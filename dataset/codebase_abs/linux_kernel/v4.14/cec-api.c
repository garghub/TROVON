static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return & V_5 -> V_7 -> V_8 ;
}
static unsigned int F_2 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_11 * V_7 = V_5 -> V_7 ;
unsigned int V_12 = 0 ;
if ( ! V_8 -> V_13 )
return V_14 | V_15 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_17 &&
V_7 -> V_18 < V_19 )
V_12 |= V_20 | V_21 ;
if ( V_5 -> V_22 )
V_12 |= V_23 | V_24 ;
if ( V_5 -> V_25 )
V_12 |= V_26 ;
F_4 ( V_3 , & V_5 -> V_27 , V_10 ) ;
F_5 ( & V_7 -> V_16 ) ;
return V_12 ;
}
static bool F_6 ( const struct V_11 * V_7 ,
const struct V_4 * V_5 )
{
bool V_28 = V_7 -> V_29 && V_7 -> V_29 == V_5 ;
bool V_30 = V_7 -> V_31 && V_7 -> V_31 == V_5 ;
if ( V_28 || V_30 )
return false ;
return V_7 -> V_29 ||
V_5 -> V_32 == V_33 ;
}
static long F_7 ( struct V_11 * V_7 ,
struct V_34 T_1 * V_35 )
{
struct V_34 V_36 = {} ;
F_8 ( V_36 . V_37 , V_7 -> V_8 . V_38 . V_39 -> V_37 -> V_40 ,
sizeof( V_36 . V_37 ) ) ;
F_8 ( V_36 . V_40 , V_7 -> V_40 , sizeof( V_36 . V_40 ) ) ;
V_36 . V_41 = V_7 -> V_41 ;
V_36 . V_42 = V_7 -> V_42 ;
V_36 . V_43 = V_44 ;
if ( F_9 ( V_35 , & V_36 , sizeof( V_36 ) ) )
return - V_45 ;
return 0 ;
}
static long F_10 ( struct V_11 * V_7 ,
T_2 T_1 * V_35 )
{
T_3 V_46 ;
F_3 ( & V_7 -> V_16 ) ;
V_46 = V_7 -> V_46 ;
F_5 ( & V_7 -> V_16 ) ;
if ( F_9 ( V_35 , & V_46 , sizeof( V_46 ) ) )
return - V_45 ;
return 0 ;
}
static long F_11 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_47 , T_2 T_1 * V_35 )
{
T_3 V_46 ;
long V_48 ;
if ( ! ( V_7 -> V_42 & V_49 ) )
return - V_50 ;
if ( F_12 ( & V_46 , V_35 , sizeof( V_46 ) ) )
return - V_45 ;
V_48 = F_13 ( V_46 , NULL , NULL ) ;
if ( V_48 )
return V_48 ;
F_3 ( & V_7 -> V_16 ) ;
if ( F_6 ( V_7 , V_5 ) )
V_48 = - V_51 ;
else
F_14 ( V_7 , V_46 , V_47 ) ;
F_5 ( & V_7 -> V_16 ) ;
return V_48 ;
}
static long F_15 ( struct V_11 * V_7 ,
struct V_52 T_1 * V_35 )
{
struct V_52 V_53 ;
F_3 ( & V_7 -> V_16 ) ;
V_53 = V_7 -> V_53 ;
if ( ! V_7 -> V_17 )
memset ( V_53 . V_54 , V_55 ,
sizeof( V_53 . V_54 ) ) ;
F_5 ( & V_7 -> V_16 ) ;
if ( F_9 ( V_35 , & V_53 , sizeof( V_53 ) ) )
return - V_45 ;
return 0 ;
}
static long F_16 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_47 , struct V_52 T_1 * V_35 )
{
struct V_52 V_53 ;
long V_48 = - V_51 ;
if ( ! ( V_7 -> V_42 & V_56 ) )
return - V_50 ;
if ( F_12 ( & V_53 , V_35 , sizeof( V_53 ) ) )
return - V_45 ;
V_53 . V_57 &= V_58 |
V_59 |
V_60 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ! V_7 -> V_61 &&
( ! V_53 . V_62 || ! V_7 -> V_17 ) &&
! F_6 ( V_7 , V_5 ) ) {
V_48 = F_17 ( V_7 , & V_53 , V_47 ) ;
if ( ! V_48 )
V_53 = V_7 -> V_53 ;
}
F_5 ( & V_7 -> V_16 ) ;
if ( V_48 )
return V_48 ;
if ( F_9 ( V_35 , & V_53 , sizeof( V_53 ) ) )
return - V_45 ;
return 0 ;
}
static long F_18 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_47 , struct V_63 T_1 * V_35 )
{
struct V_63 V_64 = {} ;
long V_48 = 0 ;
if ( ! ( V_7 -> V_42 & V_65 ) )
return - V_50 ;
if ( F_12 ( & V_64 , V_35 , sizeof( V_64 ) ) )
return - V_45 ;
if ( ( V_7 -> V_53 . V_57 & V_60 ) &&
( V_64 . V_66 == 1 || V_64 . V_64 [ 1 ] != V_67 ) )
return - V_68 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_53 . V_62 == 0 )
V_48 = - V_69 ;
else if ( V_7 -> V_61 )
V_48 = - V_70 ;
else if ( ! V_7 -> V_17 &&
( V_7 -> V_71 || V_64 . V_64 [ 0 ] != 0xf0 ) )
V_48 = - V_70 ;
else if ( F_6 ( V_7 , V_5 ) )
V_48 = - V_51 ;
else
V_48 = F_19 ( V_7 , & V_64 , V_5 , V_47 ) ;
F_5 ( & V_7 -> V_16 ) ;
if ( V_48 )
return V_48 ;
if ( F_9 ( V_35 , & V_64 , sizeof( V_64 ) ) )
return - V_45 ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 , struct V_63 * V_64 , bool V_47 )
{
T_4 V_72 = V_64 -> V_72 ;
int V_12 ;
do {
F_3 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_22 ) {
struct V_73 * V_74 =
F_21 ( & V_5 -> V_75 ,
struct V_73 , V_76 ) ;
F_22 ( & V_74 -> V_76 ) ;
* V_64 = V_74 -> V_64 ;
F_23 ( V_74 ) ;
V_5 -> V_22 -- ;
F_5 ( & V_5 -> V_16 ) ;
V_64 -> V_72 = V_72 ;
return 0 ;
}
F_5 ( & V_5 -> V_16 ) ;
if ( ! V_47 )
return - V_77 ;
if ( V_64 -> V_72 ) {
V_12 = F_24 ( V_5 -> V_27 ,
V_5 -> V_22 ,
F_25 ( V_64 -> V_72 ) ) ;
if ( V_12 == 0 )
V_12 = - V_78 ;
else if ( V_12 > 0 )
V_12 = 0 ;
} else {
V_12 = F_26 ( V_5 -> V_27 ,
V_5 -> V_22 ) ;
}
} while ( ! V_12 );
return V_12 ;
}
static long F_27 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_47 , struct V_63 T_1 * V_35 )
{
struct V_63 V_64 = {} ;
long V_48 ;
if ( F_12 ( & V_64 , V_35 , sizeof( V_64 ) ) )
return - V_45 ;
V_48 = F_20 ( V_5 , & V_64 , V_47 ) ;
if ( V_48 )
return V_48 ;
V_64 . V_57 = 0 ;
if ( F_9 ( V_35 , & V_64 , sizeof( V_64 ) ) )
return - V_45 ;
return 0 ;
}
static long F_28 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_47 , struct V_79 T_1 * V_35 )
{
struct V_80 * V_81 = NULL ;
T_5 V_82 = ~ 0ULL ;
unsigned int V_83 ;
unsigned int V_84 ;
long V_48 = 0 ;
F_3 ( & V_5 -> V_16 ) ;
while ( ! V_5 -> V_25 && V_47 ) {
F_5 ( & V_5 -> V_16 ) ;
V_48 = F_26 ( V_5 -> V_27 ,
V_5 -> V_25 ) ;
if ( V_48 )
return V_48 ;
F_3 ( & V_5 -> V_16 ) ;
}
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
struct V_80 * V_74 =
F_29 ( & V_5 -> V_86 [ V_83 ] ,
struct V_80 , V_76 ) ;
if ( V_74 && V_74 -> V_81 . V_82 <= V_82 ) {
V_81 = V_74 ;
V_84 = V_83 ;
V_82 = V_81 -> V_81 . V_82 ;
}
}
if ( ! V_81 ) {
V_48 = - V_77 ;
goto V_87;
}
F_22 ( & V_81 -> V_76 ) ;
if ( F_9 ( V_35 , & V_81 -> V_81 , sizeof( V_81 -> V_81 ) ) )
V_48 = - V_45 ;
if ( V_84 >= V_88 )
F_23 ( V_81 ) ;
V_5 -> V_89 [ V_84 ] -- ;
V_5 -> V_25 -- ;
V_87:
F_5 ( & V_5 -> V_16 ) ;
return V_48 ;
}
static long F_30 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_90 = V_5 -> V_32 | V_5 -> V_91 ;
if ( F_9 ( V_35 , & V_90 , sizeof( V_90 ) ) )
return - V_45 ;
return 0 ;
}
static long F_31 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_90 ;
T_6 V_32 ;
T_6 V_91 ;
long V_48 = 0 ;
if ( F_12 ( & V_90 , V_35 , sizeof( V_90 ) ) )
return - V_45 ;
if ( V_90 & ~ ( V_92 | V_93 ) ) {
F_32 ( 1 , L_1 , V_94 ) ;
return - V_68 ;
}
V_32 = V_90 & V_92 ;
V_91 = V_90 & V_93 ;
if ( V_32 > V_95 ||
V_91 > V_96 ) {
F_32 ( 1 , L_2 , V_94 ) ;
return - V_68 ;
}
if ( V_91 == V_96 &&
! ( V_7 -> V_42 & V_97 ) ) {
F_32 ( 1 , L_3 , V_94 ) ;
return - V_68 ;
}
if ( V_91 == V_98 &&
! ( V_7 -> V_42 & V_99 ) ) {
F_32 ( 1 , L_4 , V_94 ) ;
return - V_68 ;
}
if ( ( V_32 == V_33 ||
! ( V_7 -> V_42 & V_65 ) ) &&
V_91 >= V_100 &&
V_91 <= V_101 ) {
F_32 ( 1 , L_5 , V_94 ) ;
return - V_68 ;
}
if ( V_32 && V_91 >= V_98 ) {
F_32 ( 1 , L_6 ,
V_94 ) ;
return - V_68 ;
}
if ( V_91 >= V_98 && ! F_33 ( V_102 ) )
return - V_69 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ( V_91 == V_103 ||
V_91 == V_101 ) &&
V_7 -> V_31 && V_7 -> V_31 != V_5 )
V_48 = - V_51 ;
if ( V_32 == V_95 &&
V_7 -> V_29 && V_7 -> V_29 != V_5 )
V_48 = - V_51 ;
if ( ! V_48 ) {
bool V_104 = V_5 -> V_91 == V_96 ;
bool V_105 = V_91 == V_96 ;
if ( V_104 != V_105 ) {
if ( V_105 )
V_48 = F_34 ( V_7 ) ;
else
F_35 ( V_7 ) ;
}
}
if ( V_48 ) {
F_5 ( & V_7 -> V_16 ) ;
return V_48 ;
}
if ( V_5 -> V_91 == V_100 )
V_7 -> V_106 -- ;
if ( V_5 -> V_91 == V_98 )
V_7 -> V_107 -- ;
if ( V_91 == V_100 )
V_7 -> V_106 ++ ;
if ( V_91 == V_98 ) {
struct V_79 V_81 = {
. V_57 = V_108 ,
} ;
V_81 . V_109 = V_7 -> V_110 ? V_111 :
V_112 ;
F_36 ( V_5 , & V_81 , 0 ) ;
V_7 -> V_107 ++ ;
}
if ( V_91 == V_103 ||
V_91 == V_101 ) {
V_7 -> V_113 =
V_91 == V_101 ;
V_7 -> V_31 = V_5 ;
} else if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_113 = false ;
V_7 -> V_31 = NULL ;
}
if ( V_32 == V_95 )
V_7 -> V_29 = V_5 ;
else if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
V_5 -> V_32 = V_32 ;
V_5 -> V_91 = V_91 ;
F_5 ( & V_7 -> V_16 ) ;
return 0 ;
}
static long F_37 ( struct V_2 * V_3 , unsigned int V_114 , unsigned long V_115 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_11 * V_7 = V_5 -> V_7 ;
bool V_47 = ! ( V_3 -> V_116 & V_117 ) ;
void T_1 * V_35 = ( void T_1 * ) V_115 ;
if ( ! V_8 -> V_13 )
return - V_118 ;
switch ( V_114 ) {
case V_119 :
return F_7 ( V_7 , V_35 ) ;
case V_120 :
return F_10 ( V_7 , V_35 ) ;
case V_121 :
return F_11 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_122 :
return F_15 ( V_7 , V_35 ) ;
case V_123 :
return F_16 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_124 :
return F_18 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_125 :
return F_27 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_126 :
return F_28 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_127 :
return F_30 ( V_7 , V_5 , V_35 ) ;
case V_128 :
return F_31 ( V_7 , V_5 , V_35 ) ;
default:
return - V_50 ;
}
}
static int F_38 ( struct V_129 * V_129 , struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_39 ( V_129 -> V_130 , struct V_1 , V_131 ) ;
struct V_11 * V_7 = F_40 ( V_8 ) ;
struct V_4 * V_5 = F_41 ( sizeof( * V_5 ) , V_132 ) ;
struct V_79 V_133 = {
. V_109 = V_134 ,
. V_57 = V_108 ,
} ;
unsigned int V_83 ;
int V_48 ;
if ( ! V_5 )
return - V_135 ;
F_42 ( & V_5 -> V_75 ) ;
F_42 ( & V_5 -> V_136 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ )
F_42 ( & V_5 -> V_86 [ V_83 ] ) ;
F_43 ( & V_5 -> V_16 ) ;
F_44 ( & V_5 -> V_27 ) ;
V_5 -> V_32 = V_137 ;
V_5 -> V_7 = V_7 ;
V_48 = F_45 ( V_8 ) ;
if ( V_48 ) {
F_23 ( V_5 ) ;
return V_48 ;
}
F_3 ( & V_8 -> V_16 ) ;
if ( F_46 ( & V_8 -> V_138 ) &&
! V_7 -> V_71 &&
V_7 -> V_46 == V_139 ) {
V_48 = V_7 -> V_140 -> V_141 ( V_7 , true ) ;
if ( V_48 ) {
F_5 ( & V_8 -> V_16 ) ;
F_23 ( V_5 ) ;
return V_48 ;
}
}
V_3 -> V_6 = V_5 ;
V_133 . V_142 . V_46 = V_7 -> V_46 ;
V_133 . V_142 . V_143 = V_7 -> V_53 . V_143 ;
F_36 ( V_5 , & V_133 , 0 ) ;
F_47 ( & V_5 -> V_76 , & V_8 -> V_138 ) ;
F_5 ( & V_8 -> V_16 ) ;
return 0 ;
}
static int F_48 ( struct V_129 * V_129 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_11 * V_7 = F_40 ( V_8 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned int V_83 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_31 = NULL ;
V_7 -> V_113 = false ;
}
if ( V_5 -> V_91 == V_100 )
V_7 -> V_106 -- ;
if ( V_5 -> V_91 == V_98 )
V_7 -> V_107 -- ;
if ( V_5 -> V_91 == V_96 )
F_35 ( V_7 ) ;
F_5 ( & V_7 -> V_16 ) ;
F_3 ( & V_8 -> V_16 ) ;
F_22 ( & V_5 -> V_76 ) ;
if ( F_46 ( & V_8 -> V_138 ) &&
! V_7 -> V_71 &&
V_7 -> V_46 == V_139 ) {
F_49 ( V_7 -> V_140 -> V_141 ( V_7 , false ) ) ;
}
F_5 ( & V_8 -> V_16 ) ;
F_3 ( & V_7 -> V_16 ) ;
while ( ! F_46 ( & V_5 -> V_136 ) ) {
struct V_144 * V_145 =
F_21 ( & V_5 -> V_136 , struct V_144 , V_136 ) ;
V_145 -> V_146 = false ;
V_145 -> V_5 = NULL ;
F_22 ( & V_145 -> V_136 ) ;
}
F_5 ( & V_7 -> V_16 ) ;
while ( ! F_46 ( & V_5 -> V_75 ) ) {
struct V_73 * V_74 =
F_21 ( & V_5 -> V_75 , struct V_73 , V_76 ) ;
F_22 ( & V_74 -> V_76 ) ;
F_23 ( V_74 ) ;
}
for ( V_83 = V_88 ; V_83 < V_85 ; V_83 ++ ) {
while ( ! F_46 ( & V_5 -> V_86 [ V_83 ] ) ) {
struct V_80 * V_74 =
F_21 ( & V_5 -> V_86 [ V_83 ] ,
struct V_80 , V_76 ) ;
F_22 ( & V_74 -> V_76 ) ;
F_23 ( V_74 ) ;
}
}
F_23 ( V_5 ) ;
F_50 ( V_8 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
