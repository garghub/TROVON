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
static int F_4 ( int V_4 )
{
return F_5 ( V_5 , V_4 ) ;
}
static inline unsigned long F_6 ( int V_4 )
{
unsigned long V_6 , V_7 ;
V_6 = F_7 ( V_8 ) & ~ V_9 ;
V_7 = F_8 ( V_10 , V_4 ) ;
V_6 |= F_9 ( V_7 ) ;
return V_6 ;
}
static void F_10 ( void )
{
unsigned long V_6 ;
int V_4 = F_11 () ;
F_12 ( V_11 , V_12 ) ;
V_6 = F_6 ( V_4 ) ;
F_12 ( V_8 , V_6 ) ;
}
static void F_13 ( void )
{
F_14 ( V_13
L_1 ,
V_14 ) ;
}
static int F_15 ( int V_15 )
{
if ( V_15 < V_16 )
return ( int ) F_8 ( V_10 , V_15 ) ;
return V_17 ;
}
static void F_16 ( T_1 * V_18 , T_1 * V_19 )
{
F_17 ( 0xFFL , V_19 ) ;
}
static int F_18 ( int V_20 )
{
return 1 ;
}
static int F_19 ( int V_21 , int V_22 )
{
return V_21 >> V_22 ;
}
static inline void F_20 ( const struct V_23 * V_24 , int V_25 )
{
F_21 ( V_24 , V_25 ) ;
}
static void F_22 ( int V_25 )
{
F_23 ( V_26 , V_25 ) ;
}
static void F_24 ( int V_25 )
{
F_20 ( V_26 , V_25 ) ;
}
static int F_25 ( const struct V_27 * V_28 )
{
F_14 ( V_29 L_2 , V_28 -> V_30 ) ;
V_31 = 1 ;
return 0 ;
}
static int F_26 ( void )
{
if ( V_32 )
V_31 = 1 ;
else
F_27 ( V_33 ) ;
return V_31 ;
}
void T_2 F_28 ( void )
{
unsigned int V_4 ;
if ( ! F_26 () )
return;
V_34 = & V_35 ;
F_29 (cpu) {
if ( F_5 ( V_36 ,
V_4 ) == V_17 )
continue;
F_5 ( V_36 , V_4 ) =
F_4 ( V_4 ) ;
}
F_30 ( L_3 , V_35 . V_37 ) ;
}
