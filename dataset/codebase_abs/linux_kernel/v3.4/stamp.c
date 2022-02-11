void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , L_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
if ( V_7 == V_12 )
return;
if ( V_8 & V_13 )
F_5 ( V_7 , V_10 -> V_14 + ( 1 << V_15 ) ) ;
else
F_5 ( V_7 , V_10 -> V_14 + ( 1 << V_16 ) ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
return F_7 ( V_17 ) ;
}
static void F_8 ( void )
{
F_2 ( V_17 , L_2 ) ;
}
static void F_8 ( void ) {}
static int F_9 ( struct V_1 * V_2 ,
T_1 (* F_10)( int , void * ) , void * V_18 )
{
return F_11 ( V_19 , F_10 ,
V_20 , L_3 , V_18 ) ;
}
static void F_12 ( struct V_1 * V_2 , void * V_18 )
{
F_13 ( V_19 , V_18 ) ;
}
static inline void F_14 ( void )
{
F_15 ( V_21 . V_22 ) ;
}
static inline void F_14 ( void ) {}
static int F_16 ( void )
{
return F_7 ( V_23 ) ;
}
static int T_2 F_17 ( void )
{
#if F_18 ( V_24 ) || F_18 ( V_25 )
int V_26 ;
V_26 = F_2 ( V_23 , L_4 ) ;
if ( V_26 )
return V_26 ;
F_3 ( V_23 , 0 ) ;
F_19 ( 2 ) ;
F_20 ( V_23 , 1 ) ;
#endif
return 0 ;
}
static int T_2 F_21 ( void )
{
F_22 ( V_27 L_5 , V_28 ) ;
F_8 () ;
F_14 () ;
F_23 ( V_29 , F_24 ( V_29 ) ) ;
F_25 ( 0 , V_30 ,
F_24 ( V_30 ) ) ;
F_26 ( V_31 , F_24 ( V_31 ) ) ;
if ( F_17 () )
F_27 ( L_6 ) ;
return 0 ;
}
void T_2 F_28 ( void )
{
F_22 ( V_27 L_7 ) ;
F_29 ( V_32 ,
F_24 ( V_32 ) ) ;
}
void F_30 ( char * V_7 )
{
if ( ( F_31 () & 0x7 ) == 0x3 )
F_32 ( V_33 ) ;
}
int F_33 ( char * V_34 )
{
* ( V_35 * ) ( & ( V_34 [ 0 ] ) ) = F_34 ( V_36 ) ;
* ( V_37 * ) ( & ( V_34 [ 4 ] ) ) = F_35 ( V_36 + 4 ) ;
return 0 ;
}
