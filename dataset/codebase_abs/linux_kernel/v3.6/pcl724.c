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
unsigned long V_5 ;
unsigned int V_14 ;
int V_15 , V_16 , V_17 ;
#ifdef F_7
unsigned int V_18 ;
#endif
V_5 = V_11 -> V_19 [ 0 ] ;
V_14 = V_13 -> V_20 ;
if ( ( V_13 -> V_21 ) && ( ( V_11 -> V_19 [ 1 ] == 1 )
|| ( V_11 -> V_19 [ 1 ] == 96 ) ) )
V_14 = V_22 ;
F_8 ( V_23 L_1 , V_9 -> V_24 ,
V_13 -> V_25 , V_5 ) ;
if ( ! F_9 ( V_5 , V_14 , L_2 ) ) {
F_8 ( L_3 ) ;
return - V_26 ;
}
V_9 -> V_5 = V_5 ;
V_9 -> V_27 = V_13 -> V_25 ;
#ifdef F_7
V_18 = 0 ;
if ( V_13 -> V_28 != 0 ) {
V_18 = V_11 -> V_19 [ 1 ] ;
if ( V_18 ) {
if ( ( ( 1 << V_18 ) & V_13 -> V_28 ) == 0 ) {
F_8 ( V_29
L_4
L_5 , V_18 ) ;
V_18 = 0 ;
} else {
if ( F_10
( V_18 , V_30 , 0 , L_2 , V_9 ) ) {
F_8 ( V_29
L_6
L_5 , V_18 ) ;
V_18 = 0 ;
} else {
F_8 ( L_7 , V_18 ) ;
}
}
}
}
V_9 -> V_18 = V_18 ;
#endif
F_8 ( L_8 ) ;
V_17 = V_13 -> V_31 ;
if ( ( V_13 -> V_21 ) && ( ( V_11 -> V_19 [ 1 ] == 1 )
|| ( V_11 -> V_19 [ 1 ] == 96 ) ) )
V_17 = 4 ;
V_15 = F_11 ( V_9 , V_17 ) ;
if ( V_15 )
return V_15 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_17 ; V_16 ++ ) {
if ( V_13 -> V_32 ) {
F_12 ( V_9 , V_9 -> V_33 + V_16 ,
F_4 ,
( unsigned long ) ( V_9 -> V_5 +
V_16 * 0x1000 ) ) ;
} else
F_12 ( V_9 , V_9 -> V_33 + V_16 ,
F_1 ,
( unsigned long ) ( V_9 -> V_5 +
V_7 * V_16 ) ) ;
}
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
const struct V_12 * V_13 = F_6 ( V_9 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_17 ; V_16 ++ )
F_14 ( V_9 , V_9 -> V_33 + V_16 ) ;
#ifdef F_7
if ( V_9 -> V_18 )
F_15 ( V_9 -> V_18 , V_9 ) ;
#endif
F_16 ( V_9 -> V_5 , V_13 -> V_20 ) ;
}
