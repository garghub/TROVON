static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_8 -> V_11 ) ;
T_1 V_12 ;
F_3 ( V_10 -> V_13 , L_1
L_2 ,
V_14 , V_2 , F_4 ( V_4 ) ,
F_5 ( V_4 ) , F_6 ( V_4 ) ,
F_7 ( V_4 ) , F_8 ( V_4 ) ) ;
switch ( F_9 ( V_4 ) ) {
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
case V_19 :
V_12 = V_20 ;
break;
case V_21 :
V_12 = V_22 ;
break;
default:
F_3 ( V_10 -> V_13 , L_3 ) ;
return - V_23 ;
}
F_10 ( & V_10 -> V_24 -> V_25 , V_10 -> V_25 | V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_11 ,
int V_26 , unsigned int V_27 , int V_28 )
{
struct V_10 * V_10 = F_2 ( V_11 ) ;
F_3 ( V_10 -> V_13 , L_4 ,
V_11 , V_28 ) ;
return ( V_28 == V_29 ) ? 0 : - V_23 ;
}
static int F_12 ( struct V_5 * V_11 , unsigned int V_30 )
{
struct V_10 * V_10 = F_2 ( V_11 ) ;
F_3 ( V_10 -> V_13 , L_5 ,
V_11 , V_30 ) ;
return ( V_30 == V_31 ) ? 0 : - V_23 ;
}
static int T_2 F_13 ( struct V_32 * V_33 )
{
int V_34 ;
struct V_10 * V_10 ;
struct V_35 T_3 * V_36 ;
V_34 = F_14 ( & V_33 -> V_13 , V_37 , F_15 ( V_37 ) ) ;
if ( V_34 != 0 ) {
F_16 ( L_6 ) ;
return V_34 ;
}
V_10 = F_17 ( & V_33 -> V_13 ) ;
V_36 = V_10 -> V_24 ;
V_10 -> V_25 = V_38 | V_39 |
V_40 ;
F_10 ( & V_10 -> V_24 -> V_25 ,
V_10 -> V_25 | V_16 ) ;
if ( ! F_18 ( V_33 -> V_13 . V_41 , L_7 , NULL ) )
return 0 ;
while ( ( F_19 ( & V_36 -> V_42 . V_43 ) & 0x80 ) != 0 )
;
while ( ( F_19 ( & V_36 -> V_42 . V_43 ) & 0x80 ) == 0 )
;
F_20 ( & V_10 -> V_24 -> V_44 ,
V_45 | V_46 ) ;
return 0 ;
}
static int T_4 F_21 ( struct V_32 * V_33 )
{
F_22 ( & V_33 -> V_13 , F_15 ( V_37 ) ) ;
return 0 ;
}
