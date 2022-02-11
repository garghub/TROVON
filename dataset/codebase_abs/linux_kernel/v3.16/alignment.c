static bool F_1 ( void )
{
return F_2 () >= V_1 && F_3 () & V_2 ;
}
static int F_4 ( int V_3 , bool V_4 )
{
if ( F_1 () && ! ( V_3 & ( V_5 | V_6 ) ) ) {
V_3 |= V_5 ;
if ( V_4 )
F_5 ( V_7 L_1 ) ;
}
return V_3 ;
}
static int F_6 ( struct V_8 * V_9 , void * V_10 )
{
F_7 ( V_9 , L_2 , V_11 ) ;
F_7 ( V_9 , L_3 , V_12 ) ;
F_7 ( V_9 , L_4 , V_13 ) ;
F_7 ( V_9 , L_5 , V_14 ) ;
F_7 ( V_9 , L_6 , V_15 ) ;
if ( F_2 () >= V_16 )
F_7 ( V_9 , L_7 , V_17 ) ;
F_7 ( V_9 , L_8 , V_18 ) ;
F_7 ( V_9 , L_9 , V_19 ,
V_20 [ V_19 ] ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_9 ( V_22 , F_6 , NULL ) ;
}
static T_1 F_10 ( struct V_22 * V_22 , const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
char V_26 ;
if ( V_24 > 0 ) {
if ( F_11 ( V_26 , V_23 ) )
return - V_27 ;
if ( V_26 >= '0' && V_26 <= '5' )
V_19 = F_4 ( V_26 - '0' , true ) ;
}
return V_24 ;
}
static void
F_12 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 , union V_32 V_33 )
{
if ( ! F_13 ( V_29 ) )
V_33 . V_34 = - V_33 . V_34 ;
if ( ! F_14 ( V_29 ) )
V_28 += V_33 . V_34 ;
if ( ! F_14 ( V_29 ) || F_15 ( V_29 ) )
V_31 -> V_35 [ F_16 ( V_29 ) ] = V_28 ;
}
static int
F_17 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 )
{
unsigned int V_36 = F_18 ( V_29 ) ;
V_14 += 1 ;
if ( F_19 ( V_31 ) )
goto V_37;
if ( F_20 ( V_29 ) ) {
unsigned long V_38 ;
F_21 ( V_38 , V_28 ) ;
if ( V_29 & 0x40 )
V_38 = ( signed long ) ( ( signed short ) V_38 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_22 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
return V_39 ;
V_37:
if ( F_20 ( V_29 ) ) {
unsigned long V_38 ;
F_23 ( V_38 , V_28 ) ;
if ( V_29 & 0x40 )
V_38 = ( signed long ) ( ( signed short ) V_38 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_24 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
return V_39 ;
V_40:
return V_41 ;
}
static int
F_25 ( unsigned long V_28 , unsigned long V_29 ,
struct V_30 * V_31 )
{
unsigned int V_36 = F_18 ( V_29 ) ;
unsigned int V_42 ;
int V_43 ;
if ( ( V_29 & 0xfe000000 ) == 0xe8000000 ) {
V_42 = ( V_29 >> 8 ) & 0xf ;
V_43 = ! ! ( F_20 ( V_29 ) ) ;
} else if ( ( ( V_36 & 1 ) == 1 ) || ( V_36 == 14 ) )
goto V_44;
else {
V_43 = ( ( V_29 & 0xf0 ) == 0xd0 ) ;
V_42 = V_36 + 1 ;
}
V_17 += 1 ;
if ( F_19 ( V_31 ) )
goto V_37;
if ( V_43 ) {
unsigned long V_38 ;
F_26 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
F_26 ( V_38 , V_28 + 4 ) ;
V_31 -> V_35 [ V_42 ] = V_38 ;
} else {
F_27 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_27 ( V_31 -> V_35 [ V_42 ] , V_28 + 4 ) ;
}
return V_39 ;
V_37:
if ( V_43 ) {
unsigned long V_38 ;
F_28 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
F_28 ( V_38 , V_28 + 4 ) ;
V_31 -> V_35 [ V_42 ] = V_38 ;
} else {
F_29 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_29 ( V_31 -> V_35 [ V_42 ] , V_28 + 4 ) ;
}
return V_39 ;
V_44:
return V_45 ;
V_40:
return V_41 ;
}
static int
F_30 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 )
{
unsigned int V_36 = F_18 ( V_29 ) ;
V_15 += 1 ;
if ( ( ! F_14 ( V_29 ) && F_15 ( V_29 ) ) || F_19 ( V_31 ) )
goto V_46;
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_26 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_27 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
return V_39 ;
V_46:
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_28 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_29 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
return V_39 ;
V_40:
return V_41 ;
}
static int
F_31 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 )
{
unsigned int V_36 , V_47 , V_48 , V_49 , V_50 ;
unsigned long V_51 , V_52 ;
if ( F_32 ( V_29 ) )
goto V_44;
V_48 = 4 ;
V_31 -> V_53 += V_48 ;
V_18 += 1 ;
V_49 = F_33 ( F_34 ( V_29 ) ) * 4 ;
V_47 = F_16 ( V_29 ) ;
V_52 = V_51 = V_31 -> V_35 [ V_47 ] ;
if ( ! F_13 ( V_29 ) )
V_49 = - V_49 ;
V_52 += V_49 ;
if ( ! F_13 ( V_29 ) )
V_51 = V_52 ;
if ( F_35 ( V_29 ) )
V_51 += 4 ;
#if ! ( V_54 V_55 ) && ! ( V_54 V_56 )
if ( V_28 != V_51 ) {
F_5 ( V_57 L_10
L_11 ,
F_36 ( V_31 ) , V_29 , V_28 , V_51 ) ;
F_37 ( V_31 ) ;
}
#endif
if ( F_19 ( V_31 ) ) {
for ( V_50 = F_34 ( V_29 ) , V_36 = 0 ; V_50 ;
V_50 >>= 1 , V_36 += 1 )
if ( V_50 & 1 ) {
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_28 ( V_38 , V_51 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_29 ( V_31 -> V_35 [ V_36 ] , V_51 ) ;
V_51 += 4 ;
}
} else {
for ( V_50 = F_34 ( V_29 ) , V_36 = 0 ; V_50 ;
V_50 >>= 1 , V_36 += 1 )
if ( V_50 & 1 ) {
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_26 ( V_38 , V_51 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_27 ( V_31 -> V_35 [ V_36 ] , V_51 ) ;
V_51 += 4 ;
}
}
if ( F_15 ( V_29 ) )
V_31 -> V_35 [ V_47 ] = V_52 ;
if ( ! F_20 ( V_29 ) || ! ( F_34 ( V_29 ) & ( 1 << 15 ) ) )
V_31 -> V_53 -= V_48 ;
return V_58 ;
V_40:
V_31 -> V_53 -= V_48 ;
return V_41 ;
V_44:
F_5 ( V_57 L_12 ) ;
return V_45 ;
}
static unsigned long
F_38 ( T_5 V_59 )
{
T_6 V_60 = ( V_59 & ( 1 << 11 ) ) >> 11 ;
switch ( ( V_59 & 0xf800 ) >> 11 ) {
case 0x6000 >> 11 :
case 0x6800 >> 11 :
case 0x7000 >> 11 :
case 0x7800 >> 11 :
return 0xe5800000 |
( ( V_59 & ( 1 << 12 ) ) << ( 22 - 12 ) ) |
( V_60 << 20 ) |
( ( V_59 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_59 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_59 & ( 31 << 6 ) ) >>
( 6 - ( ( V_59 & ( 1 << 12 ) ) ? 0 : 2 ) ) ) ;
case 0x8000 >> 11 :
case 0x8800 >> 11 :
return 0xe1c000b0 |
( V_60 << 20 ) |
( ( V_59 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_59 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_59 & ( 7 << 6 ) ) >> ( 6 - 1 ) ) |
( ( V_59 & ( 3 << 9 ) ) >> ( 9 - 8 ) ) ;
case 0x5000 >> 11 :
case 0x5800 >> 11 :
{
static const T_6 V_61 [ 8 ] = {
0xe7800000 ,
0xe18000b0 ,
0xe7c00000 ,
0xe19000d0 ,
0xe7900000 ,
0xe19000b0 ,
0xe7d00000 ,
0xe19000f0
} ;
return V_61 [ ( V_59 & ( 7 << 9 ) ) >> 9 ] |
( ( V_59 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_59 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_59 & ( 7 << 6 ) ) >> ( 6 - 0 ) ) ;
}
case 0x4800 >> 11 :
return 0xe59f0000 |
( ( V_59 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_59 & 255 ) << ( 2 - 0 ) ) ;
case 0x9000 >> 11 :
case 0x9800 >> 11 :
return 0xe58d0000 |
( V_60 << 20 ) |
( ( V_59 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_59 & 255 ) << 2 ) ;
case 0xc000 >> 11 :
case 0xc800 >> 11 :
{
T_6 V_62 = ( V_59 & ( 7 << 8 ) ) >> 8 ;
T_6 V_63 = ( ( V_60 << V_62 ) & ( V_59 & 255 ) ) ? 0 : 1 << 21 ;
return 0xe8800000 | V_63 | ( V_60 << 20 ) | ( V_62 << 16 ) |
( V_59 & 255 ) ;
}
case 0xb000 >> 11 :
case 0xb800 >> 11 :
if ( ( V_59 & ( 3 << 9 ) ) == 0x0400 ) {
static const T_6 V_61 [ 4 ] = {
0xe92d0000 ,
0xe92d4000 ,
0xe8bd0000 ,
0xe8bd8000
} ;
return V_61 [ ( V_60 << 1 ) | ( ( V_59 & ( 1 << 8 ) ) >> 8 ) ] |
( V_59 & 255 ) ;
}
default:
return V_64 ;
}
}
static void *
F_39 ( unsigned long * V_65 , struct V_30 * V_31 ,
union V_32 * V_66 )
{
unsigned long V_29 = * V_65 ;
T_5 V_67 = ( V_29 >> 16 ) & 0xffff ;
T_5 V_68 = V_29 & 0xffff ;
switch ( V_67 & 0xffe0 ) {
case 0xe880 :
case 0xe8a0 :
case 0xe900 :
case 0xe920 :
return F_31 ;
case 0xf840 :
if ( F_16 ( V_29 ) == 13 && ( V_68 & 0x09ff ) == 0x0904 ) {
T_6 V_60 = ! ! ( F_20 ( V_29 ) ) ;
const T_6 V_61 [ 2 ] = {
0xe92d0000 ,
0xe8bd0000 ,
} ;
* V_65 = V_61 [ V_60 ] | ( 1 << F_18 ( V_29 ) ) ;
return F_31 ;
}
break;
case 0xe860 :
case 0xe960 :
case 0xe8e0 :
case 0xe9e0 :
V_66 -> V_34 = ( V_68 & 0xff ) << 2 ;
case 0xe940 :
case 0xe9c0 :
return F_25 ;
default:
break;
}
return NULL ;
}
static int
F_40 ( unsigned long V_28 , unsigned int V_69 , struct V_30 * V_31 )
{
union V_32 V_70 ( V_33 ) ;
unsigned long V_29 = 0 , V_71 ;
int (* F_41)( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 );
unsigned int type ;
unsigned int V_40 ;
T_5 V_59 = 0 ;
int V_72 = 4 ;
int V_73 = 0 ;
if ( F_42 ( V_31 ) )
F_43 () ;
V_71 = F_36 ( V_31 ) ;
if ( F_44 ( V_31 ) ) {
T_5 * V_74 = ( T_5 * ) ( V_71 & ~ 1 ) ;
V_40 = F_45 ( V_74 , V_59 ) ;
V_59 = F_46 ( V_59 ) ;
if ( ! V_40 ) {
if ( F_2 () >= V_75 &&
F_47 ( V_59 ) ) {
T_5 V_68 = 0 ;
V_40 = F_45 ( V_74 + 1 , V_68 ) ;
V_68 = F_46 ( V_68 ) ;
V_29 = F_48 ( V_59 , V_68 ) ;
V_73 = 1 ;
} else {
V_72 = 2 ;
V_29 = F_38 ( V_59 ) ;
}
}
} else {
V_40 = F_45 ( V_71 , V_29 ) ;
V_29 = F_49 ( V_29 ) ;
}
if ( V_40 ) {
type = V_41 ;
goto V_76;
}
if ( F_19 ( V_31 ) )
goto V_37;
V_12 += 1 ;
V_77:
V_31 -> V_53 += V_72 ;
switch ( F_50 ( V_29 ) ) {
case 0x00000000 :
if ( F_51 ( V_29 ) )
V_33 . V_34 = ( V_29 & 0xf00 ) >> 4 | ( V_29 & 15 ) ;
else
V_33 . V_34 = V_31 -> V_35 [ F_52 ( V_29 ) ] ;
if ( ( V_29 & 0x000000f0 ) == 0x000000b0 ||
( V_29 & 0x001000f0 ) == 0x001000f0 )
F_41 = F_17 ;
else if ( ( V_29 & 0x001000f0 ) == 0x000000d0 ||
( V_29 & 0x001000f0 ) == 0x000000f0 )
F_41 = F_25 ;
else if ( ( V_29 & 0x01f00ff0 ) == 0x01000090 )
goto V_78;
else
goto V_44;
break;
case 0x04000000 :
V_33 . V_34 = F_53 ( V_29 ) ;
F_41 = F_30 ;
break;
case 0x06000000 :
V_33 . V_34 = V_31 -> V_35 [ F_52 ( V_29 ) ] ;
if ( F_54 ( V_29 ) ) {
unsigned int V_79 = F_55 ( V_29 ) ;
switch( F_56 ( V_29 ) ) {
case V_80 :
V_33 . V_34 <<= V_79 ;
break;
case V_81 :
V_33 . V_34 >>= V_79 ;
break;
case V_82 :
V_33 . V_83 >>= V_79 ;
break;
case V_84 :
if ( V_79 == 0 ) {
V_33 . V_34 >>= 1 ;
if ( V_31 -> V_85 & V_86 )
V_33 . V_34 |= 1 << 31 ;
} else
V_33 . V_34 = V_33 . V_34 >> V_79 |
V_33 . V_34 << ( 32 - V_79 ) ;
break;
}
}
F_41 = F_30 ;
break;
case 0x08000000 :
if ( V_73 ) {
V_33 . V_34 = 0 ;
F_41 = F_39 ( & V_29 , V_31 , & V_33 ) ;
} else {
V_33 . V_34 = 0 ;
F_41 = F_31 ;
}
break;
default:
goto V_44;
}
if ( ! F_41 )
goto V_44;
type = F_41 ( V_28 , V_29 , V_31 ) ;
if ( type == V_45 || type == V_41 ) {
V_31 -> V_53 -= V_72 ;
goto V_76;
}
if ( type == V_39 )
F_12 ( V_28 , V_29 , V_31 , V_33 ) ;
return 0 ;
V_76:
if ( type == V_45 )
goto V_44;
F_57 ( V_28 , V_69 , V_31 ) ;
return 0 ;
V_78:
F_5 ( V_57 L_13 ) ;
V_44:
F_5 ( V_57 L_14
L_15 ,
V_72 << 1 ,
V_72 == 2 ? V_59 : V_29 , V_71 ) ;
V_13 += 1 ;
return 1 ;
V_37:
V_11 += 1 ;
if ( V_19 & V_87 )
F_5 ( L_16
L_17 , V_88 -> V_89 ,
F_58 ( V_88 ) , V_71 ,
V_72 << 1 ,
V_72 == 2 ? V_59 : V_29 ,
V_28 , V_69 ) ;
if ( V_19 & V_5 )
goto V_77;
if ( V_19 & V_6 ) {
T_7 V_90 ;
V_90 . V_91 = V_92 ;
V_90 . V_93 = 0 ;
V_90 . V_94 = V_95 ;
V_90 . V_96 = ( void T_2 * ) V_28 ;
F_59 ( V_90 . V_91 , & V_90 , V_88 ) ;
} else {
F_60 () ;
if ( ! ( F_61 () -> V_97 & V_98 ) )
F_62 ( V_99 ) ;
}
return 0 ;
}
static int T_8 F_63 ( char * V_100 )
{
F_62 ( F_64 ( V_101 ) ) ;
return 1 ;
}
static int T_8 F_65 ( void )
{
#ifdef F_66
struct V_102 * V_103 ;
V_103 = F_67 ( L_18 , V_104 | V_105 , NULL ,
& V_106 ) ;
if ( ! V_103 )
return - V_107 ;
#endif
if ( F_1 () ) {
F_62 ( F_64 ( V_101 ) ) ;
V_19 = F_4 ( V_19 , false ) ;
}
V_99 = F_3 () & ~ V_101 ;
F_68 ( V_108 , F_40 , V_92 , V_95 ,
L_19 ) ;
if ( F_2 () <= V_1 ) {
F_68 ( 3 , F_40 , V_92 , V_95 ,
L_19 ) ;
}
return 0 ;
}
