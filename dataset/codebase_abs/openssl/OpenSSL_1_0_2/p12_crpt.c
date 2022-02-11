void F_1 ( void )
{
}
int F_2 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , const T_3 * V_5 ,
const T_4 * V_6 , int V_7 )
{
T_5 * V_8 ;
int V_9 , V_10 , V_11 ;
unsigned char * V_12 ;
const unsigned char * V_13 ;
unsigned char V_14 [ V_15 ] , V_16 [ V_17 ] ;
if ( V_4 == NULL || V_4 -> type != V_18 ||
V_4 -> V_19 . V_20 == NULL ) {
F_3 ( V_21 , V_22 ) ;
return 0 ;
}
V_13 = V_4 -> V_19 . V_20 -> V_23 ;
if ( ! ( V_8 = F_4 ( NULL , & V_13 , V_4 -> V_19 . V_20 -> V_24 ) ) ) {
F_3 ( V_21 , V_22 ) ;
return 0 ;
}
if ( ! V_8 -> V_10 )
V_10 = 1 ;
else
V_10 = F_5 ( V_8 -> V_10 ) ;
V_12 = V_8 -> V_12 -> V_23 ;
V_9 = V_8 -> V_12 -> V_24 ;
if ( ! F_6 ( V_2 , V_3 , V_12 , V_9 , V_25 ,
V_10 , F_7 ( V_5 ) , V_14 , V_6 ) ) {
F_3 ( V_21 , V_26 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
if ( ! F_6 ( V_2 , V_3 , V_12 , V_9 , V_27 ,
V_10 , F_9 ( V_5 ) , V_16 , V_6 ) ) {
F_3 ( V_21 , V_28 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
F_8 ( V_8 ) ;
V_11 = F_10 ( V_1 , V_5 , NULL , V_14 , V_16 , V_7 ) ;
F_11 ( V_14 , V_15 ) ;
F_11 ( V_16 , V_17 ) ;
return V_11 ;
}
