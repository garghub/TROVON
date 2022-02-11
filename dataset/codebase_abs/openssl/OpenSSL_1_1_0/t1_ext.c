static T_1 * F_1 ( const T_2 * V_1 ,
unsigned int V_2 )
{
T_3 V_3 ;
T_1 * V_4 = V_1 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_6 ; V_3 ++ , V_4 ++ ) {
if ( V_2 == V_4 -> V_2 )
return V_4 ;
}
return NULL ;
}
void F_2 ( T_2 * V_1 )
{
T_3 V_3 ;
T_1 * V_4 = V_1 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_6 ; V_3 ++ , V_4 ++ )
V_4 -> V_7 = 0 ;
}
int F_3 ( T_4 * V_8 , int V_9 ,
unsigned int V_2 ,
const unsigned char * V_10 , T_3 V_11 , int * V_12 )
{
T_2 * V_1 = V_9 ? & V_8 -> V_13 -> V_14 : & V_8 -> V_13 -> V_15 ;
T_1 * V_4 ;
V_4 = F_1 ( V_1 , V_2 ) ;
if ( ! V_4 )
return 1 ;
if ( ! V_9 ) {
if ( ! ( V_4 -> V_7 & V_16 ) ) {
* V_12 = V_17 ;
return 0 ;
}
}
if ( V_4 -> V_7 & V_18 ) {
* V_12 = V_19 ;
return 0 ;
}
V_4 -> V_7 |= V_18 ;
if ( ! V_4 -> V_20 )
return 1 ;
return V_4 -> V_20 ( V_8 , V_2 , V_10 , V_11 , V_12 , V_4 -> V_21 ) ;
}
int F_4 ( T_4 * V_8 , int V_9 ,
unsigned char * * V_22 , unsigned char * V_23 , int * V_12 )
{
T_2 * V_1 = V_9 ? & V_8 -> V_13 -> V_14 : & V_8 -> V_13 -> V_15 ;
T_1 * V_4 ;
unsigned char * V_24 = * V_22 ;
T_3 V_3 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_6 ; V_3 ++ ) {
const unsigned char * V_25 = NULL ;
T_3 V_26 = 0 ;
V_4 = V_1 -> V_5 + V_3 ;
if ( V_9 ) {
if ( ! ( V_4 -> V_7 & V_18 ) )
continue;
if ( ! V_4 -> V_27 )
continue;
}
if ( V_4 -> V_27 ) {
int V_28 = 0 ;
V_28 = V_4 -> V_27 ( V_8 , V_4 -> V_2 ,
& V_25 , & V_26 , V_12 , V_4 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
if ( V_28 == 0 )
continue;
}
if ( 4 > V_23 - V_24 || V_26 > ( T_3 ) ( V_23 - V_24 - 4 ) )
return 0 ;
F_5 ( V_4 -> V_2 , V_24 ) ;
F_5 ( V_26 , V_24 ) ;
if ( V_26 ) {
memcpy ( V_24 , V_25 , V_26 ) ;
V_24 += V_26 ;
}
F_6 ( ! ( V_4 -> V_7 & V_16 ) ) ;
V_4 -> V_7 |= V_16 ;
if ( V_4 -> V_30 )
V_4 -> V_30 ( V_8 , V_4 -> V_2 , V_25 , V_4 -> V_29 ) ;
}
* V_22 = V_24 ;
return 1 ;
}
int F_7 ( T_2 * V_31 , const T_2 * V_32 )
{
if ( V_32 -> V_6 ) {
V_31 -> V_5 =
F_8 ( V_32 -> V_5 ,
sizeof( T_1 ) * V_32 -> V_6 ) ;
if ( V_31 -> V_5 == NULL )
return 0 ;
V_31 -> V_6 = V_32 -> V_6 ;
}
return 1 ;
}
void F_9 ( T_2 * V_1 )
{
F_10 ( V_1 -> V_5 ) ;
}
static int F_11 ( T_2 * V_1 ,
unsigned int V_2 ,
T_5 V_27 ,
T_6 V_30 ,
void * V_29 ,
T_7 V_20 , void * V_21 )
{
T_1 * V_4 , * V_33 ;
if ( ! V_27 && V_30 )
return 0 ;
if ( F_12 ( V_2 ) &&
V_2 != V_34 )
return 0 ;
if ( V_2 > 0xffff )
return 0 ;
if ( F_1 ( V_1 , V_2 ) )
return 0 ;
V_33 = F_13 ( V_1 -> V_5 ,
( V_1 -> V_6 + 1 ) * sizeof( T_1 ) ) ;
if ( V_33 == NULL ) {
F_10 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = 0 ;
return 0 ;
}
V_1 -> V_5 = V_33 ;
V_4 = V_1 -> V_5 + V_1 -> V_6 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_30 = V_30 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_29 = V_29 ;
V_4 -> V_21 = V_21 ;
V_1 -> V_6 ++ ;
return 1 ;
}
int F_14 ( const T_8 * V_35 , unsigned int V_2 )
{
return F_1 ( & V_35 -> V_13 -> V_15 , V_2 ) != NULL ;
}
int F_15 ( T_8 * V_35 , unsigned int V_2 ,
T_5 V_27 ,
T_6 V_30 ,
void * V_29 ,
T_7 V_20 , void * V_21 )
{
#ifndef F_16
if ( V_2 == V_34 &&
F_17 ( V_35 ) )
return 0 ;
#endif
return F_11 ( & V_35 -> V_13 -> V_15 , V_2 , V_27 ,
V_30 , V_29 , V_20 , V_21 ) ;
}
int F_18 ( T_8 * V_35 , unsigned int V_2 ,
T_5 V_27 ,
T_6 V_30 ,
void * V_29 ,
T_7 V_20 , void * V_21 )
{
return F_11 ( & V_35 -> V_13 -> V_14 , V_2 ,
V_27 , V_30 , V_29 , V_20 , V_21 ) ;
}
int F_12 ( unsigned int V_2 )
{
switch ( V_2 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
#ifndef F_19
case V_40 :
#endif
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_34 :
case V_48 :
#ifdef F_20
case F_20 :
#endif
return 1 ;
default:
return 0 ;
}
}
