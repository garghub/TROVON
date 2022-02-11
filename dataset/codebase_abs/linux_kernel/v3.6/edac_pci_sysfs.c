int F_1 ( void )
{
return V_1 ;
}
static int F_2 ( void )
{
return V_2 ;
}
static int F_3 ( void )
{
return V_3 ;
}
static int F_4 ( void )
{
return V_4 ;
}
int F_5 ( void )
{
return V_5 ;
}
static T_1 F_6 ( struct V_6 * V_7 , char * V_8 )
{
return sprintf ( V_8 , L_1 , F_7 ( & V_7 -> V_9 . V_10 ) ) ;
}
static T_1 F_8 ( struct V_6 * V_7 ,
char * V_8 )
{
return sprintf ( V_8 , L_1 , F_7 ( & V_7 -> V_9 . V_11 ) ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_6 * V_7 ;
F_10 ( 0 , L_2 ) ;
V_7 = F_11 ( V_13 ) ;
F_12 ( V_14 ) ;
F_13 ( V_7 ) ;
}
static T_1 F_14 ( struct V_12 * V_13 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_6 * V_7 = F_11 ( V_13 ) ;
struct V_18 * V_19 = F_15 ( V_16 ) ;
if ( V_19 -> V_20 )
return V_19 -> V_20 ( V_7 , V_17 ) ;
return - V_21 ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_22 )
{
struct V_6 * V_7 = F_11 ( V_13 ) ;
struct V_18 * V_19 = F_15 ( V_16 ) ;
if ( V_19 -> V_23 )
return V_19 -> V_23 ( V_7 , V_17 , V_22 ) ;
return - V_21 ;
}
static int F_17 ( struct V_6 * V_7 , int V_24 )
{
struct V_12 * V_25 ;
int V_26 ;
F_10 ( 0 , L_2 ) ;
V_25 = F_18 ( V_14 ) ;
if ( ! V_25 ) {
V_26 = - V_27 ;
goto V_28;
}
V_26 = F_19 ( & V_7 -> V_13 , & V_29 ,
V_14 , L_3 , V_24 ) ;
if ( V_26 != 0 ) {
F_10 ( 2 , L_4 , V_24 ) ;
F_12 ( V_14 ) ;
goto V_28;
}
F_20 ( & V_7 -> V_13 , V_30 ) ;
F_10 ( 1 , L_5 , V_24 ) ;
return 0 ;
V_28:
return V_26 ;
}
static void F_21 (
struct V_6 * V_7 )
{
F_10 ( 0 , L_2 ) ;
F_12 ( & V_7 -> V_13 ) ;
}
static T_1 F_22 ( void * V_31 , char * V_17 )
{
int * V_32 = V_31 ;
return sprintf ( V_17 , L_6 , * V_32 ) ;
}
static T_1 F_23 ( void * V_31 , const char * V_17 , T_2 V_22 )
{
int * V_32 = V_31 ;
if ( isdigit ( * V_17 ) )
* V_32 = F_24 ( V_17 , NULL , 0 ) ;
return V_22 ;
}
static T_1 F_25 ( struct V_12 * V_13 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_16 ;
if ( V_34 -> V_20 )
return V_34 -> V_20 ( V_34 -> V_32 , V_17 ) ;
return - V_21 ;
}
static T_1 F_26 ( struct V_12 * V_13 ,
struct V_15 * V_16 , const char * V_17 ,
T_2 V_22 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_16 ;
if ( V_34 -> V_20 )
return V_34 -> V_23 ( V_34 -> V_32 , V_17 , V_22 ) ;
return - V_21 ;
}
static void F_27 ( struct V_12 * V_13 )
{
F_10 ( 0 , L_7 ) ;
F_13 ( V_13 ) ;
F_28 ( V_35 ) ;
}
static int F_29 ( void )
{
int V_26 ;
struct V_36 * V_37 ;
F_10 ( 0 , L_2 ) ;
if ( F_30 ( & V_38 ) != 1 )
return 0 ;
V_37 = F_31 () ;
if ( V_37 == NULL ) {
F_10 ( 1 , L_8 ) ;
V_26 = - V_27 ;
goto V_39;
}
if ( ! F_32 ( V_35 ) ) {
F_10 ( 1 , L_9 ) ;
V_26 = - V_27 ;
goto V_40;
}
V_14 = F_33 ( sizeof( struct V_12 ) , V_41 ) ;
if ( ! V_14 ) {
F_10 ( 1 , L_10 ) ;
V_26 = - V_42 ;
goto V_43;
}
V_26 = F_19 ( V_14 ,
& V_44 ,
& V_37 -> V_45 -> V_13 , L_11 ) ;
if ( V_26 ) {
F_10 ( 1 , L_12 ) ;
goto V_46;
}
F_20 ( V_14 , V_30 ) ;
F_10 ( 1 , L_13 ) ;
return 0 ;
V_46:
F_13 ( V_14 ) ;
V_43:
F_28 ( V_35 ) ;
V_40:
F_34 () ;
V_39:
F_35 ( & V_38 ) ;
return V_26 ;
}
static void F_36 ( void )
{
F_10 ( 0 , L_2 ) ;
if ( F_37 ( & V_38 ) == 0 ) {
F_10 ( 0 , L_14 ) ;
F_12 ( V_14 ) ;
}
F_34 () ;
}
int F_38 ( struct V_6 * V_7 )
{
int V_26 ;
struct V_12 * V_47 = & V_7 -> V_13 ;
F_10 ( 0 , L_15 , V_7 -> V_48 ) ;
V_26 = F_29 () ;
if ( V_26 )
return V_26 ;
V_26 = F_17 ( V_7 , V_7 -> V_48 ) ;
if ( V_26 )
goto V_49;
V_26 = F_39 ( V_47 , & V_7 -> V_50 -> V_13 , V_51 ) ;
if ( V_26 ) {
F_10 ( 0 , L_16 , V_26 ) ;
goto V_52;
}
return 0 ;
V_52:
F_21 ( V_7 ) ;
V_49:
F_36 () ;
return V_26 ;
}
void F_40 ( struct V_6 * V_7 )
{
F_10 ( 0 , L_17 , V_7 -> V_48 ) ;
F_41 ( & V_7 -> V_13 , V_51 ) ;
F_21 ( V_7 ) ;
F_10 ( 0 , L_18 ) ;
F_36 () ;
}
static T_3 F_42 ( struct V_53 * V_50 , int V_54 )
{
int V_55 ;
T_3 V_56 ;
V_55 = V_54 ? V_57 : V_58 ;
F_43 ( V_50 , V_55 , & V_56 ) ;
if ( V_56 == 0xFFFF ) {
T_4 V_59 ;
F_44 ( V_50 , 0 , & V_59 ) ;
if ( V_59 == 0xFFFFFFFF )
return 0 ;
}
V_56 &= V_60 | V_61 |
V_62 ;
if ( V_56 )
F_45 ( V_50 , V_55 , V_56 ) ;
return V_56 ;
}
static void F_46 ( struct V_53 * V_50 )
{
T_5 V_63 ;
F_42 ( V_50 , 0 ) ;
F_47 ( V_50 , V_64 , & V_63 ) ;
if ( ( V_63 & 0x7F ) == V_65 )
F_42 ( V_50 , 1 ) ;
}
static void F_48 ( struct V_53 * V_50 )
{
unsigned long V_66 ;
T_3 V_56 ;
T_5 V_63 ;
F_49 ( V_66 ) ;
V_56 = F_42 ( V_50 , 0 ) ;
F_47 ( V_50 , V_64 , & V_63 ) ;
F_50 ( V_66 ) ;
F_10 ( 4 , L_19 , V_56 , F_51 ( & V_50 -> V_50 ) ) ;
if ( V_56 && ! V_50 -> V_67 ) {
if ( V_56 & ( V_61 ) ) {
F_52 ( V_68 , V_69 ,
L_20 ,
F_53 ( V_50 ) ) ;
F_54 ( & V_70 ) ;
}
if ( V_56 & ( V_62 ) ) {
F_52 ( V_68 , V_69 ,
L_21 ,
F_53 ( V_50 ) ) ;
F_54 ( & V_71 ) ;
}
if ( V_56 & ( V_60 ) ) {
F_52 ( V_68 , V_69 ,
L_22 ,
F_53 ( V_50 ) ) ;
F_54 ( & V_71 ) ;
}
}
F_10 ( 4 , L_23 ,
V_63 , F_51 ( & V_50 -> V_50 ) ) ;
if ( ( V_63 & 0x7F ) == V_65 ) {
V_56 = F_42 ( V_50 , 1 ) ;
F_10 ( 4 , L_24 ,
V_56 , F_51 ( & V_50 -> V_50 ) ) ;
if ( V_56 && ! V_50 -> V_67 ) {
if ( V_56 & ( V_61 ) ) {
F_52 ( V_68 , V_69 , L_25
L_20 ,
F_53 ( V_50 ) ) ;
F_54 ( & V_70 ) ;
}
if ( V_56 & ( V_62 ) ) {
F_52 ( V_68 , V_69 , L_25
L_26
L_27 , F_53 ( V_50 ) ) ;
F_54 ( & V_71 ) ;
}
if ( V_56 & ( V_60 ) ) {
F_52 ( V_68 , V_69 , L_25
L_22 ,
F_53 ( V_50 ) ) ;
F_54 ( & V_71 ) ;
}
}
}
}
static inline void F_55 ( T_6 V_72 )
{
struct V_53 * V_50 = NULL ;
while ( ( V_50 = F_56 ( V_73 , V_73 , V_50 ) ) != NULL ) {
V_72 ( V_50 ) ;
}
}
void F_57 ( void )
{
int V_74 ;
F_10 ( 3 , L_2 ) ;
if ( ! V_1 )
return;
V_74 = F_7 ( & V_71 ) ;
F_55 ( F_48 ) ;
if ( F_4 () ) {
if ( V_74 != F_7 ( & V_71 ) )
F_58 ( L_28 ) ;
}
}
void F_59 ( void )
{
F_55 ( F_46 ) ;
}
void F_60 ( struct V_6 * V_7 , const char * V_75 )
{
F_54 ( & V_7 -> V_9 . V_10 ) ;
if ( F_2 () )
F_61 ( V_7 , V_76 ,
L_29 ,
V_7 -> V_77 , V_7 -> V_48 , V_75 ) ;
F_57 () ;
}
void F_62 ( struct V_6 * V_7 , const char * V_75 )
{
F_54 ( & V_7 -> V_9 . V_11 ) ;
if ( F_3 () )
F_61 ( V_7 , V_76 ,
L_30 ,
V_7 -> V_77 , V_7 -> V_48 , V_75 ) ;
F_57 () ;
}
