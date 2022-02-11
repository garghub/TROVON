int F_1 ( char V_1 )
{
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return V_1 - '0' ;
V_1 = tolower ( V_1 ) ;
if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return V_1 - 'a' + 10 ;
return - 1 ;
}
void F_2 ( T_1 * V_2 , const char * V_3 , T_2 V_4 )
{
while ( V_4 -- ) {
* V_2 = F_1 ( * V_3 ++ ) << 4 ;
* V_2 += F_1 ( * V_3 ++ ) ;
V_2 ++ ;
}
}
void F_3 ( const void * V_5 , T_2 V_6 , int V_7 ,
int V_8 , char * V_9 , T_2 V_10 ,
bool V_11 )
{
const T_1 * V_12 = V_5 ;
T_1 V_1 ;
int V_13 , V_14 = 0 ;
int V_15 ;
if ( V_7 != 16 && V_7 != 32 )
V_7 = 16 ;
if ( ! V_6 )
goto V_16;
if ( V_6 > V_7 )
V_6 = V_7 ;
if ( ( V_6 % V_8 ) != 0 )
V_8 = 1 ;
switch ( V_8 ) {
case 8 : {
const T_3 * V_17 = V_5 ;
int V_18 = V_6 / V_8 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ )
V_14 += F_4 ( V_9 + V_14 , V_10 - V_14 ,
L_1 , V_13 ? L_2 : L_3 ,
( unsigned long long ) * ( V_17 + V_13 ) ) ;
V_15 = 17 * V_18 + 2 ;
break;
}
case 4 : {
const T_4 * V_19 = V_5 ;
int V_18 = V_6 / V_8 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ )
V_14 += F_4 ( V_9 + V_14 , V_10 - V_14 ,
L_4 , V_13 ? L_2 : L_3 , * ( V_19 + V_13 ) ) ;
V_15 = 9 * V_18 + 2 ;
break;
}
case 2 : {
const T_5 * V_20 = V_5 ;
int V_18 = V_6 / V_8 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ )
V_14 += F_4 ( V_9 + V_14 , V_10 - V_14 ,
L_5 , V_13 ? L_2 : L_3 , * ( V_20 + V_13 ) ) ;
V_15 = 5 * V_18 + 2 ;
break;
}
default:
for ( V_13 = 0 ; ( V_13 < V_6 ) && ( V_14 + 3 ) <= V_10 ; V_13 ++ ) {
V_1 = V_12 [ V_13 ] ;
V_9 [ V_14 ++ ] = F_5 ( V_1 ) ;
V_9 [ V_14 ++ ] = F_6 ( V_1 ) ;
V_9 [ V_14 ++ ] = ' ' ;
}
if ( V_13 )
V_14 -- ;
V_15 = 3 * V_7 + 2 ;
break;
}
if ( ! V_11 )
goto V_16;
while ( V_14 < ( V_10 - 1 ) && V_14 < ( V_15 - 1 ) )
V_9 [ V_14 ++ ] = ' ' ;
for ( V_13 = 0 ; ( V_13 < V_6 ) && ( V_14 + 2 ) < V_10 ; V_13 ++ ) {
V_1 = V_12 [ V_13 ] ;
V_9 [ V_14 ++ ] = ( isascii ( V_1 ) && isprint ( V_1 ) ) ? V_1 : '.' ;
}
V_16:
V_9 [ V_14 ++ ] = '\0' ;
}
void F_7 ( const char * V_21 , const char * V_22 , int V_23 ,
int V_7 , int V_8 ,
const void * V_5 , T_2 V_6 , bool V_11 )
{
const T_1 * V_12 = V_5 ;
int V_24 , V_25 , V_26 = V_6 ;
unsigned char V_9 [ 32 * 3 + 2 + 32 + 1 ] ;
if ( V_7 != 16 && V_7 != 32 )
V_7 = 16 ;
for ( V_24 = 0 ; V_24 < V_6 ; V_24 += V_7 ) {
V_25 = F_8 ( V_26 , V_7 ) ;
V_26 -= V_7 ;
F_3 ( V_12 + V_24 , V_25 , V_7 , V_8 ,
V_9 , sizeof( V_9 ) , V_11 ) ;
switch ( V_23 ) {
case V_27 :
F_9 ( L_6 ,
V_21 , V_22 , V_12 + V_24 , V_9 ) ;
break;
case V_28 :
F_9 ( L_7 , V_21 , V_22 , V_24 , V_9 ) ;
break;
default:
F_9 ( L_8 , V_21 , V_22 , V_9 ) ;
break;
}
}
}
void F_10 ( const char * V_22 , int V_23 ,
const void * V_5 , T_2 V_6 )
{
F_7 ( V_29 , V_22 , V_23 , 16 , 1 ,
V_5 , V_6 , true ) ;
}
