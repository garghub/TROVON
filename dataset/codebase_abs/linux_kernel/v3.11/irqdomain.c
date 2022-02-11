struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 ,
T_1 V_5 , int V_6 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_2 ( sizeof( * V_10 ) + (sizeof( unsigned int ) * V_4 ) ,
V_11 , F_3 ( V_3 ) ) ;
if ( F_4 ( ! V_10 ) )
return NULL ;
F_5 ( & V_10 -> V_12 , V_11 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_3 = F_6 ( V_3 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_13 = V_4 ;
V_10 -> V_14 = V_6 ;
F_7 ( & V_15 ) ;
F_8 ( & V_10 -> V_16 , & V_17 ) ;
F_9 ( & V_15 ) ;
F_10 ( L_1 , V_10 -> V_18 ) ;
return V_10 ;
}
void F_11 ( struct V_1 * V_10 )
{
F_7 ( & V_15 ) ;
F_4 ( V_10 -> V_12 . V_19 ) ;
F_12 ( & V_10 -> V_16 ) ;
if ( F_13 ( V_20 == V_10 ) )
F_14 ( NULL ) ;
F_9 ( & V_15 ) ;
F_10 ( L_2 , V_10 -> V_18 ) ;
F_15 ( V_10 -> V_3 ) ;
F_16 ( V_10 ) ;
}
struct V_1 * F_17 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_21 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 , V_4 , V_4 , 0 , V_8 , V_9 ) ;
if ( ! V_10 )
return NULL ;
if ( V_21 > 0 ) {
if ( F_18 ( V_22 ) ) {
int V_23 = F_19 ( V_21 , V_21 , V_4 ,
F_3 ( V_3 ) ) ;
if ( V_23 < 0 )
F_20 ( L_3 ,
V_21 ) ;
}
F_21 ( V_10 , V_21 , 0 , V_4 ) ;
}
return V_10 ;
}
struct V_1 * F_22 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_21 ,
T_1 V_24 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 , V_24 + V_4 ,
V_24 + V_4 , 0 , V_8 , V_9 ) ;
if ( ! V_10 )
return NULL ;
F_21 ( V_10 , V_21 , V_24 , V_4 ) ;
return V_10 ;
}
struct V_1 * F_23 ( struct V_2 * V_25 )
{
struct V_1 * V_26 , * V_27 = NULL ;
int V_23 ;
F_7 ( & V_15 ) ;
F_24 (h, &irq_domain_list, link) {
if ( V_26 -> V_8 -> V_28 )
V_23 = V_26 -> V_8 -> V_28 ( V_26 , V_25 ) ;
else
V_23 = ( V_26 -> V_3 != NULL ) && ( V_26 -> V_3 == V_25 ) ;
if ( V_23 ) {
V_27 = V_26 ;
break;
}
}
F_9 ( & V_15 ) ;
return V_27 ;
}
void F_14 ( struct V_1 * V_10 )
{
F_10 ( L_4 , V_10 ) ;
V_20 = V_10 ;
}
static void F_25 ( struct V_1 * V_10 , unsigned int V_29 )
{
struct V_30 * V_30 = F_26 ( V_29 ) ;
T_1 V_31 ;
if ( F_27 ( ! V_30 || V_30 -> V_10 != V_10 ,
L_5 , V_29 ) )
return;
V_31 = V_30 -> V_31 ;
F_28 ( V_29 , V_32 ) ;
F_29 ( V_29 , NULL , NULL ) ;
F_30 ( V_29 ) ;
if ( V_10 -> V_8 -> V_33 )
V_10 -> V_8 -> V_33 ( V_10 , V_29 ) ;
F_31 () ;
V_30 -> V_10 = NULL ;
V_30 -> V_31 = 0 ;
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = 0 ;
} else {
F_7 ( & V_35 ) ;
F_32 ( & V_10 -> V_12 , V_31 ) ;
F_9 ( & V_35 ) ;
}
}
int F_33 ( struct V_1 * V_10 , unsigned int V_36 ,
T_1 V_31 )
{
struct V_30 * V_30 = F_26 ( V_36 ) ;
int V_37 ;
if ( F_27 ( V_31 >= V_10 -> V_5 ,
L_6 , ( int ) V_31 , V_10 -> V_18 ) )
return - V_38 ;
if ( F_27 ( ! V_30 , L_7 , V_36 ) )
return - V_38 ;
if ( F_27 ( V_30 -> V_10 , L_8 , V_36 ) )
return - V_38 ;
F_7 ( & V_15 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_10 = V_10 ;
if ( V_10 -> V_8 -> V_39 ) {
V_37 = V_10 -> V_8 -> V_39 ( V_10 , V_36 , V_31 ) ;
if ( V_37 != 0 ) {
if ( V_37 != - V_40 ) {
F_20 ( L_9 ,
V_10 -> V_18 , V_31 , V_36 , V_37 ) ;
}
V_30 -> V_10 = NULL ;
V_30 -> V_31 = 0 ;
F_9 ( & V_15 ) ;
return V_37 ;
}
if ( ! V_10 -> V_18 && V_30 -> V_41 )
V_10 -> V_18 = V_30 -> V_41 -> V_18 ;
}
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = V_36 ;
} else {
F_7 ( & V_35 ) ;
F_34 ( & V_10 -> V_12 , V_31 , V_30 ) ;
F_9 ( & V_35 ) ;
}
F_9 ( & V_15 ) ;
F_35 ( V_36 , V_32 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_10 , unsigned int V_42 ,
T_1 V_43 , int V_44 )
{
int V_45 ;
F_10 ( L_10 , V_46 ,
F_36 ( V_10 -> V_3 ) , V_42 , ( int ) V_43 , V_44 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
F_33 ( V_10 , V_42 + V_45 , V_43 + V_45 ) ;
}
}
unsigned int F_37 ( struct V_1 * V_10 )
{
unsigned int V_36 ;
if ( V_10 == NULL )
V_10 = V_20 ;
V_36 = F_38 ( 1 , F_3 ( V_10 -> V_3 ) ) ;
if ( ! V_36 ) {
F_10 ( L_11 ) ;
return 0 ;
}
if ( V_36 >= V_10 -> V_14 ) {
F_39 ( L_12 ,
V_10 -> V_14 ) ;
F_40 ( V_36 ) ;
return 0 ;
}
F_10 ( L_13 , V_36 ) ;
if ( F_33 ( V_10 , V_36 , V_36 ) ) {
F_40 ( V_36 ) ;
return 0 ;
}
return V_36 ;
}
unsigned int F_41 ( struct V_1 * V_10 ,
T_1 V_31 )
{
unsigned int V_47 ;
int V_36 ;
F_10 ( L_14 , V_10 , V_31 ) ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL ) {
F_27 ( 1 , L_15 , V_46 , V_31 ) ;
return 0 ;
}
F_10 ( L_16 , V_10 ) ;
V_36 = F_42 ( V_10 , V_31 ) ;
if ( V_36 ) {
F_10 ( L_17 , V_36 ) ;
return V_36 ;
}
V_47 = V_31 % V_48 ;
if ( V_47 == 0 )
V_47 ++ ;
V_36 = F_38 ( V_47 , F_3 ( V_10 -> V_3 ) ) ;
if ( V_36 <= 0 )
V_36 = F_38 ( 1 , F_3 ( V_10 -> V_3 ) ) ;
if ( V_36 <= 0 ) {
F_10 ( L_18 ) ;
return 0 ;
}
if ( F_33 ( V_10 , V_36 , V_31 ) ) {
F_40 ( V_36 ) ;
return 0 ;
}
F_10 ( L_19 ,
V_31 , F_36 ( V_10 -> V_3 ) , V_36 ) ;
return V_36 ;
}
int F_43 ( struct V_1 * V_10 , unsigned int V_42 ,
T_1 V_43 , int V_44 )
{
int V_37 ;
V_37 = F_19 ( V_42 , V_42 , V_44 ,
F_3 ( V_10 -> V_3 ) ) ;
if ( F_13 ( V_37 < 0 ) )
return V_37 ;
F_21 ( V_10 , V_42 , V_43 , V_44 ) ;
return 0 ;
}
unsigned int F_44 ( struct V_2 * V_49 ,
const T_2 * V_50 , unsigned int V_51 )
{
struct V_1 * V_10 ;
T_1 V_31 ;
unsigned int type = V_52 ;
unsigned int V_36 ;
V_10 = V_49 ? F_23 ( V_49 ) : V_20 ;
if ( ! V_10 ) {
F_45 ( L_20 ,
F_36 ( V_49 ) ) ;
return 0 ;
}
if ( V_10 -> V_8 -> V_53 == NULL )
V_31 = V_50 [ 0 ] ;
else {
if ( V_10 -> V_8 -> V_53 ( V_10 , V_49 , V_50 , V_51 ,
& V_31 , & type ) )
return 0 ;
}
V_36 = F_41 ( V_10 , V_31 ) ;
if ( ! V_36 )
return V_36 ;
if ( type != V_52 &&
type != F_46 ( V_36 ) )
F_47 ( V_36 , type ) ;
return V_36 ;
}
void F_48 ( unsigned int V_36 )
{
struct V_30 * V_30 = F_26 ( V_36 ) ;
struct V_1 * V_10 ;
if ( ! V_36 || ! V_30 )
return;
V_10 = V_30 -> V_10 ;
if ( F_4 ( V_10 == NULL ) )
return;
F_25 ( V_10 , V_36 ) ;
F_40 ( V_36 ) ;
}
unsigned int F_42 ( struct V_1 * V_10 ,
T_1 V_31 )
{
struct V_30 * V_54 ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL )
return 0 ;
if ( V_31 < V_10 -> V_14 ) {
V_54 = F_26 ( V_31 ) ;
if ( V_54 && ( V_54 -> V_10 == V_10 ) && ( V_54 -> V_31 == V_31 ) )
return V_31 ;
}
if ( V_31 < V_10 -> V_13 )
return V_10 -> V_34 [ V_31 ] ;
F_49 () ;
V_54 = F_50 ( & V_10 -> V_12 , V_31 ) ;
F_51 () ;
return V_54 ? V_54 -> V_29 : 0 ;
}
static int F_52 ( struct V_55 * V_56 , void * V_57 )
{
unsigned long V_58 ;
struct V_59 * V_60 ;
struct V_1 * V_10 ;
struct V_61 V_62 ;
void * V_54 , * * V_63 ;
int V_45 ;
F_53 ( V_56 , L_21 ,
L_22 , L_23 , L_24 , L_25 , L_26 ) ;
F_7 ( & V_15 ) ;
F_24 (domain, &irq_domain_list, link) {
int V_44 = 0 ;
F_54 (slot, &domain->revmap_tree, &iter, 0 )
V_44 ++ ;
F_53 ( V_56 , L_27 ,
V_10 == V_20 ? '*' : ' ' , V_10 -> V_18 ,
V_10 -> V_13 + V_44 , V_10 -> V_13 ,
V_10 -> V_14 ,
V_10 -> V_3 ? F_36 ( V_10 -> V_3 ) : L_28 ) ;
}
F_9 ( & V_15 ) ;
F_53 ( V_56 , L_29 , L_30 , L_31 ,
L_32 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_33 ,
L_34 , L_35 , L_36 ) ;
for ( V_45 = 1 ; V_45 < V_48 ; V_45 ++ ) {
V_60 = F_55 ( V_45 ) ;
if ( ! V_60 )
continue;
F_56 ( & V_60 -> V_64 , V_58 ) ;
V_10 = V_60 -> V_30 . V_10 ;
if ( V_10 ) {
struct V_65 * V_41 ;
int V_31 = V_60 -> V_30 . V_31 ;
bool V_66 ;
F_53 ( V_56 , L_37 , V_45 ) ;
F_53 ( V_56 , L_38 , V_31 ) ;
V_41 = F_57 ( V_60 ) ;
F_53 ( V_56 , L_39 , ( V_41 && V_41 -> V_18 ) ? V_41 -> V_18 : L_40 ) ;
V_54 = F_58 ( V_60 ) ;
F_53 ( V_56 , V_54 ? L_41 : L_42 , V_54 ) ;
F_53 ( V_56 , L_43 , ( V_60 -> V_67 && V_60 -> V_67 -> V_68 ) ? '*' : ' ' ) ;
V_66 = ( V_45 == V_31 ) && ( V_45 < V_10 -> V_14 ) ;
F_53 ( V_56 , L_44 ,
( V_31 < V_10 -> V_13 ) ? L_45 : L_46 ,
V_66 ? L_47 : L_28 ) ;
F_53 ( V_56 , L_48 , V_60 -> V_30 . V_10 -> V_18 ) ;
}
F_59 ( & V_60 -> V_64 , V_58 ) ;
}
return 0 ;
}
static int F_60 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_61 ( V_70 , F_52 , V_69 -> V_71 ) ;
}
static int T_3 F_62 ( void )
{
if ( F_63 ( L_49 , V_72 , NULL ,
NULL , & V_73 ) == NULL )
return - V_74 ;
return 0 ;
}
int F_64 ( struct V_1 * V_75 , struct V_2 * V_76 ,
const T_2 * V_50 , unsigned int V_51 ,
unsigned long * V_77 , unsigned int * V_78 )
{
if ( F_4 ( V_51 < 1 ) )
return - V_38 ;
* V_77 = V_50 [ 0 ] ;
* V_78 = V_52 ;
return 0 ;
}
int F_65 ( struct V_1 * V_75 , struct V_2 * V_76 ,
const T_2 * V_50 , unsigned int V_51 ,
T_1 * V_77 , unsigned int * V_78 )
{
if ( F_4 ( V_51 < 2 ) )
return - V_38 ;
* V_77 = V_50 [ 0 ] ;
* V_78 = V_50 [ 1 ] & V_79 ;
return 0 ;
}
int F_66 ( struct V_1 * V_75 ,
struct V_2 * V_76 ,
const T_2 * V_50 , unsigned int V_51 ,
unsigned long * V_77 , unsigned int * V_78 )
{
if ( F_4 ( V_51 < 1 ) )
return - V_38 ;
* V_77 = V_50 [ 0 ] ;
* V_78 = ( V_51 > 1 ) ? V_50 [ 1 ] : V_52 ;
return 0 ;
}
