static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 , V_4 ) ;
F_2 ( V_2 , L_2 , V_5 ) ;
F_2 ( V_2 , L_3 , V_6 ) ;
F_2 ( V_2 , L_4 , V_7 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
if ( F_3 () >= V_9 )
F_2 ( V_2 , L_6 , V_10 ) ;
F_2 ( V_2 , L_7 , V_11 ) ;
F_2 ( V_2 , L_8 , V_12 ,
V_13 [ V_12 ] ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_5 ( V_15 , F_1 , NULL ) ;
}
static T_1 F_6 ( struct V_15 * V_15 , const char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
char V_19 ;
if ( V_17 > 0 ) {
if ( F_7 ( V_19 , V_16 ) )
return - V_20 ;
if ( V_19 >= '0' && V_19 <= '5' )
V_12 = V_19 - '0' ;
}
return V_17 ;
}
static void
F_8 ( unsigned long V_21 , unsigned long V_22 , struct V_23 * V_24 , union V_25 V_26 )
{
if ( ! F_9 ( V_22 ) )
V_26 . V_27 = - V_26 . V_27 ;
if ( ! F_10 ( V_22 ) )
V_21 += V_26 . V_27 ;
if ( ! F_10 ( V_22 ) || F_11 ( V_22 ) )
V_24 -> V_28 [ F_12 ( V_22 ) ] = V_21 ;
}
static int
F_13 ( unsigned long V_21 , unsigned long V_22 , struct V_23 * V_24 )
{
unsigned int V_29 = F_14 ( V_22 ) ;
V_7 += 1 ;
if ( F_15 ( V_24 ) )
goto V_30;
if ( F_16 ( V_22 ) ) {
unsigned long V_31 ;
F_17 ( V_31 , V_21 ) ;
if ( V_22 & 0x40 )
V_31 = ( signed long ) ( ( signed short ) V_31 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_18 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
return V_32 ;
V_30:
if ( F_16 ( V_22 ) ) {
unsigned long V_31 ;
F_19 ( V_31 , V_21 ) ;
if ( V_22 & 0x40 )
V_31 = ( signed long ) ( ( signed short ) V_31 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_20 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
return V_32 ;
V_33:
return V_34 ;
}
static int
F_21 ( unsigned long V_21 , unsigned long V_22 ,
struct V_23 * V_24 )
{
unsigned int V_29 = F_14 ( V_22 ) ;
unsigned int V_35 ;
int V_36 ;
if ( ( V_22 & 0xfe000000 ) == 0xe8000000 ) {
V_35 = ( V_22 >> 8 ) & 0xf ;
V_36 = ! ! ( F_16 ( V_22 ) ) ;
} else if ( ( ( V_29 & 1 ) == 1 ) || ( V_29 == 14 ) )
goto V_37;
else {
V_36 = ( ( V_22 & 0xf0 ) == 0xd0 ) ;
V_35 = V_29 + 1 ;
}
V_10 += 1 ;
if ( F_15 ( V_24 ) )
goto V_30;
if ( V_36 ) {
unsigned long V_31 ;
F_22 ( V_31 , V_21 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
F_22 ( V_31 , V_21 + 4 ) ;
V_24 -> V_28 [ V_35 ] = V_31 ;
} else {
F_23 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
F_23 ( V_24 -> V_28 [ V_35 ] , V_21 + 4 ) ;
}
return V_32 ;
V_30:
if ( V_36 ) {
unsigned long V_31 ;
F_24 ( V_31 , V_21 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
F_24 ( V_31 , V_21 + 4 ) ;
V_24 -> V_28 [ V_35 ] = V_31 ;
} else {
F_25 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
F_25 ( V_24 -> V_28 [ V_35 ] , V_21 + 4 ) ;
}
return V_32 ;
V_37:
return V_38 ;
V_33:
return V_34 ;
}
static int
F_26 ( unsigned long V_21 , unsigned long V_22 , struct V_23 * V_24 )
{
unsigned int V_29 = F_14 ( V_22 ) ;
V_8 += 1 ;
if ( ( ! F_10 ( V_22 ) && F_11 ( V_22 ) ) || F_15 ( V_24 ) )
goto V_39;
if ( F_16 ( V_22 ) ) {
unsigned int V_31 ;
F_22 ( V_31 , V_21 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_23 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
return V_32 ;
V_39:
if ( F_16 ( V_22 ) ) {
unsigned int V_31 ;
F_24 ( V_31 , V_21 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_25 ( V_24 -> V_28 [ V_29 ] , V_21 ) ;
return V_32 ;
V_33:
return V_34 ;
}
static int
F_27 ( unsigned long V_21 , unsigned long V_22 , struct V_23 * V_24 )
{
unsigned int V_29 , V_40 , V_41 , V_42 , V_43 ;
unsigned long V_44 , V_45 ;
if ( F_28 ( V_22 ) )
goto V_37;
V_41 = 4 ;
V_24 -> V_46 += V_41 ;
V_11 += 1 ;
V_42 = F_29 ( F_30 ( V_22 ) ) * 4 ;
V_40 = F_12 ( V_22 ) ;
V_45 = V_44 = V_24 -> V_28 [ V_40 ] ;
if ( ! F_9 ( V_22 ) )
V_42 = - V_42 ;
V_45 += V_42 ;
if ( ! F_9 ( V_22 ) )
V_44 = V_45 ;
if ( F_31 ( V_22 ) )
V_44 += 4 ;
#if ! ( V_47 V_48 ) && ! ( V_47 V_49 )
if ( V_21 != V_44 ) {
F_32 ( V_50 L_9
L_10 ,
F_33 ( V_24 ) , V_22 , V_21 , V_44 ) ;
F_34 ( V_24 ) ;
}
#endif
if ( F_15 ( V_24 ) ) {
for ( V_43 = F_30 ( V_22 ) , V_29 = 0 ; V_43 ;
V_43 >>= 1 , V_29 += 1 )
if ( V_43 & 1 ) {
if ( F_16 ( V_22 ) ) {
unsigned int V_31 ;
F_24 ( V_31 , V_44 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_25 ( V_24 -> V_28 [ V_29 ] , V_44 ) ;
V_44 += 4 ;
}
} else {
for ( V_43 = F_30 ( V_22 ) , V_29 = 0 ; V_43 ;
V_43 >>= 1 , V_29 += 1 )
if ( V_43 & 1 ) {
if ( F_16 ( V_22 ) ) {
unsigned int V_31 ;
F_22 ( V_31 , V_44 ) ;
V_24 -> V_28 [ V_29 ] = V_31 ;
} else
F_23 ( V_24 -> V_28 [ V_29 ] , V_44 ) ;
V_44 += 4 ;
}
}
if ( F_11 ( V_22 ) )
V_24 -> V_28 [ V_40 ] = V_45 ;
if ( ! F_16 ( V_22 ) || ! ( F_30 ( V_22 ) & ( 1 << 15 ) ) )
V_24 -> V_46 -= V_41 ;
return V_51 ;
V_33:
V_24 -> V_46 -= V_41 ;
return V_34 ;
V_37:
F_32 ( V_50 L_11 ) ;
return V_38 ;
}
static unsigned long
F_35 ( T_5 V_52 )
{
T_6 V_53 = ( V_52 & ( 1 << 11 ) ) >> 11 ;
switch ( ( V_52 & 0xf800 ) >> 11 ) {
case 0x6000 >> 11 :
case 0x6800 >> 11 :
case 0x7000 >> 11 :
case 0x7800 >> 11 :
return 0xe5800000 |
( ( V_52 & ( 1 << 12 ) ) << ( 22 - 12 ) ) |
( V_53 << 20 ) |
( ( V_52 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_52 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_52 & ( 31 << 6 ) ) >>
( 6 - ( ( V_52 & ( 1 << 12 ) ) ? 0 : 2 ) ) ) ;
case 0x8000 >> 11 :
case 0x8800 >> 11 :
return 0xe1c000b0 |
( V_53 << 20 ) |
( ( V_52 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_52 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_52 & ( 7 << 6 ) ) >> ( 6 - 1 ) ) |
( ( V_52 & ( 3 << 9 ) ) >> ( 9 - 8 ) ) ;
case 0x5000 >> 11 :
case 0x5800 >> 11 :
{
static const T_6 V_54 [ 8 ] = {
0xe7800000 ,
0xe18000b0 ,
0xe7c00000 ,
0xe19000d0 ,
0xe7900000 ,
0xe19000b0 ,
0xe7d00000 ,
0xe19000f0
} ;
return V_54 [ ( V_52 & ( 7 << 9 ) ) >> 9 ] |
( ( V_52 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_52 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_52 & ( 7 << 6 ) ) >> ( 6 - 0 ) ) ;
}
case 0x4800 >> 11 :
return 0xe59f0000 |
( ( V_52 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_52 & 255 ) << ( 2 - 0 ) ) ;
case 0x9000 >> 11 :
case 0x9800 >> 11 :
return 0xe58d0000 |
( V_53 << 20 ) |
( ( V_52 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_52 & 255 ) << 2 ) ;
case 0xc000 >> 11 :
case 0xc800 >> 11 :
{
T_6 V_55 = ( V_52 & ( 7 << 8 ) ) >> 8 ;
T_6 V_56 = ( ( V_53 << V_55 ) & ( V_52 & 255 ) ) ? 0 : 1 << 21 ;
return 0xe8800000 | V_56 | ( V_53 << 20 ) | ( V_55 << 16 ) |
( V_52 & 255 ) ;
}
case 0xb000 >> 11 :
case 0xb800 >> 11 :
if ( ( V_52 & ( 3 << 9 ) ) == 0x0400 ) {
static const T_6 V_54 [ 4 ] = {
0xe92d0000 ,
0xe92d4000 ,
0xe8bd0000 ,
0xe8bd8000
} ;
return V_54 [ ( V_53 << 1 ) | ( ( V_52 & ( 1 << 8 ) ) >> 8 ) ] |
( V_52 & 255 ) ;
}
default:
return V_57 ;
}
}
static void *
F_36 ( unsigned long * V_58 , struct V_23 * V_24 ,
union V_25 * V_59 )
{
unsigned long V_22 = * V_58 ;
T_5 V_60 = ( V_22 >> 16 ) & 0xffff ;
T_5 V_61 = V_22 & 0xffff ;
V_59 -> V_27 = 0 ;
switch ( V_60 & 0xffe0 ) {
case 0xe880 :
case 0xe8a0 :
case 0xe900 :
case 0xe920 :
return F_27 ;
case 0xf840 :
if ( F_12 ( V_22 ) == 13 && ( V_61 & 0x09ff ) == 0x0904 ) {
T_6 V_53 = ! ! ( F_16 ( V_22 ) ) ;
const T_6 V_54 [ 2 ] = {
0xe92d0000 ,
0xe8bd0000 ,
} ;
* V_58 = V_54 [ V_53 ] | ( 1 << F_14 ( V_22 ) ) ;
return F_27 ;
}
break;
case 0xe860 :
case 0xe960 :
case 0xe8e0 :
case 0xe9e0 :
V_59 -> V_27 = ( V_61 & 0xff ) << 2 ;
case 0xe940 :
case 0xe9c0 :
return F_21 ;
default:
break;
}
return NULL ;
}
static int
F_37 ( unsigned long V_21 , unsigned int V_62 , struct V_23 * V_24 )
{
union V_25 V_26 ;
unsigned long V_22 = 0 , V_63 ;
int (* F_38)( unsigned long V_21 , unsigned long V_22 , struct V_23 * V_24 );
unsigned int type ;
T_7 V_64 ;
unsigned int V_33 ;
T_5 V_52 = 0 ;
int V_65 = 4 ;
int V_66 = 0 ;
V_63 = F_33 ( V_24 ) ;
V_64 = F_39 () ;
F_40 ( V_67 ) ;
if ( F_41 ( V_24 ) ) {
V_33 = F_42 ( V_52 , ( T_5 * ) ( V_63 & ~ 1 ) ) ;
if ( ! V_33 ) {
if ( F_3 () >= V_68 &&
F_43 ( V_52 ) ) {
T_5 V_61 = 0 ;
V_33 = F_42 ( V_61 , ( T_5 * ) ( V_63 + 2 ) ) ;
V_22 = ( V_52 << 16 ) | V_61 ;
V_66 = 1 ;
} else {
V_65 = 2 ;
V_22 = F_35 ( V_52 ) ;
}
}
} else
V_33 = F_42 ( V_22 , ( T_6 * ) V_63 ) ;
F_40 ( V_64 ) ;
if ( V_33 ) {
type = V_34 ;
goto V_69;
}
if ( F_15 ( V_24 ) )
goto V_30;
V_5 += 1 ;
V_70:
V_24 -> V_46 += V_65 ;
switch ( F_44 ( V_22 ) ) {
case 0x00000000 :
if ( F_45 ( V_22 ) )
V_26 . V_27 = ( V_22 & 0xf00 ) >> 4 | ( V_22 & 15 ) ;
else
V_26 . V_27 = V_24 -> V_28 [ F_46 ( V_22 ) ] ;
if ( ( V_22 & 0x000000f0 ) == 0x000000b0 ||
( V_22 & 0x001000f0 ) == 0x001000f0 )
F_38 = F_13 ;
else if ( ( V_22 & 0x001000f0 ) == 0x000000d0 ||
( V_22 & 0x001000f0 ) == 0x000000f0 )
F_38 = F_21 ;
else if ( ( V_22 & 0x01f00ff0 ) == 0x01000090 )
goto V_71;
else
goto V_37;
break;
case 0x04000000 :
V_26 . V_27 = F_47 ( V_22 ) ;
F_38 = F_26 ;
break;
case 0x06000000 :
V_26 . V_27 = V_24 -> V_28 [ F_46 ( V_22 ) ] ;
if ( F_48 ( V_22 ) ) {
unsigned int V_72 = F_49 ( V_22 ) ;
switch( F_50 ( V_22 ) ) {
case V_73 :
V_26 . V_27 <<= V_72 ;
break;
case V_74 :
V_26 . V_27 >>= V_72 ;
break;
case V_75 :
V_26 . V_76 >>= V_72 ;
break;
case V_77 :
if ( V_72 == 0 ) {
V_26 . V_27 >>= 1 ;
if ( V_24 -> V_78 & V_79 )
V_26 . V_27 |= 1 << 31 ;
} else
V_26 . V_27 = V_26 . V_27 >> V_72 |
V_26 . V_27 << ( 32 - V_72 ) ;
break;
}
}
F_38 = F_26 ;
break;
case 0x08000000 :
if ( V_66 )
F_38 = F_36 ( & V_22 , V_24 , & V_26 ) ;
else
F_38 = F_27 ;
break;
default:
goto V_37;
}
if ( ! F_38 )
goto V_37;
type = F_38 ( V_21 , V_22 , V_24 ) ;
if ( type == V_38 || type == V_34 ) {
V_24 -> V_46 -= V_65 ;
goto V_69;
}
if ( type == V_32 )
F_8 ( V_21 , V_22 , V_24 , V_26 ) ;
return 0 ;
V_69:
if ( type == V_38 )
goto V_37;
F_51 ( V_21 , V_62 , V_24 ) ;
return 0 ;
V_71:
F_32 ( V_50 L_12 ) ;
V_37:
F_32 ( V_50 L_13
L_14 ,
V_65 << 1 ,
V_65 == 2 ? V_52 : V_22 , V_63 ) ;
V_6 += 1 ;
return 1 ;
V_30:
V_4 += 1 ;
if ( V_12 & V_80 )
F_32 ( L_15
L_16 , V_81 -> V_82 ,
F_52 ( V_81 ) , V_63 ,
V_65 << 1 ,
V_65 == 2 ? V_52 : V_22 ,
V_21 , V_62 ) ;
if ( V_12 & V_83 )
goto V_70;
if ( V_12 & V_84 )
F_53 ( V_85 , V_81 ) ;
else {
F_54 () ;
if ( ! ( F_55 () -> V_86 & V_87 ) )
F_56 ( V_88 ) ;
}
return 0 ;
}
static int T_8 F_57 ( void )
{
#ifdef F_58
struct V_89 * V_90 ;
V_90 = F_59 ( L_17 , V_91 | V_92 , NULL ,
& V_93 ) ;
if ( ! V_90 )
return - V_94 ;
#endif
if ( F_3 () >= V_95 && ( V_96 & V_97 ) ) {
V_96 &= ~ V_98 ;
V_88 &= ~ V_98 ;
F_56 ( V_96 ) ;
V_12 = V_83 ;
}
F_60 ( 1 , F_37 , V_85 , V_99 ,
L_18 ) ;
if ( F_3 () <= V_95 ) {
F_60 ( 3 , F_37 , V_85 , V_99 ,
L_18 ) ;
}
return 0 ;
}
