int F_1 ( const void * V_1 )
{
if ( F_2 ( V_1 ) == V_2 ) {
if ( F_3 ( V_1 ) < V_3 )
return - V_4 ;
if ( F_4 ( V_1 ) > V_5 )
return - V_4 ;
} else if ( F_2 ( V_1 ) == V_6 ) {
if ( F_5 ( V_1 ) == 0 )
return - V_7 ;
} else {
return - V_8 ;
}
return 0 ;
}
const void * F_6 ( const void * V_1 , int V_9 , int V_10 )
{
const char * V_11 ;
if ( F_3 ( V_1 ) >= 0x11 )
if ( ( ( V_9 + V_10 ) < V_9 )
|| ( ( V_9 + V_10 ) > F_5 ( V_1 ) ) )
return NULL ;
V_11 = F_7 ( V_1 , V_9 ) ;
if ( V_11 + V_10 < V_11 )
return NULL ;
return V_11 ;
}
T_1 F_8 ( const void * V_1 , int V_9 , int * V_12 )
{
const T_1 * V_13 , * V_14 ;
T_1 V_15 ;
const char * V_11 ;
if ( V_9 % V_16 )
return - 1 ;
V_13 = F_6 ( V_1 , V_9 , V_16 ) ;
if ( ! V_13 )
return V_17 ;
V_15 = F_9 ( * V_13 ) ;
V_9 += V_16 ;
switch ( V_15 ) {
case V_18 :
do {
V_11 = F_6 ( V_1 , V_9 ++ , 1 ) ;
} while ( V_11 && ( * V_11 != '\0' ) );
if ( ! V_11 )
return V_17 ;
break;
case V_19 :
V_14 = F_6 ( V_1 , V_9 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return V_17 ;
V_9 += 2 * V_16 + F_9 ( * V_14 ) ;
break;
}
if ( V_12 )
* V_12 = F_10 ( V_9 ) ;
return V_15 ;
}
int F_11 ( const void * V_1 , int V_9 )
{
if ( ( V_9 < 0 ) || ( V_9 % V_16 )
|| ( F_8 ( V_1 , V_9 , & V_9 ) != V_18 ) )
return - V_20 ;
return V_9 ;
}
int F_12 ( const void * V_1 , int V_9 , int * V_21 )
{
int V_12 = 0 ;
T_1 V_15 ;
if ( V_9 >= 0 )
if ( ( V_12 = F_11 ( V_1 , V_9 ) ) < 0 )
return V_12 ;
do {
V_9 = V_12 ;
V_15 = F_8 ( V_1 , V_9 , & V_12 ) ;
switch ( V_15 ) {
case V_19 :
case V_22 :
break;
case V_18 :
if ( V_21 )
( * V_21 ) ++ ;
break;
case V_23 :
if ( V_21 )
( * V_21 ) -- ;
break;
case V_17 :
return - V_24 ;
default:
return - V_25 ;
}
} while ( V_15 != V_18 );
return V_9 ;
}
const char * F_13 ( const char * V_26 , int V_27 , const char * V_28 )
{
int V_10 = strlen ( V_28 ) + 1 ;
const char * V_29 = V_26 + V_27 - V_10 ;
const char * V_11 ;
for ( V_11 = V_26 ; V_11 <= V_29 ; V_11 ++ )
if ( memcmp ( V_11 , V_28 , V_10 ) == 0 )
return V_11 ;
return NULL ;
}
int F_14 ( const void * V_1 , void * V_30 , int V_31 )
{
F_15 ( V_1 ) ;
if ( F_16 ( V_1 ) > V_31 )
return - V_32 ;
memmove ( V_30 , V_1 , F_16 ( V_1 ) ) ;
return 0 ;
}
