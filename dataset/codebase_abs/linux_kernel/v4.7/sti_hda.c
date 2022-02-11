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
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
int V_32 ;
V_32 = F_17 ( & V_30 -> V_33 ) ;
if ( V_32 )
return V_32 ;
F_13 ( V_20 , L_14 , V_2 -> V_4 ) ;
F_18 ( V_34 ) ;
F_10 ( V_20 , F_2 ( V_2 -> V_4 + V_34 ) ) ;
F_18 ( V_35 ) ;
F_18 ( V_36 ) ;
F_18 ( V_37 ) ;
F_18 ( V_38 ) ;
F_18 ( V_39 ) ;
F_18 ( V_40 ) ;
F_12 ( V_20 , V_2 -> V_4 + V_41 ) ;
if ( V_2 -> V_13 )
F_14 ( V_20 , V_2 -> V_13 ) ;
F_11 ( V_20 , L_10 ) ;
F_19 ( & V_30 -> V_33 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_42 * V_31 )
{
F_21 ( V_43 ,
F_6 ( V_43 ) ,
V_31 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_42 * V_31 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_43 ) ; V_9 ++ )
V_43 [ V_9 ] . V_24 = V_2 ;
return F_23 ( V_43 ,
F_6 ( V_43 ) ,
V_31 -> V_44 , V_31 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_45 , int V_46 )
{
unsigned int V_9 ;
F_15 ( L_10 ) ;
for ( V_9 = 0 ; V_9 < V_46 ; V_9 ++ )
F_3 ( V_2 , V_45 [ V_9 ] , V_41 + V_9 * 4 ) ;
for ( V_9 = V_46 ; V_9 < V_23 ; V_9 ++ )
F_3 ( V_2 , 0 , V_41 + V_9 * 4 ) ;
}
static void F_25 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
T_1 V_5 ;
if ( ! V_2 -> V_50 )
return;
F_15 ( L_10 ) ;
V_5 = F_1 ( V_2 , V_34 ) ;
V_5 &= ~ V_21 ;
F_3 ( V_2 , V_5 , V_34 ) ;
F_3 ( V_2 , 0 , V_38 ) ;
F_8 ( V_2 , false ) ;
F_26 ( V_2 -> V_51 ) ;
F_26 ( V_2 -> V_52 ) ;
V_2 -> V_50 = false ;
}
static void F_27 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
T_1 V_5 , V_9 , V_53 ;
T_1 V_54 , V_55 ;
T_1 * V_56 , * V_57 ;
T_1 V_58 ;
F_15 ( L_10 ) ;
if ( V_2 -> V_50 )
return;
if ( F_28 ( V_2 -> V_52 ) )
F_29 ( L_15 ) ;
if ( F_28 ( V_2 -> V_51 ) )
F_29 ( L_16 ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_53 ) ) {
F_29 ( L_17 ) ;
return;
}
switch ( V_10 [ V_53 ] . V_59 ) {
case V_60 :
F_29 ( L_18 ) ;
return;
case V_61 :
V_58 = V_62 ;
V_54 = V_63 ;
V_55 = V_64 ;
V_56 = V_65 ;
V_57 = V_66 ;
break;
case V_67 :
V_58 = V_68 ;
V_54 = V_69 ;
V_55 = V_70 ;
V_56 = V_71 ;
V_57 = V_71 ;
break;
case V_72 :
F_29 ( L_19 ) ;
return;
default:
F_29 ( L_20 ) ;
return;
}
F_15 ( L_21 , V_53 ) ;
F_8 ( V_2 , true ) ;
F_3 ( V_2 , V_73 , V_35 ) ;
F_3 ( V_2 , V_74 , V_36 ) ;
F_3 ( V_2 , V_75 , V_37 ) ;
F_3 ( V_2 , V_54 , V_39 ) ;
F_3 ( V_2 , V_55 , V_40 ) ;
for ( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
F_3 ( V_2 , V_56 [ V_9 ] , V_77 + V_9 * 4 ) ;
F_3 ( V_2 , V_57 [ V_9 ] , V_78 + V_9 * 4 ) ;
}
V_5 = 0 ;
V_5 |= ( V_2 -> V_7 . V_79 & V_80 ) ?
0 : V_81 ;
V_5 |= ( V_82 << V_83 ) ;
V_5 |= V_58 ;
F_3 ( V_2 , V_5 , V_34 ) ;
F_24 ( V_2 , V_10 [ V_53 ] . V_45 ,
V_10 [ V_53 ] . V_84 ) ;
V_5 = F_1 ( V_2 , V_34 ) ;
V_5 |= V_21 ;
F_3 ( V_2 , V_5 , V_34 ) ;
V_2 -> V_50 = true ;
}
static void F_30 ( struct V_47 * V_48 ,
struct V_6 * V_7 ,
struct V_6 * V_85 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
T_1 V_53 ;
int V_86 ;
int V_32 ;
F_15 ( L_10 ) ;
memcpy ( & V_2 -> V_7 , V_7 , sizeof( struct V_6 ) ) ;
if ( ! F_5 ( V_2 -> V_7 , & V_53 ) ) {
F_29 ( L_17 ) ;
return;
}
switch ( V_10 [ V_53 ] . V_59 ) {
case V_61 :
V_86 = V_7 -> clock * 1000 * 2 ;
break;
case V_67 :
V_86 = V_7 -> clock * 1000 * 4 ;
break;
default:
F_29 ( L_17 ) ;
return;
}
V_32 = F_31 ( V_2 -> V_51 , V_86 ) ;
if ( V_32 < 0 )
F_29 ( L_22 ,
V_86 ) ;
V_32 = F_31 ( V_2 -> V_52 , V_7 -> clock * 1000 ) ;
if ( V_32 < 0 )
F_29 ( L_23 ,
V_7 -> clock * 1000 ) ;
}
static void F_32 ( struct V_47 * V_48 )
{
}
static int F_33 ( struct V_87 * V_88 )
{
unsigned int V_9 ;
int V_89 = 0 ;
struct V_90 * V_91
= F_34 ( V_88 ) ;
struct V_1 * V_2 = V_91 -> V_2 ;
F_15 ( L_10 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_10 ) ; V_9 ++ ) {
struct V_6 * V_7 =
F_35 ( V_2 -> V_92 ,
& V_10 [ V_9 ] . V_7 ) ;
if ( ! V_7 )
continue;
V_7 -> V_93 = F_36 ( V_7 ) ;
if ( V_9 == 0 )
V_7 -> type |= V_94 ;
F_37 ( V_88 , V_7 ) ;
V_89 ++ ;
}
return V_89 ;
}
static int F_38 ( struct V_87 * V_88 ,
struct V_6 * V_7 )
{
int V_95 = V_7 -> clock * 1000 ;
int V_96 = V_95 - V_97 ;
int V_98 = V_95 + V_97 ;
int V_99 ;
int V_8 ;
struct V_90 * V_91
= F_34 ( V_88 ) ;
struct V_1 * V_2 = V_91 -> V_2 ;
if ( ! F_5 ( * V_7 , & V_8 ) ) {
return V_100 ;
} else {
V_99 = F_39 ( V_2 -> V_52 , V_95 ) ;
F_15 ( L_24 ,
V_95 , V_99 ) ;
if ( ( V_99 < V_96 ) || ( V_99 > V_98 ) ) {
F_15 ( L_25 ,
V_95 ) ;
return V_100 ;
}
}
return V_101 ;
}
struct V_102 * F_40 ( struct V_87 * V_88 )
{
struct V_90 * V_91
= F_34 ( V_88 ) ;
return V_91 -> V_103 ;
}
static enum V_104
F_41 ( struct V_87 * V_88 , bool V_105 )
{
return V_106 ;
}
static void F_42 ( struct V_87 * V_88 )
{
struct V_90 * V_91
= F_34 ( V_88 ) ;
F_43 ( V_88 ) ;
F_44 ( V_88 ) ;
F_45 ( V_91 ) ;
}
static struct V_102 * F_46 ( struct V_29 * V_30 )
{
struct V_102 * V_103 ;
F_47 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_103 -> V_107 == V_108 )
return V_103 ;
}
return NULL ;
}
static int F_48 ( struct V_109 * V_30 , struct V_109 * V_110 , void * V_24 )
{
struct V_1 * V_2 = F_49 ( V_30 ) ;
struct V_29 * V_92 = V_24 ;
struct V_102 * V_103 ;
struct V_90 * V_88 ;
struct V_87 * V_87 ;
struct V_47 * V_48 ;
int V_111 ;
V_2 -> V_92 = V_92 ;
V_103 = F_46 ( V_92 ) ;
if ( ! V_103 )
return - V_112 ;
V_88 = F_50 ( V_30 , sizeof( * V_88 ) , V_113 ) ;
if ( ! V_88 )
return - V_112 ;
V_88 -> V_2 = V_2 ;
V_48 = F_50 ( V_30 , sizeof( * V_48 ) , V_113 ) ;
if ( ! V_48 )
return - V_112 ;
V_48 -> V_49 = V_2 ;
V_48 -> V_114 = & V_115 ;
F_51 ( V_92 , V_48 ) ;
V_103 -> V_48 = V_48 ;
V_88 -> V_103 = V_103 ;
V_87 = (struct V_87 * ) V_88 ;
V_87 -> V_116 = V_117 ;
F_52 ( V_92 , V_87 ,
& V_118 , V_119 ) ;
F_53 ( V_87 ,
& V_120 ) ;
V_111 = F_54 ( V_87 ) ;
if ( V_111 )
goto V_121;
V_111 = F_55 ( V_87 , V_103 ) ;
if ( V_111 ) {
F_29 ( L_26 ) ;
goto V_122;
}
F_8 ( V_2 , false ) ;
if ( F_22 ( V_2 , V_92 -> V_123 ) )
F_29 ( L_27 ) ;
return 0 ;
V_122:
F_43 ( V_87 ) ;
V_121:
F_44 ( V_87 ) ;
return - V_124 ;
}
static void F_56 ( struct V_109 * V_30 ,
struct V_109 * V_110 , void * V_24 )
{
struct V_1 * V_2 = F_49 ( V_30 ) ;
struct V_29 * V_92 = V_24 ;
F_20 ( V_2 , V_92 -> V_123 ) ;
}
static int F_57 ( struct V_125 * V_126 )
{
struct V_109 * V_30 = & V_126 -> V_30 ;
struct V_1 * V_2 ;
struct V_127 * V_128 ;
F_9 ( L_28 , V_129 ) ;
V_2 = F_50 ( V_30 , sizeof( * V_2 ) , V_113 ) ;
if ( ! V_2 )
return - V_112 ;
V_2 -> V_30 = V_126 -> V_30 ;
V_128 = F_58 ( V_126 , V_130 , L_29 ) ;
if ( ! V_128 ) {
F_29 ( L_30 ) ;
return - V_112 ;
}
V_2 -> V_4 = F_59 ( V_30 , V_128 -> V_131 , F_60 ( V_128 ) ) ;
if ( ! V_2 -> V_4 )
return - V_112 ;
V_128 = F_58 ( V_126 , V_130 ,
L_31 ) ;
if ( V_128 ) {
V_2 -> V_13 = F_59 ( V_30 , V_128 -> V_131 ,
F_60 ( V_128 ) ) ;
if ( ! V_2 -> V_13 )
return - V_112 ;
} else {
F_15 ( L_32 ) ;
V_2 -> V_13 = NULL ;
}
V_2 -> V_52 = F_61 ( V_30 , L_33 ) ;
if ( F_62 ( V_2 -> V_52 ) ) {
F_29 ( L_34 ) ;
return F_63 ( V_2 -> V_52 ) ;
}
V_2 -> V_51 = F_61 ( V_30 , L_35 ) ;
if ( F_62 ( V_2 -> V_51 ) ) {
F_29 ( L_36 ) ;
return F_63 ( V_2 -> V_51 ) ;
}
F_64 ( V_126 , V_2 ) ;
return F_65 ( & V_126 -> V_30 , & V_132 ) ;
}
static int F_66 ( struct V_125 * V_126 )
{
F_67 ( & V_126 -> V_30 , & V_132 ) ;
return 0 ;
}
