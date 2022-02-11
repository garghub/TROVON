static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 = 1 << V_1 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
V_5 |= V_2 ;
if ( V_1 & 8 )
F_3 ( V_6 , V_7 ) ;
else
F_3 ( V_8 , V_9 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
F_1 ( V_11 -> V_1 ) ;
}
static void F_6 ( unsigned int V_1 )
{
unsigned int V_2 = ~ ( 1 << V_1 ) ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
V_5 &= V_2 ;
if ( V_1 & 8 )
F_3 ( V_6 , V_7 ) ;
else
F_3 ( V_8 , V_9 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
F_6 ( V_11 -> V_1 ) ;
}
static int F_8 ( unsigned int V_1 )
{
unsigned int V_2 = 1 << V_1 ;
unsigned long V_3 ;
int V_12 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_1 < 8 )
V_12 = F_9 ( V_13 ) & V_2 ;
else
V_12 = F_9 ( V_14 ) & ( V_2 >> 8 ) ;
F_4 ( & V_4 , V_3 ) ;
return V_12 ;
}
static void F_10 ( unsigned int V_1 )
{
F_11 ( V_1 ) ;
V_15 &= ~ ( 1 << V_1 ) ;
F_12 ( V_1 , & V_16 , V_17 ) ;
F_13 ( V_1 ) ;
}
static inline int F_14 ( unsigned int V_1 )
{
int V_18 ;
int V_19 = 1 << V_1 ;
if ( V_1 < 8 ) {
F_3 ( 0x0B , V_13 ) ;
V_18 = F_9 ( V_13 ) & V_19 ;
F_3 ( 0x0A , V_13 ) ;
return V_18 ;
}
F_3 ( 0x0B , V_14 ) ;
V_18 = F_9 ( V_14 ) & ( V_19 >> 8 ) ;
F_3 ( 0x0A , V_14 ) ;
return V_18 ;
}
static void F_15 ( struct V_10 * V_11 )
{
unsigned int V_1 = V_11 -> V_1 ;
unsigned int V_19 = 1 << V_1 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_5 & V_19 )
goto V_20;
V_5 |= V_19 ;
V_21:
if ( V_1 & 8 ) {
F_9 ( V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( 0x60 + ( V_1 & 7 ) , V_14 ) ;
F_3 ( 0x60 + V_22 , V_13 ) ;
} else {
F_9 ( V_9 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( 0x60 + V_1 , V_13 ) ;
}
F_4 ( & V_4 , V_3 ) ;
return;
V_20:
if ( F_14 ( V_1 ) )
goto V_21;
{
static int V_23 ;
if ( ! ( V_23 & V_19 ) ) {
F_16 ( V_24
L_1 , V_1 ) ;
V_23 |= V_19 ;
}
F_17 ( & V_25 ) ;
goto V_21;
}
}
static void F_18 ( char * V_26 )
{
F_3 ( V_26 [ 0 ] , 0x4d0 ) ;
F_3 ( V_26 [ 1 ] , 0x4d1 ) ;
}
static void F_19 ( char * V_26 )
{
V_26 [ 0 ] = F_9 ( 0x4d0 ) & 0xF8 ;
V_26 [ 1 ] = F_9 ( 0x4d1 ) & 0xDE ;
}
static void F_20 ( void )
{
F_21 ( V_27 ) ;
F_18 ( V_28 ) ;
}
static int F_22 ( void )
{
F_19 ( V_28 ) ;
return 0 ;
}
static void F_23 ( void )
{
F_3 ( 0xff , V_9 ) ;
F_3 ( 0xff , V_7 ) ;
}
static void F_24 ( void )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( 0xff , V_9 ) ;
F_3 ( 0xff , V_7 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_25 ( void )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( V_6 , V_7 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_21 ( int V_29 )
{
unsigned long V_3 ;
unsigned char V_30 = ~ ( 1 << V_22 ) ;
unsigned char V_31 ;
V_27 = V_29 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( 0xff , V_7 ) ;
F_3 ( V_30 , V_9 ) ;
V_31 = F_9 ( V_9 ) ;
if ( V_31 != V_30 ) {
F_16 ( V_32 L_2 ) ;
V_33 = & V_34 ;
F_4 ( & V_4 , V_3 ) ;
return;
}
F_3 ( 0xff , V_9 ) ;
F_26 ( 0x11 , V_13 ) ;
F_26 ( V_35 , V_9 ) ;
F_26 ( 1U << V_22 , V_9 ) ;
if ( V_29 )
F_26 ( V_36 | V_37 , V_9 ) ;
else
F_26 ( V_36 , V_9 ) ;
F_26 ( 0x11 , V_14 ) ;
F_26 ( V_38 , V_7 ) ;
F_26 ( V_22 , V_7 ) ;
F_26 ( V_39 , V_7 ) ;
if ( V_29 )
V_16 . V_40 = F_5 ;
else
V_16 . V_40 = F_15 ;
F_27 ( 100 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( V_6 , V_7 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_28 ( void ) { }
static void F_29 ( unsigned int V_41 ) { }
static void F_30 ( int V_41 ) { }
static int F_31 ( unsigned int V_1 )
{
return 0 ;
}
static int T_1 F_32 ( void )
{
if ( V_33 == & V_42 )
F_33 ( & V_43 ) ;
return 0 ;
}
