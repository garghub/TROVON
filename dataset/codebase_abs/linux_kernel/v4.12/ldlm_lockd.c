void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( V_6 , L_1 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 ) ;
if ( F_5 ( V_6 ) )
F_6 ( V_6 ) ;
V_7 = ! V_6 -> V_8 && ! V_6 -> V_9 ;
F_7 ( V_6 ) ;
if ( V_7 ) {
F_8 ( V_10 ,
L_2 , V_6 ,
V_6 -> V_11 ) ;
if ( V_6 -> V_11 )
V_6 -> V_11 ( V_6 , V_4 , V_6 -> V_12 ,
V_13 ) ;
} else {
F_8 ( V_10 ,
L_3 ,
V_6 ) ;
}
F_2 ( V_6 , L_4 ) ;
F_9 ( V_6 ) ;
}
static void F_10 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_5 * V_6 )
{
int V_18 ;
F_11 ( V_19 ) ;
int V_20 = 0 ;
F_2 ( V_6 , L_5 ) ;
if ( F_12 ( V_21 ) ) {
int V_22 = F_13 ( 1 ) ;
while ( V_22 > 0 ) {
F_14 ( V_23 ) ;
F_15 ( V_22 ) ;
if ( V_6 -> V_24 == V_6 -> V_25 ||
F_16 ( V_6 ) )
break;
}
}
V_18 = F_17 ( & V_15 -> V_26 , & V_27 , V_28 ) ;
if ( V_18 < 0 ) {
F_18 ( V_6 , L_6 , V_18 ) ;
V_20 = V_18 ;
goto V_29;
} else if ( V_18 > 0 ) {
if ( V_6 -> V_30 > 0 ) {
F_19 ( V_6 -> V_31 ) ;
if ( F_20 ( V_6 -> V_30 < V_18 ) ) {
F_18 ( V_6 , L_7 ,
V_6 -> V_30 , V_18 ) ;
V_20 = - V_32 ;
goto V_29;
}
} else if ( F_21 ( V_6 ) ) {
void * V_33 ;
V_33 = F_22 ( V_18 , V_34 ) ;
if ( ! V_33 ) {
F_18 ( V_6 , L_8 , V_18 ) ;
V_20 = - V_35 ;
goto V_29;
}
F_3 ( V_6 ) ;
F_19 ( ! V_6 -> V_31 ) ;
V_6 -> V_36 = V_37 ;
V_6 -> V_31 = V_33 ;
V_6 -> V_30 = V_18 ;
F_7 ( V_6 ) ;
}
}
F_3 ( V_6 ) ;
if ( F_16 ( V_6 ) ||
V_6 -> V_24 == V_6 -> V_25 ) {
F_7 ( V_6 ) ;
F_2 ( V_6 , L_9 ) ;
V_20 = 0 ;
goto V_29;
}
if ( V_17 -> V_38 . V_24 != V_6 -> V_25 ) {
V_6 -> V_25 = V_17 -> V_38 . V_24 ;
F_2 ( V_6 , L_10 ) ;
}
if ( V_6 -> V_39 -> V_40 != V_41 ) {
F_23 ( V_15 -> V_42 ,
V_17 -> V_38 . V_39 . V_40 ,
& V_17 -> V_38 . V_43 ,
& V_6 -> V_43 ) ;
F_2 ( V_6 , L_11 ) ;
}
F_24 ( V_6 ) ;
if ( memcmp ( & V_17 -> V_38 . V_39 . V_44 ,
& V_6 -> V_39 -> V_44 ,
sizeof( V_6 -> V_39 -> V_44 ) ) != 0 ) {
F_7 ( V_6 ) ;
V_20 = F_25 ( V_2 , V_6 ,
& V_17 -> V_38 . V_39 . V_44 ) ;
if ( V_20 < 0 ) {
F_18 ( V_6 , L_12 ) ;
goto V_29;
}
F_2 ( V_6 , L_13 ) ;
F_26 ( L_14 ) ;
F_3 ( V_6 ) ;
}
if ( V_17 -> V_45 & V_46 ) {
F_27 ( V_6 ) ;
V_6 -> V_47 |= V_48 | V_49 ;
F_2 ( V_6 , L_15 ) ;
}
if ( V_6 -> V_30 > 0 ) {
V_20 = F_28 ( V_6 , & V_15 -> V_26 , V_28 ,
V_6 -> V_31 , V_18 ) ;
if ( V_20 < 0 ) {
F_7 ( V_6 ) ;
goto V_29;
}
}
F_29 ( V_6 , & V_19 ) ;
F_7 ( V_6 ) ;
F_2 ( V_6 , L_16 ) ;
F_30 ( V_50 , 2 ) ;
F_31 ( V_2 , & V_19 , V_51 ) ;
F_32 ( L_17 ,
V_6 ) ;
goto V_29;
V_29:
if ( V_20 < 0 ) {
F_3 ( V_6 ) ;
F_33 ( V_6 ) ;
F_7 ( V_6 ) ;
F_34 ( & V_6 -> V_52 ) ;
}
F_9 ( V_6 ) ;
}
static void F_35 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_5 * V_6 )
{
int V_20 = - V_53 ;
F_2 ( V_6 , L_18 ) ;
if ( V_6 -> V_54 )
V_20 = V_6 -> V_54 ( V_6 , V_15 ) ;
if ( V_15 -> V_55 ) {
F_36 ( V_15 ) ;
} else {
V_15 -> V_56 = V_20 ;
F_37 ( V_15 ) ;
}
F_3 ( V_6 ) ;
if ( V_6 -> V_24 == V_57 &&
! V_6 -> V_8 && ! V_6 -> V_9 &&
F_38 ( F_39 () ,
F_40 ( V_6 -> V_58 ,
F_13 ( 10 ) ) ) ) {
F_7 ( V_6 ) ;
if ( F_41 ( V_2 , NULL , V_6 ) )
F_1 ( V_2 , NULL , V_6 ) ;
return;
}
F_7 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static int F_42 ( struct V_14 * V_15 , int V_20 )
{
if ( V_15 -> V_59 )
return 0 ;
V_15 -> V_56 = V_20 ;
if ( ! V_15 -> V_60 ) {
V_20 = F_43 ( V_15 , 1 , NULL , NULL ) ;
if ( V_20 )
return V_20 ;
}
return F_36 ( V_15 ) ;
}
static int F_44 ( struct V_61 * V_62 ,
enum V_63 V_64 )
{
struct V_65 * V_66 = V_67 -> V_65 ;
F_45 ( & V_66 -> V_68 ) ;
if ( V_62 -> V_69 && F_46 ( V_62 -> V_69 ) ) {
F_47 ( & V_62 -> V_70 , & V_66 -> V_71 ) ;
} else {
F_47 ( & V_62 -> V_70 , & V_66 -> V_72 ) ;
}
F_48 ( & V_66 -> V_68 ) ;
F_34 ( & V_66 -> V_73 ) ;
if ( ! ( V_64 & V_74 ) )
F_49 ( & V_62 -> V_75 ) ;
return 0 ;
}
static inline void F_50 ( struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_76 * V_77 , int V_78 ,
struct V_5 * V_6 ,
enum V_63 V_64 )
{
F_51 ( & V_62 -> V_75 ) ;
F_52 ( & V_62 -> V_79 ) ;
if ( F_53 () )
V_62 -> V_80 = 1 ;
V_62 -> V_81 = V_2 ;
V_62 -> V_82 = V_64 ;
if ( V_4 )
V_62 -> V_83 = * V_4 ;
if ( V_78 ) {
F_54 ( & V_62 -> V_79 , V_77 ) ;
F_55 ( V_77 ) ;
V_62 -> V_84 = V_78 ;
} else {
V_62 -> V_69 = V_6 ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_76 * V_77 , int V_78 ,
enum V_63 V_64 )
{
if ( V_77 && V_78 == 0 )
return 0 ;
if ( V_64 & V_74 ) {
struct V_61 * V_62 ;
V_62 = F_22 ( sizeof( * V_62 ) , V_34 ) ;
if ( ! V_62 )
return - V_35 ;
F_50 ( V_62 , V_2 , V_4 , V_77 , V_78 , V_6 , V_64 ) ;
return F_44 ( V_62 , V_64 ) ;
} else {
struct V_61 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
F_50 ( & V_62 , V_2 , V_4 , V_77 , V_78 , V_6 , V_64 ) ;
return F_44 ( & V_62 , V_64 ) ;
}
}
int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return F_56 ( V_2 , V_4 , V_6 , NULL , 0 , V_74 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_76 * V_77 , int V_78 ,
enum V_63 V_64 )
{
return F_56 ( V_2 , V_4 , NULL , V_77 , V_78 , V_64 ) ;
}
int F_58 ( void )
{
F_34 ( & V_67 -> V_65 -> V_73 ) ;
return 0 ;
}
static int F_59 ( struct V_14 * V_15 )
{
struct V_85 * V_86 = V_15 -> V_42 -> V_87 ;
char * V_88 ;
void * V_89 ;
int V_90 , V_91 ;
int V_20 = - V_53 ;
F_60 ( V_92 , V_15 , L_19 , V_86 -> V_93 ) ;
F_61 ( & V_15 -> V_26 , & V_94 ) ;
V_88 = F_62 ( & V_15 -> V_26 , & V_95 ) ;
if ( ! V_88 ) {
F_60 ( V_96 , V_15 , L_20 ) ;
return - V_97 ;
}
V_90 = F_17 ( & V_15 -> V_26 , & V_95 ,
V_28 ) ;
V_89 = F_62 ( & V_15 -> V_26 , & V_98 ) ;
if ( ! V_89 ) {
F_60 ( V_96 , V_15 , L_21 ) ;
return - V_97 ;
}
V_91 = F_17 ( & V_15 -> V_26 , & V_98 ,
V_28 ) ;
if ( F_63 ( V_99 ) )
V_20 = F_64 ( V_15 -> V_100 -> V_101 ,
V_15 -> V_42 ,
sizeof( V_99 ) ,
V_99 ,
V_91 , V_89 , NULL ) ;
else
F_60 ( V_102 , V_15 , L_22 , V_88 ) ;
return V_20 ;
}
static inline void F_65 ( struct V_14 * V_15 ,
const char * V_103 , int V_20 ,
const struct V_104 * V_105 )
{
F_60 ( ( V_15 -> V_59 || V_20 ) ? V_102 : V_10 , V_15 ,
L_23 ,
V_103 , F_66 ( V_15 -> V_106 ) , V_20 ,
V_105 ? V_105 -> V_107 : 0 ) ;
if ( V_15 -> V_59 )
F_67 ( L_24 ) ;
else if ( V_20 )
F_67 ( L_25 ) ;
}
static int F_68 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_5 * V_6 ;
int V_20 ;
if ( F_69 ( V_15 -> V_108 ) == V_109 )
return 0 ;
F_70 ( & V_15 -> V_26 , V_15 , V_110 ) ;
if ( ! V_15 -> V_42 ) {
V_20 = F_42 ( V_15 , - V_111 ) ;
F_65 ( V_15 , L_26 ,
V_20 , NULL ) ;
return 0 ;
}
F_19 ( V_15 -> V_42 -> V_87 ) ;
switch ( F_69 ( V_15 -> V_108 ) ) {
case V_112 :
if ( F_12 ( V_113 ) ) {
if ( V_114 )
F_42 ( V_15 , - ( int ) V_114 ) ;
return 0 ;
}
break;
case V_115 :
if ( F_12 ( V_116 ) )
return 0 ;
break;
case V_117 :
if ( F_12 ( V_118 ) )
return 0 ;
break;
case V_119 :
V_20 = F_59 ( V_15 ) ;
F_42 ( V_15 , V_20 ) ;
return 0 ;
default:
F_26 ( L_27 ,
F_69 ( V_15 -> V_108 ) ) ;
F_42 ( V_15 , - V_120 ) ;
return 0 ;
}
V_2 = V_15 -> V_42 -> V_87 -> V_121 ;
F_19 ( V_2 ) ;
F_61 ( & V_15 -> V_26 , & V_122 ) ;
V_17 = F_62 ( & V_15 -> V_26 , & V_123 ) ;
if ( ! V_17 ) {
V_20 = F_42 ( V_15 , - V_120 ) ;
F_65 ( V_15 , L_28 , V_20 ,
NULL ) ;
return 0 ;
}
if ( F_12 ( V_21 ) &&
F_69 ( V_15 -> V_108 ) == V_112 ) {
V_20 = F_71 ( & V_17 -> V_124 [ 0 ] , 0 ) ;
if ( V_20 < 0 )
F_26 ( L_29 , V_20 ) ;
}
V_6 = F_72 ( & V_17 -> V_124 [ 0 ] , 0 ) ;
if ( ! V_6 ) {
F_8 ( V_10 , L_30 ,
V_17 -> V_124 [ 0 ] . V_107 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_65 ( V_15 , L_31 , V_20 ,
& V_17 -> V_124 [ 0 ] ) ;
return 0 ;
}
if ( F_73 ( V_6 ) &&
F_69 ( V_15 -> V_108 ) == V_112 )
F_74 ( V_125 ) ;
F_3 ( V_6 ) ;
V_6 -> V_47 |= F_75 ( V_17 -> V_45 &
V_126 ) ;
if ( F_69 ( V_15 -> V_108 ) == V_112 ) {
if ( ( F_76 ( V_6 ) && F_77 ( V_6 ) ) ||
F_78 ( V_6 ) ) {
F_2 ( V_6 ,
L_32 ,
V_17 -> V_124 [ 0 ] . V_107 ) ;
F_7 ( V_6 ) ;
F_9 ( V_6 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_65 ( V_15 , L_33 , V_20 ,
& V_17 -> V_124 [ 0 ] ) ;
return 0 ;
}
F_27 ( V_6 ) ;
F_79 ( V_6 ) ;
}
F_7 ( V_6 ) ;
switch ( F_69 ( V_15 -> V_108 ) ) {
case V_112 :
F_8 ( V_127 , L_34 ) ;
F_80 ( & V_15 -> V_26 , & V_128 ) ;
if ( ! F_5 ( V_6 ) ) {
V_20 = F_42 ( V_15 , 0 ) ;
if ( V_15 -> V_59 || V_20 )
F_65 ( V_15 , L_35 , V_20 ,
& V_17 -> V_124 [ 0 ] ) ;
}
if ( F_41 ( V_2 , & V_17 -> V_38 , V_6 ) )
F_1 ( V_2 , & V_17 -> V_38 , V_6 ) ;
break;
case V_115 :
F_8 ( V_127 , L_36 ) ;
F_80 ( & V_15 -> V_26 , & V_129 ) ;
F_42 ( V_15 , 0 ) ;
F_10 ( V_15 , V_2 , V_17 , V_6 ) ;
break;
case V_117 :
F_8 ( V_127 , L_37 ) ;
F_80 ( & V_15 -> V_26 , & V_130 ) ;
F_35 ( V_15 , V_2 , V_17 , V_6 ) ;
break;
default:
F_81 () ;
}
return 0 ;
}
static int F_82 ( struct V_65 * V_66 ,
struct V_61 * * V_131 ,
struct V_132 * * V_133 )
{
int V_134 = F_83 ( & V_66 -> V_135 ) ;
struct V_61 * V_62 = NULL ;
static unsigned int V_136 ;
F_45 ( & V_66 -> V_68 ) ;
if ( ! F_84 ( & V_66 -> V_72 ) &&
( F_84 ( & V_66 -> V_71 ) || V_136 == 0 ) )
V_62 = F_85 ( V_66 -> V_72 . V_137 ,
struct V_61 , V_70 ) ;
else
if ( ! F_84 ( & V_66 -> V_71 ) )
V_62 = F_85 ( V_66 -> V_71 . V_137 ,
struct V_61 ,
V_70 ) ;
if ( V_62 ) {
if ( ++ V_136 >= V_134 )
V_136 = 0 ;
F_86 ( & V_62 -> V_70 ) ;
}
F_48 ( & V_66 -> V_68 ) ;
* V_131 = V_62 ;
return ( * V_131 || * V_133 ) ? 1 : 0 ;
}
static int F_87 ( struct V_65 * V_66 , bool V_138 )
{
struct V_139 V_140 = { . V_141 = V_66 } ;
struct V_142 * V_143 ;
F_51 ( & V_140 . V_144 ) ;
V_140 . V_145 = F_88 ( & V_66 -> V_135 ) ;
if ( V_140 . V_145 >= V_66 -> V_146 ) {
F_89 ( & V_66 -> V_135 ) ;
return 0 ;
}
F_90 ( V_140 . V_145 > 0 , L_38 , V_140 . V_145 ) ;
if ( V_138 &&
F_83 ( & V_66 -> V_147 ) < ( V_140 . V_145 - 1 ) ) {
F_89 ( & V_66 -> V_135 ) ;
return 0 ;
}
V_143 = F_91 ( V_148 , & V_140 , L_39 ,
V_140 . V_145 ) ;
if ( F_92 ( V_143 ) ) {
F_26 ( L_40 ,
V_140 . V_145 , F_93 ( V_143 ) ) ;
F_89 ( & V_66 -> V_135 ) ;
return F_93 ( V_143 ) ;
}
F_49 ( & V_140 . V_144 ) ;
return 0 ;
}
static int F_94 ( struct V_65 * V_66 ,
struct V_61 * V_62 )
{
if ( F_83 ( & V_66 -> V_135 ) >= V_66 -> V_146 )
return 0 ;
if ( F_83 ( & V_66 -> V_147 ) <
F_83 ( & V_66 -> V_135 ) )
return 0 ;
if ( V_62 && ( ! V_62 -> V_81 || V_62 -> V_80 ) )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_65 * V_66 ,
struct V_61 * V_62 )
{
if ( ! V_62 -> V_81 )
return V_149 ;
if ( V_62 -> V_80 )
F_96 () ;
F_30 ( V_150 , 4 ) ;
if ( V_62 -> V_84 ) {
int V_78 ;
V_78 = F_97 ( & V_62 -> V_79 ,
V_62 -> V_84 ,
V_151 ) ;
F_98 ( & V_62 -> V_79 , V_78 , NULL ,
V_62 -> V_82 ) ;
} else {
F_1 ( V_62 -> V_81 , & V_62 -> V_83 ,
V_62 -> V_69 ) ;
}
if ( V_62 -> V_80 )
F_99 () ;
if ( V_62 -> V_82 & V_74 )
F_100 ( V_62 ) ;
else
F_101 ( & V_62 -> V_75 ) ;
return 0 ;
}
static int V_148 ( void * V_152 )
{
struct V_65 * V_66 ;
struct V_139 * V_140 = V_152 ;
V_66 = V_140 -> V_141 ;
F_101 ( & V_140 -> V_144 ) ;
while ( 1 ) {
struct V_153 V_154 = { 0 } ;
struct V_61 * V_62 = NULL ;
struct V_132 * exp = NULL ;
int V_20 ;
V_20 = F_82 ( V_66 , & V_62 , & exp ) ;
if ( ! V_20 )
F_102 ( V_66 -> V_73 ,
F_82 ( V_66 , & V_62 ,
& exp ) ,
& V_154 ) ;
F_103 ( & V_66 -> V_147 ) ;
if ( F_94 ( V_66 , V_62 ) )
F_87 ( V_66 , true ) ;
if ( V_62 )
V_20 = F_95 ( V_66 , V_62 ) ;
F_89 ( & V_66 -> V_147 ) ;
if ( V_20 == V_149 )
break;
}
F_89 ( & V_66 -> V_135 ) ;
F_101 ( & V_66 -> V_155 ) ;
return 0 ;
}
int F_104 ( void )
{
int V_20 = 0 ;
F_105 ( & V_156 ) ;
if ( ++ V_157 == 1 ) {
V_20 = F_106 () ;
if ( V_20 )
V_157 -- ;
}
F_107 ( & V_156 ) ;
return V_20 ;
}
void F_108 ( void )
{
F_105 ( & V_156 ) ;
if ( V_157 == 1 ) {
int V_20 = F_109 () ;
if ( V_20 )
F_26 ( L_41 , V_20 ) ;
else
V_157 -- ;
} else {
V_157 -- ;
}
F_107 ( & V_156 ) ;
}
static T_1 F_110 ( struct V_158 * V_159 ,
struct V_160 * V_161 ,
char * V_162 )
{
return sprintf ( V_162 , L_42 , V_163 ) ;
}
static T_1 F_111 ( struct V_158 * V_159 ,
struct V_160 * V_161 ,
const char * V_164 ,
T_2 V_78 )
{
int V_20 ;
unsigned long V_89 ;
V_20 = F_112 ( V_164 , 10 , & V_89 ) ;
if ( V_20 )
return V_20 ;
V_163 = V_89 ;
return V_78 ;
}
static int F_106 ( void )
{
static struct V_165 V_166 ;
struct V_65 * V_66 = NULL ;
int V_20 = 0 ;
int V_167 ;
if ( V_67 )
return - V_168 ;
V_67 = F_22 ( sizeof( * V_67 ) , V_34 ) ;
if ( ! V_67 )
return - V_35 ;
V_169 = F_113 ( L_43 , V_170 ) ;
if ( ! V_169 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_114 ( V_169 , & V_171 ) ;
if ( V_20 )
goto V_29;
V_172 = F_115 ( L_44 , NULL , V_169 ) ;
if ( ! V_172 ) {
V_20 = - V_35 ;
goto V_29;
}
V_173 = F_115 ( L_45 , NULL , V_169 ) ;
if ( ! V_173 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_116 () ;
if ( V_20 != 0 )
goto V_29;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 = ( F_117 ( V_166 ) ) {
. V_174 = L_46 ,
. V_175 = 2 ,
. V_176 = {
. V_177 = V_178 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. V_183 = V_184 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
} ,
. V_189 = {
. V_190 = L_47 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = V_196 ,
. V_197 = V_198 ,
. V_199 = V_200 ,
. V_201 = 1 ,
. V_202 = V_203 | V_204 ,
} ,
. V_205 = {
. V_206 = V_207 ,
} ,
. V_208 = {
. V_209 = F_68 ,
} ,
} ;
V_67 -> V_210 =
F_118 ( & V_166 , V_173 ,
V_211 ) ;
if ( F_92 ( V_67 -> V_210 ) ) {
F_26 ( L_48 ) ;
V_20 = F_93 ( V_67 -> V_210 ) ;
V_67 -> V_210 = NULL ;
goto V_29;
}
V_66 = F_22 ( sizeof( * V_66 ) , V_34 ) ;
if ( ! V_66 ) {
V_20 = - V_35 ;
goto V_29;
}
V_67 -> V_65 = V_66 ;
F_119 ( & V_66 -> V_68 ) ;
F_52 ( & V_66 -> V_72 ) ;
F_52 ( & V_66 -> V_71 ) ;
F_120 ( & V_66 -> V_73 ) ;
F_121 ( & V_66 -> V_135 , 0 ) ;
F_121 ( & V_66 -> V_147 , 0 ) ;
if ( V_200 == 0 ) {
V_66 -> V_212 = V_194 ;
V_66 -> V_146 = V_198 ;
} else {
V_66 -> V_212 = F_122 ( int , V_198 ,
F_123 ( int , V_194 ,
V_200 ) ) ;
V_66 -> V_146 = V_66 -> V_212 ;
}
for ( V_167 = 0 ; V_167 < V_66 -> V_212 ; V_167 ++ ) {
V_20 = F_87 ( V_66 , false ) ;
if ( V_20 < 0 )
goto V_29;
}
V_20 = F_124 () ;
if ( V_20 ) {
F_26 ( L_49 , V_20 ) ;
goto V_29;
}
return 0 ;
V_29:
F_109 () ;
return V_20 ;
}
static int F_109 ( void )
{
if ( ! F_84 ( F_125 ( V_213 ) ) ||
! F_84 ( F_125 ( V_214 ) ) ) {
F_26 ( L_50 ) ;
F_126 ( V_213 , V_10 ) ;
F_126 ( V_214 , V_10 ) ;
return - V_215 ;
}
F_127 () ;
if ( V_67 -> V_65 ) {
struct V_65 * V_66 = V_67 -> V_65 ;
while ( F_83 ( & V_66 -> V_135 ) > 0 ) {
struct V_61 V_62 = { . V_81 = NULL } ;
F_51 ( & V_66 -> V_155 ) ;
F_45 ( & V_66 -> V_68 ) ;
F_47 ( & V_62 . V_70 , & V_66 -> V_72 ) ;
F_34 ( & V_66 -> V_73 ) ;
F_48 ( & V_66 -> V_68 ) ;
F_49 ( & V_66 -> V_155 ) ;
}
F_100 ( V_66 ) ;
}
if ( V_67 -> V_210 )
F_128 ( V_67 -> V_210 ) ;
if ( V_172 )
F_129 ( V_172 ) ;
if ( V_173 )
F_129 ( V_173 ) ;
if ( V_169 )
F_130 ( V_169 ) ;
F_131 () ;
F_100 ( V_67 ) ;
V_67 = NULL ;
return 0 ;
}
int F_132 ( void )
{
F_133 ( & V_156 ) ;
F_133 ( F_134 ( V_213 ) ) ;
F_133 ( F_134 ( V_214 ) ) ;
V_216 = F_135 ( L_51 ,
sizeof( struct V_217 ) , 0 ,
V_218 , NULL ) ;
if ( ! V_216 )
return - V_35 ;
V_219 = F_135 ( L_52 ,
sizeof( struct V_5 ) , 0 ,
V_218 |
V_220 , NULL ) ;
if ( ! V_219 ) {
F_136 ( V_216 ) ;
return - V_35 ;
}
V_221 = F_135 ( L_53 ,
sizeof( struct V_222 ) ,
0 , V_218 , NULL ) ;
if ( ! V_221 ) {
F_136 ( V_216 ) ;
F_136 ( V_219 ) ;
return - V_35 ;
}
#if V_223
V_224 = V_225 ;
#endif
return 0 ;
}
void F_137 ( void )
{
if ( V_157 )
F_26 ( L_54 , V_157 ) ;
F_136 ( V_216 ) ;
F_138 () ;
F_136 ( V_219 ) ;
F_136 ( V_221 ) ;
}
