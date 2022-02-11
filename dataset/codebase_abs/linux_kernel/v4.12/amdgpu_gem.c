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
static int F_43 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_67 ) {
V_18 = F_44 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_68 ;
}
return V_18 ;
}
int F_45 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
struct V_9 * V_10 = V_64 -> V_71 ;
union V_72 * args = V_69 ;
T_3 V_11 = args -> V_73 . V_74 ;
struct V_1 * V_2 ;
T_4 V_36 ;
bool V_15 = false ;
int V_18 ;
if ( args -> V_73 . V_75 & ~ ( V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 ) ) {
V_18 = - V_82 ;
goto V_83;
}
if ( args -> V_73 . V_84 & ~ ( V_85 |
V_30 |
V_29 |
V_20 |
V_21 |
V_22 ) ) {
V_18 = - V_82 ;
goto V_83;
}
if ( args -> V_73 . V_84 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_73 . V_84 == V_20 )
V_11 = V_11 << V_86 ;
else if ( args -> V_73 . V_84 == V_21 )
V_11 = V_11 << V_87 ;
else if ( args -> V_73 . V_84 == V_22 )
V_11 = V_11 << V_88 ;
else {
V_18 = - V_82 ;
goto V_83;
}
}
V_11 = F_46 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_73 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_73 . V_84 ) ,
args -> V_73 . V_75 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_83;
V_18 = F_47 ( V_70 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_83;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_89 . V_36 = V_36 ;
return 0 ;
V_83:
V_18 = F_43 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_48 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
struct V_9 * V_10 = V_64 -> V_71 ;
struct V_90 * args = V_69 ;
struct V_1 * V_2 ;
struct V_3 * V_51 ;
T_4 V_36 ;
int V_18 ;
if ( F_49 ( args -> V_91 | args -> V_11 ) )
return - V_82 ;
if ( args -> V_14 & ~ ( V_92 |
V_93 | V_94 |
V_95 ) )
return - V_82 ;
if ( ! ( args -> V_14 & V_92 ) &&
! ( args -> V_14 & V_95 ) ) {
return - V_96 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_85 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_97;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_98 = V_30 ;
V_51 -> V_99 = V_30 ;
V_18 = F_50 ( V_51 -> V_7 . V_100 , args -> V_91 , args -> V_14 ) ;
if ( V_18 )
goto V_101;
if ( args -> V_14 & V_95 ) {
V_18 = F_51 ( V_51 , args -> V_91 ) ;
if ( V_18 )
goto V_101;
}
if ( args -> V_14 & V_94 ) {
F_52 ( & V_102 -> V_103 -> V_104 ) ;
V_18 = F_53 ( V_51 -> V_7 . V_100 ,
V_51 -> V_7 . V_100 -> V_105 ) ;
if ( V_18 )
goto V_106;
V_18 = F_22 ( V_51 , true ) ;
if ( V_18 )
goto V_107;
F_54 ( V_51 , V_30 ) ;
V_18 = F_55 ( & V_51 -> V_7 , & V_51 -> V_108 , true , false ) ;
F_25 ( V_51 ) ;
if ( V_18 )
goto V_107;
F_56 ( & V_102 -> V_103 -> V_104 ) ;
}
V_18 = F_47 ( V_70 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_97;
args -> V_36 = V_36 ;
return 0 ;
V_107:
F_57 ( V_51 -> V_7 . V_100 -> V_105 , V_51 -> V_7 . V_100 -> V_109 , false ) ;
V_106:
F_56 ( & V_102 -> V_103 -> V_104 ) ;
V_101:
F_16 ( V_2 ) ;
V_97:
V_18 = F_43 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_58 ( struct V_33 * V_70 ,
struct V_31 * V_64 ,
T_4 V_36 , T_3 * V_110 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_59 ( V_70 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_111 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_60 ( V_4 -> V_7 . V_100 ) ||
( V_4 -> V_14 & V_77 ) ) {
F_16 ( V_2 ) ;
return - V_112 ;
}
* V_110 = F_61 ( V_4 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_62 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
union V_113 * args = V_69 ;
T_4 V_36 = args -> V_73 . V_36 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_58 ( V_70 , V_64 , V_36 , & args -> V_89 . V_114 ) ;
}
unsigned long F_63 ( T_3 V_115 )
{
unsigned long V_116 ;
T_5 V_117 ;
if ( ( ( V_118 ) V_115 ) < 0 )
return V_119 ;
V_117 = F_64 ( F_65 ( V_115 ) , F_66 () ) ;
if ( F_67 ( V_117 ) < 0 )
return 0 ;
V_116 = F_68 ( F_67 ( V_117 ) ) ;
if ( V_116 > V_119 )
return V_119 - 1 ;
return V_116 ;
}
int F_69 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
struct V_9 * V_10 = V_64 -> V_71 ;
union V_120 * args = V_69 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_36 = args -> V_73 . V_36 ;
unsigned long V_117 = F_63 ( args -> V_73 . V_117 ) ;
int V_18 = 0 ;
long V_121 ;
V_2 = F_59 ( V_70 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_111 ;
}
V_4 = F_2 ( V_2 ) ;
V_121 = F_70 ( V_4 -> V_7 . V_122 , true , true ,
V_117 ) ;
if ( V_121 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_89 . V_123 = ( V_121 == 0 ) ;
} else
V_18 = V_121 ;
F_16 ( V_2 ) ;
V_18 = F_43 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_71 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
struct V_124 * args = V_69 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_9 , args -> V_36 ) ;
V_2 = F_59 ( V_70 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_111 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_39 ( V_18 != 0 ) )
goto V_89;
if ( args -> V_125 == V_126 ) {
F_72 ( V_4 , & args -> V_69 . V_127 ) ;
V_18 = F_73 ( V_4 , args -> V_69 . V_69 ,
sizeof( args -> V_69 . V_69 ) ,
& args -> V_69 . V_128 ,
& args -> V_69 . V_14 ) ;
} else if ( args -> V_125 == V_129 ) {
if ( args -> V_69 . V_128 > sizeof( args -> V_69 . V_69 ) ) {
V_18 = - V_82 ;
goto V_130;
}
V_18 = F_74 ( V_4 , args -> V_69 . V_127 ) ;
if ( ! V_18 )
V_18 = F_75 ( V_4 , args -> V_69 . V_69 ,
args -> V_69 . V_128 ,
args -> V_69 . V_14 ) ;
}
V_130:
F_25 ( V_4 ) ;
V_89:
F_16 ( V_2 ) ;
return V_18 ;
}
static void F_76 ( struct V_9 * V_10 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_53 * V_54 ,
T_4 V_131 )
{
int V_18 = - V_28 ;
if ( ! F_28 ( V_10 , V_46 , V_54 ) )
goto error;
V_18 = F_77 ( V_10 , V_46 ) ;
if ( V_18 )
goto error;
V_18 = F_38 ( V_10 , V_46 , NULL ) ;
if ( V_18 )
goto error;
if ( V_131 == V_132 ||
V_131 == V_133 )
V_18 = F_78 ( V_10 , V_48 , false ) ;
error:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_10 , V_18 ) ;
}
int F_79 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
const T_4 V_134 = V_135 |
V_136 | V_137 |
V_138 | V_139 ;
const T_4 V_140 = V_135 |
V_141 ;
struct V_142 * args = V_69 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_64 -> V_71 ;
struct V_42 * V_43 = V_70 -> V_44 ;
struct V_3 * V_40 ;
struct V_47 * V_48 ;
struct V_57 V_58 ;
struct V_55 V_59 ;
struct V_60 V_61 ;
struct V_53 V_54 ;
T_3 V_143 ;
int V_18 = 0 ;
if ( ! V_10 -> V_144 . V_145 )
return - V_146 ;
if ( args -> V_147 < V_148 ) {
F_36 ( & V_64 -> V_149 -> V_64 ,
L_11 ,
( unsigned long ) args -> V_147 ,
V_148 ) ;
return - V_82 ;
}
if ( ( args -> V_14 & ~ V_134 ) && ( args -> V_14 & ~ V_140 ) ) {
F_36 ( & V_64 -> V_149 -> V_64 , L_12 ,
args -> V_14 ) ;
return - V_82 ;
}
switch ( args -> V_131 ) {
case V_132 :
case V_150 :
case V_151 :
case V_133 :
break;
default:
F_36 ( & V_64 -> V_149 -> V_64 , L_13 ,
args -> V_131 ) ;
return - V_82 ;
}
F_32 ( & V_54 ) ;
if ( ( args -> V_131 != V_151 ) &&
! ( args -> V_14 & V_141 ) ) {
V_2 = F_59 ( V_70 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_111 ;
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
goto V_152;
if ( V_40 ) {
V_48 = F_23 ( & V_43 -> V_46 , V_40 ) ;
if ( ! V_48 ) {
V_18 = - V_111 ;
goto V_153;
}
} else if ( args -> V_131 != V_151 ) {
V_48 = V_43 -> V_154 ;
} else {
V_48 = NULL ;
}
switch ( args -> V_131 ) {
case V_132 :
V_18 = F_80 ( V_10 , V_48 -> V_46 , args -> V_147 ,
args -> V_155 ) ;
if ( V_18 )
goto V_153;
V_143 = F_81 ( V_10 , args -> V_14 ) ;
V_18 = F_82 ( V_10 , V_48 , args -> V_147 ,
args -> V_156 , args -> V_155 ,
V_143 ) ;
break;
case V_150 :
V_18 = F_83 ( V_10 , V_48 , args -> V_147 ) ;
break;
case V_151 :
V_18 = F_84 ( V_10 , & V_43 -> V_46 ,
args -> V_147 ,
args -> V_155 ) ;
break;
case V_133 :
V_18 = F_80 ( V_10 , V_48 -> V_46 , args -> V_147 ,
args -> V_155 ) ;
if ( V_18 )
goto V_153;
V_143 = F_81 ( V_10 , args -> V_14 ) ;
V_18 = F_85 ( V_10 , V_48 , args -> V_147 ,
args -> V_156 , args -> V_155 ,
V_143 ) ;
break;
default:
break;
}
if ( ! V_18 && ! ( args -> V_14 & V_135 ) && ! V_157 )
F_76 ( V_10 , & V_43 -> V_46 , V_48 , & V_54 ,
args -> V_131 ) ;
V_153:
F_42 ( & V_61 , & V_54 ) ;
V_152:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_86 ( struct V_31 * V_64 , void * V_69 ,
struct V_33 * V_70 )
{
struct V_158 * args = V_69 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_59 ( V_70 , args -> V_36 ) ;
if ( V_2 == NULL ) {
return - V_111 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_39 ( V_18 ) )
goto V_89;
switch ( args -> V_125 ) {
case V_159 : {
struct V_160 V_161 ;
void T_6 * V_89 = ( void T_6 * ) ( V_162 ) args -> V_163 ;
V_161 . V_74 = V_4 -> V_5 . V_11 ;
V_161 . V_12 = V_4 -> V_7 . V_164 . V_165 << V_166 ;
V_161 . V_84 = V_4 -> V_98 ;
V_161 . V_75 = V_4 -> V_14 ;
F_25 ( V_4 ) ;
if ( F_87 ( V_89 , & V_161 , sizeof( V_161 ) ) )
V_18 = - V_167 ;
break;
}
case V_168 :
if ( V_4 -> V_169 && ( args -> V_163 & V_29 ) ) {
V_18 = - V_82 ;
F_25 ( V_4 ) ;
break;
}
if ( F_60 ( V_4 -> V_7 . V_100 ) ) {
V_18 = - V_112 ;
F_25 ( V_4 ) ;
break;
}
V_4 -> V_98 = args -> V_163 & ( V_29 |
V_30 |
V_85 ) ;
V_4 -> V_99 = V_4 -> V_98 ;
if ( V_4 -> V_99 == V_29 )
V_4 -> V_99 |= V_30 ;
F_25 ( V_4 ) ;
break;
default:
F_25 ( V_4 ) ;
V_18 = - V_82 ;
}
V_89:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_88 ( struct V_33 * V_39 ,
struct V_31 * V_64 ,
struct V_170 * args )
{
struct V_9 * V_10 = V_64 -> V_71 ;
struct V_1 * V_2 ;
T_4 V_36 ;
int V_18 ;
args -> V_171 = F_89 ( V_10 , args -> V_172 ,
F_90 ( args -> V_173 , 8 ) , 0 ) ;
args -> V_11 = ( T_2 ) args -> V_171 * args -> V_174 ;
args -> V_11 = F_91 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_76 ,
V_175 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_47 ( V_39 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_36 = V_36 ;
return 0 ;
}
static int F_92 ( int V_176 , void * V_177 , void * V_69 )
{
struct V_1 * V_2 = V_177 ;
struct V_3 * V_51 = F_2 ( V_2 ) ;
struct V_178 * V_179 = V_69 ;
unsigned V_180 ;
const char * V_108 ;
unsigned V_181 ;
V_180 = F_93 ( V_51 -> V_7 . V_164 . V_182 ) ;
switch ( V_180 ) {
case V_29 :
V_108 = L_14 ;
break;
case V_30 :
V_108 = L_15 ;
break;
case V_85 :
default:
V_108 = L_16 ;
break;
}
F_94 ( V_179 , L_17 ,
V_176 , F_95 ( V_51 ) , V_108 ,
F_96 ( V_51 ) ) ;
V_181 = F_97 ( V_51 -> V_181 ) ;
if ( V_181 )
F_94 ( V_179 , L_18 , V_181 ) ;
F_94 ( V_179 , L_19 ) ;
return 0 ;
}
static int F_98 ( struct V_178 * V_179 , void * V_69 )
{
struct V_183 * V_184 = (struct V_183 * ) V_179 -> V_185 ;
struct V_31 * V_64 = V_184 -> V_186 -> V_64 ;
struct V_33 * V_34 ;
int V_18 ;
V_18 = F_99 ( & V_64 -> V_35 ) ;
if ( V_18 )
return V_18 ;
F_12 (file, &dev->filelist, lhead) {
struct V_187 * V_188 ;
F_100 () ;
V_188 = F_101 ( V_34 -> V_189 , V_190 ) ;
F_94 ( V_179 , L_20 , F_102 ( V_34 -> V_189 ) ,
V_188 ? V_188 -> V_191 : L_21 ) ;
F_103 () ;
F_14 ( & V_34 -> V_37 ) ;
F_104 ( & V_34 -> V_38 , F_92 , V_179 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_64 -> V_35 ) ;
return 0 ;
}
int F_105 ( struct V_9 * V_10 )
{
#if F_106 ( V_192 )
return F_107 ( V_10 , V_193 , 1 ) ;
#endif
return 0 ;
}
