int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned long V_3 ;
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
if ( ! V_1 -> V_8 ) {
F_2 ( V_1 -> V_6 ,
L_1 ) ;
V_1 -> V_9 = 0 ;
return 0 ;
}
V_3 = V_10 | V_11 ;
if ( V_5 -> V_12 )
V_3 = V_5 -> V_12 ;
V_2 = F_3 ( V_1 -> V_13 , V_1 -> V_8 ,
V_3 ,
V_1 -> V_9 , & V_14 ,
& V_1 -> V_15 ) ;
if ( V_2 != 0 ) {
F_4 ( V_1 -> V_6 , L_2 , V_2 ) ;
return V_2 ;
}
F_5 ( V_1 , V_16 , 0 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_1 )
{
F_7 ( V_1 -> V_8 , V_1 -> V_15 ) ;
}
