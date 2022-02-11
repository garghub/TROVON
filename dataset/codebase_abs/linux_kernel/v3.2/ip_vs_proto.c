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
if ( V_2 -> V_17 != NULL )
V_2 -> V_17 ( V_8 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_1 * * V_18 ;
unsigned V_3 = F_2 ( V_2 -> V_4 ) ;
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
F_8 ( struct V_8 * V_8 , struct V_11 * V_12 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * * V_20 ;
unsigned V_3 = F_2 ( V_12 -> V_2 -> V_4 ) ;
V_20 = & V_10 -> V_15 [ V_3 ] ;
for (; * V_20 ; V_20 = & ( * V_20 ) -> V_5 ) {
if ( * V_20 == V_12 ) {
* V_20 = V_12 -> V_5 ;
if ( V_12 -> V_2 -> V_21 != NULL )
V_12 -> V_2 -> V_21 ( V_8 , V_12 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
}
return - V_19 ;
}
struct V_1 * F_10 ( unsigned short V_22 )
{
struct V_1 * V_2 ;
unsigned V_3 = F_2 ( V_22 ) ;
for ( V_2 = V_6 [ V_3 ] ; V_2 ; V_2 = V_2 -> V_5 ) {
if ( V_2 -> V_4 == V_22 )
return V_2 ;
}
return NULL ;
}
struct V_11 *
F_11 ( struct V_9 * V_10 , unsigned short V_22 )
{
struct V_11 * V_12 ;
unsigned V_3 = F_2 ( V_22 ) ;
for ( V_12 = V_10 -> V_15 [ V_3 ] ; V_12 ; V_12 = V_12 -> V_5 ) {
if ( V_12 -> V_2 -> V_4 == V_22 )
return V_12 ;
}
return NULL ;
}
struct V_11 *
F_12 ( struct V_8 * V_8 , unsigned short V_22 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
return F_11 ( V_10 , V_22 ) ;
}
void F_13 ( struct V_9 * V_10 , int V_23 )
{
struct V_11 * V_12 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
for ( V_12 = V_10 -> V_15 [ V_24 ] ; V_12 ; V_12 = V_12 -> V_5 ) {
if ( V_12 -> V_2 -> V_26 )
V_12 -> V_2 -> V_26 ( V_12 , V_23 ) ;
}
}
}
int *
F_14 ( int * V_27 , int V_28 )
{
return F_15 ( V_27 , V_28 , V_13 ) ;
}
int
F_16 ( int * V_27 , int V_29 , const char * const * V_30 ,
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
const char * F_17 ( T_3 V_22 , int V_36 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
if ( V_2 == NULL || V_2 -> V_37 == NULL )
return ( V_38 == V_22 ) ? L_1 : L_2 ;
return V_2 -> V_37 ( V_36 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
char V_43 [ 128 ] ;
struct V_44 V_45 , * V_46 ;
V_46 = F_19 ( V_40 , V_41 , sizeof( V_45 ) , & V_45 ) ;
if ( V_46 == NULL )
sprintf ( V_43 , L_3 ) ;
else if ( V_46 -> V_47 & F_20 ( V_48 ) )
sprintf ( V_43 , L_4 , & V_46 -> V_49 , & V_46 -> V_50 ) ;
else {
T_4 V_51 [ 2 ] , * V_52 ;
V_52 = F_19 ( V_40 , V_41 + V_46 -> V_53 * 4 ,
sizeof( V_51 ) , V_51 ) ;
if ( V_52 == NULL )
sprintf ( V_43 , L_5 ,
& V_46 -> V_49 , & V_46 -> V_50 ) ;
else
sprintf ( V_43 , L_6 ,
& V_46 -> V_49 , F_21 ( V_52 [ 0 ] ) ,
& V_46 -> V_50 , F_21 ( V_52 [ 1 ] ) ) ;
}
F_22 ( L_7 , V_42 , V_2 -> V_31 , V_43 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
char V_43 [ 192 ] ;
struct V_54 V_45 , * V_46 ;
V_46 = F_19 ( V_40 , V_41 , sizeof( V_45 ) , & V_45 ) ;
if ( V_46 == NULL )
sprintf ( V_43 , L_3 ) ;
else if ( V_46 -> V_55 == V_56 )
sprintf ( V_43 , L_8 , & V_46 -> V_49 , & V_46 -> V_50 ) ;
else {
T_4 V_51 [ 2 ] , * V_52 ;
V_52 = F_19 ( V_40 , V_41 + sizeof( struct V_54 ) ,
sizeof( V_51 ) , V_51 ) ;
if ( V_52 == NULL )
sprintf ( V_43 , L_9 ,
& V_46 -> V_49 , & V_46 -> V_50 ) ;
else
sprintf ( V_43 , L_10 ,
& V_46 -> V_49 , F_21 ( V_52 [ 0 ] ) ,
& V_46 -> V_50 , F_21 ( V_52 [ 1 ] ) ) ;
}
F_22 ( L_7 , V_42 , V_2 -> V_31 , V_43 ) ;
}
void
F_24 ( int V_57 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
int V_41 ,
const char * V_42 )
{
#ifdef F_25
if ( V_57 == V_58 )
F_23 ( V_2 , V_40 , V_41 , V_42 ) ;
else
#endif
F_18 ( V_2 , V_40 , V_41 , V_42 ) ;
}
int T_5 F_26 ( struct V_8 * V_8 )
{
#ifdef F_27
F_3 ( V_8 , & V_59 ) ;
#endif
#ifdef F_28
F_3 ( V_8 , & V_60 ) ;
#endif
#ifdef F_29
F_3 ( V_8 , & V_61 ) ;
#endif
#ifdef F_30
F_3 ( V_8 , & V_62 ) ;
#endif
#ifdef F_31
F_3 ( V_8 , & V_63 ) ;
#endif
return 0 ;
}
void T_6 F_32 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * V_12 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_12 = V_10 -> V_15 [ V_24 ] ) != NULL )
F_8 ( V_8 , V_12 ) ;
}
}
int T_2 F_33 ( void )
{
char V_64 [ 64 ] ;
#define F_34 ( T_7 ) \
do { \
register_ip_vs_protocol(p); \
strcat(protocols, ", "); \
strcat(protocols, (p)->name); \
} while (0)
V_64 [ 0 ] = '\0' ;
V_64 [ 2 ] = '\0' ;
#ifdef F_27
F_34 ( & V_59 ) ;
#endif
#ifdef F_28
F_34 ( & V_60 ) ;
#endif
#ifdef F_29
F_34 ( & V_61 ) ;
#endif
#ifdef F_30
F_34 ( & V_62 ) ;
#endif
#ifdef F_31
F_34 ( & V_63 ) ;
#endif
F_35 ( L_11 , & V_64 [ 2 ] ) ;
return 0 ;
}
void F_36 ( void )
{
struct V_1 * V_2 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
while ( ( V_2 = V_6 [ V_24 ] ) != NULL )
F_7 ( V_2 ) ;
}
}
