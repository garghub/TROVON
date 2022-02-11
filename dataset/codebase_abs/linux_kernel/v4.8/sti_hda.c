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
T_1 V_12 ;
if ( V_2 -> V_13 ) {
T_1 V_5 ;
switch ( ( T_1 ) V_2 -> V_13 & V_14 ) {
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
default:
F_9 ( L_1 ) ;
return;
}
V_5 = F_2 ( V_2 -> V_13 ) ;
if ( V_11 )
V_5 &= ~ V_12 ;
else
V_5 |= V_12 ;
F_4 ( V_5 , V_2 -> V_13 ) ;
}
}
static void F_10 ( struct V_19 * V_20 , int V_5 )
{
F_11 ( V_20 , L_2 ) ;
F_11 ( V_20 , V_5 & V_21 ? L_3 : L_4 ) ;
}
static void F_12 ( struct V_19 * V_20 , void T_2 * V_22 )
{
unsigned int V_9 ;
F_11 ( V_20 , L_5 ) ;
F_11 ( V_20 , L_6 ) ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ ) {
if ( V_9 % 8 == 0 )
F_13 ( V_20 , L_7 , V_9 ) ;
F_13 ( V_20 , L_8 , F_2 ( V_22 + V_9 * 4 ) ) ;
}
}
static void F_14 ( struct V_19 * V_20 , void T_2 * V_22 )
{
T_1 V_5 = F_2 ( V_22 ) ;
T_1 V_12 ;
switch ( ( T_1 ) V_22 & V_14 ) {
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
default:
F_15 ( L_9 ) ;
return;
}
F_11 ( V_20 , L_10 ) ;
F_13 ( V_20 , L_11 , L_12 , V_5 ) ;
F_11 ( V_20 , L_13 ) ;
F_11 ( V_20 , V_5 & V_12 ? L_4 : L_3 ) ;
}
static int F_16 ( struct V_19 * V_20 , void * V_24 )
{
struct V_25 * V_26 = V_20 -> V_27 ;
struct V_1 * V_2 = (struct V_1 * ) V_26 -> V_28 -> V_24 ;
F_13 ( V_20 , L_14 , V_2 -> V_4 ) ;
F_17 ( V_29 ) ;
F_10 ( V_20 , F_2 ( V_2 -> V_4 + V_29 ) ) ;
F_17 ( V_30 ) ;
F_17 ( V_31 ) ;
F_17 ( V_32 ) ;
F_17 ( V_33 ) ;
F_17 ( V_34 ) ;
F_17 ( V_35 ) ;
F_12 ( V_20 , V_2 -> V_4 + V_36 ) ;
if ( V_2 -> V_13 )
F_14 ( V_20 , V_2 -> V_13 ) ;
F_11 ( V_20 , L_10 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
F_19 ( V_39 ,
F_6 ( V_39 ) ,
V_38 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_39 ) ; V_9 ++ )
V_39 [ V_9 ] . V_24 = V_2 ;
return F_21 ( V_39 ,
F_6 ( V_39 ) ,
V_38 -> V_40 , V_38 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 * V_41 , int V_42 )
{
unsigned int V_9 ;
F_15 ( L_10 ) ;
for ( V_9 = 0 ; V_9 < V_42 ; V_9 ++ )
F_3 ( V_2 , V_41 [ V_9 ] , V_36 + V_9 * 4 ) ;
for ( V_9 = V_42 ; V_9 < V_23 ; V_9 ++ )
F_3 ( V_2 , 0 , V_36 + V_9 * 4 ) ;
}
static void F_23 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
T_1 V_5 ;
if ( ! V_2 -> V_46 )
return;
F_15 ( L_10 ) ;
V_5 = F_1 ( V_2 , V_29 ) ;
V_5 &= ~ V_21 ;
F_3 ( V_2 , V_5 , V_29 ) ;
F_3 ( V_2 , 0 , V_33 ) ;
F_8 ( V_2 , false ) ;
F_24 ( V_2 -> V_47 ) ;
F_24 ( V_2 -> V_48 ) ;
V_2 -> V_46 = false ;
}
static void F_25 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
T_1 V_5 , V_9 , V_49 ;
T_1 V_50 , V_51 ;
T_1 * V_52 , * V_53 ;
T_1 V_54 ;
F_15 ( L_10 ) ;
if ( V_2 -> V_46 )
return;
if ( F_26 ( V_2 -> V_48 ) )
F_27 ( L_15 ) ;
if ( F_26 ( V_2 -> V_47 ) )
F_27 ( L_16 ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_49 ) ) {
F_27 ( L_17 ) ;
return;
}
switch ( V_10 [ V_49 ] . V_55 ) {
case V_56 :
F_27 ( L_18 ) ;
return;
case V_57 :
V_54 = V_58 ;
V_50 = V_59 ;
V_51 = V_60 ;
V_52 = V_61 ;
V_53 = V_62 ;
break;
case V_63 :
V_54 = V_64 ;
V_50 = V_65 ;
V_51 = V_66 ;
V_52 = V_67 ;
V_53 = V_67 ;
break;
case V_68 :
F_27 ( L_19 ) ;
return;
default:
F_27 ( L_20 ) ;
return;
}
F_15 ( L_21 , V_49 ) ;
F_8 ( V_2 , true ) ;
F_3 ( V_2 , V_69 , V_30 ) ;
F_3 ( V_2 , V_70 , V_31 ) ;
F_3 ( V_2 , V_71 , V_32 ) ;
F_3 ( V_2 , V_50 , V_34 ) ;
F_3 ( V_2 , V_51 , V_35 ) ;
for ( V_9 = 0 ; V_9 < V_72 ; V_9 ++ ) {
F_3 ( V_2 , V_52 [ V_9 ] , V_73 + V_9 * 4 ) ;
F_3 ( V_2 , V_53 [ V_9 ] , V_74 + V_9 * 4 ) ;
}
V_5 = 0 ;
V_5 |= ( V_2 -> V_7 . V_75 & V_76 ) ?
0 : V_77 ;
V_5 |= ( V_78 << V_79 ) ;
V_5 |= V_54 ;
F_3 ( V_2 , V_5 , V_29 ) ;
F_22 ( V_2 , V_10 [ V_49 ] . V_41 ,
V_10 [ V_49 ] . V_80 ) ;
V_5 = F_1 ( V_2 , V_29 ) ;
V_5 |= V_21 ;
F_3 ( V_2 , V_5 , V_29 ) ;
V_2 -> V_46 = true ;
}
static void F_28 ( struct V_43 * V_44 ,
struct V_6 * V_7 ,
struct V_6 * V_81 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
T_1 V_49 ;
int V_82 ;
int V_83 ;
F_15 ( L_10 ) ;
memcpy ( & V_2 -> V_7 , V_7 , sizeof( struct V_6 ) ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_49 ) ) {
F_27 ( L_17 ) ;
return;
}
switch ( V_10 [ V_49 ] . V_55 ) {
case V_57 :
V_82 = V_7 -> clock * 1000 * 2 ;
break;
case V_63 :
V_82 = V_7 -> clock * 1000 * 4 ;
break;
default:
F_27 ( L_17 ) ;
return;
}
V_83 = F_29 ( V_2 -> V_47 , V_82 ) ;
if ( V_83 < 0 )
F_27 ( L_22 ,
V_82 ) ;
V_83 = F_29 ( V_2 -> V_48 , V_7 -> clock * 1000 ) ;
if ( V_83 < 0 )
F_27 ( L_23 ,
V_7 -> clock * 1000 ) ;
}
static void F_30 ( struct V_43 * V_44 )
{
}
static int F_31 ( struct V_84 * V_85 )
{
unsigned int V_9 ;
int V_86 = 0 ;
struct V_87 * V_88
= F_32 ( V_85 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
F_15 ( L_10 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ ) {
struct V_6 * V_7 =
F_33 ( V_2 -> V_89 ,
& V_10 [ V_9 ] . V_7 ) ;
if ( ! V_7 )
continue;
V_7 -> V_90 = F_34 ( V_7 ) ;
if ( V_9 == 0 )
V_7 -> type |= V_91 ;
F_35 ( V_85 , V_7 ) ;
V_86 ++ ;
}
return V_86 ;
}
static int F_36 ( struct V_84 * V_85 ,
struct V_6 * V_7 )
{
int V_92 = V_7 -> clock * 1000 ;
int V_93 = V_92 - V_94 ;
int V_95 = V_92 + V_94 ;
int V_96 ;
int V_8 ;
struct V_87 * V_88
= F_32 ( V_85 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_97 ;
} else {
V_96 = F_37 ( V_2 -> V_48 , V_92 ) ;
F_15 ( L_24 ,
V_92 , V_96 ) ;
if ( ( V_96 < V_93 ) || ( V_96 > V_95 ) ) {
F_15 ( L_25 ,
V_92 ) ;
return V_97 ;
}
}
return V_98 ;
}
static enum V_99
F_38 ( struct V_84 * V_85 , bool V_100 )
{
return V_101 ;
}
static int F_39 ( struct V_84 * V_85 )
{
struct V_87 * V_88
= F_32 ( V_85 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
if ( F_20 ( V_2 , V_2 -> V_89 -> V_102 ) ) {
F_27 ( L_26 ) ;
return - V_103 ;
}
return 0 ;
}
static struct V_104 * F_40 ( struct V_105 * V_106 )
{
struct V_104 * V_107 ;
F_41 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_107 -> V_108 == V_109 )
return V_107 ;
}
return NULL ;
}
static int F_42 ( struct V_110 * V_106 , struct V_110 * V_111 , void * V_24 )
{
struct V_1 * V_2 = F_43 ( V_106 ) ;
struct V_105 * V_89 = V_24 ;
struct V_104 * V_107 ;
struct V_87 * V_85 ;
struct V_84 * V_84 ;
struct V_43 * V_44 ;
int V_112 ;
V_2 -> V_89 = V_89 ;
V_107 = F_40 ( V_89 ) ;
if ( ! V_107 )
return - V_113 ;
V_85 = F_44 ( V_106 , sizeof( * V_85 ) , V_114 ) ;
if ( ! V_85 )
return - V_113 ;
V_85 -> V_2 = V_2 ;
V_44 = F_44 ( V_106 , sizeof( * V_44 ) , V_114 ) ;
if ( ! V_44 )
return - V_113 ;
V_44 -> V_45 = V_2 ;
V_44 -> V_115 = & V_116 ;
F_45 ( V_89 , V_44 ) ;
V_107 -> V_44 = V_44 ;
V_85 -> V_107 = V_107 ;
V_84 = (struct V_84 * ) V_85 ;
V_84 -> V_117 = V_118 ;
F_46 ( V_89 , V_84 ,
& V_119 , V_120 ) ;
F_47 ( V_84 ,
& V_121 ) ;
V_112 = F_48 ( V_84 , V_107 ) ;
if ( V_112 ) {
F_27 ( L_27 ) ;
goto V_122;
}
F_8 ( V_2 , false ) ;
return 0 ;
V_122:
F_49 ( V_44 ) ;
return - V_103 ;
}
static void F_50 ( struct V_110 * V_106 ,
struct V_110 * V_111 , void * V_24 )
{
struct V_1 * V_2 = F_43 ( V_106 ) ;
struct V_105 * V_89 = V_24 ;
F_18 ( V_2 , V_89 -> V_102 ) ;
}
static int F_51 ( struct V_123 * V_124 )
{
struct V_110 * V_106 = & V_124 -> V_106 ;
struct V_1 * V_2 ;
struct V_125 * V_126 ;
F_9 ( L_28 , V_127 ) ;
V_2 = F_44 ( V_106 , sizeof( * V_2 ) , V_114 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_106 = V_124 -> V_106 ;
V_126 = F_52 ( V_124 , V_128 , L_29 ) ;
if ( ! V_126 ) {
F_27 ( L_30 ) ;
return - V_113 ;
}
V_2 -> V_4 = F_53 ( V_106 , V_126 -> V_129 , F_54 ( V_126 ) ) ;
if ( ! V_2 -> V_4 )
return - V_113 ;
V_126 = F_52 ( V_124 , V_128 ,
L_31 ) ;
if ( V_126 ) {
V_2 -> V_13 = F_53 ( V_106 , V_126 -> V_129 ,
F_54 ( V_126 ) ) ;
if ( ! V_2 -> V_13 )
return - V_113 ;
} else {
F_15 ( L_32 ) ;
V_2 -> V_13 = NULL ;
}
V_2 -> V_48 = F_55 ( V_106 , L_33 ) ;
if ( F_56 ( V_2 -> V_48 ) ) {
F_27 ( L_34 ) ;
return F_57 ( V_2 -> V_48 ) ;
}
V_2 -> V_47 = F_55 ( V_106 , L_35 ) ;
if ( F_56 ( V_2 -> V_47 ) ) {
F_27 ( L_36 ) ;
return F_57 ( V_2 -> V_47 ) ;
}
F_58 ( V_124 , V_2 ) ;
return F_59 ( & V_124 -> V_106 , & V_130 ) ;
}
static int F_60 ( struct V_123 * V_124 )
{
F_61 ( & V_124 -> V_106 , & V_130 ) ;
return 0 ;
}
