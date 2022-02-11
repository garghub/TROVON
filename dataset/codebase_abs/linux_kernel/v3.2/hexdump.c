int F_1 ( char V_1 )
{
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return V_1 - '0' ;
V_1 = tolower ( V_1 ) ;
if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return V_1 - 'a' + 10 ;
return - 1 ;
}
int F_2 ( T_1 * V_2 , const char * V_3 , T_2 V_4 )
{
while ( V_4 -- ) {
int V_5 = F_1 ( * V_3 ++ ) ;
int V_6 = F_1 ( * V_3 ++ ) ;
if ( ( V_5 < 0 ) || ( V_6 < 0 ) )
return - 1 ;
* V_2 ++ = ( V_5 << 4 ) | V_6 ;
}
return 0 ;
}
void F_3 ( const void * V_7 , T_2 V_8 , int V_9 ,
int V_10 , char * V_11 , T_2 V_12 ,
bool V_13 )
{
const T_1 * V_14 = V_7 ;
T_1 V_1 ;
int V_15 , V_16 = 0 ;
int V_17 ;
if ( V_9 != 16 && V_9 != 32 )
V_9 = 16 ;
if ( ! V_8 )
goto V_18;
if ( V_8 > V_9 )
V_8 = V_9 ;
if ( ( V_8 % V_10 ) != 0 )
V_10 = 1 ;
switch ( V_10 ) {
case 8 : {
const T_3 * V_19 = V_7 ;
int V_20 = V_8 / V_10 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ )
V_16 += F_4 ( V_11 + V_16 , V_12 - V_16 ,
L_1 , V_15 ? L_2 : L_3 ,
( unsigned long long ) * ( V_19 + V_15 ) ) ;
V_17 = 17 * V_20 + 2 ;
break;
}
case 4 : {
const T_4 * V_21 = V_7 ;
int V_20 = V_8 / V_10 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ )
V_16 += F_4 ( V_11 + V_16 , V_12 - V_16 ,
L_4 , V_15 ? L_2 : L_3 , * ( V_21 + V_15 ) ) ;
V_17 = 9 * V_20 + 2 ;
break;
}
case 2 : {
const T_5 * V_22 = V_7 ;
int V_20 = V_8 / V_10 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ )
V_16 += F_4 ( V_11 + V_16 , V_12 - V_16 ,
L_5 , V_15 ? L_2 : L_3 , * ( V_22 + V_15 ) ) ;
V_17 = 5 * V_20 + 2 ;
break;
}
default:
for ( V_15 = 0 ; ( V_15 < V_8 ) && ( V_16 + 3 ) <= V_12 ; V_15 ++ ) {
V_1 = V_14 [ V_15 ] ;
V_11 [ V_16 ++ ] = F_5 ( V_1 ) ;
V_11 [ V_16 ++ ] = F_6 ( V_1 ) ;
V_11 [ V_16 ++ ] = ' ' ;
}
if ( V_15 )
V_16 -- ;
V_17 = 3 * V_9 + 2 ;
break;
}
if ( ! V_13 )
goto V_18;
while ( V_16 < ( V_12 - 1 ) && V_16 < ( V_17 - 1 ) )
V_11 [ V_16 ++ ] = ' ' ;
for ( V_15 = 0 ; ( V_15 < V_8 ) && ( V_16 + 2 ) < V_12 ; V_15 ++ ) {
V_1 = V_14 [ V_15 ] ;
V_11 [ V_16 ++ ] = ( isascii ( V_1 ) && isprint ( V_1 ) ) ? V_1 : '.' ;
}
V_18:
V_11 [ V_16 ++ ] = '\0' ;
}
void F_7 ( const char * V_23 , const char * V_24 , int V_25 ,
int V_9 , int V_10 ,
const void * V_7 , T_2 V_8 , bool V_13 )
{
const T_1 * V_14 = V_7 ;
int V_26 , V_27 , V_28 = V_8 ;
unsigned char V_11 [ 32 * 3 + 2 + 32 + 1 ] ;
if ( V_9 != 16 && V_9 != 32 )
V_9 = 16 ;
for ( V_26 = 0 ; V_26 < V_8 ; V_26 += V_9 ) {
V_27 = F_8 ( V_28 , V_9 ) ;
V_28 -= V_9 ;
F_3 ( V_14 + V_26 , V_27 , V_9 , V_10 ,
V_11 , sizeof( V_11 ) , V_13 ) ;
switch ( V_25 ) {
case V_29 :
F_9 ( L_6 ,
V_23 , V_24 , V_14 + V_26 , V_11 ) ;
break;
case V_30 :
F_9 ( L_7 , V_23 , V_24 , V_26 , V_11 ) ;
break;
default:
F_9 ( L_8 , V_23 , V_24 , V_11 ) ;
break;
}
}
}
void F_10 ( const char * V_24 , int V_25 ,
const void * V_7 , T_2 V_8 )
{
F_7 ( V_31 , V_24 , V_25 , 16 , 1 ,
V_7 , V_8 , true ) ;
}
