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
int F_5 ( const void * V_8 , T_2 V_9 , int V_10 , int V_11 ,
char * V_12 , T_2 V_13 , bool V_14 )
{
const T_1 * V_15 = V_8 ;
int V_16 ;
T_1 V_1 ;
int V_17 , V_18 = 0 ;
int V_19 ;
int V_20 ;
if ( V_10 != 16 && V_10 != 32 )
V_10 = 16 ;
if ( V_9 > V_10 )
V_9 = V_10 ;
if ( ! F_6 ( V_11 ) || V_11 > 8 )
V_11 = 1 ;
if ( ( V_9 % V_11 ) != 0 )
V_11 = 1 ;
V_16 = V_9 / V_11 ;
V_19 = V_10 * 2 + V_10 / V_11 + 1 ;
if ( ! V_13 )
goto V_21;
if ( ! V_9 )
goto V_22;
if ( V_11 == 8 ) {
const T_3 * V_23 = V_8 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_20 = snprintf ( V_12 + V_18 , V_13 - V_18 ,
L_1 , V_17 ? L_2 : L_3 ,
F_7 ( V_23 + V_17 ) ) ;
if ( V_20 >= V_13 - V_18 )
goto V_21;
V_18 += V_20 ;
}
} else if ( V_11 == 4 ) {
const T_4 * V_24 = V_8 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_20 = snprintf ( V_12 + V_18 , V_13 - V_18 ,
L_4 , V_17 ? L_2 : L_3 ,
F_7 ( V_24 + V_17 ) ) ;
if ( V_20 >= V_13 - V_18 )
goto V_21;
V_18 += V_20 ;
}
} else if ( V_11 == 2 ) {
const T_5 * V_25 = V_8 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_20 = snprintf ( V_12 + V_18 , V_13 - V_18 ,
L_5 , V_17 ? L_2 : L_3 ,
F_7 ( V_25 + V_17 ) ) ;
if ( V_20 >= V_13 - V_18 )
goto V_21;
V_18 += V_20 ;
}
} else {
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ ) {
if ( V_13 < V_18 + 2 )
goto V_26;
V_1 = V_15 [ V_17 ] ;
V_12 [ V_18 ++ ] = F_8 ( V_1 ) ;
if ( V_13 < V_18 + 2 )
goto V_26;
V_12 [ V_18 ++ ] = F_9 ( V_1 ) ;
if ( V_13 < V_18 + 2 )
goto V_26;
V_12 [ V_18 ++ ] = ' ' ;
}
if ( V_17 )
V_18 -- ;
}
if ( ! V_14 )
goto V_22;
while ( V_18 < V_19 ) {
if ( V_13 < V_18 + 2 )
goto V_26;
V_12 [ V_18 ++ ] = ' ' ;
}
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ ) {
if ( V_13 < V_18 + 2 )
goto V_26;
V_1 = V_15 [ V_17 ] ;
V_12 [ V_18 ++ ] = ( isascii ( V_1 ) && isprint ( V_1 ) ) ? V_1 : '.' ;
}
V_22:
V_12 [ V_18 ] = '\0' ;
return V_18 ;
V_26:
V_12 [ V_18 ++ ] = '\0' ;
V_21:
return V_14 ? V_19 + V_9 : ( V_11 * 2 + 1 ) * V_16 - 1 ;
}
void F_10 ( const char * V_27 , const char * V_28 , int V_29 ,
int V_10 , int V_11 ,
const void * V_8 , T_2 V_9 , bool V_14 )
{
const T_1 * V_15 = V_8 ;
int V_30 , V_31 , V_32 = V_9 ;
unsigned char V_12 [ 32 * 3 + 2 + 32 + 1 ] ;
if ( V_10 != 16 && V_10 != 32 )
V_10 = 16 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 += V_10 ) {
V_31 = F_11 ( V_32 , V_10 ) ;
V_32 -= V_10 ;
F_5 ( V_15 + V_30 , V_31 , V_10 , V_11 ,
V_12 , sizeof( V_12 ) , V_14 ) ;
switch ( V_29 ) {
case V_33 :
F_12 ( L_6 ,
V_27 , V_28 , V_15 + V_30 , V_12 ) ;
break;
case V_34 :
F_12 ( L_7 , V_27 , V_28 , V_30 , V_12 ) ;
break;
default:
F_12 ( L_8 , V_27 , V_28 , V_12 ) ;
break;
}
}
}
void F_13 ( const char * V_28 , int V_29 ,
const void * V_8 , T_2 V_9 )
{
F_10 ( V_35 , V_28 , V_29 , 16 , 1 ,
V_8 , V_9 , true ) ;
}
