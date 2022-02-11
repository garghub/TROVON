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
if ( ! V_39 [ V_53 ] ) {
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
static bool F_55 ( struct V_90 * V_91 ,
struct V_92 * V_38 )
{
return ( V_38 -> V_93 <= 0 ) && ( V_38 -> V_94 <= 0 ) &&
( ( V_38 -> V_93 + V_38 -> V_95 ) >= V_91 -> V_69 . V_72 ) &&
( ( V_38 -> V_94 + V_38 -> V_96 ) >= V_91 -> V_69 . V_76 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_90 * V_28 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_86 V_39 [ V_40 + 1 ] ;
const struct V_35 * V_36 ;
const struct V_92 * V_38 ;
int V_97 = 0 , V_11 = 0 , V_48 ;
F_11 ( L_7 , V_10 -> V_15 ) ;
F_57 (plane, pstate, state) {
V_39 [ V_97 ] . V_18 = V_18 ;
V_39 [ V_97 ] . V_28 = F_35 ( V_38 ) ;
V_97 ++ ;
}
F_58 ( V_39 , V_97 , sizeof( V_39 [ 0 ] ) , F_54 , NULL ) ;
if ( ( V_97 > 0 ) && ! F_55 ( V_28 , & V_39 [ 0 ] . V_28 -> V_11 ) )
V_11 ++ ;
V_36 = F_34 ( V_1 -> V_50 ) ;
if ( ( V_97 + V_11 ) >= V_36 -> V_19 . V_98 ) {
F_59 ( V_6 -> V_6 , L_8 ) ;
return - V_99 ;
}
for ( V_48 = 0 ; V_48 < V_97 ; V_48 ++ ) {
V_39 [ V_48 ] . V_28 -> V_47 = V_53 + V_48 + V_11 ;
F_11 ( L_9 , V_10 -> V_15 ,
F_60 ( F_36 ( V_39 [ V_48 ] . V_18 ) ) ,
V_39 [ V_48 ] . V_28 -> V_47 ) ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_90 * V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_10 , V_10 -> V_15 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_90 * V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
unsigned long V_25 ;
F_11 ( L_11 , V_10 -> V_15 , V_3 -> V_28 -> V_24 ) ;
F_14 ( V_10 -> V_24 ) ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_3 -> V_28 -> V_24 ;
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( F_63 ( ! V_10 -> V_16 ) )
return;
F_32 ( V_3 ) ;
if ( V_10 -> V_81 )
F_8 ( V_3 ) ;
V_10 -> V_101 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_102 ) ;
}
static void F_64 ( struct V_2 * V_3 , T_1 * V_103 , T_1 * V_104 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_105 = V_3 -> V_69 . V_72 ;
T_1 V_106 = V_3 -> V_69 . V_76 ;
* V_103 = F_65 ( V_10 -> V_107 . V_108 , V_105 -
V_10 -> V_107 . V_109 ) ;
* V_104 = F_65 ( V_10 -> V_107 . V_110 , V_106 -
V_10 -> V_107 . V_111 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_112 ,
T_1 V_108 , T_1 V_110 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_113 * V_114 , * V_115 = NULL ;
T_1 V_116 , V_117 , V_118 ;
int V_119 , V_19 ;
enum V_120 V_121 = V_122 ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_103 , V_104 ;
bool V_123 = true ;
unsigned long V_25 ;
if ( ( V_108 > V_124 ) || ( V_110 > V_125 ) ) {
F_59 ( V_6 -> V_6 , L_12 , V_108 , V_110 ) ;
return - V_99 ;
}
if ( NULL == V_10 -> V_16 )
return - V_99 ;
if ( ! V_112 ) {
F_11 ( L_13 ) ;
V_123 = false ;
goto V_126;
}
V_114 = F_68 ( V_21 , V_112 ) ;
if ( ! V_114 )
return - V_127 ;
V_119 = F_69 ( V_114 , V_1 -> V_34 , & V_117 ) ;
if ( V_119 )
return - V_99 ;
V_19 = V_10 -> V_19 ;
V_118 = V_108 * F_70 ( V_128 , 0 ) ;
F_19 ( & V_10 -> V_107 . V_129 , V_25 ) ;
V_115 = V_10 -> V_107 . V_130 ;
V_10 -> V_107 . V_130 = V_114 ;
V_10 -> V_107 . V_108 = V_108 ;
V_10 -> V_107 . V_110 = V_110 ;
F_64 ( V_3 , & V_103 , & V_104 ) ;
F_41 ( V_1 , F_71 ( V_19 ) , V_118 ) ;
F_41 ( V_1 , F_72 ( V_19 ) ,
F_73 ( V_131 ) ) ;
F_41 ( V_1 , F_74 ( V_19 ) ,
F_75 ( V_110 ) |
F_76 ( V_108 ) ) ;
F_41 ( V_1 , F_77 ( V_19 ) ,
F_78 ( V_104 ) |
F_79 ( V_103 ) ) ;
F_41 ( V_1 , F_80 ( V_19 ) , V_117 ) ;
V_116 = V_132 ;
V_116 |= F_81 ( V_121 ) ;
F_41 ( V_1 , F_82 ( V_19 ) , V_116 ) ;
F_21 ( & V_10 -> V_107 . V_129 , V_25 ) ;
V_126:
V_119 = F_83 ( V_10 -> V_16 , 0 , V_123 ) ;
if ( V_119 ) {
F_59 ( V_6 -> V_6 , L_14 ,
V_123 ? L_15 : L_16 , V_119 ) ;
goto V_133;
}
F_10 ( V_3 , V_14 ) ;
V_133:
if ( V_115 ) {
F_84 ( & V_10 -> V_33 , V_115 ) ;
F_4 ( V_3 , V_134 ) ;
}
return V_119 ;
}
static int F_85 ( struct V_2 * V_3 , int V_109 , int V_111 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_103 ;
T_1 V_104 ;
unsigned long V_25 ;
if ( F_63 ( ! V_3 -> V_28 -> V_29 ) )
return 0 ;
V_10 -> V_107 . V_109 = V_109 = F_86 ( V_109 , 0 ) ;
V_10 -> V_107 . V_111 = V_111 = F_86 ( V_111 , 0 ) ;
F_64 ( V_3 , & V_103 , & V_104 ) ;
F_19 ( & V_10 -> V_107 . V_129 , V_25 ) ;
F_41 ( V_1 , F_77 ( V_10 -> V_19 ) ,
F_78 ( V_104 ) |
F_79 ( V_103 ) ) ;
F_41 ( V_1 , F_87 ( V_10 -> V_19 ) ,
F_88 ( V_111 ) |
F_89 ( V_109 ) ) ;
F_21 ( & V_10 -> V_107 . V_129 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_50 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_91 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_102 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_134 )
F_92 ( & V_10 -> V_33 , V_5 -> V_138 ) ;
}
static void F_93 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 , V_83 ) ;
F_11 ( L_17 , V_10 -> V_15 , V_137 ) ;
}
static void F_94 ( struct V_135 * V_136 , T_1 V_137 )
{
struct V_10 * V_10 = F_25 ( V_136 , struct V_10 ,
V_82 ) ;
F_95 ( & V_10 -> V_13 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_119 ;
V_119 = F_97 ( & V_10 -> V_13 ,
F_98 ( 50 ) ) ;
if ( V_119 == 0 )
F_99 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_119 ;
if ( ! V_10 -> V_16 )
return;
V_119 = F_101 ( V_3 ) ;
if ( V_119 )
return;
V_119 = F_102 ( V_6 -> V_12 [ F_103 ( V_3 ) ] . V_139 ,
( ( F_104 ( V_10 -> V_16 ) &
V_10 -> V_101 ) == 0 ) ,
F_98 ( 50 ) ) ;
if ( V_119 <= 0 )
F_99 ( V_6 -> V_6 , L_19 , V_10 -> V_34 ) ;
V_10 -> V_101 = 0 ;
F_105 ( V_3 ) ;
}
T_1 F_106 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_140 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_141 * V_142 , struct V_143 * V_16 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_108 ( V_3 ) ;
V_10 -> V_83 . V_140 = F_109 ( V_142 -> V_144 ) ;
V_10 -> V_12 . V_140 = F_110 ( V_19 , V_142 ) ;
if ( ( V_142 -> type == V_145 ) &&
( V_142 -> V_69 == V_146 ) ) {
V_10 -> V_82 . V_140 = F_111 ( V_19 ) ;
V_10 -> V_82 . V_136 = F_94 ;
V_10 -> V_81 = true ;
} else {
V_10 -> V_82 . V_140 = 0 ;
V_10 -> V_82 . V_136 = NULL ;
V_10 -> V_81 = false ;
}
F_112 ( & V_1 -> V_11 ) ;
V_10 -> V_16 = V_16 ;
F_113 ( V_16 , V_142 , V_19 ) ;
}
int F_108 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_99 : V_10 -> V_19 ;
}
void F_114 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( V_10 -> V_81 )
F_96 ( V_3 ) ;
else
F_100 ( V_3 ) ;
}
struct V_2 * F_115 ( struct V_22 * V_6 ,
struct V_17 * V_18 , int V_34 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_116 ( sizeof( * V_10 ) , V_147 ) ;
if ( ! V_10 )
return F_117 ( - V_148 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_34 = V_34 ;
V_10 -> V_19 = F_118 ( V_34 ) ;
F_119 ( & V_10 -> V_51 ) ;
F_119 ( & V_10 -> V_107 . V_129 ) ;
F_120 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_136 = F_90 ;
V_10 -> V_83 . V_136 = F_93 ;
snprintf ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) , L_20 ,
F_60 ( F_36 ( V_18 ) ) , V_34 ) ;
F_121 ( V_6 , V_3 , V_18 , NULL , & V_149 ,
NULL ) ;
F_122 ( & V_10 -> V_33 ,
L_21 , F_24 ) ;
F_123 ( V_3 , & V_150 ) ;
V_18 -> V_3 = V_3 ;
return V_3 ;
}
