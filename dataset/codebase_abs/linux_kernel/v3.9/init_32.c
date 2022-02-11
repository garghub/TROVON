void F_1 ( unsigned int V_1 )
{
F_2 ( L_1 ) ;
F_3 ( V_1 ) ;
F_2 ( L_2 ,
F_4 () << ( V_2 - 10 ) ) ;
F_2 ( L_3 , V_3 ) ;
F_2 ( L_4 , F_5 () ) ;
}
unsigned long F_6 ( void )
{
int V_4 ;
int V_5 = 0 ;
for ( V_4 = 0 ; V_6 [ V_4 ] . V_7 != 0 ; V_4 ++ ) {
unsigned long V_8 = V_6 [ V_4 ] . V_9 >> V_2 ;
unsigned long V_10 = ( V_6 [ V_4 ] . V_9 + V_6 [ V_4 ] . V_7 ) >> V_2 ;
if ( V_10 <= V_11 )
continue;
if ( V_8 < V_11 )
V_8 = V_11 ;
V_5 += V_10 - V_8 ;
}
return V_5 ;
}
static unsigned long F_7 ( void )
{
int V_4 ;
unsigned long V_12 = V_13 + ( V_14 >> V_2 ) ;
unsigned long V_15 , V_16 ;
V_16 = ( V_6 [ 0 ] . V_9 + V_6 [ 0 ] . V_7 ) >> V_2 ;
for ( V_4 = 1 ; V_6 [ V_4 ] . V_7 != 0 ; V_4 ++ ) {
V_15 = V_6 [ V_4 ] . V_9 >> V_2 ;
if ( V_15 >= V_12 ) {
if ( V_16 < V_12 )
V_12 = V_16 ;
break;
}
V_16 = ( V_6 [ V_4 ] . V_9 + V_6 [ V_4 ] . V_7 ) >> V_2 ;
}
return V_12 ;
}
unsigned long T_1 F_8 ( unsigned long * V_17 )
{
unsigned long V_18 , V_8 ;
unsigned long V_19 = 0UL ;
unsigned long V_20 , V_21 , V_22 ;
int V_4 ;
V_21 = 0UL ;
for ( V_4 = 0 ; V_6 [ V_4 ] . V_7 != 0 ; V_4 ++ ) {
V_19 = V_6 [ V_4 ] . V_9 +
V_6 [ V_4 ] . V_7 ;
V_21 += V_6 [ V_4 ] . V_7 ;
if ( V_23 ) {
if ( V_21 > V_23 ) {
unsigned long V_24 = V_21 - V_23 ;
V_21 -= V_24 ;
V_19 -= V_24 ;
V_6 [ V_4 ] . V_7 -= V_24 ;
if ( V_6 [ V_4 ] . V_7 == 0 ) {
V_6 [ V_4 ] . V_9 = 0xdeadbeef ;
} else {
V_6 [ V_4 + 1 ] . V_7 = 0 ;
V_6 [ V_4 + 1 ] . V_9 = 0xdeadbeef ;
}
break;
}
}
}
V_8 = ( unsigned long ) F_9 ( F_10 ( ( unsigned long ) & V_25 ) ) ;
V_8 >>= V_2 ;
V_20 = V_8 ;
V_26 = V_19 >> V_2 ;
V_11 = V_26 ;
V_27 = V_28 = V_26 ;
if ( V_11 > V_13 + ( V_14 >> V_2 ) ) {
V_27 = V_13 + ( V_14 >> V_2 ) ;
V_11 = F_7 () ;
F_2 ( V_29 L_5 ,
F_6 () >> ( 20 - V_2 ) ) ;
}
#ifdef F_11
if ( V_30 ) {
if ( V_30 >= ( unsigned long ) & V_25 - 2 * V_31 )
V_30 -= V_32 ;
V_33 = V_30 + V_34 ;
V_35 = V_33 + V_36 ;
if ( V_35 > V_19 ) {
F_2 ( V_37 L_6
L_7 ,
V_35 , V_19 ) ;
V_33 = 0 ;
}
if ( V_33 ) {
if ( V_33 >= ( V_8 << V_2 ) &&
V_33 < ( V_8 << V_2 ) + 2 * V_31 )
V_20 = F_10 ( V_35 ) >> V_2 ;
}
}
#endif
V_18 = F_12 ( F_13 ( 0 ) , V_20 , V_13 ,
V_11 ) ;
* V_17 = 0 ;
for ( V_4 = 0 ; V_6 [ V_4 ] . V_7 != 0 ; V_4 ++ ) {
unsigned long V_15 , V_16 ;
V_15 = V_6 [ V_4 ] . V_9 >> V_2 ;
if ( V_15 >= V_11 )
break;
V_16 = ( V_6 [ V_4 ] . V_9 + V_6 [ V_4 ] . V_7 ) >> V_2 ;
if ( V_16 > V_11 )
V_16 = V_11 ;
if ( V_16 <= V_15 )
continue;
V_22 = ( V_16 - V_15 ) << V_2 ;
* V_17 += V_16 - V_15 ;
F_14 ( V_6 [ V_4 ] . V_9 , V_22 ) ;
}
#ifdef F_11
if ( V_33 ) {
V_22 = V_35 - V_33 ;
F_15 ( V_33 , V_22 , V_38 ) ;
* V_17 -= F_10 ( V_22 ) >> V_2 ;
V_33 = ( V_33 - V_34 ) + V_39 ;
V_35 = ( V_35 - V_34 ) + V_39 ;
}
#endif
V_22 = ( V_8 << V_2 ) - V_34 ;
F_15 ( V_34 , V_22 , V_38 ) ;
* V_17 -= F_10 ( V_22 ) >> V_2 ;
V_22 = V_18 ;
F_15 ( ( V_20 << V_2 ) , V_22 , V_38 ) ;
* V_17 -= F_10 ( V_22 ) >> V_2 ;
return V_26 ;
}
void T_1 F_16 ( void )
{
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
}
static void T_1 F_21 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_6 [ V_4 ] . V_7 ; V_4 ++ ) {
unsigned long V_40 , V_41 ;
V_40 = V_6 [ V_4 ] . V_9 ;
V_41 = V_40 + V_6 [ V_4 ] . V_7 ;
while ( V_40 < V_41 ) {
F_22 ( V_40 >> 20 , V_42 ) ;
V_40 += V_31 ;
}
}
}
static void F_23 ( unsigned long V_8 , unsigned long V_10 )
{
unsigned long V_12 ;
#ifdef F_24
F_2 ( L_8 , V_8 , V_10 ) ;
#endif
for ( V_12 = V_8 ; V_12 < V_10 ; V_12 ++ ) {
struct V_43 * V_43 = F_25 ( V_12 ) ;
F_26 ( V_43 ) ;
F_27 ( V_43 ) ;
F_28 ( V_43 ) ;
V_44 ++ ;
}
}
void T_1 F_29 ( void )
{
int V_45 = 0 ;
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_4 ;
if ( V_49 + V_50 * V_31 >= V_51 ) {
F_30 ( L_9 ) ;
F_30 ( L_10 ,
V_49 ,
( unsigned long ) V_49 + V_50 * V_31 ,
V_51 ) ;
F_30 ( L_11 ) ;
F_31 () ;
}
memset ( ( void * ) & V_52 , 0 , V_31 ) ;
V_4 = V_53 >> ( ( 20 - V_2 ) + 5 ) ;
V_4 += 1 ;
V_42 = ( unsigned long * )
F_32 ( V_4 << 2 , V_54 , 0UL ) ;
if ( V_42 == NULL ) {
F_30 ( L_12 ) ;
F_31 () ;
}
memset ( V_42 , 0 , V_4 << 2 ) ;
F_21 () ;
V_55 = V_53 - V_13 ;
V_56 = F_33 ( V_11 << V_2 ) ;
V_3 = F_34 () ;
for ( V_4 = 0 ; V_6 [ V_4 ] . V_7 != 0 ; V_4 ++ ) {
unsigned long V_8 = V_6 [ V_4 ] . V_9 >> V_2 ;
unsigned long V_10 = ( V_6 [ V_4 ] . V_9 + V_6 [ V_4 ] . V_7 ) >> V_2 ;
V_57 += V_6 [ V_4 ] . V_7 >> V_2 ;
if ( V_10 <= V_27 )
continue;
if ( V_8 < V_27 )
V_8 = V_27 ;
F_23 ( V_8 , V_10 ) ;
}
V_3 += V_44 ;
V_45 = ( ( ( unsigned long ) & V_58 ) - ( ( unsigned long ) & V_59 ) ) ;
V_45 = F_10 ( V_45 ) >> V_2 ;
V_46 = ( ( ( unsigned long ) & V_60 ) - ( ( unsigned long ) & V_58 ) ) ;
V_46 = F_10 ( V_46 ) >> V_2 ;
V_47 = ( ( ( unsigned long ) & V_61 ) - ( ( unsigned long ) & V_62 ) ) ;
V_47 = F_10 ( V_47 ) >> V_2 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ )
if ( F_35 ( V_4 >> ( 20 - V_2 ) , V_42 )
&& F_36 ( F_25 ( V_4 ) ) )
V_48 ++ ;
F_2 ( V_63 L_13 ,
F_5 () << ( V_2 - 10 ) ,
V_57 << ( V_2 - 10 ) ,
V_45 << ( V_2 - 10 ) ,
V_48 << ( V_2 - 10 ) ,
V_46 << ( V_2 - 10 ) ,
V_47 << ( V_2 - 10 ) ,
V_44 << ( V_2 - 10 ) ) ;
}
void F_37 ( void )
{
unsigned long V_64 ;
unsigned long V_65 ;
V_64 = ( unsigned long ) ( & V_62 ) ;
V_65 = ( unsigned long ) ( & V_61 ) - V_64 ;
for (; V_64 < ( unsigned long ) ( & V_61 ) ; V_64 += V_31 ) {
struct V_43 * V_66 ;
memset ( ( void * ) V_64 , V_67 , V_31 ) ;
V_66 = F_38 ( V_64 ) ;
F_26 ( V_66 ) ;
F_27 ( V_66 ) ;
F_28 ( V_66 ) ;
V_3 ++ ;
V_57 ++ ;
}
F_2 ( V_63 L_14 ,
V_65 >> 10 ) ;
}
void F_39 ( unsigned long V_40 , unsigned long V_41 )
{
if ( V_40 < V_41 )
F_2 ( V_63 L_15 ,
( V_41 - V_40 ) >> 10 ) ;
for (; V_40 < V_41 ; V_40 += V_31 ) {
struct V_43 * V_66 ;
memset ( ( void * ) V_40 , V_67 , V_31 ) ;
V_66 = F_38 ( V_40 ) ;
F_26 ( V_66 ) ;
F_27 ( V_66 ) ;
F_28 ( V_66 ) ;
V_3 ++ ;
V_57 ++ ;
}
}
void F_40 ( struct V_43 * V_43 )
{
unsigned long V_68 = ( unsigned long ) F_41 ( V_43 ) ;
if ( V_68 )
F_42 ( V_68 ) ;
}
