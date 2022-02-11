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
if ( V_3 -> V_16 && V_6 == V_12 ) {
if ( V_13 )
F_5 ( L_5 ) ;
F_7 ( V_17 . V_18 , V_17 . V_19 ) ;
}
}
static void F_8 ( struct V_20 * V_21 )
{
if ( V_22 > V_23 ) {
F_6 ( L_6 ,
V_23 ) ;
V_22 = V_23 ;
}
if ( V_24 && V_25 != V_26 ) {
if ( V_26 > V_27 ) {
F_6 ( L_7 ,
V_27 ) ;
V_26 = V_27 ;
}
if ( V_13 )
F_5 ( L_8 , V_26 ) ;
V_21 -> V_28 = V_26 * 1000 ;
V_25 = V_26 ;
}
}
static int F_9 ( struct V_20 * V_21 ,
unsigned long * V_29 )
{
int V_1 , V_30 = 0 ;
F_8 ( V_21 ) ;
V_30 = F_1 ( & V_1 ) ;
if ( V_30 )
return V_30 ;
if ( V_13 )
F_5 ( L_9 , V_1 ) ;
* V_29 = V_1 ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_31 * V_32 )
{
if ( V_32 != V_33 )
return 0 ;
if ( F_11 ( V_21 , 0 , V_32 ,
V_34 , V_34 ,
V_35 ) ) {
F_6 ( L_10 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_31 * V_32 )
{
if ( V_32 != V_33 )
return 0 ;
if ( F_13 ( V_21 , 0 , V_32 ) ) {
F_6 ( L_11 ) ;
return - V_5 ;
}
return 0 ;
}
static inline void F_14 ( void )
{
F_4 ( V_11 ) ;
V_24 = 0 ;
if ( V_36 )
V_36 -> V_28 = 0 ;
F_5 ( L_12 ) ;
}
static inline void F_15 ( void )
{
V_24 = 1 ;
V_36 -> V_28 = V_26 * 1000 ;
F_16 ( V_36 ) ;
F_5 ( L_13 ) ;
}
static int F_17 ( struct V_20 * V_21 ,
enum V_37 * V_38 )
{
if ( V_13 )
F_5 ( L_14 , V_24 ) ;
* V_38 = ( V_24 ) ? V_39
: V_40 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
enum V_37 V_38 )
{
if ( V_38 == V_40 && V_24 )
F_14 () ;
else if ( V_38 == V_39 && ! V_24 )
F_15 () ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , int V_41 ,
enum V_42 * type )
{
if ( V_41 == 0 )
* type = V_43 ;
else if ( V_41 == 1 )
* type = V_44 ;
else
return - V_5 ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 , int V_41 ,
unsigned long * V_1 )
{
if ( V_41 != 0 )
return - V_5 ;
* V_1 = V_22 - V_45 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , int V_41 ,
unsigned long * V_1 )
{
if ( V_41 == 0 )
* V_1 = V_22 ;
else if ( V_41 == 1 )
* V_1 = V_46 ;
else
return - V_5 ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
unsigned long * V_47 )
{
* V_47 = V_46 ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 ,
unsigned long * V_6 )
{
* V_6 = 1 ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 ,
unsigned long * V_6 )
{
int V_30 = 0 , V_48 ;
V_30 = F_3 ( & V_48 ) ;
if ( V_30 )
return V_30 ;
* V_6 = ( V_48 == V_11 ) ? 1 : 0 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
unsigned long V_6 )
{
int V_49 , V_50 , V_30 = 0 ;
if ( ! V_24 )
return 0 ;
V_30 = F_1 ( & V_49 ) ;
if ( V_30 ) {
F_6 ( L_15 ) ;
goto V_51;
}
V_30 = F_3 ( & V_50 ) ;
if ( V_30 ) {
F_6 ( L_16 ) ;
goto V_51;
}
if ( V_6 == 0 ) {
if ( V_50 == V_11 )
F_4 ( V_12 ) ;
} else {
if ( V_50 == V_12 )
F_4 ( V_11 ) ;
}
return 0 ;
V_51:
F_14 () ;
return - V_5 ;
}
static int F_26 ( struct V_52 * V_53 )
{
if ( V_24 )
F_4 ( V_11 ) ;
if ( V_13 )
F_5 ( L_17 ) ;
return 0 ;
}
static int F_27 ( struct V_54 * V_52 )
{
return 0 ;
}
static int F_28 ( struct V_54 * V_52 )
{
return 0 ;
}
static int F_29 ( const char * V_55 , const char * V_56 )
{
unsigned long V_57 = 0 , V_58 = 0 ;
V_57 = strlen ( V_55 ) ;
V_58 = strlen ( V_56 ) ;
if ( V_57 >= V_58 &&
! strncmp ( V_55 , V_56 , V_58 ) )
return 1 ;
return 0 ;
}
static int F_30 ( void )
{
char const * V_59 , * V_60 , * V_61 ;
const struct V_62 * V_63 = NULL ;
V_59 = F_31 ( V_64 ) ;
V_60 = F_31 ( V_65 ) ;
V_61 = F_31 ( V_66 ) ;
if ( ! V_59 || ! V_60 || ! V_61 ) {
F_6 ( L_18 ) ;
return - V_5 ;
}
F_32 ( L_19 , V_67 ) ;
if ( V_68 [ 0 ] ) {
V_60 = V_68 ;
F_32 ( L_20 , V_60 ) ;
V_24 = 0 ;
}
if ( V_69 [ 0 ] ) {
V_61 = V_69 ;
F_32 ( L_21 , V_61 ) ;
V_24 = 0 ;
}
if ( V_13 )
F_32 ( L_22 ,
V_59 , V_60 , V_61 ) ;
for ( V_63 = V_70 ; V_63 -> V_59 [ 0 ] ; V_63 ++ ) {
if ( F_29 ( V_59 , V_63 -> V_59 ) &&
F_29 ( V_61 , V_63 -> V_61 ) &&
F_29 ( V_60 , V_63 -> V_60 ) ) {
V_3 = V_63 ;
break;
}
}
if ( ! V_3 ) {
F_6 ( L_23 ,
V_59 , V_61 , V_60 ) ;
return - V_5 ;
}
if ( ! V_24 ) {
F_5 ( L_24 ) ;
F_5 ( L_25 ) ;
}
return 0 ;
}
static int F_33 ( void )
{
int V_30 = 0 ;
V_30 = F_34 ( & V_71 ) ;
if ( V_30 )
return V_30 ;
V_72 = F_35 ( L_26 , - 1 ) ;
if ( ! V_72 ) {
V_30 = - V_73 ;
goto V_74;
}
V_30 = F_36 ( V_72 ) ;
if ( V_30 )
goto V_75;
return 0 ;
V_75:
F_37 ( V_72 ) ;
V_74:
F_38 ( & V_71 ) ;
return V_30 ;
}
static void F_39 ( void )
{
F_40 ( V_72 ) ;
F_38 ( & V_71 ) ;
}
static int F_41 ( void )
{
V_33 = F_42 ( L_27 , NULL ,
& V_76 ) ;
if ( F_43 ( V_33 ) )
return - V_5 ;
V_36 = F_44 ( L_26 , 2 , 0 , NULL ,
& V_77 ,
& V_78 , 0 ,
( V_24 ) ? V_26 * 1000 : 0 ) ;
if ( F_43 ( V_36 ) )
return - V_5 ;
if ( strcmp ( V_36 -> V_79 -> V_80 ,
V_78 . V_81 ) ) {
F_6 ( L_28 ,
V_78 . V_81 ) ;
return - V_5 ;
}
return 0 ;
}
static void F_45 ( void )
{
if ( V_33 ) {
F_46 ( V_33 ) ;
V_33 = NULL ;
}
if ( V_36 ) {
F_47 ( V_36 ) ;
V_36 = NULL ;
}
}
static int T_2 F_48 ( void )
{
int V_30 = 0 ;
V_30 = F_30 () ;
if ( V_30 )
goto V_82;
V_30 = F_33 () ;
if ( V_30 )
goto V_82;
V_30 = F_41 () ;
if ( V_30 )
goto V_83;
return 0 ;
V_83:
F_45 () ;
F_39 () ;
V_82:
return V_30 ;
}
static void T_3 F_49 ( void )
{
F_4 ( V_11 ) ;
F_45 () ;
F_39 () ;
}
