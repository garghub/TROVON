static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
F_3 ( L_1 , V_9 , V_10 ,
V_6 , V_8 ) ;
return F_4 ( V_5 -> V_11 ,
V_5 -> V_8 + ( V_6 * 4 ) ,
F_5 ( V_8 ) ,
F_5 ( V_8 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
F_3 ( L_1 , V_9 , V_10 ,
V_6 , V_8 ) ;
return F_4 ( V_5 -> V_11 ,
V_5 -> V_8 + ( V_6 * 4 ) ,
F_5 ( V_8 ) ,
~ F_5 ( V_8 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
int V_12 ;
T_1 V_13 ;
F_3 ( L_1 , V_9 , V_10 ,
V_6 , V_8 ) ;
V_12 = F_8 ( V_5 -> V_11 , V_5 -> V_8 + ( V_6 * 4 ) , & V_13 ) ;
if ( V_12 )
return V_12 ;
return ! ! ( V_13 & F_5 ( V_8 ) ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_4 * V_5 ;
V_5 = F_10 ( & V_15 -> V_18 , sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
F_11 ( V_15 , V_5 ) ;
V_5 -> V_11 = F_12 ( V_15 -> V_18 . V_21 ,
L_2 ) ;
if ( F_13 ( V_5 -> V_11 ) ) {
F_14 ( & V_15 -> V_18 , L_3 ) ;
return F_15 ( V_5 -> V_11 ) ;
}
V_17 = F_16 ( V_15 , V_22 , 0 ) ;
if ( ! V_17 ) {
F_14 ( & V_15 -> V_18 , L_4 ) ;
return - V_23 ;
}
V_5 -> V_8 = V_17 -> V_24 ;
V_5 -> V_2 . V_25 = V_26 ;
V_5 -> V_2 . V_27 = F_17 ( V_17 ) / 4 * V_7 ;
V_5 -> V_2 . V_28 = & V_29 ;
V_5 -> V_2 . V_21 = V_15 -> V_18 . V_21 ;
F_18 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = F_20 ( V_15 ) ;
F_21 ( & V_5 -> V_2 ) ;
return 0 ;
}
