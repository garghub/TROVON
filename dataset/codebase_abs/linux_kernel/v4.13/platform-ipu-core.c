struct V_1 * T_1 F_1 (
const struct V_2 * V_3 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 ,
. V_8 = V_3 -> V_7 + 0x5f ,
. V_9 = V_10 ,
} , {
. V_6 = V_3 -> V_7 + 0x88 ,
. V_8 = V_3 -> V_7 + 0xb3 ,
. V_9 = V_10 ,
} , {
. V_6 = V_3 -> V_11 ,
. V_8 = V_3 -> V_11 ,
. V_9 = V_12 ,
} , {
. V_6 = V_3 -> V_13 ,
. V_8 = V_3 -> V_13 ,
. V_9 = V_12 ,
} ,
} ;
return V_14 = F_2 ( L_1 , - 1 ,
V_5 , F_3 ( V_5 ) , NULL , 0 ) ;
}
struct V_1 * T_1 F_4 (
const struct V_2 * V_3 ,
const struct V_15 * V_16 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 + 0x60 ,
. V_8 = V_3 -> V_7 + 0x87 ,
. V_9 = V_10 ,
} ,
} ;
int V_17 = - V_18 ;
struct V_1 * V_19 ;
if ( F_5 ( V_14 ) )
return F_6 ( - V_20 ) ;
V_19 = F_7 ( L_2 , 0 ) ;
if ( ! V_19 )
return F_6 ( - V_18 ) ;
V_19 -> V_21 . V_22 = F_8 ( sizeof( * V_19 -> V_21 . V_22 ) , V_23 ) ;
if ( ! V_19 -> V_21 . V_22 )
goto V_24;
* V_19 -> V_21 . V_22 = F_9 ( 32 ) ;
V_19 -> V_21 . V_25 = F_9 ( 32 ) ;
V_17 = F_10 ( V_19 , V_5 , F_3 ( V_5 ) ) ;
if ( V_17 )
goto V_24;
if ( V_16 ) {
struct V_15 * V_26 ;
V_17 = F_11 ( V_19 , V_16 , sizeof( * V_16 ) ) ;
if ( V_17 ) {
V_24:
F_12 ( V_19 -> V_21 . V_22 ) ;
F_13 ( V_19 ) ;
return F_6 ( - V_20 ) ;
}
V_26 = F_14 ( & V_19 -> V_21 ) ;
V_26 -> V_27 = & V_14 -> V_21 ;
}
return V_19 ;
}
struct V_1 * T_1 F_15 (
const struct V_2 * V_3 ,
struct V_28 * V_16 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 + 0xb4 ,
. V_8 = V_3 -> V_7 + 0x1bf ,
. V_9 = V_10 ,
} ,
} ;
if ( F_5 ( V_14 ) )
return F_6 ( - V_20 ) ;
V_16 -> V_27 = & V_14 -> V_21 ;
return F_16 ( L_3 , - 1 ,
V_5 , F_3 ( V_5 ) , V_16 , sizeof( * V_16 ) ,
F_9 ( 32 ) ) ;
}
