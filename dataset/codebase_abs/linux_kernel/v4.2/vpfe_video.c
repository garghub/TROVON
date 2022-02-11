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
return V_33 ? - V_72 : 0 ;
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
V_77 -> V_3 = V_3 ;
V_75 -> V_85 = & V_77 -> V_80 ;
F_18 ( & V_3 -> V_81 ) ;
return 0 ;
}
static unsigned long
F_31 ( struct V_2 * V_3 )
{
V_3 -> V_86 = V_3 -> V_87 =
F_32 ( V_3 -> V_88 . V_89 ,
struct V_90 , V_91 ) ;
F_33 ( & V_3 -> V_87 -> V_91 ) ;
V_3 -> V_87 -> V_92 . V_55 = V_93 ;
return F_34 ( & V_3 -> V_87 -> V_92 , 0 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
if ( F_36 ( & V_3 -> V_88 ) )
return;
V_3 -> V_87 = F_32 ( V_3 -> V_88 . V_89 ,
struct V_90 , V_91 ) ;
if ( V_57 == V_3 -> V_44 . V_55 )
V_3 -> V_86 = V_3 -> V_87 ;
F_33 ( & V_3 -> V_87 -> V_91 ) ;
V_3 -> V_87 -> V_92 . V_55 = V_93 ;
V_94 = F_34 ( & V_3 -> V_87 -> V_92 , 0 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_55 = V_62 ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
V_94 = F_34 ( & V_3 -> V_86 -> V_92 , 0 ) ;
V_94 += V_3 -> V_97 ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
F_39 ( & V_3 -> V_86 -> V_92 . V_98 . V_99 ) ;
F_40 ( & V_3 -> V_86 -> V_92 , V_100 ) ;
if ( V_44 -> V_55 == V_56 )
V_3 -> V_86 = V_3 -> V_87 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
V_3 -> V_61 = 0 ;
if ( V_3 -> type == V_50 )
return;
if ( F_25 ( V_3 ) )
F_24 ( V_44 ,
V_74 ) ;
}
static int F_42 ( struct V_75 * V_75 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_101 * V_80 = V_75 -> V_85 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_102 = F_43 ( V_80 , struct V_76 , V_80 ) ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_4 ) ;
F_12 ( & V_3 -> V_81 ) ;
if ( V_102 -> V_84 ) {
if ( V_3 -> V_61 ) {
F_41 ( V_3 ) ;
V_3 -> V_44 . V_55 = V_74 ;
F_45 ( & V_3 -> V_105 ,
V_3 -> V_105 . type ) ;
}
V_3 -> V_106 = 0 ;
F_46 ( & V_3 -> V_105 ) ;
F_47 ( V_3 -> V_107 ) ;
}
V_3 -> V_83 -- ;
F_48 ( & V_102 -> V_80 ) ;
F_49 ( & V_102 -> V_80 ) ;
if ( ! V_3 -> V_83 )
V_3 -> V_58 = 0 ;
F_18 ( & V_3 -> V_81 ) ;
V_75 -> V_85 = NULL ;
F_48 ( V_80 ) ;
F_50 ( V_102 ) ;
return 0 ;
}
static int F_51 ( struct V_75 * V_75 , struct V_108 * V_109 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_5 ) ;
return F_52 ( & V_3 -> V_105 , V_109 ) ;
}
static unsigned int F_53 ( struct V_75 * V_75 , T_2 * V_110 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_6 ) ;
if ( V_3 -> V_61 )
return F_54 ( & V_3 -> V_105 , V_75 , V_110 ) ;
return 0 ;
}
static int F_55 ( struct V_75 * V_75 , void * V_111 ,
struct V_112 * V_113 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_7 ) ;
if ( V_3 -> type == V_114 )
V_113 -> V_115 = V_116 | V_117 ;
else
V_113 -> V_115 = V_118 | V_117 ;
V_113 -> V_119 = V_116 | V_118 |
V_117 | V_120 ;
F_56 ( V_113 -> V_121 , V_122 , sizeof( V_113 -> V_121 ) ) ;
F_56 ( V_113 -> V_123 , L_8 , sizeof( V_113 -> V_123 ) ) ;
F_56 ( V_113 -> V_124 , V_5 -> V_125 -> V_126 , sizeof( V_113 -> V_124 ) ) ;
return 0 ;
}
static int F_57 ( struct V_75 * V_75 , void * V_111 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_9 ) ;
* V_32 = V_3 -> V_32 ;
return 0 ;
}
static int F_58 ( struct V_75 * V_75 , void * V_111 ,
struct V_127 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_31 V_128 ;
struct V_129 V_130 ;
struct V_13 * V_14 ;
struct V_29 V_30 ;
struct V_6 * V_7 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_10 ) ;
if ( V_32 -> V_28 > 0 ) {
F_59 ( & V_5 -> V_104 , L_11 ) ;
return - V_16 ;
}
V_7 = F_2 ( & V_3 -> V_26 ) ;
if ( V_7 == NULL ) {
F_59 ( & V_5 -> V_104 ,
L_12 ) ;
return - V_16 ;
}
V_14 = F_6 ( V_3 , NULL ) ;
if ( V_14 == NULL ) {
F_59 ( & V_5 -> V_104 ,
L_13 ) ;
return - V_16 ;
}
V_128 . V_26 = V_7 -> V_28 ;
V_128 . V_34 = V_35 ;
V_33 = F_8 ( V_14 , V_26 , V_36 , NULL , & V_128 ) ;
if ( V_33 ) {
F_59 ( & V_5 -> V_104 ,
L_13 ) ;
return V_33 ;
}
V_130 . V_68 = V_128 . V_30 . V_68 ;
F_10 ( & V_130 , & V_30 . V_32 . V_38 ) ;
V_32 -> V_131 = V_30 . V_32 . V_38 . V_131 ;
return 0 ;
}
static int F_60 ( struct V_75 * V_75 , void * V_111 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_29 V_30 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_14 ) ;
if ( V_3 -> V_61 ) {
F_59 ( & V_5 -> V_104 , L_15 ) ;
return - V_132 ;
}
V_33 = F_7 ( V_3 , & V_30 ) ;
if ( V_33 )
return V_33 ;
* V_32 = V_30 ;
V_3 -> V_32 = * V_32 ;
return 0 ;
}
static int F_61 ( struct V_75 * V_75 , void * V_111 ,
struct V_29 * V_32 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_29 V_30 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_16 ) ;
V_33 = F_7 ( V_3 , & V_30 ) ;
if ( V_33 )
return V_33 ;
* V_32 = V_30 ;
return 0 ;
}
static int F_62 ( struct V_75 * V_75 , void * V_111 ,
struct V_133 * V_134 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_135 * V_136 = V_3 -> V_23 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_17 ) ;
if ( V_134 -> V_28 < V_136 -> V_137 ) {
memcpy ( V_134 , & V_136 -> V_51 [ V_134 -> V_28 ] ,
sizeof( struct V_133 ) ) ;
return 0 ;
}
return - V_16 ;
}
static int F_63 ( struct V_75 * V_75 , void * V_111 , unsigned int * V_28 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_18 ) ;
* V_28 = V_3 -> V_138 ;
return 0 ;
}
static int F_64 ( struct V_75 * V_75 , void * V_111 , unsigned int V_28 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_135 * V_136 ;
struct V_139 * V_140 ;
struct V_133 * V_141 ;
T_1 V_142 ;
T_1 V_143 ;
int V_33 ;
int V_15 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_19 ) ;
V_33 = F_65 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
if ( V_3 -> V_61 ) {
F_59 ( & V_5 -> V_104 , L_20 ) ;
V_33 = - V_132 ;
goto V_144;
}
V_136 = V_3 -> V_23 ;
if ( ! V_136 -> V_145 ) {
V_33 = - V_16 ;
goto V_144;
}
if ( V_5 -> V_125 -> V_146 &&
V_5 -> V_125 -> V_146 ( V_136 -> V_147 ) < 0 ) {
V_33 = - V_148 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 ,
L_21 ,
V_136 -> V_21 ) ;
goto V_144;
}
V_140 = & V_136 -> V_149 [ V_28 ] ;
if ( V_140 && V_136 -> V_150 ) {
V_143 = V_140 -> V_143 ;
V_142 = V_140 -> V_142 ;
V_33 = F_66 ( & V_5 -> V_104 ,
V_136 -> V_147 , V_3 ,
V_151 , V_143 , V_142 , 0 ) ;
if ( V_33 ) {
F_44 ( 1 , V_103 , & V_5 -> V_104 ,
L_22 ) ;
V_33 = - V_16 ;
goto V_144;
}
}
for ( V_15 = 0 ; V_15 < V_136 -> V_137 ; V_15 ++ ) {
V_141 = & V_136 -> V_51 [ V_15 ] ;
V_3 -> V_39 . V_152 |= V_141 -> V_153 ;
}
V_3 -> V_138 = V_28 ;
V_144:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_67 ( struct V_75 * V_75 , void * V_111 , T_3 * V_154 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_135 * V_136 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_23 ) ;
V_33 = F_65 ( & V_3 -> V_81 ) ;
V_136 = V_3 -> V_23 ;
if ( V_33 )
return V_33 ;
V_33 = F_66 ( & V_5 -> V_104 , V_136 -> V_147 ,
V_3 , V_155 , V_154 ) ;
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_68 ( struct V_75 * V_75 , void * V_111 , T_3 V_154 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_135 * V_136 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_24 ) ;
V_33 = F_65 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
V_136 = V_3 -> V_23 ;
if ( V_3 -> V_61 ) {
F_59 ( & V_5 -> V_104 , L_25 ) ;
V_33 = - V_132 ;
goto V_144;
}
V_33 = F_66 ( & V_5 -> V_104 , V_136 -> V_147 ,
V_3 , V_156 , V_154 ) ;
if ( V_33 < 0 ) {
F_59 ( & V_5 -> V_104 , L_26 ) ;
V_3 -> V_157 = V_158 ;
goto V_144;
}
V_3 -> V_157 = V_154 ;
V_144:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_69 ( struct V_75 * V_75 , void * V_111 , T_3 * V_159 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_27 ) ;
* V_159 = V_3 -> V_157 ;
return 0 ;
}
static int
F_70 ( struct V_75 * V_75 , void * V_102 ,
struct V_160 * V_161 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
V_161 -> V_26 = 0 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_28 ) ;
return F_8 ( V_14 , V_26 , V_162 , V_161 ) ;
}
static int
F_71 ( struct V_75 * V_75 , void * V_102 ,
struct V_163 * V_161 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_29 ) ;
return F_8 ( V_14 , V_3 , V_164 , V_161 ) ;
}
static int
F_72 ( struct V_75 * V_75 , void * V_102 ,
struct V_163 * V_161 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_30 ) ;
V_3 -> V_157 = V_158 ;
return F_66 ( & V_5 -> V_104 ,
V_3 -> V_23 -> V_147 ,
V_3 , V_165 , V_161 ) ;
}
static int
F_73 ( struct V_75 * V_75 , void * V_102 ,
struct V_163 * V_161 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_31 ) ;
return F_8 ( V_14 , V_3 , V_166 , V_161 ) ;
}
static int
F_74 ( struct V_167 * V_168 , const struct V_29 * V_32 ,
unsigned int * V_169 , unsigned int * V_170 ,
unsigned int V_171 [] , void * V_172 [] )
{
struct V_76 * V_102 = F_75 ( V_168 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_173 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_32 ) ;
V_173 = V_3 -> V_32 . V_32 . V_38 . V_174 ;
if ( V_168 -> V_175 + * V_169 < 3 )
* V_169 = 3 - V_168 -> V_175 ;
* V_170 = 1 ;
V_171 [ 0 ] = V_173 ;
V_172 [ 0 ] = V_3 -> V_107 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 ,
L_33 , * V_169 , V_173 ) ;
return 0 ;
}
static int F_76 ( struct V_176 * V_92 )
{
struct V_76 * V_102 = F_75 ( V_92 -> V_167 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_34 ) ;
if ( V_92 -> V_55 != V_93 &&
V_92 -> V_55 != V_177 )
return 0 ;
F_77 ( V_92 , 0 , V_3 -> V_32 . V_32 . V_38 . V_174 ) ;
if ( F_78 ( V_92 , 0 ) &&
F_79 ( V_92 , 0 ) > F_80 ( V_92 , 0 ) )
return - V_16 ;
V_94 = F_34 ( V_92 , 0 ) ;
if ( ! F_81 ( V_94 , 32 ) )
return - V_16 ;
return 0 ;
}
static void F_82 ( struct V_176 * V_92 )
{
struct V_76 * V_102 = F_75 ( V_92 -> V_167 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
struct V_90 * V_178 = F_43 ( V_92 ,
struct V_90 , V_92 ) ;
unsigned long V_66 ;
unsigned long V_179 ;
unsigned long V_94 ;
F_83 ( & V_3 -> V_180 , V_66 ) ;
V_179 = F_36 ( & V_3 -> V_88 ) ;
F_84 ( & V_178 -> V_91 , & V_3 -> V_88 ) ;
F_85 ( & V_3 -> V_180 , V_66 ) ;
if ( V_179 && V_3 -> V_61 && V_44 -> V_55 ==
V_57 &&
V_3 -> V_55 == V_181 ) {
F_86 ( & V_3 -> V_180 ) ;
V_94 = F_31 ( V_3 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_55 = V_62 ;
F_87 ( & V_3 -> V_180 ) ;
if ( F_20 ( V_44 ) )
F_24 ( V_44 ,
V_57 ) ;
}
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_44 ;
int V_33 = 0 ;
V_3 -> V_61 = 1 ;
if ( F_20 ( V_44 ) )
V_33 = F_24 ( V_44 , V_44 -> V_55 ) ;
return V_33 ;
}
static int F_89 ( struct V_167 * V_168 , unsigned int V_182 )
{
struct V_76 * V_102 = F_75 ( V_168 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
int V_33 ;
V_33 = F_65 ( & V_3 -> V_81 ) ;
if ( V_33 )
goto V_183;
V_3 -> V_86 = V_3 -> V_87 =
F_32 ( V_3 -> V_88 . V_89 , struct V_90 , V_91 ) ;
F_33 ( & V_3 -> V_86 -> V_91 ) ;
V_3 -> V_86 -> V_92 . V_55 = V_93 ;
V_3 -> V_184 = 0 ;
V_94 = F_34 ( & V_3 -> V_86 -> V_92 , 0 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_55 = V_62 ;
V_33 = F_88 ( V_3 ) ;
if ( V_33 ) {
struct V_90 * V_178 , * V_185 ;
F_40 ( & V_3 -> V_86 -> V_92 , V_186 ) ;
F_90 (buf, tmp, &video->dma_queue, list) {
F_33 ( & V_178 -> V_91 ) ;
F_40 ( & V_178 -> V_92 , V_186 ) ;
}
goto V_144;
}
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
V_144:
F_18 ( & V_3 -> V_81 ) ;
V_183:
V_33 = F_45 ( & V_3 -> V_105 , V_3 -> V_105 . type ) ;
return 0 ;
}
static int F_91 ( struct V_176 * V_92 )
{
struct V_90 * V_178 = F_43 ( V_92 ,
struct V_90 , V_92 ) ;
F_92 ( & V_178 -> V_91 ) ;
return 0 ;
}
static void F_93 ( struct V_167 * V_168 )
{
struct V_76 * V_102 = F_75 ( V_168 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
if ( V_3 -> V_86 == V_3 -> V_87 ) {
F_40 ( & V_3 -> V_86 -> V_92 , V_187 ) ;
} else {
if ( V_3 -> V_86 != NULL )
F_40 ( & V_3 -> V_86 -> V_92 ,
V_187 ) ;
if ( V_3 -> V_87 != NULL )
F_40 ( & V_3 -> V_87 -> V_92 ,
V_187 ) ;
}
while ( ! F_36 ( & V_3 -> V_88 ) ) {
V_3 -> V_87 = F_32 ( V_3 -> V_88 . V_89 ,
struct V_90 , V_91 ) ;
F_33 ( & V_3 -> V_87 -> V_91 ) ;
F_40 ( & V_3 -> V_87 -> V_92 , V_187 ) ;
}
}
static void F_94 ( struct V_176 * V_92 )
{
struct V_76 * V_102 = F_75 ( V_92 -> V_167 ) ;
struct V_2 * V_3 = V_102 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_90 * V_178 = F_43 ( V_92 ,
struct V_90 , V_92 ) ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_35 ) ;
if ( V_92 -> V_55 == V_93 )
F_95 ( & V_178 -> V_91 ) ;
}
static int F_96 ( struct V_75 * V_75 , void * V_111 ,
struct V_188 * V_189 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_102 = V_75 -> V_85 ;
struct V_167 * V_190 ;
int V_33 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_36 ) ;
if ( V_114 != V_189 -> type &&
V_50 != V_189 -> type ) {
F_59 ( & V_5 -> V_104 , L_37 ) ;
return - V_16 ;
}
V_33 = F_65 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
if ( V_3 -> V_106 != 0 ) {
F_59 ( & V_5 -> V_104 , L_38 ) ;
V_33 = - V_132 ;
goto V_144;
}
V_3 -> V_191 = V_189 -> V_191 ;
V_3 -> V_107 = F_97 ( V_5 -> V_17 ) ;
if ( F_98 ( V_3 -> V_107 ) ) {
F_59 ( & V_5 -> V_104 , L_39 ) ;
return F_99 ( V_3 -> V_107 ) ;
}
V_190 = & V_3 -> V_105 ;
V_190 -> type = V_189 -> type ;
V_190 -> V_192 = V_193 | V_194 ;
V_190 -> V_195 = V_102 ;
V_190 -> V_196 = 1 ;
V_190 -> V_95 = & V_197 ;
V_190 -> V_198 = & V_199 ;
V_190 -> V_200 = sizeof( struct V_90 ) ;
V_190 -> V_201 = V_202 ;
V_33 = F_100 ( V_190 ) ;
if ( V_33 ) {
F_59 ( & V_5 -> V_104 , L_40 ) ;
F_47 ( V_5 -> V_17 ) ;
return V_33 ;
}
V_102 -> V_84 = 1 ;
V_3 -> V_106 = 1 ;
F_92 ( & V_3 -> V_88 ) ;
V_33 = F_101 ( & V_3 -> V_105 , V_189 ) ;
V_144:
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
static int F_102 ( struct V_75 * V_75 , void * V_111 ,
struct V_203 * V_178 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_41 ) ;
if ( V_114 != V_178 -> type &&
V_50 != V_178 -> type ) {
F_59 ( & V_5 -> V_104 , L_42 ) ;
return - V_16 ;
}
if ( V_3 -> V_191 != V_204 ) {
F_59 ( & V_5 -> V_104 , L_43 ) ;
return - V_16 ;
}
return F_103 ( & V_3 -> V_105 , V_178 ) ;
}
static int F_104 ( struct V_75 * V_75 , void * V_111 ,
struct V_203 * V_205 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_102 = V_75 -> V_85 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_44 ) ;
if ( V_114 != V_205 -> type &&
V_50 != V_205 -> type ) {
F_59 ( & V_5 -> V_104 , L_42 ) ;
return - V_16 ;
}
if ( ! V_102 -> V_84 ) {
F_59 ( & V_5 -> V_104 , L_45 ) ;
return - V_206 ;
}
return F_105 ( & V_3 -> V_105 , V_205 ) ;
}
static int F_106 ( struct V_75 * V_75 , void * V_111 ,
struct V_203 * V_178 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_46 ) ;
if ( V_114 != V_178 -> type &&
V_50 != V_178 -> type ) {
F_59 ( & V_5 -> V_104 , L_42 ) ;
return - V_16 ;
}
return F_107 ( & V_3 -> V_105 ,
V_178 , ( V_75 -> V_207 & V_208 ) ) ;
}
static int F_108 ( struct V_75 * V_75 , void * V_111 ,
enum V_209 V_210 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_43 * V_44 = & V_3 -> V_44 ;
struct V_76 * V_102 = V_75 -> V_85 ;
struct V_135 * V_136 ;
int V_33 = - V_16 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_47 ) ;
if ( V_114 != V_210 &&
V_50 != V_210 ) {
F_59 ( & V_5 -> V_104 , L_42 ) ;
return V_33 ;
}
if ( ! V_102 -> V_84 ) {
F_59 ( & V_5 -> V_104 , L_45 ) ;
return - V_206 ;
}
V_136 = V_3 -> V_23 ;
if ( F_36 ( & V_3 -> V_105 . V_211 ) ) {
F_59 ( & V_5 -> V_104 , L_48 ) ;
return - V_212 ;
}
if ( V_114 == V_210 ) {
V_33 = F_21 ( V_44 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return F_109 ( & V_3 -> V_105 , V_210 ) ;
}
static int F_110 ( struct V_75 * V_75 , void * V_111 ,
enum V_209 V_210 )
{
struct V_2 * V_3 = F_27 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_102 = V_75 -> V_85 ;
int V_33 = 0 ;
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_49 ) ;
if ( V_210 != V_114 &&
V_210 != V_50 ) {
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_42 ) ;
return - V_16 ;
}
if ( ! V_102 -> V_84 ) {
F_44 ( 1 , V_103 , & V_5 -> V_104 , L_45 ) ;
return - V_206 ;
}
if ( ! V_3 -> V_61 ) {
F_59 ( & V_5 -> V_104 , L_50 ) ;
return - V_16 ;
}
V_33 = F_65 ( & V_3 -> V_81 ) ;
if ( V_33 )
return V_33 ;
F_41 ( V_3 ) ;
V_33 = F_45 ( & V_3 -> V_105 , V_210 ) ;
F_18 ( & V_3 -> V_81 ) ;
return V_33 ;
}
int F_111 ( struct V_2 * V_3 , const char * V_22 )
{
const char * V_213 ;
int V_33 ;
switch ( V_3 -> type ) {
case V_114 :
V_213 = L_51 ;
V_3 -> V_26 . V_66 = V_67 ;
V_3 -> type = V_114 ;
break;
case V_50 :
V_213 = L_52 ;
V_3 -> V_26 . V_66 = V_214 ;
V_3 -> type = V_50 ;
break;
default:
return - V_16 ;
}
V_3 -> V_39 . V_215 = V_216 ;
V_3 -> V_39 . V_217 = & V_218 ;
V_3 -> V_39 . V_219 = & V_220 ;
V_3 -> V_39 . V_221 = - 1 ;
V_3 -> V_39 . V_152 = 0 ;
snprintf ( V_3 -> V_39 . V_22 , sizeof( V_3 -> V_39 . V_22 ) ,
L_53 , V_22 , V_213 ) ;
F_112 ( & V_3 -> V_222 ) ;
F_112 ( & V_3 -> V_180 ) ;
F_113 ( & V_3 -> V_81 ) ;
V_33 = F_114 ( & V_3 -> V_39 . V_10 ,
1 , & V_3 -> V_26 , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
F_115 ( & V_3 -> V_39 , V_3 ) ;
return 0 ;
}
int F_116 ( struct V_2 * V_3 ,
struct V_223 * V_224 )
{
int V_33 ;
V_3 -> V_39 . V_104 = V_224 ;
V_33 = F_117 ( & V_3 -> V_39 , V_225 , - 1 ) ;
if ( V_33 < 0 )
F_3 ( L_54 ,
V_226 , V_33 ) ;
return V_33 ;
}
void F_118 ( struct V_2 * V_3 )
{
if ( F_119 ( & V_3 -> V_39 ) ) {
F_120 ( & V_3 -> V_39 ) ;
F_121 ( & V_3 -> V_39 . V_10 ) ;
}
}
