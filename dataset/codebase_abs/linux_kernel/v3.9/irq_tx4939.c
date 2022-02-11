static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 T_2 * V_6 ;
int V_7 ;
if ( V_3 < 32 ) {
V_3 -- ;
V_6 = & V_8 -> V_9 [ ( V_3 % 16 ) / 2 ] . V_10 ;
} else {
V_3 -= 32 ;
V_6 = & V_8 -> V_9 [ 8 + ( V_3 % 16 ) / 2 ] . V_10 ;
}
V_7 = ( V_3 & 16 ) + ( V_3 & 1 ) * 8 ;
F_2 ( ( F_3 ( V_6 ) & ~ ( 0xff << V_7 ) )
| ( V_11 [ V_3 ] . V_12 << V_7 ) ,
V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 T_2 * V_6 ;
int V_7 ;
if ( V_3 < 32 ) {
V_3 -- ;
V_6 = & V_8 -> V_9 [ ( V_3 % 16 ) / 2 ] . V_10 ;
} else {
V_3 -= 32 ;
V_6 = & V_8 -> V_9 [ 8 + ( V_3 % 16 ) / 2 ] . V_10 ;
}
V_7 = ( V_3 & 16 ) + ( V_3 & 1 ) * 8 ;
F_2 ( ( F_3 ( V_6 ) & ~ ( 0xff << V_7 ) )
| ( V_13 << V_7 ) ,
V_6 ) ;
F_5 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
F_4 ( V_2 ) ;
if ( F_7 ( V_11 [ V_3 ] . V_14 ) ) {
V_3 -- ;
F_2 ( ( V_15 | ( V_3 & 0xf ) )
<< ( V_3 & 0x10 ) ,
& V_8 -> V_16 . V_10 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_17 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 V_18 ;
T_1 T_2 * V_19 ;
int V_7 ;
int V_14 ;
if ( V_17 & V_20 )
return 0 ;
switch ( V_17 & V_21 ) {
case V_22 :
V_14 = V_23 ;
break;
case V_24 :
V_14 = V_25 ;
break;
case V_26 :
V_14 = V_27 ;
break;
case V_28 :
V_14 = V_29 ;
break;
default:
return - V_30 ;
}
if ( V_3 < 32 ) {
V_3 -- ;
V_19 = & V_8 -> V_31 [ ( V_3 & 8 ) >> 3 ] . V_10 ;
} else {
V_3 -= 32 ;
V_19 = & V_8 -> V_32 [ ( ( V_3 & 8 ) >> 3 ) ] . V_10 ;
}
V_7 = ( ( ( V_3 & 16 ) >> 1 ) | ( V_3 & ( 8 - 1 ) ) ) * 2 ;
V_18 = F_3 ( V_19 ) ;
V_18 &= ~ ( 0x3 << V_7 ) ;
V_18 |= ( V_14 & 0x3 ) << V_7 ;
F_2 ( V_18 , V_19 ) ;
V_11 [ V_3 ] . V_14 = V_14 ;
return 0 ;
}
static int F_9 ( int V_33 , int V_34 )
{
int V_35 ;
if ( ( unsigned int ) V_33 >= V_36 )
return 0 ;
V_35 = V_11 [ V_33 ] . V_12 ;
V_11 [ V_33 ] . V_12 = V_34 ;
return V_35 ;
}
void T_3 F_10 ( void )
{
int V_37 ;
F_11 () ;
F_2 ( 0 , & V_8 -> V_38 . V_10 ) ;
F_2 ( 0 , & V_8 -> V_39 . V_10 ) ;
F_2 ( 0 , & V_8 -> V_40 . V_10 ) ;
for ( V_37 = 1 ; V_37 < V_36 ; V_37 ++ ) {
V_11 [ V_37 ] . V_12 = 4 ;
V_11 [ V_37 ] . V_14 = V_29 ;
F_12 ( V_5 + V_37 , & V_41 ,
V_42 ) ;
}
F_2 ( 0 , & V_8 -> V_43 . V_10 ) ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ )
F_2 ( 0 , & V_8 -> V_9 [ V_37 ] . V_10 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ )
F_2 ( 0 , & V_8 -> V_31 [ V_37 ] . V_10 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ )
F_2 ( 0 , & V_8 -> V_32 [ V_37 ] . V_10 ) ;
F_2 ( V_44 , & V_8 -> V_38 . V_10 ) ;
F_2 ( V_45 , & V_8 -> V_43 . V_10 ) ;
F_13 ( V_46 + V_47 ,
V_48 ) ;
F_9 ( V_49 , 7 ) ;
F_9 ( V_50 , 7 ) ;
F_9 ( V_51 , 7 ) ;
for ( V_37 = 0 ; V_37 < V_52 ; V_37 ++ )
F_9 ( F_14 ( V_37 ) , 6 ) ;
for ( V_37 = 0 ; V_37 < V_53 ; V_37 ++ )
F_9 ( F_15 ( V_37 ) , 5 ) ;
}
int F_16 ( void )
{
T_1 V_54 = F_3 ( & V_8 -> V_55 . V_10 ) ;
if ( F_17 ( ! ( V_54 & V_56 ) ) )
return V_5 + ( V_54 & ( V_36 - 1 ) ) ;
return - 1 ;
}
