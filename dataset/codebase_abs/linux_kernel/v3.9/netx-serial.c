static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ~ V_6 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ~ V_7 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_8 , V_2 -> V_4 + V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 -> V_10 ;
if ( V_2 -> V_12 ) {
F_3 ( V_2 -> V_12 , V_2 -> V_4 + V_13 ) ;
V_2 -> V_14 . V_15 ++ ;
V_2 -> V_12 = 0 ;
return;
}
if ( F_7 ( V_2 ) || F_8 ( V_10 ) ) {
F_1 ( V_2 ) ;
return;
}
do {
F_3 ( V_10 -> V_16 [ V_10 -> V_17 ] , V_2 -> V_4 + V_13 ) ;
V_10 -> V_17 = ( V_10 -> V_17 + 1 ) &
( V_18 - 1 ) ;
V_2 -> V_14 . V_15 ++ ;
if ( F_8 ( V_10 ) )
break;
} while ( ! ( F_2 ( V_2 -> V_4 + V_19 ) & V_20 ) );
if ( F_8 ( V_10 ) )
F_1 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_3 (
F_2 ( V_2 -> V_4 + V_5 ) | V_6 , V_2 -> V_4 + V_5 ) ;
if ( ! ( F_2 ( V_2 -> V_4 + V_19 ) & V_20 ) )
F_6 ( V_2 ) ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_4 + V_19 ) & V_21 ? 0 : V_22 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 -> V_10 ;
if ( F_8 ( V_10 ) || F_7 ( V_2 ) ) {
F_1 ( V_2 ) ;
return;
}
F_6 ( V_2 ) ;
if ( F_12 ( V_10 ) < V_23 )
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned char V_24 , V_25 , V_26 ;
while ( ! ( F_2 ( V_2 -> V_4 + V_19 ) & V_27 ) ) {
V_24 = F_2 ( V_2 -> V_4 + V_13 ) ;
V_25 = V_28 ;
V_2 -> V_14 . V_24 ++ ;
V_26 = F_2 ( V_2 -> V_4 + V_29 ) ;
if ( V_26 & V_30 ) {
F_3 ( 0 , V_2 -> V_4 + V_29 ) ;
if ( F_15 ( V_2 ) )
continue;
}
if ( F_16 ( V_26 & ( V_31 | V_32 | V_33 ) ) ) {
if ( V_26 & V_32 )
V_2 -> V_14 . V_34 ++ ;
else if ( V_26 & V_31 )
V_2 -> V_14 . V_35 ++ ;
if ( V_26 & V_33 )
V_2 -> V_14 . V_36 ++ ;
V_26 &= V_2 -> V_37 ;
if ( V_26 & V_30 )
V_25 = V_38 ;
else if ( V_26 & V_32 )
V_25 = V_39 ;
else if ( V_26 & V_31 )
V_25 = V_40 ;
}
if ( F_17 ( V_2 , V_24 ) )
continue;
F_18 ( V_2 , V_26 , V_33 , V_24 , V_25 ) ;
}
F_19 ( & V_2 -> V_11 -> V_2 ) ;
}
static T_1 F_20 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned long V_43 ;
unsigned char V_26 ;
F_21 ( & V_2 -> V_44 , V_43 ) ;
V_26 = F_2 ( V_2 -> V_4 + V_45 ) & V_46 ;
while ( V_26 ) {
if ( V_26 & V_47 )
F_14 ( V_2 ) ;
if ( V_26 & V_48 )
F_11 ( V_2 ) ;
if ( V_26 & V_49 ) {
if ( F_2 ( V_2 -> V_4 + V_19 ) & V_50 )
F_22 ( V_2 , 1 ) ;
else
F_22 ( V_2 , 0 ) ;
}
F_3 ( 0 , V_2 -> V_4 + V_45 ) ;
V_26 = F_2 ( V_2 -> V_4 + V_45 ) & V_46 ;
}
F_23 ( & V_2 -> V_44 , V_43 ) ;
return V_51 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_52 = V_53 | V_54 ;
if ( F_2 ( V_2 -> V_4 + V_19 ) & V_50 )
V_52 |= V_55 ;
return V_52 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_56 )
{
unsigned int V_3 ;
if ( V_56 & V_57 ) {
V_3 = F_2 ( V_2 -> V_4 + V_58 ) ;
F_3 ( V_3 | V_59 , V_2 -> V_4 + V_58 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_60 )
{
unsigned int V_61 ;
F_27 ( & V_2 -> V_44 ) ;
V_61 = F_2 ( V_2 -> V_4 + V_62 ) ;
if ( V_60 != 0 )
V_61 |= V_63 ;
else
V_61 &= ~ V_63 ;
F_3 ( V_61 , V_2 -> V_4 + V_62 ) ;
F_28 ( & V_2 -> V_44 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_30 ( V_2 -> V_41 , F_20 , 0 ,
V_64 , V_2 ) ;
if ( V_52 ) {
F_31 ( V_2 -> V_65 , L_1 , V_2 -> V_41 ) ;
goto exit;
}
F_3 ( F_2 ( V_2 -> V_4 + V_62 ) | V_66 ,
V_2 -> V_4 + V_62 ) ;
F_3 ( V_8 | V_7 | V_6 | V_67 | V_68 ,
V_2 -> V_4 + V_5 ) ;
exit:
return V_52 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_4 + V_5 ) ;
F_33 ( V_2 -> V_41 , V_2 ) ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_69 * V_70 ,
struct V_69 * V_71 )
{
unsigned int V_72 , V_73 ;
unsigned char V_74 ;
unsigned char V_61 = V_66 ;
unsigned char V_75 = 0 ;
switch ( V_70 -> V_76 & V_77 ) {
case V_78 :
V_61 |= V_79 ;
break;
case V_80 :
V_61 |= V_81 ;
break;
case V_82 :
V_61 |= V_83 ;
break;
case V_84 :
V_61 |= V_85 ;
break;
}
if ( V_70 -> V_76 & V_86 )
V_61 |= V_87 ;
if ( V_70 -> V_76 & V_88 ) {
V_61 |= V_89 ;
if ( ! ( V_70 -> V_76 & V_90 ) )
V_61 |= V_91 ;
}
if ( V_70 -> V_76 & V_92 )
V_75 = V_93 | V_94 | V_95 ;
V_72 = F_35 ( V_2 , V_70 , V_71 , 0 , V_2 -> V_96 / 16 ) ;
V_73 = V_72 * 4096 ;
V_73 /= 1000 ;
V_73 *= 256 ;
V_73 /= 100000 ;
F_27 ( & V_2 -> V_44 ) ;
F_36 ( V_2 , V_70 -> V_76 , V_72 ) ;
V_74 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_74 & ~ ( V_8 | V_7 | V_6 | V_67 ) ,
V_2 -> V_4 + V_5 ) ;
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_74 & ~ V_68 , V_2 -> V_4 + V_5 ) ;
V_74 &= ~ V_8 ;
if ( F_37 ( V_2 , V_70 -> V_76 ) )
V_74 |= V_8 ;
F_3 ( ( V_73 >> 8 ) & 0xff , V_2 -> V_4 + V_97 ) ;
F_3 ( V_73 & 0xff , V_2 -> V_4 + V_98 ) ;
F_3 ( V_61 , V_2 -> V_4 + V_62 ) ;
F_3 ( V_75 , V_2 -> V_4 + V_58 ) ;
V_2 -> V_99 = 0 ;
if ( V_70 -> V_100 & V_101 )
V_2 -> V_99 |= V_32 ;
if ( V_70 -> V_100 & V_102 ) {
V_2 -> V_99 |= V_30 ;
if ( V_70 -> V_100 & V_101 )
V_2 -> V_99 |= V_32 ;
}
V_2 -> V_37 = 0 ;
if ( V_70 -> V_100 & ( V_103 | V_104 ) )
V_2 -> V_37 |= V_30 ;
if ( V_70 -> V_100 & V_105 )
V_2 -> V_37 |= V_32 | V_31 ;
F_3 ( V_74 , V_2 -> V_4 + V_5 ) ;
F_28 ( & V_2 -> V_44 ) ;
}
static const char * F_38 ( struct V_1 * V_2 )
{
return V_2 -> type == V_106 ? L_2 : NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_107 , V_108 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_42 ( V_2 -> V_107 , V_108 ,
V_64 ) != NULL ? 0 : - V_109 ;
}
static void F_43 ( struct V_1 * V_2 , int V_43 )
{
if ( V_43 & V_110 && F_41 ( V_2 ) == 0 )
V_2 -> type = V_106 ;
}
static int
F_44 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
int V_52 = 0 ;
if ( V_112 -> type != V_113 && V_112 -> type != V_106 )
V_52 = - V_114 ;
return V_52 ;
}
static void F_45 ( struct V_1 * V_2 , int V_115 )
{
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_115 , V_2 -> V_4 + V_13 ) ;
}
static void
F_46 ( struct V_116 * V_117 , const char * V_118 , unsigned int V_119 )
{
struct V_1 * V_2 = & V_120 [ V_117 -> V_121 ] . V_2 ;
unsigned char V_122 ;
V_122 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_122 | V_68 , V_2 -> V_4 + V_5 ) ;
F_47 ( V_2 , V_118 , V_119 , F_45 ) ;
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_122 , V_2 -> V_4 + V_5 ) ;
}
static void T_2
F_48 ( struct V_1 * V_2 , int * V_72 ,
int * V_34 , int * V_123 , int * V_124 )
{
unsigned char V_61 ;
* V_72 = ( F_2 ( V_2 -> V_4 + V_97 ) << 8 ) |
F_2 ( V_2 -> V_4 + V_98 ) ;
* V_72 *= 1000 ;
* V_72 /= 4096 ;
* V_72 *= 1000 ;
* V_72 /= 256 ;
* V_72 *= 100 ;
V_61 = F_2 ( V_2 -> V_4 + V_62 ) ;
* V_34 = 'n' ;
if ( V_61 & V_89 ) {
if ( V_61 & V_91 )
* V_34 = 'e' ;
else
* V_34 = 'o' ;
}
switch ( V_61 & V_125 ) {
case V_85 :
* V_123 = 8 ;
break;
case V_83 :
* V_123 = 7 ;
break;
case V_81 :
* V_123 = 6 ;
break;
case V_79 :
* V_123 = 5 ;
break;
}
if ( F_2 ( V_2 -> V_4 + V_58 ) & V_93 )
* V_124 = 'r' ;
}
static int T_2
F_49 ( struct V_116 * V_117 , char * V_126 )
{
struct V_127 * V_128 ;
int V_72 = 9600 ;
int V_123 = 8 ;
int V_34 = 'n' ;
int V_124 = 'n' ;
if ( V_117 -> V_121 == - 1 || V_117 -> V_121 >= F_50 ( V_120 ) )
V_117 -> V_121 = 0 ;
V_128 = & V_120 [ V_117 -> V_121 ] ;
if ( V_126 ) {
F_51 ( V_126 , & V_72 , & V_34 , & V_123 , & V_124 ) ;
} else {
if ( F_2 ( V_128 -> V_2 . V_4 + V_5 ) & V_68 ) {
F_48 ( & V_128 -> V_2 , & V_72 ,
& V_34 , & V_123 , & V_124 ) ;
}
}
return F_52 ( & V_128 -> V_2 , V_117 , V_72 , V_34 , V_123 , V_124 ) ;
}
static int T_2 F_53 ( void )
{
F_54 ( & V_129 ) ;
return 0 ;
}
static int F_55 ( struct V_130 * V_131 , T_3 V_11 )
{
struct V_127 * V_128 = F_56 ( V_131 ) ;
if ( V_128 )
F_57 ( & V_132 , & V_128 -> V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_130 * V_131 )
{
struct V_127 * V_128 = F_56 ( V_131 ) ;
if ( V_128 )
F_59 ( & V_132 , & V_128 -> V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = & V_120 [ V_131 -> V_133 ] . V_2 ;
F_61 ( & V_131 -> V_65 , L_3 ) ;
V_2 -> V_65 = & V_131 -> V_65 ;
F_3 ( 1 , V_2 -> V_4 + V_134 ) ;
F_62 ( & V_132 , & V_120 [ V_131 -> V_133 ] . V_2 ) ;
F_63 ( V_131 , & V_120 [ V_131 -> V_133 ] ) ;
return 0 ;
}
static int F_64 ( struct V_130 * V_131 )
{
struct V_127 * V_128 = F_56 ( V_131 ) ;
F_63 ( V_131 , NULL ) ;
if ( V_128 )
F_65 ( & V_132 , & V_128 -> V_2 ) ;
return 0 ;
}
static int T_2 F_66 ( void )
{
int V_52 ;
F_67 ( V_135 L_4 ) ;
V_52 = F_68 ( & V_132 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_69 ( & V_136 ) ;
if ( V_52 != 0 )
F_70 ( & V_132 ) ;
return 0 ;
}
static void T_4 F_71 ( void )
{
F_72 ( & V_136 ) ;
F_70 ( & V_132 ) ;
}
