const char * F_1 ( char * V_1 , const char * V_2 , T_1 V_3 )
{
const char * V_4 = V_2 ;
char * V_5 = V_1 ;
V_3 = F_2 ( T_1 , V_3 , V_6 ) ;
while ( V_3 -- ) {
if ( isprint ( * V_4 ) ) {
* V_5 ++ = * V_4 ++ ;
continue;
}
* V_5 ++ = '\\' ;
if ( * V_4 == '\0' )
* V_5 ++ = '0' ;
else if ( * V_4 == '\n' )
* V_5 ++ = 'n' ;
else if ( * V_4 == '\r' )
* V_5 ++ = 'r' ;
else if ( * V_4 == '\t' )
* V_5 ++ = 't' ;
else if ( * V_4 == '\\' )
* V_5 ++ = '\\' ;
else
V_5 += snprintf ( V_5 , 3 , L_1 , * V_4 ) ;
V_4 ++ ;
}
* V_5 = '\0' ;
return V_1 ;
}
int F_3 ( struct V_7 * V_8 , char * V_9 ,
T_2 * V_10 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_10 = V_10 ;
F_4 ( & V_8 -> V_11 ) ;
F_5 ( & V_8 -> V_12 , V_13 ,
( unsigned long ) V_8 ) ;
return 0 ;
}
void F_6 ( struct V_7 * V_8 )
{
int V_14 ;
F_7 ( V_8 ) ;
F_8 ( & V_8 -> V_12 ) ;
F_9 ( V_8 , 1 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_16 * V_17 = V_8 -> V_17 [ V_14 ] ;
if ( V_17 ) {
if ( V_17 -> V_18 ) {
V_17 -> V_18 -> V_19 ( V_17 -> V_20 ) ;
F_10 ( V_17 -> V_18 -> V_21 ) ;
}
F_11 ( V_17 ) ;
V_8 -> V_17 [ V_14 ] = NULL ;
}
}
}
void F_9 ( struct V_7 * V_8 , int V_22 )
{
struct V_16 * V_23 , * V_24 ;
unsigned long V_25 ;
F_12 ( V_8 -> V_10 , V_25 ) ;
F_13 (entry, next, &info->crypt_deinit_list, list) {
if ( F_14 ( & V_23 -> V_26 ) != 0 && ! V_22 )
continue;
F_15 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_18 ) {
V_23 -> V_18 -> V_19 ( V_23 -> V_20 ) ;
F_10 ( V_23 -> V_18 -> V_21 ) ;
}
F_11 ( V_23 ) ;
}
F_16 ( V_8 -> V_10 , V_25 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
unsigned long V_25 ;
F_12 ( V_8 -> V_10 , V_25 ) ;
V_8 -> V_28 = 1 ;
F_16 ( V_8 -> V_10 , V_25 ) ;
}
void V_13 ( unsigned long V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
unsigned long V_25 ;
F_9 ( V_8 , 0 ) ;
F_12 ( V_8 -> V_10 , V_25 ) ;
if ( ! F_17 ( & V_8 -> V_11 ) && ! V_8 -> V_28 ) {
F_18 ( V_30 L_2
L_3 , V_8 -> V_9 ) ;
V_8 -> V_12 . V_31 = V_32 + V_33 ;
F_19 ( & V_8 -> V_12 ) ;
}
F_16 ( V_8 -> V_10 , V_25 ) ;
}
void F_20 ( struct V_7 * V_8 ,
struct V_16 * * V_17 )
{
struct V_16 * V_34 ;
unsigned long V_25 ;
if ( * V_17 == NULL )
return;
V_34 = * V_17 ;
* V_17 = NULL ;
F_12 ( V_8 -> V_10 , V_25 ) ;
if ( ! V_8 -> V_28 ) {
F_21 ( & V_34 -> V_27 , & V_8 -> V_11 ) ;
if ( ! F_22 ( & V_8 -> V_12 ) ) {
V_8 -> V_12 . V_31 = V_32 + V_33 ;
F_19 ( & V_8 -> V_12 ) ;
}
}
F_16 ( V_8 -> V_10 , V_25 ) ;
}
int F_23 ( struct V_35 * V_18 )
{
unsigned long V_25 ;
struct V_36 * V_37 ;
V_37 = F_24 ( sizeof( * V_37 ) , V_38 ) ;
if ( V_37 == NULL )
return - V_39 ;
V_37 -> V_18 = V_18 ;
F_12 ( & V_40 , V_25 ) ;
F_21 ( & V_37 -> V_27 , & V_41 ) ;
F_16 ( & V_40 , V_25 ) ;
F_18 ( V_30 L_4 ,
V_18 -> V_9 ) ;
return 0 ;
}
int F_25 ( struct V_35 * V_18 )
{
struct V_36 * V_37 ;
unsigned long V_25 ;
F_12 ( & V_40 , V_25 ) ;
F_26 (alg, &lib80211_crypto_algs, list) {
if ( V_37 -> V_18 == V_18 )
goto V_42;
}
F_16 ( & V_40 , V_25 ) ;
return - V_43 ;
V_42:
F_18 ( V_30 L_5 ,
V_18 -> V_9 ) ;
F_15 ( & V_37 -> V_27 ) ;
F_16 ( & V_40 , V_25 ) ;
F_11 ( V_37 ) ;
return 0 ;
}
struct V_35 * F_27 ( const char * V_9 )
{
struct V_36 * V_37 ;
unsigned long V_25 ;
F_12 ( & V_40 , V_25 ) ;
F_26 (alg, &lib80211_crypto_algs, list) {
if ( strcmp ( V_37 -> V_18 -> V_9 , V_9 ) == 0 )
goto V_42;
}
F_16 ( & V_40 , V_25 ) ;
return NULL ;
V_42:
F_16 ( & V_40 , V_25 ) ;
return V_37 -> V_18 ;
}
static void * F_28 ( int V_44 )
{
return ( void * ) 1 ;
}
static void F_29 ( void * V_20 )
{
}
static int T_3 F_30 ( void )
{
F_31 ( V_45 L_6 ) ;
return F_23 ( & V_46 ) ;
}
static void T_4 F_32 ( void )
{
F_25 ( & V_46 ) ;
F_33 ( ! F_17 ( & V_41 ) ) ;
}
