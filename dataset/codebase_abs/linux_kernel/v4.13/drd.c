static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 )
V_3 = 0 ;
F_3 ( V_2 , V_3 ?
V_6 :
V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
unsigned long V_10 , void * V_11 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_12 ) ;
F_3 ( V_2 , V_10 ?
V_6 :
V_7 ) ;
return V_13 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_15 -> V_16 ) {
if ( F_7 ( V_2 -> V_15 -> V_16 , L_1 ) )
V_2 -> V_4 = F_8 ( V_2 -> V_15 , 0 ) ;
if ( F_9 ( V_2 -> V_4 ) )
return F_10 ( V_2 -> V_4 ) ;
V_2 -> V_12 . V_17 = F_4 ;
V_14 = F_11 ( V_2 -> V_4 , V_5 ,
& V_2 -> V_12 ) ;
if ( V_14 < 0 ) {
F_12 ( V_2 -> V_15 , L_2 ) ;
return V_14 ;
}
}
F_1 ( V_2 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_4 , V_5 ,
& V_2 -> V_12 ) ;
F_3 ( V_2 , V_7 ) ;
F_15 ( & V_2 -> V_18 ) ;
F_16 ( V_2 ) ;
}
