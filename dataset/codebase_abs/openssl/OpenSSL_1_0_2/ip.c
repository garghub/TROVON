int F_1 ( void )
{
struct V_1 V_2 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = 0 ;
F_2 ( & V_2 . V_6 ) ;
if ( V_1 ( V_7 , & V_2 , NULL ) != 0 )
return 0 ;
return 1 ;
}
int F_3 ( const char * V_8 , unsigned short V_9 )
{
struct V_10 V_11 ;
int V_12 = - 1 ;
int V_13 = 1 ;
if ( ( V_12 = F_4 ( V_14 , V_15 , 0 ) ) == - 1 )
goto V_16;
if ( F_5 ( V_12 , V_17 , V_18 , ( char * ) ( & V_13 ) ,
sizeof( V_13 ) ) != 0 )
goto V_16;
V_11 . V_19 = V_20 ;
memcpy ( & V_11 . V_21 . V_22 , V_8 , 4 ) ;
V_11 . V_23 = F_6 ( V_9 ) ;
if ( F_7 ( V_12 , (struct V_24 * ) & V_11 , sizeof( struct V_10 ) ) !=
0 )
goto V_16;
if ( F_8 ( V_12 , V_25 ) != 0 )
goto V_16;
return V_12 ;
V_16:
if ( V_12 != - 1 )
F_9 ( V_12 ) ;
return - 1 ;
}
int F_10 ( const char * V_8 , unsigned short V_9 )
{
struct V_10 V_11 ;
int V_26 , V_12 = - 1 ;
if ( ( V_12 = F_4 ( V_14 , V_15 , 0 ) ) == - 1 )
goto V_16;
if ( ( ( V_26 = F_11 ( V_12 , V_27 , 0 ) ) < 0 ) ||
( F_11 ( V_12 , V_28 , V_26 | V_29 ) < 0 ) )
goto V_16;
V_11 . V_19 = V_20 ;
memcpy ( & V_11 . V_21 . V_22 , V_8 , 4 ) ;
V_11 . V_23 = F_6 ( V_9 ) ;
if ( ( F_12 ( V_12 , (struct V_24 * ) & V_11 ,
sizeof( struct V_10 ) ) != 0 ) && ( V_30 != V_31 ) )
goto V_16;
return V_12 ;
V_16:
if ( V_12 != - 1 )
F_9 ( V_12 ) ;
return - 1 ;
}
int F_13 ( const char * V_32 , const char * * V_33 ,
unsigned short * V_34 , int V_35 )
{
char V_36 [ 256 ] ;
struct V_37 * V_38 ;
unsigned long V_9 ;
const char * V_39 = strstr ( V_32 , L_1 ) ;
const char * V_8 = V_40 ;
if ( ! V_39 ) {
if ( ! V_35 )
return 0 ;
V_39 = V_32 ;
goto V_41;
}
if ( ( V_39 - V_32 ) > 255 )
return 0 ;
memset ( V_36 , 0 , 256 ) ;
memcpy ( V_36 , V_32 , V_39 - V_32 ) ;
V_39 ++ ;
if ( ( V_38 = F_14 ( V_36 ) ) == NULL ) {
fprintf ( V_42 , L_2 , V_36 ) ;
return 0 ;
}
V_8 = V_38 -> V_43 [ 0 ] ;
V_41:
if ( strlen ( V_39 ) < 1 )
return 0 ;
if ( ! F_15 ( V_39 , & V_9 ) || ( V_9 > 65535 ) )
return 0 ;
* V_33 = V_8 ;
* V_34 = ( unsigned short ) V_9 ;
return 1 ;
}
int F_16 ( const char * V_32 )
{
const char * V_8 ;
unsigned short V_9 ;
if ( ! F_13 ( V_32 , & V_8 , & V_9 , 1 ) )
return - 1 ;
return F_3 ( V_8 , V_9 ) ;
}
int F_17 ( const char * V_32 )
{
const char * V_8 ;
unsigned short V_9 ;
if ( ! F_13 ( V_32 , & V_8 , & V_9 , 0 ) )
return - 1 ;
return F_10 ( V_8 , V_9 ) ;
}
int F_18 ( int V_44 )
{
return F_19 ( V_44 , NULL , NULL ) ;
}
