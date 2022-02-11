static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
static inline struct V_6 * F_4 ( struct V_7 * V_8 , T_1 V_9 )
{
return & V_8 -> V_10 [ F_5 ( V_9 , V_8 -> V_11 ) & V_8 -> V_12 ] ;
}
int F_6 ( struct V_13 * V_14 )
{
if ( F_7 ( V_14 -> V_15 -> type != V_16 ) )
return - V_17 ;
F_8 ( & V_18 ) ;
F_9 ( & V_14 -> V_19 , & V_20 ) ;
F_10 ( & V_18 ) ;
if ( V_14 -> V_21 )
F_11 ( V_14 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
bool V_22 = false ;
struct V_13 * V_23 ;
F_8 ( & V_18 ) ;
F_13 (tmp, &netlink_tap_all, list) {
if ( V_14 == V_23 ) {
F_14 ( & V_14 -> V_19 ) ;
V_22 = true ;
goto V_24;
}
}
F_15 ( L_1 , V_14 ) ;
V_24:
F_10 ( & V_18 ) ;
if ( V_22 && V_14 -> V_21 )
F_16 ( V_14 -> V_21 ) ;
return V_22 ? 0 : - V_25 ;
}
int F_17 ( struct V_13 * V_14 )
{
int V_26 ;
V_26 = F_12 ( V_14 ) ;
F_18 () ;
return V_26 ;
}
static bool F_19 ( const struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
bool V_29 = false ;
switch ( V_2 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_29 = true ;
break;
}
return V_29 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_39 * V_15 )
{
struct V_27 * V_40 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_26 = - V_41 ;
F_21 ( V_15 ) ;
V_40 = F_22 ( V_28 , V_42 ) ;
if ( V_40 ) {
V_40 -> V_15 = V_15 ;
V_40 -> V_43 = F_23 ( ( V_44 ) V_2 -> V_30 ) ;
V_40 -> V_45 = F_1 ( V_2 ) ?
V_46 : V_47 ;
V_26 = F_24 ( V_40 ) ;
if ( F_7 ( V_26 > 0 ) )
V_26 = F_25 ( V_26 ) ;
}
F_26 ( V_15 ) ;
return V_26 ;
}
static void F_27 ( struct V_27 * V_28 )
{
int V_26 ;
struct V_13 * V_23 ;
if ( ! F_19 ( V_28 ) )
return;
F_28 (tmp, &netlink_tap_all, list) {
V_26 = F_20 ( V_28 , V_23 -> V_15 ) ;
if ( F_7 ( V_26 ) )
break;
}
}
static void F_29 ( struct V_27 * V_28 )
{
F_30 () ;
if ( F_7 ( ! F_31 ( & V_20 ) ) )
F_27 ( V_28 ) ;
F_32 () ;
}
static void F_33 ( struct V_1 * V_48 , struct V_1 * V_49 ,
struct V_27 * V_28 )
{
if ( ! ( F_1 ( V_48 ) && F_1 ( V_49 ) ) )
F_29 ( V_28 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( ! ( V_51 -> V_3 & V_52 ) ) {
if ( ! F_35 ( V_53 , & F_2 ( V_2 ) -> V_54 ) ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_36 ( & V_2 -> V_58 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_59 ) )
F_39 ( V_53 , & V_51 -> V_54 ) ;
if ( ! F_40 ( V_53 , & V_51 -> V_54 ) )
F_41 ( & V_51 -> V_60 ) ;
}
static bool F_42 ( const struct V_27 * V_28 )
{
return F_43 ( V_28 ) . V_3 & V_61 ;
}
static bool F_44 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_62 . V_63 != NULL ;
}
static bool F_45 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_64 . V_63 != NULL ;
}
static void F_46 ( void * * V_63 , unsigned int V_65 , unsigned int V_66 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( V_63 [ V_67 ] != NULL ) {
if ( F_47 ( V_63 [ V_67 ] ) )
F_48 ( V_63 [ V_67 ] ) ;
else
F_49 ( ( unsigned long ) V_63 [ V_67 ] , V_65 ) ;
}
}
F_50 ( V_63 ) ;
}
static void * F_51 ( unsigned long V_65 )
{
void * V_68 ;
T_2 V_69 = V_70 | V_71 | V_72 |
V_73 | V_74 ;
V_68 = ( void * ) F_52 ( V_69 , V_65 ) ;
if ( V_68 != NULL )
return V_68 ;
V_68 = F_53 ( ( 1 << V_65 ) * V_75 ) ;
if ( V_68 != NULL )
return V_68 ;
V_69 &= ~ V_74 ;
return ( void * ) F_52 ( V_69 , V_65 ) ;
}
static void * * F_54 ( struct V_50 * V_51 ,
struct V_76 * V_77 , unsigned int V_65 )
{
unsigned int V_78 = V_77 -> V_79 ;
unsigned int V_67 ;
void * * V_63 ;
V_63 = F_55 ( V_78 , sizeof( void * ) , V_70 ) ;
if ( V_63 == NULL )
return NULL ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
V_63 [ V_67 ] = F_51 ( V_65 ) ;
if ( V_63 [ V_67 ] == NULL )
goto V_80;
}
return V_63 ;
V_80:
F_46 ( V_63 , V_65 , V_78 ) ;
return NULL ;
}
static int F_56 ( struct V_1 * V_2 , struct V_76 * V_77 ,
bool V_81 , bool V_64 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
void * * V_63 = NULL ;
unsigned int V_65 = 0 ;
int V_86 ;
V_83 = V_64 ? & V_51 -> V_64 : & V_51 -> V_62 ;
V_85 = V_64 ? & V_2 -> V_87 : & V_2 -> V_59 ;
if ( ! V_81 ) {
if ( F_57 ( & V_51 -> V_88 ) )
return - V_89 ;
if ( F_57 ( & V_83 -> V_90 ) )
return - V_89 ;
}
if ( V_77 -> V_79 ) {
if ( V_83 -> V_63 != NULL )
return - V_89 ;
if ( ( int ) V_77 -> V_91 <= 0 )
return - V_17 ;
if ( ! F_58 ( V_77 -> V_91 , V_75 ) )
return - V_17 ;
if ( V_77 -> V_92 < V_93 )
return - V_17 ;
if ( ! F_58 ( V_77 -> V_92 , V_94 ) )
return - V_17 ;
V_83 -> V_95 = V_77 -> V_91 /
V_77 -> V_92 ;
if ( V_83 -> V_95 == 0 )
return - V_17 ;
if ( V_83 -> V_95 * V_77 -> V_79 !=
V_77 -> V_96 )
return - V_17 ;
V_65 = F_59 ( V_77 -> V_91 ) ;
V_63 = F_54 ( V_51 , V_77 , V_65 ) ;
if ( V_63 == NULL )
return - V_41 ;
} else {
if ( V_77 -> V_96 )
return - V_17 ;
}
V_86 = - V_89 ;
F_60 ( & V_51 -> V_97 ) ;
if ( V_81 || F_57 ( & V_51 -> V_88 ) == 0 ) {
V_86 = 0 ;
F_61 ( & V_85 -> V_98 ) ;
V_83 -> V_99 = V_77 -> V_96 - 1 ;
V_83 -> V_100 = 0 ;
V_83 -> V_101 = V_77 -> V_92 ;
V_83 -> V_102 = V_77 -> V_91 / V_75 ;
F_62 ( V_83 -> V_103 , V_77 -> V_79 ) ;
F_62 ( V_83 -> V_104 , V_65 ) ;
F_62 ( V_83 -> V_63 , V_63 ) ;
F_63 ( V_85 ) ;
F_64 ( & V_85 -> V_98 ) ;
F_65 ( F_57 ( & V_51 -> V_88 ) ) ;
}
F_66 ( & V_51 -> V_97 ) ;
if ( V_63 )
F_46 ( V_63 , V_65 , V_77 -> V_79 ) ;
return V_86 ;
}
static void F_67 ( struct V_105 * V_106 )
{
struct V_107 * V_107 = V_106 -> V_108 ;
struct V_109 * V_1 = V_107 -> V_110 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_36 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static void F_68 ( struct V_105 * V_106 )
{
struct V_107 * V_107 = V_106 -> V_108 ;
struct V_109 * V_1 = V_107 -> V_110 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_69 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static int F_70 ( struct V_107 * V_107 , struct V_109 * V_1 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
unsigned long V_111 , V_112 , V_113 ;
unsigned int V_67 ;
int V_86 = - V_17 ;
if ( V_106 -> V_114 )
return - V_17 ;
F_60 ( & V_51 -> V_97 ) ;
V_113 = 0 ;
for ( V_83 = & V_51 -> V_62 ; V_83 <= & V_51 -> V_64 ; V_83 ++ ) {
if ( V_83 -> V_63 == NULL )
continue;
V_113 += V_83 -> V_103 * V_83 -> V_102 * V_75 ;
}
if ( V_113 == 0 )
goto V_24;
V_112 = V_106 -> V_115 - V_106 -> V_116 ;
if ( V_112 != V_113 )
goto V_24;
V_111 = V_106 -> V_116 ;
for ( V_83 = & V_51 -> V_62 ; V_83 <= & V_51 -> V_64 ; V_83 ++ ) {
if ( V_83 -> V_63 == NULL )
continue;
for ( V_67 = 0 ; V_67 < V_83 -> V_103 ; V_67 ++ ) {
struct V_117 * V_117 ;
void * V_118 = V_83 -> V_63 [ V_67 ] ;
unsigned int V_119 ;
for ( V_119 = 0 ; V_119 < V_83 -> V_102 ; V_119 ++ ) {
V_117 = F_71 ( V_118 ) ;
V_86 = F_72 ( V_106 , V_111 , V_117 ) ;
if ( V_86 < 0 )
goto V_24;
V_111 += V_75 ;
V_118 += V_75 ;
}
}
}
F_36 ( & V_51 -> V_88 ) ;
V_106 -> V_120 = & V_121 ;
V_86 = 0 ;
V_24:
F_66 ( & V_51 -> V_97 ) ;
return V_86 ;
}
static void F_73 ( const struct V_122 * V_123 )
{
#if V_124 == 1
struct V_117 * V_125 , * V_126 ;
V_125 = F_71 ( V_123 + V_75 ) ;
V_126 = F_71 ( ( void * ) V_123 + V_93 + V_123 -> V_127 - 1 ) ;
while ( V_125 <= V_126 ) {
F_74 ( V_125 ) ;
V_125 ++ ;
}
#endif
}
static enum V_128 F_75 ( const struct V_122 * V_123 )
{
F_76 () ;
F_74 ( F_71 ( V_123 ) ) ;
return V_123 -> V_129 ;
}
static void F_77 ( struct V_122 * V_123 ,
enum V_128 V_130 )
{
V_123 -> V_129 = V_130 ;
F_74 ( F_71 ( V_123 ) ) ;
F_78 () ;
}
static struct V_122 *
F_79 ( const struct V_82 * V_83 , unsigned int V_131 )
{
unsigned int V_132 , V_133 ;
V_132 = V_131 / V_83 -> V_95 ;
V_133 = V_131 % V_83 -> V_95 ;
return V_83 -> V_63 [ V_132 ] + ( V_133 * V_83 -> V_101 ) ;
}
static struct V_122 *
F_80 ( const struct V_82 * V_83 , unsigned int V_131 ,
enum V_128 V_130 )
{
struct V_122 * V_123 ;
V_123 = F_79 ( V_83 , V_131 ) ;
if ( F_75 ( V_123 ) != V_130 )
return NULL ;
return V_123 ;
}
static struct V_122 *
F_81 ( const struct V_82 * V_83 ,
enum V_128 V_130 )
{
return F_80 ( V_83 , V_83 -> V_100 , V_130 ) ;
}
static struct V_122 *
F_82 ( const struct V_82 * V_83 ,
enum V_128 V_130 )
{
unsigned int V_134 ;
V_134 = V_83 -> V_100 ? V_83 -> V_100 - 1 : V_83 -> V_99 ;
return F_80 ( V_83 , V_134 , V_130 ) ;
}
static void F_83 ( struct V_82 * V_83 )
{
V_83 -> V_100 = V_83 -> V_100 != V_83 -> V_99 ? V_83 -> V_100 + 1 : 0 ;
}
static void F_84 ( struct V_82 * V_83 )
{
unsigned int V_100 = V_83 -> V_100 , V_131 = V_100 ;
const struct V_122 * V_123 ;
do {
V_123 = F_79 ( V_83 , V_131 ) ;
if ( V_123 -> V_129 == V_135 )
break;
if ( V_123 -> V_129 != V_136 )
break;
F_83 ( V_83 ) ;
} while ( V_83 -> V_100 != V_100 );
}
static bool F_85 ( struct V_50 * V_51 )
{
struct V_82 * V_83 = & V_51 -> V_62 ;
struct V_122 * V_123 ;
unsigned int V_137 ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL )
return false ;
V_137 = V_83 -> V_100 + V_83 -> V_99 / 2 ;
if ( V_137 > V_83 -> V_99 )
V_137 -= V_83 -> V_99 ;
V_123 = F_79 ( V_83 , V_137 ) ;
return V_123 -> V_129 == V_135 ;
}
static unsigned int F_86 ( struct V_107 * V_107 , struct V_109 * V_1 ,
T_3 * V_60 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_12 ;
int V_86 ;
if ( V_51 -> V_62 . V_63 != NULL ) {
while ( V_51 -> V_138 && F_85 ( V_51 ) ) {
V_86 = F_87 ( V_2 ) ;
if ( V_86 < 0 ) {
V_2 -> V_55 = - V_86 ;
V_2 -> V_57 ( V_2 ) ;
break;
}
}
F_37 ( V_2 ) ;
}
V_12 = F_88 ( V_107 , V_1 , V_60 ) ;
F_61 ( & V_2 -> V_59 . V_98 ) ;
if ( V_51 -> V_62 . V_63 ) {
F_84 ( & V_51 -> V_62 ) ;
if ( ! F_82 ( & V_51 -> V_62 , V_135 ) )
V_12 |= V_139 | V_140 ;
}
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_61 ( & V_2 -> V_87 . V_98 ) ;
if ( V_51 -> V_64 . V_63 ) {
if ( F_81 ( & V_51 -> V_64 , V_135 ) )
V_12 |= V_141 | V_142 ;
}
F_64 ( & V_2 -> V_87 . V_98 ) ;
return V_12 ;
}
static struct V_122 * F_89 ( struct V_27 * V_28 )
{
return (struct V_122 * ) ( V_28 -> V_100 - V_93 ) ;
}
static void F_90 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_122 * V_123 )
{
unsigned int V_112 ;
void * V_143 ;
V_112 = V_83 -> V_101 - V_93 ;
V_143 = ( void * ) V_123 + V_93 ;
V_28 -> V_100 = V_143 ;
V_28 -> V_143 = V_143 ;
F_91 ( V_28 ) ;
V_28 -> V_144 = V_28 -> V_145 + V_112 ;
V_28 -> V_66 = 0 ;
V_28 -> V_146 = V_147 ;
F_43 ( V_28 ) . V_3 |= V_61 ;
F_43 ( V_28 ) . V_2 = V_2 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_148 * V_149 ,
T_1 V_150 , T_1 V_151 ,
struct V_152 * V_153 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_122 * V_123 ;
struct V_27 * V_28 ;
unsigned int V_154 ;
bool V_155 = true ;
int V_86 = 0 , V_66 = 0 ;
if ( F_93 ( & V_2 -> V_156 -> V_107 -> V_157 ) > 2 ||
F_57 ( & V_51 -> V_88 ) > 1 )
V_155 = false ;
F_60 ( & V_51 -> V_97 ) ;
V_83 = & V_51 -> V_64 ;
V_154 = V_83 -> V_101 - V_93 ;
do {
V_123 = F_81 ( V_83 , V_158 ) ;
if ( V_123 == NULL ) {
if ( ! ( V_149 -> V_159 & V_160 ) &&
F_57 ( & V_51 -> V_64 . V_90 ) )
F_94 () ;
continue;
}
if ( V_123 -> V_127 > V_154 ) {
V_86 = - V_17 ;
goto V_24;
}
F_73 ( V_123 ) ;
if ( F_95 ( V_150 == 0 && V_151 == 0 && V_155 ) ) {
V_28 = F_96 ( V_70 ) ;
if ( V_28 == NULL ) {
V_86 = - V_56 ;
goto V_24;
}
F_97 ( V_2 ) ;
F_90 ( V_28 , V_2 , V_83 , V_123 ) ;
F_43 ( V_28 ) . V_3 |= V_161 ;
F_98 ( V_28 , V_123 -> V_127 ) ;
F_77 ( V_123 , V_162 ) ;
F_36 ( & V_83 -> V_90 ) ;
} else {
V_28 = F_99 ( V_123 -> V_127 , V_70 ) ;
if ( V_28 == NULL ) {
V_86 = - V_56 ;
goto V_24;
}
F_98 ( V_28 , V_123 -> V_127 ) ;
memcpy ( V_28 -> V_143 , ( void * ) V_123 + V_93 , V_123 -> V_127 ) ;
F_77 ( V_123 , V_135 ) ;
}
F_83 ( V_83 ) ;
F_43 ( V_28 ) . V_9 = V_51 -> V_9 ;
F_43 ( V_28 ) . V_151 = V_151 ;
F_43 ( V_28 ) . V_163 = V_153 -> V_164 -> V_163 ;
V_86 = F_100 ( V_2 , V_28 ) ;
if ( V_86 ) {
F_101 ( V_28 ) ;
goto V_24;
}
if ( F_7 ( V_151 ) ) {
F_36 ( & V_28 -> V_165 ) ;
F_102 ( V_2 , V_28 , V_150 , V_151 ,
V_70 ) ;
}
V_86 = F_103 ( V_2 , V_28 , V_150 ,
V_149 -> V_159 & V_160 ) ;
if ( V_86 < 0 )
goto V_24;
V_66 += V_86 ;
} while ( V_123 != NULL ||
( ! ( V_149 -> V_159 & V_160 ) &&
F_57 ( & V_51 -> V_64 . V_90 ) ) );
if ( V_66 > 0 )
V_86 = V_66 ;
V_24:
F_66 ( & V_51 -> V_97 ) ;
return V_86 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_122 * V_123 ;
V_123 = F_89 ( V_28 ) ;
V_123 -> V_127 = V_28 -> V_66 ;
V_123 -> V_166 = F_43 ( V_28 ) . V_151 ;
V_123 -> V_167 = F_43 ( V_28 ) . V_163 . V_168 ;
V_123 -> V_169 = F_105 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_170 ) ;
V_123 -> V_171 = F_107 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_172 ) ;
F_73 ( V_123 ) ;
F_77 ( V_123 , V_158 ) ;
F_43 ( V_28 ) . V_3 |= V_173 ;
F_101 ( V_28 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 = & V_51 -> V_62 ;
struct V_122 * V_123 ;
F_61 ( & V_2 -> V_59 . V_98 ) ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL ) {
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_101 ( V_28 ) ;
F_34 ( V_2 ) ;
return;
}
F_83 ( V_83 ) ;
F_109 ( & V_2 -> V_59 , V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
V_123 -> V_127 = V_28 -> V_66 ;
V_123 -> V_166 = F_43 ( V_28 ) . V_151 ;
V_123 -> V_167 = F_43 ( V_28 ) . V_163 . V_168 ;
V_123 -> V_169 = F_105 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_170 ) ;
V_123 -> V_171 = F_107 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_172 ) ;
F_77 ( V_123 , V_174 ) ;
}
static void V_147 ( struct V_27 * V_28 )
{
#ifdef F_110
struct V_122 * V_123 ;
struct V_82 * V_83 ;
struct V_1 * V_2 ;
if ( F_42 ( V_28 ) ) {
V_123 = F_89 ( V_28 ) ;
V_2 = F_43 ( V_28 ) . V_2 ;
if ( F_43 ( V_28 ) . V_3 & V_161 ) {
F_77 ( V_123 , V_135 ) ;
V_83 = & F_2 ( V_2 ) -> V_64 ;
} else {
if ( ! ( F_43 ( V_28 ) . V_3 & V_173 ) ) {
V_123 -> V_127 = 0 ;
F_77 ( V_123 , V_158 ) ;
}
V_83 = & F_2 ( V_2 ) -> V_62 ;
}
F_65 ( F_57 ( & V_83 -> V_90 ) == 0 ) ;
F_69 ( & V_83 -> V_90 ) ;
F_111 ( V_2 ) ;
V_28 -> V_100 = NULL ;
}
#endif
if ( F_47 ( V_28 -> V_100 ) ) {
if ( ! V_28 -> V_175 ||
! F_112 ( & ( F_113 ( V_28 ) -> V_176 ) ) )
F_48 ( V_28 -> V_100 ) ;
V_28 -> V_100 = NULL ;
}
if ( V_28 -> V_2 != NULL )
F_114 ( V_28 ) ;
}
static void F_115 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
F_65 ( V_28 -> V_2 != NULL ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_146 = V_147 ;
F_116 ( V_28 -> V_177 , & V_2 -> V_178 ) ;
F_117 ( V_2 , V_28 -> V_177 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_138 ) {
if ( V_51 -> V_179 . V_180 )
V_51 -> V_179 . V_180 ( & V_51 -> V_179 ) ;
F_16 ( V_51 -> V_179 . V_21 ) ;
F_101 ( V_51 -> V_179 . V_28 ) ;
}
F_119 ( & V_2 -> V_59 ) ;
#ifdef F_110
if ( 1 ) {
struct V_76 V_77 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_51 -> V_62 . V_63 )
F_56 ( V_2 , & V_77 , true , false ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_51 -> V_64 . V_63 )
F_56 ( V_2 , & V_77 , true , true ) ;
}
#endif
if ( ! F_120 ( V_2 , V_181 ) ) {
F_121 ( V_182 L_2 , V_2 ) ;
return;
}
F_65 ( F_57 ( & V_2 -> V_178 ) ) ;
F_65 ( F_57 ( & V_2 -> V_183 ) ) ;
F_65 ( F_2 ( V_2 ) -> V_184 ) ;
}
void F_122 ( void )
__acquires( T_4 )
{
F_123 () ;
F_124 ( & T_4 ) ;
if ( F_57 ( & V_185 ) ) {
F_125 ( V_60 , V_186 ) ;
F_126 ( & V_187 , & V_60 ) ;
for (; ; ) {
F_127 ( V_188 ) ;
if ( F_57 ( & V_185 ) == 0 )
break;
F_128 ( & T_4 ) ;
F_94 () ;
F_124 ( & T_4 ) ;
}
F_129 ( V_189 ) ;
F_130 ( & V_187 , & V_60 ) ;
}
}
void F_131 ( void )
__releases( T_4 )
{
F_128 ( & T_4 ) ;
F_132 ( & V_187 ) ;
}
static inline void
F_133 ( void )
{
F_134 ( & T_4 ) ;
F_36 ( & V_185 ) ;
F_135 ( & T_4 ) ;
}
static inline void
F_136 ( void )
{
if ( F_137 ( & V_185 ) )
F_132 ( & V_187 ) ;
}
static bool F_138 ( struct V_190 * V_190 , struct V_1 * V_2 )
{
return F_139 ( F_140 ( V_2 ) , V_190 ) ;
}
static struct V_1 * F_141 ( struct V_190 * V_190 , int V_43 , T_1 V_9 )
{
struct V_191 * V_10 = & V_192 [ V_43 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
struct V_1 * V_2 ;
F_134 ( & T_4 ) ;
V_100 = F_4 ( V_8 , V_9 ) ;
F_142 (sk, head) {
if ( V_10 -> V_193 ( V_190 , V_2 ) &&
( F_2 ( V_2 ) -> V_9 == V_9 ) ) {
F_97 ( V_2 ) ;
goto V_22;
}
}
V_2 = NULL ;
V_22:
F_135 ( & T_4 ) ;
return V_2 ;
}
static struct V_6 * F_143 ( T_5 V_112 )
{
if ( V_112 <= V_75 )
return F_144 ( V_112 , V_42 ) ;
else
return (struct V_6 * )
F_52 ( V_42 | V_72 ,
F_59 ( V_112 ) ) ;
}
static void F_145 ( struct V_6 * V_10 , T_5 V_112 )
{
if ( V_112 <= V_75 )
F_50 ( V_10 ) ;
else
F_49 ( ( unsigned long ) V_10 , F_59 ( V_112 ) ) ;
}
static int F_146 ( struct V_7 * V_8 , int V_194 )
{
unsigned int V_195 , V_12 , V_196 ;
T_5 V_197 , V_112 ;
struct V_6 * V_198 , * V_10 ;
int V_67 ;
V_195 = V_12 = V_8 -> V_12 ;
V_197 = V_112 = ( V_12 + 1 ) * sizeof( * V_10 ) ;
V_196 = V_8 -> V_196 ;
if ( V_194 ) {
if ( ++ V_196 > V_8 -> V_199 )
return 0 ;
V_12 = V_12 * 2 + 1 ;
V_112 *= 2 ;
}
V_10 = F_143 ( V_112 ) ;
if ( ! V_10 )
return 0 ;
V_198 = V_8 -> V_10 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_196 = V_196 ;
F_147 ( & V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
for ( V_67 = 0 ; V_67 <= V_195 ; V_67 ++ ) {
struct V_1 * V_2 ;
struct V_200 * V_23 ;
F_148 (sk, tmp, &otable[i])
F_149 ( V_2 , F_4 ( V_8 , F_2 ( V_2 ) -> V_9 ) ) ;
}
F_145 ( V_198 , V_197 ) ;
V_8 -> V_201 = V_202 + 10 * 60 * V_203 ;
return 1 ;
}
static inline int F_150 ( struct V_7 * V_8 , int V_66 )
{
int V_204 = V_8 -> V_205 >> V_8 -> V_196 ;
if ( F_7 ( V_204 > 1 ) && F_146 ( V_8 , 1 ) )
return 1 ;
if ( F_7 ( V_66 > V_204 ) && F_151 ( V_202 , V_8 -> V_201 ) ) {
F_146 ( V_8 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_152 ( struct V_1 * V_2 )
{
struct V_191 * V_206 = & V_192 [ V_2 -> V_30 ] ;
unsigned long V_12 ;
unsigned int V_67 ;
struct V_207 * V_207 ;
V_207 = F_153 ( V_206 -> V_207 ) ;
if ( ! V_207 )
return;
for ( V_67 = 0 ; V_67 < F_154 ( V_206 -> V_184 ) ; V_67 ++ ) {
V_12 = 0 ;
F_155 (sk, &tbl->mc_list) {
if ( V_67 < F_154 ( F_2 ( V_2 ) -> V_208 ) )
V_12 |= F_2 ( V_2 ) -> V_184 [ V_67 ] ;
}
V_207 -> V_209 [ V_67 ] = V_12 ;
}
}
static int F_156 ( struct V_1 * V_2 , struct V_190 * V_190 , T_1 V_9 )
{
struct V_191 * V_10 = & V_192 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
int V_86 = - V_210 ;
struct V_1 * V_211 ;
int V_66 ;
F_122 () ;
V_100 = F_4 ( V_8 , V_9 ) ;
V_66 = 0 ;
F_142 (osk, head) {
if ( V_10 -> V_193 ( V_190 , V_211 ) &&
( F_2 ( V_211 ) -> V_9 == V_9 ) )
break;
V_66 ++ ;
}
if ( V_211 )
goto V_86;
V_86 = - V_89 ;
if ( F_2 ( V_2 ) -> V_9 )
goto V_86;
V_86 = - V_41 ;
if ( V_212 > 32 && F_7 ( V_8 -> V_205 >= V_213 ) )
goto V_86;
if ( V_66 && F_150 ( V_8 , V_66 ) )
V_100 = F_4 ( V_8 , V_9 ) ;
V_8 -> V_205 ++ ;
F_2 ( V_2 ) -> V_9 = V_9 ;
F_157 ( V_2 , V_100 ) ;
V_86 = 0 ;
V_86:
F_131 () ;
return V_86 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_122 () ;
if ( F_159 ( V_2 ) )
V_192 [ V_2 -> V_30 ] . V_8 . V_205 -- ;
if ( F_2 ( V_2 ) -> V_214 )
F_160 ( V_2 ) ;
F_131 () ;
}
static int F_161 ( struct V_190 * V_190 , struct V_109 * V_1 ,
struct V_215 * V_216 , int V_43 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_217 = & V_218 ;
V_2 = F_162 ( V_190 , V_219 , V_70 , & V_220 ) ;
if ( ! V_2 )
return - V_41 ;
F_163 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_216 ) {
V_51 -> V_216 = V_216 ;
} else {
V_51 -> V_216 = & V_51 -> V_221 ;
F_164 ( V_51 -> V_216 ) ;
}
F_165 ( & V_51 -> V_60 ) ;
#ifdef F_110
F_164 ( & V_51 -> V_97 ) ;
#endif
V_2 -> V_222 = F_118 ;
V_2 -> V_30 = V_43 ;
return 0 ;
}
static int F_166 ( struct V_190 * V_190 , struct V_109 * V_1 , int V_43 ,
int V_223 )
{
struct V_21 * V_21 = NULL ;
struct V_215 * V_216 ;
struct V_50 * V_51 ;
int (* F_167)( int V_5 );
void (* F_168)( int V_5 );
int V_86 = 0 ;
V_1 -> V_54 = V_224 ;
if ( V_1 -> type != V_225 && V_1 -> type != V_226 )
return - V_227 ;
if ( V_43 < 0 || V_43 >= V_228 )
return - V_229 ;
F_133 () ;
#ifdef F_169
if ( ! V_192 [ V_43 ] . V_230 ) {
F_136 () ;
F_170 ( L_3 , V_219 , V_43 ) ;
F_133 () ;
}
#endif
if ( V_192 [ V_43 ] . V_230 &&
F_171 ( V_192 [ V_43 ] . V_21 ) )
V_21 = V_192 [ V_43 ] . V_21 ;
else
V_86 = - V_229 ;
V_216 = V_192 [ V_43 ] . V_216 ;
F_167 = V_192 [ V_43 ] . F_167 ;
F_168 = V_192 [ V_43 ] . F_168 ;
F_136 () ;
if ( V_86 < 0 )
goto V_24;
V_86 = F_161 ( V_190 , V_1 , V_216 , V_43 ) ;
if ( V_86 < 0 )
goto V_231;
F_172 () ;
F_173 ( V_190 , & V_220 , 1 ) ;
F_174 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_21 = V_21 ;
V_51 -> V_232 = F_167 ;
V_51 -> V_233 = F_168 ;
V_24:
return V_86 ;
V_231:
F_16 ( V_21 ) ;
goto V_24;
}
static int F_175 ( struct V_109 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_158 ( V_2 ) ;
F_176 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_177 ( & V_51 -> V_60 ) ;
F_119 ( & V_2 -> V_87 ) ;
if ( V_51 -> V_9 ) {
struct V_234 V_137 = {
. V_190 = F_140 ( V_2 ) ,
. V_43 = V_2 -> V_30 ,
. V_9 = V_51 -> V_9 ,
} ;
F_178 ( & V_235 ,
V_236 , & V_137 ) ;
}
F_16 ( V_51 -> V_21 ) ;
F_122 () ;
if ( F_1 ( V_2 ) ) {
F_179 ( V_192 [ V_2 -> V_30 ] . V_230 == 0 ) ;
if ( -- V_192 [ V_2 -> V_30 ] . V_230 == 0 ) {
struct V_207 * V_237 ;
V_237 = F_153 ( V_192 [ V_2 -> V_30 ] . V_207 ) ;
F_180 ( V_192 [ V_2 -> V_30 ] . V_207 , NULL ) ;
F_181 ( V_237 , V_238 ) ;
V_192 [ V_2 -> V_30 ] . V_21 = NULL ;
V_192 [ V_2 -> V_30 ] . F_167 = NULL ;
V_192 [ V_2 -> V_30 ] . F_168 = NULL ;
V_192 [ V_2 -> V_30 ] . V_3 = 0 ;
V_192 [ V_2 -> V_30 ] . V_230 = 0 ;
}
} else if ( V_51 -> V_214 ) {
F_152 ( V_2 ) ;
}
F_131 () ;
F_50 ( V_51 -> V_184 ) ;
V_51 -> V_184 = NULL ;
F_172 () ;
F_173 ( F_140 ( V_2 ) , & V_220 , - 1 ) ;
F_174 () ;
F_111 ( V_2 ) ;
return 0 ;
}
static int F_182 ( struct V_109 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_140 ( V_2 ) ;
struct V_191 * V_10 = & V_192 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
struct V_1 * V_211 ;
T_6 V_9 = F_183 ( V_186 ) ;
int V_86 ;
static T_6 V_239 = - 4097 ;
V_240:
F_184 () ;
F_122 () ;
V_100 = F_4 ( V_8 , V_9 ) ;
F_142 (osk, head) {
if ( ! V_10 -> V_193 ( V_190 , V_211 ) )
continue;
if ( F_2 ( V_211 ) -> V_9 == V_9 ) {
V_9 = V_239 -- ;
if ( V_239 > - 4097 )
V_239 = - 4097 ;
F_131 () ;
goto V_240;
}
}
F_131 () ;
V_86 = F_156 ( V_2 , V_190 , V_9 ) ;
if ( V_86 == - V_210 )
goto V_240;
if ( V_86 == - V_89 )
V_86 = 0 ;
return V_86 ;
}
bool F_185 ( const struct V_241 * V_242 ,
struct V_243 * V_244 , int V_245 )
{
return ( ( V_242 -> V_3 & V_246 ) ||
F_186 ( V_242 -> V_2 -> V_156 -> V_107 , V_244 , V_245 ) ) &&
F_187 ( V_244 , V_245 ) ;
}
bool F_188 ( const struct V_27 * V_28 ,
struct V_243 * V_244 , int V_245 )
{
return F_185 ( & F_43 ( V_28 ) , V_244 , V_245 ) ;
}
bool F_189 ( const struct V_27 * V_28 , int V_245 )
{
return F_188 ( V_28 , & V_247 , V_245 ) ;
}
bool F_190 ( const struct V_27 * V_28 , int V_245 )
{
return F_188 ( V_28 , F_140 ( V_28 -> V_2 ) -> V_244 , V_245 ) ;
}
static inline int F_191 ( const struct V_109 * V_1 , unsigned int V_248 )
{
return ( V_192 [ V_1 -> V_2 -> V_30 ] . V_3 & V_248 ) ||
F_187 ( F_140 ( V_1 -> V_2 ) -> V_244 , V_249 ) ;
}
static void
F_192 ( struct V_1 * V_2 , unsigned int V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_214 && ! V_214 )
F_160 ( V_2 ) ;
else if ( ! V_51 -> V_214 && V_214 )
F_193 ( V_2 , & V_192 [ V_2 -> V_30 ] . V_250 ) ;
V_51 -> V_214 = V_214 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_184 ;
unsigned long * V_251 ;
int V_86 = 0 ;
F_122 () ;
V_184 = V_192 [ V_2 -> V_30 ] . V_184 ;
if ( ! V_192 [ V_2 -> V_30 ] . V_230 ) {
V_86 = - V_252 ;
goto V_253;
}
if ( V_51 -> V_208 >= V_184 )
goto V_253;
V_251 = F_195 ( V_51 -> V_184 , F_196 ( V_184 ) , V_42 ) ;
if ( V_251 == NULL ) {
V_86 = - V_41 ;
goto V_253;
}
memset ( ( char * ) V_251 + F_196 ( V_51 -> V_208 ) , 0 ,
F_196 ( V_184 ) - F_196 ( V_51 -> V_208 ) ) ;
V_51 -> V_184 = V_251 ;
V_51 -> V_208 = V_184 ;
V_253:
F_131 () ;
return V_86 ;
}
static void V_233 ( int V_5 , long unsigned int V_184 ,
struct V_50 * V_51 )
{
int V_254 ;
if ( ! V_51 -> V_233 )
return;
for ( V_254 = 0 ; V_254 < V_5 ; V_254 ++ )
if ( F_40 ( V_5 , & V_184 ) )
V_51 -> V_233 ( V_254 ) ;
}
static int V_232 ( struct V_109 * V_1 , struct V_255 * V_256 ,
int V_257 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_140 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_256 ;
int V_86 ;
long unsigned int V_184 = V_259 -> V_260 ;
if ( V_257 < sizeof( struct V_258 ) )
return - V_17 ;
if ( V_259 -> V_261 != V_262 )
return - V_17 ;
if ( V_184 ) {
if ( ! F_191 ( V_1 , V_263 ) )
return - V_264 ;
V_86 = F_194 ( V_2 ) ;
if ( V_86 )
return V_86 ;
}
if ( V_51 -> V_9 )
if ( V_259 -> V_265 != V_51 -> V_9 )
return - V_17 ;
if ( V_51 -> V_232 && V_184 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_51 -> V_208 ; V_5 ++ ) {
if ( ! F_40 ( V_5 , & V_184 ) )
continue;
V_86 = V_51 -> V_232 ( V_5 ) ;
if ( ! V_86 )
continue;
V_233 ( V_5 , V_184 , V_51 ) ;
return V_86 ;
}
}
if ( ! V_51 -> V_9 ) {
V_86 = V_259 -> V_265 ?
F_156 ( V_2 , V_190 , V_259 -> V_265 ) :
F_182 ( V_1 ) ;
if ( V_86 ) {
V_233 ( V_51 -> V_208 - 1 , V_184 , V_51 ) ;
return V_86 ;
}
}
if ( ! V_184 && ( V_51 -> V_184 == NULL || ! ( T_1 ) V_51 -> V_184 [ 0 ] ) )
return 0 ;
F_122 () ;
F_192 ( V_2 , V_51 -> V_214 +
F_197 ( V_184 ) -
F_197 ( V_51 -> V_184 [ 0 ] ) ) ;
V_51 -> V_184 [ 0 ] = ( V_51 -> V_184 [ 0 ] & ~ 0xffffffffUL ) | V_184 ;
F_152 ( V_2 ) ;
F_131 () ;
return 0 ;
}
static int F_198 ( struct V_109 * V_1 , struct V_255 * V_256 ,
int V_266 , int V_3 )
{
int V_86 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_256 ;
if ( V_266 < sizeof( V_256 -> V_267 ) )
return - V_17 ;
if ( V_256 -> V_267 == V_268 ) {
V_2 -> V_269 = V_270 ;
V_51 -> V_150 = 0 ;
V_51 -> V_151 = 0 ;
return 0 ;
}
if ( V_256 -> V_267 != V_262 )
return - V_17 ;
if ( ( V_259 -> V_260 || V_259 -> V_265 ) &&
! F_191 ( V_1 , V_271 ) )
return - V_264 ;
if ( ! V_51 -> V_9 )
V_86 = F_182 ( V_1 ) ;
if ( V_86 == 0 ) {
V_2 -> V_269 = V_272 ;
V_51 -> V_150 = V_259 -> V_265 ;
V_51 -> V_151 = F_199 ( V_259 -> V_260 ) ;
}
return V_86 ;
}
static int F_200 ( struct V_109 * V_1 , struct V_255 * V_256 ,
int * V_257 , int V_273 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_201 ( struct V_258 * , V_259 , V_256 ) ;
V_259 -> V_261 = V_262 ;
V_259 -> V_274 = 0 ;
* V_257 = sizeof( * V_259 ) ;
if ( V_273 ) {
V_259 -> V_265 = V_51 -> V_150 ;
V_259 -> V_260 = F_3 ( V_51 -> V_151 ) ;
} else {
V_259 -> V_265 = V_51 -> V_9 ;
V_259 -> V_260 = V_51 -> V_184 ? V_51 -> V_184 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_202 ( struct V_1 * V_275 , T_1 V_9 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_141 ( F_140 ( V_275 ) , V_275 -> V_30 , V_9 ) ;
if ( ! V_1 )
return F_203 ( - V_276 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_269 == V_272 &&
V_51 -> V_150 != F_2 ( V_275 ) -> V_9 ) {
F_111 ( V_1 ) ;
return F_203 ( - V_276 ) ;
}
return V_1 ;
}
struct V_1 * F_204 ( struct V_107 * V_277 )
{
struct V_278 * V_278 = F_205 ( V_277 ) ;
struct V_1 * V_1 ;
if ( ! F_206 ( V_278 -> V_279 ) )
return F_203 ( - V_280 ) ;
V_1 = F_207 ( V_278 ) -> V_2 ;
if ( V_1 -> V_281 != V_262 )
return F_203 ( - V_17 ) ;
F_97 ( V_1 ) ;
return V_1 ;
}
static struct V_27 * F_208 ( unsigned int V_112 ,
int V_282 )
{
struct V_27 * V_28 ;
void * V_143 ;
if ( V_112 <= V_283 || V_282 )
return F_99 ( V_112 , V_70 ) ;
V_112 = F_209 ( V_112 ) +
F_209 ( sizeof( struct V_284 ) ) ;
V_143 = F_210 ( V_112 ) ;
if ( V_143 == NULL )
return NULL ;
V_28 = F_211 ( V_143 , V_112 ) ;
if ( V_28 == NULL )
F_48 ( V_143 ) ;
else {
V_28 -> V_285 = 0 ;
V_28 -> V_146 = V_147 ;
}
return V_28 ;
}
int F_212 ( struct V_1 * V_2 , struct V_27 * V_28 ,
long * V_286 , struct V_1 * V_275 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_57 ( & V_2 -> V_178 ) > V_2 -> V_287 ||
F_40 ( V_53 , & V_51 -> V_54 ) ) &&
! F_42 ( V_28 ) ) {
F_125 ( V_60 , V_186 ) ;
if ( ! * V_286 ) {
if ( ! V_275 || F_1 ( V_275 ) )
F_34 ( V_2 ) ;
F_111 ( V_2 ) ;
F_101 ( V_28 ) ;
return - V_288 ;
}
F_129 ( V_289 ) ;
F_213 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_57 ( & V_2 -> V_178 ) > V_2 -> V_287 ||
F_40 ( V_53 , & V_51 -> V_54 ) ) &&
! F_120 ( V_2 , V_181 ) )
* V_286 = F_214 ( * V_286 ) ;
F_129 ( V_189 ) ;
F_130 ( & V_51 -> V_60 , & V_60 ) ;
F_111 ( V_2 ) ;
if ( F_215 ( V_186 ) ) {
F_101 ( V_28 ) ;
return F_216 ( * V_286 ) ;
}
return 1 ;
}
F_115 ( V_28 , V_2 ) ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_66 = V_28 -> V_66 ;
F_29 ( V_28 ) ;
#ifdef F_110
if ( F_42 ( V_28 ) )
F_104 ( V_2 , V_28 ) ;
else if ( F_44 ( V_2 ) )
F_108 ( V_2 , V_28 ) ;
else
#endif
F_218 ( & V_2 -> V_59 , V_28 ) ;
V_2 -> V_290 ( V_2 ) ;
return V_66 ;
}
int F_219 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_66 = F_217 ( V_2 , V_28 ) ;
F_111 ( V_2 ) ;
return V_66 ;
}
void F_220 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_101 ( V_28 ) ;
F_111 ( V_2 ) ;
}
static struct V_27 * F_221 ( struct V_27 * V_28 , T_2 V_291 )
{
int V_292 ;
F_65 ( V_28 -> V_2 != NULL ) ;
if ( F_42 ( V_28 ) )
return V_28 ;
V_292 = V_28 -> V_144 - V_28 -> V_145 ;
if ( F_47 ( V_28 -> V_100 ) || V_292 * 2 < V_28 -> V_177 )
return V_28 ;
if ( F_222 ( V_28 ) ) {
struct V_27 * V_40 = F_22 ( V_28 , V_291 ) ;
if ( ! V_40 )
return V_28 ;
F_223 ( V_28 ) ;
V_28 = V_40 ;
}
if ( ! F_224 ( V_28 , 0 , - V_292 , V_291 ) )
V_28 -> V_177 -= V_292 ;
return V_28 ;
}
static int F_225 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_1 * V_275 )
{
int V_26 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_26 = - V_276 ;
if ( V_51 -> V_293 != NULL ) {
V_26 = V_28 -> V_66 ;
F_115 ( V_28 , V_2 ) ;
F_43 ( V_28 ) . V_2 = V_275 ;
F_33 ( V_2 , V_275 , V_28 ) ;
V_51 -> V_293 ( V_28 ) ;
F_223 ( V_28 ) ;
} else {
F_101 ( V_28 ) ;
}
F_111 ( V_2 ) ;
return V_26 ;
}
int F_103 ( struct V_1 * V_275 , struct V_27 * V_28 ,
T_1 V_9 , int V_294 )
{
struct V_1 * V_2 ;
int V_86 ;
long V_286 ;
V_28 = F_221 ( V_28 , F_226 () ) ;
V_286 = F_227 ( V_275 , V_294 ) ;
V_240:
V_2 = F_202 ( V_275 , V_9 ) ;
if ( F_228 ( V_2 ) ) {
F_101 ( V_28 ) ;
return F_229 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_225 ( V_2 , V_28 , V_275 ) ;
if ( F_230 ( V_2 , V_28 ) ) {
V_86 = V_28 -> V_66 ;
F_101 ( V_28 ) ;
F_111 ( V_2 ) ;
return V_86 ;
}
V_86 = F_212 ( V_2 , V_28 , & V_286 , V_275 ) ;
if ( V_86 == 1 )
goto V_240;
if ( V_86 )
return V_86 ;
return F_219 ( V_2 , V_28 ) ;
}
struct V_27 * F_231 ( struct V_1 * V_275 , unsigned int V_112 ,
T_1 V_150 , T_2 V_295 )
{
#ifdef F_110
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 ;
struct V_82 * V_83 ;
struct V_122 * V_123 ;
unsigned int V_154 ;
V_2 = F_202 ( V_275 , V_150 ) ;
if ( F_228 ( V_2 ) )
goto V_24;
V_83 = & F_2 ( V_2 ) -> V_62 ;
if ( V_83 -> V_63 == NULL )
goto V_296;
if ( V_83 -> V_101 - V_93 < V_112 )
goto V_296;
V_28 = F_96 ( V_295 ) ;
if ( V_28 == NULL )
goto V_80;
F_61 ( & V_2 -> V_59 . V_98 ) ;
if ( V_83 -> V_63 == NULL )
goto V_297;
V_154 = V_83 -> V_101 - V_93 ;
if ( V_154 < V_112 )
goto V_297;
F_84 ( V_83 ) ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL )
goto V_298;
F_90 ( V_28 , V_2 , V_83 , V_123 ) ;
F_77 ( V_123 , V_162 ) ;
F_36 ( & V_83 -> V_90 ) ;
F_83 ( V_83 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
return V_28 ;
V_298:
F_101 ( V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_34 ( V_2 ) ;
V_80:
F_111 ( V_2 ) ;
return NULL ;
V_297:
F_101 ( V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
V_296:
F_111 ( V_2 ) ;
V_24:
#endif
return F_99 ( V_112 , V_295 ) ;
}
int F_232 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_299 = 0 ;
struct V_207 * V_207 ;
F_179 ( ! F_1 ( V_2 ) ) ;
F_30 () ;
V_207 = F_233 ( V_192 [ V_2 -> V_30 ] . V_207 ) ;
if ( V_207 && V_5 - 1 < V_192 [ V_2 -> V_30 ] . V_184 )
V_299 = F_40 ( V_5 - 1 , V_207 -> V_209 ) ;
F_32 () ;
return V_299 ;
}
static int F_234 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_57 ( & V_2 -> V_178 ) <= V_2 -> V_287 &&
! F_40 ( V_53 , & V_51 -> V_54 ) ) {
F_115 ( V_28 , V_2 ) ;
F_217 ( V_2 , V_28 ) ;
return F_57 ( & V_2 -> V_178 ) > ( V_2 -> V_287 >> 1 ) ;
}
return - 1 ;
}
static int F_235 ( struct V_1 * V_2 ,
struct V_300 * V_301 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_302 ;
if ( V_301 -> V_303 == V_2 )
goto V_24;
if ( V_51 -> V_9 == V_301 -> V_9 || V_301 -> V_5 - 1 >= V_51 -> V_208 ||
! F_40 ( V_301 -> V_5 - 1 , V_51 -> V_184 ) )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , V_301 -> V_190 ) )
goto V_24;
if ( V_301 -> V_304 ) {
F_34 ( V_2 ) ;
goto V_24;
}
F_97 ( V_2 ) ;
if ( V_301 -> V_305 == NULL ) {
if ( F_222 ( V_301 -> V_28 ) ) {
V_301 -> V_305 = F_22 ( V_301 -> V_28 , V_301 -> V_291 ) ;
} else {
V_301 -> V_305 = F_236 ( V_301 -> V_28 ) ;
F_237 ( V_301 -> V_305 ) ;
}
}
if ( V_301 -> V_305 == NULL ) {
F_34 ( V_2 ) ;
V_301 -> V_304 = 1 ;
if ( V_51 -> V_3 & V_306 )
V_301 -> V_307 = 1 ;
} else if ( V_301 -> V_308 && V_301 -> V_308 ( V_2 , V_301 -> V_305 , V_301 -> V_309 ) ) {
F_101 ( V_301 -> V_305 ) ;
V_301 -> V_305 = NULL ;
} else if ( F_230 ( V_2 , V_301 -> V_305 ) ) {
F_101 ( V_301 -> V_305 ) ;
V_301 -> V_305 = NULL ;
} else if ( ( V_302 = F_234 ( V_2 , V_301 -> V_305 ) ) < 0 ) {
F_34 ( V_2 ) ;
if ( V_51 -> V_3 & V_306 )
V_301 -> V_307 = 1 ;
} else {
V_301 -> V_310 |= V_302 ;
V_301 -> V_311 = 1 ;
V_301 -> V_305 = NULL ;
}
F_111 ( V_2 ) ;
V_24:
return 0 ;
}
int F_238 ( struct V_1 * V_275 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_291 ,
int (* F_239)( struct V_1 * V_312 , struct V_27 * V_28 , void * V_143 ) ,
void * V_313 )
{
struct V_190 * V_190 = F_140 ( V_275 ) ;
struct V_300 V_314 ;
struct V_1 * V_2 ;
V_28 = F_221 ( V_28 , V_291 ) ;
V_314 . V_303 = V_275 ;
V_314 . V_190 = V_190 ;
V_314 . V_9 = V_9 ;
V_314 . V_5 = V_5 ;
V_314 . V_304 = 0 ;
V_314 . V_307 = 0 ;
V_314 . V_310 = 0 ;
V_314 . V_311 = 0 ;
V_314 . V_291 = V_291 ;
V_314 . V_28 = V_28 ;
V_314 . V_305 = NULL ;
V_314 . V_308 = F_239 ;
V_314 . V_309 = V_313 ;
F_133 () ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_235 ( V_2 , & V_314 ) ;
F_223 ( V_28 ) ;
F_136 () ;
if ( V_314 . V_307 ) {
F_101 ( V_314 . V_305 ) ;
return - V_56 ;
}
F_223 ( V_314 . V_305 ) ;
if ( V_314 . V_311 ) {
if ( V_314 . V_310 && ( V_291 & V_315 ) )
F_240 () ;
return 0 ;
}
return - V_316 ;
}
int F_102 ( struct V_1 * V_275 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_291 )
{
return F_238 ( V_275 , V_28 , V_9 , V_5 , V_291 ,
NULL , NULL ) ;
}
static int F_241 ( struct V_1 * V_2 , struct V_317 * V_301 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( V_2 == V_301 -> V_303 )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , F_140 ( V_301 -> V_303 ) ) )
goto V_24;
if ( V_51 -> V_9 == V_301 -> V_9 || V_301 -> V_5 - 1 >= V_51 -> V_208 ||
! F_40 ( V_301 -> V_5 - 1 , V_51 -> V_184 ) )
goto V_24;
if ( V_301 -> V_318 == V_56 && V_51 -> V_3 & V_52 ) {
V_26 = 1 ;
goto V_24;
}
V_2 -> V_55 = V_301 -> V_318 ;
V_2 -> V_57 ( V_2 ) ;
V_24:
return V_26 ;
}
int F_242 ( struct V_1 * V_275 , T_1 V_9 , T_1 V_5 , int V_318 )
{
struct V_317 V_314 ;
struct V_1 * V_2 ;
int V_26 = 0 ;
V_314 . V_303 = V_275 ;
V_314 . V_9 = V_9 ;
V_314 . V_5 = V_5 ;
V_314 . V_318 = - V_318 ;
F_134 ( & T_4 ) ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_26 += F_241 ( V_2 , & V_314 ) ;
F_135 ( & T_4 ) ;
return V_26 ;
}
static void F_243 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_319 )
{
int V_237 , V_320 = ! ! V_319 , V_214 ;
V_237 = F_40 ( V_5 - 1 , V_51 -> V_184 ) ;
V_214 = V_51 -> V_214 - V_237 + V_320 ;
if ( V_320 )
F_244 ( V_5 - 1 , V_51 -> V_184 ) ;
else
F_245 ( V_5 - 1 , V_51 -> V_184 ) ;
F_192 ( & V_51 -> V_2 , V_214 ) ;
F_152 ( & V_51 -> V_2 ) ;
}
static int F_246 ( struct V_109 * V_1 , int V_321 , int V_322 ,
char T_7 * V_323 , unsigned int V_324 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_302 = 0 ;
int V_86 ;
if ( V_321 != V_325 )
return - V_326 ;
if ( V_322 != V_327 && V_322 != V_328 &&
V_324 >= sizeof( int ) &&
F_247 ( V_302 , ( unsigned int T_7 * ) V_323 ) )
return - V_329 ;
switch ( V_322 ) {
case V_330 :
if ( V_302 )
V_51 -> V_3 |= V_331 ;
else
V_51 -> V_3 &= ~ V_331 ;
V_86 = 0 ;
break;
case V_332 :
case V_333 : {
if ( ! F_191 ( V_1 , V_263 ) )
return - V_264 ;
V_86 = F_194 ( V_2 ) ;
if ( V_86 )
return V_86 ;
if ( ! V_302 || V_302 - 1 >= V_51 -> V_208 )
return - V_17 ;
if ( V_322 == V_332 && V_51 -> V_232 ) {
V_86 = V_51 -> V_232 ( V_302 ) ;
if ( V_86 )
return V_86 ;
}
F_122 () ;
F_243 ( V_51 , V_302 ,
V_322 == V_332 ) ;
F_131 () ;
if ( V_322 == V_333 && V_51 -> V_233 )
V_51 -> V_233 ( V_302 ) ;
V_86 = 0 ;
break;
}
case V_334 :
if ( V_302 )
V_51 -> V_3 |= V_306 ;
else
V_51 -> V_3 &= ~ V_306 ;
V_86 = 0 ;
break;
case V_335 :
if ( V_302 ) {
V_51 -> V_3 |= V_52 ;
F_39 ( V_53 , & V_51 -> V_54 ) ;
F_41 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_86 = 0 ;
break;
#ifdef F_110
case V_327 :
case V_328 : {
struct V_76 V_77 ;
if ( ! F_248 ( V_249 ) )
return - V_264 ;
if ( V_324 < sizeof( V_77 ) )
return - V_17 ;
if ( F_249 ( & V_77 , V_323 , sizeof( V_77 ) ) )
return - V_329 ;
V_86 = F_56 ( V_2 , & V_77 , false ,
V_322 == V_328 ) ;
break;
}
#endif
default:
V_86 = - V_326 ;
}
return V_86 ;
}
static int F_250 ( struct V_109 * V_1 , int V_321 , int V_322 ,
char T_7 * V_323 , int T_7 * V_324 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_66 , V_302 , V_86 ;
if ( V_321 != V_325 )
return - V_326 ;
if ( F_247 ( V_66 , V_324 ) )
return - V_329 ;
if ( V_66 < 0 )
return - V_17 ;
switch ( V_322 ) {
case V_330 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_302 = V_51 -> V_3 & V_331 ? 1 : 0 ;
if ( F_251 ( V_66 , V_324 ) ||
F_251 ( V_302 , V_323 ) )
return - V_329 ;
V_86 = 0 ;
break;
case V_334 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_302 = V_51 -> V_3 & V_306 ? 1 : 0 ;
if ( F_251 ( V_66 , V_324 ) ||
F_251 ( V_302 , V_323 ) )
return - V_329 ;
V_86 = 0 ;
break;
case V_335 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_302 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_251 ( V_66 , V_324 ) ||
F_251 ( V_302 , V_323 ) )
return - V_329 ;
V_86 = 0 ;
break;
default:
V_86 = - V_326 ;
}
return V_86 ;
}
static void F_252 ( struct V_148 * V_149 , struct V_27 * V_28 )
{
struct V_336 V_314 ;
V_314 . V_5 = F_43 ( V_28 ) . V_151 ;
F_253 ( V_149 , V_325 , V_330 , sizeof( V_314 ) , & V_314 ) ;
}
static int F_254 ( struct V_337 * V_337 , struct V_109 * V_1 ,
struct V_148 * V_149 , T_5 V_66 )
{
struct V_152 * V_153 = F_255 ( V_337 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_201 ( struct V_258 * , V_256 , V_149 -> V_338 ) ;
T_1 V_150 ;
T_1 V_151 ;
struct V_27 * V_28 ;
int V_86 ;
struct V_339 V_164 ;
T_1 V_340 = 0 ;
if ( V_149 -> V_159 & V_341 )
return - V_342 ;
if ( NULL == V_153 -> V_164 )
V_153 -> V_164 = & V_164 ;
V_86 = F_256 ( V_1 , V_149 , V_153 -> V_164 , true ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_149 -> V_343 ) {
V_86 = - V_17 ;
if ( V_256 -> V_261 != V_262 )
goto V_24;
V_150 = V_256 -> V_265 ;
V_151 = F_199 ( V_256 -> V_260 ) ;
V_86 = - V_264 ;
if ( ( V_151 || V_150 ) &&
! F_191 ( V_1 , V_271 ) )
goto V_24;
V_340 |= V_246 ;
} else {
V_150 = V_51 -> V_150 ;
V_151 = V_51 -> V_151 ;
}
if ( ! V_51 -> V_9 ) {
V_86 = F_182 ( V_1 ) ;
if ( V_86 )
goto V_24;
}
if ( F_45 ( V_2 ) &&
V_149 -> V_344 -> V_345 == NULL ) {
V_86 = F_92 ( V_2 , V_149 , V_150 , V_151 ,
V_153 ) ;
goto V_24;
}
V_86 = - V_346 ;
if ( V_66 > V_2 -> V_347 - 32 )
goto V_24;
V_86 = - V_56 ;
V_28 = F_208 ( V_66 , V_151 ) ;
if ( V_28 == NULL )
goto V_24;
F_43 ( V_28 ) . V_9 = V_51 -> V_9 ;
F_43 ( V_28 ) . V_151 = V_151 ;
F_43 ( V_28 ) . V_163 = V_153 -> V_164 -> V_163 ;
F_43 ( V_28 ) . V_3 = V_340 ;
V_86 = - V_329 ;
if ( F_257 ( F_258 ( V_28 , V_66 ) , V_149 -> V_344 , V_66 ) ) {
F_101 ( V_28 ) ;
goto V_24;
}
V_86 = F_100 ( V_2 , V_28 ) ;
if ( V_86 ) {
F_101 ( V_28 ) ;
goto V_24;
}
if ( V_151 ) {
F_36 ( & V_28 -> V_165 ) ;
F_102 ( V_2 , V_28 , V_150 , V_151 , V_70 ) ;
}
V_86 = F_103 ( V_2 , V_28 , V_150 , V_149 -> V_159 & V_160 ) ;
V_24:
F_259 ( V_153 -> V_164 ) ;
return V_86 ;
}
static int F_260 ( struct V_337 * V_337 , struct V_109 * V_1 ,
struct V_148 * V_149 , T_5 V_66 ,
int V_3 )
{
struct V_152 * V_153 = F_255 ( V_337 ) ;
struct V_339 V_164 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_348 = V_3 & V_160 ;
T_5 V_349 ;
struct V_27 * V_28 , * V_350 ;
int V_86 , V_26 ;
if ( V_3 & V_341 )
return - V_342 ;
V_349 = 0 ;
V_28 = F_261 ( V_2 , V_3 , V_348 , & V_86 ) ;
if ( V_28 == NULL )
goto V_24;
V_350 = V_28 ;
#ifdef F_262
if ( F_7 ( F_113 ( V_28 ) -> V_351 ) ) {
if ( V_3 & V_352 )
V_350 = F_113 ( V_28 ) -> V_351 ;
}
#endif
V_51 -> V_353 = F_263 ( V_51 -> V_353 , V_66 ) ;
V_51 -> V_353 = F_264 ( T_5 , V_51 -> V_353 ,
16384 ) ;
V_349 = V_350 -> V_66 ;
if ( V_66 < V_349 ) {
V_149 -> V_159 |= V_354 ;
V_349 = V_66 ;
}
F_265 ( V_350 ) ;
V_86 = F_266 ( V_350 , 0 , V_149 -> V_344 , V_349 ) ;
if ( V_149 -> V_338 ) {
F_201 ( struct V_258 * , V_256 , V_149 -> V_338 ) ;
V_256 -> V_261 = V_262 ;
V_256 -> V_274 = 0 ;
V_256 -> V_265 = F_43 ( V_28 ) . V_9 ;
V_256 -> V_260 = F_3 ( F_43 ( V_28 ) . V_151 ) ;
V_149 -> V_343 = sizeof( * V_256 ) ;
}
if ( V_51 -> V_3 & V_331 )
F_252 ( V_149 , V_28 ) ;
if ( NULL == V_153 -> V_164 ) {
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_153 -> V_164 = & V_164 ;
}
V_153 -> V_164 -> V_163 = * F_267 ( V_28 ) ;
if ( V_3 & V_354 )
V_349 = V_350 -> V_66 ;
F_268 ( V_2 , V_28 ) ;
if ( V_51 -> V_138 &&
F_57 ( & V_2 -> V_178 ) <= V_2 -> V_287 / 2 ) {
V_26 = F_87 ( V_2 ) ;
if ( V_26 ) {
V_2 -> V_55 = - V_26 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_269 ( V_1 , V_149 , V_153 -> V_164 , V_3 ) ;
V_24:
F_37 ( V_2 ) ;
return V_86 ? : V_349 ;
}
static void F_270 ( struct V_1 * V_2 )
{
F_271 () ;
}
struct V_1 *
F_272 ( struct V_190 * V_190 , int V_355 , struct V_21 * V_21 ,
struct V_356 * V_357 )
{
struct V_109 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_207 * V_207 = NULL ;
struct V_215 * V_216 = V_357 ? V_357 -> V_216 : NULL ;
unsigned int V_184 ;
F_179 ( ! V_192 ) ;
if ( V_355 < 0 || V_355 >= V_228 )
return NULL ;
if ( F_273 ( V_219 , V_226 , V_355 , & V_1 ) )
return NULL ;
if ( F_161 ( & V_358 , V_1 , V_216 , V_355 ) < 0 )
goto V_359;
V_2 = V_1 -> V_2 ;
F_274 ( V_2 , V_190 ) ;
if ( ! V_357 || V_357 -> V_184 < 32 )
V_184 = 32 ;
else
V_184 = V_357 -> V_184 ;
V_207 = F_144 ( sizeof( * V_207 ) + F_196 ( V_184 ) , V_70 ) ;
if ( ! V_207 )
goto V_360;
V_2 -> V_290 = F_270 ;
if ( V_357 && V_357 -> V_361 )
F_2 ( V_2 ) -> V_293 = V_357 -> V_361 ;
if ( F_156 ( V_2 , V_190 , 0 ) )
goto V_360;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_122 () ;
if ( ! V_192 [ V_355 ] . V_230 ) {
V_192 [ V_355 ] . V_184 = V_184 ;
F_275 ( V_192 [ V_355 ] . V_207 , V_207 ) ;
V_192 [ V_355 ] . V_216 = V_216 ;
V_192 [ V_355 ] . V_21 = V_21 ;
if ( V_357 ) {
V_192 [ V_355 ] . F_167 = V_357 -> F_167 ;
V_192 [ V_355 ] . V_3 = V_357 -> V_3 ;
if ( V_357 -> V_193 )
V_192 [ V_355 ] . V_193 = V_357 -> V_193 ;
}
V_192 [ V_355 ] . V_230 = 1 ;
} else {
F_50 ( V_207 ) ;
V_192 [ V_355 ] . V_230 ++ ;
}
F_131 () ;
return V_2 ;
V_360:
F_50 ( V_207 ) ;
F_276 ( V_2 ) ;
return NULL ;
V_359:
F_277 ( V_1 ) ;
return NULL ;
}
void
F_276 ( struct V_1 * V_2 )
{
F_278 ( V_2 ) ;
}
int F_279 ( struct V_1 * V_2 , unsigned int V_184 )
{
struct V_207 * V_320 , * V_237 ;
struct V_191 * V_206 = & V_192 [ V_2 -> V_30 ] ;
if ( V_184 < 32 )
V_184 = 32 ;
if ( F_196 ( V_206 -> V_184 ) < F_196 ( V_184 ) ) {
V_320 = F_144 ( sizeof( * V_320 ) + F_196 ( V_184 ) , V_42 ) ;
if ( ! V_320 )
return - V_41 ;
V_237 = F_153 ( V_206 -> V_207 ) ;
memcpy ( V_320 -> V_209 , V_237 -> V_209 , F_196 ( V_206 -> V_184 ) ) ;
F_275 ( V_206 -> V_207 , V_320 ) ;
F_181 ( V_237 , V_238 ) ;
}
V_206 -> V_184 = V_184 ;
return 0 ;
}
int F_280 ( struct V_1 * V_2 , unsigned int V_184 )
{
int V_86 ;
F_122 () ;
V_86 = F_279 ( V_2 , V_184 ) ;
F_131 () ;
return V_86 ;
}
void F_281 ( struct V_1 * V_362 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_191 * V_206 = & V_192 [ V_362 -> V_30 ] ;
F_155 (sk, &tbl->mc_list)
F_243 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_363 *
F_282 ( struct V_27 * V_28 , T_1 V_9 , T_1 V_364 , int type , int V_66 , int V_3 )
{
struct V_363 * V_365 ;
int V_112 = F_283 ( V_66 ) ;
V_365 = (struct V_363 * ) F_258 ( V_28 , F_284 ( V_112 ) ) ;
V_365 -> V_366 = type ;
V_365 -> V_367 = V_112 ;
V_365 -> V_368 = V_3 ;
V_365 -> V_369 = V_9 ;
V_365 -> V_370 = V_364 ;
if ( ! F_285 ( V_112 ) || F_284 ( V_112 ) - V_112 != 0 )
memset ( F_286 ( V_365 ) + V_66 , 0 , F_284 ( V_112 ) - V_112 ) ;
return V_365 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_371 * V_179 ;
struct V_27 * V_28 = NULL ;
struct V_363 * V_365 ;
int V_66 , V_86 = - V_56 ;
int V_372 ;
F_60 ( V_51 -> V_216 ) ;
if ( ! V_51 -> V_138 ) {
V_86 = - V_17 ;
goto V_373;
}
V_179 = & V_51 -> V_179 ;
V_372 = F_287 ( int , V_179 -> V_374 , V_283 ) ;
if ( ! F_44 ( V_2 ) &&
F_57 ( & V_2 -> V_178 ) >= V_2 -> V_287 )
goto V_373;
if ( V_372 < V_51 -> V_353 ) {
V_28 = F_231 ( V_2 ,
V_51 -> V_353 ,
V_51 -> V_9 ,
V_70 |
V_73 |
V_74 ) ;
if ( V_28 )
F_288 ( V_28 , F_289 ( V_28 ) -
V_51 -> V_353 ) ;
}
if ( ! V_28 )
V_28 = F_231 ( V_2 , V_372 , V_51 -> V_9 ,
V_70 ) ;
if ( ! V_28 )
goto V_373;
F_115 ( V_28 , V_2 ) ;
V_66 = V_179 -> V_375 ( V_28 , V_179 ) ;
if ( V_66 > 0 ) {
F_66 ( V_51 -> V_216 ) ;
if ( F_230 ( V_2 , V_28 ) )
F_101 ( V_28 ) ;
else
F_217 ( V_2 , V_28 ) ;
return 0 ;
}
V_365 = F_290 ( V_28 , V_179 , V_376 , sizeof( V_66 ) , V_377 ) ;
if ( ! V_365 )
goto V_373;
F_291 ( V_179 , V_365 ) ;
memcpy ( F_286 ( V_365 ) , & V_66 , sizeof( V_66 ) ) ;
if ( F_230 ( V_2 , V_28 ) )
F_101 ( V_28 ) ;
else
F_217 ( V_2 , V_28 ) ;
if ( V_179 -> V_180 )
V_179 -> V_180 ( V_179 ) ;
V_51 -> V_138 = false ;
F_66 ( V_51 -> V_216 ) ;
F_16 ( V_179 -> V_21 ) ;
F_223 ( V_179 -> V_28 ) ;
return 0 ;
V_373:
F_66 ( V_51 -> V_216 ) ;
F_101 ( V_28 ) ;
return V_86 ;
}
int F_292 ( struct V_1 * V_275 , struct V_27 * V_28 ,
const struct V_363 * V_365 ,
struct V_378 * V_379 )
{
struct V_371 * V_179 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_26 ;
if ( F_42 ( V_28 ) ) {
V_28 = F_293 ( V_28 , V_70 ) ;
if ( V_28 == NULL )
return - V_56 ;
} else
F_36 ( & V_28 -> V_165 ) ;
V_2 = F_141 ( F_140 ( V_275 ) , V_275 -> V_30 , F_43 ( V_28 ) . V_9 ) ;
if ( V_2 == NULL ) {
V_26 = - V_276 ;
goto V_380;
}
V_51 = F_2 ( V_2 ) ;
F_60 ( V_51 -> V_216 ) ;
if ( V_51 -> V_138 ) {
V_26 = - V_89 ;
goto V_381;
}
if ( ! F_171 ( V_379 -> V_21 ) ) {
V_26 = - V_229 ;
goto V_381;
}
V_179 = & V_51 -> V_179 ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_375 = V_379 -> V_375 ;
V_179 -> V_180 = V_379 -> V_180 ;
V_179 -> V_365 = V_365 ;
V_179 -> V_143 = V_379 -> V_143 ;
V_179 -> V_21 = V_379 -> V_21 ;
V_179 -> V_374 = V_379 -> V_374 ;
V_179 -> V_28 = V_28 ;
V_51 -> V_138 = true ;
F_66 ( V_51 -> V_216 ) ;
V_26 = F_87 ( V_2 ) ;
F_111 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return - V_382 ;
V_381:
F_111 ( V_2 ) ;
F_66 ( V_51 -> V_216 ) ;
V_380:
F_101 ( V_28 ) ;
return V_26 ;
}
void F_294 ( struct V_27 * V_383 , struct V_363 * V_365 , int V_86 )
{
struct V_27 * V_28 ;
struct V_363 * V_384 ;
struct V_385 * V_386 ;
T_5 V_387 = sizeof( * V_386 ) ;
if ( V_86 )
V_387 += V_367 ( V_365 ) ;
V_28 = F_231 ( V_383 -> V_2 , F_295 ( V_387 ) ,
F_43 ( V_383 ) . V_9 , V_70 ) ;
if ( ! V_28 ) {
struct V_1 * V_2 ;
V_2 = F_141 ( F_140 ( V_383 -> V_2 ) ,
V_383 -> V_2 -> V_30 ,
F_43 ( V_383 ) . V_9 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_111 ( V_2 ) ;
}
return;
}
V_384 = F_282 ( V_28 , F_43 ( V_383 ) . V_9 , V_365 -> V_370 ,
V_388 , V_387 , 0 ) ;
V_386 = F_286 ( V_384 ) ;
V_386 -> error = V_86 ;
memcpy ( & V_386 -> V_149 , V_365 , V_86 ? V_365 -> V_367 : sizeof( * V_365 ) ) ;
F_103 ( V_383 -> V_2 , V_28 , F_43 ( V_383 ) . V_9 , V_160 ) ;
}
int F_296 ( struct V_27 * V_28 , int (* V_179)( struct V_27 * ,
struct V_363 * ) )
{
struct V_363 * V_365 ;
int V_86 ;
while ( V_28 -> V_66 >= F_295 ( 0 ) ) {
int V_389 ;
V_365 = F_297 ( V_28 ) ;
V_86 = 0 ;
if ( V_365 -> V_367 < V_390 || V_28 -> V_66 < V_365 -> V_367 )
return 0 ;
if ( ! ( V_365 -> V_368 & V_391 ) )
goto V_392;
if ( V_365 -> V_366 < V_393 )
goto V_392;
V_86 = V_179 ( V_28 , V_365 ) ;
if ( V_86 == - V_382 )
goto V_394;
V_392:
if ( V_365 -> V_368 & V_395 || V_86 )
F_294 ( V_28 , V_365 , V_86 ) ;
V_394:
V_389 = F_284 ( V_365 -> V_367 ) ;
if ( V_389 > V_28 -> V_66 )
V_389 = V_28 -> V_66 ;
F_298 ( V_28 , V_389 ) ;
}
return 0 ;
}
int F_299 ( struct V_1 * V_2 , struct V_27 * V_28 , T_1 V_9 ,
unsigned int V_5 , int V_396 , T_2 V_3 )
{
int V_86 = 0 ;
if ( V_5 ) {
int V_397 = 0 ;
if ( V_396 ) {
F_36 ( & V_28 -> V_165 ) ;
V_397 = V_9 ;
}
V_86 = F_300 ( V_2 , V_28 , V_397 , V_5 , V_3 ) ;
}
if ( V_396 ) {
int V_298 ;
V_298 = F_301 ( V_2 , V_28 , V_9 ) ;
if ( ! V_86 || V_86 == - V_316 )
V_86 = V_298 ;
}
return V_86 ;
}
static struct V_1 * F_302 ( struct V_398 * V_364 , T_8 V_131 )
{
struct V_399 * V_400 = V_364 -> V_401 ;
int V_67 , V_402 ;
struct V_1 * V_403 ;
T_8 V_404 = 0 ;
for ( V_67 = 0 ; V_67 < V_228 ; V_67 ++ ) {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
for ( V_402 = 0 ; V_402 <= V_8 -> V_12 ; V_402 ++ ) {
F_142 (s, &hash->table[j]) {
if ( F_140 ( V_403 ) != F_303 ( V_364 ) )
continue;
if ( V_404 == V_131 ) {
V_400 -> V_405 = V_67 ;
V_400 -> V_406 = V_402 ;
return V_403 ;
}
++ V_404 ;
}
}
}
return NULL ;
}
static void * F_304 ( struct V_398 * V_364 , T_8 * V_131 )
__acquires( T_4 )
{
F_134 ( & T_4 ) ;
return * V_131 ? F_302 ( V_364 , * V_131 - 1 ) : V_407 ;
}
static void * F_305 ( struct V_398 * V_364 , void * V_408 , T_8 * V_131 )
{
struct V_1 * V_403 ;
struct V_399 * V_400 ;
struct V_190 * V_190 ;
int V_67 , V_402 ;
++ * V_131 ;
if ( V_408 == V_407 )
return F_302 ( V_364 , 0 ) ;
V_190 = F_303 ( V_364 ) ;
V_400 = V_364 -> V_401 ;
V_403 = V_408 ;
do {
V_403 = F_306 ( V_403 ) ;
} while ( V_403 && ! V_192 [ V_403 -> V_30 ] . V_193 ( V_190 , V_403 ) );
if ( V_403 )
return V_403 ;
V_67 = V_400 -> V_405 ;
V_402 = V_400 -> V_406 + 1 ;
do {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
for (; V_402 <= V_8 -> V_12 ; V_402 ++ ) {
V_403 = F_307 ( & V_8 -> V_10 [ V_402 ] ) ;
while ( V_403 && ! V_192 [ V_403 -> V_30 ] . V_193 ( V_190 , V_403 ) )
V_403 = F_306 ( V_403 ) ;
if ( V_403 ) {
V_400 -> V_405 = V_67 ;
V_400 -> V_406 = V_402 ;
return V_403 ;
}
}
V_402 = 0 ;
} while ( ++ V_67 < V_228 );
return NULL ;
}
static void F_308 ( struct V_398 * V_364 , void * V_408 )
__releases( T_4 )
{
F_135 ( & T_4 ) ;
}
static int F_309 ( struct V_398 * V_364 , void * V_408 )
{
if ( V_408 == V_407 ) {
F_310 ( V_364 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_403 = V_408 ;
struct V_50 * V_51 = F_2 ( V_403 ) ;
F_311 ( V_364 , L_6 ,
V_403 ,
V_403 -> V_30 ,
V_51 -> V_9 ,
V_51 -> V_184 ? ( T_1 ) V_51 -> V_184 [ 0 ] : 0 ,
F_312 ( V_403 ) ,
F_313 ( V_403 ) ,
V_51 -> V_138 ,
F_57 ( & V_403 -> V_409 ) ,
F_57 ( & V_403 -> V_58 ) ,
F_314 ( V_403 )
) ;
}
return 0 ;
}
static int F_315 ( struct V_278 * V_278 , struct V_107 * V_107 )
{
return F_316 ( V_278 , V_107 , & V_410 ,
sizeof( struct V_399 ) ) ;
}
int F_317 ( struct V_411 * V_412 )
{
return F_318 ( & V_235 , V_412 ) ;
}
int F_319 ( struct V_411 * V_412 )
{
return F_320 ( & V_235 , V_412 ) ;
}
static int T_9 F_321 ( struct V_190 * V_190 )
{
#ifdef F_322
if ( ! F_323 ( L_7 , 0 , V_190 -> V_413 , & V_414 ) )
return - V_41 ;
#endif
return 0 ;
}
static void T_10 F_324 ( struct V_190 * V_190 )
{
#ifdef F_322
F_325 ( L_7 , V_190 -> V_413 ) ;
#endif
}
static void T_11 F_326 ( void )
{
struct V_207 * V_207 ;
int V_184 = 32 ;
V_207 = F_144 ( sizeof( * V_207 ) + F_196 ( V_184 ) , V_70 ) ;
if ( ! V_207 )
F_327 ( L_8 ) ;
F_122 () ;
V_192 [ V_32 ] . V_184 = V_184 ;
F_275 ( V_192 [ V_32 ] . V_207 , V_207 ) ;
V_192 [ V_32 ] . V_21 = V_415 ;
V_192 [ V_32 ] . V_230 = 1 ;
V_192 [ V_32 ] . V_3 = V_271 ;
F_131 () ;
}
static int T_11 F_328 ( void )
{
int V_67 ;
unsigned long V_416 ;
unsigned int V_65 ;
int V_86 = F_329 ( & V_220 , 0 ) ;
if ( V_86 != 0 )
goto V_24;
F_330 ( sizeof( struct V_241 ) > F_331 ( struct V_27 , V_179 ) ) ;
V_192 = F_55 ( V_228 , sizeof( * V_192 ) , V_70 ) ;
if ( ! V_192 )
goto F_327;
if ( V_417 >= ( 128 * 1024 ) )
V_416 = V_417 >> ( 21 - V_418 ) ;
else
V_416 = V_417 >> ( 23 - V_418 ) ;
V_65 = F_332 ( V_416 ) - 1 + V_418 ;
V_416 = ( 1UL << V_65 ) / sizeof( struct V_6 ) ;
V_65 = F_332 ( F_333 ( V_416 , ( unsigned long ) V_213 ) ) - 1 ;
for ( V_67 = 0 ; V_67 < V_228 ; V_67 ++ ) {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
V_8 -> V_10 = F_143 ( 1 * sizeof( * V_8 -> V_10 ) ) ;
if ( ! V_8 -> V_10 ) {
while ( V_67 -- > 0 )
F_145 ( V_192 [ V_67 ] . V_8 . V_10 ,
1 * sizeof( * V_8 -> V_10 ) ) ;
F_50 ( V_192 ) ;
goto F_327;
}
V_8 -> V_199 = V_65 ;
V_8 -> V_196 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_201 = V_202 ;
V_192 [ V_67 ] . V_193 = F_138 ;
}
F_334 ( & V_20 ) ;
F_326 () ;
F_335 ( & V_419 ) ;
F_336 ( & V_420 ) ;
F_337 () ;
V_24:
return V_86 ;
F_327:
F_327 ( L_9 ) ;
}
