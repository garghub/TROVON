static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 * V_2 -> V_8 ,
V_4 -> V_5 + V_9 ) ;
F_3 ( 0x5ab9 , V_4 -> V_5 + V_10 ) ;
F_3 ( 0x03 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
V_2 -> V_8 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_20 ;
int V_21 ;
unsigned int V_22 ;
bool V_23 = V_24 ;
V_4 = F_7 ( V_14 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
F_8 ( V_12 , V_4 ) ;
V_19 = F_9 ( V_12 , V_27 , 0 ) ;
V_4 -> V_5 = F_10 ( V_14 , V_19 ) ;
if ( F_11 ( V_4 -> V_5 ) )
return F_12 ( V_4 -> V_5 ) ;
V_20 = F_13 ( V_16 , 0 ) ;
if ( F_11 ( V_20 ) ) {
F_14 ( L_1 , V_28 ) ;
return F_12 ( V_20 ) ;
}
V_4 -> V_7 = F_15 ( V_20 ) ;
if ( V_4 -> V_7 == 0 ) {
F_14 ( L_2 , V_28 ) ;
return - V_29 ;
}
V_22 = V_30 / V_4 -> V_7 ;
V_4 -> V_14 . V_31 = & V_32 ;
V_4 -> V_14 . V_33 = & V_34 ;
V_4 -> V_14 . V_8 = V_22 ;
V_4 -> V_14 . V_35 = 1 ;
V_4 -> V_14 . V_22 = V_22 ;
V_4 -> V_14 . V_36 = V_14 ;
F_16 ( & V_4 -> V_14 , V_37 , V_14 ) ;
F_17 ( & V_4 -> V_14 , V_23 ) ;
F_18 ( & V_4 -> V_14 , V_4 ) ;
V_21 = F_19 ( & V_4 -> V_14 ) ;
if ( V_21 )
return V_21 ;
F_20 ( V_14 , L_3 ,
V_4 -> V_14 . V_8 , V_23 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_22 ( V_12 ) ;
F_1 ( & V_4 -> V_14 ) ;
F_23 ( & V_4 -> V_14 ) ;
return 0 ;
}
