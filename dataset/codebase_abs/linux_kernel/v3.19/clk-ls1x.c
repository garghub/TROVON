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
V_5 = 12 + ( V_4 & 0x3f ) + ( ( ( V_4 >> 8 ) & 0x3ff ) >> 10 ) ;
V_5 *= V_7 ;
V_5 >>= 1 ;
return V_5 ;
}
static struct V_8 * T_2 F_5 ( struct V_9 * V_10 ,
const char * V_11 ,
const char * V_12 ,
unsigned long V_13 )
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
V_8 = F_13 ( NULL , L_2 , NULL , V_24 ,
V_7 ) ;
F_14 ( V_8 , L_2 , NULL ) ;
V_8 = F_5 ( NULL , L_3 , L_2 , 0 ) ;
F_14 ( V_8 , L_3 , NULL ) ;
V_8 = F_15 ( NULL , L_4 , L_3 ,
V_25 , V_26 ,
V_27 , V_28 ,
V_29 |
V_30 , & V_31 ) ;
F_14 ( V_8 , L_4 , NULL ) ;
V_8 = F_16 ( NULL , L_5 , V_32 ,
F_17 ( V_32 ) ,
V_33 , V_26 ,
V_34 , V_35 , 0 , & V_31 ) ;
F_14 ( V_8 , L_5 , NULL ) ;
V_8 = F_15 ( NULL , L_6 , L_3 ,
0 , V_26 , V_36 ,
V_37 , V_29 , & V_31 ) ;
F_14 ( V_8 , L_6 , NULL ) ;
V_8 = F_16 ( NULL , L_7 , V_38 ,
F_17 ( V_38 ) ,
V_33 , V_26 ,
V_39 , V_40 , 0 , & V_31 ) ;
F_14 ( V_8 , L_7 , NULL ) ;
V_8 = F_15 ( NULL , L_8 , L_3 ,
0 , V_26 , V_41 ,
V_42 , V_29 ,
& V_31 ) ;
F_14 ( V_8 , L_8 , NULL ) ;
V_8 = F_16 ( NULL , L_9 , V_43 ,
F_17 ( V_43 ) ,
V_33 , V_26 ,
V_44 , V_45 , 0 , & V_31 ) ;
F_14 ( V_8 , L_9 , NULL ) ;
F_14 ( V_8 , L_10 , NULL ) ;
V_8 = F_18 ( NULL , L_11 , L_9 , 0 , 1 ,
V_46 ) ;
F_14 ( V_8 , L_11 , NULL ) ;
F_14 ( V_8 , L_12 , NULL ) ;
F_14 ( V_8 , L_13 , NULL ) ;
F_14 ( V_8 , L_14 , NULL ) ;
F_14 ( V_8 , L_15 , NULL ) ;
F_14 ( V_8 , L_16 , NULL ) ;
}
