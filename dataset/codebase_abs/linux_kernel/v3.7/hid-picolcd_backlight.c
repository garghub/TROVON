static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_4 ( V_8 , V_4 -> V_9 ) ;
unsigned long V_10 ;
if ( ! V_7 || V_7 -> V_11 != 1 || V_7 -> V_12 [ 0 ] -> V_13 != 1 )
return - V_14 ;
V_4 -> V_5 = V_2 -> V_15 . V_16 & 0x0ff ;
V_4 -> V_17 = V_2 -> V_15 . V_18 ;
F_5 ( & V_4 -> V_19 , V_10 ) ;
F_6 ( V_7 -> V_12 [ 0 ] , 0 , V_4 -> V_17 == V_20 ? V_4 -> V_5 : 0 ) ;
if ( ! ( V_4 -> V_21 & V_22 ) )
F_7 ( V_4 -> V_9 , V_7 , V_23 ) ;
F_8 ( & V_4 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
return V_25 && V_25 == F_10 ( (struct V_3 * ) F_2 ( V_2 ) ) ;
}
int F_11 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
struct V_26 * V_27 = & V_4 -> V_9 -> V_27 ;
struct V_1 * V_2 ;
struct V_28 V_15 ;
if ( ! V_7 )
return - V_14 ;
if ( V_7 -> V_11 != 1 || V_7 -> V_12 [ 0 ] -> V_13 != 1 ||
V_7 -> V_12 [ 0 ] -> V_29 != 8 ) {
F_12 ( V_27 , L_1 ) ;
return - V_30 ;
}
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . type = V_31 ;
V_15 . V_32 = 0xff ;
V_2 = F_13 ( F_14 ( V_27 ) , V_27 , V_4 ,
& V_33 , & V_15 ) ;
if ( F_15 ( V_2 ) ) {
F_12 ( V_27 , L_2 ) ;
return F_16 ( V_2 ) ;
}
V_2 -> V_15 . V_16 = 0xff ;
V_4 -> V_5 = 0xff ;
V_4 -> V_34 = V_2 ;
F_3 ( V_2 ) ;
return 0 ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_34 ;
V_4 -> V_34 = NULL ;
if ( V_2 )
F_18 ( V_2 ) ;
}
int F_19 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_34 )
return 0 ;
return F_3 ( V_4 -> V_34 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
int V_35 = V_4 -> V_17 ;
if ( ! V_4 -> V_34 )
return;
V_4 -> V_34 -> V_15 . V_18 = V_36 ;
F_3 ( V_4 -> V_34 ) ;
V_4 -> V_17 = V_4 -> V_34 -> V_15 . V_18 = V_35 ;
}
