static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 , V_9 ;
unsigned int V_10 ;
char V_11 = V_12 ;
V_6 = F_2 ( & V_4 -> V_13 -> V_4 ) ;
F_3 ( & V_4 -> V_14 , V_7 ) ;
V_8 = F_4 ( V_15 ) ;
if ( V_8 & V_4 -> V_16 & V_17 )
V_8 &= ~ ( V_18 | V_19 ) ;
V_8 &= V_4 -> V_20 ;
V_8 &= ~ V_4 -> V_16 ;
if ( ( V_8 & V_19 ) ||
( V_8 & V_18 ) ) {
while ( ( F_4 ( V_21 ) &
V_22 ) != V_22 ) {
V_10 = F_4 ( V_23 ) ;
V_4 -> V_24 . V_25 ++ ;
if ( V_8 & V_17 ) {
V_4 -> V_24 . V_26 ++ ;
V_11 = V_27 ;
} else if ( V_8 & V_28 ) {
V_4 -> V_24 . V_29 ++ ;
V_11 = V_30 ;
} else if ( V_8 & V_31 )
V_4 -> V_24 . V_32 ++ ;
if ( V_6 )
F_5 ( V_4 , V_8 ,
V_31 , V_10 ,
V_11 ) ;
}
F_6 ( & V_4 -> V_14 ) ;
if ( V_6 )
F_7 ( V_6 ) ;
F_8 ( & V_4 -> V_14 ) ;
}
if ( ( V_8 & V_33 ) == V_33 ) {
if ( F_9 ( & V_4 -> V_13 -> V_34 ) ) {
F_10 ( V_33 ,
V_35 ) ;
} else {
V_9 = V_4 -> V_36 ;
while ( V_9 -- ) {
if ( F_9 ( & V_4 -> V_13 -> V_34 ) )
break;
F_10 (
V_4 -> V_13 -> V_34 . V_37 [ V_4 -> V_13 -> V_34 .
V_38 ] , V_23 ) ;
V_4 -> V_24 . V_39 ++ ;
V_4 -> V_13 -> V_34 . V_38 =
( V_4 -> V_13 -> V_34 . V_38 + 1 ) & \
( V_40 - 1 ) ;
}
if ( F_11 (
& V_4 -> V_13 -> V_34 ) < V_41 )
F_12 ( V_4 ) ;
}
}
F_10 ( V_8 , V_15 ) ;
F_13 ( & V_4 -> V_14 , V_7 ) ;
F_14 ( V_6 ) ;
return V_42 ;
}
static unsigned int F_15 ( struct V_3 * V_4 ,
unsigned int V_43 )
{
unsigned int V_44 ;
unsigned int V_45 = 0 ;
unsigned int V_46 , V_47 ;
unsigned int V_48 ;
V_44 = V_4 -> V_49 ;
if ( F_4 ( V_50 ) & V_51 )
V_44 = V_44 / 8 ;
for ( V_47 = 4 ; V_47 < 255 ; V_47 ++ ) {
V_46 = V_44 / ( V_43 * ( V_47 + 1 ) ) ;
if ( V_46 < 2 || V_46 > 65535 )
continue;
V_45 = V_44 / ( V_46 * ( V_47 + 1 ) ) ;
if ( V_43 > V_45 )
V_48 = V_43 - V_45 ;
else
V_48 = V_45 - V_43 ;
if ( ( ( V_48 * 100 ) / V_43 ) < 3 ) {
V_45 = V_43 ;
break;
}
}
F_10 ( V_46 , V_52 ) ;
F_10 ( V_47 , V_53 ) ;
return V_45 ;
}
static void F_16 ( struct V_3 * V_4 )
{
unsigned int V_11 , V_9 = V_4 -> V_36 ;
if ( F_9 ( & V_4 -> V_13 -> V_34 ) || F_17 ( V_4 ) )
return;
V_11 = F_4 ( V_54 ) ;
F_10 ( ( V_11 & ~ V_55 ) | V_56 ,
V_54 ) ;
while ( V_9 -- && ( ( F_4 ( V_21 )
& V_57 ) ) != V_57 ) {
if ( F_9 ( & V_4 -> V_13 -> V_34 ) )
break;
F_10 (
V_4 -> V_13 -> V_34 . V_37 [ V_4 -> V_13 -> V_34 . V_38 ] ,
V_23 ) ;
V_4 -> V_24 . V_39 ++ ;
V_4 -> V_13 -> V_34 . V_38 = ( V_4 -> V_13 -> V_34 . V_38 + 1 ) &
( V_40 - 1 ) ;
}
F_10 ( V_33 , V_58 ) ;
if ( F_11 ( & V_4 -> V_13 -> V_34 ) < V_41 )
F_12 ( V_4 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
unsigned int V_59 ;
V_59 = F_4 ( V_54 ) ;
V_59 |= V_55 ;
F_10 ( V_59 , V_54 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
unsigned int V_59 ;
V_59 = F_4 ( V_54 ) ;
V_59 |= V_60 ;
F_10 ( V_59 , V_54 ) ;
}
static unsigned int F_20 ( struct V_3 * V_4 )
{
unsigned int V_11 ;
V_11 = F_4 ( V_15 ) & V_33 ;
return V_11 ? V_61 : 0 ;
}
static void F_21 ( struct V_3 * V_4 , int V_62 )
{
unsigned int V_11 ;
unsigned long V_7 ;
F_3 ( & V_4 -> V_14 , V_7 ) ;
V_11 = F_4 ( V_54 ) ;
if ( V_62 == - 1 )
F_10 ( V_63 | V_11 ,
V_54 ) ;
else {
if ( ( V_11 & V_64 ) == 0 )
F_10 ( V_64 | V_11 ,
V_54 ) ;
}
F_13 ( & V_4 -> V_14 , V_7 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_65 * V_66 , struct V_65 * V_67 )
{
unsigned int V_68 = 0 ;
unsigned int V_43 ;
unsigned long V_7 ;
unsigned int V_69 , V_70 ;
F_3 ( & V_4 -> V_14 , V_7 ) ;
while ( ( F_4 ( V_21 ) &
V_22 ) != V_22 ) {
F_4 ( V_23 ) ;
}
F_10 ( F_4 ( V_54 ) |
( V_55 | V_60 ) ,
V_54 ) ;
V_43 = F_23 ( V_4 , V_66 , V_67 , 0 , 10000000 ) ;
V_43 = F_15 ( V_4 , V_43 ) ;
if ( F_24 ( V_66 ) )
F_25 ( V_66 , V_43 , V_43 ) ;
F_26 ( V_4 , V_66 -> V_71 , V_43 ) ;
F_10 ( F_4 ( V_54 ) |
( V_72 | V_73 ) ,
V_54 ) ;
V_69 = F_4 ( V_54 ) ;
F_10 (
( V_69 & ~ ( V_55 | V_60 ) )
| ( V_56 | V_74 ) ,
V_54 ) ;
F_10 ( 10 , V_75 ) ;
V_4 -> V_20 = V_33 | V_18 |
V_31 | V_19 ;
V_4 -> V_16 = 0 ;
if ( V_66 -> V_76 & V_77 )
V_4 -> V_20 |= V_17 |
V_28 ;
if ( V_66 -> V_76 & V_78 )
V_4 -> V_16 |= V_17 |
V_28 | V_31 ;
if ( ( V_66 -> V_71 & V_79 ) == 0 )
V_4 -> V_16 |= V_18 |
V_19 | V_17 |
V_28 | V_31 ;
V_70 = F_4 ( V_50 ) ;
switch ( V_66 -> V_71 & V_80 ) {
case V_81 :
V_68 |= V_82 ;
break;
case V_83 :
V_68 |= V_84 ;
break;
default:
case V_85 :
V_68 |= V_86 ;
V_66 -> V_71 &= ~ V_80 ;
V_66 -> V_71 |= V_85 ;
break;
}
if ( V_66 -> V_71 & V_87 )
V_68 |= V_88 ;
else
V_68 |= V_89 ;
if ( V_66 -> V_71 & V_90 ) {
if ( V_66 -> V_71 & V_91 ) {
if ( V_66 -> V_71 & V_92 )
V_68 |= V_93 ;
else
V_68 |= V_94 ;
} else if ( V_66 -> V_71 & V_92 )
V_68 |= V_95 ;
else
V_68 |= V_96 ;
} else
V_68 |= V_97 ;
F_10 ( V_68 , V_50 ) ;
F_13 ( & V_4 -> V_14 , V_7 ) ;
}
static int F_27 ( struct V_3 * V_4 )
{
unsigned int V_98 = 0 , V_11 = 0 ;
V_98 = F_28 ( V_4 -> V_1 , F_1 , 0 , V_99 ,
( void * ) V_4 ) ;
if ( V_98 )
return V_98 ;
F_10 ( V_55 | V_60 ,
V_54 ) ;
F_10 ( V_72 | V_73 ,
V_54 ) ;
V_11 = F_4 ( V_54 ) ;
F_10 ( ( V_11 & ~ ( V_55 | V_60 ) )
| ( V_56 | V_74 |
V_64 ) , V_54 ) ;
F_10 ( V_100 | V_89
| V_97 | V_86 ,
V_50 ) ;
F_10 ( 14 , V_101 ) ;
F_10 ( 10 , V_75 ) ;
F_10 ( V_33 | V_17 |
V_28 | V_31 |
V_18 | V_19 , V_58 ) ;
F_10 ( ~ ( V_33 | V_17 |
V_28 | V_31 |
V_18 | V_19 ) , V_35 ) ;
return V_98 ;
}
static void F_29 ( struct V_3 * V_4 )
{
int V_11 ;
V_11 = F_4 ( V_102 ) ;
F_10 ( V_11 , V_35 ) ;
F_10 ( V_55 | V_60 ,
V_54 ) ;
F_30 ( V_4 -> V_1 , V_4 ) ;
}
static const char * F_31 ( struct V_3 * V_4 )
{
return V_4 -> type == V_103 ? V_99 : NULL ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_104 * V_105 )
{
if ( V_105 -> type != V_106 && V_105 -> type != V_103 )
return - V_107 ;
if ( V_4 -> V_1 != V_105 -> V_1 )
return - V_107 ;
if ( V_105 -> V_108 != V_109 )
return - V_107 ;
if ( V_4 -> V_110 != V_105 -> V_4 )
return - V_107 ;
if ( V_105 -> V_111 != 0 )
return - V_107 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
if ( ! F_34 ( V_4 -> V_112 , V_113 ,
V_99 ) ) {
return - V_114 ;
}
V_4 -> V_115 = F_35 ( V_4 -> V_112 , V_113 ) ;
if ( ! V_4 -> V_115 ) {
F_36 ( V_4 -> V_116 , L_1 ) ;
F_37 ( V_4 -> V_112 , V_113 ) ;
return - V_114 ;
}
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
F_37 ( V_4 -> V_112 , V_113 ) ;
F_39 ( V_4 -> V_115 ) ;
V_4 -> V_115 = NULL ;
}
static void F_40 ( struct V_3 * V_4 , int V_7 )
{
if ( V_7 & V_117 && F_33 ( V_4 ) == 0 )
V_4 -> type = V_103 ;
}
static unsigned int F_41 ( struct V_3 * V_4 )
{
return V_118 | V_119 | V_120 ;
}
static void F_42 ( struct V_3 * V_4 , unsigned int V_121 )
{
}
static void F_43 ( struct V_3 * V_4 )
{
}
static struct V_3 * F_44 ( void )
{
struct V_3 * V_4 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
if ( V_124 [ V_122 ] . V_112 == 0 )
break;
if ( V_122 >= V_123 )
return NULL ;
V_4 = & V_124 [ V_122 ] ;
F_45 ( & V_4 -> V_14 ) ;
V_4 -> V_115 = NULL ;
V_4 -> V_110 = 1 ;
V_4 -> V_1 = 0 ;
V_4 -> type = V_106 ;
V_4 -> V_125 = V_126 ;
V_4 -> V_7 = V_127 ;
V_4 -> V_128 = & V_129 ;
V_4 -> V_36 = V_130 ;
V_4 -> line = V_122 ;
V_4 -> V_116 = NULL ;
return V_4 ;
}
static void F_46 ( struct V_3 * V_4 )
{
while ( ( F_4 ( V_21 ) & V_131 )
!= V_131 )
F_47 () ;
}
static void F_48 ( struct V_3 * V_4 , int V_132 )
{
F_46 ( V_4 ) ;
F_10 ( V_132 , V_23 ) ;
}
static void F_49 ( struct V_133 * V_134 , const char * V_135 ,
unsigned int V_136 )
{
struct V_3 * V_4 = & V_124 [ V_134 -> V_137 ] ;
unsigned long V_7 ;
unsigned int V_138 ;
int V_139 = 1 ;
if ( V_140 )
V_139 = F_50 ( & V_4 -> V_14 , V_7 ) ;
else
F_3 ( & V_4 -> V_14 , V_7 ) ;
V_138 = F_4 ( V_102 ) ;
F_10 ( V_138 , V_35 ) ;
F_51 ( V_4 , V_135 , V_136 , F_48 ) ;
F_46 ( V_4 ) ;
F_10 ( ~ V_138 , V_35 ) ;
F_10 ( V_138 , V_58 ) ;
if ( V_139 )
F_13 ( & V_4 -> V_14 , V_7 ) ;
}
static int T_2 F_52 ( struct V_133 * V_134 , char * V_141 )
{
struct V_3 * V_4 = & V_124 [ V_134 -> V_137 ] ;
int V_43 = 9600 ;
int V_142 = 8 ;
int V_26 = 'n' ;
int V_143 = 'n' ;
if ( V_134 -> V_137 < 0 || V_134 -> V_137 >= V_123 )
return - V_107 ;
if ( ! V_4 -> V_112 ) {
F_53 ( L_2 , V_134 -> V_137 ) ;
return - V_144 ;
}
if ( V_141 )
F_54 ( V_141 , & V_43 , & V_26 , & V_142 , & V_143 ) ;
return F_55 ( V_4 , V_134 , V_43 , V_26 , V_142 , V_143 ) ;
}
static int T_2 F_56 ( void )
{
F_57 ( & V_145 ) ;
return 0 ;
}
static int T_3 F_58 ( struct V_146 * V_147 )
{
int V_148 ;
struct V_3 * V_4 ;
struct V_149 * V_150 , * V_151 ;
int V_152 = 0 ;
#ifdef F_59
const unsigned int * V_153 ;
V_153 = F_60 ( V_147 -> V_116 . V_154 , L_3 , NULL ) ;
if ( V_153 )
V_152 = F_61 ( V_153 ) ;
#else
V_152 = * ( ( unsigned int * ) ( V_147 -> V_116 . V_155 ) ) ;
#endif
if ( ! V_152 ) {
F_36 ( & V_147 -> V_116 , L_4 ) ;
return - V_144 ;
}
V_150 = F_62 ( V_147 , V_156 , 0 ) ;
if ( ! V_150 )
return - V_144 ;
V_151 = F_62 ( V_147 , V_157 , 0 ) ;
if ( ! V_151 )
return - V_144 ;
V_4 = F_44 () ;
if ( ! V_4 ) {
F_36 ( & V_147 -> V_116 , L_5 ) ;
return - V_144 ;
} else {
V_4 -> V_112 = V_150 -> V_158 ;
V_4 -> V_1 = V_151 -> V_158 ;
V_4 -> V_116 = & V_147 -> V_116 ;
V_4 -> V_49 = V_152 ;
F_63 ( & V_147 -> V_116 , V_4 ) ;
V_148 = F_64 ( & V_159 , V_4 ) ;
if ( V_148 ) {
F_36 ( & V_147 -> V_116 ,
L_6 , V_148 ) ;
F_63 ( & V_147 -> V_116 , NULL ) ;
return V_148 ;
}
return 0 ;
}
}
static int T_4 F_65 ( struct V_146 * V_147 )
{
struct V_3 * V_4 = F_66 ( & V_147 -> V_116 ) ;
int V_148 = 0 ;
if ( V_4 ) {
V_148 = F_67 ( & V_159 , V_4 ) ;
F_63 ( & V_147 -> V_116 , NULL ) ;
V_4 -> V_112 = 0 ;
}
return V_148 ;
}
static int F_68 ( struct V_146 * V_147 , T_5 V_13 )
{
F_69 ( & V_159 , & V_124 [ V_147 -> V_122 ] ) ;
return 0 ;
}
static int F_70 ( struct V_146 * V_147 )
{
F_71 ( & V_159 , & V_124 [ V_147 -> V_122 ] ) ;
return 0 ;
}
static int T_2 F_72 ( void )
{
int V_98 = 0 ;
V_98 = F_73 ( & V_159 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_74 ( & V_160 ) ;
if ( V_98 )
F_75 ( & V_159 ) ;
return V_98 ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_160 ) ;
F_75 ( & V_159 ) ;
}
