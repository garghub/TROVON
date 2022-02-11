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
static void F_10 ( struct V_1 * V_2 , T_1 * V_19 , int V_20 )
{
unsigned int V_9 ;
F_11 ( L_2 ) ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ )
F_3 ( V_2 , V_19 [ V_9 ] , V_21 + V_9 * 4 ) ;
for ( V_9 = V_20 ; V_9 < V_22 ; V_9 ++ )
F_3 ( V_2 , 0 , V_21 + V_9 * 4 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
T_1 V_5 ;
if ( ! V_2 -> V_26 )
return;
F_11 ( L_2 ) ;
V_5 = F_1 ( V_2 , V_27 ) ;
V_5 &= ~ V_28 ;
F_3 ( V_2 , V_5 , V_27 ) ;
F_3 ( V_2 , 0 , V_29 ) ;
F_8 ( V_2 , false ) ;
F_13 ( V_2 -> V_30 ) ;
F_13 ( V_2 -> V_31 ) ;
V_2 -> V_26 = false ;
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
T_1 V_5 , V_9 , V_32 ;
T_1 V_33 , V_34 ;
T_1 * V_35 , * V_36 ;
T_1 V_37 ;
F_11 ( L_2 ) ;
if ( V_2 -> V_26 )
return;
if ( F_15 ( V_2 -> V_31 ) )
F_16 ( L_3 ) ;
if ( F_15 ( V_2 -> V_30 ) )
F_16 ( L_4 ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_32 ) ) {
F_16 ( L_5 ) ;
return;
}
switch ( V_10 [ V_32 ] . V_38 ) {
case V_39 :
F_16 ( L_6 ) ;
return;
case V_40 :
V_37 = V_41 ;
V_33 = V_42 ;
V_34 = V_43 ;
V_35 = V_44 ;
V_36 = V_45 ;
break;
case V_46 :
V_37 = V_47 ;
V_33 = V_48 ;
V_34 = V_49 ;
V_35 = V_50 ;
V_36 = V_50 ;
break;
case V_51 :
F_16 ( L_7 ) ;
return;
default:
F_16 ( L_8 ) ;
return;
}
F_11 ( L_9 , V_32 ) ;
F_8 ( V_2 , true ) ;
F_3 ( V_2 , V_52 , V_53 ) ;
F_3 ( V_2 , V_54 , V_55 ) ;
F_3 ( V_2 , V_56 , V_57 ) ;
F_3 ( V_2 , V_33 , V_58 ) ;
F_3 ( V_2 , V_34 , V_59 ) ;
for ( V_9 = 0 ; V_9 < V_60 ; V_9 ++ ) {
F_3 ( V_2 , V_35 [ V_9 ] , V_61 + V_9 * 4 ) ;
F_3 ( V_2 , V_36 [ V_9 ] , V_62 + V_9 * 4 ) ;
}
V_5 = 0 ;
V_5 |= ( V_2 -> V_7 . V_63 & V_64 ) ?
0 : V_65 ;
V_5 |= ( V_66 << V_67 ) ;
V_5 |= V_37 ;
F_3 ( V_2 , V_5 , V_27 ) ;
F_10 ( V_2 , V_10 [ V_32 ] . V_19 ,
V_10 [ V_32 ] . V_68 ) ;
V_5 = F_1 ( V_2 , V_27 ) ;
V_5 |= V_28 ;
F_3 ( V_2 , V_5 , V_27 ) ;
V_2 -> V_26 = true ;
}
static void F_17 ( struct V_23 * V_24 ,
struct V_6 * V_7 ,
struct V_6 * V_69 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
T_1 V_32 ;
int V_70 ;
int V_71 ;
F_11 ( L_2 ) ;
memcpy ( & V_2 -> V_7 , V_7 , sizeof( struct V_6 ) ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_32 ) ) {
F_16 ( L_5 ) ;
return;
}
switch ( V_10 [ V_32 ] . V_38 ) {
case V_40 :
V_70 = V_7 -> clock * 1000 * 2 ;
break;
case V_46 :
V_70 = V_7 -> clock * 1000 * 4 ;
break;
default:
F_16 ( L_5 ) ;
return;
}
V_71 = F_18 ( V_2 -> V_30 , V_70 ) ;
if ( V_71 < 0 )
F_16 ( L_10 ,
V_70 ) ;
V_71 = F_18 ( V_2 -> V_31 , V_7 -> clock * 1000 ) ;
if ( V_71 < 0 )
F_16 ( L_11 ,
V_7 -> clock * 1000 ) ;
}
static void F_19 ( struct V_23 * V_24 )
{
}
static int F_20 ( struct V_72 * V_73 )
{
unsigned int V_9 ;
int V_74 = 0 ;
struct V_75 * V_76
= F_21 ( V_73 ) ;
struct V_1 * V_2 = V_76 -> V_2 ;
F_11 ( L_2 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ ) {
struct V_6 * V_7 =
F_22 ( V_2 -> V_77 ,
& V_10 [ V_9 ] . V_7 ) ;
if ( ! V_7 )
continue;
V_7 -> V_78 = F_23 ( V_7 ) ;
if ( V_9 == 0 )
V_7 -> type |= V_79 ;
F_24 ( V_73 , V_7 ) ;
V_74 ++ ;
}
F_25 ( & V_73 -> V_80 ) ;
return V_74 ;
}
static int F_26 ( struct V_72 * V_73 ,
struct V_6 * V_7 )
{
int V_81 = V_7 -> clock * 1000 ;
int V_82 = V_81 - V_83 ;
int V_84 = V_81 + V_83 ;
int V_85 ;
int V_8 ;
struct V_75 * V_76
= F_21 ( V_73 ) ;
struct V_1 * V_2 = V_76 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_86 ;
} else {
V_85 = F_27 ( V_2 -> V_31 , V_81 ) ;
F_11 ( L_12 ,
V_81 , V_85 ) ;
if ( ( V_85 < V_82 ) || ( V_85 > V_84 ) ) {
F_11 ( L_13 ,
V_81 ) ;
return V_86 ;
}
}
return V_87 ;
}
struct V_88 * F_28 ( struct V_72 * V_73 )
{
struct V_75 * V_76
= F_21 ( V_73 ) ;
return V_76 -> V_89 ;
}
static enum V_90
F_29 ( struct V_72 * V_73 , bool V_91 )
{
return V_92 ;
}
static void F_30 ( struct V_72 * V_73 )
{
struct V_75 * V_76
= F_21 ( V_73 ) ;
F_31 ( V_73 ) ;
F_32 ( V_73 ) ;
F_33 ( V_76 ) ;
}
static struct V_88 * F_34 ( struct V_93 * V_94 )
{
struct V_88 * V_89 ;
F_35 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_89 -> V_95 == V_96 )
return V_89 ;
}
return NULL ;
}
static int F_36 ( struct V_97 * V_94 , struct V_97 * V_98 , void * V_99 )
{
struct V_1 * V_2 = F_37 ( V_94 ) ;
struct V_93 * V_77 = V_99 ;
struct V_88 * V_89 ;
struct V_75 * V_73 ;
struct V_72 * V_72 ;
struct V_23 * V_24 ;
int V_100 ;
V_2 -> V_77 = V_77 ;
V_89 = F_34 ( V_77 ) ;
if ( ! V_89 )
return - V_101 ;
V_73 = F_38 ( V_94 , sizeof( * V_73 ) , V_102 ) ;
if ( ! V_73 )
return - V_101 ;
V_73 -> V_2 = V_2 ;
V_24 = F_38 ( V_94 , sizeof( * V_24 ) , V_102 ) ;
if ( ! V_24 )
return - V_101 ;
V_24 -> V_25 = V_2 ;
V_24 -> V_103 = & V_104 ;
F_39 ( V_77 , V_24 ) ;
V_89 -> V_24 = V_24 ;
V_73 -> V_89 = V_89 ;
V_72 = (struct V_72 * ) V_73 ;
V_72 -> V_105 = V_106 ;
F_40 ( V_77 , V_72 ,
& V_107 , V_108 ) ;
F_41 ( V_72 ,
& V_109 ) ;
V_100 = F_42 ( V_72 ) ;
if ( V_100 )
goto V_110;
V_100 = F_43 ( V_72 , V_89 ) ;
if ( V_100 ) {
F_16 ( L_14 ) ;
goto V_111;
}
return 0 ;
V_111:
F_31 ( V_72 ) ;
V_110:
F_32 ( V_72 ) ;
return - V_112 ;
}
static void F_44 ( struct V_97 * V_94 ,
struct V_97 * V_98 , void * V_99 )
{
}
static int F_45 ( struct V_113 * V_114 )
{
struct V_97 * V_94 = & V_114 -> V_94 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
F_9 ( L_15 , V_117 ) ;
V_2 = F_38 ( V_94 , sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_94 = V_114 -> V_94 ;
V_116 = F_46 ( V_114 , V_118 , L_16 ) ;
if ( ! V_116 ) {
F_16 ( L_17 ) ;
return - V_101 ;
}
V_2 -> V_4 = F_47 ( V_94 , V_116 -> V_119 , F_48 ( V_116 ) ) ;
if ( ! V_2 -> V_4 )
return - V_101 ;
V_116 = F_46 ( V_114 , V_118 ,
L_18 ) ;
if ( V_116 ) {
V_2 -> V_13 = F_47 ( V_94 , V_116 -> V_119 ,
F_48 ( V_116 ) ) ;
if ( ! V_2 -> V_13 )
return - V_101 ;
} else {
F_11 ( L_19 ) ;
V_2 -> V_13 = NULL ;
}
V_2 -> V_31 = F_49 ( V_94 , L_20 ) ;
if ( F_50 ( V_2 -> V_31 ) ) {
F_16 ( L_21 ) ;
return F_51 ( V_2 -> V_31 ) ;
}
V_2 -> V_30 = F_49 ( V_94 , L_22 ) ;
if ( F_50 ( V_2 -> V_30 ) ) {
F_16 ( L_23 ) ;
return F_51 ( V_2 -> V_30 ) ;
}
F_52 ( V_114 , V_2 ) ;
return F_53 ( & V_114 -> V_94 , & V_120 ) ;
}
static int F_54 ( struct V_113 * V_114 )
{
F_55 ( & V_114 -> V_94 , & V_120 ) ;
return 0 ;
}
