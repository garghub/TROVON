static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = sizeof( V_7 ) ;
int V_8 = V_3 / ( V_6 * V_9 ) ;
int V_10 = V_3 % ( V_6 * V_9 ) ;
unsigned long V_11 ;
V_7 V_12 ;
F_3 ( & V_5 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_5 -> V_14 + ( V_8 * V_15 ) ) ;
F_5 ( V_12 | F_6 ( V_10 ) , V_5 -> V_14 + ( V_8 * V_15 ) ) ;
F_7 ( & V_5 -> V_13 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = sizeof( V_7 ) ;
int V_8 = V_3 / ( V_6 * V_9 ) ;
int V_10 = V_3 % ( V_6 * V_9 ) ;
unsigned long V_11 ;
V_7 V_12 ;
F_3 ( & V_5 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_5 -> V_14 + ( V_8 * V_15 ) ) ;
F_5 ( V_12 & ~ F_6 ( V_10 ) , V_5 -> V_14 + ( V_8 * V_15 ) ) ;
F_7 ( & V_5 -> V_13 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 , V_2 ) ;
int V_6 = sizeof( V_7 ) ;
int V_8 = V_3 / ( V_6 * V_9 ) ;
int V_10 = V_3 % ( V_6 * V_9 ) ;
V_7 V_12 ;
V_12 = F_4 ( V_5 -> V_14 + ( V_8 * V_15 ) ) ;
return ! ( V_12 & F_6 ( V_10 ) ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_17 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
V_7 V_25 ;
if ( ! F_11 ( V_17 -> V_21 . V_24 , L_1 , NULL ) ) {
F_12 ( & V_17 -> V_21 , L_2 ,
V_17 -> V_21 . V_24 ) ;
return - V_26 ;
}
V_5 = F_13 ( & V_17 -> V_21 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
V_19 = F_14 ( V_17 , V_29 , 0 ) ;
V_5 -> V_14 = F_15 ( & V_17 -> V_21 , V_19 ) ;
if ( F_16 ( V_5 -> V_14 ) )
return F_17 ( V_5 -> V_14 ) ;
if ( F_18 ( V_23 , L_3 , & V_25 ) ) {
F_19 ( V_21 , L_4 ) ;
V_25 = 0x10 ;
}
V_5 -> V_14 += V_25 ;
F_20 ( & V_5 -> V_13 ) ;
V_5 -> V_2 . V_30 = V_31 ;
V_5 -> V_2 . V_32 = V_33 * ( sizeof( V_7 ) * V_9 ) ;
V_5 -> V_2 . V_34 = & V_35 ;
V_5 -> V_2 . V_24 = V_17 -> V_21 . V_24 ;
return F_21 ( V_21 , & V_5 -> V_2 ) ;
}
