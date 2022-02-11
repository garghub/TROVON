void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
struct V_1 *
F_3 ( struct V_3 * V_4 ,
int V_5 ,
int V_6 ,
int V_7 ,
bool V_8 ,
T_1 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 = (struct V_2 * ) V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_9 ;
if ( V_8 )
V_4 -> V_11 = V_2 -> V_6 ;
F_5 ( & V_2 -> V_12 ) ;
return V_2 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = & ( V_2 -> V_2 -> V_4 ) ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_12 , V_14 ) ;
V_13 = V_4 -> V_15 - V_4 -> V_16 < V_4 -> V_17 ;
if ( V_13 == 0 )
V_4 -> V_18 = V_4 -> V_16 + 1 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = & ( V_2 -> V_2 -> V_4 ) ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_12 , V_14 ) ;
V_13 = V_4 -> V_15 == V_4 -> V_16 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
return V_13 ;
}
int F_10 ( struct V_1 * V_2 ,
const void * V_19 , bool V_20 )
{
struct V_3 * V_4 = & ( V_2 -> V_2 -> V_4 ) ;
T_2 * V_21 ;
int V_22 , V_13 ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_12 , V_14 ) ;
if ( V_4 -> V_15 - V_4 -> V_16 == V_4 -> V_17 ) {
V_4 -> V_18 = V_4 -> V_16 + 1 ;
F_11 () ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
if ( ! F_12 () ) {
while ( ! F_6 ( V_2 ) )
F_13 ( 1 ) ;
} else {
if ( V_20 ) {
V_13 = F_14 ( * V_2 -> V_9 ,
F_6 ( V_2 ) ) ;
if ( V_13 )
return V_13 ;
} else {
F_15 ( * V_2 -> V_9 ,
F_6 ( V_2 ) ) ;
}
}
F_7 ( & V_2 -> V_12 , V_14 ) ;
}
V_22 = V_4 -> V_15 & ( V_2 -> V_6 - 1 ) ;
V_21 = V_2 -> V_2 -> V_23 + V_22 * V_2 -> V_5 ;
memcpy ( ( void * ) V_21 , V_19 , V_2 -> V_5 ) ;
V_4 -> V_15 ++ ;
F_11 () ;
if ( V_4 -> V_15 == V_4 -> V_11 )
F_16 ( 0 , V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 ,
void * V_24 )
{
volatile struct V_3 * V_4 = & ( V_2 -> V_2 -> V_4 ) ;
volatile T_2 * V_25 ;
int V_22 ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_12 , V_14 ) ;
if ( V_4 -> V_16 == V_4 -> V_15 ) {
V_4 -> V_11 = V_4 -> V_16 + 1 ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
return false ;
}
V_22 = V_4 -> V_16 & ( V_2 -> V_6 - 1 ) ;
V_25 = V_2 -> V_2 -> V_23 + V_22 * V_2 -> V_5 ;
memcpy ( V_24 , ( void * ) V_25 , V_2 -> V_5 ) ;
V_4 -> V_16 ++ ;
F_8 ( & V_2 -> V_12 , V_14 ) ;
return true ;
}
int
F_18 ( struct V_26 * V_27 , struct V_28 * V_29 ,
T_3 type , bool V_20 )
{
struct V_30 V_31 ;
V_31 . type = type ;
V_31 . V_32 = F_19 ( V_27 , V_29 -> V_33 [ 0 ] , V_29 -> V_34 ) ;
return F_10 ( V_27 -> V_35 , & V_31 , V_20 ) ;
}
int
F_20 ( struct V_26 * V_27 , struct V_28 * V_29 ,
T_3 type , bool V_20 )
{
struct V_30 V_31 ;
V_31 . type = type ;
V_31 . V_32 = F_19 ( V_27 , V_29 -> V_33 [ 0 ] , V_29 -> V_34 ) ;
return F_10 ( V_27 -> V_36 , & V_31 , V_20 ) ;
}
bool F_21 ( struct V_26 * V_27 , bool V_37 )
{
if ( ! F_9 ( V_27 -> V_38 ) ) {
F_22 ( V_27 -> V_39 , & V_27 -> V_40 ) ;
if ( V_37 )
F_23 ( & V_27 -> V_40 ) ;
return true ;
}
return false ;
}
int F_24 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
T_4 V_41 , V_42 ;
int V_43 = 0 ;
int V_13 ;
union V_44 * V_45 ;
while ( F_17 ( V_27 -> V_38 , & V_41 ) ) {
F_25 ( V_27 , L_1 , V_41 ) ;
while ( V_41 ) {
V_29 = F_26 ( V_27 , V_41 ) ;
if ( V_29 == NULL )
break;
V_13 = F_27 ( V_27 , V_29 , false ) ;
if ( V_13 ) {
F_28 ( V_27 , L_2 , V_41 ) ;
F_29 ( L_3 , V_41 ) ;
}
V_45 = F_30 ( V_27 , V_29 ) ;
V_42 = V_45 -> V_46 ;
F_31 ( V_27 , V_29 , V_45 ) ;
F_32 ( V_27 , V_29 ) ;
F_25 ( V_27 , L_4 , V_41 ,
V_42 ) ;
switch ( V_29 -> type ) {
case V_47 :
case V_48 :
case V_49 :
break;
default:
F_29 ( L_5 ) ;
break;
}
V_41 = V_42 ;
F_33 ( V_27 , V_29 ) ;
++ V_43 ;
}
}
F_25 ( V_27 , L_6 , V_50 , V_43 ) ;
return V_43 ;
}
int F_34 ( struct V_26 * V_27 , unsigned long V_51 ,
struct V_52 * * V_53 )
{
struct V_52 * V_54 ;
int V_13 ;
V_13 = F_35 ( V_27 , V_51 , false ,
V_55 , NULL , & V_54 ) ;
if ( V_13 ) {
F_29 ( L_7 ) ;
return V_13 ;
}
V_13 = F_36 ( V_54 , false ) ;
if ( F_37 ( V_13 != 0 ) )
goto V_56;
* V_53 = V_54 ;
return 0 ;
V_56:
F_38 ( & V_54 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 , T_2 V_57 , long V_58 , bool V_59 )
{
int V_60 ;
long V_61 = V_27 -> V_62 + V_58 ;
int V_13 ;
F_40 ( & V_27 -> V_63 ) ;
V_60 = F_41 ( & V_27 -> V_64 ) ;
if ( V_27 -> V_65 > V_60 ) {
if ( V_59 )
V_13 = F_42 ( V_27 -> V_66 ,
F_41 ( & V_27 -> V_64 ) > V_60 , 5 * V_67 ) ;
else
V_13 = F_43 ( V_27 -> V_66 ,
F_41 ( & V_27 -> V_64 ) > V_60 , 5 * V_67 ) ;
if ( V_13 <= 0 )
goto V_68;
V_60 = F_41 ( & V_27 -> V_64 ) ;
}
F_16 ( V_57 , V_61 ) ;
V_27 -> V_65 = V_60 + 1 ;
if ( V_59 )
V_13 = F_42 ( V_27 -> V_66 ,
F_41 ( & V_27 -> V_64 ) > V_60 , 5 * V_67 ) ;
else
V_13 = F_43 ( V_27 -> V_66 ,
F_41 ( & V_27 -> V_64 ) > V_60 , 5 * V_67 ) ;
V_68:
if ( V_13 > 0 )
V_13 = 0 ;
F_44 ( & V_27 -> V_63 ) ;
return V_13 ;
}
static void F_45 ( struct V_26 * V_27 , T_2 V_57 , long V_58 )
{
int V_13 ;
V_69:
V_13 = F_39 ( V_27 , V_57 , V_58 , false ) ;
if ( V_13 == - V_70 )
goto V_69;
}
int F_46 ( struct V_26 * V_27 , struct V_52 * V_71 ,
const struct V_72 * V_73 )
{
int V_74 ;
T_3 V_75 , V_76 ;
int V_13 ;
if ( ! V_71 -> V_77 )
F_29 ( L_8 ) ;
if ( V_71 -> V_78 )
V_74 = 0 ;
else
V_74 = V_71 -> V_74 ;
V_75 = V_71 -> V_71 . V_79 ;
V_76 = V_71 -> V_71 . V_80 ;
if ( V_73 -> V_81 < 0 || V_73 -> V_82 < 0 ||
V_73 -> V_83 > V_75 || V_73 -> V_84 > V_76 ) {
F_28 ( V_27 , L_9
L_10 , V_50 , V_74 , V_73 -> V_81 ,
V_73 -> V_82 , V_73 -> V_83 , V_73 -> V_84 , V_75 , V_76 ) ;
return - V_85 ;
}
F_40 ( & V_27 -> V_86 ) ;
V_27 -> V_87 -> V_88 = * V_73 ;
V_27 -> V_87 -> V_89 = V_74 ;
V_13 = F_39 ( V_27 , 0 , V_90 , true ) ;
F_44 ( & V_27 -> V_86 ) ;
return V_13 ;
}
void F_47 ( struct V_26 * V_27 )
{
F_16 ( 0 , V_27 -> V_62 + V_91 ) ;
}
void F_48 ( struct V_26 * V_27 )
{
F_16 ( 0 , V_27 -> V_62 + V_92 ) ;
}
void F_49 ( struct V_26 * V_27 )
{
F_45 ( V_27 , 0 , V_93 ) ;
}
void F_50 ( struct V_26 * V_27 )
{
F_45 ( V_27 , 0 , V_94 ) ;
}
void F_51 ( struct V_26 * V_27 , unsigned V_79 ,
unsigned V_80 , unsigned V_95 , struct V_52 * V_54 )
{
struct V_96 * V_97 ;
F_25 ( V_27 , L_11 , V_50 , V_27 ,
V_27 -> V_87 ) ;
V_97 = & V_27 -> V_87 -> V_98 ;
V_97 -> V_99 = V_54 -> V_71 . V_99 ;
V_97 -> V_79 = V_79 ;
V_97 -> V_80 = V_80 ;
V_97 -> V_100 = V_54 -> V_71 . V_100 ;
V_97 -> V_101 = F_19 ( V_27 , V_54 , V_95 ) ;
F_25 ( V_27 , L_12 , V_50 , V_97 -> V_101 ,
V_54 -> V_102 ) ;
V_97 -> V_14 = V_103 ;
V_97 -> type = V_104 ;
F_45 ( V_27 , 0 , V_105 ) ;
}
void F_52 ( struct V_26 * V_27 , T_2 V_41 )
{
F_25 ( V_27 , L_13 , V_41 ) ;
F_45 ( V_27 , V_41 , V_106 ) ;
}
void F_28 ( struct V_26 * V_27 , const char * V_107 , ... )
{
T_5 args ;
va_start ( args , V_107 ) ;
vsnprintf ( V_27 -> V_87 -> V_108 , V_109 , V_107 , args ) ;
va_end ( args ) ;
F_16 ( 0 , V_27 -> V_62 + V_110 ) ;
}
void F_53 ( struct V_26 * V_27 )
{
F_16 ( 0 , V_27 -> V_62 + V_111 ) ;
}
void F_54 ( struct V_26 * V_27 )
{
F_28 ( V_27 , L_14 , V_50 ,
V_27 -> V_112 ?
V_27 -> V_112 -> V_113 : - 1 ,
V_27 -> V_112 && V_27 -> V_112 -> V_113 ?
V_27 -> V_112 -> V_114 [ 0 ] . V_79 : - 1 ,
V_27 -> V_112 && V_27 -> V_112 -> V_113 ?
V_27 -> V_112 -> V_114 [ 0 ] . V_80 : - 1 ,
V_27 -> V_112 && V_27 -> V_112 -> V_113 ?
V_27 -> V_112 -> V_114 [ 0 ] . V_115 : - 1 ,
V_27 -> V_112 && V_27 -> V_112 -> V_113 ?
V_27 -> V_112 -> V_114 [ 0 ] . V_116 : - 1
) ;
F_45 ( V_27 , 0 , V_117 ) ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_52 * V_71 )
{
T_3 V_118 ;
int V_119 ;
int V_113 = 0 ;
V_120:
F_56 ( V_121 ) ;
F_57 ( & V_27 -> V_122 ) ;
V_119 = F_58 ( & V_27 -> V_123 , NULL , 1 , 0 , V_124 ) ;
F_59 ( & V_27 -> V_122 ) ;
F_60 () ;
if ( V_119 < 0 )
return V_119 ;
V_118 = V_119 ;
if ( V_118 >= V_27 -> V_125 -> V_126 ) {
V_113 ++ ;
F_57 ( & V_27 -> V_122 ) ;
F_61 ( & V_27 -> V_123 , V_118 ) ;
F_59 ( & V_27 -> V_122 ) ;
F_62 ( V_27 , 2 ) ;
goto V_120;
}
V_71 -> V_74 = V_118 ;
F_57 ( & V_27 -> V_122 ) ;
V_27 -> V_127 = V_118 ;
F_59 ( & V_27 -> V_122 ) ;
return 0 ;
}
void F_63 ( struct V_26 * V_27 ,
T_3 V_74 )
{
F_57 ( & V_27 -> V_122 ) ;
F_61 ( & V_27 -> V_123 , V_74 ) ;
F_59 ( & V_27 -> V_122 ) ;
}
int F_64 ( struct V_26 * V_27 ,
struct V_52 * V_71 ,
struct V_128 * V_129 )
{
struct V_130 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
if ( V_71 -> V_77 )
return 0 ;
V_13 = F_65 ( V_27 , V_131 ,
NULL ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_31 = (struct V_130 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_131 ;
V_31 -> V_132 . V_133 . V_99 = V_71 -> V_71 . V_99 ;
V_31 -> V_132 . V_133 . V_79 = V_71 -> V_71 . V_79 ;
V_31 -> V_132 . V_133 . V_80 = V_71 -> V_71 . V_80 ;
V_31 -> V_132 . V_133 . V_100 = V_71 -> V_71 . V_100 ;
if ( V_129 ) {
int V_134 = V_71 -> type == V_55 ? V_27 -> V_135 : V_27 -> V_136 ;
struct V_137 * V_138 = & ( V_27 -> V_139 [ V_134 ] ) ;
V_31 -> V_132 . V_133 . V_32 = V_138 -> V_140 ;
V_31 -> V_132 . V_133 . V_32 |= ( V_129 -> V_141 << V_142 ) + V_71 -> V_143 . V_144 -> V_145 [ V_129 -> V_146 ] . V_147 ;
} else
V_31 -> V_132 . V_133 . V_32 = F_19 ( V_27 , V_71 , 0 ) ;
V_31 -> V_74 = V_71 -> V_74 ;
F_31 ( V_27 , V_29 , & V_31 -> V_148 ) ;
V_71 -> V_149 = V_29 ;
F_66 ( V_27 , V_29 ) ;
F_18 ( V_27 , V_29 , V_150 , false ) ;
F_32 ( V_27 , V_29 ) ;
V_71 -> V_77 = true ;
F_57 ( & V_27 -> V_122 ) ;
F_67 ( & V_27 -> V_123 , V_71 , V_71 -> V_74 ) ;
F_59 ( & V_27 -> V_122 ) ;
return 0 ;
}
int F_68 ( struct V_26 * V_27 ,
struct V_52 * V_71 )
{
struct V_130 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
int V_41 ;
if ( ! V_71 -> V_77 )
return 0 ;
V_13 = F_65 ( V_27 , V_151 ,
V_71 -> V_149 ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_71 -> V_149 = NULL ;
F_57 ( & V_27 -> V_122 ) ;
F_67 ( & V_27 -> V_123 , NULL , V_71 -> V_74 ) ;
F_59 ( & V_27 -> V_122 ) ;
V_71 -> V_77 = false ;
V_41 = V_71 -> V_74 ;
V_71 -> V_74 = 0 ;
V_29 -> V_152 = V_41 ;
V_31 = (struct V_130 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_151 ;
V_31 -> V_74 = V_41 ;
F_31 ( V_27 , V_29 , & V_31 -> V_148 ) ;
F_66 ( V_27 , V_29 ) ;
F_18 ( V_27 , V_29 , V_150 , false ) ;
F_32 ( V_27 , V_29 ) ;
return 0 ;
}
int F_69 ( struct V_26 * V_27 , struct V_52 * V_71 )
{
struct V_72 V_153 ;
int V_13 ;
V_153 . V_81 = 0 ;
V_153 . V_83 = V_71 -> V_71 . V_79 ;
V_153 . V_82 = 0 ;
V_153 . V_84 = V_71 -> V_71 . V_80 ;
V_154:
V_13 = F_46 ( V_27 , V_71 , & V_153 ) ;
if ( V_13 == - V_70 )
goto V_154;
return V_13 ;
}
static void F_70 ( struct V_26 * V_27 , struct V_52 * V_71 , bool V_155 )
{
if ( V_155 )
F_69 ( V_27 , V_71 ) ;
F_68 ( V_27 , V_71 ) ;
}
void F_71 ( struct V_26 * V_27 , struct V_52 * V_71 , bool V_155 )
{
F_40 ( & V_27 -> V_156 ) ;
F_70 ( V_27 , V_71 , V_155 ) ;
F_44 ( & V_27 -> V_156 ) ;
}
static int F_72 ( struct V_26 * V_27 , struct V_52 * V_71 , bool V_157 )
{
int V_13 ;
V_13 = F_36 ( V_71 , false ) ;
if ( V_13 == - V_158 )
return - V_158 ;
if ( V_71 -> V_159 . V_160 > 0 && V_157 == false ) {
F_73 ( V_71 ) ;
return - V_158 ;
}
if ( V_157 )
F_44 ( & V_27 -> V_156 ) ;
F_57 ( & V_71 -> V_143 . V_144 -> V_161 ) ;
V_13 = F_74 ( & V_71 -> V_143 , true , true , ! V_157 ) ;
F_59 ( & V_71 -> V_143 . V_144 -> V_161 ) ;
if ( V_157 )
F_40 ( & V_27 -> V_156 ) ;
if ( V_13 == - V_158 ) {
F_73 ( V_71 ) ;
return - V_158 ;
}
F_70 ( V_27 , V_71 , true ) ;
F_73 ( V_71 ) ;
return 0 ;
}
static int F_62 ( struct V_26 * V_27 , int V_162 )
{
int V_163 = 0 ;
int V_43 , V_13 ;
bool V_157 = false ;
int V_141 = 0 ;
F_40 ( & V_27 -> V_156 ) ;
V_120:
F_57 ( & V_27 -> V_122 ) ;
V_141 = V_27 -> V_127 + 1 ;
F_59 ( & V_27 -> V_122 ) ;
for ( V_43 = V_141 ; V_43 < V_141 + V_27 -> V_125 -> V_126 ; V_43 ++ ) {
void * V_164 ;
int V_165 = V_43 % V_27 -> V_125 -> V_126 ;
F_57 ( & V_27 -> V_122 ) ;
V_164 = F_75 ( & V_27 -> V_123 , V_165 ) ;
F_59 ( & V_27 -> V_122 ) ;
if ( ! V_164 )
continue;
V_13 = F_72 ( V_27 , V_164 , V_157 ) ;
if ( V_13 == 0 )
V_163 ++ ;
if ( V_163 >= V_162 )
break;
}
if ( V_163 == 0 && V_157 == false ) {
V_157 = true ;
goto V_120;
}
F_44 ( & V_27 -> V_156 ) ;
if ( V_163 ) {
F_76 ( 500 , 1000 ) ;
F_21 ( V_27 , true ) ;
}
return 0 ;
}
