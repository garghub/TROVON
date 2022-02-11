const struct V_1 * F_1 ( T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_5 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
static T_1 F_3 ( struct V_6 * V_7 )
{
const struct V_1 * V_8 ;
V_8 = F_1 ( V_7 -> V_2 ) ;
if ( F_4 ( ! V_8 ) )
return - V_9 ;
return V_7 -> V_10 * V_8 -> V_11 ;
}
static T_1 F_5 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 == V_12 )
return V_7 -> V_13 * V_7 -> V_14 * 2 ;
return V_7 -> V_13 * V_7 -> V_14 ;
}
static int F_6 ( struct V_15 * V_16 ,
T_1 V_17 ,
struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 V_25 = {
. V_17 = V_17 ,
} ;
int V_26 ;
V_21 = F_7 ( V_16 ) ;
F_8 ( & V_25 . V_25 , V_7 , V_16 -> V_19 . V_27 ) ;
V_23 = F_9 ( V_21 ) ;
if ( V_23 == NULL )
return - V_28 ;
V_25 . V_29 = V_16 -> V_30 ;
V_26 = F_10 ( V_21 -> V_31 , 0 , V_29 , V_32 ,
V_23 , & V_25 ) ;
if ( V_26 < 0 )
goto V_33;
F_11 ( V_7 , & V_25 . V_25 ) ;
V_19 -> V_10 = V_7 -> V_10 ;
V_19 -> V_14 = V_7 -> V_14 ;
F_12 ( V_16 , L_1 , V_19 -> V_10 ,
V_19 -> V_14 ) ;
V_33:
F_13 ( V_23 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 ,
T_1 V_17 ,
struct V_6 * V_7 ,
struct V_18 * V_19 )
{
const struct V_1 * V_34 ;
T_1 V_35 , V_36 , V_37 ;
V_35 = V_7 -> V_10 ;
V_36 = V_7 -> V_14 ;
V_34 = F_1 ( V_7 -> V_2 ) ;
if ( ! V_34 ) {
F_12 ( V_16 , L_2 ,
V_7 -> V_2 , V_16 -> V_25 . V_2 ) ;
* V_7 = V_16 -> V_25 ;
V_7 -> V_10 = V_35 ;
V_7 -> V_14 = V_36 ;
}
V_7 -> V_13 = 0 ;
V_7 -> V_38 = 0 ;
F_6 ( V_16 , V_17 , V_7 , V_19 ) ;
if ( V_19 -> V_10 != V_35 || V_19 -> V_14 != V_36 )
F_15 ( V_16 , V_7 , V_35 , V_36 ) ;
V_37 = V_16 -> V_25 . V_2 == V_12 ? 5 : 1 ;
F_16 ( & V_7 -> V_10 , 2 , V_39 , V_37 ,
& V_7 -> V_14 , 4 , V_40 , 2 , 0 ) ;
switch ( V_7 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
default:
V_7 -> V_41 = V_42 ;
break;
}
V_7 -> V_13 = F_17 ( T_1 , V_7 -> V_13 ,
F_3 ( V_7 ) ) ;
V_7 -> V_38 = F_17 ( T_1 , V_7 -> V_38 ,
F_5 ( V_7 ) ) ;
F_12 ( V_16 , L_3 ,
V_35 , V_36 , V_7 -> V_10 , V_7 -> V_14 ,
V_7 -> V_13 , V_7 -> V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_48 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
F_20 ( V_51 -> V_52 , V_53 , sizeof( V_51 -> V_52 ) ) ;
F_20 ( V_51 -> V_54 , L_4 , sizeof( V_51 -> V_54 ) ) ;
snprintf ( V_51 -> V_55 , sizeof( V_51 -> V_55 ) , L_5 ,
F_21 ( V_16 -> V_56 ) ) ;
return 0 ;
}
static int F_22 ( struct V_48 * V_48 , void * V_49 ,
struct V_57 * V_58 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_18 V_19 ;
return F_14 ( V_16 , V_59 , & V_58 -> V_8 . V_7 ,
& V_19 ) ;
}
static int F_23 ( struct V_48 * V_48 , void * V_49 ,
struct V_57 * V_58 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_18 V_19 ;
int V_26 ;
if ( F_24 ( & V_16 -> V_60 ) )
return - V_61 ;
V_26 = F_14 ( V_16 , V_62 , & V_58 -> V_8 . V_7 ,
& V_19 ) ;
if ( V_26 )
return V_26 ;
V_16 -> V_19 . V_10 = V_19 . V_10 ;
V_16 -> V_19 . V_14 = V_19 . V_14 ;
V_16 -> V_25 = V_58 -> V_8 . V_7 ;
return 0 ;
}
static int F_25 ( struct V_48 * V_48 , void * V_49 ,
struct V_57 * V_58 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
V_58 -> V_8 . V_7 = V_16 -> V_25 ;
return 0 ;
}
static int F_26 ( struct V_48 * V_48 , void * V_49 ,
struct V_63 * V_58 )
{
if ( V_58 -> V_64 >= F_2 ( V_4 ) )
return - V_9 ;
V_58 -> V_2 = V_4 [ V_58 -> V_64 ] . V_5 ;
return 0 ;
}
static int F_27 ( struct V_48 * V_48 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
if ( V_67 -> type != V_68 )
return - V_9 ;
switch ( V_67 -> V_69 ) {
case V_70 :
case V_71 :
V_67 -> V_72 . V_73 = V_67 -> V_72 . V_74 = 0 ;
V_67 -> V_72 . V_10 = V_16 -> V_19 . V_10 ;
V_67 -> V_72 . V_14 = V_16 -> V_19 . V_14 ;
break;
case V_75 :
V_67 -> V_72 = V_16 -> V_76 ;
break;
case V_77 :
case V_78 :
V_67 -> V_72 . V_73 = V_67 -> V_72 . V_74 = 0 ;
V_67 -> V_72 . V_10 = V_16 -> V_25 . V_10 ;
V_67 -> V_72 . V_14 = V_16 -> V_25 . V_14 ;
break;
case V_79 :
V_67 -> V_72 = V_16 -> V_80 ;
break;
default:
return - V_9 ;
}
return 0 ;
}
static int F_28 ( struct V_48 * V_48 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
const struct V_1 * V_8 ;
struct V_81 V_72 = V_67 -> V_72 ;
struct V_81 V_82 ;
struct V_81 V_83 = {
. V_10 = 6 ,
. V_14 = 2 ,
} ;
if ( V_67 -> type != V_68 )
return - V_9 ;
F_29 ( & V_72 , & V_83 ) ;
switch ( V_67 -> V_69 ) {
case V_75 :
V_82 . V_74 = V_82 . V_73 = 0 ;
V_82 . V_10 = V_16 -> V_19 . V_10 ;
V_82 . V_14 = V_16 -> V_19 . V_14 ;
F_30 ( & V_72 , & V_82 ) ;
F_16 ( & V_72 . V_10 , 2 , V_16 -> V_19 . V_10 , 1 ,
& V_72 . V_14 , 4 , V_16 -> V_19 . V_14 , 2 , 0 ) ;
V_72 . V_74 = F_31 ( V_84 , V_72 . V_74 , 0 , V_16 -> V_19 . V_14 - V_72 . V_14 ) ;
V_72 . V_73 = F_31 ( V_84 , V_72 . V_73 , 0 , V_16 -> V_19 . V_10 - V_72 . V_10 ) ;
V_16 -> V_76 = V_67 -> V_72 = V_72 ;
F_12 ( V_16 , L_6 ,
V_72 . V_10 , V_72 . V_14 , V_72 . V_73 , V_72 . V_74 ,
V_16 -> V_19 . V_10 , V_16 -> V_19 . V_14 ) ;
break;
case V_79 :
V_82 . V_74 = V_82 . V_73 = 0 ;
V_82 . V_10 = V_16 -> V_25 . V_10 ;
V_82 . V_14 = V_16 -> V_25 . V_14 ;
F_30 ( & V_72 , & V_82 ) ;
while ( ( V_72 . V_74 * V_16 -> V_25 . V_13 ) & V_85 )
V_72 . V_74 -- ;
V_8 = F_1 ( V_16 -> V_25 . V_2 ) ;
while ( ( V_72 . V_73 * V_8 -> V_11 ) & V_85 )
V_72 . V_73 -- ;
V_16 -> V_80 = V_67 -> V_72 = V_72 ;
F_12 ( V_16 , L_7 ,
V_72 . V_10 , V_72 . V_14 , V_72 . V_73 , V_72 . V_74 ,
V_16 -> V_25 . V_10 , V_16 -> V_25 . V_14 ) ;
break;
default:
return - V_9 ;
}
F_32 ( V_16 ) ;
return 0 ;
}
static int F_33 ( struct V_48 * V_48 , void * V_49 ,
struct V_86 * V_76 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
if ( V_76 -> type != V_68 )
return - V_9 ;
return F_34 ( V_21 , V_87 , V_88 , V_76 ) ;
}
static int F_35 ( struct V_48 * V_48 , void * V_49 ,
struct V_89 * V_3 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
int V_26 ;
if ( V_3 -> V_64 != 0 )
return - V_9 ;
V_26 = F_34 ( V_21 , V_87 , V_90 , & V_3 -> V_91 ) ;
if ( V_26 < 0 && V_26 != - V_92 && V_26 != - V_93 )
return V_26 ;
V_3 -> type = V_94 ;
V_3 -> V_95 = V_16 -> V_96 . V_97 ;
if ( F_36 ( V_21 , V_29 , V_98 ) )
V_3 -> V_99 = V_100 ;
F_20 ( V_3 -> V_101 , L_8 , sizeof( V_3 -> V_101 ) ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_48 , void * V_49 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_38 ( struct V_48 * V_48 , void * V_49 , unsigned int V_3 )
{
if ( V_3 > 0 )
return - V_9 ;
return 0 ;
}
static int F_39 ( struct V_48 * V_48 , void * V_49 , T_2 * V_102 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
return F_34 ( V_21 , V_87 , V_103 , V_102 ) ;
}
static int F_40 ( struct V_48 * V_48 , void * V_49 , T_2 V_102 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
struct V_24 V_8 = {
. V_17 = V_62 ,
} ;
struct V_104 * V_105 = & V_8 . V_25 ;
int V_26 = F_34 ( V_21 , V_87 , V_106 , V_102 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_34 ( V_21 , V_29 , V_107 , NULL , & V_8 ) ;
if ( V_26 ) {
F_41 ( V_16 , L_9 ) ;
return V_26 ;
}
V_16 -> V_25 . V_10 = V_105 -> V_10 ;
V_16 -> V_25 . V_14 = V_105 -> V_14 ;
V_16 -> V_76 . V_74 = V_16 -> V_76 . V_73 = 0 ;
V_16 -> V_76 . V_10 = V_105 -> V_10 ;
V_16 -> V_76 . V_14 = V_105 -> V_14 ;
V_16 -> V_80 . V_74 = V_16 -> V_80 . V_73 = 0 ;
V_16 -> V_80 . V_10 = V_105 -> V_10 ;
V_16 -> V_80 . V_14 = V_105 -> V_14 ;
return 0 ;
}
static int F_42 ( struct V_48 * V_48 , void * V_49 , T_2 * V_102 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
return F_34 ( V_21 , V_87 , V_108 , V_102 ) ;
}
static int F_43 ( struct V_109 * V_65 ,
const struct V_110 * V_111 )
{
switch ( V_111 -> type ) {
case V_112 :
return F_44 ( V_65 , V_111 , 4 , NULL ) ;
}
return F_45 ( V_65 , V_111 ) ;
}
static int F_46 ( struct V_48 * V_48 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
int V_29 , V_26 ;
V_29 = V_115 -> V_29 ;
V_115 -> V_29 = V_16 -> V_30 ;
V_26 = F_34 ( V_21 , V_29 , V_116 , V_115 ) ;
V_115 -> V_29 = V_29 ;
return V_26 ;
}
static int F_47 ( struct V_48 * V_48 , void * V_113 ,
struct V_117 * V_115 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
int V_118 ;
V_118 = F_34 ( V_21 ,
V_87 , V_119 , V_115 ) ;
if ( ! V_118 ) {
V_16 -> V_19 . V_10 = V_115 -> V_120 . V_10 ;
V_16 -> V_19 . V_14 = V_115 -> V_120 . V_14 ;
V_16 -> V_25 . V_10 = V_115 -> V_120 . V_10 ;
V_16 -> V_25 . V_14 = V_115 -> V_120 . V_14 ;
}
return V_118 ;
}
static int F_48 ( struct V_48 * V_48 , void * V_113 ,
struct V_117 * V_115 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
return F_34 ( V_21 ,
V_87 , V_121 , V_115 ) ;
}
static int F_49 ( struct V_48 * V_48 , void * V_113 ,
struct V_117 * V_115 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
return F_34 ( V_21 ,
V_87 , V_122 , V_115 ) ;
}
static int F_50 ( struct V_48 * V_48 , void * V_113 ,
struct V_123 * V_51 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
int V_29 , V_26 ;
V_29 = V_51 -> V_29 ;
V_51 -> V_29 = V_16 -> V_30 ;
V_26 = F_34 ( V_21 , V_29 , V_98 , V_51 ) ;
V_51 -> V_29 = V_29 ;
return V_26 ;
}
static int F_51 ( struct V_15 * V_16 )
{
int V_26 ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
F_52 ( V_16 -> V_31 . V_56 ) ;
V_26 = F_34 ( V_21 , V_124 , V_125 , 1 ) ;
if ( V_26 < 0 && V_26 != - V_92 && V_26 != - V_93 )
return V_26 ;
return 0 ;
}
static int F_53 ( struct V_15 * V_16 )
{
int V_26 ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
V_26 = F_34 ( V_21 , V_124 , V_125 , 0 ) ;
F_54 ( V_16 -> V_31 . V_56 ) ;
if ( V_26 < 0 && V_26 != - V_92 && V_26 != - V_93 )
return V_26 ;
return 0 ;
}
static int F_55 ( struct V_48 * V_48 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
int V_26 ;
struct V_57 V_58 = {
. type = V_68 ,
. V_8 . V_7 = {
. V_10 = V_16 -> V_25 . V_10 ,
. V_14 = V_16 -> V_25 . V_14 ,
. V_41 = V_16 -> V_25 . V_41 ,
. V_126 = V_16 -> V_25 . V_126 ,
. V_2 = V_16 -> V_25 . V_2 ,
} ,
} ;
V_26 = F_51 ( V_16 ) ;
if ( V_26 < 0 )
return V_26 ;
F_56 ( & V_16 -> V_96 . V_56 ) ;
V_26 = F_57 ( & V_16 -> V_96 . V_56 ) ;
if ( V_26 < 0 && V_26 != - V_127 )
goto V_128;
V_26 = F_23 ( V_48 , NULL , & V_58 ) ;
if ( V_26 < 0 )
goto V_129;
F_58 ( & V_16 -> V_130 ) ;
return 0 ;
V_129:
F_59 ( & V_16 -> V_96 . V_56 ) ;
V_128:
F_53 ( V_16 ) ;
return V_26 ;
}
static int F_60 ( struct V_48 * V_48 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
int V_26 ;
F_61 ( & V_16 -> V_131 ) ;
V_48 -> V_132 = V_16 ;
V_26 = F_62 ( V_48 ) ;
if ( V_26 )
goto V_133;
if ( ! F_63 ( V_48 ) )
goto V_133;
if ( F_55 ( V_48 ) ) {
F_64 ( V_48 ) ;
V_26 = - V_93 ;
}
V_133:
F_65 ( & V_16 -> V_131 ) ;
return V_26 ;
}
static int F_66 ( struct V_48 * V_48 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
bool V_134 ;
int V_26 ;
F_61 ( & V_16 -> V_131 ) ;
V_134 = F_63 ( V_48 ) ;
V_26 = F_67 ( V_48 , NULL ) ;
if ( V_134 ) {
F_68 ( & V_16 -> V_96 . V_56 ) ;
F_59 ( & V_16 -> V_96 . V_56 ) ;
F_53 ( V_16 ) ;
}
F_65 ( & V_16 -> V_131 ) ;
return V_26 ;
}
void F_69 ( struct V_15 * V_16 )
{
F_70 ( & V_16 -> V_31 , L_10 ,
F_71 ( & V_16 -> V_96 ) ) ;
F_72 ( & V_16 -> V_130 ) ;
F_73 ( & V_16 -> V_96 ) ;
}
static void F_74 ( struct V_20 * V_21 ,
unsigned int V_135 , void * V_136 )
{
struct V_15 * V_16 =
F_75 ( V_21 -> V_31 , struct V_15 , V_31 ) ;
switch ( V_135 ) {
case V_137 :
F_76 ( & V_16 -> V_96 , V_136 ) ;
break;
default:
break;
}
}
int F_77 ( struct V_15 * V_16 )
{
struct V_24 V_8 = {
. V_17 = V_62 ,
} ;
struct V_104 * V_105 = & V_8 . V_25 ;
struct V_138 * V_96 = & V_16 -> V_96 ;
struct V_20 * V_21 = F_7 ( V_16 ) ;
#if F_78 ( V_139 )
int V_140 ;
#endif
int V_26 ;
F_79 ( V_21 , V_16 ) ;
V_16 -> V_31 . V_141 = F_74 ;
V_26 = F_34 ( V_21 , V_87 , V_142 , & V_16 -> V_96 . V_97 ) ;
if ( V_26 < 0 && V_26 != - V_92 && V_26 != - V_93 )
return V_26 ;
if ( V_16 -> V_96 . V_97 == 0 ) {
F_80 ( & V_16 -> V_96 , V_143 ) ;
F_80 ( & V_16 -> V_96 , V_144 ) ;
F_80 ( & V_16 -> V_96 , V_145 ) ;
F_80 ( & V_16 -> V_96 , V_146 ) ;
}
V_26 = F_81 ( & V_16 -> V_130 , 16 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_82 ( & V_16 -> V_130 , V_21 -> V_130 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_96 -> V_147 = & V_148 ;
V_96 -> V_31 = & V_16 -> V_31 ;
V_96 -> V_60 = & V_16 -> V_60 ;
F_20 ( V_96 -> V_101 , V_53 , sizeof( V_96 -> V_101 ) ) ;
V_96 -> V_149 = V_150 ;
V_96 -> V_151 = & V_152 ;
V_96 -> V_131 = & V_16 -> V_131 ;
V_96 -> V_130 = & V_16 -> V_130 ;
V_96 -> V_153 = V_154 | V_155 |
V_156 ;
V_16 -> V_30 = 0 ;
#if F_78 ( V_139 )
for ( V_140 = 0 ; V_140 < V_21 -> V_157 . V_158 ; V_140 ++ )
if ( V_21 -> V_157 . V_159 [ V_140 ] . V_160
== V_161 )
break;
if ( V_140 >= V_21 -> V_157 . V_158 )
return - V_9 ;
V_16 -> V_30 = V_140 ;
#endif
V_8 . V_29 = V_16 -> V_30 ;
V_26 = F_34 ( V_21 , V_29 , V_107 , NULL , & V_8 ) ;
if ( V_26 ) {
F_41 ( V_16 , L_9 ) ;
return V_26 ;
}
V_16 -> V_25 . V_10 = V_105 -> V_10 ;
V_16 -> V_25 . V_14 = V_105 -> V_14 ;
V_16 -> V_25 . V_126 = V_105 -> V_126 ;
V_16 -> V_25 . V_41 = V_105 -> V_41 ;
V_16 -> V_25 . V_2 = V_162 ;
V_16 -> V_76 . V_74 = V_16 -> V_76 . V_73 = 0 ;
V_16 -> V_76 . V_10 = V_105 -> V_10 ;
V_16 -> V_76 . V_14 = V_105 -> V_14 ;
V_16 -> V_80 . V_74 = V_16 -> V_80 . V_73 = 0 ;
V_16 -> V_80 . V_10 = V_105 -> V_10 ;
V_16 -> V_80 . V_14 = V_105 -> V_14 ;
V_26 = F_83 ( & V_16 -> V_96 , V_163 , - 1 ) ;
if ( V_26 ) {
F_41 ( V_16 , L_11 ) ;
return V_26 ;
}
F_84 ( & V_16 -> V_96 , V_16 ) ;
F_70 ( & V_16 -> V_31 , L_12 ,
F_71 ( & V_16 -> V_96 ) ) ;
return V_26 ;
}
