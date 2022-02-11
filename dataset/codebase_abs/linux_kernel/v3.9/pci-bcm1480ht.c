static inline T_1 F_1 ( T_1 V_1 )
{
return * ( T_1 * ) ( V_2 + ( V_1 & ~ 3 ) ) ;
}
static inline void F_2 ( T_1 V_1 , T_1 V_3 )
{
* ( T_1 * ) ( V_2 + ( V_1 & ~ 3 ) ) = V_3 ;
}
static int F_3 ( struct V_4 * V_5 , int V_6 )
{
T_1 V_7 ;
if ( ! ( V_8 & ( V_9 | V_10 ) ) )
return 0 ;
if ( V_5 -> V_11 == 0 ) {
V_7 = F_4 ( V_6 ) ;
if ( V_8 & V_10 )
return 0 ;
}
return 1 ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int V_6 ,
int V_12 , int V_13 , T_1 * V_14 )
{
T_1 V_3 = 0 ;
if ( ( V_13 == 2 ) && ( V_12 & 1 ) )
return V_15 ;
else if ( ( V_13 == 4 ) && ( V_12 & 3 ) )
return V_15 ;
if ( F_3 ( V_5 , V_6 ) )
V_3 = F_1 ( F_6 ( V_5 , V_6 , V_12 ) ) ;
else
V_3 = 0xFFFFFFFF ;
if ( V_13 == 1 )
* V_14 = ( V_3 >> ( ( V_12 & 3 ) << 3 ) ) & 0xff ;
else if ( V_13 == 2 )
* V_14 = ( V_3 >> ( ( V_12 & 3 ) << 3 ) ) & 0xffff ;
else
* V_14 = V_3 ;
return V_16 ;
}
static int F_7 ( struct V_4 * V_5 , unsigned int V_6 ,
int V_12 , int V_13 , T_1 V_14 )
{
T_1 V_17 = F_6 ( V_5 , V_6 , V_12 ) ;
T_1 V_3 = 0 ;
if ( ( V_13 == 2 ) && ( V_12 & 1 ) )
return V_15 ;
else if ( ( V_13 == 4 ) && ( V_12 & 3 ) )
return V_15 ;
if ( ! F_3 ( V_5 , V_6 ) )
return V_15 ;
V_3 = F_1 ( V_17 ) ;
if ( V_13 == 1 )
V_3 = ( V_3 & ~ ( 0xff << ( ( V_12 & 3 ) << 3 ) ) ) |
( V_14 << ( ( V_12 & 3 ) << 3 ) ) ;
else if ( V_13 == 2 )
V_3 = ( V_3 & ~ ( 0xffff << ( ( V_12 & 3 ) << 3 ) ) ) |
( V_14 << ( ( V_12 & 3 ) << 3 ) ) ;
else
V_3 = V_14 ;
F_2 ( V_17 , V_3 ) ;
return V_16 ;
}
static int F_8 ( void )
{
return 0 ;
}
static int T_2 F_9 ( void )
{
V_2 = F_10 ( V_18 , 16 * 1024 * 1024 ) ;
V_8 |= V_9 ;
V_19 = ( unsigned long )
F_10 ( V_20 ,
4 * 1024 * 1024 ) ;
V_21 . V_22 = ( unsigned long )
F_10 ( V_23 , 65536 ) ;
V_21 . V_22 -= V_21 . V_24 ;
F_11 ( & V_21 ) ;
return 0 ;
}
