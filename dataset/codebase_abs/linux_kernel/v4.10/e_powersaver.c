static int F_1 ( void )
{
V_1 = F_2 ( sizeof( * V_1 ) ,
V_2 ) ;
if ( ! V_1 )
return - V_3 ;
if ( ! F_3 ( & V_1 -> V_4 ,
V_2 ) ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
return - V_3 ;
}
if ( F_5 ( V_1 , 0 ) ) {
F_6 ( V_1 -> V_4 ) ;
F_4 ( V_1 ) ;
V_1 = NULL ;
return - V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
if ( V_1 ) {
F_8 ( 0 ) ;
F_6 ( V_1 -> V_4 ) ;
F_4 ( V_1 ) ;
V_1 = NULL ;
}
return 0 ;
}
static unsigned int F_9 ( unsigned int V_8 )
{
struct V_9 * V_10 ;
T_1 V_11 , V_12 ;
if ( V_8 )
return 0 ;
V_10 = V_13 [ V_8 ] ;
if ( V_10 == NULL )
return 0 ;
F_10 ( V_14 , V_11 , V_12 ) ;
return V_10 -> V_15 * ( ( V_11 >> 8 ) & 0xff ) ;
}
static int F_11 ( struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_1 V_16 )
{
T_1 V_11 , V_12 ;
int V_17 ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_17 = 0 ;
while ( V_11 & ( ( 1 << 16 ) | ( 1 << 17 ) ) ) {
F_12 ( 16 ) ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_17 ++ ;
if ( F_13 ( V_17 > 64 ) ) {
return - V_18 ;
}
}
F_14 ( V_19 , V_16 & 0xffff , 0 ) ;
V_17 = 0 ;
do {
F_12 ( 16 ) ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_17 ++ ;
if ( F_13 ( V_17 > 64 ) ) {
return - V_18 ;
}
} while ( V_11 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
#ifdef F_15
{
T_2 V_20 , V_21 ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_21 = V_11 & 0xff ;
F_16 ( L_1 , V_21 * 16 + 700 ) ;
V_20 = ( V_11 >> 8 ) & 0xff ;
F_16 ( L_2 , V_20 ) ;
}
#endif
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int V_22 )
{
struct V_9 * V_10 ;
unsigned int V_8 = V_7 -> V_8 ;
unsigned int V_16 ;
int V_23 ;
if ( F_13 ( V_13 [ V_8 ] == NULL ) )
return - V_18 ;
V_10 = V_13 [ V_8 ] ;
V_16 = V_10 -> V_24 [ V_22 ] . V_25 & 0xffff ;
V_23 = F_11 ( V_10 , V_7 , V_16 ) ;
if ( V_23 )
F_18 ( L_3 ) ;
return V_23 ;
}
static int F_19 ( struct V_6 * V_7 )
{
unsigned int V_17 ;
T_1 V_11 , V_12 ;
T_3 V_26 ;
T_2 V_20 , V_21 ;
T_2 V_27 , V_28 ;
T_2 V_29 , V_30 ;
T_2 V_31 = 0 ;
T_1 V_15 ;
struct V_9 * V_10 ;
struct V_32 * V_33 = & F_20 ( 0 ) ;
struct V_34 * V_35 ;
int V_36 , V_37 , V_38 ;
int V_23 ;
int V_39 ;
#if F_21 ( V_40 )
unsigned int V_41 ;
#endif
if ( V_7 -> V_8 != 0 )
return - V_18 ;
F_16 ( L_4 ) ;
switch ( V_33 -> V_42 ) {
case 10 :
F_10 ( 0x1153 , V_11 , V_12 ) ;
V_31 = ( ( ( V_11 >> 2 ) ^ V_11 ) >> 18 ) & 3 ;
F_22 ( L_5 ) ;
break;
case 13 :
F_10 ( 0x1154 , V_11 , V_12 ) ;
V_31 = ( ( ( V_11 >> 4 ) ^ ( V_11 >> 2 ) ) ) & 0x000000ff ;
F_22 ( L_6 ) ;
break;
}
switch ( V_31 ) {
case V_43 :
F_22 ( L_7 ) ;
break;
case V_44 :
F_22 ( L_8 ) ;
break;
case V_45 :
F_22 ( L_9 ) ;
break;
case V_46 :
F_22 ( L_10 ) ;
break;
case V_47 :
F_22 ( L_11 ) ;
return - V_18 ;
break;
}
F_23 ( V_48 , V_26 ) ;
if ( ! ( V_26 & V_49 ) ) {
V_26 |= V_49 ;
F_24 ( V_48 , V_26 ) ;
F_23 ( V_48 , V_26 ) ;
if ( ! ( V_26 & V_49 ) ) {
F_16 ( L_12 ) ;
return - V_18 ;
}
}
F_10 ( V_14 , V_11 , V_12 ) ;
V_21 = V_11 & 0xff ;
F_16 ( L_1 , V_21 * 16 + 700 ) ;
V_20 = ( V_11 >> 8 ) & 0xff ;
F_16 ( L_2 , V_20 ) ;
V_28 = V_12 & 0xff ;
F_16 ( L_13 , V_28 * 16 + 700 ) ;
V_27 = ( V_12 >> 8 ) & 0xff ;
F_16 ( L_14 , V_27 ) ;
V_30 = ( V_12 >> 16 ) & 0xff ;
F_16 ( L_15 , V_30 * 16 + 700 ) ;
V_29 = ( V_12 >> 24 ) & 0xff ;
F_16 ( L_16 , V_29 ) ;
if ( V_20 == 0 || V_27 == 0
|| V_29 == 0 )
return - V_50 ;
if ( V_20 > V_27
|| V_27 <= V_29 )
return - V_50 ;
if ( V_21 > 0x1f || V_28 > 0x1f )
return - V_50 ;
if ( V_28 < V_30
|| V_21 < V_30
|| V_21 > V_28 )
return - V_50 ;
if ( ! V_51 && V_27 != V_20 ) {
F_16 ( L_17 ) ;
F_16 ( L_18 ) ;
return - V_50 ;
}
if ( ! V_52 && V_28 != V_21 ) {
F_16 ( L_19 ) ;
F_16 ( L_20 ) ;
return - V_50 ;
}
V_15 = V_53 / V_20 ;
#if F_21 ( V_40 )
if ( ! V_54 && ! F_1 () ) {
if ( ! F_25 ( V_7 -> V_8 , & V_41 ) ) {
F_16 ( L_21 ,
V_41 / 1000000 ,
( V_41 % 1000000 ) / 10000 ) ;
F_7 ( V_7 ) ;
if ( V_41 && V_27 * V_15 > V_41 ) {
F_16 ( L_22 ) ;
return - V_50 ;
}
}
}
#endif
if ( V_31 == V_43 && V_55 ) {
T_1 V_56 ;
V_56 = ( V_55 - 700 ) / 16 ;
if ( V_56 >= V_30 && V_56 <= V_28 ) {
F_16 ( L_23 , V_56 * 16 + 700 ) ;
V_28 = V_56 ;
}
}
if ( V_31 == V_43 )
V_39 = V_27 - V_29 + 1 ;
else
V_39 = 2 ;
V_10 = F_2 ( sizeof( * V_10 )
+ ( V_39 + 1 ) * sizeof( struct V_34 ) ,
V_2 ) ;
if ( ! V_10 )
return - V_3 ;
V_13 [ 0 ] = V_10 ;
V_10 -> V_15 = V_15 ;
#if F_21 ( V_40 )
V_10 -> V_57 = V_41 ;
#endif
V_35 = & V_10 -> V_24 [ 0 ] ;
if ( V_31 != V_43 ) {
V_35 [ 0 ] . V_58 = V_15 * V_29 ;
V_35 [ 0 ] . V_25 = ( V_29 << 8 ) | V_30 ;
V_35 [ 1 ] . V_58 = V_15 * V_27 ;
V_35 [ 1 ] . V_25 = ( V_27 << 8 ) | V_28 ;
V_35 [ 2 ] . V_58 = V_59 ;
} else {
V_36 = 0 ;
V_37 = ( ( V_28 - V_30 ) * 256 )
/ ( V_27 - V_29 ) ;
for ( V_17 = V_29 ; V_17 <= V_27 ; V_17 ++ ) {
V_38 = ( V_36 * V_37 ) / 256 + V_30 ;
V_35 [ V_36 ] . V_58 = V_15 * V_17 ;
V_35 [ V_36 ] . V_25 = ( V_17 << 8 ) | V_38 ;
V_36 ++ ;
}
V_35 [ V_36 ] . V_58 = V_59 ;
}
V_7 -> V_60 . V_61 = 140000 ;
V_23 = F_26 ( V_7 , & V_10 -> V_24 [ 0 ] ) ;
if ( V_23 ) {
F_4 ( V_10 ) ;
return V_23 ;
}
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
unsigned int V_8 = V_7 -> V_8 ;
F_4 ( V_13 [ V_8 ] ) ;
V_13 [ V_8 ] = NULL ;
return 0 ;
}
static int T_4 F_28 ( void )
{
if ( ! F_29 ( V_62 ) || V_63 . V_42 < 10 )
return - V_18 ;
if ( F_30 ( & V_64 ) )
return - V_50 ;
return 0 ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_64 ) ;
}
