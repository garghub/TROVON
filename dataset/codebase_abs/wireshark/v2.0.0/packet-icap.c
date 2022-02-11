static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_4 * V_6 ;
T_1 * V_7 ;
T_5 V_8 = 0 ;
const T_6 * line ;
T_5 V_9 ;
const T_6 * V_10 , * V_11 ;
int V_12 ;
T_6 V_13 ;
T_7 V_14 ;
int V_15 ;
F_2 ( V_2 -> V_16 , V_17 , L_1 ) ;
V_12 = F_3 ( V_1 , V_8 , - 1 , & V_9 , FALSE ) ;
line = F_4 ( V_1 , V_8 , V_12 ) ;
V_14 = V_18 ;
if ( F_5 ( line , V_12 , & V_14 ) )
F_6 ( V_2 -> V_16 , V_19 ,
F_7 ( line , V_12 ) ) ;
else
F_2 ( V_2 -> V_16 , V_19 , L_2 ) ;
if ( V_3 ) {
V_5 = F_8 ( V_3 , V_20 , V_1 , V_8 , - 1 ,
V_21 ) ;
V_4 = F_9 ( V_5 , V_22 ) ;
}
V_14 = V_18 ;
while ( F_10 ( V_1 , V_8 ) ) {
T_8 V_23 = FALSE ;
T_8 V_24 = FALSE ;
V_12 = F_3 ( V_1 , V_8 , - 1 , & V_9 ,
FALSE ) ;
line = F_4 ( V_1 , V_8 , V_12 ) ;
V_11 = line + V_12 ;
if ( F_5 ( line , V_12 , & V_14 ) ) {
goto V_25;
}
if ( V_12 == 0 ) {
goto V_25;
}
V_10 = line ;
V_24 = FALSE ;
while ( V_10 < V_11 && ( ! V_24 ) ) {
V_13 = * V_10 ++ ;
if ( ! F_11 ( V_13 ) ) {
V_23 = FALSE ;
break;
}
switch ( V_13 ) {
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
V_23 = FALSE ;
V_24 = TRUE ;
break;
case ':' :
goto V_25;
}
}
if ( ! V_23 )
break;
V_25:
F_12 ( V_4 , V_1 , V_8 , V_9 - V_8 ) ;
V_8 = V_9 ;
}
if ( V_3 ) {
switch ( V_14 ) {
case V_26 :
V_6 = F_13 ( V_4 ,
V_27 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_6 ) ;
break;
case V_28 :
V_6 = F_13 ( V_4 ,
V_29 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_6 ) ;
break;
case V_30 :
V_6 = F_13 ( V_4 ,
V_31 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_6 ) ;
break;
case V_32 :
V_6 = F_13 ( V_4 ,
V_33 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_6 ) ;
break;
case V_18 :
default:
break;
}
}
V_15 = F_15 ( V_1 , V_8 ) ;
if ( V_15 > 0 ) {
if( V_34 ) {
V_7 = F_16 ( V_1 , V_8 ) ;
F_17 ( V_34 , V_7 , V_2 , V_4 ) ;
}
}
}
static int
F_5 ( const T_6 * V_35 , int V_12 , T_7 * type )
{
#define F_18 ( string , T_9 , T_10 ) { \
if (strncmp(data, string, length) == 0) { \
if (*type == ICAP_OTHER) \
*type = msgtype; \
return TRUE; \
} \
}
if ( V_12 >= 5 ) {
F_18 ( L_3 , 5 , V_32 ) ;
}
if ( V_12 >= 7 ) {
F_18 ( L_4 , 7 , V_28 ) ;
}
if ( V_12 >= 8 ) {
F_18 ( L_5 , 8 , V_26 ) ;
F_18 ( L_6 , 8 , V_30 ) ;
}
return FALSE ;
#undef F_18
}
void
F_19 ( void )
{
static T_11 V_36 [] = {
{ & V_33 ,
{ L_7 , L_8 ,
V_37 , V_38 , NULL , 0x0 ,
L_9 , V_39 } } ,
{ & V_29 ,
{ L_10 , L_11 ,
V_37 , V_38 , NULL , 0x0 ,
L_12 , V_39 } } ,
{ & V_31 ,
{ L_13 , L_14 ,
V_37 , V_38 , NULL , 0x0 ,
L_15 , V_39 } } ,
{ & V_27 ,
{ L_16 , L_17 ,
V_37 , V_38 , NULL , 0x0 ,
L_18 , V_39 } } ,
#if 0
{ &hf_icap_other,
{ "Other", "icap.other",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP other", HFILL }},
#endif
} ;
static T_5 * V_40 [] = {
& V_22 ,
} ;
V_20 = F_20 (
L_19 ,
L_1 , L_20 ) ;
F_21 ( V_20 , V_36 , F_22 ( V_36 ) ) ;
F_23 ( V_40 , F_22 ( V_40 ) ) ;
}
void
F_24 ( void )
{
T_12 V_41 ;
V_42 = F_25 ( L_21 ) ;
V_34 = F_25 ( L_22 ) ;
V_41 = F_26 ( F_1 , V_20 ) ;
F_27 ( L_23 , V_43 , V_41 ) ;
}
