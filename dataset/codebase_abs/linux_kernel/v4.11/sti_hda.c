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
static int F_16 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_34 ) ; V_9 ++ )
V_34 [ V_9 ] . V_19 = V_2 ;
return F_17 ( V_34 ,
F_6 ( V_34 ) ,
V_33 -> V_35 , V_33 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_36 , int V_37 )
{
unsigned int V_9 ;
F_19 ( L_8 ) ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ )
F_3 ( V_2 , V_36 [ V_9 ] , V_31 + V_9 * 4 ) ;
for ( V_9 = V_37 ; V_9 < V_18 ; V_9 ++ )
F_3 ( V_2 , 0 , V_31 + V_9 * 4 ) ;
}
static void F_20 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_5 ;
if ( ! V_2 -> V_41 )
return;
F_19 ( L_8 ) ;
V_5 = F_1 ( V_2 , V_24 ) ;
V_5 &= ~ V_16 ;
F_3 ( V_2 , V_5 , V_24 ) ;
F_3 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , false ) ;
F_21 ( V_2 -> V_42 ) ;
F_21 ( V_2 -> V_43 ) ;
V_2 -> V_41 = false ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_5 , V_9 , V_44 ;
T_1 V_45 , V_46 ;
T_1 * V_47 , * V_48 ;
T_1 V_49 ;
F_19 ( L_8 ) ;
if ( V_2 -> V_41 )
return;
if ( F_23 ( V_2 -> V_43 ) )
F_24 ( L_13 ) ;
if ( F_23 ( V_2 -> V_42 ) )
F_24 ( L_14 ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_44 ) ) {
F_24 ( L_15 ) ;
return;
}
switch ( V_10 [ V_44 ] . V_50 ) {
case V_51 :
F_24 ( L_16 ) ;
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
F_24 ( L_17 ) ;
return;
default:
F_24 ( L_18 ) ;
return;
}
F_19 ( L_19 , V_44 ) ;
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
F_18 ( V_2 , V_10 [ V_44 ] . V_36 ,
V_10 [ V_44 ] . V_75 ) ;
V_5 = F_1 ( V_2 , V_24 ) ;
V_5 |= V_16 ;
F_3 ( V_2 , V_5 , V_24 ) ;
V_2 -> V_41 = true ;
}
static void F_25 ( struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_6 * V_76 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_44 ;
int V_77 ;
int V_78 ;
F_19 ( L_8 ) ;
memcpy ( & V_2 -> V_7 , V_7 , sizeof( struct V_6 ) ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_44 ) ) {
F_24 ( L_15 ) ;
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
F_24 ( L_15 ) ;
return;
}
V_78 = F_26 ( V_2 -> V_42 , V_77 ) ;
if ( V_78 < 0 )
F_24 ( L_20 ,
V_77 ) ;
V_78 = F_26 ( V_2 -> V_43 , V_7 -> clock * 1000 ) ;
if ( V_78 < 0 )
F_24 ( L_21 ,
V_7 -> clock * 1000 ) ;
}
static void F_27 ( struct V_38 * V_39 )
{
}
static int F_28 ( struct V_79 * V_80 )
{
unsigned int V_9 ;
int V_81 = 0 ;
struct V_82 * V_83
= F_29 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
F_19 ( L_8 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ ) {
struct V_6 * V_7 =
F_30 ( V_2 -> V_84 ,
& V_10 [ V_9 ] . V_7 ) ;
if ( ! V_7 )
continue;
V_7 -> V_85 = F_31 ( V_7 ) ;
if ( V_9 == 0 )
V_7 -> type |= V_86 ;
F_32 ( V_80 , V_7 ) ;
V_81 ++ ;
}
return V_81 ;
}
static int F_33 ( struct V_79 * V_80 ,
struct V_6 * V_7 )
{
int V_87 = V_7 -> clock * 1000 ;
int V_88 = V_87 - V_89 ;
int V_90 = V_87 + V_89 ;
int V_91 ;
int V_8 ;
struct V_82 * V_83
= F_29 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_92 ;
} else {
V_91 = F_34 ( V_2 -> V_43 , V_87 ) ;
F_19 ( L_22 ,
V_87 , V_91 ) ;
if ( ( V_91 < V_88 ) || ( V_91 > V_90 ) ) {
F_19 ( L_23 ,
V_87 ) ;
return V_92 ;
}
}
return V_93 ;
}
static int F_35 ( struct V_79 * V_80 )
{
struct V_82 * V_83
= F_29 ( V_80 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
if ( F_16 ( V_2 , V_2 -> V_84 -> V_94 ) ) {
F_24 ( L_24 ) ;
return - V_95 ;
}
return 0 ;
}
static struct V_96 * F_36 ( struct V_97 * V_98 )
{
struct V_96 * V_99 ;
F_37 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_99 -> V_100 == V_101 )
return V_99 ;
}
return NULL ;
}
static int F_38 ( struct V_102 * V_98 , struct V_102 * V_103 , void * V_19 )
{
struct V_1 * V_2 = F_39 ( V_98 ) ;
struct V_97 * V_84 = V_19 ;
struct V_96 * V_99 ;
struct V_82 * V_80 ;
struct V_79 * V_79 ;
struct V_38 * V_39 ;
int V_104 ;
V_2 -> V_84 = V_84 ;
V_99 = F_36 ( V_84 ) ;
if ( ! V_99 )
return - V_105 ;
V_80 = F_40 ( V_98 , sizeof( * V_80 ) , V_106 ) ;
if ( ! V_80 )
return - V_105 ;
V_80 -> V_2 = V_2 ;
V_39 = F_40 ( V_98 , sizeof( * V_39 ) , V_106 ) ;
if ( ! V_39 )
return - V_105 ;
V_39 -> V_40 = V_2 ;
V_39 -> V_107 = & V_108 ;
F_41 ( V_99 , V_39 , NULL ) ;
V_80 -> V_99 = V_99 ;
V_79 = (struct V_79 * ) V_80 ;
V_79 -> V_109 = V_110 ;
F_42 ( V_84 , V_79 ,
& V_111 , V_112 ) ;
F_43 ( V_79 ,
& V_113 ) ;
V_104 = F_44 ( V_79 , V_99 ) ;
if ( V_104 ) {
F_24 ( L_25 ) ;
goto V_114;
}
F_8 ( V_2 , false ) ;
return 0 ;
V_114:
F_45 ( V_39 ) ;
return - V_95 ;
}
static void F_46 ( struct V_102 * V_98 ,
struct V_102 * V_103 , void * V_19 )
{
}
static int F_47 ( struct V_115 * V_116 )
{
struct V_102 * V_98 = & V_116 -> V_98 ;
struct V_1 * V_2 ;
struct V_117 * V_118 ;
F_48 ( L_26 , V_119 ) ;
V_2 = F_40 ( V_98 , sizeof( * V_2 ) , V_106 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_98 = V_116 -> V_98 ;
V_118 = F_49 ( V_116 , V_120 , L_27 ) ;
if ( ! V_118 ) {
F_24 ( L_28 ) ;
return - V_105 ;
}
V_2 -> V_4 = F_50 ( V_98 , V_118 -> V_121 , F_51 ( V_118 ) ) ;
if ( ! V_2 -> V_4 )
return - V_105 ;
V_118 = F_49 ( V_116 , V_120 ,
L_29 ) ;
if ( V_118 ) {
V_2 -> V_12 = F_50 ( V_98 , V_118 -> V_121 ,
F_51 ( V_118 ) ) ;
if ( ! V_2 -> V_12 )
return - V_105 ;
} else {
F_19 ( L_30 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_43 = F_52 ( V_98 , L_31 ) ;
if ( F_53 ( V_2 -> V_43 ) ) {
F_24 ( L_32 ) ;
return F_54 ( V_2 -> V_43 ) ;
}
V_2 -> V_42 = F_52 ( V_98 , L_33 ) ;
if ( F_53 ( V_2 -> V_42 ) ) {
F_24 ( L_34 ) ;
return F_54 ( V_2 -> V_42 ) ;
}
F_55 ( V_116 , V_2 ) ;
return F_56 ( & V_116 -> V_98 , & V_122 ) ;
}
static int F_57 ( struct V_115 * V_116 )
{
F_58 ( & V_116 -> V_98 , & V_122 ) ;
return 0 ;
}
