static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( V_4 , L_1 , V_4 ) ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_5 ( V_4 ) ) < 0 ) {
F_6 ( L_2 , V_2 -> V_6 . V_7 ) ;
F_7 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
int V_5 , V_10 ;
struct V_1 * V_2 ;
if ( F_9 () )
return - V_11 ;
if ( V_9 -> V_12 [ 1 ] . V_13 != V_14 ) {
F_10 ( L_3 ) ;
return - V_15 ;
}
V_2 = F_11 ( & V_16 , & V_9 -> V_17 , L_4 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_18 = V_9 -> V_12 [ 0 ] . V_19 ;
V_2 -> V_20 = V_9 -> V_12 [ 0 ] . V_21 - V_9 -> V_12 [ 0 ] . V_19 + 1 ;
if ( ! F_12 ( V_2 -> V_18 , V_2 -> V_20 , V_22 ) ) {
F_10 ( L_5 ) ;
V_5 = - V_23 ;
goto V_24;
}
V_2 -> V_25 = F_13 ( V_2 -> V_18 , V_2 -> V_20 ) ;
if ( ! V_2 -> V_25 ) {
F_10 ( L_6 ) ;
V_5 = - V_15 ;
goto V_26;
}
V_10 = ( V_2 -> V_18 == V_27 ) ?
V_28 : V_29 ;
if ( F_14 ( V_10 , 1 ) ) {
F_15 ( V_30 L_7 , V_9 -> V_31 ) ;
V_5 = - V_11 ;
goto V_32;
}
F_16 ( F_2 ( V_2 ) ) ;
V_5 = F_17 ( V_2 , V_9 -> V_12 [ 1 ] . V_19 ,
V_33 ) ;
if ( V_5 == 0 ) {
F_18 ( V_9 , V_2 ) ;
return V_5 ;
}
F_14 ( V_10 , 0 ) ;
V_32:
F_19 ( V_2 -> V_25 ) ;
V_26:
F_20 ( V_2 -> V_18 , V_2 -> V_20 ) ;
V_24:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
int V_10 ;
V_10 = ( V_2 -> V_18 == V_27 ) ?
V_28 : V_29 ;
F_24 ( V_2 ) ;
F_14 ( V_10 , 0 ) ;
F_19 ( V_2 -> V_25 ) ;
F_20 ( V_2 -> V_18 , V_2 -> V_20 ) ;
F_21 ( V_2 ) ;
F_18 ( V_9 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_34 * V_17 )
{
struct V_1 * V_2 = F_26 ( V_17 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_13 ;
int V_35 ;
V_35 = 0 ;
F_27 ( & V_4 -> V_36 , V_13 ) ;
if ( V_4 -> V_37 != V_38 ) {
V_35 = - V_39 ;
goto V_40;
}
F_28 ( V_4 , V_41 , & V_4 -> V_25 -> V_42 ) ;
( void ) F_29 ( V_4 , & V_4 -> V_25 -> V_42 ) ;
F_30 ( V_43 , & V_2 -> V_13 ) ;
F_14 ( V_29 , 0 ) ;
V_40:
F_31 ( & V_4 -> V_36 , V_13 ) ;
return V_35 ;
}
static int F_32 ( struct V_34 * V_17 )
{
struct V_1 * V_2 = F_26 ( V_17 ) ;
F_14 ( V_29 , 1 ) ;
F_33 ( V_43 , & V_2 -> V_13 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
