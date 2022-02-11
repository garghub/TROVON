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
static long F_13 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long * V_25 )
{
struct V_3 * V_26 = F_2 ( V_2 ) ;
struct V_1 * V_27 = & V_26 -> V_28 . V_2 ;
F_14 ( V_27 , V_2 ) ;
return V_26 -> V_29 -> V_30 ( V_27 , V_24 , V_25 ) ;
}
static unsigned long F_15 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_3 * V_26 = F_2 ( V_2 ) ;
struct V_1 * V_27 = & V_26 -> V_28 . V_2 ;
F_14 ( V_27 , V_2 ) ;
return V_26 -> V_29 -> V_31 ( V_27 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_25 )
{
struct V_3 * V_26 = F_2 ( V_2 ) ;
struct V_1 * V_27 = & V_26 -> V_28 . V_2 ;
F_14 ( V_27 , V_2 ) ;
return V_26 -> V_29 -> V_32 ( V_27 , V_24 , V_25 ) ;
}
struct V_33 * F_17 ( const char * V_34 ,
const char * * V_35 , T_1 V_36 ,
unsigned long V_13 , void T_3 * V_9 , T_1 V_37 ,
T_1 V_38 , T_1 V_16 , T_1 V_17 , T_4 * V_21 )
{
struct V_3 * V_26 ;
struct V_33 * V_33 ;
struct V_39 V_40 ;
V_26 = F_18 ( sizeof( * V_26 ) , V_41 ) ;
if ( ! V_26 )
return F_19 ( - V_42 ) ;
V_40 . V_34 = V_34 ;
V_40 . V_43 = & V_44 ;
V_40 . V_13 = V_13 ;
V_40 . V_35 = V_35 ;
V_40 . V_36 = V_36 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_16 = V_16 ;
V_26 -> V_17 = V_17 ;
V_26 -> V_21 = V_21 ;
V_26 -> V_38 = V_38 ;
V_26 -> V_13 = V_37 ;
V_26 -> V_2 . V_40 = & V_40 ;
V_33 = F_20 ( NULL , & V_26 -> V_2 ) ;
if ( F_21 ( V_33 ) )
F_22 ( V_26 ) ;
return V_33 ;
}
struct V_33 * F_23 ( const char * V_34 ,
const char * const * V_35 , T_1 V_36 ,
unsigned long V_13 , void T_3 * V_9 , T_1 V_37 ,
T_4 * V_21 )
{
struct V_3 * V_26 ;
struct V_33 * V_33 ;
struct V_39 V_40 ;
V_26 = F_18 ( sizeof( * V_26 ) , V_41 ) ;
if ( ! V_26 )
return F_19 ( - V_42 ) ;
V_40 . V_34 = V_34 ;
V_40 . V_43 = & V_45 ;
V_40 . V_13 = V_13 ;
V_40 . V_35 = V_35 ;
V_40 . V_36 = V_36 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_21 = V_21 ;
V_26 -> V_38 = 4 ;
V_26 -> V_13 = V_37 ;
V_26 -> V_28 . V_9 = V_9 + 4 ;
V_26 -> V_28 . V_8 = 16 ;
V_26 -> V_28 . V_38 = 8 ;
V_26 -> V_28 . V_46 = 1 ;
V_26 -> V_28 . V_21 = V_21 ;
V_26 -> V_29 = & V_47 ;
V_26 -> V_2 . V_40 = & V_40 ;
V_33 = F_20 ( NULL , & V_26 -> V_2 ) ;
if ( F_21 ( V_33 ) )
F_22 ( V_26 ) ;
return V_33 ;
}
