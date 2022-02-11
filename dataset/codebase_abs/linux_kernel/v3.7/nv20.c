static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_7 = ( V_6 -> V_8 >= 0x25 ? 0x300 : 0x900 ) ;
T_1 V_9 , V_10 ;
struct V_11 * V_12 ;
V_12 = F_3 ( F_2 ( V_4 ) -> V_13 ) ;
if ( ! V_12 ) {
F_4 ( V_4 , L_1 ) ;
return;
}
F_5 ( V_4 , V_14 , V_15 ) ;
F_6 ( V_4 , V_16 , 0 , V_7 ) ;
V_9 = F_7 ( V_4 , 0x10020c ) ;
for ( V_10 = V_9 ; V_10 > 0x2000000 ; V_10 -= 0x2000000 )
F_8 ( V_12 , V_10 - 4 , V_10 ) ;
V_9 = F_7 ( V_4 , 0x10020c ) ;
if ( V_9 != F_9 ( V_12 , V_9 - 4 ) )
F_6 ( V_4 , V_16 , V_7 , 0 ) ;
F_10 ( V_12 ) ;
}
static int
F_11 ( struct V_17 * V_18 , struct V_17 * V_19 ,
struct V_20 * V_21 , void * V_22 , T_2 V_23 ,
struct V_17 * * V_24 )
{
struct V_3 * V_4 ;
int V_25 ;
V_25 = F_12 ( V_18 , V_19 , V_21 , & V_4 ) ;
* V_24 = F_13 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_26 . V_27 = F_1 ;
return 0 ;
}
