static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( F_3 ( ! V_8 ) )
return NULL ;
V_8 -> V_4 = V_4 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_3 = F_4 ( V_3 ) ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_8 )
{
F_6 ( & V_10 ) ;
F_7 ( & V_8 -> V_11 , & V_12 ) ;
F_8 ( & V_10 ) ;
F_9 ( L_1 ,
V_8 -> V_4 , V_8 ) ;
}
static unsigned int F_10 ( struct V_1 * V_8 ,
T_1 V_13 )
{
T_1 V_14 = V_8 -> V_15 . V_16 . V_14 ;
int V_17 = V_8 -> V_15 . V_16 . V_17 ;
if ( F_3 ( V_13 < V_14 || V_13 >= V_14 + V_17 ) )
return 0 ;
return V_13 - V_14 + V_8 -> V_15 . V_16 . V_18 ;
}
struct V_1 * F_11 ( struct V_2 * V_3 ,
unsigned int V_17 ,
unsigned int V_18 ,
T_1 V_14 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int V_19 ;
V_8 = F_1 ( V_3 , V_20 , V_6 , V_7 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 . V_16 . V_18 = V_18 ;
V_8 -> V_15 . V_16 . V_14 = V_14 ;
V_8 -> V_15 . V_16 . V_17 = V_17 ;
F_6 ( & V_10 ) ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
int V_21 = V_18 + V_19 ;
struct V_22 * V_22 = F_12 ( V_21 ) ;
if ( F_3 ( ! V_22 || V_22 -> V_8 ) ) {
F_8 ( & V_10 ) ;
F_13 ( V_8 -> V_3 ) ;
F_14 ( V_8 ) ;
return NULL ;
}
}
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
struct V_22 * V_22 = F_12 ( V_18 + V_19 ) ;
V_22 -> V_13 = V_14 + V_19 ;
V_22 -> V_8 = V_8 ;
}
F_8 ( & V_10 ) ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
int V_21 = V_18 + V_19 ;
int V_13 = V_14 + V_19 ;
if ( ! V_21 )
continue;
V_6 -> V_23 ( V_8 , V_21 , V_13 ) ;
F_15 ( V_21 , V_24 ) ;
}
F_5 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_16 ( struct V_2 * V_3 ,
unsigned int V_17 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int * V_25 ;
V_25 = F_2 ( sizeof( * V_25 ) * V_17 , V_9 ) ;
if ( F_3 ( ! V_25 ) )
return NULL ;
V_8 = F_1 ( V_3 , V_26 , V_6 , V_7 ) ;
if ( ! V_8 ) {
F_14 ( V_25 ) ;
return NULL ;
}
V_8 -> V_15 . V_27 . V_17 = V_17 ;
V_8 -> V_15 . V_27 . V_25 = V_25 ;
F_5 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_17 ( struct V_2 * V_3 ,
unsigned int V_28 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_29 , V_6 , V_7 ) ;
if ( V_8 ) {
V_8 -> V_15 . V_30 . V_28 = V_28 ? V_28 : ~ 0 ;
F_5 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_18 ( struct V_2 * V_3 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_31 , V_6 , V_7 ) ;
if ( V_8 ) {
F_19 ( & V_8 -> V_15 . V_32 , V_9 ) ;
F_5 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_20 ( struct V_2 * V_33 )
{
struct V_1 * V_34 , * V_35 = NULL ;
int V_36 ;
F_6 ( & V_10 ) ;
F_21 (h, &irq_domain_list, link) {
if ( V_34 -> V_6 -> V_37 )
V_36 = V_34 -> V_6 -> V_37 ( V_34 , V_33 ) ;
else
V_36 = ( V_34 -> V_3 != NULL ) && ( V_34 -> V_3 == V_33 ) ;
if ( V_36 ) {
V_35 = V_34 ;
break;
}
}
F_8 ( & V_10 ) ;
return V_35 ;
}
void F_22 ( struct V_1 * V_8 )
{
F_9 ( L_2 , V_8 ) ;
V_38 = V_8 ;
}
static int F_23 ( struct V_1 * V_8 , unsigned int V_39 ,
T_1 V_13 )
{
struct V_22 * V_22 = F_12 ( V_39 ) ;
V_22 -> V_13 = V_13 ;
V_22 -> V_8 = V_8 ;
if ( V_8 -> V_6 -> V_23 ( V_8 , V_39 , V_13 ) ) {
F_9 ( L_3 ) ;
V_22 -> V_8 = NULL ;
V_22 -> V_13 = 0 ;
return - 1 ;
}
F_15 ( V_39 , V_24 ) ;
return 0 ;
}
unsigned int F_24 ( struct V_1 * V_8 )
{
unsigned int V_39 ;
if ( V_8 == NULL )
V_8 = V_38 ;
F_25 ( V_8 == NULL ) ;
F_3 ( V_8 -> V_4 != V_29 ) ;
V_39 = F_26 ( 1 , 0 ) ;
if ( ! V_39 ) {
F_9 ( L_4 ) ;
return 0 ;
}
if ( V_39 >= V_8 -> V_15 . V_30 . V_28 ) {
F_27 ( L_5 ,
V_8 -> V_15 . V_30 . V_28 ) ;
F_28 ( V_39 ) ;
return 0 ;
}
F_9 ( L_6 , V_39 ) ;
if ( F_23 ( V_8 , V_39 , V_39 ) ) {
F_28 ( V_39 ) ;
return 0 ;
}
return V_39 ;
}
unsigned int F_29 ( struct V_1 * V_8 ,
T_1 V_13 )
{
unsigned int V_40 ;
int V_39 ;
F_9 ( L_7 , V_8 , V_13 ) ;
if ( V_8 == NULL )
V_8 = V_38 ;
if ( V_8 == NULL ) {
F_30 ( V_41 L_8
L_9 , V_13 ) ;
F_3 ( 1 ) ;
return 0 ;
}
F_9 ( L_10 , V_8 ) ;
V_39 = F_31 ( V_8 , V_13 ) ;
if ( V_39 ) {
F_9 ( L_11 , V_39 ) ;
return V_39 ;
}
if ( V_8 -> V_4 == V_20 )
return F_10 ( V_8 , V_13 ) ;
V_40 = V_13 % V_42 ;
if ( V_40 == 0 )
V_40 ++ ;
V_39 = F_26 ( V_40 , 0 ) ;
if ( V_39 <= 0 )
V_39 = F_26 ( 1 , 0 ) ;
if ( V_39 <= 0 ) {
F_9 ( L_12 ) ;
return 0 ;
}
if ( F_23 ( V_8 , V_39 , V_13 ) ) {
if ( V_8 -> V_4 != V_20 )
F_28 ( V_39 ) ;
return 0 ;
}
F_9 ( L_13 ,
V_13 , V_8 -> V_3 ? V_8 -> V_3 -> V_43 : L_14 , V_39 ) ;
return V_39 ;
}
unsigned int F_32 ( struct V_2 * V_44 ,
const T_2 * V_45 , unsigned int V_46 )
{
struct V_1 * V_8 ;
T_1 V_13 ;
unsigned int type = V_47 ;
unsigned int V_39 ;
V_8 = V_44 ? F_20 ( V_44 ) : V_38 ;
if ( ! V_8 ) {
#ifdef F_33
if ( V_46 > 0 )
return V_45 [ 0 ] ;
#endif
F_30 ( V_41 L_15 ,
V_44 -> V_43 ) ;
return 0 ;
}
if ( V_8 -> V_6 -> V_48 == NULL )
V_13 = V_45 [ 0 ] ;
else {
if ( V_8 -> V_6 -> V_48 ( V_8 , V_44 , V_45 , V_46 ,
& V_13 , & type ) )
return 0 ;
}
V_39 = F_29 ( V_8 , V_13 ) ;
if ( ! V_39 )
return V_39 ;
if ( type != V_47 &&
type != ( F_34 ( F_12 ( V_39 ) ) ) )
F_35 ( V_39 , type ) ;
return V_39 ;
}
void F_36 ( unsigned int V_39 )
{
struct V_22 * V_22 = F_12 ( V_39 ) ;
struct V_1 * V_8 ;
T_1 V_13 ;
if ( ! V_39 || ! V_22 )
return;
V_8 = V_22 -> V_8 ;
if ( F_3 ( V_8 == NULL ) )
return;
if ( V_8 -> V_4 == V_20 )
return;
F_37 ( V_39 , V_24 ) ;
F_38 ( V_39 , NULL , NULL ) ;
F_39 ( V_39 ) ;
if ( V_8 -> V_6 -> V_49 )
V_8 -> V_6 -> V_49 ( V_8 , V_39 ) ;
F_40 () ;
V_13 = V_22 -> V_13 ;
switch( V_8 -> V_4 ) {
case V_26 :
if ( V_13 < V_8 -> V_15 . V_27 . V_17 )
V_8 -> V_15 . V_27 . V_25 [ V_13 ] = 0 ;
break;
case V_31 :
F_6 ( & V_50 ) ;
F_41 ( & V_8 -> V_15 . V_32 , V_13 ) ;
F_8 ( & V_50 ) ;
break;
}
F_28 ( V_39 ) ;
}
unsigned int F_31 ( struct V_1 * V_8 ,
T_1 V_13 )
{
unsigned int V_19 ;
unsigned int V_40 = V_13 % V_42 ;
if ( V_8 == NULL )
V_8 = V_38 ;
if ( V_8 == NULL )
return 0 ;
if ( V_8 -> V_4 == V_20 )
return F_10 ( V_8 , V_13 ) ;
if ( V_40 == 0 )
V_40 = 1 ;
V_19 = V_40 ;
do {
struct V_22 * V_51 = F_12 ( V_19 ) ;
if ( V_51 && ( V_51 -> V_8 == V_8 ) && ( V_51 -> V_13 == V_13 ) )
return V_19 ;
V_19 ++ ;
if ( V_19 >= V_42 )
V_19 = 1 ;
} while( V_19 != V_40 );
return 0 ;
}
unsigned int F_42 ( struct V_1 * V_8 ,
T_1 V_13 )
{
struct V_22 * V_22 ;
if ( F_43 ( V_8 -> V_4 != V_31 ) )
return F_31 ( V_8 , V_13 ) ;
F_44 () ;
V_22 = F_45 ( & V_8 -> V_15 . V_32 , V_13 ) ;
F_46 () ;
return V_22 ? V_22 -> V_21 : F_31 ( V_8 , V_13 ) ;
}
void F_47 ( struct V_1 * V_8 , unsigned int V_39 ,
T_1 V_13 )
{
struct V_22 * V_22 = F_12 ( V_39 ) ;
if ( F_3 ( V_8 -> V_4 != V_31 ) )
return;
if ( V_39 ) {
F_6 ( & V_50 ) ;
F_48 ( & V_8 -> V_15 . V_32 , V_13 , V_22 ) ;
F_8 ( & V_50 ) ;
}
}
unsigned int F_49 ( struct V_1 * V_8 ,
T_1 V_13 )
{
unsigned int * V_25 ;
if ( F_43 ( V_8 -> V_4 != V_26 ) )
return F_31 ( V_8 , V_13 ) ;
if ( F_50 ( V_13 >= V_8 -> V_15 . V_27 . V_17 ) )
return F_31 ( V_8 , V_13 ) ;
V_25 = V_8 -> V_15 . V_27 . V_25 ;
if ( F_50 ( V_25 == NULL ) )
return F_31 ( V_8 , V_13 ) ;
if ( F_50 ( ! V_25 [ V_13 ] ) )
V_25 [ V_13 ] = F_31 ( V_8 , V_13 ) ;
return V_25 [ V_13 ] ;
}
static int F_51 ( struct V_52 * V_53 , void * V_54 )
{
unsigned long V_55 ;
struct V_56 * V_57 ;
const char * V_58 ;
static const char V_59 [] = L_16 ;
void * V_51 ;
int V_19 ;
F_52 ( V_53 , L_17 , L_18 , L_19 ,
L_20 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_21 ,
L_22 ) ;
for ( V_19 = 1 ; V_19 < V_42 ; V_19 ++ ) {
V_57 = F_53 ( V_19 ) ;
if ( ! V_57 )
continue;
F_54 ( & V_57 -> V_60 , V_55 ) ;
if ( V_57 -> V_61 && V_57 -> V_61 -> V_62 ) {
struct V_63 * V_64 ;
F_52 ( V_53 , L_23 , V_19 ) ;
F_52 ( V_53 , L_24 , V_57 -> V_22 . V_13 ) ;
V_64 = F_55 ( V_57 ) ;
if ( V_64 && V_64 -> V_65 )
V_58 = V_64 -> V_65 ;
else
V_58 = V_59 ;
F_52 ( V_53 , L_25 , V_58 ) ;
V_51 = F_56 ( V_57 ) ;
F_52 ( V_53 , V_51 ? L_26 : L_27 , V_51 ) ;
if ( V_57 -> V_22 . V_8 && V_57 -> V_22 . V_8 -> V_3 )
V_58 = V_57 -> V_22 . V_8 -> V_3 -> V_43 ;
else
V_58 = V_59 ;
F_52 ( V_53 , L_28 , V_58 ) ;
}
F_57 ( & V_57 -> V_60 , V_55 ) ;
}
return 0 ;
}
static int F_58 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_59 ( V_67 , F_51 , V_66 -> V_68 ) ;
}
static int T_3 F_60 ( void )
{
if ( F_61 ( L_29 , V_69 , NULL ,
NULL , & V_70 ) == NULL )
return - V_71 ;
return 0 ;
}
int F_62 ( struct V_1 * V_72 , unsigned int V_21 ,
T_1 V_13 )
{
return 0 ;
}
int F_63 ( struct V_1 * V_72 , struct V_2 * V_73 ,
const T_2 * V_45 , unsigned int V_46 ,
unsigned long * V_74 , unsigned int * V_75 )
{
if ( F_3 ( V_46 < 1 ) )
return - V_76 ;
* V_74 = V_45 [ 0 ] ;
* V_75 = V_47 ;
return 0 ;
}
int F_64 ( struct V_1 * V_72 , struct V_2 * V_73 ,
const T_2 * V_45 , unsigned int V_46 ,
T_1 * V_74 , unsigned int * V_75 )
{
if ( F_3 ( V_46 < 2 ) )
return - V_76 ;
* V_74 = V_45 [ 0 ] ;
* V_75 = V_45 [ 1 ] & V_77 ;
return 0 ;
}
int F_65 ( struct V_1 * V_72 ,
struct V_2 * V_73 ,
const T_2 * V_45 , unsigned int V_46 ,
unsigned long * V_74 , unsigned int * V_75 )
{
if ( F_3 ( V_46 < 1 ) )
return - V_76 ;
* V_74 = V_45 [ 0 ] ;
* V_75 = ( V_46 > 1 ) ? V_45 [ 1 ] : V_47 ;
return 0 ;
}
void F_66 ( const struct V_78 * V_37 ,
T_4 V_79 , unsigned int V_80 )
{
struct V_2 * V_33 ;
F_9 ( L_30 ,
( unsigned long long ) V_79 , ( int ) V_80 ) ;
V_33 = F_67 ( NULL , V_37 , V_79 ) ;
if ( V_33 )
F_11 ( V_33 , 32 , V_80 , 0 ,
& V_81 , NULL ) ;
}
