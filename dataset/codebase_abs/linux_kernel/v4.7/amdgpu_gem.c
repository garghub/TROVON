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
int F_20 ( struct V_1 * V_16 , struct V_33 * V_39 )
{
struct V_3 * V_40 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_40 -> V_10 ;
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_44 * V_45 = & V_42 -> V_45 ;
struct V_46 * V_47 ;
int V_18 ;
V_18 = F_21 ( V_40 , false ) ;
if ( V_18 )
return V_18 ;
V_47 = F_22 ( V_45 , V_40 ) ;
if ( ! V_47 ) {
V_47 = F_23 ( V_10 , V_45 , V_40 ) ;
} else {
++ V_47 -> V_48 ;
}
F_24 ( V_40 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_16 ,
struct V_33 * V_39 )
{
struct V_3 * V_49 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_49 -> V_10 ;
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_44 * V_45 = & V_42 -> V_45 ;
struct V_50 V_51 ;
struct V_52 V_53 , V_54 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
struct V_46 * V_47 ;
int V_18 ;
F_26 ( & V_53 ) ;
F_26 ( & V_54 ) ;
V_56 . V_49 = & V_49 -> V_7 ;
V_56 . V_59 = true ;
F_27 ( & V_56 . V_60 , & V_53 ) ;
F_28 ( V_45 , & V_53 , & V_51 ) ;
V_18 = F_29 ( & V_58 , & V_53 , false , & V_54 ) ;
if ( V_18 ) {
F_30 ( V_10 -> V_61 , L_5
L_6 , V_18 ) ;
return;
}
V_47 = F_22 ( V_45 , V_49 ) ;
if ( V_47 ) {
if ( -- V_47 -> V_48 == 0 ) {
F_31 ( V_10 , V_47 ) ;
}
}
F_32 ( & V_58 , & V_53 ) ;
}
static int F_33 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_62 ) {
V_18 = F_34 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_63 ;
}
return V_18 ;
}
int F_35 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_9 * V_10 = V_61 -> V_66 ;
union V_67 * args = V_64 ;
T_3 V_11 = args -> V_68 . V_69 ;
struct V_1 * V_2 ;
T_4 V_36 ;
bool V_15 = false ;
int V_18 ;
if ( args -> V_68 . V_70 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_68 . V_70 == V_20 )
V_11 = V_11 << V_71 ;
else if ( args -> V_68 . V_70 == V_21 )
V_11 = V_11 << V_72 ;
else if ( args -> V_68 . V_70 == V_22 )
V_11 = V_11 << V_73 ;
else {
V_18 = - V_74 ;
goto V_75;
}
}
V_11 = F_36 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_68 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_68 . V_70 ) ,
args -> V_68 . V_76 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_75;
V_18 = F_37 ( V_65 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_75;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_77 . V_36 = V_36 ;
return 0 ;
V_75:
V_18 = F_33 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_38 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_9 * V_10 = V_61 -> V_66 ;
struct V_78 * args = V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_49 ;
T_4 V_36 ;
int V_18 ;
if ( F_39 ( args -> V_79 | args -> V_11 ) )
return - V_74 ;
if ( args -> V_14 & ~ ( V_80 |
V_81 | V_82 |
V_83 ) )
return - V_74 ;
if ( ! ( args -> V_14 & V_80 ) &&
! ( args -> V_14 & V_83 ) ) {
return - V_84 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_85 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_86;
V_49 = F_2 ( V_2 ) ;
V_49 -> V_87 = V_30 ;
V_49 -> V_88 = V_30 ;
V_18 = F_40 ( V_49 -> V_7 . V_89 , args -> V_79 , args -> V_14 ) ;
if ( V_18 )
goto V_90;
if ( args -> V_14 & V_83 ) {
V_18 = F_41 ( V_49 , args -> V_79 ) ;
if ( V_18 )
goto V_90;
}
if ( args -> V_14 & V_82 ) {
F_42 ( & V_91 -> V_92 -> V_93 ) ;
V_18 = F_43 ( V_49 -> V_7 . V_89 ,
V_49 -> V_7 . V_89 -> V_94 ) ;
if ( V_18 )
goto V_95;
V_18 = F_21 ( V_49 , true ) ;
if ( V_18 )
goto V_96;
F_44 ( V_49 , V_30 ) ;
V_18 = F_45 ( & V_49 -> V_7 , & V_49 -> V_97 , true , false ) ;
F_24 ( V_49 ) ;
if ( V_18 )
goto V_96;
F_46 ( & V_91 -> V_92 -> V_93 ) ;
}
V_18 = F_37 ( V_65 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 )
goto V_86;
args -> V_36 = V_36 ;
return 0 ;
V_96:
F_47 ( V_49 -> V_7 . V_89 -> V_94 , V_49 -> V_7 . V_89 -> V_98 , false ) ;
V_95:
F_46 ( & V_91 -> V_92 -> V_93 ) ;
V_90:
F_16 ( V_2 ) ;
V_86:
V_18 = F_33 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_48 ( struct V_33 * V_65 ,
struct V_31 * V_61 ,
T_4 V_36 , T_3 * V_99 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_49 ( V_65 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_50 ( V_4 -> V_7 . V_89 ) ||
( V_4 -> V_14 & V_101 ) ) {
F_16 ( V_2 ) ;
return - V_102 ;
}
* V_99 = F_51 ( V_4 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
union V_103 * args = V_64 ;
T_4 V_36 = args -> V_68 . V_36 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_48 ( V_65 , V_61 , V_36 , & args -> V_77 . V_104 ) ;
}
unsigned long F_53 ( T_3 V_105 )
{
unsigned long V_106 ;
T_5 V_107 ;
if ( ( ( V_108 ) V_105 ) < 0 )
return V_109 ;
V_107 = F_54 ( F_55 ( V_105 ) , F_56 () ) ;
if ( F_57 ( V_107 ) < 0 )
return 0 ;
V_106 = F_58 ( F_57 ( V_107 ) ) ;
if ( V_106 > V_109 )
return V_109 - 1 ;
return V_106 ;
}
int F_59 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_9 * V_10 = V_61 -> V_66 ;
union V_110 * args = V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_36 = args -> V_68 . V_36 ;
unsigned long V_107 = F_53 ( args -> V_68 . V_107 ) ;
int V_18 = 0 ;
long V_111 ;
V_2 = F_49 ( V_65 , V_36 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
if ( V_107 == 0 )
V_111 = F_60 ( V_4 -> V_7 . V_112 , true ) ;
else
V_111 = F_61 ( V_4 -> V_7 . V_112 , true , true , V_107 ) ;
if ( V_111 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_77 . V_113 = ( V_111 == 0 ) ;
} else
V_18 = V_111 ;
F_16 ( V_2 ) ;
V_18 = F_33 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_62 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_114 * args = V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_7 , args -> V_36 ) ;
V_2 = F_49 ( V_65 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_4 , false ) ;
if ( F_63 ( V_18 != 0 ) )
goto V_77;
if ( args -> V_115 == V_116 ) {
F_64 ( V_4 , & args -> V_64 . V_117 ) ;
V_18 = F_65 ( V_4 , args -> V_64 . V_64 ,
sizeof( args -> V_64 . V_64 ) ,
& args -> V_64 . V_118 ,
& args -> V_64 . V_14 ) ;
} else if ( args -> V_115 == V_119 ) {
if ( args -> V_64 . V_118 > sizeof( args -> V_64 . V_64 ) ) {
V_18 = - V_74 ;
goto V_120;
}
V_18 = F_66 ( V_4 , args -> V_64 . V_117 ) ;
if ( ! V_18 )
V_18 = F_67 ( V_4 , args -> V_64 . V_64 ,
args -> V_64 . V_118 ,
args -> V_64 . V_14 ) ;
}
V_120:
F_24 ( V_4 ) ;
V_77:
F_16 ( V_2 ) ;
return V_18 ;
}
static void F_68 ( struct V_9 * V_10 ,
struct V_46 * V_47 , T_4 V_121 )
{
struct V_55 V_56 , * V_122 ;
struct V_50 V_51 ;
struct V_57 V_58 ;
struct V_52 V_53 , V_54 ;
unsigned V_123 ;
int V_18 ;
F_26 ( & V_53 ) ;
F_26 ( & V_54 ) ;
V_56 . V_49 = & V_47 -> V_49 -> V_7 ;
V_56 . V_59 = true ;
F_27 ( & V_56 . V_60 , & V_53 ) ;
F_28 ( V_47 -> V_45 , & V_53 , & V_51 ) ;
V_18 = F_29 ( & V_58 , & V_53 , true , & V_54 ) ;
if ( V_18 )
goto V_124;
F_69 ( V_47 -> V_45 , & V_54 ) ;
F_12 (entry, &list, head) {
V_123 = F_70 ( V_122 -> V_49 -> V_125 . V_126 ) ;
if ( V_123 == V_85 )
goto V_127;
}
F_12 (entry, &duplicates, head) {
V_123 = F_70 ( V_122 -> V_49 -> V_125 . V_126 ) ;
if ( V_123 == V_85 )
goto V_127;
}
V_18 = F_71 ( V_10 , V_47 -> V_45 ) ;
if ( V_18 )
goto V_127;
V_18 = F_72 ( V_10 , V_47 -> V_45 ) ;
if ( V_18 )
goto V_127;
if ( V_121 == V_128 )
V_18 = F_73 ( V_10 , V_47 , & V_47 -> V_49 -> V_7 . V_125 ) ;
V_127:
F_32 ( & V_58 , & V_53 ) ;
V_124:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_8 , V_18 ) ;
}
int F_74 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_129 * args = V_64 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_61 -> V_66 ;
struct V_41 * V_42 = V_65 -> V_43 ;
struct V_3 * V_40 ;
struct V_46 * V_47 ;
struct V_55 V_56 , V_130 ;
struct V_57 V_58 ;
struct V_52 V_53 , V_54 ;
T_4 V_131 , V_132 = 0 ;
int V_18 = 0 ;
if ( ! V_10 -> V_133 . V_134 )
return - V_135 ;
if ( args -> V_136 < V_137 ) {
F_30 ( & V_61 -> V_138 -> V_61 ,
L_9 ,
( unsigned long ) args -> V_136 ,
V_137 ) ;
return - V_74 ;
}
V_131 = ~ ( V_139 | V_140 |
V_141 | V_142 ) ;
if ( ( args -> V_14 & V_131 ) ) {
F_30 ( & V_61 -> V_138 -> V_61 , L_10 ,
args -> V_14 , V_131 ) ;
return - V_74 ;
}
switch ( args -> V_121 ) {
case V_128 :
case V_143 :
break;
default:
F_30 ( & V_61 -> V_138 -> V_61 , L_11 ,
args -> V_121 ) ;
return - V_74 ;
}
V_2 = F_49 ( V_65 , args -> V_36 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_40 = F_2 ( V_2 ) ;
F_26 ( & V_53 ) ;
F_26 ( & V_54 ) ;
V_56 . V_49 = & V_40 -> V_7 ;
V_56 . V_59 = true ;
F_27 ( & V_56 . V_60 , & V_53 ) ;
V_130 . V_49 = & V_42 -> V_45 . V_144 -> V_7 ;
V_130 . V_59 = true ;
F_27 ( & V_130 . V_60 , & V_53 ) ;
V_18 = F_29 ( & V_58 , & V_53 , true , & V_54 ) ;
if ( V_18 ) {
F_16 ( V_2 ) ;
return V_18 ;
}
V_47 = F_22 ( & V_42 -> V_45 , V_40 ) ;
if ( ! V_47 ) {
F_32 ( & V_58 , & V_53 ) ;
F_16 ( V_2 ) ;
return - V_100 ;
}
switch ( args -> V_121 ) {
case V_128 :
if ( args -> V_14 & V_140 )
V_132 |= V_145 ;
if ( args -> V_14 & V_141 )
V_132 |= V_146 ;
if ( args -> V_14 & V_142 )
V_132 |= V_147 ;
V_18 = F_75 ( V_10 , V_47 , args -> V_136 ,
args -> V_148 , args -> V_149 ,
V_132 ) ;
break;
case V_143 :
V_18 = F_76 ( V_10 , V_47 , args -> V_136 ) ;
break;
default:
break;
}
F_32 ( & V_58 , & V_53 ) ;
if ( ! V_18 && ! ( args -> V_14 & V_139 ) &&
! V_150 )
F_68 ( V_10 , V_47 , args -> V_121 ) ;
F_16 ( V_2 ) ;
return V_18 ;
}
int F_77 ( struct V_31 * V_61 , void * V_64 ,
struct V_33 * V_65 )
{
struct V_151 * args = V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_49 ( V_65 , args -> V_36 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_4 , false ) ;
if ( F_63 ( V_18 ) )
goto V_77;
switch ( args -> V_115 ) {
case V_152 : {
struct V_153 V_154 ;
void T_6 * V_77 = ( void T_6 * ) ( long ) args -> V_155 ;
V_154 . V_69 = V_4 -> V_5 . V_11 ;
V_154 . V_12 = V_4 -> V_7 . V_125 . V_156 << V_157 ;
V_154 . V_70 = V_4 -> V_87 ;
V_154 . V_76 = V_4 -> V_14 ;
F_24 ( V_4 ) ;
if ( F_78 ( V_77 , & V_154 , sizeof( V_154 ) ) )
V_18 = - V_158 ;
break;
}
case V_159 :
if ( F_50 ( V_4 -> V_7 . V_89 ) ) {
V_18 = - V_102 ;
F_24 ( V_4 ) ;
break;
}
V_4 -> V_87 = args -> V_155 & ( V_29 |
V_30 |
V_85 ) ;
V_4 -> V_88 = V_4 -> V_87 ;
if ( V_4 -> V_88 == V_29 )
V_4 -> V_88 |= V_30 ;
F_24 ( V_4 ) ;
break;
default:
F_24 ( V_4 ) ;
V_18 = - V_74 ;
}
V_77:
F_16 ( V_2 ) ;
return V_18 ;
}
int F_79 ( struct V_33 * V_39 ,
struct V_31 * V_61 ,
struct V_160 * args )
{
struct V_9 * V_10 = V_61 -> V_66 ;
struct V_1 * V_2 ;
T_4 V_36 ;
int V_18 ;
args -> V_161 = F_80 ( V_10 , args -> V_162 , args -> V_163 , 0 ) * ( ( args -> V_163 + 1 ) / 8 ) ;
args -> V_11 = ( T_2 ) args -> V_161 * args -> V_164 ;
args -> V_11 = F_81 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_165 ,
V_166 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_37 ( V_39 , V_2 , & V_36 ) ;
F_16 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_36 = V_36 ;
return 0 ;
}
static int F_82 ( int V_167 , void * V_168 , void * V_64 )
{
struct V_1 * V_2 = V_168 ;
struct V_3 * V_49 = F_2 ( V_2 ) ;
struct V_169 * V_170 = V_64 ;
unsigned V_123 ;
const char * V_97 ;
unsigned V_171 ;
V_123 = F_70 ( V_49 -> V_7 . V_125 . V_126 ) ;
switch ( V_123 ) {
case V_29 :
V_97 = L_12 ;
break;
case V_30 :
V_97 = L_13 ;
break;
case V_85 :
default:
V_97 = L_14 ;
break;
}
F_83 ( V_170 , L_15 ,
V_167 , F_84 ( V_49 ) , V_97 ,
F_85 ( V_49 ) ) ;
V_171 = F_86 ( V_49 -> V_171 ) ;
if ( V_171 )
F_83 ( V_170 , L_16 , V_171 ) ;
F_83 ( V_170 , L_17 ) ;
return 0 ;
}
static int F_87 ( struct V_169 * V_170 , void * V_64 )
{
struct V_172 * V_173 = (struct V_172 * ) V_170 -> V_174 ;
struct V_31 * V_61 = V_173 -> V_175 -> V_61 ;
struct V_33 * V_34 ;
int V_18 ;
V_18 = F_88 ( & V_61 -> V_35 ) ;
if ( V_18 )
return V_18 ;
F_12 (file, &dev->filelist, lhead) {
struct V_176 * V_177 ;
F_89 () ;
V_177 = F_90 ( V_34 -> V_178 , V_179 ) ;
F_83 ( V_170 , L_18 , F_91 ( V_34 -> V_178 ) ,
V_177 ? V_177 -> V_180 : L_19 ) ;
F_92 () ;
F_14 ( & V_34 -> V_37 ) ;
F_93 ( & V_34 -> V_38 , F_82 , V_170 ) ;
F_18 ( & V_34 -> V_37 ) ;
}
F_19 ( & V_61 -> V_35 ) ;
return 0 ;
}
int F_94 ( struct V_9 * V_10 )
{
#if F_95 ( V_181 )
return F_96 ( V_10 , V_182 , 1 ) ;
#endif
return 0 ;
}
