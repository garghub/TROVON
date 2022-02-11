static int F_1 ( const void * V_1 , const void * V_2 )
{
return ( int ) ( unsigned long ) V_1 - ( int ) ( ( const struct V_3 * ) V_2 ) -> V_4 ;
}
static struct V_5 * F_2 ( T_1 V_4 )
{
const struct V_3 * V_6 ;
V_6 = bsearch ( ( const void * ) ( unsigned long ) V_4 ,
V_7 ,
F_3 ( V_7 ) ,
sizeof( V_7 [ 0 ] ) ,
F_1 ) ;
if ( V_6 )
return V_6 -> V_8 ;
return NULL ;
}
static T_2 F_4 ( const struct V_9 * V_10 , T_3 V_8 ,
T_3 V_11 )
{
T_2 V_12 = F_5 ( V_10 ) ;
V_8 &= ~ V_12 ;
V_8 |= ( V_11 << V_10 -> V_13 ) & V_12 ;
return V_8 ;
}
static T_3 F_6 ( const struct V_9 * V_10 , T_3 V_14 ,
T_3 V_15 )
{
T_3 V_6 = 0 ;
switch ( V_10 -> type ) {
case V_16 :
V_6 = V_10 -> V_17 ;
break;
case V_18 :
V_6 = V_14 < V_15 ? V_14 : V_15 ;
break;
case V_19 :
V_6 = V_14 > V_15 ? V_14 : V_15 ;
break;
default:
F_7 () ;
}
return V_6 ;
}
static void T_4 F_8 ( void )
{
int V_20 ;
for ( V_20 = 1 ; V_20 < F_3 ( V_7 ) ; V_20 ++ )
F_9 ( V_7 [ V_20 ] . V_4 < V_7 [ V_20 - 1 ] . V_4 ) ;
}
static void T_4 F_10 ( T_1 V_21 , T_2 V_14 )
{
T_2 V_22 = 0 ;
T_2 V_23 = ~ 0x0ULL ;
const struct V_9 * V_10 ;
struct V_5 * V_8 = F_2 ( V_21 ) ;
F_9 ( ! V_8 ) ;
for ( V_10 = V_8 -> V_24 ; V_10 -> V_25 ; V_10 ++ ) {
T_3 V_26 = F_11 ( V_10 , V_14 ) ;
V_22 = F_4 ( V_10 , V_22 , V_26 ) ;
if ( ! V_10 -> V_27 )
V_23 &= ~ F_5 ( V_10 ) ;
}
V_8 -> V_28 = V_22 ;
V_8 -> V_23 = V_23 ;
}
void T_4 F_12 ( struct V_29 * V_30 )
{
F_8 () ;
F_10 ( V_31 , V_30 -> V_32 ) ;
F_10 ( V_33 , V_30 -> V_34 ) ;
F_10 ( V_35 , V_30 -> V_36 ) ;
F_10 ( V_37 , V_30 -> V_38 ) ;
F_10 ( V_39 , V_30 -> V_40 ) ;
F_10 ( V_41 , V_30 -> V_42 ) ;
F_10 ( V_43 , V_30 -> V_44 ) ;
F_10 ( V_45 , V_30 -> V_46 ) ;
F_10 ( V_47 , V_30 -> V_48 ) ;
F_10 ( V_49 , V_30 -> V_50 ) ;
F_10 ( V_51 , V_30 -> V_52 ) ;
F_10 ( V_53 , V_30 -> V_54 ) ;
if ( F_13 ( V_30 -> V_52 ) ) {
F_10 ( V_55 , V_30 -> V_56 ) ;
F_10 ( V_57 , V_30 -> V_58 ) ;
F_10 ( V_59 , V_30 -> V_60 ) ;
F_10 ( V_61 , V_30 -> V_62 ) ;
F_10 ( V_63 , V_30 -> V_64 ) ;
F_10 ( V_65 , V_30 -> V_66 ) ;
F_10 ( V_67 , V_30 -> V_68 ) ;
F_10 ( V_69 , V_30 -> V_70 ) ;
F_10 ( V_71 , V_30 -> V_72 ) ;
F_10 ( V_73 , V_30 -> V_74 ) ;
F_10 ( V_75 , V_30 -> V_76 ) ;
F_10 ( V_77 , V_30 -> V_78 ) ;
F_10 ( V_79 , V_30 -> V_80 ) ;
F_10 ( V_81 , V_30 -> V_82 ) ;
F_10 ( V_83 , V_30 -> V_84 ) ;
F_10 ( V_85 , V_30 -> V_86 ) ;
}
}
static void F_14 ( struct V_5 * V_8 , T_2 V_14 )
{
const struct V_9 * V_10 ;
for ( V_10 = V_8 -> V_24 ; V_10 -> V_25 ; V_10 ++ ) {
T_3 V_87 = F_11 ( V_10 , V_8 -> V_28 ) ;
T_3 V_26 = F_11 ( V_10 , V_14 ) ;
if ( V_87 == V_26 )
continue;
V_26 = F_6 ( V_10 , V_26 , V_87 ) ;
V_8 -> V_28 = F_4 ( V_10 , V_8 -> V_28 , V_26 ) ;
}
}
static int F_15 ( T_1 V_4 , int V_88 , T_2 V_22 , T_2 V_89 )
{
struct V_5 * V_2 = F_2 ( V_4 ) ;
F_9 ( ! V_2 ) ;
F_14 ( V_2 , V_22 ) ;
if ( ( V_89 & V_2 -> V_23 ) == ( V_22 & V_2 -> V_23 ) )
return 0 ;
F_16 ( L_1 ,
V_2 -> V_90 , V_89 , V_88 , V_22 ) ;
return 1 ;
}
void F_17 ( int V_88 ,
struct V_29 * V_30 ,
struct V_29 * V_89 )
{
int V_91 = 0 ;
V_91 |= F_15 ( V_31 , V_88 ,
V_30 -> V_32 , V_89 -> V_32 ) ;
V_91 |= F_15 ( V_33 , V_88 ,
V_30 -> V_34 , V_89 -> V_34 ) ;
V_91 |= F_15 ( V_35 , V_88 ,
V_30 -> V_36 , V_89 -> V_36 ) ;
V_91 |= F_15 ( V_37 , V_88 ,
V_30 -> V_38 , V_89 -> V_38 ) ;
V_91 |= F_15 ( V_39 , V_88 ,
V_30 -> V_40 , V_89 -> V_40 ) ;
V_91 |= F_15 ( V_41 , V_88 ,
V_30 -> V_42 , V_89 -> V_42 ) ;
V_91 |= F_15 ( V_43 , V_88 ,
V_30 -> V_44 , V_89 -> V_44 ) ;
V_91 |= F_15 ( V_45 , V_88 ,
V_30 -> V_46 , V_89 -> V_46 ) ;
V_91 |= F_15 ( V_47 , V_88 ,
V_30 -> V_48 , V_89 -> V_48 ) ;
V_91 |= F_15 ( V_49 , V_88 ,
V_30 -> V_50 , V_89 -> V_50 ) ;
V_91 |= F_15 ( V_51 , V_88 ,
V_30 -> V_52 , V_89 -> V_52 ) ;
V_91 |= F_15 ( V_53 , V_88 ,
V_30 -> V_54 , V_89 -> V_54 ) ;
if ( F_13 ( F_18 ( V_51 ) ) &&
F_13 ( V_30 -> V_52 ) ) {
V_91 |= F_15 ( V_55 , V_88 ,
V_30 -> V_56 , V_89 -> V_56 ) ;
V_91 |= F_15 ( V_57 , V_88 ,
V_30 -> V_58 , V_89 -> V_58 ) ;
V_91 |= F_15 ( V_59 , V_88 ,
V_30 -> V_60 , V_89 -> V_60 ) ;
V_91 |= F_15 ( V_61 , V_88 ,
V_30 -> V_62 , V_89 -> V_62 ) ;
V_91 |= F_15 ( V_63 , V_88 ,
V_30 -> V_64 , V_89 -> V_64 ) ;
V_91 |= F_15 ( V_65 , V_88 ,
V_30 -> V_66 , V_89 -> V_66 ) ;
V_91 |= F_15 ( V_67 , V_88 ,
V_30 -> V_68 , V_89 -> V_68 ) ;
V_91 |= F_15 ( V_69 , V_88 ,
V_30 -> V_70 , V_89 -> V_70 ) ;
V_91 |= F_15 ( V_71 , V_88 ,
V_30 -> V_72 , V_89 -> V_72 ) ;
V_91 |= F_15 ( V_73 , V_88 ,
V_30 -> V_74 , V_89 -> V_74 ) ;
V_91 |= F_15 ( V_75 , V_88 ,
V_30 -> V_76 , V_89 -> V_76 ) ;
V_91 |= F_15 ( V_77 , V_88 ,
V_30 -> V_78 , V_89 -> V_78 ) ;
V_91 |= F_15 ( V_79 , V_88 ,
V_30 -> V_80 , V_89 -> V_80 ) ;
V_91 |= F_15 ( V_81 , V_88 ,
V_30 -> V_82 , V_89 -> V_82 ) ;
V_91 |= F_15 ( V_83 , V_88 ,
V_30 -> V_84 , V_89 -> V_84 ) ;
V_91 |= F_15 ( V_85 , V_88 ,
V_30 -> V_86 , V_89 -> V_86 ) ;
}
F_19 ( V_91 , V_92 ,
L_2 ) ;
}
T_2 F_18 ( T_1 V_1 )
{
struct V_5 * V_2 = F_2 ( V_1 ) ;
F_9 ( ! V_2 ) ;
return V_2 -> V_28 ;
}
static T_2 F_20 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_77 : return F_21 ( V_93 ) ;
case V_79 : return F_21 ( V_94 ) ;
case V_55 : return F_21 ( V_95 ) ;
case V_69 : return F_21 ( V_96 ) ;
case V_71 : return F_21 ( V_97 ) ;
case V_73 : return F_21 ( V_98 ) ;
case V_75 : return F_21 ( V_99 ) ;
case V_57 : return F_21 ( V_100 ) ;
case V_59 : return F_21 ( V_101 ) ;
case V_61 : return F_21 ( V_102 ) ;
case V_63 : return F_21 ( V_103 ) ;
case V_65 : return F_21 ( V_104 ) ;
case V_67 : return F_21 ( V_104 ) ;
case V_81 : return F_21 ( V_105 ) ;
case V_83 : return F_21 ( V_106 ) ;
case V_85 : return F_21 ( V_107 ) ;
case V_51 : return F_21 ( V_108 ) ;
case V_53 : return F_21 ( V_108 ) ;
case V_37 : return F_21 ( V_109 ) ;
case V_39 : return F_21 ( V_109 ) ;
case V_45 : return F_21 ( V_110 ) ;
case V_47 : return F_21 ( V_111 ) ;
case V_49 : return F_21 ( V_112 ) ;
case V_41 : return F_21 ( V_113 ) ;
case V_43 : return F_21 ( V_114 ) ;
case V_35 : return F_21 ( V_115 ) ;
case V_31 : return F_21 ( V_116 ) ;
case V_33 : return F_21 ( V_117 ) ;
default:
F_7 () ;
return 0 ;
}
}
static bool
F_22 ( T_2 V_8 , const struct V_118 * V_119 )
{
int V_22 = F_23 ( V_8 , V_119 -> V_120 , V_119 -> V_121 ) ;
return V_22 >= V_119 -> V_122 ;
}
static bool
F_24 ( const struct V_118 * V_119 , int V_123 )
{
T_2 V_22 ;
F_25 ( V_123 == V_124 && F_26 () ) ;
if ( V_123 == V_125 )
V_22 = F_18 ( V_119 -> V_21 ) ;
else
V_22 = F_20 ( V_119 -> V_21 ) ;
return F_22 ( V_22 , V_119 ) ;
}
static bool F_27 ( const struct V_118 * V_119 , int V_123 )
{
bool V_126 ;
if ( ! F_24 ( V_119 , V_123 ) )
return false ;
V_126 = F_28 () ;
if ( ! V_126 )
F_29 ( L_3 ,
V_119 -> V_127 ) ;
return V_126 ;
}
static bool F_30 ( const struct V_118 * V_119 , int V_128 )
{
T_1 V_129 = F_31 () ;
T_1 V_130 , V_131 ;
V_130 = 0 ;
V_131 = ( 1 << V_132 ) | V_133 ;
return F_32 ( V_129 , V_134 , V_130 , V_131 ) ;
}
static bool F_33 ( const struct V_118 * V_119 , int V_128 )
{
return F_34 () ;
}
static bool F_35 ( const struct V_118 * V_119 ,
int V_128 )
{
T_5 V_135 = F_36 ( V_136 ) ;
return V_135 > F_37 ( V_137 - 2 , 0 ) && ! F_34 () ;
}
static void T_4 F_38 ( const struct V_118 * V_138 )
{
switch ( V_138 -> V_139 ) {
case V_140 :
V_141 |= V_138 -> V_142 ;
break;
#ifdef F_39
case V_143 :
V_144 |= ( T_1 ) V_138 -> V_142 ;
break;
case V_145 :
V_146 |= ( T_1 ) V_138 -> V_142 ;
break;
#endif
default:
F_25 ( 1 ) ;
break;
}
}
static bool F_40 ( const struct V_118 * V_138 )
{
bool V_147 ;
switch ( V_138 -> V_139 ) {
case V_140 :
V_147 = ( V_141 & V_138 -> V_142 ) != 0 ;
break;
#ifdef F_39
case V_143 :
V_147 = ( V_144 & ( T_1 ) V_138 -> V_142 ) != 0 ;
break;
case V_145 :
V_147 = ( V_146 & ( T_1 ) V_138 -> V_142 ) != 0 ;
break;
#endif
default:
F_25 ( 1 ) ;
V_147 = false ;
}
return V_147 ;
}
static void T_4 F_41 ( const struct V_118 * V_148 )
{
for (; V_148 -> V_149 ; V_148 ++ )
if ( V_148 -> V_149 ( V_148 , V_148 -> V_150 ) )
F_38 ( V_148 ) ;
}
void F_42 ( const struct V_118 * V_151 ,
const char * V_30 )
{
for (; V_151 -> V_149 ; V_151 ++ ) {
if ( ! V_151 -> V_149 ( V_151 , V_151 -> V_150 ) )
continue;
if ( ! F_43 ( V_151 -> V_152 ) && V_151 -> V_127 )
F_44 ( L_4 , V_30 , V_151 -> V_127 ) ;
F_45 ( V_151 -> V_152 ) ;
}
}
void T_4 F_46 ( const struct V_118 * V_151 )
{
for (; V_151 -> V_149 ; V_151 ++ )
if ( V_151 -> V_153 && F_43 ( V_151 -> V_152 ) )
F_47 ( V_151 -> V_153 , NULL , V_154 ) ;
}
static inline void F_48 ( void )
{
V_155 = true ;
}
static void F_49 ( void )
{
F_50 () ;
F_51 () ;
}
static void
F_52 ( const struct V_118 * V_151 )
{
for (; V_151 -> V_149 ; V_151 ++ )
if ( F_40 ( V_151 ) && ! V_151 -> V_149 ( V_151 , V_124 ) ) {
F_53 ( L_5 ,
F_54 () , V_151 -> V_127 ) ;
F_55 () ;
}
}
static void
F_56 ( const struct V_118 * V_151 )
{
for (; V_151 -> V_149 ; V_151 ++ ) {
if ( ! F_43 ( V_151 -> V_152 ) )
continue;
if ( ! V_151 -> V_149 ( V_151 , V_124 ) ) {
F_53 ( L_6 ,
F_54 () , V_151 -> V_127 ) ;
F_55 () ;
}
if ( V_151 -> V_153 )
V_151 -> V_153 ( NULL ) ;
}
}
static void F_57 ( void )
{
F_58 () ;
F_56 ( V_156 ) ;
F_52 ( V_157 ) ;
if ( F_59 () )
F_52 ( V_158 ) ;
}
void F_60 ( void )
{
F_49 () ;
if ( ! V_155 )
F_61 () ;
else
F_57 () ;
}
static void T_4 F_62 ( void )
{
F_42 ( V_156 , L_7 ) ;
F_46 ( V_156 ) ;
}
bool F_63 ( unsigned int V_138 )
{
const struct V_118 * V_151 ;
if ( F_25 ( F_26 () ) )
return false ;
for ( V_151 = V_156 ; V_151 -> V_127 ; V_151 ++ )
if ( V_151 -> V_152 == V_138 && V_151 -> V_149 )
return V_151 -> V_149 ( V_151 , V_124 ) ;
return false ;
}
void T_4 F_64 ( void )
{
T_1 V_159 ;
int V_160 ;
F_62 () ;
F_65 () ;
F_41 ( V_157 ) ;
if ( F_59 () )
F_41 ( V_158 ) ;
F_48 () ;
V_159 = F_66 () ;
V_160 = F_67 () ;
if ( ! V_159 )
F_16 ( L_8 ,
V_160 ) ;
if ( V_161 < V_160 )
F_16 ( L_9 ,
V_161 , V_160 ) ;
}
static bool T_6
F_68 ( const struct V_118 * V_119 , int V_128 )
{
return ( F_43 ( V_162 ) && ! F_43 ( V_163 ) ) ;
}
