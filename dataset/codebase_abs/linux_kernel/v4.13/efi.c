static int T_1 F_1 ( T_2 * V_1 , T_3 V_2 ,
unsigned long V_3 , void * V_4 )
{
T_4 * V_5 = V_4 ;
T_2 V_6 = * V_1 ;
if ( V_5 -> V_7 & V_8 )
V_6 = F_2 ( V_6 , F_3 ( V_9 ) ) ;
if ( V_5 -> V_7 & V_10 )
V_6 = F_2 ( V_6 , F_3 ( V_11 ) ) ;
F_4 ( V_1 , V_6 , V_12 ) ;
return 0 ;
}
int T_1 F_5 ( struct V_13 * V_14 ,
T_4 * V_5 )
{
unsigned long V_15 , V_16 ;
V_15 = V_5 -> V_17 ;
V_16 = V_5 -> V_18 << V_19 ;
if ( F_6 ( V_15 + V_16 , V_20 ) <
F_7 ( V_15 , V_20 ) + V_20 )
return F_8 ( V_14 , V_15 , V_16 , F_1 , V_5 ) ;
return 0 ;
}
int T_1 F_9 ( struct V_13 * V_14 , T_4 * V_5 )
{
struct V_21 V_22 = {
. V_23 = V_5 -> V_17 ,
. V_24 = F_10 ( V_5 -> V_25 ) ,
. V_26 = V_5 -> V_18 * V_27 ,
} ;
if ( V_5 -> V_7 & V_28 )
V_22 . type = V_29 ;
else if ( V_5 -> V_7 & V_30 )
V_22 . type = V_31 ;
else if ( V_5 -> V_7 & V_32 )
V_22 . type = V_33 ;
else
V_22 . type = V_34 ;
F_11 ( V_14 , & V_22 , true ) ;
if ( V_5 -> V_7 & ( V_8 | V_10 ) )
return F_5 ( V_14 , V_5 ) ;
return 0 ;
}
