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
V_61 -> V_64 -> V_66 = F_31 ( V_56 << F_11 ( V_67 ) ) ;
V_61 -> V_64 -> V_66 &= F_31 ( V_67 ) ;
V_61 -> V_64 -> V_66 |= F_31 ( V_68 ) ;
if ( V_53 -> type == V_69 && V_53 -> V_2 == V_70 ) {
T_1 V_71 = V_55 -> V_72 . V_56 / V_53 -> V_73 . V_74 ;
if ( V_55 -> V_72 . V_56 == 0
|| V_55 -> V_72 . V_56 % V_53 -> V_73 . V_74 )
V_71 ++ ;
V_61 -> V_64 -> V_66 |= V_71 << F_11 ( V_75 ) ;
}
V_58 = ( T_1 ) ( V_55 -> V_72 . V_8 + V_55 -> V_72 . V_76 ) ;
if ( V_56 ) {
V_61 -> V_64 -> V_77 [ 0 ] = F_31 ( V_58 ) ;
for ( V_57 = 1 ; V_57 < V_78 ; V_57 ++ ) {
T_1 V_77 = V_58 + V_57 * V_79 ;
V_77 &= ~ V_80 ;
V_61 -> V_64 -> V_77 [ V_57 ] = F_31 ( V_77 ) ;
}
}
V_55 -> V_72 . V_76 += V_56 ;
if ( ! F_32 ( & V_55 -> V_81 ) ) {
V_60 = F_33 ( V_55 -> V_81 . V_82 ,
struct V_59 , V_83 ) ;
V_60 -> V_64 -> V_84 = F_31 ( V_61 -> V_8 ) ;
}
F_34 ( & V_61 -> V_83 ) ;
F_35 ( & V_61 -> V_83 , & V_55 -> V_81 ) ;
return 0 ;
}
static inline T_2 F_36 ( struct V_52 * V_73 )
{
return ( ( V_73 -> V_2 == V_70 ) ? V_85 : 0 ) | V_73 -> V_1 ;
}
static int F_37 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_3 * V_4 = V_53 -> V_4 ;
int V_86 = 0 ;
unsigned V_87 = V_55 -> V_72 . V_56 ;
int V_88 = V_78 ;
struct V_59 * V_89 , * V_60 ;
if ( V_55 -> V_72 . V_90 == - V_91 )
return - V_91 ;
V_55 -> V_72 . V_90 = - V_91 ;
V_86 = F_38 ( & V_4 -> V_92 , & V_55 -> V_72 , V_53 -> V_2 ) ;
if ( V_86 )
return V_86 ;
if ( V_55 -> V_72 . V_8 % V_93 )
V_88 -- ;
if ( V_87 == 0 ) {
V_86 = F_27 ( V_53 , V_55 , 0 ) ;
if ( V_86 < 0 )
goto V_94;
}
while ( V_87 > 0 ) {
unsigned V_95 = F_39 ( V_55 -> V_72 . V_56 - V_55 -> V_72 . V_76 ,
( unsigned ) ( V_88 * V_79 ) ) ;
V_86 = F_27 ( V_53 , V_55 , V_95 ) ;
if ( V_86 < 0 )
goto V_94;
V_87 -= V_95 ;
}
if ( V_55 -> V_72 . V_96 && V_55 -> V_72 . V_56 && V_53 -> V_2 == V_70
&& ( V_55 -> V_72 . V_56 % V_53 -> V_73 . V_74 == 0 ) ) {
V_86 = F_27 ( V_53 , V_55 , 0 ) ;
if ( V_86 < 0 )
goto V_94;
}
V_89 = F_40 ( & V_55 -> V_81 , struct V_59 , V_83 ) ;
V_60 = F_33 ( V_55 -> V_81 . V_82 ,
struct V_59 , V_83 ) ;
V_60 -> V_64 -> V_84 = F_31 ( V_97 ) ;
if ( ! V_55 -> V_72 . V_98 )
V_60 -> V_64 -> V_66 |= F_31 ( V_99 ) ;
F_41 () ;
V_55 -> V_72 . V_76 = 0 ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
struct V_54 * V_102 ;
int V_5 = F_1 ( V_53 -> V_1 , V_53 -> V_2 ) ;
int V_103 ;
struct V_59 * V_104 ;
T_1 V_84 = V_89 -> V_8 & V_105 ;
V_102 = F_33 ( V_53 -> V_100 . V_101 . V_82 ,
struct V_54 , V_101 ) ;
V_104 = F_33 ( V_102 -> V_81 . V_82 ,
struct V_59 , V_83 ) ;
V_104 -> V_64 -> V_84 = F_31 ( V_84 ) ;
F_41 () ;
if ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
goto V_94;
do {
F_4 ( V_4 , V_48 , V_106 , V_106 ) ;
V_103 = F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_48 , V_106 ) );
F_4 ( V_4 , V_48 , V_106 , 0 ) ;
if ( V_103 )
goto V_94;
}
V_53 -> V_100 . V_64 -> V_83 . V_84 = F_31 ( V_89 -> V_8 ) ;
V_53 -> V_100 . V_64 -> V_83 . V_66 &=
F_31 ( ~ ( V_107 | V_68 ) ) ;
if ( V_53 -> type == V_69 && V_53 -> V_2 == V_30 ) {
T_1 V_71 = V_55 -> V_72 . V_56 / V_53 -> V_73 . V_74 ;
if ( V_55 -> V_72 . V_56 == 0
|| V_55 -> V_72 . V_56 % V_53 -> V_73 . V_74 )
V_71 ++ ;
V_53 -> V_100 . V_64 -> V_108 |= V_71 << F_11 ( V_109 ) ;
}
F_41 () ;
V_86 = F_13 ( V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type == V_110 ) ;
V_94:
return V_86 ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_59 * V_111 = V_53 -> V_112 ;
F_43 ( V_53 -> V_65 , V_111 -> V_64 , V_111 -> V_8 ) ;
V_53 -> V_112 = NULL ;
F_30 ( V_111 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_52 * V_53 ,
struct V_59 * V_61 )
{
V_53 -> V_100 . V_64 -> V_83 . V_84 = V_61 -> V_8 ;
V_53 -> V_100 . V_64 -> V_83 . V_66 &=
F_31 ( ~ ( V_107 | V_68 ) ) ;
F_41 () ;
return F_13 ( V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type == V_110 ) ;
}
static int F_45 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
T_1 V_113 ;
struct V_59 * V_61 , * V_114 ;
unsigned V_115 ;
unsigned V_76 = V_55 -> V_72 . V_56 ;
struct V_3 * V_4 = V_53 -> V_4 ;
if ( V_55 -> V_72 . V_90 != - V_91 )
return - V_35 ;
V_55 -> V_72 . V_90 = 0 ;
F_46 (node, tmpnode, &hwreq->tds, td) {
V_113 = F_47 ( V_61 -> V_64 -> V_66 ) ;
if ( ( V_68 & V_113 ) != 0 ) {
int V_5 = F_1 ( V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_4 -> V_116 == V_117 )
if ( ! F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) )
F_44 ( V_4 , V_53 , V_61 ) ;
V_55 -> V_72 . V_90 = - V_91 ;
return - V_118 ;
}
V_115 = ( V_113 & V_67 ) ;
V_115 >>= F_11 ( V_67 ) ;
V_76 -= V_115 ;
V_55 -> V_72 . V_90 = V_113 & V_119 ;
if ( ( V_107 & V_55 -> V_72 . V_90 ) ) {
V_55 -> V_72 . V_90 = - V_120 ;
break;
} else if ( ( V_121 & V_55 -> V_72 . V_90 ) ) {
V_55 -> V_72 . V_90 = - V_122 ;
break;
} else if ( ( V_123 & V_55 -> V_72 . V_90 ) ) {
V_55 -> V_72 . V_90 = - V_124 ;
break;
}
if ( V_115 ) {
if ( V_53 -> V_2 ) {
V_55 -> V_72 . V_90 = - V_122 ;
break;
}
}
if ( V_53 -> V_112 )
F_42 ( V_53 ) ;
V_53 -> V_112 = V_61 ;
F_48 ( & V_61 -> V_83 ) ;
}
F_49 ( & V_53 -> V_4 -> V_92 , & V_55 -> V_72 , V_53 -> V_2 ) ;
V_55 -> V_72 . V_76 += V_76 ;
if ( V_55 -> V_72 . V_90 )
return V_55 -> V_72 . V_90 ;
return V_55 -> V_72 . V_76 ;
}
static int F_50 ( struct V_52 * V_53 )
__releases( V_53 -> V_125 )
__acquires( V_53 -> V_125 )
{
struct V_59 * V_61 , * V_114 ;
if ( V_53 == NULL )
return - V_35 ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
while ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
struct V_54 * V_55 = F_33 ( V_53 -> V_100 . V_101 . V_84 ,
struct V_54 , V_101 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_83 ) ;
V_61 -> V_64 = NULL ;
F_30 ( V_61 ) ;
}
F_48 ( & V_55 -> V_101 ) ;
V_55 -> V_72 . V_90 = - V_126 ;
if ( V_55 -> V_72 . V_127 != NULL ) {
F_51 ( V_53 -> V_125 ) ;
F_52 ( & V_53 -> V_73 , & V_55 -> V_72 ) ;
F_53 ( V_53 -> V_125 ) ;
}
}
if ( V_53 -> V_112 )
F_42 ( V_53 ) ;
return 0 ;
}
static int F_54 ( struct V_128 * V_73 , int V_34 , bool V_129 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
int V_130 , V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_53 -> V_73 . V_133 == NULL )
return - V_35 ;
if ( F_56 ( V_53 -> V_73 . V_133 ) )
return - V_134 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
if ( V_34 && V_53 -> V_2 == V_70 && V_129 &&
! F_32 ( & V_53 -> V_100 . V_101 ) &&
! F_58 ( V_53 -> V_73 . V_133 ) ) {
F_59 ( V_53 -> V_125 , V_132 ) ;
return - V_32 ;
}
V_130 = V_53 -> V_2 ;
do {
V_131 |= F_14 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_53 -> V_135 = 0 ;
if ( V_53 -> type == V_110 )
V_53 -> V_2 = ( V_53 -> V_2 == V_70 ) ? V_30 : V_70 ;
} while ( V_53 -> V_2 != V_130 );
F_59 ( V_53 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_60 ( struct V_136 * V_92 )
{
struct V_128 * V_73 ;
struct V_3 * V_4 = F_55 ( V_92 , struct V_3 , V_92 ) ;
unsigned long V_132 ;
F_57 ( & V_4 -> V_125 , V_132 ) ;
V_4 -> V_92 . V_137 = V_138 ;
V_4 -> V_139 = 0 ;
V_4 -> V_140 = 0 ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
F_61 (ep, gadget) {
F_62 ( V_73 ) ;
}
F_62 ( & V_4 -> V_141 -> V_73 ) ;
F_62 ( & V_4 -> V_142 -> V_73 ) ;
F_61 (ep, gadget) {
F_63 ( V_73 ) ;
}
if ( V_4 -> V_90 != NULL ) {
F_64 ( & V_4 -> V_142 -> V_73 , V_4 -> V_90 ) ;
V_4 -> V_90 = NULL ;
}
return 0 ;
}
static void F_65 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
int V_131 ;
F_51 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_92 . V_137 != V_138 )
F_66 ( & V_4 -> V_92 , V_4 -> V_143 ) ;
V_131 = F_60 ( & V_4 -> V_92 ) ;
if ( V_131 )
goto V_94;
V_131 = F_25 ( V_4 ) ;
if ( V_131 )
goto V_94;
V_4 -> V_90 = F_67 ( & V_4 -> V_142 -> V_73 , V_62 ) ;
if ( V_4 -> V_90 == NULL )
V_131 = - V_63 ;
V_94:
F_53 ( & V_4 -> V_125 ) ;
if ( V_131 )
F_68 ( V_4 -> V_144 , L_1 , V_131 ) ;
}
static void F_69 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
if ( V_73 == NULL || V_72 == NULL )
return;
F_30 ( V_72 -> V_146 ) ;
F_64 ( V_73 , V_72 ) ;
}
static int F_70 ( struct V_128 * V_73 , struct V_145 * V_72 ,
T_3 T_4 V_147 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
struct V_54 * V_55 = F_55 ( V_72 , struct V_54 , V_72 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
int V_131 = 0 ;
if ( V_73 == NULL || V_72 == NULL || V_53 -> V_73 . V_133 == NULL )
return - V_35 ;
if ( V_53 -> type == V_110 ) {
if ( V_72 -> V_56 )
V_53 = ( V_4 -> V_148 == V_30 ) ?
V_4 -> V_141 : V_4 -> V_142 ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_50 ( V_53 ) ;
V_131 = - V_149 ;
F_71 ( V_53 -> V_4 -> V_144 , L_2 ,
F_36 ( V_53 ) ) ;
}
}
if ( F_56 ( V_53 -> V_73 . V_133 ) &&
V_55 -> V_72 . V_56 > ( 1 + V_53 -> V_73 . V_150 ) * V_53 -> V_73 . V_74 ) {
F_68 ( V_53 -> V_4 -> V_144 , L_3 ) ;
return - V_151 ;
}
if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_68 ( V_53 -> V_4 -> V_144 , L_4 ) ;
return - V_118 ;
}
V_55 -> V_72 . V_90 = - V_152 ;
V_55 -> V_72 . V_76 = 0 ;
V_131 = F_37 ( V_53 , V_55 ) ;
if ( V_131 == - V_91 )
V_131 = 0 ;
if ( ! V_131 )
F_35 ( & V_55 -> V_101 , & V_53 -> V_100 . V_101 ) ;
return V_131 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_153 * V_154 )
__releases( V_53 -> V_125 )
__acquires( V_53 -> V_125 )
{
struct V_52 * V_53 = V_4 -> V_142 ;
struct V_145 * V_72 = NULL ;
T_3 V_147 = V_62 ;
int V_2 , V_1 , V_131 ;
if ( V_53 == NULL || V_154 == NULL )
return - V_35 ;
F_51 ( V_53 -> V_125 ) ;
V_72 = F_67 ( & V_53 -> V_73 , V_147 ) ;
F_53 ( V_53 -> V_125 ) ;
if ( V_72 == NULL )
return - V_63 ;
V_72 -> V_127 = F_69 ;
V_72 -> V_56 = 2 ;
V_72 -> V_146 = F_28 ( V_72 -> V_56 , V_147 ) ;
if ( V_72 -> V_146 == NULL ) {
V_131 = - V_63 ;
goto V_155;
}
if ( ( V_154 -> V_156 & V_157 ) == V_158 ) {
* ( V_159 * ) V_72 -> V_146 = ( V_4 -> V_139 << 1 ) |
V_4 -> V_92 . V_160 ;
} else if ( ( V_154 -> V_156 & V_157 ) \
== V_161 ) {
V_2 = ( F_73 ( V_154 -> V_162 ) & V_85 ) ?
V_70 : V_30 ;
V_1 = F_73 ( V_154 -> V_162 ) & V_163 ;
* ( V_159 * ) V_72 -> V_146 = F_12 ( V_4 , V_1 , V_2 ) ;
}
V_131 = F_70 ( & V_53 -> V_73 , V_72 , V_147 ) ;
if ( V_131 )
goto V_164;
return 0 ;
V_164:
F_30 ( V_72 -> V_146 ) ;
V_155:
F_51 ( V_53 -> V_125 ) ;
F_64 ( & V_53 -> V_73 , V_72 ) ;
F_53 ( V_53 -> V_125 ) ;
return V_131 ;
}
static void
F_74 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_3 * V_4 = V_72 -> V_165 ;
unsigned long V_132 ;
if ( V_4 -> V_166 ) {
F_24 ( V_4 , V_4 -> V_167 ) ;
V_4 -> V_166 = false ;
if ( V_4 -> V_167 )
F_75 ( & V_4 -> V_92 , V_168 ) ;
}
F_57 ( & V_4 -> V_125 , V_132 ) ;
if ( V_4 -> V_169 )
F_76 ( V_4 , V_4 -> V_169 ) ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
int V_131 ;
struct V_52 * V_53 ;
V_53 = ( V_4 -> V_148 == V_70 ) ? V_4 -> V_141 : V_4 -> V_142 ;
V_4 -> V_90 -> V_165 = V_4 ;
V_4 -> V_90 -> V_127 = F_74 ;
V_131 = F_70 ( & V_53 -> V_73 , V_4 -> V_90 , V_62 ) ;
return V_131 ;
}
static int F_78 ( struct V_52 * V_53 )
__releases( V_53 -> V_125 )
__acquires( V_53 -> V_125 )
{
struct V_54 * V_55 , * V_170 ;
struct V_52 * V_171 = V_53 ;
int V_131 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_131 = F_45 ( V_53 , V_55 ) ;
if ( V_131 < 0 )
break;
F_48 ( & V_55 -> V_101 ) ;
if ( V_55 -> V_72 . V_127 != NULL ) {
F_51 ( V_53 -> V_125 ) ;
if ( ( V_53 -> type == V_110 ) &&
V_55 -> V_72 . V_56 )
V_171 = V_53 -> V_4 -> V_142 ;
F_52 ( & V_171 -> V_73 , & V_55 -> V_72 ) ;
F_53 ( V_53 -> V_125 ) ;
}
}
if ( V_131 == - V_118 )
V_131 = 0 ;
return V_131 ;
}
static int F_79 ( struct V_3 * V_4 )
{
F_71 ( & V_4 -> V_92 . V_144 ,
L_5 ) ;
return F_77 ( V_4 ) ;
}
static void F_80 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
struct V_52 * V_53 = & V_4 -> V_52 [ 0 ] ;
struct V_153 V_72 ;
int type , V_1 , V_2 , V_172 = - V_35 ;
T_2 V_173 = 0 ;
F_50 ( V_4 -> V_141 ) ;
F_50 ( V_4 -> V_142 ) ;
do {
F_23 ( V_4 ) ;
memcpy ( & V_72 , & V_53 -> V_100 . V_64 -> V_154 , sizeof( V_72 ) ) ;
} while ( ! F_21 ( V_4 ) );
type = V_72 . V_156 ;
V_4 -> V_148 = ( type & V_174 ) ? V_70 : V_30 ;
switch ( V_72 . V_175 ) {
case V_176 :
if ( type == ( V_177 | V_161 ) &&
F_73 ( V_72 . V_178 ) ==
V_179 ) {
if ( V_72 . V_180 != 0 )
break;
V_1 = F_73 ( V_72 . V_162 ) ;
V_2 = V_1 & V_85 ;
V_1 &= V_163 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_52 [ V_1 ] . V_135 ) {
F_51 ( & V_4 -> V_125 ) ;
V_172 = F_81 (
& V_4 -> V_52 [ V_1 ] . V_73 ) ;
F_53 ( & V_4 -> V_125 ) ;
if ( V_172 )
break;
}
V_172 = F_77 ( V_4 ) ;
} else if ( type == ( V_177 | V_158 ) &&
F_73 ( V_72 . V_178 ) ==
V_181 ) {
if ( V_72 . V_180 != 0 )
break;
V_4 -> V_139 = 0 ;
V_172 = F_77 ( V_4 ) ;
} else {
goto V_182;
}
break;
case V_183 :
if ( type != ( V_174 | V_158 ) &&
type != ( V_174 | V_161 ) &&
type != ( V_174 | V_184 ) )
goto V_182;
if ( F_73 ( V_72 . V_180 ) != 2 ||
F_73 ( V_72 . V_178 ) != 0 )
break;
V_172 = F_72 ( V_4 , & V_72 ) ;
break;
case V_185 :
if ( type != ( V_177 | V_158 ) )
goto V_182;
if ( F_73 ( V_72 . V_180 ) != 0 ||
F_73 ( V_72 . V_162 ) != 0 )
break;
V_4 -> V_167 = ( T_2 ) F_73 ( V_72 . V_178 ) ;
V_4 -> V_166 = true ;
V_172 = F_77 ( V_4 ) ;
break;
case V_186 :
if ( type == ( V_177 | V_161 ) &&
F_73 ( V_72 . V_178 ) ==
V_179 ) {
if ( V_72 . V_180 != 0 )
break;
V_1 = F_73 ( V_72 . V_162 ) ;
V_2 = V_1 & V_85 ;
V_1 &= V_163 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_51 ( & V_4 -> V_125 ) ;
V_172 = F_54 ( & V_4 -> V_52 [ V_1 ] . V_73 , 1 , false ) ;
F_53 ( & V_4 -> V_125 ) ;
if ( ! V_172 )
F_77 ( V_4 ) ;
} else if ( type == ( V_177 | V_158 ) ) {
if ( V_72 . V_180 != 0 )
break;
switch ( F_73 ( V_72 . V_178 ) ) {
case V_181 :
V_4 -> V_139 = 1 ;
V_172 = F_77 ( V_4 ) ;
break;
case V_187 :
V_173 = F_73 ( V_72 . V_162 ) >> 8 ;
switch ( V_173 ) {
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
V_4 -> V_169 = V_173 ;
V_172 = F_77 (
V_4 ) ;
break;
default:
break;
}
break;
case V_193 :
if ( F_82 ( V_4 ) ) {
V_4 -> V_92 . V_194 = 1 ;
V_172 = F_77 (
V_4 ) ;
}
break;
case V_195 :
if ( F_82 ( V_4 ) )
V_172 = F_79 ( V_4 ) ;
break;
case V_196 :
if ( F_82 ( V_4 ) ) {
V_4 -> V_92 . V_197 = 1 ;
V_172 = F_77 (
V_4 ) ;
}
break;
default:
goto V_182;
}
} else {
goto V_182;
}
break;
default:
V_182:
if ( V_72 . V_180 == 0 )
V_4 -> V_148 = V_70 ;
F_51 ( & V_4 -> V_125 ) ;
V_172 = V_4 -> V_143 -> V_154 ( & V_4 -> V_92 , & V_72 ) ;
F_53 ( & V_4 -> V_125 ) ;
break;
}
if ( V_172 < 0 ) {
F_51 ( & V_4 -> V_125 ) ;
if ( F_54 ( & V_53 -> V_73 , 1 , false ) )
F_68 ( V_4 -> V_144 , L_6 ) ;
F_53 ( & V_4 -> V_125 ) ;
}
}
static void F_83 ( struct V_3 * V_4 )
__releases( V_4 -> V_125 )
__acquires( V_4 -> V_125 )
{
unsigned V_57 ;
int V_172 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_73 . V_133 == NULL )
continue;
if ( F_16 ( V_4 , V_57 ) ) {
V_172 = F_78 ( V_53 ) ;
if ( V_53 -> type == V_110 ) {
if ( V_172 > 0 )
V_172 = F_77 ( V_4 ) ;
if ( V_172 < 0 ) {
F_51 ( & V_4 -> V_125 ) ;
if ( F_54 ( & V_53 -> V_73 , 1 , false ) )
F_68 ( V_4 -> V_144 ,
L_6 ) ;
F_53 ( & V_4 -> V_125 ) ;
}
}
}
if ( V_57 == 0 &&
F_17 ( V_4 , V_31 , F_6 ( 0 ) ) )
F_80 ( V_4 ) ;
}
}
static int F_84 ( struct V_128 * V_73 ,
const struct V_198 * V_133 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
int V_131 = 0 ;
unsigned long V_132 ;
T_1 V_108 = 0 ;
if ( V_73 == NULL || V_133 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
if ( ! F_32 ( & V_53 -> V_100 . V_101 ) ) {
F_71 ( V_53 -> V_4 -> V_144 , L_7 ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return - V_118 ;
}
V_53 -> V_73 . V_133 = V_133 ;
V_53 -> V_2 = F_85 ( V_133 ) ? V_70 : V_30 ;
V_53 -> V_1 = F_86 ( V_133 ) ;
V_53 -> type = F_87 ( V_133 ) ;
V_53 -> V_73 . V_74 = F_88 ( V_133 ) & 0x07ff ;
V_53 -> V_73 . V_150 = F_89 ( F_88 ( V_133 ) ) ;
if ( V_53 -> type == V_110 )
V_108 |= V_199 ;
V_108 |= V_200 ;
V_108 |= ( V_53 -> V_73 . V_74 << F_11 ( V_201 ) ) & V_201 ;
if ( V_53 -> type == V_69 && V_53 -> V_2 == V_70 )
V_108 |= 3 << F_11 ( V_109 ) ;
V_53 -> V_100 . V_64 -> V_108 = F_31 ( V_108 ) ;
V_53 -> V_100 . V_64 -> V_83 . V_84 |= F_31 ( V_97 ) ;
if ( V_53 -> V_1 != 0 && V_53 -> type == V_110 ) {
F_68 ( V_53 -> V_4 -> V_144 , L_8 ) ;
V_131 = - V_35 ;
}
if ( V_53 -> V_1 )
V_131 |= F_10 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ,
V_53 -> type ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_90 ( struct V_128 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
int V_130 , V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL )
return - V_35 ;
else if ( V_53 -> V_73 . V_133 == NULL )
return - V_118 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
V_130 = V_53 -> V_2 ;
do {
V_131 |= F_50 ( V_53 ) ;
V_131 |= F_9 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
if ( V_53 -> type == V_110 )
V_53 -> V_2 = ( V_53 -> V_2 == V_70 ) ? V_30 : V_70 ;
} while ( V_53 -> V_2 != V_130 );
V_53 -> V_73 . V_133 = NULL ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return V_131 ;
}
static struct V_145 * F_91 ( struct V_128 * V_73 , T_3 V_147 )
{
struct V_54 * V_55 = NULL ;
if ( V_73 == NULL )
return NULL ;
V_55 = F_28 ( sizeof( struct V_54 ) , V_147 ) ;
if ( V_55 != NULL ) {
F_34 ( & V_55 -> V_101 ) ;
F_34 ( & V_55 -> V_81 ) ;
}
return ( V_55 == NULL ) ? NULL : & V_55 -> V_72 ;
}
static void F_92 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
struct V_54 * V_55 = F_55 ( V_72 , struct V_54 , V_72 ) ;
struct V_59 * V_61 , * V_114 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_72 == NULL ) {
return;
} else if ( ! F_32 ( & V_55 -> V_101 ) ) {
F_68 ( V_53 -> V_4 -> V_144 , L_9 ) ;
return;
}
F_57 ( V_53 -> V_125 , V_132 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_48 ( & V_61 -> V_83 ) ;
V_61 -> V_64 = NULL ;
F_30 ( V_61 ) ;
}
F_30 ( V_55 ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
}
static int F_93 ( struct V_128 * V_73 , struct V_145 * V_72 ,
T_3 T_4 V_147 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
int V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_72 == NULL || V_53 -> V_73 . V_133 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
V_131 = F_70 ( V_73 , V_72 , V_147 ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_94 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
struct V_54 * V_55 = F_55 ( V_72 , struct V_54 , V_72 ) ;
unsigned long V_132 ;
struct V_59 * V_61 , * V_114 ;
if ( V_73 == NULL || V_72 == NULL || V_55 -> V_72 . V_90 != - V_91 ||
V_53 -> V_73 . V_133 == NULL || F_32 ( & V_55 -> V_101 ) ||
F_32 ( & V_53 -> V_100 . V_101 ) )
return - V_35 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_53 -> V_65 , V_61 -> V_64 , V_61 -> V_8 ) ;
F_95 ( & V_61 -> V_83 ) ;
F_30 ( V_61 ) ;
}
F_48 ( & V_55 -> V_101 ) ;
F_49 ( & V_53 -> V_4 -> V_92 , V_72 , V_53 -> V_2 ) ;
V_72 -> V_90 = - V_202 ;
if ( V_55 -> V_72 . V_127 != NULL ) {
F_51 ( V_53 -> V_125 ) ;
F_52 ( & V_53 -> V_73 , & V_55 -> V_72 ) ;
F_53 ( V_53 -> V_125 ) ;
}
F_59 ( V_53 -> V_125 , V_132 ) ;
return 0 ;
}
static int F_96 ( struct V_128 * V_73 , int V_34 )
{
return F_54 ( V_73 , V_34 , true ) ;
}
static int F_97 ( struct V_128 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
unsigned long V_132 ;
if ( V_73 == NULL || V_53 -> V_73 . V_133 == NULL )
return - V_35 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
V_53 -> V_135 = 1 ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return F_98 ( V_73 ) ;
}
static void F_99 ( struct V_128 * V_73 )
{
struct V_52 * V_53 = F_55 ( V_73 , struct V_52 , V_73 ) ;
unsigned long V_132 ;
if ( V_73 == NULL ) {
F_68 ( V_53 -> V_4 -> V_144 , L_10 , F_36 ( V_53 ) ) ;
return;
}
F_57 ( V_53 -> V_125 , V_132 ) ;
F_5 ( V_53 -> V_4 , V_53 -> V_1 , V_53 -> V_2 ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
}
static int F_100 ( struct V_136 * V_203 , int V_204 )
{
struct V_3 * V_4 = F_55 ( V_203 , struct V_3 , V_92 ) ;
unsigned long V_132 ;
int V_205 = 0 ;
F_57 ( & V_4 -> V_125 , V_132 ) ;
V_4 -> V_206 = V_204 ;
if ( V_4 -> V_143 )
V_205 = 1 ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
if ( V_205 ) {
if ( V_204 ) {
F_101 ( & V_203 -> V_144 ) ;
F_102 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_141 -> V_100 . V_8 ) ;
F_75 ( V_203 , V_207 ) ;
F_103 ( V_203 , true ) ;
} else {
F_103 ( V_203 , false ) ;
if ( V_4 -> V_143 )
V_4 -> V_143 -> V_208 ( & V_4 -> V_92 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_209 -> V_210 )
V_4 -> V_209 -> V_210 ( V_4 ,
V_211 ) ;
F_60 ( & V_4 -> V_92 ) ;
F_104 ( & V_203 -> V_144 ) ;
F_75 ( V_203 , V_212 ) ;
}
}
return 0 ;
}
static int F_105 ( struct V_136 * V_203 )
{
struct V_3 * V_4 = F_55 ( V_203 , struct V_3 , V_92 ) ;
unsigned long V_132 ;
int V_86 = 0 ;
F_57 ( & V_4 -> V_125 , V_132 ) ;
if ( ! V_4 -> V_139 ) {
V_86 = - V_134 ;
goto V_213;
}
if ( ! F_7 ( V_4 , V_44 , V_214 ) ) {
V_86 = - V_35 ;
goto V_213;
}
F_4 ( V_4 , V_44 , V_215 , V_215 ) ;
V_213:
F_59 ( & V_4 -> V_125 , V_132 ) ;
return V_86 ;
}
static int F_106 ( struct V_136 * V_203 , unsigned V_216 )
{
struct V_3 * V_4 = F_55 ( V_203 , struct V_3 , V_92 ) ;
if ( V_4 -> V_217 )
return F_107 ( V_4 -> V_217 , V_216 ) ;
return - V_218 ;
}
static int F_108 ( struct V_136 * V_203 , int V_219 )
{
struct V_3 * V_4 = F_55 ( V_203 , struct V_3 , V_92 ) ;
struct V_52 * V_53 = V_4 -> V_142 ;
unsigned long V_132 ;
F_57 ( V_53 -> V_125 , V_132 ) ;
V_203 -> V_160 = ( V_219 != 0 ) ;
F_59 ( V_53 -> V_125 , V_132 ) ;
return 0 ;
}
static int F_109 ( struct V_136 * V_203 , int V_219 )
{
struct V_3 * V_4 = F_55 ( V_203 , struct V_3 , V_92 ) ;
if ( F_82 ( V_4 ) )
return 0 ;
F_101 ( & V_4 -> V_92 . V_144 ) ;
if ( V_219 )
F_4 ( V_4 , V_48 , V_220 , V_220 ) ;
else
F_4 ( V_4 , V_48 , V_220 , 0 ) ;
F_104 ( & V_4 -> V_92 . V_144 ) ;
return 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
int V_131 = 0 , V_57 , V_221 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 / 2 ; V_57 ++ )
for ( V_221 = V_30 ; V_221 <= V_70 ; V_221 ++ ) {
int V_222 = V_57 + V_221 * V_4 -> V_7 / 2 ;
struct V_52 * V_53 = & V_4 -> V_52 [ V_222 ] ;
F_111 ( V_53 -> V_223 , sizeof( V_53 -> V_223 ) , L_11 , V_57 ,
( V_221 == V_70 ) ? L_12 : L_13 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_125 = & V_4 -> V_125 ;
V_53 -> V_65 = V_4 -> V_65 ;
V_53 -> V_73 . V_223 = V_53 -> V_223 ;
V_53 -> V_73 . V_224 = & V_225 ;
if ( V_57 == 0 ) {
V_53 -> V_73 . V_226 . V_227 = true ;
} else {
V_53 -> V_73 . V_226 . V_228 = true ;
V_53 -> V_73 . V_226 . V_229 = true ;
V_53 -> V_73 . V_226 . V_230 = true ;
}
if ( V_221 == V_70 )
V_53 -> V_73 . V_226 . V_231 = true ;
else
V_53 -> V_73 . V_226 . V_232 = true ;
F_112 ( & V_53 -> V_73 , ( unsigned short ) ~ 0 ) ;
F_34 ( & V_53 -> V_100 . V_101 ) ;
V_53 -> V_100 . V_64 = F_113 ( V_4 -> V_233 , V_234 ,
& V_53 -> V_100 . V_8 ) ;
if ( V_53 -> V_100 . V_64 == NULL )
V_131 = - V_63 ;
else
memset ( V_53 -> V_100 . V_64 , 0 , sizeof( * V_53 -> V_100 . V_64 ) ) ;
if ( V_57 == 0 ) {
if ( V_221 == V_30 )
V_4 -> V_141 = V_53 ;
else
V_4 -> V_142 = V_53 ;
F_112 ( & V_53 -> V_73 , V_235 ) ;
continue;
}
F_35 ( & V_53 -> V_73 . V_236 , & V_4 -> V_92 . V_236 ) ;
}
return V_131 ;
}
static void F_114 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_7 ; V_57 ++ ) {
struct V_52 * V_53 = & V_4 -> V_52 [ V_57 ] ;
if ( V_53 -> V_112 )
F_42 ( V_53 ) ;
F_43 ( V_4 -> V_233 , V_53 -> V_100 . V_64 , V_53 -> V_100 . V_8 ) ;
}
}
static int F_115 ( struct V_136 * V_92 ,
struct V_237 * V_143 )
{
struct V_3 * V_4 = F_55 ( V_92 , struct V_3 , V_92 ) ;
unsigned long V_132 ;
int V_131 = - V_63 ;
if ( V_143 -> V_208 == NULL )
return - V_35 ;
V_4 -> V_141 -> V_73 . V_133 = & V_238 ;
V_131 = F_116 ( & V_4 -> V_141 -> V_73 ) ;
if ( V_131 )
return V_131 ;
V_4 -> V_142 -> V_73 . V_133 = & V_239 ;
V_131 = F_116 ( & V_4 -> V_142 -> V_73 ) ;
if ( V_131 )
return V_131 ;
V_4 -> V_143 = V_143 ;
if ( F_82 ( V_4 ) && V_4 -> V_240 . V_241 ) {
F_117 ( V_4 ) ;
return V_131 ;
}
F_101 ( & V_4 -> V_92 . V_144 ) ;
if ( V_4 -> V_206 ) {
F_57 ( & V_4 -> V_125 , V_132 ) ;
F_102 ( V_4 ) ;
} else {
F_103 ( & V_4 -> V_92 , false ) ;
F_104 ( & V_4 -> V_92 . V_144 ) ;
return V_131 ;
}
V_131 = F_3 ( V_4 , V_4 -> V_141 -> V_100 . V_8 ) ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
if ( V_131 )
F_104 ( & V_4 -> V_92 . V_144 ) ;
return V_131 ;
}
static void F_118 ( struct V_3 * V_4 )
{
if ( ! F_82 ( V_4 ) )
return;
F_119 ( & V_4 -> V_240 . V_125 ) ;
if ( V_4 -> V_240 . V_242 -> V_243 == V_244 ) {
V_4 -> V_240 . V_245 = 1 ;
F_117 ( V_4 ) ;
} else if ( V_4 -> V_240 . V_242 -> V_243 == V_246 ) {
V_4 -> V_240 . V_247 = V_248 ;
V_4 -> V_240 . V_242 -> V_243 = V_249 ;
}
F_120 ( & V_4 -> V_240 . V_125 ) ;
}
static int F_121 ( struct V_136 * V_92 )
{
struct V_3 * V_4 = F_55 ( V_92 , struct V_3 , V_92 ) ;
unsigned long V_132 ;
F_57 ( & V_4 -> V_125 , V_132 ) ;
if ( V_4 -> V_206 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_209 -> V_210 )
V_4 -> V_209 -> V_210 ( V_4 ,
V_211 ) ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
F_60 ( & V_4 -> V_92 ) ;
F_57 ( & V_4 -> V_125 , V_132 ) ;
F_122 ( & V_4 -> V_92 . V_144 ) ;
}
V_4 -> V_143 = NULL ;
F_59 ( & V_4 -> V_125 , V_132 ) ;
F_118 ( V_4 ) ;
return 0 ;
}
static T_5 F_123 ( struct V_3 * V_4 )
{
T_5 V_131 ;
T_1 V_250 ;
if ( V_4 == NULL )
return V_251 ;
F_53 ( & V_4 -> V_125 ) ;
if ( V_4 -> V_209 -> V_132 & V_252 ) {
if ( F_7 ( V_4 , V_253 , V_254 ) !=
V_255 ) {
F_51 ( & V_4 -> V_125 ) ;
return V_256 ;
}
}
V_250 = F_18 ( V_4 ) ;
if ( V_250 ) {
if ( V_14 & V_250 )
F_65 ( V_4 ) ;
if ( V_13 & V_250 ) {
V_4 -> V_92 . V_137 = F_15 ( V_4 ) ?
V_257 : V_258 ;
if ( V_4 -> V_140 && V_4 -> V_143 -> V_259 ) {
F_51 ( & V_4 -> V_125 ) ;
V_4 -> V_143 -> V_259 ( & V_4 -> V_92 ) ;
F_53 ( & V_4 -> V_125 ) ;
V_4 -> V_140 = 0 ;
}
}
if ( V_11 & V_250 )
F_83 ( V_4 ) ;
if ( V_15 & V_250 ) {
if ( V_4 -> V_92 . V_137 != V_138 &&
V_4 -> V_143 -> V_260 ) {
V_4 -> V_140 = 1 ;
F_51 ( & V_4 -> V_125 ) ;
V_4 -> V_143 -> V_260 ( & V_4 -> V_92 ) ;
F_75 ( & V_4 -> V_92 ,
V_261 ) ;
F_53 ( & V_4 -> V_125 ) ;
}
}
V_131 = V_251 ;
} else {
V_131 = V_256 ;
}
F_51 ( & V_4 -> V_125 ) ;
return V_131 ;
}
static int F_124 ( struct V_3 * V_4 )
{
struct V_262 * V_144 = V_4 -> V_144 ;
struct V_263 * V_264 = & V_4 -> V_209 -> V_265 ;
int V_131 = 0 ;
F_125 ( & V_4 -> V_125 ) ;
V_4 -> V_92 . V_224 = & V_266 ;
V_4 -> V_92 . V_137 = V_138 ;
V_4 -> V_92 . V_267 = V_257 ;
V_4 -> V_92 . V_223 = V_4 -> V_209 -> V_223 ;
V_4 -> V_92 . V_264 = V_264 ;
if ( V_4 -> V_268 && ( V_264 -> V_269 || V_264 -> V_270 ||
V_264 -> V_271 ) )
V_4 -> V_92 . V_268 = 1 ;
F_34 ( & V_4 -> V_92 . V_236 ) ;
V_4 -> V_233 = F_126 ( L_14 , V_144 ,
sizeof( struct V_272 ) ,
64 , V_79 ) ;
if ( V_4 -> V_233 == NULL )
return - V_63 ;
V_4 -> V_65 = F_126 ( L_15 , V_144 ,
sizeof( struct V_273 ) ,
64 , V_79 ) ;
if ( V_4 -> V_65 == NULL ) {
V_131 = - V_63 ;
goto V_274;
}
V_131 = F_110 ( V_4 ) ;
if ( V_131 )
goto V_275;
V_4 -> V_92 . V_276 = & V_4 -> V_142 -> V_73 ;
V_131 = F_127 ( V_144 , & V_4 -> V_92 ) ;
if ( V_131 )
goto F_114;
F_128 ( & V_4 -> V_92 . V_144 ) ;
F_129 ( & V_4 -> V_92 . V_144 ) ;
return V_131 ;
F_114:
F_114 ( V_4 ) ;
V_275:
F_130 ( V_4 -> V_65 ) ;
V_274:
F_130 ( V_4 -> V_233 ) ;
return V_131 ;
}
void F_131 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_277 [ V_278 ] )
return;
F_132 ( & V_4 -> V_92 ) ;
F_114 ( V_4 ) ;
F_130 ( V_4 -> V_65 ) ;
F_130 ( V_4 -> V_233 ) ;
}
static int F_133 ( struct V_3 * V_4 )
{
if ( V_4 -> V_268 )
F_134 ( V_4 , V_279 | V_280 ,
V_279 | V_280 ) ;
return 0 ;
}
static void F_135 ( struct V_3 * V_4 )
{
if ( V_4 -> V_268 )
F_134 ( V_4 , V_280 | V_279 , V_279 ) ;
}
int F_136 ( struct V_3 * V_4 )
{
struct V_281 * V_282 ;
if ( ! F_7 ( V_4 , V_283 , V_284 ) )
return - V_285 ;
V_282 = F_137 ( V_4 -> V_144 , sizeof( struct V_281 ) , V_234 ) ;
if ( ! V_282 )
return - V_63 ;
V_282 -> V_286 = F_133 ;
V_282 -> V_287 = F_135 ;
V_282 -> V_288 = F_123 ;
V_282 -> V_223 = L_16 ;
V_4 -> V_277 [ V_278 ] = V_282 ;
return F_124 ( V_4 ) ;
}
