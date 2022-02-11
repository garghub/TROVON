unsigned long F_1 ( void )
{
int V_1 ;
int V_2 = 0 ;
for ( V_1 = 0 ; V_3 [ V_1 ] . V_4 != 0 ; V_1 ++ ) {
unsigned long V_5 = V_3 [ V_1 ] . V_6 >> V_7 ;
unsigned long V_8 = ( V_3 [ V_1 ] . V_6 + V_3 [ V_1 ] . V_4 ) >> V_7 ;
if ( V_8 <= V_9 )
continue;
if ( V_5 < V_9 )
V_5 = V_9 ;
V_2 += V_8 - V_5 ;
}
return V_2 ;
}
static unsigned long F_2 ( void )
{
int V_1 ;
unsigned long V_10 = V_11 + ( V_12 >> V_7 ) ;
unsigned long V_13 , V_14 ;
V_14 = ( V_3 [ 0 ] . V_6 + V_3 [ 0 ] . V_4 ) >> V_7 ;
for ( V_1 = 1 ; V_3 [ V_1 ] . V_4 != 0 ; V_1 ++ ) {
V_13 = V_3 [ V_1 ] . V_6 >> V_7 ;
if ( V_13 >= V_10 ) {
if ( V_14 < V_10 )
V_10 = V_14 ;
break;
}
V_14 = ( V_3 [ V_1 ] . V_6 + V_3 [ V_1 ] . V_4 ) >> V_7 ;
}
return V_10 ;
}
unsigned long T_1 F_3 ( unsigned long * V_15 )
{
unsigned long V_16 , V_5 ;
unsigned long V_17 = 0UL ;
unsigned long V_18 , V_19 , V_20 ;
int V_1 ;
V_19 = 0UL ;
for ( V_1 = 0 ; V_3 [ V_1 ] . V_4 != 0 ; V_1 ++ ) {
V_17 = V_3 [ V_1 ] . V_6 +
V_3 [ V_1 ] . V_4 ;
V_19 += V_3 [ V_1 ] . V_4 ;
if ( V_21 ) {
if ( V_19 > V_21 ) {
unsigned long V_22 = V_19 - V_21 ;
V_19 -= V_22 ;
V_17 -= V_22 ;
V_3 [ V_1 ] . V_4 -= V_22 ;
if ( V_3 [ V_1 ] . V_4 == 0 ) {
V_3 [ V_1 ] . V_6 = 0xdeadbeef ;
} else {
V_3 [ V_1 + 1 ] . V_4 = 0 ;
V_3 [ V_1 + 1 ] . V_6 = 0xdeadbeef ;
}
break;
}
}
}
V_5 = ( unsigned long ) F_4 ( F_5 ( ( unsigned long ) & V_23 ) ) ;
V_5 >>= V_7 ;
V_18 = V_5 ;
V_24 = V_17 >> V_7 ;
V_9 = V_24 ;
V_25 = V_26 = V_24 ;
if ( V_9 > V_11 + ( V_12 >> V_7 ) ) {
V_25 = V_11 + ( V_12 >> V_7 ) ;
V_9 = F_2 () ;
F_6 ( V_27 L_1 ,
F_1 () >> ( 20 - V_7 ) ) ;
}
#ifdef F_7
if ( V_28 ) {
if ( V_28 >= ( unsigned long ) & V_23 - 2 * V_29 )
V_28 -= V_30 ;
V_31 = V_28 + V_32 ;
V_33 = V_31 + V_34 ;
if ( V_33 > V_17 ) {
F_6 ( V_35 L_2
L_3 ,
V_33 , V_17 ) ;
V_31 = 0 ;
}
if ( V_31 ) {
if ( V_31 >= ( V_5 << V_7 ) &&
V_31 < ( V_5 << V_7 ) + 2 * V_29 )
V_18 = F_5 ( V_33 ) >> V_7 ;
}
}
#endif
V_16 = F_8 ( F_9 ( 0 ) , V_18 , V_11 ,
V_9 ) ;
* V_15 = 0 ;
for ( V_1 = 0 ; V_3 [ V_1 ] . V_4 != 0 ; V_1 ++ ) {
unsigned long V_13 , V_14 ;
V_13 = V_3 [ V_1 ] . V_6 >> V_7 ;
if ( V_13 >= V_9 )
break;
V_14 = ( V_3 [ V_1 ] . V_6 + V_3 [ V_1 ] . V_4 ) >> V_7 ;
if ( V_14 > V_9 )
V_14 = V_9 ;
if ( V_14 <= V_13 )
continue;
V_20 = ( V_14 - V_13 ) << V_7 ;
* V_15 += V_14 - V_13 ;
F_10 ( V_3 [ V_1 ] . V_6 , V_20 ) ;
}
#ifdef F_7
if ( V_31 ) {
V_20 = V_33 - V_31 ;
F_11 ( V_31 , V_20 , V_36 ) ;
* V_15 -= F_5 ( V_20 ) >> V_7 ;
V_31 = ( V_31 - V_32 ) + V_37 ;
V_33 = ( V_33 - V_32 ) + V_37 ;
}
#endif
V_20 = ( V_5 << V_7 ) - V_32 ;
F_11 ( V_32 , V_20 , V_36 ) ;
* V_15 -= F_5 ( V_20 ) >> V_7 ;
V_20 = V_16 ;
F_11 ( ( V_18 << V_7 ) , V_20 , V_36 ) ;
* V_15 -= F_5 ( V_20 ) >> V_7 ;
return V_24 ;
}
void T_1 F_12 ( void )
{
F_13 () ;
F_14 () ;
F_15 () ;
F_16 () ;
}
static void T_1 F_17 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_3 [ V_1 ] . V_4 ; V_1 ++ ) {
unsigned long V_38 , V_39 ;
V_38 = V_3 [ V_1 ] . V_6 ;
V_39 = V_38 + V_3 [ V_1 ] . V_4 ;
while ( V_38 < V_39 ) {
F_18 ( V_38 >> 20 , V_40 ) ;
V_38 += V_29 ;
}
}
}
static void F_19 ( unsigned long V_5 , unsigned long V_8 )
{
unsigned long V_10 ;
#ifdef F_20
F_6 ( L_4 , V_5 , V_8 ) ;
#endif
for ( V_10 = V_5 ; V_10 < V_8 ; V_10 ++ )
F_21 ( F_22 ( V_10 ) ) ;
}
void T_1 F_23 ( void )
{
int V_1 ;
if ( V_41 + V_42 * V_29 >= V_43 ) {
F_24 ( L_5 ) ;
F_24 ( L_6 ,
V_41 ,
( unsigned long ) V_41 + V_42 * V_29 ,
V_43 ) ;
F_24 ( L_7 ) ;
F_25 () ;
}
memset ( ( void * ) V_44 , 0 , V_29 ) ;
V_1 = V_45 >> ( ( 20 - V_7 ) + 5 ) ;
V_1 += 1 ;
V_40 = ( unsigned long * )
F_26 ( V_1 << 2 , V_46 , 0UL ) ;
if ( V_40 == NULL ) {
F_24 ( L_8 ) ;
F_25 () ;
}
memset ( V_40 , 0 , V_1 << 2 ) ;
F_17 () ;
V_47 = V_45 - V_11 ;
V_48 = F_27 ( V_9 << V_7 ) ;
F_28 () ;
for ( V_1 = 0 ; V_3 [ V_1 ] . V_4 != 0 ; V_1 ++ ) {
unsigned long V_5 = V_3 [ V_1 ] . V_6 >> V_7 ;
unsigned long V_8 = ( V_3 [ V_1 ] . V_6 + V_3 [ V_1 ] . V_4 ) >> V_7 ;
if ( V_8 <= V_25 )
continue;
if ( V_5 < V_25 )
V_5 = V_25 ;
F_19 ( V_5 , V_8 ) ;
}
F_29 ( NULL ) ;
}
void F_30 ( void )
{
F_31 ( V_49 ) ;
}
void F_32 ( unsigned long V_38 , unsigned long V_39 )
{
F_33 ( ( void * ) V_38 , ( void * ) V_39 , V_49 ,
L_9 ) ;
}
void F_34 ( struct V_50 * V_50 )
{
unsigned long V_51 = ( unsigned long ) F_35 ( V_50 ) ;
if ( V_51 )
F_36 ( V_51 ) ;
}
