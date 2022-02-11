static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( & V_4 -> V_6 ) ;
if ( V_2 -> V_7 )
F_5 ( V_2 , V_4 -> V_8 ) ;
F_6 ( V_2 ) ;
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_3 * V_2 = V_12 -> V_13 ;
unsigned long V_14 = V_10 -> V_15 ;
int V_16 ;
T_1 V_17 ;
T_2 V_18 ;
V_18 = ( V_14 - V_12 -> V_19 ) >> V_20 ;
V_17 = F_9 ( V_2 -> V_21 . V_22 , V_23 ) ;
if ( V_18 > V_17 )
return V_24 ;
V_16 = - V_25 ;
F_10 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_5 ) {
F_11 ( V_2 -> V_5 [ V_18 ] ) ;
V_10 -> V_26 = V_2 -> V_5 [ V_18 ] ;
V_16 = 0 ;
}
F_12 ( & V_2 -> V_6 ) ;
if ( V_16 ) {
struct V_26 * V_26 ;
V_26 = F_13 (
F_14 ( V_2 -> V_21 . V_27 ) -> V_28 ,
V_18 ) ;
if ( ! F_15 ( V_26 ) ) {
V_10 -> V_26 = V_26 ;
V_16 = 0 ;
} else switch ( F_16 ( V_26 ) ) {
case - V_29 :
case - V_30 :
V_16 = V_31 ;
break;
case - V_32 :
V_16 = V_33 ;
break;
case - V_34 :
case - V_35 :
V_16 = V_24 ;
break;
default:
F_17 ( F_16 ( V_26 ) ) ;
V_16 = V_24 ;
break;
}
}
return V_16 ;
}
static int F_18 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
int V_16 ;
V_41 = F_19 ( sizeof( * V_41 ) , V_42 ) ;
if ( ! V_41 )
return - V_30 ;
V_39 -> V_43 = V_41 ;
V_16 = F_20 ( V_41 ) ;
if ( V_16 ) {
F_7 ( V_41 ) ;
return V_16 ;
}
return 0 ;
}
static void F_21 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_43 ;
F_22 ( V_41 ) ;
F_7 ( V_41 ) ;
}
static struct V_3 * F_23 ( struct V_36 * V_37 ,
unsigned long V_22 )
{
struct V_3 * V_2 ;
int V_16 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return F_24 ( - V_30 ) ;
V_16 = F_25 ( V_37 , & V_2 -> V_21 , F_26 ( V_22 , V_23 ) ) ;
if ( V_16 ) {
F_7 ( V_2 ) ;
return F_24 ( V_16 ) ;
}
F_27 ( & V_2 -> V_6 ) ;
return V_2 ;
}
static void F_28 ( struct V_3 * V_2 )
{
F_6 ( & V_2 -> V_21 ) ;
F_7 ( V_2 ) ;
}
static struct V_1 * F_29 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
unsigned int * V_44 ,
unsigned long V_22 )
{
struct V_3 * V_2 ;
int V_16 ;
V_2 = F_23 ( V_37 , V_22 ) ;
if ( F_15 ( V_2 ) )
return F_30 ( V_2 ) ;
V_16 = F_31 ( V_39 , & V_2 -> V_21 , V_44 ) ;
F_32 ( & V_2 -> V_21 ) ;
if ( V_16 )
goto V_45;
return & V_2 -> V_21 ;
V_45:
F_28 ( V_2 ) ;
return F_24 ( V_16 ) ;
}
static int F_33 ( struct V_38 * V_39 , struct V_36 * V_37 ,
struct V_46 * args )
{
struct V_1 * V_47 ;
T_3 V_48 , V_22 ;
V_48 = args -> V_49 * F_9 ( args -> V_50 , 8 ) ;
V_22 = args -> V_51 * V_48 ;
if ( V_22 == 0 )
return - V_35 ;
V_47 = F_29 ( V_37 , V_39 , & args -> V_44 , V_22 ) ;
if ( F_15 ( V_47 ) )
return F_16 ( V_47 ) ;
args -> V_22 = V_47 -> V_22 ;
args -> V_48 = V_48 ;
F_34 ( L_1 , V_22 ) ;
return 0 ;
}
static int F_35 ( struct V_38 * V_39 , struct V_36 * V_37 ,
T_4 V_44 , T_5 * V_52 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_36 ( V_39 , V_44 ) ;
if ( ! V_2 )
return - V_25 ;
if ( ! V_2 -> V_27 ) {
V_16 = - V_35 ;
goto V_53;
}
V_16 = F_37 ( V_2 ) ;
if ( V_16 )
goto V_53;
* V_52 = F_38 ( & V_2 -> V_54 ) ;
V_53:
F_32 ( V_2 ) ;
return V_16 ;
}
static int F_39 ( struct V_39 * V_27 , struct V_11 * V_12 )
{
unsigned long V_55 = V_12 -> V_56 ;
int V_16 ;
V_16 = F_40 ( V_27 , V_12 ) ;
if ( V_16 )
return V_16 ;
V_12 -> V_56 = V_55 | V_57 | V_58 ;
return 0 ;
}
static struct V_26 * * F_41 ( struct V_3 * V_59 )
{
F_10 ( & V_59 -> V_6 ) ;
if ( V_59 -> V_60 ++ == 0 ) {
struct V_26 * * V_5 ;
V_5 = F_42 ( & V_59 -> V_21 ) ;
if ( F_15 ( V_5 ) ) {
V_59 -> V_60 -- ;
F_12 ( & V_59 -> V_6 ) ;
return V_5 ;
}
V_59 -> V_5 = V_5 ;
}
F_12 ( & V_59 -> V_6 ) ;
return V_59 -> V_5 ;
}
static void F_43 ( struct V_3 * V_59 )
{
F_10 ( & V_59 -> V_6 ) ;
if ( -- V_59 -> V_60 == 0 ) {
F_44 ( & V_59 -> V_21 , V_59 -> V_5 , true , true ) ;
V_59 -> V_5 = NULL ;
}
F_12 ( & V_59 -> V_6 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_59 = F_2 ( V_2 ) ;
long V_61 = V_2 -> V_22 >> V_20 ;
struct V_26 * * V_5 ;
V_5 = F_41 ( V_59 ) ;
if ( F_15 ( V_5 ) )
return F_16 ( V_5 ) ;
F_46 ( V_5 , V_61 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_59 = F_2 ( V_2 ) ;
F_43 ( V_59 ) ;
}
static struct V_62 * F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_59 = F_2 ( V_2 ) ;
return F_49 ( V_59 -> V_5 , V_59 -> V_21 . V_22 >> V_20 ) ;
}
static struct V_1 * F_50 ( struct V_36 * V_37 ,
struct V_63 * V_63 )
{
struct V_64 * V_65 = F_51 ( V_37 , F_52 ( * V_65 ) , V_66 ) ;
return F_53 ( V_37 , V_63 , & V_65 -> V_67 -> V_37 ) ;
}
static struct V_1 * F_54 ( struct V_36 * V_37 ,
struct V_68 * V_69 , struct V_62 * V_70 )
{
struct V_3 * V_2 ;
int V_71 ;
V_2 = F_23 ( V_37 , V_69 -> V_72 -> V_22 ) ;
if ( F_15 ( V_2 ) )
return F_30 ( V_2 ) ;
V_71 = F_55 ( V_69 -> V_72 -> V_22 ) / V_23 ;
V_2 -> V_8 = V_70 ;
V_2 -> V_5 = F_56 ( V_71 , sizeof( struct V_26 * ) , V_42 ) ;
if ( ! V_2 -> V_5 ) {
F_28 ( V_2 ) ;
return F_24 ( - V_30 ) ;
}
V_2 -> V_60 ++ ;
F_57 ( V_2 -> V_8 , V_2 -> V_5 , NULL ,
V_71 ) ;
return & V_2 -> V_21 ;
}
static void * F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_59 = F_2 ( V_2 ) ;
long V_61 = V_2 -> V_22 >> V_20 ;
struct V_26 * * V_5 ;
V_5 = F_41 ( V_59 ) ;
if ( F_15 ( V_5 ) )
return NULL ;
return F_59 ( V_5 , V_61 , 0 , F_60 ( V_73 ) ) ;
}
static void F_61 ( struct V_1 * V_2 , void * V_14 )
{
struct V_3 * V_59 = F_2 ( V_2 ) ;
F_62 ( V_14 ) ;
F_43 ( V_59 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_16 ;
if ( V_2 -> V_22 < V_12 -> V_74 - V_12 -> V_19 )
return - V_35 ;
if ( ! V_2 -> V_27 )
return - V_75 ;
V_16 = F_64 ( V_2 -> V_27 , V_12 ) ;
if ( V_16 )
return V_16 ;
F_65 ( V_12 -> V_76 ) ;
V_12 -> V_76 = F_66 ( V_2 -> V_27 ) ;
V_12 -> V_56 |= V_57 | V_58 ;
V_12 -> V_77 = F_60 ( F_67 ( V_12 -> V_56 ) ) ;
return 0 ;
}
static void F_68 ( struct V_36 * V_37 )
{
struct V_64 * V_65 = F_51 ( V_37 , F_52 ( * V_65 ) , V_66 ) ;
F_69 ( V_65 -> V_67 ) ;
F_70 ( & V_65 -> V_66 ) ;
F_7 ( V_65 ) ;
}
static int T_6 F_71 ( void )
{
int V_16 ;
V_64 = F_19 ( sizeof( * V_64 ) , V_42 ) ;
if ( ! V_64 )
return - V_30 ;
V_16 = F_72 ( & V_64 -> V_66 , & V_78 , NULL ) ;
if ( V_16 )
goto V_79;
V_64 -> V_67 =
F_73 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_15 ( V_64 -> V_67 ) ) {
V_16 = F_16 ( V_64 -> V_67 ) ;
goto V_80;
}
F_74 ( & V_64 -> V_67 -> V_37 ,
F_75 ( 64 ) ) ;
V_16 = F_76 ( & V_64 -> V_66 , 0 ) ;
if ( V_16 )
goto V_81;
return 0 ;
V_81:
F_69 ( V_64 -> V_67 ) ;
V_80:
F_70 ( & V_64 -> V_66 ) ;
V_79:
F_7 ( V_64 ) ;
return V_16 ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_64 -> V_66 ) ;
F_79 ( & V_64 -> V_66 ) ;
}
