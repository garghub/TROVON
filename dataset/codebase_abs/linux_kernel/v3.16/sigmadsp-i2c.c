static int F_1 ( void * V_1 ,
const struct V_2 * V_3 , T_1 V_4 )
{
return F_2 ( V_1 , ( const unsigned char * ) & V_3 -> V_5 ,
V_4 ) ;
}
int F_3 ( struct V_6 * V_7 , const char * V_8 )
{
struct V_9 V_10 ;
V_10 . V_1 = V_7 ;
V_10 . V_11 = F_1 ;
return F_4 ( & V_7 -> V_12 , & V_10 , V_8 ) ;
}
