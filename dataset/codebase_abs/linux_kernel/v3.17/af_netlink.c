static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static int F_3 ( void )
{
#ifdef F_4
return ( V_5 ) ? F_5 ( & V_6 ) : 1 ;
#else
return 1 ;
#endif
}
static inline T_1 F_6 ( T_1 V_7 )
{
return V_7 ? 1 << ( V_7 - 1 ) : 0 ;
}
int F_7 ( struct V_8 * V_9 )
{
if ( F_8 ( V_9 -> V_10 -> type != V_11 ) )
return - V_12 ;
F_9 ( & V_13 ) ;
F_10 ( & V_9 -> V_14 , & V_15 ) ;
F_11 ( & V_13 ) ;
if ( V_9 -> V_16 )
F_12 ( V_9 -> V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
bool V_17 = false ;
struct V_8 * V_18 ;
F_9 ( & V_13 ) ;
F_14 (tmp, &netlink_tap_all, list) {
if ( V_9 == V_18 ) {
F_15 ( & V_9 -> V_14 ) ;
V_17 = true ;
goto V_19;
}
}
F_16 ( L_1 , V_9 ) ;
V_19:
F_11 ( & V_13 ) ;
if ( V_17 && V_9 -> V_16 )
F_17 ( V_9 -> V_16 ) ;
return V_17 ? 0 : - V_20 ;
}
int F_18 ( struct V_8 * V_9 )
{
int V_21 ;
V_21 = F_13 ( V_9 ) ;
F_19 () ;
return V_21 ;
}
static bool F_20 ( const struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
switch ( V_2 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return true ;
}
return false ;
}
static int F_21 ( struct V_22 * V_23 ,
struct V_33 * V_10 )
{
struct V_22 * V_34 ;
struct V_1 * V_2 = V_23 -> V_2 ;
int V_21 = - V_35 ;
F_22 ( V_10 ) ;
V_34 = F_23 ( V_23 , V_36 ) ;
if ( V_34 ) {
V_34 -> V_10 = V_10 ;
V_34 -> V_37 = F_24 ( ( V_38 ) V_2 -> V_24 ) ;
V_34 -> V_39 = F_1 ( V_2 ) ?
V_40 : V_41 ;
F_25 ( V_34 ) ;
V_21 = F_26 ( V_34 ) ;
if ( F_8 ( V_21 > 0 ) )
V_21 = F_27 ( V_21 ) ;
}
F_28 ( V_10 ) ;
return V_21 ;
}
static void F_29 ( struct V_22 * V_23 )
{
int V_21 ;
struct V_8 * V_18 ;
if ( ! F_20 ( V_23 ) )
return;
F_30 (tmp, &netlink_tap_all, list) {
V_21 = F_21 ( V_23 , V_18 -> V_10 ) ;
if ( F_8 ( V_21 ) )
break;
}
}
static void F_31 ( struct V_22 * V_23 )
{
F_32 () ;
if ( F_8 ( ! F_33 ( & V_15 ) ) )
F_29 ( V_23 ) ;
F_34 () ;
}
static void F_35 ( struct V_1 * V_42 , struct V_1 * V_43 ,
struct V_22 * V_23 )
{
if ( ! ( F_1 ( V_42 ) && F_1 ( V_43 ) ) )
F_31 ( V_23 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
if ( ! ( V_45 -> V_3 & V_46 ) ) {
if ( ! F_37 ( V_47 , & F_2 ( V_2 ) -> V_48 ) ) {
V_2 -> V_49 = V_50 ;
V_2 -> V_51 ( V_2 ) ;
}
}
F_38 ( & V_2 -> V_52 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
if ( F_40 ( & V_2 -> V_53 ) )
F_41 ( V_47 , & V_45 -> V_48 ) ;
if ( ! F_42 ( V_47 , & V_45 -> V_48 ) )
F_43 ( & V_45 -> V_54 ) ;
}
static bool F_44 ( const struct V_22 * V_23 )
{
return F_45 ( V_23 ) . V_3 & V_55 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_56 . V_57 != NULL ;
}
static bool F_47 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_58 . V_57 != NULL ;
}
static void F_48 ( void * * V_57 , unsigned int V_59 , unsigned int V_60 )
{
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
if ( V_57 [ V_61 ] != NULL ) {
if ( F_49 ( V_57 [ V_61 ] ) )
F_50 ( V_57 [ V_61 ] ) ;
else
F_51 ( ( unsigned long ) V_57 [ V_61 ] , V_59 ) ;
}
}
F_52 ( V_57 ) ;
}
static void * F_53 ( unsigned long V_59 )
{
void * V_62 ;
T_2 V_63 = V_64 | V_65 | V_66 |
V_67 | V_68 ;
V_62 = ( void * ) F_54 ( V_63 , V_59 ) ;
if ( V_62 != NULL )
return V_62 ;
V_62 = F_55 ( ( 1 << V_59 ) * V_69 ) ;
if ( V_62 != NULL )
return V_62 ;
V_63 &= ~ V_68 ;
return ( void * ) F_54 ( V_63 , V_59 ) ;
}
static void * * F_56 ( struct V_44 * V_45 ,
struct V_70 * V_71 , unsigned int V_59 )
{
unsigned int V_72 = V_71 -> V_73 ;
unsigned int V_61 ;
void * * V_57 ;
V_57 = F_57 ( V_72 , sizeof( void * ) , V_64 ) ;
if ( V_57 == NULL )
return NULL ;
for ( V_61 = 0 ; V_61 < V_72 ; V_61 ++ ) {
V_57 [ V_61 ] = F_53 ( V_59 ) ;
if ( V_57 [ V_61 ] == NULL )
goto V_74;
}
return V_57 ;
V_74:
F_48 ( V_57 , V_59 , V_72 ) ;
return NULL ;
}
static int F_58 ( struct V_1 * V_2 , struct V_70 * V_71 ,
bool V_75 , bool V_58 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
void * * V_57 = NULL ;
unsigned int V_59 = 0 ;
int V_80 ;
V_77 = V_58 ? & V_45 -> V_58 : & V_45 -> V_56 ;
V_79 = V_58 ? & V_2 -> V_81 : & V_2 -> V_53 ;
if ( ! V_75 ) {
if ( F_59 ( & V_45 -> V_82 ) )
return - V_83 ;
if ( F_59 ( & V_77 -> V_84 ) )
return - V_83 ;
}
if ( V_71 -> V_73 ) {
if ( V_77 -> V_57 != NULL )
return - V_83 ;
if ( ( int ) V_71 -> V_85 <= 0 )
return - V_12 ;
if ( ! F_60 ( V_71 -> V_85 ) )
return - V_12 ;
if ( V_71 -> V_86 < V_87 )
return - V_12 ;
if ( ! F_61 ( V_71 -> V_86 , V_88 ) )
return - V_12 ;
V_77 -> V_89 = V_71 -> V_85 /
V_71 -> V_86 ;
if ( V_77 -> V_89 == 0 )
return - V_12 ;
if ( V_77 -> V_89 * V_71 -> V_73 !=
V_71 -> V_90 )
return - V_12 ;
V_59 = F_62 ( V_71 -> V_85 ) ;
V_57 = F_56 ( V_45 , V_71 , V_59 ) ;
if ( V_57 == NULL )
return - V_35 ;
} else {
if ( V_71 -> V_90 )
return - V_12 ;
}
V_80 = - V_83 ;
F_63 ( & V_45 -> V_91 ) ;
if ( V_75 || F_59 ( & V_45 -> V_82 ) == 0 ) {
V_80 = 0 ;
F_64 ( & V_79 -> V_92 ) ;
V_77 -> V_93 = V_71 -> V_90 - 1 ;
V_77 -> V_94 = 0 ;
V_77 -> V_95 = V_71 -> V_86 ;
V_77 -> V_96 = V_71 -> V_85 / V_69 ;
F_65 ( V_77 -> V_97 , V_71 -> V_73 ) ;
F_65 ( V_77 -> V_98 , V_59 ) ;
F_65 ( V_77 -> V_57 , V_57 ) ;
F_66 ( V_79 ) ;
F_67 ( & V_79 -> V_92 ) ;
F_68 ( F_59 ( & V_45 -> V_82 ) ) ;
}
F_69 ( & V_45 -> V_91 ) ;
if ( V_57 )
F_48 ( V_57 , V_59 , V_71 -> V_73 ) ;
return V_80 ;
}
static void F_70 ( struct V_99 * V_100 )
{
struct V_101 * V_101 = V_100 -> V_102 ;
struct V_103 * V_1 = V_101 -> V_104 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_38 ( & F_2 ( V_2 ) -> V_82 ) ;
}
static void F_71 ( struct V_99 * V_100 )
{
struct V_101 * V_101 = V_100 -> V_102 ;
struct V_103 * V_1 = V_101 -> V_104 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_72 ( & F_2 ( V_2 ) -> V_82 ) ;
}
static int F_73 ( struct V_101 * V_101 , struct V_103 * V_1 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_76 * V_77 ;
unsigned long V_105 , V_106 , V_107 ;
unsigned int V_61 ;
int V_80 = - V_12 ;
if ( V_100 -> V_108 )
return - V_12 ;
F_63 ( & V_45 -> V_91 ) ;
V_107 = 0 ;
for ( V_77 = & V_45 -> V_56 ; V_77 <= & V_45 -> V_58 ; V_77 ++ ) {
if ( V_77 -> V_57 == NULL )
continue;
V_107 += V_77 -> V_97 * V_77 -> V_96 * V_69 ;
}
if ( V_107 == 0 )
goto V_19;
V_106 = V_100 -> V_109 - V_100 -> V_110 ;
if ( V_106 != V_107 )
goto V_19;
V_105 = V_100 -> V_110 ;
for ( V_77 = & V_45 -> V_56 ; V_77 <= & V_45 -> V_58 ; V_77 ++ ) {
if ( V_77 -> V_57 == NULL )
continue;
for ( V_61 = 0 ; V_61 < V_77 -> V_97 ; V_61 ++ ) {
struct V_111 * V_111 ;
void * V_112 = V_77 -> V_57 [ V_61 ] ;
unsigned int V_113 ;
for ( V_113 = 0 ; V_113 < V_77 -> V_96 ; V_113 ++ ) {
V_111 = F_74 ( V_112 ) ;
V_80 = F_75 ( V_100 , V_105 , V_111 ) ;
if ( V_80 < 0 )
goto V_19;
V_105 += V_69 ;
V_112 += V_69 ;
}
}
}
F_38 ( & V_45 -> V_82 ) ;
V_100 -> V_114 = & V_115 ;
V_80 = 0 ;
V_19:
F_69 ( & V_45 -> V_91 ) ;
return V_80 ;
}
static void F_76 ( const struct V_116 * V_117 )
{
#if V_118 == 1
struct V_111 * V_119 , * V_120 ;
V_119 = F_74 ( V_117 + V_69 ) ;
V_120 = F_74 ( ( void * ) V_117 + V_87 + V_117 -> V_121 - 1 ) ;
while ( V_119 <= V_120 ) {
F_77 ( V_119 ) ;
V_119 ++ ;
}
#endif
}
static enum V_122 F_78 ( const struct V_116 * V_117 )
{
F_79 () ;
F_77 ( F_74 ( V_117 ) ) ;
return V_117 -> V_123 ;
}
static void F_80 ( struct V_116 * V_117 ,
enum V_122 V_124 )
{
V_117 -> V_123 = V_124 ;
F_77 ( F_74 ( V_117 ) ) ;
F_81 () ;
}
static struct V_116 *
F_82 ( const struct V_76 * V_77 , unsigned int V_125 )
{
unsigned int V_126 , V_127 ;
V_126 = V_125 / V_77 -> V_89 ;
V_127 = V_125 % V_77 -> V_89 ;
return V_77 -> V_57 [ V_126 ] + ( V_127 * V_77 -> V_95 ) ;
}
static struct V_116 *
F_83 ( const struct V_76 * V_77 , unsigned int V_125 ,
enum V_122 V_124 )
{
struct V_116 * V_117 ;
V_117 = F_82 ( V_77 , V_125 ) ;
if ( F_78 ( V_117 ) != V_124 )
return NULL ;
return V_117 ;
}
static struct V_116 *
F_84 ( const struct V_76 * V_77 ,
enum V_122 V_124 )
{
return F_83 ( V_77 , V_77 -> V_94 , V_124 ) ;
}
static struct V_116 *
F_85 ( const struct V_76 * V_77 ,
enum V_122 V_124 )
{
unsigned int V_128 ;
V_128 = V_77 -> V_94 ? V_77 -> V_94 - 1 : V_77 -> V_93 ;
return F_83 ( V_77 , V_128 , V_124 ) ;
}
static void F_86 ( struct V_76 * V_77 )
{
V_77 -> V_94 = V_77 -> V_94 != V_77 -> V_93 ? V_77 -> V_94 + 1 : 0 ;
}
static void F_87 ( struct V_76 * V_77 )
{
unsigned int V_94 = V_77 -> V_94 , V_125 = V_94 ;
const struct V_116 * V_117 ;
do {
V_117 = F_82 ( V_77 , V_125 ) ;
if ( V_117 -> V_123 == V_129 )
break;
if ( V_117 -> V_123 != V_130 )
break;
F_86 ( V_77 ) ;
} while ( V_77 -> V_94 != V_94 );
}
static bool F_88 ( struct V_44 * V_45 )
{
struct V_76 * V_77 = & V_45 -> V_56 ;
struct V_116 * V_117 ;
unsigned int V_131 ;
V_117 = F_84 ( V_77 , V_129 ) ;
if ( V_117 == NULL )
return false ;
V_131 = V_77 -> V_94 + V_77 -> V_93 / 2 ;
if ( V_131 > V_77 -> V_93 )
V_131 -= V_77 -> V_93 ;
V_117 = F_82 ( V_77 , V_131 ) ;
return V_117 -> V_123 == V_129 ;
}
static unsigned int F_89 ( struct V_101 * V_101 , struct V_103 * V_1 ,
T_3 * V_54 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
unsigned int V_132 ;
int V_80 ;
if ( V_45 -> V_56 . V_57 != NULL ) {
while ( V_45 -> V_133 && F_88 ( V_45 ) ) {
V_80 = F_90 ( V_2 ) ;
if ( V_80 < 0 ) {
V_2 -> V_49 = - V_80 ;
V_2 -> V_51 ( V_2 ) ;
break;
}
}
F_39 ( V_2 ) ;
}
V_132 = F_91 ( V_101 , V_1 , V_54 ) ;
F_64 ( & V_2 -> V_53 . V_92 ) ;
if ( V_45 -> V_56 . V_57 ) {
F_87 ( & V_45 -> V_56 ) ;
if ( ! F_85 ( & V_45 -> V_56 , V_129 ) )
V_132 |= V_134 | V_135 ;
}
F_67 ( & V_2 -> V_53 . V_92 ) ;
F_64 ( & V_2 -> V_81 . V_92 ) ;
if ( V_45 -> V_58 . V_57 ) {
if ( F_84 ( & V_45 -> V_58 , V_129 ) )
V_132 |= V_136 | V_137 ;
}
F_67 ( & V_2 -> V_81 . V_92 ) ;
return V_132 ;
}
static struct V_116 * F_92 ( struct V_22 * V_23 )
{
return (struct V_116 * ) ( V_23 -> V_94 - V_87 ) ;
}
static void F_93 ( struct V_22 * V_23 , struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_116 * V_117 )
{
unsigned int V_106 ;
void * V_138 ;
V_106 = V_77 -> V_95 - V_87 ;
V_138 = ( void * ) V_117 + V_87 ;
V_23 -> V_94 = V_138 ;
V_23 -> V_138 = V_138 ;
F_94 ( V_23 ) ;
V_23 -> V_139 = V_23 -> V_140 + V_106 ;
V_23 -> V_60 = 0 ;
V_23 -> V_141 = V_142 ;
F_45 ( V_23 ) . V_3 |= V_55 ;
F_45 ( V_23 ) . V_2 = V_2 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_143 * V_144 ,
T_1 V_145 , T_1 V_146 ,
struct V_147 * V_148 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_76 * V_77 ;
struct V_116 * V_117 ;
struct V_22 * V_23 ;
unsigned int V_149 ;
bool V_150 = true ;
int V_80 = 0 , V_60 = 0 ;
if ( F_96 ( & V_2 -> V_151 -> V_101 -> V_152 ) > 2 ||
F_59 ( & V_45 -> V_82 ) > 1 )
V_150 = false ;
F_63 ( & V_45 -> V_91 ) ;
V_77 = & V_45 -> V_58 ;
V_149 = V_77 -> V_95 - V_87 ;
do {
V_117 = F_84 ( V_77 , V_153 ) ;
if ( V_117 == NULL ) {
if ( ! ( V_144 -> V_154 & V_155 ) &&
F_59 ( & V_45 -> V_58 . V_84 ) )
F_97 () ;
continue;
}
if ( V_117 -> V_121 > V_149 ) {
V_80 = - V_12 ;
goto V_19;
}
F_76 ( V_117 ) ;
if ( F_98 ( V_145 == 0 && V_146 == 0 && V_150 ) ) {
V_23 = F_99 ( V_64 ) ;
if ( V_23 == NULL ) {
V_80 = - V_50 ;
goto V_19;
}
F_100 ( V_2 ) ;
F_93 ( V_23 , V_2 , V_77 , V_117 ) ;
F_45 ( V_23 ) . V_3 |= V_156 ;
F_101 ( V_23 , V_117 -> V_121 ) ;
F_80 ( V_117 , V_157 ) ;
F_38 ( & V_77 -> V_84 ) ;
} else {
V_23 = F_102 ( V_117 -> V_121 , V_64 ) ;
if ( V_23 == NULL ) {
V_80 = - V_50 ;
goto V_19;
}
F_101 ( V_23 , V_117 -> V_121 ) ;
memcpy ( V_23 -> V_138 , ( void * ) V_117 + V_87 , V_117 -> V_121 ) ;
F_80 ( V_117 , V_129 ) ;
}
F_86 ( V_77 ) ;
F_45 ( V_23 ) . V_158 = V_45 -> V_158 ;
F_45 ( V_23 ) . V_146 = V_146 ;
F_45 ( V_23 ) . V_159 = V_148 -> V_160 -> V_159 ;
V_80 = F_103 ( V_2 , V_23 ) ;
if ( V_80 ) {
F_104 ( V_23 ) ;
goto V_19;
}
if ( F_8 ( V_146 ) ) {
F_38 ( & V_23 -> V_161 ) ;
F_105 ( V_2 , V_23 , V_145 , V_146 ,
V_64 ) ;
}
V_80 = F_106 ( V_2 , V_23 , V_145 ,
V_144 -> V_154 & V_155 ) ;
if ( V_80 < 0 )
goto V_19;
V_60 += V_80 ;
} while ( V_117 != NULL ||
( ! ( V_144 -> V_154 & V_155 ) &&
F_59 ( & V_45 -> V_58 . V_84 ) ) );
if ( V_60 > 0 )
V_80 = V_60 ;
V_19:
F_69 ( & V_45 -> V_91 ) ;
return V_80 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_116 * V_117 ;
V_117 = F_92 ( V_23 ) ;
V_117 -> V_121 = V_23 -> V_60 ;
V_117 -> V_162 = F_45 ( V_23 ) . V_146 ;
V_117 -> V_163 = F_45 ( V_23 ) . V_159 . V_164 ;
V_117 -> V_165 = F_108 ( F_109 ( V_2 ) , F_45 ( V_23 ) . V_159 . V_166 ) ;
V_117 -> V_167 = F_110 ( F_109 ( V_2 ) , F_45 ( V_23 ) . V_159 . V_168 ) ;
F_76 ( V_117 ) ;
F_80 ( V_117 , V_153 ) ;
F_45 ( V_23 ) . V_3 |= V_169 ;
F_104 ( V_23 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_76 * V_77 = & V_45 -> V_56 ;
struct V_116 * V_117 ;
F_64 ( & V_2 -> V_53 . V_92 ) ;
V_117 = F_84 ( V_77 , V_129 ) ;
if ( V_117 == NULL ) {
F_67 ( & V_2 -> V_53 . V_92 ) ;
F_104 ( V_23 ) ;
F_36 ( V_2 ) ;
return;
}
F_86 ( V_77 ) ;
F_112 ( & V_2 -> V_53 , V_23 ) ;
F_67 ( & V_2 -> V_53 . V_92 ) ;
V_117 -> V_121 = V_23 -> V_60 ;
V_117 -> V_162 = F_45 ( V_23 ) . V_146 ;
V_117 -> V_163 = F_45 ( V_23 ) . V_159 . V_164 ;
V_117 -> V_165 = F_108 ( F_109 ( V_2 ) , F_45 ( V_23 ) . V_159 . V_166 ) ;
V_117 -> V_167 = F_110 ( F_109 ( V_2 ) , F_45 ( V_23 ) . V_159 . V_168 ) ;
F_80 ( V_117 , V_170 ) ;
}
static void V_142 ( struct V_22 * V_23 )
{
#ifdef F_113
struct V_116 * V_117 ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
if ( F_44 ( V_23 ) ) {
V_117 = F_92 ( V_23 ) ;
V_2 = F_45 ( V_23 ) . V_2 ;
if ( F_45 ( V_23 ) . V_3 & V_156 ) {
F_80 ( V_117 , V_129 ) ;
V_77 = & F_2 ( V_2 ) -> V_58 ;
} else {
if ( ! ( F_45 ( V_23 ) . V_3 & V_169 ) ) {
V_117 -> V_121 = 0 ;
F_80 ( V_117 , V_153 ) ;
}
V_77 = & F_2 ( V_2 ) -> V_56 ;
}
F_68 ( F_59 ( & V_77 -> V_84 ) == 0 ) ;
F_72 ( & V_77 -> V_84 ) ;
F_114 ( V_2 ) ;
V_23 -> V_94 = NULL ;
}
#endif
if ( F_49 ( V_23 -> V_94 ) ) {
if ( ! V_23 -> V_171 ||
! F_115 ( & ( F_116 ( V_23 ) -> V_172 ) ) )
F_50 ( V_23 -> V_94 ) ;
V_23 -> V_94 = NULL ;
}
if ( V_23 -> V_2 != NULL )
F_117 ( V_23 ) ;
}
static void F_118 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
F_68 ( V_23 -> V_2 != NULL ) ;
V_23 -> V_2 = V_2 ;
V_23 -> V_141 = V_142 ;
F_119 ( V_23 -> V_173 , & V_2 -> V_174 ) ;
F_120 ( V_2 , V_23 -> V_173 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
if ( V_45 -> V_133 ) {
if ( V_45 -> V_175 . V_176 )
V_45 -> V_175 . V_176 ( & V_45 -> V_175 ) ;
F_17 ( V_45 -> V_175 . V_16 ) ;
F_104 ( V_45 -> V_175 . V_23 ) ;
}
F_122 ( & V_2 -> V_53 ) ;
#ifdef F_113
if ( 1 ) {
struct V_70 V_71 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
if ( V_45 -> V_56 . V_57 )
F_58 ( V_2 , & V_71 , true , false ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
if ( V_45 -> V_58 . V_57 )
F_58 ( V_2 , & V_71 , true , true ) ;
}
#endif
if ( ! F_123 ( V_2 , V_177 ) ) {
F_124 ( V_178 L_2 , V_2 ) ;
return;
}
F_68 ( F_59 ( & V_2 -> V_174 ) ) ;
F_68 ( F_59 ( & V_2 -> V_179 ) ) ;
F_68 ( F_2 ( V_2 ) -> V_180 ) ;
}
void F_125 ( void )
__acquires( T_4 )
{
F_126 () ;
F_127 ( & T_4 ) ;
if ( F_59 ( & V_181 ) ) {
F_128 ( V_54 , V_182 ) ;
F_129 ( & V_183 , & V_54 ) ;
for (; ; ) {
F_130 ( V_184 ) ;
if ( F_59 ( & V_181 ) == 0 )
break;
F_131 ( & T_4 ) ;
F_97 () ;
F_127 ( & T_4 ) ;
}
F_132 ( V_185 ) ;
F_133 ( & V_183 , & V_54 ) ;
}
}
void F_134 ( void )
__releases( T_4 )
{
F_131 ( & T_4 ) ;
F_135 ( & V_183 ) ;
}
static inline void
F_136 ( void )
{
F_137 ( & T_4 ) ;
F_38 ( & V_181 ) ;
F_138 ( & T_4 ) ;
}
static inline void
F_139 ( void )
{
if ( F_140 ( & V_181 ) )
F_135 ( & V_183 ) ;
}
static bool F_141 ( void * V_186 , void * V_187 )
{
struct V_188 * V_189 = V_187 ;
struct V_1 * V_2 = V_186 ;
return F_2 ( V_2 ) -> V_158 == V_189 -> V_158 &&
F_142 ( F_143 ( V_2 ) , V_189 -> V_190 ) ;
}
static struct V_1 * F_144 ( struct V_191 * V_192 , T_1 V_158 ,
struct V_190 * V_190 )
{
struct V_188 V_187 = {
. V_190 = V_190 ,
. V_158 = V_158 ,
} ;
T_1 V_193 ;
V_193 = F_145 ( & V_192 -> V_193 , & V_158 , sizeof( V_158 ) ) ;
return F_146 ( & V_192 -> V_193 , V_193 ,
& F_141 , & V_187 ) ;
}
static struct V_1 * F_147 ( struct V_190 * V_190 , int V_37 , T_1 V_158 )
{
struct V_191 * V_192 = & V_194 [ V_37 ] ;
struct V_1 * V_2 ;
F_32 () ;
V_2 = F_144 ( V_192 , V_158 , V_190 ) ;
if ( V_2 )
F_100 ( V_2 ) ;
F_34 () ;
return V_2 ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_191 * V_195 = & V_194 [ V_2 -> V_24 ] ;
unsigned long V_132 ;
unsigned int V_61 ;
struct V_196 * V_196 ;
V_196 = F_149 ( V_195 -> V_196 ) ;
if ( ! V_196 )
return;
for ( V_61 = 0 ; V_61 < F_150 ( V_195 -> V_180 ) ; V_61 ++ ) {
V_132 = 0 ;
F_151 (sk, &tbl->mc_list) {
if ( V_61 < F_150 ( F_2 ( V_2 ) -> V_197 ) )
V_132 |= F_2 ( V_2 ) -> V_180 [ V_61 ] ;
}
V_196 -> V_198 [ V_61 ] = V_132 ;
}
}
static int F_152 ( struct V_1 * V_2 , struct V_190 * V_190 , T_1 V_158 )
{
struct V_191 * V_192 = & V_194 [ V_2 -> V_24 ] ;
int V_80 = - V_199 ;
F_63 ( & V_6 ) ;
if ( F_144 ( V_192 , V_158 , V_190 ) )
goto V_80;
V_80 = - V_83 ;
if ( F_2 ( V_2 ) -> V_158 )
goto V_80;
V_80 = - V_35 ;
if ( V_200 > 32 && F_8 ( V_192 -> V_193 . V_201 >= V_202 ) )
goto V_80;
F_2 ( V_2 ) -> V_158 = V_158 ;
F_100 ( V_2 ) ;
F_153 ( & V_192 -> V_193 , & F_2 ( V_2 ) -> V_203 , V_64 ) ;
V_80 = 0 ;
V_80:
F_69 ( & V_6 ) ;
return V_80 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_191 * V_192 ;
F_63 ( & V_6 ) ;
V_192 = & V_194 [ V_2 -> V_24 ] ;
if ( F_155 ( & V_192 -> V_193 , & F_2 ( V_2 ) -> V_203 , V_64 ) ) {
F_68 ( F_59 ( & V_2 -> V_204 ) == 1 ) ;
F_156 ( V_2 ) ;
}
F_69 ( & V_6 ) ;
F_125 () ;
if ( F_2 ( V_2 ) -> V_205 )
F_157 ( V_2 ) ;
F_134 () ;
}
static int F_158 ( struct V_190 * V_190 , struct V_103 * V_1 ,
struct V_206 * V_207 , int V_37 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
V_1 -> V_208 = & V_209 ;
V_2 = F_159 ( V_190 , V_210 , V_64 , & V_211 ) ;
if ( ! V_2 )
return - V_35 ;
F_160 ( V_1 , V_2 ) ;
V_45 = F_2 ( V_2 ) ;
if ( V_207 ) {
V_45 -> V_207 = V_207 ;
} else {
V_45 -> V_207 = & V_45 -> V_212 ;
F_161 ( V_45 -> V_207 ) ;
}
F_162 ( & V_45 -> V_54 ) ;
#ifdef F_113
F_161 ( & V_45 -> V_91 ) ;
#endif
V_2 -> V_213 = F_121 ;
V_2 -> V_24 = V_37 ;
return 0 ;
}
static int F_163 ( struct V_190 * V_190 , struct V_103 * V_1 , int V_37 ,
int V_214 )
{
struct V_16 * V_16 = NULL ;
struct V_206 * V_207 ;
struct V_44 * V_45 ;
int (* F_164)( int V_7 );
void (* F_165)( int V_7 );
int V_80 = 0 ;
V_1 -> V_48 = V_215 ;
if ( V_1 -> type != V_216 && V_1 -> type != V_217 )
return - V_218 ;
if ( V_37 < 0 || V_37 >= V_219 )
return - V_220 ;
F_136 () ;
#ifdef F_166
if ( ! V_194 [ V_37 ] . V_221 ) {
F_139 () ;
F_167 ( L_3 , V_210 , V_37 ) ;
F_136 () ;
}
#endif
if ( V_194 [ V_37 ] . V_221 &&
F_168 ( V_194 [ V_37 ] . V_16 ) )
V_16 = V_194 [ V_37 ] . V_16 ;
else
V_80 = - V_220 ;
V_207 = V_194 [ V_37 ] . V_207 ;
F_164 = V_194 [ V_37 ] . F_164 ;
F_165 = V_194 [ V_37 ] . F_165 ;
F_139 () ;
if ( V_80 < 0 )
goto V_19;
V_80 = F_158 ( V_190 , V_1 , V_207 , V_37 ) ;
if ( V_80 < 0 )
goto V_222;
F_169 () ;
F_170 ( V_190 , & V_211 , 1 ) ;
F_171 () ;
V_45 = F_2 ( V_1 -> V_2 ) ;
V_45 -> V_16 = V_16 ;
V_45 -> V_223 = F_164 ;
V_45 -> V_224 = F_165 ;
V_19:
return V_80 ;
V_222:
F_17 ( V_16 ) ;
goto V_19;
}
static int F_172 ( struct V_103 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 ;
if ( ! V_2 )
return 0 ;
F_154 ( V_2 ) ;
F_173 ( V_2 ) ;
V_45 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_174 ( & V_45 -> V_54 ) ;
F_122 ( & V_2 -> V_81 ) ;
if ( V_45 -> V_158 ) {
struct V_225 V_131 = {
. V_190 = F_143 ( V_2 ) ,
. V_37 = V_2 -> V_24 ,
. V_158 = V_45 -> V_158 ,
} ;
F_175 ( & V_226 ,
V_227 , & V_131 ) ;
}
F_17 ( V_45 -> V_16 ) ;
F_125 () ;
if ( F_1 ( V_2 ) ) {
F_176 ( V_194 [ V_2 -> V_24 ] . V_221 == 0 ) ;
if ( -- V_194 [ V_2 -> V_24 ] . V_221 == 0 ) {
struct V_196 * V_228 ;
V_228 = F_149 ( V_194 [ V_2 -> V_24 ] . V_196 ) ;
F_177 ( V_194 [ V_2 -> V_24 ] . V_196 , NULL ) ;
F_178 ( V_228 , V_229 ) ;
V_194 [ V_2 -> V_24 ] . V_16 = NULL ;
V_194 [ V_2 -> V_24 ] . F_164 = NULL ;
V_194 [ V_2 -> V_24 ] . F_165 = NULL ;
V_194 [ V_2 -> V_24 ] . V_3 = 0 ;
V_194 [ V_2 -> V_24 ] . V_221 = 0 ;
}
} else if ( V_45 -> V_205 ) {
F_148 ( V_2 ) ;
}
F_134 () ;
F_19 () ;
F_52 ( V_45 -> V_180 ) ;
V_45 -> V_180 = NULL ;
F_169 () ;
F_170 ( F_143 ( V_2 ) , & V_211 , - 1 ) ;
F_171 () ;
F_114 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_103 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_143 ( V_2 ) ;
struct V_191 * V_192 = & V_194 [ V_2 -> V_24 ] ;
T_5 V_158 = F_180 ( V_182 ) ;
int V_80 ;
static T_5 V_230 = - 4097 ;
V_231:
F_181 () ;
F_32 () ;
if ( F_144 ( V_192 , V_158 , V_190 ) ) {
V_158 = V_230 -- ;
if ( V_230 > - 4097 )
V_230 = - 4097 ;
F_34 () ;
goto V_231;
}
F_34 () ;
V_80 = F_152 ( V_2 , V_190 , V_158 ) ;
if ( V_80 == - V_199 )
goto V_231;
if ( V_80 == - V_83 )
V_80 = 0 ;
return V_80 ;
}
bool F_182 ( const struct V_232 * V_233 ,
struct V_234 * V_235 , int V_236 )
{
return ( ( V_233 -> V_3 & V_237 ) ||
F_183 ( V_233 -> V_2 -> V_151 -> V_101 , V_235 , V_236 ) ) &&
F_184 ( V_235 , V_236 ) ;
}
bool F_185 ( const struct V_22 * V_23 ,
struct V_234 * V_235 , int V_236 )
{
return F_182 ( & F_45 ( V_23 ) , V_235 , V_236 ) ;
}
bool F_186 ( const struct V_22 * V_23 , int V_236 )
{
return F_185 ( V_23 , & V_238 , V_236 ) ;
}
bool F_187 ( const struct V_22 * V_23 , int V_236 )
{
return F_185 ( V_23 , F_143 ( V_23 -> V_2 ) -> V_235 , V_236 ) ;
}
static inline int F_188 ( const struct V_103 * V_1 , unsigned int V_239 )
{
return ( V_194 [ V_1 -> V_2 -> V_24 ] . V_3 & V_239 ) ||
F_184 ( F_143 ( V_1 -> V_2 ) -> V_235 , V_240 ) ;
}
static void
F_189 ( struct V_1 * V_2 , unsigned int V_205 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
if ( V_45 -> V_205 && ! V_205 )
F_157 ( V_2 ) ;
else if ( ! V_45 -> V_205 && V_205 )
F_190 ( V_2 , & V_194 [ V_2 -> V_24 ] . V_241 ) ;
V_45 -> V_205 = V_205 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
unsigned int V_180 ;
unsigned long * V_242 ;
int V_80 = 0 ;
F_125 () ;
V_180 = V_194 [ V_2 -> V_24 ] . V_180 ;
if ( ! V_194 [ V_2 -> V_24 ] . V_221 ) {
V_80 = - V_243 ;
goto V_244;
}
if ( V_45 -> V_197 >= V_180 )
goto V_244;
V_242 = F_192 ( V_45 -> V_180 , F_193 ( V_180 ) , V_36 ) ;
if ( V_242 == NULL ) {
V_80 = - V_35 ;
goto V_244;
}
memset ( ( char * ) V_242 + F_193 ( V_45 -> V_197 ) , 0 ,
F_193 ( V_180 ) - F_193 ( V_45 -> V_197 ) ) ;
V_45 -> V_180 = V_242 ;
V_45 -> V_197 = V_180 ;
V_244:
F_134 () ;
return V_80 ;
}
static void V_224 ( int V_7 , long unsigned int V_180 ,
struct V_44 * V_45 )
{
int V_245 ;
if ( ! V_45 -> V_224 )
return;
for ( V_245 = 0 ; V_245 < V_7 ; V_245 ++ )
if ( F_42 ( V_7 , & V_180 ) )
V_45 -> V_224 ( V_245 ) ;
}
static int V_223 ( struct V_103 * V_1 , struct V_246 * V_247 ,
int V_248 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_143 ( V_2 ) ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_249 * V_250 = (struct V_249 * ) V_247 ;
int V_80 ;
long unsigned int V_180 = V_250 -> V_251 ;
if ( V_248 < sizeof( struct V_249 ) )
return - V_12 ;
if ( V_250 -> V_252 != V_253 )
return - V_12 ;
if ( V_180 ) {
if ( ! F_188 ( V_1 , V_254 ) )
return - V_255 ;
V_80 = F_191 ( V_2 ) ;
if ( V_80 )
return V_80 ;
}
if ( V_45 -> V_158 )
if ( V_250 -> V_256 != V_45 -> V_158 )
return - V_12 ;
if ( V_45 -> V_223 && V_180 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_45 -> V_197 ; V_7 ++ ) {
if ( ! F_42 ( V_7 , & V_180 ) )
continue;
V_80 = V_45 -> V_223 ( V_7 ) ;
if ( ! V_80 )
continue;
V_224 ( V_7 , V_180 , V_45 ) ;
return V_80 ;
}
}
if ( ! V_45 -> V_158 ) {
V_80 = V_250 -> V_256 ?
F_152 ( V_2 , V_190 , V_250 -> V_256 ) :
F_179 ( V_1 ) ;
if ( V_80 ) {
V_224 ( V_45 -> V_197 - 1 , V_180 , V_45 ) ;
return V_80 ;
}
}
if ( ! V_180 && ( V_45 -> V_180 == NULL || ! ( T_1 ) V_45 -> V_180 [ 0 ] ) )
return 0 ;
F_125 () ;
F_189 ( V_2 , V_45 -> V_205 +
F_194 ( V_180 ) -
F_194 ( V_45 -> V_180 [ 0 ] ) ) ;
V_45 -> V_180 [ 0 ] = ( V_45 -> V_180 [ 0 ] & ~ 0xffffffffUL ) | V_180 ;
F_148 ( V_2 ) ;
F_134 () ;
return 0 ;
}
static int F_195 ( struct V_103 * V_1 , struct V_246 * V_247 ,
int V_257 , int V_3 )
{
int V_80 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_249 * V_250 = (struct V_249 * ) V_247 ;
if ( V_257 < sizeof( V_247 -> V_258 ) )
return - V_12 ;
if ( V_247 -> V_258 == V_259 ) {
V_2 -> V_260 = V_261 ;
V_45 -> V_145 = 0 ;
V_45 -> V_146 = 0 ;
return 0 ;
}
if ( V_247 -> V_258 != V_253 )
return - V_12 ;
if ( ( V_250 -> V_251 || V_250 -> V_256 ) &&
! F_188 ( V_1 , V_262 ) )
return - V_255 ;
if ( ! V_45 -> V_158 )
V_80 = F_179 ( V_1 ) ;
if ( V_80 == 0 ) {
V_2 -> V_260 = V_263 ;
V_45 -> V_145 = V_250 -> V_256 ;
V_45 -> V_146 = F_196 ( V_250 -> V_251 ) ;
}
return V_80 ;
}
static int F_197 ( struct V_103 * V_1 , struct V_246 * V_247 ,
int * V_248 , int V_264 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
F_198 ( struct V_249 * , V_250 , V_247 ) ;
V_250 -> V_252 = V_253 ;
V_250 -> V_265 = 0 ;
* V_248 = sizeof( * V_250 ) ;
if ( V_264 ) {
V_250 -> V_256 = V_45 -> V_145 ;
V_250 -> V_251 = F_6 ( V_45 -> V_146 ) ;
} else {
V_250 -> V_256 = V_45 -> V_158 ;
V_250 -> V_251 = V_45 -> V_180 ? V_45 -> V_180 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_199 ( struct V_1 * V_266 , T_1 V_158 )
{
struct V_1 * V_1 ;
struct V_44 * V_45 ;
V_1 = F_147 ( F_143 ( V_266 ) , V_266 -> V_24 , V_158 ) ;
if ( ! V_1 )
return F_200 ( - V_267 ) ;
V_45 = F_2 ( V_1 ) ;
if ( V_1 -> V_260 == V_263 &&
V_45 -> V_145 != F_2 ( V_266 ) -> V_158 ) {
F_114 ( V_1 ) ;
return F_200 ( - V_267 ) ;
}
return V_1 ;
}
struct V_1 * F_201 ( struct V_101 * V_268 )
{
struct V_269 * V_269 = F_202 ( V_268 ) ;
struct V_1 * V_1 ;
if ( ! F_203 ( V_269 -> V_270 ) )
return F_200 ( - V_271 ) ;
V_1 = F_204 ( V_269 ) -> V_2 ;
if ( V_1 -> V_272 != V_253 )
return F_200 ( - V_12 ) ;
F_100 ( V_1 ) ;
return V_1 ;
}
static struct V_22 * F_205 ( unsigned int V_106 ,
int V_273 )
{
struct V_22 * V_23 ;
void * V_138 ;
if ( V_106 <= V_274 || V_273 )
return F_102 ( V_106 , V_64 ) ;
V_106 = F_206 ( V_106 ) +
F_206 ( sizeof( struct V_275 ) ) ;
V_138 = F_207 ( V_106 ) ;
if ( V_138 == NULL )
return NULL ;
V_23 = F_208 ( V_138 , V_106 ) ;
if ( V_23 == NULL )
F_50 ( V_138 ) ;
else {
V_23 -> V_276 = 0 ;
V_23 -> V_141 = V_142 ;
}
return V_23 ;
}
int F_209 ( struct V_1 * V_2 , struct V_22 * V_23 ,
long * V_277 , struct V_1 * V_266 )
{
struct V_44 * V_45 ;
V_45 = F_2 ( V_2 ) ;
if ( ( F_59 ( & V_2 -> V_174 ) > V_2 -> V_278 ||
F_42 ( V_47 , & V_45 -> V_48 ) ) &&
! F_44 ( V_23 ) ) {
F_128 ( V_54 , V_182 ) ;
if ( ! * V_277 ) {
if ( ! V_266 || F_1 ( V_266 ) )
F_36 ( V_2 ) ;
F_114 ( V_2 ) ;
F_104 ( V_23 ) ;
return - V_279 ;
}
F_132 ( V_280 ) ;
F_210 ( & V_45 -> V_54 , & V_54 ) ;
if ( ( F_59 ( & V_2 -> V_174 ) > V_2 -> V_278 ||
F_42 ( V_47 , & V_45 -> V_48 ) ) &&
! F_123 ( V_2 , V_177 ) )
* V_277 = F_211 ( * V_277 ) ;
F_132 ( V_185 ) ;
F_133 ( & V_45 -> V_54 , & V_54 ) ;
F_114 ( V_2 ) ;
if ( F_212 ( V_182 ) ) {
F_104 ( V_23 ) ;
return F_213 ( * V_277 ) ;
}
return 1 ;
}
F_118 ( V_23 , V_2 ) ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_60 = V_23 -> V_60 ;
F_31 ( V_23 ) ;
#ifdef F_113
if ( F_44 ( V_23 ) )
F_107 ( V_2 , V_23 ) ;
else if ( F_46 ( V_2 ) )
F_111 ( V_2 , V_23 ) ;
else
#endif
F_215 ( & V_2 -> V_53 , V_23 ) ;
V_2 -> V_281 ( V_2 ) ;
return V_60 ;
}
int F_216 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_60 = F_214 ( V_2 , V_23 ) ;
F_114 ( V_2 ) ;
return V_60 ;
}
void F_217 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_104 ( V_23 ) ;
F_114 ( V_2 ) ;
}
static struct V_22 * F_218 ( struct V_22 * V_23 , T_2 V_282 )
{
int V_283 ;
F_68 ( V_23 -> V_2 != NULL ) ;
if ( F_44 ( V_23 ) )
return V_23 ;
V_283 = V_23 -> V_139 - V_23 -> V_140 ;
if ( F_49 ( V_23 -> V_94 ) || V_283 * 2 < V_23 -> V_173 )
return V_23 ;
if ( F_219 ( V_23 ) ) {
struct V_22 * V_34 = F_23 ( V_23 , V_282 ) ;
if ( ! V_34 )
return V_23 ;
F_220 ( V_23 ) ;
V_23 = V_34 ;
}
if ( ! F_221 ( V_23 , 0 , - V_283 , V_282 ) )
V_23 -> V_173 -= V_283 ;
return V_23 ;
}
static int F_222 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_1 * V_266 )
{
int V_21 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
V_21 = - V_267 ;
if ( V_45 -> V_284 != NULL ) {
V_21 = V_23 -> V_60 ;
F_118 ( V_23 , V_2 ) ;
F_45 ( V_23 ) . V_2 = V_266 ;
F_35 ( V_2 , V_266 , V_23 ) ;
V_45 -> V_284 ( V_23 ) ;
F_220 ( V_23 ) ;
} else {
F_104 ( V_23 ) ;
}
F_114 ( V_2 ) ;
return V_21 ;
}
int F_106 ( struct V_1 * V_266 , struct V_22 * V_23 ,
T_1 V_158 , int V_285 )
{
struct V_1 * V_2 ;
int V_80 ;
long V_277 ;
V_23 = F_218 ( V_23 , F_223 () ) ;
V_277 = F_224 ( V_266 , V_285 ) ;
V_231:
V_2 = F_199 ( V_266 , V_158 ) ;
if ( F_225 ( V_2 ) ) {
F_104 ( V_23 ) ;
return F_226 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_222 ( V_2 , V_23 , V_266 ) ;
if ( F_227 ( V_2 , V_23 ) ) {
V_80 = V_23 -> V_60 ;
F_104 ( V_23 ) ;
F_114 ( V_2 ) ;
return V_80 ;
}
V_80 = F_209 ( V_2 , V_23 , & V_277 , V_266 ) ;
if ( V_80 == 1 )
goto V_231;
if ( V_80 )
return V_80 ;
return F_216 ( V_2 , V_23 ) ;
}
struct V_22 * F_228 ( struct V_1 * V_266 , unsigned int V_106 ,
T_1 V_145 , T_2 V_286 )
{
#ifdef F_113
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 ;
struct V_76 * V_77 ;
struct V_116 * V_117 ;
unsigned int V_149 ;
V_2 = F_199 ( V_266 , V_145 ) ;
if ( F_225 ( V_2 ) )
goto V_19;
V_77 = & F_2 ( V_2 ) -> V_56 ;
if ( V_77 -> V_57 == NULL )
goto V_287;
if ( V_77 -> V_95 - V_87 < V_106 )
goto V_287;
V_23 = F_99 ( V_286 ) ;
if ( V_23 == NULL )
goto V_74;
F_64 ( & V_2 -> V_53 . V_92 ) ;
if ( V_77 -> V_57 == NULL )
goto V_288;
V_149 = V_77 -> V_95 - V_87 ;
if ( V_149 < V_106 )
goto V_288;
F_87 ( V_77 ) ;
V_117 = F_84 ( V_77 , V_129 ) ;
if ( V_117 == NULL )
goto V_289;
F_93 ( V_23 , V_2 , V_77 , V_117 ) ;
F_80 ( V_117 , V_157 ) ;
F_38 ( & V_77 -> V_84 ) ;
F_86 ( V_77 ) ;
F_67 ( & V_2 -> V_53 . V_92 ) ;
return V_23 ;
V_289:
F_104 ( V_23 ) ;
F_67 ( & V_2 -> V_53 . V_92 ) ;
F_36 ( V_2 ) ;
V_74:
F_114 ( V_2 ) ;
return NULL ;
V_288:
F_104 ( V_23 ) ;
F_67 ( & V_2 -> V_53 . V_92 ) ;
V_287:
F_114 ( V_2 ) ;
V_19:
#endif
return F_102 ( V_106 , V_286 ) ;
}
int F_229 ( struct V_1 * V_2 , unsigned int V_7 )
{
int V_290 = 0 ;
struct V_196 * V_196 ;
F_176 ( ! F_1 ( V_2 ) ) ;
F_32 () ;
V_196 = F_230 ( V_194 [ V_2 -> V_24 ] . V_196 ) ;
if ( V_196 && V_7 - 1 < V_194 [ V_2 -> V_24 ] . V_180 )
V_290 = F_42 ( V_7 - 1 , V_196 -> V_198 ) ;
F_34 () ;
return V_290 ;
}
static int F_231 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
if ( F_59 ( & V_2 -> V_174 ) <= V_2 -> V_278 &&
! F_42 ( V_47 , & V_45 -> V_48 ) ) {
F_118 ( V_23 , V_2 ) ;
F_214 ( V_2 , V_23 ) ;
return F_59 ( & V_2 -> V_174 ) > ( V_2 -> V_278 >> 1 ) ;
}
return - 1 ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_291 * V_292 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
int V_293 ;
if ( V_292 -> V_294 == V_2 )
return;
if ( V_45 -> V_158 == V_292 -> V_158 || V_292 -> V_7 - 1 >= V_45 -> V_197 ||
! F_42 ( V_292 -> V_7 - 1 , V_45 -> V_180 ) )
return;
if ( ! F_142 ( F_143 ( V_2 ) , V_292 -> V_190 ) )
return;
if ( V_292 -> V_295 ) {
F_36 ( V_2 ) ;
return;
}
F_100 ( V_2 ) ;
if ( V_292 -> V_296 == NULL ) {
if ( F_219 ( V_292 -> V_23 ) ) {
V_292 -> V_296 = F_23 ( V_292 -> V_23 , V_292 -> V_282 ) ;
} else {
V_292 -> V_296 = F_233 ( V_292 -> V_23 ) ;
F_234 ( V_292 -> V_296 ) ;
}
}
if ( V_292 -> V_296 == NULL ) {
F_36 ( V_2 ) ;
V_292 -> V_295 = 1 ;
if ( V_45 -> V_3 & V_297 )
V_292 -> V_298 = 1 ;
} else if ( V_292 -> V_299 && V_292 -> V_299 ( V_2 , V_292 -> V_296 , V_292 -> V_300 ) ) {
F_104 ( V_292 -> V_296 ) ;
V_292 -> V_296 = NULL ;
} else if ( F_227 ( V_2 , V_292 -> V_296 ) ) {
F_104 ( V_292 -> V_296 ) ;
V_292 -> V_296 = NULL ;
} else if ( ( V_293 = F_231 ( V_2 , V_292 -> V_296 ) ) < 0 ) {
F_36 ( V_2 ) ;
if ( V_45 -> V_3 & V_297 )
V_292 -> V_298 = 1 ;
} else {
V_292 -> V_301 |= V_293 ;
V_292 -> V_302 = 1 ;
V_292 -> V_296 = NULL ;
}
F_114 ( V_2 ) ;
}
int F_235 ( struct V_1 * V_266 , struct V_22 * V_23 , T_1 V_158 ,
T_1 V_7 , T_2 V_282 ,
int (* F_236)( struct V_1 * V_303 , struct V_22 * V_23 , void * V_138 ) ,
void * V_304 )
{
struct V_190 * V_190 = F_143 ( V_266 ) ;
struct V_291 V_305 ;
struct V_1 * V_2 ;
V_23 = F_218 ( V_23 , V_282 ) ;
V_305 . V_294 = V_266 ;
V_305 . V_190 = V_190 ;
V_305 . V_158 = V_158 ;
V_305 . V_7 = V_7 ;
V_305 . V_295 = 0 ;
V_305 . V_298 = 0 ;
V_305 . V_301 = 0 ;
V_305 . V_302 = 0 ;
V_305 . V_282 = V_282 ;
V_305 . V_23 = V_23 ;
V_305 . V_296 = NULL ;
V_305 . V_299 = F_236 ;
V_305 . V_300 = V_304 ;
F_136 () ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_232 ( V_2 , & V_305 ) ;
F_220 ( V_23 ) ;
F_139 () ;
if ( V_305 . V_298 ) {
F_104 ( V_305 . V_296 ) ;
return - V_50 ;
}
F_220 ( V_305 . V_296 ) ;
if ( V_305 . V_302 ) {
if ( V_305 . V_301 && ( V_282 & V_306 ) )
F_237 () ;
return 0 ;
}
return - V_307 ;
}
int F_105 ( struct V_1 * V_266 , struct V_22 * V_23 , T_1 V_158 ,
T_1 V_7 , T_2 V_282 )
{
return F_235 ( V_266 , V_23 , V_158 , V_7 , V_282 ,
NULL , NULL ) ;
}
static int F_238 ( struct V_1 * V_2 , struct V_308 * V_292 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
int V_21 = 0 ;
if ( V_2 == V_292 -> V_294 )
goto V_19;
if ( ! F_142 ( F_143 ( V_2 ) , F_143 ( V_292 -> V_294 ) ) )
goto V_19;
if ( V_45 -> V_158 == V_292 -> V_158 || V_292 -> V_7 - 1 >= V_45 -> V_197 ||
! F_42 ( V_292 -> V_7 - 1 , V_45 -> V_180 ) )
goto V_19;
if ( V_292 -> V_309 == V_50 && V_45 -> V_3 & V_46 ) {
V_21 = 1 ;
goto V_19;
}
V_2 -> V_49 = V_292 -> V_309 ;
V_2 -> V_51 ( V_2 ) ;
V_19:
return V_21 ;
}
int F_239 ( struct V_1 * V_266 , T_1 V_158 , T_1 V_7 , int V_309 )
{
struct V_308 V_305 ;
struct V_1 * V_2 ;
int V_21 = 0 ;
V_305 . V_294 = V_266 ;
V_305 . V_158 = V_158 ;
V_305 . V_7 = V_7 ;
V_305 . V_309 = - V_309 ;
F_137 ( & T_4 ) ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_21 += F_238 ( V_2 , & V_305 ) ;
F_138 ( & T_4 ) ;
return V_21 ;
}
static void F_240 ( struct V_44 * V_45 ,
unsigned int V_7 ,
int V_310 )
{
int V_228 , V_311 = ! ! V_310 , V_205 ;
V_228 = F_42 ( V_7 - 1 , V_45 -> V_180 ) ;
V_205 = V_45 -> V_205 - V_228 + V_311 ;
if ( V_311 )
F_241 ( V_7 - 1 , V_45 -> V_180 ) ;
else
F_242 ( V_7 - 1 , V_45 -> V_180 ) ;
F_189 ( & V_45 -> V_2 , V_205 ) ;
F_148 ( & V_45 -> V_2 ) ;
}
static int F_243 ( struct V_103 * V_1 , int V_312 , int V_313 ,
char T_6 * V_314 , unsigned int V_315 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
unsigned int V_293 = 0 ;
int V_80 ;
if ( V_312 != V_316 )
return - V_317 ;
if ( V_313 != V_318 && V_313 != V_319 &&
V_315 >= sizeof( int ) &&
F_244 ( V_293 , ( unsigned int T_6 * ) V_314 ) )
return - V_320 ;
switch ( V_313 ) {
case V_321 :
if ( V_293 )
V_45 -> V_3 |= V_322 ;
else
V_45 -> V_3 &= ~ V_322 ;
V_80 = 0 ;
break;
case V_323 :
case V_324 : {
if ( ! F_188 ( V_1 , V_254 ) )
return - V_255 ;
V_80 = F_191 ( V_2 ) ;
if ( V_80 )
return V_80 ;
if ( ! V_293 || V_293 - 1 >= V_45 -> V_197 )
return - V_12 ;
if ( V_313 == V_323 && V_45 -> V_223 ) {
V_80 = V_45 -> V_223 ( V_293 ) ;
if ( V_80 )
return V_80 ;
}
F_125 () ;
F_240 ( V_45 , V_293 ,
V_313 == V_323 ) ;
F_134 () ;
if ( V_313 == V_324 && V_45 -> V_224 )
V_45 -> V_224 ( V_293 ) ;
V_80 = 0 ;
break;
}
case V_325 :
if ( V_293 )
V_45 -> V_3 |= V_297 ;
else
V_45 -> V_3 &= ~ V_297 ;
V_80 = 0 ;
break;
case V_326 :
if ( V_293 ) {
V_45 -> V_3 |= V_46 ;
F_41 ( V_47 , & V_45 -> V_48 ) ;
F_43 ( & V_45 -> V_54 ) ;
} else {
V_45 -> V_3 &= ~ V_46 ;
}
V_80 = 0 ;
break;
#ifdef F_113
case V_318 :
case V_319 : {
struct V_70 V_71 ;
if ( ! F_245 ( V_240 ) )
return - V_255 ;
if ( V_315 < sizeof( V_71 ) )
return - V_12 ;
if ( F_246 ( & V_71 , V_314 , sizeof( V_71 ) ) )
return - V_320 ;
V_80 = F_58 ( V_2 , & V_71 , false ,
V_313 == V_319 ) ;
break;
}
#endif
default:
V_80 = - V_317 ;
}
return V_80 ;
}
static int F_247 ( struct V_103 * V_1 , int V_312 , int V_313 ,
char T_6 * V_314 , int T_6 * V_315 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
int V_60 , V_293 , V_80 ;
if ( V_312 != V_316 )
return - V_317 ;
if ( F_244 ( V_60 , V_315 ) )
return - V_320 ;
if ( V_60 < 0 )
return - V_12 ;
switch ( V_313 ) {
case V_321 :
if ( V_60 < sizeof( int ) )
return - V_12 ;
V_60 = sizeof( int ) ;
V_293 = V_45 -> V_3 & V_322 ? 1 : 0 ;
if ( F_248 ( V_60 , V_315 ) ||
F_248 ( V_293 , V_314 ) )
return - V_320 ;
V_80 = 0 ;
break;
case V_325 :
if ( V_60 < sizeof( int ) )
return - V_12 ;
V_60 = sizeof( int ) ;
V_293 = V_45 -> V_3 & V_297 ? 1 : 0 ;
if ( F_248 ( V_60 , V_315 ) ||
F_248 ( V_293 , V_314 ) )
return - V_320 ;
V_80 = 0 ;
break;
case V_326 :
if ( V_60 < sizeof( int ) )
return - V_12 ;
V_60 = sizeof( int ) ;
V_293 = V_45 -> V_3 & V_46 ? 1 : 0 ;
if ( F_248 ( V_60 , V_315 ) ||
F_248 ( V_293 , V_314 ) )
return - V_320 ;
V_80 = 0 ;
break;
default:
V_80 = - V_317 ;
}
return V_80 ;
}
static void F_249 ( struct V_143 * V_144 , struct V_22 * V_23 )
{
struct V_327 V_305 ;
V_305 . V_7 = F_45 ( V_23 ) . V_146 ;
F_250 ( V_144 , V_316 , V_321 , sizeof( V_305 ) , & V_305 ) ;
}
static int F_251 ( struct V_328 * V_328 , struct V_103 * V_1 ,
struct V_143 * V_144 , T_7 V_60 )
{
struct V_147 * V_148 = F_252 ( V_328 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
F_198 ( struct V_249 * , V_247 , V_144 -> V_329 ) ;
T_1 V_145 ;
T_1 V_146 ;
struct V_22 * V_23 ;
int V_80 ;
struct V_330 V_160 ;
T_1 V_331 = 0 ;
if ( V_144 -> V_154 & V_332 )
return - V_333 ;
if ( NULL == V_148 -> V_160 )
V_148 -> V_160 = & V_160 ;
V_80 = F_253 ( V_1 , V_144 , V_148 -> V_160 , true ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_144 -> V_334 ) {
V_80 = - V_12 ;
if ( V_247 -> V_252 != V_253 )
goto V_19;
V_145 = V_247 -> V_256 ;
V_146 = F_196 ( V_247 -> V_251 ) ;
V_80 = - V_255 ;
if ( ( V_146 || V_145 ) &&
! F_188 ( V_1 , V_262 ) )
goto V_19;
V_331 |= V_237 ;
} else {
V_145 = V_45 -> V_145 ;
V_146 = V_45 -> V_146 ;
}
if ( ! V_45 -> V_158 ) {
V_80 = F_179 ( V_1 ) ;
if ( V_80 )
goto V_19;
}
if ( F_47 ( V_2 ) &&
V_144 -> V_335 -> V_336 == NULL ) {
V_80 = F_95 ( V_2 , V_144 , V_145 , V_146 ,
V_148 ) ;
goto V_19;
}
V_80 = - V_337 ;
if ( V_60 > V_2 -> V_338 - 32 )
goto V_19;
V_80 = - V_50 ;
V_23 = F_205 ( V_60 , V_146 ) ;
if ( V_23 == NULL )
goto V_19;
F_45 ( V_23 ) . V_158 = V_45 -> V_158 ;
F_45 ( V_23 ) . V_146 = V_146 ;
F_45 ( V_23 ) . V_159 = V_148 -> V_160 -> V_159 ;
F_45 ( V_23 ) . V_3 = V_331 ;
V_80 = - V_320 ;
if ( F_254 ( F_255 ( V_23 , V_60 ) , V_144 -> V_335 , V_60 ) ) {
F_104 ( V_23 ) ;
goto V_19;
}
V_80 = F_103 ( V_2 , V_23 ) ;
if ( V_80 ) {
F_104 ( V_23 ) ;
goto V_19;
}
if ( V_146 ) {
F_38 ( & V_23 -> V_161 ) ;
F_105 ( V_2 , V_23 , V_145 , V_146 , V_64 ) ;
}
V_80 = F_106 ( V_2 , V_23 , V_145 , V_144 -> V_154 & V_155 ) ;
V_19:
F_256 ( V_148 -> V_160 ) ;
return V_80 ;
}
static int F_257 ( struct V_328 * V_328 , struct V_103 * V_1 ,
struct V_143 * V_144 , T_7 V_60 ,
int V_3 )
{
struct V_147 * V_148 = F_252 ( V_328 ) ;
struct V_330 V_160 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 = F_2 ( V_2 ) ;
int V_339 = V_3 & V_155 ;
T_7 V_340 ;
struct V_22 * V_23 , * V_341 ;
int V_80 , V_21 ;
if ( V_3 & V_332 )
return - V_333 ;
V_340 = 0 ;
V_23 = F_258 ( V_2 , V_3 , V_339 , & V_80 ) ;
if ( V_23 == NULL )
goto V_19;
V_341 = V_23 ;
#ifdef F_259
if ( F_8 ( F_116 ( V_23 ) -> V_342 ) ) {
if ( V_3 & V_343 )
V_341 = F_116 ( V_23 ) -> V_342 ;
}
#endif
V_45 -> V_344 = F_260 ( V_45 -> V_344 , V_60 ) ;
V_45 -> V_344 = F_261 ( T_7 , V_45 -> V_344 ,
16384 ) ;
V_340 = V_341 -> V_60 ;
if ( V_60 < V_340 ) {
V_144 -> V_154 |= V_345 ;
V_340 = V_60 ;
}
F_262 ( V_341 ) ;
V_80 = F_263 ( V_341 , 0 , V_144 -> V_335 , V_340 ) ;
if ( V_144 -> V_329 ) {
F_198 ( struct V_249 * , V_247 , V_144 -> V_329 ) ;
V_247 -> V_252 = V_253 ;
V_247 -> V_265 = 0 ;
V_247 -> V_256 = F_45 ( V_23 ) . V_158 ;
V_247 -> V_251 = F_6 ( F_45 ( V_23 ) . V_146 ) ;
V_144 -> V_334 = sizeof( * V_247 ) ;
}
if ( V_45 -> V_3 & V_322 )
F_249 ( V_144 , V_23 ) ;
if ( NULL == V_148 -> V_160 ) {
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_148 -> V_160 = & V_160 ;
}
V_148 -> V_160 -> V_159 = * F_264 ( V_23 ) ;
if ( V_3 & V_345 )
V_340 = V_341 -> V_60 ;
F_265 ( V_2 , V_23 ) ;
if ( V_45 -> V_133 &&
F_59 ( & V_2 -> V_174 ) <= V_2 -> V_278 / 2 ) {
V_21 = F_90 ( V_2 ) ;
if ( V_21 ) {
V_2 -> V_49 = - V_21 ;
V_2 -> V_51 ( V_2 ) ;
}
}
F_266 ( V_1 , V_144 , V_148 -> V_160 , V_3 ) ;
V_19:
F_39 ( V_2 ) ;
return V_80 ? : V_340 ;
}
static void F_267 ( struct V_1 * V_2 )
{
F_268 () ;
}
struct V_1 *
F_269 ( struct V_190 * V_190 , int V_346 , struct V_16 * V_16 ,
struct V_347 * V_348 )
{
struct V_103 * V_1 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
struct V_196 * V_196 = NULL ;
struct V_206 * V_207 = V_348 ? V_348 -> V_207 : NULL ;
unsigned int V_180 ;
F_176 ( ! V_194 ) ;
if ( V_346 < 0 || V_346 >= V_219 )
return NULL ;
if ( F_270 ( V_210 , V_217 , V_346 , & V_1 ) )
return NULL ;
if ( F_158 ( & V_349 , V_1 , V_207 , V_346 ) < 0 )
goto V_350;
V_2 = V_1 -> V_2 ;
F_271 ( V_2 , V_190 ) ;
if ( ! V_348 || V_348 -> V_180 < 32 )
V_180 = 32 ;
else
V_180 = V_348 -> V_180 ;
V_196 = F_272 ( sizeof( * V_196 ) + F_193 ( V_180 ) , V_64 ) ;
if ( ! V_196 )
goto V_351;
V_2 -> V_281 = F_267 ;
if ( V_348 && V_348 -> V_352 )
F_2 ( V_2 ) -> V_284 = V_348 -> V_352 ;
if ( F_152 ( V_2 , V_190 , 0 ) )
goto V_351;
V_45 = F_2 ( V_2 ) ;
V_45 -> V_3 |= V_4 ;
F_125 () ;
if ( ! V_194 [ V_346 ] . V_221 ) {
V_194 [ V_346 ] . V_180 = V_180 ;
F_273 ( V_194 [ V_346 ] . V_196 , V_196 ) ;
V_194 [ V_346 ] . V_207 = V_207 ;
V_194 [ V_346 ] . V_16 = V_16 ;
if ( V_348 ) {
V_194 [ V_346 ] . F_164 = V_348 -> F_164 ;
V_194 [ V_346 ] . V_3 = V_348 -> V_3 ;
if ( V_348 -> V_353 )
V_194 [ V_346 ] . V_353 = V_348 -> V_353 ;
}
V_194 [ V_346 ] . V_221 = 1 ;
} else {
F_52 ( V_196 ) ;
V_194 [ V_346 ] . V_221 ++ ;
}
F_134 () ;
return V_2 ;
V_351:
F_52 ( V_196 ) ;
F_274 ( V_2 ) ;
return NULL ;
V_350:
F_275 ( V_1 ) ;
return NULL ;
}
void
F_274 ( struct V_1 * V_2 )
{
F_276 ( V_2 ) ;
}
int F_277 ( struct V_1 * V_2 , unsigned int V_180 )
{
struct V_196 * V_311 , * V_228 ;
struct V_191 * V_195 = & V_194 [ V_2 -> V_24 ] ;
if ( V_180 < 32 )
V_180 = 32 ;
if ( F_193 ( V_195 -> V_180 ) < F_193 ( V_180 ) ) {
V_311 = F_272 ( sizeof( * V_311 ) + F_193 ( V_180 ) , V_36 ) ;
if ( ! V_311 )
return - V_35 ;
V_228 = F_149 ( V_195 -> V_196 ) ;
memcpy ( V_311 -> V_198 , V_228 -> V_198 , F_193 ( V_195 -> V_180 ) ) ;
F_273 ( V_195 -> V_196 , V_311 ) ;
F_178 ( V_228 , V_229 ) ;
}
V_195 -> V_180 = V_180 ;
return 0 ;
}
int F_278 ( struct V_1 * V_2 , unsigned int V_180 )
{
int V_80 ;
F_125 () ;
V_80 = F_277 ( V_2 , V_180 ) ;
F_134 () ;
return V_80 ;
}
void F_279 ( struct V_1 * V_354 , unsigned int V_7 )
{
struct V_1 * V_2 ;
struct V_191 * V_195 = & V_194 [ V_354 -> V_24 ] ;
F_151 (sk, &tbl->mc_list)
F_240 ( F_2 ( V_2 ) , V_7 , 0 ) ;
}
struct V_355 *
F_280 ( struct V_22 * V_23 , T_1 V_158 , T_1 V_356 , int type , int V_60 , int V_3 )
{
struct V_355 * V_357 ;
int V_106 = F_281 ( V_60 ) ;
V_357 = (struct V_355 * ) F_255 ( V_23 , F_282 ( V_106 ) ) ;
V_357 -> V_358 = type ;
V_357 -> V_359 = V_106 ;
V_357 -> V_360 = V_3 ;
V_357 -> V_361 = V_158 ;
V_357 -> V_362 = V_356 ;
if ( ! F_283 ( V_106 ) || F_282 ( V_106 ) - V_106 != 0 )
memset ( F_284 ( V_357 ) + V_60 , 0 , F_282 ( V_106 ) - V_106 ) ;
return V_357 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_2 ( V_2 ) ;
struct V_363 * V_175 ;
struct V_22 * V_23 = NULL ;
struct V_355 * V_357 ;
int V_60 , V_80 = - V_50 ;
int V_364 ;
F_63 ( V_45 -> V_207 ) ;
if ( ! V_45 -> V_133 ) {
V_80 = - V_12 ;
goto V_365;
}
V_175 = & V_45 -> V_175 ;
V_364 = F_285 ( int , V_175 -> V_366 , V_274 ) ;
if ( ! F_46 ( V_2 ) &&
F_59 ( & V_2 -> V_174 ) >= V_2 -> V_278 )
goto V_365;
if ( V_364 < V_45 -> V_344 ) {
V_23 = F_228 ( V_2 ,
V_45 -> V_344 ,
V_45 -> V_158 ,
V_64 |
V_67 |
V_68 ) ;
if ( V_23 )
F_286 ( V_23 , F_287 ( V_23 ) -
V_45 -> V_344 ) ;
}
if ( ! V_23 )
V_23 = F_228 ( V_2 , V_364 , V_45 -> V_158 ,
V_64 ) ;
if ( ! V_23 )
goto V_365;
F_118 ( V_23 , V_2 ) ;
V_60 = V_175 -> V_367 ( V_23 , V_175 ) ;
if ( V_60 > 0 ) {
F_69 ( V_45 -> V_207 ) ;
if ( F_227 ( V_2 , V_23 ) )
F_104 ( V_23 ) ;
else
F_214 ( V_2 , V_23 ) ;
return 0 ;
}
V_357 = F_288 ( V_23 , V_175 , V_368 , sizeof( V_60 ) , V_369 ) ;
if ( ! V_357 )
goto V_365;
F_289 ( V_175 , V_357 ) ;
memcpy ( F_284 ( V_357 ) , & V_60 , sizeof( V_60 ) ) ;
if ( F_227 ( V_2 , V_23 ) )
F_104 ( V_23 ) ;
else
F_214 ( V_2 , V_23 ) ;
if ( V_175 -> V_176 )
V_175 -> V_176 ( V_175 ) ;
V_45 -> V_133 = false ;
F_69 ( V_45 -> V_207 ) ;
F_17 ( V_175 -> V_16 ) ;
F_220 ( V_175 -> V_23 ) ;
return 0 ;
V_365:
F_69 ( V_45 -> V_207 ) ;
F_104 ( V_23 ) ;
return V_80 ;
}
int F_290 ( struct V_1 * V_266 , struct V_22 * V_23 ,
const struct V_355 * V_357 ,
struct V_370 * V_371 )
{
struct V_363 * V_175 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_21 ;
if ( F_44 ( V_23 ) ) {
V_23 = F_291 ( V_23 , V_64 ) ;
if ( V_23 == NULL )
return - V_50 ;
} else
F_38 ( & V_23 -> V_161 ) ;
V_2 = F_147 ( F_143 ( V_266 ) , V_266 -> V_24 , F_45 ( V_23 ) . V_158 ) ;
if ( V_2 == NULL ) {
V_21 = - V_267 ;
goto V_372;
}
V_45 = F_2 ( V_2 ) ;
F_63 ( V_45 -> V_207 ) ;
if ( V_45 -> V_133 ) {
V_21 = - V_83 ;
goto V_373;
}
if ( ! F_168 ( V_371 -> V_16 ) ) {
V_21 = - V_220 ;
goto V_373;
}
V_175 = & V_45 -> V_175 ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_367 = V_371 -> V_367 ;
V_175 -> V_176 = V_371 -> V_176 ;
V_175 -> V_357 = V_357 ;
V_175 -> V_138 = V_371 -> V_138 ;
V_175 -> V_16 = V_371 -> V_16 ;
V_175 -> V_366 = V_371 -> V_366 ;
V_175 -> V_23 = V_23 ;
V_45 -> V_133 = true ;
F_69 ( V_45 -> V_207 ) ;
V_21 = F_90 ( V_2 ) ;
F_114 ( V_2 ) ;
if ( V_21 )
return V_21 ;
return - V_374 ;
V_373:
F_114 ( V_2 ) ;
F_69 ( V_45 -> V_207 ) ;
V_372:
F_104 ( V_23 ) ;
return V_21 ;
}
void F_292 ( struct V_22 * V_375 , struct V_355 * V_357 , int V_80 )
{
struct V_22 * V_23 ;
struct V_355 * V_376 ;
struct V_377 * V_378 ;
T_7 V_379 = sizeof( * V_378 ) ;
if ( V_80 )
V_379 += V_359 ( V_357 ) ;
V_23 = F_228 ( V_375 -> V_2 , F_293 ( V_379 ) ,
F_45 ( V_375 ) . V_158 , V_64 ) ;
if ( ! V_23 ) {
struct V_1 * V_2 ;
V_2 = F_147 ( F_143 ( V_375 -> V_2 ) ,
V_375 -> V_2 -> V_24 ,
F_45 ( V_375 ) . V_158 ) ;
if ( V_2 ) {
V_2 -> V_49 = V_50 ;
V_2 -> V_51 ( V_2 ) ;
F_114 ( V_2 ) ;
}
return;
}
V_376 = F_280 ( V_23 , F_45 ( V_375 ) . V_158 , V_357 -> V_362 ,
V_380 , V_379 , 0 ) ;
V_378 = F_284 ( V_376 ) ;
V_378 -> error = V_80 ;
memcpy ( & V_378 -> V_144 , V_357 , V_80 ? V_357 -> V_359 : sizeof( * V_357 ) ) ;
F_106 ( V_375 -> V_2 , V_23 , F_45 ( V_375 ) . V_158 , V_155 ) ;
}
int F_294 ( struct V_22 * V_23 , int (* V_175)( struct V_22 * ,
struct V_355 * ) )
{
struct V_355 * V_357 ;
int V_80 ;
while ( V_23 -> V_60 >= F_293 ( 0 ) ) {
int V_381 ;
V_357 = F_295 ( V_23 ) ;
V_80 = 0 ;
if ( V_357 -> V_359 < V_382 || V_23 -> V_60 < V_357 -> V_359 )
return 0 ;
if ( ! ( V_357 -> V_360 & V_383 ) )
goto V_384;
if ( V_357 -> V_358 < V_385 )
goto V_384;
V_80 = V_175 ( V_23 , V_357 ) ;
if ( V_80 == - V_374 )
goto V_386;
V_384:
if ( V_357 -> V_360 & V_387 || V_80 )
F_292 ( V_23 , V_357 , V_80 ) ;
V_386:
V_381 = F_282 ( V_357 -> V_359 ) ;
if ( V_381 > V_23 -> V_60 )
V_381 = V_23 -> V_60 ;
F_296 ( V_23 , V_381 ) ;
}
return 0 ;
}
int F_297 ( struct V_1 * V_2 , struct V_22 * V_23 , T_1 V_158 ,
unsigned int V_7 , int V_388 , T_2 V_3 )
{
int V_80 = 0 ;
if ( V_7 ) {
int V_389 = 0 ;
if ( V_388 ) {
F_38 ( & V_23 -> V_161 ) ;
V_389 = V_158 ;
}
V_80 = F_298 ( V_2 , V_23 , V_389 , V_7 , V_3 ) ;
}
if ( V_388 ) {
int V_289 ;
V_289 = F_299 ( V_2 , V_23 , V_158 ) ;
if ( ! V_80 || V_80 == - V_307 )
V_80 = V_289 ;
}
return V_80 ;
}
static struct V_1 * F_300 ( struct V_390 * V_356 , T_8 V_125 )
{
struct V_391 * V_392 = V_356 -> V_393 ;
int V_61 , V_394 ;
struct V_44 * V_45 ;
struct V_1 * V_395 ;
T_8 V_396 = 0 ;
for ( V_61 = 0 ; V_61 < V_219 ; V_61 ++ ) {
struct V_397 * V_398 = & V_194 [ V_61 ] . V_193 ;
const struct V_399 * V_195 = F_301 ( V_398 -> V_195 , V_398 ) ;
for ( V_394 = 0 ; V_394 < V_195 -> V_106 ; V_394 ++ ) {
F_302 (nlk, tbl->buckets[j], node) {
V_395 = (struct V_1 * ) V_45 ;
if ( F_143 ( V_395 ) != F_303 ( V_356 ) )
continue;
if ( V_396 == V_125 ) {
V_392 -> V_400 = V_61 ;
V_392 -> V_401 = V_394 ;
return V_395 ;
}
++ V_396 ;
}
}
}
return NULL ;
}
static void * F_304 ( struct V_390 * V_356 , T_8 * V_125 )
__acquires( T_9 )
{
F_32 () ;
return * V_125 ? F_300 ( V_356 , * V_125 - 1 ) : V_402 ;
}
static void * F_305 ( struct V_390 * V_356 , void * V_403 , T_8 * V_125 )
{
struct V_44 * V_45 ;
struct V_391 * V_392 ;
struct V_190 * V_190 ;
int V_61 , V_394 ;
++ * V_125 ;
if ( V_403 == V_402 )
return F_300 ( V_356 , 0 ) ;
V_190 = F_303 ( V_356 ) ;
V_392 = V_356 -> V_393 ;
V_45 = V_403 ;
F_302 (nlk, nlk->node.next, node)
if ( F_142 ( F_143 ( (struct V_1 * ) V_45 ) , V_190 ) )
return V_45 ;
V_61 = V_392 -> V_400 ;
V_394 = V_392 -> V_401 + 1 ;
do {
struct V_397 * V_398 = & V_194 [ V_61 ] . V_193 ;
const struct V_399 * V_195 = F_301 ( V_398 -> V_195 , V_398 ) ;
for (; V_394 < V_195 -> V_106 ; V_394 ++ ) {
F_302 (nlk, tbl->buckets[j], node) {
if ( F_142 ( F_143 ( (struct V_1 * ) V_45 ) , V_190 ) ) {
V_392 -> V_400 = V_61 ;
V_392 -> V_401 = V_394 ;
return V_45 ;
}
}
}
V_394 = 0 ;
} while ( ++ V_61 < V_219 );
return NULL ;
}
static void F_306 ( struct V_390 * V_356 , void * V_403 )
__releases( T_9 )
{
F_34 () ;
}
static int F_307 ( struct V_390 * V_356 , void * V_403 )
{
if ( V_403 == V_402 ) {
F_308 ( V_356 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_395 = V_403 ;
struct V_44 * V_45 = F_2 ( V_395 ) ;
F_309 ( V_356 , L_6 ,
V_395 ,
V_395 -> V_24 ,
V_45 -> V_158 ,
V_45 -> V_180 ? ( T_1 ) V_45 -> V_180 [ 0 ] : 0 ,
F_310 ( V_395 ) ,
F_311 ( V_395 ) ,
V_45 -> V_133 ,
F_59 ( & V_395 -> V_204 ) ,
F_59 ( & V_395 -> V_52 ) ,
F_312 ( V_395 )
) ;
}
return 0 ;
}
static int F_313 ( struct V_269 * V_269 , struct V_101 * V_101 )
{
return F_314 ( V_269 , V_101 , & V_404 ,
sizeof( struct V_391 ) ) ;
}
int F_315 ( struct V_405 * V_406 )
{
return F_316 ( & V_226 , V_406 ) ;
}
int F_317 ( struct V_405 * V_406 )
{
return F_318 ( & V_226 , V_406 ) ;
}
static int T_10 F_319 ( struct V_190 * V_190 )
{
#ifdef F_320
if ( ! F_321 ( L_7 , 0 , V_190 -> V_407 , & V_408 ) )
return - V_35 ;
#endif
return 0 ;
}
static void T_11 F_322 ( struct V_190 * V_190 )
{
#ifdef F_320
F_323 ( L_7 , V_190 -> V_407 ) ;
#endif
}
static void T_12 F_324 ( void )
{
struct V_196 * V_196 ;
int V_180 = 32 ;
V_196 = F_272 ( sizeof( * V_196 ) + F_193 ( V_180 ) , V_64 ) ;
if ( ! V_196 )
F_325 ( L_8 ) ;
F_125 () ;
V_194 [ V_26 ] . V_180 = V_180 ;
F_273 ( V_194 [ V_26 ] . V_196 , V_196 ) ;
V_194 [ V_26 ] . V_16 = V_409 ;
V_194 [ V_26 ] . V_221 = 1 ;
V_194 [ V_26 ] . V_3 = V_262 ;
F_134 () ;
}
static int T_12 F_326 ( void )
{
int V_61 ;
int V_80 = F_327 ( & V_211 , 0 ) ;
struct V_410 V_411 = {
. V_412 = F_328 ( struct V_44 , V_203 ) ,
. V_413 = F_328 ( struct V_44 , V_158 ) ,
. V_414 = sizeof( T_1 ) ,
. V_415 = V_416 ,
. V_417 = 16 ,
. V_418 = V_419 ,
. V_420 = V_421 ,
. V_422 = F_3 ,
} ;
if ( V_80 != 0 )
goto V_19;
F_329 ( sizeof( struct V_232 ) > F_330 ( struct V_22 , V_175 ) ) ;
V_194 = F_57 ( V_219 , sizeof( * V_194 ) , V_64 ) ;
if ( ! V_194 )
goto F_325;
for ( V_61 = 0 ; V_61 < V_219 ; V_61 ++ ) {
if ( F_331 ( & V_194 [ V_61 ] . V_193 , & V_411 ) < 0 ) {
while ( -- V_61 > 0 )
F_332 ( & V_194 [ V_61 ] . V_193 ) ;
F_52 ( V_194 ) ;
goto F_325;
}
}
F_333 ( & V_15 ) ;
F_324 () ;
F_334 ( & V_423 ) ;
F_335 ( & V_424 ) ;
F_336 () ;
V_19:
return V_80 ;
F_325:
F_325 ( L_9 ) ;
}
