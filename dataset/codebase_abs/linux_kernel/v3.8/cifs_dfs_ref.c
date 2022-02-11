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
static char * F_8 ( const char * V_8 )
{
int V_9 ;
char * V_10 ;
char * V_11 ;
V_9 = strlen ( V_8 ) ;
V_10 = F_9 ( V_9 + 2 ,
V_12 ) ;
if ( ! V_10 )
return F_10 ( - V_13 ) ;
if ( V_8 [ 1 ] != '\\' ) {
V_10 [ 0 ] = '\\' ;
strncpy ( V_10 + 1 , V_8 , V_9 ) ;
V_9 ++ ;
V_10 [ V_9 ] = 0 ;
} else {
strncpy ( V_10 , V_8 , V_9 ) ;
V_10 [ V_9 ] = 0 ;
}
V_11 = memchr ( V_10 + 2 , '\\' , V_9 - 2 ) ;
if ( ! V_11 ) {
F_11 ( 1 , L_1 ,
V_14 , V_8 ) ;
F_12 ( V_10 ) ;
return F_10 ( - V_15 ) ;
}
V_11 ++ ;
V_11 = memchr ( V_10 + ( V_11 - V_10 ) , '\\' , V_9 - ( V_11 - V_10 ) ) ;
if ( V_11 ) {
* V_11 = 0 ;
}
return V_10 ;
}
char * F_13 ( const char * V_16 ,
const char * V_17 ,
const struct V_18 * V_19 ,
char * * V_20 )
{
int V_21 ;
char * V_22 = NULL ;
int V_23 ;
char * V_24 ;
char * V_25 = NULL ;
char V_26 = ',' ;
int V_27 , V_28 ;
if ( V_16 == NULL )
return F_10 ( - V_15 ) ;
* V_20 = F_8 ( V_19 -> V_8 ) ;
if ( F_14 ( * V_20 ) ) {
V_21 = F_15 ( * V_20 ) ;
* V_20 = NULL ;
goto V_29;
}
V_21 = F_16 ( * V_20 , & V_25 ) ;
if ( V_21 < 0 ) {
F_17 ( 1 , L_2 ,
V_14 , * V_20 , V_21 ) ;
goto V_29;
}
V_23 = strlen ( V_16 ) + V_21 + strlen ( V_19 -> V_8 ) + 12 ;
V_22 = F_18 ( V_23 + 1 , V_12 ) ;
if ( V_22 == NULL ) {
V_21 = - V_13 ;
goto V_29;
}
V_27 = 0 ;
if ( strncmp ( V_16 , L_3 , 4 ) == 0 ) {
V_26 = V_16 [ 4 ] ;
strncpy ( V_22 , V_16 , 5 ) ;
V_27 += 5 ;
}
do {
V_24 = strchr ( V_16 + V_27 , V_26 ) ;
if ( V_24 == NULL )
V_28 = strlen ( V_16 + V_27 ) ;
else
V_28 = V_24 - ( V_16 + V_27 ) + 1 ;
if ( F_19 ( V_16 + V_27 , L_4 , 4 ) == 0 ) {
V_27 += V_28 ;
continue;
}
if ( F_19 ( V_16 + V_27 , L_5 , 3 ) == 0 ) {
V_27 += V_28 ;
continue;
}
if ( F_19 ( V_16 + V_27 , L_6 , 11 ) == 0 ) {
V_27 += V_28 ;
continue;
}
strncat ( V_22 , V_16 + V_27 , V_28 ) ;
V_27 += V_28 ;
} while ( V_24 );
strcat ( V_22 , V_16 + V_27 ) ;
V_22 [ V_23 ] = '\0' ;
if ( V_22 [ strlen ( V_22 ) - 1 ] != V_26 )
strncat ( V_22 , & V_26 , 1 ) ;
strcat ( V_22 , L_5 ) ;
strcat ( V_22 , V_25 ) ;
strncat ( V_22 , & V_26 , 1 ) ;
strcat ( V_22 , L_4 ) ;
strcat ( V_22 , * V_20 ) ;
V_24 = strchr ( V_19 -> V_8 + 2 , '\\' ) ;
if ( V_24 == NULL ) {
V_21 = - V_15 ;
goto V_29;
}
V_24 = strchr ( V_24 + 1 , '\\' ) ;
if ( V_24 || ( strlen ( V_17 ) - V_19 -> V_30 ) ) {
strncat ( V_22 , & V_26 , 1 ) ;
strcat ( V_22 , L_6 ) ;
if ( V_24 )
strcat ( V_22 , V_24 + 1 ) ;
strcat ( V_22 , V_17 + V_19 -> V_30 ) ;
}
V_31:
F_12 ( V_25 ) ;
return V_22 ;
V_29:
F_12 ( V_22 ) ;
V_22 = F_10 ( V_21 ) ;
F_12 ( * V_20 ) ;
* V_20 = NULL ;
goto V_31;
}
static struct V_32 * F_20 ( struct V_33 * V_34 ,
const char * V_17 , const struct V_18 * V_19 )
{
struct V_32 * V_35 ;
char * V_22 ;
char * V_20 = NULL ;
V_22 = F_13 ( V_34 -> V_22 ,
V_17 + 1 , V_19 , & V_20 ) ;
if ( F_14 ( V_22 ) )
return (struct V_32 * ) V_22 ;
V_35 = F_21 ( & V_36 , 0 , V_20 , V_22 ) ;
F_12 ( V_22 ) ;
F_12 ( V_20 ) ;
return V_35 ;
}
static void F_22 ( const struct V_18 * V_19 )
{
F_17 ( 1 , L_7 , V_19 -> V_37 ) ;
F_17 ( 1 , L_8 , V_19 -> V_8 ) ;
F_17 ( 1 , L_9 , V_19 -> V_38 , V_19 -> V_39 ) ;
F_17 ( 1 , L_10 , V_19 -> V_40 ,
V_19 -> V_30 ) ;
}
static struct V_32 * F_23 ( struct V_41 * V_42 )
{
struct V_18 * V_43 = NULL ;
unsigned int V_44 = 0 ;
struct V_33 * V_34 ;
struct V_45 * V_46 ;
char * V_47 ;
unsigned int V_48 ;
int V_49 ;
int V_21 ;
struct V_32 * V_35 ;
struct V_50 * V_51 ;
F_17 ( 1 , L_11 , V_14 ) ;
F_6 ( F_24 ( V_42 ) ) ;
V_35 = F_10 ( - V_13 ) ;
V_47 = F_25 ( V_42 ) ;
if ( V_47 == NULL )
goto V_52;
V_34 = F_26 ( V_42 -> V_53 -> V_54 ) ;
V_51 = F_27 ( V_34 ) ;
if ( F_14 ( V_51 ) ) {
V_35 = F_28 ( V_51 ) ;
goto V_55;
}
V_46 = F_29 ( V_51 ) -> V_46 ;
V_48 = F_30 () ;
V_21 = F_31 ( V_48 , V_46 , V_47 + 1 , V_34 -> V_56 ,
& V_44 , & V_43 ,
V_34 -> V_57 & V_58 ) ;
F_32 ( V_48 ) ;
F_33 ( V_51 ) ;
V_35 = F_10 ( - V_59 ) ;
for ( V_49 = 0 ; V_49 < V_44 ; V_49 ++ ) {
int V_9 ;
F_22 ( V_43 + V_49 ) ;
V_9 = strlen ( V_43 [ V_49 ] . V_8 ) ;
if ( V_9 < 2 ) {
F_11 ( 1 , L_12 ,
V_14 , V_43 [ V_49 ] . V_8 ) ;
V_35 = F_10 ( - V_15 ) ;
break;
}
V_35 = F_20 ( V_34 ,
V_47 , V_43 + V_49 ) ;
F_17 ( 1 , L_13 , V_14 ,
V_43 [ V_49 ] . V_8 , V_35 ) ;
if ( ! F_14 ( V_35 ) )
goto V_60;
}
if ( V_21 != 0 )
V_35 = F_10 ( V_21 ) ;
V_60:
F_34 ( V_43 , V_44 ) ;
V_55:
F_12 ( V_47 ) ;
V_52:
F_17 ( 1 , L_14 , V_14 ) ;
return V_35 ;
}
struct V_32 * F_35 ( struct V_61 * V_61 )
{
struct V_32 * V_62 ;
F_17 ( 1 , L_11 , V_14 ) ;
V_62 = F_23 ( V_61 -> V_41 ) ;
if ( F_14 ( V_62 ) ) {
F_17 ( 1 , L_15 , V_14 ) ;
return V_62 ;
}
F_36 ( V_62 ) ;
F_37 ( V_62 , & V_5 ) ;
F_4 ( & V_6 ,
V_7 ) ;
F_17 ( 1 , L_16 , V_14 ) ;
return V_62 ;
}
