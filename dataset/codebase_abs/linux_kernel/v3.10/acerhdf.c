static int F_1 ( int * V_1 )
{
T_1 V_2 ;
if ( F_2 ( V_3 -> V_4 , & V_2 ) )
return - V_5 ;
* V_1 = V_2 * 1000 ;
return 0 ;
}
static int F_3 ( int * V_6 )
{
T_1 V_7 ;
if ( F_2 ( V_3 -> V_8 , & V_7 ) )
return - V_5 ;
if ( V_7 != V_3 -> V_9 . V_10 )
* V_6 = V_11 ;
else
* V_6 = V_12 ;
return 0 ;
}
static void F_4 ( int V_6 )
{
unsigned char V_9 ;
if ( V_13 )
F_5 ( L_1 , V_6 == V_12 ? L_2 : L_3 ) ;
if ( ( V_6 != V_12 ) && ( V_6 != V_11 ) ) {
F_6 ( L_4 ,
V_6 ) ;
V_6 = V_11 ;
}
V_9 = ( V_6 == V_12 ) ? V_3 -> V_9 . V_10
: V_3 -> V_9 . V_14 ;
V_15 = V_6 ;
F_7 ( V_3 -> V_8 , V_9 ) ;
}
static void F_8 ( struct V_16 * V_17 )
{
if ( V_18 > V_19 ) {
F_6 ( L_5 ,
V_19 ) ;
V_18 = V_19 ;
}
if ( V_20 && V_21 != V_22 ) {
if ( V_22 > V_23 ) {
F_6 ( L_6 ,
V_23 ) ;
V_22 = V_23 ;
}
if ( V_13 )
F_5 ( L_7 , V_22 ) ;
V_17 -> V_24 = V_22 * 1000 ;
V_21 = V_22 ;
}
}
static int F_9 ( struct V_16 * V_17 ,
unsigned long * V_25 )
{
int V_1 , V_26 = 0 ;
F_8 ( V_17 ) ;
V_26 = F_1 ( & V_1 ) ;
if ( V_26 )
return V_26 ;
if ( V_13 )
F_5 ( L_8 , V_1 ) ;
* V_25 = V_1 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_27 * V_28 )
{
if ( V_28 != V_29 )
return 0 ;
if ( F_11 ( V_17 , 0 , V_28 ,
V_30 , V_30 ) ) {
F_6 ( L_9 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_27 * V_28 )
{
if ( V_28 != V_29 )
return 0 ;
if ( F_13 ( V_17 , 0 , V_28 ) ) {
F_6 ( L_10 ) ;
return - V_5 ;
}
return 0 ;
}
static inline void F_14 ( void )
{
F_4 ( V_11 ) ;
V_20 = 0 ;
if ( V_31 )
V_31 -> V_24 = 0 ;
F_5 ( L_11 ) ;
}
static inline void F_15 ( void )
{
V_20 = 1 ;
V_31 -> V_24 = V_22 * 1000 ;
F_16 ( V_31 ) ;
F_5 ( L_12 ) ;
}
static int F_17 ( struct V_16 * V_17 ,
enum V_32 * V_33 )
{
if ( V_13 )
F_5 ( L_13 , V_20 ) ;
* V_33 = ( V_20 ) ? V_34
: V_35 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 ,
enum V_32 V_33 )
{
if ( V_33 == V_35 && V_20 )
F_14 () ;
else if ( V_33 == V_34 && ! V_20 )
F_15 () ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 , int V_36 ,
enum V_37 * type )
{
if ( V_36 == 0 )
* type = V_38 ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 , int V_36 ,
unsigned long * V_1 )
{
if ( V_36 == 0 )
* V_1 = V_18 ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 ,
unsigned long * V_39 )
{
* V_39 = V_40 ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 ,
unsigned long * V_6 )
{
* V_6 = 1 ;
return 0 ;
}
static int F_23 ( struct V_27 * V_28 ,
unsigned long * V_6 )
{
int V_26 = 0 , V_41 ;
V_26 = F_3 ( & V_41 ) ;
if ( V_26 )
return V_26 ;
* V_6 = ( V_41 == V_11 ) ? 1 : 0 ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
unsigned long V_6 )
{
int V_42 , V_43 , V_26 = 0 ;
if ( ! V_20 )
return 0 ;
V_26 = F_1 ( & V_42 ) ;
if ( V_26 ) {
F_6 ( L_14 ) ;
goto V_44;
}
V_26 = F_3 ( & V_43 ) ;
if ( V_26 ) {
F_6 ( L_15 ) ;
goto V_44;
}
if ( V_6 == 0 ) {
if ( ( V_43 == V_11 ) &&
( V_42 < V_45 ) )
F_4 ( V_12 ) ;
} else {
if ( V_43 == V_12 )
F_4 ( V_11 ) ;
}
return 0 ;
V_44:
F_14 () ;
return - V_5 ;
}
static int F_25 ( struct V_46 * V_47 )
{
if ( V_20 )
F_4 ( V_11 ) ;
if ( V_13 )
F_5 ( L_16 ) ;
return 0 ;
}
static int F_26 ( struct V_48 * V_46 )
{
return 0 ;
}
static int F_27 ( struct V_48 * V_46 )
{
return 0 ;
}
static int F_28 ( const char * V_49 , const char * V_50 )
{
unsigned long V_51 = 0 , V_52 = 0 ;
V_51 = strlen ( V_49 ) ;
V_52 = strlen ( V_50 ) ;
if ( V_51 >= V_52 &&
! strncmp ( V_49 , V_50 , V_52 ) )
return 1 ;
return 0 ;
}
static int F_29 ( void )
{
char const * V_53 , * V_54 , * V_55 ;
const struct V_56 * V_57 = NULL ;
V_53 = F_30 ( V_58 ) ;
V_54 = F_30 ( V_59 ) ;
V_55 = F_30 ( V_60 ) ;
if ( ! V_53 || ! V_54 || ! V_55 ) {
F_6 ( L_17 ) ;
return - V_5 ;
}
F_31 ( L_18 , V_61 ) ;
if ( V_62 [ 0 ] ) {
V_54 = V_62 ;
F_31 ( L_19 , V_54 ) ;
V_20 = 0 ;
}
if ( V_63 [ 0 ] ) {
V_55 = V_63 ;
F_31 ( L_20 , V_55 ) ;
V_20 = 0 ;
}
if ( V_13 )
F_31 ( L_21 ,
V_53 , V_54 , V_55 ) ;
for ( V_57 = V_64 ; V_57 -> V_53 [ 0 ] ; V_57 ++ ) {
if ( F_28 ( V_53 , V_57 -> V_53 ) &&
F_28 ( V_55 , V_57 -> V_55 ) &&
F_28 ( V_54 , V_57 -> V_54 ) ) {
V_3 = V_57 ;
break;
}
}
if ( ! V_3 ) {
F_6 ( L_22 ,
V_53 , V_55 , V_54 ) ;
return - V_5 ;
}
if ( ! V_20 ) {
F_5 ( L_23 ) ;
F_5 ( L_24 ) ;
}
return 0 ;
}
static int F_32 ( void )
{
int V_26 = 0 ;
V_26 = F_33 ( & V_65 ) ;
if ( V_26 )
return V_26 ;
V_66 = F_34 ( L_25 , - 1 ) ;
if ( ! V_66 ) {
V_26 = - V_67 ;
goto V_68;
}
V_26 = F_35 ( V_66 ) ;
if ( V_26 )
goto V_69;
return 0 ;
V_69:
F_36 ( V_66 ) ;
V_68:
F_37 ( & V_65 ) ;
return V_26 ;
}
static void F_38 ( void )
{
F_39 ( V_66 ) ;
F_37 ( & V_65 ) ;
}
static int F_40 ( void )
{
V_29 = F_41 ( L_26 , NULL ,
& V_70 ) ;
if ( F_42 ( V_29 ) )
return - V_5 ;
V_31 = F_43 ( L_25 , 1 , 0 , NULL ,
& V_71 , NULL , 0 ,
( V_20 ) ? V_22 * 1000 : 0 ) ;
if ( F_42 ( V_31 ) )
return - V_5 ;
return 0 ;
}
static void F_44 ( void )
{
if ( V_29 ) {
F_45 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_31 ) {
F_46 ( V_31 ) ;
V_31 = NULL ;
}
}
static int T_2 F_47 ( void )
{
int V_26 = 0 ;
V_26 = F_29 () ;
if ( V_26 )
goto V_72;
V_26 = F_32 () ;
if ( V_26 )
goto V_72;
V_26 = F_40 () ;
if ( V_26 )
goto V_73;
return 0 ;
V_73:
F_44 () ;
F_38 () ;
V_72:
return V_26 ;
}
static void T_3 F_48 ( void )
{
F_4 ( V_11 ) ;
F_44 () ;
F_38 () ;
}
