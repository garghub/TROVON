static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static int F_3 ( void )
{
#ifdef F_4
if ( V_5 )
return F_5 ( & V_6 ) || F_5 ( & V_7 ) ;
#endif
return 1 ;
}
static inline T_1 F_6 ( T_1 V_8 )
{
return V_8 ? 1 << ( V_8 - 1 ) : 0 ;
}
int F_7 ( struct V_9 * V_10 )
{
if ( F_8 ( V_10 -> V_11 -> type != V_12 ) )
return - V_13 ;
F_9 ( & V_14 ) ;
F_10 ( & V_10 -> V_15 , & V_16 ) ;
F_11 ( & V_14 ) ;
if ( V_10 -> V_17 )
F_12 ( V_10 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
bool V_18 = false ;
struct V_9 * V_19 ;
F_9 ( & V_14 ) ;
F_14 (tmp, &netlink_tap_all, list) {
if ( V_10 == V_19 ) {
F_15 ( & V_10 -> V_15 ) ;
V_18 = true ;
goto V_20;
}
}
F_16 ( L_1 , V_10 ) ;
V_20:
F_11 ( & V_14 ) ;
if ( V_18 && V_10 -> V_17 )
F_17 ( V_10 -> V_17 ) ;
return V_18 ? 0 : - V_21 ;
}
int F_18 ( struct V_9 * V_10 )
{
int V_22 ;
V_22 = F_13 ( V_10 ) ;
F_19 () ;
return V_22 ;
}
static bool F_20 ( const struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
switch ( V_2 -> V_25 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
return true ;
}
return false ;
}
static int F_21 ( struct V_23 * V_24 ,
struct V_34 * V_11 )
{
struct V_23 * V_35 ;
struct V_1 * V_2 = V_24 -> V_2 ;
int V_22 = - V_36 ;
F_22 ( V_11 ) ;
V_35 = F_23 ( V_24 , V_37 ) ;
if ( V_35 ) {
V_35 -> V_11 = V_11 ;
V_35 -> V_38 = F_24 ( ( V_39 ) V_2 -> V_25 ) ;
V_35 -> V_40 = F_1 ( V_2 ) ?
V_41 : V_42 ;
F_25 ( V_35 ) ;
V_22 = F_26 ( V_35 ) ;
if ( F_8 ( V_22 > 0 ) )
V_22 = F_27 ( V_22 ) ;
}
F_28 ( V_11 ) ;
return V_22 ;
}
static void F_29 ( struct V_23 * V_24 )
{
int V_22 ;
struct V_9 * V_19 ;
if ( ! F_20 ( V_24 ) )
return;
F_30 (tmp, &netlink_tap_all, list) {
V_22 = F_21 ( V_24 , V_19 -> V_11 ) ;
if ( F_8 ( V_22 ) )
break;
}
}
static void F_31 ( struct V_23 * V_24 )
{
F_32 () ;
if ( F_8 ( ! F_33 ( & V_16 ) ) )
F_29 ( V_24 ) ;
F_34 () ;
}
static void F_35 ( struct V_1 * V_43 , struct V_1 * V_44 ,
struct V_23 * V_24 )
{
if ( ! ( F_1 ( V_43 ) && F_1 ( V_44 ) ) )
F_31 ( V_24 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( ! ( V_46 -> V_3 & V_47 ) ) {
if ( ! F_37 ( V_48 , & F_2 ( V_2 ) -> V_49 ) ) {
V_2 -> V_50 = V_51 ;
V_2 -> V_52 ( V_2 ) ;
}
}
F_38 ( & V_2 -> V_53 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( F_40 ( & V_2 -> V_54 ) )
F_41 ( V_48 , & V_46 -> V_49 ) ;
if ( ! F_42 ( V_48 , & V_46 -> V_49 ) )
F_43 ( & V_46 -> V_55 ) ;
}
static bool F_44 ( const struct V_23 * V_24 )
{
return F_45 ( V_24 ) . V_3 & V_56 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_57 . V_58 != NULL ;
}
static bool F_47 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_59 . V_58 != NULL ;
}
static void F_48 ( void * * V_58 , unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
if ( V_58 [ V_62 ] != NULL ) {
if ( F_49 ( V_58 [ V_62 ] ) )
F_50 ( V_58 [ V_62 ] ) ;
else
F_51 ( ( unsigned long ) V_58 [ V_62 ] , V_60 ) ;
}
}
F_52 ( V_58 ) ;
}
static void * F_53 ( unsigned long V_60 )
{
void * V_63 ;
T_2 V_64 = V_65 | V_66 | V_67 |
V_68 | V_69 ;
V_63 = ( void * ) F_54 ( V_64 , V_60 ) ;
if ( V_63 != NULL )
return V_63 ;
V_63 = F_55 ( ( 1 << V_60 ) * V_70 ) ;
if ( V_63 != NULL )
return V_63 ;
V_64 &= ~ V_69 ;
return ( void * ) F_54 ( V_64 , V_60 ) ;
}
static void * * F_56 ( struct V_45 * V_46 ,
struct V_71 * V_72 , unsigned int V_60 )
{
unsigned int V_73 = V_72 -> V_74 ;
unsigned int V_62 ;
void * * V_58 ;
V_58 = F_57 ( V_73 , sizeof( void * ) , V_65 ) ;
if ( V_58 == NULL )
return NULL ;
for ( V_62 = 0 ; V_62 < V_73 ; V_62 ++ ) {
V_58 [ V_62 ] = F_53 ( V_60 ) ;
if ( V_58 [ V_62 ] == NULL )
goto V_75;
}
return V_58 ;
V_75:
F_48 ( V_58 , V_60 , V_73 ) ;
return NULL ;
}
static int F_58 ( struct V_1 * V_2 , struct V_71 * V_72 ,
bool V_76 , bool V_59 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
void * * V_58 = NULL ;
unsigned int V_60 = 0 ;
int V_81 ;
V_78 = V_59 ? & V_46 -> V_59 : & V_46 -> V_57 ;
V_80 = V_59 ? & V_2 -> V_82 : & V_2 -> V_54 ;
if ( ! V_76 ) {
if ( F_59 ( & V_46 -> V_83 ) )
return - V_84 ;
if ( F_59 ( & V_78 -> V_85 ) )
return - V_84 ;
}
if ( V_72 -> V_74 ) {
if ( V_78 -> V_58 != NULL )
return - V_84 ;
if ( ( int ) V_72 -> V_86 <= 0 )
return - V_13 ;
if ( ! F_60 ( V_72 -> V_86 ) )
return - V_13 ;
if ( V_72 -> V_87 < V_88 )
return - V_13 ;
if ( ! F_61 ( V_72 -> V_87 , V_89 ) )
return - V_13 ;
V_78 -> V_90 = V_72 -> V_86 /
V_72 -> V_87 ;
if ( V_78 -> V_90 == 0 )
return - V_13 ;
if ( V_78 -> V_90 * V_72 -> V_74 !=
V_72 -> V_91 )
return - V_13 ;
V_60 = F_62 ( V_72 -> V_86 ) ;
V_58 = F_56 ( V_46 , V_72 , V_60 ) ;
if ( V_58 == NULL )
return - V_36 ;
} else {
if ( V_72 -> V_91 )
return - V_13 ;
}
V_81 = - V_84 ;
F_63 ( & V_46 -> V_92 ) ;
if ( V_76 || F_59 ( & V_46 -> V_83 ) == 0 ) {
V_81 = 0 ;
F_64 ( & V_80 -> V_93 ) ;
V_78 -> V_94 = V_72 -> V_91 - 1 ;
V_78 -> V_95 = 0 ;
V_78 -> V_96 = V_72 -> V_87 ;
V_78 -> V_97 = V_72 -> V_86 / V_70 ;
F_65 ( V_78 -> V_98 , V_72 -> V_74 ) ;
F_65 ( V_78 -> V_99 , V_60 ) ;
F_65 ( V_78 -> V_58 , V_58 ) ;
F_66 ( V_80 ) ;
F_67 ( & V_80 -> V_93 ) ;
F_68 ( F_59 ( & V_46 -> V_83 ) ) ;
}
F_69 ( & V_46 -> V_92 ) ;
if ( V_58 )
F_48 ( V_58 , V_60 , V_72 -> V_74 ) ;
return V_81 ;
}
static void F_70 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_38 ( & F_2 ( V_2 ) -> V_83 ) ;
}
static void F_71 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_72 ( & F_2 ( V_2 ) -> V_83 ) ;
}
static int F_73 ( struct V_102 * V_102 , struct V_104 * V_1 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
unsigned long V_106 , V_107 , V_108 ;
unsigned int V_62 ;
int V_81 = - V_13 ;
if ( V_101 -> V_109 )
return - V_13 ;
F_63 ( & V_46 -> V_92 ) ;
V_108 = 0 ;
for ( V_78 = & V_46 -> V_57 ; V_78 <= & V_46 -> V_59 ; V_78 ++ ) {
if ( V_78 -> V_58 == NULL )
continue;
V_108 += V_78 -> V_98 * V_78 -> V_97 * V_70 ;
}
if ( V_108 == 0 )
goto V_20;
V_107 = V_101 -> V_110 - V_101 -> V_111 ;
if ( V_107 != V_108 )
goto V_20;
V_106 = V_101 -> V_111 ;
for ( V_78 = & V_46 -> V_57 ; V_78 <= & V_46 -> V_59 ; V_78 ++ ) {
if ( V_78 -> V_58 == NULL )
continue;
for ( V_62 = 0 ; V_62 < V_78 -> V_98 ; V_62 ++ ) {
struct V_112 * V_112 ;
void * V_113 = V_78 -> V_58 [ V_62 ] ;
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < V_78 -> V_97 ; V_114 ++ ) {
V_112 = F_74 ( V_113 ) ;
V_81 = F_75 ( V_101 , V_106 , V_112 ) ;
if ( V_81 < 0 )
goto V_20;
V_106 += V_70 ;
V_113 += V_70 ;
}
}
}
F_38 ( & V_46 -> V_83 ) ;
V_101 -> V_115 = & V_116 ;
V_81 = 0 ;
V_20:
F_69 ( & V_46 -> V_92 ) ;
return V_81 ;
}
static void F_76 ( const struct V_117 * V_118 )
{
#if V_119 == 1
struct V_112 * V_120 , * V_121 ;
V_120 = F_74 ( V_118 + V_70 ) ;
V_121 = F_74 ( ( void * ) V_118 + V_88 + V_118 -> V_122 - 1 ) ;
while ( V_120 <= V_121 ) {
F_77 ( V_120 ) ;
V_120 ++ ;
}
#endif
}
static enum V_123 F_78 ( const struct V_117 * V_118 )
{
F_79 () ;
F_77 ( F_74 ( V_118 ) ) ;
return V_118 -> V_124 ;
}
static void F_80 ( struct V_117 * V_118 ,
enum V_123 V_125 )
{
V_118 -> V_124 = V_125 ;
F_77 ( F_74 ( V_118 ) ) ;
F_81 () ;
}
static struct V_117 *
F_82 ( const struct V_77 * V_78 , unsigned int V_126 )
{
unsigned int V_127 , V_128 ;
V_127 = V_126 / V_78 -> V_90 ;
V_128 = V_126 % V_78 -> V_90 ;
return V_78 -> V_58 [ V_127 ] + ( V_128 * V_78 -> V_96 ) ;
}
static struct V_117 *
F_83 ( const struct V_77 * V_78 , unsigned int V_126 ,
enum V_123 V_125 )
{
struct V_117 * V_118 ;
V_118 = F_82 ( V_78 , V_126 ) ;
if ( F_78 ( V_118 ) != V_125 )
return NULL ;
return V_118 ;
}
static struct V_117 *
F_84 ( const struct V_77 * V_78 ,
enum V_123 V_125 )
{
return F_83 ( V_78 , V_78 -> V_95 , V_125 ) ;
}
static struct V_117 *
F_85 ( const struct V_77 * V_78 ,
enum V_123 V_125 )
{
unsigned int V_129 ;
V_129 = V_78 -> V_95 ? V_78 -> V_95 - 1 : V_78 -> V_94 ;
return F_83 ( V_78 , V_129 , V_125 ) ;
}
static void F_86 ( struct V_77 * V_78 )
{
V_78 -> V_95 = V_78 -> V_95 != V_78 -> V_94 ? V_78 -> V_95 + 1 : 0 ;
}
static void F_87 ( struct V_77 * V_78 )
{
unsigned int V_95 = V_78 -> V_95 , V_126 = V_95 ;
const struct V_117 * V_118 ;
do {
V_118 = F_82 ( V_78 , V_126 ) ;
if ( V_118 -> V_124 == V_130 )
break;
if ( V_118 -> V_124 != V_131 )
break;
F_86 ( V_78 ) ;
} while ( V_78 -> V_95 != V_95 );
}
static bool F_88 ( struct V_45 * V_46 )
{
struct V_77 * V_78 = & V_46 -> V_57 ;
struct V_117 * V_118 ;
unsigned int V_132 ;
V_118 = F_84 ( V_78 , V_130 ) ;
if ( V_118 == NULL )
return false ;
V_132 = V_78 -> V_95 + V_78 -> V_94 / 2 ;
if ( V_132 > V_78 -> V_94 )
V_132 -= V_78 -> V_94 ;
V_118 = F_82 ( V_78 , V_132 ) ;
return V_118 -> V_124 == V_130 ;
}
static unsigned int F_89 ( struct V_102 * V_102 , struct V_104 * V_1 ,
T_3 * V_55 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_133 ;
int V_81 ;
if ( V_46 -> V_57 . V_58 != NULL ) {
while ( V_46 -> V_134 && F_88 ( V_46 ) ) {
V_81 = F_90 ( V_2 ) ;
if ( V_81 < 0 ) {
V_2 -> V_50 = - V_81 ;
V_2 -> V_52 ( V_2 ) ;
break;
}
}
F_39 ( V_2 ) ;
}
V_133 = F_91 ( V_102 , V_1 , V_55 ) ;
F_64 ( & V_2 -> V_54 . V_93 ) ;
if ( V_46 -> V_57 . V_58 ) {
F_87 ( & V_46 -> V_57 ) ;
if ( ! F_85 ( & V_46 -> V_57 , V_130 ) )
V_133 |= V_135 | V_136 ;
}
F_67 ( & V_2 -> V_54 . V_93 ) ;
F_64 ( & V_2 -> V_82 . V_93 ) ;
if ( V_46 -> V_59 . V_58 ) {
if ( F_84 ( & V_46 -> V_59 , V_130 ) )
V_133 |= V_137 | V_138 ;
}
F_67 ( & V_2 -> V_82 . V_93 ) ;
return V_133 ;
}
static struct V_117 * F_92 ( struct V_23 * V_24 )
{
return (struct V_117 * ) ( V_24 -> V_95 - V_88 ) ;
}
static void F_93 ( struct V_23 * V_24 , struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_117 * V_118 )
{
unsigned int V_107 ;
void * V_139 ;
V_107 = V_78 -> V_96 - V_88 ;
V_139 = ( void * ) V_118 + V_88 ;
V_24 -> V_95 = V_139 ;
V_24 -> V_139 = V_139 ;
F_94 ( V_24 ) ;
V_24 -> V_140 = V_24 -> V_141 + V_107 ;
V_24 -> V_61 = 0 ;
V_24 -> V_142 = V_143 ;
F_45 ( V_24 ) . V_3 |= V_56 ;
F_45 ( V_24 ) . V_2 = V_2 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_144 * V_145 ,
T_1 V_146 , T_1 V_147 ,
struct V_148 * V_149 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
struct V_117 * V_118 ;
struct V_23 * V_24 ;
unsigned int V_150 ;
bool V_151 = true ;
int V_81 = 0 , V_61 = 0 ;
if ( F_96 ( & V_2 -> V_152 -> V_102 -> V_153 ) > 1 ||
F_59 ( & V_46 -> V_83 ) > 1 )
V_151 = false ;
F_63 ( & V_46 -> V_92 ) ;
V_78 = & V_46 -> V_59 ;
V_150 = V_78 -> V_96 - V_88 ;
do {
V_118 = F_84 ( V_78 , V_154 ) ;
if ( V_118 == NULL ) {
if ( ! ( V_145 -> V_155 & V_156 ) &&
F_59 ( & V_46 -> V_59 . V_85 ) )
F_97 () ;
continue;
}
if ( V_118 -> V_122 > V_150 ) {
V_81 = - V_13 ;
goto V_20;
}
F_76 ( V_118 ) ;
if ( F_98 ( V_146 == 0 && V_147 == 0 && V_151 ) ) {
V_24 = F_99 ( V_65 ) ;
if ( V_24 == NULL ) {
V_81 = - V_51 ;
goto V_20;
}
F_100 ( V_2 ) ;
F_93 ( V_24 , V_2 , V_78 , V_118 ) ;
F_45 ( V_24 ) . V_3 |= V_157 ;
F_101 ( V_24 , V_118 -> V_122 ) ;
F_80 ( V_118 , V_158 ) ;
F_38 ( & V_78 -> V_85 ) ;
} else {
V_24 = F_102 ( V_118 -> V_122 , V_65 ) ;
if ( V_24 == NULL ) {
V_81 = - V_51 ;
goto V_20;
}
F_101 ( V_24 , V_118 -> V_122 ) ;
memcpy ( V_24 -> V_139 , ( void * ) V_118 + V_88 , V_118 -> V_122 ) ;
F_80 ( V_118 , V_130 ) ;
}
F_86 ( V_78 ) ;
F_45 ( V_24 ) . V_159 = V_46 -> V_159 ;
F_45 ( V_24 ) . V_147 = V_147 ;
F_45 ( V_24 ) . V_160 = V_149 -> V_161 -> V_160 ;
V_81 = F_103 ( V_2 , V_24 ) ;
if ( V_81 ) {
F_104 ( V_24 ) ;
goto V_20;
}
if ( F_8 ( V_147 ) ) {
F_38 ( & V_24 -> V_162 ) ;
F_105 ( V_2 , V_24 , V_146 , V_147 ,
V_65 ) ;
}
V_81 = F_106 ( V_2 , V_24 , V_146 ,
V_145 -> V_155 & V_156 ) ;
if ( V_81 < 0 )
goto V_20;
V_61 += V_81 ;
} while ( V_118 != NULL ||
( ! ( V_145 -> V_155 & V_156 ) &&
F_59 ( & V_46 -> V_59 . V_85 ) ) );
if ( V_61 > 0 )
V_81 = V_61 ;
V_20:
F_69 ( & V_46 -> V_92 ) ;
return V_81 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_117 * V_118 ;
V_118 = F_92 ( V_24 ) ;
V_118 -> V_122 = V_24 -> V_61 ;
V_118 -> V_163 = F_45 ( V_24 ) . V_147 ;
V_118 -> V_164 = F_45 ( V_24 ) . V_160 . V_165 ;
V_118 -> V_166 = F_108 ( F_109 ( V_2 ) , F_45 ( V_24 ) . V_160 . V_167 ) ;
V_118 -> V_168 = F_110 ( F_109 ( V_2 ) , F_45 ( V_24 ) . V_160 . V_169 ) ;
F_76 ( V_118 ) ;
F_80 ( V_118 , V_154 ) ;
F_45 ( V_24 ) . V_3 |= V_170 ;
F_104 ( V_24 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 = & V_46 -> V_57 ;
struct V_117 * V_118 ;
F_64 ( & V_2 -> V_54 . V_93 ) ;
V_118 = F_84 ( V_78 , V_130 ) ;
if ( V_118 == NULL ) {
F_67 ( & V_2 -> V_54 . V_93 ) ;
F_104 ( V_24 ) ;
F_36 ( V_2 ) ;
return;
}
F_86 ( V_78 ) ;
F_112 ( & V_2 -> V_54 , V_24 ) ;
F_67 ( & V_2 -> V_54 . V_93 ) ;
V_118 -> V_122 = V_24 -> V_61 ;
V_118 -> V_163 = F_45 ( V_24 ) . V_147 ;
V_118 -> V_164 = F_45 ( V_24 ) . V_160 . V_165 ;
V_118 -> V_166 = F_108 ( F_109 ( V_2 ) , F_45 ( V_24 ) . V_160 . V_167 ) ;
V_118 -> V_168 = F_110 ( F_109 ( V_2 ) , F_45 ( V_24 ) . V_160 . V_169 ) ;
F_80 ( V_118 , V_171 ) ;
}
static void V_143 ( struct V_23 * V_24 )
{
#ifdef F_113
struct V_117 * V_118 ;
struct V_77 * V_78 ;
struct V_1 * V_2 ;
if ( F_44 ( V_24 ) ) {
V_118 = F_92 ( V_24 ) ;
V_2 = F_45 ( V_24 ) . V_2 ;
if ( F_45 ( V_24 ) . V_3 & V_157 ) {
F_80 ( V_118 , V_130 ) ;
V_78 = & F_2 ( V_2 ) -> V_59 ;
} else {
if ( ! ( F_45 ( V_24 ) . V_3 & V_170 ) ) {
V_118 -> V_122 = 0 ;
F_80 ( V_118 , V_154 ) ;
}
V_78 = & F_2 ( V_2 ) -> V_57 ;
}
F_68 ( F_59 ( & V_78 -> V_85 ) == 0 ) ;
F_72 ( & V_78 -> V_85 ) ;
F_114 ( V_2 ) ;
V_24 -> V_95 = NULL ;
}
#endif
if ( F_49 ( V_24 -> V_95 ) ) {
if ( ! V_24 -> V_172 ||
! F_115 ( & ( F_116 ( V_24 ) -> V_173 ) ) )
F_50 ( V_24 -> V_95 ) ;
V_24 -> V_95 = NULL ;
}
if ( V_24 -> V_2 != NULL )
F_117 ( V_24 ) ;
}
static void F_118 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
F_68 ( V_24 -> V_2 != NULL ) ;
V_24 -> V_2 = V_2 ;
V_24 -> V_142 = V_143 ;
F_119 ( V_24 -> V_174 , & V_2 -> V_175 ) ;
F_120 ( V_2 , V_24 -> V_174 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( V_46 -> V_134 ) {
if ( V_46 -> V_176 . V_177 )
V_46 -> V_176 . V_177 ( & V_46 -> V_176 ) ;
F_17 ( V_46 -> V_176 . V_17 ) ;
F_104 ( V_46 -> V_176 . V_24 ) ;
}
F_122 ( & V_2 -> V_54 ) ;
#ifdef F_113
if ( 1 ) {
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_46 -> V_57 . V_58 )
F_58 ( V_2 , & V_72 , true , false ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_46 -> V_59 . V_58 )
F_58 ( V_2 , & V_72 , true , true ) ;
}
#endif
if ( ! F_123 ( V_2 , V_178 ) ) {
F_124 ( V_179 L_2 , V_2 ) ;
return;
}
F_68 ( F_59 ( & V_2 -> V_175 ) ) ;
F_68 ( F_59 ( & V_2 -> V_180 ) ) ;
F_68 ( F_2 ( V_2 ) -> V_181 ) ;
}
void F_125 ( void )
__acquires( V_7 )
{
F_126 () ;
F_127 ( & V_7 ) ;
if ( F_59 ( & V_182 ) ) {
F_128 ( V_55 , V_183 ) ;
F_129 ( & V_184 , & V_55 ) ;
for (; ; ) {
F_130 ( V_185 ) ;
if ( F_59 ( & V_182 ) == 0 )
break;
F_131 ( & V_7 ) ;
F_97 () ;
F_127 ( & V_7 ) ;
}
F_132 ( V_186 ) ;
F_133 ( & V_184 , & V_55 ) ;
}
}
void F_134 ( void )
__releases( V_7 )
{
F_131 ( & V_7 ) ;
F_135 ( & V_184 ) ;
}
static inline void
F_136 ( void )
{
F_137 ( & V_7 ) ;
F_38 ( & V_182 ) ;
F_138 ( & V_7 ) ;
}
static inline void
F_139 ( void )
{
if ( F_140 ( & V_182 ) )
F_135 ( & V_184 ) ;
}
static bool F_141 ( void * V_187 , void * V_188 )
{
struct V_189 * V_190 = V_188 ;
struct V_1 * V_2 = V_187 ;
return F_2 ( V_2 ) -> V_159 == V_190 -> V_159 &&
F_142 ( F_143 ( V_2 ) , V_190 -> V_191 ) ;
}
static struct V_1 * F_144 ( struct V_192 * V_193 , T_1 V_159 ,
struct V_191 * V_191 )
{
struct V_189 V_188 = {
. V_191 = V_191 ,
. V_159 = V_159 ,
} ;
T_1 V_194 ;
V_194 = F_145 ( & V_193 -> V_194 , & V_159 , sizeof( V_159 ) ) ;
return F_146 ( & V_193 -> V_194 , V_194 ,
& F_141 , & V_188 ) ;
}
static struct V_1 * F_147 ( struct V_191 * V_191 , int V_38 , T_1 V_159 )
{
struct V_192 * V_193 = & V_195 [ V_38 ] ;
struct V_1 * V_2 ;
F_137 ( & V_7 ) ;
F_32 () ;
V_2 = F_144 ( V_193 , V_159 , V_191 ) ;
if ( V_2 )
F_100 ( V_2 ) ;
F_34 () ;
F_138 ( & V_7 ) ;
return V_2 ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_192 * V_196 = & V_195 [ V_2 -> V_25 ] ;
unsigned long V_133 ;
unsigned int V_62 ;
struct V_197 * V_197 ;
V_197 = F_149 ( V_196 -> V_197 ) ;
if ( ! V_197 )
return;
for ( V_62 = 0 ; V_62 < F_150 ( V_196 -> V_181 ) ; V_62 ++ ) {
V_133 = 0 ;
F_151 (sk, &tbl->mc_list) {
if ( V_62 < F_150 ( F_2 ( V_2 ) -> V_198 ) )
V_133 |= F_2 ( V_2 ) -> V_181 [ V_62 ] ;
}
V_197 -> V_199 [ V_62 ] = V_133 ;
}
}
static int F_152 ( struct V_1 * V_2 , struct V_191 * V_191 , T_1 V_159 )
{
struct V_192 * V_193 = & V_195 [ V_2 -> V_25 ] ;
int V_81 = - V_200 ;
F_63 ( & V_6 ) ;
if ( F_144 ( V_193 , V_159 , V_191 ) )
goto V_81;
V_81 = - V_84 ;
if ( F_2 ( V_2 ) -> V_159 )
goto V_81;
V_81 = - V_36 ;
if ( V_201 > 32 && F_8 ( V_193 -> V_194 . V_202 >= V_203 ) )
goto V_81;
F_2 ( V_2 ) -> V_159 = V_159 ;
F_100 ( V_2 ) ;
F_153 ( & V_193 -> V_194 , & F_2 ( V_2 ) -> V_204 , V_65 ) ;
V_81 = 0 ;
V_81:
F_69 ( & V_6 ) ;
return V_81 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_192 * V_193 ;
F_63 ( & V_6 ) ;
V_193 = & V_195 [ V_2 -> V_25 ] ;
if ( F_155 ( & V_193 -> V_194 , & F_2 ( V_2 ) -> V_204 , V_65 ) ) {
F_68 ( F_59 ( & V_2 -> V_205 ) == 1 ) ;
F_156 ( V_2 ) ;
}
F_69 ( & V_6 ) ;
F_125 () ;
if ( F_2 ( V_2 ) -> V_206 )
F_157 ( V_2 ) ;
F_134 () ;
}
static int F_158 ( struct V_191 * V_191 , struct V_104 * V_1 ,
struct V_207 * V_208 , int V_38 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
V_1 -> V_209 = & V_210 ;
V_2 = F_159 ( V_191 , V_211 , V_65 , & V_212 ) ;
if ( ! V_2 )
return - V_36 ;
F_160 ( V_1 , V_2 ) ;
V_46 = F_2 ( V_2 ) ;
if ( V_208 ) {
V_46 -> V_208 = V_208 ;
} else {
V_46 -> V_208 = & V_46 -> V_213 ;
F_161 ( V_46 -> V_208 ) ;
}
F_162 ( & V_46 -> V_55 ) ;
#ifdef F_113
F_161 ( & V_46 -> V_92 ) ;
#endif
V_2 -> V_214 = F_121 ;
V_2 -> V_25 = V_38 ;
return 0 ;
}
static int F_163 ( struct V_191 * V_191 , struct V_104 * V_1 , int V_38 ,
int V_215 )
{
struct V_17 * V_17 = NULL ;
struct V_207 * V_208 ;
struct V_45 * V_46 ;
int (* F_164)( int V_8 );
void (* F_165)( int V_8 );
int V_81 = 0 ;
V_1 -> V_49 = V_216 ;
if ( V_1 -> type != V_217 && V_1 -> type != V_218 )
return - V_219 ;
if ( V_38 < 0 || V_38 >= V_220 )
return - V_221 ;
F_136 () ;
#ifdef F_166
if ( ! V_195 [ V_38 ] . V_222 ) {
F_139 () ;
F_167 ( L_3 , V_211 , V_38 ) ;
F_136 () ;
}
#endif
if ( V_195 [ V_38 ] . V_222 &&
F_168 ( V_195 [ V_38 ] . V_17 ) )
V_17 = V_195 [ V_38 ] . V_17 ;
else
V_81 = - V_221 ;
V_208 = V_195 [ V_38 ] . V_208 ;
F_164 = V_195 [ V_38 ] . F_164 ;
F_165 = V_195 [ V_38 ] . F_165 ;
F_139 () ;
if ( V_81 < 0 )
goto V_20;
V_81 = F_158 ( V_191 , V_1 , V_208 , V_38 ) ;
if ( V_81 < 0 )
goto V_223;
F_169 () ;
F_170 ( V_191 , & V_212 , 1 ) ;
F_171 () ;
V_46 = F_2 ( V_1 -> V_2 ) ;
V_46 -> V_17 = V_17 ;
V_46 -> V_224 = F_164 ;
V_46 -> V_225 = F_165 ;
V_20:
return V_81 ;
V_223:
F_17 ( V_17 ) ;
goto V_20;
}
static int F_172 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
if ( ! V_2 )
return 0 ;
F_154 ( V_2 ) ;
F_173 ( V_2 ) ;
V_46 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_174 ( & V_46 -> V_55 ) ;
F_122 ( & V_2 -> V_82 ) ;
if ( V_46 -> V_159 ) {
struct V_226 V_132 = {
. V_191 = F_143 ( V_2 ) ,
. V_38 = V_2 -> V_25 ,
. V_159 = V_46 -> V_159 ,
} ;
F_175 ( & V_227 ,
V_228 , & V_132 ) ;
}
F_17 ( V_46 -> V_17 ) ;
F_125 () ;
if ( F_1 ( V_2 ) ) {
F_176 ( V_195 [ V_2 -> V_25 ] . V_222 == 0 ) ;
if ( -- V_195 [ V_2 -> V_25 ] . V_222 == 0 ) {
struct V_197 * V_229 ;
V_229 = F_149 ( V_195 [ V_2 -> V_25 ] . V_197 ) ;
F_177 ( V_195 [ V_2 -> V_25 ] . V_197 , NULL ) ;
F_178 ( V_229 , V_230 ) ;
V_195 [ V_2 -> V_25 ] . V_17 = NULL ;
V_195 [ V_2 -> V_25 ] . F_164 = NULL ;
V_195 [ V_2 -> V_25 ] . F_165 = NULL ;
V_195 [ V_2 -> V_25 ] . V_3 = 0 ;
V_195 [ V_2 -> V_25 ] . V_222 = 0 ;
}
} else if ( V_46 -> V_206 ) {
F_148 ( V_2 ) ;
}
F_134 () ;
F_52 ( V_46 -> V_181 ) ;
V_46 -> V_181 = NULL ;
F_169 () ;
F_170 ( F_143 ( V_2 ) , & V_212 , - 1 ) ;
F_171 () ;
F_114 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_191 * V_191 = F_143 ( V_2 ) ;
struct V_192 * V_193 = & V_195 [ V_2 -> V_25 ] ;
T_4 V_159 = F_180 ( V_183 ) ;
int V_81 ;
static T_4 V_231 = - 4097 ;
V_232:
F_181 () ;
F_125 () ;
F_32 () ;
if ( F_144 ( V_193 , V_159 , V_191 ) ) {
V_159 = V_231 -- ;
if ( V_231 > - 4097 )
V_231 = - 4097 ;
F_34 () ;
F_134 () ;
goto V_232;
}
F_34 () ;
F_134 () ;
V_81 = F_152 ( V_2 , V_191 , V_159 ) ;
if ( V_81 == - V_200 )
goto V_232;
if ( V_81 == - V_84 )
V_81 = 0 ;
return V_81 ;
}
bool F_182 ( const struct V_233 * V_234 ,
struct V_235 * V_236 , int V_237 )
{
return ( ( V_234 -> V_3 & V_238 ) ||
F_183 ( V_234 -> V_2 -> V_152 -> V_102 , V_236 , V_237 ) ) &&
F_184 ( V_236 , V_237 ) ;
}
bool F_185 ( const struct V_23 * V_24 ,
struct V_235 * V_236 , int V_237 )
{
return F_182 ( & F_45 ( V_24 ) , V_236 , V_237 ) ;
}
bool F_186 ( const struct V_23 * V_24 , int V_237 )
{
return F_185 ( V_24 , & V_239 , V_237 ) ;
}
bool F_187 ( const struct V_23 * V_24 , int V_237 )
{
return F_185 ( V_24 , F_143 ( V_24 -> V_2 ) -> V_236 , V_237 ) ;
}
static inline int F_188 ( const struct V_104 * V_1 , unsigned int V_240 )
{
return ( V_195 [ V_1 -> V_2 -> V_25 ] . V_3 & V_240 ) ||
F_184 ( F_143 ( V_1 -> V_2 ) -> V_236 , V_241 ) ;
}
static void
F_189 ( struct V_1 * V_2 , unsigned int V_206 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( V_46 -> V_206 && ! V_206 )
F_157 ( V_2 ) ;
else if ( ! V_46 -> V_206 && V_206 )
F_190 ( V_2 , & V_195 [ V_2 -> V_25 ] . V_242 ) ;
V_46 -> V_206 = V_206 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_181 ;
unsigned long * V_243 ;
int V_81 = 0 ;
F_125 () ;
V_181 = V_195 [ V_2 -> V_25 ] . V_181 ;
if ( ! V_195 [ V_2 -> V_25 ] . V_222 ) {
V_81 = - V_244 ;
goto V_245;
}
if ( V_46 -> V_198 >= V_181 )
goto V_245;
V_243 = F_192 ( V_46 -> V_181 , F_193 ( V_181 ) , V_37 ) ;
if ( V_243 == NULL ) {
V_81 = - V_36 ;
goto V_245;
}
memset ( ( char * ) V_243 + F_193 ( V_46 -> V_198 ) , 0 ,
F_193 ( V_181 ) - F_193 ( V_46 -> V_198 ) ) ;
V_46 -> V_181 = V_243 ;
V_46 -> V_198 = V_181 ;
V_245:
F_134 () ;
return V_81 ;
}
static void V_225 ( int V_8 , long unsigned int V_181 ,
struct V_45 * V_46 )
{
int V_246 ;
if ( ! V_46 -> V_225 )
return;
for ( V_246 = 0 ; V_246 < V_8 ; V_246 ++ )
if ( F_42 ( V_246 , & V_181 ) )
V_46 -> V_225 ( V_246 ) ;
}
static int V_224 ( struct V_104 * V_1 , struct V_247 * V_248 ,
int V_249 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_191 * V_191 = F_143 ( V_2 ) ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_248 ;
int V_81 ;
long unsigned int V_181 = V_251 -> V_252 ;
if ( V_249 < sizeof( struct V_250 ) )
return - V_13 ;
if ( V_251 -> V_253 != V_254 )
return - V_13 ;
if ( V_181 ) {
if ( ! F_188 ( V_1 , V_255 ) )
return - V_256 ;
V_81 = F_191 ( V_2 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_46 -> V_159 )
if ( V_251 -> V_257 != V_46 -> V_159 )
return - V_13 ;
if ( V_46 -> V_224 && V_181 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_46 -> V_198 ; V_8 ++ ) {
if ( ! F_42 ( V_8 , & V_181 ) )
continue;
V_81 = V_46 -> V_224 ( V_8 ) ;
if ( ! V_81 )
continue;
V_225 ( V_8 , V_181 , V_46 ) ;
return V_81 ;
}
}
if ( ! V_46 -> V_159 ) {
V_81 = V_251 -> V_257 ?
F_152 ( V_2 , V_191 , V_251 -> V_257 ) :
F_179 ( V_1 ) ;
if ( V_81 ) {
V_225 ( V_46 -> V_198 , V_181 , V_46 ) ;
return V_81 ;
}
}
if ( ! V_181 && ( V_46 -> V_181 == NULL || ! ( T_1 ) V_46 -> V_181 [ 0 ] ) )
return 0 ;
F_125 () ;
F_189 ( V_2 , V_46 -> V_206 +
F_194 ( V_181 ) -
F_194 ( V_46 -> V_181 [ 0 ] ) ) ;
V_46 -> V_181 [ 0 ] = ( V_46 -> V_181 [ 0 ] & ~ 0xffffffffUL ) | V_181 ;
F_148 ( V_2 ) ;
F_134 () ;
return 0 ;
}
static int F_195 ( struct V_104 * V_1 , struct V_247 * V_248 ,
int V_258 , int V_3 )
{
int V_81 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_248 ;
if ( V_258 < sizeof( V_248 -> V_259 ) )
return - V_13 ;
if ( V_248 -> V_259 == V_260 ) {
V_2 -> V_261 = V_262 ;
V_46 -> V_146 = 0 ;
V_46 -> V_147 = 0 ;
return 0 ;
}
if ( V_248 -> V_259 != V_254 )
return - V_13 ;
if ( ( V_251 -> V_252 || V_251 -> V_257 ) &&
! F_188 ( V_1 , V_263 ) )
return - V_256 ;
if ( ! V_46 -> V_159 )
V_81 = F_179 ( V_1 ) ;
if ( V_81 == 0 ) {
V_2 -> V_261 = V_264 ;
V_46 -> V_146 = V_251 -> V_257 ;
V_46 -> V_147 = F_196 ( V_251 -> V_252 ) ;
}
return V_81 ;
}
static int F_197 ( struct V_104 * V_1 , struct V_247 * V_248 ,
int * V_249 , int V_265 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
F_198 ( struct V_250 * , V_251 , V_248 ) ;
V_251 -> V_253 = V_254 ;
V_251 -> V_266 = 0 ;
* V_249 = sizeof( * V_251 ) ;
if ( V_265 ) {
V_251 -> V_257 = V_46 -> V_146 ;
V_251 -> V_252 = F_6 ( V_46 -> V_147 ) ;
} else {
V_251 -> V_257 = V_46 -> V_159 ;
V_251 -> V_252 = V_46 -> V_181 ? V_46 -> V_181 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_199 ( struct V_1 * V_267 , T_1 V_159 )
{
struct V_1 * V_1 ;
struct V_45 * V_46 ;
V_1 = F_147 ( F_143 ( V_267 ) , V_267 -> V_25 , V_159 ) ;
if ( ! V_1 )
return F_200 ( - V_268 ) ;
V_46 = F_2 ( V_1 ) ;
if ( V_1 -> V_261 == V_264 &&
V_46 -> V_146 != F_2 ( V_267 ) -> V_159 ) {
F_114 ( V_1 ) ;
return F_200 ( - V_268 ) ;
}
return V_1 ;
}
struct V_1 * F_201 ( struct V_102 * V_269 )
{
struct V_270 * V_270 = F_202 ( V_269 ) ;
struct V_1 * V_1 ;
if ( ! F_203 ( V_270 -> V_271 ) )
return F_200 ( - V_272 ) ;
V_1 = F_204 ( V_270 ) -> V_2 ;
if ( V_1 -> V_273 != V_254 )
return F_200 ( - V_13 ) ;
F_100 ( V_1 ) ;
return V_1 ;
}
static struct V_23 * F_205 ( unsigned int V_107 ,
int V_274 )
{
struct V_23 * V_24 ;
void * V_139 ;
if ( V_107 <= V_275 || V_274 )
return F_102 ( V_107 , V_65 ) ;
V_107 = F_206 ( V_107 ) +
F_206 ( sizeof( struct V_276 ) ) ;
V_139 = F_207 ( V_107 ) ;
if ( V_139 == NULL )
return NULL ;
V_24 = F_208 ( V_139 , V_107 ) ;
if ( V_24 == NULL )
F_50 ( V_139 ) ;
else {
V_24 -> V_277 = 0 ;
V_24 -> V_142 = V_143 ;
}
return V_24 ;
}
int F_209 ( struct V_1 * V_2 , struct V_23 * V_24 ,
long * V_278 , struct V_1 * V_267 )
{
struct V_45 * V_46 ;
V_46 = F_2 ( V_2 ) ;
if ( ( F_59 ( & V_2 -> V_175 ) > V_2 -> V_279 ||
F_42 ( V_48 , & V_46 -> V_49 ) ) &&
! F_44 ( V_24 ) ) {
F_128 ( V_55 , V_183 ) ;
if ( ! * V_278 ) {
if ( ! V_267 || F_1 ( V_267 ) )
F_36 ( V_2 ) ;
F_114 ( V_2 ) ;
F_104 ( V_24 ) ;
return - V_280 ;
}
F_132 ( V_281 ) ;
F_210 ( & V_46 -> V_55 , & V_55 ) ;
if ( ( F_59 ( & V_2 -> V_175 ) > V_2 -> V_279 ||
F_42 ( V_48 , & V_46 -> V_49 ) ) &&
! F_123 ( V_2 , V_178 ) )
* V_278 = F_211 ( * V_278 ) ;
F_132 ( V_186 ) ;
F_133 ( & V_46 -> V_55 , & V_55 ) ;
F_114 ( V_2 ) ;
if ( F_212 ( V_183 ) ) {
F_104 ( V_24 ) ;
return F_213 ( * V_278 ) ;
}
return 1 ;
}
F_118 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_61 = V_24 -> V_61 ;
F_31 ( V_24 ) ;
#ifdef F_113
if ( F_44 ( V_24 ) )
F_107 ( V_2 , V_24 ) ;
else if ( F_46 ( V_2 ) )
F_111 ( V_2 , V_24 ) ;
else
#endif
F_215 ( & V_2 -> V_54 , V_24 ) ;
V_2 -> V_282 ( V_2 ) ;
return V_61 ;
}
int F_216 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_61 = F_214 ( V_2 , V_24 ) ;
F_114 ( V_2 ) ;
return V_61 ;
}
void F_217 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_104 ( V_24 ) ;
F_114 ( V_2 ) ;
}
static struct V_23 * F_218 ( struct V_23 * V_24 , T_2 V_283 )
{
int V_284 ;
F_68 ( V_24 -> V_2 != NULL ) ;
if ( F_44 ( V_24 ) )
return V_24 ;
V_284 = V_24 -> V_140 - V_24 -> V_141 ;
if ( F_49 ( V_24 -> V_95 ) || V_284 * 2 < V_24 -> V_174 )
return V_24 ;
if ( F_219 ( V_24 ) ) {
struct V_23 * V_35 = F_23 ( V_24 , V_283 ) ;
if ( ! V_35 )
return V_24 ;
F_220 ( V_24 ) ;
V_24 = V_35 ;
}
if ( ! F_221 ( V_24 , 0 , - V_284 , V_283 ) )
V_24 -> V_174 -= V_284 ;
return V_24 ;
}
static int F_222 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_1 * V_267 )
{
int V_22 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
V_22 = - V_268 ;
if ( V_46 -> V_285 != NULL ) {
V_22 = V_24 -> V_61 ;
F_118 ( V_24 , V_2 ) ;
F_45 ( V_24 ) . V_2 = V_267 ;
F_35 ( V_2 , V_267 , V_24 ) ;
V_46 -> V_285 ( V_24 ) ;
F_220 ( V_24 ) ;
} else {
F_104 ( V_24 ) ;
}
F_114 ( V_2 ) ;
return V_22 ;
}
int F_106 ( struct V_1 * V_267 , struct V_23 * V_24 ,
T_1 V_159 , int V_286 )
{
struct V_1 * V_2 ;
int V_81 ;
long V_278 ;
V_24 = F_218 ( V_24 , F_223 () ) ;
V_278 = F_224 ( V_267 , V_286 ) ;
V_232:
V_2 = F_199 ( V_267 , V_159 ) ;
if ( F_225 ( V_2 ) ) {
F_104 ( V_24 ) ;
return F_226 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_222 ( V_2 , V_24 , V_267 ) ;
if ( F_227 ( V_2 , V_24 ) ) {
V_81 = V_24 -> V_61 ;
F_104 ( V_24 ) ;
F_114 ( V_2 ) ;
return V_81 ;
}
V_81 = F_209 ( V_2 , V_24 , & V_278 , V_267 ) ;
if ( V_81 == 1 )
goto V_232;
if ( V_81 )
return V_81 ;
return F_216 ( V_2 , V_24 ) ;
}
struct V_23 * F_228 ( struct V_1 * V_267 , unsigned int V_107 ,
T_1 V_146 , T_2 V_287 )
{
#ifdef F_113
struct V_1 * V_2 = NULL ;
struct V_23 * V_24 ;
struct V_77 * V_78 ;
struct V_117 * V_118 ;
unsigned int V_150 ;
V_2 = F_199 ( V_267 , V_146 ) ;
if ( F_225 ( V_2 ) )
goto V_20;
V_78 = & F_2 ( V_2 ) -> V_57 ;
if ( V_78 -> V_58 == NULL )
goto V_288;
if ( V_78 -> V_96 - V_88 < V_107 )
goto V_288;
V_24 = F_99 ( V_287 ) ;
if ( V_24 == NULL )
goto V_75;
F_64 ( & V_2 -> V_54 . V_93 ) ;
if ( V_78 -> V_58 == NULL )
goto V_289;
V_150 = V_78 -> V_96 - V_88 ;
if ( V_150 < V_107 )
goto V_289;
F_87 ( V_78 ) ;
V_118 = F_84 ( V_78 , V_130 ) ;
if ( V_118 == NULL )
goto V_290;
F_93 ( V_24 , V_2 , V_78 , V_118 ) ;
F_80 ( V_118 , V_158 ) ;
F_38 ( & V_78 -> V_85 ) ;
F_86 ( V_78 ) ;
F_67 ( & V_2 -> V_54 . V_93 ) ;
return V_24 ;
V_290:
F_104 ( V_24 ) ;
F_67 ( & V_2 -> V_54 . V_93 ) ;
F_36 ( V_2 ) ;
V_75:
F_114 ( V_2 ) ;
return NULL ;
V_289:
F_104 ( V_24 ) ;
F_67 ( & V_2 -> V_54 . V_93 ) ;
V_288:
F_114 ( V_2 ) ;
V_20:
#endif
return F_102 ( V_107 , V_287 ) ;
}
int F_229 ( struct V_1 * V_2 , unsigned int V_8 )
{
int V_291 = 0 ;
struct V_197 * V_197 ;
F_176 ( ! F_1 ( V_2 ) ) ;
F_32 () ;
V_197 = F_230 ( V_195 [ V_2 -> V_25 ] . V_197 ) ;
if ( V_197 && V_8 - 1 < V_195 [ V_2 -> V_25 ] . V_181 )
V_291 = F_42 ( V_8 - 1 , V_197 -> V_199 ) ;
F_34 () ;
return V_291 ;
}
static int F_231 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( F_59 ( & V_2 -> V_175 ) <= V_2 -> V_279 &&
! F_42 ( V_48 , & V_46 -> V_49 ) ) {
F_118 ( V_24 , V_2 ) ;
F_214 ( V_2 , V_24 ) ;
return F_59 ( & V_2 -> V_175 ) > ( V_2 -> V_279 >> 1 ) ;
}
return - 1 ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_294 ;
if ( V_293 -> V_295 == V_2 )
return;
if ( V_46 -> V_159 == V_293 -> V_159 || V_293 -> V_8 - 1 >= V_46 -> V_198 ||
! F_42 ( V_293 -> V_8 - 1 , V_46 -> V_181 ) )
return;
if ( ! F_142 ( F_143 ( V_2 ) , V_293 -> V_191 ) )
return;
if ( V_293 -> V_296 ) {
F_36 ( V_2 ) ;
return;
}
F_100 ( V_2 ) ;
if ( V_293 -> V_297 == NULL ) {
if ( F_219 ( V_293 -> V_24 ) ) {
V_293 -> V_297 = F_23 ( V_293 -> V_24 , V_293 -> V_283 ) ;
} else {
V_293 -> V_297 = F_233 ( V_293 -> V_24 ) ;
F_234 ( V_293 -> V_297 ) ;
}
}
if ( V_293 -> V_297 == NULL ) {
F_36 ( V_2 ) ;
V_293 -> V_296 = 1 ;
if ( V_46 -> V_3 & V_298 )
V_293 -> V_299 = 1 ;
} else if ( V_293 -> V_300 && V_293 -> V_300 ( V_2 , V_293 -> V_297 , V_293 -> V_301 ) ) {
F_104 ( V_293 -> V_297 ) ;
V_293 -> V_297 = NULL ;
} else if ( F_227 ( V_2 , V_293 -> V_297 ) ) {
F_104 ( V_293 -> V_297 ) ;
V_293 -> V_297 = NULL ;
} else if ( ( V_294 = F_231 ( V_2 , V_293 -> V_297 ) ) < 0 ) {
F_36 ( V_2 ) ;
if ( V_46 -> V_3 & V_298 )
V_293 -> V_299 = 1 ;
} else {
V_293 -> V_302 |= V_294 ;
V_293 -> V_303 = 1 ;
V_293 -> V_297 = NULL ;
}
F_114 ( V_2 ) ;
}
int F_235 ( struct V_1 * V_267 , struct V_23 * V_24 , T_1 V_159 ,
T_1 V_8 , T_2 V_283 ,
int (* F_236)( struct V_1 * V_304 , struct V_23 * V_24 , void * V_139 ) ,
void * V_305 )
{
struct V_191 * V_191 = F_143 ( V_267 ) ;
struct V_292 V_306 ;
struct V_1 * V_2 ;
V_24 = F_218 ( V_24 , V_283 ) ;
V_306 . V_295 = V_267 ;
V_306 . V_191 = V_191 ;
V_306 . V_159 = V_159 ;
V_306 . V_8 = V_8 ;
V_306 . V_296 = 0 ;
V_306 . V_299 = 0 ;
V_306 . V_302 = 0 ;
V_306 . V_303 = 0 ;
V_306 . V_283 = V_283 ;
V_306 . V_24 = V_24 ;
V_306 . V_297 = NULL ;
V_306 . V_300 = F_236 ;
V_306 . V_301 = V_305 ;
F_136 () ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_232 ( V_2 , & V_306 ) ;
F_220 ( V_24 ) ;
F_139 () ;
if ( V_306 . V_299 ) {
F_104 ( V_306 . V_297 ) ;
return - V_51 ;
}
F_220 ( V_306 . V_297 ) ;
if ( V_306 . V_303 ) {
if ( V_306 . V_302 && ( V_283 & V_307 ) )
F_237 () ;
return 0 ;
}
return - V_308 ;
}
int F_105 ( struct V_1 * V_267 , struct V_23 * V_24 , T_1 V_159 ,
T_1 V_8 , T_2 V_283 )
{
return F_235 ( V_267 , V_24 , V_159 , V_8 , V_283 ,
NULL , NULL ) ;
}
static int F_238 ( struct V_1 * V_2 , struct V_309 * V_293 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_22 = 0 ;
if ( V_2 == V_293 -> V_295 )
goto V_20;
if ( ! F_142 ( F_143 ( V_2 ) , F_143 ( V_293 -> V_295 ) ) )
goto V_20;
if ( V_46 -> V_159 == V_293 -> V_159 || V_293 -> V_8 - 1 >= V_46 -> V_198 ||
! F_42 ( V_293 -> V_8 - 1 , V_46 -> V_181 ) )
goto V_20;
if ( V_293 -> V_310 == V_51 && V_46 -> V_3 & V_47 ) {
V_22 = 1 ;
goto V_20;
}
V_2 -> V_50 = V_293 -> V_310 ;
V_2 -> V_52 ( V_2 ) ;
V_20:
return V_22 ;
}
int F_239 ( struct V_1 * V_267 , T_1 V_159 , T_1 V_8 , int V_310 )
{
struct V_309 V_306 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
V_306 . V_295 = V_267 ;
V_306 . V_159 = V_159 ;
V_306 . V_8 = V_8 ;
V_306 . V_310 = - V_310 ;
F_137 ( & V_7 ) ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_22 += F_238 ( V_2 , & V_306 ) ;
F_138 ( & V_7 ) ;
return V_22 ;
}
static void F_240 ( struct V_45 * V_46 ,
unsigned int V_8 ,
int V_311 )
{
int V_229 , V_312 = ! ! V_311 , V_206 ;
V_229 = F_42 ( V_8 - 1 , V_46 -> V_181 ) ;
V_206 = V_46 -> V_206 - V_229 + V_312 ;
if ( V_312 )
F_241 ( V_8 - 1 , V_46 -> V_181 ) ;
else
F_242 ( V_8 - 1 , V_46 -> V_181 ) ;
F_189 ( & V_46 -> V_2 , V_206 ) ;
F_148 ( & V_46 -> V_2 ) ;
}
static int F_243 ( struct V_104 * V_1 , int V_313 , int V_314 ,
char T_5 * V_315 , unsigned int V_316 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_294 = 0 ;
int V_81 ;
if ( V_313 != V_317 )
return - V_318 ;
if ( V_314 != V_319 && V_314 != V_320 &&
V_316 >= sizeof( int ) &&
F_244 ( V_294 , ( unsigned int T_5 * ) V_315 ) )
return - V_321 ;
switch ( V_314 ) {
case V_322 :
if ( V_294 )
V_46 -> V_3 |= V_323 ;
else
V_46 -> V_3 &= ~ V_323 ;
V_81 = 0 ;
break;
case V_324 :
case V_325 : {
if ( ! F_188 ( V_1 , V_255 ) )
return - V_256 ;
V_81 = F_191 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( ! V_294 || V_294 - 1 >= V_46 -> V_198 )
return - V_13 ;
if ( V_314 == V_324 && V_46 -> V_224 ) {
V_81 = V_46 -> V_224 ( V_294 ) ;
if ( V_81 )
return V_81 ;
}
F_125 () ;
F_240 ( V_46 , V_294 ,
V_314 == V_324 ) ;
F_134 () ;
if ( V_314 == V_325 && V_46 -> V_225 )
V_46 -> V_225 ( V_294 ) ;
V_81 = 0 ;
break;
}
case V_326 :
if ( V_294 )
V_46 -> V_3 |= V_298 ;
else
V_46 -> V_3 &= ~ V_298 ;
V_81 = 0 ;
break;
case V_327 :
if ( V_294 ) {
V_46 -> V_3 |= V_47 ;
F_41 ( V_48 , & V_46 -> V_49 ) ;
F_43 ( & V_46 -> V_55 ) ;
} else {
V_46 -> V_3 &= ~ V_47 ;
}
V_81 = 0 ;
break;
#ifdef F_113
case V_319 :
case V_320 : {
struct V_71 V_72 ;
if ( ! F_245 ( V_241 ) )
return - V_256 ;
if ( V_316 < sizeof( V_72 ) )
return - V_13 ;
if ( F_246 ( & V_72 , V_315 , sizeof( V_72 ) ) )
return - V_321 ;
V_81 = F_58 ( V_2 , & V_72 , false ,
V_314 == V_320 ) ;
break;
}
#endif
default:
V_81 = - V_318 ;
}
return V_81 ;
}
static int F_247 ( struct V_104 * V_1 , int V_313 , int V_314 ,
char T_5 * V_315 , int T_5 * V_316 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_61 , V_294 , V_81 ;
if ( V_313 != V_317 )
return - V_318 ;
if ( F_244 ( V_61 , V_316 ) )
return - V_321 ;
if ( V_61 < 0 )
return - V_13 ;
switch ( V_314 ) {
case V_322 :
if ( V_61 < sizeof( int ) )
return - V_13 ;
V_61 = sizeof( int ) ;
V_294 = V_46 -> V_3 & V_323 ? 1 : 0 ;
if ( F_248 ( V_61 , V_316 ) ||
F_248 ( V_294 , V_315 ) )
return - V_321 ;
V_81 = 0 ;
break;
case V_326 :
if ( V_61 < sizeof( int ) )
return - V_13 ;
V_61 = sizeof( int ) ;
V_294 = V_46 -> V_3 & V_298 ? 1 : 0 ;
if ( F_248 ( V_61 , V_316 ) ||
F_248 ( V_294 , V_315 ) )
return - V_321 ;
V_81 = 0 ;
break;
case V_327 :
if ( V_61 < sizeof( int ) )
return - V_13 ;
V_61 = sizeof( int ) ;
V_294 = V_46 -> V_3 & V_47 ? 1 : 0 ;
if ( F_248 ( V_61 , V_316 ) ||
F_248 ( V_294 , V_315 ) )
return - V_321 ;
V_81 = 0 ;
break;
default:
V_81 = - V_318 ;
}
return V_81 ;
}
static void F_249 ( struct V_144 * V_145 , struct V_23 * V_24 )
{
struct V_328 V_306 ;
V_306 . V_8 = F_45 ( V_24 ) . V_147 ;
F_250 ( V_145 , V_317 , V_322 , sizeof( V_306 ) , & V_306 ) ;
}
static int F_251 ( struct V_329 * V_329 , struct V_104 * V_1 ,
struct V_144 * V_145 , T_6 V_61 )
{
struct V_148 * V_149 = F_252 ( V_329 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
F_198 ( struct V_250 * , V_248 , V_145 -> V_330 ) ;
T_1 V_146 ;
T_1 V_147 ;
struct V_23 * V_24 ;
int V_81 ;
struct V_331 V_161 ;
T_1 V_332 = 0 ;
if ( V_145 -> V_155 & V_333 )
return - V_334 ;
if ( NULL == V_149 -> V_161 )
V_149 -> V_161 = & V_161 ;
V_81 = F_253 ( V_1 , V_145 , V_149 -> V_161 , true ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_145 -> V_335 ) {
V_81 = - V_13 ;
if ( V_248 -> V_253 != V_254 )
goto V_20;
V_146 = V_248 -> V_257 ;
V_147 = F_196 ( V_248 -> V_252 ) ;
V_81 = - V_256 ;
if ( ( V_147 || V_146 ) &&
! F_188 ( V_1 , V_263 ) )
goto V_20;
V_332 |= V_238 ;
} else {
V_146 = V_46 -> V_146 ;
V_147 = V_46 -> V_147 ;
}
if ( ! V_46 -> V_159 ) {
V_81 = F_179 ( V_1 ) ;
if ( V_81 )
goto V_20;
}
if ( F_47 ( V_2 ) &&
V_145 -> V_336 -> V_337 == NULL ) {
V_81 = F_95 ( V_2 , V_145 , V_146 , V_147 ,
V_149 ) ;
goto V_20;
}
V_81 = - V_338 ;
if ( V_61 > V_2 -> V_339 - 32 )
goto V_20;
V_81 = - V_51 ;
V_24 = F_205 ( V_61 , V_147 ) ;
if ( V_24 == NULL )
goto V_20;
F_45 ( V_24 ) . V_159 = V_46 -> V_159 ;
F_45 ( V_24 ) . V_147 = V_147 ;
F_45 ( V_24 ) . V_160 = V_149 -> V_161 -> V_160 ;
F_45 ( V_24 ) . V_3 = V_332 ;
V_81 = - V_321 ;
if ( F_254 ( F_255 ( V_24 , V_61 ) , V_145 -> V_336 , V_61 ) ) {
F_104 ( V_24 ) ;
goto V_20;
}
V_81 = F_103 ( V_2 , V_24 ) ;
if ( V_81 ) {
F_104 ( V_24 ) ;
goto V_20;
}
if ( V_147 ) {
F_38 ( & V_24 -> V_162 ) ;
F_105 ( V_2 , V_24 , V_146 , V_147 , V_65 ) ;
}
V_81 = F_106 ( V_2 , V_24 , V_146 , V_145 -> V_155 & V_156 ) ;
V_20:
F_256 ( V_149 -> V_161 ) ;
return V_81 ;
}
static int F_257 ( struct V_329 * V_329 , struct V_104 * V_1 ,
struct V_144 * V_145 , T_6 V_61 ,
int V_3 )
{
struct V_148 * V_149 = F_252 ( V_329 ) ;
struct V_331 V_161 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_340 = V_3 & V_156 ;
T_6 V_341 ;
struct V_23 * V_24 , * V_342 ;
int V_81 , V_22 ;
if ( V_3 & V_333 )
return - V_334 ;
V_341 = 0 ;
V_24 = F_258 ( V_2 , V_3 , V_340 , & V_81 ) ;
if ( V_24 == NULL )
goto V_20;
V_342 = V_24 ;
#ifdef F_259
if ( F_8 ( F_116 ( V_24 ) -> V_343 ) ) {
if ( V_3 & V_344 )
V_342 = F_116 ( V_24 ) -> V_343 ;
}
#endif
V_46 -> V_345 = F_260 ( V_46 -> V_345 , V_61 ) ;
V_46 -> V_345 = F_261 ( T_6 , V_46 -> V_345 ,
16384 ) ;
V_341 = V_342 -> V_61 ;
if ( V_61 < V_341 ) {
V_145 -> V_155 |= V_346 ;
V_341 = V_61 ;
}
F_262 ( V_342 ) ;
V_81 = F_263 ( V_342 , 0 , V_145 -> V_336 , V_341 ) ;
if ( V_145 -> V_330 ) {
F_198 ( struct V_250 * , V_248 , V_145 -> V_330 ) ;
V_248 -> V_253 = V_254 ;
V_248 -> V_266 = 0 ;
V_248 -> V_257 = F_45 ( V_24 ) . V_159 ;
V_248 -> V_252 = F_6 ( F_45 ( V_24 ) . V_147 ) ;
V_145 -> V_335 = sizeof( * V_248 ) ;
}
if ( V_46 -> V_3 & V_323 )
F_249 ( V_145 , V_24 ) ;
if ( NULL == V_149 -> V_161 ) {
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_149 -> V_161 = & V_161 ;
}
V_149 -> V_161 -> V_160 = * F_264 ( V_24 ) ;
if ( V_3 & V_346 )
V_341 = V_342 -> V_61 ;
F_265 ( V_2 , V_24 ) ;
if ( V_46 -> V_134 &&
F_59 ( & V_2 -> V_175 ) <= V_2 -> V_279 / 2 ) {
V_22 = F_90 ( V_2 ) ;
if ( V_22 ) {
V_2 -> V_50 = - V_22 ;
V_2 -> V_52 ( V_2 ) ;
}
}
F_266 ( V_1 , V_145 , V_149 -> V_161 , V_3 ) ;
V_20:
F_39 ( V_2 ) ;
return V_81 ? : V_341 ;
}
static void F_267 ( struct V_1 * V_2 )
{
F_268 () ;
}
struct V_1 *
F_269 ( struct V_191 * V_191 , int V_347 , struct V_17 * V_17 ,
struct V_348 * V_349 )
{
struct V_104 * V_1 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_197 * V_197 = NULL ;
struct V_207 * V_208 = V_349 ? V_349 -> V_208 : NULL ;
unsigned int V_181 ;
F_176 ( ! V_195 ) ;
if ( V_347 < 0 || V_347 >= V_220 )
return NULL ;
if ( F_270 ( V_211 , V_218 , V_347 , & V_1 ) )
return NULL ;
if ( F_158 ( & V_350 , V_1 , V_208 , V_347 ) < 0 )
goto V_351;
V_2 = V_1 -> V_2 ;
F_271 ( V_2 , V_191 ) ;
if ( ! V_349 || V_349 -> V_181 < 32 )
V_181 = 32 ;
else
V_181 = V_349 -> V_181 ;
V_197 = F_272 ( sizeof( * V_197 ) + F_193 ( V_181 ) , V_65 ) ;
if ( ! V_197 )
goto V_352;
V_2 -> V_282 = F_267 ;
if ( V_349 && V_349 -> V_353 )
F_2 ( V_2 ) -> V_285 = V_349 -> V_353 ;
if ( F_152 ( V_2 , V_191 , 0 ) )
goto V_352;
V_46 = F_2 ( V_2 ) ;
V_46 -> V_3 |= V_4 ;
F_125 () ;
if ( ! V_195 [ V_347 ] . V_222 ) {
V_195 [ V_347 ] . V_181 = V_181 ;
F_273 ( V_195 [ V_347 ] . V_197 , V_197 ) ;
V_195 [ V_347 ] . V_208 = V_208 ;
V_195 [ V_347 ] . V_17 = V_17 ;
if ( V_349 ) {
V_195 [ V_347 ] . F_164 = V_349 -> F_164 ;
V_195 [ V_347 ] . F_165 = V_349 -> F_165 ;
V_195 [ V_347 ] . V_3 = V_349 -> V_3 ;
if ( V_349 -> V_354 )
V_195 [ V_347 ] . V_354 = V_349 -> V_354 ;
}
V_195 [ V_347 ] . V_222 = 1 ;
} else {
F_52 ( V_197 ) ;
V_195 [ V_347 ] . V_222 ++ ;
}
F_134 () ;
return V_2 ;
V_352:
F_52 ( V_197 ) ;
F_274 ( V_2 ) ;
return NULL ;
V_351:
F_275 ( V_1 ) ;
return NULL ;
}
void
F_274 ( struct V_1 * V_2 )
{
F_276 ( V_2 ) ;
}
int F_277 ( struct V_1 * V_2 , unsigned int V_181 )
{
struct V_197 * V_312 , * V_229 ;
struct V_192 * V_196 = & V_195 [ V_2 -> V_25 ] ;
if ( V_181 < 32 )
V_181 = 32 ;
if ( F_193 ( V_196 -> V_181 ) < F_193 ( V_181 ) ) {
V_312 = F_272 ( sizeof( * V_312 ) + F_193 ( V_181 ) , V_37 ) ;
if ( ! V_312 )
return - V_36 ;
V_229 = F_149 ( V_196 -> V_197 ) ;
memcpy ( V_312 -> V_199 , V_229 -> V_199 , F_193 ( V_196 -> V_181 ) ) ;
F_273 ( V_196 -> V_197 , V_312 ) ;
F_178 ( V_229 , V_230 ) ;
}
V_196 -> V_181 = V_181 ;
return 0 ;
}
int F_278 ( struct V_1 * V_2 , unsigned int V_181 )
{
int V_81 ;
F_125 () ;
V_81 = F_277 ( V_2 , V_181 ) ;
F_134 () ;
return V_81 ;
}
void F_279 ( struct V_1 * V_355 , unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_192 * V_196 = & V_195 [ V_355 -> V_25 ] ;
F_151 (sk, &tbl->mc_list)
F_240 ( F_2 ( V_2 ) , V_8 , 0 ) ;
}
struct V_356 *
F_280 ( struct V_23 * V_24 , T_1 V_159 , T_1 V_357 , int type , int V_61 , int V_3 )
{
struct V_356 * V_358 ;
int V_107 = F_281 ( V_61 ) ;
V_358 = (struct V_356 * ) F_255 ( V_24 , F_282 ( V_107 ) ) ;
V_358 -> V_359 = type ;
V_358 -> V_360 = V_107 ;
V_358 -> V_361 = V_3 ;
V_358 -> V_362 = V_159 ;
V_358 -> V_363 = V_357 ;
if ( ! F_283 ( V_107 ) || F_282 ( V_107 ) - V_107 != 0 )
memset ( F_284 ( V_358 ) + V_61 , 0 , F_282 ( V_107 ) - V_107 ) ;
return V_358 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_364 * V_176 ;
struct V_23 * V_24 = NULL ;
struct V_356 * V_358 ;
int V_61 , V_81 = - V_51 ;
int V_365 ;
F_63 ( V_46 -> V_208 ) ;
if ( ! V_46 -> V_134 ) {
V_81 = - V_13 ;
goto V_366;
}
V_176 = & V_46 -> V_176 ;
V_365 = F_285 ( int , V_176 -> V_367 , V_275 ) ;
if ( ! F_46 ( V_2 ) &&
F_59 ( & V_2 -> V_175 ) >= V_2 -> V_279 )
goto V_366;
if ( V_365 < V_46 -> V_345 ) {
V_24 = F_228 ( V_2 ,
V_46 -> V_345 ,
V_46 -> V_159 ,
V_65 |
V_68 |
V_69 ) ;
if ( V_24 )
F_286 ( V_24 , F_287 ( V_24 ) -
V_46 -> V_345 ) ;
}
if ( ! V_24 )
V_24 = F_228 ( V_2 , V_365 , V_46 -> V_159 ,
V_65 ) ;
if ( ! V_24 )
goto V_366;
F_118 ( V_24 , V_2 ) ;
V_61 = V_176 -> V_368 ( V_24 , V_176 ) ;
if ( V_61 > 0 ) {
F_69 ( V_46 -> V_208 ) ;
if ( F_227 ( V_2 , V_24 ) )
F_104 ( V_24 ) ;
else
F_214 ( V_2 , V_24 ) ;
return 0 ;
}
V_358 = F_288 ( V_24 , V_176 , V_369 , sizeof( V_61 ) , V_370 ) ;
if ( ! V_358 )
goto V_366;
F_289 ( V_176 , V_358 ) ;
memcpy ( F_284 ( V_358 ) , & V_61 , sizeof( V_61 ) ) ;
if ( F_227 ( V_2 , V_24 ) )
F_104 ( V_24 ) ;
else
F_214 ( V_2 , V_24 ) ;
if ( V_176 -> V_177 )
V_176 -> V_177 ( V_176 ) ;
V_46 -> V_134 = false ;
F_69 ( V_46 -> V_208 ) ;
F_17 ( V_176 -> V_17 ) ;
F_220 ( V_176 -> V_24 ) ;
return 0 ;
V_366:
F_69 ( V_46 -> V_208 ) ;
F_104 ( V_24 ) ;
return V_81 ;
}
int F_290 ( struct V_1 * V_267 , struct V_23 * V_24 ,
const struct V_356 * V_358 ,
struct V_371 * V_372 )
{
struct V_364 * V_176 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int V_22 ;
if ( F_44 ( V_24 ) ) {
V_24 = F_291 ( V_24 , V_65 ) ;
if ( V_24 == NULL )
return - V_51 ;
} else
F_38 ( & V_24 -> V_162 ) ;
V_2 = F_147 ( F_143 ( V_267 ) , V_267 -> V_25 , F_45 ( V_24 ) . V_159 ) ;
if ( V_2 == NULL ) {
V_22 = - V_268 ;
goto V_373;
}
V_46 = F_2 ( V_2 ) ;
F_63 ( V_46 -> V_208 ) ;
if ( V_46 -> V_134 ) {
V_22 = - V_84 ;
goto V_374;
}
if ( ! F_168 ( V_372 -> V_17 ) ) {
V_22 = - V_221 ;
goto V_374;
}
V_176 = & V_46 -> V_176 ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_368 = V_372 -> V_368 ;
V_176 -> V_177 = V_372 -> V_177 ;
V_176 -> V_358 = V_358 ;
V_176 -> V_139 = V_372 -> V_139 ;
V_176 -> V_17 = V_372 -> V_17 ;
V_176 -> V_367 = V_372 -> V_367 ;
V_176 -> V_24 = V_24 ;
V_46 -> V_134 = true ;
F_69 ( V_46 -> V_208 ) ;
V_22 = F_90 ( V_2 ) ;
F_114 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return - V_375 ;
V_374:
F_114 ( V_2 ) ;
F_69 ( V_46 -> V_208 ) ;
V_373:
F_104 ( V_24 ) ;
return V_22 ;
}
void F_292 ( struct V_23 * V_376 , struct V_356 * V_358 , int V_81 )
{
struct V_23 * V_24 ;
struct V_356 * V_377 ;
struct V_378 * V_379 ;
T_6 V_380 = sizeof( * V_379 ) ;
if ( V_81 )
V_380 += V_360 ( V_358 ) ;
V_24 = F_228 ( V_376 -> V_2 , F_293 ( V_380 ) ,
F_45 ( V_376 ) . V_159 , V_65 ) ;
if ( ! V_24 ) {
struct V_1 * V_2 ;
V_2 = F_147 ( F_143 ( V_376 -> V_2 ) ,
V_376 -> V_2 -> V_25 ,
F_45 ( V_376 ) . V_159 ) ;
if ( V_2 ) {
V_2 -> V_50 = V_51 ;
V_2 -> V_52 ( V_2 ) ;
F_114 ( V_2 ) ;
}
return;
}
V_377 = F_280 ( V_24 , F_45 ( V_376 ) . V_159 , V_358 -> V_363 ,
V_381 , V_380 , 0 ) ;
V_379 = F_284 ( V_377 ) ;
V_379 -> error = V_81 ;
memcpy ( & V_379 -> V_145 , V_358 , V_81 ? V_358 -> V_360 : sizeof( * V_358 ) ) ;
F_106 ( V_376 -> V_2 , V_24 , F_45 ( V_376 ) . V_159 , V_156 ) ;
}
int F_294 ( struct V_23 * V_24 , int (* V_176)( struct V_23 * ,
struct V_356 * ) )
{
struct V_356 * V_358 ;
int V_81 ;
while ( V_24 -> V_61 >= F_293 ( 0 ) ) {
int V_382 ;
V_358 = F_295 ( V_24 ) ;
V_81 = 0 ;
if ( V_358 -> V_360 < V_383 || V_24 -> V_61 < V_358 -> V_360 )
return 0 ;
if ( ! ( V_358 -> V_361 & V_384 ) )
goto V_385;
if ( V_358 -> V_359 < V_386 )
goto V_385;
V_81 = V_176 ( V_24 , V_358 ) ;
if ( V_81 == - V_375 )
goto V_387;
V_385:
if ( V_358 -> V_361 & V_388 || V_81 )
F_292 ( V_24 , V_358 , V_81 ) ;
V_387:
V_382 = F_282 ( V_358 -> V_360 ) ;
if ( V_382 > V_24 -> V_61 )
V_382 = V_24 -> V_61 ;
F_296 ( V_24 , V_382 ) ;
}
return 0 ;
}
int F_297 ( struct V_1 * V_2 , struct V_23 * V_24 , T_1 V_159 ,
unsigned int V_8 , int V_389 , T_2 V_3 )
{
int V_81 = 0 ;
if ( V_8 ) {
int V_390 = 0 ;
if ( V_389 ) {
F_38 ( & V_24 -> V_162 ) ;
V_390 = V_159 ;
}
V_81 = F_298 ( V_2 , V_24 , V_390 , V_8 , V_3 ) ;
}
if ( V_389 ) {
int V_290 ;
V_290 = F_299 ( V_2 , V_24 , V_159 ) ;
if ( ! V_81 || V_81 == - V_308 )
V_81 = V_290 ;
}
return V_81 ;
}
static struct V_1 * F_300 ( struct V_391 * V_357 , T_7 V_126 )
{
struct V_392 * V_393 = V_357 -> V_394 ;
int V_62 , V_395 ;
struct V_45 * V_46 ;
struct V_1 * V_396 ;
T_7 V_397 = 0 ;
for ( V_62 = 0 ; V_62 < V_220 ; V_62 ++ ) {
struct V_398 * V_399 = & V_195 [ V_62 ] . V_194 ;
const struct V_400 * V_196 = F_301 ( V_399 -> V_196 , V_399 ) ;
for ( V_395 = 0 ; V_395 < V_196 -> V_107 ; V_395 ++ ) {
F_302 (nlk, tbl->buckets[j], node) {
V_396 = (struct V_1 * ) V_46 ;
if ( F_143 ( V_396 ) != F_303 ( V_357 ) )
continue;
if ( V_397 == V_126 ) {
V_393 -> V_401 = V_62 ;
V_393 -> V_402 = V_395 ;
return V_396 ;
}
++ V_397 ;
}
}
}
return NULL ;
}
static void * F_304 ( struct V_391 * V_357 , T_7 * V_126 )
__acquires( V_7 ) __acquires( T_8 )
{
F_137 ( & V_7 ) ;
F_32 () ;
return * V_126 ? F_300 ( V_357 , * V_126 - 1 ) : V_403 ;
}
static void * F_305 ( struct V_391 * V_357 , void * V_404 , T_7 * V_126 )
{
struct V_398 * V_399 ;
struct V_45 * V_46 ;
struct V_392 * V_393 ;
struct V_191 * V_191 ;
int V_62 , V_395 ;
++ * V_126 ;
if ( V_404 == V_403 )
return F_300 ( V_357 , 0 ) ;
V_191 = F_303 ( V_357 ) ;
V_393 = V_357 -> V_394 ;
V_46 = V_404 ;
V_62 = V_393 -> V_401 ;
V_399 = & V_195 [ V_62 ] . V_194 ;
F_306 (nlk, nlk->node.next, ht, node)
if ( F_142 ( F_143 ( (struct V_1 * ) V_46 ) , V_191 ) )
return V_46 ;
V_395 = V_393 -> V_402 + 1 ;
do {
const struct V_400 * V_196 = F_301 ( V_399 -> V_196 , V_399 ) ;
for (; V_395 < V_196 -> V_107 ; V_395 ++ ) {
F_306 (nlk, tbl->buckets[j], ht, node) {
if ( F_142 ( F_143 ( (struct V_1 * ) V_46 ) , V_191 ) ) {
V_393 -> V_401 = V_62 ;
V_393 -> V_402 = V_395 ;
return V_46 ;
}
}
}
V_395 = 0 ;
} while ( ++ V_62 < V_220 );
return NULL ;
}
static void F_307 ( struct V_391 * V_357 , void * V_404 )
__releases( T_8 ) __releases( V_7 )
{
F_34 () ;
F_138 ( & V_7 ) ;
}
static int F_308 ( struct V_391 * V_357 , void * V_404 )
{
if ( V_404 == V_403 ) {
F_309 ( V_357 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_396 = V_404 ;
struct V_45 * V_46 = F_2 ( V_396 ) ;
F_310 ( V_357 , L_6 ,
V_396 ,
V_396 -> V_25 ,
V_46 -> V_159 ,
V_46 -> V_181 ? ( T_1 ) V_46 -> V_181 [ 0 ] : 0 ,
F_311 ( V_396 ) ,
F_312 ( V_396 ) ,
V_46 -> V_134 ,
F_59 ( & V_396 -> V_205 ) ,
F_59 ( & V_396 -> V_53 ) ,
F_313 ( V_396 )
) ;
}
return 0 ;
}
static int F_314 ( struct V_270 * V_270 , struct V_102 * V_102 )
{
return F_315 ( V_270 , V_102 , & V_405 ,
sizeof( struct V_392 ) ) ;
}
int F_316 ( struct V_406 * V_407 )
{
return F_317 ( & V_227 , V_407 ) ;
}
int F_318 ( struct V_406 * V_407 )
{
return F_319 ( & V_227 , V_407 ) ;
}
static int T_9 F_320 ( struct V_191 * V_191 )
{
#ifdef F_321
if ( ! F_322 ( L_7 , 0 , V_191 -> V_408 , & V_409 ) )
return - V_36 ;
#endif
return 0 ;
}
static void T_10 F_323 ( struct V_191 * V_191 )
{
#ifdef F_321
F_324 ( L_7 , V_191 -> V_408 ) ;
#endif
}
static void T_11 F_325 ( void )
{
struct V_197 * V_197 ;
int V_181 = 32 ;
V_197 = F_272 ( sizeof( * V_197 ) + F_193 ( V_181 ) , V_65 ) ;
if ( ! V_197 )
F_326 ( L_8 ) ;
F_125 () ;
V_195 [ V_27 ] . V_181 = V_181 ;
F_273 ( V_195 [ V_27 ] . V_197 , V_197 ) ;
V_195 [ V_27 ] . V_17 = V_410 ;
V_195 [ V_27 ] . V_222 = 1 ;
V_195 [ V_27 ] . V_3 = V_263 ;
F_134 () ;
}
static int T_11 F_327 ( void )
{
int V_62 ;
int V_81 = F_328 ( & V_212 , 0 ) ;
struct V_411 V_412 = {
. V_413 = F_329 ( struct V_45 , V_204 ) ,
. V_414 = F_329 ( struct V_45 , V_159 ) ,
. V_415 = sizeof( T_1 ) ,
. V_416 = V_417 ,
. V_418 = 16 ,
. V_419 = V_420 ,
. V_421 = V_422 ,
. V_423 = F_3 ,
} ;
if ( V_81 != 0 )
goto V_20;
F_330 ( sizeof( struct V_233 ) > F_331 ( struct V_23 , V_176 ) ) ;
V_195 = F_57 ( V_220 , sizeof( * V_195 ) , V_65 ) ;
if ( ! V_195 )
goto F_326;
for ( V_62 = 0 ; V_62 < V_220 ; V_62 ++ ) {
if ( F_332 ( & V_195 [ V_62 ] . V_194 , & V_412 ) < 0 ) {
while ( -- V_62 > 0 )
F_333 ( & V_195 [ V_62 ] . V_194 ) ;
F_52 ( V_195 ) ;
goto F_326;
}
}
F_334 ( & V_16 ) ;
F_325 () ;
F_335 ( & V_424 ) ;
F_336 ( & V_425 ) ;
F_337 () ;
V_20:
return V_81 ;
F_326:
F_326 ( L_9 ) ;
}
