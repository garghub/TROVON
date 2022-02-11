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
void F_23 ( struct V_24 * V_24 , struct V_19 * V_20 )
{
if ( V_24 && V_24 -> V_8 && V_24 -> V_27 -> V_36 )
F_24 ( V_24 -> V_12 , V_20 ) ;
}
static void F_25 ( struct V_37 * V_38 )
{
struct line * line = F_26 ( V_38 , struct line , V_39 . V_38 ) ;
struct V_19 * V_20 = F_27 ( & line -> V_40 ) ;
if ( ! line -> V_41 )
F_28 ( line , V_20 , line -> V_42 -> V_43 ) ;
F_29 ( V_20 ) ;
}
int F_30 ( struct line * line )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
int V_25 ;
F_31 ( & line -> V_39 , F_25 ) ;
F_21 (ele, &line->chan_list) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
V_25 = F_18 ( V_24 ) ;
if ( V_25 ) {
if ( V_24 -> V_8 )
goto V_44;
continue;
}
if ( V_24 -> V_45 )
continue;
V_25 = F_32 ( V_24 -> V_12 , V_24 -> V_6 , V_24 -> V_7 , line ,
V_24 ) ;
if ( V_25 )
goto V_44;
V_24 -> V_45 = 1 ;
}
return 0 ;
V_44:
F_33 ( line ) ;
return V_25 ;
}
void F_34 ( void )
{
struct V_24 * V_24 ;
F_35 ( V_35 ) ;
struct V_31 * V_33 ;
unsigned long V_46 ;
F_36 ( & V_47 , V_46 ) ;
F_37 ( & V_48 , & V_35 ) ;
F_38 ( & V_47 , V_46 ) ;
F_21 (ele, &list) {
V_24 = F_22 ( V_33 , struct V_24 , V_49 ) ;
if ( V_24 -> V_6 && V_24 -> V_45 )
F_39 ( V_24 -> line -> V_42 -> V_43 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_45 )
F_39 ( V_24 -> line -> V_42 -> V_50 , V_24 ) ;
V_24 -> V_45 = 0 ;
}
}
static void F_40 ( struct V_24 * V_24 , int V_51 )
{
unsigned long V_46 ;
if ( ! V_24 -> V_26 )
return;
if ( V_51 ) {
F_36 ( & V_47 , V_46 ) ;
F_41 ( & V_24 -> V_49 , & V_48 ) ;
F_38 ( & V_47 , V_46 ) ;
}
else {
if ( V_24 -> V_6 && V_24 -> V_45 )
F_39 ( V_24 -> line -> V_42 -> V_43 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_45 )
F_39 ( V_24 -> line -> V_42 -> V_50 , V_24 ) ;
V_24 -> V_45 = 0 ;
}
if ( V_24 -> V_27 -> V_30 != NULL )
(* V_24 -> V_27 -> V_30 )( V_24 -> V_12 , V_24 -> V_9 ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_12 = - 1 ;
}
void F_33 ( struct line * line )
{
struct V_24 * V_24 ;
F_42 (chan, &line->chan_list, list) {
F_40 ( V_24 , 0 ) ;
}
}
void F_43 ( struct V_24 * V_24 , int V_52 )
{
if ( V_24 && V_24 -> V_45 )
F_44 ( V_24 -> V_12 , V_52 ) ;
}
void F_45 ( struct V_24 * V_24 , int V_52 )
{
if ( V_24 && V_24 -> V_45 )
F_46 ( V_24 -> V_12 , V_52 ) ;
}
int F_47 ( struct V_24 * V_24 , const char * V_15 , int V_16 ,
int V_50 )
{
int V_53 , V_34 = 0 ;
if ( V_16 == 0 || ! V_24 || ! V_24 -> V_27 -> V_54 )
return 0 ;
V_53 = V_24 -> V_27 -> V_54 ( V_24 -> V_12 , V_15 , V_16 , V_24 -> V_9 ) ;
if ( V_24 -> V_8 ) {
V_34 = V_53 ;
if ( ( V_34 == - V_55 ) || ( ( V_34 >= 0 ) && ( V_34 < V_16 ) ) )
F_46 ( V_24 -> V_12 , V_50 ) ;
}
return V_34 ;
}
int F_48 ( struct V_24 * V_24 , const char * V_15 , int V_16 )
{
int V_53 , V_34 = 0 ;
if ( ! V_24 || ! V_24 -> V_27 -> V_56 )
return 0 ;
V_53 = V_24 -> V_27 -> V_56 ( V_24 -> V_12 , V_15 , V_16 ) ;
if ( V_24 -> V_8 )
V_34 = V_53 ;
return V_34 ;
}
int F_49 ( struct line * line , struct V_57 * V_58 )
{
int V_25 ;
V_25 = F_20 ( & line -> V_59 ) ;
if ( V_25 )
return V_25 ;
F_2 ( V_60 L_3 , V_58 -> V_61 ,
V_58 -> V_62 ) ;
return 0 ;
}
int F_50 ( struct line * line , unsigned short * V_63 ,
unsigned short * V_64 )
{
struct V_24 * V_24 ;
V_24 = line -> V_65 ;
if ( V_24 && V_24 -> V_8 ) {
if ( V_24 -> V_27 -> V_66 == NULL )
return 0 ;
return V_24 -> V_27 -> V_66 ( V_24 -> V_12 , V_24 -> V_9 ,
V_63 , V_64 ) ;
}
V_24 = line -> V_67 ;
if ( V_24 && V_24 -> V_8 ) {
if ( V_24 -> V_27 -> V_66 == NULL )
return 0 ;
return V_24 -> V_27 -> V_66 ( V_24 -> V_12 , V_24 -> V_9 ,
V_63 , V_64 ) ;
}
return 0 ;
}
static void F_51 ( struct V_24 * V_24 )
{
F_52 ( & V_24 -> V_35 ) ;
F_40 ( V_24 , 0 ) ;
if ( V_24 -> V_27 -> free != NULL )
(* V_24 -> V_27 -> free )( V_24 -> V_9 ) ;
if ( V_24 -> V_8 && V_24 -> V_7 )
F_53 ( V_24 -> V_12 ) ;
F_54 ( V_24 ) ;
}
static void F_55 ( struct V_31 * V_32 )
{
struct V_31 * V_33 , * V_68 ;
struct V_24 * V_24 ;
F_56 (ele, next, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
F_51 ( V_24 ) ;
}
}
static int F_57 ( struct V_24 * V_24 , char * V_1 , int V_69 ,
char * * V_70 )
{
int V_53 = 0 ;
if ( V_24 == NULL ) {
F_58 ( V_1 , V_69 , V_53 , L_4 , 1 ) ;
return V_53 ;
}
F_58 ( V_1 , V_69 , V_53 , V_24 -> V_27 -> type , 0 ) ;
if ( V_24 -> V_29 == NULL ) {
F_58 ( V_1 , V_69 , V_53 , L_5 , 1 ) ;
return V_53 ;
}
F_58 ( V_1 , V_69 , V_53 , L_6 , 0 ) ;
F_58 ( V_1 , V_69 , V_53 , V_24 -> V_29 , 0 ) ;
return V_53 ;
}
static int F_59 ( struct V_24 * V_71 , struct V_24 * V_72 ,
char * V_1 , int V_69 , char * * V_70 )
{
int V_53 ;
V_53 = F_57 ( V_71 , V_1 , V_69 , V_70 ) ;
V_1 += V_53 ;
V_69 -= V_53 ;
if ( V_71 == V_72 ) {
F_58 ( V_1 , V_69 , V_53 , L_5 , 1 ) ;
return V_53 ;
}
F_58 ( V_1 , V_69 , V_53 , L_7 , 1 ) ;
V_53 = F_57 ( V_72 , V_1 , V_69 , V_70 ) ;
V_1 += V_53 ;
V_69 -= V_53 ;
F_58 ( V_1 , V_69 , V_53 , L_5 , 1 ) ;
return V_53 ;
}
int F_60 ( struct line * line , char * V_1 , int V_69 ,
char * * V_70 )
{
struct V_24 * V_71 = line -> V_65 , * V_72 = line -> V_67 ;
if ( V_71 && ! V_71 -> V_8 )
V_71 = NULL ;
if ( V_72 && ! V_72 -> V_8 )
V_72 = NULL ;
return F_59 ( V_71 , V_72 , V_1 , V_69 , V_70 ) ;
}
static struct V_24 * F_61 ( struct line * line , char * V_1 , int V_2 ,
const struct V_3 * V_4 , char * * V_70 )
{
const struct V_73 * V_74 ;
const struct V_75 * V_27 ;
struct V_24 * V_24 ;
void * V_9 ;
int V_76 ;
V_27 = NULL ;
V_9 = NULL ;
for( V_76 = 0 ; V_76 < F_62 ( V_77 ) ; V_76 ++ ) {
V_74 = & V_77 [ V_76 ] ;
if ( ! strncmp ( V_1 , V_74 -> V_78 , strlen ( V_74 -> V_78 ) ) ) {
V_27 = V_74 -> V_27 ;
V_1 += strlen ( V_74 -> V_78 ) ;
break;
}
}
if ( V_27 == NULL ) {
* V_70 = L_8 ;
return NULL ;
}
V_9 = (* V_27 -> V_79 )( V_1 , V_2 , V_4 ) ;
if ( V_9 == NULL ) {
* V_70 = L_9 ;
return NULL ;
}
V_24 = F_63 ( sizeof( * V_24 ) , V_80 ) ;
if ( V_24 == NULL ) {
* V_70 = L_10 ;
return NULL ;
}
* V_24 = ( (struct V_24 ) { . V_35 = F_64 ( V_24 -> V_35 ) ,
. V_49 =
F_64 ( V_24 -> V_49 ) ,
. line = line ,
. V_8 = 1 ,
. V_6 = 0 ,
. V_7 = 0 ,
. V_26 = 0 ,
. V_45 = 0 ,
. V_12 = - 1 ,
. V_27 = V_27 ,
. V_9 = V_9 } ) ;
return V_24 ;
}
int F_65 ( char * V_1 , struct line * line , int V_2 ,
const struct V_3 * V_4 , char * * V_70 )
{
struct V_31 * V_32 = & line -> V_59 ;
struct V_24 * V_81 ;
char * V_71 , * V_72 ;
if ( ! F_66 ( V_32 ) ) {
line -> V_65 = line -> V_67 = NULL ;
F_55 ( V_32 ) ;
F_67 ( V_32 ) ;
}
if ( ! V_1 )
return 0 ;
V_72 = strchr ( V_1 , ',' ) ;
if ( V_72 != NULL ) {
V_71 = V_1 ;
* V_72 = '\0' ;
V_72 ++ ;
V_81 = F_61 ( line , V_71 , V_2 , V_4 , V_70 ) ;
if ( V_81 == NULL )
return - 1 ;
V_81 -> V_6 = 1 ;
F_41 ( & V_81 -> V_35 , V_32 ) ;
line -> V_65 = V_81 ;
V_81 = F_61 ( line , V_72 , V_2 , V_4 , V_70 ) ;
if ( V_81 == NULL )
return - 1 ;
F_41 ( & V_81 -> V_35 , V_32 ) ;
V_81 -> V_7 = 1 ;
line -> V_67 = V_81 ;
}
else {
V_81 = F_61 ( line , V_1 , V_2 , V_4 , V_70 ) ;
if ( V_81 == NULL )
return - 1 ;
F_41 ( & V_81 -> V_35 , V_32 ) ;
V_81 -> V_6 = 1 ;
V_81 -> V_7 = 1 ;
line -> V_65 = line -> V_67 = V_81 ;
}
return 0 ;
}
void F_28 ( struct line * line , struct V_19 * V_20 , int V_52 )
{
struct V_24 * V_24 = line -> V_65 ;
int V_25 ;
char V_82 ;
if ( ! V_24 || ! V_24 -> V_27 -> V_83 )
goto V_72;
do {
if ( V_20 && ! F_68 ( V_20 , 1 ) ) {
F_69 ( & line -> V_39 , 1 ) ;
goto V_72;
}
V_25 = V_24 -> V_27 -> V_83 ( V_24 -> V_12 , & V_82 , V_24 -> V_9 ) ;
if ( V_25 > 0 )
F_10 ( V_20 , V_82 ) ;
} while ( V_25 > 0 );
if ( V_25 == 0 )
F_46 ( V_24 -> V_12 , V_52 ) ;
if ( V_25 == - V_14 ) {
if ( V_24 -> V_8 ) {
if ( V_20 != NULL )
F_70 ( V_20 ) ;
if ( line -> V_67 != V_24 )
F_40 ( line -> V_67 , 1 ) ;
}
F_40 ( V_24 , 1 ) ;
if ( V_24 -> V_8 )
return;
}
V_72:
if ( V_20 )
F_71 ( V_20 ) ;
}
