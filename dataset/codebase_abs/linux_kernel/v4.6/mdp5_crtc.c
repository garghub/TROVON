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
V_38 = F_35 ( V_18 -> V_29 ) ;
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
if ( F_14 ( ! V_3 -> V_29 ) )
return;
V_69 = & V_3 -> V_29 -> V_70 ;
F_11 ( L_5 ,
V_10 -> V_15 , V_69 -> V_11 . V_28 , V_69 -> V_15 ,
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
return V_87 -> V_29 -> V_89 - V_88 -> V_29 -> V_89 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_90 * V_29 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_86 V_39 [ V_40 + 1 ] ;
const struct V_35 * V_36 ;
int V_91 = 0 , V_48 ;
F_11 ( L_7 , V_10 -> V_15 ) ;
V_36 = F_34 ( V_1 -> V_50 ) ;
F_56 (plane, state) {
struct V_92 * V_38 ;
if ( V_91 >= ( V_36 -> V_19 . V_93 ) ) {
F_57 ( V_6 -> V_6 , L_8 ) ;
return - V_94 ;
}
V_38 = V_29 -> V_29 -> V_95 [ F_58 ( V_18 ) ] ;
if ( ! V_38 )
V_38 = V_18 -> V_29 ;
V_39 [ V_91 ] . V_18 = V_18 ;
V_39 [ V_91 ] . V_29 = F_35 ( V_38 ) ;
V_91 ++ ;
}
F_59 ( V_39 , V_91 , sizeof( V_39 [ 0 ] ) , F_54 , NULL ) ;
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ ) {
V_39 [ V_48 ] . V_29 -> V_47 = V_53 + V_48 ;
F_11 ( L_9 , V_10 -> V_15 ,
F_60 ( F_36 ( V_39 [ V_48 ] . V_18 ) ) ,
V_39 [ V_48 ] . V_29 -> V_47 ) ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_90 * V_96 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_10 , V_10 -> V_15 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
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
if ( F_63 ( ! V_10 -> V_16 ) )
return;
F_32 ( V_3 ) ;
if ( V_10 -> V_81 )
F_8 ( V_3 ) ;
V_10 -> V_97 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_98 ) ;
}
static void F_64 ( struct V_2 * V_3 , T_1 * V_99 , T_1 * V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_101 = V_3 -> V_69 . V_72 ;
T_1 V_102 = V_3 -> V_69 . V_76 ;
* V_99 = F_65 ( V_10 -> V_103 . V_104 , V_101 -
V_10 -> V_103 . V_105 ) ;
* V_100 = F_65 ( V_10 -> V_103 . V_106 , V_102 -
V_10 -> V_103 . V_107 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_108 ,
T_1 V_104 , T_1 V_106 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_109 * V_110 , * V_111 = NULL ;
T_1 V_112 , V_113 , V_114 ;
int V_115 , V_116 , V_19 ;
unsigned int V_117 ;
enum V_118 V_119 = V_120 ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_99 , V_100 ;
bool V_121 = true ;
unsigned long V_25 ;
if ( ( V_104 > V_122 ) || ( V_106 > V_123 ) ) {
F_57 ( V_6 -> V_6 , L_12 , V_104 , V_106 ) ;
return - V_94 ;
}
if ( NULL == V_10 -> V_16 )
return - V_94 ;
if ( ! V_108 ) {
F_11 ( L_13 ) ;
V_121 = false ;
goto V_124;
}
V_110 = F_68 ( V_6 , V_21 , V_108 ) ;
if ( ! V_110 )
return - V_125 ;
V_115 = F_69 ( V_110 , V_1 -> V_28 , & V_113 ) ;
if ( V_115 )
return - V_94 ;
V_19 = V_10 -> V_19 ;
F_70 ( V_126 , & V_117 , & V_116 ) ;
V_114 = V_104 * ( V_116 >> 3 ) ;
F_19 ( & V_10 -> V_103 . V_127 , V_25 ) ;
V_111 = V_10 -> V_103 . V_128 ;
V_10 -> V_103 . V_128 = V_110 ;
V_10 -> V_103 . V_104 = V_104 ;
V_10 -> V_103 . V_106 = V_106 ;
F_64 ( V_3 , & V_99 , & V_100 ) ;
F_41 ( V_1 , F_71 ( V_19 ) , V_114 ) ;
F_41 ( V_1 , F_72 ( V_19 ) ,
F_73 ( V_129 ) ) ;
F_41 ( V_1 , F_74 ( V_19 ) ,
F_75 ( V_106 ) |
F_76 ( V_104 ) ) ;
F_41 ( V_1 , F_77 ( V_19 ) ,
F_78 ( V_100 ) |
F_79 ( V_99 ) ) ;
F_41 ( V_1 , F_80 ( V_19 ) , V_113 ) ;
V_112 = V_130 ;
V_112 |= F_81 ( V_119 ) ;
F_41 ( V_1 , F_82 ( V_19 ) , V_112 ) ;
F_21 ( & V_10 -> V_103 . V_127 , V_25 ) ;
V_124:
V_115 = F_83 ( V_10 -> V_16 , 0 , V_121 ) ;
if ( V_115 ) {
F_57 ( V_6 -> V_6 , L_14 ,
V_121 ? L_15 : L_16 , V_115 ) ;
goto V_131;
}
F_10 ( V_3 , V_14 ) ;
V_131:
if ( V_111 ) {
F_84 ( & V_10 -> V_34 , V_111 ) ;
F_4 ( V_3 , V_132 ) ;
}
return V_115 ;
}
static int F_85 ( struct V_2 * V_3 , int V_105 , int V_107 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_99 ;
T_1 V_100 ;
unsigned long V_25 ;
if ( F_63 ( ! V_3 -> V_29 -> V_30 ) )
return 0 ;
V_10 -> V_103 . V_105 = V_105 = F_86 ( V_105 , 0 ) ;
V_10 -> V_103 . V_107 = V_107 = F_86 ( V_107 , 0 ) ;
F_64 ( V_3 , & V_99 , & V_100 ) ;
F_19 ( & V_10 -> V_103 . V_127 , V_25 ) ;
F_41 ( V_1 , F_77 ( V_10 -> V_19 ) ,
F_78 ( V_100 ) |
F_79 ( V_99 ) ) ;
F_41 ( V_1 , F_87 ( V_10 -> V_19 ) ,
F_88 ( V_107 ) |
F_89 ( V_105 ) ) ;
F_21 ( & V_10 -> V_103 . V_127 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_133 * V_134 , T_1 V_135 )
{
struct V_10 * V_10 = F_25 ( V_134 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_50 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_91 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_98 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_132 )
F_92 ( & V_10 -> V_34 , V_5 -> V_136 ) ;
}
static void F_93 ( struct V_133 * V_134 , T_1 V_135 )
{
struct V_10 * V_10 = F_25 ( V_134 , struct V_10 , V_83 ) ;
F_11 ( L_17 , V_10 -> V_15 , V_135 ) ;
}
static void F_94 ( struct V_133 * V_134 , T_1 V_135 )
{
struct V_10 * V_10 = F_25 ( V_134 , struct V_10 ,
V_82 ) ;
F_95 ( & V_10 -> V_13 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_115 ;
V_115 = F_97 ( & V_10 -> V_13 ,
F_98 ( 50 ) ) ;
if ( V_115 == 0 )
F_99 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_115 ;
if ( ! V_10 -> V_16 )
return;
V_115 = F_101 ( V_3 ) ;
if ( V_115 )
return;
V_115 = F_102 ( V_6 -> V_12 [ F_103 ( V_3 ) ] . V_137 ,
( ( F_104 ( V_10 -> V_16 ) &
V_10 -> V_97 ) == 0 ) ,
F_98 ( 50 ) ) ;
if ( V_115 <= 0 )
F_99 ( V_6 -> V_6 , L_19 , V_10 -> V_28 ) ;
V_10 -> V_97 = 0 ;
F_105 ( V_3 ) ;
}
T_1 F_106 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_138 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_139 * V_140 , struct V_141 * V_16 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_108 ( V_3 ) ;
V_10 -> V_83 . V_138 = F_109 ( V_140 -> V_142 ) ;
V_10 -> V_12 . V_138 = F_110 ( V_19 , V_140 ) ;
if ( ( V_140 -> type == V_143 ) &&
( V_140 -> V_69 == V_144 ) ) {
V_10 -> V_82 . V_138 = F_111 ( V_19 ) ;
V_10 -> V_82 . V_134 = F_94 ;
V_10 -> V_81 = true ;
} else {
V_10 -> V_82 . V_138 = 0 ;
V_10 -> V_82 . V_134 = NULL ;
V_10 -> V_81 = false ;
}
F_112 ( & V_1 -> V_11 ) ;
V_10 -> V_16 = V_16 ;
F_113 ( V_16 , V_140 , V_19 ) ;
}
int F_108 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_94 : V_10 -> V_19 ;
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
struct V_17 * V_18 , int V_28 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_116 ( sizeof( * V_10 ) , V_145 ) ;
if ( ! V_10 )
return F_117 ( - V_146 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_19 = F_118 ( V_28 ) ;
F_119 ( & V_10 -> V_51 ) ;
F_119 ( & V_10 -> V_103 . V_127 ) ;
F_120 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_134 = F_90 ;
V_10 -> V_83 . V_134 = F_93 ;
snprintf ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) , L_20 ,
F_60 ( F_36 ( V_18 ) ) , V_28 ) ;
F_121 ( V_6 , V_3 , V_18 , NULL , & V_147 ,
NULL ) ;
F_122 ( & V_10 -> V_34 ,
L_21 , F_24 ) ;
F_123 ( V_3 , & V_148 ) ;
V_18 -> V_3 = V_3 ;
return V_3 ;
}
