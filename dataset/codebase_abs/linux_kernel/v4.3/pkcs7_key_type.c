static int F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 = V_5 ;
struct V_6 * V_7 ;
const void * V_8 , * V_9 ;
T_1 V_10 , V_11 ;
bool V_12 ;
int V_13 ;
F_2 ( L_1 ) ;
if ( V_4 >= V_14 ) {
F_3 ( L_2 , V_4 ) ;
return - V_15 ;
}
V_9 = V_2 -> V_8 ;
V_11 = V_2 -> V_10 ;
V_7 = F_4 ( V_9 , V_11 ) ;
if ( F_5 ( V_7 ) ) {
V_13 = F_6 ( V_7 ) ;
goto error;
}
V_13 = F_7 ( V_7 , V_4 ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_8 ( V_7 , V_17 , & V_12 ) ;
if ( V_13 < 0 )
goto V_16;
if ( ! V_12 )
F_9 ( L_3 ) ;
V_13 = F_10 ( V_7 , & V_8 , & V_10 , false ) ;
if ( V_13 < 0 )
goto V_16;
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = V_10 ;
V_13 = F_11 ( V_2 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
V_16:
F_12 ( V_7 ) ;
error:
F_13 ( L_4 , V_13 ) ;
return V_13 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_18 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_18 ) ;
}
