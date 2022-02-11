static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) {
F_3 ( V_3 -> V_5 , L_1 ,
V_6 , V_3 -> V_7 ) ;
return NULL ;
}
F_4 ( V_4 , V_8 ) ;
V_9 [ V_3 -> V_7 ] = V_4 ;
F_5 ( V_3 -> V_5 , L_2 , V_3 -> V_7 ) ;
return V_4 ;
}
static int F_6 ( unsigned int V_7 )
{
struct V_1 * V_4 = V_9 [ V_7 ] ;
const struct V_2 * V_3 ;
if ( ! V_4 )
return 0 ;
V_3 = F_7 ( V_4 ) ;
if ( ! V_3 )
return 0 ;
F_8 ( V_3 -> V_10 , F_9 ( 0 ) ) ;
return 0 ;
}
static int F_10 ( unsigned int V_7 )
{
struct V_1 * V_4 = V_9 [ V_7 ] ;
const struct V_2 * V_3 ;
if ( ! V_4 )
return 0 ;
V_3 = F_7 ( V_4 ) ;
if ( ! V_3 )
return 0 ;
F_8 ( V_3 -> V_10 , F_9 ( V_7 ) ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_5 = & V_12 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_2 * V_3 ;
struct V_17 * V_18 [ 2 ] ;
void T_1 * V_19 ;
int V_10 , V_7 ;
V_3 = F_12 ( V_5 , sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_21 ;
V_3 -> V_5 = V_5 ;
V_18 [ 0 ] = F_13 ( V_12 , V_22 ,
V_23 ) ;
if ( ! V_18 [ 0 ] ) {
F_14 ( V_5 , L_3 ,
V_15 -> V_24 ) ;
return - V_25 ;
}
V_18 [ 1 ] = F_13 ( V_12 , V_22 ,
V_26 ) ;
if ( ! V_18 [ 1 ] ) {
F_14 ( V_5 , L_4 ,
V_15 -> V_24 ) ;
return - V_25 ;
}
V_3 -> V_7 = - 1 ;
V_10 = F_15 ( V_12 , 0 ) ;
if ( V_10 <= 0 ) {
F_14 ( V_5 , L_5 , V_15 -> V_24 ) ;
return - V_25 ;
}
V_3 -> V_10 = V_10 ;
V_19 = F_16 ( V_18 [ 0 ] -> V_27 , F_17 ( V_18 [ 0 ] ) , 0 ) ;
if ( ! V_19 ) {
F_14 ( V_5 , L_6 ) ;
goto V_28;
}
V_3 -> V_29 [ V_23 ] = V_19 ;
V_19 = F_16 ( V_18 [ 1 ] -> V_27 , F_17 ( V_18 [ 1 ] ) ,
V_30 | V_31 ) ;
if ( ! V_19 ) {
F_14 ( V_5 , L_7 ) ;
goto V_32;
}
V_3 -> V_29 [ V_26 ] = V_19 ;
F_18 ( & V_33 ) ;
V_7 = F_19 ( - 1 , & V_34 ) ;
if ( V_7 >= V_35 ) {
F_20 ( & V_33 ) ;
return 0 ;
}
F_21 ( V_7 , & V_34 ) ;
F_20 ( & V_33 ) ;
V_3 -> V_7 = V_7 ;
if ( ! F_1 ( V_3 ) ) {
F_14 ( V_5 , L_8 ) ;
goto V_36;
}
if ( ! F_22 ( V_7 ) )
F_6 ( V_7 ) ;
return 0 ;
V_36:
F_23 ( V_3 -> V_29 [ V_26 ] ) ;
V_32:
F_23 ( V_3 -> V_29 [ V_23 ] ) ;
V_28:
return - V_25 ;
}
static int T_2 F_24 ( struct V_37 * V_38 )
{
int V_39 ;
V_39 = F_25 ( V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_26 ( V_40 ,
L_9 ,
F_10 , F_6 ) ;
if ( V_39 < 0 ) {
F_27 ( L_10 ) ;
F_28 ( V_38 ) ;
return V_39 ;
}
return 0 ;
}
