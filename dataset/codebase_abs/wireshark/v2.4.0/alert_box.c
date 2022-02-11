void
F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_2 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void
F_3 ( const char * V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
void
F_4 ( const char * V_1 , T_1 V_2 )
{
F_5 ( V_1 , V_2 ) ;
}
void
F_6 ( const char * V_3 , int V_4 , T_2 * V_5 )
{
T_2 * V_6 ;
if ( V_4 < 0 ) {
V_6 = F_7 ( V_3 ) ;
switch ( V_4 ) {
case V_7 :
F_8 (
L_1 ,
V_6 ) ;
break;
case V_8 :
F_8 (
L_2
L_3 ,
V_6 ) ;
break;
case V_9 :
F_8 (
L_4 ,
V_6 ) ;
break;
case V_10 :
F_8 (
L_5
L_6 ,
V_6 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
case V_11 :
F_8 (
L_8 ,
V_6 ) ;
break;
case V_12 :
F_8 (
L_9
L_6 ,
V_6 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
case V_13 :
F_8 (
L_10 ,
V_6 ) ;
break;
case V_14 :
F_8 (
L_11
L_12 ,
V_6 ) ;
break;
case V_15 :
F_8 (
L_13
L_6 , V_6 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
default:
F_8 (
L_14 ,
V_6 ,
F_10 ( V_4 ) ) ;
break;
}
F_9 ( V_6 ) ;
} else {
F_11 ( V_3 , V_4 , FALSE ) ;
}
}
void
F_12 ( const char * V_3 , int V_4 ,
int V_16 )
{
T_2 * V_6 ;
if ( V_4 < 0 ) {
V_6 = F_7 ( V_3 ) ;
switch ( V_4 ) {
case V_7 :
F_8 (
L_1 ,
V_6 ) ;
break;
case V_17 :
F_8 (
L_15
L_16 ,
V_6 , F_13 ( V_16 ) ) ;
break;
case V_18 :
F_8 (
L_17 ) ;
break;
case V_19 :
F_8 ( L_18 ) ;
break;
case V_11 :
F_8 (
L_18 ) ;
break;
case V_13 :
F_8 (
L_19 ,
V_6 ) ;
break;
case V_20 :
F_8 (
L_20 ,
V_6 ) ;
break;
case V_21 :
F_8 (
L_21 ) ;
break;
default:
F_8 (
L_22 ,
V_6 ,
F_10 ( V_4 ) ) ;
break;
}
F_9 ( V_6 ) ;
} else {
F_11 ( V_3 , V_4 , TRUE ) ;
}
}
void
F_14 ( const char * V_3 , int V_4 , T_2 * V_5 )
{
T_2 * V_22 ;
if ( V_3 == NULL )
V_22 = F_15 ( L_23 ) ;
else {
T_2 * V_6 ;
V_6 = F_7 ( V_3 ) ;
V_22 = F_16 ( L_24 , V_6 ) ;
F_9 ( V_6 ) ;
}
switch ( V_4 ) {
case V_10 :
F_8 (
L_25
L_6 ,
V_22 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
case V_14 :
F_8 (
L_26 ,
V_22 ) ;
break;
case V_12 :
F_8 (
L_27
L_6 ,
V_22 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
case V_15 :
F_8 (
L_28
L_6 ,
V_22 ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
default:
F_8 (
L_29 ,
V_22 ,
F_10 ( V_4 ) ) ;
break;
}
F_9 ( V_22 ) ;
}
void
F_17 ( const char * V_23 , const char * V_24 ,
int V_4 , T_2 * V_5 , T_3 V_25 ,
int V_16 )
{
char * V_26 ;
char * V_27 ;
if ( V_4 < 0 ) {
if ( V_23 == NULL )
V_26 = F_15 ( L_30 ) ;
else
V_26 = F_16 ( L_31 , V_23 ) ;
switch ( V_4 ) {
case V_19 :
F_8 (
L_32 ,
V_25 , V_26 ,
F_13 ( V_16 ) ) ;
break;
case V_28 :
F_8 (
L_33 ,
V_25 , V_26 ,
F_13 ( V_16 ) ) ;
break;
case V_29 :
F_8 (
L_34 ,
V_25 , V_26 ,
F_13 ( V_16 ) ) ;
break;
case V_30 :
F_8 (
L_35
L_6 ,
V_25 , V_26 ,
F_13 ( V_16 ) ,
V_5 != NULL ? V_5 : L_7 ) ;
F_9 ( V_5 ) ;
break;
case V_20 :
V_27 = F_7 ( V_24 ) ;
F_8 (
L_36 ,
V_27 ) ;
F_9 ( V_27 ) ;
break;
default:
V_27 = F_7 ( V_24 ) ;
F_8 (
L_37 ,
V_27 , F_10 ( V_4 ) ) ;
F_9 ( V_27 ) ;
break;
}
F_9 ( V_26 ) ;
} else {
F_18 ( V_24 , V_4 ) ;
}
}
void
F_19 ( const char * V_3 , int V_4 )
{
T_2 * V_6 ;
if ( V_4 < 0 ) {
V_6 = F_7 ( V_3 ) ;
switch ( V_4 ) {
case V_31 :
F_8 (
L_38 ,
V_6 ) ;
break;
case V_20 :
F_8 (
L_36 ,
V_6 ) ;
break;
default:
F_8 (
L_39 ,
V_6 , F_10 ( V_4 ) ) ;
break;
}
F_9 ( V_6 ) ;
} else {
F_18 ( V_3 , V_4 ) ;
}
}
void
F_11 ( const char * V_3 , int V_4 , T_4 V_32 )
{
T_2 * V_6 ;
V_6 = F_7 ( V_3 ) ;
F_20 ( V_33 , NULL , NULL ,
F_21 ( V_4 , V_32 ) ,
V_6 ) ;
F_9 ( V_6 ) ;
}
void
F_22 ( const char * V_3 , int V_4 )
{
T_2 * V_6 ;
V_6 = F_7 ( V_3 ) ;
F_20 ( V_33 , NULL , NULL ,
L_40 ,
V_6 , F_23 ( V_4 ) ) ;
F_9 ( V_6 ) ;
}
void
F_18 ( const char * V_3 , int V_4 )
{
T_2 * V_6 ;
V_6 = F_7 ( V_3 ) ;
if ( V_4 < 0 ) {
switch ( V_4 ) {
case V_20 :
F_20 ( V_33 , NULL , NULL ,
L_36 ,
V_6 ) ;
break;
default:
F_20 ( V_33 , NULL , NULL ,
L_37 ,
V_6 , F_10 ( V_4 ) ) ;
break;
}
} else {
F_20 ( V_33 , NULL , NULL ,
F_24 ( V_4 ) , V_6 ) ;
}
F_9 ( V_6 ) ;
}
