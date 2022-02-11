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
V_86 = F_39 ( V_5 -> V_92 -> V_93 ,
& V_56 -> V_72 , V_54 -> V_2 ) ;
if ( V_86 )
return V_86 ;
if ( V_56 -> V_72 . V_9 % V_94 )
V_88 -- ;
if ( V_87 == 0 ) {
V_86 = F_28 ( V_54 , V_56 , 0 ) ;
if ( V_86 < 0 )
goto V_95;
}
while ( V_87 > 0 ) {
unsigned V_96 = F_40 ( V_56 -> V_72 . V_57 - V_56 -> V_72 . V_76 ,
( unsigned ) ( V_88 * V_79 ) ) ;
V_86 = F_28 ( V_54 , V_56 , V_96 ) ;
if ( V_86 < 0 )
goto V_95;
V_87 -= V_96 ;
}
if ( V_56 -> V_72 . V_97 && V_56 -> V_72 . V_57 && V_54 -> V_2 == V_3
&& ( V_56 -> V_72 . V_57 % V_54 -> V_73 . V_74 == 0 ) ) {
V_86 = F_28 ( V_54 , V_56 , 0 ) ;
if ( V_86 < 0 )
goto V_95;
}
V_89 = F_41 ( & V_56 -> V_81 , struct V_60 , V_83 ) ;
V_61 = F_34 ( V_56 -> V_81 . V_82 ,
struct V_60 , V_83 ) ;
V_61 -> V_65 -> V_84 = F_32 ( V_98 ) ;
if ( ! V_56 -> V_72 . V_99 )
V_61 -> V_65 -> V_67 |= F_32 ( V_100 ) ;
F_14 () ;
V_56 -> V_72 . V_76 = 0 ;
if ( ! F_33 ( & V_54 -> V_101 . V_102 ) ) {
struct V_55 * V_103 ;
int V_6 = F_1 ( V_54 -> V_1 , V_54 -> V_2 ) ;
int V_104 ;
struct V_60 * V_105 ;
T_1 V_84 = V_89 -> V_9 & V_106 ;
V_103 = F_34 ( V_54 -> V_101 . V_102 . V_82 ,
struct V_55 , V_102 ) ;
V_105 = F_34 ( V_103 -> V_81 . V_82 ,
struct V_60 , V_83 ) ;
V_105 -> V_65 -> V_84 = F_32 ( V_84 ) ;
F_14 () ;
if ( F_7 ( V_5 , V_34 , F_6 ( V_6 ) ) )
goto V_95;
do {
F_4 ( V_5 , V_49 , V_107 , V_107 ) ;
V_104 = F_7 ( V_5 , V_18 , F_6 ( V_6 ) ) ;
} while ( ! F_7 ( V_5 , V_49 , V_107 ) );
F_4 ( V_5 , V_49 , V_107 , 0 ) ;
if ( V_104 )
goto V_95;
}
V_54 -> V_101 . V_65 -> V_83 . V_84 = F_32 ( V_89 -> V_9 ) ;
V_54 -> V_101 . V_65 -> V_83 . V_67 &=
F_32 ( ~ ( V_108 | V_69 ) ) ;
if ( V_54 -> type == V_70 && V_54 -> V_2 == V_31 ) {
T_1 V_71 = V_56 -> V_72 . V_57 / V_54 -> V_73 . V_74 ;
if ( V_56 -> V_72 . V_57 == 0
|| V_56 -> V_72 . V_57 % V_54 -> V_73 . V_74 )
V_71 ++ ;
V_54 -> V_101 . V_65 -> V_109 |= F_32 ( V_71 << F_11 ( V_110 ) ) ;
}
V_86 = F_13 ( V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type == V_111 ) ;
V_95:
return V_86 ;
}
static void F_42 ( struct V_53 * V_54 )
{
struct V_60 * V_112 = V_54 -> V_113 ;
F_43 ( V_54 -> V_66 , V_112 -> V_65 , V_112 -> V_9 ) ;
V_54 -> V_113 = NULL ;
F_31 ( V_112 ) ;
}
static int F_44 ( struct V_4 * V_5 , struct V_53 * V_54 ,
struct V_60 * V_62 )
{
V_54 -> V_101 . V_65 -> V_83 . V_84 = F_32 ( V_62 -> V_9 ) ;
V_54 -> V_101 . V_65 -> V_83 . V_67 &=
F_32 ( ~ ( V_108 | V_69 ) ) ;
return F_13 ( V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type == V_111 ) ;
}
static int F_45 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
T_1 V_114 ;
struct V_60 * V_62 , * V_115 ;
unsigned V_116 ;
unsigned V_76 = V_56 -> V_72 . V_57 ;
struct V_4 * V_5 = V_54 -> V_5 ;
if ( V_56 -> V_72 . V_90 != - V_91 )
return - V_36 ;
V_56 -> V_72 . V_90 = 0 ;
F_46 (node, tmpnode, &hwreq->tds, td) {
V_114 = F_47 ( V_62 -> V_65 -> V_67 ) ;
if ( ( V_69 & V_114 ) != 0 ) {
int V_6 = F_1 ( V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_5 -> V_117 == V_118 )
if ( ! F_7 ( V_5 , V_18 , F_6 ( V_6 ) ) )
F_44 ( V_5 , V_54 , V_62 ) ;
V_56 -> V_72 . V_90 = - V_91 ;
return - V_119 ;
}
V_116 = ( V_114 & V_68 ) ;
V_116 >>= F_11 ( V_68 ) ;
V_76 -= V_116 ;
V_56 -> V_72 . V_90 = V_114 & V_120 ;
if ( ( V_108 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_121 ;
break;
} else if ( ( V_122 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_123 ;
break;
} else if ( ( V_124 & V_56 -> V_72 . V_90 ) ) {
V_56 -> V_72 . V_90 = - V_125 ;
break;
}
if ( V_116 ) {
if ( V_54 -> V_2 == V_3 ) {
V_56 -> V_72 . V_90 = - V_123 ;
break;
}
}
if ( V_54 -> V_113 )
F_42 ( V_54 ) ;
V_54 -> V_113 = V_62 ;
F_48 ( & V_62 -> V_83 ) ;
}
F_49 ( V_54 -> V_5 -> V_92 -> V_93 ,
& V_56 -> V_72 , V_54 -> V_2 ) ;
V_56 -> V_72 . V_76 += V_76 ;
if ( V_56 -> V_72 . V_90 )
return V_56 -> V_72 . V_90 ;
return V_56 -> V_72 . V_76 ;
}
static int F_50 ( struct V_53 * V_54 )
__releases( V_54 -> V_126 )
__acquires( V_54 -> V_126 )
{
struct V_60 * V_62 , * V_115 ;
if ( V_54 == NULL )
return - V_36 ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
while ( ! F_33 ( & V_54 -> V_101 . V_102 ) ) {
struct V_55 * V_56 = F_34 ( V_54 -> V_101 . V_102 . V_84 ,
struct V_55 , V_102 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_48 ( & V_62 -> V_83 ) ;
V_62 -> V_65 = NULL ;
F_31 ( V_62 ) ;
}
F_48 ( & V_56 -> V_102 ) ;
V_56 -> V_72 . V_90 = - V_127 ;
if ( V_56 -> V_72 . V_128 != NULL ) {
F_51 ( V_54 -> V_126 ) ;
F_52 ( & V_54 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_126 ) ;
}
}
if ( V_54 -> V_113 )
F_42 ( V_54 ) ;
return 0 ;
}
static int F_54 ( struct V_129 * V_73 , int V_35 , bool V_130 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_131 , V_132 = 0 ;
unsigned long V_133 ;
if ( V_73 == NULL || V_54 -> V_73 . V_134 == NULL )
return - V_36 ;
if ( F_56 ( V_54 -> V_73 . V_134 ) )
return - V_135 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
if ( V_35 && V_54 -> V_2 == V_3 && V_130 &&
! F_33 ( & V_54 -> V_101 . V_102 ) &&
! F_58 ( V_54 -> V_73 . V_134 ) ) {
F_59 ( V_54 -> V_126 , V_133 ) ;
return - V_33 ;
}
V_131 = V_54 -> V_2 ;
do {
V_132 |= F_15 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 , V_35 ) ;
if ( ! V_35 )
V_54 -> V_136 = 0 ;
if ( V_54 -> type == V_111 )
V_54 -> V_2 = ( V_54 -> V_2 == V_3 ) ? V_31 : V_3 ;
} while ( V_54 -> V_2 != V_131 );
F_59 ( V_54 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_60 ( struct V_137 * V_138 )
{
struct V_129 * V_73 ;
struct V_4 * V_5 = F_55 ( V_138 , struct V_4 , V_138 ) ;
unsigned long V_133 ;
F_57 ( & V_5 -> V_126 , V_133 ) ;
V_5 -> V_138 . V_139 = V_140 ;
V_5 -> V_141 = 0 ;
V_5 -> V_142 = 0 ;
F_59 ( & V_5 -> V_126 , V_133 ) ;
F_61 (ep, gadget) {
F_62 ( V_73 ) ;
}
F_62 ( & V_5 -> V_143 -> V_73 ) ;
F_62 ( & V_5 -> V_144 -> V_73 ) ;
F_61 (ep, gadget) {
F_63 ( V_73 ) ;
}
if ( V_5 -> V_90 != NULL ) {
F_64 ( & V_5 -> V_144 -> V_73 , V_5 -> V_90 ) ;
V_5 -> V_90 = NULL ;
}
return 0 ;
}
static void F_65 ( struct V_4 * V_5 )
__releases( V_5 -> V_126 )
__acquires( V_5 -> V_126 )
{
int V_132 ;
F_51 ( & V_5 -> V_126 ) ;
if ( V_5 -> V_138 . V_139 != V_140 )
F_66 ( & V_5 -> V_138 , V_5 -> V_145 ) ;
V_132 = F_60 ( & V_5 -> V_138 ) ;
if ( V_132 )
goto V_95;
V_132 = F_26 ( V_5 ) ;
if ( V_132 )
goto V_95;
V_5 -> V_90 = F_67 ( & V_5 -> V_144 -> V_73 , V_63 ) ;
if ( V_5 -> V_90 == NULL )
V_132 = - V_64 ;
V_95:
F_53 ( & V_5 -> V_126 ) ;
if ( V_132 )
F_68 ( V_5 -> V_92 , L_1 , V_132 ) ;
}
static void F_69 ( struct V_129 * V_73 , struct V_146 * V_72 )
{
if ( V_73 == NULL || V_72 == NULL )
return;
F_31 ( V_72 -> V_147 ) ;
F_64 ( V_73 , V_72 ) ;
}
static int F_70 ( struct V_129 * V_73 , struct V_146 * V_72 ,
T_3 T_4 V_148 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
struct V_4 * V_5 = V_54 -> V_5 ;
int V_132 = 0 ;
if ( V_73 == NULL || V_72 == NULL || V_54 -> V_73 . V_134 == NULL )
return - V_36 ;
if ( V_54 -> type == V_111 ) {
if ( V_72 -> V_57 )
V_54 = ( V_5 -> V_149 == V_31 ) ?
V_5 -> V_143 : V_5 -> V_144 ;
if ( ! F_33 ( & V_54 -> V_101 . V_102 ) ) {
F_50 ( V_54 ) ;
F_71 ( V_54 -> V_5 -> V_92 , L_2 ,
F_37 ( V_54 ) ) ;
}
}
if ( F_56 ( V_54 -> V_73 . V_134 ) &&
V_56 -> V_72 . V_57 > V_54 -> V_73 . V_150 * V_54 -> V_73 . V_74 ) {
F_68 ( V_54 -> V_5 -> V_92 , L_3 ) ;
return - V_151 ;
}
if ( ! F_33 ( & V_56 -> V_102 ) ) {
F_68 ( V_54 -> V_5 -> V_92 , L_4 ) ;
return - V_119 ;
}
V_56 -> V_72 . V_90 = - V_152 ;
V_56 -> V_72 . V_76 = 0 ;
V_132 = F_38 ( V_54 , V_56 ) ;
if ( V_132 == - V_91 )
V_132 = 0 ;
if ( ! V_132 )
F_36 ( & V_56 -> V_102 , & V_54 -> V_101 . V_102 ) ;
return V_132 ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_153 * V_154 )
__releases( V_54 -> V_126 )
__acquires( V_54 -> V_126 )
{
struct V_53 * V_54 = V_5 -> V_144 ;
struct V_146 * V_72 = NULL ;
T_3 V_148 = V_63 ;
int V_2 , V_1 , V_132 ;
if ( V_54 == NULL || V_154 == NULL )
return - V_36 ;
F_51 ( V_54 -> V_126 ) ;
V_72 = F_67 ( & V_54 -> V_73 , V_148 ) ;
F_53 ( V_54 -> V_126 ) ;
if ( V_72 == NULL )
return - V_64 ;
V_72 -> V_128 = F_69 ;
V_72 -> V_57 = 2 ;
V_72 -> V_147 = F_29 ( V_72 -> V_57 , V_148 ) ;
if ( V_72 -> V_147 == NULL ) {
V_132 = - V_64 ;
goto V_155;
}
if ( ( V_154 -> V_156 & V_157 ) == V_158 ) {
* ( V_159 * ) V_72 -> V_147 = ( V_5 -> V_141 << 1 ) |
V_5 -> V_138 . V_160 ;
} else if ( ( V_154 -> V_156 & V_157 ) \
== V_161 ) {
V_2 = ( F_73 ( V_154 -> V_162 ) & V_85 ) ?
V_3 : V_31 ;
V_1 = F_73 ( V_154 -> V_162 ) & V_163 ;
* ( V_159 * ) V_72 -> V_147 = F_12 ( V_5 , V_1 , V_2 ) ;
}
V_132 = F_70 ( & V_54 -> V_73 , V_72 , V_148 ) ;
if ( V_132 )
goto V_164;
return 0 ;
V_164:
F_31 ( V_72 -> V_147 ) ;
V_155:
F_51 ( V_54 -> V_126 ) ;
F_64 ( & V_54 -> V_73 , V_72 ) ;
F_53 ( V_54 -> V_126 ) ;
return V_132 ;
}
static void
F_74 ( struct V_129 * V_73 , struct V_146 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_165 ;
unsigned long V_133 ;
if ( V_5 -> V_166 ) {
F_25 ( V_5 , V_5 -> V_167 ) ;
V_5 -> V_166 = false ;
if ( V_5 -> V_167 )
F_75 ( & V_5 -> V_138 , V_168 ) ;
}
F_57 ( & V_5 -> V_126 , V_133 ) ;
if ( V_5 -> V_169 )
F_76 ( V_5 , V_5 -> V_169 ) ;
F_59 ( & V_5 -> V_126 , V_133 ) ;
}
static int F_77 ( struct V_4 * V_5 )
{
int V_132 ;
struct V_53 * V_54 ;
if ( F_78 ( ! V_5 -> V_90 ) )
return - V_121 ;
V_54 = ( V_5 -> V_149 == V_3 ) ? V_5 -> V_143 : V_5 -> V_144 ;
V_5 -> V_90 -> V_165 = V_5 ;
V_5 -> V_90 -> V_128 = F_74 ;
V_132 = F_70 ( & V_54 -> V_73 , V_5 -> V_90 , V_63 ) ;
return V_132 ;
}
static int F_79 ( struct V_53 * V_54 )
__releases( V_54 -> V_126 )
__acquires( V_54 -> V_126 )
{
struct V_55 * V_56 , * V_170 ;
struct V_53 * V_171 = V_54 ;
int V_132 = 0 ;
F_46 (hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
V_132 = F_45 ( V_54 , V_56 ) ;
if ( V_132 < 0 )
break;
F_48 ( & V_56 -> V_102 ) ;
if ( V_56 -> V_72 . V_128 != NULL ) {
F_51 ( V_54 -> V_126 ) ;
if ( ( V_54 -> type == V_111 ) &&
V_56 -> V_72 . V_57 )
V_171 = V_54 -> V_5 -> V_144 ;
F_52 ( & V_171 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_126 ) ;
}
}
if ( V_132 == - V_119 )
V_132 = 0 ;
return V_132 ;
}
static int F_80 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_138 . V_92 ,
L_5 ) ;
return F_77 ( V_5 ) ;
}
static void F_81 ( struct V_4 * V_5 )
__releases( V_5 -> V_126 )
__acquires( V_5 -> V_126 )
{
struct V_53 * V_54 = & V_5 -> V_53 [ 0 ] ;
struct V_153 V_72 ;
int type , V_1 , V_2 , V_172 = - V_36 ;
T_2 V_173 = 0 ;
F_50 ( V_5 -> V_143 ) ;
F_50 ( V_5 -> V_144 ) ;
do {
F_24 ( V_5 ) ;
memcpy ( & V_72 , & V_54 -> V_101 . V_65 -> V_154 , sizeof( V_72 ) ) ;
} while ( ! F_22 ( V_5 ) );
type = V_72 . V_156 ;
V_5 -> V_149 = ( type & V_174 ) ? V_3 : V_31 ;
switch ( V_72 . V_175 ) {
case V_176 :
if ( type == ( V_177 | V_161 ) &&
F_73 ( V_72 . V_178 ) ==
V_179 ) {
if ( V_72 . V_180 != 0 )
break;
V_1 = F_73 ( V_72 . V_162 ) ;
V_2 = ( V_1 & V_85 ) ? V_3 : V_31 ;
V_1 &= V_163 ;
if ( V_2 == V_3 )
V_1 += V_5 -> V_8 / 2 ;
if ( ! V_5 -> V_53 [ V_1 ] . V_136 ) {
F_51 ( & V_5 -> V_126 ) ;
V_172 = F_82 (
& V_5 -> V_53 [ V_1 ] . V_73 ) ;
F_53 ( & V_5 -> V_126 ) ;
if ( V_172 )
break;
}
V_172 = F_77 ( V_5 ) ;
} else if ( type == ( V_177 | V_158 ) &&
F_73 ( V_72 . V_178 ) ==
V_181 ) {
if ( V_72 . V_180 != 0 )
break;
V_5 -> V_141 = 0 ;
V_172 = F_77 ( V_5 ) ;
} else {
goto V_182;
}
break;
case V_183 :
if ( ( type != ( V_174 | V_158 ) ||
F_73 ( V_72 . V_162 ) == V_184 ) &&
type != ( V_174 | V_161 ) &&
type != ( V_174 | V_185 ) )
goto V_182;
if ( F_73 ( V_72 . V_180 ) != 2 ||
F_73 ( V_72 . V_178 ) != 0 )
break;
V_172 = F_72 ( V_5 , & V_72 ) ;
break;
case V_186 :
if ( type != ( V_177 | V_158 ) )
goto V_182;
if ( F_73 ( V_72 . V_180 ) != 0 ||
F_73 ( V_72 . V_162 ) != 0 )
break;
V_5 -> V_167 = ( T_2 ) F_73 ( V_72 . V_178 ) ;
V_5 -> V_166 = true ;
V_172 = F_77 ( V_5 ) ;
break;
case V_187 :
if ( type == ( V_177 | V_161 ) &&
F_73 ( V_72 . V_178 ) ==
V_179 ) {
if ( V_72 . V_180 != 0 )
break;
V_1 = F_73 ( V_72 . V_162 ) ;
V_2 = ( V_1 & V_85 ) ? V_3 : V_31 ;
V_1 &= V_163 ;
if ( V_2 == V_3 )
V_1 += V_5 -> V_8 / 2 ;
F_51 ( & V_5 -> V_126 ) ;
V_172 = F_54 ( & V_5 -> V_53 [ V_1 ] . V_73 , 1 , false ) ;
F_53 ( & V_5 -> V_126 ) ;
if ( ! V_172 )
F_77 ( V_5 ) ;
} else if ( type == ( V_177 | V_158 ) ) {
if ( V_72 . V_180 != 0 )
break;
switch ( F_73 ( V_72 . V_178 ) ) {
case V_181 :
V_5 -> V_141 = 1 ;
V_172 = F_77 ( V_5 ) ;
break;
case V_188 :
V_173 = F_73 ( V_72 . V_162 ) >> 8 ;
switch ( V_173 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
V_5 -> V_169 = V_173 ;
V_172 = F_77 (
V_5 ) ;
break;
default:
break;
}
break;
case V_194 :
if ( F_83 ( V_5 ) ) {
V_5 -> V_138 . V_195 = 1 ;
V_172 = F_77 (
V_5 ) ;
}
break;
case V_196 :
if ( F_83 ( V_5 ) )
V_172 = F_80 ( V_5 ) ;
break;
case V_197 :
if ( F_83 ( V_5 ) ) {
V_5 -> V_138 . V_198 = 1 ;
V_172 = F_77 (
V_5 ) ;
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
V_5 -> V_149 = V_3 ;
F_51 ( & V_5 -> V_126 ) ;
V_172 = V_5 -> V_145 -> V_154 ( & V_5 -> V_138 , & V_72 ) ;
F_53 ( & V_5 -> V_126 ) ;
break;
}
if ( V_172 < 0 ) {
F_51 ( & V_5 -> V_126 ) ;
if ( F_54 ( & V_54 -> V_73 , 1 , false ) )
F_68 ( V_5 -> V_92 , L_6 ) ;
F_53 ( & V_5 -> V_126 ) ;
}
}
static void F_84 ( struct V_4 * V_5 )
__releases( V_5 -> V_126 )
__acquires( V_5 -> V_126 )
{
unsigned V_58 ;
int V_172 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 ; V_58 ++ ) {
struct V_53 * V_54 = & V_5 -> V_53 [ V_58 ] ;
if ( V_54 -> V_73 . V_134 == NULL )
continue;
if ( F_17 ( V_5 , V_58 ) ) {
V_172 = F_79 ( V_54 ) ;
if ( V_54 -> type == V_111 ) {
if ( V_172 > 0 )
V_172 = F_77 ( V_5 ) ;
if ( V_172 < 0 ) {
F_51 ( & V_5 -> V_126 ) ;
if ( F_54 ( & V_54 -> V_73 , 1 , false ) )
F_68 ( V_5 -> V_92 ,
L_6 ) ;
F_53 ( & V_5 -> V_126 ) ;
}
}
}
if ( V_58 == 0 &&
F_18 ( V_5 , V_32 , F_6 ( 0 ) ) )
F_81 ( V_5 ) ;
}
}
static int F_85 ( struct V_129 * V_73 ,
const struct V_199 * V_134 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_132 = 0 ;
unsigned long V_133 ;
T_1 V_109 = 0 ;
if ( V_73 == NULL || V_134 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
if ( ! F_33 ( & V_54 -> V_101 . V_102 ) ) {
F_71 ( V_54 -> V_5 -> V_92 , L_7 ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return - V_119 ;
}
V_54 -> V_73 . V_134 = V_134 ;
V_54 -> V_2 = F_86 ( V_134 ) ? V_3 : V_31 ;
V_54 -> V_1 = F_87 ( V_134 ) ;
V_54 -> type = F_88 ( V_134 ) ;
V_54 -> V_73 . V_74 = F_89 ( V_134 ) ;
V_54 -> V_73 . V_150 = F_90 ( V_134 ) ;
if ( V_54 -> type == V_111 )
V_109 |= V_200 ;
V_109 |= V_201 ;
V_109 |= ( V_54 -> V_73 . V_74 << F_11 ( V_202 ) ) & V_202 ;
if ( V_54 -> type == V_70 && V_54 -> V_2 == V_3 )
V_109 |= 3 << F_11 ( V_110 ) ;
V_54 -> V_101 . V_65 -> V_109 = F_32 ( V_109 ) ;
V_54 -> V_101 . V_65 -> V_83 . V_84 |= F_32 ( V_98 ) ;
if ( V_54 -> V_1 != 0 && V_54 -> type == V_111 ) {
F_68 ( V_54 -> V_5 -> V_92 , L_8 ) ;
V_132 = - V_36 ;
}
if ( V_54 -> V_1 )
V_132 |= F_10 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ,
V_54 -> type ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_91 ( struct V_129 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_131 , V_132 = 0 ;
unsigned long V_133 ;
if ( V_73 == NULL )
return - V_36 ;
else if ( V_54 -> V_73 . V_134 == NULL )
return - V_119 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
V_131 = V_54 -> V_2 ;
do {
V_132 |= F_50 ( V_54 ) ;
V_132 |= F_9 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
if ( V_54 -> type == V_111 )
V_54 -> V_2 = ( V_54 -> V_2 == V_3 ) ? V_31 : V_3 ;
} while ( V_54 -> V_2 != V_131 );
V_54 -> V_73 . V_134 = NULL ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return V_132 ;
}
static struct V_146 * F_92 ( struct V_129 * V_73 , T_3 V_148 )
{
struct V_55 * V_56 = NULL ;
if ( V_73 == NULL )
return NULL ;
V_56 = F_29 ( sizeof( struct V_55 ) , V_148 ) ;
if ( V_56 != NULL ) {
F_35 ( & V_56 -> V_102 ) ;
F_35 ( & V_56 -> V_81 ) ;
}
return ( V_56 == NULL ) ? NULL : & V_56 -> V_72 ;
}
static void F_93 ( struct V_129 * V_73 , struct V_146 * V_72 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
struct V_60 * V_62 , * V_115 ;
unsigned long V_133 ;
if ( V_73 == NULL || V_72 == NULL ) {
return;
} else if ( ! F_33 ( & V_56 -> V_102 ) ) {
F_68 ( V_54 -> V_5 -> V_92 , L_9 ) ;
return;
}
F_57 ( V_54 -> V_126 , V_133 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_48 ( & V_62 -> V_83 ) ;
V_62 -> V_65 = NULL ;
F_31 ( V_62 ) ;
}
F_31 ( V_56 ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
}
static int F_94 ( struct V_129 * V_73 , struct V_146 * V_72 ,
T_3 T_4 V_148 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
int V_132 = 0 ;
unsigned long V_133 ;
if ( V_73 == NULL || V_72 == NULL || V_54 -> V_73 . V_134 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
V_132 = F_70 ( V_73 , V_72 , V_148 ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return V_132 ;
}
static int F_95 ( struct V_129 * V_73 , struct V_146 * V_72 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
struct V_55 * V_56 = F_55 ( V_72 , struct V_55 , V_72 ) ;
unsigned long V_133 ;
struct V_60 * V_62 , * V_115 ;
if ( V_73 == NULL || V_72 == NULL || V_56 -> V_72 . V_90 != - V_91 ||
V_54 -> V_73 . V_134 == NULL || F_33 ( & V_56 -> V_102 ) ||
F_33 ( & V_54 -> V_101 . V_102 ) )
return - V_36 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_46 (node, tmpnode, &hwreq->tds, td) {
F_43 ( V_54 -> V_66 , V_62 -> V_65 , V_62 -> V_9 ) ;
F_96 ( & V_62 -> V_83 ) ;
F_31 ( V_62 ) ;
}
F_48 ( & V_56 -> V_102 ) ;
F_97 ( & V_54 -> V_5 -> V_138 , V_72 , V_54 -> V_2 ) ;
V_72 -> V_90 = - V_203 ;
if ( V_56 -> V_72 . V_128 != NULL ) {
F_51 ( V_54 -> V_126 ) ;
F_52 ( & V_54 -> V_73 , & V_56 -> V_72 ) ;
F_53 ( V_54 -> V_126 ) ;
}
F_59 ( V_54 -> V_126 , V_133 ) ;
return 0 ;
}
static int F_98 ( struct V_129 * V_73 , int V_35 )
{
return F_54 ( V_73 , V_35 , true ) ;
}
static int F_99 ( struct V_129 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
unsigned long V_133 ;
if ( V_73 == NULL || V_54 -> V_73 . V_134 == NULL )
return - V_36 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
V_54 -> V_136 = 1 ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return F_100 ( V_73 ) ;
}
static void F_101 ( struct V_129 * V_73 )
{
struct V_53 * V_54 = F_55 ( V_73 , struct V_53 , V_73 ) ;
unsigned long V_133 ;
if ( V_73 == NULL ) {
F_68 ( V_54 -> V_5 -> V_92 , L_10 , F_37 ( V_54 ) ) ;
return;
}
F_57 ( V_54 -> V_126 , V_133 ) ;
F_5 ( V_54 -> V_5 , V_54 -> V_1 , V_54 -> V_2 ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
}
static int F_102 ( struct V_137 * V_204 , int V_205 )
{
struct V_4 * V_5 = F_55 ( V_204 , struct V_4 , V_138 ) ;
unsigned long V_133 ;
int V_206 = 0 ;
F_57 ( & V_5 -> V_126 , V_133 ) ;
V_5 -> V_207 = V_205 ;
if ( V_5 -> V_145 )
V_206 = 1 ;
F_59 ( & V_5 -> V_126 , V_133 ) ;
if ( V_206 ) {
if ( V_205 ) {
F_103 ( & V_204 -> V_92 ) ;
F_104 ( V_5 ) ;
F_3 ( V_5 , V_5 -> V_143 -> V_101 . V_9 ) ;
F_75 ( V_204 , V_208 ) ;
F_105 ( V_204 , true ) ;
} else {
F_105 ( V_204 , false ) ;
if ( V_5 -> V_145 )
V_5 -> V_145 -> V_209 ( & V_5 -> V_138 ) ;
F_3 ( V_5 , 0 ) ;
if ( V_5 -> V_210 -> V_211 )
V_5 -> V_210 -> V_211 ( V_5 ,
V_212 ) ;
F_60 ( & V_5 -> V_138 ) ;
F_106 ( & V_204 -> V_92 ) ;
F_75 ( V_204 , V_213 ) ;
}
}
return 0 ;
}
static int F_107 ( struct V_137 * V_204 )
{
struct V_4 * V_5 = F_55 ( V_204 , struct V_4 , V_138 ) ;
unsigned long V_133 ;
int V_86 = 0 ;
F_57 ( & V_5 -> V_126 , V_133 ) ;
if ( ! V_5 -> V_141 ) {
V_86 = - V_135 ;
goto V_214;
}
if ( ! F_7 ( V_5 , V_45 , V_215 ) ) {
V_86 = - V_36 ;
goto V_214;
}
F_4 ( V_5 , V_45 , V_216 , V_216 ) ;
V_214:
F_59 ( & V_5 -> V_126 , V_133 ) ;
return V_86 ;
}
static int F_108 ( struct V_137 * V_204 , unsigned V_217 )
{
struct V_4 * V_5 = F_55 ( V_204 , struct V_4 , V_138 ) ;
if ( V_5 -> V_218 )
return F_109 ( V_5 -> V_218 , V_217 ) ;
return - V_219 ;
}
static int F_110 ( struct V_137 * V_204 , int V_220 )
{
struct V_4 * V_5 = F_55 ( V_204 , struct V_4 , V_138 ) ;
struct V_53 * V_54 = V_5 -> V_144 ;
unsigned long V_133 ;
F_57 ( V_54 -> V_126 , V_133 ) ;
V_204 -> V_160 = ( V_220 != 0 ) ;
F_59 ( V_54 -> V_126 , V_133 ) ;
return 0 ;
}
static int F_111 ( struct V_137 * V_204 , int V_220 )
{
struct V_4 * V_5 = F_55 ( V_204 , struct V_4 , V_138 ) ;
if ( F_83 ( V_5 ) || V_5 -> V_221 == V_222 )
return 0 ;
F_103 ( & V_5 -> V_138 . V_92 ) ;
if ( V_220 )
F_4 ( V_5 , V_49 , V_223 , V_223 ) ;
else
F_4 ( V_5 , V_49 , V_223 , 0 ) ;
F_106 ( & V_5 -> V_138 . V_92 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 )
{
int V_132 = 0 , V_58 , V_224 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 / 2 ; V_58 ++ )
for ( V_224 = V_31 ; V_224 <= V_3 ; V_224 ++ ) {
int V_225 = V_58 + V_224 * V_5 -> V_8 / 2 ;
struct V_53 * V_54 = & V_5 -> V_53 [ V_225 ] ;
F_113 ( V_54 -> V_226 , sizeof( V_54 -> V_226 ) , L_11 , V_58 ,
( V_224 == V_3 ) ? L_12 : L_13 ) ;
V_54 -> V_5 = V_5 ;
V_54 -> V_126 = & V_5 -> V_126 ;
V_54 -> V_66 = V_5 -> V_66 ;
V_54 -> V_73 . V_226 = V_54 -> V_226 ;
V_54 -> V_73 . V_227 = & V_228 ;
if ( V_58 == 0 ) {
V_54 -> V_73 . V_229 . V_230 = true ;
} else {
V_54 -> V_73 . V_229 . V_231 = true ;
V_54 -> V_73 . V_229 . V_232 = true ;
V_54 -> V_73 . V_229 . V_233 = true ;
}
if ( V_224 == V_3 )
V_54 -> V_73 . V_229 . V_234 = true ;
else
V_54 -> V_73 . V_229 . V_235 = true ;
F_114 ( & V_54 -> V_73 , ( unsigned short ) ~ 0 ) ;
F_35 ( & V_54 -> V_101 . V_102 ) ;
V_54 -> V_101 . V_65 = F_30 ( V_5 -> V_236 , V_237 ,
& V_54 -> V_101 . V_9 ) ;
if ( V_54 -> V_101 . V_65 == NULL )
V_132 = - V_64 ;
if ( V_58 == 0 ) {
if ( V_224 == V_31 )
V_5 -> V_143 = V_54 ;
else
V_5 -> V_144 = V_54 ;
F_114 ( & V_54 -> V_73 , V_238 ) ;
continue;
}
F_36 ( & V_54 -> V_73 . V_239 , & V_5 -> V_138 . V_239 ) ;
}
return V_132 ;
}
static void F_115 ( struct V_4 * V_5 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_5 -> V_8 ; V_58 ++ ) {
struct V_53 * V_54 = & V_5 -> V_53 [ V_58 ] ;
if ( V_54 -> V_113 )
F_42 ( V_54 ) ;
F_43 ( V_5 -> V_236 , V_54 -> V_101 . V_65 , V_54 -> V_101 . V_9 ) ;
}
}
static int F_116 ( struct V_137 * V_138 ,
struct V_240 * V_145 )
{
struct V_4 * V_5 = F_55 ( V_138 , struct V_4 , V_138 ) ;
int V_132 = - V_64 ;
if ( V_145 -> V_209 == NULL )
return - V_36 ;
V_5 -> V_143 -> V_73 . V_134 = & V_241 ;
V_132 = F_117 ( & V_5 -> V_143 -> V_73 ) ;
if ( V_132 )
return V_132 ;
V_5 -> V_144 -> V_73 . V_134 = & V_242 ;
V_132 = F_117 ( & V_5 -> V_144 -> V_73 ) ;
if ( V_132 )
return V_132 ;
V_5 -> V_145 = V_145 ;
if ( F_83 ( V_5 ) && V_5 -> V_243 . V_244 ) {
F_118 ( V_5 ) ;
return V_132 ;
}
F_103 ( & V_5 -> V_138 . V_92 ) ;
if ( V_5 -> V_207 ) {
F_104 ( V_5 ) ;
} else {
F_105 ( & V_5 -> V_138 , false ) ;
F_106 ( & V_5 -> V_138 . V_92 ) ;
return V_132 ;
}
V_132 = F_3 ( V_5 , V_5 -> V_143 -> V_101 . V_9 ) ;
if ( V_132 )
F_106 ( & V_5 -> V_138 . V_92 ) ;
return V_132 ;
}
static void F_119 ( struct V_4 * V_5 )
{
if ( ! F_83 ( V_5 ) )
return;
F_120 ( & V_5 -> V_243 . V_126 ) ;
if ( V_5 -> V_243 . V_245 -> V_246 == V_247 ) {
V_5 -> V_243 . V_248 = 1 ;
F_118 ( V_5 ) ;
} else if ( V_5 -> V_243 . V_245 -> V_246 == V_249 ) {
V_5 -> V_243 . V_250 = V_251 ;
V_5 -> V_243 . V_245 -> V_246 = V_252 ;
}
F_121 ( & V_5 -> V_243 . V_126 ) ;
}
static int F_122 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = F_55 ( V_138 , struct V_4 , V_138 ) ;
unsigned long V_133 ;
F_57 ( & V_5 -> V_126 , V_133 ) ;
if ( V_5 -> V_207 ) {
F_3 ( V_5 , 0 ) ;
F_59 ( & V_5 -> V_126 , V_133 ) ;
if ( V_5 -> V_210 -> V_211 )
V_5 -> V_210 -> V_211 ( V_5 ,
V_212 ) ;
F_60 ( & V_5 -> V_138 ) ;
F_57 ( & V_5 -> V_126 , V_133 ) ;
F_123 ( & V_5 -> V_138 . V_92 ) ;
}
V_5 -> V_145 = NULL ;
F_59 ( & V_5 -> V_126 , V_133 ) ;
F_119 ( V_5 ) ;
return 0 ;
}
static T_5 F_124 ( struct V_4 * V_5 )
{
T_5 V_132 ;
T_1 V_253 ;
if ( V_5 == NULL )
return V_254 ;
F_53 ( & V_5 -> V_126 ) ;
if ( V_5 -> V_210 -> V_133 & V_255 ) {
if ( F_7 ( V_5 , V_256 , V_257 ) !=
V_258 ) {
F_51 ( & V_5 -> V_126 ) ;
return V_259 ;
}
}
V_253 = F_19 ( V_5 ) ;
if ( V_253 ) {
if ( V_15 & V_253 )
F_65 ( V_5 ) ;
if ( V_14 & V_253 ) {
V_5 -> V_138 . V_139 = F_16 ( V_5 ) ?
V_260 : V_261 ;
if ( V_5 -> V_142 ) {
if ( V_5 -> V_145 -> V_262 ) {
F_51 ( & V_5 -> V_126 ) ;
V_5 -> V_145 -> V_262 ( & V_5 -> V_138 ) ;
F_53 ( & V_5 -> V_126 ) ;
}
V_5 -> V_142 = 0 ;
F_75 ( & V_5 -> V_138 ,
V_5 -> V_263 ) ;
}
}
if ( V_12 & V_253 )
F_84 ( V_5 ) ;
if ( ( V_16 & V_253 ) && ! ( V_5 -> V_142 ) ) {
V_5 -> V_142 = 1 ;
V_5 -> V_263 = V_5 -> V_138 . V_246 ;
if ( V_5 -> V_138 . V_139 != V_140 &&
V_5 -> V_145 -> V_264 ) {
F_51 ( & V_5 -> V_126 ) ;
V_5 -> V_145 -> V_264 ( & V_5 -> V_138 ) ;
F_53 ( & V_5 -> V_126 ) ;
}
F_75 ( & V_5 -> V_138 ,
V_265 ) ;
}
V_132 = V_254 ;
} else {
V_132 = V_259 ;
}
F_51 ( & V_5 -> V_126 ) ;
return V_132 ;
}
static int F_125 ( struct V_4 * V_5 )
{
struct V_266 * V_92 = V_5 -> V_92 ;
struct V_267 * V_268 = & V_5 -> V_210 -> V_269 ;
int V_132 = 0 ;
V_5 -> V_138 . V_227 = & V_270 ;
V_5 -> V_138 . V_139 = V_140 ;
V_5 -> V_138 . V_271 = V_260 ;
V_5 -> V_138 . V_226 = V_5 -> V_210 -> V_226 ;
V_5 -> V_138 . V_268 = V_268 ;
if ( V_5 -> V_272 && ( V_268 -> V_273 || V_268 -> V_274 ||
V_268 -> V_275 ) )
V_5 -> V_138 . V_272 = 1 ;
F_35 ( & V_5 -> V_138 . V_239 ) ;
V_5 -> V_236 = F_126 ( L_14 , V_92 -> V_93 ,
sizeof( struct V_276 ) ,
64 , V_79 ) ;
if ( V_5 -> V_236 == NULL )
return - V_64 ;
V_5 -> V_66 = F_126 ( L_15 , V_92 -> V_93 ,
sizeof( struct V_277 ) ,
64 , V_79 ) ;
if ( V_5 -> V_66 == NULL ) {
V_132 = - V_64 ;
goto V_278;
}
V_132 = F_112 ( V_5 ) ;
if ( V_132 )
goto V_279;
V_5 -> V_138 . V_280 = & V_5 -> V_144 -> V_73 ;
V_132 = F_127 ( V_92 , & V_5 -> V_138 ) ;
if ( V_132 )
goto F_115;
F_128 ( & V_5 -> V_138 . V_92 ) ;
F_129 ( & V_5 -> V_138 . V_92 ) ;
return V_132 ;
F_115:
F_115 ( V_5 ) ;
V_279:
F_130 ( V_5 -> V_66 ) ;
V_278:
F_130 ( V_5 -> V_236 ) ;
return V_132 ;
}
void F_131 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_281 [ V_282 ] )
return;
F_132 ( & V_5 -> V_138 ) ;
F_115 ( V_5 ) ;
F_130 ( V_5 -> V_66 ) ;
F_130 ( V_5 -> V_236 ) ;
}
static int F_133 ( struct V_4 * V_5 )
{
if ( V_5 -> V_272 )
F_134 ( V_5 , V_283 | V_284 ,
V_283 | V_284 ) ;
return 0 ;
}
static void F_135 ( struct V_4 * V_5 )
{
if ( V_5 -> V_272 )
F_134 ( V_5 , V_284 | V_283 , V_283 ) ;
V_5 -> V_207 = 0 ;
}
int F_136 ( struct V_4 * V_5 )
{
struct V_285 * V_286 ;
int V_86 ;
if ( ! F_7 ( V_5 , V_287 , V_288 ) )
return - V_289 ;
V_286 = F_137 ( V_5 -> V_92 , sizeof( * V_286 ) , V_237 ) ;
if ( ! V_286 )
return - V_64 ;
V_286 -> V_290 = F_133 ;
V_286 -> V_291 = F_135 ;
V_286 -> V_292 = F_124 ;
V_286 -> V_226 = L_16 ;
V_86 = F_125 ( V_5 ) ;
if ( ! V_86 )
V_5 -> V_281 [ V_282 ] = V_286 ;
return V_86 ;
}
