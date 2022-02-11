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
struct V_79 * V_80 = NULL ;
T_5 V_81 = ~ 0ULL ;
unsigned int V_82 ;
long V_48 = 0 ;
F_3 ( & V_5 -> V_16 ) ;
while ( ! V_5 -> V_25 && V_47 ) {
F_5 ( & V_5 -> V_16 ) ;
V_48 = F_26 ( V_5 -> V_27 , V_5 -> V_25 ) ;
if ( V_48 )
return V_48 ;
F_3 ( & V_5 -> V_16 ) ;
}
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ ) {
if ( V_5 -> V_25 & ( 1 << ( V_82 + 1 ) ) &&
V_5 -> V_84 [ V_82 ] . V_81 <= V_81 ) {
V_80 = & V_5 -> V_84 [ V_82 ] ;
V_81 = V_80 -> V_81 ;
}
}
if ( ! V_80 ) {
V_48 = - V_77 ;
goto V_85;
}
if ( F_9 ( V_35 , V_80 , sizeof( * V_80 ) ) ) {
V_48 = - V_45 ;
goto V_85;
}
V_5 -> V_25 &= ~ ( 1 << V_80 -> V_86 ) ;
V_85:
F_5 ( & V_5 -> V_16 ) ;
return V_48 ;
}
static long F_29 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_87 = V_5 -> V_32 | V_5 -> V_88 ;
if ( F_9 ( V_35 , & V_87 , sizeof( V_87 ) ) )
return - V_45 ;
return 0 ;
}
static long F_30 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_87 ;
T_6 V_32 ;
T_6 V_88 ;
long V_48 = 0 ;
if ( F_12 ( & V_87 , V_35 , sizeof( V_87 ) ) )
return - V_45 ;
if ( V_87 & ~ ( V_89 | V_90 ) )
return - V_68 ;
V_32 = V_87 & V_89 ;
V_88 = V_87 & V_90 ;
if ( V_32 > V_91 ||
V_88 > V_92 )
return - V_68 ;
if ( V_88 == V_92 &&
! ( V_7 -> V_42 & V_93 ) )
return - V_68 ;
if ( ( V_32 == V_33 ||
! ( V_7 -> V_42 & V_65 ) ) &&
V_88 >= V_94 &&
V_88 <= V_95 )
return - V_68 ;
if ( V_32 && V_88 >= V_96 )
return - V_68 ;
if ( V_88 >= V_96 && ! F_31 ( V_97 ) )
return - V_69 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ( V_88 == V_98 ||
V_88 == V_95 ) &&
V_7 -> V_31 && V_7 -> V_31 != V_5 )
V_48 = - V_51 ;
if ( V_32 == V_91 &&
V_7 -> V_29 && V_7 -> V_29 != V_5 )
V_48 = - V_51 ;
if ( ! V_48 ) {
bool V_99 = V_5 -> V_88 == V_92 ;
bool V_100 = V_88 == V_92 ;
if ( V_99 != V_100 ) {
if ( V_100 )
V_48 = F_32 ( V_7 ) ;
else
F_33 ( V_7 ) ;
}
}
if ( V_48 ) {
F_5 ( & V_7 -> V_16 ) ;
return V_48 ;
}
if ( V_5 -> V_88 == V_94 )
V_7 -> V_101 -- ;
if ( V_88 == V_94 )
V_7 -> V_101 ++ ;
if ( V_88 == V_98 ||
V_88 == V_95 ) {
V_7 -> V_102 =
V_88 == V_95 ;
V_7 -> V_31 = V_5 ;
} else if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_102 = false ;
V_7 -> V_31 = NULL ;
}
if ( V_32 == V_91 )
V_7 -> V_29 = V_5 ;
else if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
V_5 -> V_32 = V_32 ;
V_5 -> V_88 = V_88 ;
F_5 ( & V_7 -> V_16 ) ;
return 0 ;
}
static long F_34 ( struct V_2 * V_3 , unsigned int V_103 , unsigned long V_104 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_11 * V_7 = V_5 -> V_7 ;
bool V_47 = ! ( V_3 -> V_105 & V_106 ) ;
void T_1 * V_35 = ( void T_1 * ) V_104 ;
if ( ! V_8 -> V_13 )
return - V_107 ;
switch ( V_103 ) {
case V_108 :
return F_7 ( V_7 , V_35 ) ;
case V_109 :
return F_10 ( V_7 , V_35 ) ;
case V_110 :
return F_11 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_111 :
return F_15 ( V_7 , V_35 ) ;
case V_112 :
return F_16 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_113 :
return F_18 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_114 :
return F_27 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_115 :
return F_28 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_116 :
return F_29 ( V_7 , V_5 , V_35 ) ;
case V_117 :
return F_30 ( V_7 , V_5 , V_35 ) ;
default:
return - V_50 ;
}
}
static int F_35 ( struct V_118 * V_118 , struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_36 ( V_118 -> V_119 , struct V_1 , V_120 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = F_38 ( sizeof( * V_5 ) , V_121 ) ;
struct V_79 V_122 = {
. V_86 = V_123 ,
. V_57 = V_124 ,
} ;
int V_48 ;
if ( ! V_5 )
return - V_125 ;
F_39 ( & V_5 -> V_75 ) ;
F_39 ( & V_5 -> V_126 ) ;
F_40 ( & V_5 -> V_16 ) ;
F_41 ( & V_5 -> V_27 ) ;
V_5 -> V_32 = V_127 ;
V_5 -> V_7 = V_7 ;
V_48 = F_42 ( V_8 ) ;
if ( V_48 ) {
F_23 ( V_5 ) ;
return V_48 ;
}
F_3 ( & V_8 -> V_16 ) ;
if ( F_43 ( & V_8 -> V_128 ) &&
! V_7 -> V_71 &&
V_7 -> V_46 == V_129 ) {
V_48 = V_7 -> V_130 -> V_131 ( V_7 , true ) ;
if ( V_48 ) {
F_5 ( & V_8 -> V_16 ) ;
F_23 ( V_5 ) ;
return V_48 ;
}
}
V_3 -> V_6 = V_5 ;
V_122 . V_132 . V_46 = V_7 -> V_46 ;
V_122 . V_132 . V_133 = V_7 -> V_53 . V_133 ;
F_44 ( V_5 , & V_122 , 0 ) ;
F_45 ( & V_5 -> V_76 , & V_8 -> V_128 ) ;
F_5 ( & V_8 -> V_16 ) ;
return 0 ;
}
static int F_46 ( struct V_118 * V_118 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_31 = NULL ;
V_7 -> V_102 = false ;
}
if ( V_5 -> V_88 == V_94 )
V_7 -> V_101 -- ;
if ( V_5 -> V_88 == V_92 )
F_33 ( V_7 ) ;
F_5 ( & V_7 -> V_16 ) ;
F_3 ( & V_8 -> V_16 ) ;
F_22 ( & V_5 -> V_76 ) ;
if ( F_43 ( & V_8 -> V_128 ) &&
! V_7 -> V_71 &&
V_7 -> V_46 == V_129 ) {
F_47 ( V_7 -> V_130 -> V_131 ( V_7 , false ) ) ;
}
F_5 ( & V_8 -> V_16 ) ;
F_3 ( & V_7 -> V_16 ) ;
while ( ! F_43 ( & V_5 -> V_126 ) ) {
struct V_134 * V_135 =
F_21 ( & V_5 -> V_126 , struct V_134 , V_126 ) ;
V_135 -> V_136 = false ;
V_135 -> V_5 = NULL ;
F_22 ( & V_135 -> V_126 ) ;
}
F_5 ( & V_7 -> V_16 ) ;
while ( ! F_43 ( & V_5 -> V_75 ) ) {
struct V_73 * V_74 =
F_21 ( & V_5 -> V_75 , struct V_73 , V_76 ) ;
F_22 ( & V_74 -> V_76 ) ;
F_23 ( V_74 ) ;
}
F_23 ( V_5 ) ;
F_48 ( V_8 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
