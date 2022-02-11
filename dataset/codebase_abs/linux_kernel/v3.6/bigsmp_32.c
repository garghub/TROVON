static unsigned F_1 ( unsigned long V_1 )
{
return ( V_1 >> 24 ) & 0xFF ;
}
static int F_2 ( void )
{
return 1 ;
}
static unsigned long F_3 ( T_1 * V_2 , int V_3 )
{
return 0 ;
}
static unsigned long F_4 ( int V_4 )
{
return 1 ;
}
static int F_5 ( int V_5 )
{
return F_6 ( V_6 , V_5 ) ;
}
static inline unsigned long F_7 ( int V_5 )
{
unsigned long V_7 , V_8 ;
V_7 = F_8 ( V_9 ) & ~ V_10 ;
V_8 = F_9 ( V_11 , V_5 ) ;
V_7 |= F_10 ( V_8 ) ;
return V_7 ;
}
static void F_11 ( void )
{
unsigned long V_7 ;
int V_5 = F_12 () ;
F_13 ( V_12 , V_13 ) ;
V_7 = F_7 ( V_5 ) ;
F_13 ( V_9 , V_7 ) ;
}
static void F_14 ( void )
{
F_15 ( V_14
L_1 ,
V_15 ) ;
}
static int F_16 ( int V_16 )
{
if ( V_16 < V_17 )
return ( int ) F_9 ( V_11 , V_16 ) ;
return V_18 ;
}
static void F_17 ( T_1 * V_19 , T_1 * V_20 )
{
F_18 ( 0xFFL , V_20 ) ;
}
static int F_19 ( int V_21 )
{
return 1 ;
}
static int F_20 ( int V_22 , int V_23 )
{
return V_22 >> V_23 ;
}
static inline void F_21 ( const struct V_24 * V_25 , int V_26 )
{
F_22 ( V_25 , V_26 ) ;
}
static void F_23 ( int V_26 )
{
F_24 ( V_27 , V_26 ) ;
}
static void F_25 ( int V_26 )
{
F_21 ( V_27 , V_26 ) ;
}
static int F_26 ( const struct V_28 * V_29 )
{
F_15 ( V_30 L_2 , V_29 -> V_31 ) ;
V_32 = 1 ;
return 0 ;
}
static int F_27 ( void )
{
if ( V_33 )
V_32 = 1 ;
else
F_28 ( V_34 ) ;
return V_32 ;
}
void T_2 F_29 ( void )
{
unsigned int V_5 ;
if ( ! F_27 () )
return;
V_35 = & V_36 ;
F_30 (cpu) {
if ( F_6 ( V_37 ,
V_5 ) == V_18 )
continue;
F_6 ( V_37 , V_5 ) =
F_5 ( V_5 ) ;
}
F_31 ( L_3 , V_36 . V_38 ) ;
}
