static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
F_2 ( L_1 , V_1 , V_2 ) ;
F_3 ( V_2 == 0 ) ;
F_4 ( V_1 , V_1 + V_2 ) ;
if ( ! V_5 )
return;
V_4 = V_1 & ~ ( V_6 - 1 ) ;
V_3 = ( V_1 + V_2 - 1 ) & ~ ( V_6 - 1 ) ;
while( 1 ) {
F_5 ( V_4 ) ;
if ( V_4 == V_3 )
break;
V_4 += V_6 ;
}
}
static void F_6 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
F_2 ( L_2 , V_1 , V_2 ) ;
F_3 ( V_2 == 0 ) ;
F_7 ( V_1 , V_1 + V_2 ) ;
if ( ! V_5 )
return;
V_4 = V_1 & ~ ( V_6 - 1 ) ;
V_3 = ( V_1 + V_2 - 1 ) & ~ ( V_6 - 1 ) ;
while( 1 ) {
F_5 ( V_4 ) ;
if ( V_4 == V_3 )
break;
V_4 += V_6 ;
}
}
static void F_8 ( void )
{
unsigned long V_7 = F_9 ( 0 ) ;
unsigned long V_3 = V_7 + V_8 ;
F_10 ( 0 ) ;
while ( V_7 < V_3 ) {
F_11 ( V_9 , V_7 ) ;
V_7 += V_6 ;
}
}
static void F_12 ( void )
{
int V_10 ;
F_13 ( V_11 ) ;
F_10 ( 0 ) ;
F_14 ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 += V_12 )
F_11 ( V_13 , F_9 ( V_10 ) ) ;
}
static void F_15 ( void )
{
if ( F_16 () & V_11 )
return;
F_3 ( V_8 == 0 ) ;
F_17 ( F_12 ) ;
}
static void F_18 ( void )
{
int V_10 ;
F_13 ( V_14 ) ;
F_10 ( 0 ) ;
F_14 ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 += V_16 )
F_11 ( V_17 , F_9 ( V_10 ) ) ;
}
static void F_19 ( void )
{
if ( F_16 () & V_14 )
return;
F_20 ( L_3 ) ;
F_17 ( F_18 ) ;
if ( V_5 )
F_15 () ;
}
static void F_21 ( void )
{
unsigned long V_18 ;
F_22 ( V_18 ) ;
F_8 () ;
F_23 ( V_11 ) ;
F_22 ( V_18 ) ;
}
static void F_24 ( void )
{
F_23 ( V_14 ) ;
if ( V_5 )
F_21 () ;
}
static void F_25 ( void )
{
unsigned long V_18 , V_1 , V_19 , V_3 , V_20 ;
V_19 = ( unsigned long ) & V_21 ;
V_19 &= ~ ( ( 8 * 1024 * 1024 ) - 1 ) ;
V_3 = V_19 + ( 8 * 1024 * 1024 ) ;
F_22 ( V_18 ) ;
F_13 ( V_11 ) ;
V_20 = ( 256 * 1024 ) ;
for ( V_1 = V_19 ; V_1 <= V_3 ; V_1 = ( V_19 + V_20 ) ) {
unsigned long * V_22 = ( unsigned long * ) V_1 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_20 <<= 1 ;
}
F_10 ( 0 ) ;
F_14 ( 0 ) ;
F_11 ( V_13 , V_19 ) ;
V_20 = ( 512 * 1024 ) ;
for ( V_1 = V_19 + ( 512 * 1024 ) ; V_1 <= V_3 ; V_1 = V_19 + V_20 ) {
F_11 ( V_23 , V_1 ) ;
if ( ! F_26 () )
break;
V_20 <<= 1 ;
}
V_1 -= V_19 ;
V_8 = V_1 ;
F_23 ( V_11 ) ;
F_27 ( V_18 ) ;
}
void F_28 ( void )
{
struct V_24 * V_25 = & V_26 ;
unsigned int V_27 = F_16 () ;
if ( ( V_27 & V_28 ) )
return;
V_25 -> V_29 . V_30 = V_16 ;
V_25 -> V_29 . V_31 = 4 ;
V_25 -> V_29 . V_32 = F_29 ( V_15 / V_25 -> V_29 . V_31 ) ;
V_25 -> V_29 . V_33 = V_15 / V_25 -> V_29 . V_31 ;
V_25 -> V_29 . V_34 = V_15 / ( V_25 -> V_29 . V_30 * V_25 -> V_29 . V_31 ) ;
F_30 ( V_35 L_4 ,
( V_15 >> 10 ) , V_16 ) ;
if ( ! ( V_27 & V_14 ) )
F_19 () ;
V_36 = & V_37 ;
V_5 = 0 ;
V_8 = 0 ;
if ( V_27 & V_38 )
return;
F_17 ( F_25 ) ;
F_15 () ;
V_5 = 1 ;
V_25 -> V_39 . V_30 = V_12 ;
V_25 -> V_39 . V_31 = 1 ;
F_20 ( L_5 , ( V_8 >> 10 ) ) ;
}
