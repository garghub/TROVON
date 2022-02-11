static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
F_4 ( V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) ) {
V_2 -> V_6 . V_7 = & V_8 ;
V_2 -> V_6 . V_9 = & V_10 ;
V_2 -> V_6 . V_11 = & V_12 ;
} else if ( F_7 ( V_2 ) ) {
V_2 -> V_6 . V_7 = & V_13 ;
V_2 -> V_6 . V_9 = & V_14 ;
V_2 -> V_6 . V_11 = & V_15 ;
} else if ( F_8 ( V_2 ) ) {
V_2 -> V_6 . V_7 = & V_16 ;
V_2 -> V_6 . V_9 = & V_17 ;
V_2 -> V_6 . V_11 = & V_18 ;
} else {
V_2 -> V_6 . V_7 = & V_19 ;
V_2 -> V_6 . V_9 = & V_20 ;
V_2 -> V_6 . V_11 = 0 ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) && ! F_11 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! V_22 || ! F_9 ( V_2 ) )
return 0 ;
V_2 -> V_6 . V_23 = true ;
if ( F_13 ( V_2 ) )
V_2 -> V_6 . V_24 = 3 ;
else if ( F_14 ( V_2 ) )
V_2 -> V_6 . V_24 = 7 ;
else if ( F_15 ( V_2 ) )
V_2 -> V_6 . V_24 = 7 ;
else if ( F_16 ( V_2 ) )
V_2 -> V_6 . V_24 = 2 ;
else if ( F_17 ( V_2 ) )
V_2 -> V_6 . V_24 = 6 ;
else if ( F_6 ( V_2 ) )
V_2 -> V_6 . V_24 = 6 ;
else
V_2 -> V_6 . V_24 = 1 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_6 . V_24 ; V_21 ++ ) {
V_2 -> V_6 . V_25 [ V_21 ] . V_26 = - 1 ;
V_2 -> V_6 . V_25 [ V_21 ] . V_27 = - 1 ;
V_2 -> V_6 . V_25 [ V_21 ] . V_28 = - 1 ;
V_2 -> V_6 . V_25 [ V_21 ] . V_29 = 0 ;
V_2 -> V_6 . V_25 [ V_21 ] . V_30 = 0 ;
V_2 -> V_6 . V_25 [ V_21 ] . V_31 = false ;
V_2 -> V_6 . V_25 [ V_21 ] . V_3 = V_32 [ V_21 ] ;
V_2 -> V_6 . V_25 [ V_21 ] . V_33 = V_21 ;
}
F_5 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_6 . V_24 ; V_21 ++ )
F_18 ( V_2 , & V_2 -> V_6 . V_25 [ V_21 ] , false ) ;
return 0 ;
}
T_1 F_19 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_6 . V_7 -> V_34 )
return V_2 -> V_6 . V_7 -> V_34 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
if ( V_2 -> V_6 . V_7 -> V_35 )
V_2 -> V_6 . V_7 -> V_35 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_21 ( struct V_36 * V_37 )
{
struct V_38 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_41 = NULL ;
struct V_42 * V_43 ;
int V_44 ;
F_22 (connector,
&encoder->dev->mode_config.connector_list, head) {
if ( V_40 -> V_37 == V_37 ) {
V_41 = F_23 ( V_40 ) ;
break;
}
}
if ( ! V_41 ) {
F_24 ( L_1 ) ;
return;
}
V_44 = F_25 ( F_26 ( V_40 ) , & V_43 ) ;
if ( V_44 <= 0 ) {
F_24 ( L_2 , V_44 ) ;
return;
}
F_27 ( ! V_43 ) ;
V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_45 )
V_38 -> V_6 -> V_45 ( V_37 , V_43 , V_44 ) ;
F_29 ( V_43 ) ;
}
static void F_30 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_39 * V_40 ;
struct V_41 * V_41 = NULL ;
T_2 * V_46 = NULL ;
int V_44 ;
F_22 (connector,
&encoder->dev->mode_config.connector_list, head) {
if ( V_40 -> V_37 == V_37 ) {
V_41 = F_23 ( V_40 ) ;
break;
}
}
if ( ! V_41 ) {
F_24 ( L_1 ) ;
return;
}
V_44 = F_31 (
F_26 ( V_40 ) , & V_46 ) ;
if ( V_44 < 0 ) {
F_32 ( L_3 ,
V_44 ) ;
V_44 = 0 ;
}
if ( V_38 -> V_6 && V_38 -> V_6 -> V_47 )
V_38 -> V_6 -> V_47 ( V_37 , V_46 , V_44 ) ;
F_29 ( V_46 ) ;
}
static void F_33 ( struct V_36 * V_37 ,
struct V_48 * V_49 )
{
struct V_38 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_41 = 0 ;
F_22 (connector,
&encoder->dev->mode_config.connector_list, head) {
if ( V_40 -> V_37 == V_37 ) {
V_41 = F_23 ( V_40 ) ;
break;
}
}
if ( ! V_41 ) {
F_24 ( L_1 ) ;
return;
}
V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_50 )
V_38 -> V_6 -> V_50 ( V_37 , V_40 , V_49 ) ;
}
struct V_51 * F_34 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_52 -> V_53 ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_54 )
return V_38 -> V_6 -> V_54 ( V_2 ) ;
return NULL ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_55 )
V_38 -> V_6 -> V_55 ( V_37 ) ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_51 * V_25 , T_2 V_56 )
{
if ( V_2 -> V_6 . V_7 -> V_57 )
V_2 -> V_6 . V_7 -> V_57 ( V_2 , V_25 , V_56 ) ;
}
void F_36 ( struct V_39 * V_40 ,
enum V_58 V_59 )
{
struct V_1 * V_2 ;
struct V_38 * V_38 ;
struct V_60 * V_61 ;
if ( ! V_40 || ! V_40 -> V_37 )
return;
V_2 = V_40 -> V_37 -> V_52 -> V_53 ;
if ( ! F_9 ( V_2 ) )
return;
V_38 = F_28 ( V_40 -> V_37 ) ;
V_61 = V_38 -> V_62 ;
if ( V_59 == V_63 ) {
struct V_41 * V_41 ;
int V_64 ;
if ( ! F_37 ( F_26 ( V_40 ) ) ) {
V_38 -> V_6 = NULL ;
return;
}
V_41 = F_23 ( V_40 ) ;
V_64 = F_38 ( V_41 ) ;
if ( V_40 -> V_65 == V_66 &&
V_64 == V_67 )
V_38 -> V_6 = V_2 -> V_6 . V_11 ;
else
V_38 -> V_6 = V_2 -> V_6 . V_9 ;
V_61 -> V_68 -> V_25 = F_34 ( V_40 -> V_37 ) ;
F_18 ( V_2 , V_61 -> V_68 -> V_25 , 0xf ) ;
} else {
F_18 ( V_2 , V_61 -> V_68 -> V_25 , 0 ) ;
V_61 -> V_68 -> V_25 = NULL ;
}
}
void F_39 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! V_2 -> V_6 . V_23 )
return;
for ( V_21 = 0 ; V_21 < V_2 -> V_6 . V_24 ; V_21 ++ )
F_18 ( V_2 , & V_2 -> V_6 . V_25 [ V_21 ] , false ) ;
V_2 -> V_6 . V_23 = false ;
}
static void F_40 ( struct V_36 * V_37 , unsigned int clock )
{
struct V_1 * V_2 = V_37 -> V_52 -> V_53 ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_69 * V_70 = F_41 ( V_37 -> V_70 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_71 )
V_38 -> V_6 -> V_71 ( V_2 , V_70 , clock ) ;
}
static int F_42 ( struct V_36 * V_37 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_37 -> V_52 -> V_53 ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
struct V_39 * V_40 ;
struct V_41 * V_41 = NULL ;
T_2 V_72 [ V_73 + V_74 ] ;
struct V_75 V_76 ;
int V_77 ;
F_22 (connector,
&encoder->dev->mode_config.connector_list, head) {
if ( V_40 -> V_37 == V_37 ) {
V_41 = F_23 ( V_40 ) ;
break;
}
}
if ( ! V_41 ) {
F_24 ( L_1 ) ;
return - V_78 ;
}
V_77 = F_43 ( & V_76 , V_49 ) ;
if ( V_77 < 0 ) {
F_24 ( L_4 , V_77 ) ;
return V_77 ;
}
if ( F_44 ( F_26 ( V_40 ) ) ) {
if ( V_38 -> V_79 == V_80 )
V_76 . V_81 = V_82 ;
else
V_76 . V_81 = V_83 ;
} else {
V_76 . V_81 = V_84 ;
}
V_77 = F_45 ( & V_76 , V_72 , sizeof( V_72 ) ) ;
if ( V_77 < 0 ) {
F_24 ( L_5 , V_77 ) ;
return V_77 ;
}
if ( V_61 && V_61 -> V_68 &&
V_38 -> V_6 && V_38 -> V_6 -> V_85 )
V_38 -> V_6 -> V_85 ( V_2 , V_61 -> V_68 -> V_3 ,
V_72 , sizeof( V_72 ) ) ;
return 0 ;
}
static void F_46 ( unsigned int clock , int * V_86 , int * V_87 , int V_88 )
{
int V_89 , V_90 ;
unsigned long div , V_91 ;
V_89 = 128 * V_88 ;
V_90 = clock * 1000 ;
div = F_47 ( V_89 , V_90 ) ;
V_89 /= div ;
V_90 /= div ;
V_91 = ( ( 128 * V_88 / 1000 ) + ( V_89 - 1 ) ) / V_89 ;
V_89 *= V_91 ;
V_90 *= V_91 ;
if ( V_89 < ( 128 * V_88 / 1500 ) )
F_48 ( V_92 L_6 ) ;
if ( V_89 > ( 128 * V_88 / 300 ) )
F_48 ( V_92 L_7 ) ;
* V_87 = V_89 ;
* V_86 = V_90 ;
F_32 ( L_8 ,
* V_87 , * V_86 , V_88 ) ;
}
static const struct V_93 * F_49 ( unsigned int clock )
{
static struct V_93 V_94 ;
T_2 V_21 ;
static const struct V_93 V_95 [] = {
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
for ( V_21 = 0 ; V_21 < F_50 ( V_95 ) ; V_21 ++ )
if ( V_95 [ V_21 ] . clock == clock )
return & V_95 [ V_21 ] ;
F_46 ( clock , & V_94 . V_96 , & V_94 . V_97 , 32000 ) ;
F_46 ( clock , & V_94 . V_98 , & V_94 . V_99 , 44100 ) ;
F_46 ( clock , & V_94 . V_100 , & V_94 . V_101 , 48000 ) ;
return & V_94 ;
}
static void F_51 ( struct V_36 * V_37 , unsigned int clock )
{
const struct V_93 * V_102 = F_49 ( clock ) ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_103 )
V_38 -> V_6 -> V_103 ( V_37 , V_61 -> V_68 -> V_3 , V_102 ) ;
}
static void F_52 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_104 )
V_38 -> V_6 -> V_104 ( V_37 , V_61 -> V_68 -> V_3 ) ;
}
static void F_53 ( struct V_36 * V_37 )
{
int V_105 = 8 ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
if ( V_37 -> V_70 ) {
struct V_69 * V_69 = F_41 ( V_37 -> V_70 ) ;
V_105 = V_69 -> V_105 ;
}
if ( V_38 -> V_6 && V_38 -> V_6 -> V_106 )
V_38 -> V_6 -> V_106 ( V_37 , V_61 -> V_68 -> V_3 , V_105 ) ;
}
static void F_54 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_107 )
V_38 -> V_6 -> V_107 ( V_37 , V_61 -> V_68 -> V_3 ) ;
}
static void F_55 ( struct V_36 * V_37 , bool V_108 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_109 )
V_38 -> V_6 -> V_109 ( V_37 , V_61 -> V_68 -> V_3 , V_108 ) ;
}
static void F_56 ( struct V_36 * V_37 ,
struct V_48 * V_49 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
F_55 ( V_37 , true ) ;
F_30 ( V_37 ) ;
F_21 ( V_37 ) ;
F_33 ( V_37 , V_49 ) ;
F_40 ( V_37 , V_49 -> clock ) ;
F_52 ( V_37 ) ;
F_53 ( V_37 ) ;
F_51 ( V_37 , V_49 -> clock ) ;
F_54 ( V_37 ) ;
F_35 ( V_37 ) ;
if ( F_42 ( V_37 , V_49 ) < 0 )
return;
F_55 ( V_37 , false ) ;
}
static void F_57 ( struct V_36 * V_37 ,
struct V_48 * V_49 )
{
struct V_110 * V_52 = V_37 -> V_52 ;
struct V_1 * V_2 = V_52 -> V_53 ;
struct V_38 * V_38 = F_28 ( V_37 ) ;
struct V_60 * V_61 = V_38 -> V_62 ;
struct V_39 * V_40 = F_58 ( V_37 ) ;
struct V_41 * V_41 = F_23 ( V_40 ) ;
struct V_111 * V_112 =
V_41 -> V_113 ;
if ( ! V_61 || ! V_61 -> V_68 )
return;
F_30 ( V_37 ) ;
F_21 ( V_37 ) ;
F_33 ( V_37 , V_49 ) ;
if ( V_2 -> clock . V_114 || F_59 ( V_2 ) )
F_40 ( V_37 , V_2 -> clock . V_115 * 10 ) ;
else
F_40 ( V_37 , V_112 -> V_116 ) ;
F_54 ( V_37 ) ;
F_35 ( V_37 ) ;
if ( F_42 ( V_37 , V_49 ) < 0 )
return;
}
void F_60 ( struct V_36 * V_37 ,
struct V_48 * V_49 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_117 )
V_38 -> V_6 -> V_117 ( V_37 , V_49 ) ;
}
void F_61 ( struct V_36 * V_37 , int V_49 )
{
struct V_38 * V_38 = F_28 ( V_37 ) ;
if ( V_38 -> V_6 && V_38 -> V_6 -> V_118 )
V_38 -> V_6 -> V_118 ( V_37 , V_49 == V_119 ) ;
}
