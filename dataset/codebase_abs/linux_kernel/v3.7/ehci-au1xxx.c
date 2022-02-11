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
V_2 -> V_7 = F_10 ( & V_10 -> V_18 , V_12 ) ;
if ( ! V_2 -> V_7 ) {
F_6 ( L_3 ) ;
V_5 = - V_16 ;
goto V_23;
}
if ( F_11 ( V_24 , 1 ) ) {
F_12 ( V_25 L_4 , V_10 -> V_26 ) ;
V_5 = - V_13 ;
goto V_23;
}
V_5 = F_13 ( V_2 , V_10 -> V_11 [ 1 ] . V_21 ,
V_27 ) ;
if ( V_5 == 0 ) {
F_14 ( V_10 , V_2 ) ;
return V_5 ;
}
F_11 ( V_24 , 0 ) ;
V_23:
F_15 ( V_2 ) ;
return V_5 ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
F_18 ( V_2 ) ;
F_11 ( V_24 , 0 ) ;
F_15 ( V_2 ) ;
F_14 ( V_10 , NULL ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
bool V_29 = F_21 ( V_18 ) ;
int V_30 ;
V_30 = F_22 ( V_2 , V_29 ) ;
F_11 ( V_24 , 0 ) ;
return V_30 ;
}
static int F_23 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
F_11 ( V_24 , 1 ) ;
F_24 ( V_2 , false ) ;
return 0 ;
}
