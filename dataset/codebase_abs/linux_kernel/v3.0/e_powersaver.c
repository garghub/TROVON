static unsigned int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 , V_5 ;
if ( V_1 )
return 0 ;
V_3 = V_6 [ V_1 ] ;
if ( V_3 == NULL )
return 0 ;
F_2 ( V_7 , V_4 , V_5 ) ;
return V_3 -> V_8 * ( ( V_4 >> 8 ) & 0xff ) ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned int V_1 ,
T_1 V_9 )
{
struct V_10 V_11 ;
T_1 V_4 , V_5 ;
int V_12 = 0 ;
int V_13 ;
V_11 . V_14 = F_1 ( V_1 ) ;
V_11 . V_15 = V_3 -> V_8 * ( ( V_9 >> 8 ) & 0xff ) ;
V_11 . V_1 = V_1 ;
F_4 ( & V_11 , V_16 ) ;
F_2 ( V_7 , V_4 , V_5 ) ;
V_13 = 0 ;
while ( V_4 & ( ( 1 << 16 ) | ( 1 << 17 ) ) ) {
F_5 ( 16 ) ;
F_2 ( V_7 , V_4 , V_5 ) ;
V_13 ++ ;
if ( F_6 ( V_13 > 64 ) ) {
V_12 = - V_17 ;
goto V_18;
}
}
F_7 ( V_19 , V_9 & 0xffff , 0 ) ;
V_13 = 0 ;
do {
F_5 ( 16 ) ;
F_2 ( V_7 , V_4 , V_5 ) ;
V_13 ++ ;
if ( F_6 ( V_13 > 64 ) ) {
V_12 = - V_17 ;
goto V_18;
}
} while ( V_4 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_18:
F_2 ( V_7 , V_4 , V_5 ) ;
V_11 . V_15 = V_3 -> V_8 * ( ( V_4 >> 8 ) & 0xff ) ;
#ifdef F_8
{
T_2 V_20 , V_21 ;
F_2 ( V_7 , V_4 , V_5 ) ;
V_21 = V_4 & 0xff ;
F_9 ( V_22 L_1 ,
V_21 * 16 + 700 ) ;
V_20 = ( V_4 >> 8 ) & 0xff ;
F_9 ( V_22 L_2 ,
V_20 ) ;
}
#endif
F_4 ( & V_11 , V_23 ) ;
return V_12 ;
}
static int F_10 ( struct V_24 * V_25 ,
unsigned int V_26 ,
unsigned int V_27 )
{
struct V_2 * V_3 ;
unsigned int V_28 = 0 ;
unsigned int V_1 = V_25 -> V_1 ;
unsigned int V_9 ;
int V_29 ;
if ( F_6 ( V_6 [ V_1 ] == NULL ) )
return - V_17 ;
V_3 = V_6 [ V_1 ] ;
if ( F_6 ( F_11 ( V_25 ,
& V_6 [ V_1 ] -> V_30 [ 0 ] ,
V_26 ,
V_27 ,
& V_28 ) ) ) {
return - V_31 ;
}
V_9 = V_3 -> V_30 [ V_28 ] . V_32 & 0xffff ;
V_29 = F_3 ( V_3 , V_1 , V_9 ) ;
if ( V_29 )
F_9 ( V_33 L_3 ) ;
return V_29 ;
}
static int F_12 ( struct V_24 * V_25 )
{
return F_13 ( V_25 ,
& V_6 [ V_25 -> V_1 ] -> V_30 [ 0 ] ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
unsigned int V_13 ;
T_1 V_4 , V_5 ;
T_3 V_34 ;
T_2 V_20 , V_21 ;
T_2 V_35 , V_36 ;
T_2 V_37 , V_38 ;
T_2 V_39 = 0 ;
T_1 V_8 ;
struct V_2 * V_3 ;
struct V_40 * V_41 = & F_15 ( 0 ) ;
struct V_42 * V_43 ;
int V_44 , V_45 , V_46 ;
int V_29 ;
int V_47 ;
if ( V_25 -> V_1 != 0 )
return - V_17 ;
F_9 ( V_22 L_4 ) ;
switch ( V_41 -> V_48 ) {
case 10 :
F_2 ( 0x1153 , V_4 , V_5 ) ;
V_39 = ( ( ( V_4 >> 2 ) ^ V_4 ) >> 18 ) & 3 ;
F_9 ( V_49 L_5 ) ;
break;
case 13 :
F_2 ( 0x1154 , V_4 , V_5 ) ;
V_39 = ( ( ( V_4 >> 4 ) ^ ( V_4 >> 2 ) ) ) & 0x000000ff ;
F_9 ( V_49 L_6 ) ;
break;
}
switch ( V_39 ) {
case V_50 :
F_9 ( V_49 L_7 ) ;
break;
case V_51 :
F_9 ( V_49 L_8 ) ;
break;
case V_52 :
F_9 ( V_49 L_9 ) ;
break;
case V_53 :
F_9 ( V_49 L_10 ) ;
break;
case V_54 :
F_9 ( V_49 L_11 ) ;
return - V_17 ;
break;
}
F_16 ( V_55 , V_34 ) ;
if ( ! ( V_34 & V_56 ) ) {
V_34 |= V_56 ;
F_17 ( V_55 , V_34 ) ;
F_16 ( V_55 , V_34 ) ;
if ( ! ( V_34 & V_56 ) ) {
F_9 ( V_22 L_12 ) ;
return - V_17 ;
}
}
F_2 ( V_7 , V_4 , V_5 ) ;
V_21 = V_4 & 0xff ;
F_9 ( V_22 L_1 ,
V_21 * 16 + 700 ) ;
V_20 = ( V_4 >> 8 ) & 0xff ;
F_9 ( V_22 L_2 , V_20 ) ;
V_36 = V_5 & 0xff ;
F_9 ( V_22 L_13 ,
V_36 * 16 + 700 ) ;
V_35 = ( V_5 >> 8 ) & 0xff ;
F_9 ( V_22 L_14 , V_35 ) ;
V_38 = ( V_5 >> 16 ) & 0xff ;
F_9 ( V_22 L_15 ,
V_38 * 16 + 700 ) ;
V_37 = ( V_5 >> 24 ) & 0xff ;
F_9 ( V_22 L_16 , V_37 ) ;
if ( V_20 == 0 || V_35 == 0
|| V_37 == 0 )
return - V_31 ;
if ( V_20 > V_35
|| V_35 <= V_37 )
return - V_31 ;
if ( V_21 > 0x1f || V_36 > 0x1f )
return - V_31 ;
if ( V_36 < V_38 )
return - V_31 ;
V_8 = V_57 / V_20 ;
if ( V_39 == V_50 )
V_47 = V_35 - V_37 + 1 ;
else
V_47 = 2 ;
V_3 = F_18 ( sizeof( struct V_2 )
+ ( V_47 + 1 ) * sizeof( struct V_42 ) ,
V_58 ) ;
if ( ! V_3 )
return - V_59 ;
V_6 [ 0 ] = V_3 ;
V_3 -> V_8 = V_8 ;
V_43 = & V_3 -> V_30 [ 0 ] ;
if ( V_39 != V_50 ) {
V_43 [ 0 ] . V_60 = V_8 * V_37 ;
V_43 [ 0 ] . V_32 = ( V_37 << 8 ) | V_38 ;
V_43 [ 1 ] . V_60 = V_8 * V_35 ;
V_43 [ 1 ] . V_32 = ( V_35 << 8 ) | V_36 ;
V_43 [ 2 ] . V_60 = V_61 ;
} else {
V_44 = 0 ;
V_45 = ( ( V_36 - V_38 ) * 256 )
/ ( V_35 - V_37 ) ;
for ( V_13 = V_37 ; V_13 <= V_35 ; V_13 ++ ) {
V_46 = ( V_44 * V_45 ) / 256 + V_38 ;
V_43 [ V_44 ] . V_60 = V_8 * V_13 ;
V_43 [ V_44 ] . V_32 = ( V_13 << 8 ) | V_46 ;
V_44 ++ ;
}
V_43 [ V_44 ] . V_60 = V_61 ;
}
V_25 -> V_62 . V_63 = 140000 ;
V_25 -> V_64 = V_8 * V_20 ;
V_29 = F_19 ( V_25 , & V_3 -> V_30 [ 0 ] ) ;
if ( V_29 ) {
F_20 ( V_3 ) ;
return V_29 ;
}
F_21 ( & V_3 -> V_30 [ 0 ] , V_25 -> V_1 ) ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
unsigned int V_1 = V_25 -> V_1 ;
struct V_2 * V_3 ;
T_1 V_4 , V_5 ;
if ( V_6 [ V_1 ] == NULL )
return - V_17 ;
V_3 = V_6 [ V_1 ] ;
F_2 ( V_7 , V_4 , V_5 ) ;
F_3 ( V_3 , V_1 , V_5 & 0xffff ) ;
F_23 ( V_25 -> V_1 ) ;
F_20 ( V_6 [ V_1 ] ) ;
V_6 [ V_1 ] = NULL ;
return 0 ;
}
static int T_4 F_24 ( void )
{
struct V_40 * V_41 = & F_15 ( 0 ) ;
if ( V_41 -> V_65 != V_66
|| V_41 -> V_67 != 6 || V_41 -> V_48 < 10 )
return - V_17 ;
if ( ! F_25 ( V_41 , V_68 ) )
return - V_17 ;
if ( F_26 ( & V_69 ) )
return - V_31 ;
return 0 ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_69 ) ;
}
