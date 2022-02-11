int F_1 ( char * V_1 , T_1 V_2 , const char * V_3 , ... )
{
int V_4 ;
T_2 V_5 ;
va_start ( V_5 , V_3 ) ;
V_4 = vsnprintf ( V_1 , V_2 , V_3 , V_5 ) ;
va_end ( V_5 ) ;
if ( V_4 >= ( int ) V_2 )
V_4 = - V_6 ;
return V_4 ;
}
int F_2 ( bool V_7 )
{
int V_4 ;
V_8 . V_9 = true ;
V_8 . V_10 = true ;
V_4 = F_3 ( NULL ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 ) ;
goto V_11;
}
if ( V_12 || V_7 )
return 0 ;
if ( V_8 . V_13 )
F_4 ( L_2 , V_8 . V_13 ) ;
V_12 = F_5 () ;
if ( ! V_12 ) {
F_4 ( L_3 ) ;
F_6 () ;
V_4 = - 1 ;
}
V_11:
if ( V_4 < 0 )
F_7 ( L_4 ) ;
return V_4 ;
}
void F_8 ( void )
{
F_9 ( V_12 ) ;
V_12 = NULL ;
F_6 () ;
}
static struct V_14 * F_10 ( const char * V_15 ,
struct V_16 * * V_17 )
{
return F_11 ( V_12 , V_15 , V_17 ) ;
}
static struct V_14 * F_12 ( T_3 V_18 , struct V_16 * * V_17 )
{
return F_13 ( V_12 , V_18 , V_17 ) ;
}
static struct V_19 * F_14 ( void )
{
struct V_20 * V_20 ;
struct V_16 * V_16 = F_15 ( V_12 ) ;
if ( F_16 ( V_16 ) < 0 )
return NULL ;
V_20 = F_17 ( V_16 ) ;
if ( ! V_20 )
return NULL ;
return V_20 -> V_19 ;
}
static int F_18 ( const char * V_15 , T_3 * V_18 ,
bool V_21 , bool V_22 )
{
struct V_19 * V_23 ;
struct V_14 * V_24 ;
struct V_16 * V_16 ;
V_23 = F_14 () ;
if ( V_23 && strcmp ( V_15 , V_23 -> V_15 ) == 0 )
* V_18 = ( V_21 ) ? V_23 -> V_18 : V_23 -> V_25 ;
else {
V_24 = F_10 ( V_15 , & V_16 ) ;
if ( ! V_24 )
return - V_26 ;
* V_18 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) -
( ( V_21 ) ? 0 : V_16 -> V_21 ) -
( ( V_22 ) ? V_16 -> V_28 : 0 ) ;
}
return 0 ;
}
static struct V_16 * F_19 ( const char * V_29 )
{
struct V_30 * V_31 = & V_12 -> V_32 ;
struct V_33 * V_33 = & V_31 -> V_33 [ V_34 ] ;
struct V_16 * V_35 ;
if ( V_29 && strchr ( V_29 , '/' ) )
return F_20 ( V_29 ) ;
if ( ! V_29 )
V_29 = L_5 ;
for ( V_35 = F_21 ( V_33 ) ; V_35 ; V_35 = F_22 ( V_35 ) ) {
if ( strncmp ( V_35 -> V_36 -> V_37 + 1 , V_29 ,
V_35 -> V_36 -> V_38 - 2 ) == 0 &&
V_29 [ V_35 -> V_36 -> V_38 - 2 ] == '\0' ) {
F_23 ( V_35 ) ;
return V_35 ;
}
}
return NULL ;
}
struct V_16 * F_24 ( const char * V_39 , struct V_40 * V_41 , bool V_42 )
{
if ( V_42 ) {
struct V_16 * V_16 ;
V_16 = F_20 ( V_39 ) ;
if ( V_16 && V_16 -> V_36 )
V_16 -> V_36 -> V_40 = F_25 ( V_41 ) ;
return V_16 ;
} else {
return F_19 ( V_39 ) ;
}
}
static int F_26 ( const char * V_43 , char * * V_44 )
{
char * V_45 , * V_46 , * V_47 ;
char V_48 [ 64 ] ;
int V_4 ;
V_47 = F_27 ( V_43 ) ;
if ( ! V_47 )
return - V_49 ;
V_45 = F_28 ( V_47 ) ;
if ( ! V_45 ) {
V_4 = - V_50 ;
goto V_11;
}
for ( V_46 = V_45 ; * V_46 != '\0' ; V_46 ++ ) {
if ( ! isalnum ( * V_46 ) && * V_46 != '_' ) {
* V_46 = '\0' ;
break;
}
}
V_4 = F_1 ( V_48 , 64 , L_6 , V_51 , V_45 ) ;
if ( V_4 < 0 )
goto V_11;
* V_44 = F_27 ( V_48 ) ;
V_4 = * V_44 ? 0 : - V_49 ;
V_11:
free ( V_47 ) ;
return V_4 ;
}
static void F_29 ( struct V_52 * V_53 )
{
free ( V_53 -> V_54 ) ;
free ( V_53 -> V_55 ) ;
free ( V_53 -> V_56 ) ;
}
static void F_30 ( struct V_57 * V_58 , int V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ )
F_31 ( V_58 + V_60 ) ;
}
static bool F_32 ( const char * V_14 , unsigned long V_61 )
{
T_3 V_62 = 0 ;
int V_4 ;
V_4 = F_18 ( L_7 , & V_62 ,
false , false ) ;
if ( V_4 == 0 && V_62 < V_61 )
F_7 ( L_8 , V_14 ) ;
else if ( F_33 ( V_61 ) )
F_7 ( L_9 , V_14 ) ;
else
return false ;
return true ;
}
static char * F_34 ( const char * V_29 )
{
int V_63 ;
T_4 * V_64 ;
T_5 V_65 ;
T_6 V_66 ;
T_7 * V_67 ;
T_8 * V_68 ;
char * V_69 = NULL ;
int V_70 ;
V_63 = F_35 ( V_29 , V_71 ) ;
if ( V_63 < 0 )
return NULL ;
V_64 = F_36 ( V_63 , V_72 , NULL ) ;
if ( V_64 == NULL )
goto V_73;
if ( F_37 ( V_64 , & V_65 ) == NULL )
goto V_74;
V_68 = F_38 ( V_64 , & V_65 , & V_66 ,
L_10 , NULL ) ;
if ( ! V_68 )
goto V_74;
V_67 = F_39 ( V_68 , NULL ) ;
if ( ! V_67 || ! V_67 -> V_75 )
goto V_74;
if ( V_65 . V_76 [ V_77 ] == V_78 )
V_70 = 12 ;
else
V_70 = 24 ;
V_69 = F_27 ( ( char * ) V_67 -> V_75 + V_70 ) ;
V_74:
F_40 ( V_64 ) ;
V_73:
F_41 ( V_63 ) ;
return V_69 ;
}
static int F_42 ( const char * V_29 , struct V_36 * * V_79 )
{
struct V_36 * V_36 ;
struct V_16 * V_16 ;
const char * V_13 ;
int V_4 = 0 ;
if ( V_29 ) {
char V_80 [ 128 ] ;
snprintf ( V_80 , sizeof( V_80 ) , L_11 , V_29 ) ;
V_16 = F_43 ( & V_12 -> V_32 , V_34 , V_80 ) ;
if ( V_16 ) {
V_36 = V_16 -> V_36 ;
goto V_81;
}
F_4 ( L_12 , V_29 ) ;
return - V_26 ;
}
V_16 = F_15 ( V_12 ) ;
V_36 = V_16 -> V_36 ;
V_13 = V_8 . V_13 ;
V_36 -> V_82 = 0 ;
if ( V_13 )
V_4 = F_44 ( V_36 , V_16 , V_13 , false ) ;
else
V_4 = F_45 ( V_36 , V_16 ) ;
V_81:
* V_79 = V_36 ;
return V_4 ;
}
static int F_46 ( struct V_83 * V_84 ,
struct V_52 * V_53 ,
struct V_52 * V_44 ,
const char * V_39 , struct V_40 * V_41 ,
bool V_85 )
{
struct V_16 * V_16 = NULL ;
struct V_14 * V_24 ;
T_3 V_61 = 0 ;
int V_4 = - V_26 ;
if ( ! V_53 -> V_55 || V_53 -> V_54 )
return - V_86 ;
V_16 = F_24 ( V_39 , V_41 , V_85 ) ;
if ( ! V_16 )
return - V_50 ;
F_47 (map, pp->function, sym) {
if ( V_85 )
V_61 = V_24 -> V_28 ;
else
V_61 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) - V_16 -> V_21 ;
break;
}
if ( ! V_61 ) {
V_4 = - V_26 ;
goto V_11;
}
F_4 ( L_13 V_87 L_14 ,
V_53 -> V_55 , V_61 ) ;
V_4 = F_48 ( V_84 , ( unsigned long ) V_61 ,
V_44 ) ;
if ( V_4 <= 0 )
V_4 = ( ! V_4 ) ? - V_26 : V_4 ;
else {
V_44 -> V_88 += V_53 -> V_88 ;
V_44 -> line += V_53 -> line ;
V_44 -> V_89 = V_53 -> V_89 ;
V_4 = 0 ;
}
V_11:
F_49 ( V_16 ) ;
return V_4 ;
}
static int F_50 ( struct V_83 * V_84 ,
struct V_90 * V_91 ,
struct V_52 * V_92 )
{
int V_4 ;
memcpy ( V_92 , & V_91 -> V_93 , sizeof( * V_92 ) ) ;
memset ( & V_91 -> V_93 , 0 , sizeof( V_91 -> V_93 ) ) ;
V_4 = F_46 ( V_84 , V_92 , & V_91 -> V_93 , V_91 -> V_39 ,
V_91 -> V_41 , V_91 -> V_85 ) ;
if ( V_4 < 0 )
memcpy ( & V_91 -> V_93 , V_92 , sizeof( * V_92 ) ) ;
return V_4 ;
}
static int F_51 ( struct V_83 * V_84 ,
struct V_94 * V_95 ,
const char * V_39 , bool V_42 )
{
struct V_52 V_53 = { . V_55 = V_95 -> V_55 ,
. V_54 = V_95 -> V_54 ,
. line = V_95 -> V_28 } ;
struct V_52 V_44 ;
int V_4 , V_96 = 0 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
if ( V_95 -> V_97 != V_98 )
V_96 = V_95 -> V_97 - V_95 -> V_28 ;
V_4 = F_46 ( V_84 , & V_53 , & V_44 ,
V_39 , NULL , V_42 ) ;
if ( ! V_4 ) {
V_95 -> V_55 = V_44 . V_55 ;
V_95 -> V_54 = V_44 . V_54 ;
V_95 -> V_28 = V_44 . line ;
if ( V_95 -> V_97 != V_98 )
V_95 -> V_97 = V_95 -> V_28 + V_96 ;
F_29 ( & V_53 ) ;
}
return V_4 ;
}
static struct V_83 * F_52 ( const char * V_29 , struct V_40 * V_41 ,
bool V_99 )
{
const char * V_100 = V_29 ;
char V_101 [ V_102 ] ;
struct V_83 * V_4 = NULL ;
struct V_36 * V_36 = NULL ;
struct V_103 V_104 ;
int V_105 ;
if ( ! V_29 || ! strchr ( V_29 , '/' ) ) {
V_105 = F_42 ( V_29 , & V_36 ) ;
if ( V_105 < 0 ) {
if ( ! V_36 || V_36 -> V_82 == 0 ) {
if ( ! F_53 ( - V_105 , V_101 , V_102 ) )
strcpy ( V_101 , L_15 ) ;
} else
F_54 ( V_36 , V_101 , V_102 ) ;
if ( ! V_99 )
F_55 ( L_16 ,
V_29 ? : L_5 , V_101 ) ;
return NULL ;
}
V_100 = V_36 -> V_106 ;
}
F_56 ( V_41 , & V_104 ) ;
V_4 = F_57 ( V_100 ) ;
if ( ! V_4 && ! V_99 ) {
F_7 ( L_17 , V_100 ) ;
if ( ! V_29 || ! F_58 ( V_100 , L_18 ) )
F_7 ( L_19 ) ;
else
F_7 ( L_20 ) ;
F_7 ( L_21 ) ;
}
F_59 ( & V_104 ) ;
return V_4 ;
}
static struct V_83 * F_60 ( const char * V_29 , bool V_99 )
{
const char * V_100 = V_29 ;
if ( ! V_29 )
V_100 = L_5 ;
if ( V_107 && ! strcmp ( V_107 , V_100 ) )
goto V_11;
free ( V_107 ) ;
V_107 = F_27 ( V_100 ) ;
if ( ! V_107 ) {
F_61 ( V_108 ) ;
V_108 = NULL ;
goto V_11;
}
V_108 = F_52 ( V_29 , NULL , V_99 ) ;
if ( ! V_108 )
F_62 ( & V_107 ) ;
V_11:
return V_108 ;
}
static void F_63 ( void )
{
F_61 ( V_108 ) ;
V_108 = NULL ;
F_62 ( & V_107 ) ;
}
static int F_64 ( const char * V_43 , unsigned long * V_61 ,
struct V_40 * V_41 )
{
T_4 * V_64 ;
T_5 V_65 ;
T_6 V_66 ;
int V_63 , V_4 = - V_26 ;
struct V_103 V_104 ;
F_56 ( V_41 , & V_104 ) ;
V_63 = F_35 ( V_43 , V_71 ) ;
F_59 ( & V_104 ) ;
if ( V_63 < 0 )
return - V_109 ;
V_64 = F_36 ( V_63 , V_72 , NULL ) ;
if ( V_64 == NULL ) {
V_4 = - V_50 ;
goto V_110;
}
if ( F_37 ( V_64 , & V_65 ) == NULL )
goto V_11;
if ( ! F_38 ( V_64 , & V_65 , & V_66 , L_22 , NULL ) )
goto V_11;
* V_61 = V_66 . V_111 - V_66 . V_112 ;
V_4 = 0 ;
V_11:
F_40 ( V_64 ) ;
V_110:
F_41 ( V_63 ) ;
return V_4 ;
}
static int F_65 ( struct V_113 * V_114 ,
struct V_52 * V_53 ,
bool V_115 )
{
struct V_83 * V_84 = NULL ;
unsigned long V_116 = 0 ;
T_3 V_18 = V_114 -> V_61 ;
int V_4 = - V_26 ;
if ( ! V_115 ) {
if ( ! V_18 ) {
V_4 = - V_50 ;
goto error;
}
V_4 = F_64 ( V_114 -> V_29 , & V_116 , NULL ) ;
if ( V_4 < 0 )
goto error;
V_18 += V_116 ;
} else if ( V_114 -> V_14 ) {
V_4 = F_18 ( V_114 -> V_14 , & V_18 ,
false , ! ! V_114 -> V_29 ) ;
if ( V_4 != 0 )
goto error;
V_18 += V_114 -> V_88 ;
}
F_4 ( L_23 V_87 L_24 , V_18 ,
V_114 -> V_29 ? : L_5 ) ;
V_84 = F_60 ( V_114 -> V_29 , V_117 <= 0 ) ;
if ( V_84 )
V_4 = F_48 ( V_84 ,
( unsigned long ) V_18 , V_53 ) ;
else
V_4 = - V_26 ;
if ( V_4 > 0 ) {
V_53 -> V_89 = V_114 -> V_89 ;
return 0 ;
}
error:
F_4 ( L_25 ) ;
return V_4 ? : - V_26 ;
}
static int F_66 ( struct V_113 * V_114 ,
struct V_16 * V_16 , unsigned long V_118 )
{
struct V_14 * V_24 ;
T_3 V_18 = V_114 -> V_61 - V_118 ;
V_24 = F_67 ( V_16 , V_18 ) ;
if ( ! V_24 )
return - V_26 ;
if ( strcmp ( V_24 -> V_15 , V_114 -> V_14 ) ) {
if ( ! V_114 -> V_119 )
V_114 -> V_119 = V_114 -> V_14 ;
else
free ( V_114 -> V_14 ) ;
V_114 -> V_14 = F_27 ( V_24 -> V_15 ) ;
if ( ! V_114 -> V_14 )
return - V_49 ;
}
V_114 -> V_88 = V_18 - V_24 -> V_28 ;
V_114 -> V_61 -= V_118 ;
return 0 ;
}
static int
F_68 ( struct V_57 * V_58 ,
int V_59 , const char * V_120 )
{
struct V_16 * V_16 ;
unsigned long V_116 = 0 ;
int V_60 , V_4 = 0 ;
V_16 = F_20 ( V_120 ) ;
if ( ! V_16 || F_64 ( V_120 , & V_116 , NULL ) < 0 ) {
F_7 ( L_26 , V_120 ) ;
return - V_50 ;
}
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_4 = F_66 ( & V_58 [ V_60 ] . V_93 ,
V_16 , V_116 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_16 ) ;
return V_4 ;
}
static int F_69 ( struct V_57 * V_58 ,
int V_59 , const char * V_43 ,
struct V_40 * V_41 )
{
int V_60 , V_4 = 0 ;
unsigned long V_116 = 0 ;
if ( ! V_43 )
return 0 ;
V_4 = F_64 ( V_43 , & V_116 , V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_60 = 0 ; V_60 < V_59 && V_4 >= 0 ; V_60 ++ ) {
V_58 [ V_60 ] . V_93 . V_61 -= V_116 ;
V_58 [ V_60 ] . V_93 . V_29 = F_27 ( V_43 ) ;
if ( ! V_58 [ V_60 ] . V_93 . V_29 ) {
V_4 = - V_49 ;
break;
}
V_58 [ V_60 ] . V_85 = true ;
}
return V_4 ;
}
static int
F_70 ( struct V_57 * V_58 ,
int V_59 , const char * V_29 ,
struct V_83 * V_84 )
{
T_9 V_121 = 0 ;
int V_60 , V_4 = 0 ;
char * V_69 = NULL ;
struct V_16 * V_16 ;
if ( ! V_29 )
return 0 ;
V_16 = F_24 ( V_29 , NULL , false ) ;
if ( ! V_16 || F_71 ( V_84 , & V_121 , true ) < 0 ) {
F_7 ( L_26 , V_29 ) ;
return - V_50 ;
}
V_69 = F_34 ( V_29 ) ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_4 = F_66 ( & V_58 [ V_60 ] . V_93 ,
V_16 , ( unsigned long ) V_121 ) ;
if ( V_4 < 0 )
break;
V_58 [ V_60 ] . V_93 . V_29 =
F_27 ( V_69 ? V_69 : V_29 ) ;
if ( ! V_58 [ V_60 ] . V_93 . V_29 ) {
V_4 = - V_49 ;
break;
}
}
free ( V_69 ) ;
F_49 ( V_16 ) ;
return V_4 ;
}
static int
F_72 ( struct V_57 * V_58 ,
int V_59 )
{
struct V_19 * V_23 ;
char * V_92 ;
int V_60 , V_122 = 0 ;
if ( V_8 . V_123 )
return F_68 ( V_58 , V_59 ,
V_8 . V_13 ) ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
return - V_50 ;
}
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
if ( ! V_58 [ V_60 ] . V_93 . V_61 )
continue;
if ( V_58 [ V_60 ] . V_93 . V_89 && ! F_73 () )
continue;
if ( F_32 ( V_58 [ V_60 ] . V_93 . V_14 ,
V_58 [ V_60 ] . V_93 . V_61 ) ) {
V_92 = NULL ;
V_122 ++ ;
} else {
V_92 = F_27 ( V_23 -> V_15 ) ;
if ( ! V_92 )
return - V_49 ;
}
if ( ! V_58 [ V_60 ] . V_93 . V_119 )
V_58 [ V_60 ] . V_93 . V_119 = V_58 [ V_60 ] . V_93 . V_14 ;
else
free ( V_58 [ V_60 ] . V_93 . V_14 ) ;
V_58 [ V_60 ] . V_93 . V_14 = V_92 ;
V_58 [ V_60 ] . V_93 . V_88 = V_58 [ V_60 ] . V_93 . V_61 -
V_23 -> V_25 ;
}
return V_122 ;
}
void __weak
F_74 ( struct V_90 * V_91 V_124 ,
int V_59 V_124 )
{
}
static int F_75 ( struct V_90 * V_91 ,
struct V_57 * V_58 ,
int V_59 , const char * V_29 ,
bool V_125 , struct V_83 * V_84 )
{
int V_4 ;
if ( V_125 )
V_4 = F_69 ( V_58 , V_59 , V_29 ,
V_91 -> V_41 ) ;
else if ( V_29 )
V_4 = F_70 ( V_58 , V_59 ,
V_29 , V_84 ) ;
else
V_4 = F_72 ( V_58 , V_59 ) ;
if ( V_4 >= 0 )
F_74 ( V_91 , V_59 ) ;
return V_4 ;
}
static int F_76 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
bool V_126 = F_77 ( V_91 ) ;
struct V_52 V_92 ;
struct V_83 * V_84 ;
int V_59 , V_4 = 0 ;
V_84 = F_52 ( V_91 -> V_39 , V_91 -> V_41 , ! V_126 ) ;
if ( ! V_84 ) {
if ( V_126 )
return - V_26 ;
F_4 ( L_28 ) ;
return 0 ;
}
F_4 ( L_29 ) ;
V_59 = F_78 ( V_84 , V_91 , V_58 ) ;
if ( V_59 == 0 ) {
V_4 = F_50 ( V_84 , V_91 , & V_92 ) ;
if ( ! V_4 ) {
V_59 = F_78 ( V_84 , V_91 , V_58 ) ;
F_29 ( & V_91 -> V_93 ) ;
memcpy ( & V_91 -> V_93 , & V_92 , sizeof( V_92 ) ) ;
}
}
if ( V_59 > 0 ) {
F_4 ( L_30 , V_59 ) ;
V_4 = F_75 ( V_91 , * V_58 , V_59 ,
V_91 -> V_39 , V_91 -> V_85 , V_84 ) ;
if ( V_4 < 0 || V_4 == V_59 ) {
F_4 ( L_31 , V_4 ) ;
F_30 ( * V_58 , V_59 ) ;
F_62 ( V_58 ) ;
V_59 = 0 ;
}
}
F_61 ( V_84 ) ;
if ( V_59 == 0 ) {
F_7 ( L_32 ,
F_79 ( & V_91 -> V_93 ) ) ;
return - V_26 ;
} else if ( V_59 < 0 ) {
F_4 ( L_33 , V_59 ) ;
if ( V_59 == - V_127 )
F_7 ( L_34
L_35 ) ;
if ( ! V_126 ) {
F_4 ( L_36 ) ;
return 0 ;
}
}
return V_59 ;
}
static int F_80 ( T_10 * V_128 , int V_129 , bool V_130 , bool V_131 )
{
char V_48 [ V_132 ] , V_133 [ V_102 ] ;
const char * V_134 = V_131 ? L_37 : V_135 ;
const char * V_136 = NULL ;
do {
if ( fgets ( V_48 , V_132 , V_128 ) == NULL )
goto error;
if ( V_130 )
continue;
if ( ! V_136 ) {
V_136 = V_131 ? L_38 : L_39 ;
F_81 ( stdout , V_134 , V_136 , V_129 ) ;
}
F_81 ( stdout , V_134 , L_40 , V_48 ) ;
} while ( strchr ( V_48 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_128 ) ) {
F_7 ( L_41 ,
F_53 ( V_109 , V_133 , sizeof( V_133 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_82 ( T_10 * V_128 , int V_129 , bool V_130 , bool V_131 )
{
int V_137 = F_80 ( V_128 , V_129 , V_130 , V_131 ) ;
if ( V_137 == 0 ) {
F_7 ( L_42 ) ;
V_137 = - 1 ;
}
return V_137 ;
}
static int F_83 ( struct V_94 * V_95 , const char * V_29 ,
bool V_42 )
{
int V_129 = 1 ;
struct V_138 * V_139 ;
struct V_83 * V_84 ;
T_10 * V_128 ;
int V_4 ;
char * V_92 ;
char V_133 [ V_102 ] ;
V_84 = F_52 ( V_29 , NULL , false ) ;
if ( ! V_84 )
return - V_26 ;
V_4 = F_84 ( V_84 , V_95 ) ;
if ( ! V_4 ) {
V_4 = F_51 ( V_84 , V_95 , V_29 , V_42 ) ;
if ( ! V_4 )
V_4 = F_84 ( V_84 , V_95 ) ;
}
F_61 ( V_84 ) ;
if ( V_4 == 0 || V_4 == - V_26 ) {
F_7 ( L_43 ) ;
return - V_26 ;
} else if ( V_4 < 0 ) {
F_7 ( L_44 ) ;
return V_4 ;
}
V_92 = V_95 -> V_100 ;
V_4 = F_85 ( V_92 , V_95 -> V_140 , & V_95 -> V_100 ) ;
if ( V_92 != V_95 -> V_100 )
free ( V_92 ) ;
if ( V_4 < 0 ) {
F_7 ( L_45 ) ;
return V_4 ;
}
F_86 () ;
if ( V_95 -> V_55 )
fprintf ( stdout , L_46 , V_95 -> V_55 , V_95 -> V_100 ,
V_95 -> V_28 - V_95 -> V_88 ) ;
else
fprintf ( stdout , L_47 , V_95 -> V_100 , V_95 -> V_28 ) ;
V_128 = fopen ( V_95 -> V_100 , L_48 ) ;
if ( V_128 == NULL ) {
F_7 ( L_49 , V_95 -> V_100 ,
F_53 ( V_109 , V_133 , sizeof( V_133 ) ) ) ;
return - V_109 ;
}
while ( V_129 < V_95 -> V_28 ) {
V_4 = F_87 ( V_128 , V_129 ++ ) ;
if ( V_4 < 0 )
goto V_97;
}
F_88 (ln, lr->line_list) {
for (; V_139 -> V_60 > V_129 ; V_129 ++ ) {
V_4 = F_89 ( V_128 , V_129 - V_95 -> V_88 ) ;
if ( V_4 < 0 )
goto V_97;
}
V_4 = F_90 ( V_128 , V_129 ++ - V_95 -> V_88 ) ;
if ( V_4 < 0 )
goto V_97;
}
if ( V_95 -> V_97 == V_98 )
V_95 -> V_97 = V_129 + V_141 ;
while ( V_129 <= V_95 -> V_97 ) {
V_4 = F_91 ( V_128 , V_129 ++ - V_95 -> V_88 ) ;
if ( V_4 <= 0 )
break;
}
V_97:
fclose ( V_128 ) ;
return V_4 ;
}
int F_92 ( struct V_94 * V_95 , const char * V_29 ,
struct V_40 * V_41 , bool V_42 )
{
int V_4 ;
struct V_103 V_104 ;
V_4 = F_2 ( V_42 ) ;
if ( V_4 < 0 )
return V_4 ;
F_56 ( V_41 , & V_104 ) ;
V_4 = F_83 ( V_95 , V_29 , V_42 ) ;
F_59 ( & V_104 ) ;
F_8 () ;
return V_4 ;
}
static int F_93 ( struct V_83 * V_84 ,
struct V_90 * V_91 ,
struct V_142 * V_143 )
{
char * V_48 ;
int V_4 , V_60 , V_144 ;
struct V_145 * V_146 ;
struct V_147 * V_148 = NULL , * V_149 ;
struct V_52 V_92 ;
const char * V_150 ;
V_48 = F_79 ( & V_91 -> V_93 ) ;
if ( ! V_48 )
return - V_50 ;
F_4 ( L_50 , V_48 ) ;
V_4 = F_94 ( V_84 , V_91 , & V_148 ) ;
if ( ! V_4 ) {
V_4 = F_50 ( V_84 , V_91 , & V_92 ) ;
if ( ! V_4 ) {
V_4 = F_94 ( V_84 , V_91 ,
& V_148 ) ;
F_29 ( & V_92 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_26 ) {
F_55 ( L_51 , V_48 ) ;
V_4 = - V_26 ;
} else
F_7 ( L_44 ) ;
goto V_97;
}
fprintf ( stdout , L_52 , V_48 ) ;
for ( V_60 = 0 ; V_60 < V_4 ; V_60 ++ ) {
V_149 = & V_148 [ V_60 ] ;
fprintf ( stdout , L_53 , V_149 -> V_93 . V_14 ,
V_149 -> V_93 . V_88 ) ;
F_62 ( & V_149 -> V_93 . V_14 ) ;
V_144 = 0 ;
if ( V_149 -> V_151 ) {
F_95 (node, vl->vars) {
V_150 = strchr ( V_146 -> V_152 , '\t' ) + 1 ;
if ( F_96 ( V_143 , V_150 ) ) {
fprintf ( stdout , L_54 , V_146 -> V_152 ) ;
V_144 ++ ;
}
}
F_97 ( V_149 -> V_151 ) ;
}
if ( V_144 == 0 )
fprintf ( stdout , L_55 ) ;
}
free ( V_148 ) ;
V_97:
free ( V_48 ) ;
return V_4 ;
}
int F_98 ( struct V_90 * V_153 , int V_154 ,
struct V_142 * V_143 )
{
int V_60 , V_4 = 0 ;
struct V_83 * V_84 ;
V_4 = F_2 ( V_153 -> V_85 ) ;
if ( V_4 < 0 )
return V_4 ;
V_84 = F_52 ( V_153 -> V_39 , V_153 -> V_41 , false ) ;
if ( ! V_84 ) {
V_4 = - V_26 ;
goto V_11;
}
F_86 () ;
for ( V_60 = 0 ; V_60 < V_154 && V_4 >= 0 ; V_60 ++ )
V_4 = F_93 ( V_84 , & V_153 [ V_60 ] , V_143 ) ;
F_61 ( V_84 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_63 ( void )
{
}
static int
F_65 ( struct V_113 * V_114 V_124 ,
struct V_52 * V_53 V_124 ,
bool V_115 V_124 )
{
return - V_155 ;
}
static int F_76 ( struct V_90 * V_91 ,
struct V_57 * * V_58 V_124 )
{
if ( F_77 ( V_91 ) ) {
F_7 ( L_56 ) ;
return - V_155 ;
}
return 0 ;
}
int F_92 ( struct V_94 * V_95 V_124 ,
const char * V_29 V_124 ,
struct V_40 * V_41 V_124 ,
bool V_42 V_124 )
{
F_7 ( L_56 ) ;
return - V_155 ;
}
int F_98 ( struct V_90 * V_153 V_124 ,
int V_154 V_124 ,
struct V_142 * T_11 V_124 )
{
F_7 ( L_56 ) ;
return - V_155 ;
}
void F_99 ( struct V_94 * V_95 )
{
free ( V_95 -> V_55 ) ;
free ( V_95 -> V_54 ) ;
free ( V_95 -> V_100 ) ;
free ( V_95 -> V_140 ) ;
F_100 ( V_95 -> V_156 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
}
int F_101 ( struct V_94 * V_95 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_156 = F_102 ( NULL ) ;
if ( ! V_95 -> V_156 )
return - V_49 ;
else
return 0 ;
}
static int F_103 ( char * * V_157 , int * V_158 , const char * V_159 )
{
const char * V_28 = * V_157 ;
V_109 = 0 ;
* V_158 = strtol ( * V_157 , V_157 , 0 ) ;
if ( V_109 || * V_157 == V_28 ) {
F_104 ( L_57 , V_159 ) ;
return - V_50 ;
}
return 0 ;
}
static bool F_105 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
int F_106 ( const char * V_160 , struct V_94 * V_95 )
{
char * V_161 , * V_54 , * V_15 = F_27 ( V_160 ) ;
int V_105 ;
if ( ! V_15 )
return - V_49 ;
V_95 -> V_28 = 0 ;
V_95 -> V_97 = V_98 ;
V_161 = strchr ( V_15 , ':' ) ;
if ( V_161 ) {
* V_161 ++ = '\0' ;
V_105 = F_103 ( & V_161 , & V_95 -> V_28 , L_58 ) ;
if ( V_105 )
goto V_105;
if ( * V_161 == '+' || * V_161 == '-' ) {
const char V_162 = * V_161 ++ ;
V_105 = F_103 ( & V_161 , & V_95 -> V_97 , L_59 ) ;
if ( V_105 )
goto V_105;
if ( V_162 == '+' ) {
V_95 -> V_97 += V_95 -> V_28 ;
V_95 -> V_97 -- ;
}
}
F_4 ( L_60 , V_95 -> V_28 , V_95 -> V_97 ) ;
V_105 = - V_50 ;
if ( V_95 -> V_28 > V_95 -> V_97 ) {
F_104 ( L_61
L_62 ) ;
goto V_105;
}
if ( * V_161 != '\0' ) {
F_104 ( L_63 , V_161 ) ;
goto V_105;
}
}
V_54 = strchr ( V_15 , '@' ) ;
if ( V_54 ) {
* V_54 = '\0' ;
V_95 -> V_54 = F_27 ( ++ V_54 ) ;
if ( V_95 -> V_54 == NULL ) {
V_105 = - V_49 ;
goto V_105;
}
V_95 -> V_55 = V_15 ;
} else if ( strchr ( V_15 , '/' ) || strchr ( V_15 , '.' ) )
V_95 -> V_54 = V_15 ;
else if ( F_105 ( V_15 ) )
V_95 -> V_55 = V_15 ;
else {
F_104 ( L_64 , V_15 ) ;
V_105 = - V_50 ;
goto V_105;
}
return 0 ;
V_105:
free ( V_15 ) ;
return V_105 ;
}
static int F_107 ( char * * V_160 , struct V_90 * V_91 )
{
char * V_157 ;
V_157 = strchr ( * V_160 , ':' ) ;
if ( V_157 ) {
* V_157 = '\0' ;
if ( ! V_91 -> V_163 && ! F_105 ( * V_160 ) )
goto V_164;
V_91 -> V_165 = F_27 ( * V_160 ) ;
if ( ! V_91 -> V_165 )
return - V_49 ;
* V_160 = V_157 + 1 ;
} else
V_91 -> V_165 = NULL ;
if ( ! V_91 -> V_163 && ! F_105 ( * V_160 ) ) {
V_164:
F_104 ( L_65
L_66 , * V_160 ) ;
return - V_50 ;
}
V_91 -> V_166 = F_27 ( * V_160 ) ;
if ( V_91 -> V_166 == NULL )
return - V_49 ;
return 0 ;
}
static int F_108 ( char * V_160 , struct V_90 * V_91 )
{
struct V_52 * V_53 = & V_91 -> V_93 ;
char * V_157 , * V_92 ;
char V_162 , V_167 = 0 ;
bool V_168 = false ;
int V_4 ;
if ( ! V_160 )
return - V_50 ;
if ( F_109 ( V_160 ) ) {
V_91 -> V_163 = true ;
if ( V_160 [ 0 ] == '%' )
V_160 ++ ;
}
V_157 = strpbrk ( V_160 , L_67 ) ;
if ( V_91 -> V_163 ) {
if ( V_157 ) {
if ( * V_157 != '@' ) {
F_104 ( L_68 ,
V_160 ) ;
return - V_50 ;
}
V_92 = F_110 ( V_157 + 1 ) ;
if ( V_92 ) {
V_91 -> V_39 = F_111 ( V_92 ) ;
free ( V_92 ) ;
} else
V_91 -> V_39 = F_27 ( V_157 + 1 ) ;
if ( ! V_91 -> V_39 )
return - V_49 ;
* V_157 = '\0' ;
}
V_4 = F_107 ( & V_160 , V_91 ) ;
if ( V_4 == 0 ) {
if ( F_112 ( & V_91 -> V_93 . V_55 , L_69 , V_91 -> V_166 ) < 0 )
V_4 = - V_109 ;
}
return V_4 ;
}
if ( V_157 && * V_157 == '=' ) {
* V_157 = '\0' ;
V_92 = V_157 + 1 ;
V_4 = F_107 ( & V_160 , V_91 ) ;
if ( V_4 < 0 )
return V_4 ;
V_160 = V_92 ;
}
if ( ! strpbrk ( V_160 , L_70 ) && ( V_157 = strpbrk ( V_160 , L_71 ) ) != NULL ) {
if ( memchr ( V_160 , '.' , V_157 - V_160 ) )
V_168 = true ;
}
V_157 = strpbrk ( V_160 , L_72 ) ;
if ( V_157 ) {
V_167 = * V_157 ;
* V_157 ++ = '\0' ;
}
if ( V_160 [ 0 ] == '\0' )
V_92 = NULL ;
else {
V_92 = F_27 ( V_160 ) ;
if ( V_92 == NULL )
return - V_49 ;
}
if ( V_168 )
V_53 -> V_54 = V_92 ;
else {
V_53 -> V_55 = V_92 ;
if ( V_92 && ! strncmp ( V_92 , L_73 , 2 ) ) {
V_53 -> V_169 = strtoul ( V_53 -> V_55 , & V_92 , 0 ) ;
if ( * V_92 != '\0' ) {
F_104 ( L_74 ) ;
return - V_50 ;
}
}
}
while ( V_157 ) {
V_160 = V_157 ;
V_162 = V_167 ;
if ( V_162 == ';' ) {
V_53 -> V_56 = F_27 ( V_160 ) ;
if ( V_53 -> V_56 == NULL )
return - V_49 ;
break;
}
V_157 = strpbrk ( V_160 , L_72 ) ;
if ( V_157 ) {
V_167 = * V_157 ;
* V_157 ++ = '\0' ;
}
switch ( V_162 ) {
case ':' :
V_53 -> line = strtoul ( V_160 , & V_92 , 0 ) ;
if ( * V_92 != '\0' ) {
F_104 ( L_75
L_76 ) ;
return - V_50 ;
}
break;
case '+' :
V_53 -> V_88 = strtoul ( V_160 , & V_92 , 0 ) ;
if ( * V_92 != '\0' ) {
F_104 ( L_77
L_78 ) ;
return - V_50 ;
}
break;
case '@' :
if ( V_53 -> V_54 ) {
F_104 ( L_79 ) ;
return - V_50 ;
}
V_53 -> V_54 = F_27 ( V_160 ) ;
if ( V_53 -> V_54 == NULL )
return - V_49 ;
break;
case '%' :
if ( strcmp ( V_160 , L_80 ) == 0 ) {
V_53 -> V_89 = 1 ;
} else {
F_104 ( L_81 , V_160 ) ;
return - V_86 ;
}
break;
default:
F_55 ( L_82 ,
__FILE__ , __LINE__ ) ;
return - V_86 ;
break;
}
}
if ( V_53 -> V_56 && V_53 -> line ) {
F_104 ( L_83
L_84 ) ;
return - V_50 ;
}
if ( V_53 -> V_56 && V_53 -> V_88 ) {
F_104 ( L_85 ) ;
return - V_50 ;
}
if ( V_53 -> line && V_53 -> V_88 ) {
F_104 ( L_86 ) ;
return - V_50 ;
}
if ( ! V_53 -> line && ! V_53 -> V_56 && V_53 -> V_54 && ! V_53 -> V_55 ) {
F_104 ( L_87
L_88 ) ;
return - V_50 ;
}
if ( V_53 -> V_88 && ! V_53 -> V_55 ) {
F_104 ( L_89 ) ;
return - V_50 ;
}
if ( ( V_53 -> V_88 || V_53 -> line || V_53 -> V_56 ) && V_53 -> V_89 ) {
F_104 ( L_90
L_91 ) ;
return - V_50 ;
}
F_4 ( L_92 ,
V_53 -> V_55 , V_53 -> V_54 , V_53 -> line , V_53 -> V_88 , V_53 -> V_89 ,
V_53 -> V_56 ) ;
return 0 ;
}
static int F_113 ( char * V_1 , struct V_170 * V_160 )
{
char * V_92 , * V_171 ;
struct V_172 * * V_173 ;
F_4 ( L_93 , V_1 ) ;
V_92 = strchr ( V_1 , '=' ) ;
if ( V_92 ) {
V_160 -> V_15 = F_114 ( V_1 , V_92 - V_1 ) ;
if ( V_160 -> V_15 == NULL )
return - V_49 ;
F_4 ( L_94 , V_160 -> V_15 ) ;
V_1 = V_92 + 1 ;
}
V_92 = strchr ( V_1 , ':' ) ;
if ( V_92 ) {
* V_92 = '\0' ;
V_160 -> type = F_27 ( V_92 + 1 ) ;
if ( V_160 -> type == NULL )
return - V_49 ;
F_4 ( L_95 , V_160 -> type ) ;
}
V_92 = strpbrk ( V_1 , L_96 ) ;
if ( ! F_115 ( V_1 ) || ! V_92 ) {
V_160 -> V_150 = F_27 ( V_1 ) ;
if ( V_160 -> V_150 == NULL )
return - V_49 ;
F_4 ( L_97 , V_160 -> V_150 ) ;
return 0 ;
}
V_160 -> V_150 = F_114 ( V_1 , V_92 - V_1 ) ;
if ( V_160 -> V_150 == NULL )
return - V_49 ;
V_171 = V_160 -> V_150 ;
F_4 ( L_98 , V_160 -> V_150 ) ;
V_173 = & V_160 -> V_174 ;
do {
* V_173 = F_116 ( sizeof( struct V_172 ) ) ;
if ( * V_173 == NULL )
return - V_49 ;
if ( * V_92 == '[' ) {
V_1 = V_92 ;
( * V_173 ) -> V_175 = strtol ( V_1 + 1 , & V_92 , 0 ) ;
( * V_173 ) -> V_176 = true ;
if ( * V_92 != ']' || V_92 == V_1 + 1 ) {
F_104 ( L_99
L_100 ) ;
return - V_50 ;
}
V_92 ++ ;
if ( * V_92 == '\0' )
V_92 = NULL ;
} else {
if ( * V_92 == '.' ) {
V_1 = V_92 + 1 ;
( * V_173 ) -> V_176 = false ;
} else if ( V_92 [ 1 ] == '>' ) {
V_1 = V_92 + 2 ;
( * V_173 ) -> V_176 = true ;
} else {
F_104 ( L_101 ,
V_1 ) ;
return - V_50 ;
}
V_92 = strpbrk ( V_1 , L_96 ) ;
}
if ( V_92 ) {
( * V_173 ) -> V_15 = F_114 ( V_1 , V_92 - V_1 ) ;
if ( ( * V_173 ) -> V_15 == NULL )
return - V_49 ;
if ( * V_1 != '[' )
V_171 = ( * V_173 ) -> V_15 ;
F_4 ( L_102 , ( * V_173 ) -> V_15 , ( * V_173 ) -> V_176 ) ;
V_173 = & ( * V_173 ) -> V_177 ;
}
} while ( V_92 );
( * V_173 ) -> V_15 = F_27 ( V_1 ) ;
if ( ( * V_173 ) -> V_15 == NULL )
return - V_49 ;
if ( * V_1 != '[' )
V_171 = ( * V_173 ) -> V_15 ;
F_4 ( L_103 , ( * V_173 ) -> V_15 , ( * V_173 ) -> V_176 ) ;
if ( ! V_160 -> V_15 ) {
V_160 -> V_15 = F_27 ( V_171 ) ;
if ( V_160 -> V_15 == NULL )
return - V_49 ;
}
return 0 ;
}
int F_117 ( const char * V_178 , struct V_90 * V_91 )
{
char * * V_179 ;
int V_180 , V_60 , V_4 = 0 ;
V_179 = F_118 ( V_178 , & V_180 ) ;
if ( ! V_179 ) {
F_4 ( L_104 ) ;
return - V_49 ;
}
if ( V_180 - 1 > V_181 ) {
F_104 ( L_105 , V_180 - 1 ) ;
V_4 = - V_182 ;
goto V_11;
}
V_4 = F_108 ( V_179 [ 0 ] , V_91 ) ;
if ( V_4 < 0 )
goto V_11;
V_91 -> V_183 = V_180 - 1 ;
V_91 -> args = F_116 ( sizeof( struct V_170 ) * V_91 -> V_183 ) ;
if ( V_91 -> args == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
for ( V_60 = 0 ; V_60 < V_91 -> V_183 && V_4 >= 0 ; V_60 ++ ) {
V_4 = F_113 ( V_179 [ V_60 + 1 ] , & V_91 -> args [ V_60 ] ) ;
if ( V_4 >= 0 &&
F_115 ( V_91 -> args [ V_60 ] . V_150 ) && V_91 -> V_93 . V_89 ) {
F_104 ( L_106
L_107 ) ;
V_4 = - V_50 ;
}
}
V_11:
F_119 ( V_179 ) ;
return V_4 ;
}
bool F_120 ( struct V_90 * V_91 )
{
int V_60 = 0 ;
for ( V_60 = 0 ; V_60 < V_91 -> V_183 ; V_60 ++ )
if ( F_115 ( V_91 -> args [ V_60 ] . V_150 ) ||
! strcmp ( V_91 -> args [ V_60 ] . V_150 , V_184 ) ||
! strcmp ( V_91 -> args [ V_60 ] . V_150 , V_185 ) )
return true ;
return false ;
}
bool F_77 ( struct V_90 * V_91 )
{
if ( V_91 -> V_93 . V_54 || V_91 -> V_93 . line || V_91 -> V_93 . V_56 )
return true ;
if ( F_120 ( V_91 ) )
return true ;
return false ;
}
int F_121 ( const char * V_178 , struct V_57 * V_186 )
{
struct V_113 * V_114 = & V_186 -> V_93 ;
char V_187 ;
char * V_188 ;
char * V_189 = NULL , * V_190 , * V_191 , * V_192 , * V_193 ;
int V_4 , V_60 , V_180 ;
char * * V_179 ;
F_4 ( L_108 , V_178 ) ;
V_179 = F_118 ( V_178 , & V_180 ) ;
if ( ! V_179 ) {
F_4 ( L_104 ) ;
return - V_49 ;
}
if ( V_180 < 2 ) {
F_104 ( L_109 ) ;
V_4 = - V_182 ;
goto V_11;
}
V_189 = F_27 ( V_179 [ 0 ] ) ;
if ( V_189 == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
V_191 = strtok_r ( V_189 , L_110 , & V_190 ) ;
V_192 = strtok_r ( NULL , L_111 , & V_190 ) ;
V_193 = strtok_r ( NULL , L_112 , & V_190 ) ;
if ( V_191 == NULL || strlen ( V_191 ) != 1 || V_192 == NULL
|| V_193 == NULL ) {
F_104 ( L_113 , V_179 [ 0 ] ) ;
V_4 = - V_50 ;
goto V_11;
}
V_187 = V_191 [ 0 ] ;
V_186 -> V_165 = F_27 ( V_192 ) ;
V_186 -> V_166 = F_27 ( V_193 ) ;
if ( V_186 -> V_165 == NULL || V_186 -> V_166 == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
F_4 ( L_114 , V_186 -> V_165 , V_186 -> V_166 , V_187 ) ;
V_114 -> V_89 = ( V_187 == 'r' ) ;
V_188 = strchr ( V_179 [ 1 ] , ':' ) ;
if ( V_188 ) {
V_114 -> V_29 = F_114 ( V_179 [ 1 ] , V_188 - V_179 [ 1 ] ) ;
if ( ! V_114 -> V_29 ) {
V_4 = - V_49 ;
goto V_11;
}
V_186 -> V_85 = ( V_114 -> V_29 [ 0 ] == '/' ) ;
V_188 ++ ;
} else
V_188 = V_179 [ 1 ] ;
V_191 = strtok_r ( V_188 , L_115 , & V_190 ) ;
if ( V_191 [ 0 ] == '0' ) {
if ( strcmp ( V_191 , L_73 ) == 0 ) {
if ( ! V_179 [ 2 ] || strcmp ( V_179 [ 2 ] , L_116 ) ) {
V_4 = - V_50 ;
goto V_11;
}
V_114 -> V_61 = 0 ;
free ( V_179 [ 2 ] ) ;
for ( V_60 = 2 ; V_179 [ V_60 + 1 ] != NULL ; V_60 ++ )
V_179 [ V_60 ] = V_179 [ V_60 + 1 ] ;
V_179 [ V_60 ] = NULL ;
V_180 -= 1 ;
} else
V_114 -> V_61 = strtoul ( V_191 , NULL , 0 ) ;
} else {
V_114 -> V_14 = F_27 ( V_191 ) ;
if ( V_114 -> V_14 == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
V_192 = strtok_r ( NULL , L_37 , & V_190 ) ;
if ( V_192 == NULL )
V_114 -> V_88 = 0 ;
else
V_114 -> V_88 = strtoul ( V_192 , NULL , 10 ) ;
}
V_186 -> V_183 = V_180 - 2 ;
V_186 -> args = F_116 ( sizeof( struct V_194 ) * V_186 -> V_183 ) ;
if ( V_186 -> args == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ ) {
V_188 = strchr ( V_179 [ V_60 + 2 ] , '=' ) ;
if ( V_188 )
* V_188 ++ = '\0' ;
else
V_188 = V_179 [ V_60 + 2 ] ;
V_186 -> args [ V_60 ] . V_15 = F_27 ( V_179 [ V_60 + 2 ] ) ;
V_186 -> args [ V_60 ] . V_195 = F_27 ( V_188 ) ;
if ( V_186 -> args [ V_60 ] . V_15 == NULL || V_186 -> args [ V_60 ] . V_195 == NULL ) {
V_4 = - V_49 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_189 ) ;
F_119 ( V_179 ) ;
return V_4 ;
}
char * F_122 ( struct V_170 * V_196 )
{
struct V_172 * V_174 = V_196 -> V_174 ;
struct V_197 V_48 ;
char * V_4 = NULL ;
int V_105 ;
if ( F_123 ( & V_48 , 64 ) < 0 )
return NULL ;
if ( V_196 -> V_15 && V_196 -> V_150 )
V_105 = F_124 ( & V_48 , L_117 , V_196 -> V_15 , V_196 -> V_150 ) ;
else
V_105 = F_125 ( & V_48 , V_196 -> V_15 ? : V_196 -> V_150 ) ;
if ( V_105 )
goto V_11;
while ( V_174 ) {
if ( V_174 -> V_15 [ 0 ] == '[' )
V_105 = F_125 ( & V_48 , V_174 -> V_15 ) ;
else
V_105 = F_124 ( & V_48 , L_118 , V_174 -> V_176 ? L_119 : L_120 ,
V_174 -> V_15 ) ;
V_174 = V_174 -> V_177 ;
if ( V_105 )
goto V_11;
}
if ( V_196 -> type )
if ( F_124 ( & V_48 , L_121 , V_196 -> type ) < 0 )
goto V_11;
V_4 = F_126 ( & V_48 , NULL ) ;
V_11:
F_127 ( & V_48 ) ;
return V_4 ;
}
char * F_79 ( struct V_52 * V_53 )
{
struct V_197 V_48 ;
char * V_92 , * V_4 = NULL ;
int V_96 , V_105 = 0 ;
if ( F_123 ( & V_48 , 64 ) < 0 )
return NULL ;
if ( V_53 -> V_55 ) {
if ( F_125 ( & V_48 , V_53 -> V_55 ) < 0 )
goto V_11;
if ( V_53 -> V_88 )
V_105 = F_124 ( & V_48 , L_122 , V_53 -> V_88 ) ;
else if ( V_53 -> line )
V_105 = F_124 ( & V_48 , L_123 , V_53 -> line ) ;
else if ( V_53 -> V_89 )
V_105 = F_125 ( & V_48 , L_124 ) ;
if ( V_105 )
goto V_11;
}
if ( V_53 -> V_54 ) {
V_92 = V_53 -> V_54 ;
V_96 = strlen ( V_92 ) ;
if ( V_96 > 30 ) {
V_92 = strchr ( V_53 -> V_54 + V_96 - 30 , '/' ) ;
V_92 = V_92 ? V_92 + 1 : V_53 -> V_54 + V_96 - 30 ;
}
V_105 = F_124 ( & V_48 , L_125 , V_92 ) ;
if ( ! V_105 && ! V_53 -> V_55 && V_53 -> line )
V_105 = F_124 ( & V_48 , L_123 , V_53 -> line ) ;
}
if ( ! V_105 )
V_4 = F_126 ( & V_48 , NULL ) ;
V_11:
F_127 ( & V_48 ) ;
return V_4 ;
}
char * F_128 ( struct V_90 * V_91 )
{
struct V_197 V_48 ;
char * V_92 , * V_4 = NULL ;
int V_60 ;
if ( F_123 ( & V_48 , 64 ) )
return NULL ;
if ( V_91 -> V_166 )
if ( F_124 ( & V_48 , L_126 , V_91 -> V_165 ? : V_51 ,
V_91 -> V_166 ) < 0 )
goto V_11;
V_92 = F_79 ( & V_91 -> V_93 ) ;
if ( ! V_92 || F_125 ( & V_48 , V_92 ) < 0 )
goto V_11;
free ( V_92 ) ;
for ( V_60 = 0 ; V_60 < V_91 -> V_183 ; V_60 ++ ) {
V_92 = F_122 ( V_91 -> args + V_60 ) ;
if ( ! V_92 || F_124 ( & V_48 , L_127 , V_92 ) < 0 )
goto V_11;
free ( V_92 ) ;
}
V_4 = F_126 ( & V_48 , NULL ) ;
V_11:
F_127 ( & V_48 ) ;
return V_4 ;
}
static int F_129 ( struct V_198 * V_176 ,
struct V_197 * V_48 , int V_199 )
{
int V_105 ;
if ( V_176 -> V_177 ) {
V_199 = F_129 ( V_176 -> V_177 , V_48 ,
V_199 + 1 ) ;
if ( V_199 < 0 )
return V_199 ;
}
V_105 = F_124 ( V_48 , L_128 , V_176 -> V_88 ) ;
return ( V_105 < 0 ) ? V_105 : V_199 ;
}
static int F_130 ( struct V_194 * V_160 ,
struct V_197 * V_48 )
{
struct V_198 * V_176 = V_160 -> V_176 ;
int V_199 = 0 , V_105 ;
if ( V_160 -> V_15 )
V_105 = F_124 ( V_48 , L_129 , V_160 -> V_15 ) ;
else
V_105 = F_131 ( V_48 , ' ' ) ;
if ( V_105 )
return V_105 ;
if ( V_160 -> V_195 [ 0 ] == '@' && V_160 -> V_176 )
V_176 = V_176 -> V_177 ;
if ( V_176 ) {
V_199 = F_129 ( V_176 , V_48 , 1 ) ;
if ( V_199 < 0 )
return V_199 ;
}
if ( V_160 -> V_195 [ 0 ] == '@' && V_160 -> V_176 )
V_105 = F_124 ( V_48 , L_130 , V_160 -> V_195 , V_160 -> V_176 -> V_88 ) ;
else
V_105 = F_125 ( V_48 , V_160 -> V_195 ) ;
while ( ! V_105 && V_199 -- )
V_105 = F_131 ( V_48 , ')' ) ;
if ( ! V_105 && V_160 -> type )
V_105 = F_124 ( V_48 , L_121 , V_160 -> type ) ;
return V_105 ;
}
char * F_132 ( struct V_57 * V_186 )
{
struct V_113 * V_114 = & V_186 -> V_93 ;
struct V_197 V_48 ;
char * V_4 = NULL ;
int V_60 , V_105 ;
if ( V_186 -> V_85 && ! V_114 -> V_29 )
return NULL ;
if ( F_123 ( & V_48 , 32 ) < 0 )
return NULL ;
if ( F_124 ( & V_48 , L_131 , V_114 -> V_89 ? 'r' : 'p' ,
V_186 -> V_165 , V_186 -> V_166 ) < 0 )
goto error;
if ( V_186 -> V_85 && ! V_114 -> V_61 ) {
if ( ! V_114 -> V_14 || strcmp ( V_114 -> V_14 , L_132 ) )
goto error;
}
if ( V_186 -> V_85 )
V_105 = F_124 ( & V_48 , L_133 , V_114 -> V_29 , V_114 -> V_61 ) ;
else if ( ! strncmp ( V_114 -> V_14 , L_73 , 2 ) )
V_105 = F_124 ( & V_48 , L_134 , V_114 -> V_29 ? : L_37 ,
V_114 -> V_29 ? L_110 : L_37 , V_114 -> V_61 ) ;
else
V_105 = F_124 ( & V_48 , L_135 , V_114 -> V_29 ? : L_37 ,
V_114 -> V_29 ? L_110 : L_37 , V_114 -> V_14 , V_114 -> V_88 ) ;
if ( V_105 )
goto error;
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ )
if ( F_130 ( & V_186 -> args [ V_60 ] , & V_48 ) < 0 )
goto error;
V_4 = F_126 ( & V_48 , NULL ) ;
error:
F_127 ( & V_48 ) ;
return V_4 ;
}
static int F_133 ( struct V_113 * V_114 ,
struct V_52 * V_53 ,
bool V_115 )
{
struct V_14 * V_24 = NULL ;
struct V_16 * V_16 = NULL ;
T_3 V_18 = V_114 -> V_61 ;
int V_4 = - V_26 ;
if ( ! V_115 ) {
V_16 = F_20 ( V_114 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_24 = F_67 ( V_16 , V_18 ) ;
} else {
if ( V_114 -> V_14 && ! V_18 ) {
if ( F_18 ( V_114 -> V_14 ,
& V_18 , true , false ) < 0 )
goto V_11;
}
if ( V_18 ) {
V_18 += V_114 -> V_88 ;
V_24 = F_12 ( V_18 , & V_16 ) ;
}
}
if ( ! V_24 )
goto V_11;
V_53 -> V_89 = V_114 -> V_89 ;
V_53 -> V_88 = V_18 - V_16 -> V_27 ( V_16 , V_24 -> V_28 ) ;
V_53 -> V_55 = F_27 ( V_24 -> V_15 ) ;
V_4 = V_53 -> V_55 ? 0 : - V_49 ;
V_11:
if ( V_16 && ! V_115 ) {
F_49 ( V_16 ) ;
}
return V_4 ;
}
static int F_134 ( struct V_113 * V_114 ,
struct V_52 * V_53 ,
bool V_115 )
{
char V_48 [ 128 ] ;
int V_4 ;
V_4 = F_65 ( V_114 , V_53 , V_115 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_133 ( V_114 , V_53 , V_115 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_136 ) ;
if ( V_114 -> V_14 ) {
V_53 -> V_55 = F_27 ( V_114 -> V_14 ) ;
V_53 -> V_88 = V_114 -> V_88 ;
} else {
V_4 = F_1 ( V_48 , 128 , L_137 V_87 , ( T_3 ) V_114 -> V_61 ) ;
if ( V_4 < 0 )
return V_4 ;
V_53 -> V_55 = F_27 ( V_48 ) ;
V_53 -> V_88 = 0 ;
}
if ( V_53 -> V_55 == NULL )
return - V_49 ;
V_53 -> V_89 = V_114 -> V_89 ;
return 0 ;
}
static int F_135 ( struct V_57 * V_186 ,
struct V_90 * V_91 , bool V_115 )
{
struct V_197 V_48 = V_200 ;
int V_60 , V_4 ;
V_91 -> V_166 = F_27 ( V_186 -> V_166 ) ;
V_91 -> V_165 = F_27 ( V_186 -> V_165 ) ;
if ( V_91 -> V_166 == NULL || V_91 -> V_165 == NULL )
return - V_49 ;
V_4 = F_134 ( & V_186 -> V_93 , & V_91 -> V_93 , V_115 ) ;
if ( V_4 < 0 )
return V_4 ;
V_91 -> V_183 = V_186 -> V_183 ;
V_91 -> args = F_116 ( sizeof( struct V_170 ) * V_91 -> V_183 ) ;
if ( V_91 -> args == NULL )
return - V_49 ;
for ( V_60 = 0 ; V_60 < V_186 -> V_183 && V_4 >= 0 ; V_60 ++ ) {
if ( V_186 -> args [ V_60 ] . V_15 )
V_91 -> args [ V_60 ] . V_15 = F_27 ( V_186 -> args [ V_60 ] . V_15 ) ;
else {
if ( ( V_4 = F_123 ( & V_48 , 32 ) ) < 0 )
goto error;
V_4 = F_130 ( & V_186 -> args [ V_60 ] , & V_48 ) ;
V_91 -> args [ V_60 ] . V_15 = F_126 ( & V_48 , NULL ) ;
}
if ( V_91 -> args [ V_60 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_49 ;
}
error:
if ( V_4 < 0 )
F_136 ( V_91 ) ;
return V_4 ;
}
void F_136 ( struct V_90 * V_91 )
{
struct V_172 * V_174 , * V_177 ;
int V_60 ;
free ( V_91 -> V_166 ) ;
free ( V_91 -> V_165 ) ;
free ( V_91 -> V_39 ) ;
F_29 ( & V_91 -> V_93 ) ;
for ( V_60 = 0 ; V_60 < V_91 -> V_183 ; V_60 ++ ) {
free ( V_91 -> args [ V_60 ] . V_15 ) ;
free ( V_91 -> args [ V_60 ] . V_150 ) ;
free ( V_91 -> args [ V_60 ] . type ) ;
V_174 = V_91 -> args [ V_60 ] . V_174 ;
while ( V_174 ) {
V_177 = V_174 -> V_177 ;
F_62 ( & V_174 -> V_15 ) ;
free ( V_174 ) ;
V_174 = V_177 ;
}
}
free ( V_91 -> args ) ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
}
static int F_137 ( struct V_52 * V_201 ,
struct V_52 * V_202 )
{
V_201 -> V_54 = F_138 ( V_202 -> V_54 , V_203 ) ;
V_201 -> V_55 = F_138 ( V_202 -> V_55 , V_203 ) ;
V_201 -> V_56 = F_138 ( V_202 -> V_56 , V_203 ) ;
V_201 -> line = V_202 -> line ;
V_201 -> V_89 = V_202 -> V_89 ;
V_201 -> V_88 = V_202 -> V_88 ;
return 0 ;
V_203:
F_29 ( V_201 ) ;
return - V_49 ;
}
static int F_139 ( struct V_170 * V_201 ,
struct V_170 * V_202 )
{
struct V_172 * V_174 , * * V_204 ;
V_201 -> V_15 = F_138 ( V_202 -> V_15 , V_203 ) ;
V_201 -> V_150 = F_138 ( V_202 -> V_150 , V_203 ) ;
V_201 -> type = F_138 ( V_202 -> type , V_203 ) ;
V_174 = V_202 -> V_174 ;
V_204 = & ( V_201 -> V_174 ) ;
while ( V_174 ) {
* V_204 = F_116 ( sizeof( * V_174 ) ) ;
if ( ! * V_204 )
goto V_203;
( * V_204 ) -> V_15 = F_138 ( V_174 -> V_15 , V_203 ) ;
( * V_204 ) -> V_175 = V_174 -> V_175 ;
( * V_204 ) -> V_176 = V_174 -> V_176 ;
V_174 = V_174 -> V_177 ;
V_204 = & ( ( * V_204 ) -> V_177 ) ;
}
return 0 ;
V_203:
return - V_49 ;
}
int F_140 ( struct V_90 * V_201 ,
struct V_90 * V_202 )
{
int V_60 ;
V_201 -> V_166 = F_138 ( V_202 -> V_166 , V_203 ) ;
V_201 -> V_165 = F_138 ( V_202 -> V_165 , V_203 ) ;
V_201 -> V_39 = F_138 ( V_202 -> V_39 , V_203 ) ;
V_201 -> V_85 = V_202 -> V_85 ;
if ( F_137 ( & V_201 -> V_93 , & V_202 -> V_93 ) < 0 )
goto V_203;
V_201 -> args = F_116 ( sizeof( struct V_170 ) * V_202 -> V_183 ) ;
if ( ! V_201 -> args )
goto V_203;
V_201 -> V_183 = V_202 -> V_183 ;
for ( V_60 = 0 ; V_60 < V_202 -> V_183 ; V_60 ++ )
if ( F_139 ( & V_201 -> args [ V_60 ] , & V_202 -> args [ V_60 ] ) < 0 )
goto V_203;
return 0 ;
V_203:
F_136 ( V_201 ) ;
return - V_49 ;
}
void F_31 ( struct V_57 * V_186 )
{
struct V_198 * V_176 , * V_177 ;
int V_60 ;
free ( V_186 -> V_166 ) ;
free ( V_186 -> V_165 ) ;
free ( V_186 -> V_93 . V_14 ) ;
free ( V_186 -> V_93 . V_119 ) ;
free ( V_186 -> V_93 . V_29 ) ;
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ ) {
free ( V_186 -> args [ V_60 ] . V_15 ) ;
free ( V_186 -> args [ V_60 ] . V_195 ) ;
free ( V_186 -> args [ V_60 ] . type ) ;
V_176 = V_186 -> args [ V_60 ] . V_176 ;
while ( V_176 ) {
V_177 = V_176 -> V_177 ;
free ( V_176 ) ;
V_176 = V_177 ;
}
}
free ( V_186 -> args ) ;
memset ( V_186 , 0 , sizeof( * V_186 ) ) ;
}
static void F_141 ( struct V_205 * V_206 )
{
struct V_207 * V_146 ;
while ( ! F_142 ( V_206 ) ) {
V_146 = F_143 ( V_206 ,
struct V_207 , V_208 ) ;
F_144 ( & V_146 -> V_208 ) ;
free ( V_146 -> V_14 ) ;
free ( V_146 ) ;
}
}
static int F_145 ( struct V_205 * V_206 )
{
struct V_207 * V_146 ;
const char * V_209 = F_146 () ;
char V_48 [ V_210 ] , * V_188 ;
T_10 * V_128 ;
int V_4 ;
if ( V_209 == NULL )
return - V_86 ;
V_4 = F_1 ( V_48 , V_210 , L_138 , V_209 ) ;
if ( V_4 < 0 )
return V_4 ;
V_128 = fopen ( V_48 , L_48 ) ;
if ( ! V_128 )
return - V_109 ;
V_4 = 0 ;
while ( fgets ( V_48 , V_210 , V_128 ) ) {
V_146 = F_116 ( sizeof( * V_146 ) ) ;
if ( ! V_146 ) {
V_4 = - V_49 ;
break;
}
F_147 ( & V_146 -> V_208 ) ;
F_148 ( & V_146 -> V_208 , V_206 ) ;
if ( sscanf ( V_48 , L_139 , & V_146 -> V_28 , & V_146 -> V_97 ) != 2 ) {
V_4 = - V_50 ;
break;
}
V_188 = strchr ( V_48 , '\t' ) ;
if ( V_188 ) {
V_188 ++ ;
if ( V_188 [ strlen ( V_188 ) - 1 ] == '\n' )
V_188 [ strlen ( V_188 ) - 1 ] = '\0' ;
} else
V_188 = ( char * ) L_140 ;
V_146 -> V_14 = F_27 ( V_188 ) ;
if ( ! V_146 -> V_14 ) {
V_4 = - V_49 ;
break;
}
F_149 ( L_141 ,
V_146 -> V_28 , V_146 -> V_97 , V_146 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_141 ( V_206 ) ;
fclose ( V_128 ) ;
return V_4 ;
}
static struct V_207 *
F_150 ( struct V_205 * V_206 ,
unsigned long V_61 )
{
struct V_207 * V_146 ;
F_151 (node, blacklist, list) {
if ( V_146 -> V_28 <= V_61 && V_61 < V_146 -> V_97 )
return V_146 ;
}
return NULL ;
}
static void F_152 ( void )
{
if ( ! F_142 ( & V_211 ) )
return;
if ( F_145 ( & V_211 ) < 0 )
F_4 ( L_142 ) ;
}
static void F_153 ( void )
{
F_141 ( & V_211 ) ;
}
static bool F_33 ( unsigned long V_61 )
{
return ! ! F_150 ( & V_211 , V_61 ) ;
}
static int F_154 ( const char * V_165 , const char * V_166 ,
struct V_90 * V_91 ,
const char * V_29 ,
struct V_197 * V_44 )
{
int V_60 , V_4 ;
char * V_48 ;
if ( F_112 ( & V_48 , L_143 , V_165 , V_166 ) < 0 )
return - V_109 ;
V_4 = F_124 ( V_44 , L_144 , V_48 ) ;
free ( V_48 ) ;
if ( V_4 )
return V_4 ;
V_48 = F_79 ( & V_91 -> V_93 ) ;
if ( ! V_48 )
return - V_49 ;
V_4 = F_125 ( V_44 , V_48 ) ;
free ( V_48 ) ;
if ( ! V_4 && V_29 )
V_4 = F_124 ( V_44 , L_145 , V_29 ) ;
if ( ! V_4 && V_91 -> V_183 > 0 ) {
V_4 = F_155 ( V_44 , L_146 , 5 ) ;
for ( V_60 = 0 ; ! V_4 && V_60 < V_91 -> V_183 ; V_60 ++ ) {
V_48 = F_122 ( & V_91 -> args [ V_60 ] ) ;
if ( ! V_48 )
return - V_49 ;
V_4 = F_124 ( V_44 , L_127 , V_48 ) ;
free ( V_48 ) ;
}
}
if ( ! V_4 )
V_4 = F_131 ( V_44 , ')' ) ;
return V_4 ;
}
int F_156 ( const char * V_165 , const char * V_166 ,
struct V_90 * V_91 ,
const char * V_29 , bool V_212 )
{
struct V_197 V_48 = V_200 ;
int V_4 ;
V_4 = F_154 ( V_165 , V_166 , V_91 , V_29 , & V_48 ) ;
if ( V_4 >= 0 ) {
if ( V_212 )
printf ( L_97 , V_48 . V_48 ) ;
else
F_157 ( L_97 , V_48 . V_48 ) ;
}
F_127 ( & V_48 ) ;
return V_4 ;
}
static bool F_158 ( struct V_57 * V_186 ,
struct V_142 * T_11 )
{
char V_92 [ 128 ] ;
if ( F_96 ( T_11 , V_186 -> V_166 ) )
return true ;
if ( F_1 ( V_92 , 128 , L_143 , V_186 -> V_165 , V_186 -> V_166 ) < 0 )
return false ;
return F_96 ( T_11 , V_92 ) ;
}
static int F_159 ( int V_63 , bool V_115 ,
struct V_142 * T_11 )
{
int V_4 = 0 ;
struct V_57 V_186 ;
struct V_90 V_91 ;
struct V_213 * V_214 ;
struct V_145 * V_215 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_214 = F_160 ( V_63 ) ;
if ( ! V_214 )
return - V_49 ;
F_95 (ent, rawlist) {
V_4 = F_121 ( V_215 -> V_152 , & V_186 ) ;
if ( V_4 >= 0 ) {
if ( ! F_158 ( & V_186 , T_11 ) )
goto V_177;
V_4 = F_135 ( & V_186 , & V_91 ,
V_115 ) ;
if ( V_4 < 0 )
goto V_177;
V_4 = F_156 ( V_91 . V_165 , V_91 . V_166 ,
& V_91 , V_186 . V_93 . V_29 ,
true ) ;
}
V_177:
F_136 ( & V_91 ) ;
F_31 ( & V_186 ) ;
if ( V_4 < 0 )
break;
}
F_97 ( V_214 ) ;
F_63 () ;
return V_4 ;
}
int F_161 ( struct V_142 * T_11 )
{
int V_216 , V_217 , V_4 ;
F_86 () ;
if ( V_218 . V_219 )
return F_162 ( T_11 ) ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_163 ( & V_216 , & V_217 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_216 >= 0 )
V_4 = F_159 ( V_216 , true , T_11 ) ;
if ( V_217 >= 0 && V_4 >= 0 )
V_4 = F_159 ( V_217 , false , T_11 ) ;
if ( V_216 > 0 )
F_41 ( V_216 ) ;
if ( V_217 > 0 )
F_41 ( V_217 ) ;
F_8 () ;
return V_4 ;
}
static int F_164 ( char * V_48 , T_1 V_96 , const char * V_220 ,
struct V_213 * V_221 , bool V_222 )
{
int V_60 , V_4 ;
char * V_188 , * V_223 ;
if ( * V_220 == '.' )
V_220 ++ ;
V_223 = F_27 ( V_220 ) ;
if ( ! V_223 )
return - V_49 ;
V_188 = strchr ( V_223 , '.' ) ;
if ( V_188 && V_188 != V_223 )
* V_188 = '\0' ;
V_4 = F_1 ( V_48 , V_96 , L_40 , V_223 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_165 ( V_221 , V_48 ) )
goto V_11;
if ( ! V_222 ) {
F_7 ( L_148
L_149
L_150
L_151 ,
V_48 ) ;
V_4 = - V_224 ;
goto V_11;
}
for ( V_60 = 1 ; V_60 < V_225 ; V_60 ++ ) {
V_4 = F_1 ( V_48 , V_96 , L_152 , V_223 , V_60 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_165 ( V_221 , V_48 ) )
break;
}
if ( V_60 == V_225 ) {
F_7 ( L_153 ) ;
V_4 = - V_182 ;
}
V_11:
free ( V_223 ) ;
return V_4 ;
}
static void F_166 ( struct V_57 * V_186 )
{
int V_60 ;
char * V_48 = F_132 ( V_186 ) ;
if ( ! V_186 -> V_85 || V_186 -> V_183 == 0 || ! V_48 )
goto V_11;
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ )
if ( F_167 ( V_186 -> args [ V_60 ] . V_195 , L_154 ) ) {
F_7 ( L_155
L_156 ,
V_186 -> args [ V_60 ] . V_195 ) ;
break;
}
V_11:
free ( V_48 ) ;
}
static int F_168 ( struct V_57 * V_186 ,
struct V_90 * V_91 ,
struct V_213 * V_221 ,
bool V_222 )
{
const char * V_166 , * V_165 ;
char V_48 [ 64 ] ;
int V_4 ;
if ( V_91 -> V_166 && ! V_91 -> V_163 )
V_166 = V_91 -> V_166 ;
else if ( V_186 -> V_166 )
V_166 = V_186 -> V_166 ;
else {
if ( V_91 -> V_93 . V_55 &&
( strncmp ( V_91 -> V_93 . V_55 , L_73 , 2 ) != 0 ) &&
! F_169 ( V_91 -> V_93 . V_55 ) )
V_166 = V_91 -> V_93 . V_55 ;
else
V_166 = V_186 -> V_93 . V_119 ;
}
if ( V_91 -> V_165 && ! V_91 -> V_163 )
V_165 = V_91 -> V_165 ;
else if ( V_186 -> V_165 )
V_165 = V_186 -> V_165 ;
else
V_165 = V_51 ;
V_4 = F_164 ( V_48 , 64 , V_166 ,
V_221 , V_222 ) ;
if ( V_4 < 0 )
return V_4 ;
V_166 = V_48 ;
V_186 -> V_166 = F_27 ( V_166 ) ;
V_186 -> V_165 = F_27 ( V_165 ) ;
if ( V_186 -> V_166 == NULL || V_186 -> V_165 == NULL )
return - V_49 ;
F_170 ( V_221 , V_166 ) ;
return 0 ;
}
static int F_171 ( bool V_125 ,
struct V_213 * * V_221 )
{
int V_63 ;
V_63 = F_172 ( V_226 | ( V_125 ? V_227 : 0 ) ) ;
if ( V_63 < 0 )
return V_63 ;
* V_221 = F_173 ( V_63 ) ;
if ( ! ( * V_221 ) ) {
F_4 ( L_157 ) ;
F_41 ( V_63 ) ;
return - V_49 ;
}
return V_63 ;
}
static int F_174 ( struct V_90 * V_91 ,
struct V_57 * V_58 ,
int V_59 , bool V_222 )
{
int V_60 , V_63 [ 2 ] = { - 1 , - 1 } , V_228 , V_4 ;
struct V_57 * V_186 = NULL ;
struct V_229 * V_219 = NULL ;
struct V_213 * V_221 [ 2 ] = { NULL , NULL } ;
struct V_103 V_104 ;
V_228 = V_91 -> V_85 ? 1 : 0 ;
V_63 [ V_228 ] = F_171 ( V_228 , & V_221 [ V_228 ] ) ;
if ( V_63 [ V_228 ] < 0 )
return V_63 [ V_228 ] ;
V_4 = 0 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_186 = & V_58 [ V_60 ] ;
V_228 = V_186 -> V_85 ? 1 : 0 ;
if ( V_63 [ V_228 ] == - 1 ) {
V_63 [ V_228 ] = F_171 ( V_228 ,
& V_221 [ V_228 ] ) ;
if ( V_63 [ V_228 ] < 0 )
goto V_230;
}
if ( ! V_186 -> V_93 . V_14 && ! V_91 -> V_85 )
continue;
V_4 = F_168 ( V_186 , V_91 , V_221 [ V_228 ] ,
V_222 ) ;
if ( V_4 < 0 )
break;
F_56 ( V_91 -> V_41 , & V_104 ) ;
V_4 = F_175 ( V_63 [ V_228 ] , V_186 ) ;
F_59 ( & V_104 ) ;
if ( V_4 < 0 )
break;
V_222 = true ;
}
if ( V_4 == - V_50 && V_91 -> V_85 )
F_166 ( V_186 ) ;
if ( V_4 == 0 && V_218 . V_219 ) {
V_219 = F_176 ( V_91 -> V_39 , V_91 -> V_41 ) ;
if ( ! V_219 ||
F_177 ( V_219 , V_91 , V_58 , V_59 ) < 0 ||
F_178 ( V_219 ) < 0 )
F_7 ( L_158 ) ;
F_179 ( V_219 ) ;
}
V_230:
for ( V_228 = 0 ; V_228 < 2 ; V_228 ++ ) {
F_97 ( V_221 [ V_228 ] ) ;
if ( V_63 [ V_228 ] >= 0 )
F_41 ( V_63 [ V_228 ] ) ;
}
return V_4 ;
}
static int F_180 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_231 )
{
int V_81 = 0 ;
struct V_14 * V_24 ;
struct V_232 * V_92 ;
if ( F_16 ( V_16 ) < 0 )
return 0 ;
F_181 (map, sym, tmp) {
if ( F_167 ( V_24 -> V_15 , V_15 ) ) {
V_81 ++ ;
if ( V_231 && V_81 < V_218 . V_233 )
V_231 [ V_81 - 1 ] = V_24 ;
}
}
return V_81 ;
}
void __weak F_182 ( struct V_90 * V_91 V_124 ,
struct V_57 * V_186 V_124 ,
struct V_16 * V_16 V_124 ,
struct V_14 * V_24 V_124 ) { }
static int F_183 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_23 = NULL ;
struct V_14 * V_24 ;
struct V_14 * * V_231 = NULL ;
struct V_57 * V_186 ;
struct V_52 * V_53 = & V_91 -> V_93 ;
struct V_113 * V_114 ;
int V_234 ;
int V_4 , V_60 , V_235 , V_122 = 0 ;
char * V_69 ;
V_16 = F_24 ( V_91 -> V_39 , V_91 -> V_41 , V_91 -> V_85 ) ;
if ( ! V_16 ) {
V_4 = - V_50 ;
goto V_11;
}
V_231 = malloc ( sizeof( struct V_14 * ) * V_218 . V_233 ) ;
if ( ! V_231 ) {
V_4 = - V_49 ;
goto V_11;
}
V_234 = F_180 ( V_16 , V_53 -> V_55 , V_231 ) ;
if ( V_234 == 0 ) {
F_55 ( L_159 , V_53 -> V_55 ,
V_91 -> V_39 ? : L_5 ) ;
V_4 = - V_26 ;
goto V_11;
} else if ( V_234 > V_218 . V_233 ) {
F_55 ( L_160 ,
V_91 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_91 -> V_85 && ! V_91 -> V_39 &&
( ! V_53 -> V_89 || F_73 () ) ) {
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
V_4 = - V_50 ;
goto V_11;
}
}
* V_58 = F_116 ( sizeof( * V_186 ) * V_234 ) ;
if ( ! * V_58 ) {
V_4 = - V_49 ;
goto V_11;
}
V_4 = 0 ;
for ( V_235 = 0 ; V_235 < V_234 ; V_235 ++ ) {
V_24 = V_231 [ V_235 ] ;
V_186 = ( * V_58 ) + V_4 ;
V_114 = & V_186 -> V_93 ;
if ( V_4 == V_234 ) {
F_7 ( L_161 ) ;
break;
}
V_4 ++ ;
if ( V_53 -> V_88 > V_24 -> V_97 - V_24 -> V_28 ) {
F_7 ( L_162 ,
V_53 -> V_88 , V_24 -> V_15 ) ;
V_4 = - V_26 ;
goto V_236;
}
V_114 -> V_61 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) + V_53 -> V_88 ;
if ( ! V_91 -> V_85 && ! V_91 -> V_39 &&
F_32 ( V_24 -> V_15 , V_114 -> V_61 ) ) {
V_114 -> V_14 = NULL ;
V_122 ++ ;
} else if ( V_23 ) {
V_114 -> V_14 = F_138 ( V_23 -> V_15 , V_237 ) ;
V_114 -> V_88 = V_114 -> V_61 - V_23 -> V_18 ;
} else {
V_114 -> V_14 = F_138 ( V_24 -> V_15 , V_237 ) ;
V_114 -> V_88 = V_53 -> V_88 ;
}
V_114 -> V_119 = F_138 ( V_24 -> V_15 , V_237 ) ;
V_114 -> V_89 = V_53 -> V_89 ;
if ( V_91 -> V_39 ) {
if ( V_91 -> V_85 ) {
V_186 -> V_93 . V_29 = F_138 ( V_91 -> V_39 ,
V_237 ) ;
} else {
V_69 = F_34 ( V_91 -> V_39 ) ;
V_186 -> V_93 . V_29 =
F_27 ( V_69 ? V_69 : V_91 -> V_39 ) ;
free ( V_69 ) ;
if ( ! V_186 -> V_93 . V_29 )
goto V_237;
}
}
V_186 -> V_85 = V_91 -> V_85 ;
V_186 -> V_183 = V_91 -> V_183 ;
if ( V_186 -> V_183 ) {
V_186 -> args = F_116 ( sizeof( struct V_194 ) *
V_186 -> V_183 ) ;
if ( V_186 -> args == NULL )
goto V_237;
}
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ ) {
if ( V_91 -> args [ V_60 ] . V_15 )
V_186 -> args [ V_60 ] . V_15 =
F_138 ( V_91 -> args [ V_60 ] . V_15 ,
V_237 ) ;
V_186 -> args [ V_60 ] . V_195 = F_138 ( V_91 -> args [ V_60 ] . V_150 ,
V_237 ) ;
if ( V_91 -> args [ V_60 ] . type )
V_186 -> args [ V_60 ] . type =
F_138 ( V_91 -> args [ V_60 ] . type ,
V_237 ) ;
}
F_182 ( V_91 , V_186 , V_16 , V_24 ) ;
}
if ( V_4 == V_122 ) {
V_4 = - V_26 ;
goto V_236;
}
V_11:
F_49 ( V_16 ) ;
free ( V_231 ) ;
return V_4 ;
V_237:
V_4 = - V_49 ;
V_236:
F_30 ( * V_58 , V_234 ) ;
F_62 ( V_58 ) ;
goto V_11;
}
static int F_184 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
struct V_52 * V_53 = & V_91 -> V_93 ;
struct V_57 * V_186 ;
struct V_113 * V_114 ;
int V_60 , V_105 ;
if ( ! ( V_91 -> V_93 . V_55 && ! strncmp ( V_91 -> V_93 . V_55 , L_73 , 2 ) ) )
return - V_50 ;
if ( F_77 ( V_91 ) )
return - V_50 ;
* V_58 = F_116 ( sizeof( * V_186 ) ) ;
if ( ! * V_58 )
return - V_49 ;
V_186 = * V_58 ;
V_114 = & V_186 -> V_93 ;
V_114 -> V_61 = V_91 -> V_93 . V_169 ;
V_114 -> V_89 = V_53 -> V_89 ;
V_186 -> V_85 = V_91 -> V_85 ;
V_105 = - V_49 ;
if ( F_112 ( & V_114 -> V_14 , L_163 , V_114 -> V_61 ) < 0 )
goto V_238;
if ( ( ! V_186 -> V_85 ) &&
( F_32 ( V_186 -> V_93 . V_14 ,
V_186 -> V_93 . V_61 ) ) ) {
V_105 = - V_239 ;
goto V_238;
}
if ( F_112 ( & V_114 -> V_119 , L_164 , V_114 -> V_61 ) < 0 )
goto V_238;
if ( V_91 -> V_39 ) {
V_114 -> V_29 = F_27 ( V_91 -> V_39 ) ;
if ( ! V_114 -> V_29 )
goto V_238;
}
if ( V_186 -> V_165 ) {
V_186 -> V_165 = F_27 ( V_91 -> V_165 ) ;
if ( ! V_186 -> V_165 )
goto V_238;
}
if ( V_91 -> V_166 ) {
V_186 -> V_166 = F_27 ( V_91 -> V_166 ) ;
if ( ! V_186 -> V_166 )
goto V_238;
}
V_186 -> V_183 = V_91 -> V_183 ;
V_186 -> args = F_116 ( sizeof( struct V_194 ) * V_186 -> V_183 ) ;
if ( ! V_186 -> args )
goto V_238;
for ( V_60 = 0 ; V_60 < V_186 -> V_183 ; V_60 ++ )
F_185 ( & V_186 -> args [ V_60 ] , & V_91 -> args [ V_60 ] ) ;
return 1 ;
V_238:
F_30 ( * V_58 , 1 ) ;
* V_58 = NULL ;
return V_105 ;
}
static void * F_186 ( void * V_240 , T_1 V_241 , void * V_242 , T_1 V_243 )
{
void * V_4 ;
V_4 = malloc ( V_241 + V_243 ) ;
if ( V_4 ) {
memcpy ( V_4 , V_240 , V_241 ) ;
memcpy ( V_4 + V_241 , V_242 , V_243 ) ;
}
return V_4 ;
}
static int
F_187 ( struct V_57 * * V_58 , int * V_59 ,
struct V_57 * * V_244 , int V_245 )
{
struct V_57 * V_246 ;
int V_4 = 0 ;
if ( * V_59 == 0 ) {
* V_58 = * V_244 ;
* V_59 = V_245 ;
* V_244 = NULL ;
return 0 ;
}
if ( * V_59 + V_245 > V_218 . V_233 )
V_4 = - V_6 ;
else {
V_246 = F_186 ( * V_58 , ( * V_59 ) * sizeof( * * V_58 ) ,
* V_244 , V_245 * sizeof( * * V_244 ) ) ;
if ( ! V_246 )
V_4 = - V_49 ;
else {
free ( * V_58 ) ;
* V_58 = V_246 ;
* V_59 += V_245 ;
}
}
if ( V_4 < 0 )
F_30 ( * V_244 , V_245 ) ;
F_62 ( V_244 ) ;
return V_4 ;
}
static int F_188 ( struct V_90 * V_91 ,
struct V_57 * * V_58 ,
const char * V_39 )
{
struct V_229 * V_219 ;
struct V_247 * V_248 ;
struct V_57 * V_249 = NULL ;
int V_59 = 0 ;
int V_4 = 0 ;
V_219 = F_176 ( V_39 , V_91 -> V_41 ) ;
if ( ! V_219 )
return 0 ;
F_189 (entry, cache) {
if ( ! V_248 -> V_91 . V_166 || ! V_248 -> V_91 . V_165 )
continue;
if ( ( ! V_91 -> V_165 || F_167 ( V_248 -> V_91 . V_165 , V_91 -> V_165 ) ) &&
F_167 ( V_248 -> V_91 . V_166 , V_91 -> V_166 ) ) {
V_4 = F_190 ( V_248 , & V_249 ) ;
if ( V_4 > 0 )
V_4 = F_187 ( V_58 , & V_59 ,
& V_249 , V_4 ) ;
if ( V_4 < 0 )
break;
}
}
F_179 ( V_219 ) ;
if ( V_4 < 0 ) {
F_30 ( * V_58 , V_59 ) ;
F_62 ( V_58 ) ;
} else {
V_4 = V_59 ;
if ( V_59 > 0 && V_39 && V_39 [ 0 ] == '/' )
V_91 -> V_85 = true ;
}
return V_4 ;
}
static int F_191 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
struct V_57 * V_249 = NULL ;
struct V_213 * V_250 ;
struct V_145 * V_251 ;
char * V_120 ;
int V_59 = 0 ;
int V_4 ;
V_250 = F_192 ( true ) ;
if ( ! V_250 ) {
V_4 = - V_109 ;
F_4 ( L_165 , V_4 ) ;
return V_4 ;
}
V_4 = 0 ;
F_95 (nd, bidlist) {
V_120 = F_111 ( V_251 -> V_152 ) ;
V_4 = F_188 ( V_91 , & V_249 , V_120 ) ;
if ( V_4 > 0 )
V_4 = F_187 ( V_58 , & V_59 ,
& V_249 , V_4 ) ;
free ( V_120 ) ;
if ( V_4 < 0 )
break;
}
F_97 ( V_250 ) ;
if ( V_4 < 0 ) {
F_30 ( * V_58 , V_59 ) ;
F_62 ( V_58 ) ;
} else
V_4 = V_59 ;
return V_4 ;
}
static int F_193 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
struct V_229 * V_219 ;
struct V_247 * V_248 ;
struct V_57 * V_186 ;
struct V_145 * V_146 ;
int V_4 , V_60 ;
if ( V_91 -> V_163 ) {
if ( ! V_91 -> V_39 )
return F_191 ( V_91 , V_58 ) ;
else
return F_188 ( V_91 , V_58 , V_91 -> V_39 ) ;
}
V_219 = F_176 ( V_91 -> V_39 , V_91 -> V_41 ) ;
if ( ! V_219 )
return 0 ;
V_248 = F_194 ( V_219 , V_91 ) ;
if ( ! V_248 ) {
V_4 = V_91 -> V_163 ? - V_26 : 0 ;
goto V_11;
}
V_4 = F_195 ( V_248 -> V_252 ) ;
if ( V_4 > V_218 . V_233 ) {
F_4 ( L_166 ,
V_91 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
* V_58 = F_116 ( V_4 * sizeof( * V_186 ) ) ;
if ( ! * V_58 ) {
V_4 = - V_49 ;
goto V_11;
}
V_60 = 0 ;
F_95 (node, entry->tevlist) {
V_186 = & ( * V_58 ) [ V_60 ++ ] ;
V_4 = F_121 ( V_146 -> V_152 , V_186 ) ;
if ( V_4 < 0 )
goto V_11;
V_186 -> V_85 = V_91 -> V_85 ;
}
V_4 = V_60 ;
V_11:
F_179 ( V_219 ) ;
return V_4 ;
}
static int F_196 ( struct V_90 * V_91 ,
struct V_57 * * V_58 )
{
int V_4 ;
if ( ! V_91 -> V_165 && ! V_91 -> V_163 ) {
if ( ! V_91 -> V_85 ) {
V_91 -> V_165 = F_27 ( V_51 ) ;
V_4 = V_91 -> V_165 ? 0 : - V_49 ;
} else
V_4 = F_26 ( V_91 -> V_39 , & V_91 -> V_165 ) ;
if ( V_4 != 0 ) {
F_7 ( L_167 ) ;
return V_4 ;
}
}
V_4 = F_184 ( V_91 , V_58 ) ;
if ( V_4 > 0 )
return V_4 ;
V_4 = F_193 ( V_91 , V_58 ) ;
if ( V_4 > 0 || V_91 -> V_163 )
return V_4 == 0 ? - V_26 : V_4 ;
V_4 = F_76 ( V_91 , V_58 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_183 ( V_91 , V_58 ) ;
}
int F_197 ( struct V_90 * V_153 , int V_154 )
{
int V_60 , V_4 ;
for ( V_60 = 0 ; V_60 < V_154 ; V_60 ++ ) {
if ( ! V_153 [ V_60 ] . V_85 )
F_152 () ;
V_4 = F_196 ( & V_153 [ V_60 ] , & V_153 [ V_60 ] . V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
V_153 [ V_60 ] . V_59 = V_4 ;
}
F_153 () ;
return 0 ;
}
static int F_198 ( struct V_57 * V_186 )
{
char * V_48 = F_132 ( V_186 ) ;
if ( ! V_48 ) {
F_4 ( L_168 ) ;
return - V_50 ;
}
printf ( L_97 , V_48 ) ;
free ( V_48 ) ;
return 0 ;
}
int F_199 ( struct V_90 * V_153 , int V_154 )
{
struct V_213 * V_221 = F_200 ( NULL , NULL ) ;
struct V_57 * V_186 ;
struct V_90 * V_91 ;
int V_60 , V_235 , V_4 = 0 ;
if ( ! V_221 )
return - V_49 ;
for ( V_235 = 0 ; V_235 < V_154 && ! V_4 ; V_235 ++ ) {
V_91 = & V_153 [ V_235 ] ;
for ( V_60 = 0 ; V_60 < V_91 -> V_59 && ! V_4 ; V_60 ++ ) {
V_186 = & V_91 -> V_58 [ V_60 ] ;
if ( ! V_186 -> V_93 . V_14 && ! V_91 -> V_85 )
continue;
V_4 = F_168 ( V_186 , V_91 ,
V_221 , true ) ;
if ( ! V_4 )
V_4 = F_198 ( V_186 ) ;
}
}
F_97 ( V_221 ) ;
return V_4 ;
}
int F_201 ( struct V_90 * V_153 , int V_154 )
{
int V_60 , V_4 = 0 ;
for ( V_60 = 0 ; V_60 < V_154 ; V_60 ++ ) {
V_4 = F_174 ( & V_153 [ V_60 ] , V_153 [ V_60 ] . V_58 ,
V_153 [ V_60 ] . V_59 ,
V_218 . V_253 ) ;
if ( V_4 < 0 )
break;
}
return V_4 ;
}
void F_202 ( struct V_90 * V_153 , int V_154 )
{
int V_60 , V_235 ;
struct V_90 * V_91 ;
for ( V_60 = 0 ; V_60 < V_154 ; V_60 ++ ) {
V_91 = & V_153 [ V_60 ] ;
for ( V_235 = 0 ; V_235 < V_153 [ V_60 ] . V_59 ; V_235 ++ )
F_31 ( & V_153 [ V_60 ] . V_58 [ V_235 ] ) ;
F_62 ( & V_153 [ V_60 ] . V_58 ) ;
V_153 [ V_60 ] . V_59 = 0 ;
F_203 ( V_91 -> V_41 ) ;
F_136 ( & V_153 [ V_60 ] ) ;
}
}
int F_204 ( struct V_90 * V_153 , int V_154 )
{
int V_4 ;
V_4 = F_2 ( V_153 -> V_85 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_197 ( V_153 , V_154 ) ;
if ( V_4 == 0 )
V_4 = F_201 ( V_153 , V_154 ) ;
F_202 ( V_153 , V_154 ) ;
F_8 () ;
return V_4 ;
}
int F_205 ( struct V_142 * T_11 )
{
int V_4 , V_254 , V_255 = - 1 , V_256 = - 1 ;
char * V_1 = F_206 ( T_11 ) ;
if ( ! V_1 )
return - V_50 ;
V_4 = F_163 ( & V_256 , & V_255 , V_226 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_207 ( V_256 , T_11 ) ;
if ( V_4 < 0 && V_4 != - V_26 )
goto error;
V_254 = F_207 ( V_255 , T_11 ) ;
if ( V_254 < 0 && V_254 != - V_26 ) {
V_4 = V_254 ;
goto error;
}
V_4 = 0 ;
error:
if ( V_256 >= 0 )
F_41 ( V_256 ) ;
if ( V_255 >= 0 )
F_41 ( V_255 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
int F_208 ( const char * V_39 , struct V_40 * V_41 ,
struct V_142 * V_143 , bool V_42 )
{
struct V_232 * V_251 ;
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 ( V_42 ) ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_24 ( V_39 , V_41 , V_42 ) ;
if ( ! V_16 ) {
F_55 ( L_169 , ( V_39 ) ? : L_5 ) ;
return - V_50 ;
}
V_4 = F_16 ( V_16 ) ;
if ( V_4 ) {
if ( V_4 == - 2 ) {
char * V_1 = F_206 ( V_143 ) ;
F_55 ( L_170 ,
V_1 ) ;
free ( V_1 ) ;
} else
F_55 ( L_171 ,
( V_39 ) ? : L_5 ) ;
goto V_97;
}
if ( ! F_209 ( V_16 -> V_36 , V_16 -> type ) )
F_210 ( V_16 -> V_36 , V_16 -> type ) ;
F_86 () ;
for ( V_251 = F_211 ( & V_16 -> V_36 -> V_257 [ V_16 -> type ] ) ; V_251 ; V_251 = F_212 ( V_251 ) ) {
struct V_258 * V_35 = F_213 ( V_251 , struct V_258 , V_232 ) ;
if ( F_96 ( V_143 , V_35 -> V_24 . V_15 ) )
printf ( L_97 , V_35 -> V_24 . V_15 ) ;
}
V_97:
F_49 ( V_16 ) ;
F_8 () ;
return V_4 ;
}
int F_185 ( struct V_194 * V_259 ,
struct V_170 * V_260 )
{
V_259 -> V_195 = F_27 ( V_260 -> V_150 ) ;
if ( V_259 -> V_195 == NULL )
return - V_49 ;
if ( V_260 -> type ) {
V_259 -> type = F_27 ( V_260 -> type ) ;
if ( V_259 -> type == NULL )
return - V_49 ;
}
if ( V_260 -> V_15 ) {
V_259 -> V_15 = F_27 ( V_260 -> V_15 ) ;
if ( V_259 -> V_15 == NULL )
return - V_49 ;
} else
V_259 -> V_15 = NULL ;
return 0 ;
}
