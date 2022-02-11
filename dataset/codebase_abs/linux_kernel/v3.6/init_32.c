void F_1 ( unsigned int V_1 )
{
F_2 ( L_1 ) ;
F_3 ( V_1 ) ;
F_2 ( L_2 ,
V_2 << ( V_3 - 10 ) ) ;
F_2 ( L_3 , V_4 ) ;
F_2 ( L_4 , F_4 () ) ;
}
unsigned long F_5 ( void )
{
int V_5 ;
int V_6 = 0 ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_8 != 0 ; V_5 ++ ) {
unsigned long V_9 = V_7 [ V_5 ] . V_10 >> V_3 ;
unsigned long V_11 = ( V_7 [ V_5 ] . V_10 + V_7 [ V_5 ] . V_8 ) >> V_3 ;
if ( V_11 <= V_12 )
continue;
if ( V_9 < V_12 )
V_9 = V_12 ;
V_6 += V_11 - V_9 ;
}
return V_6 ;
}
static unsigned long F_6 ( void )
{
int V_5 ;
unsigned long V_13 = V_14 + ( V_15 >> V_3 ) ;
unsigned long V_16 , V_17 ;
V_17 = ( V_7 [ 0 ] . V_10 + V_7 [ 0 ] . V_8 ) >> V_3 ;
for ( V_5 = 1 ; V_7 [ V_5 ] . V_8 != 0 ; V_5 ++ ) {
V_16 = V_7 [ V_5 ] . V_10 >> V_3 ;
if ( V_16 >= V_13 ) {
if ( V_17 < V_13 )
V_13 = V_17 ;
break;
}
V_17 = ( V_7 [ V_5 ] . V_10 + V_7 [ V_5 ] . V_8 ) >> V_3 ;
}
return V_13 ;
}
unsigned long T_1 F_7 ( unsigned long * V_18 )
{
unsigned long V_19 , V_9 ;
unsigned long V_20 = 0UL ;
unsigned long V_21 , V_22 , V_23 ;
int V_5 ;
V_22 = 0UL ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_8 != 0 ; V_5 ++ ) {
V_20 = V_7 [ V_5 ] . V_10 +
V_7 [ V_5 ] . V_8 ;
V_22 += V_7 [ V_5 ] . V_8 ;
if ( V_24 ) {
if ( V_22 > V_24 ) {
unsigned long V_25 = V_22 - V_24 ;
V_22 -= V_25 ;
V_20 -= V_25 ;
V_7 [ V_5 ] . V_8 -= V_25 ;
if ( V_7 [ V_5 ] . V_8 == 0 ) {
V_7 [ V_5 ] . V_10 = 0xdeadbeef ;
} else {
V_7 [ V_5 + 1 ] . V_8 = 0 ;
V_7 [ V_5 + 1 ] . V_10 = 0xdeadbeef ;
}
break;
}
}
}
V_9 = ( unsigned long ) F_8 ( F_9 ( ( unsigned long ) & V_26 ) ) ;
V_9 >>= V_3 ;
V_21 = V_9 ;
V_27 = V_20 >> V_3 ;
V_12 = V_27 ;
V_28 = V_29 = V_27 ;
if ( V_12 > V_14 + ( V_15 >> V_3 ) ) {
V_28 = V_14 + ( V_15 >> V_3 ) ;
V_12 = F_6 () ;
F_2 ( V_30 L_5 ,
F_5 () >> ( 20 - V_3 ) ) ;
}
#ifdef F_10
if ( V_31 ) {
if ( V_31 >= ( unsigned long ) & V_26 - 2 * V_32 )
V_31 -= V_33 ;
V_34 = V_31 + V_35 ;
V_36 = V_34 + V_37 ;
if ( V_36 > V_20 ) {
F_2 ( V_38 L_6
L_7 ,
V_36 , V_20 ) ;
V_34 = 0 ;
}
if ( V_34 ) {
if ( V_34 >= ( V_9 << V_3 ) &&
V_34 < ( V_9 << V_3 ) + 2 * V_32 )
V_21 = F_9 ( V_36 ) >> V_3 ;
}
}
#endif
V_19 = F_11 ( F_12 ( 0 ) , V_21 , V_14 ,
V_12 ) ;
* V_18 = 0 ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_8 != 0 ; V_5 ++ ) {
unsigned long V_16 , V_17 ;
V_16 = V_7 [ V_5 ] . V_10 >> V_3 ;
if ( V_16 >= V_12 )
break;
V_17 = ( V_7 [ V_5 ] . V_10 + V_7 [ V_5 ] . V_8 ) >> V_3 ;
if ( V_17 > V_12 )
V_17 = V_12 ;
if ( V_17 <= V_16 )
continue;
V_23 = ( V_17 - V_16 ) << V_3 ;
* V_18 += V_17 - V_16 ;
F_13 ( V_7 [ V_5 ] . V_10 , V_23 ) ;
}
#ifdef F_10
if ( V_34 ) {
V_23 = V_36 - V_34 ;
F_14 ( V_34 , V_23 , V_39 ) ;
* V_18 -= F_9 ( V_23 ) >> V_3 ;
V_34 = ( V_34 - V_35 ) + V_40 ;
V_36 = ( V_36 - V_35 ) + V_40 ;
}
#endif
V_23 = ( V_9 << V_3 ) - V_35 ;
F_14 ( V_35 , V_23 , V_39 ) ;
* V_18 -= F_9 ( V_23 ) >> V_3 ;
V_23 = V_19 ;
F_14 ( ( V_21 << V_3 ) , V_23 , V_39 ) ;
* V_18 -= F_9 ( V_23 ) >> V_3 ;
return V_27 ;
}
void T_1 F_15 ( void )
{
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
}
static void T_1 F_20 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_8 ; V_5 ++ ) {
unsigned long V_41 , V_42 ;
V_41 = V_7 [ V_5 ] . V_10 ;
V_42 = V_41 + V_7 [ V_5 ] . V_8 ;
while ( V_41 < V_42 ) {
F_21 ( V_41 >> 20 , V_43 ) ;
V_41 += V_32 ;
}
}
}
static void F_22 ( unsigned long V_9 , unsigned long V_11 )
{
unsigned long V_13 ;
#ifdef F_23
F_2 ( L_8 , V_9 , V_11 ) ;
#endif
for ( V_13 = V_9 ; V_13 < V_11 ; V_13 ++ ) {
struct V_44 * V_44 = F_24 ( V_13 ) ;
F_25 ( V_44 ) ;
F_26 ( V_44 ) ;
F_27 ( V_44 ) ;
V_45 ++ ;
}
}
void T_1 F_28 ( void )
{
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
int V_5 ;
if ( V_50 + V_51 * V_32 >= V_52 ) {
F_29 ( L_9 ) ;
F_29 ( L_10 ,
V_50 ,
( unsigned long ) V_50 + V_51 * V_32 ,
V_52 ) ;
F_29 ( L_11 ) ;
F_30 () ;
}
memset ( ( void * ) & V_53 , 0 , V_32 ) ;
V_5 = V_54 >> ( ( 20 - V_3 ) + 5 ) ;
V_5 += 1 ;
V_43 = ( unsigned long * )
F_31 ( V_5 << 2 , V_55 , 0UL ) ;
if ( V_43 == NULL ) {
F_29 ( L_12 ) ;
F_30 () ;
}
memset ( V_43 , 0 , V_5 << 2 ) ;
F_20 () ;
V_56 = V_54 - V_14 ;
V_57 = F_32 ( V_12 << V_3 ) ;
V_4 = F_33 () ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_8 != 0 ; V_5 ++ ) {
unsigned long V_9 = V_7 [ V_5 ] . V_10 >> V_3 ;
unsigned long V_11 = ( V_7 [ V_5 ] . V_10 + V_7 [ V_5 ] . V_8 ) >> V_3 ;
V_58 += V_7 [ V_5 ] . V_8 >> V_3 ;
if ( V_11 <= V_28 )
continue;
if ( V_9 < V_28 )
V_9 = V_28 ;
F_22 ( V_9 , V_11 ) ;
}
V_4 += V_45 ;
V_46 = ( ( ( unsigned long ) & V_59 ) - ( ( unsigned long ) & V_60 ) ) ;
V_46 = F_9 ( V_46 ) >> V_3 ;
V_47 = ( ( ( unsigned long ) & V_61 ) - ( ( unsigned long ) & V_59 ) ) ;
V_47 = F_9 ( V_47 ) >> V_3 ;
V_48 = ( ( ( unsigned long ) & V_62 ) - ( ( unsigned long ) & V_63 ) ) ;
V_48 = F_9 ( V_48 ) >> V_3 ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ )
if ( F_34 ( V_5 >> ( 20 - V_3 ) , V_43 )
&& F_35 ( F_24 ( V_5 ) ) )
V_49 ++ ;
F_2 ( V_64 L_13 ,
F_4 () << ( V_3 - 10 ) ,
V_58 << ( V_3 - 10 ) ,
V_46 << ( V_3 - 10 ) ,
V_49 << ( V_3 - 10 ) ,
V_47 << ( V_3 - 10 ) ,
V_48 << ( V_3 - 10 ) ,
V_45 << ( V_3 - 10 ) ) ;
}
void F_36 ( void )
{
unsigned long V_65 ;
unsigned long V_66 ;
V_65 = ( unsigned long ) ( & V_63 ) ;
V_66 = ( unsigned long ) ( & V_62 ) - V_65 ;
for (; V_65 < ( unsigned long ) ( & V_62 ) ; V_65 += V_32 ) {
struct V_44 * V_67 ;
memset ( ( void * ) V_65 , V_68 , V_32 ) ;
V_67 = F_37 ( V_65 ) ;
F_25 ( V_67 ) ;
F_26 ( V_67 ) ;
F_27 ( V_67 ) ;
V_4 ++ ;
V_58 ++ ;
}
F_2 ( V_64 L_14 ,
V_66 >> 10 ) ;
}
void F_38 ( unsigned long V_41 , unsigned long V_42 )
{
if ( V_41 < V_42 )
F_2 ( V_64 L_15 ,
( V_42 - V_41 ) >> 10 ) ;
for (; V_41 < V_42 ; V_41 += V_32 ) {
struct V_44 * V_67 ;
memset ( ( void * ) V_41 , V_68 , V_32 ) ;
V_67 = F_37 ( V_41 ) ;
F_25 ( V_67 ) ;
F_26 ( V_67 ) ;
F_27 ( V_67 ) ;
V_4 ++ ;
V_58 ++ ;
}
}
void F_39 ( struct V_44 * V_44 )
{
unsigned long V_69 = ( unsigned long ) F_40 ( V_44 ) ;
if ( V_69 )
F_41 ( V_69 ) ;
}
