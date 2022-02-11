static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
enum V_10 V_10 ;
T_2 V_11 , V_12 , V_13 , V_14 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_15 )
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
if ( ! V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_20 , V_21 * 2 ) ) {
V_6 -> V_22 = false ;
V_6 -> V_23 = false ;
} else if ( F_6 ( V_4 . V_18 , V_24 , V_21 / 2 ) )
V_6 -> V_22 = true ;
else
break;
V_6 -> V_25 = 0 ;
V_6 -> V_16 = V_26 ;
return 0 ;
case V_26 :
if ( V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_27 , V_21 ) ) {
V_6 -> V_16 = V_28 ;
return 0 ;
} else if ( F_6 ( V_4 . V_18 , V_29 , V_21 / 2 ) ) {
F_7 ( V_2 ) ;
F_3 ( 1 , L_2 ) ;
V_6 -> V_16 = V_30 ;
return 0 ;
}
break;
case V_28 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_31 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_32 ;
return 0 ;
case V_32 :
if ( V_4 . V_19 )
break;
if ( V_6 -> V_23 && V_6 -> V_25 == V_33 &&
F_8 ( V_4 . V_18 ,
V_34 , V_21 / 2 ) ) {
F_3 ( 1 , L_2 ) ;
F_7 ( V_2 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
} else if ( V_6 -> V_25 > V_33 )
V_6 -> V_23 = false ;
V_6 -> V_35 <<= 1 ;
if ( F_6 ( V_4 . V_18 , V_36 , V_21 / 2 ) )
V_6 -> V_35 |= 1 ;
else if ( ! F_6 ( V_4 . V_18 , V_37 , V_21 / 2 ) )
break;
V_6 -> V_25 ++ ;
if ( V_6 -> V_25 == V_38 )
V_6 -> V_16 = V_30 ;
else
V_6 -> V_16 = V_28 ;
return 0 ;
case V_30 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_39 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_40 ;
return 0 ;
case V_40 :
if ( V_4 . V_19 )
break;
if ( ! F_8 ( V_4 . V_18 , V_34 , V_21 / 2 ) )
break;
V_11 = F_9 ( ( V_6 -> V_35 >> 24 ) & 0xff ) ;
V_12 = F_9 ( ( V_6 -> V_35 >> 16 ) & 0xff ) ;
V_13 = F_9 ( ( V_6 -> V_35 >> 8 ) & 0xff ) ;
V_14 = F_9 ( ( V_6 -> V_35 >> 0 ) & 0xff ) ;
V_9 = F_10 ( V_11 , V_12 ,
V_13 , V_14 ,
& V_10 ) ;
if ( V_6 -> V_22 )
V_6 -> V_23 = true ;
F_11 ( V_2 , V_10 , V_9 , 0 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_3 ( 1 , L_3 ,
V_6 -> V_25 , V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
V_6 -> V_16 = V_17 ;
return - V_41 ;
}
static T_1 F_12 ( enum V_10 V_42 , T_1 V_9 )
{
unsigned int V_43 , V_44 , V_6 , V_45 ;
V_6 = V_9 & 0xff ;
if ( V_42 == V_46 ) {
V_44 = ( V_9 >> 24 ) & 0xff ;
V_43 = ( V_9 >> 16 ) & 0xff ;
V_45 = ( V_9 >> 8 ) & 0xff ;
} else if ( V_42 == V_47 ) {
V_43 = ( V_9 >> 16 ) & 0xff ;
V_44 = ( V_9 >> 8 ) & 0xff ;
V_45 = V_6 ^ 0xff ;
} else {
V_43 = ( V_9 >> 8 ) & 0xff ;
V_44 = V_43 ^ 0xff ;
V_45 = V_6 ^ 0xff ;
}
return V_45 << 24 |
V_6 << 16 |
V_44 << 8 |
V_43 ;
}
static int F_13 ( enum V_10 V_42 , T_1 V_9 ,
struct V_3 * V_48 , unsigned int V_49 )
{
struct V_3 * V_50 = V_48 ;
int V_51 ;
T_1 V_7 ;
V_7 = F_12 ( V_42 , V_9 ) ;
V_51 = F_14 ( & V_50 , V_49 , & V_52 , V_38 , V_7 ) ;
if ( V_51 < 0 )
return V_51 ;
return V_50 - V_48 ;
}
static int T_3 F_15 ( void )
{
F_16 ( & V_53 ) ;
F_17 ( V_54 L_4 ) ;
return 0 ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_53 ) ;
}
