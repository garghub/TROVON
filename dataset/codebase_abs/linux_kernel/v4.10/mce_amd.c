const char * F_1 ( enum V_1 V_2 )
{
if ( V_2 >= V_3 )
return NULL ;
return V_4 [ V_2 ] . V_5 ;
}
const char * F_2 ( enum V_1 V_2 )
{
if ( V_2 >= V_3 )
return NULL ;
return V_4 [ V_2 ] . V_6 ;
}
static void F_3 ( void )
{
F_4 ( L_1 , V_7 ) ;
}
static void F_5 ( unsigned int V_8 )
{
unsigned int V_9 , V_10 , V_11 = F_6 () ;
struct V_12 * V_13 ;
T_1 V_14 , V_15 ;
if ( V_11 )
return;
if ( F_7 ( V_11 , F_8 ( V_8 ) , & V_15 , & V_14 ) ) {
F_9 ( L_2 , V_8 ) ;
return;
}
V_10 = F_10 ( V_14 & V_16 ,
( V_14 & V_17 ) >> 16 ) ;
for ( V_9 = 0 ; V_9 < F_11 ( V_18 ) ; V_9 ++ ) {
V_13 = & V_18 [ V_9 ] ;
if ( V_10 == V_13 -> V_10 ) {
F_12 ( V_19 [ V_8 ] . V_20 ,
L_3 ,
F_1 ( V_13 -> V_21 ) ) ;
V_19 [ V_8 ] . V_20 = V_13 ;
V_19 [ V_8 ] . V_22 = V_15 ;
break;
}
}
}
static inline bool F_13 ( int V_8 )
{
if ( V_23 . V_24 )
return false ;
return ( V_8 == 4 ) ;
}
static const char * F_14 ( const struct V_25 * V_26 )
{
switch ( V_26 -> V_27 ) {
case 0x00000413 :
return L_4 ;
case 0xc0000408 :
return L_5 ;
case 0xc0000409 :
return L_6 ;
default:
F_12 ( 1 , L_7 , V_26 -> V_27 ) ;
return L_8 ;
}
}
static bool F_15 ( unsigned int V_8 , T_1 V_28 )
{
if ( V_8 == 4 )
return true ;
return V_28 & F_16 ( 28 ) ;
}
static int F_17 ( struct V_25 * V_26 , int V_29 , T_1 V_30 , T_1 V_31 )
{
int V_32 = ( V_31 & V_33 ) >> 20 ;
if ( V_29 < 0 ) {
F_4 ( V_34 L_9
L_10 , V_26 -> V_11 ,
V_26 -> V_8 , V_26 -> V_35 , V_26 -> V_27 , V_31 , V_30 ) ;
return 0 ;
}
if ( V_29 != V_32 ) {
if ( V_23 . V_24 )
return 0 ;
F_4 ( V_34 L_11
L_10 ,
V_26 -> V_11 , V_29 , V_26 -> V_8 , V_26 -> V_35 , V_26 -> V_27 , V_31 , V_30 ) ;
return 0 ;
}
return 1 ;
}
static void F_18 ( void * V_36 )
{
struct V_37 * V_38 = V_36 ;
T_1 V_31 , V_30 ;
F_19 ( V_38 -> V_26 -> V_27 , V_30 , V_31 ) ;
if ( V_38 -> V_26 -> V_39 < ( V_31 & V_40 ) )
V_38 -> V_41 = 1 ;
if ( V_38 -> V_41 ) {
V_31 =
( V_31 & ~ ( V_42 | V_43 ) ) |
( V_40 - V_38 -> V_26 -> V_39 ) ;
} else if ( V_38 -> V_44 ) {
int V_45 = ( V_31 & V_40 ) +
( V_38 -> V_44 - V_38 -> V_26 -> V_39 ) ;
V_31 = ( V_31 & ~ V_42 ) |
( V_45 & V_40 ) ;
}
V_31 &= ~ V_46 ;
if ( ! V_38 -> V_26 -> V_47 )
goto V_48;
if ( V_38 -> V_49 ) {
if ( F_17 ( V_38 -> V_26 , V_38 -> V_50 , V_30 , V_31 ) ) {
V_31 &= ~ V_33 ;
V_31 |= V_38 -> V_50 << 20 ;
}
}
if ( V_38 -> V_26 -> V_51 )
V_31 |= V_52 ;
V_48:
V_31 |= V_53 ;
F_20 ( V_38 -> V_26 -> V_27 , V_30 , V_31 ) ;
}
static void F_21 ( struct V_25 * V_26 , int V_54 )
{
struct V_37 V_38 = {
. V_26 = V_26 ,
. V_49 = 1 ,
. V_50 = V_54 ,
} ;
V_26 -> V_39 = V_40 ;
F_18 ( & V_38 ) ;
}
static int F_22 ( int V_55 , int V_56 )
{
if ( V_55 < 0 && ! F_23 ( V_56 , V_57 ,
V_58 , 0 ) )
return V_56 ;
return V_55 ;
}
static int F_24 ( int V_55 , int V_56 )
{
if ( V_55 < 0 && ! F_23 ( V_56 , V_7 ,
V_58 , 0 ) )
return V_56 ;
return V_55 ;
}
static void F_25 ( struct V_59 * V_60 )
{
T_1 V_61 = 0 , V_14 = 0 ;
int V_62 = - 1 , V_63 ;
if ( F_26 ( V_64 , & V_61 , & V_14 ) )
return;
V_63 = ( V_61 & V_65 ) >> 4 ;
if ( ! ( V_61 & V_65 ) ) {
F_4 ( V_34 L_12 ) ;
V_63 = V_66 ;
V_61 = ( V_61 & ~ V_65 ) | ( V_66 << 4 ) ;
}
V_62 = F_24 ( V_62 , V_63 ) ;
if ( ( V_62 == V_63 ) &&
( V_67 != V_68 ) )
V_67 = V_68 ;
V_61 = ( V_61 & ~ V_69 ) | V_70 ;
F_20 ( V_64 , V_61 , V_14 ) ;
}
static T_1 F_27 ( unsigned int V_11 , T_1 V_71 , T_1 V_61 , T_1 V_14 ,
unsigned int V_8 , unsigned int V_35 )
{
T_1 V_72 = 0 , V_54 = 0 ;
if ( V_23 . V_24 ) {
if ( ! V_35 ) {
V_72 = F_28 ( V_8 ) ;
} else {
T_1 V_61 , V_14 ;
if ( F_7 ( V_11 , F_29 ( V_8 ) , & V_61 , & V_14 ) )
return V_72 ;
if ( ! ( V_61 & V_73 ) )
return V_72 ;
if ( ! F_7 ( V_11 , F_28 ( V_8 ) , & V_61 , & V_14 ) &&
( V_61 & V_74 ) )
V_72 = F_30 ( V_8 , V_35 - 1 ) ;
}
return V_72 ;
}
switch ( V_35 ) {
case 0 :
V_72 = V_75 . V_76 ( V_8 ) ;
break;
case 1 :
V_54 = ( ( V_61 & V_74 ) >> 21 ) ;
if ( V_54 )
V_72 = V_77 + V_54 ;
break;
default:
V_72 = ++ V_71 ;
}
return V_72 ;
}
static int
F_31 ( unsigned int V_8 , unsigned int V_35 , T_1 V_72 ,
int V_54 , T_1 V_78 )
{
unsigned int V_11 = F_6 () ;
T_1 V_79 , V_80 , V_81 ;
struct V_25 V_26 ;
int V_56 ;
if ( ! V_35 )
F_32 ( V_82 , V_11 ) |= ( 1 << V_8 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_11 = V_11 ;
V_26 . V_8 = V_8 ;
V_26 . V_35 = V_35 ;
V_26 . V_27 = V_72 ;
V_26 . V_47 = F_15 ( V_8 , V_78 ) ;
if ( ! V_26 . V_47 )
goto V_48;
V_26 . V_51 = 1 ;
if ( ! V_23 . V_24 ) {
V_56 = ( V_78 & V_33 ) >> 20 ;
goto V_83;
}
V_81 = F_29 ( V_8 ) ;
if ( ! F_26 ( V_81 , & V_79 , & V_80 ) ) {
V_80 |= F_16 ( 0 ) ;
V_80 &= ~ F_16 ( 2 ) ;
if ( ( V_79 & F_16 ( 5 ) ) && ! ( ( V_80 >> 5 ) & 0x3 ) )
V_80 |= F_16 ( 5 ) ;
F_20 ( V_81 , V_79 , V_80 ) ;
}
if ( F_26 ( V_64 , & V_79 , & V_80 ) )
goto V_84;
V_56 = ( V_79 & V_85 ) >> 12 ;
V_83:
V_54 = F_22 ( V_54 , V_56 ) ;
if ( ( V_54 == V_56 ) && ( V_86 != V_87 ) )
V_86 = V_87 ;
V_48:
F_21 ( & V_26 , V_54 ) ;
V_84:
return V_54 ;
}
void F_33 ( struct V_59 * V_60 )
{
T_1 V_61 = 0 , V_14 = 0 , V_27 = 0 ;
unsigned int V_8 , V_35 , V_11 = F_6 () ;
int V_54 = - 1 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( V_23 . V_24 )
F_5 ( V_8 ) ;
for ( V_35 = 0 ; V_35 < V_90 ; ++ V_35 ) {
V_27 = F_27 ( V_11 , V_27 , V_61 , V_14 , V_8 , V_35 ) ;
if ( ! V_27 )
break;
if ( F_26 ( V_27 , & V_61 , & V_14 ) )
break;
if ( ! ( V_14 & V_91 ) )
continue;
if ( ! ( V_14 & V_92 ) ||
( V_14 & V_93 ) )
continue;
V_54 = F_31 ( V_8 , V_35 , V_27 , V_54 , V_14 ) ;
}
}
if ( V_23 . V_94 )
F_25 ( V_60 ) ;
}
int F_34 ( T_2 V_95 , T_3 V_96 , T_4 V_97 , T_2 * V_98 )
{
T_2 V_99 , V_100 , V_101 ;
T_2 V_102 = V_95 ;
T_1 V_103 ;
T_4 V_104 , V_105 , V_106 , V_107 ;
T_4 V_108 , V_109 , V_110 ;
T_4 V_111 , V_112 ;
T_4 V_113 , V_114 ;
T_4 V_115 , V_116 = 0 ;
T_4 V_117 , V_118 = 0 ;
bool V_119 = false ;
if ( F_35 ( V_96 , 0 , 0x1B4 , V_97 , & V_103 ) )
goto V_120;
if ( V_103 & F_16 ( 0 ) ) {
T_2 V_121 = ( V_103 & F_36 ( 31 , 20 ) ) << 8 ;
if ( V_95 >= V_121 ) {
V_102 -= V_121 ;
V_116 = 1 ;
}
}
if ( F_35 ( V_96 , 0 , 0x110 + ( 8 * V_116 ) , V_97 , & V_103 ) )
goto V_120;
if ( ! ( V_103 & F_16 ( 0 ) ) ) {
F_4 ( L_13 ,
V_122 , V_103 ) ;
goto V_120;
}
V_115 = V_103 & F_16 ( 1 ) ;
V_109 = ( V_103 >> 4 ) & 0xF ;
V_111 = ( V_103 >> 8 ) & 0x7 ;
V_99 = ( V_103 & F_36 ( 31 , 12 ) ) << 16 ;
if ( V_111 > 3 ) {
F_4 ( L_14 ,
V_122 , V_111 ) ;
goto V_120;
}
if ( F_35 ( V_96 , 0 , 0x114 + ( 8 * V_116 ) , V_97 , & V_103 ) )
goto V_120;
V_110 = ( V_103 >> 8 ) & 0x1 ;
V_108 = ( V_103 >> 10 ) & 0x3 ;
V_100 = ( ( V_103 & F_36 ( 31 , 12 ) ) << 16 ) | F_36 ( 27 , 0 ) ;
V_112 = V_111 + 8 ;
switch ( V_109 ) {
case 0 : V_109 = 0 ; break;
case 1 : V_109 = 1 ; break;
case 3 : V_109 = 2 ; break;
case 5 : V_109 = 3 ; break;
case 7 : V_109 = 4 ; break;
case 8 : V_109 = 1 ;
V_119 = true ;
break;
default:
F_4 ( L_15 ,
V_122 , V_109 ) ;
goto V_120;
}
V_113 = V_109 ;
if ( V_108 > 2 ) {
F_4 ( L_16 ,
V_122 , V_108 ) ;
goto V_120;
}
V_113 += V_108 ;
V_113 += V_110 ;
if ( V_113 > 4 ) {
F_4 ( L_17 ,
V_122 , V_113 ) ;
goto V_120;
}
if ( V_113 > 0 ) {
T_2 V_123 , V_124 , V_125 ;
T_4 V_126 , V_127 , V_128 ;
if ( F_35 ( V_96 , 0 , 0x50 , V_97 , & V_103 ) )
goto V_120;
V_128 = ( V_103 >> 8 ) & 0xFF ;
V_126 = 0 ;
if ( V_109 ) {
V_126 = V_109 ;
V_117 = ( 1 << V_126 ) - 1 ;
V_118 = V_128 & V_117 ;
}
V_127 = V_126 ;
if ( V_108 || V_110 )
if ( F_35 ( V_96 , 1 , 0x208 , V_97 , & V_103 ) )
goto V_120;
if ( V_108 ) {
V_127 = V_126 + V_108 ;
V_104 = ( V_103 >> 24 ) & 0xF ;
V_105 = ( V_103 >> 8 ) & 0xFF ;
V_118 |= ( ( V_128 & V_105 ) >> V_104 ) << V_126 ;
}
if ( V_110 ) {
V_106 = ( V_103 >> 28 ) & 0xF ;
V_107 = ( V_103 >> 16 ) & 0xFF ;
V_118 |= ( ( V_128 & V_107 ) >> V_106 ) << V_127 ;
}
V_125 = V_102 & F_36 ( V_112 - 1 , 0 ) ;
V_124 = ( V_118 << V_112 ) ;
V_123 = ( V_102 & F_36 ( 63 , V_112 ) ) << V_113 ;
V_102 = V_123 | V_124 | V_125 ;
}
V_102 += V_99 ;
if ( V_115 ) {
if ( F_35 ( V_96 , 0 , 0x104 , V_97 , & V_103 ) )
goto V_120;
V_101 = V_103 & F_37 ( 31 , 24 ) ;
if ( V_102 >= V_101 )
V_102 += ( F_38 ( 32 ) - V_101 ) ;
}
if ( V_119 ) {
V_114 = ( V_102 >> 12 ) ^
( V_102 >> 18 ) ^
( V_102 >> 21 ) ^
( V_102 >> 30 ) ^
V_118 ;
V_114 &= F_16 ( 0 ) ;
if ( V_114 != ( ( V_102 >> V_112 ) & F_16 ( 0 ) ) )
V_102 ^= F_16 ( V_112 ) ;
}
if ( V_102 > V_100 )
goto V_120;
* V_98 = V_102 ;
return 0 ;
V_120:
return - V_129 ;
}
static void
F_39 ( unsigned int V_8 , bool V_130 , bool V_131 , T_2 V_76 )
{
T_1 V_132 = V_75 . V_133 ( V_8 ) ;
T_1 V_134 = V_75 . V_72 ( V_8 ) ;
struct V_135 V_136 ;
T_2 V_133 ;
F_40 ( V_130 && V_131 ) ;
if ( V_130 && V_23 . V_24 ) {
V_132 = F_41 ( V_8 ) ;
V_134 = F_42 ( V_8 ) ;
}
F_43 ( V_132 , V_133 ) ;
if ( ! ( V_133 & V_137 ) )
return;
F_44 ( & V_136 ) ;
V_136 . V_133 = V_133 ;
V_136 . V_8 = V_8 ;
if ( V_131 )
V_136 . V_76 = V_76 ;
if ( V_136 . V_133 & V_138 ) {
F_43 ( V_134 , V_136 . V_72 ) ;
if ( V_23 . V_24 ) {
T_4 V_139 = ( V_136 . V_72 >> 56 ) & 0x3f ;
V_136 . V_72 &= F_36 ( 55 , V_139 ) ;
}
}
if ( V_23 . V_24 ) {
F_43 ( F_8 ( V_8 ) , V_136 . V_140 ) ;
if ( V_136 . V_133 & V_141 )
F_43 ( F_45 ( V_8 ) , V_136 . V_142 ) ;
}
F_46 ( & V_136 ) ;
F_47 ( V_132 , 0 ) ;
}
static inline void F_48 ( void )
{
F_49 ( V_143 ) ;
V_67 () ;
}
T_5 T_6 void F_50 ( void )
{
F_51 () ;
F_48 () ;
F_52 () ;
}
T_5 T_6 void F_53 ( void )
{
F_51 () ;
F_54 ( V_7 ) ;
F_48 () ;
F_55 ( V_7 ) ;
F_52 () ;
}
static void V_68 ( void )
{
unsigned int V_8 ;
T_1 V_132 ;
T_2 V_133 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
V_132 = ( V_23 . V_24 ) ? F_41 ( V_8 )
: V_75 . V_133 ( V_8 ) ;
F_43 ( V_132 , V_133 ) ;
if ( ! ( V_133 & V_137 ) ||
! ( V_133 & V_144 ) )
continue;
F_39 ( V_8 , true , false , 0 ) ;
break;
}
}
static void V_87 ( void )
{
T_1 V_61 = 0 , V_14 = 0 , V_27 = 0 ;
unsigned int V_8 , V_35 , V_11 = F_6 () ;
struct V_37 V_38 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_11 ) & ( 1 << V_8 ) ) )
continue;
for ( V_35 = 0 ; V_35 < V_90 ; ++ V_35 ) {
V_27 = F_27 ( V_11 , V_27 , V_61 , V_14 , V_8 , V_35 ) ;
if ( ! V_27 )
break;
if ( F_26 ( V_27 , & V_61 , & V_14 ) )
break;
if ( ! ( V_14 & V_91 ) ) {
if ( V_35 )
continue;
else
break;
}
if ( ! ( V_14 & V_92 ) ||
( V_14 & V_93 ) )
continue;
if ( V_14 & V_43 )
goto log;
}
}
return;
log:
F_39 ( V_8 , false , true , ( ( T_2 ) V_14 << 32 ) | V_61 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_26 = & F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 [ V_35 ] ;
F_18 ( & V_38 ) ;
}
static T_7
F_56 ( struct V_25 * V_26 , const char * V_147 , T_8 V_148 )
{
struct V_37 V_38 ;
unsigned long V_56 ;
if ( ! V_26 -> V_47 )
return - V_129 ;
if ( F_57 ( V_147 , 0 , & V_56 ) < 0 )
return - V_129 ;
V_26 -> V_51 = ! ! V_56 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_26 = V_26 ;
F_58 ( V_26 -> V_11 , F_18 , & V_38 , 1 ) ;
return V_148 ;
}
static T_7
F_59 ( struct V_25 * V_26 , const char * V_147 , T_8 V_148 )
{
struct V_37 V_38 ;
unsigned long V_56 ;
if ( F_57 ( V_147 , 0 , & V_56 ) < 0 )
return - V_129 ;
if ( V_56 > V_40 )
V_56 = V_40 ;
if ( V_56 < 1 )
V_56 = 1 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_44 = V_26 -> V_39 ;
V_26 -> V_39 = V_56 ;
V_38 . V_26 = V_26 ;
F_58 ( V_26 -> V_11 , F_18 , & V_38 , 1 ) ;
return V_148 ;
}
static T_7 F_60 ( struct V_25 * V_26 , char * V_147 )
{
T_1 V_30 , V_31 ;
F_61 ( V_26 -> V_11 , V_26 -> V_27 , & V_30 , & V_31 ) ;
return sprintf ( V_147 , L_18 , ( ( V_31 & V_40 ) -
( V_40 - V_26 -> V_39 ) ) ) ;
}
static T_7 F_62 ( struct V_149 * V_150 , struct V_151 * V_152 , char * V_147 )
{
struct V_25 * V_26 = F_63 ( V_150 ) ;
struct V_153 * V_154 = F_64 ( V_152 ) ;
T_7 V_155 ;
V_155 = V_154 -> F_62 ? V_154 -> F_62 ( V_26 , V_147 ) : - V_156 ;
return V_155 ;
}
static T_7 F_65 ( struct V_149 * V_150 , struct V_151 * V_152 ,
const char * V_147 , T_8 V_157 )
{
struct V_25 * V_26 = F_63 ( V_150 ) ;
struct V_153 * V_154 = F_64 ( V_152 ) ;
T_7 V_155 ;
V_155 = V_154 -> F_65 ? V_154 -> F_65 ( V_26 , V_147 , V_157 ) : - V_156 ;
return V_155 ;
}
static const char * F_66 ( unsigned int V_8 , struct V_25 * V_26 )
{
unsigned int V_21 ;
if ( ! V_23 . V_24 ) {
if ( V_26 && V_8 == 4 )
return F_14 ( V_26 ) ;
return V_158 [ V_8 ] ;
}
if ( ! V_19 [ V_8 ] . V_20 )
return NULL ;
V_21 = V_19 [ V_8 ] . V_20 -> V_21 ;
if ( V_26 && V_21 == V_159 ) {
if ( V_26 -> V_35 < F_11 ( V_160 ) )
return V_160 [ V_26 -> V_35 ] ;
return NULL ;
}
snprintf ( V_161 , V_162 ,
L_19 , F_1 ( V_21 ) ,
V_19 [ V_8 ] . V_22 ) ;
return V_161 ;
}
static int F_67 ( unsigned int V_11 , unsigned int V_8 ,
unsigned int V_35 , T_1 V_27 )
{
struct V_25 * V_26 = NULL ;
T_1 V_61 , V_14 ;
int V_163 ;
if ( ( V_8 >= V_88 . V_89 ) || ( V_35 >= V_90 ) )
return 0 ;
if ( F_7 ( V_11 , V_27 , & V_61 , & V_14 ) )
return 0 ;
if ( ! ( V_14 & V_91 ) ) {
if ( V_35 )
goto V_164;
else
return 0 ;
}
if ( ! ( V_14 & V_92 ) ||
( V_14 & V_93 ) )
goto V_164;
V_26 = F_68 ( sizeof( struct V_25 ) , V_165 ) ;
if ( ! V_26 )
return - V_166 ;
V_26 -> V_35 = V_35 ;
V_26 -> V_8 = V_8 ;
V_26 -> V_11 = V_11 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_51 = 0 ;
V_26 -> V_47 = F_15 ( V_8 , V_14 ) ;
V_26 -> V_39 = V_40 ;
if ( V_26 -> V_47 ) {
V_167 . V_168 [ 2 ] = & V_51 . V_152 ;
V_26 -> V_51 = 1 ;
} else {
V_167 . V_168 [ 2 ] = NULL ;
}
F_69 ( & V_26 -> V_169 ) ;
if ( F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 ) {
F_70 ( & V_26 -> V_169 ,
& F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 -> V_169 ) ;
} else {
F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 = V_26 ;
}
V_163 = F_71 ( & V_26 -> V_150 , & V_167 ,
F_32 ( V_145 , V_11 ) [ V_8 ] -> V_150 ,
F_66 ( V_8 , V_26 ) ) ;
if ( V_163 )
goto V_170;
V_164:
V_27 = F_27 ( V_11 , V_27 , V_61 , V_14 , V_8 , ++ V_35 ) ;
if ( ! V_27 )
return 0 ;
V_163 = F_67 ( V_11 , V_8 , V_35 , V_27 ) ;
if ( V_163 )
goto V_170;
if ( V_26 )
F_72 ( & V_26 -> V_150 , V_171 ) ;
return V_163 ;
V_170:
if ( V_26 ) {
F_73 ( & V_26 -> V_150 ) ;
F_74 ( & V_26 -> V_169 ) ;
F_75 ( V_26 ) ;
}
return V_163 ;
}
static int F_76 ( struct V_172 * V_26 )
{
struct V_173 * V_174 = & V_26 -> V_146 -> V_169 ;
struct V_25 * V_175 = NULL ;
struct V_25 * V_103 = NULL ;
int V_163 = 0 ;
V_163 = F_77 ( & V_26 -> V_146 -> V_150 , V_26 -> V_150 , V_26 -> V_146 -> V_150 . V_5 ) ;
if ( V_163 )
return V_163 ;
F_78 (pos, tmp, head, miscj) {
V_163 = F_77 ( & V_175 -> V_150 , V_26 -> V_150 , V_175 -> V_150 . V_5 ) ;
if ( V_163 ) {
F_79 (pos, tmp, head, miscj)
F_80 ( & V_175 -> V_150 ) ;
return V_163 ;
}
}
return V_163 ;
}
static int F_81 ( unsigned int V_11 , unsigned int V_8 )
{
struct V_176 * V_177 = F_32 ( V_178 , V_11 ) ;
struct V_179 * V_180 = NULL ;
struct V_172 * V_26 = NULL ;
const char * V_5 = F_66 ( V_8 , NULL ) ;
int V_163 = 0 ;
if ( ! V_177 )
return - V_181 ;
if ( F_13 ( V_8 ) ) {
V_180 = F_82 ( F_83 ( V_11 ) ) ;
if ( V_180 && V_180 -> V_182 ) {
V_26 = V_180 -> V_182 ;
V_163 = F_77 ( V_26 -> V_150 , & V_177 -> V_150 , V_5 ) ;
if ( V_163 )
goto V_84;
F_32 ( V_145 , V_11 ) [ V_8 ] = V_26 ;
F_84 ( & V_26 -> V_183 ) ;
V_163 = F_76 ( V_26 ) ;
goto V_84;
}
}
V_26 = F_68 ( sizeof( struct V_172 ) , V_165 ) ;
if ( ! V_26 ) {
V_163 = - V_166 ;
goto V_84;
}
V_26 -> V_150 = F_85 ( V_5 , & V_177 -> V_150 ) ;
if ( ! V_26 -> V_150 ) {
V_163 = - V_129 ;
goto V_170;
}
F_32 ( V_145 , V_11 ) [ V_8 ] = V_26 ;
if ( F_13 ( V_8 ) ) {
F_86 ( & V_26 -> V_183 , 1 ) ;
if ( V_180 ) {
F_87 ( V_180 -> V_182 ) ;
V_180 -> V_182 = V_26 ;
}
}
V_163 = F_67 ( V_11 , V_8 , 0 , V_75 . V_76 ( V_8 ) ) ;
if ( ! V_163 )
goto V_84;
V_170:
F_75 ( V_26 ) ;
V_84:
return V_163 ;
}
static void F_88 ( unsigned int V_11 ,
unsigned int V_8 )
{
struct V_25 * V_175 = NULL ;
struct V_25 * V_103 = NULL ;
struct V_172 * V_174 = F_32 ( V_145 , V_11 ) [ V_8 ] ;
if ( ! V_174 )
return;
F_78 (pos, tmp, &head->blocks->miscj, miscj) {
F_73 ( & V_175 -> V_150 ) ;
F_74 ( & V_175 -> V_169 ) ;
F_75 ( V_175 ) ;
}
F_75 ( F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 ) ;
F_32 ( V_145 , V_11 ) [ V_8 ] -> V_146 = NULL ;
}
static void F_89 ( struct V_172 * V_26 )
{
struct V_25 * V_175 = NULL ;
struct V_25 * V_103 = NULL ;
F_80 ( V_26 -> V_150 ) ;
F_78 (pos, tmp, &b->blocks->miscj, miscj)
F_80 ( & V_175 -> V_150 ) ;
}
static void F_90 ( unsigned int V_11 , int V_8 )
{
struct V_179 * V_180 ;
struct V_172 * V_26 ;
V_26 = F_32 ( V_145 , V_11 ) [ V_8 ] ;
if ( ! V_26 )
return;
if ( ! V_26 -> V_146 )
goto V_184;
if ( F_13 ( V_8 ) ) {
if ( ! F_91 ( & V_26 -> V_183 ) ) {
F_89 ( V_26 ) ;
F_32 ( V_145 , V_11 ) [ V_8 ] = NULL ;
return;
} else {
V_180 = F_82 ( F_83 ( V_11 ) ) ;
V_180 -> V_182 = NULL ;
}
}
F_88 ( V_11 , V_8 ) ;
V_184:
F_80 ( V_26 -> V_150 ) ;
F_73 ( V_26 -> V_150 ) ;
F_75 ( V_26 ) ;
F_32 ( V_145 , V_11 ) [ V_8 ] = NULL ;
}
int F_92 ( unsigned int V_11 )
{
unsigned int V_8 ;
if ( ! V_185 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_11 ) & ( 1 << V_8 ) ) )
continue;
F_90 ( V_11 , V_8 ) ;
}
F_75 ( F_32 ( V_145 , V_11 ) ) ;
F_32 ( V_145 , V_11 ) = NULL ;
return 0 ;
}
int F_93 ( unsigned int V_11 )
{
unsigned int V_8 ;
struct V_172 * * V_186 ;
int V_163 = 0 ;
if ( ! V_185 )
return 0 ;
V_186 = F_32 ( V_145 , V_11 ) ;
if ( V_186 )
return 0 ;
V_186 = F_68 ( sizeof( struct V_172 * ) * V_88 . V_89 ,
V_165 ) ;
if ( ! V_186 )
return - V_166 ;
F_32 ( V_145 , V_11 ) = V_186 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_11 ) & ( 1 << V_8 ) ) )
continue;
V_163 = F_81 ( V_11 , V_8 ) ;
if ( V_163 )
goto V_163;
}
return V_163 ;
V_163:
F_92 ( V_11 ) ;
return V_163 ;
}
static T_9 int F_94 ( void )
{
unsigned V_187 = 0 ;
if ( V_86 == V_87 )
V_185 = true ;
F_95 (lcpu) {
int V_163 = F_93 ( V_187 ) ;
if ( V_163 )
return V_163 ;
}
return 0 ;
}
