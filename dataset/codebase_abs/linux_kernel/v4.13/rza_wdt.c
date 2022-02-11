static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 | 0 , V_4 -> V_6 + V_7 ) ;
F_4 ( V_4 -> V_6 + V_8 ) ;
F_3 ( V_9 , V_4 -> V_6 + V_8 ) ;
F_3 ( V_10 | V_11 , V_4 -> V_6 + V_8 ) ;
F_3 ( V_12 | 0 , V_4 -> V_6 + V_13 ) ;
F_3 ( V_5 | V_14 | V_15 | F_5 ( 7 ) ,
V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 | 0 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_12 | 0 , V_4 -> V_6 + V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_16 ,
void * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 | 0 , V_4 -> V_6 + V_7 ) ;
F_4 ( V_4 -> V_6 + V_8 ) ;
F_3 ( V_9 , V_4 -> V_6 + V_8 ) ;
F_3 ( V_10 | V_11 , V_4 -> V_6 + V_8 ) ;
F_3 ( V_12 | 255 , V_4 -> V_6 + V_13 ) ;
F_3 ( V_5 | V_14 | V_15 , V_4 -> V_6 + V_7 ) ;
F_9 () ;
F_10 ( 20 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
int V_23 ;
V_4 = F_12 ( & V_19 -> V_24 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_21 = F_13 ( V_19 , V_27 , 0 ) ;
V_4 -> V_6 = F_14 ( & V_19 -> V_24 , V_21 ) ;
if ( F_15 ( V_4 -> V_6 ) )
return F_16 ( V_4 -> V_6 ) ;
V_4 -> V_28 = F_17 ( & V_19 -> V_24 , NULL ) ;
if ( F_15 ( V_4 -> V_28 ) )
return F_16 ( V_4 -> V_28 ) ;
V_22 = F_18 ( V_4 -> V_28 ) ;
if ( V_22 < 16384 ) {
F_19 ( & V_19 -> V_24 , L_1 , V_22 ) ;
return - V_29 ;
}
V_22 /= 16384 ;
V_4 -> V_2 . V_30 = & V_31 ,
V_4 -> V_2 . V_32 = & V_33 ,
V_4 -> V_2 . V_34 = & V_19 -> V_24 ;
V_4 -> V_2 . V_35 = ( 1000 * V_36 ) / V_22 ;
F_20 ( & V_19 -> V_24 , L_2 ,
V_4 -> V_2 . V_35 ) ;
V_4 -> V_2 . V_37 = 1 ;
V_4 -> V_2 . V_38 = V_39 ;
F_21 ( & V_4 -> V_2 , 0 , & V_19 -> V_24 ) ;
F_22 ( & V_4 -> V_2 , V_4 ) ;
V_23 = F_23 ( & V_19 -> V_24 , & V_4 -> V_2 ) ;
if ( V_23 )
F_19 ( & V_19 -> V_24 , L_3 ) ;
return V_23 ;
}
