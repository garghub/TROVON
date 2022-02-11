int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
T_2 V_3 ;
T_3 V_4 ;
unsigned char V_5 [ 2 ] ;
T_3 V_6 , V_7 , V_8 ;
#ifndef F_2
T_3 V_9 ;
unsigned char V_10 ;
#endif
T_3 V_11 , V_12 ;
#ifndef F_3
T_3 V_13 ;
#endif
#ifndef F_4
T_3 V_14 , V_15 ;
#endif
long V_16 ;
if ( ( V_1 == NULL ) || ( ( V_1 -> V_4 == NULL ) && ( V_1 -> V_17 == 0 ) ) )
return 0 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_18 = V_19 ;
V_3 . V_20 = V_1 -> V_20 ;
if ( V_1 -> V_4 == NULL )
V_16 = V_1 -> V_17 ;
else
V_16 = V_1 -> V_4 -> V_21 ;
V_5 [ 0 ] = ( ( unsigned char ) ( V_16 >> 8L ) ) & 0xff ;
V_5 [ 1 ] = ( ( unsigned char ) ( V_16 ) ) & 0xff ;
F_5 ( & V_3 . V_4 , & V_4 , V_5 , 2 ) ;
#ifndef F_2
if ( V_1 -> V_22 ) {
V_10 = ( unsigned char ) V_1 -> V_22 ;
F_5 ( & V_3 . V_9 , & V_9 , & V_10 , 1 ) ;
}
#endif
F_5 ( & V_3 . V_6 , & V_6 ,
V_1 -> V_6 , V_1 -> V_23 ) ;
F_5 ( & V_3 . V_7 , & V_7 ,
V_1 -> V_7 , V_1 -> V_24 ) ;
F_5 ( & V_3 . V_25 , & V_8 ,
V_1 -> V_8 , V_1 -> V_26 ) ;
V_3 . time = V_1 -> time ;
V_3 . V_27 = V_1 -> V_27 ;
V_3 . V_28 = V_1 -> V_28 ;
V_3 . V_29 = V_1 -> V_29 ;
F_6 ( & V_3 . V_11 , & V_11 ,
V_1 -> V_11 ) ;
if ( V_1 -> V_12 ) {
F_5 ( & V_3 . V_12 , & V_12 ,
V_1 -> V_12 , V_1 -> V_30 ) ;
}
if ( V_1 -> V_31 > 0 )
V_3 . V_31 = V_1 -> V_31 ;
#ifndef F_4
F_6 ( & V_3 . V_15 , & V_15 ,
V_1 -> V_15 ) ;
F_6 ( & V_3 . V_14 , & V_14 , V_1 -> V_14 ) ;
#endif
#ifndef F_3
F_6 ( & V_3 . V_13 , & V_13 , V_1 -> V_13 ) ;
#endif
V_3 . V_32 = V_1 -> V_32 ;
return F_7 ( & V_3 , V_2 ) ;
}
static int F_8 ( char * * V_33 , T_3 * V_34 )
{
F_9 ( * V_33 ) ;
* V_33 = NULL ;
if ( V_34 == NULL )
return 1 ;
* V_33 = F_10 ( ( char * ) V_34 -> V_35 , V_34 -> V_36 ) ;
if ( * V_33 == NULL )
return 0 ;
return 1 ;
}
static int F_11 ( unsigned char * V_37 , unsigned int * V_38 ,
T_3 * V_34 , int V_39 )
{
if ( V_34 == NULL ) {
* V_38 = 0 ;
return 1 ;
}
if ( V_34 -> V_36 > V_39 )
return 0 ;
memcpy ( V_37 , V_34 -> V_35 , V_34 -> V_36 ) ;
* V_38 = V_34 -> V_36 ;
return 1 ;
}
T_1 * F_12 ( T_1 * * V_40 , const unsigned char * * V_2 ,
long V_36 )
{
long V_21 ;
unsigned int V_41 ;
const unsigned char * V_42 = * V_2 ;
T_2 * V_3 = NULL ;
T_1 * V_43 = NULL ;
V_3 = F_13 ( NULL , & V_42 , V_36 ) ;
if ( V_3 == NULL )
goto V_44;
if ( ! V_40 || ! * V_40 ) {
V_43 = F_14 () ;
if ( V_43 == NULL )
goto V_44;
} else {
V_43 = * V_40 ;
}
if ( V_3 -> V_18 != V_19 ) {
F_15 ( V_45 , V_46 ) ;
goto V_44;
}
if ( ( V_3 -> V_20 >> 8 ) != V_47
&& ( V_3 -> V_20 >> 8 ) != V_48
&& V_3 -> V_20 != V_49 ) {
F_15 ( V_45 , V_50 ) ;
goto V_44;
}
V_43 -> V_20 = ( int ) V_3 -> V_20 ;
if ( V_3 -> V_4 -> V_36 != 2 ) {
F_15 ( V_45 , V_51 ) ;
goto V_44;
}
V_42 = V_3 -> V_4 -> V_35 ;
V_21 = 0x03000000L | ( ( unsigned long ) V_42 [ 0 ] << 8L ) | ( unsigned long ) V_42 [ 1 ] ;
V_43 -> V_4 = NULL ;
V_43 -> V_17 = V_21 ;
if ( ! F_11 ( V_43 -> V_7 , & V_43 -> V_24 ,
V_3 -> V_7 , V_52 ) )
goto V_44;
if ( ! F_11 ( V_43 -> V_6 , & V_41 ,
V_3 -> V_6 , V_53 ) )
goto V_44;
V_43 -> V_23 = V_41 ;
if ( V_3 -> time != 0 )
V_43 -> time = V_3 -> time ;
else
V_43 -> time = ( unsigned long ) time ( NULL ) ;
if ( V_3 -> V_27 != 0 )
V_43 -> V_27 = V_3 -> V_27 ;
else
V_43 -> V_27 = 3 ;
F_16 ( V_43 -> V_29 ) ;
V_43 -> V_29 = V_3 -> V_29 ;
V_3 -> V_29 = NULL ;
if ( ! F_11 ( V_43 -> V_8 , & V_43 -> V_26 ,
V_3 -> V_25 , V_54 ) )
goto V_44;
V_43 -> V_28 = V_3 -> V_28 ;
if ( ! F_8 ( & V_43 -> V_11 , V_3 -> V_11 ) )
goto V_44;
#ifndef F_4
if ( ! F_8 ( & V_43 -> V_15 , V_3 -> V_15 ) )
goto V_44;
if ( ! F_8 ( & V_43 -> V_14 , V_3 -> V_14 ) )
goto V_44;
#endif
V_43 -> V_31 = V_3 -> V_31 ;
if ( V_3 -> V_12 ) {
V_43 -> V_12 = V_3 -> V_12 -> V_35 ;
V_43 -> V_30 = V_3 -> V_12 -> V_36 ;
V_3 -> V_12 -> V_35 = NULL ;
} else {
V_43 -> V_12 = NULL ;
}
#ifndef F_2
if ( V_3 -> V_9 ) {
if ( V_3 -> V_9 -> V_36 != 1 ) {
F_15 ( V_45 , V_55 ) ;
goto V_44;
}
V_43 -> V_22 = V_3 -> V_9 -> V_35 [ 0 ] ;
} else {
V_43 -> V_22 = 0 ;
}
#endif
#ifndef F_3
if ( ! F_8 ( & V_43 -> V_13 , V_3 -> V_13 ) )
goto V_44;
#endif
V_43 -> V_32 = V_3 -> V_32 ;
F_17 ( V_3 , T_2 ) ;
if ( ( V_40 != NULL ) && ( * V_40 == NULL ) )
* V_40 = V_43 ;
* V_2 = V_42 ;
return V_43 ;
V_44:
F_17 ( V_3 , T_2 ) ;
if ( ( V_40 == NULL ) || ( * V_40 != V_43 ) )
F_18 ( V_43 ) ;
return NULL ;
}
