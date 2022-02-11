int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 ;
int V_7 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_4 . V_8 . V_9 = V_10 ;
V_4 . V_8 . V_11 = V_12 ;
V_4 . V_13 = V_14 ;
V_7 = F_2 ( & V_2 -> V_15 -> V_16 , & V_4 ,
& V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_17 = V_6 . V_17 ;
return 0 ;
}
int F_3 ( struct V_18 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_19 = 800 ;
V_2 -> V_20 =
36 +
4 +
8 +
2 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_5 ( V_21 , L_1 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
if ( V_2 -> V_22 != 2 &&
V_2 -> V_22 != 3 ) {
F_6 ( L_2 ,
V_2 -> V_22 ) ;
return - V_24 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_7 ;
F_8 ( & V_2 -> V_25 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( & V_2 -> V_25 ,
V_26 ) ;
if ( V_7 <= 0 ) {
F_11 ( L_3 ) ;
return - V_27 ;
}
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_12 ( V_2 ) ;
}
