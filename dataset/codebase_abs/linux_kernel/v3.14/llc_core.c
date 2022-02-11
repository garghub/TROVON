static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
int V_4 ;
if ( V_2 ) {
V_2 -> V_5 = V_6 ;
F_3 ( & V_2 -> V_7 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ )
F_4 ( & V_2 -> V_9 [ V_4 ] , V_4 ) ;
F_5 ( & V_2 -> V_10 , 1 ) ;
}
return V_2 ;
}
static struct V_1 * F_6 ( unsigned char V_11 )
{
struct V_1 * V_2 ;
F_7 (sap, &llc_sap_list, node)
if ( V_2 -> V_12 . V_13 == V_11 )
goto V_14;
V_2 = NULL ;
V_14:
return V_2 ;
}
struct V_1 * F_8 ( unsigned char V_11 )
{
struct V_1 * V_2 ;
F_9 () ;
V_2 = F_6 ( V_11 ) ;
if ( V_2 )
F_10 ( V_2 ) ;
F_11 () ;
return V_2 ;
}
struct V_1 * F_12 ( unsigned char V_13 ,
int (* F_13)( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_17 * V_21 ) )
{
struct V_1 * V_2 = NULL ;
F_14 ( & V_22 ) ;
if ( F_6 ( V_13 ) )
goto V_14;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_14;
V_2 -> V_12 . V_13 = V_13 ;
V_2 -> V_23 = F_13 ;
F_15 ( & V_2 -> V_24 , & V_25 ) ;
V_14:
F_16 ( & V_22 ) ;
return V_2 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_26 ) ;
F_14 ( & V_22 ) ;
F_19 ( & V_2 -> V_24 ) ;
F_16 ( & V_22 ) ;
F_20 () ;
F_21 ( V_2 ) ;
}
static int T_1 F_22 ( void )
{
F_23 ( & V_27 ) ;
F_23 ( & V_28 ) ;
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_27 ) ;
F_25 ( & V_28 ) ;
}
