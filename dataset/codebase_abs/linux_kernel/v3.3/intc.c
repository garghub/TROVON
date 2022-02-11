static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1 << V_2 -> V_4 ;
F_2 ( L_1 , V_2 -> V_4 ) ;
F_3 ( V_5 + V_6 , V_3 ) ;
if ( F_4 ( V_2 ) )
F_3 ( V_5 + V_7 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( L_2 , V_2 -> V_4 ) ;
F_3 ( V_5 + V_8 , 1 << V_2 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( L_3 , V_2 -> V_4 ) ;
F_3 ( V_5 + V_7 , 1 << V_2 -> V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1 << V_2 -> V_4 ;
F_2 ( L_4 , V_2 -> V_4 ) ;
F_3 ( V_5 + V_8 , V_3 ) ;
F_3 ( V_5 + V_7 , V_3 ) ;
}
unsigned int F_8 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_9 ( V_5 + V_12 ) + V_13 ;
F_2 ( L_5 , V_11 ) ;
return V_11 ;
}
void T_1 F_10 ( void )
{
T_2 V_14 , V_15 ;
struct V_16 * V_17 = NULL ;
#ifdef F_11
unsigned int V_18 = 0 ;
static int V_19 [] = {
( int ) & F_8 ,
( int ) & F_1 ,
( int ) & F_5 ,
( int ) & F_7 ,
( int ) & F_6 ,
( int ) & V_20 ,
0
} ;
#endif
V_17 = F_12 ( NULL , NULL , L_6 ) ;
F_13 ( ! V_17 ) ;
V_18 = F_14 ( F_15 ( V_17 , L_7 , NULL ) ) ;
V_18 = ( unsigned long ) F_16 ( V_18 , V_21 ) ;
V_22 = F_14 ( F_15 ( V_17 ,
L_8 , NULL ) ) ;
V_15 =
F_14 ( F_15 ( V_17 , L_9 , NULL ) ) ;
if ( V_15 > ( T_2 ) ( ( 1ULL << V_22 ) - 1 ) )
F_17 ( V_23 L_10 ) ;
#ifdef F_11
F_18 ( ( int * ) V_19 , V_18 ) ;
#endif
F_17 ( V_23 L_11 ,
V_18 , V_22 , V_15 ) ;
F_3 ( V_18 + V_24 , 0 ) ;
F_3 ( V_18 + V_7 , 0xffffffff ) ;
F_3 ( V_18 + V_25 , V_26 | V_27 ) ;
for ( V_14 = V_28 ; V_14 < ( V_22 + V_28 ) ; ++ V_14 ) {
if ( V_15 & ( 0x00000001 << ( V_14 - V_28 ) ) ) {
F_19 ( V_14 , & V_29 ,
V_30 , L_12 ) ;
F_20 ( V_14 , V_31 ) ;
} else {
F_19 ( V_14 , & V_29 ,
V_32 , L_13 ) ;
F_21 ( V_14 , V_31 ) ;
}
F_22 ( V_14 ) -> V_4 = V_14 - V_28 ;
}
}
