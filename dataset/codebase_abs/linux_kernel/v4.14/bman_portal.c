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
F_14 ( V_5 , L_3 , V_15 ) ;
return - V_24 ;
}
V_18 [ 1 ] = F_13 ( V_12 , V_22 ,
V_25 ) ;
if ( ! V_18 [ 1 ] ) {
F_14 ( V_5 , L_4 , V_15 ) ;
return - V_24 ;
}
V_3 -> V_7 = - 1 ;
V_10 = F_15 ( V_12 , 0 ) ;
if ( V_10 <= 0 ) {
F_14 ( V_5 , L_5 , V_15 ) ;
return - V_24 ;
}
V_3 -> V_10 = V_10 ;
V_19 = F_16 ( V_18 [ 0 ] -> V_26 , F_17 ( V_18 [ 0 ] ) , 0 ) ;
if ( ! V_19 ) {
F_14 ( V_5 , L_6 ) ;
goto V_27;
}
V_3 -> V_28 [ V_23 ] = V_19 ;
V_19 = F_16 ( V_18 [ 1 ] -> V_26 , F_17 ( V_18 [ 1 ] ) ,
V_29 | V_30 ) ;
if ( ! V_19 ) {
F_14 ( V_5 , L_7 ) ;
goto V_31;
}
V_3 -> V_28 [ V_25 ] = V_19 ;
F_18 ( & V_32 ) ;
V_7 = F_19 ( - 1 , & V_33 ) ;
if ( V_7 >= V_34 ) {
F_20 ( & V_32 ) ;
return 0 ;
}
F_21 ( V_7 , & V_33 ) ;
F_20 ( & V_32 ) ;
V_3 -> V_7 = V_7 ;
if ( ! F_1 ( V_3 ) ) {
F_14 ( V_5 , L_8 ) ;
goto V_35;
}
if ( ! F_22 ( V_7 ) )
F_6 ( V_7 ) ;
return 0 ;
V_35:
F_23 ( V_3 -> V_28 [ V_25 ] ) ;
V_31:
F_23 ( V_3 -> V_28 [ V_23 ] ) ;
V_27:
return - V_24 ;
}
static int T_2 F_24 ( struct V_36 * V_37 )
{
int V_38 ;
V_38 = F_25 ( V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_26 ( V_39 ,
L_9 ,
F_10 , F_6 ) ;
if ( V_38 < 0 ) {
F_27 ( L_10 ) ;
F_28 ( V_37 ) ;
return V_38 ;
}
return 0 ;
}
