static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( 1 , V_6 -> V_7 + V_8 ) ;
F_3 ( 0x5ab9 , V_6 -> V_7 + V_9 ) ;
F_3 ( 0x03 , V_6 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( 0 , V_6 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_11 * V_2 -> V_12 ,
V_6 -> V_7 + V_8 ) ;
F_3 ( 0x5ab9 , V_6 -> V_7 + V_9 ) ;
F_3 ( 0x03 , V_6 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
V_2 -> V_12 = V_12 ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_5 * V_6 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
int V_23 ;
unsigned int V_24 ;
bool V_25 = V_26 ;
V_6 = F_8 ( V_16 , sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
F_9 ( V_14 , V_6 ) ;
V_21 = F_10 ( V_14 , V_29 , 0 ) ;
V_6 -> V_7 = F_11 ( V_16 , V_21 ) ;
if ( F_12 ( V_6 -> V_7 ) )
return F_13 ( V_6 -> V_7 ) ;
V_22 = F_14 ( V_18 , 0 ) ;
if ( F_12 ( V_22 ) ) {
F_15 ( L_1 , V_30 ) ;
return F_13 ( V_22 ) ;
}
V_6 -> V_11 = F_16 ( V_22 ) ;
if ( V_6 -> V_11 == 0 ) {
F_15 ( L_2 , V_30 ) ;
return - V_31 ;
}
V_24 = V_32 / V_6 -> V_11 ;
V_6 -> V_16 . V_33 = & V_34 ;
V_6 -> V_16 . V_35 = & V_36 ;
V_6 -> V_16 . V_12 = V_24 ;
V_6 -> V_16 . V_37 = 1 ;
V_6 -> V_16 . V_24 = V_24 ;
V_6 -> V_16 . V_38 = V_16 ;
F_17 ( & V_6 -> V_16 , V_39 , V_16 ) ;
F_18 ( & V_6 -> V_16 , V_25 ) ;
F_19 ( & V_6 -> V_16 , 128 ) ;
F_20 ( & V_6 -> V_16 , V_6 ) ;
V_23 = F_21 ( & V_6 -> V_16 ) ;
if ( V_23 )
return V_23 ;
F_22 ( V_16 , L_3 ,
V_6 -> V_16 . V_12 , V_25 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_24 ( V_14 ) ;
F_4 ( & V_6 -> V_16 ) ;
return 0 ;
}
