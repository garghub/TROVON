static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_5 ) ;
V_2 |= V_6 | V_7 ;
F_3 ( V_2 , V_1 + V_5 ) ;
}
static void F_4 ( void T_1 * V_1 )
{
}
static int F_5 ( void T_1 * V_1 , const T_2 V_8 )
{
int V_9 = 0 ;
int V_10 ;
V_10 = F_2 ( V_1 + V_11 ) ;
if ( V_10 & V_12 )
V_9 |= V_13 ;
if ( V_10 & V_14 )
V_9 |= V_15 ;
if ( V_10 & V_16 )
V_9 |= V_17 ;
if ( V_10 & V_18 )
V_9 |= V_19 ;
return V_9 ;
}
static int F_6 ( void T_1 * V_1 ,
struct V_20 * V_21 )
{
int V_8 , V_9 = 0 ;
V_8 = F_2 ( V_1 + V_22 ) ;
if ( F_7 ( V_8 & V_23 ) )
V_9 |= F_5 ( V_1 , V_8 ) ;
return V_9 ;
}
static void F_8 ( void T_1 * V_1 , unsigned long V_24 )
{
}
static void F_9 ( void T_1 * V_1 , unsigned char * V_25 ,
unsigned int V_26 )
{
T_2 V_27 , V_28 ;
V_27 = ( V_25 [ 5 ] << 8 ) | ( V_25 [ 4 ] ) ;
V_28 = ( V_25 [ 3 ] << 24 ) | ( V_25 [ 2 ] << 16 ) |
( V_25 [ 1 ] << 8 ) | ( V_25 [ 0 ] ) ;
F_3 ( V_27 , V_1 + F_10 ( V_26 ) ) ;
F_3 ( V_28 , V_1 + F_11 ( V_26 ) ) ;
}
static void F_12 ( void T_1 * V_1 , unsigned char * V_25 ,
unsigned int V_26 )
{
T_2 V_27 , V_28 ;
V_27 = F_2 ( V_1 + F_10 ( V_26 ) ) ;
V_28 = F_2 ( V_1 + F_11 ( V_26 ) ) ;
V_25 [ 5 ] = ( V_27 & 0x0000FF00 ) >> 8 ;
V_25 [ 4 ] = ( V_27 & 0x000000FF ) ;
V_25 [ 3 ] = ( V_28 & 0xFF000000 ) >> 24 ;
V_25 [ 2 ] = ( V_28 & 0x00FF0000 ) >> 16 ;
V_25 [ 1 ] = ( V_28 & 0x0000FF00 ) >> 8 ;
V_25 [ 0 ] = ( V_28 & 0x000000FF ) ;
}
static void F_13 ( void T_1 * V_1 , bool V_29 )
{
T_2 V_30 ;
V_30 = F_2 ( V_1 + V_3 ) ;
V_30 &= ~ V_31 ;
if ( V_29 )
V_30 |= V_31 ;
F_3 ( V_30 , V_1 + V_3 ) ;
}
static void F_14 ( void T_1 * V_1 , bool V_29 )
{
T_2 V_32 ;
V_32 = F_2 ( V_1 + V_5 ) ;
V_32 &= ~ V_33 ;
if ( V_29 )
V_32 |= V_33 ;
F_3 ( V_32 , V_1 + V_5 ) ;
}
static int F_15 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_34 ) ;
}
static unsigned int F_16 ( void T_1 * V_1 ,
unsigned char V_35 )
{
return F_2 ( V_1 + ( F_17 ( V_35 ) ) ) ;
}
static void F_18 ( void T_1 * V_1 , unsigned char V_36 )
{
T_2 V_37 = F_2 ( V_1 + V_3 ) ;
V_37 &= ~ 0x60000000 ;
V_37 |= ( V_36 << V_38 ) ;
F_3 ( V_37 , V_1 + V_3 ) ;
}
static void F_19 ( void T_1 * V_1 , int V_39 )
{
T_2 V_40 ;
V_40 = F_2 ( V_1 + V_41 ) ;
V_40 &= ~ ( V_42 << V_39 ) ;
V_40 |= V_43 ;
F_3 ( V_40 , V_1 + V_41 ) ;
}
static void F_20 ( void T_1 * V_1 , int V_39 )
{
T_2 V_40 ;
V_40 = F_2 ( V_1 + V_41 ) ;
V_40 &= ~ ( V_42 << V_39 ) ;
V_40 |= V_44 ;
F_3 ( V_40 , V_1 + V_41 ) ;
}
static void F_21 ( void T_1 * V_1 )
{
T_2 V_45 ;
V_45 = F_2 ( V_1 + V_11 ) ;
V_45 |= V_46 | V_47 ;
F_3 ( V_45 , V_1 + V_11 ) ;
}
static void F_22 ( void T_1 * V_1 )
{
T_2 V_45 ;
V_45 = F_2 ( V_1 + V_11 ) ;
V_45 &= ~ ( V_46 | V_47 ) ;
F_3 ( V_45 , V_1 + V_11 ) ;
}
static void F_23 ( void T_1 * V_1 , const int V_48 )
{
T_2 V_45 ;
V_45 = F_2 ( V_1 + V_11 ) ;
if ( V_48 )
V_45 |= V_49 ;
else
V_45 &= ~ V_49 ;
F_3 ( V_45 , V_1 + V_11 ) ;
}
static void F_24 ( void T_1 * V_1 ,
const int V_50 , const int V_51 )
{
int V_52 = ( ( V_51 & 0xffff ) ) | ( ( V_50 & 0x7ff ) << 16 ) ;
F_3 ( V_52 , V_1 + V_53 ) ;
}
static void F_25 ( void T_1 * V_1 )
{
T_2 V_45 ;
V_45 = F_2 ( V_1 + V_5 ) ;
V_45 |= V_54 ;
F_3 ( V_45 , V_1 + V_5 ) ;
}
static void F_26 ( void T_1 * V_1 )
{
T_2 V_45 ;
V_45 = F_2 ( V_1 + V_5 ) ;
V_45 &= ~ V_54 ;
F_3 ( V_45 , V_1 + V_5 ) ;
}
const struct V_55 * F_27 ( void )
{
return & V_56 ;
}
