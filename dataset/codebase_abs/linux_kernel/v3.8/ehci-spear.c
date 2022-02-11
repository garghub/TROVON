static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_2 = F_6 ( V_5 ) ;
V_2 -> V_7 = V_5 -> V_8 ;
return F_7 ( V_5 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_9 ( V_10 ) ;
bool V_11 = F_10 ( V_10 ) ;
return F_11 ( V_5 , V_11 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_9 ( V_10 ) ;
F_13 ( V_5 , false ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_3 * V_16 ;
const struct V_17 * V_18 = & V_19 ;
int V_20 , V_21 ;
if ( F_15 () )
return - V_22 ;
V_20 = F_16 ( V_13 , 0 ) ;
if ( V_20 < 0 ) {
V_21 = V_20 ;
goto V_23;
}
if ( ! V_13 -> V_10 . V_24 )
V_13 -> V_10 . V_24 = & V_25 ;
V_16 = F_17 ( & V_13 -> V_10 , NULL ) ;
if ( F_18 ( V_16 ) ) {
F_19 ( & V_13 -> V_10 , L_1 ) ;
V_21 = F_20 ( V_16 ) ;
goto V_23;
}
V_5 = F_21 ( V_18 , & V_13 -> V_10 , F_22 ( & V_13 -> V_10 ) ) ;
if ( ! V_5 ) {
V_21 = - V_26 ;
goto V_23;
}
V_15 = F_23 ( V_13 , V_27 , 0 ) ;
if ( ! V_15 ) {
V_21 = - V_22 ;
goto V_28;
}
V_5 -> V_29 = V_15 -> V_30 ;
V_5 -> V_31 = F_24 ( V_15 ) ;
if ( ! F_25 ( & V_13 -> V_10 , V_5 -> V_29 , V_5 -> V_31 ,
V_18 -> V_32 ) ) {
V_21 = - V_33 ;
goto V_28;
}
V_5 -> V_8 = F_26 ( & V_13 -> V_10 , V_5 -> V_29 , V_5 -> V_31 ) ;
if ( V_5 -> V_8 == NULL ) {
F_27 ( & V_13 -> V_10 , L_2 ) ;
V_21 = - V_26 ;
goto V_28;
}
V_2 = (struct V_1 * ) F_6 ( V_5 ) ;
V_2 -> V_3 = V_16 ;
F_1 ( V_2 ) ;
V_21 = F_28 ( V_5 , V_20 , V_34 ) ;
if ( V_21 )
goto V_35;
return V_21 ;
V_35:
F_3 ( V_2 ) ;
V_28:
F_29 ( V_5 ) ;
V_23:
F_19 ( & V_13 -> V_10 , L_3 , V_21 ) ;
return V_21 ;
}
static int F_30 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_31 ( V_13 ) ;
struct V_1 * V_36 = F_32 ( V_5 ) ;
if ( ! V_5 )
return 0 ;
if ( F_33 () )
F_34 () ;
F_35 ( V_5 ) ;
if ( V_36 -> V_3 )
F_3 ( V_36 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
