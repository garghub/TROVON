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
T_2 V_24 = 0 ;
T_2 V_25 = 0 ;
const struct V_9 * V_10 ;
struct V_5 * V_8 = F_2 ( V_21 ) ;
F_9 ( ! V_8 ) ;
for ( V_10 = V_8 -> V_26 ; V_10 -> V_27 ; V_10 ++ ) {
T_2 V_28 = F_5 ( V_10 ) ;
T_3 V_29 = F_11 ( V_10 , V_14 ) ;
V_22 = F_4 ( V_10 , V_22 , V_29 ) ;
V_25 |= V_28 ;
if ( ! V_10 -> V_30 )
V_23 &= ~ V_28 ;
if ( V_10 -> V_31 )
V_24 |= V_28 ;
else
V_8 -> V_32 = F_4 ( V_10 ,
V_8 -> V_32 ,
V_10 -> V_17 ) ;
}
V_22 &= V_25 ;
V_8 -> V_33 = V_22 ;
V_8 -> V_23 = V_23 ;
V_8 -> V_24 = V_24 ;
}
void T_4 F_12 ( struct V_34 * V_35 )
{
F_8 () ;
F_10 ( V_36 , V_35 -> V_37 ) ;
F_10 ( V_38 , V_35 -> V_39 ) ;
F_10 ( V_40 , V_35 -> V_41 ) ;
F_10 ( V_42 , V_35 -> V_43 ) ;
F_10 ( V_44 , V_35 -> V_45 ) ;
F_10 ( V_46 , V_35 -> V_47 ) ;
F_10 ( V_48 , V_35 -> V_49 ) ;
F_10 ( V_50 , V_35 -> V_51 ) ;
F_10 ( V_52 , V_35 -> V_53 ) ;
F_10 ( V_54 , V_35 -> V_55 ) ;
F_10 ( V_56 , V_35 -> V_57 ) ;
F_10 ( V_58 , V_35 -> V_59 ) ;
if ( F_13 ( V_35 -> V_57 ) ) {
F_10 ( V_60 , V_35 -> V_61 ) ;
F_10 ( V_62 , V_35 -> V_63 ) ;
F_10 ( V_64 , V_35 -> V_65 ) ;
F_10 ( V_66 , V_35 -> V_67 ) ;
F_10 ( V_68 , V_35 -> V_69 ) ;
F_10 ( V_70 , V_35 -> V_71 ) ;
F_10 ( V_72 , V_35 -> V_73 ) ;
F_10 ( V_74 , V_35 -> V_75 ) ;
F_10 ( V_76 , V_35 -> V_77 ) ;
F_10 ( V_78 , V_35 -> V_79 ) ;
F_10 ( V_80 , V_35 -> V_81 ) ;
F_10 ( V_82 , V_35 -> V_83 ) ;
F_10 ( V_84 , V_35 -> V_85 ) ;
F_10 ( V_86 , V_35 -> V_87 ) ;
F_10 ( V_88 , V_35 -> V_89 ) ;
F_10 ( V_90 , V_35 -> V_91 ) ;
}
}
static void F_14 ( struct V_5 * V_8 , T_2 V_14 )
{
const struct V_9 * V_10 ;
for ( V_10 = V_8 -> V_26 ; V_10 -> V_27 ; V_10 ++ ) {
T_3 V_92 = F_11 ( V_10 , V_8 -> V_33 ) ;
T_3 V_29 = F_11 ( V_10 , V_14 ) ;
if ( V_92 == V_29 )
continue;
V_29 = F_6 ( V_10 , V_29 , V_92 ) ;
V_8 -> V_33 = F_4 ( V_10 , V_8 -> V_33 , V_29 ) ;
}
}
static int F_15 ( T_1 V_4 , int V_93 , T_2 V_22 , T_2 V_94 )
{
struct V_5 * V_2 = F_2 ( V_4 ) ;
F_9 ( ! V_2 ) ;
F_14 ( V_2 , V_22 ) ;
if ( ( V_94 & V_2 -> V_23 ) == ( V_22 & V_2 -> V_23 ) )
return 0 ;
F_16 ( L_1 ,
V_2 -> V_95 , V_94 , V_93 , V_22 ) ;
return 1 ;
}
void F_17 ( int V_93 ,
struct V_34 * V_35 ,
struct V_34 * V_94 )
{
int V_96 = 0 ;
V_96 |= F_15 ( V_36 , V_93 ,
V_35 -> V_37 , V_94 -> V_37 ) ;
V_96 |= F_15 ( V_38 , V_93 ,
V_35 -> V_39 , V_94 -> V_39 ) ;
V_96 |= F_15 ( V_40 , V_93 ,
V_35 -> V_41 , V_94 -> V_41 ) ;
V_96 |= F_15 ( V_42 , V_93 ,
V_35 -> V_43 , V_94 -> V_43 ) ;
V_96 |= F_15 ( V_44 , V_93 ,
V_35 -> V_45 , V_94 -> V_45 ) ;
V_96 |= F_15 ( V_46 , V_93 ,
V_35 -> V_47 , V_94 -> V_47 ) ;
V_96 |= F_15 ( V_48 , V_93 ,
V_35 -> V_49 , V_94 -> V_49 ) ;
V_96 |= F_15 ( V_50 , V_93 ,
V_35 -> V_51 , V_94 -> V_51 ) ;
V_96 |= F_15 ( V_52 , V_93 ,
V_35 -> V_53 , V_94 -> V_53 ) ;
V_96 |= F_15 ( V_54 , V_93 ,
V_35 -> V_55 , V_94 -> V_55 ) ;
V_96 |= F_15 ( V_56 , V_93 ,
V_35 -> V_57 , V_94 -> V_57 ) ;
V_96 |= F_15 ( V_58 , V_93 ,
V_35 -> V_59 , V_94 -> V_59 ) ;
if ( F_13 ( F_18 ( V_56 ) ) &&
F_13 ( V_35 -> V_57 ) ) {
V_96 |= F_15 ( V_60 , V_93 ,
V_35 -> V_61 , V_94 -> V_61 ) ;
V_96 |= F_15 ( V_62 , V_93 ,
V_35 -> V_63 , V_94 -> V_63 ) ;
V_96 |= F_15 ( V_64 , V_93 ,
V_35 -> V_65 , V_94 -> V_65 ) ;
V_96 |= F_15 ( V_66 , V_93 ,
V_35 -> V_67 , V_94 -> V_67 ) ;
V_96 |= F_15 ( V_68 , V_93 ,
V_35 -> V_69 , V_94 -> V_69 ) ;
V_96 |= F_15 ( V_70 , V_93 ,
V_35 -> V_71 , V_94 -> V_71 ) ;
V_96 |= F_15 ( V_72 , V_93 ,
V_35 -> V_73 , V_94 -> V_73 ) ;
V_96 |= F_15 ( V_74 , V_93 ,
V_35 -> V_75 , V_94 -> V_75 ) ;
V_96 |= F_15 ( V_76 , V_93 ,
V_35 -> V_77 , V_94 -> V_77 ) ;
V_96 |= F_15 ( V_78 , V_93 ,
V_35 -> V_79 , V_94 -> V_79 ) ;
V_96 |= F_15 ( V_80 , V_93 ,
V_35 -> V_81 , V_94 -> V_81 ) ;
V_96 |= F_15 ( V_82 , V_93 ,
V_35 -> V_83 , V_94 -> V_83 ) ;
V_96 |= F_15 ( V_84 , V_93 ,
V_35 -> V_85 , V_94 -> V_85 ) ;
V_96 |= F_15 ( V_86 , V_93 ,
V_35 -> V_87 , V_94 -> V_87 ) ;
V_96 |= F_15 ( V_88 , V_93 ,
V_35 -> V_89 , V_94 -> V_89 ) ;
V_96 |= F_15 ( V_90 , V_93 ,
V_35 -> V_91 , V_94 -> V_91 ) ;
}
F_19 ( V_96 , V_97 ,
L_2 ) ;
}
T_2 F_18 ( T_1 V_1 )
{
struct V_5 * V_2 = F_2 ( V_1 ) ;
F_9 ( ! V_2 ) ;
return V_2 -> V_33 ;
}
static T_2 F_20 ( T_1 V_4 )
{
switch ( V_4 ) {
F_21 ( V_82 ) ;
F_21 ( V_84 ) ;
F_21 ( V_60 ) ;
F_21 ( V_74 ) ;
F_21 ( V_76 ) ;
F_21 ( V_78 ) ;
F_21 ( V_80 ) ;
F_21 ( V_62 ) ;
F_21 ( V_64 ) ;
F_21 ( V_66 ) ;
F_21 ( V_68 ) ;
F_21 ( V_70 ) ;
F_21 ( V_72 ) ;
F_21 ( V_86 ) ;
F_21 ( V_88 ) ;
F_21 ( V_90 ) ;
F_21 ( V_56 ) ;
F_21 ( V_58 ) ;
F_21 ( V_42 ) ;
F_21 ( V_44 ) ;
F_21 ( V_50 ) ;
F_21 ( V_52 ) ;
F_21 ( V_54 ) ;
F_21 ( V_46 ) ;
F_21 ( V_48 ) ;
F_21 ( V_40 ) ;
F_21 ( V_36 ) ;
F_21 ( V_38 ) ;
default:
F_7 () ;
return 0 ;
}
}
static bool
F_22 ( T_2 V_8 , const struct V_98 * V_99 )
{
int V_22 = F_23 ( V_8 , V_99 -> V_100 , V_99 -> V_101 ) ;
return V_22 >= V_99 -> V_102 ;
}
static bool
F_24 ( const struct V_98 * V_99 , int V_103 )
{
T_2 V_22 ;
F_25 ( V_103 == V_104 && F_26 () ) ;
if ( V_103 == V_105 )
V_22 = F_18 ( V_99 -> V_21 ) ;
else
V_22 = F_20 ( V_99 -> V_21 ) ;
return F_22 ( V_22 , V_99 ) ;
}
static bool F_27 ( const struct V_98 * V_99 , int V_103 )
{
bool V_106 ;
if ( ! F_24 ( V_99 , V_103 ) )
return false ;
V_106 = F_28 () ;
if ( ! V_106 )
F_29 ( L_3 ,
V_99 -> V_107 ) ;
return V_106 ;
}
static bool F_30 ( const struct V_98 * V_99 , int V_108 )
{
T_1 V_109 = F_31 () ;
return F_32 ( V_109 , V_110 ,
F_33 ( 0 , 0 ) ,
F_33 ( 1 , V_111 ) ) ;
}
static bool F_34 ( const struct V_98 * V_99 , int V_108 )
{
return F_35 () ;
}
static bool F_36 ( const struct V_98 * V_99 ,
int V_108 )
{
T_5 V_112 = F_37 ( V_113 ) ;
return V_112 > F_38 ( V_114 - 2 , 0 ) && ! F_35 () ;
}
static bool F_39 ( const struct V_98 * V_99 , int V_108 )
{
T_2 V_115 = F_18 ( V_56 ) ;
return F_40 ( V_115 ,
V_116 ) < 0 ;
}
static void T_4 F_41 ( const struct V_98 * V_117 )
{
switch ( V_117 -> V_118 ) {
case V_119 :
V_120 |= V_117 -> V_121 ;
break;
#ifdef F_42
case V_122 :
V_123 |= ( T_1 ) V_117 -> V_121 ;
break;
case V_124 :
V_125 |= ( T_1 ) V_117 -> V_121 ;
break;
#endif
default:
F_25 ( 1 ) ;
break;
}
}
static bool F_43 ( const struct V_98 * V_117 )
{
bool V_126 ;
switch ( V_117 -> V_118 ) {
case V_119 :
V_126 = ( V_120 & V_117 -> V_121 ) != 0 ;
break;
#ifdef F_42
case V_122 :
V_126 = ( V_123 & ( T_1 ) V_117 -> V_121 ) != 0 ;
break;
case V_124 :
V_126 = ( V_125 & ( T_1 ) V_117 -> V_121 ) != 0 ;
break;
#endif
default:
F_25 ( 1 ) ;
V_126 = false ;
}
return V_126 ;
}
static void T_4 F_44 ( const struct V_98 * V_127 )
{
V_120 |= V_128 ;
for (; V_127 -> V_129 ; V_127 ++ )
if ( V_127 -> V_129 ( V_127 , V_127 -> V_130 ) )
F_41 ( V_127 ) ;
}
void F_45 ( const struct V_98 * V_131 ,
const char * V_35 )
{
for (; V_131 -> V_129 ; V_131 ++ ) {
if ( ! V_131 -> V_129 ( V_131 , V_131 -> V_130 ) )
continue;
if ( ! F_46 ( V_131 -> V_132 ) && V_131 -> V_107 )
F_47 ( L_4 , V_35 , V_131 -> V_107 ) ;
F_48 ( V_131 -> V_132 ) ;
}
}
void T_4 F_49 ( const struct V_98 * V_131 )
{
for (; V_131 -> V_129 ; V_131 ++ ) {
unsigned int V_133 = V_131 -> V_132 ;
if ( ! F_46 ( V_133 ) )
continue;
F_50 ( & V_134 [ V_133 ] ) ;
if ( V_131 -> V_135 ) {
F_51 ( V_131 -> V_135 , NULL , V_136 ) ;
}
}
}
static inline void F_52 ( void )
{
V_137 = true ;
}
static void F_53 ( void )
{
F_54 () ;
F_55 () ;
}
static void
F_56 ( const struct V_98 * V_131 )
{
for (; V_131 -> V_129 ; V_131 ++ )
if ( F_43 ( V_131 ) && ! V_131 -> V_129 ( V_131 , V_104 ) ) {
F_57 ( L_5 ,
F_58 () , V_131 -> V_107 ) ;
F_59 () ;
}
}
static void
F_60 ( const struct V_98 * V_131 )
{
for (; V_131 -> V_129 ; V_131 ++ ) {
if ( ! F_46 ( V_131 -> V_132 ) )
continue;
if ( ! V_131 -> V_129 ( V_131 , V_104 ) ) {
F_57 ( L_6 ,
F_58 () , V_131 -> V_107 ) ;
F_59 () ;
}
if ( V_131 -> V_135 )
V_131 -> V_135 ( NULL ) ;
}
}
static void F_61 ( void )
{
F_62 () ;
F_60 ( V_138 ) ;
F_56 ( V_139 ) ;
if ( F_63 () )
F_56 ( V_140 ) ;
}
void F_64 ( void )
{
F_53 () ;
if ( ! V_137 )
F_65 () ;
else
F_61 () ;
}
static void T_4 F_66 ( void )
{
F_45 ( V_138 , L_7 ) ;
F_49 ( V_138 ) ;
}
static void T_4 F_67 ( void )
{
F_50 ( & V_141 ) ;
}
static bool F_68 ( const struct V_98 * V_142 ,
unsigned int V_117 )
{
const struct V_98 * V_131 ;
if ( F_25 ( F_26 () ) )
return false ;
for ( V_131 = V_142 ; V_131 -> V_107 ; V_131 ++ )
if ( V_131 -> V_132 == V_117 && V_131 -> V_129 )
return V_131 -> V_129 ( V_131 , V_104 ) ;
return false ;
}
bool F_69 ( unsigned int V_117 )
{
return ( F_68 ( V_138 , V_117 ) ||
F_68 ( V_143 , V_117 ) ) ;
}
void T_4 F_70 ( void )
{
T_1 V_144 ;
int V_145 ;
F_66 () ;
F_71 () ;
F_67 () ;
F_44 ( V_139 ) ;
if ( F_63 () )
F_44 ( V_140 ) ;
F_52 () ;
V_144 = F_72 () ;
V_145 = F_73 () ;
if ( ! V_144 )
F_16 ( L_8 ,
V_145 ) ;
if ( V_146 < V_145 )
F_16 ( L_9 ,
V_146 , V_145 ) ;
}
static bool T_6
F_74 ( const struct V_98 * V_99 , int V_108 )
{
return ( F_75 ( V_147 ) && ! F_75 ( V_148 ) ) ;
}
static inline bool T_7 F_76 ( T_1 V_1 )
{
return ( F_77 ( V_1 ) == 0x3 &&
F_78 ( V_1 ) == 0x0 &&
F_79 ( V_1 ) == 0x0 &&
( F_80 ( V_1 ) == 0 ||
( ( F_80 ( V_1 ) >= 4 ) && ( F_80 ( V_1 ) <= 7 ) ) ) ) ;
}
static inline int F_81 ( T_1 V_1 , T_2 * V_149 )
{
switch ( V_1 ) {
case V_150 :
* V_149 = F_31 () ;
break;
case V_151 :
* V_149 = V_152 ;
break;
case V_153 :
* V_149 = 0 ;
break;
default:
return - V_154 ;
}
return 0 ;
}
static int F_82 ( T_1 V_1 , T_2 * V_149 )
{
struct V_5 * V_2 ;
if ( ! F_76 ( V_1 ) )
return - V_154 ;
if ( F_80 ( V_1 ) == 0 )
return F_81 ( V_1 , V_149 ) ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 )
* V_149 = F_83 ( V_2 ) ;
else
* V_149 = 0 ;
return 0 ;
}
static int F_84 ( struct V_155 * V_156 , T_1 V_157 )
{
int V_126 ;
T_1 V_21 , V_158 ;
T_2 V_22 ;
V_21 = ( T_1 ) F_85 ( V_159 , V_157 ) << 5 ;
V_126 = F_82 ( V_21 , & V_22 ) ;
if ( ! V_126 ) {
V_158 = F_86 ( V_160 , V_157 ) ;
F_87 ( V_156 , V_158 , V_22 ) ;
V_156 -> V_161 += 4 ;
}
return V_126 ;
}
static int T_4 F_88 ( void )
{
F_89 ( & V_162 ) ;
return 0 ;
}
