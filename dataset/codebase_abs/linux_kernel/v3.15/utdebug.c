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
V_4 = 0 ;
}
F_8 ( L_2 , V_12 , V_11 ) ;
#ifdef F_9
if ( V_17 & V_18 ) {
F_8 ( L_3 , ( V_7 ) V_15 ) ;
}
F_8 ( L_4 , V_4 ) ;
#endif
F_8 ( L_5 , F_3 ( V_6 ) ) ;
va_start ( args , V_14 ) ;
F_10 ( V_14 , args ) ;
va_end ( args ) ;
}
void T_2
F_11 ( V_7 V_10 ,
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
F_10 ( V_14 , args ) ;
va_end ( args ) ;
}
void
F_12 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_6 , V_20 ) ;
}
}
void
F_13 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , void * V_21 )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_7 , V_20 ,
V_21 ) ;
}
}
void
F_14 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , char * string )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_8 , V_20 ,
string ) ;
}
}
void
F_15 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , V_7 integer )
{
V_4 ++ ;
F_2 () ;
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_9 ,
V_20 , integer ) ;
}
}
void
F_16 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_6 , V_22 ) ;
}
if ( V_4 ) {
V_4 -- ;
}
}
void
F_17 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 ,
V_7 V_13 , T_5 V_23 )
{
if ( F_6 ( V_19 , V_13 ) ) {
if ( F_18 ( V_23 ) ) {
F_5 ( V_19 ,
V_11 , V_6 ,
V_12 , V_13 , L_8 ,
V_22 ,
F_19 ( V_23 ) ) ;
} else {
F_5 ( V_19 ,
V_11 , V_6 ,
V_12 , V_13 ,
L_10 ,
V_22 ,
F_19 ( V_23 ) ) ;
}
}
if ( V_4 ) {
V_4 -- ;
}
}
void
F_20 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_6 V_24 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_11 ,
V_22 ,
F_21 ( V_24 ) ) ;
}
if ( V_4 ) {
V_4 -- ;
}
}
void
F_22 ( V_7 V_11 ,
const char * V_6 ,
const char * V_12 , V_7 V_13 , T_7 * V_25 )
{
if ( F_6 ( V_19 , V_13 ) ) {
F_5 ( V_19 ,
V_11 , V_6 , V_12 ,
V_13 , L_7 , V_22 ,
V_25 ) ;
}
if ( V_4 ) {
V_4 -- ;
}
}
