static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 , V_7 = 0 , V_8 = 0 ;
unsigned long V_9 , V_10 , V_11 ;
for ( V_10 = V_4 -> V_12 ; V_10 <= V_4 -> V_13 ; V_10 ++ ) {
for ( V_9 = V_4 -> V_14 ; V_9 <= V_4 -> V_15 ; V_9 ++ ) {
for ( V_11 = V_4 -> V_16 ; V_11 <= V_4 -> V_17 ; V_11 ++ ) {
unsigned long V_18 ;
V_18 = V_1 * V_9 * V_10 / V_11 ;
if ( V_18 > V_2 )
continue;
if ( ( V_2 - V_18 ) < ( V_2 - V_5 ) ) {
V_5 = V_18 ;
V_6 = V_9 ;
V_7 = V_10 ;
V_8 = V_11 ;
}
}
}
}
V_4 -> V_19 = V_6 ;
V_4 -> V_20 = V_7 ;
V_4 -> V_21 = V_8 ;
}
static void F_2 ( struct V_22 * V_23 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_4 ( & V_4 -> V_25 , V_4 -> V_26 ) ;
}
static int F_5 ( struct V_22 * V_23 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_6 ( & V_4 -> V_25 , V_4 -> V_26 ) ;
}
static int F_7 ( struct V_22 * V_23 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_8 ( & V_4 -> V_25 , V_4 -> V_26 ) ;
}
static unsigned long F_9 ( struct V_22 * V_23 ,
unsigned long V_27 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
unsigned long V_19 , V_21 , V_20 ;
T_1 V_28 ;
V_28 = F_10 ( V_4 -> V_25 . V_29 + V_4 -> V_25 . V_28 ) ;
V_19 = V_28 >> V_4 -> V_19 . V_30 ;
V_19 &= ( 1 << V_4 -> V_19 . V_31 ) - 1 ;
V_20 = V_28 >> V_4 -> V_20 . V_30 ;
V_20 &= ( 1 << V_4 -> V_20 . V_31 ) - 1 ;
V_21 = V_28 >> V_4 -> V_21 . V_30 ;
V_21 &= ( 1 << V_4 -> V_21 . V_31 ) - 1 ;
return V_27 * ( V_19 + 1 ) * ( V_20 + 1 ) / ( V_21 + 1 ) ;
}
static unsigned long F_11 ( struct V_32 * V_33 ,
unsigned long V_27 ,
unsigned long V_2 ,
void * V_34 )
{
struct V_24 * V_4 = V_34 ;
struct V_3 V_35 ;
V_35 . V_14 = V_4 -> V_19 . V_36 ;
V_35 . V_15 = 1 << V_4 -> V_19 . V_31 ;
V_35 . V_12 = V_4 -> V_20 . V_36 ;
V_35 . V_13 = 1 << V_4 -> V_20 . V_31 ;
V_35 . V_16 = 1 ;
V_35 . V_17 = V_4 -> V_21 . V_37 ? : 1 << V_4 -> V_21 . V_31 ;
F_1 ( V_27 , V_2 , & V_35 ) ;
return V_27 * V_35 . V_19 * V_35 . V_20 / V_35 . V_21 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_38 * V_39 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_13 ( & V_4 -> V_25 , & V_4 -> V_33 ,
V_39 , F_11 , V_4 ) ;
}
static int F_14 ( struct V_22 * V_23 , unsigned long V_2 ,
unsigned long V_27 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
struct V_3 V_35 ;
unsigned long V_40 ;
T_1 V_28 ;
V_35 . V_14 = V_4 -> V_19 . V_36 ;
V_35 . V_15 = 1 << V_4 -> V_19 . V_31 ;
V_35 . V_12 = V_4 -> V_20 . V_36 ;
V_35 . V_13 = 1 << V_4 -> V_20 . V_31 ;
V_35 . V_16 = 1 ;
V_35 . V_17 = V_4 -> V_21 . V_37 ? : 1 << V_4 -> V_21 . V_31 ;
F_1 ( V_27 , V_2 , & V_35 ) ;
F_15 ( V_4 -> V_25 . V_41 , V_40 ) ;
V_28 = F_10 ( V_4 -> V_25 . V_29 + V_4 -> V_25 . V_28 ) ;
V_28 &= ~ F_16 ( V_4 -> V_19 . V_31 + V_4 -> V_19 . V_30 - 1 , V_4 -> V_19 . V_30 ) ;
V_28 &= ~ F_16 ( V_4 -> V_20 . V_31 + V_4 -> V_20 . V_30 - 1 , V_4 -> V_20 . V_30 ) ;
V_28 &= ~ F_16 ( V_4 -> V_21 . V_31 + V_4 -> V_21 . V_30 - 1 , V_4 -> V_21 . V_30 ) ;
V_28 |= ( V_35 . V_19 - 1 ) << V_4 -> V_19 . V_30 ;
V_28 |= ( V_35 . V_20 - 1 ) << V_4 -> V_20 . V_30 ;
V_28 |= ( V_35 . V_21 - 1 ) << V_4 -> V_21 . V_30 ;
F_17 ( V_28 , V_4 -> V_25 . V_29 + V_4 -> V_25 . V_28 ) ;
F_18 ( V_4 -> V_25 . V_41 , V_40 ) ;
F_19 ( & V_4 -> V_25 , V_4 -> V_41 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_22 * V_23 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_21 ( & V_4 -> V_25 , & V_4 -> V_33 ) ;
}
static int F_22 ( struct V_22 * V_23 , T_2 V_42 )
{
struct V_24 * V_4 = F_3 ( V_23 ) ;
return F_23 ( & V_4 -> V_25 , & V_4 -> V_33 , V_42 ) ;
}
