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
default:
type = L_8 ;
}
return snprintf ( V_12 , V_20 , L_9 , type ) ;
}
static T_4 F_12 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_10 , ( unsigned long ) V_6 -> V_21 ) ;
}
static T_4 F_13 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_11 ,
( unsigned long long ) V_6 -> V_22 ) ;
}
static T_4 F_14 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_12 , ( unsigned long ) V_6 -> V_23 ) ;
}
static T_4 F_15 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_12 , ( unsigned long ) V_6 -> V_24 ) ;
}
static T_4 F_16 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
unsigned int V_25 = V_6 -> V_24 >> V_6 -> V_26 ;
return snprintf ( V_12 , V_20 , L_13 , V_25 ) ;
}
static T_4 F_17 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_12 , ( unsigned long ) V_6 -> V_27 ) ;
}
static T_4 F_18 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_13 , V_6 -> V_28 ) ;
}
static T_4 F_19 ( struct V_4 * V_5 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_12 , V_20 , L_9 , V_6 -> V_29 ) ;
}
int F_20 ( struct V_1 * V_6 )
{
struct V_30 * V_31 ;
int V_2 , error ;
if ( ! V_6 -> V_32 ) {
switch ( V_6 -> type ) {
case V_14 :
V_6 -> V_32 = & V_33 ;
break;
case V_15 :
V_6 -> V_32 = & V_34 ;
break;
default:
V_6 -> V_32 = & V_35 ;
break;
}
}
F_21 ( V_6 -> V_24 == 0 ) ;
F_22 ( & V_36 ) ;
do {
if ( ! F_23 ( & V_3 , V_37 ) )
goto V_38;
error = F_24 ( & V_3 , V_6 , & V_2 ) ;
} while ( error == - V_39 );
if ( error )
goto V_38;
V_6 -> V_7 = V_2 ;
V_6 -> V_40 = 0 ;
if ( F_25 ( V_6 -> V_23 ) )
V_6 -> V_41 = F_26 ( V_6 -> V_23 ) - 1 ;
else
V_6 -> V_41 = 0 ;
if ( F_25 ( V_6 -> V_24 ) )
V_6 -> V_42 = F_26 ( V_6 -> V_24 ) - 1 ;
else
V_6 -> V_42 = 0 ;
V_6 -> V_43 = ( 1 << V_6 -> V_41 ) - 1 ;
V_6 -> V_44 = ( 1 << V_6 -> V_42 ) - 1 ;
if ( ( V_6 -> V_21 & V_45 ) && ( V_6 -> V_21 & V_46 ) ) {
error = F_27 ( V_6 , 0 , V_6 -> V_22 ) ;
if ( error && error != - V_47 )
F_28 ( V_48
L_14 ,
V_6 -> V_29 ) ;
}
V_6 -> V_5 . type = & V_49 ;
V_6 -> V_5 . V_50 = & V_8 ;
V_6 -> V_5 . V_51 = F_5 ( V_2 ) ;
F_29 ( & V_6 -> V_5 , L_15 , V_2 ) ;
F_30 ( & V_6 -> V_5 , V_6 ) ;
if ( F_31 ( & V_6 -> V_5 ) != 0 )
goto V_52;
if ( F_5 ( V_2 ) )
F_32 ( & V_8 , V_6 -> V_5 . V_53 ,
F_5 ( V_2 ) + 1 ,
NULL , L_16 , V_2 ) ;
F_33 ( L_17 , V_2 , V_6 -> V_29 ) ;
F_34 (not, &mtd_notifiers, list)
V_31 -> V_54 ( V_6 ) ;
F_35 ( & V_36 ) ;
F_36 ( V_55 ) ;
return 0 ;
V_52:
F_37 ( & V_3 , V_2 ) ;
V_38:
F_35 ( & V_36 ) ;
return 1 ;
}
int F_38 ( struct V_1 * V_6 )
{
int V_56 ;
struct V_30 * V_31 ;
F_22 ( & V_36 ) ;
if ( F_39 ( & V_3 , V_6 -> V_7 ) != V_6 ) {
V_56 = - V_57 ;
goto V_58;
}
F_34 (not, &mtd_notifiers, list)
V_31 -> remove ( V_6 ) ;
if ( V_6 -> V_40 ) {
F_28 ( V_59 L_18 ,
V_6 -> V_7 , V_6 -> V_29 , V_6 -> V_40 ) ;
V_56 = - V_60 ;
} else {
F_40 ( & V_6 -> V_5 ) ;
F_37 ( & V_3 , V_6 -> V_7 ) ;
F_41 ( V_55 ) ;
V_56 = 0 ;
}
V_58:
F_35 ( & V_36 ) ;
return V_56 ;
}
int F_42 ( struct V_1 * V_6 , const char * * V_61 ,
struct V_62 * V_63 ,
const struct V_64 * V_65 ,
int V_66 )
{
int V_67 ;
struct V_64 * V_68 ;
V_67 = F_43 ( V_6 , V_61 , & V_68 , V_63 ) ;
if ( V_67 <= 0 && V_66 && V_65 ) {
V_68 = F_44 ( V_65 , sizeof( * V_65 ) * V_66 ,
V_37 ) ;
if ( ! V_68 )
V_67 = - V_69 ;
else
V_67 = V_66 ;
}
if ( V_67 > 0 ) {
V_67 = F_45 ( V_6 , V_68 , V_67 ) ;
F_46 ( V_68 ) ;
} else if ( V_67 == 0 ) {
V_67 = F_20 ( V_6 ) ;
if ( V_67 == 1 )
V_67 = - V_57 ;
}
return V_67 ;
}
int F_47 ( struct V_1 * V_70 )
{
int V_67 ;
V_67 = F_48 ( V_70 ) ;
if ( V_67 )
return V_67 ;
if ( ! F_49 ( & V_70 -> V_5 ) )
return 0 ;
return F_38 ( V_70 ) ;
}
void F_50 ( struct V_30 * V_71 )
{
struct V_1 * V_6 ;
F_22 ( & V_36 ) ;
F_51 ( & V_71 -> V_72 , & V_73 ) ;
F_36 ( V_55 ) ;
F_52 (mtd)
V_71 -> V_54 ( V_6 ) ;
F_35 ( & V_36 ) ;
}
int F_53 ( struct V_30 * V_74 )
{
struct V_1 * V_6 ;
F_22 ( & V_36 ) ;
F_41 ( V_55 ) ;
F_52 (mtd)
V_74 -> remove ( V_6 ) ;
F_54 ( & V_74 -> V_72 ) ;
F_35 ( & V_36 ) ;
return 0 ;
}
struct V_1 * F_55 ( struct V_1 * V_6 , int V_75 )
{
struct V_1 * V_56 = NULL , * V_76 ;
int V_67 = - V_57 ;
F_22 ( & V_36 ) ;
if ( V_75 == - 1 ) {
F_52 (other) {
if ( V_76 == V_6 ) {
V_56 = V_6 ;
break;
}
}
} else if ( V_75 >= 0 ) {
V_56 = F_39 ( & V_3 , V_75 ) ;
if ( V_6 && V_6 != V_56 )
V_56 = NULL ;
}
if ( ! V_56 ) {
V_56 = F_56 ( V_67 ) ;
goto V_77;
}
V_67 = F_57 ( V_56 ) ;
if ( V_67 )
V_56 = F_56 ( V_67 ) ;
V_77:
F_35 ( & V_36 ) ;
return V_56 ;
}
int F_57 ( struct V_1 * V_6 )
{
int V_67 ;
if ( ! F_58 ( V_6 -> V_78 ) )
return - V_57 ;
if ( V_6 -> V_79 ) {
V_67 = V_6 -> V_79 ( V_6 ) ;
if ( V_67 ) {
F_41 ( V_6 -> V_78 ) ;
return V_67 ;
}
}
V_6 -> V_40 ++ ;
return 0 ;
}
struct V_1 * F_59 ( const char * V_29 )
{
int V_67 = - V_57 ;
struct V_1 * V_6 = NULL , * V_76 ;
F_22 ( & V_36 ) ;
F_52 (other) {
if ( ! strcmp ( V_29 , V_76 -> V_29 ) ) {
V_6 = V_76 ;
break;
}
}
if ( ! V_6 )
goto V_80;
V_67 = F_57 ( V_6 ) ;
if ( V_67 )
goto V_80;
F_35 ( & V_36 ) ;
return V_6 ;
V_80:
F_35 ( & V_36 ) ;
return F_56 ( V_67 ) ;
}
void F_60 ( struct V_1 * V_6 )
{
F_22 ( & V_36 ) ;
F_61 ( V_6 ) ;
F_35 ( & V_36 ) ;
}
void F_61 ( struct V_1 * V_6 )
{
-- V_6 -> V_40 ;
F_21 ( V_6 -> V_40 < 0 ) ;
if ( V_6 -> V_81 )
V_6 -> V_81 ( V_6 ) ;
F_41 ( V_6 -> V_78 ) ;
}
int F_62 ( struct V_1 * V_6 , struct V_82 * V_83 )
{
if ( V_83 -> V_84 > V_6 -> V_22 || V_83 -> V_85 > V_6 -> V_22 - V_83 -> V_84 )
return - V_86 ;
if ( ! ( V_6 -> V_21 & V_45 ) )
return - V_87 ;
V_83 -> V_88 = V_89 ;
if ( ! V_83 -> V_85 ) {
V_83 -> V_9 = V_90 ;
F_63 ( V_83 ) ;
return 0 ;
}
return V_6 -> V_91 ( V_6 , V_83 ) ;
}
int F_64 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 , T_6 * V_93 ,
void * * V_94 , T_7 * V_95 )
{
* V_93 = 0 ;
* V_94 = NULL ;
if ( V_95 )
* V_95 = 0 ;
if ( ! V_6 -> V_96 )
return - V_47 ;
if ( V_92 < 0 || V_92 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_92 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_96 ( V_6 , V_92 , V_85 , V_93 , V_94 , V_95 ) ;
}
int F_65 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 )
{
if ( ! V_6 -> V_96 )
return - V_47 ;
if ( V_92 < 0 || V_92 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_92 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_97 ( V_6 , V_92 , V_85 ) ;
}
unsigned long F_66 ( struct V_1 * V_6 , unsigned long V_85 ,
unsigned long V_98 , unsigned long V_21 )
{
if ( ! V_6 -> V_99 )
return - V_47 ;
if ( V_98 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_98 )
return - V_86 ;
return V_6 -> V_99 ( V_6 , V_85 , V_98 , V_21 ) ;
}
int F_67 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 , T_6 * V_93 ,
T_8 * V_12 )
{
* V_93 = 0 ;
if ( V_92 < 0 || V_92 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_92 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_100 ( V_6 , V_92 , V_85 , V_93 , V_12 ) ;
}
int F_68 ( struct V_1 * V_6 , T_5 V_101 , T_6 V_85 , T_6 * V_93 ,
const T_8 * V_12 )
{
* V_93 = 0 ;
if ( V_101 < 0 || V_101 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_101 )
return - V_86 ;
if ( ! V_6 -> V_102 || ! ( V_6 -> V_21 & V_45 ) )
return - V_87 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_102 ( V_6 , V_101 , V_85 , V_93 , V_12 ) ;
}
int F_69 ( struct V_1 * V_6 , T_5 V_101 , T_6 V_85 , T_6 * V_93 ,
const T_8 * V_12 )
{
* V_93 = 0 ;
if ( ! V_6 -> V_103 )
return - V_47 ;
if ( V_101 < 0 || V_101 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_101 )
return - V_86 ;
if ( ! ( V_6 -> V_21 & V_45 ) )
return - V_87 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_103 ( V_6 , V_101 , V_85 , V_93 , V_12 ) ;
}
int F_70 ( struct V_1 * V_6 , struct V_104 * V_12 ,
T_6 V_85 )
{
if ( ! V_6 -> V_105 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_105 ( V_6 , V_12 , V_85 ) ;
}
int F_71 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 ,
T_6 * V_93 , T_8 * V_12 )
{
* V_93 = 0 ;
if ( ! V_6 -> V_106 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_106 ( V_6 , V_92 , V_85 , V_93 , V_12 ) ;
}
int F_72 ( struct V_1 * V_6 , struct V_104 * V_12 ,
T_6 V_85 )
{
if ( ! V_6 -> V_107 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_107 ( V_6 , V_12 , V_85 ) ;
}
int F_73 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 ,
T_6 * V_93 , T_8 * V_12 )
{
* V_93 = 0 ;
if ( ! V_6 -> V_108 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_108 ( V_6 , V_92 , V_85 , V_93 , V_12 ) ;
}
int F_74 ( struct V_1 * V_6 , T_5 V_101 , T_6 V_85 ,
T_6 * V_93 , T_8 * V_12 )
{
* V_93 = 0 ;
if ( ! V_6 -> V_109 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_109 ( V_6 , V_101 , V_85 , V_93 , V_12 ) ;
}
int F_75 ( struct V_1 * V_6 , T_5 V_92 , T_6 V_85 )
{
if ( ! V_6 -> V_110 )
return - V_47 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_110 ( V_6 , V_92 , V_85 ) ;
}
int F_76 ( struct V_1 * V_6 , T_5 V_111 , T_9 V_85 )
{
if ( ! V_6 -> V_112 )
return - V_47 ;
if ( V_111 < 0 || V_111 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_111 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_112 ( V_6 , V_111 , V_85 ) ;
}
int F_27 ( struct V_1 * V_6 , T_5 V_111 , T_9 V_85 )
{
if ( ! V_6 -> V_113 )
return - V_47 ;
if ( V_111 < 0 || V_111 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_111 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_113 ( V_6 , V_111 , V_85 ) ;
}
int F_77 ( struct V_1 * V_6 , T_5 V_111 , T_9 V_85 )
{
if ( ! V_6 -> V_114 )
return - V_47 ;
if ( V_111 < 0 || V_111 > V_6 -> V_22 || V_85 > V_6 -> V_22 - V_111 )
return - V_86 ;
if ( ! V_85 )
return 0 ;
return V_6 -> V_114 ( V_6 , V_111 , V_85 ) ;
}
int F_78 ( struct V_1 * V_6 , T_5 V_111 )
{
if ( ! V_6 -> V_115 )
return 0 ;
if ( V_111 < 0 || V_111 > V_6 -> V_22 )
return - V_86 ;
return V_6 -> V_115 ( V_6 , V_111 ) ;
}
int F_79 ( struct V_1 * V_6 , T_5 V_111 )
{
if ( ! V_6 -> V_116 )
return - V_47 ;
if ( V_111 < 0 || V_111 > V_6 -> V_22 )
return - V_86 ;
if ( ! ( V_6 -> V_21 & V_45 ) )
return - V_87 ;
return V_6 -> V_116 ( V_6 , V_111 ) ;
}
static int F_80 ( struct V_1 * V_6 , const struct V_117 * V_118 ,
unsigned long V_119 , T_5 V_101 , T_6 * V_93 )
{
unsigned long V_2 ;
T_6 V_120 = 0 , V_121 ;
int V_56 = 0 ;
for ( V_2 = 0 ; V_2 < V_119 ; V_2 ++ ) {
if ( ! V_118 [ V_2 ] . V_122 )
continue;
V_56 = F_68 ( V_6 , V_101 , V_118 [ V_2 ] . V_122 , & V_121 ,
V_118 [ V_2 ] . V_123 ) ;
V_120 += V_121 ;
if ( V_56 || V_121 != V_118 [ V_2 ] . V_122 )
break;
V_101 += V_118 [ V_2 ] . V_122 ;
}
* V_93 = V_120 ;
return V_56 ;
}
int F_81 ( struct V_1 * V_6 , const struct V_117 * V_118 ,
unsigned long V_119 , T_5 V_101 , T_6 * V_93 )
{
* V_93 = 0 ;
if ( ! ( V_6 -> V_21 & V_45 ) )
return - V_87 ;
if ( ! V_6 -> V_124 )
return F_80 ( V_6 , V_118 , V_119 , V_101 , V_93 ) ;
return V_6 -> V_124 ( V_6 , V_118 , V_119 , V_101 , V_93 ) ;
}
void * F_82 ( const struct V_1 * V_6 , T_6 * V_22 )
{
T_10 V_21 = V_125 | V_126 |
V_127 | V_128 ;
T_6 V_129 = F_83 ( T_6 , V_6 -> V_24 , V_20 ) ;
void * V_130 ;
* V_22 = F_84 ( T_6 , * V_22 , V_131 ) ;
while ( * V_22 > V_129 ) {
V_130 = F_85 ( * V_22 , V_21 ) ;
if ( V_130 )
return V_130 ;
* V_22 >>= 1 ;
* V_22 = F_86 ( * V_22 , V_6 -> V_24 ) ;
}
return F_85 ( * V_22 , V_37 ) ;
}
static int F_87 ( struct V_132 * V_133 , void * V_134 )
{
struct V_1 * V_6 ;
F_88 ( V_133 , L_19 ) ;
F_22 ( & V_36 ) ;
F_52 (mtd) {
F_89 ( V_133 , L_20 ,
V_6 -> V_7 , ( unsigned long long ) V_6 -> V_22 ,
V_6 -> V_23 , V_6 -> V_29 ) ;
}
F_35 ( & V_36 ) ;
return 0 ;
}
static int F_90 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
return F_91 ( V_136 , F_87 , NULL ) ;
}
static int T_11 F_92 ( struct V_32 * V_137 , const char * V_29 )
{
int V_56 ;
V_56 = F_93 ( V_137 ) ;
if ( ! V_56 )
V_56 = F_94 ( V_137 , NULL , V_29 ) ;
if ( V_56 )
F_95 ( V_137 ) ;
return V_56 ;
}
static int T_11 F_96 ( void )
{
int V_56 ;
V_56 = F_97 ( & V_8 ) ;
if ( V_56 )
goto V_138;
V_56 = F_92 ( & V_35 , L_21 ) ;
if ( V_56 )
goto V_139;
V_56 = F_92 ( & V_34 , L_22 ) ;
if ( V_56 )
goto V_140;
V_56 = F_92 ( & V_33 , L_23 ) ;
if ( V_56 )
goto V_141;
#ifdef F_98
V_142 = F_99 ( L_24 , 0 , NULL , & V_143 ) ;
#endif
return 0 ;
V_141:
F_95 ( & V_34 ) ;
V_140:
F_95 ( & V_35 ) ;
V_139:
F_100 ( & V_8 ) ;
V_138:
F_101 ( L_25 , V_56 ) ;
return V_56 ;
}
static void T_12 F_102 ( void )
{
#ifdef F_98
if ( V_142 )
F_103 ( L_24 , NULL ) ;
#endif
F_100 ( & V_8 ) ;
F_95 ( & V_35 ) ;
F_95 ( & V_34 ) ;
F_95 ( & V_33 ) ;
}
