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
static long F_5 ( struct V_2 * V_3 , unsigned long V_13 ,
unsigned long * V_14 ,
struct V_2 * * V_15 )
{
int V_16 = F_6 ( V_3 -> V_5 ) ;
long V_17 = - V_18 ;
int V_19 ;
* V_15 = NULL ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
unsigned long V_4 ;
unsigned long V_20 ;
struct V_5 * V_21 ;
unsigned long div ;
int V_8 ;
V_21 = F_7 ( V_3 -> V_5 , V_19 ) ;
V_4 = F_8 ( V_21 ) ;
div = F_9 ( V_4 , V_13 ) ;
V_8 = F_10 ( div ) - 1 ;
if ( V_8 > V_22 )
V_8 = V_22 ;
div >>= V_8 ;
while ( div > V_23 ) {
V_8 ++ ;
div >>= 1 ;
if ( V_8 > V_22 )
break;
}
if ( V_8 > V_22 )
continue;
V_20 = ( V_4 >> V_8 ) / div ;
if ( ! * V_15 || V_20 > V_17 ) {
* V_15 = F_11 ( V_21 ) ;
* V_14 = V_4 ;
V_17 = V_20 ;
}
}
return V_17 ;
}
static int F_12 ( struct V_2 * V_3 , T_2 V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_6 = F_4 ( V_5 -> V_7 ) ;
if ( V_24 >= V_25 )
return - V_18 ;
V_6 &= ~ ( V_26 << V_27 ) ;
V_6 |= ( V_24 << V_27 ) ;
F_13 ( V_6 , V_5 -> V_7 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ( F_4 ( V_5 -> V_7 ) >> V_27 ) &
V_26 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned long V_13 ,
unsigned long V_4 )
{
unsigned long div = V_4 / V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_6 = F_4 ( V_5 -> V_7 ) ;
int V_8 ;
if ( V_4 % V_13 )
return - V_18 ;
V_8 = F_10 ( div ) - 1 ;
if ( V_8 > V_22 )
V_8 = V_22 ;
div >>= V_8 ;
if ( div > V_23 )
return - V_18 ;
V_6 &= ~ ( ( V_10 << V_9 ) |
( V_12 << V_11 ) ) ;
V_6 |= ( V_8 << V_9 ) |
( div << V_11 ) ;
F_13 ( V_6 , V_5 -> V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_29 )
{
const char * V_30 [ V_25 ] ;
struct V_31 * V_32 = V_29 -> V_33 . V_34 ;
const char * V_35 = V_32 -> V_36 ;
struct V_37 V_38 ;
struct V_1 * V_39 ;
struct V_40 * V_41 ;
struct V_5 * V_5 ;
int V_16 ;
int V_19 ;
V_39 = F_17 ( & V_29 -> V_33 , sizeof( * V_39 ) , V_42 ) ;
if ( ! V_39 )
return - V_43 ;
V_41 = F_18 ( V_29 , V_44 , 0 ) ;
V_39 -> V_7 = F_19 ( & V_29 -> V_33 , V_41 ) ;
if ( F_20 ( V_39 -> V_7 ) )
return F_21 ( V_39 -> V_7 ) ;
V_16 = F_22 ( V_32 ) ;
if ( V_16 > V_25 )
V_16 = V_25 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_30 [ V_19 ] = F_23 ( V_32 , V_19 ) ;
F_24 ( V_32 , L_1 , & V_35 ) ;
V_38 . V_36 = V_35 ;
V_38 . V_45 = & V_46 ;
V_38 . V_47 = V_30 ;
V_38 . V_48 = V_16 ;
V_38 . V_49 = 0 ;
V_39 -> V_3 . V_38 = & V_38 ;
V_5 = F_25 ( & V_29 -> V_33 , & V_39 -> V_3 ) ;
if ( F_20 ( V_5 ) )
return F_21 ( V_5 ) ;
return F_26 ( V_32 , V_50 , V_5 ) ;
}
