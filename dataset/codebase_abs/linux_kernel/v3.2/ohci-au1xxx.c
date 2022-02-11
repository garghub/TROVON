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
int V_5 ;
struct V_1 * V_2 ;
if ( F_9 () )
return - V_10 ;
if ( V_9 -> V_11 [ 1 ] . V_12 != V_13 ) {
F_10 ( L_3 ) ;
return - V_14 ;
}
V_2 = F_11 ( & V_15 , & V_9 -> V_16 , L_4 ) ;
if ( ! V_2 )
return - V_14 ;
V_2 -> V_17 = V_9 -> V_11 [ 0 ] . V_18 ;
V_2 -> V_19 = V_9 -> V_11 [ 0 ] . V_20 - V_9 -> V_11 [ 0 ] . V_18 + 1 ;
if ( ! F_12 ( V_2 -> V_17 , V_2 -> V_19 , V_21 ) ) {
F_10 ( L_5 ) ;
V_5 = - V_22 ;
goto V_23;
}
V_2 -> V_24 = F_13 ( V_2 -> V_17 , V_2 -> V_19 ) ;
if ( ! V_2 -> V_24 ) {
F_10 ( L_6 ) ;
V_5 = - V_14 ;
goto V_25;
}
if ( F_14 ( V_26 , 1 ) ) {
F_15 ( V_27 L_7 , V_9 -> V_28 ) ;
V_5 = - V_10 ;
goto V_29;
}
F_16 ( F_2 ( V_2 ) ) ;
V_5 = F_17 ( V_2 , V_9 -> V_11 [ 1 ] . V_18 ,
V_30 ) ;
if ( V_5 == 0 ) {
F_18 ( V_9 , V_2 ) ;
return V_5 ;
}
F_14 ( V_26 , 0 ) ;
V_29:
F_19 ( V_2 -> V_24 ) ;
V_25:
F_20 ( V_2 -> V_17 , V_2 -> V_19 ) ;
V_23:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
F_24 ( V_2 ) ;
F_14 ( V_26 , 0 ) ;
F_19 ( V_2 -> V_24 ) ;
F_20 ( V_2 -> V_17 , V_2 -> V_19 ) ;
F_21 ( V_2 ) ;
F_18 ( V_9 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_32 ;
V_32 = 0 ;
F_27 ( & V_4 -> V_33 , V_12 ) ;
if ( V_2 -> V_34 != V_35 ) {
V_32 = - V_36 ;
goto V_37;
}
F_28 ( V_4 , V_38 , & V_4 -> V_24 -> V_39 ) ;
( void ) F_29 ( V_4 , & V_4 -> V_24 -> V_39 ) ;
F_30 ( V_40 , & V_2 -> V_12 ) ;
F_14 ( V_26 , 0 ) ;
V_37:
F_31 ( & V_4 -> V_33 , V_12 ) ;
return V_32 ;
}
static int F_32 ( struct V_31 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
F_14 ( V_26 , 1 ) ;
F_33 ( V_40 , & V_2 -> V_12 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
