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
static T_3 F_14 ( struct V_33 * V_34 ,
struct V_38 * V_39 )
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
if ( V_40 != V_50 &&
F_16 ( & V_34 -> V_51 ,
V_40 ) )
return V_40 ;
break;
}
}
if ( V_34 -> V_51 . V_52 > 0 )
return - V_53 ;
return V_47 ;
}
static T_3 F_17 ( struct V_54 * V_54 , struct V_55 * V_56 )
{
struct V_24 * V_24 ;
struct V_38 * V_39 ;
T_3 V_45 ;
int V_57 ;
V_24 = F_18 ( V_58 ) ;
if ( ! V_24 )
return - V_59 ;
V_39 = F_19 ( V_24 ) ;
V_57 = F_20 ( V_54 , V_56 , V_39 ) ;
if ( V_57 < 0 ) {
V_45 = V_57 ;
goto V_60;
}
V_45 = F_14 ( F_21 ( V_54 ) , V_39 ) ;
V_60:
F_22 ( V_24 ) ;
return V_45 ;
}
struct V_61 * F_23 ( struct V_61 * V_62 , struct V_54 * V_54 ,
struct V_55 * V_56 )
{
T_3 V_45 ;
V_45 = F_17 ( V_54 , V_56 ) ;
if ( ( int ) V_45 < 0 )
return F_2 ( ( int ) V_45 ) ;
return F_24 ( V_62 , V_45 ) ;
}
static struct V_63 * F_25 ( struct V_64 * V_65 ,
char * V_24 , char * V_25 ,
const struct V_66 * V_67 )
{
const T_2 V_68 = sizeof( struct V_69 ) ;
struct V_63 * V_70 = F_2 ( - V_29 ) ;
char * V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
V_71 = F_1 ( & V_67 -> V_74 , V_25 , V_27 ) ;
if ( F_6 ( V_71 ) )
return F_26 ( V_71 ) ;
V_65 -> V_71 = V_71 ;
V_72 = V_71 - 1 - V_25 ;
V_65 -> V_75 = F_27 ( V_68 , V_58 ) ;
if ( V_65 -> V_75 == NULL )
return F_2 ( - V_59 ) ;
for ( V_73 = 0 ; V_73 < V_67 -> V_76 ; V_73 ++ ) {
const struct V_8 * V_77 = & V_67 -> V_78 [ V_73 ] ;
if ( V_77 -> V_11 <= 0 || V_77 -> V_11 >= V_72 )
continue;
if ( memchr ( V_77 -> V_13 , V_79 , V_77 -> V_11 ) )
continue;
V_65 -> V_80 = F_10 ( V_77 -> V_13 , V_77 -> V_11 ,
V_65 -> V_75 , V_68 ,
F_28 ( V_65 -> V_81 ) ) ;
if ( V_65 -> V_80 == 0 )
continue;
F_29 ( V_65 -> V_75 , V_82 ) ;
memcpy ( V_25 , V_77 -> V_13 , V_77 -> V_11 ) ;
V_25 [ V_77 -> V_11 ] = '\0' ;
V_65 -> V_83 = V_25 ;
snprintf ( V_24 , V_27 , L_2 ,
V_65 -> V_83 ,
V_65 -> V_71 ) ;
V_70 = F_30 ( & V_84 , 0 , V_24 , V_65 ) ;
if ( ! F_6 ( V_70 ) )
break;
}
F_31 ( V_65 -> V_75 ) ;
return V_70 ;
}
static struct V_63 * F_32 ( struct V_17 * V_17 ,
const struct V_22 * V_23 )
{
struct V_63 * V_70 = F_2 ( - V_29 ) ;
struct V_64 V_65 = {
. V_81 = V_17 -> V_85 ,
. V_17 = V_17 ,
. V_86 = F_28 ( V_17 -> V_85 ) -> V_36 -> V_87 -> V_88 ,
} ;
char * V_24 = NULL , * V_25 = NULL ;
int V_89 , error ;
if ( V_23 == NULL || V_23 -> V_90 <= 0 )
goto V_60;
F_9 ( L_3 , V_28 , V_17 ) ;
V_24 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_24 )
goto V_60;
V_25 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_25 )
goto V_60;
error = F_7 ( V_17 , V_23 , V_24 , V_25 ) ;
if ( error < 0 ) {
V_70 = F_2 ( error ) ;
goto V_60;
}
for ( V_89 = 0 ; V_89 < V_23 -> V_90 ; V_89 ++ ) {
const struct V_66 * V_67 = & V_23 -> V_23 [ V_89 ] ;
if ( V_67 == NULL || V_67 -> V_76 <= 0 ||
V_67 -> V_74 . V_7 == 0 )
continue;
V_70 = F_25 ( & V_65 , V_24 , V_25 , V_67 ) ;
if ( ! F_6 ( V_70 ) )
break;
}
V_60:
F_34 ( ( unsigned long ) V_24 ) ;
F_34 ( ( unsigned long ) V_25 ) ;
F_9 ( L_4 , V_28 ) ;
return V_70 ;
}
static struct V_63 * F_35 ( struct V_61 * V_36 , struct V_17 * V_17 )
{
struct V_63 * V_70 = F_2 ( - V_59 ) ;
struct V_17 * V_92 ;
struct V_22 * V_93 = NULL ;
struct V_24 * V_24 ;
int V_57 ;
F_9 ( L_5 , V_28 ) ;
V_24 = F_18 ( V_58 ) ;
if ( V_24 == NULL )
goto V_60;
V_93 = F_27 ( sizeof( struct V_22 ) , V_58 ) ;
if ( V_93 == NULL )
goto V_94;
V_70 = F_2 ( - V_29 ) ;
V_92 = F_36 ( V_17 ) ;
F_9 ( L_6 ,
V_28 , V_17 ) ;
V_57 = F_37 ( V_36 , V_92 -> V_95 , & V_17 -> V_96 , V_93 , V_24 ) ;
F_38 ( V_92 ) ;
if ( V_57 != 0 ||
V_93 -> V_90 <= 0 ||
V_93 -> V_26 . V_7 <= 0 )
goto V_94;
V_70 = F_32 ( V_17 , V_93 ) ;
V_94:
F_39 ( V_24 ) ;
F_31 ( V_93 ) ;
V_60:
F_9 ( L_4 , V_28 ) ;
return V_70 ;
}
struct V_63 * F_40 ( struct V_33 * V_34 , struct V_17 * V_17 ,
struct V_97 * V_98 , struct V_99 * V_100 )
{
T_3 V_45 = V_34 -> V_36 -> V_87 -> V_88 ;
struct V_17 * V_92 = F_36 ( V_17 ) ;
struct V_54 * V_101 = V_92 -> V_95 ;
struct V_55 * V_56 = & V_17 -> V_96 ;
struct V_61 * V_36 ;
struct V_63 * V_70 ;
V_36 = F_41 ( V_101 , V_56 , V_98 , V_100 ) ;
F_38 ( V_92 ) ;
if ( F_6 ( V_36 ) )
return F_26 ( V_36 ) ;
if ( V_100 -> V_102 & V_103 ) {
V_70 = F_35 ( V_36 , V_17 ) ;
goto V_60;
}
if ( V_36 -> V_87 -> V_88 != V_45 )
V_45 = V_36 -> V_87 -> V_88 ;
else {
T_3 V_104 = F_17 ( V_101 , V_56 ) ;
if ( ( int ) V_104 >= 0 )
V_45 = V_104 ;
}
V_70 = F_42 ( V_17 , V_98 , V_100 , V_45 ) ;
V_60:
F_43 ( V_36 ) ;
return V_70 ;
}
static int F_44 ( struct V_33 * V_34 ,
char * V_24 , char * V_25 ,
const struct V_66 * V_67 )
{
const T_2 V_68 = sizeof( struct V_69 ) ;
struct V_30 * V_105 ;
unsigned int V_73 ;
T_2 V_32 ;
int error ;
V_105 = F_27 ( V_68 , V_58 ) ;
if ( V_105 == NULL )
return - V_59 ;
error = - V_29 ;
for ( V_73 = 0 ; V_73 < V_67 -> V_76 ; V_73 ++ ) {
const struct V_8 * V_77 = & V_67 -> V_78 [ V_73 ] ;
char * V_83 ;
if ( V_77 -> V_11 <= 0 || V_77 -> V_11 > V_27 )
continue;
if ( memchr ( V_77 -> V_13 , V_79 , V_77 -> V_11 ) != NULL )
continue;
V_32 = F_10 ( V_77 -> V_13 , V_77 -> V_11 ,
V_105 , V_68 , V_34 ) ;
if ( V_32 == 0 )
continue;
F_29 ( V_105 , V_82 ) ;
error = - V_59 ;
V_83 = F_45 ( V_77 -> V_13 , V_77 -> V_11 , V_58 ) ;
if ( V_83 == NULL )
break;
error = F_46 ( V_34 , V_83 , V_105 , V_32 ) ;
F_31 ( V_83 ) ;
if ( error == 0 )
break;
}
F_31 ( V_105 ) ;
return error ;
}
int F_47 ( struct V_33 * V_34 ,
const struct V_22 * V_23 )
{
char * V_24 = NULL , * V_25 = NULL ;
int V_89 , error ;
error = - V_29 ;
if ( V_23 == NULL || V_23 -> V_90 <= 0 )
goto V_60;
error = - V_59 ;
V_24 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_24 )
goto V_60;
V_25 = ( char * ) F_33 ( V_91 ) ;
if ( ! V_25 )
goto V_60;
for ( V_89 = 0 ; V_89 < V_23 -> V_90 ; V_89 ++ ) {
const struct V_66 * V_67 =
& V_23 -> V_23 [ V_89 ] ;
if ( V_67 == NULL || V_67 -> V_76 <= 0 ||
V_67 -> V_74 . V_7 == 0 )
continue;
error = F_44 ( V_34 , V_24 ,
V_25 , V_67 ) ;
if ( error == 0 )
break;
}
V_60:
F_34 ( ( unsigned long ) V_24 ) ;
F_34 ( ( unsigned long ) V_25 ) ;
return error ;
}
