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
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_28 * V_29 = V_3 -> V_29 ;
F_23 ( V_3 ) ;
if ( V_29 ) {
V_29 -> V_30 -> V_31 ( V_29 , V_32 , F_24 ( V_32 ) ) ;
V_29 -> V_30 -> V_33 ( V_29 ) ;
}
if ( V_3 -> V_8 )
F_25 ( V_3 -> V_8 ) ;
if ( V_3 -> V_34 )
F_26 ( V_3 -> V_34 ) ;
if ( V_3 -> V_35 )
F_27 ( V_3 -> V_35 ) ;
F_28 ( V_3 ) ;
}
int F_15 ( struct V_3 * V_3 )
{
F_29 ( L_1 ) ;
F_30 ( V_3 -> V_36 ) ;
F_30 ( V_3 -> V_37 ) ;
F_30 ( V_3 -> V_38 ) ;
if ( V_3 -> V_39 )
F_30 ( V_3 -> V_39 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_3 )
{
F_29 ( L_1 ) ;
F_31 ( V_3 -> V_36 ) ;
F_31 ( V_3 -> V_37 ) ;
F_31 ( V_3 -> V_38 ) ;
if ( V_3 -> V_39 )
F_31 ( V_3 -> V_39 ) ;
return 0 ;
}
static struct V_24 * F_32 ( struct V_3 * V_3 ,
enum V_40 V_41 , int V_42 ,
enum V_43 V_44 , struct V_45 * V_46 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_47 * V_48 = V_5 -> V_49 ;
struct V_24 * V_25 ;
struct V_50 V_51 = {
. V_52 = V_42 ,
. type = V_41 ,
. V_53 = V_44 ,
} ;
if ( ( V_41 == V_54 ) &&
( V_44 == V_55 ) )
V_25 = F_33 ( V_5 , & V_51 , V_46 ) ;
else
V_25 = F_34 ( V_5 , & V_51 , V_46 ) ;
if ( F_35 ( V_25 ) ) {
F_36 ( V_5 -> V_5 , L_2 ) ;
return V_25 ;
}
V_25 -> V_56 = ( 1 << V_48 -> V_57 ) - 1 ;
V_48 -> V_58 [ V_48 -> V_59 ++ ] = V_25 ;
return V_25 ;
}
static int F_37 ( const struct V_60 * V_61 , int V_42 )
{
const enum V_40 * V_62 = V_61 -> V_51 . V_63 ;
const int V_64 = F_24 ( V_61 -> V_51 . V_63 ) ;
int V_65 = 0 , V_11 ;
for ( V_11 = 0 ; V_11 < V_64 ; V_11 ++ ) {
if ( V_62 [ V_11 ] == V_54 ) {
if ( V_42 == V_11 )
return V_65 ;
V_65 ++ ;
}
}
return - V_66 ;
}
static int F_38 ( struct V_3 * V_3 , int V_42 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_47 * V_48 = V_5 -> V_49 ;
const struct V_60 * V_61 =
F_39 ( V_3 -> V_35 ) ;
enum V_40 V_41 = V_61 -> V_51 . V_63 [ V_42 ] ;
struct V_67 * V_8 = V_3 -> V_8 ;
struct V_45 * V_46 ;
struct V_24 * V_25 ;
int V_68 = 0 ;
switch ( V_41 ) {
case V_69 :
break;
case V_70 :
if ( ! V_48 -> V_71 )
break;
V_46 = F_40 ( V_8 , V_42 ) ;
if ( ! V_46 ) {
V_68 = - V_66 ;
break;
}
V_25 = F_32 ( V_3 , V_70 , V_42 ,
V_72 , V_46 ) ;
if ( F_35 ( V_25 ) ) {
V_68 = F_41 ( V_25 ) ;
break;
}
V_68 = F_42 ( V_48 -> V_71 , V_5 , V_25 ) ;
break;
case V_73 :
if ( ! V_48 -> V_74 )
break;
V_46 = F_40 ( V_8 , V_42 ) ;
if ( ! V_46 ) {
V_68 = - V_66 ;
break;
}
V_25 = F_32 ( V_3 , V_73 , V_42 ,
V_72 , V_46 ) ;
if ( F_35 ( V_25 ) ) {
V_68 = F_41 ( V_25 ) ;
break;
}
V_68 = F_43 ( V_48 -> V_74 , V_5 , V_25 ) ;
break;
case V_54 :
{
int V_75 = F_37 ( V_61 , V_42 ) ;
struct V_24 * V_76 [ V_77 ] ;
enum V_43 V_53 ;
int V_11 ;
if ( ( V_75 >= F_24 ( V_48 -> V_78 ) ) || ( V_75 < 0 ) ) {
F_36 ( V_5 -> V_5 , L_3 ,
V_42 ) ;
V_68 = - V_66 ;
break;
}
if ( ! V_48 -> V_78 [ V_75 ] )
break;
V_46 = F_40 ( V_8 , V_42 ) ;
if ( ! V_46 ) {
V_68 = - V_66 ;
break;
}
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
V_53 = ( V_11 == V_79 ) ?
V_55 :
V_80 ;
V_76 [ V_11 ] = F_32 ( V_3 , V_54 ,
V_42 , V_53 , V_46 ) ;
if ( F_35 ( V_76 [ V_11 ] ) ) {
V_68 = F_41 ( V_76 [ V_11 ] ) ;
break;
}
}
V_68 = F_44 ( V_48 -> V_78 [ V_75 ] , V_5 , V_76 ) ;
break;
}
default:
F_36 ( V_5 -> V_5 , L_4 , V_41 ) ;
V_68 = - V_66 ;
break;
}
return V_68 ;
}
static int F_45 ( struct V_3 * V_3 )
{
static const enum V_81 V_82 [] = {
V_83 , V_84 , V_85 , V_86 ,
} ;
static const enum V_81 V_87 [] = {
V_88 , V_89 , V_90 , V_91 ,
} ;
static const enum V_81 V_92 [] = {
V_93 , V_94 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_47 * V_48 = V_5 -> V_49 ;
const struct V_60 * V_61 ;
int V_11 , V_68 ;
V_61 = F_39 ( V_3 -> V_35 ) ;
V_68 = F_46 ( V_3 ) ;
if ( V_68 )
goto V_95;
for ( V_11 = 0 ; V_11 < V_61 -> V_96 . V_97 ; V_11 ++ ) {
struct V_15 * V_16 ;
struct V_21 * V_22 ;
V_16 = F_47 ( V_5 , V_82 [ V_11 ] , true ,
V_61 -> V_96 . V_98 [ V_11 ] , V_61 -> V_96 . V_99 ) ;
if ( F_35 ( V_16 ) ) {
V_68 = F_41 ( V_16 ) ;
F_36 ( V_5 -> V_5 , L_5 ,
F_48 ( V_82 [ V_11 ] ) , V_68 ) ;
goto V_95;
}
V_22 = F_49 ( V_5 , V_16 , V_11 ) ;
if ( F_35 ( V_22 ) ) {
V_68 = F_41 ( V_22 ) ;
F_36 ( V_5 -> V_5 , L_6 ,
F_48 ( V_82 [ V_11 ] ) , V_68 ) ;
goto V_95;
}
V_48 -> V_82 [ V_48 -> V_57 ++ ] = V_22 ;
}
for ( V_11 = 0 ; V_11 < V_61 -> V_100 . V_97 ; V_11 ++ ) {
struct V_15 * V_16 ;
V_16 = F_47 ( V_5 , V_87 [ V_11 ] , false ,
V_61 -> V_100 . V_98 [ V_11 ] , V_61 -> V_100 . V_99 ) ;
if ( F_35 ( V_16 ) ) {
V_68 = F_41 ( V_16 ) ;
F_36 ( V_5 -> V_5 , L_7 ,
F_48 ( V_87 [ V_11 ] ) , V_68 ) ;
goto V_95;
}
}
for ( V_11 = 0 ; V_11 < V_61 -> V_101 . V_97 ; V_11 ++ ) {
struct V_15 * V_16 ;
V_16 = F_47 ( V_5 , V_92 [ V_11 ] , false ,
V_61 -> V_101 . V_98 [ V_11 ] , V_61 -> V_101 . V_99 ) ;
if ( F_35 ( V_16 ) ) {
V_68 = F_41 ( V_16 ) ;
F_36 ( V_5 -> V_5 , L_7 ,
F_48 ( V_92 [ V_11 ] ) , V_68 ) ;
goto V_95;
}
}
for ( V_11 = 0 ; V_11 < F_24 ( V_61 -> V_51 . V_63 ) ; V_11 ++ ) {
V_68 = F_38 ( V_3 , V_11 ) ;
if ( V_68 )
goto V_95;
}
return 0 ;
V_95:
return V_68 ;
}
static void F_50 ( struct V_3 * V_3 ,
T_1 * V_102 , T_1 * V_103 )
{
T_1 V_104 ;
F_12 ( V_3 ) ;
V_104 = F_51 ( V_3 , V_105 ) ;
F_15 ( V_3 ) ;
* V_102 = F_52 ( V_104 , V_106 ) ;
* V_103 = F_52 ( V_104 , V_107 ) ;
F_29 ( L_8 , * V_102 , * V_103 ) ;
}
static int F_53 ( struct V_108 * V_109 , struct V_110 * * V_111 ,
const char * V_112 , bool V_113 )
{
struct V_114 * V_5 = & V_109 -> V_5 ;
struct V_110 * V_110 = F_54 ( V_5 , V_112 ) ;
if ( F_35 ( V_110 ) && V_113 ) {
F_36 ( V_5 , L_9 , V_112 , F_41 ( V_110 ) ) ;
return F_41 ( V_110 ) ;
}
if ( F_35 ( V_110 ) )
F_29 ( L_10 , V_112 ) ;
else
* V_111 = V_110 ;
return 0 ;
}
static struct V_24 * F_55 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
struct V_24 * V_25 ;
F_56 (encoder, dev)
if ( V_25 -> V_22 == V_22 )
return V_25 ;
return NULL ;
}
static int F_57 ( struct V_4 * V_5 , unsigned int V_115 ,
unsigned int V_6 , int * V_116 , int * V_117 ,
T_2 * V_118 , T_2 * V_119 ,
const struct V_120 * V_53 )
{
struct V_47 * V_48 = V_5 -> V_49 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
int line , V_121 , V_122 , V_123 , V_124 , V_125 ;
int V_68 = 0 ;
V_22 = V_48 -> V_82 [ V_115 ] ;
if ( ! V_22 ) {
F_58 ( L_11 , V_115 ) ;
return 0 ;
}
V_25 = F_55 ( V_22 ) ;
if ( ! V_25 ) {
F_58 ( L_12 , V_115 ) ;
return 0 ;
}
V_68 |= V_126 | V_127 ;
V_121 = V_53 -> V_128 - V_53 -> V_129 ;
V_122 = V_53 -> V_130 - V_53 -> V_128 ;
V_123 = V_121 + V_122 + 1 ;
V_124 = V_123 + V_53 -> V_131 ;
V_125 = V_53 -> V_130 ;
if ( V_118 )
* V_118 = F_59 () ;
line = F_60 ( V_25 ) ;
if ( line < V_123 ) {
line -= V_123 ;
V_68 |= V_132 ;
} else if ( line > V_124 ) {
line = line - V_125 - V_123 ;
V_68 |= V_132 ;
} else {
line -= V_123 ;
}
* V_116 = line ;
* V_117 = 0 ;
if ( V_119 )
* V_119 = F_59 () ;
return V_68 ;
}
static int F_61 ( struct V_4 * V_5 , unsigned int V_115 ,
int * V_133 ,
struct V_134 * V_135 ,
unsigned V_6 )
{
struct V_47 * V_48 = V_5 -> V_49 ;
struct V_21 * V_22 ;
if ( V_115 < 0 || V_115 >= V_48 -> V_57 ) {
F_58 ( L_11 , V_115 ) ;
return - V_66 ;
}
V_22 = V_48 -> V_82 [ V_115 ] ;
if ( ! V_22 ) {
F_58 ( L_11 , V_115 ) ;
return - V_66 ;
}
return F_62 ( V_5 , V_115 , V_133 ,
V_135 , V_6 ,
& V_22 -> V_53 ) ;
}
static T_3 F_63 ( struct V_4 * V_5 , unsigned int V_115 )
{
struct V_47 * V_48 = V_5 -> V_49 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
if ( V_115 < 0 || V_115 >= V_48 -> V_57 )
return 0 ;
V_22 = V_48 -> V_82 [ V_115 ] ;
if ( ! V_22 )
return 0 ;
V_25 = F_55 ( V_22 ) ;
if ( ! V_25 )
return 0 ;
return F_64 ( V_25 ) ;
}
struct V_1 * F_65 ( struct V_4 * V_5 )
{
struct V_108 * V_109 = V_5 -> V_136 ;
struct V_137 * V_138 ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_29 ;
T_1 V_102 , V_103 ;
int V_11 , V_68 ;
V_3 = F_66 ( sizeof( * V_3 ) , V_139 ) ;
if ( ! V_3 ) {
F_36 ( V_5 -> V_5 , L_13 ) ;
V_68 = - V_140 ;
goto V_95;
}
F_67 ( & V_3 -> V_7 ) ;
F_68 ( & V_3 -> V_98 , & V_141 ) ;
V_2 = & V_3 -> V_98 . V_98 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_142 = F_69 ( V_109 , L_14 , L_15 ) ;
if ( F_35 ( V_3 -> V_142 ) ) {
V_68 = F_41 ( V_3 -> V_142 ) ;
goto V_95;
}
V_3 -> V_143 = F_69 ( V_109 , L_16 , L_17 ) ;
if ( F_35 ( V_3 -> V_143 ) ) {
V_68 = F_41 ( V_3 -> V_143 ) ;
goto V_95;
}
V_3 -> V_144 = F_70 ( & V_109 -> V_5 , L_18 ) ;
if ( F_35 ( V_3 -> V_144 ) ) {
V_68 = F_41 ( V_3 -> V_144 ) ;
goto V_95;
}
V_68 = F_71 ( V_3 -> V_144 ) ;
if ( V_68 ) {
F_36 ( V_5 -> V_5 , L_19 , V_68 ) ;
goto V_95;
}
V_68 = F_53 ( V_109 , & V_3 -> V_37 , L_20 , true ) ;
if ( V_68 )
goto V_95;
V_68 = F_53 ( V_109 , & V_3 -> V_36 , L_21 , true ) ;
if ( V_68 )
goto V_95;
V_68 = F_53 ( V_109 , & V_3 -> V_145 , L_22 , true ) ;
if ( V_68 )
goto V_95;
V_68 = F_53 ( V_109 , & V_3 -> V_38 , L_23 , true ) ;
if ( V_68 )
goto V_95;
V_68 = F_53 ( V_109 , & V_3 -> V_146 , L_24 , true ) ;
if ( V_68 )
goto V_95;
F_53 ( V_109 , & V_3 -> V_39 , L_25 , false ) ;
F_72 ( V_3 -> V_145 , 200000000 ) ;
F_50 ( V_3 , & V_102 , & V_103 ) ;
V_3 -> V_35 = F_73 ( V_3 , V_102 , V_103 ) ;
if ( F_35 ( V_3 -> V_35 ) ) {
V_68 = F_41 ( V_3 -> V_35 ) ;
V_3 -> V_35 = NULL ;
goto V_95;
}
V_138 = F_74 ( V_3 -> V_35 ) ;
V_3 -> V_99 = V_138 -> V_147 -> V_148 . V_99 ;
F_72 ( V_3 -> V_145 , V_138 -> V_147 -> V_149 ) ;
if ( V_3 -> V_99 & V_150 ) {
V_3 -> V_34 = F_75 ( V_3 -> V_5 , & V_138 -> V_147 -> V_34 ) ;
if ( F_35 ( V_3 -> V_34 ) ) {
V_68 = F_41 ( V_3 -> V_34 ) ;
V_3 -> V_34 = NULL ;
goto V_95;
}
}
V_3 -> V_8 = F_76 ( V_5 , V_3 -> V_142 , V_3 -> V_35 ) ;
if ( F_35 ( V_3 -> V_8 ) ) {
V_68 = F_41 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
goto V_95;
}
F_12 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_151 ; V_11 ++ ) {
if ( F_77 ( V_138 -> V_147 -> V_51 . V_63 [ V_11 ] ) ||
! V_138 -> V_147 -> V_51 . V_98 [ V_11 ] )
continue;
F_6 ( V_3 , F_78 ( V_11 ) , 0 ) ;
F_6 ( V_3 , F_79 ( V_11 ) , 0x3 ) ;
}
F_15 ( V_3 ) ;
F_80 ( 16 ) ;
if ( V_138 -> V_152 . V_153 ) {
V_29 = F_81 ( & V_109 -> V_5 , V_138 -> V_152 . V_153 ) ;
if ( F_35 ( V_29 ) ) {
V_68 = F_41 ( V_29 ) ;
F_36 ( V_5 -> V_5 , L_26 , V_68 ) ;
F_82 ( V_138 -> V_152 . V_153 ) ;
goto V_95;
}
V_68 = V_29 -> V_30 -> V_154 ( V_29 , V_32 ,
F_24 ( V_32 ) ) ;
if ( V_68 ) {
F_36 ( V_5 -> V_5 , L_27 , V_68 ) ;
V_29 -> V_30 -> V_33 ( V_29 ) ;
goto V_95;
}
} else {
F_83 ( V_5 -> V_5 , L_28
L_29 ) ;
V_29 = NULL ;
}
V_3 -> V_29 = V_29 ;
V_3 -> V_65 = F_84 ( V_5 , V_29 ) ;
if ( V_3 -> V_65 < 0 ) {
V_68 = V_3 -> V_65 ;
F_36 ( V_5 -> V_5 , L_30 , V_68 ) ;
goto V_95;
}
V_68 = F_45 ( V_3 ) ;
if ( V_68 ) {
F_36 ( V_5 -> V_5 , L_31 , V_68 ) ;
goto V_95;
}
V_5 -> V_13 . V_155 = 0 ;
V_5 -> V_13 . V_156 = 0 ;
V_5 -> V_13 . V_157 = V_138 -> V_147 -> V_158 . V_157 ;
V_5 -> V_13 . V_159 = V_138 -> V_147 -> V_158 . V_159 ;
V_5 -> V_160 -> V_161 = F_61 ;
V_5 -> V_160 -> V_162 = F_57 ;
V_5 -> V_160 -> V_163 = F_63 ;
V_5 -> V_164 = 0xffffffff ;
V_5 -> V_165 = true ;
return V_2 ;
V_95:
if ( V_2 )
F_22 ( V_2 ) ;
return F_85 ( V_68 ) ;
}
