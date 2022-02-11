static void T_1 F_1 ( void )
{
F_2 ( 50 * 1000 * 1000 ) ;
}
void T_1 F_3 ( void )
{
F_4 () ;
F_5 ( V_1 , F_6 ( V_1 ) ) ;
}
static int F_7 ( int V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = 0xe0000000 ;
F_8 ( V_2 , V_4 ) ;
return 1 ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_6 , 0x00100000 ) ;
F_11 () ;
F_12 ( L_1 ) ;
}
static inline int F_13 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
if ( V_8 -> V_10 == 0x01 && V_9 == 0x10 )
return 0 ;
return 1 ;
}
static int F_14 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_11 , int V_12 , T_2 * V_13 )
{
if ( F_13 ( V_8 , V_9 ) )
return F_15 ( V_8 , V_9 , V_11 , V_12 , V_13 ) ;
return V_14 ;
}
static int F_16 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_11 , int V_12 , T_2 V_13 )
{
if ( F_13 ( V_8 , V_9 ) )
return F_17 ( V_8 , V_9 , V_11 , V_12 , V_13 ) ;
return V_14 ;
}
static struct V_7 * T_1 F_18 ( int V_2 ,
struct V_3 * V_4 )
{
return F_19 ( NULL , V_4 -> V_15 , & V_16 , V_4 ,
& V_4 -> V_17 ) ;
}
static int T_1 F_20 ( const struct V_18 * V_19 , T_3 V_20 ,
T_3 V_21 )
{
int V_22 ;
if ( V_19 -> V_8 -> V_10 == 0 && F_21 ( V_19 -> V_9 ) == 0 ) {
V_22 = V_23 ;
} else if ( V_19 -> V_8 -> V_10 == 0 && F_21 ( V_19 -> V_9 ) == 1 ) {
V_22 = V_24 ;
} else if ( V_19 -> V_8 -> V_10 == 0 && F_21 ( V_19 -> V_9 ) == 4 ) {
V_22 = - 1 ;
} else if ( V_19 -> V_8 -> V_10 == 1 && F_21 ( V_19 -> V_9 ) == 0 ) {
V_22 = V_23 ;
} else if ( V_19 -> V_8 -> V_10 == 1 && F_21 ( V_19 -> V_9 ) == 1 ) {
V_22 = V_24 ;
} else {
F_22 ( V_25 L_2
L_3 , V_19 -> V_8 -> V_10 ,
F_21 ( V_19 -> V_9 ) , F_23 ( V_19 -> V_9 ) ) ;
V_22 = - 1 ;
}
return V_22 ;
}
int T_1 F_24 ( void )
{
if ( F_25 () )
F_26 ( & V_26 ) ;
return 0 ;
}
static void T_1 F_27 ( void )
{
F_28 ( V_27 , F_6 ( V_27 ) ) ;
F_29 () ;
}
