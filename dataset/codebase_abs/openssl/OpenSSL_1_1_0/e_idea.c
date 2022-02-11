static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( V_3 + V_5 , V_2 + V_5 , & F_4 ( V_6 , V_1 ) -> V_7 ) ;
return 1 ;
}
static int F_5 ( T_1 * V_1 , const unsigned char * V_8 ,
const unsigned char * V_9 , int V_10 )
{
if ( ! V_10 ) {
if ( F_6 ( V_1 ) == V_11 )
V_10 = 1 ;
else if ( F_6 ( V_1 ) == V_12 )
V_10 = 1 ;
}
if ( V_10 )
F_7 ( V_8 , & F_4 ( V_6 , V_1 ) -> V_7 ) ;
else {
T_3 V_13 ;
F_7 ( V_8 , & V_13 ) ;
F_8 ( & V_13 , & F_4 ( V_6 , V_1 ) -> V_7 ) ;
F_9 ( ( unsigned char * ) & V_13 , sizeof( T_3 ) ) ;
}
return 1 ;
}
