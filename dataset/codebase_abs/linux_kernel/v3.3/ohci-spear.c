static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int T_1 F_5 ( struct V_4 * V_5 )
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
int * V_22 = V_12 -> V_23 . V_24 ;
char V_25 [ 20 ] = L_2 ;
if ( V_22 == NULL )
return - V_26 ;
V_21 = F_15 ( V_12 , 0 ) ;
if ( V_21 < 0 ) {
V_20 = V_21 ;
goto V_27;
}
if ( * V_22 >= 0 )
sprintf ( V_25 , L_3 , * V_22 ) ;
V_16 = F_16 ( NULL , V_25 ) ;
if ( F_17 ( V_16 ) ) {
F_9 ( & V_12 -> V_23 , L_4 ) ;
V_20 = F_18 ( V_16 ) ;
goto V_28;
}
V_5 = F_19 ( V_14 , & V_12 -> V_23 , F_20 ( & V_12 -> V_23 ) ) ;
if ( ! V_5 ) {
V_20 = - V_29 ;
goto V_30;
}
V_19 = F_21 ( V_12 , V_31 , 0 ) ;
if ( ! V_19 ) {
V_20 = - V_32 ;
goto V_33;
}
V_5 -> V_34 = V_12 -> V_18 [ 0 ] . V_35 ;
V_5 -> V_36 = F_22 ( V_19 ) ;
if ( ! F_23 ( V_5 -> V_34 , V_5 -> V_36 , V_37 ) ) {
F_24 ( & V_12 -> V_23 , L_5 ) ;
V_20 = - V_38 ;
goto V_33;
}
V_5 -> V_8 = F_25 ( V_5 -> V_34 , V_5 -> V_36 ) ;
if ( ! V_5 -> V_8 ) {
F_24 ( & V_12 -> V_23 , L_6 ) ;
V_20 = - V_29 ;
goto V_39;
}
V_17 = (struct V_1 * ) F_6 ( V_5 ) ;
V_17 -> V_3 = V_16 ;
F_1 ( V_17 ) ;
F_26 ( F_6 ( V_5 ) ) ;
V_20 = F_27 ( V_5 , F_15 ( V_12 , 0 ) , 0 ) ;
if ( V_20 == 0 )
return V_20 ;
F_3 ( V_17 ) ;
F_28 ( V_5 -> V_8 ) ;
V_39:
F_29 ( V_5 -> V_34 , V_5 -> V_36 ) ;
V_33:
F_30 ( V_5 ) ;
V_30:
F_31 ( V_16 ) ;
V_28:
V_27:
F_9 ( & V_12 -> V_23 , L_7 , V_20 ) ;
return V_20 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = F_33 ( V_12 ) ;
struct V_1 * V_17 = F_34 ( V_5 ) ;
F_35 ( V_5 ) ;
if ( V_17 -> V_3 )
F_3 ( V_17 ) ;
F_28 ( V_5 -> V_8 ) ;
F_29 ( V_5 -> V_34 , V_5 -> V_36 ) ;
F_30 ( V_5 ) ;
if ( V_17 -> V_3 )
F_31 ( V_17 -> V_3 ) ;
F_36 ( V_12 , NULL ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_23 ,
T_2 V_40 )
{
struct V_4 * V_5 = F_33 ( V_23 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_17 = F_34 ( V_5 ) ;
if ( F_38 ( V_41 , V_2 -> V_42 ) )
F_39 ( 5 ) ;
V_2 -> V_42 = V_41 ;
F_3 ( V_17 ) ;
return 0 ;
}
static int F_40 ( struct V_11 * V_23 )
{
struct V_4 * V_5 = F_33 ( V_23 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_17 = F_34 ( V_5 ) ;
if ( F_38 ( V_41 , V_2 -> V_42 ) )
F_39 ( 5 ) ;
V_2 -> V_42 = V_41 ;
F_1 ( V_17 ) ;
F_41 ( V_5 ) ;
return 0 ;
}
