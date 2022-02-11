T_1 *
F_1 ( const T_1 * V_1 )
{
T_1 * V_2 ;
const T_1 * V_3 = V_1 ;
T_1 * V_4 ;
T_2 V_5 = 0 ;
T_3 V_6 = FALSE ;
while ( * V_3 ) {
if ( * V_3 == ' ' || * V_3 == '\t' )
V_6 = TRUE ;
else if ( * V_3 == '"' )
V_5 ++ ;
else if ( * V_3 == '\\' ) {
const T_1 * V_7 = V_3 ;
while ( * V_7 && * V_7 == '\\' )
V_7 ++ ;
if ( * V_7 == '"' )
V_5 ++ ;
}
V_5 ++ ;
V_3 ++ ;
}
V_4 = V_2 = F_2 ( V_5 + V_6 * 2 + 1 ) ;
V_3 = V_1 ;
if ( V_6 )
* V_4 ++ = '"' ;
while ( * V_3 ) {
if ( * V_3 == '"' )
* V_4 ++ = '\\' ;
else if ( * V_3 == '\\' ) {
const T_1 * V_7 = V_3 ;
while ( * V_7 && * V_7 == '\\' )
V_7 ++ ;
if ( * V_7 == '"' )
* V_4 ++ = '\\' ;
}
* V_4 ++ = * V_3 ;
V_3 ++ ;
}
if ( V_6 )
* V_4 ++ = '"' ;
* V_4 ++ = '\0' ;
return V_2 ;
}
const char *
F_3 ( T_4 error )
{
static char V_8 [ V_9 + 1 ] ;
T_5 V_10 ;
char * V_3 ;
F_4 ( V_11 | V_12 ,
NULL , error , 0 , V_8 , V_9 , NULL ) ;
V_10 = strlen ( V_8 ) ;
if ( V_10 >= 2 ) {
V_8 [ V_10 - 1 ] = '\0' ;
V_8 [ V_10 - 2 ] = '\0' ;
}
V_3 = strchr ( V_8 , '\0' ) ;
F_5 ( V_3 , ( V_13 ) ( sizeof V_8 - ( V_3 - V_8 ) ) , L_1 , error ) ;
return V_8 ;
}
const char *
F_6 ( T_4 V_14 )
{
static char V_8 [ V_9 + 1 ] ;
static const struct V_15 {
int V_16 ;
char * V_17 ;
} V_18 [] = {
{ V_19 , L_2 } ,
{ V_20 , L_3 } ,
{ V_21 , L_4 } ,
{ V_22 , L_5 } ,
{ V_23 , L_6 } ,
{ V_24 , L_7 } ,
{ V_25 , L_8 } ,
{ V_26 , L_9 } ,
{ V_27 , L_10 } ,
{ V_28 , L_11 } ,
{ V_29 , L_12 } ,
{ V_30 , L_13 } ,
{ V_31 , L_14 } ,
{ V_32 , L_15 } ,
{ V_33 , L_16 } ,
{ V_34 , L_17 } ,
{ V_35 , L_18 } ,
{ V_36 , L_19 } ,
{ V_37 , L_20 } ,
{ V_38 , L_21 } ,
{ V_39 , L_22 } ,
{ V_40 , L_23 } ,
{ 0 , NULL }
} ;
#define F_7 (sizeof exceptions / sizeof exceptions[0])
int V_41 ;
for ( V_41 = 0 ; V_41 < F_7 ; V_41 ++ ) {
if ( V_18 [ V_41 ] . V_16 == V_14 )
return V_18 [ V_41 ] . V_17 ;
}
F_5 ( V_8 , ( V_13 ) sizeof V_8 , L_24 , V_14 ) ;
return V_8 ;
}
