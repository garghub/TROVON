static char *
F_1 ( const char * V_1 )
{
char * V_2 ;
if ( strcmp ( V_1 , L_1 ) == 0 ) {
V_2 = F_2 ( L_2 ) ;
} else {
V_2 = F_3 ( L_3 , V_1 ) ;
}
return V_2 ;
}
static char *
F_4 ( const char * V_1 )
{
char * V_2 ;
if ( strcmp ( V_1 , L_1 ) == 0 ) {
V_2 = F_2 ( L_4 ) ;
} else {
V_2 = F_3 ( L_3 , V_1 ) ;
}
return V_2 ;
}
void
F_5 ( const char * V_3 , const char * V_4 ,
int V_5 , T_1 * V_6 )
{
char * V_7 ;
V_7 = F_1 ( V_4 ) ;
if ( V_5 < 0 ) {
switch ( V_5 ) {
case V_8 :
F_6 ( L_5 ,
V_7 ) ;
break;
case V_9 :
F_6 ( L_6 ,
V_7 , V_3 ) ;
break;
case V_10 :
F_6 ( L_7 ,
V_7 , V_3 ) ;
break;
case V_11 :
F_6 ( L_8
L_9 ,
V_7 , V_3 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
case V_12 :
F_6 ( L_11 ,
V_7 , V_3 ) ;
break;
case V_13 :
F_6 ( L_12
L_9 ,
V_7 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
case V_14 :
F_6 ( L_13 ,
V_7 ) ;
break;
case V_15 :
F_6 ( L_14 ,
V_7 ) ;
break;
case V_16 :
F_6 ( L_15
L_9 ,
V_7 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
default:
F_6 ( L_16 ,
V_7 ,
F_8 ( V_5 ) ) ;
break;
}
F_7 ( V_7 ) ;
} else
F_6 ( F_9 ( V_5 , FALSE ) , V_4 ) ;
}
void
F_10 ( const char * V_3 , const char * V_4 ,
int V_5 , int V_17 )
{
char * V_7 ;
V_7 = F_4 ( V_4 ) ;
if ( V_5 < 0 ) {
switch ( V_5 ) {
case V_8 :
F_6 ( L_5 ,
V_7 ) ;
break;
case V_18 :
F_6 ( L_17 ,
V_7 ,
F_11 ( V_17 ) ) ;
break;
case V_19 :
F_6 ( L_18 ,
V_3 ) ;
break;
case V_20 :
F_6 ( L_19 ,
F_11 ( V_17 ) ) ;
break;
case V_12 :
F_6 ( L_19 ,
F_11 ( V_17 ) ) ;
break;
case V_14 :
F_6 ( L_20 ,
V_7 ) ;
break;
case V_21 :
F_6 ( L_21 ,
V_7 ) ;
break;
case V_22 :
F_6 ( L_22 ) ;
break;
default:
F_6 ( L_23 ,
V_7 ,
F_8 ( V_5 ) ) ;
break;
}
F_7 ( V_7 ) ;
} else
F_6 ( F_9 ( V_5 , TRUE ) , V_4 ) ;
}
void
F_12 ( const char * V_3 , const char * V_4 ,
int V_5 , T_1 * V_6 )
{
char * V_23 ;
V_23 = F_1 ( V_4 ) ;
switch ( V_5 ) {
case V_11 :
F_6 ( L_8
L_9 ,
V_23 , V_3 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
case V_15 :
F_6 ( L_24 ,
V_23 ) ;
break;
case V_13 :
F_6 ( L_12
L_9 ,
V_23 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
case V_16 :
F_6 ( L_25
L_9 ,
V_23 ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
default:
F_6 ( L_26 ,
V_23 , F_8 ( V_5 ) ) ;
break;
}
F_7 ( V_23 ) ;
}
void
F_13 ( const char * V_3 , const char * V_24 ,
const char * V_25 , int V_5 , T_1 * V_6 ,
T_2 V_26 , int V_17 )
{
char * V_27 ;
char * V_28 ;
char * V_29 ;
if ( V_24 == NULL ) {
V_28 = F_2 ( L_27 ) ;
} else {
V_27 = F_1 ( V_24 ) ;
V_28 = F_3 ( L_28 , V_26 ,
V_27 ) ;
F_7 ( V_27 ) ;
}
V_29 = F_4 ( V_25 ) ;
switch ( V_5 ) {
case V_20 :
F_6 ( L_29 ,
V_28 ,
F_11 ( V_17 ) ) ;
break;
case V_30 :
F_6 ( L_30 ,
V_28 , V_3 ,
F_11 ( V_17 ) ) ;
break;
case V_31 :
F_6 ( L_31 ,
V_28 ,
F_11 ( V_17 ) ) ;
break;
case V_32 :
F_6 ( L_32
L_9 ,
V_28 ,
F_11 ( V_17 ) ,
V_6 != NULL ? V_6 : L_10 ) ;
F_7 ( V_6 ) ;
break;
case V_33 :
F_6 ( L_33
L_34 ,
V_29 ) ;
break;
#ifdef F_14
case F_14 :
F_6 ( L_35
L_36 ,
V_29 ) ;
break;
#endif
case V_21 :
F_6 ( L_37 ,
V_29 ) ;
break;
default:
F_6 ( L_38 ,
V_29 , F_8 ( V_5 ) ) ;
break;
}
F_7 ( V_28 ) ;
F_7 ( V_29 ) ;
}
void
F_15 ( const char * V_4 , int V_5 )
{
char * V_23 ;
V_23 = F_4 ( V_4 ) ;
switch ( V_5 ) {
case V_33 :
F_6 ( L_33
L_34 ,
V_23 ) ;
break;
#ifdef F_14
case F_14 :
F_6 ( L_35
L_36 ,
V_23 ) ;
break;
#endif
case V_34 :
F_6 ( L_39 ,
V_23 ) ;
break;
case V_21 :
F_6 ( L_37 ,
V_23 ) ;
break;
default:
F_6 ( L_40 ,
V_23 , F_8 ( V_5 ) ) ;
break;
}
F_7 ( V_23 ) ;
}
