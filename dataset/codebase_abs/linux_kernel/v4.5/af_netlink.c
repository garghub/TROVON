static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
static struct V_6 * F_4 ( const struct V_6 * V_7 ,
T_2 V_8 )
{
unsigned int V_9 = F_5 ( V_7 ) ;
struct V_6 * V_10 ;
V_10 = F_6 ( V_9 , V_8 ) ;
if ( V_10 == NULL )
return NULL ;
F_7 ( V_10 ) . V_11 = F_7 ( V_7 ) . V_11 ;
F_7 ( V_10 ) . V_12 = F_7 ( V_7 ) . V_12 ;
F_7 ( V_10 ) . V_13 = F_7 ( V_7 ) . V_13 ;
memcpy ( F_8 ( V_10 , V_9 ) , V_7 -> V_14 , V_9 ) ;
return V_10 ;
}
int F_9 ( struct V_15 * V_16 )
{
if ( F_10 ( V_16 -> V_17 -> type != V_18 ) )
return - V_19 ;
F_11 ( & V_20 ) ;
F_12 ( & V_16 -> V_21 , & V_22 ) ;
F_13 ( & V_20 ) ;
F_14 ( V_16 -> V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
bool V_24 = false ;
struct V_15 * V_25 ;
F_11 ( & V_20 ) ;
F_16 (tmp, &netlink_tap_all, list) {
if ( V_16 == V_25 ) {
F_17 ( & V_16 -> V_21 ) ;
V_24 = true ;
goto V_26;
}
}
F_18 ( L_1 , V_16 ) ;
V_26:
F_13 ( & V_20 ) ;
if ( V_24 )
F_19 ( V_16 -> V_23 ) ;
return V_24 ? 0 : - V_27 ;
}
int F_20 ( struct V_15 * V_16 )
{
int V_28 ;
V_28 = F_15 ( V_16 ) ;
F_21 () ;
return V_28 ;
}
static bool F_22 ( const struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
switch ( V_2 -> V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return true ;
}
return false ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_38 * V_17 )
{
struct V_6 * V_39 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_28 = - V_40 ;
F_24 ( V_17 ) ;
if ( F_25 ( V_7 ) || F_26 ( V_7 -> V_41 ) )
V_39 = F_4 ( V_7 , V_42 ) ;
else
V_39 = F_27 ( V_7 , V_42 ) ;
if ( V_39 ) {
V_39 -> V_17 = V_17 ;
V_39 -> V_43 = F_28 ( ( V_44 ) V_2 -> V_29 ) ;
V_39 -> V_45 = F_1 ( V_2 ) ?
V_46 : V_47 ;
F_29 ( V_39 ) ;
V_28 = F_30 ( V_39 ) ;
if ( F_10 ( V_28 > 0 ) )
V_28 = F_31 ( V_28 ) ;
}
F_32 ( V_17 ) ;
return V_28 ;
}
static void F_33 ( struct V_6 * V_7 )
{
int V_28 ;
struct V_15 * V_25 ;
if ( ! F_22 ( V_7 ) )
return;
F_34 (tmp, &netlink_tap_all, list) {
V_28 = F_23 ( V_7 , V_25 -> V_17 ) ;
if ( F_10 ( V_28 ) )
break;
}
}
static void F_35 ( struct V_6 * V_7 )
{
F_36 () ;
if ( F_10 ( ! F_37 ( & V_22 ) ) )
F_33 ( V_7 ) ;
F_38 () ;
}
static void F_39 ( struct V_1 * V_48 , struct V_1 * V_49 ,
struct V_6 * V_7 )
{
if ( ! ( F_1 ( V_48 ) && F_1 ( V_49 ) ) )
F_35 ( V_7 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( ! ( V_51 -> V_3 & V_52 ) ) {
if ( ! F_41 ( V_53 ,
& F_2 ( V_2 ) -> V_54 ) ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_42 ( & V_2 -> V_58 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_44 ( & V_2 -> V_59 ) )
F_45 ( V_53 , & V_51 -> V_54 ) ;
if ( ! F_46 ( V_53 , & V_51 -> V_54 ) )
F_47 ( & V_51 -> V_60 ) ;
}
static bool F_48 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_61 . V_62 != NULL ;
}
static bool F_49 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_63 . V_62 != NULL ;
}
static void F_50 ( void * * V_62 , unsigned int V_64 , unsigned int V_9 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_9 ; V_65 ++ ) {
if ( V_62 [ V_65 ] != NULL ) {
if ( F_26 ( V_62 [ V_65 ] ) )
F_51 ( V_62 [ V_65 ] ) ;
else
F_52 ( ( unsigned long ) V_62 [ V_65 ] , V_64 ) ;
}
}
F_53 ( V_62 ) ;
}
static void * F_54 ( unsigned long V_64 )
{
void * V_66 ;
T_2 V_67 = V_68 | V_69 | V_70 |
V_71 | V_72 ;
V_66 = ( void * ) F_55 ( V_67 , V_64 ) ;
if ( V_66 != NULL )
return V_66 ;
V_66 = F_56 ( ( 1 << V_64 ) * V_73 ) ;
if ( V_66 != NULL )
return V_66 ;
V_67 &= ~ V_72 ;
return ( void * ) F_55 ( V_67 , V_64 ) ;
}
static void * * F_57 ( struct V_50 * V_51 ,
struct V_74 * V_75 , unsigned int V_64 )
{
unsigned int V_76 = V_75 -> V_77 ;
unsigned int V_65 ;
void * * V_62 ;
V_62 = F_58 ( V_76 , sizeof( void * ) , V_68 ) ;
if ( V_62 == NULL )
return NULL ;
for ( V_65 = 0 ; V_65 < V_76 ; V_65 ++ ) {
V_62 [ V_65 ] = F_54 ( V_64 ) ;
if ( V_62 [ V_65 ] == NULL )
goto V_78;
}
return V_62 ;
V_78:
F_50 ( V_62 , V_64 , V_76 ) ;
return NULL ;
}
static void
F_59 ( struct V_1 * V_2 , struct V_74 * V_75 , bool V_63 , void * * V_62 ,
unsigned int V_64 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
V_80 = V_63 ? & V_2 -> V_83 : & V_2 -> V_59 ;
V_82 = V_63 ? & V_51 -> V_63 : & V_51 -> V_61 ;
F_60 ( & V_80 -> V_84 ) ;
V_82 -> V_85 = V_75 -> V_86 - 1 ;
V_82 -> V_41 = 0 ;
V_82 -> V_87 = V_75 -> V_88 ;
V_82 -> V_89 = V_75 -> V_90 / V_73 ;
F_61 ( V_82 -> V_91 , V_75 -> V_77 ) ;
F_61 ( V_82 -> V_92 , V_64 ) ;
F_61 ( V_82 -> V_62 , V_62 ) ;
F_62 ( V_80 ) ;
F_63 ( & V_80 -> V_84 ) ;
F_64 ( F_65 ( & V_51 -> V_93 ) ) ;
if ( V_62 )
F_50 ( V_62 , V_64 , V_75 -> V_77 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_74 * V_75 ,
bool V_63 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_81 * V_82 ;
void * * V_62 = NULL ;
unsigned int V_64 = 0 ;
V_82 = V_63 ? & V_51 -> V_63 : & V_51 -> V_61 ;
if ( F_65 ( & V_51 -> V_93 ) )
return - V_94 ;
if ( F_65 ( & V_82 -> V_95 ) )
return - V_94 ;
if ( V_75 -> V_77 ) {
if ( V_82 -> V_62 != NULL )
return - V_94 ;
if ( ( int ) V_75 -> V_90 <= 0 )
return - V_19 ;
if ( ! F_67 ( V_75 -> V_90 ) )
return - V_19 ;
if ( V_75 -> V_88 < V_96 )
return - V_19 ;
if ( ! F_68 ( V_75 -> V_88 , V_97 ) )
return - V_19 ;
V_82 -> V_98 = V_75 -> V_90 /
V_75 -> V_88 ;
if ( V_82 -> V_98 == 0 )
return - V_19 ;
if ( V_82 -> V_98 * V_75 -> V_77 !=
V_75 -> V_86 )
return - V_19 ;
V_64 = F_69 ( V_75 -> V_90 ) ;
V_62 = F_57 ( V_51 , V_75 , V_64 ) ;
if ( V_62 == NULL )
return - V_40 ;
} else {
if ( V_75 -> V_86 )
return - V_19 ;
}
F_70 ( & V_51 -> V_99 ) ;
if ( F_65 ( & V_51 -> V_93 ) == 0 ) {
F_59 ( V_2 , V_75 , V_63 , V_62 , V_64 ) ;
F_71 ( & V_51 -> V_99 ) ;
return 0 ;
}
F_71 ( & V_51 -> V_99 ) ;
if ( V_62 )
F_50 ( V_62 , V_64 , V_75 -> V_77 ) ;
return - V_94 ;
}
static void F_72 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_42 ( & F_2 ( V_2 ) -> V_93 ) ;
}
static void F_73 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_74 ( & F_2 ( V_2 ) -> V_93 ) ;
}
static int F_75 ( struct V_102 * V_102 , struct V_104 * V_1 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_81 * V_82 ;
unsigned long V_106 , V_107 , V_108 ;
unsigned int V_65 ;
int V_109 = - V_19 ;
if ( V_101 -> V_110 )
return - V_19 ;
F_70 ( & V_51 -> V_99 ) ;
V_108 = 0 ;
for ( V_82 = & V_51 -> V_61 ; V_82 <= & V_51 -> V_63 ; V_82 ++ ) {
if ( V_82 -> V_62 == NULL )
continue;
V_108 += V_82 -> V_91 * V_82 -> V_89 * V_73 ;
}
if ( V_108 == 0 )
goto V_26;
V_107 = V_101 -> V_111 - V_101 -> V_112 ;
if ( V_107 != V_108 )
goto V_26;
V_106 = V_101 -> V_112 ;
for ( V_82 = & V_51 -> V_61 ; V_82 <= & V_51 -> V_63 ; V_82 ++ ) {
if ( V_82 -> V_62 == NULL )
continue;
for ( V_65 = 0 ; V_65 < V_82 -> V_91 ; V_65 ++ ) {
struct V_113 * V_113 ;
void * V_114 = V_82 -> V_62 [ V_65 ] ;
unsigned int V_115 ;
for ( V_115 = 0 ; V_115 < V_82 -> V_89 ; V_115 ++ ) {
V_113 = F_76 ( V_114 ) ;
V_109 = F_77 ( V_101 , V_106 , V_113 ) ;
if ( V_109 < 0 )
goto V_26;
V_106 += V_73 ;
V_114 += V_73 ;
}
}
}
F_42 ( & V_51 -> V_93 ) ;
V_101 -> V_116 = & V_117 ;
V_109 = 0 ;
V_26:
F_71 ( & V_51 -> V_99 ) ;
return V_109 ;
}
static void F_78 ( const struct V_118 * V_119 , unsigned int V_120 )
{
#if V_121 == 1
struct V_113 * V_122 , * V_123 ;
V_122 = F_76 ( V_119 + V_73 ) ;
V_123 = F_76 ( ( void * ) V_119 + V_96 + V_120 - 1 ) ;
while ( V_122 <= V_123 ) {
F_79 ( V_122 ) ;
V_122 ++ ;
}
#endif
}
static enum V_124 F_80 ( const struct V_118 * V_119 )
{
F_81 () ;
F_79 ( F_76 ( V_119 ) ) ;
return V_119 -> V_125 ;
}
static void F_82 ( struct V_118 * V_119 ,
enum V_124 V_126 )
{
F_83 () ;
V_119 -> V_125 = V_126 ;
F_79 ( F_76 ( V_119 ) ) ;
}
static struct V_118 *
F_84 ( const struct V_81 * V_82 , unsigned int V_127 )
{
unsigned int V_128 , V_129 ;
V_128 = V_127 / V_82 -> V_98 ;
V_129 = V_127 % V_82 -> V_98 ;
return V_82 -> V_62 [ V_128 ] + ( V_129 * V_82 -> V_87 ) ;
}
static struct V_118 *
F_85 ( const struct V_81 * V_82 , unsigned int V_127 ,
enum V_124 V_126 )
{
struct V_118 * V_119 ;
V_119 = F_84 ( V_82 , V_127 ) ;
if ( F_80 ( V_119 ) != V_126 )
return NULL ;
return V_119 ;
}
static struct V_118 *
F_86 ( const struct V_81 * V_82 ,
enum V_124 V_126 )
{
return F_85 ( V_82 , V_82 -> V_41 , V_126 ) ;
}
static void F_87 ( struct V_81 * V_82 )
{
V_82 -> V_41 = V_82 -> V_41 != V_82 -> V_85 ? V_82 -> V_41 + 1 : 0 ;
}
static void F_88 ( struct V_81 * V_82 )
{
unsigned int V_41 = V_82 -> V_41 ;
const struct V_118 * V_119 ;
do {
V_119 = F_84 ( V_82 , V_82 -> V_41 ) ;
if ( V_119 -> V_125 == V_130 )
break;
if ( V_119 -> V_125 != V_131 )
break;
F_87 ( V_82 ) ;
} while ( V_82 -> V_41 != V_41 );
}
static bool F_89 ( struct V_81 * V_82 )
{
unsigned int V_41 = V_82 -> V_41 , V_127 = V_41 ;
const struct V_118 * V_119 ;
do {
V_119 = F_84 ( V_82 , V_127 ) ;
if ( V_119 -> V_125 == V_132 )
return true ;
V_127 = V_127 != 0 ? V_127 - 1 : V_82 -> V_85 ;
} while ( V_127 != V_41 );
return false ;
}
static bool F_90 ( struct V_50 * V_51 )
{
struct V_81 * V_82 = & V_51 -> V_61 ;
struct V_118 * V_119 ;
unsigned int V_133 ;
V_119 = F_86 ( V_82 , V_130 ) ;
if ( V_119 == NULL )
return false ;
V_133 = V_82 -> V_41 + V_82 -> V_85 / 2 ;
if ( V_133 > V_82 -> V_85 )
V_133 -= V_82 -> V_85 ;
V_119 = F_84 ( V_82 , V_133 ) ;
return V_119 -> V_125 == V_130 ;
}
static unsigned int F_91 ( struct V_102 * V_102 , struct V_104 * V_1 ,
T_3 * V_60 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_134 ;
int V_109 ;
if ( V_51 -> V_61 . V_62 != NULL ) {
while ( V_51 -> V_135 && F_90 ( V_51 ) ) {
V_109 = F_92 ( V_2 ) ;
if ( V_109 < 0 ) {
V_2 -> V_55 = - V_109 ;
V_2 -> V_57 ( V_2 ) ;
break;
}
}
F_43 ( V_2 ) ;
}
V_134 = F_93 ( V_102 , V_1 , V_60 ) ;
if ( ( V_134 & ( V_136 | V_137 ) ) != ( V_136 | V_137 ) ) {
F_60 ( & V_2 -> V_59 . V_84 ) ;
if ( V_51 -> V_61 . V_62 ) {
if ( F_89 ( & V_51 -> V_61 ) )
V_134 |= V_136 | V_137 ;
}
F_63 ( & V_2 -> V_59 . V_84 ) ;
}
F_60 ( & V_2 -> V_83 . V_84 ) ;
if ( V_51 -> V_63 . V_62 ) {
if ( F_86 ( & V_51 -> V_63 , V_130 ) )
V_134 |= V_138 | V_139 ;
}
F_63 ( & V_2 -> V_83 . V_84 ) ;
return V_134 ;
}
static struct V_118 * F_94 ( struct V_6 * V_7 )
{
return (struct V_118 * ) ( V_7 -> V_41 - V_96 ) ;
}
static void F_95 ( struct V_6 * V_7 , struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_118 * V_119 )
{
unsigned int V_107 ;
void * V_14 ;
V_107 = V_82 -> V_87 - V_96 ;
V_14 = ( void * ) V_119 + V_96 ;
V_7 -> V_41 = V_14 ;
V_7 -> V_14 = V_14 ;
F_96 ( V_7 ) ;
V_7 -> V_140 = V_7 -> V_141 + V_107 ;
V_7 -> V_9 = 0 ;
V_7 -> V_142 = V_143 ;
F_7 ( V_7 ) . V_3 |= V_144 ;
F_7 ( V_7 ) . V_2 = V_2 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_145 * V_146 ,
T_1 V_147 , T_1 V_12 ,
struct V_148 * V_149 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_81 * V_82 ;
struct V_118 * V_119 ;
struct V_6 * V_7 ;
unsigned int V_150 ;
int V_109 = 0 , V_9 = 0 ;
F_70 ( & V_51 -> V_99 ) ;
V_82 = & V_51 -> V_63 ;
V_150 = V_82 -> V_87 - V_96 ;
do {
unsigned int V_120 ;
V_119 = F_86 ( V_82 , V_132 ) ;
if ( V_119 == NULL ) {
if ( ! ( V_146 -> V_151 & V_152 ) &&
F_65 ( & V_51 -> V_63 . V_95 ) )
F_98 () ;
continue;
}
V_120 = F_99 ( V_119 -> V_120 ) ;
if ( V_120 > V_150 ) {
V_109 = - V_19 ;
goto V_26;
}
F_78 ( V_119 , V_120 ) ;
V_7 = F_6 ( V_120 , V_68 ) ;
if ( V_7 == NULL ) {
V_109 = - V_56 ;
goto V_26;
}
F_100 ( V_7 , V_120 ) ;
memcpy ( V_7 -> V_14 , ( void * ) V_119 + V_96 , V_120 ) ;
F_82 ( V_119 , V_130 ) ;
F_87 ( V_82 ) ;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_149 -> V_13 ;
V_109 = F_101 ( V_2 , V_7 ) ;
if ( V_109 ) {
F_102 ( V_7 ) ;
goto V_26;
}
if ( F_10 ( V_12 ) ) {
F_42 ( & V_7 -> V_153 ) ;
F_103 ( V_2 , V_7 , V_147 , V_12 ,
V_68 ) ;
}
V_109 = F_104 ( V_2 , V_7 , V_147 ,
V_146 -> V_151 & V_152 ) ;
if ( V_109 < 0 )
goto V_26;
V_9 += V_109 ;
} while ( V_119 != NULL ||
( ! ( V_146 -> V_151 & V_152 ) &&
F_65 ( & V_51 -> V_63 . V_95 ) ) );
if ( V_9 > 0 )
V_109 = V_9 ;
V_26:
F_71 ( & V_51 -> V_99 ) ;
return V_109 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_118 * V_119 ;
V_119 = F_94 ( V_7 ) ;
V_119 -> V_120 = V_7 -> V_9 ;
V_119 -> V_154 = F_7 ( V_7 ) . V_12 ;
V_119 -> V_155 = F_7 ( V_7 ) . V_13 . V_156 ;
V_119 -> V_157 = F_106 ( F_107 ( V_2 ) , F_7 ( V_7 ) . V_13 . V_158 ) ;
V_119 -> V_159 = F_108 ( F_107 ( V_2 ) , F_7 ( V_7 ) . V_13 . V_160 ) ;
F_78 ( V_119 , V_119 -> V_120 ) ;
F_82 ( V_119 , V_132 ) ;
F_7 ( V_7 ) . V_3 |= V_161 ;
F_102 ( V_7 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_81 * V_82 = & V_51 -> V_61 ;
struct V_118 * V_119 ;
F_60 ( & V_2 -> V_59 . V_84 ) ;
V_119 = F_86 ( V_82 , V_130 ) ;
if ( V_119 == NULL ) {
F_63 ( & V_2 -> V_59 . V_84 ) ;
F_102 ( V_7 ) ;
F_40 ( V_2 ) ;
return;
}
F_87 ( V_82 ) ;
F_110 ( & V_2 -> V_59 , V_7 ) ;
F_63 ( & V_2 -> V_59 . V_84 ) ;
V_119 -> V_120 = V_7 -> V_9 ;
V_119 -> V_154 = F_7 ( V_7 ) . V_12 ;
V_119 -> V_155 = F_7 ( V_7 ) . V_13 . V_156 ;
V_119 -> V_157 = F_106 ( F_107 ( V_2 ) , F_7 ( V_7 ) . V_13 . V_158 ) ;
V_119 -> V_159 = F_108 ( F_107 ( V_2 ) , F_7 ( V_7 ) . V_13 . V_160 ) ;
F_82 ( V_119 , V_162 ) ;
}
static void V_143 ( struct V_6 * V_7 )
{
#ifdef F_111
struct V_118 * V_119 ;
struct V_81 * V_82 ;
struct V_1 * V_2 ;
if ( F_25 ( V_7 ) ) {
V_119 = F_94 ( V_7 ) ;
V_2 = F_7 ( V_7 ) . V_2 ;
if ( F_7 ( V_7 ) . V_3 & V_163 ) {
F_82 ( V_119 , V_130 ) ;
V_82 = & F_2 ( V_2 ) -> V_63 ;
} else {
if ( ! ( F_7 ( V_7 ) . V_3 & V_161 ) ) {
V_119 -> V_120 = 0 ;
F_82 ( V_119 , V_132 ) ;
}
V_82 = & F_2 ( V_2 ) -> V_61 ;
}
F_64 ( F_65 ( & V_82 -> V_95 ) == 0 ) ;
F_74 ( & V_82 -> V_95 ) ;
F_112 ( V_2 ) ;
V_7 -> V_41 = NULL ;
}
#endif
if ( F_26 ( V_7 -> V_41 ) ) {
if ( ! V_7 -> V_164 ||
! F_113 ( & ( F_114 ( V_7 ) -> V_165 ) ) )
F_51 ( V_7 -> V_41 ) ;
V_7 -> V_41 = NULL ;
}
if ( V_7 -> V_2 != NULL )
F_115 ( V_7 ) ;
}
static void F_116 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
F_64 ( V_7 -> V_2 != NULL ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_142 = V_143 ;
F_117 ( V_7 -> V_166 , & V_2 -> V_167 ) ;
F_118 ( V_2 , V_7 -> V_166 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_135 ) {
if ( V_51 -> V_168 . V_169 )
V_51 -> V_168 . V_169 ( & V_51 -> V_168 ) ;
F_19 ( V_51 -> V_168 . V_23 ) ;
F_102 ( V_51 -> V_168 . V_7 ) ;
}
F_120 ( & V_2 -> V_59 ) ;
#ifdef F_111
if ( 1 ) {
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
if ( V_51 -> V_61 . V_62 )
F_59 ( V_2 , & V_75 , false , NULL , 0 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
if ( V_51 -> V_63 . V_62 )
F_59 ( V_2 , & V_75 , true , NULL , 0 ) ;
}
#endif
if ( ! F_121 ( V_2 , V_170 ) ) {
F_122 ( V_171 L_2 , V_2 ) ;
return;
}
F_64 ( F_65 ( & V_2 -> V_167 ) ) ;
F_64 ( F_65 ( & V_2 -> V_172 ) ) ;
F_64 ( F_2 ( V_2 ) -> V_173 ) ;
}
void F_123 ( void )
__acquires( T_4 )
{
F_124 () ;
F_125 ( & T_4 ) ;
if ( F_65 ( & V_174 ) ) {
F_126 ( V_60 , V_175 ) ;
F_127 ( & V_176 , & V_60 ) ;
for (; ; ) {
F_128 ( V_177 ) ;
if ( F_65 ( & V_174 ) == 0 )
break;
F_129 ( & T_4 ) ;
F_98 () ;
F_125 ( & T_4 ) ;
}
F_130 ( V_178 ) ;
F_131 ( & V_176 , & V_60 ) ;
}
}
void F_132 ( void )
__releases( T_4 )
{
F_129 ( & T_4 ) ;
F_133 ( & V_176 ) ;
}
static inline void
F_134 ( void )
{
F_135 ( & T_4 ) ;
F_42 ( & V_174 ) ;
F_136 ( & T_4 ) ;
}
static inline void
F_137 ( void )
{
if ( F_138 ( & V_174 ) )
F_133 ( & V_176 ) ;
}
static inline int F_139 ( struct V_179 * V_180 ,
const void * V_181 )
{
const struct V_182 * V_183 = V_180 -> V_184 ;
const struct V_50 * V_51 = V_181 ;
return V_51 -> V_11 != V_183 -> V_11 ||
! F_140 ( F_141 ( & V_51 -> V_2 ) , F_142 ( & V_183 -> V_185 ) ) ;
}
static void F_143 ( struct V_182 * V_180 ,
struct V_186 * V_186 , T_1 V_11 )
{
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
F_144 ( & V_180 -> V_185 , V_186 ) ;
V_180 -> V_11 = V_11 ;
}
static struct V_1 * F_145 ( struct V_187 * V_188 , T_1 V_11 ,
struct V_186 * V_186 )
{
struct V_182 V_180 ;
F_143 ( & V_180 , V_186 , V_11 ) ;
return F_146 ( & V_188 -> V_189 , & V_180 ,
V_190 ) ;
}
static int F_147 ( struct V_187 * V_188 , struct V_1 * V_2 )
{
struct V_182 V_180 ;
F_143 ( & V_180 , F_141 ( V_2 ) , F_2 ( V_2 ) -> V_11 ) ;
return F_148 ( & V_188 -> V_189 , & V_180 ,
& F_2 ( V_2 ) -> V_191 ,
V_190 ) ;
}
static struct V_1 * F_149 ( struct V_186 * V_186 , int V_43 , T_1 V_11 )
{
struct V_187 * V_188 = & V_192 [ V_43 ] ;
struct V_1 * V_2 ;
F_36 () ;
V_2 = F_145 ( V_188 , V_11 , V_186 ) ;
if ( V_2 )
F_150 ( V_2 ) ;
F_38 () ;
return V_2 ;
}
static void
F_151 ( struct V_1 * V_2 )
{
struct V_187 * V_193 = & V_192 [ V_2 -> V_29 ] ;
unsigned long V_134 ;
unsigned int V_65 ;
struct V_194 * V_194 ;
V_194 = F_152 ( V_193 -> V_194 ) ;
if ( ! V_194 )
return;
for ( V_65 = 0 ; V_65 < F_153 ( V_193 -> V_173 ) ; V_65 ++ ) {
V_134 = 0 ;
F_154 (sk, &tbl->mc_list) {
if ( V_65 < F_153 ( F_2 ( V_2 ) -> V_195 ) )
V_134 |= F_2 ( V_2 ) -> V_173 [ V_65 ] ;
}
V_194 -> V_196 [ V_65 ] = V_134 ;
}
}
static int F_155 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_187 * V_188 = & V_192 [ V_2 -> V_29 ] ;
int V_109 ;
F_156 ( V_2 ) ;
V_109 = F_2 ( V_2 ) -> V_11 == V_11 ? 0 : - V_94 ;
if ( F_2 ( V_2 ) -> V_197 )
goto V_109;
V_109 = - V_40 ;
if ( V_198 > 32 &&
F_10 ( F_65 ( & V_188 -> V_189 . V_199 ) >= V_200 ) )
goto V_109;
F_2 ( V_2 ) -> V_11 = V_11 ;
F_150 ( V_2 ) ;
V_109 = F_147 ( V_188 , V_2 ) ;
if ( V_109 ) {
if ( F_10 ( V_109 == - V_94 ) )
V_109 = - V_201 ;
if ( V_109 == - V_202 )
V_109 = - V_203 ;
F_112 ( V_2 ) ;
goto V_109;
}
F_157 () ;
F_2 ( V_2 ) -> V_197 = V_11 ;
V_109:
F_158 ( V_2 ) ;
return V_109 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_187 * V_188 ;
V_188 = & V_192 [ V_2 -> V_29 ] ;
if ( ! F_160 ( & V_188 -> V_189 , & F_2 ( V_2 ) -> V_191 ,
V_190 ) ) {
F_64 ( F_65 ( & V_2 -> V_204 ) == 1 ) ;
F_161 ( V_2 ) ;
}
F_123 () ;
if ( F_2 ( V_2 ) -> V_205 ) {
F_162 ( V_2 ) ;
F_151 ( V_2 ) ;
}
if ( V_2 -> V_29 == V_37 )
F_42 ( & V_206 ) ;
F_132 () ;
}
static int F_163 ( struct V_186 * V_186 , struct V_104 * V_1 ,
struct V_207 * V_208 , int V_43 ,
int V_209 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_210 = & V_211 ;
V_2 = F_164 ( V_186 , V_212 , V_68 , & V_213 , V_209 ) ;
if ( ! V_2 )
return - V_40 ;
F_165 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_208 ) {
V_51 -> V_208 = V_208 ;
} else {
V_51 -> V_208 = & V_51 -> V_214 ;
F_166 ( V_51 -> V_208 ) ;
}
F_167 ( & V_51 -> V_60 ) ;
#ifdef F_111
F_166 ( & V_51 -> V_99 ) ;
#endif
V_2 -> V_215 = F_119 ;
V_2 -> V_29 = V_43 ;
return 0 ;
}
static int F_168 ( struct V_186 * V_186 , struct V_104 * V_1 , int V_43 ,
int V_209 )
{
struct V_23 * V_23 = NULL ;
struct V_207 * V_208 ;
struct V_50 * V_51 ;
int (* F_169)( struct V_186 * V_186 , int V_5 );
void (* F_170)( struct V_186 * V_186 , int V_5 );
int V_109 = 0 ;
V_1 -> V_54 = V_216 ;
if ( V_1 -> type != V_217 && V_1 -> type != V_218 )
return - V_219 ;
if ( V_43 < 0 || V_43 >= V_220 )
return - V_221 ;
F_134 () ;
#ifdef F_171
if ( ! V_192 [ V_43 ] . V_222 ) {
F_137 () ;
F_172 ( L_3 , V_212 , V_43 ) ;
F_134 () ;
}
#endif
if ( V_192 [ V_43 ] . V_222 &&
F_173 ( V_192 [ V_43 ] . V_23 ) )
V_23 = V_192 [ V_43 ] . V_23 ;
else
V_109 = - V_221 ;
V_208 = V_192 [ V_43 ] . V_208 ;
F_169 = V_192 [ V_43 ] . F_169 ;
F_170 = V_192 [ V_43 ] . F_170 ;
F_137 () ;
if ( V_109 < 0 )
goto V_26;
V_109 = F_163 ( V_186 , V_1 , V_208 , V_43 , V_209 ) ;
if ( V_109 < 0 )
goto V_223;
F_174 () ;
F_175 ( V_186 , & V_213 , 1 ) ;
F_176 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_224 = F_169 ;
V_51 -> V_225 = F_170 ;
V_26:
return V_109 ;
V_223:
F_19 ( V_23 ) ;
goto V_26;
}
static void F_177 ( struct V_226 * V_41 )
{
struct V_50 * V_51 = F_178 ( V_41 , struct V_50 , V_227 ) ;
F_112 ( & V_51 -> V_2 ) ;
}
static int F_179 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_159 ( V_2 ) ;
F_180 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_225 ) {
int V_65 ;
for ( V_65 = 0 ; V_65 < V_51 -> V_195 ; V_65 ++ )
if ( F_46 ( V_65 , V_51 -> V_173 ) )
V_51 -> V_225 ( F_141 ( V_2 ) , V_65 + 1 ) ;
}
if ( V_2 -> V_29 == V_37 &&
F_113 ( & V_206 ) == 0 )
F_133 ( & V_228 ) ;
V_1 -> V_2 = NULL ;
F_181 ( & V_51 -> V_60 ) ;
F_120 ( & V_2 -> V_83 ) ;
if ( V_51 -> V_11 ) {
struct V_229 V_133 = {
. V_186 = F_141 ( V_2 ) ,
. V_43 = V_2 -> V_29 ,
. V_11 = V_51 -> V_11 ,
} ;
F_182 ( & V_230 ,
V_231 , & V_133 ) ;
}
F_19 ( V_51 -> V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_123 () ;
F_183 ( V_192 [ V_2 -> V_29 ] . V_222 == 0 ) ;
if ( -- V_192 [ V_2 -> V_29 ] . V_222 == 0 ) {
struct V_194 * V_232 ;
V_232 = F_152 ( V_192 [ V_2 -> V_29 ] . V_194 ) ;
F_184 ( V_192 [ V_2 -> V_29 ] . V_194 , NULL ) ;
F_185 ( V_232 , V_227 ) ;
V_192 [ V_2 -> V_29 ] . V_23 = NULL ;
V_192 [ V_2 -> V_29 ] . F_169 = NULL ;
V_192 [ V_2 -> V_29 ] . F_170 = NULL ;
V_192 [ V_2 -> V_29 ] . V_3 = 0 ;
V_192 [ V_2 -> V_29 ] . V_222 = 0 ;
}
F_132 () ;
}
F_53 ( V_51 -> V_173 ) ;
V_51 -> V_173 = NULL ;
F_174 () ;
F_175 ( F_141 ( V_2 ) , & V_213 , - 1 ) ;
F_176 () ;
F_186 ( & V_51 -> V_227 , F_177 ) ;
return 0 ;
}
static int F_187 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_186 * V_186 = F_141 ( V_2 ) ;
struct V_187 * V_188 = & V_192 [ V_2 -> V_29 ] ;
T_5 V_11 = F_188 ( V_175 ) ;
int V_109 ;
T_5 V_233 = - 4096 ;
bool V_234 ;
V_235:
F_189 () ;
F_36 () ;
V_234 = ! F_145 ( V_188 , V_11 , V_186 ) ;
F_38 () ;
if ( ! V_234 ) {
if ( V_233 == - 4096 )
V_233 = V_236 + F_190 ( - 4096 - V_236 ) ;
else if ( V_233 >= - 4096 )
V_233 = - 4097 ;
V_11 = V_233 -- ;
goto V_235;
}
V_109 = F_155 ( V_2 , V_11 ) ;
if ( V_109 == - V_203 )
goto V_235;
if ( V_109 == - V_94 )
V_109 = 0 ;
return V_109 ;
}
bool F_191 ( const struct V_237 * V_238 ,
struct V_239 * V_240 , int V_241 )
{
return ( ( V_238 -> V_3 & V_242 ) ||
F_192 ( V_238 -> V_2 -> V_243 -> V_102 , V_240 , V_241 ) ) &&
F_193 ( V_240 , V_241 ) ;
}
bool F_194 ( const struct V_6 * V_7 ,
struct V_239 * V_240 , int V_241 )
{
return F_191 ( & F_7 ( V_7 ) , V_240 , V_241 ) ;
}
bool F_195 ( const struct V_6 * V_7 , int V_241 )
{
return F_194 ( V_7 , & V_244 , V_241 ) ;
}
bool F_196 ( const struct V_6 * V_7 , int V_241 )
{
return F_194 ( V_7 , F_141 ( V_7 -> V_2 ) -> V_240 , V_241 ) ;
}
static inline int F_197 ( const struct V_104 * V_1 , unsigned int V_245 )
{
return ( V_192 [ V_1 -> V_2 -> V_29 ] . V_3 & V_245 ) ||
F_193 ( F_141 ( V_1 -> V_2 ) -> V_240 , V_246 ) ;
}
static void
F_198 ( struct V_1 * V_2 , unsigned int V_205 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_205 && ! V_205 )
F_162 ( V_2 ) ;
else if ( ! V_51 -> V_205 && V_205 )
F_199 ( V_2 , & V_192 [ V_2 -> V_29 ] . V_247 ) ;
V_51 -> V_205 = V_205 ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_173 ;
unsigned long * V_248 ;
int V_109 = 0 ;
F_123 () ;
V_173 = V_192 [ V_2 -> V_29 ] . V_173 ;
if ( ! V_192 [ V_2 -> V_29 ] . V_222 ) {
V_109 = - V_249 ;
goto V_250;
}
if ( V_51 -> V_195 >= V_173 )
goto V_250;
V_248 = F_201 ( V_51 -> V_173 , F_202 ( V_173 ) , V_42 ) ;
if ( V_248 == NULL ) {
V_109 = - V_40 ;
goto V_250;
}
memset ( ( char * ) V_248 + F_202 ( V_51 -> V_195 ) , 0 ,
F_202 ( V_173 ) - F_202 ( V_51 -> V_195 ) ) ;
V_51 -> V_173 = V_248 ;
V_51 -> V_195 = V_173 ;
V_250:
F_132 () ;
return V_109 ;
}
static void F_203 ( int V_5 , long unsigned int V_173 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_251 ;
if ( ! V_51 -> V_225 )
return;
for ( V_251 = 0 ; V_251 < V_5 ; V_251 ++ )
if ( F_46 ( V_251 , & V_173 ) )
V_51 -> V_225 ( F_141 ( V_2 ) , V_251 + 1 ) ;
}
static int V_224 ( struct V_104 * V_1 , struct V_252 * V_253 ,
int V_254 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_186 * V_186 = F_141 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_255 * V_256 = (struct V_255 * ) V_253 ;
int V_109 ;
long unsigned int V_173 = V_256 -> V_257 ;
bool V_197 ;
if ( V_254 < sizeof( struct V_255 ) )
return - V_19 ;
if ( V_256 -> V_258 != V_259 )
return - V_19 ;
if ( V_173 ) {
if ( ! F_197 ( V_1 , V_260 ) )
return - V_261 ;
V_109 = F_200 ( V_2 ) ;
if ( V_109 )
return V_109 ;
}
V_197 = V_51 -> V_197 ;
if ( V_197 ) {
F_81 () ;
if ( V_256 -> V_262 != V_51 -> V_11 )
return - V_19 ;
}
if ( V_51 -> V_224 && V_173 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_51 -> V_195 ; V_5 ++ ) {
if ( ! F_46 ( V_5 , & V_173 ) )
continue;
V_109 = V_51 -> V_224 ( V_186 , V_5 + 1 ) ;
if ( ! V_109 )
continue;
F_203 ( V_5 , V_173 , V_2 ) ;
return V_109 ;
}
}
if ( ! V_197 ) {
V_109 = V_256 -> V_262 ?
F_155 ( V_2 , V_256 -> V_262 ) :
F_187 ( V_1 ) ;
if ( V_109 ) {
F_203 ( V_51 -> V_195 , V_173 , V_2 ) ;
return V_109 ;
}
}
if ( ! V_173 && ( V_51 -> V_173 == NULL || ! ( T_1 ) V_51 -> V_173 [ 0 ] ) )
return 0 ;
F_123 () ;
F_198 ( V_2 , V_51 -> V_205 +
F_204 ( V_173 ) -
F_204 ( V_51 -> V_173 [ 0 ] ) ) ;
V_51 -> V_173 [ 0 ] = ( V_51 -> V_173 [ 0 ] & ~ 0xffffffffUL ) | V_173 ;
F_151 ( V_2 ) ;
F_132 () ;
return 0 ;
}
static int F_205 ( struct V_104 * V_1 , struct V_252 * V_253 ,
int V_263 , int V_3 )
{
int V_109 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_255 * V_256 = (struct V_255 * ) V_253 ;
if ( V_263 < sizeof( V_253 -> V_264 ) )
return - V_19 ;
if ( V_253 -> V_264 == V_265 ) {
V_2 -> V_266 = V_267 ;
V_51 -> V_147 = 0 ;
V_51 -> V_12 = 0 ;
return 0 ;
}
if ( V_253 -> V_264 != V_259 )
return - V_19 ;
if ( ( V_256 -> V_257 || V_256 -> V_262 ) &&
! F_197 ( V_1 , V_268 ) )
return - V_261 ;
if ( ! V_51 -> V_197 )
V_109 = F_187 ( V_1 ) ;
if ( V_109 == 0 ) {
V_2 -> V_266 = V_269 ;
V_51 -> V_147 = V_256 -> V_262 ;
V_51 -> V_12 = F_206 ( V_256 -> V_257 ) ;
}
return V_109 ;
}
static int F_207 ( struct V_104 * V_1 , struct V_252 * V_253 ,
int * V_254 , int V_270 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_208 ( struct V_255 * , V_256 , V_253 ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_271 = 0 ;
* V_254 = sizeof( * V_256 ) ;
if ( V_270 ) {
V_256 -> V_262 = V_51 -> V_147 ;
V_256 -> V_257 = F_3 ( V_51 -> V_12 ) ;
} else {
V_256 -> V_262 = V_51 -> V_11 ;
V_256 -> V_257 = V_51 -> V_173 ? V_51 -> V_173 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_209 ( struct V_1 * V_272 , T_1 V_11 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_149 ( F_141 ( V_272 ) , V_272 -> V_29 , V_11 ) ;
if ( ! V_1 )
return F_210 ( - V_273 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_266 == V_269 &&
V_51 -> V_147 != F_2 ( V_272 ) -> V_11 ) {
F_112 ( V_1 ) ;
return F_210 ( - V_273 ) ;
}
return V_1 ;
}
struct V_1 * F_211 ( struct V_102 * V_274 )
{
struct V_275 * V_275 = F_212 ( V_274 ) ;
struct V_1 * V_1 ;
if ( ! F_213 ( V_275 -> V_276 ) )
return F_210 ( - V_277 ) ;
V_1 = F_214 ( V_275 ) -> V_2 ;
if ( V_1 -> V_278 != V_259 )
return F_210 ( - V_19 ) ;
F_150 ( V_1 ) ;
return V_1 ;
}
static struct V_6 * F_215 ( unsigned int V_107 ,
int V_279 )
{
struct V_6 * V_7 ;
void * V_14 ;
if ( V_107 <= V_280 || V_279 )
return F_6 ( V_107 , V_68 ) ;
V_107 = F_216 ( V_107 ) +
F_216 ( sizeof( struct V_281 ) ) ;
V_14 = F_217 ( V_107 ) ;
if ( V_14 == NULL )
return NULL ;
V_7 = F_218 ( V_14 , V_107 ) ;
if ( V_7 == NULL )
F_51 ( V_14 ) ;
else
V_7 -> V_142 = V_143 ;
return V_7 ;
}
int F_219 ( struct V_1 * V_2 , struct V_6 * V_7 ,
long * V_282 , struct V_1 * V_272 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_65 ( & V_2 -> V_167 ) > V_2 -> V_283 ||
F_46 ( V_53 , & V_51 -> V_54 ) ) &&
! F_25 ( V_7 ) ) {
F_126 ( V_60 , V_175 ) ;
if ( ! * V_282 ) {
if ( ! V_272 || F_1 ( V_272 ) )
F_40 ( V_2 ) ;
F_112 ( V_2 ) ;
F_102 ( V_7 ) ;
return - V_284 ;
}
F_130 ( V_285 ) ;
F_220 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_65 ( & V_2 -> V_167 ) > V_2 -> V_283 ||
F_46 ( V_53 , & V_51 -> V_54 ) ) &&
! F_121 ( V_2 , V_170 ) )
* V_282 = F_221 ( * V_282 ) ;
F_130 ( V_178 ) ;
F_131 ( & V_51 -> V_60 , & V_60 ) ;
F_112 ( V_2 ) ;
if ( F_222 ( V_175 ) ) {
F_102 ( V_7 ) ;
return F_223 ( * V_282 ) ;
}
return 1 ;
}
F_116 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = V_7 -> V_9 ;
F_35 ( V_7 ) ;
#ifdef F_111
if ( F_25 ( V_7 ) )
F_105 ( V_2 , V_7 ) ;
else if ( F_48 ( V_2 ) )
F_109 ( V_2 , V_7 ) ;
else
#endif
F_225 ( & V_2 -> V_59 , V_7 ) ;
V_2 -> V_286 ( V_2 ) ;
return V_9 ;
}
int F_226 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = F_224 ( V_2 , V_7 ) ;
F_112 ( V_2 ) ;
return V_9 ;
}
void F_227 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_102 ( V_7 ) ;
F_112 ( V_2 ) ;
}
static struct V_6 * F_228 ( struct V_6 * V_7 , T_2 V_287 )
{
int V_288 ;
F_64 ( V_7 -> V_2 != NULL ) ;
if ( F_25 ( V_7 ) )
return V_7 ;
V_288 = V_7 -> V_140 - V_7 -> V_141 ;
if ( F_26 ( V_7 -> V_41 ) || V_288 * 2 < V_7 -> V_166 )
return V_7 ;
if ( F_229 ( V_7 ) ) {
struct V_6 * V_39 = F_27 ( V_7 , V_287 ) ;
if ( ! V_39 )
return V_7 ;
F_230 ( V_7 ) ;
V_7 = V_39 ;
}
if ( ! F_231 ( V_7 , 0 , - V_288 , V_287 ) )
V_7 -> V_166 -= V_288 ;
return V_7 ;
}
static int F_232 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_272 )
{
int V_28 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_28 = - V_273 ;
if ( V_51 -> V_289 != NULL ) {
V_28 = V_7 -> V_9 ;
F_116 ( V_7 , V_2 ) ;
F_7 ( V_7 ) . V_2 = V_272 ;
F_39 ( V_2 , V_272 , V_7 ) ;
V_51 -> V_289 ( V_7 ) ;
F_230 ( V_7 ) ;
} else {
F_102 ( V_7 ) ;
}
F_112 ( V_2 ) ;
return V_28 ;
}
int F_104 ( struct V_1 * V_272 , struct V_6 * V_7 ,
T_1 V_11 , int V_290 )
{
struct V_1 * V_2 ;
int V_109 ;
long V_282 ;
V_7 = F_228 ( V_7 , F_233 () ) ;
V_282 = F_234 ( V_272 , V_290 ) ;
V_235:
V_2 = F_209 ( V_272 , V_11 ) ;
if ( F_235 ( V_2 ) ) {
F_102 ( V_7 ) ;
return F_236 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_232 ( V_2 , V_7 , V_272 ) ;
if ( F_237 ( V_2 , V_7 ) ) {
V_109 = V_7 -> V_9 ;
F_102 ( V_7 ) ;
F_112 ( V_2 ) ;
return V_109 ;
}
V_109 = F_219 ( V_2 , V_7 , & V_282 , V_272 ) ;
if ( V_109 == 1 )
goto V_235;
if ( V_109 )
return V_109 ;
return F_226 ( V_2 , V_7 ) ;
}
struct V_6 * F_238 ( struct V_1 * V_272 , unsigned int V_107 ,
unsigned int V_291 , T_1 V_147 ,
T_2 V_8 )
{
#ifdef F_111
unsigned int V_150 , V_292 ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 ;
struct V_81 * V_82 ;
struct V_118 * V_119 ;
V_2 = F_209 ( V_272 , V_147 ) ;
if ( F_235 ( V_2 ) )
goto V_26;
V_82 = & F_2 ( V_2 ) -> V_61 ;
if ( V_82 -> V_62 == NULL )
goto V_293;
V_292 = V_107 + V_291 ;
if ( V_82 -> V_87 - V_96 < V_292 )
goto V_293;
V_7 = F_239 ( V_8 ) ;
if ( V_7 == NULL )
goto V_78;
F_60 ( & V_2 -> V_59 . V_84 ) ;
if ( V_82 -> V_62 == NULL )
goto V_294;
V_150 = V_82 -> V_87 - V_96 ;
if ( V_150 < V_292 )
goto V_294;
F_88 ( V_82 ) ;
V_119 = F_86 ( V_82 , V_130 ) ;
if ( V_119 == NULL )
goto V_295;
F_95 ( V_7 , V_2 , V_82 , V_119 ) ;
F_82 ( V_119 , V_296 ) ;
F_42 ( & V_82 -> V_95 ) ;
F_87 ( V_82 ) ;
F_63 ( & V_2 -> V_59 . V_84 ) ;
return V_7 ;
V_295:
F_102 ( V_7 ) ;
F_63 ( & V_2 -> V_59 . V_84 ) ;
F_40 ( V_2 ) ;
V_78:
F_112 ( V_2 ) ;
return NULL ;
V_294:
F_102 ( V_7 ) ;
F_63 ( & V_2 -> V_59 . V_84 ) ;
V_293:
F_112 ( V_2 ) ;
V_26:
#endif
return F_6 ( V_107 , V_8 ) ;
}
int F_240 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_297 = 0 ;
struct V_194 * V_194 ;
F_183 ( ! F_1 ( V_2 ) ) ;
F_36 () ;
V_194 = F_241 ( V_192 [ V_2 -> V_29 ] . V_194 ) ;
if ( V_194 && V_5 - 1 < V_192 [ V_2 -> V_29 ] . V_173 )
V_297 = F_46 ( V_5 - 1 , V_194 -> V_196 ) ;
F_38 () ;
return V_297 ;
}
static int F_242 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_65 ( & V_2 -> V_167 ) <= V_2 -> V_283 &&
! F_46 ( V_53 , & V_51 -> V_54 ) ) {
F_116 ( V_7 , V_2 ) ;
F_224 ( V_2 , V_7 ) ;
return F_65 ( & V_2 -> V_167 ) > ( V_2 -> V_283 >> 1 ) ;
}
return - 1 ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_300 ;
if ( V_299 -> V_301 == V_2 )
return;
if ( V_51 -> V_11 == V_299 -> V_11 || V_299 -> V_5 - 1 >= V_51 -> V_195 ||
! F_46 ( V_299 -> V_5 - 1 , V_51 -> V_173 ) )
return;
if ( ! F_140 ( F_141 ( V_2 ) , V_299 -> V_186 ) ) {
if ( ! ( V_51 -> V_3 & V_302 ) )
return;
if ( ! F_244 ( F_141 ( V_2 ) , V_299 -> V_186 ) )
return;
if ( ! F_192 ( V_2 -> V_243 -> V_102 , V_299 -> V_186 -> V_240 ,
V_303 ) )
return;
}
if ( V_299 -> V_304 ) {
F_40 ( V_2 ) ;
return;
}
F_150 ( V_2 ) ;
if ( V_299 -> V_305 == NULL ) {
if ( F_229 ( V_299 -> V_7 ) ) {
V_299 -> V_305 = F_27 ( V_299 -> V_7 , V_299 -> V_287 ) ;
} else {
V_299 -> V_305 = F_245 ( V_299 -> V_7 ) ;
F_246 ( V_299 -> V_305 ) ;
}
}
if ( V_299 -> V_305 == NULL ) {
F_40 ( V_2 ) ;
V_299 -> V_304 = 1 ;
if ( V_51 -> V_3 & V_306 )
V_299 -> V_307 = 1 ;
goto V_26;
}
if ( V_299 -> V_308 && V_299 -> V_308 ( V_2 , V_299 -> V_305 , V_299 -> V_309 ) ) {
F_102 ( V_299 -> V_305 ) ;
V_299 -> V_305 = NULL ;
goto V_26;
}
if ( F_237 ( V_2 , V_299 -> V_305 ) ) {
F_102 ( V_299 -> V_305 ) ;
V_299 -> V_305 = NULL ;
goto V_26;
}
F_7 ( V_299 -> V_305 ) . V_310 = F_247 ( F_141 ( V_2 ) , V_299 -> V_186 ) ;
F_7 ( V_299 -> V_305 ) . V_311 = true ;
V_300 = F_242 ( V_2 , V_299 -> V_305 ) ;
if ( V_300 < 0 ) {
F_40 ( V_2 ) ;
if ( V_51 -> V_3 & V_306 )
V_299 -> V_307 = 1 ;
} else {
V_299 -> V_312 |= V_300 ;
V_299 -> V_313 = 1 ;
V_299 -> V_305 = NULL ;
}
V_26:
F_112 ( V_2 ) ;
}
int F_248 ( struct V_1 * V_272 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_287 ,
int (* F_249)( struct V_1 * V_314 , struct V_6 * V_7 , void * V_14 ) ,
void * V_315 )
{
struct V_186 * V_186 = F_141 ( V_272 ) ;
struct V_298 V_316 ;
struct V_1 * V_2 ;
V_7 = F_228 ( V_7 , V_287 ) ;
V_316 . V_301 = V_272 ;
V_316 . V_186 = V_186 ;
V_316 . V_11 = V_11 ;
V_316 . V_5 = V_5 ;
V_316 . V_304 = 0 ;
V_316 . V_307 = 0 ;
V_316 . V_312 = 0 ;
V_316 . V_313 = 0 ;
V_316 . V_287 = V_287 ;
V_316 . V_7 = V_7 ;
V_316 . V_305 = NULL ;
V_316 . V_308 = F_249 ;
V_316 . V_309 = V_315 ;
F_134 () ;
F_154 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_243 ( V_2 , & V_316 ) ;
F_230 ( V_7 ) ;
F_137 () ;
if ( V_316 . V_307 ) {
F_102 ( V_316 . V_305 ) ;
return - V_56 ;
}
F_230 ( V_316 . V_305 ) ;
if ( V_316 . V_313 ) {
if ( V_316 . V_312 && F_250 ( V_287 ) )
F_251 () ;
return 0 ;
}
return - V_317 ;
}
int F_103 ( struct V_1 * V_272 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_287 )
{
return F_248 ( V_272 , V_7 , V_11 , V_5 , V_287 ,
NULL , NULL ) ;
}
static int F_252 ( struct V_1 * V_2 , struct V_318 * V_299 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_28 = 0 ;
if ( V_2 == V_299 -> V_301 )
goto V_26;
if ( ! F_140 ( F_141 ( V_2 ) , F_141 ( V_299 -> V_301 ) ) )
goto V_26;
if ( V_51 -> V_11 == V_299 -> V_11 || V_299 -> V_5 - 1 >= V_51 -> V_195 ||
! F_46 ( V_299 -> V_5 - 1 , V_51 -> V_173 ) )
goto V_26;
if ( V_299 -> V_319 == V_56 && V_51 -> V_3 & V_52 ) {
V_28 = 1 ;
goto V_26;
}
V_2 -> V_55 = V_299 -> V_319 ;
V_2 -> V_57 ( V_2 ) ;
V_26:
return V_28 ;
}
int F_253 ( struct V_1 * V_272 , T_1 V_11 , T_1 V_5 , int V_319 )
{
struct V_318 V_316 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_316 . V_301 = V_272 ;
V_316 . V_11 = V_11 ;
V_316 . V_5 = V_5 ;
V_316 . V_319 = - V_319 ;
F_135 ( & T_4 ) ;
F_154 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_28 += F_252 ( V_2 , & V_316 ) ;
F_136 ( & T_4 ) ;
return V_28 ;
}
static void F_254 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_320 )
{
int V_232 , V_10 = ! ! V_320 , V_205 ;
V_232 = F_46 ( V_5 - 1 , V_51 -> V_173 ) ;
V_205 = V_51 -> V_205 - V_232 + V_10 ;
if ( V_10 )
F_255 ( V_5 - 1 , V_51 -> V_173 ) ;
else
F_256 ( V_5 - 1 , V_51 -> V_173 ) ;
F_198 ( & V_51 -> V_2 , V_205 ) ;
F_151 ( & V_51 -> V_2 ) ;
}
static int F_257 ( struct V_104 * V_1 , int V_321 , int V_322 ,
char T_6 * V_323 , unsigned int V_324 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_300 = 0 ;
int V_109 ;
if ( V_321 != V_325 )
return - V_326 ;
if ( V_322 != V_327 && V_322 != V_328 &&
V_324 >= sizeof( int ) &&
F_258 ( V_300 , ( unsigned int T_6 * ) V_323 ) )
return - V_329 ;
switch ( V_322 ) {
case V_330 :
if ( V_300 )
V_51 -> V_3 |= V_331 ;
else
V_51 -> V_3 &= ~ V_331 ;
V_109 = 0 ;
break;
case V_332 :
case V_333 : {
if ( ! F_197 ( V_1 , V_260 ) )
return - V_261 ;
V_109 = F_200 ( V_2 ) ;
if ( V_109 )
return V_109 ;
if ( ! V_300 || V_300 - 1 >= V_51 -> V_195 )
return - V_19 ;
if ( V_322 == V_332 && V_51 -> V_224 ) {
V_109 = V_51 -> V_224 ( F_141 ( V_2 ) , V_300 ) ;
if ( V_109 )
return V_109 ;
}
F_123 () ;
F_254 ( V_51 , V_300 ,
V_322 == V_332 ) ;
F_132 () ;
if ( V_322 == V_333 && V_51 -> V_225 )
V_51 -> V_225 ( F_141 ( V_2 ) , V_300 ) ;
V_109 = 0 ;
break;
}
case V_334 :
if ( V_300 )
V_51 -> V_3 |= V_306 ;
else
V_51 -> V_3 &= ~ V_306 ;
V_109 = 0 ;
break;
case V_335 :
if ( V_300 ) {
V_51 -> V_3 |= V_52 ;
F_45 ( V_53 , & V_51 -> V_54 ) ;
F_47 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_109 = 0 ;
break;
#ifdef F_111
case V_327 :
case V_328 : {
struct V_74 V_75 ;
if ( ! F_259 ( V_246 ) )
return - V_261 ;
if ( V_324 < sizeof( V_75 ) )
return - V_19 ;
if ( F_260 ( & V_75 , V_323 , sizeof( V_75 ) ) )
return - V_329 ;
V_109 = F_66 ( V_2 , & V_75 ,
V_322 == V_328 ) ;
break;
}
#endif
case V_336 :
if ( ! F_193 ( F_141 ( V_2 ) -> V_240 , V_303 ) )
return - V_261 ;
if ( V_300 )
V_51 -> V_3 |= V_302 ;
else
V_51 -> V_3 &= ~ V_302 ;
V_109 = 0 ;
break;
case V_337 :
if ( V_300 )
V_51 -> V_3 |= V_338 ;
else
V_51 -> V_3 &= ~ V_338 ;
V_109 = 0 ;
break;
default:
V_109 = - V_326 ;
}
return V_109 ;
}
static int F_261 ( struct V_104 * V_1 , int V_321 , int V_322 ,
char T_6 * V_323 , int T_6 * V_324 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_9 , V_300 , V_109 ;
if ( V_321 != V_325 )
return - V_326 ;
if ( F_258 ( V_9 , V_324 ) )
return - V_329 ;
if ( V_9 < 0 )
return - V_19 ;
switch ( V_322 ) {
case V_330 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_331 ? 1 : 0 ;
if ( F_262 ( V_9 , V_324 ) ||
F_262 ( V_300 , V_323 ) )
return - V_329 ;
V_109 = 0 ;
break;
case V_334 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_306 ? 1 : 0 ;
if ( F_262 ( V_9 , V_324 ) ||
F_262 ( V_300 , V_323 ) )
return - V_329 ;
V_109 = 0 ;
break;
case V_335 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_262 ( V_9 , V_324 ) ||
F_262 ( V_300 , V_323 ) )
return - V_329 ;
V_109 = 0 ;
break;
case V_339 : {
int V_127 , V_340 , V_341 ;
V_109 = 0 ;
F_134 () ;
for ( V_127 = 0 ; V_127 * 8 < V_51 -> V_195 ; V_127 += sizeof( T_1 ) ) {
if ( V_9 - V_127 < sizeof( T_1 ) )
break;
V_340 = V_127 / sizeof( unsigned long ) ;
V_341 = ( V_127 % sizeof( unsigned long ) ) * 8 ;
if ( F_262 ( ( T_1 ) ( V_51 -> V_173 [ V_340 ] >> V_341 ) ,
( T_1 T_6 * ) ( V_323 + V_127 ) ) ) {
V_109 = - V_329 ;
break;
}
}
if ( F_262 ( F_263 ( V_51 -> V_195 / 8 , sizeof( T_1 ) ) , V_324 ) )
V_109 = - V_329 ;
F_137 () ;
break;
}
case V_337 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_338 ? 1 : 0 ;
if ( F_262 ( V_9 , V_324 ) ||
F_262 ( V_300 , V_323 ) )
return - V_329 ;
V_109 = 0 ;
break;
default:
V_109 = - V_326 ;
}
return V_109 ;
}
static void F_264 ( struct V_145 * V_146 , struct V_6 * V_7 )
{
struct V_342 V_316 ;
V_316 . V_5 = F_7 ( V_7 ) . V_12 ;
F_265 ( V_146 , V_325 , V_330 , sizeof( V_316 ) , & V_316 ) ;
}
static void F_266 ( struct V_1 * V_2 , struct V_145 * V_146 ,
struct V_6 * V_7 )
{
if ( ! F_7 ( V_7 ) . V_311 )
return;
F_265 ( V_146 , V_325 , V_336 , sizeof( int ) ,
& F_7 ( V_7 ) . V_310 ) ;
}
static int F_267 ( struct V_104 * V_1 , struct V_145 * V_146 , T_7 V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_208 ( struct V_255 * , V_253 , V_146 -> V_343 ) ;
T_1 V_147 ;
T_1 V_12 ;
struct V_6 * V_7 ;
int V_109 ;
struct V_148 V_149 ;
T_1 V_344 = 0 ;
if ( V_146 -> V_151 & V_345 )
return - V_346 ;
V_109 = F_268 ( V_1 , V_146 , & V_149 , true ) ;
if ( V_109 < 0 )
return V_109 ;
if ( V_146 -> V_347 ) {
V_109 = - V_19 ;
if ( V_253 -> V_258 != V_259 )
goto V_26;
V_147 = V_253 -> V_262 ;
V_12 = F_206 ( V_253 -> V_257 ) ;
V_109 = - V_261 ;
if ( ( V_12 || V_147 ) &&
! F_197 ( V_1 , V_268 ) )
goto V_26;
V_344 |= V_242 ;
} else {
V_147 = V_51 -> V_147 ;
V_12 = V_51 -> V_12 ;
}
if ( ! V_51 -> V_197 ) {
V_109 = F_187 ( V_1 ) ;
if ( V_109 )
goto V_26;
} else {
F_81 () ;
}
if ( F_49 ( V_2 ) &&
F_269 ( & V_146 -> V_348 ) &&
V_146 -> V_348 . V_349 == 1 &&
V_146 -> V_348 . V_350 -> V_351 == NULL ) {
V_109 = F_97 ( V_2 , V_146 , V_147 , V_12 ,
& V_149 ) ;
goto V_26;
}
V_109 = - V_352 ;
if ( V_9 > V_2 -> V_353 - 32 )
goto V_26;
V_109 = - V_56 ;
V_7 = F_215 ( V_9 , V_12 ) ;
if ( V_7 == NULL )
goto V_26;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_149 . V_13 ;
F_7 ( V_7 ) . V_3 = V_344 ;
V_109 = - V_329 ;
if ( F_270 ( F_8 ( V_7 , V_9 ) , V_146 , V_9 ) ) {
F_102 ( V_7 ) ;
goto V_26;
}
V_109 = F_101 ( V_2 , V_7 ) ;
if ( V_109 ) {
F_102 ( V_7 ) ;
goto V_26;
}
if ( V_12 ) {
F_42 ( & V_7 -> V_153 ) ;
F_103 ( V_2 , V_7 , V_147 , V_12 , V_68 ) ;
}
V_109 = F_104 ( V_2 , V_7 , V_147 , V_146 -> V_151 & V_152 ) ;
V_26:
F_271 ( & V_149 ) ;
return V_109 ;
}
static int F_272 ( struct V_104 * V_1 , struct V_145 * V_146 , T_7 V_9 ,
int V_3 )
{
struct V_148 V_149 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_354 = V_3 & V_152 ;
T_7 V_355 ;
struct V_6 * V_7 , * V_356 ;
int V_109 , V_28 ;
if ( V_3 & V_345 )
return - V_346 ;
V_355 = 0 ;
V_7 = F_273 ( V_2 , V_3 , V_354 , & V_109 ) ;
if ( V_7 == NULL )
goto V_26;
V_356 = V_7 ;
#ifdef F_274
if ( F_10 ( F_114 ( V_7 ) -> V_357 ) ) {
if ( V_3 & V_358 )
V_356 = F_114 ( V_7 ) -> V_357 ;
}
#endif
V_51 -> V_359 = F_275 ( V_51 -> V_359 , V_9 ) ;
V_51 -> V_359 = F_276 ( T_7 , V_51 -> V_359 ,
16384 ) ;
V_355 = V_356 -> V_9 ;
if ( V_9 < V_355 ) {
V_146 -> V_151 |= V_360 ;
V_355 = V_9 ;
}
F_277 ( V_356 ) ;
V_109 = F_278 ( V_356 , 0 , V_146 , V_355 ) ;
if ( V_146 -> V_343 ) {
F_208 ( struct V_255 * , V_253 , V_146 -> V_343 ) ;
V_253 -> V_258 = V_259 ;
V_253 -> V_271 = 0 ;
V_253 -> V_262 = F_7 ( V_7 ) . V_11 ;
V_253 -> V_257 = F_3 ( F_7 ( V_7 ) . V_12 ) ;
V_146 -> V_347 = sizeof( * V_253 ) ;
}
if ( V_51 -> V_3 & V_331 )
F_264 ( V_146 , V_7 ) ;
if ( V_51 -> V_3 & V_302 )
F_266 ( V_2 , V_146 , V_7 ) ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_13 = * F_279 ( V_7 ) ;
if ( V_3 & V_360 )
V_355 = V_356 -> V_9 ;
F_280 ( V_2 , V_7 ) ;
if ( V_51 -> V_135 &&
F_65 ( & V_2 -> V_167 ) <= V_2 -> V_283 / 2 ) {
V_28 = F_92 ( V_2 ) ;
if ( V_28 ) {
V_2 -> V_55 = - V_28 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_281 ( V_1 , V_146 , & V_149 , V_3 ) ;
V_26:
F_43 ( V_2 ) ;
return V_109 ? : V_355 ;
}
static void F_282 ( struct V_1 * V_2 )
{
F_283 () ;
}
struct V_1 *
F_284 ( struct V_186 * V_186 , int V_361 , struct V_23 * V_23 ,
struct V_362 * V_363 )
{
struct V_104 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_194 * V_194 = NULL ;
struct V_207 * V_208 = V_363 ? V_363 -> V_208 : NULL ;
unsigned int V_173 ;
F_183 ( ! V_192 ) ;
if ( V_361 < 0 || V_361 >= V_220 )
return NULL ;
if ( F_285 ( V_212 , V_218 , V_361 , & V_1 ) )
return NULL ;
if ( F_163 ( V_186 , V_1 , V_208 , V_361 , 1 ) < 0 )
goto V_364;
V_2 = V_1 -> V_2 ;
if ( ! V_363 || V_363 -> V_173 < 32 )
V_173 = 32 ;
else
V_173 = V_363 -> V_173 ;
V_194 = F_286 ( sizeof( * V_194 ) + F_202 ( V_173 ) , V_68 ) ;
if ( ! V_194 )
goto V_365;
V_2 -> V_286 = F_282 ;
if ( V_363 && V_363 -> V_366 )
F_2 ( V_2 ) -> V_289 = V_363 -> V_366 ;
if ( F_155 ( V_2 , 0 ) )
goto V_365;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_123 () ;
if ( ! V_192 [ V_361 ] . V_222 ) {
V_192 [ V_361 ] . V_173 = V_173 ;
F_287 ( V_192 [ V_361 ] . V_194 , V_194 ) ;
V_192 [ V_361 ] . V_208 = V_208 ;
V_192 [ V_361 ] . V_23 = V_23 ;
if ( V_363 ) {
V_192 [ V_361 ] . F_169 = V_363 -> F_169 ;
V_192 [ V_361 ] . F_170 = V_363 -> F_170 ;
V_192 [ V_361 ] . V_3 = V_363 -> V_3 ;
if ( V_363 -> V_367 )
V_192 [ V_361 ] . V_367 = V_363 -> V_367 ;
}
V_192 [ V_361 ] . V_222 = 1 ;
} else {
F_53 ( V_194 ) ;
V_192 [ V_361 ] . V_222 ++ ;
}
F_132 () ;
return V_2 ;
V_365:
F_53 ( V_194 ) ;
F_288 ( V_2 ) ;
return NULL ;
V_364:
F_289 ( V_1 ) ;
return NULL ;
}
void
F_288 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_243 == NULL )
return;
F_289 ( V_2 -> V_243 ) ;
}
int F_290 ( struct V_1 * V_2 , unsigned int V_173 )
{
struct V_194 * V_10 , * V_232 ;
struct V_187 * V_193 = & V_192 [ V_2 -> V_29 ] ;
if ( V_173 < 32 )
V_173 = 32 ;
if ( F_202 ( V_193 -> V_173 ) < F_202 ( V_173 ) ) {
V_10 = F_286 ( sizeof( * V_10 ) + F_202 ( V_173 ) , V_42 ) ;
if ( ! V_10 )
return - V_40 ;
V_232 = F_152 ( V_193 -> V_194 ) ;
memcpy ( V_10 -> V_196 , V_232 -> V_196 , F_202 ( V_193 -> V_173 ) ) ;
F_287 ( V_193 -> V_194 , V_10 ) ;
F_185 ( V_232 , V_227 ) ;
}
V_193 -> V_173 = V_173 ;
return 0 ;
}
int F_291 ( struct V_1 * V_2 , unsigned int V_173 )
{
int V_109 ;
F_123 () ;
V_109 = F_290 ( V_2 , V_173 ) ;
F_132 () ;
return V_109 ;
}
void F_292 ( struct V_1 * V_368 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_187 * V_193 = & V_192 [ V_368 -> V_29 ] ;
F_154 (sk, &tbl->mc_list)
F_254 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_369 *
F_293 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_370 , int type , int V_9 , int V_3 )
{
struct V_369 * V_371 ;
int V_107 = F_294 ( V_9 ) ;
V_371 = (struct V_369 * ) F_8 ( V_7 , F_295 ( V_107 ) ) ;
V_371 -> V_372 = type ;
V_371 -> V_373 = V_107 ;
V_371 -> V_374 = V_3 ;
V_371 -> V_375 = V_11 ;
V_371 -> V_376 = V_370 ;
if ( ! F_296 ( V_107 ) || F_295 ( V_107 ) - V_107 != 0 )
memset ( F_297 ( V_371 ) + V_9 , 0 , F_295 ( V_107 ) - V_107 ) ;
return V_371 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_377 * V_168 ;
struct V_6 * V_7 = NULL ;
struct V_369 * V_371 ;
int V_9 , V_109 = - V_56 ;
int V_378 ;
int V_379 ;
F_70 ( V_51 -> V_208 ) ;
if ( ! V_51 -> V_135 ) {
V_109 = - V_19 ;
goto V_380;
}
if ( ! F_48 ( V_2 ) &&
F_65 ( & V_2 -> V_167 ) >= V_2 -> V_283 )
goto V_380;
V_168 = & V_51 -> V_168 ;
V_378 = F_298 ( int , V_168 -> V_381 , V_280 ) ;
if ( V_378 < V_51 -> V_359 ) {
V_379 = V_51 -> V_359 ;
V_7 = F_299 ( V_2 , V_379 , V_51 -> V_11 ,
V_68 |
V_71 |
V_72 ) ;
}
if ( ! V_7 ) {
V_379 = V_378 ;
V_7 = F_299 ( V_2 , V_379 , V_51 -> V_11 ,
V_68 ) ;
}
if ( ! V_7 )
goto V_380;
if ( ! F_48 ( V_2 ) )
F_300 ( V_7 , F_301 ( V_7 ) - V_379 ) ;
F_116 ( V_7 , V_2 ) ;
V_9 = V_168 -> V_382 ( V_7 , V_168 ) ;
if ( V_9 > 0 ) {
F_71 ( V_51 -> V_208 ) ;
if ( F_237 ( V_2 , V_7 ) )
F_102 ( V_7 ) ;
else
F_224 ( V_2 , V_7 ) ;
return 0 ;
}
V_371 = F_302 ( V_7 , V_168 , V_383 , sizeof( V_9 ) , V_384 ) ;
if ( ! V_371 )
goto V_380;
F_303 ( V_168 , V_371 ) ;
memcpy ( F_297 ( V_371 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_237 ( V_2 , V_7 ) )
F_102 ( V_7 ) ;
else
F_224 ( V_2 , V_7 ) ;
if ( V_168 -> V_169 )
V_168 -> V_169 ( V_168 ) ;
V_51 -> V_135 = false ;
F_71 ( V_51 -> V_208 ) ;
F_19 ( V_168 -> V_23 ) ;
F_230 ( V_168 -> V_7 ) ;
return 0 ;
V_380:
F_71 ( V_51 -> V_208 ) ;
F_102 ( V_7 ) ;
return V_109 ;
}
int F_304 ( struct V_1 * V_272 , struct V_6 * V_7 ,
const struct V_369 * V_371 ,
struct V_385 * V_386 )
{
struct V_377 * V_168 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_28 ;
if ( F_25 ( V_7 ) ) {
V_7 = F_305 ( V_7 , V_68 ) ;
if ( V_7 == NULL )
return - V_56 ;
} else
F_42 ( & V_7 -> V_153 ) ;
V_2 = F_149 ( F_141 ( V_272 ) , V_272 -> V_29 , F_7 ( V_7 ) . V_11 ) ;
if ( V_2 == NULL ) {
V_28 = - V_273 ;
goto V_387;
}
V_51 = F_2 ( V_2 ) ;
F_70 ( V_51 -> V_208 ) ;
if ( V_51 -> V_135 ) {
V_28 = - V_94 ;
goto V_388;
}
if ( ! F_173 ( V_386 -> V_23 ) ) {
V_28 = - V_221 ;
goto V_388;
}
V_168 = & V_51 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_106 = V_386 -> V_106 ;
V_168 -> V_382 = V_386 -> V_382 ;
V_168 -> V_169 = V_386 -> V_169 ;
V_168 -> V_371 = V_371 ;
V_168 -> V_14 = V_386 -> V_14 ;
V_168 -> V_23 = V_386 -> V_23 ;
V_168 -> V_381 = V_386 -> V_381 ;
V_168 -> V_7 = V_7 ;
V_51 -> V_135 = true ;
F_71 ( V_51 -> V_208 ) ;
if ( V_168 -> V_106 )
V_168 -> V_106 ( V_168 ) ;
V_28 = F_92 ( V_2 ) ;
F_112 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return - V_389 ;
V_388:
F_112 ( V_2 ) ;
F_71 ( V_51 -> V_208 ) ;
V_387:
F_102 ( V_7 ) ;
return V_28 ;
}
void F_306 ( struct V_6 * V_390 , struct V_369 * V_371 , int V_109 )
{
struct V_6 * V_7 ;
struct V_369 * V_391 ;
struct V_392 * V_393 ;
T_7 V_394 = sizeof( * V_393 ) ;
struct V_50 * V_51 = F_2 ( F_7 ( V_390 ) . V_2 ) ;
if ( ! ( V_51 -> V_3 & V_338 ) && V_109 )
V_394 += V_373 ( V_371 ) ;
V_7 = F_299 ( V_390 -> V_2 , F_307 ( V_394 ) ,
F_7 ( V_390 ) . V_11 , V_68 ) ;
if ( ! V_7 ) {
struct V_1 * V_2 ;
V_2 = F_149 ( F_141 ( V_390 -> V_2 ) ,
V_390 -> V_2 -> V_29 ,
F_7 ( V_390 ) . V_11 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_112 ( V_2 ) ;
}
return;
}
V_391 = F_293 ( V_7 , F_7 ( V_390 ) . V_11 , V_371 -> V_376 ,
V_395 , V_394 , 0 ) ;
V_393 = F_297 ( V_391 ) ;
V_393 -> error = V_109 ;
memcpy ( & V_393 -> V_146 , V_371 , V_394 > sizeof( * V_393 ) ? V_371 -> V_373 : sizeof( * V_371 ) ) ;
F_104 ( V_390 -> V_2 , V_7 , F_7 ( V_390 ) . V_11 , V_152 ) ;
}
int F_308 ( struct V_6 * V_7 , int (* V_168)( struct V_6 * ,
struct V_369 * ) )
{
struct V_369 * V_371 ;
int V_109 ;
while ( V_7 -> V_9 >= F_307 ( 0 ) ) {
int V_396 ;
V_371 = F_309 ( V_7 ) ;
V_109 = 0 ;
if ( V_371 -> V_373 < V_397 || V_7 -> V_9 < V_371 -> V_373 )
return 0 ;
if ( ! ( V_371 -> V_374 & V_398 ) )
goto V_399;
if ( V_371 -> V_372 < V_400 )
goto V_399;
V_109 = V_168 ( V_7 , V_371 ) ;
if ( V_109 == - V_389 )
goto V_401;
V_399:
if ( V_371 -> V_374 & V_402 || V_109 )
F_306 ( V_7 , V_371 , V_109 ) ;
V_401:
V_396 = F_295 ( V_371 -> V_373 ) ;
if ( V_396 > V_7 -> V_9 )
V_396 = V_7 -> V_9 ;
F_310 ( V_7 , V_396 ) ;
}
return 0 ;
}
int F_311 ( struct V_1 * V_2 , struct V_6 * V_7 , T_1 V_11 ,
unsigned int V_5 , int V_403 , T_2 V_3 )
{
int V_109 = 0 ;
if ( V_5 ) {
int V_404 = 0 ;
if ( V_403 ) {
F_42 ( & V_7 -> V_153 ) ;
V_404 = V_11 ;
}
V_109 = F_312 ( V_2 , V_7 , V_404 , V_5 , V_3 ) ;
}
if ( V_403 ) {
int V_295 ;
V_295 = F_313 ( V_2 , V_7 , V_11 ) ;
if ( ! V_109 || V_109 == - V_317 )
V_109 = V_295 ;
}
return V_109 ;
}
static int F_314 ( struct V_405 * V_406 )
{
int V_109 ;
V_109 = F_315 ( & V_192 [ V_406 -> V_407 ] . V_189 , & V_406 -> V_408 ) ;
if ( V_109 ) {
V_406 -> V_407 = V_220 ;
return V_109 ;
}
V_109 = F_316 ( & V_406 -> V_408 ) ;
return V_109 == - V_284 ? 0 : V_109 ;
}
static void F_317 ( struct V_405 * V_406 )
{
F_318 ( & V_406 -> V_408 ) ;
F_319 ( & V_406 -> V_408 ) ;
}
static void * F_320 ( struct V_409 * V_370 )
{
struct V_405 * V_406 = V_370 -> V_410 ;
struct V_50 * V_51 ;
do {
for (; ; ) {
int V_109 ;
V_51 = F_321 ( & V_406 -> V_408 ) ;
if ( F_235 ( V_51 ) ) {
if ( F_236 ( V_51 ) == - V_284 )
continue;
return V_51 ;
}
if ( V_51 )
break;
F_317 ( V_406 ) ;
if ( ++ V_406 -> V_407 >= V_220 )
return NULL ;
V_109 = F_314 ( V_406 ) ;
if ( V_109 )
return F_210 ( V_109 ) ;
}
} while ( F_141 ( & V_51 -> V_2 ) != F_322 ( V_370 ) );
return V_51 ;
}
static void * F_323 ( struct V_409 * V_370 , T_8 * V_411 )
{
struct V_405 * V_406 = V_370 -> V_410 ;
void * V_412 = V_413 ;
T_8 V_127 ;
int V_109 ;
V_406 -> V_407 = 0 ;
V_109 = F_314 ( V_406 ) ;
if ( V_109 )
return F_210 ( V_109 ) ;
for ( V_127 = * V_411 ; V_127 && V_412 && ! F_235 ( V_412 ) ; V_127 -- )
V_412 = F_320 ( V_370 ) ;
return V_412 ;
}
static void * F_324 ( struct V_409 * V_370 , void * V_414 , T_8 * V_127 )
{
++ * V_127 ;
return F_320 ( V_370 ) ;
}
static void F_325 ( struct V_409 * V_370 , void * V_414 )
{
struct V_405 * V_406 = V_370 -> V_410 ;
if ( V_406 -> V_407 >= V_220 )
return;
F_317 ( V_406 ) ;
}
static int F_326 ( struct V_409 * V_370 , void * V_414 )
{
if ( V_414 == V_413 ) {
F_327 ( V_370 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_415 = V_414 ;
struct V_50 * V_51 = F_2 ( V_415 ) ;
F_328 ( V_370 , L_6 ,
V_415 ,
V_415 -> V_29 ,
V_51 -> V_11 ,
V_51 -> V_173 ? ( T_1 ) V_51 -> V_173 [ 0 ] : 0 ,
F_329 ( V_415 ) ,
F_330 ( V_415 ) ,
V_51 -> V_135 ,
F_65 ( & V_415 -> V_204 ) ,
F_65 ( & V_415 -> V_58 ) ,
F_331 ( V_415 )
) ;
}
return 0 ;
}
static int F_332 ( struct V_275 * V_275 , struct V_102 * V_102 )
{
return F_333 ( V_275 , V_102 , & V_416 ,
sizeof( struct V_405 ) ) ;
}
int F_334 ( struct V_417 * V_418 )
{
return F_335 ( & V_230 , V_418 ) ;
}
int F_336 ( struct V_417 * V_418 )
{
return F_337 ( & V_230 , V_418 ) ;
}
static int T_9 F_338 ( struct V_186 * V_186 )
{
#ifdef F_339
if ( ! F_340 ( L_7 , 0 , V_186 -> V_419 , & V_420 ) )
return - V_40 ;
#endif
return 0 ;
}
static void T_10 F_341 ( struct V_186 * V_186 )
{
#ifdef F_339
F_342 ( L_7 , V_186 -> V_419 ) ;
#endif
}
static void T_11 F_343 ( void )
{
struct V_194 * V_194 ;
int V_173 = 32 ;
V_194 = F_286 ( sizeof( * V_194 ) + F_202 ( V_173 ) , V_68 ) ;
if ( ! V_194 )
F_344 ( L_8 ) ;
F_123 () ;
V_192 [ V_31 ] . V_173 = V_173 ;
F_287 ( V_192 [ V_31 ] . V_194 , V_194 ) ;
V_192 [ V_31 ] . V_23 = V_421 ;
V_192 [ V_31 ] . V_222 = 1 ;
V_192 [ V_31 ] . V_3 = V_268 ;
F_132 () ;
}
static inline T_1 F_345 ( const void * V_14 , T_1 V_9 , T_1 V_422 )
{
const struct V_50 * V_51 = V_14 ;
struct V_182 V_180 ;
F_143 ( & V_180 , F_141 ( & V_51 -> V_2 ) , V_51 -> V_11 ) ;
return F_346 ( ( T_1 * ) & V_180 , V_423 / sizeof( T_1 ) , V_422 ) ;
}
static int T_11 F_347 ( void )
{
int V_65 ;
int V_109 = F_348 ( & V_213 , 0 ) ;
if ( V_109 != 0 )
goto V_26;
F_349 ( sizeof( struct V_237 ) > F_350 ( struct V_6 , V_168 ) ) ;
V_192 = F_58 ( V_220 , sizeof( * V_192 ) , V_68 ) ;
if ( ! V_192 )
goto F_344;
for ( V_65 = 0 ; V_65 < V_220 ; V_65 ++ ) {
if ( F_351 ( & V_192 [ V_65 ] . V_189 ,
& V_190 ) < 0 ) {
while ( -- V_65 > 0 )
F_352 ( & V_192 [ V_65 ] . V_189 ) ;
F_53 ( V_192 ) ;
goto F_344;
}
}
F_353 ( & V_22 ) ;
F_343 () ;
F_354 ( & V_424 ) ;
F_355 ( & V_425 ) ;
F_356 () ;
V_26:
return V_109 ;
F_344:
F_344 ( L_9 ) ;
}
