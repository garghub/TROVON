static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static unsigned long F_3 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_6 = F_4 ( V_5 -> V_7 ) ;
int V_8 = ( V_6 >> V_9 ) & V_10 ;
int div = ( V_6 >> V_11 ) & V_12 ;
return ( V_4 >> V_8 ) / ( div + 1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
int V_15 = F_6 ( V_3 ) ;
long V_16 = - V_17 ;
int V_18 ;
V_14 -> V_19 = NULL ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
unsigned long V_4 ;
unsigned long V_20 ;
struct V_2 * V_21 ;
unsigned long div ;
int V_8 ;
V_21 = F_7 ( V_3 , V_18 ) ;
V_4 = F_8 ( V_21 ) ;
div = F_9 ( V_4 , V_14 -> V_22 ) ;
V_8 = F_10 ( div ) - 1 ;
if ( V_8 > V_23 )
V_8 = V_23 ;
div >>= V_8 ;
while ( div > V_24 ) {
V_8 ++ ;
div >>= 1 ;
if ( V_8 > V_23 )
break;
}
if ( V_8 > V_23 )
continue;
V_20 = ( V_4 >> V_8 ) / div ;
if ( ! V_14 -> V_19 || V_20 > V_16 ) {
V_14 -> V_19 = V_21 ;
V_14 -> V_25 = V_4 ;
V_16 = V_20 ;
}
}
if ( V_16 < 0 )
return V_16 ;
V_14 -> V_22 = V_16 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , T_2 V_26 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_6 = F_4 ( V_5 -> V_7 ) ;
if ( V_26 >= V_27 )
return - V_17 ;
V_6 &= ~ ( V_28 << V_29 ) ;
V_6 |= ( V_26 << V_29 ) ;
F_12 ( V_6 , V_5 -> V_7 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ( F_4 ( V_5 -> V_7 ) >> V_29 ) &
V_28 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned long V_22 ,
unsigned long V_4 )
{
unsigned long div = V_4 / V_22 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_6 = F_4 ( V_5 -> V_7 ) ;
int V_8 ;
if ( V_4 % V_22 )
return - V_17 ;
V_8 = F_10 ( div ) - 1 ;
if ( V_8 > V_23 )
V_8 = V_23 ;
div >>= V_8 ;
if ( div > V_24 )
return - V_17 ;
V_6 &= ~ ( ( V_10 << V_9 ) |
( V_12 << V_11 ) ) ;
V_6 |= ( V_8 << V_9 ) |
( div << V_11 ) ;
F_12 ( V_6 , V_5 -> V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_30 * V_31 )
{
const char * V_32 [ V_27 ] ;
struct V_33 * V_34 = V_31 -> V_35 . V_36 ;
const char * V_37 = V_34 -> V_38 ;
struct V_39 V_40 ;
struct V_1 * V_41 ;
struct V_42 * V_43 ;
struct V_5 * V_5 ;
int V_15 ;
V_41 = F_16 ( & V_31 -> V_35 , sizeof( * V_41 ) , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_43 = F_17 ( V_31 , V_46 , 0 ) ;
V_41 -> V_7 = F_18 ( & V_31 -> V_35 , V_43 ) ;
if ( F_19 ( V_41 -> V_7 ) )
return F_20 ( V_41 -> V_7 ) ;
V_15 = F_21 ( V_34 ) ;
if ( V_15 > V_27 )
V_15 = V_27 ;
F_22 ( V_34 , V_32 , V_15 ) ;
F_23 ( V_34 , L_1 , & V_37 ) ;
V_40 . V_38 = V_37 ;
V_40 . V_47 = & V_48 ;
V_40 . V_49 = V_32 ;
V_40 . V_50 = V_15 ;
V_40 . V_51 = 0 ;
V_41 -> V_3 . V_40 = & V_40 ;
V_5 = F_24 ( & V_31 -> V_35 , & V_41 -> V_3 ) ;
if ( F_19 ( V_5 ) )
return F_20 ( V_5 ) ;
return F_25 ( V_34 , V_52 , V_5 ) ;
}
