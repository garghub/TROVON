void
F_1 ( T_1 * V_1 ) {
V_1 -> V_2 = F_2 ( F_3 () ) ;
V_1 -> V_3 = F_2 ( F_3 () ) ;
V_1 -> V_4 = F_2 ( F_3 () ) ;
V_1 -> V_5 = F_2 ( F_3 () ) ;
V_1 -> V_6 = F_2 ( F_3 () ) ;
}
int
F_4 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_7 * V_12 )
{
T_7 V_13 ;
V_13 = F_5 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_6 ( V_10 , V_11 , V_7 , V_8 , 1 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 1 ;
}
int
F_7 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_8 * V_12 , T_9 * * V_14 )
{
T_8 V_13 ;
T_9 * V_15 = NULL ;
V_13 = F_8 ( V_7 , V_8 ) ;
if ( V_10 ) {
V_15 = F_6 ( V_10 , V_11 , V_7 , V_8 , 2 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
if ( V_14 )
* V_14 = V_15 ;
return V_8 + 2 ;
}
int
F_9 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_8 * V_12 )
{
T_8 V_13 ;
V_13 = F_8 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_6 ( V_10 , V_11 , V_7 , V_8 , 2 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 2 ;
}
int
F_10 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_10 * V_12 )
{
T_10 V_13 ;
V_13 = F_11 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_6 ( V_10 , V_11 , V_7 , V_8 , 4 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 4 ;
}
int
F_12 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_11 * V_12 )
{
T_11 V_13 ;
V_13 = F_8 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_13 ( V_10 , V_11 , V_7 , V_8 , 2 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 2 ;
}
int
F_14 ( T_2 * V_7 , T_3 V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_12 * V_12 )
{
T_12 V_13 ;
V_13 = F_11 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_13 ( V_10 , V_11 , V_7 , V_8 , 4 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 4 ;
}
int
F_15 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_10 * V_12 )
{
T_10 V_13 ;
V_13 = F_16 ( V_7 , V_8 ) ;
if ( V_10 ) {
F_6 ( V_10 , V_11 , V_7 , V_8 , 3 , V_13 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 3 ;
}
int
F_17 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_7 * V_12 )
{
T_7 V_13 [ 6 ] ;
F_18 ( V_7 , V_13 , V_8 , 6 ) ;
if( V_10 )
F_19 ( V_10 , V_11 , V_7 , V_8 , 6 , V_13 ) ;
if ( V_12 )
memcpy ( V_12 , V_13 , 6 ) ;
return V_8 + 6 ;
}
int
F_20 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_10 * V_12 )
{
T_10 V_13 ;
V_13 = F_21 ( V_7 , V_8 ) ;
if( V_10 )
F_22 ( V_10 , V_11 , V_7 , V_8 , 4 , V_13 ) ;
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 4 ;
}
int
F_23 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_11 , T_13 * V_16 )
{
T_7 V_17 [ 2 ] = { 0 , 0 } ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_10 , V_17 ,
V_11 , V_16 ) ;
return V_8 ;
}
int
F_25 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , T_10 V_18 )
{
T_9 * V_15 ;
V_15 = F_26 ( V_10 , V_19 , V_7 , V_8 , V_18 , L_1 ,
L_2 , V_18 ) ;
F_27 ( T_5 , V_15 , & V_20 ,
L_3 , V_18 ) ;
return V_8 + V_18 ;
}
int
F_28 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , T_10 V_18 , int V_21 )
{
if ( V_10 ) {
if( V_21 == V_22 )
F_29 ( V_10 , V_23 , V_7 , V_8 , V_18 , V_24 ) ;
else
F_29 ( V_10 , V_25 , V_7 , V_8 , V_18 , V_24 ) ;
}
return V_8 + V_18 ;
}
int
F_30 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , T_10 V_18 , const char * V_26 )
{
if ( V_10 && V_18 != 0 ) {
F_26 ( V_10 , V_27 , V_7 , V_8 , V_18 , L_1 ,
L_4 , V_26 , V_18 ) ;
}
return V_8 + V_18 ;
}
int
F_31 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , T_10 V_18 )
{
F_29 ( V_10 , V_28 , V_7 , 0 , 10000 , V_24 ) ;
return V_8 + V_18 ;
}
int
F_32 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 ,
T_6 * V_10 , int V_18 )
{
F_26 ( V_10 , V_29 , V_7 , V_8 , V_18 , L_1 ,
L_5 , V_18 ) ;
return V_8 + V_18 ;
}
int
F_33 ( T_2 * V_7 , int V_8 , T_4 * T_5 V_9 , T_6 * V_10 )
{
T_14 V_30 = 0 ;
if ( V_8 % 4 ) {
V_30 = 4 - ( V_8 % 4 ) ;
F_26 ( V_10 , V_29 , V_7 , V_8 , V_30 , L_1 ,
L_5 , V_30 ) ;
}
return V_8 + V_30 ;
}
void
F_34 ( T_4 * T_5 , T_9 * V_31 , const char * V_26 )
{
F_35 ( T_5 -> V_32 , V_33 , V_26 ) ;
F_36 ( V_31 , L_6 , V_26 ) ;
}
void
F_37 ( int V_34 )
{
static T_15 V_35 [] = {
{ & V_29 ,
{ L_7 , L_8 ,
V_36 , V_37 , NULL , 0x0 ,
NULL , V_38 } } ,
{ & V_19 ,
{ L_9 , L_10 ,
V_36 , V_37 , NULL , 0x0 ,
NULL , V_38 } } ,
{ & V_27 ,
{ L_11 , L_12 ,
V_36 , V_37 , NULL , 0x0 ,
NULL , V_38 } } ,
{ & V_25 ,
{ L_13 , L_14 ,
V_39 , V_37 , NULL , 0x0 ,
NULL , V_38 } } ,
{ & V_23 ,
{ L_15 , L_16 ,
V_39 , V_37 , NULL , 0x0 ,
NULL , V_38 } } ,
{ & V_28 ,
{ L_17 , L_18 ,
V_39 , V_37 , NULL , 0x0 ,
NULL , V_38 } }
} ;
static T_16 V_40 [] = {
{ & V_20 , { L_19 , V_41 , V_42 , L_9 , V_43 } } ,
} ;
T_17 * V_44 ;
F_38 ( V_34 , V_35 , F_39 ( V_35 ) ) ;
V_44 = F_40 ( V_34 ) ;
F_41 ( V_44 , V_40 , F_39 ( V_40 ) ) ;
}
char * F_42 ( char * V_45 , int V_46 , T_18 * V_47 )
{
const char V_48 [] = L_20 ;
const char V_49 [] = L_21 ;
char * V_50 = fgets ( V_45 , V_46 , V_47 ) ;
if ( V_50 == NULL ) {
return V_50 ;
}
char * V_51 = strstr ( V_45 , V_48 ) ;
char * V_52 = V_51 + sizeof( V_48 ) - 1 ;
if( V_51 == NULL ) {
return V_50 ;
}
* V_51 = '\0' ;
T_19 V_53 = V_51 - V_45 ;
T_19 V_54 = V_46 - V_53 ;
char * V_55 = strstr ( V_52 , V_49 ) ;
if ( V_55 == NULL ) {
char * V_56 = ( char * ) F_43 ( F_44 () , V_57 ) ;
char * V_58 = V_56 ;
while( ( V_55 == NULL ) && ( V_58 != NULL ) ) {
V_58 = fgets ( V_56 , V_57 , V_47 ) ;
if ( V_58 == NULL ) {
break;
}
V_55 = strstr ( V_58 , V_49 ) ;
}
}
if ( V_55 == NULL ) {
return V_50 ;
}
char * V_59 = V_55 + sizeof( V_49 ) - 1 ;
T_19 V_60 = strlen ( V_59 ) + 1 ;
if ( V_60 < V_54 ) {
F_45 ( V_45 , V_59 , V_46 ) ;
}
else {
fseek ( V_47 , - ( long ) ( V_60 ) , V_61 ) ;
}
return V_50 ;
}
