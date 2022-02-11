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
F_4 ( V_4 , V_16 , ~ 0 , F_6 ( V_5 ) ) ;
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
static int F_13 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_29 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_29 && V_2 == V_30 && F_7 ( V_4 , V_31 , F_6 ( V_1 ) ) )
return - V_32 ;
F_4 ( V_4 , V_33 , ~ 0 , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
F_8 () ;
if ( V_29 && V_2 == V_30 && F_7 ( V_4 , V_31 , F_6 ( V_1 ) ) )
return - V_32 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_34 )
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
static int F_15 ( struct V_3 * V_4 )
{
return V_4 -> V_40 . V_41 ? F_7 ( V_4 , V_42 , V_43 ) :
F_7 ( V_4 , V_44 , V_45 ) ;
}
static int F_16 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_17 ( V_4 , V_46 , F_6 ( V_5 ) ) ;
}
static T_1 F_18 ( struct V_3 * V_4 )
{
T_1 V_37 = F_19 ( V_4 ) & F_20 ( V_4 ) ;
F_4 ( V_4 , V_47 , ~ 0 , V_37 ) ;
return V_37 ;
}
static int F_21 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , V_48 , V_49 , 0 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , V_48 , V_49 , V_49 ) ;
}
static void F_24 ( struct V_3 * V_4 , T_2 V_34 )
{
F_4 ( V_4 , V_50 , V_51 ,
V_34 << F_11 ( V_51 ) ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
F_24 ( V_4 , 0 ) ;
F_4 ( V_4 , V_16 , ~ 0 , ~ 0 ) ;
F_4 ( V_4 , V_31 , 0 , 0 ) ;
F_4 ( V_4 , V_46 , 0 , 0 ) ;
while ( F_7 ( V_4 , V_33 , ~ 0 ) )
F_26 ( 10 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 , struct V_54 * V_55 ,
unsigned V_56 )
{
int V_57 ;
T_1 V_58 ;
struct V_59 * V_60 , * V_61 = F_28 ( sizeof( struct V_59 ) ,
V_62 ) ;
if ( V_61 == NULL )
return - V_63 ;
V_61 -> V_64 = F_29 ( V_53 -> V_65 , V_62 ,
& V_61 -> V_8 ) ;
if ( V_61 -> V_64 == NULL ) {
F_30 ( V_61 ) ;
return - V_63 ;
}
memset ( V_61 -> V_64 , 0 , sizeof( struct V_66 ) ) ;
V_61 -> V_64 -> V_67 = F_31 ( V_56 << F_11 ( V_68 ) ) ;
V_61 -> V_64 -> V_67 &= F_31 ( V_68 ) ;
V_61 -> V_64 -> V_67 |= F_31 ( V_69 ) ;
if ( V_53 -> type == V_70 && V_53 -> V_2 == V_71 ) {
T_1 V_72 = V_55 -> V_73 . V_56 / V_53 -> V_74 . V_75 ;
if ( V_55 -> V_73 . V_56 == 0
|| V_55 -> V_73 . V_56 % V_53 -> V_74 . V_75 )
V_72 ++ ;
V_61 -> V_64 -> V_67 |= V_72 << F_11 ( V_76 ) ;
}
V_58 = ( T_1 ) ( V_55 -> V_73 . V_8 + V_55 -> V_73 . V_77 ) ;
if ( V_56 ) {
V_61 -> V_64 -> V_78 [ 0 ] = F_31 ( V_58 ) ;
for ( V_57 = 1 ; V_57 < V_79 ; V_57 ++ ) {
T_1 V_78 = V_58 + V_57 * V_80 ;
V_78 &= ~ V_81 ;
V_61 -> V_64 -> V_78 [ V_57 ] = F_31 ( V_78 ) ;
}
}
V_55 -> V_73 . V_77 += V_56 ;
if ( ! F_32 ( & V_55 -> V_82 ) ) {
V_60 = F_33 ( V_55 -> V_82 . V_83 ,
struct V_59 , V_84 ) ;
V_60 -> V_64 -> V_85 = F_31 ( V_61 -> V_8 ) ;
}
F_34 ( & V_61 -> V_84 ) ;
F_35 ( & V_61 -> V_84 , & V_55 -> V_82 ) ;
return 0 ;
}
static inline T_2 F_36 ( struct V_52 * V_74 )
{
return ( ( V_74 -> V_2 == V_71 ) ? V_86 : 0 ) | V_74 -> V_1 ;
}
static int F_37 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_3 * V_4 = V_53 -> V_4 ;
int V_87 = 0 ;
unsigned V_88 = V_55 -> V_73 . V_56 ;
int V_89 = V_79 ;
struct V_59 * V_90 , * V_60 ;
if ( V_55 -> V_73 . V_91 == - V_92 )
return - V_92 ;
V_55 -> V_73 . V_91 = - V_92 ;
V_87 = F_38 ( & V_4 -> V_93 , & V_55 -> V_73 , V_53 -> V_2 ) ;
if ( V_87 )
return V_87 ;
if ( V_55 -> V_73 . V_8 % V_94 )
V_89 -- ;
if ( V_88 == 0 )
F_27 ( V_53 , V_55 , 0 ) ;
while ( V_88 > 0 ) {
unsigned V_95 = F_39 ( V_55 -> V_73 . V_56 - V_55 -> V_73 . V_77 ,
( unsigned ) ( V_89 * V_80 ) ) ;
F_27 ( V_53 , V_55 , V_95 ) ;
V_88 -= V_95 ;
}
if ( V_55 -> V_73 . V_96 && V_55 -> V_73 . V_56
&& ( V_55 -> V_73 . V_56 % V_53 -> V_74 . V_75 == 0 ) )
F_27 ( V_53 , V_55 , 0 ) ;
V_90 = F_40 ( & V_55 -> V_82 , struct V_59 , V_84 ) ;
V_60 = F_33 ( V_55 -> V_82 . V_83 ,
struct V_59 , V_84 ) ;
V_60 -> V_64 -> V_85 = F_31 ( V_97 ) ;
if ( ! V_55 -> V_73 . V_98 )
V_60 -> V_64 -> V_67 |= F_31 ( V_99 ) ;
F_41 () ;
V_55 -> V_73 . V_77 = 0 ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
struct V_54 * V_102 ;
int V_5 = F_1 ( V_53 -> V_1 , V_53 -> V_2 ) ;
int V_103 ;
struct V_59 * V_104 ;
T_1 V_85 = V_90 -> V_8 & V_105 ;
V_102 = F_33 ( V_53 -> V_100 . V_101 . V_83 ,
struct V_54 , V_101 ) ;
V_104 = F_33 ( V_102 -> V_82 . V_83 ,
struct V_59 , V_84 ) ;
V_104 -> V_64 -> V_85 = F_31 ( V_85 ) ;
F_41 () ;
if ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
goto V_106;
do {
F_4 ( V_4 , V_48 , V_107 , V_107 ) ;
V_103 = F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_48 , V_107 ) );
F_4 ( V_4 , V_48 , V_107 , 0 ) ;
if ( V_103 )
goto V_106;
}
V_53 -> V_100 . V_64 -> V_84 . V_85 = F_31 ( V_90 -> V_8 ) ;
V_53 -> V_100 . V_64 -> V_84 . V_67 &=
F_31 ( ~ ( V_108 | V_69 ) ) ;
if ( V_53 -> type == V_70 && V_53 -> V_2 == V_30 ) {
T_1 V_72 = V_55 -> V_73 . V_56 / V_53 -> V_74 . V_75 ;
if ( V_55 -> V_73 . V_56 == 0
|| V_55 -> V_73 . V_56 % V_53 -> V_74 . V_75 )
V_72 ++ ;
V_53 -> V_100 . V_64 -> V_109 |= V_72 << F_11 ( V_110 ) ;
}
F_41 () ;
V_87 = F_13 ( V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type == V_111 ) ;
V_106:
return V_87 ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_59 * V_112 = V_53 -> V_113 ;
F_43 ( V_53 -> V_65 , V_112 -> V_64 , V_112 -> V_8 ) ;
V_53 -> V_113 = NULL ;
F_30 ( V_112 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_52 * V_53 ,
struct V_59 * V_61 )
{
V_53 -> V_100 . V_64 -> V_84 . V_85 = V_61 -> V_8 ;
V_53 -> V_100 . V_64 -> V_84 . V_67 &=
F_31 ( ~ ( V_108 | V_69 ) ) ;
F_41 () ;
return F_13 ( V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type == V_111 ) ;
}
static int F_45 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
T_1 V_114 ;
struct V_59 * V_61 , * V_115 ;
unsigned V_116 ;
unsigned V_77 = V_55 -> V_73 . V_56 ;
struct V_3 * V_4 = V_53 -> V_4 ;
if ( V_55 -> V_73 . V_91 != - V_92 )
return - V_35 ;
V_55 -> V_73 . V_91 = 0 ;
F_46 (node, tmpnode, &hwreq->tds, td) {
V_114 = F_47 ( V_61 -> V_64 -> V_67 ) ;
if ( ( V_69 & V_114 ) != 0 ) {
int V_5 = F_1 ( V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_4 -> V_117 == V_118 )
if ( ! F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) )
F_44 ( V_4 , V_53 , V_61 ) ;
V_55 -> V_73 . V_91 = - V_92 ;
return - V_119 ;
}
V_116 = ( V_114 & V_68 ) ;
V_116 >>= F_11 ( V_68 ) ;
V_77 -= V_116 ;
V_55 -> V_73 . V_91 = V_114 & V_120 ;
if ( ( V_108 & V_55 -> V_73 . V_91 ) ) {
V_55 -> V_73 . V_91 = - V_121 ;
break;
} else if ( ( V_122 & V_55 -> V_73 . V_91 ) ) {
V_55 -> V_73 . V_91 = - V_123 ;
break;
} else if ( ( V_124 & V_55 -> V_73 . V_91 ) ) {
V_55 -> V_73 . V_91 = - V_125 ;
break;
}
if ( V_116 ) {
if ( V_53 -> V_2 ) {
V_55 -> V_73 . V_91 = - V_123 ;
break;
}
}
if ( V_53 -> V_113 )
F_42 ( V_53 ) ;
V_53 -> V_113 = V_61 ;
F_48 ( & V_61 -> V_84 ) ;
}
F_49 ( & V_53 -> V_4 -> V_93 , & V_55 -> V_73 , V_53 -> V_2 ) ;
V_55 -> V_73 . V_77 += V_77 ;
if ( V_55 -> V_73 . V_91 )
return V_55 -> V_73 . V_91 ;
return V_55 -> V_73 . V_77 ;
}
static int F_50 ( struct V_52 * V_53 )
__releases( V_53 -> V_126 )
__acquires( V_53 -> V_126 )
{
struct V_59 * V_61 , * V_115 ;
if ( V_53 == NULL )
return - V_35 ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
while ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
struct V_54 * V_55 = F_33 ( V_53 -> V_100 . V_101 . V_85 ,
struct V_54 , V_101 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_84 ) ;
V_61 -> V_64 = NULL ;
F_30 ( V_61 ) ;
}
F_48 ( & V_55 -> V_101 ) ;
V_55 -> V_73 . V_91 = - V_127 ;
if ( V_55 -> V_73 . V_128 != NULL ) {
F_51 ( V_53 -> V_126 ) ;
F_52 ( & V_53 -> V_74 , & V_55 -> V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
}
}
if ( V_53 -> V_113 )
F_42 ( V_53 ) ;
return 0 ;
}
static int F_54 ( struct V_129 * V_93 )
{
struct V_130 * V_74 ;
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_131 ;
F_56 ( & V_4 -> V_126 , V_131 ) ;
V_4 -> V_93 . V_132 = V_133 ;
V_4 -> V_134 = 0 ;
V_4 -> V_135 = 0 ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
F_58 (ep, gadget) {
F_59 ( V_74 ) ;
}
F_59 ( & V_4 -> V_136 -> V_74 ) ;
F_59 ( & V_4 -> V_137 -> V_74 ) ;
F_58 (ep, gadget) {
F_60 ( V_74 ) ;
}
if ( V_4 -> V_91 != NULL ) {
F_61 ( & V_4 -> V_137 -> V_74 , V_4 -> V_91 ) ;
V_4 -> V_91 = NULL ;
}
return 0 ;
}
static void F_62 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
int V_138 ;
F_51 ( & V_4 -> V_126 ) ;
if ( V_4 -> V_93 . V_132 != V_133 )
F_63 ( & V_4 -> V_93 , V_4 -> V_139 ) ;
V_138 = F_54 ( & V_4 -> V_93 ) ;
if ( V_138 )
goto V_106;
V_138 = F_25 ( V_4 ) ;
if ( V_138 )
goto V_106;
V_4 -> V_91 = F_64 ( & V_4 -> V_137 -> V_74 , V_62 ) ;
if ( V_4 -> V_91 == NULL )
V_138 = - V_63 ;
V_106:
F_53 ( & V_4 -> V_126 ) ;
if ( V_138 )
F_65 ( V_4 -> V_140 , L_1 , V_138 ) ;
}
static void F_66 ( struct V_130 * V_74 , struct V_141 * V_73 )
{
if ( V_74 == NULL || V_73 == NULL )
return;
F_30 ( V_73 -> V_142 ) ;
F_61 ( V_74 , V_73 ) ;
}
static int F_67 ( struct V_130 * V_74 , struct V_141 * V_73 ,
T_3 T_4 V_143 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
int V_138 = 0 ;
if ( V_74 == NULL || V_73 == NULL || V_53 -> V_74 . V_144 == NULL )
return - V_35 ;
if ( V_53 -> type == V_111 ) {
if ( V_73 -> V_56 )
V_53 = ( V_4 -> V_145 == V_30 ) ?
V_4 -> V_136 : V_4 -> V_137 ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_50 ( V_53 ) ;
V_138 = - V_146 ;
F_68 ( V_53 -> V_4 -> V_140 , L_2 ,
F_36 ( V_53 ) ) ;
}
}
if ( F_69 ( V_53 -> V_74 . V_144 ) &&
V_55 -> V_73 . V_56 > ( 1 + V_53 -> V_74 . V_147 ) * V_53 -> V_74 . V_75 ) {
F_65 ( V_53 -> V_4 -> V_140 , L_3 ) ;
return - V_148 ;
}
if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_65 ( V_53 -> V_4 -> V_140 , L_4 ) ;
return - V_119 ;
}
V_55 -> V_73 . V_91 = - V_149 ;
V_55 -> V_73 . V_77 = 0 ;
V_138 = F_37 ( V_53 , V_55 ) ;
if ( V_138 == - V_92 )
V_138 = 0 ;
if ( ! V_138 )
F_35 ( & V_55 -> V_101 , & V_53 -> V_100 . V_101 ) ;
return V_138 ;
}
static int F_70 ( struct V_3 * V_4 ,
struct V_150 * V_151 )
__releases( V_53 -> V_126 )
__acquires( V_53 -> V_126 )
{
struct V_52 * V_53 = V_4 -> V_137 ;
struct V_141 * V_73 = NULL ;
T_3 V_143 = V_62 ;
int V_2 , V_1 , V_138 ;
if ( V_53 == NULL || V_151 == NULL )
return - V_35 ;
F_51 ( V_53 -> V_126 ) ;
V_73 = F_64 ( & V_53 -> V_74 , V_143 ) ;
F_53 ( V_53 -> V_126 ) ;
if ( V_73 == NULL )
return - V_63 ;
V_73 -> V_128 = F_66 ;
V_73 -> V_56 = 2 ;
V_73 -> V_142 = F_28 ( V_73 -> V_56 , V_143 ) ;
if ( V_73 -> V_142 == NULL ) {
V_138 = - V_63 ;
goto V_152;
}
if ( ( V_151 -> V_153 & V_154 ) == V_155 ) {
* ( V_156 * ) V_73 -> V_142 = ( V_4 -> V_134 << 1 ) |
V_4 -> V_93 . V_157 ;
} else if ( ( V_151 -> V_153 & V_154 ) \
== V_158 ) {
V_2 = ( F_71 ( V_151 -> V_159 ) & V_86 ) ?
V_71 : V_30 ;
V_1 = F_71 ( V_151 -> V_159 ) & V_160 ;
* ( V_156 * ) V_73 -> V_142 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_138 = F_67 ( & V_53 -> V_74 , V_73 , V_143 ) ;
if ( V_138 )
goto V_161;
return 0 ;
V_161:
F_30 ( V_73 -> V_142 ) ;
V_152:
F_51 ( V_53 -> V_126 ) ;
F_61 ( & V_53 -> V_74 , V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
return V_138 ;
}
static void
F_72 ( struct V_130 * V_74 , struct V_141 * V_73 )
{
struct V_3 * V_4 = V_73 -> V_162 ;
unsigned long V_131 ;
if ( V_4 -> V_163 ) {
F_24 ( V_4 , V_4 -> V_164 ) ;
V_4 -> V_163 = false ;
if ( V_4 -> V_164 )
F_73 ( & V_4 -> V_93 , V_165 ) ;
}
F_56 ( & V_4 -> V_126 , V_131 ) ;
if ( V_4 -> V_166 )
F_74 ( V_4 , V_4 -> V_166 ) ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
}
static int F_75 ( struct V_3 * V_4 )
{
int V_138 ;
struct V_52 * V_53 ;
V_53 = ( V_4 -> V_145 == V_71 ) ? V_4 -> V_136 : V_4 -> V_137 ;
V_4 -> V_91 -> V_162 = V_4 ;
V_4 -> V_91 -> V_128 = F_72 ;
V_138 = F_67 ( & V_53 -> V_74 , V_4 -> V_91 , V_62 ) ;
return V_138 ;
}
static int F_76 ( struct V_52 * V_53 )
__releases( V_53 -> V_126 )
__acquires( V_53 -> V_126 )
{
struct V_54 * V_55 , * V_167 ;
struct V_52 * V_168 = V_53 ;
int V_138 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_138 = F_45 ( V_53 , V_55 ) ;
if ( V_138 < 0 )
break;
F_48 ( & V_55 -> V_101 ) ;
if ( V_55 -> V_73 . V_128 != NULL ) {
F_51 ( V_53 -> V_126 ) ;
if ( ( V_53 -> type == V_111 ) &&
V_55 -> V_73 . V_56 )
V_168 = V_53 -> V_4 -> V_137 ;
F_52 ( & V_168 -> V_74 , & V_55 -> V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
}
}
if ( V_138 == - V_119 )
V_138 = 0 ;
return V_138 ;
}
static int F_77 ( struct V_3 * V_4 )
{
F_68 ( & V_4 -> V_93 . V_140 ,
L_5 ) ;
return F_75 ( V_4 ) ;
}
static void F_78 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
struct V_52 * V_53 = & V_4 -> V_52 [ 0 ] ;
struct V_150 V_73 ;
int type , V_1 , V_2 , V_169 = - V_35 ;
T_2 V_170 = 0 ;
F_50 ( V_4 -> V_136 ) ;
F_50 ( V_4 -> V_137 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_73 , & V_53 -> V_100 . V_64 -> V_151 , sizeof( V_73 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_73 . V_153 ;
V_4 -> V_145 = ( type & V_171 ) ? V_71 : V_30 ;
switch ( V_73 . V_172 ) {
case V_173 :
if ( type == ( V_174 | V_158 ) &&
F_71 ( V_73 . V_175 ) ==
V_176 ) {
if ( V_73 . V_177 != 0 )
break;
V_1 = F_71 ( V_73 . V_159 ) ;
V_2 = V_1 & V_86 ;
V_1 &= V_160 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_52 [ V_1 ] . V_178 ) {
F_51 ( & V_4 -> V_126 ) ;
V_169 = F_79 (
& V_4 -> V_52 [ V_1 ] . V_74 ) ;
F_53 ( & V_4 -> V_126 ) ;
if ( V_169 )
break;
}
V_169 = F_75 ( V_4 ) ;
} else if ( type == ( V_174 | V_155 ) &&
F_71 ( V_73 . V_175 ) ==
V_179 ) {
if ( V_73 . V_177 != 0 )
break;
V_4 -> V_134 = 0 ;
V_169 = F_75 ( V_4 ) ;
} else {
goto V_180;
}
break;
case V_181 :
if ( type != ( V_171 | V_155 ) &&
type != ( V_171 | V_158 ) &&
type != ( V_171 | V_182 ) )
goto V_180;
if ( F_71 ( V_73 . V_177 ) != 2 ||
F_71 ( V_73 . V_175 ) != 0 )
break;
V_169 = F_70 ( V_4 , & V_73 ) ;
break;
case V_183 :
if ( type != ( V_174 | V_155 ) )
goto V_180;
if ( F_71 ( V_73 . V_177 ) != 0 ||
F_71 ( V_73 . V_159 ) != 0 )
break;
V_4 -> V_164 = ( T_2 ) F_71 ( V_73 . V_175 ) ;
V_4 -> V_163 = true ;
V_169 = F_75 ( V_4 ) ;
break;
case V_184 :
if ( type == ( V_174 | V_158 ) &&
F_71 ( V_73 . V_175 ) ==
V_176 ) {
if ( V_73 . V_177 != 0 )
break;
V_1 = F_71 ( V_73 . V_159 ) ;
V_2 = V_1 & V_86 ;
V_1 &= V_160 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_51 ( & V_4 -> V_126 ) ;
V_169 = F_80 ( & V_4 -> V_52 [ V_1 ] . V_74 ) ;
F_53 ( & V_4 -> V_126 ) ;
if ( ! V_169 )
F_75 ( V_4 ) ;
} else if ( type == ( V_174 | V_155 ) ) {
if ( V_73 . V_177 != 0 )
break;
switch ( F_71 ( V_73 . V_175 ) ) {
case V_179 :
V_4 -> V_134 = 1 ;
V_169 = F_75 ( V_4 ) ;
break;
case V_185 :
V_170 = F_71 ( V_73 . V_159 ) >> 8 ;
switch ( V_170 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
V_4 -> V_166 = V_170 ;
V_169 = F_75 (
V_4 ) ;
break;
default:
break;
}
break;
case V_191 :
if ( F_81 ( V_4 ) ) {
V_4 -> V_93 . V_192 = 1 ;
V_169 = F_75 (
V_4 ) ;
}
break;
case V_193 :
if ( F_81 ( V_4 ) )
V_169 = F_77 ( V_4 ) ;
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
if ( V_73 . V_177 == 0 )
V_4 -> V_145 = V_71 ;
F_51 ( & V_4 -> V_126 ) ;
V_169 = V_4 -> V_139 -> V_151 ( & V_4 -> V_93 , & V_73 ) ;
F_53 ( & V_4 -> V_126 ) ;
break;
}
if ( V_169 < 0 ) {
F_51 ( & V_4 -> V_126 ) ;
if ( F_80 ( & V_53 -> V_74 ) )
F_65 ( V_4 -> V_140 , L_6 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
static void F_82 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
unsigned V_57 ;
int V_169 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_74 . V_144 == NULL )
continue;
if ( F_16 ( V_4 , V_57 ) ) {
V_169 = F_76 ( V_53 ) ;
if ( V_53 -> type == V_111 ) {
if ( V_169 > 0 )
V_169 = F_75 ( V_4 ) ;
if ( V_169 < 0 ) {
F_51 ( & V_4 -> V_126 ) ;
if ( F_80 ( & V_53 -> V_74 ) )
F_65 ( V_4 -> V_140 ,
L_6 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
}
if ( V_57 == 0 &&
F_17 ( V_4 , V_31 , F_6 ( 0 ) ) )
F_78 ( V_4 ) ;
}
}
static int F_83 ( struct V_130 * V_74 ,
const struct V_194 * V_144 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_138 = 0 ;
unsigned long V_131 ;
T_1 V_109 = 0 ;
if ( V_74 == NULL || V_144 == NULL )
return - V_35 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_68 ( V_53 -> V_4 -> V_140 , L_7 ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return - V_119 ;
}
V_53 -> V_74 . V_144 = V_144 ;
V_53 -> V_2 = F_84 ( V_144 ) ? V_71 : V_30 ;
V_53 -> V_1 = F_85 ( V_144 ) ;
V_53 -> type = F_86 ( V_144 ) ;
V_53 -> V_74 . V_75 = F_87 ( V_144 ) & 0x07ff ;
V_53 -> V_74 . V_147 = F_88 ( F_87 ( V_144 ) ) ;
if ( V_53 -> type == V_111 )
V_109 |= V_195 ;
V_109 |= V_196 ;
V_109 |= ( V_53 -> V_74 . V_75 << F_11 ( V_197 ) ) & V_197 ;
if ( V_53 -> type == V_70 && V_53 -> V_2 == V_71 )
V_109 |= 3 << F_11 ( V_110 ) ;
V_53 -> V_100 . V_64 -> V_109 = F_31 ( V_109 ) ;
V_53 -> V_100 . V_64 -> V_84 . V_85 |= F_31 ( V_97 ) ;
if ( V_53 -> V_1 != 0 && V_53 -> type == V_111 ) {
F_65 ( V_53 -> V_4 -> V_140 , L_8 ) ;
V_138 = - V_35 ;
}
if ( V_53 -> V_1 )
V_138 |= F_10 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return V_138 ;
}
static int F_89 ( struct V_130 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_198 , V_138 = 0 ;
unsigned long V_131 ;
if ( V_74 == NULL )
return - V_35 ;
else if ( V_53 -> V_74 . V_144 == NULL )
return - V_119 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
V_198 = V_53 -> V_2 ;
do {
V_138 |= F_50 ( V_53 ) ;
V_138 |= F_9 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_53 -> type == V_111 )
V_53 -> V_2 = ( V_53 -> V_2 == V_71 ) ? V_30 : V_71 ;
} while ( V_53 -> V_2 != V_198 );
V_53 -> V_74 . V_144 = NULL ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return V_138 ;
}
static struct V_141 * F_90 ( struct V_130 * V_74 , T_3 V_143 )
{
struct V_54 * V_55 = NULL ;
if ( V_74 == NULL )
return NULL ;
V_55 = F_28 ( sizeof( struct V_54 ) , V_143 ) ;
if ( V_55 != NULL ) {
F_34 ( & V_55 -> V_101 ) ;
F_34 ( & V_55 -> V_82 ) ;
}
return ( V_55 == NULL ) ? NULL : & V_55 -> V_73 ;
}
static void F_91 ( struct V_130 * V_74 , struct V_141 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
struct V_59 * V_61 , * V_115 ;
unsigned long V_131 ;
if ( V_74 == NULL || V_73 == NULL ) {
return;
} else if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_65 ( V_53 -> V_4 -> V_140 , L_9 ) ;
return;
}
F_56 ( V_53 -> V_126 , V_131 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_84 ) ;
V_61 -> V_64 = NULL ;
F_30 ( V_61 ) ;
}
F_30 ( V_55 ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
}
static int F_92 ( struct V_130 * V_74 , struct V_141 * V_73 ,
T_3 T_4 V_143 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_138 = 0 ;
unsigned long V_131 ;
if ( V_74 == NULL || V_73 == NULL || V_53 -> V_74 . V_144 == NULL )
return - V_35 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
V_138 = F_67 ( V_74 , V_73 , V_143 ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return V_138 ;
}
static int F_93 ( struct V_130 * V_74 , struct V_141 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
unsigned long V_131 ;
struct V_59 * V_61 , * V_115 ;
if ( V_74 == NULL || V_73 == NULL || V_55 -> V_73 . V_91 != - V_92 ||
V_53 -> V_74 . V_144 == NULL || F_32 ( & V_55 -> V_101 ) ||
F_32 ( & V_53 -> V_100 . V_101 ) )
return - V_35 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_94 ( & V_61 -> V_84 ) ;
F_30 ( V_61 ) ;
}
F_48 ( & V_55 -> V_101 ) ;
F_49 ( & V_53 -> V_4 -> V_93 , V_73 , V_53 -> V_2 ) ;
V_73 -> V_91 = - V_199 ;
if ( V_55 -> V_73 . V_128 != NULL ) {
F_51 ( V_53 -> V_126 ) ;
F_52 ( & V_53 -> V_74 , & V_55 -> V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
}
F_57 ( V_53 -> V_126 , V_131 ) ;
return 0 ;
}
static int F_95 ( struct V_130 * V_74 , int V_34 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_198 , V_138 = 0 ;
unsigned long V_131 ;
if ( V_74 == NULL || V_53 -> V_74 . V_144 == NULL )
return - V_35 ;
if ( F_69 ( V_53 -> V_74 . V_144 ) )
return - V_200 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
#ifndef F_96
if ( V_34 && V_53 -> type == V_201 && V_53 -> V_2 == V_71 &&
! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_57 ( V_53 -> V_126 , V_131 ) ;
return - V_32 ;
}
#endif
V_198 = V_53 -> V_2 ;
do {
V_138 |= F_14 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_53 -> V_178 = 0 ;
if ( V_53 -> type == V_111 )
V_53 -> V_2 = ( V_53 -> V_2 == V_71 ) ? V_30 : V_71 ;
} while ( V_53 -> V_2 != V_198 );
F_57 ( V_53 -> V_126 , V_131 ) ;
return V_138 ;
}
static int F_97 ( struct V_130 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
unsigned long V_131 ;
if ( V_74 == NULL || V_53 -> V_74 . V_144 == NULL )
return - V_35 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
V_53 -> V_178 = 1 ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return F_80 ( V_74 ) ;
}
static void F_98 ( struct V_130 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
unsigned long V_131 ;
if ( V_74 == NULL ) {
F_65 ( V_53 -> V_4 -> V_140 , L_10 , F_36 ( V_53 ) ) ;
return;
}
F_56 ( V_53 -> V_126 , V_131 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
}
static int F_99 ( struct V_129 * V_202 , int V_203 )
{
struct V_3 * V_4 = F_55 ( V_202 , struct V_3 , V_93 ) ;
unsigned long V_131 ;
int V_204 = 0 ;
F_56 ( & V_4 -> V_126 , V_131 ) ;
V_4 -> V_205 = V_203 ;
if ( V_4 -> V_139 )
V_204 = 1 ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
if ( V_204 ) {
if ( V_203 ) {
F_100 ( & V_202 -> V_140 ) ;
F_101 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_136 -> V_100 . V_8 ) ;
F_73 ( V_202 , V_206 ) ;
F_102 ( V_202 , true ) ;
} else {
F_102 ( V_202 , false ) ;
if ( V_4 -> V_139 )
V_4 -> V_139 -> V_207 ( & V_4 -> V_93 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_208 -> V_209 )
V_4 -> V_208 -> V_209 ( V_4 ,
V_210 ) ;
F_54 ( & V_4 -> V_93 ) ;
F_103 ( & V_202 -> V_140 ) ;
F_73 ( V_202 , V_211 ) ;
}
}
return 0 ;
}
static int F_104 ( struct V_129 * V_202 )
{
struct V_3 * V_4 = F_55 ( V_202 , struct V_3 , V_93 ) ;
unsigned long V_131 ;
int V_87 = 0 ;
F_56 ( & V_4 -> V_126 , V_131 ) ;
if ( ! V_4 -> V_134 ) {
V_87 = - V_200 ;
goto V_212;
}
if ( ! F_7 ( V_4 , V_44 , V_213 ) ) {
V_87 = - V_35 ;
goto V_212;
}
F_4 ( V_4 , V_44 , V_214 , V_214 ) ;
V_212:
F_57 ( & V_4 -> V_126 , V_131 ) ;
return V_87 ;
}
static int F_105 ( struct V_129 * V_202 , unsigned V_215 )
{
struct V_3 * V_4 = F_55 ( V_202 , struct V_3 , V_93 ) ;
if ( V_4 -> V_216 )
return F_106 ( V_4 -> V_216 , V_215 ) ;
return - V_217 ;
}
static int F_107 ( struct V_129 * V_202 , int V_218 )
{
struct V_3 * V_4 = F_55 ( V_202 , struct V_3 , V_93 ) ;
struct V_52 * V_53 = V_4 -> V_137 ;
unsigned long V_131 ;
F_56 ( V_53 -> V_126 , V_131 ) ;
V_202 -> V_157 = ( V_218 != 0 ) ;
F_57 ( V_53 -> V_126 , V_131 ) ;
return 0 ;
}
static int F_108 ( struct V_129 * V_202 , int V_218 )
{
struct V_3 * V_4 = F_55 ( V_202 , struct V_3 , V_93 ) ;
if ( F_81 ( V_4 ) )
return 0 ;
F_100 ( & V_4 -> V_93 . V_140 ) ;
if ( V_218 )
F_4 ( V_4 , V_48 , V_219 , V_219 ) ;
else
F_4 ( V_4 , V_48 , V_219 , 0 ) ;
F_103 ( & V_4 -> V_93 . V_140 ) ;
return 0 ;
}
static int F_109 ( struct V_3 * V_4 )
{
int V_138 = 0 , V_57 , V_220 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 / 2 ; V_57 ++ )
for ( V_220 = V_30 ; V_220 <= V_71 ; V_220 ++ ) {
int V_221 = V_57 + V_220 * V_4 -> V_7 / 2 ;
struct V_52 * V_53 = & V_4 -> V_52 [ V_221 ] ;
F_110 ( V_53 -> V_222 , sizeof( V_53 -> V_222 ) , L_11 , V_57 ,
( V_220 == V_71 ) ? L_12 : L_13 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_126 = & V_4 -> V_126 ;
V_53 -> V_65 = V_4 -> V_65 ;
V_53 -> V_74 . V_222 = V_53 -> V_222 ;
V_53 -> V_74 . V_223 = & V_224 ;
F_111 ( & V_53 -> V_74 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_53 -> V_100 . V_101 ) ;
V_53 -> V_100 . V_64 = F_29 ( V_4 -> V_225 , V_226 ,
& V_53 -> V_100 . V_8 ) ;
if ( V_53 -> V_100 . V_64 == NULL )
V_138 = - V_63 ;
else
memset ( V_53 -> V_100 . V_64 , 0 , sizeof( * V_53 -> V_100 . V_64 ) ) ;
if ( V_57 == 0 ) {
if ( V_220 == V_30 )
V_4 -> V_136 = V_53 ;
else
V_4 -> V_137 = V_53 ;
F_111 ( & V_53 -> V_74 , V_227 ) ;
continue;
}
F_35 ( & V_53 -> V_74 . V_228 , & V_4 -> V_93 . V_228 ) ;
}
return V_138 ;
}
static void F_112 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_113 )
F_42 ( V_53 ) ;
F_43 ( V_4 -> V_225 , V_53 -> V_100 . V_64 , V_53 -> V_100 . V_8 ) ;
}
}
static int F_113 ( struct V_129 * V_93 ,
struct V_229 * V_139 )
{
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_131 ;
int V_138 = - V_63 ;
if ( V_139 -> V_207 == NULL )
return - V_35 ;
V_4 -> V_136 -> V_74 . V_144 = & V_230 ;
V_138 = F_114 ( & V_4 -> V_136 -> V_74 ) ;
if ( V_138 )
return V_138 ;
V_4 -> V_137 -> V_74 . V_144 = & V_231 ;
V_138 = F_114 ( & V_4 -> V_137 -> V_74 ) ;
if ( V_138 )
return V_138 ;
V_4 -> V_139 = V_139 ;
if ( F_81 ( V_4 ) && V_4 -> V_232 . V_233 ) {
F_115 ( V_4 ) ;
return V_138 ;
}
F_100 ( & V_4 -> V_93 . V_140 ) ;
if ( V_4 -> V_205 ) {
F_56 ( & V_4 -> V_126 , V_131 ) ;
F_101 ( V_4 ) ;
} else {
F_102 ( & V_4 -> V_93 , false ) ;
F_103 ( & V_4 -> V_93 . V_140 ) ;
return V_138 ;
}
V_138 = F_3 ( V_4 , V_4 -> V_136 -> V_100 . V_8 ) ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
if ( V_138 )
F_103 ( & V_4 -> V_93 . V_140 ) ;
return V_138 ;
}
static int F_116 ( struct V_129 * V_93 )
{
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_131 ;
F_56 ( & V_4 -> V_126 , V_131 ) ;
if ( V_4 -> V_205 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_208 -> V_209 )
V_4 -> V_208 -> V_209 ( V_4 ,
V_210 ) ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
F_54 ( & V_4 -> V_93 ) ;
F_56 ( & V_4 -> V_126 , V_131 ) ;
F_117 ( & V_4 -> V_93 . V_140 ) ;
}
V_4 -> V_139 = NULL ;
F_57 ( & V_4 -> V_126 , V_131 ) ;
return 0 ;
}
static T_5 F_118 ( struct V_3 * V_4 )
{
T_5 V_138 ;
T_1 V_234 ;
if ( V_4 == NULL )
return V_235 ;
F_53 ( & V_4 -> V_126 ) ;
if ( V_4 -> V_208 -> V_131 & V_236 ) {
if ( F_7 ( V_4 , V_237 , V_238 ) !=
V_239 ) {
F_51 ( & V_4 -> V_126 ) ;
return V_240 ;
}
}
V_234 = F_18 ( V_4 ) ;
if ( V_234 ) {
if ( V_14 & V_234 )
F_62 ( V_4 ) ;
if ( V_13 & V_234 ) {
V_4 -> V_93 . V_132 = F_15 ( V_4 ) ?
V_241 : V_242 ;
if ( V_4 -> V_135 && V_4 -> V_139 -> V_243 ) {
F_51 ( & V_4 -> V_126 ) ;
V_4 -> V_139 -> V_243 ( & V_4 -> V_93 ) ;
F_53 ( & V_4 -> V_126 ) ;
V_4 -> V_135 = 0 ;
}
}
if ( V_11 & V_234 )
F_82 ( V_4 ) ;
if ( V_15 & V_234 ) {
if ( V_4 -> V_93 . V_132 != V_133 &&
V_4 -> V_139 -> V_244 ) {
V_4 -> V_135 = 1 ;
F_51 ( & V_4 -> V_126 ) ;
V_4 -> V_139 -> V_244 ( & V_4 -> V_93 ) ;
F_73 ( & V_4 -> V_93 ,
V_245 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
V_138 = V_235 ;
} else {
V_138 = V_240 ;
}
F_51 ( & V_4 -> V_126 ) ;
return V_138 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_246 * V_140 = V_4 -> V_140 ;
int V_138 = 0 ;
F_120 ( & V_4 -> V_126 ) ;
V_4 -> V_93 . V_223 = & V_247 ;
V_4 -> V_93 . V_132 = V_133 ;
V_4 -> V_93 . V_248 = V_241 ;
V_4 -> V_93 . V_249 = V_4 -> V_249 ? 1 : 0 ;
V_4 -> V_93 . V_222 = V_4 -> V_208 -> V_222 ;
F_34 ( & V_4 -> V_93 . V_228 ) ;
V_4 -> V_225 = F_121 ( L_14 , V_140 ,
sizeof( struct V_250 ) ,
64 , V_80 ) ;
if ( V_4 -> V_225 == NULL )
return - V_63 ;
V_4 -> V_65 = F_121 ( L_15 , V_140 ,
sizeof( struct V_66 ) ,
64 , V_80 ) ;
if ( V_4 -> V_65 == NULL ) {
V_138 = - V_63 ;
goto V_251;
}
V_138 = F_109 ( V_4 ) ;
if ( V_138 )
goto V_252;
V_4 -> V_93 . V_253 = & V_4 -> V_137 -> V_74 ;
V_138 = F_122 ( V_140 , & V_4 -> V_93 ) ;
if ( V_138 )
goto F_112;
F_123 ( & V_4 -> V_93 . V_140 ) ;
F_124 ( & V_4 -> V_93 . V_140 ) ;
return V_138 ;
F_112:
F_112 ( V_4 ) ;
V_252:
F_125 ( V_4 -> V_65 ) ;
V_251:
F_125 ( V_4 -> V_225 ) ;
return V_138 ;
}
void F_126 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_254 [ V_255 ] )
return;
F_127 ( & V_4 -> V_93 ) ;
F_112 ( V_4 ) ;
F_125 ( V_4 -> V_65 ) ;
F_125 ( V_4 -> V_225 ) ;
}
static int F_128 ( struct V_3 * V_4 )
{
if ( V_4 -> V_249 )
F_129 ( V_4 , V_256 | V_257 ,
V_256 | V_257 ) ;
return 0 ;
}
static void F_130 ( struct V_3 * V_4 )
{
if ( V_4 -> V_249 )
F_129 ( V_4 , V_257 | V_256 , V_256 ) ;
}
int F_131 ( struct V_3 * V_4 )
{
struct V_258 * V_259 ;
if ( ! F_7 ( V_4 , V_260 , V_261 ) )
return - V_262 ;
V_259 = F_132 ( V_4 -> V_140 , sizeof( struct V_258 ) , V_226 ) ;
if ( ! V_259 )
return - V_63 ;
V_259 -> V_263 = F_128 ;
V_259 -> V_264 = F_130 ;
V_259 -> V_265 = F_118 ;
V_259 -> V_222 = L_16 ;
V_4 -> V_254 [ V_255 ] = V_259 ;
return F_119 ( V_4 ) ;
}
