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
V_4 -> V_31 = F_10 ( V_32 ) ;
F_11 ( & V_10 -> V_33 . V_34 ) ;
F_12 ( & V_4 -> V_35 , & V_10 -> V_33 . V_36 ) ;
F_13 ( & V_10 -> V_33 . V_34 ) ;
return 0 ;
}
int F_14 ( struct V_9 * V_10 )
{
F_15 ( & V_10 -> V_33 . V_36 ) ;
return 0 ;
}
void F_16 ( struct V_9 * V_10 )
{
F_17 ( V_10 ) ;
}
int F_18 ( struct V_1 * V_16 , struct V_37 * V_38 )
{
struct V_3 * V_39 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_39 -> V_10 ;
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_45 * V_46 ;
int V_18 ;
V_18 = F_19 ( V_39 , false ) ;
if ( V_18 )
return V_18 ;
V_46 = F_20 ( V_44 , V_39 ) ;
if ( ! V_46 ) {
V_46 = F_21 ( V_10 , V_44 , V_39 ) ;
} else {
++ V_46 -> V_47 ;
}
F_22 ( V_39 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_16 ,
struct V_37 * V_38 )
{
struct V_3 * V_39 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_39 -> V_10 ;
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_45 * V_46 ;
int V_18 ;
V_18 = F_19 ( V_39 , true ) ;
if ( V_18 ) {
F_24 ( V_10 -> V_48 , L_3
L_4 , V_18 ) ;
return;
}
V_46 = F_20 ( V_44 , V_39 ) ;
if ( V_46 ) {
if ( -- V_46 -> V_47 == 0 ) {
F_25 ( V_10 , V_46 ) ;
}
}
F_22 ( V_39 ) ;
}
static int F_26 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_49 ) {
V_18 = F_27 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_50 ;
}
return V_18 ;
}
int F_28 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_9 * V_10 = V_48 -> V_54 ;
union V_55 * args = V_52 ;
T_3 V_11 = args -> V_56 . V_57 ;
struct V_1 * V_2 ;
T_4 V_58 ;
bool V_15 = false ;
int V_18 ;
if ( args -> V_56 . V_59 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_56 . V_59 == V_20 )
V_11 = V_11 << V_60 ;
else if ( args -> V_56 . V_59 == V_21 )
V_11 = V_11 << V_61 ;
else if ( args -> V_56 . V_59 == V_22 )
V_11 = V_11 << V_62 ;
else {
V_18 = - V_63 ;
goto V_64;
}
}
V_11 = F_29 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_56 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_56 . V_59 ) ,
args -> V_56 . V_65 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_64;
V_18 = F_30 ( V_53 , V_2 , & V_58 ) ;
F_31 ( V_2 ) ;
if ( V_18 )
goto V_64;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_66 . V_58 = V_58 ;
return 0 ;
V_64:
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_32 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_67 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_68 ;
T_4 V_58 ;
int V_18 ;
if ( F_33 ( args -> V_69 | args -> V_11 ) )
return - V_63 ;
if ( args -> V_14 & ~ ( V_70 |
V_71 | V_72 |
V_73 ) )
return - V_63 ;
if ( ! ( args -> V_14 & V_70 ) && (
! ( args -> V_14 & V_71 ) ||
! ( args -> V_14 & V_73 ) ) ) {
return - V_74 ;
}
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_75 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_76;
V_68 = F_2 ( V_2 ) ;
V_18 = F_34 ( V_68 -> V_7 . V_77 , args -> V_69 , args -> V_14 ) ;
if ( V_18 )
goto V_78;
if ( args -> V_14 & V_73 ) {
V_18 = F_35 ( V_68 , args -> V_69 ) ;
if ( V_18 )
goto V_78;
}
if ( args -> V_14 & V_72 ) {
F_36 ( & V_32 -> V_79 -> V_80 ) ;
V_18 = F_19 ( V_68 , true ) ;
if ( V_18 ) {
F_37 ( & V_32 -> V_79 -> V_80 ) ;
goto V_78;
}
F_38 ( V_68 , V_30 ) ;
V_18 = F_39 ( & V_68 -> V_7 , & V_68 -> V_81 , true , false ) ;
F_22 ( V_68 ) ;
F_37 ( & V_32 -> V_79 -> V_80 ) ;
if ( V_18 )
goto V_78;
}
V_18 = F_30 ( V_53 , V_2 , & V_58 ) ;
F_31 ( V_2 ) ;
if ( V_18 )
goto V_76;
args -> V_58 = V_58 ;
return 0 ;
V_78:
F_31 ( V_2 ) ;
V_76:
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_40 ( struct V_37 * V_53 ,
struct V_51 * V_48 ,
T_4 V_58 , T_3 * V_82 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_41 ( V_48 , V_53 , V_58 ) ;
if ( V_2 == NULL ) {
return - V_83 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_42 ( V_4 -> V_7 . V_77 ) ||
( V_4 -> V_14 & V_84 ) ) {
F_31 ( V_2 ) ;
return - V_85 ;
}
* V_82 = F_43 ( V_4 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
int F_44 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
union V_86 * args = V_52 ;
T_4 V_58 = args -> V_56 . V_58 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_40 ( V_53 , V_48 , V_58 , & args -> V_66 . V_87 ) ;
}
unsigned long F_45 ( T_3 V_88 )
{
unsigned long V_89 ;
T_5 V_90 ;
if ( ( ( V_91 ) V_88 ) < 0 )
return V_92 ;
V_90 = F_46 ( F_47 ( V_88 ) , F_48 () ) ;
if ( F_49 ( V_90 ) < 0 )
return 0 ;
V_89 = F_50 ( F_49 ( V_90 ) ) ;
if ( V_89 > V_92 )
return V_92 - 1 ;
return V_89 ;
}
int F_51 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_9 * V_10 = V_48 -> V_54 ;
union V_93 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_58 = args -> V_56 . V_58 ;
unsigned long V_90 = F_45 ( args -> V_56 . V_90 ) ;
int V_18 = 0 ;
long V_94 ;
V_2 = F_41 ( V_48 , V_53 , V_58 ) ;
if ( V_2 == NULL ) {
return - V_83 ;
}
V_4 = F_2 ( V_2 ) ;
if ( V_90 == 0 )
V_94 = F_52 ( V_4 -> V_7 . V_95 , true ) ;
else
V_94 = F_53 ( V_4 -> V_7 . V_95 , true , true , V_90 ) ;
if ( V_94 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_66 . V_96 = ( V_94 == 0 ) ;
} else
V_18 = V_94 ;
F_31 ( V_2 ) ;
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_54 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_97 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_5 , args -> V_58 ) ;
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL )
return - V_83 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_19 ( V_4 , false ) ;
if ( F_55 ( V_18 != 0 ) )
goto V_66;
if ( args -> V_98 == V_99 ) {
F_56 ( V_4 , & args -> V_52 . V_100 ) ;
V_18 = F_57 ( V_4 , args -> V_52 . V_52 ,
sizeof( args -> V_52 . V_52 ) ,
& args -> V_52 . V_101 ,
& args -> V_52 . V_14 ) ;
} else if ( args -> V_98 == V_102 ) {
if ( args -> V_52 . V_101 > sizeof( args -> V_52 . V_52 ) ) {
V_18 = - V_63 ;
goto V_103;
}
V_18 = F_58 ( V_4 , args -> V_52 . V_100 ) ;
if ( ! V_18 )
V_18 = F_59 ( V_4 , args -> V_52 . V_52 ,
args -> V_52 . V_101 ,
args -> V_52 . V_14 ) ;
}
V_103:
F_22 ( V_4 ) ;
V_66:
F_31 ( V_2 ) ;
return V_18 ;
}
static void F_60 ( struct V_9 * V_10 ,
struct V_45 * V_46 , T_4 V_104 )
{
struct V_105 V_106 , * V_107 ;
struct V_108 V_109 ;
struct V_110 V_111 ;
struct V_112 V_35 , V_113 ;
unsigned V_114 ;
int V_18 ;
F_15 ( & V_35 ) ;
F_15 ( & V_113 ) ;
V_106 . V_68 = & V_46 -> V_68 -> V_7 ;
V_106 . V_115 = true ;
F_61 ( & V_106 . V_116 , & V_35 ) ;
F_62 ( V_46 -> V_44 , & V_35 , & V_109 ) ;
V_18 = F_63 ( & V_111 , & V_35 , true , & V_113 ) ;
if ( V_18 )
goto V_117;
F_64 ( V_46 -> V_44 , & V_113 ) ;
F_65 (entry, &list, head) {
V_114 = F_66 ( V_107 -> V_68 -> V_118 . V_119 ) ;
if ( V_114 == V_75 )
goto V_120;
}
F_65 (entry, &duplicates, head) {
V_114 = F_66 ( V_107 -> V_68 -> V_118 . V_119 ) ;
if ( V_114 == V_75 )
goto V_120;
}
V_18 = F_67 ( V_10 , V_46 -> V_44 ) ;
if ( V_18 )
goto V_120;
V_18 = F_68 ( V_10 , V_46 -> V_44 ) ;
if ( V_18 )
goto V_120;
if ( V_104 == V_121 )
V_18 = F_69 ( V_10 , V_46 , & V_46 -> V_68 -> V_7 . V_118 ) ;
V_120:
F_70 ( & V_111 , & V_35 ) ;
V_117:
if ( V_18 && V_18 != - V_28 )
F_9 ( L_6 , V_18 ) ;
}
int F_71 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_122 * args = V_52 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_40 * V_41 = V_53 -> V_42 ;
struct V_3 * V_39 ;
struct V_45 * V_46 ;
struct V_105 V_106 , V_123 ;
struct V_110 V_111 ;
struct V_112 V_35 , V_113 ;
T_4 V_124 , V_125 = 0 ;
int V_18 = 0 ;
if ( ! V_10 -> V_126 . V_127 )
return - V_128 ;
if ( args -> V_129 < V_130 ) {
F_24 ( & V_48 -> V_131 -> V_48 ,
L_7 ,
( unsigned long ) args -> V_129 ,
V_130 ) ;
return - V_63 ;
}
V_124 = ~ ( V_132 | V_133 |
V_134 | V_135 ) ;
if ( ( args -> V_14 & V_124 ) ) {
F_24 ( & V_48 -> V_131 -> V_48 , L_8 ,
args -> V_14 , V_124 ) ;
return - V_63 ;
}
switch ( args -> V_104 ) {
case V_121 :
case V_136 :
break;
default:
F_24 ( & V_48 -> V_131 -> V_48 , L_9 ,
args -> V_104 ) ;
return - V_63 ;
}
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL )
return - V_83 ;
V_39 = F_2 ( V_2 ) ;
F_15 ( & V_35 ) ;
F_15 ( & V_113 ) ;
V_106 . V_68 = & V_39 -> V_7 ;
V_106 . V_115 = true ;
F_61 ( & V_106 . V_116 , & V_35 ) ;
if ( args -> V_104 == V_121 ) {
V_123 . V_68 = & V_41 -> V_44 . V_137 -> V_7 ;
V_123 . V_115 = true ;
F_61 ( & V_123 . V_116 , & V_35 ) ;
}
V_18 = F_63 ( & V_111 , & V_35 , true , & V_113 ) ;
if ( V_18 ) {
F_31 ( V_2 ) ;
return V_18 ;
}
V_46 = F_20 ( & V_41 -> V_44 , V_39 ) ;
if ( ! V_46 ) {
F_70 ( & V_111 , & V_35 ) ;
F_31 ( V_2 ) ;
return - V_83 ;
}
switch ( args -> V_104 ) {
case V_121 :
if ( args -> V_14 & V_133 )
V_125 |= V_138 ;
if ( args -> V_14 & V_134 )
V_125 |= V_139 ;
if ( args -> V_14 & V_135 )
V_125 |= V_140 ;
V_18 = F_72 ( V_10 , V_46 , args -> V_129 ,
args -> V_141 , args -> V_142 ,
V_125 ) ;
break;
case V_136 :
V_18 = F_73 ( V_10 , V_46 , args -> V_129 ) ;
break;
default:
break;
}
F_70 ( & V_111 , & V_35 ) ;
if ( ! V_18 && ! ( args -> V_14 & V_132 ) &&
! V_143 )
F_60 ( V_10 , V_46 , args -> V_104 ) ;
F_31 ( V_2 ) ;
return V_18 ;
}
int F_74 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_144 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL ) {
return - V_83 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_19 ( V_4 , false ) ;
if ( F_55 ( V_18 ) )
goto V_66;
switch ( args -> V_98 ) {
case V_145 : {
struct V_146 V_147 ;
void T_6 * V_66 = ( void T_6 * ) ( long ) args -> V_148 ;
V_147 . V_57 = V_4 -> V_5 . V_11 ;
V_147 . V_12 = V_4 -> V_7 . V_118 . V_149 << V_150 ;
V_147 . V_59 = V_4 -> V_13 ;
V_147 . V_65 = V_4 -> V_14 ;
F_22 ( V_4 ) ;
if ( F_75 ( V_66 , & V_147 , sizeof( V_147 ) ) )
V_18 = - V_151 ;
break;
}
case V_152 :
if ( F_42 ( V_4 -> V_7 . V_77 ) ) {
V_18 = - V_85 ;
F_22 ( V_4 ) ;
break;
}
V_4 -> V_13 = args -> V_148 & ( V_29 |
V_30 |
V_75 ) ;
F_22 ( V_4 ) ;
break;
default:
F_22 ( V_4 ) ;
V_18 = - V_63 ;
}
V_66:
F_31 ( V_2 ) ;
return V_18 ;
}
int F_76 ( struct V_37 * V_38 ,
struct V_51 * V_48 ,
struct V_153 * args )
{
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_1 * V_2 ;
T_4 V_58 ;
int V_18 ;
args -> V_154 = F_77 ( V_10 , args -> V_155 , args -> V_156 , 0 ) * ( ( args -> V_156 + 1 ) / 8 ) ;
args -> V_11 = ( T_2 ) args -> V_154 * args -> V_157 ;
args -> V_11 = F_78 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_158 ,
V_159 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_30 ( V_38 , V_2 , & V_58 ) ;
F_31 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_58 = V_58 ;
return 0 ;
}
static int F_79 ( struct V_160 * V_161 , void * V_52 )
{
struct V_162 * V_163 = (struct V_162 * ) V_161 -> V_164 ;
struct V_51 * V_48 = V_163 -> V_165 -> V_48 ;
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_3 * V_39 ;
unsigned V_166 = 0 ;
F_11 ( & V_10 -> V_33 . V_34 ) ;
F_65 (rbo, &adev->gem.objects, list) {
unsigned V_114 ;
const char * V_81 ;
V_114 = F_66 ( V_39 -> V_7 . V_118 . V_119 ) ;
switch ( V_114 ) {
case V_29 :
V_81 = L_10 ;
break;
case V_30 :
V_81 = L_11 ;
break;
case V_75 :
default:
V_81 = L_12 ;
break;
}
F_80 ( V_161 , L_13 ,
V_166 , F_81 ( V_39 ) >> 10 , F_81 ( V_39 ) >> 20 ,
V_81 , ( unsigned long ) V_39 -> V_31 ) ;
V_166 ++ ;
}
F_13 ( & V_10 -> V_33 . V_34 ) ;
return 0 ;
}
int F_82 ( struct V_9 * V_10 )
{
#if F_83 ( V_167 )
return F_84 ( V_10 , V_168 , 1 ) ;
#endif
return 0 ;
}
