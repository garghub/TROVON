static void F_1 ( const char * V_1 )
{
unsigned V_2 = 0 ;
char * * V_3 ;
char * * V_4 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 , V_1 ) ;
printf ( L_4 , V_1 ) ;
printf ( L_5 , V_1 ) ;
printf ( L_6
L_7 , V_1 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_14 ) ;
printf ( L_15 ) ;
printf ( L_16 ) ;
printf ( L_17 ) ;
printf ( L_18 ) ;
printf ( L_19 ) ;
printf ( L_20 ) ;
printf ( L_21 ) ;
printf ( L_22 ) ;
printf ( L_23 ) ;
printf ( L_24 ) ;
F_2 ( & V_3 , & V_4 ) ;
while ( V_3 [ V_2 ] && V_4 [ V_2 ] ) {
printf ( L_25 , V_3 [ V_2 ] , V_4 [ V_2 ] ) ;
V_2 ++ ;
}
printf ( L_26 ) ;
F_3 ( V_3 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( char * V_5 )
{
unsigned V_6 = 0 ;
unsigned V_2 = 0 ;
char * * V_3 ;
char * * V_4 ;
if ( ! V_5 ) {
F_5 ( L_27 ) ;
return V_7 ;
}
if ( F_6 ( V_5 , V_8 ) ) {
F_5 ( L_28 , V_8 ) ;
return V_7 ;
}
printf ( L_29
L_30 ,
V_6 ++ ) ;
printf ( L_31
L_32 ,
V_6 ++ ) ;
printf ( L_33
L_34 ,
V_6 ++ ) ;
printf ( L_35
L_36 ,
V_6 ++ ) ;
printf ( L_37
L_38 ,
V_6 ) ;
F_2 ( & V_3 , & V_4 ) ;
while ( V_3 [ V_2 ] && V_4 [ V_2 ] ) {
printf ( L_39 , V_6 , V_3 [ V_2 ] , V_4 [ V_2 ] ) ;
V_2 ++ ;
}
F_3 ( V_3 ) ;
F_3 ( V_4 ) ;
V_6 ++ ;
return V_9 ;
}
int main ( int V_10 , char * V_11 [] )
{
int V_12 = 0 ;
int V_13 ;
int V_14 = 5000 ;
T_1 V_15 = 1000 ;
int V_16 = FALSE ;
int V_17 = FALSE ;
char * type = NULL ;
int V_18 = - 1 ;
T_2 * V_19 ;
T_3 * V_20 ;
int V_2 ;
int V_21 = V_7 ;
#ifdef F_7
T_4 V_22 ;
#endif
T_5 * V_23 = F_8 ( T_5 , 1 ) ;
F_9 ( V_23 , V_24 , V_25 , V_26 , NULL ) ;
F_10 ( V_23 , V_8 , L_40 , 147 , L_41 ) ;
if ( V_10 == 1 ) {
F_1 ( V_11 [ 0 ] ) ;
goto V_27;
}
#ifdef F_7
F_11 () ;
#endif
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ ) {
F_12 ( L_42 , V_11 [ V_2 ] ) ;
}
F_12 ( L_26 ) ;
while ( ( V_13 = F_13 ( V_10 , V_11 , L_43 , V_28 , & V_12 ) ) != - 1 ) {
switch ( V_13 ) {
case V_29 :
printf ( L_44 , V_24 , V_25 , V_26 ) ;
V_21 = V_9 ;
goto V_27;
case V_30 :
V_31 = TRUE ;
break;
case V_32 :
F_1 ( V_11 [ 0 ] ) ;
V_21 = V_9 ;
goto V_27;
case V_33 :
V_14 = atoi ( V_34 ) ;
if ( V_14 > V_35 ) {
F_5 ( L_45 , V_35 ) ;
goto V_27;
}
break;
case V_36 :
V_15 = F_14 ( V_34 , NULL , 10 ) ;
break;
case V_37 :
if ( ! F_15 ( L_46 , V_34 ) ) {
V_16 = TRUE ;
}
break;
case V_38 :
if ( ! F_15 ( L_46 , V_34 ) ) {
V_17 = TRUE ;
}
break;
case V_39 :
F_16 ( type ) ;
type = F_17 ( V_34 ) ;
break;
case ':' :
F_5 ( L_47 , V_11 [ V_40 - 1 ] ) ;
break;
default:
if ( ! F_18 ( V_23 , V_13 - V_41 , V_34 ) )
{
F_5 ( L_48 , V_11 [ V_40 - 1 ] ) ;
goto V_27;
}
}
}
if ( V_40 != V_10 ) {
F_5 ( L_48 , V_11 [ V_40 ] ) ;
goto V_27;
}
if ( F_19 ( V_23 ) ) {
V_21 = V_9 ;
goto V_27;
}
if ( V_23 -> V_42 ) {
V_21 = F_4 ( V_23 -> V_5 ) ;
goto V_27;
}
if ( ( V_16 ) && ( V_17 ) ) {
F_5 ( L_49 ) ;
goto V_27;
}
if ( V_16 || V_17 ) {
F_16 ( type ) ;
type = NULL ;
}
#ifdef F_7
V_13 = F_20 ( F_21 ( 1 , 1 ) , & V_22 ) ;
if ( V_13 != 0 ) {
if ( V_31 )
F_5 ( L_50 , V_13 ) ;
goto V_27;
}
#endif
if ( V_23 -> V_43 ) {
if ( F_6 ( V_23 -> V_5 , V_8 ) ) {
F_5 ( L_51 ) ;
goto V_27;
}
F_22 () ;
if ( ! V_17 ) {
V_18 = F_23 ( type ) ;
V_19 = F_24 ( V_18 ) ;
if ( ! V_19 )
goto V_27;
F_12 ( L_52 , V_19 -> V_44 ) ;
F_25 ( V_19 , V_23 -> V_45 , V_14 ) ;
F_26 ( V_19 , V_15 ) ;
F_27 ( V_19 ) ;
} else {
V_18 = F_23 ( NULL ) ;
V_19 = F_24 ( V_18 ) ;
if ( ! V_19 )
goto V_27;
F_25 ( V_19 , V_23 -> V_45 , V_14 ) ;
while ( V_15 -- > 0 ) {
F_26 ( V_19 , 1 ) ;
V_18 = F_23 ( NULL ) ;
V_20 = V_19 -> V_46 ;
V_19 = F_24 ( V_18 ) ;
if ( ! V_19 )
goto V_27;
V_19 -> V_46 = V_20 ;
}
F_27 ( V_19 ) ;
}
V_21 = V_9 ;
}
V_27:
F_16 ( type ) ;
F_28 ( & V_23 ) ;
return V_21 ;
}
int T_6 F_29 ( T_7 V_47 , T_7 V_48 ,
T_8 V_49 , int V_50 ) {
return main ( V_51 , V_52 ) ;
}
