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
int V_17 ;
* V_16 = NULL ;
if ( V_12 < V_18 ) {
V_12 = V_18 ;
}
V_19:
V_17 = F_7 ( V_10 , V_11 , V_12 , V_15 , V_13 ,
V_14 , NULL , NULL , 0 , & V_4 ) ;
if ( V_17 ) {
if ( V_17 != - V_20 ) {
if ( V_13 == V_21 ) {
V_13 |= V_22 ;
goto V_19;
}
F_8 ( L_1 ,
V_11 , V_13 , V_12 , V_17 ) ;
}
return V_17 ;
}
* V_16 = & V_4 -> V_5 ;
return 0 ;
}
void F_9 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_25 * V_26 ;
F_10 ( & V_24 -> V_27 ) ;
F_11 (file, &ddev->filelist, lhead) {
struct V_1 * V_2 ;
int V_28 ;
F_12 ( 1 , L_2 ) ;
F_13 ( & V_26 -> V_29 ) ;
F_14 (&file->object_idr, gobj, handle) {
F_12 ( 1 , L_3 ) ;
F_15 ( V_2 ) ;
}
F_16 ( & V_26 -> V_30 ) ;
F_17 ( & V_26 -> V_29 ) ;
}
F_18 ( & V_24 -> V_27 ) ;
}
int F_19 ( struct V_1 * V_16 ,
struct V_25 * V_31 )
{
struct V_3 * V_32 = F_2 ( V_16 ) ;
struct V_9 * V_10 = F_20 ( V_32 -> V_7 . V_33 ) ;
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_37 * V_38 = & V_35 -> V_38 ;
struct V_39 * V_40 ;
int V_17 ;
V_17 = F_21 ( V_32 , false ) ;
if ( V_17 )
return V_17 ;
V_40 = F_22 ( V_38 , V_32 ) ;
if ( ! V_40 ) {
V_40 = F_23 ( V_10 , V_38 , V_32 ) ;
} else {
++ V_40 -> V_41 ;
}
F_24 ( V_32 ) ;
return 0 ;
}
static int F_25 ( void * V_42 , struct V_3 * V_43 )
{
if ( ! F_26 ( V_43 ) )
return - V_20 ;
if ( V_43 -> V_44 && ! F_26 ( V_43 -> V_44 ) )
return - V_20 ;
return 0 ;
}
static bool F_27 ( struct V_9 * V_10 ,
struct V_37 * V_38 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 ;
F_11 (entry, list, head) {
struct V_3 * V_43 =
F_28 ( V_48 -> V_43 , struct V_3 , V_7 ) ;
if ( F_25 ( NULL , V_43 ) )
return false ;
}
return ! F_29 ( V_10 , V_38 , F_25 , NULL ) ;
}
void F_30 ( struct V_1 * V_16 ,
struct V_25 * V_31 )
{
struct V_3 * V_43 = F_2 ( V_16 ) ;
struct V_9 * V_10 = F_20 ( V_43 -> V_7 . V_33 ) ;
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_37 * V_38 = & V_35 -> V_38 ;
struct V_49 V_50 ;
struct V_45 V_46 ;
struct V_47 V_51 ;
struct V_52 V_53 ;
struct V_39 * V_40 ;
int V_17 ;
F_31 ( & V_46 ) ;
V_51 . V_43 = & V_43 -> V_7 ;
V_51 . V_54 = true ;
F_32 ( & V_51 . V_55 , & V_46 ) ;
F_33 ( V_38 , & V_46 , & V_50 ) ;
V_17 = F_34 ( & V_53 , & V_46 , false , NULL ) ;
if ( V_17 ) {
F_35 ( V_10 -> V_56 , L_4
L_5 , V_17 ) ;
return;
}
V_40 = F_22 ( V_38 , V_43 ) ;
if ( V_40 && -- V_40 -> V_41 == 0 ) {
F_36 ( V_10 , V_40 ) ;
if ( F_27 ( V_10 , V_38 , & V_46 ) ) {
struct V_57 * V_58 = NULL ;
V_17 = F_37 ( V_10 , V_38 , & V_58 ) ;
if ( F_38 ( V_17 ) ) {
F_35 ( V_10 -> V_56 , L_6
L_7 , V_17 ) ;
}
if ( V_58 ) {
F_39 ( V_43 , V_58 , true ) ;
F_40 ( V_58 ) ;
}
}
}
F_41 ( & V_53 , & V_46 ) ;
}
int F_42 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
struct V_9 * V_10 = V_56 -> V_61 ;
union V_62 * args = V_59 ;
T_3 V_11 = args -> V_63 . V_64 ;
struct V_1 * V_2 ;
T_4 V_28 ;
bool V_15 = false ;
int V_17 ;
if ( args -> V_63 . V_65 & ~ ( V_66 |
V_67 |
V_68 |
V_69 ) )
return - V_70 ;
if ( args -> V_63 . V_71 & ~ ( V_72 |
V_22 |
V_21 |
V_73 |
V_74 |
V_75 ) )
return - V_70 ;
if ( args -> V_63 . V_71 & ( V_73 |
V_74 | V_75 ) ) {
V_15 = true ;
if ( args -> V_63 . V_71 == V_73 )
V_11 = V_11 << V_76 ;
else if ( args -> V_63 . V_71 == V_74 )
V_11 = V_11 << V_77 ;
else if ( args -> V_63 . V_71 == V_75 )
V_11 = V_11 << V_78 ;
else
return - V_70 ;
}
V_11 = F_43 ( V_11 , V_18 ) ;
V_17 = F_6 ( V_10 , V_11 , args -> V_63 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_63 . V_71 ) ,
args -> V_63 . V_65 ,
V_15 , & V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_44 ( V_60 , V_2 , & V_28 ) ;
F_15 ( V_2 ) ;
if ( V_17 )
return V_17 ;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_79 . V_28 = V_28 ;
return 0 ;
}
int F_45 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
struct V_9 * V_10 = V_56 -> V_61 ;
struct V_80 * args = V_59 ;
struct V_1 * V_2 ;
struct V_3 * V_43 ;
T_4 V_28 ;
int V_17 ;
if ( F_46 ( args -> V_81 | args -> V_11 ) )
return - V_70 ;
if ( args -> V_14 & ~ ( V_82 |
V_83 | V_84 |
V_85 ) )
return - V_70 ;
if ( ! ( args -> V_14 & V_82 ) &&
! ( args -> V_14 & V_85 ) ) {
return - V_86 ;
}
V_17 = F_6 ( V_10 , args -> V_11 , 0 ,
V_72 , 0 ,
0 , & V_2 ) ;
if ( V_17 )
return V_17 ;
V_43 = F_2 ( V_2 ) ;
V_43 -> V_87 = V_22 ;
V_43 -> V_88 = V_22 ;
V_17 = F_47 ( V_43 -> V_7 . V_89 , args -> V_81 , args -> V_14 ) ;
if ( V_17 )
goto V_90;
if ( args -> V_14 & V_85 ) {
V_17 = F_48 ( V_43 , args -> V_81 ) ;
if ( V_17 )
goto V_90;
}
if ( args -> V_14 & V_84 ) {
F_49 ( & V_91 -> V_92 -> V_93 ) ;
V_17 = F_50 ( V_43 -> V_7 . V_89 ,
V_43 -> V_7 . V_89 -> V_94 ) ;
if ( V_17 )
goto V_95;
V_17 = F_21 ( V_43 , true ) ;
if ( V_17 )
goto V_96;
F_51 ( V_43 , V_22 ) ;
V_17 = F_52 ( & V_43 -> V_7 , & V_43 -> V_97 , true , false ) ;
F_24 ( V_43 ) ;
if ( V_17 )
goto V_96;
F_53 ( & V_91 -> V_92 -> V_93 ) ;
}
V_17 = F_44 ( V_60 , V_2 , & V_28 ) ;
F_15 ( V_2 ) ;
if ( V_17 )
return V_17 ;
args -> V_28 = V_28 ;
return 0 ;
V_96:
F_54 ( V_43 -> V_7 . V_89 -> V_94 , V_43 -> V_7 . V_89 -> V_98 , false ) ;
V_95:
F_53 ( & V_91 -> V_92 -> V_93 ) ;
V_90:
F_15 ( V_2 ) ;
return V_17 ;
}
int F_55 ( struct V_25 * V_60 ,
struct V_23 * V_56 ,
T_4 V_28 , T_3 * V_99 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_56 ( V_60 , V_28 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_57 ( V_4 -> V_7 . V_89 ) ||
( V_4 -> V_14 & V_67 ) ) {
F_15 ( V_2 ) ;
return - V_101 ;
}
* V_99 = F_58 ( V_4 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_59 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
union V_102 * args = V_59 ;
T_4 V_28 = args -> V_63 . V_28 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_55 ( V_60 , V_56 , V_28 , & args -> V_79 . V_103 ) ;
}
unsigned long F_60 ( T_3 V_104 )
{
unsigned long V_105 ;
T_5 V_106 ;
if ( ( ( V_107 ) V_104 ) < 0 )
return V_108 ;
V_106 = F_61 ( F_62 ( V_104 ) , F_63 () ) ;
if ( F_64 ( V_106 ) < 0 )
return 0 ;
V_105 = F_65 ( F_64 ( V_106 ) ) ;
if ( V_105 > V_108 )
return V_108 - 1 ;
return V_105 ;
}
int F_66 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
union V_109 * args = V_59 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_28 = args -> V_63 . V_28 ;
unsigned long V_106 = F_60 ( args -> V_63 . V_106 ) ;
int V_17 = 0 ;
long V_110 ;
V_2 = F_56 ( V_60 , V_28 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_110 = F_67 ( V_4 -> V_7 . V_111 , true , true ,
V_106 ) ;
if ( V_110 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_79 . V_112 = ( V_110 == 0 ) ;
} else
V_17 = V_110 ;
F_15 ( V_2 ) ;
return V_17 ;
}
int F_68 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
struct V_113 * args = V_59 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_17 = - 1 ;
F_69 ( L_8 , args -> V_28 ) ;
V_2 = F_56 ( V_60 , args -> V_28 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_4 = F_2 ( V_2 ) ;
V_17 = F_21 ( V_4 , false ) ;
if ( F_38 ( V_17 != 0 ) )
goto V_79;
if ( args -> V_114 == V_115 ) {
F_70 ( V_4 , & args -> V_59 . V_116 ) ;
V_17 = F_71 ( V_4 , args -> V_59 . V_59 ,
sizeof( args -> V_59 . V_59 ) ,
& args -> V_59 . V_117 ,
& args -> V_59 . V_14 ) ;
} else if ( args -> V_114 == V_118 ) {
if ( args -> V_59 . V_117 > sizeof( args -> V_59 . V_59 ) ) {
V_17 = - V_70 ;
goto V_119;
}
V_17 = F_72 ( V_4 , args -> V_59 . V_116 ) ;
if ( ! V_17 )
V_17 = F_73 ( V_4 , args -> V_59 . V_59 ,
args -> V_59 . V_117 ,
args -> V_59 . V_14 ) ;
}
V_119:
F_24 ( V_4 ) ;
V_79:
F_15 ( V_2 ) ;
return V_17 ;
}
static void F_74 ( struct V_9 * V_10 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_45 * V_46 ,
T_4 V_120 )
{
int V_17 = - V_20 ;
if ( ! F_27 ( V_10 , V_38 , V_46 ) )
goto error;
V_17 = F_75 ( V_10 , V_38 ) ;
if ( V_17 )
goto error;
V_17 = F_37 ( V_10 , V_38 , NULL ) ;
if ( V_17 )
goto error;
if ( V_120 == V_121 ||
V_120 == V_122 )
V_17 = F_76 ( V_10 , V_40 , false ) ;
error:
if ( V_17 && V_17 != - V_20 )
F_8 ( L_9 , V_17 ) ;
}
int F_77 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
const T_4 V_123 = V_124 |
V_125 | V_126 |
V_127 | V_128 ;
const T_4 V_129 = V_124 |
V_130 ;
struct V_131 * args = V_59 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_56 -> V_61 ;
struct V_34 * V_35 = V_60 -> V_36 ;
struct V_3 * V_32 ;
struct V_39 * V_40 ;
struct V_49 V_50 ;
struct V_47 V_51 ;
struct V_52 V_53 ;
struct V_45 V_46 ;
T_3 V_132 ;
int V_17 = 0 ;
if ( args -> V_133 < V_134 ) {
F_35 ( & V_56 -> V_135 -> V_56 ,
L_10 ,
( unsigned long ) args -> V_133 ,
V_134 ) ;
return - V_70 ;
}
if ( ( args -> V_14 & ~ V_123 ) && ( args -> V_14 & ~ V_129 ) ) {
F_35 ( & V_56 -> V_135 -> V_56 , L_11 ,
args -> V_14 ) ;
return - V_70 ;
}
switch ( args -> V_120 ) {
case V_121 :
case V_136 :
case V_137 :
case V_122 :
break;
default:
F_35 ( & V_56 -> V_135 -> V_56 , L_12 ,
args -> V_120 ) ;
return - V_70 ;
}
if ( ( args -> V_120 == V_121 ) ||
( args -> V_120 == V_122 ) ) {
if ( F_78 ( V_10 , V_35 ) )
return - V_138 ;
}
F_31 ( & V_46 ) ;
if ( ( args -> V_120 != V_137 ) &&
! ( args -> V_14 & V_130 ) ) {
V_2 = F_56 ( V_60 , args -> V_28 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_32 = F_2 ( V_2 ) ;
V_51 . V_43 = & V_32 -> V_7 ;
V_51 . V_54 = false ;
F_32 ( & V_51 . V_55 , & V_46 ) ;
} else {
V_2 = NULL ;
V_32 = NULL ;
}
F_33 ( & V_35 -> V_38 , & V_46 , & V_50 ) ;
V_17 = F_34 ( & V_53 , & V_46 , true , NULL ) ;
if ( V_17 )
goto V_139;
if ( V_32 ) {
V_40 = F_22 ( & V_35 -> V_38 , V_32 ) ;
if ( ! V_40 ) {
V_17 = - V_100 ;
goto V_140;
}
} else if ( args -> V_120 != V_137 ) {
V_40 = V_35 -> V_141 ;
} else {
V_40 = NULL ;
}
switch ( args -> V_120 ) {
case V_121 :
V_17 = F_79 ( V_10 , V_40 -> V_142 . V_38 , args -> V_133 ,
args -> V_143 ) ;
if ( V_17 )
goto V_140;
V_132 = F_80 ( V_10 , args -> V_14 ) ;
V_17 = F_81 ( V_10 , V_40 , args -> V_133 ,
args -> V_144 , args -> V_143 ,
V_132 ) ;
break;
case V_136 :
V_17 = F_82 ( V_10 , V_40 , args -> V_133 ) ;
break;
case V_137 :
V_17 = F_83 ( V_10 , & V_35 -> V_38 ,
args -> V_133 ,
args -> V_143 ) ;
break;
case V_122 :
V_17 = F_79 ( V_10 , V_40 -> V_142 . V_38 , args -> V_133 ,
args -> V_143 ) ;
if ( V_17 )
goto V_140;
V_132 = F_80 ( V_10 , args -> V_14 ) ;
V_17 = F_84 ( V_10 , V_40 , args -> V_133 ,
args -> V_144 , args -> V_143 ,
V_132 ) ;
break;
default:
break;
}
if ( ! V_17 && ! ( args -> V_14 & V_124 ) && ! V_145 )
F_74 ( V_10 , & V_35 -> V_38 , V_40 , & V_46 ,
args -> V_120 ) ;
V_140:
F_41 ( & V_53 , & V_46 ) ;
V_139:
F_15 ( V_2 ) ;
return V_17 ;
}
int F_85 ( struct V_23 * V_56 , void * V_59 ,
struct V_25 * V_60 )
{
struct V_146 * args = V_59 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_2 = F_56 ( V_60 , args -> V_28 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_17 = F_21 ( V_4 , false ) ;
if ( F_38 ( V_17 ) )
goto V_79;
switch ( args -> V_114 ) {
case V_147 : {
struct V_148 V_149 ;
void T_6 * V_79 = F_86 ( args -> V_150 ) ;
V_149 . V_64 = V_4 -> V_5 . V_11 ;
V_149 . V_12 = V_4 -> V_7 . V_151 . V_152 << V_153 ;
V_149 . V_71 = V_4 -> V_87 ;
V_149 . V_65 = V_4 -> V_14 ;
F_24 ( V_4 ) ;
if ( F_87 ( V_79 , & V_149 , sizeof( V_149 ) ) )
V_17 = - V_154 ;
break;
}
case V_155 :
if ( V_4 -> V_156 && ( args -> V_150 & V_21 ) ) {
V_17 = - V_70 ;
F_24 ( V_4 ) ;
break;
}
if ( F_57 ( V_4 -> V_7 . V_89 ) ) {
V_17 = - V_101 ;
F_24 ( V_4 ) ;
break;
}
V_4 -> V_87 = args -> V_150 & ( V_21 |
V_22 |
V_72 ) ;
V_4 -> V_88 = V_4 -> V_87 ;
if ( V_4 -> V_88 == V_21 )
V_4 -> V_88 |= V_22 ;
F_24 ( V_4 ) ;
break;
default:
F_24 ( V_4 ) ;
V_17 = - V_70 ;
}
V_79:
F_15 ( V_2 ) ;
return V_17 ;
}
int F_88 ( struct V_25 * V_31 ,
struct V_23 * V_56 ,
struct V_157 * args )
{
struct V_9 * V_10 = V_56 -> V_61 ;
struct V_1 * V_2 ;
T_4 V_28 ;
int V_17 ;
args -> V_158 = F_89 ( V_10 , args -> V_159 ,
F_90 ( args -> V_160 , 8 ) , 0 ) ;
args -> V_11 = ( T_2 ) args -> V_158 * args -> V_161 ;
args -> V_11 = F_91 ( args -> V_11 , V_18 ) ;
V_17 = F_6 ( V_10 , args -> V_11 , 0 ,
V_21 ,
V_66 ,
V_162 ,
& V_2 ) ;
if ( V_17 )
return - V_163 ;
V_17 = F_44 ( V_31 , V_2 , & V_28 ) ;
F_15 ( V_2 ) ;
if ( V_17 ) {
return V_17 ;
}
args -> V_28 = V_28 ;
return 0 ;
}
static int F_92 ( int V_164 , void * V_165 , void * V_59 )
{
struct V_1 * V_2 = V_165 ;
struct V_3 * V_43 = F_2 ( V_2 ) ;
struct V_166 * V_167 = V_59 ;
unsigned V_168 ;
const char * V_97 ;
unsigned V_169 ;
T_3 V_170 ;
V_168 = F_93 ( V_43 -> V_7 . V_151 . V_171 ) ;
switch ( V_168 ) {
case V_21 :
V_97 = L_13 ;
break;
case V_22 :
V_97 = L_14 ;
break;
case V_72 :
default:
V_97 = L_15 ;
break;
}
F_94 ( V_167 , L_16 ,
V_164 , F_95 ( V_43 ) , V_97 ) ;
V_170 = F_96 ( V_43 -> V_7 . V_151 . V_172 ) ;
if ( V_170 != V_173 )
F_94 ( V_167 , L_17 , V_170 ) ;
V_169 = F_96 ( V_43 -> V_169 ) ;
if ( V_169 )
F_94 ( V_167 , L_18 , V_169 ) ;
F_94 ( V_167 , L_19 ) ;
return 0 ;
}
static int F_97 ( struct V_166 * V_167 , void * V_59 )
{
struct V_174 * V_175 = (struct V_174 * ) V_167 -> V_176 ;
struct V_23 * V_56 = V_175 -> V_177 -> V_56 ;
struct V_25 * V_26 ;
int V_17 ;
V_17 = F_98 ( & V_56 -> V_27 ) ;
if ( V_17 )
return V_17 ;
F_11 (file, &dev->filelist, lhead) {
struct V_178 * V_179 ;
F_99 () ;
V_179 = F_100 ( V_26 -> V_180 , V_181 ) ;
F_94 ( V_167 , L_20 , F_101 ( V_26 -> V_180 ) ,
V_179 ? V_179 -> V_182 : L_21 ) ;
F_102 () ;
F_13 ( & V_26 -> V_29 ) ;
F_103 ( & V_26 -> V_30 , F_92 , V_167 ) ;
F_17 ( & V_26 -> V_29 ) ;
}
F_18 ( & V_56 -> V_27 ) ;
return 0 ;
}
int F_104 ( struct V_9 * V_10 )
{
#if F_105 ( V_183 )
return F_106 ( V_10 , V_184 , 1 ) ;
#endif
return 0 ;
}
