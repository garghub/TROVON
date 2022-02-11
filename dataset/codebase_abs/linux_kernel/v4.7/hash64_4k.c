int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
T_1 * V_4 , unsigned long V_5 , unsigned long V_6 ,
int V_7 , int V_8 )
{
unsigned long V_9 ;
unsigned long V_10 , V_11 ;
unsigned long V_12 , V_13 ;
unsigned long V_14 , V_15 , V_16 ;
unsigned long V_17 = V_18 [ V_19 ] . V_17 ;
do {
T_1 V_20 = F_2 ( * V_4 ) ;
V_12 = F_3 ( V_20 ) ;
if ( F_4 ( V_12 & V_21 ) )
return 0 ;
if ( F_4 ( ! F_5 ( V_2 , V_12 ) ) )
return 1 ;
V_13 = V_12 | V_21 | V_22 ;
if ( V_2 & V_23 )
V_13 |= V_24 ;
} while ( ! F_6 ( V_4 , F_7 ( V_12 ) , F_7 ( V_13 ) ) );
V_10 = F_8 ( V_13 ) ;
if ( ! F_9 ( V_25 ) &&
! F_9 ( V_26 ) )
V_10 = F_10 ( V_10 , F_7 ( V_12 ) , V_5 ) ;
V_14 = F_11 ( V_1 , V_3 , V_7 ) ;
if ( F_4 ( V_12 & V_27 ) ) {
V_15 = F_12 ( V_14 , V_17 , V_7 ) ;
if ( V_12 & V_28 )
V_15 = ~ V_15 ;
V_16 = ( V_15 & V_29 ) * V_30 ;
V_16 += ( V_12 & V_31 ) >> V_32 ;
if ( V_33 . V_34 ( V_16 , V_10 , V_14 , V_19 ,
V_19 , V_7 , V_6 ) == - 1 )
V_12 &= ~ V_35 ;
}
if ( F_13 ( ! ( V_12 & V_27 ) ) ) {
V_11 = F_14 ( F_7 ( V_12 ) ) << V_36 ;
V_15 = F_12 ( V_14 , V_17 , V_7 ) ;
V_37:
V_9 = ( ( V_15 & V_29 ) * V_30 ) & ~ 0x7UL ;
V_16 = V_33 . V_38 ( V_9 , V_14 , V_11 , V_10 , 0 ,
V_19 , V_19 , V_7 ) ;
if ( F_4 ( V_16 == - 1 ) ) {
V_9 = ( ( ~ V_15 & V_29 ) * V_30 ) & ~ 0x7UL ;
V_16 = V_33 . V_38 ( V_9 , V_14 , V_11 ,
V_10 , V_39 ,
V_19 , V_19 , V_7 ) ;
if ( V_16 == - 1 ) {
if ( F_15 () & 0x1 )
V_9 = ( ( V_15 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_33 . V_40 ( V_9 ) ;
goto V_37;
}
}
if ( F_4 ( V_16 == - 2 ) ) {
* V_4 = F_7 ( V_12 ) ;
F_16 ( V_1 , V_2 , V_3 , V_5 , V_7 ,
V_19 , V_19 , V_12 ) ;
return - 1 ;
}
V_13 = ( V_13 & ~ V_35 ) | V_27 ;
V_13 |= ( V_16 << V_32 ) &
( V_28 | V_31 ) ;
}
* V_4 = F_7 ( V_13 & ~ V_21 ) ;
return 0 ;
}
