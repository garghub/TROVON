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
void T_2 * V_12 = V_11 -> V_12 ;
struct V_13 * V_13 = V_11 -> V_14 ;
T_3 * V_15 = V_6 ;
int V_16 ;
V_16 = F_3 ( V_13 ) ;
if ( V_16 < 0 ) {
F_4 ( V_11 -> V_17 , L_1 ) ;
return V_16 ;
}
F_5 ( V_18 | V_19 , V_12 + V_20 ) ;
F_6 ( 1 ) ;
while ( V_7 ) {
F_5 ( F_7 ( V_12 + V_20 ) &
( ~ ( V_21 << V_22 ) ) ,
V_12 + V_20 ) ;
F_5 ( F_7 ( V_12 + V_20 ) |
( ( V_8 & V_21 ) << V_22 ) ,
V_12 + V_20 ) ;
F_6 ( 1 ) ;
F_5 ( F_7 ( V_12 + V_20 ) |
V_23 , V_12 + V_20 ) ;
F_6 ( 1 ) ;
* V_15 ++ = F_8 ( V_12 + V_24 ) ;
F_5 ( F_7 ( V_12 + V_20 ) &
( ~ V_23 ) , V_12 + V_20 ) ;
F_6 ( 1 ) ;
V_7 -= 1 ;
V_8 += 1 ;
}
F_5 ( V_19 | V_25 , V_12 + V_20 ) ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_17 = & V_27 -> V_17 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
void T_2 * V_12 ;
struct V_13 * V_13 ;
struct V_10 * V_1 ;
V_30 = F_11 ( V_27 , V_34 , 0 ) ;
V_12 = F_12 ( V_17 , V_30 ) ;
if ( F_13 ( V_12 ) )
return F_14 ( V_12 ) ;
V_1 = F_15 ( V_17 , sizeof( struct V_10 ) ,
V_35 ) ;
if ( F_13 ( V_1 ) )
return F_14 ( V_1 ) ;
V_13 = F_16 ( V_17 , L_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_1 -> V_17 = V_17 ;
V_1 -> V_12 = V_12 ;
V_1 -> V_14 = V_13 ;
V_36 . V_37 = F_17 ( V_30 ) - 1 ;
V_33 = F_18 ( V_17 , & V_38 ,
V_1 , & V_36 ) ;
if ( F_13 ( V_33 ) ) {
F_4 ( V_17 , L_3 ) ;
return F_14 ( V_33 ) ;
}
V_39 . V_17 = V_17 ;
V_32 = F_19 ( & V_39 ) ;
if ( F_13 ( V_32 ) )
return F_14 ( V_32 ) ;
F_20 ( V_27 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = F_22 ( V_27 ) ;
return F_23 ( V_32 ) ;
}
