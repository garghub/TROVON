static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( 0xdeadbeef , V_5 + V_6 ) ;
while ( 1 )
F_3 () ;
return V_7 ;
}
static int F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
int V_14 ;
V_5 = F_5 ( V_11 , 0 ) ;
if ( ! V_5 ) {
F_6 ( 1 , L_1 ) ;
return - V_15 ;
}
if ( F_7 ( V_11 , L_2 , & V_6 ) < 0 ) {
F_8 ( L_3 ) ;
F_9 ( V_5 ) ;
return - V_16 ;
}
V_14 = F_10 ( & V_17 ) ;
if ( V_14 ) {
F_11 ( & V_9 -> V_12 , L_4 ,
V_14 ) ;
F_9 ( V_5 ) ;
}
return V_14 ;
}
