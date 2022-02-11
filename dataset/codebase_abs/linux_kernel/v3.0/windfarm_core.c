static inline void F_1 ( int V_1 , void * V_2 )
{
F_2 ( & V_3 , V_1 , V_2 ) ;
}
int F_3 ( void )
{
static char * V_4 = L_1 ;
char * V_5 [] = { V_4 , NULL } ;
static char * V_6 [] = { L_2 ,
L_3 ,
L_4 ,
NULL } ;
return F_4 ( V_4 ,
V_5 , V_6 , V_7 ) ;
}
static int F_5 ( void * V_8 )
{
unsigned long V_9 , V_10 ;
V_9 = V_11 ;
F_6 ( L_5 ) ;
F_7 () ;
while ( ! F_8 () ) {
F_9 () ;
if ( F_10 ( V_11 , V_9 ) ) {
F_1 ( V_12 , NULL ) ;
if ( V_13 ) {
V_14 ++ ;
if ( V_14 > 10 )
F_3 () ;
if ( V_14 > 30 ) {
F_11 ( V_15 L_6
L_7
L_8 ) ;
F_12 () ;
}
}
V_9 += V_16 ;
}
V_10 = V_9 - V_11 ;
if ( V_10 <= V_16 )
F_13 ( V_10 ) ;
}
F_6 ( L_9 ) ;
return 0 ;
}
static void F_14 ( void )
{
V_17 = F_15 ( F_5 , NULL , L_10 ) ;
if ( F_16 ( V_17 ) ) {
F_11 ( V_15 L_11 ,
F_17 ( V_17 ) ) ;
V_17 = NULL ;
}
}
static void F_18 ( void )
{
if ( V_17 )
F_19 ( V_17 ) ;
V_17 = NULL ;
}
static void F_20 ( struct V_18 * V_18 )
{
struct V_19 * V_20 = F_21 ( V_18 , struct V_19 , V_21 ) ;
F_6 ( L_12 , V_20 -> V_22 ) ;
if ( V_20 -> V_23 && V_20 -> V_23 -> V_24 )
V_20 -> V_23 -> V_24 ( V_20 ) ;
else
F_22 ( V_20 ) ;
}
static T_1 F_23 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_19 * V_30 = F_21 ( V_28 , struct V_19 , V_28 ) ;
T_2 V_31 = 0 ;
int V_32 ;
V_32 = V_30 -> V_23 -> V_33 ( V_30 , & V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
return sprintf ( V_29 , L_13 , V_31 ) ;
}
static T_1 F_24 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_34 )
{
struct V_19 * V_30 = F_21 ( V_28 , struct V_19 , V_28 ) ;
int V_31 ;
int V_32 ;
char * V_35 ;
V_31 = F_25 ( V_29 , & V_35 , 0 ) ;
while ( V_35 < V_29 + V_34 && ( * V_35 == ' ' || * V_35 == '\n' ) )
++ V_35 ;
if ( V_35 - V_29 < V_34 )
return - V_36 ;
V_32 = V_30 -> V_23 -> V_37 ( V_30 , V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
return V_34 ;
}
int F_26 ( struct V_19 * V_38 )
{
struct V_19 * V_20 ;
F_27 ( & V_39 ) ;
F_28 (ct, &wf_controls, link) {
if ( ! strcmp ( V_20 -> V_22 , V_38 -> V_22 ) ) {
F_11 ( V_40 L_14
L_15 , V_20 -> V_22 ) ;
F_29 ( & V_39 ) ;
return - V_41 ;
}
}
F_30 ( & V_38 -> V_21 ) ;
F_31 ( & V_38 -> V_42 , & V_43 ) ;
F_32 ( & V_38 -> V_28 . V_28 ) ;
V_38 -> V_28 . V_28 . V_22 = V_38 -> V_22 ;
V_38 -> V_28 . V_28 . V_44 = 0644 ;
V_38 -> V_28 . V_45 = F_23 ;
V_38 -> V_28 . V_46 = F_24 ;
if ( F_33 ( & V_47 . V_26 , & V_38 -> V_28 ) )
F_11 ( V_40 L_16
L_17 , V_38 -> V_22 ) ;
F_6 ( L_18 , V_38 -> V_22 ) ;
F_1 ( V_48 , V_38 ) ;
F_29 ( & V_39 ) ;
return 0 ;
}
void F_34 ( struct V_19 * V_20 )
{
F_27 ( & V_39 ) ;
F_35 ( & V_20 -> V_42 ) ;
F_29 ( & V_39 ) ;
F_6 ( L_19 , V_20 -> V_22 ) ;
F_36 ( & V_20 -> V_21 , F_20 ) ;
}
struct V_19 * F_37 ( const char * V_22 )
{
struct V_19 * V_20 ;
F_27 ( & V_39 ) ;
F_28 (ct, &wf_controls, link) {
if ( ! strcmp ( V_20 -> V_22 , V_22 ) ) {
if ( F_38 ( V_20 ) )
V_20 = NULL ;
F_29 ( & V_39 ) ;
return V_20 ;
}
}
F_29 ( & V_39 ) ;
return NULL ;
}
int F_38 ( struct V_19 * V_20 )
{
if ( ! F_39 ( V_20 -> V_23 -> V_49 ) )
return - V_50 ;
F_40 ( & V_20 -> V_21 ) ;
return 0 ;
}
void F_41 ( struct V_19 * V_20 )
{
struct V_51 * V_52 = V_20 -> V_23 -> V_49 ;
F_36 ( & V_20 -> V_21 , F_20 ) ;
F_42 ( V_52 ) ;
}
static void F_43 ( struct V_18 * V_18 )
{
struct V_53 * V_54 = F_21 ( V_18 , struct V_53 , V_21 ) ;
F_6 ( L_20 , V_54 -> V_22 ) ;
if ( V_54 -> V_23 && V_54 -> V_23 -> V_24 )
V_54 -> V_23 -> V_24 ( V_54 ) ;
else
F_22 ( V_54 ) ;
}
static T_1 F_44 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_53 * V_55 = F_21 ( V_28 , struct V_53 , V_28 ) ;
T_2 V_31 = 0 ;
int V_32 ;
V_32 = V_55 -> V_23 -> V_33 ( V_55 , & V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
return sprintf ( V_29 , L_21 , F_45 ( V_31 ) ) ;
}
int F_46 ( struct V_53 * V_56 )
{
struct V_53 * V_54 ;
F_27 ( & V_39 ) ;
F_28 (sr, &wf_sensors, link) {
if ( ! strcmp ( V_54 -> V_22 , V_56 -> V_22 ) ) {
F_11 ( V_40 L_14
L_22 , V_54 -> V_22 ) ;
F_29 ( & V_39 ) ;
return - V_41 ;
}
}
F_30 ( & V_56 -> V_21 ) ;
F_31 ( & V_56 -> V_42 , & V_57 ) ;
F_32 ( & V_56 -> V_28 . V_28 ) ;
V_56 -> V_28 . V_28 . V_22 = V_56 -> V_22 ;
V_56 -> V_28 . V_28 . V_44 = 0444 ;
V_56 -> V_28 . V_45 = F_44 ;
V_56 -> V_28 . V_46 = NULL ;
if ( F_33 ( & V_47 . V_26 , & V_56 -> V_28 ) )
F_11 ( V_40 L_16
L_17 , V_56 -> V_22 ) ;
F_6 ( L_23 , V_56 -> V_22 ) ;
F_1 ( V_58 , V_56 ) ;
F_29 ( & V_39 ) ;
return 0 ;
}
void F_47 ( struct V_53 * V_54 )
{
F_27 ( & V_39 ) ;
F_35 ( & V_54 -> V_42 ) ;
F_29 ( & V_39 ) ;
F_6 ( L_24 , V_54 -> V_22 ) ;
F_48 ( V_54 ) ;
}
struct V_53 * F_49 ( const char * V_22 )
{
struct V_53 * V_54 ;
F_27 ( & V_39 ) ;
F_28 (sr, &wf_sensors, link) {
if ( ! strcmp ( V_54 -> V_22 , V_22 ) ) {
if ( F_50 ( V_54 ) )
V_54 = NULL ;
F_29 ( & V_39 ) ;
return V_54 ;
}
}
F_29 ( & V_39 ) ;
return NULL ;
}
int F_50 ( struct V_53 * V_54 )
{
if ( ! F_39 ( V_54 -> V_23 -> V_49 ) )
return - V_50 ;
F_40 ( & V_54 -> V_21 ) ;
return 0 ;
}
void F_48 ( struct V_53 * V_54 )
{
struct V_51 * V_52 = V_54 -> V_23 -> V_49 ;
F_36 ( & V_54 -> V_21 , F_43 ) ;
F_42 ( V_52 ) ;
}
int F_51 ( struct V_59 * V_60 )
{
int V_61 ;
struct V_19 * V_20 ;
struct V_53 * V_54 ;
F_27 ( & V_39 ) ;
V_61 = F_52 ( & V_3 , V_60 ) ;
if ( V_61 != 0 )
goto V_62;
V_63 ++ ;
F_28 (ct, &wf_controls, link)
F_1 ( V_48 , V_20 ) ;
F_28 (sr, &wf_sensors, link)
F_1 ( V_58 , V_54 ) ;
if ( V_63 == 1 )
F_14 () ;
V_62:
F_29 ( & V_39 ) ;
return V_61 ;
}
int F_53 ( struct V_59 * V_60 )
{
F_27 ( & V_39 ) ;
F_54 ( & V_3 , V_60 ) ;
V_63 ++ ;
if ( V_63 == 0 )
F_18 () ;
F_29 ( & V_39 ) ;
return 0 ;
}
void F_55 ( void )
{
F_27 ( & V_39 ) ;
V_13 ++ ;
if ( V_13 == 1 ) {
F_11 ( V_40 L_25 ) ;
V_14 = 0 ;
F_1 ( V_64 , NULL ) ;
}
F_29 ( & V_39 ) ;
}
void F_56 ( void )
{
F_27 ( & V_39 ) ;
F_57 ( V_13 == 0 ) ;
if ( V_13 == 0 ) {
F_29 ( & V_39 ) ;
return;
}
V_13 -- ;
if ( V_13 == 0 ) {
F_11 ( V_40 L_26 ) ;
F_1 ( V_65 , NULL ) ;
}
F_29 ( & V_39 ) ;
}
int F_58 ( void )
{
return ( V_13 != 0 ) ;
}
static int T_4 F_59 ( void )
{
F_6 ( L_27 ) ;
if ( F_60 ( L_28 ) ||
F_60 ( L_29 ) ||
F_60 ( L_30 ) )
return - V_50 ;
F_61 ( & V_47 ) ;
return 0 ;
}
static void T_5 F_62 ( void )
{
F_63 ( V_63 != 0 ) ;
F_6 ( L_31 ) ;
F_64 ( & V_47 ) ;
}
