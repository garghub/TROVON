static struct V_1 * F_1
( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( & V_5 -> V_8 . V_9 [ 0 ] ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
return V_7 -> V_10 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_6 * V_7 ;
int V_15 ;
V_7 = F_2 ( & V_5 -> V_8 . V_9 [ 0 ] ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 ) ;
return - V_16 ;
}
V_14 = F_5 ( V_7 -> V_10 ) ;
V_12 = V_5 -> V_17 -> V_18 ;
for ( V_15 = 0 ; V_15 < V_12 -> V_19 ; V_15 ++ ) {
if ( ! strcmp ( V_12 -> V_20 [ V_15 ] . V_21 , V_14 -> V_22 ) ) {
V_3 -> V_23 = & V_12 -> V_20 [ V_15 ] ;
break;
}
}
if ( V_15 == V_12 -> V_19 ) {
F_3 ( L_2 ) ;
return - V_16 ;
}
for ( V_15 = 0 ; V_15 < V_5 -> V_24 ; V_15 ++ ) {
if ( ! strcmp ( V_3 -> V_23 -> V_21 ,
V_5 -> V_25 [ V_15 ] -> V_22 ) )
V_3 -> V_23 -> V_14 = V_5 -> V_25 [ V_15 ] ;
}
return 0 ;
}
static struct V_13 *
F_6 ( struct V_2 * V_3 , T_1 * V_26 )
{
struct V_6 * V_7 = F_2 ( & V_3 -> V_26 ) ;
if ( V_7 == NULL || V_7 -> V_10 -> type != V_27 )
return NULL ;
if ( V_26 )
* V_26 = V_7 -> V_28 ;
return F_5 ( V_7 -> V_10 ) ;
}
static int
F_7 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_31 V_32 ;
struct V_13 * V_14 ;
struct V_6 * V_7 ;
T_1 V_26 ;
int V_33 ;
V_14 = F_6 ( V_3 , & V_26 ) ;
if ( V_14 == NULL )
return - V_16 ;
V_32 . V_34 = V_35 ;
V_7 = F_2 ( & V_3 -> V_26 ) ;
V_32 . V_26 = V_7 -> V_28 ;
V_33 = F_8 ( V_14 , V_26 , V_36 , NULL , & V_32 ) ;
if ( V_33 == - V_37 )
return - V_16 ;
V_30 -> type = V_3 -> type ;
F_9 ( & V_30 -> V_32 . V_38 , & V_32 . V_30 ) ;
F_10 ( & V_32 . V_30 , & V_30 -> V_32 . V_38 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = & V_3 -> V_39 . V_10 ;
struct V_40 * V_41 = V_10 -> V_42 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
struct V_2 * V_45 = NULL ;
struct V_46 V_47 ;
V_44 -> V_48 = 0 ;
V_44 -> V_49 = 0 ;
if ( V_3 -> type == V_50 )
V_44 -> V_51 [ V_44 -> V_48 ++ ] = V_3 ;
else
V_44 -> V_52 [ V_44 -> V_49 ++ ] = V_3 ;
F_12 ( & V_41 -> V_53 ) ;
F_13 ( & V_47 , V_10 ) ;
while ( ( V_10 = F_14 ( & V_47 ) ) ) {
if ( V_10 == & V_3 -> V_39 . V_10 )
continue;
if ( F_15 ( V_10 ) != V_54 )
continue;
V_45 = F_16 ( F_17 ( V_10 ) ) ;
if ( V_45 -> type == V_50 )
V_44 -> V_51 [ V_44 -> V_48 ++ ] = V_45 ;
else
V_44 -> V_52 [ V_44 -> V_49 ++ ] = V_45 ;
}
F_18 ( & V_41 -> V_53 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
int V_33 ;
F_11 ( V_3 ) ;
if ( V_44 -> V_48 == 0 ) {
V_44 -> V_55 = V_56 ;
V_33 = F_4 ( V_3 ) ;
if ( V_33 ) {
F_3 ( L_3 ) ;
return V_33 ;
}
} else {
V_44 -> V_55 = V_57 ;
}
V_3 -> V_58 = 1 ;
V_3 -> V_59 = 1 ;
V_3 -> V_60 = 1 ;
return 0 ;
}
int F_20 ( struct V_43 * V_44 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_44 -> V_48 ; V_15 ++ )
if ( ! V_44 -> V_51 [ V_15 ] -> V_61 ||
V_44 -> V_51 [ V_15 ] -> V_55 != V_62 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_44 -> V_49 ; V_15 ++ )
if ( ! V_44 -> V_52 [ V_15 ] -> V_61 ||
V_44 -> V_52 [ V_15 ] -> V_55 != V_62 )
return 0 ;
return 1 ;
}
static int F_21 ( struct V_43 * V_44 )
{
struct V_31 V_63 ;
struct V_31 V_64 ;
struct V_13 * V_14 ;
struct V_6 * V_26 ;
int V_33 ;
V_14 = F_6 ( V_44 -> V_52 [ 0 ] , NULL ) ;
if ( V_14 == NULL )
return - V_65 ;
while ( 1 ) {
V_26 = & V_14 -> V_10 . V_9 [ 0 ] ;
if ( ! ( V_26 -> V_66 & V_67 ) )
break;
V_64 . V_34 = V_35 ;
V_64 . V_26 = V_26 -> V_28 ;
V_33 = F_8 ( V_14 , V_26 , V_36 , NULL ,
& V_64 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
return - V_65 ;
V_26 = F_2 ( V_26 ) ;
if ( V_26 == NULL ||
V_26 -> V_10 -> type != V_27 )
break;
V_14 = F_5 ( V_26 -> V_10 ) ;
V_63 . V_34 = V_35 ;
V_63 . V_26 = V_26 -> V_28 ;
V_33 = F_8 ( V_14 , V_26 , V_36 , NULL , & V_63 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
return - V_65 ;
if ( V_63 . V_30 . V_68 != V_64 . V_30 . V_68 ||
V_63 . V_30 . V_69 != V_64 . V_30 . V_69 ||
V_63 . V_30 . V_70 != V_64 . V_30 . V_70 )
return - V_65 ;
}
return 0 ;
}
static int F_22 ( struct V_43 * V_44 )
{
struct V_46 V_47 ;
struct V_1 * V_10 ;
struct V_13 * V_14 ;
struct V_40 * V_41 ;
int V_33 = 0 ;
if ( V_44 -> V_55 == V_56 )
V_10 = F_1 ( V_44 -> V_52 [ 0 ] ) ;
else
V_10 = & V_44 -> V_51 [ 0 ] -> V_39 . V_10 ;
V_41 = V_10 -> V_42 ;
F_12 ( & V_41 -> V_53 ) ;
F_13 ( & V_47 , V_10 ) ;
while ( ( V_10 = F_14 ( & V_47 ) ) ) {
if ( F_15 ( V_10 ) == V_54 )
continue;
V_14 = F_5 ( V_10 ) ;
V_33 = F_8 ( V_14 , V_3 , V_71 , 1 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
break;
}
F_18 ( & V_41 -> V_53 ) ;
return V_33 ;
}
static int F_23 ( struct V_43 * V_44 )
{
struct V_46 V_47 ;
struct V_1 * V_10 ;
struct V_13 * V_14 ;
struct V_40 * V_41 ;
int V_33 = 0 ;
if ( V_44 -> V_55 == V_56 )
V_10 = F_1 ( V_44 -> V_52 [ 0 ] ) ;
else
V_10 = & V_44 -> V_51 [ 0 ] -> V_39 . V_10 ;
V_41 = V_10 -> V_42 ;
F_12 ( & V_41 -> V_53 ) ;
F_13 ( & V_47 , V_10 ) ;
while ( ( V_10 = F_14 ( & V_47 ) ) ) {
if ( F_15 ( V_10 ) == V_54 )
continue;
V_14 = F_5 ( V_10 ) ;
V_33 = F_8 ( V_14 , V_3 , V_71 , 0 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
break;
}
F_18 ( & V_41 -> V_53 ) ;
return ( V_33 == 0 ) ? V_33 : - V_72 ;
}
static int F_24 ( struct V_43 * V_44 ,
enum V_73 V_55 )
{
if ( V_55 == V_74 )
return F_23 ( V_44 ) ;
return F_22 ( V_44 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_44 -> V_48 ; V_15 ++ )
if ( V_44 -> V_51 [ V_15 ] -> V_61 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_44 -> V_49 ; V_15 ++ )
if ( V_44 -> V_52 [ V_15 ] -> V_61 )
return 0 ;
return 1 ;
}
static int F_26 ( struct V_75 * V_75 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_76 * V_77 ;
V_77 = F_28 ( sizeof( struct V_76 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_79 ;
F_29 ( & V_77 -> V_80 , & V_3 -> V_39 ) ;
F_30 ( & V_77 -> V_80 ) ;
F_12 ( & V_3 -> V_81 ) ;
if ( ! V_3 -> V_58 && F_19 ( V_3 ) ) {
F_18 ( & V_3 -> V_81 ) ;
return - V_82 ;
}
V_3 -> V_83 ++ ;
V_77 -> V_84 = 0 ;
F_31 ( & V_3 -> V_85 , & V_77 -> V_85 ) ;
V_77 -> V_3 = V_3 ;
V_75 -> V_86 = & V_77 -> V_80 ;
F_18 ( & V_3 -> V_81 ) ;
return 0 ;
}
static unsigned long
F_32 ( struct V_2 * V_3 )
{
V_3 -> V_87 = V_3 -> V_88 =
F_33 ( V_3 -> V_89 . V_90 ,
struct V_91 , V_92 ) ;
F_34 ( & V_3 -> V_88 -> V_92 ) ;
V_3 -> V_88 -> V_93 . V_55 = V_94 ;
return F_35 ( & V_3 -> V_88 -> V_93 , 0 ) ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_95 ;
if ( F_37 ( & V_3 -> V_89 ) )
return;
V_3 -> V_88 = F_33 ( V_3 -> V_89 . V_90 ,
struct V_91 , V_92 ) ;
if ( V_57 == V_3 -> V_44 . V_55 )
V_3 -> V_87 = V_3 -> V_88 ;
F_34 ( & V_3 -> V_88 -> V_92 ) ;
V_3 -> V_88 -> V_93 . V_55 = V_94 ;
V_95 = F_35 ( & V_3 -> V_88 -> V_93 , 0 ) ;
V_3 -> V_96 -> V_97 ( V_5 , V_95 ) ;
V_3 -> V_55 = V_62 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_95 ;
V_95 = F_35 ( & V_3 -> V_87 -> V_93 , 0 ) ;
V_95 += V_3 -> V_98 ;
V_3 -> V_96 -> V_97 ( V_5 , V_95 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
F_40 ( & V_3 -> V_87 -> V_93 . V_99 . V_100 ) ;
F_41 ( & V_3 -> V_87 -> V_93 , V_101 ) ;
if ( V_44 -> V_55 == V_56 )
V_3 -> V_87 = V_3 -> V_88 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
V_3 -> V_61 = 0 ;
if ( V_3 -> type == V_50 )
return;
if ( F_25 ( V_3 ) )
F_24 ( V_44 ,
V_74 ) ;
}
static int F_43 ( struct V_75 * V_75 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_102 * V_80 = V_75 -> V_86 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_103 = F_44 ( V_80 , struct V_76 , V_80 ) ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_4 ) ;
F_12 ( & V_3 -> V_81 ) ;
if ( V_103 -> V_84 ) {
if ( V_3 -> V_61 ) {
F_42 ( V_3 ) ;
V_3 -> V_44 . V_55 = V_74 ;
F_46 ( & V_3 -> V_106 ,
V_3 -> V_106 . type ) ;
}
V_3 -> V_107 = 0 ;
F_47 ( & V_3 -> V_106 ) ;
F_48 ( V_3 -> V_108 ) ;
}
V_3 -> V_83 -- ;
F_49 ( & V_3 -> V_85 , V_103 -> V_85 ) ;
if ( ! V_3 -> V_83 )
V_3 -> V_58 = 0 ;
F_18 ( & V_3 -> V_81 ) ;
V_75 -> V_86 = NULL ;
F_50 ( V_80 ) ;
F_51 ( V_103 ) ;
return 0 ;
}
static int F_52 ( struct V_75 * V_75 , struct V_109 * V_110 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_5 ) ;
return F_53 ( & V_3 -> V_106 , V_110 ) ;
}
static unsigned int F_54 ( struct V_75 * V_75 , T_2 * V_111 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_6 ) ;
if ( V_3 -> V_61 )
return F_55 ( & V_3 -> V_106 , V_75 , V_111 ) ;
return 0 ;
}
static int F_56 ( struct V_75 * V_75 , void * V_112 ,
struct V_113 * V_114 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_7 ) ;
if ( V_3 -> type == V_115 )
V_114 -> V_116 = V_117 | V_118 ;
else
V_114 -> V_116 = V_119 | V_118 ;
V_114 -> V_120 = V_114 -> V_116 ;
V_114 -> V_121 = V_122 ;
F_57 ( V_114 -> V_123 , V_124 , sizeof( V_114 -> V_123 ) ) ;
F_57 ( V_114 -> V_125 , L_8 , sizeof( V_114 -> V_125 ) ) ;
F_57 ( V_114 -> V_126 , V_5 -> V_127 -> V_128 , sizeof( V_114 -> V_126 ) ) ;
return 0 ;
}
static int F_58 ( struct V_75 * V_75 , void * V_112 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_9 ) ;
* V_32 = V_3 -> V_32 ;
return 0 ;
}
static int F_59 ( struct V_75 * V_75 , void * V_112 ,
struct V_129 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_31 V_130 ;
struct V_131 V_132 ;
struct V_13 * V_14 ;
struct V_29 V_30 ;
struct V_6 * V_7 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_10 ) ;
if ( V_32 -> V_28 > 0 ) {
F_60 ( & V_5 -> V_105 , L_11 ) ;
return - V_16 ;
}
V_7 = F_2 ( & V_3 -> V_26 ) ;
if ( V_7 == NULL ) {
F_60 ( & V_5 -> V_105 ,
L_12 ) ;
return - V_16 ;
}
V_14 = F_6 ( V_3 , NULL ) ;
if ( V_14 == NULL ) {
F_60 ( & V_5 -> V_105 ,
L_13 ) ;
return - V_16 ;
}
V_130 . V_26 = V_7 -> V_28 ;
V_130 . V_34 = V_35 ;
V_33 = F_8 ( V_14 , V_26 , V_36 , NULL , & V_130 ) ;
if ( V_33 ) {
F_60 ( & V_5 -> V_105 ,
L_13 ) ;
return V_33 ;
}
V_132 . V_68 = V_130 . V_30 . V_68 ;
F_10 ( & V_132 , & V_30 . V_32 . V_38 ) ;
V_32 -> V_133 = V_30 . V_32 . V_38 . V_133 ;
return 0 ;
}
static int F_61 ( struct V_75 * V_75 , void * V_112 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_29 V_30 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_14 ) ;
if ( V_3 -> V_61 ) {
F_60 ( & V_5 -> V_105 , L_15 ) ;
return - V_134 ;
}
V_33 = F_7 ( V_3 , & V_30 ) ;
if ( V_33 )
return V_33 ;
* V_32 = V_30 ;
V_3 -> V_32 = * V_32 ;
return 0 ;
}
static int F_62 ( struct V_75 * V_75 , void * V_112 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_29 V_30 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_16 ) ;
V_33 = F_7 ( V_3 , & V_30 ) ;
if ( V_33 )
return V_33 ;
* V_32 = V_30 ;
return 0 ;
}
static int F_63 ( struct V_75 * V_75 , void * V_112 ,
struct V_135 * V_136 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_137 * V_138 = V_3 -> V_23 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_17 ) ;
if ( V_136 -> V_28 < V_138 -> V_139 ) {
memcpy ( V_136 , & V_138 -> V_51 [ V_136 -> V_28 ] ,
sizeof( struct V_135 ) ) ;
return 0 ;
}
return - V_16 ;
}
static int F_64 ( struct V_75 * V_75 , void * V_112 , unsigned int * V_28 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_18 ) ;
* V_28 = V_3 -> V_140 ;
return 0 ;
}
static int F_65 ( struct V_75 * V_75 , void * V_112 , unsigned int V_28 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_137 * V_138 ;
struct V_141 * V_142 ;
struct V_135 * V_143 ;
T_1 V_144 ;
T_1 V_145 ;
int V_33 ;
int V_15 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_19 ) ;
V_33 = F_66 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
if ( V_3 -> V_61 ) {
F_60 ( & V_5 -> V_105 , L_20 ) ;
V_33 = - V_134 ;
goto V_146;
}
V_138 = V_3 -> V_23 ;
if ( ! V_138 -> V_147 ) {
V_33 = - V_16 ;
goto V_146;
}
if ( V_5 -> V_127 -> V_148 &&
V_5 -> V_127 -> V_148 ( V_138 -> V_149 ) < 0 ) {
V_33 = - V_150 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 ,
L_21 ,
V_138 -> V_21 ) ;
goto V_146;
}
V_142 = & V_138 -> V_151 [ V_28 ] ;
if ( V_142 && V_138 -> V_152 ) {
V_145 = V_142 -> V_145 ;
V_144 = V_142 -> V_144 ;
V_33 = F_67 ( & V_5 -> V_105 ,
V_138 -> V_149 , V_3 ,
V_153 , V_145 , V_144 , 0 ) ;
if ( V_33 ) {
F_45 ( 1 , V_104 , & V_5 -> V_105 ,
L_22 ) ;
V_33 = - V_16 ;
goto V_146;
}
}
for ( V_15 = 0 ; V_15 < V_138 -> V_139 ; V_15 ++ ) {
V_143 = & V_138 -> V_51 [ V_15 ] ;
V_3 -> V_39 . V_154 |= V_143 -> V_155 ;
}
V_3 -> V_140 = V_28 ;
V_146:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_68 ( struct V_75 * V_75 , void * V_112 , T_3 * V_156 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_137 * V_138 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_23 ) ;
V_33 = F_66 ( & V_3 -> V_81 ) ;
V_138 = V_3 -> V_23 ;
if ( V_33 )
return V_33 ;
V_33 = F_67 ( & V_5 -> V_105 , V_138 -> V_149 ,
V_3 , V_157 , V_156 ) ;
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_69 ( struct V_75 * V_75 , void * V_112 , T_3 * V_156 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_137 * V_138 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_24 ) ;
V_33 = F_66 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
V_138 = V_3 -> V_23 ;
if ( V_3 -> V_61 ) {
F_60 ( & V_5 -> V_105 , L_25 ) ;
V_33 = - V_134 ;
goto V_146;
}
V_33 = F_67 ( & V_5 -> V_105 , V_138 -> V_149 ,
V_158 , V_159 , * V_156 ) ;
if ( V_33 < 0 ) {
F_60 ( & V_5 -> V_105 , L_26 ) ;
V_3 -> V_160 = V_161 ;
goto V_146;
}
V_3 -> V_160 = * V_156 ;
V_146:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_70 ( struct V_75 * V_75 , void * V_112 , T_3 * V_162 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_27 ) ;
* V_162 = V_3 -> V_160 ;
return 0 ;
}
static int
F_71 ( struct V_75 * V_75 , void * V_103 ,
struct V_163 * V_164 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_28 ) ;
return F_8 ( V_14 , V_3 , V_165 , V_164 ) ;
}
static int
F_72 ( struct V_75 * V_75 , void * V_103 ,
struct V_166 * V_164 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_29 ) ;
return F_8 ( V_14 , V_3 , V_167 , V_164 ) ;
}
static int
F_73 ( struct V_75 * V_75 , void * V_103 ,
struct V_166 * V_164 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_30 ) ;
V_3 -> V_160 = V_161 ;
return F_67 ( & V_5 -> V_105 ,
V_3 -> V_23 -> V_149 ,
V_3 , V_168 , V_164 ) ;
}
static int
F_74 ( struct V_75 * V_75 , void * V_103 ,
struct V_166 * V_164 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_31 ) ;
return F_8 ( V_14 , V_3 , V_169 , V_164 ) ;
}
static int
F_75 ( struct V_170 * V_171 , const struct V_29 * V_32 ,
unsigned int * V_172 , unsigned int * V_173 ,
unsigned int V_174 [] , void * V_175 [] )
{
struct V_76 * V_103 = F_76 ( V_171 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
unsigned long V_176 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_32 ) ;
V_176 = V_3 -> V_32 . V_32 . V_38 . V_177 ;
if ( V_5 -> V_178 ) {
while ( V_176 * * V_172 > V_5 -> V_178 )
( * V_172 ) -- ;
}
if ( V_44 -> V_55 == V_56 ) {
if ( * V_172 < V_179 )
* V_172 = V_179 ;
}
* V_173 = 1 ;
V_174 [ 0 ] = V_176 ;
V_175 [ 0 ] = V_3 -> V_108 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 ,
L_33 , * V_172 , V_176 ) ;
return 0 ;
}
static int F_77 ( struct V_180 * V_93 )
{
struct V_76 * V_103 = F_76 ( V_93 -> V_170 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_95 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_34 ) ;
if ( V_93 -> V_55 != V_94 &&
V_93 -> V_55 != V_181 )
return 0 ;
F_78 ( V_93 , 0 , V_3 -> V_32 . V_32 . V_38 . V_177 ) ;
if ( F_79 ( V_93 , 0 ) &&
F_80 ( V_93 , 0 ) > F_81 ( V_93 , 0 ) )
return - V_16 ;
V_95 = F_35 ( V_93 , 0 ) ;
if ( ! F_82 ( V_95 , 32 ) )
return - V_16 ;
return 0 ;
}
static void F_83 ( struct V_180 * V_93 )
{
struct V_76 * V_103 = F_76 ( V_93 -> V_170 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
struct V_91 * V_182 = F_44 ( V_93 ,
struct V_91 , V_93 ) ;
unsigned long V_66 ;
unsigned long V_183 ;
unsigned long V_95 ;
F_84 ( & V_3 -> V_184 , V_66 ) ;
V_183 = F_37 ( & V_3 -> V_89 ) ;
F_85 ( & V_182 -> V_92 , & V_3 -> V_89 ) ;
F_86 ( & V_3 -> V_184 , V_66 ) ;
if ( V_183 && V_3 -> V_61 && V_44 -> V_55 ==
V_57 &&
V_3 -> V_55 == V_185 ) {
F_87 ( & V_3 -> V_184 ) ;
V_95 = F_32 ( V_3 ) ;
V_3 -> V_96 -> V_97 ( V_5 , V_95 ) ;
V_3 -> V_55 = V_62 ;
F_88 ( & V_3 -> V_184 ) ;
if ( F_20 ( V_44 ) )
F_24 ( V_44 ,
V_57 ) ;
}
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
int V_33 = 0 ;
V_3 -> V_61 = 1 ;
if ( F_20 ( V_44 ) )
V_33 = F_24 ( V_44 , V_44 -> V_55 ) ;
return V_33 ;
}
static int F_90 ( struct V_170 * V_171 , unsigned int V_186 )
{
struct V_76 * V_103 = F_76 ( V_171 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_95 ;
int V_33 ;
V_33 = F_66 ( & V_3 -> V_81 ) ;
if ( V_33 )
goto V_187;
V_3 -> V_87 = V_3 -> V_88 =
F_33 ( V_3 -> V_89 . V_90 , struct V_91 , V_92 ) ;
F_34 ( & V_3 -> V_87 -> V_92 ) ;
V_3 -> V_87 -> V_93 . V_55 = V_94 ;
V_3 -> V_188 = 0 ;
V_95 = F_35 ( & V_3 -> V_87 -> V_93 , 0 ) ;
V_3 -> V_96 -> V_97 ( V_5 , V_95 ) ;
V_3 -> V_55 = V_62 ;
V_33 = F_89 ( V_3 ) ;
if ( V_33 )
goto V_146;
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
V_146:
F_18 ( & V_3 -> V_81 ) ;
V_187:
V_33 = F_46 ( & V_3 -> V_106 , V_3 -> V_106 . type ) ;
return 0 ;
}
static int F_91 ( struct V_180 * V_93 )
{
struct V_91 * V_182 = F_44 ( V_93 ,
struct V_91 , V_93 ) ;
F_92 ( & V_182 -> V_92 ) ;
return 0 ;
}
static int F_93 ( struct V_170 * V_171 )
{
struct V_76 * V_103 = F_76 ( V_171 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
if ( ! F_94 ( V_171 ) )
return 0 ;
while ( ! F_37 ( & V_3 -> V_89 ) ) {
V_3 -> V_88 = F_33 ( V_3 -> V_89 . V_90 ,
struct V_91 , V_92 ) ;
F_34 ( & V_3 -> V_88 -> V_92 ) ;
F_41 ( & V_3 -> V_88 -> V_93 , V_189 ) ;
}
return 0 ;
}
static void F_95 ( struct V_180 * V_93 )
{
struct V_76 * V_103 = F_76 ( V_93 -> V_170 ) ;
struct V_2 * V_3 = V_103 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_91 * V_182 = F_44 ( V_93 ,
struct V_91 , V_93 ) ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_35 ) ;
if ( V_93 -> V_55 == V_94 )
F_96 ( & V_182 -> V_92 ) ;
}
static int F_97 ( struct V_75 * V_75 , void * V_112 ,
struct V_190 * V_191 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_103 = V_75 -> V_86 ;
struct V_170 * V_192 ;
int V_33 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_36 ) ;
if ( V_115 != V_191 -> type &&
V_50 != V_191 -> type ) {
F_60 ( & V_5 -> V_105 , L_37 ) ;
return - V_16 ;
}
V_33 = F_66 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
if ( V_3 -> V_107 != 0 ) {
F_60 ( & V_5 -> V_105 , L_38 ) ;
V_33 = - V_134 ;
goto V_146;
}
V_3 -> V_193 = V_191 -> V_193 ;
V_3 -> V_108 = F_98 ( V_5 -> V_17 ) ;
if ( F_99 ( V_3 -> V_108 ) ) {
F_60 ( & V_5 -> V_105 , L_39 ) ;
return F_100 ( V_3 -> V_108 ) ;
}
V_192 = & V_3 -> V_106 ;
V_192 -> type = V_191 -> type ;
V_192 -> V_194 = V_195 | V_196 ;
V_192 -> V_197 = V_103 ;
V_192 -> V_96 = & V_198 ;
V_192 -> V_199 = & V_200 ;
V_192 -> V_201 = sizeof( struct V_91 ) ;
V_33 = F_101 ( V_192 ) ;
if ( V_33 ) {
F_60 ( & V_5 -> V_105 , L_40 ) ;
F_48 ( V_5 -> V_17 ) ;
return V_33 ;
}
V_103 -> V_84 = 1 ;
V_3 -> V_107 = 1 ;
F_92 ( & V_3 -> V_89 ) ;
V_33 = F_102 ( & V_3 -> V_106 , V_191 ) ;
V_146:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_103 ( struct V_75 * V_75 , void * V_112 ,
struct V_202 * V_182 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_41 ) ;
if ( V_115 != V_182 -> type &&
V_50 != V_182 -> type ) {
F_60 ( & V_5 -> V_105 , L_42 ) ;
return - V_16 ;
}
if ( V_3 -> V_193 != V_203 ) {
F_60 ( & V_5 -> V_105 , L_43 ) ;
return - V_16 ;
}
return F_104 ( & V_3 -> V_106 , V_182 ) ;
}
static int F_105 ( struct V_75 * V_75 , void * V_112 ,
struct V_202 * V_204 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_103 = V_75 -> V_86 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_44 ) ;
if ( V_115 != V_204 -> type &&
V_50 != V_204 -> type ) {
F_60 ( & V_5 -> V_105 , L_42 ) ;
return - V_16 ;
}
if ( ! V_103 -> V_84 ) {
F_60 ( & V_5 -> V_105 , L_45 ) ;
return - V_205 ;
}
return F_106 ( & V_3 -> V_106 , V_204 ) ;
}
static int F_107 ( struct V_75 * V_75 , void * V_112 ,
struct V_202 * V_182 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_46 ) ;
if ( V_115 != V_182 -> type &&
V_50 != V_182 -> type ) {
F_60 ( & V_5 -> V_105 , L_42 ) ;
return - V_16 ;
}
return F_108 ( & V_3 -> V_106 ,
V_182 , ( V_75 -> V_206 & V_207 ) ) ;
}
static int F_109 ( struct V_75 * V_75 , void * V_112 ,
enum V_208 V_209 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
struct V_76 * V_103 = V_75 -> V_86 ;
struct V_137 * V_138 ;
int V_33 = - V_16 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_47 ) ;
if ( V_115 != V_209 &&
V_50 != V_209 ) {
F_60 ( & V_5 -> V_105 , L_42 ) ;
return V_33 ;
}
if ( ! V_103 -> V_84 ) {
F_60 ( & V_5 -> V_105 , L_45 ) ;
return - V_205 ;
}
V_138 = V_3 -> V_23 ;
if ( F_37 ( & V_3 -> V_106 . V_210 ) ) {
F_60 ( & V_5 -> V_105 , L_48 ) ;
return - V_211 ;
}
if ( V_115 == V_209 ) {
V_33 = F_21 ( V_44 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return F_110 ( & V_3 -> V_106 , V_209 ) ;
}
static int F_111 ( struct V_75 * V_75 , void * V_112 ,
enum V_208 V_209 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_103 = V_75 -> V_86 ;
int V_33 = 0 ;
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_49 ) ;
if ( V_209 != V_115 &&
V_209 != V_50 ) {
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_42 ) ;
return - V_16 ;
}
if ( ! V_103 -> V_84 ) {
F_45 ( 1 , V_104 , & V_5 -> V_105 , L_45 ) ;
return - V_205 ;
}
if ( ! V_3 -> V_61 ) {
F_60 ( & V_5 -> V_105 , L_50 ) ;
return - V_16 ;
}
V_33 = F_66 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
F_42 ( V_3 ) ;
V_33 = F_46 ( & V_3 -> V_106 , V_209 ) ;
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
int F_112 ( struct V_2 * V_3 , const char * V_22 )
{
const char * V_212 ;
int V_33 ;
switch ( V_3 -> type ) {
case V_115 :
V_212 = L_51 ;
V_3 -> V_26 . V_66 = V_67 ;
V_3 -> type = V_115 ;
break;
case V_50 :
V_212 = L_52 ;
V_3 -> V_26 . V_66 = V_213 ;
V_3 -> type = V_50 ;
break;
default:
return - V_16 ;
}
V_3 -> V_39 . V_214 = V_215 ;
V_3 -> V_39 . V_216 = & V_217 ;
V_3 -> V_39 . V_218 = & V_219 ;
V_3 -> V_39 . V_220 = - 1 ;
V_3 -> V_39 . V_154 = 0 ;
snprintf ( V_3 -> V_39 . V_22 , sizeof( V_3 -> V_39 . V_22 ) ,
L_53 , V_22 , V_212 ) ;
F_113 ( & V_3 -> V_85 ) ;
F_114 ( & V_3 -> V_221 ) ;
F_114 ( & V_3 -> V_184 ) ;
F_115 ( & V_3 -> V_81 ) ;
V_33 = F_116 ( & V_3 -> V_39 . V_10 ,
1 , & V_3 -> V_26 , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
F_117 ( & V_3 -> V_39 , V_3 ) ;
return 0 ;
}
int F_118 ( struct V_2 * V_3 ,
struct V_222 * V_223 )
{
int V_33 ;
V_3 -> V_39 . V_105 = V_223 ;
V_33 = F_119 ( & V_3 -> V_39 , V_224 , - 1 ) ;
if ( V_33 < 0 )
F_3 ( L_54 ,
V_225 , V_33 ) ;
return V_33 ;
}
void F_120 ( struct V_2 * V_3 )
{
if ( F_121 ( & V_3 -> V_39 ) ) {
F_122 ( & V_3 -> V_39 . V_10 ) ;
F_123 ( & V_3 -> V_39 ) ;
}
}
