static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 . V_6 )
F_3 ( V_4 -> V_5 . V_6 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_7 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_8 ( V_2 -> V_9 ) ;
if ( V_9 )
F_9 ( & V_9 -> V_5 ) ;
F_10 ( V_9 ) ;
V_2 -> V_9 = NULL ;
V_9 = F_11 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_9 ) {
V_9 -> V_5 . V_2 = V_2 ;
V_9 -> V_5 . V_11 = V_12 ;
V_2 -> V_9 = & V_9 -> V_5 ;
}
}
static struct
V_13 * F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_14 ;
if ( ! V_2 -> V_9 )
return NULL ;
V_9 = F_13 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_14 = F_8 ( V_2 -> V_9 ) ;
F_14 ( V_2 , & V_9 -> V_5 ) ;
V_9 -> V_15 = V_14 -> V_15 ;
V_9 -> V_16 = V_14 -> V_16 ;
V_9 -> V_17 = V_14 -> V_17 ;
return & V_9 -> V_5 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_9 )
{
struct V_8 * V_14 = F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
F_10 ( V_14 ) ;
}
static void F_16 ( struct V_18 * V_19 ,
const struct V_13 * V_9 )
{
struct V_8 * V_20 = F_8 ( V_9 ) ;
F_17 ( V_19 , L_1 , V_20 -> V_15 ) ;
F_17 ( V_19 , L_2 , V_20 -> V_16 ) ;
F_17 ( V_19 , L_3 , V_20 -> V_17 ) ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_13 * V_9 )
{
struct V_21 * V_22 =
F_19 ( V_9 -> V_9 , V_9 -> V_23 ) ;
struct V_24 * V_25 ;
struct V_26 V_27 = { 0 } ;
T_1 V_28 , V_29 ;
int V_30 ;
if ( ! V_22 )
return - V_31 ;
V_27 . V_32 = V_22 -> V_33 . V_34 ;
V_27 . V_35 = V_22 -> V_33 . V_36 ;
V_30 = F_20 ( V_9 , & V_27 , 0 , V_37 , true , true ) ;
if ( V_30 )
return V_30 ;
V_28 = V_9 -> V_28 >> 16 ;
V_29 = V_9 -> V_29 >> 16 ;
if ( ( V_9 -> V_38 == V_28 ) && ( V_9 -> V_39 == V_29 ) ) {
V_25 -> V_40 &= ~ ( V_4 -> V_41 -> V_42 ) ;
return 0 ;
}
if ( V_4 -> V_41 -> V_42 & ( V_43 | V_44 ) )
return - V_31 ;
V_25 = F_21 ( V_22 ) ;
V_25 -> V_40 |= V_4 -> V_41 -> V_42 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_13 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_20 = F_8 ( V_9 ) ;
struct V_45 * V_6 ;
int V_46 , V_30 ;
if ( ! V_9 -> V_23 || ! V_9 -> V_6 )
return 0 ;
V_6 = V_9 -> V_6 ;
V_20 -> V_16 = F_23 ( & V_4 -> V_47 -> V_48 , V_4 -> V_41 -> V_42 ,
V_6 -> V_16 -> V_16 ) ;
if ( V_20 -> V_16 == V_49 )
return - V_31 ;
V_20 -> V_17 = V_6 -> V_16 -> V_50 ;
for ( V_46 = 0 ; V_46 < V_20 -> V_17 ; V_46 ++ ) {
if ( ! F_24 ( V_4 -> V_47 , V_6 -> V_51 [ V_46 ] ) ) {
F_25 ( L_4 ,
V_6 -> V_51 [ V_46 ] , V_46 ) ;
return - V_31 ;
}
}
if ( ( V_9 -> V_38 > V_4 -> V_47 -> V_52 ) ||
( V_9 -> V_39 > V_4 -> V_47 -> V_52 ) ||
( V_9 -> V_38 < V_4 -> V_47 -> V_53 ) ||
( V_9 -> V_39 < V_4 -> V_47 -> V_53 ) )
return - V_31 ;
if ( V_20 -> V_17 == 3 &&
! ( V_4 -> V_47 -> V_54 & V_55 ) &&
( V_9 -> V_6 -> V_51 [ 1 ] != V_9 -> V_6 -> V_51 [ 2 ] ) )
return - V_31 ;
V_30 = F_18 ( V_4 , V_9 ) ;
if ( V_30 )
return V_30 ;
if ( V_9 -> V_11 != V_12 &&
( V_6 -> V_16 -> V_16 == V_56 ||
V_6 -> V_16 -> V_16 == V_57 ) )
return - V_31 ;
V_20 -> V_15 = 0 ;
if ( V_9 -> V_11 & V_58 ) {
int V_59 ;
V_59 = V_4 -> V_47 -> V_60 ( V_4 -> V_47 , V_9 -> V_39 ,
V_9 -> V_38 ,
V_6 -> V_16 -> V_16 ) ;
if ( V_59 < 0 )
return V_59 ;
V_20 -> V_15 = V_59 ;
}
return 0 ;
}
static void F_26 ( struct V_3 * V_4 ,
int V_50 , unsigned int V_51 [ 3 ] )
{
int V_46 ;
int V_61 = V_50 ;
if ( ! V_4 -> V_41 -> V_62 )
return;
if ( V_50 == 3 )
V_61 = ( V_4 -> V_47 -> V_54 &
V_55 ) ? 3 : 2 ;
for ( V_46 = 0 ; V_46 < V_61 ; ++ V_46 )
F_27 ( V_4 -> V_47 , V_51 [ V_46 ] ,
V_4 -> V_41 -> V_5 +
V_4 -> V_41 -> V_62 + V_46 * 4 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_13 * V_63 )
{
struct V_3 * V_4 ;
const struct V_64 * V_48 ;
struct V_8 * V_20 = F_8 ( V_2 -> V_9 ) ;
T_1 V_28 , V_29 , V_65 , V_66 , V_59 ;
int V_46 ;
V_4 = F_2 ( V_2 ) ;
V_48 = & V_4 -> V_47 -> V_48 ;
V_28 = V_2 -> V_9 -> V_28 >> 16 ;
V_29 = V_2 -> V_9 -> V_29 >> 16 ;
V_65 = V_2 -> V_9 -> V_38 ;
V_66 = V_2 -> V_9 -> V_39 ;
F_27 ( V_4 -> V_47 , V_20 -> V_16 , V_4 -> V_41 -> V_5 ) ;
for ( V_46 = 0 ; V_46 < V_20 -> V_17 ; V_46 ++ ) {
T_2 V_67 = V_4 -> V_41 -> V_67 + ( V_46 << 4 ) ;
T_3 V_68 = F_29 ( V_2 -> V_9 -> V_6 ,
V_2 -> V_9 , V_46 ) ;
F_27 ( V_4 -> V_47 , F_30 ( V_68 ) , V_67 ) ;
F_27 ( V_4 -> V_47 , F_31 ( V_68 ) , V_67 + 4 ) ;
}
F_26 ( V_4 , V_20 -> V_17 ,
V_2 -> V_9 -> V_6 -> V_51 ) ;
F_27 ( V_4 -> V_47 , F_32 ( V_28 ) | F_33 ( V_29 ) ,
V_4 -> V_41 -> V_5 + V_69 ) ;
F_27 ( V_4 -> V_47 , F_32 ( V_65 ) | F_33 ( V_66 ) ,
V_4 -> V_41 -> V_5 + V_70 ) ;
F_27 ( V_4 -> V_47 , F_32 ( V_2 -> V_9 -> V_71 ) |
F_33 ( V_2 -> V_9 -> V_72 ) ,
V_4 -> V_41 -> V_5 + V_73 ) ;
if ( V_4 -> V_41 -> V_42 == V_43 )
F_27 ( V_4 -> V_47 ,
F_32 ( V_28 ) | F_33 ( V_29 ) ,
V_4 -> V_41 -> V_5 + V_74 ) ;
V_59 = F_34 ( V_4 -> V_47 , V_4 -> V_41 -> V_5 + V_75 ) ;
V_59 &= ~ V_76 ;
if ( V_2 -> V_9 -> V_11 & V_77 )
V_59 |= F_35 ( V_2 -> V_9 -> V_11 & V_77 ) <<
V_78 ;
if ( V_2 -> V_9 -> V_11 & V_79 )
V_59 |= V_80 ;
if ( V_2 -> V_9 -> V_11 & V_81 )
V_59 |= V_82 ;
V_59 &= ~ V_83 ;
V_59 |= V_84 ;
V_59 &= ~ F_36 ( V_85 ) ;
if ( V_2 -> V_9 -> V_23 ) {
struct V_24 * V_86 =
F_21 ( V_2 -> V_9 -> V_23 -> V_9 ) ;
if ( V_86 -> V_87 . V_88 &&
V_86 -> V_87 . V_89 == V_4 -> V_41 -> V_42 )
V_59 |= F_36 ( V_90 ) ;
}
V_59 |= V_91 ;
F_27 ( V_4 -> V_47 , V_59 ,
V_4 -> V_41 -> V_5 + V_75 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_47 ,
V_91 | F_36 ( V_85 ) ,
V_4 -> V_41 -> V_5 + V_75 ) ;
}
int F_39 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
const struct V_64 * V_48 = & V_95 -> V_7 -> V_48 ;
struct V_3 * V_2 = NULL ;
enum V_97 V_98 ;
unsigned long V_99 = 1 << V_93 -> V_100 . V_101 ;
unsigned long V_102 = V_12 | V_103 | V_104 |
V_105 | V_79 | V_81 ;
T_1 * V_106 ;
int V_30 , V_46 , V_107 , V_108 ;
V_106 = F_40 ( V_48 -> V_109 , sizeof( * V_106 ) , V_10 ) ;
if ( ! V_106 ) {
V_30 = - V_110 ;
goto V_111;
}
for ( V_46 = 0 ; V_46 < V_48 -> V_112 ; V_46 ++ ) {
T_4 V_42 = V_48 -> V_113 [ V_46 ] . V_42 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 ) {
V_30 = - V_110 ;
goto V_111;
}
for ( V_108 = 0 , V_107 = 0 ; V_107 < V_48 -> V_109 ; V_107 ++ ) {
if ( ( V_48 -> V_114 [ V_107 ] . V_41 & V_42 ) == V_42 )
V_106 [ V_108 ++ ] = V_48 -> V_114 [ V_107 ] . V_16 ;
}
V_98 = ( V_46 == 0 ) ? V_115 :
V_116 ;
V_30 = F_41 ( V_93 , & V_2 -> V_5 , V_99 ,
& V_117 , V_106 ,
V_108 , V_98 , NULL ) ;
if ( V_30 < 0 )
goto V_111;
F_42 ( & V_2 -> V_5 ,
& V_118 ) ;
V_2 -> V_47 = V_95 -> V_7 ;
V_2 -> V_41 = & V_48 -> V_113 [ V_46 ] ;
if ( V_42 == V_43 ) {
F_27 ( V_95 -> V_7 , 1 ,
V_2 -> V_41 -> V_5 + V_119 ) ;
continue;
}
F_43 ( & V_2 -> V_5 , V_12 , V_102 ) ;
F_27 ( V_95 -> V_7 , V_120 ,
V_2 -> V_41 -> V_5 + V_121 ) ;
}
F_10 ( V_106 ) ;
return 0 ;
V_111:
F_44 ( V_93 ) ;
F_10 ( V_106 ) ;
return V_30 ;
}
void F_44 ( struct V_92 * V_93 )
{
struct V_1 * V_19 , * V_122 ;
F_45 (p, pt, &drm->mode_config.plane_list, head) {
F_5 ( V_19 ) ;
F_10 ( V_19 ) ;
}
}
