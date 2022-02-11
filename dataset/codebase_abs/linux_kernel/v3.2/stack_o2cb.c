static inline int F_1 ( int V_1 )
{
F_2 ( V_1 > V_2 ) ;
return V_1 ;
}
static int F_3 ( T_1 V_3 )
{
int V_4 = 0 ;
F_4 ( V_5 , V_6 ) ;
F_4 ( V_7 , V_8 ) ;
F_4 ( V_9 , V_10 ) ;
F_4 ( V_11 , V_12 ) ;
F_4 ( V_13 , V_14 ) ;
F_4 ( V_15 , V_16 ) ;
F_4 ( V_17 , V_18 ) ;
F_4 ( V_19 , V_20 ) ;
F_4 ( V_21 , V_22 ) ;
F_2 ( V_3 != 0 ) ;
return V_4 ;
}
static int F_5 ( enum V_23 V_24 )
{
F_2 ( V_24 < 0 || V_24 >= F_6 ( V_25 ) ) ;
return V_25 [ V_24 ] ;
}
static void F_7 ( void * V_26 )
{
struct V_27 * V_28 = V_26 ;
V_28 -> V_29 -> V_30 -> V_31 ( V_28 ) ;
}
static void F_8 ( void * V_26 , int V_32 )
{
struct V_27 * V_28 = V_26 ;
V_28 -> V_29 -> V_30 -> V_33 ( V_28 , V_32 ) ;
}
static void F_9 ( void * V_26 , enum V_23 V_24 )
{
struct V_27 * V_28 = V_26 ;
int error = F_5 ( V_24 ) ;
if ( V_24 == V_34 )
return;
V_28 -> V_29 -> V_30 -> V_35 ( V_28 , error ) ;
}
static int F_10 ( struct V_36 * V_37 ,
int V_1 ,
struct V_27 * V_28 ,
T_1 V_3 ,
void * V_38 ,
unsigned int V_39 )
{
enum V_23 V_24 ;
int V_40 = F_1 ( V_1 ) ;
int V_4 = F_3 ( V_3 ) ;
int V_41 ;
V_24 = F_11 ( V_37 -> V_42 , V_40 , & V_28 -> V_43 ,
V_4 , V_38 , V_39 ,
F_7 , V_28 ,
F_8 ) ;
V_41 = F_5 ( V_24 ) ;
return V_41 ;
}
static int F_12 ( struct V_36 * V_37 ,
struct V_27 * V_28 ,
T_1 V_3 )
{
enum V_23 V_24 ;
int V_4 = F_3 ( V_3 ) ;
int V_41 ;
V_24 = F_13 ( V_37 -> V_42 , & V_28 -> V_43 ,
V_4 , F_9 , V_28 ) ;
V_41 = F_5 ( V_24 ) ;
return V_41 ;
}
static int F_14 ( struct V_27 * V_28 )
{
return F_5 ( V_28 -> V_43 . V_24 ) ;
}
static int F_15 ( struct V_27 * V_28 )
{
return 1 ;
}
static void * F_16 ( struct V_27 * V_28 )
{
return ( void * ) ( V_28 -> V_43 . V_44 ) ;
}
static void F_17 ( struct V_27 * V_28 )
{
F_18 ( V_28 -> V_43 . V_45 ) ;
}
static int F_19 ( void )
{
T_2 V_46 ;
int V_47 ;
unsigned long V_48 [ F_20 ( V_49 ) ] ;
unsigned long V_50 [ F_20 ( V_49 ) ] ;
V_46 = F_21 () ;
if ( V_46 == V_49 ) {
F_22 ( V_51 L_1 ) ;
return - V_52 ;
}
#define F_23 60
for ( V_47 = 0 ; V_47 < F_23 ; ++ V_47 ) {
F_24 ( V_48 , sizeof( V_48 ) ) ;
if ( ! F_25 ( V_46 , V_48 ) ) {
F_22 ( V_51 L_2
L_3 , ( F_26 () ?
L_4 : L_5 ) ) ;
return - V_52 ;
}
F_27 ( V_50 , sizeof( V_50 ) ) ;
F_28 ( V_46 , V_50 ) ;
if ( ! memcmp ( V_48 , V_50 , sizeof( V_48 ) ) )
return 0 ;
if ( V_47 < F_23 )
F_29 ( 1000 ) ;
}
F_22 ( V_51 L_6 ) ;
V_47 = - 1 ;
while ( ( V_47 = F_30 ( V_48 , V_49 ,
V_47 + 1 ) ) < V_49 ) {
if ( ! F_25 ( V_47 , V_50 ) )
F_22 ( L_7 , V_47 ) ;
}
F_22 ( L_8 ) ;
return - V_53 ;
}
static void F_31 ( int V_46 , void * V_54 )
{
struct V_36 * V_37 = V_54 ;
F_22 ( V_55 L_9 ,
V_46 , V_37 -> V_56 , V_37 -> V_57 ) ;
V_37 -> V_58 ( V_46 , V_37 -> V_59 ) ;
}
static int F_32 ( struct V_36 * V_37 )
{
int V_60 = 0 ;
T_1 V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 V_67 ;
F_2 ( V_37 == NULL ) ;
F_2 ( V_37 -> V_30 == NULL ) ;
V_60 = F_19 () ;
if ( V_60 ) {
F_22 ( V_51 L_10
L_11 ) ;
goto V_68;
}
V_65 = F_33 ( sizeof( struct V_64 ) , V_69 ) ;
if ( ! V_65 ) {
V_60 = - V_70 ;
goto V_71;
}
F_34 ( & V_65 -> V_72 , F_31 ,
V_37 ) ;
V_37 -> V_73 = V_65 ;
V_61 = F_35 ( 0 , V_37 -> V_57 , V_37 -> V_56 ) ;
V_67 . V_74 = V_37 -> V_75 . V_74 ;
V_67 . V_76 = V_37 -> V_75 . V_76 ;
V_63 = F_36 ( V_37 -> V_57 , V_61 , & V_67 ) ;
if ( F_37 ( V_63 ) ) {
V_60 = F_38 ( V_63 ) ;
F_39 ( V_60 ) ;
goto V_71;
}
V_37 -> V_75 . V_74 = V_67 . V_74 ;
V_37 -> V_75 . V_76 = V_67 . V_76 ;
V_37 -> V_42 = V_63 ;
F_40 ( V_63 , & V_65 -> V_72 ) ;
V_71:
if ( V_60 && V_37 -> V_73 )
F_41 ( V_37 -> V_73 ) ;
V_68:
return V_60 ;
}
static int F_42 ( struct V_36 * V_37 )
{
struct V_62 * V_63 = V_37 -> V_42 ;
struct V_64 * V_65 = V_37 -> V_73 ;
F_43 ( & V_65 -> V_72 ) ;
V_37 -> V_73 = NULL ;
F_41 ( V_65 ) ;
F_44 ( V_63 ) ;
V_37 -> V_42 = NULL ;
return 0 ;
}
static int F_45 ( unsigned int * V_77 )
{
int V_46 ;
V_46 = F_21 () ;
if ( V_46 == V_78 )
return - V_79 ;
if ( V_46 >= V_49 )
return - V_80 ;
* V_77 = V_46 ;
return 0 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_81 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_81 ) ;
}
