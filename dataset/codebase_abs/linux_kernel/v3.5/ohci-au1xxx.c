static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( V_4 , L_1 , V_4 ) ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_5 ( V_4 ) ) < 0 ) {
F_6 ( V_2 -> V_6 . V_7 , L_2 ,
V_2 -> V_6 . V_8 ) ;
F_7 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_5 , V_11 ;
struct V_1 * V_2 ;
if ( F_9 () )
return - V_12 ;
if ( V_10 -> V_13 [ 1 ] . V_14 != V_15 ) {
F_10 ( L_3 ) ;
return - V_16 ;
}
V_2 = F_11 ( & V_17 , & V_10 -> V_18 , L_4 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_19 = V_10 -> V_13 [ 0 ] . V_20 ;
V_2 -> V_21 = V_10 -> V_13 [ 0 ] . V_22 - V_10 -> V_13 [ 0 ] . V_20 + 1 ;
if ( ! F_12 ( V_2 -> V_19 , V_2 -> V_21 , V_23 ) ) {
F_10 ( L_5 ) ;
V_5 = - V_24 ;
goto V_25;
}
V_2 -> V_26 = F_13 ( V_2 -> V_19 , V_2 -> V_21 ) ;
if ( ! V_2 -> V_26 ) {
F_10 ( L_6 ) ;
V_5 = - V_16 ;
goto V_27;
}
V_11 = ( V_2 -> V_19 == V_28 ) ?
V_29 : V_30 ;
if ( F_14 ( V_11 , 1 ) ) {
F_15 ( V_31 L_7 , V_10 -> V_32 ) ;
V_5 = - V_12 ;
goto V_33;
}
F_16 ( F_2 ( V_2 ) ) ;
V_5 = F_17 ( V_2 , V_10 -> V_13 [ 1 ] . V_20 ,
V_34 ) ;
if ( V_5 == 0 ) {
F_18 ( V_10 , V_2 ) ;
return V_5 ;
}
F_14 ( V_11 , 0 ) ;
V_33:
F_19 ( V_2 -> V_26 ) ;
V_27:
F_20 ( V_2 -> V_19 , V_2 -> V_21 ) ;
V_25:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
int V_11 ;
V_11 = ( V_2 -> V_19 == V_28 ) ?
V_29 : V_30 ;
F_24 ( V_2 ) ;
F_14 ( V_11 , 0 ) ;
F_19 ( V_2 -> V_26 ) ;
F_20 ( V_2 -> V_19 , V_2 -> V_21 ) ;
F_21 ( V_2 ) ;
F_18 ( V_10 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_35 * V_18 )
{
struct V_1 * V_2 = F_26 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_14 ;
int V_36 ;
V_36 = 0 ;
F_27 ( & V_4 -> V_37 , V_14 ) ;
if ( V_4 -> V_38 != V_39 ) {
V_36 = - V_40 ;
goto V_41;
}
F_28 ( V_4 , V_42 , & V_4 -> V_26 -> V_43 ) ;
( void ) F_29 ( V_4 , & V_4 -> V_26 -> V_43 ) ;
F_30 ( V_44 , & V_2 -> V_14 ) ;
F_14 ( V_30 , 0 ) ;
V_41:
F_31 ( & V_4 -> V_37 , V_14 ) ;
return V_36 ;
}
static int F_32 ( struct V_35 * V_18 )
{
struct V_1 * V_2 = F_26 ( V_18 ) ;
F_14 ( V_30 , 1 ) ;
F_33 ( V_44 , & V_2 -> V_14 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
