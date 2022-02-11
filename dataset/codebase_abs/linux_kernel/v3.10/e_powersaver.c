static int F_1 ( void )
{
V_1 = F_2 ( sizeof( struct V_2 ) ,
V_3 ) ;
if ( ! V_1 )
return - V_4 ;
if ( ! F_3 ( & V_1 -> V_5 ,
V_3 ) ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
return - V_4 ;
}
if ( F_5 ( V_1 , 0 ) ) {
F_6 ( V_1 -> V_5 ) ;
F_4 ( V_1 ) ;
V_1 = NULL ;
return - V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
if ( V_1 ) {
F_8 ( V_1 , 0 ) ;
F_6 ( V_1 -> V_5 ) ;
F_4 ( V_1 ) ;
V_1 = NULL ;
}
return 0 ;
}
static unsigned int F_9 ( unsigned int V_9 )
{
struct V_10 * V_11 ;
T_1 V_12 , V_13 ;
if ( V_9 )
return 0 ;
V_11 = V_14 [ V_9 ] ;
if ( V_11 == NULL )
return 0 ;
F_10 ( V_15 , V_12 , V_13 ) ;
return V_11 -> V_16 * ( ( V_12 >> 8 ) & 0xff ) ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
T_1 V_17 )
{
struct V_18 V_19 ;
T_1 V_12 , V_13 ;
int V_20 = 0 ;
int V_21 ;
V_19 . V_22 = F_9 ( V_8 -> V_9 ) ;
V_19 . V_23 = V_11 -> V_16 * ( ( V_17 >> 8 ) & 0xff ) ;
F_12 ( V_8 , & V_19 , V_24 ) ;
F_10 ( V_15 , V_12 , V_13 ) ;
V_21 = 0 ;
while ( V_12 & ( ( 1 << 16 ) | ( 1 << 17 ) ) ) {
F_13 ( 16 ) ;
F_10 ( V_15 , V_12 , V_13 ) ;
V_21 ++ ;
if ( F_14 ( V_21 > 64 ) ) {
V_20 = - V_25 ;
goto V_26;
}
}
F_15 ( V_27 , V_17 & 0xffff , 0 ) ;
V_21 = 0 ;
do {
F_13 ( 16 ) ;
F_10 ( V_15 , V_12 , V_13 ) ;
V_21 ++ ;
if ( F_14 ( V_21 > 64 ) ) {
V_20 = - V_25 ;
goto V_26;
}
} while ( V_12 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_26:
F_10 ( V_15 , V_12 , V_13 ) ;
V_19 . V_23 = V_11 -> V_16 * ( ( V_12 >> 8 ) & 0xff ) ;
#ifdef F_16
{
T_2 V_28 , V_29 ;
F_10 ( V_15 , V_12 , V_13 ) ;
V_29 = V_12 & 0xff ;
F_17 ( V_30 L_1 ,
V_29 * 16 + 700 ) ;
V_28 = ( V_12 >> 8 ) & 0xff ;
F_17 ( V_30 L_2 ,
V_28 ) ;
}
#endif
F_12 ( V_8 , & V_19 , V_31 ) ;
return V_20 ;
}
static int F_18 ( struct V_7 * V_8 ,
unsigned int V_32 ,
unsigned int V_33 )
{
struct V_10 * V_11 ;
unsigned int V_34 = 0 ;
unsigned int V_9 = V_8 -> V_9 ;
unsigned int V_17 ;
int V_35 ;
if ( F_14 ( V_14 [ V_9 ] == NULL ) )
return - V_25 ;
V_11 = V_14 [ V_9 ] ;
if ( F_14 ( F_19 ( V_8 ,
& V_14 [ V_9 ] -> V_36 [ 0 ] ,
V_32 ,
V_33 ,
& V_34 ) ) ) {
return - V_37 ;
}
V_17 = V_11 -> V_36 [ V_34 ] . V_38 & 0xffff ;
V_35 = F_11 ( V_11 , V_8 , V_17 ) ;
if ( V_35 )
F_17 ( V_39 L_3 ) ;
return V_35 ;
}
static int F_20 ( struct V_7 * V_8 )
{
return F_21 ( V_8 ,
& V_14 [ V_8 -> V_9 ] -> V_36 [ 0 ] ) ;
}
static int F_22 ( struct V_7 * V_8 )
{
unsigned int V_21 ;
T_1 V_12 , V_13 ;
T_3 V_40 ;
T_2 V_28 , V_29 ;
T_2 V_41 , V_42 ;
T_2 V_43 , V_44 ;
T_2 V_45 = 0 ;
T_1 V_16 ;
struct V_10 * V_11 ;
struct V_46 * V_47 = & F_23 ( 0 ) ;
struct V_48 * V_49 ;
int V_50 , V_51 , V_52 ;
int V_35 ;
int V_53 ;
#if V_54 V_55 || V_54 V_56
unsigned int V_57 ;
#endif
if ( V_8 -> V_9 != 0 )
return - V_25 ;
F_17 ( V_30 L_4 ) ;
switch ( V_47 -> V_58 ) {
case 10 :
F_10 ( 0x1153 , V_12 , V_13 ) ;
V_45 = ( ( ( V_12 >> 2 ) ^ V_12 ) >> 18 ) & 3 ;
F_17 ( V_59 L_5 ) ;
break;
case 13 :
F_10 ( 0x1154 , V_12 , V_13 ) ;
V_45 = ( ( ( V_12 >> 4 ) ^ ( V_12 >> 2 ) ) ) & 0x000000ff ;
F_17 ( V_59 L_6 ) ;
break;
}
switch ( V_45 ) {
case V_60 :
F_17 ( V_59 L_7 ) ;
break;
case V_61 :
F_17 ( V_59 L_8 ) ;
break;
case V_62 :
F_17 ( V_59 L_9 ) ;
break;
case V_63 :
F_17 ( V_59 L_10 ) ;
break;
case V_64 :
F_17 ( V_59 L_11 ) ;
return - V_25 ;
break;
}
F_24 ( V_65 , V_40 ) ;
if ( ! ( V_40 & V_66 ) ) {
V_40 |= V_66 ;
F_25 ( V_65 , V_40 ) ;
F_24 ( V_65 , V_40 ) ;
if ( ! ( V_40 & V_66 ) ) {
F_17 ( V_30 L_12 ) ;
return - V_25 ;
}
}
F_10 ( V_15 , V_12 , V_13 ) ;
V_29 = V_12 & 0xff ;
F_17 ( V_30 L_1 ,
V_29 * 16 + 700 ) ;
V_28 = ( V_12 >> 8 ) & 0xff ;
F_17 ( V_30 L_2 , V_28 ) ;
V_42 = V_13 & 0xff ;
F_17 ( V_30 L_13 ,
V_42 * 16 + 700 ) ;
V_41 = ( V_13 >> 8 ) & 0xff ;
F_17 ( V_30 L_14 , V_41 ) ;
V_44 = ( V_13 >> 16 ) & 0xff ;
F_17 ( V_30 L_15 ,
V_44 * 16 + 700 ) ;
V_43 = ( V_13 >> 24 ) & 0xff ;
F_17 ( V_30 L_16 , V_43 ) ;
if ( V_28 == 0 || V_41 == 0
|| V_43 == 0 )
return - V_37 ;
if ( V_28 > V_41
|| V_41 <= V_43 )
return - V_37 ;
if ( V_29 > 0x1f || V_42 > 0x1f )
return - V_37 ;
if ( V_42 < V_44
|| V_29 < V_44
|| V_29 > V_42 )
return - V_37 ;
if ( ! V_67 && V_41 != V_28 ) {
F_17 ( V_30 L_17
L_18 ) ;
F_17 ( V_30 L_19
L_20 ) ;
return - V_37 ;
}
if ( ! V_68 && V_42 != V_29 ) {
F_17 ( V_30 L_17
L_21 ) ;
F_17 ( V_30 L_22
L_23 ) ;
return - V_37 ;
}
V_16 = V_69 / V_28 ;
#if V_54 V_55 || V_54 V_56
if ( ! V_70 && ! F_1 () ) {
if ( ! F_26 ( V_8 -> V_9 , & V_57 ) ) {
F_17 ( V_30 L_24 ,
V_57 / 1000000 ,
( V_57 % 1000000 ) / 10000 ) ;
F_7 ( V_8 ) ;
if ( V_57 && V_41 * V_16 > V_57 ) {
F_17 ( V_30 L_25 ) ;
return - V_37 ;
}
}
}
#endif
if ( V_45 == V_60 && V_71 ) {
T_1 V_72 ;
V_72 = ( V_71 - 700 ) / 16 ;
if ( V_72 >= V_44 && V_72 <= V_42 ) {
F_17 ( V_30 L_26 ,
V_72 * 16 + 700 ) ;
V_42 = V_72 ;
}
}
if ( V_45 == V_60 )
V_53 = V_41 - V_43 + 1 ;
else
V_53 = 2 ;
V_11 = F_2 ( sizeof( struct V_10 )
+ ( V_53 + 1 ) * sizeof( struct V_48 ) ,
V_3 ) ;
if ( ! V_11 )
return - V_4 ;
V_14 [ 0 ] = V_11 ;
V_11 -> V_16 = V_16 ;
#if V_54 V_55 || V_54 V_56
V_11 -> V_73 = V_57 ;
#endif
V_49 = & V_11 -> V_36 [ 0 ] ;
if ( V_45 != V_60 ) {
V_49 [ 0 ] . V_74 = V_16 * V_43 ;
V_49 [ 0 ] . V_38 = ( V_43 << 8 ) | V_44 ;
V_49 [ 1 ] . V_74 = V_16 * V_41 ;
V_49 [ 1 ] . V_38 = ( V_41 << 8 ) | V_42 ;
V_49 [ 2 ] . V_74 = V_75 ;
} else {
V_50 = 0 ;
V_51 = ( ( V_42 - V_44 ) * 256 )
/ ( V_41 - V_43 ) ;
for ( V_21 = V_43 ; V_21 <= V_41 ; V_21 ++ ) {
V_52 = ( V_50 * V_51 ) / 256 + V_44 ;
V_49 [ V_50 ] . V_74 = V_16 * V_21 ;
V_49 [ V_50 ] . V_38 = ( V_21 << 8 ) | V_52 ;
V_50 ++ ;
}
V_49 [ V_50 ] . V_74 = V_75 ;
}
V_8 -> V_76 . V_77 = 140000 ;
V_8 -> V_78 = V_16 * V_28 ;
V_35 = F_27 ( V_8 , & V_11 -> V_36 [ 0 ] ) ;
if ( V_35 ) {
F_4 ( V_11 ) ;
return V_35 ;
}
F_28 ( & V_11 -> V_36 [ 0 ] , V_8 -> V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_9 ;
F_30 ( V_8 -> V_9 ) ;
F_4 ( V_14 [ V_9 ] ) ;
V_14 [ V_9 ] = NULL ;
return 0 ;
}
static int T_4 F_31 ( void )
{
if ( ! F_32 ( V_79 ) || V_80 . V_58 < 10 )
return - V_25 ;
if ( F_33 ( & V_81 ) )
return - V_37 ;
return 0 ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_81 ) ;
}
