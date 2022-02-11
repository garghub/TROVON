static void F_1 ( const char * V_1 , T_1 * V_2 )
{
T_2 V_3 ;
for ( V_3 = 0 ; V_3 < strlen ( V_1 ) ; V_3 ++ )
V_2 [ V_3 ] = V_1 [ V_3 ] ;
V_2 [ V_3 ] = '\0' ;
}
static int F_2 ( const char * V_4 , const char * V_5 )
{
int V_6 ;
T_3 V_7 = V_8 ;
struct V_9 * V_10 ;
T_2 V_11 = ( strlen ( V_5 ) + 1 ) * sizeof( T_1 ) ;
if ( V_11 > sizeof( V_10 -> V_12 . V_13 ) ) {
F_3 ( L_1 ) ;
return - V_14 ;
}
V_10 = F_4 ( sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 ) {
F_3 ( L_2 ) ;
return - V_16 ;
}
F_1 ( V_4 , V_10 -> V_12 . V_17 ) ;
F_1 ( V_5 , ( T_1 * ) V_10 -> V_12 . V_13 ) ;
memcpy ( & V_10 -> V_12 . V_18 , & V_7 , sizeof( V_7 ) ) ;
V_6 = F_5 ( V_10 ,
V_19
| V_20
| V_21 ,
V_11 , V_10 -> V_12 . V_13 , NULL ) ;
if ( V_6 )
F_3 ( L_3 ,
V_4 , V_6 ) ;
F_6 ( V_10 ) ;
return V_6 ;
}
static int F_7 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
const char * V_26 = L_4 ;
int V_6 ;
if ( V_24 == V_27 )
V_26 = L_5 ;
V_6 = F_2 ( L_6 , V_26 ) ;
if ( V_6 || ! V_25 )
return V_28 ;
F_2 ( L_7 , ( char * ) V_25 ) ;
return V_28 ;
}
static int T_4 F_8 ( void )
{
int V_6 ;
if ( ! F_9 ( V_29 ) )
return - V_30 ;
V_6 = F_10 ( & V_31 ) ;
if ( V_6 )
F_3 ( L_8 ) ;
return V_6 ;
}
static void T_5 F_11 ( void )
{
F_12 ( & V_31 ) ;
}
