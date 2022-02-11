static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
V_5 = * V_6 ;
return V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
* V_6 = V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
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
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
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
F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_12 ;
}
static int F_6 ( const struct V_13 * V_14 )
{
if ( V_14 -> V_2 -> V_15 == NULL )
return 0 ;
switch ( V_14 -> V_2 -> V_15 -> V_3 ) {
case 0x8 :
return V_16 ;
case 0x9 :
return V_17 ;
case 0xa :
return V_18 ;
case 0xb :
return V_19 ;
}
F_7 ( 1 , L_1 , V_14 -> V_2 -> V_15 -> V_3 ) ;
return 0 ;
}
int T_2 F_8 ( const struct V_13 * V_14 , T_3 V_20 , T_3 V_21 )
{
return F_6 ( V_14 ) ;
}
int F_9 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_10 ( void )
{
T_4 V_22 , V_23 ;
int V_24 , V_25 ;
T_1 V_26 ;
V_24 = 0 ;
V_23 = F_11 ( V_24 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_22 = F_12 ( F_13 ( V_24 , V_25 ) ) ;
if ( F_14 ( V_22 , 0 ) == 0xffffffff )
continue;
V_26 = F_15 ( V_23 , V_27 + V_25 ) ;
F_16 ( V_22 , V_28 , V_26 ) ;
V_26 = F_15 ( V_23 , V_29 + V_25 ) ;
F_16 ( V_22 , V_30 ,
V_26 | 0xfff ) ;
V_26 = F_15 ( V_23 , V_31 + V_25 ) ;
F_16 ( V_22 , V_32 , V_26 ) ;
V_26 = F_15 ( V_23 , V_33 + V_25 ) ;
F_16 ( V_22 , V_34 , V_26 | 0xfff ) ;
}
return 0 ;
}
static int T_2 F_17 ( void )
{
F_18 ( V_35 ) ;
V_7 = F_19 ( V_36 , 64 << 20 ) ;
V_37 . V_38 = 0 ;
V_37 . V_39 = ~ 0 ;
F_10 () ;
F_20 ( V_40 ) ;
V_41 . V_42 = V_40 ;
F_21 ( & V_41 ) ;
F_22 ( L_2 , & V_43 ,
& V_44 ) ;
return 0 ;
}
