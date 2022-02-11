static inline char * F_1 ( const struct V_1 * V_2 ,
char * V_3 , T_1 V_4 )
{
char * V_5 = V_3 + V_4 ;
int V_6 ;
* -- V_5 = '\0' ;
V_4 -- ;
V_6 = V_2 -> V_7 ;
while ( -- V_6 >= 0 ) {
const struct V_8 * V_9 = & V_2 -> V_10 [ V_6 ] ;
V_4 -= V_9 -> V_11 + 1 ;
if ( V_4 < 0 )
goto V_12;
V_5 -= V_9 -> V_11 ;
memcpy ( V_5 , V_9 -> V_13 , V_9 -> V_11 ) ;
* -- V_5 = '/' ;
}
return V_5 ;
V_12:
return F_2 ( - V_14 ) ;
}
static char * F_3 ( const char * V_15 , const char * V_5 )
{
char * V_16 ;
if ( * V_15 == '[' ) {
V_16 = strchr ( V_15 , ']' ) ;
if ( V_16 != NULL && ++ V_16 < V_5 && * V_16 == ':' )
return V_16 + 1 ;
} else {
V_16 = strchr ( V_15 , ':' ) ;
if ( V_16 != NULL && V_16 < V_5 )
return V_16 + 1 ;
}
return NULL ;
}
static char * F_4 ( struct V_17 * V_17 , char * V_3 , T_1 V_4 )
{
char * V_18 ;
char * V_19 = F_5 ( & V_18 , V_17 , V_3 , V_4 ) ;
if ( ! F_6 ( V_19 ) ) {
char * V_20 = F_3 ( V_19 , V_18 ) ;
if ( V_20 )
return V_20 ;
}
return V_19 ;
}
static int F_7 ( struct V_17 * V_17 ,
const struct V_21 * V_22 ,
char * V_23 , char * V_24 )
{
const char * V_19 , * V_25 ;
V_19 = F_4 ( V_17 , V_23 , V_26 ) ;
if ( F_6 ( V_19 ) )
return F_8 ( V_19 ) ;
V_25 = F_1 ( & V_22 -> V_25 , V_24 , V_26 ) ;
if ( F_6 ( V_25 ) )
return F_8 ( V_25 ) ;
if ( strncmp ( V_19 , V_25 , strlen ( V_25 ) ) != 0 ) {
F_9 ( L_1 ,
V_27 , V_19 , V_25 ) ;
return - V_28 ;
}
return 0 ;
}
static T_2 F_10 ( char * string , T_2 V_11 ,
struct V_29 * V_30 , T_2 V_31 , struct V_32 * V_33 )
{
struct V_34 * V_34 = F_11 ( V_33 -> V_35 ) ;
T_1 V_36 ;
V_36 = F_12 ( V_34 , string , V_11 , V_30 , V_31 ) ;
if ( V_36 == 0 ) {
V_36 = F_13 ( V_34 , string , V_11 , V_30 , V_31 ) ;
if ( V_36 < 0 )
V_36 = 0 ;
}
return V_36 ;
}
static T_3 F_14 ( struct V_37 * V_37 , struct V_38 * V_39 )
{
struct V_23 * V_23 ;
struct V_40 * V_41 ;
T_3 V_42 ;
int V_43 ;
V_23 = F_15 ( V_44 ) ;
if ( ! V_23 )
return - V_45 ;
V_41 = F_16 ( V_23 ) ;
V_43 = F_17 ( V_37 , V_39 , V_41 ) ;
if ( V_43 < 0 ) {
V_42 = V_43 ;
goto V_46;
}
V_42 = F_18 ( V_41 ) ;
V_46:
F_19 ( V_23 ) ;
return V_42 ;
}
struct V_47 * F_20 ( struct V_47 * V_48 , struct V_37 * V_37 ,
struct V_38 * V_39 )
{
struct V_47 * V_49 ;
struct V_50 * V_51 ;
T_3 V_42 ;
V_42 = F_14 ( V_37 , V_39 ) ;
if ( V_42 < 0 )
return F_2 ( V_42 ) ;
V_49 = F_21 ( V_48 ) ;
if ( F_6 ( V_49 ) )
return V_49 ;
V_51 = F_22 ( V_42 , V_49 ) ;
if ( ! V_51 ) {
F_23 ( V_49 ) ;
V_49 = F_2 ( - V_52 ) ;
}
return V_49 ;
}
static struct V_53 * F_24 ( struct V_54 * V_55 ,
char * V_23 , char * V_24 ,
const struct V_56 * V_57 )
{
const T_2 V_58 = sizeof( struct V_59 ) ;
struct V_53 * V_60 = F_2 ( - V_28 ) ;
char * V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
V_61 = F_1 ( & V_57 -> V_64 , V_24 , V_26 ) ;
if ( F_6 ( V_61 ) )
return F_25 ( V_61 ) ;
V_55 -> V_61 = V_61 ;
V_62 = V_61 - 1 - V_24 ;
V_55 -> V_65 = F_26 ( V_58 , V_44 ) ;
if ( V_55 -> V_65 == NULL )
return F_2 ( - V_45 ) ;
for ( V_63 = 0 ; V_63 < V_57 -> V_66 ; V_63 ++ ) {
const struct V_8 * V_67 = & V_57 -> V_68 [ V_63 ] ;
if ( V_67 -> V_11 <= 0 || V_67 -> V_11 >= V_62 )
continue;
if ( memchr ( V_67 -> V_13 , V_69 , V_67 -> V_11 ) )
continue;
V_55 -> V_70 = F_10 ( V_67 -> V_13 , V_67 -> V_11 ,
V_55 -> V_65 , V_58 ,
F_27 ( V_55 -> V_71 ) ) ;
if ( V_55 -> V_70 == 0 )
continue;
F_28 ( V_55 -> V_65 , V_72 ) ;
memcpy ( V_24 , V_67 -> V_13 , V_67 -> V_11 ) ;
V_24 [ V_67 -> V_11 ] = '\0' ;
V_55 -> V_73 = V_24 ;
snprintf ( V_23 , V_26 , L_2 ,
V_55 -> V_73 ,
V_55 -> V_61 ) ;
V_60 = F_29 ( & V_74 , 0 , V_23 , V_55 ) ;
if ( ! F_6 ( V_60 ) )
break;
}
F_30 ( V_55 -> V_65 ) ;
return V_60 ;
}
static struct V_53 * F_31 ( struct V_17 * V_17 ,
const struct V_21 * V_22 )
{
struct V_53 * V_60 = F_2 ( - V_28 ) ;
struct V_54 V_55 = {
. V_71 = V_17 -> V_75 ,
. V_17 = V_17 ,
. V_76 = F_27 ( V_17 -> V_75 ) -> V_35 -> V_77 -> V_78 ,
} ;
char * V_23 = NULL , * V_24 = NULL ;
int V_79 , error ;
if ( V_22 == NULL || V_22 -> V_80 <= 0 )
goto V_46;
F_9 ( L_3 , V_27 ,
V_17 -> V_81 -> V_82 . V_39 , V_17 -> V_82 . V_39 ) ;
V_23 = ( char * ) F_32 ( V_83 ) ;
if ( ! V_23 )
goto V_46;
V_24 = ( char * ) F_32 ( V_83 ) ;
if ( ! V_24 )
goto V_46;
error = F_7 ( V_17 , V_22 , V_23 , V_24 ) ;
if ( error < 0 ) {
V_60 = F_2 ( error ) ;
goto V_46;
}
for ( V_79 = 0 ; V_79 < V_22 -> V_80 ; V_79 ++ ) {
const struct V_56 * V_57 = & V_22 -> V_22 [ V_79 ] ;
if ( V_57 == NULL || V_57 -> V_66 <= 0 ||
V_57 -> V_64 . V_7 == 0 )
continue;
V_60 = F_24 ( & V_55 , V_23 , V_24 , V_57 ) ;
if ( ! F_6 ( V_60 ) )
break;
}
V_46:
F_33 ( ( unsigned long ) V_23 ) ;
F_33 ( ( unsigned long ) V_24 ) ;
F_9 ( L_4 , V_27 ) ;
return V_60 ;
}
struct V_53 * F_34 ( struct V_47 * V_35 , struct V_17 * V_17 )
{
struct V_53 * V_60 = F_2 ( - V_45 ) ;
struct V_17 * V_84 ;
struct V_21 * V_85 = NULL ;
struct V_23 * V_23 ;
int V_43 ;
F_9 ( L_5 , V_27 ) ;
V_23 = F_15 ( V_44 ) ;
if ( V_23 == NULL )
goto V_46;
V_85 = F_26 ( sizeof( struct V_21 ) , V_44 ) ;
if ( V_85 == NULL )
goto V_86;
V_60 = F_2 ( - V_28 ) ;
V_84 = F_35 ( V_17 ) ;
F_9 ( L_6 ,
V_27 , V_84 -> V_82 . V_39 , V_17 -> V_82 . V_39 ) ;
V_43 = F_36 ( V_35 , V_84 -> V_87 , & V_17 -> V_82 , V_85 , V_23 ) ;
F_37 ( V_84 ) ;
if ( V_43 != 0 ||
V_85 -> V_80 <= 0 ||
V_85 -> V_25 . V_7 <= 0 )
goto V_86;
V_60 = F_31 ( V_17 , V_85 ) ;
V_86:
F_38 ( V_23 ) ;
F_30 ( V_85 ) ;
V_46:
F_9 ( L_4 , V_27 ) ;
return V_60 ;
}
