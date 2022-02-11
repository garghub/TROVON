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
V_27 = F_22 ( V_29 , V_30 , V_31 ,
& V_32 , & V_33 , & V_34 ) ;
if ( V_27 && V_33 ) {
return atoi ( V_33 ) ;
}
F_16 ( V_32 ) ;
F_16 ( V_33 ) ;
F_16 ( V_34 ) ;
F_16 ( V_30 ) ;
return V_27 ;
}
static void
F_23 ( void )
{
T_1 * V_35 = NULL ;
int V_36 , V_37 , V_38 , V_39 ;
T_3 * V_40 = F_9 ( V_21 ) ;
T_3 * V_41 = F_9 ( V_5 ) ;
V_37 = F_24 ( V_40 ) ;
if ( V_37 < 0 )
return;
V_39 = F_13 ( V_9 -> V_23 , int , V_37 ) ;
V_38 = F_18 () ;
V_36 = F_20 ( V_9 -> V_42 , V_39 , V_38 ) ;
if ( V_36 ) {
V_35 = F_14 ( L_3 , F_25 ( abs ( V_36 ) ) ) ;
V_36 = F_20 ( V_9 -> V_42 , V_22 , V_6 ) ;
if ( V_36 ) {
F_8 ( V_40 , - 1 ) ;
F_8 ( V_41 , - 1 ) ;
V_22 = - 1 ;
V_6 = - 1 ;
}
else {
F_17 () ;
}
}
else {
V_35 = F_14 ( L_4 , V_9 -> V_42 , V_39 , F_15 ( V_39 ) ) ;
V_22 = V_39 ;
V_6 = V_38 ;
}
F_1 ( V_35 ) ;
F_16 ( V_35 ) ;
}
static void
F_26 ( T_4 * T_5 V_43 , T_6 V_32 V_43 )
{
if ( ! V_9 || V_26 )
return;
F_23 () ;
}
static void
F_27 ( T_4 * T_5 , T_6 V_32 V_43 )
{
unsigned int V_8 ;
int V_27 ;
struct V_44 * V_29 ;
struct V_45 V_46 ;
T_1 * V_47 ;
if ( V_48 )
return;
V_47 = F_19 ( F_6 ( T_5 ) ) ;
if ( ! V_47 || V_26 )
goto V_49;
for ( V_8 = 0 ; V_8 < V_50 -> V_24 ; V_8 ++ ) {
V_29 = F_13 ( V_50 , struct V_44 * , V_8 ) ;
if ( strcmp ( V_47 , V_29 -> V_42 ) == 0 ) {
V_9 = V_29 ;
break;
}
}
V_22 = - 1 ;
V_6 = - 1 ;
if ( V_9 ) {
V_27 = F_28 ( V_9 -> V_42 , & V_46 ) ;
if ( ! V_27 ) {
V_22 = V_46 . V_51 ;
V_6 = V_46 . V_52 ;
}
}
F_17 () ;
V_49:
F_16 ( V_47 ) ;
}
void
F_29 ( void )
{
struct V_44 * V_29 ;
unsigned int V_8 ;
T_7 V_53 = FALSE ;
T_1 * V_54 = NULL , * V_35 ;
if ( ! V_55 )
return;
if ( V_50 ) {
V_54 = F_19 ( F_6 ( V_56 ) ) ;
for ( V_8 = 0 ; V_8 < V_50 -> V_24 ; V_8 ++ )
F_11 ( F_6 ( V_56 ) , 0 ) ;
F_30 ( V_50 ) ;
V_50 = NULL ;
V_9 = NULL ;
}
V_50 = F_31 () ;
if ( ! V_50 ) {
goto V_49;
}
V_48 = TRUE ;
for ( V_8 = 0 ; V_8 < V_50 -> V_24 ; V_8 ++ ) {
V_29 = F_13 ( V_50 , struct V_44 * , V_8 ) ;
F_5 ( F_6 ( V_56 ) , V_29 -> V_42 ) ;
if ( V_54 && strcmp ( V_54 , V_29 -> V_42 ) == 0 ) {
F_8 ( F_9 ( V_56 ) , V_8 ) ;
V_9 = V_29 ;
V_53 = TRUE ;
}
}
V_48 = FALSE ;
if ( ! V_53 ) {
F_8 ( F_9 ( V_56 ) , - 1 ) ;
F_8 ( F_9 ( V_21 ) , - 1 ) ;
F_8 ( F_9 ( V_5 ) , - 1 ) ;
}
V_35 = F_14 ( L_5 , V_50 -> V_24 ) ;
F_1 ( V_35 ) ;
F_16 ( V_35 ) ;
V_49:
F_16 ( V_54 ) ;
}
static void
F_32 ( const T_1 * V_57 , T_4 * V_58 )
{
T_4 * V_59 ;
T_8 * V_60 ;
V_60 = F_33 () ;
F_34 ( F_35 ( V_60 ) ) ;
V_59 = F_36 ( V_57 ) ;
F_34 ( F_35 ( V_59 ) ) ;
F_37 ( F_38 ( V_60 ) , V_59 ) ;
F_39 ( F_40 ( V_58 ) , V_60 , - 1 ) ;
}
T_4 *
F_41 ( void )
{
T_8 * V_61 ;
int V_27 ;
V_55 = F_42 () ;
F_43 ( F_44 ( V_55 ) ,
V_62 ) ;
F_34 ( V_55 ) ;
F_32 ( L_6 , V_55 ) ;
V_61 = F_33 () ;
F_34 ( F_35 ( V_61 ) ) ;
V_56 = F_45 () ;
F_46 ( V_56 , L_7 , F_47 ( F_27 ) , NULL ) ;
F_37 ( F_38 ( V_61 ) , V_56 ) ;
F_34 ( F_35 ( V_56 ) ) ;
F_39 ( F_40 ( V_55 ) , V_61 , - 1 ) ;
F_32 ( L_8 , V_55 ) ;
V_61 = F_33 () ;
F_34 ( F_35 ( V_61 ) ) ;
V_21 = F_45 () ;
#ifdef F_48
F_46 ( V_21 , L_7 , F_47 ( F_26 ) , NULL ) ;
#else
F_49 ( F_35 ( V_21 ) , FALSE ) ;
#endif
F_37 ( F_38 ( V_61 ) , V_21 ) ;
F_34 ( F_35 ( V_21 ) ) ;
F_39 ( F_40 ( V_55 ) , V_61 , - 1 ) ;
V_61 = F_33 () ;
F_34 ( F_35 ( V_61 ) ) ;
V_5 = F_45 () ;
#ifdef F_48
F_46 ( V_5 , L_7 , F_47 ( F_26 ) , NULL ) ;
#else
F_49 ( F_35 ( V_21 ) , FALSE ) ;
#endif
F_37 ( F_38 ( V_61 ) , V_5 ) ;
F_34 ( F_35 ( V_5 ) ) ;
F_39 ( F_40 ( V_55 ) , V_61 , - 1 ) ;
V_61 = F_50 () ;
F_34 ( F_35 ( V_61 ) ) ;
F_39 ( F_40 ( V_55 ) , V_61 , - 1 ) ;
V_61 = F_33 () ;
F_34 ( F_35 ( V_61 ) ) ;
V_2 = F_36 ( L_9 ) ;
F_37 ( F_38 ( V_61 ) , V_2 ) ;
F_34 ( F_35 ( V_2 ) ) ;
F_39 ( F_40 ( V_55 ) , V_61 , - 1 ) ;
F_51 () ;
V_27 = F_52 () ;
if( V_27 ) {
F_1 ( L_10 ) ;
} else {
F_29 () ;
}
return V_55 ;
}
