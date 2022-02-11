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
V_10 -> V_20 = V_15 ;
F_14 ( V_1 , V_21 , V_15 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_25 * V_26 ;
unsigned long V_27 ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_26 = V_10 -> V_26 ;
if ( V_26 ) {
if ( ! V_23 || ( V_26 -> V_11 . V_29 == V_23 ) ) {
V_10 -> V_26 = NULL ;
F_13 ( L_2 , V_10 -> V_19 , V_26 ) ;
F_17 ( V_6 , V_10 -> V_30 , V_26 ) ;
}
}
F_18 ( & V_6 -> V_28 , V_27 ) ;
}
static void F_19 ( struct V_31 * V_32 , void * V_33 )
{
struct V_10 * V_10 =
F_20 ( V_32 , struct V_10 , V_34 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_21 ( V_33 , V_1 -> V_30 ) ;
F_22 ( V_33 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_24 ( V_3 ) ;
F_25 ( & V_10 -> V_34 ) ;
F_26 ( V_10 ) ;
}
static bool F_27 ( struct V_2 * V_3 ,
const struct V_35 * V_36 ,
struct V_35 * V_37 )
{
return true ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_38 * V_39 = & V_1 -> V_6 -> V_40 ;
struct V_2 * V_3 ;
T_1 V_41 = 0 ;
static const enum V_42 V_43 [] = {
V_44 , V_45 , V_46 , V_47 , V_48 ,
} ;
F_29 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_49 = V_50 [ V_17 ] ;
V_41 = F_30 ( V_41 , V_10 -> V_51 ,
V_17 , V_43 [ V_49 ] ) ;
}
}
F_14 ( V_1 , V_52 , V_41 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_53 , V_18 = V_10 -> V_18 ;
bool V_54 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_32 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_33 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_34 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_35 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_49 = V_50 [ V_17 ] ;
if ( V_49 > 0 ) {
const struct V_55 * V_56 =
F_36 ( F_37 ( V_14 -> V_57 ) ) ;
V_54 [ V_49 - 1 ] = V_56 -> V_58 ;
}
}
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
T_1 V_59 ;
if ( V_54 [ V_53 ] ) {
V_59 = F_38 ( V_60 ) |
F_39 ( V_60 ) |
V_61 ;
} else {
V_59 = F_38 ( V_62 ) |
F_39 ( V_63 ) ;
}
F_14 ( V_1 , F_40 ( V_18 , V_53 ) , 0xff ) ;
F_14 ( V_1 , F_41 ( V_18 , V_53 ) , 0x00 ) ;
F_14 ( V_1 , F_42 ( V_18 , V_53 ) , V_59 ) ;
F_14 ( V_1 , F_43 ( V_18 , V_53 ) , 1 ) ;
F_14 ( V_1 , F_44 ( V_18 , V_53 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_18 , V_53 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_53 ) , 0 ) ;
F_14 ( V_1 , F_47 ( V_18 , V_53 ) , 0 ) ;
}
F_28 ( V_1 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_64 V_65 = V_10 -> V_65 ;
int V_18 = V_10 -> V_18 ;
struct V_35 * V_36 ;
if ( F_49 ( ! V_3 -> V_66 ) )
return;
V_36 = & V_3 -> V_66 -> V_37 ;
F_13 ( L_3 ,
V_10 -> V_19 , V_36 -> V_11 . V_30 , V_36 -> V_19 ,
V_36 -> V_67 , V_36 -> clock ,
V_36 -> V_68 , V_36 -> V_69 ,
V_36 -> V_70 , V_36 -> V_71 ,
V_36 -> V_72 , V_36 -> V_73 ,
V_36 -> V_74 , V_36 -> V_75 ,
V_36 -> type , V_36 -> V_27 ) ;
F_14 ( V_1 , F_50 ( V_65 ) ,
F_51 ( V_36 -> V_68 ) |
F_52 ( V_36 -> V_72 ) ) ;
F_14 ( V_1 , F_53 ( V_65 ) , 0 ) ;
F_14 ( V_1 , F_54 ( V_65 ) , 0 ) ;
F_14 ( V_1 , F_55 ( V_65 ) ,
F_56 ( 0 ) |
F_57 ( 0 ) ) ;
F_14 ( V_1 , F_58 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_18 ) ,
F_60 ( V_36 -> V_68 ) |
F_61 ( V_36 -> V_72 ) ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_63 ( V_18 ) , 1 ) ;
if ( V_65 == V_76 ) {
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
if ( F_49 ( ! V_10 -> V_77 ) )
return;
F_66 ( & V_1 -> V_11 , & V_10 -> V_78 ) ;
F_67 ( V_1 ) ;
V_10 -> V_77 = false ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_49 ( V_10 -> V_77 ) )
return;
F_69 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_78 ) ;
F_8 ( V_3 ) ;
V_10 -> V_77 = true ;
}
static int F_70 ( struct V_2 * V_3 ,
struct V_79 * V_66 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
unsigned long V_27 ;
F_13 ( L_7 , V_10 -> V_19 , V_3 -> V_66 -> V_26 ) ;
F_49 ( V_10 -> V_26 ) ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_10 -> V_26 = V_3 -> V_66 -> V_26 ;
F_18 ( & V_6 -> V_28 , V_27 ) ;
F_31 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_81 ) ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_82 * V_83 , T_2 V_33 )
{
return - V_84 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_64 V_65 = V_10 -> V_65 ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_85 . V_86 , V_27 ) ;
if ( V_10 -> V_85 . V_87 ) {
struct V_88 * V_89 = V_10 -> V_85 . V_89 ;
struct V_88 * V_90 = V_10 -> V_85 . V_91 ;
T_1 V_92 = V_10 -> V_85 . V_93 ;
if ( V_89 ) {
F_75 ( V_89 ) ;
F_76 ( V_89 , V_1 -> V_30 , & V_92 ) ;
F_14 ( V_1 , F_77 ( V_65 ) ,
F_78 ( V_10 -> V_85 . V_94 ) |
F_79 ( V_10 -> V_85 . V_95 ) ) ;
F_14 ( V_1 , F_80 ( V_65 ) , V_92 ) ;
F_14 ( V_1 , F_81 ( V_65 ) ,
F_82 ( V_96 ) |
V_97 ) ;
} else {
F_14 ( V_1 , F_80 ( V_65 ) ,
V_1 -> V_98 ) ;
}
if ( V_90 )
F_83 ( & V_10 -> V_34 , V_90 ) ;
V_10 -> V_85 . V_91 = V_89 ;
V_10 -> V_85 . V_87 = false ;
}
F_14 ( V_1 , F_84 ( V_65 ) ,
F_85 ( V_10 -> V_85 . V_99 ) |
F_86 ( V_10 -> V_85 . V_100 ) ) ;
F_18 ( & V_10 -> V_85 . V_86 , V_27 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_22 * V_29 , T_1 V_101 ,
T_1 V_94 , T_1 V_95 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_88 * V_102 , * V_103 ;
unsigned long V_27 ;
T_1 V_92 ;
int V_104 ;
if ( ( V_94 > V_105 ) || ( V_95 > V_106 ) ) {
F_88 ( V_6 -> V_6 , L_8 , V_94 , V_95 ) ;
return - V_84 ;
}
if ( V_101 ) {
V_102 = F_89 ( V_6 , V_29 , V_101 ) ;
if ( ! V_102 )
return - V_107 ;
} else {
V_102 = NULL ;
}
if ( V_102 ) {
V_104 = F_90 ( V_102 , V_1 -> V_30 , & V_92 ) ;
if ( V_104 )
goto V_108;
} else {
V_92 = 0 ;
}
F_16 ( & V_10 -> V_85 . V_86 , V_27 ) ;
V_103 = V_10 -> V_85 . V_89 ;
V_10 -> V_85 . V_89 = V_102 ;
V_10 -> V_85 . V_93 = V_92 ;
V_10 -> V_85 . V_94 = V_94 ;
V_10 -> V_85 . V_95 = V_95 ;
V_10 -> V_85 . V_87 = true ;
F_18 ( & V_10 -> V_85 . V_86 , V_27 ) ;
if ( V_103 ) {
F_83 ( & V_10 -> V_34 , V_103 ) ;
}
F_4 ( V_3 , V_109 ) ;
return 0 ;
V_108:
F_22 ( V_102 ) ;
return V_104 ;
}
static int F_91 ( struct V_2 * V_3 , int V_99 , int V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_85 . V_86 , V_27 ) ;
V_10 -> V_85 . V_99 = V_99 ;
V_10 -> V_85 . V_100 = V_100 ;
F_18 ( & V_10 -> V_85 . V_86 , V_27 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_109 ) ;
return 0 ;
}
static void F_92 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_66 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_93 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_81 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_109 ) {
F_74 ( V_3 ) ;
F_94 ( & V_10 -> V_34 , V_5 -> V_113 ) ;
}
}
static void F_95 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_78 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_9 , V_10 -> V_19 , V_112 ) ;
F_8 ( V_3 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_104 ;
V_104 = F_97 ( V_3 ) ;
if ( V_104 )
return;
V_104 = F_98 ( V_6 -> V_12 [ F_99 ( V_3 ) ] . V_114 ,
! ( F_100 ( V_1 , V_21 ) &
V_10 -> V_20 ) ,
F_101 ( 50 ) ) ;
if ( V_104 <= 0 )
F_102 ( V_6 -> V_6 , L_10 , V_10 -> V_30 ) ;
V_10 -> V_20 = 0 ;
F_103 ( V_3 ) ;
}
T_1 F_104 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_115 ;
}
void F_105 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_23 ) ;
F_15 ( V_3 , V_23 ) ;
}
void F_106 ( struct V_2 * V_3 , T_1 V_39 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_107 ( V_10 -> V_65 ) , V_39 ) ;
}
void F_108 ( struct V_2 * V_3 , enum V_116 V_117 , int V_51 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_118 ;
V_118 = F_100 ( V_1 , V_119 ) ;
switch ( V_10 -> V_65 ) {
case V_120 :
V_118 &= ~ V_121 ;
V_118 |= F_109 ( V_117 ) ;
break;
case V_122 :
V_118 &= ~ V_123 ;
V_118 |= F_110 ( V_117 ) ;
break;
case V_76 :
V_118 &= ~ V_124 ;
V_118 |= F_111 ( V_117 ) ;
break;
}
if ( V_117 == V_125 ) {
V_118 &= ~ V_126 ;
V_118 |= V_127 ;
} else if ( V_117 == V_128 ) {
V_118 &= ~ V_127 ;
V_118 |= V_126 ;
}
V_10 -> V_51 = V_51 ;
F_31 ( V_3 ) ;
F_13 ( L_12 , V_10 -> V_19 , V_118 ) ;
F_14 ( V_1 , V_119 , V_118 ) ;
}
void F_112 ( struct V_2 * V_3 )
{
F_96 ( V_3 ) ;
}
struct V_2 * F_113 ( struct V_24 * V_6 ,
struct V_13 * V_14 , int V_30 , int V_129 ,
enum V_64 V_130 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_114 ( sizeof( * V_10 ) , V_131 ) ;
if ( ! V_10 )
return F_115 ( - V_132 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_30 = V_30 ;
V_10 -> V_18 = V_129 ;
V_10 -> V_65 = V_130 ;
V_10 -> V_12 . V_115 = F_116 ( V_10 -> V_65 ) ;
V_10 -> V_12 . V_111 = F_92 ;
V_10 -> V_78 . V_115 = F_117 ( V_10 -> V_65 ) ;
V_10 -> V_78 . V_111 = F_95 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_13 ,
V_133 [ V_130 ] , V_129 ) ;
F_118 ( & V_10 -> V_85 . V_86 ) ;
F_119 ( & V_10 -> V_34 ,
L_14 , F_19 ) ;
F_120 ( V_6 , V_3 , V_14 , NULL , & V_134 ,
NULL ) ;
F_121 ( V_3 , & V_135 ) ;
V_14 -> V_3 = V_3 ;
return V_3 ;
}
