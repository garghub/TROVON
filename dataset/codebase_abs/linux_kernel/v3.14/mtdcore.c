struct V_1 * F_1 ( int V_2 )
{
return F_2 ( & V_3 , & V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_1 T_1 * V_6 = F_4 ( V_5 ) ;
T_2 V_7 = F_5 ( V_6 -> V_7 ) ;
if ( V_7 )
F_6 ( & V_8 , V_7 + 1 ) ;
}
static int F_7 ( struct V_4 * V_5 , T_3 V_9 )
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
static T_4 F_11 ( struct V_4 * V_5 ,
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
static T_4 F_12 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_11 , ( unsigned long ) V_6 -> V_22 ) ;
}
static T_4 F_13 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_12 ,
( unsigned long long ) V_6 -> V_23 ) ;
}
static T_4 F_14 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_24 ) ;
}
static T_4 F_15 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_25 ) ;
}
static T_4 F_16 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
unsigned int V_26 = V_6 -> V_25 >> V_6 -> V_27 ;
return snprintf ( V_12 , V_21 , L_14 , V_26 ) ;
}
static T_4 F_17 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_13 , ( unsigned long ) V_6 -> V_28 ) ;
}
static T_4 F_18 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_29 ) ;
}
static T_4 F_19 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_10 , V_6 -> V_30 ) ;
}
static T_4 F_20 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_31 ) ;
}
static T_4 F_21 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_32 ) ;
}
static T_4 F_22 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
const char * V_12 , T_5 V_33 )
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
static T_4 F_24 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_21 , L_14 , V_6 -> V_35 ) ;
}
int F_25 ( struct V_1 * V_6 )
{
struct V_36 * V_37 ;
int V_2 , error ;
if ( ! V_6 -> V_38 ) {
switch ( V_6 -> type ) {
case V_14 :
V_6 -> V_38 = & V_39 ;
break;
case V_15 :
V_6 -> V_38 = & V_40 ;
break;
default:
V_6 -> V_38 = & V_41 ;
break;
}
}
F_26 ( V_6 -> V_25 == 0 ) ;
F_27 ( & V_42 ) ;
V_2 = F_28 ( & V_3 , V_6 , 0 , 0 , V_43 ) ;
if ( V_2 < 0 )
goto V_44;
V_6 -> V_7 = V_2 ;
V_6 -> V_45 = 0 ;
if ( V_6 -> V_32 == 0 )
V_6 -> V_32 = V_6 -> V_31 ;
if ( F_29 ( V_6 -> V_24 ) )
V_6 -> V_46 = F_30 ( V_6 -> V_24 ) - 1 ;
else
V_6 -> V_46 = 0 ;
if ( F_29 ( V_6 -> V_25 ) )
V_6 -> V_47 = F_30 ( V_6 -> V_25 ) - 1 ;
else
V_6 -> V_47 = 0 ;
V_6 -> V_48 = ( 1 << V_6 -> V_46 ) - 1 ;
V_6 -> V_49 = ( 1 << V_6 -> V_47 ) - 1 ;
if ( ( V_6 -> V_22 & V_50 ) && ( V_6 -> V_22 & V_51 ) ) {
error = F_31 ( V_6 , 0 , V_6 -> V_23 ) ;
if ( error && error != - V_52 )
F_32 ( V_53
L_15 ,
V_6 -> V_30 ) ;
}
V_6 -> V_5 . type = & V_54 ;
V_6 -> V_5 . V_55 = & V_8 ;
V_6 -> V_5 . V_56 = F_5 ( V_2 ) ;
F_33 ( & V_6 -> V_5 , L_16 , V_2 ) ;
F_34 ( & V_6 -> V_5 , V_6 ) ;
if ( F_35 ( & V_6 -> V_5 ) != 0 )
goto V_57;
if ( F_5 ( V_2 ) )
F_36 ( & V_8 , V_6 -> V_5 . V_58 ,
F_5 ( V_2 ) + 1 ,
NULL , L_17 , V_2 ) ;
F_37 ( L_18 , V_2 , V_6 -> V_30 ) ;
F_38 (not, &mtd_notifiers, list)
V_37 -> V_59 ( V_6 ) ;
F_39 ( & V_42 ) ;
F_40 ( V_60 ) ;
return 0 ;
V_57:
F_41 ( & V_3 , V_2 ) ;
V_44:
F_39 ( & V_42 ) ;
return 1 ;
}
int F_42 ( struct V_1 * V_6 )
{
int V_61 ;
struct V_36 * V_37 ;
F_27 ( & V_42 ) ;
if ( F_43 ( & V_3 , V_6 -> V_7 ) != V_6 ) {
V_61 = - V_62 ;
goto V_63;
}
F_38 (not, &mtd_notifiers, list)
V_37 -> remove ( V_6 ) ;
if ( V_6 -> V_45 ) {
F_32 ( V_64 L_19 ,
V_6 -> V_7 , V_6 -> V_30 , V_6 -> V_45 ) ;
V_61 = - V_65 ;
} else {
F_44 ( & V_6 -> V_5 ) ;
F_41 ( & V_3 , V_6 -> V_7 ) ;
F_45 ( V_60 ) ;
V_61 = 0 ;
}
V_63:
F_39 ( & V_42 ) ;
return V_61 ;
}
int F_46 ( struct V_1 * V_6 , const char * const * V_66 ,
struct V_67 * V_68 ,
const struct V_69 * V_70 ,
int V_71 )
{
int V_72 ;
struct V_69 * V_73 ;
V_72 = F_47 ( V_6 , V_66 , & V_73 , V_68 ) ;
if ( V_72 <= 0 && V_71 && V_70 ) {
V_73 = F_48 ( V_70 , sizeof( * V_70 ) * V_71 ,
V_43 ) ;
if ( ! V_73 )
V_72 = - V_74 ;
else
V_72 = V_71 ;
}
if ( V_72 > 0 ) {
V_72 = F_49 ( V_6 , V_73 , V_72 ) ;
F_50 ( V_73 ) ;
} else if ( V_72 == 0 ) {
V_72 = F_25 ( V_6 ) ;
if ( V_72 == 1 )
V_72 = - V_62 ;
}
return V_72 ;
}
int F_51 ( struct V_1 * V_75 )
{
int V_72 ;
V_72 = F_52 ( V_75 ) ;
if ( V_72 )
return V_72 ;
if ( ! F_53 ( & V_75 -> V_5 ) )
return 0 ;
return F_42 ( V_75 ) ;
}
void F_54 ( struct V_36 * V_76 )
{
struct V_1 * V_6 ;
F_27 ( & V_42 ) ;
F_55 ( & V_76 -> V_77 , & V_78 ) ;
F_40 ( V_60 ) ;
F_56 (mtd)
V_76 -> V_59 ( V_6 ) ;
F_39 ( & V_42 ) ;
}
int F_57 ( struct V_36 * V_79 )
{
struct V_1 * V_6 ;
F_27 ( & V_42 ) ;
F_45 ( V_60 ) ;
F_56 (mtd)
V_79 -> remove ( V_6 ) ;
F_58 ( & V_79 -> V_77 ) ;
F_39 ( & V_42 ) ;
return 0 ;
}
struct V_1 * F_59 ( struct V_1 * V_6 , int V_80 )
{
struct V_1 * V_61 = NULL , * V_81 ;
int V_72 = - V_62 ;
F_27 ( & V_42 ) ;
if ( V_80 == - 1 ) {
F_56 (other) {
if ( V_81 == V_6 ) {
V_61 = V_6 ;
break;
}
}
} else if ( V_80 >= 0 ) {
V_61 = F_43 ( & V_3 , V_80 ) ;
if ( V_6 && V_6 != V_61 )
V_61 = NULL ;
}
if ( ! V_61 ) {
V_61 = F_60 ( V_72 ) ;
goto V_82;
}
V_72 = F_61 ( V_61 ) ;
if ( V_72 )
V_61 = F_60 ( V_72 ) ;
V_82:
F_39 ( & V_42 ) ;
return V_61 ;
}
int F_61 ( struct V_1 * V_6 )
{
int V_72 ;
if ( ! F_62 ( V_6 -> V_83 ) )
return - V_62 ;
if ( V_6 -> V_84 ) {
V_72 = V_6 -> V_84 ( V_6 ) ;
if ( V_72 ) {
F_45 ( V_6 -> V_83 ) ;
return V_72 ;
}
}
V_6 -> V_45 ++ ;
return 0 ;
}
struct V_1 * F_63 ( const char * V_30 )
{
int V_72 = - V_62 ;
struct V_1 * V_6 = NULL , * V_81 ;
F_27 ( & V_42 ) ;
F_56 (other) {
if ( ! strcmp ( V_30 , V_81 -> V_30 ) ) {
V_6 = V_81 ;
break;
}
}
if ( ! V_6 )
goto V_85;
V_72 = F_61 ( V_6 ) ;
if ( V_72 )
goto V_85;
F_39 ( & V_42 ) ;
return V_6 ;
V_85:
F_39 ( & V_42 ) ;
return F_60 ( V_72 ) ;
}
void F_64 ( struct V_1 * V_6 )
{
F_27 ( & V_42 ) ;
F_65 ( V_6 ) ;
F_39 ( & V_42 ) ;
}
void F_65 ( struct V_1 * V_6 )
{
-- V_6 -> V_45 ;
F_26 ( V_6 -> V_45 < 0 ) ;
if ( V_6 -> V_86 )
V_6 -> V_86 ( V_6 ) ;
F_45 ( V_6 -> V_83 ) ;
}
int F_66 ( struct V_1 * V_6 , struct V_87 * V_88 )
{
if ( V_88 -> V_89 > V_6 -> V_23 || V_88 -> V_90 > V_6 -> V_23 - V_88 -> V_89 )
return - V_91 ;
if ( ! ( V_6 -> V_22 & V_50 ) )
return - V_92 ;
V_88 -> V_93 = V_94 ;
if ( ! V_88 -> V_90 ) {
V_88 -> V_9 = V_95 ;
F_67 ( V_88 ) ;
return 0 ;
}
return V_6 -> V_96 ( V_6 , V_88 ) ;
}
int F_68 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 , T_5 * V_98 ,
void * * V_99 , T_7 * V_100 )
{
* V_98 = 0 ;
* V_99 = NULL ;
if ( V_100 )
* V_100 = 0 ;
if ( ! V_6 -> V_101 )
return - V_52 ;
if ( V_97 < 0 || V_97 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_97 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_101 ( V_6 , V_97 , V_90 , V_98 , V_99 , V_100 ) ;
}
int F_69 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 )
{
if ( ! V_6 -> V_101 )
return - V_52 ;
if ( V_97 < 0 || V_97 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_97 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_102 ( V_6 , V_97 , V_90 ) ;
}
unsigned long F_70 ( struct V_1 * V_6 , unsigned long V_90 ,
unsigned long V_103 , unsigned long V_22 )
{
if ( ! V_6 -> V_104 )
return - V_52 ;
if ( V_103 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_103 )
return - V_91 ;
return V_6 -> V_104 ( V_6 , V_90 , V_103 , V_22 ) ;
}
int F_71 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 , T_5 * V_98 ,
T_8 * V_12 )
{
int V_105 ;
* V_98 = 0 ;
if ( V_97 < 0 || V_97 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_97 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
V_105 = V_6 -> V_106 ( V_6 , V_97 , V_90 , V_98 , V_12 ) ;
if ( F_72 ( V_105 < 0 ) )
return V_105 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_105 >= V_6 -> V_32 ? - V_107 : 0 ;
}
int F_73 ( struct V_1 * V_6 , T_6 V_108 , T_5 V_90 , T_5 * V_98 ,
const T_8 * V_12 )
{
* V_98 = 0 ;
if ( V_108 < 0 || V_108 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_108 )
return - V_91 ;
if ( ! V_6 -> V_109 || ! ( V_6 -> V_22 & V_50 ) )
return - V_92 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_109 ( V_6 , V_108 , V_90 , V_98 , V_12 ) ;
}
int F_74 ( struct V_1 * V_6 , T_6 V_108 , T_5 V_90 , T_5 * V_98 ,
const T_8 * V_12 )
{
* V_98 = 0 ;
if ( ! V_6 -> V_110 )
return - V_52 ;
if ( V_108 < 0 || V_108 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_108 )
return - V_91 ;
if ( ! ( V_6 -> V_22 & V_50 ) )
return - V_92 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_110 ( V_6 , V_108 , V_90 , V_98 , V_12 ) ;
}
int F_75 ( struct V_1 * V_6 , T_6 V_97 , struct V_111 * V_112 )
{
int V_105 ;
V_112 -> V_98 = V_112 -> V_113 = 0 ;
if ( ! V_6 -> V_114 )
return - V_52 ;
V_105 = V_6 -> V_114 ( V_6 , V_97 , V_112 ) ;
if ( F_72 ( V_105 < 0 ) )
return V_105 ;
if ( V_6 -> V_31 == 0 )
return 0 ;
return V_105 >= V_6 -> V_32 ? - V_107 : 0 ;
}
int F_76 ( struct V_1 * V_6 , struct V_115 * V_12 ,
T_5 V_90 )
{
if ( ! V_6 -> V_116 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_116 ( V_6 , V_12 , V_90 ) ;
}
int F_77 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 ,
T_5 * V_98 , T_8 * V_12 )
{
* V_98 = 0 ;
if ( ! V_6 -> V_117 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_117 ( V_6 , V_97 , V_90 , V_98 , V_12 ) ;
}
int F_78 ( struct V_1 * V_6 , struct V_115 * V_12 ,
T_5 V_90 )
{
if ( ! V_6 -> V_118 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_118 ( V_6 , V_12 , V_90 ) ;
}
int F_79 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 ,
T_5 * V_98 , T_8 * V_12 )
{
* V_98 = 0 ;
if ( ! V_6 -> V_119 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_119 ( V_6 , V_97 , V_90 , V_98 , V_12 ) ;
}
int F_80 ( struct V_1 * V_6 , T_6 V_108 , T_5 V_90 ,
T_5 * V_98 , T_8 * V_12 )
{
* V_98 = 0 ;
if ( ! V_6 -> V_120 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_120 ( V_6 , V_108 , V_90 , V_98 , V_12 ) ;
}
int F_81 ( struct V_1 * V_6 , T_6 V_97 , T_5 V_90 )
{
if ( ! V_6 -> V_121 )
return - V_52 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_121 ( V_6 , V_97 , V_90 ) ;
}
int F_82 ( struct V_1 * V_6 , T_6 V_122 , T_9 V_90 )
{
if ( ! V_6 -> V_123 )
return - V_52 ;
if ( V_122 < 0 || V_122 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_122 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_123 ( V_6 , V_122 , V_90 ) ;
}
int F_31 ( struct V_1 * V_6 , T_6 V_122 , T_9 V_90 )
{
if ( ! V_6 -> V_124 )
return - V_52 ;
if ( V_122 < 0 || V_122 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_122 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_124 ( V_6 , V_122 , V_90 ) ;
}
int F_83 ( struct V_1 * V_6 , T_6 V_122 , T_9 V_90 )
{
if ( ! V_6 -> V_125 )
return - V_52 ;
if ( V_122 < 0 || V_122 > V_6 -> V_23 || V_90 > V_6 -> V_23 - V_122 )
return - V_91 ;
if ( ! V_90 )
return 0 ;
return V_6 -> V_125 ( V_6 , V_122 , V_90 ) ;
}
int F_84 ( struct V_1 * V_6 , T_6 V_122 )
{
if ( ! V_6 -> V_126 )
return 0 ;
if ( V_122 < 0 || V_122 > V_6 -> V_23 )
return - V_91 ;
return V_6 -> V_126 ( V_6 , V_122 ) ;
}
int F_85 ( struct V_1 * V_6 , T_6 V_122 )
{
if ( ! V_6 -> V_127 )
return - V_52 ;
if ( V_122 < 0 || V_122 > V_6 -> V_23 )
return - V_91 ;
if ( ! ( V_6 -> V_22 & V_50 ) )
return - V_92 ;
return V_6 -> V_127 ( V_6 , V_122 ) ;
}
static int F_86 ( struct V_1 * V_6 , const struct V_128 * V_129 ,
unsigned long V_33 , T_6 V_108 , T_5 * V_98 )
{
unsigned long V_2 ;
T_5 V_130 = 0 , V_131 ;
int V_61 = 0 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ ) {
if ( ! V_129 [ V_2 ] . V_132 )
continue;
V_61 = F_73 ( V_6 , V_108 , V_129 [ V_2 ] . V_132 , & V_131 ,
V_129 [ V_2 ] . V_133 ) ;
V_130 += V_131 ;
if ( V_61 || V_131 != V_129 [ V_2 ] . V_132 )
break;
V_108 += V_129 [ V_2 ] . V_132 ;
}
* V_98 = V_130 ;
return V_61 ;
}
int F_87 ( struct V_1 * V_6 , const struct V_128 * V_129 ,
unsigned long V_33 , T_6 V_108 , T_5 * V_98 )
{
* V_98 = 0 ;
if ( ! ( V_6 -> V_22 & V_50 ) )
return - V_92 ;
if ( ! V_6 -> V_134 )
return F_86 ( V_6 , V_129 , V_33 , V_108 , V_98 ) ;
return V_6 -> V_134 ( V_6 , V_129 , V_33 , V_108 , V_98 ) ;
}
void * F_88 ( const struct V_1 * V_6 , T_5 * V_23 )
{
T_10 V_22 = V_135 | V_136 |
V_137 | V_138 ;
T_5 V_139 = F_89 ( T_5 , V_6 -> V_25 , V_21 ) ;
void * V_140 ;
* V_23 = F_90 ( T_5 , * V_23 , V_141 ) ;
while ( * V_23 > V_139 ) {
V_140 = F_91 ( * V_23 , V_22 ) ;
if ( V_140 )
return V_140 ;
* V_23 >>= 1 ;
* V_23 = F_92 ( * V_23 , V_6 -> V_25 ) ;
}
return F_91 ( * V_23 , V_43 ) ;
}
static int F_93 ( struct V_142 * V_143 , void * V_144 )
{
struct V_1 * V_6 ;
F_94 ( V_143 , L_20 ) ;
F_27 ( & V_42 ) ;
F_56 (mtd) {
F_95 ( V_143 , L_21 ,
V_6 -> V_7 , ( unsigned long long ) V_6 -> V_23 ,
V_6 -> V_24 , V_6 -> V_30 ) ;
}
F_39 ( & V_42 ) ;
return 0 ;
}
static int F_96 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
return F_97 ( V_146 , F_93 , NULL ) ;
}
static int T_11 F_98 ( struct V_38 * V_147 , const char * V_30 )
{
int V_61 ;
V_61 = F_99 ( V_147 ) ;
if ( ! V_61 )
V_61 = F_100 ( V_147 , NULL , L_22 , V_30 ) ;
if ( V_61 )
F_101 ( V_147 ) ;
return V_61 ;
}
static int T_11 F_102 ( void )
{
int V_61 ;
V_61 = F_103 ( & V_8 ) ;
if ( V_61 )
goto V_148;
V_61 = F_98 ( & V_41 , L_23 ) ;
if ( V_61 )
goto V_149;
V_61 = F_98 ( & V_40 , L_24 ) ;
if ( V_61 )
goto V_150;
V_61 = F_98 ( & V_39 , L_25 ) ;
if ( V_61 )
goto V_151;
V_152 = F_104 ( L_26 , 0 , NULL , & V_153 ) ;
V_61 = F_105 () ;
if ( V_61 )
goto V_154;
return 0 ;
V_154:
if ( V_152 )
F_106 ( L_26 , NULL ) ;
V_151:
F_101 ( & V_40 ) ;
V_150:
F_101 ( & V_41 ) ;
V_149:
F_107 ( & V_8 ) ;
V_148:
F_108 ( L_27 , V_61 ) ;
return V_61 ;
}
static void T_12 F_109 ( void )
{
F_110 () ;
if ( V_152 )
F_106 ( L_26 , NULL ) ;
F_107 ( & V_8 ) ;
F_101 ( & V_41 ) ;
F_101 ( & V_40 ) ;
F_101 ( & V_39 ) ;
}
