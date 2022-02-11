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
if ( ! F_6 ( V_10 , V_13 ) ) {
return;
}
V_15 = F_7 () ;
if ( V_15 != V_16 ) {
if ( V_17 & V_18 ) {
F_8
( L_1 ,
( V_7 ) V_16 , ( V_7 ) V_15 ) ;
}
V_16 = V_15 ;
}
F_8 ( L_2 , V_12 , V_11 ) ;
if ( V_17 & V_18 ) {
F_8 ( L_3 , ( V_7 ) V_15 ) ;
}
F_8 ( L_4 ,
V_4 ,
F_3 ( V_6 ) ) ;
va_start ( args , V_14 ) ;
F_9 ( V_14 , args ) ;
va_end ( args ) ;
}
void T_2
F_10 ( V_7 V_10 ,
V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , const char * V_14 , ... )
{
T_4 args ;
if ( ! F_6 ( V_10 , V_13 ) ) {
return;
}
va_start ( args , V_14 ) ;
F_9 ( V_14 , args ) ;
va_end ( args ) ;
}
void
F_11 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_5 , V_20 ) ;
}
}
void
F_12 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , void * V_21 )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_6 , V_20 ,
V_21 ) ;
}
}
void
F_13 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , char * string )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_7 , V_20 ,
string ) ;
}
}
void
F_14 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , V_7 integer )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_8 ,
V_20 , integer ) ;
}
}
void
F_15 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_5 , V_22 ) ;
}
V_4 -- ;
}
void
F_16 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , T_5 V_23 )
{
if ( F_6 ( V_19 , V_13 ) ) {
if ( F_17 ( V_23 ) ) {
F_5 ( V_19 ,
V_11 , V_6 ,
V_12 , V_13 , L_7 ,
V_22 ,
F_18 ( V_23 ) ) ;
} else {
F_5 ( V_19 ,
V_11 , V_6 ,
V_12 , V_13 ,
L_9 ,
V_22 ,
F_18 ( V_23 ) ) ;
}
}
V_4 -- ;
}
void
F_19 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_6 V_24 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_10 ,
V_22 ,
F_20 ( V_24 ) ) ;
}
V_4 -- ;
}
void
F_21 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_7 * V_25 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_6 , V_22 ,
V_25 ) ;
}
V_4 -- ;
}
void F_22 ( T_7 * V_26 , V_7 V_27 , V_7 V_28 , V_7 V_29 )
{
V_7 V_30 = 0 ;
V_7 V_31 ;
V_7 V_32 ;
T_7 V_33 ;
if ( ! V_26 ) {
F_8 ( L_11 ) ;
return;
}
if ( ( V_27 < 4 ) || ( V_27 & 0x01 ) ) {
V_28 = V_34 ;
}
while ( V_30 < V_27 ) {
F_8 ( L_12 , ( V_29 + V_30 ) ) ;
for ( V_31 = 0 ; V_31 < 16 ; ) {
if ( V_30 + V_31 >= V_27 ) {
F_8 ( L_13 , ( ( V_28 * 2 ) + 1 ) , L_14 ) ;
V_31 += V_28 ;
continue;
}
switch ( V_28 ) {
case V_34 :
default:
F_8 ( L_15 ,
V_26 [ ( T_1 ) V_30 + V_31 ] ) ;
break;
case V_35 :
F_23 ( & V_32 ,
& V_26 [ ( T_1 ) V_30 + V_31 ] ) ;
F_8 ( L_16 , V_32 ) ;
break;
case V_36 :
F_24 ( & V_32 ,
& V_26 [ ( T_1 ) V_30 + V_31 ] ) ;
F_8 ( L_17 , V_32 ) ;
break;
case V_37 :
F_24 ( & V_32 ,
& V_26 [ ( T_1 ) V_30 + V_31 ] ) ;
F_8 ( L_18 , V_32 ) ;
F_24 ( & V_32 ,
& V_26 [ ( T_1 ) V_30 + V_31 +
4 ] ) ;
F_8 ( L_17 , V_32 ) ;
break;
}
V_31 += V_28 ;
}
F_8 ( L_14 ) ;
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ ) {
if ( V_30 + V_31 >= V_27 ) {
F_8 ( L_19 ) ;
return;
}
V_33 = V_26 [ ( T_1 ) V_30 + V_31 ] ;
if ( F_25 ( V_33 ) ) {
F_8 ( L_20 , V_33 ) ;
} else {
F_8 ( L_21 ) ;
}
}
F_8 ( L_19 ) ;
V_30 += 16 ;
}
return;
}
void
F_26 ( T_7 * V_26 , V_7 V_27 , V_7 V_28 , V_7 V_13 )
{
if ( ! ( ( V_38 & V_18 ) &&
( V_13 & V_39 ) ) ) {
return;
}
F_22 ( V_26 , V_27 , V_28 , 0 ) ;
}
