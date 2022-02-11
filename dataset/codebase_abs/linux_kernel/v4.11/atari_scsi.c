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
static unsigned long F_26 ( struct V_18 * V_19 ,
void * V_48 , unsigned long V_49 ,
int V_50 )
{
unsigned long V_8 = F_27 ( V_48 ) ;
F_10 ( V_28 , L_13 ,
V_19 -> V_51 -> V_52 , V_48 , V_8 , V_49 , V_50 ) ;
if ( ! F_16 () && ! F_28 ( V_8 ) ) {
if ( V_50 )
memcpy ( V_53 , V_48 , V_49 ) ;
else
V_33 = V_48 ;
V_8 = V_54 ;
}
V_27 = V_8 ;
F_29 ( V_8 , V_49 , V_50 ) ;
if ( F_16 () ) {
V_20 . V_21 = V_50 ;
F_30 ( V_9 , V_8 ) ;
F_30 ( V_55 , V_49 ) ;
V_20 . V_21 = V_50 | 2 ;
} else {
F_1 ( V_8 ) ;
V_50 <<= 8 ;
V_2 . V_30 = 0x90 | V_50 ;
V_2 . V_30 = 0x90 | ( V_50 ^ 0x100 ) ;
V_2 . V_30 = 0x90 | V_50 ;
F_31 ( 40 ) ;
V_2 . V_56 = ( V_49 + ( V_50 ? 511 : 0 ) ) >> 9 ;
F_31 ( 40 ) ;
V_2 . V_30 = 0x10 | V_50 ;
F_31 ( 40 ) ;
V_31 = 1 ;
}
return V_49 ;
}
static inline int F_32 ( struct V_18 * V_19 ,
unsigned char * V_48 , int V_49 )
{
return F_26 ( V_19 , V_48 , V_49 , 0 ) ;
}
static inline int F_33 ( struct V_18 * V_19 ,
unsigned char * V_48 , int V_49 )
{
return F_26 ( V_19 , V_48 , V_49 , 1 ) ;
}
static int F_34 ( struct V_18 * V_19 )
{
return V_25 ;
}
static int F_35 ( struct V_57 * V_58 )
{
unsigned char V_59 = V_58 -> V_60 [ 0 ] ;
if ( V_59 == V_61 || V_59 == V_62 ||
V_59 == V_63 )
return V_64 ;
else if ( V_59 == V_65 || V_59 == V_66 ||
V_59 == 0xa8 || V_59 == V_67 ||
V_59 == V_68 ) {
if ( V_58 -> V_69 -> type == V_70 && ! ( V_58 -> V_60 [ 1 ] & 1 ) )
return V_64 ;
else
return V_71 ;
} else
return V_72 ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_57 * V_58 )
{
int V_73 = V_58 -> V_74 . V_75 ;
int V_76 , V_77 ;
if ( V_73 < V_78 )
return 0 ;
if ( F_16 () )
return V_73 ;
if ( V_58 -> V_79 == V_80 ) {
V_76 = V_73 ;
} else {
if ( V_73 & 0x1ff )
V_76 = 0 ;
else {
switch ( F_35 ( V_58 ) ) {
case V_71 :
V_76 = V_73 ;
break;
case V_64 :
V_76 = 0 ;
break;
case V_72 :
default:
V_76 = ( V_73 < 1024 ) ? 0 : V_73 ;
break;
}
}
}
V_77 = ( V_53 && ! F_28 ( F_27 ( V_58 -> V_74 . V_81 ) ) ) ?
V_82 : 255 * 512 ;
if ( V_76 > V_77 )
V_76 = V_77 ;
if ( V_76 != V_73 )
F_10 ( V_28 , L_14 ,
V_76 , V_73 ) ;
return V_76 ;
}
static T_3 F_37 ( unsigned int V_83 )
{
return V_84 [ V_83 * 2 ] ;
}
static void F_38 ( unsigned int V_83 , T_3 V_85 )
{
V_84 [ V_83 * 2 ] = V_85 ;
}
static T_3 F_39 ( unsigned int V_83 )
{
unsigned long V_86 ;
T_3 V_87 ;
V_83 += 0x88 ;
F_40 ( V_86 ) ;
V_88 . V_30 = ( V_89 ) V_83 ;
V_87 = ( T_3 ) V_88 . V_56 ;
F_41 ( V_86 ) ;
return V_87 ;
}
static void F_42 ( unsigned int V_83 , T_3 V_85 )
{
unsigned long V_86 ;
V_83 += 0x88 ;
F_40 ( V_86 ) ;
V_88 . V_30 = ( V_89 ) V_83 ;
V_88 . V_56 = ( V_89 ) V_85 ;
F_41 ( V_86 ) ;
}
static int F_43 ( struct V_57 * V_58 )
{
int V_90 ;
unsigned long V_86 ;
F_40 ( V_86 ) ;
if ( F_16 () ) {
V_20 . V_21 = 0 ;
} else {
if ( F_17 ( F_13 ) )
V_2 . V_30 = 0x90 ;
V_31 = 0 ;
V_33 = NULL ;
}
V_90 = F_44 ( V_58 ) ;
F_41 ( V_86 ) ;
return V_90 ;
}
static int T_2 F_45 ( struct V_91 * V_92 )
{
struct V_16 * V_17 ;
int error ;
struct V_93 * V_14 ;
int V_94 = 0 ;
V_14 = F_46 ( V_92 , V_95 , 0 ) ;
if ( ! V_14 )
return - V_96 ;
if ( F_47 ( V_97 ) ) {
V_98 = F_37 ;
V_99 = F_38 ;
} else {
V_98 = F_39 ;
V_99 = F_42 ;
}
if ( F_47 ( V_97 ) ) {
V_100 . V_40 = 16 ;
V_100 . V_101 = V_102 ;
} else {
V_100 . V_40 = 1 ;
V_100 . V_101 = V_103 ;
}
if ( V_43 > 0 )
V_100 . V_40 = V_43 ;
if ( V_44 > 0 )
V_100 . V_104 = V_44 ;
if ( F_47 ( V_97 ) && V_45 >= 0 )
V_100 . V_101 = V_45 ;
if ( V_46 >= 0 ) {
V_100 . V_105 = V_46 & 7 ;
} else {
if ( F_47 ( V_106 ) && F_48 () ) {
unsigned char V_107 = F_49 ( 16 ) ;
if ( V_107 & 0x80 )
V_100 . V_105 = V_107 & 7 ;
}
}
if ( F_47 ( V_108 ) && ! F_47 ( V_109 ) &&
V_11 > 1 ) {
V_53 = F_50 ( V_82 , L_15 ) ;
if ( ! V_53 ) {
F_51 ( V_110 L_16 ) ;
return - V_111 ;
}
V_54 = F_52 ( V_53 ) ;
V_33 = NULL ;
}
V_17 = F_53 ( & V_100 ,
sizeof( struct V_18 ) ) ;
if ( ! V_17 ) {
error = - V_111 ;
goto V_112;
}
V_17 -> V_14 = V_14 -> V_113 ;
V_94 |= F_16 () ? 0 : V_114 ;
V_94 |= V_47 > 0 ? V_115 : 0 ;
error = F_54 ( V_17 , V_94 ) ;
if ( error )
goto V_116;
if ( F_16 () ) {
error = F_55 ( V_17 -> V_14 , F_6 , 0 ,
L_17 , V_17 ) ;
if ( error ) {
F_51 ( V_110 L_18 ,
V_17 -> V_14 ) ;
goto V_117;
}
V_118 . V_119 |= 0x80 ;
V_20 . V_21 = 0 ;
V_25 = 0 ;
if ( V_120 ) {
struct V_18 * V_19 =
F_7 ( V_17 ) ;
V_19 -> V_121 = 4 ;
}
} else {
V_25 = 0 ;
V_31 = 0 ;
V_122 = ( F_47 ( V_109 ) ? 0x00000000
: 0xff000000 ) ;
}
F_56 ( V_17 ) ;
error = F_57 ( V_17 , NULL ) ;
if ( error )
goto V_123;
F_58 ( V_92 , V_17 ) ;
F_59 ( V_17 ) ;
return 0 ;
V_123:
if ( F_16 () )
F_60 ( V_17 -> V_14 , V_17 ) ;
V_117:
F_61 ( V_17 ) ;
V_116:
F_62 ( V_17 ) ;
V_112:
if ( V_53 )
F_63 ( V_53 ) ;
return error ;
}
static int T_4 F_64 ( struct V_91 * V_92 )
{
struct V_16 * V_17 = F_65 ( V_92 ) ;
F_66 ( V_17 ) ;
if ( F_16 () )
F_60 ( V_17 -> V_14 , V_17 ) ;
F_61 ( V_17 ) ;
F_62 ( V_17 ) ;
if ( V_53 )
F_63 ( V_53 ) ;
return 0 ;
}
