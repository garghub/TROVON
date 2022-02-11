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
static void F_19 ( int V_46 , void * V_47 )
{
struct V_36 * V_37 = V_47 ;
F_20 ( V_48 , L_1 ,
V_46 , V_37 -> V_49 , V_37 -> V_50 ) ;
V_37 -> V_51 ( V_46 , V_37 -> V_52 ) ;
}
static int F_21 ( struct V_36 * V_37 )
{
int V_53 = 0 ;
T_1 V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 V_60 ;
F_2 ( V_37 == NULL ) ;
F_2 ( V_37 -> V_30 == NULL ) ;
if ( ! F_22 () ) {
if ( F_23 () )
F_20 ( V_61 , L_2 ) ;
V_53 = - V_62 ;
goto V_63;
}
V_58 = F_24 ( sizeof( struct V_57 ) , V_64 ) ;
if ( ! V_58 ) {
V_53 = - V_65 ;
goto V_66;
}
F_25 ( & V_58 -> V_67 , F_19 ,
V_37 ) ;
V_37 -> V_68 = V_58 ;
V_54 = F_26 ( 0 , V_37 -> V_50 , V_37 -> V_49 ) ;
V_60 . V_69 = V_37 -> V_70 . V_69 ;
V_60 . V_71 = V_37 -> V_70 . V_71 ;
V_56 = F_27 ( V_37 -> V_50 , V_54 , & V_60 ) ;
if ( F_28 ( V_56 ) ) {
V_53 = F_29 ( V_56 ) ;
F_30 ( V_53 ) ;
goto V_66;
}
V_37 -> V_70 . V_69 = V_60 . V_69 ;
V_37 -> V_70 . V_71 = V_60 . V_71 ;
V_37 -> V_42 = V_56 ;
F_31 ( V_56 , & V_58 -> V_67 ) ;
V_66:
if ( V_53 && V_37 -> V_68 )
F_32 ( V_37 -> V_68 ) ;
V_63:
return V_53 ;
}
static int F_33 ( struct V_36 * V_37 )
{
struct V_55 * V_56 = V_37 -> V_42 ;
struct V_57 * V_58 = V_37 -> V_68 ;
F_34 ( & V_58 -> V_67 ) ;
V_37 -> V_68 = NULL ;
F_32 ( V_58 ) ;
F_35 ( V_56 ) ;
V_37 -> V_42 = NULL ;
return 0 ;
}
static int F_36 ( unsigned int * V_72 )
{
int V_46 ;
V_46 = F_37 () ;
if ( V_46 == V_73 )
return - V_74 ;
if ( V_46 >= V_75 )
return - V_76 ;
* V_72 = V_46 ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_77 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_77 ) ;
}
