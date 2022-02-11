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
int V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_8 = V_5 -> V_8 ;
V_7 = F_8 ( V_2 ) ;
if ( V_7 < 0 ) {
F_9 ( V_5 -> V_9 . V_10 , L_1 ) ;
F_10 ( V_5 ) ;
return V_7 ;
}
F_11 ( V_2 ) ;
#ifdef F_12
F_13 ( V_2 , 1 ) ;
#endif
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
const struct V_13 * V_14 = & V_15 ;
struct V_4 * V_5 = NULL ;
struct V_3 * V_16 ;
struct V_1 * V_17 ;
struct V_18 * V_19 ;
int V_20 , V_21 ;
V_21 = F_15 ( V_12 , 0 ) ;
if ( V_21 < 0 ) {
V_20 = V_21 ;
goto V_22;
}
if ( ! V_12 -> V_23 . V_24 )
V_12 -> V_23 . V_24 = & V_25 ;
V_16 = F_16 ( & V_12 -> V_23 , NULL ) ;
if ( F_17 ( V_16 ) ) {
F_9 ( & V_12 -> V_23 , L_2 ) ;
V_20 = F_18 ( V_16 ) ;
goto V_22;
}
V_5 = F_19 ( V_14 , & V_12 -> V_23 , F_20 ( & V_12 -> V_23 ) ) ;
if ( ! V_5 ) {
V_20 = - V_26 ;
goto V_22;
}
V_19 = F_21 ( V_12 , V_27 , 0 ) ;
if ( ! V_19 ) {
V_20 = - V_28 ;
goto V_29;
}
V_5 -> V_30 = V_12 -> V_18 [ 0 ] . V_31 ;
V_5 -> V_32 = F_22 ( V_19 ) ;
if ( ! F_23 ( & V_12 -> V_23 , V_5 -> V_30 , V_5 -> V_32 ,
V_33 ) ) {
F_24 ( & V_12 -> V_23 , L_3 ) ;
V_20 = - V_34 ;
goto V_29;
}
V_5 -> V_8 = F_25 ( & V_12 -> V_23 , V_5 -> V_30 , V_5 -> V_32 ) ;
if ( ! V_5 -> V_8 ) {
F_24 ( & V_12 -> V_23 , L_4 ) ;
V_20 = - V_26 ;
goto V_29;
}
V_17 = (struct V_1 * ) F_6 ( V_5 ) ;
V_17 -> V_3 = V_16 ;
F_1 ( V_17 ) ;
F_26 ( F_6 ( V_5 ) ) ;
V_20 = F_27 ( V_5 , F_15 ( V_12 , 0 ) , 0 ) ;
if ( V_20 == 0 )
return V_20 ;
F_3 ( V_17 ) ;
V_29:
F_28 ( V_5 ) ;
V_22:
F_9 ( & V_12 -> V_23 , L_5 , V_20 ) ;
return V_20 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = F_30 ( V_12 ) ;
struct V_1 * V_17 = F_31 ( V_5 ) ;
F_32 ( V_5 ) ;
if ( V_17 -> V_3 )
F_3 ( V_17 ) ;
F_28 ( V_5 ) ;
F_33 ( V_12 , NULL ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_23 ,
T_1 V_35 )
{
struct V_4 * V_5 = F_30 ( V_23 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_17 = F_31 ( V_5 ) ;
if ( F_35 ( V_36 , V_2 -> V_37 ) )
F_36 ( 5 ) ;
V_2 -> V_37 = V_36 ;
F_3 ( V_17 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_23 )
{
struct V_4 * V_5 = F_30 ( V_23 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_17 = F_31 ( V_5 ) ;
if ( F_35 ( V_36 , V_2 -> V_37 ) )
F_36 ( 5 ) ;
V_2 -> V_37 = V_36 ;
F_1 ( V_17 ) ;
F_38 ( V_5 , false ) ;
return 0 ;
}
