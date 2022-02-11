T_1 * F_1 ( char * V_1 , int (* F_2)() , int V_2 ,
int V_3 )
{
T_2 * V_4 ;
T_1 * V_5 ;
if ( ! ( V_4 = F_3 () ) ) {
F_4 ( V_6 , V_7 ) ;
return NULL ;
}
V_4 -> type = F_5 ( V_2 ) ;
if ( ! F_6 ( V_1 , F_2 , & V_4 -> V_8 . V_9 ) ) {
F_4 ( V_6 , V_7 ) ;
return NULL ;
}
if ( ! ( V_5 = F_7 () ) ) {
F_4 ( V_6 , V_7 ) ;
return NULL ;
}
V_5 -> V_8 . V_4 = V_4 ;
V_5 -> type = F_5 ( V_3 ) ;
return V_5 ;
}
T_1 * F_8 ( T_3 * V_10 )
{
T_1 * V_4 ;
if ( ! ( V_4 = F_7 () ) ) {
F_4 ( V_11 , V_7 ) ;
return NULL ;
}
V_4 -> type = F_5 ( V_12 ) ;
V_4 -> V_8 . V_13 = V_10 ;
return V_4 ;
}
T_1 * F_9 ( int V_14 , const char * V_15 ,
int V_16 , unsigned char * V_17 , int V_18 , int V_19 ,
T_3 * V_10 )
{
T_1 * V_4 ;
if ( ! ( V_4 = F_7 () ) ) {
F_4 ( V_20 , V_7 ) ;
return NULL ;
}
V_4 -> type = F_5 ( V_21 ) ;
if ( ! ( V_4 -> V_8 . V_22 =
F_10 ( V_14 , NULL , V_15 , V_16 , V_17 , V_18 , V_19 ,
V_10 ) ) ) {
F_4 ( V_20 , V_7 ) ;
return NULL ;
}
return V_4 ;
}
T_4 * F_10 ( int V_14 , const T_5 * V_23 ,
const char * V_15 , int V_16 ,
unsigned char * V_17 , int V_18 , int V_19 ,
T_3 * V_24 )
{
T_4 * V_10 ;
T_6 * V_25 ;
if ( ! ( V_10 = F_11 () ) ) {
F_4 ( V_26 , V_7 ) ;
goto V_27;
}
if( V_14 == - 1 ) V_25 = F_12 ( V_23 , V_19 , V_17 , V_18 ) ;
else V_25 = F_13 ( V_14 , V_19 , V_17 , V_18 ) ;
if( ! V_25 ) {
F_4 ( V_26 , V_28 ) ;
goto V_27;
}
F_14 ( V_10 -> V_29 ) ;
V_10 -> V_29 = V_25 ;
F_15 ( V_10 -> V_30 ) ;
if ( ! ( V_10 -> V_30 =
F_16 ( V_25 , V_31 , V_15 , V_16 ,
( char * ) V_24 , 0 ) ) ) {
F_4 ( V_26 , V_32 ) ;
goto V_27;
}
return V_10 ;
V_27:
F_17 ( V_10 ) ;
return NULL ;
}
