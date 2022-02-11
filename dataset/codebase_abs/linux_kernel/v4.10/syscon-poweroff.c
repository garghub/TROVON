static void F_1 ( void )
{
F_2 ( V_1 , V_2 , V_3 ) ;
F_3 ( 1000 ) ;
F_4 ( L_1 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
char V_6 [ V_7 ] ;
V_1 = F_6 ( V_5 -> V_8 . V_9 , L_2 ) ;
if ( F_7 ( V_1 ) ) {
F_8 ( & V_5 -> V_8 , L_3 ) ;
return F_9 ( V_1 ) ;
}
if ( F_10 ( V_5 -> V_8 . V_9 , L_4 , & V_2 ) ) {
F_8 ( & V_5 -> V_8 , L_5 ) ;
return - V_10 ;
}
if ( F_10 ( V_5 -> V_8 . V_9 , L_6 , & V_3 ) ) {
F_8 ( & V_5 -> V_8 , L_7 ) ;
return - V_10 ;
}
if ( V_11 ) {
F_11 ( ( V_12 ) V_11 , V_6 ) ;
F_8 ( & V_5 -> V_8 ,
L_8 ,
V_11 , V_6 ) ;
return - V_13 ;
}
V_11 = F_1 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
if ( V_11 == F_1 )
V_11 = NULL ;
return 0 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_14 ) ;
}
