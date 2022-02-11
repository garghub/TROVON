static bool F_1 ( void )
{
return F_2 () >= V_1 && F_3 () & V_2 ;
}
static int F_4 ( int V_3 , bool V_4 )
{
if ( F_1 () && ! ( V_3 & ( V_5 | V_6 ) ) ) {
V_3 |= V_5 ;
if ( V_4 )
F_5 ( L_1 ) ;
}
return V_3 ;
}
static int F_6 ( struct V_7 * V_8 , void * V_9 )
{
F_7 ( V_8 , L_2 , V_10 ) ;
F_7 ( V_8 , L_3 , V_11 , V_12 ) ;
F_7 ( V_8 , L_4 , V_13 ) ;
F_7 ( V_8 , L_5 , V_14 ) ;
F_7 ( V_8 , L_6 , V_15 ) ;
if ( F_2 () >= V_16 )
F_7 ( V_8 , L_7 , V_17 ) ;
F_7 ( V_8 , L_8 , V_18 ) ;
F_7 ( V_8 , L_9 , V_19 ,
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
unsigned int V_40 = F_23 () ;
F_24 ( V_38 , V_28 ) ;
F_25 ( V_40 ) ;
if ( V_29 & 0x40 )
V_38 = ( signed long ) ( ( signed short ) V_38 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else {
unsigned int V_40 = F_23 () ;
F_26 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_25 ( V_40 ) ;
}
return V_39 ;
V_41:
return V_42 ;
}
static int
F_27 ( unsigned long V_28 , unsigned long V_29 ,
struct V_30 * V_31 )
{
unsigned int V_36 = F_18 ( V_29 ) ;
unsigned int V_43 ;
int V_44 ;
if ( ( V_29 & 0xfe000000 ) == 0xe8000000 ) {
V_43 = ( V_29 >> 8 ) & 0xf ;
V_44 = ! ! ( F_20 ( V_29 ) ) ;
} else if ( ( ( V_36 & 1 ) == 1 ) || ( V_36 == 14 ) )
goto V_45;
else {
V_44 = ( ( V_29 & 0xf0 ) == 0xd0 ) ;
V_43 = V_36 + 1 ;
}
V_17 += 1 ;
if ( F_19 ( V_31 ) )
goto V_37;
if ( V_44 ) {
unsigned long V_38 ;
F_28 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
F_28 ( V_38 , V_28 + 4 ) ;
V_31 -> V_35 [ V_43 ] = V_38 ;
} else {
F_29 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_29 ( V_31 -> V_35 [ V_43 ] , V_28 + 4 ) ;
}
return V_39 ;
V_37:
if ( V_44 ) {
unsigned long V_38 , V_46 ;
unsigned int V_40 = F_23 () ;
F_30 ( V_38 , V_28 ) ;
F_30 ( V_46 , V_28 + 4 ) ;
F_25 ( V_40 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
V_31 -> V_35 [ V_43 ] = V_46 ;
} else {
unsigned int V_40 = F_23 () ;
F_31 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_31 ( V_31 -> V_35 [ V_43 ] , V_28 + 4 ) ;
F_25 ( V_40 ) ;
}
return V_39 ;
V_45:
return V_47 ;
V_41:
return V_42 ;
}
static int
F_32 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 )
{
unsigned int V_36 = F_18 ( V_29 ) ;
V_15 += 1 ;
if ( ( ! F_14 ( V_29 ) && F_15 ( V_29 ) ) || F_19 ( V_31 ) )
goto V_48;
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_28 ( V_38 , V_28 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_29 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
return V_39 ;
V_48:
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
unsigned int V_40 = F_23 () ;
F_30 ( V_38 , V_28 ) ;
F_25 ( V_40 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else {
unsigned int V_40 = F_23 () ;
F_31 ( V_31 -> V_35 [ V_36 ] , V_28 ) ;
F_25 ( V_40 ) ;
}
return V_39 ;
V_41:
return V_42 ;
}
static int
F_33 ( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 )
{
unsigned int V_36 , V_49 , V_50 , V_51 , V_52 ;
unsigned long V_53 , V_54 ;
if ( F_34 ( V_29 ) )
goto V_45;
V_50 = 4 ;
V_31 -> V_55 += V_50 ;
V_18 += 1 ;
V_51 = F_35 ( F_36 ( V_29 ) ) * 4 ;
V_49 = F_16 ( V_29 ) ;
V_54 = V_53 = V_31 -> V_35 [ V_49 ] ;
if ( ! F_13 ( V_29 ) )
V_51 = - V_51 ;
V_54 += V_51 ;
if ( ! F_13 ( V_29 ) )
V_53 = V_54 ;
if ( F_37 ( V_29 ) )
V_53 += 4 ;
#if ! ( V_56 V_57 ) && ! ( V_56 V_58 )
if ( V_28 != V_53 ) {
F_38 ( L_10
L_11 ,
F_39 ( V_31 ) , V_29 , V_28 , V_53 ) ;
F_40 ( V_31 ) ;
}
#endif
if ( F_19 ( V_31 ) ) {
unsigned int V_40 = F_23 () ;
for ( V_52 = F_36 ( V_29 ) , V_36 = 0 ; V_52 ;
V_52 >>= 1 , V_36 += 1 )
if ( V_52 & 1 ) {
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_30 ( V_38 , V_53 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_31 ( V_31 -> V_35 [ V_36 ] , V_53 ) ;
V_53 += 4 ;
}
F_25 ( V_40 ) ;
} else {
for ( V_52 = F_36 ( V_29 ) , V_36 = 0 ; V_52 ;
V_52 >>= 1 , V_36 += 1 )
if ( V_52 & 1 ) {
if ( F_20 ( V_29 ) ) {
unsigned int V_38 ;
F_28 ( V_38 , V_53 ) ;
V_31 -> V_35 [ V_36 ] = V_38 ;
} else
F_29 ( V_31 -> V_35 [ V_36 ] , V_53 ) ;
V_53 += 4 ;
}
}
if ( F_15 ( V_29 ) )
V_31 -> V_35 [ V_49 ] = V_54 ;
if ( ! F_20 ( V_29 ) || ! ( F_36 ( V_29 ) & ( 1 << 15 ) ) )
V_31 -> V_55 -= V_50 ;
return V_59 ;
V_41:
V_31 -> V_55 -= V_50 ;
return V_42 ;
V_45:
F_38 ( L_12 ) ;
return V_47 ;
}
static unsigned long
F_41 ( T_5 V_60 )
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
F_42 ( unsigned long * V_66 , struct V_30 * V_31 ,
union V_32 * V_67 )
{
unsigned long V_29 = * V_66 ;
T_5 V_68 = ( V_29 >> 16 ) & 0xffff ;
T_5 V_69 = V_29 & 0xffff ;
switch ( V_68 & 0xffe0 ) {
case 0xe880 :
case 0xe8a0 :
case 0xe900 :
case 0xe920 :
return F_33 ;
case 0xf840 :
if ( F_16 ( V_29 ) == 13 && ( V_69 & 0x09ff ) == 0x0904 ) {
T_6 V_61 = ! ! ( F_20 ( V_29 ) ) ;
const T_6 V_62 [ 2 ] = {
0xe92d0000 ,
0xe8bd0000 ,
} ;
* V_66 = V_62 [ V_61 ] | ( 1 << F_18 ( V_29 ) ) ;
return F_33 ;
}
break;
case 0xe860 :
case 0xe960 :
case 0xe8e0 :
case 0xe9e0 :
V_67 -> V_34 = ( V_69 & 0xff ) << 2 ;
case 0xe940 :
case 0xe9c0 :
return F_27 ;
default:
break;
}
return NULL ;
}
static int
F_43 ( unsigned long V_28 , unsigned int V_70 , struct V_30 * V_31 )
{
union V_32 V_71 ( V_33 ) ;
unsigned long V_29 = 0 , V_72 ;
int (* F_44)( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 );
unsigned int type ;
unsigned int V_41 ;
T_5 V_60 = 0 ;
int V_73 = 4 ;
int V_74 = 0 ;
if ( F_45 ( V_31 ) )
F_46 () ;
V_72 = F_39 ( V_31 ) ;
if ( F_47 ( V_31 ) ) {
T_5 * V_75 = ( T_5 * ) ( V_72 & ~ 1 ) ;
V_41 = F_48 ( V_75 , V_60 ) ;
V_60 = F_49 ( V_60 ) ;
if ( ! V_41 ) {
if ( F_2 () >= V_76 &&
F_50 ( V_60 ) ) {
T_5 V_69 = 0 ;
V_41 = F_48 ( V_75 + 1 , V_69 ) ;
V_69 = F_49 ( V_69 ) ;
V_29 = F_51 ( V_60 , V_69 ) ;
V_74 = 1 ;
} else {
V_73 = 2 ;
V_29 = F_41 ( V_60 ) ;
}
}
} else {
V_41 = F_48 ( ( void * ) V_72 , V_29 ) ;
V_29 = F_52 ( V_29 ) ;
}
if ( V_41 ) {
type = V_42 ;
goto V_77;
}
if ( F_19 ( V_31 ) )
goto V_37;
V_11 += 1 ;
V_12 = ( void * ) F_39 ( V_31 ) ;
V_78:
V_31 -> V_55 += V_73 ;
switch ( F_53 ( V_29 ) ) {
case 0x00000000 :
if ( F_54 ( V_29 ) )
V_33 . V_34 = ( V_29 & 0xf00 ) >> 4 | ( V_29 & 15 ) ;
else
V_33 . V_34 = V_31 -> V_35 [ F_55 ( V_29 ) ] ;
if ( ( V_29 & 0x000000f0 ) == 0x000000b0 ||
( V_29 & 0x001000f0 ) == 0x001000f0 )
F_44 = F_17 ;
else if ( ( V_29 & 0x001000f0 ) == 0x000000d0 ||
( V_29 & 0x001000f0 ) == 0x000000f0 )
F_44 = F_27 ;
else if ( ( V_29 & 0x01f00ff0 ) == 0x01000090 )
goto V_79;
else
goto V_45;
break;
case 0x04000000 :
if ( F_56 ( V_29 ) == 0xf0000000 )
goto V_45;
V_33 . V_34 = F_57 ( V_29 ) ;
F_44 = F_32 ;
break;
case 0x06000000 :
V_33 . V_34 = V_31 -> V_35 [ F_55 ( V_29 ) ] ;
if ( F_58 ( V_29 ) ) {
unsigned int V_80 = F_59 ( V_29 ) ;
switch( F_60 ( V_29 ) ) {
case V_81 :
V_33 . V_34 <<= V_80 ;
break;
case V_82 :
V_33 . V_34 >>= V_80 ;
break;
case V_83 :
V_33 . V_84 >>= V_80 ;
break;
case V_85 :
if ( V_80 == 0 ) {
V_33 . V_34 >>= 1 ;
if ( V_31 -> V_86 & V_87 )
V_33 . V_34 |= 1 << 31 ;
} else
V_33 . V_34 = V_33 . V_34 >> V_80 |
V_33 . V_34 << ( 32 - V_80 ) ;
break;
}
}
F_44 = F_32 ;
break;
case 0x08000000 :
if ( V_74 ) {
V_33 . V_34 = 0 ;
F_44 = F_42 ( & V_29 , V_31 , & V_33 ) ;
} else {
V_33 . V_34 = 0 ;
F_44 = F_33 ;
}
break;
default:
goto V_45;
}
if ( ! F_44 )
goto V_45;
type = F_44 ( V_28 , V_29 , V_31 ) ;
if ( type == V_47 || type == V_42 ) {
V_31 -> V_55 -= V_73 ;
goto V_77;
}
if ( type == V_39 )
F_12 ( V_28 , V_29 , V_31 , V_33 ) ;
return 0 ;
V_77:
if ( type == V_47 )
goto V_45;
F_61 ( V_28 , V_70 , V_31 ) ;
return 0 ;
V_79:
F_38 ( L_13 ) ;
V_45:
F_38 ( L_14
L_15 ,
V_73 << 1 ,
V_73 == 2 ? V_60 : V_29 , V_72 ) ;
V_13 += 1 ;
return 1 ;
V_37:
V_10 += 1 ;
if ( V_19 & V_88 )
F_62 ( L_16
L_17 , V_89 -> V_90 ,
F_63 ( V_89 ) , V_72 ,
V_73 << 1 ,
V_73 == 2 ? V_60 : V_29 ,
V_28 , V_70 ) ;
if ( V_19 & V_5 )
goto V_78;
if ( V_19 & V_6 ) {
T_7 V_91 ;
V_91 . V_92 = V_93 ;
V_91 . V_94 = 0 ;
V_91 . V_95 = V_96 ;
V_91 . V_97 = ( void T_2 * ) V_28 ;
F_64 ( V_91 . V_92 , & V_91 , V_89 ) ;
} else {
F_65 () ;
if ( ! ( F_66 () -> V_98 & V_99 ) )
F_67 ( V_100 ) ;
}
return 0 ;
}
static int T_8 F_68 ( char * V_101 )
{
F_67 ( F_69 ( V_102 ) ) ;
return 1 ;
}
static int T_8 F_70 ( void )
{
#ifdef F_71
struct V_103 * V_104 ;
V_104 = F_72 ( L_18 , V_105 | V_106 , NULL ,
& V_107 ) ;
if ( ! V_104 )
return - V_108 ;
#endif
if ( F_1 () ) {
F_67 ( F_69 ( V_102 ) ) ;
V_19 = F_4 ( V_19 , false ) ;
}
V_100 = F_3 () & ~ V_102 ;
F_73 ( V_109 , F_43 , V_93 , V_96 ,
L_19 ) ;
if ( F_2 () <= V_1 ) {
F_73 ( 3 , F_43 , V_93 , V_96 ,
L_19 ) ;
}
return 0 ;
}
