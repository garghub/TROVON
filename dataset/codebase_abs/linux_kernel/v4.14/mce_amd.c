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
static void F_5 ( unsigned int V_8 , unsigned int V_9 )
{
unsigned int V_10 , V_11 ;
struct V_12 * V_13 ;
T_1 V_14 , V_15 ;
T_1 V_16 = F_6 ( V_8 ) ;
if ( ! F_7 ( V_16 , & V_15 , & V_14 ) ) {
V_14 |= F_8 ( 0 ) ;
if ( ( V_15 & F_8 ( 5 ) ) && ! ( ( V_14 >> 5 ) & 0x3 ) )
V_14 |= F_8 ( 5 ) ;
F_9 ( V_16 , V_15 , V_14 ) ;
}
if ( V_17 [ V_8 ] . V_18 )
return;
if ( F_10 ( V_9 , F_11 ( V_8 ) , & V_15 , & V_14 ) ) {
F_12 ( L_2 , V_8 ) ;
return;
}
V_11 = F_13 ( V_14 & V_19 ,
( V_14 & V_20 ) >> 16 ) ;
for ( V_10 = 0 ; V_10 < F_14 ( V_21 ) ; V_10 ++ ) {
V_13 = & V_21 [ V_10 ] ;
if ( V_11 == V_13 -> V_11 ) {
V_17 [ V_8 ] . V_18 = V_13 ;
V_17 [ V_8 ] . V_22 = V_15 ;
V_17 [ V_8 ] . V_23 = V_13 -> V_24 ++ ;
break;
}
}
}
static inline bool F_15 ( int V_8 )
{
if ( V_25 . V_26 )
return false ;
return ( V_8 == 4 ) ;
}
static const char * F_16 ( const struct V_27 * V_28 )
{
switch ( V_28 -> V_29 ) {
case 0x00000413 :
return L_3 ;
case 0xc0000408 :
return L_4 ;
case 0xc0000409 :
return L_5 ;
default:
F_17 ( 1 , L_6 , V_28 -> V_29 ) ;
return L_7 ;
}
}
static bool F_18 ( unsigned int V_8 , T_1 V_30 )
{
if ( V_8 == 4 )
return true ;
return V_30 & F_8 ( 28 ) ;
}
static int F_19 ( struct V_27 * V_28 , int V_31 , T_1 V_32 , T_1 V_33 )
{
int V_34 = ( V_33 & V_35 ) >> 20 ;
if ( V_31 < 0 ) {
F_4 ( V_36 L_8
L_9 , V_28 -> V_9 ,
V_28 -> V_8 , V_28 -> V_37 , V_28 -> V_29 , V_33 , V_32 ) ;
return 0 ;
}
if ( V_31 != V_34 ) {
if ( V_25 . V_26 )
return 0 ;
F_4 ( V_36 L_10
L_9 ,
V_28 -> V_9 , V_31 , V_28 -> V_8 , V_28 -> V_37 , V_28 -> V_29 , V_33 , V_32 ) ;
return 0 ;
}
return 1 ;
}
static void F_20 ( void * V_38 )
{
struct V_39 * V_40 = V_38 ;
T_1 V_33 , V_32 ;
F_21 ( V_40 -> V_28 -> V_29 , V_32 , V_33 ) ;
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
if ( F_19 ( V_40 -> V_28 , V_40 -> V_52 , V_32 , V_33 ) ) {
V_33 &= ~ V_35 ;
V_33 |= V_40 -> V_52 << 20 ;
}
}
if ( V_40 -> V_28 -> V_53 )
V_33 |= V_54 ;
V_50:
V_33 |= V_55 ;
F_9 ( V_40 -> V_28 -> V_29 , V_32 , V_33 ) ;
}
static void F_22 ( struct V_27 * V_28 , int V_56 )
{
struct V_39 V_40 = {
. V_28 = V_28 ,
. V_51 = 1 ,
. V_52 = V_56 ,
} ;
V_28 -> V_41 = V_42 ;
F_20 ( & V_40 ) ;
}
static int F_23 ( int V_57 , int V_58 )
{
if ( V_57 < 0 && ! F_24 ( V_58 , V_59 ,
V_60 , 0 ) )
return V_58 ;
return V_57 ;
}
static int F_25 ( int V_57 , int V_58 )
{
if ( V_57 < 0 && ! F_24 ( V_58 , V_7 ,
V_60 , 0 ) )
return V_58 ;
return V_57 ;
}
static void F_26 ( struct V_61 * V_62 )
{
T_1 V_15 = 0 , V_14 = 0 ;
int V_63 = - 1 , V_64 ;
if ( F_7 ( V_65 , & V_15 , & V_14 ) )
return;
V_64 = ( V_15 & V_66 ) >> 4 ;
if ( ! ( V_15 & V_66 ) ) {
F_4 ( V_36 L_11 ) ;
V_64 = V_67 ;
V_15 = ( V_15 & ~ V_66 ) | ( V_67 << 4 ) ;
}
V_63 = F_25 ( V_63 , V_64 ) ;
if ( ( V_63 == V_64 ) &&
( V_68 != V_69 ) )
V_68 = V_69 ;
V_15 = ( V_15 & ~ V_70 ) | V_71 ;
F_9 ( V_65 , V_15 , V_14 ) ;
}
static T_1 F_27 ( unsigned int V_9 , T_1 V_72 , T_1 V_15 , T_1 V_14 ,
unsigned int V_8 , unsigned int V_37 )
{
T_1 V_73 = 0 , V_56 = 0 ;
if ( V_25 . V_26 ) {
if ( ! V_37 ) {
V_73 = F_28 ( V_8 ) ;
} else {
T_1 V_15 , V_14 ;
if ( F_10 ( V_9 , F_6 ( V_8 ) , & V_15 , & V_14 ) )
return V_73 ;
if ( ! ( V_15 & V_74 ) )
return V_73 ;
if ( ! F_10 ( V_9 , F_28 ( V_8 ) , & V_15 , & V_14 ) &&
( V_15 & V_75 ) )
V_73 = F_29 ( V_8 , V_37 - 1 ) ;
}
return V_73 ;
}
switch ( V_37 ) {
case 0 :
V_73 = V_76 . V_77 ( V_8 ) ;
break;
case 1 :
V_56 = ( ( V_15 & V_75 ) >> 21 ) ;
if ( V_56 )
V_73 = V_78 + V_56 ;
break;
default:
V_73 = ++ V_72 ;
}
return V_73 ;
}
static int
F_30 ( unsigned int V_8 , unsigned int V_37 , T_1 V_73 ,
int V_56 , T_1 V_79 )
{
unsigned int V_9 = F_31 () ;
T_1 V_80 , V_81 ;
struct V_27 V_28 ;
int V_58 ;
if ( ! V_37 )
F_32 ( V_82 , V_9 ) |= ( 1 << V_8 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_9 = V_9 ;
V_28 . V_8 = V_8 ;
V_28 . V_37 = V_37 ;
V_28 . V_29 = V_73 ;
V_28 . V_49 = F_18 ( V_8 , V_79 ) ;
if ( ! V_28 . V_49 )
goto V_50;
V_28 . V_53 = 1 ;
if ( ! V_25 . V_26 ) {
V_58 = ( V_79 & V_35 ) >> 20 ;
goto V_83;
}
if ( F_7 ( V_65 , & V_80 , & V_81 ) )
goto V_84;
V_58 = ( V_80 & V_85 ) >> 12 ;
V_83:
V_56 = F_23 ( V_56 , V_58 ) ;
if ( ( V_56 == V_58 ) && ( V_86 != V_87 ) )
V_86 = V_87 ;
V_50:
F_22 ( & V_28 , V_56 ) ;
V_84:
return V_56 ;
}
void F_33 ( struct V_61 * V_62 )
{
T_1 V_15 = 0 , V_14 = 0 , V_29 = 0 ;
unsigned int V_8 , V_37 , V_9 = F_31 () ;
int V_56 = - 1 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( V_25 . V_26 )
F_5 ( V_8 , V_9 ) ;
for ( V_37 = 0 ; V_37 < V_90 ; ++ V_37 ) {
V_29 = F_27 ( V_9 , V_29 , V_15 , V_14 , V_8 , V_37 ) ;
if ( ! V_29 )
break;
if ( F_7 ( V_29 , & V_15 , & V_14 ) )
break;
if ( ! ( V_14 & V_91 ) )
continue;
if ( ! ( V_14 & V_92 ) ||
( V_14 & V_93 ) )
continue;
V_56 = F_30 ( V_8 , V_37 , V_29 , V_56 , V_14 ) ;
}
}
if ( V_25 . V_94 )
F_26 ( V_62 ) ;
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
if ( V_103 & F_8 ( 0 ) ) {
T_2 V_121 = ( V_103 & F_36 ( 31 , 20 ) ) << 8 ;
if ( V_95 >= V_121 ) {
V_102 -= V_121 ;
V_116 = 1 ;
}
}
if ( F_35 ( V_96 , 0 , 0x110 + ( 8 * V_116 ) , V_97 , & V_103 ) )
goto V_120;
if ( ! ( V_103 & F_8 ( 0 ) ) ) {
F_4 ( L_12 ,
V_122 , V_103 ) ;
goto V_120;
}
V_115 = V_103 & F_8 ( 1 ) ;
V_109 = ( V_103 >> 4 ) & 0xF ;
V_111 = ( V_103 >> 8 ) & 0x7 ;
V_99 = ( V_103 & F_36 ( 31 , 12 ) ) << 16 ;
if ( V_111 > 3 ) {
F_4 ( L_13 ,
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
F_4 ( L_14 ,
V_122 , V_109 ) ;
goto V_120;
}
V_113 = V_109 ;
if ( V_108 > 2 ) {
F_4 ( L_15 ,
V_122 , V_108 ) ;
goto V_120;
}
V_113 += V_108 ;
V_113 += V_110 ;
if ( V_113 > 4 ) {
F_4 ( L_16 ,
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
V_114 &= F_8 ( 0 ) ;
if ( V_114 != ( ( V_102 >> V_112 ) & F_8 ( 0 ) ) )
V_102 ^= F_8 ( V_112 ) ;
}
if ( V_102 > V_100 )
goto V_120;
* V_98 = V_102 ;
return 0 ;
V_120:
return - V_129 ;
}
static void F_39 ( unsigned int V_8 , T_2 V_130 , T_2 V_73 , T_2 V_77 )
{
struct V_131 V_132 ;
F_40 ( & V_132 ) ;
V_132 . V_130 = V_130 ;
V_132 . V_77 = V_77 ;
V_132 . V_8 = V_8 ;
V_132 . V_133 = F_41 () ;
if ( V_132 . V_130 & V_134 ) {
V_132 . V_73 = V_73 ;
if ( V_25 . V_26 ) {
T_4 V_135 = ( V_132 . V_73 >> 56 ) & 0x3f ;
V_132 . V_73 &= F_36 ( 55 , V_135 ) ;
}
}
if ( V_25 . V_26 ) {
F_42 ( F_11 ( V_8 ) , V_132 . V_136 ) ;
if ( V_132 . V_130 & V_137 )
F_42 ( F_43 ( V_8 ) , V_132 . V_138 ) ;
}
F_44 ( & V_132 ) ;
}
T_5 T_6 void T_7 F_45 ( void )
{
F_46 () ;
F_47 ( V_7 ) ;
F_48 ( V_139 ) ;
V_68 () ;
F_49 ( V_7 ) ;
F_50 () ;
}
static inline bool
F_51 ( unsigned int V_8 , T_1 V_140 , T_1 V_141 , T_2 V_77 )
{
T_2 V_130 , V_73 = 0 ;
F_42 ( V_140 , V_130 ) ;
if ( ! ( V_130 & V_142 ) )
return false ;
if ( V_130 & V_134 )
F_42 ( V_141 , V_73 ) ;
F_39 ( V_8 , V_130 , V_73 , V_77 ) ;
F_52 ( V_140 , 0 ) ;
return V_130 & V_143 ;
}
static void F_53 ( unsigned int V_8 )
{
bool V_144 ;
V_144 = F_51 ( V_8 , V_76 . V_130 ( V_8 ) ,
V_76 . V_73 ( V_8 ) , 0 ) ;
if ( ! V_25 . V_26 )
return;
if ( V_144 ) {
F_52 ( F_54 ( V_8 ) , 0 ) ;
return;
}
F_51 ( V_8 , F_54 ( V_8 ) ,
F_55 ( V_8 ) , 0 ) ;
}
static void V_69 ( void )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 )
F_53 ( V_8 ) ;
}
static void F_56 ( unsigned int V_8 , T_2 V_77 )
{
F_51 ( V_8 , V_76 . V_130 ( V_8 ) , V_76 . V_73 ( V_8 ) , V_77 ) ;
}
static void F_57 ( struct V_27 * V_37 )
{
struct V_39 V_40 ;
T_1 V_15 = 0 , V_14 = 0 ;
if ( ! V_37 )
return;
if ( F_7 ( V_37 -> V_29 , & V_15 , & V_14 ) )
return;
if ( ! ( V_14 & V_45 ) )
return;
F_56 ( V_37 -> V_8 , ( ( T_2 ) V_14 << 32 ) | V_15 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_28 = V_37 ;
F_20 ( & V_40 ) ;
}
static void V_87 ( void )
{
struct V_27 * V_145 = NULL , * V_37 = NULL , * V_103 = NULL ;
unsigned int V_8 , V_9 = F_31 () ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_9 ) & ( 1 << V_8 ) ) )
continue;
V_145 = F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 ;
if ( ! V_145 )
continue;
F_57 ( V_145 ) ;
F_58 (block, tmp, &first_block->miscj, miscj)
F_57 ( V_37 ) ;
}
}
static T_8
F_59 ( struct V_27 * V_28 , const char * V_148 , T_9 V_149 )
{
struct V_39 V_40 ;
unsigned long V_58 ;
if ( ! V_28 -> V_49 )
return - V_129 ;
if ( F_60 ( V_148 , 0 , & V_58 ) < 0 )
return - V_129 ;
V_28 -> V_53 = ! ! V_58 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_28 = V_28 ;
F_61 ( V_28 -> V_9 , F_20 , & V_40 , 1 ) ;
return V_149 ;
}
static T_8
F_62 ( struct V_27 * V_28 , const char * V_148 , T_9 V_149 )
{
struct V_39 V_40 ;
unsigned long V_58 ;
if ( F_60 ( V_148 , 0 , & V_58 ) < 0 )
return - V_129 ;
if ( V_58 > V_42 )
V_58 = V_42 ;
if ( V_58 < 1 )
V_58 = 1 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_46 = V_28 -> V_41 ;
V_28 -> V_41 = V_58 ;
V_40 . V_28 = V_28 ;
F_61 ( V_28 -> V_9 , F_20 , & V_40 , 1 ) ;
return V_149 ;
}
static T_8 F_63 ( struct V_27 * V_28 , char * V_148 )
{
T_1 V_32 , V_33 ;
F_64 ( V_28 -> V_9 , V_28 -> V_29 , & V_32 , & V_33 ) ;
return sprintf ( V_148 , L_17 , ( ( V_33 & V_42 ) -
( V_42 - V_28 -> V_41 ) ) ) ;
}
static T_8 F_65 ( struct V_150 * V_151 , struct V_152 * V_153 , char * V_148 )
{
struct V_27 * V_28 = F_66 ( V_151 ) ;
struct V_154 * V_155 = F_67 ( V_153 ) ;
T_8 V_156 ;
V_156 = V_155 -> F_65 ? V_155 -> F_65 ( V_28 , V_148 ) : - V_157 ;
return V_156 ;
}
static T_8 F_68 ( struct V_150 * V_151 , struct V_152 * V_153 ,
const char * V_148 , T_9 V_24 )
{
struct V_27 * V_28 = F_66 ( V_151 ) ;
struct V_154 * V_155 = F_67 ( V_153 ) ;
T_8 V_156 ;
V_156 = V_155 -> F_68 ? V_155 -> F_68 ( V_28 , V_148 , V_24 ) : - V_157 ;
return V_156 ;
}
static const char * F_69 ( unsigned int V_8 , struct V_27 * V_28 )
{
unsigned int V_158 ;
if ( ! V_25 . V_26 ) {
if ( V_28 && V_8 == 4 )
return F_16 ( V_28 ) ;
return V_159 [ V_8 ] ;
}
if ( ! V_17 [ V_8 ] . V_18 )
return NULL ;
V_158 = V_17 [ V_8 ] . V_18 -> V_158 ;
if ( V_28 && V_158 == V_160 ) {
if ( V_28 -> V_37 < F_14 ( V_161 ) )
return V_161 [ V_28 -> V_37 ] ;
return NULL ;
}
if ( V_17 [ V_8 ] . V_18 -> V_24 == 1 )
return F_1 ( V_158 ) ;
snprintf ( V_162 , V_163 ,
L_18 , F_1 ( V_158 ) ,
V_17 [ V_8 ] . V_23 ) ;
return V_162 ;
}
static int F_70 ( unsigned int V_9 , unsigned int V_8 ,
unsigned int V_37 , T_1 V_29 )
{
struct V_27 * V_28 = NULL ;
T_1 V_15 , V_14 ;
int V_164 ;
if ( ( V_8 >= V_88 . V_89 ) || ( V_37 >= V_90 ) )
return 0 ;
if ( F_10 ( V_9 , V_29 , & V_15 , & V_14 ) )
return 0 ;
if ( ! ( V_14 & V_91 ) ) {
if ( V_37 )
goto V_165;
else
return 0 ;
}
if ( ! ( V_14 & V_92 ) ||
( V_14 & V_93 ) )
goto V_165;
V_28 = F_71 ( sizeof( struct V_27 ) , V_166 ) ;
if ( ! V_28 )
return - V_167 ;
V_28 -> V_37 = V_37 ;
V_28 -> V_8 = V_8 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_53 = 0 ;
V_28 -> V_49 = F_18 ( V_8 , V_14 ) ;
V_28 -> V_41 = V_42 ;
if ( V_28 -> V_49 ) {
V_168 . V_169 [ 2 ] = & V_53 . V_153 ;
V_28 -> V_53 = 1 ;
} else {
V_168 . V_169 [ 2 ] = NULL ;
}
F_72 ( & V_28 -> V_170 ) ;
if ( F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 ) {
F_73 ( & V_28 -> V_170 ,
& F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 -> V_170 ) ;
} else {
F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 = V_28 ;
}
V_164 = F_74 ( & V_28 -> V_151 , & V_168 ,
F_32 ( V_146 , V_9 ) [ V_8 ] -> V_151 ,
F_69 ( V_8 , V_28 ) ) ;
if ( V_164 )
goto V_171;
V_165:
V_29 = F_27 ( V_9 , V_29 , V_15 , V_14 , V_8 , ++ V_37 ) ;
if ( ! V_29 )
return 0 ;
V_164 = F_70 ( V_9 , V_8 , V_37 , V_29 ) ;
if ( V_164 )
goto V_171;
if ( V_28 )
F_75 ( & V_28 -> V_151 , V_172 ) ;
return V_164 ;
V_171:
if ( V_28 ) {
F_76 ( & V_28 -> V_151 ) ;
F_77 ( & V_28 -> V_170 ) ;
F_78 ( V_28 ) ;
}
return V_164 ;
}
static int F_79 ( struct V_173 * V_28 )
{
struct V_174 * V_175 = & V_28 -> V_147 -> V_170 ;
struct V_27 * V_176 = NULL ;
struct V_27 * V_103 = NULL ;
int V_164 = 0 ;
V_164 = F_80 ( & V_28 -> V_147 -> V_151 , V_28 -> V_151 , V_28 -> V_147 -> V_151 . V_5 ) ;
if ( V_164 )
return V_164 ;
F_58 (pos, tmp, head, miscj) {
V_164 = F_80 ( & V_176 -> V_151 , V_28 -> V_151 , V_176 -> V_151 . V_5 ) ;
if ( V_164 ) {
F_81 (pos, tmp, head, miscj)
F_82 ( & V_176 -> V_151 ) ;
return V_164 ;
}
}
return V_164 ;
}
static int F_83 ( unsigned int V_9 , unsigned int V_8 )
{
struct V_177 * V_178 = F_32 ( V_179 , V_9 ) ;
struct V_180 * V_181 = NULL ;
struct V_173 * V_28 = NULL ;
const char * V_5 = F_69 ( V_8 , NULL ) ;
int V_164 = 0 ;
if ( ! V_178 )
return - V_182 ;
if ( F_15 ( V_8 ) ) {
V_181 = F_84 ( F_85 ( V_9 ) ) ;
if ( V_181 && V_181 -> V_183 ) {
V_28 = V_181 -> V_183 ;
V_164 = F_80 ( V_28 -> V_151 , & V_178 -> V_151 , V_5 ) ;
if ( V_164 )
goto V_84;
F_32 ( V_146 , V_9 ) [ V_8 ] = V_28 ;
F_86 ( & V_28 -> V_184 ) ;
V_164 = F_79 ( V_28 ) ;
goto V_84;
}
}
V_28 = F_71 ( sizeof( struct V_173 ) , V_166 ) ;
if ( ! V_28 ) {
V_164 = - V_167 ;
goto V_84;
}
V_28 -> V_151 = F_87 ( V_5 , & V_178 -> V_151 ) ;
if ( ! V_28 -> V_151 ) {
V_164 = - V_129 ;
goto V_171;
}
F_32 ( V_146 , V_9 ) [ V_8 ] = V_28 ;
if ( F_15 ( V_8 ) ) {
F_88 ( & V_28 -> V_184 , 1 ) ;
if ( V_181 ) {
F_89 ( V_181 -> V_183 ) ;
V_181 -> V_183 = V_28 ;
}
}
V_164 = F_70 ( V_9 , V_8 , 0 , V_76 . V_77 ( V_8 ) ) ;
if ( ! V_164 )
goto V_84;
V_171:
F_78 ( V_28 ) ;
V_84:
return V_164 ;
}
static void F_90 ( unsigned int V_9 ,
unsigned int V_8 )
{
struct V_27 * V_176 = NULL ;
struct V_27 * V_103 = NULL ;
struct V_173 * V_175 = F_32 ( V_146 , V_9 ) [ V_8 ] ;
if ( ! V_175 )
return;
F_58 (pos, tmp, &head->blocks->miscj, miscj) {
F_76 ( & V_176 -> V_151 ) ;
F_77 ( & V_176 -> V_170 ) ;
F_78 ( V_176 ) ;
}
F_78 ( F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 ) ;
F_32 ( V_146 , V_9 ) [ V_8 ] -> V_147 = NULL ;
}
static void F_91 ( struct V_173 * V_28 )
{
struct V_27 * V_176 = NULL ;
struct V_27 * V_103 = NULL ;
F_82 ( V_28 -> V_151 ) ;
F_58 (pos, tmp, &b->blocks->miscj, miscj)
F_82 ( & V_176 -> V_151 ) ;
}
static void F_92 ( unsigned int V_9 , int V_8 )
{
struct V_180 * V_181 ;
struct V_173 * V_28 ;
V_28 = F_32 ( V_146 , V_9 ) [ V_8 ] ;
if ( ! V_28 )
return;
if ( ! V_28 -> V_147 )
goto V_185;
if ( F_15 ( V_8 ) ) {
if ( ! F_93 ( & V_28 -> V_184 ) ) {
F_91 ( V_28 ) ;
F_32 ( V_146 , V_9 ) [ V_8 ] = NULL ;
return;
} else {
V_181 = F_84 ( F_85 ( V_9 ) ) ;
V_181 -> V_183 = NULL ;
}
}
F_90 ( V_9 , V_8 ) ;
V_185:
F_82 ( V_28 -> V_151 ) ;
F_76 ( V_28 -> V_151 ) ;
F_78 ( V_28 ) ;
F_32 ( V_146 , V_9 ) [ V_8 ] = NULL ;
}
int F_94 ( unsigned int V_9 )
{
unsigned int V_8 ;
if ( ! V_186 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_9 ) & ( 1 << V_8 ) ) )
continue;
F_92 ( V_9 , V_8 ) ;
}
F_78 ( F_32 ( V_146 , V_9 ) ) ;
F_32 ( V_146 , V_9 ) = NULL ;
return 0 ;
}
int F_95 ( unsigned int V_9 )
{
unsigned int V_8 ;
struct V_173 * * V_187 ;
int V_164 = 0 ;
if ( ! V_186 )
return 0 ;
V_187 = F_32 ( V_146 , V_9 ) ;
if ( V_187 )
return 0 ;
V_187 = F_71 ( sizeof( struct V_173 * ) * V_88 . V_89 ,
V_166 ) ;
if ( ! V_187 )
return - V_167 ;
F_32 ( V_146 , V_9 ) = V_187 ;
for ( V_8 = 0 ; V_8 < V_88 . V_89 ; ++ V_8 ) {
if ( ! ( F_32 ( V_82 , V_9 ) & ( 1 << V_8 ) ) )
continue;
V_164 = F_83 ( V_9 , V_8 ) ;
if ( V_164 )
goto V_164;
}
return V_164 ;
V_164:
F_94 ( V_9 ) ;
return V_164 ;
}
static T_10 int F_96 ( void )
{
unsigned V_188 = 0 ;
if ( V_86 == V_87 )
V_186 = true ;
F_97 (lcpu) {
int V_164 = F_95 ( V_188 ) ;
if ( V_164 )
return V_164 ;
}
return 0 ;
}
