static inline void F_1 ( unsigned long V_1 )
{
V_2 . V_3 = ( unsigned char ) V_1 ;
F_2 () ;
V_1 >>= 8 ;
V_2 . V_4 = ( unsigned char ) V_1 ;
F_2 () ;
V_1 >>= 8 ;
V_2 . V_5 = ( unsigned char ) V_1 ;
F_2 () ;
}
static inline unsigned long F_3 ( void )
{
unsigned long V_1 ;
V_1 = V_2 . V_3 ;
F_2 () ;
V_1 |= ( V_2 . V_4 & 0xff ) << 8 ;
F_2 () ;
V_1 |= ( V_2 . V_5 & 0xff ) << 16 ;
F_2 () ;
return V_1 ;
}
static int F_4 ( unsigned char V_6 )
{
int V_7 ;
unsigned long V_8 = F_5 ( V_9 ) , V_10 ;
if ( V_6 & 0x01 ) {
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 ) {
V_10 = V_12 [ V_7 ] . V_8 + V_12 [ V_7 ] . V_13 ;
if ( V_10 <= V_8 && V_8 <= V_10 + 4 )
return 1 ;
}
}
return 0 ;
}
static T_1 F_6 ( int V_14 , void * V_15 )
{
#ifdef F_7
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = F_8 ( V_17 ) ;
int V_6 ;
V_6 = V_20 . V_21 ;
F_9 ( V_22 , V_17 , L_1 ,
V_6 & 0xff ) ;
if ( V_6 & 0x80 ) {
if ( ! F_4 ( V_6 ) ) {
F_10 ( V_23 L_2 ,
F_5 ( V_9 ) ) ;
F_10 ( V_24 L_3 ) ;
}
}
if ( ( V_6 & 0x02 ) && ! ( V_6 & 0x40 ) ) {
V_25 = V_19 -> V_26 -
( F_5 ( V_9 ) - V_27 ) ;
F_11 ( V_28 , L_4 ,
V_25 ) ;
if ( ( signed int ) V_25 < 0 )
V_25 = 0 ;
if ( ( V_6 & 1 ) == 0 ) {
F_12 () ;
} else {
if ( V_25 & 0x1ff ) {
F_11 ( V_28 , L_5
L_6 ,
512 - ( V_25 & 0x1ff ) ) ;
V_25 = ( V_25 + 511 ) & ~ 0x1ff ;
}
}
V_20 . V_21 = 0 ;
}
if ( V_6 & 0x40 ) {
V_25 = 0 ;
if ( ( V_6 & 1 ) == 0 )
F_12 () ;
V_20 . V_21 = 0 ;
}
#endif
F_13 ( V_14 , V_15 ) ;
return V_29 ;
}
static T_1 F_14 ( int V_14 , void * V_15 )
{
#ifdef F_7
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = F_8 ( V_17 ) ;
int V_6 ;
V_2 . V_30 = 0x90 ;
V_6 = V_2 . V_30 ;
if ( ! ( V_6 & 0x01 ) ) {
F_10 ( V_24 L_7 , F_3 () ) ;
}
if ( V_31 && ( V_6 & 0x02 ) ) {
unsigned long V_32 ;
V_32 = F_3 () - V_27 ;
if ( V_32 & 15 )
F_10 ( V_23 L_8
L_9 , V_32 & 15 ) ;
V_25 = V_19 -> V_26 - V_32 ;
F_11 ( V_28 , L_4 ,
V_25 ) ;
} else
V_25 = 0 ;
V_31 = 0 ;
if ( V_33 ) {
memcpy ( V_33 , F_15 ( V_27 ) ,
V_19 -> V_26 - V_25 ) ;
V_33 = NULL ;
}
#endif
F_13 ( V_14 , V_15 ) ;
return V_29 ;
}
static void F_12 ( void )
{
int V_34 ;
char * V_35 , * V_36 ;
unsigned long V_37 ;
V_37 = F_5 ( V_9 ) ;
V_34 = V_37 & 3 ;
if ( V_34 ) {
V_37 ^= V_34 ;
F_11 ( V_28 , L_10 ,
V_34 , V_37 ) ;
V_36 = F_15 ( V_37 ) ;
F_11 ( V_28 , L_11 , V_36 ) ;
for ( V_35 = ( char * ) & V_20 . V_38 ; V_34 != 0 ; -- V_34 )
* V_36 ++ = * V_35 ++ ;
}
}
static void F_16 ( void )
{
if ( F_17 () )
return;
if ( F_18 ( F_14 ) )
F_19 () ;
}
static int F_20 ( struct V_16 * V_17 )
{
if ( F_17 () )
return 1 ;
if ( F_21 () )
return F_22 ( F_14 , V_17 ) ;
F_23 ( F_14 , V_17 ) ;
return 1 ;
}
static int T_2 F_24 ( char * V_39 )
{
int V_40 [ 8 ] ;
F_25 ( V_39 , F_26 ( V_40 ) , V_40 ) ;
if ( V_40 [ 0 ] < 1 ) {
F_10 ( L_12 ) ;
return 0 ;
}
if ( V_40 [ 0 ] >= 1 )
V_41 = V_40 [ 1 ] ;
if ( V_40 [ 0 ] >= 2 )
V_42 = V_40 [ 2 ] ;
if ( V_40 [ 0 ] >= 3 )
V_43 = V_40 [ 3 ] ;
if ( V_40 [ 0 ] >= 4 )
V_44 = V_40 [ 4 ] ;
if ( V_40 [ 0 ] >= 5 )
V_45 = V_40 [ 5 ] ;
if ( V_40 [ 0 ] >= 7 )
V_46 = V_40 [ 7 ] ;
return 1 ;
}
static unsigned long F_27 ( struct V_16 * V_17 ,
void * V_47 , unsigned long V_48 ,
int V_49 )
{
unsigned long V_8 = F_28 ( V_47 ) ;
F_11 ( V_28 , L_13
L_14 , V_17 -> V_50 , V_47 , V_8 , V_48 , V_49 ) ;
if ( ! F_17 () && ! F_29 ( V_8 ) ) {
if ( V_49 )
memcpy ( V_51 , V_47 , V_48 ) ;
else
V_33 = V_47 ;
V_8 = V_52 ;
}
V_27 = V_8 ;
F_30 ( V_8 , V_48 , V_49 ) ;
if ( V_48 == 0 )
F_10 ( V_53 L_15 ) ;
if ( F_17 () ) {
V_20 . V_21 = V_49 ;
F_31 ( V_9 , V_8 ) ;
F_31 ( V_54 , V_48 ) ;
V_20 . V_21 = V_49 | 2 ;
} else {
F_1 ( V_8 ) ;
V_49 <<= 8 ;
V_2 . V_30 = 0x90 | V_49 ;
V_2 . V_30 = 0x90 | ( V_49 ^ 0x100 ) ;
V_2 . V_30 = 0x90 | V_49 ;
F_32 ( 40 ) ;
V_2 . V_55 = ( V_48 + ( V_49 ? 511 : 0 ) ) >> 9 ;
F_32 ( 40 ) ;
V_2 . V_30 = 0x10 | V_49 ;
F_32 ( 40 ) ;
V_31 = 1 ;
}
return V_48 ;
}
static long F_33 ( struct V_16 * V_17 )
{
return V_25 ;
}
static int F_34 ( struct V_56 * V_57 )
{
unsigned char V_58 = V_57 -> V_59 [ 0 ] ;
if ( V_58 == V_60 || V_58 == V_61 ||
V_58 == V_62 )
return V_63 ;
else if ( V_58 == V_64 || V_58 == V_65 ||
V_58 == 0xa8 || V_58 == V_66 ||
V_58 == V_67 ) {
if ( V_57 -> V_68 -> type == V_69 && ! ( V_57 -> V_59 [ 1 ] & 1 ) )
return V_63 ;
else
return V_70 ;
} else
return V_71 ;
}
static unsigned long F_35 ( unsigned long V_72 ,
struct V_56 * V_57 , int V_73 )
{
unsigned long V_74 , V_75 ;
if ( F_17 () )
return V_72 ;
if ( V_73 ) {
V_74 = V_72 ;
} else {
if ( V_72 & 0x1ff )
V_74 = 0 ;
else {
switch ( F_34 ( V_57 ) ) {
case V_70 :
V_74 = V_72 ;
break;
case V_63 :
V_74 = 0 ;
break;
case V_71 :
default:
V_74 = ( V_72 < 1024 ) ? 0 : V_72 ;
break;
}
}
}
V_75 = ( V_51 && ! F_29 ( F_28 ( V_57 -> V_76 . V_77 ) ) ) ?
V_78 : 255 * 512 ;
if ( V_74 > V_75 )
V_74 = V_75 ;
if ( V_74 != V_72 )
F_11 ( V_28 , L_16
L_17 , V_74 , V_72 ) ;
return V_74 ;
}
static unsigned char F_36 ( unsigned char V_79 )
{
return V_80 [ V_79 * 2 ] ;
}
static void F_37 ( unsigned char V_79 , unsigned char V_81 )
{
V_80 [ V_79 * 2 ] = V_81 ;
}
static unsigned char F_38 ( unsigned char V_79 )
{
V_82 . V_30 = ( V_83 ) ( 0x88 + V_79 ) ;
return ( V_84 ) V_82 . V_55 ;
}
static void F_39 ( unsigned char V_79 , unsigned char V_81 )
{
V_82 . V_30 = ( V_83 ) ( 0x88 + V_79 ) ;
V_82 . V_55 = ( V_83 ) V_81 ;
}
static int F_40 ( struct V_56 * V_57 )
{
int V_85 ;
unsigned long V_86 ;
F_41 ( V_86 ) ;
#ifdef F_7
if ( F_17 () ) {
V_20 . V_21 = 0 ;
} else {
V_2 . V_30 = 0x90 ;
V_31 = 0 ;
V_33 = NULL ;
}
#endif
V_85 = F_42 ( V_57 ) ;
F_43 ( V_86 ) ;
return V_85 ;
}
static int T_2 F_44 ( struct V_87 * V_88 )
{
struct V_16 * V_17 ;
int error ;
struct V_89 * V_14 ;
int V_90 = 0 ;
V_14 = F_45 ( V_88 , V_91 , 0 ) ;
if ( ! V_14 )
return - V_92 ;
if ( F_46 ( V_93 ) ) {
V_94 = F_36 ;
V_95 = F_37 ;
} else {
V_94 = F_38 ;
V_95 = F_39 ;
}
if ( F_46 ( V_93 ) ) {
V_96 . V_97 = 16 ;
V_96 . V_98 = 8 ;
V_96 . V_99 = V_100 ;
} else {
V_96 . V_97 = 8 ;
V_96 . V_98 = 1 ;
V_96 . V_99 = V_101 ;
}
if ( V_41 > 0 )
V_96 . V_97 = V_41 ;
if ( V_42 > 0 )
V_96 . V_98 = V_42 ;
if ( F_46 ( V_93 ) && V_43 >= 0 )
V_96 . V_99 = V_43 ;
if ( V_44 >= 0 ) {
V_96 . V_102 = V_44 & 7 ;
} else {
if ( F_46 ( V_103 ) && F_47 () ) {
unsigned char V_104 = F_48 ( 16 ) ;
if ( V_104 & 0x80 )
V_96 . V_102 = V_104 & 7 ;
}
}
#ifdef F_7
if ( F_46 ( V_105 ) && ! F_46 ( V_106 ) &&
V_11 > 1 ) {
V_51 = F_49 ( V_78 , L_18 ) ;
if ( ! V_51 ) {
F_50 ( V_107 L_19 ) ;
return - V_108 ;
}
V_52 = F_51 ( V_51 ) ;
V_33 = 0 ;
}
#endif
V_17 = F_52 ( & V_96 ,
sizeof( struct V_18 ) ) ;
if ( ! V_17 ) {
error = - V_108 ;
goto V_109;
}
V_17 -> V_14 = V_14 -> V_110 ;
V_90 |= F_17 () ? 0 : V_111 ;
#ifdef F_53
V_90 |= V_45 > 0 ? V_112 : 0 ;
#endif
V_90 |= V_46 > 0 ? V_113 : 0 ;
error = F_54 ( V_17 , V_90 ) ;
if ( error )
goto V_114;
if ( F_17 () ) {
error = F_55 ( V_17 -> V_14 , F_6 , 0 ,
L_20 , V_17 ) ;
if ( error ) {
F_50 ( V_107 L_21 ,
V_17 -> V_14 ) ;
goto V_115;
}
V_116 . V_117 |= 0x80 ;
#ifdef F_7
V_20 . V_21 = 0 ;
V_25 = 0 ;
if ( V_118 ) {
struct V_18 * V_19 =
F_8 ( V_17 ) ;
V_19 -> V_119 = 4 ;
}
#endif
} else {
#ifdef F_7
V_25 = 0 ;
V_31 = 0 ;
V_120 = ( F_46 ( V_106 ) ? 0x00000000
: 0xff000000 ) ;
#endif
}
F_56 ( V_17 ) ;
error = F_57 ( V_17 , NULL ) ;
if ( error )
goto V_121;
F_58 ( V_88 , V_17 ) ;
F_59 ( V_17 ) ;
return 0 ;
V_121:
if ( F_17 () )
F_60 ( V_17 -> V_14 , V_17 ) ;
V_115:
F_61 ( V_17 ) ;
V_114:
F_62 ( V_17 ) ;
V_109:
if ( V_51 )
F_63 ( V_51 ) ;
return error ;
}
static int T_3 F_64 ( struct V_87 * V_88 )
{
struct V_16 * V_17 = F_65 ( V_88 ) ;
F_66 ( V_17 ) ;
if ( F_17 () )
F_60 ( V_17 -> V_14 , V_17 ) ;
F_61 ( V_17 ) ;
F_62 ( V_17 ) ;
if ( V_51 )
F_63 ( V_51 ) ;
return 0 ;
}
