static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long V_5 )
{
const struct V_6 * V_7 = V_6 ;
for (; V_7 -> V_5 != ~ 0UL ; ++ V_7 ) {
if ( V_5 <= V_7 -> V_5 )
break;
}
if ( V_7 -> V_5 == ~ 0UL )
return - V_8 ;
F_2 ( V_2 , V_7 -> V_9 ,
V_10 ) ;
F_2 ( V_2 , V_7 -> V_11 ,
V_12 ) ;
F_2 ( V_2 , V_7 -> div , V_13 ) ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 )
{
return F_4 ( V_15 , & V_16 ) ;
}
static int F_5 ( struct V_14 * V_15 )
{
F_6 ( V_15 ) ;
return 0 ;
}
