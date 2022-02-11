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
static int F_26 ( void * V_50 , struct V_3 * V_51 )
{
if ( ! F_27 ( V_51 ) )
return - V_28 ;
if ( V_51 -> V_52 && ! F_27 ( V_51 -> V_52 ) )
return - V_28 ;
return 0 ;
}
static bool F_28 ( struct V_9 * V_10 ,
struct V_45 * V_46 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
F_12 (entry, list, head) {
struct V_3 * V_51 =
F_29 ( V_56 -> V_51 , struct V_3 , V_7 ) ;
if ( F_26 ( NULL , V_51 ) )
return false ;
}
return ! F_30 ( V_10 , V_46 , F_26 , NULL ) ;
}
void F_31 ( struct V_1 * V_16 ,
struct V_33 * V_39 )
{
struct V_3 * V_51 = F_2 ( V_16 ) ;
struct V_9 * V_10 = F_21 ( V_51 -> V_7 . V_41 ) ;
struct V_42 * V_43 = V_39 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_57 V_58 ;
struct V_53 V_54 ;
struct V_55 V_59 ;
struct V_60 V_61 ;
struct V_47 * V_48 ;
int V_18 ;
F_32 ( & V_54 ) ;
V_59 . V_51 = & V_51 -> V_7 ;
V_59 . V_62 = true ;
F_33 ( & V_59 . V_63 , & V_54 ) ;
F_34 ( V_46 , & V_54 , & V_58 ) ;
V_18 = F_35 ( & V_61 , & V_54 , false , NULL ) ;
if ( V_18 ) {
F_36 ( V_10 -> V_64 , L_5
L_6 , V_18 ) ;
return;
}
V_48 = F_23 ( V_46 , V_51 ) ;
if ( V_48 && -- V_48 -> V_49 == 0 ) {
F_37 ( V_10 , V_48 ) ;
if ( F_28 ( V_10 , V_46 , & V_54 ) ) {
struct V_65 * V_66 = NULL ;
V_18 = F_38 ( V_10 , V_46 , & V_66 ) ;
if ( F_39 ( V_18 ) ) {
F_36 ( V_10 -> V_64 , L_7
L_8 , V_18 ) ;
}
if ( V_66 ) {
F_40 ( V_51 , V_66 , true ) ;
F_41 ( V_66 ) ;
}
}
}
F_42 ( & V_61 , & V_54 ) ;
}
int F_43 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
struct V_9 * V_10 = V_64 -> V_69 ;
union V_70 * args = V_67 ;
T_3 V_11 = args -> V_71 . V_72 ;
struct V_1 * V_2 ;
T_4 V_36 ;
bool V_15 = false ;
int V_18 ;
if ( args -> V_71 . V_73 & ~ ( V_74 |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 ) )
return - V_80 ;
if ( args -> V_71 . V_81 & ~ ( V_82 |
V_30 |
V_29 |
V_20 |
V_21 |
V_22 ) )
return - V_80 ;
if ( args -> V_71 . V_81 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_71 . V_81 == V_20 )
V_11 = V_11 << V_83 ;
else if ( args -> V_71 . V_81 == V_21 )
V_11 = V_11 << V_84 ;
else if ( args -> V_71 . V_81 == V_22 )
V_11 = V_11 << V_85 ;
else
return - V_80 ;
}
V_11 = F_44 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_71 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_71 . V_81 ) ,
args -> V_71 . V_73 ,
V_15 , & V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_45 ( V_68 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
return V_18 ;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_86 . V_36 = V_36 ;
return 0 ;
}
int F_46 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
struct V_9 * V_10 = V_64 -> V_69 ;
struct V_87 * args = V_67 ;
struct V_1 * V_2 ;
struct V_3 * V_51 ;
T_4 V_36 ;
int V_18 ;
if ( F_47 ( args -> V_88 | args -> V_11 ) )
return - V_80 ;
if ( args -> V_14 & ~ ( V_89 |
V_90 | V_91 |
V_92 ) )
return - V_80 ;
if ( ! ( args -> V_14 & V_89 ) &&
! ( args -> V_14 & V_92 ) ) {
return - V_93 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_82 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
return V_18 ;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_94 = V_30 ;
V_51 -> V_95 = V_30 ;
V_18 = F_48 ( V_51 -> V_7 . V_96 , args -> V_88 , args -> V_14 ) ;
if ( V_18 )
goto V_97;
if ( args -> V_14 & V_92 ) {
V_18 = F_49 ( V_51 , args -> V_88 ) ;
if ( V_18 )
goto V_97;
}
if ( args -> V_14 & V_91 ) {
F_50 ( & V_98 -> V_99 -> V_100 ) ;
V_18 = F_51 ( V_51 -> V_7 . V_96 ,
V_51 -> V_7 . V_96 -> V_101 ) ;
if ( V_18 )
goto V_102;
V_18 = F_22 ( V_51 , true ) ;
if ( V_18 )
goto V_103;
F_52 ( V_51 , V_30 ) ;
V_18 = F_53 ( & V_51 -> V_7 , & V_51 -> V_104 , true , false ) ;
F_25 ( V_51 ) ;
if ( V_18 )
goto V_103;
F_54 ( & V_98 -> V_99 -> V_100 ) ;
}
V_18 = F_45 ( V_68 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
return V_18 ;
args -> V_36 = V_36 ;
return 0 ;
V_103:
F_55 ( V_51 -> V_7 . V_96 -> V_101 , V_51 -> V_7 . V_96 -> V_105 , false ) ;
V_102:
F_54 ( & V_98 -> V_99 -> V_100 ) ;
V_97:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_56 ( struct V_33 * V_68 ,
struct V_31 * V_64 ,
T_4 V_36 , T_3 * V_106 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_57 ( V_68 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_58 ( V_4 -> V_7 . V_96 ) ||
( V_4 -> V_14 & V_75 ) ) {
F_16 ( V_2 ) ;
return - V_108 ;
}
* V_106 = F_59 ( V_4 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_60 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
union V_109 * args = V_67 ;
T_4 V_36 = args -> V_71 . V_36 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_56 ( V_68 , V_64 , V_36 , & args -> V_86 . V_110 ) ;
}
unsigned long F_61 ( T_3 V_111 )
{
unsigned long V_112 ;
T_5 V_113 ;
if ( ( ( V_114 ) V_111 ) < 0 )
return V_115 ;
V_113 = F_62 ( F_63 ( V_111 ) , F_64 () ) ;
if ( F_65 ( V_113 ) < 0 )
return 0 ;
V_112 = F_66 ( F_65 ( V_113 ) ) ;
if ( V_112 > V_115 )
return V_115 - 1 ;
return V_112 ;
}
int F_67 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
union V_116 * args = V_67 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_36 = args -> V_71 . V_36 ;
unsigned long V_113 = F_61 ( args -> V_71 . V_113 ) ;
int V_18 = 0 ;
long V_117 ;
V_2 = F_57 ( V_68 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
V_117 = F_68 ( V_4 -> V_7 . V_118 , true , true ,
V_113 ) ;
if ( V_117 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_86 . V_119 = ( V_117 == 0 ) ;
} else
V_18 = V_117 ;
F_16 ( V_2 ) ;
return V_18 ;
}
int F_69 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
struct V_120 * args = V_67 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_9 , args -> V_36 ) ;
V_2 = F_57 ( V_68 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_107 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_39 ( V_18 != 0 ) )
goto V_86;
if ( args -> V_121 == V_122 ) {
F_70 ( V_4 , & args -> V_67 . V_123 ) ;
V_18 = F_71 ( V_4 , args -> V_67 . V_67 ,
sizeof( args -> V_67 . V_67 ) ,
& args -> V_67 . V_124 ,
& args -> V_67 . V_14 ) ;
} else if ( args -> V_121 == V_125 ) {
if ( args -> V_67 . V_124 > sizeof( args -> V_67 . V_67 ) ) {
V_18 = - V_80 ;
goto V_126;
}
V_18 = F_72 ( V_4 , args -> V_67 . V_123 ) ;
if ( ! V_18 )
V_18 = F_73 ( V_4 , args -> V_67 . V_67 ,
args -> V_67 . V_124 ,
args -> V_67 . V_14 ) ;
}
V_126:
F_25 ( V_4 ) ;
V_86:
F_16 ( V_2 ) ;
return V_18 ;
}
static void F_74 ( struct V_9 * V_10 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_53 * V_54 ,
T_4 V_127 )
{
int V_18 = - V_28 ;
if ( ! F_28 ( V_10 , V_46 , V_54 ) )
goto error;
V_18 = F_75 ( V_10 , V_46 ) ;
if ( V_18 )
goto error;
V_18 = F_38 ( V_10 , V_46 , NULL ) ;
if ( V_18 )
goto error;
if ( V_127 == V_128 ||
V_127 == V_129 )
V_18 = F_76 ( V_10 , V_48 , false ) ;
error:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_10 , V_18 ) ;
}
int F_77 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
const T_4 V_130 = V_131 |
V_132 | V_133 |
V_134 | V_135 ;
const T_4 V_136 = V_131 |
V_137 ;
struct V_138 * args = V_67 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_64 -> V_69 ;
struct V_42 * V_43 = V_68 -> V_44 ;
struct V_3 * V_40 ;
struct V_47 * V_48 ;
struct V_57 V_58 ;
struct V_55 V_59 ;
struct V_60 V_61 ;
struct V_53 V_54 ;
T_3 V_139 ;
int V_18 = 0 ;
if ( args -> V_140 < V_141 ) {
F_36 ( & V_64 -> V_142 -> V_64 ,
L_11 ,
( unsigned long ) args -> V_140 ,
V_141 ) ;
return - V_80 ;
}
if ( ( args -> V_14 & ~ V_130 ) && ( args -> V_14 & ~ V_136 ) ) {
F_36 ( & V_64 -> V_142 -> V_64 , L_12 ,
args -> V_14 ) ;
return - V_80 ;
}
switch ( args -> V_127 ) {
case V_128 :
case V_143 :
case V_144 :
case V_129 :
break;
default:
F_36 ( & V_64 -> V_142 -> V_64 , L_13 ,
args -> V_127 ) ;
return - V_80 ;
}
if ( ( args -> V_127 == V_128 ) ||
( args -> V_127 == V_129 ) ) {
if ( F_78 ( V_10 , V_43 ) )
return - V_145 ;
}
F_32 ( & V_54 ) ;
if ( ( args -> V_127 != V_144 ) &&
! ( args -> V_14 & V_137 ) ) {
V_2 = F_57 ( V_68 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_107 ;
V_40 = F_2 ( V_2 ) ;
V_59 . V_51 = & V_40 -> V_7 ;
V_59 . V_62 = false ;
F_33 ( & V_59 . V_63 , & V_54 ) ;
} else {
V_2 = NULL ;
V_40 = NULL ;
}
F_34 ( & V_43 -> V_46 , & V_54 , & V_58 ) ;
V_18 = F_35 ( & V_61 , & V_54 , true , NULL ) ;
if ( V_18 )
goto V_146;
if ( V_40 ) {
V_48 = F_23 ( & V_43 -> V_46 , V_40 ) ;
if ( ! V_48 ) {
V_18 = - V_107 ;
goto V_147;
}
} else if ( args -> V_127 != V_144 ) {
V_48 = V_43 -> V_148 ;
} else {
V_48 = NULL ;
}
switch ( args -> V_127 ) {
case V_128 :
V_18 = F_79 ( V_10 , V_48 -> V_46 , args -> V_140 ,
args -> V_149 ) ;
if ( V_18 )
goto V_147;
V_139 = F_80 ( V_10 , args -> V_14 ) ;
V_18 = F_81 ( V_10 , V_48 , args -> V_140 ,
args -> V_150 , args -> V_149 ,
V_139 ) ;
break;
case V_143 :
V_18 = F_82 ( V_10 , V_48 , args -> V_140 ) ;
break;
case V_144 :
V_18 = F_83 ( V_10 , & V_43 -> V_46 ,
args -> V_140 ,
args -> V_149 ) ;
break;
case V_129 :
V_18 = F_79 ( V_10 , V_48 -> V_46 , args -> V_140 ,
args -> V_149 ) ;
if ( V_18 )
goto V_147;
V_139 = F_80 ( V_10 , args -> V_14 ) ;
V_18 = F_84 ( V_10 , V_48 , args -> V_140 ,
args -> V_150 , args -> V_149 ,
V_139 ) ;
break;
default:
break;
}
if ( ! V_18 && ! ( args -> V_14 & V_131 ) && ! V_151 )
F_74 ( V_10 , & V_43 -> V_46 , V_48 , & V_54 ,
args -> V_127 ) ;
V_147:
F_42 ( & V_61 , & V_54 ) ;
V_146:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_85 ( struct V_31 * V_64 , void * V_67 ,
struct V_33 * V_68 )
{
struct V_152 * args = V_67 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_57 ( V_68 , args -> V_36 ) ;
if ( V_2 == NULL ) {
return - V_107 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_39 ( V_18 ) )
goto V_86;
switch ( args -> V_121 ) {
case V_153 : {
struct V_154 V_155 ;
void T_6 * V_86 = ( void T_6 * ) ( V_156 ) args -> V_157 ;
V_155 . V_72 = V_4 -> V_5 . V_11 ;
V_155 . V_12 = V_4 -> V_7 . V_158 . V_159 << V_160 ;
V_155 . V_81 = V_4 -> V_94 ;
V_155 . V_73 = V_4 -> V_14 ;
F_25 ( V_4 ) ;
if ( F_86 ( V_86 , & V_155 , sizeof( V_155 ) ) )
V_18 = - V_161 ;
break;
}
case V_162 :
if ( V_4 -> V_163 && ( args -> V_157 & V_29 ) ) {
V_18 = - V_80 ;
F_25 ( V_4 ) ;
break;
}
if ( F_58 ( V_4 -> V_7 . V_96 ) ) {
V_18 = - V_108 ;
F_25 ( V_4 ) ;
break;
}
V_4 -> V_94 = args -> V_157 & ( V_29 |
V_30 |
V_82 ) ;
V_4 -> V_95 = V_4 -> V_94 ;
if ( V_4 -> V_95 == V_29 )
V_4 -> V_95 |= V_30 ;
F_25 ( V_4 ) ;
break;
default:
F_25 ( V_4 ) ;
V_18 = - V_80 ;
}
V_86:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_87 ( struct V_33 * V_39 ,
struct V_31 * V_64 ,
struct V_164 * args )
{
struct V_9 * V_10 = V_64 -> V_69 ;
struct V_1 * V_2 ;
T_4 V_36 ;
int V_18 ;
args -> V_165 = F_88 ( V_10 , args -> V_166 ,
F_89 ( args -> V_167 , 8 ) , 0 ) ;
args -> V_11 = ( T_2 ) args -> V_165 * args -> V_168 ;
args -> V_11 = F_90 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_74 ,
V_169 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_45 ( V_39 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_36 = V_36 ;
return 0 ;
}
static int F_91 ( int V_170 , void * V_171 , void * V_67 )
{
struct V_1 * V_2 = V_171 ;
struct V_3 * V_51 = F_2 ( V_2 ) ;
struct V_172 * V_173 = V_67 ;
unsigned V_174 ;
const char * V_104 ;
unsigned V_175 ;
V_174 = F_92 ( V_51 -> V_7 . V_158 . V_176 ) ;
switch ( V_174 ) {
case V_29 :
V_104 = L_14 ;
break;
case V_30 :
V_104 = L_15 ;
break;
case V_82 :
default:
V_104 = L_16 ;
break;
}
F_93 ( V_173 , L_17 ,
V_170 , F_94 ( V_51 ) , V_104 ,
F_95 ( V_51 ) ) ;
V_175 = F_96 ( V_51 -> V_175 ) ;
if ( V_175 )
F_93 ( V_173 , L_18 , V_175 ) ;
F_93 ( V_173 , L_19 ) ;
return 0 ;
}
static int F_97 ( struct V_172 * V_173 , void * V_67 )
{
struct V_177 * V_178 = (struct V_177 * ) V_173 -> V_179 ;
struct V_31 * V_64 = V_178 -> V_180 -> V_64 ;
struct V_33 * V_34 ;
int V_18 ;
V_18 = F_98 ( & V_64 -> V_35 ) ;
if ( V_18 )
return V_18 ;
F_12 (file, &dev->filelist, lhead) {
struct V_181 * V_182 ;
F_99 () ;
V_182 = F_100 ( V_34 -> V_183 , V_184 ) ;
F_93 ( V_173 , L_20 , F_101 ( V_34 -> V_183 ) ,
V_182 ? V_182 -> V_185 : L_21 ) ;
F_102 () ;
F_14 ( & V_34 -> V_37 ) ;
F_103 ( & V_34 -> V_38 , F_91 , V_173 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_64 -> V_35 ) ;
return 0 ;
}
int F_104 ( struct V_9 * V_10 )
{
#if F_105 ( V_186 )
return F_106 ( V_10 , V_187 , 1 ) ;
#endif
return 0 ;
}
