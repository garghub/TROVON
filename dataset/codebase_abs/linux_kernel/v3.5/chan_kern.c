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
if ( ! line -> V_40 )
F_27 ( line , line -> V_20 , line -> V_41 -> V_42 ) ;
}
int F_28 ( struct line * line )
{
struct V_31 * V_33 ;
struct V_24 * V_24 ;
int V_25 ;
F_29 ( & line -> V_39 , F_25 ) ;
F_21 (ele, &line->chan_list) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
V_25 = F_18 ( V_24 ) ;
if ( V_25 ) {
if ( V_24 -> V_8 )
goto V_43;
continue;
}
if ( V_24 -> V_44 )
continue;
V_25 = F_30 ( V_24 -> V_12 , V_24 -> V_6 , V_24 -> V_7 , line ,
V_24 ) ;
if ( V_25 )
goto V_43;
V_24 -> V_44 = 1 ;
}
return 0 ;
V_43:
F_31 ( line ) ;
return V_25 ;
}
void F_32 ( void )
{
struct V_24 * V_24 ;
F_33 ( V_35 ) ;
struct V_31 * V_33 ;
unsigned long V_45 ;
F_34 ( & V_46 , V_45 ) ;
F_35 ( & V_47 , & V_35 ) ;
F_36 ( & V_46 , V_45 ) ;
F_21 (ele, &list) {
V_24 = F_22 ( V_33 , struct V_24 , V_48 ) ;
if ( V_24 -> V_6 && V_24 -> V_44 )
F_37 ( V_24 -> line -> V_41 -> V_42 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_44 )
F_37 ( V_24 -> line -> V_41 -> V_49 , V_24 ) ;
V_24 -> V_44 = 0 ;
}
}
static void F_38 ( struct V_24 * V_24 , int V_50 )
{
unsigned long V_45 ;
if ( ! V_24 -> V_26 )
return;
if ( V_50 ) {
F_34 ( & V_46 , V_45 ) ;
F_39 ( & V_24 -> V_48 , & V_47 ) ;
F_36 ( & V_46 , V_45 ) ;
}
else {
if ( V_24 -> V_6 && V_24 -> V_44 )
F_37 ( V_24 -> line -> V_41 -> V_42 , V_24 ) ;
if ( V_24 -> V_7 && V_24 -> V_44 )
F_37 ( V_24 -> line -> V_41 -> V_49 , V_24 ) ;
V_24 -> V_44 = 0 ;
}
if ( V_24 -> V_27 -> V_30 != NULL )
(* V_24 -> V_27 -> V_30 )( V_24 -> V_12 , V_24 -> V_9 ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_12 = - 1 ;
}
void F_31 ( struct line * line )
{
struct V_24 * V_24 ;
F_40 (chan, &line->chan_list, list) {
F_38 ( V_24 , 0 ) ;
}
}
void F_41 ( struct V_24 * V_24 , int V_51 )
{
if ( V_24 && V_24 -> V_44 )
F_42 ( V_24 -> V_12 , V_51 ) ;
}
void F_43 ( struct V_24 * V_24 , int V_51 )
{
if ( V_24 && V_24 -> V_44 )
F_44 ( V_24 -> V_12 , V_51 ) ;
}
int F_45 ( struct V_24 * V_24 , const char * V_15 , int V_16 ,
int V_49 )
{
int V_52 , V_34 = 0 ;
if ( V_16 == 0 || ! V_24 || ! V_24 -> V_27 -> V_53 )
return 0 ;
V_52 = V_24 -> V_27 -> V_53 ( V_24 -> V_12 , V_15 , V_16 , V_24 -> V_9 ) ;
if ( V_24 -> V_8 ) {
V_34 = V_52 ;
if ( ( V_34 == - V_54 ) || ( ( V_34 >= 0 ) && ( V_34 < V_16 ) ) )
F_44 ( V_24 -> V_12 , V_49 ) ;
}
return V_34 ;
}
int F_46 ( struct V_24 * V_24 , const char * V_15 , int V_16 )
{
int V_52 , V_34 = 0 ;
if ( ! V_24 || ! V_24 -> V_27 -> V_55 )
return 0 ;
V_52 = V_24 -> V_27 -> V_55 ( V_24 -> V_12 , V_15 , V_16 ) ;
if ( V_24 -> V_8 )
V_34 = V_52 ;
return V_34 ;
}
int F_47 ( struct line * line , struct V_56 * V_57 )
{
int V_25 ;
V_25 = F_20 ( & line -> V_58 ) ;
if ( V_25 )
return V_25 ;
F_2 ( V_59 L_3 , V_57 -> V_60 ,
V_57 -> V_61 ) ;
return 0 ;
}
int F_48 ( struct line * line , unsigned short * V_62 ,
unsigned short * V_63 )
{
struct V_24 * V_24 ;
V_24 = line -> V_64 ;
if ( V_24 && V_24 -> V_8 ) {
if ( V_24 -> V_27 -> V_65 == NULL )
return 0 ;
return V_24 -> V_27 -> V_65 ( V_24 -> V_12 , V_24 -> V_9 ,
V_62 , V_63 ) ;
}
V_24 = line -> V_66 ;
if ( V_24 && V_24 -> V_8 ) {
if ( V_24 -> V_27 -> V_65 == NULL )
return 0 ;
return V_24 -> V_27 -> V_65 ( V_24 -> V_12 , V_24 -> V_9 ,
V_62 , V_63 ) ;
}
return 0 ;
}
static void F_49 ( struct V_24 * V_24 )
{
F_50 ( & V_24 -> V_35 ) ;
F_38 ( V_24 , 0 ) ;
if ( V_24 -> V_27 -> free != NULL )
(* V_24 -> V_27 -> free )( V_24 -> V_9 ) ;
if ( V_24 -> V_8 && V_24 -> V_7 )
F_51 ( V_24 -> V_12 ) ;
F_52 ( V_24 ) ;
}
static void F_53 ( struct V_31 * V_32 )
{
struct V_31 * V_33 , * V_67 ;
struct V_24 * V_24 ;
F_54 (ele, next, chans) {
V_24 = F_22 ( V_33 , struct V_24 , V_35 ) ;
F_49 ( V_24 ) ;
}
}
static int F_55 ( struct V_24 * V_24 , char * V_1 , int V_68 ,
char * * V_69 )
{
int V_52 = 0 ;
if ( V_24 == NULL ) {
F_56 ( V_1 , V_68 , V_52 , L_4 , 1 ) ;
return V_52 ;
}
F_56 ( V_1 , V_68 , V_52 , V_24 -> V_27 -> type , 0 ) ;
if ( V_24 -> V_29 == NULL ) {
F_56 ( V_1 , V_68 , V_52 , L_5 , 1 ) ;
return V_52 ;
}
F_56 ( V_1 , V_68 , V_52 , L_6 , 0 ) ;
F_56 ( V_1 , V_68 , V_52 , V_24 -> V_29 , 0 ) ;
return V_52 ;
}
static int F_57 ( struct V_24 * V_70 , struct V_24 * V_71 ,
char * V_1 , int V_68 , char * * V_69 )
{
int V_52 ;
V_52 = F_55 ( V_70 , V_1 , V_68 , V_69 ) ;
V_1 += V_52 ;
V_68 -= V_52 ;
if ( V_70 == V_71 ) {
F_56 ( V_1 , V_68 , V_52 , L_5 , 1 ) ;
return V_52 ;
}
F_56 ( V_1 , V_68 , V_52 , L_7 , 1 ) ;
V_52 = F_55 ( V_71 , V_1 , V_68 , V_69 ) ;
V_1 += V_52 ;
V_68 -= V_52 ;
F_56 ( V_1 , V_68 , V_52 , L_5 , 1 ) ;
return V_52 ;
}
int F_58 ( struct line * line , char * V_1 , int V_68 ,
char * * V_69 )
{
struct V_24 * V_70 = line -> V_64 , * V_71 = line -> V_66 ;
if ( V_70 && ! V_70 -> V_8 )
V_70 = NULL ;
if ( V_71 && ! V_71 -> V_8 )
V_71 = NULL ;
return F_57 ( V_70 , V_71 , V_1 , V_68 , V_69 ) ;
}
static struct V_24 * F_59 ( struct line * line , char * V_1 , int V_2 ,
const struct V_3 * V_4 , char * * V_69 )
{
const struct V_72 * V_73 ;
const struct V_74 * V_27 ;
struct V_24 * V_24 ;
void * V_9 ;
int V_75 ;
V_27 = NULL ;
V_9 = NULL ;
for( V_75 = 0 ; V_75 < F_60 ( V_76 ) ; V_75 ++ ) {
V_73 = & V_76 [ V_75 ] ;
if ( ! strncmp ( V_1 , V_73 -> V_77 , strlen ( V_73 -> V_77 ) ) ) {
V_27 = V_73 -> V_27 ;
V_1 += strlen ( V_73 -> V_77 ) ;
break;
}
}
if ( V_27 == NULL ) {
* V_69 = L_8 ;
return NULL ;
}
V_9 = (* V_27 -> V_78 )( V_1 , V_2 , V_4 ) ;
if ( V_9 == NULL ) {
* V_69 = L_9 ;
return NULL ;
}
V_24 = F_61 ( sizeof( * V_24 ) , V_79 ) ;
if ( V_24 == NULL ) {
* V_69 = L_10 ;
return NULL ;
}
* V_24 = ( (struct V_24 ) { . V_35 = F_62 ( V_24 -> V_35 ) ,
. V_48 =
F_62 ( V_24 -> V_48 ) ,
. line = line ,
. V_8 = 1 ,
. V_6 = 0 ,
. V_7 = 0 ,
. V_26 = 0 ,
. V_44 = 0 ,
. V_12 = - 1 ,
. V_27 = V_27 ,
. V_9 = V_9 } ) ;
return V_24 ;
}
int F_63 ( char * V_1 , struct line * line , int V_2 ,
const struct V_3 * V_4 , char * * V_69 )
{
struct V_31 * V_32 = & line -> V_58 ;
struct V_24 * V_80 ;
char * V_70 , * V_71 ;
if ( ! F_64 ( V_32 ) ) {
line -> V_64 = line -> V_66 = NULL ;
F_53 ( V_32 ) ;
F_65 ( V_32 ) ;
}
if ( ! V_1 )
return 0 ;
V_71 = strchr ( V_1 , ',' ) ;
if ( V_71 != NULL ) {
V_70 = V_1 ;
* V_71 = '\0' ;
V_71 ++ ;
V_80 = F_59 ( line , V_70 , V_2 , V_4 , V_69 ) ;
if ( V_80 == NULL )
return - 1 ;
V_80 -> V_6 = 1 ;
F_39 ( & V_80 -> V_35 , V_32 ) ;
line -> V_64 = V_80 ;
V_80 = F_59 ( line , V_71 , V_2 , V_4 , V_69 ) ;
if ( V_80 == NULL )
return - 1 ;
F_39 ( & V_80 -> V_35 , V_32 ) ;
V_80 -> V_7 = 1 ;
line -> V_66 = V_80 ;
}
else {
V_80 = F_59 ( line , V_1 , V_2 , V_4 , V_69 ) ;
if ( V_80 == NULL )
return - 1 ;
F_39 ( & V_80 -> V_35 , V_32 ) ;
V_80 -> V_6 = 1 ;
V_80 -> V_7 = 1 ;
line -> V_64 = line -> V_66 = V_80 ;
}
return 0 ;
}
void F_27 ( struct line * line , struct V_19 * V_20 , int V_51 )
{
struct V_24 * V_24 = line -> V_64 ;
int V_25 ;
char V_81 ;
if ( ! V_24 || ! V_24 -> V_27 -> V_82 )
goto V_71;
do {
if ( V_20 && ! F_66 ( V_20 , 1 ) ) {
F_67 ( & line -> V_39 , 1 ) ;
goto V_71;
}
V_25 = V_24 -> V_27 -> V_82 ( V_24 -> V_12 , & V_81 , V_24 -> V_9 ) ;
if ( V_25 > 0 )
F_10 ( V_20 , V_81 ) ;
} while ( V_25 > 0 );
if ( V_25 == 0 )
F_44 ( V_24 -> V_12 , V_51 ) ;
if ( V_25 == - V_14 ) {
if ( V_24 -> V_8 ) {
if ( V_20 != NULL )
F_68 ( V_20 ) ;
if ( line -> V_66 != V_24 )
F_38 ( line -> V_66 , 1 ) ;
}
F_38 ( V_24 , 1 ) ;
if ( V_24 -> V_8 )
return;
}
V_71:
if ( V_20 )
F_69 ( V_20 ) ;
}
