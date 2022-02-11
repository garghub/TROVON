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
if ( F_33 ( V_4 -> V_55 , L_15 ) )
return - V_56 ;
V_4 -> V_55 = & V_57 ;
F_34 ( V_4 -> V_24 == 0 ) ;
F_35 ( & V_58 ) ;
V_5 = F_36 ( & V_6 , V_4 , 0 , 0 , V_59 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
goto V_60;
}
V_4 -> V_7 = V_5 ;
V_4 -> V_61 = 0 ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = V_4 -> V_30 ;
if ( F_37 ( V_4 -> V_23 ) )
V_4 -> V_62 = F_38 ( V_4 -> V_23 ) - 1 ;
else
V_4 -> V_62 = 0 ;
if ( F_37 ( V_4 -> V_24 ) )
V_4 -> V_63 = F_38 ( V_4 -> V_24 ) - 1 ;
else
V_4 -> V_63 = 0 ;
V_4 -> V_64 = ( 1 << V_4 -> V_62 ) - 1 ;
V_4 -> V_65 = ( 1 << V_4 -> V_63 ) - 1 ;
if ( ( V_4 -> V_21 & V_66 ) && ( V_4 -> V_21 & V_67 ) ) {
error = F_39 ( V_4 , 0 , V_4 -> V_22 ) ;
if ( error && error != - V_68 )
F_40 ( V_69
L_16 ,
V_4 -> V_29 ) ;
error = 0 ;
}
V_4 -> V_2 . type = & V_70 ;
V_4 -> V_2 . V_71 = & V_8 ;
V_4 -> V_2 . V_72 = F_9 ( V_5 ) ;
F_41 ( & V_4 -> V_2 , L_17 , V_5 ) ;
F_42 ( & V_4 -> V_2 , V_4 ) ;
error = F_43 ( & V_4 -> V_2 ) ;
if ( error )
goto V_73;
F_44 ( & V_8 , V_4 -> V_2 . V_74 , F_9 ( V_5 ) + 1 , NULL ,
L_18 , V_5 ) ;
F_45 ( L_19 , V_5 , V_4 -> V_29 ) ;
F_46 (not, &mtd_notifiers, list)
V_54 -> V_75 ( V_4 ) ;
F_47 ( & V_58 ) ;
F_48 ( V_76 ) ;
return 0 ;
V_73:
F_49 ( & V_6 , V_5 ) ;
V_60:
F_47 ( & V_58 ) ;
return error ;
}
int F_50 ( struct V_3 * V_4 )
{
int V_77 ;
struct V_53 * V_54 ;
F_35 ( & V_58 ) ;
if ( F_51 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_77 = - V_78 ;
goto V_79;
}
F_46 (not, &mtd_notifiers, list)
V_54 -> remove ( V_4 ) ;
if ( V_4 -> V_61 ) {
F_40 ( V_80 L_20 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_61 ) ;
V_77 = - V_81 ;
} else {
F_52 ( & V_4 -> V_2 ) ;
F_49 ( & V_6 , V_4 -> V_7 ) ;
F_53 ( V_76 ) ;
V_77 = 0 ;
}
V_79:
F_47 ( & V_58 ) ;
return V_77 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_82 * V_83 ,
int V_84 )
{
int V_77 ;
if ( V_84 == 0 || F_55 ( V_85 ) ) {
V_77 = F_32 ( V_4 ) ;
if ( V_77 )
return V_77 ;
}
if ( V_84 > 0 ) {
V_77 = F_56 ( V_4 , V_83 , V_84 ) ;
if ( V_77 && F_55 ( V_85 ) )
F_50 ( V_4 ) ;
return V_77 ;
}
return 0 ;
}
static void F_57 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_74 ) {
if ( ! V_4 -> V_86 && V_4 -> V_2 . V_74 -> V_87 )
V_4 -> V_86 = V_4 -> V_2 . V_74 -> V_87 -> V_86 ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 = F_58 ( V_4 -> V_2 . V_74 ) ;
} else {
F_45 ( L_21 ) ;
}
}
int F_59 ( struct V_3 * V_4 , const char * const * V_88 ,
struct V_89 * V_90 ,
const struct V_82 * V_91 ,
int V_92 )
{
int V_77 ;
struct V_82 * V_83 = NULL ;
F_57 ( V_4 ) ;
V_77 = F_60 ( V_4 , V_88 , & V_83 , V_90 ) ;
if ( V_77 <= 0 && V_92 && V_91 ) {
V_83 = F_61 ( V_91 , sizeof( * V_91 ) * V_92 ,
V_59 ) ;
if ( ! V_83 )
V_77 = - V_93 ;
else
V_77 = V_92 ;
}
if ( V_77 < 0 ) {
F_62 ( L_22 ,
V_77 ) ;
V_77 = 0 ;
}
V_77 = F_54 ( V_4 , V_83 , V_77 ) ;
if ( V_77 )
goto V_94;
F_33 ( V_4 -> V_51 && V_4 -> V_50 . V_95 ,
L_15 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_95 ) {
V_4 -> V_50 . V_95 = F_30 ;
F_63 ( & V_4 -> V_50 ) ;
}
V_94:
F_64 ( V_83 ) ;
return V_77 ;
}
int F_65 ( struct V_3 * V_96 )
{
int V_97 ;
if ( V_96 -> V_51 )
F_66 ( & V_96 -> V_50 ) ;
V_97 = F_67 ( V_96 ) ;
if ( V_97 )
return V_97 ;
if ( ! F_68 ( & V_96 -> V_2 ) )
return 0 ;
return F_50 ( V_96 ) ;
}
void F_69 ( struct V_53 * V_98 )
{
struct V_3 * V_4 ;
F_35 ( & V_58 ) ;
F_70 ( & V_98 -> V_99 , & V_100 ) ;
F_48 ( V_76 ) ;
F_71 (mtd)
V_98 -> V_75 ( V_4 ) ;
F_47 ( & V_58 ) ;
}
int F_72 ( struct V_53 * V_101 )
{
struct V_3 * V_4 ;
F_35 ( & V_58 ) ;
F_53 ( V_76 ) ;
F_71 (mtd)
V_101 -> remove ( V_4 ) ;
F_73 ( & V_101 -> V_99 ) ;
F_47 ( & V_58 ) ;
return 0 ;
}
struct V_3 * F_74 ( struct V_3 * V_4 , int V_102 )
{
struct V_3 * V_77 = NULL , * V_103 ;
int V_97 = - V_78 ;
F_35 ( & V_58 ) ;
if ( V_102 == - 1 ) {
F_71 (other) {
if ( V_103 == V_4 ) {
V_77 = V_4 ;
break;
}
}
} else if ( V_102 >= 0 ) {
V_77 = F_51 ( & V_6 , V_102 ) ;
if ( V_4 && V_4 != V_77 )
V_77 = NULL ;
}
if ( ! V_77 ) {
V_77 = F_75 ( V_97 ) ;
goto V_94;
}
V_97 = F_76 ( V_77 ) ;
if ( V_97 )
V_77 = F_75 ( V_97 ) ;
V_94:
F_47 ( & V_58 ) ;
return V_77 ;
}
int F_76 ( struct V_3 * V_4 )
{
int V_97 ;
if ( ! F_77 ( V_4 -> V_86 ) )
return - V_78 ;
if ( V_4 -> V_104 ) {
V_97 = V_4 -> V_104 ( V_4 ) ;
if ( V_97 ) {
F_53 ( V_4 -> V_86 ) ;
return V_97 ;
}
}
V_4 -> V_61 ++ ;
return 0 ;
}
struct V_3 * F_78 ( const char * V_29 )
{
int V_97 = - V_78 ;
struct V_3 * V_4 = NULL , * V_103 ;
F_35 ( & V_58 ) ;
F_71 (other) {
if ( ! strcmp ( V_29 , V_103 -> V_29 ) ) {
V_4 = V_103 ;
break;
}
}
if ( ! V_4 )
goto V_105;
V_97 = F_76 ( V_4 ) ;
if ( V_97 )
goto V_105;
F_47 ( & V_58 ) ;
return V_4 ;
V_105:
F_47 ( & V_58 ) ;
return F_75 ( V_97 ) ;
}
void F_79 ( struct V_3 * V_4 )
{
F_35 ( & V_58 ) ;
F_80 ( V_4 ) ;
F_47 ( & V_58 ) ;
}
void F_80 ( struct V_3 * V_4 )
{
-- V_4 -> V_61 ;
F_34 ( V_4 -> V_61 < 0 ) ;
if ( V_4 -> V_106 )
V_4 -> V_106 ( V_4 ) ;
F_53 ( V_4 -> V_86 ) ;
}
int F_81 ( struct V_3 * V_4 , struct V_107 * V_108 )
{
if ( V_108 -> V_109 >= V_4 -> V_22 || V_108 -> V_110 > V_4 -> V_22 - V_108 -> V_109 )
return - V_111 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_112 ;
V_108 -> V_113 = V_114 ;
if ( ! V_108 -> V_110 ) {
V_108 -> V_48 = V_115 ;
F_82 ( V_108 ) ;
return 0 ;
}
return V_4 -> V_116 ( V_4 , V_108 ) ;
}
int F_83 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 , T_3 * V_118 ,
void * * V_119 , T_5 * V_120 )
{
* V_118 = 0 ;
* V_119 = NULL ;
if ( V_120 )
* V_120 = 0 ;
if ( ! V_4 -> V_121 )
return - V_68 ;
if ( V_117 < 0 || V_117 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_117 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_121 ( V_4 , V_117 , V_110 , V_118 , V_119 , V_120 ) ;
}
int F_84 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 )
{
if ( ! V_4 -> V_121 )
return - V_68 ;
if ( V_117 < 0 || V_117 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_117 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_122 ( V_4 , V_117 , V_110 ) ;
}
unsigned long F_85 ( struct V_3 * V_4 , unsigned long V_110 ,
unsigned long V_123 , unsigned long V_21 )
{
if ( ! V_4 -> V_124 )
return - V_68 ;
if ( V_123 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_123 )
return - V_111 ;
return V_4 -> V_124 ( V_4 , V_110 , V_123 , V_21 ) ;
}
int F_86 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 , T_3 * V_118 ,
T_6 * V_11 )
{
int V_125 ;
* V_118 = 0 ;
if ( V_117 < 0 || V_117 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_117 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
V_125 = V_4 -> V_126 ( V_4 , V_117 , V_110 , V_118 , V_11 ) ;
if ( F_87 ( V_125 < 0 ) )
return V_125 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_125 >= V_4 -> V_31 ? - V_127 : 0 ;
}
int F_88 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_110 , T_3 * V_118 ,
const T_6 * V_11 )
{
* V_118 = 0 ;
if ( V_128 < 0 || V_128 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_128 )
return - V_111 ;
if ( ! V_4 -> V_129 || ! ( V_4 -> V_21 & V_66 ) )
return - V_112 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_129 ( V_4 , V_128 , V_110 , V_118 , V_11 ) ;
}
int F_89 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_110 , T_3 * V_118 ,
const T_6 * V_11 )
{
* V_118 = 0 ;
if ( ! V_4 -> V_130 )
return - V_68 ;
if ( V_128 < 0 || V_128 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_128 )
return - V_111 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_112 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_130 ( V_4 , V_128 , V_110 , V_118 , V_11 ) ;
}
int F_90 ( struct V_3 * V_4 , T_4 V_117 , struct V_131 * V_132 )
{
int V_125 ;
V_132 -> V_118 = V_132 -> V_133 = 0 ;
if ( ! V_4 -> V_134 )
return - V_68 ;
V_125 = V_4 -> V_134 ( V_4 , V_117 , V_132 ) ;
if ( F_87 ( V_125 < 0 ) )
return V_125 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_125 >= V_4 -> V_31 ? - V_127 : 0 ;
}
int F_91 ( struct V_3 * V_4 , T_3 V_110 , T_3 * V_118 ,
struct V_135 * V_11 )
{
if ( ! V_4 -> V_136 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_136 ( V_4 , V_110 , V_118 , V_11 ) ;
}
int F_92 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 ,
T_3 * V_118 , T_6 * V_11 )
{
* V_118 = 0 ;
if ( ! V_4 -> V_137 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_137 ( V_4 , V_117 , V_110 , V_118 , V_11 ) ;
}
int F_93 ( struct V_3 * V_4 , T_3 V_110 , T_3 * V_118 ,
struct V_135 * V_11 )
{
if ( ! V_4 -> V_138 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_138 ( V_4 , V_110 , V_118 , V_11 ) ;
}
int F_94 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 ,
T_3 * V_118 , T_6 * V_11 )
{
* V_118 = 0 ;
if ( ! V_4 -> V_139 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_139 ( V_4 , V_117 , V_110 , V_118 , V_11 ) ;
}
int F_95 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_110 ,
T_3 * V_118 , T_6 * V_11 )
{
int V_77 ;
* V_118 = 0 ;
if ( ! V_4 -> V_140 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
V_77 = V_4 -> V_140 ( V_4 , V_128 , V_110 , V_118 , V_11 ) ;
if ( V_77 )
return V_77 ;
return ( * V_118 ) ? 0 : - V_141 ;
}
int F_96 ( struct V_3 * V_4 , T_4 V_117 , T_3 V_110 )
{
if ( ! V_4 -> V_142 )
return - V_68 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_142 ( V_4 , V_117 , V_110 ) ;
}
int F_97 ( struct V_3 * V_4 , T_4 V_143 , T_7 V_110 )
{
if ( ! V_4 -> V_144 )
return - V_68 ;
if ( V_143 < 0 || V_143 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_143 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_144 ( V_4 , V_143 , V_110 ) ;
}
int F_39 ( struct V_3 * V_4 , T_4 V_143 , T_7 V_110 )
{
if ( ! V_4 -> V_145 )
return - V_68 ;
if ( V_143 < 0 || V_143 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_143 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_145 ( V_4 , V_143 , V_110 ) ;
}
int F_98 ( struct V_3 * V_4 , T_4 V_143 , T_7 V_110 )
{
if ( ! V_4 -> V_146 )
return - V_68 ;
if ( V_143 < 0 || V_143 >= V_4 -> V_22 || V_110 > V_4 -> V_22 - V_143 )
return - V_111 ;
if ( ! V_110 )
return 0 ;
return V_4 -> V_146 ( V_4 , V_143 , V_110 ) ;
}
int F_99 ( struct V_3 * V_4 , T_4 V_143 )
{
if ( V_143 < 0 || V_143 >= V_4 -> V_22 )
return - V_111 ;
if ( ! V_4 -> V_147 )
return 0 ;
return V_4 -> V_147 ( V_4 , V_143 ) ;
}
int F_100 ( struct V_3 * V_4 , T_4 V_143 )
{
if ( V_143 < 0 || V_143 >= V_4 -> V_22 )
return - V_111 ;
if ( ! V_4 -> V_148 )
return 0 ;
return V_4 -> V_148 ( V_4 , V_143 ) ;
}
int F_101 ( struct V_3 * V_4 , T_4 V_143 )
{
if ( ! V_4 -> V_149 )
return - V_68 ;
if ( V_143 < 0 || V_143 >= V_4 -> V_22 )
return - V_111 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_112 ;
return V_4 -> V_149 ( V_4 , V_143 ) ;
}
static int F_102 ( struct V_3 * V_4 , const struct V_150 * V_151 ,
unsigned long V_32 , T_4 V_128 , T_3 * V_118 )
{
unsigned long V_5 ;
T_3 V_152 = 0 , V_153 ;
int V_77 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_151 [ V_5 ] . V_154 )
continue;
V_77 = F_88 ( V_4 , V_128 , V_151 [ V_5 ] . V_154 , & V_153 ,
V_151 [ V_5 ] . V_155 ) ;
V_152 += V_153 ;
if ( V_77 || V_153 != V_151 [ V_5 ] . V_154 )
break;
V_128 += V_151 [ V_5 ] . V_154 ;
}
* V_118 = V_152 ;
return V_77 ;
}
int F_103 ( struct V_3 * V_4 , const struct V_150 * V_151 ,
unsigned long V_32 , T_4 V_128 , T_3 * V_118 )
{
* V_118 = 0 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_112 ;
if ( ! V_4 -> V_156 )
return F_102 ( V_4 , V_151 , V_32 , V_128 , V_118 ) ;
return V_4 -> V_156 ( V_4 , V_151 , V_32 , V_128 , V_118 ) ;
}
void * F_104 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_8 V_21 = V_157 | V_158 | V_159 ;
T_3 V_160 = F_105 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_161 ;
* V_22 = F_106 ( T_3 , * V_22 , V_162 ) ;
while ( * V_22 > V_160 ) {
V_161 = F_107 ( * V_22 , V_21 ) ;
if ( V_161 )
return V_161 ;
* V_22 >>= 1 ;
* V_22 = F_108 ( * V_22 , V_4 -> V_24 ) ;
}
return F_107 ( * V_22 , V_59 ) ;
}
static int F_109 ( struct V_163 * V_164 , void * V_165 )
{
struct V_3 * V_4 ;
F_110 ( V_164 , L_23 ) ;
F_35 ( & V_58 ) ;
F_71 (mtd) {
F_111 ( V_164 , L_24 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_47 ( & V_58 ) ;
return 0 ;
}
static int F_112 ( struct V_166 * V_166 , struct V_167 * V_167 )
{
return F_113 ( V_167 , F_109 , NULL ) ;
}
static int T_9 F_114 ( struct V_55 * V_168 , const char * V_29 )
{
int V_77 ;
V_77 = F_115 ( V_168 ) ;
if ( ! V_77 )
V_77 = F_116 ( V_168 , NULL , L_25 , V_29 ) ;
if ( V_77 )
F_117 ( V_168 ) ;
return V_77 ;
}
static int T_9 F_118 ( void )
{
int V_77 ;
V_77 = F_119 ( & V_8 ) ;
if ( V_77 )
goto V_169;
V_77 = F_114 ( & V_57 , L_26 ) ;
if ( V_77 )
goto V_170;
V_171 = F_120 ( L_26 , 0 , NULL , & V_172 ) ;
V_77 = F_121 () ;
if ( V_77 )
goto V_173;
return 0 ;
V_173:
if ( V_171 )
F_122 ( L_26 , NULL ) ;
V_170:
F_123 ( & V_8 ) ;
V_169:
F_124 ( L_27 , V_77 ) ;
return V_77 ;
}
static void T_10 F_125 ( void )
{
F_126 () ;
if ( V_171 )
F_122 ( L_26 , NULL ) ;
F_123 ( & V_8 ) ;
F_117 ( & V_57 ) ;
F_127 ( & V_6 ) ;
}
