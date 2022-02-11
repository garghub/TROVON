static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
int error = - V_10 ;
if ( F_2 ( V_2 ) )
goto V_11;
V_9 = F_3 ( V_2 , 0 ) ;
if ( ! F_4 ( V_9 , V_12 , V_13 ) ) {
F_5 ( V_14 L_1 ,
V_9 , V_9 + V_12 ) ;
goto V_15;
}
V_6 = F_6 ( & V_16 ,
sizeof( struct V_7 ) ) ;
if ( ! V_6 )
goto V_17;
V_8 = F_7 ( V_6 ) ;
V_8 -> V_18 = V_9 ;
V_6 -> V_19 = V_20 ;
error = F_8 ( V_6 , 0 ) ;
if ( error )
goto V_21;
F_9 ( V_6 ) ;
F_10 ( V_2 , V_6 ) ;
error = F_11 ( V_6 , & V_2 -> V_22 ) ;
if ( error )
goto V_23;
F_12 ( V_6 ) ;
return 0 ;
V_23:
F_13 ( V_6 ) ;
V_21:
F_14 ( V_6 ) ;
V_17:
F_15 ( V_9 , V_12 ) ;
V_15:
F_16 ( V_2 ) ;
V_11:
return error ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
unsigned long V_9 = V_8 -> V_18 ;
F_19 ( V_6 ) ;
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
F_15 ( V_9 , V_12 ) ;
F_16 ( V_2 ) ;
}
