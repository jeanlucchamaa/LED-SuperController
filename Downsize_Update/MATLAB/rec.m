%% start
clear; clc;
r=audiorecorder(44100,16,1,1);
record(r);
counter=1;
tempcounter=1;
cycles=1;
bass=zeros(1,30);
treble=zeros(1,30);
coeff=2.3;
noisefloor=.01;

while(r.CurrentSample<1000)
   ; %hang until the sample has data inside 
end
while(tempcounter<5000000)
    A=getaudiodata(r);
    tempcounter=length(A);
    if(counter~=tempcounter)
        chunk=A(counter:tempcounter);
        Y = fft(chunk);
        counter=tempcounter;
    %% initial math
        L=length(chunk);
        P2 = abs(Y/L);
        P1 = P2(1:floor(L/2+1));
        P1(2:end-1) = 2*P1(2:end-1);
        Fs=44100;
        f = Fs*(0:(L/2))/L;
    %% drawing 
%         subplot(2,1,1)
%         plot(chunk);
%         axis([0 2000 -.075 .075])
%         subplot(2,1,2)
%         bar(f,P1)
%         axis([40 10000 .000001 .01])
%         drawnow
    %% graph utilities
        lowend=sum(P1(find(f>30,1):find(f>120)));
        highend=sum(P1(find(f>7000,1):find(f>12000)));

        
        cyclemod=mod(cycles,30)+1;
        bass(cyclemod)=lowend;
        treble(cyclemod)=highend;
        bthresh=mean(bass)*coeff; %average bass * coeff = bang threshold
        tthresh=mean(treble)*coeff; %average treble * coeff = bang threshold
        
        
        res=bar([lowend bthresh tthresh highend]);
        if((lowend > noisefloor && lowend > bthresh)...
                || (highend > noisefloor && highend > tthresh))
            disp('bang');
            res.FaceColor='yellow';    
        else
            res.FaceColor='blue';
        end
        ylim([0 .05])
        drawnow
        cycles=cycles+1;
    end
end
stop(r);