static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
if ( F_2 ( V_5 ) ) {
T_1 V_6 ;
F_3 ( V_7 + V_3 , * V_4 , V_6 ) ;
return 0 ;
}
return F_4 ( V_2 , V_8 + V_3 * 4 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( F_2 ( V_5 ) ) {
F_6 ( V_7 + V_3 , V_4 , 0 ) ;
return 0 ;
}
return F_7 ( V_2 , V_8 + V_3 * 4 , V_4 ) ;
}
static void F_8 ( T_2 * V_9 , T_3 V_10 )
{
struct V_1 * V_2 = F_9 ( V_9 -> V_11 -> V_12 ) ;
int V_13 = ( V_9 -> V_14 & 1 ) ? V_15 : V_16 ;
T_1 V_17 ;
F_1 ( V_2 , V_18 , & V_17 ) ;
V_17 &= ~ ( V_19 << V_13 ) ;
V_17 |= V_10 << V_13 ;
F_5 ( V_2 , V_18 , V_17 ) ;
}
static T_3 F_10 ( T_4 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 -> V_12 ) ;
T_1 V_20 ;
F_1 ( V_2 , V_21 , & V_20 ) ;
if ( V_20 & V_22 )
return V_23 ;
else
return V_24 ;
}
static void F_11 ( T_4 * V_11 , T_2 * V_9 )
{
static const T_3 V_25 [ 5 ] = {
0x98 , 0x55 , 0x32 , 0x21 , 0x20 ,
} ;
static const T_3 V_26 [ 5 ] = {
0x2 , 0x1 , 0x0 , 0x0 , 0x0 ,
} ;
static const T_3 V_27 [ 5 ] = {
0x99 , 0x92 , 0x90 , 0x22 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_11 -> V_12 ) ;
T_2 * V_28 = F_12 ( V_9 ) ;
int V_29 = ( V_9 -> V_14 & 1 ) ? V_30 : V_31 ;
unsigned long V_32 = ( unsigned long ) F_13 ( V_9 ) ;
T_1 V_33 ;
const T_3 V_34 = V_9 -> V_35 - V_36 ;
T_3 V_37 = V_34 ;
if ( V_28 )
V_37 = F_14 ( T_3 , V_34 , V_28 -> V_35 - V_36 ) ;
V_32 &= ( V_19 << 8 ) ;
V_32 |= V_25 [ V_34 ] ;
F_15 ( V_9 , ( void * ) V_32 ) ;
F_8 ( V_9 , V_25 [ V_34 ] ) ;
F_1 ( V_2 , V_38 , & V_33 ) ;
V_33 &= ~ ( V_39 << V_29 ) ;
V_33 |= V_26 [ V_34 ] << V_29 ;
V_33 &= ~ ( V_40 << V_41 ) ;
V_33 |= V_27 [ V_37 ] << V_41 ;
F_5 ( V_2 , V_38 , V_33 ) ;
}
static void F_16 ( T_4 * V_11 , T_2 * V_9 )
{
static const T_3 V_42 [ 6 ] = {
0xc2 , 0xc1 , 0xc0 , 0xc4 , 0xc5 , 0xc6 ,
} ;
static const T_3 V_43 [ 3 ] = {
0x67 , 0x21 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_11 -> V_12 ) ;
int V_13 = ( V_9 -> V_14 & 1 ) ? V_15 : V_16 ;
unsigned long V_32 = ( unsigned long ) F_13 ( V_9 ) ;
T_1 V_44 ;
const T_3 V_45 = V_9 -> V_46 ;
F_1 ( V_2 , V_47 , & V_44 ) ;
if ( V_45 >= V_48 ) {
V_44 &= ~ ( V_19 << V_13 ) ;
V_44 |= V_42 [ V_45 - V_48 ] << V_13 ;
} else {
V_44 &= ~ ( V_49 << V_13 ) ;
V_32 &= V_19 ;
V_32 |= V_43 [ V_45 - V_50 ] << 8 ;
F_15 ( V_9 , ( void * ) V_32 ) ;
}
F_5 ( V_2 , V_47 , V_44 ) ;
}
static void F_17 ( T_2 * V_9 )
{
unsigned long V_32 = ( unsigned long ) F_13 ( V_9 ) ;
if ( V_9 -> V_51 < V_48 &&
( V_32 >> 8 ) != ( V_32 & V_19 ) )
F_8 ( V_9 , V_32 >> 8 ) ;
F_18 ( V_9 ) ;
}
static int F_19 ( T_2 * V_9 )
{
int V_52 = F_20 ( V_9 ) ;
unsigned long V_32 = ( unsigned long ) F_13 ( V_9 ) ;
if ( V_9 -> V_51 < V_48 &&
( V_32 >> 8 ) != ( V_32 & V_19 ) )
F_8 ( V_9 , V_32 & V_19 ) ;
return V_52 ;
}
static int F_21 ( struct V_1 * V_12 , const struct V_53 * V_54 )
{
T_1 V_20 ;
if ( V_5 )
F_22 (KERN_INFO DRV_NAME L_1 ) ;
F_1 ( V_12 , V_21 , & V_20 ) ;
if ( ( V_20 & V_55 ) == 0 ) {
F_22 (KERN_ERR DRV_NAME L_2 ) ;
return - V_56 ;
}
return F_23 ( V_12 , & V_57 , NULL ) ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_58 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_58 ) ;
}
