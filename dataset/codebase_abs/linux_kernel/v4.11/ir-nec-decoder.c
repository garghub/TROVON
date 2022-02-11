static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
enum V_10 V_10 ;
T_2 V_11 , V_12 , V_13 , V_14 ;
bool V_15 = false ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_16 )
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_17 , F_4 ( V_4 . V_19 ) , F_5 ( V_4 . V_20 ) ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
if ( ! V_4 . V_20 )
break;
if ( F_6 ( V_4 . V_19 , V_21 , V_22 * 2 ) ) {
V_6 -> V_23 = false ;
V_6 -> V_24 = false ;
} else if ( F_6 ( V_4 . V_19 , V_25 , V_22 / 2 ) )
V_6 -> V_23 = true ;
else
break;
V_6 -> V_26 = 0 ;
V_6 -> V_17 = V_27 ;
return 0 ;
case V_27 :
if ( V_4 . V_20 )
break;
if ( F_6 ( V_4 . V_19 , V_28 , V_22 ) ) {
V_6 -> V_17 = V_29 ;
return 0 ;
} else if ( F_6 ( V_4 . V_19 , V_30 , V_22 / 2 ) ) {
if ( ! V_2 -> V_31 ) {
F_3 ( 1 , L_2 ) ;
} else {
F_7 ( V_2 ) ;
F_3 ( 1 , L_3 ) ;
V_6 -> V_17 = V_32 ;
}
return 0 ;
}
break;
case V_29 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_33 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_34 ;
return 0 ;
case V_34 :
if ( V_4 . V_20 )
break;
if ( V_6 -> V_24 && V_6 -> V_26 == V_35 &&
F_8 ( V_4 . V_19 ,
V_36 , V_22 / 2 ) ) {
F_3 ( 1 , L_3 ) ;
F_7 ( V_2 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
} else if ( V_6 -> V_26 > V_35 )
V_6 -> V_24 = false ;
V_6 -> V_37 <<= 1 ;
if ( F_6 ( V_4 . V_19 , V_38 , V_22 / 2 ) )
V_6 -> V_37 |= 1 ;
else if ( ! F_6 ( V_4 . V_19 , V_39 , V_22 / 2 ) )
break;
V_6 -> V_26 ++ ;
if ( V_6 -> V_26 == V_40 )
V_6 -> V_17 = V_32 ;
else
V_6 -> V_17 = V_29 ;
return 0 ;
case V_32 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_41 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_42 ;
return 0 ;
case V_42 :
if ( V_4 . V_20 )
break;
if ( ! F_8 ( V_4 . V_19 , V_36 , V_22 / 2 ) )
break;
V_11 = F_9 ( ( V_6 -> V_37 >> 24 ) & 0xff ) ;
V_12 = F_9 ( ( V_6 -> V_37 >> 16 ) & 0xff ) ;
V_13 = F_9 ( ( V_6 -> V_37 >> 8 ) & 0xff ) ;
V_14 = F_9 ( ( V_6 -> V_37 >> 0 ) & 0xff ) ;
if ( ( V_13 ^ V_14 ) != 0xff ) {
F_3 ( 1 , L_4 ,
V_6 -> V_37 ) ;
V_15 = true ;
}
if ( V_15 ) {
V_9 = V_12 << 24 |
V_11 << 16 |
V_14 << 8 |
V_13 ;
F_3 ( 1 , L_5 , V_9 ) ;
V_10 = V_43 ;
} else if ( ( V_11 ^ V_12 ) != 0xff ) {
V_9 = V_11 << 16 |
V_12 << 8 |
V_13 ;
F_3 ( 1 , L_6 , V_9 ) ;
V_10 = V_44 ;
} else {
V_9 = V_11 << 8 | V_13 ;
F_3 ( 1 , L_7 , V_9 ) ;
V_10 = V_45 ;
}
if ( V_6 -> V_23 )
V_6 -> V_24 = true ;
F_10 ( V_2 , V_10 , V_9 , 0 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_3 ( 1 , L_8 ,
V_6 -> V_26 , V_6 -> V_17 , F_4 ( V_4 . V_19 ) , F_5 ( V_4 . V_20 ) ) ;
V_6 -> V_17 = V_18 ;
return - V_46 ;
}
static T_1 F_11 ( enum V_10 V_47 , T_1 V_9 )
{
unsigned int V_48 , V_49 , V_6 , V_50 ;
V_6 = V_9 & 0xff ;
if ( V_47 == V_43 ) {
V_49 = ( V_9 >> 24 ) & 0xff ;
V_48 = ( V_9 >> 16 ) & 0xff ;
V_50 = ( V_9 >> 8 ) & 0xff ;
} else if ( V_47 == V_44 ) {
V_48 = ( V_9 >> 16 ) & 0xff ;
V_49 = ( V_9 >> 8 ) & 0xff ;
V_50 = V_6 ^ 0xff ;
} else {
V_48 = ( V_9 >> 8 ) & 0xff ;
V_49 = V_48 ^ 0xff ;
V_50 = V_6 ^ 0xff ;
}
return V_50 << 24 |
V_6 << 16 |
V_49 << 8 |
V_48 ;
}
static int F_12 ( enum V_10 V_47 , T_1 V_9 ,
struct V_3 * V_51 , unsigned int V_52 )
{
struct V_3 * V_53 = V_51 ;
int V_54 ;
T_1 V_7 ;
V_7 = F_11 ( V_47 , V_9 ) ;
V_54 = F_13 ( & V_53 , V_52 , & V_55 , V_40 , V_7 ) ;
if ( V_54 < 0 )
return V_54 ;
return V_53 - V_51 ;
}
static int T_3 F_14 ( void )
{
F_15 ( & V_56 ) ;
F_16 ( V_57 L_9 ) ;
return 0 ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_56 ) ;
}
