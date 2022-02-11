static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
V_3 = 1 ;
}
static void F_3 ( void )
{
F_4 ( V_2 ) ;
F_4 ( V_1 ) ;
V_3 = 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_6 ( & V_5 -> V_6 , L_1 ) ;
F_1 () ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_6 ( & V_5 -> V_6 , L_2 ) ;
F_3 () ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
V_10 -> V_11 = V_8 -> V_12 ;
return F_10 ( V_8 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_13 * V_14 = & V_15 ;
struct V_16 * V_17 ;
int V_18 ;
int V_19 ;
if ( F_12 () )
return - V_20 ;
F_13 ( L_3 ) ;
V_18 = F_14 ( V_5 , 0 ) ;
if ( V_18 <= 0 ) {
F_15 ( & V_5 -> V_6 ,
L_4 ,
F_16 ( & V_5 -> V_6 ) ) ;
V_19 = - V_20 ;
goto V_21;
}
if ( ! V_5 -> V_6 . V_22 )
V_5 -> V_6 . V_22 = & V_23 ;
V_8 = F_17 ( V_14 , & V_5 -> V_6 , F_16 ( & V_5 -> V_6 ) ) ;
if ( ! V_8 ) {
V_19 = - V_24 ;
goto V_21;
}
V_17 = F_18 ( V_5 , V_25 , 0 ) ;
if ( ! V_17 ) {
F_15 ( & V_5 -> V_6 ,
L_5 ,
F_16 ( & V_5 -> V_6 ) ) ;
V_19 = - V_20 ;
goto V_26;
}
V_8 -> V_27 = V_17 -> V_28 ;
V_8 -> V_29 = F_19 ( V_17 ) ;
V_8 -> V_12 = F_20 ( & V_5 -> V_6 , V_17 ) ;
if ( F_21 ( V_8 -> V_12 ) ) {
V_19 = F_22 ( V_8 -> V_12 ) ;
goto V_26;
}
V_1 = F_23 ( & V_5 -> V_6 , L_6 ) ;
if ( F_21 ( V_1 ) ) {
F_15 ( & V_5 -> V_6 , L_7 ) ;
V_19 = - V_30 ;
goto V_26;
}
V_2 = F_23 ( & V_5 -> V_6 , L_8 ) ;
if ( F_21 ( V_2 ) ) {
F_15 ( & V_5 -> V_6 , L_9 ) ;
V_19 = - V_30 ;
goto V_26;
}
F_5 ( V_5 ) ;
V_19 = F_24 ( V_8 , V_18 , V_31 ) ;
if ( V_19 )
goto V_32;
return V_19 ;
V_32:
F_7 ( V_5 ) ;
V_26:
F_25 ( V_8 ) ;
V_21:
F_15 ( & V_5 -> V_6 , L_10 ,
F_16 ( & V_5 -> V_6 ) , V_19 ) ;
return V_19 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_27 ( V_5 ) ;
F_28 ( V_8 ) ;
F_29 ( V_8 ) ;
F_25 ( V_8 ) ;
F_7 ( V_5 ) ;
V_2 = V_1 = NULL ;
return 0 ;
}
