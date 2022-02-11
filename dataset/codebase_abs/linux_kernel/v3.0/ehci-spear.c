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
V_2 -> V_9 = V_5 -> V_9 + F_7 ( V_2 , F_8 ( V_2 ,
& V_2 -> V_8 -> V_10 ) ) ;
V_2 -> V_11 = F_8 ( V_2 , & V_2 -> V_8 -> V_11 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_5 ) ;
if ( V_7 )
return V_7 ;
F_11 ( V_2 ) ;
F_12 ( V_2 , 0 ) ;
return V_7 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_3 * V_16 ;
const struct V_17 * V_18 = & V_19 ;
int * V_20 = V_13 -> V_21 . V_22 ;
int V_23 , V_7 ;
char V_24 [ 20 ] = L_1 ;
if ( V_20 == NULL )
return - V_25 ;
if ( F_14 () )
return - V_26 ;
V_23 = F_15 ( V_13 , 0 ) ;
if ( V_23 < 0 ) {
V_7 = V_23 ;
goto V_27;
}
if ( * V_20 >= 0 )
sprintf ( V_24 , L_2 , * V_20 ) ;
V_16 = F_16 ( NULL , V_24 ) ;
if ( F_17 ( V_16 ) ) {
F_18 ( & V_13 -> V_21 , L_3 ) ;
V_7 = F_19 ( V_16 ) ;
goto V_28;
}
V_5 = F_20 ( V_18 , & V_13 -> V_21 , F_21 ( & V_13 -> V_21 ) ) ;
if ( ! V_5 ) {
V_7 = - V_29 ;
goto V_30;
}
V_15 = F_22 ( V_13 , V_31 , 0 ) ;
if ( ! V_15 ) {
V_7 = - V_26 ;
goto V_32;
}
V_5 -> V_33 = V_15 -> V_34 ;
V_5 -> V_35 = F_23 ( V_15 ) ;
if ( ! F_24 ( V_5 -> V_33 , V_5 -> V_35 ,
V_18 -> V_36 ) ) {
V_7 = - V_37 ;
goto V_32;
}
V_5 -> V_9 = F_25 ( V_5 -> V_33 , V_5 -> V_35 ) ;
if ( V_5 -> V_9 == NULL ) {
F_26 ( & V_13 -> V_21 , L_4 ) ;
V_7 = - V_29 ;
goto V_38;
}
V_2 = (struct V_1 * ) F_6 ( V_5 ) ;
V_2 -> V_3 = V_16 ;
F_1 ( V_2 ) ;
V_7 = F_27 ( V_5 , V_23 , V_39 | V_40 ) ;
if ( V_7 )
goto V_41;
return V_7 ;
V_41:
F_3 ( V_2 ) ;
F_28 ( V_5 -> V_9 ) ;
V_38:
F_29 ( V_5 -> V_33 , V_5 -> V_35 ) ;
V_32:
F_30 ( V_5 ) ;
V_30:
F_31 ( V_16 ) ;
V_28:
V_27:
F_18 ( & V_13 -> V_21 , L_5 , V_7 ) ;
return V_7 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_33 ( V_13 ) ;
struct V_1 * V_42 = F_34 ( V_5 ) ;
if ( ! V_5 )
return 0 ;
if ( F_35 () )
F_36 () ;
F_37 ( V_5 ) ;
if ( V_42 -> V_3 )
F_3 ( V_42 ) ;
F_28 ( V_5 -> V_9 ) ;
F_29 ( V_5 -> V_33 , V_5 -> V_35 ) ;
F_30 ( V_5 ) ;
if ( V_42 -> V_3 )
F_31 ( V_42 -> V_3 ) ;
return 0 ;
}
