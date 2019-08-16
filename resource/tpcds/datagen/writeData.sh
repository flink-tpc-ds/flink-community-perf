#!/bin/bash
  
ps -efww|grep dsdgen |grep -v grep|cut -c 9-15|xargs kill -9
ps -efww|grep FsShell |grep -v grep|cut -c 9-15|xargs kill -9
ps -efww|grep wait4process.sh |grep -v grep|cut -c 9-15|xargs kill -9
rm -rf *.dat
  
rm -rf ./call_center.dat
mkfifo ./call_center.dat
./dsdgen -SCALE 1 -TABLE call_center -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./call_center.dat ./data//SF1/call_center &
rm -rf ./catalog_page.dat
mkfifo ./catalog_page.dat
./dsdgen -SCALE 1 -TABLE catalog_page -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./catalog_page.dat ./data//SF1/catalog_page &
rm -rf ./catalog_sales.dat
mkfifo ./catalog_sales.dat
rm -rf ./catalog_returns.dat
mkfifo ./catalog_returns.dat
./dsdgen -SCALE 1 -TABLE catalog_sales -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./catalog_sales.dat ./data//SF1/catalog_sales &
./copyAndDelete.sh ./catalog_returns.dat ./data//SF1/catalog_returns &
rm -rf ./customer_address.dat
mkfifo ./customer_address.dat
./dsdgen -SCALE 1 -TABLE customer_address -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./customer_address.dat ./data//SF1/customer_address &
rm -rf ./customer.dat
mkfifo ./customer.dat
./dsdgen -SCALE 1 -TABLE customer -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./customer.dat ./data//SF1/customer &
rm -rf ./customer_demographics.dat
mkfifo ./customer_demographics.dat
./dsdgen -SCALE 1 -TABLE customer_demographics -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./customer_demographics.dat ./data//SF1/customer_demographics &
rm -rf ./date_dim.dat
mkfifo ./date_dim.dat
./dsdgen -SCALE 1 -TABLE date_dim -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./date_dim.dat ./data//SF1/date_dim &
rm -rf ./household_demographics.dat
mkfifo ./household_demographics.dat
./dsdgen -SCALE 1 -TABLE household_demographics -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./household_demographics.dat ./data//SF1/household_demographics &
rm -rf ./income_band.dat
mkfifo ./income_band.dat
./dsdgen -SCALE 1 -TABLE income_band -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./income_band.dat ./data//SF1/income_band &
rm -rf ./inventory.dat
mkfifo ./inventory.dat
./dsdgen -SCALE 1 -TABLE inventory -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./inventory.dat ./data//SF1/inventory &
rm -rf ./item.dat
mkfifo ./item.dat
./dsdgen -SCALE 1 -TABLE item -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./item.dat ./data//SF1/item &
rm -rf ./promotion.dat
mkfifo ./promotion.dat
./dsdgen -SCALE 1 -TABLE promotion -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./promotion.dat ./data//SF1/promotion &
rm -rf ./reason.dat
mkfifo ./reason.dat
./dsdgen -SCALE 1 -TABLE reason -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./reason.dat ./data//SF1/reason &
rm -rf ./ship_mode.dat
mkfifo ./ship_mode.dat
./dsdgen -SCALE 1 -TABLE ship_mode -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./ship_mode.dat ./data//SF1/ship_mode &
rm -rf ./store.dat
mkfifo ./store.dat
./dsdgen -SCALE 1 -TABLE store -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./store.dat ./data//SF1/store &
rm -rf ./store_sales.dat
mkfifo ./store_sales.dat
rm -rf ./store_returns.dat
mkfifo ./store_returns.dat
./dsdgen -SCALE 1 -TABLE store_sales -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./store_sales.dat ./data//SF1/store_sales &
./copyAndDelete.sh ./store_returns.dat ./data//SF1/store_returns  &
rm -rf ./time_dim.dat
mkfifo ./time_dim.dat
./dsdgen -SCALE 1 -TABLE time_dim -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./time_dim.dat ./data//SF1/time_dim &
rm -rf ./warehouse.dat
mkfifo ./warehouse.dat
./dsdgen -SCALE 1 -TABLE warehouse -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./warehouse.dat ./data//SF1/warehouse &
rm -rf ./web_page.dat
mkfifo ./web_page.dat
./dsdgen -SCALE 1 -TABLE web_page -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./web_page.dat ./data//SF1/web_page &
rm -rf ./web_sales.dat
mkfifo ./web_sales.dat
rm -rf ./web_returns.dat
mkfifo ./web_returns.dat
./dsdgen -SCALE 1 -TABLE web_sales -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./web_sales.dat ./data//SF1/web_sales &
./copyAndDelete.sh ./web_returns.dat ./data//SF1/web_returns &
rm -rf ./web_site.dat
mkfifo ./web_site.dat
./dsdgen -SCALE 1 -TABLE web_site -FORCE Y -RNGSEED 0 &
./copyAndDelete.sh ./web_site.dat ./data//SF1/web_site &
echo "[INFO] this machine has 21 dsden thread" 
echo "[INFO] Waiting until completion..." 
./wait4process.sh dsdgen 0 
   
