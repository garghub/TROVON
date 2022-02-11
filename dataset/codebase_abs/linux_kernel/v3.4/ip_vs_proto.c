static int T_1 T_2 F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = F_2 ( V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 [ V_3 ] ;
V_6 [ V_3 ] = V_2 ;
if ( V_2 -> V_7 != NULL )
V_2 -> V_7 ( V_2 ) ;
return 0 ;
}
static int
F_3 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
unsigned V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_11 * V_12 =
F_5 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_5 = V_10 -> V_15 [ V_3 ] ;
V_10 -> V_15 [ V_3 ] = V_12 ;
F_6 ( & V_12 -> V_16 , 0 ) ;
if ( V_2 -> V_17 != NULL ) {
int V_18 = V_2 -> V_17 ( V_8 , V_12 ) ;
if ( V_18 ) {
V_10 -> V_15 [ V_3 ] = V_12 -> V_5 ;
F_7 ( V_12 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_1 * * V_19 ;
unsigned V_3 = F_2 ( V_2 -> V_4 ) ;
V_19 = & V_6 [ V_3 ] ;
for (; * V_19 ; V_19 = & ( * V_19 ) -> V_5 ) {
if ( * V_19 == V_2 ) {
* V_19 = V_2 -> V_5 ;
if ( V_2 -> exit != NULL )
V_2 -> exit ( V_2 ) ;
return 0 ;
}
}
return - V_20 ;
}
static int
F_9 ( struct V_8 * V_8 , struct V_11 * V_12 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * * V_21 ;
unsigned V_3 = F_2 ( V_12 -> V_2 -> V_4 ) ;
V_21 = & V_10 -> V_15 [ V_3 ] ;
for (; * V_21 ; V_21 = & ( * V_21 ) -> V_5 ) {
if ( * V_21 == V_12 ) {
* V_21 = V_12 -> V_5 ;
if ( V_12 -> V_2 -> V_22 != NULL )
V_12 -> V_2 -> V_22 ( V_8 , V_12 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
}
return - V_20 ;
}
struct V_1 * F_10 ( unsigned short V_23 )
{
struct V_1 * V_2 ;
unsigned V_3 = F_2 ( V_23 ) ;
for ( V_2 = V_6 [ V_3 ] ; V_2 ; V_2 = V_2 -> V_5 ) {
if ( V_2 -> V_4 == V_23 )
return V_2 ;
}
return NULL ;
}
struct V_11 *
F_11 ( struct V_9 * V_10 , unsigned short V_23 )
{
struct V_11 * V_12 ;
unsigned V_3 = F_2 ( V_23 ) ;
for ( V_12 = V_10 -> V_15 [ V_3 ] ; V_12 ; V_12 = V_12 -> V_5 ) {
if ( V_12 -> V_2 -> V_4 == V_23 )
return V_12 ;
}
return NULL ;
}
struct V_11 *
F_12 ( struct V_8 * V_8 , unsigned short V_23 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
return F_11 ( V_10 , V_23 ) ;
}
void F_13 ( struct V_9 * V_10 , int V_24 )
{
struct V_11 * V_12 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
for ( V_12 = V_10 -> V_15 [ V_25 ] ; V_12 ; V_12 = V_12 -> V_5 ) {
if ( V_12 -> V_2 -> V_27 )
V_12 -> V_2 -> V_27 ( V_12 , V_24 ) ;
}
}
}
int *
F_14 ( int * V_28 , int V_29 )
{
return F_15 ( V_28 , V_29 , V_13 ) ;
}
int
F_16 ( int * V_28 , int V_30 , const char * const * V_31 ,
const char * V_32 , int V_33 )
{
int V_25 ;
if ( ! V_28 || ! V_32 || ! V_33 )
return - V_34 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
if ( strcmp ( V_31 [ V_25 ] , V_32 ) )
continue;
V_28 [ V_25 ] = V_33 * V_35 ;
return 0 ;
}
return - V_36 ;
}
const char * F_17 ( T_3 V_23 , int V_37 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
if ( V_2 == NULL || V_2 -> V_38 == NULL )
return ( V_39 == V_23 ) ? L_1 : L_2 ;
return V_2 -> V_38 ( V_37 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
const struct V_40 * V_41 ,
int V_42 ,
const char * V_43 )
{
char V_44 [ 128 ] ;
struct V_45 V_46 , * V_47 ;
V_47 = F_19 ( V_41 , V_42 , sizeof( V_46 ) , & V_46 ) ;
if ( V_47 == NULL )
sprintf ( V_44 , L_3 ) ;
else if ( V_47 -> V_48 & F_20 ( V_49 ) )
sprintf ( V_44 , L_4 , & V_47 -> V_50 , & V_47 -> V_51 ) ;
else {
T_4 V_52 [ 2 ] , * V_53 ;
V_53 = F_19 ( V_41 , V_42 + V_47 -> V_54 * 4 ,
sizeof( V_52 ) , V_52 ) ;
if ( V_53 == NULL )
sprintf ( V_44 , L_5 ,
& V_47 -> V_50 , & V_47 -> V_51 ) ;
else
sprintf ( V_44 , L_6 ,
& V_47 -> V_50 , F_21 ( V_53 [ 0 ] ) ,
& V_47 -> V_51 , F_21 ( V_53 [ 1 ] ) ) ;
}
F_22 ( L_7 , V_43 , V_2 -> V_32 , V_44 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
const struct V_40 * V_41 ,
int V_42 ,
const char * V_43 )
{
char V_44 [ 192 ] ;
struct V_55 V_46 , * V_47 ;
V_47 = F_19 ( V_41 , V_42 , sizeof( V_46 ) , & V_46 ) ;
if ( V_47 == NULL )
sprintf ( V_44 , L_3 ) ;
else if ( V_47 -> V_56 == V_57 )
sprintf ( V_44 , L_8 , & V_47 -> V_50 , & V_47 -> V_51 ) ;
else {
T_4 V_52 [ 2 ] , * V_53 ;
V_53 = F_19 ( V_41 , V_42 + sizeof( struct V_55 ) ,
sizeof( V_52 ) , V_52 ) ;
if ( V_53 == NULL )
sprintf ( V_44 , L_9 ,
& V_47 -> V_50 , & V_47 -> V_51 ) ;
else
sprintf ( V_44 , L_10 ,
& V_47 -> V_50 , F_21 ( V_53 [ 0 ] ) ,
& V_47 -> V_51 , F_21 ( V_53 [ 1 ] ) ) ;
}
F_22 ( L_7 , V_43 , V_2 -> V_32 , V_44 ) ;
}
void
F_24 ( int V_58 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
int V_42 ,
const char * V_43 )
{
#ifdef F_25
if ( V_58 == V_59 )
F_23 ( V_2 , V_41 , V_42 , V_43 ) ;
else
#endif
F_18 ( V_2 , V_41 , V_42 , V_43 ) ;
}
int T_5 F_26 ( struct V_8 * V_8 )
{
int V_25 , V_18 ;
static struct V_1 * V_60 [] = {
#ifdef F_27
& V_61 ,
#endif
#ifdef F_28
& V_62 ,
#endif
#ifdef F_29
& V_63 ,
#endif
#ifdef F_30
& V_64 ,
#endif
#ifdef F_31
& V_65 ,
#endif
} ;
for ( V_25 = 0 ; V_25 < F_32 ( V_60 ) ; V_25 ++ ) {
V_18 = F_3 ( V_8 , V_60 [ V_25 ] ) ;
if ( V_18 < 0 )
goto V_66;
}
return 0 ;
V_66:
F_33 ( V_8 ) ;
return V_18 ;
}
void T_6 F_33 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * V_12 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
while ( ( V_12 = V_10 -> V_15 [ V_25 ] ) != NULL )
F_9 ( V_8 , V_12 ) ;
}
}
int T_2 F_34 ( void )
{
char V_67 [ 64 ] ;
#define F_35 ( T_7 ) \
do { \
register_ip_vs_protocol(p); \
strcat(protocols, ", "); \
strcat(protocols, (p)->name); \
} while (0)
V_67 [ 0 ] = '\0' ;
V_67 [ 2 ] = '\0' ;
#ifdef F_27
F_35 ( & V_61 ) ;
#endif
#ifdef F_28
F_35 ( & V_62 ) ;
#endif
#ifdef F_29
F_35 ( & V_63 ) ;
#endif
#ifdef F_30
F_35 ( & V_64 ) ;
#endif
#ifdef F_31
F_35 ( & V_65 ) ;
#endif
F_36 ( L_11 , & V_67 [ 2 ] ) ;
return 0 ;
}
void F_37 ( void )
{
struct V_1 * V_2 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
while ( ( V_2 = V_6 [ V_25 ] ) != NULL )
F_8 ( V_2 ) ;
}
}
