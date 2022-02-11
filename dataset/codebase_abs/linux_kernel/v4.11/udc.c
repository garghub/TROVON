static inline int F_1 ( int V_1 , int V_2 )
{
return V_1 + ( ( V_2 == V_3 ) ? 16 : 0 ) ;
}
static inline int F_2 ( struct V_4 * V_5 , int V_6 )
{
int V_7 = 16 - V_5 -> V_8 / 2 ;
if ( V_6 >= V_5 -> V_8 / 2 )
V_6 += V_7 ;
return V_6 ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_9 )
{
if ( V_9 ) {
F_4 ( V_5 , V_10 , ~ 0 , V_9 ) ;
F_4 ( V_5 , V_11 , ~ 0 ,
V_12 | V_13 | V_14 | V_15 | V_16 ) ;
} else {
F_4 ( V_5 , V_11 , ~ 0 , 0 ) ;
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_1 , int V_2 )
{
int V_6 = F_1 ( V_1 , V_2 ) ;
do {
F_4 ( V_5 , V_17 , ~ 0 , F_6 ( V_6 ) ) ;
while ( F_7 ( V_5 , V_17 , F_6 ( V_6 ) ) )
F_8 () ;
} while ( F_7 ( V_5 , V_18 , F_6 ( V_6 ) ) );
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , int V_1 , int V_2 )
{
F_4 ( V_5 , V_19 + V_1 ,
( V_2 == V_3 ) ? V_20 : V_21 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , int V_1 , int V_2 , int type )
{
T_1 V_22 , V_23 ;
if ( V_2 == V_3 ) {
V_22 = V_24 ;
V_23 = type << F_11 ( V_22 ) ;
V_22 |= V_25 ;
V_22 |= V_26 ;
V_23 |= V_26 ;
V_22 |= V_20 ;
V_23 |= V_20 ;
} else {
V_22 = V_27 ;
V_23 = type << F_11 ( V_22 ) ;
V_22 |= V_28 ;
V_22 |= V_29 ;
V_23 |= V_29 ;
V_22 |= V_21 ;
V_23 |= V_21 ;
}
F_4 ( V_5 , V_19 + V_1 , V_22 , V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 , int V_1 , int V_2 )
{
T_1 V_22 = ( V_2 == V_3 ) ? V_25 : V_28 ;
return F_7 ( V_5 , V_19 + V_1 , V_22 ) ? 1 : 0 ;
}
static int F_13 ( struct V_4 * V_5 , int V_1 , int V_2 , int V_30 )
{
int V_6 = F_1 ( V_1 , V_2 ) ;
F_14 () ;
if ( V_30 && V_2 == V_31 && F_7 ( V_5 , V_32 , F_6 ( V_1 ) ) )
return - V_33 ;
F_4 ( V_5 , V_34 , ~ 0 , F_6 ( V_6 ) ) ;
while ( F_7 ( V_5 , V_34 , F_6 ( V_6 ) ) )
F_8 () ;
if ( V_30 && V_2 == V_31 && F_7 ( V_5 , V_32 , F_6 ( V_1 ) ) )
return - V_33 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , int V_1 , int V_2 , int V_35 )
{
if ( V_35 != 0 && V_35 != 1 )
return - V_36 ;
do {
enum V_37 V_38 = V_19 + V_1 ;
T_1 V_39 = ( V_2 == V_3 ) ? V_25 : V_28 ;
T_1 V_40 = ( V_2 == V_3 ) ? V_26 : V_29 ;
F_4 ( V_5 , V_38 , V_39 | V_40 ,
V_35 ? V_39 : V_40 ) ;
} while ( V_35 != F_12 ( V_5 , V_1 , V_2 ) );
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
return V_5 -> V_41 . V_42 ? F_7 ( V_5 , V_43 , V_44 ) :
F_7 ( V_5 , V_45 , V_46 ) ;
}
static int F_17 ( struct V_4 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) ;
return F_18 ( V_5 , V_47 , F_6 ( V_6 ) ) ;
}
static T_1 F_19 ( struct V_4 * V_5 )
{
T_1 V_38 = F_20 ( V_5 ) & F_21 ( V_5 ) ;
F_4 ( V_5 , V_48 , ~ 0 , V_38 ) ;
return V_38 ;
}
static int F_22 ( struct V_4 * V_5 )
{
return F_23 ( V_5 , V_49 , V_50 , 0 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
return F_23 ( V_5 , V_49 , V_50 , V_50 ) ;
}
static void F_25 ( struct V_4 * V_5 , T_2 V_35 )
{
F_4 ( V_5 , V_51 , V_52 ,
V_35 << F_11 ( V_52 ) ) ;
}
static int F_26 ( struct V_4 * V_5 )
{
F_25 ( V_5 , 0 ) ;
F_4 ( V_5 , V_17 , ~ 0 , ~ 0 ) ;
F_4 ( V_5 , V_32 , 0 , 0 ) ;
F_4 ( V_5 , V_47 , 0 , 0 ) ;
while ( F_7 ( V_5 , V_34 , ~ 0 ) )
F_27 ( 10 ) ;
return 0 ;
}
static int F_28 ( struct V_53 * V_54 , struct V_55 * V_56 ,
unsigned V_57 )
{
int V_58 ;
T_1 V_59 ;
struct V_60 * V_61 , * V_62 = F_29 ( sizeof( struct V_60 ) ,
V_63 ) ;
if ( V_62 == NULL )
return - V_64 ;
V_62 -> V_65 = F_30 ( V_54 -> V_66 , V_63 , & V_62 -> V_9 ) ;
if ( V_62 -> V_65 == NULL ) {
F_31 ( V_62 ) ;
return - V_64 ;
}
V_62 -> V_65 -> V_67 = F_32 ( V_57 << F_11 ( V_68 ) ) ;
V_62 -> V_65 -> V_67 &= F_32 ( V_68 ) ;
V_62 -> V_65 -> V_67 |= F_32 ( V_69 ) ;
if ( V_54 -> type == V_70 && V_54 -> V_2 == V_3 ) {
T_1 V_71 = V_56 -> V_72 . V_57 / V_54 -> V_73 . V_74 ;
if ( V_56 -> V_72 . V_57 == 0
|| V_56 -> V_72 . V_57 % V_54 -> V_73 . V_74 )
V_71 ++ ;
V_62 -> V_65 -> V_67 |= F_32 ( V_71 << F_11 ( V_75 ) ) ;
}
V_59 = ( T_1 ) ( V_56 -> V_72 . V_9 + V_56 -> V_72 . V_76 ) ;
if ( V_57 ) {
V_62 -> V_65 -> V_77 [ 0 ] = F_32 ( V_59 ) ;
for ( V_58 = 1 ; V_58 < V_78 ; V_58 ++ ) {
T_1 V_77 = V_59 + V_58 * V_79 ;
V_77 &= ~ V_80 ;
V_62 -> V_65 -> V_77 [ V_58 ] = F_32 ( V_77 ) ;
}
}
V_56 -> V_72 . V_76 += V_57 ;
if ( ! F_33 ( & V_56 -> V_81 ) ) {
V_61 = F_34 ( V_56 -> V_81 . V_82 ,
struct V_60 , V_83 ) ;
V_61 -> V_65 -> V_84 = F_32 ( V_62 -> V_9 ) ;
}
F_35 ( & V_62 -> V_83 ) ;
F_36 ( & V_62 -> V_83 , & V_56 -> V_81 ) ;
return 0 ;
}
static inline T_2 F_37 ( struct V_53 * V_73 )
{
return ( ( V_73 -> V_2 == V_3 ) ? V_85 : 0 ) | V_73 -> V_1 ;
}
static int F_38 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
struct V_4 * V_5 = V_54 -> V_5 ;
int V_86 = 0 ;
unsigned V_87 = V_56 -> V_72 . V_57 ;
int V_88 = V_78 ;
struct V_60 * V_89 , * V_61 ;
if ( V_56 -> V_72 . V_90 == - V_91 )
return - V_91 ;
V_56 -> V_72 . V_90 = - V_91 ;
V_86 = F_39 ( & V_5 -> V_92 , & V_56 -> V_72 , V_54 -> V_2 ) ;
if ( V_86 )
return V_86 ;
if ( V_56 -> V_72 . V_9 % V_93 )
V_88 -- ;
if ( V_87 == 0 ) {
V_86 = F_28 ( V_54 , V_56 , 0 ) ;
if ( V_86 < 0 )
goto V_94;
}
while ( V_87 > 0 ) {
unsigned V_95 = F_40 ( V_56 -> V_72 . V_57 - V_56 -> V_72 . V_76 ,
( unsigned ) ( V_88 * V_79 ) ) ;
V_86 = F_28 ( V_54 , V_56 , V_95 ) ;
if ( V_86 < 0 )
goto V_94;
V_87 -= V_95 ;
}
if ( V_56 -> V_72 . V_96 && V_56 -> V_72 . V_57 && V_54 -> V_2 == V_3
&& ( V_56 -> V_72 . V_57 % V_54 -> V_73 . V_74 == 0 ) ) {
V_86 = F_28 ( V_54 , V_56 , 0 ) ;
if ( V_86 < 0 )
goto V_94;
}
V_89 = F_41 ( & V_56 -> V_81 , struct V_60 , V_83 ) ;
V_61 = F_34 ( V_56 -> V_81 . V_82 ,
struct V_60 , V_83 ) ;
V_61 -> V_65 -> V_84 = F_32 ( V_97 ) ;
if ( ! V_56 -> V_72 . V_98 )
V_61 -> V_65 -> V_67 |= F_32 ( V_99 ) ;
F_14 () ;
V_56 -> V_72 . V_76 = 0 ;
if ( ! F_33 ( & V_54 -> V_100 . V_101 ) ) {
struct V_55 * V_102 ;
int V_6 = F_1 ( V_54 -> V_1 , V_54 -> V_2 ) ;
int V_103 ;
struct V_60 * V_104 ;
T_1 V_84 = V_89 -> V_9 & V_105 ;
V_102 = F_34 ( V_54 -> V_100 . V_101 . V_82 ,
struct V_55 , V_101 ) ;
V_104 = F_34 ( V_102 -> V_81 . V_82 ,
struct V_60 , V_83 ) ;
V_104 -> V_65 -> V_84 = F_32 ( V_84 ) ;
F_14 () ;
if ( F_7 ( V_5 , V_34 , F_6 ( V_6 ) ) )
goto V_94;
do {
F_4 ( V_5 , V_49 , V_106 , V_106 ) ;
V_103 = F_7 ( V_5 , V_18 , F_6 ( V_6 ) ) ;
} while ( ! F_7 ( V_5 , V_49 , V_106 ) );
F_4 ( V_5 , V_49 , V_106 , 0 ) ;
if ( V_103 )
goto V_94;
}
V_54 -> V_100 . V_65 -> V_83 . V_84 = F_32 ( V_89 -> V_9 ) ;
V_54 -> V_100 . V_65 -> V_83 . V_67 &=
F_32 ( ~ ( V_107 | V_69 ) ) ;
if ( V_54 -> type == V_70 && V_54 -> V_2 == V_31 ) {
T_1 V_71 = V_56 -> V_72 . V_57 / V_54 -> V_73 . V_74 ;
if ( V_56 -> V_72 . V_57 == 0
|| V_56 -> V_72 . V_57 % V_54 -> V_73 . V_74 )
V_71 ++ ;
V_54 -> V_100 . V_65 -> V_108 |= F_32 ( V_71 << F_11 ( V_109 ) ) ;
}
V_86 = F_13 ( V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type == V_110 ) ;
V_94:
return V_86 ;
}
static void F_42 ( struct V_53 * V_54 )
{
struct V_60 * V_111 = V_54 -> V_112 ;
F_43 ( V_54 -> V_66 , V_111 -> V_65 , V_111 -> V_9 ) ;
V_54 -> V_112 = NULL ;
F_31 ( V_111 ) ;
}
static int F_44 ( struct V_4 * V_5 , struct V_53 * V_54 ,
struct V_60 * V_62 )
{
V_54 -> V_100 . V_65 -> V_83 . V_84 = F_32 ( V_62 -> V_9 ) ;
V_54 -> V_100 . V_65 -> V_83 . V_67 &=
F_32 ( ~ ( V_107 | V_69 ) ) ;
return F_13 ( V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type == V_110 ) ;
}
static int F_45 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
T_1 V_113 ;
struct V_60 * V_62 , * V_114 ;
unsigned V_115 ;
unsigned V_76 = V_56 -> V_72 . V_57 ;
struct V_4 * V_5 = V_54 -> V_5 ;
if ( V_56 -> V_72 . V_90 != - V_91 )
return - V_36 ;
V_56 -> V_72 . V_90 = 0 ;
F_46 (node, tmpnode, &hwreq->tds, td) {
V_113 = F_47 ( V_62 -> V_65 -> V_67 ) ;
if ( ( V_69 & V_113 ) != 0 ) {
int V_6 = F_1 ( V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_5 -> V_116 == V_117 )
if ( ! F_7 ( V_5 , V_18 , F_6 ( V_6 ) ) )
F_44 ( V_5 , V_54 , V_62 ) ;
V_56 -> V_72 . V_90 = - V_91 ;
return - V_118 ;
}
V_115 = ( V_113 & V_68 ) ;
V_115 >>= F_11 ( V_68 ) ;
V_76 -= V_115 ;
V_56 -> V_72 . V_90 = V_113 & V_119 ;
if ( ( V_107 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_120 ;
break;
} else if ( ( V_121 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_122 ;
break;
} else if ( ( V_123 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_124 ;
break;
}
if ( V_115 ) {
if ( V_54 -> V_2 == V_3 ) {
V_56 -> V_72 . V_90 = - V_122 ;
break;
}
}
if ( V_54 -> V_112 )
F_42 ( V_54 ) ;
V_54 -> V_112 = V_62 ;
F_48 ( & V_62 -> V_83 ) ;
}
F_49 ( & V_54 -> V_5 -> V_92 , & V_56 -> V_72 , V_54 -> V_2 ) ;
V_56 -> V_72 . V_76 += V_76 ;
if ( V_56 -> V_72 . V_90 )
return V_56 -> V_72 . V_90 ;
return V_56 -> V_72 . V_76 ;
}
static int F_50 ( struct V_53 * V_54 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_60 * V_62 , * V_114 ;
if ( V_54 == NULL )
return - V_36 ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
while ( ! F_33 ( & V_54 -> V_100 . V_101 ) ) {
struct V_55 * V_56 = F_34 ( V_54 -> V_100 . V_101 . V_84 ,
struct V_55 , V_101 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_48 ( & V_62 -> V_83 ) ;
V_62 -> V_65 = NULL ;
F_31 ( V_62 ) ;
}
F_48 ( & V_56 -> V_101 ) ;
V_56 -> V_72 . V_90 = - V_126 ;
if ( V_56 -> V_72 . V_127 != NULL ) {
F_51 ( V_54 -> V_125 ) ;
F_52 ( & V_54 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_125 ) ;
}
}
if ( V_54 -> V_112 )
F_42 ( V_54 ) ;
return 0 ;
}
static int F_54 ( struct V_128 * V_73 , int V_35 , bool V_129 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_130 , V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_54 -> V_73 . V_133 == NULL )
return - V_36 ;
if ( F_56 ( V_54 -> V_73 . V_133 ) )
return - V_134 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
if ( V_35 && V_54 -> V_2 == V_3 && V_129 &&
! F_33 ( & V_54 -> V_100 . V_101 ) &&
! F_58 ( V_54 -> V_73 . V_133 ) ) {
F_59 ( V_54 -> V_125 , V_132 ) ;
return - V_33 ;
}
V_130 = V_54 -> V_2 ;
do {
V_131 |= F_15 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 , V_35 ) ;
if ( ! V_35 )
V_54 -> V_135 = 0 ;
if ( V_54 -> type == V_110 )
V_54 -> V_2 = ( V_54 -> V_2 == V_3 ) ? V_31 : V_3 ;
} while ( V_54 -> V_2 != V_130 );
F_59 ( V_54 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_60 ( struct V_136 * V_92 )
{
struct V_128 * V_73 ;
struct V_4 * V_5 = F_55 ( V_92 , struct V_4 , V_92 ) ;
unsigned long V_132 ;
F_57 ( & V_5 -> V_125 , V_132 ) ;
V_5 -> V_92 . V_137 = V_138 ;
V_5 -> V_139 = 0 ;
V_5 -> V_140 = 0 ;
F_59 ( & V_5 -> V_125 , V_132 ) ;
F_61 (ep, gadget) {
F_62 ( V_73 ) ;
}
F_62 ( & V_5 -> V_141 -> V_73 ) ;
F_62 ( & V_5 -> V_142 -> V_73 ) ;
F_61 (ep, gadget) {
F_63 ( V_73 ) ;
}
if ( V_5 -> V_90 != NULL ) {
F_64 ( & V_5 -> V_142 -> V_73 , V_5 -> V_90 ) ;
V_5 -> V_90 = NULL ;
}
return 0 ;
}
static void F_65 ( struct V_4 * V_5 )
__releases( V_5 -> V_125 )
__acquires( V_5 -> V_125 )
{
int V_131 ;
F_51 ( & V_5 -> V_125 ) ;
if ( V_5 -> V_92 . V_137 != V_138 )
F_66 ( & V_5 -> V_92 , V_5 -> V_143 ) ;
V_131 = F_60 ( & V_5 -> V_92 ) ;
if ( V_131 )
goto V_94;
V_131 = F_26 ( V_5 ) ;
if ( V_131 )
goto V_94;
V_5 -> V_90 = F_67 ( & V_5 -> V_142 -> V_73 , V_63 ) ;
if ( V_5 -> V_90 == NULL )
V_131 = - V_64 ;
V_94:
F_53 ( & V_5 -> V_125 ) ;
if ( V_131 )
F_68 ( V_5 -> V_144 , L_1 , V_131 ) ;
}
static void F_69 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
if ( V_73 == NULL || V_72 == NULL )
return;
F_31 ( V_72 -> V_146 ) ;
F_64 ( V_73 , V_72 ) ;
}
static int F_70 ( struct V_128 * V_73 , struct V_145 * V_72 ,
T_3 T_4 V_147 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
struct V_4 * V_5 = V_54 -> V_5 ;
int V_131 = 0 ;
if ( V_73 == NULL || V_72 == NULL || V_54 -> V_73 . V_133 == NULL )
return - V_36 ;
if ( V_54 -> type == V_110 ) {
if ( V_72 -> V_57 )
V_54 = ( V_5 -> V_148 == V_31 ) ?
V_5 -> V_141 : V_5 -> V_142 ;
if ( ! F_33 ( & V_54 -> V_100 . V_101 ) ) {
F_50 ( V_54 ) ;
F_71 ( V_54 -> V_5 -> V_144 , L_2 ,
F_37 ( V_54 ) ) ;
}
}
if ( F_56 ( V_54 -> V_73 . V_133 ) &&
V_56 -> V_72 . V_57 > V_54 -> V_73 . V_149 * V_54 -> V_73 . V_74 ) {
F_68 ( V_54 -> V_5 -> V_144 , L_3 ) ;
return - V_150 ;
}
if ( ! F_33 ( & V_56 -> V_101 ) ) {
F_68 ( V_54 -> V_5 -> V_144 , L_4 ) ;
return - V_118 ;
}
V_56 -> V_72 . V_90 = - V_151 ;
V_56 -> V_72 . V_76 = 0 ;
V_131 = F_38 ( V_54 , V_56 ) ;
if ( V_131 == - V_91 )
V_131 = 0 ;
if ( ! V_131 )
F_36 ( & V_56 -> V_101 , & V_54 -> V_100 . V_101 ) ;
return V_131 ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_152 * V_153 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_53 * V_54 = V_5 -> V_142 ;
struct V_145 * V_72 = NULL ;
T_3 V_147 = V_63 ;
int V_2 , V_1 , V_131 ;
if ( V_54 == NULL || V_153 == NULL )
return - V_36 ;
F_51 ( V_54 -> V_125 ) ;
V_72 = F_67 ( & V_54 -> V_73 , V_147 ) ;
F_53 ( V_54 -> V_125 ) ;
if ( V_72 == NULL )
return - V_64 ;
V_72 -> V_127 = F_69 ;
V_72 -> V_57 = 2 ;
V_72 -> V_146 = F_29 ( V_72 -> V_57 , V_147 ) ;
if ( V_72 -> V_146 == NULL ) {
V_131 = - V_64 ;
goto V_154;
}
if ( ( V_153 -> V_155 & V_156 ) == V_157 ) {
* ( V_158 * ) V_72 -> V_146 = ( V_5 -> V_139 << 1 ) |
V_5 -> V_92 . V_159 ;
} else if ( ( V_153 -> V_155 & V_156 ) \
== V_160 ) {
V_2 = ( F_73 ( V_153 -> V_161 ) & V_85 ) ?
V_3 : V_31 ;
V_1 = F_73 ( V_153 -> V_161 ) & V_162 ;
* ( V_158 * ) V_72 -> V_146 = F_12 ( V_5 , V_1 , V_2 ) ;
}
V_131 = F_70 ( & V_54 -> V_73 , V_72 , V_147 ) ;
if ( V_131 )
goto V_163;
return 0 ;
V_163:
F_31 ( V_72 -> V_146 ) ;
V_154:
F_51 ( V_54 -> V_125 ) ;
F_64 ( & V_54 -> V_73 , V_72 ) ;
F_53 ( V_54 -> V_125 ) ;
return V_131 ;
}
static void
F_74 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_164 ;
unsigned long V_132 ;
if ( V_5 -> V_165 ) {
F_25 ( V_5 , V_5 -> V_166 ) ;
V_5 -> V_165 = false ;
if ( V_5 -> V_166 )
F_75 ( & V_5 -> V_92 , V_167 ) ;
}
F_57 ( & V_5 -> V_125 , V_132 ) ;
if ( V_5 -> V_168 )
F_76 ( V_5 , V_5 -> V_168 ) ;
F_59 ( & V_5 -> V_125 , V_132 ) ;
}
static int F_77 ( struct V_4 * V_5 )
{
int V_131 ;
struct V_53 * V_54 ;
if ( F_78 ( ! V_5 -> V_90 ) )
return - V_120 ;
V_54 = ( V_5 -> V_148 == V_3 ) ? V_5 -> V_141 : V_5 -> V_142 ;
V_5 -> V_90 -> V_164 = V_5 ;
V_5 -> V_90 -> V_127 = F_74 ;
V_131 = F_70 ( & V_54 -> V_73 , V_5 -> V_90 , V_63 ) ;
return V_131 ;
}
static int F_79 ( struct V_53 * V_54 )
__releases( V_54 -> V_125 )
__acquires( V_54 -> V_125 )
{
struct V_55 * V_56 , * V_169 ;
struct V_53 * V_170 = V_54 ;
int V_131 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_131 = F_45 ( V_54 , V_56 ) ;
if ( V_131 < 0 )
break;
F_48 ( & V_56 -> V_101 ) ;
if ( V_56 -> V_72 . V_127 != NULL ) {
F_51 ( V_54 -> V_125 ) ;
if ( ( V_54 -> type == V_110 ) &&
V_56 -> V_72 . V_57 )
V_170 = V_54 -> V_5 -> V_142 ;
F_52 ( & V_170 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_125 ) ;
}
}
if ( V_131 == - V_118 )
V_131 = 0 ;
return V_131 ;
}
static int F_80 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_92 . V_144 ,
L_5 ) ;
return F_77 ( V_5 ) ;
}
static void F_81 ( struct V_4 * V_5 )
__releases( V_5 -> V_125 )
__acquires( V_5 -> V_125 )
{
struct V_53 * V_54 = & V_5 -> V_53 [ 0 ] ;
struct V_152 V_72 ;
int type , V_1 , V_2 , V_171 = - V_36 ;
T_2 V_172 = 0 ;
F_50 ( V_5 -> V_141 ) ;
F_50 ( V_5 -> V_142 ) ;
do {
F_24 ( V_5 ) ;
memcpy ( & V_72 , & V_54 -> V_100 . V_65 -> V_153 , sizeof( V_72 ) ) ;
} while ( ! F_22 ( V_5 ) );
type = V_72 . V_155 ;
V_5 -> V_148 = ( type & V_173 ) ? V_3 : V_31 ;
switch ( V_72 . V_174 ) {
case V_175 :
if ( type == ( V_176 | V_160 ) &&
F_73 ( V_72 . V_177 ) ==
V_178 ) {
if ( V_72 . V_179 != 0 )
break;
V_1 = F_73 ( V_72 . V_161 ) ;
V_2 = ( V_1 & V_85 ) ? V_3 : V_31 ;
V_1 &= V_162 ;
if ( V_2 == V_3 )
V_1 += V_5 -> V_8 / 2 ;
if ( ! V_5 -> V_53 [ V_1 ] . V_135 ) {
F_51 ( & V_5 -> V_125 ) ;
V_171 = F_82 (
& V_5 -> V_53 [ V_1 ] . V_73 ) ;
F_53 ( & V_5 -> V_125 ) ;
if ( V_171 )
break;
}
V_171 = F_77 ( V_5 ) ;
} else if ( type == ( V_176 | V_157 ) &&
F_73 ( V_72 . V_177 ) ==
V_180 ) {
if ( V_72 . V_179 != 0 )
break;
V_5 -> V_139 = 0 ;
V_171 = F_77 ( V_5 ) ;
} else {
goto V_181;
}
break;
case V_182 :
if ( ( type != ( V_173 | V_157 ) ||
F_73 ( V_72 . V_161 ) == V_183 ) &&
type != ( V_173 | V_160 ) &&
type != ( V_173 | V_184 ) )
goto V_181;
if ( F_73 ( V_72 . V_179 ) != 2 ||
F_73 ( V_72 . V_177 ) != 0 )
break;
V_171 = F_72 ( V_5 , & V_72 ) ;
break;
case V_185 :
if ( type != ( V_176 | V_157 ) )
goto V_181;
if ( F_73 ( V_72 . V_179 ) != 0 ||
F_73 ( V_72 . V_161 ) != 0 )
break;
V_5 -> V_166 = ( T_2 ) F_73 ( V_72 . V_177 ) ;
V_5 -> V_165 = true ;
V_171 = F_77 ( V_5 ) ;
break;
case V_186 :
if ( type == ( V_176 | V_160 ) &&
F_73 ( V_72 . V_177 ) ==
V_178 ) {
if ( V_72 . V_179 != 0 )
break;
V_1 = F_73 ( V_72 . V_161 ) ;
V_2 = ( V_1 & V_85 ) ? V_3 : V_31 ;
V_1 &= V_162 ;
if ( V_2 == V_3 )
V_1 += V_5 -> V_8 / 2 ;
F_51 ( & V_5 -> V_125 ) ;
V_171 = F_54 ( & V_5 -> V_53 [ V_1 ] . V_73 , 1 , false ) ;
F_53 ( & V_5 -> V_125 ) ;
if ( ! V_171 )
F_77 ( V_5 ) ;
} else if ( type == ( V_176 | V_157 ) ) {
if ( V_72 . V_179 != 0 )
break;
switch ( F_73 ( V_72 . V_177 ) ) {
case V_180 :
V_5 -> V_139 = 1 ;
V_171 = F_77 ( V_5 ) ;
break;
case V_187 :
V_172 = F_73 ( V_72 . V_161 ) >> 8 ;
switch ( V_172 ) {
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
V_5 -> V_168 = V_172 ;
V_171 = F_77 (
V_5 ) ;
break;
default:
break;
}
break;
case V_193 :
if ( F_83 ( V_5 ) ) {
V_5 -> V_92 . V_194 = 1 ;
V_171 = F_77 (
V_5 ) ;
}
break;
case V_195 :
if ( F_83 ( V_5 ) )
V_171 = F_80 ( V_5 ) ;
break;
case V_196 :
if ( F_83 ( V_5 ) ) {
V_5 -> V_92 . V_197 = 1 ;
V_171 = F_77 (
V_5 ) ;
}
break;
default:
goto V_181;
}
} else {
goto V_181;
}
break;
default:
V_181:
if ( V_72 . V_179 == 0 )
V_5 -> V_148 = V_3 ;
F_51 ( & V_5 -> V_125 ) ;
V_171 = V_5 -> V_143 -> V_153 ( & V_5 -> V_92 , & V_72 ) ;
F_53 ( & V_5 -> V_125 ) ;
break;
}
if ( V_171 < 0 ) {
F_51 ( & V_5 -> V_125 ) ;
if ( F_54 ( & V_54 -> V_73 , 1 , false ) )
F_68 ( V_5 -> V_144 , L_6 ) ;
F_53 ( & V_5 -> V_125 ) ;
}
}
static void F_84 ( struct V_4 * V_5 )
__releases( V_5 -> V_125 )
__acquires( V_5 -> V_125 )
{
unsigned V_58 ;
int V_171 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 ; V_58 ++ ) {
struct V_53 * V_54 = & V_5 -> V_53 [ V_58 ] ;
if ( V_54 -> V_73 . V_133 == NULL )
continue;
if ( F_17 ( V_5 , V_58 ) ) {
V_171 = F_79 ( V_54 ) ;
if ( V_54 -> type == V_110 ) {
if ( V_171 > 0 )
V_171 = F_77 ( V_5 ) ;
if ( V_171 < 0 ) {
F_51 ( & V_5 -> V_125 ) ;
if ( F_54 ( & V_54 -> V_73 , 1 , false ) )
F_68 ( V_5 -> V_144 ,
L_6 ) ;
F_53 ( & V_5 -> V_125 ) ;
}
}
}
if ( V_58 == 0 &&
F_18 ( V_5 , V_32 , F_6 ( 0 ) ) )
F_81 ( V_5 ) ;
}
}
static int F_85 ( struct V_128 * V_73 ,
const struct V_198 * V_133 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_131 = 0 ;
unsigned long V_132 ;
T_1 V_108 = 0 ;
if ( V_73 == NULL || V_133 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
if ( ! F_33 ( & V_54 -> V_100 . V_101 ) ) {
F_71 ( V_54 -> V_5 -> V_144 , L_7 ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return - V_118 ;
}
V_54 -> V_73 . V_133 = V_133 ;
V_54 -> V_2 = F_86 ( V_133 ) ? V_3 : V_31 ;
V_54 -> V_1 = F_87 ( V_133 ) ;
V_54 -> type = F_88 ( V_133 ) ;
V_54 -> V_73 . V_74 = F_89 ( V_133 ) ;
V_54 -> V_73 . V_149 = F_90 ( V_133 ) ;
if ( V_54 -> type == V_110 )
V_108 |= V_199 ;
V_108 |= V_200 ;
V_108 |= ( V_54 -> V_73 . V_74 << F_11 ( V_201 ) ) & V_201 ;
if ( V_54 -> type == V_70 && V_54 -> V_2 == V_3 )
V_108 |= 3 << F_11 ( V_109 ) ;
V_54 -> V_100 . V_65 -> V_108 = F_32 ( V_108 ) ;
V_54 -> V_100 . V_65 -> V_83 . V_84 |= F_32 ( V_97 ) ;
if ( V_54 -> V_1 != 0 && V_54 -> type == V_110 ) {
F_68 ( V_54 -> V_5 -> V_144 , L_8 ) ;
V_131 = - V_36 ;
}
if ( V_54 -> V_1 )
V_131 |= F_10 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_91 ( struct V_128 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_130 , V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL )
return - V_36 ;
else if ( V_54 -> V_73 . V_133 == NULL )
return - V_118 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
V_130 = V_54 -> V_2 ;
do {
V_131 |= F_50 ( V_54 ) ;
V_131 |= F_9 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_54 -> type == V_110 )
V_54 -> V_2 = ( V_54 -> V_2 == V_3 ) ? V_31 : V_3 ;
} while ( V_54 -> V_2 != V_130 );
V_54 -> V_73 . V_133 = NULL ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return V_131 ;
}
static struct V_145 * F_92 ( struct V_128 * V_73 , T_3 V_147 )
{
struct V_55 * V_56 = NULL ;
if ( V_73 == NULL )
return NULL ;
V_56 = F_29 ( sizeof( struct V_55 ) , V_147 ) ;
if ( V_56 != NULL ) {
F_35 ( & V_56 -> V_101 ) ;
F_35 ( & V_56 -> V_81 ) ;
}
return ( V_56 == NULL ) ? NULL : & V_56 -> V_72 ;
}
static void F_93 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
struct V_60 * V_62 , * V_114 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_72 == NULL ) {
return;
} else if ( ! F_33 ( & V_56 -> V_101 ) ) {
F_68 ( V_54 -> V_5 -> V_144 , L_9 ) ;
return;
}
F_57 ( V_54 -> V_125 , V_132 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_48 ( & V_62 -> V_83 ) ;
V_62 -> V_65 = NULL ;
F_31 ( V_62 ) ;
}
F_31 ( V_56 ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
}
static int F_94 ( struct V_128 * V_73 , struct V_145 * V_72 ,
T_3 T_4 V_147 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_131 = 0 ;
unsigned long V_132 ;
if ( V_73 == NULL || V_72 == NULL || V_54 -> V_73 . V_133 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
V_131 = F_70 ( V_73 , V_72 , V_147 ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return V_131 ;
}
static int F_95 ( struct V_128 * V_73 , struct V_145 * V_72 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
unsigned long V_132 ;
struct V_60 * V_62 , * V_114 ;
if ( V_73 == NULL || V_72 == NULL || V_56 -> V_72 . V_90 != - V_91 ||
V_54 -> V_73 . V_133 == NULL || F_33 ( & V_56 -> V_101 ) ||
F_33 ( & V_54 -> V_100 . V_101 ) )
return - V_36 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_96 ( & V_62 -> V_83 ) ;
F_31 ( V_62 ) ;
}
F_48 ( & V_56 -> V_101 ) ;
F_49 ( & V_54 -> V_5 -> V_92 , V_72 , V_54 -> V_2 ) ;
V_72 -> V_90 = - V_202 ;
if ( V_56 -> V_72 . V_127 != NULL ) {
F_51 ( V_54 -> V_125 ) ;
F_52 ( & V_54 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_125 ) ;
}
F_59 ( V_54 -> V_125 , V_132 ) ;
return 0 ;
}
static int F_97 ( struct V_128 * V_73 , int V_35 )
{
return F_54 ( V_73 , V_35 , true ) ;
}
static int F_98 ( struct V_128 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
unsigned long V_132 ;
if ( V_73 == NULL || V_54 -> V_73 . V_133 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
V_54 -> V_135 = 1 ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return F_99 ( V_73 ) ;
}
static void F_100 ( struct V_128 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
unsigned long V_132 ;
if ( V_73 == NULL ) {
F_68 ( V_54 -> V_5 -> V_144 , L_10 , F_37 ( V_54 ) ) ;
return;
}
F_57 ( V_54 -> V_125 , V_132 ) ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
}
static int F_101 ( struct V_136 * V_203 , int V_204 )
{
struct V_4 * V_5 = F_55 ( V_203 , struct V_4 , V_92 ) ;
unsigned long V_132 ;
int V_205 = 0 ;
F_57 ( & V_5 -> V_125 , V_132 ) ;
V_5 -> V_206 = V_204 ;
if ( V_5 -> V_143 )
V_205 = 1 ;
F_59 ( & V_5 -> V_125 , V_132 ) ;
if ( V_205 ) {
if ( V_204 ) {
F_102 ( & V_203 -> V_144 ) ;
F_103 ( V_5 ) ;
F_3 ( V_5 , V_5 -> V_141 -> V_100 . V_9 ) ;
F_75 ( V_203 , V_207 ) ;
F_104 ( V_203 , true ) ;
} else {
F_104 ( V_203 , false ) ;
if ( V_5 -> V_143 )
V_5 -> V_143 -> V_208 ( & V_5 -> V_92 ) ;
F_3 ( V_5 , 0 ) ;
if ( V_5 -> V_209 -> V_210 )
V_5 -> V_209 -> V_210 ( V_5 ,
V_211 ) ;
F_60 ( & V_5 -> V_92 ) ;
F_105 ( & V_203 -> V_144 ) ;
F_75 ( V_203 , V_212 ) ;
}
}
return 0 ;
}
static int F_106 ( struct V_136 * V_203 )
{
struct V_4 * V_5 = F_55 ( V_203 , struct V_4 , V_92 ) ;
unsigned long V_132 ;
int V_86 = 0 ;
F_57 ( & V_5 -> V_125 , V_132 ) ;
if ( ! V_5 -> V_139 ) {
V_86 = - V_134 ;
goto V_213;
}
if ( ! F_7 ( V_5 , V_45 , V_214 ) ) {
V_86 = - V_36 ;
goto V_213;
}
F_4 ( V_5 , V_45 , V_215 , V_215 ) ;
V_213:
F_59 ( & V_5 -> V_125 , V_132 ) ;
return V_86 ;
}
static int F_107 ( struct V_136 * V_203 , unsigned V_216 )
{
struct V_4 * V_5 = F_55 ( V_203 , struct V_4 , V_92 ) ;
if ( V_5 -> V_217 )
return F_108 ( V_5 -> V_217 , V_216 ) ;
return - V_218 ;
}
static int F_109 ( struct V_136 * V_203 , int V_219 )
{
struct V_4 * V_5 = F_55 ( V_203 , struct V_4 , V_92 ) ;
struct V_53 * V_54 = V_5 -> V_142 ;
unsigned long V_132 ;
F_57 ( V_54 -> V_125 , V_132 ) ;
V_203 -> V_159 = ( V_219 != 0 ) ;
F_59 ( V_54 -> V_125 , V_132 ) ;
return 0 ;
}
static int F_110 ( struct V_136 * V_203 , int V_219 )
{
struct V_4 * V_5 = F_55 ( V_203 , struct V_4 , V_92 ) ;
if ( F_83 ( V_5 ) || V_5 -> V_220 == V_221 )
return 0 ;
F_102 ( & V_5 -> V_92 . V_144 ) ;
if ( V_219 )
F_4 ( V_5 , V_49 , V_222 , V_222 ) ;
else
F_4 ( V_5 , V_49 , V_222 , 0 ) ;
F_105 ( & V_5 -> V_92 . V_144 ) ;
return 0 ;
}
static int F_111 ( struct V_4 * V_5 )
{
int V_131 = 0 , V_58 , V_223 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 / 2 ; V_58 ++ )
for ( V_223 = V_31 ; V_223 <= V_3 ; V_223 ++ ) {
int V_224 = V_58 + V_223 * V_5 -> V_8 / 2 ;
struct V_53 * V_54 = & V_5 -> V_53 [ V_224 ] ;
F_112 ( V_54 -> V_225 , sizeof( V_54 -> V_225 ) , L_11 , V_58 ,
( V_223 == V_3 ) ? L_12 : L_13 ) ;
V_54 -> V_5 = V_5 ;
V_54 -> V_125 = & V_5 -> V_125 ;
V_54 -> V_66 = V_5 -> V_66 ;
V_54 -> V_73 . V_225 = V_54 -> V_225 ;
V_54 -> V_73 . V_226 = & V_227 ;
if ( V_58 == 0 ) {
V_54 -> V_73 . V_228 . V_229 = true ;
} else {
V_54 -> V_73 . V_228 . V_230 = true ;
V_54 -> V_73 . V_228 . V_231 = true ;
V_54 -> V_73 . V_228 . V_232 = true ;
}
if ( V_223 == V_3 )
V_54 -> V_73 . V_228 . V_233 = true ;
else
V_54 -> V_73 . V_228 . V_234 = true ;
F_113 ( & V_54 -> V_73 , ( unsigned short ) ~ 0 ) ;
F_35 ( & V_54 -> V_100 . V_101 ) ;
V_54 -> V_100 . V_65 = F_30 ( V_5 -> V_235 , V_236 ,
& V_54 -> V_100 . V_9 ) ;
if ( V_54 -> V_100 . V_65 == NULL )
V_131 = - V_64 ;
if ( V_58 == 0 ) {
if ( V_223 == V_31 )
V_5 -> V_141 = V_54 ;
else
V_5 -> V_142 = V_54 ;
F_113 ( & V_54 -> V_73 , V_237 ) ;
continue;
}
F_36 ( & V_54 -> V_73 . V_238 , & V_5 -> V_92 . V_238 ) ;
}
return V_131 ;
}
static void F_114 ( struct V_4 * V_5 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 ; V_58 ++ ) {
struct V_53 * V_54 = & V_5 -> V_53 [ V_58 ] ;
if ( V_54 -> V_112 )
F_42 ( V_54 ) ;
F_43 ( V_5 -> V_235 , V_54 -> V_100 . V_65 , V_54 -> V_100 . V_9 ) ;
}
}
static int F_115 ( struct V_136 * V_92 ,
struct V_239 * V_143 )
{
struct V_4 * V_5 = F_55 ( V_92 , struct V_4 , V_92 ) ;
int V_131 = - V_64 ;
if ( V_143 -> V_208 == NULL )
return - V_36 ;
V_5 -> V_141 -> V_73 . V_133 = & V_240 ;
V_131 = F_116 ( & V_5 -> V_141 -> V_73 ) ;
if ( V_131 )
return V_131 ;
V_5 -> V_142 -> V_73 . V_133 = & V_241 ;
V_131 = F_116 ( & V_5 -> V_142 -> V_73 ) ;
if ( V_131 )
return V_131 ;
V_5 -> V_143 = V_143 ;
if ( F_83 ( V_5 ) && V_5 -> V_242 . V_243 ) {
F_117 ( V_5 ) ;
return V_131 ;
}
F_102 ( & V_5 -> V_92 . V_144 ) ;
if ( V_5 -> V_206 ) {
F_103 ( V_5 ) ;
} else {
F_104 ( & V_5 -> V_92 , false ) ;
F_105 ( & V_5 -> V_92 . V_144 ) ;
return V_131 ;
}
V_131 = F_3 ( V_5 , V_5 -> V_141 -> V_100 . V_9 ) ;
if ( V_131 )
F_105 ( & V_5 -> V_92 . V_144 ) ;
return V_131 ;
}
static void F_118 ( struct V_4 * V_5 )
{
if ( ! F_83 ( V_5 ) )
return;
F_119 ( & V_5 -> V_242 . V_125 ) ;
if ( V_5 -> V_242 . V_244 -> V_245 == V_246 ) {
V_5 -> V_242 . V_247 = 1 ;
F_117 ( V_5 ) ;
} else if ( V_5 -> V_242 . V_244 -> V_245 == V_248 ) {
V_5 -> V_242 . V_249 = V_250 ;
V_5 -> V_242 . V_244 -> V_245 = V_251 ;
}
F_120 ( & V_5 -> V_242 . V_125 ) ;
}
static int F_121 ( struct V_136 * V_92 )
{
struct V_4 * V_5 = F_55 ( V_92 , struct V_4 , V_92 ) ;
unsigned long V_132 ;
F_57 ( & V_5 -> V_125 , V_132 ) ;
if ( V_5 -> V_206 ) {
F_3 ( V_5 , 0 ) ;
F_59 ( & V_5 -> V_125 , V_132 ) ;
if ( V_5 -> V_209 -> V_210 )
V_5 -> V_209 -> V_210 ( V_5 ,
V_211 ) ;
F_60 ( & V_5 -> V_92 ) ;
F_57 ( & V_5 -> V_125 , V_132 ) ;
F_122 ( & V_5 -> V_92 . V_144 ) ;
}
V_5 -> V_143 = NULL ;
F_59 ( & V_5 -> V_125 , V_132 ) ;
F_118 ( V_5 ) ;
return 0 ;
}
static T_5 F_123 ( struct V_4 * V_5 )
{
T_5 V_131 ;
T_1 V_252 ;
if ( V_5 == NULL )
return V_253 ;
F_53 ( & V_5 -> V_125 ) ;
if ( V_5 -> V_209 -> V_132 & V_254 ) {
if ( F_7 ( V_5 , V_255 , V_256 ) !=
V_257 ) {
F_51 ( & V_5 -> V_125 ) ;
return V_258 ;
}
}
V_252 = F_19 ( V_5 ) ;
if ( V_252 ) {
if ( V_15 & V_252 )
F_65 ( V_5 ) ;
if ( V_14 & V_252 ) {
V_5 -> V_92 . V_137 = F_16 ( V_5 ) ?
V_259 : V_260 ;
if ( V_5 -> V_140 && V_5 -> V_143 -> V_261 ) {
F_51 ( & V_5 -> V_125 ) ;
V_5 -> V_143 -> V_261 ( & V_5 -> V_92 ) ;
F_53 ( & V_5 -> V_125 ) ;
V_5 -> V_140 = 0 ;
}
}
if ( V_12 & V_252 )
F_84 ( V_5 ) ;
if ( V_16 & V_252 ) {
if ( V_5 -> V_92 . V_137 != V_138 &&
V_5 -> V_143 -> V_262 ) {
V_5 -> V_140 = 1 ;
F_51 ( & V_5 -> V_125 ) ;
V_5 -> V_143 -> V_262 ( & V_5 -> V_92 ) ;
F_75 ( & V_5 -> V_92 ,
V_263 ) ;
F_53 ( & V_5 -> V_125 ) ;
}
}
V_131 = V_253 ;
} else {
V_131 = V_258 ;
}
F_51 ( & V_5 -> V_125 ) ;
return V_131 ;
}
static int F_124 ( struct V_4 * V_5 )
{
struct V_264 * V_144 = V_5 -> V_144 ;
struct V_265 * V_266 = & V_5 -> V_209 -> V_267 ;
int V_131 = 0 ;
V_5 -> V_92 . V_226 = & V_268 ;
V_5 -> V_92 . V_137 = V_138 ;
V_5 -> V_92 . V_269 = V_259 ;
V_5 -> V_92 . V_225 = V_5 -> V_209 -> V_225 ;
V_5 -> V_92 . V_266 = V_266 ;
if ( V_5 -> V_270 && ( V_266 -> V_271 || V_266 -> V_272 ||
V_266 -> V_273 ) )
V_5 -> V_92 . V_270 = 1 ;
F_35 ( & V_5 -> V_92 . V_238 ) ;
V_5 -> V_235 = F_125 ( L_14 , V_144 ,
sizeof( struct V_274 ) ,
64 , V_79 ) ;
if ( V_5 -> V_235 == NULL )
return - V_64 ;
V_5 -> V_66 = F_125 ( L_15 , V_144 ,
sizeof( struct V_275 ) ,
64 , V_79 ) ;
if ( V_5 -> V_66 == NULL ) {
V_131 = - V_64 ;
goto V_276;
}
V_131 = F_111 ( V_5 ) ;
if ( V_131 )
goto V_277;
V_5 -> V_92 . V_278 = & V_5 -> V_142 -> V_73 ;
V_131 = F_126 ( V_144 , & V_5 -> V_92 ) ;
if ( V_131 )
goto F_114;
F_127 ( & V_5 -> V_92 . V_144 ) ;
F_128 ( & V_5 -> V_92 . V_144 ) ;
return V_131 ;
F_114:
F_114 ( V_5 ) ;
V_277:
F_129 ( V_5 -> V_66 ) ;
V_276:
F_129 ( V_5 -> V_235 ) ;
return V_131 ;
}
void F_130 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_279 [ V_280 ] )
return;
F_131 ( & V_5 -> V_92 ) ;
F_114 ( V_5 ) ;
F_129 ( V_5 -> V_66 ) ;
F_129 ( V_5 -> V_235 ) ;
}
static int F_132 ( struct V_4 * V_5 )
{
if ( V_5 -> V_270 )
F_133 ( V_5 , V_281 | V_282 ,
V_281 | V_282 ) ;
return 0 ;
}
static void F_134 ( struct V_4 * V_5 )
{
if ( V_5 -> V_270 )
F_133 ( V_5 , V_282 | V_281 , V_281 ) ;
}
int F_135 ( struct V_4 * V_5 )
{
struct V_283 * V_284 ;
if ( ! F_7 ( V_5 , V_285 , V_286 ) )
return - V_287 ;
V_284 = F_136 ( V_5 -> V_144 , sizeof( * V_284 ) , V_236 ) ;
if ( ! V_284 )
return - V_64 ;
V_284 -> V_288 = F_132 ;
V_284 -> V_289 = F_134 ;
V_284 -> V_290 = F_123 ;
V_284 -> V_225 = L_16 ;
V_5 -> V_279 [ V_280 ] = V_284 ;
return F_124 ( V_5 ) ;
}
