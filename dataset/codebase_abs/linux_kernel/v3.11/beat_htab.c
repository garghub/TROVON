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
int V_11 , int V_12 , int V_13 )
{
unsigned long V_14 ;
T_1 V_3 , V_15 , V_16 ;
if ( V_10 & V_17 )
return - 1 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_1
L_2 ,
V_1 , V_18 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_12 , V_19 ) |
V_10 | V_20 ;
V_15 = F_6 ( V_8 , V_11 , V_12 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_15 ) ;
if ( V_9 & V_21 )
V_15 &= ~ V_22 ;
F_7 ( & V_23 ) ;
V_14 = F_1 ( V_1 ) ;
if ( V_14 == 0 ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_4 ) ;
F_8 ( & V_23 ) ;
return - 1 ;
}
V_14 = F_9 ( 0 , V_1 , V_14 << 48 ,
V_3 , V_15 , & V_16 ) ;
F_8 ( & V_23 ) ;
if ( F_10 ( V_14 != 0 ) ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_5 , V_14 ) ;
return - 2 ;
}
if ( ! ( V_10 & V_4 ) )
F_4 ( L_6 , V_16 ) ;
return ( V_16 ^ V_1 ) & 15 ;
}
static long F_11 ( unsigned long V_1 )
{
F_4 ( L_7 , V_1 ) ;
return - 1 ;
}
static unsigned long F_12 ( unsigned long V_16 )
{
unsigned long V_24 ;
unsigned long V_14 ;
T_1 V_25 [ 5 ] ;
V_14 = F_2 ( 0 , V_16 & ~ 3UL , V_25 ) ;
V_24 = V_25 [ V_16 & 3 ] ;
F_13 ( V_14 != 0 ) ;
return V_24 ;
}
static void F_14 ( void )
{
unsigned long V_26 = 1UL << V_27 ;
unsigned long V_28 = V_26 >> 4 ;
int V_29 ;
T_1 V_30 , V_31 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
F_15 ( 0 , V_29 , 0 , 0 , - 1UL , - 1UL , & V_30 , & V_31 ) ;
}
static long F_16 ( unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_7 ,
int V_11 , int V_12 ,
int V_13 , int V_33 )
{
unsigned long V_14 ;
T_1 V_30 , V_31 ;
unsigned long V_34 ;
V_34 = F_17 ( V_7 , V_11 , V_19 ) ;
F_4 ( L_8
L_9 ,
V_34 & V_35 , V_16 , V_11 , V_32 ) ;
F_7 ( & V_23 ) ;
V_30 = F_12 ( V_16 ) ;
if ( ( V_30 & ~ 0x7FUL ) != ( V_34 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_8 ( & V_23 ) ;
return - 1 ;
}
V_14 = F_15 ( 0 , V_16 , 0 , V_32 , 0 , 7 , & V_30 ,
& V_31 ) ;
F_8 ( & V_23 ) ;
if ( V_14 != 0 || V_30 == 0 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_11 , V_30 , V_31 ) ;
F_13 ( V_14 != 0 ) ;
return 0 ;
}
static long F_18 ( unsigned long V_7 , int V_11 )
{
unsigned long V_36 ;
unsigned long V_29 , V_37 ;
long V_16 ;
unsigned long V_34 , V_3 ;
V_36 = F_19 ( V_7 , V_38 [ V_11 ] . V_39 , V_19 ) ;
V_34 = F_17 ( V_7 , V_11 , V_19 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
V_16 = ( V_36 & V_5 ) * V_6 ;
for ( V_29 = 0 ; V_29 < V_6 ; V_29 ++ ) {
V_3 = F_12 ( V_16 ) ;
if ( F_20 ( V_3 , V_34 )
&& ( V_3 & V_20 )
&& ( ! ! ( V_3 & V_17 ) == V_37 ) ) {
if ( V_37 )
V_16 = - V_16 ;
return V_16 ;
}
++ V_16 ;
}
V_36 = ~ V_36 ;
}
return - 1 ;
}
static void F_21 ( unsigned long V_32 ,
unsigned long V_40 ,
int V_11 , int V_13 )
{
unsigned long V_7 ;
unsigned long V_14 , V_16 , V_41 ;
T_1 V_30 , V_31 ;
V_41 = F_22 ( V_40 , V_19 ) ;
V_7 = F_23 ( V_40 , V_41 , V_19 ) ;
F_7 ( & V_23 ) ;
V_16 = F_18 ( V_7 , V_11 ) ;
F_13 ( V_16 == - 1 ) ;
V_14 = F_15 ( 0 , V_16 , 0 , V_32 , 0 , 7 ,
& V_30 , & V_31 ) ;
F_8 ( & V_23 ) ;
F_13 ( V_14 != 0 ) ;
}
static void F_24 ( unsigned long V_16 , unsigned long V_7 ,
int V_11 , int V_12 ,
int V_13 , int V_33 )
{
unsigned long V_34 ;
unsigned long V_14 ;
T_1 V_31 , V_42 ;
unsigned long V_43 ;
F_4 ( L_12 ,
V_16 , V_18 , V_11 , V_33 ) ;
V_34 = F_17 ( V_7 , V_11 , V_19 ) ;
F_25 ( & V_23 , V_43 ) ;
V_31 = F_12 ( V_16 ) ;
if ( ( V_31 & ~ 0x7FUL ) != ( V_34 & ~ 0x7FUL ) ) {
F_4 ( L_10 ) ;
F_26 ( & V_23 , V_43 ) ;
return;
}
V_14 = F_15 ( 0 , V_16 , 0 , 0 , V_20 , 0 ,
& V_31 , & V_42 ) ;
F_26 ( & V_23 , V_43 ) ;
F_13 ( V_14 != 0 ) ;
}
void T_2 F_27 ( void )
{
V_44 . V_45 = F_24 ;
V_44 . V_46 = F_16 ;
V_44 . V_47 = F_21 ;
V_44 . V_48 = F_3 ;
V_44 . V_49 = F_11 ;
V_44 . V_50 = F_14 ;
}
static long F_28 ( unsigned long V_1 ,
unsigned long V_7 , unsigned long V_8 ,
unsigned long V_9 , unsigned long V_10 ,
int V_11 , int V_12 , int V_13 )
{
unsigned long V_14 ;
T_1 V_3 , V_15 , V_16 ;
if ( V_10 & V_17 )
return - 1 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_13
L_2 ,
V_1 , V_7 , V_8 , V_9 , V_10 , V_11 ) ;
V_3 = F_5 ( V_7 , V_11 , V_12 , V_19 ) |
V_10 | V_20 ;
V_15 = F_6 ( V_8 , V_11 , V_12 ) | V_9 ;
if ( ! ( V_10 & V_4 ) )
F_4 ( L_3 , V_3 , V_15 ) ;
if ( V_9 & V_21 )
V_15 &= ~ V_22 ;
V_14 = F_29 ( 0 , V_1 , V_3 , V_15 ,
V_4 , 0 , & V_16 ) ;
if ( F_10 ( V_14 != 0 ) ) {
if ( ! ( V_10 & V_4 ) )
F_4 ( L_5 , V_14 ) ;
return - 2 ;
}
if ( ! ( V_10 & V_4 ) )
F_4 ( L_6 , V_16 ) ;
return ( V_16 ^ V_1 ) & 15 ;
}
static long F_30 ( unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_7 ,
int V_11 , int V_12 ,
int V_13 , int V_33 )
{
unsigned long V_14 ;
unsigned long V_34 ;
unsigned long V_51 ;
V_34 = F_17 ( V_7 , V_11 , V_19 ) ;
V_51 = ( V_11 == V_52 ) ? - 1UL : V_38 [ V_11 ] . V_53 [ V_11 ] ;
F_4 ( L_8
L_9 ,
V_34 & V_35 , V_16 , V_11 , V_32 ) ;
V_14 = F_31 ( 0 , V_16 , V_34 , V_51 , 7 , V_32 ) ;
if ( V_14 == 0xfffffff7 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
F_4 ( L_14 ) ;
F_13 ( V_14 != 0 ) ;
return 0 ;
}
static void F_32 ( unsigned long V_16 , unsigned long V_7 ,
int V_11 , int V_12 ,
int V_13 , int V_33 )
{
unsigned long V_34 ;
unsigned long V_14 ;
unsigned long V_51 ;
F_4 ( L_15 ,
V_16 , V_7 , V_11 , V_33 ) ;
V_34 = F_17 ( V_7 , V_11 , V_19 ) ;
V_51 = ( V_11 == V_52 ) ? - 1UL : V_38 [ V_11 ] . V_53 [ V_11 ] ;
V_14 = F_33 ( 0 , V_16 , V_34 , V_51 ) ;
F_13 ( V_14 != 0 && V_14 != 0xfffffff7 ) ;
}
static T_3 F_34 ( void )
{
return F_35 ( 0 ) ;
}
static void F_36 ( void )
{
F_34 () ;
}
void T_2 F_37 ( void )
{
if ( F_34 () == 0 ) {
V_44 . V_45 = F_32 ;
V_44 . V_46 = F_30 ;
V_44 . V_47 = F_21 ;
V_44 . V_48 = F_28 ;
V_44 . V_49 = F_11 ;
V_44 . V_50 = F_36 ;
} else {
V_44 . V_45 = F_24 ;
V_44 . V_46 = F_16 ;
V_44 . V_47 = F_21 ;
V_44 . V_48 = F_3 ;
V_44 . V_49 = F_11 ;
V_44 . V_50 = F_14 ;
}
}
