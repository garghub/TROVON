static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_6 ;
F_4 ( V_5 -> V_5 ) ;
F_5 ( & V_3 -> V_7 , V_6 ) ;
F_6 ( V_3 , F_7 ( 0 ) , 0 ) ;
F_8 ( & V_3 -> V_7 , V_6 ) ;
F_9 ( V_3 -> V_8 ) ;
F_10 ( V_5 -> V_5 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_12 ( V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_12 = V_3 -> V_5 -> V_13 . V_14 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
struct V_15 * V_16 = V_10 -> V_17 [ V_11 ] ;
struct V_18 * V_19 = V_10 -> V_20 [ V_11 ] ;
if ( ! V_16 )
continue;
F_14 ( V_16 , V_19 ) ;
}
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_17 ( V_22 ) ;
}
static long F_18 ( struct V_1 * V_2 , unsigned long V_23 ,
struct V_24 * V_25 )
{
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_24 * V_26 ,
bool V_27 )
{
if ( V_27 )
return F_20 ( V_25 ,
V_26 ) ;
else
return F_21 ( V_25 , V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_30 * V_31 = V_3 -> V_5 -> V_32 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_31 -> V_33 ; V_11 ++ )
F_23 ( V_31 -> V_34 [ V_11 ] , V_29 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_35 * V_36 = V_3 -> V_36 ;
F_25 ( V_3 ) ;
if ( V_36 ) {
V_36 -> V_37 -> V_38 ( V_36 , V_39 , F_26 ( V_39 ) ) ;
V_36 -> V_37 -> V_40 ( V_36 ) ;
}
if ( V_3 -> V_8 )
F_27 ( V_3 -> V_8 ) ;
if ( V_3 -> V_41 )
F_28 ( V_3 -> V_41 ) ;
if ( V_3 -> V_42 )
F_29 ( V_3 -> V_42 ) ;
F_30 ( V_3 ) ;
}
int F_15 ( struct V_3 * V_3 )
{
F_31 ( L_1 ) ;
F_32 ( V_3 -> V_43 ) ;
F_32 ( V_3 -> V_44 ) ;
F_32 ( V_3 -> V_45 ) ;
if ( V_3 -> V_46 )
F_32 ( V_3 -> V_46 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_3 )
{
F_31 ( L_1 ) ;
F_33 ( V_3 -> V_43 ) ;
F_33 ( V_3 -> V_44 ) ;
F_33 ( V_3 -> V_45 ) ;
if ( V_3 -> V_46 )
F_33 ( V_3 -> V_46 ) ;
return 0 ;
}
static struct V_24 * F_34 ( struct V_3 * V_3 ,
enum V_47 V_48 , int V_49 ,
enum V_50 V_51 , struct V_52 * V_53 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
struct V_24 * V_25 ;
struct V_54 V_55 = {
. V_56 = V_49 ,
. type = V_48 ,
. V_57 = V_51 ,
} ;
if ( ( V_48 == V_58 ) &&
( V_51 == V_59 ) )
V_25 = F_35 ( V_5 , & V_55 , V_53 ) ;
else
V_25 = F_36 ( V_5 , & V_55 , V_53 ) ;
if ( F_37 ( V_25 ) ) {
F_38 ( V_5 -> V_5 , L_2 ) ;
return V_25 ;
}
V_25 -> V_60 = ( 1 << V_31 -> V_33 ) - 1 ;
V_31 -> V_61 [ V_31 -> V_62 ++ ] = V_25 ;
return V_25 ;
}
static int F_39 ( const struct V_63 * V_64 , int V_49 )
{
const enum V_47 * V_65 = V_64 -> V_55 . V_66 ;
const int V_67 = F_26 ( V_64 -> V_55 . V_66 ) ;
int V_68 = 0 , V_11 ;
for ( V_11 = 0 ; V_11 < V_67 ; V_11 ++ ) {
if ( V_65 [ V_11 ] == V_58 ) {
if ( V_49 == V_11 )
return V_68 ;
V_68 ++ ;
}
}
return - V_69 ;
}
static int F_40 ( struct V_3 * V_3 , int V_49 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
const struct V_63 * V_64 =
F_41 ( V_3 -> V_42 ) ;
enum V_47 V_48 = V_64 -> V_55 . V_66 [ V_49 ] ;
struct V_70 * V_8 = V_3 -> V_8 ;
struct V_52 * V_53 ;
struct V_24 * V_25 ;
int V_71 = 0 ;
switch ( V_48 ) {
case V_72 :
break;
case V_73 :
if ( ! V_31 -> V_74 )
break;
V_53 = F_42 ( V_8 , V_49 ) ;
if ( ! V_53 ) {
V_71 = - V_69 ;
break;
}
V_25 = F_34 ( V_3 , V_73 , V_49 ,
V_75 , V_53 ) ;
if ( F_37 ( V_25 ) ) {
V_71 = F_43 ( V_25 ) ;
break;
}
V_71 = F_44 ( V_31 -> V_74 , V_5 , V_25 ) ;
break;
case V_76 :
if ( ! V_31 -> V_77 )
break;
V_53 = F_42 ( V_8 , V_49 ) ;
if ( ! V_53 ) {
V_71 = - V_69 ;
break;
}
V_25 = F_34 ( V_3 , V_76 , V_49 ,
V_75 , V_53 ) ;
if ( F_37 ( V_25 ) ) {
V_71 = F_43 ( V_25 ) ;
break;
}
V_71 = F_45 ( V_31 -> V_77 , V_5 , V_25 ) ;
break;
case V_58 :
{
int V_78 = F_39 ( V_64 , V_49 ) ;
struct V_24 * V_79 [ V_80 ] ;
enum V_50 V_57 ;
int V_11 ;
if ( ( V_78 >= F_26 ( V_31 -> V_81 ) ) || ( V_78 < 0 ) ) {
F_38 ( V_5 -> V_5 , L_3 ,
V_49 ) ;
V_71 = - V_69 ;
break;
}
if ( ! V_31 -> V_81 [ V_78 ] )
break;
V_53 = F_42 ( V_8 , V_49 ) ;
if ( ! V_53 ) {
V_71 = - V_69 ;
break;
}
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ ) {
V_57 = ( V_11 == V_82 ) ?
V_59 :
V_83 ;
V_79 [ V_11 ] = F_34 ( V_3 , V_58 ,
V_49 , V_57 , V_53 ) ;
if ( F_37 ( V_79 [ V_11 ] ) ) {
V_71 = F_43 ( V_79 [ V_11 ] ) ;
break;
}
}
V_71 = F_46 ( V_31 -> V_81 [ V_78 ] , V_5 , V_79 ) ;
break;
}
default:
F_38 ( V_5 -> V_5 , L_4 , V_48 ) ;
V_71 = - V_69 ;
break;
}
return V_71 ;
}
static int F_47 ( struct V_3 * V_3 )
{
static const enum V_84 V_34 [] = {
V_85 , V_86 , V_87 , V_88 ,
} ;
static const enum V_84 V_89 [] = {
V_90 , V_91 , V_92 , V_93 ,
} ;
static const enum V_84 V_94 [] = {
V_95 , V_96 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
const struct V_63 * V_64 ;
int V_11 , V_71 ;
V_64 = F_41 ( V_3 -> V_42 ) ;
V_71 = F_48 ( V_3 ) ;
if ( V_71 )
goto V_97;
for ( V_11 = 0 ; V_11 < V_64 -> V_98 . V_99 ; V_11 ++ ) {
struct V_15 * V_16 ;
struct V_21 * V_22 ;
V_16 = F_49 ( V_5 , V_34 [ V_11 ] , true ,
V_64 -> V_98 . V_100 [ V_11 ] , V_64 -> V_98 . V_101 ) ;
if ( F_37 ( V_16 ) ) {
V_71 = F_43 ( V_16 ) ;
F_38 ( V_5 -> V_5 , L_5 ,
F_50 ( V_34 [ V_11 ] ) , V_71 ) ;
goto V_97;
}
V_22 = F_51 ( V_5 , V_16 , V_11 ) ;
if ( F_37 ( V_22 ) ) {
V_71 = F_43 ( V_22 ) ;
F_38 ( V_5 -> V_5 , L_6 ,
F_50 ( V_34 [ V_11 ] ) , V_71 ) ;
goto V_97;
}
V_31 -> V_34 [ V_31 -> V_33 ++ ] = V_22 ;
}
for ( V_11 = 0 ; V_11 < V_64 -> V_102 . V_99 ; V_11 ++ ) {
struct V_15 * V_16 ;
V_16 = F_49 ( V_5 , V_89 [ V_11 ] , false ,
V_64 -> V_102 . V_100 [ V_11 ] , V_64 -> V_102 . V_101 ) ;
if ( F_37 ( V_16 ) ) {
V_71 = F_43 ( V_16 ) ;
F_38 ( V_5 -> V_5 , L_7 ,
F_50 ( V_89 [ V_11 ] ) , V_71 ) ;
goto V_97;
}
}
for ( V_11 = 0 ; V_11 < V_64 -> V_103 . V_99 ; V_11 ++ ) {
struct V_15 * V_16 ;
V_16 = F_49 ( V_5 , V_94 [ V_11 ] , false ,
V_64 -> V_103 . V_100 [ V_11 ] , V_64 -> V_103 . V_101 ) ;
if ( F_37 ( V_16 ) ) {
V_71 = F_43 ( V_16 ) ;
F_38 ( V_5 -> V_5 , L_7 ,
F_50 ( V_94 [ V_11 ] ) , V_71 ) ;
goto V_97;
}
}
for ( V_11 = 0 ; V_11 < F_26 ( V_64 -> V_55 . V_66 ) ; V_11 ++ ) {
V_71 = F_40 ( V_3 , V_11 ) ;
if ( V_71 )
goto V_97;
}
return 0 ;
V_97:
return V_71 ;
}
static void F_52 ( struct V_3 * V_3 ,
T_1 * V_104 , T_1 * V_105 )
{
T_1 V_106 ;
F_12 ( V_3 ) ;
V_106 = F_53 ( V_3 , V_107 ) ;
F_15 ( V_3 ) ;
* V_104 = F_54 ( V_106 , V_108 ) ;
* V_105 = F_54 ( V_106 , V_109 ) ;
F_31 ( L_8 , * V_104 , * V_105 ) ;
}
static int F_55 ( struct V_110 * V_111 , struct V_112 * * V_113 ,
const char * V_114 , bool V_115 )
{
struct V_116 * V_5 = & V_111 -> V_5 ;
struct V_112 * V_112 = F_56 ( V_5 , V_114 ) ;
if ( F_37 ( V_112 ) && V_115 ) {
F_38 ( V_5 , L_9 , V_114 , F_43 ( V_112 ) ) ;
return F_43 ( V_112 ) ;
}
if ( F_37 ( V_112 ) )
F_31 ( L_10 , V_114 ) ;
else
* V_113 = V_112 ;
return 0 ;
}
static struct V_24 * F_57 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
struct V_24 * V_25 ;
F_58 (encoder, dev)
if ( V_25 -> V_22 == V_22 )
return V_25 ;
return NULL ;
}
static int F_59 ( struct V_4 * V_5 , unsigned int V_117 ,
unsigned int V_6 , int * V_118 , int * V_119 ,
T_2 * V_120 , T_2 * V_121 ,
const struct V_122 * V_57 )
{
struct V_30 * V_31 = V_5 -> V_32 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
int line , V_123 , V_124 , V_125 , V_126 , V_127 ;
int V_71 = 0 ;
V_22 = V_31 -> V_34 [ V_117 ] ;
if ( ! V_22 ) {
F_60 ( L_11 , V_117 ) ;
return 0 ;
}
V_25 = F_57 ( V_22 ) ;
if ( ! V_25 ) {
F_60 ( L_12 , V_117 ) ;
return 0 ;
}
V_71 |= V_128 | V_129 ;
V_123 = V_57 -> V_130 - V_57 -> V_131 ;
V_124 = V_57 -> V_132 - V_57 -> V_130 ;
V_125 = V_123 + V_124 + 1 ;
V_126 = V_125 + V_57 -> V_133 ;
V_127 = V_57 -> V_132 ;
if ( V_120 )
* V_120 = F_61 () ;
line = F_62 ( V_25 ) ;
if ( line < V_125 ) {
line -= V_125 ;
V_71 |= V_134 ;
} else if ( line > V_126 ) {
line = line - V_127 - V_125 ;
V_71 |= V_134 ;
} else {
line -= V_125 ;
}
* V_118 = line ;
* V_119 = 0 ;
if ( V_121 )
* V_121 = F_61 () ;
return V_71 ;
}
static int F_63 ( struct V_4 * V_5 , unsigned int V_117 ,
int * V_135 ,
struct V_136 * V_137 ,
unsigned V_6 )
{
struct V_30 * V_31 = V_5 -> V_32 ;
struct V_21 * V_22 ;
if ( V_117 < 0 || V_117 >= V_31 -> V_33 ) {
F_60 ( L_11 , V_117 ) ;
return - V_69 ;
}
V_22 = V_31 -> V_34 [ V_117 ] ;
if ( ! V_22 ) {
F_60 ( L_11 , V_117 ) ;
return - V_69 ;
}
return F_64 ( V_5 , V_117 , V_135 ,
V_137 , V_6 ,
& V_22 -> V_57 ) ;
}
static T_3 F_65 ( struct V_4 * V_5 , unsigned int V_117 )
{
struct V_30 * V_31 = V_5 -> V_32 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
if ( V_117 < 0 || V_117 >= V_31 -> V_33 )
return 0 ;
V_22 = V_31 -> V_34 [ V_117 ] ;
if ( ! V_22 )
return 0 ;
V_25 = F_57 ( V_22 ) ;
if ( ! V_25 )
return 0 ;
return F_66 ( V_25 ) ;
}
struct V_1 * F_67 ( struct V_4 * V_5 )
{
struct V_110 * V_111 = V_5 -> V_138 ;
struct V_139 * V_140 ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_35 * V_36 ;
T_1 V_104 , V_105 ;
int V_11 , V_71 ;
V_3 = F_68 ( sizeof( * V_3 ) , V_141 ) ;
if ( ! V_3 ) {
F_38 ( V_5 -> V_5 , L_13 ) ;
V_71 = - V_142 ;
goto V_97;
}
F_69 ( & V_3 -> V_7 ) ;
F_70 ( & V_3 -> V_100 , & V_143 ) ;
V_2 = & V_3 -> V_100 . V_100 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_144 = F_71 ( V_111 , L_14 , L_15 ) ;
if ( F_37 ( V_3 -> V_144 ) ) {
V_71 = F_43 ( V_3 -> V_144 ) ;
goto V_97;
}
V_3 -> V_145 = F_71 ( V_111 , L_16 , L_17 ) ;
if ( F_37 ( V_3 -> V_145 ) ) {
V_71 = F_43 ( V_3 -> V_145 ) ;
goto V_97;
}
V_3 -> V_146 = F_72 ( & V_111 -> V_5 , L_18 ) ;
if ( F_37 ( V_3 -> V_146 ) ) {
V_71 = F_43 ( V_3 -> V_146 ) ;
goto V_97;
}
V_71 = F_73 ( V_3 -> V_146 ) ;
if ( V_71 ) {
F_38 ( V_5 -> V_5 , L_19 , V_71 ) ;
goto V_97;
}
V_71 = F_55 ( V_111 , & V_3 -> V_44 , L_20 , true ) ;
if ( V_71 )
goto V_97;
V_71 = F_55 ( V_111 , & V_3 -> V_43 , L_21 , true ) ;
if ( V_71 )
goto V_97;
V_71 = F_55 ( V_111 , & V_3 -> V_147 , L_22 , true ) ;
if ( V_71 )
goto V_97;
V_71 = F_55 ( V_111 , & V_3 -> V_45 , L_23 , true ) ;
if ( V_71 )
goto V_97;
V_71 = F_55 ( V_111 , & V_3 -> V_148 , L_24 , true ) ;
if ( V_71 )
goto V_97;
F_55 ( V_111 , & V_3 -> V_46 , L_25 , false ) ;
F_74 ( V_3 -> V_147 , 200000000 ) ;
F_52 ( V_3 , & V_104 , & V_105 ) ;
V_3 -> V_42 = F_75 ( V_3 , V_104 , V_105 ) ;
if ( F_37 ( V_3 -> V_42 ) ) {
V_71 = F_43 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
goto V_97;
}
V_140 = F_76 ( V_3 -> V_42 ) ;
V_3 -> V_101 = V_140 -> V_149 -> V_150 . V_101 ;
F_74 ( V_3 -> V_147 , V_140 -> V_149 -> V_151 ) ;
if ( V_3 -> V_101 & V_152 ) {
V_3 -> V_41 = F_77 ( V_3 -> V_5 , & V_140 -> V_149 -> V_41 ) ;
if ( F_37 ( V_3 -> V_41 ) ) {
V_71 = F_43 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
goto V_97;
}
}
V_3 -> V_8 = F_78 ( V_5 , V_3 -> V_144 , V_3 -> V_42 ) ;
if ( F_37 ( V_3 -> V_8 ) ) {
V_71 = F_43 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
goto V_97;
}
F_12 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_153 ; V_11 ++ ) {
if ( F_79 ( V_140 -> V_149 -> V_55 . V_66 [ V_11 ] ) ||
! V_140 -> V_149 -> V_55 . V_100 [ V_11 ] )
continue;
F_6 ( V_3 , F_80 ( V_11 ) , 0 ) ;
F_6 ( V_3 , F_81 ( V_11 ) , 0x3 ) ;
}
F_15 ( V_3 ) ;
F_82 ( 16 ) ;
if ( V_140 -> V_154 . V_155 ) {
V_36 = F_83 ( & V_111 -> V_5 , V_140 -> V_154 . V_155 ) ;
if ( F_37 ( V_36 ) ) {
V_71 = F_43 ( V_36 ) ;
F_38 ( V_5 -> V_5 , L_26 , V_71 ) ;
F_84 ( V_140 -> V_154 . V_155 ) ;
goto V_97;
}
V_71 = V_36 -> V_37 -> V_156 ( V_36 , V_39 ,
F_26 ( V_39 ) ) ;
if ( V_71 ) {
F_38 ( V_5 -> V_5 , L_27 , V_71 ) ;
V_36 -> V_37 -> V_40 ( V_36 ) ;
goto V_97;
}
} else {
F_85 ( V_5 -> V_5 , L_28
L_29 ) ;
V_36 = NULL ;
}
V_3 -> V_36 = V_36 ;
V_3 -> V_68 = F_86 ( V_5 , V_36 ) ;
if ( V_3 -> V_68 < 0 ) {
V_71 = V_3 -> V_68 ;
F_38 ( V_5 -> V_5 , L_30 , V_71 ) ;
goto V_97;
}
V_71 = F_47 ( V_3 ) ;
if ( V_71 ) {
F_38 ( V_5 -> V_5 , L_31 , V_71 ) ;
goto V_97;
}
V_5 -> V_13 . V_157 = 0 ;
V_5 -> V_13 . V_158 = 0 ;
V_5 -> V_13 . V_159 = V_140 -> V_149 -> V_160 . V_159 ;
V_5 -> V_13 . V_161 = V_140 -> V_149 -> V_160 . V_161 ;
V_5 -> V_162 -> V_163 = F_63 ;
V_5 -> V_162 -> V_164 = F_59 ;
V_5 -> V_162 -> V_165 = F_65 ;
V_5 -> V_166 = 0xffffffff ;
V_5 -> V_167 = true ;
return V_2 ;
V_97:
if ( V_2 )
F_24 ( V_2 ) ;
return F_87 ( V_71 ) ;
}
