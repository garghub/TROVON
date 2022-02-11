static inline unsigned int F_1 ( unsigned V_1 )
{
unsigned long V_2 = 0 ;
T_1 V_3 [ 5 ] ;
F_2 ( 0 , V_1 + 0 , V_3 ) ;
if ( ! ( V_3 [ 0 ] & V_4 ) )
V_2 |= 0x8000 ;
if ( ! ( V_3 [ 1 ] & V_4 ) )
V_2 |= 0x4000 ;
if ( ! ( V_3 [ 2 ] & V_4 ) )
V_2 |= 0x2000 ;
if ( ! ( V_3 [ 3 ] & V_4 ) )
V_2 |= 0x1000 ;
F_2 ( 0 , V_1 + 4 , V_3 ) ;
if ( ! ( V_3 [ 0 ] & V_4 ) )
V_2 |= 0x0800 ;
if ( ! ( V_3 [ 1 ] & V_4 ) )
V_2 |= 0x0400 ;
if ( ! ( V_3 [ 2 ] & V_4 ) )
V_2 |= 0x0200 ;
if ( ! ( V_3 [ 3 ] & V_4 ) )
V_2 |= 0x0100 ;
V_1 = ~ V_1 & ( V_5 * V_6 ) ;
F_2 ( 0 , V_1 + 0 , V_3 ) ;
if ( ! ( V_3 [ 0 ] & V_4 ) )
V_2 |= 0x80 ;
if ( ! ( V_3 [ 1 ] & V_4 ) )
V_2 |= 0x40 ;
if ( ! ( V_3 [ 2 ] & V_4 ) )
V_2 |= 0x20 ;
if ( ! ( V_3 [ 3 ] & V_4 ) )
V_2 |= 0x10 ;
F_2 ( 0 , V_1 + 4 , V_3 ) ;
if ( ! ( V_3 [ 0 ] & V_4 ) )
V_2 |= 0x08 ;
if ( ! ( V_3 [ 1 ] & V_4 ) )
V_2 |= 0x04 ;
if ( ! ( V_3 [ 2 ] & V_4 ) )
V_2 |= 0x02 ;
if ( ! ( V_3 [ 3 ] & V_4 ) )
V_2 |= 0x01 ;
return V_2 ;
}
static long F_3 ( unsigned long V_1 ,
unsigned long V_7 , unsigned long V_8 ,
unsigned long V_9 , unsigned long V_10 ,
int V_11 , int V_12 )
{
unsigned long V_13 ;
T_1 V_3 , V_14 , V_15 ;
if ( V_10 & V_16 )
return - 1 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_1
L_2 ,
V_1 , V_17 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_18 ) |
V_10 | V_19 ;
V_14 = F_6 ( V_8 , V_11 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_14 ) ;
if ( V_9 & V_20 )
V_14 &= ~ V_21 ;
F_7 ( & V_22 ) ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 == 0 ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_4 ) ;
F_8 ( & V_22 ) ;
return - 1 ;
}
V_13 = F_9 ( 0 , V_1 , V_13 << 48 ,
V_3 , V_14 , & V_15 ) ;
F_8 ( & V_22 ) ;
if ( F_10 ( V_13 != 0 ) ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_5 , V_13 ) ;
return - 2 ;
}
if ( ! ( V_10 & V_4 ) )
F_4 ( L_6 , V_15 ) ;
return ( V_15 ^ V_1 ) & 15 ;
}
static long F_11 ( unsigned long V_1 )
{
F_4 ( L_7 , V_1 ) ;
return - 1 ;
}
static unsigned long F_12 ( unsigned long V_15 )
{
unsigned long V_23 ;
unsigned long V_13 ;
T_1 V_24 [ 5 ] ;
V_13 = F_2 ( 0 , V_15 & ~ 3UL , V_24 ) ;
V_23 = V_24 [ V_15 & 3 ] ;
F_13 ( V_13 != 0 ) ;
return V_23 ;
}
static void F_14 ( void )
{
unsigned long V_25 = 1UL << V_26 ;
unsigned long V_27 = V_25 >> 4 ;
int V_28 ;
T_1 V_29 , V_30 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_15 ( 0 , V_28 , 0 , 0 , - 1UL , - 1UL , & V_29 , & V_30 ) ;
}
static long F_16 ( unsigned long V_15 ,
unsigned long V_31 ,
unsigned long V_7 ,
int V_11 , int V_12 , int V_32 )
{
unsigned long V_13 ;
T_1 V_29 , V_30 ;
unsigned long V_33 ;
V_33 = F_5 ( V_7 , V_11 , V_18 ) ;
F_4 ( L_8
L_9 ,
V_33 & V_34 , V_15 , V_11 , V_31 ) ;
F_7 ( & V_22 ) ;
V_29 = F_12 ( V_15 ) ;
if ( ( V_29 & ~ 0x7FUL ) != ( V_33 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_8 ( & V_22 ) ;
return - 1 ;
}
V_13 = F_15 ( 0 , V_15 , 0 , V_31 , 0 , 7 , & V_29 ,
& V_30 ) ;
F_8 ( & V_22 ) ;
if ( V_13 != 0 || V_29 == 0 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_11 , V_29 , V_30 ) ;
F_13 ( V_13 != 0 ) ;
return 0 ;
}
static long F_17 ( unsigned long V_7 , int V_11 )
{
unsigned long V_35 ;
unsigned long V_28 , V_36 ;
long V_15 ;
unsigned long V_33 , V_3 ;
V_35 = F_18 ( V_7 , V_37 [ V_11 ] . V_38 , V_18 ) ;
V_33 = F_5 ( V_7 , V_11 , V_18 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_15 = ( V_35 & V_5 ) * V_6 ;
for ( V_28 = 0 ; V_28 < V_6 ; V_28 ++ ) {
V_3 = F_12 ( V_15 ) ;
if ( F_19 ( V_3 , V_33 )
&& ( V_3 & V_19 )
&& ( ! ! ( V_3 & V_16 ) == V_36 ) ) {
if ( V_36 )
V_15 = - V_15 ;
return V_15 ;
}
++ V_15 ;
}
V_35 = ~ V_35 ;
}
return - 1 ;
}
static void F_20 ( unsigned long V_31 ,
unsigned long V_39 ,
int V_11 , int V_12 )
{
unsigned long V_7 ;
unsigned long V_13 , V_15 , V_40 ;
T_1 V_29 , V_30 ;
V_40 = F_21 ( V_39 , V_18 ) ;
V_7 = F_22 ( V_39 , V_40 , V_18 ) ;
F_7 ( & V_22 ) ;
V_15 = F_17 ( V_7 , V_11 ) ;
F_13 ( V_15 == - 1 ) ;
V_13 = F_15 ( 0 , V_15 , 0 , V_31 , 0 , 7 ,
& V_29 , & V_30 ) ;
F_8 ( & V_22 ) ;
F_13 ( V_13 != 0 ) ;
}
static void F_23 ( unsigned long V_15 , unsigned long V_7 ,
int V_11 , int V_12 , int V_32 )
{
unsigned long V_33 ;
unsigned long V_13 ;
T_1 V_30 , V_41 ;
unsigned long V_42 ;
F_4 ( L_12 ,
V_15 , V_17 , V_11 , V_32 ) ;
V_33 = F_5 ( V_7 , V_11 , V_18 ) ;
F_24 ( & V_22 , V_42 ) ;
V_30 = F_12 ( V_15 ) ;
if ( ( V_30 & ~ 0x7FUL ) != ( V_33 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_25 ( & V_22 , V_42 ) ;
return;
}
V_13 = F_15 ( 0 , V_15 , 0 , 0 , V_19 , 0 ,
& V_30 , & V_41 ) ;
F_25 ( & V_22 , V_42 ) ;
F_13 ( V_13 != 0 ) ;
}
void T_2 F_26 ( void )
{
V_43 . V_44 = F_23 ;
V_43 . V_45 = F_16 ;
V_43 . V_46 = F_20 ;
V_43 . V_47 = F_3 ;
V_43 . V_48 = F_11 ;
V_43 . V_49 = F_14 ;
}
static long F_27 ( unsigned long V_1 ,
unsigned long V_7 , unsigned long V_8 ,
unsigned long V_9 , unsigned long V_10 ,
int V_11 , int V_12 )
{
unsigned long V_13 ;
T_1 V_3 , V_14 , V_15 ;
if ( V_10 & V_16 )
return - 1 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_13
L_2 ,
V_1 , V_7 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_18 ) |
V_10 | V_19 ;
V_14 = F_6 ( V_8 , V_11 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_14 ) ;
if ( V_9 & V_20 )
V_14 &= ~ V_21 ;
V_13 = F_28 ( 0 , V_1 , V_3 , V_14 ,
V_4 , 0 , & V_15 ) ;
if ( F_10 ( V_13 != 0 ) ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_5 , V_13 ) ;
return - 2 ;
}
if ( ! ( V_10 & V_4 ) )
F_4 ( L_6 , V_15 ) ;
return ( V_15 ^ V_1 ) & 15 ;
}
static long F_29 ( unsigned long V_15 ,
unsigned long V_31 ,
unsigned long V_7 ,
int V_11 , int V_12 , int V_32 )
{
unsigned long V_13 ;
unsigned long V_33 ;
unsigned long V_50 ;
V_33 = F_5 ( V_7 , V_11 , V_18 ) ;
V_50 = ( V_11 == V_51 ) ? - 1UL : V_37 [ V_11 ] . V_52 ;
F_4 ( L_8
L_9 ,
V_33 & V_34 , V_15 , V_11 , V_31 ) ;
V_13 = F_30 ( 0 , V_15 , V_33 , V_50 , 7 , V_31 ) ;
if ( V_13 == 0xfffffff7 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_14 ) ;
F_13 ( V_13 != 0 ) ;
return 0 ;
}
static void F_31 ( unsigned long V_15 , unsigned long V_7 ,
int V_11 , int V_12 , int V_32 )
{
unsigned long V_33 ;
unsigned long V_13 ;
unsigned long V_50 ;
F_4 ( L_15 ,
V_15 , V_7 , V_11 , V_32 ) ;
V_33 = F_5 ( V_7 , V_11 , V_18 ) ;
V_50 = ( V_11 == V_51 ) ? - 1UL : V_37 [ V_11 ] . V_52 ;
V_13 = F_32 ( 0 , V_15 , V_33 , V_50 ) ;
F_13 ( V_13 != 0 && V_13 != 0xfffffff7 ) ;
}
static T_3 F_33 ( void )
{
return F_34 ( 0 ) ;
}
static void F_35 ( void )
{
F_33 () ;
}
void T_2 F_36 ( void )
{
if ( F_33 () == 0 ) {
V_43 . V_44 = F_31 ;
V_43 . V_45 = F_29 ;
V_43 . V_46 = F_20 ;
V_43 . V_47 = F_27 ;
V_43 . V_48 = F_11 ;
V_43 . V_49 = F_35 ;
} else {
V_43 . V_44 = F_23 ;
V_43 . V_45 = F_16 ;
V_43 . V_46 = F_20 ;
V_43 . V_47 = F_3 ;
V_43 . V_48 = F_11 ;
V_43 . V_49 = F_14 ;
}
}
