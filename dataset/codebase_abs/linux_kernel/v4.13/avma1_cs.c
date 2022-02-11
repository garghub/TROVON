static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ) ;
V_2 -> V_4 |= V_5 | V_6 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = V_9 ;
return F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_10 )
{
F_2 ( & V_10 -> V_3 , L_2 , V_10 ) ;
F_5 ( V_10 ) ;
F_6 ( V_10 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_12 )
{
V_2 -> V_13 [ 0 ] -> V_14 = 16 ;
V_2 -> V_13 [ 0 ] -> V_15 &= ~ V_16 ;
V_2 -> V_13 [ 0 ] -> V_15 |= V_17 ;
V_2 -> V_18 = 5 ;
return F_8 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_10 )
{
int V_19 = - 1 ;
char V_20 [ 128 ] ;
T_1 V_21 ;
int V_22 = 0 ;
F_2 ( & V_10 -> V_3 , L_3 , V_10 ) ;
V_20 [ 0 ] = 0 ;
if ( V_10 -> V_23 [ 1 ] )
F_9 ( V_20 , V_10 -> V_23 [ 1 ] , sizeof( V_20 ) ) ;
if ( F_10 ( V_10 , F_7 , NULL ) )
return - V_24 ;
do {
if ( ! V_10 -> V_25 ) {
F_11 ( V_10 ) ;
break;
}
V_19 = F_12 ( V_10 ) ;
if ( V_19 != 0 ) {
F_11 ( V_10 ) ;
break;
}
} while ( 0 );
if ( V_19 != 0 ) {
F_5 ( V_10 ) ;
return - V_24 ;
}
V_21 . V_26 [ 0 ] = V_10 -> V_25 ;
V_21 . V_26 [ 1 ] = V_10 -> V_13 [ 0 ] -> V_27 ;
V_21 . V_28 = V_29 ;
V_21 . V_30 = V_31 ;
V_19 = F_13 ( V_10 , & V_22 , & V_21 ) ;
if ( V_19 < 0 ) {
F_14 ( V_32 L_4
L_5 , V_19 ,
( unsigned int ) V_10 -> V_13 [ 0 ] -> V_27 ) ;
F_5 ( V_10 ) ;
return - V_24 ;
}
V_10 -> V_11 = ( void * ) ( unsigned long ) V_19 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_10 )
{
unsigned long V_33 = ( unsigned long ) V_10 -> V_11 ;
F_2 ( & V_10 -> V_3 , L_6 , V_10 ) ;
F_15 ( V_33 ) ;
F_11 ( V_10 ) ;
}
