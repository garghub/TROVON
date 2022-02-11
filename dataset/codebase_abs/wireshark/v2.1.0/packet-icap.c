static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 = NULL ;
T_5 * V_6 = NULL ;
T_5 * V_7 ;
T_1 * V_8 ;
T_6 V_9 = 0 ;
const T_7 * line ;
T_6 V_10 ;
const T_7 * V_11 , * V_12 ;
int V_13 ;
T_7 V_14 ;
T_8 V_15 ;
int V_16 ;
F_2 ( V_2 -> V_17 , V_18 , L_1 ) ;
V_13 = F_3 ( V_1 , V_9 , - 1 , & V_10 , FALSE ) ;
line = F_4 ( V_1 , V_9 , V_13 ) ;
V_15 = V_19 ;
if ( F_5 ( line , V_13 , & V_15 ) )
F_6 ( V_2 -> V_17 , V_20 ,
F_7 ( line , V_13 ) ) ;
else
F_2 ( V_2 -> V_17 , V_20 , L_2 ) ;
if ( V_3 ) {
V_6 = F_8 ( V_3 , V_21 , V_1 , V_9 , - 1 ,
V_22 ) ;
V_5 = F_9 ( V_6 , V_23 ) ;
}
V_15 = V_19 ;
while ( F_10 ( V_1 , V_9 ) ) {
T_9 V_24 = FALSE ;
T_9 V_25 = FALSE ;
V_13 = F_3 ( V_1 , V_9 , - 1 , & V_10 ,
FALSE ) ;
line = F_4 ( V_1 , V_9 , V_13 ) ;
V_12 = line + V_13 ;
if ( F_5 ( line , V_13 , & V_15 ) ) {
goto V_26;
}
if ( V_13 == 0 ) {
goto V_26;
}
V_11 = line ;
V_25 = FALSE ;
while ( V_11 < V_12 && ( ! V_25 ) ) {
V_14 = * V_11 ++ ;
if ( ! F_11 ( V_14 ) ) {
V_24 = FALSE ;
break;
}
switch ( V_14 ) {
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
V_24 = FALSE ;
V_25 = TRUE ;
break;
case ':' :
goto V_26;
}
}
if ( ! V_24 )
break;
V_26:
F_12 ( V_5 , V_1 , V_9 , V_10 - V_9 ) ;
V_9 = V_10 ;
}
if ( V_3 ) {
switch ( V_15 ) {
case V_27 :
V_7 = F_13 ( V_5 ,
V_28 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_7 ) ;
break;
case V_29 :
V_7 = F_13 ( V_5 ,
V_30 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_7 ) ;
break;
case V_31 :
V_7 = F_13 ( V_5 ,
V_32 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_7 ) ;
break;
case V_33 :
V_7 = F_13 ( V_5 ,
V_34 , V_1 , 0 , 0 , 1 ) ;
F_14 ( V_7 ) ;
break;
case V_19 :
default:
break;
}
}
V_16 = F_15 ( V_1 , V_9 ) ;
if ( V_16 > 0 ) {
if( V_35 ) {
V_8 = F_16 ( V_1 , V_9 ) ;
F_17 ( V_35 , V_8 , V_2 , V_5 ) ;
}
}
return F_18 ( V_1 ) ;
}
static int
F_5 ( const T_7 * T_4 , int V_13 , T_8 * type )
{
#define F_19 ( string , T_10 , T_11 ) { \
if (strncmp(data, string, length) == 0) { \
if (*type == ICAP_OTHER) \
*type = msgtype; \
return TRUE; \
} \
}
if ( V_13 >= 5 ) {
F_19 ( L_3 , 5 , V_33 ) ;
}
if ( V_13 >= 7 ) {
F_19 ( L_4 , 7 , V_29 ) ;
}
if ( V_13 >= 8 ) {
F_19 ( L_5 , 8 , V_27 ) ;
F_19 ( L_6 , 8 , V_31 ) ;
}
return FALSE ;
#undef F_19
}
void
F_20 ( void )
{
static T_12 V_36 [] = {
{ & V_34 ,
{ L_7 , L_8 ,
V_37 , V_38 , NULL , 0x0 ,
L_9 , V_39 } } ,
{ & V_30 ,
{ L_10 , L_11 ,
V_37 , V_38 , NULL , 0x0 ,
L_12 , V_39 } } ,
{ & V_32 ,
{ L_13 , L_14 ,
V_37 , V_38 , NULL , 0x0 ,
L_15 , V_39 } } ,
{ & V_28 ,
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
static T_6 * V_40 [] = {
& V_23 ,
} ;
V_21 = F_21 (
L_19 ,
L_1 , L_20 ) ;
F_22 ( V_21 , V_36 , F_23 ( V_36 ) ) ;
F_24 ( V_40 , F_23 ( V_40 ) ) ;
}
void
F_25 ( void )
{
T_13 V_41 ;
V_35 = F_26 ( L_21 , V_21 ) ;
V_41 = F_27 ( F_1 , V_21 ) ;
F_28 ( L_22 , V_42 , V_41 ) ;
}
