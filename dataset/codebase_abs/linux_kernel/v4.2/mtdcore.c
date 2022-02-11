static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 ? F_3 ( V_4 ) : 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
return 0 ;
}
struct V_3 * F_6 ( int V_5 )
{
return F_7 ( & V_6 , & V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = F_9 ( V_4 -> V_7 ) ;
F_10 ( & V_8 , V_7 + 1 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * type ;
switch ( V_4 -> type ) {
case V_12 :
type = L_1 ;
break;
case V_13 :
type = L_2 ;
break;
case V_14 :
type = L_3 ;
break;
case V_15 :
type = L_4 ;
break;
case V_16 :
type = L_5 ;
break;
case V_17 :
type = L_6 ;
break;
case V_18 :
type = L_7 ;
break;
case V_19 :
type = L_8 ;
break;
default:
type = L_9 ;
}
return snprintf ( V_11 , V_20 , L_10 , type ) ;
}
static T_2 F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_11 , ( unsigned long ) V_4 -> V_21 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_12 ,
( unsigned long long ) V_4 -> V_22 ) ;
}
static T_2 F_14 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_13 , ( unsigned long ) V_4 -> V_23 ) ;
}
static T_2 F_15 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_13 , ( unsigned long ) V_4 -> V_24 ) ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_25 = V_4 -> V_24 >> V_4 -> V_26 ;
return snprintf ( V_11 , V_20 , L_14 , V_25 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_13 , ( unsigned long ) V_4 -> V_27 ) ;
}
static T_2 F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_14 , V_4 -> V_28 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_10 , V_4 -> V_29 ) ;
}
static T_2 F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_14 , V_4 -> V_30 ) ;
}
static T_2 F_21 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_14 , V_4 -> V_31 ) ;
}
static T_2 F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_31 ;
int V_33 ;
V_33 = F_23 ( V_11 , 0 , & V_31 ) ;
if ( V_33 )
return V_33 ;
V_4 -> V_31 = V_31 ;
return V_32 ;
}
static T_2 F_24 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return snprintf ( V_11 , V_20 , L_14 , V_4 -> V_34 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_4 -> V_36 ;
return snprintf ( V_11 , V_20 , L_14 , V_36 -> V_37 ) ;
}
static T_2 F_26 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_4 -> V_36 ;
return snprintf ( V_11 , V_20 , L_14 , V_36 -> V_38 ) ;
}
static T_2 F_27 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_4 -> V_36 ;
return snprintf ( V_11 , V_20 , L_14 , V_36 -> V_39 ) ;
}
static T_2 F_28 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_4 -> V_36 ;
return snprintf ( V_11 , V_20 , L_14 , V_36 -> V_40 ) ;
}
unsigned F_29 ( struct V_3 * V_4 )
{
switch ( V_4 -> type ) {
case V_13 :
return V_41 | V_42 | V_43 |
V_44 | V_45 ;
case V_14 :
return V_41 | V_42 | V_43 |
V_44 ;
default:
return V_41 ;
}
}
static int F_30 ( struct V_46 * V_47 , unsigned long V_48 ,
void * V_49 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_47 , struct V_3 , V_50 ) ;
V_4 -> V_51 ( V_4 ) ;
return V_52 ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_53 * V_54 ;
int V_5 , error ;
V_4 -> V_55 = & V_56 ;
F_33 ( V_4 -> V_24 == 0 ) ;
F_34 ( & V_57 ) ;
V_5 = F_35 ( & V_6 , V_4 , 0 , 0 , V_58 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
goto V_59;
}
V_4 -> V_7 = V_5 ;
V_4 -> V_60 = 0 ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = V_4 -> V_30 ;
if ( F_36 ( V_4 -> V_23 ) )
V_4 -> V_61 = F_37 ( V_4 -> V_23 ) - 1 ;
else
V_4 -> V_61 = 0 ;
if ( F_36 ( V_4 -> V_24 ) )
V_4 -> V_62 = F_37 ( V_4 -> V_24 ) - 1 ;
else
V_4 -> V_62 = 0 ;
V_4 -> V_63 = ( 1 << V_4 -> V_61 ) - 1 ;
V_4 -> V_64 = ( 1 << V_4 -> V_62 ) - 1 ;
if ( ( V_4 -> V_21 & V_65 ) && ( V_4 -> V_21 & V_66 ) ) {
error = F_38 ( V_4 , 0 , V_4 -> V_22 ) ;
if ( error && error != - V_67 )
F_39 ( V_68
L_15 ,
V_4 -> V_29 ) ;
error = 0 ;
}
V_4 -> V_2 . type = & V_69 ;
V_4 -> V_2 . V_70 = & V_8 ;
V_4 -> V_2 . V_71 = F_9 ( V_5 ) ;
F_40 ( & V_4 -> V_2 , L_16 , V_5 ) ;
F_41 ( & V_4 -> V_2 , V_4 ) ;
error = F_42 ( & V_4 -> V_2 ) ;
if ( error )
goto V_72;
F_43 ( & V_8 , V_4 -> V_2 . V_73 , F_9 ( V_5 ) + 1 , NULL ,
L_17 , V_5 ) ;
F_44 ( L_18 , V_5 , V_4 -> V_29 ) ;
F_45 (not, &mtd_notifiers, list)
V_54 -> V_74 ( V_4 ) ;
F_46 ( & V_57 ) ;
F_47 ( V_75 ) ;
return 0 ;
V_72:
F_48 ( & V_6 , V_5 ) ;
V_59:
F_46 ( & V_57 ) ;
return error ;
}
int F_49 ( struct V_3 * V_4 )
{
int V_76 ;
struct V_53 * V_54 ;
F_34 ( & V_57 ) ;
if ( F_50 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_76 = - V_77 ;
goto V_78;
}
F_45 (not, &mtd_notifiers, list)
V_54 -> remove ( V_4 ) ;
if ( V_4 -> V_60 ) {
F_39 ( V_79 L_19 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_60 ) ;
V_76 = - V_80 ;
} else {
F_51 ( & V_4 -> V_2 ) ;
F_48 ( & V_6 , V_4 -> V_7 ) ;
F_52 ( V_75 ) ;
V_76 = 0 ;
}
V_78:
F_46 ( & V_57 ) ;
return V_76 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_81 * V_82 ,
int V_83 )
{
int V_76 ;
if ( V_83 == 0 || F_54 ( V_84 ) ) {
V_76 = F_32 ( V_4 ) ;
if ( V_76 )
return V_76 ;
}
if ( V_83 > 0 ) {
V_76 = F_55 ( V_4 , V_82 , V_83 ) ;
if ( V_76 && F_54 ( V_84 ) )
F_49 ( V_4 ) ;
return V_76 ;
}
return 0 ;
}
int F_56 ( struct V_3 * V_4 , const char * const * V_85 ,
struct V_86 * V_87 ,
const struct V_81 * V_88 ,
int V_89 )
{
int V_76 ;
struct V_81 * V_82 = NULL ;
V_76 = F_57 ( V_4 , V_85 , & V_82 , V_87 ) ;
if ( V_76 <= 0 && V_89 && V_88 ) {
V_82 = F_58 ( V_88 , sizeof( * V_88 ) * V_89 ,
V_58 ) ;
if ( ! V_82 )
V_76 = - V_90 ;
else
V_76 = V_89 ;
}
if ( V_76 >= 0 )
V_76 = F_53 ( V_4 , V_82 , V_76 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_91 ) {
V_4 -> V_50 . V_91 = F_30 ;
F_59 ( & V_4 -> V_50 ) ;
}
F_60 ( V_82 ) ;
return V_76 ;
}
int F_61 ( struct V_3 * V_92 )
{
int V_93 ;
if ( V_92 -> V_51 )
F_62 ( & V_92 -> V_50 ) ;
V_93 = F_63 ( V_92 ) ;
if ( V_93 )
return V_93 ;
if ( ! F_64 ( & V_92 -> V_2 ) )
return 0 ;
return F_49 ( V_92 ) ;
}
void F_65 ( struct V_53 * V_94 )
{
struct V_3 * V_4 ;
F_34 ( & V_57 ) ;
F_66 ( & V_94 -> V_95 , & V_96 ) ;
F_47 ( V_75 ) ;
F_67 (mtd)
V_94 -> V_74 ( V_4 ) ;
F_46 ( & V_57 ) ;
}
int F_68 ( struct V_53 * V_97 )
{
struct V_3 * V_4 ;
F_34 ( & V_57 ) ;
F_52 ( V_75 ) ;
F_67 (mtd)
V_97 -> remove ( V_4 ) ;
F_69 ( & V_97 -> V_95 ) ;
F_46 ( & V_57 ) ;
return 0 ;
}
struct V_3 * F_70 ( struct V_3 * V_4 , int V_98 )
{
struct V_3 * V_76 = NULL , * V_99 ;
int V_93 = - V_77 ;
F_34 ( & V_57 ) ;
if ( V_98 == - 1 ) {
F_67 (other) {
if ( V_99 == V_4 ) {
V_76 = V_4 ;
break;
}
}
} else if ( V_98 >= 0 ) {
V_76 = F_50 ( & V_6 , V_98 ) ;
if ( V_4 && V_4 != V_76 )
V_76 = NULL ;
}
if ( ! V_76 ) {
V_76 = F_71 ( V_93 ) ;
goto V_100;
}
V_93 = F_72 ( V_76 ) ;
if ( V_93 )
V_76 = F_71 ( V_93 ) ;
V_100:
F_46 ( & V_57 ) ;
return V_76 ;
}
int F_72 ( struct V_3 * V_4 )
{
int V_93 ;
if ( ! F_73 ( V_4 -> V_101 ) )
return - V_77 ;
if ( V_4 -> V_102 ) {
V_93 = V_4 -> V_102 ( V_4 ) ;
if ( V_93 ) {
F_52 ( V_4 -> V_101 ) ;
return V_93 ;
}
}
V_4 -> V_60 ++ ;
return 0 ;
}
struct V_3 * F_74 ( const char * V_29 )
{
int V_93 = - V_77 ;
struct V_3 * V_4 = NULL , * V_99 ;
F_34 ( & V_57 ) ;
F_67 (other) {
if ( ! strcmp ( V_29 , V_99 -> V_29 ) ) {
V_4 = V_99 ;
break;
}
}
if ( ! V_4 )
goto V_103;
V_93 = F_72 ( V_4 ) ;
if ( V_93 )
goto V_103;
F_46 ( & V_57 ) ;
return V_4 ;
V_103:
F_46 ( & V_57 ) ;
return F_71 ( V_93 ) ;
}
void F_75 ( struct V_3 * V_4 )
{
F_34 ( & V_57 ) ;
F_76 ( V_4 ) ;
F_46 ( & V_57 ) ;
}
void F_76 ( struct V_3 * V_4 )
{
-- V_4 -> V_60 ;
F_33 ( V_4 -> V_60 < 0 ) ;
if ( V_4 -> V_104 )
V_4 -> V_104 ( V_4 ) ;
F_52 ( V_4 -> V_101 ) ;
}
int F_77 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
if ( V_106 -> V_107 >= V_4 -> V_22 || V_106 -> V_108 > V_4 -> V_22 - V_106 -> V_107 )
return - V_109 ;
if ( ! ( V_4 -> V_21 & V_65 ) )
return - V_110 ;
V_106 -> V_111 = V_112 ;
if ( ! V_106 -> V_108 ) {
V_106 -> V_48 = V_113 ;
F_78 ( V_106 ) ;
return 0 ;
}
return V_4 -> V_114 ( V_4 , V_106 ) ;
}
int F_79 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 , T_3 * V_116 ,
void * * V_117 , T_5 * V_118 )
{
* V_116 = 0 ;
* V_117 = NULL ;
if ( V_118 )
* V_118 = 0 ;
if ( ! V_4 -> V_119 )
return - V_67 ;
if ( V_115 < 0 || V_115 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_115 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_119 ( V_4 , V_115 , V_108 , V_116 , V_117 , V_118 ) ;
}
int F_80 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 )
{
if ( ! V_4 -> V_119 )
return - V_67 ;
if ( V_115 < 0 || V_115 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_115 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_120 ( V_4 , V_115 , V_108 ) ;
}
unsigned long F_81 ( struct V_3 * V_4 , unsigned long V_108 ,
unsigned long V_121 , unsigned long V_21 )
{
if ( ! V_4 -> V_122 )
return - V_67 ;
if ( V_121 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_121 )
return - V_109 ;
return V_4 -> V_122 ( V_4 , V_108 , V_121 , V_21 ) ;
}
int F_82 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 , T_3 * V_116 ,
T_6 * V_11 )
{
int V_123 ;
* V_116 = 0 ;
if ( V_115 < 0 || V_115 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_115 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
V_123 = V_4 -> V_124 ( V_4 , V_115 , V_108 , V_116 , V_11 ) ;
if ( F_83 ( V_123 < 0 ) )
return V_123 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_123 >= V_4 -> V_31 ? - V_125 : 0 ;
}
int F_84 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_108 , T_3 * V_116 ,
const T_6 * V_11 )
{
* V_116 = 0 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_126 )
return - V_109 ;
if ( ! V_4 -> V_127 || ! ( V_4 -> V_21 & V_65 ) )
return - V_110 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_127 ( V_4 , V_126 , V_108 , V_116 , V_11 ) ;
}
int F_85 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_108 , T_3 * V_116 ,
const T_6 * V_11 )
{
* V_116 = 0 ;
if ( ! V_4 -> V_128 )
return - V_67 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_126 )
return - V_109 ;
if ( ! ( V_4 -> V_21 & V_65 ) )
return - V_110 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_128 ( V_4 , V_126 , V_108 , V_116 , V_11 ) ;
}
int F_86 ( struct V_3 * V_4 , T_4 V_115 , struct V_129 * V_130 )
{
int V_123 ;
V_130 -> V_116 = V_130 -> V_131 = 0 ;
if ( ! V_4 -> V_132 )
return - V_67 ;
V_123 = V_4 -> V_132 ( V_4 , V_115 , V_130 ) ;
if ( F_83 ( V_123 < 0 ) )
return V_123 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_123 >= V_4 -> V_31 ? - V_125 : 0 ;
}
int F_87 ( struct V_3 * V_4 , T_3 V_108 , T_3 * V_116 ,
struct V_133 * V_11 )
{
if ( ! V_4 -> V_134 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_134 ( V_4 , V_108 , V_116 , V_11 ) ;
}
int F_88 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 ,
T_3 * V_116 , T_6 * V_11 )
{
* V_116 = 0 ;
if ( ! V_4 -> V_135 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_135 ( V_4 , V_115 , V_108 , V_116 , V_11 ) ;
}
int F_89 ( struct V_3 * V_4 , T_3 V_108 , T_3 * V_116 ,
struct V_133 * V_11 )
{
if ( ! V_4 -> V_136 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_136 ( V_4 , V_108 , V_116 , V_11 ) ;
}
int F_90 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 ,
T_3 * V_116 , T_6 * V_11 )
{
* V_116 = 0 ;
if ( ! V_4 -> V_137 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_137 ( V_4 , V_115 , V_108 , V_116 , V_11 ) ;
}
int F_91 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_108 ,
T_3 * V_116 , T_6 * V_11 )
{
int V_76 ;
* V_116 = 0 ;
if ( ! V_4 -> V_138 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
V_76 = V_4 -> V_138 ( V_4 , V_126 , V_108 , V_116 , V_11 ) ;
if ( V_76 )
return V_76 ;
return ( * V_116 ) ? 0 : - V_139 ;
}
int F_92 ( struct V_3 * V_4 , T_4 V_115 , T_3 V_108 )
{
if ( ! V_4 -> V_140 )
return - V_67 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_140 ( V_4 , V_115 , V_108 ) ;
}
int F_93 ( struct V_3 * V_4 , T_4 V_141 , T_7 V_108 )
{
if ( ! V_4 -> V_142 )
return - V_67 ;
if ( V_141 < 0 || V_141 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_141 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_142 ( V_4 , V_141 , V_108 ) ;
}
int F_38 ( struct V_3 * V_4 , T_4 V_141 , T_7 V_108 )
{
if ( ! V_4 -> V_143 )
return - V_67 ;
if ( V_141 < 0 || V_141 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_141 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_143 ( V_4 , V_141 , V_108 ) ;
}
int F_94 ( struct V_3 * V_4 , T_4 V_141 , T_7 V_108 )
{
if ( ! V_4 -> V_144 )
return - V_67 ;
if ( V_141 < 0 || V_141 >= V_4 -> V_22 || V_108 > V_4 -> V_22 - V_141 )
return - V_109 ;
if ( ! V_108 )
return 0 ;
return V_4 -> V_144 ( V_4 , V_141 , V_108 ) ;
}
int F_95 ( struct V_3 * V_4 , T_4 V_141 )
{
if ( V_141 < 0 || V_141 >= V_4 -> V_22 )
return - V_109 ;
if ( ! V_4 -> V_145 )
return 0 ;
return V_4 -> V_145 ( V_4 , V_141 ) ;
}
int F_96 ( struct V_3 * V_4 , T_4 V_141 )
{
if ( V_141 < 0 || V_141 >= V_4 -> V_22 )
return - V_109 ;
if ( ! V_4 -> V_146 )
return 0 ;
return V_4 -> V_146 ( V_4 , V_141 ) ;
}
int F_97 ( struct V_3 * V_4 , T_4 V_141 )
{
if ( ! V_4 -> V_147 )
return - V_67 ;
if ( V_141 < 0 || V_141 >= V_4 -> V_22 )
return - V_109 ;
if ( ! ( V_4 -> V_21 & V_65 ) )
return - V_110 ;
return V_4 -> V_147 ( V_4 , V_141 ) ;
}
static int F_98 ( struct V_3 * V_4 , const struct V_148 * V_149 ,
unsigned long V_32 , T_4 V_126 , T_3 * V_116 )
{
unsigned long V_5 ;
T_3 V_150 = 0 , V_151 ;
int V_76 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_149 [ V_5 ] . V_152 )
continue;
V_76 = F_84 ( V_4 , V_126 , V_149 [ V_5 ] . V_152 , & V_151 ,
V_149 [ V_5 ] . V_153 ) ;
V_150 += V_151 ;
if ( V_76 || V_151 != V_149 [ V_5 ] . V_152 )
break;
V_126 += V_149 [ V_5 ] . V_152 ;
}
* V_116 = V_150 ;
return V_76 ;
}
int F_99 ( struct V_3 * V_4 , const struct V_148 * V_149 ,
unsigned long V_32 , T_4 V_126 , T_3 * V_116 )
{
* V_116 = 0 ;
if ( ! ( V_4 -> V_21 & V_65 ) )
return - V_110 ;
if ( ! V_4 -> V_154 )
return F_98 ( V_4 , V_149 , V_32 , V_126 , V_116 ) ;
return V_4 -> V_154 ( V_4 , V_149 , V_32 , V_126 , V_116 ) ;
}
void * F_100 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_8 V_21 = V_155 | V_156 |
V_157 | V_158 ;
T_3 V_159 = F_101 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_160 ;
* V_22 = F_102 ( T_3 , * V_22 , V_161 ) ;
while ( * V_22 > V_159 ) {
V_160 = F_103 ( * V_22 , V_21 ) ;
if ( V_160 )
return V_160 ;
* V_22 >>= 1 ;
* V_22 = F_104 ( * V_22 , V_4 -> V_24 ) ;
}
return F_103 ( * V_22 , V_58 ) ;
}
static int F_105 ( struct V_162 * V_163 , void * V_164 )
{
struct V_3 * V_4 ;
F_106 ( V_163 , L_20 ) ;
F_34 ( & V_57 ) ;
F_67 (mtd) {
F_107 ( V_163 , L_21 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_46 ( & V_57 ) ;
return 0 ;
}
static int F_108 ( struct V_165 * V_165 , struct V_166 * V_166 )
{
return F_109 ( V_166 , F_105 , NULL ) ;
}
static int T_9 F_110 ( struct V_55 * V_167 , const char * V_29 )
{
int V_76 ;
V_76 = F_111 ( V_167 ) ;
if ( ! V_76 )
V_76 = F_112 ( V_167 , NULL , L_22 , V_29 ) ;
if ( V_76 )
F_113 ( V_167 ) ;
return V_76 ;
}
static int T_9 F_114 ( void )
{
int V_76 ;
V_76 = F_115 ( & V_8 ) ;
if ( V_76 )
goto V_168;
V_76 = F_110 ( & V_56 , L_23 ) ;
if ( V_76 )
goto V_169;
V_170 = F_116 ( L_23 , 0 , NULL , & V_171 ) ;
V_76 = F_117 () ;
if ( V_76 )
goto V_172;
return 0 ;
V_172:
if ( V_170 )
F_118 ( L_23 , NULL ) ;
V_169:
F_119 ( & V_8 ) ;
V_168:
F_120 ( L_24 , V_76 ) ;
return V_76 ;
}
static void T_10 F_121 ( void )
{
F_122 () ;
if ( V_170 )
F_118 ( L_23 , NULL ) ;
F_119 ( & V_8 ) ;
F_113 ( & V_56 ) ;
}
