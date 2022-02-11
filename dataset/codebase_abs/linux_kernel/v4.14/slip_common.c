int F_1 ( int V_1 , void * V_2 , int V_3 , struct V_4 * V_5 )
{
int V_6 , V_7 , V_8 , V_9 ;
if( V_5 -> V_10 > 0 ) {
V_6 = 0 ;
while( V_6 < V_5 -> V_10 ) {
V_8 = F_2 ( V_5 -> V_11 [ V_6 ++ ] , V_5 -> V_11 ,
& V_5 -> V_12 , & V_5 -> V_13 ) ;
if( V_8 ) {
memcpy ( V_2 , V_5 -> V_11 , V_8 ) ;
memmove ( V_5 -> V_11 , & V_5 -> V_11 [ V_6 ] ,
V_5 -> V_10 - V_6 ) ;
V_5 -> V_10 = V_5 -> V_10 - V_6 ;
return V_8 ;
}
}
V_5 -> V_10 = 0 ;
}
V_7 = F_3 ( V_1 , & V_5 -> V_11 [ V_5 -> V_12 ] ,
sizeof( V_5 -> V_11 ) - V_5 -> V_12 ) ;
if( V_7 <= 0 )
return V_7 ;
V_9 = V_5 -> V_12 ;
for( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_8 = F_2 ( V_5 -> V_11 [ V_9 + V_6 ] , V_5 -> V_11 , & V_5 -> V_12 ,
& V_5 -> V_13 ) ;
if( V_8 ) {
memcpy ( V_2 , V_5 -> V_11 , V_8 ) ;
memmove ( V_5 -> V_11 , & V_5 -> V_11 [ V_9 + V_6 + 1 ] ,
V_7 - ( V_6 + 1 ) ) ;
V_5 -> V_10 = V_7 - ( V_6 + 1 ) ;
return V_8 ;
}
}
return 0 ;
}
int F_4 ( int V_1 , void * V_2 , int V_3 , struct V_4 * V_5 )
{
int V_14 , V_7 ;
V_14 = F_5 ( V_2 , V_5 -> V_15 , V_3 ) ;
V_7 = F_6 ( V_1 , V_5 -> V_15 , V_14 ) ;
if( V_7 < 0 )
return V_7 ;
else return V_3 ;
}
