static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
unsigned long V_6 ;
T_1 V_7 , V_8 , V_9 ;
F_2 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_3 ( V_5 , 0x22400 , 0x800 , 0x800 ) ;
V_8 = F_3 ( V_5 , 0x21000 , 0x1 , 0x1 ) ;
V_9 = F_4 ( V_5 , 0x21100 + V_3 ) ;
F_5 ( V_5 , 0x21000 , V_8 ) ;
F_5 ( V_5 , 0x22400 , V_7 ) ;
F_6 ( & V_5 -> V_10 , V_6 ) ;
return V_9 ;
}
static int
F_7 ( struct V_1 * V_11 , struct V_1 * V_12 ,
struct V_13 * V_14 , void * V_15 , T_1 V_16 ,
struct V_1 * * V_17 )
{
struct V_4 * V_5 ;
int V_18 ;
V_18 = F_8 ( V_11 , V_12 , V_14 , & V_5 ) ;
* V_17 = F_9 ( V_5 ) ;
if ( V_18 )
return V_18 ;
F_10 ( & V_5 -> V_10 ) ;
return 0 ;
}
