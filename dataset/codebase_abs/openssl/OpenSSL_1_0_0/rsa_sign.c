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
if( ( V_5 -> V_16 & V_17 ) && V_5 -> V_18 -> V_19 )
{
return V_5 -> V_18 -> V_19 ( type , V_1 , V_2 ,
V_3 , V_4 , V_5 ) ;
}
if( type == V_20 ) {
if( V_2 != V_21 ) {
F_2 ( V_22 , V_23 ) ;
return ( 0 ) ;
}
V_8 = V_21 ;
V_13 = V_1 ;
} else {
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_24 = F_3 ( type ) ;
if ( V_6 . V_14 -> V_24 == NULL )
{
F_2 ( V_22 , V_25 ) ;
return ( 0 ) ;
}
if ( V_6 . V_14 -> V_24 -> V_26 == 0 )
{
F_2 ( V_22 , V_27 ) ;
return ( 0 ) ;
}
V_7 . type = V_28 ;
V_7 . V_29 . V_30 = NULL ;
V_6 . V_14 -> V_7 = & V_7 ;
V_6 . V_15 = & V_15 ;
V_6 . V_15 -> V_31 = ( unsigned char * ) V_1 ;
V_6 . V_15 -> V_26 = V_2 ;
V_8 = F_4 ( & V_6 , NULL ) ;
}
V_9 = F_5 ( V_5 ) ;
if ( V_8 > ( V_9 - V_32 ) )
{
F_2 ( V_22 , V_33 ) ;
return ( 0 ) ;
}
if( type != V_20 ) {
V_12 = ( unsigned char * ) F_6 ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL )
{
F_2 ( V_22 , V_34 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_4 ( & V_6 , & V_11 ) ;
V_13 = V_12 ;
}
V_8 = F_7 ( V_8 , V_13 , V_3 , V_5 , V_35 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
if( type != V_20 ) {
F_8 ( V_12 , ( unsigned int ) V_9 + 1 ) ;
F_9 ( V_12 ) ;
}
return ( V_10 ) ;
}
int F_10 ( int V_36 , const unsigned char * V_1 ,
unsigned int V_2 ,
unsigned char * V_37 , T_6 * V_38 ,
const unsigned char * V_39 , T_6 V_4 ,
T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_40 ;
unsigned char * V_13 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_5 ( V_5 ) )
{
F_2 ( V_41 , V_42 ) ;
return ( 0 ) ;
}
if( ( V_36 == V_20 ) && V_37 )
{
V_8 = F_11 ( ( int ) V_4 ,
V_39 , V_37 , V_5 , V_35 ) ;
if ( V_8 <= 0 )
return 0 ;
* V_38 = V_8 ;
return 1 ;
}
V_13 = ( unsigned char * ) F_6 ( ( unsigned int ) V_4 ) ;
if ( V_13 == NULL )
{
F_2 ( V_41 , V_34 ) ;
goto V_43;
}
if( ( V_36 == V_20 ) && ( V_2 != V_21 ) ) {
F_2 ( V_41 , V_23 ) ;
goto V_43;
}
V_8 = F_11 ( ( int ) V_4 , V_39 , V_13 , V_5 , V_35 ) ;
if ( V_8 <= 0 ) goto V_43;
if( V_36 == V_20 ) {
if( ( V_8 != V_21 ) || memcmp ( V_13 , V_1 , V_21 ) )
F_2 ( V_41 , V_44 ) ;
else V_10 = 1 ;
} else {
const unsigned char * V_11 = V_13 ;
V_6 = F_12 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL ) goto V_43;
if( V_11 != V_13 + V_8 )
{
F_2 ( V_41 , V_44 ) ;
goto V_43;
}
if( V_6 -> V_14 -> V_7
&& F_13 ( V_6 -> V_14 -> V_7 ) != V_28 )
{
F_2 ( V_41 , V_44 ) ;
goto V_43;
}
V_40 = F_14 ( V_6 -> V_14 -> V_24 ) ;
#ifdef F_15
fprintf ( V_45 , L_1 , F_16 ( V_40 ) ,
F_16 ( V_36 ) ) ;
#endif
if ( V_40 != V_36 )
{
if ( ( ( V_36 == V_46 ) &&
( V_40 == V_47 ) ) ||
( ( V_36 == V_48 ) &&
( V_40 == V_49 ) ) )
{
#if ! F_17 ( V_50 ) && ! F_17 ( V_51 )
fprintf ( V_45 , L_2 ) ;
#endif
}
else
{
F_2 ( V_41 ,
V_52 ) ;
goto V_43;
}
}
if ( V_37 )
{
const T_7 * V_53 ;
V_53 = F_18 ( V_36 ) ;
if ( V_53 && ( F_19 ( V_53 ) != V_6 -> V_15 -> V_26 ) )
F_2 ( V_41 ,
V_54 ) ;
else
{
memcpy ( V_37 , V_6 -> V_15 -> V_31 ,
V_6 -> V_15 -> V_26 ) ;
* V_38 = V_6 -> V_15 -> V_26 ;
V_10 = 1 ;
}
}
else if ( ( ( unsigned int ) V_6 -> V_15 -> V_26 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_15 -> V_31 , V_2 ) != 0 ) )
{
F_2 ( V_41 , V_44 ) ;
}
else
V_10 = 1 ;
}
V_43:
if ( V_6 != NULL ) F_20 ( V_6 ) ;
if ( V_13 != NULL )
{
F_8 ( V_13 , ( unsigned int ) V_4 ) ;
F_9 ( V_13 ) ;
}
return ( V_10 ) ;
}
int F_21 ( int V_36 , const unsigned char * V_1 , unsigned int V_2 ,
const unsigned char * V_39 , unsigned int V_4 ,
T_1 * V_5 )
{
if( ( V_5 -> V_16 & V_17 ) && V_5 -> V_18 -> V_55 )
{
return V_5 -> V_18 -> V_55 ( V_36 , V_1 , V_2 ,
V_39 , V_4 , V_5 ) ;
}
return F_10 ( V_36 , V_1 , V_2 , NULL , NULL , V_39 , V_4 , V_5 ) ;
}
