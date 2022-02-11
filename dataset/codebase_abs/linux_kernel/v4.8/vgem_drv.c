static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_3 * V_2 = V_6 -> V_9 ;
unsigned long V_10 = ( unsigned long ) V_8 -> V_11 ;
struct V_12 * V_12 ;
V_12 = F_6 ( F_7 ( V_2 -> V_13 . V_14 ) -> V_15 ,
( V_10 - V_6 -> V_16 ) >> V_17 ) ;
if ( ! F_8 ( V_12 ) ) {
V_8 -> V_12 = V_12 ;
return 0 ;
} else switch ( F_9 ( V_12 ) ) {
case - V_18 :
case - V_19 :
return V_20 ;
case - V_21 :
return V_22 ;
case - V_23 :
case - V_24 :
return V_25 ;
default:
F_10 ( F_9 ( V_12 ) ) ;
return V_25 ;
}
}
static int F_11 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_12 ( sizeof( * V_31 ) , V_33 ) ;
if ( ! V_31 )
return - V_19 ;
V_29 -> V_34 = V_31 ;
V_32 = F_13 ( V_31 ) ;
if ( V_32 ) {
F_4 ( V_31 ) ;
return V_32 ;
}
return 0 ;
}
static void F_14 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_34 ;
F_15 ( V_31 ) ;
F_4 ( V_31 ) ;
}
static struct V_1 * F_16 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
unsigned int * V_35 ,
unsigned long V_36 )
{
struct V_3 * V_2 ;
int V_32 ;
V_2 = F_12 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return F_17 ( - V_19 ) ;
V_32 = F_18 ( V_27 , & V_2 -> V_13 , F_19 ( V_36 , V_37 ) ) ;
if ( V_32 )
goto V_38;
V_32 = F_20 ( V_29 , & V_2 -> V_13 , V_35 ) ;
F_21 ( & V_2 -> V_13 ) ;
if ( V_32 )
goto V_39;
return & V_2 -> V_13 ;
V_38:
F_4 ( V_2 ) ;
V_39:
return F_17 ( V_32 ) ;
}
static int F_22 ( struct V_28 * V_29 , struct V_26 * V_27 ,
struct V_40 * args )
{
struct V_1 * V_41 ;
T_1 V_42 , V_36 ;
V_42 = args -> V_43 * F_23 ( args -> V_44 , 8 ) ;
V_36 = args -> V_45 * V_42 ;
if ( V_36 == 0 )
return - V_24 ;
V_41 = F_16 ( V_27 , V_29 , & args -> V_35 , V_36 ) ;
if ( F_8 ( V_41 ) )
return F_9 ( V_41 ) ;
args -> V_36 = V_41 -> V_36 ;
args -> V_42 = V_42 ;
F_24 ( L_1 , V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 , struct V_26 * V_27 ,
T_2 V_35 , T_3 * V_46 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_26 ( V_29 , V_35 ) ;
if ( ! V_2 )
return - V_47 ;
if ( ! V_2 -> V_14 ) {
V_32 = - V_24 ;
goto V_48;
}
V_32 = F_27 ( V_2 ) ;
if ( V_32 )
goto V_48;
* V_46 = F_28 ( & V_2 -> V_49 ) ;
V_48:
F_21 ( V_2 ) ;
return V_32 ;
}
static int F_29 ( struct V_29 * V_14 , struct V_5 * V_6 )
{
unsigned long V_50 = V_6 -> V_51 ;
int V_32 ;
V_32 = F_30 ( V_14 , V_6 ) ;
if ( V_32 )
return V_32 ;
V_6 -> V_51 = V_50 | V_52 | V_53 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
long V_54 = V_2 -> V_36 >> V_17 ;
struct V_12 * * V_55 ;
V_55 = F_32 ( V_2 ) ;
if ( F_8 ( V_55 ) )
return F_9 ( V_55 ) ;
F_33 ( V_55 , V_54 ) ;
F_34 ( V_2 , V_55 , true , false ) ;
return 0 ;
}
static struct V_56 * F_35 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_12 * * V_55 ;
V_55 = F_32 ( V_2 ) ;
if ( F_8 ( V_55 ) )
return F_36 ( V_55 ) ;
V_57 = F_37 ( V_55 , V_2 -> V_36 >> V_17 ) ;
F_34 ( V_2 , V_55 , false , false ) ;
return V_57 ;
}
static void * F_38 ( struct V_1 * V_2 )
{
long V_54 = V_2 -> V_36 >> V_17 ;
struct V_12 * * V_55 ;
void * V_58 ;
V_55 = F_32 ( V_2 ) ;
if ( F_8 ( V_55 ) )
return NULL ;
V_58 = F_39 ( V_55 , V_54 , 0 , F_40 ( V_59 ) ) ;
F_34 ( V_2 , V_55 , false , false ) ;
return V_58 ;
}
static void F_41 ( struct V_1 * V_2 , void * V_10 )
{
F_42 ( V_10 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_32 ;
if ( V_2 -> V_36 < V_6 -> V_60 - V_6 -> V_16 )
return - V_24 ;
if ( ! V_2 -> V_14 )
return - V_61 ;
V_32 = V_2 -> V_14 -> V_62 -> V_63 ( V_2 -> V_14 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_44 ( V_6 -> V_64 ) ;
V_6 -> V_64 = F_45 ( V_2 -> V_14 ) ;
V_6 -> V_51 |= V_52 | V_53 ;
V_6 -> V_65 = F_40 ( F_46 ( V_6 -> V_51 ) ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
int V_32 ;
V_66 = F_48 ( & V_67 , NULL ) ;
if ( ! V_66 ) {
V_32 = - V_19 ;
goto V_68;
}
V_32 = F_49 ( V_66 , 0 ) ;
if ( V_32 )
goto V_69;
return 0 ;
V_69:
F_50 ( V_66 ) ;
V_68:
return V_32 ;
}
static void T_5 F_51 ( void )
{
F_52 ( V_66 ) ;
F_50 ( V_66 ) ;
}
