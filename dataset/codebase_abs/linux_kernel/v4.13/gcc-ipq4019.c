static T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_6 , V_7 , V_8 ;
T_1 V_9 ;
F_2 ( V_2 -> V_8 . V_10 . V_11 , V_5 -> V_12 , & V_8 ) ;
V_7 = ( V_8 >> V_5 -> V_13 ) &
( F_3 ( V_5 -> V_14 ) - 1 ) ;
V_6 = ( V_8 >> V_5 -> V_15 ) &
( F_3 ( V_5 -> V_16 ) - 1 ) ;
V_9 = V_3 / V_7 ;
V_9 *= 2 ;
V_9 *= V_6 ;
return V_9 ;
}
static long F_4 ( struct V_17 * V_18 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
struct V_17 * V_22 ;
const struct V_23 * V_24 ;
V_24 = F_6 ( V_21 -> V_23 , V_19 ) ;
if ( ! V_24 )
return - V_25 ;
V_22 = F_7 ( V_18 , V_24 -> V_26 ) ;
* V_20 = F_8 ( V_22 ) ;
return V_24 -> V_27 ;
}
static int F_9 ( struct V_17 * V_18 , unsigned long V_19 ,
unsigned long V_3 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
const struct V_23 * V_24 ;
T_2 V_28 ;
int V_29 ;
V_24 = F_6 ( V_21 -> V_23 , V_19 ) ;
if ( ! V_24 )
return - V_25 ;
V_28 = ( F_3 ( V_21 -> V_8 . V_30 ) - 1 ) << V_21 -> V_8 . V_31 ;
V_29 = F_10 ( V_21 -> V_8 . V_10 . V_11 ,
V_21 -> V_8 . V_12 , V_28 ,
V_24 -> V_32 << V_21 -> V_8 . V_31 ) ;
F_11 ( 1 ) ;
return 0 ;
}
static unsigned long
F_12 ( struct V_17 * V_18 ,
unsigned long V_3 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
T_2 V_8 , V_32 ;
T_1 V_19 ;
F_2 ( V_21 -> V_8 . V_10 . V_11 , V_21 -> V_8 . V_12 , & V_8 ) ;
V_8 = ( V_8 >> V_21 -> V_8 . V_31 ) & ( F_3 ( V_21 -> V_8 . V_30 ) - 1 ) ;
if ( V_8 > 10 )
V_32 = ( V_8 + 1 ) * 2 ;
else
V_32 = V_8 + 12 ;
V_19 = F_1 ( V_21 , V_3 ) * 2 ;
F_13 ( V_19 , V_32 ) ;
return V_19 ;
}
static unsigned long
F_14 ( struct V_17 * V_18 ,
unsigned long V_3 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
T_2 V_8 , V_32 = 1 ;
T_1 V_19 ;
const struct V_33 * V_34 ;
if ( V_21 -> V_35 ) {
V_32 = V_21 -> V_35 ;
} else {
F_2 ( V_21 -> V_8 . V_10 . V_11 , V_21 -> V_8 . V_12 , & V_8 ) ;
V_8 = ( V_8 >> V_21 -> V_8 . V_31 ) & ( F_3 ( V_21 -> V_8 . V_30 ) - 1 ) ;
for ( V_34 = V_21 -> V_36 ; V_34 -> div ; V_34 ++ ) {
if ( V_34 -> V_37 == V_8 )
V_32 = V_34 -> div ;
}
}
V_19 = F_1 ( V_21 , V_3 ) ;
F_13 ( V_19 , V_32 ) ;
return V_19 ;
}
static int
F_15 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
int V_42 = 0 ;
if ( V_40 == V_43 )
V_42 = V_44 . V_45 ( & V_46 . V_10 . V_18 ,
V_47 ) ;
return F_16 ( V_42 ) ;
}
static int F_17 ( struct V_48 * V_49 )
{
int V_42 ;
V_42 = F_18 ( V_49 , & V_50 ) ;
if ( V_42 )
return V_42 ;
return F_19 ( V_46 . V_10 . V_18 . V_51 ,
& V_52 ) ;
}
static int F_20 ( struct V_48 * V_49 )
{
return F_21 ( V_46 . V_10 . V_18 . V_51 ,
& V_52 ) ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_53 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_53 ) ;
}
