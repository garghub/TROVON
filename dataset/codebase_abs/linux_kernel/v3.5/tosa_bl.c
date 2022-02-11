static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
F_2 ( V_2 -> V_6 , V_9 , V_2 -> V_10 ) ;
F_2 ( V_2 -> V_6 , V_11 , ( V_12 ) ( V_3 & 0xff ) ) ;
F_3 ( V_13 , V_3 & 0x100 ) ;
F_4 ( V_5 , V_3 ) ;
}
static int F_5 ( struct V_14 * V_7 )
{
struct V_15 * V_16 = & V_7 -> V_16 ;
struct V_1 * V_2 = F_6 ( & V_7 -> V_7 ) ;
int V_17 = F_7 ( V_16 -> V_17 , V_16 -> V_18 ) ;
int V_3 = V_16 -> V_3 ;
if ( V_17 )
V_3 = 0 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_7 )
{
struct V_15 * V_16 = & V_7 -> V_16 ;
return V_16 -> V_3 ;
}
static int T_1 F_9 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_15 V_16 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_10 ( & V_20 -> V_7 , sizeof( struct V_1 ) ,
V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_2 -> V_10 = V_26 . V_10 == - 1 ? V_27 : V_26 . V_10 ;
V_23 = F_11 ( V_13 , L_1 ) ;
if ( V_23 ) {
F_12 ( & V_2 -> V_28 -> V_7 , L_2 ) ;
return V_23 ;
}
V_23 = F_13 ( V_13 , 0 ) ;
if ( V_23 )
goto V_29;
F_14 ( V_20 , V_2 ) ;
V_2 -> V_6 = V_20 ;
memset ( & V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 . type = V_30 ;
V_16 . V_31 = 512 - 1 ;
V_2 -> V_28 = F_15 ( L_3 , & V_20 -> V_7 , V_2 ,
& V_32 , & V_16 ) ;
if ( F_16 ( V_2 -> V_28 ) ) {
V_23 = F_17 ( V_2 -> V_28 ) ;
goto V_33;
}
V_2 -> V_28 -> V_16 . V_3 = 69 ;
V_2 -> V_28 -> V_16 . V_17 = V_34 ;
F_18 ( V_2 -> V_28 ) ;
return 0 ;
V_33:
V_2 -> V_28 = NULL ;
V_29:
F_19 ( V_13 ) ;
return V_23 ;
}
static int T_2 F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
F_22 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
F_19 ( V_13 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , T_3 V_35 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
F_18 ( V_2 -> V_28 ) ;
return 0 ;
}
