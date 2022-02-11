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
struct V_30 * V_31 , T_2 V_32 , struct V_33 * V_33 )
{
T_1 V_34 ;
V_34 = F_11 ( V_33 , string , V_11 , V_31 , V_32 ) ;
if ( V_34 == 0 ) {
V_34 = F_12 ( V_33 , string , V_11 , V_31 , V_32 ) ;
if ( V_34 < 0 )
V_34 = 0 ;
}
return V_34 ;
}
static T_3 F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
T_3 V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_41 = & V_38 -> V_38 [ V_42 ] ;
switch ( V_41 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
V_39 = F_14 ( V_41 -> V_44 ,
& V_41 -> V_48 ) ;
if ( V_39 != V_49 &&
F_15 ( & V_36 -> V_50 ,
V_39 ) )
return V_39 ;
break;
}
}
if ( V_36 -> V_50 . V_51 > 0 )
return - V_52 ;
return V_46 ;
}
static T_3 F_16 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
struct V_24 * V_24 ;
struct V_37 * V_38 ;
T_3 V_44 ;
int V_56 ;
V_24 = F_17 ( V_57 ) ;
if ( ! V_24 )
return - V_58 ;
V_38 = F_18 ( V_24 ) ;
V_56 = F_19 ( V_53 , V_55 , V_38 ) ;
if ( V_56 < 0 ) {
V_44 = V_56 ;
goto V_59;
}
V_44 = F_13 ( F_20 ( V_53 ) , V_38 ) ;
V_59:
F_21 ( V_24 ) ;
return V_44 ;
}
struct V_60 * F_22 ( struct V_60 * V_61 , struct V_53 * V_53 ,
struct V_54 * V_55 )
{
T_3 V_44 ;
V_44 = F_16 ( V_53 , V_55 ) ;
if ( ( int ) V_44 < 0 )
return F_2 ( ( int ) V_44 ) ;
return F_23 ( V_61 , V_44 ) ;
}
static struct V_62 * F_24 ( struct V_63 * V_64 ,
char * V_24 , char * V_25 ,
const struct V_65 * V_66 )
{
const T_2 V_67 = sizeof( struct V_68 ) ;
struct V_33 * V_33 = F_25 ( F_26 ( V_64 -> V_69 ) -> V_70 ) ;
struct V_62 * V_71 = F_2 ( - V_29 ) ;
char * V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
V_72 = F_1 ( & V_66 -> V_75 , V_25 , V_27 ) ;
if ( F_6 ( V_72 ) )
return F_27 ( V_72 ) ;
V_64 -> V_72 = V_72 ;
V_73 = V_72 - 1 - V_25 ;
V_64 -> V_76 = F_28 ( V_67 , V_57 ) ;
if ( V_64 -> V_76 == NULL )
return F_2 ( - V_58 ) ;
for ( V_74 = 0 ; V_74 < V_66 -> V_77 ; V_74 ++ ) {
const struct V_8 * V_78 = & V_66 -> V_79 [ V_74 ] ;
if ( V_78 -> V_11 <= 0 || V_78 -> V_11 >= V_73 )
continue;
if ( memchr ( V_78 -> V_13 , V_80 , V_78 -> V_11 ) )
continue;
V_64 -> V_81 = F_10 ( V_78 -> V_13 , V_78 -> V_11 ,
V_64 -> V_76 , V_67 , V_33 ) ;
if ( V_64 -> V_81 == 0 )
continue;
F_29 ( V_64 -> V_76 , V_82 ) ;
memcpy ( V_25 , V_78 -> V_13 , V_78 -> V_11 ) ;
V_25 [ V_78 -> V_11 ] = '\0' ;
V_64 -> V_83 = V_25 ;
snprintf ( V_24 , V_27 , L_2 ,
V_64 -> V_83 ,
V_64 -> V_72 ) ;
V_71 = F_30 ( & V_84 , 0 , V_24 , V_64 ) ;
if ( ! F_6 ( V_71 ) )
break;
}
F_31 ( V_64 -> V_76 ) ;
return V_71 ;
}
static struct V_62 * F_32 ( struct V_17 * V_17 ,
const struct V_22 * V_23 )
{
struct V_62 * V_71 = F_2 ( - V_29 ) ;
struct V_63 V_64 = {
. V_69 = V_17 -> V_85 ,
. V_17 = V_17 ,
. V_86 = F_26 ( V_17 -> V_85 ) -> V_70 -> V_87 -> V_88 ,
} ;
char * V_24 = NULL , * V_25 = NULL ;
int V_89 , error ;
if ( V_23 == NULL || V_23 -> V_90 <= 0 )
goto V_59;
F_9 ( L_3 , V_28 , V_17 ) ;
V_24 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_24 )
goto V_59;
V_25 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_25 )
goto V_59;
error = F_7 ( V_17 , V_23 , V_24 , V_25 ) ;
if ( error < 0 ) {
V_71 = F_2 ( error ) ;
goto V_59;
}
for ( V_89 = 0 ; V_89 < V_23 -> V_90 ; V_89 ++ ) {
const struct V_65 * V_66 = & V_23 -> V_23 [ V_89 ] ;
if ( V_66 == NULL || V_66 -> V_77 <= 0 ||
V_66 -> V_75 . V_7 == 0 )
continue;
V_71 = F_24 ( & V_64 , V_24 , V_25 , V_66 ) ;
if ( ! F_6 ( V_71 ) )
break;
}
V_59:
F_34 ( ( unsigned long ) V_24 ) ;
F_34 ( ( unsigned long ) V_25 ) ;
F_9 ( L_4 , V_28 ) ;
return V_71 ;
}
static struct V_62 * F_35 ( struct V_60 * V_70 , struct V_17 * V_17 )
{
struct V_62 * V_71 = F_2 ( - V_58 ) ;
struct V_17 * V_92 ;
struct V_22 * V_93 = NULL ;
struct V_24 * V_24 ;
int V_56 ;
F_9 ( L_5 , V_28 ) ;
V_24 = F_17 ( V_57 ) ;
if ( V_24 == NULL )
goto V_59;
V_93 = F_28 ( sizeof( struct V_22 ) , V_57 ) ;
if ( V_93 == NULL )
goto V_94;
V_71 = F_2 ( - V_29 ) ;
V_92 = F_36 ( V_17 ) ;
F_9 ( L_6 ,
V_28 , V_17 ) ;
V_56 = F_37 ( V_70 , V_92 -> V_95 , & V_17 -> V_96 , V_93 , V_24 ) ;
F_38 ( V_92 ) ;
if ( V_56 != 0 ||
V_93 -> V_90 <= 0 ||
V_93 -> V_26 . V_7 <= 0 )
goto V_94;
V_71 = F_32 ( V_17 , V_93 ) ;
V_94:
F_39 ( V_24 ) ;
F_31 ( V_93 ) ;
V_59:
F_9 ( L_4 , V_28 ) ;
return V_71 ;
}
struct V_62 * F_40 ( struct V_35 * V_36 , struct V_17 * V_17 ,
struct V_97 * V_98 , struct V_99 * V_100 )
{
T_3 V_44 = V_36 -> V_70 -> V_87 -> V_88 ;
struct V_17 * V_92 = F_36 ( V_17 ) ;
struct V_53 * V_101 = V_92 -> V_95 ;
struct V_54 * V_55 = & V_17 -> V_96 ;
struct V_60 * V_70 ;
struct V_62 * V_71 ;
V_70 = F_41 ( V_101 , V_55 , V_98 , V_100 ) ;
F_38 ( V_92 ) ;
if ( F_6 ( V_70 ) )
return F_27 ( V_70 ) ;
if ( V_100 -> V_102 & V_103 ) {
V_71 = F_35 ( V_70 , V_17 ) ;
goto V_59;
}
if ( V_70 -> V_87 -> V_88 != V_44 )
V_44 = V_70 -> V_87 -> V_88 ;
else {
T_3 V_104 = F_16 ( V_101 , V_55 ) ;
if ( ( int ) V_104 >= 0 )
V_44 = V_104 ;
}
V_71 = F_42 ( V_17 , V_98 , V_100 , V_44 ) ;
V_59:
F_43 ( V_70 ) ;
return V_71 ;
}
static int F_44 ( struct V_35 * V_36 ,
char * V_24 , char * V_25 ,
const struct V_65 * V_66 )
{
const T_2 V_67 = sizeof( struct V_68 ) ;
struct V_33 * V_33 = F_25 ( V_36 -> V_70 ) ;
struct V_30 * V_105 ;
unsigned int V_74 ;
T_2 V_32 ;
int error ;
V_105 = F_28 ( V_67 , V_57 ) ;
if ( V_105 == NULL )
return - V_58 ;
error = - V_29 ;
for ( V_74 = 0 ; V_74 < V_66 -> V_77 ; V_74 ++ ) {
const struct V_8 * V_78 = & V_66 -> V_79 [ V_74 ] ;
char * V_83 ;
if ( V_78 -> V_11 <= 0 || V_78 -> V_11 > V_27 )
continue;
if ( memchr ( V_78 -> V_13 , V_80 , V_78 -> V_11 ) != NULL )
continue;
V_32 = F_10 ( V_78 -> V_13 , V_78 -> V_11 ,
V_105 , V_67 , V_33 ) ;
if ( V_32 == 0 )
continue;
F_29 ( V_105 , V_82 ) ;
error = - V_58 ;
V_83 = F_45 ( V_78 -> V_13 , V_78 -> V_11 , V_57 ) ;
if ( V_83 == NULL )
break;
error = F_46 ( V_36 , V_83 , V_105 , V_32 , V_33 ) ;
F_31 ( V_83 ) ;
if ( error == 0 )
break;
}
F_31 ( V_105 ) ;
return error ;
}
int F_47 ( struct V_35 * V_36 ,
const struct V_22 * V_23 )
{
char * V_24 = NULL , * V_25 = NULL ;
int V_89 , error ;
error = - V_29 ;
if ( V_23 == NULL || V_23 -> V_90 <= 0 )
goto V_59;
error = - V_58 ;
V_24 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_24 )
goto V_59;
V_25 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_25 )
goto V_59;
for ( V_89 = 0 ; V_89 < V_23 -> V_90 ; V_89 ++ ) {
const struct V_65 * V_66 =
& V_23 -> V_23 [ V_89 ] ;
if ( V_66 == NULL || V_66 -> V_77 <= 0 ||
V_66 -> V_75 . V_7 == 0 )
continue;
error = F_44 ( V_36 , V_24 ,
V_25 , V_66 ) ;
if ( error == 0 )
break;
}
V_59:
F_34 ( ( unsigned long ) V_24 ) ;
F_34 ( ( unsigned long ) V_25 ) ;
return error ;
}
