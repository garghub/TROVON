static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const void * V_5 , * V_6 ;
T_1 V_7 , V_8 ;
bool V_9 ;
int V_10 ;
F_2 ( L_1 ) ;
V_6 = V_2 -> V_5 ;
V_8 = V_2 -> V_7 ;
V_4 = F_3 ( V_6 , V_8 ) ;
if ( F_4 ( V_4 ) ) {
V_10 = F_5 ( V_4 ) ;
goto error;
}
V_10 = F_6 ( V_4 ) ;
if ( V_10 < 0 )
goto V_11;
V_10 = F_7 ( V_4 , V_12 , & V_9 ) ;
if ( V_10 < 0 )
goto V_11;
if ( ! V_9 )
F_8 ( L_2 ) ;
V_10 = F_9 ( V_4 , & V_5 , & V_7 , false ) ;
if ( V_10 < 0 )
goto V_11;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_10 = F_10 ( V_2 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_11:
F_11 ( V_4 ) ;
error:
F_12 ( L_3 , V_10 ) ;
return V_10 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_13 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_13 ) ;
}
