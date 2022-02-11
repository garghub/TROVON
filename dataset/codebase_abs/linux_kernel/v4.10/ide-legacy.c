static void F_1 ( struct V_1 * * V_2 , struct V_1 * V_3 ,
T_1 V_4 , const struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
if ( V_4 == 0 ) {
V_8 = 0x1f0 ;
V_9 = 0x3f6 ;
V_10 = 14 ;
} else {
V_8 = 0x170 ;
V_9 = 0x376 ;
V_10 = 15 ;
}
if ( ! F_2 ( V_8 , 8 , V_6 -> V_11 ) ) {
F_3 ( V_12 L_1 ,
V_6 -> V_11 , V_8 , V_8 + 7 ) ;
return;
}
if ( ! F_2 ( V_9 , 1 , V_6 -> V_11 ) ) {
F_3 ( V_12 L_2 ,
V_6 -> V_11 , V_9 ) ;
F_4 ( V_8 , 8 ) ;
return;
}
F_5 ( V_3 , V_8 , V_9 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_7 = V_7 ;
V_2 [ V_4 ] = V_3 ;
}
int F_6 ( const struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 V_3 [ 2 ] , * V_2 [] = { NULL , NULL } ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
if ( ( V_6 -> V_13 & V_14 ) == 0 )
F_1 ( V_2 , & V_3 [ 0 ] , 0 , V_6 , V_7 ) ;
F_1 ( V_2 , & V_3 [ 1 ] , 1 , V_6 , V_7 ) ;
if ( V_2 [ 0 ] == NULL && V_2 [ 1 ] == NULL &&
( V_6 -> V_13 & V_15 ) )
return - V_16 ;
return F_7 ( V_6 , V_2 , 2 , NULL ) ;
}
