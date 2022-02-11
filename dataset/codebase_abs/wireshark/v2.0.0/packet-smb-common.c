int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , char * * V_5 )
{
char * V_6 ;
T_3 V_7 ;
V_6 = F_2 ( F_3 () , V_1 , V_3 , & V_7 , V_8 ) ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_7 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_7 ;
}
int F_5 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , char * * V_5 )
{
char * V_6 , * V_9 ;
int V_7 ;
int V_10 ;
T_4 V_11 ;
V_7 = 0 ;
while ( F_6 ( V_1 , V_3 + V_7 ) != '\0' )
V_7 += 2 ;
V_7 += 2 ;
V_6 = ( char * ) F_7 ( F_3 () , V_7 / 2 ) ;
V_10 = V_3 ;
V_9 = V_6 ;
while ( ( V_11 = F_6 ( V_1 , V_10 ) ) != '\0' ) {
* V_9 ++ = ( char ) V_11 ;
V_10 += 2 ;
}
* V_9 = '\0' ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_7 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_7 ;
}
int F_8 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
const char * * V_5 )
{
int V_12 ;
const T_5 * V_6 = NULL ;
V_12 = F_9 ( V_1 , V_3 , V_13 + 3 + 1 , 0 , & V_6 ) ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_12 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_12 ;
}
static T_6 *
F_10 ( T_1 * V_1 , int V_3 , int * V_14 , T_7 V_15 ,
T_4 V_16 )
{
T_6 * V_17 ;
T_6 * V_9 ;
T_4 V_18 ;
int V_7 ;
int V_19 ;
T_7 V_20 = FALSE ;
V_17 = ( T_6 * ) F_7 ( F_3 () , V_13 + 3 + 1 ) ;
V_9 = V_17 ;
V_7 = V_13 ;
V_19 = 0 ;
for (; ; ) {
if ( V_16 == 0 )
break;
if ( V_16 == 1 ) {
if ( ! V_15 )
V_19 += 1 ;
break;
}
V_18 = F_6 ( V_1 , V_3 ) ;
if ( V_18 == 0 ) {
V_19 += 2 ;
break;
}
if ( V_7 > 0 ) {
if ( ( V_18 & 0xFF00 ) == 0 )
* V_9 ++ = ( T_6 ) V_18 ;
else
* V_9 ++ = '?' ;
V_7 -- ;
} else
V_20 = TRUE ;
V_3 += 2 ;
V_16 -= 2 ;
V_19 += 2 ;
if( V_15 ) {
if( V_19 >= * V_14 ) {
break;
}
}
}
if ( V_20 ) {
* V_9 ++ = '.' ;
* V_9 ++ = '.' ;
* V_9 ++ = '.' ;
}
* V_9 = '\0' ;
* V_14 = V_19 ;
return V_17 ;
}
const T_6 *
F_11 ( T_1 * V_1 , int * V_21 ,
T_7 V_22 , int * V_7 , T_7 V_23 , T_7 V_15 ,
T_4 * V_24 )
{
T_6 * V_17 ;
const T_6 * string ;
int V_25 = 0 ;
int V_26 ;
T_7 V_20 = FALSE ;
if ( * V_24 == 0 ) {
return NULL ;
}
if ( V_22 ) {
if ( ( ! V_23 ) && ( * V_21 % 2 ) ) {
( * V_21 ) ++ ;
( * V_24 ) -- ;
if ( * V_24 == 0 ) {
return NULL ;
}
}
if( V_15 ) {
V_25 = * V_7 ;
if ( V_25 < 0 ) {
V_25 = V_27 ;
}
}
string = F_10 ( V_1 , * V_21 , & V_25 , V_15 , * V_24 ) ;
} else {
if( V_15 ) {
V_17 = ( T_6 * ) F_7 ( F_3 () , V_13 + 3 + 1 ) ;
V_26 = * V_7 ;
if ( V_26 < 0 ) {
V_26 = V_27 ;
}
F_12 ( V_1 , * V_21 , V_26 ) ;
if ( V_26 > V_13 ) {
V_26 = V_13 ;
V_20 = TRUE ;
}
F_13 ( V_1 , ( V_28 * ) V_17 , * V_21 , V_26 ) ;
V_17 [ V_26 ] = '\0' ;
if ( V_20 )
F_14 ( V_17 , L_1 , V_13 + 3 + 1 ) ;
V_25 = * V_7 ;
string = V_17 ;
} else {
string = F_15 ( V_1 , * V_21 , & V_25 ) ;
}
}
* V_7 = V_25 ;
return string ;
}
