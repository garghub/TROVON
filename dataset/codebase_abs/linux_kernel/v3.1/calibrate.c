static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static unsigned long T_2 F_3 ( void )
{
unsigned long V_3 , V_4 , V_5 ;
unsigned long V_6 , V_7 , V_8 ;
unsigned long V_9 ;
unsigned long V_10 , V_11 ;
unsigned long V_12 = 0 ;
unsigned long V_13 = 0 ;
unsigned long V_14 [ V_15 ] ;
int V_16 = - 1 ;
int V_17 = - 1 ;
int V_18 ;
if ( F_4 ( & V_3 ) < 0 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_3 = 0 ;
F_4 ( & V_4 ) ;
V_9 = V_19 ;
while ( F_5 ( V_19 , V_9 + 1 ) ) {
V_3 = V_4 ;
F_4 ( & V_4 ) ;
}
F_4 ( & V_5 ) ;
V_6 = 0 ;
V_7 = V_5 ;
while ( F_5 ( V_19 , V_9 + 1 +
V_20 ) ) {
V_6 = V_7 ;
F_4 ( & V_7 ) ;
}
F_4 ( & V_8 ) ;
V_11 = ( V_8 - V_3 ) /
V_20 ;
V_10 = ( V_6 - V_5 ) /
V_20 ;
if ( V_4 >= V_8 )
F_6 ( V_21 L_1
L_2
L_3 ,
V_4 , V_8 ) ;
if ( V_4 < V_8 && V_3 != 0 && V_6 != 0 &&
( V_11 - V_10 ) < ( V_11 >> 3 ) ) {
V_13 ++ ;
V_12 += V_11 ;
V_14 [ V_18 ] = V_11 ;
if ( V_16 < 0 || V_11 > V_14 [ V_16 ] )
V_16 = V_18 ;
if ( V_17 < 0 || V_11 < V_14 [ V_17 ] )
V_17 = V_18 ;
} else
V_14 [ V_18 ] = 0 ;
}
while ( V_13 > 1 ) {
unsigned long V_22 ;
unsigned long V_23 ;
V_22 = ( V_12 / V_13 ) ;
V_23 = V_22 >> 3 ;
if ( ( V_14 [ V_16 ] - V_14 [ V_17 ] ) < V_23 )
return V_22 ;
V_12 = 0 ;
V_13 = 0 ;
if ( ( V_14 [ V_16 ] - V_22 ) <
( V_22 - V_14 [ V_17 ] ) ) {
F_6 ( V_21 L_4
L_5 ,
V_17 , V_14 [ V_17 ] ) ;
V_14 [ V_17 ] = 0 ;
V_17 = V_16 ;
} else {
F_6 ( V_21 L_4
L_6 ,
V_16 , V_14 [ V_16 ] ) ;
V_14 [ V_16 ] = 0 ;
V_16 = V_17 ;
}
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
if ( V_14 [ V_18 ] == 0 )
continue;
V_13 ++ ;
V_12 += V_14 [ V_18 ] ;
if ( V_14 [ V_18 ] < V_14 [ V_17 ] )
V_17 = V_18 ;
if ( V_14 [ V_18 ] > V_14 [ V_16 ] )
V_16 = V_18 ;
}
}
F_6 ( V_21 L_7
L_8
L_9 ) ;
return 0 ;
}
static unsigned long T_2 F_3 ( void ) { return 0 ; }
static unsigned long T_2 F_7 ( void )
{
unsigned long V_24 , V_25 , V_26 , V_27 , V_28 , V_29 ;
int V_30 = 0 , V_31 = 0 , V_32 = 0 ;
V_24 = ( 1 << 12 ) ;
V_26 = V_19 ;
while ( V_26 == V_19 )
;
V_26 = V_19 ;
do {
if ( ++ V_32 == ( 1 << V_31 ) ) {
++ V_31 ;
V_32 = 0 ;
}
F_8 ( V_24 * V_31 ) ;
V_30 += V_31 ;
} while ( V_26 == V_19 );
V_30 -= V_31 ;
V_28 = V_24 * V_31 ;
V_25 = V_24 * V_30 ;
V_33:
V_24 = V_25 ;
V_27 = V_28 ;
V_29 = V_24 >> V_34 ;
while ( V_27 > V_29 ) {
V_24 += V_27 ;
V_26 = V_19 ;
while ( V_26 == V_19 )
;
V_26 = V_19 ;
F_8 ( V_24 ) ;
if ( V_19 != V_26 )
V_24 -= V_27 ;
V_27 >>= 1 ;
}
if ( V_24 + V_27 * 2 == V_25 + V_28 * 2 ) {
V_25 = V_24 ;
V_28 <<= 2 ;
goto V_33;
}
return V_24 ;
}
void T_2 F_9 ( void )
{
unsigned long V_24 ;
static bool V_35 ;
int V_36 = F_10 () ;
if ( F_11 ( V_37 , V_36 ) ) {
V_24 = F_11 ( V_37 , V_36 ) ;
F_12 ( L_10
L_11 ) ;
} else if ( V_2 ) {
V_24 = V_2 ;
if ( ! V_35 )
F_12 ( L_10
L_12 ) ;
} else if ( ( ! V_35 ) && V_38 ) {
V_24 = V_38 ;
F_12 ( L_13
L_14 ) ;
} else if ( ( V_24 = F_3 () ) != 0 ) {
if ( ! V_35 )
F_12 ( L_15
L_16 ) ;
} else {
if ( ! V_35 )
F_12 ( L_17 ) ;
V_24 = F_7 () ;
}
F_11 ( V_37 , V_36 ) = V_24 ;
if ( ! V_35 )
F_13 ( L_18 ,
V_24 / ( 500000 / V_39 ) ,
( V_24 / ( 5000 / V_39 ) ) % 100 , V_24 ) ;
V_40 = V_24 ;
V_35 = true ;
}
