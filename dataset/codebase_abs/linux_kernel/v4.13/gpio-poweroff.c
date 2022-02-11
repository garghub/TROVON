static void F_1 ( void )
{
F_2 ( ! V_1 ) ;
F_3 ( V_1 , 1 ) ;
F_4 ( 100 ) ;
F_5 ( V_1 , 0 ) ;
F_4 ( 100 ) ;
F_5 ( V_1 , 1 ) ;
F_4 ( 3000 ) ;
F_6 ( 1 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
bool V_4 = false ;
enum V_5 V_6 ;
if ( V_7 != NULL ) {
F_8 ( & V_3 -> V_8 ,
L_1 ,
V_9 ) ;
return - V_10 ;
}
V_4 = F_9 ( V_3 -> V_8 . V_11 , L_2 ) ;
if ( V_4 )
V_6 = V_12 ;
else
V_6 = V_13 ;
V_1 = F_10 ( & V_3 -> V_8 , NULL , V_6 ) ;
if ( F_11 ( V_1 ) )
return F_12 ( V_1 ) ;
V_7 = & F_1 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
if ( V_7 == & F_1 )
V_7 = NULL ;
return 0 ;
}
