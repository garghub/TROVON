static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x137250 , 0x3f , 0 ) ;
F_2 ( V_2 , 0x000200 , 0x20 , 0 ) ;
F_3 ( 20 , 30 ) ;
F_2 ( V_2 , 0x000200 , 0x20 , 0x20 ) ;
F_4 ( V_2 , 0x12004c , 0x4 ) ;
F_4 ( V_2 , 0x122204 , 0x2 ) ;
F_5 ( V_2 , 0x122204 ) ;
}
static void
F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = ( void * ) V_4 ;
T_1 V_5 = F_5 ( V_2 , 0x120058 ) ;
if ( V_5 & 0x7 ) {
F_7 ( V_2 , L_1 ) ;
F_1 ( V_2 ) ;
}
F_2 ( V_2 , 0x12004c , 0x2 , 0x2 ) ;
if ( ! F_8 ( V_4 , 0x12004c , 0x3f , 0x00 ) )
F_9 ( V_2 , L_2 ) ;
}
static int
F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = ( void * ) V_7 ;
int V_8 ;
V_8 = F_11 ( V_7 ) ;
if ( V_8 )
return V_8 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_6 * V_9 , struct V_6 * V_10 ,
struct V_11 * V_12 , void * V_13 , T_1 V_14 ,
struct V_6 * * V_15 )
{
struct V_1 * V_2 ;
int V_8 ;
V_8 = F_13 ( V_9 , V_10 , V_12 , & V_2 ) ;
* V_15 = F_14 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_15 ( V_2 ) -> V_16 = F_6 ;
return 0 ;
}
