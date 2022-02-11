struct V_1 * F_1 ( int V_2 )
{
return F_2 ( & V_3 , & V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
T_1 V_7 = F_5 ( V_6 -> V_7 ) ;
F_6 ( & V_8 , V_7 + 1 ) ;
}
static int F_7 ( struct V_4 * V_5 , T_2 V_9 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return V_6 ? F_8 ( V_6 ) : 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
if ( V_6 )
F_10 ( V_6 ) ;
return 0 ;
}
static T_3 F_11 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
char * type ;
switch ( V_6 -> type ) {
case V_13 :
type = L_1 ;
break;
case V_14 :
type = L_2 ;
break;
case V_15 :
type = L_3 ;
break;
case V_16 :
type = L_4 ;
break;
case V_17 :
type = L_5 ;
break;
case V_18 :
type = L_6 ;
break;
case V_19 :
type = L_7 ;
break;
case V_20 :
type = L_8 ;
break;
default:
type = L_9 ;
}
return snprintf ( V_12 , V_21 , L_10 , type ) ;
}
static T_3 F_12 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_11 , ( unsigned long ) V_6 -> V_22 ) ;
}
static T_3 F_13 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_12 ,
( unsigned long long ) V_6 -> V_23 ) ;
}
static T_3 F_14 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_24 ) ;
}
static T_3 F_15 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_25 ) ;
}
static T_3 F_16 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
unsigned int V_26 = V_6 -> V_25 >> V_6 -> V_27 ;
return snprintf ( V_12 , V_21 , L_14 , V_26 ) ;
}
static T_3 F_17 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_28 ) ;
}
static T_3 F_18 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_29 ) ;
}
static T_3 F_19 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_10 , V_6 -> V_30 ) ;
}
static T_3 F_20 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_31 ) ;
}
static T_3 F_21 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_32 ) ;
}
static T_3 F_22 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
const char * V_12 , T_4 V_33 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
unsigned int V_32 ;
int V_34 ;
V_34 = F_23 ( V_12 , 0 , & V_32 ) ;
if ( V_34 )
return V_34 ;
V_6 -> V_32 = V_32 ;
return V_33 ;
}
static T_3 F_24 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_35 ) ;
}
static T_3 F_25 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
struct V_36 * V_37 = & V_6 -> V_37 ;
return snprintf ( V_12 , V_21 , L_14 , V_37 -> V_38 ) ;
}
static T_3 F_26 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
struct V_36 * V_37 = & V_6 -> V_37 ;
return snprintf ( V_12 , V_21 , L_14 , V_37 -> V_39 ) ;
}
static T_3 F_27 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
struct V_36 * V_37 = & V_6 -> V_37 ;
return snprintf ( V_12 , V_21 , L_14 , V_37 -> V_40 ) ;
}
static T_3 F_28 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
struct V_36 * V_37 = & V_6 -> V_37 ;
return snprintf ( V_12 , V_21 , L_14 , V_37 -> V_41 ) ;
}
int F_29 ( struct V_1 * V_6 )
{
struct V_42 * V_43 ;
int V_2 , error ;
if ( ! V_6 -> V_44 ) {
switch ( V_6 -> type ) {
case V_14 :
V_6 -> V_44 = & V_45 ;
break;
case V_15 :
V_6 -> V_44 = & V_46 ;
break;
default:
V_6 -> V_44 = & V_47 ;
break;
}
}
F_30 ( V_6 -> V_25 == 0 ) ;
F_31 ( & V_48 ) ;
V_2 = F_32 ( & V_3 , V_6 , 0 , 0 , V_49 ) ;
if ( V_2 < 0 )
goto V_50;
V_6 -> V_7 = V_2 ;
V_6 -> V_51 = 0 ;
if ( V_6 -> V_32 == 0 )
V_6 -> V_32 = V_6 -> V_31 ;
if ( F_33 ( V_6 -> V_24 ) )
V_6 -> V_52 = F_34 ( V_6 -> V_24 ) - 1 ;
else
V_6 -> V_52 = 0 ;
if ( F_33 ( V_6 -> V_25 ) )
V_6 -> V_53 = F_34 ( V_6 -> V_25 ) - 1 ;
else
V_6 -> V_53 = 0 ;
V_6 -> V_54 = ( 1 << V_6 -> V_52 ) - 1 ;
V_6 -> V_55 = ( 1 << V_6 -> V_53 ) - 1 ;
if ( ( V_6 -> V_22 & V_56 ) && ( V_6 -> V_22 & V_57 ) ) {
error = F_35 ( V_6 , 0 , V_6 -> V_23 ) ;
if ( error && error != - V_58 )
F_36 ( V_59
L_15 ,
V_6 -> V_30 ) ;
}
V_6 -> V_5 . type = & V_60 ;
V_6 -> V_5 . V_61 = & V_8 ;
V_6 -> V_5 . V_62 = F_5 ( V_2 ) ;
F_37 ( & V_6 -> V_5 , L_16 , V_2 ) ;
F_38 ( & V_6 -> V_5 , V_6 ) ;
if ( F_39 ( & V_6 -> V_5 ) != 0 )
goto V_63;
F_40 ( & V_8 , V_6 -> V_5 . V_64 , F_5 ( V_2 ) + 1 , NULL ,
L_17 , V_2 ) ;
F_41 ( L_18 , V_2 , V_6 -> V_30 ) ;
F_42 (not, &mtd_notifiers, list)
V_43 -> V_65 ( V_6 ) ;
F_43 ( & V_48 ) ;
F_44 ( V_66 ) ;
return 0 ;
V_63:
F_45 ( & V_3 , V_2 ) ;
V_50:
F_43 ( & V_48 ) ;
return 1 ;
}
int F_46 ( struct V_1 * V_6 )
{
int V_67 ;
struct V_42 * V_43 ;
F_31 ( & V_48 ) ;
if ( F_47 ( & V_3 , V_6 -> V_7 ) != V_6 ) {
V_67 = - V_68 ;
goto V_69;
}
F_42 (not, &mtd_notifiers, list)
V_43 -> remove ( V_6 ) ;
if ( V_6 -> V_51 ) {
F_36 ( V_70 L_19 ,
V_6 -> V_7 , V_6 -> V_30 , V_6 -> V_51 ) ;
V_67 = - V_71 ;
} else {
F_48 ( & V_6 -> V_5 ) ;
F_45 ( & V_3 , V_6 -> V_7 ) ;
F_49 ( V_66 ) ;
V_67 = 0 ;
}
V_69:
F_43 ( & V_48 ) ;
return V_67 ;
}
int F_50 ( struct V_1 * V_6 , const char * const * V_72 ,
struct V_73 * V_74 ,
const struct V_75 * V_76 ,
int V_77 )
{
int V_78 ;
struct V_75 * V_79 ;
V_78 = F_51 ( V_6 , V_72 , & V_79 , V_74 ) ;
if ( V_78 <= 0 && V_77 && V_76 ) {
V_79 = F_52 ( V_76 , sizeof( * V_76 ) * V_77 ,
V_49 ) ;
if ( ! V_79 )
V_78 = - V_80 ;
else
V_78 = V_77 ;
}
if ( V_78 > 0 ) {
V_78 = F_53 ( V_6 , V_79 , V_78 ) ;
F_54 ( V_79 ) ;
} else if ( V_78 == 0 ) {
V_78 = F_29 ( V_6 ) ;
if ( V_78 == 1 )
V_78 = - V_68 ;
}
return V_78 ;
}
int F_55 ( struct V_1 * V_81 )
{
int V_78 ;
V_78 = F_56 ( V_81 ) ;
if ( V_78 )
return V_78 ;
if ( ! F_57 ( & V_81 -> V_5 ) )
return 0 ;
return F_46 ( V_81 ) ;
}
void F_58 ( struct V_42 * V_82 )
{
struct V_1 * V_6 ;
F_31 ( & V_48 ) ;
F_59 ( & V_82 -> V_83 , & V_84 ) ;
F_44 ( V_66 ) ;
F_60 (mtd)
V_82 -> V_65 ( V_6 ) ;
F_43 ( & V_48 ) ;
}
int F_61 ( struct V_42 * V_85 )
{
struct V_1 * V_6 ;
F_31 ( & V_48 ) ;
F_49 ( V_66 ) ;
F_60 (mtd)
V_85 -> remove ( V_6 ) ;
F_62 ( & V_85 -> V_83 ) ;
F_43 ( & V_48 ) ;
return 0 ;
}
struct V_1 * F_63 ( struct V_1 * V_6 , int V_86 )
{
struct V_1 * V_67 = NULL , * V_87 ;
int V_78 = - V_68 ;
F_31 ( & V_48 ) ;
if ( V_86 == - 1 ) {
F_60 (other) {
if ( V_87 == V_6 ) {
V_67 = V_6 ;
break;
}
}
} else if ( V_86 >= 0 ) {
V_67 = F_47 ( & V_3 , V_86 ) ;
if ( V_6 && V_6 != V_67 )
V_67 = NULL ;
}
if ( ! V_67 ) {
V_67 = F_64 ( V_78 ) ;
goto V_88;
}
V_78 = F_65 ( V_67 ) ;
if ( V_78 )
V_67 = F_64 ( V_78 ) ;
V_88:
F_43 ( & V_48 ) ;
return V_67 ;
}
int F_65 ( struct V_1 * V_6 )
{
int V_78 ;
if ( ! F_66 ( V_6 -> V_89 ) )
return - V_68 ;
if ( V_6 -> V_90 ) {
V_78 = V_6 -> V_90 ( V_6 ) ;
if ( V_78 ) {
F_49 ( V_6 -> V_89 ) ;
return V_78 ;
}
}
V_6 -> V_51 ++ ;
return 0 ;
}
struct V_1 * F_67 ( const char * V_30 )
{
int V_78 = - V_68 ;
struct V_1 * V_6 = NULL , * V_87 ;
F_31 ( & V_48 ) ;
F_60 (other) {
if ( ! strcmp ( V_30 , V_87 -> V_30 ) ) {
V_6 = V_87 ;
break;
}
}
if ( ! V_6 )
goto V_91;
V_78 = F_65 ( V_6 ) ;
if ( V_78 )
goto V_91;
F_43 ( & V_48 ) ;
return V_6 ;
V_91:
F_43 ( & V_48 ) ;
return F_64 ( V_78 ) ;
}
void F_68 ( struct V_1 * V_6 )
{
F_31 ( & V_48 ) ;
F_69 ( V_6 ) ;
F_43 ( & V_48 ) ;
}
void F_69 ( struct V_1 * V_6 )
{
-- V_6 -> V_51 ;
F_30 ( V_6 -> V_51 < 0 ) ;
if ( V_6 -> V_92 )
V_6 -> V_92 ( V_6 ) ;
F_49 ( V_6 -> V_89 ) ;
}
int F_70 ( struct V_1 * V_6 , struct V_93 * V_94 )
{
if ( V_94 -> V_95 >= V_6 -> V_23 || V_94 -> V_96 > V_6 -> V_23 - V_94 -> V_95 )
return - V_97 ;
if ( ! ( V_6 -> V_22 & V_56 ) )
return - V_98 ;
V_94 -> V_99 = V_100 ;
if ( ! V_94 -> V_96 ) {
V_94 -> V_9 = V_101 ;
F_71 ( V_94 ) ;
return 0 ;
}
return V_6 -> V_102 ( V_6 , V_94 ) ;
}
int F_72 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 , T_4 * V_104 ,
void * * V_105 , T_6 * V_106 )
{
* V_104 = 0 ;
* V_105 = NULL ;
if ( V_106 )
* V_106 = 0 ;
if ( ! V_6 -> V_107 )
return - V_58 ;
if ( V_103 < 0 || V_103 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_103 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_107 ( V_6 , V_103 , V_96 , V_104 , V_105 , V_106 ) ;
}
int F_73 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 )
{
if ( ! V_6 -> V_107 )
return - V_58 ;
if ( V_103 < 0 || V_103 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_103 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_108 ( V_6 , V_103 , V_96 ) ;
}
unsigned long F_74 ( struct V_1 * V_6 , unsigned long V_96 ,
unsigned long V_109 , unsigned long V_22 )
{
if ( ! V_6 -> V_110 )
return - V_58 ;
if ( V_109 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_109 )
return - V_97 ;
return V_6 -> V_110 ( V_6 , V_96 , V_109 , V_22 ) ;
}
int F_75 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 , T_4 * V_104 ,
T_7 * V_12 )
{
int V_111 ;
* V_104 = 0 ;
if ( V_103 < 0 || V_103 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_103 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
V_111 = V_6 -> V_112 ( V_6 , V_103 , V_96 , V_104 , V_12 ) ;
if ( F_76 ( V_111 < 0 ) )
return V_111 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_111 >= V_6 -> V_32 ? - V_113 : 0 ;
}
int F_77 ( struct V_1 * V_6 , T_5 V_114 , T_4 V_96 , T_4 * V_104 ,
const T_7 * V_12 )
{
* V_104 = 0 ;
if ( V_114 < 0 || V_114 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_114 )
return - V_97 ;
if ( ! V_6 -> V_115 || ! ( V_6 -> V_22 & V_56 ) )
return - V_98 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_115 ( V_6 , V_114 , V_96 , V_104 , V_12 ) ;
}
int F_78 ( struct V_1 * V_6 , T_5 V_114 , T_4 V_96 , T_4 * V_104 ,
const T_7 * V_12 )
{
* V_104 = 0 ;
if ( ! V_6 -> V_116 )
return - V_58 ;
if ( V_114 < 0 || V_114 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_114 )
return - V_97 ;
if ( ! ( V_6 -> V_22 & V_56 ) )
return - V_98 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_116 ( V_6 , V_114 , V_96 , V_104 , V_12 ) ;
}
int F_79 ( struct V_1 * V_6 , T_5 V_103 , struct V_117 * V_118 )
{
int V_111 ;
V_118 -> V_104 = V_118 -> V_119 = 0 ;
if ( ! V_6 -> V_120 )
return - V_58 ;
V_111 = V_6 -> V_120 ( V_6 , V_103 , V_118 ) ;
if ( F_76 ( V_111 < 0 ) )
return V_111 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_111 >= V_6 -> V_32 ? - V_113 : 0 ;
}
int F_80 ( struct V_1 * V_6 , T_4 V_96 , T_4 * V_104 ,
struct V_121 * V_12 )
{
if ( ! V_6 -> V_122 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_122 ( V_6 , V_96 , V_104 , V_12 ) ;
}
int F_81 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 ,
T_4 * V_104 , T_7 * V_12 )
{
* V_104 = 0 ;
if ( ! V_6 -> V_123 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_123 ( V_6 , V_103 , V_96 , V_104 , V_12 ) ;
}
int F_82 ( struct V_1 * V_6 , T_4 V_96 , T_4 * V_104 ,
struct V_121 * V_12 )
{
if ( ! V_6 -> V_124 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_124 ( V_6 , V_96 , V_104 , V_12 ) ;
}
int F_83 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 ,
T_4 * V_104 , T_7 * V_12 )
{
* V_104 = 0 ;
if ( ! V_6 -> V_125 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_125 ( V_6 , V_103 , V_96 , V_104 , V_12 ) ;
}
int F_84 ( struct V_1 * V_6 , T_5 V_114 , T_4 V_96 ,
T_4 * V_104 , T_7 * V_12 )
{
int V_67 ;
* V_104 = 0 ;
if ( ! V_6 -> V_126 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
V_67 = V_6 -> V_126 ( V_6 , V_114 , V_96 , V_104 , V_12 ) ;
if ( V_67 )
return V_67 ;
return ( * V_104 ) ? 0 : - V_127 ;
}
int F_85 ( struct V_1 * V_6 , T_5 V_103 , T_4 V_96 )
{
if ( ! V_6 -> V_128 )
return - V_58 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_128 ( V_6 , V_103 , V_96 ) ;
}
int F_86 ( struct V_1 * V_6 , T_5 V_129 , T_8 V_96 )
{
if ( ! V_6 -> V_130 )
return - V_58 ;
if ( V_129 < 0 || V_129 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_129 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_130 ( V_6 , V_129 , V_96 ) ;
}
int F_35 ( struct V_1 * V_6 , T_5 V_129 , T_8 V_96 )
{
if ( ! V_6 -> V_131 )
return - V_58 ;
if ( V_129 < 0 || V_129 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_129 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_131 ( V_6 , V_129 , V_96 ) ;
}
int F_87 ( struct V_1 * V_6 , T_5 V_129 , T_8 V_96 )
{
if ( ! V_6 -> V_132 )
return - V_58 ;
if ( V_129 < 0 || V_129 >= V_6 -> V_23 || V_96 > V_6 -> V_23 - V_129 )
return - V_97 ;
if ( ! V_96 )
return 0 ;
return V_6 -> V_132 ( V_6 , V_129 , V_96 ) ;
}
int F_88 ( struct V_1 * V_6 , T_5 V_129 )
{
if ( V_129 < 0 || V_129 >= V_6 -> V_23 )
return - V_97 ;
if ( ! V_6 -> V_133 )
return 0 ;
return V_6 -> V_133 ( V_6 , V_129 ) ;
}
int F_89 ( struct V_1 * V_6 , T_5 V_129 )
{
if ( V_129 < 0 || V_129 >= V_6 -> V_23 )
return - V_97 ;
if ( ! V_6 -> V_134 )
return 0 ;
return V_6 -> V_134 ( V_6 , V_129 ) ;
}
int F_90 ( struct V_1 * V_6 , T_5 V_129 )
{
if ( ! V_6 -> V_135 )
return - V_58 ;
if ( V_129 < 0 || V_129 >= V_6 -> V_23 )
return - V_97 ;
if ( ! ( V_6 -> V_22 & V_56 ) )
return - V_98 ;
return V_6 -> V_135 ( V_6 , V_129 ) ;
}
static int F_91 ( struct V_1 * V_6 , const struct V_136 * V_137 ,
unsigned long V_33 , T_5 V_114 , T_4 * V_104 )
{
unsigned long V_2 ;
T_4 V_138 = 0 , V_139 ;
int V_67 = 0 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ ) {
if ( ! V_137 [ V_2 ] . V_140 )
continue;
V_67 = F_77 ( V_6 , V_114 , V_137 [ V_2 ] . V_140 , & V_139 ,
V_137 [ V_2 ] . V_141 ) ;
V_138 += V_139 ;
if ( V_67 || V_139 != V_137 [ V_2 ] . V_140 )
break;
V_114 += V_137 [ V_2 ] . V_140 ;
}
* V_104 = V_138 ;
return V_67 ;
}
int F_92 ( struct V_1 * V_6 , const struct V_136 * V_137 ,
unsigned long V_33 , T_5 V_114 , T_4 * V_104 )
{
* V_104 = 0 ;
if ( ! ( V_6 -> V_22 & V_56 ) )
return - V_98 ;
if ( ! V_6 -> V_142 )
return F_91 ( V_6 , V_137 , V_33 , V_114 , V_104 ) ;
return V_6 -> V_142 ( V_6 , V_137 , V_33 , V_114 , V_104 ) ;
}
void * F_93 ( const struct V_1 * V_6 , T_4 * V_23 )
{
T_9 V_22 = V_143 | V_144 |
V_145 | V_146 ;
T_4 V_147 = F_94 ( T_4 , V_6 -> V_25 , V_21 ) ;
void * V_148 ;
* V_23 = F_95 ( T_4 , * V_23 , V_149 ) ;
while ( * V_23 > V_147 ) {
V_148 = F_96 ( * V_23 , V_22 ) ;
if ( V_148 )
return V_148 ;
* V_23 >>= 1 ;
* V_23 = F_97 ( * V_23 , V_6 -> V_25 ) ;
}
return F_96 ( * V_23 , V_49 ) ;
}
static int F_98 ( struct V_150 * V_151 , void * V_152 )
{
struct V_1 * V_6 ;
F_99 ( V_151 , L_20 ) ;
F_31 ( & V_48 ) ;
F_60 (mtd) {
F_100 ( V_151 , L_21 ,
V_6 -> V_7 , ( unsigned long long ) V_6 -> V_23 ,
V_6 -> V_24 , V_6 -> V_30 ) ;
}
F_43 ( & V_48 ) ;
return 0 ;
}
static int F_101 ( struct V_153 * V_153 , struct V_154 * V_154 )
{
return F_102 ( V_154 , F_98 , NULL ) ;
}
static int T_10 F_103 ( struct V_44 * V_155 , const char * V_30 )
{
int V_67 ;
V_67 = F_104 ( V_155 ) ;
if ( ! V_67 )
V_67 = F_105 ( V_155 , NULL , L_22 , V_30 ) ;
if ( V_67 )
F_106 ( V_155 ) ;
return V_67 ;
}
static int T_10 F_107 ( void )
{
int V_67 ;
V_67 = F_108 ( & V_8 ) ;
if ( V_67 )
goto V_156;
V_67 = F_103 ( & V_47 , L_23 ) ;
if ( V_67 )
goto V_157;
V_67 = F_103 ( & V_46 , L_24 ) ;
if ( V_67 )
goto V_158;
V_67 = F_103 ( & V_45 , L_25 ) ;
if ( V_67 )
goto V_159;
V_160 = F_109 ( L_26 , 0 , NULL , & V_161 ) ;
V_67 = F_110 () ;
if ( V_67 )
goto V_162;
return 0 ;
V_162:
if ( V_160 )
F_111 ( L_26 , NULL ) ;
V_159:
F_106 ( & V_46 ) ;
V_158:
F_106 ( & V_47 ) ;
V_157:
F_112 ( & V_8 ) ;
V_156:
F_113 ( L_27 , V_67 ) ;
return V_67 ;
}
static void T_11 F_114 ( void )
{
F_115 () ;
if ( V_160 )
F_111 ( L_26 , NULL ) ;
F_112 ( & V_8 ) ;
F_106 ( & V_47 ) ;
F_106 ( & V_46 ) ;
F_106 ( & V_45 ) ;
}
