static void F_1 ( const char * V_1 )
{
F_2 ( F_3 ( V_2 ) , V_1 ) ;
}
static
void F_4 ( const char * type , int V_3 , int V_4 )
{
F_5 ( F_6 ( V_5 ) , type ) ;
if ( V_3 != - 1 && V_3 == F_7 ( type ) ) {
F_8 ( F_9 ( V_5 ) , V_4 ) ;
V_6 = V_3 ;
}
}
static
void F_10 ( void )
{
static unsigned int V_7 ;
unsigned int V_8 ;
int V_3 = - 1 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
F_11 ( F_6 ( V_5 ) , 0 ) ;
}
if ( ! V_9 ) {
return;
}
V_3 = V_6 ;
V_6 = - 1 ;
V_8 = 0 ;
F_4 ( V_10 , V_3 , V_8 ++ ) ;
if ( V_9 -> V_11 & ( 1 << V_12 ) ) {
F_4 ( V_13 , V_3 , V_8 ++ ) ;
}
if ( V_9 -> V_11 & ( 1 << V_14 ) ) {
F_4 ( V_15 , V_3 , V_8 ++ ) ;
}
if ( V_9 -> V_11 & ( 1 << V_16 ) ) {
F_4 ( V_17 , V_3 , V_8 ++ ) ;
}
V_7 = V_8 ;
}
static
void F_12 ( void )
{
static unsigned int V_18 ;
unsigned int V_8 ;
T_1 * V_19 ;
T_2 V_20 = 0 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
F_11 ( F_6 ( V_21 ) , 0 ) ;
}
V_20 = V_22 ;
V_22 = - 1 ;
if ( ! V_9 )
return;
V_18 = V_9 -> V_23 -> V_24 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
int V_25 ;
V_25 = F_13 ( V_9 -> V_23 , int , V_8 ) ;
V_19 = F_14 ( L_1 , V_25 , F_15 ( V_25 ) ) ;
F_5 ( F_6 ( V_21 ) , V_19 ) ;
F_16 ( V_19 ) ;
if ( V_25 == V_20 ) {
F_8 ( F_9 ( V_21 ) , V_8 ) ;
V_22 = V_20 ;
}
}
}
static
void F_17 ( void )
{
V_26 = TRUE ;
F_12 () ;
F_10 () ;
V_26 = FALSE ;
}
static
int F_18 ( void )
{
int V_27 ;
T_1 * V_28 = F_19 ( F_6 ( V_5 ) ) ;
V_27 = F_7 ( V_28 ) ;
F_16 ( V_28 ) ;
return V_27 ;
}
static int
F_20 ( char * V_29 , int V_25 , int type )
{
T_1 * V_30 ;
const T_1 * V_31 ;
T_1 * V_32 , * V_33 , * V_34 ;
int V_27 ;
V_30 = F_14 ( L_2 , V_25 ) ;
V_31 = F_21 ( type ) ;
V_27 = F_22 ( V_29 , V_30 , V_31 , NULL , NULL ,
& V_32 , & V_33 , & V_34 , V_35 ) ;
if ( V_27 && V_33 ) {
F_23 ( V_33 , NULL , & V_27 ) ;
return V_27 ;
}
F_16 ( V_32 ) ;
F_16 ( V_33 ) ;
F_16 ( V_34 ) ;
F_16 ( V_30 ) ;
return V_27 ;
}
static void
F_24 ( void )
{
T_1 * V_36 = NULL ;
int V_37 , V_38 , V_39 , V_40 ;
T_3 * V_41 = F_9 ( V_21 ) ;
T_3 * V_42 = F_9 ( V_5 ) ;
V_38 = F_25 ( V_41 ) ;
if ( V_38 < 0 )
return;
V_40 = F_13 ( V_9 -> V_23 , int , V_38 ) ;
V_39 = F_18 () ;
V_37 = F_20 ( V_9 -> V_43 , V_40 , V_39 ) ;
if ( V_37 ) {
V_36 = F_14 ( L_3 , F_26 ( abs ( V_37 ) ) ) ;
V_37 = F_20 ( V_9 -> V_43 , V_22 , V_6 ) ;
if ( V_37 ) {
F_8 ( V_41 , - 1 ) ;
F_8 ( V_42 , - 1 ) ;
V_22 = - 1 ;
V_6 = - 1 ;
}
else {
F_17 () ;
}
}
else {
V_36 = F_14 ( L_4 , V_9 -> V_43 , V_40 , F_15 ( V_40 ) ) ;
V_22 = V_40 ;
V_6 = V_39 ;
}
F_1 ( V_36 ) ;
F_16 ( V_36 ) ;
}
static void
F_27 ( T_4 * T_5 V_44 , T_6 V_32 V_44 )
{
if ( ! V_9 || V_26 )
return;
F_24 () ;
}
static void
F_28 ( T_4 * T_5 , T_6 V_32 V_44 )
{
unsigned int V_8 ;
int V_27 ;
struct V_45 * V_29 ;
struct V_46 V_47 ;
T_1 * V_48 ;
if ( V_49 )
return;
V_48 = F_19 ( F_6 ( T_5 ) ) ;
if ( ! V_48 || V_26 )
goto V_50;
for ( V_8 = 0 ; V_8 < V_51 -> V_24 ; V_8 ++ ) {
V_29 = F_13 ( V_51 , struct V_45 * , V_8 ) ;
if ( strcmp ( V_48 , V_29 -> V_43 ) == 0 ) {
V_9 = V_29 ;
break;
}
}
V_22 = - 1 ;
V_6 = - 1 ;
if ( V_9 ) {
V_27 = F_29 ( V_9 -> V_43 , & V_47 ) ;
if ( ! V_27 ) {
V_22 = V_47 . V_52 ;
V_6 = V_47 . V_53 ;
}
}
F_17 () ;
V_50:
F_16 ( V_48 ) ;
}
void
F_30 ( void )
{
struct V_45 * V_29 ;
unsigned int V_8 ;
T_7 V_54 = FALSE ;
T_1 * V_55 = NULL , * V_36 ;
if ( ! V_56 )
return;
if ( V_51 ) {
V_55 = F_19 ( F_6 ( V_57 ) ) ;
for ( V_8 = 0 ; V_8 < V_51 -> V_24 ; V_8 ++ )
F_11 ( F_6 ( V_57 ) , 0 ) ;
F_31 ( V_51 ) ;
V_51 = NULL ;
V_9 = NULL ;
}
V_51 = F_32 () ;
if ( ! V_51 ) {
goto V_50;
}
V_49 = TRUE ;
for ( V_8 = 0 ; V_8 < V_51 -> V_24 ; V_8 ++ ) {
V_29 = F_13 ( V_51 , struct V_45 * , V_8 ) ;
F_5 ( F_6 ( V_57 ) , V_29 -> V_43 ) ;
if ( V_55 && strcmp ( V_55 , V_29 -> V_43 ) == 0 ) {
F_8 ( F_9 ( V_57 ) , V_8 ) ;
V_9 = V_29 ;
V_54 = TRUE ;
}
}
V_49 = FALSE ;
if ( ! V_54 ) {
F_8 ( F_9 ( V_57 ) , - 1 ) ;
F_8 ( F_9 ( V_21 ) , - 1 ) ;
F_8 ( F_9 ( V_5 ) , - 1 ) ;
}
V_36 = F_14 ( L_5 , V_51 -> V_24 ) ;
F_1 ( V_36 ) ;
F_16 ( V_36 ) ;
V_50:
F_16 ( V_55 ) ;
}
static void
F_33 ( const T_1 * V_58 , T_4 * V_59 )
{
T_4 * V_60 ;
T_8 * V_61 ;
V_61 = F_34 () ;
F_35 ( F_36 ( V_61 ) ) ;
V_60 = F_37 ( V_58 ) ;
F_35 ( F_36 ( V_60 ) ) ;
F_38 ( F_39 ( V_61 ) , V_60 ) ;
F_40 ( F_41 ( V_59 ) , V_61 , - 1 ) ;
}
T_4 *
F_42 ( void )
{
T_8 * V_62 ;
int V_27 ;
V_56 = F_43 () ;
F_44 ( F_45 ( V_56 ) ,
V_63 ) ;
F_35 ( V_56 ) ;
F_33 ( L_6 , V_56 ) ;
V_62 = F_34 () ;
F_35 ( F_36 ( V_62 ) ) ;
V_57 = F_46 () ;
F_47 ( V_57 , L_7 , F_48 ( F_28 ) , NULL ) ;
F_38 ( F_39 ( V_62 ) , V_57 ) ;
F_35 ( F_36 ( V_57 ) ) ;
F_40 ( F_41 ( V_56 ) , V_62 , - 1 ) ;
F_33 ( L_8 , V_56 ) ;
V_62 = F_34 () ;
F_35 ( F_36 ( V_62 ) ) ;
V_21 = F_46 () ;
#ifdef F_49
F_47 ( V_21 , L_7 , F_48 ( F_27 ) , NULL ) ;
#else
F_50 ( F_36 ( V_21 ) , FALSE ) ;
#endif
F_38 ( F_39 ( V_62 ) , V_21 ) ;
F_35 ( F_36 ( V_21 ) ) ;
F_40 ( F_41 ( V_56 ) , V_62 , - 1 ) ;
V_62 = F_34 () ;
F_35 ( F_36 ( V_62 ) ) ;
V_5 = F_46 () ;
#ifdef F_49
F_47 ( V_5 , L_7 , F_48 ( F_27 ) , NULL ) ;
#else
F_50 ( F_36 ( V_21 ) , FALSE ) ;
#endif
F_38 ( F_39 ( V_62 ) , V_5 ) ;
F_35 ( F_36 ( V_5 ) ) ;
F_40 ( F_41 ( V_56 ) , V_62 , - 1 ) ;
V_62 = F_51 () ;
F_35 ( F_36 ( V_62 ) ) ;
F_40 ( F_41 ( V_56 ) , V_62 , - 1 ) ;
V_62 = F_34 () ;
F_35 ( F_36 ( V_62 ) ) ;
V_2 = F_37 ( L_9 ) ;
F_38 ( F_39 ( V_62 ) , V_2 ) ;
F_35 ( F_36 ( V_2 ) ) ;
F_40 ( F_41 ( V_56 ) , V_62 , - 1 ) ;
F_52 () ;
V_27 = F_53 () ;
if( V_27 ) {
F_1 ( L_10 ) ;
} else {
F_30 () ;
}
return V_56 ;
}
