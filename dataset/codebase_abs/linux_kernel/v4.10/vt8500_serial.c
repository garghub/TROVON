static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_11 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 |= V_12 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_2 ;
if ( ( F_3 ( V_2 , V_16 ) & V_17 ) ) {
V_2 -> V_18 . V_19 ++ ;
F_10 ( V_14 , 0 , V_20 ) ;
}
while ( F_3 ( V_2 , V_21 ) & 0x1f00 ) {
unsigned int V_22 ;
char V_23 = V_24 ;
V_22 = F_11 ( V_2 -> V_5 + V_25 ) & 0x3ff ;
V_22 &= ~ V_2 -> V_26 ;
if ( V_22 & V_27 ) {
V_2 -> V_18 . V_28 ++ ;
V_23 = V_29 ;
} else if ( V_22 & V_30 ) {
V_2 -> V_18 . V_31 ++ ;
V_23 = V_32 ;
}
V_2 -> V_18 . V_33 ++ ;
if ( ! F_12 ( V_2 , V_22 ) )
F_10 ( V_14 , V_22 , V_23 ) ;
}
F_13 ( & V_2 -> V_34 ) ;
F_14 ( V_14 ) ;
F_15 ( & V_2 -> V_34 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = & V_2 -> V_15 -> V_36 ;
if ( V_2 -> V_37 ) {
F_17 ( V_2 -> V_37 , V_2 -> V_5 + V_38 ) ;
V_2 -> V_18 . V_39 ++ ;
V_2 -> V_37 = 0 ;
}
if ( F_18 ( V_36 ) || F_19 ( V_2 ) ) {
F_5 ( V_2 ) ;
return;
}
while ( ( F_3 ( V_2 , V_21 ) & 0x1f ) < 16 ) {
if ( F_18 ( V_36 ) )
break;
F_17 ( V_36 -> V_40 [ V_36 -> V_41 ] , V_2 -> V_5 + V_38 ) ;
V_36 -> V_41 = ( V_36 -> V_41 + 1 ) & ( V_42 - 1 ) ;
V_2 -> V_18 . V_39 ++ ;
}
if ( F_20 ( V_36 ) < V_43 )
F_21 ( V_2 ) ;
if ( F_18 ( V_36 ) )
F_5 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
F_16 ( V_2 ) ;
V_6 -> V_8 |= V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_18 . V_44 ++ ;
F_24 ( & V_2 -> V_15 -> V_2 . V_45 ) ;
}
static T_1 F_25 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
unsigned long V_48 ;
F_15 ( & V_2 -> V_34 ) ;
V_48 = F_3 ( V_2 , V_16 ) ;
F_1 ( V_2 , V_48 , V_16 ) ;
if ( V_48 & V_11 )
F_9 ( V_2 ) ;
if ( V_48 & V_9 )
F_16 ( V_2 ) ;
if ( V_48 & V_12 )
F_23 ( V_2 ) ;
F_13 ( & V_2 -> V_34 ) ;
return V_49 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_21 ) & 0x1f ) < 16 ?
V_50 : 0 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
V_51 = F_3 ( V_2 , V_52 ) ;
if ( V_51 & ( 1 << 4 ) )
return V_53 ;
else
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_54 )
{
unsigned int V_55 = F_3 ( V_2 , V_56 ) ;
if ( V_54 & V_57 )
V_55 |= V_58 ;
else
V_55 &= ~ V_58 ;
F_1 ( V_2 , V_55 , V_56 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_59 )
{
if ( V_59 )
F_1 ( V_2 ,
F_3 ( V_2 , V_56 ) | V_60 ,
V_56 ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
unsigned long div ;
unsigned int V_62 = 1000 ;
div = ( ( V_6 -> V_63 - 1 ) & 0xf ) << 16 ;
div |= ( F_31 ( V_2 , V_61 ) - 1 ) & 0x3ff ;
V_61 = V_2 -> V_64 / 16 / ( ( div & 0x3ff ) + 1 ) ;
while ( ( F_3 ( V_2 , V_52 ) & ( 1 << 5 ) ) && -- V_62 )
F_32 () ;
F_1 ( V_2 , div , V_65 ) ;
F_1 ( V_2 , F_33 ( V_61 , 4096 , 1000000 ) , V_66 ) ;
return V_61 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
int V_67 ;
snprintf ( V_6 -> V_68 , sizeof( V_6 -> V_68 ) ,
L_1 , V_2 -> line ) ;
V_67 = F_35 ( V_2 -> V_46 , F_25 , V_69 ,
V_6 -> V_68 , V_2 ) ;
if ( F_36 ( V_67 ) )
return V_67 ;
F_1 ( V_2 , 0x03 , V_56 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
V_6 -> V_8 = 0 ;
F_1 ( & V_6 -> V_7 , 0 , V_10 ) ;
F_1 ( & V_6 -> V_7 , 0x880 , V_70 ) ;
F_38 ( V_2 -> V_46 , V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_71 * V_73 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
unsigned long V_74 ;
unsigned int V_61 , V_55 ;
unsigned int V_62 = 1000 ;
F_40 ( & V_2 -> V_34 , V_74 ) ;
V_61 = F_41 ( V_2 , V_72 , V_73 , 900 , 921600 ) ;
V_61 = F_30 ( V_2 , V_61 ) ;
if ( F_42 ( V_72 ) )
F_43 ( V_72 , V_61 , V_61 ) ;
V_55 = F_3 ( & V_6 -> V_7 , V_56 ) ;
V_55 &= ~ ( V_75 | V_76 ) ;
if ( V_72 -> V_77 & V_78 ) {
V_55 |= V_75 ;
V_72 -> V_77 &= ~ V_79 ;
if ( V_72 -> V_77 & V_80 )
V_55 |= V_76 ;
}
V_55 &= ~ V_81 ;
switch ( V_72 -> V_77 & V_82 ) {
case V_83 :
break;
case V_84 :
default:
V_55 |= V_81 ;
V_72 -> V_77 &= ~ V_82 ;
V_72 -> V_77 |= V_84 ;
break;
}
V_55 &= ~ V_85 ;
if ( V_72 -> V_77 & V_86 )
V_55 |= V_85 ;
V_55 &= ~ V_87 ;
if ( V_6 -> V_88 & V_89 )
V_55 |= V_87 ;
F_1 ( & V_6 -> V_7 , V_55 , V_56 ) ;
V_2 -> V_26 = 0 ;
if ( V_72 -> V_90 & V_91 )
V_2 -> V_26 = V_27 | V_30 ;
F_44 ( V_2 , V_72 -> V_77 , V_61 ) ;
F_1 ( & V_6 -> V_7 , 0x88c , V_70 ) ;
while ( ( F_3 ( & V_6 -> V_7 , V_70 ) & 0xc )
&& -- V_62 )
F_32 () ;
V_6 -> V_8 = V_11 | V_9 ;
if ( F_45 ( & V_6 -> V_7 , V_72 -> V_77 ) )
V_6 -> V_8 |= V_12 ;
F_1 ( & V_6 -> V_7 , 0x881 , V_70 ) ;
F_1 ( & V_6 -> V_7 , V_6 -> V_8 , V_10 ) ;
F_46 ( & V_2 -> V_34 , V_74 ) ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
return V_6 -> V_68 ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , int V_74 )
{
V_2 -> type = V_92 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
if ( F_36 ( V_94 -> type != V_95 && V_94 -> type != V_92 ) )
return - V_96 ;
if ( F_36 ( V_2 -> V_46 != V_94 -> V_46 ) )
return - V_96 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned int V_97 , V_98 = 10000 ;
do {
V_97 = F_3 ( V_2 , V_21 ) ;
if ( -- V_98 == 0 )
break;
F_53 ( 1 ) ;
} while ( V_97 & 0x10 );
}
static void F_54 ( struct V_1 * V_2 , int V_22 )
{
F_52 ( V_2 ) ;
F_17 ( V_22 , V_2 -> V_5 + V_38 ) ;
}
static void F_55 ( struct V_99 * V_100 , const char * V_101 ,
unsigned int V_102 )
{
struct V_6 * V_6 = V_103 [ V_100 -> V_104 ] ;
unsigned long V_8 ;
F_56 ( V_100 -> V_104 < 0 || V_100 -> V_104 >= V_105 . V_106 ) ;
V_8 = F_3 ( & V_6 -> V_7 , V_10 ) ;
F_1 ( & V_6 -> V_7 , V_10 , 0 ) ;
F_57 ( & V_6 -> V_7 , V_101 , V_102 ,
F_54 ) ;
F_52 ( & V_6 -> V_7 ) ;
F_1 ( & V_6 -> V_7 , V_10 , V_8 ) ;
}
static int T_2 F_58 ( struct V_99 * V_100 , char * V_107 )
{
struct V_6 * V_6 ;
int V_61 = 9600 ;
int V_108 = 8 ;
int V_31 = 'n' ;
int V_109 = 'n' ;
if ( F_36 ( V_100 -> V_104 >= V_105 . V_106 || V_100 -> V_104 < 0 ) )
return - V_110 ;
V_6 = V_103 [ V_100 -> V_104 ] ;
if ( ! V_6 )
return - V_111 ;
if ( V_107 )
F_59 ( V_107 , & V_61 , & V_31 , & V_108 , & V_109 ) ;
return F_60 ( & V_6 -> V_7 ,
V_100 , V_61 , V_31 , V_108 , V_109 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
unsigned int V_97 = F_3 ( V_2 , V_21 ) ;
if ( ! ( V_97 & 0x1f00 ) )
return V_112 ;
return F_3 ( V_2 , V_25 ) & 0xff ;
}
static void F_62 ( struct V_1 * V_2 , unsigned char V_22 )
{
unsigned int V_97 , V_98 = 10000 ;
do {
V_97 = F_3 ( V_2 , V_21 ) ;
if ( -- V_98 == 0 )
break;
F_53 ( 1 ) ;
} while ( V_97 & 0x10 );
F_1 ( V_2 , V_22 , V_38 ) ;
}
static int F_63 ( struct V_113 * V_114 )
{
struct V_6 * V_6 ;
struct V_115 * V_116 , * V_117 ;
struct V_118 * V_119 = V_114 -> V_120 . V_121 ;
const struct V_122 * V_123 ;
const unsigned int * V_74 ;
int V_67 ;
int V_2 ;
V_123 = F_64 ( V_124 , & V_114 -> V_120 ) ;
if ( ! V_123 )
return - V_96 ;
V_74 = V_123 -> V_125 ;
V_116 = F_65 ( V_114 , V_126 , 0 ) ;
V_117 = F_65 ( V_114 , V_127 , 0 ) ;
if ( ! V_116 || ! V_117 )
return - V_111 ;
if ( V_119 ) {
V_2 = F_66 ( V_119 , L_2 ) ;
if ( V_2 >= V_128 )
V_2 = - 1 ;
} else {
V_2 = - 1 ;
}
if ( V_2 < 0 ) {
V_2 = F_67 ( V_129 ,
V_128 ) ;
}
if ( V_2 >= V_128 )
return - V_111 ;
if ( F_68 ( V_2 , V_129 ) ) {
return - V_130 ;
}
V_6 = F_69 ( & V_114 -> V_120 , sizeof( struct V_6 ) ,
V_131 ) ;
if ( ! V_6 )
return - V_132 ;
V_6 -> V_7 . V_5 = F_70 ( & V_114 -> V_120 , V_116 ) ;
if ( F_71 ( V_6 -> V_7 . V_5 ) )
return F_72 ( V_6 -> V_7 . V_5 ) ;
V_6 -> V_133 = F_73 ( V_114 -> V_120 . V_121 , 0 ) ;
if ( F_71 ( V_6 -> V_133 ) ) {
F_74 ( & V_114 -> V_120 , L_3 ) ;
return - V_96 ;
}
V_67 = F_75 ( V_6 -> V_133 ) ;
if ( V_67 ) {
F_74 ( & V_114 -> V_120 , L_4 ) ;
return V_67 ;
}
V_6 -> V_88 = * V_74 ;
V_6 -> V_63 = F_76 (
F_77 ( V_6 -> V_133 ) ,
V_134
) ;
V_6 -> V_7 . type = V_92 ;
V_6 -> V_7 . V_135 = V_136 ;
V_6 -> V_7 . V_137 = V_116 -> V_138 ;
V_6 -> V_7 . V_46 = V_117 -> V_138 ;
V_6 -> V_7 . V_139 = 16 ;
V_6 -> V_7 . V_140 = & V_141 ;
V_6 -> V_7 . line = V_2 ;
V_6 -> V_7 . V_120 = & V_114 -> V_120 ;
V_6 -> V_7 . V_74 = V_142 | V_143 ;
V_6 -> V_7 . V_64 = 16 * F_77 ( V_6 -> V_133 ) /
V_6 -> V_63 /
V_144 ;
snprintf ( V_6 -> V_68 , sizeof( V_6 -> V_68 ) ,
L_5 , V_114 -> V_145 ) ;
V_103 [ V_2 ] = V_6 ;
F_78 ( & V_105 , & V_6 -> V_7 ) ;
F_79 ( V_114 , V_6 ) ;
return 0 ;
}
static int T_2 F_80 ( void )
{
int V_67 ;
V_67 = F_81 ( & V_105 ) ;
if ( F_36 ( V_67 ) )
return V_67 ;
V_67 = F_82 ( & V_146 ) ;
if ( F_36 ( V_67 ) )
F_83 ( & V_105 ) ;
return V_67 ;
}
