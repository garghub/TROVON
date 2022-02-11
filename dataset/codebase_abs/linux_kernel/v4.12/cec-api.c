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
else if ( ! V_7 -> V_17 && V_64 . V_64 [ 0 ] != 0xf0 )
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
T_4 V_71 = V_64 -> V_71 ;
int V_12 ;
do {
F_3 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_22 ) {
struct V_72 * V_73 =
F_21 ( & V_5 -> V_74 ,
struct V_72 , V_75 ) ;
F_22 ( & V_73 -> V_75 ) ;
* V_64 = V_73 -> V_64 ;
F_23 ( V_73 ) ;
V_5 -> V_22 -- ;
F_5 ( & V_5 -> V_16 ) ;
V_64 -> V_71 = V_71 ;
return 0 ;
}
F_5 ( & V_5 -> V_16 ) ;
if ( ! V_47 )
return - V_76 ;
if ( V_64 -> V_71 ) {
V_12 = F_24 ( V_5 -> V_27 ,
V_5 -> V_22 ,
F_25 ( V_64 -> V_71 ) ) ;
if ( V_12 == 0 )
V_12 = - V_77 ;
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
bool V_47 , struct V_78 T_1 * V_35 )
{
struct V_78 * V_79 = NULL ;
T_5 V_80 = ~ 0ULL ;
unsigned int V_81 ;
long V_48 = 0 ;
F_3 ( & V_5 -> V_16 ) ;
while ( ! V_5 -> V_25 && V_47 ) {
F_5 ( & V_5 -> V_16 ) ;
V_48 = F_26 ( V_5 -> V_27 , V_5 -> V_25 ) ;
if ( V_48 )
return V_48 ;
F_3 ( & V_5 -> V_16 ) ;
}
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
if ( V_5 -> V_25 & ( 1 << ( V_81 + 1 ) ) &&
V_5 -> V_83 [ V_81 ] . V_80 <= V_80 ) {
V_79 = & V_5 -> V_83 [ V_81 ] ;
V_80 = V_79 -> V_80 ;
}
}
if ( ! V_79 ) {
V_48 = - V_76 ;
goto V_84;
}
if ( F_9 ( V_35 , V_79 , sizeof( * V_79 ) ) ) {
V_48 = - V_45 ;
goto V_84;
}
V_5 -> V_25 &= ~ ( 1 << V_79 -> V_85 ) ;
V_84:
F_5 ( & V_5 -> V_16 ) ;
return V_48 ;
}
static long F_29 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_86 = V_5 -> V_32 | V_5 -> V_87 ;
if ( F_9 ( V_35 , & V_86 , sizeof( V_86 ) ) )
return - V_45 ;
return 0 ;
}
static long F_30 ( struct V_11 * V_7 , struct V_4 * V_5 ,
T_4 T_1 * V_35 )
{
T_4 V_86 ;
T_6 V_32 ;
T_6 V_87 ;
long V_48 = 0 ;
if ( F_12 ( & V_86 , V_35 , sizeof( V_86 ) ) )
return - V_45 ;
if ( V_86 & ~ ( V_88 | V_89 ) )
return - V_68 ;
V_32 = V_86 & V_88 ;
V_87 = V_86 & V_89 ;
if ( V_32 > V_90 ||
V_87 > V_91 )
return - V_68 ;
if ( V_87 == V_91 &&
! ( V_7 -> V_42 & V_92 ) )
return - V_68 ;
if ( ( V_32 == V_33 ||
! ( V_7 -> V_42 & V_65 ) ) &&
V_87 >= V_93 &&
V_87 <= V_94 )
return - V_68 ;
if ( V_32 && V_87 >= V_95 )
return - V_68 ;
if ( V_87 >= V_95 && ! F_31 ( V_96 ) )
return - V_69 ;
F_3 ( & V_7 -> V_16 ) ;
if ( ( V_87 == V_97 ||
V_87 == V_94 ) &&
V_7 -> V_31 && V_7 -> V_31 != V_5 )
V_48 = - V_51 ;
if ( V_32 == V_90 &&
V_7 -> V_29 && V_7 -> V_29 != V_5 )
V_48 = - V_51 ;
if ( ! V_48 ) {
bool V_98 = V_5 -> V_87 == V_91 ;
bool V_99 = V_87 == V_91 ;
if ( V_98 != V_99 ) {
if ( V_99 )
V_48 = F_32 ( V_7 ) ;
else
F_33 ( V_7 ) ;
}
}
if ( V_48 ) {
F_5 ( & V_7 -> V_16 ) ;
return V_48 ;
}
if ( V_5 -> V_87 == V_93 )
V_7 -> V_100 -- ;
if ( V_87 == V_93 )
V_7 -> V_100 ++ ;
if ( V_87 == V_97 ||
V_87 == V_94 ) {
V_7 -> V_101 =
V_87 == V_94 ;
V_7 -> V_31 = V_5 ;
} else if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_101 = false ;
V_7 -> V_31 = NULL ;
}
if ( V_32 == V_90 )
V_7 -> V_29 = V_5 ;
else if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
V_5 -> V_32 = V_32 ;
V_5 -> V_87 = V_87 ;
F_5 ( & V_7 -> V_16 ) ;
return 0 ;
}
static long F_34 ( struct V_2 * V_3 , unsigned int V_102 , unsigned long V_103 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_11 * V_7 = V_5 -> V_7 ;
bool V_47 = ! ( V_3 -> V_104 & V_105 ) ;
void T_1 * V_35 = ( void T_1 * ) V_103 ;
if ( ! V_8 -> V_13 )
return - V_106 ;
switch ( V_102 ) {
case V_107 :
return F_7 ( V_7 , V_35 ) ;
case V_108 :
return F_10 ( V_7 , V_35 ) ;
case V_109 :
return F_11 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_110 :
return F_15 ( V_7 , V_35 ) ;
case V_111 :
return F_16 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_112 :
return F_18 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_113 :
return F_27 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_114 :
return F_28 ( V_7 , V_5 , V_47 , V_35 ) ;
case V_115 :
return F_29 ( V_7 , V_5 , V_35 ) ;
case V_116 :
return F_30 ( V_7 , V_5 , V_35 ) ;
default:
return - V_50 ;
}
}
static int F_35 ( struct V_117 * V_117 , struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_36 ( V_117 -> V_118 , struct V_1 , V_119 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = F_38 ( sizeof( * V_5 ) , V_120 ) ;
struct V_78 V_121 = {
. V_85 = V_122 ,
. V_57 = V_123 ,
} ;
int V_48 ;
if ( ! V_5 )
return - V_124 ;
F_39 ( & V_5 -> V_74 ) ;
F_39 ( & V_5 -> V_125 ) ;
F_40 ( & V_5 -> V_16 ) ;
F_41 ( & V_5 -> V_27 ) ;
V_5 -> V_32 = V_126 ;
V_5 -> V_7 = V_7 ;
V_48 = F_42 ( V_8 ) ;
if ( V_48 ) {
F_23 ( V_5 ) ;
return V_48 ;
}
F_3 ( & V_8 -> V_16 ) ;
if ( F_43 ( & V_8 -> V_127 ) &&
V_7 -> V_46 == V_128 ) {
V_48 = V_7 -> V_129 -> V_130 ( V_7 , true ) ;
if ( V_48 ) {
F_5 ( & V_8 -> V_16 ) ;
F_23 ( V_5 ) ;
return V_48 ;
}
}
V_3 -> V_6 = V_5 ;
V_121 . V_131 . V_46 = V_7 -> V_46 ;
V_121 . V_131 . V_132 = V_7 -> V_53 . V_132 ;
F_44 ( V_5 , & V_121 , 0 ) ;
F_45 ( & V_5 -> V_75 , & V_8 -> V_127 ) ;
F_5 ( & V_8 -> V_16 ) ;
return 0 ;
}
static int F_46 ( struct V_117 * V_117 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_11 * V_7 = F_37 ( V_8 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_29 == V_5 )
V_7 -> V_29 = NULL ;
if ( V_7 -> V_31 == V_5 ) {
V_7 -> V_31 = NULL ;
V_7 -> V_101 = false ;
}
if ( V_5 -> V_87 == V_93 )
V_7 -> V_100 -- ;
if ( V_5 -> V_87 == V_91 )
F_33 ( V_7 ) ;
F_5 ( & V_7 -> V_16 ) ;
F_3 ( & V_8 -> V_16 ) ;
F_22 ( & V_5 -> V_75 ) ;
if ( F_43 ( & V_8 -> V_127 ) &&
V_7 -> V_46 == V_128 ) {
F_47 ( V_7 -> V_129 -> V_130 ( V_7 , false ) ) ;
}
F_5 ( & V_8 -> V_16 ) ;
F_3 ( & V_7 -> V_16 ) ;
while ( ! F_43 ( & V_5 -> V_125 ) ) {
struct V_133 * V_134 =
F_21 ( & V_5 -> V_125 , struct V_133 , V_125 ) ;
V_134 -> V_135 = false ;
V_134 -> V_5 = NULL ;
F_22 ( & V_134 -> V_125 ) ;
}
F_5 ( & V_7 -> V_16 ) ;
while ( ! F_43 ( & V_5 -> V_74 ) ) {
struct V_72 * V_73 =
F_21 ( & V_5 -> V_74 , struct V_72 , V_75 ) ;
F_22 ( & V_73 -> V_75 ) ;
F_23 ( V_73 ) ;
}
F_23 ( V_5 ) ;
F_48 ( V_8 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
