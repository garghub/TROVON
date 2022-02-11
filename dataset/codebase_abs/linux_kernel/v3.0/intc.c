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
int V_4 ;
V_4 = F_9 ( V_5 + V_11 ) ;
F_2 ( L_5 , V_4 ) ;
return V_4 ;
}
void T_1 F_10 ( void )
{
T_2 V_12 , V_13 , V_14 ;
struct V_15 * V_16 = NULL ;
#ifdef F_11
unsigned int V_17 = 0 ;
static int V_18 [] = {
( int ) & F_8 ,
( int ) & F_1 ,
( int ) & F_5 ,
( int ) & F_7 ,
( int ) & F_6 ,
( int ) & V_19 ,
0
} ;
#endif
const char * const V_20 [] = {
L_6 ,
NULL
} ;
for ( V_13 = 0 ; V_20 [ V_13 ] != NULL ; V_13 ++ ) {
V_16 = F_12 ( NULL , NULL , V_20 [ V_13 ] ) ;
if ( V_16 )
break;
}
F_13 ( ! V_16 ) ;
V_17 = F_14 ( F_15 ( V_16 ,
L_7 , NULL ) ) ;
V_17 = ( unsigned long ) F_16 ( V_17 , V_21 ) ;
V_22 = F_14 ( F_15 ( V_16 ,
L_8 , NULL ) ) ;
V_14 =
F_14 ( F_15 ( V_16 ,
L_9 , NULL ) ) ;
if ( V_14 >= ( 1 << ( V_22 + 1 ) ) )
F_17 ( V_23 L_10 ) ;
#ifdef F_11
F_18 ( ( int * ) V_18 , V_17 ) ;
#endif
F_17 ( V_23 L_11 ,
V_20 [ V_13 ] , V_17 , V_22 , V_14 ) ;
F_3 ( V_17 + V_24 , 0 ) ;
F_3 ( V_17 + V_7 , 0xffffffff ) ;
F_3 ( V_17 + V_25 , V_26 | V_27 ) ;
for ( V_12 = 0 ; V_12 < V_22 ; ++ V_12 ) {
if ( V_14 & ( 0x00000001 << V_12 ) ) {
F_19 ( V_12 , & V_28 ,
V_29 , L_12 ) ;
F_20 ( V_12 , V_30 ) ;
} else {
F_19 ( V_12 , & V_28 ,
V_31 , L_13 ) ;
F_21 ( V_12 , V_30 ) ;
}
}
}
