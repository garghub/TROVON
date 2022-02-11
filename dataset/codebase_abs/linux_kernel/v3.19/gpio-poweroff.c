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
if ( V_5 != NULL ) {
F_8 ( & V_3 -> V_6 ,
L_1 ,
V_7 ) ;
return - V_8 ;
}
V_1 = F_9 ( & V_3 -> V_6 , NULL ) ;
if ( F_10 ( V_1 ) )
return F_11 ( V_1 ) ;
V_4 = F_12 ( V_3 -> V_6 . V_9 , L_2 ) ;
if ( V_4 ) {
if ( F_13 ( V_1 ) ) {
F_8 ( & V_3 -> V_6 ,
L_3 ) ;
return - V_10 ;
}
} else {
if ( F_3 ( V_1 , 0 ) ) {
F_8 ( & V_3 -> V_6 ,
L_4 ) ;
return - V_10 ;
}
}
V_5 = & F_1 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
if ( V_5 == & F_1 )
V_5 = NULL ;
return 0 ;
}
