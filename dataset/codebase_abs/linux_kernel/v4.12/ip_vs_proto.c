static int T_1 T_2 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 [ V_3 ] ;
V_6 [ V_3 ] = V_2 ;
if ( V_2 -> V_7 != NULL )
V_2 -> V_7 ( V_2 ) ;
return 0 ;
}
static int
F_3 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_10 * V_11 =
F_4 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_5 = V_9 -> V_14 [ V_3 ] ;
V_9 -> V_14 [ V_3 ] = V_11 ;
F_5 ( & V_11 -> V_15 , 0 ) ;
if ( V_2 -> V_16 != NULL ) {
int V_17 = V_2 -> V_16 ( V_9 , V_11 ) ;
if ( V_17 ) {
V_9 -> V_14 [ V_3 ] = V_11 -> V_5 ;
F_6 ( V_11 ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_1 * * V_18 ;
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
V_18 = & V_6 [ V_3 ] ;
for (; * V_18 ; V_18 = & ( * V_18 ) -> V_5 ) {
if ( * V_18 == V_2 ) {
* V_18 = V_2 -> V_5 ;
if ( V_2 -> exit != NULL )
V_2 -> exit ( V_2 ) ;
return 0 ;
}
}
return - V_19 ;
}
static int
F_8 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_10 * * V_20 ;
unsigned int V_3 = F_2 ( V_11 -> V_2 -> V_4 ) ;
V_20 = & V_9 -> V_14 [ V_3 ] ;
for (; * V_20 ; V_20 = & ( * V_20 ) -> V_5 ) {
if ( * V_20 == V_11 ) {
* V_20 = V_11 -> V_5 ;
if ( V_11 -> V_2 -> V_21 != NULL )
V_11 -> V_2 -> V_21 ( V_9 , V_11 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
}
return - V_19 ;
}
struct V_1 * F_9 ( unsigned short V_22 )
{
struct V_1 * V_2 ;
unsigned int V_3 = F_2 ( V_22 ) ;
for ( V_2 = V_6 [ V_3 ] ; V_2 ; V_2 = V_2 -> V_5 ) {
if ( V_2 -> V_4 == V_22 )
return V_2 ;
}
return NULL ;
}
struct V_10 *
F_10 ( struct V_8 * V_9 , unsigned short V_22 )
{
struct V_10 * V_11 ;
unsigned int V_3 = F_2 ( V_22 ) ;
for ( V_11 = V_9 -> V_14 [ V_3 ] ; V_11 ; V_11 = V_11 -> V_5 ) {
if ( V_11 -> V_2 -> V_4 == V_22 )
return V_11 ;
}
return NULL ;
}
void F_11 ( struct V_8 * V_9 , int V_23 )
{
struct V_10 * V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
for ( V_11 = V_9 -> V_14 [ V_24 ] ; V_11 ; V_11 = V_11 -> V_5 ) {
if ( V_11 -> V_2 -> V_26 )
V_11 -> V_2 -> V_26 ( V_11 , V_23 ) ;
}
}
}
int *
F_12 ( int * V_27 , int V_28 )
{
return F_13 ( V_27 , V_28 , V_12 ) ;
}
const char * F_14 ( T_3 V_22 , int V_29 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
if ( V_2 == NULL || V_2 -> V_30 == NULL )
return ( V_31 == V_22 ) ? L_1 : L_2 ;
return V_2 -> V_30 ( V_29 ) ;
}
static void
F_15 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
int V_34 ,
const char * V_35 )
{
char V_36 [ 128 ] ;
struct V_37 V_38 , * V_39 ;
V_39 = F_16 ( V_33 , V_34 , sizeof( V_38 ) , & V_38 ) ;
if ( V_39 == NULL )
sprintf ( V_36 , L_3 ) ;
else if ( V_39 -> V_40 & F_17 ( V_41 ) )
sprintf ( V_36 , L_4 , & V_39 -> V_42 , & V_39 -> V_43 ) ;
else {
T_4 V_44 [ 2 ] , * V_45 ;
V_45 = F_16 ( V_33 , V_34 + V_39 -> V_46 * 4 ,
sizeof( V_44 ) , V_44 ) ;
if ( V_45 == NULL )
sprintf ( V_36 , L_5 ,
& V_39 -> V_42 , & V_39 -> V_43 ) ;
else
sprintf ( V_36 , L_6 ,
& V_39 -> V_42 , F_18 ( V_45 [ 0 ] ) ,
& V_39 -> V_43 , F_18 ( V_45 [ 1 ] ) ) ;
}
F_19 ( L_7 , V_35 , V_2 -> V_47 , V_36 ) ;
}
static void
F_20 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
int V_34 ,
const char * V_35 )
{
char V_36 [ 192 ] ;
struct V_48 V_38 , * V_39 ;
V_39 = F_16 ( V_33 , V_34 , sizeof( V_38 ) , & V_38 ) ;
if ( V_39 == NULL )
sprintf ( V_36 , L_3 ) ;
else if ( V_39 -> V_49 == V_50 )
sprintf ( V_36 , L_8 , & V_39 -> V_42 , & V_39 -> V_43 ) ;
else {
T_4 V_44 [ 2 ] , * V_45 ;
V_45 = F_16 ( V_33 , V_34 + sizeof( struct V_48 ) ,
sizeof( V_44 ) , V_44 ) ;
if ( V_45 == NULL )
sprintf ( V_36 , L_9 ,
& V_39 -> V_42 , & V_39 -> V_43 ) ;
else
sprintf ( V_36 , L_10 ,
& V_39 -> V_42 , F_18 ( V_45 [ 0 ] ) ,
& V_39 -> V_43 , F_18 ( V_45 [ 1 ] ) ) ;
}
F_19 ( L_7 , V_35 , V_2 -> V_47 , V_36 ) ;
}
void
F_21 ( int V_51 , struct V_1 * V_2 ,
const struct V_32 * V_33 ,
int V_34 ,
const char * V_35 )
{
#ifdef F_22
if ( V_51 == V_52 )
F_20 ( V_2 , V_33 , V_34 , V_35 ) ;
else
#endif
F_15 ( V_2 , V_33 , V_34 , V_35 ) ;
}
int T_5 F_23 ( struct V_8 * V_9 )
{
int V_24 , V_17 ;
static struct V_1 * V_53 [] = {
#ifdef F_24
& V_54 ,
#endif
#ifdef F_25
& V_55 ,
#endif
#ifdef F_26
& V_56 ,
#endif
#ifdef F_27
& V_57 ,
#endif
#ifdef F_28
& V_58 ,
#endif
} ;
for ( V_24 = 0 ; V_24 < F_29 ( V_53 ) ; V_24 ++ ) {
V_17 = F_3 ( V_9 , V_53 [ V_24 ] ) ;
if ( V_17 < 0 )
goto V_59;
}
return 0 ;
V_59:
F_30 ( V_9 ) ;
return V_17 ;
}
void T_6 F_30 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_11 = V_9 -> V_14 [ V_24 ] ) != NULL )
F_8 ( V_9 , V_11 ) ;
}
}
int T_2 F_31 ( void )
{
char V_60 [ 64 ] ;
#define F_32 ( T_7 ) \
do { \
register_ip_vs_protocol(p); \
strcat(protocols, ", "); \
strcat(protocols, (p)->name); \
} while (0)
V_60 [ 0 ] = '\0' ;
V_60 [ 2 ] = '\0' ;
#ifdef F_24
F_32 ( & V_54 ) ;
#endif
#ifdef F_25
F_32 ( & V_55 ) ;
#endif
#ifdef F_26
F_32 ( & V_56 ) ;
#endif
#ifdef F_27
F_32 ( & V_57 ) ;
#endif
#ifdef F_28
F_32 ( & V_58 ) ;
#endif
F_33 ( L_11 , & V_60 [ 2 ] ) ;
return 0 ;
}
void F_34 ( void )
{
struct V_1 * V_2 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_2 = V_6 [ V_24 ] ) != NULL )
F_7 ( V_2 ) ;
}
}
