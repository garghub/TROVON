static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
int F_4 ( struct V_6 * V_7 )
{
if ( F_5 ( V_7 -> V_8 -> type != V_9 ) )
return - V_10 ;
F_6 ( & V_11 ) ;
F_7 ( & V_7 -> V_12 , & V_13 ) ;
F_8 ( & V_11 ) ;
F_9 ( V_7 -> V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
bool V_15 = false ;
struct V_6 * V_16 ;
F_6 ( & V_11 ) ;
F_11 (tmp, &netlink_tap_all, list) {
if ( V_7 == V_16 ) {
F_12 ( & V_7 -> V_12 ) ;
V_15 = true ;
goto V_17;
}
}
F_13 ( L_1 , V_7 ) ;
V_17:
F_8 ( & V_11 ) ;
if ( V_15 )
F_14 ( V_7 -> V_14 ) ;
return V_15 ? 0 : - V_18 ;
}
int F_15 ( struct V_6 * V_7 )
{
int V_19 ;
V_19 = F_10 ( V_7 ) ;
F_16 () ;
return V_19 ;
}
static bool F_17 ( const struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return true ;
}
return false ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_31 * V_8 )
{
struct V_20 * V_32 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_19 = - V_33 ;
F_19 ( V_8 ) ;
V_32 = F_20 ( V_21 , V_34 ) ;
if ( V_32 ) {
V_32 -> V_8 = V_8 ;
V_32 -> V_35 = F_21 ( ( V_36 ) V_2 -> V_22 ) ;
V_32 -> V_37 = F_1 ( V_2 ) ?
V_38 : V_39 ;
F_22 ( V_32 ) ;
V_19 = F_23 ( V_32 ) ;
if ( F_5 ( V_19 > 0 ) )
V_19 = F_24 ( V_19 ) ;
}
F_25 ( V_8 ) ;
return V_19 ;
}
static void F_26 ( struct V_20 * V_21 )
{
int V_19 ;
struct V_6 * V_16 ;
if ( ! F_17 ( V_21 ) )
return;
F_27 (tmp, &netlink_tap_all, list) {
V_19 = F_18 ( V_21 , V_16 -> V_8 ) ;
if ( F_5 ( V_19 ) )
break;
}
}
static void F_28 ( struct V_20 * V_21 )
{
F_29 () ;
if ( F_5 ( ! F_30 ( & V_13 ) ) )
F_26 ( V_21 ) ;
F_31 () ;
}
static void F_32 ( struct V_1 * V_40 , struct V_1 * V_41 ,
struct V_20 * V_21 )
{
if ( ! ( F_1 ( V_40 ) && F_1 ( V_41 ) ) )
F_28 ( V_21 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( ! ( V_43 -> V_3 & V_44 ) ) {
if ( ! F_34 ( V_45 ,
& F_2 ( V_2 ) -> V_46 ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 ( V_2 ) ;
}
}
F_35 ( & V_2 -> V_50 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( F_37 ( & V_2 -> V_51 ) )
F_38 ( V_45 , & V_43 -> V_46 ) ;
if ( ! F_39 ( V_45 , & V_43 -> V_46 ) )
F_40 ( & V_43 -> V_52 ) ;
}
static bool F_41 ( const struct V_20 * V_21 )
{
return F_42 ( V_21 ) . V_3 & V_53 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_54 . V_55 != NULL ;
}
static bool F_44 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_56 . V_55 != NULL ;
}
static void F_45 ( void * * V_55 , unsigned int V_57 , unsigned int V_58 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
if ( V_55 [ V_59 ] != NULL ) {
if ( F_46 ( V_55 [ V_59 ] ) )
F_47 ( V_55 [ V_59 ] ) ;
else
F_48 ( ( unsigned long ) V_55 [ V_59 ] , V_57 ) ;
}
}
F_49 ( V_55 ) ;
}
static void * F_50 ( unsigned long V_57 )
{
void * V_60 ;
T_2 V_61 = V_62 | V_63 | V_64 |
V_65 | V_66 ;
V_60 = ( void * ) F_51 ( V_61 , V_57 ) ;
if ( V_60 != NULL )
return V_60 ;
V_60 = F_52 ( ( 1 << V_57 ) * V_67 ) ;
if ( V_60 != NULL )
return V_60 ;
V_61 &= ~ V_66 ;
return ( void * ) F_51 ( V_61 , V_57 ) ;
}
static void * * F_53 ( struct V_42 * V_43 ,
struct V_68 * V_69 , unsigned int V_57 )
{
unsigned int V_70 = V_69 -> V_71 ;
unsigned int V_59 ;
void * * V_55 ;
V_55 = F_54 ( V_70 , sizeof( void * ) , V_62 ) ;
if ( V_55 == NULL )
return NULL ;
for ( V_59 = 0 ; V_59 < V_70 ; V_59 ++ ) {
V_55 [ V_59 ] = F_50 ( V_57 ) ;
if ( V_55 [ V_59 ] == NULL )
goto V_72;
}
return V_55 ;
V_72:
F_45 ( V_55 , V_57 , V_70 ) ;
return NULL ;
}
static void
F_55 ( struct V_1 * V_2 , struct V_68 * V_69 , bool V_56 , void * * V_55 ,
unsigned int V_57 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
V_74 = V_56 ? & V_2 -> V_77 : & V_2 -> V_51 ;
V_76 = V_56 ? & V_43 -> V_56 : & V_43 -> V_54 ;
F_56 ( & V_74 -> V_78 ) ;
V_76 -> V_79 = V_69 -> V_80 - 1 ;
V_76 -> V_81 = 0 ;
V_76 -> V_82 = V_69 -> V_83 ;
V_76 -> V_84 = V_69 -> V_85 / V_67 ;
F_57 ( V_76 -> V_86 , V_69 -> V_71 ) ;
F_57 ( V_76 -> V_87 , V_57 ) ;
F_57 ( V_76 -> V_55 , V_55 ) ;
F_58 ( V_74 ) ;
F_59 ( & V_74 -> V_78 ) ;
F_60 ( F_61 ( & V_43 -> V_88 ) ) ;
if ( V_55 )
F_45 ( V_55 , V_57 , V_69 -> V_71 ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_68 * V_69 ,
bool V_56 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
void * * V_55 = NULL ;
unsigned int V_57 = 0 ;
V_76 = V_56 ? & V_43 -> V_56 : & V_43 -> V_54 ;
if ( F_61 ( & V_43 -> V_88 ) )
return - V_89 ;
if ( F_61 ( & V_76 -> V_90 ) )
return - V_89 ;
if ( V_69 -> V_71 ) {
if ( V_76 -> V_55 != NULL )
return - V_89 ;
if ( ( int ) V_69 -> V_85 <= 0 )
return - V_10 ;
if ( ! F_63 ( V_69 -> V_85 ) )
return - V_10 ;
if ( V_69 -> V_83 < V_91 )
return - V_10 ;
if ( ! F_64 ( V_69 -> V_83 , V_92 ) )
return - V_10 ;
V_76 -> V_93 = V_69 -> V_85 /
V_69 -> V_83 ;
if ( V_76 -> V_93 == 0 )
return - V_10 ;
if ( V_76 -> V_93 * V_69 -> V_71 !=
V_69 -> V_80 )
return - V_10 ;
V_57 = F_65 ( V_69 -> V_85 ) ;
V_55 = F_53 ( V_43 , V_69 , V_57 ) ;
if ( V_55 == NULL )
return - V_33 ;
} else {
if ( V_69 -> V_80 )
return - V_10 ;
}
F_66 ( & V_43 -> V_94 ) ;
if ( F_61 ( & V_43 -> V_88 ) == 0 ) {
F_55 ( V_2 , V_69 , V_56 , V_55 , V_57 ) ;
F_67 ( & V_43 -> V_94 ) ;
return 0 ;
}
F_67 ( & V_43 -> V_94 ) ;
if ( V_55 )
F_45 ( V_55 , V_57 , V_69 -> V_71 ) ;
return - V_89 ;
}
static void F_68 ( struct V_95 * V_96 )
{
struct V_97 * V_97 = V_96 -> V_98 ;
struct V_99 * V_1 = V_97 -> V_100 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_35 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static void F_69 ( struct V_95 * V_96 )
{
struct V_97 * V_97 = V_96 -> V_98 ;
struct V_99 * V_1 = V_97 -> V_100 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_70 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static int F_71 ( struct V_97 * V_97 , struct V_99 * V_1 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
unsigned long V_101 , V_102 , V_103 ;
unsigned int V_59 ;
int V_104 = - V_10 ;
if ( V_96 -> V_105 )
return - V_10 ;
F_66 ( & V_43 -> V_94 ) ;
V_103 = 0 ;
for ( V_76 = & V_43 -> V_54 ; V_76 <= & V_43 -> V_56 ; V_76 ++ ) {
if ( V_76 -> V_55 == NULL )
continue;
V_103 += V_76 -> V_86 * V_76 -> V_84 * V_67 ;
}
if ( V_103 == 0 )
goto V_17;
V_102 = V_96 -> V_106 - V_96 -> V_107 ;
if ( V_102 != V_103 )
goto V_17;
V_101 = V_96 -> V_107 ;
for ( V_76 = & V_43 -> V_54 ; V_76 <= & V_43 -> V_56 ; V_76 ++ ) {
if ( V_76 -> V_55 == NULL )
continue;
for ( V_59 = 0 ; V_59 < V_76 -> V_86 ; V_59 ++ ) {
struct V_108 * V_108 ;
void * V_109 = V_76 -> V_55 [ V_59 ] ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < V_76 -> V_84 ; V_110 ++ ) {
V_108 = F_72 ( V_109 ) ;
V_104 = F_73 ( V_96 , V_101 , V_108 ) ;
if ( V_104 < 0 )
goto V_17;
V_101 += V_67 ;
V_109 += V_67 ;
}
}
}
F_35 ( & V_43 -> V_88 ) ;
V_96 -> V_111 = & V_112 ;
V_104 = 0 ;
V_17:
F_67 ( & V_43 -> V_94 ) ;
return V_104 ;
}
static void F_74 ( const struct V_113 * V_114 , unsigned int V_115 )
{
#if V_116 == 1
struct V_108 * V_117 , * V_118 ;
V_117 = F_72 ( V_114 + V_67 ) ;
V_118 = F_72 ( ( void * ) V_114 + V_91 + V_115 - 1 ) ;
while ( V_117 <= V_118 ) {
F_75 ( V_117 ) ;
V_117 ++ ;
}
#endif
}
static enum V_119 F_76 ( const struct V_113 * V_114 )
{
F_77 () ;
F_75 ( F_72 ( V_114 ) ) ;
return V_114 -> V_120 ;
}
static void F_78 ( struct V_113 * V_114 ,
enum V_119 V_121 )
{
F_79 () ;
V_114 -> V_120 = V_121 ;
F_75 ( F_72 ( V_114 ) ) ;
}
static struct V_113 *
F_80 ( const struct V_75 * V_76 , unsigned int V_122 )
{
unsigned int V_123 , V_124 ;
V_123 = V_122 / V_76 -> V_93 ;
V_124 = V_122 % V_76 -> V_93 ;
return V_76 -> V_55 [ V_123 ] + ( V_124 * V_76 -> V_82 ) ;
}
static struct V_113 *
F_81 ( const struct V_75 * V_76 , unsigned int V_122 ,
enum V_119 V_121 )
{
struct V_113 * V_114 ;
V_114 = F_80 ( V_76 , V_122 ) ;
if ( F_76 ( V_114 ) != V_121 )
return NULL ;
return V_114 ;
}
static struct V_113 *
F_82 ( const struct V_75 * V_76 ,
enum V_119 V_121 )
{
return F_81 ( V_76 , V_76 -> V_81 , V_121 ) ;
}
static struct V_113 *
F_83 ( const struct V_75 * V_76 ,
enum V_119 V_121 )
{
unsigned int V_125 ;
V_125 = V_76 -> V_81 ? V_76 -> V_81 - 1 : V_76 -> V_79 ;
return F_81 ( V_76 , V_125 , V_121 ) ;
}
static void F_84 ( struct V_75 * V_76 )
{
V_76 -> V_81 = V_76 -> V_81 != V_76 -> V_79 ? V_76 -> V_81 + 1 : 0 ;
}
static void F_85 ( struct V_75 * V_76 )
{
unsigned int V_81 = V_76 -> V_81 , V_122 = V_81 ;
const struct V_113 * V_114 ;
do {
V_114 = F_80 ( V_76 , V_122 ) ;
if ( V_114 -> V_120 == V_126 )
break;
if ( V_114 -> V_120 != V_127 )
break;
F_84 ( V_76 ) ;
} while ( V_76 -> V_81 != V_81 );
}
static bool F_86 ( struct V_42 * V_43 )
{
struct V_75 * V_76 = & V_43 -> V_54 ;
struct V_113 * V_114 ;
unsigned int V_128 ;
V_114 = F_82 ( V_76 , V_126 ) ;
if ( V_114 == NULL )
return false ;
V_128 = V_76 -> V_81 + V_76 -> V_79 / 2 ;
if ( V_128 > V_76 -> V_79 )
V_128 -= V_76 -> V_79 ;
V_114 = F_80 ( V_76 , V_128 ) ;
return V_114 -> V_120 == V_126 ;
}
static unsigned int F_87 ( struct V_97 * V_97 , struct V_99 * V_1 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_129 ;
int V_104 ;
if ( V_43 -> V_54 . V_55 != NULL ) {
while ( V_43 -> V_130 && F_86 ( V_43 ) ) {
V_104 = F_88 ( V_2 ) ;
if ( V_104 < 0 ) {
V_2 -> V_47 = - V_104 ;
V_2 -> V_49 ( V_2 ) ;
break;
}
}
F_36 ( V_2 ) ;
}
V_129 = F_89 ( V_97 , V_1 , V_52 ) ;
F_56 ( & V_2 -> V_51 . V_78 ) ;
if ( V_43 -> V_54 . V_55 ) {
F_85 ( & V_43 -> V_54 ) ;
if ( ! F_83 ( & V_43 -> V_54 , V_126 ) )
V_129 |= V_131 | V_132 ;
}
F_59 ( & V_2 -> V_51 . V_78 ) ;
F_56 ( & V_2 -> V_77 . V_78 ) ;
if ( V_43 -> V_56 . V_55 ) {
if ( F_82 ( & V_43 -> V_56 , V_126 ) )
V_129 |= V_133 | V_134 ;
}
F_59 ( & V_2 -> V_77 . V_78 ) ;
return V_129 ;
}
static struct V_113 * F_90 ( struct V_20 * V_21 )
{
return (struct V_113 * ) ( V_21 -> V_81 - V_91 ) ;
}
static void F_91 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_113 * V_114 )
{
unsigned int V_102 ;
void * V_135 ;
V_102 = V_76 -> V_82 - V_91 ;
V_135 = ( void * ) V_114 + V_91 ;
V_21 -> V_81 = V_135 ;
V_21 -> V_135 = V_135 ;
F_92 ( V_21 ) ;
V_21 -> V_136 = V_21 -> V_137 + V_102 ;
V_21 -> V_58 = 0 ;
V_21 -> V_138 = V_139 ;
F_42 ( V_21 ) . V_3 |= V_53 ;
F_42 ( V_21 ) . V_2 = V_2 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_140 * V_141 ,
T_1 V_142 , T_1 V_143 ,
struct V_144 * V_145 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
struct V_113 * V_114 ;
struct V_20 * V_21 ;
unsigned int V_146 ;
int V_104 = 0 , V_58 = 0 ;
F_66 ( & V_43 -> V_94 ) ;
V_76 = & V_43 -> V_56 ;
V_146 = V_76 -> V_82 - V_91 ;
do {
unsigned int V_115 ;
V_114 = F_82 ( V_76 , V_147 ) ;
if ( V_114 == NULL ) {
if ( ! ( V_141 -> V_148 & V_149 ) &&
F_61 ( & V_43 -> V_56 . V_90 ) )
F_94 () ;
continue;
}
V_115 = F_95 ( V_114 -> V_115 ) ;
if ( V_115 > V_146 ) {
V_104 = - V_10 ;
goto V_17;
}
F_74 ( V_114 , V_115 ) ;
V_21 = F_96 ( V_115 , V_62 ) ;
if ( V_21 == NULL ) {
V_104 = - V_48 ;
goto V_17;
}
F_97 ( V_21 , V_115 ) ;
memcpy ( V_21 -> V_135 , ( void * ) V_114 + V_91 , V_115 ) ;
F_78 ( V_114 , V_126 ) ;
F_84 ( V_76 ) ;
F_42 ( V_21 ) . V_150 = V_43 -> V_150 ;
F_42 ( V_21 ) . V_143 = V_143 ;
F_42 ( V_21 ) . V_151 = V_145 -> V_151 ;
V_104 = F_98 ( V_2 , V_21 ) ;
if ( V_104 ) {
F_99 ( V_21 ) ;
goto V_17;
}
if ( F_5 ( V_143 ) ) {
F_35 ( & V_21 -> V_152 ) ;
F_100 ( V_2 , V_21 , V_142 , V_143 ,
V_62 ) ;
}
V_104 = F_101 ( V_2 , V_21 , V_142 ,
V_141 -> V_148 & V_149 ) ;
if ( V_104 < 0 )
goto V_17;
V_58 += V_104 ;
} while ( V_114 != NULL ||
( ! ( V_141 -> V_148 & V_149 ) &&
F_61 ( & V_43 -> V_56 . V_90 ) ) );
if ( V_58 > 0 )
V_104 = V_58 ;
V_17:
F_67 ( & V_43 -> V_94 ) ;
return V_104 ;
}
static void F_102 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_113 * V_114 ;
V_114 = F_90 ( V_21 ) ;
V_114 -> V_115 = V_21 -> V_58 ;
V_114 -> V_153 = F_42 ( V_21 ) . V_143 ;
V_114 -> V_154 = F_42 ( V_21 ) . V_151 . V_155 ;
V_114 -> V_156 = F_103 ( F_104 ( V_2 ) , F_42 ( V_21 ) . V_151 . V_157 ) ;
V_114 -> V_158 = F_105 ( F_104 ( V_2 ) , F_42 ( V_21 ) . V_151 . V_159 ) ;
F_74 ( V_114 , V_114 -> V_115 ) ;
F_78 ( V_114 , V_147 ) ;
F_42 ( V_21 ) . V_3 |= V_160 ;
F_99 ( V_21 ) ;
}
static void F_106 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_75 * V_76 = & V_43 -> V_54 ;
struct V_113 * V_114 ;
F_56 ( & V_2 -> V_51 . V_78 ) ;
V_114 = F_82 ( V_76 , V_126 ) ;
if ( V_114 == NULL ) {
F_59 ( & V_2 -> V_51 . V_78 ) ;
F_99 ( V_21 ) ;
F_33 ( V_2 ) ;
return;
}
F_84 ( V_76 ) ;
F_107 ( & V_2 -> V_51 , V_21 ) ;
F_59 ( & V_2 -> V_51 . V_78 ) ;
V_114 -> V_115 = V_21 -> V_58 ;
V_114 -> V_153 = F_42 ( V_21 ) . V_143 ;
V_114 -> V_154 = F_42 ( V_21 ) . V_151 . V_155 ;
V_114 -> V_156 = F_103 ( F_104 ( V_2 ) , F_42 ( V_21 ) . V_151 . V_157 ) ;
V_114 -> V_158 = F_105 ( F_104 ( V_2 ) , F_42 ( V_21 ) . V_151 . V_159 ) ;
F_78 ( V_114 , V_161 ) ;
}
static void V_139 ( struct V_20 * V_21 )
{
#ifdef F_108
struct V_113 * V_114 ;
struct V_75 * V_76 ;
struct V_1 * V_2 ;
if ( F_41 ( V_21 ) ) {
V_114 = F_90 ( V_21 ) ;
V_2 = F_42 ( V_21 ) . V_2 ;
if ( F_42 ( V_21 ) . V_3 & V_162 ) {
F_78 ( V_114 , V_126 ) ;
V_76 = & F_2 ( V_2 ) -> V_56 ;
} else {
if ( ! ( F_42 ( V_21 ) . V_3 & V_160 ) ) {
V_114 -> V_115 = 0 ;
F_78 ( V_114 , V_147 ) ;
}
V_76 = & F_2 ( V_2 ) -> V_54 ;
}
F_60 ( F_61 ( & V_76 -> V_90 ) == 0 ) ;
F_70 ( & V_76 -> V_90 ) ;
F_109 ( V_2 ) ;
V_21 -> V_81 = NULL ;
}
#endif
if ( F_46 ( V_21 -> V_81 ) ) {
if ( ! V_21 -> V_163 ||
! F_110 ( & ( F_111 ( V_21 ) -> V_164 ) ) )
F_47 ( V_21 -> V_81 ) ;
V_21 -> V_81 = NULL ;
}
if ( V_21 -> V_2 != NULL )
F_112 ( V_21 ) ;
}
static void F_113 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
F_60 ( V_21 -> V_2 != NULL ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_138 = V_139 ;
F_114 ( V_21 -> V_165 , & V_2 -> V_166 ) ;
F_115 ( V_2 , V_21 -> V_165 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_130 ) {
if ( V_43 -> V_167 . V_168 )
V_43 -> V_167 . V_168 ( & V_43 -> V_167 ) ;
F_14 ( V_43 -> V_167 . V_14 ) ;
F_99 ( V_43 -> V_167 . V_21 ) ;
}
F_117 ( & V_2 -> V_51 ) ;
#ifdef F_108
if ( 1 ) {
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_54 . V_55 )
F_55 ( V_2 , & V_69 , false , NULL , 0 ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_56 . V_55 )
F_55 ( V_2 , & V_69 , true , NULL , 0 ) ;
}
#endif
if ( ! F_118 ( V_2 , V_169 ) ) {
F_119 ( V_170 L_2 , V_2 ) ;
return;
}
F_60 ( F_61 ( & V_2 -> V_166 ) ) ;
F_60 ( F_61 ( & V_2 -> V_171 ) ) ;
F_60 ( F_2 ( V_2 ) -> V_172 ) ;
}
void F_120 ( void )
__acquires( T_4 )
{
F_121 () ;
F_122 ( & T_4 ) ;
if ( F_61 ( & V_173 ) ) {
F_123 ( V_52 , V_174 ) ;
F_124 ( & V_175 , & V_52 ) ;
for (; ; ) {
F_125 ( V_176 ) ;
if ( F_61 ( & V_173 ) == 0 )
break;
F_126 ( & T_4 ) ;
F_94 () ;
F_122 ( & T_4 ) ;
}
F_127 ( V_177 ) ;
F_128 ( & V_175 , & V_52 ) ;
}
}
void F_129 ( void )
__releases( T_4 )
{
F_126 ( & T_4 ) ;
F_130 ( & V_175 ) ;
}
static inline void
F_131 ( void )
{
F_132 ( & T_4 ) ;
F_35 ( & V_173 ) ;
F_133 ( & T_4 ) ;
}
static inline void
F_134 ( void )
{
if ( F_135 ( & V_173 ) )
F_130 ( & V_175 ) ;
}
static inline int F_136 ( struct V_178 * V_179 ,
const void * V_180 )
{
const struct V_181 * V_182 = V_179 -> V_183 ;
const struct V_42 * V_43 = V_180 ;
return V_43 -> V_150 != V_182 -> V_150 ||
! F_137 ( F_138 ( & V_43 -> V_2 ) , F_139 ( & V_182 -> V_184 ) ) ;
}
static void F_140 ( struct V_181 * V_179 ,
struct V_185 * V_185 , T_1 V_150 )
{
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
F_141 ( & V_179 -> V_184 , V_185 ) ;
V_179 -> V_150 = V_150 ;
}
static struct V_1 * F_142 ( struct V_186 * V_187 , T_1 V_150 ,
struct V_185 * V_185 )
{
struct V_181 V_179 ;
F_140 ( & V_179 , V_185 , V_150 ) ;
return F_143 ( & V_187 -> V_188 , & V_179 ,
V_189 ) ;
}
static int F_144 ( struct V_186 * V_187 , struct V_1 * V_2 )
{
struct V_181 V_179 ;
F_140 ( & V_179 , F_138 ( V_2 ) , F_2 ( V_2 ) -> V_150 ) ;
return F_145 ( & V_187 -> V_188 , & V_179 ,
& F_2 ( V_2 ) -> V_190 ,
V_189 ) ;
}
static struct V_1 * F_146 ( struct V_185 * V_185 , int V_35 , T_1 V_150 )
{
struct V_186 * V_187 = & V_191 [ V_35 ] ;
struct V_1 * V_2 ;
F_29 () ;
V_2 = F_142 ( V_187 , V_150 , V_185 ) ;
if ( V_2 )
F_147 ( V_2 ) ;
F_31 () ;
return V_2 ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_186 * V_192 = & V_191 [ V_2 -> V_22 ] ;
unsigned long V_129 ;
unsigned int V_59 ;
struct V_193 * V_193 ;
V_193 = F_149 ( V_192 -> V_193 ) ;
if ( ! V_193 )
return;
for ( V_59 = 0 ; V_59 < F_150 ( V_192 -> V_172 ) ; V_59 ++ ) {
V_129 = 0 ;
F_151 (sk, &tbl->mc_list) {
if ( V_59 < F_150 ( F_2 ( V_2 ) -> V_194 ) )
V_129 |= F_2 ( V_2 ) -> V_172 [ V_59 ] ;
}
V_193 -> V_195 [ V_59 ] = V_129 ;
}
}
static int F_152 ( struct V_1 * V_2 , T_1 V_150 )
{
struct V_186 * V_187 = & V_191 [ V_2 -> V_22 ] ;
int V_104 ;
F_153 ( V_2 ) ;
V_104 = - V_89 ;
if ( F_2 ( V_2 ) -> V_150 )
goto V_104;
V_104 = - V_33 ;
if ( V_196 > 32 &&
F_5 ( F_61 ( & V_187 -> V_188 . V_197 ) >= V_198 ) )
goto V_104;
F_2 ( V_2 ) -> V_150 = V_150 ;
F_147 ( V_2 ) ;
V_104 = F_144 ( V_187 , V_2 ) ;
if ( V_104 ) {
if ( F_5 ( V_104 == - V_89 ) )
V_104 = - V_199 ;
if ( V_104 == - V_200 )
V_104 = - V_201 ;
F_2 ( V_2 ) -> V_150 = 0 ;
F_109 ( V_2 ) ;
}
V_104:
F_154 ( V_2 ) ;
return V_104 ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_186 * V_187 ;
V_187 = & V_191 [ V_2 -> V_22 ] ;
if ( ! F_156 ( & V_187 -> V_188 , & F_2 ( V_2 ) -> V_190 ,
V_189 ) ) {
F_60 ( F_61 ( & V_2 -> V_202 ) == 1 ) ;
F_157 ( V_2 ) ;
}
F_120 () ;
if ( F_2 ( V_2 ) -> V_203 ) {
F_158 ( V_2 ) ;
F_148 ( V_2 ) ;
}
if ( V_2 -> V_22 == V_30 )
F_35 ( & V_204 ) ;
F_129 () ;
}
static int F_159 ( struct V_185 * V_185 , struct V_99 * V_1 ,
struct V_205 * V_206 , int V_35 ,
int V_207 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
V_1 -> V_208 = & V_209 ;
V_2 = F_160 ( V_185 , V_210 , V_62 , & V_211 , V_207 ) ;
if ( ! V_2 )
return - V_33 ;
F_161 ( V_1 , V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_206 ) {
V_43 -> V_206 = V_206 ;
} else {
V_43 -> V_206 = & V_43 -> V_212 ;
F_162 ( V_43 -> V_206 ) ;
}
F_163 ( & V_43 -> V_52 ) ;
#ifdef F_108
F_162 ( & V_43 -> V_94 ) ;
#endif
V_2 -> V_213 = F_116 ;
V_2 -> V_22 = V_35 ;
return 0 ;
}
static int F_164 ( struct V_185 * V_185 , struct V_99 * V_1 , int V_35 ,
int V_207 )
{
struct V_14 * V_14 = NULL ;
struct V_205 * V_206 ;
struct V_42 * V_43 ;
int (* F_165)( struct V_185 * V_185 , int V_5 );
void (* F_166)( struct V_185 * V_185 , int V_5 );
int V_104 = 0 ;
V_1 -> V_46 = V_214 ;
if ( V_1 -> type != V_215 && V_1 -> type != V_216 )
return - V_217 ;
if ( V_35 < 0 || V_35 >= V_218 )
return - V_219 ;
F_131 () ;
#ifdef F_167
if ( ! V_191 [ V_35 ] . V_220 ) {
F_134 () ;
F_168 ( L_3 , V_210 , V_35 ) ;
F_131 () ;
}
#endif
if ( V_191 [ V_35 ] . V_220 &&
F_169 ( V_191 [ V_35 ] . V_14 ) )
V_14 = V_191 [ V_35 ] . V_14 ;
else
V_104 = - V_219 ;
V_206 = V_191 [ V_35 ] . V_206 ;
F_165 = V_191 [ V_35 ] . F_165 ;
F_166 = V_191 [ V_35 ] . F_166 ;
F_134 () ;
if ( V_104 < 0 )
goto V_17;
V_104 = F_159 ( V_185 , V_1 , V_206 , V_35 , V_207 ) ;
if ( V_104 < 0 )
goto V_221;
F_170 () ;
F_171 ( V_185 , & V_211 , 1 ) ;
F_172 () ;
V_43 = F_2 ( V_1 -> V_2 ) ;
V_43 -> V_14 = V_14 ;
V_43 -> V_222 = F_165 ;
V_43 -> V_223 = F_166 ;
V_17:
return V_104 ;
V_221:
F_14 ( V_14 ) ;
goto V_17;
}
static void F_173 ( struct V_224 * V_81 )
{
struct V_42 * V_43 = F_174 ( V_81 , struct V_42 , V_225 ) ;
F_109 ( & V_43 -> V_2 ) ;
}
static int F_175 ( struct V_99 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 ;
if ( ! V_2 )
return 0 ;
F_155 ( V_2 ) ;
F_176 ( V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_223 ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_43 -> V_194 ; V_59 ++ )
if ( F_39 ( V_59 , V_43 -> V_172 ) )
V_43 -> V_223 ( F_138 ( V_2 ) , V_59 + 1 ) ;
}
if ( V_2 -> V_22 == V_30 &&
F_110 ( & V_204 ) == 0 )
F_130 ( & V_226 ) ;
V_1 -> V_2 = NULL ;
F_177 ( & V_43 -> V_52 ) ;
F_117 ( & V_2 -> V_77 ) ;
if ( V_43 -> V_150 ) {
struct V_227 V_128 = {
. V_185 = F_138 ( V_2 ) ,
. V_35 = V_2 -> V_22 ,
. V_150 = V_43 -> V_150 ,
} ;
F_178 ( & V_228 ,
V_229 , & V_128 ) ;
}
F_14 ( V_43 -> V_14 ) ;
if ( F_1 ( V_2 ) ) {
F_120 () ;
F_179 ( V_191 [ V_2 -> V_22 ] . V_220 == 0 ) ;
if ( -- V_191 [ V_2 -> V_22 ] . V_220 == 0 ) {
struct V_193 * V_230 ;
V_230 = F_149 ( V_191 [ V_2 -> V_22 ] . V_193 ) ;
F_180 ( V_191 [ V_2 -> V_22 ] . V_193 , NULL ) ;
F_181 ( V_230 , V_225 ) ;
V_191 [ V_2 -> V_22 ] . V_14 = NULL ;
V_191 [ V_2 -> V_22 ] . F_165 = NULL ;
V_191 [ V_2 -> V_22 ] . F_166 = NULL ;
V_191 [ V_2 -> V_22 ] . V_3 = 0 ;
V_191 [ V_2 -> V_22 ] . V_220 = 0 ;
}
F_129 () ;
}
F_49 ( V_43 -> V_172 ) ;
V_43 -> V_172 = NULL ;
F_170 () ;
F_171 ( F_138 ( V_2 ) , & V_211 , - 1 ) ;
F_172 () ;
F_182 ( & V_43 -> V_225 , F_173 ) ;
return 0 ;
}
static int F_183 ( struct V_99 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_185 * V_185 = F_138 ( V_2 ) ;
struct V_186 * V_187 = & V_191 [ V_2 -> V_22 ] ;
T_5 V_150 = F_184 ( V_174 ) ;
int V_104 ;
T_5 V_231 = - 4096 ;
bool V_232 ;
V_233:
F_185 () ;
F_29 () ;
V_232 = ! F_142 ( V_187 , V_150 , V_185 ) ;
F_31 () ;
if ( ! V_232 ) {
if ( V_231 == - 4096 )
V_231 = V_234 + F_186 ( - 4096 - V_234 ) ;
else if ( V_231 >= - 4096 )
V_231 = - 4097 ;
V_150 = V_231 -- ;
goto V_233;
}
V_104 = F_152 ( V_2 , V_150 ) ;
if ( V_104 == - V_201 )
goto V_233;
if ( V_104 == - V_89 )
V_104 = 0 ;
return V_104 ;
}
bool F_187 ( const struct V_235 * V_236 ,
struct V_237 * V_238 , int V_239 )
{
return ( ( V_236 -> V_3 & V_240 ) ||
F_188 ( V_236 -> V_2 -> V_241 -> V_97 , V_238 , V_239 ) ) &&
F_189 ( V_238 , V_239 ) ;
}
bool F_190 ( const struct V_20 * V_21 ,
struct V_237 * V_238 , int V_239 )
{
return F_187 ( & F_42 ( V_21 ) , V_238 , V_239 ) ;
}
bool F_191 ( const struct V_20 * V_21 , int V_239 )
{
return F_190 ( V_21 , & V_242 , V_239 ) ;
}
bool F_192 ( const struct V_20 * V_21 , int V_239 )
{
return F_190 ( V_21 , F_138 ( V_21 -> V_2 ) -> V_238 , V_239 ) ;
}
static inline int F_193 ( const struct V_99 * V_1 , unsigned int V_243 )
{
return ( V_191 [ V_1 -> V_2 -> V_22 ] . V_3 & V_243 ) ||
F_189 ( F_138 ( V_1 -> V_2 ) -> V_238 , V_244 ) ;
}
static void
F_194 ( struct V_1 * V_2 , unsigned int V_203 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_203 && ! V_203 )
F_158 ( V_2 ) ;
else if ( ! V_43 -> V_203 && V_203 )
F_195 ( V_2 , & V_191 [ V_2 -> V_22 ] . V_245 ) ;
V_43 -> V_203 = V_203 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_172 ;
unsigned long * V_246 ;
int V_104 = 0 ;
F_120 () ;
V_172 = V_191 [ V_2 -> V_22 ] . V_172 ;
if ( ! V_191 [ V_2 -> V_22 ] . V_220 ) {
V_104 = - V_247 ;
goto V_248;
}
if ( V_43 -> V_194 >= V_172 )
goto V_248;
V_246 = F_197 ( V_43 -> V_172 , F_198 ( V_172 ) , V_34 ) ;
if ( V_246 == NULL ) {
V_104 = - V_33 ;
goto V_248;
}
memset ( ( char * ) V_246 + F_198 ( V_43 -> V_194 ) , 0 ,
F_198 ( V_172 ) - F_198 ( V_43 -> V_194 ) ) ;
V_43 -> V_172 = V_246 ;
V_43 -> V_194 = V_172 ;
V_248:
F_129 () ;
return V_104 ;
}
static void F_199 ( int V_5 , long unsigned int V_172 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_249 ;
if ( ! V_43 -> V_223 )
return;
for ( V_249 = 0 ; V_249 < V_5 ; V_249 ++ )
if ( F_39 ( V_249 , & V_172 ) )
V_43 -> V_223 ( F_138 ( V_2 ) , V_249 + 1 ) ;
}
static int V_222 ( struct V_99 * V_1 , struct V_250 * V_251 ,
int V_252 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_185 * V_185 = F_138 ( V_2 ) ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_253 * V_254 = (struct V_253 * ) V_251 ;
int V_104 ;
long unsigned int V_172 = V_254 -> V_255 ;
if ( V_252 < sizeof( struct V_253 ) )
return - V_10 ;
if ( V_254 -> V_256 != V_257 )
return - V_10 ;
if ( V_172 ) {
if ( ! F_193 ( V_1 , V_258 ) )
return - V_259 ;
V_104 = F_196 ( V_2 ) ;
if ( V_104 )
return V_104 ;
}
if ( V_43 -> V_150 )
if ( V_254 -> V_260 != V_43 -> V_150 )
return - V_10 ;
if ( V_43 -> V_222 && V_172 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_43 -> V_194 ; V_5 ++ ) {
if ( ! F_39 ( V_5 , & V_172 ) )
continue;
V_104 = V_43 -> V_222 ( V_185 , V_5 + 1 ) ;
if ( ! V_104 )
continue;
F_199 ( V_5 , V_172 , V_2 ) ;
return V_104 ;
}
}
if ( ! V_43 -> V_150 ) {
V_104 = V_254 -> V_260 ?
F_152 ( V_2 , V_254 -> V_260 ) :
F_183 ( V_1 ) ;
if ( V_104 ) {
F_199 ( V_43 -> V_194 , V_172 , V_2 ) ;
return V_104 ;
}
}
if ( ! V_172 && ( V_43 -> V_172 == NULL || ! ( T_1 ) V_43 -> V_172 [ 0 ] ) )
return 0 ;
F_120 () ;
F_194 ( V_2 , V_43 -> V_203 +
F_200 ( V_172 ) -
F_200 ( V_43 -> V_172 [ 0 ] ) ) ;
V_43 -> V_172 [ 0 ] = ( V_43 -> V_172 [ 0 ] & ~ 0xffffffffUL ) | V_172 ;
F_148 ( V_2 ) ;
F_129 () ;
return 0 ;
}
static int F_201 ( struct V_99 * V_1 , struct V_250 * V_251 ,
int V_261 , int V_3 )
{
int V_104 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_253 * V_254 = (struct V_253 * ) V_251 ;
if ( V_261 < sizeof( V_251 -> V_262 ) )
return - V_10 ;
if ( V_251 -> V_262 == V_263 ) {
V_2 -> V_264 = V_265 ;
V_43 -> V_142 = 0 ;
V_43 -> V_143 = 0 ;
return 0 ;
}
if ( V_251 -> V_262 != V_257 )
return - V_10 ;
if ( ( V_254 -> V_255 || V_254 -> V_260 ) &&
! F_193 ( V_1 , V_266 ) )
return - V_259 ;
if ( ! V_43 -> V_150 )
V_104 = F_183 ( V_1 ) ;
if ( V_104 == 0 ) {
V_2 -> V_264 = V_267 ;
V_43 -> V_142 = V_254 -> V_260 ;
V_43 -> V_143 = F_202 ( V_254 -> V_255 ) ;
}
return V_104 ;
}
static int F_203 ( struct V_99 * V_1 , struct V_250 * V_251 ,
int * V_252 , int V_268 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_204 ( struct V_253 * , V_254 , V_251 ) ;
V_254 -> V_256 = V_257 ;
V_254 -> V_269 = 0 ;
* V_252 = sizeof( * V_254 ) ;
if ( V_268 ) {
V_254 -> V_260 = V_43 -> V_142 ;
V_254 -> V_255 = F_3 ( V_43 -> V_143 ) ;
} else {
V_254 -> V_260 = V_43 -> V_150 ;
V_254 -> V_255 = V_43 -> V_172 ? V_43 -> V_172 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_205 ( struct V_1 * V_270 , T_1 V_150 )
{
struct V_1 * V_1 ;
struct V_42 * V_43 ;
V_1 = F_146 ( F_138 ( V_270 ) , V_270 -> V_22 , V_150 ) ;
if ( ! V_1 )
return F_206 ( - V_271 ) ;
V_43 = F_2 ( V_1 ) ;
if ( V_1 -> V_264 == V_267 &&
V_43 -> V_142 != F_2 ( V_270 ) -> V_150 ) {
F_109 ( V_1 ) ;
return F_206 ( - V_271 ) ;
}
return V_1 ;
}
struct V_1 * F_207 ( struct V_97 * V_272 )
{
struct V_273 * V_273 = F_208 ( V_272 ) ;
struct V_1 * V_1 ;
if ( ! F_209 ( V_273 -> V_274 ) )
return F_206 ( - V_275 ) ;
V_1 = F_210 ( V_273 ) -> V_2 ;
if ( V_1 -> V_276 != V_257 )
return F_206 ( - V_10 ) ;
F_147 ( V_1 ) ;
return V_1 ;
}
static struct V_20 * F_211 ( unsigned int V_102 ,
int V_277 )
{
struct V_20 * V_21 ;
void * V_135 ;
if ( V_102 <= V_278 || V_277 )
return F_96 ( V_102 , V_62 ) ;
V_102 = F_212 ( V_102 ) +
F_212 ( sizeof( struct V_279 ) ) ;
V_135 = F_213 ( V_102 ) ;
if ( V_135 == NULL )
return NULL ;
V_21 = F_214 ( V_135 , V_102 ) ;
if ( V_21 == NULL )
F_47 ( V_135 ) ;
else
V_21 -> V_138 = V_139 ;
return V_21 ;
}
int F_215 ( struct V_1 * V_2 , struct V_20 * V_21 ,
long * V_280 , struct V_1 * V_270 )
{
struct V_42 * V_43 ;
V_43 = F_2 ( V_2 ) ;
if ( ( F_61 ( & V_2 -> V_166 ) > V_2 -> V_281 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_41 ( V_21 ) ) {
F_123 ( V_52 , V_174 ) ;
if ( ! * V_280 ) {
if ( ! V_270 || F_1 ( V_270 ) )
F_33 ( V_2 ) ;
F_109 ( V_2 ) ;
F_99 ( V_21 ) ;
return - V_282 ;
}
F_127 ( V_283 ) ;
F_216 ( & V_43 -> V_52 , & V_52 ) ;
if ( ( F_61 ( & V_2 -> V_166 ) > V_2 -> V_281 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_118 ( V_2 , V_169 ) )
* V_280 = F_217 ( * V_280 ) ;
F_127 ( V_177 ) ;
F_128 ( & V_43 -> V_52 , & V_52 ) ;
F_109 ( V_2 ) ;
if ( F_218 ( V_174 ) ) {
F_99 ( V_21 ) ;
return F_219 ( * V_280 ) ;
}
return 1 ;
}
F_113 ( V_21 , V_2 ) ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = V_21 -> V_58 ;
F_28 ( V_21 ) ;
#ifdef F_108
if ( F_41 ( V_21 ) )
F_102 ( V_2 , V_21 ) ;
else if ( F_43 ( V_2 ) )
F_106 ( V_2 , V_21 ) ;
else
#endif
F_221 ( & V_2 -> V_51 , V_21 ) ;
V_2 -> V_284 ( V_2 ) ;
return V_58 ;
}
int F_222 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = F_220 ( V_2 , V_21 ) ;
F_109 ( V_2 ) ;
return V_58 ;
}
void F_223 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
F_99 ( V_21 ) ;
F_109 ( V_2 ) ;
}
static struct V_20 * F_224 ( struct V_20 * V_21 , T_2 V_285 )
{
int V_286 ;
F_60 ( V_21 -> V_2 != NULL ) ;
if ( F_41 ( V_21 ) )
return V_21 ;
V_286 = V_21 -> V_136 - V_21 -> V_137 ;
if ( F_46 ( V_21 -> V_81 ) || V_286 * 2 < V_21 -> V_165 )
return V_21 ;
if ( F_225 ( V_21 ) ) {
struct V_20 * V_32 = F_20 ( V_21 , V_285 ) ;
if ( ! V_32 )
return V_21 ;
F_226 ( V_21 ) ;
V_21 = V_32 ;
}
if ( ! F_227 ( V_21 , 0 , - V_286 , V_285 ) )
V_21 -> V_165 -= V_286 ;
return V_21 ;
}
static int F_228 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_1 * V_270 )
{
int V_19 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
V_19 = - V_271 ;
if ( V_43 -> V_287 != NULL ) {
V_19 = V_21 -> V_58 ;
F_113 ( V_21 , V_2 ) ;
F_42 ( V_21 ) . V_2 = V_270 ;
F_32 ( V_2 , V_270 , V_21 ) ;
V_43 -> V_287 ( V_21 ) ;
F_226 ( V_21 ) ;
} else {
F_99 ( V_21 ) ;
}
F_109 ( V_2 ) ;
return V_19 ;
}
int F_101 ( struct V_1 * V_270 , struct V_20 * V_21 ,
T_1 V_150 , int V_288 )
{
struct V_1 * V_2 ;
int V_104 ;
long V_280 ;
V_21 = F_224 ( V_21 , F_229 () ) ;
V_280 = F_230 ( V_270 , V_288 ) ;
V_233:
V_2 = F_205 ( V_270 , V_150 ) ;
if ( F_231 ( V_2 ) ) {
F_99 ( V_21 ) ;
return F_232 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_228 ( V_2 , V_21 , V_270 ) ;
if ( F_233 ( V_2 , V_21 ) ) {
V_104 = V_21 -> V_58 ;
F_99 ( V_21 ) ;
F_109 ( V_2 ) ;
return V_104 ;
}
V_104 = F_215 ( V_2 , V_21 , & V_280 , V_270 ) ;
if ( V_104 == 1 )
goto V_233;
if ( V_104 )
return V_104 ;
return F_222 ( V_2 , V_21 ) ;
}
struct V_20 * F_234 ( struct V_1 * V_270 , unsigned int V_102 ,
T_1 V_142 , T_2 V_289 )
{
#ifdef F_108
struct V_1 * V_2 = NULL ;
struct V_20 * V_21 ;
struct V_75 * V_76 ;
struct V_113 * V_114 ;
unsigned int V_146 ;
V_2 = F_205 ( V_270 , V_142 ) ;
if ( F_231 ( V_2 ) )
goto V_17;
V_76 = & F_2 ( V_2 ) -> V_54 ;
if ( V_76 -> V_55 == NULL )
goto V_290;
if ( V_76 -> V_82 - V_91 < V_102 )
goto V_290;
V_21 = F_235 ( V_289 ) ;
if ( V_21 == NULL )
goto V_72;
F_56 ( & V_2 -> V_51 . V_78 ) ;
if ( V_76 -> V_55 == NULL )
goto V_291;
V_146 = V_76 -> V_82 - V_91 ;
if ( V_146 < V_102 )
goto V_291;
F_85 ( V_76 ) ;
V_114 = F_82 ( V_76 , V_126 ) ;
if ( V_114 == NULL )
goto V_292;
F_91 ( V_21 , V_2 , V_76 , V_114 ) ;
F_78 ( V_114 , V_293 ) ;
F_35 ( & V_76 -> V_90 ) ;
F_84 ( V_76 ) ;
F_59 ( & V_2 -> V_51 . V_78 ) ;
return V_21 ;
V_292:
F_99 ( V_21 ) ;
F_59 ( & V_2 -> V_51 . V_78 ) ;
F_33 ( V_2 ) ;
V_72:
F_109 ( V_2 ) ;
return NULL ;
V_291:
F_99 ( V_21 ) ;
F_59 ( & V_2 -> V_51 . V_78 ) ;
V_290:
F_109 ( V_2 ) ;
V_17:
#endif
return F_96 ( V_102 , V_289 ) ;
}
int F_236 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_294 = 0 ;
struct V_193 * V_193 ;
F_179 ( ! F_1 ( V_2 ) ) ;
F_29 () ;
V_193 = F_237 ( V_191 [ V_2 -> V_22 ] . V_193 ) ;
if ( V_193 && V_5 - 1 < V_191 [ V_2 -> V_22 ] . V_172 )
V_294 = F_39 ( V_5 - 1 , V_193 -> V_195 ) ;
F_31 () ;
return V_294 ;
}
static int F_238 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( F_61 ( & V_2 -> V_166 ) <= V_2 -> V_281 &&
! F_39 ( V_45 , & V_43 -> V_46 ) ) {
F_113 ( V_21 , V_2 ) ;
F_220 ( V_2 , V_21 ) ;
return F_61 ( & V_2 -> V_166 ) > ( V_2 -> V_281 >> 1 ) ;
}
return - 1 ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_295 * V_296 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_297 ;
if ( V_296 -> V_298 == V_2 )
return;
if ( V_43 -> V_150 == V_296 -> V_150 || V_296 -> V_5 - 1 >= V_43 -> V_194 ||
! F_39 ( V_296 -> V_5 - 1 , V_43 -> V_172 ) )
return;
if ( ! F_137 ( F_138 ( V_2 ) , V_296 -> V_185 ) ) {
if ( ! ( V_43 -> V_3 & V_299 ) )
return;
if ( ! F_240 ( F_138 ( V_2 ) , V_296 -> V_185 ) )
return;
if ( ! F_188 ( V_2 -> V_241 -> V_97 , V_296 -> V_185 -> V_238 ,
V_300 ) )
return;
}
if ( V_296 -> V_301 ) {
F_33 ( V_2 ) ;
return;
}
F_147 ( V_2 ) ;
if ( V_296 -> V_302 == NULL ) {
if ( F_225 ( V_296 -> V_21 ) ) {
V_296 -> V_302 = F_20 ( V_296 -> V_21 , V_296 -> V_285 ) ;
} else {
V_296 -> V_302 = F_241 ( V_296 -> V_21 ) ;
F_242 ( V_296 -> V_302 ) ;
}
}
if ( V_296 -> V_302 == NULL ) {
F_33 ( V_2 ) ;
V_296 -> V_301 = 1 ;
if ( V_43 -> V_3 & V_303 )
V_296 -> V_304 = 1 ;
goto V_17;
}
if ( V_296 -> V_305 && V_296 -> V_305 ( V_2 , V_296 -> V_302 , V_296 -> V_306 ) ) {
F_99 ( V_296 -> V_302 ) ;
V_296 -> V_302 = NULL ;
goto V_17;
}
if ( F_233 ( V_2 , V_296 -> V_302 ) ) {
F_99 ( V_296 -> V_302 ) ;
V_296 -> V_302 = NULL ;
goto V_17;
}
F_42 ( V_296 -> V_302 ) . V_307 = F_243 ( F_138 ( V_2 ) , V_296 -> V_185 ) ;
F_42 ( V_296 -> V_302 ) . V_308 = true ;
V_297 = F_238 ( V_2 , V_296 -> V_302 ) ;
if ( V_297 < 0 ) {
F_33 ( V_2 ) ;
if ( V_43 -> V_3 & V_303 )
V_296 -> V_304 = 1 ;
} else {
V_296 -> V_309 |= V_297 ;
V_296 -> V_310 = 1 ;
V_296 -> V_302 = NULL ;
}
V_17:
F_109 ( V_2 ) ;
}
int F_244 ( struct V_1 * V_270 , struct V_20 * V_21 , T_1 V_150 ,
T_1 V_5 , T_2 V_285 ,
int (* F_245)( struct V_1 * V_311 , struct V_20 * V_21 , void * V_135 ) ,
void * V_312 )
{
struct V_185 * V_185 = F_138 ( V_270 ) ;
struct V_295 V_313 ;
struct V_1 * V_2 ;
V_21 = F_224 ( V_21 , V_285 ) ;
V_313 . V_298 = V_270 ;
V_313 . V_185 = V_185 ;
V_313 . V_150 = V_150 ;
V_313 . V_5 = V_5 ;
V_313 . V_301 = 0 ;
V_313 . V_304 = 0 ;
V_313 . V_309 = 0 ;
V_313 . V_310 = 0 ;
V_313 . V_285 = V_285 ;
V_313 . V_21 = V_21 ;
V_313 . V_302 = NULL ;
V_313 . V_305 = F_245 ;
V_313 . V_306 = V_312 ;
F_131 () ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_239 ( V_2 , & V_313 ) ;
F_226 ( V_21 ) ;
F_134 () ;
if ( V_313 . V_304 ) {
F_99 ( V_313 . V_302 ) ;
return - V_48 ;
}
F_226 ( V_313 . V_302 ) ;
if ( V_313 . V_310 ) {
if ( V_313 . V_309 && ( V_285 & V_314 ) )
F_246 () ;
return 0 ;
}
return - V_315 ;
}
int F_100 ( struct V_1 * V_270 , struct V_20 * V_21 , T_1 V_150 ,
T_1 V_5 , T_2 V_285 )
{
return F_244 ( V_270 , V_21 , V_150 , V_5 , V_285 ,
NULL , NULL ) ;
}
static int F_247 ( struct V_1 * V_2 , struct V_316 * V_296 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_19 = 0 ;
if ( V_2 == V_296 -> V_298 )
goto V_17;
if ( ! F_137 ( F_138 ( V_2 ) , F_138 ( V_296 -> V_298 ) ) )
goto V_17;
if ( V_43 -> V_150 == V_296 -> V_150 || V_296 -> V_5 - 1 >= V_43 -> V_194 ||
! F_39 ( V_296 -> V_5 - 1 , V_43 -> V_172 ) )
goto V_17;
if ( V_296 -> V_317 == V_48 && V_43 -> V_3 & V_44 ) {
V_19 = 1 ;
goto V_17;
}
V_2 -> V_47 = V_296 -> V_317 ;
V_2 -> V_49 ( V_2 ) ;
V_17:
return V_19 ;
}
int F_248 ( struct V_1 * V_270 , T_1 V_150 , T_1 V_5 , int V_317 )
{
struct V_316 V_313 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_313 . V_298 = V_270 ;
V_313 . V_150 = V_150 ;
V_313 . V_5 = V_5 ;
V_313 . V_317 = - V_317 ;
F_132 ( & T_4 ) ;
F_151 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_19 += F_247 ( V_2 , & V_313 ) ;
F_133 ( & T_4 ) ;
return V_19 ;
}
static void F_249 ( struct V_42 * V_43 ,
unsigned int V_5 ,
int V_318 )
{
int V_230 , V_319 = ! ! V_318 , V_203 ;
V_230 = F_39 ( V_5 - 1 , V_43 -> V_172 ) ;
V_203 = V_43 -> V_203 - V_230 + V_319 ;
if ( V_319 )
F_250 ( V_5 - 1 , V_43 -> V_172 ) ;
else
F_251 ( V_5 - 1 , V_43 -> V_172 ) ;
F_194 ( & V_43 -> V_2 , V_203 ) ;
F_148 ( & V_43 -> V_2 ) ;
}
static int F_252 ( struct V_99 * V_1 , int V_320 , int V_321 ,
char T_6 * V_322 , unsigned int V_323 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_297 = 0 ;
int V_104 ;
if ( V_320 != V_324 )
return - V_325 ;
if ( V_321 != V_326 && V_321 != V_327 &&
V_323 >= sizeof( int ) &&
F_253 ( V_297 , ( unsigned int T_6 * ) V_322 ) )
return - V_328 ;
switch ( V_321 ) {
case V_329 :
if ( V_297 )
V_43 -> V_3 |= V_330 ;
else
V_43 -> V_3 &= ~ V_330 ;
V_104 = 0 ;
break;
case V_331 :
case V_332 : {
if ( ! F_193 ( V_1 , V_258 ) )
return - V_259 ;
V_104 = F_196 ( V_2 ) ;
if ( V_104 )
return V_104 ;
if ( ! V_297 || V_297 - 1 >= V_43 -> V_194 )
return - V_10 ;
if ( V_321 == V_331 && V_43 -> V_222 ) {
V_104 = V_43 -> V_222 ( F_138 ( V_2 ) , V_297 ) ;
if ( V_104 )
return V_104 ;
}
F_120 () ;
F_249 ( V_43 , V_297 ,
V_321 == V_331 ) ;
F_129 () ;
if ( V_321 == V_332 && V_43 -> V_223 )
V_43 -> V_223 ( F_138 ( V_2 ) , V_297 ) ;
V_104 = 0 ;
break;
}
case V_333 :
if ( V_297 )
V_43 -> V_3 |= V_303 ;
else
V_43 -> V_3 &= ~ V_303 ;
V_104 = 0 ;
break;
case V_334 :
if ( V_297 ) {
V_43 -> V_3 |= V_44 ;
F_38 ( V_45 , & V_43 -> V_46 ) ;
F_40 ( & V_43 -> V_52 ) ;
} else {
V_43 -> V_3 &= ~ V_44 ;
}
V_104 = 0 ;
break;
#ifdef F_108
case V_326 :
case V_327 : {
struct V_68 V_69 ;
if ( ! F_254 ( V_244 ) )
return - V_259 ;
if ( V_323 < sizeof( V_69 ) )
return - V_10 ;
if ( F_255 ( & V_69 , V_322 , sizeof( V_69 ) ) )
return - V_328 ;
V_104 = F_62 ( V_2 , & V_69 ,
V_321 == V_327 ) ;
break;
}
#endif
case V_335 :
if ( ! F_189 ( F_138 ( V_2 ) -> V_238 , V_300 ) )
return - V_259 ;
if ( V_297 )
V_43 -> V_3 |= V_299 ;
else
V_43 -> V_3 &= ~ V_299 ;
V_104 = 0 ;
break;
default:
V_104 = - V_325 ;
}
return V_104 ;
}
static int F_256 ( struct V_99 * V_1 , int V_320 , int V_321 ,
char T_6 * V_322 , int T_6 * V_323 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_58 , V_297 , V_104 ;
if ( V_320 != V_324 )
return - V_325 ;
if ( F_253 ( V_58 , V_323 ) )
return - V_328 ;
if ( V_58 < 0 )
return - V_10 ;
switch ( V_321 ) {
case V_329 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_297 = V_43 -> V_3 & V_330 ? 1 : 0 ;
if ( F_257 ( V_58 , V_323 ) ||
F_257 ( V_297 , V_322 ) )
return - V_328 ;
V_104 = 0 ;
break;
case V_333 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_297 = V_43 -> V_3 & V_303 ? 1 : 0 ;
if ( F_257 ( V_58 , V_323 ) ||
F_257 ( V_297 , V_322 ) )
return - V_328 ;
V_104 = 0 ;
break;
case V_334 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_297 = V_43 -> V_3 & V_44 ? 1 : 0 ;
if ( F_257 ( V_58 , V_323 ) ||
F_257 ( V_297 , V_322 ) )
return - V_328 ;
V_104 = 0 ;
break;
case V_336 : {
int V_122 , V_337 , V_338 ;
V_104 = 0 ;
F_120 () ;
for ( V_122 = 0 ; V_122 * 8 < V_43 -> V_194 ; V_122 += sizeof( T_1 ) ) {
if ( V_58 - V_122 < sizeof( T_1 ) )
break;
V_337 = V_122 / sizeof( unsigned long ) ;
V_338 = ( V_122 % sizeof( unsigned long ) ) * 8 ;
if ( F_257 ( ( T_1 ) ( V_43 -> V_172 [ V_337 ] >> V_338 ) ,
( T_1 T_6 * ) ( V_322 + V_122 ) ) ) {
V_104 = - V_328 ;
break;
}
}
if ( F_257 ( F_258 ( V_43 -> V_194 / 8 , sizeof( T_1 ) ) , V_323 ) )
V_104 = - V_328 ;
F_129 () ;
break;
}
default:
V_104 = - V_325 ;
}
return V_104 ;
}
static void F_259 ( struct V_140 * V_141 , struct V_20 * V_21 )
{
struct V_339 V_313 ;
V_313 . V_5 = F_42 ( V_21 ) . V_143 ;
F_260 ( V_141 , V_324 , V_329 , sizeof( V_313 ) , & V_313 ) ;
}
static void F_261 ( struct V_1 * V_2 , struct V_140 * V_141 ,
struct V_20 * V_21 )
{
if ( ! F_42 ( V_21 ) . V_308 )
return;
F_260 ( V_141 , V_324 , V_335 , sizeof( int ) ,
& F_42 ( V_21 ) . V_307 ) ;
}
static int F_262 ( struct V_99 * V_1 , struct V_140 * V_141 , T_7 V_58 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_204 ( struct V_253 * , V_251 , V_141 -> V_340 ) ;
T_1 V_142 ;
T_1 V_143 ;
struct V_20 * V_21 ;
int V_104 ;
struct V_144 V_145 ;
T_1 V_341 = 0 ;
if ( V_141 -> V_148 & V_342 )
return - V_343 ;
V_104 = F_263 ( V_1 , V_141 , & V_145 , true ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_141 -> V_344 ) {
V_104 = - V_10 ;
if ( V_251 -> V_256 != V_257 )
goto V_17;
V_142 = V_251 -> V_260 ;
V_143 = F_202 ( V_251 -> V_255 ) ;
V_104 = - V_259 ;
if ( ( V_143 || V_142 ) &&
! F_193 ( V_1 , V_266 ) )
goto V_17;
V_341 |= V_240 ;
} else {
V_142 = V_43 -> V_142 ;
V_143 = V_43 -> V_143 ;
}
if ( ! V_43 -> V_150 ) {
V_104 = F_183 ( V_1 ) ;
if ( V_104 )
goto V_17;
}
if ( F_44 ( V_2 ) &&
F_264 ( & V_141 -> V_345 ) &&
V_141 -> V_345 . V_346 == 1 &&
V_141 -> V_345 . V_347 -> V_348 == NULL ) {
V_104 = F_93 ( V_2 , V_141 , V_142 , V_143 ,
& V_145 ) ;
goto V_17;
}
V_104 = - V_349 ;
if ( V_58 > V_2 -> V_350 - 32 )
goto V_17;
V_104 = - V_48 ;
V_21 = F_211 ( V_58 , V_143 ) ;
if ( V_21 == NULL )
goto V_17;
F_42 ( V_21 ) . V_150 = V_43 -> V_150 ;
F_42 ( V_21 ) . V_143 = V_143 ;
F_42 ( V_21 ) . V_151 = V_145 . V_151 ;
F_42 ( V_21 ) . V_3 = V_341 ;
V_104 = - V_328 ;
if ( F_265 ( F_266 ( V_21 , V_58 ) , V_141 , V_58 ) ) {
F_99 ( V_21 ) ;
goto V_17;
}
V_104 = F_98 ( V_2 , V_21 ) ;
if ( V_104 ) {
F_99 ( V_21 ) ;
goto V_17;
}
if ( V_143 ) {
F_35 ( & V_21 -> V_152 ) ;
F_100 ( V_2 , V_21 , V_142 , V_143 , V_62 ) ;
}
V_104 = F_101 ( V_2 , V_21 , V_142 , V_141 -> V_148 & V_149 ) ;
V_17:
F_267 ( & V_145 ) ;
return V_104 ;
}
static int F_268 ( struct V_99 * V_1 , struct V_140 * V_141 , T_7 V_58 ,
int V_3 )
{
struct V_144 V_145 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_351 = V_3 & V_149 ;
T_7 V_352 ;
struct V_20 * V_21 , * V_353 ;
int V_104 , V_19 ;
if ( V_3 & V_342 )
return - V_343 ;
V_352 = 0 ;
V_21 = F_269 ( V_2 , V_3 , V_351 , & V_104 ) ;
if ( V_21 == NULL )
goto V_17;
V_353 = V_21 ;
#ifdef F_270
if ( F_5 ( F_111 ( V_21 ) -> V_354 ) ) {
if ( V_3 & V_355 )
V_353 = F_111 ( V_21 ) -> V_354 ;
}
#endif
V_43 -> V_356 = F_271 ( V_43 -> V_356 , V_58 ) ;
V_43 -> V_356 = F_272 ( T_7 , V_43 -> V_356 ,
16384 ) ;
V_352 = V_353 -> V_58 ;
if ( V_58 < V_352 ) {
V_141 -> V_148 |= V_357 ;
V_352 = V_58 ;
}
F_273 ( V_353 ) ;
V_104 = F_274 ( V_353 , 0 , V_141 , V_352 ) ;
if ( V_141 -> V_340 ) {
F_204 ( struct V_253 * , V_251 , V_141 -> V_340 ) ;
V_251 -> V_256 = V_257 ;
V_251 -> V_269 = 0 ;
V_251 -> V_260 = F_42 ( V_21 ) . V_150 ;
V_251 -> V_255 = F_3 ( F_42 ( V_21 ) . V_143 ) ;
V_141 -> V_344 = sizeof( * V_251 ) ;
}
if ( V_43 -> V_3 & V_330 )
F_259 ( V_141 , V_21 ) ;
if ( V_43 -> V_3 & V_299 )
F_261 ( V_2 , V_141 , V_21 ) ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_151 = * F_275 ( V_21 ) ;
if ( V_3 & V_357 )
V_352 = V_353 -> V_58 ;
F_276 ( V_2 , V_21 ) ;
if ( V_43 -> V_130 &&
F_61 ( & V_2 -> V_166 ) <= V_2 -> V_281 / 2 ) {
V_19 = F_88 ( V_2 ) ;
if ( V_19 ) {
V_2 -> V_47 = - V_19 ;
V_2 -> V_49 ( V_2 ) ;
}
}
F_277 ( V_1 , V_141 , & V_145 , V_3 ) ;
V_17:
F_36 ( V_2 ) ;
return V_104 ? : V_352 ;
}
static void F_278 ( struct V_1 * V_2 )
{
F_279 () ;
}
struct V_1 *
F_280 ( struct V_185 * V_185 , int V_358 , struct V_14 * V_14 ,
struct V_359 * V_360 )
{
struct V_99 * V_1 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_193 * V_193 = NULL ;
struct V_205 * V_206 = V_360 ? V_360 -> V_206 : NULL ;
unsigned int V_172 ;
F_179 ( ! V_191 ) ;
if ( V_358 < 0 || V_358 >= V_218 )
return NULL ;
if ( F_281 ( V_210 , V_216 , V_358 , & V_1 ) )
return NULL ;
if ( F_159 ( V_185 , V_1 , V_206 , V_358 , 1 ) < 0 )
goto V_361;
V_2 = V_1 -> V_2 ;
if ( ! V_360 || V_360 -> V_172 < 32 )
V_172 = 32 ;
else
V_172 = V_360 -> V_172 ;
V_193 = F_282 ( sizeof( * V_193 ) + F_198 ( V_172 ) , V_62 ) ;
if ( ! V_193 )
goto V_362;
V_2 -> V_284 = F_278 ;
if ( V_360 && V_360 -> V_363 )
F_2 ( V_2 ) -> V_287 = V_360 -> V_363 ;
if ( F_152 ( V_2 , 0 ) )
goto V_362;
V_43 = F_2 ( V_2 ) ;
V_43 -> V_3 |= V_4 ;
F_120 () ;
if ( ! V_191 [ V_358 ] . V_220 ) {
V_191 [ V_358 ] . V_172 = V_172 ;
F_283 ( V_191 [ V_358 ] . V_193 , V_193 ) ;
V_191 [ V_358 ] . V_206 = V_206 ;
V_191 [ V_358 ] . V_14 = V_14 ;
if ( V_360 ) {
V_191 [ V_358 ] . F_165 = V_360 -> F_165 ;
V_191 [ V_358 ] . F_166 = V_360 -> F_166 ;
V_191 [ V_358 ] . V_3 = V_360 -> V_3 ;
if ( V_360 -> V_364 )
V_191 [ V_358 ] . V_364 = V_360 -> V_364 ;
}
V_191 [ V_358 ] . V_220 = 1 ;
} else {
F_49 ( V_193 ) ;
V_191 [ V_358 ] . V_220 ++ ;
}
F_129 () ;
return V_2 ;
V_362:
F_49 ( V_193 ) ;
F_284 ( V_2 ) ;
return NULL ;
V_361:
F_285 ( V_1 ) ;
return NULL ;
}
void
F_284 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_241 == NULL )
return;
F_285 ( V_2 -> V_241 ) ;
}
int F_286 ( struct V_1 * V_2 , unsigned int V_172 )
{
struct V_193 * V_319 , * V_230 ;
struct V_186 * V_192 = & V_191 [ V_2 -> V_22 ] ;
if ( V_172 < 32 )
V_172 = 32 ;
if ( F_198 ( V_192 -> V_172 ) < F_198 ( V_172 ) ) {
V_319 = F_282 ( sizeof( * V_319 ) + F_198 ( V_172 ) , V_34 ) ;
if ( ! V_319 )
return - V_33 ;
V_230 = F_149 ( V_192 -> V_193 ) ;
memcpy ( V_319 -> V_195 , V_230 -> V_195 , F_198 ( V_192 -> V_172 ) ) ;
F_283 ( V_192 -> V_193 , V_319 ) ;
F_181 ( V_230 , V_225 ) ;
}
V_192 -> V_172 = V_172 ;
return 0 ;
}
int F_287 ( struct V_1 * V_2 , unsigned int V_172 )
{
int V_104 ;
F_120 () ;
V_104 = F_286 ( V_2 , V_172 ) ;
F_129 () ;
return V_104 ;
}
void F_288 ( struct V_1 * V_365 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_186 * V_192 = & V_191 [ V_365 -> V_22 ] ;
F_151 (sk, &tbl->mc_list)
F_249 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_366 *
F_289 ( struct V_20 * V_21 , T_1 V_150 , T_1 V_367 , int type , int V_58 , int V_3 )
{
struct V_366 * V_368 ;
int V_102 = F_290 ( V_58 ) ;
V_368 = (struct V_366 * ) F_266 ( V_21 , F_291 ( V_102 ) ) ;
V_368 -> V_369 = type ;
V_368 -> V_370 = V_102 ;
V_368 -> V_371 = V_3 ;
V_368 -> V_372 = V_150 ;
V_368 -> V_373 = V_367 ;
if ( ! F_292 ( V_102 ) || F_291 ( V_102 ) - V_102 != 0 )
memset ( F_293 ( V_368 ) + V_58 , 0 , F_291 ( V_102 ) - V_102 ) ;
return V_368 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_374 * V_167 ;
struct V_20 * V_21 = NULL ;
struct V_366 * V_368 ;
int V_58 , V_104 = - V_48 ;
int V_375 ;
F_66 ( V_43 -> V_206 ) ;
if ( ! V_43 -> V_130 ) {
V_104 = - V_10 ;
goto V_376;
}
V_167 = & V_43 -> V_167 ;
V_375 = F_294 ( int , V_167 -> V_377 , V_278 ) ;
if ( ! F_43 ( V_2 ) &&
F_61 ( & V_2 -> V_166 ) >= V_2 -> V_281 )
goto V_376;
if ( V_375 < V_43 -> V_356 ) {
V_21 = F_234 ( V_2 ,
V_43 -> V_356 ,
V_43 -> V_150 ,
V_62 |
V_65 |
V_66 ) ;
if ( V_21 )
F_295 ( V_21 , F_296 ( V_21 ) -
V_43 -> V_356 ) ;
}
if ( ! V_21 )
V_21 = F_234 ( V_2 , V_375 , V_43 -> V_150 ,
V_62 ) ;
if ( ! V_21 )
goto V_376;
F_113 ( V_21 , V_2 ) ;
V_58 = V_167 -> V_378 ( V_21 , V_167 ) ;
if ( V_58 > 0 ) {
F_67 ( V_43 -> V_206 ) ;
if ( F_233 ( V_2 , V_21 ) )
F_99 ( V_21 ) ;
else
F_220 ( V_2 , V_21 ) ;
return 0 ;
}
V_368 = F_297 ( V_21 , V_167 , V_379 , sizeof( V_58 ) , V_380 ) ;
if ( ! V_368 )
goto V_376;
F_298 ( V_167 , V_368 ) ;
memcpy ( F_293 ( V_368 ) , & V_58 , sizeof( V_58 ) ) ;
if ( F_233 ( V_2 , V_21 ) )
F_99 ( V_21 ) ;
else
F_220 ( V_2 , V_21 ) ;
if ( V_167 -> V_168 )
V_167 -> V_168 ( V_167 ) ;
V_43 -> V_130 = false ;
F_67 ( V_43 -> V_206 ) ;
F_14 ( V_167 -> V_14 ) ;
F_226 ( V_167 -> V_21 ) ;
return 0 ;
V_376:
F_67 ( V_43 -> V_206 ) ;
F_99 ( V_21 ) ;
return V_104 ;
}
int F_299 ( struct V_1 * V_270 , struct V_20 * V_21 ,
const struct V_366 * V_368 ,
struct V_381 * V_382 )
{
struct V_374 * V_167 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_19 ;
if ( F_41 ( V_21 ) ) {
V_21 = F_300 ( V_21 , V_62 ) ;
if ( V_21 == NULL )
return - V_48 ;
} else
F_35 ( & V_21 -> V_152 ) ;
V_2 = F_146 ( F_138 ( V_270 ) , V_270 -> V_22 , F_42 ( V_21 ) . V_150 ) ;
if ( V_2 == NULL ) {
V_19 = - V_271 ;
goto V_383;
}
V_43 = F_2 ( V_2 ) ;
F_66 ( V_43 -> V_206 ) ;
if ( V_43 -> V_130 ) {
V_19 = - V_89 ;
goto V_384;
}
if ( ! F_169 ( V_382 -> V_14 ) ) {
V_19 = - V_219 ;
goto V_384;
}
V_167 = & V_43 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
V_167 -> V_378 = V_382 -> V_378 ;
V_167 -> V_168 = V_382 -> V_168 ;
V_167 -> V_368 = V_368 ;
V_167 -> V_135 = V_382 -> V_135 ;
V_167 -> V_14 = V_382 -> V_14 ;
V_167 -> V_377 = V_382 -> V_377 ;
V_167 -> V_21 = V_21 ;
V_43 -> V_130 = true ;
F_67 ( V_43 -> V_206 ) ;
V_19 = F_88 ( V_2 ) ;
F_109 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return - V_385 ;
V_384:
F_109 ( V_2 ) ;
F_67 ( V_43 -> V_206 ) ;
V_383:
F_99 ( V_21 ) ;
return V_19 ;
}
void F_301 ( struct V_20 * V_386 , struct V_366 * V_368 , int V_104 )
{
struct V_20 * V_21 ;
struct V_366 * V_387 ;
struct V_388 * V_389 ;
T_7 V_390 = sizeof( * V_389 ) ;
if ( V_104 )
V_390 += V_370 ( V_368 ) ;
V_21 = F_234 ( V_386 -> V_2 , F_302 ( V_390 ) ,
F_42 ( V_386 ) . V_150 , V_62 ) ;
if ( ! V_21 ) {
struct V_1 * V_2 ;
V_2 = F_146 ( F_138 ( V_386 -> V_2 ) ,
V_386 -> V_2 -> V_22 ,
F_42 ( V_386 ) . V_150 ) ;
if ( V_2 ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 ( V_2 ) ;
F_109 ( V_2 ) ;
}
return;
}
V_387 = F_289 ( V_21 , F_42 ( V_386 ) . V_150 , V_368 -> V_373 ,
V_391 , V_390 , 0 ) ;
V_389 = F_293 ( V_387 ) ;
V_389 -> error = V_104 ;
memcpy ( & V_389 -> V_141 , V_368 , V_104 ? V_368 -> V_370 : sizeof( * V_368 ) ) ;
F_101 ( V_386 -> V_2 , V_21 , F_42 ( V_386 ) . V_150 , V_149 ) ;
}
int F_303 ( struct V_20 * V_21 , int (* V_167)( struct V_20 * ,
struct V_366 * ) )
{
struct V_366 * V_368 ;
int V_104 ;
while ( V_21 -> V_58 >= F_302 ( 0 ) ) {
int V_392 ;
V_368 = F_304 ( V_21 ) ;
V_104 = 0 ;
if ( V_368 -> V_370 < V_393 || V_21 -> V_58 < V_368 -> V_370 )
return 0 ;
if ( ! ( V_368 -> V_371 & V_394 ) )
goto V_395;
if ( V_368 -> V_369 < V_396 )
goto V_395;
V_104 = V_167 ( V_21 , V_368 ) ;
if ( V_104 == - V_385 )
goto V_397;
V_395:
if ( V_368 -> V_371 & V_398 || V_104 )
F_301 ( V_21 , V_368 , V_104 ) ;
V_397:
V_392 = F_291 ( V_368 -> V_370 ) ;
if ( V_392 > V_21 -> V_58 )
V_392 = V_21 -> V_58 ;
F_305 ( V_21 , V_392 ) ;
}
return 0 ;
}
int F_306 ( struct V_1 * V_2 , struct V_20 * V_21 , T_1 V_150 ,
unsigned int V_5 , int V_399 , T_2 V_3 )
{
int V_104 = 0 ;
if ( V_5 ) {
int V_400 = 0 ;
if ( V_399 ) {
F_35 ( & V_21 -> V_152 ) ;
V_400 = V_150 ;
}
V_104 = F_307 ( V_2 , V_21 , V_400 , V_5 , V_3 ) ;
}
if ( V_399 ) {
int V_292 ;
V_292 = F_308 ( V_2 , V_21 , V_150 ) ;
if ( ! V_104 || V_104 == - V_315 )
V_104 = V_292 ;
}
return V_104 ;
}
static int F_309 ( struct V_401 * V_402 )
{
int V_104 ;
V_104 = F_310 ( & V_191 [ V_402 -> V_403 ] . V_188 , & V_402 -> V_404 ) ;
if ( V_104 ) {
V_402 -> V_403 = V_218 ;
return V_104 ;
}
V_104 = F_311 ( & V_402 -> V_404 ) ;
return V_104 == - V_282 ? 0 : V_104 ;
}
static void F_312 ( struct V_401 * V_402 )
{
F_313 ( & V_402 -> V_404 ) ;
F_314 ( & V_402 -> V_404 ) ;
}
static void * F_315 ( struct V_405 * V_367 )
{
struct V_401 * V_402 = V_367 -> V_406 ;
struct V_42 * V_43 ;
do {
for (; ; ) {
int V_104 ;
V_43 = F_316 ( & V_402 -> V_404 ) ;
if ( F_231 ( V_43 ) ) {
if ( F_232 ( V_43 ) == - V_282 )
continue;
return V_43 ;
}
if ( V_43 )
break;
F_312 ( V_402 ) ;
if ( ++ V_402 -> V_403 >= V_218 )
return NULL ;
V_104 = F_309 ( V_402 ) ;
if ( V_104 )
return F_206 ( V_104 ) ;
}
} while ( F_138 ( & V_43 -> V_2 ) != F_317 ( V_367 ) );
return V_43 ;
}
static void * F_318 ( struct V_405 * V_367 , T_8 * V_407 )
{
struct V_401 * V_402 = V_367 -> V_406 ;
void * V_408 = V_409 ;
T_8 V_122 ;
int V_104 ;
V_402 -> V_403 = 0 ;
V_104 = F_309 ( V_402 ) ;
if ( V_104 )
return F_206 ( V_104 ) ;
for ( V_122 = * V_407 ; V_122 && V_408 && ! F_231 ( V_408 ) ; V_122 -- )
V_408 = F_315 ( V_367 ) ;
return V_408 ;
}
static void * F_319 ( struct V_405 * V_367 , void * V_410 , T_8 * V_122 )
{
++ * V_122 ;
return F_315 ( V_367 ) ;
}
static void F_320 ( struct V_405 * V_367 , void * V_410 )
{
struct V_401 * V_402 = V_367 -> V_406 ;
if ( V_402 -> V_403 >= V_218 )
return;
F_312 ( V_402 ) ;
}
static int F_321 ( struct V_405 * V_367 , void * V_410 )
{
if ( V_410 == V_409 ) {
F_322 ( V_367 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_411 = V_410 ;
struct V_42 * V_43 = F_2 ( V_411 ) ;
F_323 ( V_367 , L_6 ,
V_411 ,
V_411 -> V_22 ,
V_43 -> V_150 ,
V_43 -> V_172 ? ( T_1 ) V_43 -> V_172 [ 0 ] : 0 ,
F_324 ( V_411 ) ,
F_325 ( V_411 ) ,
V_43 -> V_130 ,
F_61 ( & V_411 -> V_202 ) ,
F_61 ( & V_411 -> V_50 ) ,
F_326 ( V_411 )
) ;
}
return 0 ;
}
static int F_327 ( struct V_273 * V_273 , struct V_97 * V_97 )
{
return F_328 ( V_273 , V_97 , & V_412 ,
sizeof( struct V_401 ) ) ;
}
int F_329 ( struct V_413 * V_414 )
{
return F_330 ( & V_228 , V_414 ) ;
}
int F_331 ( struct V_413 * V_414 )
{
return F_332 ( & V_228 , V_414 ) ;
}
static int T_9 F_333 ( struct V_185 * V_185 )
{
#ifdef F_334
if ( ! F_335 ( L_7 , 0 , V_185 -> V_415 , & V_416 ) )
return - V_33 ;
#endif
return 0 ;
}
static void T_10 F_336 ( struct V_185 * V_185 )
{
#ifdef F_334
F_337 ( L_7 , V_185 -> V_415 ) ;
#endif
}
static void T_11 F_338 ( void )
{
struct V_193 * V_193 ;
int V_172 = 32 ;
V_193 = F_282 ( sizeof( * V_193 ) + F_198 ( V_172 ) , V_62 ) ;
if ( ! V_193 )
F_339 ( L_8 ) ;
F_120 () ;
V_191 [ V_24 ] . V_172 = V_172 ;
F_283 ( V_191 [ V_24 ] . V_193 , V_193 ) ;
V_191 [ V_24 ] . V_14 = V_417 ;
V_191 [ V_24 ] . V_220 = 1 ;
V_191 [ V_24 ] . V_3 = V_266 ;
F_129 () ;
}
static inline T_1 F_340 ( const void * V_135 , T_1 V_58 , T_1 V_418 )
{
const struct V_42 * V_43 = V_135 ;
struct V_181 V_179 ;
F_140 ( & V_179 , F_138 ( & V_43 -> V_2 ) , V_43 -> V_150 ) ;
return F_341 ( ( T_1 * ) & V_179 , V_419 / sizeof( T_1 ) , V_418 ) ;
}
static int T_11 F_342 ( void )
{
int V_59 ;
int V_104 = F_343 ( & V_211 , 0 ) ;
if ( V_104 != 0 )
goto V_17;
F_344 ( sizeof( struct V_235 ) > F_345 ( struct V_20 , V_167 ) ) ;
V_191 = F_54 ( V_218 , sizeof( * V_191 ) , V_62 ) ;
if ( ! V_191 )
goto F_339;
for ( V_59 = 0 ; V_59 < V_218 ; V_59 ++ ) {
if ( F_346 ( & V_191 [ V_59 ] . V_188 ,
& V_189 ) < 0 ) {
while ( -- V_59 > 0 )
F_347 ( & V_191 [ V_59 ] . V_188 ) ;
F_49 ( V_191 ) ;
goto F_339;
}
}
F_348 ( & V_13 ) ;
F_338 () ;
F_349 ( & V_420 ) ;
F_350 ( & V_421 ) ;
F_351 () ;
V_17:
return V_104 ;
F_339:
F_339 ( L_9 ) ;
}
