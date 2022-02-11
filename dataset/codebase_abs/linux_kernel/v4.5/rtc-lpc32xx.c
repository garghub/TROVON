static int F_1 ( struct V_1 * V_2 , struct V_3 * time )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_6 , V_7 ) ;
F_4 ( V_4 , time ) ;
return F_5 ( time ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_7 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( V_6 , V_11 ) ;
F_8 ( V_6 , V_11 , V_9 | V_12 ) ;
F_8 ( V_6 , V_7 , V_8 ) ;
F_8 ( V_6 , V_13 , 0xFFFFFFFF - V_8 ) ;
F_8 ( V_6 , V_11 , V_9 &= ~ V_12 ) ;
F_9 ( & V_6 -> V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( F_3 ( V_6 , V_16 ) , & V_15 -> time ) ;
V_15 -> V_17 = V_6 -> V_18 ;
V_15 -> V_19 = ! ! ( F_3 ( V_6 , V_20 ) &
V_21 ) ;
return F_5 ( & V_15 -> time ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_22 ;
T_1 V_9 ;
int V_23 ;
V_23 = F_12 ( & V_15 -> time , & V_22 ) ;
if ( V_23 < 0 ) {
F_13 ( V_2 , L_1 , V_23 ) ;
return V_23 ;
}
F_7 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( V_6 , V_11 ) ;
F_8 ( V_6 , V_11 , V_9 & ~ V_24 ) ;
F_8 ( V_6 , V_16 , V_22 ) ;
V_6 -> V_18 = V_15 -> V_17 ;
if ( V_15 -> V_17 ) {
F_8 ( V_6 , V_20 ,
V_21 ) ;
F_8 ( V_6 , V_11 , V_9 |
V_24 ) ;
}
F_9 ( & V_6 -> V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_7 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( V_6 , V_11 ) ;
if ( V_17 ) {
V_6 -> V_18 = 1 ;
V_9 |= V_24 ;
} else {
V_6 -> V_18 = 0 ;
V_9 &= ~ V_24 ;
}
F_8 ( V_6 , V_11 , V_9 ) ;
F_9 ( & V_6 -> V_10 ) ;
return 0 ;
}
static T_2 F_15 ( int V_25 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
F_16 ( & V_6 -> V_10 ) ;
F_8 ( V_6 , V_11 ,
F_3 ( V_6 , V_11 ) &
~ V_24 ) ;
V_6 -> V_18 = 0 ;
F_8 ( V_6 , V_16 , 0xFFFFFFFF ) ;
F_8 ( V_6 , V_20 , V_21 ) ;
F_17 ( & V_6 -> V_10 ) ;
F_18 ( V_6 -> V_6 , 1 , V_26 | V_27 ) ;
return V_28 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_5 * V_6 ;
int V_33 ;
T_1 V_9 ;
V_33 = F_20 ( V_30 , 0 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_30 -> V_2 , L_2 ) ;
V_33 = - 1 ;
}
V_6 = F_21 ( & V_30 -> V_2 , sizeof( * V_6 ) , V_34 ) ;
if ( F_22 ( ! V_6 ) )
return - V_35 ;
V_6 -> V_25 = V_33 ;
V_32 = F_23 ( V_30 , V_36 , 0 ) ;
V_6 -> V_37 = F_24 ( & V_30 -> V_2 , V_32 ) ;
if ( F_25 ( V_6 -> V_37 ) )
return F_26 ( V_6 -> V_37 ) ;
F_27 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( V_6 , V_11 ) ;
if ( F_3 ( V_6 , V_38 ) != V_39 ) {
V_9 &= ~ ( V_40 |
V_12 |
V_24 |
V_41 |
V_42 |
V_43 |
V_44 ) ;
F_8 ( V_6 , V_11 , V_9 ) ;
F_8 ( V_6 , V_16 , 0xFFFFFFFF ) ;
F_8 ( V_6 , V_20 ,
V_21 |
V_45 |
V_46 ) ;
F_8 ( V_6 , V_38 ,
V_39 ) ;
} else {
F_8 ( V_6 , V_11 ,
V_9 & ~ V_24 ) ;
}
F_28 ( V_30 , V_6 ) ;
V_6 -> V_6 = F_29 ( & V_30 -> V_2 , V_47 ,
& V_48 , V_49 ) ;
if ( F_25 ( V_6 -> V_6 ) ) {
F_30 ( & V_30 -> V_2 , L_3 ) ;
return F_26 ( V_6 -> V_6 ) ;
}
if ( V_6 -> V_25 >= 0 ) {
if ( F_31 ( & V_30 -> V_2 , V_6 -> V_25 ,
F_15 ,
0 , V_30 -> V_50 , V_6 ) < 0 ) {
F_13 ( & V_30 -> V_2 , L_4 ) ;
V_6 -> V_25 = - 1 ;
} else {
F_32 ( & V_30 -> V_2 , 1 ) ;
}
}
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_34 ( V_30 ) ;
if ( V_6 -> V_25 >= 0 )
F_32 ( & V_30 -> V_2 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
struct V_5 * V_6 = F_34 ( V_30 ) ;
if ( V_6 -> V_25 >= 0 ) {
if ( F_37 ( & V_30 -> V_2 ) )
F_38 ( V_6 -> V_25 ) ;
else
F_39 ( V_6 -> V_25 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
struct V_5 * V_6 = F_34 ( V_30 ) ;
if ( V_6 -> V_25 >= 0 && F_37 ( & V_30 -> V_2 ) )
F_39 ( V_6 -> V_25 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
struct V_5 * V_6 = F_34 ( V_30 ) ;
F_7 ( & V_6 -> V_10 ) ;
F_8 ( V_6 , V_11 ,
F_3 ( V_6 , V_11 ) &
~ V_24 ) ;
F_9 ( & V_6 -> V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
struct V_5 * V_6 = F_34 ( V_30 ) ;
if ( V_6 -> V_18 ) {
F_7 ( & V_6 -> V_10 ) ;
F_8 ( V_6 , V_11 ,
F_3 ( V_6 , V_11 ) |
V_24 ) ;
F_9 ( & V_6 -> V_10 ) ;
}
return 0 ;
}
