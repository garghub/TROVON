static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 , V_6 ;
T_1 V_7 , V_8 ;
V_5 = F_3 ( V_4 -> V_9 ) ;
V_6 = V_5 & V_10 ;
F_4 ( ( V_6 != F_5 ( V_11 ) ) &&
( V_6 != F_5 ( V_12 ) ) ) ;
V_8 = ( V_6 == F_5 ( V_12 ) ) ?
F_6 ( V_4 , V_12 ) :
F_6 ( V_4 , V_11 ) ;
V_7 = ( V_5 >> V_8 ) & F_7 ( V_4 ) ;
if ( ( V_4 -> V_13 & V_14 ) && ! ( V_5 & V_15 ) &&
( V_7 == V_4 -> V_16 ) )
V_7 = V_4 -> V_17 ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 , V_6 ;
int V_19 = 0 ;
T_1 V_20 , V_8 ;
unsigned long V_13 = 0 ;
if ( V_4 -> V_21 )
F_9 ( V_4 -> V_21 , V_13 ) ;
V_5 = F_3 ( V_4 -> V_9 ) ;
V_6 = V_5 & V_10 ;
F_4 ( ( V_6 != F_5 ( V_11 ) ) &&
( V_6 != F_5 ( V_12 ) ) ) ;
V_8 = ( V_6 == F_5 ( V_12 ) ) ?
F_6 ( V_4 , V_12 ) :
F_6 ( V_4 , V_11 ) ;
if ( ( V_4 -> V_13 & V_14 ) && ( ( V_18 == V_4 -> V_17 ) ||
( V_18 == V_4 -> V_16 ) ) ) {
V_20 = F_1 ( V_2 ) ;
if ( ( V_20 == V_4 -> V_17 ) ||
( V_20 == V_4 -> V_16 ) ) {
V_19 = - V_22 ;
goto V_23;
}
V_5 ^= V_15 ;
F_10 ( V_5 , V_4 -> V_9 ) ;
F_11 ( 2 ) ;
if ( V_18 == V_4 -> V_17 )
V_18 = V_4 -> V_16 ;
}
V_5 &= ~ ( ( F_7 ( V_4 ) ) << V_8 ) ;
V_5 |= ( V_18 & ( F_7 ( V_4 ) ) ) << V_8 ;
F_10 ( V_5 , V_4 -> V_9 ) ;
F_11 ( 2 ) ;
V_23:
if ( V_4 -> V_21 )
F_12 ( V_4 -> V_21 , V_13 ) ;
return V_19 ;
}
struct V_24 * F_13 ( const char * V_25 ,
const char * * V_26 , T_1 V_27 ,
unsigned long V_13 , void T_3 * V_9 , T_1 V_28 ,
T_1 V_29 , T_1 V_16 , T_1 V_17 , T_4 * V_21 )
{
struct V_3 * V_30 ;
struct V_24 * V_24 ;
struct V_31 V_32 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_33 ) ;
if ( ! V_30 ) {
F_15 ( L_1 , V_34 ) ;
return F_16 ( - V_35 ) ;
}
V_32 . V_25 = V_25 ;
V_32 . V_36 = & V_37 ;
V_32 . V_13 = V_13 ;
V_32 . V_26 = V_26 ;
V_32 . V_27 = V_27 ;
V_30 -> V_9 = V_9 ;
V_30 -> V_16 = V_16 ;
V_30 -> V_17 = V_17 ;
V_30 -> V_21 = V_21 ;
V_30 -> V_29 = V_29 ;
V_30 -> V_13 = V_28 ;
V_30 -> V_2 . V_32 = & V_32 ;
V_24 = F_17 ( NULL , & V_30 -> V_2 ) ;
if ( F_18 ( V_24 ) )
F_19 ( V_30 ) ;
return V_24 ;
}
