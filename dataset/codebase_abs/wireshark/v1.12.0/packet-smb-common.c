int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , char * * V_5 )
{
char * V_6 ;
T_3 V_7 ;
V_6 = F_2 ( F_3 () , V_1 , V_3 , & V_7 ) ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_7 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_7 ;
}
int F_5 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , char * * V_5 )
{
char * V_6 , * V_8 ;
int V_7 ;
int V_9 ;
T_4 V_10 ;
V_7 = 0 ;
while ( F_6 ( V_1 , V_3 + V_7 ) != '\0' )
V_7 += 2 ;
V_7 += 2 ;
V_6 = ( char * ) F_7 ( F_3 () , V_7 / 2 ) ;
V_9 = V_3 ;
V_8 = V_6 ;
while ( ( V_10 = F_6 ( V_1 , V_9 ) ) != '\0' ) {
* V_8 ++ = ( char ) V_10 ;
V_9 += 2 ;
}
* V_8 = '\0' ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_7 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_7 ;
}
int F_8 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
const char * * V_5 )
{
int V_11 ;
const T_5 * V_6 = NULL ;
V_11 = F_9 ( V_1 , V_3 , V_12 + 3 + 1 , 0 , & V_6 ) ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_11 , V_6 ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_11 ;
}
static T_6 *
F_10 ( T_1 * V_1 , int V_3 , int * V_13 , T_7 V_14 ,
T_4 V_15 )
{
T_6 * V_16 ;
T_6 * V_8 ;
T_4 V_17 ;
int V_7 ;
int V_18 ;
T_7 V_19 = FALSE ;
V_16 = ( T_6 * ) F_7 ( F_3 () , V_12 + 3 + 1 ) ;
V_8 = V_16 ;
V_7 = V_12 ;
V_18 = 0 ;
for (; ; ) {
if ( V_15 == 0 )
break;
if ( V_15 == 1 ) {
if ( ! V_14 )
V_18 += 1 ;
break;
}
V_17 = F_6 ( V_1 , V_3 ) ;
if ( V_17 == 0 ) {
V_18 += 2 ;
break;
}
if ( V_7 > 0 ) {
if ( ( V_17 & 0xFF00 ) == 0 )
* V_8 ++ = ( T_6 ) V_17 ;
else
* V_8 ++ = '?' ;
V_7 -- ;
} else
V_19 = TRUE ;
V_3 += 2 ;
V_15 -= 2 ;
V_18 += 2 ;
if( V_14 ) {
if( V_18 >= * V_13 ) {
break;
}
}
}
if ( V_19 ) {
* V_8 ++ = '.' ;
* V_8 ++ = '.' ;
* V_8 ++ = '.' ;
}
* V_8 = '\0' ;
* V_13 = V_18 ;
return V_16 ;
}
const T_6 *
F_11 ( T_1 * V_1 , int * V_20 ,
T_7 V_21 , int * V_7 , T_7 V_22 , T_7 V_14 ,
T_4 * V_23 )
{
T_6 * V_16 ;
const T_6 * string ;
int V_24 = 0 ;
int V_25 ;
T_7 V_19 = FALSE ;
if ( * V_23 == 0 ) {
return NULL ;
}
if ( V_21 ) {
if ( ( ! V_22 ) && ( * V_20 % 2 ) ) {
( * V_20 ) ++ ;
( * V_23 ) -- ;
if ( * V_23 == 0 ) {
return NULL ;
}
}
if( V_14 ) {
V_24 = * V_7 ;
if ( V_24 < 0 ) {
V_24 = V_26 ;
}
}
string = F_10 ( V_1 , * V_20 , & V_24 , V_14 , * V_23 ) ;
} else {
if( V_14 ) {
V_16 = ( T_6 * ) F_7 ( F_3 () , V_12 + 3 + 1 ) ;
V_25 = * V_7 ;
if ( V_25 < 0 ) {
V_25 = V_26 ;
}
F_12 ( V_1 , * V_20 , V_25 ) ;
if ( V_25 > V_12 ) {
V_25 = V_12 ;
V_19 = TRUE ;
}
F_13 ( V_1 , ( V_27 * ) V_16 , * V_20 , V_25 ) ;
V_16 [ V_25 ] = '\0' ;
if ( V_19 )
F_14 ( V_16 , L_1 , V_12 + 3 + 1 ) ;
V_24 = * V_7 ;
string = V_16 ;
} else {
string = F_15 ( V_1 , * V_20 , & V_24 ) ;
}
}
* V_7 = V_24 ;
return string ;
}
