static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 , 0 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
if ( ! F_4 ( V_4 -> V_8 , F_5 ( V_4 ) , V_9 ) ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 , 0 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
F_7 ( V_4 -> V_8 , F_5 ( V_4 ) ) ;
return 0 ;
}
static void T_1 F_8 ( void )
{
const char * V_10 [] = { L_3 , L_4 } ;
if ( ! F_9 () )
return;
F_10 ( L_5 , V_10 , F_11 ( V_10 ) ) ;
}
static void F_8 ( void ) { }
static int T_1 F_12 ( struct V_11 * V_2 ,
const struct V_12 * V_13 )
{
int V_14 , V_15 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
return V_14 ;
for ( V_15 = 0 ; V_15 < F_11 ( V_16 ) ; V_15 ++ ) {
int V_17 = V_16 [ V_15 ] . V_13 ;
struct V_3 * V_18 = & V_19 [ V_17 ] ;
V_18 -> V_20 = V_5 ;
V_18 -> V_8 = F_14 ( V_2 , V_17 ) ;
V_18 -> V_21 = F_15 ( V_2 , V_17 ) ;
V_16 [ V_15 ] . V_13 = 0 ;
}
V_14 = F_16 ( & V_2 -> V_6 , - 1 , V_16 ,
F_11 ( V_16 ) , NULL , 0 , NULL ) ;
if ( V_14 ) {
F_3 ( & V_2 -> V_6 , L_6 , V_14 ) ;
goto V_22;
}
F_8 () ;
F_17 ( & V_2 -> V_6 , L_7 ,
F_11 ( V_16 ) ) ;
return 0 ;
V_22:
F_18 ( V_2 ) ;
return V_14 ;
}
static void T_2 F_19 ( struct V_11 * V_2 )
{
F_20 ( & V_2 -> V_6 ) ;
F_18 ( V_2 ) ;
}
