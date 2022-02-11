struct V_1 * T_1 F_1 (
const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 -> V_9 ,
. V_10 = V_3 -> V_9 + 0x5f ,
. V_11 = V_12 ,
} , {
. V_8 = V_3 -> V_9 + 0x88 ,
. V_10 = V_3 -> V_9 + 0xb3 ,
. V_11 = V_12 ,
} , {
. V_8 = V_3 -> V_13 ,
. V_10 = V_3 -> V_13 ,
. V_11 = V_14 ,
} , {
. V_8 = V_3 -> V_15 ,
. V_10 = V_3 -> V_15 ,
. V_11 = V_14 ,
} ,
} ;
return V_16 = F_2 ( L_1 , - 1 ,
V_7 , F_3 ( V_7 ) , V_5 , sizeof( * V_5 ) ) ;
}
struct V_1 * T_1 F_4 (
const struct V_2 * V_3 ,
const struct V_17 * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 -> V_9 + 0x60 ,
. V_10 = V_3 -> V_9 + 0x87 ,
. V_11 = V_12 ,
} ,
} ;
int V_18 = - V_19 ;
struct V_1 * V_20 ;
if ( F_5 ( V_16 ) )
return F_6 ( - V_21 ) ;
V_20 = F_7 ( L_2 , 0 ) ;
if ( ! V_20 )
goto V_22;
V_20 -> V_23 . V_24 = F_8 ( sizeof( * V_20 -> V_23 . V_24 ) , V_25 ) ;
if ( ! V_20 -> V_23 . V_24 )
goto V_22;
* V_20 -> V_23 . V_24 = F_9 ( 32 ) ;
V_20 -> V_23 . V_26 = F_9 ( 32 ) ;
V_18 = F_10 ( V_20 , V_7 , F_3 ( V_7 ) ) ;
if ( V_18 )
goto V_22;
if ( V_5 ) {
struct V_17 * V_27 ;
V_18 = F_11 ( V_20 , V_5 , sizeof( * V_5 ) ) ;
if ( V_18 ) {
V_22:
F_12 ( V_20 -> V_23 . V_24 ) ;
F_13 ( V_20 ) ;
return F_6 ( - V_21 ) ;
}
V_27 = F_14 ( & V_20 -> V_23 ) ;
V_27 -> V_28 = & V_16 -> V_23 ;
}
return V_20 ;
}
struct V_1 * T_1 F_15 (
const struct V_2 * V_3 ,
struct V_29 * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 -> V_9 + 0xb4 ,
. V_10 = V_3 -> V_9 + 0x1bf ,
. V_11 = V_12 ,
} ,
} ;
if ( F_5 ( V_16 ) )
return F_6 ( - V_21 ) ;
V_5 -> V_28 = & V_16 -> V_23 ;
return F_16 ( L_3 , - 1 ,
V_7 , F_3 ( V_7 ) , V_5 , sizeof( * V_5 ) ,
F_9 ( 32 ) ) ;
}
