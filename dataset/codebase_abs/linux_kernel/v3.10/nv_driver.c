static inline unsigned char F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 . V_4 , 0x3cc ) ) ;
}
static Bool
F_3 ( struct V_1 * V_2 , Bool V_5 )
{
volatile T_1 T_2 * V_6 = V_2 -> V_3 . V_7 ;
T_1 V_8 , V_9 ;
Bool V_10 ;
if( V_5 ) V_6 += 0x800 ;
V_8 = F_4 ( V_6 , 0x052C ) ;
V_9 = F_4 ( V_6 , 0x0608 ) ;
F_5 ( V_6 , 0x0608 , V_9 & ~ 0x00010000 ) ;
F_5 ( V_6 , 0x052C , V_8 & 0x0000FEEE ) ;
F_6 ( 1 ) ;
F_5 ( V_6 , 0x052C , F_4 ( V_6 , 0x052C ) | 1 ) ;
F_5 ( V_2 -> V_3 . V_7 , 0x0610 , 0x94050140 ) ;
F_5 ( V_2 -> V_3 . V_7 , 0x0608 , 0x00001000 ) ;
F_6 ( 1 ) ;
V_10 = ( F_4 ( V_6 , 0x0608 ) & ( 1 << 28 ) ) ? TRUE : FALSE ;
F_5 ( V_2 -> V_3 . V_7 , 0x0608 ,
F_4 ( V_2 -> V_3 . V_7 , 0x0608 ) & 0x0000EFFF ) ;
F_5 ( V_6 , 0x052C , V_8 ) ;
F_5 ( V_6 , 0x0608 , V_9 ) ;
return V_10 ;
}
static void
F_7 ( struct V_1 * V_2 )
{
F_8 (KERN_INFO PFX
L_1 ,
par->SecondCRTC ? 1 : 0 ) ;
if( V_2 -> V_11 != - 1 ) {
F_8 (KERN_INFO PFX
L_2 , par->forceCRTC) ;
V_2 -> V_12 = V_2 -> V_11 ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == 1 ) {
switch( V_2 -> V_14 & 0xffff ) {
case 0x0174 :
case 0x0175 :
case 0x0176 :
case 0x0177 :
case 0x0179 :
case 0x017C :
case 0x017D :
case 0x0186 :
case 0x0187 :
case 0x0286 :
case 0x028C :
case 0x0316 :
case 0x0317 :
case 0x031A :
case 0x031B :
case 0x031C :
case 0x031D :
case 0x031E :
case 0x031F :
case 0x0324 :
case 0x0325 :
case 0x0328 :
case 0x0329 :
case 0x032C :
case 0x032D :
V_2 -> V_12 = TRUE ;
break;
default:
V_2 -> V_12 = FALSE ;
break;
}
} else {
if( F_3 ( V_2 , 0 ) ) {
if ( F_4 ( V_2 -> V_3 . V_7 , 0x0000052C ) & 0x100 )
V_2 -> V_12 = TRUE ;
else
V_2 -> V_12 = FALSE ;
} else
if ( F_3 ( V_2 , 1 ) ) {
if( F_4 ( V_2 -> V_3 . V_7 , 0x0000252C ) & 0x100 )
V_2 -> V_12 = TRUE ;
else
V_2 -> V_12 = FALSE ;
} else
V_2 -> V_12 = FALSE ;
}
F_7 ( V_2 ) ;
}
unsigned long F_10 ( struct V_1 * V_2 )
{
T_3 * V_15 = & V_2 -> V_3 ;
unsigned long V_16 = 0 ;
unsigned int V_17 = V_2 -> V_14 ;
struct V_18 * V_19 ;
T_4 V_20 ;
switch ( V_15 -> V_21 ) {
case V_22 :
if ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x00000020 ) {
if ( ( ( F_4 ( V_15 -> V_24 , 0x00000000 ) & 0xF0 ) == 0x20 )
&& ( ( F_4 ( V_15 -> V_24 , 0x00000000 ) & 0x0F ) >= 0x02 ) ) {
switch ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x03 ) {
case 2 :
V_16 = 1024 * 4 ;
break;
case 1 :
V_16 = 1024 * 2 ;
break;
default:
V_16 = 1024 * 8 ;
break;
}
} else {
V_16 = 1024 * 8 ;
}
} else {
switch ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x00000003 ) {
case 0 :
V_16 = 1024 * 8 ;
break;
case 2 :
V_16 = 1024 * 4 ;
break;
default:
V_16 = 1024 * 2 ;
break;
}
}
break;
case V_25 :
if ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x00000100 ) {
V_16 = ( ( F_4 ( V_15 -> V_23 , 0x00000000 ) >> 12 ) & 0x0F ) *
1024 * 2 + 1024 * 2 ;
} else {
switch ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x00000003 ) {
case 0 :
V_16 = 1024 * 32 ;
break;
case 1 :
V_16 = 1024 * 4 ;
break;
case 2 :
V_16 = 1024 * 8 ;
break;
case 3 :
default:
V_16 = 1024 * 16 ;
break;
}
}
break;
case V_26 :
case V_27 :
case V_28 :
if( V_17 == V_29 ) {
V_19 = F_11 ( 0 , 1 ) ;
F_12 ( V_19 , 0x7C , & V_20 ) ;
F_13 ( V_19 ) ;
V_16 = ( ( ( V_20 >> 6 ) & 31 ) + 1 ) * 1024 ;
} else if ( V_17 == V_30 ) {
V_19 = F_11 ( 0 , 1 ) ;
F_12 ( V_19 , 0x84 , & V_20 ) ;
F_13 ( V_19 ) ;
V_16 = ( ( ( V_20 >> 4 ) & 127 ) + 1 ) * 1024 ;
} else {
switch ( ( F_4 ( V_15 -> V_23 , 0x0000020C ) >> 20 ) &
0x000000FF ) {
case 0x02 :
V_16 = 1024 * 2 ;
break;
case 0x04 :
V_16 = 1024 * 4 ;
break;
case 0x08 :
V_16 = 1024 * 8 ;
break;
case 0x10 :
V_16 = 1024 * 16 ;
break;
case 0x20 :
V_16 = 1024 * 32 ;
break;
case 0x40 :
V_16 = 1024 * 64 ;
break;
case 0x80 :
V_16 = 1024 * 128 ;
break;
default:
V_16 = 1024 * 16 ;
break;
}
}
break;
}
return V_16 ;
}
unsigned long F_14 ( struct V_1 * V_2 )
{
T_3 * V_15 = & V_2 -> V_3 ;
unsigned long V_31 = 0 ;
switch ( V_15 -> V_21 ) {
case V_22 :
if ( F_4 ( V_15 -> V_23 , 0x00000000 ) & 0x00000020 ) {
if ( ( ( F_4 ( V_15 -> V_24 , 0x00000000 ) & 0xF0 ) == 0x20 )
&& ( ( F_4 ( V_15 -> V_24 , 0x00000000 ) & 0x0F ) >= 0x02 ) ) {
V_31 = 800000 ;
} else {
V_31 = 1000000 ;
}
} else {
V_31 = 1000000 ;
}
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
switch ( ( F_4 ( V_15 -> V_23 , 0x00000000 ) >> 3 ) & 0x00000003 ) {
case 3 :
V_31 = 800000 ;
break;
default:
V_31 = 1000000 ;
break;
}
break;
}
return V_31 ;
}
void
F_15 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_32 = 0 ;
V_2 -> V_3 . V_7 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00680000 ) ;
V_2 -> V_3 . V_23 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00100000 ) ;
V_2 -> V_3 . V_34 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00002000 ) ;
V_2 -> V_3 . V_35 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00400000 ) ;
V_2 -> V_3 . V_36 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00101000 ) ;
V_2 -> V_3 . V_37 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00009000 ) ;
V_2 -> V_3 . V_24 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00000000 ) ;
V_2 -> V_3 . V_38 =
( volatile T_1 T_2 * ) ( V_2 -> V_33 + 0x00800000 ) ;
V_2 -> V_3 . V_39 = V_2 -> V_33 + 0x00601000 ;
V_2 -> V_3 . V_40 = V_2 -> V_33 + 0x00681000 ;
V_2 -> V_3 . V_4 = V_2 -> V_33 + 0x000C0000 ;
V_2 -> V_3 . V_41 = ( F_1 ( V_2 ) & 0x01 ) ? 0x3D0 : 0x3B0 ;
if ( V_2 -> V_13 == - 1 ) {
switch ( V_2 -> V_14 & 0xffff ) {
case 0x0112 :
case 0x0174 :
case 0x0175 :
case 0x0176 :
case 0x0177 :
case 0x0179 :
case 0x017C :
case 0x017D :
case 0x0186 :
case 0x0187 :
case 0x0286 :
case 0x028C :
case 0x0316 :
case 0x0317 :
case 0x031A :
case 0x031B :
case 0x031C :
case 0x031D :
case 0x031E :
case 0x031F :
case 0x0324 :
case 0x0325 :
case 0x0328 :
case 0x0329 :
case 0x032C :
case 0x032D :
F_8 (KERN_INFO PFX
L_3 ) ;
V_2 -> V_13 = 1 ;
break;
default:
break;
}
}
switch ( V_2 -> V_14 & 0x0ff0 ) {
case 0x0110 :
if ( V_2 -> V_14 == V_42 )
V_2 -> V_12 = TRUE ;
#if F_16 ( V_43 )
if ( V_2 -> V_13 == 1 )
V_2 -> V_12 = TRUE ;
#endif
F_7 ( V_2 ) ;
break;
case 0x0170 :
case 0x0180 :
case 0x01F0 :
case 0x0250 :
case 0x0280 :
case 0x0300 :
case 0x0310 :
case 0x0320 :
case 0x0330 :
case 0x0340 :
F_9 ( V_2 ) ;
break;
default:
break;
}
if ( V_2 -> V_12 ) {
V_2 -> V_3 . V_44 = V_2 -> V_3 . V_39 + 0x2000 ;
V_2 -> V_3 . V_45 = V_2 -> V_3 . V_46 + 0x800 ;
V_2 -> V_3 . V_6 = V_2 -> V_3 . V_7 + 0x800 ;
V_2 -> V_3 . V_47 = V_2 -> V_3 . V_40 + 0x2000 ;
} else {
V_2 -> V_3 . V_44 = V_2 -> V_3 . V_39 ;
V_2 -> V_3 . V_45 = V_2 -> V_3 . V_46 ;
V_2 -> V_3 . V_6 = V_2 -> V_3 . V_7 ;
V_2 -> V_3 . V_47 = V_2 -> V_3 . V_40 ;
}
if ( V_2 -> V_13 == - 1 ) {
V_2 -> V_13 = 0 ;
}
V_2 -> V_3 . V_48 = ( V_2 -> V_13 > 0 ) ? TRUE : FALSE ;
F_17 ( & V_2 -> V_3 , V_2 -> V_14 ) ;
}
