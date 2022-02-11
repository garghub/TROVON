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
} else {
F_4 ( V_4 , V_10 , ~ 0 , 0 ) ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
do {
F_4 ( V_4 , V_16 , F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_16 , F_6 ( V_5 ) ) )
F_8 () ;
} while ( F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) );
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
F_5 ( V_4 , V_1 , V_2 ) ;
F_4 ( V_4 , V_18 + V_1 ,
V_2 ? V_19 : V_20 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , int V_1 , int V_2 , int type )
{
T_1 V_21 , V_22 ;
if ( V_2 ) {
V_21 = V_23 ;
V_22 = type << F_11 ( V_21 ) ;
V_21 |= V_24 ;
V_21 |= V_25 ;
V_22 |= V_25 ;
V_21 |= V_19 ;
V_22 |= V_19 ;
} else {
V_21 = V_26 ;
V_22 = type << F_11 ( V_21 ) ;
V_21 |= V_27 ;
V_21 |= V_28 ;
V_22 |= V_28 ;
V_21 |= V_20 ;
V_22 |= V_20 ;
}
F_4 ( V_4 , V_18 + V_1 , V_21 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
T_1 V_21 = V_2 ? V_24 : V_27 ;
return F_7 ( V_4 , V_18 + V_1 , V_21 ) ? 1 : 0 ;
}
static int F_13 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_14 ( V_4 , V_29 , F_6 ( V_5 ) ) ;
}
static int F_15 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_30 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_30 && V_2 == V_31 && F_7 ( V_4 , V_29 , F_6 ( V_1 ) ) )
return - V_32 ;
F_4 ( V_4 , V_33 , F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
F_8 () ;
if ( V_30 && V_2 == V_31 && F_7 ( V_4 , V_29 , F_6 ( V_1 ) ) )
return - V_32 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_34 )
{
if ( V_34 != 0 && V_34 != 1 )
return - V_35 ;
do {
enum V_36 V_37 = V_18 + V_1 ;
T_1 V_38 = V_2 ? V_24 : V_27 ;
T_1 V_39 = V_2 ? V_25 : V_28 ;
F_4 ( V_4 , V_37 , V_38 | V_39 ,
V_34 ? V_38 : V_39 ) ;
} while ( V_34 != F_12 ( V_4 , V_1 , V_2 ) );
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
return V_4 -> V_40 . V_41 ? F_7 ( V_4 , V_42 , V_43 ) :
F_7 ( V_4 , V_44 , V_45 ) ;
}
static T_1 F_18 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_10 , ~ 0 ) ;
}
static T_1 F_19 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_46 , ~ 0 ) ;
}
static int F_20 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_14 ( V_4 , V_47 , F_6 ( V_5 ) ) ;
}
static T_1 F_21 ( struct V_3 * V_4 )
{
T_1 V_37 = F_19 ( V_4 ) & F_18 ( V_4 ) ;
F_4 ( V_4 , V_46 , ~ 0 , V_37 ) ;
return V_37 ;
}
static int F_22 ( struct V_3 * V_4 )
{
return F_23 ( V_4 , V_48 , V_49 , 0 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
return F_23 ( V_4 , V_48 , V_49 , V_49 ) ;
}
static void F_25 ( struct V_3 * V_4 , T_2 V_34 )
{
F_4 ( V_4 , V_50 , V_51 ,
V_34 << F_11 ( V_51 ) ) ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_25 ( V_4 , 0 ) ;
F_4 ( V_4 , V_16 , ~ 0 , ~ 0 ) ;
F_4 ( V_4 , V_29 , 0 , 0 ) ;
F_4 ( V_4 , V_47 , 0 , 0 ) ;
while ( F_7 ( V_4 , V_33 , ~ 0 ) )
F_27 ( 10 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_53 , struct V_54 * V_55 ,
unsigned V_56 )
{
int V_57 ;
T_1 V_58 ;
struct V_59 * V_60 , * V_61 = F_29 ( sizeof( struct V_59 ) ,
V_62 ) ;
if ( V_61 == NULL )
return - V_63 ;
V_61 -> V_64 = F_30 ( V_53 -> V_65 , V_62 ,
& V_61 -> V_8 ) ;
if ( V_61 -> V_64 == NULL ) {
F_31 ( V_61 ) ;
return - V_63 ;
}
memset ( V_61 -> V_64 , 0 , sizeof( struct V_66 ) ) ;
V_61 -> V_64 -> V_67 = F_32 ( V_56 << F_11 ( V_68 ) ) ;
V_61 -> V_64 -> V_67 &= F_32 ( V_68 ) ;
V_61 -> V_64 -> V_67 |= F_32 ( V_69 ) ;
V_58 = ( T_1 ) ( V_55 -> V_70 . V_8 + V_55 -> V_70 . V_71 ) ;
if ( V_56 ) {
V_61 -> V_64 -> V_72 [ 0 ] = F_32 ( V_58 ) ;
for ( V_57 = 1 ; V_57 < V_73 ; V_57 ++ ) {
T_1 V_72 = V_58 + V_57 * V_74 ;
V_72 &= ~ V_75 ;
V_61 -> V_64 -> V_72 [ V_57 ] = F_32 ( V_72 ) ;
}
}
V_55 -> V_70 . V_71 += V_56 ;
if ( ! F_33 ( & V_55 -> V_76 ) ) {
V_60 = F_34 ( V_55 -> V_76 . V_77 ,
struct V_59 , V_78 ) ;
V_60 -> V_64 -> V_79 = F_32 ( V_61 -> V_8 ) ;
}
F_35 ( & V_61 -> V_78 ) ;
F_36 ( & V_61 -> V_78 , & V_55 -> V_76 ) ;
return 0 ;
}
static inline T_2 F_37 ( struct V_52 * V_80 )
{
return ( ( V_80 -> V_2 == V_81 ) ? V_82 : 0 ) | V_80 -> V_1 ;
}
static int F_38 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_3 * V_4 = V_53 -> V_4 ;
int V_83 = 0 ;
unsigned V_84 = V_55 -> V_70 . V_56 ;
int V_85 = V_73 ;
struct V_59 * V_86 , * V_60 ;
if ( V_55 -> V_70 . V_87 == - V_88 )
return - V_88 ;
V_55 -> V_70 . V_87 = - V_88 ;
V_83 = F_39 ( & V_4 -> V_89 , & V_55 -> V_70 , V_53 -> V_2 ) ;
if ( V_83 )
return V_83 ;
if ( V_55 -> V_70 . V_8 % V_90 )
V_85 -- ;
if ( V_84 == 0 )
F_28 ( V_53 , V_55 , 0 ) ;
while ( V_84 > 0 ) {
unsigned V_91 = F_40 ( V_55 -> V_70 . V_56 - V_55 -> V_70 . V_71 ,
( unsigned ) ( V_85 * V_74 ) ) ;
F_28 ( V_53 , V_55 , V_91 ) ;
V_84 -= V_91 ;
}
if ( V_55 -> V_70 . V_92 && V_55 -> V_70 . V_56
&& ( V_55 -> V_70 . V_56 % V_53 -> V_80 . V_93 == 0 ) )
F_28 ( V_53 , V_55 , 0 ) ;
V_86 = F_41 ( & V_55 -> V_76 , struct V_59 , V_78 ) ;
V_60 = F_34 ( V_55 -> V_76 . V_77 ,
struct V_59 , V_78 ) ;
V_60 -> V_64 -> V_79 = F_32 ( V_94 ) ;
if ( ! V_55 -> V_70 . V_95 )
V_60 -> V_64 -> V_67 |= F_32 ( V_96 ) ;
F_42 () ;
V_55 -> V_70 . V_71 = 0 ;
if ( ! F_33 ( & V_53 -> V_97 . V_98 ) ) {
struct V_54 * V_99 ;
int V_5 = F_1 ( V_53 -> V_1 , V_53 -> V_2 ) ;
int V_100 ;
struct V_59 * V_101 ;
T_1 V_79 = V_86 -> V_8 & V_102 ;
V_99 = F_34 ( V_53 -> V_97 . V_98 . V_77 ,
struct V_54 , V_98 ) ;
V_101 = F_34 ( V_99 -> V_76 . V_77 ,
struct V_59 , V_78 ) ;
V_101 -> V_64 -> V_79 = F_32 ( V_79 ) ;
F_42 () ;
if ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
goto V_103;
do {
F_4 ( V_4 , V_48 , V_104 , V_104 ) ;
V_100 = F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_48 , V_104 ) );
F_4 ( V_4 , V_48 , V_104 , 0 ) ;
if ( V_100 )
goto V_103;
}
V_53 -> V_97 . V_64 -> V_78 . V_79 = F_32 ( V_86 -> V_8 ) ;
V_53 -> V_97 . V_64 -> V_78 . V_67 &=
F_32 ( ~ ( V_105 | V_69 ) ) ;
if ( V_53 -> type == V_106 ) {
T_1 V_107 = V_55 -> V_70 . V_56 / V_53 -> V_80 . V_93 ;
if ( V_55 -> V_70 . V_56 % V_53 -> V_80 . V_93 )
V_107 ++ ;
V_53 -> V_97 . V_64 -> V_108 |= V_107 << F_11 ( V_109 ) ;
}
F_42 () ;
V_83 = F_15 ( V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type == V_110 ) ;
V_103:
return V_83 ;
}
static void F_43 ( struct V_52 * V_53 )
{
struct V_59 * V_111 = V_53 -> V_112 ;
F_44 ( V_53 -> V_65 , V_111 -> V_64 , V_111 -> V_8 ) ;
V_53 -> V_112 = NULL ;
F_31 ( V_111 ) ;
}
static int F_45 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
T_1 V_113 ;
struct V_59 * V_61 , * V_114 ;
unsigned V_115 ;
unsigned V_71 = V_55 -> V_70 . V_56 ;
if ( V_55 -> V_70 . V_87 != - V_88 )
return - V_35 ;
V_55 -> V_70 . V_87 = 0 ;
F_46 (node, tmpnode, &hwreq->tds, td) {
V_113 = F_47 ( V_61 -> V_64 -> V_67 ) ;
if ( ( V_69 & V_113 ) != 0 ) {
V_55 -> V_70 . V_87 = - V_88 ;
return - V_116 ;
}
V_115 = ( V_113 & V_68 ) ;
V_115 >>= F_11 ( V_68 ) ;
V_71 -= V_115 ;
V_55 -> V_70 . V_87 = V_113 & V_117 ;
if ( ( V_105 & V_55 -> V_70 . V_87 ) ) {
V_55 -> V_70 . V_87 = - V_118 ;
break;
} else if ( ( V_119 & V_55 -> V_70 . V_87 ) ) {
V_55 -> V_70 . V_87 = - V_120 ;
break;
} else if ( ( V_121 & V_55 -> V_70 . V_87 ) ) {
V_55 -> V_70 . V_87 = - V_122 ;
break;
}
if ( V_115 ) {
if ( V_53 -> V_2 ) {
V_55 -> V_70 . V_87 = - V_120 ;
break;
}
}
if ( V_53 -> V_112 )
F_43 ( V_53 ) ;
V_53 -> V_112 = V_61 ;
F_48 ( & V_61 -> V_78 ) ;
}
F_49 ( & V_53 -> V_4 -> V_89 , & V_55 -> V_70 , V_53 -> V_2 ) ;
V_55 -> V_70 . V_71 += V_71 ;
if ( V_55 -> V_70 . V_87 )
return V_55 -> V_70 . V_87 ;
return V_55 -> V_70 . V_71 ;
}
static int F_50 ( struct V_52 * V_53 )
__releases( V_53 -> V_123 )
__acquires( V_53 -> V_123 )
{
struct V_59 * V_61 , * V_114 ;
if ( V_53 == NULL )
return - V_35 ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
while ( ! F_33 ( & V_53 -> V_97 . V_98 ) ) {
struct V_54 * V_55 = F_34 ( V_53 -> V_97 . V_98 . V_79 ,
struct V_54 , V_98 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_44 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_78 ) ;
V_61 -> V_64 = NULL ;
F_31 ( V_61 ) ;
}
F_48 ( & V_55 -> V_98 ) ;
V_55 -> V_70 . V_87 = - V_124 ;
if ( V_55 -> V_70 . V_125 != NULL ) {
F_51 ( V_53 -> V_123 ) ;
V_55 -> V_70 . V_125 ( & V_53 -> V_80 , & V_55 -> V_70 ) ;
F_52 ( V_53 -> V_123 ) ;
}
}
if ( V_53 -> V_112 )
F_43 ( V_53 ) ;
return 0 ;
}
static int F_53 ( struct V_126 * V_89 )
{
struct V_127 * V_80 ;
struct V_3 * V_4 = F_54 ( V_89 , struct V_3 , V_89 ) ;
unsigned long V_128 ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
V_4 -> V_89 . V_129 = V_130 ;
V_4 -> V_131 = 0 ;
V_4 -> V_132 = 0 ;
F_56 ( & V_4 -> V_123 , V_128 ) ;
F_57 (ep, gadget) {
F_58 ( V_80 ) ;
}
F_58 ( & V_4 -> V_133 -> V_80 ) ;
F_58 ( & V_4 -> V_134 -> V_80 ) ;
if ( V_4 -> V_135 )
V_4 -> V_135 -> V_136 ( V_89 ) ;
F_57 (ep, gadget) {
F_59 ( V_80 ) ;
}
if ( V_4 -> V_87 != NULL ) {
F_60 ( & V_4 -> V_134 -> V_80 , V_4 -> V_87 ) ;
V_4 -> V_87 = NULL ;
}
return 0 ;
}
static void F_61 ( struct V_3 * V_4 )
__releases( V_4 -> V_123 )
__acquires( V_4 -> V_123 )
{
int V_137 ;
F_51 ( & V_4 -> V_123 ) ;
V_137 = F_53 ( & V_4 -> V_89 ) ;
if ( V_137 )
goto V_103;
V_137 = F_26 ( V_4 ) ;
if ( V_137 )
goto V_103;
V_4 -> V_87 = F_62 ( & V_4 -> V_134 -> V_80 , V_62 ) ;
if ( V_4 -> V_87 == NULL )
V_137 = - V_63 ;
V_103:
F_52 ( & V_4 -> V_123 ) ;
if ( V_137 )
F_63 ( V_4 -> V_138 , L_1 , V_137 ) ;
}
static void F_64 ( struct V_127 * V_80 , struct V_139 * V_70 )
{
if ( V_80 == NULL || V_70 == NULL )
return;
F_31 ( V_70 -> V_140 ) ;
F_60 ( V_80 , V_70 ) ;
}
static int F_65 ( struct V_127 * V_80 , struct V_139 * V_70 ,
T_3 T_4 V_141 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
struct V_54 * V_55 = F_54 ( V_70 , struct V_54 , V_70 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
int V_137 = 0 ;
if ( V_80 == NULL || V_70 == NULL || V_53 -> V_80 . V_142 == NULL )
return - V_35 ;
if ( V_53 -> type == V_110 ) {
if ( V_70 -> V_56 )
V_53 = ( V_4 -> V_143 == V_31 ) ?
V_4 -> V_133 : V_4 -> V_134 ;
if ( ! F_33 ( & V_53 -> V_97 . V_98 ) ) {
F_50 ( V_53 ) ;
V_137 = - V_144 ;
F_66 ( V_53 -> V_4 -> V_138 , L_2 ,
F_37 ( V_53 ) ) ;
}
}
if ( F_67 ( V_53 -> V_80 . V_142 ) &&
V_55 -> V_70 . V_56 > ( 1 + V_53 -> V_80 . V_145 ) * V_53 -> V_80 . V_93 ) {
F_63 ( V_53 -> V_4 -> V_138 , L_3 ) ;
return - V_146 ;
}
if ( ! F_33 ( & V_55 -> V_98 ) ) {
F_63 ( V_53 -> V_4 -> V_138 , L_4 ) ;
return - V_116 ;
}
V_55 -> V_70 . V_87 = - V_147 ;
V_55 -> V_70 . V_71 = 0 ;
V_137 = F_38 ( V_53 , V_55 ) ;
if ( V_137 == - V_88 )
V_137 = 0 ;
if ( ! V_137 )
F_36 ( & V_55 -> V_98 , & V_53 -> V_97 . V_98 ) ;
return V_137 ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_148 * V_149 )
__releases( V_53 -> V_123 )
__acquires( V_53 -> V_123 )
{
struct V_52 * V_53 = V_4 -> V_134 ;
struct V_139 * V_70 = NULL ;
T_3 V_141 = V_62 ;
int V_2 , V_1 , V_137 ;
if ( V_53 == NULL || V_149 == NULL )
return - V_35 ;
F_51 ( V_53 -> V_123 ) ;
V_70 = F_62 ( & V_53 -> V_80 , V_141 ) ;
F_52 ( V_53 -> V_123 ) ;
if ( V_70 == NULL )
return - V_63 ;
V_70 -> V_125 = F_64 ;
V_70 -> V_56 = 2 ;
V_70 -> V_140 = F_29 ( V_70 -> V_56 , V_141 ) ;
if ( V_70 -> V_140 == NULL ) {
V_137 = - V_63 ;
goto V_150;
}
if ( ( V_149 -> V_151 & V_152 ) == V_153 ) {
* ( V_154 * ) V_70 -> V_140 = V_4 -> V_131 << 1 ;
V_137 = 0 ;
} else if ( ( V_149 -> V_151 & V_152 ) \
== V_155 ) {
V_2 = ( F_69 ( V_149 -> V_156 ) & V_82 ) ?
V_81 : V_31 ;
V_1 = F_69 ( V_149 -> V_156 ) & V_157 ;
* ( V_154 * ) V_70 -> V_140 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_137 = F_65 ( & V_53 -> V_80 , V_70 , V_141 ) ;
if ( V_137 )
goto V_158;
return 0 ;
V_158:
F_31 ( V_70 -> V_140 ) ;
V_150:
F_51 ( V_53 -> V_123 ) ;
F_60 ( & V_53 -> V_80 , V_70 ) ;
F_52 ( V_53 -> V_123 ) ;
return V_137 ;
}
static void
F_70 ( struct V_127 * V_80 , struct V_139 * V_70 )
{
struct V_3 * V_4 = V_70 -> V_159 ;
unsigned long V_128 ;
if ( V_4 -> V_160 ) {
F_25 ( V_4 , V_4 -> V_161 ) ;
V_4 -> V_160 = false ;
}
F_55 ( & V_4 -> V_123 , V_128 ) ;
if ( V_4 -> V_162 )
F_71 ( V_4 , V_4 -> V_162 ) ;
F_56 ( & V_4 -> V_123 , V_128 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
int V_137 ;
struct V_52 * V_53 ;
V_53 = ( V_4 -> V_143 == V_81 ) ? V_4 -> V_133 : V_4 -> V_134 ;
V_4 -> V_87 -> V_159 = V_4 ;
V_4 -> V_87 -> V_125 = F_70 ;
V_137 = F_65 ( & V_53 -> V_80 , V_4 -> V_87 , V_62 ) ;
return V_137 ;
}
static int F_73 ( struct V_52 * V_53 )
__releases( V_53 -> V_123 )
__acquires( V_53 -> V_123 )
{
struct V_54 * V_55 , * V_163 ;
struct V_52 * V_164 = V_53 ;
int V_137 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_137 = F_45 ( V_53 , V_55 ) ;
if ( V_137 < 0 )
break;
F_48 ( & V_55 -> V_98 ) ;
if ( V_55 -> V_70 . V_125 != NULL ) {
F_51 ( V_53 -> V_123 ) ;
if ( ( V_53 -> type == V_110 ) &&
V_55 -> V_70 . V_56 )
V_164 = V_53 -> V_4 -> V_134 ;
V_55 -> V_70 . V_125 ( & V_164 -> V_80 , & V_55 -> V_70 ) ;
F_52 ( V_53 -> V_123 ) ;
}
}
if ( V_137 == - V_116 )
V_137 = 0 ;
return V_137 ;
}
static void F_74 ( struct V_3 * V_4 )
__releases( V_4 -> V_123 )
__acquires( V_4 -> V_123 )
{
unsigned V_57 ;
T_2 V_165 = 0 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
int type , V_1 , V_2 , V_166 = - V_35 ;
struct V_148 V_70 ;
if ( V_53 -> V_80 . V_142 == NULL )
continue;
if ( F_20 ( V_4 , V_57 ) ) {
V_166 = F_73 ( V_53 ) ;
if ( V_53 -> type == V_110 ) {
if ( V_166 > 0 )
V_166 = F_72 ( V_4 ) ;
if ( V_166 < 0 ) {
F_51 ( & V_4 -> V_123 ) ;
if ( F_75 ( & V_53 -> V_80 ) )
F_63 ( V_4 -> V_138 ,
L_5 ) ;
F_52 ( & V_4 -> V_123 ) ;
}
}
}
if ( V_53 -> type != V_110 ||
! F_13 ( V_4 , V_57 ) )
continue;
if ( V_57 != 0 ) {
F_66 ( V_4 -> V_138 , L_6 , V_57 ) ;
continue;
}
F_50 ( V_4 -> V_133 ) ;
F_50 ( V_4 -> V_134 ) ;
do {
F_24 ( V_4 ) ;
memcpy ( & V_70 , & V_53 -> V_97 . V_64 -> V_149 , sizeof( V_70 ) ) ;
} while ( ! F_22 ( V_4 ) );
type = V_70 . V_151 ;
V_4 -> V_143 = ( type & V_167 ) ? V_81 : V_31 ;
switch ( V_70 . V_168 ) {
case V_169 :
if ( type == ( V_170 | V_155 ) &&
F_69 ( V_70 . V_171 ) ==
V_172 ) {
if ( V_70 . V_173 != 0 )
break;
V_1 = F_69 ( V_70 . V_156 ) ;
V_2 = V_1 & V_82 ;
V_1 &= V_157 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_52 [ V_1 ] . V_174 ) {
F_51 ( & V_4 -> V_123 ) ;
V_166 = F_76 (
& V_4 -> V_52 [ V_1 ] . V_80 ) ;
F_52 ( & V_4 -> V_123 ) ;
if ( V_166 )
break;
}
V_166 = F_72 ( V_4 ) ;
} else if ( type == ( V_170 | V_153 ) &&
F_69 ( V_70 . V_171 ) ==
V_175 ) {
if ( V_70 . V_173 != 0 )
break;
V_4 -> V_131 = 0 ;
V_166 = F_72 ( V_4 ) ;
} else {
goto V_176;
}
break;
case V_177 :
if ( type != ( V_167 | V_153 ) &&
type != ( V_167 | V_155 ) &&
type != ( V_167 | V_178 ) )
goto V_176;
if ( F_69 ( V_70 . V_173 ) != 2 ||
F_69 ( V_70 . V_171 ) != 0 )
break;
V_166 = F_68 ( V_4 , & V_70 ) ;
break;
case V_179 :
if ( type != ( V_170 | V_153 ) )
goto V_176;
if ( F_69 ( V_70 . V_173 ) != 0 ||
F_69 ( V_70 . V_156 ) != 0 )
break;
V_4 -> V_161 = ( T_2 ) F_69 ( V_70 . V_171 ) ;
V_4 -> V_160 = true ;
V_166 = F_72 ( V_4 ) ;
break;
case V_180 :
if ( type == ( V_170 | V_155 ) &&
F_69 ( V_70 . V_171 ) ==
V_172 ) {
if ( V_70 . V_173 != 0 )
break;
V_1 = F_69 ( V_70 . V_156 ) ;
V_2 = V_1 & V_82 ;
V_1 &= V_157 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_51 ( & V_4 -> V_123 ) ;
V_166 = F_75 ( & V_4 -> V_52 [ V_1 ] . V_80 ) ;
F_52 ( & V_4 -> V_123 ) ;
if ( ! V_166 )
F_72 ( V_4 ) ;
} else if ( type == ( V_170 | V_153 ) ) {
if ( V_70 . V_173 != 0 )
break;
switch ( F_69 ( V_70 . V_171 ) ) {
case V_175 :
V_4 -> V_131 = 1 ;
V_166 = F_72 ( V_4 ) ;
break;
case V_181 :
V_165 = F_69 ( V_70 . V_156 ) >> 8 ;
switch ( V_165 ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
V_4 -> V_162 = V_165 ;
V_166 = F_72 (
V_4 ) ;
break;
default:
break;
}
default:
goto V_176;
}
} else {
goto V_176;
}
break;
default:
V_176:
if ( V_70 . V_173 == 0 )
V_4 -> V_143 = V_81 ;
F_51 ( & V_4 -> V_123 ) ;
V_166 = V_4 -> V_135 -> V_149 ( & V_4 -> V_89 , & V_70 ) ;
F_52 ( & V_4 -> V_123 ) ;
break;
}
if ( V_166 < 0 ) {
F_51 ( & V_4 -> V_123 ) ;
if ( F_75 ( & V_53 -> V_80 ) )
F_63 ( V_4 -> V_138 , L_5 ) ;
F_52 ( & V_4 -> V_123 ) ;
}
}
}
static int F_77 ( struct V_127 * V_80 ,
const struct V_187 * V_142 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
int V_137 = 0 ;
unsigned long V_128 ;
T_1 V_108 = 0 ;
if ( V_80 == NULL || V_142 == NULL )
return - V_35 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
V_53 -> V_80 . V_142 = V_142 ;
if ( ! F_33 ( & V_53 -> V_97 . V_98 ) )
F_66 ( V_53 -> V_4 -> V_138 , L_7 ) ;
V_53 -> V_2 = F_78 ( V_142 ) ? V_81 : V_31 ;
V_53 -> V_1 = F_79 ( V_142 ) ;
V_53 -> type = F_80 ( V_142 ) ;
V_53 -> V_80 . V_93 = F_81 ( V_142 ) & 0x07ff ;
V_53 -> V_80 . V_145 = F_82 ( F_81 ( V_142 ) ) ;
if ( V_53 -> type == V_110 )
V_108 |= V_188 ;
if ( V_53 -> V_1 )
V_108 |= V_189 ;
V_108 |= ( V_53 -> V_80 . V_93 << F_11 ( V_190 ) ) & V_190 ;
V_53 -> V_97 . V_64 -> V_108 = F_32 ( V_108 ) ;
V_53 -> V_97 . V_64 -> V_78 . V_79 |= F_32 ( V_94 ) ;
if ( V_53 -> V_1 )
V_137 |= F_10 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type ) ;
F_56 ( V_53 -> V_123 , V_128 ) ;
return V_137 ;
}
static int F_83 ( struct V_127 * V_80 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
int V_191 , V_137 = 0 ;
unsigned long V_128 ;
if ( V_80 == NULL )
return - V_35 ;
else if ( V_53 -> V_80 . V_142 == NULL )
return - V_116 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
V_191 = V_53 -> V_2 ;
do {
V_137 |= F_50 ( V_53 ) ;
V_137 |= F_9 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_53 -> type == V_110 )
V_53 -> V_2 = ( V_53 -> V_2 == V_81 ) ? V_31 : V_81 ;
} while ( V_53 -> V_2 != V_191 );
V_53 -> V_80 . V_142 = NULL ;
F_56 ( V_53 -> V_123 , V_128 ) ;
return V_137 ;
}
static struct V_139 * F_84 ( struct V_127 * V_80 , T_3 V_141 )
{
struct V_54 * V_55 = NULL ;
if ( V_80 == NULL )
return NULL ;
V_55 = F_29 ( sizeof( struct V_54 ) , V_141 ) ;
if ( V_55 != NULL ) {
F_35 ( & V_55 -> V_98 ) ;
F_35 ( & V_55 -> V_76 ) ;
}
return ( V_55 == NULL ) ? NULL : & V_55 -> V_70 ;
}
static void F_85 ( struct V_127 * V_80 , struct V_139 * V_70 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
struct V_54 * V_55 = F_54 ( V_70 , struct V_54 , V_70 ) ;
struct V_59 * V_61 , * V_114 ;
unsigned long V_128 ;
if ( V_80 == NULL || V_70 == NULL ) {
return;
} else if ( ! F_33 ( & V_55 -> V_98 ) ) {
F_63 ( V_53 -> V_4 -> V_138 , L_8 ) ;
return;
}
F_55 ( V_53 -> V_123 , V_128 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_44 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_78 ) ;
V_61 -> V_64 = NULL ;
F_31 ( V_61 ) ;
}
F_31 ( V_55 ) ;
F_56 ( V_53 -> V_123 , V_128 ) ;
}
static int F_86 ( struct V_127 * V_80 , struct V_139 * V_70 ,
T_3 T_4 V_141 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
int V_137 = 0 ;
unsigned long V_128 ;
if ( V_80 == NULL || V_70 == NULL || V_53 -> V_80 . V_142 == NULL )
return - V_35 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
V_137 = F_65 ( V_80 , V_70 , V_141 ) ;
F_56 ( V_53 -> V_123 , V_128 ) ;
return V_137 ;
}
static int F_87 ( struct V_127 * V_80 , struct V_139 * V_70 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
struct V_54 * V_55 = F_54 ( V_70 , struct V_54 , V_70 ) ;
unsigned long V_128 ;
if ( V_80 == NULL || V_70 == NULL || V_55 -> V_70 . V_87 != - V_88 ||
V_53 -> V_80 . V_142 == NULL || F_33 ( & V_55 -> V_98 ) ||
F_33 ( & V_53 -> V_97 . V_98 ) )
return - V_35 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_48 ( & V_55 -> V_98 ) ;
F_49 ( & V_53 -> V_4 -> V_89 , V_70 , V_53 -> V_2 ) ;
V_70 -> V_87 = - V_192 ;
if ( V_55 -> V_70 . V_125 != NULL ) {
F_51 ( V_53 -> V_123 ) ;
V_55 -> V_70 . V_125 ( & V_53 -> V_80 , & V_55 -> V_70 ) ;
F_52 ( V_53 -> V_123 ) ;
}
F_56 ( V_53 -> V_123 , V_128 ) ;
return 0 ;
}
static int F_88 ( struct V_127 * V_80 , int V_34 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
int V_191 , V_137 = 0 ;
unsigned long V_128 ;
if ( V_80 == NULL || V_53 -> V_80 . V_142 == NULL )
return - V_35 ;
if ( F_67 ( V_53 -> V_80 . V_142 ) )
return - V_193 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
#ifndef F_89
if ( V_34 && V_53 -> type == V_194 && V_53 -> V_2 == V_81 &&
! F_33 ( & V_53 -> V_97 . V_98 ) ) {
F_56 ( V_53 -> V_123 , V_128 ) ;
return - V_32 ;
}
#endif
V_191 = V_53 -> V_2 ;
do {
V_137 |= F_16 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_53 -> V_174 = 0 ;
if ( V_53 -> type == V_110 )
V_53 -> V_2 = ( V_53 -> V_2 == V_81 ) ? V_31 : V_81 ;
} while ( V_53 -> V_2 != V_191 );
F_56 ( V_53 -> V_123 , V_128 ) ;
return V_137 ;
}
static int F_90 ( struct V_127 * V_80 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
unsigned long V_128 ;
if ( V_80 == NULL || V_53 -> V_80 . V_142 == NULL )
return - V_35 ;
F_55 ( V_53 -> V_123 , V_128 ) ;
V_53 -> V_174 = 1 ;
F_56 ( V_53 -> V_123 , V_128 ) ;
return F_75 ( V_80 ) ;
}
static void F_91 ( struct V_127 * V_80 )
{
struct V_52 * V_53 = F_54 ( V_80 , struct V_52 , V_80 ) ;
unsigned long V_128 ;
if ( V_80 == NULL ) {
F_63 ( V_53 -> V_4 -> V_138 , L_9 , F_37 ( V_53 ) ) ;
return;
}
F_55 ( V_53 -> V_123 , V_128 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_56 ( V_53 -> V_123 , V_128 ) ;
}
static int F_92 ( struct V_126 * V_195 , int V_196 )
{
struct V_3 * V_4 = F_54 ( V_195 , struct V_3 , V_89 ) ;
unsigned long V_128 ;
int V_197 = 0 ;
if ( ! ( V_4 -> V_198 -> V_128 & V_199 ) )
return - V_193 ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
V_4 -> V_200 = V_196 ;
if ( V_4 -> V_135 )
V_197 = 1 ;
F_56 ( & V_4 -> V_123 , V_128 ) ;
if ( V_197 ) {
if ( V_196 ) {
F_93 ( & V_195 -> V_138 ) ;
F_94 ( V_4 , V_201 ) ;
F_3 ( V_4 , V_4 -> V_133 -> V_97 . V_8 ) ;
} else {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_198 -> V_202 )
V_4 -> V_198 -> V_202 ( V_4 ,
V_203 ) ;
F_53 ( & V_4 -> V_89 ) ;
F_95 ( & V_195 -> V_138 ) ;
}
}
return 0 ;
}
static int F_96 ( struct V_126 * V_195 )
{
struct V_3 * V_4 = F_54 ( V_195 , struct V_3 , V_89 ) ;
unsigned long V_128 ;
int V_83 = 0 ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
if ( ! V_4 -> V_131 ) {
V_83 = - V_193 ;
goto V_204;
}
if ( ! F_7 ( V_4 , V_44 , V_205 ) ) {
V_83 = - V_35 ;
goto V_204;
}
F_4 ( V_4 , V_44 , V_206 , V_206 ) ;
V_204:
F_56 ( & V_4 -> V_123 , V_128 ) ;
return V_83 ;
}
static int F_97 ( struct V_126 * V_195 , unsigned V_207 )
{
struct V_3 * V_4 = F_54 ( V_195 , struct V_3 , V_89 ) ;
if ( V_4 -> V_208 )
return F_98 ( V_4 -> V_208 , V_207 ) ;
return - V_209 ;
}
static int F_99 ( struct V_126 * V_195 , int V_210 )
{
struct V_3 * V_4 = F_54 ( V_195 , struct V_3 , V_89 ) ;
if ( V_210 )
F_4 ( V_4 , V_48 , V_211 , V_211 ) ;
else
F_4 ( V_4 , V_48 , V_211 , 0 ) ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_137 = 0 , V_57 , V_212 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 / 2 ; V_57 ++ )
for ( V_212 = V_31 ; V_212 <= V_81 ; V_212 ++ ) {
int V_213 = V_57 + V_212 * V_4 -> V_7 / 2 ;
struct V_52 * V_53 = & V_4 -> V_52 [ V_213 ] ;
F_101 ( V_53 -> V_214 , sizeof( V_53 -> V_214 ) , L_10 , V_57 ,
( V_212 == V_81 ) ? L_11 : L_12 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_123 = & V_4 -> V_123 ;
V_53 -> V_65 = V_4 -> V_65 ;
V_53 -> V_80 . V_214 = V_53 -> V_214 ;
V_53 -> V_80 . V_215 = & V_216 ;
V_53 -> V_80 . V_93 = ( unsigned short ) ~ 0 ;
F_35 ( & V_53 -> V_97 . V_98 ) ;
V_53 -> V_97 . V_64 = F_30 ( V_4 -> V_217 , V_218 ,
& V_53 -> V_97 . V_8 ) ;
if ( V_53 -> V_97 . V_64 == NULL )
V_137 = - V_63 ;
else
memset ( V_53 -> V_97 . V_64 , 0 , sizeof( * V_53 -> V_97 . V_64 ) ) ;
if ( V_57 == 0 ) {
if ( V_212 == V_31 )
V_4 -> V_133 = V_53 ;
else
V_4 -> V_134 = V_53 ;
V_53 -> V_80 . V_93 = V_219 ;
continue;
}
F_36 ( & V_53 -> V_80 . V_220 , & V_4 -> V_89 . V_220 ) ;
}
return V_137 ;
}
static void F_102 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
F_44 ( V_4 -> V_217 , V_53 -> V_97 . V_64 , V_53 -> V_97 . V_8 ) ;
}
}
static int F_103 ( struct V_126 * V_89 ,
struct V_221 * V_135 )
{
struct V_3 * V_4 = F_54 ( V_89 , struct V_3 , V_89 ) ;
unsigned long V_128 ;
int V_137 = - V_63 ;
if ( V_135 -> V_136 == NULL )
return - V_35 ;
V_4 -> V_133 -> V_80 . V_142 = & V_222 ;
V_137 = F_104 ( & V_4 -> V_133 -> V_80 ) ;
if ( V_137 )
return V_137 ;
V_4 -> V_134 -> V_80 . V_142 = & V_223 ;
V_137 = F_104 ( & V_4 -> V_134 -> V_80 ) ;
if ( V_137 )
return V_137 ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
V_4 -> V_135 = V_135 ;
F_93 ( & V_4 -> V_89 . V_138 ) ;
if ( V_4 -> V_198 -> V_128 & V_199 ) {
if ( V_4 -> V_200 ) {
if ( V_4 -> V_198 -> V_128 & V_224 )
F_94 ( V_4 , V_201 ) ;
} else {
F_95 ( & V_4 -> V_89 . V_138 ) ;
goto V_103;
}
}
V_137 = F_3 ( V_4 , V_4 -> V_133 -> V_97 . V_8 ) ;
if ( V_137 )
F_95 ( & V_4 -> V_89 . V_138 ) ;
V_103:
F_56 ( & V_4 -> V_123 , V_128 ) ;
return V_137 ;
}
static int F_105 ( struct V_126 * V_89 ,
struct V_221 * V_135 )
{
struct V_3 * V_4 = F_54 ( V_89 , struct V_3 , V_89 ) ;
unsigned long V_128 ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
if ( ! ( V_4 -> V_198 -> V_128 & V_199 ) ||
V_4 -> V_200 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_198 -> V_202 )
V_4 -> V_198 -> V_202 ( V_4 ,
V_203 ) ;
V_4 -> V_135 = NULL ;
F_56 ( & V_4 -> V_123 , V_128 ) ;
F_53 ( & V_4 -> V_89 ) ;
F_55 ( & V_4 -> V_123 , V_128 ) ;
F_106 ( & V_4 -> V_89 . V_138 ) ;
}
F_56 ( & V_4 -> V_123 , V_128 ) ;
return 0 ;
}
static T_5 F_107 ( struct V_3 * V_4 )
{
T_5 V_137 ;
T_1 V_225 ;
if ( V_4 == NULL )
return V_226 ;
F_52 ( & V_4 -> V_123 ) ;
if ( V_4 -> V_198 -> V_128 & V_224 ) {
if ( F_7 ( V_4 , V_227 , V_228 ) !=
V_201 ) {
F_51 ( & V_4 -> V_123 ) ;
return V_229 ;
}
}
V_225 = F_21 ( V_4 ) ;
if ( V_225 ) {
if ( V_14 & V_225 )
F_61 ( V_4 ) ;
if ( V_13 & V_225 ) {
V_4 -> V_89 . V_129 = F_17 ( V_4 ) ?
V_230 : V_231 ;
if ( V_4 -> V_132 && V_4 -> V_135 -> V_232 ) {
F_51 ( & V_4 -> V_123 ) ;
V_4 -> V_135 -> V_232 ( & V_4 -> V_89 ) ;
F_52 ( & V_4 -> V_123 ) ;
V_4 -> V_132 = 0 ;
}
}
if ( V_11 & V_225 )
F_74 ( V_4 ) ;
if ( V_15 & V_225 ) {
if ( V_4 -> V_89 . V_129 != V_130 &&
V_4 -> V_135 -> V_233 ) {
V_4 -> V_132 = 1 ;
F_51 ( & V_4 -> V_123 ) ;
V_4 -> V_135 -> V_233 ( & V_4 -> V_89 ) ;
F_52 ( & V_4 -> V_123 ) ;
}
}
V_137 = V_226 ;
} else {
V_137 = V_229 ;
}
F_51 ( & V_4 -> V_123 ) ;
return V_137 ;
}
static int F_108 ( struct V_3 * V_4 )
{
struct V_234 * V_138 = V_4 -> V_138 ;
int V_137 = 0 ;
F_109 ( & V_4 -> V_123 ) ;
V_4 -> V_89 . V_215 = & V_235 ;
V_4 -> V_89 . V_129 = V_130 ;
V_4 -> V_89 . V_236 = V_230 ;
V_4 -> V_89 . V_237 = 0 ;
V_4 -> V_89 . V_214 = V_4 -> V_198 -> V_214 ;
F_35 ( & V_4 -> V_89 . V_220 ) ;
V_4 -> V_217 = F_110 ( L_13 , V_138 ,
sizeof( struct V_238 ) ,
64 , V_74 ) ;
if ( V_4 -> V_217 == NULL )
return - V_63 ;
V_4 -> V_65 = F_110 ( L_14 , V_138 ,
sizeof( struct V_66 ) ,
64 , V_74 ) ;
if ( V_4 -> V_65 == NULL ) {
V_137 = - V_63 ;
goto V_239;
}
V_137 = F_100 ( V_4 ) ;
if ( V_137 )
goto V_240;
V_4 -> V_89 . V_241 = & V_4 -> V_134 -> V_80 ;
if ( V_4 -> V_242 ) {
V_4 -> V_208 = F_111 ( V_243 ) ;
if ( F_112 ( V_4 -> V_208 ) )
V_4 -> V_208 = NULL ;
}
if ( V_4 -> V_198 -> V_128 & V_244 ) {
if ( V_4 -> V_208 == NULL ) {
V_137 = - V_245 ;
goto F_102;
}
}
if ( ! ( V_4 -> V_198 -> V_128 & V_224 ) ) {
V_137 = F_94 ( V_4 , V_201 ) ;
if ( V_137 )
goto V_246;
}
if ( V_4 -> V_208 ) {
V_137 = F_113 ( V_4 -> V_208 -> V_247 ,
& V_4 -> V_89 ) ;
if ( V_137 )
goto V_246;
}
V_137 = F_114 ( V_138 , & V_4 -> V_89 ) ;
if ( V_137 )
goto V_248;
F_115 ( & V_4 -> V_89 . V_138 ) ;
F_116 ( & V_4 -> V_89 . V_138 ) ;
return V_137 ;
V_248:
if ( V_4 -> V_208 ) {
F_113 ( V_4 -> V_208 -> V_247 , NULL ) ;
if ( V_4 -> V_242 )
F_117 ( V_4 -> V_208 ) ;
}
F_63 ( V_138 , L_15 , V_137 ) ;
V_246:
if ( V_4 -> V_208 && V_4 -> V_242 )
F_117 ( V_4 -> V_208 ) ;
F_102:
F_102 ( V_4 ) ;
V_240:
F_118 ( V_4 -> V_65 ) ;
V_239:
F_118 ( V_4 -> V_217 ) ;
return V_137 ;
}
static void F_119 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
F_120 ( & V_4 -> V_89 ) ;
F_102 ( V_4 ) ;
F_118 ( V_4 -> V_65 ) ;
F_118 ( V_4 -> V_217 ) ;
if ( V_4 -> V_208 ) {
F_113 ( V_4 -> V_208 -> V_247 , NULL ) ;
if ( V_4 -> V_242 )
F_117 ( V_4 -> V_208 ) ;
}
memset ( & V_4 -> V_89 , 0 , sizeof( V_4 -> V_89 ) ) ;
}
int F_121 ( struct V_3 * V_4 )
{
struct V_249 * V_250 ;
if ( ! F_7 ( V_4 , V_251 , V_252 ) )
return - V_253 ;
V_250 = F_122 ( V_4 -> V_138 , sizeof( struct V_249 ) , V_218 ) ;
if ( ! V_250 )
return - V_63 ;
V_250 -> V_254 = F_108 ;
V_250 -> V_255 = F_119 ;
V_250 -> V_256 = F_107 ;
V_250 -> V_214 = L_16 ;
V_4 -> V_257 [ V_258 ] = V_250 ;
return 0 ;
}
