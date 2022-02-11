static struct V_1 * F_1 ( struct V_2 * V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
F_2 (tgt, &gn->targets, list)
if ( ! strcmp ( V_4 , V_5 -> V_6 -> V_7 ) )
return V_5 ;
return NULL ;
}
static int F_3 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_14 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_1 * V_22 ;
void * V_23 ;
V_21 = F_4 ( V_11 -> V_24 , 1 ) ;
if ( ! V_21 ) {
F_5 ( L_1 , V_11 -> V_24 ) ;
return - V_25 ;
}
F_6 ( & V_3 -> V_26 ) ;
V_22 = F_1 ( V_3 , V_11 -> V_27 ) ;
if ( V_22 ) {
F_5 ( L_2 ) ;
F_7 ( & V_3 -> V_26 ) ;
return - V_25 ;
}
F_7 ( & V_3 -> V_26 ) ;
V_22 = F_8 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_22 )
return - V_29 ;
V_17 = F_9 ( V_28 , V_9 -> V_30 -> V_31 ) ;
if ( ! V_17 )
goto V_32;
F_10 ( V_17 , V_21 -> V_33 ) ;
V_19 = F_11 ( 0 ) ;
if ( ! V_19 )
goto V_34;
sprintf ( V_19 -> V_7 , L_3 , V_11 -> V_27 ) ;
V_19 -> V_35 = V_36 ;
V_19 -> V_37 = 0 ;
V_19 -> V_38 = 0 ;
V_19 -> V_39 = & V_40 ;
V_19 -> V_41 = V_17 ;
V_23 = V_21 -> V_42 ( V_9 , V_19 , V_14 -> V_43 , V_14 -> V_44 ) ;
if ( F_12 ( V_23 ) )
goto V_45;
V_19 -> V_46 = V_23 ;
V_17 -> V_47 = V_23 ;
F_13 ( V_17 , 8 * V_9 -> V_48 -> V_49 ) ;
F_14 ( V_19 , V_21 -> V_50 ( V_23 ) ) ;
F_15 ( V_19 ) ;
V_22 -> type = V_21 ;
V_22 -> V_6 = V_19 ;
V_22 -> V_9 = V_9 ;
F_6 ( & V_3 -> V_26 ) ;
F_16 ( & V_22 -> V_51 , & V_3 -> V_52 ) ;
F_7 ( & V_3 -> V_26 ) ;
return 0 ;
V_45:
F_17 ( V_19 ) ;
V_34:
F_18 ( V_17 ) ;
V_32:
F_19 ( V_22 ) ;
return - V_29 ;
}
static void F_20 ( struct V_1 * V_22 )
{
struct V_20 * V_21 = V_22 -> type ;
struct V_18 * V_19 = V_22 -> V_6 ;
struct V_16 * V_30 = V_19 -> V_41 ;
F_21 ( V_19 ) ;
F_18 ( V_30 ) ;
if ( V_21 -> exit )
V_21 -> exit ( V_19 -> V_46 ) ;
F_17 ( V_19 ) ;
F_22 ( & V_22 -> V_51 ) ;
F_19 ( V_22 ) ;
}
static int F_23 ( struct V_8 * V_9 , struct V_53 * remove )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_1 * V_22 ;
if ( ! V_3 )
return 1 ;
F_6 ( & V_3 -> V_26 ) ;
V_22 = F_1 ( V_3 , remove -> V_27 ) ;
if ( ! V_22 ) {
F_7 ( & V_3 -> V_26 ) ;
return 1 ;
}
F_20 ( V_22 ) ;
F_7 ( & V_3 -> V_26 ) ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 , T_1 * V_54 , T_1 V_55 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_56 * V_57 , * V_58 , * V_59 ;
T_1 V_60 = 0 ;
T_1 V_61 = ( V_9 -> V_62 * V_9 -> V_63 ) >> 9 ;
if ( V_55 > V_61 )
return - V_25 ;
V_57 = F_8 ( sizeof( struct V_56 ) , V_28 ) ;
if ( ! V_57 )
return - V_29 ;
V_58 = NULL ;
F_25 ( & V_9 -> V_26 ) ;
F_2 (next, &gn->area_list, list) {
if ( V_60 + V_55 > V_59 -> V_60 ) {
V_60 = V_59 -> V_64 ;
V_58 = V_59 ;
continue;
}
break;
}
if ( ( V_60 + V_55 ) > V_61 ) {
F_26 ( & V_9 -> V_26 ) ;
F_19 ( V_57 ) ;
return - V_25 ;
}
V_57 -> V_60 = * V_54 = V_60 ;
V_57 -> V_64 = V_60 + V_55 ;
if ( V_58 )
F_27 ( & V_57 -> V_51 , & V_58 -> V_51 ) ;
else
F_27 ( & V_57 -> V_51 , & V_3 -> V_65 ) ;
F_26 ( & V_9 -> V_26 ) ;
return 0 ;
}
static void F_28 ( struct V_8 * V_9 , T_1 V_60 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_56 * V_57 ;
F_25 ( & V_9 -> V_26 ) ;
F_2 (area, &gn->area_list, list) {
if ( V_57 -> V_60 != V_60 )
continue;
F_22 ( & V_57 -> V_51 ) ;
F_26 ( & V_9 -> V_26 ) ;
F_19 ( V_57 ) ;
return;
}
F_26 ( & V_9 -> V_26 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_66 * V_67 ;
int V_68 ;
F_30 (gn, lun, i) {
if ( ! V_67 -> V_69 . V_70 )
break;
F_31 ( V_67 -> V_69 . V_70 ) ;
}
}
static void F_32 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
F_19 ( V_3 -> V_71 ) ;
}
static int F_33 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
struct V_66 * V_67 ;
int V_68 ;
V_3 -> V_71 = F_34 ( V_9 -> V_72 , sizeof( struct V_66 ) , V_28 ) ;
if ( ! V_3 -> V_71 )
return - V_29 ;
F_30 (gn, lun, i) {
F_35 ( & V_67 -> V_69 . V_26 ) ;
F_36 ( & V_67 -> V_73 ) ;
F_36 ( & V_67 -> V_74 ) ;
F_36 ( & V_67 -> V_75 ) ;
V_67 -> V_76 = 2 ;
V_67 -> V_69 . V_77 = V_68 ;
V_67 -> V_69 . V_78 = V_68 % V_9 -> V_79 ;
V_67 -> V_69 . V_80 = V_68 / V_9 -> V_79 ;
V_67 -> V_69 . V_81 = V_9 -> V_82 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_83 V_84 ,
T_2 * V_85 , int V_86 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_66 * V_67 ;
struct V_87 * V_88 ;
int V_68 ;
V_86 = F_38 ( V_9 , V_85 , V_86 ) ;
if ( V_86 < 0 )
return V_86 ;
V_67 = & V_3 -> V_71 [ ( V_9 -> V_79 * V_84 . V_89 . V_90 ) + V_84 . V_89 . V_67 ] ;
for ( V_68 = 0 ; V_68 < V_86 ; V_68 ++ ) {
if ( V_85 [ V_68 ] == 0 )
continue;
V_88 = & V_67 -> V_69 . V_70 [ V_68 ] ;
F_39 ( & V_88 -> V_51 , & V_67 -> V_75 ) ;
V_67 -> V_69 . V_81 -- ;
}
return 0 ;
}
static int F_40 ( T_3 V_91 , T_4 V_92 , T_5 * V_93 , void * V_94 )
{
struct V_8 * V_9 = V_94 ;
struct V_2 * V_3 = V_9 -> V_12 ;
T_3 V_95 = V_91 + V_92 ;
struct V_66 * V_67 ;
struct V_87 * V_88 ;
T_3 V_68 ;
int V_78 ;
if ( F_41 ( V_95 > V_9 -> V_63 ) ) {
F_5 ( L_4 ) ;
return - V_25 ;
}
for ( V_68 = 0 ; V_68 < V_92 ; V_68 ++ ) {
T_3 V_96 = F_42 ( V_93 [ V_68 ] ) ;
if ( F_41 ( V_96 >= V_9 -> V_63 && V_96 != V_97 ) ) {
F_5 ( L_5 ) ;
return - V_25 ;
}
if ( ! V_96 )
continue;
V_78 = F_43 ( V_96 , V_9 -> V_98 ) ;
V_67 = & V_3 -> V_71 [ V_78 ] ;
V_96 = V_96 - ( V_9 -> V_98 * V_78 ) ;
V_88 = & V_67 -> V_69 . V_70 [ F_43 ( V_96 , V_9 -> V_99 ) ] ;
if ( ! V_88 -> V_100 ) {
F_39 ( & V_88 -> V_51 , & V_67 -> V_74 ) ;
V_88 -> V_100 = V_101 ;
V_67 -> V_69 . V_81 -- ;
}
}
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
struct V_66 * V_67 ;
struct V_87 * V_102 ;
T_1 V_103 , V_104 , V_105 = 0 ;
int V_106 , V_86 ;
T_2 * V_85 ;
V_86 = V_9 -> V_82 * V_9 -> V_107 ;
V_85 = F_8 ( V_86 , V_28 ) ;
if ( ! V_85 )
return - V_29 ;
F_30 (gn, lun, lun_iter) {
V_67 -> V_69 . V_70 = F_45 ( sizeof( struct V_87 ) *
V_9 -> V_82 ) ;
if ( ! V_67 -> V_69 . V_70 ) {
F_19 ( V_85 ) ;
return - V_29 ;
}
for ( V_104 = 0 ; V_104 < V_9 -> V_82 ; V_104 ++ ) {
V_102 = & V_67 -> V_69 . V_70 [ V_104 ] ;
F_36 ( & V_102 -> V_51 ) ;
V_102 -> V_67 = & V_67 -> V_69 ;
V_102 -> V_77 = V_105 ++ ;
if ( F_41 ( V_103 == 0 && V_104 == 0 ) ) {
V_67 -> V_69 . V_81 -- ;
continue;
}
F_16 ( & V_102 -> V_51 , & V_67 -> V_73 ) ;
}
if ( V_9 -> V_48 -> V_108 ) {
struct V_83 V_84 ;
V_84 . V_84 = 0 ;
V_84 . V_89 . V_90 = V_67 -> V_69 . V_80 ;
V_84 . V_89 . V_67 = V_67 -> V_69 . V_78 ;
V_106 = F_46 ( V_9 , V_84 , V_85 ) ;
if ( V_106 )
F_5 ( L_6 ) ;
V_106 = F_37 ( V_3 , V_84 , V_85 , V_86 ) ;
if ( V_106 )
F_5 ( L_7 ) ;
}
}
if ( ( V_9 -> V_109 . V_110 & V_111 ) && V_9 -> V_48 -> V_112 ) {
V_106 = V_9 -> V_48 -> V_112 ( V_9 , 0 , V_9 -> V_63 ,
F_40 , V_9 ) ;
if ( V_106 ) {
F_5 ( L_8 ) ;
F_47 ( L_9 ) ;
}
}
F_19 ( V_85 ) ;
return 0 ;
}
static void F_48 ( struct V_8 * V_9 )
{
F_29 ( V_9 ) ;
F_32 ( V_9 ) ;
F_19 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
int V_106 ;
if ( ! F_50 ( V_113 ) )
return - V_114 ;
V_3 = F_51 ( sizeof( struct V_2 ) , V_28 ) ;
if ( ! V_3 )
return - V_29 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_72 = V_9 -> V_72 ;
F_36 ( & V_3 -> V_65 ) ;
F_52 ( & V_3 -> V_26 ) ;
F_36 ( & V_3 -> V_52 ) ;
V_9 -> V_12 = V_3 ;
V_106 = F_33 ( V_9 , V_3 ) ;
if ( V_106 ) {
F_5 ( L_10 ) ;
goto V_115;
}
V_106 = F_44 ( V_9 , V_3 ) ;
if ( V_106 ) {
F_5 ( L_11 ) ;
goto V_115;
}
return 1 ;
V_115:
F_48 ( V_9 ) ;
F_53 ( V_113 ) ;
return V_106 ;
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_1 * V_22 , * V_116 ;
F_6 ( & V_3 -> V_26 ) ;
F_55 (t, tmp, &gn->targets, list) {
if ( V_22 -> V_9 != V_9 )
continue;
F_20 ( V_22 ) ;
}
F_7 ( & V_3 -> V_26 ) ;
F_48 ( V_9 ) ;
F_53 ( V_113 ) ;
}
static struct V_87 * F_56 ( struct V_8 * V_9 ,
struct V_117 * V_69 , unsigned long V_35 )
{
struct V_66 * V_67 = F_57 ( V_69 , struct V_66 , V_69 ) ;
struct V_87 * V_88 = NULL ;
int V_118 = V_35 & V_119 ;
F_25 ( & V_69 -> V_26 ) ;
if ( F_58 ( & V_67 -> V_73 ) ) {
F_59 ( L_12 ,
V_67 -> V_69 . V_77 ) ;
goto V_120;
}
if ( ! V_118 && V_67 -> V_69 . V_81 < V_67 -> V_76 )
goto V_120;
V_88 = F_60 ( & V_67 -> V_73 , struct V_87 , V_51 ) ;
F_39 ( & V_88 -> V_51 , & V_67 -> V_74 ) ;
V_88 -> V_100 = V_101 ;
V_67 -> V_69 . V_81 -- ;
V_120:
F_26 ( & V_69 -> V_26 ) ;
return V_88 ;
}
static void F_61 ( struct V_8 * V_9 , struct V_87 * V_88 )
{
struct V_117 * V_69 = V_88 -> V_67 ;
struct V_66 * V_67 = F_57 ( V_69 , struct V_66 , V_69 ) ;
F_25 ( & V_69 -> V_26 ) ;
if ( V_88 -> V_100 & V_101 ) {
F_39 ( & V_88 -> V_51 , & V_67 -> V_73 ) ;
V_67 -> V_69 . V_81 ++ ;
V_88 -> V_100 = V_121 ;
} else if ( V_88 -> V_100 & V_122 ) {
F_39 ( & V_88 -> V_51 , & V_67 -> V_75 ) ;
V_88 -> V_100 = V_122 ;
} else {
F_62 ( 1 ) ;
F_5 ( L_13 ,
V_88 -> V_77 , V_88 -> V_100 ) ;
F_39 ( & V_88 -> V_51 , & V_67 -> V_75 ) ;
}
F_26 ( & V_69 -> V_26 ) ;
}
static void F_63 ( struct V_8 * V_9 , struct V_83 V_84 , int type )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_66 * V_67 ;
struct V_87 * V_88 ;
F_64 ( L_14 ,
V_84 . V_89 . V_90 , V_84 . V_89 . V_67 , V_84 . V_89 . V_88 , V_84 . V_89 . V_123 , type ) ;
if ( F_41 ( V_84 . V_89 . V_90 > V_9 -> V_124 ||
V_84 . V_89 . V_67 > V_9 -> V_79 ||
V_84 . V_89 . V_88 > V_9 -> V_82 ) ) {
F_62 ( 1 ) ;
F_5 ( L_15 ,
V_84 . V_89 . V_90 , V_9 -> V_124 ,
V_84 . V_89 . V_67 , V_9 -> V_79 ,
V_84 . V_89 . V_88 , V_9 -> V_82 ) ;
return;
}
V_67 = & V_3 -> V_71 [ ( V_9 -> V_79 * V_84 . V_89 . V_90 ) + V_84 . V_89 . V_67 ] ;
V_88 = & V_67 -> V_69 . V_70 [ V_84 . V_89 . V_88 ] ;
V_88 -> V_100 = type ;
}
static void F_65 ( struct V_8 * V_9 , struct V_125 * V_126 )
{
int V_127 = - 1 ;
int V_128 = V_9 -> V_48 -> V_49 ;
void * V_129 = & V_126 -> V_130 ;
F_66 ( V_9 , V_126 ) ;
if ( V_126 -> V_131 == 1 ) {
F_63 ( V_9 , V_126 -> V_83 , V_122 ) ;
return;
}
while ( ( V_127 = F_67 ( V_129 , V_128 , V_127 + 1 ) ) < V_128 )
F_63 ( V_9 , V_126 -> V_132 [ V_127 ] , V_122 ) ;
}
static void F_68 ( struct V_125 * V_126 )
{
struct V_133 * V_134 = V_126 -> V_134 ;
if ( V_126 -> error == V_135 )
F_65 ( V_126 -> V_9 , V_126 ) ;
V_134 -> V_21 -> V_136 ( V_126 ) ;
}
static int F_69 ( struct V_8 * V_9 , struct V_125 * V_126 )
{
if ( ! V_9 -> V_48 -> V_137 )
return - V_114 ;
F_70 ( V_9 , V_126 ) ;
V_126 -> V_9 = V_9 ;
V_126 -> V_136 = F_68 ;
return V_9 -> V_48 -> V_137 ( V_9 , V_126 ) ;
}
static int F_71 ( struct V_8 * V_9 , struct V_87 * V_88 ,
unsigned long V_35 )
{
struct V_83 V_138 = F_72 ( V_9 , V_88 ) ;
return F_73 ( V_9 , & V_138 , 1 ) ;
}
static int F_74 ( struct V_8 * V_9 , int V_139 )
{
return F_75 ( V_139 , V_9 -> V_140 ) ;
}
static void F_76 ( struct V_8 * V_9 , int V_139 )
{
F_77 ( ! F_78 ( V_139 , V_9 -> V_140 ) ) ;
}
static struct V_117 * F_79 ( struct V_8 * V_9 , int V_139 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
if ( F_41 ( V_139 >= V_9 -> V_72 ) )
return NULL ;
return & V_3 -> V_71 [ V_139 ] . V_69 ;
}
static void F_80 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_12 ;
struct V_66 * V_67 ;
unsigned int V_68 ;
F_30 (gn, lun, i) {
F_25 ( & V_67 -> V_69 . V_26 ) ;
F_81 ( L_16 , V_9 -> V_4 , V_68 ,
V_67 -> V_69 . V_81 ) ;
F_26 ( & V_67 -> V_69 . V_26 ) ;
}
}
static int T_6 F_82 ( void )
{
return F_83 ( & V_141 ) ;
}
static void F_84 ( void )
{
F_85 ( & V_141 ) ;
}
