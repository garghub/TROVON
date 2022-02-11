static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 * V_6 ;
V_4 &= ~ 3 ;
if ( F_2 () ) {
if ( V_2 -> V_7 == 0 ) {
if ( F_3 ( V_3 ) != 0 ||
! F_4 ( F_5 ( V_3 ) ) )
return 0xffffffff ;
} else if ( V_2 -> V_8 -> V_7 == 0 ) {
if ( F_3 ( V_3 ) == 0 )
return 0xffffffff ;
if ( V_3 == 44 )
return 0xffffffff ;
}
} else if ( V_2 -> V_7 == 0 && F_3 ( V_3 ) == 1 && V_4 == 0x954 ) {
return 0xffffffff ;
}
V_6 = ( T_1 * ) ( V_9 +
F_6 ( V_2 -> V_7 , V_3 , V_4 ) ) ;
V_5 = * V_6 ;
return V_5 ;
}
static inline void F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_9 +
F_6 ( V_2 -> V_7 , V_3 , V_4 & ~ 3 ) ) ;
* V_6 = V_5 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_10 , T_1 * V_11 )
{
T_1 V_5 ;
if ( ( V_10 == 2 ) && ( V_4 & 1 ) )
return V_12 ;
else if ( ( V_10 == 4 ) && ( V_4 & 3 ) )
return V_12 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_10 == 1 )
* V_11 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xff ;
else if ( V_10 == 2 )
* V_11 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xffff ;
else
* V_11 = V_5 ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_10 , T_1 V_11 )
{
T_1 V_5 ;
if ( ( V_10 == 2 ) && ( V_4 & 1 ) )
return V_12 ;
else if ( ( V_10 == 4 ) && ( V_4 & 3 ) )
return V_12 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_10 == 1 )
V_5 = ( V_5 & ~ ( 0xff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_11 << ( ( V_4 & 3 ) << 3 ) ) ;
else if ( V_10 == 2 )
V_5 = ( V_5 & ~ ( 0xffff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_11 << ( ( V_4 & 3 ) << 3 ) ) ;
else
V_5 = V_11 ;
F_7 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_13 ;
}
struct V_14 * F_10 ( const struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_16 ;
V_2 = V_15 -> V_2 ;
if ( F_2 () ) {
for ( V_16 = V_2 -> V_8 ; V_16 && V_16 -> V_8 && V_16 -> V_8 -> V_7 != 0 ;
V_16 = V_16 -> V_8 )
V_2 = V_16 ;
return ( V_16 && V_16 -> V_8 ) ? V_2 -> V_17 : NULL ;
} else {
for ( V_16 = V_2 -> V_8 ; V_16 && V_16 -> V_7 != 0 ; V_16 = V_16 -> V_8 )
V_2 = V_16 ;
return V_16 ? V_2 -> V_17 : NULL ;
}
}
int F_11 ( const struct V_14 * V_18 )
{
if ( F_2 () )
return F_5 ( V_18 -> V_2 -> V_17 -> V_3 ) ;
else
return F_3 ( V_18 -> V_3 ) / 8 ;
}
int F_12 ( const struct V_14 * V_15 , T_2 V_19 , T_2 V_20 )
{
struct V_14 * V_18 ;
int V_21 , V_22 ;
V_18 = F_10 ( V_15 ) ;
if ( V_18 == NULL )
return 0 ;
V_21 = F_5 ( V_18 -> V_3 ) ;
V_22 = F_11 ( V_18 ) ;
return F_13 ( V_22 , F_14 ( V_21 ) ) ;
}
int F_15 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_16 ( int V_22 , int V_23 )
{
T_3 V_24 , V_25 ;
T_1 V_26 ;
V_24 = F_17 ( V_22 ) ;
V_25 = F_18 ( V_22 , V_23 ) ;
if ( F_2 () ) {
V_26 = F_19 ( V_24 ,
V_27 + V_23 ) ;
F_20 ( V_25 , V_28 , V_26 ) ;
V_26 = F_19 ( V_24 ,
V_29 + V_23 ) ;
F_20 ( V_25 ,
V_30 , V_26 | 0xfff ) ;
V_26 = F_19 ( V_24 ,
V_31 + V_23 ) ;
F_20 ( V_25 , V_32 , V_26 ) ;
V_26 = F_19 ( V_24 ,
V_33 + V_23 ) ;
F_20 ( V_25 ,
V_34 , V_26 | 0xfff ) ;
} else {
V_26 = F_19 ( V_24 , V_35 + V_23 ) ;
F_20 ( V_25 , V_36 , V_26 ) ;
V_26 = F_19 ( V_24 ,
V_37 + V_23 ) ;
F_20 ( V_25 , V_38 , V_26 | 0xfff ) ;
V_26 = F_19 ( V_24 , V_39 + V_23 ) ;
F_20 ( V_25 , V_40 , V_26 ) ;
V_26 = F_19 ( V_24 , V_41 + V_23 ) ;
F_20 ( V_25 , V_42 , V_26 | 0xfff ) ;
}
}
static inline void F_16 ( int V_22 , int V_23 ) {}
static int T_4 F_21 ( void )
{
T_3 V_43 ;
int V_23 , V_44 ;
T_1 V_26 ;
F_22 ( V_45 ) ;
V_9 = F_23 ( V_46 , 64 << 20 ) ;
V_47 . V_48 = 0 ;
V_47 . V_49 = ~ 0 ;
for ( V_44 = 0 ; V_44 < V_50 ; V_44 ++ ) {
if ( ! F_4 ( V_44 ) )
continue;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
V_43 = F_18 ( V_44 , V_23 ) ;
if ( F_24 ( V_43 , 0 ) == 0xffffffff )
continue;
F_16 ( V_44 , V_23 ) ;
F_25 ( V_44 , V_23 ) ;
V_26 = F_24 ( V_43 , 0xf ) ;
V_26 &= ~ 0x1ffu ;
V_26 |= ( 1 << 8 ) | F_14 ( V_23 ) ;
F_20 ( V_43 , 0xf , V_26 ) ;
F_26 ( L_1 , V_44 , V_23 ) ;
}
}
F_27 ( V_52 ) ;
V_53 . V_54 = V_52 ;
F_28 ( & V_53 ) ;
F_26 ( L_2 , & V_55 ,
& V_56 ) ;
return 0 ;
}
