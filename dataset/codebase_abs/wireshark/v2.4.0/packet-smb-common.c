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
T_5 V_13 ;
const T_6 * V_6 = NULL ;
V_12 = F_9 ( V_1 , V_3 , V_14 + 3 + 1 , 0 , & V_6 , & V_13 ) ;
F_4 ( V_2 , V_4 , V_1 , V_3 , V_12 , F_10 ( F_3 () , V_6 , V_13 ) ) ;
if ( V_5 )
* V_5 = V_6 ;
return V_3 + V_12 ;
}
static T_7 *
F_11 ( T_1 * V_1 , int V_3 , int * V_15 , T_8 V_16 ,
T_4 V_17 )
{
T_7 * V_18 ;
T_7 * V_9 ;
T_4 V_19 ;
int V_7 ;
int V_20 ;
T_8 V_21 = FALSE ;
V_18 = ( T_7 * ) F_7 ( F_3 () , V_14 + 3 + 1 ) ;
V_9 = V_18 ;
V_7 = V_14 ;
V_20 = 0 ;
for (; ; ) {
if ( V_17 == 0 )
break;
if ( V_17 == 1 ) {
if ( ! V_16 )
V_20 += 1 ;
break;
}
V_19 = F_6 ( V_1 , V_3 ) ;
if ( V_19 == 0 ) {
V_20 += 2 ;
break;
}
if ( V_7 > 0 ) {
if ( ( V_19 & 0xFF00 ) == 0 )
* V_9 ++ = ( T_7 ) V_19 ;
else
* V_9 ++ = '?' ;
V_7 -- ;
} else
V_21 = TRUE ;
V_3 += 2 ;
V_17 -= 2 ;
V_20 += 2 ;
if( V_16 ) {
if( V_20 >= * V_15 ) {
break;
}
}
}
if ( V_21 ) {
* V_9 ++ = '.' ;
* V_9 ++ = '.' ;
* V_9 ++ = '.' ;
}
* V_9 = '\0' ;
* V_15 = V_20 ;
return V_18 ;
}
const T_7 *
F_12 ( T_1 * V_1 , int * V_22 ,
T_8 V_23 , int * V_7 , T_8 V_24 , T_8 V_16 ,
T_4 * V_25 )
{
T_7 * V_18 ;
const T_7 * string ;
int V_26 = 0 ;
int V_27 ;
T_8 V_21 = FALSE ;
if ( * V_25 == 0 ) {
return NULL ;
}
if ( V_23 ) {
if ( ( ! V_24 ) && ( * V_22 % 2 ) ) {
( * V_22 ) ++ ;
( * V_25 ) -- ;
if ( * V_25 == 0 ) {
return NULL ;
}
}
if( V_16 ) {
V_26 = * V_7 ;
if ( V_26 < 0 ) {
V_26 = V_28 ;
}
}
string = F_11 ( V_1 , * V_22 , & V_26 , V_16 , * V_25 ) ;
} else {
if( V_16 ) {
V_18 = ( T_7 * ) F_7 ( F_3 () , V_14 + 3 + 1 ) ;
V_27 = * V_7 ;
if ( V_27 < 0 ) {
V_27 = V_28 ;
}
F_13 ( V_1 , * V_22 , V_27 ) ;
if ( V_27 > V_14 ) {
V_27 = V_14 ;
V_21 = TRUE ;
}
F_14 ( V_1 , ( V_29 * ) V_18 , * V_22 , V_27 ) ;
V_18 [ V_27 ] = '\0' ;
if ( V_21 )
F_15 ( V_18 , L_1 , V_14 + 3 + 1 ) ;
V_26 = * V_7 ;
string = V_18 ;
} else {
string = F_16 ( V_1 , * V_22 , & V_26 ) ;
}
}
* V_7 = V_26 ;
return string ;
}
