static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_2 . V_7 ;
if ( V_6 && V_6 -> V_8 )
V_6 -> V_8 ( V_2 ) ;
F_3 ( V_4 -> V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_2 . V_7 ;
F_5 ( V_4 -> V_9 ) ;
if ( V_6 && V_6 -> V_10 )
V_6 -> V_10 ( V_2 ) ;
F_6 ( V_4 -> V_11 + 0x200 , 0 ,
V_12 [ 0 ] . V_13 & 0xfffe ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_14 , int V_3 )
{
struct V_1 * V_2 = F_8 ( V_14 -> V_2 . V_15 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_11 + 0x200 , 0 , V_3 ) ;
}
static void F_10 ( struct V_1 * V_14 , int V_3 )
{
struct V_1 * V_2 = F_8 ( V_14 -> V_2 . V_15 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_11 + 0x200 , 0 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 -> V_2 . V_15 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_9 ) ;
F_13 ( V_4 -> V_11 + 0x200 , 0 ,
V_12 [ 0 ] . V_13 & 0xfffe ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 -> V_2 . V_15 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_9 ) ;
return 0 ;
}
static int T_2 F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_2 . V_7 ;
struct V_16 * V_17 , * V_18 ;
struct V_19 * V_9 ;
struct V_4 * V_4 ;
int V_20 , V_21 ;
V_17 = F_16 ( V_2 , V_22 , 0 ) ;
if ( ! V_17 ) {
return - V_23 ;
}
V_4 = F_17 ( sizeof *V_4 , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_21 = F_18 ( V_2 , 0 ) ;
if ( V_21 >= 0 )
V_20 = V_21 ;
else
goto V_26;
V_9 = F_19 ( & V_2 -> V_2 , L_1 ) ;
if ( F_20 ( V_9 ) ) {
V_21 = F_21 ( V_9 ) ;
goto V_27;
}
V_18 = & V_4 -> V_18 ;
V_18 -> V_28 = L_2 ;
V_18 -> V_13 = V_17 -> V_13 ;
V_18 -> V_29 = V_17 -> V_13 + 0xff ;
V_18 -> V_30 = V_22 ;
V_21 = F_22 ( V_17 , V_18 ) ;
if ( V_21 )
goto V_31;
V_4 -> V_11 = F_23 ( V_18 -> V_13 , F_24 ( V_18 ) ) ;
if ( ! V_4 -> V_11 ) {
V_21 = - V_25 ;
goto V_32;
}
V_4 -> V_9 = V_9 ;
F_25 ( V_2 , V_4 ) ;
if ( V_6 && V_6 -> V_33 )
V_6 -> V_33 ( V_2 ) ;
F_26 ( V_34 L_3 ) ;
V_21 = F_27 ( & V_2 -> V_2 , V_2 -> V_35 , V_36 ,
F_28 ( V_36 ) , V_17 , V_20 ) ;
if ( ! V_21 )
return 0 ;
F_29 ( V_4 -> V_11 ) ;
V_32:
F_30 ( & V_4 -> V_18 ) ;
V_31:
F_31 ( V_9 ) ;
V_27:
V_26:
F_32 ( V_4 ) ;
return V_21 ;
}
static int T_3 F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_34 ( & V_2 -> V_2 ) ;
F_29 ( V_4 -> V_11 ) ;
F_30 ( & V_4 -> V_18 ) ;
F_3 ( V_4 -> V_9 ) ;
F_31 ( V_4 -> V_9 ) ;
F_25 ( V_2 , NULL ) ;
F_32 ( V_4 ) ;
return 0 ;
}
