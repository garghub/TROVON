static bool T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 ( 0 ) ;
bool V_3 = false ;
if ( F_3 ( V_2 , L_1 , NULL ) )
V_3 = true ;
F_4 ( V_2 ) ;
return V_3 ;
}
static int T_1 F_5 ( void )
{
struct V_1 * V_2 = F_6 ( L_2 ) ;
const struct V_4 * V_5 ;
const void * V_6 = NULL ;
if ( ! V_2 )
return - V_7 ;
V_5 = F_7 ( V_8 , V_2 ) ;
if ( V_5 ) {
V_6 = V_5 -> V_6 ;
goto V_9;
}
if ( F_1 () && ! F_7 ( V_10 , V_2 ) )
goto V_9;
F_4 ( V_2 ) ;
return - V_7 ;
V_9:
F_4 ( V_2 ) ;
return F_8 ( F_9 ( NULL , L_3 ,
- 1 , V_6 ,
sizeof( struct V_11 ) ) ) ;
}
