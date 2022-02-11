static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 + V_2 ) ;
}
static int F_3 ( unsigned long V_3 ,
struct V_4 * V_5 )
{
T_3 V_6 ;
V_6 = F_2 ( V_1 + V_7 ) ;
F_4 ( V_6 + V_3 , V_1 + V_8 ) ;
if ( F_2 ( V_1 + V_7 ) - V_6 > V_3 )
return - V_9 ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
T_3 V_6 ;
V_6 = F_2 ( V_1 + V_10 ) ;
V_6 &= ~ ( V_11 | V_12 ) ;
F_4 ( V_6 , V_1 + V_10 ) ;
F_4 ( 0 , V_1 + V_7 ) ;
F_4 ( 0 , V_1 + V_13 ) ;
V_6 = F_2 ( V_1 + V_14 ) ;
V_6 &= ~ ( V_15 | V_16 ) ;
V_6 |= V_17 ;
F_4 ( V_6 , V_1 + V_14 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
V_6 |= V_11 ;
F_4 ( V_6 , V_1 + V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
T_3 V_18 = F_7 ( V_19 , V_20 ) ;
T_3 V_6 ;
V_6 = F_2 ( V_1 + V_10 ) ;
V_6 &= ~ ( V_11 | V_12 ) ;
F_4 ( V_6 , V_1 + V_10 ) ;
V_6 = 0xffffffff - ( V_18 - 1 ) ;
F_4 ( V_6 , V_1 + V_7 ) ;
F_4 ( V_6 , V_1 + V_13 ) ;
V_6 = F_2 ( V_1 + V_14 ) ;
V_6 &= ~ ( V_17 | V_16 ) ;
V_6 |= V_15 ;
F_4 ( V_6 , V_1 + V_14 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
V_6 |= V_11 ;
V_6 |= V_12 ;
F_4 ( V_6 , V_1 + V_10 ) ;
return 0 ;
}
static T_4 F_8 ( int V_21 , void * V_22 )
{
struct V_4 * V_5 = & V_23 ;
V_5 -> V_24 ( V_5 ) ;
return V_25 ;
}
static int T_5 F_9 ( struct V_26 * V_27 )
{
static struct V_28 * V_29 ;
int V_21 ;
int V_30 ;
T_3 V_31 ;
V_29 = F_10 ( V_27 , L_1 ) ;
if ( F_11 ( V_29 ) ) {
F_12 ( L_2 ) ;
return - V_32 ;
}
V_30 = F_13 ( V_29 , V_33 , & V_31 ) ;
if ( V_30 ) {
F_12 ( L_3 ) ;
return - V_34 ;
}
V_1 = F_14 ( V_27 , 0 ) ;
if ( ! V_1 ) {
F_12 ( L_4 ) ;
return - V_34 ;
}
V_21 = F_15 ( V_27 , 0 ) ;
if ( V_21 <= 0 ) {
F_12 ( L_5 ) ;
return - V_35 ;
}
V_19 = F_16 ( V_31 ) * 1000000 ;
F_17 ( V_36 L_6 , V_19 / 1000000 ) ;
V_19 /= 6 ;
switch ( V_31 & V_37 ) {
case V_38 :
F_17 ( V_39 L_7 ) ;
break;
case V_40 :
F_17 ( V_39 L_8 ) ;
break;
case V_41 :
F_17 ( V_39 L_9 ) ;
break;
case V_42 :
F_17 ( V_39 L_10 ) ;
break;
}
F_4 ( V_43 , V_1 + V_14 ) ;
F_4 ( 0 , V_1 + V_44 ) ;
F_4 ( V_45 , V_1 + V_10 ) ;
F_4 ( 0 , V_1 + V_2 ) ;
F_4 ( 0 , V_1 + V_46 ) ;
F_4 ( 0 , V_1 + V_47 ) ;
F_4 ( 0 , V_1 + V_48 ) ;
F_18 ( V_1 + V_2 ,
L_11 , V_19 ,
300 , 32 , V_49 ) ;
F_19 ( F_1 , 32 , V_19 ) ;
F_4 ( 0 , V_1 + V_7 ) ;
F_4 ( 0 , V_1 + V_13 ) ;
F_4 ( 0 , V_1 + V_8 ) ;
F_4 ( 0 , V_1 + V_50 ) ;
F_20 ( V_21 , & V_51 ) ;
V_23 . V_52 = F_21 ( 0 ) ;
F_22 ( & V_23 , V_19 ,
1 , 0xffffffff ) ;
return 0 ;
}
