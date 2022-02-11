static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_5 =
F_2 ( V_2 , struct V_5 , V_6 ) ;
F_3 ( V_5 -> V_7 , 1 ) ;
F_4 ( V_5 -> V_8 ) ;
F_5 ( V_5 -> V_7 , 0 ) ;
F_4 ( V_5 -> V_9 ) ;
F_5 ( V_5 -> V_7 , 1 ) ;
F_4 ( V_5 -> V_10 ) ;
F_6 ( 1 ) ;
return V_11 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_5 * V_5 ;
bool V_14 = false ;
T_1 V_15 ;
int V_16 ;
V_5 = F_8 ( & V_13 -> V_17 , sizeof( * V_5 ) ,
V_18 ) ;
if ( ! V_5 )
return - V_19 ;
V_14 = F_9 ( V_13 -> V_17 . V_20 , L_1 ) ;
V_5 -> V_7 = F_10 ( & V_13 -> V_17 , NULL ,
V_14 ? V_21 : V_22 ) ;
if ( F_11 ( V_5 -> V_7 ) ) {
F_12 ( & V_13 -> V_17 , L_2 ) ;
return F_13 ( V_5 -> V_7 ) ;
}
V_5 -> V_6 . V_23 = F_1 ;
V_5 -> V_6 . V_24 = 128 ;
V_5 -> V_8 = 100 ;
V_5 -> V_9 = 100 ;
V_5 -> V_10 = 3000 ;
V_16 = F_14 ( V_13 -> V_17 . V_20 , L_3 , & V_15 ) ;
if ( ! V_16 ) {
if ( V_15 > 255 )
F_12 ( & V_13 -> V_17 , L_4 ,
V_15 ) ;
else
V_5 -> V_6 . V_24 = V_15 ;
}
F_14 ( V_13 -> V_17 . V_20 , L_5 ,
& V_5 -> V_8 ) ;
F_14 ( V_13 -> V_17 . V_20 , L_6 ,
& V_5 -> V_9 ) ;
F_14 ( V_13 -> V_17 . V_20 , L_7 ,
& V_5 -> V_10 ) ;
F_15 ( V_13 , V_5 ) ;
V_16 = F_16 ( & V_5 -> V_6 ) ;
if ( V_16 ) {
F_12 ( & V_13 -> V_17 , L_8 ,
V_25 , V_16 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_18 ( V_13 ) ;
int V_16 ;
V_16 = F_19 ( & V_5 -> V_6 ) ;
if ( V_16 ) {
F_12 ( & V_13 -> V_17 ,
L_9 ,
V_25 , V_16 ) ;
return - V_26 ;
}
return 0 ;
}
