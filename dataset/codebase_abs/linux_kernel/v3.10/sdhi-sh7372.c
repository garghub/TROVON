T_1 void F_1 ( unsigned short * V_1 , unsigned long V_2 )
{
int V_3 ;
F_2 () ;
F_3 ( V_4 ) ;
F_4 ( V_5 , V_6 ) ;
F_4 ( V_7 | V_5 , V_8 ) ;
F_4 ( V_5 , V_9 ) ;
F_4 ( V_5 , V_10 ) ;
F_4 ( V_5 , V_11 ) ;
F_4 ( V_5 , V_12 ) ;
F_5 ( F_6 ( V_13 ) & ~ ( 1 << 13 ) , V_13 ) ;
F_3 ( V_14 ) ;
V_3 = F_7 ( V_15 ) ;
if ( V_3 < 0 )
goto V_16;
F_3 ( V_17 ) ;
if ( F_8 ( V_15 , V_3 ,
0 ,
( V_2 + V_18 - 1 ) / V_18 , V_1 ) )
goto V_16;
F_5 ( F_6 ( V_13 ) | ( 1 << 13 ) , V_13 ) ;
F_3 ( V_19 ) ;
return;
V_16:
for(; ; ) ;
}
