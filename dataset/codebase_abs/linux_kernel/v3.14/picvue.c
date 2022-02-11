static void F_1 ( T_1 V_1 )
{
* V_2 -> V_3 = V_1 ;
}
static T_1 F_2 ( void )
{
T_1 V_4 = * V_2 -> V_3 ;
return V_4 ;
}
static void F_3 ( T_1 V_5 , T_2 V_6 )
{
V_5 |= V_2 -> V_7 ;
F_1 ( V_5 ) ;
V_5 &= ~ V_2 -> V_8 ;
V_5 |= V_6 << V_2 -> V_9 ;
F_1 ( V_5 ) ;
F_4 ( 220 ) ;
F_1 ( V_5 & ~ V_2 -> V_7 ) ;
F_4 ( 220 ) ;
}
static T_2 F_5 ( T_1 V_5 )
{
T_2 V_6 ;
V_5 |= V_2 -> V_7 ;
F_1 ( V_5 ) ;
F_4 ( 220 ) ;
V_6 = ( F_2 () & V_2 -> V_8 ) >> V_2 -> V_9 ;
V_5 &= ~ V_2 -> V_7 ;
F_1 ( V_5 ) ;
F_4 ( 220 ) ;
return V_6 ;
}
static T_2 F_6 ( void )
{
T_1 V_5 = F_2 () ;
T_2 V_6 ;
V_5 |= V_2 -> V_10 ;
V_5 &= ~ V_2 -> V_11 ;
F_1 ( V_5 ) ;
F_4 ( 40 ) ;
V_6 = F_5 ( V_5 ) ;
V_5 |= V_2 -> V_11 ;
F_1 ( V_5 ) ;
return V_6 ;
}
static int F_7 ( void )
{
int V_12 = V_13 ;
int V_14 = 0 ;
while ( ( F_6 () & V_15 ) && V_12 )
V_12 -- ;
if ( V_12 == 0 )
V_14 = - V_16 ;
return V_14 ;
}
static void F_8 ( T_2 V_6 , int V_17 )
{
T_1 V_5 = F_2 () ;
V_5 &= ~ V_2 -> V_10 ;
if ( V_17 == V_18 )
V_5 |= V_2 -> V_11 ;
else
V_5 &= ~ V_2 -> V_11 ;
F_1 ( V_5 ) ;
F_4 ( 40 ) ;
F_3 ( V_5 , V_6 ) ;
if ( V_17 == V_18 )
V_5 &= ~ V_2 -> V_11 ;
else
V_5 |= V_2 -> V_11 ;
F_1 ( V_5 ) ;
F_7 () ;
}
void F_9 ( const unsigned char * V_19 , T_2 V_20 , int line )
{
int V_12 = 0 ;
if ( line > 0 && ( V_21 > 1 ) )
V_20 += 0x40 * line ;
F_8 ( 0x80 | V_20 , V_22 ) ;
while ( * V_19 != 0 && V_12 < V_23 ) {
F_8 ( * V_19 ++ , V_18 ) ;
V_12 ++ ;
}
}
void F_10 ( const unsigned char * V_19 , int line )
{
int V_24 = strlen ( V_19 ) ;
T_2 V_20 ;
if ( V_24 > V_25 )
V_20 = 0 ;
else
V_20 = ( V_25 - strlen ( V_19 ) ) / 2 ;
F_9 ( V_19 , V_20 , line ) ;
}
void F_11 ( const unsigned char * V_19 )
{
int V_24 = strlen ( V_19 ) ;
F_9 ( V_19 , 0 , 0 ) ;
if ( V_24 > V_25 )
F_9 ( & V_19 [ V_25 ] , 0 , 1 ) ;
}
int F_12 ( int V_26 , T_2 V_27 [ V_28 ] )
{
int V_12 ;
int V_20 ;
if ( V_26 > V_29 )
return - V_30 ;
V_20 = V_26 * 8 ;
F_8 ( 0x40 | V_20 , V_22 ) ;
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ )
F_8 ( V_27 [ V_12 ] , V_18 ) ;
return 0 ;
}
static void F_13 ( T_2 V_31 )
{
F_8 ( V_32 | ( V_31 & ( V_33 | V_34 | V_35 ) ) ,
V_22 ) ;
}
static void F_14 ( T_2 V_31 )
{
F_8 ( V_36 | ( V_31 & ( V_37 | V_38 ) ) ,
V_22 ) ;
}
void F_15 ( T_2 V_31 )
{
F_8 ( V_39 | ( V_31 & ( V_40 | V_41 | V_42 ) ) , V_22 ) ;
}
void F_16 ( T_2 V_31 )
{
F_8 ( V_43 | ( V_31 & ( V_44 | V_45 ) ) , V_22 ) ;
}
void F_17 ( void )
{
F_8 ( V_46 , V_22 ) ;
}
void F_18 ( void )
{
F_8 ( V_47 , V_22 ) ;
}
int F_19 ( void )
{
T_2 V_31 = V_33 ;
if ( V_21 == 2 )
V_31 |= ( V_48 | V_34 ) ;
else
V_31 |= ( V_35 | V_49 ) ;
F_13 ( V_31 ) ;
F_15 ( V_40 ) ;
F_14 ( V_37 ) ;
F_17 () ;
F_10 ( L_1 , 0 ) ;
F_10 ( L_2 , 1 ) ;
return 0 ;
}
