static void
F_1 ( const char * V_1 , T_1 V_2 )
{
fprintf ( V_3 , L_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
fprintf ( V_3 , L_2 ) ;
}
static void
F_2 ( const char * V_1 , T_1 V_2 )
{
vfprintf ( V_3 , V_1 , V_2 ) ;
fprintf ( V_3 , L_2 ) ;
}
static void
F_3 ( T_2 V_4 )
{
T_3 * V_5 ;
char * * V_6 ;
char * * V_7 ;
unsigned V_8 = 0 ;
if ( ! V_4 ) {
V_5 = stdout ;
}
else {
V_5 = V_3 ;
}
fprintf ( V_5 , L_3 ) ;
fprintf ( V_5 , L_4 ) ;
fprintf ( V_5 , L_5 ) ;
fprintf ( V_5 , L_6 ) ;
fprintf ( V_5 , L_2 ) ;
fprintf ( V_5 , L_7 ) ;
F_4 ( & V_6 , & V_7 ) ;
while ( V_6 [ V_8 ] && V_7 [ V_8 ] ) {
fprintf ( V_5 , L_8 , V_6 [ V_8 ] , V_7 [ V_8 ] ) ;
V_8 ++ ;
}
F_5 ( V_6 ) ;
F_5 ( V_7 ) ;
fprintf ( V_5 , L_9 ) ;
}
int
main ( int V_9 , char * * V_10 )
{
char * V_11 ;
int V_12 ;
int V_13 = - 1 ;
char * V_14 = NULL ;
int V_15 = 5000 ;
int V_16 = 1000 ;
T_4 * V_17 ;
T_5 * type = NULL ;
int V_18 = FALSE ;
T_6 * V_19 ;
int V_20 = V_21 ;
static const struct V_22 V_23 [] = {
{ L_10 , V_24 , NULL , 'h' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_6 () ;
V_11 = F_7 ( V_10 [ 0 ] , main ) ;
if ( V_11 != NULL ) {
fprintf ( V_3 ,
L_11 ,
V_11 ) ;
F_8 ( V_11 ) ;
}
F_9 () ;
F_10 ( F_1 , F_2 ) ;
#ifdef F_11
F_12 ( V_9 , V_10 ) ;
F_13 () ;
#endif
#ifdef F_14
F_15 ( F_1 , F_1 ,
NULL , NULL , NULL ) ;
F_16 ( V_25 ) ;
F_17 () ;
#endif
while ( ( V_12 = F_18 ( V_9 , V_10 , L_12 , V_23 , NULL ) ) != - 1 ) {
switch ( V_12 ) {
case 'b' :
V_15 = F_19 ( V_26 , L_13 ) ;
if ( V_15 > 65536 ) {
F_20 ( L_14 ) ;
V_20 = V_27 ;
goto V_28;
}
break;
case 'c' :
V_16 = F_19 ( V_26 , L_15 ) ;
break;
case 't' :
type = F_21 ( V_26 ) ;
break;
case 'h' :
F_3 ( FALSE ) ;
goto V_28;
break;
case 'r' :
V_18 = TRUE ;
break;
default:
F_3 ( TRUE ) ;
V_20 = V_27 ;
goto V_28;
break;
}
}
if ( V_9 > V_29 ) {
V_14 = V_10 [ V_29 ] ;
}
else {
F_3 ( TRUE ) ;
V_20 = V_27 ;
goto V_28;
}
if ( ! V_18 ) {
V_13 = F_22 ( type ) ;
F_8 ( type ) ;
V_17 = F_23 ( V_13 ) ;
if ( ! V_17 ) {
V_20 = V_27 ;
goto V_28;
}
V_20 = F_24 ( V_17 , V_14 , V_15 ) ;
if ( V_20 != V_21 )
goto V_28;
F_25 ( V_17 , V_16 ) ;
} else {
if ( type ) {
fprintf ( V_3 , L_16 ) ;
V_20 = V_30 ;
goto V_28;
}
V_13 = F_22 ( NULL ) ;
V_17 = F_23 ( V_13 ) ;
if ( ! V_17 ) {
V_20 = V_27 ;
goto V_28;
}
V_20 = F_24 ( V_17 , V_14 , V_15 ) ;
if ( V_20 != V_21 )
goto V_28;
while ( V_16 -- > 0 ) {
F_25 ( V_17 , 1 ) ;
V_13 = F_22 ( NULL ) ;
V_19 = V_17 -> V_31 ;
V_17 = F_23 ( V_13 ) ;
if ( ! V_17 ) {
V_20 = V_27 ;
goto V_28;
}
V_17 -> V_31 = V_19 ;
}
}
if ( ! F_26 ( V_17 ) ) {
V_20 = V_32 ;
}
V_28:
F_27 () ;
return V_20 ;
}
