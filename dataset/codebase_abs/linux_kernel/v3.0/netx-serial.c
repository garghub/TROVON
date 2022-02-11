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
struct V_27 * V_28 = V_2 -> V_11 -> V_2 . V_28 ;
while ( ! ( F_2 ( V_2 -> V_4 + V_19 ) & V_29 ) ) {
V_24 = F_2 ( V_2 -> V_4 + V_13 ) ;
V_25 = V_30 ;
V_2 -> V_14 . V_24 ++ ;
V_26 = F_2 ( V_2 -> V_4 + V_31 ) ;
if ( V_26 & V_32 ) {
F_3 ( 0 , V_2 -> V_4 + V_31 ) ;
if ( F_15 ( V_2 ) )
continue;
}
if ( F_16 ( V_26 & ( V_33 | V_34 | V_35 ) ) ) {
if ( V_26 & V_34 )
V_2 -> V_14 . V_36 ++ ;
else if ( V_26 & V_33 )
V_2 -> V_14 . V_37 ++ ;
if ( V_26 & V_35 )
V_2 -> V_14 . V_38 ++ ;
V_26 &= V_2 -> V_39 ;
if ( V_26 & V_32 )
V_25 = V_40 ;
else if ( V_26 & V_34 )
V_25 = V_41 ;
else if ( V_26 & V_33 )
V_25 = V_42 ;
}
if ( F_17 ( V_2 , V_24 ) )
continue;
F_18 ( V_2 , V_26 , V_35 , V_24 , V_25 ) ;
}
F_19 ( V_28 ) ;
return;
}
static T_1 F_20 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
unsigned long V_45 ;
unsigned char V_26 ;
F_21 ( & V_2 -> V_46 , V_45 ) ;
V_26 = F_2 ( V_2 -> V_4 + V_47 ) & V_48 ;
while ( V_26 ) {
if ( V_26 & V_49 )
F_14 ( V_2 ) ;
if ( V_26 & V_50 )
F_11 ( V_2 ) ;
if ( V_26 & V_51 ) {
if ( F_2 ( V_2 -> V_4 + V_19 ) & V_52 )
F_22 ( V_2 , 1 ) ;
else
F_22 ( V_2 , 0 ) ;
}
F_3 ( 0 , V_2 -> V_4 + V_47 ) ;
V_26 = F_2 ( V_2 -> V_4 + V_47 ) & V_48 ;
}
F_23 ( & V_2 -> V_46 , V_45 ) ;
return V_53 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_54 = V_55 | V_56 ;
if ( F_2 ( V_2 -> V_4 + V_19 ) & V_52 )
V_54 |= V_57 ;
return V_54 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_58 )
{
unsigned int V_3 ;
if ( V_58 & V_59 ) {
V_3 = F_2 ( V_2 -> V_4 + V_60 ) ;
F_3 ( V_3 | V_61 , V_2 -> V_4 + V_60 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_62 )
{
unsigned int V_63 ;
F_27 ( & V_2 -> V_46 ) ;
V_63 = F_2 ( V_2 -> V_4 + V_64 ) ;
if ( V_62 != 0 )
V_63 |= V_65 ;
else
V_63 &= ~ V_65 ;
F_3 ( V_63 , V_2 -> V_4 + V_64 ) ;
F_28 ( & V_2 -> V_46 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_30 ( V_2 -> V_43 , F_20 , 0 ,
V_66 , V_2 ) ;
if ( V_54 ) {
F_31 ( V_2 -> V_67 , L_1 , V_2 -> V_43 ) ;
goto exit;
}
F_3 ( F_2 ( V_2 -> V_4 + V_64 ) | V_68 ,
V_2 -> V_4 + V_64 ) ;
F_3 ( V_8 | V_7 | V_6 | V_69 | V_70 ,
V_2 -> V_4 + V_5 ) ;
exit:
return V_54 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_4 + V_5 ) ;
F_33 ( V_2 -> V_43 , V_2 ) ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_71 * V_72 ,
struct V_71 * V_73 )
{
unsigned int V_74 , V_75 ;
unsigned char V_76 ;
unsigned char V_63 = V_68 ;
unsigned char V_77 = 0 ;
switch ( V_72 -> V_78 & V_79 ) {
case V_80 :
V_63 |= V_81 ;
break;
case V_82 :
V_63 |= V_83 ;
break;
case V_84 :
V_63 |= V_85 ;
break;
case V_86 :
V_63 |= V_87 ;
break;
}
if ( V_72 -> V_78 & V_88 )
V_63 |= V_89 ;
if ( V_72 -> V_78 & V_90 ) {
V_63 |= V_91 ;
if ( ! ( V_72 -> V_78 & V_92 ) )
V_63 |= V_93 ;
}
if ( V_72 -> V_78 & V_94 )
V_77 = V_95 | V_96 | V_97 ;
V_74 = F_35 ( V_2 , V_72 , V_73 , 0 , V_2 -> V_98 / 16 ) ;
V_75 = V_74 * 4096 ;
V_75 /= 1000 ;
V_75 *= 256 ;
V_75 /= 100000 ;
F_27 ( & V_2 -> V_46 ) ;
F_36 ( V_2 , V_72 -> V_78 , V_74 ) ;
V_76 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_76 & ~ ( V_8 | V_7 | V_6 | V_69 ) ,
V_2 -> V_4 + V_5 ) ;
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_76 & ~ V_70 , V_2 -> V_4 + V_5 ) ;
V_76 &= ~ V_8 ;
if ( F_37 ( V_2 , V_72 -> V_78 ) )
V_76 |= V_8 ;
F_3 ( ( V_75 >> 8 ) & 0xff , V_2 -> V_4 + V_99 ) ;
F_3 ( V_75 & 0xff , V_2 -> V_4 + V_100 ) ;
F_3 ( V_63 , V_2 -> V_4 + V_64 ) ;
F_3 ( V_77 , V_2 -> V_4 + V_60 ) ;
V_2 -> V_101 = 0 ;
if ( V_72 -> V_102 & V_103 )
V_2 -> V_101 |= V_34 ;
if ( V_72 -> V_102 & V_104 ) {
V_2 -> V_101 |= V_32 ;
if ( V_72 -> V_102 & V_103 )
V_2 -> V_101 |= V_34 ;
}
V_2 -> V_39 = 0 ;
if ( V_72 -> V_102 & ( V_105 | V_106 ) )
V_2 -> V_39 |= V_32 ;
if ( V_72 -> V_102 & V_107 )
V_2 -> V_39 |= V_34 | V_33 ;
F_3 ( V_76 , V_2 -> V_4 + V_5 ) ;
F_28 ( & V_2 -> V_46 ) ;
}
static const char * F_38 ( struct V_1 * V_2 )
{
return V_2 -> type == V_108 ? L_2 : NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_109 , V_110 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_42 ( V_2 -> V_109 , V_110 ,
V_66 ) != NULL ? 0 : - V_111 ;
}
static void F_43 ( struct V_1 * V_2 , int V_45 )
{
if ( V_45 & V_112 && F_41 ( V_2 ) == 0 )
V_2 -> type = V_108 ;
}
static int
F_44 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
int V_54 = 0 ;
if ( V_114 -> type != V_115 && V_114 -> type != V_108 )
V_54 = - V_116 ;
return V_54 ;
}
static void F_45 ( struct V_1 * V_2 , int V_117 )
{
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_117 , V_2 -> V_4 + V_13 ) ;
}
static void
F_46 ( struct V_118 * V_119 , const char * V_120 , unsigned int V_121 )
{
struct V_1 * V_2 = & V_122 [ V_119 -> V_123 ] . V_2 ;
unsigned char V_124 ;
V_124 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_124 | V_70 , V_2 -> V_4 + V_5 ) ;
F_47 ( V_2 , V_120 , V_121 , F_45 ) ;
while ( F_2 ( V_2 -> V_4 + V_19 ) & V_21 ) ;
F_3 ( V_124 , V_2 -> V_4 + V_5 ) ;
}
static void T_2
F_48 ( struct V_1 * V_2 , int * V_74 ,
int * V_36 , int * V_125 , int * V_126 )
{
unsigned char V_63 ;
* V_74 = ( F_2 ( V_2 -> V_4 + V_99 ) << 8 ) |
F_2 ( V_2 -> V_4 + V_100 ) ;
* V_74 *= 1000 ;
* V_74 /= 4096 ;
* V_74 *= 1000 ;
* V_74 /= 256 ;
* V_74 *= 100 ;
V_63 = F_2 ( V_2 -> V_4 + V_64 ) ;
* V_36 = 'n' ;
if ( V_63 & V_91 ) {
if ( V_63 & V_93 )
* V_36 = 'e' ;
else
* V_36 = 'o' ;
}
switch ( V_63 & V_127 ) {
case V_87 :
* V_125 = 8 ;
break;
case V_85 :
* V_125 = 7 ;
break;
case V_83 :
* V_125 = 6 ;
break;
case V_81 :
* V_125 = 5 ;
break;
}
if ( F_2 ( V_2 -> V_4 + V_60 ) & V_95 )
* V_126 = 'r' ;
}
static int T_2
F_49 ( struct V_118 * V_119 , char * V_128 )
{
struct V_129 * V_130 ;
int V_74 = 9600 ;
int V_125 = 8 ;
int V_36 = 'n' ;
int V_126 = 'n' ;
if ( V_119 -> V_123 == - 1 || V_119 -> V_123 >= F_50 ( V_122 ) )
V_119 -> V_123 = 0 ;
V_130 = & V_122 [ V_119 -> V_123 ] ;
if ( V_128 ) {
F_51 ( V_128 , & V_74 , & V_36 , & V_125 , & V_126 ) ;
} else {
if ( F_2 ( V_130 -> V_2 . V_4 + V_5 ) & V_70 ) {
F_48 ( & V_130 -> V_2 , & V_74 ,
& V_36 , & V_125 , & V_126 ) ;
}
}
return F_52 ( & V_130 -> V_2 , V_119 , V_74 , V_36 , V_125 , V_126 ) ;
}
static int T_2 F_53 ( void )
{
F_54 ( & V_131 ) ;
return 0 ;
}
static int F_55 ( struct V_132 * V_133 , T_3 V_11 )
{
struct V_129 * V_130 = F_56 ( V_133 ) ;
if ( V_130 )
F_57 ( & V_134 , & V_130 -> V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_132 * V_133 )
{
struct V_129 * V_130 = F_56 ( V_133 ) ;
if ( V_130 )
F_59 ( & V_134 , & V_130 -> V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = & V_122 [ V_133 -> V_135 ] . V_2 ;
F_61 ( & V_133 -> V_67 , L_3 ) ;
V_2 -> V_67 = & V_133 -> V_67 ;
F_3 ( 1 , V_2 -> V_4 + V_136 ) ;
F_62 ( & V_134 , & V_122 [ V_133 -> V_135 ] . V_2 ) ;
F_63 ( V_133 , & V_122 [ V_133 -> V_135 ] ) ;
return 0 ;
}
static int F_64 ( struct V_132 * V_133 )
{
struct V_129 * V_130 = F_56 ( V_133 ) ;
F_63 ( V_133 , NULL ) ;
if ( V_130 )
F_65 ( & V_134 , & V_130 -> V_2 ) ;
return 0 ;
}
static int T_2 F_66 ( void )
{
int V_54 ;
F_67 ( V_137 L_4 ) ;
V_54 = F_68 ( & V_134 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_69 ( & V_138 ) ;
if ( V_54 != 0 )
F_70 ( & V_134 ) ;
return 0 ;
}
static void T_4 F_71 ( void )
{
F_72 ( & V_138 ) ;
F_70 ( & V_134 ) ;
}
