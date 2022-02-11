static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_3 ( V_5 , 0x1084 , 0x800 , 0x800 ) ;
V_8 = F_4 ( V_5 , 0x21000 + V_3 ) ;
F_5 ( V_5 , 0x1084 , V_7 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
return V_8 ;
}
static int
F_7 ( struct V_1 * V_10 , struct V_1 * V_11 ,
struct V_12 * V_13 , void * V_14 , T_1 V_15 ,
struct V_1 * * V_16 )
{
struct V_4 * V_5 ;
int V_17 ;
V_17 = F_8 ( V_10 , V_11 , V_13 , & V_5 ) ;
* V_16 = F_9 ( V_5 ) ;
if ( V_17 )
return V_17 ;
F_10 ( & V_5 -> V_9 ) ;
return 0 ;
}
