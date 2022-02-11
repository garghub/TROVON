static unsigned int F_1 ( unsigned int V_1 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static T_1 F_4 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_2 () ;
F_3 () ;
}
static void F_6 ( int V_6 , int V_7 , struct V_8 * V_9 [] )
{
F_2 () ;
F_3 () ;
}
static unsigned long F_7 ( unsigned long V_10 ,
struct V_11 * V_11 ,
struct V_12 * V_13 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , T_2 V_16 ,
const enum V_17 V_18 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_10 ( T_3 * V_21 , struct V_22 * V_22 ,
struct V_23 * V_24 , unsigned int V_20 ,
unsigned long V_25 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static struct V_26 * F_11 ( const char * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < F_12 ( V_29 ) ; V_28 ++ ) {
if ( ! strcmp ( V_27 , V_29 [ V_28 ] . V_27 ) )
return & V_29 [ V_28 ] ;
}
return NULL ;
}
static T_4 void F_13 ( struct V_26 * V_26 )
{
F_14 ( ! V_26 || ! V_26 -> V_30 ) ;
V_26 -> V_30 () ;
}
static int F_15 ( struct V_31 * V_31 ,
struct V_26 * V_26 )
{
int V_32 ;
if ( ! V_31 -> V_33 . V_34 . V_35 ) {
F_13 ( V_26 ) ;
return 0 ;
}
if ( V_36 != NULL )
F_16 ( V_36 ) ;
V_37 = V_31 ;
V_38 = V_26 ;
V_36 = & V_31 -> V_33 ;
V_32 = F_17 ( V_36 ) ;
if ( V_32 < 0 ) {
F_18 ( L_1 ,
V_31 -> V_33 . V_34 . V_35 ) ;
V_36 = NULL ;
V_37 = NULL ;
V_38 = NULL ;
}
return V_32 ;
}
static void F_2 ( void )
{
unsigned long V_39 ;
bool V_40 = false ;
F_14 ( ! V_37 || ! V_38 ) ;
F_19 ( & V_41 , V_39 ) ;
V_42 -- ;
F_18 ( L_2 ,
V_37 -> V_27 , V_38 -> V_27 , V_42 ) ;
if ( V_42 == 0 ) {
V_40 = true ;
V_42 = V_43 ;
}
F_20 ( & V_41 , V_39 ) ;
if ( V_40 )
F_13 ( V_38 ) ;
}
static T_5 F_21 ( struct V_22 * V_44 ,
const char T_6 * V_45 ,
T_7 V_46 , T_8 * V_47 )
{
struct V_31 * V_31 = F_22 ( V_44 ) -> V_48 ;
struct V_26 * V_26 = NULL ;
char * V_49 ;
int V_50 ;
if ( V_46 >= V_51 )
return - V_52 ;
V_49 = ( char * ) F_23 ( V_53 ) ;
if ( ! V_49 )
return - V_54 ;
if ( F_24 ( V_49 , V_45 , V_46 ) ) {
F_25 ( ( unsigned long ) V_49 ) ;
return - V_55 ;
}
V_49 [ V_46 ] = '\0' ;
F_26 ( V_49 ) ;
V_26 = F_11 ( V_49 ) ;
F_25 ( ( unsigned long ) V_49 ) ;
if ( ! V_26 )
return - V_52 ;
V_50 = F_15 ( V_31 , V_26 ) ;
if ( V_50 < 0 )
return V_50 ;
* V_47 += V_46 ;
return V_46 ;
}
static T_5 F_27 ( struct V_22 * V_44 , char T_6 * V_45 ,
T_7 V_46 , T_8 * V_47 )
{
char * V_49 ;
int V_28 , V_56 , V_57 ;
V_49 = ( char * ) F_23 ( V_53 ) ;
if ( V_49 == NULL )
return - V_54 ;
V_56 = snprintf ( V_49 , V_51 , L_3 ) ;
for ( V_28 = 0 ; V_28 < F_12 ( V_29 ) ; V_28 ++ ) {
V_56 += snprintf ( V_49 + V_56 , V_51 - V_56 , L_4 ,
V_29 [ V_28 ] . V_27 ) ;
}
V_49 [ V_56 ] = '\0' ;
V_57 = F_28 ( V_45 , V_46 , V_47 ,
V_49 , V_56 ) ;
F_25 ( ( unsigned long ) V_49 ) ;
return V_57 ;
}
static int F_29 ( struct V_58 * V_58 , struct V_22 * V_22 )
{
return 0 ;
}
static T_5 F_30 ( struct V_22 * V_44 , const char T_6 * V_45 ,
T_7 V_46 , T_8 * V_47 )
{
struct V_26 * V_26 ;
char * V_49 ;
if ( V_46 >= V_51 )
return - V_52 ;
if ( V_46 < 1 )
return - V_52 ;
V_49 = ( char * ) F_23 ( V_53 ) ;
if ( ! V_49 )
return - V_54 ;
if ( F_24 ( V_49 , V_45 , V_46 ) ) {
F_25 ( ( unsigned long ) V_49 ) ;
return - V_55 ;
}
V_49 [ V_46 ] = '\0' ;
F_26 ( V_49 ) ;
V_26 = F_11 ( V_49 ) ;
F_25 ( ( unsigned long ) V_49 ) ;
if ( ! V_26 )
return - V_52 ;
F_18 ( L_5 , V_26 -> V_27 ) ;
F_13 ( V_26 ) ;
* V_47 += V_46 ;
return V_46 ;
}
static int T_9 F_31 ( void )
{
struct V_31 * V_31 = NULL ;
struct V_26 * V_26 = NULL ;
int V_32 = - V_52 ;
int V_28 ;
if ( ( V_59 || V_60 ) && ! ( V_59 && V_60 ) ) {
F_32 ( L_6 ) ;
return - V_52 ;
}
if ( V_59 ) {
V_26 = F_11 ( V_59 ) ;
if ( ! V_26 ) {
F_32 ( L_7 , V_59 ) ;
return - V_52 ;
}
}
if ( V_60 ) {
for ( V_28 = 0 ; V_28 < F_12 ( V_61 ) ; V_28 ++ ) {
if ( ! strcmp ( V_60 , V_61 [ V_28 ] . V_27 ) )
V_31 = & V_61 [ V_28 ] ;
}
if ( ! V_31 ) {
F_32 ( L_8 , V_60 ) ;
return - V_52 ;
}
}
#ifdef F_33
V_42 = V_43 ;
#endif
F_34 ( & V_62 ) ;
F_35 () ;
F_36 () ;
V_63 = F_37 ( L_9 , NULL ) ;
if ( ! V_63 ) {
F_32 ( L_10 ) ;
return - V_64 ;
}
for ( V_28 = 0 ; V_28 < F_12 ( V_61 ) ; V_28 ++ ) {
struct V_31 * V_65 = & V_61 [ V_28 ] ;
struct V_66 * V_67 ;
V_67 = F_38 ( V_65 -> V_27 , 0644 , V_63 ,
V_65 , & V_65 -> V_68 ) ;
if ( V_67 == NULL ) {
F_32 ( L_11 , V_65 -> V_27 ) ;
goto V_69;
}
}
if ( V_31 ) {
V_32 = F_15 ( V_31 , V_26 ) ;
if ( V_32 < 0 ) {
F_18 ( L_8 , V_31 -> V_27 ) ;
goto V_69;
}
F_18 ( L_12 ,
V_31 -> V_27 , V_59 ) ;
} else {
F_18 ( L_13 ) ;
}
return 0 ;
V_69:
F_39 ( V_63 ) ;
return V_32 ;
}
static void T_10 F_40 ( void )
{
F_39 ( V_63 ) ;
F_41 () ;
if ( V_36 != NULL )
F_16 ( V_36 ) ;
F_18 ( L_14 ) ;
}
