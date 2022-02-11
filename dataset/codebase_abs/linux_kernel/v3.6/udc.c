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
static inline T_2 F_28 ( struct V_52 * V_53 )
{
return ( ( V_53 -> V_2 == V_54 ) ? V_55 : 0 ) | V_53 -> V_1 ;
}
static int F_29 ( struct V_52 * V_56 , struct V_57 * V_58 )
{
struct V_3 * V_4 = V_56 -> V_4 ;
unsigned V_59 ;
int V_60 = 0 ;
unsigned V_61 = V_58 -> V_62 . V_61 ;
if ( V_58 -> V_62 . V_63 == - V_64 )
return - V_64 ;
V_58 -> V_62 . V_63 = - V_64 ;
if ( V_58 -> V_62 . V_65 && V_61 && ( V_61 % V_56 -> V_53 . V_66 == 0 ) ) {
V_58 -> V_67 = F_30 ( V_56 -> V_68 , V_69 ,
& V_58 -> V_70 ) ;
if ( V_58 -> V_67 == NULL )
return - V_71 ;
memset ( V_58 -> V_67 , 0 , sizeof( * V_58 -> V_67 ) ) ;
V_58 -> V_67 -> V_72 = V_73 ;
V_58 -> V_67 -> V_74 = V_75 ;
if ( ! V_58 -> V_62 . V_76 )
V_58 -> V_67 -> V_74 |= V_77 ;
}
V_60 = F_31 ( & V_4 -> V_78 , & V_58 -> V_62 , V_56 -> V_2 ) ;
if ( V_60 )
return V_60 ;
memset ( V_58 -> V_79 , 0 , sizeof( * V_58 -> V_79 ) ) ;
V_58 -> V_79 -> V_74 = V_61 << F_11 ( V_80 ) ;
V_58 -> V_79 -> V_74 &= V_80 ;
V_58 -> V_79 -> V_74 |= V_75 ;
if ( V_58 -> V_67 ) {
V_58 -> V_79 -> V_72 = V_58 -> V_70 ;
} else {
V_58 -> V_79 -> V_72 = V_73 ;
if ( ! V_58 -> V_62 . V_76 )
V_58 -> V_79 -> V_74 |= V_77 ;
}
V_58 -> V_79 -> V_81 [ 0 ] = V_58 -> V_62 . V_8 ;
for ( V_59 = 1 ; V_59 < 5 ; V_59 ++ )
V_58 -> V_79 -> V_81 [ V_59 ] =
( V_58 -> V_62 . V_8 + V_59 * V_82 ) & ~ V_83 ;
if ( ! F_32 ( & V_56 -> V_84 . V_85 ) ) {
struct V_57 * V_86 ;
int V_5 = F_1 ( V_56 -> V_1 , V_56 -> V_2 ) ;
int V_87 ;
V_86 = F_33 ( V_56 -> V_84 . V_85 . V_88 ,
struct V_57 , V_85 ) ;
if ( V_86 -> V_67 )
V_86 -> V_67 -> V_72 = V_58 -> V_8 & V_89 ;
else
V_86 -> V_79 -> V_72 = V_58 -> V_8 & V_89 ;
F_34 () ;
if ( F_7 ( V_4 , V_33 , F_6 ( V_5 ) ) )
goto V_90;
do {
F_4 ( V_4 , V_48 , V_91 , V_91 ) ;
V_87 = F_7 ( V_4 , V_17 , F_6 ( V_5 ) ) ;
} while ( ! F_7 ( V_4 , V_48 , V_91 ) );
F_4 ( V_4 , V_48 , V_91 , 0 ) ;
if ( V_87 )
goto V_90;
}
V_56 -> V_84 . V_79 -> V_92 . V_72 = V_58 -> V_8 ;
V_56 -> V_84 . V_79 -> V_92 . V_74 &= ~ V_93 ;
V_56 -> V_84 . V_79 -> V_94 |= V_95 ;
F_34 () ;
V_60 = F_15 ( V_4 , V_56 -> V_1 , V_56 -> V_2 ,
V_56 -> type == V_96 ) ;
V_90:
return V_60 ;
}
static int F_35 ( struct V_52 * V_56 , struct V_57 * V_58 )
{
if ( V_58 -> V_62 . V_63 != - V_64 )
return - V_35 ;
if ( ( V_75 & V_58 -> V_79 -> V_74 ) != 0 )
return - V_97 ;
if ( V_58 -> V_67 ) {
if ( ( V_75 & V_58 -> V_67 -> V_74 ) != 0 )
return - V_97 ;
F_36 ( V_56 -> V_68 , V_58 -> V_67 , V_58 -> V_70 ) ;
V_58 -> V_67 = NULL ;
}
V_58 -> V_62 . V_63 = 0 ;
F_37 ( & V_56 -> V_4 -> V_78 , & V_58 -> V_62 , V_56 -> V_2 ) ;
V_58 -> V_62 . V_63 = V_58 -> V_79 -> V_74 & V_93 ;
if ( ( V_98 & V_58 -> V_62 . V_63 ) != 0 )
V_58 -> V_62 . V_63 = - 1 ;
else if ( ( V_99 & V_58 -> V_62 . V_63 ) != 0 )
V_58 -> V_62 . V_63 = - 1 ;
else if ( ( V_100 & V_58 -> V_62 . V_63 ) != 0 )
V_58 -> V_62 . V_63 = - 1 ;
V_58 -> V_62 . V_101 = V_58 -> V_79 -> V_74 & V_80 ;
V_58 -> V_62 . V_101 >>= F_11 ( V_80 ) ;
V_58 -> V_62 . V_101 = V_58 -> V_62 . V_61 - V_58 -> V_62 . V_101 ;
V_58 -> V_62 . V_101 = V_58 -> V_62 . V_63 ? 0 : V_58 -> V_62 . V_101 ;
return V_58 -> V_62 . V_101 ;
}
static int F_38 ( struct V_52 * V_56 )
__releases( V_56 -> V_102 )
__acquires( V_56 -> V_102 )
{
if ( V_56 == NULL )
return - V_35 ;
F_5 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 ) ;
while ( ! F_32 ( & V_56 -> V_84 . V_85 ) ) {
struct V_57 * V_58 = \
F_33 ( V_56 -> V_84 . V_85 . V_72 ,
struct V_57 , V_85 ) ;
F_39 ( & V_58 -> V_85 ) ;
V_58 -> V_62 . V_63 = - V_103 ;
if ( V_58 -> V_62 . V_104 != NULL ) {
F_40 ( V_56 -> V_102 ) ;
V_58 -> V_62 . V_104 ( & V_56 -> V_53 , & V_58 -> V_62 ) ;
F_41 ( V_56 -> V_102 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_105 * V_78 )
{
struct V_106 * V_53 ;
struct V_3 * V_4 = F_43 ( V_78 , struct V_3 , V_78 ) ;
unsigned long V_107 ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
V_4 -> V_78 . V_108 = V_109 ;
V_4 -> V_110 = 0 ;
V_4 -> V_111 = 0 ;
F_45 ( & V_4 -> V_102 , V_107 ) ;
F_46 (ep, gadget) {
F_47 ( V_53 ) ;
}
F_47 ( & V_4 -> V_112 -> V_53 ) ;
F_47 ( & V_4 -> V_113 -> V_53 ) ;
if ( V_4 -> V_114 )
V_4 -> V_114 -> V_115 ( V_78 ) ;
F_46 (ep, gadget) {
F_48 ( V_53 ) ;
}
if ( V_4 -> V_63 != NULL ) {
F_49 ( & V_4 -> V_113 -> V_53 , V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
}
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
__releases( V_4 -> V_102 )
__acquires( V_4 -> V_102 )
{
int V_116 ;
F_51 ( 0xFF , L_1 , 0 ) ;
F_40 ( & V_4 -> V_102 ) ;
V_116 = F_42 ( & V_4 -> V_78 ) ;
if ( V_116 )
goto V_90;
V_116 = F_26 ( V_4 ) ;
if ( V_116 )
goto V_90;
V_4 -> V_63 = F_52 ( & V_4 -> V_113 -> V_53 , V_69 ) ;
if ( V_4 -> V_63 == NULL )
V_116 = - V_71 ;
V_90:
F_41 ( & V_4 -> V_102 ) ;
if ( V_116 )
F_53 ( V_4 -> V_117 , L_2 , V_116 ) ;
}
static void F_54 ( struct V_106 * V_53 , struct V_118 * V_62 )
{
if ( V_53 == NULL || V_62 == NULL )
return;
F_55 ( V_62 -> V_119 ) ;
F_49 ( V_53 , V_62 ) ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_120 * V_121 )
__releases( V_56 -> V_102 )
__acquires( V_56 -> V_102 )
{
struct V_52 * V_56 = V_4 -> V_113 ;
struct V_118 * V_62 = NULL ;
T_3 V_122 = V_69 ;
int V_2 , V_1 , V_116 ;
if ( V_56 == NULL || V_121 == NULL )
return - V_35 ;
F_40 ( V_56 -> V_102 ) ;
V_62 = F_52 ( & V_56 -> V_53 , V_122 ) ;
F_41 ( V_56 -> V_102 ) ;
if ( V_62 == NULL )
return - V_71 ;
V_62 -> V_104 = F_54 ;
V_62 -> V_61 = 2 ;
V_62 -> V_119 = F_57 ( V_62 -> V_61 , V_122 ) ;
if ( V_62 -> V_119 == NULL ) {
V_116 = - V_71 ;
goto V_123;
}
if ( ( V_121 -> V_124 & V_125 ) == V_126 ) {
* ( V_127 * ) V_62 -> V_119 = V_4 -> V_110 << 1 ;
V_116 = 0 ;
} else if ( ( V_121 -> V_124 & V_125 ) \
== V_128 ) {
V_2 = ( F_58 ( V_121 -> V_129 ) & V_55 ) ?
V_54 : V_31 ;
V_1 = F_58 ( V_121 -> V_129 ) & V_130 ;
* ( V_127 * ) V_62 -> V_119 = F_12 ( V_4 , V_1 , V_2 ) ;
}
F_40 ( V_56 -> V_102 ) ;
V_116 = F_59 ( & V_56 -> V_53 , V_62 , V_122 ) ;
F_41 ( V_56 -> V_102 ) ;
if ( V_116 )
goto V_131;
return 0 ;
V_131:
F_55 ( V_62 -> V_119 ) ;
V_123:
F_40 ( V_56 -> V_102 ) ;
F_49 ( & V_56 -> V_53 , V_62 ) ;
F_41 ( V_56 -> V_102 ) ;
return V_116 ;
}
static void
F_60 ( struct V_106 * V_53 , struct V_118 * V_62 )
{
struct V_3 * V_4 = V_62 -> V_132 ;
unsigned long V_107 ;
if ( V_4 -> V_133 ) {
F_25 ( V_4 , V_4 -> V_134 ) ;
V_4 -> V_133 = false ;
}
F_44 ( & V_4 -> V_102 , V_107 ) ;
if ( V_4 -> V_135 )
F_61 ( V_4 , V_4 -> V_135 ) ;
F_45 ( & V_4 -> V_102 , V_107 ) ;
}
static int F_62 ( struct V_3 * V_4 )
__releases( V_56 -> V_102 )
__acquires( V_56 -> V_102 )
{
int V_116 ;
struct V_52 * V_56 ;
V_56 = ( V_4 -> V_136 == V_54 ) ? V_4 -> V_112 : V_4 -> V_113 ;
V_4 -> V_63 -> V_132 = V_4 ;
V_4 -> V_63 -> V_104 = F_60 ;
F_40 ( V_56 -> V_102 ) ;
V_116 = F_59 ( & V_56 -> V_53 , V_4 -> V_63 , V_69 ) ;
F_41 ( V_56 -> V_102 ) ;
return V_116 ;
}
static int F_63 ( struct V_52 * V_56 )
__releases( V_56 -> V_102 )
__acquires( V_56 -> V_102 )
{
struct V_57 * V_58 , * V_137 ;
struct V_52 * V_138 = V_56 ;
int V_116 = 0 ;
F_64 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_116 = F_35 ( V_56 , V_58 ) ;
if ( V_116 < 0 )
break;
F_39 ( & V_58 -> V_85 ) ;
F_65 ( F_28 ( V_56 ) , V_58 -> V_79 -> V_74 , V_116 ) ;
if ( V_58 -> V_62 . V_104 != NULL ) {
F_40 ( V_56 -> V_102 ) ;
if ( ( V_56 -> type == V_96 ) &&
V_58 -> V_62 . V_61 )
V_138 = V_56 -> V_4 -> V_113 ;
V_58 -> V_62 . V_104 ( & V_138 -> V_53 , & V_58 -> V_62 ) ;
F_41 ( V_56 -> V_102 ) ;
}
}
if ( V_116 == - V_97 )
V_116 = 0 ;
if ( V_116 < 0 )
F_51 ( F_28 ( V_56 ) , L_3 , V_116 ) ;
return V_116 ;
}
static void F_66 ( struct V_3 * V_4 )
__releases( V_4 -> V_102 )
__acquires( V_4 -> V_102 )
{
unsigned V_59 ;
T_2 V_139 = 0 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_7 ; V_59 ++ ) {
struct V_52 * V_56 = & V_4 -> V_52 [ V_59 ] ;
int type , V_1 , V_2 , V_140 = - V_35 ;
struct V_120 V_62 ;
if ( V_56 -> V_53 . V_141 == NULL )
continue;
if ( F_20 ( V_4 , V_59 ) ) {
V_140 = F_63 ( V_56 ) ;
if ( V_56 -> type == V_96 ) {
if ( V_140 > 0 )
V_140 = F_62 ( V_4 ) ;
if ( V_140 < 0 ) {
F_51 ( F_28 ( V_56 ) ,
L_4 , V_140 ) ;
F_40 ( & V_4 -> V_102 ) ;
if ( F_67 ( & V_56 -> V_53 ) )
F_53 ( V_4 -> V_117 ,
L_5 ) ;
F_41 ( & V_4 -> V_102 ) ;
}
}
}
if ( V_56 -> type != V_96 ||
! F_13 ( V_4 , V_59 ) )
continue;
if ( V_59 != 0 ) {
F_68 ( V_4 -> V_117 , L_6 , V_59 ) ;
continue;
}
F_38 ( V_4 -> V_112 ) ;
F_38 ( V_4 -> V_113 ) ;
do {
F_24 ( V_4 ) ;
memcpy ( & V_62 , & V_56 -> V_84 . V_79 -> V_121 , sizeof( V_62 ) ) ;
} while ( ! F_22 ( V_4 ) );
type = V_62 . V_124 ;
V_4 -> V_136 = ( type & V_142 ) ? V_54 : V_31 ;
F_69 ( F_28 ( V_56 ) , & V_62 ) ;
switch ( V_62 . V_143 ) {
case V_144 :
if ( type == ( V_145 | V_128 ) &&
F_58 ( V_62 . V_146 ) ==
V_147 ) {
if ( V_62 . V_148 != 0 )
break;
V_1 = F_58 ( V_62 . V_129 ) ;
V_2 = V_1 & V_55 ;
V_1 &= V_130 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
if ( ! V_4 -> V_52 [ V_1 ] . V_149 ) {
F_40 ( & V_4 -> V_102 ) ;
V_140 = F_70 (
& V_4 -> V_52 [ V_1 ] . V_53 ) ;
F_41 ( & V_4 -> V_102 ) ;
if ( V_140 )
break;
}
V_140 = F_62 ( V_4 ) ;
} else if ( type == ( V_145 | V_126 ) &&
F_58 ( V_62 . V_146 ) ==
V_150 ) {
if ( V_62 . V_148 != 0 )
break;
V_4 -> V_110 = 0 ;
V_140 = F_62 ( V_4 ) ;
} else {
goto V_151;
}
break;
case V_152 :
if ( type != ( V_142 | V_126 ) &&
type != ( V_142 | V_128 ) &&
type != ( V_142 | V_153 ) )
goto V_151;
if ( F_58 ( V_62 . V_148 ) != 2 ||
F_58 ( V_62 . V_146 ) != 0 )
break;
V_140 = F_56 ( V_4 , & V_62 ) ;
break;
case V_154 :
if ( type != ( V_145 | V_126 ) )
goto V_151;
if ( F_58 ( V_62 . V_148 ) != 0 ||
F_58 ( V_62 . V_129 ) != 0 )
break;
V_4 -> V_134 = ( T_2 ) F_58 ( V_62 . V_146 ) ;
V_4 -> V_133 = true ;
V_140 = F_62 ( V_4 ) ;
break;
case V_155 :
if ( type == ( V_145 | V_128 ) &&
F_58 ( V_62 . V_146 ) ==
V_147 ) {
if ( V_62 . V_148 != 0 )
break;
V_1 = F_58 ( V_62 . V_129 ) ;
V_2 = V_1 & V_55 ;
V_1 &= V_130 ;
if ( V_2 )
V_1 += V_4 -> V_7 / 2 ;
F_40 ( & V_4 -> V_102 ) ;
V_140 = F_67 ( & V_4 -> V_52 [ V_1 ] . V_53 ) ;
F_41 ( & V_4 -> V_102 ) ;
if ( ! V_140 )
F_62 ( V_4 ) ;
} else if ( type == ( V_145 | V_126 ) ) {
if ( V_62 . V_148 != 0 )
break;
switch ( F_58 ( V_62 . V_146 ) ) {
case V_150 :
V_4 -> V_110 = 1 ;
V_140 = F_62 ( V_4 ) ;
break;
case V_156 :
V_139 = F_58 ( V_62 . V_129 ) >> 8 ;
switch ( V_139 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_4 -> V_135 = V_139 ;
V_140 = F_62 (
V_4 ) ;
break;
default:
break;
}
default:
goto V_151;
}
} else {
goto V_151;
}
break;
default:
V_151:
if ( V_62 . V_148 == 0 )
V_4 -> V_136 = V_54 ;
F_40 ( & V_4 -> V_102 ) ;
V_140 = V_4 -> V_114 -> V_121 ( & V_4 -> V_78 , & V_62 ) ;
F_41 ( & V_4 -> V_102 ) ;
break;
}
if ( V_140 < 0 ) {
F_51 ( F_28 ( V_56 ) , L_4 , V_140 ) ;
F_40 ( & V_4 -> V_102 ) ;
if ( F_67 ( & V_56 -> V_53 ) )
F_53 ( V_4 -> V_117 , L_5 ) ;
F_41 ( & V_4 -> V_102 ) ;
}
}
}
static int F_71 ( struct V_106 * V_53 ,
const struct V_162 * V_141 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
int V_116 = 0 ;
unsigned long V_107 ;
if ( V_53 == NULL || V_141 == NULL )
return - V_35 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
V_56 -> V_53 . V_141 = V_141 ;
if ( ! F_32 ( & V_56 -> V_84 . V_85 ) )
F_68 ( V_56 -> V_4 -> V_117 , L_7 ) ;
V_56 -> V_2 = F_72 ( V_141 ) ? V_54 : V_31 ;
V_56 -> V_1 = F_73 ( V_141 ) ;
V_56 -> type = F_74 ( V_141 ) ;
V_56 -> V_53 . V_66 = F_75 ( V_141 ) ;
F_51 ( F_28 ( V_56 ) , L_8 , 0 ) ;
V_56 -> V_84 . V_79 -> V_94 = 0 ;
if ( V_56 -> type == V_96 )
V_56 -> V_84 . V_79 -> V_94 |= V_163 ;
else if ( V_56 -> type == V_164 )
V_56 -> V_84 . V_79 -> V_94 &= ~ V_165 ;
else
V_56 -> V_84 . V_79 -> V_94 &= ~ V_95 ;
V_56 -> V_84 . V_79 -> V_94 |=
( V_56 -> V_53 . V_66 << F_11 ( V_166 ) ) & V_166 ;
V_56 -> V_84 . V_79 -> V_92 . V_72 |= V_73 ;
if ( V_56 -> V_1 )
V_116 |= F_10 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 , V_56 -> type ) ;
F_45 ( V_56 -> V_102 , V_107 ) ;
return V_116 ;
}
static int F_76 ( struct V_106 * V_53 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
int V_167 , V_116 = 0 ;
unsigned long V_107 ;
if ( V_53 == NULL )
return - V_35 ;
else if ( V_56 -> V_53 . V_141 == NULL )
return - V_97 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
V_167 = V_56 -> V_2 ;
do {
F_51 ( F_28 ( V_56 ) , L_9 , 0 ) ;
V_116 |= F_38 ( V_56 ) ;
V_116 |= F_9 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 ) ;
if ( V_56 -> type == V_96 )
V_56 -> V_2 = ( V_56 -> V_2 == V_54 ) ? V_31 : V_54 ;
} while ( V_56 -> V_2 != V_167 );
V_56 -> V_53 . V_141 = NULL ;
F_45 ( V_56 -> V_102 , V_107 ) ;
return V_116 ;
}
static struct V_118 * F_77 ( struct V_106 * V_53 , T_3 V_122 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
struct V_57 * V_58 = NULL ;
if ( V_53 == NULL )
return NULL ;
V_58 = F_57 ( sizeof( struct V_57 ) , V_122 ) ;
if ( V_58 != NULL ) {
F_78 ( & V_58 -> V_85 ) ;
V_58 -> V_79 = F_30 ( V_56 -> V_68 , V_122 ,
& V_58 -> V_8 ) ;
if ( V_58 -> V_79 == NULL ) {
F_55 ( V_58 ) ;
V_58 = NULL ;
}
}
F_51 ( F_28 ( V_56 ) , L_10 , V_58 == NULL ) ;
return ( V_58 == NULL ) ? NULL : & V_58 -> V_62 ;
}
static void F_79 ( struct V_106 * V_53 , struct V_118 * V_62 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
struct V_57 * V_58 = F_43 ( V_62 , struct V_57 , V_62 ) ;
unsigned long V_107 ;
if ( V_53 == NULL || V_62 == NULL ) {
return;
} else if ( ! F_32 ( & V_58 -> V_85 ) ) {
F_53 ( V_56 -> V_4 -> V_117 , L_11 ) ;
return;
}
F_44 ( V_56 -> V_102 , V_107 ) ;
if ( V_58 -> V_79 )
F_36 ( V_56 -> V_68 , V_58 -> V_79 , V_58 -> V_8 ) ;
F_55 ( V_58 ) ;
F_51 ( F_28 ( V_56 ) , L_12 , 0 ) ;
F_45 ( V_56 -> V_102 , V_107 ) ;
}
static int F_80 ( struct V_106 * V_53 , struct V_118 * V_62 ,
T_3 T_4 V_122 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
struct V_57 * V_58 = F_43 ( V_62 , struct V_57 , V_62 ) ;
struct V_3 * V_4 = V_56 -> V_4 ;
int V_116 = 0 ;
unsigned long V_107 ;
if ( V_53 == NULL || V_62 == NULL || V_56 -> V_53 . V_141 == NULL )
return - V_35 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
if ( V_56 -> type == V_96 ) {
if ( V_62 -> V_61 )
V_56 = ( V_4 -> V_136 == V_31 ) ?
V_4 -> V_112 : V_4 -> V_113 ;
if ( ! F_32 ( & V_56 -> V_84 . V_85 ) ) {
F_38 ( V_56 ) ;
V_116 = - V_168 ;
F_68 ( V_56 -> V_4 -> V_117 , L_13 ,
F_28 ( V_56 ) ) ;
}
}
if ( ! F_32 ( & V_58 -> V_85 ) ) {
V_116 = - V_97 ;
F_53 ( V_56 -> V_4 -> V_117 , L_14 ) ;
goto V_90;
}
if ( V_62 -> V_61 > 4 * V_82 ) {
V_62 -> V_61 = 4 * V_82 ;
V_116 = - V_169 ;
F_68 ( V_56 -> V_4 -> V_117 , L_15 ) ;
}
F_81 ( F_28 ( V_56 ) , V_62 , V_116 ) ;
V_58 -> V_62 . V_63 = - V_170 ;
V_58 -> V_62 . V_101 = 0 ;
V_116 = F_29 ( V_56 , V_58 ) ;
if ( V_116 == - V_64 ) {
F_51 ( F_28 ( V_56 ) , L_16 , V_116 ) ;
V_116 = 0 ;
}
if ( ! V_116 )
F_82 ( & V_58 -> V_85 , & V_56 -> V_84 . V_85 ) ;
V_90:
F_45 ( V_56 -> V_102 , V_107 ) ;
return V_116 ;
}
static int F_83 ( struct V_106 * V_53 , struct V_118 * V_62 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
struct V_57 * V_58 = F_43 ( V_62 , struct V_57 , V_62 ) ;
unsigned long V_107 ;
if ( V_53 == NULL || V_62 == NULL || V_58 -> V_62 . V_63 != - V_64 ||
V_56 -> V_53 . V_141 == NULL || F_32 ( & V_58 -> V_85 ) ||
F_32 ( & V_56 -> V_84 . V_85 ) )
return - V_35 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
F_51 ( F_28 ( V_56 ) , L_17 , 0 ) ;
F_5 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 ) ;
F_39 ( & V_58 -> V_85 ) ;
F_37 ( & V_56 -> V_4 -> V_78 , V_62 , V_56 -> V_2 ) ;
V_62 -> V_63 = - V_171 ;
if ( V_58 -> V_62 . V_104 != NULL ) {
F_40 ( V_56 -> V_102 ) ;
V_58 -> V_62 . V_104 ( & V_56 -> V_53 , & V_58 -> V_62 ) ;
F_41 ( V_56 -> V_102 ) ;
}
F_45 ( V_56 -> V_102 , V_107 ) ;
return 0 ;
}
static int F_84 ( struct V_106 * V_53 , int V_34 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
int V_167 , V_116 = 0 ;
unsigned long V_107 ;
if ( V_53 == NULL || V_56 -> V_53 . V_141 == NULL )
return - V_35 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
#ifndef F_85
if ( V_34 && V_56 -> type == V_172 && V_56 -> V_2 == V_54 &&
! F_32 ( & V_56 -> V_84 . V_85 ) ) {
F_45 ( V_56 -> V_102 , V_107 ) ;
return - V_32 ;
}
#endif
V_167 = V_56 -> V_2 ;
do {
F_51 ( F_28 ( V_56 ) , L_18 , V_34 ) ;
V_116 |= F_16 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 , V_34 ) ;
if ( ! V_34 )
V_56 -> V_149 = 0 ;
if ( V_56 -> type == V_96 )
V_56 -> V_2 = ( V_56 -> V_2 == V_54 ) ? V_31 : V_54 ;
} while ( V_56 -> V_2 != V_167 );
F_45 ( V_56 -> V_102 , V_107 ) ;
return V_116 ;
}
static int F_86 ( struct V_106 * V_53 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
unsigned long V_107 ;
if ( V_53 == NULL || V_56 -> V_53 . V_141 == NULL )
return - V_35 ;
F_44 ( V_56 -> V_102 , V_107 ) ;
F_51 ( F_28 ( V_56 ) , L_19 , 0 ) ;
V_56 -> V_149 = 1 ;
F_45 ( V_56 -> V_102 , V_107 ) ;
return F_67 ( V_53 ) ;
}
static void F_87 ( struct V_106 * V_53 )
{
struct V_52 * V_56 = F_43 ( V_53 , struct V_52 , V_53 ) ;
unsigned long V_107 ;
if ( V_53 == NULL ) {
F_53 ( V_56 -> V_4 -> V_117 , L_20 , F_28 ( V_56 ) ) ;
return;
}
F_44 ( V_56 -> V_102 , V_107 ) ;
F_51 ( F_28 ( V_56 ) , L_21 , 0 ) ;
F_5 ( V_56 -> V_4 , V_56 -> V_1 , V_56 -> V_2 ) ;
F_45 ( V_56 -> V_102 , V_107 ) ;
}
static int F_88 ( struct V_105 * V_173 , int V_174 )
{
struct V_3 * V_4 = F_43 ( V_173 , struct V_3 , V_78 ) ;
unsigned long V_107 ;
int V_175 = 0 ;
if ( ! ( V_4 -> V_176 -> V_107 & V_177 ) )
return - V_178 ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
V_4 -> V_179 = V_174 ;
if ( V_4 -> V_114 )
V_175 = 1 ;
F_45 ( & V_4 -> V_102 , V_107 ) ;
if ( V_175 ) {
if ( V_174 ) {
F_89 ( & V_173 -> V_117 ) ;
F_90 ( V_4 , V_180 ) ;
F_3 ( V_4 , V_4 -> V_112 -> V_84 . V_8 ) ;
} else {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_176 -> V_181 )
V_4 -> V_176 -> V_181 ( V_4 ,
V_182 ) ;
F_42 ( & V_4 -> V_78 ) ;
F_91 ( & V_173 -> V_117 ) ;
}
}
return 0 ;
}
static int F_92 ( struct V_105 * V_173 )
{
struct V_3 * V_4 = F_43 ( V_173 , struct V_3 , V_78 ) ;
unsigned long V_107 ;
int V_60 = 0 ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
if ( ! V_4 -> V_110 ) {
V_60 = - V_178 ;
goto V_183;
}
if ( ! F_7 ( V_4 , V_44 , V_184 ) ) {
V_60 = - V_35 ;
goto V_183;
}
F_4 ( V_4 , V_44 , V_185 , V_185 ) ;
V_183:
F_45 ( & V_4 -> V_102 , V_107 ) ;
return V_60 ;
}
static int F_93 ( struct V_105 * V_173 , unsigned V_186 )
{
struct V_3 * V_4 = F_43 ( V_173 , struct V_3 , V_78 ) ;
if ( V_4 -> V_187 )
return F_94 ( V_4 -> V_187 , V_186 ) ;
return - V_188 ;
}
static int F_95 ( struct V_105 * V_173 , int V_189 )
{
struct V_3 * V_4 = F_43 ( V_173 , struct V_3 , V_78 ) ;
if ( V_189 )
F_4 ( V_4 , V_48 , V_190 , V_190 ) ;
else
F_4 ( V_4 , V_48 , V_190 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_3 * V_4 )
{
int V_116 = 0 , V_59 , V_191 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_7 / 2 ; V_59 ++ )
for ( V_191 = V_31 ; V_191 <= V_54 ; V_191 ++ ) {
int V_192 = V_59 + V_191 * V_4 -> V_7 / 2 ;
struct V_52 * V_56 = & V_4 -> V_52 [ V_192 ] ;
F_97 ( V_56 -> V_193 , sizeof( V_56 -> V_193 ) , L_22 , V_59 ,
( V_191 == V_54 ) ? L_23 : L_24 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_102 = & V_4 -> V_102 ;
V_56 -> V_68 = V_4 -> V_68 ;
V_56 -> V_53 . V_193 = V_56 -> V_193 ;
V_56 -> V_53 . V_194 = & V_195 ;
V_56 -> V_53 . V_66 = ( unsigned short ) ~ 0 ;
F_78 ( & V_56 -> V_84 . V_85 ) ;
V_56 -> V_84 . V_79 = F_30 ( V_4 -> V_196 , V_197 ,
& V_56 -> V_84 . V_8 ) ;
if ( V_56 -> V_84 . V_79 == NULL )
V_116 = - V_71 ;
else
memset ( V_56 -> V_84 . V_79 , 0 , sizeof( * V_56 -> V_84 . V_79 ) ) ;
if ( V_59 == 0 ) {
if ( V_191 == V_31 )
V_4 -> V_112 = V_56 ;
else
V_4 -> V_113 = V_56 ;
V_56 -> V_53 . V_66 = V_198 ;
continue;
}
F_82 ( & V_56 -> V_53 . V_199 , & V_4 -> V_78 . V_199 ) ;
}
return V_116 ;
}
static void F_98 ( struct V_3 * V_4 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_7 ; V_59 ++ ) {
struct V_52 * V_56 = & V_4 -> V_52 [ V_59 ] ;
F_36 ( V_4 -> V_196 , V_56 -> V_84 . V_79 , V_56 -> V_84 . V_8 ) ;
}
}
static int F_99 ( struct V_105 * V_78 ,
struct V_200 * V_114 )
{
struct V_3 * V_4 = F_43 ( V_78 , struct V_3 , V_78 ) ;
unsigned long V_107 ;
int V_116 = - V_71 ;
if ( V_114 -> V_115 == NULL )
return - V_35 ;
V_4 -> V_112 -> V_53 . V_141 = & V_201 ;
V_116 = F_100 ( & V_4 -> V_112 -> V_53 ) ;
if ( V_116 )
return V_116 ;
V_4 -> V_113 -> V_53 . V_141 = & V_202 ;
V_116 = F_100 ( & V_4 -> V_113 -> V_53 ) ;
if ( V_116 )
return V_116 ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
V_4 -> V_114 = V_114 ;
F_89 ( & V_4 -> V_78 . V_117 ) ;
if ( V_4 -> V_176 -> V_107 & V_177 ) {
if ( V_4 -> V_179 ) {
if ( V_4 -> V_176 -> V_107 & V_203 )
F_90 ( V_4 , V_180 ) ;
} else {
F_91 ( & V_4 -> V_78 . V_117 ) ;
goto V_90;
}
}
V_116 = F_3 ( V_4 , V_4 -> V_112 -> V_84 . V_8 ) ;
if ( V_116 )
F_91 ( & V_4 -> V_78 . V_117 ) ;
V_90:
F_45 ( & V_4 -> V_102 , V_107 ) ;
return V_116 ;
}
static int F_101 ( struct V_105 * V_78 ,
struct V_200 * V_114 )
{
struct V_3 * V_4 = F_43 ( V_78 , struct V_3 , V_78 ) ;
unsigned long V_107 ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
if ( ! ( V_4 -> V_176 -> V_107 & V_177 ) ||
V_4 -> V_179 ) {
F_3 ( V_4 , 0 ) ;
if ( V_4 -> V_176 -> V_181 )
V_4 -> V_176 -> V_181 ( V_4 ,
V_182 ) ;
V_4 -> V_114 = NULL ;
F_45 ( & V_4 -> V_102 , V_107 ) ;
F_42 ( & V_4 -> V_78 ) ;
F_44 ( & V_4 -> V_102 , V_107 ) ;
F_102 ( & V_4 -> V_78 . V_117 ) ;
}
F_45 ( & V_4 -> V_102 , V_107 ) ;
return 0 ;
}
static T_5 F_103 ( struct V_3 * V_4 )
{
T_5 V_116 ;
T_1 V_204 ;
if ( V_4 == NULL )
return V_205 ;
F_41 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_176 -> V_107 & V_203 ) {
if ( F_7 ( V_4 , V_206 , V_207 ) !=
V_180 ) {
F_40 ( & V_4 -> V_102 ) ;
return V_208 ;
}
}
V_204 = F_21 ( V_4 ) ;
F_104 ( V_204 ) ;
if ( V_204 ) {
if ( V_14 & V_204 )
F_50 ( V_4 ) ;
if ( V_13 & V_204 ) {
V_4 -> V_78 . V_108 = F_17 ( V_4 ) ?
V_209 : V_210 ;
if ( V_4 -> V_111 && V_4 -> V_114 -> V_211 ) {
F_40 ( & V_4 -> V_102 ) ;
V_4 -> V_114 -> V_211 ( & V_4 -> V_78 ) ;
F_41 ( & V_4 -> V_102 ) ;
V_4 -> V_111 = 0 ;
}
}
if ( V_11 & V_204 )
F_66 ( V_4 ) ;
if ( V_15 & V_204 ) {
if ( V_4 -> V_78 . V_108 != V_109 &&
V_4 -> V_114 -> V_212 ) {
V_4 -> V_111 = 1 ;
F_40 ( & V_4 -> V_102 ) ;
V_4 -> V_114 -> V_212 ( & V_4 -> V_78 ) ;
F_41 ( & V_4 -> V_102 ) ;
}
}
V_116 = V_205 ;
} else {
V_116 = V_208 ;
}
F_40 ( & V_4 -> V_102 ) ;
return V_116 ;
}
static void F_105 ( struct V_213 * V_117 )
{
}
static int F_106 ( struct V_3 * V_4 )
{
struct V_213 * V_117 = V_4 -> V_117 ;
int V_116 = 0 ;
F_107 ( & V_4 -> V_102 ) ;
V_4 -> V_78 . V_194 = & V_214 ;
V_4 -> V_78 . V_108 = V_109 ;
V_4 -> V_78 . V_215 = V_209 ;
V_4 -> V_78 . V_216 = 0 ;
V_4 -> V_78 . V_193 = V_4 -> V_176 -> V_193 ;
F_78 ( & V_4 -> V_78 . V_199 ) ;
F_108 ( & V_4 -> V_78 . V_117 , L_25 ) ;
V_4 -> V_78 . V_117 . V_217 = V_117 -> V_217 ;
V_4 -> V_78 . V_117 . V_218 = V_117 -> V_218 ;
V_4 -> V_78 . V_117 . V_219 = V_117 ;
V_4 -> V_78 . V_117 . V_220 = F_105 ;
V_4 -> V_196 = F_109 ( L_26 , V_117 ,
sizeof( struct V_221 ) ,
64 , V_82 ) ;
if ( V_4 -> V_196 == NULL )
return - V_71 ;
V_4 -> V_68 = F_109 ( L_27 , V_117 ,
sizeof( struct V_222 ) ,
64 , V_82 ) ;
if ( V_4 -> V_68 == NULL ) {
V_116 = - V_71 ;
goto V_223;
}
V_116 = F_96 ( V_4 ) ;
if ( V_116 )
goto V_224;
V_4 -> V_78 . V_225 = & V_4 -> V_113 -> V_53 ;
if ( V_4 -> V_226 )
V_4 -> V_187 = F_110 ( V_227 ) ;
if ( V_4 -> V_176 -> V_107 & V_228 ) {
if ( V_4 -> V_187 == NULL ) {
V_116 = - V_229 ;
goto F_98;
}
}
if ( ! ( V_4 -> V_176 -> V_107 & V_203 ) ) {
V_116 = F_90 ( V_4 , V_180 ) ;
if ( V_116 )
goto V_230;
}
V_116 = F_111 ( & V_4 -> V_78 . V_117 ) ;
if ( V_116 ) {
F_112 ( & V_4 -> V_78 . V_117 ) ;
goto V_230;
}
V_116 = F_113 ( & V_4 -> V_78 . V_117 ) ;
if ( V_116 )
goto V_231;
if ( ! F_114 ( V_4 -> V_187 ) ) {
V_116 = F_115 ( V_4 -> V_187 -> V_232 ,
& V_4 -> V_78 ) ;
if ( V_116 )
goto V_233;
}
V_116 = F_116 ( V_117 , & V_4 -> V_78 ) ;
if ( V_116 )
goto V_234;
F_117 ( & V_4 -> V_78 . V_117 ) ;
F_118 ( & V_4 -> V_78 . V_117 ) ;
return V_116 ;
V_234:
if ( ! F_114 ( V_4 -> V_187 ) ) {
F_115 ( V_4 -> V_187 -> V_232 , NULL ) ;
if ( V_4 -> V_226 )
F_119 ( V_4 -> V_187 ) ;
}
F_53 ( V_117 , L_28 , V_116 ) ;
V_233:
F_120 ( & V_4 -> V_78 . V_117 ) ;
V_231:
F_121 ( & V_4 -> V_78 . V_117 ) ;
V_230:
if ( ! F_114 ( V_4 -> V_187 ) && V_4 -> V_226 )
F_119 ( V_4 -> V_187 ) ;
F_98:
F_98 ( V_4 ) ;
V_224:
F_122 ( V_4 -> V_68 ) ;
V_223:
F_122 ( V_4 -> V_196 ) ;
return V_116 ;
}
static void F_123 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
F_124 ( & V_4 -> V_78 ) ;
F_98 ( V_4 ) ;
F_122 ( V_4 -> V_68 ) ;
F_122 ( V_4 -> V_196 ) ;
if ( ! F_114 ( V_4 -> V_187 ) ) {
F_115 ( V_4 -> V_187 -> V_232 , NULL ) ;
if ( V_4 -> V_226 )
F_119 ( V_4 -> V_187 ) ;
}
F_120 ( & V_4 -> V_78 . V_117 ) ;
F_121 ( & V_4 -> V_78 . V_117 ) ;
memset ( & V_4 -> V_78 , 0 , sizeof( V_4 -> V_78 ) ) ;
}
int F_125 ( struct V_3 * V_4 )
{
struct V_235 * V_236 ;
if ( ! F_7 ( V_4 , V_237 , V_238 ) )
return - V_239 ;
V_236 = F_126 ( V_4 -> V_117 , sizeof( struct V_235 ) , V_197 ) ;
if ( ! V_236 )
return - V_71 ;
V_236 -> V_240 = F_106 ;
V_236 -> V_241 = F_123 ;
V_236 -> V_242 = F_103 ;
V_236 -> V_193 = L_25 ;
V_4 -> V_243 [ V_244 ] = V_236 ;
return 0 ;
}
