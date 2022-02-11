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
F_25 ( V_27 -> V_44 , & V_27 -> V_45 ) ;
if ( V_42 )
F_26 ( & V_27 -> V_45 ) ;
return true ;
}
return false ;
}
int F_27 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
T_4 V_46 , V_47 ;
int V_48 = 0 ;
union V_49 * V_50 ;
while ( F_18 ( V_27 -> V_43 , & V_46 ) ) {
F_28 ( V_27 , L_1 , V_46 ) ;
while ( V_46 ) {
V_29 = F_29 ( V_27 , V_46 ) ;
if ( V_29 == NULL )
break;
V_50 = F_30 ( V_27 , V_29 ) ;
V_47 = V_50 -> V_51 ;
F_31 ( V_27 , V_29 , V_50 ) ;
F_28 ( V_27 , L_2 , V_46 ,
V_47 ) ;
switch ( V_29 -> type ) {
case V_52 :
case V_53 :
case V_54 :
break;
default:
F_32 ( L_3 ) ;
break;
}
V_46 = V_47 ;
F_33 ( V_27 , V_29 ) ;
++ V_48 ;
}
}
F_28 ( V_27 , L_4 , V_55 , V_48 ) ;
return V_48 ;
}
int F_34 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
unsigned long V_56 ,
struct V_57 * * V_58 )
{
struct V_57 * V_38 ;
int V_13 ;
V_13 = F_35 ( V_27 , V_56 , false ,
false , V_59 , NULL , & V_38 ) ;
if ( V_13 ) {
F_32 ( L_5 ) ;
return V_13 ;
}
V_13 = F_36 ( V_29 , V_38 ) ;
if ( V_13 )
goto V_60;
* V_58 = V_38 ;
return 0 ;
V_60:
F_37 ( & V_38 ) ;
return V_13 ;
}
static int F_38 ( struct V_26 * V_27 , T_2 V_61 , long V_62 , bool V_63 )
{
int V_64 ;
long V_65 = V_27 -> V_66 + V_62 ;
int V_13 ;
F_39 ( & V_27 -> V_67 ) ;
V_64 = F_40 ( & V_27 -> V_68 ) ;
if ( V_27 -> V_69 > V_64 ) {
if ( V_63 )
V_13 = F_41 ( V_27 -> V_70 ,
F_40 ( & V_27 -> V_68 ) > V_64 , 5 * V_71 ) ;
else
V_13 = F_42 ( V_27 -> V_70 ,
F_40 ( & V_27 -> V_68 ) > V_64 , 5 * V_71 ) ;
if ( V_13 <= 0 )
goto V_72;
V_64 = F_40 ( & V_27 -> V_68 ) ;
}
F_17 ( V_61 , V_65 ) ;
V_27 -> V_69 = V_64 + 1 ;
if ( V_63 )
V_13 = F_41 ( V_27 -> V_70 ,
F_40 ( & V_27 -> V_68 ) > V_64 , 5 * V_71 ) ;
else
V_13 = F_42 ( V_27 -> V_70 ,
F_40 ( & V_27 -> V_68 ) > V_64 , 5 * V_71 ) ;
V_72:
if ( V_13 > 0 )
V_13 = 0 ;
F_43 ( & V_27 -> V_67 ) ;
return V_13 ;
}
static void F_44 ( struct V_26 * V_27 , T_2 V_61 , long V_62 )
{
int V_13 ;
V_73:
V_13 = F_38 ( V_27 , V_61 , V_62 , false ) ;
if ( V_13 == - V_74 )
goto V_73;
}
int F_45 ( struct V_26 * V_27 , struct V_57 * V_75 ,
const struct V_76 * V_77 )
{
int V_78 ;
T_3 V_79 , V_80 ;
int V_13 ;
if ( ! V_75 -> V_81 )
F_32 ( L_6 ) ;
if ( V_75 -> V_82 )
V_78 = 0 ;
else
V_78 = V_75 -> V_78 ;
V_79 = V_75 -> V_75 . V_83 ;
V_80 = V_75 -> V_75 . V_84 ;
if ( V_77 -> V_85 < 0 || V_77 -> V_86 < 0 ||
V_77 -> V_87 > V_79 || V_77 -> V_88 > V_80 ) {
F_46 ( V_27 , L_7
L_8 , V_55 , V_78 , V_77 -> V_85 ,
V_77 -> V_86 , V_77 -> V_87 , V_77 -> V_88 , V_79 , V_80 ) ;
return - V_89 ;
}
F_39 ( & V_27 -> V_90 ) ;
V_27 -> V_91 -> V_92 = * V_77 ;
V_27 -> V_91 -> V_93 = V_78 ;
V_13 = F_38 ( V_27 , 0 , V_94 , true ) ;
F_43 ( & V_27 -> V_90 ) ;
return V_13 ;
}
void F_47 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_66 + V_95 ) ;
}
void F_48 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_66 + V_96 ) ;
}
void F_49 ( struct V_26 * V_27 )
{
F_44 ( V_27 , 0 , V_97 ) ;
}
void F_50 ( struct V_26 * V_27 )
{
F_44 ( V_27 , 0 , V_98 ) ;
}
void F_51 ( struct V_26 * V_27 ,
unsigned V_99 , struct V_57 * V_38 )
{
struct V_100 * V_101 ;
F_28 ( V_27 , L_9 , V_55 , V_27 ,
V_27 -> V_91 ) ;
V_101 = & V_27 -> V_91 -> V_102 ;
V_101 -> V_103 = V_38 -> V_75 . V_103 ;
V_101 -> V_83 = V_38 -> V_75 . V_83 ;
V_101 -> V_84 = V_38 -> V_75 . V_84 ;
V_101 -> V_104 = V_38 -> V_75 . V_104 ;
V_101 -> V_105 = F_21 ( V_27 , V_38 , V_99 ) ;
F_28 ( V_27 , L_10 , V_55 , V_101 -> V_105 ,
V_38 -> V_106 ) ;
V_101 -> V_14 = V_107 ;
V_101 -> type = V_108 ;
F_44 ( V_27 , 0 , V_109 ) ;
}
void F_52 ( struct V_26 * V_27 , T_2 V_46 )
{
F_28 ( V_27 , L_11 , V_46 ) ;
F_44 ( V_27 , V_46 , V_110 ) ;
}
void F_46 ( struct V_26 * V_27 , const char * V_111 , ... )
{
T_5 args ;
va_start ( args , V_111 ) ;
vsnprintf ( V_27 -> V_91 -> V_112 , V_113 , V_111 , args ) ;
va_end ( args ) ;
F_17 ( 0 , V_27 -> V_66 + V_114 ) ;
}
void F_53 ( struct V_26 * V_27 )
{
F_17 ( 0 , V_27 -> V_66 + V_115 ) ;
}
void F_54 ( struct V_26 * V_27 )
{
F_46 ( V_27 , L_12 , V_55 ,
V_27 -> V_116 ?
V_27 -> V_116 -> V_117 : - 1 ,
V_27 -> V_116 && V_27 -> V_116 -> V_117 ?
V_27 -> V_116 -> V_118 [ 0 ] . V_83 : - 1 ,
V_27 -> V_116 && V_27 -> V_116 -> V_117 ?
V_27 -> V_116 -> V_118 [ 0 ] . V_84 : - 1 ,
V_27 -> V_116 && V_27 -> V_116 -> V_117 ?
V_27 -> V_116 -> V_118 [ 0 ] . V_119 : - 1 ,
V_27 -> V_116 && V_27 -> V_116 -> V_117 ?
V_27 -> V_116 -> V_118 [ 0 ] . V_120 : - 1
) ;
F_44 ( V_27 , 0 , V_121 ) ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_57 * V_75 )
{
T_3 V_122 ;
int V_123 ;
int V_117 = 0 ;
V_124:
F_56 ( V_125 ) ;
F_57 ( & V_27 -> V_126 ) ;
V_123 = F_58 ( & V_27 -> V_127 , NULL , 1 , 0 , V_128 ) ;
F_59 ( & V_27 -> V_126 ) ;
F_60 () ;
if ( V_123 < 0 )
return V_123 ;
V_122 = V_123 ;
if ( V_122 >= V_27 -> V_129 -> V_130 ) {
V_117 ++ ;
F_57 ( & V_27 -> V_126 ) ;
F_61 ( & V_27 -> V_127 , V_122 ) ;
F_59 ( & V_27 -> V_126 ) ;
F_62 ( V_27 , 2 ) ;
goto V_124;
}
V_75 -> V_78 = V_122 ;
F_57 ( & V_27 -> V_126 ) ;
V_27 -> V_131 = V_122 ;
F_59 ( & V_27 -> V_126 ) ;
return 0 ;
}
void F_63 ( struct V_26 * V_27 ,
T_3 V_78 )
{
F_57 ( & V_27 -> V_126 ) ;
F_61 ( & V_27 -> V_127 , V_78 ) ;
F_59 ( & V_27 -> V_126 ) ;
}
int F_64 ( struct V_26 * V_27 ,
struct V_57 * V_75 ,
struct V_132 * V_133 )
{
struct V_134 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
if ( V_75 -> V_81 )
return 0 ;
V_13 = F_65 ( V_27 , V_135 ,
NULL ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_66 ( V_29 , true ) ;
if ( V_13 )
return V_13 ;
V_31 = (struct V_134 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_135 ;
V_31 -> V_14 = V_107 ;
V_31 -> V_136 . V_137 . V_103 = V_75 -> V_75 . V_103 ;
V_31 -> V_136 . V_137 . V_83 = V_75 -> V_75 . V_83 ;
V_31 -> V_136 . V_137 . V_84 = V_75 -> V_75 . V_84 ;
V_31 -> V_136 . V_137 . V_104 = V_75 -> V_75 . V_104 ;
if ( V_133 ) {
int V_138 = V_75 -> type == V_59 ? V_27 -> V_139 : V_27 -> V_140 ;
struct V_141 * V_142 = & ( V_27 -> V_143 [ V_138 ] ) ;
V_31 -> V_136 . V_137 . V_37 = V_142 -> V_144 ;
V_31 -> V_136 . V_137 . V_37 |= ( V_133 -> V_145 << V_146 ) + V_75 -> V_147 . V_148 -> V_149 [ V_133 -> V_150 ] . V_151 ;
} else
V_31 -> V_136 . V_137 . V_37 = F_21 ( V_27 , V_75 , 0 ) ;
V_31 -> V_78 = V_75 -> V_78 ;
F_31 ( V_27 , V_29 , & V_31 -> V_152 ) ;
V_75 -> V_153 = V_29 ;
F_19 ( V_27 , V_29 , V_154 , false ) ;
F_67 ( V_29 ) ;
V_75 -> V_81 = true ;
F_57 ( & V_27 -> V_126 ) ;
F_68 ( & V_27 -> V_127 , V_75 , V_75 -> V_78 ) ;
F_59 ( & V_27 -> V_126 ) ;
return 0 ;
}
int F_69 ( struct V_26 * V_27 ,
struct V_57 * V_75 )
{
struct V_134 * V_31 ;
struct V_28 * V_29 ;
int V_13 ;
int V_46 ;
if ( ! V_75 -> V_81 )
return 0 ;
V_13 = F_65 ( V_27 , V_155 ,
V_75 -> V_153 ,
& V_29 ) ;
if ( V_13 )
return V_13 ;
V_75 -> V_153 = NULL ;
F_57 ( & V_27 -> V_126 ) ;
F_68 ( & V_27 -> V_127 , NULL , V_75 -> V_78 ) ;
F_59 ( & V_27 -> V_126 ) ;
V_75 -> V_81 = false ;
V_46 = V_75 -> V_78 ;
V_75 -> V_78 = 0 ;
V_29 -> V_156 = V_46 ;
V_31 = (struct V_134 * ) F_30 ( V_27 , V_29 ) ;
V_31 -> type = V_155 ;
V_31 -> V_78 = V_46 ;
F_31 ( V_27 , V_29 , & V_31 -> V_152 ) ;
F_19 ( V_27 , V_29 , V_154 , false ) ;
F_67 ( V_29 ) ;
return 0 ;
}
int F_70 ( struct V_26 * V_27 , struct V_57 * V_75 )
{
struct V_76 V_157 ;
int V_13 ;
V_157 . V_85 = 0 ;
V_157 . V_87 = V_75 -> V_75 . V_83 ;
V_157 . V_86 = 0 ;
V_157 . V_88 = V_75 -> V_75 . V_84 ;
V_158:
V_13 = F_45 ( V_27 , V_75 , & V_157 ) ;
if ( V_13 == - V_74 )
goto V_158;
return V_13 ;
}
static void F_71 ( struct V_26 * V_27 , struct V_57 * V_75 , bool V_159 )
{
if ( V_159 )
F_70 ( V_27 , V_75 ) ;
F_69 ( V_27 , V_75 ) ;
}
void F_72 ( struct V_26 * V_27 , struct V_57 * V_75 , bool V_159 )
{
F_39 ( & V_27 -> V_160 ) ;
F_71 ( V_27 , V_75 , V_159 ) ;
F_43 ( & V_27 -> V_160 ) ;
}
static int F_73 ( struct V_26 * V_27 , struct V_57 * V_75 , bool V_161 )
{
int V_13 ;
V_13 = F_74 ( V_75 , false ) ;
if ( V_13 )
return V_13 ;
if ( V_161 )
F_43 ( & V_27 -> V_160 ) ;
V_13 = F_75 ( & V_75 -> V_147 , true , ! V_161 ) ;
if ( V_161 )
F_39 ( & V_27 -> V_160 ) ;
if ( V_13 ) {
F_76 ( V_75 ) ;
return V_13 ;
}
F_71 ( V_27 , V_75 , true ) ;
F_76 ( V_75 ) ;
return 0 ;
}
static int F_62 ( struct V_26 * V_27 , int V_162 )
{
int V_163 = 0 ;
int V_48 , V_13 ;
bool V_161 = false ;
int V_145 = 0 ;
F_39 ( & V_27 -> V_160 ) ;
V_124:
F_57 ( & V_27 -> V_126 ) ;
V_145 = V_27 -> V_131 + 1 ;
F_59 ( & V_27 -> V_126 ) ;
for ( V_48 = V_145 ; V_48 < V_145 + V_27 -> V_129 -> V_130 ; V_48 ++ ) {
void * V_164 ;
int V_165 = V_48 % V_27 -> V_129 -> V_130 ;
F_57 ( & V_27 -> V_126 ) ;
V_164 = F_77 ( & V_27 -> V_127 , V_165 ) ;
F_59 ( & V_27 -> V_126 ) ;
if ( ! V_164 )
continue;
V_13 = F_73 ( V_27 , V_164 , V_161 ) ;
if ( V_13 == 0 )
V_163 ++ ;
if ( V_163 >= V_162 )
break;
}
if ( V_163 == 0 && V_161 == false ) {
V_161 = true ;
goto V_124;
}
F_43 ( & V_27 -> V_160 ) ;
if ( V_163 ) {
F_78 ( 500 , 1000 ) ;
F_24 ( V_27 , true ) ;
}
return 0 ;
}
