static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( 1 , V_5 + 0xb0 ) ;
F_2 ( 1 , V_6 + 0x34 ) ;
F_3 ( 50 ) ;
F_4 ( L_1 ) ;
return V_7 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
int V_14 ;
V_5 = F_6 ( V_11 , 0 ) ;
if ( ! V_5 ) {
F_7 ( 1 , L_2 ) ;
return - V_15 ;
}
V_11 = F_8 ( NULL , NULL , L_3 ) ;
V_6 = F_6 ( V_11 , 0 ) ;
if ( ! V_6 ) {
F_9 ( V_5 ) ;
F_7 ( 1 , L_4 ) ;
return - V_15 ;
}
V_14 = F_10 ( & V_16 ) ;
if ( V_14 )
F_11 ( & V_9 -> V_12 , L_5 ,
V_14 ) ;
return V_14 ;
}
