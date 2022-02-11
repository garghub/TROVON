static inline T_1 F_1 ( int V_1 )
{
return ( V_1 & 0x10 ) << 3 ;
}
static T_2 F_2 ( struct V_2 * V_2 , const char T_3 * V_3 ,
T_4 V_4 , T_5 * V_5 )
{
T_1 V_6 = F_3 ( V_2 -> V_7 . V_8 -> V_9 ) ;
int V_10 , V_11 ;
T_1 V_12 = V_13 + F_1 ( V_6 ) ;
T_1 V_14 , V_15 ;
char V_16 ;
V_15 = 1 << ( V_6 & 0x0F ) ;
V_14 = V_15 << 16 ;
for ( V_10 = 0 ; V_10 < V_4 ; ++ V_10 ) {
if ( F_4 ( V_16 , V_3 + V_10 ) )
return - V_17 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_18 ) ; V_11 ++ ) {
if ( V_16 == V_18 [ V_11 ] . V_19 ) {
F_6 ( V_15 , V_12 + V_18 [ V_11 ] . V_20 ) ;
if ( V_16 == 'O' ) {
F_6 ( V_14 , V_12 + 0x10 ) ;
F_6 ( V_14 , V_12 + 0x14 ) ;
}
break;
} else if ( V_16 == V_18 [ V_11 ] . V_21 ) {
F_6 ( V_14 , V_12 + V_18 [ V_11 ] . V_20 ) ;
break;
}
}
}
* V_5 = 0 ;
return V_4 ;
}
static T_2 F_7 ( struct V_2 * V_2 , char T_3 * V_22 ,
T_4 V_4 , T_5 * V_5 )
{
T_1 V_6 = F_3 ( V_2 -> V_7 . V_8 -> V_9 ) ;
T_1 V_12 = V_13 + F_1 ( V_6 ) ;
int V_23 = 1 << ( V_6 & 0x0f ) ;
int V_10 ;
char V_24 ;
T_2 V_25 = 0 ;
if ( * V_5 >= F_5 ( V_18 ) )
return 0 ;
for ( V_10 = * V_5 ; ( V_10 < ( * V_5 + V_4 ) ) && ( V_10 < F_5 ( V_18 ) ) ; V_10 ++ ) {
V_24 = ( F_8 ( V_12 + V_18 [ V_10 ] . V_26 ) & V_23 ) ?
V_18 [ V_10 ] . V_19 : V_18 [ V_10 ] . V_21 ;
if ( F_9 ( V_24 , V_22 + V_25 ) )
return - V_17 ;
V_25 ++ ;
}
if ( ( V_10 == F_5 ( V_18 ) ) && ( V_25 < V_4 ) ) {
if ( F_9 ( '\n' , V_22 + V_25 ) )
return - V_17 ;
V_25 ++ ;
}
* V_5 += V_25 ;
return V_25 ;
}
static int F_10 ( struct V_27 * V_27 , struct V_2 * V_2 )
{
T_1 V_6 = F_3 ( V_27 ) ;
if ( ( V_28 & ( 1 << V_6 ) ) == 0 )
return - V_29 ;
return F_11 ( V_27 , V_2 ) ;
}
static int T_6 F_12 ( void )
{
T_7 V_30 ;
T_1 V_31 , V_32 ;
int V_33 ;
if ( F_13 ( V_34 ) == 0 ) {
F_14 (KERN_WARNING NAME L_1 ) ;
return - V_35 ;
}
F_15 ( V_36 , V_31 , V_32 ) ;
if ( V_32 != 0x0000f001 ) {
F_14 (KERN_WARNING NAME L_2 ) ;
return - V_35 ;
}
V_13 = V_31 & 0x0000ff00 ;
if ( V_28 != 0 )
V_28 &= 0x1f7fffff ;
else
V_28 = 0x0b003c66 ;
if ( ! F_16 ( V_13 , V_37 , V_38 ) ) {
F_14 (KERN_ERR NAME L_3 ) ;
return - V_35 ;
}
if ( V_39 ) {
V_30 = F_17 ( V_39 , 0 ) ;
V_33 = F_18 ( V_30 , V_40 ,
V_38 ) ;
} else {
V_33 = F_19 ( & V_30 , 0 , V_40 ,
V_38 ) ;
V_39 = F_20 ( V_30 ) ;
}
if ( V_33 ) {
F_21 ( V_13 , V_37 ) ;
return - 1 ;
}
F_14 (KERN_DEBUG NAME L_4 ,
gpio_base, mask, major) ;
F_22 ( & V_41 , & V_42 ) ;
F_23 ( & V_41 , V_30 , V_40 ) ;
return 0 ;
}
static void T_8 F_24 ( void )
{
T_7 V_30 = F_17 ( V_39 , 0 ) ;
F_25 ( & V_41 ) ;
F_26 ( V_30 , V_40 ) ;
F_21 ( V_13 , V_37 ) ;
}
