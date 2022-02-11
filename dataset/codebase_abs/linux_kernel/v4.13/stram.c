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
V_5 = ( V_6 [ 0 ] . V_7 == 0 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; ++ V_4 ) {
if ( V_6 [ V_4 ] . V_7 == 0 ) {
return;
}
}
F_4 ( L_1 ) ;
}
void T_1 F_5 ( void * V_9 )
{
if ( V_5 ) {
F_6 ( L_2 ) ;
V_10 . V_11 = ( V_12 ) F_7 ( V_3 ) ;
V_10 . V_13 = V_10 . V_11 + V_3 - 1 ;
F_8 ( & V_14 , & V_10 ) ;
V_15 = 0 ;
F_6 ( L_3 ,
V_3 , & V_10 ) ;
F_6 ( L_4 ,
V_15 ) ;
}
}
int T_1 F_9 ( void )
{
if ( ! V_5 ) {
F_6 ( L_5 ) ;
V_10 . V_11 = V_16 ;
V_10 . V_13 = V_10 . V_11 + V_3 - 1 ;
F_8 ( & V_14 , & V_10 ) ;
V_15 = ( unsigned long ) F_10 ( V_10 . V_11 ,
F_11 ( & V_10 ) ) - V_10 . V_11 ;
F_6 ( L_3 ,
V_3 , & V_10 ) ;
F_6 ( L_4 ,
V_15 ) ;
}
return 0 ;
}
void * F_12 ( unsigned long V_17 )
{
return ( void * ) ( V_17 + V_15 ) ;
}
unsigned long F_13 ( void * V_18 )
{
return ( unsigned long ) ( V_18 - V_15 ) ;
}
void * F_14 ( unsigned long V_19 , const char * V_20 )
{
struct V_21 * V_22 ;
int error ;
F_6 ( L_6 , V_19 ) ;
V_19 = F_15 ( V_19 ) ;
V_22 = F_16 ( sizeof( struct V_21 ) , V_23 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_24 = V_20 ;
error = F_17 ( & V_10 , V_22 , V_19 , 0 , V_25 ,
V_16 , NULL , NULL ) ;
if ( error < 0 ) {
F_18 ( L_7 ,
error ) ;
F_19 ( V_22 ) ;
return NULL ;
}
F_6 ( L_8 , V_22 ) ;
return F_12 ( V_22 -> V_11 ) ;
}
void F_20 ( void * V_7 )
{
unsigned long V_11 = F_13 ( V_7 ) ;
struct V_21 * V_22 ;
unsigned long V_19 ;
V_22 = F_21 ( & V_10 , V_11 ) ;
if ( ! V_22 ) {
F_18 ( L_9
L_10 , V_7 ) ;
return;
}
V_19 = F_11 ( V_22 ) ;
F_6 ( L_11 , V_19 , V_7 ) ;
F_22 ( V_22 ) ;
F_19 ( V_22 ) ;
}
