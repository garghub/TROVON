static int T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 ( L_1 ) ;
const struct V_3 * V_4 ;
if ( ! V_2 )
return - V_5 ;
V_4 = F_3 ( V_6 , V_2 ) ;
F_4 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
return F_5 ( F_6 ( NULL , L_2 ,
- 1 , V_4 -> V_7 ,
sizeof( struct V_8 ) ) ) ;
}
