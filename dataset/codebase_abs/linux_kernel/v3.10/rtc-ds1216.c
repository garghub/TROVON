static void F_1 ( T_1 T_2 * V_1 , T_1 * V_2 )
{
unsigned char V_3 ;
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_3 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
V_3 |= ( F_2 ( V_1 ) & 0x1 ) << V_5 ;
V_2 [ V_4 ] = V_3 ;
}
}
static void F_3 ( T_1 T_2 * V_1 , const T_1 * V_2 )
{
unsigned char V_3 ;
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_3 = V_2 [ V_4 ] ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_4 ( V_3 , V_1 ) ;
V_3 = V_3 >> 1 ;
}
}
}
static void F_5 ( T_1 T_2 * V_1 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 , V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_8 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 V_16 ;
F_5 ( V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 , ( T_1 * ) & V_16 ) ;
V_10 -> V_17 = F_9 ( V_16 . V_18 ) ;
V_10 -> V_19 = F_9 ( V_16 . V_20 ) ;
if ( V_16 . V_21 & V_22 ) {
V_10 -> V_23 = F_9 ( V_16 . V_21 & 0x1f ) ;
if ( V_16 . V_21 & V_24 )
V_10 -> V_23 += 12 ;
} else
V_10 -> V_23 = F_9 ( V_16 . V_21 & 0x3f ) ;
V_10 -> V_25 = ( V_16 . V_26 & 7 ) - 1 ;
V_10 -> V_27 = F_9 ( V_16 . V_28 & 0x3f ) ;
V_10 -> V_29 = F_9 ( V_16 . V_30 & 0x1f ) ;
V_10 -> V_31 = F_9 ( V_16 . V_32 ) ;
if ( V_10 -> V_31 < 70 )
V_10 -> V_31 += 100 ;
return F_10 ( V_10 ) ;
}
static int F_11 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_8 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 V_16 ;
F_5 ( V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 , ( T_1 * ) & V_16 ) ;
V_16 . V_33 = 0 ;
V_16 . V_18 = F_12 ( V_10 -> V_17 ) ;
V_16 . V_20 = F_12 ( V_10 -> V_19 ) ;
V_16 . V_21 &= V_22 ;
if ( V_16 . V_21 && V_10 -> V_23 > 12 ) {
V_16 . V_21 |= V_24 ;
V_10 -> V_23 -= 12 ;
}
V_16 . V_21 |= F_12 ( V_10 -> V_23 ) ;
V_16 . V_26 &= ~ 7 ;
V_16 . V_26 |= V_10 -> V_25 ;
V_16 . V_28 = F_12 ( V_10 -> V_27 ) ;
V_16 . V_30 = F_12 ( V_10 -> V_29 ) ;
V_16 . V_32 = F_12 ( V_10 -> V_31 % 100 ) ;
F_5 ( V_14 -> V_1 ) ;
F_3 ( V_14 -> V_1 , ( T_1 * ) & V_16 ) ;
return 0 ;
}
static int T_3 F_13 ( struct V_11 * V_12 )
{
struct V_34 * V_35 ;
struct V_13 * V_14 ;
T_1 V_36 [ 8 ] ;
V_35 = F_14 ( V_12 , V_37 , 0 ) ;
if ( ! V_35 )
return - V_38 ;
V_14 = F_15 ( & V_12 -> V_8 , sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_40 ;
F_16 ( V_12 , V_14 ) ;
V_14 -> V_1 = F_17 ( & V_12 -> V_8 , V_35 ) ;
if ( F_18 ( V_14 -> V_1 ) )
return F_19 ( V_14 -> V_1 ) ;
V_14 -> V_41 = F_20 ( & V_12 -> V_8 , L_1 ,
& V_42 , V_43 ) ;
if ( F_18 ( V_14 -> V_41 ) )
return F_19 ( V_14 -> V_41 ) ;
F_1 ( V_14 -> V_1 , V_36 ) ;
return 0 ;
}
static int T_4 F_21 ( struct V_11 * V_12 )
{
return 0 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_44 , F_13 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_44 ) ;
}
