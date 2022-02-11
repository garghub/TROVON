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
V_7 = F_4 ( V_5 -> V_5 , V_6 , V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_5 -> V_5 = V_7 ;
V_5 -> V_10 = V_6 ;
return 0 ;
}
int F_5 ( struct V_4 * V_5 , const char * V_11 , ... )
{
T_1 args ;
int V_10 , V_12 ;
int V_13 = 0 ;
F_6 () ;
if ( V_5 -> V_14 || V_5 -> error )
return 0 ;
V_10 = V_5 -> V_10 - V_5 -> V_15 ;
va_start ( args , V_11 ) ;
for (; ; ) {
T_1 V_16 ;
F_7 ( V_16 , args ) ;
V_12 = vsnprintf ( V_5 -> V_5 + V_5 -> V_17 , V_10 , V_11 , V_16 ) ;
va_end ( V_16 ) ;
if ( V_12 < V_10 )
break;
V_13 = F_2 ( V_5 , V_5 -> V_10 + V_18 ) ;
if ( V_13 < 0 )
break;
V_10 = V_5 -> V_10 - V_5 -> V_15 ;
}
va_end ( args ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_17 += V_12 ;
V_5 -> V_15 += V_12 ;
return V_12 ;
}
static void F_8 ( struct V_19 * V_20 ,
struct V_19 * V_21 )
{
if ( V_21 )
F_9 ( V_21 -> V_22 , V_20 ) ;
}
static T_2 F_10 ( struct V_23 * V_23 , T_2 V_24 , int V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_2 V_30 = - V_31 , V_15 ;
V_27 = V_23 -> V_32 ;
V_29 = V_27 -> V_29 ;
F_11 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 == V_35 &&
V_29 -> V_36 . V_37 -> V_38 ) {
V_24 = V_29 -> V_36 . V_37 -> V_38 ( V_29 ,
V_27 -> V_39 ,
V_23 , V_24 , V_25 ) ;
goto V_40;
}
if ( V_29 -> V_34 == V_35 )
V_15 = V_29 -> V_15 ;
else
V_15 = 0 ;
switch ( V_25 ) {
case V_41 :
break;
case V_42 :
V_24 += V_23 -> V_43 ;
break;
case V_44 :
if ( ! V_15 )
goto V_40;
V_24 += V_15 ;
break;
default:
goto V_40;
}
if ( V_24 < 0 )
goto V_40;
if ( V_15 && V_24 > V_15 )
V_24 = V_15 ;
V_23 -> V_43 = V_24 ;
V_30 = V_24 ;
V_40:
F_12 ( & V_29 -> V_33 ) ;
return V_30 ;
}
static T_3 F_13 ( struct V_23 * V_23 , char T_4 * V_5 ,
T_5 V_45 , T_2 * V_24 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_46 ;
T_5 V_15 = 0 ;
T_2 V_47 ;
V_27 = V_23 -> V_32 ;
if ( F_14 ( ! V_27 ) )
return - V_48 ;
V_47 = * V_24 ;
if ( V_47 < 0 || ( long ) V_47 != V_47 || ( T_3 ) V_45 < 0 )
return - V_49 ;
if ( ( unsigned long ) V_47 + ( unsigned long ) V_45 < ( unsigned long ) V_47 )
return - V_49 ;
V_29 = V_27 -> V_29 ;
switch ( V_29 -> V_34 ) {
case V_50 :
V_46 = V_27 -> V_51 ;
if ( V_46 == NULL )
return - V_49 ;
if ( V_47 >= V_46 -> V_15 )
return 0 ;
V_15 = V_46 -> V_15 - V_47 ;
V_15 = F_15 ( V_45 , V_15 ) ;
if ( F_16 ( V_5 , V_46 -> V_5 + V_47 , V_15 ) )
return - V_52 ;
break;
case V_35 :
if ( V_47 >= V_29 -> V_15 )
return 0 ;
if ( V_29 -> V_36 . V_37 -> V_53 ) {
V_15 = V_29 -> V_15 - V_47 ;
V_15 = F_15 ( V_45 , V_15 ) ;
V_15 = V_29 -> V_36 . V_37 -> V_53 ( V_29 ,
V_27 -> V_39 ,
V_23 , V_5 , V_15 , V_47 ) ;
}
break;
}
if ( ( T_3 ) V_15 > 0 )
* V_24 = V_47 + V_15 ;
return V_15 ;
}
static T_3 F_17 ( struct V_23 * V_23 , const char T_4 * V_5 ,
T_5 V_45 , T_2 * V_24 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_46 ;
T_3 V_15 = 0 ;
T_2 V_47 ;
V_27 = V_23 -> V_32 ;
if ( F_14 ( ! V_27 ) )
return - V_48 ;
V_29 = V_27 -> V_29 ;
V_47 = * V_24 ;
if ( V_47 < 0 || ( long ) V_47 != V_47 || ( T_3 ) V_45 < 0 )
return - V_49 ;
if ( ( unsigned long ) V_47 + ( unsigned long ) V_45 < ( unsigned long ) V_47 )
return - V_49 ;
switch ( V_29 -> V_34 ) {
case V_50 :
V_46 = V_27 -> V_54 ;
if ( V_46 == NULL )
return - V_49 ;
F_11 ( & V_29 -> V_33 ) ;
if ( V_47 + V_45 >= V_46 -> V_10 ) {
if ( F_2 ( V_46 , V_47 + V_45 ) ) {
F_12 ( & V_29 -> V_33 ) ;
return - V_9 ;
}
}
if ( F_18 ( V_46 -> V_5 + V_47 , V_5 , V_45 ) ) {
F_12 ( & V_29 -> V_33 ) ;
return - V_52 ;
}
V_46 -> V_15 = V_47 + V_45 ;
F_12 ( & V_29 -> V_33 ) ;
V_15 = V_45 ;
break;
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_55 && V_45 > 0 ) {
T_5 V_56 = V_29 -> V_15 - V_47 ;
V_45 = F_15 ( V_45 , V_56 ) ;
V_15 = V_29 -> V_36 . V_37 -> V_55 ( V_29 ,
V_27 -> V_39 ,
V_23 , V_5 , V_45 , V_47 ) ;
}
break;
}
if ( ( T_3 ) V_15 > 0 )
* V_24 = V_47 + V_15 ;
return V_15 ;
}
static int F_19 ( struct V_57 * V_57 , struct V_23 * V_23 )
{
struct V_28 * V_29 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
struct V_19 * V_58 ;
int V_59 , V_13 ;
F_11 ( & V_60 ) ;
V_58 = F_20 ( V_57 ) ;
V_29 = V_58 == NULL ? NULL : (struct V_28 * ) V_58 -> V_27 ;
if ( V_29 == NULL || ! V_29 -> V_58 ) {
F_12 ( & V_60 ) ;
return - V_61 ;
}
if ( ! F_21 ( V_29 -> V_62 ) ) {
V_13 = - V_52 ;
goto V_63;
}
V_59 = V_23 -> V_64 & V_65 ;
if ( V_59 == V_66 || V_59 == V_67 ) {
if ( ( V_29 -> V_34 == V_35 &&
V_29 -> V_36 . V_37 -> V_53 == NULL ) ) {
V_13 = - V_61 ;
goto V_68;
}
}
if ( V_59 == V_69 || V_59 == V_67 ) {
if ( ( V_29 -> V_34 == V_35 &&
V_29 -> V_36 . V_37 -> V_55 == NULL ) ) {
V_13 = - V_61 ;
goto V_68;
}
}
V_27 = F_22 ( sizeof( * V_27 ) , V_8 ) ;
if ( V_27 == NULL ) {
V_13 = - V_9 ;
goto V_68;
}
V_27 -> V_29 = V_29 ;
switch ( V_29 -> V_34 ) {
case V_50 :
if ( V_59 == V_66 || V_59 == V_67 ) {
V_5 = F_22 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_70;
V_27 -> V_51 = V_5 ;
V_5 -> V_10 = V_18 ;
V_5 -> V_5 = F_23 ( V_5 -> V_10 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_70;
}
if ( V_59 == V_69 || V_59 == V_67 ) {
V_5 = F_22 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_70;
V_27 -> V_54 = V_5 ;
V_5 -> V_10 = V_18 ;
V_5 -> V_5 = F_23 ( V_5 -> V_10 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_70;
}
break;
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_71 ) {
if ( ( V_13 = V_29 -> V_36 . V_37 -> V_71 ( V_29 , V_59 ,
& V_27 -> V_39 ) ) < 0 ) {
F_24 ( V_27 ) ;
goto V_68;
}
}
break;
}
V_23 -> V_32 = V_27 ;
F_12 ( & V_60 ) ;
if ( V_29 -> V_34 == V_50 &&
( V_59 == V_66 || V_59 == V_67 ) ) {
if ( V_29 -> V_36 . V_72 . V_53 ) {
F_11 ( & V_29 -> V_33 ) ;
V_29 -> V_36 . V_72 . V_53 ( V_29 , V_27 -> V_51 ) ;
F_12 ( & V_29 -> V_33 ) ;
}
}
return 0 ;
V_70:
if ( V_27 -> V_51 ) {
F_24 ( V_27 -> V_51 -> V_5 ) ;
F_24 ( V_27 -> V_51 ) ;
}
if ( V_27 -> V_54 ) {
F_24 ( V_27 -> V_54 -> V_5 ) ;
F_24 ( V_27 -> V_54 ) ;
}
F_24 ( V_27 ) ;
V_13 = - V_9 ;
V_68:
F_25 ( V_29 -> V_62 ) ;
V_63:
F_12 ( & V_60 ) ;
return V_13 ;
}
static int F_26 ( struct V_57 * V_57 , struct V_23 * V_23 )
{
struct V_28 * V_29 ;
struct V_26 * V_27 ;
int V_59 ;
V_59 = V_23 -> V_64 & V_65 ;
V_27 = V_23 -> V_32 ;
V_29 = V_27 -> V_29 ;
switch ( V_29 -> V_34 ) {
case V_50 :
if ( V_27 -> V_51 ) {
F_24 ( V_27 -> V_51 -> V_5 ) ;
F_24 ( V_27 -> V_51 ) ;
}
if ( V_27 -> V_54 ) {
if ( V_29 -> V_36 . V_72 . V_55 ) {
V_29 -> V_36 . V_72 . V_55 ( V_29 , V_27 -> V_54 ) ;
if ( V_27 -> V_54 -> error ) {
F_27 ( V_73 L_13 ,
V_29 -> V_22 ,
V_27 -> V_54 -> error ) ;
}
}
F_24 ( V_27 -> V_54 -> V_5 ) ;
F_24 ( V_27 -> V_54 ) ;
}
break;
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_74 )
V_29 -> V_36 . V_37 -> V_74 ( V_29 , V_59 ,
V_27 -> V_39 ) ;
break;
}
F_25 ( V_29 -> V_62 ) ;
F_24 ( V_27 ) ;
return 0 ;
}
static unsigned int F_28 ( struct V_23 * V_23 , T_6 * V_75 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
unsigned int V_76 ;
V_27 = V_23 -> V_32 ;
if ( V_27 == NULL )
return 0 ;
V_29 = V_27 -> V_29 ;
V_76 = 0 ;
switch ( V_29 -> V_34 ) {
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_77 )
return V_29 -> V_36 . V_37 -> V_77 ( V_29 ,
V_27 -> V_39 ,
V_23 , V_75 ) ;
if ( V_29 -> V_36 . V_37 -> V_53 )
V_76 |= V_78 | V_79 ;
if ( V_29 -> V_36 . V_37 -> V_55 )
V_76 |= V_80 | V_81 ;
break;
}
return V_76 ;
}
static long F_29 ( struct V_23 * V_23 , unsigned int V_82 ,
unsigned long V_83 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = V_23 -> V_32 ;
if ( V_27 == NULL )
return 0 ;
V_29 = V_27 -> V_29 ;
switch ( V_29 -> V_34 ) {
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_84 )
return V_29 -> V_36 . V_37 -> V_84 ( V_29 ,
V_27 -> V_39 ,
V_23 , V_82 , V_83 ) ;
break;
}
return - V_85 ;
}
static int F_30 ( struct V_23 * V_23 , struct V_86 * V_87 )
{
struct V_57 * V_57 = V_23 -> V_88 . V_89 -> V_90 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = V_23 -> V_32 ;
if ( V_27 == NULL )
return 0 ;
V_29 = V_27 -> V_29 ;
switch ( V_29 -> V_34 ) {
case V_35 :
if ( V_29 -> V_36 . V_37 -> V_91 )
return V_29 -> V_36 . V_37 -> V_91 ( V_29 ,
V_27 -> V_39 ,
V_57 , V_23 , V_87 ) ;
break;
}
return - V_48 ;
}
int T_7 F_31 ( void )
{
struct V_19 * V_58 ;
V_58 = F_32 ( L_14 , V_92 | V_93 | V_94 , NULL ) ;
if ( V_58 == NULL )
return - V_9 ;
V_95 = V_58 ;
#ifdef F_33
{
struct V_28 * V_29 ;
if ( ( V_29 = F_34 ( V_96 , L_6 , NULL ) ) == NULL )
return - V_9 ;
V_29 -> V_59 = V_92 | V_93 | V_94 ;
if ( F_35 ( V_29 ) < 0 ) {
F_36 ( V_29 ) ;
return - V_9 ;
}
V_97 = V_29 ;
}
#endif
#if F_37 ( V_98 ) || F_37 ( V_99 )
{
struct V_28 * V_29 ;
if ( ( V_29 = F_34 ( V_96 , L_11 , NULL ) ) == NULL )
return - V_9 ;
V_29 -> V_59 = V_92 | V_93 | V_94 ;
if ( F_35 ( V_29 ) < 0 ) {
F_36 ( V_29 ) ;
return - V_9 ;
}
V_100 = V_29 ;
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
if ( V_95 ) {
#if F_37 ( V_98 ) || F_37 ( V_99 )
F_36 ( V_100 ) ;
#endif
#ifdef F_33
F_36 ( V_97 ) ;
#endif
F_8 ( NULL , V_95 ) ;
}
return 0 ;
}
int F_47 ( struct V_101 * V_102 )
{
char V_1 [ 8 ] ;
struct V_28 * V_29 ;
if ( F_14 ( ! V_102 ) )
return - V_48 ;
sprintf ( V_1 , L_15 , V_102 -> V_103 ) ;
if ( ( V_29 = F_34 ( V_102 -> V_62 , V_1 , NULL ) ) == NULL )
return - V_9 ;
V_29 -> V_59 = V_92 | V_93 | V_94 ;
if ( F_35 ( V_29 ) < 0 ) {
F_36 ( V_29 ) ;
return - V_9 ;
}
V_102 -> V_104 = V_29 ;
return 0 ;
}
int F_48 ( struct V_101 * V_102 )
{
struct V_19 * V_58 ;
if ( F_14 ( ! V_102 ) )
return - V_48 ;
if ( ! strcmp ( V_102 -> V_105 , V_102 -> V_104 -> V_22 ) )
return 0 ;
V_58 = F_49 ( V_102 -> V_105 , V_95 , V_102 -> V_104 -> V_22 ) ;
if ( V_58 == NULL )
return - V_9 ;
V_102 -> V_106 = V_58 ;
return 0 ;
}
void F_50 ( struct V_101 * V_102 )
{
F_11 ( & V_60 ) ;
if ( V_102 -> V_106 ) {
F_8 ( V_95 , V_102 -> V_106 ) ;
V_102 -> V_106 = NULL ;
}
if ( strcmp ( V_102 -> V_105 , V_102 -> V_104 -> V_22 ) )
V_102 -> V_106 = F_49 ( V_102 -> V_105 ,
V_95 ,
V_102 -> V_104 -> V_22 ) ;
F_12 ( & V_60 ) ;
}
void F_51 ( struct V_101 * V_102 )
{
if ( ! V_102 )
return;
F_11 ( & V_60 ) ;
if ( V_102 -> V_106 ) {
F_8 ( V_95 , V_102 -> V_106 ) ;
V_102 -> V_106 = NULL ;
}
if ( V_102 -> V_104 )
F_52 ( V_102 -> V_104 ) ;
F_12 ( & V_60 ) ;
}
int F_53 ( struct V_101 * V_102 )
{
if ( ! V_102 )
return 0 ;
F_36 ( V_102 -> V_104 ) ;
V_102 -> V_104 = NULL ;
return 0 ;
}
int F_54 ( struct V_4 * V_5 , char * line , int V_10 )
{
int V_36 = - 1 ;
if ( V_10 <= 0 || V_5 -> V_14 || V_5 -> error )
return 1 ;
while ( -- V_10 > 0 ) {
V_36 = V_5 -> V_5 [ V_5 -> V_17 ++ ] ;
if ( V_36 == '\n' ) {
if ( V_5 -> V_17 >= V_5 -> V_15 )
V_5 -> V_14 = 1 ;
break;
}
* line ++ = V_36 ;
if ( V_5 -> V_17 >= V_5 -> V_15 ) {
V_5 -> V_14 = 1 ;
break;
}
}
while ( V_36 != '\n' && ! V_5 -> V_14 ) {
V_36 = V_5 -> V_5 [ V_5 -> V_17 ++ ] ;
if ( V_5 -> V_17 >= V_5 -> V_15 )
V_5 -> V_14 = 1 ;
}
* line = '\0' ;
return 0 ;
}
const char * F_55 ( char * V_107 , const char * V_108 , int V_10 )
{
int V_36 ;
while ( * V_108 == ' ' || * V_108 == '\t' )
V_108 ++ ;
if ( * V_108 == '"' || * V_108 == '\'' ) {
V_36 = * V_108 ++ ;
while ( -- V_10 > 0 && * V_108 && * V_108 != V_36 ) {
* V_107 ++ = * V_108 ++ ;
}
if ( * V_108 == V_36 )
V_108 ++ ;
} else {
while ( -- V_10 > 0 && * V_108 && * V_108 != ' ' && * V_108 != '\t' ) {
* V_107 ++ = * V_108 ++ ;
}
}
* V_107 = 0 ;
while ( * V_108 == ' ' || * V_108 == '\t' )
V_108 ++ ;
return V_108 ;
}
static struct V_28 * F_56 ( const char * V_22 )
{
struct V_28 * V_29 ;
V_29 = F_22 ( sizeof( * V_29 ) , V_8 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_22 = F_57 ( V_22 , V_8 ) ;
if ( V_29 -> V_22 == NULL ) {
F_24 ( V_29 ) ;
return NULL ;
}
V_29 -> V_59 = V_109 | V_93 ;
V_29 -> V_34 = V_50 ;
F_58 ( & V_29 -> V_33 ) ;
F_59 ( & V_29 -> V_110 ) ;
F_59 ( & V_29 -> V_111 ) ;
return V_29 ;
}
struct V_28 * F_34 ( struct V_62 * V_62 ,
const char * V_22 ,
struct V_28 * V_20 )
{
struct V_28 * V_29 = F_56 ( V_22 ) ;
if ( V_29 ) {
V_29 -> V_62 = V_62 ;
V_29 -> V_20 = V_20 ;
}
return V_29 ;
}
struct V_28 * F_60 ( struct V_101 * V_102 ,
const char * V_22 ,
struct V_28 * V_20 )
{
struct V_28 * V_29 = F_56 ( V_22 ) ;
if ( V_29 ) {
V_29 -> V_62 = V_102 -> V_62 ;
V_29 -> V_102 = V_102 ;
V_29 -> V_20 = V_20 ;
}
return V_29 ;
}
static void F_52 ( struct V_28 * V_29 )
{
struct V_112 * V_58 , * V_113 ;
struct V_19 * V_114 ;
F_61 (p, n, &entry->children) {
F_52 ( F_62 ( V_58 , struct V_28 , V_111 ) ) ;
}
if ( ! V_29 -> V_58 )
return;
F_63 ( & V_29 -> V_111 ) ;
V_114 = V_29 -> V_20 == NULL ? V_95 : V_29 -> V_20 -> V_58 ;
F_14 ( ! V_114 ) ;
F_8 ( V_114 , V_29 -> V_58 ) ;
V_29 -> V_58 = NULL ;
}
static int F_64 ( struct V_115 * V_116 )
{
struct V_28 * V_29 = V_116 -> V_117 ;
F_36 ( V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_115 * V_116 )
{
struct V_28 * V_29 = V_116 -> V_117 ;
return F_35 ( V_29 ) ;
}
int F_66 ( struct V_101 * V_102 , const char * V_22 ,
struct V_28 * * V_118 )
{
static struct V_119 V_37 = {
. V_120 = F_64 ,
. V_121 = F_65 ,
} ;
struct V_28 * V_29 ;
int V_13 ;
V_29 = F_60 ( V_102 , V_22 , V_102 -> V_104 ) ;
if ( ! V_29 )
return - V_9 ;
if ( ( V_13 = F_67 ( V_102 , V_122 , V_29 , & V_37 ) ) < 0 ) {
F_36 ( V_29 ) ;
return V_13 ;
}
if ( V_118 )
* V_118 = V_29 ;
return 0 ;
}
void F_36 ( struct V_28 * V_29 )
{
if ( V_29 == NULL )
return;
if ( V_29 -> V_58 ) {
F_11 ( & V_60 ) ;
F_52 ( V_29 ) ;
F_12 ( & V_60 ) ;
}
F_24 ( V_29 -> V_22 ) ;
if ( V_29 -> V_123 )
V_29 -> V_123 ( V_29 ) ;
F_24 ( V_29 ) ;
}
int F_35 ( struct V_28 * V_29 )
{
struct V_19 * V_114 , * V_58 = NULL ;
if ( F_14 ( ! V_29 ) )
return - V_48 ;
V_114 = V_29 -> V_20 == NULL ? V_95 : V_29 -> V_20 -> V_58 ;
F_11 ( & V_60 ) ;
V_58 = F_32 ( V_29 -> V_22 , V_29 -> V_59 , V_114 ) ;
if ( ! V_58 ) {
F_12 ( & V_60 ) ;
return - V_9 ;
}
if ( ! F_68 ( V_29 -> V_59 ) )
V_58 -> V_124 = & V_125 ;
V_58 -> V_15 = V_29 -> V_15 ;
V_58 -> V_27 = V_29 ;
V_29 -> V_58 = V_58 ;
if ( V_29 -> V_20 )
F_69 ( & V_29 -> V_111 , & V_29 -> V_20 -> V_110 ) ;
F_12 ( & V_60 ) ;
return 0 ;
}
static void F_70 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
F_5 (buffer,
L_16
CONFIG_SND_VERSION CONFIG_SND_DATE L_17
) ;
}
static int T_7 F_38 ( void )
{
struct V_28 * V_29 ;
V_29 = F_34 ( V_96 , L_1 , NULL ) ;
if ( V_29 == NULL )
return - V_9 ;
V_29 -> V_36 . V_72 . V_53 = F_70 ;
if ( F_35 ( V_29 ) < 0 ) {
F_36 ( V_29 ) ;
return - V_9 ;
}
V_126 = V_29 ;
return 0 ;
}
static int T_8 F_46 ( void )
{
F_36 ( V_126 ) ;
return 0 ;
}
