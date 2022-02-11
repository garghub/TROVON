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
static int F_10 ( struct V_19 * V_19 )
{
int V_12 , V_20 ;
if ( V_19 -> V_21 )
return 0 ;
if ( V_19 -> V_22 -> V_23 == NULL )
V_12 = 0 ;
else V_12 = (* V_19 -> V_22 -> V_23 )( V_19 -> V_6 , V_19 -> V_7 , V_19 -> V_8 ,
V_19 -> V_9 , & V_19 -> V_24 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = F_11 ( V_12 , 0 ) ;
if ( V_20 ) {
(* V_19 -> V_22 -> V_25 )( V_12 , V_19 -> V_9 ) ;
return V_20 ;
}
V_19 -> V_12 = V_12 ;
V_19 -> V_21 = 1 ;
return 0 ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_26 * V_28 ;
struct V_19 * V_19 ;
int V_29 , V_20 = 0 ;
F_13 (ele, chans) {
V_19 = F_14 ( V_28 , struct V_19 , V_30 ) ;
V_29 = F_10 ( V_19 ) ;
if ( V_19 -> V_8 )
V_20 = V_29 ;
}
return V_20 ;
}
void F_15 ( struct V_19 * V_19 , struct V_31 * V_32 )
{
if ( V_19 && V_19 -> V_8 && V_19 -> V_22 -> V_33 )
F_16 ( V_19 -> V_12 , V_32 ) ;
}
static void F_17 ( struct V_34 * V_35 )
{
struct line * line = F_18 ( V_35 , struct line , V_36 . V_35 ) ;
if ( ! line -> V_37 )
F_19 ( line , line -> V_38 -> V_39 ) ;
}
int F_20 ( struct line * line )
{
struct V_26 * V_28 ;
struct V_19 * V_19 ;
int V_20 ;
F_21 ( & line -> V_36 , F_17 ) ;
F_13 (ele, &line->chan_list) {
V_19 = F_14 ( V_28 , struct V_19 , V_30 ) ;
V_20 = F_10 ( V_19 ) ;
if ( V_20 ) {
if ( V_19 -> V_8 )
goto V_40;
continue;
}
if ( V_19 -> V_41 )
continue;
V_20 = F_22 ( V_19 -> V_12 , V_19 -> V_6 , V_19 -> V_7 , line ,
V_19 ) ;
if ( V_20 )
goto V_40;
V_19 -> V_41 = 1 ;
}
return 0 ;
V_40:
F_23 ( line ) ;
return V_20 ;
}
void F_24 ( void )
{
struct V_19 * V_19 ;
F_25 ( V_30 ) ;
struct V_26 * V_28 ;
unsigned long V_42 ;
F_26 ( & V_43 , V_42 ) ;
F_27 ( & V_44 , & V_30 ) ;
F_28 ( & V_43 , V_42 ) ;
F_13 (ele, &list) {
V_19 = F_14 ( V_28 , struct V_19 , V_45 ) ;
if ( V_19 -> V_6 && V_19 -> V_41 )
F_29 ( V_19 -> line -> V_38 -> V_39 , V_19 ) ;
if ( V_19 -> V_7 && V_19 -> V_41 )
F_29 ( V_19 -> line -> V_38 -> V_46 , V_19 ) ;
V_19 -> V_41 = 0 ;
}
}
static void F_30 ( struct V_19 * V_19 , int V_47 )
{
unsigned long V_42 ;
if ( ! V_19 -> V_21 )
return;
if ( V_47 ) {
F_26 ( & V_43 , V_42 ) ;
F_31 ( & V_19 -> V_45 , & V_44 ) ;
F_28 ( & V_43 , V_42 ) ;
}
else {
if ( V_19 -> V_6 && V_19 -> V_41 )
F_29 ( V_19 -> line -> V_38 -> V_39 , V_19 ) ;
if ( V_19 -> V_7 && V_19 -> V_41 )
F_29 ( V_19 -> line -> V_38 -> V_46 , V_19 ) ;
V_19 -> V_41 = 0 ;
}
if ( V_19 -> V_22 -> V_25 != NULL )
(* V_19 -> V_22 -> V_25 )( V_19 -> V_12 , V_19 -> V_9 ) ;
V_19 -> V_21 = 0 ;
V_19 -> V_12 = - 1 ;
}
void F_23 ( struct line * line )
{
struct V_19 * V_19 ;
F_32 (chan, &line->chan_list, list) {
F_30 ( V_19 , 0 ) ;
}
}
void F_33 ( struct V_19 * V_19 , int V_48 )
{
if ( V_19 && V_19 -> V_41 )
F_34 ( V_19 -> V_12 , V_48 ) ;
}
void F_35 ( struct V_19 * V_19 , int V_48 )
{
if ( V_19 && V_19 -> V_41 )
F_36 ( V_19 -> V_12 , V_48 ) ;
}
int F_37 ( struct V_19 * V_19 , const char * V_15 , int V_16 ,
int V_46 )
{
int V_49 , V_29 = 0 ;
if ( V_16 == 0 || ! V_19 || ! V_19 -> V_22 -> V_50 )
return 0 ;
V_49 = V_19 -> V_22 -> V_50 ( V_19 -> V_12 , V_15 , V_16 , V_19 -> V_9 ) ;
if ( V_19 -> V_8 ) {
V_29 = V_49 ;
if ( ( V_29 == - V_51 ) || ( ( V_29 >= 0 ) && ( V_29 < V_16 ) ) )
F_36 ( V_19 -> V_12 , V_46 ) ;
}
return V_29 ;
}
int F_38 ( struct V_19 * V_19 , const char * V_15 , int V_16 )
{
int V_49 , V_29 = 0 ;
if ( ! V_19 || ! V_19 -> V_22 -> V_52 )
return 0 ;
V_49 = V_19 -> V_22 -> V_52 ( V_19 -> V_12 , V_15 , V_16 ) ;
if ( V_19 -> V_8 )
V_29 = V_49 ;
return V_29 ;
}
int F_39 ( struct line * line , struct V_53 * V_54 )
{
int V_20 ;
V_20 = F_12 ( & line -> V_55 ) ;
if ( V_20 )
return V_20 ;
F_2 ( V_56 L_3 , V_54 -> V_57 ,
V_54 -> V_58 ) ;
return 0 ;
}
int F_40 ( struct line * line , unsigned short * V_59 ,
unsigned short * V_60 )
{
struct V_19 * V_19 ;
V_19 = line -> V_61 ;
if ( V_19 && V_19 -> V_8 ) {
if ( V_19 -> V_22 -> V_62 == NULL )
return 0 ;
return V_19 -> V_22 -> V_62 ( V_19 -> V_12 , V_19 -> V_9 ,
V_59 , V_60 ) ;
}
V_19 = line -> V_63 ;
if ( V_19 && V_19 -> V_8 ) {
if ( V_19 -> V_22 -> V_62 == NULL )
return 0 ;
return V_19 -> V_22 -> V_62 ( V_19 -> V_12 , V_19 -> V_9 ,
V_59 , V_60 ) ;
}
return 0 ;
}
static void F_41 ( struct V_19 * V_19 )
{
F_42 ( & V_19 -> V_30 ) ;
F_30 ( V_19 , 0 ) ;
if ( V_19 -> V_22 -> free != NULL )
(* V_19 -> V_22 -> free )( V_19 -> V_9 ) ;
if ( V_19 -> V_8 && V_19 -> V_7 )
F_43 ( V_19 -> V_12 ) ;
F_44 ( V_19 ) ;
}
static void F_45 ( struct V_26 * V_27 )
{
struct V_26 * V_28 , * V_64 ;
struct V_19 * V_19 ;
F_46 (ele, next, chans) {
V_19 = F_14 ( V_28 , struct V_19 , V_30 ) ;
F_41 ( V_19 ) ;
}
}
static int F_47 ( struct V_19 * V_19 , char * V_1 , int V_65 ,
char * * V_66 )
{
int V_49 = 0 ;
if ( V_19 == NULL ) {
F_48 ( V_1 , V_65 , V_49 , L_4 , 1 ) ;
return V_49 ;
}
F_48 ( V_1 , V_65 , V_49 , V_19 -> V_22 -> type , 0 ) ;
if ( V_19 -> V_24 == NULL ) {
F_48 ( V_1 , V_65 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
F_48 ( V_1 , V_65 , V_49 , L_6 , 0 ) ;
F_48 ( V_1 , V_65 , V_49 , V_19 -> V_24 , 0 ) ;
return V_49 ;
}
static int F_49 ( struct V_19 * V_67 , struct V_19 * V_68 ,
char * V_1 , int V_65 , char * * V_66 )
{
int V_49 ;
V_49 = F_47 ( V_67 , V_1 , V_65 , V_66 ) ;
V_1 += V_49 ;
V_65 -= V_49 ;
if ( V_67 == V_68 ) {
F_48 ( V_1 , V_65 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
F_48 ( V_1 , V_65 , V_49 , L_7 , 1 ) ;
V_49 = F_47 ( V_68 , V_1 , V_65 , V_66 ) ;
V_1 += V_49 ;
V_65 -= V_49 ;
F_48 ( V_1 , V_65 , V_49 , L_5 , 1 ) ;
return V_49 ;
}
int F_50 ( struct line * line , char * V_1 , int V_65 ,
char * * V_66 )
{
struct V_19 * V_67 = line -> V_61 , * V_68 = line -> V_63 ;
if ( V_67 && ! V_67 -> V_8 )
V_67 = NULL ;
if ( V_68 && ! V_68 -> V_8 )
V_68 = NULL ;
return F_49 ( V_67 , V_68 , V_1 , V_65 , V_66 ) ;
}
static struct V_19 * F_51 ( struct line * line , char * V_1 , int V_2 ,
const struct V_3 * V_4 , char * * V_66 )
{
const struct V_69 * V_70 ;
const struct V_71 * V_22 ;
struct V_19 * V_19 ;
void * V_9 ;
int V_72 ;
V_22 = NULL ;
V_9 = NULL ;
for( V_72 = 0 ; V_72 < F_52 ( V_73 ) ; V_72 ++ ) {
V_70 = & V_73 [ V_72 ] ;
if ( ! strncmp ( V_1 , V_70 -> V_74 , strlen ( V_70 -> V_74 ) ) ) {
V_22 = V_70 -> V_22 ;
V_1 += strlen ( V_70 -> V_74 ) ;
break;
}
}
if ( V_22 == NULL ) {
* V_66 = L_8 ;
return NULL ;
}
V_9 = (* V_22 -> V_75 )( V_1 , V_2 , V_4 ) ;
if ( V_9 == NULL ) {
* V_66 = L_9 ;
return NULL ;
}
V_19 = F_53 ( sizeof( * V_19 ) , V_76 ) ;
if ( V_19 == NULL ) {
* V_66 = L_10 ;
return NULL ;
}
* V_19 = ( (struct V_19 ) { . V_30 = F_54 ( V_19 -> V_30 ) ,
. V_45 =
F_54 ( V_19 -> V_45 ) ,
. line = line ,
. V_8 = 1 ,
. V_6 = 0 ,
. V_7 = 0 ,
. V_21 = 0 ,
. V_41 = 0 ,
. V_12 = - 1 ,
. V_22 = V_22 ,
. V_9 = V_9 } ) ;
return V_19 ;
}
int F_55 ( char * V_1 , struct line * line , int V_2 ,
const struct V_3 * V_4 , char * * V_66 )
{
struct V_26 * V_27 = & line -> V_55 ;
struct V_19 * V_77 ;
char * V_67 , * V_68 ;
if ( ! F_56 ( V_27 ) ) {
line -> V_61 = line -> V_63 = NULL ;
F_45 ( V_27 ) ;
F_57 ( V_27 ) ;
}
if ( ! V_1 )
return 0 ;
V_68 = strchr ( V_1 , ',' ) ;
if ( V_68 != NULL ) {
V_67 = V_1 ;
* V_68 = '\0' ;
V_68 ++ ;
V_77 = F_51 ( line , V_67 , V_2 , V_4 , V_66 ) ;
if ( V_77 == NULL )
return - 1 ;
V_77 -> V_6 = 1 ;
F_31 ( & V_77 -> V_30 , V_27 ) ;
line -> V_61 = V_77 ;
V_77 = F_51 ( line , V_68 , V_2 , V_4 , V_66 ) ;
if ( V_77 == NULL )
return - 1 ;
F_31 ( & V_77 -> V_30 , V_27 ) ;
V_77 -> V_7 = 1 ;
line -> V_63 = V_77 ;
}
else {
V_77 = F_51 ( line , V_1 , V_2 , V_4 , V_66 ) ;
if ( V_77 == NULL )
return - 1 ;
F_31 ( & V_77 -> V_30 , V_27 ) ;
V_77 -> V_6 = 1 ;
V_77 -> V_7 = 1 ;
line -> V_61 = line -> V_63 = V_77 ;
}
return 0 ;
}
void F_19 ( struct line * line , int V_48 )
{
struct V_31 * V_32 = & line -> V_32 ;
struct V_19 * V_19 = line -> V_61 ;
int V_20 ;
char V_78 ;
if ( ! V_19 || ! V_19 -> V_22 -> V_79 )
goto V_68;
do {
if ( ! F_58 ( V_32 , 1 ) ) {
F_59 ( & line -> V_36 , 1 ) ;
goto V_68;
}
V_20 = V_19 -> V_22 -> V_79 ( V_19 -> V_12 , & V_78 , V_19 -> V_9 ) ;
if ( V_20 > 0 )
F_60 ( V_32 , V_78 , V_80 ) ;
} while ( V_20 > 0 );
if ( V_20 == 0 )
F_36 ( V_19 -> V_12 , V_48 ) ;
if ( V_20 == - V_14 ) {
if ( V_19 -> V_8 ) {
F_61 ( & line -> V_32 , false ) ;
if ( line -> V_63 != V_19 )
F_30 ( line -> V_63 , 1 ) ;
}
F_30 ( V_19 , 1 ) ;
if ( V_19 -> V_8 )
return;
}
V_68:
F_62 ( V_32 ) ;
}
