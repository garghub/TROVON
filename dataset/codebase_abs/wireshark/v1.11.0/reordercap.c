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
F_3 ( T_1 * V_4 , T_2 * V_5 , T_3 * V_6 , T_4 * V_7 ,
const char * V_8 )
{
int V_9 ;
T_5 * V_10 ;
struct V_11 V_12 ;
F_4 ( L_11 V_13 L_12 ,
V_4 -> V_14 , V_4 -> V_15 ) ;
if ( ! F_5 ( V_5 , V_4 -> V_14 , & V_12 , V_7 , V_4 -> V_15 ,
& V_9 , & V_10 ) ) {
if ( V_9 != 0 ) {
fprintf ( V_1 ,
L_13 ,
V_8 , F_6 ( V_9 ) ) ;
switch ( V_9 ) {
case V_16 :
case V_17 :
case V_18 :
fprintf ( V_1 , L_14 , V_10 ) ;
F_7 ( V_10 ) ;
break;
}
exit ( 1 ) ;
}
}
V_12 . V_19 = V_4 -> time ;
if ( ! F_8 ( V_6 , & V_12 , F_9 ( V_7 ) , & V_9 ) ) {
fprintf ( V_1 , L_15 ,
F_6 ( V_9 ) ) ;
exit ( 1 ) ;
}
}
static int
F_10 ( T_6 V_20 , T_6 V_21 )
{
const T_1 * V_22 = * ( const T_1 * * ) V_20 ;
const T_1 * V_23 = * ( const T_1 * * ) V_21 ;
const struct V_24 * V_25 = & V_22 -> time ;
const struct V_24 * V_26 = & V_23 -> time ;
if ( V_25 -> V_27 > V_26 -> V_27 )
return 1 ;
if ( V_25 -> V_27 < V_26 -> V_27 )
return - 1 ;
if ( V_25 -> V_28 > V_26 -> V_28 )
return 1 ;
if ( V_25 -> V_28 < V_26 -> V_28 )
return - 1 ;
if ( V_22 -> V_29 > V_23 -> V_29 )
return 1 ;
if ( V_22 -> V_29 < V_23 -> V_29 )
return - 1 ;
return 0 ;
}
int main ( int V_30 , char * V_31 [] )
{
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_4 V_7 ;
int V_9 ;
T_5 * V_10 ;
T_7 V_32 ;
const struct V_11 * V_12 ;
T_8 V_33 = 0 ;
T_9 V_34 = TRUE ;
T_8 V_35 ;
T_10 * V_36 ;
T_11 * V_37 ;
T_12 * V_38 ;
T_1 * V_39 = NULL ;
int V_40 ;
int V_41 ;
char * V_8 ;
char * V_42 ;
while ( ( V_40 = F_11 ( V_30 , V_31 , L_16 ) ) != - 1 ) {
switch ( V_40 ) {
case 'n' :
V_34 = FALSE ;
break;
case '?' :
F_1 () ;
exit ( 1 ) ;
}
}
V_41 = V_30 - V_43 ;
if ( V_41 == 2 ) {
V_8 = V_31 [ V_43 ] ;
V_42 = V_31 [ V_43 + 1 ] ;
}
else {
F_1 () ;
exit ( 1 ) ;
}
V_5 = F_12 ( V_8 , & V_9 , & V_10 , TRUE ) ;
if ( V_5 == NULL ) {
fprintf ( V_1 , L_17 , V_8 ,
F_6 ( V_9 ) ) ;
switch ( V_9 ) {
case V_16 :
case V_17 :
case V_18 :
fprintf ( V_1 , L_14 , V_10 ) ;
F_7 ( V_10 ) ;
break;
}
exit ( 1 ) ;
}
F_4 ( L_18 , F_13 ( V_5 ) ) ;
V_36 = F_14 ( V_5 ) ;
V_37 = F_15 ( V_5 ) ;
V_6 = F_16 ( V_42 , F_13 ( V_5 ) , F_17 ( V_5 ) ,
65535 , FALSE , V_36 , V_37 , & V_9 ) ;
F_7 ( V_37 ) ;
if ( V_6 == NULL ) {
fprintf ( V_1 , L_19 ,
V_42 , F_6 ( V_9 ) ) ;
F_7 ( V_36 ) ;
exit ( 1 ) ;
}
V_38 = F_18 () ;
while ( F_19 ( V_5 , & V_9 , & V_10 , & V_32 ) ) {
T_1 * V_44 ;
V_12 = F_20 ( V_5 ) ;
V_44 = F_21 ( T_1 ) ;
V_44 -> V_29 = V_38 -> V_45 + 1 ;
V_44 -> V_14 = V_32 ;
V_44 -> V_15 = V_12 -> V_45 ;
V_44 -> time = V_12 -> V_19 ;
if ( V_39 && F_10 ( & V_44 , & V_39 ) < 0 ) {
V_33 ++ ;
}
F_22 ( V_38 , V_44 ) ;
V_39 = V_44 ;
}
if ( V_9 != 0 ) {
fprintf ( V_1 ,
L_20 ,
V_8 , F_6 ( V_9 ) ) ;
switch ( V_9 ) {
case V_16 :
case V_17 :
case V_18 :
fprintf ( V_1 , L_14 , V_10 ) ;
F_7 ( V_10 ) ;
break;
}
}
printf ( L_21 , V_38 -> V_45 , V_33 ) ;
if ( V_33 > 0 ) {
F_23 ( V_38 , F_10 ) ;
}
F_24 ( & V_7 , 1500 ) ;
for ( V_35 = 0 ; V_35 < V_38 -> V_45 ; V_35 ++ ) {
T_1 * V_4 = ( T_1 * ) V_38 -> V_46 [ V_35 ] ;
if ( V_34 || ( V_33 > 0 ) ) {
F_3 ( V_4 , V_5 , V_6 , & V_7 , V_8 ) ;
}
F_25 ( T_1 , V_4 ) ;
}
F_26 ( & V_7 ) ;
if ( ! V_34 && ( V_33 == 0 ) ) {
printf ( L_22 ) ;
}
F_27 ( V_38 , TRUE ) ;
if ( ! F_28 ( V_6 , & V_9 ) ) {
fprintf ( V_1 , L_23 , V_42 ,
F_6 ( V_9 ) ) ;
F_7 ( V_36 ) ;
exit ( 1 ) ;
}
F_7 ( V_36 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
