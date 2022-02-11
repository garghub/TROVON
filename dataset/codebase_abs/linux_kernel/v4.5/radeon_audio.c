static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
F_4 ( V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_2 V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
if ( ! V_7 )
return;
if ( V_2 -> V_15 . V_16 ) {
F_6 (encoder, &rdev->ddev->mode_config.encoder_list, head) {
if ( F_7 ( V_10 ) ) {
V_11 = F_8 ( V_10 ) ;
V_13 = V_11 -> V_17 ;
if ( V_13 -> V_7 == V_7 )
V_14 ++ ;
}
}
if ( ( V_14 > 1 ) && ( V_8 == 0 ) )
return;
}
if ( V_2 -> V_18 . V_19 -> V_20 )
V_2 -> V_18 . V_19 -> V_20 ( V_2 , V_7 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) ) {
V_2 -> V_18 . V_19 = & V_21 ;
V_2 -> V_18 . V_22 = & V_23 ;
V_2 -> V_18 . V_24 = & V_25 ;
} else if ( F_11 ( V_2 ) ) {
V_2 -> V_18 . V_19 = & V_26 ;
V_2 -> V_18 . V_22 = & V_27 ;
V_2 -> V_18 . V_24 = & V_28 ;
} else if ( F_12 ( V_2 ) ) {
V_2 -> V_18 . V_19 = & V_29 ;
V_2 -> V_18 . V_22 = & V_30 ;
V_2 -> V_18 . V_24 = & V_31 ;
} else {
V_2 -> V_18 . V_19 = & V_32 ;
V_2 -> V_18 . V_22 = & V_33 ;
V_2 -> V_18 . V_24 = 0 ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) && ! F_15 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! V_35 || ! F_13 ( V_2 ) )
return 0 ;
V_2 -> V_18 . V_36 = true ;
if ( F_17 ( V_2 ) )
V_2 -> V_18 . V_37 = 3 ;
else if ( F_18 ( V_2 ) )
V_2 -> V_18 . V_37 = 7 ;
else if ( F_19 ( V_2 ) )
V_2 -> V_18 . V_37 = 7 ;
else if ( F_20 ( V_2 ) )
V_2 -> V_18 . V_37 = 2 ;
else if ( F_21 ( V_2 ) )
V_2 -> V_18 . V_37 = 6 ;
else if ( F_10 ( V_2 ) )
V_2 -> V_18 . V_37 = 6 ;
else
V_2 -> V_18 . V_37 = 1 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_18 . V_37 ; V_34 ++ ) {
V_2 -> V_18 . V_7 [ V_34 ] . V_38 = - 1 ;
V_2 -> V_18 . V_7 [ V_34 ] . V_39 = - 1 ;
V_2 -> V_18 . V_7 [ V_34 ] . V_40 = - 1 ;
V_2 -> V_18 . V_7 [ V_34 ] . V_41 = 0 ;
V_2 -> V_18 . V_7 [ V_34 ] . V_42 = 0 ;
V_2 -> V_18 . V_7 [ V_34 ] . V_43 = false ;
V_2 -> V_18 . V_7 [ V_34 ] . V_3 = V_44 [ V_34 ] ;
V_2 -> V_18 . V_7 [ V_34 ] . V_45 = V_34 ;
}
F_9 ( V_2 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_18 . V_37 ; V_34 ++ )
F_5 ( V_2 , & V_2 -> V_18 . V_7 [ V_34 ] , 0 ) ;
return 0 ;
}
T_1 F_22 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_18 . V_19 -> V_46 )
return V_2 -> V_18 . V_19 -> V_46 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
if ( V_2 -> V_18 . V_19 -> V_47 )
V_2 -> V_18 . V_19 -> V_47 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_48 * V_49 = F_25 ( V_10 ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_50 * V_51 ;
int V_52 ;
if ( ! V_49 )
return;
V_52 = F_26 ( F_27 ( V_49 ) , & V_51 ) ;
if ( V_52 <= 0 ) {
F_28 ( L_1 , V_52 ) ;
return;
}
F_29 ( ! V_51 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_53 )
V_11 -> V_18 -> V_53 ( V_10 , V_51 , V_52 ) ;
F_30 ( V_51 ) ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_48 * V_49 = F_25 ( V_10 ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
T_2 * V_54 = NULL ;
int V_52 ;
if ( ! V_49 )
return;
V_52 = F_32 ( F_27 ( V_49 ) ,
& V_54 ) ;
if ( V_52 < 0 ) {
F_33 ( L_2 ,
V_52 ) ;
V_52 = 0 ;
}
if ( V_11 -> V_18 && V_11 -> V_18 -> V_55 )
V_11 -> V_18 -> V_55 ( V_10 , V_54 , V_52 ) ;
F_30 ( V_54 ) ;
}
static void F_34 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_48 * V_49 = F_25 ( V_10 ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
if ( ! V_49 )
return;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_58 )
V_11 -> V_18 -> V_58 ( V_10 , V_49 , V_57 ) ;
}
struct V_6 * F_35 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_59 -> V_60 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_61 )
return V_11 -> V_18 -> V_61 ( V_2 ) ;
return NULL ;
}
static void F_36 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_62 )
V_11 -> V_18 -> V_62 ( V_10 ) ;
}
void F_37 ( struct V_48 * V_49 ,
struct V_9 * V_10 ,
enum V_63 V_64 )
{
struct V_65 * V_59 = V_49 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_60 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 ;
if ( ! F_13 ( V_2 ) )
return;
if ( ! F_7 ( V_10 ) )
return;
V_13 = V_11 -> V_17 ;
if ( V_64 == V_66 ) {
if ( V_49 -> V_67 == V_68 ) {
struct V_69 * V_69 = F_38 ( V_49 ) ;
if ( F_39 ( V_69 ) ==
V_70 )
V_11 -> V_18 = V_2 -> V_18 . V_24 ;
else
V_11 -> V_18 = V_2 -> V_18 . V_22 ;
} else {
V_11 -> V_18 = V_2 -> V_18 . V_22 ;
}
if ( F_40 ( F_27 ( V_49 ) ) ) {
if ( ! V_13 -> V_7 )
V_13 -> V_7 = F_35 ( V_10 ) ;
F_5 ( V_2 , V_13 -> V_7 , 0xf ) ;
} else {
F_5 ( V_2 , V_13 -> V_7 , 0 ) ;
V_13 -> V_7 = NULL ;
}
} else {
F_5 ( V_2 , V_13 -> V_7 , 0 ) ;
V_13 -> V_7 = NULL ;
}
}
void F_41 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! V_2 -> V_18 . V_36 )
return;
for ( V_34 = 0 ; V_34 < V_2 -> V_18 . V_37 ; V_34 ++ )
F_5 ( V_2 , & V_2 -> V_18 . V_7 [ V_34 ] , 0 ) ;
V_2 -> V_18 . V_36 = false ;
}
static void F_42 ( struct V_9 * V_10 , unsigned int clock )
{
struct V_1 * V_2 = V_10 -> V_59 -> V_60 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_71 * V_72 = F_43 ( V_10 -> V_72 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_73 )
V_11 -> V_18 -> V_73 ( V_2 , V_72 , clock ) ;
}
static int F_44 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = V_10 -> V_59 -> V_60 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
struct V_48 * V_49 = F_25 ( V_10 ) ;
T_2 V_74 [ V_75 + V_76 ] ;
struct V_77 V_78 ;
int V_79 ;
if ( ! V_49 )
return - V_80 ;
V_79 = F_45 ( & V_78 , V_57 ) ;
if ( V_79 < 0 ) {
F_28 ( L_3 , V_79 ) ;
return V_79 ;
}
if ( V_11 -> V_81 != V_82 ) {
if ( F_46 ( F_27 ( V_49 ) ) ) {
if ( V_11 -> V_81 == V_83 )
V_78 . V_84 = V_85 ;
else
V_78 . V_84 = V_86 ;
} else {
V_78 . V_84 = V_87 ;
}
}
V_79 = F_47 ( & V_78 , V_74 , sizeof( V_74 ) ) ;
if ( V_79 < 0 ) {
F_28 ( L_4 , V_79 ) ;
return V_79 ;
}
if ( V_13 && V_13 -> V_88 && V_11 -> V_18 &&
V_11 -> V_18 -> V_89 )
V_11 -> V_18 -> V_89 ( V_2 , V_13 -> V_88 -> V_3 ,
V_74 , sizeof( V_74 ) ) ;
return 0 ;
}
static void F_48 ( unsigned int clock , int * V_90 , int * V_91 , int V_92 )
{
int V_93 , V_94 ;
unsigned long div , V_95 ;
V_93 = 128 * V_92 ;
V_94 = clock * 1000 ;
div = F_49 ( V_93 , V_94 ) ;
V_93 /= div ;
V_94 /= div ;
V_95 = ( ( 128 * V_92 / 1000 ) + ( V_93 - 1 ) ) / V_93 ;
V_93 *= V_95 ;
V_94 *= V_95 ;
if ( V_93 < ( 128 * V_92 / 1500 ) )
F_50 ( V_96 L_5 ) ;
if ( V_93 > ( 128 * V_92 / 300 ) )
F_50 ( V_96 L_6 ) ;
* V_91 = V_93 ;
* V_90 = V_94 ;
F_33 ( L_7 ,
* V_91 , * V_90 , V_92 ) ;
}
static const struct V_97 * F_51 ( unsigned int clock )
{
static struct V_97 V_98 ;
T_2 V_34 ;
static const struct V_97 V_99 [] = {
{ 25175 , 4096 , 25175 , 28224 , 125875 , 6144 , 25175 } ,
{ 25200 , 4096 , 25200 , 6272 , 28000 , 6144 , 25200 } ,
{ 27000 , 4096 , 27000 , 6272 , 30000 , 6144 , 27000 } ,
{ 27027 , 4096 , 27027 , 6272 , 30030 , 6144 , 27027 } ,
{ 54000 , 4096 , 54000 , 6272 , 60000 , 6144 , 54000 } ,
{ 54054 , 4096 , 54054 , 6272 , 60060 , 6144 , 54054 } ,
{ 74176 , 4096 , 74176 , 5733 , 75335 , 6144 , 74176 } ,
{ 74250 , 4096 , 74250 , 6272 , 82500 , 6144 , 74250 } ,
{ 148352 , 4096 , 148352 , 5733 , 150670 , 6144 , 148352 } ,
{ 148500 , 4096 , 148500 , 6272 , 165000 , 6144 , 148500 } ,
} ;
for ( V_34 = 0 ; V_34 < F_52 ( V_99 ) ; V_34 ++ )
if ( V_99 [ V_34 ] . clock == clock )
return & V_99 [ V_34 ] ;
F_48 ( clock , & V_98 . V_100 , & V_98 . V_101 , 32000 ) ;
F_48 ( clock , & V_98 . V_102 , & V_98 . V_103 , 44100 ) ;
F_48 ( clock , & V_98 . V_104 , & V_98 . V_105 , 48000 ) ;
return & V_98 ;
}
static void F_53 ( struct V_9 * V_10 , unsigned int clock )
{
const struct V_97 * V_106 = F_51 ( clock ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_107 )
V_11 -> V_18 -> V_107 ( V_10 , V_13 -> V_88 -> V_3 , V_106 ) ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_108 )
V_11 -> V_18 -> V_108 ( V_10 , V_13 -> V_88 -> V_3 ) ;
}
static void F_55 ( struct V_9 * V_10 )
{
int V_109 = 8 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( V_10 -> V_72 ) {
struct V_71 * V_71 = F_43 ( V_10 -> V_72 ) ;
V_109 = V_71 -> V_109 ;
}
if ( V_11 -> V_18 && V_11 -> V_18 -> V_110 )
V_11 -> V_18 -> V_110 ( V_10 , V_13 -> V_88 -> V_3 , V_109 ) ;
}
static void F_56 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_111 )
V_11 -> V_18 -> V_111 ( V_10 , V_13 -> V_88 -> V_3 ) ;
}
static void F_57 ( struct V_9 * V_10 , bool V_112 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_113 )
V_11 -> V_18 -> V_113 ( V_10 , V_13 -> V_88 -> V_3 , V_112 ) ;
}
static void F_58 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
struct V_48 * V_49 = F_25 ( V_10 ) ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( ! V_49 )
return;
if ( F_40 ( F_27 ( V_49 ) ) ) {
F_57 ( V_10 , true ) ;
F_31 ( V_10 ) ;
F_24 ( V_10 ) ;
F_34 ( V_10 , V_57 ) ;
F_42 ( V_10 , V_57 -> clock ) ;
F_54 ( V_10 ) ;
F_55 ( V_10 ) ;
F_53 ( V_10 , V_57 -> clock ) ;
F_56 ( V_10 ) ;
F_36 ( V_10 ) ;
if ( F_44 ( V_10 , V_57 ) < 0 )
return;
F_57 ( V_10 , false ) ;
} else {
F_55 ( V_10 ) ;
if ( F_44 ( V_10 , V_57 ) < 0 )
return;
}
}
static void F_59 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_65 * V_59 = V_10 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_60 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_17 ;
struct V_48 * V_49 = F_25 ( V_10 ) ;
if ( ! V_13 || ! V_13 -> V_88 )
return;
if ( ! V_49 )
return;
if ( F_40 ( F_27 ( V_49 ) ) ) {
F_31 ( V_10 ) ;
F_24 ( V_10 ) ;
F_34 ( V_10 , V_57 ) ;
F_42 ( V_10 , V_2 -> clock . V_114 * 10 ) ;
F_56 ( V_10 ) ;
F_36 ( V_10 ) ;
if ( F_44 ( V_10 , V_57 ) < 0 )
return;
}
}
void F_60 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_115 )
V_11 -> V_18 -> V_115 ( V_10 , V_57 ) ;
}
void F_61 ( struct V_9 * V_10 , int V_57 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
if ( V_11 -> V_18 && V_11 -> V_18 -> V_116 )
V_11 -> V_18 -> V_116 ( V_10 , V_57 == V_117 ) ;
}
unsigned int F_62 ( unsigned int div )
{
if ( div >= 8 && div < 64 )
return ( div - 8 ) * 25 + 200 ;
else if ( div >= 64 && div < 96 )
return ( div - 64 ) * 50 + 1600 ;
else if ( div >= 96 && div < 128 )
return ( div - 96 ) * 100 + 3200 ;
else
return 0 ;
}
