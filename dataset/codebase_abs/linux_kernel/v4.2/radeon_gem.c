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
F_15 ( V_37 L_3 ) ;
return 0 ;
}
if ( V_36 == V_38 ) {
V_18 = F_16 ( V_4 -> V_7 . V_39 , true , true , 30 * V_40 ) ;
if ( ! V_18 )
V_18 = - V_41 ;
if ( V_18 < 0 && V_18 != - V_42 ) {
F_15 ( V_43 L_4 , V_18 ) ;
return V_18 ;
}
}
return 0 ;
}
int F_17 ( struct V_9 * V_10 )
{
F_18 ( & V_10 -> V_30 . V_33 ) ;
return 0 ;
}
void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_10 ) ;
}
int F_21 ( struct V_1 * V_16 , struct V_44 * V_45 )
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
V_18 = F_22 ( V_46 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_53 = F_23 ( V_51 , V_46 ) ;
if ( ! V_53 ) {
V_53 = F_24 ( V_10 , V_51 , V_46 ) ;
} else {
++ V_53 -> V_57 ;
}
F_25 ( V_46 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_16 ,
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
V_18 = F_22 ( V_46 , true ) ;
if ( V_18 ) {
F_27 ( V_10 -> V_58 , L_5
L_6 , V_18 ) ;
return;
}
V_53 = F_23 ( V_51 , V_46 ) ;
if ( V_53 ) {
if ( -- V_53 -> V_57 == 0 ) {
F_28 ( V_10 , V_53 ) ;
}
}
F_25 ( V_46 ) ;
}
static int F_29 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_59 ) {
V_18 = F_30 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_60 ;
}
return V_18 ;
}
int F_31 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_65 * args = V_62 ;
struct V_66 * V_67 ;
V_67 = & V_10 -> V_68 . V_69 . V_67 [ V_70 ] ;
args -> V_71 = V_10 -> V_20 . V_72 ;
args -> V_73 = ( V_74 ) V_67 -> V_11 << V_75 ;
args -> V_73 -= V_10 -> V_76 ;
args -> V_77 = V_10 -> V_20 . V_21 ;
args -> V_77 -= V_10 -> V_22 ;
return 0 ;
}
int F_32 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
F_9 ( L_7 , V_78 ) ;
return - V_79 ;
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
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_80 * args = V_62 ;
struct V_1 * V_2 ;
T_2 V_81 ;
int V_18 ;
F_35 ( & V_10 -> V_82 ) ;
args -> V_11 = F_36 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , args -> V_12 ,
args -> V_13 , args -> V_14 ,
false , & V_2 ) ;
if ( V_18 ) {
F_37 ( & V_10 -> V_82 ) ;
V_18 = F_29 ( V_10 , V_18 ) ;
return V_18 ;
}
V_18 = F_38 ( V_63 , V_2 , & V_81 ) ;
F_39 ( V_2 ) ;
if ( V_18 ) {
F_37 ( & V_10 -> V_82 ) ;
V_18 = F_29 ( V_10 , V_18 ) ;
return V_18 ;
}
args -> V_81 = V_81 ;
F_37 ( & V_10 -> V_82 ) ;
return 0 ;
}
int F_40 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_83 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_84 ;
T_2 V_81 ;
int V_18 ;
if ( F_41 ( args -> V_85 | args -> V_11 ) )
return - V_86 ;
if ( args -> V_14 & ~ ( V_87 |
V_88 | V_89 |
V_90 ) )
return - V_86 ;
if ( args -> V_14 & V_87 ) {
if ( V_10 -> V_54 < V_91 )
return - V_86 ;
} else if ( ! ( args -> V_14 & V_88 ) ||
! ( args -> V_14 & V_90 ) ) {
return - V_92 ;
}
F_35 ( & V_10 -> V_82 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_38 , 0 ,
false , & V_2 ) ;
if ( V_18 )
goto V_93;
V_84 = F_2 ( V_2 ) ;
V_18 = F_42 ( V_84 -> V_7 . V_94 , args -> V_85 , args -> V_14 ) ;
if ( V_18 )
goto V_95;
if ( args -> V_14 & V_90 ) {
V_18 = F_43 ( V_84 , args -> V_85 ) ;
if ( V_18 )
goto V_95;
}
if ( args -> V_14 & V_89 ) {
F_35 ( & V_29 -> V_96 -> V_97 ) ;
V_18 = F_22 ( V_84 , true ) ;
if ( V_18 ) {
F_37 ( & V_29 -> V_96 -> V_97 ) ;
goto V_95;
}
F_44 ( V_84 , V_27 ) ;
V_18 = F_45 ( & V_84 -> V_7 , & V_84 -> V_98 , true , false ) ;
F_25 ( V_84 ) ;
F_37 ( & V_29 -> V_96 -> V_97 ) ;
if ( V_18 )
goto V_95;
}
V_18 = F_38 ( V_63 , V_2 , & V_81 ) ;
F_39 ( V_2 ) ;
if ( V_18 )
goto V_93;
args -> V_81 = V_81 ;
F_37 ( & V_10 -> V_82 ) ;
return 0 ;
V_95:
F_39 ( V_2 ) ;
V_93:
F_37 ( & V_10 -> V_82 ) ;
V_18 = F_29 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_46 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_99 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
F_35 ( & V_10 -> V_82 ) ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
F_37 ( & V_10 -> V_82 ) ;
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_14 ( V_2 , args -> V_101 , args -> V_102 ) ;
F_39 ( V_2 ) ;
F_37 ( & V_10 -> V_82 ) ;
V_18 = F_29 ( V_4 -> V_10 , V_18 ) ;
return V_18 ;
}
int F_48 ( struct V_44 * V_63 ,
struct V_61 * V_58 ,
T_2 V_81 , T_3 * V_103 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_47 ( V_58 , V_63 , V_81 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_49 ( V_4 -> V_7 . V_94 ) ) {
F_39 ( V_2 ) ;
return - V_104 ;
}
* V_103 = F_50 ( V_4 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
int F_51 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_105 * args = V_62 ;
return F_48 ( V_63 , V_58 , args -> V_81 , & args -> V_106 ) ;
}
int F_52 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_107 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_2 V_108 = 0 ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_53 ( V_4 -> V_7 . V_39 , true ) ;
if ( V_18 == 0 )
V_18 = - V_41 ;
else
V_18 = 0 ;
V_108 = F_54 ( V_4 -> V_7 . V_109 . V_110 ) ;
args -> V_36 = F_55 ( V_108 ) ;
F_39 ( V_2 ) ;
return V_18 ;
}
int F_56 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_111 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
T_2 V_108 = 0 ;
long V_112 ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_112 = F_16 ( V_4 -> V_7 . V_39 , true , true , 30 * V_40 ) ;
if ( V_112 == 0 )
V_18 = - V_41 ;
else if ( V_112 < 0 )
V_18 = V_112 ;
V_108 = F_54 ( V_4 -> V_7 . V_109 . V_110 ) ;
if ( V_10 -> V_113 -> V_114 &&
F_55 ( V_108 ) == V_26 )
V_4 -> V_10 -> V_113 -> V_114 ( V_10 ) ;
F_39 ( V_2 ) ;
V_18 = F_29 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_57 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_115 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_7 ( L_8 , args -> V_81 ) ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_58 ( V_4 , args -> V_116 , args -> V_117 ) ;
F_39 ( V_2 ) ;
return V_18 ;
}
int F_59 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_118 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_46 ;
int V_18 = 0 ;
F_7 ( L_9 ) ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_46 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_46 , false ) ;
if ( F_60 ( V_18 != 0 ) )
goto V_119;
F_61 ( V_46 , & args -> V_116 , & args -> V_117 ) ;
F_25 ( V_46 ) ;
V_119:
F_39 ( V_2 ) ;
return V_18 ;
}
static void F_62 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
struct V_120 V_121 , * V_122 ;
struct V_123 * V_124 ;
struct V_125 V_126 ;
struct V_127 V_32 ;
unsigned V_36 ;
int V_18 ;
F_18 ( & V_32 ) ;
V_121 . V_84 = & V_53 -> V_84 -> V_7 ;
V_121 . V_128 = true ;
F_63 ( & V_121 . V_129 , & V_32 ) ;
V_124 = F_64 ( V_10 , V_53 -> V_51 , & V_32 ) ;
if ( ! V_124 )
return;
V_18 = F_65 ( & V_126 , & V_32 , true , NULL ) ;
if ( V_18 )
goto V_130;
F_66 (entry, &list, head) {
V_36 = F_55 ( V_122 -> V_84 -> V_109 . V_110 ) ;
if ( V_36 == V_38 )
goto V_131;
}
F_11 ( & V_53 -> V_51 -> V_31 ) ;
V_18 = F_67 ( V_10 , V_53 -> V_51 ) ;
if ( V_18 )
goto V_132;
if ( V_53 -> V_133 . V_134 )
V_18 = F_68 ( V_10 , V_53 , & V_53 -> V_84 -> V_7 . V_109 ) ;
V_132:
F_13 ( & V_53 -> V_51 -> V_31 ) ;
V_131:
F_69 ( & V_126 , & V_32 ) ;
V_130:
F_70 ( V_124 ) ;
if ( V_18 && V_18 != - V_25 )
F_9 ( L_10 , V_18 ) ;
}
int F_71 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_135 * args = V_62 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_47 * V_48 = V_63 -> V_49 ;
struct V_3 * V_46 ;
struct V_52 * V_53 ;
T_1 V_136 ;
int V_18 = 0 ;
if ( ! V_10 -> V_137 . V_138 ) {
args -> V_139 = V_140 ;
return - V_141 ;
}
if ( args -> V_142 ) {
args -> V_139 = V_140 ;
return - V_86 ;
}
if ( args -> V_143 < V_144 ) {
F_27 ( & V_58 -> V_145 -> V_58 ,
L_11 ,
( unsigned long ) args -> V_143 ,
V_144 ) ;
args -> V_139 = V_140 ;
return - V_86 ;
}
V_136 = V_146 | V_147 ;
if ( ( args -> V_14 & V_136 ) ) {
F_27 ( & V_58 -> V_145 -> V_58 , L_12 ,
args -> V_14 , V_136 ) ;
args -> V_139 = V_140 ;
return - V_86 ;
}
switch ( args -> V_139 ) {
case V_148 :
case V_149 :
break;
default:
F_27 ( & V_58 -> V_145 -> V_58 , L_13 ,
args -> V_139 ) ;
args -> V_139 = V_140 ;
return - V_86 ;
}
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
args -> V_139 = V_140 ;
return - V_100 ;
}
V_46 = F_2 ( V_2 ) ;
V_18 = F_22 ( V_46 , false ) ;
if ( V_18 ) {
args -> V_139 = V_140 ;
F_39 ( V_2 ) ;
return V_18 ;
}
V_53 = F_23 ( & V_48 -> V_51 , V_46 ) ;
if ( ! V_53 ) {
args -> V_139 = V_140 ;
F_39 ( V_2 ) ;
return - V_100 ;
}
switch ( args -> V_139 ) {
case V_148 :
if ( V_53 -> V_133 . V_134 ) {
args -> V_139 = V_150 ;
args -> V_143 = V_53 -> V_133 . V_134 * V_151 ;
F_25 ( V_46 ) ;
goto V_119;
}
V_18 = F_72 ( V_10 , V_53 , args -> V_143 , args -> V_14 ) ;
break;
case V_149 :
V_18 = F_72 ( V_10 , V_53 , 0 , 0 ) ;
break;
default:
break;
}
if ( ! V_18 )
F_62 ( V_10 , V_53 ) ;
args -> V_139 = V_152 ;
if ( V_18 ) {
args -> V_139 = V_140 ;
}
V_119:
F_39 ( V_2 ) ;
return V_18 ;
}
int F_73 ( struct V_61 * V_58 , void * V_62 ,
struct V_44 * V_63 )
{
struct V_153 * args = V_62 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_47 ( V_58 , V_63 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_100 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = - V_104 ;
if ( F_49 ( V_4 -> V_7 . V_94 ) )
goto V_119;
V_18 = F_22 ( V_4 , false ) ;
if ( F_60 ( V_18 ) )
goto V_119;
switch ( args -> V_154 ) {
case V_155 :
args -> V_156 = V_4 -> V_13 ;
break;
case V_157 :
V_4 -> V_13 = args -> V_156 & ( V_26 |
V_27 |
V_38 ) ;
break;
default:
V_18 = - V_86 ;
}
F_25 ( V_4 ) ;
V_119:
F_39 ( V_2 ) ;
return V_18 ;
}
int F_74 ( struct V_44 * V_45 ,
struct V_61 * V_58 ,
struct V_158 * args )
{
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_1 * V_2 ;
T_2 V_81 ;
int V_18 ;
args -> V_117 = F_75 ( V_10 , args -> V_159 , args -> V_160 , 0 ) * ( ( args -> V_160 + 1 ) / 8 ) ;
args -> V_11 = args -> V_117 * args -> V_161 ;
args -> V_11 = F_76 ( args -> V_11 , V_19 ) ;
V_18 = F_6 ( V_10 , args -> V_11 , 0 ,
V_26 , 0 ,
false , & V_2 ) ;
if ( V_18 )
return - V_23 ;
V_18 = F_38 ( V_45 , V_2 , & V_81 ) ;
F_39 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_81 = V_81 ;
return 0 ;
}
static int F_77 ( struct V_162 * V_163 , void * V_62 )
{
struct V_164 * V_165 = (struct V_164 * ) V_163 -> V_166 ;
struct V_61 * V_58 = V_165 -> V_167 -> V_58 ;
struct V_9 * V_10 = V_58 -> V_64 ;
struct V_3 * V_46 ;
unsigned V_168 = 0 ;
F_11 ( & V_10 -> V_30 . V_31 ) ;
F_66 (rbo, &rdev->gem.objects, list) {
unsigned V_36 ;
const char * V_98 ;
V_36 = F_55 ( V_46 -> V_7 . V_109 . V_110 ) ;
switch ( V_36 ) {
case V_26 :
V_98 = L_14 ;
break;
case V_27 :
V_98 = L_15 ;
break;
case V_38 :
default:
V_98 = L_16 ;
break;
}
F_78 ( V_163 , L_17 ,
V_168 , F_79 ( V_46 ) >> 10 , F_79 ( V_46 ) >> 20 ,
V_98 , ( unsigned long ) V_46 -> V_28 ) ;
V_168 ++ ;
}
F_13 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
int F_80 ( struct V_9 * V_10 )
{
#if F_81 ( V_169 )
return F_82 ( V_10 , V_170 , 1 ) ;
#endif
return 0 ;
}
