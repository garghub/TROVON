static inline T_1 F_1 ( T_1 V_1 )
{
return * ( T_1 * ) ( V_2 + ( V_1 & ~ 3 ) ) ;
}
static inline void F_2 ( T_1 V_1 , T_1 V_3 )
{
* ( T_1 * ) ( V_2 + ( V_1 & ~ 3 ) ) = V_3 ;
}
int F_3 ( const struct V_4 * V_5 , T_2 V_6 , T_2 V_7 )
{
return V_5 -> V_8 ;
}
int F_4 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 )
{
T_1 V_12 ;
if ( ! ( V_13 & ( V_14 | V_15 ) ) )
return 0 ;
if ( V_10 -> V_16 == 0 ) {
V_12 = F_6 ( V_11 ) ;
if ( V_12 == V_17 )
return ( V_13 & V_18 ) != 0 ;
else if ( V_13 & V_15 )
return 0 ;
else
return 1 ;
} else
return 1 ;
}
static int F_7 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_19 , int V_20 , T_1 * V_21 )
{
T_1 V_3 = 0 ;
if ( ( V_20 == 2 ) && ( V_19 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_19 & 3 ) )
return V_22 ;
if ( F_5 ( V_10 , V_11 ) )
V_3 = F_1 ( F_8 ( V_10 , V_11 , V_19 ) ) ;
else
V_3 = 0xFFFFFFFF ;
if ( V_20 == 1 )
* V_21 = ( V_3 >> ( ( V_19 & 3 ) << 3 ) ) & 0xff ;
else if ( V_20 == 2 )
* V_21 = ( V_3 >> ( ( V_19 & 3 ) << 3 ) ) & 0xffff ;
else
* V_21 = V_3 ;
return V_23 ;
}
static int F_9 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_19 , int V_20 , T_1 V_21 )
{
T_1 V_24 = F_8 ( V_10 , V_11 , V_19 ) ;
T_1 V_3 = 0 ;
if ( ( V_20 == 2 ) && ( V_19 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_19 & 3 ) )
return V_22 ;
if ( ! F_5 ( V_10 , V_11 ) )
return V_22 ;
V_3 = F_1 ( V_24 ) ;
if ( V_20 == 1 )
V_3 = ( V_3 & ~ ( 0xff << ( ( V_19 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_19 & 3 ) << 3 ) ) ;
else if ( V_20 == 2 )
V_3 = ( V_3 & ~ ( 0xffff << ( ( V_19 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_19 & 3 ) << 3 ) ) ;
else
V_3 = V_21 ;
F_2 ( V_24 , V_3 ) ;
return V_23 ;
}
static int T_3 F_10 ( void )
{
void T_4 * V_25 ;
T_5 V_26 ;
T_6 V_27 ;
F_11 ( V_28 ) ;
V_29 = 0x00008000UL ;
V_30 = 0x01000000UL ;
V_31 . V_32 = 0x01ffffffUL ;
V_33 . V_32 = 0xffffffffUL ;
V_2 =
F_12 ( V_34 , 16 * 1024 * 1024 ) ;
V_27 = F_13 ( F_14 ( V_35 ) ) ;
if ( ! ( V_27 & V_36 ) ) {
V_13 |= V_15 ;
} else {
V_26 =
F_1 ( F_15
( 0 , F_16 ( V_37 , 0 ) ,
V_38 ) ) ;
if ( ! ( V_26 & V_39 ) ) {
F_17
( L_1 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
V_13 |= V_14 ;
}
V_25 = F_12 ( V_40 , 1024 * 1024 ) ;
V_41 . V_25 = ( unsigned long ) V_25 ;
F_19 ( ( unsigned long ) V_25 ) ;
#ifdef F_20
V_26 = F_1 ( F_15 ( 0 , F_16 ( V_17 , 0 ) ,
V_38 ) ) ;
if ( V_26 & V_39 ) {
V_13 |= V_18 ;
V_42 = ( unsigned long )
F_12 ( V_43 ,
4 * 1024 * 1024 ) ;
}
#endif
F_21 ( & V_41 ) ;
#ifdef F_22
F_23 ( & V_44 , 0 , V_45 - 1 , 1 ) ;
#endif
return 0 ;
}
