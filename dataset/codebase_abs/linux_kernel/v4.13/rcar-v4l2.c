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
static void F_6 ( struct V_15 * V_16 )
{
V_16 -> V_17 . V_18 = V_16 -> V_17 . V_19 = 0 ;
V_16 -> V_17 . V_10 = V_16 -> V_20 . V_10 ;
V_16 -> V_17 . V_14 = V_16 -> V_20 . V_14 ;
V_16 -> V_21 . V_18 = V_16 -> V_21 . V_19 = 0 ;
V_16 -> V_21 . V_10 = V_16 -> V_22 . V_10 ;
V_16 -> V_21 . V_14 = V_16 -> V_22 . V_14 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_23 V_8 = {
. V_24 = V_25 ,
} ;
struct V_26 * V_27 = & V_8 . V_22 ;
int V_28 ;
V_8 . V_29 = V_16 -> V_30 . V_31 ;
V_28 = F_8 ( F_9 ( V_16 ) , V_29 , V_32 , NULL , & V_8 ) ;
if ( V_28 )
return V_28 ;
V_16 -> V_22 . V_10 = V_27 -> V_10 ;
V_16 -> V_22 . V_14 = V_27 -> V_14 ;
V_16 -> V_22 . V_33 = V_27 -> V_33 ;
V_16 -> V_22 . V_34 = V_27 -> V_34 ;
if ( V_16 -> V_22 . V_34 == V_35 &&
F_10 ( F_9 ( V_16 ) , V_36 , V_37 ) )
V_16 -> V_22 . V_34 = V_38 ;
switch ( V_16 -> V_22 . V_34 ) {
case V_39 :
case V_40 :
case V_35 :
V_16 -> V_22 . V_14 /= 2 ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_38 :
break;
default:
V_16 -> V_22 . V_34 = V_41 ;
break;
}
F_6 ( V_16 ) ;
V_16 -> V_22 . V_13 = F_3 ( & V_16 -> V_22 ) ;
V_16 -> V_22 . V_44 = F_5 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 ,
T_1 V_24 ,
struct V_6 * V_7 ,
struct V_45 * V_20 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_23 V_22 = {
. V_24 = V_24 ,
} ;
enum V_50 V_34 ;
int V_28 ;
V_47 = F_9 ( V_16 ) ;
F_12 ( & V_22 . V_22 , V_7 , V_16 -> V_30 . V_51 ) ;
V_49 = F_13 ( V_47 ) ;
if ( V_49 == NULL )
return - V_52 ;
V_22 . V_29 = V_16 -> V_30 . V_31 ;
V_34 = V_7 -> V_34 ;
V_28 = F_8 ( V_47 , V_29 , V_53 , V_49 , & V_22 ) ;
if ( V_28 < 0 && V_28 != - V_54 )
goto V_55;
F_14 ( V_7 , & V_22 . V_22 ) ;
V_7 -> V_34 = V_34 ;
V_20 -> V_10 = V_7 -> V_10 ;
V_20 -> V_14 = V_7 -> V_14 ;
F_15 ( V_16 , L_1 , V_20 -> V_10 ,
V_20 -> V_14 ) ;
V_55:
F_16 ( V_49 ) ;
return V_28 ;
}
static int F_17 ( struct V_15 * V_16 ,
T_1 V_24 ,
struct V_6 * V_7 ,
struct V_45 * V_20 )
{
T_1 V_56 , V_57 , V_58 ;
int V_28 ;
V_56 = V_7 -> V_10 ;
V_57 = V_7 -> V_14 ;
if ( V_7 -> V_34 == V_59 )
V_7 -> V_34 = V_16 -> V_22 . V_34 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
F_15 ( V_16 , L_2 ,
V_7 -> V_2 , V_60 ) ;
V_7 -> V_2 = V_60 ;
}
V_7 -> V_13 = 0 ;
V_7 -> V_44 = 0 ;
V_28 = F_11 ( V_16 , V_24 , V_7 , V_20 ) ;
if ( V_28 )
return V_28 ;
switch ( V_7 -> V_34 ) {
case V_39 :
case V_40 :
case V_35 :
V_7 -> V_14 /= 2 ;
V_20 -> V_14 /= 2 ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_38 :
break;
default:
V_7 -> V_34 = V_41 ;
break;
}
if ( V_20 -> V_10 != V_56 || V_20 -> V_14 != V_57 )
F_18 ( V_16 , V_7 , V_56 , V_57 ) ;
V_58 = V_16 -> V_22 . V_2 == V_12 ? 5 : 1 ;
F_19 ( & V_7 -> V_10 , 2 , V_61 , V_58 ,
& V_7 -> V_14 , 4 , V_62 , 2 , 0 ) ;
V_7 -> V_13 = F_20 ( T_1 , V_7 -> V_13 ,
F_3 ( V_7 ) ) ;
V_7 -> V_44 = F_20 ( T_1 , V_7 -> V_44 ,
F_5 ( V_7 ) ) ;
if ( V_16 -> V_63 == V_64 && V_7 -> V_2 == V_65 ) {
F_21 ( V_16 , L_3 ) ;
return - V_9 ;
}
F_15 ( V_16 , L_4 ,
V_56 , V_57 , V_7 -> V_10 , V_7 -> V_14 ,
V_7 -> V_13 , V_7 -> V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_66 * V_66 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
F_24 ( V_69 -> V_70 , V_71 , sizeof( V_69 -> V_70 ) ) ;
F_24 ( V_69 -> V_72 , L_5 , sizeof( V_69 -> V_72 ) ) ;
snprintf ( V_69 -> V_73 , sizeof( V_69 -> V_73 ) , L_6 ,
F_25 ( V_16 -> V_74 ) ) ;
return 0 ;
}
static int F_26 ( struct V_66 * V_66 , void * V_67 ,
struct V_75 * V_76 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_45 V_20 ;
return F_17 ( V_16 , V_77 , & V_76 -> V_8 . V_7 ,
& V_20 ) ;
}
static int F_27 ( struct V_66 * V_66 , void * V_67 ,
struct V_75 * V_76 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_45 V_20 ;
int V_28 ;
if ( F_28 ( & V_16 -> V_78 ) )
return - V_79 ;
V_28 = F_17 ( V_16 , V_25 , & V_76 -> V_8 . V_7 ,
& V_20 ) ;
if ( V_28 )
return V_28 ;
V_16 -> V_20 . V_10 = V_20 . V_10 ;
V_16 -> V_20 . V_14 = V_20 . V_14 ;
V_16 -> V_22 = V_76 -> V_8 . V_7 ;
F_6 ( V_16 ) ;
return 0 ;
}
static int F_29 ( struct V_66 * V_66 , void * V_67 ,
struct V_75 * V_76 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
V_76 -> V_8 . V_7 = V_16 -> V_22 ;
return 0 ;
}
static int F_30 ( struct V_66 * V_66 , void * V_67 ,
struct V_80 * V_76 )
{
if ( V_76 -> V_81 >= F_2 ( V_4 ) )
return - V_9 ;
V_76 -> V_2 = V_4 [ V_76 -> V_81 ] . V_5 ;
return 0 ;
}
static int F_31 ( struct V_66 * V_66 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
if ( V_84 -> type != V_85 )
return - V_9 ;
switch ( V_84 -> V_86 ) {
case V_87 :
case V_88 :
V_84 -> V_89 . V_19 = V_84 -> V_89 . V_18 = 0 ;
V_84 -> V_89 . V_10 = V_16 -> V_20 . V_10 ;
V_84 -> V_89 . V_14 = V_16 -> V_20 . V_14 ;
break;
case V_90 :
V_84 -> V_89 = V_16 -> V_17 ;
break;
case V_91 :
case V_92 :
V_84 -> V_89 . V_19 = V_84 -> V_89 . V_18 = 0 ;
V_84 -> V_89 . V_10 = V_16 -> V_22 . V_10 ;
V_84 -> V_89 . V_14 = V_16 -> V_22 . V_14 ;
break;
case V_93 :
V_84 -> V_89 = V_16 -> V_21 ;
break;
default:
return - V_9 ;
}
return 0 ;
}
static int F_32 ( struct V_66 * V_66 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
const struct V_1 * V_8 ;
struct V_94 V_89 = V_84 -> V_89 ;
struct V_94 V_95 ;
struct V_94 V_96 = {
. V_10 = 6 ,
. V_14 = 2 ,
} ;
if ( V_84 -> type != V_85 )
return - V_9 ;
F_33 ( & V_89 , & V_96 ) ;
switch ( V_84 -> V_86 ) {
case V_90 :
V_95 . V_18 = V_95 . V_19 = 0 ;
V_95 . V_10 = V_16 -> V_20 . V_10 ;
V_95 . V_14 = V_16 -> V_20 . V_14 ;
F_34 ( & V_89 , & V_95 ) ;
F_19 ( & V_89 . V_10 , 2 , V_16 -> V_20 . V_10 , 1 ,
& V_89 . V_14 , 4 , V_16 -> V_20 . V_14 , 2 , 0 ) ;
V_89 . V_18 = F_35 ( V_97 , V_89 . V_18 , 0 , V_16 -> V_20 . V_14 - V_89 . V_14 ) ;
V_89 . V_19 = F_35 ( V_97 , V_89 . V_19 , 0 , V_16 -> V_20 . V_10 - V_89 . V_10 ) ;
V_16 -> V_17 = V_84 -> V_89 = V_89 ;
F_15 ( V_16 , L_7 ,
V_89 . V_10 , V_89 . V_14 , V_89 . V_19 , V_89 . V_18 ,
V_16 -> V_20 . V_10 , V_16 -> V_20 . V_14 ) ;
break;
case V_93 :
V_95 . V_18 = V_95 . V_19 = 0 ;
V_95 . V_10 = V_16 -> V_22 . V_10 ;
V_95 . V_14 = V_16 -> V_22 . V_14 ;
F_34 ( & V_89 , & V_95 ) ;
while ( ( V_89 . V_18 * V_16 -> V_22 . V_13 ) & V_98 )
V_89 . V_18 -- ;
V_8 = F_1 ( V_16 -> V_22 . V_2 ) ;
while ( ( V_89 . V_19 * V_8 -> V_11 ) & V_98 )
V_89 . V_19 -- ;
V_16 -> V_21 = V_84 -> V_89 = V_89 ;
F_15 ( V_16 , L_8 ,
V_89 . V_10 , V_89 . V_14 , V_89 . V_19 , V_89 . V_18 ,
V_16 -> V_22 . V_10 , V_16 -> V_22 . V_14 ) ;
break;
default:
return - V_9 ;
}
F_36 ( V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_66 * V_66 , void * V_67 ,
struct V_99 * V_17 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
if ( V_17 -> type != V_85 )
return - V_9 ;
return F_8 ( V_47 , V_36 , V_100 , & V_17 -> V_101 ) ;
}
static int F_38 ( struct V_66 * V_66 , void * V_67 ,
struct V_102 * V_3 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
if ( V_3 -> V_81 != 0 )
return - V_9 ;
V_28 = F_8 ( V_47 , V_36 , V_103 , & V_3 -> V_104 ) ;
if ( V_28 < 0 && V_28 != - V_54 && V_28 != - V_105 )
return V_28 ;
V_3 -> type = V_106 ;
if ( F_10 ( V_47 , V_29 , V_107 ) ) {
V_3 -> V_108 = V_109 ;
V_3 -> V_110 = 0 ;
} else {
V_3 -> V_108 = V_111 ;
V_3 -> V_110 = V_16 -> V_112 . V_113 ;
}
F_24 ( V_3 -> V_114 , L_9 , sizeof( V_3 -> V_114 ) ) ;
return 0 ;
}
static int F_39 ( struct V_66 * V_66 , void * V_67 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_40 ( struct V_66 * V_66 , void * V_67 , unsigned int V_3 )
{
if ( V_3 > 0 )
return - V_9 ;
return 0 ;
}
static int F_41 ( struct V_66 * V_66 , void * V_67 , T_2 * V_115 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
return F_8 ( V_47 , V_36 , V_116 , V_115 ) ;
}
static int F_42 ( struct V_66 * V_66 , void * V_67 , T_2 V_115 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
int V_28 ;
V_28 = F_8 ( F_9 ( V_16 ) , V_36 , V_117 , V_115 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_7 ( V_16 ) ;
}
static int F_43 ( struct V_66 * V_66 , void * V_67 , T_2 * V_115 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
return F_8 ( V_47 , V_36 , V_37 , V_115 ) ;
}
static int F_44 ( struct V_118 * V_82 ,
const struct V_119 * V_120 )
{
switch ( V_120 -> type ) {
case V_121 :
return F_45 ( V_82 , V_120 , 4 , NULL ) ;
}
return F_46 ( V_82 , V_120 ) ;
}
static int F_47 ( struct V_66 * V_66 , void * V_122 ,
struct V_123 * V_124 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
if ( V_124 -> V_29 )
return - V_9 ;
V_124 -> V_29 = V_16 -> V_30 . V_125 ;
V_28 = F_8 ( V_47 , V_29 , V_126 , V_124 ) ;
V_124 -> V_29 = 0 ;
return V_28 ;
}
static int F_48 ( struct V_66 * V_66 , void * V_122 ,
struct V_127 * V_124 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
V_28 = F_8 ( V_47 , V_36 , V_128 , V_124 ) ;
if ( V_28 )
return V_28 ;
return F_7 ( V_16 ) ;
}
static int F_49 ( struct V_66 * V_66 , void * V_122 ,
struct V_127 * V_124 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
return F_8 ( V_47 , V_36 , V_129 , V_124 ) ;
}
static int F_50 ( struct V_66 * V_66 , void * V_122 ,
struct V_127 * V_124 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
return F_8 ( V_47 , V_36 , V_130 , V_124 ) ;
}
static int F_51 ( struct V_66 * V_66 , void * V_122 ,
struct V_131 * V_69 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
if ( V_69 -> V_29 )
return - V_9 ;
V_69 -> V_29 = V_16 -> V_30 . V_125 ;
V_28 = F_8 ( V_47 , V_29 , V_107 , V_69 ) ;
V_69 -> V_29 = 0 ;
return V_28 ;
}
static int F_52 ( struct V_66 * V_66 , void * V_82 , struct V_132 * V_133 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
if ( V_133 -> V_29 )
return - V_9 ;
V_133 -> V_29 = V_16 -> V_30 . V_125 ;
V_28 = F_8 ( V_47 , V_29 , V_134 , V_133 ) ;
V_133 -> V_29 = 0 ;
return V_28 ;
}
static int F_53 ( struct V_66 * V_66 , void * V_82 , struct V_132 * V_133 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
if ( V_133 -> V_29 )
return - V_9 ;
V_133 -> V_29 = V_16 -> V_30 . V_125 ;
V_28 = F_8 ( V_47 , V_29 , V_135 , V_133 ) ;
V_133 -> V_29 = 0 ;
return V_28 ;
}
static int F_54 ( struct V_15 * V_16 )
{
int V_28 ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
F_55 ( V_16 -> V_136 . V_74 ) ;
V_28 = F_8 ( V_47 , V_137 , V_138 , 1 ) ;
if ( V_28 < 0 && V_28 != - V_54 && V_28 != - V_105 )
return V_28 ;
return 0 ;
}
static int F_56 ( struct V_15 * V_16 )
{
int V_28 ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
V_28 = F_8 ( V_47 , V_137 , V_138 , 0 ) ;
F_57 ( V_16 -> V_136 . V_74 ) ;
if ( V_28 < 0 && V_28 != - V_54 && V_28 != - V_105 )
return V_28 ;
return 0 ;
}
static int F_58 ( struct V_66 * V_66 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
int V_28 ;
struct V_75 V_76 = {
. type = V_85 ,
. V_8 . V_7 = {
. V_10 = V_16 -> V_22 . V_10 ,
. V_14 = V_16 -> V_22 . V_14 ,
. V_34 = V_16 -> V_22 . V_34 ,
. V_33 = V_16 -> V_22 . V_33 ,
. V_2 = V_16 -> V_22 . V_2 ,
} ,
} ;
V_28 = F_54 ( V_16 ) ;
if ( V_28 < 0 )
return V_28 ;
F_59 ( & V_16 -> V_112 . V_74 ) ;
V_28 = F_60 ( & V_16 -> V_112 . V_74 ) ;
if ( V_28 < 0 && V_28 != - V_139 )
goto V_140;
V_28 = F_27 ( V_66 , NULL , & V_76 ) ;
if ( V_28 < 0 )
goto V_141;
F_61 ( & V_16 -> V_142 ) ;
return 0 ;
V_141:
F_62 ( & V_16 -> V_112 . V_74 ) ;
V_140:
F_56 ( V_16 ) ;
return V_28 ;
}
static int F_63 ( struct V_66 * V_66 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
int V_28 ;
F_64 ( & V_16 -> V_143 ) ;
V_66 -> V_144 = V_16 ;
V_28 = F_65 ( V_66 ) ;
if ( V_28 )
goto V_145;
if ( ! F_66 ( V_66 ) )
goto V_145;
if ( F_58 ( V_66 ) ) {
F_67 ( V_66 ) ;
V_28 = - V_105 ;
}
V_145:
F_68 ( & V_16 -> V_143 ) ;
return V_28 ;
}
static int F_69 ( struct V_66 * V_66 )
{
struct V_15 * V_16 = F_23 ( V_66 ) ;
bool V_146 ;
int V_28 ;
F_64 ( & V_16 -> V_143 ) ;
V_146 = F_66 ( V_66 ) ;
V_28 = F_70 ( V_66 , NULL ) ;
if ( V_146 ) {
F_71 ( & V_16 -> V_112 . V_74 ) ;
F_62 ( & V_16 -> V_112 . V_74 ) ;
F_56 ( V_16 ) ;
}
F_68 ( & V_16 -> V_143 ) ;
return V_28 ;
}
void F_72 ( struct V_15 * V_16 )
{
F_73 ( & V_16 -> V_136 , L_10 ,
F_74 ( & V_16 -> V_112 ) ) ;
F_75 ( & V_16 -> V_142 ) ;
F_76 ( & V_16 -> V_112 ) ;
}
static void F_77 ( struct V_46 * V_47 ,
unsigned int V_147 , void * V_148 )
{
struct V_15 * V_16 =
F_78 ( V_47 -> V_136 , struct V_15 , V_136 ) ;
switch ( V_147 ) {
case V_149 :
F_79 ( & V_16 -> V_112 , V_148 ) ;
break;
default:
break;
}
}
int F_80 ( struct V_15 * V_16 )
{
struct V_150 * V_112 = & V_16 -> V_112 ;
struct V_46 * V_47 = F_9 ( V_16 ) ;
int V_28 ;
F_81 ( V_47 , V_16 ) ;
V_16 -> V_136 . V_151 = F_77 ;
V_28 = F_8 ( V_47 , V_36 , V_152 , & V_16 -> V_112 . V_113 ) ;
if ( V_28 < 0 && V_28 != - V_54 && V_28 != - V_105 )
return V_28 ;
if ( V_16 -> V_112 . V_113 == 0 ) {
F_82 ( & V_16 -> V_112 , V_153 ) ;
F_82 ( & V_16 -> V_112 , V_154 ) ;
F_82 ( & V_16 -> V_112 , V_155 ) ;
F_82 ( & V_16 -> V_112 , V_156 ) ;
}
V_28 = F_83 ( & V_16 -> V_142 , 16 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_84 ( & V_16 -> V_142 , V_47 -> V_142 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_112 -> V_157 = & V_158 ;
V_112 -> V_136 = & V_16 -> V_136 ;
V_112 -> V_78 = & V_16 -> V_78 ;
F_24 ( V_112 -> V_114 , V_71 , sizeof( V_112 -> V_114 ) ) ;
V_112 -> V_159 = V_160 ;
V_112 -> V_161 = & V_162 ;
V_112 -> V_143 = & V_16 -> V_143 ;
V_112 -> V_142 = & V_16 -> V_142 ;
V_112 -> V_163 = V_164 | V_165 |
V_166 ;
V_16 -> V_22 . V_2 = V_60 ;
F_7 ( V_16 ) ;
V_28 = F_85 ( & V_16 -> V_112 , V_167 , - 1 ) ;
if ( V_28 ) {
F_21 ( V_16 , L_11 ) ;
return V_28 ;
}
F_86 ( & V_16 -> V_112 , V_16 ) ;
F_73 ( & V_16 -> V_136 , L_12 ,
F_74 ( & V_16 -> V_112 ) ) ;
return V_28 ;
}
