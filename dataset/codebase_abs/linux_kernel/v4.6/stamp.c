void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , L_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
if ( V_7 == V_11 )
return;
if ( V_8 & V_12 )
F_6 ( V_7 , V_10 -> V_13 + ( 1 << V_14 ) ) ;
else
F_6 ( V_7 , V_10 -> V_13 + ( 1 << V_15 ) ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_16 ) ;
}
static void F_9 ( void )
{
F_2 ( V_16 , L_2 ) ;
F_10 ( V_16 ) ;
}
static void F_9 ( void ) {}
static int F_11 ( struct V_1 * V_2 ,
T_1 (* F_12)( int , void * ) , void * V_17 )
{
return F_13 ( V_18 , F_12 ,
V_19 , L_3 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 , void * V_17 )
{
F_15 ( V_18 , V_17 ) ;
}
static inline void F_16 ( void )
{
F_17 ( V_20 . V_21 ) ;
}
static inline void F_16 ( void ) {}
static int F_18 ( void )
{
return F_8 ( V_22 ) ;
}
static int T_2 F_19 ( void )
{
#if F_20 ( V_23 )
int V_24 ;
V_24 = F_2 ( V_22 , L_4 ) ;
if ( V_24 )
return V_24 ;
F_3 ( V_22 , 0 ) ;
F_21 ( 2 ) ;
F_22 ( V_22 , 1 ) ;
#endif
return 0 ;
}
static int T_2 F_23 ( void )
{
F_24 ( V_25 L_5 , V_26 ) ;
F_9 () ;
F_16 () ;
F_25 ( V_27 , F_26 ( V_27 ) ) ;
F_27 ( 0 , V_28 ,
F_26 ( V_28 ) ) ;
F_28 ( V_29 , F_26 ( V_29 ) ) ;
if ( F_19 () )
F_29 ( L_6 ) ;
return 0 ;
}
void T_2 F_30 ( void )
{
F_24 ( V_25 L_7 ) ;
F_31 ( V_30 ,
F_26 ( V_30 ) ) ;
}
void F_32 ( char * V_7 )
{
if ( ( F_33 () & 0x7 ) == 0x3 )
F_34 ( V_31 ) ;
}
int F_35 ( char * V_32 )
{
* ( V_33 * ) ( & ( V_32 [ 0 ] ) ) = F_36 ( V_34 ) ;
* ( V_35 * ) ( & ( V_32 [ 4 ] ) ) = F_37 ( V_34 + 4 ) ;
return 0 ;
}
