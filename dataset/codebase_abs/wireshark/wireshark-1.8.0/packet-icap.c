static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_4 * V_6 ;
T_5 V_7 = 0 ;
const T_6 * line ;
T_5 V_8 ;
const T_6 * V_9 , * V_10 ;
int V_11 ;
T_6 V_12 ;
T_7 V_13 ;
int V_14 ;
F_2 ( V_2 -> V_15 , V_16 , L_1 ) ;
if ( F_3 ( V_2 -> V_15 , V_17 ) ) {
V_11 = F_4 ( V_1 , V_7 , - 1 , & V_8 ,
FALSE ) ;
line = F_5 ( V_1 , V_7 , V_11 ) ;
V_13 = V_18 ;
if ( F_6 ( line , V_11 , & V_13 ) )
F_7 ( V_2 -> V_15 , V_17 ,
F_8 ( line , V_11 ) ) ;
else
F_2 ( V_2 -> V_15 , V_17 , L_2 ) ;
}
if ( V_3 ) {
V_5 = F_9 ( V_3 , V_19 , V_1 , V_7 , - 1 ,
V_20 ) ;
V_4 = F_10 ( V_5 , V_21 ) ;
}
V_13 = V_18 ;
while ( F_11 ( V_1 , V_7 ) ) {
T_8 V_22 = FALSE ;
T_8 V_23 = FALSE ;
V_11 = F_4 ( V_1 , V_7 , - 1 , & V_8 ,
FALSE ) ;
line = F_5 ( V_1 , V_7 , V_11 ) ;
V_10 = line + V_11 ;
if ( F_6 ( line , V_11 , & V_13 ) ) {
V_22 = TRUE ;
goto V_24;
}
if ( V_11 == 0 ) {
V_22 = TRUE ;
goto V_24;
}
V_9 = line ;
V_23 = FALSE ;
while ( V_9 < V_10 && ( ! V_23 ) ) {
V_12 = * V_9 ++ ;
if ( ! isascii ( V_12 ) ) {
V_22 = FALSE ;
break;
}
if ( iscntrl ( V_12 ) ) {
V_22 = FALSE ;
break;
}
switch ( V_12 ) {
case '(' :
case ')' :
case '<' :
case '>' :
case '@' :
case ',' :
case ';' :
case '\\' :
case '"' :
case '/' :
case '[' :
case ']' :
case '?' :
case '=' :
case '{' :
case '}' :
V_22 = FALSE ;
V_23 = TRUE ;
break;
case ':' :
V_22 = TRUE ;
goto V_24;
}
}
if ( ! V_22 )
break;
V_24:
if ( V_3 ) {
F_12 ( V_4 , V_1 , V_7 ,
V_8 - V_7 , L_3 ,
F_13 ( V_1 , V_7 ,
V_8 - V_7 )
) ;
}
V_7 = V_8 ;
}
if ( V_3 ) {
switch ( V_13 ) {
case V_25 :
V_6 = F_14 ( V_4 ,
V_26 , V_1 , 0 , 0 , 1 ) ;
F_15 ( V_6 ) ;
break;
case V_27 :
V_6 = F_14 ( V_4 ,
V_28 , V_1 , 0 , 0 , 1 ) ;
F_15 ( V_6 ) ;
break;
case V_29 :
V_6 = F_14 ( V_4 ,
V_30 , V_1 , 0 , 0 , 1 ) ;
F_15 ( V_6 ) ;
break;
case V_31 :
V_6 = F_14 ( V_4 ,
V_32 , V_1 , 0 , 0 , 1 ) ;
F_15 ( V_6 ) ;
break;
case V_18 :
default:
break;
}
}
V_14 = F_16 ( V_1 , V_7 ) ;
if ( V_14 > 0 ) {
F_17 ( V_33 ,
F_18 ( V_1 , V_7 ) , V_2 , V_4 ) ;
}
}
static int
F_6 ( const T_6 * V_34 , int V_11 , T_7 * type )
{
#define F_19 ( string , T_9 , T_10 ) { \
if (strncmp(data, string, length) == 0) { \
if (*type == ICAP_OTHER) \
*type = msgtype; \
return TRUE; \
} \
}
if ( V_11 >= 5 ) {
F_19 ( L_4 , 5 , V_31 ) ;
}
if ( V_11 >= 7 ) {
F_19 ( L_5 , 7 , V_27 ) ;
}
if ( V_11 >= 8 ) {
F_19 ( L_6 , 8 , V_25 ) ;
F_19 ( L_7 , 8 , V_29 ) ;
}
return FALSE ;
#undef F_19
}
void
F_20 ( void )
{
static T_11 V_35 [] = {
{ & V_32 ,
{ L_8 , L_9 ,
V_36 , V_37 , NULL , 0x0 ,
L_10 , V_38 } } ,
{ & V_28 ,
{ L_11 , L_12 ,
V_36 , V_37 , NULL , 0x0 ,
L_13 , V_38 } } ,
{ & V_30 ,
{ L_14 , L_15 ,
V_36 , V_37 , NULL , 0x0 ,
L_16 , V_38 } } ,
{ & V_26 ,
{ L_17 , L_18 ,
V_36 , V_37 , NULL , 0x0 ,
L_19 , V_38 } } ,
{ & V_39 ,
{ L_20 , L_21 ,
V_36 , V_37 , NULL , 0x0 ,
L_22 , V_38 } } ,
} ;
static T_5 * V_40 [] = {
& V_21 ,
} ;
V_19 = F_21 (
L_23 ,
L_1 , L_24 ) ;
F_22 ( V_19 , V_35 , F_23 ( V_35 ) ) ;
F_24 ( V_40 , F_23 ( V_40 ) ) ;
}
void
F_25 ( void )
{
T_12 V_41 ;
V_33 = F_26 ( L_25 ) ;
V_41 = F_27 ( F_1 , V_19 ) ;
F_28 ( L_26 , V_42 , V_41 ) ;
}
