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
int
F_14 ( int * V_27 , int V_29 , const char * const * V_30 ,
const char * V_31 , int V_32 )
{
int V_24 ;
if ( ! V_27 || ! V_31 || ! V_32 )
return - V_33 ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
if ( strcmp ( V_30 [ V_24 ] , V_31 ) )
continue;
V_27 [ V_24 ] = V_32 * V_34 ;
return 0 ;
}
return - V_35 ;
}
const char * F_15 ( T_3 V_22 , int V_36 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
if ( V_2 == NULL || V_2 -> V_37 == NULL )
return ( V_38 == V_22 ) ? L_1 : L_2 ;
return V_2 -> V_37 ( V_36 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
char V_43 [ 128 ] ;
struct V_44 V_45 , * V_46 ;
V_46 = F_17 ( V_40 , V_41 , sizeof( V_45 ) , & V_45 ) ;
if ( V_46 == NULL )
sprintf ( V_43 , L_3 ) ;
else if ( V_46 -> V_47 & F_18 ( V_48 ) )
sprintf ( V_43 , L_4 , & V_46 -> V_49 , & V_46 -> V_50 ) ;
else {
T_4 V_51 [ 2 ] , * V_52 ;
V_52 = F_17 ( V_40 , V_41 + V_46 -> V_53 * 4 ,
sizeof( V_51 ) , V_51 ) ;
if ( V_52 == NULL )
sprintf ( V_43 , L_5 ,
& V_46 -> V_49 , & V_46 -> V_50 ) ;
else
sprintf ( V_43 , L_6 ,
& V_46 -> V_49 , F_19 ( V_52 [ 0 ] ) ,
& V_46 -> V_50 , F_19 ( V_52 [ 1 ] ) ) ;
}
F_20 ( L_7 , V_42 , V_2 -> V_31 , V_43 ) ;
}
static void
F_21 ( struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
char V_43 [ 192 ] ;
struct V_54 V_45 , * V_46 ;
V_46 = F_17 ( V_40 , V_41 , sizeof( V_45 ) , & V_45 ) ;
if ( V_46 == NULL )
sprintf ( V_43 , L_3 ) ;
else if ( V_46 -> V_55 == V_56 )
sprintf ( V_43 , L_8 , & V_46 -> V_49 , & V_46 -> V_50 ) ;
else {
T_4 V_51 [ 2 ] , * V_52 ;
V_52 = F_17 ( V_40 , V_41 + sizeof( struct V_54 ) ,
sizeof( V_51 ) , V_51 ) ;
if ( V_52 == NULL )
sprintf ( V_43 , L_9 ,
& V_46 -> V_49 , & V_46 -> V_50 ) ;
else
sprintf ( V_43 , L_10 ,
& V_46 -> V_49 , F_19 ( V_52 [ 0 ] ) ,
& V_46 -> V_50 , F_19 ( V_52 [ 1 ] ) ) ;
}
F_20 ( L_7 , V_42 , V_2 -> V_31 , V_43 ) ;
}
void
F_22 ( int V_57 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
#ifdef F_23
if ( V_57 == V_58 )
F_21 ( V_2 , V_40 , V_41 , V_42 ) ;
else
#endif
F_16 ( V_2 , V_40 , V_41 , V_42 ) ;
}
int T_5 F_24 ( struct V_8 * V_9 )
{
int V_24 , V_17 ;
static struct V_1 * V_59 [] = {
#ifdef F_25
& V_60 ,
#endif
#ifdef F_26
& V_61 ,
#endif
#ifdef F_27
& V_62 ,
#endif
#ifdef F_28
& V_63 ,
#endif
#ifdef F_29
& V_64 ,
#endif
} ;
for ( V_24 = 0 ; V_24 < F_30 ( V_59 ) ; V_24 ++ ) {
V_17 = F_3 ( V_9 , V_59 [ V_24 ] ) ;
if ( V_17 < 0 )
goto V_65;
}
return 0 ;
V_65:
F_31 ( V_9 ) ;
return V_17 ;
}
void T_6 F_31 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_11 = V_9 -> V_14 [ V_24 ] ) != NULL )
F_8 ( V_9 , V_11 ) ;
}
}
int T_2 F_32 ( void )
{
char V_66 [ 64 ] ;
#define F_33 ( T_7 ) \
do { \
register_ip_vs_protocol(p); \
strcat(protocols, ", "); \
strcat(protocols, (p)->name); \
} while (0)
V_66 [ 0 ] = '\0' ;
V_66 [ 2 ] = '\0' ;
#ifdef F_25
F_33 ( & V_60 ) ;
#endif
#ifdef F_26
F_33 ( & V_61 ) ;
#endif
#ifdef F_27
F_33 ( & V_62 ) ;
#endif
#ifdef F_28
F_33 ( & V_63 ) ;
#endif
#ifdef F_29
F_33 ( & V_64 ) ;
#endif
F_34 ( L_11 , & V_66 [ 2 ] ) ;
return 0 ;
}
void F_35 ( void )
{
struct V_1 * V_2 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_2 = V_6 [ V_24 ] ) != NULL )
F_7 ( V_2 ) ;
}
}
