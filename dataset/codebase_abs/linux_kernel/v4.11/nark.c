static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! V_3 ) {
F_2 ( V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_5 = NULL ;
F_2 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
V_2 -> V_7 = F_3 ( V_2 -> V_8 , 2 ) ;
V_2 -> V_4 . V_5 = F_4 ( ( V_9 ) F_3 ( V_2 -> V_8 , 0 ) |
( ( V_9 ) F_3 ( V_2 -> V_8 , 1 ) << 32 ) ,
sizeof( struct V_10 ) - sizeof( struct V_11 ) ) ;
V_2 -> V_6 = NULL ;
if ( V_2 -> V_4 . V_5 == NULL )
return - 1 ;
V_2 -> V_6 = F_4 ( V_2 -> V_7 , V_3 ) ;
if ( V_2 -> V_6 == NULL ) {
F_2 ( V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_5 = NULL ;
return - 1 ;
}
V_2 -> V_12 = & ( (struct V_10 V_13 * ) V_2 -> V_6 ) -> V_12 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_15 = F_1 ;
V_2 -> V_14 . V_16 = V_17 ;
return F_6 ( V_2 ) ;
}
