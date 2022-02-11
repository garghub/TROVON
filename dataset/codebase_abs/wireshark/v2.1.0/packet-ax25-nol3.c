static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
int V_7 ;
int V_8 ;
V_8 = 0 ;
V_7 = F_2 ( V_1 , V_8 ) ;
F_3 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_4 ( V_2 -> V_9 , V_11 , L_2 , F_5 ( V_1 , V_8 , 15 ) ) ;
if ( V_3 )
{
V_5 = F_6 ( V_3 , V_12 , V_1 , 0 , - 1 ,
L_3 , F_5 ( V_1 , V_8 , 15 ) ) ;
V_6 = F_7 ( V_5 , V_13 ) ;
V_8 = 0 ;
F_8 ( V_6 , V_14 , V_1 , V_8 , V_7 , V_15 | V_16 ) ;
}
return F_9 ( V_1 ) ;
}
static T_6
F_10 ( T_7 V_17 )
{
T_6 V_18 = FALSE ;
switch ( V_17 )
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
case '}' : V_18 = TRUE ; break;
default : break;
}
return V_18 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_19 ;
char * V_20 ;
int V_8 ;
T_1 * V_21 = NULL ;
T_7 V_17 = 0 ;
T_6 V_22 ;
V_20 = ( char * ) F_12 ( F_13 () , STRLEN ) ;
V_20 [ 0 ] = '\0' ;
F_3 ( V_2 -> V_9 , V_10 , L_4 ) ;
F_14 ( V_2 -> V_9 , V_11 ) ;
V_8 = 0 ;
F_15 ( V_20 , STRLEN , L_5 ) ;
if ( V_23 )
{
V_17 = F_16 ( V_1 , V_8 ) ;
if ( F_10 ( V_17 ) )
F_15 ( V_20 , STRLEN , L_6 ) ;
}
if ( V_24 )
{
if ( F_16 ( V_1 , V_8 ) == 'D' && F_16 ( V_1 , V_8 + 1 ) == 'X' )
F_15 ( V_20 , STRLEN , L_7 ) ;
}
F_17 ( V_2 -> V_9 , V_11 , V_20 ) ;
V_5 = F_6 ( V_3 ,
V_25 ,
V_1 ,
0 ,
- 1 ,
L_8 , V_20 ) ;
V_19 = F_7 ( V_5 , V_26 ) ;
V_21 = F_18 ( V_1 , V_8 ) ;
V_22 = FALSE ;
if ( V_23 )
{
if ( F_10 ( V_17 ) )
{
V_22 = TRUE ;
F_19 ( V_27 , V_21 , V_2 , V_19 ) ;
}
}
if ( V_24 )
{
if ( F_16 ( V_1 , V_8 ) == 'D' && F_16 ( V_1 , V_8 + 1 ) == 'X' )
{
V_22 = TRUE ;
F_1 ( V_21 , V_2 , V_19 , NULL ) ;
}
}
if ( ! V_22 )
F_20 ( V_21 , V_2 , V_19 ) ;
return F_9 ( V_1 ) ;
}
void
F_21 ( void )
{
T_8 * V_28 ;
#if 0
static hf_register_info hf[] = {
{ &hf_text,
{ "Text", "ax25_nol3.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
#endif
static T_9 V_29 [] = {
{ & V_14 ,
{ L_1 , L_9 ,
V_30 , V_31 , NULL , 0x0 ,
L_7 , V_32 }
} ,
} ;
static T_10 * V_33 [] = {
& V_26 ,
& V_13 ,
} ;
V_25 = F_22 ( L_10 , L_11 , L_12 ) ;
F_23 ( V_33 , F_24 ( V_33 ) ) ;
V_28 = F_25 ( V_25 , NULL ) ;
F_26 ( V_28 , L_13 ,
L_14 ,
L_15 ,
& V_23 ) ;
F_26 ( V_28 , L_16 ,
L_17 ,
L_18 ,
& V_24 ) ;
V_12 = F_22 ( L_7 , L_1 , L_19 ) ;
F_27 ( L_19 , F_1 , V_12 ) ;
F_28 ( V_12 , V_29 , F_24 ( V_29 ) ) ;
}
void
F_29 ( void )
{
F_30 ( L_20 , V_34 , F_31 ( F_11 , V_25 ) ) ;
V_27 = F_32 ( L_21 , V_25 ) ;
}
