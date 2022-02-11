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
return - V_7 ;
* V_2 ++ = ( V_5 << 4 ) | V_6 ;
}
return 0 ;
}
char * F_3 ( char * V_2 , const void * V_3 , T_2 V_4 )
{
const unsigned char * V_8 = V_3 ;
while ( V_4 -- )
V_2 = F_4 ( V_2 , * V_8 ++ ) ;
return V_2 ;
}
int F_5 ( const void * V_9 , T_2 V_10 , int V_11 , int V_12 ,
char * V_13 , T_2 V_14 , bool V_15 )
{
const T_1 * V_16 = V_9 ;
int V_17 ;
T_1 V_1 ;
int V_18 , V_19 = 0 ;
int V_20 ;
int V_21 ;
if ( V_11 != 16 && V_11 != 32 )
V_11 = 16 ;
if ( V_10 > V_11 )
V_10 = V_11 ;
if ( ! F_6 ( V_12 ) || V_12 > 8 )
V_12 = 1 ;
if ( ( V_10 % V_12 ) != 0 )
V_12 = 1 ;
V_17 = V_10 / V_12 ;
V_20 = V_11 * 2 + V_11 / V_12 + 1 ;
if ( ! V_14 )
goto V_22;
if ( ! V_10 )
goto V_23;
if ( V_12 == 8 ) {
const T_3 * V_24 = V_9 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_21 = snprintf ( V_13 + V_19 , V_14 - V_19 ,
L_1 , V_18 ? L_2 : L_3 ,
F_7 ( V_24 + V_18 ) ) ;
if ( V_21 >= V_14 - V_19 )
goto V_22;
V_19 += V_21 ;
}
} else if ( V_12 == 4 ) {
const T_4 * V_25 = V_9 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_21 = snprintf ( V_13 + V_19 , V_14 - V_19 ,
L_4 , V_18 ? L_2 : L_3 ,
F_7 ( V_25 + V_18 ) ) ;
if ( V_21 >= V_14 - V_19 )
goto V_22;
V_19 += V_21 ;
}
} else if ( V_12 == 2 ) {
const T_5 * V_26 = V_9 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_21 = snprintf ( V_13 + V_19 , V_14 - V_19 ,
L_5 , V_18 ? L_2 : L_3 ,
F_7 ( V_26 + V_18 ) ) ;
if ( V_21 >= V_14 - V_19 )
goto V_22;
V_19 += V_21 ;
}
} else {
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
if ( V_14 < V_19 + 2 )
goto V_27;
V_1 = V_16 [ V_18 ] ;
V_13 [ V_19 ++ ] = F_8 ( V_1 ) ;
if ( V_14 < V_19 + 2 )
goto V_27;
V_13 [ V_19 ++ ] = F_9 ( V_1 ) ;
if ( V_14 < V_19 + 2 )
goto V_27;
V_13 [ V_19 ++ ] = ' ' ;
}
if ( V_18 )
V_19 -- ;
}
if ( ! V_15 )
goto V_23;
while ( V_19 < V_20 ) {
if ( V_14 < V_19 + 2 )
goto V_27;
V_13 [ V_19 ++ ] = ' ' ;
}
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
if ( V_14 < V_19 + 2 )
goto V_27;
V_1 = V_16 [ V_18 ] ;
V_13 [ V_19 ++ ] = ( isascii ( V_1 ) && isprint ( V_1 ) ) ? V_1 : '.' ;
}
V_23:
V_13 [ V_19 ] = '\0' ;
return V_19 ;
V_27:
V_13 [ V_19 ++ ] = '\0' ;
V_22:
return V_15 ? V_20 + V_10 : ( V_12 * 2 + 1 ) * V_17 - 1 ;
}
void F_10 ( const char * V_28 , const char * V_29 , int V_30 ,
int V_11 , int V_12 ,
const void * V_9 , T_2 V_10 , bool V_15 )
{
const T_1 * V_16 = V_9 ;
int V_31 , V_32 , V_33 = V_10 ;
unsigned char V_13 [ 32 * 3 + 2 + 32 + 1 ] ;
if ( V_11 != 16 && V_11 != 32 )
V_11 = 16 ;
for ( V_31 = 0 ; V_31 < V_10 ; V_31 += V_11 ) {
V_32 = F_11 ( V_33 , V_11 ) ;
V_33 -= V_11 ;
F_5 ( V_16 + V_31 , V_32 , V_11 , V_12 ,
V_13 , sizeof( V_13 ) , V_15 ) ;
switch ( V_30 ) {
case V_34 :
F_12 ( L_6 ,
V_28 , V_29 , V_16 + V_31 , V_13 ) ;
break;
case V_35 :
F_12 ( L_7 , V_28 , V_29 , V_31 , V_13 ) ;
break;
default:
F_12 ( L_8 , V_28 , V_29 , V_13 ) ;
break;
}
}
}
void F_13 ( const char * V_29 , int V_30 ,
const void * V_9 , T_2 V_10 )
{
F_10 ( V_36 , V_29 , V_30 , 16 , 1 ,
V_9 , V_10 , true ) ;
}
