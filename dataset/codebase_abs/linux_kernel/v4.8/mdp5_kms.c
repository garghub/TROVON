static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 ) ;
F_5 ( V_3 ) ;
F_6 ( & V_3 -> V_8 , V_6 ) ;
F_7 ( V_3 , V_9 , 0 ) ;
F_8 ( & V_3 -> V_8 , V_6 ) ;
F_9 ( V_3 -> V_10 ) ;
F_10 ( V_3 ) ;
F_11 ( & V_5 -> V_7 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_5 ( V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_13 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_14 (state, plane, plane_state, i)
F_15 ( V_15 , V_17 ) ;
F_10 ( V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
F_17 ( V_19 ) ;
}
static long F_18 ( struct V_1 * V_2 , unsigned long V_20 ,
struct V_21 * V_22 )
{
return V_20 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_21 * V_23 ,
bool V_24 )
{
if ( V_24 )
return F_20 ( V_22 ,
V_23 ) ;
else
return F_21 ( V_22 , V_23 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_25 * V_26 = V_3 -> V_26 ;
if ( V_26 ) {
V_26 -> V_27 -> V_28 ( V_26 , V_29 , F_23 ( V_29 ) ) ;
V_26 -> V_27 -> V_30 ( V_26 ) ;
}
}
int F_10 ( struct V_3 * V_3 )
{
F_24 ( L_1 ) ;
F_25 ( V_3 -> V_31 ) ;
F_25 ( V_3 -> V_32 ) ;
F_25 ( V_3 -> V_33 ) ;
if ( V_3 -> V_34 )
F_25 ( V_3 -> V_34 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_24 ( L_1 ) ;
F_26 ( V_3 -> V_31 ) ;
F_26 ( V_3 -> V_32 ) ;
F_26 ( V_3 -> V_33 ) ;
if ( V_3 -> V_34 )
F_26 ( V_3 -> V_34 ) ;
return 0 ;
}
static struct V_21 * F_27 ( struct V_3 * V_3 ,
enum V_35 V_36 , int V_37 ,
enum V_38 V_39 , struct V_40 * V_41 )
{
struct V_42 * V_7 = V_3 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_21 * V_22 ;
struct V_46 V_47 = {
. V_48 = V_37 ,
. type = V_36 ,
. V_49 = V_39 ,
} ;
if ( ( V_36 == V_50 ) &&
( V_39 == V_51 ) )
V_22 = F_28 ( V_7 , & V_47 , V_41 ) ;
else
V_22 = F_29 ( V_7 , & V_47 , V_41 ) ;
if ( F_30 ( V_22 ) ) {
F_31 ( V_7 -> V_7 , L_2 ) ;
return V_22 ;
}
V_22 -> V_52 = ( 1 << V_44 -> V_53 ) - 1 ;
V_44 -> V_54 [ V_44 -> V_55 ++ ] = V_22 ;
return V_22 ;
}
static int F_32 ( const struct V_56 * V_57 , int V_37 )
{
const enum V_35 * V_58 = V_57 -> V_47 . V_59 ;
const int V_60 = F_23 ( V_57 -> V_47 . V_59 ) ;
int V_61 = 0 , V_13 ;
for ( V_13 = 0 ; V_13 < V_60 ; V_13 ++ ) {
if ( V_58 [ V_13 ] == V_50 ) {
if ( V_37 == V_13 )
return V_61 ;
V_61 ++ ;
}
}
return - V_62 ;
}
static int F_33 ( struct V_3 * V_3 , int V_37 )
{
struct V_42 * V_7 = V_3 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
const struct V_56 * V_57 =
F_34 ( V_3 -> V_63 ) ;
enum V_35 V_36 = V_57 -> V_47 . V_59 [ V_37 ] ;
struct V_64 * V_10 = V_3 -> V_10 ;
struct V_40 * V_41 ;
struct V_21 * V_22 ;
int V_65 = 0 ;
switch ( V_36 ) {
case V_66 :
break;
case V_67 :
if ( ! V_44 -> V_68 )
break;
V_41 = F_35 ( V_10 , V_37 ) ;
if ( ! V_41 ) {
V_65 = - V_62 ;
break;
}
V_22 = F_27 ( V_3 , V_67 , V_37 ,
V_69 , V_41 ) ;
if ( F_30 ( V_22 ) ) {
V_65 = F_36 ( V_22 ) ;
break;
}
V_65 = F_37 ( V_44 -> V_68 , V_7 , V_22 ) ;
break;
case V_70 :
if ( ! V_44 -> V_71 )
break;
V_41 = F_35 ( V_10 , V_37 ) ;
if ( ! V_41 ) {
V_65 = - V_62 ;
break;
}
V_22 = F_27 ( V_3 , V_70 , V_37 ,
V_69 , V_41 ) ;
if ( F_30 ( V_22 ) ) {
V_65 = F_36 ( V_22 ) ;
break;
}
V_65 = F_38 ( V_44 -> V_71 , V_7 , V_22 ) ;
break;
case V_50 :
{
int V_72 = F_32 ( V_57 , V_37 ) ;
struct V_21 * V_73 [ V_74 ] ;
enum V_38 V_49 ;
int V_13 ;
if ( ( V_72 >= F_23 ( V_44 -> V_75 ) ) || ( V_72 < 0 ) ) {
F_31 ( V_7 -> V_7 , L_3 ,
V_37 ) ;
V_65 = - V_62 ;
break;
}
if ( ! V_44 -> V_75 [ V_72 ] )
break;
V_41 = F_35 ( V_10 , V_37 ) ;
if ( ! V_41 ) {
V_65 = - V_62 ;
break;
}
for ( V_13 = 0 ; V_13 < V_74 ; V_13 ++ ) {
V_49 = ( V_13 == V_76 ) ?
V_51 :
V_77 ;
V_73 [ V_13 ] = F_27 ( V_3 , V_50 ,
V_37 , V_49 , V_41 ) ;
if ( F_30 ( V_73 [ V_13 ] ) ) {
V_65 = F_36 ( V_73 [ V_13 ] ) ;
break;
}
}
V_65 = F_39 ( V_44 -> V_75 [ V_72 ] , V_7 , V_73 ) ;
break;
}
default:
F_31 ( V_7 -> V_7 , L_4 , V_36 ) ;
V_65 = - V_62 ;
break;
}
return V_65 ;
}
static int F_40 ( struct V_3 * V_3 )
{
static const enum V_78 V_79 [] = {
V_80 , V_81 , V_82 , V_83 ,
} ;
static const enum V_78 V_84 [] = {
V_85 , V_86 , V_87 , V_88 ,
} ;
static const enum V_78 V_89 [] = {
V_90 , V_91 ,
} ;
struct V_42 * V_7 = V_3 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
const struct V_56 * V_57 ;
int V_13 , V_65 ;
V_57 = F_34 ( V_3 -> V_63 ) ;
for ( V_13 = 0 ; V_13 < V_57 -> V_92 . V_93 ; V_13 ++ ) {
struct V_14 * V_15 ;
struct V_18 * V_19 ;
V_15 = F_41 ( V_7 , V_79 [ V_13 ] , true ,
V_57 -> V_92 . V_94 [ V_13 ] , V_57 -> V_92 . V_95 ) ;
if ( F_30 ( V_15 ) ) {
V_65 = F_36 ( V_15 ) ;
F_31 ( V_7 -> V_7 , L_5 ,
F_42 ( V_79 [ V_13 ] ) , V_65 ) ;
goto V_96;
}
V_19 = F_43 ( V_7 , V_15 , V_13 ) ;
if ( F_30 ( V_19 ) ) {
V_65 = F_36 ( V_19 ) ;
F_31 ( V_7 -> V_7 , L_6 ,
F_42 ( V_79 [ V_13 ] ) , V_65 ) ;
goto V_96;
}
V_44 -> V_79 [ V_44 -> V_53 ++ ] = V_19 ;
}
for ( V_13 = 0 ; V_13 < V_57 -> V_97 . V_93 ; V_13 ++ ) {
struct V_14 * V_15 ;
V_15 = F_41 ( V_7 , V_84 [ V_13 ] , false ,
V_57 -> V_97 . V_94 [ V_13 ] , V_57 -> V_97 . V_95 ) ;
if ( F_30 ( V_15 ) ) {
V_65 = F_36 ( V_15 ) ;
F_31 ( V_7 -> V_7 , L_7 ,
F_42 ( V_84 [ V_13 ] ) , V_65 ) ;
goto V_96;
}
}
for ( V_13 = 0 ; V_13 < V_57 -> V_98 . V_93 ; V_13 ++ ) {
struct V_14 * V_15 ;
V_15 = F_41 ( V_7 , V_89 [ V_13 ] , false ,
V_57 -> V_98 . V_94 [ V_13 ] , V_57 -> V_98 . V_95 ) ;
if ( F_30 ( V_15 ) ) {
V_65 = F_36 ( V_15 ) ;
F_31 ( V_7 -> V_7 , L_7 ,
F_42 ( V_89 [ V_13 ] ) , V_65 ) ;
goto V_96;
}
}
for ( V_13 = 0 ; V_13 < F_23 ( V_57 -> V_47 . V_59 ) ; V_13 ++ ) {
V_65 = F_33 ( V_3 , V_13 ) ;
if ( V_65 )
goto V_96;
}
return 0 ;
V_96:
return V_65 ;
}
static void F_44 ( struct V_3 * V_3 ,
T_1 * V_99 , T_1 * V_100 )
{
T_1 V_101 ;
F_5 ( V_3 ) ;
V_101 = F_45 ( V_3 , V_102 ) ;
F_10 ( V_3 ) ;
* V_99 = F_46 ( V_101 , V_103 ) ;
* V_100 = F_46 ( V_101 , V_104 ) ;
F_24 ( L_8 , * V_99 , * V_100 ) ;
}
static int F_47 ( struct V_4 * V_5 , struct V_105 * * V_106 ,
const char * V_107 , bool V_108 )
{
struct V_109 * V_7 = & V_5 -> V_7 ;
struct V_105 * V_105 = F_48 ( V_7 , V_107 ) ;
if ( F_30 ( V_105 ) && V_108 ) {
F_31 ( V_7 , L_9 , V_107 , F_36 ( V_105 ) ) ;
return F_36 ( V_105 ) ;
}
if ( F_30 ( V_105 ) )
F_24 ( L_10 , V_107 ) ;
else
* V_106 = V_105 ;
return 0 ;
}
static struct V_21 * F_49 ( struct V_18 * V_19 )
{
struct V_42 * V_7 = V_19 -> V_7 ;
struct V_21 * V_22 ;
F_50 (encoder, dev)
if ( V_22 -> V_19 == V_19 )
return V_22 ;
return NULL ;
}
static int F_51 ( struct V_42 * V_7 , unsigned int V_110 ,
unsigned int V_6 , int * V_111 , int * V_112 ,
T_2 * V_113 , T_2 * V_114 ,
const struct V_115 * V_49 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_18 * V_19 ;
struct V_21 * V_22 ;
int line , V_116 , V_117 , V_118 , V_119 , V_120 ;
int V_65 = 0 ;
V_19 = V_44 -> V_79 [ V_110 ] ;
if ( ! V_19 ) {
F_52 ( L_11 , V_110 ) ;
return 0 ;
}
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 ) {
F_52 ( L_12 , V_110 ) ;
return 0 ;
}
V_65 |= V_121 | V_122 ;
V_116 = V_49 -> V_123 - V_49 -> V_124 ;
V_117 = V_49 -> V_125 - V_49 -> V_123 ;
V_118 = V_116 + V_117 + 1 ;
V_119 = V_118 + V_49 -> V_126 ;
V_120 = V_49 -> V_125 ;
if ( V_113 )
* V_113 = F_53 () ;
line = F_54 ( V_22 ) ;
if ( line < V_118 ) {
line -= V_118 ;
V_65 |= V_127 ;
} else if ( line > V_119 ) {
line = line - V_120 - V_118 ;
V_65 |= V_127 ;
} else {
line -= V_118 ;
}
* V_111 = line ;
* V_112 = 0 ;
if ( V_114 )
* V_114 = F_53 () ;
return V_65 ;
}
static int F_55 ( struct V_42 * V_7 , unsigned int V_110 ,
int * V_128 ,
struct V_129 * V_130 ,
unsigned V_6 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_18 * V_19 ;
if ( V_110 < 0 || V_110 >= V_44 -> V_53 ) {
F_52 ( L_11 , V_110 ) ;
return - V_62 ;
}
V_19 = V_44 -> V_79 [ V_110 ] ;
if ( ! V_19 ) {
F_52 ( L_11 , V_110 ) ;
return - V_62 ;
}
return F_56 ( V_7 , V_110 , V_128 ,
V_130 , V_6 ,
& V_19 -> V_49 ) ;
}
static T_1 F_57 ( struct V_42 * V_7 , unsigned int V_110 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_18 * V_19 ;
struct V_21 * V_22 ;
if ( V_110 < 0 || V_110 >= V_44 -> V_53 )
return 0 ;
V_19 = V_44 -> V_79 [ V_110 ] ;
if ( ! V_19 )
return 0 ;
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 )
return 0 ;
return F_58 ( V_22 ) ;
}
struct V_1 * F_59 ( struct V_42 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_131 * V_132 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_133 , V_13 , V_65 ;
V_2 = V_44 -> V_2 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_60 ( & V_3 -> V_94 , & V_134 ) ;
V_5 = V_3 -> V_5 ;
V_133 = F_61 ( V_5 -> V_7 . V_135 , 0 ) ;
if ( V_133 < 0 ) {
V_65 = V_133 ;
F_31 ( & V_5 -> V_7 , L_13 , V_65 ) ;
goto V_96;
}
V_2 -> V_133 = V_133 ;
V_132 = F_62 ( V_3 -> V_63 ) ;
F_5 ( V_3 ) ;
for ( V_13 = 0 ; V_13 < V_136 ; V_13 ++ ) {
if ( F_63 ( V_132 -> V_137 -> V_47 . V_59 [ V_13 ] ) ||
! V_132 -> V_137 -> V_47 . V_94 [ V_13 ] )
continue;
F_7 ( V_3 , F_64 ( V_13 ) , 0 ) ;
F_7 ( V_3 , F_65 ( V_13 ) , 0x3 ) ;
}
F_10 ( V_3 ) ;
F_66 ( 16 ) ;
if ( V_132 -> V_138 . V_139 ) {
V_26 = F_67 ( & V_5 -> V_7 , V_132 -> V_138 . V_139 ) ;
if ( F_30 ( V_26 ) ) {
V_65 = F_36 ( V_26 ) ;
F_31 ( & V_5 -> V_7 , L_14 , V_65 ) ;
F_68 ( V_132 -> V_138 . V_139 ) ;
goto V_96;
}
V_65 = V_26 -> V_27 -> V_140 ( V_26 , V_29 ,
F_23 ( V_29 ) ) ;
if ( V_65 ) {
F_31 ( & V_5 -> V_7 , L_15 ,
V_65 ) ;
V_26 -> V_27 -> V_30 ( V_26 ) ;
goto V_96;
}
} else {
F_69 ( & V_5 -> V_7 ,
L_16 ) ;
V_26 = NULL ;
}
V_3 -> V_26 = V_26 ;
V_3 -> V_61 = F_70 ( V_7 , V_26 ) ;
if ( V_3 -> V_61 < 0 ) {
V_65 = V_3 -> V_61 ;
F_31 ( & V_5 -> V_7 , L_17 , V_65 ) ;
goto V_96;
}
V_65 = F_40 ( V_3 ) ;
if ( V_65 ) {
F_31 ( & V_5 -> V_7 , L_18 , V_65 ) ;
goto V_96;
}
V_7 -> V_141 . V_142 = 0 ;
V_7 -> V_141 . V_143 = 0 ;
V_7 -> V_141 . V_144 = V_132 -> V_137 -> V_145 . V_144 ;
V_7 -> V_141 . V_146 = V_132 -> V_137 -> V_145 . V_146 ;
V_7 -> V_147 -> V_148 = F_55 ;
V_7 -> V_147 -> V_149 = F_51 ;
V_7 -> V_147 -> V_150 = F_57 ;
V_7 -> V_151 = 0xffffffff ;
V_7 -> V_152 = true ;
return V_2 ;
V_96:
if ( V_2 )
F_22 ( V_2 ) ;
return F_71 ( V_65 ) ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_73 ( V_5 ) ;
if ( V_3 -> V_10 )
F_74 ( V_3 -> V_10 ) ;
if ( V_3 -> V_153 )
F_75 ( V_3 -> V_153 ) ;
if ( V_3 -> V_63 )
F_76 ( V_3 -> V_63 ) ;
if ( V_3 -> V_154 )
F_77 ( & V_5 -> V_7 ) ;
}
static int F_78 ( struct V_4 * V_5 , struct V_42 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_3 * V_3 ;
struct V_131 * V_132 ;
T_1 V_99 , V_100 ;
int V_65 ;
V_3 = F_79 ( & V_5 -> V_7 , sizeof( * V_3 ) , V_155 ) ;
if ( ! V_3 ) {
V_65 = - V_156 ;
goto V_96;
}
F_80 ( V_5 , V_3 ) ;
F_81 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_157 = F_82 ( V_5 , L_19 , L_20 ) ;
if ( F_30 ( V_3 -> V_157 ) ) {
V_65 = F_36 ( V_3 -> V_157 ) ;
goto V_96;
}
V_65 = F_47 ( V_5 , & V_3 -> V_32 , L_21 , true ) ;
if ( V_65 )
goto V_96;
V_65 = F_47 ( V_5 , & V_3 -> V_31 , L_22 , true ) ;
if ( V_65 )
goto V_96;
V_65 = F_47 ( V_5 , & V_3 -> V_33 , L_23 , true ) ;
if ( V_65 )
goto V_96;
V_65 = F_47 ( V_5 , & V_3 -> V_158 , L_24 , true ) ;
if ( V_65 )
goto V_96;
F_47 ( V_5 , & V_3 -> V_34 , L_25 , false ) ;
F_83 ( V_3 -> V_33 , 200000000 ) ;
F_84 ( & V_5 -> V_7 ) ;
V_3 -> V_154 = true ;
F_44 ( V_3 , & V_99 , & V_100 ) ;
V_3 -> V_63 = F_85 ( V_3 , V_99 , V_100 ) ;
if ( F_30 ( V_3 -> V_63 ) ) {
V_65 = F_36 ( V_3 -> V_63 ) ;
V_3 -> V_63 = NULL ;
goto V_96;
}
V_132 = F_62 ( V_3 -> V_63 ) ;
V_3 -> V_95 = V_132 -> V_137 -> V_159 . V_95 ;
F_83 ( V_3 -> V_33 , V_132 -> V_137 -> V_160 ) ;
if ( V_3 -> V_95 & V_161 ) {
V_3 -> V_153 = F_86 ( V_3 -> V_7 , & V_132 -> V_137 -> V_153 ) ;
if ( F_30 ( V_3 -> V_153 ) ) {
V_65 = F_36 ( V_3 -> V_153 ) ;
V_3 -> V_153 = NULL ;
goto V_96;
}
}
V_3 -> V_10 = F_87 ( V_7 , V_3 -> V_157 , V_3 -> V_63 ) ;
if ( F_30 ( V_3 -> V_10 ) ) {
V_65 = F_36 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
goto V_96;
}
V_44 -> V_2 = & V_3 -> V_94 . V_94 ;
return 0 ;
V_96:
F_72 ( V_5 ) ;
return V_65 ;
}
static int F_88 ( struct V_109 * V_7 , struct V_109 * V_162 , void * V_163 )
{
struct V_42 * V_164 = F_89 ( V_162 ) ;
struct V_4 * V_5 = F_90 ( V_7 ) ;
F_24 ( L_1 ) ;
return F_78 ( V_5 , V_164 ) ;
}
static void F_91 ( struct V_109 * V_7 , struct V_109 * V_162 ,
void * V_163 )
{
struct V_4 * V_5 = F_90 ( V_7 ) ;
F_72 ( V_5 ) ;
}
static int F_92 ( struct V_4 * V_5 )
{
F_24 ( L_1 ) ;
return F_93 ( & V_5 -> V_7 , & V_165 ) ;
}
static int F_94 ( struct V_4 * V_5 )
{
F_24 ( L_1 ) ;
F_95 ( & V_5 -> V_7 , & V_165 ) ;
return 0 ;
}
void T_3 F_96 ( void )
{
F_24 ( L_1 ) ;
F_97 ( & V_166 ) ;
}
void T_4 F_98 ( void )
{
F_24 ( L_1 ) ;
F_99 ( & V_166 ) ;
}
