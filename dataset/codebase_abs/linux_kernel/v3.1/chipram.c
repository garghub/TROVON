void T_1 F_1 ( void )
{
if ( ! F_2 ( V_1 ) )
return;
V_2 . V_3 = V_4 + V_5 - 1 ;
F_3 ( & V_6 , & V_2 ) ;
F_4 ( & V_7 , V_5 ) ;
}
void * F_5 ( unsigned long V_8 , const char * V_9 )
{
struct V_10 * V_11 ;
void * V_12 ;
V_11 = F_6 ( sizeof( struct V_10 ) , V_13 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_9 = V_9 ;
V_12 = F_7 ( V_8 , V_11 ) ;
if ( ! V_12 ) {
F_8 ( V_11 ) ;
return NULL ;
}
return V_12 ;
}
void * F_7 ( unsigned long V_8 , struct V_10 * V_11 )
{
int error ;
V_8 = F_9 ( V_8 ) ;
F_10 ( L_1 , V_8 ) ;
error = F_11 ( & V_2 , V_11 , V_8 , 0 , V_14 ,
V_15 , NULL , NULL ) ;
if ( error < 0 ) {
F_12 ( L_2 ,
error ) ;
return NULL ;
}
F_13 ( V_8 , & V_7 ) ;
F_10 ( L_3 , V_11 ) ;
return ( void * ) F_14 ( V_11 -> V_16 ) ;
}
void F_15 ( void * V_17 )
{
unsigned long V_16 = F_16 ( V_17 ) ;
struct V_10 * V_11 ;
unsigned long V_8 ;
V_11 = F_17 ( & V_2 , V_16 ) ;
if ( ! V_11 ) {
F_12 ( L_4
L_5 , V_17 ) ;
return;
}
V_8 = F_18 ( V_11 ) ;
F_10 ( L_6 , V_8 , V_17 ) ;
F_19 ( V_8 , & V_7 ) ;
F_20 ( V_11 ) ;
F_8 ( V_11 ) ;
}
unsigned long F_21 ( void )
{
unsigned long V_18 = F_22 ( & V_7 ) ;
F_10 ( L_7 , V_18 ) ;
return V_18 ;
}
