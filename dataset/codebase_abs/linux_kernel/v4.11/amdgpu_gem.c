void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 ) {
if ( V_4 -> V_5 . V_6 )
F_3 ( & V_4 -> V_5 , V_4 -> V_7 . V_8 ) ;
F_4 ( V_4 ) ;
F_5 ( & V_4 ) ;
}
}
int F_6 ( struct V_9 * V_10 , unsigned long V_11 ,
int V_12 , T_1 V_13 ,
T_2 V_14 , bool V_15 ,
struct V_1 * * V_16 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_18 ;
* V_16 = NULL ;
if ( V_12 < V_19 ) {
V_12 = V_19 ;
}
if ( ! ( V_13 & ( V_20 | V_21 | V_22 ) ) ) {
V_17 = V_10 -> V_23 . V_24 - V_10 -> V_25 ;
if ( V_11 > V_17 ) {
F_7 ( L_1 ,
V_11 >> 20 , V_17 >> 20 ) ;
return - V_26 ;
}
}
V_27:
V_18 = F_8 ( V_10 , V_11 , V_12 , V_15 , V_13 ,
V_14 , NULL , NULL , & V_4 ) ;
if ( V_18 ) {
if ( V_18 != - V_28 ) {
if ( V_13 == V_29 ) {
V_13 |= V_30 ;
goto V_27;
}
F_9 ( L_2 ,
V_11 , V_13 , V_12 , V_18 ) ;
}
return V_18 ;
}
* V_16 = & V_4 -> V_5 ;
return 0 ;
}
void F_10 ( struct V_9 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_33 * V_34 ;
F_11 ( & V_32 -> V_35 ) ;
F_12 (file, &ddev->filelist, lhead) {
struct V_1 * V_2 ;
int V_36 ;
F_13 ( 1 , L_3 ) ;
F_14 ( & V_34 -> V_37 ) ;
F_15 (&file->object_idr, gobj, handle) {
F_13 ( 1 , L_4 ) ;
F_16 ( V_2 ) ;
}
F_17 ( & V_34 -> V_38 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_32 -> V_35 ) ;
}
int F_20 ( struct V_1 * V_16 ,
struct V_33 * V_39 )
{
struct V_3 * V_40 = F_2 ( V_16 ) ;
struct V_9 * V_10 = F_21 ( V_40 -> V_7 . V_41 ) ;
struct V_42 * V_43 = V_39 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_47 * V_48 ;
int V_18 ;
V_18 = F_22 ( V_40 , false ) ;
if ( V_18 )
return V_18 ;
V_48 = F_23 ( V_46 , V_40 ) ;
if ( ! V_48 ) {
V_48 = F_24 ( V_10 , V_46 , V_40 ) ;
} else {
++ V_48 -> V_49 ;
}
F_25 ( V_40 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_16 ,
struct V_33 * V_39 )
{
struct V_3 * V_50 = F_2 ( V_16 ) ;
struct V_9 * V_10 = F_21 ( V_50 -> V_7 . V_41 ) ;
struct V_42 * V_43 = V_39 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_51 V_52 ;
struct V_53 V_54 , V_55 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_47 * V_48 ;
int V_18 ;
F_27 ( & V_54 ) ;
F_27 ( & V_55 ) ;
V_57 . V_50 = & V_50 -> V_7 ;
V_57 . V_60 = true ;
F_28 ( & V_57 . V_61 , & V_54 ) ;
F_29 ( V_46 , & V_54 , & V_52 ) ;
V_18 = F_30 ( & V_59 , & V_54 , false , & V_55 ) ;
if ( V_18 ) {
F_31 ( V_10 -> V_62 , L_5
L_6 , V_18 ) ;
return;
}
V_48 = F_23 ( V_46 , V_50 ) ;
if ( V_48 ) {
if ( -- V_48 -> V_49 == 0 ) {
F_32 ( V_10 , V_48 ) ;
}
}
F_33 ( & V_59 , & V_54 ) ;
}
static int F_34 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_63 ) {
V_18 = F_35 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_64 ;
}
return V_18 ;
}
int F_36 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_9 * V_10 = V_62 -> V_67 ;
union V_68 * args = V_65 ;
T_3 V_11 = args -> V_69 . V_70 ;
struct V_1 * V_2 ;
T_4 V_36 ;
bool V_15 = false ;
int V_18 ;
if ( args -> V_69 . V_71 & ~ ( V_72 |
V_73 |
V_74 |
V_75 |
V_76 |
V_77 ) ) {
V_18 = - V_78 ;
goto V_79;
}
if ( args -> V_69 . V_80 & ~ ( V_81 |
V_30 |
V_29 |
V_20 |
V_21 |
V_22 ) ) {
V_18 = - V_78 ;
goto V_79;
}
if ( args -> V_69 . V_80 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_69 . V_80 == V_20 )
V_11 = V_11 << V_82 ;
else if ( args -> V_69 . V_80 == V_21 )
V_11 = V_11 << V_83 ;
else if ( args -> V_69 . V_80 == V_22 )
V_11 = V_11 << V_84 ;
else {
V_18 = - V_78 ;
goto V_79;
}
}
V_11 = F_37 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_69 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_69 . V_80 ) ,
args -> V_69 . V_71 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_79;
V_18 = F_38 ( V_66 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_79;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_85 . V_36 = V_36 ;
return 0 ;
V_79:
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_39 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_86 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_50 ;
T_4 V_36 ;
int V_18 ;
if ( F_40 ( args -> V_87 | args -> V_11 ) )
return - V_78 ;
if ( args -> V_14 & ~ ( V_88 |
V_89 | V_90 |
V_91 ) )
return - V_78 ;
if ( ! ( args -> V_14 & V_88 ) &&
! ( args -> V_14 & V_91 ) ) {
return - V_92 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_81 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_93;
V_50 = F_2 ( V_2 ) ;
V_50 -> V_94 = V_30 ;
V_50 -> V_95 = V_30 ;
V_18 = F_41 ( V_50 -> V_7 . V_96 , args -> V_87 , args -> V_14 ) ;
if ( V_18 )
goto V_97;
if ( args -> V_14 & V_91 ) {
V_18 = F_42 ( V_50 , args -> V_87 ) ;
if ( V_18 )
goto V_97;
}
if ( args -> V_14 & V_90 ) {
F_43 ( & V_98 -> V_99 -> V_100 ) ;
V_18 = F_44 ( V_50 -> V_7 . V_96 ,
V_50 -> V_7 . V_96 -> V_101 ) ;
if ( V_18 )
goto V_102;
V_18 = F_22 ( V_50 , true ) ;
if ( V_18 )
goto V_103;
F_45 ( V_50 , V_30 ) ;
V_18 = F_46 ( & V_50 -> V_7 , & V_50 -> V_104 , true , false ) ;
F_25 ( V_50 ) ;
if ( V_18 )
goto V_103;
F_47 ( & V_98 -> V_99 -> V_100 ) ;
}
V_18 = F_38 ( V_66 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_93;
args -> V_36 = V_36 ;
return 0 ;
V_103:
F_48 ( V_50 -> V_7 . V_96 -> V_101 , V_50 -> V_7 . V_96 -> V_105 , false ) ;
V_102:
F_47 ( & V_98 -> V_99 -> V_100 ) ;
V_97:
F_16 ( V_2 ) ;
V_93:
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_49 ( struct V_33 * V_66 ,
struct V_31 * V_62 ,
T_4 V_36 , T_3 * V_106 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_50 ( V_66 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_51 ( V_4 -> V_7 . V_96 ) ||
( V_4 -> V_14 & V_73 ) ) {
F_16 ( V_2 ) ;
return - V_108 ;
}
* V_106 = F_52 ( V_4 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
union V_109 * args = V_65 ;
T_4 V_36 = args -> V_69 . V_36 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_49 ( V_66 , V_62 , V_36 , & args -> V_85 . V_110 ) ;
}
unsigned long F_54 ( T_3 V_111 )
{
unsigned long V_112 ;
T_5 V_113 ;
if ( ( ( V_114 ) V_111 ) < 0 )
return V_115 ;
V_113 = F_55 ( F_56 ( V_111 ) , F_57 () ) ;
if ( F_58 ( V_113 ) < 0 )
return 0 ;
V_112 = F_59 ( F_58 ( V_113 ) ) ;
if ( V_112 > V_115 )
return V_115 - 1 ;
return V_112 ;
}
int F_60 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_9 * V_10 = V_62 -> V_67 ;
union V_116 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_36 = args -> V_69 . V_36 ;
unsigned long V_113 = F_54 ( args -> V_69 . V_113 ) ;
int V_18 = 0 ;
long V_117 ;
V_2 = F_50 ( V_66 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
V_117 = F_61 ( V_4 -> V_7 . V_118 , true , true ,
V_113 ) ;
if ( V_117 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_85 . V_119 = ( V_117 == 0 ) ;
} else
V_18 = V_117 ;
F_16 ( V_2 ) ;
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_62 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_120 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_7 , args -> V_36 ) ;
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_107 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_63 ( V_18 != 0 ) )
goto V_85;
if ( args -> V_121 == V_122 ) {
F_64 ( V_4 , & args -> V_65 . V_123 ) ;
V_18 = F_65 ( V_4 , args -> V_65 . V_65 ,
sizeof( args -> V_65 . V_65 ) ,
& args -> V_65 . V_124 ,
& args -> V_65 . V_14 ) ;
} else if ( args -> V_121 == V_125 ) {
if ( args -> V_65 . V_124 > sizeof( args -> V_65 . V_65 ) ) {
V_18 = - V_78 ;
goto V_126;
}
V_18 = F_66 ( V_4 , args -> V_65 . V_123 ) ;
if ( ! V_18 )
V_18 = F_67 ( V_4 , args -> V_65 . V_65 ,
args -> V_65 . V_124 ,
args -> V_65 . V_14 ) ;
}
V_126:
F_25 ( V_4 ) ;
V_85:
F_16 ( V_2 ) ;
return V_18 ;
}
static int F_68 ( void * V_127 , struct V_3 * V_50 )
{
if ( ! F_69 ( V_50 ) )
return - V_28 ;
if ( V_50 -> V_128 && ! F_69 ( V_50 -> V_128 ) )
return - V_28 ;
return 0 ;
}
static void F_70 ( struct V_9 * V_10 ,
struct V_47 * V_48 ,
struct V_53 * V_54 ,
T_4 V_129 )
{
struct V_56 * V_130 ;
int V_18 = - V_28 ;
F_12 (entry, list, head) {
struct V_3 * V_50 =
F_71 ( V_130 -> V_50 , struct V_3 , V_7 ) ;
if ( F_68 ( NULL , V_50 ) )
goto error;
}
V_18 = F_72 ( V_10 , V_48 -> V_46 , F_68 ,
NULL ) ;
if ( V_18 )
goto error;
V_18 = F_73 ( V_10 , V_48 -> V_46 ) ;
if ( V_18 )
goto error;
V_18 = F_74 ( V_10 , V_48 -> V_46 ) ;
if ( V_18 )
goto error;
if ( V_129 == V_131 )
V_18 = F_75 ( V_10 , V_48 , false ) ;
error:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_8 , V_18 ) ;
}
int F_76 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_132 * args = V_65 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_42 * V_43 = V_66 -> V_44 ;
struct V_3 * V_40 ;
struct V_47 * V_48 ;
struct V_51 V_52 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_53 V_54 ;
T_4 V_133 , V_134 = 0 ;
int V_18 = 0 ;
if ( ! V_10 -> V_135 . V_136 )
return - V_137 ;
if ( args -> V_138 < V_139 ) {
F_31 ( & V_62 -> V_140 -> V_62 ,
L_9 ,
( unsigned long ) args -> V_138 ,
V_139 ) ;
return - V_78 ;
}
V_133 = ~ ( V_141 | V_142 |
V_143 | V_144 ) ;
if ( ( args -> V_14 & V_133 ) ) {
F_31 ( & V_62 -> V_140 -> V_62 , L_10 ,
args -> V_14 , V_133 ) ;
return - V_78 ;
}
switch ( args -> V_129 ) {
case V_131 :
case V_145 :
break;
default:
F_31 ( & V_62 -> V_140 -> V_62 , L_11 ,
args -> V_129 ) ;
return - V_78 ;
}
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_107 ;
V_40 = F_2 ( V_2 ) ;
F_27 ( & V_54 ) ;
V_57 . V_50 = & V_40 -> V_7 ;
V_57 . V_60 = false ;
F_28 ( & V_57 . V_61 , & V_54 ) ;
F_29 ( & V_43 -> V_46 , & V_54 , & V_52 ) ;
V_18 = F_30 ( & V_59 , & V_54 , true , NULL ) ;
if ( V_18 ) {
F_16 ( V_2 ) ;
return V_18 ;
}
V_48 = F_23 ( & V_43 -> V_46 , V_40 ) ;
if ( ! V_48 ) {
F_33 ( & V_59 , & V_54 ) ;
F_16 ( V_2 ) ;
return - V_107 ;
}
switch ( args -> V_129 ) {
case V_131 :
if ( args -> V_14 & V_142 )
V_134 |= V_146 ;
if ( args -> V_14 & V_143 )
V_134 |= V_147 ;
if ( args -> V_14 & V_144 )
V_134 |= V_148 ;
V_18 = F_77 ( V_10 , V_48 , args -> V_138 ,
args -> V_149 , args -> V_150 ,
V_134 ) ;
break;
case V_145 :
V_18 = F_78 ( V_10 , V_48 , args -> V_138 ) ;
break;
default:
break;
}
if ( ! V_18 && ! ( args -> V_14 & V_141 ) &&
! V_151 )
F_70 ( V_10 , V_48 , & V_54 , args -> V_129 ) ;
F_33 ( & V_59 , & V_54 ) ;
F_16 ( V_2 ) ;
return V_18 ;
}
int F_79 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_152 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_63 ( V_18 ) )
goto V_85;
switch ( args -> V_121 ) {
case V_153 : {
struct V_154 V_155 ;
void T_6 * V_85 = ( void T_6 * ) ( long ) args -> V_156 ;
V_155 . V_70 = V_4 -> V_5 . V_11 ;
V_155 . V_12 = V_4 -> V_7 . V_157 . V_158 << V_159 ;
V_155 . V_80 = V_4 -> V_94 ;
V_155 . V_71 = V_4 -> V_14 ;
F_25 ( V_4 ) ;
if ( F_80 ( V_85 , & V_155 , sizeof( V_155 ) ) )
V_18 = - V_160 ;
break;
}
case V_161 :
if ( F_51 ( V_4 -> V_7 . V_96 ) ) {
V_18 = - V_108 ;
F_25 ( V_4 ) ;
break;
}
V_4 -> V_94 = args -> V_156 & ( V_29 |
V_30 |
V_81 ) ;
V_4 -> V_95 = V_4 -> V_94 ;
if ( V_4 -> V_95 == V_29 )
V_4 -> V_95 |= V_30 ;
F_25 ( V_4 ) ;
break;
default:
F_25 ( V_4 ) ;
V_18 = - V_78 ;
}
V_85:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_81 ( struct V_33 * V_39 ,
struct V_31 * V_62 ,
struct V_162 * args )
{
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_1 * V_2 ;
T_4 V_36 ;
int V_18 ;
args -> V_163 = F_82 ( V_10 , args -> V_164 ,
F_83 ( args -> V_165 , 8 ) , 0 ) ;
args -> V_11 = ( T_2 ) args -> V_163 * args -> V_166 ;
args -> V_11 = F_84 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_72 ,
V_167 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_38 ( V_39 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_36 = V_36 ;
return 0 ;
}
static int F_85 ( int V_168 , void * V_169 , void * V_65 )
{
struct V_1 * V_2 = V_169 ;
struct V_3 * V_50 = F_2 ( V_2 ) ;
struct V_170 * V_171 = V_65 ;
unsigned V_172 ;
const char * V_104 ;
unsigned V_173 ;
V_172 = F_86 ( V_50 -> V_7 . V_157 . V_174 ) ;
switch ( V_172 ) {
case V_29 :
V_104 = L_12 ;
break;
case V_30 :
V_104 = L_13 ;
break;
case V_81 :
default:
V_104 = L_14 ;
break;
}
F_87 ( V_171 , L_15 ,
V_168 , F_88 ( V_50 ) , V_104 ,
F_89 ( V_50 ) ) ;
V_173 = F_90 ( V_50 -> V_173 ) ;
if ( V_173 )
F_87 ( V_171 , L_16 , V_173 ) ;
F_87 ( V_171 , L_17 ) ;
return 0 ;
}
static int F_91 ( struct V_170 * V_171 , void * V_65 )
{
struct V_175 * V_176 = (struct V_175 * ) V_171 -> V_177 ;
struct V_31 * V_62 = V_176 -> V_178 -> V_62 ;
struct V_33 * V_34 ;
int V_18 ;
V_18 = F_92 ( & V_62 -> V_35 ) ;
if ( V_18 )
return V_18 ;
F_12 (file, &dev->filelist, lhead) {
struct V_179 * V_180 ;
F_93 () ;
V_180 = F_94 ( V_34 -> V_181 , V_182 ) ;
F_87 ( V_171 , L_18 , F_95 ( V_34 -> V_181 ) ,
V_180 ? V_180 -> V_183 : L_19 ) ;
F_96 () ;
F_14 ( & V_34 -> V_37 ) ;
F_97 ( & V_34 -> V_38 , F_85 , V_171 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_62 -> V_35 ) ;
return 0 ;
}
int F_98 ( struct V_9 * V_10 )
{
#if F_99 ( V_184 )
return F_100 ( V_10 , V_185 , 1 ) ;
#endif
return 0 ;
}
