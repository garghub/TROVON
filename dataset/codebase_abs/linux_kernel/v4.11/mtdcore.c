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
int F_32 ( struct V_3 * V_4 , int V_53 ,
struct V_54 * V_55 )
{
int V_56 = F_33 ( V_4 ) / F_34 ( V_4 ) ;
if ( V_53 < 0 || V_53 >= V_56 )
return - V_57 ;
if ( V_4 -> V_58 && V_4 -> V_58 -> V_59 )
return V_4 -> V_58 -> V_59 ( V_4 , V_53 , V_55 ) ;
V_55 -> V_60 = 0 ;
V_55 -> V_61 = V_53 ;
return 0 ;
}
int F_35 ( struct V_3 * V_4 ,
const struct V_54 * V_55 )
{
int V_62 = F_34 ( V_4 ) ;
int V_56 = F_33 ( V_4 ) / V_62 ;
if ( ! V_55 || V_55 -> V_61 < 0 || V_55 -> V_61 >= V_56 ||
V_55 -> V_60 < 0 || V_55 -> V_60 >= V_62 )
return - V_57 ;
if ( V_4 -> V_58 && V_4 -> V_58 -> V_63 )
return V_4 -> V_58 -> V_63 ( V_4 , V_55 ) ;
return V_55 -> V_61 ;
}
int F_34 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_58 || ! V_4 -> V_58 -> V_62 )
return 1 ;
return V_4 -> V_58 -> V_62 ;
}
int F_36 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
int V_5 , error ;
if ( F_37 ( V_4 -> V_66 , L_15 ) )
return - V_67 ;
V_4 -> V_66 = V_68 ;
F_38 ( V_4 -> V_24 == 0 ) ;
F_39 ( & V_69 ) ;
V_5 = F_40 ( & V_6 , V_4 , 0 , 0 , V_70 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
goto V_71;
}
V_4 -> V_7 = V_5 ;
V_4 -> V_72 = 0 ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = V_4 -> V_30 ;
if ( F_41 ( V_4 -> V_23 ) )
V_4 -> V_73 = F_42 ( V_4 -> V_23 ) - 1 ;
else
V_4 -> V_73 = 0 ;
if ( F_41 ( V_4 -> V_24 ) )
V_4 -> V_74 = F_42 ( V_4 -> V_24 ) - 1 ;
else
V_4 -> V_74 = 0 ;
V_4 -> V_75 = ( 1 << V_4 -> V_73 ) - 1 ;
V_4 -> V_76 = ( 1 << V_4 -> V_74 ) - 1 ;
if ( ( V_4 -> V_21 & V_77 ) && ( V_4 -> V_21 & V_78 ) ) {
error = F_43 ( V_4 , 0 , V_4 -> V_22 ) ;
if ( error && error != - V_79 )
F_44 ( V_80
L_16 ,
V_4 -> V_29 ) ;
error = 0 ;
}
V_4 -> V_2 . type = & V_81 ;
V_4 -> V_2 . V_82 = & V_8 ;
V_4 -> V_2 . V_83 = F_9 ( V_5 ) ;
F_45 ( & V_4 -> V_2 , L_17 , V_5 ) ;
F_46 ( & V_4 -> V_2 , V_4 ) ;
F_47 ( F_48 ( V_4 ) ) ;
error = F_49 ( & V_4 -> V_2 ) ;
if ( error )
goto V_84;
F_50 ( & V_8 , V_4 -> V_2 . V_85 , F_9 ( V_5 ) + 1 , NULL ,
L_18 , V_5 ) ;
F_51 ( L_19 , V_5 , V_4 -> V_29 ) ;
F_52 (not, &mtd_notifiers, list)
V_65 -> V_86 ( V_4 ) ;
F_53 ( & V_69 ) ;
F_54 ( V_87 ) ;
return 0 ;
V_84:
F_55 ( F_48 ( V_4 ) ) ;
F_56 ( & V_6 , V_5 ) ;
V_71:
F_53 ( & V_69 ) ;
return error ;
}
int F_57 ( struct V_3 * V_4 )
{
int V_88 ;
struct V_64 * V_65 ;
F_39 ( & V_69 ) ;
if ( F_58 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_88 = - V_89 ;
goto V_90;
}
F_52 (not, &mtd_notifiers, list)
V_65 -> remove ( V_4 ) ;
if ( V_4 -> V_72 ) {
F_44 ( V_91 L_20 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_72 ) ;
V_88 = - V_92 ;
} else {
F_59 ( & V_4 -> V_2 ) ;
F_56 ( & V_6 , V_4 -> V_7 ) ;
F_55 ( F_48 ( V_4 ) ) ;
F_60 ( V_87 ) ;
V_88 = 0 ;
}
V_90:
F_53 ( & V_69 ) ;
return V_88 ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_93 * V_94 )
{
const struct V_95 * V_96 = V_94 -> V_94 ;
int V_97 = V_94 -> V_98 ;
int V_88 ;
if ( V_97 == 0 || F_62 ( V_99 ) ) {
V_88 = F_36 ( V_4 ) ;
if ( V_88 )
return V_88 ;
}
if ( V_97 > 0 ) {
V_88 = F_63 ( V_4 , V_96 , V_97 ) ;
if ( V_88 && F_62 ( V_99 ) )
F_57 ( V_4 ) ;
return V_88 ;
}
return 0 ;
}
static void F_64 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_85 ) {
if ( ! V_4 -> V_100 && V_4 -> V_2 . V_85 -> V_101 )
V_4 -> V_100 = V_4 -> V_2 . V_85 -> V_101 -> V_100 ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 = F_65 ( V_4 -> V_2 . V_85 ) ;
} else {
F_51 ( L_21 ) ;
}
}
int F_66 ( struct V_3 * V_4 , const char * const * V_102 ,
struct V_103 * V_104 ,
const struct V_95 * V_94 ,
int V_98 )
{
struct V_93 V_105 ;
int V_88 ;
F_64 ( V_4 ) ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_88 = F_67 ( V_4 , V_102 , & V_105 , V_104 ) ;
if ( ( V_88 < 0 || V_105 . V_98 == 0 ) && V_94 && V_98 ) {
V_105 = (struct V_93 ) {
. V_94 = V_94 ,
. V_98 = V_98 ,
} ;
} else if ( V_88 < 0 ) {
F_68 ( L_22 ,
V_88 ) ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
}
V_88 = F_61 ( V_4 , & V_105 ) ;
if ( V_88 )
goto V_106;
F_37 ( V_4 -> V_51 && V_4 -> V_50 . V_107 ,
L_15 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_107 ) {
V_4 -> V_50 . V_107 = F_30 ;
F_69 ( & V_4 -> V_50 ) ;
}
V_106:
F_70 ( & V_105 ) ;
return V_88 ;
}
int F_71 ( struct V_3 * V_108 )
{
int V_109 ;
if ( V_108 -> V_51 )
F_72 ( & V_108 -> V_50 ) ;
V_109 = F_73 ( V_108 ) ;
if ( V_109 )
return V_109 ;
if ( ! F_74 ( & V_108 -> V_2 ) )
return 0 ;
return F_57 ( V_108 ) ;
}
void F_75 ( struct V_64 * V_110 )
{
struct V_3 * V_4 ;
F_39 ( & V_69 ) ;
F_76 ( & V_110 -> V_111 , & V_112 ) ;
F_54 ( V_87 ) ;
F_77 (mtd)
V_110 -> V_86 ( V_4 ) ;
F_53 ( & V_69 ) ;
}
int F_78 ( struct V_64 * V_113 )
{
struct V_3 * V_4 ;
F_39 ( & V_69 ) ;
F_60 ( V_87 ) ;
F_77 (mtd)
V_113 -> remove ( V_4 ) ;
F_79 ( & V_113 -> V_111 ) ;
F_53 ( & V_69 ) ;
return 0 ;
}
struct V_3 * F_80 ( struct V_3 * V_4 , int V_114 )
{
struct V_3 * V_88 = NULL , * V_115 ;
int V_109 = - V_89 ;
F_39 ( & V_69 ) ;
if ( V_114 == - 1 ) {
F_77 (other) {
if ( V_115 == V_4 ) {
V_88 = V_4 ;
break;
}
}
} else if ( V_114 >= 0 ) {
V_88 = F_58 ( & V_6 , V_114 ) ;
if ( V_4 && V_4 != V_88 )
V_88 = NULL ;
}
if ( ! V_88 ) {
V_88 = F_81 ( V_109 ) ;
goto V_106;
}
V_109 = F_82 ( V_88 ) ;
if ( V_109 )
V_88 = F_81 ( V_109 ) ;
V_106:
F_53 ( & V_69 ) ;
return V_88 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_109 ;
if ( ! F_83 ( V_4 -> V_100 ) )
return - V_89 ;
if ( V_4 -> V_116 ) {
V_109 = V_4 -> V_116 ( V_4 ) ;
if ( V_109 ) {
F_60 ( V_4 -> V_100 ) ;
return V_109 ;
}
}
V_4 -> V_72 ++ ;
return 0 ;
}
struct V_3 * F_84 ( const char * V_29 )
{
int V_109 = - V_89 ;
struct V_3 * V_4 = NULL , * V_115 ;
F_39 ( & V_69 ) ;
F_77 (other) {
if ( ! strcmp ( V_29 , V_115 -> V_29 ) ) {
V_4 = V_115 ;
break;
}
}
if ( ! V_4 )
goto V_117;
V_109 = F_82 ( V_4 ) ;
if ( V_109 )
goto V_117;
F_53 ( & V_69 ) ;
return V_4 ;
V_117:
F_53 ( & V_69 ) ;
return F_81 ( V_109 ) ;
}
void F_85 ( struct V_3 * V_4 )
{
F_39 ( & V_69 ) ;
F_86 ( V_4 ) ;
F_53 ( & V_69 ) ;
}
void F_86 ( struct V_3 * V_4 )
{
-- V_4 -> V_72 ;
F_38 ( V_4 -> V_72 < 0 ) ;
if ( V_4 -> V_118 )
V_4 -> V_118 ( V_4 ) ;
F_60 ( V_4 -> V_100 ) ;
}
int F_87 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
if ( V_120 -> V_121 >= V_4 -> V_22 || V_120 -> V_122 > V_4 -> V_22 - V_120 -> V_121 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
V_120 -> V_124 = V_125 ;
if ( ! V_120 -> V_122 ) {
V_120 -> V_48 = V_126 ;
F_88 ( V_120 ) ;
return 0 ;
}
F_89 () ;
return V_4 -> V_127 ( V_4 , V_120 ) ;
}
int F_90 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 , T_3 * V_129 ,
void * * V_130 , T_5 * V_131 )
{
* V_129 = 0 ;
* V_130 = NULL ;
if ( V_131 )
* V_131 = 0 ;
if ( ! V_4 -> V_132 )
return - V_79 ;
if ( V_128 < 0 || V_128 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_128 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_132 ( V_4 , V_128 , V_122 , V_129 , V_130 , V_131 ) ;
}
int F_91 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 )
{
if ( ! V_4 -> V_132 )
return - V_79 ;
if ( V_128 < 0 || V_128 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_128 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_133 ( V_4 , V_128 , V_122 ) ;
}
unsigned long F_92 ( struct V_3 * V_4 , unsigned long V_122 ,
unsigned long V_134 , unsigned long V_21 )
{
if ( ! V_4 -> V_135 )
return - V_79 ;
if ( V_134 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_134 )
return - V_57 ;
return V_4 -> V_135 ( V_4 , V_122 , V_134 , V_21 ) ;
}
int F_93 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 , T_3 * V_129 ,
T_6 * V_11 )
{
int V_136 ;
* V_129 = 0 ;
if ( V_128 < 0 || V_128 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_128 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
F_89 () ;
V_136 = V_4 -> V_137 ( V_4 , V_128 , V_122 , V_129 , V_11 ) ;
if ( F_94 ( V_136 < 0 ) )
return V_136 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_136 >= V_4 -> V_31 ? - V_138 : 0 ;
}
int F_95 ( struct V_3 * V_4 , T_4 V_139 , T_3 V_122 , T_3 * V_129 ,
const T_6 * V_11 )
{
* V_129 = 0 ;
if ( V_139 < 0 || V_139 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_139 )
return - V_57 ;
if ( ! V_4 -> V_140 || ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
if ( ! V_122 )
return 0 ;
F_89 () ;
return V_4 -> V_140 ( V_4 , V_139 , V_122 , V_129 , V_11 ) ;
}
int F_96 ( struct V_3 * V_4 , T_4 V_139 , T_3 V_122 , T_3 * V_129 ,
const T_6 * V_11 )
{
* V_129 = 0 ;
if ( ! V_4 -> V_141 )
return - V_79 ;
if ( V_139 < 0 || V_139 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_139 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_141 ( V_4 , V_139 , V_122 , V_129 , V_11 ) ;
}
int F_97 ( struct V_3 * V_4 , T_4 V_128 , struct V_142 * V_143 )
{
int V_136 ;
V_143 -> V_129 = V_143 -> V_144 = 0 ;
if ( ! V_4 -> V_145 )
return - V_79 ;
F_89 () ;
V_136 = V_4 -> V_145 ( V_4 , V_128 , V_143 ) ;
if ( F_94 ( V_136 < 0 ) )
return V_136 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_136 >= V_4 -> V_31 ? - V_138 : 0 ;
}
int F_98 ( struct V_3 * V_4 , T_4 V_139 ,
struct V_142 * V_143 )
{
V_143 -> V_129 = V_143 -> V_144 = 0 ;
if ( ! V_4 -> V_146 )
return - V_79 ;
if ( ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
F_89 () ;
return V_4 -> V_146 ( V_4 , V_139 , V_143 ) ;
}
int F_99 ( struct V_3 * V_4 , int V_147 ,
struct V_148 * V_149 )
{
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
if ( ! V_4 || V_147 < 0 )
return - V_57 ;
if ( ! V_4 -> V_150 || ! V_4 -> V_150 -> V_151 )
return - V_152 ;
return V_4 -> V_150 -> V_151 ( V_4 , V_147 , V_149 ) ;
}
int F_100 ( struct V_3 * V_4 , int V_147 ,
struct V_148 * V_153 )
{
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
if ( ! V_4 || V_147 < 0 )
return - V_57 ;
if ( ! V_4 -> V_150 || ! V_4 -> V_150 -> free )
return - V_152 ;
return V_4 -> V_150 -> free ( V_4 , V_147 , V_153 ) ;
}
static int F_101 ( struct V_3 * V_4 , int V_154 ,
int * V_155 , struct V_148 * V_156 ,
int (* F_102)( struct V_3 * ,
int V_147 ,
struct V_148 * V_156 ) )
{
int V_157 = 0 , V_88 , V_147 = 0 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
while ( 1 ) {
V_88 = F_102 ( V_4 , V_147 , V_156 ) ;
if ( V_88 )
return V_88 ;
if ( V_157 + V_156 -> V_158 > V_154 )
break;
V_157 += V_156 -> V_158 ;
V_147 ++ ;
}
V_156 -> V_134 += V_154 - V_157 ;
V_156 -> V_158 -= V_154 - V_157 ;
* V_155 = V_147 ;
return 0 ;
}
int F_103 ( struct V_3 * V_4 , int V_159 ,
int * V_147 ,
struct V_148 * V_156 )
{
return F_101 ( V_4 , V_159 , V_147 , V_156 ,
F_99 ) ;
}
static int F_104 ( struct V_3 * V_4 , T_7 * V_11 ,
const T_7 * V_160 , int V_161 , int V_162 ,
int (* F_102)( struct V_3 * ,
int V_147 ,
struct V_148 * V_156 ) )
{
struct V_148 V_156 ;
int V_147 , V_88 ;
V_88 = F_101 ( V_4 , V_161 , & V_147 ,
& V_156 , F_102 ) ;
while ( ! V_88 ) {
int V_163 ;
V_163 = F_105 ( int , V_162 , V_156 . V_158 ) ;
memcpy ( V_11 , V_160 + V_156 . V_134 , V_163 ) ;
V_11 += V_163 ;
V_162 -= V_163 ;
if ( ! V_162 )
break;
V_88 = F_102 ( V_4 , ++ V_147 , & V_156 ) ;
}
return V_88 ;
}
static int F_106 ( struct V_3 * V_4 , const T_7 * V_11 ,
T_7 * V_160 , int V_161 , int V_162 ,
int (* F_102)( struct V_3 * ,
int V_147 ,
struct V_148 * V_156 ) )
{
struct V_148 V_156 ;
int V_147 , V_88 ;
V_88 = F_101 ( V_4 , V_161 , & V_147 ,
& V_156 , F_102 ) ;
while ( ! V_88 ) {
int V_163 ;
V_163 = F_105 ( int , V_162 , V_156 . V_158 ) ;
memcpy ( V_160 + V_156 . V_134 , V_11 , V_163 ) ;
V_11 += V_163 ;
V_162 -= V_163 ;
if ( ! V_162 )
break;
V_88 = F_102 ( V_4 , ++ V_147 , & V_156 ) ;
}
return V_88 ;
}
static int F_107 ( struct V_3 * V_4 ,
int (* F_102)( struct V_3 * ,
int V_147 ,
struct V_148 * V_156 ) )
{
struct V_148 V_156 ;
int V_147 = 0 , V_88 , V_162 = 0 ;
while ( 1 ) {
V_88 = F_102 ( V_4 , V_147 ++ , & V_156 ) ;
if ( V_88 ) {
if ( V_88 == - V_164 )
V_88 = V_162 ;
break;
}
V_162 += V_156 . V_158 ;
}
return V_88 ;
}
int F_108 ( struct V_3 * V_4 , T_7 * V_165 ,
const T_7 * V_160 , int V_161 , int V_162 )
{
return F_104 ( V_4 , V_165 , V_160 , V_161 , V_162 ,
F_99 ) ;
}
int F_109 ( struct V_3 * V_4 , const T_7 * V_165 ,
T_7 * V_160 , int V_161 , int V_162 )
{
return F_106 ( V_4 , V_165 , V_160 , V_161 , V_162 ,
F_99 ) ;
}
int F_110 ( struct V_3 * V_4 , T_7 * V_166 ,
const T_7 * V_160 , int V_161 , int V_162 )
{
return F_104 ( V_4 , V_166 , V_160 , V_161 , V_162 ,
F_100 ) ;
}
int F_111 ( struct V_3 * V_4 , const T_7 * V_166 ,
T_7 * V_160 , int V_161 , int V_162 )
{
return F_106 ( V_4 , V_166 , V_160 , V_161 , V_162 ,
F_100 ) ;
}
int F_112 ( struct V_3 * V_4 )
{
return F_107 ( V_4 , F_100 ) ;
}
int F_113 ( struct V_3 * V_4 )
{
return F_107 ( V_4 , F_99 ) ;
}
int F_114 ( struct V_3 * V_4 , T_3 V_122 , T_3 * V_129 ,
struct V_167 * V_11 )
{
if ( ! V_4 -> V_168 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_168 ( V_4 , V_122 , V_129 , V_11 ) ;
}
int F_115 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 ,
T_3 * V_129 , T_6 * V_11 )
{
* V_129 = 0 ;
if ( ! V_4 -> V_169 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_169 ( V_4 , V_128 , V_122 , V_129 , V_11 ) ;
}
int F_116 ( struct V_3 * V_4 , T_3 V_122 , T_3 * V_129 ,
struct V_167 * V_11 )
{
if ( ! V_4 -> V_170 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_170 ( V_4 , V_122 , V_129 , V_11 ) ;
}
int F_117 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 ,
T_3 * V_129 , T_6 * V_11 )
{
* V_129 = 0 ;
if ( ! V_4 -> V_171 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_171 ( V_4 , V_128 , V_122 , V_129 , V_11 ) ;
}
int F_118 ( struct V_3 * V_4 , T_4 V_139 , T_3 V_122 ,
T_3 * V_129 , T_6 * V_11 )
{
int V_88 ;
* V_129 = 0 ;
if ( ! V_4 -> V_172 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
V_88 = V_4 -> V_172 ( V_4 , V_139 , V_122 , V_129 , V_11 ) ;
if ( V_88 )
return V_88 ;
return ( * V_129 ) ? 0 : - V_173 ;
}
int F_119 ( struct V_3 * V_4 , T_4 V_128 , T_3 V_122 )
{
if ( ! V_4 -> V_174 )
return - V_79 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_174 ( V_4 , V_128 , V_122 ) ;
}
int F_120 ( struct V_3 * V_4 , T_4 V_175 , T_8 V_122 )
{
if ( ! V_4 -> V_176 )
return - V_79 ;
if ( V_175 < 0 || V_175 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_175 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_176 ( V_4 , V_175 , V_122 ) ;
}
int F_43 ( struct V_3 * V_4 , T_4 V_175 , T_8 V_122 )
{
if ( ! V_4 -> V_177 )
return - V_79 ;
if ( V_175 < 0 || V_175 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_175 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_177 ( V_4 , V_175 , V_122 ) ;
}
int F_121 ( struct V_3 * V_4 , T_4 V_175 , T_8 V_122 )
{
if ( ! V_4 -> V_178 )
return - V_79 ;
if ( V_175 < 0 || V_175 >= V_4 -> V_22 || V_122 > V_4 -> V_22 - V_175 )
return - V_57 ;
if ( ! V_122 )
return 0 ;
return V_4 -> V_178 ( V_4 , V_175 , V_122 ) ;
}
int F_122 ( struct V_3 * V_4 , T_4 V_175 )
{
if ( V_175 < 0 || V_175 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_179 )
return 0 ;
return V_4 -> V_179 ( V_4 , V_175 ) ;
}
int F_123 ( struct V_3 * V_4 , T_4 V_175 )
{
if ( V_175 < 0 || V_175 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_180 )
return 0 ;
return V_4 -> V_180 ( V_4 , V_175 ) ;
}
int F_124 ( struct V_3 * V_4 , T_4 V_175 )
{
if ( ! V_4 -> V_181 )
return - V_79 ;
if ( V_175 < 0 || V_175 >= V_4 -> V_22 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
return V_4 -> V_181 ( V_4 , V_175 ) ;
}
static int F_125 ( struct V_3 * V_4 , const struct V_182 * V_183 ,
unsigned long V_32 , T_4 V_139 , T_3 * V_129 )
{
unsigned long V_5 ;
T_3 V_184 = 0 , V_185 ;
int V_88 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_183 [ V_5 ] . V_186 )
continue;
V_88 = F_95 ( V_4 , V_139 , V_183 [ V_5 ] . V_186 , & V_185 ,
V_183 [ V_5 ] . V_187 ) ;
V_184 += V_185 ;
if ( V_88 || V_185 != V_183 [ V_5 ] . V_186 )
break;
V_139 += V_183 [ V_5 ] . V_186 ;
}
* V_129 = V_184 ;
return V_88 ;
}
int F_126 ( struct V_3 * V_4 , const struct V_182 * V_183 ,
unsigned long V_32 , T_4 V_139 , T_3 * V_129 )
{
* V_129 = 0 ;
if ( ! ( V_4 -> V_21 & V_77 ) )
return - V_123 ;
if ( ! V_4 -> V_188 )
return F_125 ( V_4 , V_183 , V_32 , V_139 , V_129 ) ;
return V_4 -> V_188 ( V_4 , V_183 , V_32 , V_139 , V_129 ) ;
}
void * F_127 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_9 V_21 = V_189 | V_190 | V_191 ;
T_3 V_192 = F_128 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_193 ;
* V_22 = F_105 ( T_3 , * V_22 , V_194 ) ;
while ( * V_22 > V_192 ) {
V_193 = F_129 ( * V_22 , V_21 ) ;
if ( V_193 )
return V_193 ;
* V_22 >>= 1 ;
* V_22 = F_130 ( * V_22 , V_4 -> V_24 ) ;
}
return F_129 ( * V_22 , V_70 ) ;
}
static int F_131 ( struct V_195 * V_196 , void * V_197 )
{
struct V_3 * V_4 ;
F_132 ( V_196 , L_23 ) ;
F_39 ( & V_69 ) ;
F_77 (mtd) {
F_133 ( V_196 , L_24 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_53 ( & V_69 ) ;
return 0 ;
}
static int F_134 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_135 ( V_199 , F_131 , NULL ) ;
}
static struct V_66 * T_10 F_136 ( char * V_29 )
{
struct V_66 * V_200 ;
int V_88 ;
V_200 = F_137 ( sizeof( * V_200 ) , V_70 ) ;
if ( ! V_200 )
return F_81 ( - V_201 ) ;
V_88 = F_138 ( V_200 , V_29 ) ;
if ( V_88 )
F_139 ( V_200 ) ;
return V_88 ? F_81 ( V_88 ) : V_200 ;
}
static int T_10 F_140 ( void )
{
int V_88 ;
V_88 = F_141 ( & V_8 ) ;
if ( V_88 )
goto V_202;
V_68 = F_136 ( L_25 ) ;
if ( F_142 ( V_68 ) ) {
V_88 = F_143 ( V_68 ) ;
goto V_203;
}
V_204 = F_144 ( L_25 , 0 , NULL , & V_205 ) ;
V_88 = F_145 () ;
if ( V_88 )
goto V_206;
return 0 ;
V_206:
if ( V_204 )
F_146 ( L_25 , NULL ) ;
F_147 ( V_68 ) ;
F_139 ( V_68 ) ;
V_203:
F_148 ( & V_8 ) ;
V_202:
F_149 ( L_26 , V_88 ) ;
return V_88 ;
}
static void T_11 F_150 ( void )
{
F_151 () ;
if ( V_204 )
F_146 ( L_25 , NULL ) ;
F_148 ( & V_8 ) ;
F_147 ( V_68 ) ;
F_139 ( V_68 ) ;
F_152 ( & V_6 ) ;
}
