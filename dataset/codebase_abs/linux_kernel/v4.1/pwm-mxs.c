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
V_13 = V_12 / V_15 [ div ] ;
V_13 = V_13 * V_6 ;
F_4 ( V_13 , 1000000000 ) ;
if ( V_13 < V_16 )
break;
div ++ ;
if ( div >= V_17 )
return - V_18 ;
}
V_10 = V_13 ;
V_13 *= V_5 ;
F_4 ( V_13 , V_6 ) ;
V_11 = V_13 ;
if ( ! F_5 ( V_19 , & V_4 -> V_20 ) ) {
V_9 = F_6 ( V_8 -> V_14 ) ;
if ( V_9 )
return V_9 ;
}
F_7 ( V_11 << 16 ,
V_8 -> V_21 + V_22 + V_4 -> V_23 * 0x20 ) ;
F_7 ( F_8 ( V_10 ) | V_24 |
V_25 | F_9 ( div ) ,
V_8 -> V_21 + V_26 + V_4 -> V_23 * 0x20 ) ;
if ( ! F_5 ( V_19 , & V_4 -> V_20 ) )
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
F_7 ( 1 << V_4 -> V_23 , V_8 -> V_21 + V_27 + V_28 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( 1 << V_4 -> V_23 , V_8 -> V_21 + V_27 + V_29 ) ;
F_10 ( V_8 -> V_14 ) ;
}
static int F_13 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_34 . V_35 ;
struct V_7 * V_8 ;
struct V_36 * V_37 ;
int V_9 ;
V_8 = F_14 ( & V_31 -> V_34 , sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return - V_39 ;
V_37 = F_15 ( V_31 , V_40 , 0 ) ;
V_8 -> V_21 = F_16 ( & V_31 -> V_34 , V_37 ) ;
if ( F_17 ( V_8 -> V_21 ) )
return F_18 ( V_8 -> V_21 ) ;
V_8 -> V_14 = F_19 ( & V_31 -> V_34 , NULL ) ;
if ( F_17 ( V_8 -> V_14 ) )
return F_18 ( V_8 -> V_14 ) ;
V_8 -> V_2 . V_34 = & V_31 -> V_34 ;
V_8 -> V_2 . V_41 = & V_42 ;
V_8 -> V_2 . V_21 = - 1 ;
V_8 -> V_2 . V_43 = true ;
V_9 = F_20 ( V_33 , L_1 , & V_8 -> V_2 . V_44 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_31 -> V_34 , L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_22 ( & V_8 -> V_2 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_31 -> V_34 , L_3 , V_9 ) ;
return V_9 ;
}
F_23 ( V_31 , V_8 ) ;
V_9 = F_24 ( V_8 -> V_21 ) ;
if ( V_9 )
goto V_45;
return 0 ;
V_45:
F_25 ( & V_8 -> V_2 ) ;
return V_9 ;
}
static int F_26 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = F_27 ( V_31 ) ;
return F_25 ( & V_8 -> V_2 ) ;
}
