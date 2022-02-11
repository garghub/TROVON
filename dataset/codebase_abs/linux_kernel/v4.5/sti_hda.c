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
return V_74 ;
}
static int F_25 ( struct V_72 * V_73 ,
struct V_6 * V_7 )
{
int V_80 = V_7 -> clock * 1000 ;
int V_81 = V_80 - V_82 ;
int V_83 = V_80 + V_82 ;
int V_84 ;
int V_8 ;
struct V_75 * V_76
= F_21 ( V_73 ) ;
struct V_1 * V_2 = V_76 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_85 ;
} else {
V_84 = F_26 ( V_2 -> V_31 , V_80 ) ;
F_11 ( L_12 ,
V_80 , V_84 ) ;
if ( ( V_84 < V_81 ) || ( V_84 > V_83 ) ) {
F_11 ( L_13 ,
V_80 ) ;
return V_85 ;
}
}
return V_86 ;
}
struct V_87 * F_27 ( struct V_72 * V_73 )
{
struct V_75 * V_76
= F_21 ( V_73 ) ;
return V_76 -> V_88 ;
}
static enum V_89
F_28 ( struct V_72 * V_73 , bool V_90 )
{
return V_91 ;
}
static void F_29 ( struct V_72 * V_73 )
{
struct V_75 * V_76
= F_21 ( V_73 ) ;
F_30 ( V_73 ) ;
F_31 ( V_73 ) ;
F_32 ( V_76 ) ;
}
static struct V_87 * F_33 ( struct V_92 * V_93 )
{
struct V_87 * V_88 ;
F_34 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_88 -> V_94 == V_95 )
return V_88 ;
}
return NULL ;
}
static int F_35 ( struct V_96 * V_93 , struct V_96 * V_97 , void * V_98 )
{
struct V_1 * V_2 = F_36 ( V_93 ) ;
struct V_92 * V_77 = V_98 ;
struct V_87 * V_88 ;
struct V_75 * V_73 ;
struct V_72 * V_72 ;
struct V_23 * V_24 ;
int V_99 ;
V_2 -> V_77 = V_77 ;
V_88 = F_33 ( V_77 ) ;
if ( ! V_88 )
return - V_100 ;
V_73 = F_37 ( V_93 , sizeof( * V_73 ) , V_101 ) ;
if ( ! V_73 )
return - V_100 ;
V_73 -> V_2 = V_2 ;
V_24 = F_37 ( V_93 , sizeof( * V_24 ) , V_101 ) ;
if ( ! V_24 )
return - V_100 ;
V_24 -> V_25 = V_2 ;
V_24 -> V_102 = & V_103 ;
F_38 ( V_77 , V_24 ) ;
V_88 -> V_24 = V_24 ;
V_73 -> V_88 = V_88 ;
V_72 = (struct V_72 * ) V_73 ;
V_72 -> V_104 = V_105 ;
F_39 ( V_77 , V_72 ,
& V_106 , V_107 ) ;
F_40 ( V_72 ,
& V_108 ) ;
V_99 = F_41 ( V_72 ) ;
if ( V_99 )
goto V_109;
V_99 = F_42 ( V_72 , V_88 ) ;
if ( V_99 ) {
F_16 ( L_14 ) ;
goto V_110;
}
return 0 ;
V_110:
F_30 ( V_72 ) ;
V_109:
F_31 ( V_72 ) ;
return - V_111 ;
}
static void F_43 ( struct V_96 * V_93 ,
struct V_96 * V_97 , void * V_98 )
{
}
static int F_44 ( struct V_112 * V_113 )
{
struct V_96 * V_93 = & V_113 -> V_93 ;
struct V_1 * V_2 ;
struct V_114 * V_115 ;
F_9 ( L_15 , V_116 ) ;
V_2 = F_37 ( V_93 , sizeof( * V_2 ) , V_101 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_93 = V_113 -> V_93 ;
V_115 = F_45 ( V_113 , V_117 , L_16 ) ;
if ( ! V_115 ) {
F_16 ( L_17 ) ;
return - V_100 ;
}
V_2 -> V_4 = F_46 ( V_93 , V_115 -> V_118 , F_47 ( V_115 ) ) ;
if ( ! V_2 -> V_4 )
return - V_100 ;
V_115 = F_45 ( V_113 , V_117 ,
L_18 ) ;
if ( V_115 ) {
V_2 -> V_13 = F_46 ( V_93 , V_115 -> V_118 ,
F_47 ( V_115 ) ) ;
if ( ! V_2 -> V_13 )
return - V_100 ;
} else {
F_11 ( L_19 ) ;
V_2 -> V_13 = NULL ;
}
V_2 -> V_31 = F_48 ( V_93 , L_20 ) ;
if ( F_49 ( V_2 -> V_31 ) ) {
F_16 ( L_21 ) ;
return F_50 ( V_2 -> V_31 ) ;
}
V_2 -> V_30 = F_48 ( V_93 , L_22 ) ;
if ( F_49 ( V_2 -> V_30 ) ) {
F_16 ( L_23 ) ;
return F_50 ( V_2 -> V_30 ) ;
}
F_51 ( V_113 , V_2 ) ;
return F_52 ( & V_113 -> V_93 , & V_119 ) ;
}
static int F_53 ( struct V_112 * V_113 )
{
F_54 ( & V_113 -> V_93 , & V_119 ) ;
return 0 ;
}
