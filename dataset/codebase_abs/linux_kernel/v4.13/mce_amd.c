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
if ( V_9 )
return;
if ( F_10 ( V_9 , F_11 ( V_8 ) , & V_15 , & V_14 ) ) {
F_12 ( L_2 , V_8 ) ;
return;
}
V_11 = F_13 ( V_14 & V_17 ,
( V_14 & V_18 ) >> 16 ) ;
for ( V_10 = 0 ; V_10 < F_14 ( V_19 ) ; V_10 ++ ) {
V_13 = & V_19 [ V_10 ] ;
if ( V_11 == V_13 -> V_11 ) {
F_15 ( V_20 [ V_8 ] . V_21 ,
L_3 ,
F_1 ( V_13 -> V_22 ) ) ;
V_20 [ V_8 ] . V_21 = V_13 ;
V_20 [ V_8 ] . V_23 = V_15 ;
V_20 [ V_8 ] . V_24 = V_13 -> V_25 ++ ;
break;
}
}
}
static inline bool F_16 ( int V_8 )
{
if ( V_26 . V_27 )
return false ;
return ( V_8 == 4 ) ;
}
static const char * F_17 ( const struct V_28 * V_29 )
{
switch ( V_29 -> V_30 ) {
case 0x00000413 :
return L_4 ;
case 0xc0000408 :
return L_5 ;
case 0xc0000409 :
return L_6 ;
default:
F_15 ( 1 , L_7 , V_29 -> V_30 ) ;
return L_8 ;
}
}
static bool F_18 ( unsigned int V_8 , T_1 V_31 )
{
if ( V_8 == 4 )
return true ;
return V_31 & F_8 ( 28 ) ;
}
static int F_19 ( struct V_28 * V_29 , int V_32 , T_1 V_33 , T_1 V_34 )
{
int V_35 = ( V_34 & V_36 ) >> 20 ;
if ( V_32 < 0 ) {
F_4 ( V_37 L_9
L_10 , V_29 -> V_9 ,
V_29 -> V_8 , V_29 -> V_38 , V_29 -> V_30 , V_34 , V_33 ) ;
return 0 ;
}
if ( V_32 != V_35 ) {
if ( V_26 . V_27 )
return 0 ;
F_4 ( V_37 L_11
L_10 ,
V_29 -> V_9 , V_32 , V_29 -> V_8 , V_29 -> V_38 , V_29 -> V_30 , V_34 , V_33 ) ;
return 0 ;
}
return 1 ;
}
static void F_20 ( void * V_39 )
{
struct V_40 * V_41 = V_39 ;
T_1 V_34 , V_33 ;
F_21 ( V_41 -> V_29 -> V_30 , V_33 , V_34 ) ;
if ( V_41 -> V_29 -> V_42 < ( V_34 & V_43 ) )
V_41 -> V_44 = 1 ;
if ( V_41 -> V_44 ) {
V_34 =
( V_34 & ~ ( V_45 | V_46 ) ) |
( V_43 - V_41 -> V_29 -> V_42 ) ;
} else if ( V_41 -> V_47 ) {
int V_48 = ( V_34 & V_43 ) +
( V_41 -> V_47 - V_41 -> V_29 -> V_42 ) ;
V_34 = ( V_34 & ~ V_45 ) |
( V_48 & V_43 ) ;
}
V_34 &= ~ V_49 ;
if ( ! V_41 -> V_29 -> V_50 )
goto V_51;
if ( V_41 -> V_52 ) {
if ( F_19 ( V_41 -> V_29 , V_41 -> V_53 , V_33 , V_34 ) ) {
V_34 &= ~ V_36 ;
V_34 |= V_41 -> V_53 << 20 ;
}
}
if ( V_41 -> V_29 -> V_54 )
V_34 |= V_55 ;
V_51:
V_34 |= V_56 ;
F_9 ( V_41 -> V_29 -> V_30 , V_33 , V_34 ) ;
}
static void F_22 ( struct V_28 * V_29 , int V_57 )
{
struct V_40 V_41 = {
. V_29 = V_29 ,
. V_52 = 1 ,
. V_53 = V_57 ,
} ;
V_29 -> V_42 = V_43 ;
F_20 ( & V_41 ) ;
}
static int F_23 ( int V_58 , int V_59 )
{
if ( V_58 < 0 && ! F_24 ( V_59 , V_60 ,
V_61 , 0 ) )
return V_59 ;
return V_58 ;
}
static int F_25 ( int V_58 , int V_59 )
{
if ( V_58 < 0 && ! F_24 ( V_59 , V_7 ,
V_61 , 0 ) )
return V_59 ;
return V_58 ;
}
static void F_26 ( struct V_62 * V_63 )
{
T_1 V_15 = 0 , V_14 = 0 ;
int V_64 = - 1 , V_65 ;
if ( F_7 ( V_66 , & V_15 , & V_14 ) )
return;
V_65 = ( V_15 & V_67 ) >> 4 ;
if ( ! ( V_15 & V_67 ) ) {
F_4 ( V_37 L_12 ) ;
V_65 = V_68 ;
V_15 = ( V_15 & ~ V_67 ) | ( V_68 << 4 ) ;
}
V_64 = F_25 ( V_64 , V_65 ) ;
if ( ( V_64 == V_65 ) &&
( V_69 != V_70 ) )
V_69 = V_70 ;
V_15 = ( V_15 & ~ V_71 ) | V_72 ;
F_9 ( V_66 , V_15 , V_14 ) ;
}
static T_1 F_27 ( unsigned int V_9 , T_1 V_73 , T_1 V_15 , T_1 V_14 ,
unsigned int V_8 , unsigned int V_38 )
{
T_1 V_74 = 0 , V_57 = 0 ;
if ( V_26 . V_27 ) {
if ( ! V_38 ) {
V_74 = F_28 ( V_8 ) ;
} else {
T_1 V_15 , V_14 ;
if ( F_10 ( V_9 , F_6 ( V_8 ) , & V_15 , & V_14 ) )
return V_74 ;
if ( ! ( V_15 & V_75 ) )
return V_74 ;
if ( ! F_10 ( V_9 , F_28 ( V_8 ) , & V_15 , & V_14 ) &&
( V_15 & V_76 ) )
V_74 = F_29 ( V_8 , V_38 - 1 ) ;
}
return V_74 ;
}
switch ( V_38 ) {
case 0 :
V_74 = V_77 . V_78 ( V_8 ) ;
break;
case 1 :
V_57 = ( ( V_15 & V_76 ) >> 21 ) ;
if ( V_57 )
V_74 = V_79 + V_57 ;
break;
default:
V_74 = ++ V_73 ;
}
return V_74 ;
}
static int
F_30 ( unsigned int V_8 , unsigned int V_38 , T_1 V_74 ,
int V_57 , T_1 V_80 )
{
unsigned int V_9 = F_31 () ;
T_1 V_81 , V_82 ;
struct V_28 V_29 ;
int V_59 ;
if ( ! V_38 )
F_32 ( V_83 , V_9 ) |= ( 1 << V_8 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_9 = V_9 ;
V_29 . V_8 = V_8 ;
V_29 . V_38 = V_38 ;
V_29 . V_30 = V_74 ;
V_29 . V_50 = F_18 ( V_8 , V_80 ) ;
if ( ! V_29 . V_50 )
goto V_51;
V_29 . V_54 = 1 ;
if ( ! V_26 . V_27 ) {
V_59 = ( V_80 & V_36 ) >> 20 ;
goto V_84;
}
if ( F_7 ( V_66 , & V_81 , & V_82 ) )
goto V_85;
V_59 = ( V_81 & V_86 ) >> 12 ;
V_84:
V_57 = F_23 ( V_57 , V_59 ) ;
if ( ( V_57 == V_59 ) && ( V_87 != V_88 ) )
V_87 = V_88 ;
V_51:
F_22 ( & V_29 , V_57 ) ;
V_85:
return V_57 ;
}
void F_33 ( struct V_62 * V_63 )
{
T_1 V_15 = 0 , V_14 = 0 , V_30 = 0 ;
unsigned int V_8 , V_38 , V_9 = F_31 () ;
int V_57 = - 1 ;
for ( V_8 = 0 ; V_8 < V_89 . V_90 ; ++ V_8 ) {
if ( V_26 . V_27 )
F_5 ( V_8 , V_9 ) ;
for ( V_38 = 0 ; V_38 < V_91 ; ++ V_38 ) {
V_30 = F_27 ( V_9 , V_30 , V_15 , V_14 , V_8 , V_38 ) ;
if ( ! V_30 )
break;
if ( F_7 ( V_30 , & V_15 , & V_14 ) )
break;
if ( ! ( V_14 & V_92 ) )
continue;
if ( ! ( V_14 & V_93 ) ||
( V_14 & V_94 ) )
continue;
V_57 = F_30 ( V_8 , V_38 , V_30 , V_57 , V_14 ) ;
}
}
if ( V_26 . V_95 )
F_26 ( V_63 ) ;
}
int F_34 ( T_2 V_96 , T_3 V_97 , T_4 V_98 , T_2 * V_99 )
{
T_2 V_100 , V_101 , V_102 ;
T_2 V_103 = V_96 ;
T_1 V_104 ;
T_4 V_105 , V_106 , V_107 , V_108 ;
T_4 V_109 , V_110 , V_111 ;
T_4 V_112 , V_113 ;
T_4 V_114 , V_115 ;
T_4 V_116 , V_117 = 0 ;
T_4 V_118 , V_119 = 0 ;
bool V_120 = false ;
if ( F_35 ( V_97 , 0 , 0x1B4 , V_98 , & V_104 ) )
goto V_121;
if ( V_104 & F_8 ( 0 ) ) {
T_2 V_122 = ( V_104 & F_36 ( 31 , 20 ) ) << 8 ;
if ( V_96 >= V_122 ) {
V_103 -= V_122 ;
V_117 = 1 ;
}
}
if ( F_35 ( V_97 , 0 , 0x110 + ( 8 * V_117 ) , V_98 , & V_104 ) )
goto V_121;
if ( ! ( V_104 & F_8 ( 0 ) ) ) {
F_4 ( L_13 ,
V_123 , V_104 ) ;
goto V_121;
}
V_116 = V_104 & F_8 ( 1 ) ;
V_110 = ( V_104 >> 4 ) & 0xF ;
V_112 = ( V_104 >> 8 ) & 0x7 ;
V_100 = ( V_104 & F_36 ( 31 , 12 ) ) << 16 ;
if ( V_112 > 3 ) {
F_4 ( L_14 ,
V_123 , V_112 ) ;
goto V_121;
}
if ( F_35 ( V_97 , 0 , 0x114 + ( 8 * V_117 ) , V_98 , & V_104 ) )
goto V_121;
V_111 = ( V_104 >> 8 ) & 0x1 ;
V_109 = ( V_104 >> 10 ) & 0x3 ;
V_101 = ( ( V_104 & F_36 ( 31 , 12 ) ) << 16 ) | F_36 ( 27 , 0 ) ;
V_113 = V_112 + 8 ;
switch ( V_110 ) {
case 0 : V_110 = 0 ; break;
case 1 : V_110 = 1 ; break;
case 3 : V_110 = 2 ; break;
case 5 : V_110 = 3 ; break;
case 7 : V_110 = 4 ; break;
case 8 : V_110 = 1 ;
V_120 = true ;
break;
default:
F_4 ( L_15 ,
V_123 , V_110 ) ;
goto V_121;
}
V_114 = V_110 ;
if ( V_109 > 2 ) {
F_4 ( L_16 ,
V_123 , V_109 ) ;
goto V_121;
}
V_114 += V_109 ;
V_114 += V_111 ;
if ( V_114 > 4 ) {
F_4 ( L_17 ,
V_123 , V_114 ) ;
goto V_121;
}
if ( V_114 > 0 ) {
T_2 V_124 , V_125 , V_126 ;
T_4 V_127 , V_128 , V_129 ;
if ( F_35 ( V_97 , 0 , 0x50 , V_98 , & V_104 ) )
goto V_121;
V_129 = ( V_104 >> 8 ) & 0xFF ;
V_127 = 0 ;
if ( V_110 ) {
V_127 = V_110 ;
V_118 = ( 1 << V_127 ) - 1 ;
V_119 = V_129 & V_118 ;
}
V_128 = V_127 ;
if ( V_109 || V_111 )
if ( F_35 ( V_97 , 1 , 0x208 , V_98 , & V_104 ) )
goto V_121;
if ( V_109 ) {
V_128 = V_127 + V_109 ;
V_105 = ( V_104 >> 24 ) & 0xF ;
V_106 = ( V_104 >> 8 ) & 0xFF ;
V_119 |= ( ( V_129 & V_106 ) >> V_105 ) << V_127 ;
}
if ( V_111 ) {
V_107 = ( V_104 >> 28 ) & 0xF ;
V_108 = ( V_104 >> 16 ) & 0xFF ;
V_119 |= ( ( V_129 & V_108 ) >> V_107 ) << V_128 ;
}
V_126 = V_103 & F_36 ( V_113 - 1 , 0 ) ;
V_125 = ( V_119 << V_113 ) ;
V_124 = ( V_103 & F_36 ( 63 , V_113 ) ) << V_114 ;
V_103 = V_124 | V_125 | V_126 ;
}
V_103 += V_100 ;
if ( V_116 ) {
if ( F_35 ( V_97 , 0 , 0x104 , V_98 , & V_104 ) )
goto V_121;
V_102 = V_104 & F_37 ( 31 , 24 ) ;
if ( V_103 >= V_102 )
V_103 += ( F_38 ( 32 ) - V_102 ) ;
}
if ( V_120 ) {
V_115 = ( V_103 >> 12 ) ^
( V_103 >> 18 ) ^
( V_103 >> 21 ) ^
( V_103 >> 30 ) ^
V_119 ;
V_115 &= F_8 ( 0 ) ;
if ( V_115 != ( ( V_103 >> V_113 ) & F_8 ( 0 ) ) )
V_103 ^= F_8 ( V_113 ) ;
}
if ( V_103 > V_101 )
goto V_121;
* V_99 = V_103 ;
return 0 ;
V_121:
return - V_130 ;
}
static void F_39 ( unsigned int V_8 , T_2 V_131 , T_2 V_74 , T_2 V_78 )
{
struct V_132 V_133 ;
F_40 ( & V_133 ) ;
V_133 . V_131 = V_131 ;
V_133 . V_78 = V_78 ;
V_133 . V_8 = V_8 ;
V_133 . V_134 = F_41 () ;
if ( V_133 . V_131 & V_135 ) {
V_133 . V_74 = V_74 ;
if ( V_26 . V_27 ) {
T_4 V_136 = ( V_133 . V_74 >> 56 ) & 0x3f ;
V_133 . V_74 &= F_36 ( 55 , V_136 ) ;
}
}
if ( V_26 . V_27 ) {
F_42 ( F_11 ( V_8 ) , V_133 . V_137 ) ;
if ( V_133 . V_131 & V_138 )
F_42 ( F_43 ( V_8 ) , V_133 . V_139 ) ;
}
F_44 ( & V_133 ) ;
}
static inline void F_45 ( void )
{
F_46 ( V_140 ) ;
V_69 () ;
}
T_5 T_6 void T_7 F_47 ( void )
{
F_48 () ;
F_45 () ;
F_49 () ;
}
T_5 T_6 void T_7 F_50 ( void )
{
F_48 () ;
F_51 ( V_7 ) ;
F_45 () ;
F_52 ( V_7 ) ;
F_49 () ;
}
static inline bool
F_53 ( unsigned int V_8 , T_1 V_141 , T_1 V_142 , T_2 V_78 )
{
T_2 V_131 , V_74 = 0 ;
F_42 ( V_141 , V_131 ) ;
if ( ! ( V_131 & V_143 ) )
return false ;
if ( V_131 & V_135 )
F_42 ( V_142 , V_74 ) ;
F_39 ( V_8 , V_131 , V_74 , V_78 ) ;
F_54 ( V_141 , 0 ) ;
return V_131 & V_144 ;
}
static void F_55 ( unsigned int V_8 )
{
bool V_145 ;
V_145 = F_53 ( V_8 , V_77 . V_131 ( V_8 ) ,
V_77 . V_74 ( V_8 ) , 0 ) ;
if ( ! V_26 . V_27 )
return;
if ( V_145 ) {
F_54 ( F_56 ( V_8 ) , 0 ) ;
return;
}
F_53 ( V_8 , F_56 ( V_8 ) ,
F_57 ( V_8 ) , 0 ) ;
}
static void V_70 ( void )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_89 . V_90 ; ++ V_8 )
F_55 ( V_8 ) ;
}
static void F_58 ( unsigned int V_8 , T_2 V_78 )
{
F_53 ( V_8 , V_77 . V_131 ( V_8 ) , V_77 . V_74 ( V_8 ) , V_78 ) ;
}
static void F_59 ( struct V_28 * V_38 )
{
struct V_40 V_41 ;
T_1 V_15 = 0 , V_14 = 0 ;
if ( ! V_38 )
return;
if ( F_7 ( V_38 -> V_30 , & V_15 , & V_14 ) )
return;
if ( ! ( V_14 & V_46 ) )
return;
F_58 ( V_38 -> V_8 , ( ( T_2 ) V_14 << 32 ) | V_15 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_29 = V_38 ;
F_20 ( & V_41 ) ;
}
static void V_88 ( void )
{
struct V_28 * V_146 = NULL , * V_38 = NULL , * V_104 = NULL ;
unsigned int V_8 , V_9 = F_31 () ;
for ( V_8 = 0 ; V_8 < V_89 . V_90 ; ++ V_8 ) {
if ( ! ( F_32 ( V_83 , V_9 ) & ( 1 << V_8 ) ) )
continue;
V_146 = F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 ;
if ( ! V_146 )
continue;
F_59 ( V_146 ) ;
F_60 (block, tmp, &first_block->miscj, miscj)
F_59 ( V_38 ) ;
}
}
static T_8
F_61 ( struct V_28 * V_29 , const char * V_149 , T_9 V_150 )
{
struct V_40 V_41 ;
unsigned long V_59 ;
if ( ! V_29 -> V_50 )
return - V_130 ;
if ( F_62 ( V_149 , 0 , & V_59 ) < 0 )
return - V_130 ;
V_29 -> V_54 = ! ! V_59 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_29 = V_29 ;
F_63 ( V_29 -> V_9 , F_20 , & V_41 , 1 ) ;
return V_150 ;
}
static T_8
F_64 ( struct V_28 * V_29 , const char * V_149 , T_9 V_150 )
{
struct V_40 V_41 ;
unsigned long V_59 ;
if ( F_62 ( V_149 , 0 , & V_59 ) < 0 )
return - V_130 ;
if ( V_59 > V_43 )
V_59 = V_43 ;
if ( V_59 < 1 )
V_59 = 1 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 = V_29 -> V_42 ;
V_29 -> V_42 = V_59 ;
V_41 . V_29 = V_29 ;
F_63 ( V_29 -> V_9 , F_20 , & V_41 , 1 ) ;
return V_150 ;
}
static T_8 F_65 ( struct V_28 * V_29 , char * V_149 )
{
T_1 V_33 , V_34 ;
F_66 ( V_29 -> V_9 , V_29 -> V_30 , & V_33 , & V_34 ) ;
return sprintf ( V_149 , L_18 , ( ( V_34 & V_43 ) -
( V_43 - V_29 -> V_42 ) ) ) ;
}
static T_8 F_67 ( struct V_151 * V_152 , struct V_153 * V_154 , char * V_149 )
{
struct V_28 * V_29 = F_68 ( V_152 ) ;
struct V_155 * V_156 = F_69 ( V_154 ) ;
T_8 V_157 ;
V_157 = V_156 -> F_67 ? V_156 -> F_67 ( V_29 , V_149 ) : - V_158 ;
return V_157 ;
}
static T_8 F_70 ( struct V_151 * V_152 , struct V_153 * V_154 ,
const char * V_149 , T_9 V_25 )
{
struct V_28 * V_29 = F_68 ( V_152 ) ;
struct V_155 * V_156 = F_69 ( V_154 ) ;
T_8 V_157 ;
V_157 = V_156 -> F_70 ? V_156 -> F_70 ( V_29 , V_149 , V_25 ) : - V_158 ;
return V_157 ;
}
static const char * F_71 ( unsigned int V_8 , struct V_28 * V_29 )
{
unsigned int V_22 ;
if ( ! V_26 . V_27 ) {
if ( V_29 && V_8 == 4 )
return F_17 ( V_29 ) ;
return V_159 [ V_8 ] ;
}
if ( ! V_20 [ V_8 ] . V_21 )
return NULL ;
V_22 = V_20 [ V_8 ] . V_21 -> V_22 ;
if ( V_29 && V_22 == V_160 ) {
if ( V_29 -> V_38 < F_14 ( V_161 ) )
return V_161 [ V_29 -> V_38 ] ;
return NULL ;
}
if ( V_20 [ V_8 ] . V_21 -> V_25 == 1 )
return F_1 ( V_22 ) ;
snprintf ( V_162 , V_163 ,
L_19 , F_1 ( V_22 ) ,
V_20 [ V_8 ] . V_24 ) ;
return V_162 ;
}
static int F_72 ( unsigned int V_9 , unsigned int V_8 ,
unsigned int V_38 , T_1 V_30 )
{
struct V_28 * V_29 = NULL ;
T_1 V_15 , V_14 ;
int V_164 ;
if ( ( V_8 >= V_89 . V_90 ) || ( V_38 >= V_91 ) )
return 0 ;
if ( F_10 ( V_9 , V_30 , & V_15 , & V_14 ) )
return 0 ;
if ( ! ( V_14 & V_92 ) ) {
if ( V_38 )
goto V_165;
else
return 0 ;
}
if ( ! ( V_14 & V_93 ) ||
( V_14 & V_94 ) )
goto V_165;
V_29 = F_73 ( sizeof( struct V_28 ) , V_166 ) ;
if ( ! V_29 )
return - V_167 ;
V_29 -> V_38 = V_38 ;
V_29 -> V_8 = V_8 ;
V_29 -> V_9 = V_9 ;
V_29 -> V_30 = V_30 ;
V_29 -> V_54 = 0 ;
V_29 -> V_50 = F_18 ( V_8 , V_14 ) ;
V_29 -> V_42 = V_43 ;
if ( V_29 -> V_50 ) {
V_168 . V_169 [ 2 ] = & V_54 . V_154 ;
V_29 -> V_54 = 1 ;
} else {
V_168 . V_169 [ 2 ] = NULL ;
}
F_74 ( & V_29 -> V_170 ) ;
if ( F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 ) {
F_75 ( & V_29 -> V_170 ,
& F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 -> V_170 ) ;
} else {
F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 = V_29 ;
}
V_164 = F_76 ( & V_29 -> V_152 , & V_168 ,
F_32 ( V_147 , V_9 ) [ V_8 ] -> V_152 ,
F_71 ( V_8 , V_29 ) ) ;
if ( V_164 )
goto V_171;
V_165:
V_30 = F_27 ( V_9 , V_30 , V_15 , V_14 , V_8 , ++ V_38 ) ;
if ( ! V_30 )
return 0 ;
V_164 = F_72 ( V_9 , V_8 , V_38 , V_30 ) ;
if ( V_164 )
goto V_171;
if ( V_29 )
F_77 ( & V_29 -> V_152 , V_172 ) ;
return V_164 ;
V_171:
if ( V_29 ) {
F_78 ( & V_29 -> V_152 ) ;
F_79 ( & V_29 -> V_170 ) ;
F_80 ( V_29 ) ;
}
return V_164 ;
}
static int F_81 ( struct V_173 * V_29 )
{
struct V_174 * V_175 = & V_29 -> V_148 -> V_170 ;
struct V_28 * V_176 = NULL ;
struct V_28 * V_104 = NULL ;
int V_164 = 0 ;
V_164 = F_82 ( & V_29 -> V_148 -> V_152 , V_29 -> V_152 , V_29 -> V_148 -> V_152 . V_5 ) ;
if ( V_164 )
return V_164 ;
F_60 (pos, tmp, head, miscj) {
V_164 = F_82 ( & V_176 -> V_152 , V_29 -> V_152 , V_176 -> V_152 . V_5 ) ;
if ( V_164 ) {
F_83 (pos, tmp, head, miscj)
F_84 ( & V_176 -> V_152 ) ;
return V_164 ;
}
}
return V_164 ;
}
static int F_85 ( unsigned int V_9 , unsigned int V_8 )
{
struct V_177 * V_178 = F_32 ( V_179 , V_9 ) ;
struct V_180 * V_181 = NULL ;
struct V_173 * V_29 = NULL ;
const char * V_5 = F_71 ( V_8 , NULL ) ;
int V_164 = 0 ;
if ( ! V_178 )
return - V_182 ;
if ( F_16 ( V_8 ) ) {
V_181 = F_86 ( F_87 ( V_9 ) ) ;
if ( V_181 && V_181 -> V_183 ) {
V_29 = V_181 -> V_183 ;
V_164 = F_82 ( V_29 -> V_152 , & V_178 -> V_152 , V_5 ) ;
if ( V_164 )
goto V_85;
F_32 ( V_147 , V_9 ) [ V_8 ] = V_29 ;
F_88 ( & V_29 -> V_184 ) ;
V_164 = F_81 ( V_29 ) ;
goto V_85;
}
}
V_29 = F_73 ( sizeof( struct V_173 ) , V_166 ) ;
if ( ! V_29 ) {
V_164 = - V_167 ;
goto V_85;
}
V_29 -> V_152 = F_89 ( V_5 , & V_178 -> V_152 ) ;
if ( ! V_29 -> V_152 ) {
V_164 = - V_130 ;
goto V_171;
}
F_32 ( V_147 , V_9 ) [ V_8 ] = V_29 ;
if ( F_16 ( V_8 ) ) {
F_90 ( & V_29 -> V_184 , 1 ) ;
if ( V_181 ) {
F_91 ( V_181 -> V_183 ) ;
V_181 -> V_183 = V_29 ;
}
}
V_164 = F_72 ( V_9 , V_8 , 0 , V_77 . V_78 ( V_8 ) ) ;
if ( ! V_164 )
goto V_85;
V_171:
F_80 ( V_29 ) ;
V_85:
return V_164 ;
}
static void F_92 ( unsigned int V_9 ,
unsigned int V_8 )
{
struct V_28 * V_176 = NULL ;
struct V_28 * V_104 = NULL ;
struct V_173 * V_175 = F_32 ( V_147 , V_9 ) [ V_8 ] ;
if ( ! V_175 )
return;
F_60 (pos, tmp, &head->blocks->miscj, miscj) {
F_78 ( & V_176 -> V_152 ) ;
F_79 ( & V_176 -> V_170 ) ;
F_80 ( V_176 ) ;
}
F_80 ( F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 ) ;
F_32 ( V_147 , V_9 ) [ V_8 ] -> V_148 = NULL ;
}
static void F_93 ( struct V_173 * V_29 )
{
struct V_28 * V_176 = NULL ;
struct V_28 * V_104 = NULL ;
F_84 ( V_29 -> V_152 ) ;
F_60 (pos, tmp, &b->blocks->miscj, miscj)
F_84 ( & V_176 -> V_152 ) ;
}
static void F_94 ( unsigned int V_9 , int V_8 )
{
struct V_180 * V_181 ;
struct V_173 * V_29 ;
V_29 = F_32 ( V_147 , V_9 ) [ V_8 ] ;
if ( ! V_29 )
return;
if ( ! V_29 -> V_148 )
goto V_185;
if ( F_16 ( V_8 ) ) {
if ( ! F_95 ( & V_29 -> V_184 ) ) {
F_93 ( V_29 ) ;
F_32 ( V_147 , V_9 ) [ V_8 ] = NULL ;
return;
} else {
V_181 = F_86 ( F_87 ( V_9 ) ) ;
V_181 -> V_183 = NULL ;
}
}
F_92 ( V_9 , V_8 ) ;
V_185:
F_84 ( V_29 -> V_152 ) ;
F_78 ( V_29 -> V_152 ) ;
F_80 ( V_29 ) ;
F_32 ( V_147 , V_9 ) [ V_8 ] = NULL ;
}
int F_96 ( unsigned int V_9 )
{
unsigned int V_8 ;
if ( ! V_186 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_89 . V_90 ; ++ V_8 ) {
if ( ! ( F_32 ( V_83 , V_9 ) & ( 1 << V_8 ) ) )
continue;
F_94 ( V_9 , V_8 ) ;
}
F_80 ( F_32 ( V_147 , V_9 ) ) ;
F_32 ( V_147 , V_9 ) = NULL ;
return 0 ;
}
int F_97 ( unsigned int V_9 )
{
unsigned int V_8 ;
struct V_173 * * V_187 ;
int V_164 = 0 ;
if ( ! V_186 )
return 0 ;
V_187 = F_32 ( V_147 , V_9 ) ;
if ( V_187 )
return 0 ;
V_187 = F_73 ( sizeof( struct V_173 * ) * V_89 . V_90 ,
V_166 ) ;
if ( ! V_187 )
return - V_167 ;
F_32 ( V_147 , V_9 ) = V_187 ;
for ( V_8 = 0 ; V_8 < V_89 . V_90 ; ++ V_8 ) {
if ( ! ( F_32 ( V_83 , V_9 ) & ( 1 << V_8 ) ) )
continue;
V_164 = F_85 ( V_9 , V_8 ) ;
if ( V_164 )
goto V_164;
}
return V_164 ;
V_164:
F_96 ( V_9 ) ;
return V_164 ;
}
static T_10 int F_98 ( void )
{
unsigned V_188 = 0 ;
if ( V_87 == V_88 )
V_186 = true ;
F_99 (lcpu) {
int V_164 = F_97 ( V_188 ) ;
if ( V_164 )
return V_164 ;
}
return 0 ;
}
