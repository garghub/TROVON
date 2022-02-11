static int T_1 F_1 ( char * V_1 )
{
if ( ! V_2 )
return 0 ;
V_3 = F_2 ( V_1 , NULL ) ;
return 0 ;
}
void T_1 F_3 ( void )
{
int V_4 ;
void * V_5 ;
V_5 = F_4 ( 0 ) ;
V_6 = ( V_5 == 0 ) ;
for ( V_4 = 0 ; V_4 < V_7 ; ++ V_4 ) {
if ( V_8 [ V_4 ] . V_9 == 0 ) {
return;
}
}
F_5 ( L_1 ) ;
}
void T_1 F_6 ( void * V_10 )
{
if ( ! V_6 )
F_7 ( 0 , V_11 , V_12 ) ;
V_13 . V_14 = ( V_15 ) F_8 ( V_3 ) ;
V_13 . V_16 = V_13 . V_14 + V_3 - 1 ;
F_9 ( & V_17 , & V_13 ) ;
F_10 ( L_2 ,
V_3 , & V_13 ) ;
}
void * F_11 ( unsigned long V_18 , const char * V_19 )
{
struct V_20 * V_21 ;
int error ;
F_10 ( L_3 , V_18 ) ;
V_18 = F_12 ( V_18 ) ;
V_21 = F_13 ( sizeof( struct V_20 ) , V_22 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_23 = V_19 ;
error = F_14 ( & V_13 , V_21 , V_18 , 0 , V_24 ,
V_11 , NULL , NULL ) ;
if ( error < 0 ) {
F_15 ( L_4 ,
error ) ;
F_16 ( V_21 ) ;
return NULL ;
}
F_10 ( L_5 , V_21 ) ;
return ( void * ) V_21 -> V_14 ;
}
void F_17 ( void * V_9 )
{
unsigned long V_14 = ( unsigned long ) V_9 ;
struct V_20 * V_21 ;
unsigned long V_18 ;
V_21 = F_18 ( & V_13 , V_14 ) ;
if ( ! V_21 ) {
F_15 ( L_6
L_7 , V_9 ) ;
return;
}
V_18 = F_19 ( V_21 ) ;
F_10 ( L_8 , V_18 , V_9 ) ;
F_20 ( V_21 ) ;
F_16 ( V_21 ) ;
}
