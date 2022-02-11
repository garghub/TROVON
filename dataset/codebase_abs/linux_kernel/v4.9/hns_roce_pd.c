static int F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
return F_2 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_4 , V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_6 - 1 ,
V_2 -> V_5 . V_7 , 0 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_4 ) ;
}
struct V_8 * F_9 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_15 * V_16 = & V_2 -> V_17 -> V_16 ;
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_11 ( sizeof( * V_19 ) , V_21 ) ;
if ( ! V_19 )
return F_12 ( - V_22 ) ;
V_20 = F_1 ( F_10 ( V_10 ) , & V_19 -> V_3 ) ;
if ( V_20 ) {
F_13 ( V_19 ) ;
F_14 ( V_16 , L_1 ) ;
return F_12 ( V_20 ) ;
}
if ( V_12 ) {
if ( F_15 ( V_14 , & V_19 -> V_3 , sizeof( V_23 ) ) ) {
F_3 ( F_10 ( V_10 ) , V_19 -> V_3 ) ;
F_14 ( V_16 , L_2 ) ;
F_13 ( V_19 ) ;
return F_12 ( - V_24 ) ;
}
}
return & V_19 -> V_25 ;
}
int F_16 ( struct V_8 * V_19 )
{
F_3 ( F_10 ( V_19 -> V_15 ) , F_17 ( V_19 ) -> V_3 ) ;
F_13 ( F_17 ( V_19 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_20 = 0 ;
V_20 = F_2 ( & V_2 -> V_30 . V_31 , & V_27 -> V_32 ) ;
if ( V_20 == - 1 )
return - V_22 ;
if ( V_27 -> V_32 > 0 )
V_27 -> V_32 = ( V_27 -> V_32 - 1 ) %
( V_2 -> V_5 . V_33 - 1 ) + 1 ;
V_29 = F_19 ( V_2 -> V_17 , V_34 , 0 ) ;
if ( ! V_29 ) {
F_14 ( & V_2 -> V_17 -> V_16 , L_3 ) ;
return - V_35 ;
}
V_27 -> V_36 = ( ( V_29 -> V_37 ) >> V_38 ) + V_27 -> V_32 ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
F_4 ( & V_2 -> V_30 . V_31 , V_27 -> V_32 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_30 . V_31 ,
V_2 -> V_5 . V_39 ,
V_2 -> V_5 . V_39 - 1 ,
V_2 -> V_5 . V_40 , 0 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_30 . V_31 ) ;
}
