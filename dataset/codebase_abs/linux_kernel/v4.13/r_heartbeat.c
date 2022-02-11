void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 = 0 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_9 = 0 ;
int V_10 = 1 ;
V_8 = F_4 ( V_2 , sizeof F_5 ) ;
if ( ! V_8 )
return - V_11 ;
while ( V_9 < 3 ) {
memcpy ( V_8 -> V_12 , ( void * ) & F_5 , sizeof F_5 ) ;
V_8 -> V_13 = V_14 ;
F_6 ( V_2 , V_8 ) ;
F_7 ( V_8 , V_15 ) ;
if ( V_8 -> V_13 != V_16 )
V_9 ++ ;
F_8 ( V_4 -> V_5 ,
V_4 -> V_6 ,
V_17 * V_18 ) ;
if ( F_9 ( V_19 ) || V_4 -> V_6 ) {
V_10 = - V_20 ;
break;
}
}
F_10 ( V_8 ) ;
V_4 -> V_6 = 0 ;
return V_10 ;
}
void F_11 ( struct V_3 * V_4 )
{
V_4 -> V_6 = 1 ;
F_12 ( & V_4 -> V_5 ) ;
}
