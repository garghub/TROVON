static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 * V_6 ;
V_4 &= ~ 3 ;
if ( V_2 -> V_7 == 0 && F_2 ( V_3 ) == 1 && V_4 == 0x954 )
return 0xffffffff ;
V_6 = ( T_1 * ) ( V_8 +
F_3 ( V_2 -> V_7 , V_3 , V_4 ) ) ;
V_5 = * V_6 ;
return V_5 ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_8 +
F_3 ( V_2 -> V_7 , V_3 , V_4 & ~ 3 ) ) ;
* V_6 = V_5 ;
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
static struct V_13 * F_7 ( const struct V_13 * V_14 )
{
struct V_1 * V_2 , * V_15 ;
V_2 = V_14 -> V_2 ;
for ( V_15 = V_2 -> V_16 ; V_15 && V_15 -> V_7 != 0 ; V_15 = V_15 -> V_16 )
V_2 = V_15 ;
return V_15 ? V_2 -> V_17 : NULL ;
}
static inline int F_8 ( int V_18 )
{
return V_19 + V_18 ;
}
int T_2 F_9 ( const struct V_13 * V_14 , T_3 V_20 , T_3 V_21 )
{
struct V_13 * V_22 ;
int V_23 , V_24 ;
V_22 = F_7 ( V_14 ) ;
if ( V_22 == NULL )
return 0 ;
V_24 = F_10 ( V_22 -> V_3 ) ;
V_23 = F_2 ( V_22 -> V_3 ) ;
return F_11 ( V_23 / 8 , F_8 ( V_24 ) ) ;
}
int F_12 ( struct V_13 * V_14 )
{
return 0 ;
}
static void F_13 ( int V_25 , int V_18 )
{
T_4 V_26 , V_27 ;
T_1 V_28 ;
V_26 = F_14 ( V_25 ) ;
V_27 = F_15 ( V_25 , V_18 ) ;
V_28 = F_16 ( V_26 , V_29 + V_18 ) ;
F_17 ( V_27 , V_30 , V_28 ) ;
V_28 = F_16 ( V_26 , V_31 + V_18 ) ;
F_17 ( V_27 , V_32 , V_28 | 0xfff ) ;
V_28 = F_16 ( V_26 , V_33 + V_18 ) ;
F_17 ( V_27 , V_34 , V_28 ) ;
V_28 = F_16 ( V_26 , V_35 + V_18 ) ;
F_17 ( V_27 , V_36 , V_28 | 0xfff ) ;
}
static inline void F_13 ( int V_25 , int V_18 ) {}
static int T_2 F_18 ( void )
{
struct V_37 * V_38 ;
T_4 V_39 ;
int V_18 , V_40 ;
T_1 V_28 ;
F_19 ( V_41 ) ;
V_8 = F_20 ( V_42 , 64 << 20 ) ;
V_43 . V_44 = 0 ;
V_43 . V_45 = ~ 0 ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
V_38 = F_21 ( V_40 ) ;
if ( ! V_38 -> V_47 )
continue;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_39 = F_15 ( V_40 , V_18 ) ;
if ( F_22 ( V_39 , 0 ) == 0xffffffff )
continue;
F_13 ( V_40 , V_18 ) ;
V_28 = F_22 ( V_39 , 0xf ) ;
V_28 &= ~ 0x1fu ;
V_28 |= ( 1 << 8 ) | F_8 ( V_18 ) ;
F_17 ( V_39 , 0xf , V_28 ) ;
F_23 ( L_1 , V_40 , V_18 ) ;
}
}
F_24 ( V_48 ) ;
V_49 . V_50 = V_48 ;
F_25 ( & V_49 ) ;
F_23 ( L_2 , & V_51 ,
& V_52 ) ;
return 0 ;
}
