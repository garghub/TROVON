int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * T_2 V_2 ,
struct V_8 * V_8 )
{
struct V_9 V_10 ;
struct V_11 * V_11 = F_2 ( V_8 , V_6 -> V_12 ,
V_6 -> V_13 ) ;
if ( V_11 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_14 . type ) ;
return - 1 ;
}
F_4 ( V_11 , V_6 -> V_15 , V_16 , V_6 -> V_17 , & V_10 ) ;
if ( V_10 . V_18 != NULL )
V_10 . V_18 -> V_19 -> V_20 = 1 ;
F_5 ( V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6
V_2 ,
struct V_8 * V_8 )
{
struct V_11 * V_11 = F_2 ( V_8 ,
V_4 -> V_21 . V_12 ,
V_4 -> V_21 . V_13 ) ;
F_7 ( L_2 , V_4 -> V_21 . V_12 , V_4 -> V_21 . V_13 ,
V_4 -> V_21 . V_22 , V_4 -> V_21 . V_23 ) ;
if ( V_11 ) {
F_8 ( V_8 , V_11 ) ;
F_5 ( V_11 ) ;
}
return 0 ;
}
int F_9 ( const T_3 * V_24 , int V_25 , char * V_26 )
{
char * V_27 = V_26 ;
const T_3 * V_28 = V_24 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; ++ V_29 ) {
sprintf ( V_27 , L_3 , * V_28 ) ;
++ V_28 ;
V_27 += 2 ;
}
return ( V_27 - V_26 ) + 1 ;
}
int F_10 ( const char * V_30 , char * V_31 )
{
char V_32 [ V_33 ] ;
T_3 V_24 [ V_34 ] ;
int V_35 ;
if ( ! V_30 )
V_30 = L_4 ;
F_11 ( V_32 , sizeof( V_32 ) , L_5 , V_30 ) ;
V_35 = F_12 ( V_32 , V_24 , sizeof( V_24 ) ) ;
if ( V_35 < 0 )
return V_35 ;
return F_9 ( V_24 , sizeof( V_24 ) , V_31 ) ;
}
int F_13 ( const char * V_36 , char * V_31 )
{
T_3 V_24 [ V_34 ] ;
int V_35 ;
V_35 = F_14 ( V_36 , V_24 , sizeof( V_24 ) ) ;
if ( V_35 < 0 )
return V_35 ;
else if ( V_35 != sizeof( V_24 ) )
return - V_37 ;
return F_9 ( V_24 , sizeof( V_24 ) , V_31 ) ;
}
static int F_15 ( char * * V_38 , T_4 V_39 , const char * V_40 , ... )
{
T_5 V_41 ;
int V_35 ;
if ( ! V_38 )
return - V_37 ;
va_start ( V_41 , V_40 ) ;
if ( * V_38 )
V_35 = vsnprintf ( * V_38 , V_39 , V_40 , V_41 ) ;
else
V_35 = F_16 ( V_38 , V_40 , V_41 ) ;
va_end ( V_41 ) ;
return V_35 ;
}
static char * F_17 ( const char * V_31 , char * V_26 , T_4 V_39 )
{
char * V_42 = V_26 ;
int V_35 = F_15 ( & V_26 , V_39 , L_6 , V_43 ,
V_31 , V_31 + 2 ) ;
if ( V_35 < 0 || ( V_42 && V_39 < ( unsigned int ) V_35 ) )
return NULL ;
return V_26 ;
}
char * F_18 ( const struct V_19 * V_19 , char * V_26 , T_4 V_39 )
{
char V_44 [ V_45 ] ;
if ( ! V_19 -> V_46 )
return NULL ;
F_9 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_44 ) ;
return F_17 ( V_44 , V_26 , V_39 ) ;
}
bool F_19 ( const struct V_19 * V_19 , char * V_26 , T_4 V_39 )
{
char * V_47 , * V_48 ;
struct V_49 V_50 ;
V_47 = F_18 ( V_19 , V_26 , V_39 ) ;
if ( ! V_47 )
goto V_51;
if ( F_20 ( V_47 , V_52 ) )
goto V_51;
if ( F_21 ( V_47 , & V_50 ) == - 1 )
goto V_51;
if ( ( T_4 ) V_50 . V_53 > V_39 - 1 )
goto V_51;
if ( F_22 ( V_47 , V_26 , V_39 - 1 ) < 0 )
goto V_51;
V_26 [ V_50 . V_53 ] = '\0' ;
V_48 = strrchr ( V_26 , '/' ) ;
if ( ! V_48 )
goto V_51;
if ( V_48 - 3 < V_26 )
goto V_51;
return strncmp ( L_7 , V_48 - 3 , 3 ) == 0 ;
V_51:
if ( V_47 )
V_47 = F_18 ( V_19 , V_26 , V_39 ) ;
F_3 ( L_8 , V_47 ? :
V_19 -> V_54 ? :
V_19 -> V_55 ? :
L_9 ) ;
return false ;
}
static int F_23 ( const char * V_56 , T_4 V_57 , T_3 * V_24 ,
T_6 V_12 , T_7 V_58 , int V_59 )
{
int V_51 ;
struct V_60 V_61 ;
T_4 V_25 ;
V_25 = V_57 + 1 ;
V_25 = F_24 ( V_25 , V_62 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memcpy ( & V_61 . V_24 , V_24 , V_34 ) ;
V_61 . V_12 = V_12 ;
V_61 . V_14 . V_58 = V_58 ;
V_61 . V_14 . V_39 = sizeof( V_61 ) + V_25 ;
V_51 = F_25 ( V_59 , & V_61 , sizeof( V_61 ) ) ;
if ( V_51 < 0 )
return V_51 ;
return F_26 ( V_59 , V_56 , V_57 + 1 , V_25 ) ;
}
static int F_27 ( struct V_8 * V_8 , int V_59 )
{
int V_51 = 0 ;
char V_63 [ V_33 ] ;
struct V_19 * V_64 ;
T_7 V_65 = V_66 ,
V_67 = V_68 ;
if ( ! F_28 ( V_8 ) ) {
V_65 = V_69 ;
V_67 = V_70 ;
}
F_29 (pos, &machine->dsos.head) {
const char * V_56 ;
T_4 V_57 ;
bool V_71 = false ;
if ( ! V_64 -> V_20 && ! F_30 ( V_64 ) )
continue;
if ( F_30 ( V_64 ) ) {
V_56 = V_64 -> V_55 ;
V_57 = V_64 -> V_72 ;
} else if ( F_31 ( V_64 ) ) {
F_32 ( V_8 , V_63 , sizeof( V_63 ) ) ;
V_56 = V_63 ;
V_57 = strlen ( V_63 ) ;
} else {
V_56 = V_64 -> V_54 ;
V_57 = V_64 -> V_73 ;
}
V_71 = V_64 -> V_74 ||
F_33 ( V_56 ,
V_75 ) ;
V_51 = F_23 ( V_56 , V_57 , V_64 -> V_24 , V_8 -> V_12 ,
V_71 ? V_65 : V_67 , V_59 ) ;
if ( V_51 )
break;
}
return V_51 ;
}
int F_34 ( struct V_76 * V_77 , int V_59 )
{
struct V_78 * V_79 ;
int V_51 = F_27 ( & V_77 -> V_80 . V_81 , V_59 ) ;
if ( V_51 )
return V_51 ;
for ( V_79 = F_35 ( & V_77 -> V_80 . V_82 ) ; V_79 ; V_79 = F_36 ( V_79 ) ) {
struct V_8 * V_64 = F_37 ( V_79 , struct V_8 , V_78 ) ;
V_51 = F_27 ( V_64 , V_59 ) ;
if ( V_51 )
break;
}
return V_51 ;
}
static int F_38 ( struct V_83 * V_84 )
{
struct V_19 * V_64 ;
F_39 (pos, head, node)
V_64 -> V_20 = true ;
return 0 ;
}
static int F_40 ( struct V_8 * V_8 )
{
return F_38 ( & V_8 -> V_85 . V_84 ) ;
}
int F_41 ( struct V_76 * V_77 )
{
struct V_78 * V_79 ;
int V_51 ;
V_51 = F_40 ( & V_77 -> V_80 . V_81 ) ;
if ( V_51 )
return V_51 ;
for ( V_79 = F_35 ( & V_77 -> V_80 . V_82 ) ; V_79 ; V_79 = F_36 ( V_79 ) ) {
struct V_8 * V_64 = F_37 ( V_79 , struct V_8 , V_78 ) ;
V_51 = F_40 ( V_64 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
void F_42 ( void )
{
V_86 = true ;
}
static char * F_43 ( const char * V_56 ,
bool V_87 , bool V_88 )
{
char * V_89 = ( char * ) V_56 , * V_90 ;
bool V_91 = V_87 || V_88 ;
if ( ! V_91 ) {
V_89 = F_44 ( V_56 , NULL ) ;
if ( ! V_89 )
return NULL ;
}
if ( F_45 ( & V_90 , L_10 , V_43 , V_91 ? L_11 : L_4 ,
V_88 ? V_92 : V_89 ) < 0 )
V_90 = NULL ;
if ( ! V_91 )
free ( V_89 ) ;
return V_90 ;
}
int F_46 ( const char * V_36 ,
struct V_93 * * V_94 )
{
char * V_95 ;
int V_35 = 0 ;
V_95 = F_43 ( V_36 , false , false ) ;
if ( ! V_95 )
return - V_96 ;
* V_94 = F_47 ( V_95 , V_97 ) ;
if ( ! * V_94 )
V_35 = - V_98 ;
free ( V_95 ) ;
return V_35 ;
}
int F_48 ( const char * V_31 , const char * V_56 ,
bool V_87 , bool V_88 )
{
const T_4 V_39 = V_33 ;
char * V_89 = NULL , * V_90 = NULL , * V_95 = NULL ,
* V_99 = F_49 ( V_39 ) , * V_100 , * V_42 ;
int V_51 = - 1 ;
if ( ! V_87 ) {
V_89 = F_44 ( V_56 , NULL ) ;
if ( ! V_89 )
goto V_101;
}
V_95 = F_43 ( V_56 , V_87 , V_88 ) ;
if ( ! V_95 )
goto V_101;
if ( F_50 ( V_95 , 0755 ) )
goto V_101;
if ( F_45 ( & V_90 , L_12 , V_95 , V_31 ) < 0 ) {
V_90 = NULL ;
goto V_101;
}
if ( F_20 ( V_90 , V_52 ) ) {
if ( V_87 ) {
if ( F_51 ( L_13 , V_90 ) )
goto V_101;
} else if ( F_52 ( V_89 , V_90 ) && V_98 != V_102 &&
F_51 ( V_56 , V_90 ) )
goto V_101;
}
if ( ! F_17 ( V_31 , V_99 , V_39 ) )
goto V_101;
V_42 = strrchr ( V_99 , '/' ) ;
* V_42 = '\0' ;
if ( F_20 ( V_99 , V_103 ) && F_50 ( V_99 , 0755 ) )
goto V_101;
* V_42 = '/' ;
V_100 = V_90 + strlen ( V_43 ) - 5 ;
memcpy ( V_100 , L_14 , 5 ) ;
if ( F_53 ( V_100 , V_99 ) == 0 )
V_51 = 0 ;
V_101:
if ( ! V_87 )
free ( V_89 ) ;
free ( V_90 ) ;
free ( V_95 ) ;
free ( V_99 ) ;
return V_51 ;
}
static int F_54 ( const T_3 * V_24 , T_4 V_104 ,
const char * V_56 , bool V_87 ,
bool V_88 )
{
char V_31 [ V_45 ] ;
F_9 ( V_24 , V_104 , V_31 ) ;
return F_48 ( V_31 , V_56 , V_87 , V_88 ) ;
}
bool F_55 ( const char * V_31 )
{
bool V_35 = false ;
char * V_90 = F_17 ( V_31 , NULL , 0 ) ;
if ( V_90 && ! F_20 ( V_90 , V_52 ) )
V_35 = true ;
free ( V_90 ) ;
return V_35 ;
}
int F_56 ( const char * V_31 )
{
const T_4 V_39 = V_33 ;
char * V_90 = F_49 ( V_39 ) ,
* V_99 = F_49 ( V_39 ) , * V_42 ;
int V_51 = - 1 ;
if ( V_90 == NULL || V_99 == NULL )
goto V_101;
if ( ! F_17 ( V_31 , V_99 , V_39 ) )
goto V_101;
if ( F_20 ( V_99 , V_52 ) )
goto V_101;
if ( F_22 ( V_99 , V_90 , V_39 - 1 ) < 0 )
goto V_101;
if ( F_57 ( V_99 ) )
goto V_101;
V_42 = strrchr ( V_99 , '/' ) + 1 ;
snprintf ( V_42 , V_39 - ( V_42 - V_99 ) , L_15 , V_90 ) ;
if ( F_57 ( V_99 ) )
goto V_101;
V_51 = 0 ;
V_101:
free ( V_90 ) ;
free ( V_99 ) ;
return V_51 ;
}
static int F_58 ( struct V_19 * V_19 , struct V_8 * V_8 )
{
bool V_87 = V_19 -> V_74 && V_19 -> V_54 [ 0 ] != '/' ;
bool V_88 = F_30 ( V_19 ) ;
const char * V_56 = V_19 -> V_54 ;
char V_63 [ V_33 ] ;
if ( F_31 ( V_19 ) ) {
V_87 = true ;
F_32 ( V_8 , V_63 , sizeof( V_63 ) ) ;
V_56 = V_63 ;
}
return F_54 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_56 ,
V_87 , V_88 ) ;
}
static int F_59 ( struct V_83 * V_84 ,
struct V_8 * V_8 )
{
struct V_19 * V_64 ;
int V_51 = 0 ;
F_29 (pos, head)
if ( F_58 ( V_64 , V_8 ) )
V_51 = - 1 ;
return V_51 ;
}
static int F_60 ( struct V_8 * V_8 )
{
return F_59 ( & V_8 -> V_85 . V_84 , V_8 ) ;
}
int F_61 ( struct V_76 * V_77 )
{
struct V_78 * V_79 ;
int V_35 ;
if ( V_86 )
return 0 ;
if ( F_62 ( V_43 , 0755 ) != 0 && V_98 != V_102 )
return - 1 ;
V_35 = F_60 ( & V_77 -> V_80 . V_81 ) ;
for ( V_79 = F_35 ( & V_77 -> V_80 . V_82 ) ; V_79 ; V_79 = F_36 ( V_79 ) ) {
struct V_8 * V_64 = F_37 ( V_79 , struct V_8 , V_78 ) ;
V_35 |= F_60 ( V_64 ) ;
}
return V_35 ? - 1 : 0 ;
}
static bool F_63 ( struct V_8 * V_8 , bool V_105 )
{
return F_64 ( & V_8 -> V_85 . V_84 , V_105 ) ;
}
bool F_65 ( struct V_76 * V_77 , bool V_105 )
{
struct V_78 * V_79 ;
bool V_35 = F_63 ( & V_77 -> V_80 . V_81 , V_105 ) ;
for ( V_79 = F_35 ( & V_77 -> V_80 . V_82 ) ; V_79 ; V_79 = F_36 ( V_79 ) ) {
struct V_8 * V_64 = F_37 ( V_79 , struct V_8 , V_78 ) ;
V_35 |= F_63 ( V_64 , V_105 ) ;
}
return V_35 ;
}
