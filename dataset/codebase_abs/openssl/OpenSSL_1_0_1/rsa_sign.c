int F_1 ( int type , const unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
T_3 V_7 ;
int V_8 , V_9 , V_10 = 1 ;
unsigned char * V_11 , * V_12 = NULL ;
const unsigned char * V_13 = NULL ;
T_4 V_14 ;
T_5 V_15 ;
#ifdef F_2
if ( F_3 () && ! ( V_5 -> V_16 -> V_17 & V_18 )
&& ! ( V_5 -> V_17 & V_19 ) )
{
F_4 ( V_20 , V_21 ) ;
return 0 ;
}
#endif
if( ( V_5 -> V_17 & V_22 ) && V_5 -> V_16 -> V_23 )
{
return V_5 -> V_16 -> V_23 ( type , V_1 , V_2 ,
V_3 , V_4 , V_5 ) ;
}
if( type == V_24 ) {
if( V_2 != V_25 ) {
F_4 ( V_20 , V_26 ) ;
return ( 0 ) ;
}
V_8 = V_25 ;
V_13 = V_1 ;
} else {
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_27 = F_5 ( type ) ;
if ( V_6 . V_14 -> V_27 == NULL )
{
F_4 ( V_20 , V_28 ) ;
return ( 0 ) ;
}
if ( V_6 . V_14 -> V_27 -> V_29 == 0 )
{
F_4 ( V_20 , V_30 ) ;
return ( 0 ) ;
}
V_7 . type = V_31 ;
V_7 . V_32 . V_33 = NULL ;
V_6 . V_14 -> V_7 = & V_7 ;
V_6 . V_15 = & V_15 ;
V_6 . V_15 -> V_34 = ( unsigned char * ) V_1 ;
V_6 . V_15 -> V_29 = V_2 ;
V_8 = F_6 ( & V_6 , NULL ) ;
}
V_9 = F_7 ( V_5 ) ;
if ( V_8 > ( V_9 - V_35 ) )
{
F_4 ( V_20 , V_36 ) ;
return ( 0 ) ;
}
if( type != V_24 ) {
V_12 = ( unsigned char * ) F_8 ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL )
{
F_4 ( V_20 , V_37 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_6 ( & V_6 , & V_11 ) ;
V_13 = V_12 ;
}
V_8 = F_9 ( V_8 , V_13 , V_3 , V_5 , V_38 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
if( type != V_24 ) {
F_10 ( V_12 , ( unsigned int ) V_9 + 1 ) ;
F_11 ( V_12 ) ;
}
return ( V_10 ) ;
}
int F_12 ( int V_39 , const unsigned char * V_1 ,
unsigned int V_2 ,
unsigned char * V_40 , T_6 * V_41 ,
const unsigned char * V_42 , T_6 V_4 ,
T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_43 ;
unsigned char * V_13 ;
T_2 * V_6 = NULL ;
#ifdef F_2
if ( F_3 () && ! ( V_5 -> V_16 -> V_17 & V_18 )
&& ! ( V_5 -> V_17 & V_19 ) )
{
F_4 ( V_44 , V_21 ) ;
return 0 ;
}
#endif
if ( V_4 != ( unsigned int ) F_7 ( V_5 ) )
{
F_4 ( V_44 , V_45 ) ;
return ( 0 ) ;
}
if( ( V_39 == V_24 ) && V_40 )
{
V_8 = F_13 ( ( int ) V_4 ,
V_42 , V_40 , V_5 , V_38 ) ;
if ( V_8 <= 0 )
return 0 ;
* V_41 = V_8 ;
return 1 ;
}
V_13 = ( unsigned char * ) F_8 ( ( unsigned int ) V_4 ) ;
if ( V_13 == NULL )
{
F_4 ( V_44 , V_37 ) ;
goto V_46;
}
if( ( V_39 == V_24 ) && ( V_2 != V_25 ) ) {
F_4 ( V_44 , V_26 ) ;
goto V_46;
}
V_8 = F_13 ( ( int ) V_4 , V_42 , V_13 , V_5 , V_38 ) ;
if ( V_8 <= 0 ) goto V_46;
if ( V_39 == V_47 && V_8 == 18 && V_13 [ 0 ] == 0x04 && V_13 [ 1 ] == 0x10 )
{
if ( V_40 )
{
memcpy ( V_40 , V_13 + 2 , 16 ) ;
* V_41 = 16 ;
V_10 = 1 ;
}
else if( memcmp ( V_1 , V_13 + 2 , 16 ) )
F_4 ( V_44 , V_48 ) ;
else
V_10 = 1 ;
}
if( V_39 == V_24 ) {
if( ( V_8 != V_25 ) || memcmp ( V_13 , V_1 , V_25 ) )
F_4 ( V_44 , V_48 ) ;
else V_10 = 1 ;
} else {
const unsigned char * V_11 = V_13 ;
V_6 = F_14 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL ) goto V_46;
if( V_11 != V_13 + V_8 )
{
F_4 ( V_44 , V_48 ) ;
goto V_46;
}
if( V_6 -> V_14 -> V_7
&& F_15 ( V_6 -> V_14 -> V_7 ) != V_31 )
{
F_4 ( V_44 , V_48 ) ;
goto V_46;
}
V_43 = F_16 ( V_6 -> V_14 -> V_27 ) ;
#ifdef F_17
fprintf ( V_49 , L_1 , F_18 ( V_43 ) ,
F_18 ( V_39 ) ) ;
#endif
if ( V_43 != V_39 )
{
if ( ( ( V_39 == V_50 ) &&
( V_43 == V_51 ) ) ||
( ( V_39 == V_52 ) &&
( V_43 == V_53 ) ) )
{
#if ! F_19 ( V_54 ) && ! F_19 ( V_55 )
fprintf ( V_49 , L_2 ) ;
#endif
}
else
{
F_4 ( V_44 ,
V_56 ) ;
goto V_46;
}
}
if ( V_40 )
{
const T_7 * V_57 ;
V_57 = F_20 ( V_39 ) ;
if ( V_57 && ( F_21 ( V_57 ) != V_6 -> V_15 -> V_29 ) )
F_4 ( V_44 ,
V_58 ) ;
else
{
memcpy ( V_40 , V_6 -> V_15 -> V_34 ,
V_6 -> V_15 -> V_29 ) ;
* V_41 = V_6 -> V_15 -> V_29 ;
V_10 = 1 ;
}
}
else if ( ( ( unsigned int ) V_6 -> V_15 -> V_29 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_15 -> V_34 , V_2 ) != 0 ) )
{
F_4 ( V_44 , V_48 ) ;
}
else
V_10 = 1 ;
}
V_46:
if ( V_6 != NULL ) F_22 ( V_6 ) ;
if ( V_13 != NULL )
{
F_10 ( V_13 , ( unsigned int ) V_4 ) ;
F_11 ( V_13 ) ;
}
return ( V_10 ) ;
}
int F_23 ( int V_39 , const unsigned char * V_1 , unsigned int V_2 ,
const unsigned char * V_42 , unsigned int V_4 ,
T_1 * V_5 )
{
if( ( V_5 -> V_17 & V_22 ) && V_5 -> V_16 -> V_59 )
{
return V_5 -> V_16 -> V_59 ( V_39 , V_1 , V_2 ,
V_42 , V_4 , V_5 ) ;
}
return F_12 ( V_39 , V_1 , V_2 , NULL , NULL , V_42 , V_4 , V_5 ) ;
}
