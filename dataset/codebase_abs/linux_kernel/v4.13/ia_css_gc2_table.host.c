void
F_1 ( void )
{
#if F_2 ( V_1 )
V_2 . V_3 = V_4 ;
V_5 . V_3 = V_4 ;
V_6 . V_3 = V_4 ;
memcpy ( V_2 . V_7 . V_8 , V_9 ,
sizeof( V_9 ) ) ;
memcpy ( V_5 . V_7 . V_8 , V_9 ,
sizeof( V_9 ) ) ;
memcpy ( V_6 . V_7 . V_8 , V_9 ,
sizeof( V_9 ) ) ;
#else
memcpy ( V_2 . V_7 . V_10 , V_9 ,
sizeof( V_9 ) ) ;
memcpy ( V_5 . V_7 . V_10 , V_9 ,
sizeof( V_9 ) ) ;
memcpy ( V_6 . V_7 . V_10 , V_9 ,
sizeof( V_9 ) ) ;
V_2 . V_3 = V_11 ;
V_5 . V_3 = V_11 ;
V_6 . V_3 = V_11 ;
#endif
}
