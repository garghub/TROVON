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
T_3 V_40 ;
struct V_41 * V_42 ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_39 -> V_44 ; V_43 ++ ) {
V_42 = & V_39 -> V_39 [ V_43 ] ;
switch ( V_42 -> V_45 ) {
case V_46 :
case V_47 :
case V_48 :
V_40 = F_15 ( V_42 -> V_45 ,
& V_42 -> V_49 ) ;
if ( V_40 != V_50 )
return V_40 ;
break;
}
}
return V_47 ;
}
static T_3 F_16 ( struct V_51 * V_51 , struct V_52 * V_53 )
{
struct V_24 * V_24 ;
struct V_38 * V_39 ;
T_3 V_45 ;
int V_54 ;
V_24 = F_17 ( V_55 ) ;
if ( ! V_24 )
return - V_56 ;
V_39 = F_18 ( V_24 ) ;
V_54 = F_19 ( V_51 , V_53 , V_39 ) ;
if ( V_54 < 0 ) {
V_45 = V_54 ;
goto V_57;
}
V_45 = F_14 ( V_39 ) ;
V_57:
F_20 ( V_24 ) ;
return V_45 ;
}
struct V_58 * F_21 ( struct V_58 * V_59 , struct V_51 * V_51 ,
struct V_52 * V_53 )
{
T_3 V_45 ;
V_45 = F_16 ( V_51 , V_53 ) ;
if ( ( int ) V_45 < 0 )
return F_2 ( ( int ) V_45 ) ;
return F_22 ( V_59 , V_45 ) ;
}
static struct V_60 * F_23 ( struct V_61 * V_62 ,
char * V_24 , char * V_25 ,
const struct V_63 * V_64 )
{
const T_2 V_65 = sizeof( struct V_66 ) ;
struct V_60 * V_67 = F_2 ( - V_29 ) ;
char * V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
V_68 = F_1 ( & V_64 -> V_71 , V_25 , V_27 ) ;
if ( F_6 ( V_68 ) )
return F_24 ( V_68 ) ;
V_62 -> V_68 = V_68 ;
V_69 = V_68 - 1 - V_25 ;
V_62 -> V_72 = F_25 ( V_65 , V_55 ) ;
if ( V_62 -> V_72 == NULL )
return F_2 ( - V_56 ) ;
for ( V_70 = 0 ; V_70 < V_64 -> V_73 ; V_70 ++ ) {
const struct V_8 * V_74 = & V_64 -> V_75 [ V_70 ] ;
if ( V_74 -> V_11 <= 0 || V_74 -> V_11 >= V_69 )
continue;
if ( memchr ( V_74 -> V_13 , V_76 , V_74 -> V_11 ) )
continue;
V_62 -> V_77 = F_10 ( V_74 -> V_13 , V_74 -> V_11 ,
V_62 -> V_72 , V_65 ,
F_26 ( V_62 -> V_78 ) ) ;
if ( V_62 -> V_77 == 0 )
continue;
F_27 ( V_62 -> V_72 , V_79 ) ;
memcpy ( V_25 , V_74 -> V_13 , V_74 -> V_11 ) ;
V_25 [ V_74 -> V_11 ] = '\0' ;
V_62 -> V_80 = V_25 ;
snprintf ( V_24 , V_27 , L_2 ,
V_62 -> V_80 ,
V_62 -> V_68 ) ;
V_67 = F_28 ( & V_81 , 0 , V_24 , V_62 ) ;
if ( ! F_6 ( V_67 ) )
break;
}
F_29 ( V_62 -> V_72 ) ;
return V_67 ;
}
static struct V_60 * F_30 ( struct V_17 * V_17 ,
const struct V_22 * V_23 )
{
struct V_60 * V_67 = F_2 ( - V_29 ) ;
struct V_61 V_62 = {
. V_78 = V_17 -> V_82 ,
. V_17 = V_17 ,
. V_83 = F_26 ( V_17 -> V_82 ) -> V_36 -> V_84 -> V_85 ,
} ;
char * V_24 = NULL , * V_25 = NULL ;
int V_86 , error ;
if ( V_23 == NULL || V_23 -> V_87 <= 0 )
goto V_57;
F_9 ( L_3 , V_28 ,
V_17 -> V_88 -> V_89 . V_53 , V_17 -> V_89 . V_53 ) ;
V_24 = ( char * ) F_31 ( V_90 ) ;
if ( ! V_24 )
goto V_57;
V_25 = ( char * ) F_31 ( V_90 ) ;
if ( ! V_25 )
goto V_57;
error = F_7 ( V_17 , V_23 , V_24 , V_25 ) ;
if ( error < 0 ) {
V_67 = F_2 ( error ) ;
goto V_57;
}
for ( V_86 = 0 ; V_86 < V_23 -> V_87 ; V_86 ++ ) {
const struct V_63 * V_64 = & V_23 -> V_23 [ V_86 ] ;
if ( V_64 == NULL || V_64 -> V_73 <= 0 ||
V_64 -> V_71 . V_7 == 0 )
continue;
V_67 = F_23 ( & V_62 , V_24 , V_25 , V_64 ) ;
if ( ! F_6 ( V_67 ) )
break;
}
V_57:
F_32 ( ( unsigned long ) V_24 ) ;
F_32 ( ( unsigned long ) V_25 ) ;
F_9 ( L_4 , V_28 ) ;
return V_67 ;
}
static struct V_60 * F_33 ( struct V_58 * V_36 , struct V_17 * V_17 )
{
struct V_60 * V_67 = F_2 ( - V_56 ) ;
struct V_17 * V_91 ;
struct V_22 * V_92 = NULL ;
struct V_24 * V_24 ;
int V_54 ;
F_9 ( L_5 , V_28 ) ;
V_24 = F_17 ( V_55 ) ;
if ( V_24 == NULL )
goto V_57;
V_92 = F_25 ( sizeof( struct V_22 ) , V_55 ) ;
if ( V_92 == NULL )
goto V_93;
V_67 = F_2 ( - V_29 ) ;
V_91 = F_34 ( V_17 ) ;
F_9 ( L_6 ,
V_28 , V_91 -> V_89 . V_53 , V_17 -> V_89 . V_53 ) ;
V_54 = F_35 ( V_36 , V_91 -> V_94 , & V_17 -> V_89 , V_92 , V_24 ) ;
F_36 ( V_91 ) ;
if ( V_54 != 0 ||
V_92 -> V_87 <= 0 ||
V_92 -> V_26 . V_7 <= 0 )
goto V_93;
V_67 = F_30 ( V_17 , V_92 ) ;
V_93:
F_37 ( V_24 ) ;
F_29 ( V_92 ) ;
V_57:
F_9 ( L_4 , V_28 ) ;
return V_67 ;
}
struct V_60 * F_38 ( struct V_33 * V_34 , struct V_17 * V_17 ,
struct V_95 * V_96 , struct V_97 * V_98 )
{
T_3 V_45 = V_34 -> V_36 -> V_84 -> V_85 ;
struct V_17 * V_91 = F_34 ( V_17 ) ;
struct V_51 * V_99 = V_91 -> V_94 ;
struct V_52 * V_53 = & V_17 -> V_89 ;
struct V_58 * V_36 ;
struct V_60 * V_67 ;
V_36 = F_39 ( V_99 , V_53 , V_96 , V_98 ) ;
F_36 ( V_91 ) ;
if ( F_6 ( V_36 ) )
return F_24 ( V_36 ) ;
if ( V_98 -> V_100 & V_101 ) {
V_67 = F_33 ( V_36 , V_17 ) ;
goto V_57;
}
if ( V_36 -> V_84 -> V_85 != V_45 )
V_45 = V_36 -> V_84 -> V_85 ;
else if ( ! ( V_34 -> V_102 & V_103 ) ) {
T_3 V_104 = F_16 ( V_99 , V_53 ) ;
if ( ( int ) V_104 >= 0 )
V_45 = V_104 ;
}
V_67 = F_40 ( V_17 , V_96 , V_98 , V_45 ) ;
V_57:
F_41 ( V_36 ) ;
return V_67 ;
}
