static int F_1 ( unsigned long V_1 )
{
int V_2 = 0 , V_3 ;
V_3 = 16 ; if ( V_1 >> 16 == 0 ) V_3 = 0 ; V_2 += V_3 ; V_1 >>= V_3 ;
V_3 = 8 ; if ( V_1 >> 8 == 0 ) V_3 = 0 ; V_2 += V_3 ; V_1 >>= V_3 ;
V_3 = 4 ; if ( V_1 >> 4 == 0 ) V_3 = 0 ; V_2 += V_3 ; V_1 >>= V_3 ;
V_3 = 2 ; if ( V_1 >> 2 == 0 ) V_3 = 0 ; V_2 += V_3 ; V_1 >>= V_3 ;
V_3 = 1 ; if ( V_1 >> 1 == 0 ) V_3 = 0 ; V_2 += V_3 ;
return V_2 ;
}
static void F_2 ( void )
{
int V_4 , V_5 ;
T_1 V_6 , V_7 ;
T_2 V_8 = F_3 () ;
int V_9 =
( F_4 ( V_8 ) == 0 ) ? V_10 : V_11 ;
V_6 = F_5 ( V_12 ) ;
V_7 = F_5 ( V_9 ) ;
V_6 &= V_7 ;
if ( ! V_6 )
return;
V_5 = F_1 ( V_6 ) ;
#ifdef F_6
if ( V_6 & ( 1UL << V_13 ) ) {
F_7 ( V_13 ) ;
F_8 () ;
} else if ( V_6 & ( 1UL << V_14 ) ) {
F_7 ( V_14 ) ;
F_8 () ;
} else if ( V_6 & ( 1UL << V_15 ) ) {
F_7 ( V_15 ) ;
F_9 () ;
F_10 () ;
F_11 () ;
} else if ( V_6 & ( 1UL << V_16 ) ) {
F_7 ( V_16 ) ;
F_9 () ;
F_10 () ;
F_11 () ;
} else
#endif
{
struct V_17 * V_18 = V_19 [ V_8 ] . V_20 ;
V_4 = V_18 -> V_21 [ V_5 ] ;
F_12 ( V_4 ) ;
}
F_5 ( V_12 ) ;
}
static void F_13 ( void )
{
int V_4 , V_5 ;
T_1 V_22 , V_23 ;
T_2 V_8 = F_3 () ;
int V_24 = ( F_4 ( V_8 ) == 0 ) ? V_25 : V_26 ;
struct V_17 * V_18 = V_19 [ V_8 ] . V_20 ;
V_22 = F_5 ( V_27 ) ;
V_23 = F_5 ( V_24 ) ;
V_22 &= V_23 ;
if ( ! V_22 )
return;
V_5 = F_1 ( V_22 ) ;
V_4 = V_18 -> V_21 [ V_5 ] ;
F_7 ( V_5 ) ;
F_12 ( V_4 ) ;
F_5 ( V_27 ) ;
}
static void F_14 ( void )
{
F_15 ( L_1 , F_3 () ) ;
}
static void F_16 ( void )
{
F_15 ( L_2 , F_3 () ) ;
}
T_3 void F_17 ( void )
{
unsigned long V_28 = F_18 () & F_19 () ;
extern unsigned int V_29 ;
if ( V_28 & V_30 )
F_12 ( V_29 ) ;
else if ( V_28 & V_31 )
F_2 () ;
else if ( V_28 & V_32 )
F_13 () ;
else if ( V_28 & V_33 )
F_14 () ;
else if ( V_28 & V_34 )
F_16 () ;
}
void T_4 F_20 ( void )
{
}
void F_21 ( void )
{
int V_35 = F_5 ( V_36 ) ;
int V_8 = F_3 () ;
struct V_17 * V_18 = V_19 [ V_8 ] . V_20 ;
struct V_37 * V_38 = V_37 ( F_22 ( V_8 ) ) ;
int V_39 , V_40 ;
V_39 = V_13 + V_35 ;
F_23 ( V_39 , V_38 -> V_41 ) ;
F_23 ( V_39 , V_18 -> V_42 ) ;
F_7 ( V_39 ) ;
V_40 = V_15 + V_35 ;
F_23 ( V_40 , V_38 -> V_41 ) ;
F_23 ( V_40 , V_18 -> V_42 ) ;
F_7 ( V_40 ) ;
if ( V_35 == 0 ) {
F_24 ( V_10 , V_18 -> V_42 [ 0 ] ) ;
F_24 ( V_25 , V_18 -> V_42 [ 1 ] ) ;
} else {
F_24 ( V_11 , V_18 -> V_42 [ 0 ] ) ;
F_24 ( V_26 , V_18 -> V_42 [ 1 ] ) ;
}
}
