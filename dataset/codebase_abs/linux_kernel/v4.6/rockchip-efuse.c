static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
return 0 ;
}
static int F_2 ( void * V_1 ,
const void * V_4 , T_1 V_5 ,
void * V_6 , T_1 V_7 )
{
unsigned int V_8 = * ( V_9 * ) V_4 ;
struct V_10 * V_11 = V_1 ;
T_2 * V_12 = V_6 ;
int V_13 ;
V_13 = F_3 ( V_11 -> V_14 ) ;
if ( V_13 < 0 ) {
F_4 ( V_11 -> V_15 , L_1 ) ;
return V_13 ;
}
F_5 ( V_16 | V_17 , V_11 -> V_18 + V_19 ) ;
F_6 ( 1 ) ;
while ( V_7 ) {
F_5 ( F_7 ( V_11 -> V_18 + V_19 ) &
( ~ ( V_20 << V_21 ) ) ,
V_11 -> V_18 + V_19 ) ;
F_5 ( F_7 ( V_11 -> V_18 + V_19 ) |
( ( V_8 & V_20 ) << V_21 ) ,
V_11 -> V_18 + V_19 ) ;
F_6 ( 1 ) ;
F_5 ( F_7 ( V_11 -> V_18 + V_19 ) |
V_22 , V_11 -> V_18 + V_19 ) ;
F_6 ( 1 ) ;
* V_12 ++ = F_8 ( V_11 -> V_18 + V_23 ) ;
F_5 ( F_7 ( V_11 -> V_18 + V_19 ) &
( ~ V_22 ) , V_11 -> V_18 + V_19 ) ;
F_6 ( 1 ) ;
V_7 -= 1 ;
V_8 += 1 ;
}
F_5 ( V_17 | V_24 , V_11 -> V_18 + V_19 ) ;
F_9 ( V_11 -> V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_31 ;
struct V_10 * V_11 ;
V_11 = F_11 ( & V_26 -> V_15 , sizeof( struct V_10 ) ,
V_32 ) ;
if ( ! V_11 )
return - V_33 ;
V_28 = F_12 ( V_26 , V_34 , 0 ) ;
V_11 -> V_18 = F_13 ( & V_26 -> V_15 , V_28 ) ;
if ( F_14 ( V_11 -> V_18 ) )
return F_15 ( V_11 -> V_18 ) ;
V_11 -> V_14 = F_16 ( & V_26 -> V_15 , L_2 ) ;
if ( F_14 ( V_11 -> V_14 ) )
return F_15 ( V_11 -> V_14 ) ;
V_11 -> V_15 = & V_26 -> V_15 ;
V_35 . V_36 = F_17 ( V_28 ) - 1 ;
V_31 = F_18 ( V_11 -> V_15 , & V_37 ,
V_11 , & V_35 ) ;
if ( F_14 ( V_31 ) ) {
F_4 ( V_11 -> V_15 , L_3 ) ;
return F_15 ( V_31 ) ;
}
V_38 . V_15 = V_11 -> V_15 ;
V_30 = F_19 ( & V_38 ) ;
if ( F_14 ( V_30 ) )
return F_15 ( V_30 ) ;
F_20 ( V_26 , V_30 ) ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_29 * V_30 = F_22 ( V_26 ) ;
return F_23 ( V_30 ) ;
}
