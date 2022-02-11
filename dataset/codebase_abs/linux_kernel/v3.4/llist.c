bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 ;
V_6 = V_5 -> V_8 ;
for (; ; ) {
V_7 = V_6 ;
V_3 -> V_9 = V_6 ;
V_6 = F_2 ( & V_5 -> V_8 , V_7 , V_2 ) ;
if ( V_6 == V_7 )
break;
}
return V_7 == NULL ;
}
struct V_1 * F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 , * V_9 ;
V_6 = V_5 -> V_8 ;
for (; ; ) {
if ( V_6 == NULL )
return NULL ;
V_7 = V_6 ;
V_9 = V_6 -> V_9 ;
V_6 = F_2 ( & V_5 -> V_8 , V_7 , V_9 ) ;
if ( V_6 == V_7 )
break;
}
return V_6 ;
}
