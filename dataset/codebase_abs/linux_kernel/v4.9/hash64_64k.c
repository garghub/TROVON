bool F_1 ( T_1 V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
unsigned long V_4 = F_2 ( V_1 . V_5 ) ;
V_3 = ( V_4 & V_6 ) >> V_7 ;
V_2 = V_2 >> 2 ;
if ( V_3 & ( 0x1 << V_2 ) )
return true ;
else
return false ;
}
static unsigned long F_3 ( unsigned long V_4 , unsigned long V_2 )
{
unsigned long V_3 ;
if ( ! ( V_4 & V_8 ) )
return V_4 ;
V_2 = V_2 >> 2 ;
V_3 = 0x1 << V_2 ;
return V_4 | ( V_3 << V_7 ) ;
}
int F_4 ( unsigned long V_9 , unsigned long V_10 , unsigned long V_11 ,
T_2 * V_12 , unsigned long V_13 , unsigned long V_14 ,
int V_15 , int V_16 )
{
T_1 V_1 ;
unsigned long * V_17 ;
unsigned long V_18 ;
unsigned int V_19 ;
unsigned long V_20 , V_21 , V_22 ;
unsigned long V_23 , V_24 , V_25 ;
unsigned long V_26 , V_27 , V_28 ;
unsigned long V_29 = V_30 [ V_31 ] . V_29 ;
do {
T_2 V_5 = F_5 ( * V_12 ) ;
V_23 = F_2 ( V_5 ) ;
if ( F_6 ( V_23 & V_32 ) )
return 0 ;
if ( F_6 ( ! F_7 ( V_10 , V_23 ) ) )
return 1 ;
V_24 = V_23 | V_32 | V_33 | V_8 ;
if ( V_10 & V_34 )
V_24 |= V_35 ;
} while ( ! F_8 ( V_12 , F_9 ( V_23 ) , F_9 ( V_24 ) ) );
V_25 = V_24 & ~ V_16 ;
V_20 = F_10 ( V_25 ) ;
if ( F_11 ( V_36 ) &&
! F_11 ( V_37 ) ) {
V_20 = F_12 ( V_20 , F_9 ( V_23 ) , V_13 ) ;
}
V_19 = ( V_9 & ( V_38 - 1 ) ) >> V_29 ;
V_26 = F_13 ( V_9 , V_11 , V_15 ) ;
V_1 = F_14 ( F_9 ( V_23 ) , V_12 ) ;
if ( ! ( V_23 & V_39 ) )
goto V_40;
if ( ! ( V_23 & V_8 ) ) {
F_15 ( V_26 , V_1 , V_41 , V_15 , V_14 ) ;
V_23 &= ~ ( V_39 | V_42 | V_43 ) ;
V_24 &= ~ ( V_39 | V_42 | V_43 ) ;
goto V_40;
}
if ( F_1 ( V_1 , V_19 ) ) {
int V_44 ;
V_27 = F_16 ( V_26 , V_29 , V_15 ) ;
V_22 = F_17 ( V_1 , V_19 ) ;
if ( V_22 & V_45 )
V_27 = ~ V_27 ;
V_28 = ( V_27 & V_46 ) * V_47 ;
V_28 += V_22 & V_48 ;
V_44 = V_49 . V_50 ( V_28 , V_20 , V_26 ,
V_31 , V_31 ,
V_15 , V_14 ) ;
if ( V_44 == - 1 )
goto V_40;
* V_12 = F_9 ( V_24 & ~ V_32 ) ;
return 0 ;
}
V_40:
if ( V_23 & V_51 ) {
V_21 = F_18 ( F_9 ( V_23 ) ) << V_52 ;
} else {
V_21 = F_18 ( F_9 ( V_23 ) ) << V_53 ;
V_21 += ( V_19 << V_29 ) ;
}
V_27 = F_16 ( V_26 , V_29 , V_15 ) ;
V_54:
V_18 = ( ( V_27 & V_46 ) * V_47 ) & ~ 0x7UL ;
V_28 = V_49 . V_55 ( V_18 , V_26 , V_21 , V_20 , 0 ,
V_31 , V_31 , V_15 ) ;
if ( F_6 ( V_28 == - 1 ) ) {
V_18 = ( ( ~ V_27 & V_46 ) * V_47 ) & ~ 0x7UL ;
V_28 = V_49 . V_55 ( V_18 , V_26 , V_21 ,
V_20 , V_56 ,
V_31 , V_31 ,
V_15 ) ;
if ( V_28 == - 1 ) {
if ( F_19 () & 0x1 )
V_18 = ( ( V_27 & V_46 ) *
V_47 ) & ~ 0x7UL ;
V_49 . V_57 ( V_18 ) ;
goto V_54;
}
}
if ( F_6 ( V_28 == - 2 ) ) {
* V_12 = F_9 ( V_23 ) ;
F_20 ( V_9 , V_10 , V_11 , V_13 , V_15 ,
V_31 , V_31 , V_23 ) ;
return - 1 ;
}
V_17 = ( unsigned long * ) ( V_12 + V_58 ) ;
V_1 . V_22 &= ~ ( 0xfUL << ( V_19 << 2 ) ) ;
* V_17 = V_1 . V_22 | ( V_28 << ( V_19 << 2 ) ) ;
V_24 = F_3 ( V_24 , V_19 ) ;
V_24 |= V_39 ;
F_21 () ;
* V_12 = F_9 ( V_24 & ~ V_32 ) ;
return 0 ;
}
int F_22 ( unsigned long V_9 , unsigned long V_10 ,
unsigned long V_11 , T_2 * V_12 , unsigned long V_13 ,
unsigned long V_14 , int V_15 )
{
unsigned long V_18 ;
unsigned long V_20 , V_21 ;
unsigned long V_23 , V_24 ;
unsigned long V_26 , V_27 , V_28 ;
unsigned long V_29 = V_30 [ V_41 ] . V_29 ;
do {
T_2 V_5 = F_5 ( * V_12 ) ;
V_23 = F_2 ( V_5 ) ;
if ( F_6 ( V_23 & V_32 ) )
return 0 ;
if ( F_6 ( ! F_7 ( V_10 , V_23 ) ) )
return 1 ;
if ( ! F_23 ( V_59 ) &&
F_6 ( F_24 ( V_5 ) ) )
return 0 ;
V_24 = V_23 | V_32 | V_33 ;
if ( V_10 & V_34 )
V_24 |= V_35 ;
} while ( ! F_8 ( V_12 , F_9 ( V_23 ) , F_9 ( V_24 ) ) );
V_20 = F_10 ( V_24 ) ;
if ( F_11 ( V_36 ) &&
! F_11 ( V_37 ) )
V_20 = F_12 ( V_20 , F_9 ( V_23 ) , V_13 ) ;
V_26 = F_13 ( V_9 , V_11 , V_15 ) ;
if ( F_6 ( V_23 & V_39 ) ) {
V_27 = F_16 ( V_26 , V_29 , V_15 ) ;
if ( V_23 & V_43 )
V_27 = ~ V_27 ;
V_28 = ( V_27 & V_46 ) * V_47 ;
V_28 += ( V_23 & V_42 ) >> V_7 ;
if ( V_49 . V_50 ( V_28 , V_20 , V_26 , V_41 ,
V_41 , V_15 ,
V_14 ) == - 1 )
V_23 &= ~ V_60 ;
}
if ( F_25 ( ! ( V_23 & V_39 ) ) ) {
V_21 = F_18 ( F_9 ( V_23 ) ) << V_53 ;
V_27 = F_16 ( V_26 , V_29 , V_15 ) ;
V_54:
V_18 = ( ( V_27 & V_46 ) * V_47 ) & ~ 0x7UL ;
V_28 = V_49 . V_55 ( V_18 , V_26 , V_21 , V_20 , 0 ,
V_41 , V_41 ,
V_15 ) ;
if ( F_6 ( V_28 == - 1 ) ) {
V_18 = ( ( ~ V_27 & V_46 ) * V_47 ) & ~ 0x7UL ;
V_28 = V_49 . V_55 ( V_18 , V_26 , V_21 ,
V_20 ,
V_56 ,
V_41 ,
V_41 , V_15 ) ;
if ( V_28 == - 1 ) {
if ( F_19 () & 0x1 )
V_18 = ( ( V_27 & V_46 ) *
V_47 ) & ~ 0x7UL ;
V_49 . V_57 ( V_18 ) ;
goto V_54;
}
}
if ( F_6 ( V_28 == - 2 ) ) {
* V_12 = F_9 ( V_23 ) ;
F_20 ( V_9 , V_10 , V_11 , V_13 , V_15 ,
V_41 , V_41 , V_23 ) ;
return - 1 ;
}
V_24 = ( V_24 & ~ V_60 ) | V_39 ;
V_24 |= ( V_28 << V_7 ) &
( V_43 | V_42 ) ;
}
* V_12 = F_9 ( V_24 & ~ V_32 ) ;
return 0 ;
}
