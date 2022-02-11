static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_2 ) ;
if ( V_6 && V_6 -> V_7 )
V_6 -> V_7 ( V_2 ) ;
F_4 ( V_4 -> V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_2 ) ;
F_6 ( V_4 -> V_8 ) ;
if ( V_6 && V_6 -> V_9 )
V_6 -> V_9 ( V_2 ) ;
F_7 ( V_4 -> V_10 + 0x200 , 0 ,
V_11 [ 0 ] . V_12 & 0xfffe ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_13 , int V_3 )
{
struct V_1 * V_2 = F_9 ( V_13 -> V_2 . V_14 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 -> V_10 + 0x200 , 0 , V_3 ) ;
}
static void F_11 ( struct V_1 * V_13 , int V_3 )
{
struct V_1 * V_2 = F_9 ( V_13 -> V_2 . V_14 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 -> V_10 + 0x200 , 0 , V_3 ) ;
}
static int F_13 ( struct V_1 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 -> V_2 . V_14 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 -> V_8 ) ;
F_14 ( V_4 -> V_10 + 0x200 , 0 ,
V_11 [ 0 ] . V_12 & 0xfffe ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 -> V_2 . V_14 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_4 -> V_8 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( & V_2 -> V_2 ) ;
struct V_15 * V_16 , * V_17 ;
struct V_18 * V_8 ;
struct V_4 * V_4 ;
int V_19 , V_20 ;
V_16 = F_17 ( V_2 , V_21 , 0 ) ;
if ( ! V_16 )
return - V_22 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_20 = F_19 ( V_2 , 0 ) ;
if ( V_20 >= 0 )
V_19 = V_20 ;
else
goto V_25;
V_8 = F_20 ( & V_2 -> V_2 , L_1 ) ;
if ( F_21 ( V_8 ) ) {
V_20 = F_22 ( V_8 ) ;
goto V_26;
}
V_17 = & V_4 -> V_17 ;
V_17 -> V_27 = L_2 ;
V_17 -> V_12 = V_16 -> V_12 ;
V_17 -> V_28 = V_16 -> V_12 + 0xff ;
V_17 -> V_29 = V_21 ;
V_20 = F_23 ( V_16 , V_17 ) ;
if ( V_20 )
goto V_30;
V_4 -> V_10 = F_24 ( V_17 -> V_12 , F_25 ( V_17 ) ) ;
if ( ! V_4 -> V_10 ) {
V_20 = - V_24 ;
goto V_31;
}
V_4 -> V_8 = V_8 ;
F_26 ( V_2 , V_4 ) ;
if ( V_6 && V_6 -> V_32 )
V_6 -> V_32 ( V_2 ) ;
F_27 ( & V_2 -> V_2 , L_3 ) ;
V_20 = F_28 ( & V_2 -> V_2 , V_2 -> V_33 , V_34 ,
F_29 ( V_34 ) , V_16 , V_19 , NULL ) ;
if ( ! V_20 )
return 0 ;
F_30 ( V_4 -> V_10 ) ;
V_31:
F_31 ( & V_4 -> V_17 ) ;
V_30:
F_32 ( V_8 ) ;
V_26:
V_25:
F_33 ( V_4 ) ;
return V_20 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_35 ( & V_2 -> V_2 ) ;
F_30 ( V_4 -> V_10 ) ;
F_31 ( & V_4 -> V_17 ) ;
F_4 ( V_4 -> V_8 ) ;
F_32 ( V_4 -> V_8 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
