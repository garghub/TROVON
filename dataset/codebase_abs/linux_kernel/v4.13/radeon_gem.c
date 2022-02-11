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
int V_12 , int V_13 ,
T_1 V_14 , bool V_15 ,
struct V_1 * * V_16 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_18 ;
* V_16 = NULL ;
if ( V_12 < V_19 ) {
V_12 = V_19 ;
}
V_17 = V_10 -> V_20 . V_21 - V_10 -> V_22 ;
if ( V_11 > V_17 ) {
F_7 ( L_1 ,
V_11 >> 20 , V_17 >> 20 ) ;
return - V_23 ;
}
V_24:
V_18 = F_8 ( V_10 , V_11 , V_12 , V_15 , V_13 ,
V_14 , NULL , NULL , & V_4 ) ;
if ( V_18 ) {
if ( V_18 != - V_25 ) {
if ( V_13 == V_26 ) {
V_13 |= V_27 ;
goto V_24;
}
F_9 ( L_2 ,
V_11 , V_13 , V_12 , V_18 ) ;
}
return V_18 ;
}
* V_16 = & V_4 -> V_5 ;
V_4 -> V_28 = F_10 ( V_29 ) ;
F_11 ( & V_10 -> V_30 . V_31 ) ;
F_12 ( & V_4 -> V_32 , & V_10 -> V_30 . V_33 ) ;
F_13 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_2 V_34 , T_2 V_35 )
{
struct V_3 * V_4 ;
T_2 V_36 ;
long V_18 ;
V_4 = F_2 ( V_2 ) ;
V_36 = V_35 ;
if ( ! V_36 ) {
V_36 = V_34 ;
}
if ( ! V_36 ) {
F_15 ( L_3 ) ;
return 0 ;
}
if ( V_36 == V_37 ) {
V_18 = F_16 ( V_4 -> V_7 . V_38 , true , true , 30 * V_39 ) ;
if ( ! V_18 )
V_18 = - V_40 ;
if ( V_18 < 0 && V_18 != - V_41 ) {
F_17 ( L_4 , V_18 ) ;
return V_18 ;
}
}
if ( V_36 == V_26 && V_4 -> V_42 ) {
return - V_43 ;
}
return 0 ;
}
int F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_30 . V_33 ) ;
return 0 ;
}
void F_20 ( struct V_9 * V_10 )
{
F_21 ( V_10 ) ;
}
int F_22 ( struct V_1 * V_16 , struct V_44 * V_45 )
{
struct V_3 * V_46 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
struct V_52 * V_53 ;
int V_18 ;
if ( ( V_10 -> V_54 < V_55 ) ||
( ! V_10 -> V_56 ) ) {
return 0 ;
}
V_18 = F_23 ( V_46 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_53 = F_24 ( V_51 , V_46 ) ;
if ( ! V_53 ) {
V_53 = F_25 ( V_10 , V_51 , V_46 ) ;
} else {
++ V_53 -> V_57 ;
}
F_26 ( V_46 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_16 ,
struct V_44 * V_45 )
{
struct V_3 * V_46 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
struct V_52 * V_53 ;
int V_18 ;
if ( ( V_10 -> V_54 < V_55 ) ||
( ! V_10 -> V_56 ) ) {
return;
}
V_18 = F_23 ( V_46 , true ) ;
if ( V_18 ) {
F_28 ( V_10 -> V_58 , L_5
L_6 , V_18 ) ;
return;
}
V_53 = F_24 ( V_51 , V_46 ) ;
if ( V_53 ) {
if ( -- V_53 -> V_57 == 0 ) {
F_29 ( V_10 , V_53 ) ;
}
}
F_26 ( V_46 ) ;
}
static int F_30 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_59 ) {
V_18 = F_31 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_60 ;
}
return V_18 ;
}
int F_32 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_65 * args = V_62 ;
struct V_66 * V_67 ;
V_67 = & V_10 -> V_68 . V_69 . V_67 [ V_70 ] ;
args -> V_71 = ( V_72 ) V_67 -> V_11 << V_73 ;
args -> V_74 = V_10 -> V_20 . V_75 ;
args -> V_74 -= V_10 -> V_76 ;
args -> V_77 = V_10 -> V_20 . V_21 ;
args -> V_77 -= V_10 -> V_22 ;
return 0 ;
}
int F_33 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
F_9 ( L_7 , V_78 ) ;
return - V_79 ;
}
int F_34 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
F_9 ( L_7 , V_78 ) ;
return - V_79 ;
}
int F_35 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_80 * args = V_62 ;
struct V_1 * V_2 ;
T_2 V_81 ;
int V_18 ;
F_36 ( & V_10 -> V_82 ) ;
args -> V_11 = F_37 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , args -> V_12 ,
args -> V_13 , args -> V_14 ,
false , & V_2 ) ;
if ( V_18 ) {
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_30 ( V_10 , V_18 ) ;
return V_18 ;
}
V_18 = F_39 ( V_63 , V_2 , & V_81 ) ;
F_40 ( V_2 ) ;
if ( V_18 ) {
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_30 ( V_10 , V_18 ) ;
return V_18 ;
}
args -> V_81 = V_81 ;
F_38 ( & V_10 -> V_82 ) ;
return 0 ;
}
int F_41 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_83 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_84 ;
T_2 V_81 ;
int V_18 ;
if ( F_42 ( args -> V_85 | args -> V_11 ) )
return - V_43 ;
if ( args -> V_14 & ~ ( V_86 |
V_87 | V_88 |
V_89 ) )
return - V_43 ;
if ( args -> V_14 & V_86 ) {
if ( V_10 -> V_54 < V_90 )
return - V_43 ;
} else if ( ! ( args -> V_14 & V_87 ) ||
! ( args -> V_14 & V_89 ) ) {
return - V_91 ;
}
F_36 ( & V_10 -> V_82 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_37 , 0 ,
false , & V_2 ) ;
if ( V_18 )
goto V_92;
V_84 = F_2 ( V_2 ) ;
V_18 = F_43 ( V_84 -> V_7 . V_93 , args -> V_85 , args -> V_14 ) ;
if ( V_18 )
goto V_94;
if ( args -> V_14 & V_89 ) {
V_18 = F_44 ( V_84 , args -> V_85 ) ;
if ( V_18 )
goto V_94;
}
if ( args -> V_14 & V_88 ) {
F_36 ( & V_29 -> V_95 -> V_96 ) ;
V_18 = F_23 ( V_84 , true ) ;
if ( V_18 ) {
F_38 ( & V_29 -> V_95 -> V_96 ) ;
goto V_94;
}
F_45 ( V_84 , V_27 ) ;
V_18 = F_46 ( & V_84 -> V_7 , & V_84 -> V_97 , true , false ) ;
F_26 ( V_84 ) ;
F_38 ( & V_29 -> V_95 -> V_96 ) ;
if ( V_18 )
goto V_94;
}
V_18 = F_39 ( V_63 , V_2 , & V_81 ) ;
F_40 ( V_2 ) ;
if ( V_18 )
goto V_92;
args -> V_81 = V_81 ;
F_38 ( & V_10 -> V_82 ) ;
return 0 ;
V_94:
F_40 ( V_2 ) ;
V_92:
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_30 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_47 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_98 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
F_36 ( & V_10 -> V_82 ) ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
F_38 ( & V_10 -> V_82 ) ;
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_14 ( V_2 , args -> V_100 , args -> V_101 ) ;
F_40 ( V_2 ) ;
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_30 ( V_4 -> V_10 , V_18 ) ;
return V_18 ;
}
int F_49 ( struct V_44 * V_63 ,
struct V_61 * V_58 ,
T_2 V_81 , T_3 * V_102 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_48 ( V_63 , V_81 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_50 ( V_4 -> V_7 . V_93 ) ) {
F_40 ( V_2 ) ;
return - V_103 ;
}
* V_102 = F_51 ( V_4 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_104 * args = V_62 ;
return F_49 ( V_63 , V_58 , args -> V_81 , & args -> V_105 ) ;
}
int F_53 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_106 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_2 V_107 = 0 ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_54 ( V_4 -> V_7 . V_38 , true ) ;
if ( V_18 == 0 )
V_18 = - V_40 ;
else
V_18 = 0 ;
V_107 = F_55 ( V_4 -> V_7 . V_108 . V_109 ) ;
args -> V_36 = F_56 ( V_107 ) ;
F_40 ( V_2 ) ;
return V_18 ;
}
int F_57 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_110 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
T_2 V_107 = 0 ;
long V_111 ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_111 = F_16 ( V_4 -> V_7 . V_38 , true , true , 30 * V_39 ) ;
if ( V_111 == 0 )
V_18 = - V_40 ;
else if ( V_111 < 0 )
V_18 = V_111 ;
V_107 = F_55 ( V_4 -> V_7 . V_108 . V_109 ) ;
if ( V_10 -> V_112 -> V_113 &&
F_56 ( V_107 ) == V_26 )
V_4 -> V_10 -> V_112 -> V_113 ( V_10 ) ;
F_40 ( V_2 ) ;
V_18 = F_30 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_58 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_114 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_7 ( L_8 , args -> V_81 ) ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_99 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_59 ( V_4 , args -> V_115 , args -> V_116 ) ;
F_40 ( V_2 ) ;
return V_18 ;
}
int F_60 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_117 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_46 ;
int V_18 = 0 ;
F_7 ( L_9 ) ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_99 ;
V_46 = F_2 ( V_2 ) ;
V_18 = F_23 ( V_46 , false ) ;
if ( F_61 ( V_18 != 0 ) )
goto V_118;
F_62 ( V_46 , & args -> V_115 , & args -> V_116 ) ;
F_26 ( V_46 ) ;
V_118:
F_40 ( V_2 ) ;
return V_18 ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
struct V_119 V_120 , * V_121 ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_126 V_32 ;
unsigned V_36 ;
int V_18 ;
F_19 ( & V_32 ) ;
V_120 . V_84 = & V_53 -> V_84 -> V_7 ;
V_120 . V_127 = true ;
F_64 ( & V_120 . V_128 , & V_32 ) ;
V_123 = F_65 ( V_10 , V_53 -> V_51 , & V_32 ) ;
if ( ! V_123 )
return;
V_18 = F_66 ( & V_125 , & V_32 , true , NULL ) ;
if ( V_18 )
goto V_129;
F_67 (entry, &list, head) {
V_36 = F_56 ( V_121 -> V_84 -> V_108 . V_109 ) ;
if ( V_36 == V_37 )
goto V_130;
}
F_11 ( & V_53 -> V_51 -> V_31 ) ;
V_18 = F_68 ( V_10 , V_53 -> V_51 ) ;
if ( V_18 )
goto V_131;
if ( V_53 -> V_132 . V_133 )
V_18 = F_69 ( V_10 , V_53 , & V_53 -> V_84 -> V_7 . V_108 ) ;
V_131:
F_13 ( & V_53 -> V_51 -> V_31 ) ;
V_130:
F_70 ( & V_125 , & V_32 ) ;
V_129:
F_71 ( V_123 ) ;
if ( V_18 && V_18 != - V_25 )
F_9 ( L_10 , V_18 ) ;
}
int F_72 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_134 * args = V_62 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_47 * V_48 = V_63 -> V_49 ;
struct V_3 * V_46 ;
struct V_52 * V_53 ;
T_1 V_135 ;
int V_18 = 0 ;
if ( ! V_10 -> V_136 . V_137 ) {
args -> V_138 = V_139 ;
return - V_140 ;
}
if ( args -> V_141 ) {
args -> V_138 = V_139 ;
return - V_43 ;
}
if ( args -> V_142 < V_143 ) {
F_28 ( & V_58 -> V_144 -> V_58 ,
L_11 ,
( unsigned long ) args -> V_142 ,
V_143 ) ;
args -> V_138 = V_139 ;
return - V_43 ;
}
V_135 = V_145 | V_146 ;
if ( ( args -> V_14 & V_135 ) ) {
F_28 ( & V_58 -> V_144 -> V_58 , L_12 ,
args -> V_14 , V_135 ) ;
args -> V_138 = V_139 ;
return - V_43 ;
}
switch ( args -> V_138 ) {
case V_147 :
case V_148 :
break;
default:
F_28 ( & V_58 -> V_144 -> V_58 , L_13 ,
args -> V_138 ) ;
args -> V_138 = V_139 ;
return - V_43 ;
}
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
args -> V_138 = V_139 ;
return - V_99 ;
}
V_46 = F_2 ( V_2 ) ;
V_18 = F_23 ( V_46 , false ) ;
if ( V_18 ) {
args -> V_138 = V_139 ;
F_40 ( V_2 ) ;
return V_18 ;
}
V_53 = F_24 ( & V_48 -> V_51 , V_46 ) ;
if ( ! V_53 ) {
args -> V_138 = V_139 ;
F_26 ( V_46 ) ;
F_40 ( V_2 ) ;
return - V_99 ;
}
switch ( args -> V_138 ) {
case V_147 :
if ( V_53 -> V_132 . V_133 ) {
args -> V_138 = V_149 ;
args -> V_142 = V_53 -> V_132 . V_133 * V_150 ;
F_26 ( V_46 ) ;
goto V_118;
}
V_18 = F_73 ( V_10 , V_53 , args -> V_142 , args -> V_14 ) ;
break;
case V_148 :
V_18 = F_73 ( V_10 , V_53 , 0 , 0 ) ;
break;
default:
break;
}
if ( ! V_18 )
F_63 ( V_10 , V_53 ) ;
args -> V_138 = V_151 ;
if ( V_18 ) {
args -> V_138 = V_139 ;
}
V_118:
F_40 ( V_2 ) ;
return V_18 ;
}
int F_74 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_152 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_48 ( V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = - V_103 ;
if ( F_50 ( V_4 -> V_7 . V_93 ) )
goto V_118;
V_18 = F_23 ( V_4 , false ) ;
if ( F_61 ( V_18 ) )
goto V_118;
switch ( args -> V_153 ) {
case V_154 :
args -> V_155 = V_4 -> V_13 ;
break;
case V_156 :
V_4 -> V_13 = args -> V_155 & ( V_26 |
V_27 |
V_37 ) ;
break;
default:
V_18 = - V_43 ;
}
F_26 ( V_4 ) ;
V_118:
F_40 ( V_2 ) ;
return V_18 ;
}
int F_75 ( struct V_44 * V_45 ,
struct V_61 * V_58 ,
struct V_157 * args )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_1 * V_2 ;
T_2 V_81 ;
int V_18 ;
args -> V_116 = F_76 ( V_10 , args -> V_158 ,
F_77 ( args -> V_159 , 8 ) , 0 ) ;
args -> V_11 = args -> V_116 * args -> V_160 ;
args -> V_11 = F_78 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_26 , 0 ,
false , & V_2 ) ;
if ( V_18 )
return - V_23 ;
V_18 = F_39 ( V_45 , V_2 , & V_81 ) ;
F_40 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_81 = V_81 ;
return 0 ;
}
static int F_79 ( struct V_161 * V_162 , void * V_62 )
{
struct V_163 * V_164 = (struct V_163 * ) V_162 -> V_165 ;
struct V_61 * V_58 = V_164 -> V_166 -> V_58 ;
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_3 * V_46 ;
unsigned V_167 = 0 ;
F_11 ( & V_10 -> V_30 . V_31 ) ;
F_67 (rbo, &rdev->gem.objects, list) {
unsigned V_36 ;
const char * V_97 ;
V_36 = F_56 ( V_46 -> V_7 . V_108 . V_109 ) ;
switch ( V_36 ) {
case V_26 :
V_97 = L_14 ;
break;
case V_27 :
V_97 = L_15 ;
break;
case V_37 :
default:
V_97 = L_16 ;
break;
}
F_80 ( V_162 , L_17 ,
V_167 , F_81 ( V_46 ) >> 10 , F_81 ( V_46 ) >> 20 ,
V_97 , ( unsigned long ) V_46 -> V_28 ) ;
V_167 ++ ;
}
F_13 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
int F_82 ( struct V_9 * V_10 )
{
#if F_83 ( V_168 )
return F_84 ( V_10 , V_169 , 1 ) ;
#endif
return 0 ;
}
