bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
do {
V_3 -> V_7 = V_6 = F_2 ( V_5 -> V_6 ) ;
} while ( F_3 ( & V_5 -> V_6 , V_6 , V_2 ) != V_6 );
return ! V_6 ;
}
struct V_1 * F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_8 , * V_9 , * V_7 ;
V_8 = V_5 -> V_6 ;
for (; ; ) {
if ( V_8 == NULL )
return NULL ;
V_9 = V_8 ;
V_7 = V_8 -> V_7 ;
V_8 = F_3 ( & V_5 -> V_6 , V_9 , V_7 ) ;
if ( V_8 == V_9 )
break;
}
return V_8 ;
}
struct V_1 * F_5 ( struct V_1 * V_5 )
{
struct V_1 * V_10 = NULL ;
while ( V_5 ) {
struct V_1 * V_11 = V_5 ;
V_5 = V_5 -> V_7 ;
V_11 -> V_7 = V_10 ;
V_10 = V_11 ;
}
return V_10 ;
}
