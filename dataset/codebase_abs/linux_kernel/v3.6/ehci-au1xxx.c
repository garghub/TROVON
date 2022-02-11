static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_2 -> V_7 ;
V_5 = F_3 ( V_2 ) ;
V_4 -> V_8 = 0 ;
return V_5 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_5 ;
if ( F_5 () )
return - V_13 ;
if ( V_10 -> V_11 [ 1 ] . V_14 != V_15 ) {
F_6 ( L_1 ) ;
return - V_16 ;
}
V_2 = F_7 ( & V_17 , & V_10 -> V_18 , L_2 ) ;
if ( ! V_2 )
return - V_16 ;
V_12 = F_8 ( V_10 , V_19 , 0 ) ;
V_2 -> V_20 = V_12 -> V_21 ;
V_2 -> V_22 = F_9 ( V_12 ) ;
if ( ! F_10 ( V_2 -> V_20 , V_2 -> V_22 , V_23 ) ) {
F_6 ( L_3 ) ;
V_5 = - V_24 ;
goto V_25;
}
V_2 -> V_7 = F_11 ( V_2 -> V_20 , V_2 -> V_22 ) ;
if ( ! V_2 -> V_7 ) {
F_6 ( L_4 ) ;
V_5 = - V_16 ;
goto V_26;
}
if ( F_12 ( V_27 , 1 ) ) {
F_13 ( V_28 L_5 , V_10 -> V_29 ) ;
V_5 = - V_13 ;
goto V_30;
}
V_5 = F_14 ( V_2 , V_10 -> V_11 [ 1 ] . V_21 ,
V_31 ) ;
if ( V_5 == 0 ) {
F_15 ( V_10 , V_2 ) ;
return V_5 ;
}
F_12 ( V_27 , 0 ) ;
V_30:
F_16 ( V_2 -> V_7 ) ;
V_26:
F_17 ( V_2 -> V_20 , V_2 -> V_22 ) ;
V_25:
F_18 ( V_2 ) ;
return V_5 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_20 ( V_10 ) ;
F_21 ( V_2 ) ;
F_12 ( V_27 , 0 ) ;
F_16 ( V_2 -> V_7 ) ;
F_17 ( V_2 -> V_20 , V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
F_15 ( V_10 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_32 * V_18 )
{
struct V_1 * V_2 = F_23 ( V_18 ) ;
bool V_33 = F_24 ( V_18 ) ;
int V_34 ;
V_34 = F_25 ( V_2 , V_33 ) ;
F_12 ( V_27 , 0 ) ;
return V_34 ;
}
static int F_26 ( struct V_32 * V_18 )
{
struct V_1 * V_2 = F_23 ( V_18 ) ;
F_12 ( V_27 , 1 ) ;
F_27 ( V_2 , false ) ;
return 0 ;
}
