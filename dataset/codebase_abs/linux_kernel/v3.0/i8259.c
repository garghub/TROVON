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
F_12 ( V_1 , & V_16 , V_17 ,
V_16 . V_18 ) ;
F_13 ( V_1 ) ;
}
static inline int F_14 ( unsigned int V_1 )
{
int V_19 ;
int V_20 = 1 << V_1 ;
if ( V_1 < 8 ) {
F_3 ( 0x0B , V_13 ) ;
V_19 = F_9 ( V_13 ) & V_20 ;
F_3 ( 0x0A , V_13 ) ;
return V_19 ;
}
F_3 ( 0x0B , V_14 ) ;
V_19 = F_9 ( V_14 ) & ( V_20 >> 8 ) ;
F_3 ( 0x0A , V_14 ) ;
return V_19 ;
}
static void F_15 ( struct V_10 * V_11 )
{
unsigned int V_1 = V_11 -> V_1 ;
unsigned int V_20 = 1 << V_1 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_5 & V_20 )
goto V_21;
V_5 |= V_20 ;
V_22:
if ( V_1 & 8 ) {
F_9 ( V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( 0x60 + ( V_1 & 7 ) , V_14 ) ;
F_3 ( 0x60 + V_23 , V_13 ) ;
} else {
F_9 ( V_9 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( 0x60 + V_1 , V_13 ) ;
}
F_4 ( & V_4 , V_3 ) ;
return;
V_21:
if ( F_14 ( V_1 ) )
goto V_22;
{
static int V_24 ;
if ( ! ( V_24 & V_20 ) ) {
F_16 ( V_25
L_1 , V_1 ) ;
V_24 |= V_20 ;
}
F_17 ( & V_26 ) ;
goto V_22;
}
}
static void F_18 ( char * V_27 )
{
F_3 ( V_27 [ 0 ] , 0x4d0 ) ;
F_3 ( V_27 [ 1 ] , 0x4d1 ) ;
}
static void F_19 ( char * V_27 )
{
V_27 [ 0 ] = F_9 ( 0x4d0 ) & 0xF8 ;
V_27 [ 1 ] = F_9 ( 0x4d1 ) & 0xDE ;
}
static void F_20 ( void )
{
F_21 ( V_28 ) ;
F_18 ( V_29 ) ;
}
static int F_22 ( void )
{
F_19 ( V_29 ) ;
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
static void F_21 ( int V_30 )
{
unsigned long V_3 ;
V_28 = V_30 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( 0xff , V_9 ) ;
F_3 ( 0xff , V_7 ) ;
F_26 ( 0x11 , V_13 ) ;
F_26 ( V_31 , V_9 ) ;
F_26 ( 1U << V_23 , V_9 ) ;
if ( V_30 )
F_26 ( V_32 | V_33 , V_9 ) ;
else
F_26 ( V_32 , V_9 ) ;
F_26 ( 0x11 , V_14 ) ;
F_26 ( V_34 , V_7 ) ;
F_26 ( V_23 , V_7 ) ;
F_26 ( V_35 , V_7 ) ;
if ( V_30 )
V_16 . V_36 = F_5 ;
else
V_16 . V_36 = F_15 ;
F_27 ( 100 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( V_6 , V_7 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_28 ( void ) { }
static void F_29 ( unsigned int V_37 ) { }
static void F_30 ( int V_37 ) { }
static int F_31 ( unsigned int V_1 )
{
return 0 ;
}
static int T_1 F_32 ( void )
{
if ( V_38 == & V_39 )
F_33 ( & V_40 ) ;
return 0 ;
}
