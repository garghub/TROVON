static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 & V_2 ) >>
V_3 ;
}
static T_2 F_2 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
const T_3 * V_8 ;
T_4 V_9 ;
V_7 = V_5 -> V_10 [ V_11 ] ;
V_8 = ( T_3 * ) V_7 . V_12 ;
V_9 = F_3 ( V_8 [ V_13 ] ) ;
if ( V_9 < V_14 || V_9 > V_15 )
V_9 = V_16 ;
return V_9 ;
}
static T_4 F_4 ( struct V_4 * V_5 )
{
const T_5 * V_8 ;
T_5 V_17 , V_18 , V_19 , V_20 ;
V_8 = V_5 -> V_10 [ V_11 ] . V_12 ;
V_17 = V_8 [ V_21 ] ;
V_18 = V_8 [ V_21 + 1 ] ;
V_19 = V_8 [ V_21 + 2 ] ;
if ( V_17 > V_18 ) {
if ( V_17 > V_19 )
V_20 = ( V_18 > V_19 ) ? V_18 : V_19 ;
else
V_20 = V_17 ;
} else {
if ( V_18 > V_19 )
V_20 = ( V_17 > V_19 ) ? V_17 : V_19 ;
else
V_20 = V_18 ;
}
return V_17 - V_20 ;
}
static T_5 F_5 ( struct V_4 * V_5 , T_5 V_22 )
{
T_2 V_23 = V_22 - F_4 ( V_5 ) ;
if ( V_23 > V_24 )
V_23 = V_24 ;
else if ( V_23 < V_25 )
V_23 = V_25 ;
return V_23 ;
}
static bool F_6 ( struct V_4 * V_5 ,
union V_26 * V_27 )
{
T_5 V_28 [ V_29 ] ;
T_5 V_30 = 0 , V_1 ;
T_1 V_31 ;
V_31 = F_7 ( V_5 -> V_32 , V_33 ) ;
memcpy ( V_28 , & V_31 , sizeof( V_31 ) ) ;
V_31 = F_7 ( V_5 -> V_32 , V_34 ) ;
V_28 [ 4 ] = V_31 & 0xff ;
if ( V_27 -> V_35 . V_36 < V_28 [ 0 ] ||
V_27 -> V_35 . V_36 > V_28 [ 4 ] )
return false ;
if ( V_27 -> V_35 . V_36 > V_28 [ 3 ] )
V_30 = 3 ;
else if ( V_27 -> V_35 . V_36 > V_28 [ 2 ] )
V_30 = 2 ;
else if ( V_27 -> V_35 . V_36 > V_28 [ 1 ] )
V_30 = 1 ;
V_27 -> V_35 . V_37 = V_28 [ V_30 ] ;
V_27 -> V_35 . V_38 = V_28 [ V_30 + 1 ] ;
V_1 = V_27 -> V_35 . V_1 ;
V_27 -> V_35 . V_1 =
( V_1 & ~ V_2 ) |
( V_30 & V_2 ) ;
return true ;
}
static bool F_8 ( struct V_4 * V_5 ,
union V_26 * V_27 )
{
T_1 V_31 ;
T_5 V_39 ;
V_31 = F_7 ( V_5 -> V_32 , V_40 ) ;
V_31 &= V_41 | V_42 ;
V_27 -> V_43 = V_31 ;
V_39 = V_27 -> V_35 . V_36 ;
V_39 = F_5 ( V_5 , V_39 ) ;
V_27 -> V_35 . V_36 = V_39 ;
return F_6 ( V_5 , V_27 ) &&
F_9 ( V_27 -> V_35 . V_1 ) ;
}
static T_6 F_10 ( union V_26 V_27 ,
T_4 V_44 )
{
T_1 V_45 ;
T_5 V_46 ;
static const T_4 V_47 [ V_48 ] = {
2168 , 2118 , 2071 , 2026 , 1983 , 1942 , 1902 , 1864 , 1828 ,
} ;
V_46 = V_27 . V_35 . V_38 - V_27 . V_35 . V_37 ;
if ( V_46 < V_49 ||
V_46 > V_50 )
return V_51 ;
V_45 =
V_46 * ( F_1 ( V_27 . V_35 . V_1 ) + 9 ) ;
V_45 += V_27 . V_35 . V_36 ;
V_45 -= V_27 . V_35 . V_38 ;
V_45 *= V_47 [ V_46 - V_52 ] ;
V_45 *= V_44 ;
V_45 = V_45 >> V_53 ;
return ( T_2 ) V_45 - 240 ;
}
static T_6 F_11 ( struct V_4 * V_5 )
{
T_4 V_44 ;
union V_26 V_27 ;
V_44 = F_2 ( V_5 ) ;
F_12 ( V_5 -> V_32 , V_54 , 0 ) ;
F_12 ( V_5 -> V_32 , V_54 , 1 ) ;
F_12 ( V_5 -> V_32 , V_55 ,
V_56 ) ;
F_13 ( 100 ) ;
if ( ! F_8 ( V_5 , & V_27 ) )
return V_51 ;
F_12 ( V_5 -> V_32 , V_54 , 0 ) ;
return F_10 ( V_27 , V_44 ) ;
}
static void F_14 ( struct V_4 * V_5 )
{
T_1 V_57 = V_5 -> V_58 . V_59 -> V_60 ;
F_15 ( V_5 , L_1 ) ;
F_16 ( V_5 , true ) ;
F_17 ( & V_5 -> V_58 . V_61 ,
F_18 ( V_57 * V_62 ) ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_15 ( V_5 , L_2 ) ;
F_16 ( V_5 , false ) ;
}
static void F_20 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_4 * V_5 ;
T_1 V_57 ;
T_6 V_67 ;
V_66 = F_21 ( V_64 , struct V_65 , V_61 . V_64 ) ;
V_5 = F_21 ( V_66 , struct V_4 , V_58 ) ;
V_57 = V_66 -> V_59 -> V_60 ;
F_22 ( V_5 -> V_32 ) ;
V_67 = F_11 ( V_5 ) ;
F_23 ( V_5 -> V_32 ) ;
if ( V_67 < V_68 || V_67 > V_69 ) {
F_24 ( V_5 , L_3 ) ;
goto V_70;
}
F_24 ( V_5 , L_4 , V_67 ) ;
if ( V_67 <= V_66 -> V_59 -> V_61 ) {
F_19 ( V_5 ) ;
return;
}
V_70:
F_17 ( & V_5 -> V_58 . V_61 ,
F_25 ( V_57 * V_62 ) ) ;
}
static void F_26 ( void * V_71 , T_5 * V_72 ,
struct V_73 * V_74 )
{
struct V_4 * V_5 = V_71 ;
enum V_75 V_76 ;
F_27 ( & V_5 -> V_77 ) ;
if ( V_5 -> V_58 . V_78 )
V_76 = V_79 ;
else
V_76 = V_80 ;
if ( V_74 -> type != V_81 )
return;
F_28 ( V_5 , V_74 , V_82 , V_76 ) ;
}
static void F_29 ( struct V_4 * V_5 , bool V_83 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_88 , V_89 ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
V_85 = F_30 ( V_5 -> V_91 [ V_88 ] ,
F_31 ( & V_5 -> V_77 ) ) ;
if ( F_32 ( V_85 ) )
continue;
V_87 = F_33 ( V_85 ) ;
if ( V_83 == V_87 -> V_92 )
continue;
V_89 = F_34 ( V_5 , V_87 , V_83 ) ;
if ( V_89 ) {
F_15 ( V_5 , L_5 ,
V_83 ? L_6 : L_7 ) ;
} else {
F_24 ( V_5 , L_8 ,
V_83 ? L_9 : L_10 ) ;
V_87 -> V_92 = V_83 ;
}
}
}
static void F_35 ( struct V_4 * V_5 , T_1 V_93 )
{
struct V_94 V_95 = {
. V_96 = V_97 ,
. V_98 = { sizeof( T_1 ) , } ,
. V_12 = { & V_93 , } ,
. V_1 = V_99 ,
} ;
if ( F_36 ( V_5 , & V_95 ) == 0 ) {
F_24 ( V_5 , L_11 ,
V_93 ) ;
V_5 -> V_58 . V_100 = V_93 ;
} else {
F_15 ( V_5 , L_12 ) ;
}
}
void F_37 ( struct V_4 * V_5 )
{
const struct V_101 * V_59 = V_5 -> V_58 . V_59 ;
struct V_65 * V_66 = & V_5 -> V_58 ;
T_6 V_102 = V_5 -> V_102 ;
bool V_103 = false ;
int V_88 ;
T_1 V_100 ;
F_24 ( V_5 , L_4 , V_5 -> V_102 ) ;
if ( V_59 -> V_104 && V_102 >= V_59 -> V_105 ) {
F_14 ( V_5 ) ;
return;
}
if ( V_59 -> V_106 ) {
if ( ! V_66 -> V_78 &&
V_102 >= V_59 -> V_107 ) {
F_24 ( V_5 , L_13 ) ;
V_66 -> V_78 = true ;
F_38 (
V_5 -> V_108 , V_109 ,
F_26 , V_5 ) ;
V_103 = true ;
} else if ( V_66 -> V_78 &&
V_102 <= V_59 -> V_110 ) {
F_24 ( V_5 , L_14 ) ;
V_66 -> V_78 = false ;
F_38 (
V_5 -> V_108 , V_109 ,
F_26 , V_5 ) ;
}
}
if ( V_59 -> V_111 ) {
if ( V_102 >= V_59 -> V_112 ) {
F_29 ( V_5 , true ) ;
V_103 = true ;
} else if ( V_102 <= V_59 -> V_113 ) {
F_29 ( V_5 , false ) ;
}
}
if ( V_59 -> V_114 ) {
V_100 = 0 ;
for ( V_88 = 0 ; V_88 < V_115 ; V_88 ++ ) {
if ( V_102 < V_59 -> V_100 [ V_88 ] . V_102 )
break;
V_100 = V_59 -> V_100 [ V_88 ] . V_93 ;
}
if ( V_100 != 0 )
V_103 = true ;
if ( V_66 -> V_100 != V_100 )
F_35 ( V_5 , V_100 ) ;
}
if ( ! V_66 -> V_116 && V_103 ) {
F_39 ( V_5 ,
L_15 ) ;
V_66 -> V_116 = true ;
} else if ( V_66 -> V_116 && ! V_66 -> V_78 && V_66 -> V_100 == 0 &&
V_102 <= V_59 -> V_113 ) {
F_39 ( V_5 ,
L_16 ) ;
V_66 -> V_116 = false ;
}
}
void F_40 ( struct V_4 * V_5 )
{
struct V_65 * V_66 = & V_5 -> V_58 ;
F_24 ( V_5 , L_17 ) ;
if ( V_5 -> V_117 -> V_118 )
V_66 -> V_59 = & V_119 ;
else
V_66 -> V_59 = & V_120 ;
V_66 -> V_116 = false ;
F_41 ( & V_66 -> V_61 , F_20 ) ;
}
void F_42 ( struct V_4 * V_5 )
{
F_43 ( & V_5 -> V_58 . V_61 ) ;
F_24 ( V_5 , L_18 ) ;
}
