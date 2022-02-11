static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 -> V_4 ;
if ( V_3 ) {
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_3 = F_3 ( V_6 ) & ~ V_3 ;
F_4 ( V_3 , V_6 ) ;
F_5 ( V_5 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 -> V_4 ;
if ( V_3 ) {
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_3 = F_3 ( V_6 ) | V_3 ;
F_4 ( V_3 , V_6 ) ;
F_5 ( V_5 ) ;
}
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_7 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_10 ( V_2 -> V_7 ) ;
}
static unsigned int F_11 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
unsigned int V_7 ;
if ( V_10 >= 16 ) {
F_12 ( L_1 , V_10 ) ;
F_13 () ;
}
V_7 = F_14 ( V_10 , V_10 ) ;
if ( V_7 ) {
unsigned long V_3 = 0UL ;
switch ( V_10 ) {
case 1 :
V_3 = V_11 ;
break;
case 8 :
V_3 = V_12 ;
break;
case 10 :
V_3 = V_13 ;
break;
case 14 :
V_3 = V_14 ;
break;
default:
break;
}
F_15 ( V_7 , & V_15 ,
V_16 , L_2 ) ;
F_16 ( V_7 , ( void * ) V_3 ) ;
}
return V_7 ;
}
static void F_17 ( void )
{
F_18 ( & V_17 -> V_18 ) ;
}
static void F_19 ( int V_19 , unsigned int V_20 )
{
}
static void T_1 F_20 ( T_2 V_21 )
{
const struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_7 ;
const T_3 * V_26 ;
int V_27 ;
V_25 = F_21 ( NULL , L_3 ) ;
if ( ! V_25 ) {
F_12 ( L_4 ) ;
F_13 () ;
}
V_26 = F_22 ( V_25 , L_5 , NULL ) ;
if ( ! V_26 ) {
F_12 ( L_6 ) ;
F_13 () ;
}
V_17 = ( void V_28 * ) ( unsigned long ) V_26 [ 0 ] ;
V_23 = F_22 ( V_25 , L_7 , NULL ) ;
F_23 ( V_25 ) ;
if ( ! V_23 ) {
F_12 ( L_8 ) ;
F_13 () ;
}
F_24 ( ( ( ( 1000000 / V_29 ) + 1 ) << 10 ) , & V_17 -> V_18 ) ;
V_30 = & V_17 -> V_31 ;
V_7 = F_11 ( NULL , V_23 [ 0 ] . V_32 ) ;
V_27 = F_25 ( V_7 , V_21 , V_33 , L_9 , NULL ) ;
if ( V_27 ) {
F_12 ( L_10 , V_27 ) ;
F_13 () ;
}
F_1 ( F_26 ( V_7 ) ) ;
}
static void F_27 ( void )
{
}
void T_1 F_28 ( void )
{
struct V_24 * V_25 ;
const T_3 * V_26 ;
V_25 = F_21 ( NULL , L_11 ) ;
if ( ! V_25 ) {
F_12 ( L_12 ) ;
F_13 () ;
}
V_26 = F_22 ( V_25 , L_5 , NULL ) ;
F_23 ( V_25 ) ;
if ( ! V_26 ) {
F_12 ( L_13 ) ;
F_13 () ;
}
V_6 = ( void V_28 * ) ( unsigned long ) V_26 [ 0 ] ;
F_29 ( V_34 , F_17 , V_35 ) ;
F_29 ( V_36 , F_19 , V_37 ) ;
V_38 . V_39 = F_20 ;
V_38 . V_40 = F_11 ;
#ifdef F_30
F_29 ( V_41 , F_27 , V_37 ) ;
F_29 ( V_42 , F_27 , V_37 ) ;
F_29 ( V_43 , F_27 , V_37 ) ;
#endif
F_4 ( V_44 , V_6 ) ;
}
