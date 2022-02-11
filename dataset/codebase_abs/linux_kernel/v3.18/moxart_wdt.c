static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 ,
V_7 ) ;
F_3 ( 1 , V_6 -> V_8 + V_9 ) ;
F_3 ( 0x5ab9 , V_6 -> V_8 + V_10 ) ;
F_3 ( 0x03 , V_6 -> V_8 + V_11 ) ;
return V_12 ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_5 ( V_14 ) ;
F_3 ( 0 , V_6 -> V_8 + V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_5 ( V_14 ) ;
F_3 ( V_6 -> V_15 * V_14 -> V_16 ,
V_6 -> V_8 + V_9 ) ;
F_3 ( 0x5ab9 , V_6 -> V_8 + V_10 ) ;
F_3 ( 0x03 , V_6 -> V_8 + V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
unsigned int V_16 )
{
V_14 -> V_16 = V_16 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_26 ;
int V_27 ;
unsigned int V_28 ;
bool V_29 = V_30 ;
V_6 = F_9 ( V_20 , sizeof( * V_6 ) , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
F_10 ( V_18 , V_6 ) ;
V_25 = F_11 ( V_18 , V_33 , 0 ) ;
V_6 -> V_8 = F_12 ( V_20 , V_25 ) ;
if ( F_13 ( V_6 -> V_8 ) )
return F_14 ( V_6 -> V_8 ) ;
V_26 = F_15 ( V_22 , 0 ) ;
if ( F_13 ( V_26 ) ) {
F_16 ( L_1 , V_34 ) ;
return F_14 ( V_26 ) ;
}
V_6 -> V_15 = F_17 ( V_26 ) ;
if ( V_6 -> V_15 == 0 ) {
F_16 ( L_2 , V_34 ) ;
return - V_35 ;
}
V_28 = V_36 / V_6 -> V_15 ;
V_6 -> V_20 . V_37 = & V_38 ;
V_6 -> V_20 . V_39 = & V_40 ;
V_6 -> V_20 . V_16 = V_28 ;
V_6 -> V_20 . V_41 = 1 ;
V_6 -> V_20 . V_28 = V_28 ;
V_6 -> V_20 . V_42 = V_20 ;
F_18 ( & V_6 -> V_20 , V_43 , V_20 ) ;
F_19 ( & V_6 -> V_20 , V_29 ) ;
F_20 ( & V_6 -> V_20 , V_6 ) ;
V_27 = F_21 ( & V_6 -> V_20 ) ;
if ( V_27 )
return V_27 ;
V_6 -> V_7 . V_44 = F_1 ;
V_6 -> V_7 . V_45 = 128 ;
V_27 = F_22 ( & V_6 -> V_7 ) ;
if ( V_27 )
F_23 ( V_20 , L_3 ,
V_27 ) ;
F_24 ( V_20 , L_4 ,
V_6 -> V_20 . V_16 , V_29 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_26 ( V_18 ) ;
F_27 ( & V_6 -> V_7 ) ;
F_4 ( & V_6 -> V_20 ) ;
return 0 ;
}
