static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static bool F_5 ( struct V_6 V_7 , int * V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ )
if ( F_7 ( & V_10 [ V_9 ] . V_7 , & V_7 ) ) {
* V_8 = V_9 ;
return true ;
}
return false ;
}
static void F_8 ( struct V_1 * V_2 , bool V_11 )
{
if ( V_2 -> V_12 ) {
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_12 ) ;
if ( V_11 )
V_5 &= ~ V_13 ;
else
V_5 |= V_13 ;
F_4 ( V_5 , V_2 -> V_12 ) ;
}
}
static void F_9 ( struct V_14 * V_15 , int V_5 )
{
F_10 ( V_15 , L_1 ) ;
F_10 ( V_15 , V_5 & V_16 ? L_2 : L_3 ) ;
}
static void F_11 ( struct V_14 * V_15 , void T_2 * V_17 )
{
unsigned int V_9 ;
F_10 ( V_15 , L_4 ) ;
F_10 ( V_15 , L_5 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
if ( V_9 % 8 == 0 )
F_12 ( V_15 , L_6 , V_9 ) ;
F_12 ( V_15 , L_7 , F_2 ( V_17 + V_9 * 4 ) ) ;
}
}
static void F_13 ( struct V_14 * V_15 , void T_2 * V_17 )
{
T_1 V_5 = F_2 ( V_17 ) ;
F_10 ( V_15 , L_8 ) ;
F_12 ( V_15 , L_9 , L_10 , V_5 ) ;
F_10 ( V_15 , L_11 ) ;
F_10 ( V_15 , V_5 & V_13 ? L_3 : L_2 ) ;
}
static int F_14 ( struct V_14 * V_15 , void * V_19 )
{
struct V_20 * V_21 = V_15 -> V_22 ;
struct V_1 * V_2 = (struct V_1 * ) V_21 -> V_23 -> V_19 ;
F_12 ( V_15 , L_12 , V_2 -> V_4 ) ;
F_15 ( V_24 ) ;
F_9 ( V_15 , F_2 ( V_2 -> V_4 + V_24 ) ) ;
F_15 ( V_25 ) ;
F_15 ( V_26 ) ;
F_15 ( V_27 ) ;
F_15 ( V_28 ) ;
F_15 ( V_29 ) ;
F_15 ( V_30 ) ;
F_11 ( V_15 , V_2 -> V_4 + V_31 ) ;
if ( V_2 -> V_12 )
F_13 ( V_15 , V_2 -> V_12 ) ;
F_10 ( V_15 , L_8 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
F_17 ( V_34 ,
F_6 ( V_34 ) ,
V_33 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_34 ) ; V_9 ++ )
V_34 [ V_9 ] . V_19 = V_2 ;
return F_19 ( V_34 ,
F_6 ( V_34 ) ,
V_33 -> V_35 , V_33 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_36 , int V_37 )
{
unsigned int V_9 ;
F_21 ( L_8 ) ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ )
F_3 ( V_2 , V_36 [ V_9 ] , V_31 + V_9 * 4 ) ;
for ( V_9 = V_37 ; V_9 < V_18 ; V_9 ++ )
F_3 ( V_2 , 0 , V_31 + V_9 * 4 ) ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_5 ;
if ( ! V_2 -> V_41 )
return;
F_21 ( L_8 ) ;
V_5 = F_1 ( V_2 , V_24 ) ;
V_5 &= ~ V_16 ;
F_3 ( V_2 , V_5 , V_24 ) ;
F_3 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , false ) ;
F_23 ( V_2 -> V_42 ) ;
F_23 ( V_2 -> V_43 ) ;
V_2 -> V_41 = false ;
}
static void F_24 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_5 , V_9 , V_44 ;
T_1 V_45 , V_46 ;
T_1 * V_47 , * V_48 ;
T_1 V_49 ;
F_21 ( L_8 ) ;
if ( V_2 -> V_41 )
return;
if ( F_25 ( V_2 -> V_43 ) )
F_26 ( L_13 ) ;
if ( F_25 ( V_2 -> V_42 ) )
F_26 ( L_14 ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_44 ) ) {
F_26 ( L_15 ) ;
return;
}
switch ( V_10 [ V_44 ] . V_50 ) {
case V_51 :
F_26 ( L_16 ) ;
return;
case V_52 :
V_49 = V_53 ;
V_45 = V_54 ;
V_46 = V_55 ;
V_47 = V_56 ;
V_48 = V_57 ;
break;
case V_58 :
V_49 = V_59 ;
V_45 = V_60 ;
V_46 = V_61 ;
V_47 = V_62 ;
V_48 = V_62 ;
break;
case V_63 :
F_26 ( L_17 ) ;
return;
default:
F_26 ( L_18 ) ;
return;
}
F_21 ( L_19 , V_44 ) ;
F_8 ( V_2 , true ) ;
F_3 ( V_2 , V_64 , V_25 ) ;
F_3 ( V_2 , V_65 , V_26 ) ;
F_3 ( V_2 , V_66 , V_27 ) ;
F_3 ( V_2 , V_45 , V_29 ) ;
F_3 ( V_2 , V_46 , V_30 ) ;
for ( V_9 = 0 ; V_9 < V_67 ; V_9 ++ ) {
F_3 ( V_2 , V_47 [ V_9 ] , V_68 + V_9 * 4 ) ;
F_3 ( V_2 , V_48 [ V_9 ] , V_69 + V_9 * 4 ) ;
}
V_5 = 0 ;
V_5 |= ( V_2 -> V_7 . V_70 & V_71 ) ?
0 : V_72 ;
V_5 |= ( V_73 << V_74 ) ;
V_5 |= V_49 ;
F_3 ( V_2 , V_5 , V_24 ) ;
F_20 ( V_2 , V_10 [ V_44 ] . V_36 ,
V_10 [ V_44 ] . V_75 ) ;
V_5 = F_1 ( V_2 , V_24 ) ;
V_5 |= V_16 ;
F_3 ( V_2 , V_5 , V_24 ) ;
V_2 -> V_41 = true ;
}
static void F_27 ( struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_6 * V_76 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_44 ;
int V_77 ;
int V_78 ;
F_21 ( L_8 ) ;
memcpy ( & V_2 -> V_7 , V_7 , sizeof( struct V_6 ) ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_44 ) ) {
F_26 ( L_15 ) ;
return;
}
switch ( V_10 [ V_44 ] . V_50 ) {
case V_52 :
V_77 = V_7 -> clock * 1000 * 2 ;
break;
case V_58 :
V_77 = V_7 -> clock * 1000 * 4 ;
break;
default:
F_26 ( L_15 ) ;
return;
}
V_78 = F_28 ( V_2 -> V_42 , V_77 ) ;
if ( V_78 < 0 )
F_26 ( L_20 ,
V_77 ) ;
V_78 = F_28 ( V_2 -> V_43 , V_7 -> clock * 1000 ) ;
if ( V_78 < 0 )
F_26 ( L_21 ,
V_7 -> clock * 1000 ) ;
}
static void F_29 ( struct V_38 * V_39 )
{
}
static int F_30 ( struct V_79 * V_80 )
{
unsigned int V_9 ;
int V_81 = 0 ;
struct V_82 * V_83
= F_31 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
F_21 ( L_8 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ ) {
struct V_6 * V_7 =
F_32 ( V_2 -> V_84 ,
& V_10 [ V_9 ] . V_7 ) ;
if ( ! V_7 )
continue;
V_7 -> V_85 = F_33 ( V_7 ) ;
if ( V_9 == 0 )
V_7 -> type |= V_86 ;
F_34 ( V_80 , V_7 ) ;
V_81 ++ ;
}
return V_81 ;
}
static int F_35 ( struct V_79 * V_80 ,
struct V_6 * V_7 )
{
int V_87 = V_7 -> clock * 1000 ;
int V_88 = V_87 - V_89 ;
int V_90 = V_87 + V_89 ;
int V_91 ;
int V_8 ;
struct V_82 * V_83
= F_31 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_92 ;
} else {
V_91 = F_36 ( V_2 -> V_43 , V_87 ) ;
F_21 ( L_22 ,
V_87 , V_91 ) ;
if ( ( V_91 < V_88 ) || ( V_91 > V_90 ) ) {
F_21 ( L_23 ,
V_87 ) ;
return V_92 ;
}
}
return V_93 ;
}
static enum V_94
F_37 ( struct V_79 * V_80 , bool V_95 )
{
return V_96 ;
}
static int F_38 ( struct V_79 * V_80 )
{
struct V_82 * V_83
= F_31 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
if ( F_18 ( V_2 , V_2 -> V_84 -> V_97 ) ) {
F_26 ( L_24 ) ;
return - V_98 ;
}
return 0 ;
}
static struct V_99 * F_39 ( struct V_100 * V_101 )
{
struct V_99 * V_102 ;
F_40 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_102 -> V_103 == V_104 )
return V_102 ;
}
return NULL ;
}
static int F_41 ( struct V_105 * V_101 , struct V_105 * V_106 , void * V_19 )
{
struct V_1 * V_2 = F_42 ( V_101 ) ;
struct V_100 * V_84 = V_19 ;
struct V_99 * V_102 ;
struct V_82 * V_80 ;
struct V_79 * V_79 ;
struct V_38 * V_39 ;
int V_107 ;
V_2 -> V_84 = V_84 ;
V_102 = F_39 ( V_84 ) ;
if ( ! V_102 )
return - V_108 ;
V_80 = F_43 ( V_101 , sizeof( * V_80 ) , V_109 ) ;
if ( ! V_80 )
return - V_108 ;
V_80 -> V_2 = V_2 ;
V_39 = F_43 ( V_101 , sizeof( * V_39 ) , V_109 ) ;
if ( ! V_39 )
return - V_108 ;
V_39 -> V_40 = V_2 ;
V_39 -> V_110 = & V_111 ;
F_44 ( V_84 , V_39 ) ;
V_102 -> V_39 = V_39 ;
V_80 -> V_102 = V_102 ;
V_79 = (struct V_79 * ) V_80 ;
V_79 -> V_112 = V_113 ;
F_45 ( V_84 , V_79 ,
& V_114 , V_115 ) ;
F_46 ( V_79 ,
& V_116 ) ;
V_107 = F_47 ( V_79 , V_102 ) ;
if ( V_107 ) {
F_26 ( L_25 ) ;
goto V_117;
}
F_8 ( V_2 , false ) ;
return 0 ;
V_117:
F_48 ( V_39 ) ;
return - V_98 ;
}
static void F_49 ( struct V_105 * V_101 ,
struct V_105 * V_106 , void * V_19 )
{
struct V_1 * V_2 = F_42 ( V_101 ) ;
struct V_100 * V_84 = V_19 ;
F_16 ( V_2 , V_84 -> V_97 ) ;
}
static int F_50 ( struct V_118 * V_119 )
{
struct V_105 * V_101 = & V_119 -> V_101 ;
struct V_1 * V_2 ;
struct V_120 * V_121 ;
F_51 ( L_26 , V_122 ) ;
V_2 = F_43 ( V_101 , sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_108 ;
V_2 -> V_101 = V_119 -> V_101 ;
V_121 = F_52 ( V_119 , V_123 , L_27 ) ;
if ( ! V_121 ) {
F_26 ( L_28 ) ;
return - V_108 ;
}
V_2 -> V_4 = F_53 ( V_101 , V_121 -> V_124 , F_54 ( V_121 ) ) ;
if ( ! V_2 -> V_4 )
return - V_108 ;
V_121 = F_52 ( V_119 , V_123 ,
L_29 ) ;
if ( V_121 ) {
V_2 -> V_12 = F_53 ( V_101 , V_121 -> V_124 ,
F_54 ( V_121 ) ) ;
if ( ! V_2 -> V_12 )
return - V_108 ;
} else {
F_21 ( L_30 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_43 = F_55 ( V_101 , L_31 ) ;
if ( F_56 ( V_2 -> V_43 ) ) {
F_26 ( L_32 ) ;
return F_57 ( V_2 -> V_43 ) ;
}
V_2 -> V_42 = F_55 ( V_101 , L_33 ) ;
if ( F_56 ( V_2 -> V_42 ) ) {
F_26 ( L_34 ) ;
return F_57 ( V_2 -> V_42 ) ;
}
F_58 ( V_119 , V_2 ) ;
return F_59 ( & V_119 -> V_101 , & V_125 ) ;
}
static int F_60 ( struct V_118 * V_119 )
{
F_61 ( & V_119 -> V_101 , & V_125 ) ;
return 0 ;
}
