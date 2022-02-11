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
return V_30 - V_26 ;
}
static int F_10 ( char * * V_32 , T_4 V_33 , const char * V_34 , ... )
{
T_5 V_35 ;
int V_36 ;
if ( ! V_32 )
return - V_37 ;
va_start ( V_35 , V_34 ) ;
if ( * V_32 )
V_36 = vsnprintf ( * V_32 , V_33 , V_34 , V_35 ) ;
else
V_36 = F_11 ( V_32 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
return V_36 ;
}
static char * F_12 ( const char * V_38 , char * V_28 , T_4 V_33 )
{
char * V_39 = V_28 ;
int V_36 = F_10 ( & V_28 , V_33 , L_4 , V_40 ,
V_38 , V_38 + 2 ) ;
if ( V_36 < 0 || ( V_39 && V_33 < ( unsigned int ) V_36 ) )
return NULL ;
return V_28 ;
}
char * F_13 ( const struct V_21 * V_21 , char * V_28 , T_4 V_33 )
{
char V_41 [ V_42 * 2 + 1 ] ;
if ( ! V_21 -> V_43 )
return NULL ;
F_9 ( V_21 -> V_26 , sizeof( V_21 -> V_26 ) , V_41 ) ;
return F_12 ( V_41 , V_28 , V_33 ) ;
}
static int F_14 ( const char * V_44 , T_4 V_45 , T_3 * V_26 ,
T_6 V_16 , T_7 V_13 , int V_46 )
{
int V_47 ;
struct V_48 V_49 ;
T_4 V_27 ;
V_27 = V_45 + 1 ;
V_27 = F_15 ( V_27 , V_50 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
memcpy ( & V_49 . V_26 , V_26 , V_42 ) ;
V_49 . V_16 = V_16 ;
V_49 . V_12 . V_13 = V_13 ;
V_49 . V_12 . V_33 = sizeof( V_49 ) + V_27 ;
V_47 = F_16 ( V_46 , & V_49 , sizeof( V_49 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return F_17 ( V_46 , V_44 , V_45 + 1 , V_27 ) ;
}
static int F_18 ( struct V_8 * V_8 , int V_46 )
{
int V_47 = 0 ;
char V_51 [ V_52 ] ;
struct V_21 * V_53 ;
T_7 V_54 = V_55 ,
V_56 = V_57 ;
if ( ! F_19 ( V_8 ) ) {
V_54 = V_58 ;
V_56 = V_59 ;
}
F_20 (pos, &machine->dsos.head) {
const char * V_44 ;
T_4 V_45 ;
if ( ! V_53 -> V_22 )
continue;
if ( F_21 ( V_53 ) ) {
V_44 = V_53 -> V_60 ;
V_45 = V_53 -> V_61 + 1 ;
} else if ( F_22 ( V_53 ) ) {
F_23 ( V_8 , V_51 , sizeof( V_51 ) ) ;
V_44 = V_51 ;
V_45 = strlen ( V_51 ) + 1 ;
} else {
V_44 = V_53 -> V_62 ;
V_45 = V_53 -> V_63 + 1 ;
}
V_47 = F_14 ( V_44 , V_45 , V_53 -> V_26 , V_8 -> V_16 ,
V_53 -> V_64 ? V_54 : V_56 , V_46 ) ;
if ( V_47 )
break;
}
return V_47 ;
}
int F_24 ( struct V_65 * V_66 , int V_46 )
{
struct V_67 * V_68 ;
int V_47 = F_18 ( & V_66 -> V_69 . V_70 , V_46 ) ;
if ( V_47 )
return V_47 ;
for ( V_68 = F_25 ( & V_66 -> V_69 . V_71 ) ; V_68 ; V_68 = F_26 ( V_68 ) ) {
struct V_8 * V_53 = F_27 ( V_68 , struct V_8 , V_67 ) ;
V_47 = F_18 ( V_53 , V_46 ) ;
if ( V_47 )
break;
}
return V_47 ;
}
static int F_28 ( struct V_72 * V_73 )
{
struct V_21 * V_53 ;
F_29 (pos, head, node)
V_53 -> V_22 = true ;
return 0 ;
}
static int F_30 ( struct V_8 * V_8 )
{
return F_28 ( & V_8 -> V_74 . V_73 ) ;
}
int F_31 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
int V_47 ;
V_47 = F_30 ( & V_66 -> V_69 . V_70 ) ;
if ( V_47 )
return V_47 ;
for ( V_68 = F_25 ( & V_66 -> V_69 . V_71 ) ; V_68 ; V_68 = F_26 ( V_68 ) ) {
struct V_8 * V_53 = F_27 ( V_68 , struct V_8 , V_67 ) ;
V_47 = F_30 ( V_53 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
void F_32 ( void )
{
V_75 = true ;
}
static char * F_33 ( const char * V_44 ,
bool V_76 , bool V_77 )
{
char * V_78 = ( char * ) V_44 , * V_79 ;
bool V_80 = V_76 || V_77 ;
if ( ! V_80 ) {
V_78 = F_34 ( V_44 , NULL ) ;
if ( ! V_78 )
return NULL ;
}
if ( F_35 ( & V_79 , L_5 , V_40 , V_80 ? L_6 : L_7 ,
V_77 ? V_81 : V_78 ) < 0 )
V_79 = NULL ;
if ( ! V_80 )
free ( V_78 ) ;
return V_79 ;
}
int F_36 ( const char * V_82 ,
struct V_83 * * V_84 )
{
struct V_83 * V_85 ;
char * V_86 ;
T_8 * V_87 ;
struct V_88 * V_89 ;
int V_36 = 0 ;
V_85 = F_37 ( true , NULL ) ;
V_86 = F_33 ( V_82 , false , false ) ;
if ( ! V_85 || ! V_86 ) {
V_36 = - V_90 ;
goto V_91;
}
V_87 = F_38 ( V_86 ) ;
if ( ! V_87 ) {
V_36 = - V_92 ;
goto V_91;
}
while ( ( V_89 = F_39 ( V_87 ) ) != NULL ) {
if ( ! strcmp ( V_89 -> V_93 , L_8 ) || ! strcmp ( V_89 -> V_93 , L_9 ) )
continue;
F_40 ( V_85 , V_89 -> V_93 ) ;
}
F_41 ( V_87 ) ;
V_91:
free ( V_86 ) ;
if ( V_36 )
F_42 ( V_85 ) ;
else
* V_84 = V_85 ;
return V_36 ;
}
int F_43 ( const char * V_38 , const char * V_44 ,
bool V_76 , bool V_77 )
{
const T_4 V_33 = V_52 ;
char * V_78 = NULL , * V_79 = NULL , * V_86 = NULL ,
* V_94 = F_44 ( V_33 ) , * V_95 , * V_39 ;
int V_47 = - 1 ;
if ( ! V_76 ) {
V_78 = F_34 ( V_44 , NULL ) ;
if ( ! V_78 )
goto V_96;
}
V_86 = F_33 ( V_44 , V_76 , V_77 ) ;
if ( ! V_86 )
goto V_96;
if ( F_45 ( V_86 , 0755 ) )
goto V_96;
if ( F_35 ( & V_79 , L_10 , V_86 , V_38 ) < 0 ) {
V_79 = NULL ;
goto V_96;
}
if ( F_46 ( V_79 , V_97 ) ) {
if ( V_76 ) {
if ( F_47 ( L_11 , V_79 ) )
goto V_96;
} else if ( F_48 ( V_78 , V_79 ) && V_92 != V_98 &&
F_47 ( V_44 , V_79 ) )
goto V_96;
}
if ( ! F_12 ( V_38 , V_94 , V_33 ) )
goto V_96;
V_39 = strrchr ( V_94 , '/' ) ;
* V_39 = '\0' ;
if ( F_46 ( V_94 , V_99 ) && F_45 ( V_94 , 0755 ) )
goto V_96;
* V_39 = '/' ;
V_95 = V_79 + strlen ( V_40 ) - 5 ;
memcpy ( V_95 , L_12 , 5 ) ;
if ( F_49 ( V_95 , V_94 ) == 0 )
V_47 = 0 ;
V_96:
if ( ! V_76 )
free ( V_78 ) ;
free ( V_79 ) ;
free ( V_86 ) ;
free ( V_94 ) ;
return V_47 ;
}
static int F_50 ( const T_3 * V_26 , T_4 V_100 ,
const char * V_44 , bool V_76 ,
bool V_77 )
{
char V_38 [ V_42 * 2 + 1 ] ;
F_9 ( V_26 , V_100 , V_38 ) ;
return F_43 ( V_38 , V_44 , V_76 , V_77 ) ;
}
bool F_51 ( const char * V_38 )
{
bool V_36 = false ;
char * V_79 = F_12 ( V_38 , NULL , 0 ) ;
if ( V_79 && ! F_46 ( V_79 , V_97 ) )
V_36 = true ;
free ( V_79 ) ;
return V_36 ;
}
int F_52 ( const char * V_38 )
{
const T_4 V_33 = V_52 ;
char * V_79 = F_44 ( V_33 ) ,
* V_94 = F_44 ( V_33 ) , * V_39 ;
int V_47 = - 1 ;
if ( V_79 == NULL || V_94 == NULL )
goto V_96;
if ( ! F_12 ( V_38 , V_94 , V_33 ) )
goto V_96;
if ( F_46 ( V_94 , V_97 ) )
goto V_96;
if ( F_53 ( V_94 , V_79 , V_33 - 1 ) < 0 )
goto V_96;
if ( F_54 ( V_94 ) )
goto V_96;
V_39 = strrchr ( V_94 , '/' ) + 1 ;
snprintf ( V_39 , V_33 - ( V_39 - V_94 ) , L_13 , V_79 ) ;
if ( F_54 ( V_94 ) )
goto V_96;
V_47 = 0 ;
V_96:
free ( V_79 ) ;
free ( V_94 ) ;
return V_47 ;
}
static int F_55 ( struct V_21 * V_21 , struct V_8 * V_8 )
{
bool V_76 = V_21 -> V_64 && V_21 -> V_62 [ 0 ] != '/' ;
bool V_77 = F_21 ( V_21 ) ;
const char * V_44 = V_21 -> V_62 ;
char V_51 [ V_52 ] ;
if ( F_22 ( V_21 ) ) {
V_76 = true ;
F_23 ( V_8 , V_51 , sizeof( V_51 ) ) ;
V_44 = V_51 ;
}
return F_50 ( V_21 -> V_26 , sizeof( V_21 -> V_26 ) , V_44 ,
V_76 , V_77 ) ;
}
static int F_56 ( struct V_72 * V_73 ,
struct V_8 * V_8 )
{
struct V_21 * V_53 ;
int V_47 = 0 ;
F_20 (pos, head)
if ( F_55 ( V_53 , V_8 ) )
V_47 = - 1 ;
return V_47 ;
}
static int F_57 ( struct V_8 * V_8 )
{
return F_56 ( & V_8 -> V_74 . V_73 , V_8 ) ;
}
int F_58 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
int V_36 ;
if ( V_75 )
return 0 ;
if ( F_59 ( V_40 , 0755 ) != 0 && V_92 != V_98 )
return - 1 ;
V_36 = F_57 ( & V_66 -> V_69 . V_70 ) ;
for ( V_68 = F_25 ( & V_66 -> V_69 . V_71 ) ; V_68 ; V_68 = F_26 ( V_68 ) ) {
struct V_8 * V_53 = F_27 ( V_68 , struct V_8 , V_67 ) ;
V_36 |= F_57 ( V_53 ) ;
}
return V_36 ? - 1 : 0 ;
}
static bool F_60 ( struct V_8 * V_8 , bool V_101 )
{
return F_61 ( & V_8 -> V_74 . V_73 , V_101 ) ;
}
bool F_62 ( struct V_65 * V_66 , bool V_101 )
{
struct V_67 * V_68 ;
bool V_36 = F_60 ( & V_66 -> V_69 . V_70 , V_101 ) ;
for ( V_68 = F_25 ( & V_66 -> V_69 . V_71 ) ; V_68 ; V_68 = F_26 ( V_68 ) ) {
struct V_8 * V_53 = F_27 ( V_68 , struct V_8 , V_67 ) ;
V_36 |= F_60 ( V_53 , V_101 ) ;
}
return V_36 ;
}
