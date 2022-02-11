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
F_6 ( V_8 -> V_3 ) ;
F_7 ( V_8 ) ;
}
static void F_8 ( struct V_1 * V_8 )
{
F_9 ( & V_10 ) ;
F_10 ( & V_8 -> V_11 , & V_12 ) ;
F_11 ( & V_10 ) ;
F_12 ( L_1 ,
V_8 -> V_4 , V_8 ) ;
}
void F_13 ( struct V_1 * V_8 )
{
F_9 ( & V_10 ) ;
switch ( V_8 -> V_4 ) {
case V_13 :
break;
case V_14 :
F_3 ( V_8 -> V_15 . V_16 . V_17 ) ;
break;
case V_18 :
F_7 ( V_8 -> V_15 . V_19 . V_20 ) ;
V_8 -> V_15 . V_19 . V_21 = 0 ;
break;
case V_22 :
break;
}
F_14 ( & V_8 -> V_11 ) ;
if ( F_15 ( V_23 == V_8 ) )
F_16 ( NULL ) ;
F_11 ( & V_10 ) ;
F_12 ( L_2 ,
V_8 -> V_4 , V_8 ) ;
F_5 ( V_8 ) ;
}
static unsigned int F_17 ( struct V_1 * V_8 ,
T_1 V_24 )
{
T_1 V_25 = V_8 -> V_15 . V_26 . V_25 ;
int V_21 = V_8 -> V_15 . V_26 . V_21 ;
if ( F_3 ( V_24 < V_25 || V_24 >= V_25 + V_21 ) )
return 0 ;
return V_24 - V_25 + V_8 -> V_15 . V_26 . V_27 ;
}
struct V_1 * F_18 ( struct V_2 * V_3 ,
unsigned int V_21 ,
unsigned int V_27 ,
T_1 V_25 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int V_28 ;
V_8 = F_1 ( V_3 , V_13 , V_6 , V_7 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 . V_26 . V_27 = V_27 ;
V_8 -> V_15 . V_26 . V_25 = V_25 ;
V_8 -> V_15 . V_26 . V_21 = V_21 ;
F_9 ( & V_10 ) ;
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
int V_29 = V_27 + V_28 ;
struct V_30 * V_30 = F_19 ( V_29 ) ;
if ( F_3 ( ! V_30 || V_30 -> V_8 ) ) {
F_11 ( & V_10 ) ;
F_5 ( V_8 ) ;
return NULL ;
}
}
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
struct V_30 * V_30 = F_19 ( V_27 + V_28 ) ;
V_30 -> V_24 = V_25 + V_28 ;
V_30 -> V_8 = V_8 ;
}
F_11 ( & V_10 ) ;
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
int V_29 = V_27 + V_28 ;
int V_24 = V_25 + V_28 ;
if ( ! V_29 )
continue;
V_6 -> V_31 ( V_8 , V_29 , V_24 ) ;
F_20 ( V_29 , V_32 ) ;
}
F_8 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_21 ( struct V_2 * V_3 ,
unsigned int V_21 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int * V_20 ;
V_20 = F_2 ( sizeof( * V_20 ) * V_21 , V_9 ) ;
if ( F_3 ( ! V_20 ) )
return NULL ;
V_8 = F_1 ( V_3 , V_18 , V_6 , V_7 ) ;
if ( ! V_8 ) {
F_7 ( V_20 ) ;
return NULL ;
}
V_8 -> V_15 . V_19 . V_21 = V_21 ;
V_8 -> V_15 . V_19 . V_20 = V_20 ;
F_8 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_22 ( struct V_2 * V_3 ,
unsigned int V_33 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_22 , V_6 , V_7 ) ;
if ( V_8 ) {
V_8 -> V_15 . V_34 . V_33 = V_33 ? V_33 : ~ 0 ;
F_8 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_23 ( struct V_2 * V_3 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_14 , V_6 , V_7 ) ;
if ( V_8 ) {
F_24 ( & V_8 -> V_15 . V_16 , V_9 ) ;
F_8 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_25 ( struct V_2 * V_35 )
{
struct V_1 * V_36 , * V_37 = NULL ;
int V_38 ;
F_9 ( & V_10 ) ;
F_26 (h, &irq_domain_list, link) {
if ( V_36 -> V_6 -> V_39 )
V_38 = V_36 -> V_6 -> V_39 ( V_36 , V_35 ) ;
else
V_38 = ( V_36 -> V_3 != NULL ) && ( V_36 -> V_3 == V_35 ) ;
if ( V_38 ) {
V_37 = V_36 ;
break;
}
}
F_11 ( & V_10 ) ;
return V_37 ;
}
void F_16 ( struct V_1 * V_8 )
{
F_12 ( L_3 , V_8 ) ;
V_23 = V_8 ;
}
static int F_27 ( struct V_1 * V_8 , unsigned int V_40 ,
T_1 V_24 )
{
struct V_30 * V_30 = F_19 ( V_40 ) ;
V_30 -> V_24 = V_24 ;
V_30 -> V_8 = V_8 ;
if ( V_8 -> V_6 -> V_31 ( V_8 , V_40 , V_24 ) ) {
F_12 ( L_4 , V_40 , V_24 ) ;
V_30 -> V_8 = NULL ;
V_30 -> V_24 = 0 ;
return - 1 ;
}
F_20 ( V_40 , V_32 ) ;
return 0 ;
}
unsigned int F_28 ( struct V_1 * V_8 )
{
unsigned int V_40 ;
if ( V_8 == NULL )
V_8 = V_23 ;
F_29 ( V_8 == NULL ) ;
F_3 ( V_8 -> V_4 != V_22 ) ;
V_40 = F_30 ( 1 , 0 ) ;
if ( ! V_40 ) {
F_12 ( L_5 ) ;
return 0 ;
}
if ( V_40 >= V_8 -> V_15 . V_34 . V_33 ) {
F_31 ( L_6 ,
V_8 -> V_15 . V_34 . V_33 ) ;
F_32 ( V_40 ) ;
return 0 ;
}
F_12 ( L_7 , V_40 ) ;
if ( F_27 ( V_8 , V_40 , V_40 ) ) {
F_32 ( V_40 ) ;
return 0 ;
}
return V_40 ;
}
unsigned int F_33 ( struct V_1 * V_8 ,
T_1 V_24 )
{
unsigned int V_41 ;
int V_40 ;
F_12 ( L_8 , V_8 , V_24 ) ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL ) {
F_34 ( L_9
L_10 , V_24 ) ;
F_3 ( 1 ) ;
return 0 ;
}
F_12 ( L_11 , V_8 ) ;
V_40 = F_35 ( V_8 , V_24 ) ;
if ( V_40 ) {
F_12 ( L_12 , V_40 ) ;
return V_40 ;
}
if ( V_8 -> V_4 == V_13 )
return F_17 ( V_8 , V_24 ) ;
V_41 = V_24 % V_42 ;
if ( V_41 == 0 )
V_41 ++ ;
V_40 = F_30 ( V_41 , 0 ) ;
if ( V_40 <= 0 )
V_40 = F_30 ( 1 , 0 ) ;
if ( V_40 <= 0 ) {
F_12 ( L_13 ) ;
return 0 ;
}
if ( F_27 ( V_8 , V_40 , V_24 ) ) {
if ( V_8 -> V_4 != V_13 )
F_32 ( V_40 ) ;
return 0 ;
}
F_12 ( L_14 ,
V_24 , V_8 -> V_3 ? V_8 -> V_3 -> V_43 : L_15 , V_40 ) ;
return V_40 ;
}
unsigned int F_36 ( struct V_2 * V_44 ,
const T_2 * V_45 , unsigned int V_46 )
{
struct V_1 * V_8 ;
T_1 V_24 ;
unsigned int type = V_47 ;
unsigned int V_40 ;
V_8 = V_44 ? F_25 ( V_44 ) : V_23 ;
if ( ! V_8 ) {
#ifdef F_37
if ( V_46 > 0 )
return V_45 [ 0 ] ;
#endif
F_34 ( L_16 ,
V_44 -> V_43 ) ;
return 0 ;
}
if ( V_8 -> V_6 -> V_48 == NULL )
V_24 = V_45 [ 0 ] ;
else {
if ( V_8 -> V_6 -> V_48 ( V_8 , V_44 , V_45 , V_46 ,
& V_24 , & type ) )
return 0 ;
}
V_40 = F_33 ( V_8 , V_24 ) ;
if ( ! V_40 )
return V_40 ;
if ( type != V_47 &&
type != ( F_38 ( F_19 ( V_40 ) ) ) )
F_39 ( V_40 , type ) ;
return V_40 ;
}
void F_40 ( unsigned int V_40 )
{
struct V_30 * V_30 = F_19 ( V_40 ) ;
struct V_1 * V_8 ;
T_1 V_24 ;
if ( ! V_40 || ! V_30 )
return;
V_8 = V_30 -> V_8 ;
if ( F_3 ( V_8 == NULL ) )
return;
if ( V_8 -> V_4 == V_13 )
return;
F_41 ( V_40 , V_32 ) ;
F_42 ( V_40 , NULL , NULL ) ;
F_43 ( V_40 ) ;
if ( V_8 -> V_6 -> V_49 )
V_8 -> V_6 -> V_49 ( V_8 , V_40 ) ;
F_44 () ;
V_24 = V_30 -> V_24 ;
switch( V_8 -> V_4 ) {
case V_18 :
if ( V_24 < V_8 -> V_15 . V_19 . V_21 )
V_8 -> V_15 . V_19 . V_20 [ V_24 ] = 0 ;
break;
case V_14 :
F_9 ( & V_50 ) ;
F_45 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_11 ( & V_50 ) ;
break;
}
F_32 ( V_40 ) ;
}
unsigned int F_35 ( struct V_1 * V_8 ,
T_1 V_24 )
{
unsigned int V_28 ;
unsigned int V_41 = V_24 % V_42 ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL )
return 0 ;
if ( V_8 -> V_4 == V_13 )
return F_17 ( V_8 , V_24 ) ;
if ( V_41 == 0 )
V_41 = 1 ;
V_28 = V_41 ;
do {
struct V_30 * V_51 = F_19 ( V_28 ) ;
if ( V_51 && ( V_51 -> V_8 == V_8 ) && ( V_51 -> V_24 == V_24 ) )
return V_28 ;
V_28 ++ ;
if ( V_28 >= V_42 )
V_28 = 1 ;
} while( V_28 != V_41 );
return 0 ;
}
unsigned int F_46 ( struct V_1 * V_8 ,
T_1 V_24 )
{
struct V_30 * V_30 ;
if ( F_47 ( V_8 -> V_4 != V_14 ) )
return F_35 ( V_8 , V_24 ) ;
F_48 () ;
V_30 = F_49 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_50 () ;
return V_30 ? V_30 -> V_29 : F_35 ( V_8 , V_24 ) ;
}
void F_51 ( struct V_1 * V_8 , unsigned int V_40 ,
T_1 V_24 )
{
struct V_30 * V_30 = F_19 ( V_40 ) ;
if ( F_3 ( V_8 -> V_4 != V_14 ) )
return;
if ( V_40 ) {
F_9 ( & V_50 ) ;
F_52 ( & V_8 -> V_15 . V_16 , V_24 , V_30 ) ;
F_11 ( & V_50 ) ;
}
}
unsigned int F_53 ( struct V_1 * V_8 ,
T_1 V_24 )
{
unsigned int * V_20 ;
if ( F_47 ( V_8 -> V_4 != V_18 ) )
return F_35 ( V_8 , V_24 ) ;
if ( F_15 ( V_24 >= V_8 -> V_15 . V_19 . V_21 ) )
return F_35 ( V_8 , V_24 ) ;
V_20 = V_8 -> V_15 . V_19 . V_20 ;
if ( F_15 ( V_20 == NULL ) )
return F_35 ( V_8 , V_24 ) ;
if ( F_15 ( ! V_20 [ V_24 ] ) )
V_20 [ V_24 ] = F_35 ( V_8 , V_24 ) ;
return V_20 [ V_24 ] ;
}
static int F_54 ( struct V_52 * V_53 , void * V_54 )
{
unsigned long V_55 ;
struct V_56 * V_57 ;
const char * V_58 ;
static const char V_59 [] = L_17 ;
void * V_51 ;
int V_28 ;
F_55 ( V_53 , L_18 , L_19 , L_20 ,
L_21 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_22 ,
L_23 ) ;
for ( V_28 = 1 ; V_28 < V_42 ; V_28 ++ ) {
V_57 = F_56 ( V_28 ) ;
if ( ! V_57 )
continue;
F_57 ( & V_57 -> V_60 , V_55 ) ;
if ( V_57 -> V_61 && V_57 -> V_61 -> V_62 ) {
struct V_63 * V_64 ;
F_55 ( V_53 , L_24 , V_28 ) ;
F_55 ( V_53 , L_25 , V_57 -> V_30 . V_24 ) ;
V_64 = F_58 ( V_57 ) ;
if ( V_64 && V_64 -> V_65 )
V_58 = V_64 -> V_65 ;
else
V_58 = V_59 ;
F_55 ( V_53 , L_26 , V_58 ) ;
V_51 = F_59 ( V_57 ) ;
F_55 ( V_53 , V_51 ? L_27 : L_28 , V_51 ) ;
if ( V_57 -> V_30 . V_8 && V_57 -> V_30 . V_8 -> V_3 )
V_58 = V_57 -> V_30 . V_8 -> V_3 -> V_43 ;
else
V_58 = V_59 ;
F_55 ( V_53 , L_29 , V_58 ) ;
}
F_60 ( & V_57 -> V_60 , V_55 ) ;
}
return 0 ;
}
static int F_61 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_62 ( V_67 , F_54 , V_66 -> V_68 ) ;
}
static int T_3 F_63 ( void )
{
if ( F_64 ( L_30 , V_69 , NULL ,
NULL , & V_70 ) == NULL )
return - V_71 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_72 , unsigned int V_29 ,
T_1 V_24 )
{
return 0 ;
}
int F_66 ( struct V_1 * V_72 , struct V_2 * V_73 ,
const T_2 * V_45 , unsigned int V_46 ,
unsigned long * V_74 , unsigned int * V_75 )
{
if ( F_3 ( V_46 < 1 ) )
return - V_76 ;
* V_74 = V_45 [ 0 ] ;
* V_75 = V_47 ;
return 0 ;
}
int F_67 ( struct V_1 * V_72 , struct V_2 * V_73 ,
const T_2 * V_45 , unsigned int V_46 ,
T_1 * V_74 , unsigned int * V_75 )
{
if ( F_3 ( V_46 < 2 ) )
return - V_76 ;
* V_74 = V_45 [ 0 ] ;
* V_75 = V_45 [ 1 ] & V_77 ;
return 0 ;
}
int F_68 ( struct V_1 * V_72 ,
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
void F_69 ( const struct V_78 * V_39 ,
T_4 V_79 , unsigned int V_80 )
{
struct V_2 * V_35 ;
F_12 ( L_31 ,
( unsigned long long ) V_79 , ( int ) V_80 ) ;
V_35 = F_70 ( NULL , V_39 , V_79 ) ;
if ( V_35 )
F_18 ( V_35 , 32 , V_80 , 0 ,
& V_81 , NULL ) ;
}
