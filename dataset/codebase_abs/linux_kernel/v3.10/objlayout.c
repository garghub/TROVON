struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
}
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
V_71 -> V_78 -> V_79 = V_15 ;
F_25 ( V_46 ) ;
F_5 ( L_11 , V_8 ,
V_15 , V_71 -> V_77 . V_80 , V_74 ) ;
if ( V_74 )
F_36 ( V_71 ) ;
else {
F_38 ( & V_71 -> V_69 . V_72 . V_73 , F_34 ) ;
F_39 ( & V_71 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_81
F_40 ( struct V_70 * V_71 )
{
struct V_82 * V_83 = V_71 -> V_78 ;
struct V_2 * V_2 = V_83 -> V_2 ;
T_4 V_38 = V_71 -> args . V_38 ;
T_5 V_39 = V_71 -> args . V_39 ;
int V_32 ;
T_4 V_80 ;
V_80 = F_41 ( V_2 ) ;
if ( F_17 ( V_38 + V_39 > V_80 ) ) {
if ( V_38 >= V_80 ) {
V_32 = 0 ;
V_71 -> V_77 . V_39 = 0 ;
V_71 -> V_77 . V_80 = 1 ;
goto V_84;
}
V_39 = V_80 - V_38 ;
}
V_71 -> V_77 . V_80 = ( V_38 + V_39 ) >= V_80 ;
F_23 ( V_83 -> V_28 , & V_71 -> args . V_21 ,
& V_71 -> args . V_85 ,
V_71 -> args . V_38 , V_71 -> args . V_39 ) ;
F_5 ( L_12 ,
V_8 , V_2 -> V_86 , V_38 , V_39 , V_71 -> V_77 . V_80 ) ;
V_32 = F_42 ( V_71 ) ;
V_84:
if ( F_17 ( V_32 ) ) {
V_83 -> V_79 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_87 ;
}
return V_88 ;
}
static void F_43 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_89 * V_90 ;
F_5 ( L_10 , V_8 ) ;
V_69 = F_35 ( V_67 , struct V_68 , V_72 . V_73 ) ;
V_90 = F_35 ( V_69 , struct V_89 , V_69 ) ;
F_44 ( V_90 ) ;
}
void
F_45 ( struct V_45 * V_46 , T_3 V_15 , bool V_74 )
{
struct V_89 * V_90 = V_46 -> V_75 ;
V_46 -> V_15 = V_90 -> V_69 . V_76 = V_15 ;
if ( V_15 >= 0 ) {
V_90 -> V_77 . V_39 = V_15 ;
V_90 -> V_91 . V_92 = V_46 -> V_92 ;
} else {
V_90 -> V_78 -> V_79 = V_15 ;
}
F_25 ( V_46 ) ;
F_5 ( L_14 , V_8 ,
V_15 , V_90 -> V_91 . V_92 , V_74 ) ;
if ( V_74 )
F_44 ( V_90 ) ;
else {
F_38 ( & V_90 -> V_69 . V_72 . V_73 , F_43 ) ;
F_39 ( & V_90 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_81
F_46 ( struct V_89 * V_90 ,
int V_93 )
{
struct V_82 * V_83 = V_90 -> V_78 ;
int V_32 ;
F_23 ( V_83 -> V_28 , & V_90 -> args . V_21 ,
& V_90 -> args . V_85 ,
V_90 -> args . V_38 , V_90 -> args . V_39 ) ;
V_32 = F_47 ( V_90 , V_93 ) ;
if ( F_17 ( V_32 ) ) {
V_83 -> V_79 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_87 ;
}
return V_88 ;
}
void
F_48 ( struct V_1 * V_12 ,
struct V_17 * V_94 ,
const struct V_95 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_96 V_97 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
F_28 ( & V_5 -> V_6 ) ;
V_97 . V_98 = ( V_5 -> V_47 == V_99 ) ;
V_97 . V_100 = V_5 -> V_101 ;
V_5 -> V_101 = 0 ;
V_5 -> V_47 = V_102 ;
V_97 . V_103 = ! F_9 ( & V_5 -> V_7 ) ;
F_30 ( & V_5 -> V_6 ) ;
V_33 = F_49 ( V_94 , 4 ) ;
F_24 ( F_50 ( V_94 , & V_97 ) ) ;
* V_33 = F_51 ( ( V_94 -> V_104 - V_33 - 1 ) * 4 ) ;
F_5 ( L_16 , V_8 ,
V_97 . V_100 , V_97 . V_103 ) ;
}
static int
F_52 ( T_7 V_62 )
{
switch ( V_62 ) {
case 0 :
return 0 ;
case V_105 :
return V_106 ;
case V_107 :
return V_108 ;
case V_109 :
return V_110 ;
case V_111 :
return V_112 ;
case V_113 :
return V_114 ;
case V_115 :
return V_116 ;
default:
F_8 ( 1 ) ;
case V_117 :
return V_118 ;
}
}
static void
F_53 ( struct V_54 * V_119 ,
const struct V_54 * V_120 )
{
T_2 V_121 , V_122 ;
if ( ! V_119 -> V_62 ) {
* V_119 = * V_120 ;
memset ( & V_119 -> V_58 . V_63 , 0 ,
sizeof( V_119 -> V_58 . V_63 ) ) ;
return;
}
if ( V_119 -> V_58 . V_64 !=
V_120 -> V_58 . V_64 )
V_119 -> V_58 . V_64 = 0 ;
if ( V_119 -> V_58 . V_65 !=
V_120 -> V_58 . V_65 )
V_119 -> V_58 . V_65 = 0 ;
if ( V_119 -> V_59 > V_120 -> V_59 )
V_119 -> V_59 = V_120 -> V_59 ;
V_121 = F_22 ( V_119 -> V_59 ,
V_119 -> V_60 ) ;
V_122 = F_22 ( V_120 -> V_59 ,
V_120 -> V_60 ) ;
if ( V_121 < V_122 )
V_121 = V_122 ;
V_119 -> V_60 = V_121 - V_119 -> V_59 ;
if ( ( V_120 -> V_61 == V_119 -> V_61 ) &&
( F_52 ( V_120 -> V_62 ) > F_52 ( V_119 -> V_62 ) ) ) {
V_119 -> V_62 = V_120 -> V_62 ;
} else if ( V_120 -> V_61 ) {
V_119 -> V_61 = true ;
V_119 -> V_62 = V_120 -> V_62 ;
}
}
static void
F_54 ( struct V_4 * V_5 , T_6 * V_104 )
{
struct V_45 * V_46 , * V_123 ;
struct V_54 V_124 = { . V_62 = 0 } ;
F_55 (oir, tmp, &objlay->err_list, err_list) {
unsigned V_125 ;
for ( V_125 = 0 ; V_125 < V_46 -> V_57 ; V_125 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_125 ] ;
if ( ! V_55 -> V_62 )
continue;
F_56 ( V_126 L_17
L_18
L_19 ,
V_8 , V_125 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_32 ( & V_55 -> V_58 . V_63 ) ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
F_53 ( & V_124 , V_55 ) ;
}
F_57 ( & V_46 -> V_7 ) ;
F_27 ( V_46 ) ;
}
F_58 ( V_104 , & V_124 ) ;
}
void
F_59 ( struct V_1 * V_12 ,
struct V_17 * V_94 ,
const struct V_127 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_45 * V_46 , * V_123 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
V_33 = F_49 ( V_94 , 4 ) ;
F_24 ( ! V_33 ) ;
F_28 ( & V_5 -> V_6 ) ;
F_55 (oir, tmp, &objlay->err_list, err_list) {
T_6 * V_128 = NULL , * V_104 ;
unsigned V_125 ;
int V_77 = 0 ;
for ( V_125 = 0 ; V_125 < V_46 -> V_57 ; V_125 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_125 ] ;
if ( ! V_55 -> V_62 )
continue;
F_5 ( L_20
L_21
L_22 ,
V_8 , V_125 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_32 ( & V_55 -> V_58 . V_63 ) ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
V_104 = F_60 ( V_94 ) ;
if ( F_17 ( ! V_104 ) ) {
V_77 = - V_129 ;
break;
}
V_128 = V_104 ;
F_58 ( V_104 , & V_46 -> V_56 [ V_125 ] ) ;
}
if ( F_17 ( V_77 ) ) {
F_24 ( ! V_128 ) ;
F_54 ( V_5 , V_128 ) ;
goto V_130;
}
F_57 ( & V_46 -> V_7 ) ;
F_27 ( V_46 ) ;
}
V_130:
F_30 ( & V_5 -> V_6 ) ;
* V_33 = F_51 ( ( V_94 -> V_104 - V_33 - 1 ) * 4 ) ;
F_5 ( L_23 , V_8 ) ;
}
int F_61 ( struct V_1 * V_12 ,
struct V_131 * V_132 , struct V_133 * * V_134 ,
T_1 V_3 )
{
struct V_135 * V_136 ;
struct V_137 V_138 ;
struct V_26 * V_26 , * * V_21 ;
T_7 * V_104 ;
int V_32 ;
V_26 = F_12 ( V_3 ) ;
if ( ! V_26 )
return - V_16 ;
V_21 = & V_26 ;
V_138 . V_21 = V_21 ;
memcpy ( & V_138 . V_139 , V_132 , sizeof( * V_132 ) ) ;
V_138 . V_140 = V_141 ;
V_138 . V_21 = & V_26 ;
V_138 . V_85 = 0 ;
V_138 . V_142 = V_30 ;
V_138 . V_143 = 0 ;
V_32 = F_62 ( F_63 ( V_12 -> V_144 ) , & V_138 ) ;
F_5 ( L_24 , V_8 , V_32 ) ;
if ( V_32 )
goto V_145;
V_104 = F_15 ( V_26 ) ;
V_136 = F_2 ( sizeof( * V_136 ) , V_3 ) ;
if ( ! V_136 ) {
V_32 = - V_16 ;
goto V_145;
}
F_64 ( & V_136 -> V_146 , V_104 ) ;
V_136 -> V_26 = V_26 ;
* V_134 = & V_136 -> V_146 ;
return 0 ;
V_145:
F_18 ( V_26 ) ;
return V_32 ;
}
void F_65 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = F_35 ( V_134 ,
struct V_135 ,
V_146 ) ;
F_18 ( V_136 -> V_26 ) ;
F_10 ( V_136 ) ;
}
static int F_66 ( struct V_147 * V_148 )
{
static char * V_149 [] = { L_25 ,
L_26 ,
L_27 ,
NULL
} ;
char * V_150 [ 8 ] ;
int V_151 ;
if ( F_17 ( ! V_152 [ 0 ] ) ) {
F_5 ( L_28 , V_8 ) ;
return - V_153 ;
}
F_5 ( L_29 , V_8 , V_148 -> V_154 ) ;
F_5 ( L_30 , V_8 , V_148 -> V_155 ) ;
F_5 ( L_31 , V_8 , V_148 -> V_156 ) ;
V_150 [ 0 ] = ( char * ) V_152 ;
V_150 [ 1 ] = L_32 ;
V_150 [ 2 ] = V_148 -> V_154 ;
V_150 [ 3 ] = L_33 ;
V_150 [ 4 ] = V_148 -> V_155 ;
V_150 [ 5 ] = L_34 ;
V_150 [ 6 ] = V_148 -> V_156 ;
V_150 [ 7 ] = NULL ;
V_151 = F_67 ( V_150 [ 0 ] , V_150 , V_149 , V_157 ) ;
if ( V_151 == - V_158 || V_151 == - V_153 ) {
F_56 ( V_126 L_35
L_36 ,
V_152 ) ;
V_152 [ 0 ] = '\0' ;
}
F_5 ( L_37 , V_8 , V_152 , V_151 ) ;
return V_151 ;
}
static void F_68 ( struct V_159 V_160 ,
char * V_161 , int V_162 ,
const char * V_163 )
{
if ( ! V_160 . V_24 )
return;
if ( V_160 . V_24 >= V_162 ) {
F_69 (
L_38 ,
V_163 , V_160 . V_24 , V_162 ) ;
V_160 . V_24 = V_162 - 1 ;
}
memcpy ( V_161 , V_160 . V_164 , V_160 . V_24 ) ;
}
static void F_70 ( struct V_159 V_160 ,
char V_165 [ V_166 ] )
{
int V_125 ;
char * V_167 ;
if ( ! V_160 . V_24 )
return;
if ( V_160 . V_24 != V_168 ) {
F_69 (
L_39 ,
V_160 . V_24 ) ;
if ( V_160 . V_24 > V_168 )
V_160 . V_24 = V_168 ;
}
V_167 = V_165 ;
for ( V_125 = 0 ; V_125 < V_160 . V_24 ; V_125 ++ )
V_167 = F_71 ( V_167 , V_160 . V_164 [ V_125 ] ) ;
}
int F_72 ( struct V_133 * V_134 )
{
int V_169 ;
struct V_147 V_148 ;
if ( ! V_134 -> V_170 . V_171 . V_172 . V_24 )
return - V_173 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_68 (
V_134 -> V_170 . V_171 . V_172 ,
V_148 . V_154 , sizeof( V_148 . V_154 ) , L_40 ) ;
F_68 (
V_134 -> V_174 ,
V_148 . V_155 , sizeof( V_148 . V_155 ) , L_41 ) ;
F_70 ( V_134 -> V_175 , V_148 . V_156 ) ;
V_169 = F_66 ( & V_148 ) ;
if ( V_169 > 0 )
V_169 = - V_173 ;
return V_169 ;
}
