static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_7 ) ;
F_4 ( V_6 -> V_9 ) ;
if ( V_4 == 0 ) {
F_5 ( 0x00 , V_6 -> V_9 + V_10 ) ;
F_5 ( 0xff , V_6 -> V_9 + V_11 ) ;
} else {
F_5 ( 0x00 , V_6 -> V_9 + V_11 ) ;
F_5 ( 0xff , V_6 -> V_9 + V_10 ) ;
}
F_6 ( V_6 -> V_9 ) ;
F_7 ( V_6 -> V_7 , L_1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_4 ( V_6 -> V_9 ) ;
if ( V_4 == 0 )
F_5 ( 0xff , V_6 -> V_9 + V_10 ) ;
else
F_5 ( 0xff , V_6 -> V_9 + V_11 ) ;
F_6 ( V_6 -> V_9 ) ;
F_9 ( V_6 -> V_7 ) ;
F_7 ( V_6 -> V_7 , L_2 ) ;
}
static int F_10 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
int V_16 ;
struct V_17 * V_7 = & V_13 -> V_7 ;
struct V_18 * V_19 = & V_13 -> V_19 ;
struct V_20 * V_21 = NULL ;
struct V_5 * V_6 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = V_13 -> V_7 . V_26 ;
void T_1 * V_9 ;
if ( V_25 ) {
V_21 = F_11 ( V_7 , V_25 ) ;
if ( F_12 ( V_21 ) )
return F_13 ( V_21 ) ;
V_13 -> V_7 . V_27 = V_21 ;
}
V_6 = F_14 ( V_7 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
V_6 -> V_7 = & V_13 -> V_7 ;
V_6 -> V_30 = F_15 ( & V_13 -> V_7 , L_3 ) ;
if ( ! F_12 ( V_6 -> V_30 ) ) {
V_16 = F_16 ( V_6 -> V_30 ) ;
if ( V_16 )
return V_16 ;
}
V_9 = F_17 ( V_7 , V_19 ) ;
if ( F_12 ( V_9 ) )
return F_13 ( V_9 ) ;
V_6 -> V_9 = V_9 ;
F_18 ( V_7 , V_6 ) ;
F_9 ( & V_13 -> V_7 ) ;
V_23 = F_14 ( V_7 , sizeof( * V_23 ) , V_28 ) ;
if ( ! V_23 )
return - V_29 ;
V_23 -> type = V_31 ;
V_23 -> V_32 . V_33 = V_34 ;
V_23 -> V_35 = & V_36 ;
V_23 -> V_21 = V_13 -> V_7 . V_27 ;
V_23 -> V_7 = & V_13 -> V_7 ;
V_6 -> V_2 = F_19 ( V_23 ) ;
if ( F_12 ( V_6 -> V_2 ) )
return F_13 ( V_6 -> V_2 ) ;
F_7 ( V_7 , L_4 , ( char * ) V_15 -> V_37 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = F_21 ( V_13 ) ;
F_22 ( & V_13 -> V_7 ) ;
F_23 ( V_6 -> V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_12 ( V_6 -> V_30 ) )
F_25 ( V_6 -> V_30 ) ;
return 0 ;
}
static int F_26 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_12 ( V_6 -> V_30 ) )
F_16 ( V_6 -> V_30 ) ;
return 0 ;
}
