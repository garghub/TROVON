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
if ( V_18 ) {
return V_18 ;
}
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
F_29 ( & V_10 -> V_59 ) ;
if ( args -> V_56 . V_60 & ( V_20 |
V_21 | V_22 ) ) {
V_15 = true ;
if ( args -> V_56 . V_60 == V_20 )
V_11 = V_11 << V_61 ;
else if ( args -> V_56 . V_60 == V_21 )
V_11 = V_11 << V_62 ;
else if ( args -> V_56 . V_60 == V_22 )
V_11 = V_11 << V_63 ;
else {
V_18 = - V_64 ;
goto V_65;
}
}
V_11 = F_30 ( V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , V_11 , args -> V_56 . V_12 ,
( T_1 ) ( 0xffffffff & args -> V_56 . V_60 ) ,
args -> V_56 . V_66 ,
V_15 , & V_2 ) ;
if ( V_18 )
goto V_65;
V_18 = F_31 ( V_53 , V_2 , & V_58 ) ;
F_32 ( V_2 ) ;
if ( V_18 )
goto V_65;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_67 . V_58 = V_58 ;
F_33 ( & V_10 -> V_59 ) ;
return 0 ;
V_65:
F_33 ( & V_10 -> V_59 ) ;
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_34 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_68 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_69 ;
T_4 V_58 ;
int V_18 ;
if ( F_35 ( args -> V_70 | args -> V_11 ) )
return - V_64 ;
if ( args -> V_14 & ~ ( V_71 |
V_72 | V_73 |
V_74 ) )
return - V_64 ;
if ( ! ( args -> V_14 & V_72 ) ||
! ( args -> V_14 & V_74 ) ) {
return - V_75 ;
}
F_29 ( & V_10 -> V_59 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_76 , 0 ,
0 , & V_2 ) ;
if ( V_18 )
goto V_77;
V_69 = F_2 ( V_2 ) ;
V_18 = F_36 ( V_69 -> V_7 . V_78 , args -> V_70 , args -> V_14 ) ;
if ( V_18 )
goto V_79;
if ( args -> V_14 & V_74 ) {
V_18 = F_37 ( V_69 , args -> V_70 ) ;
if ( V_18 )
goto V_79;
}
if ( args -> V_14 & V_73 ) {
F_29 ( & V_32 -> V_80 -> V_81 ) ;
V_18 = F_19 ( V_69 , true ) ;
if ( V_18 ) {
F_33 ( & V_32 -> V_80 -> V_81 ) ;
goto V_79;
}
F_38 ( V_69 , V_30 ) ;
V_18 = F_39 ( & V_69 -> V_7 , & V_69 -> V_82 , true , false ) ;
F_22 ( V_69 ) ;
F_33 ( & V_32 -> V_80 -> V_81 ) ;
if ( V_18 )
goto V_79;
}
V_18 = F_31 ( V_53 , V_2 , & V_58 ) ;
F_32 ( V_2 ) ;
if ( V_18 )
goto V_77;
args -> V_58 = V_58 ;
F_33 ( & V_10 -> V_59 ) ;
return 0 ;
V_79:
F_32 ( V_2 ) ;
V_77:
F_33 ( & V_10 -> V_59 ) ;
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_40 ( struct V_37 * V_53 ,
struct V_51 * V_48 ,
T_4 V_58 , T_3 * V_83 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_41 ( V_48 , V_53 , V_58 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_42 ( V_4 -> V_7 . V_78 ) ||
( V_4 -> V_14 & V_85 ) ) {
F_32 ( V_2 ) ;
return - V_86 ;
}
* V_83 = F_43 ( V_4 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
int F_44 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
union V_87 * args = V_52 ;
T_4 V_58 = args -> V_56 . V_58 ;
memset ( args , 0 , sizeof( * args ) ) ;
return F_40 ( V_53 , V_48 , V_58 , & args -> V_67 . V_88 ) ;
}
unsigned long F_45 ( T_3 V_89 )
{
unsigned long V_90 ;
T_5 V_91 ;
if ( ( ( V_92 ) V_89 ) < 0 )
return V_93 ;
V_91 = F_46 ( F_47 ( V_89 ) , F_48 () ) ;
if ( F_49 ( V_91 ) < 0 )
return 0 ;
V_90 = F_50 ( F_49 ( V_91 ) ) ;
if ( V_90 > V_93 )
return V_93 - 1 ;
return V_90 ;
}
int F_51 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_9 * V_10 = V_48 -> V_54 ;
union V_94 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_58 = args -> V_56 . V_58 ;
unsigned long V_91 = F_45 ( args -> V_56 . V_91 ) ;
int V_18 = 0 ;
long V_95 ;
V_2 = F_41 ( V_48 , V_53 , V_58 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
if ( V_91 == 0 )
V_95 = F_52 ( V_4 -> V_7 . V_96 , true ) ;
else
V_95 = F_53 ( V_4 -> V_7 . V_96 , true , true , V_91 ) ;
if ( V_95 >= 0 ) {
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_67 . V_97 = ( V_95 == 0 ) ;
} else
V_18 = V_95 ;
F_32 ( V_2 ) ;
V_18 = F_26 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_54 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_98 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = - 1 ;
F_7 ( L_5 , args -> V_58 ) ;
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL )
return - V_84 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_19 ( V_4 , false ) ;
if ( F_55 ( V_18 != 0 ) )
goto V_67;
if ( args -> V_99 == V_100 ) {
F_56 ( V_4 , & args -> V_52 . V_101 ) ;
V_18 = F_57 ( V_4 , args -> V_52 . V_52 ,
sizeof( args -> V_52 . V_52 ) ,
& args -> V_52 . V_102 ,
& args -> V_52 . V_14 ) ;
} else if ( args -> V_99 == V_103 ) {
if ( args -> V_52 . V_102 > sizeof( args -> V_52 . V_52 ) ) {
V_18 = - V_64 ;
goto V_104;
}
V_18 = F_58 ( V_4 , args -> V_52 . V_101 ) ;
if ( ! V_18 )
V_18 = F_59 ( V_4 , args -> V_52 . V_52 ,
args -> V_52 . V_102 ,
args -> V_52 . V_14 ) ;
}
V_104:
F_22 ( V_4 ) ;
V_67:
F_32 ( V_2 ) ;
return V_18 ;
}
static void F_60 ( struct V_9 * V_10 ,
struct V_45 * V_46 , T_4 V_105 )
{
struct V_106 V_107 , * V_108 ;
struct V_109 * V_110 ;
struct V_111 V_112 ;
struct V_113 V_35 , V_114 ;
unsigned V_115 ;
int V_18 ;
F_15 ( & V_35 ) ;
F_15 ( & V_114 ) ;
V_107 . V_69 = & V_46 -> V_69 -> V_7 ;
V_107 . V_116 = true ;
F_61 ( & V_107 . V_117 , & V_35 ) ;
V_110 = F_62 ( V_10 , V_46 -> V_44 , & V_35 ) ;
if ( ! V_110 )
return;
V_18 = F_63 ( & V_112 , & V_35 , true , & V_114 ) ;
if ( V_18 )
goto V_118;
F_64 (entry, &list, head) {
V_115 = F_65 ( V_108 -> V_69 -> V_119 . V_120 ) ;
if ( V_115 == V_76 )
goto V_121;
}
F_11 ( & V_46 -> V_44 -> V_34 ) ;
V_18 = F_66 ( V_10 , V_46 -> V_44 ) ;
if ( V_18 )
goto V_65;
if ( V_105 == V_122 )
V_18 = F_67 ( V_10 , V_46 , & V_46 -> V_69 -> V_7 . V_119 ) ;
V_65:
F_13 ( & V_46 -> V_44 -> V_34 ) ;
V_121:
F_68 ( & V_112 , & V_35 ) ;
V_118:
F_69 ( V_110 ) ;
if ( V_18 && V_18 != - V_28 )
F_9 ( L_6 , V_18 ) ;
}
int F_70 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_123 * args = V_52 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_40 * V_41 = V_53 -> V_42 ;
struct V_3 * V_39 ;
struct V_45 * V_46 ;
T_4 V_124 , V_125 = 0 ;
int V_18 = 0 ;
if ( ! V_10 -> V_126 . V_127 )
return - V_128 ;
if ( args -> V_129 < V_130 ) {
F_24 ( & V_48 -> V_131 -> V_48 ,
L_7 ,
( unsigned long ) args -> V_129 ,
V_130 ) ;
return - V_64 ;
}
V_124 = ~ ( V_132 | V_133 |
V_134 | V_135 ) ;
if ( ( args -> V_14 & V_124 ) ) {
F_24 ( & V_48 -> V_131 -> V_48 , L_8 ,
args -> V_14 , V_124 ) ;
return - V_64 ;
}
switch ( args -> V_105 ) {
case V_122 :
case V_136 :
break;
default:
F_24 ( & V_48 -> V_131 -> V_48 , L_9 ,
args -> V_105 ) ;
return - V_64 ;
}
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL )
return - V_84 ;
V_39 = F_2 ( V_2 ) ;
V_18 = F_19 ( V_39 , false ) ;
if ( V_18 ) {
F_32 ( V_2 ) ;
return V_18 ;
}
V_46 = F_20 ( & V_41 -> V_44 , V_39 ) ;
if ( ! V_46 ) {
F_22 ( V_39 ) ;
return - V_84 ;
}
switch ( args -> V_105 ) {
case V_122 :
if ( args -> V_14 & V_133 )
V_125 |= V_137 ;
if ( args -> V_14 & V_134 )
V_125 |= V_138 ;
if ( args -> V_14 & V_135 )
V_125 |= V_139 ;
V_18 = F_71 ( V_10 , V_46 , args -> V_129 ,
args -> V_140 , args -> V_141 ,
V_125 ) ;
break;
case V_136 :
V_18 = F_72 ( V_10 , V_46 , args -> V_129 ) ;
break;
default:
break;
}
if ( ! V_18 && ! ( args -> V_14 & V_132 ) )
F_60 ( V_10 , V_46 , args -> V_105 ) ;
F_32 ( V_2 ) ;
return V_18 ;
}
int F_73 ( struct V_51 * V_48 , void * V_52 ,
struct V_37 * V_53 )
{
struct V_142 * args = V_52 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_41 ( V_48 , V_53 , args -> V_58 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_19 ( V_4 , false ) ;
if ( F_55 ( V_18 ) )
goto V_67;
switch ( args -> V_99 ) {
case V_143 : {
struct V_144 V_145 ;
void T_6 * V_67 = ( void T_6 * ) ( long ) args -> V_146 ;
V_145 . V_57 = V_4 -> V_5 . V_11 ;
V_145 . V_12 = V_4 -> V_7 . V_119 . V_147 << V_148 ;
V_145 . V_60 = V_4 -> V_13 ;
V_145 . V_66 = V_4 -> V_14 ;
F_22 ( V_4 ) ;
if ( F_74 ( V_67 , & V_145 , sizeof( V_145 ) ) )
V_18 = - V_149 ;
break;
}
case V_150 :
if ( F_42 ( V_4 -> V_7 . V_78 ) ) {
V_18 = - V_86 ;
F_22 ( V_4 ) ;
break;
}
V_4 -> V_13 = args -> V_146 & ( V_29 |
V_30 |
V_76 ) ;
F_22 ( V_4 ) ;
break;
default:
F_22 ( V_4 ) ;
V_18 = - V_64 ;
}
V_67:
F_32 ( V_2 ) ;
return V_18 ;
}
int F_75 ( struct V_37 * V_38 ,
struct V_51 * V_48 ,
struct V_151 * args )
{
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_1 * V_2 ;
T_4 V_58 ;
int V_18 ;
args -> V_152 = F_76 ( V_10 , args -> V_153 , args -> V_154 , 0 ) * ( ( args -> V_154 + 1 ) / 8 ) ;
args -> V_11 = ( T_2 ) args -> V_152 * args -> V_155 ;
args -> V_11 = F_77 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_29 ,
V_156 ,
V_157 ,
& V_2 ) ;
if ( V_18 )
return - V_26 ;
V_18 = F_31 ( V_38 , V_2 , & V_58 ) ;
F_32 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_58 = V_58 ;
return 0 ;
}
static int F_78 ( struct V_158 * V_159 , void * V_52 )
{
struct V_160 * V_161 = (struct V_160 * ) V_159 -> V_162 ;
struct V_51 * V_48 = V_161 -> V_163 -> V_48 ;
struct V_9 * V_10 = V_48 -> V_54 ;
struct V_3 * V_39 ;
unsigned V_164 = 0 ;
F_11 ( & V_10 -> V_33 . V_34 ) ;
F_64 (rbo, &adev->gem.objects, list) {
unsigned V_115 ;
const char * V_82 ;
V_115 = F_65 ( V_39 -> V_7 . V_119 . V_120 ) ;
switch ( V_115 ) {
case V_29 :
V_82 = L_10 ;
break;
case V_30 :
V_82 = L_11 ;
break;
case V_76 :
default:
V_82 = L_12 ;
break;
}
F_79 ( V_159 , L_13 ,
V_164 , F_80 ( V_39 ) >> 10 , F_80 ( V_39 ) >> 20 ,
V_82 , ( unsigned long ) V_39 -> V_31 ) ;
V_164 ++ ;
}
F_13 ( & V_10 -> V_33 . V_34 ) ;
return 0 ;
}
int F_81 ( struct V_9 * V_10 )
{
#if F_82 ( V_165 )
return F_83 ( V_10 , V_166 , 1 ) ;
#endif
return 0 ;
}
