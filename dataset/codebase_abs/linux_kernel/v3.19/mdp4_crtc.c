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
static void F_27 ( struct V_2 * V_3 , int V_34 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_35 = ( V_34 == V_36 ) ;
F_13 ( L_3 , V_10 -> V_19 , V_34 ) ;
if ( V_35 != V_10 -> V_35 ) {
if ( V_35 ) {
F_28 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_37 ) ;
} else {
F_29 ( & V_1 -> V_11 , & V_10 -> V_37 ) ;
F_30 ( V_1 ) ;
}
V_10 -> V_35 = V_35 ;
}
}
static bool F_31 ( struct V_2 * V_3 ,
const struct V_38 * V_34 ,
struct V_38 * V_39 )
{
return true ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_40 * V_41 = & V_1 -> V_6 -> V_42 ;
struct V_2 * V_3 ;
T_1 V_43 = 0 ;
static const enum V_44 V_45 [] = {
V_46 , V_47 , V_48 , V_49 , V_50 ,
} ;
F_33 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_51 = V_52 [ V_17 ] ;
V_43 = F_34 ( V_43 , V_10 -> V_53 ,
V_17 , V_45 [ V_51 ] ) ;
}
}
F_14 ( V_1 , V_54 , V_43 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_55 , V_18 = V_10 -> V_18 ;
bool V_56 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_36 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_37 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_38 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_39 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_51 = V_52 [ V_17 ] ;
if ( V_51 > 0 ) {
const struct V_57 * V_58 =
F_40 ( F_41 ( V_14 -> V_59 ) ) ;
V_56 [ V_51 - 1 ] = V_58 -> V_60 ;
}
}
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
T_1 V_61 ;
if ( V_56 [ V_55 ] ) {
V_61 = F_42 ( V_62 ) |
F_43 ( V_62 ) |
V_63 ;
} else {
V_61 = F_42 ( V_64 ) |
F_43 ( V_65 ) ;
}
F_14 ( V_1 , F_44 ( V_18 , V_55 ) , 0xff ) ;
F_14 ( V_1 , F_45 ( V_18 , V_55 ) , 0x00 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_55 ) , V_61 ) ;
F_14 ( V_1 , F_47 ( V_18 , V_55 ) , 1 ) ;
F_14 ( V_1 , F_48 ( V_18 , V_55 ) , 0 ) ;
F_14 ( V_1 , F_49 ( V_18 , V_55 ) , 0 ) ;
F_14 ( V_1 , F_50 ( V_18 , V_55 ) , 0 ) ;
F_14 ( V_1 , F_51 ( V_18 , V_55 ) , 0 ) ;
}
F_32 ( V_1 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_66 V_67 = V_10 -> V_67 ;
int V_18 = V_10 -> V_18 ;
struct V_38 * V_34 ;
if ( F_53 ( ! V_3 -> V_68 ) )
return;
V_34 = & V_3 -> V_68 -> V_39 ;
F_13 ( L_4 ,
V_10 -> V_19 , V_34 -> V_11 . V_29 , V_34 -> V_19 ,
V_34 -> V_69 , V_34 -> clock ,
V_34 -> V_70 , V_34 -> V_71 ,
V_34 -> V_72 , V_34 -> V_73 ,
V_34 -> V_74 , V_34 -> V_75 ,
V_34 -> V_76 , V_34 -> V_77 ,
V_34 -> type , V_34 -> V_26 ) ;
F_14 ( V_1 , F_54 ( V_67 ) ,
F_55 ( V_34 -> V_70 ) |
F_56 ( V_34 -> V_74 ) ) ;
F_14 ( V_1 , F_57 ( V_67 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_67 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_67 ) ,
F_60 ( 0 ) |
F_61 ( 0 ) ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_63 ( V_18 ) ,
F_64 ( V_34 -> V_70 ) |
F_65 ( V_34 -> V_74 ) ) ;
F_14 ( V_1 , F_66 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_67 ( V_18 ) , 1 ) ;
if ( V_67 == V_78 ) {
F_14 ( V_1 , F_68 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_68 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_68 ( 2 ) , 0x00ff0000 ) ;
}
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
F_70 ( V_3 ) ;
F_28 ( F_1 ( V_3 ) ) ;
F_27 ( V_3 , V_79 ) ;
}
static void F_71 ( struct V_2 * V_3 )
{
F_27 ( V_3 , V_36 ) ;
F_8 ( V_3 ) ;
F_30 ( F_1 ( V_3 ) ) ;
F_72 ( V_3 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
}
static int F_74 ( struct V_2 * V_3 ,
struct V_80 * V_68 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_7 , V_10 -> V_19 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_23 * V_6 = V_3 -> V_6 ;
unsigned long V_26 ;
F_13 ( L_8 , V_10 -> V_19 , V_3 -> V_68 -> V_25 ) ;
F_53 ( V_10 -> V_25 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
V_10 -> V_25 = V_3 -> V_68 -> V_25 ;
F_18 ( & V_6 -> V_27 , V_26 ) ;
F_35 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_81 ) ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_82 * V_83 , T_2 V_32 )
{
return - V_84 ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_66 V_67 = V_10 -> V_67 ;
unsigned long V_26 ;
F_16 ( & V_10 -> V_85 . V_86 , V_26 ) ;
if ( V_10 -> V_85 . V_87 ) {
struct V_88 * V_89 = V_10 -> V_85 . V_89 ;
struct V_88 * V_90 = V_10 -> V_85 . V_91 ;
T_1 V_92 = V_10 -> V_85 . V_93 ;
if ( V_89 ) {
F_79 ( V_89 ) ;
F_80 ( V_89 , V_1 -> V_29 , & V_92 ) ;
F_14 ( V_1 , F_81 ( V_67 ) ,
F_82 ( V_10 -> V_85 . V_94 ) |
F_83 ( V_10 -> V_85 . V_95 ) ) ;
F_14 ( V_1 , F_84 ( V_67 ) , V_92 ) ;
F_14 ( V_1 , F_85 ( V_67 ) ,
F_86 ( V_96 ) |
V_97 ) ;
} else {
F_14 ( V_1 , F_84 ( V_67 ) ,
V_1 -> V_98 ) ;
}
if ( V_90 )
F_87 ( & V_10 -> V_33 , V_90 ) ;
V_10 -> V_85 . V_91 = V_89 ;
V_10 -> V_85 . V_87 = false ;
}
F_14 ( V_1 , F_88 ( V_67 ) ,
F_89 ( V_10 -> V_85 . V_99 ) |
F_90 ( V_10 -> V_85 . V_100 ) ) ;
F_18 ( & V_10 -> V_85 . V_86 , V_26 ) ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_21 * V_28 , T_1 V_101 ,
T_1 V_94 , T_1 V_95 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_6 = V_3 -> V_6 ;
struct V_88 * V_102 , * V_103 ;
unsigned long V_26 ;
T_1 V_92 ;
int V_104 ;
if ( ( V_94 > V_105 ) || ( V_95 > V_106 ) ) {
F_92 ( V_6 -> V_6 , L_9 , V_94 , V_95 ) ;
return - V_84 ;
}
if ( V_101 ) {
V_102 = F_93 ( V_6 , V_28 , V_101 ) ;
if ( ! V_102 )
return - V_107 ;
} else {
V_102 = NULL ;
}
if ( V_102 ) {
V_104 = F_94 ( V_102 , V_1 -> V_29 , & V_92 ) ;
if ( V_104 )
goto V_108;
} else {
V_92 = 0 ;
}
F_16 ( & V_10 -> V_85 . V_86 , V_26 ) ;
V_103 = V_10 -> V_85 . V_89 ;
V_10 -> V_85 . V_89 = V_102 ;
V_10 -> V_85 . V_93 = V_92 ;
V_10 -> V_85 . V_94 = V_94 ;
V_10 -> V_85 . V_95 = V_95 ;
V_10 -> V_85 . V_87 = true ;
F_18 ( & V_10 -> V_85 . V_86 , V_26 ) ;
if ( V_103 ) {
F_87 ( & V_10 -> V_33 , V_103 ) ;
}
F_4 ( V_3 , V_109 ) ;
return 0 ;
V_108:
F_22 ( V_102 ) ;
return V_104 ;
}
static int F_95 ( struct V_2 * V_3 , int V_99 , int V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_26 ;
F_16 ( & V_10 -> V_85 . V_86 , V_26 ) ;
V_10 -> V_85 . V_99 = V_99 ;
V_10 -> V_85 . V_100 = V_100 ;
F_18 ( & V_10 -> V_85 . V_86 , V_26 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_109 ) ;
return 0 ;
}
static void F_96 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_29 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_97 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_81 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_109 ) {
F_78 ( V_3 ) ;
F_98 ( & V_10 -> V_33 , V_5 -> V_113 ) ;
}
}
static void F_99 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_37 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_10 , V_10 -> V_19 , V_112 ) ;
F_8 ( V_3 ) ;
}
T_1 F_100 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_114 ;
}
void F_101 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_22 ) ;
F_15 ( V_3 , V_22 ) ;
}
void F_102 ( struct V_2 * V_3 , T_1 V_41 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_103 ( V_10 -> V_67 ) , V_41 ) ;
}
void F_104 ( struct V_2 * V_3 , enum V_115 V_116 , int V_53 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_117 ;
V_117 = F_105 ( V_1 , V_118 ) ;
switch ( V_10 -> V_67 ) {
case V_119 :
V_117 &= ~ V_120 ;
V_117 |= F_106 ( V_116 ) ;
break;
case V_121 :
V_117 &= ~ V_122 ;
V_117 |= F_107 ( V_116 ) ;
break;
case V_78 :
V_117 &= ~ V_123 ;
V_117 |= F_108 ( V_116 ) ;
break;
}
if ( V_116 == V_124 ) {
V_117 &= ~ V_125 ;
V_117 |= V_126 ;
} else if ( V_116 == V_127 ) {
V_117 &= ~ V_126 ;
V_117 |= V_125 ;
}
V_10 -> V_53 = V_53 ;
F_35 ( V_3 ) ;
F_13 ( L_12 , V_10 -> V_19 , V_117 ) ;
F_14 ( V_1 , V_118 , V_117 ) ;
}
struct V_2 * F_109 ( struct V_23 * V_6 ,
struct V_13 * V_14 , int V_29 , int V_128 ,
enum V_66 V_129 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_110 ( sizeof( * V_10 ) , V_130 ) ;
if ( ! V_10 )
return F_111 ( - V_131 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_18 = V_128 ;
V_10 -> V_67 = V_129 ;
V_10 -> V_12 . V_114 = F_112 ( V_10 -> V_67 ) ;
V_10 -> V_12 . V_111 = F_96 ;
V_10 -> V_37 . V_114 = F_113 ( V_10 -> V_67 ) ;
V_10 -> V_37 . V_111 = F_99 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_13 ,
V_132 [ V_129 ] , V_128 ) ;
F_114 ( & V_10 -> V_85 . V_86 ) ;
F_115 ( & V_10 -> V_33 ,
L_14 , F_19 ) ;
F_116 ( V_6 , V_3 , V_14 , NULL , & V_133 ) ;
F_117 ( V_3 , & V_134 ) ;
V_14 -> V_3 = V_3 ;
F_118 ( V_14 , & V_3 -> V_11 ) ;
return V_3 ;
}
