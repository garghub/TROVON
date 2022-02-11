T_1 * F_1 ( void * V_1 , const T_2 * V_2 , int V_3 ,
int V_4 )
{
T_3 * V_5 ;
T_1 * V_6 ;
if ( ! ( V_5 = F_2 () ) ) {
F_3 ( V_7 , V_8 ) ;
return NULL ;
}
V_5 -> type = F_4 ( V_3 ) ;
if ( ! F_5 ( V_1 , V_2 , & V_5 -> V_9 . V_10 ) ) {
F_3 ( V_7 , V_8 ) ;
return NULL ;
}
if ( ! ( V_6 = F_6 () ) ) {
F_3 ( V_7 , V_8 ) ;
return NULL ;
}
V_6 -> V_9 . V_5 = V_5 ;
V_6 -> type = F_4 ( V_4 ) ;
return V_6 ;
}
T_1 * F_7 ( T_4 * V_11 )
{
T_1 * V_5 ;
if ( ! ( V_5 = F_6 () ) ) {
F_3 ( V_12 , V_8 ) ;
return NULL ;
}
V_5 -> type = F_4 ( V_13 ) ;
V_5 -> V_9 . V_14 = V_11 ;
return V_5 ;
}
T_1 * F_8 ( int V_15 , const char * V_16 ,
int V_17 , unsigned char * V_18 , int V_19 , int V_20 ,
T_4 * V_11 )
{
T_1 * V_5 ;
if ( ! ( V_5 = F_6 () ) ) {
F_3 ( V_21 , V_8 ) ;
return NULL ;
}
V_5 -> type = F_4 ( V_22 ) ;
if ( ! ( V_5 -> V_9 . V_23 =
F_9 ( V_15 , NULL , V_16 , V_17 , V_18 , V_19 , V_20 ,
V_11 ) ) ) {
F_3 ( V_21 , V_8 ) ;
return NULL ;
}
return V_5 ;
}
