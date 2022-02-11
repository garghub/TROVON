static T_1 * T_2 F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( V_2 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
return V_1 ;
}
static T_3 * T_2 F_7 ( void )
{
if ( ! V_3 ) {
unsigned long V_4 , V_5 ;
int V_6 ;
V_5 = ( unsigned long ) V_7 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
if ( ! F_8 ( V_7 [ V_6 ] ) )
continue;
V_4 = F_9 ( V_7 [ V_6 ] ) ;
if ( V_4 > V_5 )
V_5 = V_4 ;
}
V_3 = ( T_3 * ) V_5 ;
#ifdef F_10
F_11 ( L_1 , V_3 ) ;
#endif
}
V_3 += V_9 ;
if ( ( ( unsigned long ) V_3 & ~ V_10 ) == 0 ) {
V_3 = ( T_3 * ) F_2 ( V_2 ) ;
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
}
return V_3 ;
}
static void T_2 F_12 ( int V_11 )
{
#define F_13 (256*1024)
#define F_14 (32*1024*1024)
unsigned long V_12 , V_13 , V_14 ;
T_4 * V_15 ;
T_3 * V_16 ;
T_1 * V_17 ;
V_14 = V_18 [ V_11 ] . V_14 ;
V_12 = V_18 [ V_11 ] . V_19 ;
V_13 = ( unsigned long ) F_15 ( V_12 ) ;
V_12 |= V_20 |
V_21 | V_22 | V_23 ;
if ( V_24 )
V_12 |= V_25 ;
while ( V_14 > 0 ) {
#ifdef F_10
if ( ! ( V_13 & ( F_13 - 1 ) ) )
F_11 ( L_2 , V_12 & V_10 ,
V_13 ) ;
#endif
V_15 = F_16 ( V_13 ) ;
if ( V_13 && V_26 ) {
if ( ! ( V_13 & ( F_14 - 1 ) ) &&
V_14 >= F_14 ) {
#ifdef F_10
F_11 ( L_3 ) ;
#endif
F_17 ( * V_15 ) = V_12 ;
V_14 -= F_14 ;
V_13 += F_14 ;
V_12 += F_14 ;
continue;
}
}
if ( ! F_8 ( * V_15 ) ) {
V_16 = F_7 () ;
#ifdef F_10
F_11 ( L_4 , V_16 ) ;
#endif
F_18 ( V_15 , V_16 ) ;
} else
V_16 = F_19 ( V_15 , V_13 ) ;
if ( V_26 ) {
if ( V_13 ) {
#ifdef F_10
F_11 ( L_5 ) ;
#endif
V_16 -> V_4 [ ( V_13 / F_13 ) & 15 ] = V_12 ;
V_12 += F_13 ;
} else {
int V_6 ;
#ifdef F_10
F_11 ( L_6 ) ;
#endif
V_27 = F_7 () ;
V_17 = ( T_1 * ) V_27 ;
V_16 -> V_4 [ 0 ] = F_20 ( V_17 ) |
V_28 | V_22 ;
F_21 ( * V_17 ++ ) = 0 ;
V_12 += V_2 ;
for ( V_6 = 1 ; V_6 < 64 ; V_12 += V_2 , V_6 ++ )
F_21 ( * V_17 ++ ) = V_12 ;
}
V_14 -= F_13 ;
V_13 += F_13 ;
} else {
if ( ! F_22 ( * V_16 ) ) {
#ifdef F_10
F_11 ( L_7 ) ;
#endif
V_17 = F_1 () ;
F_23 ( V_16 , V_17 ) ;
}
V_17 = F_24 ( V_16 , V_13 ) ;
if ( V_13 ) {
if ( ! F_25 ( * V_17 ) )
F_21 ( * V_17 ) = V_12 ;
} else
F_21 ( * V_17 ) = 0 ;
V_14 -= V_2 ;
V_13 += V_2 ;
V_12 += V_2 ;
}
}
#ifdef F_10
F_11 ( L_8 ) ;
#endif
}
void T_2 F_26 ( void )
{
unsigned long V_29 [ V_30 ] = { 0 , } ;
unsigned long V_31 , V_32 ;
unsigned long V_19 , V_14 , V_33 ;
int V_6 ;
#ifdef F_10
F_11 ( L_9 , V_7 , V_34 ) ;
#endif
if ( V_24 ) {
int V_6 ;
#ifndef F_27
F_27 = V_35 ;
#endif
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ )
F_28 ( V_36 [ V_6 ] ) |= V_35 ;
}
V_31 = V_18 [ 0 ] . V_19 ;
V_32 = V_31 + V_18 [ 0 ] . V_14 ;
for ( V_6 = 1 ; V_6 < V_37 ; ) {
if ( V_18 [ V_6 ] . V_19 < V_31 ) {
F_11 ( L_10 ,
V_18 [ V_6 ] . V_19 , V_18 [ V_6 ] . V_14 ) ;
F_11 ( L_11 ) ;
V_37 -- ;
memmove ( V_18 + V_6 , V_18 + V_6 + 1 ,
( V_37 - V_6 ) * sizeof( struct V_38 ) ) ;
continue;
}
V_19 = V_18 [ V_6 ] . V_19 + V_18 [ V_6 ] . V_14 ;
if ( V_19 > V_32 )
V_32 = V_19 ;
V_6 ++ ;
}
V_39 = V_31 - V_40 ;
V_41 = F_29 ( V_32 - V_31 - 1 ) - 6 ;
F_30 ( NULL , V_42 , V_43 ) ;
F_31 () ;
V_44 = F_15 ( V_32 ) ;
V_45 = V_34 >> V_46 ;
V_47 = V_48 = V_32 >> V_46 ;
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ ) {
V_19 = V_18 [ V_6 ] . V_19 ;
V_33 = V_19 + V_18 [ V_6 ] . V_14 ;
F_32 ( V_6 ) ;
V_34 = F_33 ( V_34 ) ;
V_34 += F_34 ( F_35 ( V_6 ) ,
V_34 >> V_46 ,
V_19 >> V_46 ,
V_33 >> V_46 ) ;
}
V_19 = V_18 [ 0 ] . V_19 ;
V_14 = V_18 [ 0 ] . V_14 ;
F_36 ( F_35 ( 0 ) , V_34 ,
F_37 ( V_49 , V_14 ) - ( V_34 - V_19 ) ) ;
F_12 ( 0 ) ;
if ( V_14 > V_49 )
F_36 ( F_35 ( 0 ) , V_19 + V_49 ,
V_14 - V_49 ) ;
for ( V_6 = 1 ; V_6 < V_37 ; V_6 ++ )
F_12 ( V_6 ) ;
F_38 () ;
V_50 = F_39 ( V_2 ) ;
F_40 ( V_51 ) ;
#ifdef F_10
F_11 ( L_12 ) ;
#endif
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ ) {
V_29 [ V_52 ] = V_18 [ V_6 ] . V_14 >> V_46 ;
F_41 ( V_6 , V_29 ,
V_18 [ V_6 ] . V_19 >> V_46 , NULL ) ;
if ( F_42 ( V_6 ) )
F_43 ( V_6 , V_53 ) ;
}
}
