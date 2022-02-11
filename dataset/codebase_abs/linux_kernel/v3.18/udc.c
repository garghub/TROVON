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
static int F_16 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_17 ( V_4 , V_48 , F_6 ( V_5 ) ) ;
}
static T_1 F_18 ( struct V_3 * V_4 )
{
T_1 V_39 = F_19 ( V_4 ) & F_20 ( V_4 ) ;
F_4 ( V_4 , V_49 , ~ 0 , V_39 ) ;
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
F_4 ( V_4 , V_48 , 0 , 0 ) ;
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
F_51 ( & V_54 -> V_75 , & V_56 -> V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
}
}
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
return 0 ;
}
static int F_53 ( struct V_128 * V_94 )
{
struct V_129 * V_75 ;
struct V_3 * V_4 = F_54 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
V_4 -> V_94 . V_131 = V_132 ;
V_4 -> V_133 = 0 ;
V_4 -> V_134 = 0 ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
F_57 (ep, gadget) {
F_58 ( V_75 ) ;
}
F_58 ( & V_4 -> V_135 -> V_75 ) ;
F_58 ( & V_4 -> V_136 -> V_75 ) ;
F_57 (ep, gadget) {
F_59 ( V_75 ) ;
}
if ( V_4 -> V_92 != NULL ) {
F_60 ( & V_4 -> V_136 -> V_75 , V_4 -> V_92 ) ;
V_4 -> V_92 = NULL ;
}
return 0 ;
}
static void F_61 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
int V_137 ;
F_50 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_94 . V_131 != V_132 ) {
if ( V_4 -> V_138 )
V_4 -> V_138 -> V_139 ( & V_4 -> V_94 ) ;
}
V_137 = F_53 ( & V_4 -> V_94 ) ;
if ( V_137 )
goto V_107;
V_137 = F_25 ( V_4 ) ;
if ( V_137 )
goto V_107;
V_4 -> V_92 = F_62 ( & V_4 -> V_136 -> V_75 , V_63 ) ;
if ( V_4 -> V_92 == NULL )
V_137 = - V_64 ;
F_63 ( & V_4 -> V_94 , V_140 ) ;
V_107:
F_52 ( & V_4 -> V_125 ) ;
if ( V_137 )
F_64 ( V_4 -> V_141 , L_1 , V_137 ) ;
}
static void F_65 ( struct V_129 * V_75 , struct V_142 * V_74 )
{
if ( V_75 == NULL || V_74 == NULL )
return;
F_30 ( V_74 -> V_143 ) ;
F_60 ( V_75 , V_74 ) ;
}
static int F_66 ( struct V_129 * V_75 , struct V_142 * V_74 ,
T_3 T_4 V_144 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
struct V_3 * V_4 = V_54 -> V_4 ;
int V_137 = 0 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_145 == NULL )
return - V_37 ;
if ( V_54 -> type == V_112 ) {
if ( V_74 -> V_57 )
V_54 = ( V_4 -> V_146 == V_32 ) ?
V_4 -> V_135 : V_4 -> V_136 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_49 ( V_54 ) ;
V_137 = - V_147 ;
F_67 ( V_54 -> V_4 -> V_141 , L_2 ,
F_36 ( V_54 ) ) ;
}
}
if ( F_68 ( V_54 -> V_75 . V_145 ) &&
V_56 -> V_74 . V_57 > ( 1 + V_54 -> V_75 . V_148 ) * V_54 -> V_75 . V_76 ) {
F_64 ( V_54 -> V_4 -> V_141 , L_3 ) ;
return - V_149 ;
}
if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_64 ( V_54 -> V_4 -> V_141 , L_4 ) ;
return - V_118 ;
}
V_56 -> V_74 . V_92 = - V_150 ;
V_56 -> V_74 . V_78 = 0 ;
V_137 = F_37 ( V_54 , V_56 ) ;
if ( V_137 == - V_93 )
V_137 = 0 ;
if ( ! V_137 )
F_35 ( & V_56 -> V_102 , & V_54 -> V_101 . V_102 ) ;
return V_137 ;
}
static int F_69 ( struct V_3 * V_4 ,
struct V_151 * V_152 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_53 * V_54 = V_4 -> V_136 ;
struct V_142 * V_74 = NULL ;
T_3 V_144 = V_63 ;
int V_2 , V_1 , V_137 ;
if ( V_54 == NULL || V_152 == NULL )
return - V_37 ;
F_50 ( V_54 -> V_125 ) ;
V_74 = F_62 ( & V_54 -> V_75 , V_144 ) ;
F_52 ( V_54 -> V_125 ) ;
if ( V_74 == NULL )
return - V_64 ;
V_74 -> V_127 = F_65 ;
V_74 -> V_57 = 2 ;
V_74 -> V_143 = F_28 ( V_74 -> V_57 , V_144 ) ;
if ( V_74 -> V_143 == NULL ) {
V_137 = - V_64 ;
goto V_153;
}
if ( ( V_152 -> V_154 & V_155 ) == V_156 ) {
* ( V_157 * ) V_74 -> V_143 = V_4 -> V_133 << 1 ;
} else if ( ( V_152 -> V_154 & V_155 ) \
== V_158 ) {
V_2 = ( F_70 ( V_152 -> V_159 ) & V_87 ) ?
V_72 : V_32 ;
V_1 = F_70 ( V_152 -> V_159 ) & V_160 ;
* ( V_157 * ) V_74 -> V_143 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_137 = F_66 ( & V_54 -> V_75 , V_74 , V_144 ) ;
if ( V_137 )
goto V_161;
return 0 ;
V_161:
F_30 ( V_74 -> V_143 ) ;
V_153:
F_50 ( V_54 -> V_125 ) ;
F_60 ( & V_54 -> V_75 , V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
return V_137 ;
}
static void
F_71 ( struct V_129 * V_75 , struct V_142 * V_74 )
{
struct V_3 * V_4 = V_74 -> V_162 ;
unsigned long V_130 ;
if ( V_4 -> V_163 ) {
F_24 ( V_4 , V_4 -> V_164 ) ;
V_4 -> V_163 = false ;
if ( V_4 -> V_164 )
F_63 ( & V_4 -> V_94 , V_165 ) ;
}
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_166 )
F_72 ( V_4 , V_4 -> V_166 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
}
static int F_73 ( struct V_3 * V_4 )
{
int V_137 ;
struct V_53 * V_54 ;
V_54 = ( V_4 -> V_146 == V_72 ) ? V_4 -> V_135 : V_4 -> V_136 ;
V_4 -> V_92 -> V_162 = V_4 ;
V_4 -> V_92 -> V_127 = F_71 ;
V_137 = F_66 ( & V_54 -> V_75 , V_4 -> V_92 , V_63 ) ;
return V_137 ;
}
static int F_74 ( struct V_53 * V_54 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_55 * V_56 , * V_167 ;
struct V_53 * V_168 = V_54 ;
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
V_168 = V_54 -> V_4 -> V_136 ;
F_51 ( & V_168 -> V_75 , & V_56 -> V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
}
}
if ( V_137 == - V_118 )
V_137 = 0 ;
return V_137 ;
}
static void F_75 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
struct V_53 * V_54 = & V_4 -> V_53 [ 0 ] ;
struct V_151 V_74 ;
int type , V_1 , V_2 , V_169 = - V_37 ;
T_2 V_170 = 0 ;
F_49 ( V_4 -> V_135 ) ;
F_49 ( V_4 -> V_136 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_74 , & V_54 -> V_101 . V_65 -> V_152 , sizeof( V_74 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_74 . V_154 ;
V_4 -> V_146 = ( type & V_171 ) ? V_72 : V_32 ;
switch ( V_74 . V_172 ) {
case V_173 :
if ( type == ( V_174 | V_158 ) &&
F_70 ( V_74 . V_175 ) ==
V_176 ) {
if ( V_74 . V_177 != 0 )
break;
V_1 = F_70 ( V_74 . V_159 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_160 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_53 [ V_1 ] . V_178 ) {
F_50 ( & V_4 -> V_125 ) ;
V_169 = F_76 (
& V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_52 ( & V_4 -> V_125 ) ;
if ( V_169 )
break;
}
V_169 = F_73 ( V_4 ) ;
} else if ( type == ( V_174 | V_156 ) &&
F_70 ( V_74 . V_175 ) ==
V_179 ) {
if ( V_74 . V_177 != 0 )
break;
V_4 -> V_133 = 0 ;
V_169 = F_73 ( V_4 ) ;
} else {
goto V_180;
}
break;
case V_181 :
if ( type != ( V_171 | V_156 ) &&
type != ( V_171 | V_158 ) &&
type != ( V_171 | V_182 ) )
goto V_180;
if ( F_70 ( V_74 . V_177 ) != 2 ||
F_70 ( V_74 . V_175 ) != 0 )
break;
V_169 = F_69 ( V_4 , & V_74 ) ;
break;
case V_183 :
if ( type != ( V_174 | V_156 ) )
goto V_180;
if ( F_70 ( V_74 . V_177 ) != 0 ||
F_70 ( V_74 . V_159 ) != 0 )
break;
V_4 -> V_164 = ( T_2 ) F_70 ( V_74 . V_175 ) ;
V_4 -> V_163 = true ;
V_169 = F_73 ( V_4 ) ;
break;
case V_184 :
if ( type == ( V_174 | V_158 ) &&
F_70 ( V_74 . V_175 ) ==
V_176 ) {
if ( V_74 . V_177 != 0 )
break;
V_1 = F_70 ( V_74 . V_159 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_160 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_50 ( & V_4 -> V_125 ) ;
V_169 = F_77 ( & V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_52 ( & V_4 -> V_125 ) ;
if ( ! V_169 )
F_73 ( V_4 ) ;
} else if ( type == ( V_174 | V_156 ) ) {
if ( V_74 . V_177 != 0 )
break;
switch ( F_70 ( V_74 . V_175 ) ) {
case V_179 :
V_4 -> V_133 = 1 ;
V_169 = F_73 ( V_4 ) ;
break;
case V_185 :
V_170 = F_70 ( V_74 . V_159 ) >> 8 ;
switch ( V_170 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
V_4 -> V_166 = V_170 ;
V_169 = F_73 (
V_4 ) ;
break;
default:
break;
}
break;
case V_191 :
if ( F_78 ( V_4 ) ) {
V_4 -> V_94 . V_192 = 1 ;
V_169 = F_73 (
V_4 ) ;
}
break;
default:
goto V_180;
}
} else {
goto V_180;
}
break;
default:
V_180:
if ( V_74 . V_177 == 0 )
V_4 -> V_146 = V_72 ;
F_50 ( & V_4 -> V_125 ) ;
V_169 = V_4 -> V_138 -> V_152 ( & V_4 -> V_94 , & V_74 ) ;
F_52 ( & V_4 -> V_125 ) ;
break;
}
if ( V_169 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_77 ( & V_54 -> V_75 ) )
F_64 ( V_4 -> V_141 , L_5 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
static void F_79 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
unsigned V_58 ;
int V_169 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_75 . V_145 == NULL )
continue;
if ( F_16 ( V_4 , V_58 ) ) {
V_169 = F_74 ( V_54 ) ;
if ( V_54 -> type == V_112 ) {
if ( V_169 > 0 )
V_169 = F_73 ( V_4 ) ;
if ( V_169 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_77 ( & V_54 -> V_75 ) )
F_64 ( V_4 -> V_141 ,
L_5 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
}
if ( V_58 == 0 &&
F_17 ( V_4 , V_33 , F_6 ( 0 ) ) )
F_75 ( V_4 ) ;
}
}
static int F_80 ( struct V_129 * V_75 ,
const struct V_193 * V_145 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
T_1 V_110 = 0 ;
if ( V_75 == NULL || V_145 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_75 . V_145 = V_145 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) )
F_67 ( V_54 -> V_4 -> V_141 , L_6 ) ;
V_54 -> V_2 = F_81 ( V_145 ) ? V_72 : V_32 ;
V_54 -> V_1 = F_82 ( V_145 ) ;
V_54 -> type = F_83 ( V_145 ) ;
V_54 -> V_75 . V_76 = F_84 ( V_145 ) & 0x07ff ;
V_54 -> V_75 . V_148 = F_85 ( F_84 ( V_145 ) ) ;
if ( V_54 -> type == V_112 )
V_110 |= V_194 ;
V_110 |= V_195 ;
V_110 |= ( V_54 -> V_75 . V_76 << F_11 ( V_196 ) ) & V_196 ;
if ( V_54 -> type == V_71 && V_54 -> V_2 == V_72 )
V_110 |= 3 << F_11 ( V_111 ) ;
V_54 -> V_101 . V_65 -> V_110 = F_31 ( V_110 ) ;
V_54 -> V_101 . V_65 -> V_85 . V_86 |= F_31 ( V_98 ) ;
if ( V_54 -> V_1 != 0 && V_54 -> type == V_112 ) {
F_64 ( V_54 -> V_4 -> V_141 , L_7 ) ;
V_137 = - V_37 ;
}
if ( V_54 -> V_1 )
V_137 |= F_10 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_86 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_197 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL )
return - V_37 ;
else if ( V_54 -> V_75 . V_145 == NULL )
return - V_118 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_197 = V_54 -> V_2 ;
do {
V_137 |= F_49 ( V_54 ) ;
V_137 |= F_9 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_197 );
V_54 -> V_75 . V_145 = NULL ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static struct V_142 * F_87 ( struct V_129 * V_75 , T_3 V_144 )
{
struct V_55 * V_56 = NULL ;
if ( V_75 == NULL )
return NULL ;
V_56 = F_28 ( sizeof( struct V_55 ) , V_144 ) ;
if ( V_56 != NULL ) {
F_34 ( & V_56 -> V_102 ) ;
F_34 ( & V_56 -> V_83 ) ;
}
return ( V_56 == NULL ) ? NULL : & V_56 -> V_74 ;
}
static void F_88 ( struct V_129 * V_75 , struct V_142 * V_74 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
struct V_60 * V_62 , * V_116 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL ) {
return;
} else if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_64 ( V_54 -> V_4 -> V_141 , L_8 ) ;
return;
}
F_55 ( V_54 -> V_125 , V_130 ) ;
F_45 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_8 ) ;
F_47 ( & V_62 -> V_85 ) ;
V_62 -> V_65 = NULL ;
F_30 ( V_62 ) ;
}
F_30 ( V_56 ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
}
static int F_89 ( struct V_129 * V_75 , struct V_142 * V_74 ,
T_3 T_4 V_144 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_145 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_137 = F_66 ( V_75 , V_74 , V_144 ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_90 ( struct V_129 * V_75 , struct V_142 * V_74 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
unsigned long V_130 ;
struct V_60 * V_62 , * V_116 ;
if ( V_75 == NULL || V_74 == NULL || V_56 -> V_74 . V_92 != - V_93 ||
V_54 -> V_75 . V_145 == NULL || F_32 ( & V_56 -> V_102 ) ||
F_32 ( & V_54 -> V_101 . V_102 ) )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_45 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_8 ) ;
F_91 ( & V_62 -> V_85 ) ;
F_30 ( V_62 ) ;
}
F_47 ( & V_56 -> V_102 ) ;
F_48 ( & V_54 -> V_4 -> V_94 , V_74 , V_54 -> V_2 ) ;
V_74 -> V_92 = - V_198 ;
if ( V_56 -> V_74 . V_127 != NULL ) {
F_50 ( V_54 -> V_125 ) ;
F_51 ( & V_54 -> V_75 , & V_56 -> V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
}
F_56 ( V_54 -> V_125 , V_130 ) ;
return 0 ;
}
static int F_92 ( struct V_129 * V_75 , int V_36 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_197 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_145 == NULL )
return - V_37 ;
if ( F_68 ( V_54 -> V_75 . V_145 ) )
return - V_199 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
#ifndef F_93
if ( V_36 && V_54 -> type == V_200 && V_54 -> V_2 == V_72 &&
! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_56 ( V_54 -> V_125 , V_130 ) ;
return - V_34 ;
}
#endif
V_197 = V_54 -> V_2 ;
do {
V_137 |= F_14 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 , V_36 ) ;
if ( ! V_36 )
V_54 -> V_178 = 0 ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_197 );
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_94 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_145 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_178 = 1 ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return F_77 ( V_75 ) ;
}
static void F_95 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL ) {
F_64 ( V_54 -> V_4 -> V_141 , L_9 , F_36 ( V_54 ) ) ;
return;
}
F_55 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
}
static int F_96 ( struct V_128 * V_201 , int V_202 )
{
struct V_3 * V_4 = F_54 ( V_201 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_203 = 0 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
V_4 -> V_204 = V_202 ;
if ( V_4 -> V_138 )
V_203 = 1 ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
if ( V_203 ) {
if ( V_202 ) {
F_97 ( & V_201 -> V_141 ) ;
F_98 ( V_4 , V_205 ) ;
F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_63 ( V_201 , V_206 ) ;
} else {
if ( V_4 -> V_138 )
V_4 -> V_138 -> V_139 ( & V_4 -> V_94 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_207 -> V_208 )
V_4 -> V_207 -> V_208 ( V_4 ,
V_209 ) ;
F_53 ( & V_4 -> V_94 ) ;
F_99 ( & V_201 -> V_141 ) ;
F_63 ( V_201 , V_210 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_128 * V_201 )
{
struct V_3 * V_4 = F_54 ( V_201 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_88 = 0 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( ! V_4 -> V_133 ) {
V_88 = - V_199 ;
goto V_211;
}
if ( ! F_7 ( V_4 , V_46 , V_212 ) ) {
V_88 = - V_37 ;
goto V_211;
}
F_4 ( V_4 , V_46 , V_213 , V_213 ) ;
V_211:
F_56 ( & V_4 -> V_125 , V_130 ) ;
return V_88 ;
}
static int F_101 ( struct V_128 * V_201 , unsigned V_214 )
{
struct V_3 * V_4 = F_54 ( V_201 , struct V_3 , V_94 ) ;
if ( V_4 -> V_215 )
return F_102 ( V_4 -> V_215 , V_214 ) ;
return - V_216 ;
}
static int F_103 ( struct V_128 * V_201 , int V_217 )
{
struct V_3 * V_4 = F_54 ( V_201 , struct V_3 , V_94 ) ;
if ( ! V_4 -> V_204 )
return - V_199 ;
if ( V_217 )
F_4 ( V_4 , V_16 , V_17 , V_17 ) ;
else
F_4 ( V_4 , V_16 , V_17 , 0 ) ;
return 0 ;
}
static int F_104 ( struct V_3 * V_4 )
{
int V_137 = 0 , V_58 , V_218 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 / 2 ; V_58 ++ )
for ( V_218 = V_32 ; V_218 <= V_72 ; V_218 ++ ) {
int V_219 = V_58 + V_218 * V_4 -> V_7 / 2 ;
struct V_53 * V_54 = & V_4 -> V_53 [ V_219 ] ;
F_105 ( V_54 -> V_220 , sizeof( V_54 -> V_220 ) , L_10 , V_58 ,
( V_218 == V_72 ) ? L_11 : L_12 ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_125 = & V_4 -> V_125 ;
V_54 -> V_66 = V_4 -> V_66 ;
V_54 -> V_75 . V_220 = V_54 -> V_220 ;
V_54 -> V_75 . V_221 = & V_222 ;
F_106 ( & V_54 -> V_75 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_54 -> V_101 . V_102 ) ;
V_54 -> V_101 . V_65 = F_29 ( V_4 -> V_223 , V_224 ,
& V_54 -> V_101 . V_8 ) ;
if ( V_54 -> V_101 . V_65 == NULL )
V_137 = - V_64 ;
else
memset ( V_54 -> V_101 . V_65 , 0 , sizeof( * V_54 -> V_101 . V_65 ) ) ;
if ( V_58 == 0 ) {
if ( V_218 == V_32 )
V_4 -> V_135 = V_54 ;
else
V_4 -> V_136 = V_54 ;
F_106 ( & V_54 -> V_75 , V_225 ) ;
continue;
}
F_35 ( & V_54 -> V_75 . V_226 , & V_4 -> V_94 . V_226 ) ;
}
return V_137 ;
}
static void F_107 ( struct V_3 * V_4 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
F_43 ( V_4 -> V_223 , V_54 -> V_101 . V_65 , V_54 -> V_101 . V_8 ) ;
}
}
static int F_108 ( struct V_128 * V_94 ,
struct V_227 * V_138 )
{
struct V_3 * V_4 = F_54 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_137 = - V_64 ;
if ( V_138 -> V_139 == NULL )
return - V_37 ;
V_4 -> V_135 -> V_75 . V_145 = & V_228 ;
V_137 = F_109 ( & V_4 -> V_135 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_136 -> V_75 . V_145 = & V_229 ;
V_137 = F_109 ( & V_4 -> V_136 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_138 = V_138 ;
if ( F_78 ( V_4 ) && V_4 -> V_230 . V_231 ) {
F_110 ( V_4 ) ;
return V_137 ;
}
F_97 ( & V_4 -> V_94 . V_141 ) ;
if ( V_4 -> V_204 ) {
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_98 ( V_4 , V_205 ) ;
} else {
F_99 ( & V_4 -> V_94 . V_141 ) ;
return V_137 ;
}
V_137 = F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
if ( V_137 )
F_99 ( & V_4 -> V_94 . V_141 ) ;
return V_137 ;
}
static int F_111 ( struct V_128 * V_94 ,
struct V_227 * V_138 )
{
struct V_3 * V_4 = F_54 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_204 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_207 -> V_208 )
V_4 -> V_207 -> V_208 ( V_4 ,
V_209 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
F_53 ( & V_4 -> V_94 ) ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_112 ( & V_4 -> V_94 . V_141 ) ;
}
V_4 -> V_138 = NULL ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
return 0 ;
}
static T_5 F_113 ( struct V_3 * V_4 )
{
T_5 V_137 ;
T_1 V_232 ;
if ( V_4 == NULL )
return V_233 ;
F_52 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_207 -> V_130 & V_234 ) {
if ( F_7 ( V_4 , V_235 , V_236 ) !=
V_205 ) {
F_50 ( & V_4 -> V_125 ) ;
return V_237 ;
}
}
V_232 = F_18 ( V_4 ) ;
if ( V_232 ) {
if ( V_14 & V_232 )
F_61 ( V_4 ) ;
if ( V_13 & V_232 ) {
V_4 -> V_94 . V_131 = F_15 ( V_4 ) ?
V_238 : V_239 ;
if ( V_4 -> V_134 && V_4 -> V_138 -> V_240 ) {
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_240 ( & V_4 -> V_94 ) ;
F_52 ( & V_4 -> V_125 ) ;
V_4 -> V_134 = 0 ;
}
}
if ( V_11 & V_232 )
F_79 ( V_4 ) ;
if ( V_15 & V_232 ) {
if ( V_4 -> V_94 . V_131 != V_132 &&
V_4 -> V_138 -> V_241 ) {
V_4 -> V_134 = 1 ;
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_241 ( & V_4 -> V_94 ) ;
F_63 ( & V_4 -> V_94 ,
V_242 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
V_137 = V_233 ;
} else {
V_137 = V_237 ;
}
F_50 ( & V_4 -> V_125 ) ;
return V_137 ;
}
static int F_114 ( struct V_3 * V_4 )
{
struct V_243 * V_141 = V_4 -> V_141 ;
int V_137 = 0 ;
F_115 ( & V_4 -> V_125 ) ;
V_4 -> V_94 . V_221 = & V_244 ;
V_4 -> V_94 . V_131 = V_132 ;
V_4 -> V_94 . V_245 = V_238 ;
V_4 -> V_94 . V_246 = V_4 -> V_246 ? 1 : 0 ;
V_4 -> V_94 . V_220 = V_4 -> V_207 -> V_220 ;
F_34 ( & V_4 -> V_94 . V_226 ) ;
V_4 -> V_223 = F_116 ( L_13 , V_141 ,
sizeof( struct V_247 ) ,
64 , V_81 ) ;
if ( V_4 -> V_223 == NULL )
return - V_64 ;
V_4 -> V_66 = F_116 ( L_14 , V_141 ,
sizeof( struct V_67 ) ,
64 , V_81 ) ;
if ( V_4 -> V_66 == NULL ) {
V_137 = - V_64 ;
goto V_248;
}
V_137 = F_104 ( V_4 ) ;
if ( V_137 )
goto V_249;
V_4 -> V_94 . V_250 = & V_4 -> V_136 -> V_75 ;
V_137 = F_117 ( V_141 , & V_4 -> V_94 ) ;
if ( V_137 )
goto F_107;
F_118 ( & V_4 -> V_94 . V_141 ) ;
F_119 ( & V_4 -> V_94 . V_141 ) ;
return V_137 ;
F_107:
F_107 ( V_4 ) ;
V_249:
F_120 ( V_4 -> V_66 ) ;
V_248:
F_120 ( V_4 -> V_223 ) ;
return V_137 ;
}
void F_121 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_251 [ V_252 ] )
return;
F_122 ( & V_4 -> V_94 ) ;
F_107 ( V_4 ) ;
F_120 ( V_4 -> V_66 ) ;
F_120 ( V_4 -> V_223 ) ;
}
static int F_123 ( struct V_3 * V_4 )
{
if ( V_4 -> V_246 )
F_124 ( V_4 , V_253 | V_254 ,
V_253 | V_254 ) ;
return 0 ;
}
static void F_125 ( struct V_3 * V_4 )
{
if ( V_4 -> V_246 )
F_124 ( V_4 , V_254 | V_253 , V_253 ) ;
}
int F_126 ( struct V_3 * V_4 )
{
struct V_255 * V_256 ;
if ( ! F_7 ( V_4 , V_257 , V_258 ) )
return - V_259 ;
V_256 = F_127 ( V_4 -> V_141 , sizeof( struct V_255 ) , V_224 ) ;
if ( ! V_256 )
return - V_64 ;
V_256 -> V_260 = F_123 ;
V_256 -> V_261 = F_125 ;
V_256 -> V_262 = F_113 ;
V_256 -> V_220 = L_15 ;
V_4 -> V_251 [ V_252 ] = V_256 ;
return F_114 ( V_4 ) ;
}
