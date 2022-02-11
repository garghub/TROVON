static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
else
F_3 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_7 ;
if ( V_2 -> V_5 )
V_7 = F_5 ( V_2 -> V_5 , V_3 ) ;
else
V_7 = F_6 ( V_2 -> V_6 , V_3 ) ;
return V_7 ;
}
static void F_7 ( struct V_8 * V_9 , T_2 V_10 ,
T_1 V_11 , T_1 V_12 , T_1 V_13 )
{
union V_14 * V_15 ;
union V_14 V_16 [ 3 ] , V_17 ;
V_16 [ 0 ] . integer . type = V_18 ;
V_16 [ 0 ] . integer . V_19 = V_11 ;
V_16 [ 1 ] . integer . type = V_18 ;
V_16 [ 1 ] . integer . V_19 = V_12 ;
V_16 [ 2 ] . integer . type = V_18 ;
V_16 [ 2 ] . integer . V_19 = V_13 ;
V_17 . type = V_20 ;
V_17 . V_21 . V_22 = 3 ;
V_17 . V_21 . V_23 = V_16 ;
V_15 = F_8 ( F_9 ( V_9 -> V_24 ) ,
& V_25 , 0 , V_10 , & V_17 ) ;
if ( ! V_15 ) {
F_10 ( V_9 -> V_24 , L_1 ,
V_11 , V_12 , V_13 ) ;
return;
}
F_11 ( V_15 ) ;
}
static void F_12 ( struct V_8 * V_9 , int V_26 ,
T_3 V_27 , int V_28 )
{
int V_29 = 0 ;
T_2 V_19 ;
if ( ! V_9 ) {
F_13 ( L_2 ) ;
return;
}
if ( ! V_9 -> V_30 ) {
F_14 ( V_9 -> V_24 , L_3 ,
V_9 -> V_31 ) ;
return;
}
if ( V_27 == V_32 )
V_29 = 1 ;
V_19 = V_9 -> V_33 ;
if ( V_26 ) {
F_15 ( V_19 , V_34 , V_26 ) ;
F_16 ( V_19 , V_35 ,
V_36 , V_29 ) ;
F_15 ( V_19 , V_37 , V_28 ) ;
if ( V_19 != V_9 -> V_33 ) {
F_2 ( V_9 -> V_30 ,
V_9 -> V_38 , V_19 ) ;
V_9 -> V_33 = V_19 ;
}
} else {
V_19 = ( V_9 -> V_33 ) & ( 0x1 << V_39 ) ;
F_2 ( V_9 -> V_30 ,
V_9 -> V_38 , V_19 ) ;
V_9 -> V_33 = V_19 ;
}
}
static void F_17 ( struct V_8 * V_9 , int V_26 ,
T_3 V_27 , int V_28 )
{
if ( ! V_9 ) {
F_13 ( L_4 ) ;
return;
}
F_7 ( V_9 , V_40 ,
V_26 , V_9 -> V_31 , V_28 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_30 )
return;
F_2 ( V_9 -> V_30 , V_9 -> V_38 ,
V_41 ) ;
V_9 -> V_33 = V_41 ;
}
static void F_19 ( struct V_8 * V_9 )
{
if ( ! V_9 ) {
F_13 ( L_5 ) ;
return;
}
if ( V_9 -> V_42 != V_43 )
return;
F_7 ( V_9 , V_40 ,
0 , V_9 -> V_31 , 0 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
enum V_44 V_45 )
{
switch ( V_45 ) {
case V_46 :
V_9 -> V_33 =
F_5 ( V_9 -> V_30 ,
V_9 -> V_38 ) ;
F_15 ( V_9 -> V_33 , V_39 ,
V_47 ) ;
F_2 ( V_9 -> V_30 , V_9 -> V_38 ,
V_9 -> V_33 ) ;
break;
case V_48 :
F_15 ( V_9 -> V_33 , V_39 ,
V_41 ) ;
F_2 ( V_9 -> V_30 , V_9 -> V_38 ,
V_9 -> V_33 ) ;
break;
default:
F_14 ( V_9 -> V_24 , L_6 , V_45 ) ;
return - V_49 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_10 ,
T_1 V_50 , T_1 V_12 , T_1 V_4 )
{
union V_14 * V_15 ;
union V_14 V_16 [ 3 ] , V_17 ;
V_16 [ 0 ] . integer . type = V_18 ;
V_16 [ 0 ] . integer . V_19 = V_50 ;
V_16 [ 1 ] . integer . type = V_18 ;
V_16 [ 1 ] . integer . V_19 = V_12 ;
V_16 [ 2 ] . integer . type = V_18 ;
V_16 [ 2 ] . integer . V_19 = V_4 ;
V_17 . type = V_20 ;
V_17 . V_21 . V_22 = 3 ;
V_17 . V_21 . V_23 = V_16 ;
V_15 = F_8 ( F_9 ( V_2 -> V_24 ) ,
& V_25 , 0 , V_10 , & V_17 ) ;
if ( ! V_15 ) {
F_10 ( V_2 -> V_24 , L_7 ,
V_50 , V_12 ) ;
return;
}
F_11 ( V_15 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_51 )
{
T_1 V_52 ;
T_1 V_53 ;
if ( ! V_51 ) {
V_52 = V_54 ;
V_53 = V_55 ;
} else {
V_52 = V_56 ;
V_53 = V_57 ;
}
F_1 ( V_2 , V_52 , V_58 ) ;
F_1 ( V_2 , V_53 , V_58 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_60 ,
0 , V_51 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_12 ,
bool V_51 )
{
T_1 V_61 = 0 ;
T_1 V_62 ;
if ( V_12 >= V_63 )
return;
V_61 |= V_58 ;
V_61 |= 0x2082082 << V_2 -> V_9 [ V_12 ] -> V_64 ;
if ( ! V_51 )
V_62 = V_65 ;
else
V_62 = V_66 ;
F_1 ( V_2 , V_62 , V_61 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
T_1 V_12 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_67 , V_12 , V_51 ) ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_68 , bool V_51 )
{
T_1 V_62 ;
if ( ! V_51 )
V_62 = V_69 ;
else
V_62 = V_70 ;
F_1 ( V_2 , V_62 , V_68 ) ;
}
void
F_27 ( struct V_1 * V_2 , T_1 V_68 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_71 ,
V_68 , V_51 ) ;
}
void F_28 ( struct V_1 * V_2 , bool V_51 )
{
if ( ! V_51 ) {
F_1 ( V_2 , V_72 , 1 ) ;
} else {
F_1 ( V_2 ,
V_73 , 1 ) ;
F_1 ( V_2 ,
V_74 , 1 ) ;
F_29 ( 20 ) ;
F_1 ( V_2 , V_75 , 1 ) ;
}
}
void F_30 ( struct V_1 * V_2 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_76 , 0 , V_51 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_12 ,
bool V_51 )
{
T_1 V_77 ;
T_1 V_78 ;
T_1 V_64 ;
if ( V_12 >= V_79 )
return;
if ( ! F_32 ( V_2 ) ) {
V_77 = 0x1 << V_12 ;
V_64 = V_2 -> V_9 [ V_12 ] -> V_64 ;
V_78 = F_33 ( V_2 -> V_80 ) ?
0x1041041 : 0x2082082 ;
V_78 <<= V_64 ;
if ( ! V_51 ) {
F_1 ( V_2 , V_81 ,
V_77 ) ;
F_1 ( V_2 , V_82 ,
V_78 ) ;
} else {
F_1 ( V_2 , V_83 ,
V_78 ) ;
F_1 ( V_2 , V_84 ,
V_77 ) ;
}
} else {
V_77 = 0x15540 ;
V_78 = F_33 ( V_2 -> V_80 ) ? 0x100 : 0x40 ;
V_77 <<= V_2 -> V_85 ;
V_78 <<= V_2 -> V_85 ;
if ( ! V_51 ) {
F_1 ( V_2 , V_81 ,
V_77 ) ;
F_1 ( V_2 , V_86 ,
V_78 ) ;
} else {
F_1 ( V_2 , V_84 ,
V_77 ) ;
F_1 ( V_2 , V_87 ,
V_78 ) ;
}
}
}
static void F_34 ( struct V_1 * V_2 ,
T_1 V_12 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_88 , V_12 , V_51 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_12 ,
bool V_51 )
{
T_1 V_61 = 0 ;
T_1 V_62 ;
V_61 |= V_58 << V_2 -> V_9 [ V_12 ] -> V_64 ;
if ( ! V_51 )
V_62 = V_86 ;
else
V_62 = V_87 ;
F_1 ( V_2 , V_62 , V_61 ) ;
}
static void
F_36 ( struct V_1 * V_2 , T_1 V_12 , bool V_51 )
{
F_21 ( V_2 , V_59 ,
V_89 , V_12 , V_51 ) ;
}
static void F_37 ( struct V_1 * V_2 , bool V_51 )
{
T_1 V_61 ;
T_1 V_62 ;
if ( ! ( F_38 ( V_2 -> V_24 ) ) )
return;
if ( ! F_32 ( V_2 ) ) {
V_61 = V_58 ;
if ( ! V_51 )
V_62 = V_90 ;
else
V_62 = V_91 ;
} else {
V_61 = 0x100 << V_2 -> V_85 ;
if ( ! V_51 )
V_62 = V_86 ;
else
V_62 = V_87 ;
}
F_1 ( V_2 , V_62 , V_61 ) ;
}
static T_4 F_39 ( struct V_8 * V_9 )
{
T_1 V_92 ;
T_1 V_3 ;
bool V_93 = F_33 ( V_9 -> V_2 -> V_80 ) ;
int V_31 = V_9 -> V_31 ;
T_4 V_94 ;
if ( V_93 ) {
if ( F_32 ( V_9 -> V_2 ) )
return V_95 ;
if ( V_31 >= 0 && V_31 <= 3 )
V_3 = V_96 ;
else
V_3 = V_97 ;
} else{
if ( ! F_32 ( V_9 -> V_2 ) && V_31 <= 3 )
V_3 = V_98 ;
else
V_3 = V_99 ;
}
V_92 = F_4 ( V_9 -> V_2 , V_3 ) ;
if ( F_40 ( V_92 , V_9 -> V_100 ) )
V_94 = V_101 ;
else
V_94 = V_95 ;
return V_94 ;
}
static T_4 F_41 ( struct V_8 * V_9 )
{
T_4 V_94 = V_102 ;
union V_14 * V_15 ;
union V_14 V_16 , V_17 ;
V_16 . integer . type = V_18 ;
V_16 . integer . V_19 = V_9 -> V_31 ;
V_17 . type = V_20 ,
V_17 . V_21 . V_22 = 1 ,
V_17 . V_21 . V_23 = & V_16 ,
V_15 = F_8 ( F_9 ( V_9 -> V_24 ) ,
& V_25 , 0 ,
V_103 , & V_17 ) ;
if ( ! V_15 || V_15 -> type != V_18 )
return V_94 ;
V_94 = V_15 -> integer . V_19 ?
V_101 : V_95 ;
F_42 ( V_9 -> V_24 , L_8 , V_9 -> V_31 , V_94 ) ;
F_11 ( V_15 ) ;
return V_94 ;
}
int F_43 ( struct V_8 * V_9 , int * V_104 )
{
if ( ! V_9 -> V_30 )
return - V_105 ;
* V_104 = ! F_5 ( V_9 -> V_30 , V_9 -> V_38
+ V_106 ) ;
return 0 ;
}
int F_44 ( struct V_8 * V_9 , int * V_104 )
{
union V_14 * V_15 ;
union V_14 V_16 , V_17 ;
V_16 . integer . type = V_18 ;
V_16 . integer . V_19 = V_9 -> V_31 ;
V_17 . type = V_20 ,
V_17 . V_21 . V_22 = 1 ,
V_17 . V_21 . V_23 = & V_16 ,
V_15 = F_8 ( F_9 ( V_9 -> V_24 ) ,
& V_25 , 0 ,
V_107 , & V_17 ) ;
if ( ! V_15 || V_15 -> type != V_18 )
return - V_105 ;
* V_104 = V_15 -> integer . V_19 ;
F_11 ( V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , bool V_108 )
{
const T_2 V_109 [] = {
0 ,
1 ,
2 ,
3 ,
2 ,
3 ,
0 ,
1
} ;
#define F_46 ( T_5 , V_3 ) ((0x4080 + (reg) * 0x0002 + (lane) * 0x0200) * 2)
T_6 V_110 = F_46 ( V_109 [ V_9 -> V_31 ] , 0 ) ;
int V_104 ;
int V_7 = F_43 ( V_9 , & V_104 ) ;
if ( ! V_9 -> V_111 ) {
if ( V_7 )
F_47 ( L_9 ) ;
else
if ( ! V_104 )
F_47 ( L_10 ) ;
}
if ( V_9 -> V_112 ) {
T_1 V_113 ;
if ( ! F_33 ( V_9 -> V_2 -> V_80 ) ) {
#define F_48 0x40008
if ( ( ! F_32 ( V_9 -> V_2 ) ) &&
( V_9 -> V_31 <= 3 ) )
F_2 ( V_9 -> V_112 ,
F_48 , 0 ) ;
else
F_2 ( V_9 -> V_112 ,
F_48 , 3 ) ;
}
V_113 = F_5 ( V_9 -> V_112 , V_110 ) ;
F_16 ( V_113 , 1ull << 10 , 10 , V_108 ) ;
F_2 ( V_9 -> V_112 , V_110 , V_113 ) ;
} else {
T_2 * V_114 = ( T_2 * ) V_9 -> V_115 +
( V_9 -> V_31 <= 3 ? 0x00280000 : 0x00200000 ) ;
F_49 ( V_114 , V_110 , 1ull << 10 , 10 , V_108 ) ;
}
return 0 ;
}
static int
F_50 ( struct V_8 * V_9 , bool V_108 )
{
union V_14 * V_15 ;
union V_14 V_16 [ 3 ] , V_17 ;
V_16 [ 0 ] . integer . type = V_18 ;
V_16 [ 0 ] . integer . V_19 = V_9 -> V_31 ;
V_16 [ 1 ] . integer . type = V_18 ;
V_16 [ 1 ] . integer . V_19 = ! ! V_108 ;
V_17 . type = V_20 ;
V_17 . V_21 . V_22 = 2 ;
V_17 . V_21 . V_23 = V_16 ;
V_15 = F_8 ( F_9 ( V_9 -> V_2 -> V_24 ) ,
& V_25 , 0 ,
V_116 , & V_17 ) ;
if ( ! V_15 ) {
F_10 ( V_9 -> V_2 -> V_24 , L_11 ,
V_9 -> V_31 ) ;
return - V_117 ;
}
F_11 ( V_15 ) ;
return 0 ;
}
struct V_118 * F_51 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
V_119 = F_52 ( V_2 -> V_24 , sizeof( * V_119 ) , V_120 ) ;
if ( ! V_119 )
return NULL ;
if ( F_38 ( V_2 -> V_24 ) ) {
V_119 -> V_121 = F_12 ;
V_119 -> V_122 = F_18 ;
V_119 -> F_20 = F_20 ;
V_119 -> V_123 = F_22 ;
V_119 -> V_124 = F_24 ;
V_119 -> V_125 = F_31 ;
V_119 -> V_126 = F_35 ;
V_119 -> V_127 = F_37 ;
V_119 -> F_26 = F_26 ;
V_119 -> F_28 = F_28 ;
V_119 -> V_128 = F_39 ;
V_119 -> V_129 = F_43 ;
V_119 -> V_130 = F_45 ;
} else if ( F_53 ( V_2 -> V_24 -> V_131 ) ) {
V_119 -> V_121 = F_17 ;
V_119 -> V_122 = F_19 ;
V_119 -> F_20 = F_20 ;
V_119 -> V_123 = F_23 ;
V_119 -> V_124 = F_25 ;
V_119 -> V_125 = F_34 ;
V_119 -> V_126 = F_36 ;
V_119 -> V_127 = F_37 ;
V_119 -> F_26 = F_27 ;
V_119 -> F_28 = F_30 ;
V_119 -> V_128 = F_41 ;
V_119 -> V_129 = F_44 ;
V_119 -> V_130 = F_50 ;
} else {
F_54 ( V_2 -> V_24 , ( void * ) V_119 ) ;
V_119 = NULL ;
}
return ( void * ) V_119 ;
}
static int F_55 ( struct V_132 * V_24 , void * V_131 )
{
return V_24 -> V_131 == V_131 ;
}
struct
V_133 * F_56 ( struct V_134 * V_131 )
{
struct V_132 * V_24 ;
V_24 = F_57 ( & V_135 , NULL ,
V_131 , F_55 ) ;
return V_24 ? F_58 ( V_24 ) : NULL ;
}
