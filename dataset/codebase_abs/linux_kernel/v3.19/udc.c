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
if ( V_4 -> V_94 . V_131 != V_132 )
F_62 ( & V_4 -> V_94 , V_4 -> V_138 ) ;
V_137 = F_53 ( & V_4 -> V_94 ) ;
if ( V_137 )
goto V_107;
V_137 = F_25 ( V_4 ) ;
if ( V_137 )
goto V_107;
V_4 -> V_92 = F_63 ( & V_4 -> V_136 -> V_75 , V_63 ) ;
if ( V_4 -> V_92 == NULL )
V_137 = - V_64 ;
V_107:
F_52 ( & V_4 -> V_125 ) ;
if ( V_137 )
F_64 ( V_4 -> V_139 , L_1 , V_137 ) ;
}
static void F_65 ( struct V_129 * V_75 , struct V_140 * V_74 )
{
if ( V_75 == NULL || V_74 == NULL )
return;
F_30 ( V_74 -> V_141 ) ;
F_60 ( V_75 , V_74 ) ;
}
static int F_66 ( struct V_129 * V_75 , struct V_140 * V_74 ,
T_3 T_4 V_142 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
struct V_3 * V_4 = V_54 -> V_4 ;
int V_137 = 0 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_143 == NULL )
return - V_37 ;
if ( V_54 -> type == V_112 ) {
if ( V_74 -> V_57 )
V_54 = ( V_4 -> V_144 == V_32 ) ?
V_4 -> V_135 : V_4 -> V_136 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_49 ( V_54 ) ;
V_137 = - V_145 ;
F_67 ( V_54 -> V_4 -> V_139 , L_2 ,
F_36 ( V_54 ) ) ;
}
}
if ( F_68 ( V_54 -> V_75 . V_143 ) &&
V_56 -> V_74 . V_57 > ( 1 + V_54 -> V_75 . V_146 ) * V_54 -> V_75 . V_76 ) {
F_64 ( V_54 -> V_4 -> V_139 , L_3 ) ;
return - V_147 ;
}
if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_64 ( V_54 -> V_4 -> V_139 , L_4 ) ;
return - V_118 ;
}
V_56 -> V_74 . V_92 = - V_148 ;
V_56 -> V_74 . V_78 = 0 ;
V_137 = F_37 ( V_54 , V_56 ) ;
if ( V_137 == - V_93 )
V_137 = 0 ;
if ( ! V_137 )
F_35 ( & V_56 -> V_102 , & V_54 -> V_101 . V_102 ) ;
return V_137 ;
}
static int F_69 ( struct V_3 * V_4 ,
struct V_149 * V_150 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_53 * V_54 = V_4 -> V_136 ;
struct V_140 * V_74 = NULL ;
T_3 V_142 = V_63 ;
int V_2 , V_1 , V_137 ;
if ( V_54 == NULL || V_150 == NULL )
return - V_37 ;
F_50 ( V_54 -> V_125 ) ;
V_74 = F_63 ( & V_54 -> V_75 , V_142 ) ;
F_52 ( V_54 -> V_125 ) ;
if ( V_74 == NULL )
return - V_64 ;
V_74 -> V_127 = F_65 ;
V_74 -> V_57 = 2 ;
V_74 -> V_141 = F_28 ( V_74 -> V_57 , V_142 ) ;
if ( V_74 -> V_141 == NULL ) {
V_137 = - V_64 ;
goto V_151;
}
if ( ( V_150 -> V_152 & V_153 ) == V_154 ) {
* ( V_155 * ) V_74 -> V_141 = V_4 -> V_133 << 1 ;
} else if ( ( V_150 -> V_152 & V_153 ) \
== V_156 ) {
V_2 = ( F_70 ( V_150 -> V_157 ) & V_87 ) ?
V_72 : V_32 ;
V_1 = F_70 ( V_150 -> V_157 ) & V_158 ;
* ( V_155 * ) V_74 -> V_141 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_137 = F_66 ( & V_54 -> V_75 , V_74 , V_142 ) ;
if ( V_137 )
goto V_159;
return 0 ;
V_159:
F_30 ( V_74 -> V_141 ) ;
V_151:
F_50 ( V_54 -> V_125 ) ;
F_60 ( & V_54 -> V_75 , V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
return V_137 ;
}
static void
F_71 ( struct V_129 * V_75 , struct V_140 * V_74 )
{
struct V_3 * V_4 = V_74 -> V_160 ;
unsigned long V_130 ;
if ( V_4 -> V_161 ) {
F_24 ( V_4 , V_4 -> V_162 ) ;
V_4 -> V_161 = false ;
if ( V_4 -> V_162 )
F_72 ( & V_4 -> V_94 , V_163 ) ;
}
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_164 )
F_73 ( V_4 , V_4 -> V_164 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
}
static int F_74 ( struct V_3 * V_4 )
{
int V_137 ;
struct V_53 * V_54 ;
V_54 = ( V_4 -> V_144 == V_72 ) ? V_4 -> V_135 : V_4 -> V_136 ;
V_4 -> V_92 -> V_160 = V_4 ;
V_4 -> V_92 -> V_127 = F_71 ;
V_137 = F_66 ( & V_54 -> V_75 , V_4 -> V_92 , V_63 ) ;
return V_137 ;
}
static int F_75 ( struct V_53 * V_54 )
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
F_51 ( & V_166 -> V_75 , & V_56 -> V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
}
}
if ( V_137 == - V_118 )
V_137 = 0 ;
return V_137 ;
}
static void F_76 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
struct V_53 * V_54 = & V_4 -> V_53 [ 0 ] ;
struct V_149 V_74 ;
int type , V_1 , V_2 , V_167 = - V_37 ;
T_2 V_168 = 0 ;
F_49 ( V_4 -> V_135 ) ;
F_49 ( V_4 -> V_136 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_74 , & V_54 -> V_101 . V_65 -> V_150 , sizeof( V_74 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_74 . V_152 ;
V_4 -> V_144 = ( type & V_169 ) ? V_72 : V_32 ;
switch ( V_74 . V_170 ) {
case V_171 :
if ( type == ( V_172 | V_156 ) &&
F_70 ( V_74 . V_173 ) ==
V_174 ) {
if ( V_74 . V_175 != 0 )
break;
V_1 = F_70 ( V_74 . V_157 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_158 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_53 [ V_1 ] . V_176 ) {
F_50 ( & V_4 -> V_125 ) ;
V_167 = F_77 (
& V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_52 ( & V_4 -> V_125 ) ;
if ( V_167 )
break;
}
V_167 = F_74 ( V_4 ) ;
} else if ( type == ( V_172 | V_154 ) &&
F_70 ( V_74 . V_173 ) ==
V_177 ) {
if ( V_74 . V_175 != 0 )
break;
V_4 -> V_133 = 0 ;
V_167 = F_74 ( V_4 ) ;
} else {
goto V_178;
}
break;
case V_179 :
if ( type != ( V_169 | V_154 ) &&
type != ( V_169 | V_156 ) &&
type != ( V_169 | V_180 ) )
goto V_178;
if ( F_70 ( V_74 . V_175 ) != 2 ||
F_70 ( V_74 . V_173 ) != 0 )
break;
V_167 = F_69 ( V_4 , & V_74 ) ;
break;
case V_181 :
if ( type != ( V_172 | V_154 ) )
goto V_178;
if ( F_70 ( V_74 . V_175 ) != 0 ||
F_70 ( V_74 . V_157 ) != 0 )
break;
V_4 -> V_162 = ( T_2 ) F_70 ( V_74 . V_173 ) ;
V_4 -> V_161 = true ;
V_167 = F_74 ( V_4 ) ;
break;
case V_182 :
if ( type == ( V_172 | V_156 ) &&
F_70 ( V_74 . V_173 ) ==
V_174 ) {
if ( V_74 . V_175 != 0 )
break;
V_1 = F_70 ( V_74 . V_157 ) ;
V_2 = V_1 & V_87 ;
V_1 &= V_158 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_50 ( & V_4 -> V_125 ) ;
V_167 = F_78 ( & V_4 -> V_53 [ V_1 ] . V_75 ) ;
F_52 ( & V_4 -> V_125 ) ;
if ( ! V_167 )
F_74 ( V_4 ) ;
} else if ( type == ( V_172 | V_154 ) ) {
if ( V_74 . V_175 != 0 )
break;
switch ( F_70 ( V_74 . V_173 ) ) {
case V_177 :
V_4 -> V_133 = 1 ;
V_167 = F_74 ( V_4 ) ;
break;
case V_183 :
V_168 = F_70 ( V_74 . V_157 ) >> 8 ;
switch ( V_168 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
V_4 -> V_164 = V_168 ;
V_167 = F_74 (
V_4 ) ;
break;
default:
break;
}
break;
case V_189 :
if ( F_79 ( V_4 ) ) {
V_4 -> V_94 . V_190 = 1 ;
V_167 = F_74 (
V_4 ) ;
}
break;
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
V_4 -> V_144 = V_72 ;
F_50 ( & V_4 -> V_125 ) ;
V_167 = V_4 -> V_138 -> V_150 ( & V_4 -> V_94 , & V_74 ) ;
F_52 ( & V_4 -> V_125 ) ;
break;
}
if ( V_167 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_78 ( & V_54 -> V_75 ) )
F_64 ( V_4 -> V_139 , L_5 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
static void F_80 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
unsigned V_58 ;
int V_167 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_75 . V_143 == NULL )
continue;
if ( F_16 ( V_4 , V_58 ) ) {
V_167 = F_75 ( V_54 ) ;
if ( V_54 -> type == V_112 ) {
if ( V_167 > 0 )
V_167 = F_74 ( V_4 ) ;
if ( V_167 < 0 ) {
F_50 ( & V_4 -> V_125 ) ;
if ( F_78 ( & V_54 -> V_75 ) )
F_64 ( V_4 -> V_139 ,
L_5 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
}
if ( V_58 == 0 &&
F_17 ( V_4 , V_33 , F_6 ( 0 ) ) )
F_76 ( V_4 ) ;
}
}
static int F_81 ( struct V_129 * V_75 ,
const struct V_191 * V_143 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
T_1 V_110 = 0 ;
if ( V_75 == NULL || V_143 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_75 . V_143 = V_143 ;
if ( ! F_32 ( & V_54 -> V_101 . V_102 ) )
F_67 ( V_54 -> V_4 -> V_139 , L_6 ) ;
V_54 -> V_2 = F_82 ( V_143 ) ? V_72 : V_32 ;
V_54 -> V_1 = F_83 ( V_143 ) ;
V_54 -> type = F_84 ( V_143 ) ;
V_54 -> V_75 . V_76 = F_85 ( V_143 ) & 0x07ff ;
V_54 -> V_75 . V_146 = F_86 ( F_85 ( V_143 ) ) ;
if ( V_54 -> type == V_112 )
V_110 |= V_192 ;
V_110 |= V_193 ;
V_110 |= ( V_54 -> V_75 . V_76 << F_11 ( V_194 ) ) & V_194 ;
if ( V_54 -> type == V_71 && V_54 -> V_2 == V_72 )
V_110 |= 3 << F_11 ( V_111 ) ;
V_54 -> V_101 . V_65 -> V_110 = F_31 ( V_110 ) ;
V_54 -> V_101 . V_65 -> V_85 . V_86 |= F_31 ( V_98 ) ;
if ( V_54 -> V_1 != 0 && V_54 -> type == V_112 ) {
F_64 ( V_54 -> V_4 -> V_139 , L_7 ) ;
V_137 = - V_37 ;
}
if ( V_54 -> V_1 )
V_137 |= F_10 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_87 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_195 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL )
return - V_37 ;
else if ( V_54 -> V_75 . V_143 == NULL )
return - V_118 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_195 = V_54 -> V_2 ;
do {
V_137 |= F_49 ( V_54 ) ;
V_137 |= F_9 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_195 );
V_54 -> V_75 . V_143 = NULL ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static struct V_140 * F_88 ( struct V_129 * V_75 , T_3 V_142 )
{
struct V_55 * V_56 = NULL ;
if ( V_75 == NULL )
return NULL ;
V_56 = F_28 ( sizeof( struct V_55 ) , V_142 ) ;
if ( V_56 != NULL ) {
F_34 ( & V_56 -> V_102 ) ;
F_34 ( & V_56 -> V_83 ) ;
}
return ( V_56 == NULL ) ? NULL : & V_56 -> V_74 ;
}
static void F_89 ( struct V_129 * V_75 , struct V_140 * V_74 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
struct V_60 * V_62 , * V_116 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL ) {
return;
} else if ( ! F_32 ( & V_56 -> V_102 ) ) {
F_64 ( V_54 -> V_4 -> V_139 , L_8 ) ;
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
static int F_90 ( struct V_129 * V_75 , struct V_140 * V_74 ,
T_3 T_4 V_142 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_74 == NULL || V_54 -> V_75 . V_143 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_137 = F_66 ( V_75 , V_74 , V_142 ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_91 ( struct V_129 * V_75 , struct V_140 * V_74 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
struct V_55 * V_56 = F_54 ( V_74 , struct V_55 , V_74 ) ;
unsigned long V_130 ;
struct V_60 * V_62 , * V_116 ;
if ( V_75 == NULL || V_74 == NULL || V_56 -> V_74 . V_92 != - V_93 ||
V_54 -> V_75 . V_143 == NULL || F_32 ( & V_56 -> V_102 ) ||
F_32 ( & V_54 -> V_101 . V_102 ) )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_45 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_8 ) ;
F_92 ( & V_62 -> V_85 ) ;
F_30 ( V_62 ) ;
}
F_47 ( & V_56 -> V_102 ) ;
F_48 ( & V_54 -> V_4 -> V_94 , V_74 , V_54 -> V_2 ) ;
V_74 -> V_92 = - V_196 ;
if ( V_56 -> V_74 . V_127 != NULL ) {
F_50 ( V_54 -> V_125 ) ;
F_51 ( & V_54 -> V_75 , & V_56 -> V_74 ) ;
F_52 ( V_54 -> V_125 ) ;
}
F_56 ( V_54 -> V_125 , V_130 ) ;
return 0 ;
}
static int F_93 ( struct V_129 * V_75 , int V_36 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
int V_195 , V_137 = 0 ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_143 == NULL )
return - V_37 ;
if ( F_68 ( V_54 -> V_75 . V_143 ) )
return - V_197 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
#ifndef F_94
if ( V_36 && V_54 -> type == V_198 && V_54 -> V_2 == V_72 &&
! F_32 ( & V_54 -> V_101 . V_102 ) ) {
F_56 ( V_54 -> V_125 , V_130 ) ;
return - V_34 ;
}
#endif
V_195 = V_54 -> V_2 ;
do {
V_137 |= F_14 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 , V_36 ) ;
if ( ! V_36 )
V_54 -> V_176 = 0 ;
if ( V_54 -> type == V_112 )
V_54 -> V_2 = ( V_54 -> V_2 == V_72 ) ? V_32 : V_72 ;
} while ( V_54 -> V_2 != V_195 );
F_56 ( V_54 -> V_125 , V_130 ) ;
return V_137 ;
}
static int F_95 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL || V_54 -> V_75 . V_143 == NULL )
return - V_37 ;
F_55 ( V_54 -> V_125 , V_130 ) ;
V_54 -> V_176 = 1 ;
F_56 ( V_54 -> V_125 , V_130 ) ;
return F_78 ( V_75 ) ;
}
static void F_96 ( struct V_129 * V_75 )
{
struct V_53 * V_54 = F_54 ( V_75 , struct V_53 , V_75 ) ;
unsigned long V_130 ;
if ( V_75 == NULL ) {
F_64 ( V_54 -> V_4 -> V_139 , L_9 , F_36 ( V_54 ) ) ;
return;
}
F_55 ( V_54 -> V_125 , V_130 ) ;
F_5 ( V_54 -> V_4 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_56 ( V_54 -> V_125 , V_130 ) ;
}
static int F_97 ( struct V_128 * V_199 , int V_200 )
{
struct V_3 * V_4 = F_54 ( V_199 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_201 = 0 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
V_4 -> V_202 = V_200 ;
if ( V_4 -> V_138 )
V_201 = 1 ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
if ( V_201 ) {
if ( V_200 ) {
F_98 ( & V_199 -> V_139 ) ;
F_99 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_72 ( V_199 , V_203 ) ;
} else {
if ( V_4 -> V_138 )
V_4 -> V_138 -> V_204 ( & V_4 -> V_94 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_205 -> V_206 )
V_4 -> V_205 -> V_206 ( V_4 ,
V_207 ) ;
F_53 ( & V_4 -> V_94 ) ;
F_100 ( & V_199 -> V_139 ) ;
F_72 ( V_199 , V_208 ) ;
}
}
return 0 ;
}
static int F_101 ( struct V_128 * V_199 )
{
struct V_3 * V_4 = F_54 ( V_199 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_88 = 0 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( ! V_4 -> V_133 ) {
V_88 = - V_197 ;
goto V_209;
}
if ( ! F_7 ( V_4 , V_46 , V_210 ) ) {
V_88 = - V_37 ;
goto V_209;
}
F_4 ( V_4 , V_46 , V_211 , V_211 ) ;
V_209:
F_56 ( & V_4 -> V_125 , V_130 ) ;
return V_88 ;
}
static int F_102 ( struct V_128 * V_199 , unsigned V_212 )
{
struct V_3 * V_4 = F_54 ( V_199 , struct V_3 , V_94 ) ;
if ( V_4 -> V_213 )
return F_103 ( V_4 -> V_213 , V_212 ) ;
return - V_214 ;
}
static int F_104 ( struct V_128 * V_199 , int V_215 )
{
struct V_3 * V_4 = F_54 ( V_199 , struct V_3 , V_94 ) ;
if ( ! V_4 -> V_202 )
return - V_197 ;
if ( V_215 )
F_4 ( V_4 , V_16 , V_17 , V_17 ) ;
else
F_4 ( V_4 , V_16 , V_17 , 0 ) ;
return 0 ;
}
static int F_105 ( struct V_3 * V_4 )
{
int V_137 = 0 , V_58 , V_216 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 / 2 ; V_58 ++ )
for ( V_216 = V_32 ; V_216 <= V_72 ; V_216 ++ ) {
int V_217 = V_58 + V_216 * V_4 -> V_7 / 2 ;
struct V_53 * V_54 = & V_4 -> V_53 [ V_217 ] ;
F_106 ( V_54 -> V_218 , sizeof( V_54 -> V_218 ) , L_10 , V_58 ,
( V_216 == V_72 ) ? L_11 : L_12 ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_125 = & V_4 -> V_125 ;
V_54 -> V_66 = V_4 -> V_66 ;
V_54 -> V_75 . V_218 = V_54 -> V_218 ;
V_54 -> V_75 . V_219 = & V_220 ;
F_107 ( & V_54 -> V_75 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_54 -> V_101 . V_102 ) ;
V_54 -> V_101 . V_65 = F_29 ( V_4 -> V_221 , V_222 ,
& V_54 -> V_101 . V_8 ) ;
if ( V_54 -> V_101 . V_65 == NULL )
V_137 = - V_64 ;
else
memset ( V_54 -> V_101 . V_65 , 0 , sizeof( * V_54 -> V_101 . V_65 ) ) ;
if ( V_58 == 0 ) {
if ( V_216 == V_32 )
V_4 -> V_135 = V_54 ;
else
V_4 -> V_136 = V_54 ;
F_107 ( & V_54 -> V_75 , V_223 ) ;
continue;
}
F_35 ( & V_54 -> V_75 . V_224 , & V_4 -> V_94 . V_224 ) ;
}
return V_137 ;
}
static void F_108 ( struct V_3 * V_4 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_7 ; V_58 ++ ) {
struct V_53 * V_54 = & V_4 -> V_53 [ V_58 ] ;
if ( V_54 -> V_114 )
F_42 ( V_54 ) ;
F_43 ( V_4 -> V_221 , V_54 -> V_101 . V_65 , V_54 -> V_101 . V_8 ) ;
}
}
static int F_109 ( struct V_128 * V_94 ,
struct V_225 * V_138 )
{
struct V_3 * V_4 = F_54 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
int V_137 = - V_64 ;
if ( V_138 -> V_204 == NULL )
return - V_37 ;
V_4 -> V_135 -> V_75 . V_143 = & V_226 ;
V_137 = F_110 ( & V_4 -> V_135 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_136 -> V_75 . V_143 = & V_227 ;
V_137 = F_110 ( & V_4 -> V_136 -> V_75 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_138 = V_138 ;
if ( F_79 ( V_4 ) && V_4 -> V_228 . V_229 ) {
F_111 ( V_4 ) ;
return V_137 ;
}
F_98 ( & V_4 -> V_94 . V_139 ) ;
if ( V_4 -> V_202 ) {
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_99 ( V_4 ) ;
} else {
F_100 ( & V_4 -> V_94 . V_139 ) ;
return V_137 ;
}
V_137 = F_3 ( V_4 , V_4 -> V_135 -> V_101 . V_8 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
if ( V_137 )
F_100 ( & V_4 -> V_94 . V_139 ) ;
return V_137 ;
}
static int F_112 ( struct V_128 * V_94 )
{
struct V_3 * V_4 = F_54 ( V_94 , struct V_3 , V_94 ) ;
unsigned long V_130 ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
if ( V_4 -> V_202 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_205 -> V_206 )
V_4 -> V_205 -> V_206 ( V_4 ,
V_207 ) ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
F_53 ( & V_4 -> V_94 ) ;
F_55 ( & V_4 -> V_125 , V_130 ) ;
F_113 ( & V_4 -> V_94 . V_139 ) ;
}
V_4 -> V_138 = NULL ;
F_56 ( & V_4 -> V_125 , V_130 ) ;
return 0 ;
}
static T_5 F_114 ( struct V_3 * V_4 )
{
T_5 V_137 ;
T_1 V_230 ;
if ( V_4 == NULL )
return V_231 ;
F_52 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_205 -> V_130 & V_232 ) {
if ( F_7 ( V_4 , V_233 , V_234 ) !=
V_235 ) {
F_50 ( & V_4 -> V_125 ) ;
return V_236 ;
}
}
V_230 = F_18 ( V_4 ) ;
if ( V_230 ) {
if ( V_14 & V_230 )
F_61 ( V_4 ) ;
if ( V_13 & V_230 ) {
V_4 -> V_94 . V_131 = F_15 ( V_4 ) ?
V_237 : V_238 ;
if ( V_4 -> V_134 && V_4 -> V_138 -> V_239 ) {
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_239 ( & V_4 -> V_94 ) ;
F_52 ( & V_4 -> V_125 ) ;
V_4 -> V_134 = 0 ;
}
}
if ( V_11 & V_230 )
F_80 ( V_4 ) ;
if ( V_15 & V_230 ) {
if ( V_4 -> V_94 . V_131 != V_132 &&
V_4 -> V_138 -> V_240 ) {
V_4 -> V_134 = 1 ;
F_50 ( & V_4 -> V_125 ) ;
V_4 -> V_138 -> V_240 ( & V_4 -> V_94 ) ;
F_72 ( & V_4 -> V_94 ,
V_241 ) ;
F_52 ( & V_4 -> V_125 ) ;
}
}
V_137 = V_231 ;
} else {
V_137 = V_236 ;
}
F_50 ( & V_4 -> V_125 ) ;
return V_137 ;
}
static int F_115 ( struct V_3 * V_4 )
{
struct V_242 * V_139 = V_4 -> V_139 ;
int V_137 = 0 ;
F_116 ( & V_4 -> V_125 ) ;
V_4 -> V_94 . V_219 = & V_243 ;
V_4 -> V_94 . V_131 = V_132 ;
V_4 -> V_94 . V_244 = V_237 ;
V_4 -> V_94 . V_245 = V_4 -> V_245 ? 1 : 0 ;
V_4 -> V_94 . V_218 = V_4 -> V_205 -> V_218 ;
F_34 ( & V_4 -> V_94 . V_224 ) ;
V_4 -> V_221 = F_117 ( L_13 , V_139 ,
sizeof( struct V_246 ) ,
64 , V_81 ) ;
if ( V_4 -> V_221 == NULL )
return - V_64 ;
V_4 -> V_66 = F_117 ( L_14 , V_139 ,
sizeof( struct V_67 ) ,
64 , V_81 ) ;
if ( V_4 -> V_66 == NULL ) {
V_137 = - V_64 ;
goto V_247;
}
V_137 = F_105 ( V_4 ) ;
if ( V_137 )
goto V_248;
V_4 -> V_94 . V_249 = & V_4 -> V_136 -> V_75 ;
V_137 = F_118 ( V_139 , & V_4 -> V_94 ) ;
if ( V_137 )
goto F_108;
F_119 ( & V_4 -> V_94 . V_139 ) ;
F_120 ( & V_4 -> V_94 . V_139 ) ;
return V_137 ;
F_108:
F_108 ( V_4 ) ;
V_248:
F_121 ( V_4 -> V_66 ) ;
V_247:
F_121 ( V_4 -> V_221 ) ;
return V_137 ;
}
void F_122 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_250 [ V_251 ] )
return;
F_123 ( & V_4 -> V_94 ) ;
F_108 ( V_4 ) ;
F_121 ( V_4 -> V_66 ) ;
F_121 ( V_4 -> V_221 ) ;
}
static int F_124 ( struct V_3 * V_4 )
{
if ( V_4 -> V_245 )
F_125 ( V_4 , V_252 | V_253 ,
V_252 | V_253 ) ;
return 0 ;
}
static void F_126 ( struct V_3 * V_4 )
{
if ( V_4 -> V_245 )
F_125 ( V_4 , V_253 | V_252 , V_252 ) ;
}
int F_127 ( struct V_3 * V_4 )
{
struct V_254 * V_255 ;
if ( ! F_7 ( V_4 , V_256 , V_257 ) )
return - V_258 ;
V_255 = F_128 ( V_4 -> V_139 , sizeof( struct V_254 ) , V_222 ) ;
if ( ! V_255 )
return - V_64 ;
V_255 -> V_259 = F_124 ;
V_255 -> V_260 = F_126 ;
V_255 -> V_261 = F_114 ;
V_255 -> V_218 = L_15 ;
V_4 -> V_250 [ V_251 ] = V_255 ;
return F_115 ( V_4 ) ;
}
