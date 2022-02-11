static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
printf ( L_1 , V_2 -> V_4 ) ;
F_2 (coll, bench)
printf ( L_2 , V_3 -> V_4 , V_3 -> V_5 ) ;
printf ( L_3 ) ;
}
static void F_3 ( void )
{
struct V_1 * V_2 ;
int V_6 ;
printf ( L_4 ) ;
for ( V_6 = 0 ; V_7 [ V_6 ] ; V_6 ++ )
printf ( L_5 , V_7 [ V_6 ] ) ;
printf ( L_3 ) ;
printf ( L_6 ) ;
F_4 (coll)
printf ( L_2 , V_2 -> V_4 , V_2 -> V_5 ) ;
printf ( L_3 ) ;
}
static int F_5 ( const char * V_8 )
{
if ( ! V_8 )
return V_9 ;
if ( ! strcmp ( V_8 , V_10 ) )
return V_9 ;
else if ( ! strcmp ( V_8 , V_11 ) )
return V_12 ;
return V_13 ;
}
static int F_6 ( const char * V_14 , const char * V_15 , T_1 V_16 ,
int V_17 , const char * * V_18 , const char * V_19 )
{
int V_20 ;
char * V_4 ;
int V_21 ;
V_20 = strlen ( V_14 ) + 1 + strlen ( V_15 ) + 1 ;
V_4 = F_7 ( V_20 ) ;
F_8 ( ! V_4 ) ;
F_9 ( V_4 , V_20 , L_7 , V_14 , V_15 ) ;
F_10 ( V_22 , V_4 ) ;
V_18 [ 0 ] = V_4 ;
V_21 = V_16 ( V_17 , V_18 , V_19 ) ;
free ( V_4 ) ;
return V_21 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
const char * V_18 [ 2 ] ;
V_18 [ 1 ] = NULL ;
F_2 (coll, bench) {
if ( ! V_3 -> V_16 )
break;
printf ( L_8 , V_2 -> V_4 , V_3 -> V_4 ) ;
fflush ( stdout ) ;
V_18 [ 1 ] = V_3 -> V_4 ;
F_6 ( V_2 -> V_4 , V_3 -> V_4 , V_3 -> V_16 , 1 , V_18 , NULL ) ;
printf ( L_3 ) ;
}
}
static void F_12 ( void )
{
struct V_1 * V_2 ;
F_4 (coll)
F_11 ( V_2 ) ;
}
int F_13 ( int V_17 , const char * * V_18 , const char * V_19 V_23 )
{
struct V_1 * V_2 ;
int V_21 = 0 ;
if ( V_17 < 2 ) {
F_3 () ;
goto V_24;
}
V_17 = F_14 ( V_17 , V_18 , V_25 , V_7 ,
V_26 ) ;
V_27 = F_5 ( V_28 ) ;
if ( V_27 == V_13 ) {
printf ( L_9 , V_28 ) ;
goto V_24;
}
if ( V_29 == 0 ) {
printf ( L_10 ) ;
goto V_24;
}
if ( V_17 < 1 ) {
F_3 () ;
goto V_24;
}
if ( ! strcmp ( V_18 [ 0 ] , L_11 ) ) {
F_12 () ;
goto V_24;
}
F_4 (coll) {
struct V_3 * V_3 ;
if ( strcmp ( V_2 -> V_4 , V_18 [ 0 ] ) )
continue;
if ( V_17 < 2 ) {
F_1 ( V_2 ) ;
goto V_24;
}
if ( ! strcmp ( V_18 [ 1 ] , L_11 ) ) {
F_11 ( V_2 ) ;
goto V_24;
}
F_2 (coll, bench) {
if ( strcmp ( V_3 -> V_4 , V_18 [ 1 ] ) )
continue;
if ( V_27 == V_9 )
printf ( L_12 , V_2 -> V_4 , V_3 -> V_4 ) ;
fflush ( stdout ) ;
V_21 = F_6 ( V_2 -> V_4 , V_3 -> V_4 , V_3 -> V_16 , V_17 - 1 , V_18 + 1 , V_19 ) ;
goto V_24;
}
if ( ! strcmp ( V_18 [ 1 ] , L_13 ) || ! strcmp ( V_18 [ 1 ] , L_14 ) ) {
F_1 ( V_2 ) ;
goto V_24;
}
printf ( L_15 , V_18 [ 1 ] , V_18 [ 0 ] ) ;
V_21 = 1 ;
goto V_24;
}
printf ( L_16 , V_18 [ 0 ] ) ;
V_21 = 1 ;
V_24:
return V_21 ;
}
