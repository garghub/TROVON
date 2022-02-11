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
F_43 ( F_44 ( V_4 ) ) ;
error = F_45 ( & V_4 -> V_2 ) ;
if ( error )
goto V_73;
F_46 ( & V_8 , V_4 -> V_2 . V_74 , F_9 ( V_5 ) + 1 , NULL ,
L_18 , V_5 ) ;
F_47 ( L_19 , V_5 , V_4 -> V_29 ) ;
F_48 (not, &mtd_notifiers, list)
V_54 -> V_75 ( V_4 ) ;
F_49 ( & V_58 ) ;
F_50 ( V_76 ) ;
return 0 ;
V_73:
F_51 ( F_44 ( V_4 ) ) ;
F_52 ( & V_6 , V_5 ) ;
V_60:
F_49 ( & V_58 ) ;
return error ;
}
int F_53 ( struct V_3 * V_4 )
{
int V_77 ;
struct V_53 * V_54 ;
F_35 ( & V_58 ) ;
if ( F_54 ( & V_6 , V_4 -> V_7 ) != V_4 ) {
V_77 = - V_78 ;
goto V_79;
}
F_48 (not, &mtd_notifiers, list)
V_54 -> remove ( V_4 ) ;
if ( V_4 -> V_61 ) {
F_40 ( V_80 L_20 ,
V_4 -> V_7 , V_4 -> V_29 , V_4 -> V_61 ) ;
V_77 = - V_81 ;
} else {
F_55 ( & V_4 -> V_2 ) ;
F_52 ( & V_6 , V_4 -> V_7 ) ;
F_51 ( F_44 ( V_4 ) ) ;
F_56 ( V_76 ) ;
V_77 = 0 ;
}
V_79:
F_49 ( & V_58 ) ;
return V_77 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_82 * V_83 )
{
const struct V_84 * V_85 = V_83 -> V_83 ;
int V_86 = V_83 -> V_87 ;
int V_77 ;
if ( V_86 == 0 || F_58 ( V_88 ) ) {
V_77 = F_32 ( V_4 ) ;
if ( V_77 )
return V_77 ;
}
if ( V_86 > 0 ) {
V_77 = F_59 ( V_4 , V_85 , V_86 ) ;
if ( V_77 && F_58 ( V_88 ) )
F_53 ( V_4 ) ;
return V_77 ;
}
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_74 ) {
if ( ! V_4 -> V_89 && V_4 -> V_2 . V_74 -> V_90 )
V_4 -> V_89 = V_4 -> V_2 . V_74 -> V_90 -> V_89 ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 = F_61 ( V_4 -> V_2 . V_74 ) ;
} else {
F_47 ( L_21 ) ;
}
}
int F_62 ( struct V_3 * V_4 , const char * const * V_91 ,
struct V_92 * V_93 ,
const struct V_84 * V_83 ,
int V_87 )
{
struct V_82 V_94 ;
int V_77 ;
F_60 ( V_4 ) ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_77 = F_63 ( V_4 , V_91 , & V_94 , V_93 ) ;
if ( ( V_77 < 0 || V_94 . V_87 == 0 ) && V_83 && V_87 ) {
V_94 = (struct V_82 ) {
. V_83 = V_83 ,
. V_87 = V_87 ,
} ;
} else if ( V_77 < 0 ) {
F_64 ( L_22 ,
V_77 ) ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
}
V_77 = F_57 ( V_4 , & V_94 ) ;
if ( V_77 )
goto V_95;
F_33 ( V_4 -> V_51 && V_4 -> V_50 . V_96 ,
L_15 ) ;
if ( V_4 -> V_51 && ! V_4 -> V_50 . V_96 ) {
V_4 -> V_50 . V_96 = F_30 ;
F_65 ( & V_4 -> V_50 ) ;
}
V_95:
F_66 ( & V_94 ) ;
return V_77 ;
}
int F_67 ( struct V_3 * V_97 )
{
int V_98 ;
if ( V_97 -> V_51 )
F_68 ( & V_97 -> V_50 ) ;
V_98 = F_69 ( V_97 ) ;
if ( V_98 )
return V_98 ;
if ( ! F_70 ( & V_97 -> V_2 ) )
return 0 ;
return F_53 ( V_97 ) ;
}
void F_71 ( struct V_53 * V_99 )
{
struct V_3 * V_4 ;
F_35 ( & V_58 ) ;
F_72 ( & V_99 -> V_100 , & V_101 ) ;
F_50 ( V_76 ) ;
F_73 (mtd)
V_99 -> V_75 ( V_4 ) ;
F_49 ( & V_58 ) ;
}
int F_74 ( struct V_53 * V_102 )
{
struct V_3 * V_4 ;
F_35 ( & V_58 ) ;
F_56 ( V_76 ) ;
F_73 (mtd)
V_102 -> remove ( V_4 ) ;
F_75 ( & V_102 -> V_100 ) ;
F_49 ( & V_58 ) ;
return 0 ;
}
struct V_3 * F_76 ( struct V_3 * V_4 , int V_103 )
{
struct V_3 * V_77 = NULL , * V_104 ;
int V_98 = - V_78 ;
F_35 ( & V_58 ) ;
if ( V_103 == - 1 ) {
F_73 (other) {
if ( V_104 == V_4 ) {
V_77 = V_4 ;
break;
}
}
} else if ( V_103 >= 0 ) {
V_77 = F_54 ( & V_6 , V_103 ) ;
if ( V_4 && V_4 != V_77 )
V_77 = NULL ;
}
if ( ! V_77 ) {
V_77 = F_77 ( V_98 ) ;
goto V_95;
}
V_98 = F_78 ( V_77 ) ;
if ( V_98 )
V_77 = F_77 ( V_98 ) ;
V_95:
F_49 ( & V_58 ) ;
return V_77 ;
}
int F_78 ( struct V_3 * V_4 )
{
int V_98 ;
if ( ! F_79 ( V_4 -> V_89 ) )
return - V_78 ;
if ( V_4 -> V_105 ) {
V_98 = V_4 -> V_105 ( V_4 ) ;
if ( V_98 ) {
F_56 ( V_4 -> V_89 ) ;
return V_98 ;
}
}
V_4 -> V_61 ++ ;
return 0 ;
}
struct V_3 * F_80 ( const char * V_29 )
{
int V_98 = - V_78 ;
struct V_3 * V_4 = NULL , * V_104 ;
F_35 ( & V_58 ) ;
F_73 (other) {
if ( ! strcmp ( V_29 , V_104 -> V_29 ) ) {
V_4 = V_104 ;
break;
}
}
if ( ! V_4 )
goto V_106;
V_98 = F_78 ( V_4 ) ;
if ( V_98 )
goto V_106;
F_49 ( & V_58 ) ;
return V_4 ;
V_106:
F_49 ( & V_58 ) ;
return F_77 ( V_98 ) ;
}
void F_81 ( struct V_3 * V_4 )
{
F_35 ( & V_58 ) ;
F_82 ( V_4 ) ;
F_49 ( & V_58 ) ;
}
void F_82 ( struct V_3 * V_4 )
{
-- V_4 -> V_61 ;
F_34 ( V_4 -> V_61 < 0 ) ;
if ( V_4 -> V_107 )
V_4 -> V_107 ( V_4 ) ;
F_56 ( V_4 -> V_89 ) ;
}
int F_83 ( struct V_3 * V_4 , struct V_108 * V_109 )
{
if ( V_109 -> V_110 >= V_4 -> V_22 || V_109 -> V_111 > V_4 -> V_22 - V_109 -> V_110 )
return - V_112 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
V_109 -> V_114 = V_115 ;
if ( ! V_109 -> V_111 ) {
V_109 -> V_48 = V_116 ;
F_84 ( V_109 ) ;
return 0 ;
}
F_85 () ;
return V_4 -> V_117 ( V_4 , V_109 ) ;
}
int F_86 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 , T_3 * V_119 ,
void * * V_120 , T_5 * V_121 )
{
* V_119 = 0 ;
* V_120 = NULL ;
if ( V_121 )
* V_121 = 0 ;
if ( ! V_4 -> V_122 )
return - V_68 ;
if ( V_118 < 0 || V_118 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_118 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_122 ( V_4 , V_118 , V_111 , V_119 , V_120 , V_121 ) ;
}
int F_87 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 )
{
if ( ! V_4 -> V_122 )
return - V_68 ;
if ( V_118 < 0 || V_118 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_118 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_123 ( V_4 , V_118 , V_111 ) ;
}
unsigned long F_88 ( struct V_3 * V_4 , unsigned long V_111 ,
unsigned long V_124 , unsigned long V_21 )
{
if ( ! V_4 -> V_125 )
return - V_68 ;
if ( V_124 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_124 )
return - V_112 ;
return V_4 -> V_125 ( V_4 , V_111 , V_124 , V_21 ) ;
}
int F_89 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 , T_3 * V_119 ,
T_6 * V_11 )
{
int V_126 ;
* V_119 = 0 ;
if ( V_118 < 0 || V_118 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_118 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
F_85 () ;
V_126 = V_4 -> V_127 ( V_4 , V_118 , V_111 , V_119 , V_11 ) ;
if ( F_90 ( V_126 < 0 ) )
return V_126 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_126 >= V_4 -> V_31 ? - V_128 : 0 ;
}
int F_91 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_111 , T_3 * V_119 ,
const T_6 * V_11 )
{
* V_119 = 0 ;
if ( V_129 < 0 || V_129 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_129 )
return - V_112 ;
if ( ! V_4 -> V_130 || ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
if ( ! V_111 )
return 0 ;
F_85 () ;
return V_4 -> V_130 ( V_4 , V_129 , V_111 , V_119 , V_11 ) ;
}
int F_92 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_111 , T_3 * V_119 ,
const T_6 * V_11 )
{
* V_119 = 0 ;
if ( ! V_4 -> V_131 )
return - V_68 ;
if ( V_129 < 0 || V_129 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_129 )
return - V_112 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_131 ( V_4 , V_129 , V_111 , V_119 , V_11 ) ;
}
int F_93 ( struct V_3 * V_4 , T_4 V_118 , struct V_132 * V_133 )
{
int V_126 ;
V_133 -> V_119 = V_133 -> V_134 = 0 ;
if ( ! V_4 -> V_135 )
return - V_68 ;
F_85 () ;
V_126 = V_4 -> V_135 ( V_4 , V_118 , V_133 ) ;
if ( F_90 ( V_126 < 0 ) )
return V_126 ;
if ( V_4 -> V_30 == 0 )
return 0 ;
return V_126 >= V_4 -> V_31 ? - V_128 : 0 ;
}
int F_94 ( struct V_3 * V_4 , T_4 V_129 ,
struct V_132 * V_133 )
{
V_133 -> V_119 = V_133 -> V_134 = 0 ;
if ( ! V_4 -> V_136 )
return - V_68 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
F_85 () ;
return V_4 -> V_136 ( V_4 , V_129 , V_133 ) ;
}
int F_95 ( struct V_3 * V_4 , int V_137 ,
struct V_138 * V_139 )
{
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
if ( ! V_4 || V_137 < 0 )
return - V_112 ;
if ( ! V_4 -> V_140 || ! V_4 -> V_140 -> V_141 )
return - V_142 ;
return V_4 -> V_140 -> V_141 ( V_4 , V_137 , V_139 ) ;
}
int F_96 ( struct V_3 * V_4 , int V_137 ,
struct V_138 * V_143 )
{
memset ( V_143 , 0 , sizeof( * V_143 ) ) ;
if ( ! V_4 || V_137 < 0 )
return - V_112 ;
if ( ! V_4 -> V_140 || ! V_4 -> V_140 -> free )
return - V_142 ;
return V_4 -> V_140 -> free ( V_4 , V_137 , V_143 ) ;
}
static int F_97 ( struct V_3 * V_4 , int V_144 ,
int * V_145 , struct V_138 * V_146 ,
int (* F_98)( struct V_3 * ,
int V_137 ,
struct V_138 * V_146 ) )
{
int V_147 = 0 , V_77 , V_137 = 0 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
while ( 1 ) {
V_77 = F_98 ( V_4 , V_137 , V_146 ) ;
if ( V_77 )
return V_77 ;
if ( V_147 + V_146 -> V_148 > V_144 )
break;
V_147 += V_146 -> V_148 ;
V_137 ++ ;
}
V_146 -> V_124 += V_144 - V_147 ;
V_146 -> V_148 -= V_144 - V_147 ;
* V_145 = V_137 ;
return 0 ;
}
int F_99 ( struct V_3 * V_4 , int V_149 ,
int * V_137 ,
struct V_138 * V_146 )
{
return F_97 ( V_4 , V_149 , V_137 , V_146 ,
F_95 ) ;
}
static int F_100 ( struct V_3 * V_4 , T_7 * V_11 ,
const T_7 * V_150 , int V_151 , int V_152 ,
int (* F_98)( struct V_3 * ,
int V_137 ,
struct V_138 * V_146 ) )
{
struct V_138 V_146 = { } ;
int V_137 = 0 , V_77 ;
V_77 = F_97 ( V_4 , V_151 , & V_137 ,
& V_146 , F_98 ) ;
while ( ! V_77 ) {
int V_153 ;
V_153 = V_146 . V_148 > V_152 ? V_152 : V_146 . V_148 ;
memcpy ( V_11 , V_150 + V_146 . V_124 , V_153 ) ;
V_11 += V_153 ;
V_152 -= V_153 ;
if ( ! V_152 )
break;
V_77 = F_98 ( V_4 , ++ V_137 , & V_146 ) ;
}
return V_77 ;
}
static int F_101 ( struct V_3 * V_4 , const T_7 * V_11 ,
T_7 * V_150 , int V_151 , int V_152 ,
int (* F_98)( struct V_3 * ,
int V_137 ,
struct V_138 * V_146 ) )
{
struct V_138 V_146 = { } ;
int V_137 = 0 , V_77 ;
V_77 = F_97 ( V_4 , V_151 , & V_137 ,
& V_146 , F_98 ) ;
while ( ! V_77 ) {
int V_153 ;
V_153 = V_146 . V_148 > V_152 ? V_152 : V_146 . V_148 ;
memcpy ( V_150 + V_146 . V_124 , V_11 , V_153 ) ;
V_11 += V_153 ;
V_152 -= V_153 ;
if ( ! V_152 )
break;
V_77 = F_98 ( V_4 , ++ V_137 , & V_146 ) ;
}
return V_77 ;
}
static int F_102 ( struct V_3 * V_4 ,
int (* F_98)( struct V_3 * ,
int V_137 ,
struct V_138 * V_146 ) )
{
struct V_138 V_146 = { } ;
int V_137 = 0 , V_77 , V_152 = 0 ;
while ( 1 ) {
V_77 = F_98 ( V_4 , V_137 ++ , & V_146 ) ;
if ( V_77 ) {
if ( V_77 == - V_154 )
V_77 = V_152 ;
break;
}
V_152 += V_146 . V_148 ;
}
return V_77 ;
}
int F_103 ( struct V_3 * V_4 , T_7 * V_155 ,
const T_7 * V_150 , int V_151 , int V_152 )
{
return F_100 ( V_4 , V_155 , V_150 , V_151 , V_152 ,
F_95 ) ;
}
int F_104 ( struct V_3 * V_4 , const T_7 * V_155 ,
T_7 * V_150 , int V_151 , int V_152 )
{
return F_101 ( V_4 , V_155 , V_150 , V_151 , V_152 ,
F_95 ) ;
}
int F_105 ( struct V_3 * V_4 , T_7 * V_156 ,
const T_7 * V_150 , int V_151 , int V_152 )
{
return F_100 ( V_4 , V_156 , V_150 , V_151 , V_152 ,
F_96 ) ;
}
int F_106 ( struct V_3 * V_4 , const T_7 * V_156 ,
T_7 * V_150 , int V_151 , int V_152 )
{
return F_101 ( V_4 , V_156 , V_150 , V_151 , V_152 ,
F_96 ) ;
}
int F_107 ( struct V_3 * V_4 )
{
return F_102 ( V_4 , F_96 ) ;
}
int F_108 ( struct V_3 * V_4 )
{
return F_102 ( V_4 , F_95 ) ;
}
int F_109 ( struct V_3 * V_4 , T_3 V_111 , T_3 * V_119 ,
struct V_157 * V_11 )
{
if ( ! V_4 -> V_158 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_158 ( V_4 , V_111 , V_119 , V_11 ) ;
}
int F_110 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 ,
T_3 * V_119 , T_6 * V_11 )
{
* V_119 = 0 ;
if ( ! V_4 -> V_159 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_159 ( V_4 , V_118 , V_111 , V_119 , V_11 ) ;
}
int F_111 ( struct V_3 * V_4 , T_3 V_111 , T_3 * V_119 ,
struct V_157 * V_11 )
{
if ( ! V_4 -> V_160 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_160 ( V_4 , V_111 , V_119 , V_11 ) ;
}
int F_112 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 ,
T_3 * V_119 , T_6 * V_11 )
{
* V_119 = 0 ;
if ( ! V_4 -> V_161 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_161 ( V_4 , V_118 , V_111 , V_119 , V_11 ) ;
}
int F_113 ( struct V_3 * V_4 , T_4 V_129 , T_3 V_111 ,
T_3 * V_119 , T_6 * V_11 )
{
int V_77 ;
* V_119 = 0 ;
if ( ! V_4 -> V_162 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
V_77 = V_4 -> V_162 ( V_4 , V_129 , V_111 , V_119 , V_11 ) ;
if ( V_77 )
return V_77 ;
return ( * V_119 ) ? 0 : - V_163 ;
}
int F_114 ( struct V_3 * V_4 , T_4 V_118 , T_3 V_111 )
{
if ( ! V_4 -> V_164 )
return - V_68 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_164 ( V_4 , V_118 , V_111 ) ;
}
int F_115 ( struct V_3 * V_4 , T_4 V_165 , T_8 V_111 )
{
if ( ! V_4 -> V_166 )
return - V_68 ;
if ( V_165 < 0 || V_165 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_165 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_166 ( V_4 , V_165 , V_111 ) ;
}
int F_39 ( struct V_3 * V_4 , T_4 V_165 , T_8 V_111 )
{
if ( ! V_4 -> V_167 )
return - V_68 ;
if ( V_165 < 0 || V_165 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_165 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_167 ( V_4 , V_165 , V_111 ) ;
}
int F_116 ( struct V_3 * V_4 , T_4 V_165 , T_8 V_111 )
{
if ( ! V_4 -> V_168 )
return - V_68 ;
if ( V_165 < 0 || V_165 >= V_4 -> V_22 || V_111 > V_4 -> V_22 - V_165 )
return - V_112 ;
if ( ! V_111 )
return 0 ;
return V_4 -> V_168 ( V_4 , V_165 , V_111 ) ;
}
int F_117 ( struct V_3 * V_4 , T_4 V_165 )
{
if ( V_165 < 0 || V_165 >= V_4 -> V_22 )
return - V_112 ;
if ( ! V_4 -> V_169 )
return 0 ;
return V_4 -> V_169 ( V_4 , V_165 ) ;
}
int F_118 ( struct V_3 * V_4 , T_4 V_165 )
{
if ( V_165 < 0 || V_165 >= V_4 -> V_22 )
return - V_112 ;
if ( ! V_4 -> V_170 )
return 0 ;
return V_4 -> V_170 ( V_4 , V_165 ) ;
}
int F_119 ( struct V_3 * V_4 , T_4 V_165 )
{
if ( ! V_4 -> V_171 )
return - V_68 ;
if ( V_165 < 0 || V_165 >= V_4 -> V_22 )
return - V_112 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
return V_4 -> V_171 ( V_4 , V_165 ) ;
}
static int F_120 ( struct V_3 * V_4 , const struct V_172 * V_173 ,
unsigned long V_32 , T_4 V_129 , T_3 * V_119 )
{
unsigned long V_5 ;
T_3 V_174 = 0 , V_175 ;
int V_77 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_173 [ V_5 ] . V_176 )
continue;
V_77 = F_91 ( V_4 , V_129 , V_173 [ V_5 ] . V_176 , & V_175 ,
V_173 [ V_5 ] . V_177 ) ;
V_174 += V_175 ;
if ( V_77 || V_175 != V_173 [ V_5 ] . V_176 )
break;
V_129 += V_173 [ V_5 ] . V_176 ;
}
* V_119 = V_174 ;
return V_77 ;
}
int F_121 ( struct V_3 * V_4 , const struct V_172 * V_173 ,
unsigned long V_32 , T_4 V_129 , T_3 * V_119 )
{
* V_119 = 0 ;
if ( ! ( V_4 -> V_21 & V_66 ) )
return - V_113 ;
if ( ! V_4 -> V_178 )
return F_120 ( V_4 , V_173 , V_32 , V_129 , V_119 ) ;
return V_4 -> V_178 ( V_4 , V_173 , V_32 , V_129 , V_119 ) ;
}
void * F_122 ( const struct V_3 * V_4 , T_3 * V_22 )
{
T_9 V_21 = V_179 | V_180 | V_181 ;
T_3 V_182 = F_123 ( T_3 , V_4 -> V_24 , V_20 ) ;
void * V_183 ;
* V_22 = F_124 ( T_3 , * V_22 , V_184 ) ;
while ( * V_22 > V_182 ) {
V_183 = F_125 ( * V_22 , V_21 ) ;
if ( V_183 )
return V_183 ;
* V_22 >>= 1 ;
* V_22 = F_126 ( * V_22 , V_4 -> V_24 ) ;
}
return F_125 ( * V_22 , V_59 ) ;
}
static int F_127 ( struct V_185 * V_186 , void * V_187 )
{
struct V_3 * V_4 ;
F_128 ( V_186 , L_23 ) ;
F_35 ( & V_58 ) ;
F_73 (mtd) {
F_129 ( V_186 , L_24 ,
V_4 -> V_7 , ( unsigned long long ) V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_29 ) ;
}
F_49 ( & V_58 ) ;
return 0 ;
}
static int F_130 ( struct V_188 * V_188 , struct V_189 * V_189 )
{
return F_131 ( V_189 , F_127 , NULL ) ;
}
static int T_10 F_132 ( struct V_55 * V_190 , const char * V_29 )
{
int V_77 ;
V_77 = F_133 ( V_190 ) ;
if ( ! V_77 )
V_77 = F_134 ( V_190 , NULL , L_25 , V_29 ) ;
if ( V_77 )
F_135 ( V_190 ) ;
return V_77 ;
}
static int T_10 F_136 ( void )
{
int V_77 ;
V_77 = F_137 ( & V_8 ) ;
if ( V_77 )
goto V_191;
V_77 = F_132 ( & V_57 , L_26 ) ;
if ( V_77 )
goto V_192;
V_193 = F_138 ( L_26 , 0 , NULL , & V_194 ) ;
V_77 = F_139 () ;
if ( V_77 )
goto V_195;
return 0 ;
V_195:
if ( V_193 )
F_140 ( L_26 , NULL ) ;
V_192:
F_141 ( & V_8 ) ;
V_191:
F_142 ( L_27 , V_77 ) ;
return V_77 ;
}
static void T_11 F_143 ( void )
{
F_144 () ;
if ( V_193 )
F_140 ( L_26 , NULL ) ;
F_141 ( & V_8 ) ;
F_135 ( & V_57 ) ;
F_145 ( & V_6 ) ;
}
