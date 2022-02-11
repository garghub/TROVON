static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
V_5 = * V_6 ;
return F_3 ( V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
* V_6 = F_3 ( V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_9 , T_1 * V_10 )
{
T_1 V_5 ;
if ( ( V_9 == 2 ) && ( V_4 & 1 ) )
return V_11 ;
else if ( ( V_9 == 4 ) && ( V_4 & 3 ) )
return V_11 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_9 == 1 )
* V_10 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xff ;
else if ( V_9 == 2 )
* V_10 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xffff ;
else
* V_10 = V_5 ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_9 , T_1 V_10 )
{
T_1 V_5 ;
if ( ( V_9 == 2 ) && ( V_4 & 1 ) )
return V_11 ;
else if ( ( V_9 == 4 ) && ( V_4 & 3 ) )
return V_11 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_9 == 1 )
V_5 = ( V_5 & ~ ( 0xff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_4 & 3 ) << 3 ) ) ;
else if ( V_9 == 2 )
V_5 = ( V_5 & ~ ( 0xffff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_4 & 3 ) << 3 ) ) ;
else
V_5 = V_10 ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_12 ;
}
int T_2 F_7 ( const struct V_13 * V_14 , T_3 V_15 , T_3 V_16 )
{
if ( ! F_8 () )
return V_17 ;
if ( V_14 -> V_2 -> V_18 == NULL )
return 0 ;
switch ( V_14 -> V_2 -> V_18 -> V_3 ) {
case 0x0 :
return V_19 ;
case 0x8 :
return V_20 ;
case 0x10 :
if ( F_9 () )
return V_21 ;
else
return V_22 ;
case 0x18 :
if ( F_9 () )
return V_23 ;
else
return V_24 ;
}
F_10 ( 1 , L_1 , V_14 -> V_2 -> V_18 -> V_3 ) ;
return 0 ;
}
int F_11 ( struct V_13 * V_14 )
{
return 0 ;
}
static int T_2 F_12 ( void )
{
V_25 = 1 ;
V_7 = F_13 ( V_26 , 16 << 20 ) ;
V_27 . V_28 = 0 ;
V_27 . V_29 = ~ 0 ;
F_14 ( V_30 ) ;
V_31 . V_32 = V_30 ;
F_15 ( L_2 ) ;
F_16 ( & V_31 ) ;
return 0 ;
}
