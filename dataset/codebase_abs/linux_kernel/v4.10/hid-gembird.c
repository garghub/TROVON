static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
T_1 * V_5 ;
T_2 V_6 = sizeof( V_7 ) -
sizeof( V_8 ) ;
T_2 V_9 = * V_4 + V_6 ;
if ( * V_4 >= 31 && ! memcmp ( & V_3 [ V_10 ] ,
V_8 ,
sizeof( V_8 ) ) ) {
V_5 = F_2 ( & V_2 -> V_11 , V_9 , V_12 ) ;
if ( V_5 == NULL )
return V_3 ;
F_3 ( & V_2 -> V_11 ,
L_1 ) ;
memcpy ( V_5 + V_6 , V_3 , * V_4 ) ;
memcpy ( V_5 , V_3 , V_10 ) ;
memcpy ( V_5 + V_10 ,
V_7 ,
sizeof( V_7 ) ) ;
* V_4 = V_9 ;
V_3 = V_5 ;
}
return V_3 ;
}
