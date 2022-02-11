unsigned int F_1 ( unsigned char * V_1 , int V_2 )
{
switch ( V_2 ) {
case 1 : return * V_1 ;
case 2 : return F_2 ( V_1 ) ;
case 3 : return F_3 ( V_1 ) ;
case 4 : return F_4 ( V_1 ) ;
default: return 0 ;
}
}
void * F_5 ( void * V_3 , int V_4 , void * V_5 , T_1 V_6 )
{
T_1 * V_7 , * V_8 , * V_9 ;
V_7 = V_3 ;
V_8 = V_7 + V_4 ;
for (; V_7 < V_8 ; ) {
if ( V_7 [ 0 ] < 2 )
return NULL ;
V_9 = V_7 + V_7 [ 0 ] ;
if ( V_9 > V_8 )
return NULL ;
if ( V_7 [ 1 ] == V_6 && ( ! V_5 || ( void * ) V_7 > V_5 ) ) {
return V_7 ;
}
V_7 = V_9 ;
}
return NULL ;
}
void * F_6 ( void * V_10 , int V_11 , void * V_5 , T_1 V_12 )
{
unsigned char * V_7 = V_5 ;
while ( ( V_7 = F_5 ( V_10 , V_11 , V_7 ,
V_13 ) ) != NULL ) {
if ( V_7 [ 0 ] >= 3 && V_7 [ 2 ] == V_12 )
return V_7 ;
}
return NULL ;
}
int F_7 ( struct V_14 * V_15 , unsigned int V_16 , T_2 V_17 ,
T_2 V_18 , T_3 V_19 , T_3 V_20 , void * V_21 ,
T_3 V_2 )
{
int V_22 ;
void * V_23 = NULL ;
if ( V_2 > 0 ) {
V_23 = F_8 ( V_21 , V_2 , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
}
V_22 = F_9 ( V_15 , V_16 , V_17 , V_18 ,
V_19 , V_20 , V_23 , V_2 , 1000 ) ;
if ( V_2 > 0 ) {
memcpy ( V_21 , V_23 , V_2 ) ;
F_10 ( V_23 ) ;
}
F_11 ( V_15 , V_16 , V_17 , V_18 ,
V_19 , V_20 , V_21 , V_2 ) ;
return V_22 ;
}
unsigned char F_12 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
switch ( F_13 ( V_27 -> V_15 ) ) {
case V_30 :
case V_31 :
if ( F_14 ( V_29 , 0 ) -> V_32 >= 1 &&
F_14 ( V_29 , 0 ) -> V_32 <= 4 )
return F_14 ( V_29 , 0 ) -> V_32 - 1 ;
break;
default:
break;
}
return 0 ;
}
