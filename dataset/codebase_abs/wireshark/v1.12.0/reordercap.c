static void F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
if ( ! V_1 ) {
V_2 = stdout ;
}
else {
V_2 = V_3 ;
}
fprintf ( V_2 , L_1
#ifdef F_2
L_2 F_2 L_3 V_4 L_4
#endif
L_5 , V_5 ) ;
fprintf ( V_2 , L_6 ) ;
fprintf ( V_2 , L_7 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_8 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_9 ) ;
fprintf ( V_2 , L_10 ) ;
fprintf ( V_2 , L_11 ) ;
}
static void
F_3 ( T_3 * V_6 , T_4 * V_7 , T_5 * V_8 , T_6 * V_9 ,
const char * V_10 )
{
int V_11 ;
T_7 * V_12 ;
struct V_13 V_14 ;
memset ( & V_14 , 0 , sizeof( struct V_13 ) ) ;
F_4 ( L_12 V_15 L_13 ,
V_6 -> V_16 ) ;
if ( ! F_5 ( V_7 , V_6 -> V_16 , & V_14 , V_9 , & V_11 , & V_12 ) ) {
if ( V_11 != 0 ) {
fprintf ( V_3 ,
L_14 ,
V_10 , F_6 ( V_11 ) ) ;
switch ( V_11 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_3 , L_15 , V_12 ) ;
F_7 ( V_12 ) ;
break;
}
exit ( 1 ) ;
}
}
V_14 . V_20 = V_6 -> time ;
if ( ! F_8 ( V_8 , & V_14 , F_9 ( V_9 ) , & V_11 ) ) {
fprintf ( V_3 , L_16 ,
F_6 ( V_11 ) ) ;
exit ( 1 ) ;
}
}
static int
F_10 ( T_8 V_21 , T_8 V_22 )
{
const T_3 * V_23 = * ( const T_3 * const * ) V_21 ;
const T_3 * V_24 = * ( const T_3 * const * ) V_22 ;
const T_9 * V_25 = & V_23 -> time ;
const T_9 * V_26 = & V_24 -> time ;
return F_11 ( V_25 , V_26 ) ;
}
int main ( int V_27 , char * V_28 [] )
{
T_4 * V_7 = NULL ;
T_5 * V_8 = NULL ;
T_6 V_9 ;
int V_11 ;
T_7 * V_12 ;
T_10 V_29 ;
const struct V_13 * V_14 ;
T_11 V_30 = 0 ;
T_1 V_31 = TRUE ;
T_11 V_32 ;
T_12 * V_33 ;
T_13 * V_34 ;
T_14 * V_35 ;
T_3 * V_36 = NULL ;
int V_37 ;
int V_38 ;
char * V_10 ;
char * V_39 ;
while ( ( V_37 = F_12 ( V_27 , V_28 , L_17 ) ) != - 1 ) {
switch ( V_37 ) {
case 'n' :
V_31 = FALSE ;
break;
case 'h' :
F_1 ( FALSE ) ;
exit ( 0 ) ;
case '?' :
F_1 ( TRUE ) ;
exit ( 1 ) ;
}
}
V_38 = V_27 - V_40 ;
if ( V_38 == 2 ) {
V_10 = V_28 [ V_40 ] ;
V_39 = V_28 [ V_40 + 1 ] ;
}
else {
F_1 ( TRUE ) ;
exit ( 1 ) ;
}
V_7 = F_13 ( V_10 , V_41 , & V_11 , & V_12 , TRUE ) ;
if ( V_7 == NULL ) {
fprintf ( V_3 , L_18 , V_10 ,
F_6 ( V_11 ) ) ;
switch ( V_11 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_3 , L_15 , V_12 ) ;
F_7 ( V_12 ) ;
break;
}
exit ( 1 ) ;
}
F_4 ( L_19 , F_14 ( V_7 ) ) ;
V_33 = F_15 ( V_7 ) ;
V_34 = F_16 ( V_7 ) ;
V_8 = F_17 ( V_39 , F_14 ( V_7 ) , F_18 ( V_7 ) ,
65535 , FALSE , V_33 , V_34 , & V_11 ) ;
F_7 ( V_34 ) ;
if ( V_8 == NULL ) {
fprintf ( V_3 , L_20 ,
V_39 , F_6 ( V_11 ) ) ;
F_7 ( V_33 ) ;
exit ( 1 ) ;
}
V_35 = F_19 () ;
while ( F_20 ( V_7 , & V_11 , & V_12 , & V_29 ) ) {
T_3 * V_42 ;
V_14 = F_21 ( V_7 ) ;
V_42 = F_22 ( T_3 ) ;
V_42 -> V_43 = V_35 -> V_44 + 1 ;
V_42 -> V_16 = V_29 ;
if ( V_14 -> V_45 & V_46 ) {
V_42 -> time = V_14 -> V_20 ;
} else {
F_23 ( & V_42 -> time ) ;
}
if ( V_36 && F_10 ( & V_42 , & V_36 ) < 0 ) {
V_30 ++ ;
}
F_24 ( V_35 , V_42 ) ;
V_36 = V_42 ;
}
if ( V_11 != 0 ) {
fprintf ( V_3 ,
L_21 ,
V_10 , F_6 ( V_11 ) ) ;
switch ( V_11 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_3 , L_15 , V_12 ) ;
F_7 ( V_12 ) ;
break;
}
}
printf ( L_22 , V_35 -> V_44 , V_30 ) ;
if ( V_30 > 0 ) {
F_25 ( V_35 , F_10 ) ;
}
F_26 ( & V_9 , 1500 ) ;
for ( V_32 = 0 ; V_32 < V_35 -> V_44 ; V_32 ++ ) {
T_3 * V_6 = ( T_3 * ) V_35 -> V_47 [ V_32 ] ;
if ( V_31 || ( V_30 > 0 ) ) {
F_3 ( V_6 , V_7 , V_8 , & V_9 , V_10 ) ;
}
F_27 ( T_3 , V_6 ) ;
}
F_28 ( & V_9 ) ;
if ( ! V_31 && ( V_30 == 0 ) ) {
printf ( L_23 ) ;
}
F_29 ( V_35 , TRUE ) ;
if ( ! F_30 ( V_8 , & V_11 ) ) {
fprintf ( V_3 , L_24 , V_39 ,
F_6 ( V_11 ) ) ;
F_7 ( V_33 ) ;
exit ( 1 ) ;
}
F_7 ( V_33 ) ;
F_31 ( V_7 ) ;
return 0 ;
}
