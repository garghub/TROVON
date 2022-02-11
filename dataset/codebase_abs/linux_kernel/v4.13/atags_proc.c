static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_6 -> V_7 , V_6 -> V_8 ) ;
}
void T_5 F_5 ( const struct V_9 * V_10 )
{
memcpy ( V_11 , V_10 , sizeof( V_11 ) ) ;
}
static int T_5 F_6 ( void )
{
struct V_12 * V_13 ;
struct V_9 * V_9 = (struct V_9 * ) V_11 ;
struct V_5 * V_6 ;
T_3 V_8 ;
if ( V_9 -> V_14 . V_9 != V_15 ) {
F_7 ( L_1 ) ;
return - V_16 ;
}
for (; V_9 -> V_14 . V_8 ; V_9 = F_8 ( V_9 ) )
;
V_8 = ( char * ) V_9 - V_11 + sizeof( struct V_17 ) ;
F_9 ( V_9 -> V_14 . V_9 != V_18 ) ;
V_6 = F_10 ( sizeof( * V_6 ) + V_8 , V_19 ) ;
if ( ! V_6 )
goto V_20;
V_6 -> V_8 = V_8 ;
memcpy ( V_6 -> V_7 , V_11 , V_8 ) ;
V_13 = F_11 ( L_2 , 0400 , NULL , & V_21 , V_6 ) ;
if ( ! V_13 )
goto V_20;
return 0 ;
V_20:
F_12 ( V_6 ) ;
F_13 ( L_3 ) ;
return - V_22 ;
}
