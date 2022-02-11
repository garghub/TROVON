static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_6 ,
V_4 + F_4 ( V_2 -> V_7 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_6 ,
V_4 + F_6 ( V_2 -> V_7 ) ) ;
}
T_1 void T_2 F_7 ( struct V_8 * V_9 )
{
T_3 V_10 ;
do {
V_10 = F_8 ( V_4 + V_11 ) ;
if ( V_10 != 0x7f ) {
F_2 ( V_10 , V_4 + V_12 ) ;
V_10 = F_9 ( V_13 , V_10 ) ;
F_10 ( V_10 , V_9 ) ;
continue;
}
break;
} while ( 1 );
}
static int F_11 ( struct V_14 * V_2 , unsigned int V_15 ,
T_4 V_16 )
{
F_12 ( V_15 , & V_17 , V_18 ) ;
F_13 ( V_15 , V_19 ) ;
return 0 ;
}
static void T_5 F_14 ( struct V_20 * V_21 ,
struct V_20 * V_22 )
{
F_15 ( V_4 + V_23 ) ;
V_13 = F_16 ( V_21 , V_24 ,
& V_25 , NULL ) ;
F_17 ( ! V_13 ) ;
}
void T_5 F_18 ( void )
{
F_19 ( V_26 ) ;
}
