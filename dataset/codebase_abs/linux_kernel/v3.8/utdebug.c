void F_1 ( void )
{
T_1 V_1 ;
V_2 = & V_1 ;
}
void F_2 ( void )
{
T_1 V_1 ;
if ( & V_1 < V_3 ) {
V_3 = & V_1 ;
}
if ( V_4 > V_5 ) {
V_5 = V_4 ;
}
}
static const char * F_3 ( const char * V_6 )
{
if ( * ( F_4 ( V_7 , V_6 ) ) == V_8 ) {
return ( V_6 + 4 ) ;
}
if ( * ( F_4 ( V_7 , V_6 ) ) == V_9 ) {
return ( V_6 + 5 ) ;
}
return ( V_6 ) ;
}
void T_2
F_5 ( V_7 V_10 ,
V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , const char * V_14 , ... )
{
T_3 V_15 ;
T_4 args ;
if ( ! ( V_10 & V_16 ) ||
! ( V_13 & V_17 ) ) {
return;
}
V_15 = F_6 () ;
if ( V_15 != V_18 ) {
if ( V_19 & V_16 ) {
F_7
( L_1 ,
( V_7 ) V_18 , ( V_7 ) V_15 ) ;
}
V_18 = V_15 ;
}
F_7 ( L_2 , V_12 , V_11 ) ;
if ( V_19 & V_16 ) {
F_7 ( L_3 , ( V_7 ) V_15 ) ;
}
F_7 ( L_4 ,
V_4 ,
F_3 ( V_6 ) ) ;
va_start ( args , V_14 ) ;
F_8 ( V_14 , args ) ;
va_end ( args ) ;
}
void T_2
F_9 ( V_7 V_10 ,
V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , const char * V_14 , ... )
{
T_4 args ;
if ( ! ( V_10 & V_16 ) ||
! ( V_13 & V_17 ) ) {
return;
}
va_start ( args , V_14 ) ;
F_8 ( V_14 , args ) ;
va_end ( args ) ;
}
void
F_10 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
V_4 ++ ;
F_2 () ;
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_5 , V_21 ) ;
}
void
F_11 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , void * V_22 )
{
V_4 ++ ;
F_2 () ;
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_6 , V_21 , V_22 ) ;
}
void
F_12 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , char * string )
{
V_4 ++ ;
F_2 () ;
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_7 , V_21 , string ) ;
}
void
F_13 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , V_7 integer )
{
V_4 ++ ;
F_2 () ;
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_8 , V_21 , integer ) ;
}
void
F_14 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_5 , V_23 ) ;
V_4 -- ;
}
void
F_15 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , T_5 V_24 )
{
if ( F_16 ( V_24 ) ) {
F_5 ( V_20 ,
V_11 , V_6 , V_12 ,
V_13 , L_7 , V_23 ,
F_17 ( V_24 ) ) ;
} else {
F_5 ( V_20 ,
V_11 , V_6 , V_12 ,
V_13 , L_9 ,
V_23 ,
F_17 ( V_24 ) ) ;
}
V_4 -- ;
}
void
F_18 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_6 V_25 )
{
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_10 , V_23 ,
F_19 ( V_25 ) ) ;
V_4 -- ;
}
void
F_20 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_7 * V_26 )
{
F_5 ( V_20 ,
V_11 , V_6 , V_12 , V_13 ,
L_6 , V_23 , V_26 ) ;
V_4 -- ;
}
void F_21 ( T_7 * V_27 , V_7 V_28 , V_7 V_29 , V_7 V_30 )
{
V_7 V_31 = 0 ;
V_7 V_32 ;
V_7 V_33 ;
T_7 V_34 ;
if ( ! V_27 ) {
F_7 ( L_11 ) ;
return;
}
if ( ( V_28 < 4 ) || ( V_28 & 0x01 ) ) {
V_29 = V_35 ;
}
while ( V_31 < V_28 ) {
F_7 ( L_12 , ( V_30 + V_31 ) ) ;
for ( V_32 = 0 ; V_32 < 16 ; ) {
if ( V_31 + V_32 >= V_28 ) {
F_7 ( L_13 , ( ( V_29 * 2 ) + 1 ) , L_14 ) ;
V_32 += V_29 ;
continue;
}
switch ( V_29 ) {
case V_35 :
default:
F_7 ( L_15 ,
V_27 [ ( T_1 ) V_31 + V_32 ] ) ;
break;
case V_36 :
F_22 ( & V_33 ,
& V_27 [ ( T_1 ) V_31 + V_32 ] ) ;
F_7 ( L_16 , V_33 ) ;
break;
case V_37 :
F_23 ( & V_33 ,
& V_27 [ ( T_1 ) V_31 + V_32 ] ) ;
F_7 ( L_17 , V_33 ) ;
break;
case V_38 :
F_23 ( & V_33 ,
& V_27 [ ( T_1 ) V_31 + V_32 ] ) ;
F_7 ( L_18 , V_33 ) ;
F_23 ( & V_33 ,
& V_27 [ ( T_1 ) V_31 + V_32 +
4 ] ) ;
F_7 ( L_17 , V_33 ) ;
break;
}
V_32 += V_29 ;
}
F_7 ( L_14 ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
if ( V_31 + V_32 >= V_28 ) {
F_7 ( L_19 ) ;
return;
}
V_34 = V_27 [ ( T_1 ) V_31 + V_32 ] ;
if ( F_24 ( V_34 ) ) {
F_7 ( L_20 , V_34 ) ;
} else {
F_7 ( L_21 ) ;
}
}
F_7 ( L_19 ) ;
V_31 += 16 ;
}
return;
}
void
F_25 ( T_7 * V_27 , V_7 V_28 , V_7 V_29 , V_7 V_13 )
{
if ( ! ( ( V_39 & V_16 ) &&
( V_13 & V_17 ) ) ) {
return;
}
F_21 ( V_27 , V_28 , V_29 , 0 ) ;
}
