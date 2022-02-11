static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 +
F_3 ( 0 ) + V_3 ) ;
}
static inline void F_4 ( void )
{
F_2 ( V_1 , V_2 +
F_3 ( 0 ) + V_4 ) ;
}
static void F_5 ( void )
{
F_2 ( V_5 , V_2 +
F_3 ( 0 ) + V_3 ) ;
}
static T_1 F_6 ( struct V_6 * V_7 )
{
return ~ ( ( F_7 ( V_2 + F_8 ( 1 ) )
& 0xffff0000 ) >> 16 ) ;
}
static int F_9 ( unsigned long V_8 ,
struct V_9 * V_10 )
{
F_2 ( V_8 , V_2 + F_8 ( 0 ) ) ;
return 0 ;
}
static int F_10 ( unsigned long V_8 ,
struct V_9 * V_10 )
{
F_2 ( V_8 , V_2 + F_11 ( 0 ) ) ;
return 0 ;
}
static T_2 F_12 ( int V_11 , void * V_12 )
{
struct V_9 * V_8 = V_12 ;
F_5 () ;
V_8 -> V_13 ( V_8 ) ;
return V_14 ;
}
static void F_13 ( char * V_15 )
{
F_1 () ;
if ( F_14 () )
F_2 ( 0xffff , V_2 + F_8 ( 1 ) ) ;
else
F_2 ( 0xffffffff ,
V_2 + F_11 ( 1 ) ) ;
F_5 () ;
#ifdef F_15
F_16 ( L_1 , __func__, state)
#endif
}
static int F_17 ( struct V_9 * V_8 )
{
F_13 ( L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_8 )
{
if ( F_19 ( V_8 ) )
F_13 ( L_3 ) ;
F_4 () ;
return 0 ;
}
static int T_3 F_20 ( struct V_16 * V_17 )
{
if ( F_14 () )
V_18 . V_19 = F_9 ;
V_18 . V_20 = F_21 ( 0 ) ;
F_22 ( & V_18 ,
F_23 ( V_17 ) ,
F_14 () ? 0xf : 0x2 ,
F_14 () ? 0xfffe : 0xfffffffe ) ;
return 0 ;
}
static T_4 T_5 F_24 ( void )
{
return ~ F_25 ( V_2 + F_26 ( 1 ) ) ;
}
static int T_3 F_27 ( struct V_16 * V_17 )
{
unsigned int V_21 = F_23 ( V_17 ) ;
if ( F_14 () )
F_28 ( & V_22 , V_21 ) ;
else {
F_29 ( V_2 + F_26 ( 1 ) ,
L_4 , V_21 , 200 , 32 , V_23 ) ;
F_30 ( F_24 , 32 , V_21 ) ;
}
return 0 ;
}
static int T_3 F_31 ( struct V_24 * V_25 )
{
struct V_16 * V_17 ;
int V_11 , V_26 ;
V_2 = F_32 ( V_25 , 0 ) ;
F_33 ( ! V_2 ) ;
V_17 = F_34 ( V_25 , 0 ) ;
if ( F_35 ( V_17 ) ) {
F_36 ( L_5 , V_27 ) ;
return F_37 ( V_17 ) ;
}
V_26 = F_38 ( V_17 ) ;
if ( V_26 )
return V_26 ;
F_39 ( V_2 + V_28 ) ;
V_29 = F_7 ( V_2 +
( F_40 ( V_25 , L_6 ) ?
V_30 :
V_31 ) ) ;
V_29 >>= V_32 ;
F_2 ( ( F_14 () ?
V_33 :
V_34 ) |
V_35 |
V_1 ,
V_2 + F_3 ( 0 ) ) ;
F_2 ( ( F_14 () ?
V_33 :
V_34 ) |
V_36 ,
V_2 + F_3 ( 1 ) ) ;
if ( F_14 () )
F_2 ( 0xffff ,
V_2 + F_8 ( 1 ) ) ;
else
F_2 ( 0xffffffff ,
V_2 + F_11 ( 1 ) ) ;
V_26 = F_27 ( V_17 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_20 ( V_17 ) ;
if ( V_26 )
return V_26 ;
V_11 = F_41 ( V_25 , 0 ) ;
if ( V_11 <= 0 )
return - V_37 ;
return F_42 ( V_11 , & V_38 ) ;
}
