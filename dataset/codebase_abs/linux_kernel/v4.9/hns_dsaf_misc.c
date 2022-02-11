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
static void F_7 ( struct V_8 * V_9 , int V_10 ,
T_2 V_11 , int V_12 )
{
int V_13 = 0 ;
T_3 V_14 ;
if ( ! V_9 ) {
F_8 ( L_1 ) ;
return;
}
if ( ! V_9 -> V_15 ) {
F_9 ( V_9 -> V_16 , L_2 ,
V_9 -> V_17 ) ;
return;
}
if ( V_11 == V_18 )
V_13 = 1 ;
V_14 = V_9 -> V_19 ;
if ( V_10 ) {
F_10 ( V_14 , V_20 , V_10 ) ;
F_11 ( V_14 , V_21 ,
V_22 , V_13 ) ;
F_10 ( V_14 , V_23 , V_12 ) ;
if ( V_14 != V_9 -> V_19 ) {
F_2 ( V_9 -> V_15 ,
V_9 -> V_24 , V_14 ) ;
V_9 -> V_19 = V_14 ;
}
} else {
V_14 = ( V_9 -> V_19 ) & ( 0x1 << V_25 ) ;
F_2 ( V_9 -> V_15 ,
V_9 -> V_24 , V_14 ) ;
V_9 -> V_19 = V_14 ;
}
}
static void F_12 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_15 )
return;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_26 ) ;
V_9 -> V_19 = V_26 ;
}
static int F_13 ( struct V_8 * V_9 ,
enum V_27 V_28 )
{
switch ( V_28 ) {
case V_29 :
V_9 -> V_19 =
F_5 ( V_9 -> V_15 ,
V_9 -> V_24 ) ;
F_10 ( V_9 -> V_19 , V_25 ,
V_30 ) ;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_9 -> V_19 ) ;
break;
case V_31 :
F_10 ( V_9 -> V_19 , V_25 ,
V_26 ) ;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_9 -> V_19 ) ;
break;
default:
F_9 ( V_9 -> V_16 , L_3 , V_28 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , T_3 V_33 ,
T_1 V_34 , T_1 V_35 , T_1 V_4 )
{
union V_36 * V_37 ;
union V_36 V_38 [ 3 ] , V_39 ;
V_38 [ 0 ] . integer . type = V_40 ;
V_38 [ 0 ] . integer . V_14 = V_34 ;
V_38 [ 1 ] . integer . type = V_40 ;
V_38 [ 1 ] . integer . V_14 = V_35 ;
V_38 [ 2 ] . integer . type = V_40 ;
V_38 [ 2 ] . integer . V_14 = V_4 ;
V_39 . type = V_41 ;
V_39 . V_42 . V_43 = 3 ;
V_39 . V_42 . V_44 = V_38 ;
V_37 = F_15 ( F_16 ( V_2 -> V_16 ) ,
V_45 , 0 , V_33 , & V_39 ) ;
if ( ! V_37 ) {
F_17 ( V_2 -> V_16 , L_4 ,
V_34 , V_35 ) ;
return;
}
F_18 ( V_37 ) ;
}
static void F_19 ( struct V_1 * V_2 , bool V_46 )
{
T_1 V_47 ;
T_1 V_48 ;
if ( ! V_46 ) {
V_47 = V_49 ;
V_48 = V_50 ;
} else {
V_47 = V_51 ;
V_48 = V_52 ;
}
F_1 ( V_2 , V_47 , V_53 ) ;
F_1 ( V_2 , V_48 , V_53 ) ;
}
static void F_20 ( struct V_1 * V_2 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_55 ,
0 , V_46 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_35 ,
bool V_46 )
{
T_1 V_56 = 0 ;
T_1 V_57 ;
if ( V_35 >= V_58 )
return;
V_56 |= V_53 ;
V_56 |= 0x2082082 << V_2 -> V_9 [ V_35 ] -> V_59 ;
if ( ! V_46 )
V_57 = V_60 ;
else
V_57 = V_61 ;
F_1 ( V_2 , V_57 , V_56 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_62 , V_35 , V_46 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
T_1 V_56 = 0 ;
T_1 V_57 ;
if ( V_35 >= V_58 )
return;
V_56 |= V_63
<< V_2 -> V_9 [ V_35 ] -> V_59 ;
if ( ! V_46 )
V_57 = V_60 ;
else
V_57 = V_61 ;
F_1 ( V_2 , V_57 , V_56 ) ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_64 , bool V_46 )
{
T_1 V_57 ;
if ( ! V_46 )
V_57 = V_65 ;
else
V_57 = V_66 ;
F_1 ( V_2 , V_57 , V_64 ) ;
}
void
F_25 ( struct V_1 * V_2 , T_1 V_64 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_67 ,
V_64 , V_46 ) ;
}
void F_26 ( struct V_1 * V_2 , bool V_46 )
{
if ( ! V_46 ) {
F_1 ( V_2 , V_68 , 1 ) ;
} else {
F_1 ( V_2 ,
V_69 , 1 ) ;
F_1 ( V_2 ,
V_70 , 1 ) ;
F_27 ( 20 ) ;
F_1 ( V_2 , V_71 , 1 ) ;
}
}
void F_28 ( struct V_1 * V_2 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_72 , 0 , V_46 ) ;
}
static void
F_29 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_73 , V_35 , V_46 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_35 ,
bool V_46 )
{
T_1 V_74 ;
T_1 V_75 ;
T_1 V_59 ;
if ( V_35 >= V_76 )
return;
if ( ! F_31 ( V_2 ) ) {
V_74 = 0x1 << V_35 ;
V_59 = V_2 -> V_9 [ V_35 ] -> V_59 ;
V_75 = F_32 ( V_2 -> V_77 ) ?
0x1041041 : 0x2082082 ;
V_75 <<= V_59 ;
if ( ! V_46 ) {
F_1 ( V_2 , V_78 ,
V_74 ) ;
F_1 ( V_2 , V_79 ,
V_75 ) ;
} else {
F_1 ( V_2 , V_80 ,
V_75 ) ;
F_1 ( V_2 , V_81 ,
V_74 ) ;
}
} else {
V_74 = 0x15540 ;
V_75 = F_32 ( V_2 -> V_77 ) ? 0x100 : 0x40 ;
V_74 <<= V_2 -> V_82 ;
V_75 <<= V_2 -> V_82 ;
if ( ! V_46 ) {
F_1 ( V_2 , V_78 ,
V_74 ) ;
F_1 ( V_2 , V_83 ,
V_75 ) ;
} else {
F_1 ( V_2 , V_81 ,
V_74 ) ;
F_1 ( V_2 , V_84 ,
V_75 ) ;
}
}
}
static void F_33 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_85 , V_35 , V_46 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_1 V_35 ,
bool V_46 )
{
T_1 V_56 = 0 ;
T_1 V_57 ;
V_56 |= V_53 << V_2 -> V_9 [ V_35 ] -> V_59 ;
if ( ! V_46 )
V_57 = V_83 ;
else
V_57 = V_84 ;
F_1 ( V_2 , V_57 , V_56 ) ;
}
static void
F_35 ( struct V_1 * V_2 , T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_86 , V_35 , V_46 ) ;
}
static void F_36 ( struct V_1 * V_2 , bool V_46 )
{
T_1 V_56 ;
T_1 V_57 ;
if ( ! ( F_37 ( V_2 -> V_16 ) ) )
return;
if ( ! F_31 ( V_2 ) ) {
V_56 = V_53 ;
if ( ! V_46 )
V_57 = V_87 ;
else
V_57 = V_88 ;
} else {
V_56 = 0x100 << V_2 -> V_82 ;
if ( ! V_46 )
V_57 = V_83 ;
else
V_57 = V_84 ;
}
F_1 ( V_2 , V_57 , V_56 ) ;
}
static T_4 F_38 ( struct V_8 * V_9 )
{
T_1 V_89 ;
T_1 V_3 ;
bool V_90 = F_32 ( V_9 -> V_2 -> V_77 ) ;
int V_17 = V_9 -> V_17 ;
T_4 V_91 ;
if ( V_90 ) {
if ( F_31 ( V_9 -> V_2 ) )
return V_92 ;
if ( V_17 >= 0 && V_17 <= 3 )
V_3 = V_93 ;
else
V_3 = V_94 ;
} else{
if ( ! F_31 ( V_9 -> V_2 ) && V_17 <= 3 )
V_3 = V_95 ;
else
V_3 = V_96 ;
}
V_89 = F_4 ( V_9 -> V_2 , V_3 ) ;
if ( F_39 ( V_89 , V_9 -> V_97 ) )
V_91 = V_98 ;
else
V_91 = V_92 ;
return V_91 ;
}
static T_4 F_40 ( struct V_8 * V_9 )
{
T_4 V_91 = V_99 ;
union V_36 * V_37 ;
union V_36 V_38 , V_39 ;
V_38 . integer . type = V_40 ;
V_38 . integer . V_14 = V_9 -> V_17 ;
V_39 . type = V_41 ,
V_39 . V_42 . V_43 = 1 ,
V_39 . V_42 . V_44 = & V_38 ,
V_37 = F_15 ( F_16 ( V_9 -> V_16 ) ,
V_45 , 0 ,
V_100 , & V_39 ) ;
if ( ! V_37 || V_37 -> type != V_40 )
return V_91 ;
V_91 = V_37 -> integer . V_14 ?
V_98 : V_92 ;
F_41 ( V_9 -> V_16 , L_5 , V_9 -> V_17 , V_91 ) ;
F_18 ( V_37 ) ;
return V_91 ;
}
int F_42 ( struct V_8 * V_9 , int * V_101 )
{
if ( ! V_9 -> V_15 )
return - V_102 ;
* V_101 = ! F_5 ( V_9 -> V_15 , V_9 -> V_24
+ V_103 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , bool V_104 )
{
const T_3 V_105 [] = {
0 ,
1 ,
2 ,
3 ,
2 ,
3 ,
0 ,
1
} ;
#define F_44 ( T_5 , V_3 ) ((0x4080 + (reg) * 0x0002 + (lane) * 0x0200) * 2)
T_6 V_106 = F_44 ( V_105 [ V_9 -> V_17 ] , 0 ) ;
int V_101 ;
int V_7 = F_42 ( V_9 , & V_101 ) ;
if ( ! V_9 -> V_107 ) {
if ( V_7 )
F_45 ( L_6 ) ;
else
if ( ! V_101 )
F_45 ( L_7 ) ;
}
if ( V_9 -> V_108 ) {
T_1 V_109 ;
if ( ! F_32 ( V_9 -> V_2 -> V_77 ) ) {
#define F_46 0x40008
if ( ( ! F_31 ( V_9 -> V_2 ) ) &&
( V_9 -> V_17 <= 3 ) )
F_2 ( V_9 -> V_108 ,
F_46 , 0 ) ;
else
F_2 ( V_9 -> V_108 ,
F_46 , 3 ) ;
}
V_109 = F_5 ( V_9 -> V_108 , V_106 ) ;
F_11 ( V_109 , 1ull << 10 , 10 , V_104 ) ;
F_2 ( V_9 -> V_108 , V_106 , V_109 ) ;
} else {
T_3 * V_110 = ( T_3 * ) V_9 -> V_111 +
( V_9 -> V_17 <= 3 ? 0x00280000 : 0x00200000 ) ;
F_47 ( V_110 , V_106 , 1ull << 10 , 10 , V_104 ) ;
}
return 0 ;
}
static int
F_48 ( struct V_8 * V_9 , bool V_104 )
{
union V_36 * V_37 ;
union V_36 V_38 [ 3 ] , V_39 ;
V_38 [ 0 ] . integer . type = V_40 ;
V_38 [ 0 ] . integer . V_14 = V_9 -> V_17 ;
V_38 [ 1 ] . integer . type = V_40 ;
V_38 [ 1 ] . integer . V_14 = ! ! V_104 ;
V_39 . type = V_41 ;
V_39 . V_42 . V_43 = 2 ;
V_39 . V_42 . V_44 = V_38 ;
V_37 = F_15 ( F_16 ( V_9 -> V_2 -> V_16 ) ,
V_45 , 0 ,
V_112 , & V_39 ) ;
if ( ! V_37 ) {
F_17 ( V_9 -> V_2 -> V_16 , L_8 ,
V_9 -> V_17 ) ;
return - V_113 ;
}
F_18 ( V_37 ) ;
return 0 ;
}
struct V_114 * F_49 ( struct V_1 * V_2 )
{
struct V_114 * V_115 ;
V_115 = F_50 ( V_2 -> V_16 , sizeof( * V_115 ) , V_116 ) ;
if ( ! V_115 )
return NULL ;
if ( F_37 ( V_2 -> V_16 ) ) {
V_115 -> V_117 = F_7 ;
V_115 -> V_118 = F_12 ;
V_115 -> F_13 = F_13 ;
V_115 -> V_119 = F_19 ;
V_115 -> V_120 = F_21 ;
V_115 -> V_121 = F_23 ;
V_115 -> V_122 = F_30 ;
V_115 -> V_123 = F_34 ;
V_115 -> V_124 = F_36 ;
V_115 -> F_24 = F_24 ;
V_115 -> F_26 = F_26 ;
V_115 -> V_125 = F_38 ;
V_115 -> V_126 = F_42 ;
V_115 -> V_127 = F_43 ;
} else if ( F_51 ( V_2 -> V_16 -> V_128 ) ) {
V_115 -> V_117 = F_7 ;
V_115 -> V_118 = F_12 ;
V_115 -> F_13 = F_13 ;
V_115 -> V_119 = F_20 ;
V_115 -> V_120 = F_22 ;
V_115 -> V_121 = F_29 ;
V_115 -> V_122 = F_33 ;
V_115 -> V_123 = F_35 ;
V_115 -> V_124 = F_36 ;
V_115 -> F_24 = F_25 ;
V_115 -> F_26 = F_28 ;
V_115 -> V_125 = F_40 ;
V_115 -> V_126 = F_42 ;
V_115 -> V_127 = F_48 ;
} else {
F_52 ( V_2 -> V_16 , ( void * ) V_115 ) ;
V_115 = NULL ;
}
return ( void * ) V_115 ;
}
static int F_53 ( struct V_129 * V_16 , void * V_128 )
{
return V_16 -> V_128 == V_128 ;
}
struct
V_130 * F_54 ( struct V_131 * V_128 )
{
struct V_129 * V_16 ;
V_16 = F_55 ( & V_132 , NULL ,
V_128 , F_53 ) ;
return V_16 ? F_56 ( V_16 ) : NULL ;
}
