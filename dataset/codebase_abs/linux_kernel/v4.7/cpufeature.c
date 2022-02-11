static int F_1 ( const void * V_1 , const void * V_2 )
{
return ( int ) ( unsigned long ) V_1 - ( int ) ( ( const struct V_3 * ) V_2 ) -> V_4 ;
}
static struct V_3 * F_2 ( T_1 V_4 )
{
return bsearch ( ( const void * ) ( unsigned long ) V_4 ,
V_5 ,
F_3 ( V_5 ) ,
sizeof( V_5 [ 0 ] ) ,
F_1 ) ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_3 V_8 , T_3 V_9 )
{
T_2 V_10 = F_5 ( V_7 ) ;
V_8 &= ~ V_10 ;
V_8 |= ( V_9 << V_7 -> V_11 ) & V_10 ;
return V_8 ;
}
static T_3 F_6 ( struct V_6 * V_7 , T_3 V_12 , T_3 V_13 )
{
T_3 V_14 = 0 ;
switch ( V_7 -> type ) {
case V_15 :
V_14 = V_7 -> V_16 ;
break;
case V_17 :
V_14 = V_12 < V_13 ? V_12 : V_13 ;
break;
case V_18 :
V_14 = V_12 > V_13 ? V_12 : V_13 ;
break;
default:
F_7 () ;
}
return V_14 ;
}
static int T_4 F_8 ( const void * V_19 , const void * V_20 )
{
return ( ( const struct V_3 * ) V_19 ) -> V_4 -
( ( const struct V_3 * ) V_20 ) -> V_4 ;
}
static void T_4 F_9 ( void * V_19 , void * V_20 , int V_21 )
{
struct V_3 V_22 = * (struct V_3 * ) V_19 ;
* (struct V_3 * ) V_19 = * (struct V_3 * ) V_20 ;
* (struct V_3 * ) V_20 = V_22 ;
}
static void T_4 F_10 ( void )
{
F_11 ( V_5 ,
F_3 ( V_5 ) ,
sizeof( V_5 [ 0 ] ) ,
F_8 ,
F_9 ) ;
}
static void T_4 F_12 ( T_1 V_23 , T_2 V_12 )
{
T_2 V_24 = 0 ;
T_2 V_25 = ~ 0x0ULL ;
struct V_6 * V_7 ;
struct V_3 * V_8 = F_2 ( V_23 ) ;
F_13 ( ! V_8 ) ;
for ( V_7 = V_8 -> V_26 ; V_7 -> V_27 ; V_7 ++ ) {
T_3 V_28 = F_14 ( V_7 , V_12 ) ;
V_24 = F_4 ( V_7 , V_24 , V_28 ) ;
if ( ! V_7 -> V_29 )
V_25 &= ~ F_5 ( V_7 ) ;
}
V_8 -> V_30 = V_24 ;
V_8 -> V_25 = V_25 ;
}
void T_4 F_15 ( struct V_31 * V_32 )
{
F_10 () ;
F_12 ( V_33 , V_32 -> V_34 ) ;
F_12 ( V_35 , V_32 -> V_36 ) ;
F_12 ( V_37 , V_32 -> V_38 ) ;
F_12 ( V_39 , V_32 -> V_40 ) ;
F_12 ( V_41 , V_32 -> V_42 ) ;
F_12 ( V_43 , V_32 -> V_44 ) ;
F_12 ( V_45 , V_32 -> V_46 ) ;
F_12 ( V_47 , V_32 -> V_48 ) ;
F_12 ( V_49 , V_32 -> V_50 ) ;
F_12 ( V_51 , V_32 -> V_52 ) ;
F_12 ( V_53 , V_32 -> V_54 ) ;
F_12 ( V_55 , V_32 -> V_56 ) ;
if ( F_16 ( V_32 -> V_54 ) ) {
F_12 ( V_57 , V_32 -> V_58 ) ;
F_12 ( V_59 , V_32 -> V_60 ) ;
F_12 ( V_61 , V_32 -> V_62 ) ;
F_12 ( V_63 , V_32 -> V_64 ) ;
F_12 ( V_65 , V_32 -> V_66 ) ;
F_12 ( V_67 , V_32 -> V_68 ) ;
F_12 ( V_69 , V_32 -> V_70 ) ;
F_12 ( V_71 , V_32 -> V_72 ) ;
F_12 ( V_73 , V_32 -> V_74 ) ;
F_12 ( V_75 , V_32 -> V_76 ) ;
F_12 ( V_77 , V_32 -> V_78 ) ;
F_12 ( V_79 , V_32 -> V_80 ) ;
F_12 ( V_81 , V_32 -> V_82 ) ;
F_12 ( V_83 , V_32 -> V_84 ) ;
F_12 ( V_85 , V_32 -> V_86 ) ;
F_12 ( V_87 , V_32 -> V_88 ) ;
}
}
static void F_17 ( struct V_3 * V_8 , T_2 V_12 )
{
struct V_6 * V_7 ;
for ( V_7 = V_8 -> V_26 ; V_7 -> V_27 ; V_7 ++ ) {
T_3 V_89 = F_14 ( V_7 , V_8 -> V_30 ) ;
T_3 V_28 = F_14 ( V_7 , V_12 ) ;
if ( V_89 == V_28 )
continue;
V_28 = F_6 ( V_7 , V_28 , V_89 ) ;
V_8 -> V_30 = F_4 ( V_7 , V_8 -> V_30 , V_28 ) ;
}
}
static int F_18 ( T_1 V_4 , int V_90 , T_2 V_24 , T_2 V_91 )
{
struct V_3 * V_2 = F_2 ( V_4 ) ;
F_13 ( ! V_2 ) ;
F_17 ( V_2 , V_24 ) ;
if ( ( V_91 & V_2 -> V_25 ) == ( V_24 & V_2 -> V_25 ) )
return 0 ;
F_19 ( L_1 ,
V_2 -> V_92 , V_91 , V_90 , V_24 ) ;
return 1 ;
}
void F_20 ( int V_90 ,
struct V_31 * V_32 ,
struct V_31 * V_91 )
{
int V_93 = 0 ;
V_93 |= F_18 ( V_33 , V_90 ,
V_32 -> V_34 , V_91 -> V_34 ) ;
V_93 |= F_18 ( V_35 , V_90 ,
V_32 -> V_36 , V_91 -> V_36 ) ;
V_93 |= F_18 ( V_37 , V_90 ,
V_32 -> V_38 , V_91 -> V_38 ) ;
V_93 |= F_18 ( V_39 , V_90 ,
V_32 -> V_40 , V_91 -> V_40 ) ;
V_93 |= F_18 ( V_41 , V_90 ,
V_32 -> V_42 , V_91 -> V_42 ) ;
V_93 |= F_18 ( V_43 , V_90 ,
V_32 -> V_44 , V_91 -> V_44 ) ;
V_93 |= F_18 ( V_45 , V_90 ,
V_32 -> V_46 , V_91 -> V_46 ) ;
V_93 |= F_18 ( V_47 , V_90 ,
V_32 -> V_48 , V_91 -> V_48 ) ;
V_93 |= F_18 ( V_49 , V_90 ,
V_32 -> V_50 , V_91 -> V_50 ) ;
V_93 |= F_18 ( V_51 , V_90 ,
V_32 -> V_52 , V_91 -> V_52 ) ;
V_93 |= F_18 ( V_53 , V_90 ,
V_32 -> V_54 , V_91 -> V_54 ) ;
V_93 |= F_18 ( V_55 , V_90 ,
V_32 -> V_56 , V_91 -> V_56 ) ;
if ( F_16 ( F_21 ( V_53 ) ) &&
F_16 ( V_32 -> V_54 ) ) {
V_93 |= F_18 ( V_57 , V_90 ,
V_32 -> V_58 , V_91 -> V_58 ) ;
V_93 |= F_18 ( V_59 , V_90 ,
V_32 -> V_60 , V_91 -> V_60 ) ;
V_93 |= F_18 ( V_61 , V_90 ,
V_32 -> V_62 , V_91 -> V_62 ) ;
V_93 |= F_18 ( V_63 , V_90 ,
V_32 -> V_64 , V_91 -> V_64 ) ;
V_93 |= F_18 ( V_65 , V_90 ,
V_32 -> V_66 , V_91 -> V_66 ) ;
V_93 |= F_18 ( V_67 , V_90 ,
V_32 -> V_68 , V_91 -> V_68 ) ;
V_93 |= F_18 ( V_69 , V_90 ,
V_32 -> V_70 , V_91 -> V_70 ) ;
V_93 |= F_18 ( V_71 , V_90 ,
V_32 -> V_72 , V_91 -> V_72 ) ;
V_93 |= F_18 ( V_73 , V_90 ,
V_32 -> V_74 , V_91 -> V_74 ) ;
V_93 |= F_18 ( V_75 , V_90 ,
V_32 -> V_76 , V_91 -> V_76 ) ;
V_93 |= F_18 ( V_77 , V_90 ,
V_32 -> V_78 , V_91 -> V_78 ) ;
V_93 |= F_18 ( V_79 , V_90 ,
V_32 -> V_80 , V_91 -> V_80 ) ;
V_93 |= F_18 ( V_81 , V_90 ,
V_32 -> V_82 , V_91 -> V_82 ) ;
V_93 |= F_18 ( V_83 , V_90 ,
V_32 -> V_84 , V_91 -> V_84 ) ;
V_93 |= F_18 ( V_85 , V_90 ,
V_32 -> V_86 , V_91 -> V_86 ) ;
V_93 |= F_18 ( V_87 , V_90 ,
V_32 -> V_88 , V_91 -> V_88 ) ;
}
F_22 ( V_93 , V_94 ,
L_2 ) ;
}
T_2 F_21 ( T_1 V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
F_13 ( ! V_2 ) ;
return V_2 -> V_30 ;
}
static T_2 F_23 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_79 : return F_24 ( V_95 ) ;
case V_81 : return F_24 ( V_96 ) ;
case V_57 : return F_24 ( V_97 ) ;
case V_71 : return F_24 ( V_98 ) ;
case V_73 : return F_24 ( V_99 ) ;
case V_75 : return F_24 ( V_100 ) ;
case V_77 : return F_24 ( V_101 ) ;
case V_59 : return F_24 ( V_102 ) ;
case V_61 : return F_24 ( V_103 ) ;
case V_63 : return F_24 ( V_104 ) ;
case V_65 : return F_24 ( V_105 ) ;
case V_67 : return F_24 ( V_106 ) ;
case V_69 : return F_24 ( V_106 ) ;
case V_83 : return F_24 ( V_107 ) ;
case V_85 : return F_24 ( V_108 ) ;
case V_87 : return F_24 ( V_109 ) ;
case V_53 : return F_24 ( V_110 ) ;
case V_55 : return F_24 ( V_110 ) ;
case V_39 : return F_24 ( V_111 ) ;
case V_41 : return F_24 ( V_111 ) ;
case V_47 : return F_24 ( V_112 ) ;
case V_49 : return F_24 ( V_113 ) ;
case V_51 : return F_24 ( V_114 ) ;
case V_43 : return F_24 ( V_115 ) ;
case V_45 : return F_24 ( V_116 ) ;
case V_37 : return F_24 ( V_117 ) ;
case V_33 : return F_24 ( V_118 ) ;
case V_35 : return F_24 ( V_119 ) ;
default:
F_7 () ;
return 0 ;
}
}
static bool
F_25 ( T_2 V_8 , const struct V_120 * V_121 )
{
int V_24 = F_26 ( V_8 , V_121 -> V_122 , V_121 -> V_123 ) ;
return V_24 >= V_121 -> V_124 ;
}
static bool
F_27 ( const struct V_120 * V_121 , int V_125 )
{
T_2 V_24 ;
F_28 ( V_125 == V_126 && F_29 () ) ;
if ( V_125 == V_127 )
V_24 = F_21 ( V_121 -> V_23 ) ;
else
V_24 = F_23 ( V_121 -> V_23 ) ;
return F_25 ( V_24 , V_121 ) ;
}
static bool F_30 ( const struct V_120 * V_121 , int V_125 )
{
bool V_128 ;
if ( ! F_27 ( V_121 , V_125 ) )
return false ;
V_128 = F_31 () ;
if ( ! V_128 )
F_32 ( L_3 ,
V_121 -> V_129 ) ;
return V_128 ;
}
static bool F_33 ( const struct V_120 * V_121 , int V_130 )
{
T_1 V_131 = F_34 () ;
T_1 V_132 , V_133 ;
V_132 = 0 ;
V_133 = ( 1 << V_134 ) | V_135 ;
return F_35 ( V_131 , V_136 , V_132 , V_133 ) ;
}
static bool F_36 ( const struct V_120 * V_121 , int V_130 )
{
return F_37 () ;
}
static void T_4 F_38 ( const struct V_120 * V_137 )
{
switch ( V_137 -> V_138 ) {
case V_139 :
V_140 |= V_137 -> V_141 ;
break;
#ifdef F_39
case V_142 :
V_143 |= ( T_1 ) V_137 -> V_141 ;
break;
case V_144 :
V_145 |= ( T_1 ) V_137 -> V_141 ;
break;
#endif
default:
F_28 ( 1 ) ;
break;
}
}
static bool F_40 ( const struct V_120 * V_137 )
{
bool V_146 ;
switch ( V_137 -> V_138 ) {
case V_139 :
V_146 = ( V_140 & V_137 -> V_141 ) != 0 ;
break;
#ifdef F_39
case V_142 :
V_146 = ( V_143 & ( T_1 ) V_137 -> V_141 ) != 0 ;
break;
case V_144 :
V_146 = ( V_145 & ( T_1 ) V_137 -> V_141 ) != 0 ;
break;
#endif
default:
F_28 ( 1 ) ;
V_146 = false ;
}
return V_146 ;
}
static void T_4 F_41 ( const struct V_120 * V_147 )
{
for (; V_147 -> V_148 ; V_147 ++ )
if ( V_147 -> V_148 ( V_147 , V_147 -> V_149 ) )
F_38 ( V_147 ) ;
}
void F_42 ( const struct V_120 * V_150 ,
const char * V_32 )
{
for (; V_150 -> V_148 ; V_150 ++ ) {
if ( ! V_150 -> V_148 ( V_150 , V_150 -> V_149 ) )
continue;
if ( ! F_43 ( V_150 -> V_151 ) && V_150 -> V_129 )
F_44 ( L_4 , V_32 , V_150 -> V_129 ) ;
F_45 ( V_150 -> V_151 ) ;
}
}
static void T_4
F_46 ( const struct V_120 * V_150 )
{
for (; V_150 -> V_148 ; V_150 ++ )
if ( V_150 -> V_152 && F_43 ( V_150 -> V_151 ) )
F_47 ( V_150 -> V_152 , NULL , true ) ;
}
static inline void F_48 ( void )
{
V_153 = true ;
}
static void F_49 ( void )
{
F_50 () ;
F_51 () ;
}
static void
F_52 ( const struct V_120 * V_150 )
{
for (; V_150 -> V_148 ; V_150 ++ )
if ( F_40 ( V_150 ) && ! V_150 -> V_148 ( V_150 , V_126 ) ) {
F_53 ( L_5 ,
F_54 () , V_150 -> V_129 ) ;
F_55 () ;
}
}
static void
F_56 ( const struct V_120 * V_150 )
{
for (; V_150 -> V_148 ; V_150 ++ ) {
if ( ! F_43 ( V_150 -> V_151 ) )
continue;
if ( ! V_150 -> V_148 ( V_150 , V_126 ) ) {
F_53 ( L_6 ,
F_54 () , V_150 -> V_129 ) ;
F_55 () ;
}
if ( V_150 -> V_152 )
V_150 -> V_152 ( NULL ) ;
}
}
void F_57 ( void )
{
F_49 () ;
if ( ! V_153 )
return;
F_58 () ;
F_56 ( V_154 ) ;
F_52 ( V_155 ) ;
if ( F_59 () )
F_52 ( V_156 ) ;
}
static void T_4 F_60 ( void )
{
F_42 ( V_154 , L_7 ) ;
F_46 ( V_154 ) ;
}
bool F_61 ( unsigned int V_137 )
{
const struct V_120 * V_150 ;
if ( F_28 ( F_29 () ) )
return false ;
for ( V_150 = V_154 ; V_150 -> V_129 ; V_150 ++ )
if ( V_150 -> V_151 == V_137 && V_150 -> V_148 )
return V_150 -> V_148 ( V_150 , V_126 ) ;
return false ;
}
void T_4 F_62 ( void )
{
T_1 V_157 ;
int V_158 ;
F_60 () ;
F_41 ( V_155 ) ;
if ( F_59 () )
F_41 ( V_156 ) ;
F_48 () ;
V_157 = F_63 () ;
V_158 = F_64 () ;
if ( ! V_157 )
F_19 ( L_8 ,
V_158 ) ;
if ( V_159 < V_158 )
F_19 ( L_9 ,
V_159 , V_158 ) ;
}
static bool T_5
F_65 ( const struct V_120 * V_121 , int V_130 )
{
return ( F_43 ( V_160 ) && ! F_43 ( V_161 ) ) ;
}
