int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 ,
unsigned char * V_4 , int V_5 , int V_6 , T_2 * V_7 ,
int V_8 )
{
T_3 * V_9 , V_10 ;
unsigned char V_11 [ V_12 ] , V_13 [ V_14 ] ;
int V_15 ;
V_10 . V_16 = F_2 ( V_1 ) ;
if ( V_10 . V_16 != V_17 ) V_15 = F_3 ( V_18 , ( char * ) & V_10 ) ;
else V_15 = - 1 ;
if ( V_15 == - 1 ) {
char V_19 [ 80 ] ;
F_4 ( V_20 , V_21 ) ;
if ( ! V_1 ) strcpy ( V_19 , L_1 ) ;
else F_5 ( V_19 , 80 , V_1 ) ;
F_6 ( 2 , L_2 , V_19 ) ;
return 0 ;
}
if ( V_3 == - 1 ) V_3 = strlen ( V_2 ) ;
V_9 = ( T_3 * ) F_7 ( V_18 , V_15 ) ;
V_15 = (* V_9 -> V_22 )( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_9 -> V_23 , V_9 -> V_24 , V_11 , V_13 ) ;
if ( ! V_15 ) {
F_4 ( V_20 , V_25 ) ;
return 0 ;
}
F_8 ( V_7 , V_9 -> V_23 , V_11 , V_13 , V_8 ) ;
return 1 ;
}
int F_9 ( T_4 * V_26 , const char * V_2 ,
int V_3 , T_2 * V_7 , int V_8 )
{
T_5 * V_27 ;
int V_5 , V_6 ;
unsigned char * V_4 , * V_28 ;
V_28 = V_26 -> V_29 -> V_30 . V_31 -> V_32 ;
if ( ! ( V_27 = F_10 ( NULL , & V_28 ,
V_26 -> V_29 -> V_30 . V_31 -> V_33 ) ) ) {
F_4 ( V_34 , V_35 ) ;
return 0 ;
}
if ( ! V_27 -> V_6 ) V_6 = 1 ;
else V_6 = F_11 ( V_27 -> V_6 ) ;
V_4 = V_27 -> V_4 -> V_32 ;
V_5 = V_27 -> V_4 -> V_33 ;
if ( ! ( F_1 ( V_26 -> V_36 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 ) ) ) {
F_4 ( V_34 , V_37 ) ;
F_12 ( V_27 ) ;
return 0 ;
}
F_12 ( V_27 ) ;
return 1 ;
}
static int F_13 ( T_3 * * V_38 , T_3 * * V_39 )
{
return ( ( * V_38 ) -> V_16 - ( * V_39 ) -> V_16 ) ;
}
int F_14 ( int V_40 , T_6 * V_23 , T_7 * V_24 ,
T_8 * V_22 )
{
T_3 * V_41 ;
if ( ! V_18 ) V_18 = F_15 ( F_13 ) ;
if ( ! ( V_41 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ) ) {
F_4 ( V_42 , V_43 ) ;
return 0 ;
}
V_41 -> V_16 = V_40 ;
V_41 -> V_23 = V_23 ;
V_41 -> V_24 = V_24 ;
V_41 -> V_22 = V_22 ;
F_16 ( V_18 , ( char * ) V_41 ) ;
return 1 ;
}
void F_17 ( void )
{
F_18 ( V_18 , V_44 ) ;
V_18 = NULL ;
}
