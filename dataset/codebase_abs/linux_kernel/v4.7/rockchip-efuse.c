static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
T_2 * V_7 = V_3 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
if ( V_8 < 0 ) {
F_3 ( V_6 -> V_10 , L_1 ) ;
return V_8 ;
}
F_4 ( V_11 | V_12 , V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
while ( V_4 -- ) {
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) &
( ~ ( V_15 << V_16 ) ) ,
V_6 -> V_13 + V_14 ) ;
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) |
( ( V_2 ++ & V_15 ) << V_16 ) ,
V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) |
V_17 , V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
* V_7 ++ = F_7 ( V_6 -> V_13 + V_18 ) ;
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) &
( ~ V_17 ) , V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
}
F_4 ( V_12 | V_19 , V_6 -> V_13 + V_14 ) ;
F_8 ( V_6 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_5 * V_6 ;
V_6 = F_10 ( & V_21 -> V_10 , sizeof( struct V_5 ) ,
V_26 ) ;
if ( ! V_6 )
return - V_27 ;
V_23 = F_11 ( V_21 , V_28 , 0 ) ;
V_6 -> V_13 = F_12 ( & V_21 -> V_10 , V_23 ) ;
if ( F_13 ( V_6 -> V_13 ) )
return F_14 ( V_6 -> V_13 ) ;
V_6 -> V_9 = F_15 ( & V_21 -> V_10 , L_2 ) ;
if ( F_13 ( V_6 -> V_9 ) )
return F_14 ( V_6 -> V_9 ) ;
V_6 -> V_10 = & V_21 -> V_10 ;
V_29 . V_30 = F_16 ( V_23 ) ;
V_29 . V_31 = F_1 ;
V_29 . V_32 = V_6 ;
V_29 . V_10 = V_6 -> V_10 ;
V_25 = F_17 ( & V_29 ) ;
if ( F_13 ( V_25 ) )
return F_14 ( V_25 ) ;
F_18 ( V_21 , V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_24 * V_25 = F_20 ( V_21 ) ;
return F_21 ( V_25 ) ;
}
