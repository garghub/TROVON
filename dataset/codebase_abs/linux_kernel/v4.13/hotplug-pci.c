int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_7 , V_8 = V_4 -> V_9 . V_8 ;
int V_10 = V_4 -> V_9 . V_10 ;
for ( V_7 = V_8 ; V_7 <= V_10 ; V_7 ++ ) {
if ( ! F_2 ( F_3 ( V_4 ) , V_7 ) )
break;
}
if ( V_7 -- > V_10 ) {
F_4 ( V_11 L_1 ,
F_5 ( V_2 ) ) ;
return - 1 ;
}
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
V_7 = F_6 ( V_4 , V_2 , V_7 , V_6 ) ;
if ( ! V_2 -> V_12 )
return - 1 ;
return 0 ;
}
