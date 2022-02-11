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
if ( ! F_50 ( V_83 ) ) {
V_4 -> V_84 . V_85 = F_51 ( F_52 ( & V_4 -> V_2 ) , V_83 ) ;
if ( F_50 ( V_4 -> V_84 . V_85 ) ) {
F_53 ( L_18 ,
F_52 ( & V_4 -> V_2 ) ) ;
}
}
F_54 ( & V_8 , V_4 -> V_2 . V_86 , F_9 ( V_5 ) + 1 , NULL ,
L_19 , V_5 ) ;
F_53 ( L_20 , V_5 , V_4 -> V_29 ) ;
F_55 (not, &mtd_notifiers, list)
V_65 -> V_87 ( V_4 ) ;
F_56 ( & V_67 ) ;
F_57 ( V_88 ) ;
return 0 ;
V_82:
F_58 ( F_48 ( V_4 ) ) ;
F_59 ( & V_6 , V_5 ) ;
V_69:
F_56 ( & V_67 ) ;
return error ;
}
int F_60 ( struct V_3 * V_4 )
{
int V_89 ;
struct V_64 * V_65 ;
F_39 ( & V_67 ) ;
F_61 ( V_4 -> V_84 . V_85 ) ;
if ( F_62 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_89 = - V_90 ;
goto V_91;
}
F_55 (not, &mtd_notifiers, list)
V_65 -> remove ( V_4 ) ;
if ( V_4 -> V_70 ) {
F_44 ( V_92 L_21 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_70 ) ;
V_89 = - V_93 ;
} else {
F_63 ( & V_4 -> V_2 ) ;
F_59 ( & V_6 , V_4 -> V_7 ) ;
F_58 ( F_48 ( V_4 ) ) ;
F_64 ( V_88 ) ;
V_89 = 0 ;
}
V_91:
F_56 ( & V_67 ) ;
return V_89 ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
const struct V_96 * V_97 = V_95 -> V_95 ;
int V_98 = V_95 -> V_99 ;
int V_89 ;
if ( V_98 == 0 || F_66 ( V_100 ) ) {
V_89 = F_36 ( V_4 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_98 > 0 ) {
V_89 = F_67 ( V_4 , V_97 , V_98 ) ;
if ( V_89 && F_66 ( V_100 ) )
F_60 ( V_4 ) ;
return V_89 ;
}
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_86 ) {
if ( ! V_4 -> V_101 && V_4 -> V_2 . V_86 -> V_102 )
V_4 -> V_101 = V_4 -> V_2 . V_86 -> V_102 -> V_101 ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 = F_52 ( V_4 -> V_2 . V_86 ) ;
} else {
F_53 ( L_22 ) ;
}
}
int F_69 ( struct V_3 * V_4 , const char * const * V_103 ,
struct V_104 * V_105 ,
const struct V_96 * V_95 ,
int V_99 )
{
struct V_94 V_106 ;
int V_89 ;
F_68 ( V_4 ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_89 = F_70 ( V_4 , V_103 , & V_106 , V_105 ) ;
if ( ( V_89 < 0 || V_106 . V_99 == 0 ) && V_95 && V_99 ) {
V_106 = (struct V_94 ) {
. V_95 = V_95 ,
. V_99 = V_99 ,
} ;
} else if ( V_89 < 0 ) {
F_71 ( L_23 ,
V_89 ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
}
V_89 = F_65 ( V_4 , & V_106 ) ;
if ( V_89 )
goto V_107;
F_37 ( V_4 -> V_51 && V_4 -> V_50 . V_108 ,
L_15 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_108 ) {
V_4 -> V_50 . V_108 = F_30 ;
F_72 ( & V_4 -> V_50 ) ;
}
V_107:
F_73 ( & V_106 ) ;
return V_89 ;
}
int F_74 ( struct V_3 * V_109 )
{
int V_110 ;
if ( V_109 -> V_51 )
F_75 ( & V_109 -> V_50 ) ;
V_110 = F_76 ( V_109 ) ;
if ( V_110 )
return V_110 ;
if ( ! F_77 ( & V_109 -> V_2 ) )
return 0 ;
return F_60 ( V_109 ) ;
}
void F_78 ( struct V_64 * V_111 )
{
struct V_3 * V_4 ;
F_39 ( & V_67 ) ;
F_79 ( & V_111 -> V_112 , & V_113 ) ;
F_57 ( V_88 ) ;
F_80 (mtd)
V_111 -> V_87 ( V_4 ) ;
F_56 ( & V_67 ) ;
}
int F_81 ( struct V_64 * V_114 )
{
struct V_3 * V_4 ;
F_39 ( & V_67 ) ;
F_64 ( V_88 ) ;
F_80 (mtd)
V_114 -> remove ( V_4 ) ;
F_82 ( & V_114 -> V_112 ) ;
F_56 ( & V_67 ) ;
return 0 ;
}
struct V_3 * F_83 ( struct V_3 * V_4 , int V_115 )
{
struct V_3 * V_89 = NULL , * V_116 ;
int V_110 = - V_90 ;
F_39 ( & V_67 ) ;
if ( V_115 == - 1 ) {
F_80 (other) {
if ( V_116 == V_4 ) {
V_89 = V_4 ;
break;
}
}
} else if ( V_115 >= 0 ) {
V_89 = F_62 ( & V_6 , V_115 ) ;
if ( V_4 && V_4 != V_89 )
V_89 = NULL ;
}
if ( ! V_89 ) {
V_89 = F_84 ( V_110 ) ;
goto V_107;
}
V_110 = F_85 ( V_89 ) ;
if ( V_110 )
V_89 = F_84 ( V_110 ) ;
V_107:
F_56 ( & V_67 ) ;
return V_89 ;
}
int F_85 ( struct V_3 * V_4 )
{
int V_110 ;
if ( ! F_86 ( V_4 -> V_101 ) )
return - V_90 ;
if ( V_4 -> V_117 ) {
V_110 = V_4 -> V_117 ( V_4 ) ;
if ( V_110 ) {
F_64 ( V_4 -> V_101 ) ;
return V_110 ;
}
}
V_4 -> V_70 ++ ;
return 0 ;
}
struct V_3 * F_87 ( const char * V_29 )
{
int V_110 = - V_90 ;
struct V_3 * V_4 = NULL , * V_116 ;
F_39 ( & V_67 ) ;
F_80 (other) {
if ( ! strcmp ( V_29 , V_116 -> V_29 ) ) {
V_4 = V_116 ;
break;
}
}
if ( ! V_4 )
goto V_118;
V_110 = F_85 ( V_4 ) ;
if ( V_110 )
goto V_118;
F_56 ( & V_67 ) ;
return V_4 ;
V_118:
F_56 ( & V_67 ) ;
return F_84 ( V_110 ) ;
}
void F_88 ( struct V_3 * V_4 )
{
F_39 ( & V_67 ) ;
F_89 ( V_4 ) ;
F_56 ( & V_67 ) ;
}
void F_89 ( struct V_3 * V_4 )
{
-- V_4 -> V_70 ;
F_38 ( V_4 -> V_70 < 0 ) ;
if ( V_4 -> V_119 )
V_4 -> V_119 ( V_4 ) ;
F_64 ( V_4 -> V_101 ) ;
}
int F_90 ( struct V_3 * V_4 , struct V_120 * V_121 )
{
if ( V_121 -> V_122 >= V_4 -> V_22 || V_121 -> V_123 > V_4 -> V_22 - V_121 -> V_122 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
V_121 -> V_125 = V_126 ;
if ( ! V_121 -> V_123 ) {
V_121 -> V_48 = V_127 ;
F_91 ( V_121 ) ;
return 0 ;
}
F_92 () ;
return V_4 -> V_128 ( V_4 , V_121 ) ;
}
int F_93 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 , T_3 * V_130 ,
void * * V_131 , T_5 * V_132 )
{
* V_130 = 0 ;
* V_131 = NULL ;
if ( V_132 )
* V_132 = 0 ;
if ( ! V_4 -> V_133 )
return - V_77 ;
if ( V_129 < 0 || V_129 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_129 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_133 ( V_4 , V_129 , V_123 , V_130 , V_131 , V_132 ) ;
}
int F_94 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 )
{
if ( ! V_4 -> V_134 )
return - V_77 ;
if ( V_129 < 0 || V_129 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_129 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_134 ( V_4 , V_129 , V_123 ) ;
}
unsigned long F_95 ( struct V_3 * V_4 , unsigned long V_123 ,
unsigned long V_135 , unsigned long V_21 )
{
if ( ! V_4 -> V_136 )
return - V_77 ;
if ( V_135 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_135 )
return - V_57 ;
return V_4 -> V_136 ( V_4 , V_123 , V_135 , V_21 ) ;
}
int F_96 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 , T_3 * V_130 ,
T_6 * V_11 )
{
int V_137 ;
* V_130 = 0 ;
if ( V_129 < 0 || V_129 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_129 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
F_92 () ;
V_137 = V_4 -> V_138 ( V_4 , V_129 , V_123 , V_130 , V_11 ) ;
if ( F_97 ( V_137 < 0 ) )
return V_137 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_137 >= V_4 -> V_31 ? - V_139 : 0 ;
}
int F_98 ( struct V_3 * V_4 , T_4 V_140 , T_3 V_123 , T_3 * V_130 ,
const T_6 * V_11 )
{
* V_130 = 0 ;
if ( V_140 < 0 || V_140 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_140 )
return - V_57 ;
if ( ! V_4 -> V_141 || ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
if ( ! V_123 )
return 0 ;
F_92 () ;
return V_4 -> V_141 ( V_4 , V_140 , V_123 , V_130 , V_11 ) ;
}
int F_99 ( struct V_3 * V_4 , T_4 V_140 , T_3 V_123 , T_3 * V_130 ,
const T_6 * V_11 )
{
* V_130 = 0 ;
if ( ! V_4 -> V_142 )
return - V_77 ;
if ( V_140 < 0 || V_140 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_140 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_142 ( V_4 , V_140 , V_123 , V_130 , V_11 ) ;
}
int F_100 ( struct V_3 * V_4 , T_4 V_129 , struct V_143 * V_144 )
{
int V_137 ;
V_144 -> V_130 = V_144 -> V_145 = 0 ;
if ( ! V_4 -> V_146 )
return - V_77 ;
F_92 () ;
V_137 = V_4 -> V_146 ( V_4 , V_129 , V_144 ) ;
if ( F_97 ( V_137 < 0 ) )
return V_137 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_137 >= V_4 -> V_31 ? - V_139 : 0 ;
}
int F_101 ( struct V_3 * V_4 , T_4 V_140 ,
struct V_143 * V_144 )
{
V_144 -> V_130 = V_144 -> V_145 = 0 ;
if ( ! V_4 -> V_147 )
return - V_77 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
F_92 () ;
return V_4 -> V_147 ( V_4 , V_140 , V_144 ) ;
}
int F_102 ( struct V_3 * V_4 , int V_148 ,
struct V_149 * V_150 )
{
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
if ( ! V_4 || V_148 < 0 )
return - V_57 ;
if ( ! V_4 -> V_151 || ! V_4 -> V_151 -> V_152 )
return - V_153 ;
return V_4 -> V_151 -> V_152 ( V_4 , V_148 , V_150 ) ;
}
int F_103 ( struct V_3 * V_4 , int V_148 ,
struct V_149 * V_154 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
if ( ! V_4 || V_148 < 0 )
return - V_57 ;
if ( ! V_4 -> V_151 || ! V_4 -> V_151 -> free )
return - V_153 ;
return V_4 -> V_151 -> free ( V_4 , V_148 , V_154 ) ;
}
static int F_104 ( struct V_3 * V_4 , int V_155 ,
int * V_156 , struct V_149 * V_157 ,
int (* F_105)( struct V_3 * ,
int V_148 ,
struct V_149 * V_157 ) )
{
int V_158 = 0 , V_89 , V_148 = 0 ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
while ( 1 ) {
V_89 = F_105 ( V_4 , V_148 , V_157 ) ;
if ( V_89 )
return V_89 ;
if ( V_158 + V_157 -> V_159 > V_155 )
break;
V_158 += V_157 -> V_159 ;
V_148 ++ ;
}
V_157 -> V_135 += V_155 - V_158 ;
V_157 -> V_159 -= V_155 - V_158 ;
* V_156 = V_148 ;
return 0 ;
}
int F_106 ( struct V_3 * V_4 , int V_160 ,
int * V_148 ,
struct V_149 * V_157 )
{
return F_104 ( V_4 , V_160 , V_148 , V_157 ,
F_102 ) ;
}
static int F_107 ( struct V_3 * V_4 , T_7 * V_11 ,
const T_7 * V_161 , int V_162 , int V_163 ,
int (* F_105)( struct V_3 * ,
int V_148 ,
struct V_149 * V_157 ) )
{
struct V_149 V_157 ;
int V_148 , V_89 ;
V_89 = F_104 ( V_4 , V_162 , & V_148 ,
& V_157 , F_105 ) ;
while ( ! V_89 ) {
int V_164 ;
V_164 = F_108 ( int , V_163 , V_157 . V_159 ) ;
memcpy ( V_11 , V_161 + V_157 . V_135 , V_164 ) ;
V_11 += V_164 ;
V_163 -= V_164 ;
if ( ! V_163 )
break;
V_89 = F_105 ( V_4 , ++ V_148 , & V_157 ) ;
}
return V_89 ;
}
static int F_109 ( struct V_3 * V_4 , const T_7 * V_11 ,
T_7 * V_161 , int V_162 , int V_163 ,
int (* F_105)( struct V_3 * ,
int V_148 ,
struct V_149 * V_157 ) )
{
struct V_149 V_157 ;
int V_148 , V_89 ;
V_89 = F_104 ( V_4 , V_162 , & V_148 ,
& V_157 , F_105 ) ;
while ( ! V_89 ) {
int V_164 ;
V_164 = F_108 ( int , V_163 , V_157 . V_159 ) ;
memcpy ( V_161 + V_157 . V_135 , V_11 , V_164 ) ;
V_11 += V_164 ;
V_163 -= V_164 ;
if ( ! V_163 )
break;
V_89 = F_105 ( V_4 , ++ V_148 , & V_157 ) ;
}
return V_89 ;
}
static int F_110 ( struct V_3 * V_4 ,
int (* F_105)( struct V_3 * ,
int V_148 ,
struct V_149 * V_157 ) )
{
struct V_149 V_157 ;
int V_148 = 0 , V_89 , V_163 = 0 ;
while ( 1 ) {
V_89 = F_105 ( V_4 , V_148 ++ , & V_157 ) ;
if ( V_89 ) {
if ( V_89 == - V_165 )
V_89 = V_163 ;
break;
}
V_163 += V_157 . V_159 ;
}
return V_89 ;
}
int F_111 ( struct V_3 * V_4 , T_7 * V_166 ,
const T_7 * V_161 , int V_162 , int V_163 )
{
return F_107 ( V_4 , V_166 , V_161 , V_162 , V_163 ,
F_102 ) ;
}
int F_112 ( struct V_3 * V_4 , const T_7 * V_166 ,
T_7 * V_161 , int V_162 , int V_163 )
{
return F_109 ( V_4 , V_166 , V_161 , V_162 , V_163 ,
F_102 ) ;
}
int F_113 ( struct V_3 * V_4 , T_7 * V_167 ,
const T_7 * V_161 , int V_162 , int V_163 )
{
return F_107 ( V_4 , V_167 , V_161 , V_162 , V_163 ,
F_103 ) ;
}
int F_114 ( struct V_3 * V_4 , const T_7 * V_167 ,
T_7 * V_161 , int V_162 , int V_163 )
{
return F_109 ( V_4 , V_167 , V_161 , V_162 , V_163 ,
F_103 ) ;
}
int F_115 ( struct V_3 * V_4 )
{
return F_110 ( V_4 , F_103 ) ;
}
int F_116 ( struct V_3 * V_4 )
{
return F_110 ( V_4 , F_102 ) ;
}
int F_117 ( struct V_3 * V_4 , T_3 V_123 , T_3 * V_130 ,
struct V_168 * V_11 )
{
if ( ! V_4 -> V_169 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_169 ( V_4 , V_123 , V_130 , V_11 ) ;
}
int F_118 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 ,
T_3 * V_130 , T_6 * V_11 )
{
* V_130 = 0 ;
if ( ! V_4 -> V_170 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_170 ( V_4 , V_129 , V_123 , V_130 , V_11 ) ;
}
int F_119 ( struct V_3 * V_4 , T_3 V_123 , T_3 * V_130 ,
struct V_168 * V_11 )
{
if ( ! V_4 -> V_171 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_171 ( V_4 , V_123 , V_130 , V_11 ) ;
}
int F_120 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 ,
T_3 * V_130 , T_6 * V_11 )
{
* V_130 = 0 ;
if ( ! V_4 -> V_172 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_172 ( V_4 , V_129 , V_123 , V_130 , V_11 ) ;
}
int F_121 ( struct V_3 * V_4 , T_4 V_140 , T_3 V_123 ,
T_3 * V_130 , T_6 * V_11 )
{
int V_89 ;
* V_130 = 0 ;
if ( ! V_4 -> V_173 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
V_89 = V_4 -> V_173 ( V_4 , V_140 , V_123 , V_130 , V_11 ) ;
if ( V_89 )
return V_89 ;
return ( * V_130 ) ? 0 : - V_174 ;
}
int F_122 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_123 )
{
if ( ! V_4 -> V_175 )
return - V_77 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_175 ( V_4 , V_129 , V_123 ) ;
}
int F_123 ( struct V_3 * V_4 , T_4 V_176 , T_8 V_123 )
{
if ( ! V_4 -> V_177 )
return - V_77 ;
if ( V_176 < 0 || V_176 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_176 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_177 ( V_4 , V_176 , V_123 ) ;
}
int F_43 ( struct V_3 * V_4 , T_4 V_176 , T_8 V_123 )
{
if ( ! V_4 -> V_178 )
return - V_77 ;
if ( V_176 < 0 || V_176 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_176 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_178 ( V_4 , V_176 , V_123 ) ;
}
int F_124 ( struct V_3 * V_4 , T_4 V_176 , T_8 V_123 )
{
if ( ! V_4 -> V_179 )
return - V_77 ;
if ( V_176 < 0 || V_176 >= V_4 -> V_22 || V_123 > V_4 -> V_22 - V_176 )
return - V_57 ;
if ( ! V_123 )
return 0 ;
return V_4 -> V_179 ( V_4 , V_176 , V_123 ) ;
}
int F_125 ( struct V_3 * V_4 , T_4 V_176 )
{
if ( V_176 < 0 || V_176 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_180 )
return 0 ;
return V_4 -> V_180 ( V_4 , V_176 ) ;
}
int F_126 ( struct V_3 * V_4 , T_4 V_176 )
{
if ( V_176 < 0 || V_176 >= V_4 -> V_22 )
return - V_57 ;
if ( ! V_4 -> V_181 )
return 0 ;
return V_4 -> V_181 ( V_4 , V_176 ) ;
}
int F_127 ( struct V_3 * V_4 , T_4 V_176 )
{
if ( ! V_4 -> V_182 )
return - V_77 ;
if ( V_176 < 0 || V_176 >= V_4 -> V_22 )
return - V_57 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
return V_4 -> V_182 ( V_4 , V_176 ) ;
}
static int F_128 ( struct V_3 * V_4 , const struct V_183 * V_184 ,
unsigned long V_32 , T_4 V_140 , T_3 * V_130 )
{
unsigned long V_5 ;
T_3 V_185 = 0 , V_186 ;
int V_89 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_184 [ V_5 ] . V_187 )
continue;
V_89 = F_98 ( V_4 , V_140 , V_184 [ V_5 ] . V_187 , & V_186 ,
V_184 [ V_5 ] . V_188 ) ;
V_185 += V_186 ;
if ( V_89 || V_186 != V_184 [ V_5 ] . V_187 )
break;
V_140 += V_184 [ V_5 ] . V_187 ;
}
* V_130 = V_185 ;
return V_89 ;
}
int F_129 ( struct V_3 * V_4 , const struct V_183 * V_184 ,
unsigned long V_32 , T_4 V_140 , T_3 * V_130 )
{
* V_130 = 0 ;
if ( ! ( V_4 -> V_21 & V_75 ) )
return - V_124 ;
if ( ! V_4 -> V_189 )
return F_128 ( V_4 , V_184 , V_32 , V_140 , V_130 ) ;
return V_4 -> V_189 ( V_4 , V_184 , V_32 , V_140 , V_130 ) ;
}
void * F_130 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_9 V_21 = V_190 | V_191 | V_192 ;
T_3 V_193 = F_131 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_194 ;
* V_22 = F_108 ( T_3 , * V_22 , V_195 ) ;
while ( * V_22 > V_193 ) {
V_194 = F_132 ( * V_22 , V_21 ) ;
if ( V_194 )
return V_194 ;
* V_22 >>= 1 ;
* V_22 = F_133 ( * V_22 , V_4 -> V_24 ) ;
}
return F_132 ( * V_22 , V_68 ) ;
}
static int F_134 ( struct V_196 * V_197 , void * V_198 )
{
struct V_3 * V_4 ;
F_135 ( V_197 , L_24 ) ;
F_39 ( & V_67 ) ;
F_80 (mtd) {
F_136 ( V_197 , L_25 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_56 ( & V_67 ) ;
return 0 ;
}
static int F_137 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_138 ( V_200 , F_134 , NULL ) ;
}
static struct V_201 * T_10 F_139 ( char * V_29 )
{
struct V_201 * V_202 ;
int V_89 ;
V_202 = F_140 ( V_68 ) ;
if ( ! V_202 )
return F_84 ( - V_203 ) ;
V_202 -> V_29 = V_29 ;
V_89 = F_141 ( V_202 , L_26 , V_29 ) ;
if ( V_89 )
F_142 ( V_202 ) ;
return V_89 ? F_84 ( V_89 ) : V_202 ;
}
static int T_10 F_143 ( void )
{
int V_89 ;
V_89 = F_144 ( & V_8 ) ;
if ( V_89 )
goto V_204;
V_205 = F_139 ( L_27 ) ;
if ( F_145 ( V_205 ) ) {
V_89 = F_146 ( V_205 ) ;
goto V_206;
}
V_207 = F_147 ( L_27 , 0 , NULL , & V_208 ) ;
V_89 = F_148 () ;
if ( V_89 )
goto V_209;
V_83 = F_51 ( L_27 , NULL ) ;
return 0 ;
V_209:
if ( V_207 )
F_149 ( L_27 , NULL ) ;
F_142 ( V_205 ) ;
V_206:
F_150 ( & V_8 ) ;
V_204:
F_151 ( L_28 , V_89 ) ;
return V_89 ;
}
static void T_11 F_152 ( void )
{
F_61 ( V_83 ) ;
F_153 () ;
if ( V_207 )
F_149 ( L_27 , NULL ) ;
F_150 ( & V_8 ) ;
F_142 ( V_205 ) ;
F_154 ( & V_6 ) ;
}
