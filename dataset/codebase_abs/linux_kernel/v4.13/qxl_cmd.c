void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_2 -> V_3 . V_4 = V_2 -> V_5 ;
}
struct V_1 *
F_4 ( struct V_6 * V_3 ,
int V_7 ,
int V_5 ,
int V_8 ,
bool V_9 ,
T_1 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 = (struct V_2 * ) V_3 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = V_10 ;
if ( V_9 )
F_3 ( V_2 ) ;
F_6 ( & V_2 -> V_12 ) ;
return V_2 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_6 * V_3 = & ( V_2 -> V_2 -> V_3 ) ;
unsigned long V_14 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
V_13 = V_3 -> V_15 - V_3 -> V_16 < V_3 -> V_17 ;
if ( V_13 == 0 )
V_3 -> V_18 = V_3 -> V_16 + 1 ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
return V_13 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_6 * V_3 = & ( V_2 -> V_2 -> V_3 ) ;
unsigned long V_14 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
V_13 = V_3 -> V_15 == V_3 -> V_16 ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
return V_13 ;
}
int F_11 ( struct V_1 * V_2 ,
const void * V_19 , bool V_20 )
{
struct V_6 * V_3 = & ( V_2 -> V_2 -> V_3 ) ;
T_2 * V_21 ;
int V_22 , V_13 ;
unsigned long V_14 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
if ( V_3 -> V_15 - V_3 -> V_16 == V_3 -> V_17 ) {
V_3 -> V_18 = V_3 -> V_16 + 1 ;
F_12 () ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
if ( ! F_13 () ) {
while ( ! F_7 ( V_2 ) )
F_14 ( 1 ) ;
} else {
if ( V_20 ) {
V_13 = F_15 ( * V_2 -> V_10 ,
F_7 ( V_2 ) ) ;
if ( V_13 )
return V_13 ;
} else {
F_16 ( * V_2 -> V_10 ,
F_7 ( V_2 ) ) ;
}
}
F_8 ( & V_2 -> V_12 , V_14 ) ;
}
V_22 = V_3 -> V_15 & ( V_2 -> V_5 - 1 ) ;
V_21 = V_2 -> V_2 -> V_23 + V_22 * V_2 -> V_7 ;
memcpy ( ( void * ) V_21 , V_19 , V_2 -> V_7 ) ;
V_3 -> V_15 ++ ;
F_12 () ;
if ( V_3 -> V_15 == V_3 -> V_4 )
F_17 ( 0 , V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
return 0 ;
}
static bool F_18 ( struct V_1 * V_2 ,
void * V_24 )
{
volatile struct V_6 * V_3 = & ( V_2 -> V_2 -> V_3 ) ;
volatile T_2 * V_25 ;
int V_22 ;
unsigned long V_14 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
if ( V_3 -> V_16 == V_3 -> V_15 ) {
V_3 -> V_4 = V_3 -> V_16 + 1 ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
return false ;
}
V_22 = V_3 -> V_16 & ( V_2 -> V_5 - 1 ) ;
V_25 = V_2 -> V_2 -> V_23 + V_22 * V_2 -> V_7 ;
memcpy ( V_24 , ( void * ) V_25 , V_2 -> V_7 ) ;
V_3 -> V_16 ++ ;
F_9 ( & V_2 -> V_12 , V_14 ) ;
return true ;
}
int
F_19 ( struct V_26 * V_27 , struct V_28 * V_29 ,
T_3 type , bool V_20 )
{
struct V_30 V_31 ;
struct V_32 * V_33 = F_20 ( & V_29 -> V_34 , struct V_32 , V_35 . V_36 ) ;
V_31 . type = type ;
V_31 . V_37 = F_21 ( V_27 , F_22 ( V_33 -> V_35 . V_38 ) , V_29 -> V_39 ) ;
return F_11 ( V_27 -> V_40 , & V_31 , V_20 ) ;
}
int
F_23 ( struct V_26 * V_27 , struct V_28 * V_29 ,
T_3 type , bool V_20 )
{
struct V_30 V_31 ;
struct V_32 * V_33 = F_20 ( & V_29 -> V_34 , struct V_32 , V_35 . V_36 ) ;
V_31 . type = type ;
V_31 . V_37 = F_21 ( V_27 , F_22 ( V_33 -> V_35 . V_38 ) , V_29 -> V_39 ) ;
return F_11 ( V_27 -> V_41 , & V_31 , V_20 ) ;
}
bool F_24 ( struct V_26 * V_27 , bool V_42 )
{
if ( ! F_10 ( V_27 -> V_43 ) ) {
F_25 ( & V_27 -> V_44 ) ;
if ( V_42 )
F_26 ( & V_27 -> V_44 ) ;
return true ;
}
return false ;
}
int F_27 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
T_4 V_45 , V_46 ;
int V_47 = 0 ;
union V_48 * V_49 ;
while ( F_18 ( V_27 -> V_43 , & V_45 ) ) {
F_28 ( V_27 , L_1 , V_45 ) ;
while ( V_45 ) {
V_29 = F_29 ( V_27 , V_45 ) ;
if ( V_29 == NULL )
break;
V_49 = F_30 ( V_27 , V_29 ) ;
V_46 = V_49 -> V_50 ;
F_31 ( V_27 , V_29 , V_49 ) ;
F_28 ( V_27 , L_2 , V_45 ,
V_46 ) ;
switch ( V_29 -> type ) {
case V_51 :
case V_52 :
case V_53 :
break;
default:
F_32 ( L_3 ) ;
break;
}
V_45 = V_46 ;
F_33 ( V_27 , V_29 ) ;
++ V_47 ;
}
}
F_28 ( V_27 , L_4 , V_54 , V_47 ) ;
return V_47 ;
}
int F_34 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
unsigned long V_55 ,
struct V_56 * * V_57 )
{
struct V_56 * V_38 ;
int V_13 ;
V_13 = F_35 ( V_27 , V_55 , false ,
false , V_58 , NULL , & V_38 ) ;
if ( V_13 ) {
F_32 ( L_5 ) ;
return V_13 ;
}
V_13 = F_36 ( V_29 , V_38 ) ;
if ( V_13 )
goto V_59;
* V_57 = V_38 ;
return 0 ;
V_59:
F_37 ( & V_38 ) ;
return V_13 ;
}
static int F_38 ( struct V_26 * V_27 , T_2 V_60 , long V_61 , bool V_62 )
{
int V_63 ;
long V_64 = V_27 -> V_65 + V_61 ;
int V_13 ;
F_39 ( & V_27 -> V_66 ) ;
V_63 = F_40 ( & V_27 -> V_67 ) ;
if ( V_27 -> V_68 > V_63 ) {
if ( V_62 )
V_13 = F_41 ( V_27 -> V_69 ,
F_40 ( & V_27 -> V_67 ) > V_63 , 5 * V_70 ) ;
else
V_13 = F_42 ( V_27 -> V_69 ,
F_40 ( & V_27 -> V_67 ) > V_63 , 5 * V_70 ) ;
if ( V_13 <= 0 )
goto V_71;
V_63 = F_40 ( & V_27 -> V_67 ) ;
}
F_17 ( V_60 , V_64 ) ;
V_27 -> V_68 = V_63 + 1 ;
if ( V_62 )
V_13 = F_41 ( V_27 -> V_69 ,
F_40 ( & V_27 -> V_67 ) > V_63 , 5 * V_70 ) ;
else
V_13 = F_42 ( V_27 -> V_69 ,
F_40 ( & V_27 -> V_67 ) > V_63 , 5 * V_70 ) ;
V_71:
if ( V_13 > 0 )
V_13 = 0 ;
F_43 ( & V_27 -> V_66 ) ;
return V_13 ;
}
static void F_44 ( struct V_26 * V_27 , T_2 V_60 , long V_61 )
{
int V_13 ;
V_72:
V_13 = F_38 ( V_27 , V_60 , V_61 , false ) ;
if ( V_13 == - V_73 )
goto V_72;
}
int F_45 ( struct V_26 * V_27 , struct V_56 * V_74 ,
const struct V_75 * V_76 )
{
int V_77 ;
T_3 V_78 , V_79 ;
int V_13 ;
if ( ! V_74 -> V_80 )
F_32 ( L_6 ) ;
if ( V_74 -> V_81 )
V_77 = 0 ;
else
V_77 = V_74 -> V_77 ;
V_78 = V_74 -> V_74 . V_82 ;
V_79 = V_74 -> V_74 . V_83 ;
if ( V_76 -> V_84 < 0 || V_76 -> V_85 < 0 ||
V_76 -> V_86 > V_78 || V_76 -> V_87 > V_79 ) {
F_46 ( V_27 , L_7
L_8 , V_54 , V_77 , V_76 -> V_84 ,
V_76 -> V_85 , V_76 -> V_86 , V_76 -> V_87 , V_78 , V_79 ) ;
return - V_88 ;
}
F_39 ( & V_27 -> V_89 ) ;
V_27 -> V_90 -> V_91 = * V_76 ;
V_27 -> V_90 -> V_92 = V_77 ;
V_13 = F_38 ( V_27 , 0 , V_93 , true ) ;
F_43 ( & V_27 -> V_89 ) ;
return V_13 ;
}
void F_47 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_65 + V_94 ) ;
}
void F_48 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_65 + V_95 ) ;
}
void F_49 ( struct V_26 * V_27 )
{
F_44 ( V_27 , 0 , V_96 ) ;
}
void F_50 ( struct V_26 * V_27 )
{
F_44 ( V_27 , 0 , V_97 ) ;
}
void F_51 ( struct V_26 * V_27 ,
unsigned V_98 , struct V_56 * V_38 )
{
struct V_99 * V_100 ;
F_28 ( V_27 , L_9 , V_54 , V_27 ,
V_27 -> V_90 ) ;
V_100 = & V_27 -> V_90 -> V_101 ;
V_100 -> V_102 = V_38 -> V_74 . V_102 ;
V_100 -> V_82 = V_38 -> V_74 . V_82 ;
V_100 -> V_83 = V_38 -> V_74 . V_83 ;
V_100 -> V_103 = V_38 -> V_74 . V_103 ;
V_100 -> V_104 = F_21 ( V_27 , V_38 , V_98 ) ;
F_28 ( V_27 , L_10 , V_54 , V_100 -> V_104 ,
V_38 -> V_105 ) ;
V_100 -> V_14 = V_106 ;
V_100 -> type = V_107 ;
F_44 ( V_27 , 0 , V_108 ) ;
}
void F_52 ( struct V_26 * V_27 , T_2 V_45 )
{
F_28 ( V_27 , L_11 , V_45 ) ;
F_44 ( V_27 , V_45 , V_109 ) ;
}
void F_46 ( struct V_26 * V_27 , const char * V_110 , ... )
{
T_5 args ;
va_start ( args , V_110 ) ;
vsnprintf ( V_27 -> V_90 -> V_111 , V_112 , V_110 , args ) ;
va_end ( args ) ;
F_17 ( 0 , V_27 -> V_65 + V_113 ) ;
}
void F_53 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_65 + V_114 ) ;
}
void F_54 ( struct V_26 * V_27 )
{
F_46 ( V_27 , L_12 , V_54 ,
V_27 -> V_115 ?
V_27 -> V_115 -> V_116 : - 1 ,
V_27 -> V_115 && V_27 -> V_115 -> V_116 ?
V_27 -> V_115 -> V_117 [ 0 ] . V_82 : - 1 ,
V_27 -> V_115 && V_27 -> V_115 -> V_116 ?
V_27 -> V_115 -> V_117 [ 0 ] . V_83 : - 1 ,
V_27 -> V_115 && V_27 -> V_115 -> V_116 ?
V_27 -> V_115 -> V_117 [ 0 ] . V_118 : - 1 ,
V_27 -> V_115 && V_27 -> V_115 -> V_116 ?
V_27 -> V_115 -> V_117 [ 0 ] . V_119 : - 1
) ;
F_44 ( V_27 , 0 , V_120 ) ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_56 * V_74 )
{
T_3 V_121 ;
int V_122 ;
int V_116 = 0 ;
V_123:
F_56 ( V_124 ) ;
F_57 ( & V_27 -> V_125 ) ;
V_122 = F_58 ( & V_27 -> V_126 , NULL , 1 , 0 , V_127 ) ;
F_59 ( & V_27 -> V_125 ) ;
F_60 () ;
if ( V_122 < 0 )
return V_122 ;
V_121 = V_122 ;
if ( V_121 >= V_27 -> V_128 -> V_129 ) {
V_116 ++ ;
F_57 ( & V_27 -> V_125 ) ;
F_61 ( & V_27 -> V_126 , V_121 ) ;
F_59 ( & V_27 -> V_125 ) ;
F_62 ( V_27 , 2 ) ;
goto V_123;
}
V_74 -> V_77 = V_121 ;
F_57 ( & V_27 -> V_125 ) ;
V_27 -> V_130 = V_121 ;
F_59 ( & V_27 -> V_125 ) ;
return 0 ;
}
void F_63 ( struct V_26 * V_27 ,
T_3 V_77 )
{
F_57 ( & V_27 -> V_125 ) ;
F_61 ( & V_27 -> V_126 , V_77 ) ;
F_59 ( & V_27 -> V_125 ) ;
}
int F_64 ( struct V_26 * V_27 ,
struct V_56 * V_74 ,
struct V_131 * V_132 )
{
struct V_133 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
if ( V_74 -> V_80 )
return 0 ;
V_13 = F_65 ( V_27 , V_134 ,
NULL ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_66 ( V_29 , true ) ;
if ( V_13 )
return V_13 ;
V_31 = (struct V_133 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_134 ;
V_31 -> V_14 = V_106 ;
V_31 -> V_135 . V_136 . V_102 = V_74 -> V_74 . V_102 ;
V_31 -> V_135 . V_136 . V_82 = V_74 -> V_74 . V_82 ;
V_31 -> V_135 . V_136 . V_83 = V_74 -> V_74 . V_83 ;
V_31 -> V_135 . V_136 . V_103 = V_74 -> V_74 . V_103 ;
if ( V_132 ) {
int V_137 = V_74 -> type == V_58 ? V_27 -> V_138 : V_27 -> V_139 ;
struct V_140 * V_141 = & ( V_27 -> V_142 [ V_137 ] ) ;
V_31 -> V_135 . V_136 . V_37 = V_141 -> V_143 ;
V_31 -> V_135 . V_136 . V_37 |= ( V_132 -> V_144 << V_145 ) + V_74 -> V_146 . V_147 -> V_148 [ V_132 -> V_149 ] . V_150 ;
} else
V_31 -> V_135 . V_136 . V_37 = F_21 ( V_27 , V_74 , 0 ) ;
V_31 -> V_77 = V_74 -> V_77 ;
F_31 ( V_27 , V_29 , & V_31 -> V_151 ) ;
V_74 -> V_152 = V_29 ;
F_19 ( V_27 , V_29 , V_153 , false ) ;
F_67 ( V_29 ) ;
V_74 -> V_80 = true ;
F_57 ( & V_27 -> V_125 ) ;
F_68 ( & V_27 -> V_126 , V_74 , V_74 -> V_77 ) ;
F_59 ( & V_27 -> V_125 ) ;
return 0 ;
}
int F_69 ( struct V_26 * V_27 ,
struct V_56 * V_74 )
{
struct V_133 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
int V_45 ;
if ( ! V_74 -> V_80 )
return 0 ;
V_13 = F_65 ( V_27 , V_154 ,
V_74 -> V_152 ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_74 -> V_152 = NULL ;
F_57 ( & V_27 -> V_125 ) ;
F_68 ( & V_27 -> V_126 , NULL , V_74 -> V_77 ) ;
F_59 ( & V_27 -> V_125 ) ;
V_74 -> V_80 = false ;
V_45 = V_74 -> V_77 ;
V_74 -> V_77 = 0 ;
V_29 -> V_155 = V_45 ;
V_31 = (struct V_133 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_154 ;
V_31 -> V_77 = V_45 ;
F_31 ( V_27 , V_29 , & V_31 -> V_151 ) ;
F_19 ( V_27 , V_29 , V_153 , false ) ;
F_67 ( V_29 ) ;
return 0 ;
}
static int F_70 ( struct V_26 * V_27 , struct V_56 * V_74 )
{
struct V_75 V_156 ;
int V_13 ;
V_156 . V_84 = 0 ;
V_156 . V_86 = V_74 -> V_74 . V_82 ;
V_156 . V_85 = 0 ;
V_156 . V_87 = V_74 -> V_74 . V_83 ;
V_157:
V_13 = F_45 ( V_27 , V_74 , & V_156 ) ;
if ( V_13 == - V_73 )
goto V_157;
return V_13 ;
}
static void F_71 ( struct V_26 * V_27 , struct V_56 * V_74 , bool V_158 )
{
if ( V_158 )
F_70 ( V_27 , V_74 ) ;
F_69 ( V_27 , V_74 ) ;
}
void F_72 ( struct V_26 * V_27 , struct V_56 * V_74 , bool V_158 )
{
F_39 ( & V_27 -> V_159 ) ;
F_71 ( V_27 , V_74 , V_158 ) ;
F_43 ( & V_27 -> V_159 ) ;
}
static int F_73 ( struct V_26 * V_27 , struct V_56 * V_74 , bool V_160 )
{
int V_13 ;
V_13 = F_74 ( V_74 , false ) ;
if ( V_13 )
return V_13 ;
if ( V_160 )
F_43 ( & V_27 -> V_159 ) ;
V_13 = F_75 ( & V_74 -> V_146 , true , ! V_160 ) ;
if ( V_160 )
F_39 ( & V_27 -> V_159 ) ;
if ( V_13 ) {
F_76 ( V_74 ) ;
return V_13 ;
}
F_71 ( V_27 , V_74 , true ) ;
F_76 ( V_74 ) ;
return 0 ;
}
static int F_62 ( struct V_26 * V_27 , int V_161 )
{
int V_162 = 0 ;
int V_47 , V_13 ;
bool V_160 = false ;
int V_144 = 0 ;
F_39 ( & V_27 -> V_159 ) ;
V_123:
F_57 ( & V_27 -> V_125 ) ;
V_144 = V_27 -> V_130 + 1 ;
F_59 ( & V_27 -> V_125 ) ;
for ( V_47 = V_144 ; V_47 < V_144 + V_27 -> V_128 -> V_129 ; V_47 ++ ) {
void * V_163 ;
int V_164 = V_47 % V_27 -> V_128 -> V_129 ;
F_57 ( & V_27 -> V_125 ) ;
V_163 = F_77 ( & V_27 -> V_126 , V_164 ) ;
F_59 ( & V_27 -> V_125 ) ;
if ( ! V_163 )
continue;
V_13 = F_73 ( V_27 , V_163 , V_160 ) ;
if ( V_13 == 0 )
V_162 ++ ;
if ( V_162 >= V_161 )
break;
}
if ( V_162 == 0 && V_160 == false ) {
V_160 = true ;
goto V_123;
}
F_43 ( & V_27 -> V_159 ) ;
if ( V_162 ) {
F_78 ( 500 , 1000 ) ;
F_24 ( V_27 , true ) ;
}
return 0 ;
}
