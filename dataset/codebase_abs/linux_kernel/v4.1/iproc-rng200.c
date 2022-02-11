static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 &= ~ V_4 ;
V_2 |= V_5 ;
F_3 ( V_2 , V_1 + V_3 ) ;
F_3 ( 0xFFFFFFFFUL , V_1 + V_6 ) ;
V_2 = F_2 ( V_1 + V_7 ) ;
V_2 |= V_8 ;
F_3 ( V_2 , V_1 + V_7 ) ;
V_2 = F_2 ( V_1 + V_9 ) ;
V_2 |= V_10 ;
F_3 ( V_2 , V_1 + V_9 ) ;
V_2 = F_2 ( V_1 + V_9 ) ;
V_2 &= ~ V_10 ;
F_3 ( V_2 , V_1 + V_9 ) ;
V_2 = F_2 ( V_1 + V_7 ) ;
V_2 &= ~ V_8 ;
F_3 ( V_2 , V_1 + V_7 ) ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 &= ~ V_4 ;
V_2 |= V_11 ;
F_3 ( V_2 , V_1 + V_3 ) ;
}
static int F_4 ( struct V_12 * V_13 , void * V_14 , T_3 V_15 ,
bool V_16 )
{
struct V_17 * V_18 = F_5 ( V_13 ) ;
T_2 V_19 = V_15 ;
T_2 V_20 ;
#define F_6 1
T_2 V_21 = 0 ;
#define F_7 (1 * HZ)
unsigned long V_22 = V_23 + F_7 ;
while ( ( V_19 > 0 ) && F_8 ( V_23 , V_22 ) ) {
V_20 = F_2 ( V_18 -> V_24 + V_6 ) ;
if ( ( V_20 & ( V_25 |
V_26 ) ) != 0 ) {
if ( V_21 >= F_6 )
return V_15 - V_19 ;
F_1 ( V_18 -> V_24 ) ;
V_21 ++ ;
}
if ( ( F_2 ( V_18 -> V_24 + V_27 ) &
V_28 ) > 0 ) {
if ( V_19 >= sizeof( T_2 ) ) {
* ( T_2 * ) V_14 = F_2 ( V_18 -> V_24 +
V_29 ) ;
V_14 += sizeof( T_2 ) ;
V_19 -= sizeof( T_2 ) ;
} else {
T_2 V_30 = F_2 ( V_18 -> V_24 +
V_29 ) ;
memcpy ( V_14 , & V_30 , V_19 ) ;
V_14 += V_19 ;
V_19 = 0 ;
}
V_22 = V_23 + F_7 ;
} else {
if ( ! V_16 )
return V_15 - V_19 ;
F_9 ( F_10 ( V_19 * 10 , 500U ) , 500 ) ;
}
}
return V_15 - V_19 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_5 ( V_13 ) ;
T_2 V_2 ;
V_2 = F_2 ( V_18 -> V_24 + V_3 ) ;
V_2 &= ~ V_4 ;
V_2 |= V_11 ;
F_3 ( V_2 , V_18 -> V_24 + V_3 ) ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_5 ( V_13 ) ;
T_2 V_2 ;
V_2 = F_2 ( V_18 -> V_24 + V_3 ) ;
V_2 &= ~ V_4 ;
V_2 |= V_5 ;
F_3 ( V_2 , V_18 -> V_24 + V_3 ) ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = & V_32 -> V_36 ;
int V_37 ;
V_18 = F_14 ( V_36 , sizeof( * V_18 ) , V_38 ) ;
if ( ! V_18 )
return - V_39 ;
V_34 = F_15 ( V_32 , V_40 , 0 ) ;
if ( ! V_34 ) {
F_16 ( V_36 , L_1 ) ;
return - V_41 ;
}
V_18 -> V_24 = F_17 ( V_36 , V_34 ) ;
if ( F_18 ( V_18 -> V_24 ) ) {
F_16 ( V_36 , L_2 ) ;
return F_19 ( V_18 -> V_24 ) ;
}
V_18 -> V_13 . V_42 = L_3 ,
V_18 -> V_13 . V_43 = F_4 ,
V_18 -> V_13 . V_44 = F_11 ,
V_18 -> V_13 . V_45 = F_12 ,
V_37 = F_20 ( V_36 , & V_18 -> V_13 ) ;
if ( V_37 ) {
F_16 ( V_36 , L_4 ) ;
return V_37 ;
}
F_21 ( V_36 , L_5 ) ;
return 0 ;
}
