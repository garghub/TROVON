struct V_1 * F_1 ( int V_2 )
{
return F_2 ( & V_3 , & V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
T_1 V_7 = F_5 ( V_6 -> V_7 ) ;
if ( V_7 )
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
if ( V_6 && V_6 -> V_10 )
F_10 ( V_6 ) ;
return 0 ;
}
static T_3 F_11 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
char * type ;
switch ( V_6 -> type ) {
case V_14 :
type = L_1 ;
break;
case V_15 :
type = L_2 ;
break;
case V_16 :
type = L_3 ;
break;
case V_17 :
type = L_4 ;
break;
case V_18 :
type = L_5 ;
break;
case V_19 :
type = L_6 ;
break;
case V_20 :
type = L_7 ;
break;
default:
type = L_8 ;
}
return snprintf ( V_13 , V_21 , L_9 , type ) ;
}
static T_3 F_12 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_10 , ( unsigned long ) V_6 -> V_22 ) ;
}
static T_3 F_13 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_11 ,
( unsigned long long ) V_6 -> V_23 ) ;
}
static T_3 F_14 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_12 , ( unsigned long ) V_6 -> V_24 ) ;
}
static T_3 F_15 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_12 , ( unsigned long ) V_6 -> V_25 ) ;
}
static T_3 F_16 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
unsigned int V_26 = V_6 -> V_25 >> V_6 -> V_27 ;
return snprintf ( V_13 , V_21 , L_13 , V_26 ) ;
}
static T_3 F_17 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_12 , ( unsigned long ) V_6 -> V_28 ) ;
}
static T_3 F_18 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_13 , V_6 -> V_29 ) ;
}
static T_3 F_19 ( struct V_4 * V_5 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_13 , V_21 , L_9 , V_6 -> V_30 ) ;
}
int F_20 ( struct V_1 * V_6 )
{
struct V_31 * V_32 ;
int V_2 , error ;
if ( ! V_6 -> V_33 ) {
switch ( V_6 -> type ) {
case V_15 :
V_6 -> V_33 = & V_34 ;
break;
case V_16 :
V_6 -> V_33 = & V_35 ;
break;
default:
V_6 -> V_33 = & V_36 ;
break;
}
}
F_21 ( V_6 -> V_25 == 0 ) ;
F_22 ( & V_37 ) ;
do {
if ( ! F_23 ( & V_3 , V_38 ) )
goto V_39;
error = F_24 ( & V_3 , V_6 , & V_2 ) ;
} while ( error == - V_40 );
if ( error )
goto V_39;
V_6 -> V_7 = V_2 ;
V_6 -> V_41 = 0 ;
if ( F_25 ( V_6 -> V_24 ) )
V_6 -> V_42 = F_26 ( V_6 -> V_24 ) - 1 ;
else
V_6 -> V_42 = 0 ;
if ( F_25 ( V_6 -> V_25 ) )
V_6 -> V_43 = F_26 ( V_6 -> V_25 ) - 1 ;
else
V_6 -> V_43 = 0 ;
V_6 -> V_44 = ( 1 << V_6 -> V_42 ) - 1 ;
V_6 -> V_45 = ( 1 << V_6 -> V_43 ) - 1 ;
if ( ( V_6 -> V_22 & V_46 ) && ( V_6 -> V_22 & V_47 ) ) {
error = F_27 ( V_6 , 0 , V_6 -> V_23 ) ;
if ( error && error != - V_48 )
F_28 ( V_49
L_14 ,
V_6 -> V_30 ) ;
}
V_6 -> V_5 . type = & V_50 ;
V_6 -> V_5 . V_51 = & V_8 ;
V_6 -> V_5 . V_52 = F_5 ( V_2 ) ;
F_29 ( & V_6 -> V_5 , L_15 , V_2 ) ;
F_30 ( & V_6 -> V_5 , V_6 ) ;
if ( F_31 ( & V_6 -> V_5 ) != 0 )
goto V_53;
if ( F_5 ( V_2 ) )
F_32 ( & V_8 , V_6 -> V_5 . V_54 ,
F_5 ( V_2 ) + 1 ,
NULL , L_16 , V_2 ) ;
F_33 ( L_17 , V_2 , V_6 -> V_30 ) ;
F_34 (not, &mtd_notifiers, list)
V_32 -> V_55 ( V_6 ) ;
F_35 ( & V_37 ) ;
F_36 ( V_56 ) ;
return 0 ;
V_53:
F_37 ( & V_3 , V_2 ) ;
V_39:
F_35 ( & V_37 ) ;
return 1 ;
}
int F_38 ( struct V_1 * V_6 )
{
int V_57 ;
struct V_31 * V_32 ;
F_22 ( & V_37 ) ;
if ( F_39 ( & V_3 , V_6 -> V_7 ) != V_6 ) {
V_57 = - V_58 ;
goto V_59;
}
F_34 (not, &mtd_notifiers, list)
V_32 -> remove ( V_6 ) ;
if ( V_6 -> V_41 ) {
F_28 ( V_60 L_18 ,
V_6 -> V_7 , V_6 -> V_30 , V_6 -> V_41 ) ;
V_57 = - V_61 ;
} else {
F_40 ( & V_6 -> V_5 ) ;
F_37 ( & V_3 , V_6 -> V_7 ) ;
F_41 ( V_56 ) ;
V_57 = 0 ;
}
V_59:
F_35 ( & V_37 ) ;
return V_57 ;
}
int F_42 ( struct V_1 * V_6 , const char * * V_62 ,
struct V_63 * V_64 ,
const struct V_65 * V_66 ,
int V_67 )
{
int V_68 ;
struct V_65 * V_69 ;
V_68 = F_43 ( V_6 , V_62 , & V_69 , V_64 ) ;
if ( V_68 <= 0 && V_67 && V_66 ) {
V_69 = F_44 ( V_66 , sizeof( * V_66 ) * V_67 ,
V_38 ) ;
if ( ! V_69 )
V_68 = - V_70 ;
else
V_68 = V_67 ;
}
if ( V_68 > 0 ) {
V_68 = F_45 ( V_6 , V_69 , V_68 ) ;
F_46 ( V_69 ) ;
} else if ( V_68 == 0 ) {
V_68 = F_20 ( V_6 ) ;
if ( V_68 == 1 )
V_68 = - V_58 ;
}
return V_68 ;
}
int F_47 ( struct V_1 * V_71 )
{
int V_68 ;
V_68 = F_48 ( V_71 ) ;
if ( V_68 )
return V_68 ;
if ( ! F_49 ( & V_71 -> V_5 ) )
return 0 ;
return F_38 ( V_71 ) ;
}
void F_50 ( struct V_31 * V_72 )
{
struct V_1 * V_6 ;
F_22 ( & V_37 ) ;
F_51 ( & V_72 -> V_73 , & V_74 ) ;
F_36 ( V_56 ) ;
F_52 (mtd)
V_72 -> V_55 ( V_6 ) ;
F_35 ( & V_37 ) ;
}
int F_53 ( struct V_31 * V_75 )
{
struct V_1 * V_6 ;
F_22 ( & V_37 ) ;
F_41 ( V_56 ) ;
F_52 (mtd)
V_75 -> remove ( V_6 ) ;
F_54 ( & V_75 -> V_73 ) ;
F_35 ( & V_37 ) ;
return 0 ;
}
struct V_1 * F_55 ( struct V_1 * V_6 , int V_76 )
{
struct V_1 * V_57 = NULL , * V_77 ;
int V_68 = - V_58 ;
F_22 ( & V_37 ) ;
if ( V_76 == - 1 ) {
F_52 (other) {
if ( V_77 == V_6 ) {
V_57 = V_6 ;
break;
}
}
} else if ( V_76 >= 0 ) {
V_57 = F_39 ( & V_3 , V_76 ) ;
if ( V_6 && V_6 != V_57 )
V_57 = NULL ;
}
if ( ! V_57 ) {
V_57 = F_56 ( V_68 ) ;
goto V_78;
}
V_68 = F_57 ( V_57 ) ;
if ( V_68 )
V_57 = F_56 ( V_68 ) ;
V_78:
F_35 ( & V_37 ) ;
return V_57 ;
}
int F_57 ( struct V_1 * V_6 )
{
int V_68 ;
if ( ! F_58 ( V_6 -> V_79 ) )
return - V_58 ;
if ( V_6 -> V_80 ) {
V_68 = V_6 -> V_80 ( V_6 ) ;
if ( V_68 ) {
F_41 ( V_6 -> V_79 ) ;
return V_68 ;
}
}
V_6 -> V_41 ++ ;
return 0 ;
}
struct V_1 * F_59 ( const char * V_30 )
{
int V_68 = - V_58 ;
struct V_1 * V_6 = NULL , * V_77 ;
F_22 ( & V_37 ) ;
F_52 (other) {
if ( ! strcmp ( V_30 , V_77 -> V_30 ) ) {
V_6 = V_77 ;
break;
}
}
if ( ! V_6 )
goto V_81;
V_68 = F_57 ( V_6 ) ;
if ( V_68 )
goto V_81;
F_35 ( & V_37 ) ;
return V_6 ;
V_81:
F_35 ( & V_37 ) ;
return F_56 ( V_68 ) ;
}
void F_60 ( struct V_1 * V_6 )
{
F_22 ( & V_37 ) ;
F_61 ( V_6 ) ;
F_35 ( & V_37 ) ;
}
void F_61 ( struct V_1 * V_6 )
{
-- V_6 -> V_41 ;
F_21 ( V_6 -> V_41 < 0 ) ;
if ( V_6 -> V_82 )
V_6 -> V_82 ( V_6 ) ;
F_41 ( V_6 -> V_79 ) ;
}
static int F_62 ( struct V_1 * V_6 , const struct V_83 * V_84 ,
unsigned long V_85 , T_4 V_86 , T_5 * V_87 )
{
unsigned long V_2 ;
T_5 V_88 = 0 , V_89 ;
int V_57 = 0 ;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ ) {
if ( ! V_84 [ V_2 ] . V_90 )
continue;
V_57 = F_63 ( V_6 , V_86 , V_84 [ V_2 ] . V_90 , & V_89 ,
V_84 [ V_2 ] . V_91 ) ;
V_88 += V_89 ;
if ( V_57 || V_89 != V_84 [ V_2 ] . V_90 )
break;
V_86 += V_84 [ V_2 ] . V_90 ;
}
* V_87 = V_88 ;
return V_57 ;
}
int F_64 ( struct V_1 * V_6 , const struct V_83 * V_84 ,
unsigned long V_85 , T_4 V_86 , T_5 * V_87 )
{
* V_87 = 0 ;
if ( ! V_6 -> V_92 )
return F_62 ( V_6 , V_84 , V_85 , V_86 , V_87 ) ;
return V_6 -> V_92 ( V_6 , V_84 , V_85 , V_86 , V_87 ) ;
}
void * F_65 ( const struct V_1 * V_6 , T_5 * V_23 )
{
T_6 V_22 = V_93 | V_94 |
V_95 | V_96 ;
T_5 V_97 = F_66 ( T_5 , V_6 -> V_25 , V_21 ) ;
void * V_98 ;
* V_23 = F_67 ( T_5 , * V_23 , V_99 ) ;
while ( * V_23 > V_97 ) {
V_98 = F_68 ( * V_23 , V_22 ) ;
if ( V_98 )
return V_98 ;
* V_23 >>= 1 ;
* V_23 = F_69 ( * V_23 , V_6 -> V_25 ) ;
}
return F_68 ( * V_23 , V_38 ) ;
}
static int F_70 ( struct V_100 * V_101 , void * V_102 )
{
struct V_1 * V_6 ;
F_71 ( V_101 , L_19 ) ;
F_22 ( & V_37 ) ;
F_52 (mtd) {
F_72 ( V_101 , L_20 ,
V_6 -> V_7 , ( unsigned long long ) V_6 -> V_23 ,
V_6 -> V_24 , V_6 -> V_30 ) ;
}
F_35 ( & V_37 ) ;
return 0 ;
}
static int F_73 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_74 ( V_104 , F_70 , NULL ) ;
}
static int T_7 F_75 ( struct V_33 * V_105 , const char * V_30 )
{
int V_57 ;
V_57 = F_76 ( V_105 ) ;
if ( ! V_57 )
V_57 = F_77 ( V_105 , NULL , V_30 ) ;
if ( V_57 )
F_78 ( V_105 ) ;
return V_57 ;
}
static int T_7 F_79 ( void )
{
int V_57 ;
V_57 = F_80 ( & V_8 ) ;
if ( V_57 )
goto V_106;
V_57 = F_75 ( & V_36 , L_21 ) ;
if ( V_57 )
goto V_107;
V_57 = F_75 ( & V_35 , L_22 ) ;
if ( V_57 )
goto V_108;
V_57 = F_75 ( & V_34 , L_23 ) ;
if ( V_57 )
goto V_109;
#ifdef F_81
V_110 = F_82 ( L_24 , 0 , NULL , & V_111 ) ;
#endif
return 0 ;
V_109:
F_78 ( & V_35 ) ;
V_108:
F_78 ( & V_36 ) ;
V_107:
F_83 ( & V_8 ) ;
V_106:
F_84 ( L_25 , V_57 ) ;
return V_57 ;
}
static void T_8 F_85 ( void )
{
#ifdef F_81
if ( V_110 )
F_86 ( L_24 , NULL ) ;
#endif
F_83 ( & V_8 ) ;
F_78 ( & V_36 ) ;
F_78 ( & V_35 ) ;
F_78 ( & V_34 ) ;
}
