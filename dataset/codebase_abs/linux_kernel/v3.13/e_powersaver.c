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
F_8 ( V_1 , 0 ) ;
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
F_16 ( V_22 L_1 ,
V_21 * 16 + 700 ) ;
V_20 = ( V_11 >> 8 ) & 0xff ;
F_16 ( V_22 L_2 ,
V_20 ) ;
}
#endif
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int V_23 )
{
struct V_9 * V_10 ;
unsigned int V_8 = V_7 -> V_8 ;
unsigned int V_16 ;
int V_24 ;
if ( F_13 ( V_13 [ V_8 ] == NULL ) )
return - V_18 ;
V_10 = V_13 [ V_8 ] ;
V_16 = V_10 -> V_25 [ V_23 ] . V_26 & 0xffff ;
V_24 = F_11 ( V_10 , V_7 , V_16 ) ;
if ( V_24 )
F_16 ( V_27 L_3 ) ;
return V_24 ;
}
static int F_18 ( struct V_6 * V_7 )
{
unsigned int V_17 ;
T_1 V_11 , V_12 ;
T_3 V_28 ;
T_2 V_20 , V_21 ;
T_2 V_29 , V_30 ;
T_2 V_31 , V_32 ;
T_2 V_33 = 0 ;
T_1 V_15 ;
struct V_9 * V_10 ;
struct V_34 * V_35 = & F_19 ( 0 ) ;
struct V_36 * V_37 ;
int V_38 , V_39 , V_40 ;
int V_24 ;
int V_41 ;
#if V_42 V_43 || V_42 V_44
unsigned int V_45 ;
#endif
if ( V_7 -> V_8 != 0 )
return - V_18 ;
F_16 ( V_22 L_4 ) ;
switch ( V_35 -> V_46 ) {
case 10 :
F_10 ( 0x1153 , V_11 , V_12 ) ;
V_33 = ( ( ( V_11 >> 2 ) ^ V_11 ) >> 18 ) & 3 ;
F_16 ( V_47 L_5 ) ;
break;
case 13 :
F_10 ( 0x1154 , V_11 , V_12 ) ;
V_33 = ( ( ( V_11 >> 4 ) ^ ( V_11 >> 2 ) ) ) & 0x000000ff ;
F_16 ( V_47 L_6 ) ;
break;
}
switch ( V_33 ) {
case V_48 :
F_16 ( V_47 L_7 ) ;
break;
case V_49 :
F_16 ( V_47 L_8 ) ;
break;
case V_50 :
F_16 ( V_47 L_9 ) ;
break;
case V_51 :
F_16 ( V_47 L_10 ) ;
break;
case V_52 :
F_16 ( V_47 L_11 ) ;
return - V_18 ;
break;
}
F_20 ( V_53 , V_28 ) ;
if ( ! ( V_28 & V_54 ) ) {
V_28 |= V_54 ;
F_21 ( V_53 , V_28 ) ;
F_20 ( V_53 , V_28 ) ;
if ( ! ( V_28 & V_54 ) ) {
F_16 ( V_22 L_12 ) ;
return - V_18 ;
}
}
F_10 ( V_14 , V_11 , V_12 ) ;
V_21 = V_11 & 0xff ;
F_16 ( V_22 L_1 ,
V_21 * 16 + 700 ) ;
V_20 = ( V_11 >> 8 ) & 0xff ;
F_16 ( V_22 L_2 , V_20 ) ;
V_30 = V_12 & 0xff ;
F_16 ( V_22 L_13 ,
V_30 * 16 + 700 ) ;
V_29 = ( V_12 >> 8 ) & 0xff ;
F_16 ( V_22 L_14 , V_29 ) ;
V_32 = ( V_12 >> 16 ) & 0xff ;
F_16 ( V_22 L_15 ,
V_32 * 16 + 700 ) ;
V_31 = ( V_12 >> 24 ) & 0xff ;
F_16 ( V_22 L_16 , V_31 ) ;
if ( V_20 == 0 || V_29 == 0
|| V_31 == 0 )
return - V_55 ;
if ( V_20 > V_29
|| V_29 <= V_31 )
return - V_55 ;
if ( V_21 > 0x1f || V_30 > 0x1f )
return - V_55 ;
if ( V_30 < V_32
|| V_21 < V_32
|| V_21 > V_30 )
return - V_55 ;
if ( ! V_56 && V_29 != V_20 ) {
F_16 ( V_22 L_17
L_18 ) ;
F_16 ( V_22 L_19
L_20 ) ;
return - V_55 ;
}
if ( ! V_57 && V_30 != V_21 ) {
F_16 ( V_22 L_17
L_21 ) ;
F_16 ( V_22 L_22
L_23 ) ;
return - V_55 ;
}
V_15 = V_58 / V_20 ;
#if V_42 V_43 || V_42 V_44
if ( ! V_59 && ! F_1 () ) {
if ( ! F_22 ( V_7 -> V_8 , & V_45 ) ) {
F_16 ( V_22 L_24 ,
V_45 / 1000000 ,
( V_45 % 1000000 ) / 10000 ) ;
F_7 ( V_7 ) ;
if ( V_45 && V_29 * V_15 > V_45 ) {
F_16 ( V_22 L_25 ) ;
return - V_55 ;
}
}
}
#endif
if ( V_33 == V_48 && V_60 ) {
T_1 V_61 ;
V_61 = ( V_60 - 700 ) / 16 ;
if ( V_61 >= V_32 && V_61 <= V_30 ) {
F_16 ( V_22 L_26 ,
V_61 * 16 + 700 ) ;
V_30 = V_61 ;
}
}
if ( V_33 == V_48 )
V_41 = V_29 - V_31 + 1 ;
else
V_41 = 2 ;
V_10 = F_2 ( sizeof( * V_10 )
+ ( V_41 + 1 ) * sizeof( struct V_36 ) ,
V_2 ) ;
if ( ! V_10 )
return - V_3 ;
V_13 [ 0 ] = V_10 ;
V_10 -> V_15 = V_15 ;
#if V_42 V_43 || V_42 V_44
V_10 -> V_62 = V_45 ;
#endif
V_37 = & V_10 -> V_25 [ 0 ] ;
if ( V_33 != V_48 ) {
V_37 [ 0 ] . V_63 = V_15 * V_31 ;
V_37 [ 0 ] . V_26 = ( V_31 << 8 ) | V_32 ;
V_37 [ 1 ] . V_63 = V_15 * V_29 ;
V_37 [ 1 ] . V_26 = ( V_29 << 8 ) | V_30 ;
V_37 [ 2 ] . V_63 = V_64 ;
} else {
V_38 = 0 ;
V_39 = ( ( V_30 - V_32 ) * 256 )
/ ( V_29 - V_31 ) ;
for ( V_17 = V_31 ; V_17 <= V_29 ; V_17 ++ ) {
V_40 = ( V_38 * V_39 ) / 256 + V_32 ;
V_37 [ V_38 ] . V_63 = V_15 * V_17 ;
V_37 [ V_38 ] . V_26 = ( V_17 << 8 ) | V_40 ;
V_38 ++ ;
}
V_37 [ V_38 ] . V_63 = V_64 ;
}
V_7 -> V_65 . V_66 = 140000 ;
V_24 = F_23 ( V_7 , & V_10 -> V_25 [ 0 ] ) ;
if ( V_24 ) {
F_4 ( V_10 ) ;
return V_24 ;
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
unsigned int V_8 = V_7 -> V_8 ;
F_25 ( V_7 -> V_8 ) ;
F_4 ( V_13 [ V_8 ] ) ;
V_13 [ V_8 ] = NULL ;
return 0 ;
}
static int T_4 F_26 ( void )
{
if ( ! F_27 ( V_67 ) || V_68 . V_46 < 10 )
return - V_18 ;
if ( F_28 ( & V_69 ) )
return - V_55 ;
return 0 ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_69 ) ;
}
