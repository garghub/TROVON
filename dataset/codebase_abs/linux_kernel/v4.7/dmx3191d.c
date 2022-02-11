static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
int error = - V_8 ;
if ( F_2 ( V_2 ) )
goto V_9;
V_7 = F_3 ( V_2 , 0 ) ;
if ( ! F_4 ( V_7 , V_10 , V_11 ) ) {
F_5 ( V_12 L_1 ,
V_7 , V_7 + V_10 ) ;
goto V_13;
}
V_6 = F_6 ( & V_14 ,
sizeof( struct V_15 ) ) ;
if ( ! V_6 )
goto V_16;
V_6 -> V_17 = V_7 ;
V_6 -> V_18 = V_19 ;
error = F_7 ( V_6 , 0 ) ;
if ( error )
goto V_20;
F_8 ( V_6 ) ;
F_9 ( V_2 , V_6 ) ;
error = F_10 ( V_6 , & V_2 -> V_21 ) ;
if ( error )
goto V_22;
F_11 ( V_6 ) ;
return 0 ;
V_22:
F_12 ( V_6 ) ;
V_20:
F_13 ( V_6 ) ;
V_16:
F_14 ( V_7 , V_10 ) ;
V_13:
F_15 ( V_2 ) ;
V_9:
return error ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
unsigned long V_7 = V_6 -> V_17 ;
F_18 ( V_6 ) ;
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
F_14 ( V_7 , V_10 ) ;
F_15 ( V_2 ) ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_23 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_23 ) ;
}
