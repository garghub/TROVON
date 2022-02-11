static T_1 F_1 ( char * V_1 )
{
if ( ! ( V_2 & V_3 ) ) {
return ( FALSE ) ;
}
if ( V_4 ) {
return ( TRUE ) ;
}
if ( V_1 &&
( V_5 &&
strcmp ( V_5 , V_1 ) ) ) {
return ( FALSE ) ;
}
if ( ( V_2 & V_6 ) &&
! V_5 ) {
return ( FALSE ) ;
}
return ( TRUE ) ;
}
static const char * F_2 ( T_2 type )
{
switch ( type ) {
case V_7 :
return L_1 ;
case V_8 :
return L_2 ;
case V_9 :
return L_3 ;
default:
return L_4 ;
}
}
void
F_3 ( T_2 type ,
T_1 V_10 , T_1 * V_11 , char * V_12 )
{
F_4 ( V_13 ) ;
if ( V_12 ) {
F_5 ( ( V_14 ,
L_5 ,
F_2 ( type ) ,
V_10 ? L_6 : L_7 , V_11 , V_12 ) ) ;
} else {
F_5 ( ( V_14 ,
L_8 ,
F_2 ( type ) ,
V_10 ? L_6 : L_7 , V_11 ) ) ;
}
}
void
F_6 ( struct V_15 * V_16 ,
union V_17 * V_18 ,
struct V_19 * V_20 )
{
T_3 V_21 ;
char * V_12 = NULL ;
T_1 V_22 = FALSE ;
F_4 ( V_23 ) ;
if ( V_16 ) {
V_12 = F_7 ( V_16 , TRUE ) ;
}
V_21 = F_8 ( V_24 ) ;
if ( F_9 ( V_21 ) ) {
goto exit;
}
V_22 = F_1 ( V_12 ) ;
if ( V_22 && ! V_4 ) {
V_4 = V_18 ;
V_25 = V_26 ;
V_27 = V_28 ;
V_26 = V_29 ;
V_28 = V_30 ;
if ( V_31 ) {
V_26 = V_31 ;
}
if ( V_32 ) {
V_28 = V_32 ;
}
}
( void ) F_10 ( V_24 ) ;
exit:
if ( V_22 ) {
F_11 ( V_7 , TRUE ,
V_18 ? V_18 -> V_33 . V_34 : NULL ,
V_12 ) ;
}
if ( V_12 ) {
F_12 ( V_12 ) ;
}
}
void
F_13 ( struct V_15 * V_16 ,
union V_17 * V_18 ,
struct V_19 * V_20 )
{
T_3 V_21 ;
char * V_12 = NULL ;
T_1 V_22 ;
F_4 ( V_35 ) ;
if ( V_16 ) {
V_12 = F_7 ( V_16 , TRUE ) ;
}
V_21 = F_8 ( V_24 ) ;
if ( F_9 ( V_21 ) ) {
goto V_36;
}
V_22 = F_1 ( NULL ) ;
( void ) F_10 ( V_24 ) ;
if ( V_22 ) {
F_11 ( V_7 , FALSE ,
V_18 ? V_18 -> V_33 . V_34 : NULL ,
V_12 ) ;
}
V_21 = F_8 ( V_24 ) ;
if ( F_9 ( V_21 ) ) {
goto V_36;
}
if ( V_4 == V_18 ) {
if ( V_2 & V_6 ) {
V_5 = NULL ;
}
V_26 = V_25 ;
V_28 = V_27 ;
V_4 = NULL ;
}
( void ) F_10 ( V_24 ) ;
V_36:
if ( V_12 ) {
F_12 ( V_12 ) ;
}
}
void
F_14 ( union V_37 * V_38 ,
struct V_19 * V_20 )
{
F_4 ( V_39 ) ;
if ( F_1 ( NULL ) &&
( V_2 & V_40 ) ) {
F_11 ( V_8 , TRUE ,
V_38 -> V_41 . V_11 , V_38 -> V_41 . V_42 ) ;
}
}
void
F_15 ( union V_37 * V_38 ,
struct V_19 * V_20 )
{
F_4 ( V_43 ) ;
if ( F_1 ( NULL ) &&
( V_2 & V_40 ) ) {
F_11 ( V_8 , FALSE ,
V_38 -> V_41 . V_11 , V_38 -> V_41 . V_42 ) ;
}
}
