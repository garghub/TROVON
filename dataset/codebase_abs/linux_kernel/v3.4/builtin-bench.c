static void F_1 ( int V_1 )
{
int V_2 ;
printf ( L_1 ,
V_3 [ V_1 ] . V_4 ) ;
for ( V_2 = 0 ; V_3 [ V_1 ] . V_5 [ V_2 ] . V_4 ; V_2 ++ )
printf ( L_2 ,
V_3 [ V_1 ] . V_5 [ V_2 ] . V_4 ,
V_3 [ V_1 ] . V_5 [ V_2 ] . V_6 ) ;
printf ( L_3 ) ;
return;
}
static void F_2 ( void )
{
int V_2 ;
printf ( L_4 ) ;
for ( V_2 = 0 ; V_7 [ V_2 ] ; V_2 ++ )
printf ( L_5 , V_7 [ V_2 ] ) ;
printf ( L_3 ) ;
printf ( L_6 ) ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 ; V_2 ++ )
printf ( L_2 ,
V_3 [ V_2 ] . V_4 , V_3 [ V_2 ] . V_6 ) ;
printf ( L_3 ) ;
}
static int F_3 ( const char * V_8 )
{
if ( ! V_8 )
return V_9 ;
if ( ! strcmp ( V_8 , V_10 ) )
return V_9 ;
else if ( ! strcmp ( V_8 , V_11 ) )
return V_12 ;
return V_13 ;
}
static void F_4 ( struct V_14 * V_15 )
{
int V_2 ;
const char * V_16 [ 2 ] ;
struct V_17 * V_5 = V_15 -> V_5 ;
V_16 [ 1 ] = NULL ;
for ( V_2 = 0 ; V_5 [ V_2 ] . V_18 ; V_2 ++ ) {
printf ( L_7 ,
V_15 -> V_4 ,
V_5 [ V_2 ] . V_4 ) ;
V_16 [ 1 ] = V_5 [ V_2 ] . V_4 ;
V_5 [ V_2 ] . V_18 ( 1 , V_16 , NULL ) ;
printf ( L_3 ) ;
}
}
static void F_5 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_5 ; V_2 ++ )
F_4 ( & V_3 [ V_2 ] ) ;
}
int F_6 ( int V_19 , const char * * V_16 , const char * T_1 V_20 )
{
int V_2 , V_21 , V_22 = 0 ;
if ( V_19 < 2 ) {
F_2 () ;
goto V_23;
}
V_19 = F_7 ( V_19 , V_16 , V_24 , V_7 ,
V_25 ) ;
V_26 = F_3 ( V_27 ) ;
if ( V_26 == V_13 ) {
printf ( L_8 , V_27 ) ;
goto V_23;
}
if ( V_19 < 1 ) {
F_2 () ;
goto V_23;
}
if ( ! strcmp ( V_16 [ 0 ] , L_9 ) ) {
F_5 () ;
goto V_23;
}
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 ; V_2 ++ ) {
if ( strcmp ( V_3 [ V_2 ] . V_4 , V_16 [ 0 ] ) )
continue;
if ( V_19 < 2 ) {
F_1 ( V_2 ) ;
goto V_23;
}
if ( ! strcmp ( V_16 [ 1 ] , L_9 ) ) {
F_4 ( & V_3 [ V_2 ] ) ;
goto V_23;
}
for ( V_21 = 0 ; V_3 [ V_2 ] . V_5 [ V_21 ] . V_4 ; V_21 ++ ) {
if ( strcmp ( V_3 [ V_2 ] . V_5 [ V_21 ] . V_4 , V_16 [ 1 ] ) )
continue;
if ( V_26 == V_9 )
printf ( L_7 ,
V_3 [ V_2 ] . V_4 ,
V_3 [ V_2 ] . V_5 [ V_21 ] . V_4 ) ;
V_22 = V_3 [ V_2 ] . V_5 [ V_21 ] . V_18 ( V_19 - 1 ,
V_16 + 1 , T_1 ) ;
goto V_23;
}
if ( ! strcmp ( V_16 [ 1 ] , L_10 ) || ! strcmp ( V_16 [ 1 ] , L_11 ) ) {
F_1 ( V_2 ) ;
goto V_23;
}
printf ( L_12 , V_16 [ 1 ] , V_16 [ 0 ] ) ;
V_22 = 1 ;
goto V_23;
}
printf ( L_13 , V_16 [ 0 ] ) ;
V_22 = 1 ;
V_23:
return V_22 ;
}
