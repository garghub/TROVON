static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 T_2 * V_6 = & V_7 -> V_8 [ ( V_3 % 16 ) / 2 ] ;
int V_9 = V_3 / 16 * 16 + ( V_3 & 1 ) * 8 ;
F_2 ( ( F_3 ( V_6 ) & ~ ( 0xff << V_9 ) )
| ( V_10 [ V_3 ] . V_11 << V_9 ) ,
V_6 ) ;
#ifdef F_4
F_2 ( 0 , & V_7 -> V_12 ) ;
F_2 ( V_13 , & V_7 -> V_12 ) ;
#endif
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 T_2 * V_6 = & V_7 -> V_8 [ ( V_3 % 16 ) / 2 ] ;
int V_9 = V_3 / 16 * 16 + ( V_3 & 1 ) * 8 ;
F_2 ( ( F_3 ( V_6 ) & ~ ( 0xff << V_9 ) )
| ( V_14 << V_9 ) ,
V_6 ) ;
#ifdef F_4
F_2 ( 0 , & V_7 -> V_12 ) ;
F_2 ( V_13 , & V_7 -> V_12 ) ;
F_3 ( & V_7 -> V_15 ) ;
#else
F_6 () ;
#endif
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
F_5 ( V_2 ) ;
if ( F_8 ( F_9 ( V_10 [ V_3 ] . V_16 ) ) )
F_2 ( V_17 | V_3 , & V_7 -> V_18 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_19 )
{
unsigned int V_3 = V_2 -> V_4 - V_5 ;
T_1 V_20 ;
T_1 T_2 * V_21 ;
int V_9 ;
int V_16 ;
if ( V_19 & V_22 )
return 0 ;
switch ( V_19 & V_23 ) {
case V_24 : V_16 = V_25 ; break;
case V_26 : V_16 = V_27 ; break;
case V_28 : V_16 = V_29 ; break;
case V_30 : V_16 = V_31 ; break;
default:
return - V_32 ;
}
V_21 = & V_7 -> V_20 [ ( unsigned int ) V_3 / 8 ] ;
V_20 = F_3 ( V_21 ) ;
V_9 = ( V_3 & ( 8 - 1 ) ) * 2 ;
V_20 &= ~ ( 0x3 << V_9 ) ;
V_20 |= ( V_16 & 0x3 ) << V_9 ;
F_2 ( V_20 , V_21 ) ;
V_10 [ V_3 ] . V_16 = V_16 ;
return 0 ;
}
void T_3 F_11 ( unsigned long V_33 )
{
int V_34 ;
V_7 = F_12 ( V_33 , sizeof( struct V_35 ) ) ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
V_10 [ V_34 ] . V_11 = 4 ;
V_10 [ V_34 ] . V_16 = V_31 ;
F_13 ( V_5 + V_34 , & V_37 ,
V_38 ) ;
}
F_2 ( 0 , & V_7 -> V_12 ) ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ )
F_2 ( 0 , & V_7 -> V_8 [ V_34 ] ) ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ )
F_2 ( 0 , & V_7 -> V_20 [ V_34 ] ) ;
F_2 ( V_39 , & V_7 -> V_40 ) ;
F_2 ( V_13 , & V_7 -> V_12 ) ;
}
int T_3 F_14 ( int V_41 , int V_42 )
{
int V_43 ;
if ( ( unsigned int ) V_41 >= V_36 )
return 0 ;
V_43 = V_10 [ V_41 ] . V_11 ;
V_10 [ V_41 ] . V_11 = V_42 ;
return V_43 ;
}
int F_15 ( void )
{
T_1 V_44 = F_3 ( & V_7 -> V_44 ) ;
if ( F_16 ( ! ( V_44 & V_45 ) ) )
return V_5 + ( V_44 & ( V_36 - 1 ) ) ;
return - 1 ;
}
