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
int V_7 = 0 ;
V_2 -> V_8 = V_5 -> V_9 ;
V_7 = F_7 ( V_5 ) ;
if ( V_7 )
return V_7 ;
F_8 ( V_2 , 0 ) ;
return V_7 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_10 ( V_11 ) ;
bool V_12 = F_11 ( V_11 ) ;
return F_12 ( V_5 , V_12 ) ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_10 ( V_11 ) ;
F_14 ( V_5 , false ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_3 * V_17 ;
const struct V_18 * V_19 = & V_20 ;
int V_21 , V_7 ;
char V_22 [ 20 ] = L_1 ;
static int V_23 = - 1 ;
if ( F_16 () )
return - V_24 ;
V_21 = F_17 ( V_14 , 0 ) ;
if ( V_21 < 0 ) {
V_7 = V_21 ;
goto V_25;
}
if ( ! V_14 -> V_11 . V_26 )
V_14 -> V_11 . V_26 = & V_27 ;
if ( V_14 -> V_28 < 0 )
V_23 ++ ;
else
V_23 = V_14 -> V_28 ;
sprintf ( V_22 , L_2 , V_23 ) ;
V_17 = F_18 ( NULL , V_22 ) ;
if ( F_19 ( V_17 ) ) {
F_20 ( & V_14 -> V_11 , L_3 ) ;
V_7 = F_21 ( V_17 ) ;
goto V_29;
}
V_5 = F_22 ( V_19 , & V_14 -> V_11 , F_23 ( & V_14 -> V_11 ) ) ;
if ( ! V_5 ) {
V_7 = - V_30 ;
goto V_31;
}
V_16 = F_24 ( V_14 , V_32 , 0 ) ;
if ( ! V_16 ) {
V_7 = - V_24 ;
goto V_33;
}
V_5 -> V_34 = V_16 -> V_35 ;
V_5 -> V_36 = F_25 ( V_16 ) ;
if ( ! F_26 ( V_5 -> V_34 , V_5 -> V_36 ,
V_19 -> V_37 ) ) {
V_7 = - V_38 ;
goto V_33;
}
V_5 -> V_9 = F_27 ( V_5 -> V_34 , V_5 -> V_36 ) ;
if ( V_5 -> V_9 == NULL ) {
F_28 ( & V_14 -> V_11 , L_4 ) ;
V_7 = - V_30 ;
goto V_39;
}
V_2 = (struct V_1 * ) F_6 ( V_5 ) ;
V_2 -> V_3 = V_17 ;
F_1 ( V_2 ) ;
V_7 = F_29 ( V_5 , V_21 , V_40 ) ;
if ( V_7 )
goto V_41;
return V_7 ;
V_41:
F_3 ( V_2 ) ;
F_30 ( V_5 -> V_9 ) ;
V_39:
F_31 ( V_5 -> V_34 , V_5 -> V_36 ) ;
V_33:
F_32 ( V_5 ) ;
V_31:
F_33 ( V_17 ) ;
V_29:
V_25:
F_20 ( & V_14 -> V_11 , L_5 , V_7 ) ;
return V_7 ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_35 ( V_14 ) ;
struct V_1 * V_42 = F_36 ( V_5 ) ;
if ( ! V_5 )
return 0 ;
if ( F_37 () )
F_38 () ;
F_39 ( V_5 ) ;
if ( V_42 -> V_3 )
F_3 ( V_42 ) ;
F_30 ( V_5 -> V_9 ) ;
F_31 ( V_5 -> V_34 , V_5 -> V_36 ) ;
F_32 ( V_5 ) ;
if ( V_42 -> V_3 )
F_33 ( V_42 -> V_3 ) ;
return 0 ;
}
