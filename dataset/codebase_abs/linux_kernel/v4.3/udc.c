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
if ( V_55 -> V_73 . V_96 && V_55 -> V_73 . V_56 && V_53 -> V_2 == V_71
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
static int F_54 ( struct V_129 * V_74 , int V_34 , bool V_130 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_131 , V_132 = 0 ;
unsigned long V_133 ;
if ( V_74 == NULL || V_53 -> V_74 . V_134 == NULL )
return - V_35 ;
if ( F_56 ( V_53 -> V_74 . V_134 ) )
return - V_135 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
if ( V_34 && V_53 -> V_2 == V_71 && V_130 &&
! F_32 ( & V_53 -> V_100 . V_101 ) &&
! F_58 ( V_53 -> V_74 . V_134 ) ) {
F_59 ( V_53 -> V_126 , V_133 ) ;
return - V_32 ;
}
V_131 = V_53 -> V_2 ;
do {
V_132 |= F_14 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_53 -> V_136 = 0 ;
if ( V_53 -> type == V_111 )
V_53 -> V_2 = ( V_53 -> V_2 == V_71 ) ? V_30 : V_71 ;
} while ( V_53 -> V_2 != V_131 );
F_59 ( V_53 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_60 ( struct V_137 * V_93 )
{
struct V_129 * V_74 ;
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_133 ;
F_57 ( & V_4 -> V_126 , V_133 ) ;
V_4 -> V_93 . V_138 = V_139 ;
V_4 -> V_140 = 0 ;
V_4 -> V_141 = 0 ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
F_61 (ep, gadget) {
F_62 ( V_74 ) ;
}
F_62 ( & V_4 -> V_142 -> V_74 ) ;
F_62 ( & V_4 -> V_143 -> V_74 ) ;
F_61 (ep, gadget) {
F_63 ( V_74 ) ;
}
if ( V_4 -> V_91 != NULL ) {
F_64 ( & V_4 -> V_143 -> V_74 , V_4 -> V_91 ) ;
V_4 -> V_91 = NULL ;
}
return 0 ;
}
static void F_65 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
int V_132 ;
F_51 ( & V_4 -> V_126 ) ;
if ( V_4 -> V_93 . V_138 != V_139 )
F_66 ( & V_4 -> V_93 , V_4 -> V_144 ) ;
V_132 = F_60 ( & V_4 -> V_93 ) ;
if ( V_132 )
goto V_106;
V_132 = F_25 ( V_4 ) ;
if ( V_132 )
goto V_106;
V_4 -> V_91 = F_67 ( & V_4 -> V_143 -> V_74 , V_62 ) ;
if ( V_4 -> V_91 == NULL )
V_132 = - V_63 ;
V_106:
F_53 ( & V_4 -> V_126 ) ;
if ( V_132 )
F_68 ( V_4 -> V_145 , L_1 , V_132 ) ;
}
static void F_69 ( struct V_129 * V_74 , struct V_146 * V_73 )
{
if ( V_74 == NULL || V_73 == NULL )
return;
F_30 ( V_73 -> V_147 ) ;
F_64 ( V_74 , V_73 ) ;
}
static int F_70 ( struct V_129 * V_74 , struct V_146 * V_73 ,
T_3 T_4 V_148 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
int V_132 = 0 ;
if ( V_74 == NULL || V_73 == NULL || V_53 -> V_74 . V_134 == NULL )
return - V_35 ;
if ( V_53 -> type == V_111 ) {
if ( V_73 -> V_56 )
V_53 = ( V_4 -> V_149 == V_30 ) ?
V_4 -> V_142 : V_4 -> V_143 ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_50 ( V_53 ) ;
V_132 = - V_150 ;
F_71 ( V_53 -> V_4 -> V_145 , L_2 ,
F_36 ( V_53 ) ) ;
}
}
if ( F_56 ( V_53 -> V_74 . V_134 ) &&
V_55 -> V_73 . V_56 > ( 1 + V_53 -> V_74 . V_151 ) * V_53 -> V_74 . V_75 ) {
F_68 ( V_53 -> V_4 -> V_145 , L_3 ) ;
return - V_152 ;
}
if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_68 ( V_53 -> V_4 -> V_145 , L_4 ) ;
return - V_119 ;
}
V_55 -> V_73 . V_91 = - V_153 ;
V_55 -> V_73 . V_77 = 0 ;
V_132 = F_37 ( V_53 , V_55 ) ;
if ( V_132 == - V_92 )
V_132 = 0 ;
if ( ! V_132 )
F_35 ( & V_55 -> V_101 , & V_53 -> V_100 . V_101 ) ;
return V_132 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_154 * V_155 )
__releases( V_53 -> V_126 )
__acquires( V_53 -> V_126 )
{
struct V_52 * V_53 = V_4 -> V_143 ;
struct V_146 * V_73 = NULL ;
T_3 V_148 = V_62 ;
int V_2 , V_1 , V_132 ;
if ( V_53 == NULL || V_155 == NULL )
return - V_35 ;
F_51 ( V_53 -> V_126 ) ;
V_73 = F_67 ( & V_53 -> V_74 , V_148 ) ;
F_53 ( V_53 -> V_126 ) ;
if ( V_73 == NULL )
return - V_63 ;
V_73 -> V_128 = F_69 ;
V_73 -> V_56 = 2 ;
V_73 -> V_147 = F_28 ( V_73 -> V_56 , V_148 ) ;
if ( V_73 -> V_147 == NULL ) {
V_132 = - V_63 ;
goto V_156;
}
if ( ( V_155 -> V_157 & V_158 ) == V_159 ) {
* ( V_160 * ) V_73 -> V_147 = ( V_4 -> V_140 << 1 ) |
V_4 -> V_93 . V_161 ;
} else if ( ( V_155 -> V_157 & V_158 ) \
== V_162 ) {
V_2 = ( F_73 ( V_155 -> V_163 ) & V_86 ) ?
V_71 : V_30 ;
V_1 = F_73 ( V_155 -> V_163 ) & V_164 ;
* ( V_160 * ) V_73 -> V_147 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_132 = F_70 ( & V_53 -> V_74 , V_73 , V_148 ) ;
if ( V_132 )
goto V_165;
return 0 ;
V_165:
F_30 ( V_73 -> V_147 ) ;
V_156:
F_51 ( V_53 -> V_126 ) ;
F_64 ( & V_53 -> V_74 , V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
return V_132 ;
}
static void
F_74 ( struct V_129 * V_74 , struct V_146 * V_73 )
{
struct V_3 * V_4 = V_73 -> V_166 ;
unsigned long V_133 ;
if ( V_4 -> V_167 ) {
F_24 ( V_4 , V_4 -> V_168 ) ;
V_4 -> V_167 = false ;
if ( V_4 -> V_168 )
F_75 ( & V_4 -> V_93 , V_169 ) ;
}
F_57 ( & V_4 -> V_126 , V_133 ) ;
if ( V_4 -> V_170 )
F_76 ( V_4 , V_4 -> V_170 ) ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
int V_132 ;
struct V_52 * V_53 ;
V_53 = ( V_4 -> V_149 == V_71 ) ? V_4 -> V_142 : V_4 -> V_143 ;
V_4 -> V_91 -> V_166 = V_4 ;
V_4 -> V_91 -> V_128 = F_74 ;
V_132 = F_70 ( & V_53 -> V_74 , V_4 -> V_91 , V_62 ) ;
return V_132 ;
}
static int F_78 ( struct V_52 * V_53 )
__releases( V_53 -> V_126 )
__acquires( V_53 -> V_126 )
{
struct V_54 * V_55 , * V_171 ;
struct V_52 * V_172 = V_53 ;
int V_132 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_132 = F_45 ( V_53 , V_55 ) ;
if ( V_132 < 0 )
break;
F_48 ( & V_55 -> V_101 ) ;
if ( V_55 -> V_73 . V_128 != NULL ) {
F_51 ( V_53 -> V_126 ) ;
if ( ( V_53 -> type == V_111 ) &&
V_55 -> V_73 . V_56 )
V_172 = V_53 -> V_4 -> V_143 ;
F_52 ( & V_172 -> V_74 , & V_55 -> V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
}
}
if ( V_132 == - V_119 )
V_132 = 0 ;
return V_132 ;
}
static int F_79 ( struct V_3 * V_4 )
{
F_71 ( & V_4 -> V_93 . V_145 ,
L_5 ) ;
return F_77 ( V_4 ) ;
}
static void F_80 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
struct V_52 * V_53 = & V_4 -> V_52 [ 0 ] ;
struct V_154 V_73 ;
int type , V_1 , V_2 , V_173 = - V_35 ;
T_2 V_174 = 0 ;
F_50 ( V_4 -> V_142 ) ;
F_50 ( V_4 -> V_143 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_73 , & V_53 -> V_100 . V_64 -> V_155 , sizeof( V_73 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_73 . V_157 ;
V_4 -> V_149 = ( type & V_175 ) ? V_71 : V_30 ;
switch ( V_73 . V_176 ) {
case V_177 :
if ( type == ( V_178 | V_162 ) &&
F_73 ( V_73 . V_179 ) ==
V_180 ) {
if ( V_73 . V_181 != 0 )
break;
V_1 = F_73 ( V_73 . V_163 ) ;
V_2 = V_1 & V_86 ;
V_1 &= V_164 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_52 [ V_1 ] . V_136 ) {
F_51 ( & V_4 -> V_126 ) ;
V_173 = F_81 (
& V_4 -> V_52 [ V_1 ] . V_74 ) ;
F_53 ( & V_4 -> V_126 ) ;
if ( V_173 )
break;
}
V_173 = F_77 ( V_4 ) ;
} else if ( type == ( V_178 | V_159 ) &&
F_73 ( V_73 . V_179 ) ==
V_182 ) {
if ( V_73 . V_181 != 0 )
break;
V_4 -> V_140 = 0 ;
V_173 = F_77 ( V_4 ) ;
} else {
goto V_183;
}
break;
case V_184 :
if ( type != ( V_175 | V_159 ) &&
type != ( V_175 | V_162 ) &&
type != ( V_175 | V_185 ) )
goto V_183;
if ( F_73 ( V_73 . V_181 ) != 2 ||
F_73 ( V_73 . V_179 ) != 0 )
break;
V_173 = F_72 ( V_4 , & V_73 ) ;
break;
case V_186 :
if ( type != ( V_178 | V_159 ) )
goto V_183;
if ( F_73 ( V_73 . V_181 ) != 0 ||
F_73 ( V_73 . V_163 ) != 0 )
break;
V_4 -> V_168 = ( T_2 ) F_73 ( V_73 . V_179 ) ;
V_4 -> V_167 = true ;
V_173 = F_77 ( V_4 ) ;
break;
case V_187 :
if ( type == ( V_178 | V_162 ) &&
F_73 ( V_73 . V_179 ) ==
V_180 ) {
if ( V_73 . V_181 != 0 )
break;
V_1 = F_73 ( V_73 . V_163 ) ;
V_2 = V_1 & V_86 ;
V_1 &= V_164 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_51 ( & V_4 -> V_126 ) ;
V_173 = F_54 ( & V_4 -> V_52 [ V_1 ] . V_74 , 1 , false ) ;
F_53 ( & V_4 -> V_126 ) ;
if ( ! V_173 )
F_77 ( V_4 ) ;
} else if ( type == ( V_178 | V_159 ) ) {
if ( V_73 . V_181 != 0 )
break;
switch ( F_73 ( V_73 . V_179 ) ) {
case V_182 :
V_4 -> V_140 = 1 ;
V_173 = F_77 ( V_4 ) ;
break;
case V_188 :
V_174 = F_73 ( V_73 . V_163 ) >> 8 ;
switch ( V_174 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
V_4 -> V_170 = V_174 ;
V_173 = F_77 (
V_4 ) ;
break;
default:
break;
}
break;
case V_194 :
if ( F_82 ( V_4 ) ) {
V_4 -> V_93 . V_195 = 1 ;
V_173 = F_77 (
V_4 ) ;
}
break;
case V_196 :
if ( F_82 ( V_4 ) )
V_173 = F_79 ( V_4 ) ;
break;
case V_197 :
if ( F_82 ( V_4 ) ) {
V_4 -> V_93 . V_198 = 1 ;
V_173 = F_77 (
V_4 ) ;
}
break;
default:
goto V_183;
}
} else {
goto V_183;
}
break;
default:
V_183:
if ( V_73 . V_181 == 0 )
V_4 -> V_149 = V_71 ;
F_51 ( & V_4 -> V_126 ) ;
V_173 = V_4 -> V_144 -> V_155 ( & V_4 -> V_93 , & V_73 ) ;
F_53 ( & V_4 -> V_126 ) ;
break;
}
if ( V_173 < 0 ) {
F_51 ( & V_4 -> V_126 ) ;
if ( F_54 ( & V_53 -> V_74 , 1 , false ) )
F_68 ( V_4 -> V_145 , L_6 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
static void F_83 ( struct V_3 * V_4 )
__releases( V_4 -> V_126 )
__acquires( V_4 -> V_126 )
{
unsigned V_57 ;
int V_173 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_74 . V_134 == NULL )
continue;
if ( F_16 ( V_4 , V_57 ) ) {
V_173 = F_78 ( V_53 ) ;
if ( V_53 -> type == V_111 ) {
if ( V_173 > 0 )
V_173 = F_77 ( V_4 ) ;
if ( V_173 < 0 ) {
F_51 ( & V_4 -> V_126 ) ;
if ( F_54 ( & V_53 -> V_74 , 1 , false ) )
F_68 ( V_4 -> V_145 ,
L_6 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
}
if ( V_57 == 0 &&
F_17 ( V_4 , V_31 , F_6 ( 0 ) ) )
F_80 ( V_4 ) ;
}
}
static int F_84 ( struct V_129 * V_74 ,
const struct V_199 * V_134 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_132 = 0 ;
unsigned long V_133 ;
T_1 V_109 = 0 ;
if ( V_74 == NULL || V_134 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_71 ( V_53 -> V_4 -> V_145 , L_7 ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return - V_119 ;
}
V_53 -> V_74 . V_134 = V_134 ;
V_53 -> V_2 = F_85 ( V_134 ) ? V_71 : V_30 ;
V_53 -> V_1 = F_86 ( V_134 ) ;
V_53 -> type = F_87 ( V_134 ) ;
V_53 -> V_74 . V_75 = F_88 ( V_134 ) & 0x07ff ;
V_53 -> V_74 . V_151 = F_89 ( F_88 ( V_134 ) ) ;
if ( V_53 -> type == V_111 )
V_109 |= V_200 ;
V_109 |= V_201 ;
V_109 |= ( V_53 -> V_74 . V_75 << F_11 ( V_202 ) ) & V_202 ;
if ( V_53 -> type == V_70 && V_53 -> V_2 == V_71 )
V_109 |= 3 << F_11 ( V_110 ) ;
V_53 -> V_100 . V_64 -> V_109 = F_31 ( V_109 ) ;
V_53 -> V_100 . V_64 -> V_84 . V_85 |= F_31 ( V_97 ) ;
if ( V_53 -> V_1 != 0 && V_53 -> type == V_111 ) {
F_68 ( V_53 -> V_4 -> V_145 , L_8 ) ;
V_132 = - V_35 ;
}
if ( V_53 -> V_1 )
V_132 |= F_10 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_90 ( struct V_129 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_131 , V_132 = 0 ;
unsigned long V_133 ;
if ( V_74 == NULL )
return - V_35 ;
else if ( V_53 -> V_74 . V_134 == NULL )
return - V_119 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
V_131 = V_53 -> V_2 ;
do {
V_132 |= F_50 ( V_53 ) ;
V_132 |= F_9 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_53 -> type == V_111 )
V_53 -> V_2 = ( V_53 -> V_2 == V_71 ) ? V_30 : V_71 ;
} while ( V_53 -> V_2 != V_131 );
V_53 -> V_74 . V_134 = NULL ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return V_132 ;
}
static struct V_146 * F_91 ( struct V_129 * V_74 , T_3 V_148 )
{
struct V_54 * V_55 = NULL ;
if ( V_74 == NULL )
return NULL ;
V_55 = F_28 ( sizeof( struct V_54 ) , V_148 ) ;
if ( V_55 != NULL ) {
F_34 ( & V_55 -> V_101 ) ;
F_34 ( & V_55 -> V_82 ) ;
}
return ( V_55 == NULL ) ? NULL : & V_55 -> V_73 ;
}
static void F_92 ( struct V_129 * V_74 , struct V_146 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
struct V_59 * V_61 , * V_115 ;
unsigned long V_133 ;
if ( V_74 == NULL || V_73 == NULL ) {
return;
} else if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_68 ( V_53 -> V_4 -> V_145 , L_9 ) ;
return;
}
F_57 ( V_53 -> V_126 , V_133 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_84 ) ;
V_61 -> V_64 = NULL ;
F_30 ( V_61 ) ;
}
F_30 ( V_55 ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
}
static int F_93 ( struct V_129 * V_74 , struct V_146 * V_73 ,
T_3 T_4 V_148 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
int V_132 = 0 ;
unsigned long V_133 ;
if ( V_74 == NULL || V_73 == NULL || V_53 -> V_74 . V_134 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
V_132 = F_70 ( V_74 , V_73 , V_148 ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_94 ( struct V_129 * V_74 , struct V_146 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
struct V_54 * V_55 = F_55 ( V_73 , struct V_54 , V_73 ) ;
unsigned long V_133 ;
struct V_59 * V_61 , * V_115 ;
if ( V_74 == NULL || V_73 == NULL || V_55 -> V_73 . V_91 != - V_92 ||
V_53 -> V_74 . V_134 == NULL || F_32 ( & V_55 -> V_101 ) ||
F_32 ( & V_53 -> V_100 . V_101 ) )
return - V_35 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_95 ( & V_61 -> V_84 ) ;
F_30 ( V_61 ) ;
}
F_48 ( & V_55 -> V_101 ) ;
F_49 ( & V_53 -> V_4 -> V_93 , V_73 , V_53 -> V_2 ) ;
V_73 -> V_91 = - V_203 ;
if ( V_55 -> V_73 . V_128 != NULL ) {
F_51 ( V_53 -> V_126 ) ;
F_52 ( & V_53 -> V_74 , & V_55 -> V_73 ) ;
F_53 ( V_53 -> V_126 ) ;
}
F_59 ( V_53 -> V_126 , V_133 ) ;
return 0 ;
}
static int F_96 ( struct V_129 * V_74 , int V_34 )
{
return F_54 ( V_74 , V_34 , true ) ;
}
static int F_97 ( struct V_129 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
unsigned long V_133 ;
if ( V_74 == NULL || V_53 -> V_74 . V_134 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
V_53 -> V_136 = 1 ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return F_98 ( V_74 ) ;
}
static void F_99 ( struct V_129 * V_74 )
{
struct V_52 * V_53 = F_55 ( V_74 , struct V_52 , V_74 ) ;
unsigned long V_133 ;
if ( V_74 == NULL ) {
F_68 ( V_53 -> V_4 -> V_145 , L_10 , F_36 ( V_53 ) ) ;
return;
}
F_57 ( V_53 -> V_126 , V_133 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
}
static int F_100 ( struct V_137 * V_204 , int V_205 )
{
struct V_3 * V_4 = F_55 ( V_204 , struct V_3 , V_93 ) ;
unsigned long V_133 ;
int V_206 = 0 ;
F_57 ( & V_4 -> V_126 , V_133 ) ;
V_4 -> V_207 = V_205 ;
if ( V_4 -> V_144 )
V_206 = 1 ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
if ( V_206 ) {
if ( V_205 ) {
F_101 ( & V_204 -> V_145 ) ;
F_102 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_142 -> V_100 . V_8 ) ;
F_75 ( V_204 , V_208 ) ;
F_103 ( V_204 , true ) ;
} else {
F_103 ( V_204 , false ) ;
if ( V_4 -> V_144 )
V_4 -> V_144 -> V_209 ( & V_4 -> V_93 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_210 -> V_211 )
V_4 -> V_210 -> V_211 ( V_4 ,
V_212 ) ;
F_60 ( & V_4 -> V_93 ) ;
F_104 ( & V_204 -> V_145 ) ;
F_75 ( V_204 , V_213 ) ;
}
}
return 0 ;
}
static int F_105 ( struct V_137 * V_204 )
{
struct V_3 * V_4 = F_55 ( V_204 , struct V_3 , V_93 ) ;
unsigned long V_133 ;
int V_87 = 0 ;
F_57 ( & V_4 -> V_126 , V_133 ) ;
if ( ! V_4 -> V_140 ) {
V_87 = - V_135 ;
goto V_214;
}
if ( ! F_7 ( V_4 , V_44 , V_215 ) ) {
V_87 = - V_35 ;
goto V_214;
}
F_4 ( V_4 , V_44 , V_216 , V_216 ) ;
V_214:
F_59 ( & V_4 -> V_126 , V_133 ) ;
return V_87 ;
}
static int F_106 ( struct V_137 * V_204 , unsigned V_217 )
{
struct V_3 * V_4 = F_55 ( V_204 , struct V_3 , V_93 ) ;
if ( V_4 -> V_218 )
return F_107 ( V_4 -> V_218 , V_217 ) ;
return - V_219 ;
}
static int F_108 ( struct V_137 * V_204 , int V_220 )
{
struct V_3 * V_4 = F_55 ( V_204 , struct V_3 , V_93 ) ;
struct V_52 * V_53 = V_4 -> V_143 ;
unsigned long V_133 ;
F_57 ( V_53 -> V_126 , V_133 ) ;
V_204 -> V_161 = ( V_220 != 0 ) ;
F_59 ( V_53 -> V_126 , V_133 ) ;
return 0 ;
}
static int F_109 ( struct V_137 * V_204 , int V_220 )
{
struct V_3 * V_4 = F_55 ( V_204 , struct V_3 , V_93 ) ;
if ( F_82 ( V_4 ) )
return 0 ;
F_101 ( & V_4 -> V_93 . V_145 ) ;
if ( V_220 )
F_4 ( V_4 , V_48 , V_221 , V_221 ) ;
else
F_4 ( V_4 , V_48 , V_221 , 0 ) ;
F_104 ( & V_4 -> V_93 . V_145 ) ;
return 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
int V_132 = 0 , V_57 , V_222 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 / 2 ; V_57 ++ )
for ( V_222 = V_30 ; V_222 <= V_71 ; V_222 ++ ) {
int V_223 = V_57 + V_222 * V_4 -> V_7 / 2 ;
struct V_52 * V_53 = & V_4 -> V_52 [ V_223 ] ;
F_111 ( V_53 -> V_224 , sizeof( V_53 -> V_224 ) , L_11 , V_57 ,
( V_222 == V_71 ) ? L_12 : L_13 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_126 = & V_4 -> V_126 ;
V_53 -> V_65 = V_4 -> V_65 ;
V_53 -> V_74 . V_224 = V_53 -> V_224 ;
V_53 -> V_74 . V_225 = & V_226 ;
if ( V_57 == 0 ) {
V_53 -> V_74 . V_227 . V_228 = true ;
} else {
V_53 -> V_74 . V_227 . V_229 = true ;
V_53 -> V_74 . V_227 . V_230 = true ;
V_53 -> V_74 . V_227 . V_231 = true ;
}
if ( V_222 == V_71 )
V_53 -> V_74 . V_227 . V_232 = true ;
else
V_53 -> V_74 . V_227 . V_233 = true ;
F_112 ( & V_53 -> V_74 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_53 -> V_100 . V_101 ) ;
V_53 -> V_100 . V_64 = F_29 ( V_4 -> V_234 , V_235 ,
& V_53 -> V_100 . V_8 ) ;
if ( V_53 -> V_100 . V_64 == NULL )
V_132 = - V_63 ;
else
memset ( V_53 -> V_100 . V_64 , 0 , sizeof( * V_53 -> V_100 . V_64 ) ) ;
if ( V_57 == 0 ) {
if ( V_222 == V_30 )
V_4 -> V_142 = V_53 ;
else
V_4 -> V_143 = V_53 ;
F_112 ( & V_53 -> V_74 , V_236 ) ;
continue;
}
F_35 ( & V_53 -> V_74 . V_237 , & V_4 -> V_93 . V_237 ) ;
}
return V_132 ;
}
static void F_113 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_113 )
F_42 ( V_53 ) ;
F_43 ( V_4 -> V_234 , V_53 -> V_100 . V_64 , V_53 -> V_100 . V_8 ) ;
}
}
static int F_114 ( struct V_137 * V_93 ,
struct V_238 * V_144 )
{
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_133 ;
int V_132 = - V_63 ;
if ( V_144 -> V_209 == NULL )
return - V_35 ;
V_4 -> V_142 -> V_74 . V_134 = & V_239 ;
V_132 = F_115 ( & V_4 -> V_142 -> V_74 ) ;
if ( V_132 )
return V_132 ;
V_4 -> V_143 -> V_74 . V_134 = & V_240 ;
V_132 = F_115 ( & V_4 -> V_143 -> V_74 ) ;
if ( V_132 )
return V_132 ;
V_4 -> V_144 = V_144 ;
if ( F_82 ( V_4 ) && V_4 -> V_241 . V_242 ) {
F_116 ( V_4 ) ;
return V_132 ;
}
F_101 ( & V_4 -> V_93 . V_145 ) ;
if ( V_4 -> V_207 ) {
F_57 ( & V_4 -> V_126 , V_133 ) ;
F_102 ( V_4 ) ;
} else {
F_103 ( & V_4 -> V_93 , false ) ;
F_104 ( & V_4 -> V_93 . V_145 ) ;
return V_132 ;
}
V_132 = F_3 ( V_4 , V_4 -> V_142 -> V_100 . V_8 ) ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
if ( V_132 )
F_104 ( & V_4 -> V_93 . V_145 ) ;
return V_132 ;
}
static int F_117 ( struct V_137 * V_93 )
{
struct V_3 * V_4 = F_55 ( V_93 , struct V_3 , V_93 ) ;
unsigned long V_133 ;
F_57 ( & V_4 -> V_126 , V_133 ) ;
if ( V_4 -> V_207 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_210 -> V_211 )
V_4 -> V_210 -> V_211 ( V_4 ,
V_212 ) ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
F_60 ( & V_4 -> V_93 ) ;
F_57 ( & V_4 -> V_126 , V_133 ) ;
F_118 ( & V_4 -> V_93 . V_145 ) ;
}
V_4 -> V_144 = NULL ;
F_59 ( & V_4 -> V_126 , V_133 ) ;
return 0 ;
}
static T_5 F_119 ( struct V_3 * V_4 )
{
T_5 V_132 ;
T_1 V_243 ;
if ( V_4 == NULL )
return V_244 ;
F_53 ( & V_4 -> V_126 ) ;
if ( V_4 -> V_210 -> V_133 & V_245 ) {
if ( F_7 ( V_4 , V_246 , V_247 ) !=
V_248 ) {
F_51 ( & V_4 -> V_126 ) ;
return V_249 ;
}
}
V_243 = F_18 ( V_4 ) ;
if ( V_243 ) {
if ( V_14 & V_243 )
F_65 ( V_4 ) ;
if ( V_13 & V_243 ) {
V_4 -> V_93 . V_138 = F_15 ( V_4 ) ?
V_250 : V_251 ;
if ( V_4 -> V_141 && V_4 -> V_144 -> V_252 ) {
F_51 ( & V_4 -> V_126 ) ;
V_4 -> V_144 -> V_252 ( & V_4 -> V_93 ) ;
F_53 ( & V_4 -> V_126 ) ;
V_4 -> V_141 = 0 ;
}
}
if ( V_11 & V_243 )
F_83 ( V_4 ) ;
if ( V_15 & V_243 ) {
if ( V_4 -> V_93 . V_138 != V_139 &&
V_4 -> V_144 -> V_253 ) {
V_4 -> V_141 = 1 ;
F_51 ( & V_4 -> V_126 ) ;
V_4 -> V_144 -> V_253 ( & V_4 -> V_93 ) ;
F_75 ( & V_4 -> V_93 ,
V_254 ) ;
F_53 ( & V_4 -> V_126 ) ;
}
}
V_132 = V_244 ;
} else {
V_132 = V_249 ;
}
F_51 ( & V_4 -> V_126 ) ;
return V_132 ;
}
static int F_120 ( struct V_3 * V_4 )
{
struct V_255 * V_145 = V_4 -> V_145 ;
struct V_256 * V_257 = & V_4 -> V_210 -> V_258 ;
int V_132 = 0 ;
F_121 ( & V_4 -> V_126 ) ;
V_4 -> V_93 . V_225 = & V_259 ;
V_4 -> V_93 . V_138 = V_139 ;
V_4 -> V_93 . V_260 = V_250 ;
V_4 -> V_93 . V_224 = V_4 -> V_210 -> V_224 ;
V_4 -> V_93 . V_257 = V_257 ;
if ( V_4 -> V_261 && ( V_257 -> V_262 || V_257 -> V_263 ||
V_257 -> V_264 ) )
V_4 -> V_93 . V_261 = 1 ;
F_34 ( & V_4 -> V_93 . V_237 ) ;
V_4 -> V_234 = F_122 ( L_14 , V_145 ,
sizeof( struct V_265 ) ,
64 , V_80 ) ;
if ( V_4 -> V_234 == NULL )
return - V_63 ;
V_4 -> V_65 = F_122 ( L_15 , V_145 ,
sizeof( struct V_66 ) ,
64 , V_80 ) ;
if ( V_4 -> V_65 == NULL ) {
V_132 = - V_63 ;
goto V_266;
}
V_132 = F_110 ( V_4 ) ;
if ( V_132 )
goto V_267;
V_4 -> V_93 . V_268 = & V_4 -> V_143 -> V_74 ;
V_132 = F_123 ( V_145 , & V_4 -> V_93 ) ;
if ( V_132 )
goto F_113;
F_124 ( & V_4 -> V_93 . V_145 ) ;
F_125 ( & V_4 -> V_93 . V_145 ) ;
return V_132 ;
F_113:
F_113 ( V_4 ) ;
V_267:
F_126 ( V_4 -> V_65 ) ;
V_266:
F_126 ( V_4 -> V_234 ) ;
return V_132 ;
}
void F_127 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_269 [ V_270 ] )
return;
F_128 ( & V_4 -> V_93 ) ;
F_113 ( V_4 ) ;
F_126 ( V_4 -> V_65 ) ;
F_126 ( V_4 -> V_234 ) ;
}
static int F_129 ( struct V_3 * V_4 )
{
if ( V_4 -> V_261 )
F_130 ( V_4 , V_271 | V_272 ,
V_271 | V_272 ) ;
return 0 ;
}
static void F_131 ( struct V_3 * V_4 )
{
if ( V_4 -> V_261 )
F_130 ( V_4 , V_272 | V_271 , V_271 ) ;
}
int F_132 ( struct V_3 * V_4 )
{
struct V_273 * V_274 ;
if ( ! F_7 ( V_4 , V_275 , V_276 ) )
return - V_277 ;
V_274 = F_133 ( V_4 -> V_145 , sizeof( struct V_273 ) , V_235 ) ;
if ( ! V_274 )
return - V_63 ;
V_274 -> V_278 = F_129 ;
V_274 -> V_279 = F_131 ;
V_274 -> V_280 = F_119 ;
V_274 -> V_224 = L_16 ;
V_4 -> V_269 [ V_270 ] = V_274 ;
return F_120 ( V_4 ) ;
}
