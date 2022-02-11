static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 = V_5 ;
if ( F_2 () > 1 || V_2 -> V_7 != 0 )
V_6 = V_4 -> V_8 ;
if ( V_6 == 0 )
return F_3 ( V_2 , V_4 , V_6 ) ;
F_4 () ;
return V_6 ;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_11 ;
F_4 = ( void * ) ( V_10 -> V_2 . V_12 ) ;
V_11 = F_6 ( & V_13 , NULL ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_2 , L_1 ) ;
return V_11 ;
}
return 0 ;
}
