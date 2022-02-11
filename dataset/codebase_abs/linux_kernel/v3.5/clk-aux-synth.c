static unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_9 = V_8 [ V_4 ] . V_9 ? 1 : 2 ;
return ( ( ( V_3 / 10000 ) * V_8 [ V_4 ] . V_10 ) /
( V_8 [ V_4 ] . V_11 * V_9 ) ) * 10000 ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_13 ;
return F_4 ( V_2 , V_12 , * V_3 , F_1 ,
V_6 -> V_14 , & V_13 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_16 = 1 , V_17 = 1 , V_18 , V_19 ;
unsigned long V_20 = 0 ;
if ( V_6 -> V_21 )
F_6 ( V_6 -> V_21 , V_20 ) ;
V_18 = F_7 ( V_6 -> V_22 ) ;
if ( V_6 -> V_21 )
F_8 ( V_6 -> V_21 , V_20 ) ;
V_19 = ( V_18 >> V_6 -> V_23 -> V_24 ) & V_6 -> V_23 -> V_25 ;
if ( V_19 == V_6 -> V_23 -> V_26 )
V_17 = 2 ;
V_16 = ( V_18 >> V_6 -> V_23 -> V_27 ) &
V_6 -> V_23 -> V_28 ;
V_17 *= ( V_18 >> V_6 -> V_23 -> V_29 ) &
V_6 -> V_23 -> V_30 ;
if ( ! V_17 )
return 0 ;
return ( ( ( V_15 / 10000 ) * V_16 ) / V_17 ) * 10000 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_18 , V_20 = 0 ;
int V_31 ;
F_4 ( V_2 , V_12 , V_3 , F_1 , V_6 -> V_14 ,
& V_31 ) ;
if ( V_6 -> V_21 )
F_6 ( V_6 -> V_21 , V_20 ) ;
V_18 = F_7 ( V_6 -> V_22 ) &
~ ( V_6 -> V_23 -> V_25 << V_6 -> V_23 -> V_24 ) ;
V_18 |= ( V_8 [ V_31 ] . V_9 & V_6 -> V_23 -> V_25 ) <<
V_6 -> V_23 -> V_24 ;
V_18 &= ~ ( V_6 -> V_23 -> V_28 << V_6 -> V_23 -> V_27 ) ;
V_18 |= ( V_8 [ V_31 ] . V_10 & V_6 -> V_23 -> V_28 ) <<
V_6 -> V_23 -> V_27 ;
V_18 &= ~ ( V_6 -> V_23 -> V_30 << V_6 -> V_23 -> V_29 ) ;
V_18 |= ( V_8 [ V_31 ] . V_11 & V_6 -> V_23 -> V_30 ) <<
V_6 -> V_23 -> V_29 ;
F_10 ( V_18 , V_6 -> V_22 ) ;
if ( V_6 -> V_21 )
F_8 ( V_6 -> V_21 , V_20 ) ;
return 0 ;
}
struct V_32 * F_11 ( const char * V_33 , const char * V_34 ,
const char * V_35 , unsigned long V_20 , void T_2 * V_22 ,
struct V_36 * V_23 , struct V_7 * V_8 ,
T_1 V_14 , T_3 * V_21 , struct V_32 * * V_37 )
{
struct V_5 * V_6 ;
struct V_38 V_39 ;
struct V_32 * V_32 ;
if ( ! V_33 || ! V_35 || ! V_22 || ! V_8 || ! V_14 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_40 ) ;
}
V_6 = F_14 ( sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 ) {
F_12 ( L_2 ) ;
return F_13 ( - V_42 ) ;
}
if ( ! V_23 )
V_6 -> V_23 = & V_43 ;
else
V_6 -> V_23 = V_23 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_2 . V_39 = & V_39 ;
V_39 . V_44 = V_33 ;
V_39 . V_45 = & V_46 ;
V_39 . V_20 = V_20 ;
V_39 . V_47 = & V_35 ;
V_39 . V_48 = 1 ;
V_32 = F_15 ( NULL , & V_6 -> V_2 ) ;
if ( F_16 ( V_32 ) )
goto V_49;
if ( V_34 ) {
struct V_32 * V_50 ;
V_50 = F_17 ( NULL , V_34 , V_33 , 0 , V_22 ,
V_6 -> V_23 -> V_51 , 0 , V_21 ) ;
if ( F_16 ( V_50 ) )
goto V_49;
if ( V_37 )
* V_37 = V_50 ;
}
return V_32 ;
V_49:
F_18 ( V_6 ) ;
F_12 ( L_3 ) ;
return NULL ;
}
