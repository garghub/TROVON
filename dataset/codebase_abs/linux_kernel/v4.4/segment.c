static void F_1 ( char * V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
static const char * const V_4 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 ,
L_7 , L_8 } ;
V_3 = ( V_2 & V_5 ) >> V_6 ;
V_1 += sprintf ( V_1 , L_9 , V_4 [ V_3 ] ) ;
if ( ( V_3 == 0 ) || ( V_3 > 3 ) ) {
V_1 += sprintf ( V_1 , L_10 ,
( ( V_2 & V_7 ) >> V_8 ) ) ;
V_1 += sprintf ( V_1 , L_11 ,
( ( V_2 & V_9 ) >> V_10 ) ) ;
} else {
V_1 += sprintf ( V_1 , L_12 ) ;
V_1 += sprintf ( V_1 , L_13 ) ;
}
V_1 += sprintf ( V_1 , L_14 ,
( ( V_2 & V_11 ) >> V_12 ) ) ;
}
static int F_2 ( struct V_13 * V_14 , void * V_15 )
{
unsigned int V_16 ;
char V_1 [ 42 ] ;
F_3 ( V_14 , L_15 ) ;
F_3 ( V_14 , L_16 ) ;
V_16 = F_4 () ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_17 , V_1 ) ;
V_16 >>= 16 ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_18 , V_1 ) ;
V_16 = F_6 () ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_19 , V_1 ) ;
V_16 >>= 16 ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_20 , V_1 ) ;
V_16 = F_7 () ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_21 , V_1 ) ;
V_16 >>= 16 ;
F_1 ( V_1 , V_16 ) ;
F_5 ( V_14 , L_22 , V_1 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
return F_9 ( V_18 , F_2 , NULL ) ;
}
static int T_1 F_10 ( void )
{
struct V_19 * V_20 ;
if ( V_21 ) {
if ( ! V_22 )
return - V_23 ;
V_20 = F_11 ( L_23 , V_24 ,
V_22 , NULL ,
& V_25 ) ;
if ( ! V_20 )
return - V_26 ;
}
return 0 ;
}
