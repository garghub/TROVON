static void F_1 ( void )
{
fprintf ( V_1 , L_1
#ifdef F_2
L_2 F_2 L_3 V_2 L_4
#endif
L_5 , V_3 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_9 ) ;
fprintf ( V_1 , L_10 ) ;
}
static void
F_3 ( T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 ;
T_4 * V_8 ;
struct V_9 V_10 ;
T_5 V_11 [ 65535 ] ;
F_4 ( L_11 V_12 L_12 ,
V_4 -> V_13 , V_4 -> V_14 ) ;
F_5 ( V_5 ,
V_4 -> V_13 ,
& V_10 ,
V_11 ,
V_4 -> V_14 ,
& V_7 ,
& V_8 ) ;
F_4 ( L_13 , V_7 , V_11 ) ;
V_10 . V_15 = V_4 -> time ;
if ( ! F_6 ( V_6 , & V_10 , V_11 , & V_7 ) ) {
printf ( L_14 , F_7 ( V_7 ) ) ;
exit ( 1 ) ;
}
}
static int
F_8 ( T_6 V_16 , T_6 V_17 )
{
const T_1 * V_18 = * ( const T_1 * * ) V_16 ;
const T_1 * V_19 = * ( const T_1 * * ) V_17 ;
const struct V_20 * V_21 = & V_18 -> time ;
const struct V_20 * V_22 = & V_19 -> time ;
if ( V_21 -> V_23 > V_22 -> V_23 )
return 1 ;
if ( V_21 -> V_23 < V_22 -> V_23 )
return - 1 ;
if ( V_21 -> V_24 > V_22 -> V_24 )
return 1 ;
if ( V_21 -> V_24 < V_22 -> V_24 )
return - 1 ;
if ( V_18 -> V_25 > V_19 -> V_25 )
return 1 ;
if ( V_18 -> V_25 < V_19 -> V_25 )
return - 1 ;
return 0 ;
}
int main ( int V_26 , char * V_27 [] )
{
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
int V_7 ;
T_4 * V_28 ;
T_7 V_29 ;
const struct V_9 * V_10 ;
T_8 V_30 = 0 ;
T_9 V_31 = TRUE ;
T_8 V_32 ;
T_10 * V_33 ;
T_1 * V_34 = NULL ;
int V_35 ;
int V_36 ;
char * V_37 ;
char * V_38 ;
while ( ( V_35 = F_9 ( V_26 , V_27 , L_15 ) ) != - 1 ) {
switch ( V_35 ) {
case 'n' :
V_31 = FALSE ;
break;
case '?' :
F_1 () ;
exit ( 1 ) ;
}
}
V_36 = V_26 - V_39 ;
if ( V_36 == 2 ) {
V_37 = V_27 [ V_39 ] ;
V_38 = V_27 [ V_39 + 1 ] ;
}
else {
F_1 () ;
exit ( 1 ) ;
}
V_5 = F_10 ( V_37 , & V_7 , & V_28 , TRUE ) ;
if ( V_5 == NULL ) {
printf ( L_16 , V_37 , F_7 ( V_7 ) ) ;
exit ( 1 ) ;
}
F_4 ( L_17 , F_11 ( V_5 ) ) ;
V_6 = F_12 ( V_38 , F_11 ( V_5 ) , F_13 ( V_5 ) , 65535 , FALSE , & V_7 ) ;
if ( V_6 == NULL ) {
printf ( L_18 , V_38 , F_7 ( V_7 ) ) ;
exit ( 1 ) ;
}
V_33 = F_14 () ;
while ( F_15 ( V_5 , & V_7 , & V_28 , & V_29 ) ) {
T_1 * V_40 ;
V_10 = F_16 ( V_5 ) ;
V_40 = F_17 ( T_1 ) ;
V_40 -> V_25 = V_33 -> V_41 + 1 ;
V_40 -> V_13 = V_29 ;
V_40 -> V_14 = V_10 -> V_41 ;
V_40 -> time = V_10 -> V_15 ;
if ( V_34 && F_8 ( & V_40 , & V_34 ) < 0 ) {
V_30 ++ ;
}
F_18 ( V_33 , V_40 ) ;
V_34 = V_40 ;
}
printf ( L_19 , V_33 -> V_41 , V_30 ) ;
if ( V_30 > 0 ) {
F_19 ( V_33 , F_8 ) ;
}
for ( V_32 = 0 ; V_32 < V_33 -> V_41 ; V_32 ++ ) {
T_1 * V_4 = ( T_1 * ) V_33 -> V_42 [ V_32 ] ;
if ( V_31 || ( V_30 > 0 ) ) {
F_3 ( V_4 , V_5 , V_6 ) ;
}
F_20 ( T_1 , V_4 ) ;
}
if ( ! V_31 && ( V_30 == 0 ) ) {
printf ( L_20 ) ;
}
F_21 ( V_33 , TRUE ) ;
if ( ! F_22 ( V_6 , & V_7 ) ) {
printf ( L_21 , V_38 , F_7 ( V_7 ) ) ;
exit ( 1 ) ;
}
F_23 ( V_5 ) ;
return 0 ;
}
