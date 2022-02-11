static void F_1 ( void )
{
T_1 V_1 , V_2 ;
int V_3 ;
for ( V_3 = V_4 ; V_3 <= V_5 ; V_3 ++ ) {
F_2 ( F_3 ( V_3 ) , & V_1 , & V_2 ) ;
V_1 |= 0x01 ;
F_4 ( F_3 ( V_3 ) , V_1 , V_2 ) ;
}
}
static void F_5 ( void )
{
T_1 V_1 , V_2 ;
int V_3 ;
for ( V_3 = V_4 ; V_3 <= V_5 ; V_3 ++ ) {
F_2 ( F_3 ( V_3 ) , & V_1 , & V_2 ) ;
V_1 &= ~ 0x01 ;
F_4 ( F_3 ( V_3 ) , V_1 , V_2 ) ;
}
}
void F_6 ( int V_6 , T_1 V_7 )
{
T_1 V_1 = 0 , V_2 = V_7 ;
if ( V_7 == V_8 ) {
F_2 ( F_7 ( V_9 ) , & V_1 , & V_2 ) ;
V_2 |= V_10 [ V_6 ] ;
F_4 ( F_7 ( V_9 ) , V_1 , V_2 ) ;
} else if ( V_7 & 0x01 ) {
V_1 = 0x0000f001 ;
V_2 &= V_11 [ V_6 ] ;
F_4 ( V_12 [ V_6 ] , V_1 , V_2 ) ;
V_1 = ( ( V_7 & 0x000ffffc ) << 12 ) |
( ( V_13 [ V_6 ] - 4 ) << 12 ) | 0x01 ;
V_2 = ( ( V_7 & 0x000ffffc ) << 12 ) | 0x01 ;
F_4 ( V_14 [ V_6 ] , V_1 , V_2 ) ;
}
}
T_1 F_8 ( int V_6 )
{
T_1 V_15 = 0 ;
T_1 V_1 , V_2 ;
F_2 ( F_7 ( V_9 ) , & V_1 , & V_2 ) ;
if ( V_2 & V_10 [ V_6 ] ) {
V_15 = V_11 [ V_6 ] | V_16 ;
V_2 &= ~ V_10 [ V_6 ] ;
F_4 ( F_7 ( V_9 ) , V_1 , V_2 ) ;
} else {
F_2 ( V_12 [ V_6 ] , & V_1 , & V_2 ) ;
V_15 = V_2 & V_11 [ V_6 ] ;
V_15 |= 0x01 ;
V_15 &= ~ 0x02 ;
}
return V_15 ;
}
void F_9 ( int V_17 , T_1 V_7 )
{
T_1 V_1 = 0 , V_2 = V_7 ;
T_1 V_18 ;
switch ( V_17 ) {
case V_19 :
if ( V_7 & V_20 )
F_1 () ;
else
F_5 () ;
break;
case V_21 :
F_2 ( F_10 ( V_22 ) , & V_1 , & V_2 ) ;
V_18 = V_2 & 0x0000ffff ;
if ( ( V_7 & V_23 ) &&
( V_2 & V_24 ) )
V_18 |= V_25 ;
if ( ( V_7 & V_26 ) &&
( V_2 & V_27 ) )
V_18 |= V_28 ;
if ( ( V_7 & V_29 )
&& ( V_2 & V_30 ) )
V_18 |= V_31 ;
if ( ( V_7 & V_32 )
&& ( V_2 & V_33 ) )
V_18 |= V_34 ;
V_2 = V_18 ;
F_4 ( F_10 ( V_22 ) , V_1 , V_2 ) ;
break;
case V_35 :
V_7 &= 0x0000ff00 ;
F_2 ( F_10 ( V_36 ) , & V_1 , & V_2 ) ;
V_1 &= 0xffffff00 ;
V_1 |= ( V_7 >> 8 ) ;
F_4 ( F_10 ( V_36 ) , V_1 , V_2 ) ;
break;
case V_37 :
F_6 ( 0 , V_7 ) ;
break;
case V_38 :
F_6 ( 1 , V_7 ) ;
break;
case V_39 :
F_6 ( 2 , V_7 ) ;
break;
case V_40 :
F_6 ( 3 , V_7 ) ;
break;
case V_41 :
F_6 ( 4 , V_7 ) ;
break;
case V_42 :
F_6 ( 5 , V_7 ) ;
break;
case V_43 :
F_2 ( F_3 ( V_44 ) , & V_1 , & V_2 ) ;
V_2 &= ~ ( 0xf << 24 ) ;
if ( V_7 )
V_2 |= ( V_45 << 24 ) ;
F_4 ( F_3 ( V_44 ) , V_1 , V_2 ) ;
break;
case V_46 :
F_2 ( F_3 ( V_44 ) , & V_1 , & V_2 ) ;
V_2 &= ~ ( 0xf << 28 ) ;
if ( V_7 )
V_2 |= ( V_47 << 28 ) ;
F_4 ( F_3 ( V_44 ) , V_1 , V_2 ) ;
break;
case V_48 :
if ( V_7 ) {
F_2 ( F_10 ( V_22 ) , & V_1 , & V_2 ) ;
V_2 |= 0x00000063 ;
F_4 ( F_10 ( V_22 ) , V_1 , V_2 ) ;
}
default:
break;
}
}
T_1 F_11 ( int V_17 )
{
T_1 V_15 = 0 ;
T_1 V_1 , V_2 ;
switch ( V_17 ) {
case V_49 :
V_15 =
F_12 ( V_50 , V_51 ) ;
break;
case V_19 :
F_2 ( F_3 ( V_4 ) , & V_1 , & V_2 ) ;
if ( V_1 & 0x01 )
V_15 |= V_20 ;
break;
case V_21 :
V_15 |= V_52 ;
V_15 |= V_53 ;
V_15 |= V_54 ;
F_2 ( F_10 ( V_22 ) , & V_1 , & V_2 ) ;
if ( V_2 & V_25 )
V_15 |= V_23 ;
if ( V_2 & V_28 )
V_15 |= V_26 ;
if ( V_2 & V_31 )
V_15 |= V_29 ;
if ( V_2 & V_34 )
V_15 |= V_32 ;
break;
case V_55 :
F_2 ( F_7 ( V_56 ) , & V_1 , & V_2 ) ;
V_15 = V_2 & 0x000000ff ;
V_15 |= ( V_57 << 8 ) ;
break;
case V_35 :
F_2 ( F_10 ( V_36 ) , & V_1 , & V_2 ) ;
V_1 &= 0x000000f8 ;
V_15 = F_13 ( V_58 , V_1 ) ;
break;
case V_37 :
return F_8 ( 0 ) ;
break;
case V_38 :
return F_8 ( 1 ) ;
break;
case V_39 :
return F_8 ( 2 ) ;
break;
case V_40 :
break;
case V_41 :
return F_8 ( 4 ) ;
break;
case V_42 :
return F_8 ( 5 ) ;
break;
case V_59 :
V_15 = V_60 ;
break;
case V_61 :
V_15 =
F_12 ( V_62 , V_63 ) ;
break;
case V_64 :
V_15 = V_65 ;
break;
case V_66 :
V_15 = V_67 ;
break;
case V_68 :
V_15 = F_14 ( 0x00 , 0x00 ) ;
break;
default:
break;
}
return V_15 ;
}
static void F_15 ( struct V_69 * V_70 )
{
V_70 -> V_71 = 1 ;
}
