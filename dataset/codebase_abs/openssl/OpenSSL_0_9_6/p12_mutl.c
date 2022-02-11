int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 ,
unsigned char * V_4 , unsigned int * V_5 )
{
const T_2 * V_6 ;
T_3 V_7 ;
unsigned char V_8 [ V_9 ] , * V_10 ;
int V_11 , V_12 ;
V_10 = V_1 -> V_4 -> V_10 -> V_13 ;
V_11 = V_1 -> V_4 -> V_10 -> V_14 ;
if ( ! V_1 -> V_4 -> V_12 ) V_12 = 1 ;
else V_12 = F_2 ( V_1 -> V_4 -> V_12 ) ;
if( ! ( V_6 =
F_3 ( V_1 -> V_4 -> V_15 -> V_16 -> V_17 ) ) ) {
F_4 ( V_18 , V_19 ) ;
return 0 ;
}
if( ! F_5 ( V_2 , V_3 , V_10 , V_11 , V_20 , V_12 ,
V_9 , V_8 , V_6 ) ) {
F_4 ( V_18 , V_21 ) ;
return 0 ;
}
F_6 ( & V_7 , V_8 , V_9 , V_6 ) ;
F_7 ( & V_7 , V_1 -> V_22 -> V_23 . V_13 -> V_13 ,
V_1 -> V_22 -> V_23 . V_13 -> V_14 ) ;
F_8 ( & V_7 , V_4 , V_5 ) ;
return 1 ;
}
int F_9 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
unsigned char V_4 [ V_24 ] ;
unsigned int V_5 ;
if( V_1 -> V_4 == NULL ) {
F_4 ( V_25 , V_26 ) ;
return 0 ;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , & V_5 ) ) {
F_4 ( V_25 , V_27 ) ;
return 0 ;
}
if ( ( V_5 != ( unsigned int ) V_1 -> V_4 -> V_15 -> V_28 -> V_14 )
|| memcmp ( V_4 , V_1 -> V_4 -> V_15 -> V_28 -> V_13 , V_5 ) ) return 0 ;
return 1 ;
}
int F_10 ( T_1 * V_1 , const char * V_2 , int V_3 ,
unsigned char * V_10 , int V_11 , int V_12 , T_2 * V_6 )
{
unsigned char V_4 [ V_24 ] ;
unsigned int V_5 ;
if ( ! V_6 ) V_6 = F_11 () ;
if ( F_12 ( V_1 , V_12 , V_10 , V_11 , V_6 ) ==
V_29 ) {
F_4 ( V_30 , V_31 ) ;
return 0 ;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , & V_5 ) ) {
F_4 ( V_30 , V_27 ) ;
return 0 ;
}
if ( ! ( F_13 ( V_1 -> V_4 -> V_15 -> V_28 , V_4 , V_5 ) ) ) {
F_4 ( V_30 , V_32 ) ;
return 0 ;
}
return 1 ;
}
int F_12 ( T_1 * V_1 , int V_12 , unsigned char * V_10 , int V_11 ,
T_2 * V_6 )
{
if ( ! ( V_1 -> V_4 = F_14 () ) ) return V_29 ;
if ( V_12 > 1 ) {
if( ! ( V_1 -> V_4 -> V_12 = F_15 () ) ) {
F_4 ( V_33 , V_34 ) ;
return 0 ;
}
F_16 ( V_1 -> V_4 -> V_12 , V_12 ) ;
}
if ( ! V_11 ) V_11 = V_35 ;
V_1 -> V_4 -> V_10 -> V_14 = V_11 ;
if ( ! ( V_1 -> V_4 -> V_10 -> V_13 = F_17 ( V_11 ) ) ) {
F_4 ( V_33 , V_34 ) ;
return 0 ;
}
if ( ! V_10 ) {
if ( F_18 ( V_1 -> V_4 -> V_10 -> V_13 , V_11 ) < 0 )
return 0 ;
}
else memcpy ( V_1 -> V_4 -> V_10 -> V_13 , V_10 , V_11 ) ;
V_1 -> V_4 -> V_15 -> V_16 -> V_17 = F_19 ( F_20 ( V_6 ) ) ;
if ( ! ( V_1 -> V_4 -> V_15 -> V_16 -> V_36 = F_21 () ) ) {
F_4 ( V_33 , V_34 ) ;
return 0 ;
}
V_1 -> V_4 -> V_15 -> V_16 -> V_36 -> type = V_37 ;
return 1 ;
}
