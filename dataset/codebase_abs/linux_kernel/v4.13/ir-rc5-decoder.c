static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 ;
enum V_11 V_12 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_13 )
V_6 -> V_14 = V_15 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
goto V_18;
V_19:
F_4 ( 2 , L_1 ,
V_6 -> V_14 , F_5 ( V_4 . V_16 ) , F_6 ( V_4 . V_20 ) ) ;
if ( ! F_3 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
return 0 ;
switch ( V_6 -> V_14 ) {
case V_15 :
if ( ! V_4 . V_20 )
break;
V_6 -> V_14 = V_21 ;
V_6 -> V_22 = 1 ;
F_7 ( & V_4 , V_23 ) ;
goto V_19;
case V_21 :
if ( ! V_4 . V_20 && F_3 ( V_4 . V_16 , V_24 , V_17 / 2 ) ) {
V_6 -> V_14 = V_25 ;
goto V_19;
}
if ( ! F_8 ( V_4 . V_16 , V_23 , V_17 / 2 ) )
break;
V_6 -> V_26 <<= 1 ;
if ( ! V_4 . V_20 )
V_6 -> V_26 |= 1 ;
V_6 -> V_22 ++ ;
V_6 -> V_14 = V_27 ;
return 0 ;
case V_27 :
if ( ! F_9 ( & V_4 , & V_2 -> V_7 -> V_28 ) )
break;
if ( V_6 -> V_22 == V_29 )
V_6 -> V_14 = V_30 ;
else
V_6 -> V_14 = V_21 ;
F_7 ( & V_4 , V_31 ) ;
goto V_19;
case V_30 :
if ( ! V_4 . V_20 && F_3 ( V_4 . V_16 , V_32 , V_17 / 2 ) ) {
V_6 -> V_33 = true ;
F_7 ( & V_4 , V_32 ) ;
} else
V_6 -> V_33 = false ;
V_6 -> V_14 = V_21 ;
goto V_19;
case V_25 :
if ( V_4 . V_20 )
break;
if ( V_6 -> V_33 && V_6 -> V_22 == V_34 ) {
T_1 V_35 , V_36 , system ;
if ( ! ( V_2 -> V_37 & V_38 ) ) {
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_35 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
V_36 = ( V_6 -> V_26 & 0x00FC0 ) >> 6 ;
system = ( V_6 -> V_26 & 0x1F000 ) >> 12 ;
V_9 = ( V_6 -> V_26 & 0x20000 ) ? 1 : 0 ;
V_36 += ( V_6 -> V_26 & 0x40000 ) ? 0 : 0x40 ;
V_10 = system << 16 | V_36 << 8 | V_35 ;
V_12 = V_39 ;
} else if ( ! V_6 -> V_33 && V_6 -> V_22 == V_40 ) {
T_1 V_36 , system ;
if ( ! ( V_2 -> V_37 & V_41 ) ) {
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_36 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_26 & 0x007C0 ) >> 6 ;
V_9 = ( V_6 -> V_26 & 0x00800 ) ? 1 : 0 ;
V_36 += ( V_6 -> V_26 & 0x01000 ) ? 0 : 0x40 ;
V_10 = system << 8 | V_36 ;
V_12 = V_42 ;
} else if ( ! V_6 -> V_33 && V_6 -> V_22 == V_43 ) {
T_1 V_36 , system ;
if ( ! ( V_2 -> V_37 & V_44 ) ) {
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_36 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_26 & 0x02FC0 ) >> 6 ;
V_9 = ( V_6 -> V_26 & 0x01000 ) ? 1 : 0 ;
V_10 = system << 6 | V_36 ;
V_12 = V_45 ;
} else
break;
F_4 ( 1 , L_2 ,
V_10 , V_12 , V_9 ) ;
F_10 ( V_2 , V_12 , V_10 , V_9 ) ;
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_18:
F_4 ( 1 , L_3 ,
V_6 -> V_14 , V_6 -> V_22 , F_5 ( V_4 . V_16 ) , F_6 ( V_4 . V_20 ) ) ;
V_6 -> V_14 = V_15 ;
return - V_46 ;
}
static int F_11 ( enum V_11 V_12 , T_2 V_10 ,
struct V_3 * V_47 , unsigned int V_48 )
{
int V_49 ;
struct V_3 * V_50 = V_47 ;
unsigned int V_6 , V_35 , V_36 , V_51 , system , V_52 ;
if ( V_12 == V_42 ) {
V_36 = ( V_10 & 0x003f ) >> 0 ;
V_51 = ( V_10 & 0x0040 ) >> 6 ;
system = ( V_10 & 0x1f00 ) >> 8 ;
V_6 = ! V_51 << 12 | system << 6 | V_36 ;
V_49 = F_12 ( & V_50 , V_48 , & V_53 ,
V_40 , V_6 ) ;
if ( V_49 < 0 )
return V_49 ;
} else if ( V_12 == V_39 ) {
V_35 = ( V_10 & 0x00003f ) >> 0 ;
V_36 = ( V_10 & 0x003f00 ) >> 8 ;
V_51 = ! ( V_10 & 0x004000 ) ;
system = ( V_10 & 0x1f0000 ) >> 16 ;
V_6 = V_51 << 18 | system << 12 | V_36 << 6 | V_35 ;
V_52 = V_6 >> ( V_34 - V_29 ) ;
V_49 = F_12 ( & V_50 , V_48 , & V_54 [ 0 ] ,
V_29 , V_52 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_12 ( & V_50 , V_48 - ( V_50 - V_47 ) ,
& V_54 [ 1 ] ,
V_34 - V_29 ,
V_6 ) ;
if ( V_49 < 0 )
return V_49 ;
} else if ( V_12 == V_45 ) {
V_49 = F_12 ( & V_50 , V_48 , & V_55 ,
V_43 , V_10 & 0x2fff ) ;
if ( V_49 < 0 )
return V_49 ;
} else {
return - V_46 ;
}
return V_50 - V_47 ;
}
static int T_3 F_13 ( void )
{
F_14 ( & V_56 ) ;
F_15 ( V_57 L_4 ) ;
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_56 ) ;
}
