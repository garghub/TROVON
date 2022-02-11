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
static void F_22 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_48 , V_49 , V_49 ) ;
F_4 ( V_4 , V_48 , V_50 , V_50 ) ;
F_23 ( V_4 -> V_51 , & V_4 -> V_52 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_48 , V_50 , 0 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
return F_26 ( V_4 , V_53 , V_54 , 0 ) ;
}
static int F_27 ( struct V_3 * V_4 )
{
return F_26 ( V_4 , V_53 , V_54 , V_54 ) ;
}
static void F_28 ( struct V_3 * V_4 , T_2 V_34 )
{
F_4 ( V_4 , V_55 , V_56 ,
V_34 << F_11 ( V_56 ) ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
F_28 ( V_4 , 0 ) ;
F_4 ( V_4 , V_16 , ~ 0 , ~ 0 ) ;
F_4 ( V_4 , V_29 , 0 , 0 ) ;
F_4 ( V_4 , V_47 , 0 , 0 ) ;
while ( F_7 ( V_4 , V_33 , ~ 0 ) )
F_30 ( 10 ) ;
return 0 ;
}
static void V_52 ( struct V_57 * V_58 )
{
struct V_3 * V_4 = F_31 ( V_58 , struct V_3 , V_52 ) ;
if ( F_7 ( V_4 , V_48 , V_59 ) )
F_32 ( & V_4 -> V_60 ) ;
else
F_33 ( & V_4 -> V_60 ) ;
}
static inline T_2 F_34 ( struct V_61 * V_62 )
{
return ( ( V_62 -> V_2 == V_63 ) ? V_64 : 0 ) | V_62 -> V_1 ;
}
static int F_35 ( struct V_61 * V_65 , struct V_66 * V_67 )
{
struct V_3 * V_4 = V_65 -> V_4 ;
unsigned V_68 ;
int V_69 = 0 ;
unsigned V_70 = V_67 -> V_71 . V_70 ;
if ( V_67 -> V_71 . V_72 == - V_73 )
return - V_73 ;
V_67 -> V_71 . V_72 = - V_73 ;
if ( V_67 -> V_71 . V_74 && V_70 && ( V_70 % V_65 -> V_62 . V_75 == 0 ) ) {
V_67 -> V_76 = F_36 ( V_65 -> V_77 , V_78 ,
& V_67 -> V_79 ) ;
if ( V_67 -> V_76 == NULL )
return - V_80 ;
memset ( V_67 -> V_76 , 0 , sizeof( * V_67 -> V_76 ) ) ;
V_67 -> V_76 -> V_81 = V_82 ;
V_67 -> V_76 -> V_83 = V_84 ;
if ( ! V_67 -> V_71 . V_85 )
V_67 -> V_76 -> V_83 |= V_86 ;
}
V_69 = F_37 ( & V_4 -> V_60 , & V_67 -> V_71 , V_65 -> V_2 ) ;
if ( V_69 )
return V_69 ;
memset ( V_67 -> V_87 , 0 , sizeof( * V_67 -> V_87 ) ) ;
V_67 -> V_87 -> V_83 = V_70 << F_11 ( V_88 ) ;
V_67 -> V_87 -> V_83 &= V_88 ;
V_67 -> V_87 -> V_83 |= V_84 ;
if ( V_67 -> V_76 ) {
V_67 -> V_87 -> V_81 = V_67 -> V_79 ;
} else {
V_67 -> V_87 -> V_81 = V_82 ;
if ( ! V_67 -> V_71 . V_85 )
V_67 -> V_87 -> V_83 |= V_86 ;
}
V_67 -> V_87 -> V_89 [ 0 ] = V_67 -> V_71 . V_8 ;
for ( V_68 = 1 ; V_68 < 5 ; V_68 ++ )
V_67 -> V_87 -> V_89 [ V_68 ] =
( V_67 -> V_71 . V_8 + V_68 * V_90 ) & ~ V_91 ;
if ( ! F_38 ( & V_65 -> V_92 . V_93 ) ) {
struct V_66 * V_94 ;
int V_5 = F_1 ( V_65 -> V_1 , V_65 -> V_2 ) ;
int V_95 ;
V_94 = F_39 ( V_65 -> V_92 . V_93 . V_96 ,
struct V_66 , V_93 ) ;
if ( V_94 -> V_76 )
V_94 -> V_76 -> V_81 = V_67 -> V_8 & V_97 ;
else
V_94 -> V_87 -> V_81 = V_67 -> V_8 & V_97 ;
F_40 () ;
if ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
goto V_98;
do {
F_4 ( V_4 , V_53 , V_99 , V_99 ) ;
V_95 = F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_53 , V_99 ) );
F_4 ( V_4 , V_53 , V_99 , 0 ) ;
if ( V_95 )
goto V_98;
}
V_65 -> V_92 . V_87 -> V_100 . V_81 = V_67 -> V_8 ;
V_65 -> V_92 . V_87 -> V_100 . V_83 &= ~ V_101 ;
V_65 -> V_92 . V_87 -> V_102 |= V_103 ;
F_40 () ;
V_69 = F_15 ( V_4 , V_65 -> V_1 , V_65 -> V_2 ,
V_65 -> type == V_104 ) ;
V_98:
return V_69 ;
}
static int F_41 ( struct V_61 * V_65 , struct V_66 * V_67 )
{
if ( V_67 -> V_71 . V_72 != - V_73 )
return - V_35 ;
if ( ( V_84 & V_67 -> V_87 -> V_83 ) != 0 )
return - V_105 ;
if ( V_67 -> V_76 ) {
if ( ( V_84 & V_67 -> V_76 -> V_83 ) != 0 )
return - V_105 ;
F_42 ( V_65 -> V_77 , V_67 -> V_76 , V_67 -> V_79 ) ;
V_67 -> V_76 = NULL ;
}
V_67 -> V_71 . V_72 = 0 ;
F_43 ( & V_65 -> V_4 -> V_60 , & V_67 -> V_71 , V_65 -> V_2 ) ;
V_67 -> V_71 . V_72 = V_67 -> V_87 -> V_83 & V_101 ;
if ( ( V_106 & V_67 -> V_71 . V_72 ) != 0 )
V_67 -> V_71 . V_72 = - 1 ;
else if ( ( V_107 & V_67 -> V_71 . V_72 ) != 0 )
V_67 -> V_71 . V_72 = - 1 ;
else if ( ( V_108 & V_67 -> V_71 . V_72 ) != 0 )
V_67 -> V_71 . V_72 = - 1 ;
V_67 -> V_71 . V_109 = V_67 -> V_87 -> V_83 & V_88 ;
V_67 -> V_71 . V_109 >>= F_11 ( V_88 ) ;
V_67 -> V_71 . V_109 = V_67 -> V_71 . V_70 - V_67 -> V_71 . V_109 ;
V_67 -> V_71 . V_109 = V_67 -> V_71 . V_72 ? 0 : V_67 -> V_71 . V_109 ;
return V_67 -> V_71 . V_109 ;
}
static int F_44 ( struct V_61 * V_65 )
__releases( V_65 -> V_110 )
__acquires( V_65 -> V_110 )
{
if ( V_65 == NULL )
return - V_35 ;
F_5 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 ) ;
while ( ! F_38 ( & V_65 -> V_92 . V_93 ) ) {
struct V_66 * V_67 = \
F_39 ( V_65 -> V_92 . V_93 . V_81 ,
struct V_66 , V_93 ) ;
F_45 ( & V_67 -> V_93 ) ;
V_67 -> V_71 . V_72 = - V_111 ;
if ( V_67 -> V_71 . V_112 != NULL ) {
F_46 ( V_65 -> V_110 ) ;
V_67 -> V_71 . V_112 ( & V_65 -> V_62 , & V_67 -> V_71 ) ;
F_47 ( V_65 -> V_110 ) ;
}
}
return 0 ;
}
static int F_48 ( struct V_113 * V_60 )
{
struct V_114 * V_62 ;
struct V_3 * V_4 = F_31 ( V_60 , struct V_3 , V_60 ) ;
unsigned long V_115 ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
V_4 -> V_60 . V_116 = V_117 ;
V_4 -> V_118 = 0 ;
V_4 -> V_119 = 0 ;
F_50 ( & V_4 -> V_110 , V_115 ) ;
F_51 (ep, gadget) {
F_52 ( V_62 ) ;
}
F_52 ( & V_4 -> V_120 -> V_62 ) ;
F_52 ( & V_4 -> V_121 -> V_62 ) ;
if ( V_4 -> V_122 )
V_4 -> V_122 -> V_123 ( V_60 ) ;
F_51 (ep, gadget) {
F_53 ( V_62 ) ;
}
if ( V_4 -> V_72 != NULL ) {
F_54 ( & V_4 -> V_121 -> V_62 , V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
}
return 0 ;
}
static void F_55 ( struct V_3 * V_4 )
__releases( V_4 -> V_110 )
__acquires( V_4 -> V_110 )
{
int V_124 ;
F_56 ( 0xFF , L_1 , 0 ) ;
F_46 ( & V_4 -> V_110 ) ;
V_124 = F_48 ( & V_4 -> V_60 ) ;
if ( V_124 )
goto V_98;
V_124 = F_29 ( V_4 ) ;
if ( V_124 )
goto V_98;
V_4 -> V_72 = F_57 ( & V_4 -> V_121 -> V_62 , V_78 ) ;
if ( V_4 -> V_72 == NULL )
V_124 = - V_80 ;
V_98:
F_47 ( & V_4 -> V_110 ) ;
if ( V_124 )
F_58 ( V_4 -> V_125 , L_2 , V_124 ) ;
}
static void F_59 ( struct V_114 * V_62 , struct V_126 * V_71 )
{
if ( V_62 == NULL || V_71 == NULL )
return;
F_60 ( V_71 -> V_127 ) ;
F_54 ( V_62 , V_71 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_128 * V_129 )
__releases( V_65 -> V_110 )
__acquires( V_65 -> V_110 )
{
struct V_61 * V_65 = V_4 -> V_121 ;
struct V_126 * V_71 = NULL ;
T_3 V_130 = V_78 ;
int V_2 , V_1 , V_124 ;
if ( V_65 == NULL || V_129 == NULL )
return - V_35 ;
F_46 ( V_65 -> V_110 ) ;
V_71 = F_57 ( & V_65 -> V_62 , V_130 ) ;
F_47 ( V_65 -> V_110 ) ;
if ( V_71 == NULL )
return - V_80 ;
V_71 -> V_112 = F_59 ;
V_71 -> V_70 = 2 ;
V_71 -> V_127 = F_62 ( V_71 -> V_70 , V_130 ) ;
if ( V_71 -> V_127 == NULL ) {
V_124 = - V_80 ;
goto V_131;
}
if ( ( V_129 -> V_132 & V_133 ) == V_134 ) {
* ( V_135 * ) V_71 -> V_127 = V_4 -> V_118 << 1 ;
V_124 = 0 ;
} else if ( ( V_129 -> V_132 & V_133 ) \
== V_136 ) {
V_2 = ( F_63 ( V_129 -> V_137 ) & V_64 ) ?
V_63 : V_31 ;
V_1 = F_63 ( V_129 -> V_137 ) & V_138 ;
* ( V_135 * ) V_71 -> V_127 = F_12 ( V_4 , V_1 , V_2 ) ;
}
F_46 ( V_65 -> V_110 ) ;
V_124 = F_64 ( & V_65 -> V_62 , V_71 , V_130 ) ;
F_47 ( V_65 -> V_110 ) ;
if ( V_124 )
goto V_139;
return 0 ;
V_139:
F_60 ( V_71 -> V_127 ) ;
V_131:
F_46 ( V_65 -> V_110 ) ;
F_54 ( & V_65 -> V_62 , V_71 ) ;
F_47 ( V_65 -> V_110 ) ;
return V_124 ;
}
static void
F_65 ( struct V_114 * V_62 , struct V_126 * V_71 )
{
struct V_3 * V_4 = V_71 -> V_140 ;
unsigned long V_115 ;
if ( V_4 -> V_141 ) {
F_28 ( V_4 , V_4 -> V_142 ) ;
V_4 -> V_141 = false ;
}
F_49 ( & V_4 -> V_110 , V_115 ) ;
if ( V_4 -> V_143 )
F_66 ( V_4 , V_4 -> V_143 ) ;
F_50 ( & V_4 -> V_110 , V_115 ) ;
}
static int F_67 ( struct V_3 * V_4 )
__releases( V_65 -> V_110 )
__acquires( V_65 -> V_110 )
{
int V_124 ;
struct V_61 * V_65 ;
V_65 = ( V_4 -> V_144 == V_63 ) ? V_4 -> V_120 : V_4 -> V_121 ;
V_4 -> V_72 -> V_140 = V_4 ;
V_4 -> V_72 -> V_112 = F_65 ;
F_46 ( V_65 -> V_110 ) ;
V_124 = F_64 ( & V_65 -> V_62 , V_4 -> V_72 , V_78 ) ;
F_47 ( V_65 -> V_110 ) ;
return V_124 ;
}
static int F_68 ( struct V_61 * V_65 )
__releases( V_65 -> V_110 )
__acquires( V_65 -> V_110 )
{
struct V_66 * V_67 , * V_145 ;
struct V_61 * V_146 = V_65 ;
int V_124 = 0 ;
F_69 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_124 = F_41 ( V_65 , V_67 ) ;
if ( V_124 < 0 )
break;
F_45 ( & V_67 -> V_93 ) ;
F_70 ( F_34 ( V_65 ) , V_67 -> V_87 -> V_83 , V_124 ) ;
if ( V_67 -> V_71 . V_112 != NULL ) {
F_46 ( V_65 -> V_110 ) ;
if ( ( V_65 -> type == V_104 ) &&
V_67 -> V_71 . V_70 )
V_146 = V_65 -> V_4 -> V_121 ;
V_67 -> V_71 . V_112 ( & V_146 -> V_62 , & V_67 -> V_71 ) ;
F_47 ( V_65 -> V_110 ) ;
}
}
if ( V_124 == - V_105 )
V_124 = 0 ;
if ( V_124 < 0 )
F_56 ( F_34 ( V_65 ) , L_3 , V_124 ) ;
return V_124 ;
}
static void F_71 ( struct V_3 * V_4 )
__releases( V_4 -> V_110 )
__acquires( V_4 -> V_110 )
{
unsigned V_68 ;
T_2 V_147 = 0 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_7 ; V_68 ++ ) {
struct V_61 * V_65 = & V_4 -> V_61 [ V_68 ] ;
int type , V_1 , V_2 , V_148 = - V_35 ;
struct V_128 V_71 ;
if ( V_65 -> V_62 . V_149 == NULL )
continue;
if ( F_20 ( V_4 , V_68 ) ) {
V_148 = F_68 ( V_65 ) ;
if ( V_65 -> type == V_104 ) {
if ( V_148 > 0 )
V_148 = F_67 ( V_4 ) ;
if ( V_148 < 0 ) {
F_56 ( F_34 ( V_65 ) ,
L_4 , V_148 ) ;
F_46 ( & V_4 -> V_110 ) ;
if ( F_72 ( & V_65 -> V_62 ) )
F_58 ( V_4 -> V_125 ,
L_5 ) ;
F_47 ( & V_4 -> V_110 ) ;
}
}
}
if ( V_65 -> type != V_104 ||
! F_13 ( V_4 , V_68 ) )
continue;
if ( V_68 != 0 ) {
F_73 ( V_4 -> V_125 , L_6 , V_68 ) ;
continue;
}
F_44 ( V_4 -> V_120 ) ;
F_44 ( V_4 -> V_121 ) ;
do {
F_27 ( V_4 ) ;
memcpy ( & V_71 , & V_65 -> V_92 . V_87 -> V_129 , sizeof( V_71 ) ) ;
} while ( ! F_25 ( V_4 ) );
type = V_71 . V_132 ;
V_4 -> V_144 = ( type & V_150 ) ? V_63 : V_31 ;
F_74 ( F_34 ( V_65 ) , & V_71 ) ;
switch ( V_71 . V_151 ) {
case V_152 :
if ( type == ( V_153 | V_136 ) &&
F_63 ( V_71 . V_154 ) ==
V_155 ) {
if ( V_71 . V_156 != 0 )
break;
V_1 = F_63 ( V_71 . V_137 ) ;
V_2 = V_1 & V_64 ;
V_1 &= V_138 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_61 [ V_1 ] . V_157 ) {
F_46 ( & V_4 -> V_110 ) ;
V_148 = F_75 (
& V_4 -> V_61 [ V_1 ] . V_62 ) ;
F_47 ( & V_4 -> V_110 ) ;
if ( V_148 )
break;
}
V_148 = F_67 ( V_4 ) ;
} else if ( type == ( V_153 | V_134 ) &&
F_63 ( V_71 . V_154 ) ==
V_158 ) {
if ( V_71 . V_156 != 0 )
break;
V_4 -> V_118 = 0 ;
V_148 = F_67 ( V_4 ) ;
} else {
goto V_159;
}
break;
case V_160 :
if ( type != ( V_150 | V_134 ) &&
type != ( V_150 | V_136 ) &&
type != ( V_150 | V_161 ) )
goto V_159;
if ( F_63 ( V_71 . V_156 ) != 2 ||
F_63 ( V_71 . V_154 ) != 0 )
break;
V_148 = F_61 ( V_4 , & V_71 ) ;
break;
case V_162 :
if ( type != ( V_153 | V_134 ) )
goto V_159;
if ( F_63 ( V_71 . V_156 ) != 0 ||
F_63 ( V_71 . V_137 ) != 0 )
break;
V_4 -> V_142 = ( T_2 ) F_63 ( V_71 . V_154 ) ;
V_4 -> V_141 = true ;
V_148 = F_67 ( V_4 ) ;
break;
case V_163 :
if ( type == ( V_153 | V_136 ) &&
F_63 ( V_71 . V_154 ) ==
V_155 ) {
if ( V_71 . V_156 != 0 )
break;
V_1 = F_63 ( V_71 . V_137 ) ;
V_2 = V_1 & V_64 ;
V_1 &= V_138 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_46 ( & V_4 -> V_110 ) ;
V_148 = F_72 ( & V_4 -> V_61 [ V_1 ] . V_62 ) ;
F_47 ( & V_4 -> V_110 ) ;
if ( ! V_148 )
F_67 ( V_4 ) ;
} else if ( type == ( V_153 | V_134 ) ) {
if ( V_71 . V_156 != 0 )
break;
switch ( F_63 ( V_71 . V_154 ) ) {
case V_158 :
V_4 -> V_118 = 1 ;
V_148 = F_67 ( V_4 ) ;
break;
case V_164 :
V_147 = F_63 ( V_71 . V_137 ) >> 8 ;
switch ( V_147 ) {
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_4 -> V_143 = V_147 ;
V_148 = F_67 (
V_4 ) ;
break;
default:
break;
}
default:
goto V_159;
}
} else {
goto V_159;
}
break;
default:
V_159:
if ( V_71 . V_156 == 0 )
V_4 -> V_144 = V_63 ;
F_46 ( & V_4 -> V_110 ) ;
V_148 = V_4 -> V_122 -> V_129 ( & V_4 -> V_60 , & V_71 ) ;
F_47 ( & V_4 -> V_110 ) ;
break;
}
if ( V_148 < 0 ) {
F_56 ( F_34 ( V_65 ) , L_4 , V_148 ) ;
F_46 ( & V_4 -> V_110 ) ;
if ( F_72 ( & V_65 -> V_62 ) )
F_58 ( V_4 -> V_125 , L_5 ) ;
F_47 ( & V_4 -> V_110 ) ;
}
}
}
static int F_76 ( struct V_114 * V_62 ,
const struct V_170 * V_149 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
int V_124 = 0 ;
unsigned long V_115 ;
if ( V_62 == NULL || V_149 == NULL )
return - V_35 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
V_65 -> V_62 . V_149 = V_149 ;
if ( ! F_38 ( & V_65 -> V_92 . V_93 ) )
F_73 ( V_65 -> V_4 -> V_125 , L_7 ) ;
V_65 -> V_2 = F_77 ( V_149 ) ? V_63 : V_31 ;
V_65 -> V_1 = F_78 ( V_149 ) ;
V_65 -> type = F_79 ( V_149 ) ;
V_65 -> V_62 . V_75 = F_80 ( V_149 ) ;
F_56 ( F_34 ( V_65 ) , L_8 , 0 ) ;
V_65 -> V_92 . V_87 -> V_102 = 0 ;
if ( V_65 -> type == V_104 )
V_65 -> V_92 . V_87 -> V_102 |= V_171 ;
else if ( V_65 -> type == V_172 )
V_65 -> V_92 . V_87 -> V_102 &= ~ V_173 ;
else
V_65 -> V_92 . V_87 -> V_102 &= ~ V_103 ;
V_65 -> V_92 . V_87 -> V_102 |=
( V_65 -> V_62 . V_75 << F_11 ( V_174 ) ) & V_174 ;
V_65 -> V_92 . V_87 -> V_100 . V_81 |= V_82 ;
if ( V_65 -> V_1 )
V_124 |= F_10 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 , V_65 -> type ) ;
F_50 ( V_65 -> V_110 , V_115 ) ;
return V_124 ;
}
static int F_81 ( struct V_114 * V_62 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
int V_175 , V_124 = 0 ;
unsigned long V_115 ;
if ( V_62 == NULL )
return - V_35 ;
else if ( V_65 -> V_62 . V_149 == NULL )
return - V_105 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
V_175 = V_65 -> V_2 ;
do {
F_56 ( F_34 ( V_65 ) , L_9 , 0 ) ;
V_124 |= F_44 ( V_65 ) ;
V_124 |= F_9 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 ) ;
if ( V_65 -> type == V_104 )
V_65 -> V_2 = ( V_65 -> V_2 == V_63 ) ? V_31 : V_63 ;
} while ( V_65 -> V_2 != V_175 );
V_65 -> V_62 . V_149 = NULL ;
F_50 ( V_65 -> V_110 , V_115 ) ;
return V_124 ;
}
static struct V_126 * F_82 ( struct V_114 * V_62 , T_3 V_130 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
struct V_66 * V_67 = NULL ;
if ( V_62 == NULL )
return NULL ;
V_67 = F_62 ( sizeof( struct V_66 ) , V_130 ) ;
if ( V_67 != NULL ) {
F_83 ( & V_67 -> V_93 ) ;
V_67 -> V_87 = F_36 ( V_65 -> V_77 , V_130 ,
& V_67 -> V_8 ) ;
if ( V_67 -> V_87 == NULL ) {
F_60 ( V_67 ) ;
V_67 = NULL ;
}
}
F_56 ( F_34 ( V_65 ) , L_10 , V_67 == NULL ) ;
return ( V_67 == NULL ) ? NULL : & V_67 -> V_71 ;
}
static void F_84 ( struct V_114 * V_62 , struct V_126 * V_71 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
struct V_66 * V_67 = F_31 ( V_71 , struct V_66 , V_71 ) ;
unsigned long V_115 ;
if ( V_62 == NULL || V_71 == NULL ) {
return;
} else if ( ! F_38 ( & V_67 -> V_93 ) ) {
F_58 ( V_65 -> V_4 -> V_125 , L_11 ) ;
return;
}
F_49 ( V_65 -> V_110 , V_115 ) ;
if ( V_67 -> V_87 )
F_42 ( V_65 -> V_77 , V_67 -> V_87 , V_67 -> V_8 ) ;
F_60 ( V_67 ) ;
F_56 ( F_34 ( V_65 ) , L_12 , 0 ) ;
F_50 ( V_65 -> V_110 , V_115 ) ;
}
static int F_85 ( struct V_114 * V_62 , struct V_126 * V_71 ,
T_3 T_4 V_130 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
struct V_66 * V_67 = F_31 ( V_71 , struct V_66 , V_71 ) ;
struct V_3 * V_4 = V_65 -> V_4 ;
int V_124 = 0 ;
unsigned long V_115 ;
if ( V_62 == NULL || V_71 == NULL || V_65 -> V_62 . V_149 == NULL )
return - V_35 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
if ( V_65 -> type == V_104 ) {
if ( V_71 -> V_70 )
V_65 = ( V_4 -> V_144 == V_31 ) ?
V_4 -> V_120 : V_4 -> V_121 ;
if ( ! F_38 ( & V_65 -> V_92 . V_93 ) ) {
F_44 ( V_65 ) ;
V_124 = - V_176 ;
F_73 ( V_65 -> V_4 -> V_125 , L_13 ,
F_34 ( V_65 ) ) ;
}
}
if ( ! F_38 ( & V_67 -> V_93 ) ) {
V_124 = - V_105 ;
F_58 ( V_65 -> V_4 -> V_125 , L_14 ) ;
goto V_98;
}
if ( V_71 -> V_70 > 4 * V_90 ) {
V_71 -> V_70 = 4 * V_90 ;
V_124 = - V_177 ;
F_73 ( V_65 -> V_4 -> V_125 , L_15 ) ;
}
F_86 ( F_34 ( V_65 ) , V_71 , V_124 ) ;
V_67 -> V_71 . V_72 = - V_178 ;
V_67 -> V_71 . V_109 = 0 ;
V_124 = F_35 ( V_65 , V_67 ) ;
if ( V_124 == - V_73 ) {
F_56 ( F_34 ( V_65 ) , L_16 , V_124 ) ;
V_124 = 0 ;
}
if ( ! V_124 )
F_87 ( & V_67 -> V_93 , & V_65 -> V_92 . V_93 ) ;
V_98:
F_50 ( V_65 -> V_110 , V_115 ) ;
return V_124 ;
}
static int F_88 ( struct V_114 * V_62 , struct V_126 * V_71 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
struct V_66 * V_67 = F_31 ( V_71 , struct V_66 , V_71 ) ;
unsigned long V_115 ;
if ( V_62 == NULL || V_71 == NULL || V_67 -> V_71 . V_72 != - V_73 ||
V_65 -> V_62 . V_149 == NULL || F_38 ( & V_67 -> V_93 ) ||
F_38 ( & V_65 -> V_92 . V_93 ) )
return - V_35 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
F_56 ( F_34 ( V_65 ) , L_17 , 0 ) ;
F_5 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 ) ;
F_45 ( & V_67 -> V_93 ) ;
F_43 ( & V_65 -> V_4 -> V_60 , V_71 , V_65 -> V_2 ) ;
V_71 -> V_72 = - V_179 ;
if ( V_67 -> V_71 . V_112 != NULL ) {
F_46 ( V_65 -> V_110 ) ;
V_67 -> V_71 . V_112 ( & V_65 -> V_62 , & V_67 -> V_71 ) ;
F_47 ( V_65 -> V_110 ) ;
}
F_50 ( V_65 -> V_110 , V_115 ) ;
return 0 ;
}
static int F_89 ( struct V_114 * V_62 , int V_34 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
int V_175 , V_124 = 0 ;
unsigned long V_115 ;
if ( V_62 == NULL || V_65 -> V_62 . V_149 == NULL )
return - V_35 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
#ifndef F_90
if ( V_34 && V_65 -> type == V_180 && V_65 -> V_2 == V_63 &&
! F_38 ( & V_65 -> V_92 . V_93 ) ) {
F_50 ( V_65 -> V_110 , V_115 ) ;
return - V_32 ;
}
#endif
V_175 = V_65 -> V_2 ;
do {
F_56 ( F_34 ( V_65 ) , L_18 , V_34 ) ;
V_124 |= F_16 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_65 -> V_157 = 0 ;
if ( V_65 -> type == V_104 )
V_65 -> V_2 = ( V_65 -> V_2 == V_63 ) ? V_31 : V_63 ;
} while ( V_65 -> V_2 != V_175 );
F_50 ( V_65 -> V_110 , V_115 ) ;
return V_124 ;
}
static int F_91 ( struct V_114 * V_62 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
unsigned long V_115 ;
if ( V_62 == NULL || V_65 -> V_62 . V_149 == NULL )
return - V_35 ;
F_49 ( V_65 -> V_110 , V_115 ) ;
F_56 ( F_34 ( V_65 ) , L_19 , 0 ) ;
V_65 -> V_157 = 1 ;
F_50 ( V_65 -> V_110 , V_115 ) ;
return F_72 ( V_62 ) ;
}
static void F_92 ( struct V_114 * V_62 )
{
struct V_61 * V_65 = F_31 ( V_62 , struct V_61 , V_62 ) ;
unsigned long V_115 ;
if ( V_62 == NULL ) {
F_58 ( V_65 -> V_4 -> V_125 , L_20 , F_34 ( V_65 ) ) ;
return;
}
F_49 ( V_65 -> V_110 , V_115 ) ;
F_56 ( F_34 ( V_65 ) , L_21 , 0 ) ;
F_5 ( V_65 -> V_4 , V_65 -> V_1 , V_65 -> V_2 ) ;
F_50 ( V_65 -> V_110 , V_115 ) ;
}
static int F_93 ( struct V_113 * V_181 , int V_182 )
{
struct V_3 * V_4 = F_31 ( V_181 , struct V_3 , V_60 ) ;
unsigned long V_115 ;
int V_183 = 0 ;
if ( ! ( V_4 -> V_184 -> V_115 & V_185 ) )
return - V_186 ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
V_4 -> V_187 = V_182 ;
if ( V_4 -> V_122 )
V_183 = 1 ;
F_50 ( & V_4 -> V_110 , V_115 ) ;
if ( V_183 ) {
if ( V_182 ) {
F_94 ( & V_181 -> V_125 ) ;
F_95 ( V_4 , V_188 ) ;
F_22 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_120 -> V_92 . V_8 ) ;
} else {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_184 -> V_189 )
V_4 -> V_184 -> V_189 ( V_4 ,
V_190 ) ;
F_48 ( & V_4 -> V_60 ) ;
F_96 ( & V_181 -> V_125 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_113 * V_181 )
{
struct V_3 * V_4 = F_31 ( V_181 , struct V_3 , V_60 ) ;
unsigned long V_115 ;
int V_69 = 0 ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
if ( ! V_4 -> V_118 ) {
V_69 = - V_186 ;
goto V_191;
}
if ( ! F_7 ( V_4 , V_44 , V_192 ) ) {
V_69 = - V_35 ;
goto V_191;
}
F_4 ( V_4 , V_44 , V_193 , V_193 ) ;
V_191:
F_50 ( & V_4 -> V_110 , V_115 ) ;
return V_69 ;
}
static int F_98 ( struct V_113 * V_181 , unsigned V_194 )
{
struct V_3 * V_4 = F_31 ( V_181 , struct V_3 , V_60 ) ;
if ( V_4 -> V_195 )
return F_99 ( V_4 -> V_195 , V_194 ) ;
return - V_196 ;
}
static int F_100 ( struct V_113 * V_181 , int V_197 )
{
struct V_3 * V_4 = F_31 ( V_181 , struct V_3 , V_60 ) ;
if ( V_197 )
F_4 ( V_4 , V_53 , V_198 , V_198 ) ;
else
F_4 ( V_4 , V_53 , V_198 , 0 ) ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 )
{
int V_124 = 0 , V_68 , V_199 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_7 / 2 ; V_68 ++ )
for ( V_199 = V_31 ; V_199 <= V_63 ; V_199 ++ ) {
int V_200 = V_68 + V_199 * V_4 -> V_7 / 2 ;
struct V_61 * V_65 = & V_4 -> V_61 [ V_200 ] ;
F_102 ( V_65 -> V_201 , sizeof( V_65 -> V_201 ) , L_22 , V_68 ,
( V_199 == V_63 ) ? L_23 : L_24 ) ;
V_65 -> V_4 = V_4 ;
V_65 -> V_110 = & V_4 -> V_110 ;
V_65 -> V_77 = V_4 -> V_77 ;
V_65 -> V_62 . V_201 = V_65 -> V_201 ;
V_65 -> V_62 . V_202 = & V_203 ;
V_65 -> V_62 . V_75 = ( unsigned short ) ~ 0 ;
F_83 ( & V_65 -> V_92 . V_93 ) ;
V_65 -> V_92 . V_87 = F_36 ( V_4 -> V_204 , V_205 ,
& V_65 -> V_92 . V_8 ) ;
if ( V_65 -> V_92 . V_87 == NULL )
V_124 = - V_80 ;
else
memset ( V_65 -> V_92 . V_87 , 0 , sizeof( * V_65 -> V_92 . V_87 ) ) ;
if ( V_68 == 0 ) {
if ( V_199 == V_31 )
V_4 -> V_120 = V_65 ;
else
V_4 -> V_121 = V_65 ;
V_65 -> V_62 . V_75 = V_206 ;
continue;
}
F_87 ( & V_65 -> V_62 . V_207 , & V_4 -> V_60 . V_207 ) ;
}
return V_124 ;
}
static void F_103 ( struct V_3 * V_4 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_7 ; V_68 ++ ) {
struct V_61 * V_65 = & V_4 -> V_61 [ V_68 ] ;
F_42 ( V_4 -> V_204 , V_65 -> V_92 . V_87 , V_65 -> V_92 . V_8 ) ;
}
}
static int F_104 ( struct V_113 * V_60 ,
struct V_208 * V_122 )
{
struct V_3 * V_4 = F_31 ( V_60 , struct V_3 , V_60 ) ;
unsigned long V_115 ;
int V_124 = - V_80 ;
if ( V_122 -> V_123 == NULL )
return - V_35 ;
V_4 -> V_120 -> V_62 . V_149 = & V_209 ;
V_124 = F_105 ( & V_4 -> V_120 -> V_62 ) ;
if ( V_124 )
return V_124 ;
V_4 -> V_121 -> V_62 . V_149 = & V_210 ;
V_124 = F_105 ( & V_4 -> V_121 -> V_62 ) ;
if ( V_124 )
return V_124 ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
V_4 -> V_122 = V_122 ;
F_94 ( & V_4 -> V_60 . V_125 ) ;
if ( V_4 -> V_184 -> V_115 & V_185 ) {
if ( V_4 -> V_187 ) {
if ( V_4 -> V_184 -> V_115 & V_211 ) {
F_95 ( V_4 , V_188 ) ;
F_22 ( V_4 ) ;
}
} else {
F_96 ( & V_4 -> V_60 . V_125 ) ;
goto V_98;
}
}
V_124 = F_3 ( V_4 , V_4 -> V_120 -> V_92 . V_8 ) ;
if ( V_124 )
F_96 ( & V_4 -> V_60 . V_125 ) ;
V_98:
F_50 ( & V_4 -> V_110 , V_115 ) ;
return V_124 ;
}
static int F_106 ( struct V_113 * V_60 ,
struct V_208 * V_122 )
{
struct V_3 * V_4 = F_31 ( V_60 , struct V_3 , V_60 ) ;
unsigned long V_115 ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
if ( ! ( V_4 -> V_184 -> V_115 & V_185 ) ||
V_4 -> V_187 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_184 -> V_189 )
V_4 -> V_184 -> V_189 ( V_4 ,
V_190 ) ;
V_4 -> V_122 = NULL ;
F_50 ( & V_4 -> V_110 , V_115 ) ;
F_48 ( & V_4 -> V_60 ) ;
F_49 ( & V_4 -> V_110 , V_115 ) ;
F_107 ( & V_4 -> V_60 . V_125 ) ;
}
F_50 ( & V_4 -> V_110 , V_115 ) ;
return 0 ;
}
static T_5 F_108 ( struct V_3 * V_4 )
{
T_5 V_124 ;
T_1 V_212 ;
if ( V_4 == NULL )
return V_213 ;
F_47 ( & V_4 -> V_110 ) ;
if ( V_4 -> V_184 -> V_115 & V_211 ) {
if ( F_7 ( V_4 , V_214 , V_215 ) !=
V_188 ) {
F_46 ( & V_4 -> V_110 ) ;
return V_216 ;
}
}
V_212 = F_21 ( V_4 ) ;
F_109 ( V_212 ) ;
if ( V_212 ) {
if ( V_14 & V_212 )
F_55 ( V_4 ) ;
if ( V_13 & V_212 ) {
V_4 -> V_60 . V_116 = F_17 ( V_4 ) ?
V_217 : V_218 ;
if ( V_4 -> V_119 && V_4 -> V_122 -> V_219 ) {
F_46 ( & V_4 -> V_110 ) ;
V_4 -> V_122 -> V_219 ( & V_4 -> V_60 ) ;
F_47 ( & V_4 -> V_110 ) ;
V_4 -> V_119 = 0 ;
}
}
if ( V_11 & V_212 )
F_71 ( V_4 ) ;
if ( V_15 & V_212 ) {
if ( V_4 -> V_60 . V_116 != V_117 &&
V_4 -> V_122 -> V_220 ) {
V_4 -> V_119 = 1 ;
F_46 ( & V_4 -> V_110 ) ;
V_4 -> V_122 -> V_220 ( & V_4 -> V_60 ) ;
F_47 ( & V_4 -> V_110 ) ;
}
}
V_124 = V_213 ;
} else {
V_124 = V_216 ;
}
V_212 = F_7 ( V_4 , V_48 , ~ 0 ) ;
F_4 ( V_4 , V_48 , ~ 0 , V_212 ) ;
if ( V_212 & ( V_50 & V_49 ) )
F_23 ( V_4 -> V_51 , & V_4 -> V_52 ) ;
F_46 ( & V_4 -> V_110 ) ;
return V_124 ;
}
static void F_110 ( struct V_221 * V_125 )
{
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_221 * V_125 = V_4 -> V_125 ;
int V_124 = 0 ;
F_112 ( & V_4 -> V_110 ) ;
V_4 -> V_60 . V_202 = & V_222 ;
V_4 -> V_60 . V_116 = V_117 ;
V_4 -> V_60 . V_223 = V_217 ;
V_4 -> V_60 . V_224 = 0 ;
V_4 -> V_60 . V_201 = V_4 -> V_184 -> V_201 ;
F_83 ( & V_4 -> V_60 . V_207 ) ;
F_113 ( & V_4 -> V_60 . V_125 , L_25 ) ;
V_4 -> V_60 . V_125 . V_225 = V_125 -> V_225 ;
V_4 -> V_60 . V_125 . V_226 = V_125 -> V_226 ;
V_4 -> V_60 . V_125 . V_227 = V_125 ;
V_4 -> V_60 . V_125 . V_228 = F_110 ;
V_4 -> V_204 = F_114 ( L_26 , V_125 ,
sizeof( struct V_229 ) ,
64 , V_90 ) ;
if ( V_4 -> V_204 == NULL )
return - V_80 ;
V_4 -> V_77 = F_114 ( L_27 , V_125 ,
sizeof( struct V_230 ) ,
64 , V_90 ) ;
if ( V_4 -> V_77 == NULL ) {
V_124 = - V_80 ;
goto V_231;
}
V_124 = F_101 ( V_4 ) ;
if ( V_124 )
goto V_232;
V_4 -> V_60 . V_233 = & V_4 -> V_121 -> V_62 ;
if ( V_4 -> V_234 )
V_4 -> V_195 = F_115 ( V_235 ) ;
if ( V_4 -> V_184 -> V_115 & V_236 ) {
if ( V_4 -> V_195 == NULL ) {
V_124 = - V_237 ;
goto F_103;
}
}
if ( ! ( V_4 -> V_184 -> V_115 & V_211 ) ) {
V_124 = F_95 ( V_4 , V_188 ) ;
if ( V_124 )
goto V_238;
F_22 ( V_4 ) ;
}
V_124 = F_116 ( & V_4 -> V_60 . V_125 ) ;
if ( V_124 ) {
F_117 ( & V_4 -> V_60 . V_125 ) ;
goto V_238;
}
V_124 = F_118 ( V_4 -> V_125 ) ;
if ( V_124 )
goto V_239;
if ( ! F_119 ( V_4 -> V_195 ) ) {
V_124 = F_120 ( V_4 -> V_195 -> V_240 ,
& V_4 -> V_60 ) ;
if ( V_124 )
goto V_241;
}
V_124 = F_121 ( V_125 , & V_4 -> V_60 ) ;
if ( V_124 )
goto V_242;
F_122 ( & V_4 -> V_60 . V_125 ) ;
F_123 ( & V_4 -> V_60 . V_125 ) ;
return V_124 ;
V_242:
if ( ! F_119 ( V_4 -> V_195 ) ) {
F_120 ( V_4 -> V_195 -> V_240 , NULL ) ;
if ( V_4 -> V_234 )
F_124 ( V_4 -> V_195 ) ;
}
F_58 ( V_125 , L_28 , V_124 ) ;
V_241:
F_125 ( V_4 -> V_125 ) ;
V_239:
F_126 ( & V_4 -> V_60 . V_125 ) ;
V_238:
if ( ! F_119 ( V_4 -> V_195 ) && V_4 -> V_234 )
F_124 ( V_4 -> V_195 ) ;
F_103:
F_103 ( V_4 ) ;
V_232:
F_127 ( V_4 -> V_77 ) ;
V_231:
F_127 ( V_4 -> V_204 ) ;
return V_124 ;
}
static void F_128 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
F_24 ( V_4 ) ;
F_129 ( & V_4 -> V_52 ) ;
F_130 ( & V_4 -> V_60 ) ;
F_103 ( V_4 ) ;
F_127 ( V_4 -> V_77 ) ;
F_127 ( V_4 -> V_204 ) ;
if ( ! F_119 ( V_4 -> V_195 ) ) {
F_120 ( V_4 -> V_195 -> V_240 , NULL ) ;
if ( V_4 -> V_234 )
F_124 ( V_4 -> V_195 ) ;
}
F_125 ( V_4 -> V_125 ) ;
F_126 ( & V_4 -> V_60 . V_125 ) ;
memset ( & V_4 -> V_60 , 0 , sizeof( V_4 -> V_60 ) ) ;
}
int F_131 ( struct V_3 * V_4 )
{
struct V_243 * V_244 ;
if ( ! F_7 ( V_4 , V_245 , V_246 ) )
return - V_247 ;
V_244 = F_132 ( V_4 -> V_125 , sizeof( struct V_243 ) , V_205 ) ;
if ( ! V_244 )
return - V_80 ;
V_244 -> V_248 = F_111 ;
V_244 -> V_249 = F_128 ;
V_244 -> V_250 = F_108 ;
V_244 -> V_201 = L_25 ;
V_4 -> V_251 [ V_252 ] = V_244 ;
F_133 ( & V_4 -> V_52 , V_52 ) ;
return 0 ;
}
