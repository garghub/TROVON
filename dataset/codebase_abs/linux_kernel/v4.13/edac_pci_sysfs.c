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
if ( V_34 -> V_23 )
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
if ( ! F_32 ( V_35 ) ) {
F_10 ( 1 , L_8 ) ;
V_26 = - V_27 ;
goto V_39;
}
V_14 = F_33 ( sizeof( struct V_12 ) , V_40 ) ;
if ( ! V_14 ) {
F_10 ( 1 , L_9 ) ;
V_26 = - V_41 ;
goto V_42;
}
V_26 = F_19 ( V_14 ,
& V_43 ,
& V_37 -> V_44 -> V_13 , L_10 ) ;
if ( V_26 ) {
F_10 ( 1 , L_11 ) ;
goto V_45;
}
F_20 ( V_14 , V_30 ) ;
F_10 ( 1 , L_12 ) ;
return 0 ;
V_45:
F_13 ( V_14 ) ;
V_42:
F_28 ( V_35 ) ;
V_39:
F_34 ( & V_38 ) ;
return V_26 ;
}
static void F_35 ( void )
{
F_10 ( 0 , L_2 ) ;
if ( F_36 ( & V_38 ) == 0 ) {
F_10 ( 0 , L_13 ) ;
F_12 ( V_14 ) ;
}
}
int F_37 ( struct V_6 * V_7 )
{
int V_26 ;
struct V_12 * V_46 = & V_7 -> V_13 ;
F_10 ( 0 , L_14 , V_7 -> V_47 ) ;
V_26 = F_29 () ;
if ( V_26 )
return V_26 ;
V_26 = F_17 ( V_7 , V_7 -> V_47 ) ;
if ( V_26 )
goto V_48;
V_26 = F_38 ( V_46 , & V_7 -> V_49 -> V_13 , V_50 ) ;
if ( V_26 ) {
F_10 ( 0 , L_15 , V_26 ) ;
goto V_51;
}
return 0 ;
V_51:
F_21 ( V_7 ) ;
V_48:
F_35 () ;
return V_26 ;
}
void F_39 ( struct V_6 * V_7 )
{
F_10 ( 0 , L_16 , V_7 -> V_47 ) ;
F_40 ( & V_7 -> V_13 , V_50 ) ;
F_21 ( V_7 ) ;
F_10 ( 0 , L_17 ) ;
F_35 () ;
}
static T_3 F_41 ( struct V_52 * V_49 , int V_53 )
{
int V_54 ;
T_3 V_55 ;
V_54 = V_53 ? V_56 : V_57 ;
F_42 ( V_49 , V_54 , & V_55 ) ;
if ( V_55 == 0xFFFF ) {
T_4 V_58 ;
F_43 ( V_49 , 0 , & V_58 ) ;
if ( V_58 == 0xFFFFFFFF )
return 0 ;
}
V_55 &= V_59 | V_60 |
V_61 ;
if ( V_55 )
F_44 ( V_49 , V_54 , V_55 ) ;
return V_55 ;
}
static void F_45 ( struct V_52 * V_49 )
{
T_5 V_62 ;
F_41 ( V_49 , 0 ) ;
F_46 ( V_49 , V_63 , & V_62 ) ;
if ( ( V_62 & 0x7F ) == V_64 )
F_41 ( V_49 , 1 ) ;
}
static void F_47 ( struct V_52 * V_49 )
{
unsigned long V_65 ;
T_3 V_55 ;
T_5 V_62 ;
F_48 ( V_65 ) ;
V_55 = F_41 ( V_49 , 0 ) ;
F_46 ( V_49 , V_63 , & V_62 ) ;
F_49 ( V_65 ) ;
F_10 ( 4 , L_18 , V_55 , F_50 ( & V_49 -> V_49 ) ) ;
if ( V_55 && ! V_49 -> V_66 ) {
if ( V_55 & ( V_60 ) ) {
F_51 ( V_67 , V_68 ,
L_19 ,
F_52 ( V_49 ) ) ;
F_53 ( & V_69 ) ;
}
if ( V_55 & ( V_61 ) ) {
F_51 ( V_67 , V_68 ,
L_20 ,
F_52 ( V_49 ) ) ;
F_53 ( & V_70 ) ;
}
if ( V_55 & ( V_59 ) ) {
F_51 ( V_67 , V_68 ,
L_21 ,
F_52 ( V_49 ) ) ;
F_53 ( & V_70 ) ;
}
}
F_10 ( 4 , L_22 ,
V_62 , F_50 ( & V_49 -> V_49 ) ) ;
if ( ( V_62 & 0x7F ) == V_64 ) {
V_55 = F_41 ( V_49 , 1 ) ;
F_10 ( 4 , L_23 ,
V_55 , F_50 ( & V_49 -> V_49 ) ) ;
if ( V_55 && ! V_49 -> V_66 ) {
if ( V_55 & ( V_60 ) ) {
F_51 ( V_67 , V_68 , L_24
L_19 ,
F_52 ( V_49 ) ) ;
F_53 ( & V_69 ) ;
}
if ( V_55 & ( V_61 ) ) {
F_51 ( V_67 , V_68 , L_24
L_25
L_26 , F_52 ( V_49 ) ) ;
F_53 ( & V_70 ) ;
}
if ( V_55 & ( V_59 ) ) {
F_51 ( V_67 , V_68 , L_24
L_21 ,
F_52 ( V_49 ) ) ;
F_53 ( & V_70 ) ;
}
}
}
}
static inline void F_54 ( T_6 V_71 )
{
struct V_52 * V_49 = NULL ;
F_55 (dev)
V_71 ( V_49 ) ;
}
void F_56 ( void )
{
int V_72 ;
F_10 ( 3 , L_2 ) ;
if ( ! V_1 )
return;
V_72 = F_7 ( & V_70 ) ;
F_54 ( F_47 ) ;
if ( F_4 () ) {
if ( V_72 != F_7 ( & V_70 ) )
F_57 ( L_27 ) ;
}
}
void F_58 ( void )
{
F_54 ( F_45 ) ;
}
void F_59 ( struct V_6 * V_7 , const char * V_73 )
{
F_53 ( & V_7 -> V_9 . V_10 ) ;
if ( F_2 () )
F_60 ( V_7 , V_74 ,
L_28 ,
V_7 -> V_75 , V_7 -> V_47 , V_73 ) ;
F_56 () ;
}
void F_61 ( struct V_6 * V_7 , const char * V_73 )
{
F_53 ( & V_7 -> V_9 . V_11 ) ;
if ( F_3 () )
F_60 ( V_7 , V_74 ,
L_29 ,
V_7 -> V_75 , V_7 -> V_47 , V_73 ) ;
F_56 () ;
}
