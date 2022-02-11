static int
F_1 ( char * V_1 , char * * V_2 , T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_7 * V_7 = (struct V_7 * ) V_6 ;
if ( V_3 >= V_7 -> V_8 ) {
* V_5 = 1 ;
return 0 ;
}
V_4 = F_2 ( ( int ) ( V_7 -> V_8 - V_3 ) , V_4 ) ;
memcpy ( V_1 , & V_7 -> V_6 [ V_3 ] , V_4 ) ;
return V_4 ;
}
void T_2 F_3 ( const struct V_9 * V_10 )
{
memcpy ( V_11 , V_10 , sizeof( V_11 ) ) ;
}
static int T_2 F_4 ( void )
{
struct V_12 * V_13 ;
struct V_9 * V_9 = (struct V_9 * ) V_11 ;
struct V_7 * V_14 ;
T_3 V_8 ;
if ( V_9 -> V_15 . V_9 != V_16 ) {
F_5 ( V_17 L_1 ) ;
return - V_18 ;
}
for (; V_9 -> V_15 . V_8 ; V_9 = F_6 ( V_9 ) )
;
V_8 = ( char * ) V_9 - V_11 + sizeof( struct V_19 ) ;
F_7 ( V_9 -> V_15 . V_9 != V_20 ) ;
V_14 = F_8 ( sizeof( * V_14 ) + V_8 , V_21 ) ;
if ( ! V_14 )
goto V_22;
V_14 -> V_8 = V_8 ;
memcpy ( V_14 -> V_6 , V_11 , V_8 ) ;
V_13 = F_9 ( L_2 , 0400 ,
NULL , F_1 , V_14 ) ;
if ( ! V_13 )
goto V_22;
return 0 ;
V_22:
F_10 ( V_14 ) ;
F_5 ( V_23 L_3 ) ;
return - V_24 ;
}
