void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = V_2 -> V_4 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 ) >= F_3 ( V_2 ) && V_1 ) {
F_4 ( V_7 , & V_1 -> V_8 ) ;
F_5 () ;
V_6 = F_6 ( V_2 -> V_9 ) ;
if ( F_7 ( V_6 ) )
F_8 ( & V_6 -> V_10 , V_11 |
V_12 | V_13 ) ;
if ( V_6 && V_6 -> V_14 && ! ( V_2 -> V_15 & V_16 ) )
F_9 ( V_1 , V_17 , V_18 ) ;
F_10 () ;
}
}
int F_11 ( struct V_1 * V_2 , long * V_19 )
{
struct V_20 * V_21 = V_22 ;
F_12 ( V_10 ) ;
int V_23 ;
do {
int V_24 = F_13 ( V_2 ) ;
if ( V_24 )
return V_24 ;
if ( ( 1 << V_2 -> V_25 ) & ~ ( V_26 | V_27 ) )
return - V_28 ;
if ( ! * V_19 )
return - V_29 ;
if ( F_14 ( V_21 ) )
return F_15 ( * V_19 ) ;
F_16 ( F_17 ( V_2 ) , & V_10 , V_30 ) ;
V_2 -> V_31 ++ ;
V_23 = F_18 ( V_2 , V_19 ,
! V_2 -> V_32 &&
! ( ( 1 << V_2 -> V_25 ) &
~ ( V_33 | V_34 ) ) ) ;
F_19 ( F_17 ( V_2 ) , & V_10 ) ;
V_2 -> V_31 -- ;
} while ( ! V_23 );
return 0 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return ( 1 << V_2 -> V_25 ) &
( V_35 | V_36 | V_37 ) ;
}
void F_21 ( struct V_1 * V_2 , long V_38 )
{
if ( V_38 ) {
F_12 ( V_10 ) ;
do {
F_16 ( F_17 ( V_2 ) , & V_10 ,
V_30 ) ;
if ( F_18 ( V_2 , & V_38 , ! F_20 ( V_2 ) ) )
break;
} while ( ! F_14 ( V_22 ) && V_38 );
F_19 ( F_17 ( V_2 ) , & V_10 ) ;
}
}
int F_22 ( struct V_1 * V_2 , long * V_19 )
{
int V_24 = 0 ;
long V_39 = 0 ;
long V_40 = * V_19 ;
F_12 ( V_10 ) ;
if ( F_23 ( V_2 ) )
V_40 = V_39 = ( F_24 () % ( V_41 / 5 ) ) + 2 ;
while ( 1 ) {
F_25 ( V_42 , & V_2 -> V_4 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) , & V_10 , V_30 ) ;
if ( V_2 -> V_32 || ( V_2 -> V_15 & V_16 ) )
goto V_43;
if ( ! * V_19 )
goto V_44;
if ( F_14 ( V_22 ) )
goto V_45;
F_4 ( V_42 , & V_2 -> V_4 -> V_8 ) ;
if ( F_23 ( V_2 ) && ! V_39 )
break;
F_25 ( V_7 , & V_2 -> V_4 -> V_8 ) ;
V_2 -> V_31 ++ ;
F_18 ( V_2 , & V_40 , V_2 -> V_32 ||
( V_2 -> V_15 & V_16 ) ||
( F_23 ( V_2 ) &&
! V_39 ) ) ;
V_2 -> V_31 -- ;
if ( V_39 ) {
V_39 -= V_40 ;
V_40 = * V_19 ;
if ( V_40 != V_46 &&
( V_40 -= V_39 ) < 0 )
V_40 = 0 ;
V_39 = 0 ;
}
* V_19 = V_40 ;
}
V_47:
F_19 ( F_17 ( V_2 ) , & V_10 ) ;
return V_24 ;
V_43:
V_24 = - V_28 ;
goto V_47;
V_44:
V_24 = - V_29 ;
goto V_47;
V_45:
V_24 = F_15 ( * V_19 ) ;
goto V_47;
}
int F_26 ( struct V_1 * V_2 , int V_8 , int V_24 )
{
if ( V_24 == - V_28 )
V_24 = F_13 ( V_2 ) ? : - V_28 ;
if ( V_24 == - V_28 && ! ( V_8 & V_48 ) )
F_27 ( V_49 , V_22 , 0 ) ;
return V_24 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_50 ) ;
F_29 ( & V_2 -> V_51 ) ;
F_30 ( ! F_31 ( & V_2 -> V_52 ) ) ;
F_32 ( V_2 ) ;
F_30 ( V_2 -> V_53 ) ;
F_30 ( V_2 -> V_54 ) ;
}
