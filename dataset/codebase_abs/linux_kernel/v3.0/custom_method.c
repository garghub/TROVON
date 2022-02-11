static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
static char * V_5 ;
static T_5 V_6 ;
static T_5 V_7 ;
struct V_8 V_9 ;
T_6 V_10 ;
if ( ! ( * V_4 ) ) {
if ( V_3 <= sizeof( struct V_8 ) )
return - V_11 ;
if ( F_2 ( & V_9 , V_2 ,
sizeof( struct V_8 ) ) )
return - V_12 ;
V_7 = V_6 = V_9 . V_13 ;
V_5 = F_3 ( V_6 , V_14 ) ;
if ( ! V_5 )
return - V_15 ;
}
if ( V_5 == NULL )
return - V_11 ;
if ( ( * V_4 > V_6 ) ||
( * V_4 + V_3 > V_6 ) ||
( * V_4 + V_3 < V_3 ) ||
( V_3 > V_7 ) )
return - V_11 ;
if ( F_2 ( V_5 + ( * V_4 ) , V_2 , V_3 ) ) {
F_4 ( V_5 ) ;
V_5 = NULL ;
return - V_12 ;
}
V_7 -= V_3 ;
* V_4 += V_3 ;
if ( ! V_7 ) {
V_10 = F_5 ( V_5 ) ;
F_4 ( V_5 ) ;
V_5 = NULL ;
if ( F_6 ( V_10 ) )
return - V_11 ;
F_7 ( V_16 ) ;
}
return V_3 ;
}
static int T_7 F_8 ( void )
{
if ( V_17 == NULL )
return - V_18 ;
V_19 = F_9 ( L_1 , V_20 ,
V_17 , NULL , & V_21 ) ;
if ( V_19 == NULL )
return - V_22 ;
return 0 ;
}
static void T_8 F_10 ( void )
{
if ( V_19 )
F_11 ( V_19 ) ;
}
