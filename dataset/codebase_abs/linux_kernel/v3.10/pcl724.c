static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
unsigned long V_5 = V_4 ;
if ( V_1 ) {
F_2 ( V_3 , V_5 + V_2 ) ;
return 0 ;
} else {
return F_3 ( V_5 + V_2 ) ;
}
}
static int F_4 ( int V_1 , int V_2 , int V_3 ,
unsigned long V_5 )
{
int V_6 = V_7 * ( V_5 >> 12 ) ;
V_5 &= 0x0fff ;
if ( V_1 ) {
F_2 ( V_2 + V_6 , V_5 ) ;
F_2 ( V_3 , V_5 + 1 ) ;
return 0 ;
} else {
F_2 ( V_2 + V_6 , V_5 ) ;
return F_3 ( V_5 + 1 ) ;
}
}
static int F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
const struct V_12 * V_13 = F_6 ( V_9 ) ;
struct V_14 * V_15 ;
unsigned int V_16 ;
int V_17 , V_18 , V_19 ;
#ifdef F_7
unsigned int V_20 ;
#endif
V_16 = V_13 -> V_21 ;
if ( ( V_13 -> V_22 ) &&
( ( V_11 -> V_23 [ 1 ] == 1 ) || ( V_11 -> V_23 [ 1 ] == 96 ) ) )
V_16 = V_24 ;
V_17 = F_8 ( V_9 , V_11 -> V_23 [ 0 ] , V_16 ) ;
if ( V_17 )
return V_17 ;
#ifdef F_7
V_20 = 0 ;
if ( V_13 -> V_25 != 0 ) {
V_20 = V_11 -> V_23 [ 1 ] ;
if ( V_20 ) {
if ( ( ( 1 << V_20 ) & V_13 -> V_25 ) == 0 ) {
F_9 ( V_26
L_1
L_2 , V_20 ) ;
V_20 = 0 ;
} else {
if ( F_10 ( V_20 , V_27 , 0 ,
V_9 -> V_28 , V_9 ) ) {
F_9 ( V_26
L_3
L_2 , V_20 ) ;
V_20 = 0 ;
} else {
F_9 ( L_4 , V_20 ) ;
}
}
}
}
V_9 -> V_20 = V_20 ;
#endif
F_9 ( L_5 ) ;
V_19 = V_13 -> V_29 ;
if ( ( V_13 -> V_22 ) && ( ( V_11 -> V_23 [ 1 ] == 1 )
|| ( V_11 -> V_23 [ 1 ] == 96 ) ) )
V_19 = 4 ;
V_17 = F_11 ( V_9 , V_19 ) ;
if ( V_17 )
return V_17 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_15 = & V_9 -> V_30 [ V_18 ] ;
if ( V_13 -> V_31 ) {
F_12 ( V_9 , V_15 , F_4 ,
( unsigned long ) ( V_9 -> V_5 +
V_18 * 0x1000 ) ) ;
} else
F_12 ( V_9 , V_15 , F_1 ,
( unsigned long ) ( V_9 -> V_5 +
V_7 * V_18 ) ) ;
}
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ )
F_14 ( V_9 , V_18 ) ;
F_15 ( V_9 ) ;
}
