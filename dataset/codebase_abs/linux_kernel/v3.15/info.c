int F_1 ( const char * V_1 )
{
static char * V_2 [] =
{
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
NULL
} ;
char * * V_3 = V_2 ;
while ( * V_3 ) {
if ( ! strcmp ( * V_3 , V_1 ) )
return 0 ;
V_3 ++ ;
}
if ( ! strncmp ( V_1 , L_12 , 4 ) )
return 0 ;
return 1 ;
}
static int F_2 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
char * V_7 ;
V_6 = F_3 ( V_6 ) ;
V_7 = F_4 ( V_5 -> V_5 , V_6 , V_8 | V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_5 -> V_5 = V_7 ;
V_5 -> V_11 = V_6 ;
return 0 ;
}
int F_5 ( struct V_4 * V_5 , const char * V_12 , ... )
{
T_1 args ;
int V_11 , V_13 ;
int V_14 = 0 ;
F_6 () ;
if ( V_5 -> V_15 || V_5 -> error )
return 0 ;
V_11 = V_5 -> V_11 - V_5 -> V_16 ;
va_start ( args , V_12 ) ;
for (; ; ) {
T_1 V_17 ;
F_7 ( V_17 , args ) ;
V_13 = vsnprintf ( V_5 -> V_5 + V_5 -> V_18 , V_11 , V_12 , V_17 ) ;
va_end ( V_17 ) ;
if ( V_13 < V_11 )
break;
V_14 = F_2 ( V_5 , V_5 -> V_11 + V_19 ) ;
if ( V_14 < 0 )
break;
V_11 = V_5 -> V_11 - V_5 -> V_16 ;
}
va_end ( args ) ;
if ( V_14 < 0 )
return V_14 ;
V_5 -> V_18 += V_13 ;
V_5 -> V_16 += V_13 ;
return V_13 ;
}
static T_2 F_8 ( struct V_20 * V_20 , T_2 V_21 , int V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
T_2 V_27 = - V_28 , V_16 ;
V_24 = V_20 -> V_29 ;
V_26 = V_24 -> V_26 ;
F_9 ( & V_26 -> V_30 ) ;
if ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_35 ) {
V_21 = V_26 -> V_33 . V_34 -> V_35 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_21 , V_22 ) ;
goto V_37;
}
if ( V_26 -> V_31 == V_32 )
V_16 = V_26 -> V_16 ;
else
V_16 = 0 ;
switch ( V_22 ) {
case V_38 :
break;
case V_39 :
V_21 += V_20 -> V_40 ;
break;
case V_41 :
if ( ! V_16 )
goto V_37;
V_21 += V_16 ;
break;
default:
goto V_37;
}
if ( V_21 < 0 )
goto V_37;
if ( V_16 && V_21 > V_16 )
V_21 = V_16 ;
V_20 -> V_40 = V_21 ;
V_27 = V_21 ;
V_37:
F_10 ( & V_26 -> V_30 ) ;
return V_27 ;
}
static T_3 F_11 ( struct V_20 * V_20 , char T_4 * V_5 ,
T_5 V_42 , T_2 * V_21 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_43 ;
T_5 V_16 = 0 ;
T_2 V_44 ;
V_24 = V_20 -> V_29 ;
if ( F_12 ( ! V_24 ) )
return - V_45 ;
V_44 = * V_21 ;
if ( V_44 < 0 || ( long ) V_44 != V_44 || ( T_3 ) V_42 < 0 )
return - V_46 ;
if ( ( unsigned long ) V_44 + ( unsigned long ) V_42 < ( unsigned long ) V_44 )
return - V_46 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
V_43 = V_24 -> V_48 ;
if ( V_43 == NULL )
return - V_46 ;
if ( V_44 >= V_43 -> V_16 )
return 0 ;
V_16 = V_43 -> V_16 - V_44 ;
V_16 = F_13 ( V_42 , V_16 ) ;
if ( F_14 ( V_5 , V_43 -> V_5 + V_44 , V_16 ) )
return - V_49 ;
break;
case V_32 :
if ( V_44 >= V_26 -> V_16 )
return 0 ;
if ( V_26 -> V_33 . V_34 -> V_50 ) {
V_16 = V_26 -> V_16 - V_44 ;
V_16 = F_13 ( V_42 , V_16 ) ;
V_16 = V_26 -> V_33 . V_34 -> V_50 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_5 , V_16 , V_44 ) ;
}
break;
}
if ( ( T_3 ) V_16 > 0 )
* V_21 = V_44 + V_16 ;
return V_16 ;
}
static T_3 F_15 ( struct V_20 * V_20 , const char T_4 * V_5 ,
T_5 V_42 , T_2 * V_21 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_43 ;
T_3 V_16 = 0 ;
T_2 V_44 ;
V_24 = V_20 -> V_29 ;
if ( F_12 ( ! V_24 ) )
return - V_45 ;
V_26 = V_24 -> V_26 ;
V_44 = * V_21 ;
if ( V_44 < 0 || ( long ) V_44 != V_44 || ( T_3 ) V_42 < 0 )
return - V_46 ;
if ( ( unsigned long ) V_44 + ( unsigned long ) V_42 < ( unsigned long ) V_44 )
return - V_46 ;
switch ( V_26 -> V_31 ) {
case V_47 :
V_43 = V_24 -> V_51 ;
if ( V_43 == NULL )
return - V_46 ;
F_9 ( & V_26 -> V_30 ) ;
if ( V_44 + V_42 >= V_43 -> V_11 ) {
if ( F_2 ( V_43 , V_44 + V_42 ) ) {
F_10 ( & V_26 -> V_30 ) ;
return - V_10 ;
}
}
if ( F_16 ( V_43 -> V_5 + V_44 , V_5 , V_42 ) ) {
F_10 ( & V_26 -> V_30 ) ;
return - V_49 ;
}
V_43 -> V_16 = V_44 + V_42 ;
F_10 ( & V_26 -> V_30 ) ;
V_16 = V_42 ;
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_52 && V_42 > 0 ) {
T_5 V_53 = V_26 -> V_16 - V_44 ;
V_42 = F_13 ( V_42 , V_53 ) ;
V_16 = V_26 -> V_33 . V_34 -> V_52 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_5 , V_42 , V_44 ) ;
}
break;
}
if ( ( T_3 ) V_16 > 0 )
* V_21 = V_44 + V_16 ;
return V_16 ;
}
static int F_17 ( struct V_54 * V_54 , struct V_20 * V_20 )
{
struct V_25 * V_26 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
int V_55 , V_14 ;
F_9 ( & V_56 ) ;
V_26 = F_18 ( V_54 ) ;
if ( V_26 == NULL || ! V_26 -> V_57 ) {
F_10 ( & V_56 ) ;
return - V_58 ;
}
if ( ! F_19 ( V_26 -> V_59 ) ) {
V_14 = - V_49 ;
goto V_60;
}
V_55 = V_20 -> V_61 & V_62 ;
if ( V_55 == V_63 || V_55 == V_64 ) {
if ( ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_50 == NULL ) ) {
V_14 = - V_58 ;
goto V_65;
}
}
if ( V_55 == V_66 || V_55 == V_64 ) {
if ( ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_52 == NULL ) ) {
V_14 = - V_58 ;
goto V_65;
}
}
V_24 = F_20 ( sizeof( * V_24 ) , V_8 ) ;
if ( V_24 == NULL ) {
V_14 = - V_10 ;
goto V_65;
}
V_24 -> V_26 = V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
if ( V_55 == V_63 || V_55 == V_64 ) {
V_5 = F_20 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_67;
V_24 -> V_48 = V_5 ;
V_5 -> V_11 = V_19 ;
V_5 -> V_5 = F_20 ( V_5 -> V_11 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_67;
}
if ( V_55 == V_66 || V_55 == V_64 ) {
V_5 = F_20 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_67;
V_24 -> V_51 = V_5 ;
V_5 -> V_11 = V_19 ;
V_5 -> V_5 = F_21 ( V_5 -> V_11 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_67;
}
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_68 ) {
if ( ( V_14 = V_26 -> V_33 . V_34 -> V_68 ( V_26 , V_55 ,
& V_24 -> V_36 ) ) < 0 ) {
F_22 ( V_24 ) ;
goto V_65;
}
}
break;
}
V_20 -> V_29 = V_24 ;
F_10 ( & V_56 ) ;
if ( V_26 -> V_31 == V_47 &&
( V_55 == V_63 || V_55 == V_64 ) ) {
if ( V_26 -> V_33 . V_69 . V_50 ) {
F_9 ( & V_26 -> V_30 ) ;
V_26 -> V_33 . V_69 . V_50 ( V_26 , V_24 -> V_48 ) ;
F_10 ( & V_26 -> V_30 ) ;
}
}
return 0 ;
V_67:
if ( V_24 -> V_48 ) {
F_22 ( V_24 -> V_48 -> V_5 ) ;
F_22 ( V_24 -> V_48 ) ;
}
if ( V_24 -> V_51 ) {
F_22 ( V_24 -> V_51 -> V_5 ) ;
F_22 ( V_24 -> V_51 ) ;
}
F_22 ( V_24 ) ;
V_14 = - V_10 ;
V_65:
F_23 ( V_26 -> V_59 ) ;
V_60:
F_10 ( & V_56 ) ;
return V_14 ;
}
static int F_24 ( struct V_54 * V_54 , struct V_20 * V_20 )
{
struct V_25 * V_26 ;
struct V_23 * V_24 ;
int V_55 ;
V_55 = V_20 -> V_61 & V_62 ;
V_24 = V_20 -> V_29 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
if ( V_24 -> V_48 ) {
F_22 ( V_24 -> V_48 -> V_5 ) ;
F_22 ( V_24 -> V_48 ) ;
}
if ( V_24 -> V_51 ) {
if ( V_26 -> V_33 . V_69 . V_52 ) {
V_26 -> V_33 . V_69 . V_52 ( V_26 , V_24 -> V_51 ) ;
if ( V_24 -> V_51 -> error ) {
if ( V_26 -> V_70 )
F_25 ( V_26 -> V_70 -> V_71 , L_13 ,
V_26 -> V_72 ,
V_24 -> V_51 -> error ) ;
else
F_26 ( L_14 ,
V_26 -> V_72 ,
V_24 -> V_51 -> error ) ;
}
}
F_22 ( V_24 -> V_51 -> V_5 ) ;
F_22 ( V_24 -> V_51 ) ;
}
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_73 )
V_26 -> V_33 . V_34 -> V_73 ( V_26 , V_55 ,
V_24 -> V_36 ) ;
break;
}
F_23 ( V_26 -> V_59 ) ;
F_22 ( V_24 ) ;
return 0 ;
}
static unsigned int F_27 ( struct V_20 * V_20 , T_6 * V_74 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
unsigned int V_75 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
V_75 = 0 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_76 )
return V_26 -> V_33 . V_34 -> V_76 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_74 ) ;
if ( V_26 -> V_33 . V_34 -> V_50 )
V_75 |= V_77 | V_78 ;
if ( V_26 -> V_33 . V_34 -> V_52 )
V_75 |= V_79 | V_80 ;
break;
}
return V_75 ;
}
static long F_28 ( struct V_20 * V_20 , unsigned int V_81 ,
unsigned long V_82 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_83 )
return V_26 -> V_33 . V_34 -> V_83 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_81 , V_82 ) ;
break;
}
return - V_84 ;
}
static int F_29 ( struct V_20 * V_20 , struct V_85 * V_86 )
{
struct V_54 * V_54 = F_30 ( V_20 ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_87 )
return V_26 -> V_33 . V_34 -> V_87 ( V_26 ,
V_24 -> V_36 ,
V_54 , V_20 , V_86 ) ;
break;
}
return - V_45 ;
}
int T_7 F_31 ( void )
{
struct V_88 * V_57 ;
V_57 = F_32 ( L_15 , NULL ) ;
if ( V_57 == NULL )
return - V_10 ;
V_89 = V_57 ;
#ifdef F_33
{
struct V_25 * V_26 ;
if ( ( V_26 = F_34 ( V_90 , L_6 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_91 | V_92 | V_93 ;
if ( F_35 ( V_26 ) < 0 ) {
F_36 ( V_26 ) ;
return - V_10 ;
}
V_94 = V_26 ;
}
#endif
#if F_37 ( V_95 )
{
struct V_25 * V_26 ;
if ( ( V_26 = F_34 ( V_90 , L_11 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_91 | V_92 | V_93 ;
if ( F_35 ( V_26 ) < 0 ) {
F_36 ( V_26 ) ;
return - V_10 ;
}
V_96 = V_26 ;
}
#endif
F_38 () ;
F_39 () ;
F_40 () ;
F_41 () ;
return 0 ;
}
int T_8 F_42 ( void )
{
F_43 () ;
F_44 () ;
F_45 () ;
F_46 () ;
if ( V_89 ) {
#if F_37 ( V_95 )
F_36 ( V_96 ) ;
#endif
#ifdef F_33
F_36 ( V_94 ) ;
#endif
F_47 ( V_89 ) ;
}
return 0 ;
}
int F_48 ( struct V_97 * V_70 )
{
char V_1 [ 8 ] ;
struct V_25 * V_26 ;
if ( F_12 ( ! V_70 ) )
return - V_45 ;
sprintf ( V_1 , L_16 , V_70 -> V_98 ) ;
if ( ( V_26 = F_34 ( V_70 -> V_59 , V_1 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_91 | V_92 | V_93 ;
if ( F_35 ( V_26 ) < 0 ) {
F_36 ( V_26 ) ;
return - V_10 ;
}
V_70 -> V_99 = V_26 ;
return 0 ;
}
int F_49 ( struct V_97 * V_70 )
{
struct V_88 * V_57 ;
if ( F_12 ( ! V_70 ) )
return - V_45 ;
if ( ! strcmp ( V_70 -> V_100 , V_70 -> V_99 -> V_72 ) )
return 0 ;
V_57 = F_50 ( V_70 -> V_100 , V_89 , V_70 -> V_99 -> V_72 ) ;
if ( V_57 == NULL )
return - V_10 ;
V_70 -> V_101 = V_57 ;
return 0 ;
}
void F_51 ( struct V_97 * V_70 )
{
F_9 ( & V_56 ) ;
if ( V_70 -> V_101 ) {
F_47 ( V_70 -> V_101 ) ;
V_70 -> V_101 = NULL ;
}
if ( strcmp ( V_70 -> V_100 , V_70 -> V_99 -> V_72 ) )
V_70 -> V_101 = F_50 ( V_70 -> V_100 ,
V_89 ,
V_70 -> V_99 -> V_72 ) ;
F_10 ( & V_56 ) ;
}
void F_52 ( struct V_97 * V_70 )
{
if ( ! V_70 )
return;
F_9 ( & V_56 ) ;
F_47 ( V_70 -> V_101 ) ;
V_70 -> V_101 = NULL ;
if ( V_70 -> V_99 )
F_53 ( V_70 -> V_99 ) ;
F_10 ( & V_56 ) ;
}
int F_54 ( struct V_97 * V_70 )
{
if ( ! V_70 )
return 0 ;
F_36 ( V_70 -> V_99 ) ;
V_70 -> V_99 = NULL ;
return 0 ;
}
int F_55 ( struct V_4 * V_5 , char * line , int V_11 )
{
int V_33 = - 1 ;
if ( F_12 ( ! V_5 || ! V_5 -> V_5 ) )
return 1 ;
if ( V_11 <= 0 || V_5 -> V_15 || V_5 -> error )
return 1 ;
while ( ! V_5 -> V_15 ) {
V_33 = V_5 -> V_5 [ V_5 -> V_18 ++ ] ;
if ( V_5 -> V_18 >= V_5 -> V_16 )
V_5 -> V_15 = 1 ;
if ( V_33 == '\n' )
break;
if ( V_11 ) {
V_11 -- ;
* line ++ = V_33 ;
}
}
* line = '\0' ;
return 0 ;
}
const char * F_56 ( char * V_102 , const char * V_103 , int V_11 )
{
int V_33 ;
while ( * V_103 == ' ' || * V_103 == '\t' )
V_103 ++ ;
if ( * V_103 == '"' || * V_103 == '\'' ) {
V_33 = * V_103 ++ ;
while ( -- V_11 > 0 && * V_103 && * V_103 != V_33 ) {
* V_102 ++ = * V_103 ++ ;
}
if ( * V_103 == V_33 )
V_103 ++ ;
} else {
while ( -- V_11 > 0 && * V_103 && * V_103 != ' ' && * V_103 != '\t' ) {
* V_102 ++ = * V_103 ++ ;
}
}
* V_102 = 0 ;
while ( * V_103 == ' ' || * V_103 == '\t' )
V_103 ++ ;
return V_103 ;
}
static struct V_25 * F_57 ( const char * V_72 )
{
struct V_25 * V_26 ;
V_26 = F_20 ( sizeof( * V_26 ) , V_8 ) ;
if ( V_26 == NULL )
return NULL ;
V_26 -> V_72 = F_58 ( V_72 , V_8 ) ;
if ( V_26 -> V_72 == NULL ) {
F_22 ( V_26 ) ;
return NULL ;
}
V_26 -> V_55 = V_104 | V_92 ;
V_26 -> V_31 = V_47 ;
F_59 ( & V_26 -> V_30 ) ;
F_60 ( & V_26 -> V_105 ) ;
F_60 ( & V_26 -> V_106 ) ;
return V_26 ;
}
struct V_25 * F_34 ( struct V_59 * V_59 ,
const char * V_72 ,
struct V_25 * V_107 )
{
struct V_25 * V_26 = F_57 ( V_72 ) ;
if ( V_26 ) {
V_26 -> V_59 = V_59 ;
V_26 -> V_107 = V_107 ;
}
return V_26 ;
}
struct V_25 * F_61 ( struct V_97 * V_70 ,
const char * V_72 ,
struct V_25 * V_107 )
{
struct V_25 * V_26 = F_57 ( V_72 ) ;
if ( V_26 ) {
V_26 -> V_59 = V_70 -> V_59 ;
V_26 -> V_70 = V_70 ;
V_26 -> V_107 = V_107 ;
}
return V_26 ;
}
static void F_53 ( struct V_25 * V_26 )
{
struct V_108 * V_57 , * V_109 ;
struct V_88 * V_110 ;
F_62 (p, n, &entry->children) {
F_53 ( F_63 ( V_57 , struct V_25 , V_106 ) ) ;
}
if ( ! V_26 -> V_57 )
return;
F_64 ( & V_26 -> V_106 ) ;
V_110 = V_26 -> V_107 == NULL ? V_89 : V_26 -> V_107 -> V_57 ;
F_12 ( ! V_110 ) ;
F_47 ( V_26 -> V_57 ) ;
V_26 -> V_57 = NULL ;
}
static int F_65 ( struct V_111 * V_112 )
{
struct V_25 * V_26 = V_112 -> V_113 ;
F_36 ( V_26 ) ;
return 0 ;
}
static int F_66 ( struct V_111 * V_112 )
{
struct V_25 * V_26 = V_112 -> V_113 ;
return F_35 ( V_26 ) ;
}
int F_67 ( struct V_97 * V_70 , const char * V_72 ,
struct V_25 * * V_114 )
{
static struct V_115 V_34 = {
. V_116 = F_65 ,
. V_117 = F_66 ,
} ;
struct V_25 * V_26 ;
int V_14 ;
V_26 = F_61 ( V_70 , V_72 , V_70 -> V_99 ) ;
if ( ! V_26 )
return - V_10 ;
if ( ( V_14 = F_68 ( V_70 , V_118 , V_26 , & V_34 ) ) < 0 ) {
F_36 ( V_26 ) ;
return V_14 ;
}
if ( V_114 )
* V_114 = V_26 ;
return 0 ;
}
void F_36 ( struct V_25 * V_26 )
{
if ( V_26 == NULL )
return;
if ( V_26 -> V_57 ) {
F_9 ( & V_56 ) ;
F_53 ( V_26 ) ;
F_10 ( & V_56 ) ;
}
F_22 ( V_26 -> V_72 ) ;
if ( V_26 -> V_119 )
V_26 -> V_119 ( V_26 ) ;
F_22 ( V_26 ) ;
}
int F_35 ( struct V_25 * V_26 )
{
struct V_88 * V_110 , * V_57 = NULL ;
if ( F_12 ( ! V_26 ) )
return - V_45 ;
V_110 = V_26 -> V_107 == NULL ? V_89 : V_26 -> V_107 -> V_57 ;
F_9 ( & V_56 ) ;
if ( F_69 ( V_26 -> V_55 ) ) {
V_57 = F_70 ( V_26 -> V_72 , V_26 -> V_55 , V_110 ) ;
if ( ! V_57 ) {
F_10 ( & V_56 ) ;
return - V_10 ;
}
} else {
V_57 = F_71 ( V_26 -> V_72 , V_26 -> V_55 , V_110 ,
& V_120 , V_26 ) ;
if ( ! V_57 ) {
F_10 ( & V_56 ) ;
return - V_10 ;
}
F_72 ( V_57 , V_26 -> V_16 ) ;
}
V_26 -> V_57 = V_57 ;
if ( V_26 -> V_107 )
F_73 ( & V_26 -> V_106 , & V_26 -> V_107 -> V_105 ) ;
F_10 ( & V_56 ) ;
return 0 ;
}
static void F_74 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
F_5 ( V_5 ,
L_17 ,
F_75 () -> V_73 ) ;
}
static int T_7 F_38 ( void )
{
struct V_25 * V_26 ;
V_26 = F_34 ( V_90 , L_1 , NULL ) ;
if ( V_26 == NULL )
return - V_10 ;
V_26 -> V_33 . V_69 . V_50 = F_74 ;
if ( F_35 ( V_26 ) < 0 ) {
F_36 ( V_26 ) ;
return - V_10 ;
}
V_121 = V_26 ;
return 0 ;
}
static int T_8 F_46 ( void )
{
F_36 ( V_121 ) ;
return 0 ;
}
