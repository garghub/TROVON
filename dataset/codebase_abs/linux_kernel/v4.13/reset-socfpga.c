static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * V_13 ) ) ;
F_5 ( V_10 | F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * V_13 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * V_13 ) ) ;
F_5 ( V_10 & ~ F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * V_13 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 , V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
T_1 V_10 ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * V_13 ) ) ;
return ! ( V_10 & F_6 ( V_8 ) ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = & V_15 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
T_1 V_23 ;
if ( ! F_11 ( V_15 -> V_19 . V_22 , L_1 , NULL ) ) {
F_12 ( & V_15 -> V_19 , L_2 ,
V_15 -> V_19 . V_22 -> V_24 ) ;
return - V_25 ;
}
V_5 = F_13 ( & V_15 -> V_19 , sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return - V_27 ;
V_17 = F_14 ( V_15 , V_28 , 0 ) ;
V_5 -> V_12 = F_15 ( & V_15 -> V_19 , V_17 ) ;
if ( F_16 ( V_5 -> V_12 ) )
return F_17 ( V_5 -> V_12 ) ;
if ( F_18 ( V_21 , L_3 , & V_23 ) ) {
F_19 ( V_19 , L_4 ) ;
V_23 = 0x10 ;
}
V_5 -> V_12 += V_23 ;
F_20 ( & V_5 -> V_11 ) ;
V_5 -> V_2 . V_29 = V_30 ;
V_5 -> V_2 . V_31 = V_32 * V_7 ;
V_5 -> V_2 . V_33 = & V_34 ;
V_5 -> V_2 . V_22 = V_15 -> V_19 . V_22 ;
return F_21 ( V_19 , & V_5 -> V_2 ) ;
}
