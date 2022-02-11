static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( int V_2 , int V_3 , int V_4 , unsigned long V_5 )
{
unsigned long V_6 = V_5 ;
if ( V_2 ) {
F_6 ( V_4 , V_6 + V_3 ) ;
return 0 ;
} else {
return F_7 ( V_6 + V_3 ) ;
}
}
static int F_8 ( int V_2 , int V_3 , int V_4 ,
unsigned long V_6 )
{
int V_7 = V_8 * ( V_6 >> 12 ) ;
V_6 &= 0x0fff ;
if ( V_2 ) {
F_6 ( V_3 + V_7 , V_6 ) ;
F_6 ( V_4 , V_6 + 1 ) ;
return 0 ;
} else {
F_6 ( V_3 + V_7 , V_6 ) ;
return F_7 ( V_6 + 1 ) ;
}
}
static int F_9 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
unsigned long V_6 ;
unsigned int V_13 ;
int V_14 , V_15 , V_16 ;
#ifdef F_10
unsigned int V_17 ;
#endif
V_6 = V_12 -> V_18 [ 0 ] ;
V_13 = V_19 -> V_20 ;
if ( ( V_19 -> V_21 ) && ( ( V_12 -> V_18 [ 1 ] == 1 )
|| ( V_12 -> V_18 [ 1 ] == 96 ) ) )
V_13 = V_22 ;
F_11 ( V_23 L_1 , V_10 -> V_24 ,
V_19 -> V_25 , V_6 ) ;
if ( ! F_12 ( V_6 , V_13 , L_2 ) ) {
F_11 ( L_3 ) ;
return - V_26 ;
}
V_10 -> V_6 = V_6 ;
V_10 -> V_27 = V_19 -> V_25 ;
#ifdef F_10
V_17 = 0 ;
if ( V_19 -> V_28 != 0 ) {
V_17 = V_12 -> V_18 [ 1 ] ;
if ( V_17 ) {
if ( ( ( 1 << V_17 ) & V_19 -> V_28 ) == 0 ) {
F_11 ( V_29
L_4
L_5 , V_17 ) ;
V_17 = 0 ;
} else {
if ( F_13
( V_17 , V_30 , 0 , L_2 , V_10 ) ) {
F_11 ( V_29
L_6
L_5 , V_17 ) ;
V_17 = 0 ;
} else {
F_11 ( L_7 , V_17 ) ;
}
}
}
}
V_10 -> V_17 = V_17 ;
#endif
F_11 ( L_8 ) ;
V_16 = V_19 -> V_31 ;
if ( ( V_19 -> V_21 ) && ( ( V_12 -> V_18 [ 1 ] == 1 )
|| ( V_12 -> V_18 [ 1 ] == 96 ) ) )
V_16 = 4 ;
V_14 = F_14 ( V_10 , V_16 ) ;
if ( V_14 < 0 )
return V_14 ;
for ( V_15 = 0 ; V_15 < V_10 -> V_16 ; V_15 ++ ) {
if ( V_19 -> V_32 ) {
F_15 ( V_10 , V_10 -> V_33 + V_15 ,
F_8 ,
( unsigned long ) ( V_10 -> V_6 +
V_15 * 0x1000 ) ) ;
} else
F_15 ( V_10 , V_10 -> V_33 + V_15 ,
F_5 ,
( unsigned long ) ( V_10 -> V_6 +
V_8 * V_15 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_10 -> V_16 ; V_15 ++ )
F_17 ( V_10 , V_10 -> V_33 + V_15 ) ;
#ifdef F_10
if ( V_10 -> V_17 )
F_18 ( V_10 -> V_17 , V_10 ) ;
#endif
F_19 ( V_10 -> V_6 , V_19 -> V_20 ) ;
return 0 ;
}
