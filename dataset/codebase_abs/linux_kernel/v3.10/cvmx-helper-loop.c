int F_1 ( int V_1 )
{
union V_2 V_3 ;
int V_4 = 4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
union V_6 V_7 ;
int V_8 = F_2 ( V_1 , V_5 ) ;
V_7 . V_9 = F_3 ( F_4 ( V_8 ) ) ;
V_7 . V_10 . V_11 = 0 ;
V_7 . V_10 . V_12 = 0 ;
F_5 ( F_4 ( V_8 ) , V_7 . V_9 ) ;
}
V_3 . V_9 = F_3 ( V_13 ) ;
V_3 . V_10 . V_14 = 0 ;
F_5 ( V_13 , V_3 . V_9 ) ;
return V_4 ;
}
int F_6 ( int V_1 )
{
return 0 ;
}
