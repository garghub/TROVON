static void F_1 ( T_1 * V_1 )
{
unsigned V_2 = 0 ;
char * * V_3 ;
char * * V_4 ;
F_2 ( V_1 ) ;
printf ( L_1 ) ;
F_3 ( & V_3 , & V_4 ) ;
while ( V_3 [ V_2 ] && V_4 [ V_2 ] ) {
printf ( L_2 , V_3 [ V_2 ] , V_4 [ V_2 ] ) ;
V_2 ++ ;
}
printf ( L_3 ) ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
}
static int F_5 ( char * V_5 )
{
unsigned V_6 = 0 ;
unsigned V_2 = 0 ;
char * * V_3 ;
char * * V_4 ;
if ( ! V_5 ) {
F_6 ( L_4 ) ;
return V_7 ;
}
if ( F_7 ( V_5 , V_8 ) ) {
F_6 ( L_5 , V_8 ) ;
return V_7 ;
}
printf ( L_6
L_7 ,
V_6 ++ ) ;
printf ( L_8
L_9 ,
V_6 ++ ) ;
printf ( L_10
L_11 ,
V_6 ++ ) ;
printf ( L_12
L_13 ,
V_6 ++ ) ;
printf ( L_14
L_15 ,
V_6 ) ;
F_3 ( & V_3 , & V_4 ) ;
while ( V_3 [ V_2 ] && V_4 [ V_2 ] ) {
printf ( L_16 , V_6 , V_3 [ V_2 ] , V_4 [ V_2 ] ) ;
V_2 ++ ;
}
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
V_6 ++ ;
return V_9 ;
}
int main ( int V_10 , char * V_11 [] )
{
int V_12 = 0 ;
int V_13 ;
T_2 V_14 = 5000 ;
T_3 V_15 = 1000 ;
int V_16 = FALSE ;
int V_17 = FALSE ;
char * type = NULL ;
int V_18 = - 1 ;
T_4 * V_19 ;
T_5 * V_20 ;
int V_2 ;
int V_21 = V_7 ;
#ifdef F_8
T_6 V_22 ;
#endif
T_1 * V_1 = F_9 ( T_1 , 1 ) ;
char * V_23 ;
char * V_24 = NULL ;
V_23 = F_10 ( L_17 ) ;
F_11 ( V_1 , V_11 [ 0 ] , V_25 , V_26 ,
V_27 , V_23 ) ;
F_12 ( V_23 ) ;
F_13 ( V_1 , V_8 , L_18 , 147 , L_19 ) ;
V_24 = F_14 (
L_20
L_21
L_22
L_23
L_24 , V_11 [ 0 ] , V_11 [ 0 ] , V_8 , V_11 [ 0 ] , V_8 ,
V_11 [ 0 ] , V_8 ) ;
F_15 ( V_1 , V_24 ) ;
F_12 ( V_24 ) ;
F_16 ( V_1 , L_25 , L_26 ) ;
F_16 ( V_1 , L_27 , L_28 ) ;
F_16 ( V_1 , L_29 , L_30 ) ;
F_16 ( V_1 , L_31 , L_32 ) ;
F_16 ( V_1 , L_33 , L_34 ) ;
F_16 ( V_1 , L_35 , L_36 ) ;
F_16 ( V_1 , L_37 , L_38 ) ;
if ( V_10 == 1 ) {
F_1 ( V_1 ) ;
goto V_28;
}
#ifdef F_8
F_17 () ;
#endif
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ )
F_18 ( L_39 , V_11 [ V_2 ] ) ;
while ( ( V_13 = F_19 ( V_10 , V_11 , L_40 , V_29 , & V_12 ) ) != - 1 ) {
switch ( V_13 ) {
case V_30 :
printf ( L_41 , V_1 -> V_31 ) ;
V_21 = V_9 ;
goto V_28;
case V_32 :
F_1 ( V_1 ) ;
V_21 = V_9 ;
goto V_28;
case V_33 :
if ( ! F_20 ( V_34 , NULL , & V_14 ) ) {
F_6 ( L_42 ,
V_34 , V_35 ) ;
goto V_28;
}
break;
case V_36 :
if ( ! F_21 ( V_34 , NULL , & V_15 ) ) {
F_6 ( L_43 , V_34 ) ;
goto V_28;
}
break;
case V_37 :
if ( ! F_22 ( L_44 , V_34 ) ) {
V_16 = TRUE ;
}
break;
case V_38 :
if ( ! F_22 ( L_44 , V_34 ) ) {
V_17 = TRUE ;
}
break;
case V_39 :
F_12 ( type ) ;
type = F_23 ( V_34 ) ;
break;
case ':' :
F_6 ( L_45 , V_11 [ V_40 - 1 ] ) ;
break;
default:
if ( ! F_24 ( V_1 , V_13 - V_41 , V_34 ) )
{
F_6 ( L_46 , V_11 [ V_40 - 1 ] ) ;
goto V_28;
}
}
}
if ( V_40 != V_10 ) {
F_6 ( L_46 , V_11 [ V_40 ] ) ;
goto V_28;
}
if ( F_25 ( V_1 ) ) {
V_21 = V_9 ;
goto V_28;
}
if ( V_1 -> V_42 ) {
V_21 = F_5 ( V_1 -> V_5 ) ;
goto V_28;
}
if ( ( V_16 ) && ( V_17 ) ) {
F_6 ( L_47 ) ;
goto V_28;
}
if ( V_16 || V_17 ) {
F_12 ( type ) ;
type = NULL ;
}
#ifdef F_8
V_13 = F_26 ( F_27 ( 1 , 1 ) , & V_22 ) ;
if ( V_13 != 0 ) {
F_6 ( L_48 , V_13 ) ;
goto V_28;
}
#endif
if ( V_1 -> V_43 ) {
if ( F_7 ( V_1 -> V_5 , V_8 ) ) {
F_6 ( L_49 ) ;
goto V_28;
}
if ( ! V_17 ) {
V_18 = F_28 ( type ) ;
V_19 = F_29 ( V_18 ) ;
if ( ! V_19 )
goto V_28;
F_18 ( L_50 , V_19 -> V_44 ) ;
F_30 ( V_19 , V_1 -> V_45 , V_14 ) ;
F_31 ( V_19 , V_15 ) ;
F_32 ( V_19 ) ;
} else {
V_18 = F_28 ( NULL ) ;
V_19 = F_29 ( V_18 ) ;
if ( ! V_19 )
goto V_28;
F_30 ( V_19 , V_1 -> V_45 , V_14 ) ;
while ( V_15 -- > 0 ) {
F_31 ( V_19 , 1 ) ;
V_18 = F_28 ( NULL ) ;
V_20 = V_19 -> V_46 ;
V_19 = F_29 ( V_18 ) ;
if ( ! V_19 )
goto V_28;
V_19 -> V_46 = V_20 ;
}
F_32 ( V_19 ) ;
}
V_21 = V_9 ;
}
V_28:
F_12 ( type ) ;
F_33 ( & V_1 ) ;
return V_21 ;
}
int T_7
F_34 ( struct V_47 * V_48 ,
struct V_47 * V_49 ,
char * V_50 ,
int V_51 )
{
return main ( V_52 , V_53 ) ;
}
