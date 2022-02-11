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
F_9 ( & V_10 -> V_13 ) ;
}
static T_2 F_10 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_1 , V_10 -> V_15 , V_14 ) ;
return F_12 ( V_10 -> V_16 , V_14 ) ;
}
static T_2 F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_17 * V_18 ;
T_1 V_14 = 0 ;
if ( F_14 ( ! V_10 -> V_16 ) )
return 0 ;
F_15 (plane, crtc) {
V_14 |= F_16 ( V_18 ) ;
}
V_14 |= F_17 ( V_10 -> V_19 ) ;
return F_10 ( V_3 , V_14 ) ;
}
static void F_18 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_23 * V_24 ;
struct V_17 * V_18 ;
unsigned long V_25 ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_24 = V_10 -> V_24 ;
if ( V_24 ) {
if ( ! V_21 || ( V_24 -> V_11 . V_27 == V_21 ) ) {
V_10 -> V_24 = NULL ;
F_11 ( L_2 , V_10 -> V_15 , V_24 ) ;
F_20 ( V_3 , V_24 ) ;
}
}
F_21 ( & V_6 -> V_26 , V_25 ) ;
F_15 (plane, crtc) {
F_22 ( V_18 ) ;
}
if ( V_10 -> V_16 && ! V_3 -> V_28 -> V_29 ) {
F_23 ( V_10 -> V_16 , NULL , 0 , 0 ) ;
V_10 -> V_16 = NULL ;
}
}
static void F_24 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_25 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_26 ( V_32 , V_1 -> V_34 ) ;
F_27 ( V_32 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_10 -> V_33 ) ;
F_31 ( V_10 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
const struct V_35 * V_36 ;
struct V_37 * V_38 , * V_39 [ V_40 + 1 ] = { NULL } ;
const struct V_41 * V_42 ;
T_1 V_19 = V_10 -> V_19 ;
T_1 V_43 , V_44 , V_45 , V_46 = 0 ;
unsigned long V_25 ;
T_3 V_47 [ V_40 + 1 ] ;
int V_48 , V_49 = 0 ;
#define F_33 ( V_47 ) ((stage) - STAGE0)
V_36 = F_34 ( V_1 -> V_50 ) ;
F_19 ( & V_10 -> V_51 , V_25 ) ;
if ( ! V_10 -> V_16 )
goto V_52;
F_15 (plane, crtc) {
V_38 = F_35 ( V_18 -> V_28 ) ;
V_39 [ V_38 -> V_47 ] = V_38 ;
V_47 [ V_38 -> V_47 ] = F_36 ( V_18 ) ;
V_49 ++ ;
}
if ( ! V_39 [ V_53 ] && V_49 ) {
V_46 |= V_54 ;
F_11 ( L_3 ) ;
}
for ( V_48 = V_55 ; V_48 <= V_40 ; V_48 ++ ) {
if ( ! V_39 [ V_48 ] )
continue;
V_42 = F_37 (
F_38 ( V_39 [ V_48 ] -> V_11 . V_56 ) ) ;
V_18 = V_39 [ V_48 ] -> V_11 . V_18 ;
V_43 = F_39 ( V_57 ) |
F_40 ( V_58 ) ;
V_44 = V_39 [ V_48 ] -> V_59 ;
V_45 = 0xFF - V_39 [ V_48 ] -> V_59 ;
F_11 ( L_4 , V_48 , V_44 , V_45 ) ;
if ( V_42 -> V_60 && V_39 [ V_48 ] -> V_61 ) {
V_43 = F_39 ( V_57 ) |
F_40 ( V_62 ) ;
if ( V_44 != 0xff ) {
V_45 = V_44 ;
V_43 |=
V_63 |
V_64 ;
} else {
V_43 |= V_65 ;
}
} else if ( V_42 -> V_60 ) {
V_43 = F_39 ( V_62 ) |
F_40 ( V_62 ) ;
if ( V_44 != 0xff ) {
V_45 = V_44 ;
V_43 |=
V_66 |
V_67 |
V_63 |
V_64 ;
} else {
V_43 |= V_65 ;
}
}
F_41 ( V_1 , F_42 ( V_19 ,
F_33 ( V_48 ) ) , V_43 ) ;
F_41 ( V_1 , F_43 ( V_19 ,
F_33 ( V_48 ) ) , V_44 ) ;
F_41 ( V_1 , F_44 ( V_19 ,
F_33 ( V_48 ) ) , V_45 ) ;
}
F_23 ( V_10 -> V_16 , V_47 , V_49 , V_46 ) ;
V_52:
F_21 ( & V_10 -> V_51 , V_25 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_25 ;
struct V_68 * V_69 ;
if ( F_14 ( ! V_3 -> V_28 ) )
return;
V_69 = & V_3 -> V_28 -> V_70 ;
F_11 ( L_5 ,
V_10 -> V_15 , V_69 -> V_11 . V_34 , V_69 -> V_15 ,
V_69 -> V_71 , V_69 -> clock ,
V_69 -> V_72 , V_69 -> V_73 ,
V_69 -> V_74 , V_69 -> V_75 ,
V_69 -> V_76 , V_69 -> V_77 ,
V_69 -> V_78 , V_69 -> V_79 ,
V_69 -> type , V_69 -> V_25 ) ;
F_19 ( & V_10 -> V_51 , V_25 ) ;
F_41 ( V_1 , F_46 ( V_10 -> V_19 ) ,
F_47 ( V_69 -> V_72 ) |
F_48 ( V_69 -> V_76 ) ) ;
F_21 ( & V_10 -> V_51 , V_25 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( ! V_10 -> V_80 ) )
return;
if ( V_10 -> V_81 )
F_50 ( & V_1 -> V_11 , & V_10 -> V_82 ) ;
F_50 ( & V_1 -> V_11 , & V_10 -> V_83 ) ;
F_51 ( V_1 ) ;
V_10 -> V_80 = false ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( V_10 -> V_80 ) )
return;
F_53 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_83 ) ;
if ( V_10 -> V_81 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_82 ) ;
V_10 -> V_80 = true ;
}
static int F_54 ( const void * V_84 , const void * V_85 )
{
struct V_86 * V_87 = (struct V_86 * ) V_84 ;
struct V_86 * V_88 = (struct V_86 * ) V_85 ;
return V_87 -> V_28 -> V_89 - V_88 -> V_28 -> V_89 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_90 * V_28 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_86 V_39 [ V_40 + 1 ] ;
const struct V_35 * V_36 ;
const struct V_91 * V_38 ;
int V_92 = 0 , V_48 ;
F_11 ( L_7 , V_10 -> V_15 ) ;
V_36 = F_34 ( V_1 -> V_50 ) ;
F_56 (plane, pstate, state) {
if ( V_92 >= ( V_36 -> V_19 . V_93 ) ) {
F_57 ( V_6 -> V_6 , L_8 ) ;
return - V_94 ;
}
V_39 [ V_92 ] . V_18 = V_18 ;
V_39 [ V_92 ] . V_28 = F_35 ( V_38 ) ;
V_92 ++ ;
}
F_58 ( V_39 , V_92 , sizeof( V_39 [ 0 ] ) , F_54 , NULL ) ;
for ( V_48 = 0 ; V_48 < V_92 ; V_48 ++ ) {
V_39 [ V_48 ] . V_28 -> V_47 = V_53 + V_48 ;
F_11 ( L_9 , V_10 -> V_15 ,
F_59 ( F_36 ( V_39 [ V_48 ] . V_18 ) ) ,
V_39 [ V_48 ] . V_28 -> V_47 ) ;
}
return 0 ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_90 * V_95 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_10 , V_10 -> V_15 ) ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_90 * V_95 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
unsigned long V_25 ;
F_11 ( L_11 , V_10 -> V_15 , V_3 -> V_28 -> V_24 ) ;
F_14 ( V_10 -> V_24 ) ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_3 -> V_28 -> V_24 ;
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( F_62 ( ! V_10 -> V_16 ) )
return;
F_32 ( V_3 ) ;
if ( V_10 -> V_81 )
F_8 ( V_3 ) ;
V_10 -> V_96 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_97 ) ;
}
static void F_63 ( struct V_2 * V_3 , T_1 * V_98 , T_1 * V_99 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_100 = V_3 -> V_69 . V_72 ;
T_1 V_101 = V_3 -> V_69 . V_76 ;
* V_98 = F_64 ( V_10 -> V_102 . V_103 , V_100 -
V_10 -> V_102 . V_104 ) ;
* V_99 = F_64 ( V_10 -> V_102 . V_105 , V_101 -
V_10 -> V_102 . V_106 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_107 ,
T_1 V_103 , T_1 V_105 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_108 * V_109 , * V_110 = NULL ;
T_1 V_111 , V_112 , V_113 ;
int V_114 , V_19 ;
enum V_115 V_116 = V_117 ;
T_1 V_14 = F_66 ( 0 ) ;
T_1 V_98 , V_99 ;
bool V_118 = true ;
unsigned long V_25 ;
if ( ( V_103 > V_119 ) || ( V_105 > V_120 ) ) {
F_57 ( V_6 -> V_6 , L_12 , V_103 , V_105 ) ;
return - V_94 ;
}
if ( NULL == V_10 -> V_16 )
return - V_94 ;
if ( ! V_107 ) {
F_11 ( L_13 ) ;
V_118 = false ;
goto V_121;
}
V_109 = F_67 ( V_21 , V_107 ) ;
if ( ! V_109 )
return - V_122 ;
V_114 = F_68 ( V_109 , V_1 -> V_34 , & V_112 ) ;
if ( V_114 )
return - V_94 ;
V_19 = V_10 -> V_19 ;
V_113 = V_103 * F_69 ( V_123 , 0 ) ;
F_19 ( & V_10 -> V_102 . V_124 , V_25 ) ;
V_110 = V_10 -> V_102 . V_125 ;
V_10 -> V_102 . V_125 = V_109 ;
V_10 -> V_102 . V_103 = V_103 ;
V_10 -> V_102 . V_105 = V_105 ;
F_63 ( V_3 , & V_98 , & V_99 ) ;
F_41 ( V_1 , F_70 ( V_19 ) , V_113 ) ;
F_41 ( V_1 , F_71 ( V_19 ) ,
F_72 ( V_126 ) ) ;
F_41 ( V_1 , F_73 ( V_19 ) ,
F_74 ( V_105 ) |
F_75 ( V_103 ) ) ;
F_41 ( V_1 , F_76 ( V_19 ) ,
F_77 ( V_99 ) |
F_78 ( V_98 ) ) ;
F_41 ( V_1 , F_79 ( V_19 ) , V_112 ) ;
V_111 = V_127 ;
V_111 |= F_80 ( V_116 ) ;
F_41 ( V_1 , F_81 ( V_19 ) , V_111 ) ;
F_21 ( & V_10 -> V_102 . V_124 , V_25 ) ;
V_121:
V_114 = F_82 ( V_10 -> V_16 , 0 , V_118 ) ;
if ( V_114 ) {
F_57 ( V_6 -> V_6 , L_14 ,
V_118 ? L_15 : L_16 , V_114 ) ;
goto V_128;
}
F_10 ( V_3 , V_14 ) ;
V_128:
if ( V_110 ) {
F_83 ( & V_10 -> V_33 , V_110 ) ;
F_4 ( V_3 , V_129 ) ;
}
return V_114 ;
}
static int F_84 ( struct V_2 * V_3 , int V_104 , int V_106 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_66 ( 0 ) ;
T_1 V_98 ;
T_1 V_99 ;
unsigned long V_25 ;
if ( F_62 ( ! V_3 -> V_28 -> V_29 ) )
return 0 ;
V_10 -> V_102 . V_104 = V_104 = F_85 ( V_104 , 0 ) ;
V_10 -> V_102 . V_106 = V_106 = F_85 ( V_106 , 0 ) ;
F_63 ( V_3 , & V_98 , & V_99 ) ;
F_19 ( & V_10 -> V_102 . V_124 , V_25 ) ;
F_41 ( V_1 , F_76 ( V_10 -> V_19 ) ,
F_77 ( V_99 ) |
F_78 ( V_98 ) ) ;
F_41 ( V_1 , F_86 ( V_10 -> V_19 ) ,
F_87 ( V_106 ) |
F_88 ( V_104 ) ) ;
F_21 ( & V_10 -> V_102 . V_124 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_89 ( struct V_130 * V_131 , T_1 V_132 )
{
struct V_10 * V_10 = F_25 ( V_131 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_50 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_90 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_97 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_129 )
F_91 ( & V_10 -> V_33 , V_5 -> V_133 ) ;
}
static void F_92 ( struct V_130 * V_131 , T_1 V_132 )
{
struct V_10 * V_10 = F_25 ( V_131 , struct V_10 , V_83 ) ;
F_11 ( L_17 , V_10 -> V_15 , V_132 ) ;
}
static void F_93 ( struct V_130 * V_131 , T_1 V_132 )
{
struct V_10 * V_10 = F_25 ( V_131 , struct V_10 ,
V_82 ) ;
F_94 ( & V_10 -> V_13 ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_114 ;
V_114 = F_96 ( & V_10 -> V_13 ,
F_97 ( 50 ) ) ;
if ( V_114 == 0 )
F_98 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_114 ;
if ( ! V_10 -> V_16 )
return;
V_114 = F_100 ( V_3 ) ;
if ( V_114 )
return;
V_114 = F_101 ( V_6 -> V_12 [ F_102 ( V_3 ) ] . V_134 ,
( ( F_103 ( V_10 -> V_16 ) &
V_10 -> V_96 ) == 0 ) ,
F_97 ( 50 ) ) ;
if ( V_114 <= 0 )
F_98 ( V_6 -> V_6 , L_19 , V_10 -> V_34 ) ;
V_10 -> V_96 = 0 ;
F_104 ( V_3 ) ;
}
T_1 F_105 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_135 ;
}
void F_106 ( struct V_2 * V_3 ,
struct V_136 * V_137 , struct V_138 * V_16 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_107 ( V_3 ) ;
V_10 -> V_83 . V_135 = F_108 ( V_137 -> V_139 ) ;
V_10 -> V_12 . V_135 = F_109 ( V_19 , V_137 ) ;
if ( ( V_137 -> type == V_140 ) &&
( V_137 -> V_69 == V_141 ) ) {
V_10 -> V_82 . V_135 = F_110 ( V_19 ) ;
V_10 -> V_82 . V_131 = F_93 ;
V_10 -> V_81 = true ;
} else {
V_10 -> V_82 . V_135 = 0 ;
V_10 -> V_82 . V_131 = NULL ;
V_10 -> V_81 = false ;
}
F_111 ( & V_1 -> V_11 ) ;
V_10 -> V_16 = V_16 ;
F_112 ( V_16 , V_137 , V_19 ) ;
}
int F_107 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_94 : V_10 -> V_19 ;
}
void F_113 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( V_10 -> V_81 )
F_95 ( V_3 ) ;
else
F_99 ( V_3 ) ;
}
struct V_2 * F_114 ( struct V_22 * V_6 ,
struct V_17 * V_18 , int V_34 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_115 ( sizeof( * V_10 ) , V_142 ) ;
if ( ! V_10 )
return F_116 ( - V_143 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_34 = V_34 ;
V_10 -> V_19 = F_117 ( V_34 ) ;
F_118 ( & V_10 -> V_51 ) ;
F_118 ( & V_10 -> V_102 . V_124 ) ;
F_119 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_131 = F_89 ;
V_10 -> V_83 . V_131 = F_92 ;
snprintf ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) , L_20 ,
F_59 ( F_36 ( V_18 ) ) , V_34 ) ;
F_120 ( V_6 , V_3 , V_18 , NULL , & V_144 ,
NULL ) ;
F_121 ( & V_10 -> V_33 ,
L_21 , F_24 ) ;
F_122 ( V_3 , & V_145 ) ;
V_18 -> V_3 = V_3 ;
return V_3 ;
}
