static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
T_1 V_15 = 0 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
V_15 |= F_11 ( V_17 ) ;
}
V_15 |= F_12 ( V_10 -> V_18 ) ;
F_13 ( L_1 , V_10 -> V_19 , V_15 ) ;
F_14 ( V_1 , V_20 , V_15 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_23 * V_6 = V_3 -> V_6 ;
struct V_24 * V_25 ;
unsigned long V_26 ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
V_25 = V_10 -> V_25 ;
if ( V_25 ) {
if ( ! V_22 || ( V_25 -> V_11 . V_28 == V_22 ) ) {
V_10 -> V_25 = NULL ;
F_13 ( L_2 , V_10 -> V_19 , V_25 ) ;
F_17 ( V_6 , V_10 -> V_29 , V_25 ) ;
}
}
F_18 ( & V_6 -> V_27 , V_26 ) ;
}
static void F_19 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_20 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_21 ( V_32 , V_1 -> V_29 ) ;
F_22 ( V_32 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_24 ( V_3 ) ;
F_25 ( & V_10 -> V_33 ) ;
F_26 ( V_10 ) ;
}
static bool F_27 ( struct V_2 * V_3 ,
const struct V_34 * V_35 ,
struct V_34 * V_36 )
{
return true ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_37 * V_38 = & V_1 -> V_6 -> V_39 ;
struct V_2 * V_3 ;
T_1 V_40 = 0 ;
static const enum V_41 V_42 [] = {
V_43 , V_44 , V_45 , V_46 , V_47 ,
} ;
F_29 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_48 = V_49 [ V_17 ] ;
V_40 = F_30 ( V_40 , V_10 -> V_50 ,
V_17 , V_42 [ V_48 ] ) ;
}
}
F_14 ( V_1 , V_51 , V_40 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_52 , V_18 = V_10 -> V_18 ;
bool V_53 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_32 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_33 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_34 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_35 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_48 = V_49 [ V_17 ] ;
if ( V_48 > 0 ) {
const struct V_54 * V_55 =
F_36 ( F_37 ( V_14 -> V_56 ) ) ;
V_53 [ V_48 - 1 ] = V_55 -> V_57 ;
}
}
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
T_1 V_58 ;
if ( V_53 [ V_52 ] ) {
V_58 = F_38 ( V_59 ) |
F_39 ( V_59 ) |
V_60 ;
} else {
V_58 = F_38 ( V_61 ) |
F_39 ( V_62 ) ;
}
F_14 ( V_1 , F_40 ( V_18 , V_52 ) , 0xff ) ;
F_14 ( V_1 , F_41 ( V_18 , V_52 ) , 0x00 ) ;
F_14 ( V_1 , F_42 ( V_18 , V_52 ) , V_58 ) ;
F_14 ( V_1 , F_43 ( V_18 , V_52 ) , 1 ) ;
F_14 ( V_1 , F_44 ( V_18 , V_52 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_18 , V_52 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_52 ) , 0 ) ;
F_14 ( V_1 , F_47 ( V_18 , V_52 ) , 0 ) ;
}
F_28 ( V_1 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_63 V_64 = V_10 -> V_64 ;
int V_18 = V_10 -> V_18 ;
struct V_34 * V_35 ;
if ( F_49 ( ! V_3 -> V_65 ) )
return;
V_35 = & V_3 -> V_65 -> V_36 ;
F_13 ( L_3 ,
V_10 -> V_19 , V_35 -> V_11 . V_29 , V_35 -> V_19 ,
V_35 -> V_66 , V_35 -> clock ,
V_35 -> V_67 , V_35 -> V_68 ,
V_35 -> V_69 , V_35 -> V_70 ,
V_35 -> V_71 , V_35 -> V_72 ,
V_35 -> V_73 , V_35 -> V_74 ,
V_35 -> type , V_35 -> V_26 ) ;
F_14 ( V_1 , F_50 ( V_64 ) ,
F_51 ( V_35 -> V_67 ) |
F_52 ( V_35 -> V_71 ) ) ;
F_14 ( V_1 , F_53 ( V_64 ) , 0 ) ;
F_14 ( V_1 , F_54 ( V_64 ) , 0 ) ;
F_14 ( V_1 , F_55 ( V_64 ) ,
F_56 ( 0 ) |
F_57 ( 0 ) ) ;
F_14 ( V_1 , F_58 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_18 ) ,
F_60 ( V_35 -> V_67 ) |
F_61 ( V_35 -> V_71 ) ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_63 ( V_18 ) , 1 ) ;
if ( V_64 == V_75 ) {
F_14 ( V_1 , F_64 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_64 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_64 ( 2 ) , 0x00ff0000 ) ;
}
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_49 ( ! V_10 -> V_76 ) )
return;
F_66 ( & V_1 -> V_11 , & V_10 -> V_77 ) ;
F_67 ( V_1 ) ;
V_10 -> V_76 = false ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_49 ( V_10 -> V_76 ) )
return;
F_69 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_77 ) ;
F_8 ( V_3 ) ;
V_10 -> V_76 = true ;
}
static int F_70 ( struct V_2 * V_3 ,
struct V_78 * V_65 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_23 * V_6 = V_3 -> V_6 ;
unsigned long V_26 ;
F_13 ( L_7 , V_10 -> V_19 , V_3 -> V_65 -> V_25 ) ;
F_49 ( V_10 -> V_25 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
V_10 -> V_25 = V_3 -> V_65 -> V_25 ;
F_18 ( & V_6 -> V_27 , V_26 ) ;
F_31 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_79 ) ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_80 * V_81 , T_2 V_32 )
{
return - V_82 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_63 V_64 = V_10 -> V_64 ;
unsigned long V_26 ;
F_16 ( & V_10 -> V_83 . V_84 , V_26 ) ;
if ( V_10 -> V_83 . V_85 ) {
struct V_86 * V_87 = V_10 -> V_83 . V_87 ;
struct V_86 * V_88 = V_10 -> V_83 . V_89 ;
T_1 V_90 = V_10 -> V_83 . V_91 ;
if ( V_87 ) {
F_75 ( V_87 ) ;
F_76 ( V_87 , V_1 -> V_29 , & V_90 ) ;
F_14 ( V_1 , F_77 ( V_64 ) ,
F_78 ( V_10 -> V_83 . V_92 ) |
F_79 ( V_10 -> V_83 . V_93 ) ) ;
F_14 ( V_1 , F_80 ( V_64 ) , V_90 ) ;
F_14 ( V_1 , F_81 ( V_64 ) ,
F_82 ( V_94 ) |
V_95 ) ;
} else {
F_14 ( V_1 , F_80 ( V_64 ) ,
V_1 -> V_96 ) ;
}
if ( V_88 )
F_83 ( & V_10 -> V_33 , V_88 ) ;
V_10 -> V_83 . V_89 = V_87 ;
V_10 -> V_83 . V_85 = false ;
}
F_14 ( V_1 , F_84 ( V_64 ) ,
F_85 ( V_10 -> V_83 . V_97 ) |
F_86 ( V_10 -> V_83 . V_98 ) ) ;
F_18 ( & V_10 -> V_83 . V_84 , V_26 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_21 * V_28 , T_1 V_99 ,
T_1 V_92 , T_1 V_93 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_6 = V_3 -> V_6 ;
struct V_86 * V_100 , * V_101 ;
unsigned long V_26 ;
T_1 V_90 ;
int V_102 ;
if ( ( V_92 > V_103 ) || ( V_93 > V_104 ) ) {
F_88 ( V_6 -> V_6 , L_8 , V_92 , V_93 ) ;
return - V_82 ;
}
if ( V_99 ) {
V_100 = F_89 ( V_6 , V_28 , V_99 ) ;
if ( ! V_100 )
return - V_105 ;
} else {
V_100 = NULL ;
}
if ( V_100 ) {
V_102 = F_90 ( V_100 , V_1 -> V_29 , & V_90 ) ;
if ( V_102 )
goto V_106;
} else {
V_90 = 0 ;
}
F_16 ( & V_10 -> V_83 . V_84 , V_26 ) ;
V_101 = V_10 -> V_83 . V_87 ;
V_10 -> V_83 . V_87 = V_100 ;
V_10 -> V_83 . V_91 = V_90 ;
V_10 -> V_83 . V_92 = V_92 ;
V_10 -> V_83 . V_93 = V_93 ;
V_10 -> V_83 . V_85 = true ;
F_18 ( & V_10 -> V_83 . V_84 , V_26 ) ;
if ( V_101 ) {
F_83 ( & V_10 -> V_33 , V_101 ) ;
}
F_4 ( V_3 , V_107 ) ;
return 0 ;
V_106:
F_22 ( V_100 ) ;
return V_102 ;
}
static int F_91 ( struct V_2 * V_3 , int V_97 , int V_98 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_26 ;
F_16 ( & V_10 -> V_83 . V_84 , V_26 ) ;
V_10 -> V_83 . V_97 = V_97 ;
V_10 -> V_83 . V_98 = V_98 ;
F_18 ( & V_10 -> V_83 . V_84 , V_26 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_107 ) ;
return 0 ;
}
static void F_92 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_66 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_93 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_79 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_107 ) {
F_74 ( V_3 ) ;
F_94 ( & V_10 -> V_33 , V_5 -> V_111 ) ;
}
}
static void F_95 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_77 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_9 , V_10 -> V_19 , V_110 ) ;
F_8 ( V_3 ) ;
}
T_1 F_96 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_112 ;
}
void F_97 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_10 , V_10 -> V_19 , V_22 ) ;
F_15 ( V_3 , V_22 ) ;
}
void F_98 ( struct V_2 * V_3 , T_1 V_38 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_99 ( V_10 -> V_64 ) , V_38 ) ;
}
void F_100 ( struct V_2 * V_3 , enum V_113 V_114 , int V_50 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_115 ;
V_115 = F_101 ( V_1 , V_116 ) ;
switch ( V_10 -> V_64 ) {
case V_117 :
V_115 &= ~ V_118 ;
V_115 |= F_102 ( V_114 ) ;
break;
case V_119 :
V_115 &= ~ V_120 ;
V_115 |= F_103 ( V_114 ) ;
break;
case V_75 :
V_115 &= ~ V_121 ;
V_115 |= F_104 ( V_114 ) ;
break;
}
if ( V_114 == V_122 ) {
V_115 &= ~ V_123 ;
V_115 |= V_124 ;
} else if ( V_114 == V_125 ) {
V_115 &= ~ V_124 ;
V_115 |= V_123 ;
}
V_10 -> V_50 = V_50 ;
F_31 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_115 ) ;
F_14 ( V_1 , V_116 , V_115 ) ;
}
struct V_2 * F_105 ( struct V_23 * V_6 ,
struct V_13 * V_14 , int V_29 , int V_126 ,
enum V_63 V_127 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_106 ( sizeof( * V_10 ) , V_128 ) ;
if ( ! V_10 )
return F_107 ( - V_129 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_18 = V_126 ;
V_10 -> V_64 = V_127 ;
V_10 -> V_12 . V_112 = F_108 ( V_10 -> V_64 ) ;
V_10 -> V_12 . V_109 = F_92 ;
V_10 -> V_77 . V_112 = F_109 ( V_10 -> V_64 ) ;
V_10 -> V_77 . V_109 = F_95 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_12 ,
V_130 [ V_127 ] , V_126 ) ;
F_110 ( & V_10 -> V_83 . V_84 ) ;
F_111 ( & V_10 -> V_33 ,
L_13 , F_19 ) ;
F_112 ( V_6 , V_3 , V_14 , NULL , & V_131 ) ;
F_113 ( V_3 , & V_132 ) ;
V_14 -> V_3 = V_3 ;
F_114 ( V_14 , & V_3 -> V_11 ) ;
return V_3 ;
}
