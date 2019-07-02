# DO NOT RUN THIS FILE DIRECTLY
# USE make install
FLAG="flag{y0u_g0t_th1s_flag}"

./exec-encrypt $FLAG ./code > ./.hint

mkdir output
mv .hint exec-me output/
