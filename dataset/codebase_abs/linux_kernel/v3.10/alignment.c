static bool F_1 ( void )
{
return F_2 () >= V_1 && ( V_2 & V_3 ) ;
}
static int F_3 ( int V_4 , bool V_5 )
{
if ( F_1 () && ! ( V_4 & ( V_6 | V_7 ) ) ) {
V_4 |= V_6 ;
if ( V_5 )
F_4 ( V_8 L_1 ) ;
}
return V_4 ;
}
static int F_5 ( struct V_9 * V_10 , void * V_11 )
{
F_6 ( V_10 , L_2 , V_12 ) ;
F_6 ( V_10 , L_3 , V_13 ) ;
F_6 ( V_10 , L_4 , V_14 ) ;
F_6 ( V_10 , L_5 , V_15 ) ;
F_6 ( V_10 , L_6 , V_16 ) ;
if ( F_2 () >= V_17 )
F_6 ( V_10 , L_7 , V_18 ) ;
F_6 ( V_10 , L_8 , V_19 ) ;
F_6 ( V_10 , L_9 , V_20 ,
V_21 [ V_20 ] ) ;
return 0 ;
}
static int F_7 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_8 ( V_23 , F_5 , NULL ) ;
}
static T_1 F_9 ( struct V_23 * V_23 , const char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
char V_27 ;
if ( V_25 > 0 ) {
if ( F_10 ( V_27 , V_24 ) )
return - V_28 ;
if ( V_27 >= '0' && V_27 <= '5' )
V_20 = F_3 ( V_27 - '0' , true ) ;
}
return V_25 ;
}
static void
F_11 ( unsigned long V_29 , unsigned long V_30 , struct V_31 * V_32 , union V_33 V_34 )
{
if ( ! F_12 ( V_30 ) )
V_34 . V_35 = - V_34 . V_35 ;
if ( ! F_13 ( V_30 ) )
V_29 += V_34 . V_35 ;
if ( ! F_13 ( V_30 ) || F_14 ( V_30 ) )
V_32 -> V_36 [ F_15 ( V_30 ) ] = V_29 ;
}
static int
F_16 ( unsigned long V_29 , unsigned long V_30 , struct V_31 * V_32 )
{
unsigned int V_37 = F_17 ( V_30 ) ;
V_15 += 1 ;
if ( F_18 ( V_32 ) )
goto V_38;
if ( F_19 ( V_30 ) ) {
unsigned long V_39 ;
F_20 ( V_39 , V_29 ) ;
if ( V_30 & 0x40 )
V_39 = ( signed long ) ( ( signed short ) V_39 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_21 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
return V_40 ;
V_38:
if ( F_19 ( V_30 ) ) {
unsigned long V_39 ;
F_22 ( V_39 , V_29 ) ;
if ( V_30 & 0x40 )
V_39 = ( signed long ) ( ( signed short ) V_39 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_23 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
return V_40 ;
V_41:
return V_42 ;
}
static int
F_24 ( unsigned long V_29 , unsigned long V_30 ,
struct V_31 * V_32 )
{
unsigned int V_37 = F_17 ( V_30 ) ;
unsigned int V_43 ;
int V_44 ;
if ( ( V_30 & 0xfe000000 ) == 0xe8000000 ) {
V_43 = ( V_30 >> 8 ) & 0xf ;
V_44 = ! ! ( F_19 ( V_30 ) ) ;
} else if ( ( ( V_37 & 1 ) == 1 ) || ( V_37 == 14 ) )
goto V_45;
else {
V_44 = ( ( V_30 & 0xf0 ) == 0xd0 ) ;
V_43 = V_37 + 1 ;
}
V_18 += 1 ;
if ( F_18 ( V_32 ) )
goto V_38;
if ( V_44 ) {
unsigned long V_39 ;
F_25 ( V_39 , V_29 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
F_25 ( V_39 , V_29 + 4 ) ;
V_32 -> V_36 [ V_43 ] = V_39 ;
} else {
F_26 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
F_26 ( V_32 -> V_36 [ V_43 ] , V_29 + 4 ) ;
}
return V_40 ;
V_38:
if ( V_44 ) {
unsigned long V_39 ;
F_27 ( V_39 , V_29 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
F_27 ( V_39 , V_29 + 4 ) ;
V_32 -> V_36 [ V_43 ] = V_39 ;
} else {
F_28 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
F_28 ( V_32 -> V_36 [ V_43 ] , V_29 + 4 ) ;
}
return V_40 ;
V_45:
return V_46 ;
V_41:
return V_42 ;
}
static int
F_29 ( unsigned long V_29 , unsigned long V_30 , struct V_31 * V_32 )
{
unsigned int V_37 = F_17 ( V_30 ) ;
V_16 += 1 ;
if ( ( ! F_13 ( V_30 ) && F_14 ( V_30 ) ) || F_18 ( V_32 ) )
goto V_47;
if ( F_19 ( V_30 ) ) {
unsigned int V_39 ;
F_25 ( V_39 , V_29 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_26 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
return V_40 ;
V_47:
if ( F_19 ( V_30 ) ) {
unsigned int V_39 ;
F_27 ( V_39 , V_29 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_28 ( V_32 -> V_36 [ V_37 ] , V_29 ) ;
return V_40 ;
V_41:
return V_42 ;
}
static int
F_30 ( unsigned long V_29 , unsigned long V_30 , struct V_31 * V_32 )
{
unsigned int V_37 , V_48 , V_49 , V_50 , V_51 ;
unsigned long V_52 , V_53 ;
if ( F_31 ( V_30 ) )
goto V_45;
V_49 = 4 ;
V_32 -> V_54 += V_49 ;
V_19 += 1 ;
V_50 = F_32 ( F_33 ( V_30 ) ) * 4 ;
V_48 = F_15 ( V_30 ) ;
V_53 = V_52 = V_32 -> V_36 [ V_48 ] ;
if ( ! F_12 ( V_30 ) )
V_50 = - V_50 ;
V_53 += V_50 ;
if ( ! F_12 ( V_30 ) )
V_52 = V_53 ;
if ( F_34 ( V_30 ) )
V_52 += 4 ;
#if ! ( V_55 V_56 ) && ! ( V_55 V_57 )
if ( V_29 != V_52 ) {
F_4 ( V_58 L_10
L_11 ,
F_35 ( V_32 ) , V_30 , V_29 , V_52 ) ;
F_36 ( V_32 ) ;
}
#endif
if ( F_18 ( V_32 ) ) {
for ( V_51 = F_33 ( V_30 ) , V_37 = 0 ; V_51 ;
V_51 >>= 1 , V_37 += 1 )
if ( V_51 & 1 ) {
if ( F_19 ( V_30 ) ) {
unsigned int V_39 ;
F_27 ( V_39 , V_52 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_28 ( V_32 -> V_36 [ V_37 ] , V_52 ) ;
V_52 += 4 ;
}
} else {
for ( V_51 = F_33 ( V_30 ) , V_37 = 0 ; V_51 ;
V_51 >>= 1 , V_37 += 1 )
if ( V_51 & 1 ) {
if ( F_19 ( V_30 ) ) {
unsigned int V_39 ;
F_25 ( V_39 , V_52 ) ;
V_32 -> V_36 [ V_37 ] = V_39 ;
} else
F_26 ( V_32 -> V_36 [ V_37 ] , V_52 ) ;
V_52 += 4 ;
}
}
if ( F_14 ( V_30 ) )
V_32 -> V_36 [ V_48 ] = V_53 ;
if ( ! F_19 ( V_30 ) || ! ( F_33 ( V_30 ) & ( 1 << 15 ) ) )
V_32 -> V_54 -= V_49 ;
return V_59 ;
V_41:
V_32 -> V_54 -= V_49 ;
return V_42 ;
V_45:
F_4 ( V_58 L_12 ) ;
return V_46 ;
}
static unsigned long
F_37 ( T_5 V_60 )
{
T_6 V_61 = ( V_60 & ( 1 << 11 ) ) >> 11 ;
switch ( ( V_60 & 0xf800 ) >> 11 ) {
case 0x6000 >> 11 :
case 0x6800 >> 11 :
case 0x7000 >> 11 :
case 0x7800 >> 11 :
return 0xe5800000 |
( ( V_60 & ( 1 << 12 ) ) << ( 22 - 12 ) ) |
( V_61 << 20 ) |
( ( V_60 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_60 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_60 & ( 31 << 6 ) ) >>
( 6 - ( ( V_60 & ( 1 << 12 ) ) ? 0 : 2 ) ) ) ;
case 0x8000 >> 11 :
case 0x8800 >> 11 :
return 0xe1c000b0 |
( V_61 << 20 ) |
( ( V_60 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_60 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_60 & ( 7 << 6 ) ) >> ( 6 - 1 ) ) |
( ( V_60 & ( 3 << 9 ) ) >> ( 9 - 8 ) ) ;
case 0x5000 >> 11 :
case 0x5800 >> 11 :
{
static const T_6 V_62 [ 8 ] = {
0xe7800000 ,
0xe18000b0 ,
0xe7c00000 ,
0xe19000d0 ,
0xe7900000 ,
0xe19000b0 ,
0xe7d00000 ,
0xe19000f0
} ;
return V_62 [ ( V_60 & ( 7 << 9 ) ) >> 9 ] |
( ( V_60 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_60 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_60 & ( 7 << 6 ) ) >> ( 6 - 0 ) ) ;
}
case 0x4800 >> 11 :
return 0xe59f0000 |
( ( V_60 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_60 & 255 ) << ( 2 - 0 ) ) ;
case 0x9000 >> 11 :
case 0x9800 >> 11 :
return 0xe58d0000 |
( V_61 << 20 ) |
( ( V_60 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_60 & 255 ) << 2 ) ;
case 0xc000 >> 11 :
case 0xc800 >> 11 :
{
T_6 V_63 = ( V_60 & ( 7 << 8 ) ) >> 8 ;
T_6 V_64 = ( ( V_61 << V_63 ) & ( V_60 & 255 ) ) ? 0 : 1 << 21 ;
return 0xe8800000 | V_64 | ( V_61 << 20 ) | ( V_63 << 16 ) |
( V_60 & 255 ) ;
}
case 0xb000 >> 11 :
case 0xb800 >> 11 :
if ( ( V_60 & ( 3 << 9 ) ) == 0x0400 ) {
static const T_6 V_62 [ 4 ] = {
0xe92d0000 ,
0xe92d4000 ,
0xe8bd0000 ,
0xe8bd8000
} ;
return V_62 [ ( V_61 << 1 ) | ( ( V_60 & ( 1 << 8 ) ) >> 8 ) ] |
( V_60 & 255 ) ;
}
default:
return V_65 ;
}
}
static void *
F_38 ( unsigned long * V_66 , struct V_31 * V_32 ,
union V_33 * V_67 )
{
unsigned long V_30 = * V_66 ;
T_5 V_68 = ( V_30 >> 16 ) & 0xffff ;
T_5 V_69 = V_30 & 0xffff ;
switch ( V_68 & 0xffe0 ) {
case 0xe880 :
case 0xe8a0 :
case 0xe900 :
case 0xe920 :
return F_30 ;
case 0xf840 :
if ( F_15 ( V_30 ) == 13 && ( V_69 & 0x09ff ) == 0x0904 ) {
T_6 V_61 = ! ! ( F_19 ( V_30 ) ) ;
const T_6 V_62 [ 2 ] = {
0xe92d0000 ,
0xe8bd0000 ,
} ;
* V_66 = V_62 [ V_61 ] | ( 1 << F_17 ( V_30 ) ) ;
return F_30 ;
}
break;
case 0xe860 :
case 0xe960 :
case 0xe8e0 :
case 0xe9e0 :
V_67 -> V_35 = ( V_69 & 0xff ) << 2 ;
case 0xe940 :
case 0xe9c0 :
return F_24 ;
default:
break;
}
return NULL ;
}
static int
F_39 ( unsigned long V_29 , unsigned int V_70 , struct V_31 * V_32 )
{
union V_33 V_71 ( V_34 ) ;
unsigned long V_30 = 0 , V_72 ;
int (* F_40)( unsigned long V_29 , unsigned long V_30 , struct V_31 * V_32 );
unsigned int type ;
unsigned int V_41 ;
T_5 V_60 = 0 ;
int V_73 = 4 ;
int V_74 = 0 ;
if ( F_41 ( V_32 ) )
F_42 () ;
V_72 = F_35 ( V_32 ) ;
if ( F_43 ( V_32 ) ) {
T_5 * V_75 = ( T_5 * ) ( V_72 & ~ 1 ) ;
V_41 = F_44 ( V_75 , V_60 ) ;
if ( ! V_41 ) {
if ( F_2 () >= V_76 &&
F_45 ( V_60 ) ) {
T_5 V_69 = 0 ;
V_41 = F_44 ( V_75 + 1 , V_69 ) ;
V_30 = ( V_60 << 16 ) | V_69 ;
V_74 = 1 ;
} else {
V_73 = 2 ;
V_30 = F_37 ( V_60 ) ;
}
}
} else
V_41 = F_44 ( V_72 , V_30 ) ;
if ( V_41 ) {
type = V_42 ;
goto V_77;
}
if ( F_18 ( V_32 ) )
goto V_38;
V_13 += 1 ;
V_78:
V_32 -> V_54 += V_73 ;
switch ( F_46 ( V_30 ) ) {
case 0x00000000 :
if ( F_47 ( V_30 ) )
V_34 . V_35 = ( V_30 & 0xf00 ) >> 4 | ( V_30 & 15 ) ;
else
V_34 . V_35 = V_32 -> V_36 [ F_48 ( V_30 ) ] ;
if ( ( V_30 & 0x000000f0 ) == 0x000000b0 ||
( V_30 & 0x001000f0 ) == 0x001000f0 )
F_40 = F_16 ;
else if ( ( V_30 & 0x001000f0 ) == 0x000000d0 ||
( V_30 & 0x001000f0 ) == 0x000000f0 )
F_40 = F_24 ;
else if ( ( V_30 & 0x01f00ff0 ) == 0x01000090 )
goto V_79;
else
goto V_45;
break;
case 0x04000000 :
V_34 . V_35 = F_49 ( V_30 ) ;
F_40 = F_29 ;
break;
case 0x06000000 :
V_34 . V_35 = V_32 -> V_36 [ F_48 ( V_30 ) ] ;
if ( F_50 ( V_30 ) ) {
unsigned int V_80 = F_51 ( V_30 ) ;
switch( F_52 ( V_30 ) ) {
case V_81 :
V_34 . V_35 <<= V_80 ;
break;
case V_82 :
V_34 . V_35 >>= V_80 ;
break;
case V_83 :
V_34 . V_84 >>= V_80 ;
break;
case V_85 :
if ( V_80 == 0 ) {
V_34 . V_35 >>= 1 ;
if ( V_32 -> V_86 & V_87 )
V_34 . V_35 |= 1 << 31 ;
} else
V_34 . V_35 = V_34 . V_35 >> V_80 |
V_34 . V_35 << ( 32 - V_80 ) ;
break;
}
}
F_40 = F_29 ;
break;
case 0x08000000 :
if ( V_74 ) {
V_34 . V_35 = 0 ;
F_40 = F_38 ( & V_30 , V_32 , & V_34 ) ;
} else {
V_34 . V_35 = 0 ;
F_40 = F_30 ;
}
break;
default:
goto V_45;
}
if ( ! F_40 )
goto V_45;
type = F_40 ( V_29 , V_30 , V_32 ) ;
if ( type == V_46 || type == V_42 ) {
V_32 -> V_54 -= V_73 ;
goto V_77;
}
if ( type == V_40 )
F_11 ( V_29 , V_30 , V_32 , V_34 ) ;
return 0 ;
V_77:
if ( type == V_46 )
goto V_45;
F_53 ( V_29 , V_70 , V_32 ) ;
return 0 ;
V_79:
F_4 ( V_58 L_13 ) ;
V_45:
F_4 ( V_58 L_14
L_15 ,
V_73 << 1 ,
V_73 == 2 ? V_60 : V_30 , V_72 ) ;
V_14 += 1 ;
return 1 ;
V_38:
V_12 += 1 ;
if ( V_20 & V_88 )
F_4 ( L_16
L_17 , V_89 -> V_90 ,
F_54 ( V_89 ) , V_72 ,
V_73 << 1 ,
V_73 == 2 ? V_60 : V_30 ,
V_29 , V_70 ) ;
if ( V_20 & V_6 )
goto V_78;
if ( V_20 & V_7 ) {
T_7 V_91 ;
V_91 . V_92 = V_93 ;
V_91 . V_94 = 0 ;
V_91 . V_95 = V_96 ;
V_91 . V_97 = ( void T_2 * ) V_29 ;
F_55 ( V_91 . V_92 , & V_91 , V_89 ) ;
} else {
F_56 () ;
if ( ! ( F_57 () -> V_98 & V_99 ) )
F_58 ( V_100 ) ;
}
return 0 ;
}
static int T_8 F_59 ( void )
{
#ifdef F_60
struct V_101 * V_102 ;
V_102 = F_61 ( L_18 , V_103 | V_104 , NULL ,
& V_105 ) ;
if ( ! V_102 )
return - V_106 ;
#endif
#ifdef F_62
if ( F_1 () ) {
V_2 &= ~ V_107 ;
V_100 &= ~ V_107 ;
F_58 ( V_2 ) ;
V_20 = F_3 ( V_20 , false ) ;
}
#endif
F_63 ( V_108 , F_39 , V_93 , V_96 ,
L_19 ) ;
if ( F_2 () <= V_1 ) {
F_63 ( 3 , F_39 , V_93 , V_96 ,
L_19 ) ;
}
return 0 ;
}
