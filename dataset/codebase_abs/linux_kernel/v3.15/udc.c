static inline int F_1 ( int V_1 , int V_2 )
{
return V_1 + ( V_2 ? 16 : 0 ) ;
}
static inline int F_2 ( struct V_3 * V_4 , int V_5 )
{
int V_6 = 16 - V_4 -> V_7 / 2 ;
if ( V_5 >= V_4 -> V_7 / 2 )
V_5 += V_6 ;
return V_5 ;
}
static int F_3 ( struct V_3 * V_4 , T_1 V_8 )
{
if ( V_8 ) {
F_4 ( V_4 , V_9 , ~ 0 , V_8 ) ;
F_4 ( V_4 , V_10 , ~ 0 ,
V_11 | V_12 | V_13 | V_14 | V_15 ) ;
F_4 ( V_4 , V_16 , V_17 , V_17 ) ;
} else {
F_4 ( V_4 , V_10 , ~ 0 , 0 ) ;
F_4 ( V_4 , V_16 , V_17 , 0 ) ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
do {
F_4 ( V_4 , V_18 , ~ 0 , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_18 , F_6 ( V_5 ) ) )
F_8 () ;
} while ( F_7 ( V_4 , V_19 , F_6 ( V_5 ) ) );
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
F_5 ( V_4 , V_1 , V_2 ) ;
F_4 ( V_4 , V_20 + V_1 ,
V_2 ? V_21 : V_22 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , int V_1 , int V_2 , int type )
{
T_1 V_23 , V_24 ;
if ( V_2 ) {
V_23 = V_25 ;
V_24 = type << F_11 ( V_23 ) ;
V_23 |= V_26 ;
V_23 |= V_27 ;
V_24 |= V_27 ;
V_23 |= V_21 ;
V_24 |= V_21 ;
} else {
V_23 = V_28 ;
V_24 = type << F_11 ( V_23 ) ;
V_23 |= V_29 ;
V_23 |= V_30 ;
V_24 |= V_30 ;
V_23 |= V_22 ;
V_24 |= V_22 ;
}
F_4 ( V_4 , V_20 + V_1 , V_23 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
T_1 V_23 = V_2 ? V_26 : V_29 ;
return F_7 ( V_4 , V_20 + V_1 , V_23 ) ? 1 : 0 ;
}
static int F_13 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_31 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_31 && V_2 == V_32 && F_7 ( V_4 , V_33 , F_6 ( V_1 ) ) )
return - V_34 ;
F_4 ( V_4 , V_35 , ~ 0 , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_35 , F_6 ( V_5 ) ) )
F_8 () ;
if ( V_31 && V_2 == V_32 && F_7 ( V_4 , V_33 , F_6 ( V_1 ) ) )
return - V_34 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_36 )
{
if ( V_36 != 0 && V_36 != 1 )
return - V_37 ;
do {
enum V_38 V_39 = V_20 + V_1 ;
T_1 V_40 = V_2 ? V_26 : V_29 ;
T_1 V_41 = V_2 ? V_27 : V_30 ;
F_4 ( V_4 , V_39 , V_40 | V_41 ,
V_36 ? V_40 : V_41 ) ;
} while ( V_36 != F_12 ( V_4 , V_1 , V_2 ) );
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
return V_4 -> V_42 . V_43 ? F_7 ( V_4 , V_44 , V_45 ) :
F_7 ( V_4 , V_46 , V_47 ) ;
}
static T_1 F_16 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_10 , ~ 0 ) ;
}
static T_1 F_17 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_48 , ~ 0 ) ;
}
static int F_18 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_19 ( V_4 , V_49 , F_6 ( V_5 ) ) ;
}
static T_1 F_20 ( struct V_3 * V_4 )
{
T_1 V_39 = F_17 ( V_4 ) & F_16 ( V_4 ) ;
F_4 ( V_4 , V_48 , ~ 0 , V_39 ) ;
return V_39 ;
}
static int F_21 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , V_16 , V_50 , 0 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , V_16 , V_50 , V_50 ) ;
}
static void F_24 ( struct V_3 * V_4 , T_2 V_36 )
{
F_4 ( V_4 , V_51 , V_52 ,
V_36 << F_11 ( V_52 ) ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
F_24 ( V_4 , 0 ) ;
F_4 ( V_4 , V_18 , ~ 0 , ~ 0 ) ;
F_4 ( V_4 , V_33 , 0 , 0 ) ;
F_4 ( V_4 , V_49 , 0 , 0 ) ;
while ( F_7 ( V_4 , V_35 , ~ 0 ) )
F_26 ( 10 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_54 , struct V_55 * V_56 ,
unsigned V_57 )
{
int V_58 ;
T_1 V_59 ;
struct V_60 * V_61 , * V_62 = F_28 ( sizeof( struct V_60 ) ,
V_63 ) ;
if ( V_62 == NULL )
return - V_64 ;
V_62 -> V_65 = F_29 ( V_54 -> V_66 , V_63 ,
& V_62 -> V_8 ) ;
if ( V_62 -> V_65 == NULL ) {
F_30 ( V_62 ) ;
return - V_64 ;
}
memset ( V_62 -> V_65 , 0 , sizeof( struct V_67 ) ) ;
V_62 -> V_65 -> V_68 = F_31 ( V_57 << F_11 ( V_69 ) ) ;
V_62 -> V_65 -> V_68 &= F_31 ( V_69 ) ;
V_62 -> V_65 -> V_68 |= F_31 ( V_70 ) ;
if ( V_54 -> type == V_71 && V_54 -> V_2 == V_72 ) {
T_1 V_73 = V_56 -> V_74 . V_57 / V_54 -> V_75 . V_76 ;
if ( V_56 -> V_74 . V_57 == 0
|| V_56 -> V_74 . V_57 % V_54 -> V_75 . V_76 )
V_73 ++ ;
V_62 -> V_65 -> V_68 |= V_73 << F_11 ( V_77 ) ;
}
V_59 = ( T_1 ) ( V_56 -> V_74 . V_8 + V_56 -> V_74 . V_78 ) ;
if ( V_57 ) {
V_62 -> V_65 -> V_79 [ 0 ] = F_31 ( V_59 ) ;
for ( V_58 = 1 ; V_58 < V_80 ; V_58 ++ ) {
T_1 V_79 = V_59 + V_58 * V_81 ;
V_79 &= ~ V_82 ;
V_62 -> V_65 -> V_79 [ V_58 ] = F_31 ( V_79 ) ;
}
}
V_56 -> V_74 . V_78 += V_57 ;
if ( ! F_32 ( & V_56 -> V_83 ) ) {
V_61 = F_33 ( V_56 -> V_83 . V_84 ,
struct V_60 , V_85 ) ;
V_61 -> V_65 -> V_86 = F_31 ( V_62 -> V_8 ) ;
}
F_34 ( & V_62 -> V_85 ) ;
F_35 ( & V_62 -> V_85 , & V_56 -> V_83 ) ;
return 0 ;
}
static inline T_2 F_36 ( struct V_53 * V_75 )
{
return ( ( V_75 -> V_2 == V_72 ) ? V_87 : 0 ) | V_75 -> V_1 ;
}
static int F_37 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
struct V_3 * V_4 = V_54 -> V_4 ;
int V_88 = 0 ;
unsigned V_89 = V_56 -> V_74 . V_57 ;
int V_90 = V_80 ;
struct V_60 * V_91 , * V_61 ;
if ( V_56 -> V_74 . V_92 == - V_93 )
return - V_93 ;
V_56 -> V_74 . V_92 = - V_93 ;
V_88 = F_38 ( & V_4 -> V_94 , & V_56 -> V_74 , V_54 -> V_2 ) ;
if ( V_88 )
return V_88 ;
if ( V_56 -> V_74 . V_8 % V_95 )
V_90 -- ;
if ( V_89 == 0 )
F_27 ( V_54 , V_56 , 0 ) ;
while ( V_89 > 0 ) {
unsigned V_96 = F_39 ( V_56 -> V_74 . V_57 - V_56 -> V_74 . V_78 ,
( unsigned ) ( V_90 * V_81 ) ) ;
F_27 ( V_54 , V_56 , V_96 ) ;
V_89 -= V_96 ;
}
if ( V_56 -> V_74 . V_97 && V_56 -> V_74 . V_57
&& ( V_56 -> V_74 . V_57 % V_54 -> V_75 . V_76 == 0 ) )
F_27 ( V_54 , V_56 , 0 ) ;
V_91 = F_40 ( & V_56 -> V_83 , struct V_60 , V_85 ) ;
V_61 = F_33 ( V_56 -> V_83 . V_84 ,
struct V_60 , V_85 ) ;
V_61 -> V_65 -> V_86 = F_31 ( V_98 ) ;
if ( ! V_56 -> V_74 . V_99 )
V_61 -> V_65 -> V_68 |= F_31 ( V_100 ) ;
F_41 () ;
V_56 -> V_74 . V_78 = 0 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) ) {
struct V_55 * V_103 ;
int V_5 = F_1 ( V_54 -> V_1 , V_54 -> V_2 ) ;
int V_104 ;
struct V_60 * V_105 ;
T_1 V_86 = V_91 -> V_8 & V_106 ;
V_103 = F_33 ( V_54 -> V_101 . V_102 . V_84 ,
struct V_55 , V_102 ) ;
V_105 = F_33 ( V_103 -> V_83 . V_84 ,
struct V_60 , V_85 ) ;
V_105 -> V_65 -> V_86 = F_31 ( V_86 ) ;
F_41 () ;
if ( F_7 ( V_4 , V_35 , F_6 ( V_5 ) ) )
goto V_107;
do {
F_4 ( V_4 , V_16 , V_108 , V_108 ) ;
V_104 = F_7 ( V_4 , V_19 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_16 , V_108 ) );
F_4 ( V_4 , V_16 , V_108 , 0 ) ;
if ( V_104 )
goto V_107;
}
V_54 -> V_101 . V_65 -> V_85 . V_86 = F_31 ( V_91 -> V_8 ) ;
V_54 -> V_101 . V_65 -> V_85 . V_68 &=
F_31 ( ~ ( V_109 | V_70 ) ) ;
if ( V_54 -> type == V_71 && V_54 -> V_2 == V_32 ) {
T_1 V_73 = V_56 -> V_74 . V_57 / V_54 -> V_75 . V_76 ;
if ( V_56 -> V_74 . V_57 == 0
|| V_56 -> V_74 . V_57 % V_54 -> V_75 . V_76 )
V_73 ++ ;
V_54 -> V_101 . V_65 -> V_110 |= V_73 << F_11 ( V_111 ) ;
}
F_41 () ;
V_88 = F_13 ( V_4 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type == V_112 ) ;
V_107:
return V_88 ;
}
static void F_42 ( struct V_53 * V_54 )
{
struct V_60 * V_113 = V_54 -> V_114 ;
F_43 ( V_54 -> V_66 , V_113 -> V_65 , V_113 -> V_8 ) ;
V_54 -> V_114 = NULL ;
F_30 ( V_113 ) ;
}
static int F_44 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
T_1 V_115 ;
struct V_60 * V_62 , * V_116 ;
unsigned V_117 ;
unsigned V_78 = V_56 -> V_74 . V_57 ;
if ( V_56 -> V_74 . V_92 != - V_93 )
return - V_37 ;
V_56 -> V_74 . V_92 = 0 ;
F_45 (node, tmpnode, &hwreq->tds, td) {
V_115 = F_46 ( V_62 -> V_65 -> V_68 ) ;
if ( ( V_70 & V_115 ) != 0 ) {
V_56 -> V_74 . V_92 = - V_93 ;
return - V_118 ;
}
V_117 = ( V_115 & V_69 ) ;
V_117 >>= F_11 ( V_69 ) ;
V_78 -= V_117 ;
V_56 -> V_74 . V_92 = V_115 & V_119 ;
if ( ( V_109 & V_56 -> V_74 . V_92 ) ) {
V_56 -> V_74 . V_92 = - V_120 ;
break;
} else if ( ( V_121 & V_56 -> V_74 . V_92 ) ) {
V_56 -> V_74 . V_92 = - V_122 ;
break;
} else if ( ( V_123 & V_56 -> V_74 . V_92 ) ) {
V_56 -> V_74 . V_92 = - V_124 ;
break;
}
if ( V_117 ) {
if ( V_54 -> V_2 ) {
V_56 -> V_74 . V_92 = - V_122 ;
break;
}
}
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
V_54 -> V_114 = V_62 ;
F_47 ( & V_62 -> V_85 ) ;
}
F_48 ( & V_54 -> V_4 -> V_94 , & V_56 -> V_74 , V_54 -> V_2 ) ;
V_56 -> V_74 . V_78 += V_78 ;
if ( V_56 -> V_74 . V_92 )
return V_56 -> V_74 . V_92 ;
return V_56 -> V_74 . V_78 ;
}
static int F_49 ( struct V_53 * V_54 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_60 * V_62 , * V_116 ;
if ( V_54 == NULL )
return - V_37 ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
while ( ! F_32 ( & V_54 -> V_101 . V_102 ) ) {
struct V_55 * V_56 = F_33 ( V_54 -> V_101 . V_102 . V_86 ,
struct V_55 , V_102 ) ;
F_45 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_8 ) ;
F_47 ( & V_62 -> V_85 ) ;
V_62 -> V_65 = NULL ;
F_30 ( V_62 ) ;
}
F_47 ( & V_56 -> V_102 ) ;
V_56 -> V_74 . V_92 = - V_126 ;
if ( V_56 -> V_74 . V_127 != NULL ) {
F_50 ( V_54 -> V_125 ) ;
V_56 -> V_74 . V_127 ( & V_54 -> V_75 , & V_56 -> V_74 ) ;
F_51 ( V_54 -> V_125 ) ;
}
}
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
return 0 ;
}
static int F_52 ( struct V_128 * V_94 )
{
struct V_129 * V_75 ;
struct V_3 * V_4 = F_53 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
F_54 ( & V_4 -> V_125 , V_130 ) ;
V_4 -> V_94 . V_131 = V_132 ;
V_4 -> V_133 = 0 ;
V_4 -> V_134 = 0 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_56 (ep, gadget) {
F_57 ( V_75 ) ;
}
F_57 ( & V_4 -> V_135 -> V_75 ) ;
F_57 ( & V_4 -> V_136 -> V_75 ) ;
F_56 (ep, gadget) {
F_58 ( V_75 ) ;
}
if ( V_4 -> V_92 != NULL ) {
F_59 ( & V_4 -> V_136 -> V_75 , V_4 -> V_92 ) ;
V_4 -> V_92 = NULL ;
}
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
int V_137 ;
F_50 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_94 . V_131 != V_132 ) {
if ( V_4 -> V_138 )
V_4 -> V_138 -> V_139 ( & V_4 -> V_94 ) ;
}
V_137 = F_52 ( & V_4 -> V_94 ) ;
if ( V_137 )
goto V_107;
V_137 = F_25 ( V_4 ) ;
if ( V_137 )
goto V_107;
V_4 -> V_92 = F_61 ( & V_4 -> V_136 -> V_75 , V_63 ) ;
if ( V_4 -> V_92 == NULL )
V_137 = - V_64 ;
V_107:
F_51 ( & V_4 -> V_125 ) ;
if ( V_137 )
F_62 ( V_4 -> V_140 , L_1 , V_137 ) ;
}
static void F_63 ( struct V_129 * V_75 , struct V_141 * V_74 )
{
if ( V_75 == NULL || V_74 == NULL )
return;
F_30 ( V_74 -> V_142 ) ;
F_59 ( V_75 , V_74 ) ;
}
static int F_64 ( struct V_129 * V_75 , struct V_141 * V_74 ,
T_3 T_4 V_143 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_53 ( V_74 , struct V_55 , V_74 ) ;
struct V_3 * V_4 = V_54 -> V_4 ;
int V_137 = 0 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_144 == NULL )
return - V_37 ;
if ( V_54 -> type == V_112 ) {
if ( V_74 -> V_57 )
V_54 = ( V_4 -> V_145 == V_32 ) ?
V_4 -> V_135 : V_4 -> V_136 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_49 ( V_54 ) ;
V_137 = - V_146 ;
F_65 ( V_54 -> V_4 -> V_140 , L_2 ,
F_36 ( V_54 ) ) ;
}
}
if ( F_66 ( V_54 -> V_75 . V_144 ) &&
V_56 -> V_74 . V_57 > ( 1 + V_54 -> V_75 . V_147 ) * V_54 -> V_75 . V_76 ) {
F_62 ( V_54 -> V_4 -> V_140 , L_3 ) ;
return - V_148 ;
}
if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_62 ( V_54 -> V_4 -> V_140 , L_4 ) ;
return - V_118 ;
}
V_56 -> V_74 . V_92 = - V_149 ;
V_56 -> V_74 . V_78 = 0 ;
V_137 = F_37 ( V_54 , V_56 ) ;
if ( V_137 == - V_93 )
V_137 = 0 ;
if ( ! V_137 )
F_35 ( & V_56 -> V_102 , & V_54 -> V_101 . V_102 ) ;
return V_137 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_150 * V_151 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_53 * V_54 = V_4 -> V_136 ;
struct V_141 * V_74 = NULL ;
T_3 V_143 = V_63 ;
int V_2 , V_1 , V_137 ;
if ( V_54 == NULL || V_151 == NULL )
return - V_37 ;
F_50 ( V_54 -> V_125 ) ;
V_74 = F_61 ( & V_54 -> V_75 , V_143 ) ;
F_51 ( V_54 -> V_125 ) ;
if ( V_74 == NULL )
return - V_64 ;
V_74 -> V_127 = F_63 ;
V_74 -> V_57 = 2 ;
V_74 -> V_142 = F_28 ( V_74 -> V_57 , V_143 ) ;
if ( V_74 -> V_142 == NULL ) {
V_137 = - V_64 ;
goto V_152;
}
if ( ( V_151 -> V_153 & V_154 ) == V_155 ) {
* ( V_156 * ) V_74 -> V_142 = V_4 -> V_133 << 1 ;
V_137 = 0 ;
} else if ( ( V_151 -> V_153 & V_154 ) \
== V_157 ) {
V_2 = ( F_68 ( V_151 -> V_158 ) & V_87 ) ?
V_72 : V_32 ;
V_1 = F_68 ( V_151 -> V_158 ) & V_159 ;
* ( V_156 * ) V_74 -> V_142 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_137 = F_64 ( & V_54 -> V_75 , V_74 , V_143 ) ;
if ( V_137 )
goto V_160;
return 0 ;
V_160:
F_30 ( V_74 -> V_142 ) ;
V_152:
F_50 ( V_54 -> V_125 ) ;
F_59 ( & V_54 -> V_75 , V_74 ) ;
F_51 ( V_54 -> V_125 ) ;
return V_137 ;
}
static void
F_69 ( struct V_129 * V_75 , struct V_141 * V_74 )
{
struct V_3 * V_4 = V_74 -> V_161 ;
unsigned long V_130 ;
if ( V_4 -> V_162 ) {
F_24 ( V_4 , V_4 -> V_163 ) ;
V_4 -> V_162 = false ;
}
F_54 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_164 )
F_70 ( V_4 , V_4 -> V_164 ) ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
int V_137 ;
struct V_53 * V_54 ;
V_54 = ( V_4 -> V_145 == V_72 ) ? V_4 -> V_135 : V_4 -> V_136 ;
V_4 -> V_92 -> V_161 = V_4 ;
V_4 -> V_92 -> V_127 = F_69 ;
V_137 = F_64 ( & V_54 -> V_75 , V_4 -> V_92 , V_63 ) ;
return V_137 ;
}
static int F_72 ( struct V_53 * V_54 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_55 * V_56 , * V_165 ;
struct V_53 * V_166 = V_54 ;
int V_137 = 0 ;
F_45 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_137 = F_44 ( V_54 , V_56 ) ;
if ( V_137 < 0 )
break;
F_47 ( & V_56 -> V_102 ) ;
if ( V_56 -> V_74 . V_127 != NULL ) {
F_50 ( V_54 -> V_125 ) ;
if ( ( V_54 -> type == V_112 ) &&
V_56 -> V_74 . V_57 )
V_166 = V_54 -> V_4 -> V_136 ;
V_56 -> V_74 . V_127 ( & V_166 -> V_75 , & V_56 -> V_74 ) ;
F_51 ( V_54 -> V_125 ) ;
}
}
if ( V_137 == - V_118 )
V_137 = 0 ;
return V_137 ;
}
static void F_73 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
struct V_53 * V_54 = & V_4 -> V_53 [ 0 ] ;
struct V_150 V_74 ;
int type , V_1 , V_2 , V_167 = - V_37 ;
T_2 V_168 = 0 ;
F_49 ( V_4 -> V_135 ) ;
F_49 ( V_4 -> V_136 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_74 , & V_54 -> V_101 . V_65 -> V_151 , sizeof( V_74 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_74 . V_153 ;
V_4 -> V_145 = ( type & V_169 ) ? V_72 : V_32 ;
switch ( V_74 . V_170 ) {
case V_171 :
if ( type == ( V_172 | V_157 ) &&
F_68 ( V_74 . V_173 ) ==
V_174 ) {
if ( V_74 . V_175 != 0 )
break;
V_1 = F_68 ( V_74 . V_158 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_159 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_53 [ V_1 ] . V_176 ) {
F_50 ( & V_4 -> V_125 ) ;
V_167 = F_74 (
& V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_51 ( & V_4 -> V_125 ) ;
if ( V_167 )
break;
}
V_167 = F_71 ( V_4 ) ;
} else if ( type == ( V_172 | V_155 ) &&
F_68 ( V_74 . V_173 ) ==
V_177 ) {
if ( V_74 . V_175 != 0 )
break;
V_4 -> V_133 = 0 ;
V_167 = F_71 ( V_4 ) ;
} else {
goto V_178;
}
break;
case V_179 :
if ( type != ( V_169 | V_155 ) &&
type != ( V_169 | V_157 ) &&
type != ( V_169 | V_180 ) )
goto V_178;
if ( F_68 ( V_74 . V_175 ) != 2 ||
F_68 ( V_74 . V_173 ) != 0 )
break;
V_167 = F_67 ( V_4 , & V_74 ) ;
break;
case V_181 :
if ( type != ( V_172 | V_155 ) )
goto V_178;
if ( F_68 ( V_74 . V_175 ) != 0 ||
F_68 ( V_74 . V_158 ) != 0 )
break;
V_4 -> V_163 = ( T_2 ) F_68 ( V_74 . V_173 ) ;
V_4 -> V_162 = true ;
V_167 = F_71 ( V_4 ) ;
break;
case V_182 :
if ( type == ( V_172 | V_157 ) &&
F_68 ( V_74 . V_173 ) ==
V_174 ) {
if ( V_74 . V_175 != 0 )
break;
V_1 = F_68 ( V_74 . V_158 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_159 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_50 ( & V_4 -> V_125 ) ;
V_167 = F_75 ( & V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_51 ( & V_4 -> V_125 ) ;
if ( ! V_167 )
F_71 ( V_4 ) ;
} else if ( type == ( V_172 | V_155 ) ) {
if ( V_74 . V_175 != 0 )
break;
switch ( F_68 ( V_74 . V_173 ) ) {
case V_177 :
V_4 -> V_133 = 1 ;
V_167 = F_71 ( V_4 ) ;
break;
case V_183 :
V_168 = F_68 ( V_74 . V_158 ) >> 8 ;
switch ( V_168 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
V_4 -> V_164 = V_168 ;
V_167 = F_71 (
V_4 ) ;
break;
default:
break;
}
default:
goto V_178;
}
} else {
goto V_178;
}
break;
default:
V_178:
if ( V_74 . V_175 == 0 )
V_4 -> V_145 = V_72 ;
F_50 ( & V_4 -> V_125 ) ;
V_167 = V_4 -> V_138 -> V_151 ( & V_4 -> V_94 , & V_74 ) ;
F_51 ( & V_4 -> V_125 ) ;
break;
}
if ( V_167 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_75 ( & V_54 -> V_75 ) )
F_62 ( V_4 -> V_140 , L_5 ) ;
F_51 ( & V_4 -> V_125 ) ;
}
}
static void F_76 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
unsigned V_58 ;
int V_167 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_75 . V_144 == NULL )
continue;
if ( F_18 ( V_4 , V_58 ) ) {
V_167 = F_72 ( V_54 ) ;
if ( V_54 -> type == V_112 ) {
if ( V_167 > 0 )
V_167 = F_71 ( V_4 ) ;
if ( V_167 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_75 ( & V_54 -> V_75 ) )
F_62 ( V_4 -> V_140 ,
L_5 ) ;
F_51 ( & V_4 -> V_125 ) ;
}
}
}
if ( V_58 == 0 &&
F_19 ( V_4 , V_33 , F_6 ( 0 ) ) )
F_73 ( V_4 ) ;
}
}
static int F_77 ( struct V_129 * V_75 ,
const struct V_189 * V_144 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
T_1 V_110 = 0 ;
if ( V_75 == NULL || V_144 == NULL )
return - V_37 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_75 . V_144 = V_144 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) )
F_65 ( V_54 -> V_4 -> V_140 , L_6 ) ;
V_54 -> V_2 = F_78 ( V_144 ) ? V_72 : V_32 ;
V_54 -> V_1 = F_79 ( V_144 ) ;
V_54 -> type = F_80 ( V_144 ) ;
V_54 -> V_75 . V_76 = F_81 ( V_144 ) & 0x07ff ;
V_54 -> V_75 . V_147 = F_82 ( F_81 ( V_144 ) ) ;
if ( V_54 -> type == V_112 )
V_110 |= V_190 ;
if ( V_54 -> V_1 )
V_110 |= V_191 ;
V_110 |= ( V_54 -> V_75 . V_76 << F_11 ( V_192 ) ) & V_192 ;
if ( V_54 -> type == V_71 && V_54 -> V_2 == V_72 )
V_110 |= 3 << F_11 ( V_111 ) ;
V_54 -> V_101 . V_65 -> V_110 = F_31 ( V_110 ) ;
V_54 -> V_101 . V_65 -> V_85 . V_86 |= F_31 ( V_98 ) ;
if ( V_54 -> V_1 != 0 && V_54 -> type == V_112 ) {
F_62 ( V_54 -> V_4 -> V_140 , L_7 ) ;
V_137 = - V_37 ;
}
if ( V_54 -> V_1 )
V_137 |= F_10 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type ) ;
F_55 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_83 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
int V_193 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL )
return - V_37 ;
else if ( V_54 -> V_75 . V_144 == NULL )
return - V_118 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
V_193 = V_54 -> V_2 ;
do {
V_137 |= F_49 ( V_54 ) ;
V_137 |= F_9 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_193 );
V_54 -> V_75 . V_144 = NULL ;
F_55 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static struct V_141 * F_84 ( struct V_129 * V_75 , T_3 V_143 )
{
struct V_55 * V_56 = NULL ;
if ( V_75 == NULL )
return NULL ;
V_56 = F_28 ( sizeof( struct V_55 ) , V_143 ) ;
if ( V_56 != NULL ) {
F_34 ( & V_56 -> V_102 ) ;
F_34 ( & V_56 -> V_83 ) ;
}
return ( V_56 == NULL ) ? NULL : & V_56 -> V_74 ;
}
static void F_85 ( struct V_129 * V_75 , struct V_141 * V_74 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_53 ( V_74 , struct V_55 , V_74 ) ;
struct V_60 * V_62 , * V_116 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL ) {
return;
} else if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_62 ( V_54 -> V_4 -> V_140 , L_8 ) ;
return;
}
F_54 ( V_54 -> V_125 , V_130 ) ;
F_45 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_8 ) ;
F_47 ( & V_62 -> V_85 ) ;
V_62 -> V_65 = NULL ;
F_30 ( V_62 ) ;
}
F_30 ( V_56 ) ;
F_55 ( V_54 -> V_125 , V_130 ) ;
}
static int F_86 ( struct V_129 * V_75 , struct V_141 * V_74 ,
T_3 T_4 V_143 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_144 == NULL )
return - V_37 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
V_137 = F_64 ( V_75 , V_74 , V_143 ) ;
F_55 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_87 ( struct V_129 * V_75 , struct V_141 * V_74 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_53 ( V_74 , struct V_55 , V_74 ) ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL || V_56 -> V_74 . V_92 != - V_93 ||
V_54 -> V_75 . V_144 == NULL || F_32 ( & V_56 -> V_102 ) ||
F_32 ( & V_54 -> V_101 . V_102 ) )
return - V_37 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_47 ( & V_56 -> V_102 ) ;
F_48 ( & V_54 -> V_4 -> V_94 , V_74 , V_54 -> V_2 ) ;
V_74 -> V_92 = - V_194 ;
if ( V_56 -> V_74 . V_127 != NULL ) {
F_50 ( V_54 -> V_125 ) ;
V_56 -> V_74 . V_127 ( & V_54 -> V_75 , & V_56 -> V_74 ) ;
F_51 ( V_54 -> V_125 ) ;
}
F_55 ( V_54 -> V_125 , V_130 ) ;
return 0 ;
}
static int F_88 ( struct V_129 * V_75 , int V_36 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
int V_193 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_144 == NULL )
return - V_37 ;
if ( F_66 ( V_54 -> V_75 . V_144 ) )
return - V_195 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
#ifndef F_89
if ( V_36 && V_54 -> type == V_196 && V_54 -> V_2 == V_72 &&
! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_55 ( V_54 -> V_125 , V_130 ) ;
return - V_34 ;
}
#endif
V_193 = V_54 -> V_2 ;
do {
V_137 |= F_14 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 , V_36 ) ;
if ( ! V_36 )
V_54 -> V_176 = 0 ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_193 );
F_55 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_90 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_144 == NULL )
return - V_37 ;
F_54 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_176 = 1 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
return F_75 ( V_75 ) ;
}
static void F_91 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_53 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL ) {
F_62 ( V_54 -> V_4 -> V_140 , L_9 , F_36 ( V_54 ) ) ;
return;
}
F_54 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_55 ( V_54 -> V_125 , V_130 ) ;
}
static int F_92 ( struct V_128 * V_197 , int V_198 )
{
struct V_3 * V_4 = F_53 ( V_197 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_199 = 0 ;
F_54 ( & V_4 -> V_125 , V_130 ) ;
V_4 -> V_200 = V_198 ;
if ( V_4 -> V_138 )
V_199 = 1 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_199 ) {
if ( V_198 ) {
F_93 ( & V_197 -> V_140 ) ;
F_94 ( V_4 , V_201 ) ;
F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_95 ( V_4 -> V_140 , L_10 ) ;
} else {
if ( V_4 -> V_138 )
V_4 -> V_138 -> V_139 ( & V_4 -> V_94 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_202 -> V_203 )
V_4 -> V_202 -> V_203 ( V_4 ,
V_204 ) ;
F_52 ( & V_4 -> V_94 ) ;
F_96 ( & V_197 -> V_140 ) ;
F_95 ( V_4 -> V_140 , L_11 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_128 * V_197 )
{
struct V_3 * V_4 = F_53 ( V_197 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_88 = 0 ;
F_54 ( & V_4 -> V_125 , V_130 ) ;
if ( ! V_4 -> V_133 ) {
V_88 = - V_195 ;
goto V_205;
}
if ( ! F_7 ( V_4 , V_46 , V_206 ) ) {
V_88 = - V_37 ;
goto V_205;
}
F_4 ( V_4 , V_46 , V_207 , V_207 ) ;
V_205:
F_55 ( & V_4 -> V_125 , V_130 ) ;
return V_88 ;
}
static int F_98 ( struct V_128 * V_197 , unsigned V_208 )
{
struct V_3 * V_4 = F_53 ( V_197 , struct V_3 , V_94 ) ;
if ( V_4 -> V_209 )
return F_99 ( V_4 -> V_209 , V_208 ) ;
return - V_210 ;
}
static int F_100 ( struct V_128 * V_197 , int V_211 )
{
struct V_3 * V_4 = F_53 ( V_197 , struct V_3 , V_94 ) ;
if ( ! V_4 -> V_200 )
return - V_195 ;
if ( V_211 )
F_4 ( V_4 , V_16 , V_17 , V_17 ) ;
else
F_4 ( V_4 , V_16 , V_17 , 0 ) ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 )
{
int V_137 = 0 , V_58 , V_212 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 / 2 ; V_58 ++ )
for ( V_212 = V_32 ; V_212 <= V_72 ; V_212 ++ ) {
int V_213 = V_58 + V_212 * V_4 -> V_7 / 2 ;
struct V_53 * V_54 = & V_4 -> V_53 [ V_213 ] ;
F_102 ( V_54 -> V_214 , sizeof( V_54 -> V_214 ) , L_12 , V_58 ,
( V_212 == V_72 ) ? L_13 : L_14 ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_125 = & V_4 -> V_125 ;
V_54 -> V_66 = V_4 -> V_66 ;
V_54 -> V_75 . V_214 = V_54 -> V_214 ;
V_54 -> V_75 . V_215 = & V_216 ;
F_103 ( & V_54 -> V_75 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_54 -> V_101 . V_102 ) ;
V_54 -> V_101 . V_65 = F_29 ( V_4 -> V_217 , V_218 ,
& V_54 -> V_101 . V_8 ) ;
if ( V_54 -> V_101 . V_65 == NULL )
V_137 = - V_64 ;
else
memset ( V_54 -> V_101 . V_65 , 0 , sizeof( * V_54 -> V_101 . V_65 ) ) ;
if ( V_58 == 0 ) {
if ( V_212 == V_32 )
V_4 -> V_135 = V_54 ;
else
V_4 -> V_136 = V_54 ;
F_103 ( & V_54 -> V_75 , V_219 ) ;
continue;
}
F_35 ( & V_54 -> V_75 . V_220 , & V_4 -> V_94 . V_220 ) ;
}
return V_137 ;
}
static void F_104 ( struct V_3 * V_4 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
F_43 ( V_4 -> V_217 , V_54 -> V_101 . V_65 , V_54 -> V_101 . V_8 ) ;
}
}
static int F_105 ( struct V_128 * V_94 ,
struct V_221 * V_138 )
{
struct V_3 * V_4 = F_53 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_137 = - V_64 ;
if ( V_138 -> V_139 == NULL )
return - V_37 ;
V_4 -> V_135 -> V_75 . V_144 = & V_222 ;
V_137 = F_106 ( & V_4 -> V_135 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_136 -> V_75 . V_144 = & V_223 ;
V_137 = F_106 ( & V_4 -> V_136 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_138 = V_138 ;
F_93 ( & V_4 -> V_94 . V_140 ) ;
if ( V_4 -> V_200 ) {
F_54 ( & V_4 -> V_125 , V_130 ) ;
F_94 ( V_4 , V_201 ) ;
} else {
F_96 ( & V_4 -> V_94 . V_140 ) ;
return V_137 ;
}
V_137 = F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_137 )
F_96 ( & V_4 -> V_94 . V_140 ) ;
return V_137 ;
}
static int F_107 ( struct V_128 * V_94 ,
struct V_221 * V_138 )
{
struct V_3 * V_4 = F_53 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
F_54 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_200 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_202 -> V_203 )
V_4 -> V_202 -> V_203 ( V_4 ,
V_204 ) ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_52 ( & V_4 -> V_94 ) ;
F_54 ( & V_4 -> V_125 , V_130 ) ;
F_108 ( & V_4 -> V_94 . V_140 ) ;
}
V_4 -> V_138 = NULL ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
return 0 ;
}
static T_5 F_109 ( struct V_3 * V_4 )
{
T_5 V_137 ;
T_1 V_224 ;
if ( V_4 == NULL )
return V_225 ;
F_51 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_202 -> V_130 & V_226 ) {
if ( F_7 ( V_4 , V_227 , V_228 ) !=
V_201 ) {
F_50 ( & V_4 -> V_125 ) ;
return V_229 ;
}
}
V_224 = F_20 ( V_4 ) ;
if ( V_224 ) {
if ( V_14 & V_224 )
F_60 ( V_4 ) ;
if ( V_13 & V_224 ) {
V_4 -> V_94 . V_131 = F_15 ( V_4 ) ?
V_230 : V_231 ;
if ( V_4 -> V_134 && V_4 -> V_138 -> V_232 ) {
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_232 ( & V_4 -> V_94 ) ;
F_51 ( & V_4 -> V_125 ) ;
V_4 -> V_134 = 0 ;
}
}
if ( V_11 & V_224 )
F_76 ( V_4 ) ;
if ( V_15 & V_224 ) {
if ( V_4 -> V_94 . V_131 != V_132 &&
V_4 -> V_138 -> V_233 ) {
V_4 -> V_134 = 1 ;
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_233 ( & V_4 -> V_94 ) ;
F_51 ( & V_4 -> V_125 ) ;
}
}
V_137 = V_225 ;
} else {
V_137 = V_229 ;
}
F_50 ( & V_4 -> V_125 ) ;
return V_137 ;
}
static int F_110 ( struct V_3 * V_4 )
{
struct V_234 * V_140 = V_4 -> V_140 ;
int V_137 = 0 ;
F_111 ( & V_4 -> V_125 ) ;
V_4 -> V_94 . V_215 = & V_235 ;
V_4 -> V_94 . V_131 = V_132 ;
V_4 -> V_94 . V_236 = V_230 ;
V_4 -> V_94 . V_237 = 0 ;
V_4 -> V_94 . V_214 = V_4 -> V_202 -> V_214 ;
F_34 ( & V_4 -> V_94 . V_220 ) ;
V_4 -> V_217 = F_112 ( L_15 , V_140 ,
sizeof( struct V_238 ) ,
64 , V_81 ) ;
if ( V_4 -> V_217 == NULL )
return - V_64 ;
V_4 -> V_66 = F_112 ( L_16 , V_140 ,
sizeof( struct V_67 ) ,
64 , V_81 ) ;
if ( V_4 -> V_66 == NULL ) {
V_137 = - V_64 ;
goto V_239;
}
V_137 = F_101 ( V_4 ) ;
if ( V_137 )
goto V_240;
V_4 -> V_94 . V_241 = & V_4 -> V_136 -> V_75 ;
V_137 = F_113 ( V_140 , & V_4 -> V_94 ) ;
if ( V_137 )
goto F_104;
F_114 ( & V_4 -> V_94 . V_140 ) ;
F_115 ( & V_4 -> V_94 . V_140 ) ;
return V_137 ;
F_104:
F_104 ( V_4 ) ;
V_240:
F_116 ( V_4 -> V_66 ) ;
V_239:
F_116 ( V_4 -> V_217 ) ;
return V_137 ;
}
void F_117 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_242 [ V_243 ] )
return;
F_118 ( & V_4 -> V_94 ) ;
F_104 ( V_4 ) ;
F_116 ( V_4 -> V_66 ) ;
F_116 ( V_4 -> V_217 ) ;
}
static int F_119 ( struct V_3 * V_4 )
{
if ( V_4 -> V_237 ) {
F_120 ( V_4 , V_244 ) ;
F_121 ( V_4 , V_245 ) ;
}
return 0 ;
}
static void F_122 ( struct V_3 * V_4 )
{
if ( V_4 -> V_237 ) {
F_120 ( V_4 , V_244 ) ;
F_123 ( V_4 , V_245 ) ;
}
}
int F_124 ( struct V_3 * V_4 )
{
struct V_246 * V_247 ;
if ( ! F_7 ( V_4 , V_248 , V_249 ) )
return - V_250 ;
V_247 = F_125 ( V_4 -> V_140 , sizeof( struct V_246 ) , V_218 ) ;
if ( ! V_247 )
return - V_64 ;
V_247 -> V_251 = F_119 ;
V_247 -> V_252 = F_122 ;
V_247 -> V_253 = F_109 ;
V_247 -> V_214 = L_17 ;
V_4 -> V_242 [ V_243 ] = V_247 ;
return F_110 ( V_4 ) ;
}
