# Resetful-Ocean-Optitcal
Using the Ocean Optics Seabreaze, vue and plotly the first pass at a network interface test with USB2000
very much a work in progress


![Alt text] (./image/newplot.png?raw=true "output")
working on build on :
	Description:	Ubuntu 22.04.3 LTS,
	Release:	22.04,
	Codename:	jammy

with   
	nodejs version v14.21.3

build RestfullSpectum
in	RestfullSpectrum,
		cmake .,
                make 

run ./RestfullSpectrum it take a few minutes to find all the devices out there


build  RestfullPlotlyView:
        in RestfullPlotlyView,
		pnpm install,
		pnpm run serve,

https://www.buymeacoffee.com/outofturn

