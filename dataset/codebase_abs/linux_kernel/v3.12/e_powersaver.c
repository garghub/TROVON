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
struct V_17 V_18 ;
T_1 V_11 , V_12 ;
int V_19 = 0 ;
int V_20 ;
V_18 . V_21 = F_9 ( V_7 -> V_8 ) ;
V_18 . V_22 = V_10 -> V_15 * ( ( V_16 >> 8 ) & 0xff ) ;
F_12 ( V_7 , & V_18 , V_23 ) ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_20 = 0 ;
while ( V_11 & ( ( 1 << 16 ) | ( 1 << 17 ) ) ) {
F_13 ( 16 ) ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_20 ++ ;
if ( F_14 ( V_20 > 64 ) ) {
V_19 = - V_24 ;
goto V_25;
}
}
F_15 ( V_26 , V_16 & 0xffff , 0 ) ;
V_20 = 0 ;
do {
F_13 ( 16 ) ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_20 ++ ;
if ( F_14 ( V_20 > 64 ) ) {
V_19 = - V_24 ;
goto V_25;
}
} while ( V_11 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_25:
F_10 ( V_14 , V_11 , V_12 ) ;
V_18 . V_22 = V_10 -> V_15 * ( ( V_11 >> 8 ) & 0xff ) ;
#ifdef F_16
{
T_2 V_27 , V_28 ;
F_10 ( V_14 , V_11 , V_12 ) ;
V_28 = V_11 & 0xff ;
F_17 ( V_29 L_1 ,
V_28 * 16 + 700 ) ;
V_27 = ( V_11 >> 8 ) & 0xff ;
F_17 ( V_29 L_2 ,
V_27 ) ;
}
#endif
if ( V_19 )
V_18 . V_22 = V_18 . V_21 ;
F_12 ( V_7 , & V_18 , V_30 ) ;
return V_19 ;
}
static int F_18 ( struct V_6 * V_7 ,
unsigned int V_31 ,
unsigned int V_32 )
{
struct V_9 * V_10 ;
unsigned int V_33 = 0 ;
unsigned int V_8 = V_7 -> V_8 ;
unsigned int V_16 ;
int V_34 ;
if ( F_14 ( V_13 [ V_8 ] == NULL ) )
return - V_24 ;
V_10 = V_13 [ V_8 ] ;
if ( F_14 ( F_19 ( V_7 ,
& V_13 [ V_8 ] -> V_35 [ 0 ] ,
V_31 ,
V_32 ,
& V_33 ) ) ) {
return - V_36 ;
}
V_16 = V_10 -> V_35 [ V_33 ] . V_37 & 0xffff ;
V_34 = F_11 ( V_10 , V_7 , V_16 ) ;
if ( V_34 )
F_17 ( V_38 L_3 ) ;
return V_34 ;
}
static int F_20 ( struct V_6 * V_7 )
{
return F_21 ( V_7 ,
& V_13 [ V_7 -> V_8 ] -> V_35 [ 0 ] ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
unsigned int V_20 ;
T_1 V_11 , V_12 ;
T_3 V_39 ;
T_2 V_27 , V_28 ;
T_2 V_40 , V_41 ;
T_2 V_42 , V_43 ;
T_2 V_44 = 0 ;
T_1 V_15 ;
struct V_9 * V_10 ;
struct V_45 * V_46 = & F_23 ( 0 ) ;
struct V_47 * V_48 ;
int V_49 , V_50 , V_51 ;
int V_34 ;
int V_52 ;
#if V_53 V_54 || V_53 V_55
unsigned int V_56 ;
#endif
if ( V_7 -> V_8 != 0 )
return - V_24 ;
F_17 ( V_29 L_4 ) ;
switch ( V_46 -> V_57 ) {
case 10 :
F_10 ( 0x1153 , V_11 , V_12 ) ;
V_44 = ( ( ( V_11 >> 2 ) ^ V_11 ) >> 18 ) & 3 ;
F_17 ( V_58 L_5 ) ;
break;
case 13 :
F_10 ( 0x1154 , V_11 , V_12 ) ;
V_44 = ( ( ( V_11 >> 4 ) ^ ( V_11 >> 2 ) ) ) & 0x000000ff ;
F_17 ( V_58 L_6 ) ;
break;
}
switch ( V_44 ) {
case V_59 :
F_17 ( V_58 L_7 ) ;
break;
case V_60 :
F_17 ( V_58 L_8 ) ;
break;
case V_61 :
F_17 ( V_58 L_9 ) ;
break;
case V_62 :
F_17 ( V_58 L_10 ) ;
break;
case V_63 :
F_17 ( V_58 L_11 ) ;
return - V_24 ;
break;
}
F_24 ( V_64 , V_39 ) ;
if ( ! ( V_39 & V_65 ) ) {
V_39 |= V_65 ;
F_25 ( V_64 , V_39 ) ;
F_24 ( V_64 , V_39 ) ;
if ( ! ( V_39 & V_65 ) ) {
F_17 ( V_29 L_12 ) ;
return - V_24 ;
}
}
F_10 ( V_14 , V_11 , V_12 ) ;
V_28 = V_11 & 0xff ;
F_17 ( V_29 L_1 ,
V_28 * 16 + 700 ) ;
V_27 = ( V_11 >> 8 ) & 0xff ;
F_17 ( V_29 L_2 , V_27 ) ;
V_41 = V_12 & 0xff ;
F_17 ( V_29 L_13 ,
V_41 * 16 + 700 ) ;
V_40 = ( V_12 >> 8 ) & 0xff ;
F_17 ( V_29 L_14 , V_40 ) ;
V_43 = ( V_12 >> 16 ) & 0xff ;
F_17 ( V_29 L_15 ,
V_43 * 16 + 700 ) ;
V_42 = ( V_12 >> 24 ) & 0xff ;
F_17 ( V_29 L_16 , V_42 ) ;
if ( V_27 == 0 || V_40 == 0
|| V_42 == 0 )
return - V_36 ;
if ( V_27 > V_40
|| V_40 <= V_42 )
return - V_36 ;
if ( V_28 > 0x1f || V_41 > 0x1f )
return - V_36 ;
if ( V_41 < V_43
|| V_28 < V_43
|| V_28 > V_41 )
return - V_36 ;
if ( ! V_66 && V_40 != V_27 ) {
F_17 ( V_29 L_17
L_18 ) ;
F_17 ( V_29 L_19
L_20 ) ;
return - V_36 ;
}
if ( ! V_67 && V_41 != V_28 ) {
F_17 ( V_29 L_17
L_21 ) ;
F_17 ( V_29 L_22
L_23 ) ;
return - V_36 ;
}
V_15 = V_68 / V_27 ;
#if V_53 V_54 || V_53 V_55
if ( ! V_69 && ! F_1 () ) {
if ( ! F_26 ( V_7 -> V_8 , & V_56 ) ) {
F_17 ( V_29 L_24 ,
V_56 / 1000000 ,
( V_56 % 1000000 ) / 10000 ) ;
F_7 ( V_7 ) ;
if ( V_56 && V_40 * V_15 > V_56 ) {
F_17 ( V_29 L_25 ) ;
return - V_36 ;
}
}
}
#endif
if ( V_44 == V_59 && V_70 ) {
T_1 V_71 ;
V_71 = ( V_70 - 700 ) / 16 ;
if ( V_71 >= V_43 && V_71 <= V_41 ) {
F_17 ( V_29 L_26 ,
V_71 * 16 + 700 ) ;
V_41 = V_71 ;
}
}
if ( V_44 == V_59 )
V_52 = V_40 - V_42 + 1 ;
else
V_52 = 2 ;
V_10 = F_2 ( sizeof( * V_10 )
+ ( V_52 + 1 ) * sizeof( struct V_47 ) ,
V_2 ) ;
if ( ! V_10 )
return - V_3 ;
V_13 [ 0 ] = V_10 ;
V_10 -> V_15 = V_15 ;
#if V_53 V_54 || V_53 V_55
V_10 -> V_72 = V_56 ;
#endif
V_48 = & V_10 -> V_35 [ 0 ] ;
if ( V_44 != V_59 ) {
V_48 [ 0 ] . V_73 = V_15 * V_42 ;
V_48 [ 0 ] . V_37 = ( V_42 << 8 ) | V_43 ;
V_48 [ 1 ] . V_73 = V_15 * V_40 ;
V_48 [ 1 ] . V_37 = ( V_40 << 8 ) | V_41 ;
V_48 [ 2 ] . V_73 = V_74 ;
} else {
V_49 = 0 ;
V_50 = ( ( V_41 - V_43 ) * 256 )
/ ( V_40 - V_42 ) ;
for ( V_20 = V_42 ; V_20 <= V_40 ; V_20 ++ ) {
V_51 = ( V_49 * V_50 ) / 256 + V_43 ;
V_48 [ V_49 ] . V_73 = V_15 * V_20 ;
V_48 [ V_49 ] . V_37 = ( V_20 << 8 ) | V_51 ;
V_49 ++ ;
}
V_48 [ V_49 ] . V_73 = V_74 ;
}
V_7 -> V_75 . V_76 = 140000 ;
V_7 -> V_77 = V_15 * V_27 ;
V_34 = F_27 ( V_7 , & V_10 -> V_35 [ 0 ] ) ;
if ( V_34 ) {
F_4 ( V_10 ) ;
return V_34 ;
}
F_28 ( & V_10 -> V_35 [ 0 ] , V_7 -> V_8 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
unsigned int V_8 = V_7 -> V_8 ;
F_30 ( V_7 -> V_8 ) ;
F_4 ( V_13 [ V_8 ] ) ;
V_13 [ V_8 ] = NULL ;
return 0 ;
}
static int T_4 F_31 ( void )
{
if ( ! F_32 ( V_78 ) || V_79 . V_57 < 10 )
return - V_24 ;
if ( F_33 ( & V_80 ) )
return - V_36 ;
return 0 ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_80 ) ;
}
