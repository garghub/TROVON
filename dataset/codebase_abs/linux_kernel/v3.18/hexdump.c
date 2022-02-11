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
char * F_3 ( char * V_2 , const void * V_3 , T_2 V_4 )
{
const unsigned char * V_7 = V_3 ;
while ( V_4 -- )
V_2 = F_4 ( V_2 , * V_7 ++ ) ;
return V_2 ;
}
void F_5 ( const void * V_8 , T_2 V_9 , int V_10 ,
int V_11 , char * V_12 , T_2 V_13 ,
bool V_14 )
{
const T_1 * V_15 = V_8 ;
T_1 V_1 ;
int V_16 , V_17 = 0 ;
int V_18 ;
if ( V_10 != 16 && V_10 != 32 )
V_10 = 16 ;
if ( ! V_9 )
goto V_19;
if ( V_9 > V_10 )
V_9 = V_10 ;
if ( ( V_9 % V_11 ) != 0 )
V_11 = 1 ;
switch ( V_11 ) {
case 8 : {
const T_3 * V_20 = V_8 ;
int V_21 = V_9 / V_11 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ )
V_17 += F_6 ( V_12 + V_17 , V_13 - V_17 ,
L_1 , V_16 ? L_2 : L_3 ,
( unsigned long long ) * ( V_20 + V_16 ) ) ;
V_18 = 17 * V_21 + 2 ;
break;
}
case 4 : {
const T_4 * V_22 = V_8 ;
int V_21 = V_9 / V_11 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ )
V_17 += F_6 ( V_12 + V_17 , V_13 - V_17 ,
L_4 , V_16 ? L_2 : L_3 , * ( V_22 + V_16 ) ) ;
V_18 = 9 * V_21 + 2 ;
break;
}
case 2 : {
const T_5 * V_23 = V_8 ;
int V_21 = V_9 / V_11 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ )
V_17 += F_6 ( V_12 + V_17 , V_13 - V_17 ,
L_5 , V_16 ? L_2 : L_3 , * ( V_23 + V_16 ) ) ;
V_18 = 5 * V_21 + 2 ;
break;
}
default:
for ( V_16 = 0 ; ( V_16 < V_9 ) && ( V_17 + 3 ) <= V_13 ; V_16 ++ ) {
V_1 = V_15 [ V_16 ] ;
V_12 [ V_17 ++ ] = F_7 ( V_1 ) ;
V_12 [ V_17 ++ ] = F_8 ( V_1 ) ;
V_12 [ V_17 ++ ] = ' ' ;
}
if ( V_16 )
V_17 -- ;
V_18 = 3 * V_10 + 2 ;
break;
}
if ( ! V_14 )
goto V_19;
while ( V_17 < ( V_13 - 1 ) && V_17 < ( V_18 - 1 ) )
V_12 [ V_17 ++ ] = ' ' ;
for ( V_16 = 0 ; ( V_16 < V_9 ) && ( V_17 + 2 ) < V_13 ; V_16 ++ ) {
V_1 = V_15 [ V_16 ] ;
V_12 [ V_17 ++ ] = ( isascii ( V_1 ) && isprint ( V_1 ) ) ? V_1 : '.' ;
}
V_19:
V_12 [ V_17 ++ ] = '\0' ;
}
void F_9 ( const char * V_24 , const char * V_25 , int V_26 ,
int V_10 , int V_11 ,
const void * V_8 , T_2 V_9 , bool V_14 )
{
const T_1 * V_15 = V_8 ;
int V_27 , V_28 , V_29 = V_9 ;
unsigned char V_12 [ 32 * 3 + 2 + 32 + 1 ] ;
if ( V_10 != 16 && V_10 != 32 )
V_10 = 16 ;
for ( V_27 = 0 ; V_27 < V_9 ; V_27 += V_10 ) {
V_28 = F_10 ( V_29 , V_10 ) ;
V_29 -= V_10 ;
F_5 ( V_15 + V_27 , V_28 , V_10 , V_11 ,
V_12 , sizeof( V_12 ) , V_14 ) ;
switch ( V_26 ) {
case V_30 :
F_11 ( L_6 ,
V_24 , V_25 , V_15 + V_27 , V_12 ) ;
break;
case V_31 :
F_11 ( L_7 , V_24 , V_25 , V_27 , V_12 ) ;
break;
default:
F_11 ( L_8 , V_24 , V_25 , V_12 ) ;
break;
}
}
}
void F_12 ( const char * V_25 , int V_26 ,
const void * V_8 , T_2 V_9 )
{
F_9 ( V_32 , V_25 , V_26 , 16 , 1 ,
V_8 , V_9 , true ) ;
}
