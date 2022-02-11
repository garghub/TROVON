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
unsigned F_29 ( struct V_1 * V_6 )
{
switch ( V_6 -> type ) {
case V_14 :
return V_42 | V_43 | V_44 |
V_45 | V_46 ;
case V_15 :
return V_42 | V_43 | V_44 |
V_45 ;
default:
return V_42 ;
}
}
static int F_30 ( struct V_47 * V_48 , unsigned long V_9 ,
void * V_49 )
{
struct V_1 * V_6 ;
V_6 = F_31 ( V_48 , struct V_1 , V_50 ) ;
V_6 -> V_51 ( V_6 ) ;
return V_52 ;
}
int F_32 ( struct V_1 * V_6 )
{
struct V_53 * V_54 ;
int V_2 , error ;
V_6 -> V_55 = & V_56 ;
F_33 ( V_6 -> V_25 == 0 ) ;
F_34 ( & V_57 ) ;
V_2 = F_35 ( & V_3 , V_6 , 0 , 0 , V_58 ) ;
if ( V_2 < 0 )
goto V_59;
V_6 -> V_7 = V_2 ;
V_6 -> V_60 = 0 ;
if ( V_6 -> V_32 == 0 )
V_6 -> V_32 = V_6 -> V_31 ;
if ( F_36 ( V_6 -> V_24 ) )
V_6 -> V_61 = F_37 ( V_6 -> V_24 ) - 1 ;
else
V_6 -> V_61 = 0 ;
if ( F_36 ( V_6 -> V_25 ) )
V_6 -> V_62 = F_37 ( V_6 -> V_25 ) - 1 ;
else
V_6 -> V_62 = 0 ;
V_6 -> V_63 = ( 1 << V_6 -> V_61 ) - 1 ;
V_6 -> V_64 = ( 1 << V_6 -> V_62 ) - 1 ;
if ( ( V_6 -> V_22 & V_65 ) && ( V_6 -> V_22 & V_66 ) ) {
error = F_38 ( V_6 , 0 , V_6 -> V_23 ) ;
if ( error && error != - V_67 )
F_39 ( V_68
L_15 ,
V_6 -> V_30 ) ;
}
V_6 -> V_5 . type = & V_69 ;
V_6 -> V_5 . V_70 = & V_8 ;
V_6 -> V_5 . V_71 = F_5 ( V_2 ) ;
F_40 ( & V_6 -> V_5 , L_16 , V_2 ) ;
F_41 ( & V_6 -> V_5 , V_6 ) ;
if ( F_42 ( & V_6 -> V_5 ) != 0 )
goto V_72;
F_43 ( & V_8 , V_6 -> V_5 . V_73 , F_5 ( V_2 ) + 1 , NULL ,
L_17 , V_2 ) ;
F_44 ( L_18 , V_2 , V_6 -> V_30 ) ;
F_45 (not, &mtd_notifiers, list)
V_54 -> V_74 ( V_6 ) ;
F_46 ( & V_57 ) ;
F_47 ( V_75 ) ;
return 0 ;
V_72:
F_48 ( & V_3 , V_2 ) ;
V_59:
F_46 ( & V_57 ) ;
return 1 ;
}
int F_49 ( struct V_1 * V_6 )
{
int V_76 ;
struct V_53 * V_54 ;
F_34 ( & V_57 ) ;
if ( F_50 ( & V_3 , V_6 -> V_7 ) != V_6 ) {
V_76 = - V_77 ;
goto V_78;
}
F_45 (not, &mtd_notifiers, list)
V_54 -> remove ( V_6 ) ;
if ( V_6 -> V_60 ) {
F_39 ( V_79 L_19 ,
V_6 -> V_7 , V_6 -> V_30 , V_6 -> V_60 ) ;
V_76 = - V_80 ;
} else {
F_51 ( & V_6 -> V_5 ) ;
F_48 ( & V_3 , V_6 -> V_7 ) ;
F_52 ( V_75 ) ;
V_76 = 0 ;
}
V_78:
F_46 ( & V_57 ) ;
return V_76 ;
}
int F_53 ( struct V_1 * V_6 , const char * const * V_81 ,
struct V_82 * V_83 ,
const struct V_84 * V_85 ,
int V_86 )
{
int V_87 ;
struct V_84 * V_88 ;
V_87 = F_54 ( V_6 , V_81 , & V_88 , V_83 ) ;
if ( V_87 <= 0 && V_86 && V_85 ) {
V_88 = F_55 ( V_85 , sizeof( * V_85 ) * V_86 ,
V_58 ) ;
if ( ! V_88 )
V_87 = - V_89 ;
else
V_87 = V_86 ;
}
if ( V_87 > 0 ) {
V_87 = F_56 ( V_6 , V_88 , V_87 ) ;
F_57 ( V_88 ) ;
} else if ( V_87 == 0 ) {
V_87 = F_32 ( V_6 ) ;
if ( V_87 == 1 )
V_87 = - V_77 ;
}
if ( V_6 -> V_51 && ! V_6 -> V_50 . V_90 ) {
V_6 -> V_50 . V_90 = F_30 ;
F_58 ( & V_6 -> V_50 ) ;
}
return V_87 ;
}
int F_59 ( struct V_1 * V_91 )
{
int V_87 ;
if ( V_91 -> V_51 )
F_60 ( & V_91 -> V_50 ) ;
V_87 = F_61 ( V_91 ) ;
if ( V_87 )
return V_87 ;
if ( ! F_62 ( & V_91 -> V_5 ) )
return 0 ;
return F_49 ( V_91 ) ;
}
void F_63 ( struct V_53 * V_92 )
{
struct V_1 * V_6 ;
F_34 ( & V_57 ) ;
F_64 ( & V_92 -> V_93 , & V_94 ) ;
F_47 ( V_75 ) ;
F_65 (mtd)
V_92 -> V_74 ( V_6 ) ;
F_46 ( & V_57 ) ;
}
int F_66 ( struct V_53 * V_95 )
{
struct V_1 * V_6 ;
F_34 ( & V_57 ) ;
F_52 ( V_75 ) ;
F_65 (mtd)
V_95 -> remove ( V_6 ) ;
F_67 ( & V_95 -> V_93 ) ;
F_46 ( & V_57 ) ;
return 0 ;
}
struct V_1 * F_68 ( struct V_1 * V_6 , int V_96 )
{
struct V_1 * V_76 = NULL , * V_97 ;
int V_87 = - V_77 ;
F_34 ( & V_57 ) ;
if ( V_96 == - 1 ) {
F_65 (other) {
if ( V_97 == V_6 ) {
V_76 = V_6 ;
break;
}
}
} else if ( V_96 >= 0 ) {
V_76 = F_50 ( & V_3 , V_96 ) ;
if ( V_6 && V_6 != V_76 )
V_76 = NULL ;
}
if ( ! V_76 ) {
V_76 = F_69 ( V_87 ) ;
goto V_98;
}
V_87 = F_70 ( V_76 ) ;
if ( V_87 )
V_76 = F_69 ( V_87 ) ;
V_98:
F_46 ( & V_57 ) ;
return V_76 ;
}
int F_70 ( struct V_1 * V_6 )
{
int V_87 ;
if ( ! F_71 ( V_6 -> V_99 ) )
return - V_77 ;
if ( V_6 -> V_100 ) {
V_87 = V_6 -> V_100 ( V_6 ) ;
if ( V_87 ) {
F_52 ( V_6 -> V_99 ) ;
return V_87 ;
}
}
V_6 -> V_60 ++ ;
return 0 ;
}
struct V_1 * F_72 ( const char * V_30 )
{
int V_87 = - V_77 ;
struct V_1 * V_6 = NULL , * V_97 ;
F_34 ( & V_57 ) ;
F_65 (other) {
if ( ! strcmp ( V_30 , V_97 -> V_30 ) ) {
V_6 = V_97 ;
break;
}
}
if ( ! V_6 )
goto V_101;
V_87 = F_70 ( V_6 ) ;
if ( V_87 )
goto V_101;
F_46 ( & V_57 ) ;
return V_6 ;
V_101:
F_46 ( & V_57 ) ;
return F_69 ( V_87 ) ;
}
void F_73 ( struct V_1 * V_6 )
{
F_34 ( & V_57 ) ;
F_74 ( V_6 ) ;
F_46 ( & V_57 ) ;
}
void F_74 ( struct V_1 * V_6 )
{
-- V_6 -> V_60 ;
F_33 ( V_6 -> V_60 < 0 ) ;
if ( V_6 -> V_102 )
V_6 -> V_102 ( V_6 ) ;
F_52 ( V_6 -> V_99 ) ;
}
int F_75 ( struct V_1 * V_6 , struct V_103 * V_104 )
{
if ( V_104 -> V_105 >= V_6 -> V_23 || V_104 -> V_106 > V_6 -> V_23 - V_104 -> V_105 )
return - V_107 ;
if ( ! ( V_6 -> V_22 & V_65 ) )
return - V_108 ;
V_104 -> V_109 = V_110 ;
if ( ! V_104 -> V_106 ) {
V_104 -> V_9 = V_111 ;
F_76 ( V_104 ) ;
return 0 ;
}
return V_6 -> V_112 ( V_6 , V_104 ) ;
}
int F_77 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 , T_4 * V_114 ,
void * * V_115 , T_6 * V_116 )
{
* V_114 = 0 ;
* V_115 = NULL ;
if ( V_116 )
* V_116 = 0 ;
if ( ! V_6 -> V_117 )
return - V_67 ;
if ( V_113 < 0 || V_113 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_113 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_117 ( V_6 , V_113 , V_106 , V_114 , V_115 , V_116 ) ;
}
int F_78 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 )
{
if ( ! V_6 -> V_117 )
return - V_67 ;
if ( V_113 < 0 || V_113 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_113 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_118 ( V_6 , V_113 , V_106 ) ;
}
unsigned long F_79 ( struct V_1 * V_6 , unsigned long V_106 ,
unsigned long V_119 , unsigned long V_22 )
{
if ( ! V_6 -> V_120 )
return - V_67 ;
if ( V_119 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_119 )
return - V_107 ;
return V_6 -> V_120 ( V_6 , V_106 , V_119 , V_22 ) ;
}
int F_80 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 , T_4 * V_114 ,
T_7 * V_12 )
{
int V_121 ;
* V_114 = 0 ;
if ( V_113 < 0 || V_113 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_113 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
V_121 = V_6 -> V_122 ( V_6 , V_113 , V_106 , V_114 , V_12 ) ;
if ( F_81 ( V_121 < 0 ) )
return V_121 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_121 >= V_6 -> V_32 ? - V_123 : 0 ;
}
int F_82 ( struct V_1 * V_6 , T_5 V_124 , T_4 V_106 , T_4 * V_114 ,
const T_7 * V_12 )
{
* V_114 = 0 ;
if ( V_124 < 0 || V_124 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_124 )
return - V_107 ;
if ( ! V_6 -> V_125 || ! ( V_6 -> V_22 & V_65 ) )
return - V_108 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_125 ( V_6 , V_124 , V_106 , V_114 , V_12 ) ;
}
int F_83 ( struct V_1 * V_6 , T_5 V_124 , T_4 V_106 , T_4 * V_114 ,
const T_7 * V_12 )
{
* V_114 = 0 ;
if ( ! V_6 -> V_126 )
return - V_67 ;
if ( V_124 < 0 || V_124 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_124 )
return - V_107 ;
if ( ! ( V_6 -> V_22 & V_65 ) )
return - V_108 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_126 ( V_6 , V_124 , V_106 , V_114 , V_12 ) ;
}
int F_84 ( struct V_1 * V_6 , T_5 V_113 , struct V_127 * V_128 )
{
int V_121 ;
V_128 -> V_114 = V_128 -> V_129 = 0 ;
if ( ! V_6 -> V_130 )
return - V_67 ;
V_121 = V_6 -> V_130 ( V_6 , V_113 , V_128 ) ;
if ( F_81 ( V_121 < 0 ) )
return V_121 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_121 >= V_6 -> V_32 ? - V_123 : 0 ;
}
int F_85 ( struct V_1 * V_6 , T_4 V_106 , T_4 * V_114 ,
struct V_131 * V_12 )
{
if ( ! V_6 -> V_132 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_132 ( V_6 , V_106 , V_114 , V_12 ) ;
}
int F_86 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 ,
T_4 * V_114 , T_7 * V_12 )
{
* V_114 = 0 ;
if ( ! V_6 -> V_133 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_133 ( V_6 , V_113 , V_106 , V_114 , V_12 ) ;
}
int F_87 ( struct V_1 * V_6 , T_4 V_106 , T_4 * V_114 ,
struct V_131 * V_12 )
{
if ( ! V_6 -> V_134 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_134 ( V_6 , V_106 , V_114 , V_12 ) ;
}
int F_88 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 ,
T_4 * V_114 , T_7 * V_12 )
{
* V_114 = 0 ;
if ( ! V_6 -> V_135 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_135 ( V_6 , V_113 , V_106 , V_114 , V_12 ) ;
}
int F_89 ( struct V_1 * V_6 , T_5 V_124 , T_4 V_106 ,
T_4 * V_114 , T_7 * V_12 )
{
int V_76 ;
* V_114 = 0 ;
if ( ! V_6 -> V_136 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
V_76 = V_6 -> V_136 ( V_6 , V_124 , V_106 , V_114 , V_12 ) ;
if ( V_76 )
return V_76 ;
return ( * V_114 ) ? 0 : - V_137 ;
}
int F_90 ( struct V_1 * V_6 , T_5 V_113 , T_4 V_106 )
{
if ( ! V_6 -> V_138 )
return - V_67 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_138 ( V_6 , V_113 , V_106 ) ;
}
int F_91 ( struct V_1 * V_6 , T_5 V_139 , T_8 V_106 )
{
if ( ! V_6 -> V_140 )
return - V_67 ;
if ( V_139 < 0 || V_139 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_139 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_140 ( V_6 , V_139 , V_106 ) ;
}
int F_38 ( struct V_1 * V_6 , T_5 V_139 , T_8 V_106 )
{
if ( ! V_6 -> V_141 )
return - V_67 ;
if ( V_139 < 0 || V_139 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_139 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_141 ( V_6 , V_139 , V_106 ) ;
}
int F_92 ( struct V_1 * V_6 , T_5 V_139 , T_8 V_106 )
{
if ( ! V_6 -> V_142 )
return - V_67 ;
if ( V_139 < 0 || V_139 >= V_6 -> V_23 || V_106 > V_6 -> V_23 - V_139 )
return - V_107 ;
if ( ! V_106 )
return 0 ;
return V_6 -> V_142 ( V_6 , V_139 , V_106 ) ;
}
int F_93 ( struct V_1 * V_6 , T_5 V_139 )
{
if ( V_139 < 0 || V_139 >= V_6 -> V_23 )
return - V_107 ;
if ( ! V_6 -> V_143 )
return 0 ;
return V_6 -> V_143 ( V_6 , V_139 ) ;
}
int F_94 ( struct V_1 * V_6 , T_5 V_139 )
{
if ( V_139 < 0 || V_139 >= V_6 -> V_23 )
return - V_107 ;
if ( ! V_6 -> V_144 )
return 0 ;
return V_6 -> V_144 ( V_6 , V_139 ) ;
}
int F_95 ( struct V_1 * V_6 , T_5 V_139 )
{
if ( ! V_6 -> V_145 )
return - V_67 ;
if ( V_139 < 0 || V_139 >= V_6 -> V_23 )
return - V_107 ;
if ( ! ( V_6 -> V_22 & V_65 ) )
return - V_108 ;
return V_6 -> V_145 ( V_6 , V_139 ) ;
}
static int F_96 ( struct V_1 * V_6 , const struct V_146 * V_147 ,
unsigned long V_33 , T_5 V_124 , T_4 * V_114 )
{
unsigned long V_2 ;
T_4 V_148 = 0 , V_149 ;
int V_76 = 0 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ ) {
if ( ! V_147 [ V_2 ] . V_150 )
continue;
V_76 = F_82 ( V_6 , V_124 , V_147 [ V_2 ] . V_150 , & V_149 ,
V_147 [ V_2 ] . V_151 ) ;
V_148 += V_149 ;
if ( V_76 || V_149 != V_147 [ V_2 ] . V_150 )
break;
V_124 += V_147 [ V_2 ] . V_150 ;
}
* V_114 = V_148 ;
return V_76 ;
}
int F_97 ( struct V_1 * V_6 , const struct V_146 * V_147 ,
unsigned long V_33 , T_5 V_124 , T_4 * V_114 )
{
* V_114 = 0 ;
if ( ! ( V_6 -> V_22 & V_65 ) )
return - V_108 ;
if ( ! V_6 -> V_152 )
return F_96 ( V_6 , V_147 , V_33 , V_124 , V_114 ) ;
return V_6 -> V_152 ( V_6 , V_147 , V_33 , V_124 , V_114 ) ;
}
void * F_98 ( const struct V_1 * V_6 , T_4 * V_23 )
{
T_9 V_22 = V_153 | V_154 |
V_155 | V_156 ;
T_4 V_157 = F_99 ( T_4 , V_6 -> V_25 , V_21 ) ;
void * V_158 ;
* V_23 = F_100 ( T_4 , * V_23 , V_159 ) ;
while ( * V_23 > V_157 ) {
V_158 = F_101 ( * V_23 , V_22 ) ;
if ( V_158 )
return V_158 ;
* V_23 >>= 1 ;
* V_23 = F_102 ( * V_23 , V_6 -> V_25 ) ;
}
return F_101 ( * V_23 , V_58 ) ;
}
static int F_103 ( struct V_160 * V_161 , void * V_162 )
{
struct V_1 * V_6 ;
F_104 ( V_161 , L_20 ) ;
F_34 ( & V_57 ) ;
F_65 (mtd) {
F_105 ( V_161 , L_21 ,
V_6 -> V_7 , ( unsigned long long ) V_6 -> V_23 ,
V_6 -> V_24 , V_6 -> V_30 ) ;
}
F_46 ( & V_57 ) ;
return 0 ;
}
static int F_106 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
return F_107 ( V_164 , F_103 , NULL ) ;
}
static int T_10 F_108 ( struct V_55 * V_165 , const char * V_30 )
{
int V_76 ;
V_76 = F_109 ( V_165 ) ;
if ( ! V_76 )
V_76 = F_110 ( V_165 , NULL , L_22 , V_30 ) ;
if ( V_76 )
F_111 ( V_165 ) ;
return V_76 ;
}
static int T_10 F_112 ( void )
{
int V_76 ;
V_76 = F_113 ( & V_8 ) ;
if ( V_76 )
goto V_166;
V_76 = F_108 ( & V_56 , L_23 ) ;
if ( V_76 )
goto V_167;
V_168 = F_114 ( L_23 , 0 , NULL , & V_169 ) ;
V_76 = F_115 () ;
if ( V_76 )
goto V_170;
return 0 ;
V_170:
if ( V_168 )
F_116 ( L_23 , NULL ) ;
V_167:
F_117 ( & V_8 ) ;
V_166:
F_118 ( L_24 , V_76 ) ;
return V_76 ;
}
static void T_11 F_119 ( void )
{
F_120 () ;
if ( V_168 )
F_116 ( L_23 , NULL ) ;
F_117 ( & V_8 ) ;
F_111 ( & V_56 ) ;
}
