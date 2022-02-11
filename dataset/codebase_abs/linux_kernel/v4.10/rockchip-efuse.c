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
static int F_9 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
T_3 V_24 ;
T_2 * V_7 ;
int V_8 , V_25 = 0 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
if ( V_8 < 0 ) {
F_3 ( V_6 -> V_10 , L_1 ) ;
return V_8 ;
}
V_20 = F_10 ( V_2 , V_26 ) / V_26 ;
V_21 = F_11 ( V_2 + V_4 , V_26 ) / V_26 ;
V_22 = V_2 % V_26 ;
V_23 = V_21 - V_20 ;
V_7 = F_12 ( sizeof( * V_7 ) * V_23 * V_26 , V_27 ) ;
if ( ! V_7 ) {
F_8 ( V_6 -> V_9 ) ;
return - V_28 ;
}
F_4 ( V_29 | V_30 | V_31 | V_32 ,
V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
while ( V_23 -- ) {
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) | V_33 |
( ( V_20 ++ & V_34 ) << V_35 ) ,
V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
V_24 = F_6 ( V_6 -> V_13 + V_18 ) ;
F_4 ( F_6 ( V_6 -> V_13 + V_14 ) & ( ~ V_33 ) ,
V_6 -> V_13 + V_14 ) ;
F_5 ( 1 ) ;
memcpy ( & V_7 [ V_25 ] , & V_24 , V_26 ) ;
V_25 += V_26 ;
}
F_4 ( V_36 | V_37 , V_6 -> V_13 + V_14 ) ;
memcpy ( V_3 , V_7 + V_22 , V_4 ) ;
F_13 ( V_7 ) ;
F_8 ( V_6 -> V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_5 * V_6 ;
const struct V_44 * V_45 ;
struct V_46 * V_10 = & V_39 -> V_10 ;
V_45 = F_15 ( V_10 -> V_47 -> V_48 , V_10 ) ;
if ( ! V_45 || ! V_45 -> V_49 ) {
F_3 ( V_10 , L_2 ) ;
return - V_50 ;
}
V_6 = F_16 ( & V_39 -> V_10 , sizeof( struct V_5 ) ,
V_27 ) ;
if ( ! V_6 )
return - V_28 ;
V_41 = F_17 ( V_39 , V_51 , 0 ) ;
V_6 -> V_13 = F_18 ( & V_39 -> V_10 , V_41 ) ;
if ( F_19 ( V_6 -> V_13 ) )
return F_20 ( V_6 -> V_13 ) ;
V_6 -> V_9 = F_21 ( & V_39 -> V_10 , L_3 ) ;
if ( F_19 ( V_6 -> V_9 ) )
return F_20 ( V_6 -> V_9 ) ;
V_6 -> V_10 = & V_39 -> V_10 ;
V_52 . V_53 = F_22 ( V_41 ) ;
V_52 . V_54 = V_45 -> V_49 ;
V_52 . V_55 = V_6 ;
V_52 . V_10 = V_6 -> V_10 ;
V_43 = F_23 ( & V_52 ) ;
if ( F_19 ( V_43 ) )
return F_20 ( V_43 ) ;
F_24 ( V_39 , V_43 ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_39 )
{
struct V_42 * V_43 = F_26 ( V_39 ) ;
return F_27 ( V_43 ) ;
}
