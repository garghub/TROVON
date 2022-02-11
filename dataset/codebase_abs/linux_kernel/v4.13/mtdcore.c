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
if ( F_37 ( V_4 -> V_2 . type , L_15 ) )
return - V_66 ;
F_38 ( V_4 -> V_24 == 0 ) ;
F_39 ( & V_67 ) ;
V_5 = F_40 ( & V_6 , V_4 , 0 , 0 , V_68 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
goto V_69;
}
V_4 -> V_7 = V_5 ;
V_4 -> V_70 = 0 ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = V_4 -> V_30 ;
if ( F_41 ( V_4 -> V_23 ) )
V_4 -> V_71 = F_42 ( V_4 -> V_23 ) - 1 ;
else
V_4 -> V_71 = 0 ;
if ( F_41 ( V_4 -> V_24 ) )
V_4 -> V_72 = F_42 ( V_4 -> V_24 ) - 1 ;
else
V_4 -> V_72 = 0 ;
V_4 -> V_73 = ( 1 << V_4 -> V_71 ) - 1 ;
V_4 -> V_74 = ( 1 << V_4 -> V_72 ) - 1 ;
if ( ( V_4 -> V_21 & V_75 ) && ( V_4 -> V_21 & V_76 ) ) {
error = F_43 ( V_4 , 0 , V_4 -> V_22 ) ;
if ( error && error != - V_77 )
F_44 ( V_78
L_16 ,
V_4 -> V_29 ) ;
error = 0 ;
}
V_4 -> V_2 . type = & V_79 ;
V_4 -> V_2 . V_80 = & V_8 ;
V_4 -> V_2 . V_81 = F_9 ( V_5 ) ;
F_45 ( & V_4 -> V_2 , L_17 , V_5 ) ;
F_46 ( & V_4 -> V_2 , V_4 ) ;
F_47 ( F_48 ( V_4 ) ) ;
error = F_49 ( & V_4 -> V_2 ) ;
if ( error )
goto V_82;
F_50 ( & V_8 , V_4 -> V_2 . V_83 , F_9 ( V_5 ) + 1 , NULL ,
L_18 , V_5 ) ;
F_51 ( L_19 , V_5 , V_4 -> V_29 ) ;
F_52 (not, &mtd_notifiers, list)
V_65 -> V_84 ( V_4 ) ;
F_53 ( & V_67 ) ;
F_54 ( V_85 ) ;
return 0 ;
V_82:
F_55 ( F_48 ( V_4 ) ) ;
F_56 ( & V_6 , V_5 ) ;
V_69:
F_53 ( & V_67 ) ;
return error ;
}
int F_57 ( struct V_3 * V_4 )
{
int V_86 ;
struct V_64 * V_65 ;
F_39 ( & V_67 ) ;
if ( F_58 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_86 = - V_87 ;
goto V_88;
}
F_52 (not, &mtd_notifiers, list)
V_65 -> remove ( V_4 ) ;
if ( V_4 -> V_70 ) {
F_44 ( V_89 L_20 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_70 ) ;
V_86 = - V_90 ;
} else {
F_59 ( & V_4 -> V_2 ) ;
F_56 ( & V_6 , V_4 -> V_7 ) ;
F_55 ( F_48 ( V_4 ) ) ;
F_60 ( V_85 ) ;
V_86 = 0 ;
}
V_88:
F_53 ( & V_67 ) ;
return V_86 ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_91 * V_92 )
{
const struct V_93 * V_94 = V_92 -> V_92 ;
int V_95 = V_92 -> V_96 ;
int V_86 ;
if ( V_95 == 0 || F_62 ( V_97 ) ) {
V_86 = F_36 ( V_4 ) ;
if ( V_86 )
return V_86 ;
}
if ( V_95 > 0 ) {
V_86 = F_63 ( V_4 , V_94 , V_95 ) ;
if ( V_86 && F_62 ( V_97 ) )
F_57 ( V_4 ) ;
return V_86 ;
}
return 0 ;
}
static void F_64 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_83 ) {
if ( ! V_4 -> V_98 && V_4 -> V_2 . V_83 -> V_99 )
V_4 -> V_98 = V_4 -> V_2 . V_83 -> V_99 -> V_98 ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 = F_65 ( V_4 -> V_2 . V_83 ) ;
} else {
F_51 ( L_21 ) ;
}
}
int F_66 ( struct V_3 * V_4 , const char * const * V_100 ,
struct V_101 * V_102 ,
const struct V_93 * V_92 ,
int V_96 )
{
struct V_91 V_103 ;
int V_86 ;
F_64 ( V_4 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_86 = F_67 ( V_4 , V_100 , & V_103 , V_102 ) ;
if ( ( V_86 < 0 || V_103 . V_96 == 0 ) && V_92 && V_96 ) {
V_103 = (struct V_91 ) {
. V_92 = V_92 ,
. V_96 = V_96 ,
} ;
} else if ( V_86 < 0 ) {
F_68 ( L_22 ,
V_86 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
}
V_86 = F_61 ( V_4 , & V_103 ) ;
if ( V_86 )
goto V_104;
F_37 ( V_4 -> V_51 && V_4 -> V_50 . V_105 ,
L_15 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_105 ) {
V_4 -> V_50 . V_105 = F_30 ;
F_69 ( & V_4 -> V_50 ) ;
}
V_104:
F_70 ( & V_103 ) ;
return V_86 ;
}
int F_71 ( struct V_3 * V_106 )
{
int V_107 ;
if ( V_106 -> V_51 )
F_72 ( & V_106 -> V_50 ) ;
V_107 = F_73 ( V_106 ) ;
if ( V_107 )
return V_107 ;
if ( ! F_74 ( & V_106 -> V_2 ) )
return 0 ;
return F_57 ( V_106 ) ;
}
void F_75 ( struct V_64 * V_108 )
{
struct V_3 * V_4 ;
F_39 ( & V_67 ) ;
F_76 ( & V_108 -> V_109 , & V_110 ) ;
F_54 ( V_85 ) ;
F_77 (mtd)
V_108 -> V_84 ( V_4 ) ;
F_53 ( & V_67 ) ;
}
int F_78 ( struct V_64 * V_111 )
{
struct V_3 * V_4 ;
F_39 ( & V_67 ) ;
F_60 ( V_85 ) ;
F_77 (mtd)
V_111 -> remove ( V_4 ) ;
F_79 ( & V_111 -> V_109 ) ;
F_53 ( & V_67 ) ;
return 0 ;
}
struct V_3 * F_80 ( struct V_3 * V_4 , int V_112 )
{
struct V_3 * V_86 = NULL , * V_113 ;
int V_107 = - V_87 ;
F_39 ( & V_67 ) ;
if ( V_112 == - 1 ) {
F_77 (other) {
if ( V_113 == V_4 ) {
V_86 = V_4 ;
break;
}
}
} else if ( V_112 >= 0 ) {
V_86 = F_58 ( & V_6 , V_112 ) ;
if ( V_4 && V_4 != V_86 )
V_86 = NULL ;
}
if ( ! V_86 ) {
V_86 = F_81 ( V_107 ) ;
goto V_104;
}
V_107 = F_82 ( V_86 ) ;
if ( V_107 )
V_86 = F_81 ( V_107 ) ;
V_104:
F_53 ( & V_67 ) ;
return V_86 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_107 ;
if ( ! F_83 ( V_4 -> V_98 ) )
return - V_87 ;
if ( V_4 -> V_114 ) {
V_107 = V_4 -> V_114 ( V_4 ) ;
if ( V_107 ) {
F_60 ( V_4 -> V_98 ) ;
return V_107 ;
}
}
V_4 -> V_70 ++ ;
return 0 ;
}
struct V_3 * F_84 ( const char * V_29 )
{
int V_107 = - V_87 ;
struct V_3 * V_4 = NULL , * V_113 ;
F_39 ( & V_67 ) ;
F_77 (other) {
if ( ! strcmp ( V_29 , V_113 -> V_29 ) ) {
V_4 = V_113 ;
break;
}
}
if ( ! V_4 )
goto V_115;
V_107 = F_82 ( V_4 ) ;
if ( V_107 )
goto V_115;
F_53 ( & V_67 ) ;
return V_4 ;
V_115:
F_53 ( & V_67 ) ;
return F_81 ( V_107 ) ;
}
void F_85 ( struct V_3 * V_4 )
{
F_39 ( & V_67 ) ;
F_86 ( V_4 ) ;
F_53 ( & V_67 ) ;
}
void F_86 ( struct V_3 * V_4 )
{
-- V_4 -> V_70 ;
F_38 ( V_4 -> V_70 < 0 ) ;
if ( V_4 -> V_116 )
V_4 -> V_116 ( V_4 ) ;
F_60 ( V_4 -> V_98 ) ;
}
int F_87 ( struct V_3 * V_4 , struct V_117 * V_118 )
{
if ( V_118 -> V_119 >= V_4 -> V_22 || V_118 -> V_120 > V_4 -> V_22 - V_118 -> V_119 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
V_118 -> V_122 = V_123 ;
if ( ! V_118 -> V_120 ) {
V_118 -> V_48 = V_124 ;
F_88 ( V_118 ) ;
return 0 ;
}
F_89 () ;
return V_4 -> V_125 ( V_4 , V_118 ) ;
}
int F_90 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 , T_3 * V_127 ,
void * * V_128 , T_5 * V_129 )
{
* V_127 = 0 ;
* V_128 = NULL ;
if ( V_129 )
* V_129 = 0 ;
if ( ! V_4 -> V_130 )
return - V_77 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_126 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_130 ( V_4 , V_126 , V_120 , V_127 , V_128 , V_129 ) ;
}
int F_91 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 )
{
if ( ! V_4 -> V_131 )
return - V_77 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_126 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_131 ( V_4 , V_126 , V_120 ) ;
}
unsigned long F_92 ( struct V_3 * V_4 , unsigned long V_120 ,
unsigned long V_132 , unsigned long V_21 )
{
if ( ! V_4 -> V_133 )
return - V_77 ;
if ( V_132 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_132 )
return - V_57 ;
return V_4 -> V_133 ( V_4 , V_120 , V_132 , V_21 ) ;
}
int F_93 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 , T_3 * V_127 ,
T_6 * V_11 )
{
int V_134 ;
* V_127 = 0 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_126 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
F_89 () ;
V_134 = V_4 -> V_135 ( V_4 , V_126 , V_120 , V_127 , V_11 ) ;
if ( F_94 ( V_134 < 0 ) )
return V_134 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_134 >= V_4 -> V_31 ? - V_136 : 0 ;
}
int F_95 ( struct V_3 * V_4 , T_4 V_137 , T_3 V_120 , T_3 * V_127 ,
const T_6 * V_11 )
{
* V_127 = 0 ;
if ( V_137 < 0 || V_137 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_137 )
return - V_57 ;
if ( ! V_4 -> V_138 || ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
if ( ! V_120 )
return 0 ;
F_89 () ;
return V_4 -> V_138 ( V_4 , V_137 , V_120 , V_127 , V_11 ) ;
}
int F_96 ( struct V_3 * V_4 , T_4 V_137 , T_3 V_120 , T_3 * V_127 ,
const T_6 * V_11 )
{
* V_127 = 0 ;
if ( ! V_4 -> V_139 )
return - V_77 ;
if ( V_137 < 0 || V_137 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_137 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_139 ( V_4 , V_137 , V_120 , V_127 , V_11 ) ;
}
int F_97 ( struct V_3 * V_4 , T_4 V_126 , struct V_140 * V_141 )
{
int V_134 ;
V_141 -> V_127 = V_141 -> V_142 = 0 ;
if ( ! V_4 -> V_143 )
return - V_77 ;
F_89 () ;
V_134 = V_4 -> V_143 ( V_4 , V_126 , V_141 ) ;
if ( F_94 ( V_134 < 0 ) )
return V_134 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_134 >= V_4 -> V_31 ? - V_136 : 0 ;
}
int F_98 ( struct V_3 * V_4 , T_4 V_137 ,
struct V_140 * V_141 )
{
V_141 -> V_127 = V_141 -> V_142 = 0 ;
if ( ! V_4 -> V_144 )
return - V_77 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
F_89 () ;
return V_4 -> V_144 ( V_4 , V_137 , V_141 ) ;
}
int F_99 ( struct V_3 * V_4 , int V_145 ,
struct V_146 * V_147 )
{
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
if ( ! V_4 || V_145 < 0 )
return - V_57 ;
if ( ! V_4 -> V_148 || ! V_4 -> V_148 -> V_149 )
return - V_150 ;
return V_4 -> V_148 -> V_149 ( V_4 , V_145 , V_147 ) ;
}
int F_100 ( struct V_3 * V_4 , int V_145 ,
struct V_146 * V_151 )
{
memset ( V_151 , 0 , sizeof( * V_151 ) ) ;
if ( ! V_4 || V_145 < 0 )
return - V_57 ;
if ( ! V_4 -> V_148 || ! V_4 -> V_148 -> free )
return - V_150 ;
return V_4 -> V_148 -> free ( V_4 , V_145 , V_151 ) ;
}
static int F_101 ( struct V_3 * V_4 , int V_152 ,
int * V_153 , struct V_146 * V_154 ,
int (* F_102)( struct V_3 * ,
int V_145 ,
struct V_146 * V_154 ) )
{
int V_155 = 0 , V_86 , V_145 = 0 ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
while ( 1 ) {
V_86 = F_102 ( V_4 , V_145 , V_154 ) ;
if ( V_86 )
return V_86 ;
if ( V_155 + V_154 -> V_156 > V_152 )
break;
V_155 += V_154 -> V_156 ;
V_145 ++ ;
}
V_154 -> V_132 += V_152 - V_155 ;
V_154 -> V_156 -= V_152 - V_155 ;
* V_153 = V_145 ;
return 0 ;
}
int F_103 ( struct V_3 * V_4 , int V_157 ,
int * V_145 ,
struct V_146 * V_154 )
{
return F_101 ( V_4 , V_157 , V_145 , V_154 ,
F_99 ) ;
}
static int F_104 ( struct V_3 * V_4 , T_7 * V_11 ,
const T_7 * V_158 , int V_159 , int V_160 ,
int (* F_102)( struct V_3 * ,
int V_145 ,
struct V_146 * V_154 ) )
{
struct V_146 V_154 ;
int V_145 , V_86 ;
V_86 = F_101 ( V_4 , V_159 , & V_145 ,
& V_154 , F_102 ) ;
while ( ! V_86 ) {
int V_161 ;
V_161 = F_105 ( int , V_160 , V_154 . V_156 ) ;
memcpy ( V_11 , V_158 + V_154 . V_132 , V_161 ) ;
V_11 += V_161 ;
V_160 -= V_161 ;
if ( ! V_160 )
break;
V_86 = F_102 ( V_4 , ++ V_145 , & V_154 ) ;
}
return V_86 ;
}
static int F_106 ( struct V_3 * V_4 , const T_7 * V_11 ,
T_7 * V_158 , int V_159 , int V_160 ,
int (* F_102)( struct V_3 * ,
int V_145 ,
struct V_146 * V_154 ) )
{
struct V_146 V_154 ;
int V_145 , V_86 ;
V_86 = F_101 ( V_4 , V_159 , & V_145 ,
& V_154 , F_102 ) ;
while ( ! V_86 ) {
int V_161 ;
V_161 = F_105 ( int , V_160 , V_154 . V_156 ) ;
memcpy ( V_158 + V_154 . V_132 , V_11 , V_161 ) ;
V_11 += V_161 ;
V_160 -= V_161 ;
if ( ! V_160 )
break;
V_86 = F_102 ( V_4 , ++ V_145 , & V_154 ) ;
}
return V_86 ;
}
static int F_107 ( struct V_3 * V_4 ,
int (* F_102)( struct V_3 * ,
int V_145 ,
struct V_146 * V_154 ) )
{
struct V_146 V_154 ;
int V_145 = 0 , V_86 , V_160 = 0 ;
while ( 1 ) {
V_86 = F_102 ( V_4 , V_145 ++ , & V_154 ) ;
if ( V_86 ) {
if ( V_86 == - V_162 )
V_86 = V_160 ;
break;
}
V_160 += V_154 . V_156 ;
}
return V_86 ;
}
int F_108 ( struct V_3 * V_4 , T_7 * V_163 ,
const T_7 * V_158 , int V_159 , int V_160 )
{
return F_104 ( V_4 , V_163 , V_158 , V_159 , V_160 ,
F_99 ) ;
}
int F_109 ( struct V_3 * V_4 , const T_7 * V_163 ,
T_7 * V_158 , int V_159 , int V_160 )
{
return F_106 ( V_4 , V_163 , V_158 , V_159 , V_160 ,
F_99 ) ;
}
int F_110 ( struct V_3 * V_4 , T_7 * V_164 ,
const T_7 * V_158 , int V_159 , int V_160 )
{
return F_104 ( V_4 , V_164 , V_158 , V_159 , V_160 ,
F_100 ) ;
}
int F_111 ( struct V_3 * V_4 , const T_7 * V_164 ,
T_7 * V_158 , int V_159 , int V_160 )
{
return F_106 ( V_4 , V_164 , V_158 , V_159 , V_160 ,
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
int F_114 ( struct V_3 * V_4 , T_3 V_120 , T_3 * V_127 ,
struct V_165 * V_11 )
{
if ( ! V_4 -> V_166 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_166 ( V_4 , V_120 , V_127 , V_11 ) ;
}
int F_115 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 ,
T_3 * V_127 , T_6 * V_11 )
{
* V_127 = 0 ;
if ( ! V_4 -> V_167 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_167 ( V_4 , V_126 , V_120 , V_127 , V_11 ) ;
}
int F_116 ( struct V_3 * V_4 , T_3 V_120 , T_3 * V_127 ,
struct V_165 * V_11 )
{
if ( ! V_4 -> V_168 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_168 ( V_4 , V_120 , V_127 , V_11 ) ;
}
int F_117 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 ,
T_3 * V_127 , T_6 * V_11 )
{
* V_127 = 0 ;
if ( ! V_4 -> V_169 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_169 ( V_4 , V_126 , V_120 , V_127 , V_11 ) ;
}
int F_118 ( struct V_3 * V_4 , T_4 V_137 , T_3 V_120 ,
T_3 * V_127 , T_6 * V_11 )
{
int V_86 ;
* V_127 = 0 ;
if ( ! V_4 -> V_170 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
V_86 = V_4 -> V_170 ( V_4 , V_137 , V_120 , V_127 , V_11 ) ;
if ( V_86 )
return V_86 ;
return ( * V_127 ) ? 0 : - V_171 ;
}
int F_119 ( struct V_3 * V_4 , T_4 V_126 , T_3 V_120 )
{
if ( ! V_4 -> V_172 )
return - V_77 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_172 ( V_4 , V_126 , V_120 ) ;
}
int F_120 ( struct V_3 * V_4 , T_4 V_173 , T_8 V_120 )
{
if ( ! V_4 -> V_174 )
return - V_77 ;
if ( V_173 < 0 || V_173 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_173 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_174 ( V_4 , V_173 , V_120 ) ;
}
int F_43 ( struct V_3 * V_4 , T_4 V_173 , T_8 V_120 )
{
if ( ! V_4 -> V_175 )
return - V_77 ;
if ( V_173 < 0 || V_173 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_173 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_175 ( V_4 , V_173 , V_120 ) ;
}
int F_121 ( struct V_3 * V_4 , T_4 V_173 , T_8 V_120 )
{
if ( ! V_4 -> V_176 )
return - V_77 ;
if ( V_173 < 0 || V_173 >= V_4 -> V_22 || V_120 > V_4 -> V_22 - V_173 )
return - V_57 ;
if ( ! V_120 )
return 0 ;
return V_4 -> V_176 ( V_4 , V_173 , V_120 ) ;
}
int F_122 ( struct V_3 * V_4 , T_4 V_173 )
{
if ( V_173 < 0 || V_173 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_177 )
return 0 ;
return V_4 -> V_177 ( V_4 , V_173 ) ;
}
int F_123 ( struct V_3 * V_4 , T_4 V_173 )
{
if ( V_173 < 0 || V_173 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_178 )
return 0 ;
return V_4 -> V_178 ( V_4 , V_173 ) ;
}
int F_124 ( struct V_3 * V_4 , T_4 V_173 )
{
if ( ! V_4 -> V_179 )
return - V_77 ;
if ( V_173 < 0 || V_173 >= V_4 -> V_22 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
return V_4 -> V_179 ( V_4 , V_173 ) ;
}
static int F_125 ( struct V_3 * V_4 , const struct V_180 * V_181 ,
unsigned long V_32 , T_4 V_137 , T_3 * V_127 )
{
unsigned long V_5 ;
T_3 V_182 = 0 , V_183 ;
int V_86 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_181 [ V_5 ] . V_184 )
continue;
V_86 = F_95 ( V_4 , V_137 , V_181 [ V_5 ] . V_184 , & V_183 ,
V_181 [ V_5 ] . V_185 ) ;
V_182 += V_183 ;
if ( V_86 || V_183 != V_181 [ V_5 ] . V_184 )
break;
V_137 += V_181 [ V_5 ] . V_184 ;
}
* V_127 = V_182 ;
return V_86 ;
}
int F_126 ( struct V_3 * V_4 , const struct V_180 * V_181 ,
unsigned long V_32 , T_4 V_137 , T_3 * V_127 )
{
* V_127 = 0 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_121 ;
if ( ! V_4 -> V_186 )
return F_125 ( V_4 , V_181 , V_32 , V_137 , V_127 ) ;
return V_4 -> V_186 ( V_4 , V_181 , V_32 , V_137 , V_127 ) ;
}
void * F_127 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_9 V_21 = V_187 | V_188 | V_189 ;
T_3 V_190 = F_128 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_191 ;
* V_22 = F_105 ( T_3 , * V_22 , V_192 ) ;
while ( * V_22 > V_190 ) {
V_191 = F_129 ( * V_22 , V_21 ) ;
if ( V_191 )
return V_191 ;
* V_22 >>= 1 ;
* V_22 = F_130 ( * V_22 , V_4 -> V_24 ) ;
}
return F_129 ( * V_22 , V_68 ) ;
}
static int F_131 ( struct V_193 * V_194 , void * V_195 )
{
struct V_3 * V_4 ;
F_132 ( V_194 , L_23 ) ;
F_39 ( & V_67 ) ;
F_77 (mtd) {
F_133 ( V_194 , L_24 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_53 ( & V_67 ) ;
return 0 ;
}
static int F_134 ( struct V_196 * V_196 , struct V_197 * V_197 )
{
return F_135 ( V_197 , F_131 , NULL ) ;
}
static struct V_198 * T_10 F_136 ( char * V_29 )
{
struct V_198 * V_199 ;
int V_86 ;
V_199 = F_137 ( V_68 ) ;
if ( ! V_199 )
return F_81 ( - V_200 ) ;
V_199 -> V_29 = V_29 ;
V_86 = F_138 ( V_199 , L_25 , V_29 ) ;
if ( V_86 )
F_139 ( V_199 ) ;
return V_86 ? F_81 ( V_86 ) : V_199 ;
}
static int T_10 F_140 ( void )
{
int V_86 ;
V_86 = F_141 ( & V_8 ) ;
if ( V_86 )
goto V_201;
V_202 = F_136 ( L_26 ) ;
if ( F_142 ( V_202 ) ) {
V_86 = F_143 ( V_202 ) ;
goto V_203;
}
V_204 = F_144 ( L_26 , 0 , NULL , & V_205 ) ;
V_86 = F_145 () ;
if ( V_86 )
goto V_206;
return 0 ;
V_206:
if ( V_204 )
F_146 ( L_26 , NULL ) ;
F_139 ( V_202 ) ;
V_203:
F_147 ( & V_8 ) ;
V_201:
F_148 ( L_27 , V_86 ) ;
return V_86 ;
}
static void T_11 F_149 ( void )
{
F_150 () ;
if ( V_204 )
F_146 ( L_26 , NULL ) ;
F_147 ( & V_8 ) ;
F_139 ( V_202 ) ;
F_151 ( & V_6 ) ;
}
