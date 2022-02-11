void
F_1 ( unsigned int * V_1 , boolean * V_2 , int V_3 )
{
unsigned int V_4 ;
int V_5 , V_6 ;
boolean V_7 = FALSE , V_8 , V_9 ;
V_4 = * V_1 ;
V_8 = * V_2 ;
V_6 = F_2 ( V_4 ) - V_10 ;
V_5 = F_3 ( V_4 ) ;
F_4 ( V_4 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_9 ) {
switch ( V_3 ) {
case V_11 :
if ( V_5 == 0 ) {
F_5 ( V_4 ) ;
}
break;
case V_12 :
if ( V_5 != 0 ) {
F_5 ( V_4 ) ;
}
break;
case V_13 :
if ( V_7 && ( V_8 ||
F_6 ( V_4 ) ) ) {
F_5 ( V_4 ) ;
}
break;
}
}
F_7 ( V_4 , V_5 ) ;
* V_1 = V_4 ;
* V_2 = V_9 ;
return;
}
void
F_8 ( unsigned int * V_14 ,
unsigned int * V_15 ,
boolean * V_2 ,
int V_3 )
{
unsigned int V_16 , V_17 ;
int V_5 , V_6 ;
boolean V_7 = FALSE , V_8 , V_9 ;
V_16 = * V_14 ;
V_17 = * V_15 ;
V_8 = * V_2 ;
V_6 = F_9 ( V_16 ) - V_18 ;
V_5 = F_10 ( V_16 ) ;
F_11 ( V_16 , V_17 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_9 ) {
switch ( V_3 ) {
case V_11 :
if ( V_5 == 0 ) {
F_12 ( V_16 , V_17 ) ;
}
break;
case V_12 :
if ( V_5 != 0 ) {
F_12 ( V_16 , V_17 ) ;
}
break;
case V_13 :
if ( V_7 && ( V_8 ||
F_13 ( V_17 ) ) ) {
F_12 ( V_16 , V_17 ) ;
}
break;
}
}
F_14 ( V_16 , V_5 ) ;
* V_14 = V_16 ;
* V_15 = V_17 ;
* V_2 = V_9 ;
return;
}
