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
unsigned long V_5 ;
unsigned int V_12 ;
int V_13 , V_14 , V_15 ;
#ifdef F_6
unsigned int V_16 ;
#endif
V_5 = V_11 -> V_17 [ 0 ] ;
V_12 = V_18 -> V_19 ;
if ( ( V_18 -> V_20 ) && ( ( V_11 -> V_17 [ 1 ] == 1 )
|| ( V_11 -> V_17 [ 1 ] == 96 ) ) )
V_12 = V_21 ;
F_7 ( V_22 L_1 , V_9 -> V_23 ,
V_18 -> V_24 , V_5 ) ;
if ( ! F_8 ( V_5 , V_12 , L_2 ) ) {
F_7 ( L_3 ) ;
return - V_25 ;
}
V_9 -> V_5 = V_5 ;
V_9 -> V_26 = V_18 -> V_24 ;
#ifdef F_6
V_16 = 0 ;
if ( V_18 -> V_27 != 0 ) {
V_16 = V_11 -> V_17 [ 1 ] ;
if ( V_16 ) {
if ( ( ( 1 << V_16 ) & V_18 -> V_27 ) == 0 ) {
F_7 ( V_28
L_4
L_5 , V_16 ) ;
V_16 = 0 ;
} else {
if ( F_9
( V_16 , V_29 , 0 , L_2 , V_9 ) ) {
F_7 ( V_28
L_6
L_5 , V_16 ) ;
V_16 = 0 ;
} else {
F_7 ( L_7 , V_16 ) ;
}
}
}
}
V_9 -> V_16 = V_16 ;
#endif
F_7 ( L_8 ) ;
V_15 = V_18 -> V_30 ;
if ( ( V_18 -> V_20 ) && ( ( V_11 -> V_17 [ 1 ] == 1 )
|| ( V_11 -> V_17 [ 1 ] == 96 ) ) )
V_15 = 4 ;
V_13 = F_10 ( V_9 , V_15 ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_15 ; V_14 ++ ) {
if ( V_18 -> V_31 ) {
F_11 ( V_9 , V_9 -> V_32 + V_14 ,
F_4 ,
( unsigned long ) ( V_9 -> V_5 +
V_14 * 0x1000 ) ) ;
} else
F_11 ( V_9 , V_9 -> V_32 + V_14 ,
F_1 ,
( unsigned long ) ( V_9 -> V_5 +
V_7 * V_14 ) ) ;
}
return 0 ;
}
static void F_12 ( struct V_8 * V_9 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_15 ; V_14 ++ )
F_13 ( V_9 , V_9 -> V_32 + V_14 ) ;
#ifdef F_6
if ( V_9 -> V_16 )
F_14 ( V_9 -> V_16 , V_9 ) ;
#endif
F_15 ( V_9 -> V_5 , V_18 -> V_19 ) ;
}
