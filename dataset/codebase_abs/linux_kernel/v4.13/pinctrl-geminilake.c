static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
if ( ! V_6 )
return - V_9 ;
for ( V_7 = 0 ; V_10 [ V_7 ] ; V_7 ++ ) {
if ( ! strcmp ( V_6 -> V_11 . V_12 ,
V_10 [ V_7 ] -> V_13 ) ) {
V_4 = V_10 [ V_7 ] ;
break;
}
}
if ( ! V_4 )
return - V_9 ;
return F_3 ( V_2 , V_4 ) ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_14 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_14 ) ;
}
