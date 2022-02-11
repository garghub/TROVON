void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 = F_2 ( V_2 ) ;
memcpy ( V_1 , & V_3 , sizeof( T_2 ) ) ;
}
void F_3 ( T_1 * V_1 , T_3 V_2 )
{
T_3 V_3 = F_4 ( V_2 ) ;
memcpy ( V_1 , & V_3 , sizeof( T_3 ) ) ;
}
T_2 F_5 ( const T_1 * V_4 )
{
T_2 V_2 ;
memcpy ( & V_2 , V_4 , sizeof( T_2 ) ) ;
return F_6 ( V_2 ) ;
}
T_3 F_7 ( const T_1 * V_4 )
{
T_3 V_2 ;
memcpy ( & V_2 , V_4 , sizeof( T_3 ) ) ;
return F_8 ( V_2 ) ;
}
int F_9 ( T_1 * * V_5 , T_4 * V_6 ,
T_4 V_7 )
{
if( V_7 > * V_6 ) {
T_1 * V_8 ;
V_7 = ( V_7 + 4095 ) / 4096 * 4096 ;
V_8 = ( T_1 * ) realloc ( * V_5 , V_7 ) ;
if( V_8 == NULL ) {
return V_9 ;
} else {
* V_5 = V_8 ;
* V_6 = V_7 ;
}
}
return 0 ;
}
void * F_10 ( const void * V_10 , T_4 V_2 )
{
void * V_11 ;
if( V_2 == 0 ) {
return NULL ;
}
V_11 = malloc ( V_2 ) ;
if( V_11 == NULL ) {
return NULL ;
}
memcpy ( V_11 , V_10 , V_2 ) ;
return V_11 ;
}
void F_11 ( T_1 * V_12 , T_4 V_13 )
{
T_4 V_14 ;
for( V_14 = 0 ; V_14 < V_13 ; ++ V_14 ) {
if( 'A' <= V_12 [ V_14 ] && V_12 [ V_14 ] <= 'Z' ) {
V_12 [ V_14 ] += 'a' - 'A' ;
}
}
}
int F_12 ( T_5 * V_15 ,
T_5 * V_16 ,
T_5 * V_17 ,
T_5 * V_18 )
{
if( * V_18 > 0 ) {
T_5 V_19 =
F_13 ( 0 , * V_16 ) - * V_18 ;
if( V_19 < 0 ) {
T_5 V_20 ;
if( * V_15 >
V_21 + V_19 ) {
return V_22 ;
}
* V_15 -= V_19 ;
V_20 = F_14 ( * V_17 ,
- V_19 ) ;
* V_17 -= V_20 ;
if( * V_16 < 0 ) {
* V_16 += V_20 ;
} else {
* V_16 = V_20 ;
}
* V_18 -= V_20 ;
} else {
* V_16 = V_19 ;
}
return 0 ;
} else {
if( * V_15 + * V_18 < 0 ||
* V_16 < V_23 - * V_18 ||
* V_17 > V_24 + * V_18 ) {
return V_22 ;
}
* V_15 += * V_18 ;
* V_16 += * V_18 ;
* V_17 -= * V_18 ;
* V_18 = 0 ;
}
return 0 ;
}
int F_15 ( T_5 V_25 ,
T_5 V_26 )
{
return V_26 >= V_25 / 2 ;
}
const char * F_16 ( int V_27 )
{
switch( V_27 ) {
case 0 :
return L_1 ;
case V_28 :
return L_2 ;
case V_29 :
return L_3 ;
case V_30 :
return L_4 ;
case V_31 :
return L_5 ;
case V_32 :
return L_6 ;
case V_33 :
return L_7 ;
case V_34 :
return L_8 ;
case V_35 :
return L_9 ;
case V_36 :
return L_10 ;
case V_37 :
return L_11 ;
case V_38 :
return L_12 ;
case V_39 :
return L_13 ;
case V_40 :
return L_14 ;
case V_41 :
return L_15 ;
case V_42 :
return L_16 ;
case V_43 :
return L_17 ;
case V_44 :
return L_18 ;
case V_45 :
return L_19 ;
case V_46 :
return L_20 ;
case V_47 :
return L_21 ;
case V_48 :
return L_22 ;
case V_49 :
return L_23 ;
case V_22 :
return L_24 ;
case V_50 :
return L_25 ;
case V_51 :
return L_26 ;
case V_52 :
return L_27 ;
case V_53 :
return L_28 ;
case V_54 :
return L_29 ;
case V_9 :
return L_30 ;
case V_55 :
return L_31 ;
default:
return L_32 ;
}
}
void F_17 ( void * V_56 )
{
free ( V_56 ) ;
}
int F_18 ( const T_1 * V_57 , T_4 V_13 )
{
const T_1 * V_58 ;
if( V_13 == 0 ) {
return 0 ;
}
if( * V_57 == ':' ) {
if( V_13 == 1 ) {
return 0 ;
}
++ V_57 ;
-- V_13 ;
}
for( V_58 = V_57 + V_13 ; V_57 != V_58 ; ++ V_57 ) {
if( ! V_59 [ * V_57 ] ) {
return 0 ;
}
}
return 1 ;
}
int F_19 ( const T_1 * V_60 , T_4 V_13 )
{
const T_1 * V_58 ;
for( V_58 = V_60 + V_13 ; V_60 != V_58 ; ++ V_60 ) {
if( ! V_61 [ * V_60 ] ) {
return 0 ;
}
}
return 1 ;
}
T_1 * F_20 ( T_1 * V_11 , const void * V_10 , T_4 V_13 )
{
memcpy ( V_11 , V_10 , V_13 ) ;
return V_11 + V_13 ;
}
