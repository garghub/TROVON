static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
if ( V_2 -> V_6 )
F_4 ( V_2 , V_4 -> V_7 ) ;
F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_3 * V_2 = V_11 -> V_12 ;
unsigned long V_13 = V_9 -> V_14 ;
int V_15 ;
T_1 V_16 ;
T_2 V_17 ;
V_17 = ( V_13 - V_11 -> V_18 ) >> V_19 ;
V_16 = F_8 ( V_2 -> V_20 . V_21 , V_22 ) ;
if ( V_17 > V_16 )
return V_23 ;
if ( V_2 -> V_5 ) {
F_9 ( V_2 -> V_5 [ V_17 ] ) ;
V_9 -> V_24 = V_2 -> V_5 [ V_17 ] ;
V_15 = 0 ;
} else {
struct V_24 * V_24 ;
V_24 = F_10 (
F_11 ( V_2 -> V_20 . V_25 ) -> V_26 ,
V_17 ) ;
if ( ! F_12 ( V_24 ) ) {
V_9 -> V_24 = V_24 ;
V_15 = 0 ;
} else switch ( F_13 ( V_24 ) ) {
case - V_27 :
case - V_28 :
V_15 = V_29 ;
break;
case - V_30 :
V_15 = V_31 ;
break;
case - V_32 :
case - V_33 :
V_15 = V_23 ;
break;
default:
F_14 ( F_13 ( V_24 ) ) ;
V_15 = V_23 ;
break;
}
}
return V_15 ;
}
static int F_15 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_38 * V_39 ;
int V_15 ;
V_39 = F_16 ( sizeof( * V_39 ) , V_40 ) ;
if ( ! V_39 )
return - V_28 ;
V_37 -> V_41 = V_39 ;
V_15 = F_17 ( V_39 ) ;
if ( V_15 ) {
F_6 ( V_39 ) ;
return V_15 ;
}
return 0 ;
}
static void F_18 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_41 ;
F_19 ( V_39 ) ;
F_6 ( V_39 ) ;
}
static struct V_3 * F_20 ( struct V_34 * V_35 ,
unsigned long V_21 )
{
struct V_3 * V_2 ;
int V_15 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return F_21 ( - V_28 ) ;
V_15 = F_22 ( V_35 , & V_2 -> V_20 , F_23 ( V_21 , V_22 ) ) ;
if ( V_15 ) {
F_6 ( V_2 ) ;
return F_21 ( V_15 ) ;
}
return V_2 ;
}
static void F_24 ( struct V_3 * V_2 )
{
F_5 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
}
static struct V_1 * F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned int * V_42 ,
unsigned long V_21 )
{
struct V_3 * V_2 ;
int V_15 ;
V_2 = F_20 ( V_35 , V_21 ) ;
if ( F_12 ( V_2 ) )
return F_26 ( V_2 ) ;
V_15 = F_27 ( V_37 , & V_2 -> V_20 , V_42 ) ;
F_28 ( & V_2 -> V_20 ) ;
if ( V_15 )
goto V_43;
return & V_2 -> V_20 ;
V_43:
F_24 ( V_2 ) ;
return F_21 ( V_15 ) ;
}
static int F_29 ( struct V_36 * V_37 , struct V_34 * V_35 ,
struct V_44 * args )
{
struct V_1 * V_45 ;
T_3 V_46 , V_21 ;
V_46 = args -> V_47 * F_8 ( args -> V_48 , 8 ) ;
V_21 = args -> V_49 * V_46 ;
if ( V_21 == 0 )
return - V_33 ;
V_45 = F_25 ( V_35 , V_37 , & args -> V_42 , V_21 ) ;
if ( F_12 ( V_45 ) )
return F_13 ( V_45 ) ;
args -> V_21 = V_45 -> V_21 ;
args -> V_46 = V_46 ;
F_30 ( L_1 , V_21 ) ;
return 0 ;
}
static int F_31 ( struct V_36 * V_37 , struct V_34 * V_35 ,
T_4 V_42 , T_5 * V_50 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_32 ( V_37 , V_42 ) ;
if ( ! V_2 )
return - V_51 ;
if ( ! V_2 -> V_25 ) {
V_15 = - V_33 ;
goto V_52;
}
V_15 = F_33 ( V_2 ) ;
if ( V_15 )
goto V_52;
* V_50 = F_34 ( & V_2 -> V_53 ) ;
V_52:
F_28 ( V_2 ) ;
return V_15 ;
}
static int F_35 ( struct V_37 * V_25 , struct V_10 * V_11 )
{
unsigned long V_54 = V_11 -> V_55 ;
int V_15 ;
V_15 = F_36 ( V_25 , V_11 ) ;
if ( V_15 )
return V_15 ;
V_11 -> V_55 = V_54 | V_56 | V_57 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
long V_58 = V_2 -> V_21 >> V_19 ;
struct V_24 * * V_5 ;
V_5 = F_38 ( V_2 ) ;
if ( F_12 ( V_5 ) )
return F_13 ( V_5 ) ;
F_39 ( V_5 , V_58 ) ;
F_40 ( V_2 , V_5 , true , false ) ;
return 0 ;
}
static struct V_59 * F_41 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
struct V_24 * * V_5 ;
V_5 = F_38 ( V_2 ) ;
if ( F_12 ( V_5 ) )
return F_26 ( V_5 ) ;
V_60 = F_42 ( V_5 , V_2 -> V_21 >> V_19 ) ;
F_40 ( V_2 , V_5 , false , false ) ;
return V_60 ;
}
static struct V_1 * F_43 ( struct V_34 * V_35 ,
struct V_61 * V_61 )
{
struct V_62 * V_63 = F_44 ( V_35 , F_45 ( * V_63 ) , V_64 ) ;
return F_46 ( V_35 , V_61 , & V_63 -> V_65 -> V_35 ) ;
}
static struct V_1 * F_47 ( struct V_34 * V_35 ,
struct V_66 * V_67 , struct V_59 * V_68 )
{
struct V_3 * V_2 ;
int V_69 ;
V_2 = F_20 ( V_35 , V_67 -> V_70 -> V_21 ) ;
if ( F_12 ( V_2 ) )
return F_26 ( V_2 ) ;
V_69 = F_48 ( V_67 -> V_70 -> V_21 ) / V_22 ;
V_2 -> V_7 = V_68 ;
V_2 -> V_5 = F_49 ( V_69 , sizeof( struct V_24 * ) , V_40 ) ;
if ( ! V_2 -> V_5 ) {
F_24 ( V_2 ) ;
return F_21 ( - V_28 ) ;
}
F_50 ( V_2 -> V_7 , V_2 -> V_5 , NULL ,
V_69 ) ;
return & V_2 -> V_20 ;
}
static void * F_51 ( struct V_1 * V_2 )
{
long V_58 = V_2 -> V_21 >> V_19 ;
struct V_24 * * V_5 ;
void * V_71 ;
V_5 = F_38 ( V_2 ) ;
if ( F_12 ( V_5 ) )
return NULL ;
V_71 = F_52 ( V_5 , V_58 , 0 , F_53 ( V_72 ) ) ;
F_40 ( V_2 , V_5 , false , false ) ;
return V_71 ;
}
static void F_54 ( struct V_1 * V_2 , void * V_13 )
{
F_55 ( V_13 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_15 ;
if ( V_2 -> V_21 < V_11 -> V_73 - V_11 -> V_18 )
return - V_33 ;
if ( ! V_2 -> V_25 )
return - V_74 ;
V_15 = F_57 ( V_2 -> V_25 , V_11 ) ;
if ( V_15 )
return V_15 ;
F_58 ( V_11 -> V_75 ) ;
V_11 -> V_75 = F_59 ( V_2 -> V_25 ) ;
V_11 -> V_55 |= V_56 | V_57 ;
V_11 -> V_76 = F_53 ( F_60 ( V_11 -> V_55 ) ) ;
return 0 ;
}
static void F_61 ( struct V_34 * V_35 )
{
struct V_62 * V_63 = F_44 ( V_35 , F_45 ( * V_63 ) , V_64 ) ;
F_62 ( V_63 -> V_65 ) ;
F_63 ( & V_63 -> V_64 ) ;
F_6 ( V_63 ) ;
}
static int T_6 F_64 ( void )
{
int V_15 ;
V_62 = F_16 ( sizeof( * V_62 ) , V_40 ) ;
if ( ! V_62 )
return - V_28 ;
V_15 = F_65 ( & V_62 -> V_64 , & V_77 , NULL ) ;
if ( V_15 )
goto V_78;
V_62 -> V_65 =
F_66 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_12 ( V_62 -> V_65 ) ) {
V_15 = F_13 ( V_62 -> V_65 ) ;
goto V_79;
}
F_67 ( & V_62 -> V_65 -> V_35 ,
F_68 ( 64 ) ) ;
V_15 = F_69 ( & V_62 -> V_64 , 0 ) ;
if ( V_15 )
goto V_80;
return 0 ;
V_80:
F_62 ( V_62 -> V_65 ) ;
V_79:
F_63 ( & V_62 -> V_64 ) ;
V_78:
F_6 ( V_62 ) ;
return V_15 ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_62 -> V_64 ) ;
F_72 ( & V_62 -> V_64 ) ;
}
