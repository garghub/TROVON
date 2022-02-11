T_1 *
F_1 ( char const * V_1 )
{
int V_2 = 0 ;
T_2 type , V_3 ;
T_1 * V_4 ;
T_2 V_5 ;
T_2 V_6 =
V_7 |
V_8 |
V_9 |
V_10 |
V_11 | V_12 ;
if ( V_13 == 0 )
{
T_3 V_14 = F_2 ( L_1 ) ;
if ( ! V_14 )
{
F_3 ( L_2 ) ;
return NULL ;
}
V_5 = F_4 ( 0 ) ;
if ( V_5 != V_15 ) {
F_3 ( L_3 , V_5 ) ;
return NULL ;
}
V_13 = F_5 ( L_4 , V_16 ,
NULL , NULL , 0 ) ;
if( V_13 == NULL ) {
F_3 ( L_5 , F_6 () ) ;
return NULL ;
}
}
V_4 = F_7 ( sizeof( T_1 ) ) ;
V_4 -> V_17 = F_8 ( V_13 , V_1 , NULL , 0 , V_6 , 0 ) ;
V_18:
#if 0
if (net_user && net_passwd)
{
InternetSetOption (connection, INTERNET_OPTION_USERNAME,
net_user, strlen (net_user));
InternetSetOption (connection, INTERNET_OPTION_PASSWORD,
net_passwd, strlen (net_passwd));
}
#endif
#if 0
if (net_proxy_user && net_proxy_passwd)
{
InternetSetOption (connection, INTERNET_OPTION_PROXY_USERNAME,
net_proxy_user, strlen (net_proxy_user));
InternetSetOption (connection, INTERNET_OPTION_PROXY_PASSWORD,
net_proxy_passwd, strlen (net_proxy_passwd));
}
#endif
if ( V_2 )
if ( ! F_9 ( V_4 -> V_17 , 0 , 0 , 0 , 0 ) )
V_4 -> V_17 = 0 ;
if ( ! V_4 -> V_17 )
{
switch( F_6 () ) {
case V_19 :
{
char V_20 [ 2000 ] ;
T_2 V_21 , V_22 = sizeof ( V_20 ) ;
F_10 ( & V_21 , V_20 , & V_22 ) ;
F_11 ( 0 , V_20 , L_6 , 0 ) ;
}
break;
case V_23 :
F_3 ( L_7 ) ;
break;
case V_24 :
F_3 ( L_8 ) ;
break;
default:
F_3 ( L_9 , F_6 () ) ;
}
return NULL ;
}
V_3 = sizeof ( type ) ;
F_12 ( V_4 -> V_17 , V_25 ,
& type , & V_3 ) ;
switch ( type )
{
case V_26 :
case V_27 :
V_3 = sizeof ( T_2 ) ;
if ( F_13 ( V_4 -> V_17 ,
V_28 | V_29 ,
& type , & V_3 , NULL ) )
{
if ( type == 401 )
{
F_14 ( V_4 ) ;
V_2 = 1 ;
goto V_18;
}
else if ( type == 407 )
{
F_14 ( V_4 ) ;
V_2 = 1 ;
goto V_18;
}
else if ( type >= 300 )
{
F_3 ( L_10 , type ) ;
F_15 ( V_4 ) ;
return NULL ;
}
}
}
return V_4 ;
}
void
F_14 ( T_1 * V_30 )
{
T_2 V_31 = 0 ;
char V_20 [ 1024 ] ;
do
{
F_16 ( V_30 -> V_17 , V_20 , 1024 , & V_31 ) ;
}
while ( V_31 > 0 );
}
void
F_17 ( T_1 * V_30 )
{
if ( V_30 -> V_17 )
F_18 ( V_30 -> V_17 ) ;
F_15 ( V_30 ) ;
}
int
F_19 ( T_1 * V_30 )
{
return ( V_30 -> V_17 == NULL ) ? 0 : 1 ;
}
int
F_20 ( T_1 * V_30 , char * V_20 , int V_32 )
{
T_2 V_31 ;
if ( F_16 ( V_30 -> V_17 , V_20 , V_32 , & V_31 ) )
return V_31 ;
return - 1 ;
}
