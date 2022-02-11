static int F_1 ( bool * V_1 , const char * V_2 , ... )
{
T_1 args ;
int V_3 = 0 ;
if ( ! * V_1 ) {
V_3 += printf ( L_1 ) ;
} else {
V_3 += printf ( L_2 ) ;
* V_1 = false ;
}
va_start ( args , V_2 ) ;
V_3 += vprintf ( V_2 , args ) ;
va_end ( args ) ;
return V_3 ;
}
static int F_2 ( bool * V_1 , const char * V_4 , T_2 V_5 )
{
if ( V_5 == 0 )
return 0 ;
return F_1 ( V_1 , L_3 V_6 , V_4 , V_5 ) ;
}
static int F_3 ( const char * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_4 ( V_7 , V_14 , 0 , false , NULL ) ;
if ( V_11 == NULL )
return - V_15 ;
F_5 (pos, &session->evlist->entries, node) {
bool V_1 = true ;
printf ( L_4 , F_6 ( V_13 ) ) ;
if ( V_9 -> V_16 || V_9 -> V_17 ) {
F_1 ( & V_1 , L_5 V_6 ,
( T_2 ) V_13 -> V_18 . V_19 ) ;
}
if ( V_9 -> V_16 ) {
F_7 ( type ) ;
F_7 ( V_20 ) ;
F_7 ( V_21 ) ;
F_7 ( V_22 ) ;
F_7 ( V_23 ) ;
F_7 ( V_24 ) ;
F_7 ( V_25 ) ;
F_7 ( V_26 ) ;
F_7 ( V_27 ) ;
F_7 ( V_28 ) ;
F_7 ( V_29 ) ;
F_7 ( V_30 ) ;
F_7 ( V_31 ) ;
F_7 ( V_32 ) ;
F_7 ( V_33 ) ;
F_7 ( V_34 ) ;
F_7 ( V_35 ) ;
F_7 ( V_17 ) ;
F_7 ( V_36 ) ;
F_7 ( V_37 ) ;
F_7 ( V_38 ) ;
F_7 ( V_39 ) ;
F_7 ( V_40 ) ;
F_7 ( V_41 ) ;
F_7 ( V_42 ) ;
F_7 ( V_43 ) ;
F_7 ( V_44 ) ;
F_7 ( V_45 ) ;
F_7 ( V_46 ) ;
F_7 ( V_47 ) ;
F_7 ( V_48 ) ;
}
putchar ( '\n' ) ;
}
F_8 ( V_11 ) ;
return 0 ;
}
int F_9 ( int V_49 , const char * * V_50 , const char * T_3 V_51 )
{
struct V_8 V_9 = { . V_16 = false , } ;
const char * V_7 = NULL ;
const struct V_52 V_53 [] = {
F_10 ( 'i' , L_6 , & V_7 , L_7 ,
L_8 ) ,
F_11 ( 'F' , L_9 , & V_9 . V_17 ,
L_10 ) ,
F_11 ( 'v' , L_11 , & V_9 . V_16 ,
L_12 ) ,
F_12 ()
} ;
V_49 = F_13 ( V_49 , V_50 , V_53 , V_54 , 0 ) ;
if ( V_49 )
F_14 ( V_54 , V_53 ) ;
return F_3 ( V_7 , & V_9 ) ;
}
