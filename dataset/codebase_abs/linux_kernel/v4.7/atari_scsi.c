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
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = F_7 ( V_17 ) ;
int V_6 ;
V_6 = V_20 . V_21 ;
F_8 ( V_22 , V_17 , L_1 ,
V_6 & 0xff ) ;
if ( V_6 & 0x80 ) {
if ( ! F_4 ( V_6 ) ) {
F_9 ( V_23 L_2 ,
F_5 ( V_9 ) ) ;
F_9 ( V_24 L_3 ) ;
}
}
if ( ( V_6 & 0x02 ) && ! ( V_6 & 0x40 ) ) {
V_25 = V_19 -> V_26 -
( F_5 ( V_9 ) - V_27 ) ;
F_10 ( V_28 , L_4 ,
V_25 ) ;
if ( ( signed int ) V_25 < 0 )
V_25 = 0 ;
if ( ( V_6 & 1 ) == 0 ) {
F_11 () ;
} else {
if ( V_25 & 0x1ff ) {
F_10 ( V_28 , L_5
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
F_11 () ;
V_20 . V_21 = 0 ;
}
F_12 ( V_14 , V_15 ) ;
return V_29 ;
}
static T_1 F_13 ( int V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = F_7 ( V_17 ) ;
int V_6 ;
V_2 . V_30 = 0x90 ;
V_6 = V_2 . V_30 ;
if ( ! ( V_6 & 0x01 ) ) {
F_9 ( V_24 L_7 , F_3 () ) ;
}
if ( V_31 && ( V_6 & 0x02 ) ) {
unsigned long V_32 ;
V_32 = F_3 () - V_27 ;
if ( V_32 & 15 )
F_9 ( V_23 L_8
L_9 , V_32 & 15 ) ;
V_25 = V_19 -> V_26 - V_32 ;
F_10 ( V_28 , L_4 ,
V_25 ) ;
} else
V_25 = 0 ;
V_31 = 0 ;
if ( V_33 ) {
memcpy ( V_33 , F_14 ( V_27 ) ,
V_19 -> V_26 - V_25 ) ;
V_33 = NULL ;
}
F_12 ( V_14 , V_15 ) ;
return V_29 ;
}
static void F_11 ( void )
{
int V_34 ;
char * V_35 , * V_36 ;
unsigned long V_37 ;
V_37 = F_5 ( V_9 ) ;
V_34 = V_37 & 3 ;
if ( V_34 ) {
V_37 ^= V_34 ;
F_10 ( V_28 , L_10 ,
V_34 , V_37 ) ;
V_36 = F_14 ( V_37 ) ;
F_10 ( V_28 , L_11 , V_36 ) ;
for ( V_35 = ( char * ) & V_20 . V_38 ; V_34 != 0 ; -- V_34 )
* V_36 ++ = * V_35 ++ ;
}
}
static void F_15 ( void )
{
if ( F_16 () )
return;
if ( F_17 ( F_13 ) )
F_18 () ;
}
static int F_19 ( struct V_16 * V_17 )
{
if ( F_16 () )
return 1 ;
if ( F_17 ( F_13 ) &&
V_17 -> V_39 -> V_40 > 1 )
return 1 ;
if ( F_20 () )
return F_21 ( F_13 , V_17 ) ;
F_22 ( F_13 , V_17 ) ;
return 1 ;
}
static int T_2 F_23 ( char * V_41 )
{
int V_42 [ 8 ] ;
F_24 ( V_41 , F_25 ( V_42 ) , V_42 ) ;
if ( V_42 [ 0 ] < 1 ) {
F_9 ( L_12 ) ;
return 0 ;
}
if ( V_42 [ 0 ] >= 1 )
V_43 = V_42 [ 1 ] ;
if ( V_42 [ 0 ] >= 2 )
V_44 = V_42 [ 2 ] ;
if ( V_42 [ 0 ] >= 3 )
V_45 = V_42 [ 3 ] ;
if ( V_42 [ 0 ] >= 4 )
V_46 = V_42 [ 4 ] ;
if ( V_42 [ 0 ] >= 7 )
V_47 = V_42 [ 7 ] ;
return 1 ;
}
static unsigned long F_26 ( struct V_16 * V_17 ,
void * V_48 , unsigned long V_49 ,
int V_50 )
{
unsigned long V_8 = F_27 ( V_48 ) ;
F_10 ( V_28 , L_13
L_14 , V_17 -> V_51 , V_48 , V_8 , V_49 , V_50 ) ;
if ( ! F_16 () && ! F_28 ( V_8 ) ) {
if ( V_50 )
memcpy ( V_52 , V_48 , V_49 ) ;
else
V_33 = V_48 ;
V_8 = V_53 ;
}
V_27 = V_8 ;
F_29 ( V_8 , V_49 , V_50 ) ;
if ( F_16 () ) {
V_20 . V_21 = V_50 ;
F_30 ( V_9 , V_8 ) ;
F_30 ( V_54 , V_49 ) ;
V_20 . V_21 = V_50 | 2 ;
} else {
F_1 ( V_8 ) ;
V_50 <<= 8 ;
V_2 . V_30 = 0x90 | V_50 ;
V_2 . V_30 = 0x90 | ( V_50 ^ 0x100 ) ;
V_2 . V_30 = 0x90 | V_50 ;
F_31 ( 40 ) ;
V_2 . V_55 = ( V_49 + ( V_50 ? 511 : 0 ) ) >> 9 ;
F_31 ( 40 ) ;
V_2 . V_30 = 0x10 | V_50 ;
F_31 ( 40 ) ;
V_31 = 1 ;
}
return V_49 ;
}
static long F_32 ( struct V_16 * V_17 )
{
return V_25 ;
}
static int F_33 ( struct V_56 * V_57 )
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
static unsigned long F_34 ( unsigned long V_72 ,
struct V_56 * V_57 , int V_73 )
{
unsigned long V_74 , V_75 ;
if ( V_72 < V_76 )
return 0 ;
if ( F_16 () )
return V_72 ;
if ( V_73 ) {
V_74 = V_72 ;
} else {
if ( V_72 & 0x1ff )
V_74 = 0 ;
else {
switch ( F_33 ( V_57 ) ) {
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
V_75 = ( V_52 && ! F_28 ( F_27 ( V_57 -> V_77 . V_78 ) ) ) ?
V_79 : 255 * 512 ;
if ( V_74 > V_75 )
V_74 = V_75 ;
if ( V_74 != V_72 )
F_10 ( V_28 , L_15
L_16 , V_74 , V_72 ) ;
return V_74 ;
}
static unsigned char F_35 ( unsigned char V_80 )
{
return V_81 [ V_80 * 2 ] ;
}
static void F_36 ( unsigned char V_80 , unsigned char V_82 )
{
V_81 [ V_80 * 2 ] = V_82 ;
}
static unsigned char F_37 ( unsigned char V_80 )
{
V_83 . V_30 = ( V_84 ) ( 0x88 + V_80 ) ;
return ( V_85 ) V_83 . V_55 ;
}
static void F_38 ( unsigned char V_80 , unsigned char V_82 )
{
V_83 . V_30 = ( V_84 ) ( 0x88 + V_80 ) ;
V_83 . V_55 = ( V_84 ) V_82 ;
}
static int F_39 ( struct V_56 * V_57 )
{
int V_86 ;
unsigned long V_87 ;
F_40 ( V_87 ) ;
if ( F_16 () ) {
V_20 . V_21 = 0 ;
} else {
V_2 . V_30 = 0x90 ;
V_31 = 0 ;
V_33 = NULL ;
}
V_86 = F_41 ( V_57 ) ;
F_42 ( V_87 ) ;
return V_86 ;
}
static int T_2 F_43 ( struct V_88 * V_89 )
{
struct V_16 * V_17 ;
int error ;
struct V_90 * V_14 ;
int V_91 = 0 ;
V_14 = F_44 ( V_89 , V_92 , 0 ) ;
if ( ! V_14 )
return - V_93 ;
if ( F_45 ( V_94 ) ) {
V_95 = F_35 ;
V_96 = F_36 ;
} else {
V_95 = F_37 ;
V_96 = F_38 ;
}
if ( F_45 ( V_94 ) ) {
V_97 . V_40 = 16 ;
V_97 . V_98 = V_99 ;
} else {
V_97 . V_40 = 1 ;
V_97 . V_98 = V_100 ;
}
if ( V_43 > 0 )
V_97 . V_40 = V_43 ;
if ( V_44 > 0 )
V_97 . V_101 = V_44 ;
if ( F_45 ( V_94 ) && V_45 >= 0 )
V_97 . V_98 = V_45 ;
if ( V_46 >= 0 ) {
V_97 . V_102 = V_46 & 7 ;
} else {
if ( F_45 ( V_103 ) && F_46 () ) {
unsigned char V_104 = F_47 ( 16 ) ;
if ( V_104 & 0x80 )
V_97 . V_102 = V_104 & 7 ;
}
}
if ( F_45 ( V_105 ) && ! F_45 ( V_106 ) &&
V_11 > 1 ) {
V_52 = F_48 ( V_79 , L_17 ) ;
if ( ! V_52 ) {
F_49 ( V_107 L_18 ) ;
return - V_108 ;
}
V_53 = F_50 ( V_52 ) ;
V_33 = 0 ;
}
V_17 = F_51 ( & V_97 ,
sizeof( struct V_18 ) ) ;
if ( ! V_17 ) {
error = - V_108 ;
goto V_109;
}
V_17 -> V_14 = V_14 -> V_110 ;
V_91 |= F_16 () ? 0 : V_111 ;
V_91 |= V_47 > 0 ? V_112 : 0 ;
error = F_52 ( V_17 , V_91 ) ;
if ( error )
goto V_113;
if ( F_16 () ) {
error = F_53 ( V_17 -> V_14 , F_6 , 0 ,
L_19 , V_17 ) ;
if ( error ) {
F_49 ( V_107 L_20 ,
V_17 -> V_14 ) ;
goto V_114;
}
V_115 . V_116 |= 0x80 ;
V_20 . V_21 = 0 ;
V_25 = 0 ;
if ( V_117 ) {
struct V_18 * V_19 =
F_7 ( V_17 ) ;
V_19 -> V_118 = 4 ;
}
} else {
V_25 = 0 ;
V_31 = 0 ;
V_119 = ( F_45 ( V_106 ) ? 0x00000000
: 0xff000000 ) ;
}
F_54 ( V_17 ) ;
error = F_55 ( V_17 , NULL ) ;
if ( error )
goto V_120;
F_56 ( V_89 , V_17 ) ;
F_57 ( V_17 ) ;
return 0 ;
V_120:
if ( F_16 () )
F_58 ( V_17 -> V_14 , V_17 ) ;
V_114:
F_59 ( V_17 ) ;
V_113:
F_60 ( V_17 ) ;
V_109:
if ( V_52 )
F_61 ( V_52 ) ;
return error ;
}
static int T_3 F_62 ( struct V_88 * V_89 )
{
struct V_16 * V_17 = F_63 ( V_89 ) ;
F_64 ( V_17 ) ;
if ( F_16 () )
F_58 ( V_17 -> V_14 , V_17 ) ;
F_59 ( V_17 ) ;
F_60 ( V_17 ) ;
if ( V_52 )
F_61 ( V_52 ) ;
return 0 ;
}
