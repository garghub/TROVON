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
if ( V_7 == 0 )
return - 1 ;
return V_8 - 1 + V_7 ;
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
if ( V_13 & V_15 )
return 0 ;
else
return 1 ;
} else
return 1 ;
}
static int F_7 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_17 , int V_18 , T_1 * V_19 )
{
T_1 V_3 = 0 ;
if ( ( V_18 == 2 ) && ( V_17 & 1 ) )
return V_20 ;
else if ( ( V_18 == 4 ) && ( V_17 & 3 ) )
return V_20 ;
if ( F_5 ( V_10 , V_11 ) )
V_3 = F_1 ( F_8 ( V_10 , V_11 , V_17 ) ) ;
else
V_3 = 0xFFFFFFFF ;
if ( V_18 == 1 )
* V_19 = ( V_3 >> ( ( V_17 & 3 ) << 3 ) ) & 0xff ;
else if ( V_18 == 2 )
* V_19 = ( V_3 >> ( ( V_17 & 3 ) << 3 ) ) & 0xffff ;
else
* V_19 = V_3 ;
return V_21 ;
}
static int F_9 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_17 , int V_18 , T_1 V_19 )
{
T_1 V_22 = F_8 ( V_10 , V_11 , V_17 ) ;
T_1 V_3 = 0 ;
if ( ( V_18 == 2 ) && ( V_17 & 1 ) )
return V_20 ;
else if ( ( V_18 == 4 ) && ( V_17 & 3 ) )
return V_20 ;
if ( ! F_5 ( V_10 , V_11 ) )
return V_20 ;
V_3 = F_1 ( V_22 ) ;
if ( V_18 == 1 )
V_3 = ( V_3 & ~ ( 0xff << ( ( V_17 & 3 ) << 3 ) ) ) |
( V_19 << ( ( V_17 & 3 ) << 3 ) ) ;
else if ( V_18 == 2 )
V_3 = ( V_3 & ~ ( 0xffff << ( ( V_17 & 3 ) << 3 ) ) ) |
( V_19 << ( ( V_17 & 3 ) << 3 ) ) ;
else
V_3 = V_19 ;
F_2 ( V_22 , V_3 ) ;
return V_21 ;
}
static int T_3 F_10 ( void )
{
T_4 V_23 ;
T_5 V_24 ;
V_25 = 1 ;
V_26 = 0x00008000UL ;
V_27 = 0x01000000UL ;
V_28 . V_29 = 0xffffffffUL ;
V_30 . V_29 = 0xffffffffUL ;
V_2 = F_11 ( V_31 , 16 * 1024 * 1024 ) ;
V_24 = F_12 ( F_13 ( V_32 ) ) ;
if ( ! ( V_24 & V_33 ) ) {
V_13 |= V_15 ;
} else {
V_23 = F_1 ( F_14 ( 0 , F_15 ( V_34 , 0 ) ,
V_35 ) ) ;
if ( ! ( V_23 & V_36 ) ) {
F_16
( L_1 ) ;
F_17 ( V_2 ) ;
return 1 ;
}
V_13 |= V_14 ;
}
V_23 = F_1 ( F_14 ( 0 , F_15 ( V_34 , 0 ) , 0x40 ) ) ;
F_2 ( F_14 ( 0 , F_15 ( V_34 , 0 ) , 0x40 ) ,
V_23 | 0x10 ) ;
V_23 = F_1 ( F_14 ( 0 , F_15 ( V_34 , 0 ) , 0x40 ) ) ;
V_37 . V_38 = ( unsigned long )
F_11 ( V_39 , 65536 ) ;
V_37 . V_38 -= V_37 . V_40 ;
F_18 ( V_37 . V_38 ) ;
F_19 ( & V_37 ) ;
#ifdef F_20
F_21 ( & V_41 , 0 , V_42 - 1 , 1 ) ;
#endif
return 0 ;
}
