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
F_4 ( V_4 , V_16 , V_17 , 0 ) ;
F_4 ( V_4 , V_10 , ~ 0 , 0 ) ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , int V_1 , int V_2 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
do {
F_4 ( V_4 , V_18 , F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
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
static int F_13 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_14 ( V_4 , V_31 , F_6 ( V_5 ) ) ;
}
static int F_15 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_32 )
{
int V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_32 && V_2 == V_33 && F_7 ( V_4 , V_31 , F_6 ( V_1 ) ) )
return - V_34 ;
F_4 ( V_4 , V_35 , F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
while ( F_7 ( V_4 , V_35 , F_6 ( V_5 ) ) )
F_8 () ;
if ( V_32 && V_2 == V_33 && F_7 ( V_4 , V_31 , F_6 ( V_1 ) ) )
return - V_34 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int V_1 , int V_2 , int V_36 )
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
static int F_17 ( struct V_3 * V_4 )
{
return V_4 -> V_42 . V_43 ? F_7 ( V_4 , V_44 , V_45 ) :
F_7 ( V_4 , V_46 , V_47 ) ;
}
static T_1 F_18 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_10 , ~ 0 ) ;
}
static T_1 F_19 ( struct V_3 * V_4 )
{
return F_7 ( V_4 , V_48 , ~ 0 ) ;
}
static int F_20 ( struct V_3 * V_4 , int V_5 )
{
V_5 = F_2 ( V_4 , V_5 ) ;
return F_14 ( V_4 , V_49 , F_6 ( V_5 ) ) ;
}
static T_1 F_21 ( struct V_3 * V_4 )
{
T_1 V_39 = F_19 ( V_4 ) & F_18 ( V_4 ) ;
F_4 ( V_4 , V_48 , ~ 0 , V_39 ) ;
return V_39 ;
}
static int F_22 ( struct V_3 * V_4 )
{
return F_23 ( V_4 , V_16 , V_50 , 0 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
return F_23 ( V_4 , V_16 , V_50 , V_50 ) ;
}
static void F_25 ( struct V_3 * V_4 , T_2 V_36 )
{
F_4 ( V_4 , V_51 , V_52 ,
V_36 << F_11 ( V_52 ) ) ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_25 ( V_4 , 0 ) ;
F_4 ( V_4 , V_18 , ~ 0 , ~ 0 ) ;
F_4 ( V_4 , V_31 , 0 , 0 ) ;
F_4 ( V_4 , V_49 , 0 , 0 ) ;
while ( F_7 ( V_4 , V_35 , ~ 0 ) )
F_27 ( 10 ) ;
return 0 ;
}
static inline T_2 F_28 ( struct V_53 * V_54 )
{
return ( ( V_54 -> V_2 == V_55 ) ? V_56 : 0 ) | V_54 -> V_1 ;
}
static int F_29 ( struct V_53 * V_57 , struct V_58 * V_59 )
{
struct V_3 * V_4 = V_57 -> V_4 ;
unsigned V_60 ;
int V_61 = 0 ;
unsigned V_62 = V_59 -> V_63 . V_62 ;
if ( V_59 -> V_63 . V_64 == - V_65 )
return - V_65 ;
V_59 -> V_63 . V_64 = - V_65 ;
if ( V_59 -> V_63 . V_66 && V_62 && ( V_62 % V_57 -> V_54 . V_67 == 0 ) ) {
V_59 -> V_68 = F_30 ( V_57 -> V_69 , V_70 ,
& V_59 -> V_71 ) ;
if ( V_59 -> V_68 == NULL )
return - V_72 ;
memset ( V_59 -> V_68 , 0 , sizeof( * V_59 -> V_68 ) ) ;
V_59 -> V_68 -> V_73 = V_74 ;
V_59 -> V_68 -> V_75 = V_76 ;
if ( ! V_59 -> V_63 . V_77 )
V_59 -> V_68 -> V_75 |= V_78 ;
}
V_61 = F_31 ( & V_4 -> V_79 , & V_59 -> V_63 , V_57 -> V_2 ) ;
if ( V_61 )
return V_61 ;
memset ( V_59 -> V_80 , 0 , sizeof( * V_59 -> V_80 ) ) ;
V_59 -> V_80 -> V_75 = V_62 << F_11 ( V_81 ) ;
V_59 -> V_80 -> V_75 &= V_81 ;
V_59 -> V_80 -> V_75 |= V_76 ;
if ( V_59 -> V_68 ) {
V_59 -> V_80 -> V_73 = V_59 -> V_71 ;
} else {
V_59 -> V_80 -> V_73 = V_74 ;
if ( ! V_59 -> V_63 . V_77 )
V_59 -> V_80 -> V_75 |= V_78 ;
}
V_59 -> V_80 -> V_82 [ 0 ] = V_59 -> V_63 . V_8 ;
for ( V_60 = 1 ; V_60 < 5 ; V_60 ++ )
V_59 -> V_80 -> V_82 [ V_60 ] =
( V_59 -> V_63 . V_8 + V_60 * V_83 ) & ~ V_84 ;
if ( ! F_32 ( & V_57 -> V_85 . V_86 ) ) {
struct V_58 * V_87 ;
int V_5 = F_1 ( V_57 -> V_1 , V_57 -> V_2 ) ;
int V_88 ;
V_87 = F_33 ( V_57 -> V_85 . V_86 . V_89 ,
struct V_58 , V_86 ) ;
if ( V_87 -> V_68 )
V_87 -> V_68 -> V_73 = V_59 -> V_8 & V_90 ;
else
V_87 -> V_80 -> V_73 = V_59 -> V_8 & V_90 ;
F_34 () ;
if ( F_7 ( V_4 , V_35 , F_6 ( V_5 ) ) )
goto V_91;
do {
F_4 ( V_4 , V_16 , V_92 , V_92 ) ;
V_88 = F_7 ( V_4 , V_19 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_16 , V_92 ) );
F_4 ( V_4 , V_16 , V_92 , 0 ) ;
if ( V_88 )
goto V_91;
}
V_57 -> V_85 . V_80 -> V_93 . V_73 = V_59 -> V_8 ;
V_57 -> V_85 . V_80 -> V_93 . V_75 &= ~ V_94 ;
V_57 -> V_85 . V_80 -> V_95 |= V_96 ;
F_34 () ;
V_61 = F_15 ( V_4 , V_57 -> V_1 , V_57 -> V_2 ,
V_57 -> type == V_97 ) ;
V_91:
return V_61 ;
}
static int F_35 ( struct V_53 * V_57 , struct V_58 * V_59 )
{
if ( V_59 -> V_63 . V_64 != - V_65 )
return - V_37 ;
if ( ( V_76 & V_59 -> V_80 -> V_75 ) != 0 )
return - V_98 ;
if ( V_59 -> V_68 ) {
if ( ( V_76 & V_59 -> V_68 -> V_75 ) != 0 )
return - V_98 ;
F_36 ( V_57 -> V_69 , V_59 -> V_68 , V_59 -> V_71 ) ;
V_59 -> V_68 = NULL ;
}
V_59 -> V_63 . V_64 = 0 ;
F_37 ( & V_57 -> V_4 -> V_79 , & V_59 -> V_63 , V_57 -> V_2 ) ;
V_59 -> V_63 . V_64 = V_59 -> V_80 -> V_75 & V_94 ;
if ( ( V_99 & V_59 -> V_63 . V_64 ) != 0 )
V_59 -> V_63 . V_64 = - 1 ;
else if ( ( V_100 & V_59 -> V_63 . V_64 ) != 0 )
V_59 -> V_63 . V_64 = - 1 ;
else if ( ( V_101 & V_59 -> V_63 . V_64 ) != 0 )
V_59 -> V_63 . V_64 = - 1 ;
V_59 -> V_63 . V_102 = V_59 -> V_80 -> V_75 & V_81 ;
V_59 -> V_63 . V_102 >>= F_11 ( V_81 ) ;
V_59 -> V_63 . V_102 = V_59 -> V_63 . V_62 - V_59 -> V_63 . V_102 ;
V_59 -> V_63 . V_102 = V_59 -> V_63 . V_64 ? 0 : V_59 -> V_63 . V_102 ;
return V_59 -> V_63 . V_102 ;
}
static int F_38 ( struct V_53 * V_57 )
__releases( V_57 -> V_103 )
__acquires( V_57 -> V_103 )
{
if ( V_57 == NULL )
return - V_37 ;
F_5 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 ) ;
while ( ! F_32 ( & V_57 -> V_85 . V_86 ) ) {
struct V_58 * V_59 = \
F_33 ( V_57 -> V_85 . V_86 . V_73 ,
struct V_58 , V_86 ) ;
F_39 ( & V_59 -> V_86 ) ;
V_59 -> V_63 . V_64 = - V_104 ;
if ( V_59 -> V_63 . V_105 != NULL ) {
F_40 ( V_57 -> V_103 ) ;
V_59 -> V_63 . V_105 ( & V_57 -> V_54 , & V_59 -> V_63 ) ;
F_41 ( V_57 -> V_103 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_106 * V_79 )
{
struct V_107 * V_54 ;
struct V_3 * V_4 = F_43 ( V_79 , struct V_3 , V_79 ) ;
unsigned long V_108 ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
V_4 -> V_79 . V_109 = V_110 ;
V_4 -> V_111 = 0 ;
V_4 -> V_112 = 0 ;
F_45 ( & V_4 -> V_103 , V_108 ) ;
F_46 (ep, gadget) {
F_47 ( V_54 ) ;
}
F_47 ( & V_4 -> V_113 -> V_54 ) ;
F_47 ( & V_4 -> V_114 -> V_54 ) ;
if ( V_4 -> V_115 )
V_4 -> V_115 -> V_116 ( V_79 ) ;
F_46 (ep, gadget) {
F_48 ( V_54 ) ;
}
if ( V_4 -> V_64 != NULL ) {
F_49 ( & V_4 -> V_114 -> V_54 , V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
}
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
__releases( V_4 -> V_103 )
__acquires( V_4 -> V_103 )
{
int V_117 ;
F_51 ( 0xFF , L_1 , 0 ) ;
F_40 ( & V_4 -> V_103 ) ;
V_117 = F_42 ( & V_4 -> V_79 ) ;
if ( V_117 )
goto V_91;
V_117 = F_26 ( V_4 ) ;
if ( V_117 )
goto V_91;
V_4 -> V_64 = F_52 ( & V_4 -> V_114 -> V_54 , V_70 ) ;
if ( V_4 -> V_64 == NULL )
V_117 = - V_72 ;
V_91:
F_41 ( & V_4 -> V_103 ) ;
if ( V_117 )
F_53 ( V_4 -> V_118 , L_2 , V_117 ) ;
}
static void F_54 ( struct V_107 * V_54 , struct V_119 * V_63 )
{
if ( V_54 == NULL || V_63 == NULL )
return;
F_55 ( V_63 -> V_120 ) ;
F_49 ( V_54 , V_63 ) ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_121 * V_122 )
__releases( V_57 -> V_103 )
__acquires( V_57 -> V_103 )
{
struct V_53 * V_57 = V_4 -> V_114 ;
struct V_119 * V_63 = NULL ;
T_3 V_123 = V_70 ;
int V_2 , V_1 , V_117 ;
if ( V_57 == NULL || V_122 == NULL )
return - V_37 ;
F_40 ( V_57 -> V_103 ) ;
V_63 = F_52 ( & V_57 -> V_54 , V_123 ) ;
F_41 ( V_57 -> V_103 ) ;
if ( V_63 == NULL )
return - V_72 ;
V_63 -> V_105 = F_54 ;
V_63 -> V_62 = 2 ;
V_63 -> V_120 = F_57 ( V_63 -> V_62 , V_123 ) ;
if ( V_63 -> V_120 == NULL ) {
V_117 = - V_72 ;
goto V_124;
}
if ( ( V_122 -> V_125 & V_126 ) == V_127 ) {
* ( V_128 * ) V_63 -> V_120 = V_4 -> V_111 << 1 ;
V_117 = 0 ;
} else if ( ( V_122 -> V_125 & V_126 ) \
== V_129 ) {
V_2 = ( F_58 ( V_122 -> V_130 ) & V_56 ) ?
V_55 : V_33 ;
V_1 = F_58 ( V_122 -> V_130 ) & V_131 ;
* ( V_128 * ) V_63 -> V_120 = F_12 ( V_4 , V_1 , V_2 ) ;
}
F_40 ( V_57 -> V_103 ) ;
V_117 = F_59 ( & V_57 -> V_54 , V_63 , V_123 ) ;
F_41 ( V_57 -> V_103 ) ;
if ( V_117 )
goto V_132;
return 0 ;
V_132:
F_55 ( V_63 -> V_120 ) ;
V_124:
F_40 ( V_57 -> V_103 ) ;
F_49 ( & V_57 -> V_54 , V_63 ) ;
F_41 ( V_57 -> V_103 ) ;
return V_117 ;
}
static void
F_60 ( struct V_107 * V_54 , struct V_119 * V_63 )
{
struct V_3 * V_4 = V_63 -> V_133 ;
unsigned long V_108 ;
if ( V_4 -> V_134 ) {
F_25 ( V_4 , V_4 -> V_135 ) ;
V_4 -> V_134 = false ;
}
F_44 ( & V_4 -> V_103 , V_108 ) ;
if ( V_4 -> V_136 )
F_61 ( V_4 , V_4 -> V_136 ) ;
F_45 ( & V_4 -> V_103 , V_108 ) ;
}
static int F_62 ( struct V_3 * V_4 )
__releases( V_57 -> V_103 )
__acquires( V_57 -> V_103 )
{
int V_117 ;
struct V_53 * V_57 ;
V_57 = ( V_4 -> V_137 == V_55 ) ? V_4 -> V_113 : V_4 -> V_114 ;
V_4 -> V_64 -> V_133 = V_4 ;
V_4 -> V_64 -> V_105 = F_60 ;
F_40 ( V_57 -> V_103 ) ;
V_117 = F_59 ( & V_57 -> V_54 , V_4 -> V_64 , V_70 ) ;
F_41 ( V_57 -> V_103 ) ;
return V_117 ;
}
static int F_63 ( struct V_53 * V_57 )
__releases( V_57 -> V_103 )
__acquires( V_57 -> V_103 )
{
struct V_58 * V_59 , * V_138 ;
struct V_53 * V_139 = V_57 ;
int V_140 ( V_117 ) ;
if ( F_32 ( & V_57 -> V_85 . V_86 ) )
return - V_37 ;
F_64 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_117 = F_35 ( V_57 , V_59 ) ;
if ( V_117 < 0 )
break;
F_39 ( & V_59 -> V_86 ) ;
F_65 ( F_28 ( V_57 ) , V_59 -> V_80 -> V_75 , V_117 ) ;
if ( V_59 -> V_63 . V_105 != NULL ) {
F_40 ( V_57 -> V_103 ) ;
if ( ( V_57 -> type == V_97 ) &&
V_59 -> V_63 . V_62 )
V_139 = V_57 -> V_4 -> V_114 ;
V_59 -> V_63 . V_105 ( & V_139 -> V_54 , & V_59 -> V_63 ) ;
F_41 ( V_57 -> V_103 ) ;
}
}
if ( V_117 == - V_98 )
V_117 = 0 ;
if ( V_117 < 0 )
F_51 ( F_28 ( V_57 ) , L_3 , V_117 ) ;
return V_117 ;
}
static void F_66 ( struct V_3 * V_4 )
__releases( V_4 -> V_103 )
__acquires( V_4 -> V_103 )
{
unsigned V_60 ;
T_2 V_141 = 0 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_7 ; V_60 ++ ) {
struct V_53 * V_57 = & V_4 -> V_53 [ V_60 ] ;
int type , V_1 , V_2 , V_142 = - V_37 ;
struct V_121 V_63 ;
if ( V_57 -> V_54 . V_143 == NULL )
continue;
if ( F_20 ( V_4 , V_60 ) ) {
V_142 = F_63 ( V_57 ) ;
if ( V_57 -> type == V_97 ) {
if ( V_142 > 0 )
V_142 = F_62 ( V_4 ) ;
if ( V_142 < 0 ) {
F_51 ( F_28 ( V_57 ) ,
L_4 , V_142 ) ;
F_40 ( & V_4 -> V_103 ) ;
if ( F_67 ( & V_57 -> V_54 ) )
F_53 ( V_4 -> V_118 ,
L_5 ) ;
F_41 ( & V_4 -> V_103 ) ;
}
}
}
if ( V_57 -> type != V_97 ||
! F_13 ( V_4 , V_60 ) )
continue;
if ( V_60 != 0 ) {
F_68 ( V_4 -> V_118 , L_6 , V_60 ) ;
continue;
}
F_38 ( V_4 -> V_113 ) ;
F_38 ( V_4 -> V_114 ) ;
do {
F_24 ( V_4 ) ;
memcpy ( & V_63 , & V_57 -> V_85 . V_80 -> V_122 , sizeof( V_63 ) ) ;
} while ( ! F_22 ( V_4 ) );
type = V_63 . V_125 ;
V_4 -> V_137 = ( type & V_144 ) ? V_55 : V_33 ;
F_69 ( F_28 ( V_57 ) , & V_63 ) ;
switch ( V_63 . V_145 ) {
case V_146 :
if ( type == ( V_147 | V_129 ) &&
F_58 ( V_63 . V_148 ) ==
V_149 ) {
if ( V_63 . V_150 != 0 )
break;
V_1 = F_58 ( V_63 . V_130 ) ;
V_2 = V_1 & V_56 ;
V_1 &= V_131 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_53 [ V_1 ] . V_151 ) {
F_40 ( & V_4 -> V_103 ) ;
V_142 = F_70 (
& V_4 -> V_53 [ V_1 ] . V_54 ) ;
F_41 ( & V_4 -> V_103 ) ;
if ( V_142 )
break;
}
V_142 = F_62 ( V_4 ) ;
} else if ( type == ( V_147 | V_127 ) &&
F_58 ( V_63 . V_148 ) ==
V_152 ) {
if ( V_63 . V_150 != 0 )
break;
V_4 -> V_111 = 0 ;
V_142 = F_62 ( V_4 ) ;
} else {
goto V_153;
}
break;
case V_154 :
if ( type != ( V_144 | V_127 ) &&
type != ( V_144 | V_129 ) &&
type != ( V_144 | V_155 ) )
goto V_153;
if ( F_58 ( V_63 . V_150 ) != 2 ||
F_58 ( V_63 . V_148 ) != 0 )
break;
V_142 = F_56 ( V_4 , & V_63 ) ;
break;
case V_156 :
if ( type != ( V_147 | V_127 ) )
goto V_153;
if ( F_58 ( V_63 . V_150 ) != 0 ||
F_58 ( V_63 . V_130 ) != 0 )
break;
V_4 -> V_135 = ( T_2 ) F_58 ( V_63 . V_148 ) ;
V_4 -> V_134 = true ;
V_142 = F_62 ( V_4 ) ;
break;
case V_157 :
if ( type == ( V_147 | V_129 ) &&
F_58 ( V_63 . V_148 ) ==
V_149 ) {
if ( V_63 . V_150 != 0 )
break;
V_1 = F_58 ( V_63 . V_130 ) ;
V_2 = V_1 & V_56 ;
V_1 &= V_131 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_40 ( & V_4 -> V_103 ) ;
V_142 = F_67 ( & V_4 -> V_53 [ V_1 ] . V_54 ) ;
F_41 ( & V_4 -> V_103 ) ;
if ( ! V_142 )
F_62 ( V_4 ) ;
} else if ( type == ( V_147 | V_127 ) ) {
if ( V_63 . V_150 != 0 )
break;
switch ( F_58 ( V_63 . V_148 ) ) {
case V_152 :
V_4 -> V_111 = 1 ;
V_142 = F_62 ( V_4 ) ;
break;
case V_158 :
V_141 = F_58 ( V_63 . V_130 ) >> 8 ;
switch ( V_141 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
V_4 -> V_136 = V_141 ;
V_142 = F_62 (
V_4 ) ;
break;
default:
break;
}
default:
goto V_153;
}
} else {
goto V_153;
}
break;
default:
V_153:
if ( V_63 . V_150 == 0 )
V_4 -> V_137 = V_55 ;
F_40 ( & V_4 -> V_103 ) ;
V_142 = V_4 -> V_115 -> V_122 ( & V_4 -> V_79 , & V_63 ) ;
F_41 ( & V_4 -> V_103 ) ;
break;
}
if ( V_142 < 0 ) {
F_51 ( F_28 ( V_57 ) , L_4 , V_142 ) ;
F_40 ( & V_4 -> V_103 ) ;
if ( F_67 ( & V_57 -> V_54 ) )
F_53 ( V_4 -> V_118 , L_5 ) ;
F_41 ( & V_4 -> V_103 ) ;
}
}
}
static int F_71 ( struct V_107 * V_54 ,
const struct V_164 * V_143 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
int V_117 = 0 ;
unsigned long V_108 ;
if ( V_54 == NULL || V_143 == NULL )
return - V_37 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
V_57 -> V_54 . V_143 = V_143 ;
if ( ! F_32 ( & V_57 -> V_85 . V_86 ) )
F_68 ( V_57 -> V_4 -> V_118 , L_7 ) ;
V_57 -> V_2 = F_72 ( V_143 ) ? V_55 : V_33 ;
V_57 -> V_1 = F_73 ( V_143 ) ;
V_57 -> type = F_74 ( V_143 ) ;
V_57 -> V_54 . V_67 = F_75 ( V_143 ) ;
F_51 ( F_28 ( V_57 ) , L_8 , 0 ) ;
V_57 -> V_85 . V_80 -> V_95 = 0 ;
if ( V_57 -> type == V_97 )
V_57 -> V_85 . V_80 -> V_95 |= V_165 ;
else if ( V_57 -> type == V_166 )
V_57 -> V_85 . V_80 -> V_95 &= ~ V_167 ;
else
V_57 -> V_85 . V_80 -> V_95 &= ~ V_96 ;
V_57 -> V_85 . V_80 -> V_95 |=
( V_57 -> V_54 . V_67 << F_11 ( V_168 ) ) & V_168 ;
V_57 -> V_85 . V_80 -> V_93 . V_73 |= V_74 ;
if ( V_57 -> V_1 )
V_117 |= F_10 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 , V_57 -> type ) ;
F_45 ( V_57 -> V_103 , V_108 ) ;
return V_117 ;
}
static int F_76 ( struct V_107 * V_54 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
int V_169 , V_117 = 0 ;
unsigned long V_108 ;
if ( V_54 == NULL )
return - V_37 ;
else if ( V_57 -> V_54 . V_143 == NULL )
return - V_98 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
V_169 = V_57 -> V_2 ;
do {
F_51 ( F_28 ( V_57 ) , L_9 , 0 ) ;
V_117 |= F_38 ( V_57 ) ;
V_117 |= F_9 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 ) ;
if ( V_57 -> type == V_97 )
V_57 -> V_2 = ( V_57 -> V_2 == V_55 ) ? V_33 : V_55 ;
} while ( V_57 -> V_2 != V_169 );
V_57 -> V_54 . V_143 = NULL ;
F_45 ( V_57 -> V_103 , V_108 ) ;
return V_117 ;
}
static struct V_119 * F_77 ( struct V_107 * V_54 , T_3 V_123 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
struct V_58 * V_59 = NULL ;
if ( V_54 == NULL )
return NULL ;
V_59 = F_57 ( sizeof( struct V_58 ) , V_123 ) ;
if ( V_59 != NULL ) {
F_78 ( & V_59 -> V_86 ) ;
V_59 -> V_80 = F_30 ( V_57 -> V_69 , V_123 ,
& V_59 -> V_8 ) ;
if ( V_59 -> V_80 == NULL ) {
F_55 ( V_59 ) ;
V_59 = NULL ;
}
}
F_51 ( F_28 ( V_57 ) , L_10 , V_59 == NULL ) ;
return ( V_59 == NULL ) ? NULL : & V_59 -> V_63 ;
}
static void F_79 ( struct V_107 * V_54 , struct V_119 * V_63 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
struct V_58 * V_59 = F_43 ( V_63 , struct V_58 , V_63 ) ;
unsigned long V_108 ;
if ( V_54 == NULL || V_63 == NULL ) {
return;
} else if ( ! F_32 ( & V_59 -> V_86 ) ) {
F_53 ( V_57 -> V_4 -> V_118 , L_11 ) ;
return;
}
F_44 ( V_57 -> V_103 , V_108 ) ;
if ( V_59 -> V_80 )
F_36 ( V_57 -> V_69 , V_59 -> V_80 , V_59 -> V_8 ) ;
F_55 ( V_59 ) ;
F_51 ( F_28 ( V_57 ) , L_12 , 0 ) ;
F_45 ( V_57 -> V_103 , V_108 ) ;
}
static int F_80 ( struct V_107 * V_54 , struct V_119 * V_63 ,
T_3 T_4 V_123 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
struct V_58 * V_59 = F_43 ( V_63 , struct V_58 , V_63 ) ;
struct V_3 * V_4 = V_57 -> V_4 ;
int V_117 = 0 ;
unsigned long V_108 ;
if ( V_54 == NULL || V_63 == NULL || V_57 -> V_54 . V_143 == NULL )
return - V_37 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
if ( V_57 -> type == V_97 ) {
if ( V_63 -> V_62 )
V_57 = ( V_4 -> V_137 == V_33 ) ?
V_4 -> V_113 : V_4 -> V_114 ;
if ( ! F_32 ( & V_57 -> V_85 . V_86 ) ) {
F_38 ( V_57 ) ;
V_117 = - V_170 ;
F_68 ( V_57 -> V_4 -> V_118 , L_13 ,
F_28 ( V_57 ) ) ;
}
}
if ( ! F_32 ( & V_59 -> V_86 ) ) {
V_117 = - V_98 ;
F_53 ( V_57 -> V_4 -> V_118 , L_14 ) ;
goto V_91;
}
if ( V_63 -> V_62 > 4 * V_83 ) {
V_63 -> V_62 = 4 * V_83 ;
V_117 = - V_171 ;
F_68 ( V_57 -> V_4 -> V_118 , L_15 ) ;
}
F_81 ( F_28 ( V_57 ) , V_63 , V_117 ) ;
V_59 -> V_63 . V_64 = - V_172 ;
V_59 -> V_63 . V_102 = 0 ;
V_117 = F_29 ( V_57 , V_59 ) ;
if ( V_117 == - V_65 ) {
F_51 ( F_28 ( V_57 ) , L_16 , V_117 ) ;
V_117 = 0 ;
}
if ( ! V_117 )
F_82 ( & V_59 -> V_86 , & V_57 -> V_85 . V_86 ) ;
V_91:
F_45 ( V_57 -> V_103 , V_108 ) ;
return V_117 ;
}
static int F_83 ( struct V_107 * V_54 , struct V_119 * V_63 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
struct V_58 * V_59 = F_43 ( V_63 , struct V_58 , V_63 ) ;
unsigned long V_108 ;
if ( V_54 == NULL || V_63 == NULL || V_59 -> V_63 . V_64 != - V_65 ||
V_57 -> V_54 . V_143 == NULL || F_32 ( & V_59 -> V_86 ) ||
F_32 ( & V_57 -> V_85 . V_86 ) )
return - V_37 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
F_51 ( F_28 ( V_57 ) , L_17 , 0 ) ;
F_5 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 ) ;
F_39 ( & V_59 -> V_86 ) ;
F_37 ( & V_57 -> V_4 -> V_79 , V_63 , V_57 -> V_2 ) ;
V_63 -> V_64 = - V_173 ;
if ( V_59 -> V_63 . V_105 != NULL ) {
F_40 ( V_57 -> V_103 ) ;
V_59 -> V_63 . V_105 ( & V_57 -> V_54 , & V_59 -> V_63 ) ;
F_41 ( V_57 -> V_103 ) ;
}
F_45 ( V_57 -> V_103 , V_108 ) ;
return 0 ;
}
static int F_84 ( struct V_107 * V_54 , int V_36 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
int V_169 , V_117 = 0 ;
unsigned long V_108 ;
if ( V_54 == NULL || V_57 -> V_54 . V_143 == NULL )
return - V_37 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
#ifndef F_85
if ( V_36 && V_57 -> type == V_174 && V_57 -> V_2 == V_55 &&
! F_32 ( & V_57 -> V_85 . V_86 ) ) {
F_45 ( V_57 -> V_103 , V_108 ) ;
return - V_34 ;
}
#endif
V_169 = V_57 -> V_2 ;
do {
F_51 ( F_28 ( V_57 ) , L_18 , V_36 ) ;
V_117 |= F_16 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 , V_36 ) ;
if ( ! V_36 )
V_57 -> V_151 = 0 ;
if ( V_57 -> type == V_97 )
V_57 -> V_2 = ( V_57 -> V_2 == V_55 ) ? V_33 : V_55 ;
} while ( V_57 -> V_2 != V_169 );
F_45 ( V_57 -> V_103 , V_108 ) ;
return V_117 ;
}
static int F_86 ( struct V_107 * V_54 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
unsigned long V_108 ;
if ( V_54 == NULL || V_57 -> V_54 . V_143 == NULL )
return - V_37 ;
F_44 ( V_57 -> V_103 , V_108 ) ;
F_51 ( F_28 ( V_57 ) , L_19 , 0 ) ;
V_57 -> V_151 = 1 ;
F_45 ( V_57 -> V_103 , V_108 ) ;
return F_67 ( V_54 ) ;
}
static void F_87 ( struct V_107 * V_54 )
{
struct V_53 * V_57 = F_43 ( V_54 , struct V_53 , V_54 ) ;
unsigned long V_108 ;
if ( V_54 == NULL ) {
F_53 ( V_57 -> V_4 -> V_118 , L_20 , F_28 ( V_57 ) ) ;
return;
}
F_44 ( V_57 -> V_103 , V_108 ) ;
F_51 ( F_28 ( V_57 ) , L_21 , 0 ) ;
F_5 ( V_57 -> V_4 , V_57 -> V_1 , V_57 -> V_2 ) ;
F_45 ( V_57 -> V_103 , V_108 ) ;
}
static int F_88 ( struct V_106 * V_175 , int V_176 )
{
struct V_3 * V_4 = F_43 ( V_175 , struct V_3 , V_79 ) ;
unsigned long V_108 ;
int V_177 = 0 ;
if ( ! ( V_4 -> V_178 -> V_108 & V_179 ) )
return - V_180 ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
V_4 -> V_181 = V_176 ;
if ( V_4 -> V_115 )
V_177 = 1 ;
F_45 ( & V_4 -> V_103 , V_108 ) ;
if ( V_177 ) {
if ( V_176 ) {
F_89 ( & V_175 -> V_118 ) ;
F_90 ( V_4 , V_182 ) ;
F_3 ( V_4 , V_4 -> V_113 -> V_85 . V_8 ) ;
} else {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_178 -> V_183 )
V_4 -> V_178 -> V_183 ( V_4 ,
V_184 ) ;
F_42 ( & V_4 -> V_79 ) ;
F_91 ( & V_175 -> V_118 ) ;
}
}
return 0 ;
}
static int F_92 ( struct V_106 * V_175 )
{
struct V_3 * V_4 = F_43 ( V_175 , struct V_3 , V_79 ) ;
unsigned long V_108 ;
int V_61 = 0 ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
if ( ! V_4 -> V_111 ) {
V_61 = - V_180 ;
goto V_185;
}
if ( ! F_7 ( V_4 , V_46 , V_186 ) ) {
V_61 = - V_37 ;
goto V_185;
}
F_4 ( V_4 , V_46 , V_187 , V_187 ) ;
V_185:
F_45 ( & V_4 -> V_103 , V_108 ) ;
return V_61 ;
}
static int F_93 ( struct V_106 * V_175 , unsigned V_188 )
{
struct V_3 * V_4 = F_43 ( V_175 , struct V_3 , V_79 ) ;
if ( V_4 -> V_189 )
return F_94 ( V_4 -> V_189 , V_188 ) ;
return - V_190 ;
}
static int F_95 ( struct V_3 * V_4 )
{
int V_117 = 0 , V_60 , V_191 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_7 / 2 ; V_60 ++ )
for ( V_191 = V_33 ; V_191 <= V_55 ; V_191 ++ ) {
int V_192 = V_60 + V_191 * V_4 -> V_7 / 2 ;
struct V_53 * V_57 = & V_4 -> V_53 [ V_192 ] ;
F_96 ( V_57 -> V_193 , sizeof( V_57 -> V_193 ) , L_22 , V_60 ,
( V_191 == V_55 ) ? L_23 : L_24 ) ;
V_57 -> V_4 = V_4 ;
V_57 -> V_103 = & V_4 -> V_103 ;
V_57 -> V_69 = V_4 -> V_69 ;
V_57 -> V_54 . V_193 = V_57 -> V_193 ;
V_57 -> V_54 . V_194 = & V_195 ;
V_57 -> V_54 . V_67 = V_196 ;
F_78 ( & V_57 -> V_85 . V_86 ) ;
V_57 -> V_85 . V_80 = F_30 ( V_4 -> V_197 , V_198 ,
& V_57 -> V_85 . V_8 ) ;
if ( V_57 -> V_85 . V_80 == NULL )
V_117 = - V_72 ;
else
memset ( V_57 -> V_85 . V_80 , 0 , sizeof( * V_57 -> V_85 . V_80 ) ) ;
if ( V_60 == 0 ) {
if ( V_191 == V_33 )
V_4 -> V_113 = V_57 ;
else
V_4 -> V_114 = V_57 ;
continue;
}
F_82 ( & V_57 -> V_54 . V_199 , & V_4 -> V_79 . V_199 ) ;
}
return V_117 ;
}
static int F_97 ( struct V_106 * V_79 ,
struct V_200 * V_115 )
{
struct V_3 * V_4 = F_43 ( V_79 , struct V_3 , V_79 ) ;
unsigned long V_108 ;
int V_117 = - V_72 ;
if ( V_115 -> V_116 == NULL )
return - V_37 ;
V_4 -> V_113 -> V_54 . V_143 = & V_201 ;
V_117 = F_98 ( & V_4 -> V_113 -> V_54 ) ;
if ( V_117 )
return V_117 ;
V_4 -> V_114 -> V_54 . V_143 = & V_202 ;
V_117 = F_98 ( & V_4 -> V_114 -> V_54 ) ;
if ( V_117 )
return V_117 ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
V_4 -> V_115 = V_115 ;
F_89 ( & V_4 -> V_79 . V_118 ) ;
if ( V_4 -> V_178 -> V_108 & V_179 ) {
if ( V_4 -> V_181 ) {
if ( V_4 -> V_178 -> V_108 & V_203 )
F_90 ( V_4 , V_182 ) ;
} else {
F_91 ( & V_4 -> V_79 . V_118 ) ;
goto V_91;
}
}
V_117 = F_3 ( V_4 , V_4 -> V_113 -> V_85 . V_8 ) ;
if ( V_117 )
F_91 ( & V_4 -> V_79 . V_118 ) ;
V_91:
F_45 ( & V_4 -> V_103 , V_108 ) ;
return V_117 ;
}
static int F_99 ( struct V_106 * V_79 ,
struct V_200 * V_115 )
{
struct V_3 * V_4 = F_43 ( V_79 , struct V_3 , V_79 ) ;
unsigned long V_108 ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
if ( ! ( V_4 -> V_178 -> V_108 & V_179 ) ||
V_4 -> V_181 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_178 -> V_183 )
V_4 -> V_178 -> V_183 ( V_4 ,
V_184 ) ;
V_4 -> V_115 = NULL ;
F_45 ( & V_4 -> V_103 , V_108 ) ;
F_42 ( & V_4 -> V_79 ) ;
F_44 ( & V_4 -> V_103 , V_108 ) ;
F_100 ( & V_4 -> V_79 . V_118 ) ;
}
F_45 ( & V_4 -> V_103 , V_108 ) ;
return 0 ;
}
static T_5 F_101 ( struct V_3 * V_4 )
{
T_5 V_117 ;
T_1 V_204 ;
if ( V_4 == NULL )
return V_205 ;
F_41 ( & V_4 -> V_103 ) ;
if ( V_4 -> V_178 -> V_108 & V_203 ) {
if ( F_7 ( V_4 , V_206 , V_207 ) !=
V_182 ) {
F_40 ( & V_4 -> V_103 ) ;
return V_208 ;
}
}
V_204 = F_21 ( V_4 ) ;
F_102 ( V_204 ) ;
if ( V_204 ) {
if ( V_14 & V_204 )
F_50 ( V_4 ) ;
if ( V_13 & V_204 ) {
V_4 -> V_79 . V_109 = F_17 ( V_4 ) ?
V_209 : V_210 ;
if ( V_4 -> V_112 && V_4 -> V_115 -> V_211 ) {
F_40 ( & V_4 -> V_103 ) ;
V_4 -> V_115 -> V_211 ( & V_4 -> V_79 ) ;
F_41 ( & V_4 -> V_103 ) ;
V_4 -> V_112 = 0 ;
}
}
if ( V_11 & V_204 )
F_66 ( V_4 ) ;
if ( V_15 & V_204 ) {
if ( V_4 -> V_79 . V_109 != V_110 &&
V_4 -> V_115 -> V_212 ) {
V_4 -> V_112 = 1 ;
F_40 ( & V_4 -> V_103 ) ;
V_4 -> V_115 -> V_212 ( & V_4 -> V_79 ) ;
F_41 ( & V_4 -> V_103 ) ;
}
}
V_117 = V_205 ;
} else {
V_117 = V_208 ;
}
F_40 ( & V_4 -> V_103 ) ;
return V_117 ;
}
static void F_103 ( struct V_213 * V_118 )
{
}
static int F_104 ( struct V_3 * V_4 )
{
struct V_213 * V_118 = V_4 -> V_118 ;
int V_117 = 0 ;
if ( ! V_4 )
return - V_37 ;
F_105 ( & V_4 -> V_103 ) ;
V_4 -> V_79 . V_194 = & V_214 ;
V_4 -> V_79 . V_109 = V_110 ;
V_4 -> V_79 . V_215 = V_209 ;
V_4 -> V_79 . V_216 = 0 ;
V_4 -> V_79 . V_193 = V_4 -> V_178 -> V_193 ;
F_78 ( & V_4 -> V_79 . V_199 ) ;
F_106 ( & V_4 -> V_79 . V_118 , L_25 ) ;
V_4 -> V_79 . V_118 . V_217 = V_118 -> V_217 ;
V_4 -> V_79 . V_118 . V_218 = V_118 -> V_218 ;
V_4 -> V_79 . V_118 . V_219 = V_118 ;
V_4 -> V_79 . V_118 . V_220 = F_103 ;
V_4 -> V_197 = F_107 ( L_26 , V_118 ,
sizeof( struct V_221 ) ,
64 , V_83 ) ;
if ( V_4 -> V_197 == NULL )
return - V_72 ;
V_4 -> V_69 = F_107 ( L_27 , V_118 ,
sizeof( struct V_222 ) ,
64 , V_83 ) ;
if ( V_4 -> V_69 == NULL ) {
V_117 = - V_72 ;
goto V_223;
}
V_117 = F_95 ( V_4 ) ;
if ( V_117 )
goto V_224;
V_4 -> V_79 . V_225 = & V_4 -> V_114 -> V_54 ;
V_4 -> V_189 = F_108 () ;
if ( V_4 -> V_178 -> V_108 & V_226 ) {
if ( V_4 -> V_189 == NULL ) {
V_117 = - V_227 ;
goto V_224;
}
}
if ( ! ( V_4 -> V_178 -> V_108 & V_203 ) ) {
V_117 = F_90 ( V_4 , V_182 ) ;
if ( V_117 )
goto V_228;
}
V_117 = F_109 ( & V_4 -> V_79 . V_118 ) ;
if ( V_117 ) {
F_110 ( & V_4 -> V_79 . V_118 ) ;
goto V_228;
}
V_117 = F_111 ( & V_4 -> V_79 . V_118 ) ;
if ( V_117 )
goto V_229;
if ( V_4 -> V_189 ) {
V_117 = F_112 ( V_4 -> V_189 -> V_230 ,
& V_4 -> V_79 ) ;
if ( V_117 )
goto V_231;
}
V_117 = F_113 ( V_118 , & V_4 -> V_79 ) ;
if ( V_117 )
goto V_232;
F_114 ( & V_4 -> V_79 . V_118 ) ;
F_115 ( & V_4 -> V_79 . V_118 ) ;
return V_117 ;
V_232:
if ( V_4 -> V_189 ) {
F_112 ( V_4 -> V_189 -> V_230 , & V_4 -> V_79 ) ;
F_116 ( V_4 -> V_189 ) ;
}
F_53 ( V_118 , L_28 , V_117 ) ;
V_231:
F_117 ( & V_4 -> V_79 . V_118 ) ;
V_229:
F_118 ( & V_4 -> V_79 . V_118 ) ;
V_228:
if ( V_4 -> V_189 )
F_116 ( V_4 -> V_189 ) ;
V_224:
F_119 ( V_4 -> V_69 ) ;
V_223:
F_119 ( V_4 -> V_197 ) ;
return V_117 ;
}
static void F_120 ( struct V_3 * V_4 )
{
int V_60 ;
if ( V_4 == NULL )
return;
F_121 ( & V_4 -> V_79 ) ;
for ( V_60 = 0 ; V_60 < V_4 -> V_7 ; V_60 ++ ) {
struct V_53 * V_57 = & V_4 -> V_53 [ V_60 ] ;
F_36 ( V_4 -> V_197 , V_57 -> V_85 . V_80 , V_57 -> V_85 . V_8 ) ;
}
F_119 ( V_4 -> V_69 ) ;
F_119 ( V_4 -> V_197 ) ;
if ( V_4 -> V_189 ) {
F_112 ( V_4 -> V_189 -> V_230 , NULL ) ;
F_116 ( V_4 -> V_189 ) ;
}
F_117 ( & V_4 -> V_79 . V_118 ) ;
F_118 ( & V_4 -> V_79 . V_118 ) ;
memset ( & V_4 -> V_79 , 0 , sizeof( V_4 -> V_79 ) ) ;
}
int F_122 ( struct V_3 * V_233 )
{
struct V_234 * V_235 ;
if ( ! F_7 ( V_233 , V_236 , V_237 ) )
return - V_238 ;
V_235 = F_123 ( V_233 -> V_118 , sizeof( struct V_234 ) , V_198 ) ;
if ( ! V_235 )
return - V_72 ;
V_235 -> V_239 = F_104 ;
V_235 -> V_240 = F_120 ;
V_235 -> V_241 = F_101 ;
V_235 -> V_193 = L_25 ;
V_233 -> V_242 [ V_243 ] = V_235 ;
return 0 ;
}
