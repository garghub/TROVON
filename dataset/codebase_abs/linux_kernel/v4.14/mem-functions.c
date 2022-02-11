static int F_1 ( void )
{
V_1 = F_2 ( & V_2 , F_3 () , - 1 , - 1 , F_4 () ) ;
if ( V_1 < 0 && V_3 == V_4 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static T_1 F_6 ( void )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_1 , & V_6 , sizeof( T_1 ) ) ;
F_8 ( V_5 != sizeof( T_1 ) ) ;
return V_6 ;
}
static double F_9 ( struct V_7 * V_8 )
{
return ( double ) V_8 -> V_9 + ( double ) V_8 -> V_10 / ( double ) V_11 ;
}
static void F_10 ( struct V_12 * V_13 , int V_14 , T_2 V_15 , double V_16 )
{
const struct V_17 * V_18 = & V_13 -> V_19 [ V_14 ] ;
double V_20 = 0.0 ;
T_1 V_21 = 0 ;
void * V_22 = NULL , * V_23 = F_11 ( V_15 ) ;
printf ( L_2 , V_18 -> V_24 , V_18 -> V_25 ) ;
if ( V_23 == NULL )
goto V_26;
if ( V_13 -> V_27 ) {
V_22 = F_11 ( V_15 ) ;
if ( V_22 == NULL )
goto V_26;
}
if ( V_28 == V_29 )
printf ( L_3 , V_30 ) ;
if ( V_31 ) {
V_21 = V_13 -> V_32 ( V_18 , V_15 , V_22 , V_23 ) ;
} else {
V_20 = V_13 -> V_33 ( V_18 , V_15 , V_22 , V_23 ) ;
}
switch ( V_28 ) {
case V_29 :
if ( V_31 ) {
printf ( L_4 , ( double ) V_21 / V_16 ) ;
} else {
F_12 ( V_20 ) ;
}
break;
case V_34 :
if ( V_31 ) {
printf ( L_5 , ( double ) V_21 / V_16 ) ;
} else {
printf ( L_5 , V_20 ) ;
}
break;
default:
F_8 ( 1 ) ;
break;
}
V_35:
free ( V_22 ) ;
free ( V_23 ) ;
return;
V_26:
printf ( L_6 , V_30 ) ;
goto V_35;
}
static int F_13 ( int V_36 , const char * * V_37 , struct V_12 * V_13 )
{
int V_38 ;
T_2 V_15 ;
double V_16 ;
V_36 = F_14 ( V_36 , V_37 , V_39 , V_13 -> V_40 , 0 ) ;
if ( V_31 ) {
V_38 = F_1 () ;
if ( V_38 < 0 ) {
fprintf ( V_41 , L_7 ) ;
return V_38 ;
}
}
V_15 = ( T_2 ) F_15 ( ( char * ) V_30 ) ;
V_16 = ( double ) V_15 * V_42 ;
if ( ( V_43 ) V_15 <= 0 ) {
fprintf ( V_41 , L_8 , V_30 ) ;
return 1 ;
}
if ( ! strncmp ( V_44 , L_9 , 3 ) ) {
for ( V_38 = 0 ; V_13 -> V_19 [ V_38 ] . V_24 ; V_38 ++ )
F_10 ( V_13 , V_38 , V_15 , V_16 ) ;
return 0 ;
}
for ( V_38 = 0 ; V_13 -> V_19 [ V_38 ] . V_24 ; V_38 ++ ) {
if ( ! strcmp ( V_13 -> V_19 [ V_38 ] . V_24 , V_44 ) )
break;
}
if ( ! V_13 -> V_19 [ V_38 ] . V_24 ) {
if ( strcmp ( V_44 , L_10 ) && strcmp ( V_44 , L_11 ) )
printf ( L_12 , V_44 ) ;
printf ( L_13 ) ;
for ( V_38 = 0 ; V_13 -> V_19 [ V_38 ] . V_24 ; V_38 ++ ) {
printf ( L_14 ,
V_13 -> V_19 [ V_38 ] . V_24 , V_13 -> V_19 [ V_38 ] . V_25 ) ;
}
return 1 ;
}
F_10 ( V_13 , V_38 , V_15 , V_16 ) ;
return 0 ;
}
static T_1 F_16 ( const struct V_17 * V_18 , T_2 V_15 , void * V_22 , void * V_23 )
{
T_1 V_45 = 0ULL , V_46 = 0ULL ;
T_3 V_47 = V_18 -> V_47 . memcpy ;
int V_38 ;
memset ( V_22 , 0 , V_15 ) ;
V_47 ( V_23 , V_22 , V_15 ) ;
V_45 = F_6 () ;
for ( V_38 = 0 ; V_38 < V_42 ; ++ V_38 )
V_47 ( V_23 , V_22 , V_15 ) ;
V_46 = F_6 () ;
return V_46 - V_45 ;
}
static double F_17 ( const struct V_17 * V_18 , T_2 V_15 , void * V_22 , void * V_23 )
{
struct V_7 V_48 , V_49 , V_50 ;
T_3 V_47 = V_18 -> V_47 . memcpy ;
int V_38 ;
V_47 ( V_23 , V_22 , V_15 ) ;
F_8 ( F_18 ( & V_48 , NULL ) ) ;
for ( V_38 = 0 ; V_38 < V_42 ; ++ V_38 )
V_47 ( V_23 , V_22 , V_15 ) ;
F_8 ( F_18 ( & V_49 , NULL ) ) ;
F_19 ( & V_49 , & V_48 , & V_50 ) ;
return ( double ) ( ( ( double ) V_15 * V_42 ) / F_9 ( & V_50 ) ) ;
}
int F_20 ( int V_36 , const char * * V_37 )
{
struct V_12 V_13 = {
. V_19 = V_51 ,
. V_32 = F_16 ,
. V_33 = F_17 ,
. V_40 = V_52 ,
. V_27 = true ,
} ;
return F_13 ( V_36 , V_37 , & V_13 ) ;
}
static T_1 F_21 ( const struct V_17 * V_18 , T_2 V_15 , void * V_22 V_53 , void * V_23 )
{
T_1 V_45 = 0ULL , V_46 = 0ULL ;
T_4 V_47 = V_18 -> V_47 . memset ;
int V_38 ;
V_47 ( V_23 , - 1 , V_15 ) ;
V_45 = F_6 () ;
for ( V_38 = 0 ; V_38 < V_42 ; ++ V_38 )
V_47 ( V_23 , V_38 , V_15 ) ;
V_46 = F_6 () ;
return V_46 - V_45 ;
}
static double F_22 ( const struct V_17 * V_18 , T_2 V_15 , void * V_22 V_53 , void * V_23 )
{
struct V_7 V_48 , V_49 , V_50 ;
T_4 V_47 = V_18 -> V_47 . memset ;
int V_38 ;
V_47 ( V_23 , - 1 , V_15 ) ;
F_8 ( F_18 ( & V_48 , NULL ) ) ;
for ( V_38 = 0 ; V_38 < V_42 ; ++ V_38 )
V_47 ( V_23 , V_38 , V_15 ) ;
F_8 ( F_18 ( & V_49 , NULL ) ) ;
F_19 ( & V_49 , & V_48 , & V_50 ) ;
return ( double ) ( ( ( double ) V_15 * V_42 ) / F_9 ( & V_50 ) ) ;
}
int F_23 ( int V_36 , const char * * V_37 )
{
struct V_12 V_13 = {
. V_19 = V_54 ,
. V_32 = F_21 ,
. V_33 = F_22 ,
. V_40 = V_55 ,
} ;
return F_13 ( V_36 , V_37 , & V_13 ) ;
}
