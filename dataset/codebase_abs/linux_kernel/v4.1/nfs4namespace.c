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
static struct V_35 * F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
T_3 V_41 ;
struct V_42 * V_43 ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_43 = & V_40 -> V_40 [ V_44 ] ;
switch ( V_43 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
V_41 = F_14 ( V_43 -> V_46 ,
& V_43 -> V_50 ) ;
if ( V_41 != V_51 &&
F_15 ( & V_38 -> V_52 , V_41 ) ) {
struct V_35 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_16 ( V_36 , V_41 ) ;
if ( F_6 ( V_53 ) )
continue;
V_55 = F_17 ( V_53 -> V_56 , 0 ) ;
if ( F_6 ( V_55 ) ) {
F_18 ( V_53 ) ;
continue;
}
F_19 ( V_55 ) ;
return V_53 ;
}
}
}
return F_2 ( - V_57 ) ;
}
struct V_35 *
F_20 ( struct V_35 * V_36 , struct V_58 * V_58 ,
struct V_59 * V_60 )
{
struct V_24 * V_24 ;
struct V_39 * V_40 ;
struct V_35 * V_53 ;
int V_61 ;
V_24 = F_21 ( V_62 ) ;
if ( ! V_24 )
return F_2 ( - V_63 ) ;
V_40 = F_22 ( V_24 ) ;
V_61 = F_23 ( V_58 , V_60 , V_40 ) ;
if ( V_61 < 0 ) {
V_53 = F_2 ( V_61 ) ;
goto V_64;
}
V_53 = F_13 ( V_36 , F_24 ( V_58 ) , V_40 ) ;
V_64:
F_25 ( V_24 ) ;
return V_53 ;
}
static struct V_65 * F_26 ( struct V_66 * V_67 ,
char * V_24 , char * V_25 ,
const struct V_68 * V_69 )
{
const T_2 V_70 = sizeof( struct V_71 ) ;
struct V_33 * V_33 = F_27 ( F_28 ( V_67 -> V_72 ) -> V_73 ) ;
struct V_65 * V_74 = F_2 ( - V_29 ) ;
char * V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
V_75 = F_1 ( & V_69 -> V_78 , V_25 , V_27 ) ;
if ( F_6 ( V_75 ) )
return F_29 ( V_75 ) ;
V_67 -> V_75 = V_75 ;
V_76 = V_75 - 1 - V_25 ;
V_67 -> V_79 = F_30 ( V_70 , V_62 ) ;
if ( V_67 -> V_79 == NULL )
return F_2 ( - V_63 ) ;
for ( V_77 = 0 ; V_77 < V_69 -> V_80 ; V_77 ++ ) {
const struct V_8 * V_81 = & V_69 -> V_82 [ V_77 ] ;
if ( V_81 -> V_11 <= 0 || V_81 -> V_11 >= V_76 )
continue;
if ( memchr ( V_81 -> V_13 , V_83 , V_81 -> V_11 ) )
continue;
V_67 -> V_84 = F_10 ( V_81 -> V_13 , V_81 -> V_11 ,
V_67 -> V_79 , V_70 , V_33 ) ;
if ( V_67 -> V_84 == 0 )
continue;
F_31 ( V_67 -> V_79 , V_85 ) ;
memcpy ( V_25 , V_81 -> V_13 , V_81 -> V_11 ) ;
V_25 [ V_81 -> V_11 ] = '\0' ;
V_67 -> V_86 = V_25 ;
snprintf ( V_24 , V_27 , L_2 ,
V_67 -> V_86 ,
V_67 -> V_75 ) ;
V_74 = F_32 ( & V_87 , 0 , V_24 , V_67 ) ;
if ( ! F_6 ( V_74 ) )
break;
}
F_33 ( V_67 -> V_79 ) ;
return V_74 ;
}
static struct V_65 * F_34 ( struct V_17 * V_17 ,
const struct V_22 * V_23 )
{
struct V_65 * V_74 = F_2 ( - V_29 ) ;
struct V_66 V_67 = {
. V_72 = V_17 -> V_88 ,
. V_17 = V_17 ,
. V_89 = F_28 ( V_17 -> V_88 ) -> V_73 -> V_56 -> V_90 ,
} ;
char * V_24 = NULL , * V_25 = NULL ;
int V_91 , error ;
if ( V_23 == NULL || V_23 -> V_92 <= 0 )
goto V_64;
F_9 ( L_3 , V_28 , V_17 ) ;
V_24 = ( char * ) F_35 ( V_93 ) ;
if ( ! V_24 )
goto V_64;
V_25 = ( char * ) F_35 ( V_93 ) ;
if ( ! V_25 )
goto V_64;
error = F_7 ( V_17 , V_23 , V_24 , V_25 ) ;
if ( error < 0 ) {
V_74 = F_2 ( error ) ;
goto V_64;
}
for ( V_91 = 0 ; V_91 < V_23 -> V_92 ; V_91 ++ ) {
const struct V_68 * V_69 = & V_23 -> V_23 [ V_91 ] ;
if ( V_69 == NULL || V_69 -> V_80 <= 0 ||
V_69 -> V_78 . V_7 == 0 )
continue;
V_74 = F_26 ( & V_67 , V_24 , V_25 , V_69 ) ;
if ( ! F_6 ( V_74 ) )
break;
}
V_64:
F_36 ( ( unsigned long ) V_24 ) ;
F_36 ( ( unsigned long ) V_25 ) ;
F_9 ( L_4 , V_28 ) ;
return V_74 ;
}
static struct V_65 * F_37 ( struct V_35 * V_73 , struct V_17 * V_17 )
{
struct V_65 * V_74 = F_2 ( - V_63 ) ;
struct V_17 * V_94 ;
struct V_22 * V_95 = NULL ;
struct V_24 * V_24 ;
int V_61 ;
F_9 ( L_5 , V_28 ) ;
V_24 = F_21 ( V_62 ) ;
if ( V_24 == NULL )
goto V_64;
V_95 = F_30 ( sizeof( struct V_22 ) , V_62 ) ;
if ( V_95 == NULL )
goto V_96;
V_74 = F_2 ( - V_29 ) ;
V_94 = F_38 ( V_17 ) ;
F_9 ( L_6 ,
V_28 , V_17 ) ;
V_61 = F_39 ( V_73 , F_40 ( V_94 ) , & V_17 -> V_97 , V_95 , V_24 ) ;
F_41 ( V_94 ) ;
if ( V_61 != 0 ||
V_95 -> V_92 <= 0 ||
V_95 -> V_26 . V_7 <= 0 )
goto V_96;
V_74 = F_34 ( V_17 , V_95 ) ;
V_96:
F_42 ( V_24 ) ;
F_33 ( V_95 ) ;
V_64:
F_9 ( L_4 , V_28 ) ;
return V_74 ;
}
struct V_65 * F_43 ( struct V_37 * V_38 , struct V_17 * V_17 ,
struct V_98 * V_99 , struct V_100 * V_101 )
{
T_3 V_46 = V_38 -> V_73 -> V_56 -> V_90 ;
struct V_17 * V_94 = F_38 ( V_17 ) ;
struct V_58 * V_102 = F_40 ( V_94 ) ;
struct V_59 * V_60 = & V_17 -> V_97 ;
struct V_35 * V_73 ;
struct V_65 * V_74 ;
V_73 = F_44 ( V_102 , V_60 , V_99 , V_101 ) ;
F_41 ( V_94 ) ;
if ( F_6 ( V_73 ) )
return F_29 ( V_73 ) ;
if ( V_101 -> V_103 & V_104 ) {
V_74 = F_37 ( V_73 , V_17 ) ;
goto V_64;
}
if ( V_73 -> V_56 -> V_90 != V_46 )
V_46 = V_73 -> V_56 -> V_90 ;
V_74 = F_45 ( V_17 , V_99 , V_101 , V_46 ) ;
V_64:
F_18 ( V_73 ) ;
return V_74 ;
}
static int F_46 ( struct V_37 * V_38 ,
char * V_24 , char * V_25 ,
const struct V_68 * V_69 )
{
const T_2 V_70 = sizeof( struct V_71 ) ;
struct V_33 * V_33 = F_27 ( V_38 -> V_73 ) ;
struct V_30 * V_105 ;
unsigned int V_77 ;
T_2 V_32 ;
int error ;
V_105 = F_30 ( V_70 , V_62 ) ;
if ( V_105 == NULL )
return - V_63 ;
error = - V_29 ;
for ( V_77 = 0 ; V_77 < V_69 -> V_80 ; V_77 ++ ) {
const struct V_8 * V_81 = & V_69 -> V_82 [ V_77 ] ;
char * V_86 ;
if ( V_81 -> V_11 <= 0 || V_81 -> V_11 > V_27 )
continue;
if ( memchr ( V_81 -> V_13 , V_83 , V_81 -> V_11 ) != NULL )
continue;
V_32 = F_10 ( V_81 -> V_13 , V_81 -> V_11 ,
V_105 , V_70 , V_33 ) ;
if ( V_32 == 0 )
continue;
F_31 ( V_105 , V_85 ) ;
error = - V_63 ;
V_86 = F_47 ( V_81 -> V_13 , V_81 -> V_11 , V_62 ) ;
if ( V_86 == NULL )
break;
error = F_48 ( V_38 , V_86 , V_105 , V_32 , V_33 ) ;
F_33 ( V_86 ) ;
if ( error == 0 )
break;
}
F_33 ( V_105 ) ;
return error ;
}
int F_49 ( struct V_37 * V_38 ,
const struct V_22 * V_23 )
{
char * V_24 = NULL , * V_25 = NULL ;
int V_91 , error ;
error = - V_29 ;
if ( V_23 == NULL || V_23 -> V_92 <= 0 )
goto V_64;
error = - V_63 ;
V_24 = ( char * ) F_35 ( V_93 ) ;
if ( ! V_24 )
goto V_64;
V_25 = ( char * ) F_35 ( V_93 ) ;
if ( ! V_25 )
goto V_64;
for ( V_91 = 0 ; V_91 < V_23 -> V_92 ; V_91 ++ ) {
const struct V_68 * V_69 =
& V_23 -> V_23 [ V_91 ] ;
if ( V_69 == NULL || V_69 -> V_80 <= 0 ||
V_69 -> V_78 . V_7 == 0 )
continue;
error = F_46 ( V_38 , V_24 ,
V_25 , V_69 ) ;
if ( error == 0 )
break;
}
V_64:
F_36 ( ( unsigned long ) V_24 ) ;
F_36 ( ( unsigned long ) V_25 ) ;
return error ;
}
