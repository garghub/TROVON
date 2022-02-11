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
T_3 F_14 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_41 V_42 ;
int V_43 ;
T_3 V_44 = V_45 ;
for ( V_43 = 0 ; V_43 < V_38 -> V_46 ; V_43 ++ ) {
struct V_47 * V_48 ;
V_48 = & V_38 -> V_38 [ V_43 ] ;
if ( V_48 -> V_48 == V_49 || V_48 -> V_48 == V_45 ) {
V_44 = V_48 -> V_48 ;
break;
} else if ( V_48 -> V_48 == V_50 ) {
V_42 . V_11 = V_48 -> V_51 . V_52 . V_11 ;
V_42 . V_13 = V_48 -> V_51 . V_52 . V_13 ;
V_40 = F_15 ( & V_42 ) ;
if ( ! V_40 )
continue;
V_44 = F_16 ( V_40 , V_48 -> V_51 . V_53 ) ;
F_17 ( V_40 ) ;
break;
}
}
return V_44 ;
}
static T_3 F_18 ( struct V_54 * V_54 , struct V_55 * V_56 )
{
struct V_23 * V_23 ;
struct V_37 * V_38 ;
T_3 V_48 ;
int V_57 ;
V_23 = F_19 ( V_58 ) ;
if ( ! V_23 )
return - V_59 ;
V_38 = F_20 ( V_23 ) ;
V_57 = F_21 ( V_54 , V_56 , V_38 ) ;
if ( V_57 < 0 ) {
V_48 = V_57 ;
goto V_60;
}
V_48 = F_14 ( V_38 ) ;
V_60:
F_22 ( V_23 ) ;
return V_48 ;
}
struct V_61 * F_23 ( struct V_61 * V_62 , struct V_54 * V_54 ,
struct V_55 * V_56 )
{
struct V_61 * V_63 ;
struct V_64 * V_65 ;
T_3 V_48 ;
V_48 = F_18 ( V_54 , V_56 ) ;
if ( ( int ) V_48 < 0 )
return F_2 ( V_48 ) ;
V_63 = F_24 ( V_62 ) ;
if ( F_6 ( V_63 ) )
return V_63 ;
V_65 = F_25 ( V_48 , V_63 ) ;
if ( ! V_65 ) {
F_26 ( V_63 ) ;
V_63 = F_2 ( - V_66 ) ;
}
return V_63 ;
}
static struct V_67 * F_27 ( struct V_68 * V_69 ,
char * V_23 , char * V_24 ,
const struct V_70 * V_71 )
{
const T_2 V_72 = sizeof( struct V_73 ) ;
struct V_67 * V_74 = F_2 ( - V_28 ) ;
char * V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
V_75 = F_1 ( & V_71 -> V_78 , V_24 , V_26 ) ;
if ( F_6 ( V_75 ) )
return F_28 ( V_75 ) ;
V_69 -> V_75 = V_75 ;
V_76 = V_75 - 1 - V_24 ;
V_69 -> V_79 = F_29 ( V_72 , V_58 ) ;
if ( V_69 -> V_79 == NULL )
return F_2 ( - V_59 ) ;
for ( V_77 = 0 ; V_77 < V_71 -> V_80 ; V_77 ++ ) {
const struct V_8 * V_81 = & V_71 -> V_82 [ V_77 ] ;
if ( V_81 -> V_11 <= 0 || V_81 -> V_11 >= V_76 )
continue;
if ( memchr ( V_81 -> V_13 , V_83 , V_81 -> V_11 ) )
continue;
V_69 -> V_84 = F_10 ( V_81 -> V_13 , V_81 -> V_11 ,
V_69 -> V_79 , V_72 ,
F_30 ( V_69 -> V_85 ) ) ;
if ( V_69 -> V_84 == 0 )
continue;
F_31 ( V_69 -> V_79 , V_86 ) ;
memcpy ( V_24 , V_81 -> V_13 , V_81 -> V_11 ) ;
V_24 [ V_81 -> V_11 ] = '\0' ;
V_69 -> V_87 = V_24 ;
snprintf ( V_23 , V_26 , L_2 ,
V_69 -> V_87 ,
V_69 -> V_75 ) ;
V_74 = F_32 ( & V_88 , 0 , V_23 , V_69 ) ;
if ( ! F_6 ( V_74 ) )
break;
}
F_33 ( V_69 -> V_79 ) ;
return V_74 ;
}
static struct V_67 * F_34 ( struct V_17 * V_17 ,
const struct V_21 * V_22 )
{
struct V_67 * V_74 = F_2 ( - V_28 ) ;
struct V_68 V_69 = {
. V_85 = V_17 -> V_89 ,
. V_17 = V_17 ,
. V_90 = F_30 ( V_17 -> V_89 ) -> V_35 -> V_91 -> V_92 ,
} ;
char * V_23 = NULL , * V_24 = NULL ;
int V_93 , error ;
if ( V_22 == NULL || V_22 -> V_94 <= 0 )
goto V_60;
F_9 ( L_3 , V_27 ,
V_17 -> V_95 -> V_96 . V_56 , V_17 -> V_96 . V_56 ) ;
V_23 = ( char * ) F_35 ( V_97 ) ;
if ( ! V_23 )
goto V_60;
V_24 = ( char * ) F_35 ( V_97 ) ;
if ( ! V_24 )
goto V_60;
error = F_7 ( V_17 , V_22 , V_23 , V_24 ) ;
if ( error < 0 ) {
V_74 = F_2 ( error ) ;
goto V_60;
}
for ( V_93 = 0 ; V_93 < V_22 -> V_94 ; V_93 ++ ) {
const struct V_70 * V_71 = & V_22 -> V_22 [ V_93 ] ;
if ( V_71 == NULL || V_71 -> V_80 <= 0 ||
V_71 -> V_78 . V_7 == 0 )
continue;
V_74 = F_27 ( & V_69 , V_23 , V_24 , V_71 ) ;
if ( ! F_6 ( V_74 ) )
break;
}
V_60:
F_36 ( ( unsigned long ) V_23 ) ;
F_36 ( ( unsigned long ) V_24 ) ;
F_9 ( L_4 , V_27 ) ;
return V_74 ;
}
static struct V_67 * F_37 ( struct V_61 * V_35 , struct V_17 * V_17 )
{
struct V_67 * V_74 = F_2 ( - V_59 ) ;
struct V_17 * V_98 ;
struct V_21 * V_99 = NULL ;
struct V_23 * V_23 ;
int V_57 ;
F_9 ( L_5 , V_27 ) ;
V_23 = F_19 ( V_58 ) ;
if ( V_23 == NULL )
goto V_60;
V_99 = F_29 ( sizeof( struct V_21 ) , V_58 ) ;
if ( V_99 == NULL )
goto V_100;
V_74 = F_2 ( - V_28 ) ;
V_98 = F_38 ( V_17 ) ;
F_9 ( L_6 ,
V_27 , V_98 -> V_96 . V_56 , V_17 -> V_96 . V_56 ) ;
V_57 = F_39 ( V_35 , V_98 -> V_101 , & V_17 -> V_96 , V_99 , V_23 ) ;
F_40 ( V_98 ) ;
if ( V_57 != 0 ||
V_99 -> V_94 <= 0 ||
V_99 -> V_25 . V_7 <= 0 )
goto V_100;
V_74 = F_34 ( V_17 , V_99 ) ;
V_100:
F_41 ( V_23 ) ;
F_33 ( V_99 ) ;
V_60:
F_9 ( L_4 , V_27 ) ;
return V_74 ;
}
struct V_67 * F_42 ( struct V_32 * V_33 , struct V_17 * V_17 ,
struct V_102 * V_103 , struct V_104 * V_105 )
{
struct V_17 * V_98 = F_38 ( V_17 ) ;
struct V_61 * V_35 ;
struct V_67 * V_74 ;
V_35 = F_43 ( V_98 -> V_101 , & V_17 -> V_96 , V_103 , V_105 ) ;
F_40 ( V_98 ) ;
if ( F_6 ( V_35 ) )
return F_28 ( V_35 ) ;
if ( V_105 -> V_106 & V_107 )
V_74 = F_37 ( V_35 , V_17 ) ;
else
V_74 = F_44 ( V_17 , V_103 , V_105 , V_35 -> V_91 -> V_92 ) ;
F_26 ( V_35 ) ;
return V_74 ;
}
