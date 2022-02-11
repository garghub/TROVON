static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
}
static unsigned long F_3 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 , V_5 ;
V_4 = F_4 ( V_6 ) ;
V_5 = ( ( 12 + ( V_4 & 0x3f ) ) * 1000000 ) +
( ( ( ( V_4 >> 8 ) & 0x3ff ) * 1000000 ) >> 10 ) ;
V_5 *= V_7 ;
V_5 >>= 1 ;
return V_5 ;
}
static struct V_8 * T_2 F_5 ( struct V_9 * V_10 ,
const char * V_11 , const char * V_12 , unsigned long V_13 )
{
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_14 V_15 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_2 ) {
F_7 ( L_1 , V_17 ) ;
return F_8 ( - V_18 ) ;
}
V_15 . V_11 = V_11 ;
V_15 . V_19 = & V_20 ;
V_15 . V_13 = V_13 | V_21 ;
V_15 . V_22 = ( V_12 ? & V_12 : NULL ) ;
V_15 . V_23 = ( V_12 ? 1 : 0 ) ;
V_2 -> V_15 = & V_15 ;
V_8 = F_9 ( V_10 , V_2 ) ;
if ( F_10 ( V_8 ) )
F_11 ( V_2 ) ;
return V_8 ;
}
void T_2 F_12 ( void )
{
struct V_8 * V_8 ;
V_8 = F_5 ( NULL , L_2 , NULL , V_24 ) ;
F_13 ( V_8 ) ;
V_8 = F_14 ( NULL , L_3 , L_2 ,
V_25 , V_26 , V_27 ,
V_28 , V_29 , & V_30 ) ;
F_13 ( V_8 ) ;
F_15 ( V_8 , L_4 , NULL ) ;
V_8 = F_14 ( NULL , L_5 , L_2 ,
V_25 , V_26 , V_31 ,
V_32 , V_29 , & V_30 ) ;
F_13 ( V_8 ) ;
F_15 ( V_8 , L_6 , NULL ) ;
V_8 = F_14 ( NULL , L_7 , L_2 ,
V_25 , V_26 , V_33 ,
V_34 , V_29 , & V_30 ) ;
F_13 ( V_8 ) ;
F_15 ( V_8 , L_8 , NULL ) ;
F_15 ( V_8 , L_9 , NULL ) ;
V_8 = F_16 ( NULL , L_10 , L_7 , 0 , 1 , 2 ) ;
F_13 ( V_8 ) ;
F_15 ( V_8 , L_11 , NULL ) ;
F_15 ( V_8 , L_12 , NULL ) ;
}
