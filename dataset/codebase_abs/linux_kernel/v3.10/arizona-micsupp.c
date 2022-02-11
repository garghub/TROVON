static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 > V_4 )
return - V_5 ;
if ( V_3 == V_4 )
return 3300000 ;
else
return ( V_3 * 50000 ) + 1700000 ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_6 , int V_7 )
{
unsigned int V_8 ;
int V_3 ;
if ( V_6 < 1700000 )
V_6 = 1700000 ;
if ( V_6 > 3200000 )
V_3 = V_4 ;
else
V_3 = F_3 ( V_6 - 1700000 , 50000 ) ;
if ( V_3 < 0 )
return - V_5 ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 < V_6 || V_8 > V_7 )
return - V_5 ;
return V_3 ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_5 ( V_10 , struct V_11 , V_13 ) ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
struct V_16 * V_16 = V_12 -> V_16 ;
struct V_17 * V_17 = V_16 -> V_17 ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_6 ( V_17 , V_20 , & V_18 ) ;
if ( V_19 != 0 ) {
F_7 ( V_16 -> V_21 , L_1 , V_19 ) ;
return;
}
if ( V_15 ) {
if ( ( V_18 & ( V_22 | V_23 ) ) ==
V_22 )
F_8 ( V_15 , L_2 ) ;
else
F_9 ( V_15 , L_2 ) ;
F_10 ( V_15 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_12 ( V_2 ) ;
int V_19 ;
V_19 = F_13 ( V_2 ) ;
if ( V_19 == 0 )
F_14 ( & V_12 -> V_13 ) ;
return V_19 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_12 ( V_2 ) ;
int V_19 ;
V_19 = F_16 ( V_2 ) ;
if ( V_19 == 0 )
F_14 ( & V_12 -> V_13 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_2 , bool V_24 )
{
struct V_11 * V_12 = F_12 ( V_2 ) ;
int V_19 ;
V_19 = F_18 ( V_2 , V_24 ) ;
if ( V_19 == 0 )
F_14 ( & V_12 -> V_13 ) ;
return V_19 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_16 * V_16 = F_20 ( V_26 -> V_21 . V_27 ) ;
struct V_28 V_29 = { } ;
struct V_11 * V_12 ;
int V_19 ;
V_12 = F_21 ( & V_26 -> V_21 , sizeof( * V_12 ) , V_30 ) ;
if ( V_12 == NULL ) {
F_7 ( & V_26 -> V_21 , L_3 ) ;
return - V_31 ;
}
V_12 -> V_16 = V_16 ;
F_22 ( & V_12 -> V_13 , F_4 ) ;
V_12 -> V_32 = V_33 ;
V_12 -> V_32 . V_34 = & V_12 -> V_35 ;
V_12 -> V_35 . V_35 = L_4 ;
V_12 -> V_35 . V_36 = V_36 ( V_16 -> V_21 ) ;
V_29 . V_21 = V_16 -> V_21 ;
V_29 . V_37 = V_12 ;
V_29 . V_17 = V_16 -> V_17 ;
if ( V_16 -> V_38 . V_39 )
V_29 . V_32 = V_16 -> V_38 . V_39 ;
else
V_29 . V_32 = & V_12 -> V_32 ;
F_23 ( V_16 -> V_17 , V_20 ,
V_23 , 0 ) ;
V_12 -> V_40 = F_24 ( & V_11 , & V_29 ) ;
if ( F_25 ( V_12 -> V_40 ) ) {
V_19 = F_26 ( V_12 -> V_40 ) ;
F_7 ( V_16 -> V_21 , L_5 ,
V_19 ) ;
return V_19 ;
}
F_27 ( V_26 , V_12 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_29 ( V_26 ) ;
F_30 ( V_12 -> V_40 ) ;
return 0 ;
}
