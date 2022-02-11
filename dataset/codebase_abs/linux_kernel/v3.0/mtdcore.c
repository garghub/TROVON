struct V_1 * F_1 ( int V_2 )
{
return F_2 ( & V_3 , & V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
T_1 V_6 = F_4 ( F_5 ( V_5 ) -> V_6 ) ;
if ( V_6 )
F_6 ( & V_7 , V_6 + 1 ) ;
}
static int F_7 ( struct V_4 * V_5 , T_2 V_8 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
if ( V_9 && V_9 -> V_10 )
return V_9 -> V_10 ( V_9 ) ;
else
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
if ( V_9 && V_9 -> V_11 )
V_9 -> V_11 ( V_9 ) ;
return 0 ;
}
static T_3 F_9 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
char * type ;
switch ( V_9 -> type ) {
case V_15 :
type = L_1 ;
break;
case V_16 :
type = L_2 ;
break;
case V_17 :
type = L_3 ;
break;
case V_18 :
type = L_4 ;
break;
case V_19 :
type = L_5 ;
break;
case V_20 :
type = L_6 ;
break;
case V_21 :
type = L_7 ;
break;
default:
type = L_8 ;
}
return snprintf ( V_14 , V_22 , L_9 , type ) ;
}
static T_3 F_10 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_10 , ( unsigned long ) V_9 -> V_23 ) ;
}
static T_3 F_11 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_11 ,
( unsigned long long ) V_9 -> V_24 ) ;
}
static T_3 F_12 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_12 , ( unsigned long ) V_9 -> V_25 ) ;
}
static T_3 F_13 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_12 , ( unsigned long ) V_9 -> V_26 ) ;
}
static T_3 F_14 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
unsigned int V_27 = V_9 -> V_26 >> V_9 -> V_28 ;
return snprintf ( V_14 , V_22 , L_13 , V_27 ) ;
}
static T_3 F_15 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_12 , ( unsigned long ) V_9 -> V_29 ) ;
}
static T_3 F_16 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_13 , V_9 -> V_30 ) ;
}
static T_3 F_17 ( struct V_4 * V_5 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_9 = F_5 ( V_5 ) ;
return snprintf ( V_14 , V_22 , L_9 , V_9 -> V_31 ) ;
}
int F_18 ( struct V_1 * V_9 )
{
struct V_32 * V_33 ;
int V_2 , error ;
if ( ! V_9 -> V_34 ) {
switch ( V_9 -> type ) {
case V_16 :
V_9 -> V_34 = & V_35 ;
break;
case V_17 :
V_9 -> V_34 = & V_36 ;
break;
default:
V_9 -> V_34 = & V_37 ;
break;
}
}
F_19 ( V_9 -> V_26 == 0 ) ;
F_20 ( & V_38 ) ;
do {
if ( ! F_21 ( & V_3 , V_39 ) )
goto V_40;
error = F_22 ( & V_3 , V_9 , & V_2 ) ;
} while ( error == - V_41 );
if ( error )
goto V_40;
V_9 -> V_6 = V_2 ;
V_9 -> V_42 = 0 ;
if ( F_23 ( V_9 -> V_25 ) )
V_9 -> V_43 = F_24 ( V_9 -> V_25 ) - 1 ;
else
V_9 -> V_43 = 0 ;
if ( F_23 ( V_9 -> V_26 ) )
V_9 -> V_44 = F_24 ( V_9 -> V_26 ) - 1 ;
else
V_9 -> V_44 = 0 ;
V_9 -> V_45 = ( 1 << V_9 -> V_43 ) - 1 ;
V_9 -> V_46 = ( 1 << V_9 -> V_44 ) - 1 ;
if ( ( V_9 -> V_23 & V_47 )
&& ( V_9 -> V_23 & V_48 ) && V_9 -> V_49 ) {
if ( V_9 -> V_49 ( V_9 , 0 , V_9 -> V_24 ) )
F_25 ( V_50
L_14 ,
V_9 -> V_31 ) ;
}
V_9 -> V_5 . type = & V_51 ;
V_9 -> V_5 . V_52 = & V_7 ;
V_9 -> V_5 . V_53 = F_4 ( V_2 ) ;
F_26 ( & V_9 -> V_5 , L_15 , V_2 ) ;
F_27 ( & V_9 -> V_5 , V_9 ) ;
if ( F_28 ( & V_9 -> V_5 ) != 0 )
goto V_54;
if ( F_4 ( V_2 ) )
F_29 ( & V_7 , V_9 -> V_5 . V_55 ,
F_4 ( V_2 ) + 1 ,
NULL , L_16 , V_2 ) ;
F_30 ( 0 , L_17 , V_2 , V_9 -> V_31 ) ;
F_31 (not, &mtd_notifiers, list)
V_33 -> V_56 ( V_9 ) ;
F_32 ( & V_38 ) ;
F_33 ( V_57 ) ;
return 0 ;
V_54:
F_34 ( & V_3 , V_2 ) ;
V_40:
F_32 ( & V_38 ) ;
return 1 ;
}
int F_35 ( struct V_1 * V_9 )
{
int V_58 ;
struct V_32 * V_33 ;
F_20 ( & V_38 ) ;
if ( F_36 ( & V_3 , V_9 -> V_6 ) != V_9 ) {
V_58 = - V_59 ;
goto V_60;
}
F_31 (not, &mtd_notifiers, list)
V_33 -> remove ( V_9 ) ;
if ( V_9 -> V_42 ) {
F_25 ( V_61 L_18 ,
V_9 -> V_6 , V_9 -> V_31 , V_9 -> V_42 ) ;
V_58 = - V_62 ;
} else {
F_37 ( & V_9 -> V_5 ) ;
F_34 ( & V_3 , V_9 -> V_6 ) ;
F_38 ( V_57 ) ;
V_58 = 0 ;
}
V_60:
F_32 ( & V_38 ) ;
return V_58 ;
}
int F_39 ( struct V_1 * V_63 ,
const struct V_64 * V_65 ,
int V_66 )
{
return V_65 ? F_40 ( V_63 , V_65 , V_66 ) :
F_18 ( V_63 ) ;
}
int F_41 ( struct V_1 * V_63 )
{
int V_67 ;
V_67 = F_42 ( V_63 ) ;
if ( V_67 )
return V_67 ;
if ( ! F_43 ( & V_63 -> V_5 ) )
return 0 ;
return F_35 ( V_63 ) ;
}
void F_44 ( struct V_32 * V_68 )
{
struct V_1 * V_9 ;
F_20 ( & V_38 ) ;
F_45 ( & V_68 -> V_69 , & V_70 ) ;
F_33 ( V_57 ) ;
F_46 (mtd)
V_68 -> V_56 ( V_9 ) ;
F_32 ( & V_38 ) ;
}
int F_47 ( struct V_32 * V_71 )
{
struct V_1 * V_9 ;
F_20 ( & V_38 ) ;
F_38 ( V_57 ) ;
F_46 (mtd)
V_71 -> remove ( V_9 ) ;
F_48 ( & V_71 -> V_69 ) ;
F_32 ( & V_38 ) ;
return 0 ;
}
struct V_1 * F_49 ( struct V_1 * V_9 , int V_72 )
{
struct V_1 * V_58 = NULL , * V_73 ;
int V_67 = - V_59 ;
F_20 ( & V_38 ) ;
if ( V_72 == - 1 ) {
F_46 (other) {
if ( V_73 == V_9 ) {
V_58 = V_9 ;
break;
}
}
} else if ( V_72 >= 0 ) {
V_58 = F_36 ( & V_3 , V_72 ) ;
if ( V_9 && V_9 != V_58 )
V_58 = NULL ;
}
if ( ! V_58 ) {
V_58 = F_50 ( V_67 ) ;
goto V_74;
}
V_67 = F_51 ( V_58 ) ;
if ( V_67 )
V_58 = F_50 ( V_67 ) ;
V_74:
F_32 ( & V_38 ) ;
return V_58 ;
}
int F_51 ( struct V_1 * V_9 )
{
int V_67 ;
if ( ! F_52 ( V_9 -> V_75 ) )
return - V_59 ;
if ( V_9 -> V_76 ) {
V_67 = V_9 -> V_76 ( V_9 ) ;
if ( V_67 ) {
F_38 ( V_9 -> V_75 ) ;
return V_67 ;
}
}
V_9 -> V_42 ++ ;
return 0 ;
}
struct V_1 * F_53 ( const char * V_31 )
{
int V_67 = - V_59 ;
struct V_1 * V_9 = NULL , * V_73 ;
F_20 ( & V_38 ) ;
F_46 (other) {
if ( ! strcmp ( V_31 , V_73 -> V_31 ) ) {
V_9 = V_73 ;
break;
}
}
if ( ! V_9 )
goto V_77;
V_67 = F_51 ( V_9 ) ;
if ( V_67 )
goto V_77;
F_32 ( & V_38 ) ;
return V_9 ;
V_77:
F_32 ( & V_38 ) ;
return F_50 ( V_67 ) ;
}
void F_54 ( struct V_1 * V_9 )
{
F_20 ( & V_38 ) ;
F_55 ( V_9 ) ;
F_32 ( & V_38 ) ;
}
void F_55 ( struct V_1 * V_9 )
{
-- V_9 -> V_42 ;
F_19 ( V_9 -> V_42 < 0 ) ;
if ( V_9 -> V_78 )
V_9 -> V_78 ( V_9 ) ;
F_38 ( V_9 -> V_75 ) ;
}
int F_56 ( struct V_1 * V_9 , const struct V_79 * V_80 ,
unsigned long V_81 , T_4 V_82 , T_5 * V_83 )
{
unsigned long V_2 ;
T_5 V_84 = 0 , V_85 ;
int V_58 = 0 ;
if( ! V_9 -> V_86 ) {
V_58 = - V_87 ;
} else {
for ( V_2 = 0 ; V_2 < V_81 ; V_2 ++ ) {
if ( ! V_80 [ V_2 ] . V_88 )
continue;
V_58 = V_9 -> V_86 ( V_9 , V_82 , V_80 [ V_2 ] . V_88 , & V_85 , V_80 [ V_2 ] . V_89 ) ;
V_84 += V_85 ;
if ( V_58 || V_85 != V_80 [ V_2 ] . V_88 )
break;
V_82 += V_80 [ V_2 ] . V_88 ;
}
}
if ( V_83 )
* V_83 = V_84 ;
return V_58 ;
}
void * F_57 ( const struct V_1 * V_9 , T_5 * V_24 )
{
T_6 V_23 = V_90 | V_91 |
V_92 | V_93 ;
T_5 V_94 = F_58 ( T_5 , V_9 -> V_26 , V_22 ) ;
void * V_95 ;
* V_24 = F_59 ( T_5 , * V_24 , V_96 ) ;
while ( * V_24 > V_94 ) {
V_95 = F_60 ( * V_24 , V_23 ) ;
if ( V_95 )
return V_95 ;
* V_24 >>= 1 ;
* V_24 = F_61 ( * V_24 , V_9 -> V_26 ) ;
}
return F_60 ( * V_24 , V_39 ) ;
}
static int F_62 ( struct V_97 * V_98 , void * V_99 )
{
struct V_1 * V_9 ;
F_63 ( V_98 , L_19 ) ;
F_20 ( & V_38 ) ;
F_46 (mtd) {
F_64 ( V_98 , L_20 ,
V_9 -> V_6 , ( unsigned long long ) V_9 -> V_24 ,
V_9 -> V_25 , V_9 -> V_31 ) ;
}
F_32 ( & V_38 ) ;
return 0 ;
}
static int F_65 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
return F_66 ( V_101 , F_62 , NULL ) ;
}
static int T_7 F_67 ( struct V_34 * V_102 , const char * V_31 )
{
int V_58 ;
V_58 = F_68 ( V_102 ) ;
if ( ! V_58 )
V_58 = F_69 ( V_102 , NULL , V_31 ) ;
if ( V_58 )
F_70 ( V_102 ) ;
return V_58 ;
}
static int T_7 F_71 ( void )
{
int V_58 ;
V_58 = F_72 ( & V_7 ) ;
if ( V_58 )
goto V_103;
V_58 = F_67 ( & V_37 , L_21 ) ;
if ( V_58 )
goto V_104;
V_58 = F_67 ( & V_36 , L_22 ) ;
if ( V_58 )
goto V_105;
V_58 = F_67 ( & V_35 , L_23 ) ;
if ( V_58 )
goto V_106;
#ifdef F_73
V_107 = F_74 ( L_24 , 0 , NULL , & V_108 ) ;
#endif
return 0 ;
V_106:
F_70 ( & V_36 ) ;
V_105:
F_70 ( & V_37 ) ;
V_104:
F_75 ( & V_7 ) ;
V_103:
F_76 ( L_25 , V_58 ) ;
return V_58 ;
}
static void T_8 F_77 ( void )
{
#ifdef F_73
if ( V_107 )
F_78 ( L_24 , NULL ) ;
#endif
F_75 ( & V_7 ) ;
F_70 ( & V_37 ) ;
F_70 ( & V_36 ) ;
F_70 ( & V_35 ) ;
}
