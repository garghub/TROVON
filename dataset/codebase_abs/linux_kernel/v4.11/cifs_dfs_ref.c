static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
F_2 ( V_4 ) ;
if ( ! F_3 ( V_4 ) )
F_4 ( & V_6 ,
V_7 ) ;
}
void F_5 ( void )
{
F_6 ( ! F_3 ( & V_5 ) ) ;
F_7 ( & V_6 ) ;
}
static char *
F_8 ( char * V_8 , const char * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
char * V_12 ;
char * V_13 ;
V_8 += strspn ( V_8 , L_1 ) ;
if ( ! * V_8 )
return F_9 ( - V_14 ) ;
V_11 = strlen ( V_8 ) ;
V_13 = V_8 + V_11 - 1 ;
while ( * V_13 == '\\' ) {
-- V_13 ;
-- V_11 ;
}
V_10 = V_9 ? strlen ( V_9 ) : 0 ;
V_12 = F_10 ( 2 + V_11 + 1 + V_10 + 1 , V_15 ) ;
if ( ! V_12 )
return F_9 ( - V_16 ) ;
V_13 = V_12 ;
* V_13 = '/' ;
++ V_13 ;
* V_13 = '/' ;
++ V_13 ;
memcpy ( V_13 , V_8 , V_11 ) ;
V_13 += V_11 ;
if ( V_10 ) {
* V_13 = '/' ;
++ V_13 ;
memcpy ( V_13 , V_9 , V_10 ) ;
V_13 += V_10 ;
}
* V_13 = '\0' ;
F_11 ( V_12 , '/' ) ;
return V_12 ;
}
char * F_12 ( const char * V_17 ,
const char * V_18 ,
const struct V_19 * V_20 ,
char * * V_21 )
{
int V_22 ;
char * V_23 = NULL ;
const char * V_9 = NULL ;
int V_24 ;
char * V_25 ;
char * V_26 = NULL ;
char V_27 = ',' ;
int V_28 , V_29 ;
if ( V_17 == NULL )
return F_9 ( - V_14 ) ;
if ( strlen ( V_18 ) - V_20 -> V_30 ) {
V_9 = V_18 + V_20 -> V_30 ;
if ( * V_9 == '/' || * V_9 == '\\' )
V_9 ++ ;
}
* V_21 = F_8 ( V_20 -> V_31 , V_9 ) ;
if ( F_13 ( * V_21 ) ) {
V_22 = F_14 ( * V_21 ) ;
* V_21 = NULL ;
goto V_32;
}
V_22 = F_15 ( * V_21 , & V_26 ) ;
if ( V_22 < 0 ) {
F_16 ( V_33 , L_2 ,
V_34 , * V_21 , V_22 ) ;
goto V_32;
}
V_24 = strlen ( V_17 ) + V_35 ;
V_23 = F_17 ( V_24 + sizeof( L_3 ) + 1 , V_15 ) ;
if ( V_23 == NULL ) {
V_22 = - V_16 ;
goto V_32;
}
V_28 = 0 ;
if ( strncmp ( V_17 , L_4 , 4 ) == 0 ) {
V_27 = V_17 [ 4 ] ;
strncpy ( V_23 , V_17 , 5 ) ;
V_28 += 5 ;
}
do {
V_25 = strchr ( V_17 + V_28 , V_27 ) ;
if ( V_25 == NULL )
V_29 = strlen ( V_17 + V_28 ) ;
else
V_29 = V_25 - ( V_17 + V_28 ) + 1 ;
if ( strncasecmp ( V_17 + V_28 , L_5 , 4 ) == 0 ) {
V_28 += V_29 ;
continue;
}
if ( strncasecmp ( V_17 + V_28 , L_3 , 3 ) == 0 ) {
V_28 += V_29 ;
continue;
}
if ( strncasecmp ( V_17 + V_28 , L_6 , 11 ) == 0 ) {
V_28 += V_29 ;
continue;
}
strncat ( V_23 , V_17 + V_28 , V_29 ) ;
V_28 += V_29 ;
} while ( V_25 );
strcat ( V_23 , V_17 + V_28 ) ;
V_23 [ V_24 ] = '\0' ;
if ( V_23 [ strlen ( V_23 ) - 1 ] != V_27 )
strncat ( V_23 , & V_27 , 1 ) ;
strcat ( V_23 , L_3 ) ;
strcat ( V_23 , V_26 ) ;
V_36:
F_18 ( V_26 ) ;
return V_23 ;
V_32:
F_18 ( V_23 ) ;
V_23 = F_9 ( V_22 ) ;
F_18 ( * V_21 ) ;
* V_21 = NULL ;
goto V_36;
}
static struct V_37 * F_19 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
const char * V_18 , const struct V_19 * V_20 )
{
struct V_37 * V_42 ;
char * V_23 ;
char * V_21 = NULL ;
V_23 = F_12 ( V_41 -> V_23 ,
V_18 + 1 , V_20 , & V_21 ) ;
if ( F_13 ( V_23 ) )
return (struct V_37 * ) V_23 ;
V_42 = F_20 ( V_39 , & V_43 , V_21 , V_23 ) ;
F_18 ( V_23 ) ;
F_18 ( V_21 ) ;
return V_42 ;
}
static void F_21 ( const struct V_19 * V_20 )
{
F_16 ( V_33 , L_7 , V_20 -> V_44 ) ;
F_16 ( V_33 , L_8 , V_20 -> V_31 ) ;
F_16 ( V_33 , L_9 ,
V_20 -> V_45 , V_20 -> V_46 ) ;
F_16 ( V_33 , L_10 ,
V_20 -> V_47 , V_20 -> V_30 ) ;
}
static struct V_37 * F_22 ( struct V_38 * V_39 )
{
struct V_19 * V_48 = NULL ;
unsigned int V_49 = 0 ;
struct V_40 * V_41 ;
struct V_50 * V_51 ;
char * V_52 ;
unsigned int V_53 ;
int V_54 ;
int V_22 ;
struct V_37 * V_42 ;
struct V_55 * V_56 ;
F_16 ( V_33 , L_11 , V_34 ) ;
F_6 ( F_23 ( V_39 ) ) ;
V_42 = F_9 ( - V_16 ) ;
V_52 = F_24 ( V_39 , true ) ;
if ( V_52 == NULL )
goto V_57;
V_41 = F_25 ( V_39 -> V_58 ) ;
V_56 = F_26 ( V_41 ) ;
if ( F_13 ( V_56 ) ) {
V_42 = F_27 ( V_56 ) ;
goto V_59;
}
V_51 = F_28 ( V_56 ) -> V_51 ;
V_53 = F_29 () ;
V_22 = F_30 ( V_53 , V_51 , V_52 + 1 , V_41 -> V_60 ,
& V_49 , & V_48 ,
F_31 ( V_41 ) ) ;
F_32 ( V_53 ) ;
F_33 ( V_56 ) ;
V_42 = F_9 ( - V_61 ) ;
for ( V_54 = 0 ; V_54 < V_49 ; V_54 ++ ) {
int V_62 ;
F_21 ( V_48 + V_54 ) ;
V_62 = strlen ( V_48 [ V_54 ] . V_31 ) ;
if ( V_62 < 2 ) {
F_16 ( V_63 , L_12 ,
V_34 , V_48 [ V_54 ] . V_31 ) ;
V_42 = F_9 ( - V_14 ) ;
break;
}
V_42 = F_19 ( V_39 , V_41 ,
V_52 , V_48 + V_54 ) ;
F_16 ( V_33 , L_13 ,
V_34 , V_48 [ V_54 ] . V_31 , V_42 ) ;
if ( ! F_13 ( V_42 ) )
goto V_64;
}
if ( V_22 != 0 )
V_42 = F_9 ( V_22 ) ;
V_64:
F_34 ( V_48 , V_49 ) ;
V_59:
F_18 ( V_52 ) ;
V_57:
F_16 ( V_33 , L_14 , V_34 ) ;
return V_42 ;
}
struct V_37 * F_35 ( struct V_65 * V_65 )
{
struct V_37 * V_66 ;
F_16 ( V_33 , L_11 , V_34 ) ;
V_66 = F_22 ( V_65 -> V_38 ) ;
if ( F_13 ( V_66 ) ) {
F_16 ( V_33 , L_15 , V_34 ) ;
return V_66 ;
}
F_36 ( V_66 ) ;
F_37 ( V_66 , & V_5 ) ;
F_4 ( & V_6 ,
V_7 ) ;
F_16 ( V_33 , L_16 , V_34 ) ;
return V_66 ;
}
