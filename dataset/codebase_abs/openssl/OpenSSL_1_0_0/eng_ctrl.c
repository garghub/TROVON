static int F_1 ( const T_1 * V_1 )
{
if( ( V_1 -> V_2 == 0 ) || ( V_1 -> V_3 == NULL ) )
return 1 ;
return 0 ;
}
static int F_2 ( const T_1 * V_1 , const char * V_4 )
{
int V_5 = 0 ;
while( ! F_1 ( V_1 ) && ( strcmp ( V_1 -> V_3 , V_4 ) != 0 ) )
{
V_5 ++ ;
V_1 ++ ;
}
if( F_1 ( V_1 ) )
return - 1 ;
return V_5 ;
}
static int F_3 ( const T_1 * V_1 , unsigned int V_6 )
{
int V_5 = 0 ;
while( ! F_1 ( V_1 ) && ( V_1 -> V_2 < V_6 ) )
{
V_5 ++ ;
V_1 ++ ;
}
if( V_1 -> V_2 == V_6 )
return V_5 ;
return - 1 ;
}
static int F_4 ( T_2 * V_7 , int V_8 , long V_9 , void * V_10 ,
void (* F_5)( void ) )
{
int V_5 ;
char * V_4 = ( char * ) V_10 ;
if( V_8 == V_11 )
{
if( ( V_7 -> V_12 == NULL ) || F_1 ( V_7 -> V_12 ) )
return 0 ;
return V_7 -> V_12 -> V_2 ;
}
if( ( V_8 == V_13 ) ||
( V_8 == V_14 ) ||
( V_8 == V_15 ) )
{
if( V_4 == NULL )
{
F_6 ( V_16 ,
V_17 ) ;
return - 1 ;
}
}
if( V_8 == V_13 )
{
if( ( V_7 -> V_12 == NULL ) || ( ( V_5 = F_2 (
V_7 -> V_12 , V_4 ) ) < 0 ) )
{
F_6 ( V_16 ,
V_18 ) ;
return - 1 ;
}
return V_7 -> V_12 [ V_5 ] . V_2 ;
}
if( ( V_7 -> V_12 == NULL ) || ( ( V_5 = F_3 ( V_7 -> V_12 ,
( unsigned int ) V_9 ) ) < 0 ) )
{
F_6 ( V_16 ,
V_19 ) ;
return - 1 ;
}
switch( V_8 )
{
case V_20 :
V_5 ++ ;
if( F_1 ( V_7 -> V_12 + V_5 ) )
return 0 ;
else
return V_7 -> V_12 [ V_5 ] . V_2 ;
case V_21 :
return strlen ( V_7 -> V_12 [ V_5 ] . V_3 ) ;
case V_14 :
return F_7 ( V_4 , strlen ( V_7 -> V_12 [ V_5 ] . V_3 ) + 1 ,
L_1 , V_7 -> V_12 [ V_5 ] . V_3 ) ;
case V_22 :
if( V_7 -> V_12 [ V_5 ] . V_23 )
return strlen ( V_7 -> V_12 [ V_5 ] . V_23 ) ;
return strlen ( V_24 ) ;
case V_15 :
if( V_7 -> V_12 [ V_5 ] . V_23 )
return F_7 ( V_4 ,
strlen ( V_7 -> V_12 [ V_5 ] . V_23 ) + 1 ,
L_1 , V_7 -> V_12 [ V_5 ] . V_23 ) ;
return F_7 ( V_4 , strlen ( V_24 ) + 1 , L_1 ,
V_24 ) ;
case V_25 :
return V_7 -> V_12 [ V_5 ] . V_26 ;
}
F_6 ( V_16 , V_27 ) ;
return - 1 ;
}
int F_8 ( T_2 * V_7 , int V_8 , long V_9 , void * V_10 , void (* F_5)( void ) )
{
int V_28 , V_29 ;
if( V_7 == NULL )
{
F_6 ( V_30 , V_17 ) ;
return 0 ;
}
F_9 ( V_31 ) ;
V_29 = ( ( V_7 -> V_32 > 0 ) ? 1 : 0 ) ;
F_10 ( V_31 ) ;
V_28 = ( ( V_7 -> V_33 == NULL ) ? 0 : 1 ) ;
if( ! V_29 )
{
F_6 ( V_30 , V_34 ) ;
return 0 ;
}
switch( V_8 )
{
case V_35 :
return V_28 ;
case V_11 :
case V_20 :
case V_13 :
case V_21 :
case V_14 :
case V_22 :
case V_15 :
case V_25 :
if( V_28 && ! ( V_7 -> V_36 & V_37 ) )
return F_4 ( V_7 , V_8 , V_9 , V_10 , F_5 ) ;
if( ! V_28 )
{
F_6 ( V_30 , V_38 ) ;
return - 1 ;
}
default:
break;
}
if( ! V_28 )
{
F_6 ( V_30 , V_38 ) ;
return 0 ;
}
return V_7 -> V_33 ( V_7 , V_8 , V_9 , V_10 , F_5 ) ;
}
int F_11 ( T_2 * V_7 , int V_8 )
{
int V_36 ;
if( ( V_36 = F_8 ( V_7 , V_25 , V_8 , NULL , NULL ) ) < 0 )
{
F_6 ( V_39 ,
V_19 ) ;
return 0 ;
}
if( ! ( V_36 & V_40 ) &&
! ( V_36 & V_41 ) &&
! ( V_36 & V_42 ) )
return 0 ;
return 1 ;
}
int F_12 ( T_2 * V_7 , const char * V_3 ,
long V_9 , void * V_10 , void (* F_5)( void ) , int V_43 )
{
int V_6 ;
if( ( V_7 == NULL ) || ( V_3 == NULL ) )
{
F_6 ( V_44 ,
V_17 ) ;
return 0 ;
}
if( ( V_7 -> V_33 == NULL ) || ( ( V_6 = F_8 ( V_7 ,
V_13 ,
0 , ( void * ) V_3 , NULL ) ) <= 0 ) )
{
if( V_43 )
{
F_13 () ;
return 1 ;
}
F_6 ( V_44 ,
V_18 ) ;
return 0 ;
}
if ( F_8 ( V_7 , V_6 , V_9 , V_10 , F_5 ) > 0 )
return 1 ;
return 0 ;
}
int F_14 ( T_2 * V_7 , const char * V_3 , const char * V_45 ,
int V_43 )
{
int V_6 , V_36 ;
long V_46 ;
char * V_47 ;
if( ( V_7 == NULL ) || ( V_3 == NULL ) )
{
F_6 ( V_48 ,
V_17 ) ;
return 0 ;
}
if( ( V_7 -> V_33 == NULL ) || ( ( V_6 = F_8 ( V_7 ,
V_13 ,
0 , ( void * ) V_3 , NULL ) ) <= 0 ) )
{
if( V_43 )
{
F_13 () ;
return 1 ;
}
F_6 ( V_48 ,
V_18 ) ;
return 0 ;
}
if( ! F_11 ( V_7 , V_6 ) )
{
F_6 ( V_48 ,
V_49 ) ;
return 0 ;
}
if( ( V_36 = F_8 ( V_7 , V_25 , V_6 , NULL , NULL ) ) < 0 )
{
F_6 ( V_48 ,
V_27 ) ;
return 0 ;
}
if( V_36 & V_40 )
{
if( V_45 != NULL )
{
F_6 ( V_48 ,
V_50 ) ;
return 0 ;
}
if( F_8 ( V_7 , V_6 , 0 , ( void * ) V_45 , NULL ) > 0 )
return 1 ;
return 0 ;
}
if( V_45 == NULL )
{
F_6 ( V_48 ,
V_51 ) ;
return 0 ;
}
if( V_36 & V_42 )
{
if( F_8 ( V_7 , V_6 , 0 , ( void * ) V_45 , NULL ) > 0 )
return 1 ;
return 0 ;
}
if( ! ( V_36 & V_41 ) )
{
F_6 ( V_48 ,
V_27 ) ;
return 0 ;
}
V_46 = strtol ( V_45 , & V_47 , 10 ) ;
if( ( V_45 == V_47 ) || ( * V_47 != '\0' ) )
{
F_6 ( V_48 ,
V_52 ) ;
return 0 ;
}
if( F_8 ( V_7 , V_6 , V_46 , NULL , NULL ) > 0 )
return 1 ;
return 0 ;
}
