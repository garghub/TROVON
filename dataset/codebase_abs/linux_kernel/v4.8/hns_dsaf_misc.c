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
static void
F_24 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_64 , V_35 , V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_35 ,
bool V_46 )
{
T_1 V_65 ;
T_1 V_66 ;
T_1 V_59 ;
if ( V_35 >= V_67 )
return;
if ( ! F_26 ( V_2 ) ) {
V_65 = 0x1 << V_35 ;
V_59 = V_2 -> V_9 [ V_35 ] -> V_59 ;
V_66 = F_27 ( V_2 -> V_68 ) ?
0x1041041 : 0x2082082 ;
V_66 <<= V_59 ;
if ( ! V_46 ) {
F_1 ( V_2 , V_69 ,
V_65 ) ;
F_1 ( V_2 , V_70 ,
V_66 ) ;
} else {
F_1 ( V_2 , V_71 ,
V_66 ) ;
F_1 ( V_2 , V_72 ,
V_65 ) ;
}
} else {
V_65 = 0x15540 ;
V_66 = F_27 ( V_2 -> V_68 ) ? 0x100 : 0x40 ;
V_65 <<= V_2 -> V_73 ;
V_66 <<= V_2 -> V_73 ;
if ( ! V_46 ) {
F_1 ( V_2 , V_69 ,
V_65 ) ;
F_1 ( V_2 , V_74 ,
V_66 ) ;
} else {
F_1 ( V_2 , V_72 ,
V_65 ) ;
F_1 ( V_2 , V_75 ,
V_66 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 ,
T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_76 , V_35 , V_46 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_35 ,
bool V_46 )
{
T_1 V_56 = 0 ;
T_1 V_57 ;
V_56 |= V_53 << V_2 -> V_9 [ V_35 ] -> V_59 ;
if ( ! V_46 )
V_57 = V_74 ;
else
V_57 = V_75 ;
F_1 ( V_2 , V_57 , V_56 ) ;
}
static void
F_30 ( struct V_1 * V_2 , T_1 V_35 , bool V_46 )
{
F_14 ( V_2 , V_54 ,
V_77 , V_35 , V_46 ) ;
}
static void F_31 ( struct V_1 * V_2 , bool V_46 )
{
T_1 V_56 ;
T_1 V_57 ;
if ( ! ( F_32 ( V_2 -> V_16 ) ) )
return;
if ( ! F_26 ( V_2 ) ) {
V_56 = V_53 ;
if ( ! V_46 )
V_57 = V_78 ;
else
V_57 = V_79 ;
} else {
V_56 = 0x100 << V_2 -> V_73 ;
if ( ! V_46 )
V_57 = V_74 ;
else
V_57 = V_75 ;
}
F_1 ( V_2 , V_57 , V_56 ) ;
}
static T_4 F_33 ( struct V_8 * V_9 )
{
T_1 V_80 ;
T_1 V_3 ;
bool V_81 = F_27 ( V_9 -> V_2 -> V_68 ) ;
int V_17 = V_9 -> V_17 ;
T_4 V_82 ;
if ( V_81 ) {
if ( F_26 ( V_9 -> V_2 ) )
return V_83 ;
if ( V_17 >= 0 && V_17 <= 3 )
V_3 = V_84 ;
else
V_3 = V_85 ;
} else{
if ( ! F_26 ( V_9 -> V_2 ) && V_17 <= 3 )
V_3 = V_86 ;
else
V_3 = V_87 ;
}
V_80 = F_4 ( V_9 -> V_2 , V_3 ) ;
if ( F_34 ( V_80 , V_9 -> V_88 ) )
V_82 = V_89 ;
else
V_82 = V_83 ;
return V_82 ;
}
static T_4 F_35 ( struct V_8 * V_9 )
{
T_4 V_82 = V_90 ;
union V_36 * V_37 ;
union V_36 V_38 , V_39 ;
V_38 . integer . type = V_40 ;
V_38 . integer . V_14 = V_9 -> V_17 ;
V_39 . type = V_41 ,
V_39 . V_42 . V_43 = 1 ,
V_39 . V_42 . V_44 = & V_38 ,
V_37 = F_15 ( F_16 ( V_9 -> V_16 ) ,
V_45 , 0 ,
V_91 , & V_39 ) ;
if ( ! V_37 || V_37 -> type != V_40 )
return V_82 ;
V_82 = V_37 -> integer . V_14 ?
V_89 : V_83 ;
F_36 ( V_9 -> V_16 , L_5 , V_9 -> V_17 , V_82 ) ;
F_18 ( V_37 ) ;
return V_82 ;
}
int F_37 ( struct V_8 * V_9 , int * V_92 )
{
if ( ! V_9 -> V_15 )
return - V_93 ;
* V_92 = ! F_5 ( V_9 -> V_15 , V_9 -> V_24
+ V_94 ) ;
return 0 ;
}
static int F_38 ( struct V_8 * V_9 , bool V_95 )
{
const T_3 V_96 [] = {
0 ,
1 ,
2 ,
3 ,
2 ,
3 ,
0 ,
1
} ;
#define F_39 ( T_5 , V_3 ) ((0x4080 + (reg) * 0x0002 + (lane) * 0x0200) * 2)
T_6 V_97 = F_39 ( V_96 [ V_9 -> V_17 ] , 0 ) ;
int V_92 ;
int V_7 = F_37 ( V_9 , & V_92 ) ;
if ( ! V_9 -> V_98 ) {
if ( V_7 )
F_40 ( L_6 ) ;
else
if ( ! V_92 )
F_40 ( L_7 ) ;
}
if ( V_9 -> V_99 ) {
T_1 V_100 ;
if ( ! F_27 ( V_9 -> V_2 -> V_68 ) ) {
#define F_41 0x40008
if ( ( ! F_26 ( V_9 -> V_2 ) ) &&
( V_9 -> V_17 <= 3 ) )
F_2 ( V_9 -> V_99 ,
F_41 , 0 ) ;
else
F_2 ( V_9 -> V_99 ,
F_41 , 3 ) ;
}
V_100 = F_5 ( V_9 -> V_99 , V_97 ) ;
F_11 ( V_100 , 1ull << 10 , 10 , V_95 ) ;
F_2 ( V_9 -> V_99 , V_97 , V_100 ) ;
} else {
T_3 * V_101 = ( T_3 * ) V_9 -> V_102 +
( V_9 -> V_17 <= 3 ? 0x00280000 : 0x00200000 ) ;
F_42 ( V_101 , V_97 , 1ull << 10 , 10 , V_95 ) ;
}
return 0 ;
}
static int
F_43 ( struct V_8 * V_9 , bool V_95 )
{
union V_36 * V_37 ;
union V_36 V_38 [ 3 ] , V_39 ;
V_38 [ 0 ] . integer . type = V_40 ;
V_38 [ 0 ] . integer . V_14 = V_9 -> V_17 ;
V_38 [ 1 ] . integer . type = V_40 ;
V_38 [ 1 ] . integer . V_14 = ! ! V_95 ;
V_39 . type = V_41 ;
V_39 . V_42 . V_43 = 2 ;
V_39 . V_42 . V_44 = V_38 ;
V_37 = F_15 ( F_16 ( V_9 -> V_2 -> V_16 ) ,
V_45 , 0 ,
V_103 , & V_39 ) ;
if ( ! V_37 ) {
F_17 ( V_9 -> V_2 -> V_16 , L_8 ,
V_9 -> V_17 ) ;
return - V_104 ;
}
F_18 ( V_37 ) ;
return 0 ;
}
struct V_105 * F_44 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
V_106 = F_45 ( V_2 -> V_16 , sizeof( * V_106 ) , V_107 ) ;
if ( ! V_106 )
return NULL ;
if ( F_32 ( V_2 -> V_16 ) ) {
V_106 -> V_108 = F_7 ;
V_106 -> V_109 = F_12 ;
V_106 -> F_13 = F_13 ;
V_106 -> V_110 = F_19 ;
V_106 -> V_111 = F_21 ;
V_106 -> V_112 = F_23 ;
V_106 -> V_113 = F_25 ;
V_106 -> V_114 = F_29 ;
V_106 -> V_115 = F_31 ;
V_106 -> V_116 = F_33 ;
V_106 -> V_117 = F_37 ;
V_106 -> V_118 = F_38 ;
} else if ( F_46 ( V_2 -> V_16 -> V_119 ) ) {
V_106 -> V_108 = F_7 ;
V_106 -> V_109 = F_12 ;
V_106 -> F_13 = F_13 ;
V_106 -> V_110 = F_20 ;
V_106 -> V_111 = F_22 ;
V_106 -> V_112 = F_24 ;
V_106 -> V_113 = F_28 ;
V_106 -> V_114 = F_30 ;
V_106 -> V_115 = F_31 ;
V_106 -> V_116 = F_35 ;
V_106 -> V_117 = F_37 ;
V_106 -> V_118 = F_43 ;
} else {
F_47 ( V_2 -> V_16 , ( void * ) V_106 ) ;
V_106 = NULL ;
}
return ( void * ) V_106 ;
}
