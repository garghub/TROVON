static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = NULL ;
const struct V_3 * * V_5 ;
const struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( & V_2 -> V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_7 = F_3 ( V_13 , & V_2 -> V_11 ) ;
if ( ! V_7 )
return - V_12 ;
V_5 = ( const struct V_3 * * ) V_7 -> V_14 ;
for ( V_10 = 0 ; V_5 [ V_10 ] ; V_10 ++ ) {
if ( ! strcmp ( V_9 -> V_15 . V_16 , V_5 [ V_10 ] -> V_17 ) ) {
V_4 = V_5 [ V_10 ] ;
break;
}
}
if ( ! V_4 )
return - V_12 ;
return F_4 ( V_2 , V_4 ) ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_18 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_18 ) ;
}
