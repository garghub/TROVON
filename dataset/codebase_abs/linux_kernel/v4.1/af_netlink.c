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
if ( V_15 && V_7 -> V_14 )
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
if ( ! F_34 ( V_45 , & F_2 ( V_2 ) -> V_46 ) ) {
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
static int F_55 ( struct V_1 * V_2 , struct V_68 * V_69 ,
bool V_73 , bool V_56 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
void * * V_55 = NULL ;
unsigned int V_57 = 0 ;
int V_78 ;
V_75 = V_56 ? & V_43 -> V_56 : & V_43 -> V_54 ;
V_77 = V_56 ? & V_2 -> V_79 : & V_2 -> V_51 ;
if ( ! V_73 ) {
if ( F_56 ( & V_43 -> V_80 ) )
return - V_81 ;
if ( F_56 ( & V_75 -> V_82 ) )
return - V_81 ;
}
if ( V_69 -> V_71 ) {
if ( V_75 -> V_55 != NULL )
return - V_81 ;
if ( ( int ) V_69 -> V_83 <= 0 )
return - V_10 ;
if ( ! F_57 ( V_69 -> V_83 ) )
return - V_10 ;
if ( V_69 -> V_84 < V_85 )
return - V_10 ;
if ( ! F_58 ( V_69 -> V_84 , V_86 ) )
return - V_10 ;
V_75 -> V_87 = V_69 -> V_83 /
V_69 -> V_84 ;
if ( V_75 -> V_87 == 0 )
return - V_10 ;
if ( V_75 -> V_87 * V_69 -> V_71 !=
V_69 -> V_88 )
return - V_10 ;
V_57 = F_59 ( V_69 -> V_83 ) ;
V_55 = F_53 ( V_43 , V_69 , V_57 ) ;
if ( V_55 == NULL )
return - V_33 ;
} else {
if ( V_69 -> V_88 )
return - V_10 ;
}
V_78 = - V_81 ;
F_60 ( & V_43 -> V_89 ) ;
if ( V_73 || F_56 ( & V_43 -> V_80 ) == 0 ) {
V_78 = 0 ;
F_61 ( & V_77 -> V_90 ) ;
V_75 -> V_91 = V_69 -> V_88 - 1 ;
V_75 -> V_92 = 0 ;
V_75 -> V_93 = V_69 -> V_84 ;
V_75 -> V_94 = V_69 -> V_83 / V_67 ;
F_62 ( V_75 -> V_95 , V_69 -> V_71 ) ;
F_62 ( V_75 -> V_96 , V_57 ) ;
F_62 ( V_75 -> V_55 , V_55 ) ;
F_63 ( V_77 ) ;
F_64 ( & V_77 -> V_90 ) ;
F_65 ( F_56 ( & V_43 -> V_80 ) ) ;
}
F_66 ( & V_43 -> V_89 ) ;
if ( V_55 )
F_45 ( V_55 , V_57 , V_69 -> V_71 ) ;
return V_78 ;
}
static void F_67 ( struct V_97 * V_98 )
{
struct V_99 * V_99 = V_98 -> V_100 ;
struct V_101 * V_1 = V_99 -> V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_35 ( & F_2 ( V_2 ) -> V_80 ) ;
}
static void F_68 ( struct V_97 * V_98 )
{
struct V_99 * V_99 = V_98 -> V_100 ;
struct V_101 * V_1 = V_99 -> V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_69 ( & F_2 ( V_2 ) -> V_80 ) ;
}
static int F_70 ( struct V_99 * V_99 , struct V_101 * V_1 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
unsigned long V_103 , V_104 , V_105 ;
unsigned int V_59 ;
int V_78 = - V_10 ;
if ( V_98 -> V_106 )
return - V_10 ;
F_60 ( & V_43 -> V_89 ) ;
V_105 = 0 ;
for ( V_75 = & V_43 -> V_54 ; V_75 <= & V_43 -> V_56 ; V_75 ++ ) {
if ( V_75 -> V_55 == NULL )
continue;
V_105 += V_75 -> V_95 * V_75 -> V_94 * V_67 ;
}
if ( V_105 == 0 )
goto V_17;
V_104 = V_98 -> V_107 - V_98 -> V_108 ;
if ( V_104 != V_105 )
goto V_17;
V_103 = V_98 -> V_108 ;
for ( V_75 = & V_43 -> V_54 ; V_75 <= & V_43 -> V_56 ; V_75 ++ ) {
if ( V_75 -> V_55 == NULL )
continue;
for ( V_59 = 0 ; V_59 < V_75 -> V_95 ; V_59 ++ ) {
struct V_109 * V_109 ;
void * V_110 = V_75 -> V_55 [ V_59 ] ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_75 -> V_94 ; V_111 ++ ) {
V_109 = F_71 ( V_110 ) ;
V_78 = F_72 ( V_98 , V_103 , V_109 ) ;
if ( V_78 < 0 )
goto V_17;
V_103 += V_67 ;
V_110 += V_67 ;
}
}
}
F_35 ( & V_43 -> V_80 ) ;
V_98 -> V_112 = & V_113 ;
V_78 = 0 ;
V_17:
F_66 ( & V_43 -> V_89 ) ;
return V_78 ;
}
static void F_73 ( const struct V_114 * V_115 , unsigned int V_116 )
{
#if V_117 == 1
struct V_109 * V_118 , * V_119 ;
V_118 = F_71 ( V_115 + V_67 ) ;
V_119 = F_71 ( ( void * ) V_115 + V_85 + V_116 - 1 ) ;
while ( V_118 <= V_119 ) {
F_74 ( V_118 ) ;
V_118 ++ ;
}
#endif
}
static enum V_120 F_75 ( const struct V_114 * V_115 )
{
F_76 () ;
F_74 ( F_71 ( V_115 ) ) ;
return V_115 -> V_121 ;
}
static void F_77 ( struct V_114 * V_115 ,
enum V_120 V_122 )
{
F_78 () ;
V_115 -> V_121 = V_122 ;
F_74 ( F_71 ( V_115 ) ) ;
}
static struct V_114 *
F_79 ( const struct V_74 * V_75 , unsigned int V_123 )
{
unsigned int V_124 , V_125 ;
V_124 = V_123 / V_75 -> V_87 ;
V_125 = V_123 % V_75 -> V_87 ;
return V_75 -> V_55 [ V_124 ] + ( V_125 * V_75 -> V_93 ) ;
}
static struct V_114 *
F_80 ( const struct V_74 * V_75 , unsigned int V_123 ,
enum V_120 V_122 )
{
struct V_114 * V_115 ;
V_115 = F_79 ( V_75 , V_123 ) ;
if ( F_75 ( V_115 ) != V_122 )
return NULL ;
return V_115 ;
}
static struct V_114 *
F_81 ( const struct V_74 * V_75 ,
enum V_120 V_122 )
{
return F_80 ( V_75 , V_75 -> V_92 , V_122 ) ;
}
static struct V_114 *
F_82 ( const struct V_74 * V_75 ,
enum V_120 V_122 )
{
unsigned int V_126 ;
V_126 = V_75 -> V_92 ? V_75 -> V_92 - 1 : V_75 -> V_91 ;
return F_80 ( V_75 , V_126 , V_122 ) ;
}
static void F_83 ( struct V_74 * V_75 )
{
V_75 -> V_92 = V_75 -> V_92 != V_75 -> V_91 ? V_75 -> V_92 + 1 : 0 ;
}
static void F_84 ( struct V_74 * V_75 )
{
unsigned int V_92 = V_75 -> V_92 , V_123 = V_92 ;
const struct V_114 * V_115 ;
do {
V_115 = F_79 ( V_75 , V_123 ) ;
if ( V_115 -> V_121 == V_127 )
break;
if ( V_115 -> V_121 != V_128 )
break;
F_83 ( V_75 ) ;
} while ( V_75 -> V_92 != V_92 );
}
static bool F_85 ( struct V_42 * V_43 )
{
struct V_74 * V_75 = & V_43 -> V_54 ;
struct V_114 * V_115 ;
unsigned int V_129 ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL )
return false ;
V_129 = V_75 -> V_92 + V_75 -> V_91 / 2 ;
if ( V_129 > V_75 -> V_91 )
V_129 -= V_75 -> V_91 ;
V_115 = F_79 ( V_75 , V_129 ) ;
return V_115 -> V_121 == V_127 ;
}
static unsigned int F_86 ( struct V_99 * V_99 , struct V_101 * V_1 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_130 ;
int V_78 ;
if ( V_43 -> V_54 . V_55 != NULL ) {
while ( V_43 -> V_131 && F_85 ( V_43 ) ) {
V_78 = F_87 ( V_2 ) ;
if ( V_78 < 0 ) {
V_2 -> V_47 = - V_78 ;
V_2 -> V_49 ( V_2 ) ;
break;
}
}
F_36 ( V_2 ) ;
}
V_130 = F_88 ( V_99 , V_1 , V_52 ) ;
F_61 ( & V_2 -> V_51 . V_90 ) ;
if ( V_43 -> V_54 . V_55 ) {
F_84 ( & V_43 -> V_54 ) ;
if ( ! F_82 ( & V_43 -> V_54 , V_127 ) )
V_130 |= V_132 | V_133 ;
}
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_61 ( & V_2 -> V_79 . V_90 ) ;
if ( V_43 -> V_56 . V_55 ) {
if ( F_81 ( & V_43 -> V_56 , V_127 ) )
V_130 |= V_134 | V_135 ;
}
F_64 ( & V_2 -> V_79 . V_90 ) ;
return V_130 ;
}
static struct V_114 * F_89 ( struct V_20 * V_21 )
{
return (struct V_114 * ) ( V_21 -> V_92 - V_85 ) ;
}
static void F_90 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_114 * V_115 )
{
unsigned int V_104 ;
void * V_136 ;
V_104 = V_75 -> V_93 - V_85 ;
V_136 = ( void * ) V_115 + V_85 ;
V_21 -> V_92 = V_136 ;
V_21 -> V_136 = V_136 ;
F_91 ( V_21 ) ;
V_21 -> V_137 = V_21 -> V_138 + V_104 ;
V_21 -> V_58 = 0 ;
V_21 -> V_139 = V_140 ;
F_42 ( V_21 ) . V_3 |= V_53 ;
F_42 ( V_21 ) . V_2 = V_2 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_141 * V_142 ,
T_1 V_143 , T_1 V_144 ,
struct V_145 * V_146 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_114 * V_115 ;
struct V_20 * V_21 ;
unsigned int V_147 ;
int V_78 = 0 , V_58 = 0 ;
F_60 ( & V_43 -> V_89 ) ;
V_75 = & V_43 -> V_56 ;
V_147 = V_75 -> V_93 - V_85 ;
do {
unsigned int V_116 ;
V_115 = F_81 ( V_75 , V_148 ) ;
if ( V_115 == NULL ) {
if ( ! ( V_142 -> V_149 & V_150 ) &&
F_56 ( & V_43 -> V_56 . V_82 ) )
F_93 () ;
continue;
}
V_116 = F_94 ( V_115 -> V_116 ) ;
if ( V_116 > V_147 ) {
V_78 = - V_10 ;
goto V_17;
}
F_73 ( V_115 , V_116 ) ;
V_21 = F_95 ( V_116 , V_62 ) ;
if ( V_21 == NULL ) {
V_78 = - V_48 ;
goto V_17;
}
F_96 ( V_21 , V_116 ) ;
memcpy ( V_21 -> V_136 , ( void * ) V_115 + V_85 , V_116 ) ;
F_77 ( V_115 , V_127 ) ;
F_83 ( V_75 ) ;
F_42 ( V_21 ) . V_151 = V_43 -> V_151 ;
F_42 ( V_21 ) . V_144 = V_144 ;
F_42 ( V_21 ) . V_152 = V_146 -> V_152 ;
V_78 = F_97 ( V_2 , V_21 ) ;
if ( V_78 ) {
F_98 ( V_21 ) ;
goto V_17;
}
if ( F_5 ( V_144 ) ) {
F_35 ( & V_21 -> V_153 ) ;
F_99 ( V_2 , V_21 , V_143 , V_144 ,
V_62 ) ;
}
V_78 = F_100 ( V_2 , V_21 , V_143 ,
V_142 -> V_149 & V_150 ) ;
if ( V_78 < 0 )
goto V_17;
V_58 += V_78 ;
} while ( V_115 != NULL ||
( ! ( V_142 -> V_149 & V_150 ) &&
F_56 ( & V_43 -> V_56 . V_82 ) ) );
if ( V_58 > 0 )
V_78 = V_58 ;
V_17:
F_66 ( & V_43 -> V_89 ) ;
return V_78 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_114 * V_115 ;
V_115 = F_89 ( V_21 ) ;
V_115 -> V_116 = V_21 -> V_58 ;
V_115 -> V_154 = F_42 ( V_21 ) . V_144 ;
V_115 -> V_155 = F_42 ( V_21 ) . V_152 . V_156 ;
V_115 -> V_157 = F_102 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_158 ) ;
V_115 -> V_159 = F_104 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_160 ) ;
F_73 ( V_115 , V_115 -> V_116 ) ;
F_77 ( V_115 , V_148 ) ;
F_42 ( V_21 ) . V_3 |= V_161 ;
F_98 ( V_21 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 = & V_43 -> V_54 ;
struct V_114 * V_115 ;
F_61 ( & V_2 -> V_51 . V_90 ) ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL ) {
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_98 ( V_21 ) ;
F_33 ( V_2 ) ;
return;
}
F_83 ( V_75 ) ;
F_106 ( & V_2 -> V_51 , V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
V_115 -> V_116 = V_21 -> V_58 ;
V_115 -> V_154 = F_42 ( V_21 ) . V_144 ;
V_115 -> V_155 = F_42 ( V_21 ) . V_152 . V_156 ;
V_115 -> V_157 = F_102 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_158 ) ;
V_115 -> V_159 = F_104 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_160 ) ;
F_77 ( V_115 , V_162 ) ;
}
static void V_140 ( struct V_20 * V_21 )
{
#ifdef F_107
struct V_114 * V_115 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
if ( F_41 ( V_21 ) ) {
V_115 = F_89 ( V_21 ) ;
V_2 = F_42 ( V_21 ) . V_2 ;
if ( F_42 ( V_21 ) . V_3 & V_163 ) {
F_77 ( V_115 , V_127 ) ;
V_75 = & F_2 ( V_2 ) -> V_56 ;
} else {
if ( ! ( F_42 ( V_21 ) . V_3 & V_161 ) ) {
V_115 -> V_116 = 0 ;
F_77 ( V_115 , V_148 ) ;
}
V_75 = & F_2 ( V_2 ) -> V_54 ;
}
F_65 ( F_56 ( & V_75 -> V_82 ) == 0 ) ;
F_69 ( & V_75 -> V_82 ) ;
F_108 ( V_2 ) ;
V_21 -> V_92 = NULL ;
}
#endif
if ( F_46 ( V_21 -> V_92 ) ) {
if ( ! V_21 -> V_164 ||
! F_109 ( & ( F_110 ( V_21 ) -> V_165 ) ) )
F_47 ( V_21 -> V_92 ) ;
V_21 -> V_92 = NULL ;
}
if ( V_21 -> V_2 != NULL )
F_111 ( V_21 ) ;
}
static void F_112 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
F_65 ( V_21 -> V_2 != NULL ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_139 = V_140 ;
F_113 ( V_21 -> V_166 , & V_2 -> V_167 ) ;
F_114 ( V_2 , V_21 -> V_166 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_131 ) {
if ( V_43 -> V_168 . V_169 )
V_43 -> V_168 . V_169 ( & V_43 -> V_168 ) ;
F_14 ( V_43 -> V_168 . V_14 ) ;
F_98 ( V_43 -> V_168 . V_21 ) ;
}
F_116 ( & V_2 -> V_51 ) ;
#ifdef F_107
if ( 1 ) {
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_54 . V_55 )
F_55 ( V_2 , & V_69 , true , false ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_56 . V_55 )
F_55 ( V_2 , & V_69 , true , true ) ;
}
#endif
if ( ! F_117 ( V_2 , V_170 ) ) {
F_118 ( V_171 L_2 , V_2 ) ;
return;
}
F_65 ( F_56 ( & V_2 -> V_167 ) ) ;
F_65 ( F_56 ( & V_2 -> V_172 ) ) ;
F_65 ( F_2 ( V_2 ) -> V_173 ) ;
}
void F_119 ( void )
__acquires( T_4 )
{
F_120 () ;
F_121 ( & T_4 ) ;
if ( F_56 ( & V_174 ) ) {
F_122 ( V_52 , V_175 ) ;
F_123 ( & V_176 , & V_52 ) ;
for (; ; ) {
F_124 ( V_177 ) ;
if ( F_56 ( & V_174 ) == 0 )
break;
F_125 ( & T_4 ) ;
F_93 () ;
F_121 ( & T_4 ) ;
}
F_126 ( V_178 ) ;
F_127 ( & V_176 , & V_52 ) ;
}
}
void F_128 ( void )
__releases( T_4 )
{
F_125 ( & T_4 ) ;
F_129 ( & V_176 ) ;
}
static inline void
F_130 ( void )
{
F_131 ( & T_4 ) ;
F_35 ( & V_174 ) ;
F_132 ( & T_4 ) ;
}
static inline void
F_133 ( void )
{
if ( F_134 ( & V_174 ) )
F_129 ( & V_176 ) ;
}
static inline int F_135 ( struct V_179 * V_180 ,
const void * V_181 )
{
const struct V_182 * V_183 = V_180 -> V_184 ;
const struct V_42 * V_43 = V_181 ;
return V_43 -> V_151 != V_183 -> V_151 ||
! F_136 ( F_137 ( & V_43 -> V_2 ) , F_138 ( & V_183 -> V_185 ) ) ;
}
static void F_139 ( struct V_182 * V_180 ,
struct V_186 * V_186 , T_1 V_151 )
{
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
F_140 ( & V_180 -> V_185 , V_186 ) ;
V_180 -> V_151 = V_151 ;
}
static struct V_1 * F_141 ( struct V_187 * V_188 , T_1 V_151 ,
struct V_186 * V_186 )
{
struct V_182 V_180 ;
F_139 ( & V_180 , V_186 , V_151 ) ;
return F_142 ( & V_188 -> V_189 , & V_180 ,
V_190 ) ;
}
static int F_143 ( struct V_187 * V_188 , struct V_1 * V_2 )
{
struct V_182 V_180 ;
F_139 ( & V_180 , F_137 ( V_2 ) , F_2 ( V_2 ) -> V_151 ) ;
return F_144 ( & V_188 -> V_189 , & V_180 ,
& F_2 ( V_2 ) -> V_191 ,
V_190 ) ;
}
static struct V_1 * F_145 ( struct V_186 * V_186 , int V_35 , T_1 V_151 )
{
struct V_187 * V_188 = & V_192 [ V_35 ] ;
struct V_1 * V_2 ;
F_29 () ;
V_2 = F_141 ( V_188 , V_151 , V_186 ) ;
if ( V_2 )
F_146 ( V_2 ) ;
F_31 () ;
return V_2 ;
}
static void
F_147 ( struct V_1 * V_2 )
{
struct V_187 * V_193 = & V_192 [ V_2 -> V_22 ] ;
unsigned long V_130 ;
unsigned int V_59 ;
struct V_194 * V_194 ;
V_194 = F_148 ( V_193 -> V_194 ) ;
if ( ! V_194 )
return;
for ( V_59 = 0 ; V_59 < F_149 ( V_193 -> V_173 ) ; V_59 ++ ) {
V_130 = 0 ;
F_150 (sk, &tbl->mc_list) {
if ( V_59 < F_149 ( F_2 ( V_2 ) -> V_195 ) )
V_130 |= F_2 ( V_2 ) -> V_173 [ V_59 ] ;
}
V_194 -> V_196 [ V_59 ] = V_130 ;
}
}
static int F_151 ( struct V_1 * V_2 , T_1 V_151 )
{
struct V_187 * V_188 = & V_192 [ V_2 -> V_22 ] ;
int V_78 ;
F_152 ( V_2 ) ;
V_78 = - V_81 ;
if ( F_2 ( V_2 ) -> V_151 )
goto V_78;
V_78 = - V_33 ;
if ( V_197 > 32 &&
F_5 ( F_56 ( & V_188 -> V_189 . V_198 ) >= V_199 ) )
goto V_78;
F_2 ( V_2 ) -> V_151 = V_151 ;
F_146 ( V_2 ) ;
V_78 = F_143 ( V_188 , V_2 ) ;
if ( V_78 ) {
if ( V_78 == - V_200 )
V_78 = - V_201 ;
F_2 ( V_2 ) -> V_151 = 0 ;
F_108 ( V_2 ) ;
}
V_78:
F_153 ( V_2 ) ;
return V_78 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_187 * V_188 ;
V_188 = & V_192 [ V_2 -> V_22 ] ;
if ( ! F_155 ( & V_188 -> V_189 , & F_2 ( V_2 ) -> V_191 ,
V_190 ) ) {
F_65 ( F_56 ( & V_2 -> V_202 ) == 1 ) ;
F_156 ( V_2 ) ;
}
F_119 () ;
if ( F_2 ( V_2 ) -> V_203 ) {
F_157 ( V_2 ) ;
F_147 ( V_2 ) ;
}
if ( V_2 -> V_22 == V_30 )
F_35 ( & V_204 ) ;
F_128 () ;
}
static int F_158 ( struct V_186 * V_186 , struct V_101 * V_1 ,
struct V_205 * V_206 , int V_35 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
V_1 -> V_207 = & V_208 ;
V_2 = F_159 ( V_186 , V_209 , V_62 , & V_210 ) ;
if ( ! V_2 )
return - V_33 ;
F_160 ( V_1 , V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_206 ) {
V_43 -> V_206 = V_206 ;
} else {
V_43 -> V_206 = & V_43 -> V_211 ;
F_161 ( V_43 -> V_206 ) ;
}
F_162 ( & V_43 -> V_52 ) ;
#ifdef F_107
F_161 ( & V_43 -> V_89 ) ;
#endif
V_2 -> V_212 = F_115 ;
V_2 -> V_22 = V_35 ;
return 0 ;
}
static int F_163 ( struct V_186 * V_186 , struct V_101 * V_1 , int V_35 ,
int V_213 )
{
struct V_14 * V_14 = NULL ;
struct V_205 * V_206 ;
struct V_42 * V_43 ;
int (* F_164)( struct V_186 * V_186 , int V_5 );
void (* F_165)( struct V_186 * V_186 , int V_5 );
int V_78 = 0 ;
V_1 -> V_46 = V_214 ;
if ( V_1 -> type != V_215 && V_1 -> type != V_216 )
return - V_217 ;
if ( V_35 < 0 || V_35 >= V_218 )
return - V_219 ;
F_130 () ;
#ifdef F_166
if ( ! V_192 [ V_35 ] . V_220 ) {
F_133 () ;
F_167 ( L_3 , V_209 , V_35 ) ;
F_130 () ;
}
#endif
if ( V_192 [ V_35 ] . V_220 &&
F_168 ( V_192 [ V_35 ] . V_14 ) )
V_14 = V_192 [ V_35 ] . V_14 ;
else
V_78 = - V_219 ;
V_206 = V_192 [ V_35 ] . V_206 ;
F_164 = V_192 [ V_35 ] . F_164 ;
F_165 = V_192 [ V_35 ] . F_165 ;
F_133 () ;
if ( V_78 < 0 )
goto V_17;
V_78 = F_158 ( V_186 , V_1 , V_206 , V_35 ) ;
if ( V_78 < 0 )
goto V_221;
F_169 () ;
F_170 ( V_186 , & V_210 , 1 ) ;
F_171 () ;
V_43 = F_2 ( V_1 -> V_2 ) ;
V_43 -> V_14 = V_14 ;
V_43 -> V_222 = F_164 ;
V_43 -> V_223 = F_165 ;
V_17:
return V_78 ;
V_221:
F_14 ( V_14 ) ;
goto V_17;
}
static void F_172 ( struct V_224 * V_92 )
{
struct V_42 * V_43 = F_173 ( V_92 , struct V_42 , V_225 ) ;
F_108 ( & V_43 -> V_2 ) ;
}
static int F_174 ( struct V_101 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 ;
if ( ! V_2 )
return 0 ;
F_154 ( V_2 ) ;
F_175 ( V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_223 ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_43 -> V_195 ; V_59 ++ )
if ( F_39 ( V_59 , V_43 -> V_173 ) )
V_43 -> V_223 ( F_137 ( V_2 ) , V_59 + 1 ) ;
}
if ( V_2 -> V_22 == V_30 &&
F_109 ( & V_204 ) == 0 )
F_129 ( & V_226 ) ;
V_1 -> V_2 = NULL ;
F_176 ( & V_43 -> V_52 ) ;
F_116 ( & V_2 -> V_79 ) ;
if ( V_43 -> V_151 ) {
struct V_227 V_129 = {
. V_186 = F_137 ( V_2 ) ,
. V_35 = V_2 -> V_22 ,
. V_151 = V_43 -> V_151 ,
} ;
F_177 ( & V_228 ,
V_229 , & V_129 ) ;
}
F_14 ( V_43 -> V_14 ) ;
if ( F_1 ( V_2 ) ) {
F_119 () ;
F_178 ( V_192 [ V_2 -> V_22 ] . V_220 == 0 ) ;
if ( -- V_192 [ V_2 -> V_22 ] . V_220 == 0 ) {
struct V_194 * V_230 ;
V_230 = F_148 ( V_192 [ V_2 -> V_22 ] . V_194 ) ;
F_179 ( V_192 [ V_2 -> V_22 ] . V_194 , NULL ) ;
F_180 ( V_230 , V_225 ) ;
V_192 [ V_2 -> V_22 ] . V_14 = NULL ;
V_192 [ V_2 -> V_22 ] . F_164 = NULL ;
V_192 [ V_2 -> V_22 ] . F_165 = NULL ;
V_192 [ V_2 -> V_22 ] . V_3 = 0 ;
V_192 [ V_2 -> V_22 ] . V_220 = 0 ;
}
F_128 () ;
}
F_49 ( V_43 -> V_173 ) ;
V_43 -> V_173 = NULL ;
F_169 () ;
F_170 ( F_137 ( V_2 ) , & V_210 , - 1 ) ;
F_171 () ;
F_181 ( & V_43 -> V_225 , F_172 ) ;
return 0 ;
}
static int F_182 ( struct V_101 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_186 * V_186 = F_137 ( V_2 ) ;
struct V_187 * V_188 = & V_192 [ V_2 -> V_22 ] ;
T_5 V_151 = F_183 ( V_175 ) ;
int V_78 ;
static T_5 V_231 = - 4097 ;
V_232:
F_184 () ;
F_29 () ;
if ( F_141 ( V_188 , V_151 , V_186 ) ) {
V_151 = V_231 -- ;
if ( V_231 > - 4097 )
V_231 = - 4097 ;
F_31 () ;
goto V_232;
}
F_31 () ;
V_78 = F_151 ( V_2 , V_151 ) ;
if ( V_78 == - V_201 )
goto V_232;
if ( V_78 == - V_81 )
V_78 = 0 ;
return V_78 ;
}
bool F_185 ( const struct V_233 * V_234 ,
struct V_235 * V_236 , int V_237 )
{
return ( ( V_234 -> V_3 & V_238 ) ||
F_186 ( V_234 -> V_2 -> V_239 -> V_99 , V_236 , V_237 ) ) &&
F_187 ( V_236 , V_237 ) ;
}
bool F_188 ( const struct V_20 * V_21 ,
struct V_235 * V_236 , int V_237 )
{
return F_185 ( & F_42 ( V_21 ) , V_236 , V_237 ) ;
}
bool F_189 ( const struct V_20 * V_21 , int V_237 )
{
return F_188 ( V_21 , & V_240 , V_237 ) ;
}
bool F_190 ( const struct V_20 * V_21 , int V_237 )
{
return F_188 ( V_21 , F_137 ( V_21 -> V_2 ) -> V_236 , V_237 ) ;
}
static inline int F_191 ( const struct V_101 * V_1 , unsigned int V_241 )
{
return ( V_192 [ V_1 -> V_2 -> V_22 ] . V_3 & V_241 ) ||
F_187 ( F_137 ( V_1 -> V_2 ) -> V_236 , V_242 ) ;
}
static void
F_192 ( struct V_1 * V_2 , unsigned int V_203 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_203 && ! V_203 )
F_157 ( V_2 ) ;
else if ( ! V_43 -> V_203 && V_203 )
F_193 ( V_2 , & V_192 [ V_2 -> V_22 ] . V_243 ) ;
V_43 -> V_203 = V_203 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_173 ;
unsigned long * V_244 ;
int V_78 = 0 ;
F_119 () ;
V_173 = V_192 [ V_2 -> V_22 ] . V_173 ;
if ( ! V_192 [ V_2 -> V_22 ] . V_220 ) {
V_78 = - V_245 ;
goto V_246;
}
if ( V_43 -> V_195 >= V_173 )
goto V_246;
V_244 = F_195 ( V_43 -> V_173 , F_196 ( V_173 ) , V_34 ) ;
if ( V_244 == NULL ) {
V_78 = - V_33 ;
goto V_246;
}
memset ( ( char * ) V_244 + F_196 ( V_43 -> V_195 ) , 0 ,
F_196 ( V_173 ) - F_196 ( V_43 -> V_195 ) ) ;
V_43 -> V_173 = V_244 ;
V_43 -> V_195 = V_173 ;
V_246:
F_128 () ;
return V_78 ;
}
static void F_197 ( int V_5 , long unsigned int V_173 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_247 ;
if ( ! V_43 -> V_223 )
return;
for ( V_247 = 0 ; V_247 < V_5 ; V_247 ++ )
if ( F_39 ( V_247 , & V_173 ) )
V_43 -> V_223 ( F_137 ( V_2 ) , V_247 + 1 ) ;
}
static int V_222 ( struct V_101 * V_1 , struct V_248 * V_249 ,
int V_250 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_186 * V_186 = F_137 ( V_2 ) ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_249 ;
int V_78 ;
long unsigned int V_173 = V_252 -> V_253 ;
if ( V_250 < sizeof( struct V_251 ) )
return - V_10 ;
if ( V_252 -> V_254 != V_255 )
return - V_10 ;
if ( V_173 ) {
if ( ! F_191 ( V_1 , V_256 ) )
return - V_257 ;
V_78 = F_194 ( V_2 ) ;
if ( V_78 )
return V_78 ;
}
if ( V_43 -> V_151 )
if ( V_252 -> V_258 != V_43 -> V_151 )
return - V_10 ;
if ( V_43 -> V_222 && V_173 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_43 -> V_195 ; V_5 ++ ) {
if ( ! F_39 ( V_5 , & V_173 ) )
continue;
V_78 = V_43 -> V_222 ( V_186 , V_5 + 1 ) ;
if ( ! V_78 )
continue;
F_197 ( V_5 , V_173 , V_2 ) ;
return V_78 ;
}
}
if ( ! V_43 -> V_151 ) {
V_78 = V_252 -> V_258 ?
F_151 ( V_2 , V_252 -> V_258 ) :
F_182 ( V_1 ) ;
if ( V_78 ) {
F_197 ( V_43 -> V_195 , V_173 , V_2 ) ;
return V_78 ;
}
}
if ( ! V_173 && ( V_43 -> V_173 == NULL || ! ( T_1 ) V_43 -> V_173 [ 0 ] ) )
return 0 ;
F_119 () ;
F_192 ( V_2 , V_43 -> V_203 +
F_198 ( V_173 ) -
F_198 ( V_43 -> V_173 [ 0 ] ) ) ;
V_43 -> V_173 [ 0 ] = ( V_43 -> V_173 [ 0 ] & ~ 0xffffffffUL ) | V_173 ;
F_147 ( V_2 ) ;
F_128 () ;
return 0 ;
}
static int F_199 ( struct V_101 * V_1 , struct V_248 * V_249 ,
int V_259 , int V_3 )
{
int V_78 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_249 ;
if ( V_259 < sizeof( V_249 -> V_260 ) )
return - V_10 ;
if ( V_249 -> V_260 == V_261 ) {
V_2 -> V_262 = V_263 ;
V_43 -> V_143 = 0 ;
V_43 -> V_144 = 0 ;
return 0 ;
}
if ( V_249 -> V_260 != V_255 )
return - V_10 ;
if ( ( V_252 -> V_253 || V_252 -> V_258 ) &&
! F_191 ( V_1 , V_264 ) )
return - V_257 ;
if ( ! V_43 -> V_151 )
V_78 = F_182 ( V_1 ) ;
if ( V_78 == 0 ) {
V_2 -> V_262 = V_265 ;
V_43 -> V_143 = V_252 -> V_258 ;
V_43 -> V_144 = F_200 ( V_252 -> V_253 ) ;
}
return V_78 ;
}
static int F_201 ( struct V_101 * V_1 , struct V_248 * V_249 ,
int * V_250 , int V_266 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_202 ( struct V_251 * , V_252 , V_249 ) ;
V_252 -> V_254 = V_255 ;
V_252 -> V_267 = 0 ;
* V_250 = sizeof( * V_252 ) ;
if ( V_266 ) {
V_252 -> V_258 = V_43 -> V_143 ;
V_252 -> V_253 = F_3 ( V_43 -> V_144 ) ;
} else {
V_252 -> V_258 = V_43 -> V_151 ;
V_252 -> V_253 = V_43 -> V_173 ? V_43 -> V_173 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_203 ( struct V_1 * V_268 , T_1 V_151 )
{
struct V_1 * V_1 ;
struct V_42 * V_43 ;
V_1 = F_145 ( F_137 ( V_268 ) , V_268 -> V_22 , V_151 ) ;
if ( ! V_1 )
return F_204 ( - V_269 ) ;
V_43 = F_2 ( V_1 ) ;
if ( V_1 -> V_262 == V_265 &&
V_43 -> V_143 != F_2 ( V_268 ) -> V_151 ) {
F_108 ( V_1 ) ;
return F_204 ( - V_269 ) ;
}
return V_1 ;
}
struct V_1 * F_205 ( struct V_99 * V_270 )
{
struct V_271 * V_271 = F_206 ( V_270 ) ;
struct V_1 * V_1 ;
if ( ! F_207 ( V_271 -> V_272 ) )
return F_204 ( - V_273 ) ;
V_1 = F_208 ( V_271 ) -> V_2 ;
if ( V_1 -> V_274 != V_255 )
return F_204 ( - V_10 ) ;
F_146 ( V_1 ) ;
return V_1 ;
}
static struct V_20 * F_209 ( unsigned int V_104 ,
int V_275 )
{
struct V_20 * V_21 ;
void * V_136 ;
if ( V_104 <= V_276 || V_275 )
return F_95 ( V_104 , V_62 ) ;
V_104 = F_210 ( V_104 ) +
F_210 ( sizeof( struct V_277 ) ) ;
V_136 = F_211 ( V_104 ) ;
if ( V_136 == NULL )
return NULL ;
V_21 = F_212 ( V_136 , V_104 ) ;
if ( V_21 == NULL )
F_47 ( V_136 ) ;
else
V_21 -> V_139 = V_140 ;
return V_21 ;
}
int F_213 ( struct V_1 * V_2 , struct V_20 * V_21 ,
long * V_278 , struct V_1 * V_268 )
{
struct V_42 * V_43 ;
V_43 = F_2 ( V_2 ) ;
if ( ( F_56 ( & V_2 -> V_167 ) > V_2 -> V_279 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_41 ( V_21 ) ) {
F_122 ( V_52 , V_175 ) ;
if ( ! * V_278 ) {
if ( ! V_268 || F_1 ( V_268 ) )
F_33 ( V_2 ) ;
F_108 ( V_2 ) ;
F_98 ( V_21 ) ;
return - V_280 ;
}
F_126 ( V_281 ) ;
F_214 ( & V_43 -> V_52 , & V_52 ) ;
if ( ( F_56 ( & V_2 -> V_167 ) > V_2 -> V_279 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_117 ( V_2 , V_170 ) )
* V_278 = F_215 ( * V_278 ) ;
F_126 ( V_178 ) ;
F_127 ( & V_43 -> V_52 , & V_52 ) ;
F_108 ( V_2 ) ;
if ( F_216 ( V_175 ) ) {
F_98 ( V_21 ) ;
return F_217 ( * V_278 ) ;
}
return 1 ;
}
F_112 ( V_21 , V_2 ) ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = V_21 -> V_58 ;
F_28 ( V_21 ) ;
#ifdef F_107
if ( F_41 ( V_21 ) )
F_101 ( V_2 , V_21 ) ;
else if ( F_43 ( V_2 ) )
F_105 ( V_2 , V_21 ) ;
else
#endif
F_219 ( & V_2 -> V_51 , V_21 ) ;
V_2 -> V_282 ( V_2 ) ;
return V_58 ;
}
int F_220 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = F_218 ( V_2 , V_21 ) ;
F_108 ( V_2 ) ;
return V_58 ;
}
void F_221 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
F_98 ( V_21 ) ;
F_108 ( V_2 ) ;
}
static struct V_20 * F_222 ( struct V_20 * V_21 , T_2 V_283 )
{
int V_284 ;
F_65 ( V_21 -> V_2 != NULL ) ;
if ( F_41 ( V_21 ) )
return V_21 ;
V_284 = V_21 -> V_137 - V_21 -> V_138 ;
if ( F_46 ( V_21 -> V_92 ) || V_284 * 2 < V_21 -> V_166 )
return V_21 ;
if ( F_223 ( V_21 ) ) {
struct V_20 * V_32 = F_20 ( V_21 , V_283 ) ;
if ( ! V_32 )
return V_21 ;
F_224 ( V_21 ) ;
V_21 = V_32 ;
}
if ( ! F_225 ( V_21 , 0 , - V_284 , V_283 ) )
V_21 -> V_166 -= V_284 ;
return V_21 ;
}
static int F_226 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_1 * V_268 )
{
int V_19 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
V_19 = - V_269 ;
if ( V_43 -> V_285 != NULL ) {
V_19 = V_21 -> V_58 ;
F_112 ( V_21 , V_2 ) ;
F_42 ( V_21 ) . V_2 = V_268 ;
F_32 ( V_2 , V_268 , V_21 ) ;
V_43 -> V_285 ( V_21 ) ;
F_224 ( V_21 ) ;
} else {
F_98 ( V_21 ) ;
}
F_108 ( V_2 ) ;
return V_19 ;
}
int F_100 ( struct V_1 * V_268 , struct V_20 * V_21 ,
T_1 V_151 , int V_286 )
{
struct V_1 * V_2 ;
int V_78 ;
long V_278 ;
V_21 = F_222 ( V_21 , F_227 () ) ;
V_278 = F_228 ( V_268 , V_286 ) ;
V_232:
V_2 = F_203 ( V_268 , V_151 ) ;
if ( F_229 ( V_2 ) ) {
F_98 ( V_21 ) ;
return F_230 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_226 ( V_2 , V_21 , V_268 ) ;
if ( F_231 ( V_2 , V_21 ) ) {
V_78 = V_21 -> V_58 ;
F_98 ( V_21 ) ;
F_108 ( V_2 ) ;
return V_78 ;
}
V_78 = F_213 ( V_2 , V_21 , & V_278 , V_268 ) ;
if ( V_78 == 1 )
goto V_232;
if ( V_78 )
return V_78 ;
return F_220 ( V_2 , V_21 ) ;
}
struct V_20 * F_232 ( struct V_1 * V_268 , unsigned int V_104 ,
T_1 V_143 , T_2 V_287 )
{
#ifdef F_107
struct V_1 * V_2 = NULL ;
struct V_20 * V_21 ;
struct V_74 * V_75 ;
struct V_114 * V_115 ;
unsigned int V_147 ;
V_2 = F_203 ( V_268 , V_143 ) ;
if ( F_229 ( V_2 ) )
goto V_17;
V_75 = & F_2 ( V_2 ) -> V_54 ;
if ( V_75 -> V_55 == NULL )
goto V_288;
if ( V_75 -> V_93 - V_85 < V_104 )
goto V_288;
V_21 = F_233 ( V_287 ) ;
if ( V_21 == NULL )
goto V_72;
F_61 ( & V_2 -> V_51 . V_90 ) ;
if ( V_75 -> V_55 == NULL )
goto V_289;
V_147 = V_75 -> V_93 - V_85 ;
if ( V_147 < V_104 )
goto V_289;
F_84 ( V_75 ) ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL )
goto V_290;
F_90 ( V_21 , V_2 , V_75 , V_115 ) ;
F_77 ( V_115 , V_291 ) ;
F_35 ( & V_75 -> V_82 ) ;
F_83 ( V_75 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
return V_21 ;
V_290:
F_98 ( V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_33 ( V_2 ) ;
V_72:
F_108 ( V_2 ) ;
return NULL ;
V_289:
F_98 ( V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
V_288:
F_108 ( V_2 ) ;
V_17:
#endif
return F_95 ( V_104 , V_287 ) ;
}
int F_234 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_292 = 0 ;
struct V_194 * V_194 ;
F_178 ( ! F_1 ( V_2 ) ) ;
F_29 () ;
V_194 = F_235 ( V_192 [ V_2 -> V_22 ] . V_194 ) ;
if ( V_194 && V_5 - 1 < V_192 [ V_2 -> V_22 ] . V_173 )
V_292 = F_39 ( V_5 - 1 , V_194 -> V_196 ) ;
F_31 () ;
return V_292 ;
}
static int F_236 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( F_56 ( & V_2 -> V_167 ) <= V_2 -> V_279 &&
! F_39 ( V_45 , & V_43 -> V_46 ) ) {
F_112 ( V_21 , V_2 ) ;
F_218 ( V_2 , V_21 ) ;
return F_56 ( & V_2 -> V_167 ) > ( V_2 -> V_279 >> 1 ) ;
}
return - 1 ;
}
static void F_237 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_295 ;
if ( V_294 -> V_296 == V_2 )
return;
if ( V_43 -> V_151 == V_294 -> V_151 || V_294 -> V_5 - 1 >= V_43 -> V_195 ||
! F_39 ( V_294 -> V_5 - 1 , V_43 -> V_173 ) )
return;
if ( ! F_136 ( F_137 ( V_2 ) , V_294 -> V_186 ) )
return;
if ( V_294 -> V_297 ) {
F_33 ( V_2 ) ;
return;
}
F_146 ( V_2 ) ;
if ( V_294 -> V_298 == NULL ) {
if ( F_223 ( V_294 -> V_21 ) ) {
V_294 -> V_298 = F_20 ( V_294 -> V_21 , V_294 -> V_283 ) ;
} else {
V_294 -> V_298 = F_238 ( V_294 -> V_21 ) ;
F_239 ( V_294 -> V_298 ) ;
}
}
if ( V_294 -> V_298 == NULL ) {
F_33 ( V_2 ) ;
V_294 -> V_297 = 1 ;
if ( V_43 -> V_3 & V_299 )
V_294 -> V_300 = 1 ;
} else if ( V_294 -> V_301 && V_294 -> V_301 ( V_2 , V_294 -> V_298 , V_294 -> V_302 ) ) {
F_98 ( V_294 -> V_298 ) ;
V_294 -> V_298 = NULL ;
} else if ( F_231 ( V_2 , V_294 -> V_298 ) ) {
F_98 ( V_294 -> V_298 ) ;
V_294 -> V_298 = NULL ;
} else if ( ( V_295 = F_236 ( V_2 , V_294 -> V_298 ) ) < 0 ) {
F_33 ( V_2 ) ;
if ( V_43 -> V_3 & V_299 )
V_294 -> V_300 = 1 ;
} else {
V_294 -> V_303 |= V_295 ;
V_294 -> V_304 = 1 ;
V_294 -> V_298 = NULL ;
}
F_108 ( V_2 ) ;
}
int F_240 ( struct V_1 * V_268 , struct V_20 * V_21 , T_1 V_151 ,
T_1 V_5 , T_2 V_283 ,
int (* F_241)( struct V_1 * V_305 , struct V_20 * V_21 , void * V_136 ) ,
void * V_306 )
{
struct V_186 * V_186 = F_137 ( V_268 ) ;
struct V_293 V_307 ;
struct V_1 * V_2 ;
V_21 = F_222 ( V_21 , V_283 ) ;
V_307 . V_296 = V_268 ;
V_307 . V_186 = V_186 ;
V_307 . V_151 = V_151 ;
V_307 . V_5 = V_5 ;
V_307 . V_297 = 0 ;
V_307 . V_300 = 0 ;
V_307 . V_303 = 0 ;
V_307 . V_304 = 0 ;
V_307 . V_283 = V_283 ;
V_307 . V_21 = V_21 ;
V_307 . V_298 = NULL ;
V_307 . V_301 = F_241 ;
V_307 . V_302 = V_306 ;
F_130 () ;
F_150 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_237 ( V_2 , & V_307 ) ;
F_224 ( V_21 ) ;
F_133 () ;
if ( V_307 . V_300 ) {
F_98 ( V_307 . V_298 ) ;
return - V_48 ;
}
F_224 ( V_307 . V_298 ) ;
if ( V_307 . V_304 ) {
if ( V_307 . V_303 && ( V_283 & V_308 ) )
F_242 () ;
return 0 ;
}
return - V_309 ;
}
int F_99 ( struct V_1 * V_268 , struct V_20 * V_21 , T_1 V_151 ,
T_1 V_5 , T_2 V_283 )
{
return F_240 ( V_268 , V_21 , V_151 , V_5 , V_283 ,
NULL , NULL ) ;
}
static int F_243 ( struct V_1 * V_2 , struct V_310 * V_294 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_19 = 0 ;
if ( V_2 == V_294 -> V_296 )
goto V_17;
if ( ! F_136 ( F_137 ( V_2 ) , F_137 ( V_294 -> V_296 ) ) )
goto V_17;
if ( V_43 -> V_151 == V_294 -> V_151 || V_294 -> V_5 - 1 >= V_43 -> V_195 ||
! F_39 ( V_294 -> V_5 - 1 , V_43 -> V_173 ) )
goto V_17;
if ( V_294 -> V_311 == V_48 && V_43 -> V_3 & V_44 ) {
V_19 = 1 ;
goto V_17;
}
V_2 -> V_47 = V_294 -> V_311 ;
V_2 -> V_49 ( V_2 ) ;
V_17:
return V_19 ;
}
int F_244 ( struct V_1 * V_268 , T_1 V_151 , T_1 V_5 , int V_311 )
{
struct V_310 V_307 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_307 . V_296 = V_268 ;
V_307 . V_151 = V_151 ;
V_307 . V_5 = V_5 ;
V_307 . V_311 = - V_311 ;
F_131 ( & T_4 ) ;
F_150 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_19 += F_243 ( V_2 , & V_307 ) ;
F_132 ( & T_4 ) ;
return V_19 ;
}
static void F_245 ( struct V_42 * V_43 ,
unsigned int V_5 ,
int V_312 )
{
int V_230 , V_313 = ! ! V_312 , V_203 ;
V_230 = F_39 ( V_5 - 1 , V_43 -> V_173 ) ;
V_203 = V_43 -> V_203 - V_230 + V_313 ;
if ( V_313 )
F_246 ( V_5 - 1 , V_43 -> V_173 ) ;
else
F_247 ( V_5 - 1 , V_43 -> V_173 ) ;
F_192 ( & V_43 -> V_2 , V_203 ) ;
F_147 ( & V_43 -> V_2 ) ;
}
static int F_248 ( struct V_101 * V_1 , int V_314 , int V_315 ,
char T_6 * V_316 , unsigned int V_317 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_295 = 0 ;
int V_78 ;
if ( V_314 != V_318 )
return - V_319 ;
if ( V_315 != V_320 && V_315 != V_321 &&
V_317 >= sizeof( int ) &&
F_249 ( V_295 , ( unsigned int T_6 * ) V_316 ) )
return - V_322 ;
switch ( V_315 ) {
case V_323 :
if ( V_295 )
V_43 -> V_3 |= V_324 ;
else
V_43 -> V_3 &= ~ V_324 ;
V_78 = 0 ;
break;
case V_325 :
case V_326 : {
if ( ! F_191 ( V_1 , V_256 ) )
return - V_257 ;
V_78 = F_194 ( V_2 ) ;
if ( V_78 )
return V_78 ;
if ( ! V_295 || V_295 - 1 >= V_43 -> V_195 )
return - V_10 ;
if ( V_315 == V_325 && V_43 -> V_222 ) {
V_78 = V_43 -> V_222 ( F_137 ( V_2 ) , V_295 ) ;
if ( V_78 )
return V_78 ;
}
F_119 () ;
F_245 ( V_43 , V_295 ,
V_315 == V_325 ) ;
F_128 () ;
if ( V_315 == V_326 && V_43 -> V_223 )
V_43 -> V_223 ( F_137 ( V_2 ) , V_295 ) ;
V_78 = 0 ;
break;
}
case V_327 :
if ( V_295 )
V_43 -> V_3 |= V_299 ;
else
V_43 -> V_3 &= ~ V_299 ;
V_78 = 0 ;
break;
case V_328 :
if ( V_295 ) {
V_43 -> V_3 |= V_44 ;
F_38 ( V_45 , & V_43 -> V_46 ) ;
F_40 ( & V_43 -> V_52 ) ;
} else {
V_43 -> V_3 &= ~ V_44 ;
}
V_78 = 0 ;
break;
#ifdef F_107
case V_320 :
case V_321 : {
struct V_68 V_69 ;
if ( ! F_250 ( V_242 ) )
return - V_257 ;
if ( V_317 < sizeof( V_69 ) )
return - V_10 ;
if ( F_251 ( & V_69 , V_316 , sizeof( V_69 ) ) )
return - V_322 ;
V_78 = F_55 ( V_2 , & V_69 , false ,
V_315 == V_321 ) ;
break;
}
#endif
default:
V_78 = - V_319 ;
}
return V_78 ;
}
static int F_252 ( struct V_101 * V_1 , int V_314 , int V_315 ,
char T_6 * V_316 , int T_6 * V_317 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_58 , V_295 , V_78 ;
if ( V_314 != V_318 )
return - V_319 ;
if ( F_249 ( V_58 , V_317 ) )
return - V_322 ;
if ( V_58 < 0 )
return - V_10 ;
switch ( V_315 ) {
case V_323 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_295 = V_43 -> V_3 & V_324 ? 1 : 0 ;
if ( F_253 ( V_58 , V_317 ) ||
F_253 ( V_295 , V_316 ) )
return - V_322 ;
V_78 = 0 ;
break;
case V_327 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_295 = V_43 -> V_3 & V_299 ? 1 : 0 ;
if ( F_253 ( V_58 , V_317 ) ||
F_253 ( V_295 , V_316 ) )
return - V_322 ;
V_78 = 0 ;
break;
case V_328 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_295 = V_43 -> V_3 & V_44 ? 1 : 0 ;
if ( F_253 ( V_58 , V_317 ) ||
F_253 ( V_295 , V_316 ) )
return - V_322 ;
V_78 = 0 ;
break;
default:
V_78 = - V_319 ;
}
return V_78 ;
}
static void F_254 ( struct V_141 * V_142 , struct V_20 * V_21 )
{
struct V_329 V_307 ;
V_307 . V_5 = F_42 ( V_21 ) . V_144 ;
F_255 ( V_142 , V_318 , V_323 , sizeof( V_307 ) , & V_307 ) ;
}
static int F_256 ( struct V_101 * V_1 , struct V_141 * V_142 , T_7 V_58 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_202 ( struct V_251 * , V_249 , V_142 -> V_330 ) ;
T_1 V_143 ;
T_1 V_144 ;
struct V_20 * V_21 ;
int V_78 ;
struct V_145 V_146 ;
T_1 V_331 = 0 ;
if ( V_142 -> V_149 & V_332 )
return - V_333 ;
V_78 = F_257 ( V_1 , V_142 , & V_146 , true ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_142 -> V_334 ) {
V_78 = - V_10 ;
if ( V_249 -> V_254 != V_255 )
goto V_17;
V_143 = V_249 -> V_258 ;
V_144 = F_200 ( V_249 -> V_253 ) ;
V_78 = - V_257 ;
if ( ( V_144 || V_143 ) &&
! F_191 ( V_1 , V_264 ) )
goto V_17;
V_331 |= V_238 ;
} else {
V_143 = V_43 -> V_143 ;
V_144 = V_43 -> V_144 ;
}
if ( ! V_43 -> V_151 ) {
V_78 = F_182 ( V_1 ) ;
if ( V_78 )
goto V_17;
}
if ( F_44 ( V_2 ) &&
V_142 -> V_335 . type == V_336 &&
V_142 -> V_335 . V_337 == 1 &&
V_142 -> V_335 . V_338 -> V_339 == NULL ) {
V_78 = F_92 ( V_2 , V_142 , V_143 , V_144 ,
& V_146 ) ;
goto V_17;
}
V_78 = - V_340 ;
if ( V_58 > V_2 -> V_341 - 32 )
goto V_17;
V_78 = - V_48 ;
V_21 = F_209 ( V_58 , V_144 ) ;
if ( V_21 == NULL )
goto V_17;
F_42 ( V_21 ) . V_151 = V_43 -> V_151 ;
F_42 ( V_21 ) . V_144 = V_144 ;
F_42 ( V_21 ) . V_152 = V_146 . V_152 ;
F_42 ( V_21 ) . V_3 = V_331 ;
V_78 = - V_322 ;
if ( F_258 ( F_259 ( V_21 , V_58 ) , V_142 , V_58 ) ) {
F_98 ( V_21 ) ;
goto V_17;
}
V_78 = F_97 ( V_2 , V_21 ) ;
if ( V_78 ) {
F_98 ( V_21 ) ;
goto V_17;
}
if ( V_144 ) {
F_35 ( & V_21 -> V_153 ) ;
F_99 ( V_2 , V_21 , V_143 , V_144 , V_62 ) ;
}
V_78 = F_100 ( V_2 , V_21 , V_143 , V_142 -> V_149 & V_150 ) ;
V_17:
F_260 ( & V_146 ) ;
return V_78 ;
}
static int F_261 ( struct V_101 * V_1 , struct V_141 * V_142 , T_7 V_58 ,
int V_3 )
{
struct V_145 V_146 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_342 = V_3 & V_150 ;
T_7 V_343 ;
struct V_20 * V_21 , * V_344 ;
int V_78 , V_19 ;
if ( V_3 & V_332 )
return - V_333 ;
V_343 = 0 ;
V_21 = F_262 ( V_2 , V_3 , V_342 , & V_78 ) ;
if ( V_21 == NULL )
goto V_17;
V_344 = V_21 ;
#ifdef F_263
if ( F_5 ( F_110 ( V_21 ) -> V_345 ) ) {
if ( V_3 & V_346 )
V_344 = F_110 ( V_21 ) -> V_345 ;
}
#endif
V_43 -> V_347 = F_264 ( V_43 -> V_347 , V_58 ) ;
V_43 -> V_347 = F_265 ( T_7 , V_43 -> V_347 ,
16384 ) ;
V_343 = V_344 -> V_58 ;
if ( V_58 < V_343 ) {
V_142 -> V_149 |= V_348 ;
V_343 = V_58 ;
}
F_266 ( V_344 ) ;
V_78 = F_267 ( V_344 , 0 , V_142 , V_343 ) ;
if ( V_142 -> V_330 ) {
F_202 ( struct V_251 * , V_249 , V_142 -> V_330 ) ;
V_249 -> V_254 = V_255 ;
V_249 -> V_267 = 0 ;
V_249 -> V_258 = F_42 ( V_21 ) . V_151 ;
V_249 -> V_253 = F_3 ( F_42 ( V_21 ) . V_144 ) ;
V_142 -> V_334 = sizeof( * V_249 ) ;
}
if ( V_43 -> V_3 & V_324 )
F_254 ( V_142 , V_21 ) ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_152 = * F_268 ( V_21 ) ;
if ( V_3 & V_348 )
V_343 = V_344 -> V_58 ;
F_269 ( V_2 , V_21 ) ;
if ( V_43 -> V_131 &&
F_56 ( & V_2 -> V_167 ) <= V_2 -> V_279 / 2 ) {
V_19 = F_87 ( V_2 ) ;
if ( V_19 ) {
V_2 -> V_47 = - V_19 ;
V_2 -> V_49 ( V_2 ) ;
}
}
F_270 ( V_1 , V_142 , & V_146 , V_3 ) ;
V_17:
F_36 ( V_2 ) ;
return V_78 ? : V_343 ;
}
static void F_271 ( struct V_1 * V_2 )
{
F_272 () ;
}
struct V_1 *
F_273 ( struct V_186 * V_186 , int V_349 , struct V_14 * V_14 ,
struct V_350 * V_351 )
{
struct V_101 * V_1 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_194 * V_194 = NULL ;
struct V_205 * V_206 = V_351 ? V_351 -> V_206 : NULL ;
unsigned int V_173 ;
F_178 ( ! V_192 ) ;
if ( V_349 < 0 || V_349 >= V_218 )
return NULL ;
if ( F_274 ( V_209 , V_216 , V_349 , & V_1 ) )
return NULL ;
if ( F_158 ( & V_352 , V_1 , V_206 , V_349 ) < 0 )
goto V_353;
V_2 = V_1 -> V_2 ;
F_275 ( V_2 , V_186 ) ;
if ( ! V_351 || V_351 -> V_173 < 32 )
V_173 = 32 ;
else
V_173 = V_351 -> V_173 ;
V_194 = F_276 ( sizeof( * V_194 ) + F_196 ( V_173 ) , V_62 ) ;
if ( ! V_194 )
goto V_354;
V_2 -> V_282 = F_271 ;
if ( V_351 && V_351 -> V_355 )
F_2 ( V_2 ) -> V_285 = V_351 -> V_355 ;
if ( F_151 ( V_2 , 0 ) )
goto V_354;
V_43 = F_2 ( V_2 ) ;
V_43 -> V_3 |= V_4 ;
F_119 () ;
if ( ! V_192 [ V_349 ] . V_220 ) {
V_192 [ V_349 ] . V_173 = V_173 ;
F_277 ( V_192 [ V_349 ] . V_194 , V_194 ) ;
V_192 [ V_349 ] . V_206 = V_206 ;
V_192 [ V_349 ] . V_14 = V_14 ;
if ( V_351 ) {
V_192 [ V_349 ] . F_164 = V_351 -> F_164 ;
V_192 [ V_349 ] . F_165 = V_351 -> F_165 ;
V_192 [ V_349 ] . V_3 = V_351 -> V_3 ;
if ( V_351 -> V_356 )
V_192 [ V_349 ] . V_356 = V_351 -> V_356 ;
}
V_192 [ V_349 ] . V_220 = 1 ;
} else {
F_49 ( V_194 ) ;
V_192 [ V_349 ] . V_220 ++ ;
}
F_128 () ;
return V_2 ;
V_354:
F_49 ( V_194 ) ;
F_278 ( V_2 ) ;
return NULL ;
V_353:
F_279 ( V_1 ) ;
return NULL ;
}
void
F_278 ( struct V_1 * V_2 )
{
F_280 ( V_2 ) ;
}
int F_281 ( struct V_1 * V_2 , unsigned int V_173 )
{
struct V_194 * V_313 , * V_230 ;
struct V_187 * V_193 = & V_192 [ V_2 -> V_22 ] ;
if ( V_173 < 32 )
V_173 = 32 ;
if ( F_196 ( V_193 -> V_173 ) < F_196 ( V_173 ) ) {
V_313 = F_276 ( sizeof( * V_313 ) + F_196 ( V_173 ) , V_34 ) ;
if ( ! V_313 )
return - V_33 ;
V_230 = F_148 ( V_193 -> V_194 ) ;
memcpy ( V_313 -> V_196 , V_230 -> V_196 , F_196 ( V_193 -> V_173 ) ) ;
F_277 ( V_193 -> V_194 , V_313 ) ;
F_180 ( V_230 , V_225 ) ;
}
V_193 -> V_173 = V_173 ;
return 0 ;
}
int F_282 ( struct V_1 * V_2 , unsigned int V_173 )
{
int V_78 ;
F_119 () ;
V_78 = F_281 ( V_2 , V_173 ) ;
F_128 () ;
return V_78 ;
}
void F_283 ( struct V_1 * V_357 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_187 * V_193 = & V_192 [ V_357 -> V_22 ] ;
F_150 (sk, &tbl->mc_list)
F_245 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_358 *
F_284 ( struct V_20 * V_21 , T_1 V_151 , T_1 V_359 , int type , int V_58 , int V_3 )
{
struct V_358 * V_360 ;
int V_104 = F_285 ( V_58 ) ;
V_360 = (struct V_358 * ) F_259 ( V_21 , F_286 ( V_104 ) ) ;
V_360 -> V_361 = type ;
V_360 -> V_362 = V_104 ;
V_360 -> V_363 = V_3 ;
V_360 -> V_364 = V_151 ;
V_360 -> V_365 = V_359 ;
if ( ! F_287 ( V_104 ) || F_286 ( V_104 ) - V_104 != 0 )
memset ( F_288 ( V_360 ) + V_58 , 0 , F_286 ( V_104 ) - V_104 ) ;
return V_360 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_366 * V_168 ;
struct V_20 * V_21 = NULL ;
struct V_358 * V_360 ;
int V_58 , V_78 = - V_48 ;
int V_367 ;
F_60 ( V_43 -> V_206 ) ;
if ( ! V_43 -> V_131 ) {
V_78 = - V_10 ;
goto V_368;
}
V_168 = & V_43 -> V_168 ;
V_367 = F_289 ( int , V_168 -> V_369 , V_276 ) ;
if ( ! F_43 ( V_2 ) &&
F_56 ( & V_2 -> V_167 ) >= V_2 -> V_279 )
goto V_368;
if ( V_367 < V_43 -> V_347 ) {
V_21 = F_232 ( V_2 ,
V_43 -> V_347 ,
V_43 -> V_151 ,
V_62 |
V_65 |
V_66 ) ;
if ( V_21 )
F_290 ( V_21 , F_291 ( V_21 ) -
V_43 -> V_347 ) ;
}
if ( ! V_21 )
V_21 = F_232 ( V_2 , V_367 , V_43 -> V_151 ,
V_62 ) ;
if ( ! V_21 )
goto V_368;
F_112 ( V_21 , V_2 ) ;
V_58 = V_168 -> V_370 ( V_21 , V_168 ) ;
if ( V_58 > 0 ) {
F_66 ( V_43 -> V_206 ) ;
if ( F_231 ( V_2 , V_21 ) )
F_98 ( V_21 ) ;
else
F_218 ( V_2 , V_21 ) ;
return 0 ;
}
V_360 = F_292 ( V_21 , V_168 , V_371 , sizeof( V_58 ) , V_372 ) ;
if ( ! V_360 )
goto V_368;
F_293 ( V_168 , V_360 ) ;
memcpy ( F_288 ( V_360 ) , & V_58 , sizeof( V_58 ) ) ;
if ( F_231 ( V_2 , V_21 ) )
F_98 ( V_21 ) ;
else
F_218 ( V_2 , V_21 ) ;
if ( V_168 -> V_169 )
V_168 -> V_169 ( V_168 ) ;
V_43 -> V_131 = false ;
F_66 ( V_43 -> V_206 ) ;
F_14 ( V_168 -> V_14 ) ;
F_224 ( V_168 -> V_21 ) ;
return 0 ;
V_368:
F_66 ( V_43 -> V_206 ) ;
F_98 ( V_21 ) ;
return V_78 ;
}
int F_294 ( struct V_1 * V_268 , struct V_20 * V_21 ,
const struct V_358 * V_360 ,
struct V_373 * V_374 )
{
struct V_366 * V_168 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_19 ;
if ( F_41 ( V_21 ) ) {
V_21 = F_295 ( V_21 , V_62 ) ;
if ( V_21 == NULL )
return - V_48 ;
} else
F_35 ( & V_21 -> V_153 ) ;
V_2 = F_145 ( F_137 ( V_268 ) , V_268 -> V_22 , F_42 ( V_21 ) . V_151 ) ;
if ( V_2 == NULL ) {
V_19 = - V_269 ;
goto V_375;
}
V_43 = F_2 ( V_2 ) ;
F_60 ( V_43 -> V_206 ) ;
if ( V_43 -> V_131 ) {
V_19 = - V_81 ;
goto V_376;
}
if ( ! F_168 ( V_374 -> V_14 ) ) {
V_19 = - V_219 ;
goto V_376;
}
V_168 = & V_43 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_370 = V_374 -> V_370 ;
V_168 -> V_169 = V_374 -> V_169 ;
V_168 -> V_360 = V_360 ;
V_168 -> V_136 = V_374 -> V_136 ;
V_168 -> V_14 = V_374 -> V_14 ;
V_168 -> V_369 = V_374 -> V_369 ;
V_168 -> V_21 = V_21 ;
V_43 -> V_131 = true ;
F_66 ( V_43 -> V_206 ) ;
V_19 = F_87 ( V_2 ) ;
F_108 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return - V_377 ;
V_376:
F_108 ( V_2 ) ;
F_66 ( V_43 -> V_206 ) ;
V_375:
F_98 ( V_21 ) ;
return V_19 ;
}
void F_296 ( struct V_20 * V_378 , struct V_358 * V_360 , int V_78 )
{
struct V_20 * V_21 ;
struct V_358 * V_379 ;
struct V_380 * V_381 ;
T_7 V_382 = sizeof( * V_381 ) ;
if ( V_78 )
V_382 += V_362 ( V_360 ) ;
V_21 = F_232 ( V_378 -> V_2 , F_297 ( V_382 ) ,
F_42 ( V_378 ) . V_151 , V_62 ) ;
if ( ! V_21 ) {
struct V_1 * V_2 ;
V_2 = F_145 ( F_137 ( V_378 -> V_2 ) ,
V_378 -> V_2 -> V_22 ,
F_42 ( V_378 ) . V_151 ) ;
if ( V_2 ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 ( V_2 ) ;
F_108 ( V_2 ) ;
}
return;
}
V_379 = F_284 ( V_21 , F_42 ( V_378 ) . V_151 , V_360 -> V_365 ,
V_383 , V_382 , 0 ) ;
V_381 = F_288 ( V_379 ) ;
V_381 -> error = V_78 ;
memcpy ( & V_381 -> V_142 , V_360 , V_78 ? V_360 -> V_362 : sizeof( * V_360 ) ) ;
F_100 ( V_378 -> V_2 , V_21 , F_42 ( V_378 ) . V_151 , V_150 ) ;
}
int F_298 ( struct V_20 * V_21 , int (* V_168)( struct V_20 * ,
struct V_358 * ) )
{
struct V_358 * V_360 ;
int V_78 ;
while ( V_21 -> V_58 >= F_297 ( 0 ) ) {
int V_384 ;
V_360 = F_299 ( V_21 ) ;
V_78 = 0 ;
if ( V_360 -> V_362 < V_385 || V_21 -> V_58 < V_360 -> V_362 )
return 0 ;
if ( ! ( V_360 -> V_363 & V_386 ) )
goto V_387;
if ( V_360 -> V_361 < V_388 )
goto V_387;
V_78 = V_168 ( V_21 , V_360 ) ;
if ( V_78 == - V_377 )
goto V_389;
V_387:
if ( V_360 -> V_363 & V_390 || V_78 )
F_296 ( V_21 , V_360 , V_78 ) ;
V_389:
V_384 = F_286 ( V_360 -> V_362 ) ;
if ( V_384 > V_21 -> V_58 )
V_384 = V_21 -> V_58 ;
F_300 ( V_21 , V_384 ) ;
}
return 0 ;
}
int F_301 ( struct V_1 * V_2 , struct V_20 * V_21 , T_1 V_151 ,
unsigned int V_5 , int V_391 , T_2 V_3 )
{
int V_78 = 0 ;
if ( V_5 ) {
int V_392 = 0 ;
if ( V_391 ) {
F_35 ( & V_21 -> V_153 ) ;
V_392 = V_151 ;
}
V_78 = F_302 ( V_2 , V_21 , V_392 , V_5 , V_3 ) ;
}
if ( V_391 ) {
int V_290 ;
V_290 = F_303 ( V_2 , V_21 , V_151 ) ;
if ( ! V_78 || V_78 == - V_309 )
V_78 = V_290 ;
}
return V_78 ;
}
static int F_304 ( struct V_393 * V_394 )
{
int V_78 ;
V_78 = F_305 ( & V_192 [ V_394 -> V_395 ] . V_189 , & V_394 -> V_396 ) ;
if ( V_78 ) {
V_394 -> V_395 = V_218 ;
return V_78 ;
}
V_78 = F_306 ( & V_394 -> V_396 ) ;
return V_78 == - V_280 ? 0 : V_78 ;
}
static void F_307 ( struct V_393 * V_394 )
{
F_308 ( & V_394 -> V_396 ) ;
F_309 ( & V_394 -> V_396 ) ;
}
static void * F_310 ( struct V_397 * V_359 )
{
struct V_393 * V_394 = V_359 -> V_398 ;
struct V_42 * V_43 ;
do {
for (; ; ) {
int V_78 ;
V_43 = F_311 ( & V_394 -> V_396 ) ;
if ( F_229 ( V_43 ) ) {
if ( F_230 ( V_43 ) == - V_280 )
continue;
return V_43 ;
}
if ( V_43 )
break;
F_307 ( V_394 ) ;
if ( ++ V_394 -> V_395 >= V_218 )
return NULL ;
V_78 = F_304 ( V_394 ) ;
if ( V_78 )
return F_204 ( V_78 ) ;
}
} while ( F_137 ( & V_43 -> V_2 ) != F_312 ( V_359 ) );
return V_43 ;
}
static void * F_313 ( struct V_397 * V_359 , T_8 * V_399 )
{
struct V_393 * V_394 = V_359 -> V_398 ;
void * V_400 = V_401 ;
T_8 V_123 ;
int V_78 ;
V_394 -> V_395 = 0 ;
V_78 = F_304 ( V_394 ) ;
if ( V_78 )
return F_204 ( V_78 ) ;
for ( V_123 = * V_399 ; V_123 && V_400 && ! F_229 ( V_400 ) ; V_123 -- )
V_400 = F_310 ( V_359 ) ;
return V_400 ;
}
static void * F_314 ( struct V_397 * V_359 , void * V_402 , T_8 * V_123 )
{
++ * V_123 ;
return F_310 ( V_359 ) ;
}
static void F_315 ( struct V_397 * V_359 , void * V_402 )
{
struct V_393 * V_394 = V_359 -> V_398 ;
if ( V_394 -> V_395 >= V_218 )
return;
F_307 ( V_394 ) ;
}
static int F_316 ( struct V_397 * V_359 , void * V_402 )
{
if ( V_402 == V_401 ) {
F_317 ( V_359 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_403 = V_402 ;
struct V_42 * V_43 = F_2 ( V_403 ) ;
F_318 ( V_359 , L_6 ,
V_403 ,
V_403 -> V_22 ,
V_43 -> V_151 ,
V_43 -> V_173 ? ( T_1 ) V_43 -> V_173 [ 0 ] : 0 ,
F_319 ( V_403 ) ,
F_320 ( V_403 ) ,
V_43 -> V_131 ,
F_56 ( & V_403 -> V_202 ) ,
F_56 ( & V_403 -> V_50 ) ,
F_321 ( V_403 )
) ;
}
return 0 ;
}
static int F_322 ( struct V_271 * V_271 , struct V_99 * V_99 )
{
return F_323 ( V_271 , V_99 , & V_404 ,
sizeof( struct V_393 ) ) ;
}
int F_324 ( struct V_405 * V_406 )
{
return F_325 ( & V_228 , V_406 ) ;
}
int F_326 ( struct V_405 * V_406 )
{
return F_327 ( & V_228 , V_406 ) ;
}
static int T_9 F_328 ( struct V_186 * V_186 )
{
#ifdef F_329
if ( ! F_330 ( L_7 , 0 , V_186 -> V_407 , & V_408 ) )
return - V_33 ;
#endif
return 0 ;
}
static void T_10 F_331 ( struct V_186 * V_186 )
{
#ifdef F_329
F_332 ( L_7 , V_186 -> V_407 ) ;
#endif
}
static void T_11 F_333 ( void )
{
struct V_194 * V_194 ;
int V_173 = 32 ;
V_194 = F_276 ( sizeof( * V_194 ) + F_196 ( V_173 ) , V_62 ) ;
if ( ! V_194 )
F_334 ( L_8 ) ;
F_119 () ;
V_192 [ V_24 ] . V_173 = V_173 ;
F_277 ( V_192 [ V_24 ] . V_194 , V_194 ) ;
V_192 [ V_24 ] . V_14 = V_409 ;
V_192 [ V_24 ] . V_220 = 1 ;
V_192 [ V_24 ] . V_3 = V_264 ;
F_128 () ;
}
static inline T_1 F_335 ( const void * V_136 , T_1 V_58 , T_1 V_410 )
{
const struct V_42 * V_43 = V_136 ;
struct V_182 V_180 ;
F_139 ( & V_180 , F_137 ( & V_43 -> V_2 ) , V_43 -> V_151 ) ;
return F_336 ( ( T_1 * ) & V_180 , V_411 / sizeof( T_1 ) , V_410 ) ;
}
static int T_11 F_337 ( void )
{
int V_59 ;
int V_78 = F_338 ( & V_210 , 0 ) ;
if ( V_78 != 0 )
goto V_17;
F_339 ( sizeof( struct V_233 ) > F_340 ( struct V_20 , V_168 ) ) ;
V_192 = F_54 ( V_218 , sizeof( * V_192 ) , V_62 ) ;
if ( ! V_192 )
goto F_334;
for ( V_59 = 0 ; V_59 < V_218 ; V_59 ++ ) {
if ( F_341 ( & V_192 [ V_59 ] . V_189 ,
& V_190 ) < 0 ) {
while ( -- V_59 > 0 )
F_342 ( & V_192 [ V_59 ] . V_189 ) ;
F_49 ( V_192 ) ;
goto F_334;
}
}
F_343 ( & V_13 ) ;
F_333 () ;
F_344 ( & V_412 ) ;
F_345 ( & V_413 ) ;
F_346 () ;
V_17:
return V_78 ;
F_334:
F_334 ( L_9 ) ;
}
