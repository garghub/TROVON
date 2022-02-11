static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return - V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return - V_4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( (struct V_5 * ) F_5 ( V_2 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_7 ( V_2 -> V_7 ) ;
F_8 ( V_6 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! F_14 ( V_2 , F_15 ( 64 ) )
&& ! F_16 ( V_2 , F_15 ( 64 ) ) )
return 0 ;
V_8 = F_14 ( V_2 , F_15 ( 32 ) ) ;
if ( ! V_8 )
V_8 = F_16 ( V_2 , F_15 ( 32 ) ) ;
return V_8 ;
}
static int
F_17 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_5 * V_6 ;
void T_2 * V_11 ;
int V_8 ;
V_8 = F_18 ( V_2 ) ;
if ( V_8 ) {
F_19 ( & V_2 -> V_12 , L_1 ) ;
goto V_13;
}
F_20 ( V_2 ) ;
V_8 = F_21 ( V_2 , V_14 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_2 -> V_12 , L_2 ) ;
goto V_15;
}
V_11 = F_22 ( V_2 , 0 ) ;
if ( ! V_11 ) {
F_19 ( & V_2 -> V_12 , L_3 ) ;
V_8 = - V_16 ;
goto V_17;
}
V_8 = F_13 ( V_2 ) ;
if ( V_8 ) {
F_19 ( & V_2 -> V_12 , L_4 ) ;
goto V_18;
}
V_8 = F_23 ( & V_2 -> V_12 , & V_6 , V_11 , V_2 -> V_7 ) ;
if ( V_8 ) {
F_19 ( & V_2 -> V_12 , L_5 ) ;
goto V_18;
}
F_10 ( V_2 , V_6 ) ;
return 0 ;
V_18:
F_24 ( V_11 ) ;
V_17:
F_9 ( V_2 ) ;
V_15:
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_13:
return V_8 ;
}
