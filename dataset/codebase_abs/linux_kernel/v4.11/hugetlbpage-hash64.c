int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
T_1 * V_4 , unsigned long V_5 , unsigned long V_6 ,
int V_7 , unsigned int V_8 , unsigned int V_9 )
{
unsigned long V_10 ;
unsigned long V_11 , V_12 ;
unsigned long V_13 , V_14 , V_15 ;
long V_16 ;
F_2 ( V_8 != V_17 [ V_9 ] . V_8 ) ;
V_10 = F_3 ( V_1 , V_3 , V_7 ) ;
do {
V_11 = F_4 ( * V_4 ) ;
if ( F_5 ( V_11 & V_18 ) )
return 0 ;
if ( F_5 ( ! F_6 ( V_2 , V_11 ) ) )
return 1 ;
V_12 = V_11 | V_18 | V_19 ;
if ( V_2 & V_20 )
V_12 |= V_21 ;
} while( ! F_7 ( V_4 , F_8 ( V_11 ) , F_8 ( V_12 ) ) );
V_13 = F_9 ( V_12 ) ;
V_15 = ( ( 1UL ) << V_8 ) ;
if ( ! F_10 ( V_22 ) )
V_13 = F_11 ( V_13 , F_8 ( V_11 ) , V_5 ) ;
if ( F_5 ( V_11 & V_23 ) ) {
unsigned long V_24 , V_16 ;
V_24 = F_12 ( V_10 , V_8 , V_7 ) ;
if ( V_11 & V_25 )
V_24 = ~ V_24 ;
V_16 = ( V_24 & V_26 ) * V_27 ;
V_16 += ( V_11 & V_28 ) >> V_29 ;
if ( V_30 . V_31 ( V_16 , V_13 , V_10 , V_9 ,
V_9 , V_7 , V_6 ) == - 1 )
V_11 &= ~ V_32 ;
}
if ( F_13 ( ! ( V_11 & V_23 ) ) ) {
unsigned long V_24 = F_12 ( V_10 , V_8 , V_7 ) ;
V_14 = F_14 ( F_8 ( V_11 ) ) << V_33 ;
V_12 = ( V_12 & ~ V_32 ) | V_23 ;
V_16 = F_15 ( V_24 , V_10 , V_14 , V_13 , 0 ,
V_9 , V_7 ) ;
if ( F_5 ( V_16 == - 2 ) ) {
* V_4 = F_8 ( V_11 ) ;
F_16 ( V_1 , V_2 , V_3 , V_5 , V_7 ,
V_9 , V_9 , V_11 ) ;
return - 1 ;
}
V_12 |= ( V_16 << V_29 ) &
( V_25 | V_28 ) ;
}
* V_4 = F_8 ( V_12 & ~ V_18 ) ;
return 0 ;
}
