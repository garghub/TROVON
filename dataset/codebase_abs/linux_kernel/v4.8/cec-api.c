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
F_8 ( V_36 . V_37 , V_7 -> V_8 . V_38 -> V_37 -> V_39 ,
sizeof( V_36 . V_37 ) ) ;
F_8 ( V_36 . V_39 , V_7 -> V_39 , sizeof( V_36 . V_39 ) ) ;
V_36 . V_40 = V_7 -> V_40 ;
V_36 . V_41 = V_7 -> V_41 ;
V_36 . V_42 = V_43 ;
if ( F_9 ( V_35 , & V_36 , sizeof( V_36 ) ) )
return - V_44 ;
return 0 ;
}
static long F_10 ( struct V_11 * V_7 ,
T_2 T_1 * V_35 )
{
T_3 V_45 ;
F_3 ( & V_7 -> V_16 ) ;
V_45 = V_7 -> V_45 ;
F_5 ( & V_7 -> V_16 ) ;
if ( F_9 ( V_35 , & V_45 , sizeof( V_45 ) ) )
return - V_44 ;
return 0 ;
}
static long F_11 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_46 , T_2 T_1 * V_35 )
{
T_3 V_45 ;
long V_47 ;
if ( ! ( V_7 -> V_41 & V_48 ) )
return - V_49 ;
if ( F_12 ( & V_45 , V_35 , sizeof( V_45 ) ) )
return - V_44 ;
V_47 = F_13 ( V_45 , NULL , NULL ) ;
if ( V_47 )
return V_47 ;
F_3 ( & V_7 -> V_16 ) ;
if ( F_6 ( V_7 , V_5 ) )
V_47 = - V_50 ;
else
F_14 ( V_7 , V_45 , V_46 ) ;
F_5 ( & V_7 -> V_16 ) ;
return V_47 ;
}
static long F_15 ( struct V_11 * V_7 ,
struct V_51 T_1 * V_35 )
{
struct V_51 V_52 ;
F_3 ( & V_7 -> V_16 ) ;
V_52 = V_7 -> V_52 ;
if ( ! V_7 -> V_17 )
memset ( V_52 . V_53 , V_54 ,
sizeof( V_52 . V_53 ) ) ;
F_5 ( & V_7 -> V_16 ) ;
if ( F_9 ( V_35 , & V_52 , sizeof( V_52 ) ) )
return - V_44 ;
return 0 ;
}
static long F_16 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_46 , struct V_51 T_1 * V_35 )
{
struct V_51 V_52 ;
long V_47 = - V_50 ;
if ( ! ( V_7 -> V_41 & V_55 ) )
return - V_49 ;
if ( F_12 ( & V_52 , V_35 , sizeof( V_52 ) ) )
return - V_44 ;
V_52 . V_56 &= V_57 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ! V_7 -> V_58 &&
( ! V_52 . V_59 || ! V_7 -> V_17 ) &&
! F_6 ( V_7 , V_5 ) ) {
V_47 = F_17 ( V_7 , & V_52 , V_46 ) ;
if ( ! V_47 )
V_52 = V_7 -> V_52 ;
}
F_5 ( & V_7 -> V_16 ) ;
if ( V_47 )
return V_47 ;
if ( F_9 ( V_35 , & V_52 , sizeof( V_52 ) ) )
return - V_44 ;
return 0 ;
}
static long F_18 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_46 , struct V_60 T_1 * V_35 )
{
struct V_60 V_61 = {} ;
long V_47 = 0 ;
if ( ! ( V_7 -> V_41 & V_62 ) )
return - V_49 ;
if ( F_12 ( & V_61 , V_35 , sizeof( V_61 ) ) )
return - V_44 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ! V_7 -> V_17 )
V_47 = - V_63 ;
else if ( F_6 ( V_7 , V_5 ) )
V_47 = - V_50 ;
else
V_47 = F_19 ( V_7 , & V_61 , V_5 , V_46 ) ;
F_5 ( & V_7 -> V_16 ) ;
if ( V_47 )
return V_47 ;
if ( F_9 ( V_35 , & V_61 , sizeof( V_61 ) ) )
return - V_44 ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 , struct V_60 * V_61 , bool V_46 )
{
T_4 V_64 = V_61 -> V_64 ;
int V_12 ;
do {
F_3 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_22 ) {
struct V_65 * V_66 =
F_21 ( & V_5 -> V_67 ,
struct V_65 , V_68 ) ;
F_22 ( & V_66 -> V_68 ) ;
* V_61 = V_66 -> V_61 ;
F_23 ( V_66 ) ;
V_5 -> V_22 -- ;
F_5 ( & V_5 -> V_16 ) ;
V_61 -> V_64 = V_64 ;
return 0 ;
}
F_5 ( & V_5 -> V_16 ) ;
if ( ! V_46 )
return - V_69 ;
if ( V_61 -> V_64 ) {
V_12 = F_24 ( V_5 -> V_27 ,
V_5 -> V_22 ,
F_25 ( V_61 -> V_64 ) ) ;
if ( V_12 == 0 )
V_12 = - V_70 ;
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
bool V_46 , struct V_60 T_1 * V_35 )
{
struct V_60 V_61 = {} ;
long V_47 = 0 ;
if ( F_12 ( & V_61 , V_35 , sizeof( V_61 ) ) )
return - V_44 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ! V_7 -> V_17 && V_5 -> V_71 < V_72 )
V_47 = - V_63 ;
F_5 ( & V_7 -> V_16 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_20 ( V_5 , & V_61 , V_46 ) ;
if ( V_47 )
return V_47 ;
if ( F_9 ( V_35 , & V_61 , sizeof( V_61 ) ) )
return - V_44 ;
return 0 ;
}
static long F_28 ( struct V_11 * V_7 , struct V_4 * V_5 ,
bool V_46 , struct V_73 T_1 * V_35 )
{
struct V_73 * V_74 = NULL ;
T_5 V_75 = ~ 0ULL ;
unsigned int V_76 ;
long V_47 = 0 ;
F_3 ( & V_5 -> V_16 ) ;
while ( ! V_5 -> V_25 && V_46 ) {
F_5 ( & V_5 -> V_16 ) ;
V_47 = F_26 ( V_5 -> V_27 , V_5 -> V_25 ) ;
if ( V_47 )
return V_47 ;
F_3 ( & V_5 -> V_16 ) ;
}
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
if ( V_5 -> V_25 & ( 1 << ( V_76 + 1 ) ) &&
V_5 -> V_78 [ V_76 ] . V_75 <= V_75 ) {
V_74 = & V_5 -> V_78 [ V_76 ] ;
V_75 = V_74 -> V_75 ;
}
}
if ( ! V_74 ) {
V_47 = - V_69 ;
goto V_79;
}
if ( F_9 ( V_35 , V_74 , sizeof( * V_74 ) ) ) {
V_47 = - V_44 ;
goto V_79;
}
V_5 -> V_25 &= ~ ( 1 << V_74 -> V_80 ) ;
V_79:
F_5 ( & V_5 -> V_16 ) ;
return V_47 ;
}
static long F_29 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_81 = V_5 -> V_32 | V_5 -> V_71 ;
if ( F_9 ( V_35 , & V_81 , sizeof( V_81 ) ) )
return - V_44 ;
return 0 ;
}
static long F_30 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_81 ;
T_6 V_32 ;
T_6 V_71 ;
long V_47 = 0 ;
if ( F_12 ( & V_81 , V_35 , sizeof( V_81 ) ) )
return - V_44 ;
if ( V_81 & ~ ( V_82 | V_83 ) )
return - V_84 ;
V_32 = V_81 & V_82 ;
V_71 = V_81 & V_83 ;
if ( V_32 > V_85 ||
V_71 > V_86 )
return - V_84 ;
if ( V_71 == V_86 &&
! ( V_7 -> V_41 & V_87 ) )
return - V_84 ;
if ( ( V_32 == V_33 ||
! ( V_7 -> V_41 & V_62 ) ) &&
V_71 >= V_88 &&
V_71 <= V_89 )
return - V_84 ;
if ( V_32 && V_71 >= V_72 )
return - V_84 ;
if ( V_71 >= V_72 && ! F_31 ( V_90 ) )
return - V_91 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ( V_71 == V_92 ||
V_71 == V_89 ) &&
V_7 -> V_31 && V_7 -> V_31 != V_5 )
V_47 = - V_50 ;
if ( V_32 == V_85 &&
V_7 -> V_29 && V_7 -> V_29 != V_5 )
V_47 = - V_50 ;
if ( ! V_47 ) {
bool V_93 = V_5 -> V_71 == V_86 ;
bool V_94 = V_71 == V_86 ;
if ( V_93 != V_94 ) {
if ( V_94 )
V_47 = F_32 ( V_7 ) ;
else
F_33 ( V_7 ) ;
}
}
if ( V_47 ) {
F_5 ( & V_7 -> V_16 ) ;
return V_47 ;
}
if ( V_5 -> V_71 == V_88 )
V_7 -> V_95 -- ;
if ( V_71 == V_88 )
V_7 -> V_95 ++ ;
if ( V_71 == V_92 ||
V_71 == V_89 ) {
V_7 -> V_96 =
V_71 == V_89 ;
V_7 -> V_31 = V_5 ;
} else if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_96 = false ;
V_7 -> V_31 = NULL ;
}
if ( V_32 == V_85 )
V_7 -> V_29 = V_5 ;
else if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
V_5 -> V_32 = V_32 ;
V_5 -> V_71 = V_71 ;
F_5 ( & V_7 -> V_16 ) ;
return 0 ;
}
static long F_34 ( struct V_2 * V_3 , unsigned int V_97 , unsigned long V_98 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_11 * V_7 = V_5 -> V_7 ;
bool V_46 = ! ( V_3 -> V_99 & V_100 ) ;
void T_1 * V_35 = ( void T_1 * ) V_98 ;
if ( ! V_8 -> V_13 )
return - V_101 ;
switch ( V_97 ) {
case V_102 :
return F_7 ( V_7 , V_35 ) ;
case V_103 :
return F_10 ( V_7 , V_35 ) ;
case V_104 :
return F_11 ( V_7 , V_5 , V_46 , V_35 ) ;
case V_105 :
return F_15 ( V_7 , V_35 ) ;
case V_106 :
return F_16 ( V_7 , V_5 , V_46 , V_35 ) ;
case V_107 :
return F_18 ( V_7 , V_5 , V_46 , V_35 ) ;
case V_108 :
return F_27 ( V_7 , V_5 , V_46 , V_35 ) ;
case V_109 :
return F_28 ( V_7 , V_5 , V_46 , V_35 ) ;
case V_110 :
return F_29 ( V_7 , V_5 , V_35 ) ;
case V_111 :
return F_30 ( V_7 , V_5 , V_35 ) ;
default:
return - V_49 ;
}
}
static int F_35 ( struct V_112 * V_112 , struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_36 ( V_112 -> V_113 , struct V_1 , V_114 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = F_38 ( sizeof( * V_5 ) , V_115 ) ;
struct V_73 V_116 = {
. V_80 = V_117 ,
. V_56 = V_118 ,
} ;
int V_47 ;
if ( ! V_5 )
return - V_119 ;
F_39 ( & V_5 -> V_67 ) ;
F_39 ( & V_5 -> V_120 ) ;
F_40 ( & V_5 -> V_16 ) ;
F_41 ( & V_5 -> V_27 ) ;
V_5 -> V_32 = V_121 ;
V_5 -> V_7 = V_7 ;
V_47 = F_42 ( V_8 ) ;
if ( V_47 ) {
F_23 ( V_5 ) ;
return V_47 ;
}
V_3 -> V_6 = V_5 ;
F_3 ( & V_8 -> V_16 ) ;
V_116 . V_122 . V_45 = V_7 -> V_45 ;
V_116 . V_122 . V_123 = V_7 -> V_52 . V_123 ;
F_43 ( V_5 , & V_116 , 0 ) ;
F_44 ( & V_5 -> V_68 , & V_8 -> V_124 ) ;
F_5 ( & V_8 -> V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_112 * V_112 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_31 = NULL ;
V_7 -> V_96 = false ;
}
if ( V_5 -> V_71 == V_88 )
V_7 -> V_95 -- ;
if ( V_5 -> V_71 == V_86 )
F_33 ( V_7 ) ;
F_5 ( & V_7 -> V_16 ) ;
F_3 ( & V_8 -> V_16 ) ;
F_22 ( & V_5 -> V_68 ) ;
F_5 ( & V_8 -> V_16 ) ;
F_3 ( & V_7 -> V_16 ) ;
while ( ! F_46 ( & V_5 -> V_120 ) ) {
struct V_125 * V_126 =
F_21 ( & V_5 -> V_120 , struct V_125 , V_120 ) ;
V_126 -> V_127 = false ;
V_126 -> V_5 = NULL ;
F_22 ( & V_126 -> V_120 ) ;
}
F_5 ( & V_7 -> V_16 ) ;
while ( ! F_46 ( & V_5 -> V_67 ) ) {
struct V_65 * V_66 =
F_21 ( & V_5 -> V_67 , struct V_65 , V_68 ) ;
F_22 ( & V_66 -> V_68 ) ;
F_23 ( V_66 ) ;
}
F_23 ( V_5 ) ;
F_47 ( V_8 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
