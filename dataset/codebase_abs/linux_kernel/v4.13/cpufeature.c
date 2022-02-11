static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
F_2 ( L_1 , V_5 , & V_6 ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
F_4 ( & V_7 ,
& V_8 ) ;
return 0 ;
}
static int F_5 ( const void * V_9 , const void * V_10 )
{
return ( int ) ( unsigned long ) V_9 - ( int ) ( ( const struct V_11 * ) V_10 ) -> V_12 ;
}
static struct V_13 * F_6 ( T_2 V_12 )
{
const struct V_11 * V_14 ;
V_14 = bsearch ( ( const void * ) ( unsigned long ) V_12 ,
V_15 ,
F_7 ( V_15 ) ,
sizeof( V_15 [ 0 ] ) ,
F_5 ) ;
if ( V_14 )
return V_14 -> V_16 ;
return NULL ;
}
static T_3 F_8 ( const struct V_17 * V_18 , T_4 V_16 ,
T_4 V_19 )
{
T_3 V_20 = F_9 ( V_18 ) ;
V_16 &= ~ V_20 ;
V_16 |= ( V_19 << V_18 -> V_21 ) & V_20 ;
return V_16 ;
}
static T_4 F_10 ( const struct V_17 * V_18 , T_4 V_22 ,
T_4 V_23 )
{
T_4 V_14 = 0 ;
switch ( V_18 -> type ) {
case V_24 :
V_14 = V_18 -> V_25 ;
break;
case V_26 :
V_14 = V_22 < V_23 ? V_22 : V_23 ;
break;
case V_27 :
V_14 = V_22 > V_23 ? V_22 : V_23 ;
break;
default:
F_11 () ;
}
return V_14 ;
}
static void T_1 F_12 ( void )
{
int V_28 ;
for ( V_28 = 1 ; V_28 < F_7 ( V_15 ) ; V_28 ++ )
F_13 ( V_15 [ V_28 ] . V_12 < V_15 [ V_28 - 1 ] . V_12 ) ;
}
static void T_1 F_14 ( T_2 V_29 , T_3 V_22 )
{
T_3 V_30 = 0 ;
T_3 V_31 = ~ 0x0ULL ;
T_3 V_32 = 0 ;
T_3 V_33 = 0 ;
const struct V_17 * V_18 ;
struct V_13 * V_16 = F_6 ( V_29 ) ;
F_13 ( ! V_16 ) ;
for ( V_18 = V_16 -> V_34 ; V_18 -> V_35 ; V_18 ++ ) {
T_3 V_36 = F_9 ( V_18 ) ;
T_4 V_37 = F_15 ( V_18 , V_22 ) ;
V_30 = F_8 ( V_18 , V_30 , V_37 ) ;
V_33 |= V_36 ;
if ( ! V_18 -> V_38 )
V_31 &= ~ V_36 ;
if ( V_18 -> V_39 )
V_32 |= V_36 ;
else
V_16 -> V_40 = F_8 ( V_18 ,
V_16 -> V_40 ,
V_18 -> V_25 ) ;
}
V_30 &= V_33 ;
V_16 -> V_41 = V_30 ;
V_16 -> V_31 = V_31 ;
V_16 -> V_32 = V_32 ;
}
void T_1 F_16 ( struct V_42 * V_43 )
{
F_12 () ;
F_14 ( V_44 , V_43 -> V_45 ) ;
F_14 ( V_46 , V_43 -> V_47 ) ;
F_14 ( V_48 , V_43 -> V_49 ) ;
F_14 ( V_50 , V_43 -> V_51 ) ;
F_14 ( V_52 , V_43 -> V_53 ) ;
F_14 ( V_54 , V_43 -> V_55 ) ;
F_14 ( V_56 , V_43 -> V_57 ) ;
F_14 ( V_58 , V_43 -> V_59 ) ;
F_14 ( V_60 , V_43 -> V_61 ) ;
F_14 ( V_62 , V_43 -> V_63 ) ;
F_14 ( V_64 , V_43 -> V_65 ) ;
F_14 ( V_66 , V_43 -> V_67 ) ;
if ( F_17 ( V_43 -> V_65 ) ) {
F_14 ( V_68 , V_43 -> V_69 ) ;
F_14 ( V_70 , V_43 -> V_71 ) ;
F_14 ( V_72 , V_43 -> V_73 ) ;
F_14 ( V_74 , V_43 -> V_75 ) ;
F_14 ( V_76 , V_43 -> V_77 ) ;
F_14 ( V_78 , V_43 -> V_79 ) ;
F_14 ( V_80 , V_43 -> V_81 ) ;
F_14 ( V_82 , V_43 -> V_83 ) ;
F_14 ( V_84 , V_43 -> V_85 ) ;
F_14 ( V_86 , V_43 -> V_87 ) ;
F_14 ( V_88 , V_43 -> V_89 ) ;
F_14 ( V_90 , V_43 -> V_91 ) ;
F_14 ( V_92 , V_43 -> V_93 ) ;
F_14 ( V_94 , V_43 -> V_95 ) ;
F_14 ( V_96 , V_43 -> V_97 ) ;
F_14 ( V_98 , V_43 -> V_99 ) ;
}
}
static void F_18 ( struct V_13 * V_16 , T_3 V_22 )
{
const struct V_17 * V_18 ;
for ( V_18 = V_16 -> V_34 ; V_18 -> V_35 ; V_18 ++ ) {
T_4 V_100 = F_15 ( V_18 , V_16 -> V_41 ) ;
T_4 V_37 = F_15 ( V_18 , V_22 ) ;
if ( V_100 == V_37 )
continue;
V_37 = F_10 ( V_18 , V_37 , V_100 ) ;
V_16 -> V_41 = F_8 ( V_18 , V_16 -> V_41 , V_37 ) ;
}
}
static int F_19 ( T_2 V_12 , int V_101 , T_3 V_30 , T_3 V_102 )
{
struct V_13 * V_10 = F_6 ( V_12 ) ;
F_13 ( ! V_10 ) ;
F_18 ( V_10 , V_30 ) ;
if ( ( V_102 & V_10 -> V_31 ) == ( V_30 & V_10 -> V_31 ) )
return 0 ;
F_20 ( L_2 ,
V_10 -> V_103 , V_102 , V_101 , V_30 ) ;
return 1 ;
}
void F_21 ( int V_101 ,
struct V_42 * V_43 ,
struct V_42 * V_102 )
{
int V_104 = 0 ;
V_104 |= F_19 ( V_44 , V_101 ,
V_43 -> V_45 , V_102 -> V_45 ) ;
V_104 |= F_19 ( V_46 , V_101 ,
V_43 -> V_47 , V_102 -> V_47 ) ;
V_104 |= F_19 ( V_48 , V_101 ,
V_43 -> V_49 , V_102 -> V_49 ) ;
V_104 |= F_19 ( V_50 , V_101 ,
V_43 -> V_51 , V_102 -> V_51 ) ;
V_104 |= F_19 ( V_52 , V_101 ,
V_43 -> V_53 , V_102 -> V_53 ) ;
V_104 |= F_19 ( V_54 , V_101 ,
V_43 -> V_55 , V_102 -> V_55 ) ;
V_104 |= F_19 ( V_56 , V_101 ,
V_43 -> V_57 , V_102 -> V_57 ) ;
V_104 |= F_19 ( V_58 , V_101 ,
V_43 -> V_59 , V_102 -> V_59 ) ;
V_104 |= F_19 ( V_60 , V_101 ,
V_43 -> V_61 , V_102 -> V_61 ) ;
V_104 |= F_19 ( V_62 , V_101 ,
V_43 -> V_63 , V_102 -> V_63 ) ;
V_104 |= F_19 ( V_64 , V_101 ,
V_43 -> V_65 , V_102 -> V_65 ) ;
V_104 |= F_19 ( V_66 , V_101 ,
V_43 -> V_67 , V_102 -> V_67 ) ;
if ( F_17 ( F_22 ( V_64 ) ) &&
F_17 ( V_43 -> V_65 ) ) {
V_104 |= F_19 ( V_68 , V_101 ,
V_43 -> V_69 , V_102 -> V_69 ) ;
V_104 |= F_19 ( V_70 , V_101 ,
V_43 -> V_71 , V_102 -> V_71 ) ;
V_104 |= F_19 ( V_72 , V_101 ,
V_43 -> V_73 , V_102 -> V_73 ) ;
V_104 |= F_19 ( V_74 , V_101 ,
V_43 -> V_75 , V_102 -> V_75 ) ;
V_104 |= F_19 ( V_76 , V_101 ,
V_43 -> V_77 , V_102 -> V_77 ) ;
V_104 |= F_19 ( V_78 , V_101 ,
V_43 -> V_79 , V_102 -> V_79 ) ;
V_104 |= F_19 ( V_80 , V_101 ,
V_43 -> V_81 , V_102 -> V_81 ) ;
V_104 |= F_19 ( V_82 , V_101 ,
V_43 -> V_83 , V_102 -> V_83 ) ;
V_104 |= F_19 ( V_84 , V_101 ,
V_43 -> V_85 , V_102 -> V_85 ) ;
V_104 |= F_19 ( V_86 , V_101 ,
V_43 -> V_87 , V_102 -> V_87 ) ;
V_104 |= F_19 ( V_88 , V_101 ,
V_43 -> V_89 , V_102 -> V_89 ) ;
V_104 |= F_19 ( V_90 , V_101 ,
V_43 -> V_91 , V_102 -> V_91 ) ;
V_104 |= F_19 ( V_92 , V_101 ,
V_43 -> V_93 , V_102 -> V_93 ) ;
V_104 |= F_19 ( V_94 , V_101 ,
V_43 -> V_95 , V_102 -> V_95 ) ;
V_104 |= F_19 ( V_96 , V_101 ,
V_43 -> V_97 , V_102 -> V_97 ) ;
V_104 |= F_19 ( V_98 , V_101 ,
V_43 -> V_99 , V_102 -> V_99 ) ;
}
if ( V_104 ) {
F_23 ( L_3 ) ;
F_24 ( V_105 , V_106 ) ;
}
}
T_3 F_22 ( T_2 V_9 )
{
struct V_13 * V_10 = F_6 ( V_9 ) ;
F_13 ( ! V_10 ) ;
return V_10 -> V_41 ;
}
static T_3 F_25 ( T_2 V_12 )
{
switch ( V_12 ) {
F_26 ( V_90 ) ;
F_26 ( V_92 ) ;
F_26 ( V_68 ) ;
F_26 ( V_82 ) ;
F_26 ( V_84 ) ;
F_26 ( V_86 ) ;
F_26 ( V_88 ) ;
F_26 ( V_70 ) ;
F_26 ( V_72 ) ;
F_26 ( V_74 ) ;
F_26 ( V_76 ) ;
F_26 ( V_78 ) ;
F_26 ( V_80 ) ;
F_26 ( V_94 ) ;
F_26 ( V_96 ) ;
F_26 ( V_98 ) ;
F_26 ( V_64 ) ;
F_26 ( V_66 ) ;
F_26 ( V_50 ) ;
F_26 ( V_52 ) ;
F_26 ( V_58 ) ;
F_26 ( V_60 ) ;
F_26 ( V_62 ) ;
F_26 ( V_54 ) ;
F_26 ( V_56 ) ;
F_26 ( V_48 ) ;
F_26 ( V_44 ) ;
F_26 ( V_46 ) ;
default:
F_11 () ;
return 0 ;
}
}
static bool
F_27 ( T_3 V_16 , const struct V_107 * V_108 )
{
int V_30 = F_28 ( V_16 , V_108 -> V_109 , V_108 -> V_110 ) ;
return V_30 >= V_108 -> V_111 ;
}
static bool
F_29 ( const struct V_107 * V_108 , int V_112 )
{
T_3 V_30 ;
F_30 ( V_112 == V_113 && F_31 () ) ;
if ( V_112 == V_114 )
V_30 = F_22 ( V_108 -> V_29 ) ;
else
V_30 = F_25 ( V_108 -> V_29 ) ;
return F_27 ( V_30 , V_108 ) ;
}
static bool F_32 ( const struct V_107 * V_108 , int V_112 )
{
bool V_115 ;
if ( ! F_29 ( V_108 , V_112 ) )
return false ;
V_115 = F_33 () ;
if ( ! V_115 )
F_23 ( L_4 ,
V_108 -> V_116 ) ;
return V_115 ;
}
static bool F_34 ( const struct V_107 * V_108 , int V_117 )
{
T_2 V_118 = F_35 () ;
return F_36 ( V_118 , V_119 ,
F_37 ( 0 , 0 ) ,
F_37 ( 1 , V_120 ) ) ;
}
static bool F_38 ( const struct V_107 * V_108 , int V_117 )
{
return F_39 () ;
}
static bool F_40 ( const struct V_107 * V_108 ,
int V_117 )
{
T_5 V_121 = F_41 ( V_122 ) ;
return V_121 > F_42 ( V_123 - 2 , 0 ) && ! F_39 () ;
}
static bool F_43 ( const struct V_107 * V_108 , int V_117 )
{
T_3 V_124 = F_22 ( V_64 ) ;
return F_44 ( V_124 ,
V_125 ) < 0 ;
}
static void T_1 F_45 ( const struct V_107 * V_126 )
{
switch ( V_126 -> V_127 ) {
case V_128 :
V_129 |= V_126 -> V_130 ;
break;
#ifdef F_46
case V_131 :
V_132 |= ( T_2 ) V_126 -> V_130 ;
break;
case V_133 :
V_134 |= ( T_2 ) V_126 -> V_130 ;
break;
#endif
default:
F_30 ( 1 ) ;
break;
}
}
static bool F_47 ( const struct V_107 * V_126 )
{
bool V_135 ;
switch ( V_126 -> V_127 ) {
case V_128 :
V_135 = ( V_129 & V_126 -> V_130 ) != 0 ;
break;
#ifdef F_46
case V_131 :
V_135 = ( V_132 & ( T_2 ) V_126 -> V_130 ) != 0 ;
break;
case V_133 :
V_135 = ( V_134 & ( T_2 ) V_126 -> V_130 ) != 0 ;
break;
#endif
default:
F_30 ( 1 ) ;
V_135 = false ;
}
return V_135 ;
}
static void T_1 F_48 ( const struct V_107 * V_136 )
{
V_129 |= V_137 ;
for (; V_136 -> V_138 ; V_136 ++ )
if ( V_136 -> V_138 ( V_136 , V_136 -> V_139 ) )
F_45 ( V_136 ) ;
}
void F_49 ( const struct V_107 * V_140 ,
const char * V_43 )
{
for (; V_140 -> V_138 ; V_140 ++ ) {
if ( ! V_140 -> V_138 ( V_140 , V_140 -> V_139 ) )
continue;
if ( ! F_50 ( V_140 -> V_141 ) && V_140 -> V_116 )
F_51 ( L_5 , V_43 , V_140 -> V_116 ) ;
F_52 ( V_140 -> V_141 ) ;
}
}
void T_1 F_53 ( const struct V_107 * V_140 )
{
for (; V_140 -> V_138 ; V_140 ++ ) {
unsigned int V_142 = V_140 -> V_141 ;
if ( ! F_50 ( V_142 ) )
continue;
F_54 ( & V_143 [ V_142 ] ) ;
if ( V_140 -> V_144 ) {
F_55 ( V_140 -> V_144 , NULL , V_145 ) ;
}
}
}
static inline void F_56 ( void )
{
V_146 = true ;
}
static void F_57 ( void )
{
F_58 () ;
F_59 () ;
}
static void
F_60 ( const struct V_107 * V_140 )
{
for (; V_140 -> V_138 ; V_140 ++ )
if ( F_47 ( V_140 ) && ! V_140 -> V_138 ( V_140 , V_113 ) ) {
F_61 ( L_6 ,
F_62 () , V_140 -> V_116 ) ;
F_63 () ;
}
}
static void
F_64 ( const struct V_107 * V_140 )
{
for (; V_140 -> V_138 ; V_140 ++ ) {
if ( ! F_50 ( V_140 -> V_141 ) )
continue;
if ( ! V_140 -> V_138 ( V_140 , V_113 ) ) {
F_61 ( L_7 ,
F_62 () , V_140 -> V_116 ) ;
F_63 () ;
}
if ( V_140 -> V_144 )
V_140 -> V_144 ( NULL ) ;
}
}
static void F_65 ( void )
{
F_66 () ;
F_64 ( V_147 ) ;
F_60 ( V_148 ) ;
if ( F_67 () )
F_60 ( V_149 ) ;
}
void F_68 ( void )
{
F_57 () ;
if ( ! V_146 )
F_69 () ;
else
F_65 () ;
}
static void T_1 F_70 ( void )
{
F_49 ( V_147 , L_8 ) ;
F_53 ( V_147 ) ;
}
static void T_1 F_71 ( void )
{
F_54 ( & V_150 ) ;
}
static bool F_72 ( const struct V_107 * V_151 ,
unsigned int V_126 )
{
const struct V_107 * V_140 ;
if ( F_30 ( F_31 () ) )
return false ;
for ( V_140 = V_151 ; V_140 -> V_116 ; V_140 ++ )
if ( V_140 -> V_141 == V_126 && V_140 -> V_138 )
return V_140 -> V_138 ( V_140 , V_113 ) ;
return false ;
}
bool F_73 ( unsigned int V_126 )
{
return ( F_72 ( V_147 , V_126 ) ||
F_72 ( V_152 , V_126 ) ) ;
}
void T_1 F_74 ( void )
{
T_2 V_153 ;
int V_154 ;
F_70 () ;
F_75 () ;
F_71 () ;
F_48 ( V_148 ) ;
if ( F_67 () )
F_48 ( V_149 ) ;
F_56 () ;
V_153 = F_76 () ;
V_154 = F_77 () ;
if ( ! V_153 )
F_20 ( L_9 ,
V_154 ) ;
if ( V_155 < V_154 )
F_20 ( L_10 ,
V_155 , V_154 ) ;
}
static bool T_6
F_78 ( const struct V_107 * V_108 , int V_117 )
{
return ( F_79 ( V_156 ) && ! F_79 ( V_157 ) ) ;
}
static inline bool T_7 F_80 ( T_2 V_9 )
{
return ( F_81 ( V_9 ) == 0x3 &&
F_82 ( V_9 ) == 0x0 &&
F_83 ( V_9 ) == 0x0 &&
( F_84 ( V_9 ) == 0 ||
( ( F_84 ( V_9 ) >= 4 ) && ( F_84 ( V_9 ) <= 7 ) ) ) ) ;
}
static inline int F_85 ( T_2 V_9 , T_3 * V_158 )
{
switch ( V_9 ) {
case V_159 :
* V_158 = F_35 () ;
break;
case V_160 :
* V_158 = V_161 ;
break;
case V_162 :
* V_158 = 0 ;
break;
default:
return - V_163 ;
}
return 0 ;
}
static int F_86 ( T_2 V_9 , T_3 * V_158 )
{
struct V_13 * V_10 ;
if ( ! F_80 ( V_9 ) )
return - V_163 ;
if ( F_84 ( V_9 ) == 0 )
return F_85 ( V_9 , V_158 ) ;
V_10 = F_6 ( V_9 ) ;
if ( V_10 )
* V_158 = F_87 ( V_10 ) ;
else
* V_158 = 0 ;
return 0 ;
}
static int F_88 ( struct V_164 * V_165 , T_2 V_166 )
{
int V_135 ;
T_2 V_29 , V_167 ;
T_3 V_30 ;
V_29 = ( T_2 ) F_89 ( V_168 , V_166 ) << 5 ;
V_135 = F_86 ( V_29 , & V_30 ) ;
if ( ! V_135 ) {
V_167 = F_90 ( V_169 , V_166 ) ;
F_91 ( V_165 , V_167 , V_30 ) ;
V_165 -> V_170 += 4 ;
}
return V_135 ;
}
static int T_1 F_92 ( void )
{
F_93 ( & V_171 ) ;
return 0 ;
}
