static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
return ( V_1 << 56 ) | ( V_2 << 48 ) ;
}
static void T_1 F_2 ( const struct V_3 * V_4 ,
const char * V_5 , int line )
{
F_3 ( L_1 , V_5 , line , V_4 -> V_6 ) ;
F_3 ( L_2 , V_5 , line , V_4 -> V_7 . V_8 ) ;
F_3 ( L_3 , V_5 , line , V_4 -> V_9 ) ;
F_3 ( L_4 , V_5 , line , V_4 -> V_10 ) ;
F_3 ( L_5 , V_5 , line , V_4 -> V_11 . V_12 ) ;
F_3 ( L_6 , V_5 , line , V_4 -> V_11 . V_13 ) ;
F_3 ( L_7 , V_5 , line , V_4 -> V_11 . V_8 ) ;
}
unsigned long F_4 ( unsigned long V_14 )
{
F_5 ( F_6 ( V_14 ) ) ;
return ( V_14 < V_3 . V_7 . V_8 || V_14 >= V_3 . V_6 )
? V_14 : V_14 + V_3 . V_11 . V_13 ;
}
void T_2 F_7 ( unsigned long * V_10 )
{
int V_15 ;
T_3 V_16 ;
T_3 V_8 ;
T_3 V_17 ;
T_3 V_18 ;
T_3 V_19 ;
V_15 = F_8 ( 0 ,
& V_16 , & V_8 , & V_17 , & V_18 ,
& V_19 ) ;
if ( V_15 ) {
F_3 ( L_8
L_9 , V_20 , __LINE__ ,
F_9 ( V_15 ) ) ;
goto V_21;
}
if ( V_18 < V_22 ) {
F_3 ( L_10 , V_20 , __LINE__ ,
V_18 ) ;
goto V_21;
}
F_10 ( V_23 > V_24 ) ;
F_10 ( V_23 < V_25 ) ;
V_15 = F_11 ( V_23 ,
2 , F_1 ( V_22 , V_26 ) ,
& V_3 . V_9 , & V_3 . V_10 ) ;
if ( V_15 ) {
F_3 ( L_11 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
goto V_21;
}
V_15 = F_12 ( V_3 . V_9 ) ;
if ( V_15 ) {
F_3 ( L_12 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
goto V_21;
}
* V_10 = V_3 . V_10 ;
F_13 ( & V_3 ) ;
return;
V_21:
F_14 ( L_13 ) ;
}
void F_15 ( void )
{
int V_15 ;
F_3 ( L_3 , V_20 , __LINE__ , V_3 . V_9 ) ;
if ( V_3 . V_9 ) {
V_15 = F_12 ( 0 ) ;
F_5 ( V_15 ) ;
V_15 = F_16 ( V_3 . V_9 ) ;
F_5 ( V_15 ) ;
V_3 . V_9 = 0 ;
}
}
static int F_17 ( struct V_27 * V_28 )
{
int V_15 ;
V_15 = F_18 ( 0 , & V_28 -> V_12 , & V_28 -> V_8 ) ;
if ( V_15 )
goto V_29;
if ( ! V_28 -> V_12 || ! V_28 -> V_8 ) {
V_15 = - 1 ;
goto V_29;
}
V_28 -> V_13 = V_28 -> V_12 - V_3 . V_7 . V_8 ;
F_3 ( L_14 ,
V_20 , __LINE__ , V_28 -> V_12 , V_28 -> V_8 ) ;
return 0 ;
V_29:
F_3 ( L_15 , V_20 , __LINE__ ) ;
V_28 -> V_8 = V_28 -> V_12 = V_28 -> V_13 = 0 ;
return V_15 ;
}
static int F_19 ( const struct V_27 * V_28 )
{
return V_28 ? F_20 ( 0 , V_28 -> V_12 , V_28 -> V_8 ) :
F_20 ( 0 , 0 , 0 ) ;
}
static int F_21 ( struct V_27 * V_28 , unsigned long V_8 )
{
int V_15 ;
T_3 V_30 ;
V_28 -> V_8 = F_22 ( V_8 , 1 << V_22 ) ;
F_3 ( L_16 , V_20 , __LINE__ , V_8 ) ;
F_3 ( L_17 , V_20 , __LINE__ , V_28 -> V_8 ) ;
F_3 ( L_18 , V_20 , __LINE__ ,
V_8 - V_28 -> V_8 , ( V_8 - V_28 -> V_8 ) / 1024 / 1024 ) ;
if ( V_28 -> V_8 == 0 ) {
F_3 ( L_19 , V_20 , __LINE__ ) ;
V_15 = - 1 ;
goto V_29;
}
V_15 = F_23 ( V_28 -> V_8 , V_22 , 0 ,
V_31 , & V_28 -> V_12 , & V_30 ) ;
if ( V_15 || V_28 -> V_12 < V_3 . V_7 . V_8 ) {
F_3 ( L_20 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
goto V_29;
}
V_28 -> V_32 = 1 ;
V_28 -> V_13 = V_28 -> V_12 - V_3 . V_7 . V_8 ;
return V_15 ;
V_29:
V_28 -> V_8 = V_28 -> V_12 = V_28 -> V_13 = 0 ;
return V_15 ;
}
static void F_24 ( struct V_27 * V_28 )
{
int V_15 ;
if ( ! V_28 -> V_32 ) {
F_25 ( L_21 ,
V_20 , __LINE__ , V_28 -> V_12 , V_28 -> V_8 ) ;
return;
}
F_3 ( L_22 , V_20 , __LINE__ , V_28 -> V_12 ) ;
if ( V_28 -> V_12 ) {
V_15 = F_26 ( V_28 -> V_12 ) ;
F_5 ( V_15 ) ;
V_28 -> V_8 = V_28 -> V_12 = V_28 -> V_13 = 0 ;
V_3 . V_6 = V_3 . V_7 . V_8 ;
}
F_19 ( NULL ) ;
}
static unsigned long F_27 ( struct V_33 * V_28 ,
unsigned long V_34 )
{
if ( V_34 >= V_3 . V_7 . V_8 )
V_34 -= V_3 . V_11 . V_13 ;
F_5 ( V_34 < V_28 -> V_13 ) ;
F_5 ( V_34 >= V_28 -> V_13 + V_28 -> V_35 ) ;
return V_28 -> V_36 + V_34 - V_28 -> V_13 ;
}
static void T_1 F_28 ( const struct V_33 * V_28 ,
const char * V_5 , int line )
{
F_3 ( L_23 , V_5 , line , V_28 -> V_37 -> V_38 ,
V_28 -> V_37 -> V_39 ) ;
F_3 ( L_24 , V_5 , line , V_28 -> V_40 ) ;
F_3 ( L_25 , V_5 , line , V_28 -> V_36 ) ;
F_3 ( L_26 , V_5 , line , V_28 -> V_35 ) ;
F_3 ( L_27 , V_5 , line , V_28 -> V_13 ) ;
}
static void F_29 ( const struct V_41 * V_42 , const char * V_5 ,
int line )
{
F_3 ( L_28 , V_5 , line ,
V_42 -> V_43 -> V_37 -> V_38 , V_42 -> V_43 -> V_37 -> V_39 ) ;
F_3 ( L_29 , V_5 , line , V_42 -> V_43 -> V_36 ) ;
F_3 ( L_30 , V_5 , line , V_42 -> V_43 -> V_40 ) ;
F_3 ( L_31 , V_5 , line , V_42 -> V_43 -> V_35 ) ;
F_3 ( L_32 , V_5 , line , V_42 -> V_43 -> V_13 ) ;
F_3 ( L_33 , V_5 , line , V_42 -> V_34 ) ;
F_3 ( L_34 , V_5 , line , V_42 -> V_36 ) ;
F_3 ( L_35 , V_5 , line , V_42 -> V_35 ) ;
}
static struct V_41 * F_30 ( struct V_33 * V_28 ,
unsigned long V_36 , unsigned long V_35 )
{
struct V_41 * V_42 ;
unsigned long V_44 = F_22 ( V_36 , 1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_36 - V_44 ,
1 << V_28 -> V_40 ) ;
F_32 (c, &r->chunk_list.head, link) {
if ( V_44 >= V_42 -> V_36 &&
V_44 + V_45 <= V_42 -> V_36 + V_42 -> V_35 )
return V_42 ;
if ( V_44 + V_45 <= V_42 -> V_36 )
continue;
if ( V_44 >= V_42 -> V_36 + V_42 -> V_35 )
continue;
F_33 ( V_42 ) ;
F_34 () ;
}
return NULL ;
}
static struct V_41 * F_35 ( struct V_33 * V_28 ,
unsigned long V_34 , unsigned long V_35 )
{
struct V_41 * V_42 ;
unsigned long V_46 = F_22 ( V_34 , 1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_34 - V_46 ,
1 << V_28 -> V_40 ) ;
F_32 (c, &r->chunk_list.head, link) {
if ( V_42 -> V_34 <= V_46 &&
V_46 < V_42 -> V_34 + V_42 -> V_35 ) {
if ( V_46 + V_45 <= V_42 -> V_34 + V_42 -> V_35 )
return V_42 ;
else {
F_33 ( V_42 ) ;
F_34 () ;
}
}
if ( V_46 + V_45 <= V_42 -> V_34 ) {
continue;
}
if ( V_42 -> V_34 + V_42 -> V_35 <= V_46 ) {
continue;
}
}
return NULL ;
}
static int F_36 ( struct V_41 * V_42 )
{
int V_15 = 0 ;
if ( V_42 -> V_36 ) {
V_15 = F_37 ( V_42 -> V_43 -> V_37 -> V_38 ,
V_42 -> V_43 -> V_37 -> V_39 , V_42 -> V_36 , V_42 -> V_35 ) ;
F_5 ( V_15 ) ;
}
F_38 ( V_42 ) ;
return V_15 ;
}
static int F_39 ( struct V_41 * V_42 )
{
int V_15 = 0 ;
int V_47 ;
unsigned long V_13 ;
struct V_33 * V_28 = V_42 -> V_43 ;
F_3 ( L_36 , V_20 ) ;
for ( V_47 = 0 ; V_47 < ( V_42 -> V_35 >> V_28 -> V_40 ) ; V_47 ++ ) {
V_13 = ( 1 << V_28 -> V_40 ) * V_47 ;
V_15 = F_40 ( 0 ,
V_42 -> V_36 + V_13 ,
V_42 -> V_34 + V_13 ,
V_28 -> V_48 ,
0 ) ;
F_3 ( L_37 , V_20 ,
V_42 -> V_36 + V_13 ,
V_42 -> V_34 + V_13 ,
V_28 -> V_48 ) ;
if ( V_15 ) {
F_3 ( L_38 , V_20 ,
__LINE__ , F_9 ( V_15 ) ) ;
}
}
F_38 ( V_42 ) ;
F_3 ( L_39 , V_20 ) ;
return V_15 ;
}
static int F_41 ( struct V_33 * V_28 , unsigned long V_14 ,
unsigned long V_35 , struct V_41 * * V_49 , T_3 V_50 )
{
int V_15 ;
struct V_41 * V_42 ;
V_42 = F_42 ( sizeof( struct V_41 ) , V_51 ) ;
if ( ! V_42 ) {
V_15 = - V_52 ;
goto V_53;
}
V_42 -> V_43 = V_28 ;
V_42 -> V_34 = F_4 ( V_14 ) ;
V_42 -> V_36 = F_27 ( V_28 , V_42 -> V_34 ) ;
V_42 -> V_35 = V_35 ;
F_5 ( V_50 != 0xf800000000000000UL ) ;
V_15 = F_43 ( V_42 -> V_43 -> V_37 -> V_38 ,
V_42 -> V_43 -> V_37 -> V_39 , V_42 -> V_34 ,
V_42 -> V_36 , V_42 -> V_35 , V_50 ) ;
if ( V_15 ) {
F_3 ( L_40 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
goto V_54;
}
F_44 ( & V_42 -> V_55 , & V_28 -> V_56 . V_57 ) ;
* V_49 = V_42 ;
return 0 ;
V_54:
F_38 ( V_42 ) ;
V_53:
* V_49 = NULL ;
F_3 ( L_41 , V_20 , __LINE__ ) ;
return V_15 ;
}
static int F_45 ( struct V_33 * V_28 , unsigned long V_14 ,
unsigned long V_35 , struct V_41 * * V_49 ,
T_3 V_50 )
{
int V_15 ;
struct V_41 * V_42 , * V_58 ;
int V_47 , V_59 ;
unsigned long V_13 ;
F_3 ( V_60 L_42 , V_20 ,
V_14 , F_4 ( V_14 ) , V_35 ) ;
V_42 = F_42 ( sizeof( struct V_41 ) , V_51 ) ;
if ( ! V_42 ) {
V_15 = - V_52 ;
goto V_53;
}
V_42 -> V_43 = V_28 ;
V_42 -> V_35 = V_35 ;
V_42 -> V_34 = F_4 ( V_14 ) ;
if ( F_46 ( & V_28 -> V_56 . V_57 ) ) {
V_42 -> V_36 = V_28 -> V_36 ;
} else {
V_58 = F_47 ( V_28 -> V_56 . V_57 . V_61 ,
struct V_41 , V_55 ) ;
V_42 -> V_36 = V_58 -> V_36 + V_58 -> V_35 ;
F_3 ( L_43 , V_20 ,
V_58 -> V_36 , V_58 -> V_35 ) ;
}
V_59 = V_35 >> V_28 -> V_40 ;
F_3 ( L_44 , V_20 ,
V_28 -> V_40 , V_28 -> V_35 , V_59 , V_50 ) ;
for ( V_47 = 0 ; V_47 < V_59 ; V_47 ++ ) {
V_13 = ( 1 << V_28 -> V_40 ) * V_47 ;
V_15 = F_40 ( 0 ,
V_42 -> V_36 + V_13 ,
V_42 -> V_34 + V_13 ,
V_28 -> V_48 ,
V_50 ) ;
if ( V_15 ) {
F_48 ( L_38 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
goto V_54;
}
F_3 ( L_45 , V_20 ,
V_47 , V_42 -> V_36 + V_13 , V_42 -> V_34 + V_13 ,
V_28 -> V_48 ) ;
}
F_44 ( & V_42 -> V_55 , & V_28 -> V_56 . V_57 ) ;
* V_49 = V_42 ;
F_3 ( L_46 , V_20 ) ;
return 0 ;
V_54:
for ( V_47 -- ; 0 <= V_47 ; V_47 -- ) {
F_40 ( 0 ,
V_42 -> V_36 + V_13 ,
V_42 -> V_34 + V_13 ,
V_28 -> V_48 ,
0 ) ;
}
F_38 ( V_42 ) ;
V_53:
* V_49 = NULL ;
return V_15 ;
}
static int F_49 ( struct V_33 * V_28 )
{
int V_15 ;
T_3 V_36 ;
F_3 ( L_47 , V_20 , __LINE__ ) ;
F_5 ( ! V_28 ) ;
if ( ! V_28 -> V_37 -> V_38 ) {
F_25 ( L_48 , V_20 , __LINE__ ,
V_28 -> V_37 -> V_38 , V_28 -> V_37 -> V_39 ) ;
return 0 ;
}
F_3 ( L_49 , V_20 ,
__LINE__ , V_28 -> V_35 , V_28 -> V_40 , V_28 -> V_13 ) ;
F_5 ( ! V_28 -> V_35 ) ;
F_5 ( ! V_28 -> V_40 ) ;
F_5 ( ! V_28 -> V_62 ) ;
F_50 ( & V_28 -> V_56 . V_57 ) ;
F_51 ( & V_28 -> V_56 . V_63 ) ;
V_15 = F_52 ( V_28 -> V_37 -> V_38 , V_28 -> V_37 -> V_39 ,
F_53 ( V_28 -> V_35 ) , V_28 -> V_40 , V_28 -> V_64 ,
& V_36 ) ;
V_28 -> V_36 = V_36 ;
if ( V_15 ) {
F_3 ( L_50 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
V_28 -> V_35 = V_28 -> V_36 = 0 ;
}
return V_15 ;
}
static int F_54 ( struct V_33 * V_28 )
{
int V_15 ;
T_3 V_36 ;
F_50 ( & V_28 -> V_56 . V_57 ) ;
F_51 ( & V_28 -> V_56 . V_63 ) ;
V_15 = F_55 ( 0 ,
V_28 -> V_35 ,
V_28 -> V_40 ,
& V_36 ) ;
V_28 -> V_36 = V_36 ;
if ( V_15 ) {
F_3 ( L_51 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
V_28 -> V_35 = V_28 -> V_36 = 0 ;
}
F_3 ( L_52 , V_20 ,
V_28 -> V_35 , V_28 -> V_40 , V_28 -> V_36 ) ;
return V_15 ;
}
static int F_56 ( struct V_33 * V_28 )
{
int V_15 ;
struct V_41 * V_42 ;
struct V_41 * V_65 ;
F_5 ( ! V_28 ) ;
if ( ! V_28 -> V_37 -> V_38 ) {
F_25 ( L_48 , V_20 , __LINE__ ,
V_28 -> V_37 -> V_38 , V_28 -> V_37 -> V_39 ) ;
return 0 ;
}
F_57 (c, tmp, &r->chunk_list.head, link) {
F_58 ( & V_42 -> V_55 ) ;
F_36 ( V_42 ) ;
}
V_15 = F_59 ( V_28 -> V_37 -> V_38 , V_28 -> V_37 -> V_39 ,
V_28 -> V_36 ) ;
if ( V_15 )
F_3 ( L_53 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
V_28 -> V_36 = 0 ;
return V_15 ;
}
static int F_60 ( struct V_33 * V_28 )
{
int V_15 ;
struct V_41 * V_42 , * V_66 ;
F_3 ( L_54 , V_20 ) ;
F_57 (c, n, &r->chunk_list.head, link) {
F_58 ( & V_42 -> V_55 ) ;
F_39 ( V_42 ) ;
}
V_15 = F_61 ( 0 , V_28 -> V_36 ) ;
if ( V_15 )
F_3 ( L_53 ,
V_20 , __LINE__ , F_9 ( V_15 ) ) ;
V_28 -> V_36 = 0 ;
F_3 ( L_46 , V_20 ) ;
return V_15 ;
}
static int F_62 ( struct V_33 * V_28 , unsigned long V_67 ,
unsigned long V_35 , T_4 * V_36 ,
T_3 V_50 )
{
int V_15 ;
unsigned long V_19 ;
struct V_41 * V_42 ;
unsigned long V_14 = F_6 ( V_67 ) ? F_63 ( V_67 )
: V_67 ;
unsigned long V_68 = F_22 ( V_14 , 1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_14 - V_68 ,
1 << V_28 -> V_40 ) ;
* V_36 = F_27 ( V_28 , F_4 ( V_14 ) ) ;
if ( ! V_69 ) {
unsigned long V_34 = F_4 ( V_14 ) ;
F_3 ( L_55 , V_20 , __LINE__ ) ;
F_3 ( L_56 , V_20 , __LINE__ ,
V_67 ) ;
F_3 ( L_57 , V_20 , __LINE__ ,
V_14 ) ;
F_3 ( L_58 , V_20 , __LINE__ ,
V_34 ) ;
F_3 ( L_59 , V_20 , __LINE__ , V_35 ) ;
F_3 ( L_60 , V_20 , __LINE__ ,
* V_36 , V_35 ) ;
}
F_64 ( & V_28 -> V_56 . V_63 , V_19 ) ;
V_42 = F_30 ( V_28 , * V_36 , V_35 ) ;
if ( V_42 ) {
F_3 ( L_61 , V_20 , __LINE__ ) ;
F_33 ( V_42 ) ;
V_42 -> V_70 ++ ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return 0 ;
}
V_15 = F_41 ( V_28 , V_68 , V_45 , & V_42 , V_50 ) ;
if ( V_15 ) {
* V_36 = 0 ;
F_3 ( L_62 ,
V_20 , __LINE__ , V_15 ) ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return V_15 ;
}
V_42 -> V_70 = 1 ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return V_15 ;
}
static int F_66 ( struct V_33 * V_28 , unsigned long V_67 ,
unsigned long V_35 , T_4 * V_36 ,
T_3 V_50 )
{
int V_15 ;
unsigned long V_19 ;
struct V_41 * V_42 ;
unsigned long V_14 = F_6 ( V_67 ) ? F_63 ( V_67 )
: V_67 ;
unsigned long V_68 = F_22 ( V_14 , 1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_14 - V_68 ,
1 << V_28 -> V_40 ) ;
F_3 ( V_60 L_63 , V_20 ,
V_67 , V_35 ) ;
F_3 ( V_60 L_64 , V_20 ,
V_14 , V_68 , V_45 ) ;
F_64 ( & V_28 -> V_56 . V_63 , V_19 ) ;
V_42 = F_35 ( V_28 , F_4 ( V_14 ) , V_35 ) ;
if ( V_42 ) {
F_34 () ;
* V_36 = V_42 -> V_36 + V_14 - V_68 ;
V_42 -> V_70 ++ ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return 0 ;
}
V_15 = F_45 ( V_28 , V_68 , V_45 , & V_42 ,
V_50 ) ;
if ( V_15 ) {
* V_36 = 0 ;
F_3 ( L_65 ,
V_20 , __LINE__ , V_15 ) ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return V_15 ;
}
* V_36 = V_42 -> V_36 + V_14 - V_68 ;
F_3 ( L_66 , V_20 ,
V_67 , V_14 , V_68 , * V_36 ) ;
V_42 -> V_70 = 1 ;
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return V_15 ;
}
static int F_67 ( struct V_33 * V_28 , T_4 V_36 ,
unsigned long V_35 )
{
unsigned long V_19 ;
struct V_41 * V_42 ;
F_64 ( & V_28 -> V_56 . V_63 , V_19 ) ;
V_42 = F_30 ( V_28 , V_36 , V_35 ) ;
if ( ! V_42 ) {
unsigned long V_44 = F_22 ( V_36 ,
1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_36
- V_44 , 1 << V_28 -> V_40 ) ;
F_3 ( L_67 ,
V_20 , __LINE__ , V_36 ) ;
F_3 ( L_68 ,
V_20 , __LINE__ , V_35 ) ;
F_3 ( L_69 ,
V_20 , __LINE__ , V_44 ) ;
F_3 ( L_70 ,
V_20 , __LINE__ , V_45 ) ;
F_34 () ;
}
V_42 -> V_70 -- ;
if ( ! V_42 -> V_70 ) {
F_58 ( & V_42 -> V_55 ) ;
F_36 ( V_42 ) ;
}
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
return 0 ;
}
static int F_68 ( struct V_33 * V_28 ,
T_4 V_36 , unsigned long V_35 )
{
unsigned long V_19 ;
struct V_41 * V_42 ;
F_3 ( L_71 , V_20 , V_36 , V_35 ) ;
F_64 ( & V_28 -> V_56 . V_63 , V_19 ) ;
V_42 = F_30 ( V_28 , V_36 , V_35 ) ;
if ( ! V_42 ) {
unsigned long V_44 = F_22 ( V_36 ,
1 << V_28 -> V_40 ) ;
unsigned long V_45 = F_31 ( V_35 + V_36
- V_44 ,
1 << V_28 -> V_40 ) ;
F_3 ( L_67 ,
V_20 , __LINE__ , V_36 ) ;
F_3 ( L_68 ,
V_20 , __LINE__ , V_35 ) ;
F_3 ( L_69 ,
V_20 , __LINE__ , V_44 ) ;
F_3 ( L_70 ,
V_20 , __LINE__ , V_45 ) ;
F_34 () ;
}
V_42 -> V_70 -- ;
if ( ! V_42 -> V_70 ) {
F_58 ( & V_42 -> V_55 ) ;
F_39 ( V_42 ) ;
}
F_65 ( & V_28 -> V_56 . V_63 , V_19 ) ;
F_3 ( L_46 , V_20 ) ;
return 0 ;
}
static int F_69 ( struct V_33 * V_28 )
{
int V_15 ;
unsigned long V_67 , V_35 ;
T_4 V_65 ;
if ( V_28 -> V_35 > 16 * 1024 * 1024 ) {
if ( V_28 -> V_40 != V_71 ) {
F_25 ( L_72 ,
V_20 , __LINE__ ) ;
V_28 -> V_40 = V_71 ;
V_28 -> V_35 = F_31 ( V_28 -> V_35 , 1 << V_28 -> V_40 ) ;
}
}
V_15 = F_49 ( V_28 ) ;
F_5 ( V_15 ) ;
if ( V_28 -> V_13 < V_3 . V_7 . V_8 ) {
V_67 = V_3 . V_7 . V_12 + V_28 -> V_13 ;
V_35 = V_3 . V_7 . V_8 - V_28 -> V_13 ;
if ( V_35 > V_28 -> V_35 )
V_35 = V_28 -> V_35 ;
V_15 = F_62 ( V_28 , V_67 , V_35 , & V_65 ,
V_72 | V_73 | V_74 |
V_75 ) ;
F_5 ( V_15 ) ;
}
if ( V_28 -> V_13 + V_28 -> V_35 > V_3 . V_7 . V_8 ) {
V_67 = V_3 . V_7 . V_8 ;
V_35 = V_28 -> V_35 ;
if ( V_28 -> V_13 >= V_3 . V_7 . V_8 )
V_67 += V_28 -> V_13 - V_3 . V_7 . V_8 ;
else
V_35 -= V_3 . V_7 . V_8 - V_28 -> V_13 ;
V_15 = F_62 ( V_28 , V_67 , V_35 , & V_65 ,
V_72 | V_73 | V_74 |
V_75 ) ;
F_5 ( V_15 ) ;
}
return V_15 ;
}
static int F_70 ( struct V_33 * V_28 )
{
int V_15 ;
T_4 V_36 ;
unsigned long V_35 , V_34 ;
if ( V_28 -> V_13 < V_3 . V_7 . V_8 ) {
V_34 = V_3 . V_7 . V_12 + V_28 -> V_13 ;
V_35 = V_3 . V_7 . V_8 - V_28 -> V_13 ;
if ( V_35 > V_28 -> V_35 )
V_35 = V_28 -> V_35 ;
V_36 = F_27 ( V_28 , V_34 ) ;
V_15 = F_67 ( V_28 , V_36 , V_35 ) ;
F_5 ( V_15 ) ;
}
if ( V_28 -> V_13 + V_28 -> V_35 > V_3 . V_7 . V_8 ) {
V_34 = V_3 . V_11 . V_12 ;
V_35 = V_28 -> V_35 ;
if ( V_28 -> V_13 >= V_3 . V_7 . V_8 )
V_34 += V_28 -> V_13 - V_3 . V_7 . V_8 ;
else
V_35 -= V_3 . V_7 . V_8 - V_28 -> V_13 ;
V_36 = F_27 ( V_28 , V_34 ) ;
V_15 = F_67 ( V_28 , V_36 , V_35 ) ;
F_5 ( V_15 ) ;
}
V_15 = F_56 ( V_28 ) ;
F_5 ( V_15 ) ;
return V_15 ;
}
static int F_71 ( struct V_33 * V_28 ,
unsigned long V_67 , unsigned long V_35 , T_4 * V_36 ,
T_3 V_50 )
{
unsigned long V_14 = F_6 ( V_67 ) ? F_63 ( V_67 )
: V_67 ;
* V_36 = F_27 ( V_28 , F_4 ( V_14 ) ) ;
return 0 ;
}
static int F_72 ( struct V_33 * V_28 ,
T_4 V_36 , unsigned long V_35 )
{
return 0 ;
}
int F_73 ( struct V_76 * V_37 ,
struct V_33 * V_28 , enum V_77 V_40 ,
enum V_78 V_64 , void * V_79 , unsigned long V_35 )
{
unsigned long V_34 ;
V_34 = V_79 ? F_4 ( F_63 ( V_79 ) ) : 0 ;
V_28 -> V_37 = V_37 ;
V_28 -> V_40 = V_40 ;
V_28 -> V_64 = V_64 ;
V_28 -> V_13 = V_34 ;
if ( V_28 -> V_13 >= V_3 . V_7 . V_8 )
V_28 -> V_13 -= V_3 . V_11 . V_13 ;
V_28 -> V_35 = V_35 ? V_35 : F_31 ( V_3 . V_6 , 1 << V_28 -> V_40 ) ;
switch ( V_37 -> V_80 ) {
case V_81 :
V_28 -> V_62 = ( V_69 )
? & V_82
: & V_83 ;
break;
case V_84 :
V_28 -> V_62 = & V_85 ;
break;
default:
F_34 () ;
return - V_86 ;
}
return 0 ;
}
int F_74 ( struct V_33 * V_28 )
{
F_5 ( ! V_28 ) ;
F_5 ( ! V_28 -> V_62 ) ;
F_5 ( ! V_28 -> V_62 -> V_87 ) ;
return V_28 -> V_62 -> V_87 ( V_28 ) ;
}
int F_75 ( struct V_33 * V_28 )
{
F_5 ( ! V_28 ) ;
F_5 ( ! V_28 -> V_62 ) ;
F_5 ( ! V_28 -> V_62 -> free ) ;
return V_28 -> V_62 -> free ( V_28 ) ;
}
int F_76 ( struct V_33 * V_28 , unsigned long V_67 ,
unsigned long V_35 , T_4 * V_36 ,
T_3 V_50 )
{
return V_28 -> V_62 -> V_3 ( V_28 , V_67 , V_35 , V_36 , V_50 ) ;
}
int F_77 ( struct V_33 * V_28 , T_4 V_36 ,
unsigned long V_35 )
{
return V_28 -> V_62 -> V_88 ( V_28 , V_36 , V_35 ) ;
}
void T_2 F_78 ( void )
{
int V_15 ;
F_3 ( L_55 , V_20 , __LINE__ ) ;
V_15 = F_79 ( & V_3 . V_7 . V_12 , & V_3 . V_7 . V_8 ,
& V_3 . V_6 ) ;
if ( V_15 )
F_14 ( L_73 ) ;
V_3 . V_7 . V_13 = V_3 . V_7 . V_12 ;
V_3 . V_9 = V_3 . V_10 = 0 ;
F_5 ( V_3 . V_7 . V_12 ) ;
F_5 ( ! V_3 . V_7 . V_8 ) ;
if ( F_17 ( & V_3 . V_11 ) ) {
V_15 = F_21 ( & V_3 . V_11 , V_3 . V_6 - V_3 . V_7 . V_8 ) ;
if ( ! V_15 )
F_19 ( & V_3 . V_11 ) ;
}
V_3 . V_6 = V_3 . V_7 . V_8 + V_3 . V_11 . V_8 ;
if ( ! V_3 . V_11 . V_8 ) {
F_3 ( L_74 , V_20 , __LINE__ ) ;
} else {
F_3 ( L_75 ,
V_20 , __LINE__ , V_3 . V_7 . V_8 ,
V_3 . V_6 - V_3 . V_7 . V_8 ) ;
F_80 ( V_3 . V_7 . V_8 , V_3 . V_6 - V_3 . V_7 . V_8 ) ;
}
F_3 ( L_41 , V_20 , __LINE__ ) ;
}
void F_81 ( void )
{
F_24 ( & V_3 . V_11 ) ;
}
