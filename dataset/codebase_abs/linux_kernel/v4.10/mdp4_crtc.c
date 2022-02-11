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
F_17 ( V_3 , V_26 ) ;
}
}
F_18 ( & V_6 -> V_28 , V_27 ) ;
}
static void F_19 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_20 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_21 ( V_32 , V_1 -> V_34 ) ;
F_22 ( V_32 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_24 ( V_3 ) ;
F_25 ( & V_10 -> V_33 ) ;
F_26 ( V_10 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_35 * V_36 = & V_1 -> V_6 -> V_37 ;
struct V_2 * V_3 ;
T_1 V_38 = 0 ;
static const enum V_39 V_40 [] = {
V_41 , V_42 , V_43 , V_44 , V_45 ,
} ;
F_28 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_46 = V_47 [ V_17 ] ;
V_38 = F_29 ( V_38 , V_10 -> V_48 ,
V_17 , V_40 [ V_46 ] ) ;
}
}
F_14 ( V_1 , V_49 , V_38 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_50 , V_18 = V_10 -> V_18 ;
bool V_51 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_31 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_32 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_33 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_34 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_46 = V_47 [ V_17 ] ;
if ( V_46 > 0 ) {
const struct V_52 * V_53 =
F_35 ( F_36 ( V_14 -> V_54 ) ) ;
V_51 [ V_46 - 1 ] = V_53 -> V_55 ;
}
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
T_1 V_56 ;
if ( V_51 [ V_50 ] ) {
V_56 = F_37 ( V_57 ) |
F_38 ( V_57 ) |
V_58 ;
} else {
V_56 = F_37 ( V_59 ) |
F_38 ( V_60 ) ;
}
F_14 ( V_1 , F_39 ( V_18 , V_50 ) , 0xff ) ;
F_14 ( V_1 , F_40 ( V_18 , V_50 ) , 0x00 ) ;
F_14 ( V_1 , F_41 ( V_18 , V_50 ) , V_56 ) ;
F_14 ( V_1 , F_42 ( V_18 , V_50 ) , 1 ) ;
F_14 ( V_1 , F_43 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_50 ) , 0 ) ;
}
F_27 ( V_1 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_61 V_62 = V_10 -> V_62 ;
int V_18 = V_10 -> V_18 ;
struct V_63 * V_64 ;
if ( F_48 ( ! V_3 -> V_65 ) )
return;
V_64 = & V_3 -> V_65 -> V_66 ;
F_13 ( L_3 ,
V_10 -> V_19 , V_64 -> V_11 . V_34 , V_64 -> V_19 ,
V_64 -> V_67 , V_64 -> clock ,
V_64 -> V_68 , V_64 -> V_69 ,
V_64 -> V_70 , V_64 -> V_71 ,
V_64 -> V_72 , V_64 -> V_73 ,
V_64 -> V_74 , V_64 -> V_75 ,
V_64 -> type , V_64 -> V_27 ) ;
F_14 ( V_1 , F_49 ( V_62 ) ,
F_50 ( V_64 -> V_68 ) |
F_51 ( V_64 -> V_72 ) ) ;
F_14 ( V_1 , F_52 ( V_62 ) , 0 ) ;
F_14 ( V_1 , F_53 ( V_62 ) , 0 ) ;
F_14 ( V_1 , F_54 ( V_62 ) ,
F_55 ( 0 ) |
F_56 ( 0 ) ) ;
F_14 ( V_1 , F_57 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_18 ) ,
F_59 ( V_64 -> V_68 ) |
F_60 ( V_64 -> V_72 ) ) ;
F_14 ( V_1 , F_61 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 1 ) ;
if ( V_62 == V_76 ) {
F_14 ( V_1 , F_63 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_63 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_63 ( 2 ) , 0x00ff0000 ) ;
}
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_48 ( ! V_10 -> V_77 ) )
return;
F_65 ( & V_1 -> V_11 , & V_10 -> V_78 ) ;
F_66 ( V_1 ) ;
V_10 -> V_77 = false ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_48 ( V_10 -> V_77 ) )
return;
F_68 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_78 ) ;
F_8 ( V_3 ) ;
V_10 -> V_77 = true ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_79 * V_65 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
unsigned long V_27 ;
F_13 ( L_7 , V_10 -> V_19 , V_3 -> V_65 -> V_26 ) ;
F_48 ( V_10 -> V_26 ) ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_10 -> V_26 = V_3 -> V_65 -> V_26 ;
F_18 ( & V_6 -> V_28 , V_27 ) ;
F_30 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_81 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_61 V_62 = V_10 -> V_62 ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_82 . V_83 , V_27 ) ;
if ( V_10 -> V_82 . V_84 ) {
struct V_85 * V_86 = V_10 -> V_82 . V_86 ;
struct V_85 * V_87 = V_10 -> V_82 . V_88 ;
T_2 V_89 = V_10 -> V_82 . V_90 ;
if ( V_86 ) {
F_73 ( V_86 ) ;
F_74 ( V_86 , V_1 -> V_34 , & V_89 ) ;
F_14 ( V_1 , F_75 ( V_62 ) ,
F_76 ( V_10 -> V_82 . V_91 ) |
F_77 ( V_10 -> V_82 . V_92 ) ) ;
F_14 ( V_1 , F_78 ( V_62 ) , V_89 ) ;
F_14 ( V_1 , F_79 ( V_62 ) ,
F_80 ( V_93 ) |
V_94 ) ;
} else {
F_14 ( V_1 , F_78 ( V_62 ) ,
V_1 -> V_95 ) ;
}
if ( V_87 )
F_81 ( & V_10 -> V_33 , V_87 ) ;
V_10 -> V_82 . V_88 = V_86 ;
V_10 -> V_82 . V_84 = false ;
}
F_14 ( V_1 , F_82 ( V_62 ) ,
F_83 ( V_10 -> V_82 . V_96 ) |
F_84 ( V_10 -> V_82 . V_97 ) ) ;
F_18 ( & V_10 -> V_82 . V_83 , V_27 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_22 * V_29 , T_1 V_98 ,
T_1 V_91 , T_1 V_92 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_85 * V_99 , * V_100 ;
unsigned long V_27 ;
T_2 V_89 ;
int V_101 ;
if ( ( V_91 > V_102 ) || ( V_92 > V_103 ) ) {
F_86 ( V_6 -> V_6 , L_8 , V_91 , V_92 ) ;
return - V_104 ;
}
if ( V_98 ) {
V_99 = F_87 ( V_29 , V_98 ) ;
if ( ! V_99 )
return - V_105 ;
} else {
V_99 = NULL ;
}
if ( V_99 ) {
V_101 = F_88 ( V_99 , V_1 -> V_34 , & V_89 ) ;
if ( V_101 )
goto V_106;
} else {
V_89 = 0 ;
}
F_16 ( & V_10 -> V_82 . V_83 , V_27 ) ;
V_100 = V_10 -> V_82 . V_86 ;
V_10 -> V_82 . V_86 = V_99 ;
V_10 -> V_82 . V_90 = V_89 ;
V_10 -> V_82 . V_91 = V_91 ;
V_10 -> V_82 . V_92 = V_92 ;
V_10 -> V_82 . V_84 = true ;
F_18 ( & V_10 -> V_82 . V_83 , V_27 ) ;
if ( V_100 ) {
F_81 ( & V_10 -> V_33 , V_100 ) ;
}
F_4 ( V_3 , V_107 ) ;
return 0 ;
V_106:
F_22 ( V_99 ) ;
return V_101 ;
}
static int F_89 ( struct V_2 * V_3 , int V_96 , int V_97 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_82 . V_83 , V_27 ) ;
V_10 -> V_82 . V_96 = V_96 ;
V_10 -> V_82 . V_97 = V_97 ;
F_18 ( & V_10 -> V_82 . V_83 , V_27 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_107 ) ;
return 0 ;
}
static void F_90 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_65 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_91 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_81 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_107 ) {
F_72 ( V_3 ) ;
F_92 ( & V_10 -> V_33 , V_5 -> V_111 ) ;
}
}
static void F_93 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_78 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_9 , V_10 -> V_19 , V_110 ) ;
F_8 ( V_3 ) ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_101 ;
V_101 = F_95 ( V_3 ) ;
if ( V_101 )
return;
V_101 = F_96 ( V_6 -> V_12 [ F_97 ( V_3 ) ] . V_112 ,
! ( F_98 ( V_1 , V_21 ) &
V_10 -> V_20 ) ,
F_99 ( 50 ) ) ;
if ( V_101 <= 0 )
F_100 ( V_6 -> V_6 , L_10 , V_10 -> V_34 ) ;
V_10 -> V_20 = 0 ;
F_101 ( V_3 ) ;
}
T_1 F_102 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_113 ;
}
void F_103 ( struct V_2 * V_3 , T_1 V_36 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_104 ( V_10 -> V_62 ) , V_36 ) ;
}
void F_105 ( struct V_2 * V_3 , enum V_114 V_115 , int V_48 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_116 ;
V_116 = F_98 ( V_1 , V_117 ) ;
switch ( V_10 -> V_62 ) {
case V_118 :
V_116 &= ~ V_119 ;
V_116 |= F_106 ( V_115 ) ;
break;
case V_120 :
V_116 &= ~ V_121 ;
V_116 |= F_107 ( V_115 ) ;
break;
case V_76 :
V_116 &= ~ V_122 ;
V_116 |= F_108 ( V_115 ) ;
break;
}
if ( V_115 == V_123 ) {
V_116 &= ~ V_124 ;
V_116 |= V_125 ;
} else if ( V_115 == V_126 ) {
V_116 &= ~ V_125 ;
V_116 |= V_124 ;
}
V_10 -> V_48 = V_48 ;
F_30 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_116 ) ;
F_14 ( V_1 , V_117 , V_116 ) ;
}
void F_109 ( struct V_2 * V_3 )
{
F_94 ( V_3 ) ;
}
struct V_2 * F_110 ( struct V_24 * V_6 ,
struct V_13 * V_14 , int V_34 , int V_127 ,
enum V_61 V_128 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_111 ( sizeof( * V_10 ) , V_129 ) ;
if ( ! V_10 )
return F_112 ( - V_130 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_34 = V_34 ;
V_10 -> V_18 = V_127 ;
V_10 -> V_62 = V_128 ;
V_10 -> V_12 . V_113 = F_113 ( V_10 -> V_62 ) ;
V_10 -> V_12 . V_109 = F_90 ;
V_10 -> V_78 . V_113 = F_114 ( V_10 -> V_62 ) ;
V_10 -> V_78 . V_109 = F_93 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_12 ,
V_131 [ V_128 ] , V_127 ) ;
F_115 ( & V_10 -> V_82 . V_83 ) ;
F_116 ( & V_10 -> V_33 ,
L_13 , F_19 ) ;
F_117 ( V_6 , V_3 , V_14 , NULL , & V_132 ,
NULL ) ;
F_118 ( V_3 , & V_133 ) ;
V_14 -> V_3 = V_3 ;
return V_3 ;
}
