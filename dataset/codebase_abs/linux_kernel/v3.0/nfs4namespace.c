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
static char * F_3 ( struct V_15 * V_15 , char * V_3 , T_1 V_4 )
{
char * V_16 ;
char * V_17 = F_4 ( & V_16 , V_15 , V_3 , V_4 ) ;
if ( ! F_5 ( V_17 ) ) {
char * V_18 = strchr ( V_17 , ':' ) ;
if ( V_18 && V_18 < V_16 )
V_17 = V_18 + 1 ;
}
return V_17 ;
}
static int F_6 ( struct V_15 * V_15 ,
const struct V_19 * V_20 ,
char * V_21 , char * V_22 )
{
const char * V_17 , * V_23 ;
V_17 = F_3 ( V_15 , V_21 , V_24 ) ;
if ( F_5 ( V_17 ) )
return F_7 ( V_17 ) ;
V_23 = F_1 ( & V_20 -> V_23 , V_22 , V_24 ) ;
if ( F_5 ( V_23 ) )
return F_7 ( V_23 ) ;
if ( strncmp ( V_17 , V_23 , strlen ( V_23 ) ) != 0 ) {
F_8 ( L_1 ,
V_25 , V_17 , V_23 ) ;
return - V_26 ;
}
return 0 ;
}
static T_2 F_9 ( char * string , T_2 V_11 ,
struct V_27 * V_28 , T_2 V_29 )
{
T_1 V_30 ;
V_30 = F_10 ( string , V_11 , V_28 , V_29 ) ;
if ( V_30 == 0 ) {
V_30 = F_11 ( string , V_11 , V_28 , V_29 ) ;
if ( V_30 < 0 )
V_30 = 0 ;
}
return V_30 ;
}
static struct V_31 * F_12 ( struct V_32 * V_33 ,
char * V_21 , char * V_22 ,
const struct V_34 * V_35 )
{
const T_2 V_36 = sizeof( struct V_37 ) ;
struct V_31 * V_38 = F_2 ( - V_26 ) ;
char * V_39 ;
unsigned int V_40 ;
unsigned int V_41 ;
V_39 = F_1 ( & V_35 -> V_42 , V_22 , V_24 ) ;
if ( F_5 ( V_39 ) )
return F_13 ( V_39 ) ;
V_33 -> V_39 = V_39 ;
V_40 = V_39 - 1 - V_22 ;
V_33 -> V_43 = F_14 ( V_36 , V_44 ) ;
if ( V_33 -> V_43 == NULL )
return F_2 ( - V_45 ) ;
for ( V_41 = 0 ; V_41 < V_35 -> V_46 ; V_41 ++ ) {
const struct V_8 * V_47 = & V_35 -> V_48 [ V_41 ] ;
if ( V_47 -> V_11 <= 0 || V_47 -> V_11 >= V_40 )
continue;
if ( memchr ( V_47 -> V_13 , V_49 , V_47 -> V_11 ) )
continue;
V_33 -> V_50 = F_9 ( V_47 -> V_13 , V_47 -> V_11 ,
V_33 -> V_43 , V_36 ) ;
if ( V_33 -> V_50 == 0 )
continue;
F_15 ( V_33 -> V_43 , V_51 ) ;
memcpy ( V_22 , V_47 -> V_13 , V_47 -> V_11 ) ;
V_22 [ V_47 -> V_11 ] = '\0' ;
V_33 -> V_52 = V_22 ;
snprintf ( V_21 , V_24 , L_2 ,
V_33 -> V_52 ,
V_33 -> V_39 ) ;
V_38 = F_16 ( & V_53 , 0 , V_21 , V_33 ) ;
if ( ! F_5 ( V_38 ) )
break;
}
F_17 ( V_33 -> V_43 ) ;
return V_38 ;
}
static struct V_31 * F_18 ( struct V_15 * V_15 ,
const struct V_19 * V_20 )
{
struct V_31 * V_38 = F_2 ( - V_26 ) ;
struct V_32 V_33 = {
. V_54 = V_15 -> V_55 ,
. V_15 = V_15 ,
. V_56 = F_19 ( V_15 -> V_55 ) -> V_57 -> V_58 -> V_59 ,
} ;
char * V_21 = NULL , * V_22 = NULL ;
int V_60 , error ;
if ( V_20 == NULL || V_20 -> V_61 <= 0 )
goto V_62;
F_8 ( L_3 , V_25 ,
V_15 -> V_63 -> V_64 . V_65 , V_15 -> V_64 . V_65 ) ;
V_21 = ( char * ) F_20 ( V_66 ) ;
if ( ! V_21 )
goto V_62;
V_22 = ( char * ) F_20 ( V_66 ) ;
if ( ! V_22 )
goto V_62;
error = F_6 ( V_15 , V_20 , V_21 , V_22 ) ;
if ( error < 0 ) {
V_38 = F_2 ( error ) ;
goto V_62;
}
for ( V_60 = 0 ; V_60 < V_20 -> V_61 ; V_60 ++ ) {
const struct V_34 * V_35 = & V_20 -> V_20 [ V_60 ] ;
if ( V_35 == NULL || V_35 -> V_46 <= 0 ||
V_35 -> V_42 . V_7 == 0 )
continue;
V_38 = F_12 ( & V_33 , V_21 , V_22 , V_35 ) ;
if ( ! F_5 ( V_38 ) )
break;
}
V_62:
F_21 ( ( unsigned long ) V_21 ) ;
F_21 ( ( unsigned long ) V_22 ) ;
F_8 ( L_4 , V_25 ) ;
return V_38 ;
}
struct V_31 * F_22 ( struct V_15 * V_15 )
{
struct V_31 * V_38 = F_2 ( - V_45 ) ;
struct V_15 * V_67 ;
struct V_19 * V_68 = NULL ;
struct V_21 * V_21 ;
int V_69 ;
F_8 ( L_5 , V_25 ) ;
V_21 = F_23 ( V_44 ) ;
if ( V_21 == NULL )
goto V_62;
V_68 = F_14 ( sizeof( struct V_19 ) , V_44 ) ;
if ( V_68 == NULL )
goto V_70;
V_38 = F_2 ( - V_26 ) ;
V_67 = F_24 ( V_15 ) ;
F_8 ( L_6 ,
V_25 , V_67 -> V_64 . V_65 , V_15 -> V_64 . V_65 ) ;
V_69 = F_25 ( V_67 -> V_71 , & V_15 -> V_64 , V_68 , V_21 ) ;
F_26 ( V_67 ) ;
if ( V_69 != 0 ||
V_68 -> V_61 <= 0 ||
V_68 -> V_23 . V_7 <= 0 )
goto V_70;
V_38 = F_18 ( V_15 , V_68 ) ;
V_70:
F_27 ( V_21 ) ;
F_17 ( V_68 ) ;
V_62:
F_8 ( L_4 , V_25 ) ;
return V_38 ;
}
