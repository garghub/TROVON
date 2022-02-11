static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_1 , V_3 ) ;
if ( V_3 != 0 )
return - V_12 ;
return F_3 ( V_6 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_7 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_2 , V_3 ) ;
if ( V_3 != 0 )
return - V_12 ;
return F_5 ( V_6 , V_4 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_3 , V_3 ) ;
if ( V_3 != 0 )
return - V_12 ;
return F_7 ( V_6 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_4 , V_3 ) ;
if ( V_3 != 0 )
return - V_12 ;
return F_9 ( V_6 , V_4 , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_5 , V_3 ) ;
F_11 ( 500 ) ;
F_12 ( 0xda , V_13 ) ;
F_11 ( 500 ) ;
F_12 ( 0x00 , V_13 ) ;
F_13 ( 1000 ) ;
F_14 ( & V_6 -> V_2 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_6 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_7 , V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 , int V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_11 , 1 , L_8 , V_3 ) ;
if ( V_6 -> V_15 == V_16 ) {
F_2 ( V_11 , 1 , L_9 ) ;
return V_17 | V_18 ;
} else {
F_2 ( V_11 , 1 , L_10 ) ;
}
return 0 ;
}
int F_18 ( struct V_8 * V_9 )
{
struct V_19 * V_19 = & V_9 -> V_19 ;
struct V_5 * V_6 ;
int V_20 = 0 , V_21 ;
F_2 ( V_11 , 1 , L_11 ) ;
V_6 = F_19 ( sizeof( struct V_5 ) , V_22 ) ;
if ( ! V_6 ) {
F_2 ( V_23 , 1 , L_12 ) ;
V_21 = - V_24 ;
goto V_25;
}
V_6 -> V_10 = V_9 ;
V_9 -> V_5 = V_6 ;
V_20 = V_26 ;
V_6 -> V_2 . V_27 = V_28 ;
V_6 -> V_2 . V_29 = F_1 ;
V_6 -> V_2 . V_30 = F_4 ;
V_6 -> V_2 . V_31 = F_6 ;
V_6 -> V_2 . V_32 = F_8 ;
V_6 -> V_2 . V_33 = F_10 ;
V_6 -> V_2 . V_34 = F_15 ;
V_6 -> V_2 . V_35 = F_16 ;
V_6 -> V_2 . V_36 = F_17 ;
V_6 -> V_2 . V_7 = V_6 ;
F_20 ( & V_6 -> V_37 ) ;
F_21 ( & V_6 -> V_38 ) ;
F_21 ( & V_6 -> V_39 ) ;
F_21 ( & V_6 -> V_40 ) ;
F_2 ( V_23 , 1 , L_13 ) ;
V_21 = F_22 ( V_19 , & V_6 -> V_2 , V_20 , 1 ) ;
if ( V_21 != 0 ) {
F_2 ( V_23 , 1 , L_14 , V_21 ) ;
goto V_25;
}
F_2 ( V_23 , 1 , L_15 ) ;
F_23 ( V_6 ) ;
return 0 ;
V_25:
F_24 ( V_6 ) ;
return V_21 ;
}
void F_25 ( struct V_8 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_5 ;
F_2 ( V_11 , 1 , L_16 ) ;
F_26 ( V_6 ) ;
F_2 ( V_23 , 1 , L_17 ) ;
if ( V_6 )
F_27 ( & V_6 -> V_2 ) ;
F_24 ( V_6 ) ;
}
