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
F_10 ( L_2 , V_14 ) ;
V_7 = F_11 ( V_13 ) ;
F_12 ( V_15 ) ;
F_13 ( V_7 ) ;
}
static T_1 F_14 ( struct V_12 * V_13 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_11 ( V_13 ) ;
struct V_19 * V_20 = F_15 ( V_17 ) ;
if ( V_20 -> V_21 )
return V_20 -> V_21 ( V_7 , V_18 ) ;
return - V_22 ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
const char * V_18 , T_2 V_23 )
{
struct V_6 * V_7 = F_11 ( V_13 ) ;
struct V_19 * V_20 = F_15 ( V_17 ) ;
if ( V_20 -> V_24 )
return V_20 -> V_24 ( V_7 , V_18 , V_23 ) ;
return - V_22 ;
}
static int F_17 ( struct V_6 * V_7 , int V_25 )
{
struct V_12 * V_26 ;
int V_27 ;
F_10 ( L_2 , V_14 ) ;
V_26 = F_18 ( V_15 ) ;
if ( ! V_26 ) {
V_27 = - V_28 ;
goto V_29;
}
V_27 = F_19 ( & V_7 -> V_13 , & V_30 ,
V_15 , L_3 , V_25 ) ;
if ( V_27 != 0 ) {
F_20 ( L_4 ,
V_14 , V_25 ) ;
F_12 ( V_15 ) ;
goto V_29;
}
F_21 ( & V_7 -> V_13 , V_31 ) ;
F_22 ( L_5 , V_14 , V_25 ) ;
return 0 ;
V_29:
return V_27 ;
}
static void F_23 (
struct V_6 * V_7 )
{
F_10 ( L_2 , V_14 ) ;
F_12 ( & V_7 -> V_13 ) ;
}
static T_1 F_24 ( void * V_32 , char * V_18 )
{
int * V_33 = V_32 ;
return sprintf ( V_18 , L_6 , * V_33 ) ;
}
static T_1 F_25 ( void * V_32 , const char * V_18 , T_2 V_23 )
{
int * V_33 = V_32 ;
if ( isdigit ( * V_18 ) )
* V_33 = F_26 ( V_18 , NULL , 0 ) ;
return V_23 ;
}
static T_1 F_27 ( struct V_12 * V_13 , struct V_16 * V_17 ,
char * V_18 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_17 ;
if ( V_35 -> V_21 )
return V_35 -> V_21 ( V_35 -> V_33 , V_18 ) ;
return - V_22 ;
}
static T_1 F_28 ( struct V_12 * V_13 ,
struct V_16 * V_17 , const char * V_18 ,
T_2 V_23 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_17 ;
if ( V_35 -> V_21 )
return V_35 -> V_24 ( V_35 -> V_33 , V_18 , V_23 ) ;
return - V_22 ;
}
static void F_29 ( struct V_12 * V_13 )
{
F_10 ( L_7 , V_14 ) ;
F_13 ( V_13 ) ;
F_30 ( V_36 ) ;
}
static int F_31 ( void )
{
int V_27 ;
struct V_37 * V_38 ;
F_10 ( L_2 , V_14 ) ;
if ( F_32 ( & V_39 ) != 1 )
return 0 ;
V_38 = F_33 () ;
if ( V_38 == NULL ) {
F_22 ( L_8 , V_14 ) ;
V_27 = - V_28 ;
goto V_40;
}
if ( ! F_34 ( V_36 ) ) {
F_22 ( L_9 , V_14 ) ;
V_27 = - V_28 ;
goto V_41;
}
V_15 = F_35 ( sizeof( struct V_12 ) , V_42 ) ;
if ( ! V_15 ) {
F_22 ( L_10 ) ;
V_27 = - V_43 ;
goto V_44;
}
V_27 = F_19 ( V_15 ,
& V_45 ,
& V_38 -> V_46 -> V_13 , L_11 ) ;
if ( V_27 ) {
F_22 ( L_12 ) ;
goto V_47;
}
F_21 ( V_15 , V_31 ) ;
F_22 ( L_13 ) ;
return 0 ;
V_47:
F_13 ( V_15 ) ;
V_44:
F_30 ( V_36 ) ;
V_41:
F_36 () ;
V_40:
F_37 ( & V_39 ) ;
return V_27 ;
}
static void F_38 ( void )
{
F_10 ( L_2 , V_14 ) ;
if ( F_39 ( & V_39 ) == 0 ) {
F_10 ( L_14 ,
V_14 ) ;
F_12 ( V_15 ) ;
}
F_36 () ;
}
int F_40 ( struct V_6 * V_7 )
{
int V_27 ;
struct V_12 * V_48 = & V_7 -> V_13 ;
F_10 ( L_15 , V_14 , V_7 -> V_49 ) ;
V_27 = F_31 () ;
if ( V_27 )
return V_27 ;
V_27 = F_17 ( V_7 , V_7 -> V_49 ) ;
if ( V_27 )
goto V_50;
V_27 = F_41 ( V_48 , & V_7 -> V_51 -> V_13 , V_52 ) ;
if ( V_27 ) {
F_10 ( L_16 ,
V_14 , V_27 ) ;
goto V_53;
}
return 0 ;
V_53:
F_23 ( V_7 ) ;
V_50:
F_38 () ;
return V_27 ;
}
void F_42 ( struct V_6 * V_7 )
{
F_10 ( L_17 , V_14 , V_7 -> V_49 ) ;
F_43 ( & V_7 -> V_13 , V_52 ) ;
F_23 ( V_7 ) ;
F_10 ( L_18 , V_14 ) ;
F_38 () ;
}
static T_3 F_44 ( struct V_54 * V_51 , int V_55 )
{
int V_56 ;
T_3 V_57 ;
V_56 = V_55 ? V_58 : V_59 ;
F_45 ( V_51 , V_56 , & V_57 ) ;
if ( V_57 == 0xFFFF ) {
T_4 V_60 ;
F_46 ( V_51 , 0 , & V_60 ) ;
if ( V_60 == 0xFFFFFFFF )
return 0 ;
}
V_57 &= V_61 | V_62 |
V_63 ;
if ( V_57 )
F_47 ( V_51 , V_56 , V_57 ) ;
return V_57 ;
}
static void F_48 ( struct V_54 * V_51 )
{
T_5 V_64 ;
F_44 ( V_51 , 0 ) ;
F_49 ( V_51 , V_65 , & V_64 ) ;
if ( ( V_64 & 0x7F ) == V_66 )
F_44 ( V_51 , 1 ) ;
}
static void F_50 ( struct V_54 * V_51 )
{
unsigned long V_67 ;
T_3 V_57 ;
T_5 V_64 ;
F_51 ( V_67 ) ;
V_57 = F_44 ( V_51 , 0 ) ;
F_49 ( V_51 , V_65 , & V_64 ) ;
F_52 ( V_67 ) ;
F_53 ( L_19 , V_57 , F_54 ( & V_51 -> V_51 ) ) ;
if ( V_57 && ! V_51 -> V_68 ) {
if ( V_57 & ( V_62 ) ) {
F_55 ( V_69 , V_70 ,
L_20 ,
F_56 ( V_51 ) ) ;
F_57 ( & V_71 ) ;
}
if ( V_57 & ( V_63 ) ) {
F_55 ( V_69 , V_70 ,
L_21 ,
F_56 ( V_51 ) ) ;
F_57 ( & V_72 ) ;
}
if ( V_57 & ( V_61 ) ) {
F_55 ( V_69 , V_70 ,
L_22 ,
F_56 ( V_51 ) ) ;
F_57 ( & V_72 ) ;
}
}
F_53 ( L_23 , V_64 , F_54 ( & V_51 -> V_51 ) ) ;
if ( ( V_64 & 0x7F ) == V_66 ) {
V_57 = F_44 ( V_51 , 1 ) ;
F_53 ( L_24 , V_57 , F_54 ( & V_51 -> V_51 ) ) ;
if ( V_57 && ! V_51 -> V_68 ) {
if ( V_57 & ( V_62 ) ) {
F_55 ( V_69 , V_70 , L_25
L_20 ,
F_56 ( V_51 ) ) ;
F_57 ( & V_71 ) ;
}
if ( V_57 & ( V_63 ) ) {
F_55 ( V_69 , V_70 , L_25
L_26
L_27 , F_56 ( V_51 ) ) ;
F_57 ( & V_72 ) ;
}
if ( V_57 & ( V_61 ) ) {
F_55 ( V_69 , V_70 , L_25
L_22 ,
F_56 ( V_51 ) ) ;
F_57 ( & V_72 ) ;
}
}
}
}
static inline void F_58 ( T_6 V_73 )
{
struct V_54 * V_51 = NULL ;
while ( ( V_51 = F_59 ( V_74 , V_74 , V_51 ) ) != NULL ) {
V_73 ( V_51 ) ;
}
}
void F_60 ( void )
{
int V_75 ;
F_61 ( L_2 , V_14 ) ;
if ( ! V_1 )
return;
V_75 = F_7 ( & V_72 ) ;
F_58 ( F_50 ) ;
if ( F_4 () ) {
if ( V_75 != F_7 ( & V_72 ) )
F_62 ( L_28 ) ;
}
}
void F_63 ( void )
{
F_58 ( F_48 ) ;
}
void F_64 ( struct V_6 * V_7 , const char * V_76 )
{
F_57 ( & V_7 -> V_9 . V_10 ) ;
if ( F_2 () )
F_65 ( V_7 , V_77 ,
L_29 ,
V_7 -> V_78 , V_7 -> V_49 , V_76 ) ;
F_60 () ;
}
void F_66 ( struct V_6 * V_7 , const char * V_76 )
{
F_57 ( & V_7 -> V_9 . V_11 ) ;
if ( F_3 () )
F_65 ( V_7 , V_77 ,
L_30 ,
V_7 -> V_78 , V_7 -> V_49 , V_76 ) ;
F_60 () ;
}
