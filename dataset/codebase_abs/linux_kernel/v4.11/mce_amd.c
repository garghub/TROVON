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
V_19 [ V_8 ] . V_23 = V_13 -> V_24 ++ ;
break;
}
}
}
static inline bool F_13 ( int V_8 )
{
if ( V_25 . V_26 )
return false ;
return ( V_8 == 4 ) ;
}
static const char * F_14 ( const struct V_27 * V_28 )
{
switch ( V_28 -> V_29 ) {
case 0x00000413 :
return L_4 ;
case 0xc0000408 :
return L_5 ;
case 0xc0000409 :
return L_6 ;
default:
F_12 ( 1 , L_7 , V_28 -> V_29 ) ;
return L_8 ;
}
}
static bool F_15 ( unsigned int V_8 , T_1 V_30 )
{
if ( V_8 == 4 )
return true ;
return V_30 & F_16 ( 28 ) ;
}
static int F_17 ( struct V_27 * V_28 , int V_31 , T_1 V_32 , T_1 V_33 )
{
int V_34 = ( V_33 & V_35 ) >> 20 ;
if ( V_31 < 0 ) {
F_4 ( V_36 L_9
L_10 , V_28 -> V_11 ,
V_28 -> V_8 , V_28 -> V_37 , V_28 -> V_29 , V_33 , V_32 ) ;
return 0 ;
}
if ( V_31 != V_34 ) {
if ( V_25 . V_26 )
return 0 ;
F_4 ( V_36 L_11
L_10 ,
V_28 -> V_11 , V_31 , V_28 -> V_8 , V_28 -> V_37 , V_28 -> V_29 , V_33 , V_32 ) ;
return 0 ;
}
return 1 ;
}
static void F_18 ( void * V_38 )
{
struct V_39 * V_40 = V_38 ;
T_1 V_33 , V_32 ;
F_19 ( V_40 -> V_28 -> V_29 , V_32 , V_33 ) ;
if ( V_40 -> V_28 -> V_41 < ( V_33 & V_42 ) )
V_40 -> V_43 = 1 ;
if ( V_40 -> V_43 ) {
V_33 =
( V_33 & ~ ( V_44 | V_45 ) ) |
( V_42 - V_40 -> V_28 -> V_41 ) ;
} else if ( V_40 -> V_46 ) {
int V_47 = ( V_33 & V_42 ) +
( V_40 -> V_46 - V_40 -> V_28 -> V_41 ) ;
V_33 = ( V_33 & ~ V_44 ) |
( V_47 & V_42 ) ;
}
V_33 &= ~ V_48 ;
if ( ! V_40 -> V_28 -> V_49 )
goto V_50;
if ( V_40 -> V_51 ) {
if ( F_17 ( V_40 -> V_28 , V_40 -> V_52 , V_32 , V_33 ) ) {
V_33 &= ~ V_35 ;
V_33 |= V_40 -> V_52 << 20 ;
}
}
if ( V_40 -> V_28 -> V_53 )
V_33 |= V_54 ;
V_50:
V_33 |= V_55 ;
F_20 ( V_40 -> V_28 -> V_29 , V_32 , V_33 ) ;
}
static void F_21 ( struct V_27 * V_28 , int V_56 )
{
struct V_39 V_40 = {
. V_28 = V_28 ,
. V_51 = 1 ,
. V_52 = V_56 ,
} ;
V_28 -> V_41 = V_42 ;
F_18 ( & V_40 ) ;
}
static int F_22 ( int V_57 , int V_58 )
{
if ( V_57 < 0 && ! F_23 ( V_58 , V_59 ,
V_60 , 0 ) )
return V_58 ;
return V_57 ;
}
static int F_24 ( int V_57 , int V_58 )
{
if ( V_57 < 0 && ! F_23 ( V_58 , V_7 ,
V_60 , 0 ) )
return V_58 ;
return V_57 ;
}
static void F_25 ( struct V_61 * V_62 )
{
T_1 V_63 = 0 , V_14 = 0 ;
int V_64 = - 1 , V_65 ;
if ( F_26 ( V_66 , & V_63 , & V_14 ) )
return;
V_65 = ( V_63 & V_67 ) >> 4 ;
if ( ! ( V_63 & V_67 ) ) {
F_4 ( V_36 L_12 ) ;
V_65 = V_68 ;
V_63 = ( V_63 & ~ V_67 ) | ( V_68 << 4 ) ;
}
V_64 = F_24 ( V_64 , V_65 ) ;
if ( ( V_64 == V_65 ) &&
( V_69 != V_70 ) )
V_69 = V_70 ;
V_63 = ( V_63 & ~ V_71 ) | V_72 ;
F_20 ( V_66 , V_63 , V_14 ) ;
}
static T_1 F_27 ( unsigned int V_11 , T_1 V_73 , T_1 V_63 , T_1 V_14 ,
unsigned int V_8 , unsigned int V_37 )
{
T_1 V_74 = 0 , V_56 = 0 ;
if ( V_25 . V_26 ) {
if ( ! V_37 ) {
V_74 = F_28 ( V_8 ) ;
} else {
T_1 V_63 , V_14 ;
if ( F_7 ( V_11 , F_29 ( V_8 ) , & V_63 , & V_14 ) )
return V_74 ;
if ( ! ( V_63 & V_75 ) )
return V_74 ;
if ( ! F_7 ( V_11 , F_28 ( V_8 ) , & V_63 , & V_14 ) &&
( V_63 & V_76 ) )
V_74 = F_30 ( V_8 , V_37 - 1 ) ;
}
return V_74 ;
}
switch ( V_37 ) {
case 0 :
V_74 = V_77 . V_78 ( V_8 ) ;
break;
case 1 :
V_56 = ( ( V_63 & V_76 ) >> 21 ) ;
if ( V_56 )
V_74 = V_79 + V_56 ;
break;
default:
V_74 = ++ V_73 ;
}
return V_74 ;
}
static int
F_31 ( unsigned int V_8 , unsigned int V_37 , T_1 V_74 ,
int V_56 , T_1 V_80 )
{
unsigned int V_11 = F_6 () ;
T_1 V_81 , V_82 , V_83 ;
struct V_27 V_28 ;
int V_58 ;
if ( ! V_37 )
F_32 ( V_84 , V_11 ) |= ( 1 << V_8 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_11 = V_11 ;
V_28 . V_8 = V_8 ;
V_28 . V_37 = V_37 ;
V_28 . V_29 = V_74 ;
V_28 . V_49 = F_15 ( V_8 , V_80 ) ;
if ( ! V_28 . V_49 )
goto V_50;
V_28 . V_53 = 1 ;
if ( ! V_25 . V_26 ) {
V_58 = ( V_80 & V_35 ) >> 20 ;
goto V_85;
}
V_83 = F_29 ( V_8 ) ;
if ( ! F_26 ( V_83 , & V_81 , & V_82 ) ) {
V_82 |= F_16 ( 0 ) ;
V_82 &= ~ F_16 ( 2 ) ;
if ( ( V_81 & F_16 ( 5 ) ) && ! ( ( V_82 >> 5 ) & 0x3 ) )
V_82 |= F_16 ( 5 ) ;
F_20 ( V_83 , V_81 , V_82 ) ;
}
if ( F_26 ( V_66 , & V_81 , & V_82 ) )
goto V_86;
V_58 = ( V_81 & V_87 ) >> 12 ;
V_85:
V_56 = F_22 ( V_56 , V_58 ) ;
if ( ( V_56 == V_58 ) && ( V_88 != V_89 ) )
V_88 = V_89 ;
V_50:
F_21 ( & V_28 , V_56 ) ;
V_86:
return V_56 ;
}
void F_33 ( struct V_61 * V_62 )
{
T_1 V_63 = 0 , V_14 = 0 , V_29 = 0 ;
unsigned int V_8 , V_37 , V_11 = F_6 () ;
int V_56 = - 1 ;
for ( V_8 = 0 ; V_8 < V_90 . V_91 ; ++ V_8 ) {
if ( V_25 . V_26 )
F_5 ( V_8 ) ;
for ( V_37 = 0 ; V_37 < V_92 ; ++ V_37 ) {
V_29 = F_27 ( V_11 , V_29 , V_63 , V_14 , V_8 , V_37 ) ;
if ( ! V_29 )
break;
if ( F_26 ( V_29 , & V_63 , & V_14 ) )
break;
if ( ! ( V_14 & V_93 ) )
continue;
if ( ! ( V_14 & V_94 ) ||
( V_14 & V_95 ) )
continue;
V_56 = F_31 ( V_8 , V_37 , V_29 , V_56 , V_14 ) ;
}
}
if ( V_25 . V_96 )
F_25 ( V_62 ) ;
}
int F_34 ( T_2 V_97 , T_3 V_98 , T_4 V_99 , T_2 * V_100 )
{
T_2 V_101 , V_102 , V_103 ;
T_2 V_104 = V_97 ;
T_1 V_105 ;
T_4 V_106 , V_107 , V_108 , V_109 ;
T_4 V_110 , V_111 , V_112 ;
T_4 V_113 , V_114 ;
T_4 V_115 , V_116 ;
T_4 V_117 , V_118 = 0 ;
T_4 V_119 , V_120 = 0 ;
bool V_121 = false ;
if ( F_35 ( V_98 , 0 , 0x1B4 , V_99 , & V_105 ) )
goto V_122;
if ( V_105 & F_16 ( 0 ) ) {
T_2 V_123 = ( V_105 & F_36 ( 31 , 20 ) ) << 8 ;
if ( V_97 >= V_123 ) {
V_104 -= V_123 ;
V_118 = 1 ;
}
}
if ( F_35 ( V_98 , 0 , 0x110 + ( 8 * V_118 ) , V_99 , & V_105 ) )
goto V_122;
if ( ! ( V_105 & F_16 ( 0 ) ) ) {
F_4 ( L_13 ,
V_124 , V_105 ) ;
goto V_122;
}
V_117 = V_105 & F_16 ( 1 ) ;
V_111 = ( V_105 >> 4 ) & 0xF ;
V_113 = ( V_105 >> 8 ) & 0x7 ;
V_101 = ( V_105 & F_36 ( 31 , 12 ) ) << 16 ;
if ( V_113 > 3 ) {
F_4 ( L_14 ,
V_124 , V_113 ) ;
goto V_122;
}
if ( F_35 ( V_98 , 0 , 0x114 + ( 8 * V_118 ) , V_99 , & V_105 ) )
goto V_122;
V_112 = ( V_105 >> 8 ) & 0x1 ;
V_110 = ( V_105 >> 10 ) & 0x3 ;
V_102 = ( ( V_105 & F_36 ( 31 , 12 ) ) << 16 ) | F_36 ( 27 , 0 ) ;
V_114 = V_113 + 8 ;
switch ( V_111 ) {
case 0 : V_111 = 0 ; break;
case 1 : V_111 = 1 ; break;
case 3 : V_111 = 2 ; break;
case 5 : V_111 = 3 ; break;
case 7 : V_111 = 4 ; break;
case 8 : V_111 = 1 ;
V_121 = true ;
break;
default:
F_4 ( L_15 ,
V_124 , V_111 ) ;
goto V_122;
}
V_115 = V_111 ;
if ( V_110 > 2 ) {
F_4 ( L_16 ,
V_124 , V_110 ) ;
goto V_122;
}
V_115 += V_110 ;
V_115 += V_112 ;
if ( V_115 > 4 ) {
F_4 ( L_17 ,
V_124 , V_115 ) ;
goto V_122;
}
if ( V_115 > 0 ) {
T_2 V_125 , V_126 , V_127 ;
T_4 V_128 , V_129 , V_130 ;
if ( F_35 ( V_98 , 0 , 0x50 , V_99 , & V_105 ) )
goto V_122;
V_130 = ( V_105 >> 8 ) & 0xFF ;
V_128 = 0 ;
if ( V_111 ) {
V_128 = V_111 ;
V_119 = ( 1 << V_128 ) - 1 ;
V_120 = V_130 & V_119 ;
}
V_129 = V_128 ;
if ( V_110 || V_112 )
if ( F_35 ( V_98 , 1 , 0x208 , V_99 , & V_105 ) )
goto V_122;
if ( V_110 ) {
V_129 = V_128 + V_110 ;
V_106 = ( V_105 >> 24 ) & 0xF ;
V_107 = ( V_105 >> 8 ) & 0xFF ;
V_120 |= ( ( V_130 & V_107 ) >> V_106 ) << V_128 ;
}
if ( V_112 ) {
V_108 = ( V_105 >> 28 ) & 0xF ;
V_109 = ( V_105 >> 16 ) & 0xFF ;
V_120 |= ( ( V_130 & V_109 ) >> V_108 ) << V_129 ;
}
V_127 = V_104 & F_36 ( V_114 - 1 , 0 ) ;
V_126 = ( V_120 << V_114 ) ;
V_125 = ( V_104 & F_36 ( 63 , V_114 ) ) << V_115 ;
V_104 = V_125 | V_126 | V_127 ;
}
V_104 += V_101 ;
if ( V_117 ) {
if ( F_35 ( V_98 , 0 , 0x104 , V_99 , & V_105 ) )
goto V_122;
V_103 = V_105 & F_37 ( 31 , 24 ) ;
if ( V_104 >= V_103 )
V_104 += ( F_38 ( 32 ) - V_103 ) ;
}
if ( V_121 ) {
V_116 = ( V_104 >> 12 ) ^
( V_104 >> 18 ) ^
( V_104 >> 21 ) ^
( V_104 >> 30 ) ^
V_120 ;
V_116 &= F_16 ( 0 ) ;
if ( V_116 != ( ( V_104 >> V_114 ) & F_16 ( 0 ) ) )
V_104 ^= F_16 ( V_114 ) ;
}
if ( V_104 > V_102 )
goto V_122;
* V_100 = V_104 ;
return 0 ;
V_122:
return - V_131 ;
}
static void
F_39 ( unsigned int V_8 , bool V_132 , bool V_133 , T_2 V_78 )
{
T_1 V_134 = V_77 . V_135 ( V_8 ) ;
T_1 V_136 = V_77 . V_74 ( V_8 ) ;
struct V_137 V_138 ;
T_2 V_135 ;
F_40 ( V_132 && V_133 ) ;
if ( V_132 && V_25 . V_26 ) {
V_134 = F_41 ( V_8 ) ;
V_136 = F_42 ( V_8 ) ;
}
F_43 ( V_134 , V_135 ) ;
if ( ! ( V_135 & V_139 ) )
return;
F_44 ( & V_138 ) ;
V_138 . V_135 = V_135 ;
V_138 . V_8 = V_8 ;
V_138 . V_140 = F_45 () ;
if ( V_133 )
V_138 . V_78 = V_78 ;
if ( V_138 . V_135 & V_141 ) {
F_43 ( V_136 , V_138 . V_74 ) ;
if ( V_25 . V_26 ) {
T_4 V_142 = ( V_138 . V_74 >> 56 ) & 0x3f ;
V_138 . V_74 &= F_36 ( 55 , V_142 ) ;
}
}
if ( V_25 . V_26 ) {
F_43 ( F_8 ( V_8 ) , V_138 . V_143 ) ;
if ( V_138 . V_135 & V_144 )
F_43 ( F_46 ( V_8 ) , V_138 . V_145 ) ;
}
F_47 ( & V_138 ) ;
F_48 ( V_134 , 0 ) ;
}
static inline void F_49 ( void )
{
F_50 ( V_146 ) ;
V_69 () ;
}
T_5 T_6 void T_7 F_51 ( void )
{
F_52 () ;
F_49 () ;
F_53 () ;
}
T_5 T_6 void T_7 F_54 ( void )
{
F_52 () ;
F_55 ( V_7 ) ;
F_49 () ;
F_56 ( V_7 ) ;
F_53 () ;
}
static void V_70 ( void )
{
unsigned int V_8 ;
T_1 V_134 ;
T_2 V_135 ;
for ( V_8 = 0 ; V_8 < V_90 . V_91 ; ++ V_8 ) {
V_134 = ( V_25 . V_26 ) ? F_41 ( V_8 )
: V_77 . V_135 ( V_8 ) ;
F_43 ( V_134 , V_135 ) ;
if ( ! ( V_135 & V_139 ) ||
! ( V_135 & V_147 ) )
continue;
F_39 ( V_8 , true , false , 0 ) ;
break;
}
}
static void V_89 ( void )
{
T_1 V_63 = 0 , V_14 = 0 , V_29 = 0 ;
unsigned int V_8 , V_37 , V_11 = F_6 () ;
struct V_39 V_40 ;
for ( V_8 = 0 ; V_8 < V_90 . V_91 ; ++ V_8 ) {
if ( ! ( F_32 ( V_84 , V_11 ) & ( 1 << V_8 ) ) )
continue;
for ( V_37 = 0 ; V_37 < V_92 ; ++ V_37 ) {
V_29 = F_27 ( V_11 , V_29 , V_63 , V_14 , V_8 , V_37 ) ;
if ( ! V_29 )
break;
if ( F_26 ( V_29 , & V_63 , & V_14 ) )
break;
if ( ! ( V_14 & V_93 ) ) {
if ( V_37 )
continue;
else
break;
}
if ( ! ( V_14 & V_94 ) ||
( V_14 & V_95 ) )
continue;
if ( V_14 & V_45 )
goto log;
}
}
return;
log:
F_39 ( V_8 , false , true , ( ( T_2 ) V_14 << 32 ) | V_63 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_28 = & F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 [ V_37 ] ;
F_18 ( & V_40 ) ;
}
static T_8
F_57 ( struct V_27 * V_28 , const char * V_150 , T_9 V_151 )
{
struct V_39 V_40 ;
unsigned long V_58 ;
if ( ! V_28 -> V_49 )
return - V_131 ;
if ( F_58 ( V_150 , 0 , & V_58 ) < 0 )
return - V_131 ;
V_28 -> V_53 = ! ! V_58 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_28 = V_28 ;
F_59 ( V_28 -> V_11 , F_18 , & V_40 , 1 ) ;
return V_151 ;
}
static T_8
F_60 ( struct V_27 * V_28 , const char * V_150 , T_9 V_151 )
{
struct V_39 V_40 ;
unsigned long V_58 ;
if ( F_58 ( V_150 , 0 , & V_58 ) < 0 )
return - V_131 ;
if ( V_58 > V_42 )
V_58 = V_42 ;
if ( V_58 < 1 )
V_58 = 1 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_46 = V_28 -> V_41 ;
V_28 -> V_41 = V_58 ;
V_40 . V_28 = V_28 ;
F_59 ( V_28 -> V_11 , F_18 , & V_40 , 1 ) ;
return V_151 ;
}
static T_8 F_61 ( struct V_27 * V_28 , char * V_150 )
{
T_1 V_32 , V_33 ;
F_62 ( V_28 -> V_11 , V_28 -> V_29 , & V_32 , & V_33 ) ;
return sprintf ( V_150 , L_18 , ( ( V_33 & V_42 ) -
( V_42 - V_28 -> V_41 ) ) ) ;
}
static T_8 F_63 ( struct V_152 * V_153 , struct V_154 * V_155 , char * V_150 )
{
struct V_27 * V_28 = F_64 ( V_153 ) ;
struct V_156 * V_157 = F_65 ( V_155 ) ;
T_8 V_158 ;
V_158 = V_157 -> F_63 ? V_157 -> F_63 ( V_28 , V_150 ) : - V_159 ;
return V_158 ;
}
static T_8 F_66 ( struct V_152 * V_153 , struct V_154 * V_155 ,
const char * V_150 , T_9 V_24 )
{
struct V_27 * V_28 = F_64 ( V_153 ) ;
struct V_156 * V_157 = F_65 ( V_155 ) ;
T_8 V_158 ;
V_158 = V_157 -> F_66 ? V_157 -> F_66 ( V_28 , V_150 , V_24 ) : - V_159 ;
return V_158 ;
}
static const char * F_67 ( unsigned int V_8 , struct V_27 * V_28 )
{
unsigned int V_21 ;
if ( ! V_25 . V_26 ) {
if ( V_28 && V_8 == 4 )
return F_14 ( V_28 ) ;
return V_160 [ V_8 ] ;
}
if ( ! V_19 [ V_8 ] . V_20 )
return NULL ;
V_21 = V_19 [ V_8 ] . V_20 -> V_21 ;
if ( V_28 && V_21 == V_161 ) {
if ( V_28 -> V_37 < F_11 ( V_162 ) )
return V_162 [ V_28 -> V_37 ] ;
return NULL ;
}
if ( V_19 [ V_8 ] . V_20 -> V_24 == 1 )
return F_1 ( V_21 ) ;
snprintf ( V_163 , V_164 ,
L_19 , F_1 ( V_21 ) ,
V_19 [ V_8 ] . V_23 ) ;
return V_163 ;
}
static int F_68 ( unsigned int V_11 , unsigned int V_8 ,
unsigned int V_37 , T_1 V_29 )
{
struct V_27 * V_28 = NULL ;
T_1 V_63 , V_14 ;
int V_165 ;
if ( ( V_8 >= V_90 . V_91 ) || ( V_37 >= V_92 ) )
return 0 ;
if ( F_7 ( V_11 , V_29 , & V_63 , & V_14 ) )
return 0 ;
if ( ! ( V_14 & V_93 ) ) {
if ( V_37 )
goto V_166;
else
return 0 ;
}
if ( ! ( V_14 & V_94 ) ||
( V_14 & V_95 ) )
goto V_166;
V_28 = F_69 ( sizeof( struct V_27 ) , V_167 ) ;
if ( ! V_28 )
return - V_168 ;
V_28 -> V_37 = V_37 ;
V_28 -> V_8 = V_8 ;
V_28 -> V_11 = V_11 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_53 = 0 ;
V_28 -> V_49 = F_15 ( V_8 , V_14 ) ;
V_28 -> V_41 = V_42 ;
if ( V_28 -> V_49 ) {
V_169 . V_170 [ 2 ] = & V_53 . V_155 ;
V_28 -> V_53 = 1 ;
} else {
V_169 . V_170 [ 2 ] = NULL ;
}
F_70 ( & V_28 -> V_171 ) ;
if ( F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 ) {
F_71 ( & V_28 -> V_171 ,
& F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 -> V_171 ) ;
} else {
F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 = V_28 ;
}
V_165 = F_72 ( & V_28 -> V_153 , & V_169 ,
F_32 ( V_148 , V_11 ) [ V_8 ] -> V_153 ,
F_67 ( V_8 , V_28 ) ) ;
if ( V_165 )
goto V_172;
V_166:
V_29 = F_27 ( V_11 , V_29 , V_63 , V_14 , V_8 , ++ V_37 ) ;
if ( ! V_29 )
return 0 ;
V_165 = F_68 ( V_11 , V_8 , V_37 , V_29 ) ;
if ( V_165 )
goto V_172;
if ( V_28 )
F_73 ( & V_28 -> V_153 , V_173 ) ;
return V_165 ;
V_172:
if ( V_28 ) {
F_74 ( & V_28 -> V_153 ) ;
F_75 ( & V_28 -> V_171 ) ;
F_76 ( V_28 ) ;
}
return V_165 ;
}
static int F_77 ( struct V_174 * V_28 )
{
struct V_175 * V_176 = & V_28 -> V_149 -> V_171 ;
struct V_27 * V_177 = NULL ;
struct V_27 * V_105 = NULL ;
int V_165 = 0 ;
V_165 = F_78 ( & V_28 -> V_149 -> V_153 , V_28 -> V_153 , V_28 -> V_149 -> V_153 . V_5 ) ;
if ( V_165 )
return V_165 ;
F_79 (pos, tmp, head, miscj) {
V_165 = F_78 ( & V_177 -> V_153 , V_28 -> V_153 , V_177 -> V_153 . V_5 ) ;
if ( V_165 ) {
F_80 (pos, tmp, head, miscj)
F_81 ( & V_177 -> V_153 ) ;
return V_165 ;
}
}
return V_165 ;
}
static int F_82 ( unsigned int V_11 , unsigned int V_8 )
{
struct V_178 * V_179 = F_32 ( V_180 , V_11 ) ;
struct V_181 * V_182 = NULL ;
struct V_174 * V_28 = NULL ;
const char * V_5 = F_67 ( V_8 , NULL ) ;
int V_165 = 0 ;
if ( ! V_179 )
return - V_183 ;
if ( F_13 ( V_8 ) ) {
V_182 = F_83 ( F_84 ( V_11 ) ) ;
if ( V_182 && V_182 -> V_184 ) {
V_28 = V_182 -> V_184 ;
V_165 = F_78 ( V_28 -> V_153 , & V_179 -> V_153 , V_5 ) ;
if ( V_165 )
goto V_86;
F_32 ( V_148 , V_11 ) [ V_8 ] = V_28 ;
F_85 ( & V_28 -> V_185 ) ;
V_165 = F_77 ( V_28 ) ;
goto V_86;
}
}
V_28 = F_69 ( sizeof( struct V_174 ) , V_167 ) ;
if ( ! V_28 ) {
V_165 = - V_168 ;
goto V_86;
}
V_28 -> V_153 = F_86 ( V_5 , & V_179 -> V_153 ) ;
if ( ! V_28 -> V_153 ) {
V_165 = - V_131 ;
goto V_172;
}
F_32 ( V_148 , V_11 ) [ V_8 ] = V_28 ;
if ( F_13 ( V_8 ) ) {
F_87 ( & V_28 -> V_185 , 1 ) ;
if ( V_182 ) {
F_88 ( V_182 -> V_184 ) ;
V_182 -> V_184 = V_28 ;
}
}
V_165 = F_68 ( V_11 , V_8 , 0 , V_77 . V_78 ( V_8 ) ) ;
if ( ! V_165 )
goto V_86;
V_172:
F_76 ( V_28 ) ;
V_86:
return V_165 ;
}
static void F_89 ( unsigned int V_11 ,
unsigned int V_8 )
{
struct V_27 * V_177 = NULL ;
struct V_27 * V_105 = NULL ;
struct V_174 * V_176 = F_32 ( V_148 , V_11 ) [ V_8 ] ;
if ( ! V_176 )
return;
F_79 (pos, tmp, &head->blocks->miscj, miscj) {
F_74 ( & V_177 -> V_153 ) ;
F_75 ( & V_177 -> V_171 ) ;
F_76 ( V_177 ) ;
}
F_76 ( F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 ) ;
F_32 ( V_148 , V_11 ) [ V_8 ] -> V_149 = NULL ;
}
static void F_90 ( struct V_174 * V_28 )
{
struct V_27 * V_177 = NULL ;
struct V_27 * V_105 = NULL ;
F_81 ( V_28 -> V_153 ) ;
F_79 (pos, tmp, &b->blocks->miscj, miscj)
F_81 ( & V_177 -> V_153 ) ;
}
static void F_91 ( unsigned int V_11 , int V_8 )
{
struct V_181 * V_182 ;
struct V_174 * V_28 ;
V_28 = F_32 ( V_148 , V_11 ) [ V_8 ] ;
if ( ! V_28 )
return;
if ( ! V_28 -> V_149 )
goto V_186;
if ( F_13 ( V_8 ) ) {
if ( ! F_92 ( & V_28 -> V_185 ) ) {
F_90 ( V_28 ) ;
F_32 ( V_148 , V_11 ) [ V_8 ] = NULL ;
return;
} else {
V_182 = F_83 ( F_84 ( V_11 ) ) ;
V_182 -> V_184 = NULL ;
}
}
F_89 ( V_11 , V_8 ) ;
V_186:
F_81 ( V_28 -> V_153 ) ;
F_74 ( V_28 -> V_153 ) ;
F_76 ( V_28 ) ;
F_32 ( V_148 , V_11 ) [ V_8 ] = NULL ;
}
int F_93 ( unsigned int V_11 )
{
unsigned int V_8 ;
if ( ! V_187 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_90 . V_91 ; ++ V_8 ) {
if ( ! ( F_32 ( V_84 , V_11 ) & ( 1 << V_8 ) ) )
continue;
F_91 ( V_11 , V_8 ) ;
}
F_76 ( F_32 ( V_148 , V_11 ) ) ;
F_32 ( V_148 , V_11 ) = NULL ;
return 0 ;
}
int F_94 ( unsigned int V_11 )
{
unsigned int V_8 ;
struct V_174 * * V_188 ;
int V_165 = 0 ;
if ( ! V_187 )
return 0 ;
V_188 = F_32 ( V_148 , V_11 ) ;
if ( V_188 )
return 0 ;
V_188 = F_69 ( sizeof( struct V_174 * ) * V_90 . V_91 ,
V_167 ) ;
if ( ! V_188 )
return - V_168 ;
F_32 ( V_148 , V_11 ) = V_188 ;
for ( V_8 = 0 ; V_8 < V_90 . V_91 ; ++ V_8 ) {
if ( ! ( F_32 ( V_84 , V_11 ) & ( 1 << V_8 ) ) )
continue;
V_165 = F_82 ( V_11 , V_8 ) ;
if ( V_165 )
goto V_165;
}
return V_165 ;
V_165:
F_93 ( V_11 ) ;
return V_165 ;
}
static T_10 int F_95 ( void )
{
unsigned V_189 = 0 ;
if ( V_88 == V_89 )
V_187 = true ;
F_96 (lcpu) {
int V_165 = F_94 ( V_189 ) ;
if ( V_165 )
return V_165 ;
}
return 0 ;
}
