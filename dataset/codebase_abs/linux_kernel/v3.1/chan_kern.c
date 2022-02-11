static void * F_1 ( char * V_1 , int V_2 ,
const struct V_3 * V_4 )
{
F_2 ( V_5 L_1
L_2 ) ;
return NULL ;
}
static int F_3 ( int V_6 , int V_7 , int V_8 , void * V_9 ,
char * * V_10 )
{
F_2 ( V_5 L_1
L_2 ) ;
return - V_11 ;
}
static void F_4 ( int V_12 , void * V_9 )
{
F_2 ( V_5 L_1
L_2 ) ;
}
static int F_5 ( int V_12 , char * V_13 , void * V_9 )
{
F_2 ( V_5 L_1
L_2 ) ;
return - V_14 ;
}
static int F_6 ( int V_12 , const char * V_15 , int V_16 , void * V_9 )
{
F_2 ( V_5 L_1
L_2 ) ;
return - V_14 ;
}
static int F_7 ( int V_12 , const char * V_15 , int V_16 )
{
F_2 ( V_5 L_1
L_2 ) ;
return - V_14 ;
}
static int F_8 ( int V_12 , void * V_9 , unsigned short * V_17 ,
unsigned short * V_18 )
{
F_2 ( V_5 L_1
L_2 ) ;
return - V_11 ;
}
static void F_9 ( void * V_9 )
{
F_2 ( V_5 L_1
L_2 ) ;
}
static void F_10 ( struct V_19 * V_20 , char V_21 )
{
if ( V_20 == NULL )
return;
if ( F_11 ( V_20 ) && ! F_12 ( V_20 ) && ! V_20 -> V_22 ) {
if ( V_21 == F_13 ( V_20 ) ) {
F_14 ( V_20 ) ;
return;
}
else if ( V_21 == F_15 ( V_20 ) ) {
F_16 ( V_20 ) ;
return;
}
}
F_17 ( V_20 , V_21 , V_23 ) ;
}
static int F_18 ( struct V_24 * V_24 )
{
int V_12 , V_25 ;
if ( V_24 -> V_26 )
return 0 ;
if ( V_24 -> V_27 -> V_28 == NULL )
V_12 = 0 ;
else V_12 = (* V_24 -> V_27 -> V_28 )( V_24 -> V_6 , V_24 -> V_7 , V_24 -> V_8 ,
V_24 -> V_9 , & V_24 -> V_29 ) ;
if ( V_12 < 0 )
return V_12 ;
V_25 = F_19 ( V_12 , 0 ) ;
if ( V_25 ) {
(* V_24 -> V_27 -> V_30 )( V_12 , V_24 -> V_9 ) ;
return V_25 ;
}
V_24 -> V_12 = V_12 ;
V_24 -> V_26 = 1 ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
int V_34 , V_25 = 0 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
V_34 = F_18 ( V_24 ) ;
if ( V_24 -> V_8 )
V_25 = V_34 ;
}
return V_25 ;
}
void F_23 ( struct V_31 * V_32 , struct V_19 * V_20 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( V_24 -> V_8 && V_24 -> V_7 && V_24 -> V_27 -> V_36 ) {
F_24 ( V_24 -> V_12 , V_20 ) ;
return;
}
}
}
int F_25 ( struct line * line )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
int V_25 ;
F_21 (ele, &line->chan_list) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
V_25 = F_18 ( V_24 ) ;
if ( V_25 ) {
if ( V_24 -> V_8 )
goto V_37;
continue;
}
if ( V_24 -> V_38 )
continue;
V_25 = F_26 ( V_24 -> V_12 , V_24 -> V_6 , V_24 -> V_7 , line ,
V_24 ) ;
if ( V_25 )
goto V_37;
V_24 -> V_38 = 1 ;
}
return 0 ;
V_37:
F_27 ( & line -> V_39 , 0 ) ;
return V_25 ;
}
void F_28 ( void )
{
struct V_24 * V_24 ;
F_29 ( V_35 ) ;
struct V_31 * V_33 ;
unsigned long V_40 ;
F_30 ( & V_41 , V_40 ) ;
F_31 ( & V_42 , & V_35 ) ;
F_32 ( & V_41 , V_40 ) ;
F_21 (ele, &list) {
V_24 = F_22 ( V_33 , struct V_24 , V_43 ) ;
if ( V_24 -> V_6 && V_24 -> V_38 )
F_33 ( V_24 -> line -> V_44 -> V_45 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_38 )
F_33 ( V_24 -> line -> V_44 -> V_46 , V_24 ) ;
V_24 -> V_38 = 0 ;
}
}
static void F_34 ( struct V_24 * V_24 , int V_47 )
{
unsigned long V_40 ;
if ( ! V_24 -> V_26 )
return;
if ( V_47 ) {
F_30 ( & V_41 , V_40 ) ;
F_35 ( & V_24 -> V_43 , & V_42 ) ;
F_32 ( & V_41 , V_40 ) ;
}
else {
if ( V_24 -> V_6 && V_24 -> V_38 )
F_33 ( V_24 -> line -> V_44 -> V_45 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_38 )
F_33 ( V_24 -> line -> V_44 -> V_46 , V_24 ) ;
V_24 -> V_38 = 0 ;
}
if ( V_24 -> V_27 -> V_30 != NULL )
(* V_24 -> V_27 -> V_30 )( V_24 -> V_12 , V_24 -> V_9 ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_12 = - 1 ;
}
void F_27 ( struct V_31 * V_32 , int V_47 )
{
struct V_24 * V_24 ;
F_36 (chan, chans, list) {
F_34 ( V_24 , V_47 ) ;
}
}
void F_37 ( struct V_31 * V_32 , int V_48 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( V_24 -> V_38 && V_24 -> V_6 )
F_38 ( V_24 -> V_12 , V_48 ) ;
}
}
void F_39 ( struct V_31 * V_32 , int V_48 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( V_24 -> V_38 && V_24 -> V_6 )
F_40 ( V_24 -> V_12 , V_48 ) ;
}
}
int F_41 ( struct V_31 * V_32 , const char * V_15 , int V_16 ,
int V_46 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 = NULL ;
int V_49 , V_34 = 0 ;
if ( V_16 == 0 )
return 0 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( ! V_24 -> V_7 || ( V_24 -> V_27 -> V_50 == NULL ) )
continue;
V_49 = V_24 -> V_27 -> V_50 ( V_24 -> V_12 , V_15 , V_16 , V_24 -> V_9 ) ;
if ( V_24 -> V_8 ) {
V_34 = V_49 ;
if ( ( V_34 == - V_51 ) || ( ( V_34 >= 0 ) && ( V_34 < V_16 ) ) )
F_40 ( V_24 -> V_12 , V_46 ) ;
}
}
return V_34 ;
}
int F_42 ( struct V_31 * V_32 , const char * V_15 , int V_16 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
int V_49 , V_34 = 0 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( ! V_24 -> V_7 || ( V_24 -> V_27 -> V_52 == NULL ) )
continue;
V_49 = V_24 -> V_27 -> V_52 ( V_24 -> V_12 , V_15 , V_16 ) ;
if ( V_24 -> V_8 )
V_34 = V_49 ;
}
return V_34 ;
}
int F_43 ( struct line * line , struct V_53 * V_54 )
{
int V_25 ;
V_25 = F_20 ( & line -> V_39 ) ;
if ( V_25 )
return V_25 ;
F_2 ( V_55 L_3 , V_54 -> V_56 ,
V_54 -> V_57 ) ;
return 0 ;
}
int F_44 ( struct V_31 * V_32 , unsigned short * V_58 ,
unsigned short * V_59 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( V_24 -> V_8 ) {
if ( V_24 -> V_27 -> V_60 == NULL )
return 0 ;
return V_24 -> V_27 -> V_60 ( V_24 -> V_12 , V_24 -> V_9 ,
V_58 , V_59 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_24 * V_24 , int V_47 )
{
F_46 ( & V_24 -> V_35 ) ;
F_34 ( V_24 , V_47 ) ;
if ( V_24 -> V_27 -> free != NULL )
(* V_24 -> V_27 -> free )( V_24 -> V_9 ) ;
if ( V_24 -> V_8 && V_24 -> V_7 )
F_47 ( V_24 -> V_12 ) ;
F_48 ( V_24 ) ;
}
static void F_49 ( struct V_31 * V_32 , int V_47 )
{
struct V_31 * V_33 , * V_61 ;
struct V_24 * V_24 ;
F_50 (ele, next, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
F_45 ( V_24 , V_47 ) ;
}
}
static int F_51 ( struct V_24 * V_24 , char * V_1 , int V_62 ,
char * * V_63 )
{
int V_49 = 0 ;
if ( V_24 == NULL ) {
F_52 ( V_1 , V_62 , V_49 , L_4 , 1 ) ;
return V_49 ;
}
F_52 ( V_1 , V_62 , V_49 , V_24 -> V_27 -> type , 0 ) ;
if ( V_24 -> V_29 == NULL ) {
F_52 ( V_1 , V_62 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
F_52 ( V_1 , V_62 , V_49 , L_6 , 0 ) ;
F_52 ( V_1 , V_62 , V_49 , V_24 -> V_29 , 0 ) ;
return V_49 ;
}
static int F_53 ( struct V_24 * V_64 , struct V_24 * V_65 ,
char * V_1 , int V_62 , char * * V_63 )
{
int V_49 ;
V_49 = F_51 ( V_64 , V_1 , V_62 , V_63 ) ;
V_1 += V_49 ;
V_62 -= V_49 ;
if ( V_64 == V_65 ) {
F_52 ( V_1 , V_62 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
F_52 ( V_1 , V_62 , V_49 , L_7 , 1 ) ;
V_49 = F_51 ( V_65 , V_1 , V_62 , V_63 ) ;
V_1 += V_49 ;
V_62 -= V_49 ;
F_52 ( V_1 , V_62 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
int F_54 ( struct V_31 * V_32 , char * V_1 , int V_62 ,
char * * V_63 )
{
struct V_31 * V_33 ;
struct V_24 * V_24 , * V_64 = NULL , * V_65 = NULL ;
F_21 (ele, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( ! V_24 -> V_8 )
continue;
if ( V_24 -> V_6 )
V_64 = V_24 ;
if ( V_24 -> V_7 )
V_65 = V_24 ;
}
return F_53 ( V_64 , V_65 , V_1 , V_62 , V_63 ) ;
}
static struct V_24 * F_55 ( struct line * line , char * V_1 , int V_2 ,
const struct V_3 * V_4 , char * * V_63 )
{
const struct V_66 * V_67 ;
const struct V_68 * V_27 ;
struct V_24 * V_24 ;
void * V_9 ;
int V_69 ;
V_27 = NULL ;
V_9 = NULL ;
for( V_69 = 0 ; V_69 < F_56 ( V_70 ) ; V_69 ++ ) {
V_67 = & V_70 [ V_69 ] ;
if ( ! strncmp ( V_1 , V_67 -> V_71 , strlen ( V_67 -> V_71 ) ) ) {
V_27 = V_67 -> V_27 ;
V_1 += strlen ( V_67 -> V_71 ) ;
break;
}
}
if ( V_27 == NULL ) {
* V_63 = L_8 ;
return NULL ;
}
V_9 = (* V_27 -> V_72 )( V_1 , V_2 , V_4 ) ;
if ( V_9 == NULL ) {
* V_63 = L_9 ;
return NULL ;
}
V_24 = F_57 ( sizeof( * V_24 ) , V_73 ) ;
if ( V_24 == NULL ) {
* V_63 = L_10 ;
return NULL ;
}
* V_24 = ( (struct V_24 ) { . V_35 = F_58 ( V_24 -> V_35 ) ,
. V_43 =
F_58 ( V_24 -> V_43 ) ,
. line = line ,
. V_8 = 1 ,
. V_6 = 0 ,
. V_7 = 0 ,
. V_26 = 0 ,
. V_38 = 0 ,
. V_12 = - 1 ,
. V_27 = V_27 ,
. V_9 = V_9 } ) ;
return V_24 ;
}
int F_59 ( char * V_1 , struct line * line , int V_2 ,
const struct V_3 * V_4 , char * * V_63 )
{
struct V_31 * V_32 = & line -> V_39 ;
struct V_24 * V_74 ;
char * V_64 , * V_65 ;
if ( ! F_60 ( V_32 ) ) {
F_49 ( V_32 , 0 ) ;
F_61 ( V_32 ) ;
}
V_65 = strchr ( V_1 , ',' ) ;
if ( V_65 != NULL ) {
V_64 = V_1 ;
* V_65 = '\0' ;
V_65 ++ ;
V_74 = F_55 ( line , V_64 , V_2 , V_4 , V_63 ) ;
if ( V_74 == NULL )
return - 1 ;
V_74 -> V_6 = 1 ;
F_35 ( & V_74 -> V_35 , V_32 ) ;
V_74 = F_55 ( line , V_65 , V_2 , V_4 , V_63 ) ;
if ( V_74 == NULL )
return - 1 ;
F_35 ( & V_74 -> V_35 , V_32 ) ;
V_74 -> V_7 = 1 ;
}
else {
V_74 = F_55 ( line , V_1 , V_2 , V_4 , V_63 ) ;
if ( V_74 == NULL )
return - 1 ;
F_35 ( & V_74 -> V_35 , V_32 ) ;
V_74 -> V_6 = 1 ;
V_74 -> V_7 = 1 ;
}
return 0 ;
}
void F_62 ( struct V_31 * V_32 , struct V_75 * V_76 ,
struct V_19 * V_20 , int V_48 )
{
struct V_31 * V_33 , * V_61 ;
struct V_24 * V_24 ;
int V_25 ;
char V_77 ;
F_50 (ele, next, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
if ( ! V_24 -> V_6 || ( V_24 -> V_27 -> V_78 == NULL ) )
continue;
do {
if ( V_20 && ! F_63 ( V_20 , 1 ) ) {
F_64 ( V_76 , 1 ) ;
goto V_65;
}
V_25 = V_24 -> V_27 -> V_78 ( V_24 -> V_12 , & V_77 , V_24 -> V_9 ) ;
if ( V_25 > 0 )
F_10 ( V_20 , V_77 ) ;
} while ( V_25 > 0 );
if ( V_25 == 0 )
F_40 ( V_24 -> V_12 , V_48 ) ;
if ( V_25 == - V_14 ) {
if ( V_24 -> V_8 ) {
if ( V_20 != NULL )
F_65 ( V_20 ) ;
F_27 ( V_32 , 1 ) ;
return;
}
else F_34 ( V_24 , 1 ) ;
}
}
V_65:
if ( V_20 )
F_66 ( V_20 ) ;
}
