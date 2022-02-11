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
V_11 = F_3 ( V_1 , V_7 , - 1 , & V_8 , FALSE ) ;
line = F_4 ( V_1 , V_7 , V_11 ) ;
V_13 = V_17 ;
if ( F_5 ( line , V_11 , & V_13 ) )
F_6 ( V_2 -> V_15 , V_18 ,
F_7 ( line , V_11 ) ) ;
else
F_2 ( V_2 -> V_15 , V_18 , L_2 ) ;
if ( V_3 ) {
V_5 = F_8 ( V_3 , V_19 , V_1 , V_7 , - 1 ,
V_20 ) ;
V_4 = F_9 ( V_5 , V_21 ) ;
}
V_13 = V_17 ;
while ( F_10 ( V_1 , V_7 ) ) {
T_8 V_22 = FALSE ;
T_8 V_23 = FALSE ;
V_11 = F_3 ( V_1 , V_7 , - 1 , & V_8 ,
FALSE ) ;
line = F_4 ( V_1 , V_7 , V_11 ) ;
V_10 = line + V_11 ;
if ( F_5 ( line , V_11 , & V_13 ) ) {
goto V_24;
}
if ( V_11 == 0 ) {
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
goto V_24;
}
}
if ( ! V_22 )
break;
V_24:
F_11 ( V_4 , V_1 , V_7 , V_8 - V_7 ) ;
V_7 = V_8 ;
}
if ( V_3 ) {
switch ( V_13 ) {
case V_25 :
V_6 = F_12 ( V_4 ,
V_26 , V_1 , 0 , 0 , 1 ) ;
F_13 ( V_6 ) ;
break;
case V_27 :
V_6 = F_12 ( V_4 ,
V_28 , V_1 , 0 , 0 , 1 ) ;
F_13 ( V_6 ) ;
break;
case V_29 :
V_6 = F_12 ( V_4 ,
V_30 , V_1 , 0 , 0 , 1 ) ;
F_13 ( V_6 ) ;
break;
case V_31 :
V_6 = F_12 ( V_4 ,
V_32 , V_1 , 0 , 0 , 1 ) ;
F_13 ( V_6 ) ;
break;
case V_17 :
default:
break;
}
}
V_14 = F_14 ( V_1 , V_7 ) ;
if ( V_14 > 0 ) {
F_15 ( V_33 ,
F_16 ( V_1 , V_7 ) , V_2 , V_4 ) ;
}
}
static int
F_5 ( const T_6 * V_34 , int V_11 , T_7 * type )
{
#define F_17 ( string , T_9 , T_10 ) { \
if (strncmp(data, string, length) == 0) { \
if (*type == ICAP_OTHER) \
*type = msgtype; \
return TRUE; \
} \
}
if ( V_11 >= 5 ) {
F_17 ( L_3 , 5 , V_31 ) ;
}
if ( V_11 >= 7 ) {
F_17 ( L_4 , 7 , V_27 ) ;
}
if ( V_11 >= 8 ) {
F_17 ( L_5 , 8 , V_25 ) ;
F_17 ( L_6 , 8 , V_29 ) ;
}
return FALSE ;
#undef F_17
}
void
F_18 ( void )
{
static T_11 V_35 [] = {
{ & V_32 ,
{ L_7 , L_8 ,
V_36 , V_37 , NULL , 0x0 ,
L_9 , V_38 } } ,
{ & V_28 ,
{ L_10 , L_11 ,
V_36 , V_37 , NULL , 0x0 ,
L_12 , V_38 } } ,
{ & V_30 ,
{ L_13 , L_14 ,
V_36 , V_37 , NULL , 0x0 ,
L_15 , V_38 } } ,
{ & V_26 ,
{ L_16 , L_17 ,
V_36 , V_37 , NULL , 0x0 ,
L_18 , V_38 } } ,
#if 0
{ &hf_icap_other,
{ "Other", "icap.other",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP other", HFILL }},
#endif
} ;
static T_5 * V_39 [] = {
& V_21 ,
} ;
V_19 = F_19 (
L_19 ,
L_1 , L_20 ) ;
F_20 ( V_19 , V_35 , F_21 ( V_35 ) ) ;
F_22 ( V_39 , F_21 ( V_39 ) ) ;
}
void
F_23 ( void )
{
T_12 V_40 ;
V_33 = F_24 ( L_21 ) ;
V_40 = F_25 ( F_1 , V_19 ) ;
F_26 ( L_22 , V_41 , V_40 ) ;
}
