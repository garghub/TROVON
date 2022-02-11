struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_3 ) ;
if ( ! V_5 )
return NULL ;
F_3 ( & V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_5 ( L_1 , V_8 , V_5 ) ;
return & V_5 -> V_9 ;
}
void
F_6 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = F_7 ( V_10 ) ;
F_5 ( L_2 , V_8 , V_5 ) ;
F_8 ( ! F_9 ( & V_5 -> V_7 ) ) ;
F_10 ( V_5 ) ;
}
struct V_11 *
F_11 ( struct V_1 * V_12 ,
struct V_13 * V_14 ,
T_1 V_3 )
{
int V_15 = - V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 = {
. V_21 = V_14 -> V_22 -> V_21 ,
. V_23 = V_14 -> V_22 -> V_24 ,
. V_25 = V_14 -> V_22 -> V_24 ,
. V_24 = V_14 -> V_22 -> V_24 ,
} ;
struct V_26 * V_27 ;
struct V_11 * V_28 ;
F_5 ( L_3 , V_8 , V_12 ) ;
V_27 = F_12 ( V_3 ) ;
if ( ! V_27 )
goto V_29;
F_13 ( & V_18 , & V_20 , NULL ) ;
F_14 ( & V_18 , F_15 ( V_27 ) , V_30 ) ;
V_15 = F_16 ( & V_28 , V_12 , & V_14 -> V_31 , & V_18 , V_3 ) ;
if ( F_17 ( V_15 ) ) {
F_5 ( L_4 , V_8 ,
V_15 ) ;
goto V_32;
}
F_18 ( V_27 ) ;
F_5 ( L_1 , V_8 , V_28 ) ;
return V_28 ;
V_32:
F_18 ( V_27 ) ;
V_29:
F_5 ( L_5 , V_8 , V_15 ) ;
return F_19 ( V_15 ) ;
}
void
F_20 ( struct V_11 * V_28 )
{
F_5 ( L_6 , V_8 , V_28 ) ;
if ( F_17 ( ! V_28 ) )
return;
F_21 ( V_28 ) ;
}
static inline T_2
F_22 ( T_2 V_33 , T_2 V_24 )
{
T_2 V_34 ;
V_34 = V_33 + V_24 ;
return V_34 >= V_33 ? V_34 : V_35 ;
}
static void F_23 ( struct V_11 * V_28 ,
struct V_26 * * * V_36 , unsigned * V_37 ,
T_2 V_38 , unsigned long V_39 )
{
T_2 V_40 ;
F_24 ( V_38 < V_28 -> V_41 . V_38 ) ;
V_40 = F_22 ( V_28 -> V_41 . V_38 ,
V_28 -> V_41 . V_42 ) ;
F_24 ( V_38 >= V_40 ) ;
F_8 ( V_38 + V_39 > V_40 ) ;
if ( * V_37 > V_30 ) {
F_5 ( L_7 , V_8 , * V_37 ) ;
* V_36 += * V_37 >> V_43 ;
* V_37 &= ~ V_44 ;
}
}
static void
F_25 ( struct V_45 * V_46 )
{
if ( F_26 ( V_46 -> V_15 >= 0 ) ) {
F_27 ( V_46 ) ;
} else {
struct V_4 * V_5 = V_46 -> V_5 ;
F_28 ( & V_5 -> V_6 ) ;
V_5 -> V_47 = V_48 ;
F_29 ( & V_5 -> V_7 , & V_46 -> V_7 ) ;
F_30 ( & V_5 -> V_6 ) ;
}
}
void
F_31 ( struct V_45 * V_46 , unsigned V_49 ,
struct V_50 * V_51 , int V_52 ,
T_2 V_38 , T_2 V_42 , bool V_53 )
{
struct V_54 * V_55 = & V_46 -> V_56 [ V_49 ] ;
F_24 ( V_49 >= V_46 -> V_57 ) ;
if ( V_52 ) {
V_55 -> V_58 = * V_51 ;
V_55 -> V_59 = V_38 ;
V_55 -> V_60 = V_42 ;
V_55 -> V_61 = V_53 ;
V_55 -> V_62 = V_52 ;
F_5 ( L_8
L_9 ,
V_8 , V_49 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_32 ( & V_55 -> V_58 . V_63 ) ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
} else {
V_55 -> V_62 = 0 ;
}
}
static void F_34 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
F_5 ( L_10 , V_8 ) ;
V_69 = F_35 ( V_67 , struct V_68 , V_72 . V_73 ) ;
V_71 = F_35 ( V_69 , struct V_70 , V_69 ) ;
F_36 ( V_71 ) ;
}
void
F_37 ( struct V_45 * V_46 , T_3 V_15 , bool V_74 )
{
struct V_70 * V_71 = V_46 -> V_75 ;
V_46 -> V_15 = V_71 -> V_69 . V_76 = V_15 ;
if ( V_15 >= 0 )
V_71 -> V_77 . V_39 = V_15 ;
else
V_71 -> V_78 = V_15 ;
F_25 ( V_46 ) ;
F_5 ( L_11 , V_8 ,
V_15 , V_71 -> V_77 . V_79 , V_74 ) ;
if ( V_74 )
F_36 ( V_71 ) ;
else {
F_38 ( & V_71 -> V_69 . V_72 . V_73 , F_34 ) ;
F_39 ( & V_71 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_80
F_40 ( struct V_70 * V_71 )
{
struct V_2 * V_2 = V_71 -> V_2 ;
T_4 V_38 = V_71 -> args . V_38 ;
T_5 V_39 = V_71 -> args . V_39 ;
int V_32 ;
T_4 V_79 ;
V_79 = F_41 ( V_2 ) ;
if ( F_17 ( V_38 + V_39 > V_79 ) ) {
if ( V_38 >= V_79 ) {
V_32 = 0 ;
V_71 -> V_77 . V_39 = 0 ;
V_71 -> V_77 . V_79 = 1 ;
goto V_81;
}
V_39 = V_79 - V_38 ;
}
V_71 -> V_77 . V_79 = ( V_38 + V_39 ) >= V_79 ;
F_23 ( V_71 -> V_28 , & V_71 -> args . V_21 ,
& V_71 -> args . V_82 ,
V_71 -> args . V_38 , V_71 -> args . V_39 ) ;
F_5 ( L_12 ,
V_8 , V_2 -> V_83 , V_38 , V_39 , V_71 -> V_77 . V_79 ) ;
V_32 = F_42 ( V_71 ) ;
V_81:
if ( F_17 ( V_32 ) ) {
V_71 -> V_78 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_84 ;
}
return V_85 ;
}
static void F_43 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
F_5 ( L_10 , V_8 ) ;
V_69 = F_35 ( V_67 , struct V_68 , V_72 . V_73 ) ;
V_71 = F_35 ( V_69 , struct V_70 , V_69 ) ;
F_44 ( V_71 ) ;
}
void
F_45 ( struct V_45 * V_46 , T_3 V_15 , bool V_74 )
{
struct V_70 * V_71 = V_46 -> V_75 ;
V_46 -> V_15 = V_71 -> V_69 . V_76 = V_15 ;
if ( V_15 >= 0 ) {
V_71 -> V_77 . V_39 = V_15 ;
V_71 -> V_86 . V_87 = V_46 -> V_87 ;
} else {
V_71 -> V_78 = V_15 ;
}
F_25 ( V_46 ) ;
F_5 ( L_14 , V_8 ,
V_15 , V_71 -> V_86 . V_87 , V_74 ) ;
if ( V_74 )
F_44 ( V_71 ) ;
else {
F_38 ( & V_71 -> V_69 . V_72 . V_73 , F_43 ) ;
F_39 ( & V_71 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_80
F_46 ( struct V_70 * V_71 , int V_88 )
{
int V_32 ;
F_23 ( V_71 -> V_28 , & V_71 -> args . V_21 ,
& V_71 -> args . V_82 ,
V_71 -> args . V_38 , V_71 -> args . V_39 ) ;
V_32 = F_47 ( V_71 , V_88 ) ;
if ( F_17 ( V_32 ) ) {
V_71 -> V_78 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_84 ;
}
return V_85 ;
}
void
F_48 ( struct V_1 * V_12 ,
struct V_17 * V_89 ,
const struct V_90 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_91 V_92 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
F_28 ( & V_5 -> V_6 ) ;
V_92 . V_93 = ( V_5 -> V_47 == V_94 ) ;
V_92 . V_95 = V_5 -> V_96 ;
V_5 -> V_96 = 0 ;
V_5 -> V_47 = V_97 ;
V_92 . V_98 = ! F_9 ( & V_5 -> V_7 ) ;
F_30 ( & V_5 -> V_6 ) ;
V_33 = F_49 ( V_89 , 4 ) ;
F_24 ( F_50 ( V_89 , & V_92 ) ) ;
* V_33 = F_51 ( ( V_89 -> V_99 - V_33 - 1 ) * 4 ) ;
F_5 ( L_16 , V_8 ,
V_92 . V_95 , V_92 . V_98 ) ;
}
static int
F_52 ( T_7 V_62 )
{
switch ( V_62 ) {
case 0 :
return 0 ;
case V_100 :
return V_101 ;
case V_102 :
return V_103 ;
case V_104 :
return V_105 ;
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
default:
F_8 ( 1 ) ;
case V_112 :
return V_113 ;
}
}
static void
F_53 ( struct V_54 * V_114 ,
const struct V_54 * V_115 )
{
T_2 V_116 , V_117 ;
if ( ! V_114 -> V_62 ) {
* V_114 = * V_115 ;
memset ( & V_114 -> V_58 . V_63 , 0 ,
sizeof( V_114 -> V_58 . V_63 ) ) ;
return;
}
if ( V_114 -> V_58 . V_64 !=
V_115 -> V_58 . V_64 )
V_114 -> V_58 . V_64 = 0 ;
if ( V_114 -> V_58 . V_65 !=
V_115 -> V_58 . V_65 )
V_114 -> V_58 . V_65 = 0 ;
if ( V_114 -> V_59 > V_115 -> V_59 )
V_114 -> V_59 = V_115 -> V_59 ;
V_116 = F_22 ( V_114 -> V_59 ,
V_114 -> V_60 ) ;
V_117 = F_22 ( V_115 -> V_59 ,
V_115 -> V_60 ) ;
if ( V_116 < V_117 )
V_116 = V_117 ;
V_114 -> V_60 = V_116 - V_114 -> V_59 ;
if ( ( V_115 -> V_61 == V_114 -> V_61 ) &&
( F_52 ( V_115 -> V_62 ) > F_52 ( V_114 -> V_62 ) ) ) {
V_114 -> V_62 = V_115 -> V_62 ;
} else if ( V_115 -> V_61 ) {
V_114 -> V_61 = true ;
V_114 -> V_62 = V_115 -> V_62 ;
}
}
static void
F_54 ( struct V_4 * V_5 , T_6 * V_99 )
{
struct V_45 * V_46 , * V_118 ;
struct V_54 V_119 = { . V_62 = 0 } ;
F_55 (oir, tmp, &objlay->err_list, err_list) {
unsigned V_120 ;
for ( V_120 = 0 ; V_120 < V_46 -> V_57 ; V_120 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_120 ] ;
if ( ! V_55 -> V_62 )
continue;
F_56 ( V_121 L_17
L_18
L_19 ,
V_8 , V_120 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_32 ( & V_55 -> V_58 . V_63 ) ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
F_53 ( & V_119 , V_55 ) ;
}
F_57 ( & V_46 -> V_7 ) ;
F_27 ( V_46 ) ;
}
F_58 ( V_99 , & V_119 ) ;
}
void
F_59 ( struct V_17 * V_89 ,
const struct V_122 * args )
{
struct V_1 * V_12 = args -> V_123 ;
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_45 * V_46 , * V_118 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
V_33 = F_49 ( V_89 , 4 ) ;
F_24 ( ! V_33 ) ;
F_28 ( & V_5 -> V_6 ) ;
F_55 (oir, tmp, &objlay->err_list, err_list) {
T_6 * V_124 = NULL , * V_99 ;
unsigned V_120 ;
int V_77 = 0 ;
for ( V_120 = 0 ; V_120 < V_46 -> V_57 ; V_120 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_120 ] ;
if ( ! V_55 -> V_62 )
continue;
F_5 ( L_20
L_21
L_22 ,
V_8 , V_120 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_32 ( & V_55 -> V_58 . V_63 ) ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
V_99 = F_60 ( V_89 ) ;
if ( F_17 ( ! V_99 ) ) {
V_77 = - V_125 ;
break;
}
V_124 = V_99 ;
F_58 ( V_99 , & V_46 -> V_56 [ V_120 ] ) ;
}
if ( F_17 ( V_77 ) ) {
F_24 ( ! V_124 ) ;
F_54 ( V_5 , V_124 ) ;
goto V_126;
}
F_57 ( & V_46 -> V_7 ) ;
F_27 ( V_46 ) ;
}
V_126:
F_30 ( & V_5 -> V_6 ) ;
* V_33 = F_51 ( ( V_89 -> V_99 - V_33 - 1 ) * 4 ) ;
F_5 ( L_23 , V_8 ) ;
}
static int F_61 ( struct V_127 * V_128 )
{
static char * V_129 [] = { L_24 ,
L_25 ,
L_26 ,
NULL
} ;
char * V_130 [ 8 ] ;
int V_131 ;
if ( F_17 ( ! V_132 [ 0 ] ) ) {
F_5 ( L_27 , V_8 ) ;
return - V_133 ;
}
F_5 ( L_28 , V_8 , V_128 -> V_134 ) ;
F_5 ( L_29 , V_8 , V_128 -> V_135 ) ;
F_5 ( L_30 , V_8 , V_128 -> V_136 ) ;
V_130 [ 0 ] = ( char * ) V_132 ;
V_130 [ 1 ] = L_31 ;
V_130 [ 2 ] = V_128 -> V_134 ;
V_130 [ 3 ] = L_32 ;
V_130 [ 4 ] = V_128 -> V_135 ;
V_130 [ 5 ] = L_33 ;
V_130 [ 6 ] = V_128 -> V_136 ;
V_130 [ 7 ] = NULL ;
V_131 = F_62 ( V_130 [ 0 ] , V_130 , V_129 , V_137 ) ;
if ( V_131 == - V_138 || V_131 == - V_133 ) {
F_56 ( V_121 L_34
L_35 ,
V_132 ) ;
V_132 [ 0 ] = '\0' ;
}
F_5 ( L_36 , V_8 , V_132 , V_131 ) ;
return V_131 ;
}
static void F_63 ( struct V_139 V_140 ,
char * V_141 , int V_142 ,
const char * V_143 )
{
if ( ! V_140 . V_24 )
return;
if ( V_140 . V_24 >= V_142 ) {
F_64 (
L_37 ,
V_143 , V_140 . V_24 , V_142 ) ;
V_140 . V_24 = V_142 - 1 ;
}
memcpy ( V_141 , V_140 . V_144 , V_140 . V_24 ) ;
}
static void F_65 ( struct V_139 V_140 ,
char V_145 [ V_146 ] )
{
int V_120 ;
char * V_147 ;
if ( ! V_140 . V_24 )
return;
if ( V_140 . V_24 != V_148 ) {
F_64 (
L_38 ,
V_140 . V_24 ) ;
if ( V_140 . V_24 > V_148 )
V_140 . V_24 = V_148 ;
}
V_147 = V_145 ;
for ( V_120 = 0 ; V_120 < V_140 . V_24 ; V_120 ++ )
V_147 = F_66 ( V_147 , V_140 . V_144 [ V_120 ] ) ;
}
int F_67 ( struct V_149 * V_150 )
{
int V_151 ;
struct V_127 V_128 ;
if ( ! V_150 -> V_152 . V_153 . V_154 . V_24 )
return - V_155 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_63 (
V_150 -> V_152 . V_153 . V_154 ,
V_128 . V_134 , sizeof( V_128 . V_134 ) , L_39 ) ;
F_63 (
V_150 -> V_156 ,
V_128 . V_135 , sizeof( V_128 . V_135 ) , L_40 ) ;
F_65 ( V_150 -> V_157 , V_128 . V_136 ) ;
V_151 = F_61 ( & V_128 ) ;
if ( V_151 > 0 )
V_151 = - V_155 ;
return V_151 ;
}
