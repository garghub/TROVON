static int F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
return F_2 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_4 ( & V_2 -> V_4 , V_3 , V_5 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_4 , V_2 -> V_6 . V_7 ,
V_2 -> V_6 . V_7 - 1 ,
V_2 -> V_6 . V_8 , 0 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_4 ) ;
}
struct V_9 * F_9 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_16 * V_17 = & V_2 -> V_18 -> V_17 ;
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_11 ( sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return F_12 ( - V_23 ) ;
V_21 = F_1 ( F_10 ( V_11 ) , & V_20 -> V_3 ) ;
if ( V_21 ) {
F_13 ( V_20 ) ;
F_14 ( V_17 , L_1 ) ;
return F_12 ( V_21 ) ;
}
if ( V_13 ) {
if ( F_15 ( V_15 , & V_20 -> V_3 , sizeof( V_24 ) ) ) {
F_3 ( F_10 ( V_11 ) , V_20 -> V_3 ) ;
F_14 ( V_17 , L_2 ) ;
F_13 ( V_20 ) ;
return F_12 ( - V_25 ) ;
}
}
return & V_20 -> V_26 ;
}
int F_16 ( struct V_9 * V_20 )
{
F_3 ( F_10 ( V_20 -> V_16 ) , F_17 ( V_20 ) -> V_3 ) ;
F_13 ( F_17 ( V_20 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_30 ;
int V_21 = 0 ;
V_21 = F_2 ( & V_2 -> V_31 . V_32 , & V_28 -> V_33 ) ;
if ( V_21 == - 1 )
return - V_23 ;
if ( V_28 -> V_33 > 0 )
V_28 -> V_33 = ( V_28 -> V_33 - 1 ) %
( V_2 -> V_6 . V_34 - 1 ) + 1 ;
V_30 = F_19 ( V_2 -> V_18 , V_35 , 0 ) ;
if ( ! V_30 ) {
F_14 ( & V_2 -> V_18 -> V_17 , L_3 ) ;
return - V_36 ;
}
V_28 -> V_37 = ( ( V_30 -> V_38 ) >> V_39 ) + V_28 -> V_33 ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_4 ( & V_2 -> V_31 . V_32 , V_28 -> V_33 ,
V_5 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_31 . V_32 ,
V_2 -> V_6 . V_40 ,
V_2 -> V_6 . V_40 - 1 ,
V_2 -> V_6 . V_41 , 0 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_31 . V_32 ) ;
}
