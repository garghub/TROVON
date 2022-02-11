int F_1 ( struct V_1 * V_1 , unsigned long V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_6 = V_7 [ V_1 -> V_8 ] . V_6 ;
struct V_9 * V_10 = NULL ;
if ( ! V_11 )
return - V_12 ;
if ( ! V_6 )
return - V_13 ;
for ( V_3 = 0 ; V_3 < V_7 [ V_1 -> V_8 ] . V_14 ; V_3 ++ ) {
if ( V_6 [ V_3 ] . V_15 == V_2 / 1000 ) {
V_10 = V_6 [ V_3 ] . V_16 ;
break;
}
}
if ( ! V_10 )
return - V_13 ;
F_2 ( & V_17 ) ;
for ( V_3 = 0 ; V_10 [ V_3 ] . V_18 ; V_3 ++ ) {
V_4 = F_3 ( V_11 ,
V_10 [ V_3 ] . V_18 | 0x80 , V_10 [ V_3 ] . V_19 ) ;
if ( V_4 )
break;
}
F_4 ( & V_17 ) ;
if ( ! V_4 )
V_1 -> V_2 = V_2 ;
return V_4 ;
}
static int F_5 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
V_11 = V_21 ;
return 0 ;
}
static int T_1 F_6 ( struct V_20 * V_21 )
{
V_11 = NULL ;
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_24 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_24 ) ;
}
