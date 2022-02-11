static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_6 -> V_7 + V_8 ) , V_4 ) ;
return F_5 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( ( V_10 ) V_9 , V_6 -> V_7 + V_11 ) ;
F_4 ( V_6 -> V_7 + V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_14 , & V_13 -> time ) ;
V_13 -> V_15 = F_4 ( V_6 -> V_7 + V_16 ) & V_17 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , V_10 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_10 V_18 ;
V_18 = F_4 ( V_6 -> V_7 + V_16 ) ;
if ( V_15 ) {
V_18 &= ~ V_19 ;
V_18 |= V_17 ;
} else {
V_18 &= ~ V_17 ;
V_18 |= V_19 ;
}
F_7 ( V_18 , V_6 -> V_7 + V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_3 ;
unsigned long V_14 ;
V_3 = F_4 ( V_6 -> V_7 + V_8 ) ;
F_11 ( & V_13 -> time , & V_14 ) ;
V_6 -> V_14 = V_14 ;
F_7 ( ( V_10 ) V_6 -> V_14 , V_6 -> V_7 + V_20 ) ;
F_9 ( V_2 , V_13 -> V_15 ) ;
return 0 ;
}
static T_1 F_12 ( int V_21 , void * V_22 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
if ( ! ( F_4 ( V_6 -> V_7 + V_23 ) & V_24 ) )
return V_25 ;
F_4 ( V_6 -> V_7 + V_26 ) ;
F_13 ( V_6 -> V_27 , 1 , V_28 | V_29 ) ;
return V_30 ;
}
static int F_14 ( struct V_31 * V_32 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_35 ;
int V_21 ;
V_6 = F_15 ( & V_32 -> V_2 , sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
F_16 ( V_32 , V_6 ) ;
V_6 -> V_2 = & V_32 -> V_2 ;
V_34 = F_17 ( V_32 , V_38 , 0 ) ;
V_6 -> V_7 = F_18 ( & V_32 -> V_2 , V_34 ) ;
if ( F_19 ( V_6 -> V_7 ) )
return F_20 ( V_6 -> V_7 ) ;
V_21 = F_21 ( V_32 , 0 ) ;
if ( V_21 < 0 ) {
F_22 ( & V_32 -> V_2 , L_1 ) ;
return V_21 ;
}
V_35 = F_23 ( & V_32 -> V_2 , V_21 , F_12 , 0 ,
F_24 ( & V_32 -> V_2 ) , V_6 ) ;
if ( V_35 ) {
F_22 ( & V_32 -> V_2 , L_2 ) ;
return V_35 ;
}
V_6 -> V_39 = F_25 ( & V_32 -> V_2 , NULL ) ;
if ( F_19 ( V_6 -> V_39 ) ) {
F_22 ( & V_32 -> V_2 , L_3 ) ;
return - V_40 ;
}
F_26 ( V_6 -> V_39 ) ;
F_7 ( V_41 , V_6 -> V_7 + V_16 ) ;
F_27 ( & V_32 -> V_2 , 1 ) ;
V_6 -> V_27 = F_28 ( & V_32 -> V_2 , V_32 -> V_42 ,
& V_43 , V_44 ) ;
if ( F_19 ( V_6 -> V_27 ) ) {
F_29 ( V_6 -> V_39 ) ;
return F_20 ( V_6 -> V_27 ) ;
}
V_6 -> V_27 -> V_45 = 1 ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_31 ( V_32 ) ;
F_9 ( & V_32 -> V_2 , 0 ) ;
F_27 ( & V_32 -> V_2 , 0 ) ;
F_29 ( V_6 -> V_39 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_33 ( V_2 ) ;
struct V_5 * V_6 = F_31 ( V_32 ) ;
int V_21 ;
V_21 = F_21 ( V_32 , 0 ) ;
if ( F_34 ( & V_32 -> V_2 ) ) {
if ( ! F_35 ( V_21 ) )
V_6 -> V_46 = 1 ;
} else {
F_9 ( V_2 , 0 ) ;
F_36 ( V_6 -> V_39 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_33 ( V_2 ) ;
struct V_5 * V_6 = F_31 ( V_32 ) ;
int V_21 ;
V_21 = F_21 ( V_32 , 0 ) ;
if ( F_34 ( & V_32 -> V_2 ) ) {
if ( V_6 -> V_46 ) {
F_38 ( V_21 ) ;
V_6 -> V_46 = 0 ;
}
} else {
F_39 ( V_6 -> V_39 ) ;
F_9 ( V_2 , 1 ) ;
}
return 0 ;
}
