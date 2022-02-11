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
F_9 ( V_17 ) ;
}
static void F_8 ( void ) {}
static int F_10 ( struct V_1 * V_2 ,
T_1 (* F_11)( int , void * ) , void * V_18 )
{
return F_12 ( V_19 , F_11 ,
V_20 , L_3 , V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 , void * V_18 )
{
F_14 ( V_19 , V_18 ) ;
}
static inline void F_15 ( void )
{
F_16 ( V_21 . V_22 ) ;
}
static inline void F_15 ( void ) {}
static int F_17 ( void )
{
return F_7 ( V_23 ) ;
}
static int T_2 F_18 ( void )
{
#if F_19 ( V_24 )
int V_25 ;
V_25 = F_2 ( V_23 , L_4 ) ;
if ( V_25 )
return V_25 ;
F_3 ( V_23 , 0 ) ;
F_20 ( 2 ) ;
F_21 ( V_23 , 1 ) ;
#endif
return 0 ;
}
static int T_2 F_22 ( void )
{
F_23 ( V_26 L_5 , V_27 ) ;
F_8 () ;
F_15 () ;
F_24 ( V_28 , F_25 ( V_28 ) ) ;
F_26 ( 0 , V_29 ,
F_25 ( V_29 ) ) ;
F_27 ( V_30 , F_25 ( V_30 ) ) ;
if ( F_18 () )
F_28 ( L_6 ) ;
return 0 ;
}
void T_2 F_29 ( void )
{
F_23 ( V_26 L_7 ) ;
F_30 ( V_31 ,
F_25 ( V_31 ) ) ;
}
void F_31 ( char * V_7 )
{
if ( ( F_32 () & 0x7 ) == 0x3 )
F_33 ( V_32 ) ;
}
int F_34 ( char * V_33 )
{
* ( V_34 * ) ( & ( V_33 [ 0 ] ) ) = F_35 ( V_35 ) ;
* ( V_36 * ) ( & ( V_33 [ 4 ] ) ) = F_36 ( V_35 + 4 ) ;
return 0 ;
}
