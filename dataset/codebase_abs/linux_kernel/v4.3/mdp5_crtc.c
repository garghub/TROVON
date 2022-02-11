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
F_20 ( V_6 , V_10 -> V_28 , V_24 ) ;
}
}
F_21 ( & V_6 -> V_26 , V_25 ) ;
F_15 (plane, crtc) {
F_22 ( V_18 ) ;
}
if ( V_10 -> V_16 && ! V_3 -> V_29 -> V_30 ) {
F_23 ( V_10 -> V_16 , NULL , 0 , 0 ) ;
V_10 -> V_16 = NULL ;
}
}
static void F_24 ( struct V_31 * V_32 , void * V_33 )
{
struct V_10 * V_10 =
F_25 ( V_32 , struct V_10 , V_34 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_26 ( V_33 , V_1 -> V_28 ) ;
F_27 ( V_33 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_10 -> V_34 ) ;
F_31 ( V_10 ) ;
}
static bool F_32 ( struct V_2 * V_3 ,
const struct V_35 * V_36 ,
struct V_35 * V_37 )
{
return true ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
const struct V_38 * V_39 ;
struct V_40 * V_41 , * V_42 [ V_43 + 1 ] = { NULL } ;
const struct V_44 * V_45 ;
T_1 V_19 = V_10 -> V_19 ;
T_1 V_46 , V_47 , V_48 , V_49 = 0 ;
unsigned long V_25 ;
T_3 V_50 [ V_43 + 1 ] ;
int V_51 , V_52 = 0 ;
#define F_34 ( V_50 ) ((stage) - STAGE0)
V_39 = F_35 ( V_1 -> V_53 ) ;
F_19 ( & V_10 -> V_54 , V_25 ) ;
if ( ! V_10 -> V_16 )
goto V_55;
F_15 (plane, crtc) {
V_41 = F_36 ( V_18 -> V_29 ) ;
V_42 [ V_41 -> V_50 ] = V_41 ;
V_50 [ V_41 -> V_50 ] = F_37 ( V_18 ) ;
V_52 ++ ;
}
if ( ! V_42 [ V_56 ] && V_52 ) {
V_49 |= V_57 ;
F_11 ( L_3 ) ;
}
for ( V_51 = V_58 ; V_51 <= V_43 ; V_51 ++ ) {
if ( ! V_42 [ V_51 ] )
continue;
V_45 = F_38 (
F_39 ( V_42 [ V_51 ] -> V_11 . V_59 ) ) ;
V_18 = V_42 [ V_51 ] -> V_11 . V_18 ;
V_46 = F_40 ( V_60 ) |
F_41 ( V_61 ) ;
V_47 = V_42 [ V_51 ] -> V_62 ;
V_48 = 0xFF - V_42 [ V_51 ] -> V_62 ;
F_11 ( L_4 , V_51 , V_47 , V_48 ) ;
if ( V_45 -> V_63 && V_42 [ V_51 ] -> V_64 ) {
V_46 = F_40 ( V_60 ) |
F_41 ( V_65 ) ;
if ( V_47 != 0xff ) {
V_48 = V_47 ;
V_46 |=
V_66 |
V_67 ;
} else {
V_46 |= V_68 ;
}
} else if ( V_45 -> V_63 ) {
V_46 = F_40 ( V_65 ) |
F_41 ( V_65 ) ;
if ( V_47 != 0xff ) {
V_48 = V_47 ;
V_46 |=
V_69 |
V_70 |
V_66 |
V_67 ;
} else {
V_46 |= V_68 ;
}
}
F_42 ( V_1 , F_43 ( V_19 ,
F_34 ( V_51 ) ) , V_46 ) ;
F_42 ( V_1 , F_44 ( V_19 ,
F_34 ( V_51 ) ) , V_47 ) ;
F_42 ( V_1 , F_45 ( V_19 ,
F_34 ( V_51 ) ) , V_48 ) ;
}
F_23 ( V_10 -> V_16 , V_50 , V_52 , V_49 ) ;
V_55:
F_21 ( & V_10 -> V_54 , V_25 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_25 ;
struct V_35 * V_36 ;
if ( F_14 ( ! V_3 -> V_29 ) )
return;
V_36 = & V_3 -> V_29 -> V_37 ;
F_11 ( L_5 ,
V_10 -> V_15 , V_36 -> V_11 . V_28 , V_36 -> V_15 ,
V_36 -> V_71 , V_36 -> clock ,
V_36 -> V_72 , V_36 -> V_73 ,
V_36 -> V_74 , V_36 -> V_75 ,
V_36 -> V_76 , V_36 -> V_77 ,
V_36 -> V_78 , V_36 -> V_79 ,
V_36 -> type , V_36 -> V_25 ) ;
F_19 ( & V_10 -> V_54 , V_25 ) ;
F_42 ( V_1 , F_47 ( V_10 -> V_19 ) ,
F_48 ( V_36 -> V_72 ) |
F_49 ( V_36 -> V_76 ) ) ;
F_21 ( & V_10 -> V_54 , V_25 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( ! V_10 -> V_80 ) )
return;
if ( V_10 -> V_81 )
F_51 ( & V_1 -> V_11 , & V_10 -> V_82 ) ;
F_51 ( & V_1 -> V_11 , & V_10 -> V_83 ) ;
F_52 ( V_1 ) ;
V_10 -> V_80 = false ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( V_10 -> V_80 ) )
return;
F_54 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_83 ) ;
if ( V_10 -> V_81 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_82 ) ;
V_10 -> V_80 = true ;
}
static int F_55 ( const void * V_84 , const void * V_85 )
{
struct V_86 * V_87 = (struct V_86 * ) V_84 ;
struct V_86 * V_88 = (struct V_86 * ) V_85 ;
return V_87 -> V_29 -> V_89 - V_88 -> V_29 -> V_89 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_90 * V_29 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_86 V_42 [ V_43 + 1 ] ;
const struct V_38 * V_39 ;
int V_91 = 0 , V_51 ;
F_11 ( L_7 , V_10 -> V_15 ) ;
V_39 = F_35 ( V_1 -> V_53 ) ;
F_57 (plane, state) {
struct V_92 * V_41 ;
if ( V_91 >= ( V_39 -> V_19 . V_93 ) ) {
F_58 ( V_6 -> V_6 , L_8 ) ;
return - V_94 ;
}
V_41 = V_29 -> V_29 -> V_95 [ F_59 ( V_18 ) ] ;
if ( ! V_41 )
V_41 = V_18 -> V_29 ;
V_42 [ V_91 ] . V_18 = V_18 ;
V_42 [ V_91 ] . V_29 = F_36 ( V_41 ) ;
V_91 ++ ;
}
F_60 ( V_42 , V_91 , sizeof( V_42 [ 0 ] ) , F_55 , NULL ) ;
for ( V_51 = 0 ; V_51 < V_91 ; V_51 ++ ) {
V_42 [ V_51 ] . V_29 -> V_50 = V_56 + V_51 ;
F_11 ( L_9 , V_10 -> V_15 ,
F_61 ( F_37 ( V_42 [ V_51 ] . V_18 ) ) ,
V_42 [ V_51 ] . V_29 -> V_50 ) ;
}
return 0 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_90 * V_96 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_10 , V_10 -> V_15 ) ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_90 * V_96 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
unsigned long V_25 ;
F_11 ( L_11 , V_10 -> V_15 , V_3 -> V_29 -> V_24 ) ;
F_14 ( V_10 -> V_24 ) ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_3 -> V_29 -> V_24 ;
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( F_64 ( ! V_10 -> V_16 ) )
return;
F_33 ( V_3 ) ;
if ( V_10 -> V_81 )
F_8 ( V_3 ) ;
V_10 -> V_97 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_98 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_99 * V_100 , T_4 V_33 )
{
return - V_94 ;
}
static void F_66 ( struct V_2 * V_3 , T_1 * V_101 , T_1 * V_102 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_103 = V_3 -> V_36 . V_72 ;
T_1 V_104 = V_3 -> V_36 . V_76 ;
* V_101 = F_67 ( V_10 -> V_105 . V_106 , V_103 -
V_10 -> V_105 . V_107 ) ;
* V_102 = F_67 ( V_10 -> V_105 . V_108 , V_104 -
V_10 -> V_105 . V_109 ) ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_110 ,
T_1 V_106 , T_1 V_108 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_111 * V_112 , * V_113 = NULL ;
T_1 V_114 , V_115 , V_116 ;
int V_117 , V_118 , V_19 ;
unsigned int V_119 ;
enum V_120 V_121 = V_122 ;
T_1 V_14 = F_69 ( 0 ) ;
T_1 V_101 , V_102 ;
bool V_123 = true ;
unsigned long V_25 ;
if ( ( V_106 > V_124 ) || ( V_108 > V_125 ) ) {
F_58 ( V_6 -> V_6 , L_12 , V_106 , V_108 ) ;
return - V_94 ;
}
if ( NULL == V_10 -> V_16 )
return - V_94 ;
if ( ! V_110 ) {
F_11 ( L_13 ) ;
V_123 = false ;
goto V_126;
}
V_112 = F_70 ( V_6 , V_21 , V_110 ) ;
if ( ! V_112 )
return - V_127 ;
V_117 = F_71 ( V_112 , V_1 -> V_28 , & V_115 ) ;
if ( V_117 )
return - V_94 ;
V_19 = V_10 -> V_19 ;
F_72 ( V_128 , & V_119 , & V_118 ) ;
V_116 = V_106 * ( V_118 >> 3 ) ;
F_19 ( & V_10 -> V_105 . V_129 , V_25 ) ;
V_113 = V_10 -> V_105 . V_130 ;
V_10 -> V_105 . V_130 = V_112 ;
V_10 -> V_105 . V_106 = V_106 ;
V_10 -> V_105 . V_108 = V_108 ;
F_66 ( V_3 , & V_101 , & V_102 ) ;
F_42 ( V_1 , F_73 ( V_19 ) , V_116 ) ;
F_42 ( V_1 , F_74 ( V_19 ) ,
F_75 ( V_131 ) ) ;
F_42 ( V_1 , F_76 ( V_19 ) ,
F_77 ( V_108 ) |
F_78 ( V_106 ) ) ;
F_42 ( V_1 , F_79 ( V_19 ) ,
F_80 ( V_102 ) |
F_81 ( V_101 ) ) ;
F_42 ( V_1 , F_82 ( V_19 ) , V_115 ) ;
V_114 = V_132 ;
V_114 |= F_83 ( V_121 ) ;
F_42 ( V_1 , F_84 ( V_19 ) , V_114 ) ;
F_21 ( & V_10 -> V_105 . V_129 , V_25 ) ;
V_126:
V_117 = F_85 ( V_10 -> V_16 , 0 , V_123 ) ;
if ( V_117 ) {
F_58 ( V_6 -> V_6 , L_14 ,
V_123 ? L_15 : L_16 , V_117 ) ;
goto V_133;
}
F_10 ( V_3 , V_14 ) ;
V_133:
if ( V_113 ) {
F_86 ( & V_10 -> V_34 , V_113 ) ;
F_4 ( V_3 , V_134 ) ;
}
return V_117 ;
}
static int F_87 ( struct V_2 * V_3 , int V_107 , int V_109 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_69 ( 0 ) ;
T_1 V_101 ;
T_1 V_102 ;
unsigned long V_25 ;
if ( F_64 ( ! V_3 -> V_29 -> V_30 ) )
return 0 ;
V_10 -> V_105 . V_107 = V_107 = F_88 ( V_107 , 0 ) ;
V_10 -> V_105 . V_109 = V_109 = F_88 ( V_109 , 0 ) ;
F_66 ( V_3 , & V_101 , & V_102 ) ;
F_19 ( & V_10 -> V_105 . V_129 , V_25 ) ;
F_42 ( V_1 , F_79 ( V_10 -> V_19 ) ,
F_80 ( V_102 ) |
F_81 ( V_101 ) ) ;
F_42 ( V_1 , F_89 ( V_10 -> V_19 ) ,
F_90 ( V_109 ) |
F_91 ( V_107 ) ) ;
F_21 ( & V_10 -> V_105 . V_129 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_92 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_51 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_93 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_98 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_134 )
F_94 ( & V_10 -> V_34 , V_5 -> V_138 ) ;
}
static void F_95 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 , V_83 ) ;
F_11 ( L_17 , V_10 -> V_15 , V_137 ) ;
}
static void F_96 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 ,
V_82 ) ;
F_97 ( & V_10 -> V_13 ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_117 ;
V_117 = F_99 ( & V_10 -> V_13 ,
F_100 ( 50 ) ) ;
if ( V_117 == 0 )
F_101 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_117 ;
if ( ! V_10 -> V_16 )
return;
V_117 = F_103 ( V_3 ) ;
if ( V_117 )
return;
V_117 = F_104 ( V_6 -> V_12 [ F_105 ( V_3 ) ] . V_139 ,
( ( F_106 ( V_10 -> V_16 ) &
V_10 -> V_97 ) == 0 ) ,
F_100 ( 50 ) ) ;
if ( V_117 <= 0 )
F_101 ( V_6 -> V_6 , L_19 , V_10 -> V_28 ) ;
V_10 -> V_97 = 0 ;
F_107 ( V_3 ) ;
}
T_1 F_108 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_140 ;
}
void F_109 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
F_11 ( L_20 , V_21 ) ;
F_18 ( V_3 , V_21 ) ;
}
void F_110 ( struct V_2 * V_3 ,
struct V_141 * V_142 , struct V_143 * V_16 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_111 ( V_3 ) ;
V_10 -> V_83 . V_140 = F_112 ( V_142 -> V_144 ) ;
V_10 -> V_12 . V_140 = F_113 ( V_19 , V_142 ) ;
if ( ( V_142 -> type == V_145 ) &&
( V_142 -> V_36 == V_146 ) ) {
V_10 -> V_82 . V_140 = F_114 ( V_19 ) ;
V_10 -> V_82 . V_136 = F_96 ;
V_10 -> V_81 = true ;
} else {
V_10 -> V_82 . V_140 = 0 ;
V_10 -> V_82 . V_136 = NULL ;
V_10 -> V_81 = false ;
}
F_115 ( & V_1 -> V_11 ) ;
V_10 -> V_16 = V_16 ;
F_116 ( V_16 , V_142 , V_19 ) ;
}
int F_111 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_94 : V_10 -> V_19 ;
}
void F_117 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( V_10 -> V_81 )
F_98 ( V_3 ) ;
else
F_102 ( V_3 ) ;
}
struct V_2 * F_118 ( struct V_22 * V_6 ,
struct V_17 * V_18 , int V_28 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_119 ( sizeof( * V_10 ) , V_147 ) ;
if ( ! V_10 )
return F_120 ( - V_148 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_19 = F_121 ( V_28 ) ;
F_122 ( & V_10 -> V_54 ) ;
F_122 ( & V_10 -> V_105 . V_129 ) ;
F_123 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_136 = F_92 ;
V_10 -> V_83 . V_136 = F_95 ;
snprintf ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) , L_21 ,
F_61 ( F_37 ( V_18 ) ) , V_28 ) ;
F_124 ( V_6 , V_3 , V_18 , NULL , & V_149 ) ;
F_125 ( & V_10 -> V_34 ,
L_22 , F_24 ) ;
F_126 ( V_3 , & V_150 ) ;
V_18 -> V_3 = V_3 ;
return V_3 ;
}
