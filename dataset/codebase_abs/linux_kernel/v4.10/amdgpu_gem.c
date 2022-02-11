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
if ( args -> V_69 . V_71 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_69 . V_71 == V_20 )
V_11 = V_11 << V_72 ;
else if ( args -> V_69 . V_71 == V_21 )
V_11 = V_11 << V_73 ;
else if ( args -> V_69 . V_71 == V_22 )
V_11 = V_11 << V_74 ;
else {
V_18 = - V_75 ;
goto V_76;
}
}
V_11 = F_37 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_69 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_69 . V_71 ) ,
args -> V_69 . V_77 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_76;
V_18 = F_38 ( V_66 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_76;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_78 . V_36 = V_36 ;
return 0 ;
V_76:
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_39 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_79 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_50 ;
T_4 V_36 ;
int V_18 ;
if ( F_40 ( args -> V_80 | args -> V_11 ) )
return - V_75 ;
if ( args -> V_14 & ~ ( V_81 |
V_82 | V_83 |
V_84 ) )
return - V_75 ;
if ( ! ( args -> V_14 & V_81 ) &&
! ( args -> V_14 & V_84 ) ) {
return - V_85 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_86 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_87;
V_50 = F_2 ( V_2 ) ;
V_50 -> V_88 = V_30 ;
V_50 -> V_89 = V_30 ;
V_18 = F_41 ( V_50 -> V_7 . V_90 , args -> V_80 , args -> V_14 ) ;
if ( V_18 )
goto V_91;
if ( args -> V_14 & V_84 ) {
V_18 = F_42 ( V_50 , args -> V_80 ) ;
if ( V_18 )
goto V_91;
}
if ( args -> V_14 & V_83 ) {
F_43 ( & V_92 -> V_93 -> V_94 ) ;
V_18 = F_44 ( V_50 -> V_7 . V_90 ,
V_50 -> V_7 . V_90 -> V_95 ) ;
if ( V_18 )
goto V_96;
V_18 = F_22 ( V_50 , true ) ;
if ( V_18 )
goto V_97;
F_45 ( V_50 , V_30 ) ;
V_18 = F_46 ( & V_50 -> V_7 , & V_50 -> V_98 , true , false ) ;
F_25 ( V_50 ) ;
if ( V_18 )
goto V_97;
F_47 ( & V_92 -> V_93 -> V_94 ) ;
}
V_18 = F_38 ( V_66 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_87;
args -> V_36 = V_36 ;
return 0 ;
V_97:
F_48 ( V_50 -> V_7 . V_90 -> V_95 , V_50 -> V_7 . V_90 -> V_99 , false ) ;
V_96:
F_47 ( & V_92 -> V_93 -> V_94 ) ;
V_91:
F_16 ( V_2 ) ;
V_87:
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_49 ( struct V_33 * V_66 ,
struct V_31 * V_62 ,
T_4 V_36 , T_3 * V_100 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_50 ( V_66 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_101 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_51 ( V_4 -> V_7 . V_90 ) ||
( V_4 -> V_14 & V_102 ) ) {
F_16 ( V_2 ) ;
return - V_103 ;
}
* V_100 = F_52 ( V_4 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
union V_104 * args = V_65 ;
T_4 V_36 = args -> V_69 . V_36 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_49 ( V_66 , V_62 , V_36 , & args -> V_78 . V_105 ) ;
}
unsigned long F_54 ( T_3 V_106 )
{
unsigned long V_107 ;
T_5 V_108 ;
if ( ( ( V_109 ) V_106 ) < 0 )
return V_110 ;
V_108 = F_55 ( F_56 ( V_106 ) , F_57 () ) ;
if ( F_58 ( V_108 ) < 0 )
return 0 ;
V_107 = F_59 ( F_58 ( V_108 ) ) ;
if ( V_107 > V_110 )
return V_110 - 1 ;
return V_107 ;
}
int F_60 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_9 * V_10 = V_62 -> V_67 ;
union V_111 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_36 = args -> V_69 . V_36 ;
unsigned long V_108 = F_54 ( args -> V_69 . V_108 ) ;
int V_18 = 0 ;
long V_112 ;
V_2 = F_50 ( V_66 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_101 ;
}
V_4 = F_2 ( V_2 ) ;
V_112 = F_61 ( V_4 -> V_7 . V_113 , true , true ,
V_108 ) ;
if ( V_112 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_78 . V_114 = ( V_112 == 0 ) ;
} else
V_18 = V_112 ;
F_16 ( V_2 ) ;
V_18 = F_34 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_62 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_115 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_7 , args -> V_36 ) ;
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_101 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_63 ( V_18 != 0 ) )
goto V_78;
if ( args -> V_116 == V_117 ) {
F_64 ( V_4 , & args -> V_65 . V_118 ) ;
V_18 = F_65 ( V_4 , args -> V_65 . V_65 ,
sizeof( args -> V_65 . V_65 ) ,
& args -> V_65 . V_119 ,
& args -> V_65 . V_14 ) ;
} else if ( args -> V_116 == V_120 ) {
if ( args -> V_65 . V_119 > sizeof( args -> V_65 . V_65 ) ) {
V_18 = - V_75 ;
goto V_121;
}
V_18 = F_66 ( V_4 , args -> V_65 . V_118 ) ;
if ( ! V_18 )
V_18 = F_67 ( V_4 , args -> V_65 . V_65 ,
args -> V_65 . V_119 ,
args -> V_65 . V_14 ) ;
}
V_121:
F_25 ( V_4 ) ;
V_78:
F_16 ( V_2 ) ;
return V_18 ;
}
static int F_68 ( void * V_122 , struct V_3 * V_50 )
{
unsigned V_123 = F_69 ( V_50 -> V_7 . V_124 . V_125 ) ;
return V_123 == V_86 ? - V_28 : 0 ;
}
static void F_70 ( struct V_9 * V_10 ,
struct V_47 * V_48 ,
T_4 V_126 )
{
struct V_56 V_57 , * V_127 ;
struct V_51 V_52 ;
struct V_58 V_59 ;
struct V_53 V_54 , V_55 ;
unsigned V_123 ;
int V_18 ;
F_27 ( & V_54 ) ;
F_27 ( & V_55 ) ;
V_57 . V_50 = & V_48 -> V_50 -> V_7 ;
V_57 . V_60 = true ;
F_28 ( & V_57 . V_61 , & V_54 ) ;
F_29 ( V_48 -> V_46 , & V_54 , & V_52 ) ;
V_18 = F_30 ( & V_59 , & V_54 , true , & V_55 ) ;
if ( V_18 )
goto V_128;
F_12 (entry, &list, head) {
V_123 = F_69 ( V_127 -> V_50 -> V_124 . V_125 ) ;
if ( V_123 == V_86 )
goto V_129;
}
V_18 = F_71 ( V_10 , V_48 -> V_46 , F_68 ,
NULL ) ;
if ( V_18 )
goto V_129;
V_18 = F_72 ( V_10 , V_48 -> V_46 ) ;
if ( V_18 )
goto V_129;
V_18 = F_73 ( V_10 , V_48 -> V_46 ) ;
if ( V_18 )
goto V_129;
if ( V_126 == V_130 )
V_18 = F_74 ( V_10 , V_48 , false ) ;
V_129:
F_33 ( & V_59 , & V_54 ) ;
V_128:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_8 , V_18 ) ;
}
int F_75 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_131 * args = V_65 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_42 * V_43 = V_66 -> V_44 ;
struct V_3 * V_40 ;
struct V_47 * V_48 ;
struct V_51 V_52 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_53 V_54 , V_55 ;
T_4 V_132 , V_133 = 0 ;
int V_18 = 0 ;
if ( ! V_10 -> V_134 . V_135 )
return - V_136 ;
if ( args -> V_137 < V_138 ) {
F_31 ( & V_62 -> V_139 -> V_62 ,
L_9 ,
( unsigned long ) args -> V_137 ,
V_138 ) ;
return - V_75 ;
}
V_132 = ~ ( V_140 | V_141 |
V_142 | V_143 ) ;
if ( ( args -> V_14 & V_132 ) ) {
F_31 ( & V_62 -> V_139 -> V_62 , L_10 ,
args -> V_14 , V_132 ) ;
return - V_75 ;
}
switch ( args -> V_126 ) {
case V_130 :
case V_144 :
break;
default:
F_31 ( & V_62 -> V_139 -> V_62 , L_11 ,
args -> V_126 ) ;
return - V_75 ;
}
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_101 ;
V_40 = F_2 ( V_2 ) ;
F_27 ( & V_54 ) ;
F_27 ( & V_55 ) ;
V_57 . V_50 = & V_40 -> V_7 ;
V_57 . V_60 = true ;
F_28 ( & V_57 . V_61 , & V_54 ) ;
F_29 ( & V_43 -> V_46 , & V_54 , & V_52 ) ;
V_18 = F_30 ( & V_59 , & V_54 , true , & V_55 ) ;
if ( V_18 ) {
F_16 ( V_2 ) ;
return V_18 ;
}
V_48 = F_23 ( & V_43 -> V_46 , V_40 ) ;
if ( ! V_48 ) {
F_33 ( & V_59 , & V_54 ) ;
F_16 ( V_2 ) ;
return - V_101 ;
}
switch ( args -> V_126 ) {
case V_130 :
if ( args -> V_14 & V_141 )
V_133 |= V_145 ;
if ( args -> V_14 & V_142 )
V_133 |= V_146 ;
if ( args -> V_14 & V_143 )
V_133 |= V_147 ;
V_18 = F_76 ( V_10 , V_48 , args -> V_137 ,
args -> V_148 , args -> V_149 ,
V_133 ) ;
break;
case V_144 :
V_18 = F_77 ( V_10 , V_48 , args -> V_137 ) ;
break;
default:
break;
}
F_33 ( & V_59 , & V_54 ) ;
if ( ! V_18 && ! ( args -> V_14 & V_140 ) &&
! V_150 )
F_70 ( V_10 , V_48 , args -> V_126 ) ;
F_16 ( V_2 ) ;
return V_18 ;
}
int F_78 ( struct V_31 * V_62 , void * V_65 ,
struct V_33 * V_66 )
{
struct V_151 * args = V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_50 ( V_66 , args -> V_36 ) ;
if ( V_2 == NULL ) {
return - V_101 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_4 , false ) ;
if ( F_63 ( V_18 ) )
goto V_78;
switch ( args -> V_116 ) {
case V_152 : {
struct V_153 V_154 ;
void T_6 * V_78 = ( void T_6 * ) ( long ) args -> V_155 ;
V_154 . V_70 = V_4 -> V_5 . V_11 ;
V_154 . V_12 = V_4 -> V_7 . V_124 . V_156 << V_157 ;
V_154 . V_71 = V_4 -> V_88 ;
V_154 . V_77 = V_4 -> V_14 ;
F_25 ( V_4 ) ;
if ( F_79 ( V_78 , & V_154 , sizeof( V_154 ) ) )
V_18 = - V_158 ;
break;
}
case V_159 :
if ( F_51 ( V_4 -> V_7 . V_90 ) ) {
V_18 = - V_103 ;
F_25 ( V_4 ) ;
break;
}
V_4 -> V_88 = args -> V_155 & ( V_29 |
V_30 |
V_86 ) ;
V_4 -> V_89 = V_4 -> V_88 ;
if ( V_4 -> V_89 == V_29 )
V_4 -> V_89 |= V_30 ;
F_25 ( V_4 ) ;
break;
default:
F_25 ( V_4 ) ;
V_18 = - V_75 ;
}
V_78:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_80 ( struct V_33 * V_39 ,
struct V_31 * V_62 ,
struct V_160 * args )
{
struct V_9 * V_10 = V_62 -> V_67 ;
struct V_1 * V_2 ;
T_4 V_36 ;
int V_18 ;
args -> V_161 = F_81 ( V_10 , args -> V_162 ,
F_82 ( args -> V_163 , 8 ) , 0 ) ;
args -> V_11 = ( T_2 ) args -> V_161 * args -> V_164 ;
args -> V_11 = F_83 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_165 ,
V_166 ,
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
static int F_84 ( int V_167 , void * V_168 , void * V_65 )
{
struct V_1 * V_2 = V_168 ;
struct V_3 * V_50 = F_2 ( V_2 ) ;
struct V_169 * V_170 = V_65 ;
unsigned V_123 ;
const char * V_98 ;
unsigned V_171 ;
V_123 = F_69 ( V_50 -> V_7 . V_124 . V_125 ) ;
switch ( V_123 ) {
case V_29 :
V_98 = L_12 ;
break;
case V_30 :
V_98 = L_13 ;
break;
case V_86 :
default:
V_98 = L_14 ;
break;
}
F_85 ( V_170 , L_15 ,
V_167 , F_86 ( V_50 ) , V_98 ,
F_87 ( V_50 ) ) ;
V_171 = F_88 ( V_50 -> V_171 ) ;
if ( V_171 )
F_85 ( V_170 , L_16 , V_171 ) ;
F_85 ( V_170 , L_17 ) ;
return 0 ;
}
static int F_89 ( struct V_169 * V_170 , void * V_65 )
{
struct V_172 * V_173 = (struct V_172 * ) V_170 -> V_174 ;
struct V_31 * V_62 = V_173 -> V_175 -> V_62 ;
struct V_33 * V_34 ;
int V_18 ;
V_18 = F_90 ( & V_62 -> V_35 ) ;
if ( V_18 )
return V_18 ;
F_12 (file, &dev->filelist, lhead) {
struct V_176 * V_177 ;
F_91 () ;
V_177 = F_92 ( V_34 -> V_178 , V_179 ) ;
F_85 ( V_170 , L_18 , F_93 ( V_34 -> V_178 ) ,
V_177 ? V_177 -> V_180 : L_19 ) ;
F_94 () ;
F_14 ( & V_34 -> V_37 ) ;
F_95 ( & V_34 -> V_38 , F_84 , V_170 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_62 -> V_35 ) ;
return 0 ;
}
int F_96 ( struct V_9 * V_10 )
{
#if F_97 ( V_181 )
return F_98 ( V_10 , V_182 , 1 ) ;
#endif
return 0 ;
}
