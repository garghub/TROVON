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
int V_21 ;
V_1 = F_10 ( V_27 , 0 ) ;
if ( ! V_1 ) {
F_11 ( L_1 ) ;
return - V_28 ;
}
V_21 = F_12 ( V_27 , 0 ) ;
if ( V_21 <= 0 ) {
F_11 ( L_2 ) ;
return - V_29 ;
}
F_4 ( V_30 , V_1 + V_14 ) ;
F_4 ( 0 , V_1 + V_31 ) ;
F_4 ( V_32 , V_1 + V_10 ) ;
F_4 ( 0 , V_1 + V_2 ) ;
F_4 ( 0 , V_1 + V_33 ) ;
F_4 ( 0 , V_1 + V_34 ) ;
F_4 ( 0 , V_1 + V_35 ) ;
F_13 ( V_1 + V_2 ,
L_3 , V_19 ,
300 , 32 , V_36 ) ;
F_14 ( F_1 , 32 , V_19 ) ;
F_4 ( 0 , V_1 + V_7 ) ;
F_4 ( 0 , V_1 + V_13 ) ;
F_4 ( 0 , V_1 + V_8 ) ;
F_4 ( 0 , V_1 + V_37 ) ;
F_15 ( V_21 , & V_38 ) ;
V_23 . V_39 = F_16 ( 0 ) ;
F_17 ( & V_23 , V_19 ,
1 , 0xffffffff ) ;
return 0 ;
}
static int T_5 F_18 ( struct V_26 * V_27 )
{
struct V_40 * V_40 ;
V_40 = F_19 ( V_27 , L_4 ) ;
if ( F_20 ( V_40 ) ) {
F_11 ( L_5 ) ;
return F_21 ( V_40 ) ;
}
V_19 = F_22 ( V_40 ) ;
return F_9 ( V_27 ) ;
}
static int T_5 F_23 ( struct V_26 * V_27 )
{
static struct V_41 * V_42 ;
int V_43 ;
T_3 V_44 ;
V_42 = F_24 ( V_27 , L_6 ) ;
if ( F_20 ( V_42 ) ) {
F_11 ( L_7 ) ;
return - V_45 ;
}
V_43 = F_25 ( V_42 , V_46 , & V_44 ) ;
if ( V_43 ) {
F_11 ( L_8 ) ;
return - V_28 ;
}
V_19 = F_26 ( V_44 ) * 1000000 ;
F_27 ( L_9 , V_19 / 1000000 ) ;
V_19 /= 6 ;
switch ( V_44 & V_47 ) {
case V_48 :
F_28 ( L_10 ) ;
break;
case V_49 :
F_28 ( L_11 ) ;
break;
case V_50 :
F_28 ( L_12 ) ;
break;
case V_51 :
F_28 ( L_13 ) ;
break;
}
return F_9 ( V_27 ) ;
}
