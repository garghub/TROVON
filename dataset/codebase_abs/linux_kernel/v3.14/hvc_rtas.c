static inline int F_1 ( T_1 V_1 , const char * V_2 ,
int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( F_2 ( V_5 , 1 , 1 , NULL , V_2 [ V_4 ] ) )
break;
}
return V_4 ;
}
static int F_3 ( T_1 V_1 , char * V_2 , int V_3 )
{
int V_4 , V_6 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( F_2 ( V_7 , 0 , 2 , & V_6 ) )
break;
V_2 [ V_4 ] = V_6 ;
}
return V_4 ;
}
static int T_2 F_4 ( void )
{
struct V_8 * V_9 ;
if ( V_5 == V_10 )
V_5 = F_5 ( L_1 ) ;
if ( V_5 == V_10 )
return - V_11 ;
if ( V_7 == V_10 )
V_7 = F_5 ( L_2 ) ;
if ( V_7 == V_10 )
return - V_11 ;
F_6 ( V_12 ) ;
V_9 = F_7 ( V_13 , 0 , & V_14 , 16 ) ;
if ( F_8 ( V_9 ) )
return F_9 ( V_9 ) ;
V_12 = V_9 ;
return 0 ;
}
static int T_2 F_10 ( void )
{
V_5 = F_5 ( L_1 ) ;
if ( V_5 == V_10 )
return - V_11 ;
V_7 = F_5 ( L_2 ) ;
if ( V_7 == V_10 )
return - V_11 ;
F_11 ( V_13 , 0 , & V_14 ) ;
F_12 ( L_3 , 0 , NULL ) ;
return 0 ;
}
