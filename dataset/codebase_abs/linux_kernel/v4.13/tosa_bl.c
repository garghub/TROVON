static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 -> V_7 ) ;
F_3 ( V_2 -> V_6 , V_8 , V_2 -> V_9 ) ;
F_3 ( V_2 -> V_6 , V_10 , ( V_11 ) ( V_3 & 0xff ) ) ;
F_4 ( V_12 , V_3 & 0x100 ) ;
F_5 ( V_5 , V_3 ) ;
}
static int F_6 ( struct V_13 * V_7 )
{
struct V_14 * V_15 = & V_7 -> V_15 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
int V_16 = F_8 ( V_15 -> V_16 , V_15 -> V_17 ) ;
int V_3 = V_15 -> V_3 ;
if ( V_16 )
V_3 = 0 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_7 )
{
struct V_14 * V_15 = & V_7 -> V_15 ;
return V_15 -> V_3 ;
}
static int F_10 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_14 V_15 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
V_2 = F_11 ( & V_19 -> V_7 , sizeof( struct V_1 ) ,
V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_9 = V_25 . V_9 == - 1 ? V_26 : V_25 . V_9 ;
V_22 = F_12 ( & V_19 -> V_7 , V_12 ,
V_27 , L_1 ) ;
if ( V_22 ) {
F_13 ( & V_2 -> V_28 -> V_7 , L_2 ) ;
return V_22 ;
}
F_14 ( V_19 , V_2 ) ;
V_2 -> V_6 = V_19 ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . type = V_29 ;
V_15 . V_30 = 512 - 1 ;
V_2 -> V_28 = F_15 ( & V_19 -> V_7 , L_3 ,
& V_19 -> V_7 , V_2 , & V_31 ,
& V_15 ) ;
if ( F_16 ( V_2 -> V_28 ) ) {
V_22 = F_17 ( V_2 -> V_28 ) ;
goto V_32;
}
V_2 -> V_28 -> V_15 . V_3 = 69 ;
V_2 -> V_28 -> V_15 . V_16 = V_33 ;
F_18 ( V_2 -> V_28 ) ;
return 0 ;
V_32:
V_2 -> V_28 = NULL ;
return V_22 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
V_2 -> V_28 = NULL ;
return 0 ;
}
static int F_21 ( struct V_34 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_34 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
F_18 ( V_2 -> V_28 ) ;
return 0 ;
}
