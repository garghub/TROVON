int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * T_2 V_2 ,
struct V_8 * V_8 )
{
struct V_9 V_10 ;
T_3 V_11 = V_4 -> V_12 . V_13 & V_14 ;
struct V_15 * V_15 = F_2 ( V_8 , V_6 -> V_16 ,
V_6 -> V_17 ) ;
if ( V_15 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_12 . type ) ;
return - 1 ;
}
F_4 ( V_15 , V_11 , V_18 , V_6 -> V_19 , & V_10 ) ;
if ( V_10 . V_20 != NULL )
V_10 . V_20 -> V_21 -> V_22 = 1 ;
F_5 ( V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6
V_2 ,
struct V_8 * V_8 )
{
struct V_15 * V_15 = F_2 ( V_8 ,
V_4 -> V_23 . V_16 ,
V_4 -> V_23 . V_17 ) ;
F_7 ( L_2 , V_4 -> V_23 . V_16 , V_4 -> V_23 . V_17 ,
V_4 -> V_23 . V_24 , V_4 -> V_23 . V_25 ) ;
if ( V_15 ) {
F_8 ( V_8 , V_15 ) ;
F_5 ( V_15 ) ;
}
return 0 ;
}
int F_9 ( const T_3 * V_26 , int V_27 , char * V_28 )
{
char * V_29 = V_28 ;
const T_3 * V_30 = V_26 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_27 ; ++ V_31 ) {
sprintf ( V_29 , L_3 , * V_30 ) ;
++ V_30 ;
V_29 += 2 ;
}
return ( V_29 - V_28 ) + 1 ;
}
int F_10 ( const char * V_32 , char * V_33 )
{
char V_34 [ V_35 ] ;
T_3 V_26 [ V_36 ] ;
int V_37 ;
if ( ! V_32 )
V_32 = L_4 ;
F_11 ( V_34 , sizeof( V_34 ) , L_5 , V_32 ) ;
V_37 = F_12 ( V_34 , V_26 , sizeof( V_26 ) ) ;
if ( V_37 < 0 )
return V_37 ;
return F_9 ( V_26 , sizeof( V_26 ) , V_33 ) ;
}
int F_13 ( const char * V_38 , char * V_33 )
{
T_3 V_26 [ V_36 ] ;
int V_37 ;
V_37 = F_14 ( V_38 , V_26 , sizeof( V_26 ) ) ;
if ( V_37 < 0 )
return V_37 ;
else if ( V_37 != sizeof( V_26 ) )
return - V_39 ;
return F_9 ( V_26 , sizeof( V_26 ) , V_33 ) ;
}
static int F_15 ( char * * V_40 , T_4 V_41 , const char * V_42 , ... )
{
T_5 V_43 ;
int V_37 ;
if ( ! V_40 )
return - V_39 ;
va_start ( V_43 , V_42 ) ;
if ( * V_40 )
V_37 = vsnprintf ( * V_40 , V_41 , V_42 , V_43 ) ;
else
V_37 = F_16 ( V_40 , V_42 , V_43 ) ;
va_end ( V_43 ) ;
return V_37 ;
}
static char * F_17 ( const char * V_33 , char * V_28 , T_4 V_41 )
{
char * V_44 = V_28 ;
int V_37 = F_15 ( & V_28 , V_41 , L_6 , V_45 ,
V_33 , V_33 + 2 ) ;
if ( V_37 < 0 || ( V_44 && V_41 < ( unsigned int ) V_37 ) )
return NULL ;
return V_28 ;
}
char * F_18 ( const struct V_21 * V_21 , char * V_28 , T_4 V_41 )
{
char V_46 [ V_47 ] ;
if ( ! V_21 -> V_48 )
return NULL ;
F_9 ( V_21 -> V_26 , sizeof( V_21 -> V_26 ) , V_46 ) ;
return F_17 ( V_46 , V_28 , V_41 ) ;
}
static int F_19 ( const char * V_49 , T_4 V_50 , T_3 * V_26 ,
T_6 V_16 , T_7 V_13 , int V_51 )
{
int V_52 ;
struct V_53 V_54 ;
T_4 V_27 ;
V_27 = V_50 + 1 ;
V_27 = F_20 ( V_27 , V_55 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
memcpy ( & V_54 . V_26 , V_26 , V_36 ) ;
V_54 . V_16 = V_16 ;
V_54 . V_12 . V_13 = V_13 ;
V_54 . V_12 . V_41 = sizeof( V_54 ) + V_27 ;
V_52 = F_21 ( V_51 , & V_54 , sizeof( V_54 ) ) ;
if ( V_52 < 0 )
return V_52 ;
return F_22 ( V_51 , V_49 , V_50 + 1 , V_27 ) ;
}
static int F_23 ( struct V_8 * V_8 , int V_51 )
{
int V_52 = 0 ;
char V_56 [ V_35 ] ;
struct V_21 * V_57 ;
T_7 V_58 = V_59 ,
V_60 = V_61 ;
if ( ! F_24 ( V_8 ) ) {
V_58 = V_62 ;
V_60 = V_63 ;
}
F_25 (pos, &machine->dsos.head) {
const char * V_49 ;
T_4 V_50 ;
if ( ! V_57 -> V_22 )
continue;
if ( F_26 ( V_57 ) ) {
V_49 = V_57 -> V_64 ;
V_50 = V_57 -> V_65 + 1 ;
} else if ( F_27 ( V_57 ) ) {
F_28 ( V_8 , V_56 , sizeof( V_56 ) ) ;
V_49 = V_56 ;
V_50 = strlen ( V_56 ) + 1 ;
} else {
V_49 = V_57 -> V_66 ;
V_50 = V_57 -> V_67 + 1 ;
}
V_52 = F_19 ( V_49 , V_50 , V_57 -> V_26 , V_8 -> V_16 ,
V_57 -> V_68 ? V_58 : V_60 , V_51 ) ;
if ( V_52 )
break;
}
return V_52 ;
}
int F_29 ( struct V_69 * V_70 , int V_51 )
{
struct V_71 * V_72 ;
int V_52 = F_23 ( & V_70 -> V_73 . V_74 , V_51 ) ;
if ( V_52 )
return V_52 ;
for ( V_72 = F_30 ( & V_70 -> V_73 . V_75 ) ; V_72 ; V_72 = F_31 ( V_72 ) ) {
struct V_8 * V_57 = F_32 ( V_72 , struct V_8 , V_71 ) ;
V_52 = F_23 ( V_57 , V_51 ) ;
if ( V_52 )
break;
}
return V_52 ;
}
static int F_33 ( struct V_76 * V_77 )
{
struct V_21 * V_57 ;
F_34 (pos, head, node)
V_57 -> V_22 = true ;
return 0 ;
}
static int F_35 ( struct V_8 * V_8 )
{
return F_33 ( & V_8 -> V_78 . V_77 ) ;
}
int F_36 ( struct V_69 * V_70 )
{
struct V_71 * V_72 ;
int V_52 ;
V_52 = F_35 ( & V_70 -> V_73 . V_74 ) ;
if ( V_52 )
return V_52 ;
for ( V_72 = F_30 ( & V_70 -> V_73 . V_75 ) ; V_72 ; V_72 = F_31 ( V_72 ) ) {
struct V_8 * V_57 = F_32 ( V_72 , struct V_8 , V_71 ) ;
V_52 = F_35 ( V_57 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
void F_37 ( void )
{
V_79 = true ;
}
static char * F_38 ( const char * V_49 ,
bool V_80 , bool V_81 )
{
char * V_82 = ( char * ) V_49 , * V_83 ;
bool V_84 = V_80 || V_81 ;
if ( ! V_84 ) {
V_82 = F_39 ( V_49 , NULL ) ;
if ( ! V_82 )
return NULL ;
}
if ( F_40 ( & V_83 , L_7 , V_45 , V_84 ? L_8 : L_4 ,
V_81 ? V_85 : V_82 ) < 0 )
V_83 = NULL ;
if ( ! V_84 )
free ( V_82 ) ;
return V_83 ;
}
int F_41 ( const char * V_38 ,
struct V_86 * * V_87 )
{
struct V_86 * V_88 ;
char * V_89 ;
T_8 * V_90 ;
struct V_91 * V_92 ;
int V_37 = 0 ;
V_88 = F_42 ( NULL , NULL ) ;
V_89 = F_38 ( V_38 , false , false ) ;
if ( ! V_88 || ! V_89 ) {
V_37 = - V_93 ;
goto V_94;
}
V_90 = F_43 ( V_89 ) ;
if ( ! V_90 ) {
V_37 = - V_95 ;
goto V_94;
}
while ( ( V_92 = F_44 ( V_90 ) ) != NULL ) {
if ( ! strcmp ( V_92 -> V_96 , L_9 ) || ! strcmp ( V_92 -> V_96 , L_10 ) )
continue;
F_45 ( V_88 , V_92 -> V_96 ) ;
}
F_46 ( V_90 ) ;
V_94:
free ( V_89 ) ;
if ( V_37 )
F_47 ( V_88 ) ;
else
* V_87 = V_88 ;
return V_37 ;
}
int F_48 ( const char * V_33 , const char * V_49 ,
bool V_80 , bool V_81 )
{
const T_4 V_41 = V_35 ;
char * V_82 = NULL , * V_83 = NULL , * V_89 = NULL ,
* V_97 = F_49 ( V_41 ) , * V_98 , * V_44 ;
int V_52 = - 1 ;
if ( ! V_80 ) {
V_82 = F_39 ( V_49 , NULL ) ;
if ( ! V_82 )
goto V_99;
}
V_89 = F_38 ( V_49 , V_80 , V_81 ) ;
if ( ! V_89 )
goto V_99;
if ( F_50 ( V_89 , 0755 ) )
goto V_99;
if ( F_40 ( & V_83 , L_11 , V_89 , V_33 ) < 0 ) {
V_83 = NULL ;
goto V_99;
}
if ( F_51 ( V_83 , V_100 ) ) {
if ( V_80 ) {
if ( F_52 ( L_12 , V_83 ) )
goto V_99;
} else if ( F_53 ( V_82 , V_83 ) && V_95 != V_101 &&
F_52 ( V_49 , V_83 ) )
goto V_99;
}
if ( ! F_17 ( V_33 , V_97 , V_41 ) )
goto V_99;
V_44 = strrchr ( V_97 , '/' ) ;
* V_44 = '\0' ;
if ( F_51 ( V_97 , V_102 ) && F_50 ( V_97 , 0755 ) )
goto V_99;
* V_44 = '/' ;
V_98 = V_83 + strlen ( V_45 ) - 5 ;
memcpy ( V_98 , L_13 , 5 ) ;
if ( F_54 ( V_98 , V_97 ) == 0 )
V_52 = 0 ;
V_99:
if ( ! V_80 )
free ( V_82 ) ;
free ( V_83 ) ;
free ( V_89 ) ;
free ( V_97 ) ;
return V_52 ;
}
static int F_55 ( const T_3 * V_26 , T_4 V_103 ,
const char * V_49 , bool V_80 ,
bool V_81 )
{
char V_33 [ V_47 ] ;
F_9 ( V_26 , V_103 , V_33 ) ;
return F_48 ( V_33 , V_49 , V_80 , V_81 ) ;
}
bool F_56 ( const char * V_33 )
{
bool V_37 = false ;
char * V_83 = F_17 ( V_33 , NULL , 0 ) ;
if ( V_83 && ! F_51 ( V_83 , V_100 ) )
V_37 = true ;
free ( V_83 ) ;
return V_37 ;
}
int F_57 ( const char * V_33 )
{
const T_4 V_41 = V_35 ;
char * V_83 = F_49 ( V_41 ) ,
* V_97 = F_49 ( V_41 ) , * V_44 ;
int V_52 = - 1 ;
if ( V_83 == NULL || V_97 == NULL )
goto V_99;
if ( ! F_17 ( V_33 , V_97 , V_41 ) )
goto V_99;
if ( F_51 ( V_97 , V_100 ) )
goto V_99;
if ( F_58 ( V_97 , V_83 , V_41 - 1 ) < 0 )
goto V_99;
if ( F_59 ( V_97 ) )
goto V_99;
V_44 = strrchr ( V_97 , '/' ) + 1 ;
snprintf ( V_44 , V_41 - ( V_44 - V_97 ) , L_14 , V_83 ) ;
if ( F_59 ( V_97 ) )
goto V_99;
V_52 = 0 ;
V_99:
free ( V_83 ) ;
free ( V_97 ) ;
return V_52 ;
}
static int F_60 ( struct V_21 * V_21 , struct V_8 * V_8 )
{
bool V_80 = V_21 -> V_68 && V_21 -> V_66 [ 0 ] != '/' ;
bool V_81 = F_26 ( V_21 ) ;
const char * V_49 = V_21 -> V_66 ;
char V_56 [ V_35 ] ;
if ( F_27 ( V_21 ) ) {
V_80 = true ;
F_28 ( V_8 , V_56 , sizeof( V_56 ) ) ;
V_49 = V_56 ;
}
return F_55 ( V_21 -> V_26 , sizeof( V_21 -> V_26 ) , V_49 ,
V_80 , V_81 ) ;
}
static int F_61 ( struct V_76 * V_77 ,
struct V_8 * V_8 )
{
struct V_21 * V_57 ;
int V_52 = 0 ;
F_25 (pos, head)
if ( F_60 ( V_57 , V_8 ) )
V_52 = - 1 ;
return V_52 ;
}
static int F_62 ( struct V_8 * V_8 )
{
return F_61 ( & V_8 -> V_78 . V_77 , V_8 ) ;
}
int F_63 ( struct V_69 * V_70 )
{
struct V_71 * V_72 ;
int V_37 ;
if ( V_79 )
return 0 ;
if ( F_64 ( V_45 , 0755 ) != 0 && V_95 != V_101 )
return - 1 ;
V_37 = F_62 ( & V_70 -> V_73 . V_74 ) ;
for ( V_72 = F_30 ( & V_70 -> V_73 . V_75 ) ; V_72 ; V_72 = F_31 ( V_72 ) ) {
struct V_8 * V_57 = F_32 ( V_72 , struct V_8 , V_71 ) ;
V_37 |= F_62 ( V_57 ) ;
}
return V_37 ? - 1 : 0 ;
}
static bool F_65 ( struct V_8 * V_8 , bool V_104 )
{
return F_66 ( & V_8 -> V_78 . V_77 , V_104 ) ;
}
bool F_67 ( struct V_69 * V_70 , bool V_104 )
{
struct V_71 * V_72 ;
bool V_37 = F_65 ( & V_70 -> V_73 . V_74 , V_104 ) ;
for ( V_72 = F_30 ( & V_70 -> V_73 . V_75 ) ; V_72 ; V_72 = F_31 ( V_72 ) ) {
struct V_8 * V_57 = F_32 ( V_72 , struct V_8 , V_71 ) ;
V_37 |= F_65 ( V_57 , V_104 ) ;
}
return V_37 ;
}
