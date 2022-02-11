static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_7 ;
unsigned int V_8 = V_9 ;
int V_10 , V_11 ;
if ( V_3 >= V_12 ) {
V_3 -= V_12 ;
V_8 = V_13 ;
}
V_11 = F_3 ( V_6 , V_8 , & V_10 ) ;
if ( V_11 ) {
F_4 ( V_5 -> V_2 . V_14 , L_1 ,
V_13 ) ;
return V_11 ;
}
return ! ! ( V_10 & F_5 ( V_3 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_7 ;
int V_10 , V_11 ;
if ( V_3 >= V_12 )
return 0 ;
V_11 = F_3 ( V_6 , F_7 ( V_3 ) , & V_10 ) ;
if ( V_11 ) {
F_4 ( V_5 -> V_2 . V_14 , L_1 ,
F_7 ( V_3 ) ) ;
return V_11 ;
}
V_10 &= V_15 ;
return V_10 >= V_16 ? 0 : 1 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_7 ;
unsigned int V_8 = V_9 ;
if ( V_3 >= V_12 ) {
V_8 = V_13 ;
V_3 -= V_12 ;
}
F_9 ( V_6 , V_8 , F_5 ( V_3 ) , V_17 ? F_5 ( V_3 ) : 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_7 ;
if ( V_3 >= V_12 )
return 0 ;
F_8 ( V_2 , V_3 , V_17 ) ;
return F_9 ( V_6 , F_7 ( V_3 ) ,
V_15 ,
V_16 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_7 ;
if ( V_3 >= V_12 )
return - V_18 ;
return F_9 ( V_6 , F_7 ( V_3 ) ,
V_15 , 0x00 ) ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_4 * V_5 ;
int V_11 ;
V_5 = F_13 ( & V_20 -> V_21 , sizeof( * V_5 ) ,
V_22 ) ;
if ( ! V_5 )
return - V_23 ;
V_5 -> V_7 = F_14 ( V_20 -> V_21 . V_14 ) ;
V_5 -> V_2 . V_24 = L_2 ;
V_5 -> V_2 . V_25 = V_26 ;
V_5 -> V_2 . V_27 = F_11 ;
V_5 -> V_2 . V_28 = F_10 ;
V_5 -> V_2 . V_29 = F_1 ;
V_5 -> V_2 . V_30 = F_6 ;
V_5 -> V_2 . V_31 = F_8 ;
V_5 -> V_2 . V_32 = true ;
V_5 -> V_2 . V_33 = V_34 ;
V_5 -> V_2 . V_35 = V_36 ;
V_5 -> V_2 . V_37 = - 1 ;
V_5 -> V_2 . V_14 = & V_20 -> V_21 ;
V_11 = F_15 ( & V_20 -> V_21 , & V_5 -> V_2 ,
V_5 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_20 -> V_21 , L_3 , V_11 ) ;
return V_11 ;
}
F_16 ( V_20 , V_5 ) ;
return V_11 ;
}
