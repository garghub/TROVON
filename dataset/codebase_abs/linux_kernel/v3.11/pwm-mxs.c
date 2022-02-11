static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 , div = 0 ;
unsigned int V_10 , V_11 ;
unsigned long V_12 ;
unsigned long long V_13 ;
V_12 = F_3 ( V_8 -> V_14 ) ;
while ( 1 ) {
V_13 = V_12 / ( 1 << div ) ;
V_13 = V_13 * V_6 ;
F_4 ( V_13 , 1000000000 ) ;
if ( V_13 < V_15 )
break;
div ++ ;
if ( div > V_16 )
return - V_17 ;
}
V_10 = V_13 ;
V_13 *= V_5 ;
F_4 ( V_13 , V_6 ) ;
V_11 = V_13 ;
if ( ! F_5 ( V_18 , & V_4 -> V_19 ) ) {
V_9 = F_6 ( V_8 -> V_14 ) ;
if ( V_9 )
return V_9 ;
}
F_7 ( V_11 << 16 ,
V_8 -> V_20 + V_21 + V_4 -> V_22 * 0x20 ) ;
F_7 ( F_8 ( V_10 ) | V_23 |
V_24 | F_9 ( div ) ,
V_8 -> V_20 + V_25 + V_4 -> V_22 * 0x20 ) ;
if ( ! F_5 ( V_18 , & V_4 -> V_19 ) )
F_10 ( V_8 -> V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_6 ( V_8 -> V_14 ) ;
if ( V_9 )
return V_9 ;
F_7 ( 1 << V_4 -> V_22 , V_8 -> V_20 + V_26 + V_27 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( 1 << V_4 -> V_22 , V_8 -> V_20 + V_26 + V_28 ) ;
F_10 ( V_8 -> V_14 ) ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 . V_34 ;
struct V_7 * V_8 ;
struct V_35 * V_36 ;
int V_9 ;
V_8 = F_14 ( & V_30 -> V_33 , sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return - V_38 ;
V_36 = F_15 ( V_30 , V_39 , 0 ) ;
V_8 -> V_20 = F_16 ( & V_30 -> V_33 , V_36 ) ;
if ( F_17 ( V_8 -> V_20 ) )
return F_18 ( V_8 -> V_20 ) ;
V_8 -> V_14 = F_19 ( & V_30 -> V_33 , NULL ) ;
if ( F_17 ( V_8 -> V_14 ) )
return F_18 ( V_8 -> V_14 ) ;
V_8 -> V_2 . V_33 = & V_30 -> V_33 ;
V_8 -> V_2 . V_40 = & V_41 ;
V_8 -> V_2 . V_20 = - 1 ;
V_9 = F_20 ( V_32 , L_1 , & V_8 -> V_2 . V_42 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_30 -> V_33 , L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_22 ( & V_8 -> V_2 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_30 -> V_33 , L_3 , V_9 ) ;
return V_9 ;
}
F_23 ( V_30 , V_8 ) ;
F_24 ( V_8 -> V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = F_26 ( V_30 ) ;
return F_27 ( & V_8 -> V_2 ) ;
}
