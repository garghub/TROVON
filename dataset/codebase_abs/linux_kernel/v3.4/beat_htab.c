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
V_1 , V_7 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_17 ) |
V_10 | V_18 ;
V_14 = F_6 ( V_8 , V_11 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_14 ) ;
if ( V_9 & V_19 )
V_14 &= ~ V_20 ;
F_7 ( & V_21 ) ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 == 0 ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_4 ) ;
F_8 ( & V_21 ) ;
return - 1 ;
}
V_13 = F_9 ( 0 , V_1 , V_13 << 48 ,
V_3 , V_14 , & V_15 ) ;
F_8 ( & V_21 ) ;
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
unsigned long V_22 ;
unsigned long V_13 ;
T_1 V_23 [ 5 ] ;
V_13 = F_2 ( 0 , V_15 & ~ 3UL , V_23 ) ;
V_22 = V_23 [ V_15 & 3 ] ;
F_13 ( V_13 != 0 ) ;
return V_22 ;
}
static void F_14 ( void )
{
unsigned long V_24 = 1UL << V_25 ;
unsigned long V_26 = V_24 >> 4 ;
int V_27 ;
T_1 V_28 , V_29 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_15 ( 0 , V_27 , 0 , 0 , - 1UL , - 1UL , & V_28 , & V_29 ) ;
}
static long F_16 ( unsigned long V_15 ,
unsigned long V_30 ,
unsigned long V_7 ,
int V_11 , int V_12 , int V_31 )
{
unsigned long V_13 ;
T_1 V_28 , V_29 ;
unsigned long V_32 ;
V_32 = F_5 ( V_7 , V_11 , V_17 ) ;
F_4 ( L_8
L_9 ,
V_32 & V_33 , V_15 , V_11 , V_30 ) ;
F_7 ( & V_21 ) ;
V_28 = F_12 ( V_15 ) ;
if ( ( V_28 & ~ 0x7FUL ) != ( V_32 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_8 ( & V_21 ) ;
return - 1 ;
}
V_13 = F_15 ( 0 , V_15 , 0 , V_30 , 0 , 7 , & V_28 ,
& V_29 ) ;
F_8 ( & V_21 ) ;
if ( V_13 != 0 || V_28 == 0 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_11 , V_28 , V_29 ) ;
F_13 ( V_13 != 0 ) ;
return 0 ;
}
static long F_17 ( unsigned long V_7 , int V_11 )
{
unsigned long V_34 ;
unsigned long V_27 , V_35 ;
long V_15 ;
unsigned long V_32 , V_3 ;
V_34 = F_18 ( V_7 , V_36 [ V_11 ] . V_37 , V_17 ) ;
V_32 = F_5 ( V_7 , V_11 , V_17 ) ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
V_15 = ( V_34 & V_5 ) * V_6 ;
for ( V_27 = 0 ; V_27 < V_6 ; V_27 ++ ) {
V_3 = F_12 ( V_15 ) ;
if ( F_19 ( V_3 , V_32 )
&& ( V_3 & V_18 )
&& ( ! ! ( V_3 & V_16 ) == V_35 ) ) {
if ( V_35 )
V_15 = - V_15 ;
return V_15 ;
}
++ V_15 ;
}
V_34 = ~ V_34 ;
}
return - 1 ;
}
static void F_20 ( unsigned long V_30 ,
unsigned long V_38 ,
int V_11 , int V_12 )
{
unsigned long V_13 , V_15 , V_39 , V_7 ;
T_1 V_28 , V_29 ;
V_39 = F_21 ( V_38 , V_17 ) ;
V_7 = ( V_39 << 28 ) | ( V_38 & 0x0fffffff ) ;
F_7 ( & V_21 ) ;
V_15 = F_17 ( V_7 , V_11 ) ;
F_13 ( V_15 == - 1 ) ;
V_13 = F_15 ( 0 , V_15 , 0 , V_30 , 0 , 7 ,
& V_28 , & V_29 ) ;
F_8 ( & V_21 ) ;
F_13 ( V_13 != 0 ) ;
}
static void F_22 ( unsigned long V_15 , unsigned long V_7 ,
int V_11 , int V_12 , int V_31 )
{
unsigned long V_32 ;
unsigned long V_13 ;
T_1 V_29 , V_40 ;
unsigned long V_41 ;
F_4 ( L_12 ,
V_15 , V_7 , V_11 , V_31 ) ;
V_32 = F_5 ( V_7 , V_11 , V_17 ) ;
F_23 ( & V_21 , V_41 ) ;
V_29 = F_12 ( V_15 ) ;
if ( ( V_29 & ~ 0x7FUL ) != ( V_32 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_24 ( & V_21 , V_41 ) ;
return;
}
V_13 = F_15 ( 0 , V_15 , 0 , 0 , V_18 , 0 ,
& V_29 , & V_40 ) ;
F_24 ( & V_21 , V_41 ) ;
F_13 ( V_13 != 0 ) ;
}
void T_2 F_25 ( void )
{
V_42 . V_43 = F_22 ;
V_42 . V_44 = F_16 ;
V_42 . V_45 = F_20 ;
V_42 . V_46 = F_3 ;
V_42 . V_47 = F_11 ;
V_42 . V_48 = F_14 ;
}
static long F_26 ( unsigned long V_1 ,
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
V_1 , V_7 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_17 ) |
V_10 | V_18 ;
V_14 = F_6 ( V_8 , V_11 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_14 ) ;
if ( V_9 & V_19 )
V_14 &= ~ V_20 ;
V_13 = F_27 ( 0 , V_1 , V_3 , V_14 ,
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
static long F_28 ( unsigned long V_15 ,
unsigned long V_30 ,
unsigned long V_7 ,
int V_11 , int V_12 , int V_31 )
{
unsigned long V_13 ;
unsigned long V_32 ;
unsigned long V_49 ;
V_32 = F_5 ( V_7 , V_11 , V_17 ) ;
V_49 = ( V_11 == V_50 ) ? - 1UL : V_36 [ V_11 ] . V_51 ;
F_4 ( L_8
L_9 ,
V_32 & V_33 , V_15 , V_11 , V_30 ) ;
V_13 = F_29 ( 0 , V_15 , V_32 , V_49 , 7 , V_30 ) ;
if ( V_13 == 0xfffffff7 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_13 ) ;
F_13 ( V_13 != 0 ) ;
return 0 ;
}
static void F_30 ( unsigned long V_15 , unsigned long V_7 ,
int V_11 , int V_12 , int V_31 )
{
unsigned long V_32 ;
unsigned long V_13 ;
unsigned long V_49 ;
F_4 ( L_12 ,
V_15 , V_7 , V_11 , V_31 ) ;
V_32 = F_5 ( V_7 , V_11 , V_17 ) ;
V_49 = ( V_11 == V_50 ) ? - 1UL : V_36 [ V_11 ] . V_51 ;
V_13 = F_31 ( 0 , V_15 , V_32 , V_49 ) ;
F_13 ( V_13 != 0 && V_13 != 0xfffffff7 ) ;
}
static T_3 F_32 ( void )
{
return F_33 ( 0 ) ;
}
static void F_34 ( void )
{
F_32 () ;
}
void T_2 F_35 ( void )
{
if ( F_32 () == 0 ) {
V_42 . V_43 = F_30 ;
V_42 . V_44 = F_28 ;
V_42 . V_45 = F_20 ;
V_42 . V_46 = F_26 ;
V_42 . V_47 = F_11 ;
V_42 . V_48 = F_34 ;
} else {
V_42 . V_43 = F_22 ;
V_42 . V_44 = F_16 ;
V_42 . V_45 = F_20 ;
V_42 . V_46 = F_3 ;
V_42 . V_47 = F_11 ;
V_42 . V_48 = F_14 ;
}
}
