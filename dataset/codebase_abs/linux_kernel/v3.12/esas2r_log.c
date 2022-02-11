static const char * F_1 ( const long V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
case V_9 :
default:
return V_10 ;
}
}
static int F_2 ( const long V_1 ,
const struct V_11 * V_12 ,
const char * V_13 ,
T_1 args )
{
if ( V_1 <= V_14 ) {
unsigned long V_15 = 0 ;
int V_16 = 0 ;
char * V_17 = V_18 ;
T_2 V_19 = V_20 ;
const char * V_21 = L_1 ;
const char * V_22 = L_2 ;
const char * V_23 =
F_1 ( V_1 ) ;
F_3 ( & V_24 , V_15 ) ;
if ( V_17 == NULL ) {
F_4 ( & V_24 , V_15 ) ;
return - 1 ;
}
memset ( V_17 , 0 , V_19 ) ;
if ( V_12 == NULL ) {
snprintf ( V_17 , V_19 , V_21 , V_23 ,
V_25 ) ;
} else {
snprintf ( V_17 , V_19 , V_22 , V_23 ,
V_25 ,
( V_12 -> V_26 ? V_12 -> V_26 -> V_27 : L_3 ) ,
( V_12 -> V_28 ? V_12 -> V_28 -> V_27 : L_3 ) ,
F_5 ( V_12 ) ) ;
}
V_17 += strlen ( V_18 ) ;
V_19 -= strlen ( V_18 ) ;
V_16 = vsnprintf ( V_17 , V_19 , V_13 , args ) ;
if ( V_16 < 0 ) {
F_4 ( & V_24 , V_15 ) ;
return - 1 ;
}
if ( strlen ( V_18 ) < V_19 )
strcat ( V_17 , L_4 ) ;
F_6 ( V_18 ) ;
F_4 ( & V_24 , V_15 ) ;
}
return 0 ;
}
int F_7 ( const long V_1 , const char * V_13 , ... )
{
int V_16 = 0 ;
T_1 args ;
va_start ( args , V_13 ) ;
V_16 = F_2 ( V_1 , NULL , V_13 , args ) ;
va_end ( args ) ;
return V_16 ;
}
int F_8 ( const long V_1 ,
const struct V_11 * V_12 ,
const char * V_13 ,
... )
{
int V_16 = 0 ;
T_1 args ;
va_start ( args , V_13 ) ;
V_16 = F_2 ( V_1 , V_12 , V_13 , args ) ;
va_end ( args ) ;
return V_16 ;
}
int F_9 ( const long V_1 ,
const void * V_29 ,
T_2 V_30 )
{
if ( V_1 <= V_14 ) {
F_10 ( F_1 ( V_1 ) ,
L_5 , V_31 , 16 , 1 , V_29 ,
V_30 , true ) ;
}
return 1 ;
}
