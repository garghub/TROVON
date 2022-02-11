static struct V_1 * T_1
F_1 ( char * V_2 , void (* F_2)( struct V_1 * ,
struct V_3 * ) )
{
struct V_1 * V_4 ;
V_4 = F_3 ( V_5 , V_2 , V_6 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 . V_10 . F_2 = F_2 ;
if ( F_4 ( V_4 ) < 0 ) {
F_5 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
static void F_6 ( void )
{
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
}
int T_1 F_7 ( void )
{
V_11 = F_1 ( L_1 ,
V_14 ) ;
V_12 = F_1 ( L_2 ,
V_15 ) ;
V_13 = F_1 ( L_3 , V_16 ) ;
if ( ! V_11 || ! V_12 || ! V_13 )
goto error;
return 0 ;
error:
F_6 () ;
return - V_17 ;
}
int T_2 F_8 ( void )
{
F_6 () ;
return 0 ;
}
