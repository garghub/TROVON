static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = NULL ;
const struct V_3 * * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( & V_2 -> V_9 ) ;
if ( V_7 ) {
const struct V_10 * V_11 ;
V_11 = F_3 ( V_12 , & V_2 -> V_9 ) ;
if ( ! V_11 )
return - V_13 ;
V_5 = ( const struct V_3 * * )
V_11 -> V_14 ;
for ( V_8 = 0 ; V_5 [ V_8 ] ; V_8 ++ ) {
if ( ! strcmp ( V_7 -> V_15 . V_16 , V_5 [ V_8 ] -> V_17 ) ) {
V_4 = V_5 [ V_8 ] ;
break;
}
}
} else {
const struct V_18 * V_19 ;
V_19 = F_4 ( V_2 ) ;
if ( ! V_19 )
return - V_13 ;
V_5 = ( const struct V_3 * * )
V_19 -> V_14 ;
V_4 = V_5 [ V_2 -> V_11 ] ;
}
if ( ! V_4 )
return - V_13 ;
return F_5 ( V_2 , V_4 ) ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_20 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_20 ) ;
}
