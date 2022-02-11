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
char * V_19 = F_5 ( & V_18 , V_17 , V_3 , V_4 ,
V_20 ) ;
if ( ! F_6 ( V_19 ) ) {
char * V_21 = F_3 ( V_19 , V_18 ) ;
if ( V_21 )
return V_21 ;
}
return V_19 ;
}
static int F_7 ( struct V_17 * V_17 ,
const struct V_22 * V_23 ,
char * V_24 , char * V_25 )
{
const char * V_19 , * V_26 ;
V_19 = F_4 ( V_17 , V_24 , V_27 ) ;
if ( F_6 ( V_19 ) )
return F_8 ( V_19 ) ;
V_26 = F_1 ( & V_23 -> V_26 , V_25 , V_27 ) ;
if ( F_6 ( V_26 ) )
return F_8 ( V_26 ) ;
if ( strncmp ( V_19 , V_26 , strlen ( V_26 ) ) != 0 ) {
F_9 ( L_1 ,
V_28 , V_19 , V_26 ) ;
return - V_29 ;
}
return 0 ;
}
static T_2 F_10 ( char * string , T_2 V_11 ,
struct V_30 * V_31 , T_2 V_32 , struct V_33 * V_34 )
{
struct V_35 * V_35 = F_11 ( V_34 -> V_36 ) ;
T_1 V_37 ;
V_37 = F_12 ( V_35 , string , V_11 , V_31 , V_32 ) ;
if ( V_37 == 0 ) {
V_37 = F_13 ( V_35 , string , V_11 , V_31 , V_32 ) ;
if ( V_37 < 0 )
V_37 = 0 ;
}
return V_37 ;
}
T_3 F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 V_43 ;
int V_44 ;
T_3 V_45 = V_46 ;
for ( V_44 = 0 ; V_44 < V_39 -> V_47 ; V_44 ++ ) {
struct V_48 * V_49 ;
V_49 = & V_39 -> V_39 [ V_44 ] ;
if ( V_49 -> V_49 == V_50 || V_49 -> V_49 == V_46 ) {
V_45 = V_49 -> V_49 ;
break;
} else if ( V_49 -> V_49 == V_51 ) {
V_43 . V_11 = V_49 -> V_52 . V_53 . V_11 ;
V_43 . V_13 = V_49 -> V_52 . V_53 . V_13 ;
V_41 = F_15 ( & V_43 ) ;
if ( ! V_41 )
continue;
V_45 = F_16 ( V_41 , V_49 -> V_52 . V_54 ) ;
F_17 ( V_41 ) ;
break;
}
}
return V_45 ;
}
static T_3 F_18 ( struct V_55 * V_55 , struct V_56 * V_57 )
{
struct V_24 * V_24 ;
struct V_38 * V_39 ;
T_3 V_49 ;
int V_58 ;
V_24 = F_19 ( V_59 ) ;
if ( ! V_24 )
return - V_60 ;
V_39 = F_20 ( V_24 ) ;
V_58 = F_21 ( V_55 , V_57 , V_39 ) ;
if ( V_58 < 0 ) {
V_49 = V_58 ;
goto V_61;
}
V_49 = F_14 ( V_39 ) ;
V_61:
F_22 ( V_24 ) ;
return V_49 ;
}
struct V_62 * F_23 ( struct V_62 * V_63 , struct V_55 * V_55 ,
struct V_56 * V_57 )
{
T_3 V_49 ;
V_49 = F_18 ( V_55 , V_57 ) ;
if ( ( int ) V_49 < 0 )
return F_2 ( ( int ) V_49 ) ;
return F_24 ( V_63 , V_49 ) ;
}
static struct V_64 * F_25 ( struct V_65 * V_66 ,
char * V_24 , char * V_25 ,
const struct V_67 * V_68 )
{
const T_2 V_69 = sizeof( struct V_70 ) ;
struct V_64 * V_71 = F_2 ( - V_29 ) ;
char * V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
V_72 = F_1 ( & V_68 -> V_75 , V_25 , V_27 ) ;
if ( F_6 ( V_72 ) )
return F_26 ( V_72 ) ;
V_66 -> V_72 = V_72 ;
V_73 = V_72 - 1 - V_25 ;
V_66 -> V_76 = F_27 ( V_69 , V_59 ) ;
if ( V_66 -> V_76 == NULL )
return F_2 ( - V_60 ) ;
for ( V_74 = 0 ; V_74 < V_68 -> V_77 ; V_74 ++ ) {
const struct V_8 * V_78 = & V_68 -> V_79 [ V_74 ] ;
if ( V_78 -> V_11 <= 0 || V_78 -> V_11 >= V_73 )
continue;
if ( memchr ( V_78 -> V_13 , V_80 , V_78 -> V_11 ) )
continue;
V_66 -> V_81 = F_10 ( V_78 -> V_13 , V_78 -> V_11 ,
V_66 -> V_76 , V_69 ,
F_28 ( V_66 -> V_82 ) ) ;
if ( V_66 -> V_81 == 0 )
continue;
F_29 ( V_66 -> V_76 , V_83 ) ;
memcpy ( V_25 , V_78 -> V_13 , V_78 -> V_11 ) ;
V_25 [ V_78 -> V_11 ] = '\0' ;
V_66 -> V_84 = V_25 ;
snprintf ( V_24 , V_27 , L_2 ,
V_66 -> V_84 ,
V_66 -> V_72 ) ;
V_71 = F_30 ( & V_85 , 0 , V_24 , V_66 ) ;
if ( ! F_6 ( V_71 ) )
break;
}
F_31 ( V_66 -> V_76 ) ;
return V_71 ;
}
static struct V_64 * F_32 ( struct V_17 * V_17 ,
const struct V_22 * V_23 )
{
struct V_64 * V_71 = F_2 ( - V_29 ) ;
struct V_65 V_66 = {
. V_82 = V_17 -> V_86 ,
. V_17 = V_17 ,
. V_87 = F_28 ( V_17 -> V_86 ) -> V_36 -> V_88 -> V_89 ,
} ;
char * V_24 = NULL , * V_25 = NULL ;
int V_90 , error ;
if ( V_23 == NULL || V_23 -> V_91 <= 0 )
goto V_61;
F_9 ( L_3 , V_28 ,
V_17 -> V_92 -> V_93 . V_57 , V_17 -> V_93 . V_57 ) ;
V_24 = ( char * ) F_33 ( V_94 ) ;
if ( ! V_24 )
goto V_61;
V_25 = ( char * ) F_33 ( V_94 ) ;
if ( ! V_25 )
goto V_61;
error = F_7 ( V_17 , V_23 , V_24 , V_25 ) ;
if ( error < 0 ) {
V_71 = F_2 ( error ) ;
goto V_61;
}
for ( V_90 = 0 ; V_90 < V_23 -> V_91 ; V_90 ++ ) {
const struct V_67 * V_68 = & V_23 -> V_23 [ V_90 ] ;
if ( V_68 == NULL || V_68 -> V_77 <= 0 ||
V_68 -> V_75 . V_7 == 0 )
continue;
V_71 = F_25 ( & V_66 , V_24 , V_25 , V_68 ) ;
if ( ! F_6 ( V_71 ) )
break;
}
V_61:
F_34 ( ( unsigned long ) V_24 ) ;
F_34 ( ( unsigned long ) V_25 ) ;
F_9 ( L_4 , V_28 ) ;
return V_71 ;
}
static struct V_64 * F_35 ( struct V_62 * V_36 , struct V_17 * V_17 )
{
struct V_64 * V_71 = F_2 ( - V_60 ) ;
struct V_17 * V_95 ;
struct V_22 * V_96 = NULL ;
struct V_24 * V_24 ;
int V_58 ;
F_9 ( L_5 , V_28 ) ;
V_24 = F_19 ( V_59 ) ;
if ( V_24 == NULL )
goto V_61;
V_96 = F_27 ( sizeof( struct V_22 ) , V_59 ) ;
if ( V_96 == NULL )
goto V_97;
V_71 = F_2 ( - V_29 ) ;
V_95 = F_36 ( V_17 ) ;
F_9 ( L_6 ,
V_28 , V_95 -> V_93 . V_57 , V_17 -> V_93 . V_57 ) ;
V_58 = F_37 ( V_36 , V_95 -> V_98 , & V_17 -> V_93 , V_96 , V_24 ) ;
F_38 ( V_95 ) ;
if ( V_58 != 0 ||
V_96 -> V_91 <= 0 ||
V_96 -> V_26 . V_7 <= 0 )
goto V_97;
V_71 = F_32 ( V_17 , V_96 ) ;
V_97:
F_39 ( V_24 ) ;
F_31 ( V_96 ) ;
V_61:
F_9 ( L_4 , V_28 ) ;
return V_71 ;
}
struct V_64 * F_40 ( struct V_33 * V_34 , struct V_17 * V_17 ,
struct V_99 * V_100 , struct V_101 * V_102 )
{
struct V_17 * V_95 = F_36 ( V_17 ) ;
struct V_62 * V_36 ;
struct V_64 * V_71 ;
V_36 = F_41 ( V_95 -> V_98 , & V_17 -> V_93 , V_100 , V_102 ) ;
F_38 ( V_95 ) ;
if ( F_6 ( V_36 ) )
return F_26 ( V_36 ) ;
if ( V_102 -> V_103 & V_104 )
V_71 = F_35 ( V_36 , V_17 ) ;
else
V_71 = F_42 ( V_17 , V_100 , V_102 , V_36 -> V_88 -> V_89 ) ;
F_43 ( V_36 ) ;
return V_71 ;
}
