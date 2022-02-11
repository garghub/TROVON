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
F_36 ( L_10
L_11 ,
F_37 ( V_31 ) , V_29 , V_28 , V_51 ) ;
F_38 ( V_31 ) ;
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
return V_57 ;
V_40:
V_31 -> V_53 -= V_48 ;
return V_41 ;
V_44:
F_36 ( L_12 ) ;
return V_45 ;
}
static unsigned long
F_39 ( T_5 V_58 )
{
T_6 V_59 = ( V_58 & ( 1 << 11 ) ) >> 11 ;
switch ( ( V_58 & 0xf800 ) >> 11 ) {
case 0x6000 >> 11 :
case 0x6800 >> 11 :
case 0x7000 >> 11 :
case 0x7800 >> 11 :
return 0xe5800000 |
( ( V_58 & ( 1 << 12 ) ) << ( 22 - 12 ) ) |
( V_59 << 20 ) |
( ( V_58 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_58 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_58 & ( 31 << 6 ) ) >>
( 6 - ( ( V_58 & ( 1 << 12 ) ) ? 0 : 2 ) ) ) ;
case 0x8000 >> 11 :
case 0x8800 >> 11 :
return 0xe1c000b0 |
( V_59 << 20 ) |
( ( V_58 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_58 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_58 & ( 7 << 6 ) ) >> ( 6 - 1 ) ) |
( ( V_58 & ( 3 << 9 ) ) >> ( 9 - 8 ) ) ;
case 0x5000 >> 11 :
case 0x5800 >> 11 :
{
static const T_6 V_60 [ 8 ] = {
0xe7800000 ,
0xe18000b0 ,
0xe7c00000 ,
0xe19000d0 ,
0xe7900000 ,
0xe19000b0 ,
0xe7d00000 ,
0xe19000f0
} ;
return V_60 [ ( V_58 & ( 7 << 9 ) ) >> 9 ] |
( ( V_58 & ( 7 << 0 ) ) << ( 12 - 0 ) ) |
( ( V_58 & ( 7 << 3 ) ) << ( 16 - 3 ) ) |
( ( V_58 & ( 7 << 6 ) ) >> ( 6 - 0 ) ) ;
}
case 0x4800 >> 11 :
return 0xe59f0000 |
( ( V_58 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_58 & 255 ) << ( 2 - 0 ) ) ;
case 0x9000 >> 11 :
case 0x9800 >> 11 :
return 0xe58d0000 |
( V_59 << 20 ) |
( ( V_58 & ( 7 << 8 ) ) << ( 12 - 8 ) ) |
( ( V_58 & 255 ) << 2 ) ;
case 0xc000 >> 11 :
case 0xc800 >> 11 :
{
T_6 V_61 = ( V_58 & ( 7 << 8 ) ) >> 8 ;
T_6 V_62 = ( ( V_59 << V_61 ) & ( V_58 & 255 ) ) ? 0 : 1 << 21 ;
return 0xe8800000 | V_62 | ( V_59 << 20 ) | ( V_61 << 16 ) |
( V_58 & 255 ) ;
}
case 0xb000 >> 11 :
case 0xb800 >> 11 :
if ( ( V_58 & ( 3 << 9 ) ) == 0x0400 ) {
static const T_6 V_60 [ 4 ] = {
0xe92d0000 ,
0xe92d4000 ,
0xe8bd0000 ,
0xe8bd8000
} ;
return V_60 [ ( V_59 << 1 ) | ( ( V_58 & ( 1 << 8 ) ) >> 8 ) ] |
( V_58 & 255 ) ;
}
default:
return V_63 ;
}
}
static void *
F_40 ( unsigned long * V_64 , struct V_30 * V_31 ,
union V_32 * V_65 )
{
unsigned long V_29 = * V_64 ;
T_5 V_66 = ( V_29 >> 16 ) & 0xffff ;
T_5 V_67 = V_29 & 0xffff ;
switch ( V_66 & 0xffe0 ) {
case 0xe880 :
case 0xe8a0 :
case 0xe900 :
case 0xe920 :
return F_31 ;
case 0xf840 :
if ( F_16 ( V_29 ) == 13 && ( V_67 & 0x09ff ) == 0x0904 ) {
T_6 V_59 = ! ! ( F_20 ( V_29 ) ) ;
const T_6 V_60 [ 2 ] = {
0xe92d0000 ,
0xe8bd0000 ,
} ;
* V_64 = V_60 [ V_59 ] | ( 1 << F_18 ( V_29 ) ) ;
return F_31 ;
}
break;
case 0xe860 :
case 0xe960 :
case 0xe8e0 :
case 0xe9e0 :
V_65 -> V_34 = ( V_67 & 0xff ) << 2 ;
case 0xe940 :
case 0xe9c0 :
return F_25 ;
default:
break;
}
return NULL ;
}
static int
F_41 ( unsigned long V_28 , unsigned int V_68 , struct V_30 * V_31 )
{
union V_32 V_69 ( V_33 ) ;
unsigned long V_29 = 0 , V_70 ;
int (* F_42)( unsigned long V_28 , unsigned long V_29 , struct V_30 * V_31 );
unsigned int type ;
unsigned int V_40 ;
T_5 V_58 = 0 ;
int V_71 = 4 ;
int V_72 = 0 ;
if ( F_43 ( V_31 ) )
F_44 () ;
V_70 = F_37 ( V_31 ) ;
if ( F_45 ( V_31 ) ) {
T_5 * V_73 = ( T_5 * ) ( V_70 & ~ 1 ) ;
V_40 = F_46 ( V_73 , V_58 ) ;
V_58 = F_47 ( V_58 ) ;
if ( ! V_40 ) {
if ( F_2 () >= V_74 &&
F_48 ( V_58 ) ) {
T_5 V_67 = 0 ;
V_40 = F_46 ( V_73 + 1 , V_67 ) ;
V_67 = F_47 ( V_67 ) ;
V_29 = F_49 ( V_58 , V_67 ) ;
V_72 = 1 ;
} else {
V_71 = 2 ;
V_29 = F_39 ( V_58 ) ;
}
}
} else {
V_40 = F_46 ( V_70 , V_29 ) ;
V_29 = F_50 ( V_29 ) ;
}
if ( V_40 ) {
type = V_41 ;
goto V_75;
}
if ( F_19 ( V_31 ) )
goto V_37;
V_11 += 1 ;
V_12 = ( void * ) F_37 ( V_31 ) ;
V_76:
V_31 -> V_53 += V_71 ;
switch ( F_51 ( V_29 ) ) {
case 0x00000000 :
if ( F_52 ( V_29 ) )
V_33 . V_34 = ( V_29 & 0xf00 ) >> 4 | ( V_29 & 15 ) ;
else
V_33 . V_34 = V_31 -> V_35 [ F_53 ( V_29 ) ] ;
if ( ( V_29 & 0x000000f0 ) == 0x000000b0 ||
( V_29 & 0x001000f0 ) == 0x001000f0 )
F_42 = F_17 ;
else if ( ( V_29 & 0x001000f0 ) == 0x000000d0 ||
( V_29 & 0x001000f0 ) == 0x000000f0 )
F_42 = F_25 ;
else if ( ( V_29 & 0x01f00ff0 ) == 0x01000090 )
goto V_77;
else
goto V_44;
break;
case 0x04000000 :
if ( F_54 ( V_29 ) == 0xf0000000 )
goto V_44;
V_33 . V_34 = F_55 ( V_29 ) ;
F_42 = F_30 ;
break;
case 0x06000000 :
V_33 . V_34 = V_31 -> V_35 [ F_53 ( V_29 ) ] ;
if ( F_56 ( V_29 ) ) {
unsigned int V_78 = F_57 ( V_29 ) ;
switch( F_58 ( V_29 ) ) {
case V_79 :
V_33 . V_34 <<= V_78 ;
break;
case V_80 :
V_33 . V_34 >>= V_78 ;
break;
case V_81 :
V_33 . V_82 >>= V_78 ;
break;
case V_83 :
if ( V_78 == 0 ) {
V_33 . V_34 >>= 1 ;
if ( V_31 -> V_84 & V_85 )
V_33 . V_34 |= 1 << 31 ;
} else
V_33 . V_34 = V_33 . V_34 >> V_78 |
V_33 . V_34 << ( 32 - V_78 ) ;
break;
}
}
F_42 = F_30 ;
break;
case 0x08000000 :
if ( V_72 ) {
V_33 . V_34 = 0 ;
F_42 = F_40 ( & V_29 , V_31 , & V_33 ) ;
} else {
V_33 . V_34 = 0 ;
F_42 = F_31 ;
}
break;
default:
goto V_44;
}
if ( ! F_42 )
goto V_44;
type = F_42 ( V_28 , V_29 , V_31 ) ;
if ( type == V_45 || type == V_41 ) {
V_31 -> V_53 -= V_71 ;
goto V_75;
}
if ( type == V_39 )
F_12 ( V_28 , V_29 , V_31 , V_33 ) ;
return 0 ;
V_75:
if ( type == V_45 )
goto V_44;
F_59 ( V_28 , V_68 , V_31 ) ;
return 0 ;
V_77:
F_36 ( L_13 ) ;
V_44:
F_36 ( L_14
L_15 ,
V_71 << 1 ,
V_71 == 2 ? V_58 : V_29 , V_70 ) ;
V_13 += 1 ;
return 1 ;
V_37:
V_10 += 1 ;
if ( V_19 & V_86 )
F_60 ( L_16
L_17 , V_87 -> V_88 ,
F_61 ( V_87 ) , V_70 ,
V_71 << 1 ,
V_71 == 2 ? V_58 : V_29 ,
V_28 , V_68 ) ;
if ( V_19 & V_5 )
goto V_76;
if ( V_19 & V_6 ) {
T_7 V_89 ;
V_89 . V_90 = V_91 ;
V_89 . V_92 = 0 ;
V_89 . V_93 = V_94 ;
V_89 . V_95 = ( void T_2 * ) V_28 ;
F_62 ( V_89 . V_90 , & V_89 , V_87 ) ;
} else {
F_63 () ;
if ( ! ( F_64 () -> V_96 & V_97 ) )
F_65 ( V_98 ) ;
}
return 0 ;
}
static int T_8 F_66 ( char * V_99 )
{
F_65 ( F_67 ( V_100 ) ) ;
return 1 ;
}
static int T_8 F_68 ( void )
{
#ifdef F_69
struct V_101 * V_102 ;
V_102 = F_70 ( L_18 , V_103 | V_104 , NULL ,
& V_105 ) ;
if ( ! V_102 )
return - V_106 ;
#endif
if ( F_1 () ) {
F_65 ( F_67 ( V_100 ) ) ;
V_19 = F_4 ( V_19 , false ) ;
}
V_98 = F_3 () & ~ V_100 ;
F_71 ( V_107 , F_41 , V_91 , V_94 ,
L_19 ) ;
if ( F_2 () <= V_1 ) {
F_71 ( 3 , F_41 , V_91 , V_94 ,
L_19 ) ;
}
return 0 ;
}
