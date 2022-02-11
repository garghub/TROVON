static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 ;
int V_6 ;
int V_7 ;
V_7 = 0 ;
V_6 = F_2 ( V_1 , V_7 ) ;
F_3 ( V_2 -> V_8 , V_9 , L_1 ) ;
F_4 ( V_2 -> V_8 , V_10 , L_2 , F_5 ( V_1 , V_7 , 15 ) ) ;
if ( V_3 )
{
V_4 = F_6 ( V_3 , V_11 , V_1 , 0 , - 1 ,
L_3 , F_5 ( V_1 , V_7 , 15 ) ) ;
V_5 = F_7 ( V_4 , V_12 ) ;
V_7 = 0 ;
F_8 ( V_5 , V_13 , V_1 , V_7 , V_6 , V_14 | V_15 ) ;
}
}
static T_5
F_9 ( T_6 V_16 )
{
T_5 V_17 = FALSE ;
switch ( V_16 )
{
case 0x1c :
case 0x1d :
case '!' :
case '#' :
case '$' :
case '%' :
case '&' :
case ')' :
case '*' :
case '+' :
case ',' :
case '.' :
case '/' :
case ':' :
case ';' :
case '<' :
case '=' :
case '>' :
case '?' :
case '@' :
case 'T' :
case '[' :
case '\'' :
case '_' :
case '`' :
case '{' :
case '}' : V_17 = TRUE ; break;
default : break;
}
return V_17 ;
}
static void
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_18 ;
char * V_19 ;
int V_7 ;
T_1 * V_20 = NULL ;
T_6 V_16 = 0 ;
T_5 V_21 ;
V_19 = ( char * ) F_11 ( F_12 () , STRLEN ) ;
V_19 [ 0 ] = '\0' ;
F_3 ( V_2 -> V_8 , V_9 , L_4 ) ;
F_13 ( V_2 -> V_8 , V_10 ) ;
V_7 = 0 ;
F_14 ( V_19 , STRLEN , L_5 ) ;
if ( V_22 )
{
V_16 = F_15 ( V_1 , V_7 ) ;
if ( F_9 ( V_16 ) )
F_14 ( V_19 , STRLEN , L_6 ) ;
}
if ( V_23 )
{
if ( F_15 ( V_1 , V_7 ) == 'D' && F_15 ( V_1 , V_7 + 1 ) == 'X' )
F_14 ( V_19 , STRLEN , L_7 ) ;
}
F_16 ( V_2 -> V_8 , V_10 , V_19 ) ;
if ( V_3 )
{
V_4 = F_6 ( V_3 ,
V_24 ,
V_1 ,
0 ,
- 1 ,
L_8 , V_19 ) ;
V_18 = F_7 ( V_4 , V_25 ) ;
V_20 = F_17 ( V_1 , V_7 ) ;
V_21 = FALSE ;
if ( V_22 )
{
if ( F_9 ( V_16 ) )
{
V_21 = TRUE ;
F_18 ( V_26 , V_20 , V_2 , V_18 ) ;
}
}
if ( V_23 )
{
if ( F_15 ( V_1 , V_7 ) == 'D' && F_15 ( V_1 , V_7 + 1 ) == 'X' )
{
V_21 = TRUE ;
F_1 ( V_20 , V_2 , V_18 ) ;
}
}
if ( ! V_21 )
F_18 ( V_27 , V_20 , V_2 , V_18 ) ;
}
}
void
F_19 ( void )
{
T_7 * V_28 ;
#if 0
static hf_register_info hf[] = {
{ &hf_text,
{ "Text", "ax25_nol3.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
#endif
static T_8 V_29 [] = {
{ & V_13 ,
{ L_1 , L_9 ,
V_30 , V_31 , NULL , 0x0 ,
L_7 , V_32 }
} ,
} ;
static T_9 * V_33 [] = {
& V_25 ,
& V_12 ,
} ;
V_24 = F_20 ( L_10 , L_11 , L_12 ) ;
F_21 ( V_33 , F_22 ( V_33 ) ) ;
V_28 = F_23 ( V_24 , NULL ) ;
F_24 ( V_28 , L_13 ,
L_14 ,
L_15 ,
& V_22 ) ;
F_24 ( V_28 , L_16 ,
L_17 ,
L_18 ,
& V_23 ) ;
V_11 = F_20 ( L_7 , L_1 , L_19 ) ;
F_25 ( L_19 , F_1 , V_11 ) ;
F_26 ( V_11 , V_29 , F_22 ( V_29 ) ) ;
}
void
F_27 ( void )
{
F_28 ( L_20 , V_34 , F_29 ( F_10 , V_24 ) ) ;
V_26 = F_30 ( L_21 ) ;
V_27 = F_30 ( L_22 ) ;
}
