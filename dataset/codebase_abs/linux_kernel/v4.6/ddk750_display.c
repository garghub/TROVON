static void F_1 ( int V_1 , int V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
int V_6 = 0 ;
if ( ! V_1 ) {
V_3 = V_7 ;
V_5 = V_8 ;
} else {
V_3 = V_9 ;
V_5 = V_10 ;
}
V_4 = F_2 ( V_3 ) ;
if ( V_2 ) {
V_4 |= V_11 ;
F_3 ( V_3 , V_4 ) ;
V_4 |= V_12 ;
do {
V_6 ++ ;
F_3 ( V_3 , V_4 ) ;
} while ( ( F_2 ( V_3 ) & ~ V_5 ) != ( V_4 & ~ V_5 ) );
F_4 ( L_1 , V_6 ) ;
} else {
V_4 &= ~ V_12 ;
F_3 ( V_3 , V_4 ) ;
V_4 &= ~ V_11 ;
F_3 ( V_3 , V_4 ) ;
}
}
static void F_5 ( int V_1 , int V_13 )
{
unsigned int V_14 ;
if ( ! V_1 ) {
if ( ! ( F_2 ( V_15 ) & V_16 ) ||
! ( F_2 ( V_7 ) & V_11 ) ) {
return;
}
while ( V_13 -- > 0 ) {
do {
V_14 = F_2 ( V_17 ) ;
} while ( V_14 & V_18 );
do {
V_14 = F_2 ( V_17 ) ;
} while ( ! ( V_14 & V_18 ) );
}
} else {
if ( ! ( F_2 ( V_19 ) & V_16 ) ||
! ( F_2 ( V_9 ) & V_11 ) ) {
return;
}
while ( V_13 -- > 0 ) {
do {
V_14 = F_2 ( V_17 ) ;
} while ( V_14 & V_18 );
do {
V_14 = F_2 ( V_17 ) ;
} while ( ! ( V_14 & V_18 ) );
}
}
}
static void F_6 ( int V_20 , int V_13 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_7 ) ;
V_3 |= ( V_20 ? V_21 : 0 ) ;
F_3 ( V_7 , V_3 ) ;
F_7 ( V_13 ) ;
V_3 = F_2 ( V_7 ) ;
V_3 |= ( V_20 ? V_22 : 0 ) ;
F_3 ( V_7 , V_3 ) ;
F_7 ( V_13 ) ;
V_3 = F_2 ( V_7 ) ;
V_3 |= ( V_20 ? V_23 : 0 ) ;
F_3 ( V_7 , V_3 ) ;
F_7 ( V_13 ) ;
V_3 = F_2 ( V_7 ) ;
V_3 |= ( V_20 ? V_21 : 0 ) ;
F_3 ( V_7 , V_3 ) ;
F_7 ( V_13 ) ;
}
void F_8 ( T_1 V_24 )
{
unsigned int V_3 ;
if ( V_24 & V_25 ) {
V_3 = F_2 ( V_7 ) ;
V_3 &= ~ V_26 ;
V_3 |= ( ( ( V_24 & V_27 ) >> V_28 ) <<
V_29 ) ;
F_3 ( V_7 , V_3 ) ;
}
if ( V_24 & V_30 ) {
V_3 = F_2 ( V_9 ) ;
V_3 &= ~ V_31 ;
V_3 |= ( ( ( V_24 & V_32 ) >> V_33 ) <<
V_34 ) ;
V_3 &= ~ V_35 ;
F_3 ( V_9 , V_3 ) ;
}
if ( V_24 & V_36 ) {
F_1 ( 0 , ( V_24 & V_37 ) >> V_38 ) ;
}
if ( V_24 & V_39 ) {
F_1 ( 1 , ( V_24 & V_40 ) >> V_41 ) ;
}
if ( V_24 & V_42 ) {
F_6 ( ( V_24 & V_43 ) >> V_44 , 4 ) ;
}
if ( V_24 & V_45 )
F_9 ( ( V_24 & V_46 ) >> V_47 ) ;
if ( V_24 & V_48 )
F_10 ( ( V_24 & V_49 ) >> V_50 ) ;
}
