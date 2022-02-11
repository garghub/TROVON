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
int V_6 ;
V_6 = V_16 . V_17 ;
F_8 ( V_18 , L_1 ,
V_19 -> V_20 , V_6 & 0xff ) ;
if ( V_6 & 0x80 ) {
if ( ! F_4 ( V_6 ) ) {
F_9 ( V_21 L_2 ,
F_5 ( V_9 ) ) ;
F_9 ( V_22 L_3 ) ;
}
}
if ( ( V_6 & 0x02 ) && ! ( V_6 & 0x40 ) ) {
V_23 = V_24 - ( F_5 ( V_9 ) - V_25 ) ;
F_8 ( V_26 , L_4 ,
V_23 ) ;
if ( ( signed int ) V_23 < 0 )
V_23 = 0 ;
if ( ( V_6 & 1 ) == 0 ) {
F_10 () ;
} else {
if ( V_23 & 0x1ff ) {
F_8 ( V_26 , L_5
L_6 ,
512 - ( V_23 & 0x1ff ) ) ;
V_23 = ( V_23 + 511 ) & ~ 0x1ff ;
}
}
V_16 . V_17 = 0 ;
}
if ( V_6 & 0x40 ) {
V_23 = 0 ;
if ( ( V_6 & 1 ) == 0 )
F_10 () ;
V_16 . V_17 = 0 ;
}
#endif
F_11 ( V_14 , V_15 ) ;
return V_27 ;
}
static T_1 F_12 ( int V_14 , void * V_15 )
{
#ifdef F_7
int V_6 ;
V_2 . V_28 = 0x90 ;
V_6 = V_2 . V_28 ;
if ( ! ( V_6 & 0x01 ) ) {
F_9 ( V_22 L_7 , F_3 () ) ;
}
if ( V_29 && ( V_6 & 0x02 ) ) {
unsigned long V_30 ;
V_30 = F_3 () - V_25 ;
if ( V_30 & 15 )
F_9 ( V_21 L_8
L_9 , V_30 & 15 ) ;
V_23 = V_24 - V_30 ;
F_8 ( V_26 , L_4 ,
V_23 ) ;
} else
V_23 = 0 ;
V_29 = 0 ;
if ( V_31 ) {
memcpy ( V_31 , F_13 ( V_25 ) ,
V_24 - V_23 ) ;
V_31 = NULL ;
}
#endif
F_11 ( V_14 , V_15 ) ;
return V_27 ;
}
static void F_10 ( void )
{
int V_32 ;
char * V_33 , * V_34 ;
unsigned long V_35 ;
V_35 = F_5 ( V_9 ) ;
V_32 = V_35 & 3 ;
if ( V_32 ) {
V_35 ^= V_32 ;
F_8 ( V_26 , L_10 ,
V_32 , V_35 ) ;
V_34 = F_13 ( V_35 ) ;
F_8 ( V_26 , L_11 , V_34 ) ;
for ( V_33 = ( char * ) & V_16 . V_36 ; V_32 != 0 ; -- V_32 )
* V_34 ++ = * V_33 ++ ;
}
}
static void F_14 ( void )
{
if ( F_15 () )
return;
if ( F_16 ( F_12 ) )
F_17 () ;
}
static int F_18 ( struct V_37 * V_38 )
{
if ( F_15 () )
return 1 ;
if ( F_19 () )
return F_20 ( F_12 , V_38 ) ;
F_21 ( F_12 , V_38 ) ;
return 1 ;
}
static int T_2 F_22 ( char * V_39 )
{
int V_40 [ 6 ] ;
F_23 ( V_39 , F_24 ( V_40 ) , V_40 ) ;
if ( V_40 [ 0 ] < 1 ) {
F_9 ( L_12 ) ;
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
#ifdef F_25
if ( V_40 [ 0 ] >= 5 )
V_45 = V_40 [ 5 ] ;
#endif
return 1 ;
}
static void T_2 F_26 ( void )
{
unsigned long V_46 ;
F_9 ( L_13 ) ;
F_27 ( V_47 ,
F_28 ( F_29 ( V_48 ) ) ) ;
F_27 ( V_49 , V_50 | V_51 ) ;
F_30 ( 50 ) ;
F_27 ( V_49 , V_50 ) ;
F_29 ( V_52 ) ;
V_46 = V_53 + V_54 ;
while ( F_31 ( V_53 , V_46 ) )
F_32 () ;
F_9 ( L_14 ) ;
}
static unsigned long F_33 ( struct V_37 * V_38 ,
void * V_55 , unsigned long V_56 ,
int V_57 )
{
unsigned long V_8 = F_34 ( V_55 ) ;
F_8 ( V_26 , L_15
L_16 , V_38 -> V_20 , V_55 , V_8 , V_56 , V_57 ) ;
if ( ! F_15 () && ! F_35 ( V_8 ) ) {
if ( V_57 )
memcpy ( V_58 , V_55 , V_56 ) ;
else
V_31 = V_55 ;
V_8 = V_59 ;
}
V_25 = V_8 ;
F_36 ( V_8 , V_56 , V_57 ) ;
if ( V_56 == 0 )
F_9 ( V_60 L_17 ) ;
if ( F_15 () ) {
V_16 . V_17 = V_57 ;
F_37 ( V_9 , V_8 ) ;
F_37 ( V_61 , V_56 ) ;
V_16 . V_17 = V_57 | 2 ;
} else {
F_1 ( V_8 ) ;
V_57 <<= 8 ;
V_2 . V_28 = 0x90 | V_57 ;
V_2 . V_28 = 0x90 | ( V_57 ^ 0x100 ) ;
V_2 . V_28 = 0x90 | V_57 ;
F_30 ( 40 ) ;
V_2 . V_62 = ( V_56 + ( V_57 ? 511 : 0 ) ) >> 9 ;
F_30 ( 40 ) ;
V_2 . V_28 = 0x10 | V_57 ;
F_30 ( 40 ) ;
V_29 = 1 ;
}
return V_56 ;
}
static long F_38 ( struct V_37 * V_38 )
{
return V_23 ;
}
static int F_39 ( struct V_63 * V_64 )
{
unsigned char V_65 = V_64 -> V_66 [ 0 ] ;
if ( V_65 == V_67 || V_65 == V_68 ||
V_65 == V_69 )
return V_70 ;
else if ( V_65 == V_71 || V_65 == V_72 ||
V_65 == 0xa8 || V_65 == V_73 ||
V_65 == V_74 ) {
if ( V_64 -> V_75 -> type == V_76 && ! ( V_64 -> V_66 [ 1 ] & 1 ) )
return V_70 ;
else
return V_77 ;
} else
return V_78 ;
}
static unsigned long F_40 ( unsigned long V_79 ,
struct V_63 * V_64 , int V_80 )
{
unsigned long V_81 , V_82 ;
if ( F_15 () )
return V_79 ;
if ( V_80 ) {
V_81 = V_79 ;
} else {
if ( V_79 & 0x1ff )
V_81 = 0 ;
else {
switch ( F_39 ( V_64 ) ) {
case V_77 :
V_81 = V_79 ;
break;
case V_70 :
V_81 = 0 ;
break;
case V_78 :
default:
V_81 = ( V_79 < 1024 ) ? 0 : V_79 ;
break;
}
}
}
V_82 = ( V_58 && ! F_35 ( F_34 ( V_64 -> V_83 . V_84 ) ) ) ?
V_85 : 255 * 512 ;
if ( V_81 > V_82 )
V_81 = V_82 ;
if ( V_81 != V_79 )
F_8 ( V_26 , L_18
L_19 , V_81 , V_79 ) ;
return V_81 ;
}
static unsigned char F_41 ( unsigned char V_86 )
{
return V_87 [ V_86 * 2 ] ;
}
static void F_42 ( unsigned char V_86 , unsigned char V_88 )
{
V_87 [ V_86 * 2 ] = V_88 ;
}
static unsigned char F_43 ( unsigned char V_86 )
{
V_89 . V_28 = ( V_90 ) ( 0x88 + V_86 ) ;
return ( V_91 ) V_89 . V_62 ;
}
static void F_44 ( unsigned char V_86 , unsigned char V_88 )
{
V_89 . V_28 = ( V_90 ) ( 0x88 + V_86 ) ;
V_89 . V_62 = ( V_90 ) V_88 ;
}
static int F_45 ( struct V_63 * V_64 )
{
int V_92 ;
unsigned long V_93 ;
F_46 ( V_93 ) ;
#ifdef F_7
if ( F_15 () ) {
V_16 . V_17 = 0 ;
} else {
V_2 . V_28 = 0x90 ;
V_29 = 0 ;
V_31 = NULL ;
}
#endif
V_92 = F_47 ( V_64 ) ;
F_48 ( V_93 ) ;
return V_92 ;
}
static int T_2 F_49 ( struct V_94 * V_95 )
{
struct V_37 * V_38 ;
int error ;
struct V_96 * V_14 ;
int V_97 = 0 ;
V_14 = F_50 ( V_95 , V_98 , 0 ) ;
if ( ! V_14 )
return - V_99 ;
if ( F_51 ( V_100 ) ) {
V_101 = F_41 ;
V_102 = F_42 ;
} else {
V_101 = F_43 ;
V_102 = F_44 ;
}
if ( F_51 ( V_100 ) ) {
V_103 . V_104 = 16 ;
V_103 . V_105 = 8 ;
V_103 . V_106 = V_107 ;
} else {
V_103 . V_104 = 8 ;
V_103 . V_105 = 1 ;
V_103 . V_106 = V_108 ;
}
if ( V_41 > 0 )
V_103 . V_104 = V_41 ;
if ( V_42 > 0 )
V_103 . V_105 = V_42 ;
if ( F_51 ( V_100 ) && V_43 >= 0 )
V_103 . V_106 = V_43 ;
if ( V_44 >= 0 ) {
V_103 . V_109 = V_44 & 7 ;
} else {
if ( F_51 ( V_110 ) && F_52 () ) {
unsigned char V_111 = F_53 ( 14 ) ;
if ( V_111 & 0x80 )
V_103 . V_109 = V_111 & 7 ;
}
}
#ifdef F_7
if ( F_51 ( V_112 ) && ! F_51 ( V_113 ) &&
V_11 > 1 ) {
V_58 = F_54 ( V_85 , L_20 ) ;
if ( ! V_58 ) {
F_55 ( V_114 L_21 ) ;
return - V_115 ;
}
V_59 = F_56 ( V_58 ) ;
V_31 = 0 ;
}
#endif
V_38 = F_57 ( & V_103 ,
sizeof( struct V_116 ) ) ;
if ( ! V_38 ) {
error = - V_115 ;
goto V_117;
}
V_19 = V_38 ;
#ifdef F_58
F_26 () ;
#endif
V_38 -> V_14 = V_14 -> V_118 ;
V_97 |= F_15 () ? 0 : V_119 ;
#ifdef F_25
V_97 |= V_45 > 0 ? V_120 : 0 ;
#endif
F_59 ( V_38 , V_97 ) ;
if ( F_15 () ) {
error = F_60 ( V_38 -> V_14 , F_6 , 0 ,
L_22 , V_38 ) ;
if ( error ) {
F_55 ( V_114 L_23 ,
V_38 -> V_14 ) ;
goto V_121;
}
V_122 . V_123 |= 0x80 ;
#ifdef F_7
V_16 . V_17 = 0 ;
V_23 = 0 ;
if ( V_124 ) {
struct V_116 * V_125 =
F_61 ( V_38 ) ;
V_125 -> V_126 = 4 ;
}
#endif
} else {
#ifdef F_7
V_23 = 0 ;
V_29 = 0 ;
V_127 = ( F_51 ( V_113 ) ? 0x00000000
: 0xff000000 ) ;
#endif
}
error = F_62 ( V_38 , NULL ) ;
if ( error )
goto V_128;
F_63 ( V_95 , V_38 ) ;
F_64 ( V_38 ) ;
return 0 ;
V_128:
if ( F_15 () )
F_65 ( V_38 -> V_14 , V_38 ) ;
V_121:
F_66 ( V_38 ) ;
F_67 ( V_38 ) ;
V_117:
if ( V_58 )
F_68 ( V_58 ) ;
return error ;
}
static int T_3 F_69 ( struct V_94 * V_95 )
{
struct V_37 * V_38 = F_70 ( V_95 ) ;
F_71 ( V_38 ) ;
if ( F_15 () )
F_65 ( V_38 -> V_14 , V_38 ) ;
F_66 ( V_38 ) ;
F_67 ( V_38 ) ;
if ( V_58 )
F_68 ( V_58 ) ;
return 0 ;
}
