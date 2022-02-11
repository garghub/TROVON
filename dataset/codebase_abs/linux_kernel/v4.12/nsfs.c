static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = V_1 -> V_7 ;
return F_3 ( V_1 , V_2 , V_3 , L_1 ,
V_6 -> V_8 , V_4 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
if ( V_4 ) {
struct V_10 * V_11 = V_4 -> V_12 ;
F_5 ( & V_11 -> V_13 , 0 ) ;
}
}
static void F_6 ( struct V_4 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
F_7 ( V_4 ) ;
V_11 -> V_14 -> V_15 ( V_11 ) ;
}
static void * F_8 ( struct V_16 * V_16 , struct V_10 * V_11 )
{
struct V_17 * V_18 = V_19 ;
struct V_20 V_21 = { . V_8 = L_2 , } ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
unsigned long V_22 ;
F_9 () ;
V_22 = F_10 ( & V_11 -> V_13 ) ;
if ( ! V_22 )
goto V_23;
V_1 = (struct V_1 * ) V_22 ;
if ( ! F_11 ( & V_1 -> V_24 ) )
goto V_23;
F_12 () ;
V_11 -> V_14 -> V_15 ( V_11 ) ;
V_25:
V_16 -> V_18 = F_13 ( V_18 ) ;
V_16 -> V_1 = V_1 ;
return NULL ;
V_23:
F_12 () ;
V_4 = F_14 ( V_18 -> V_26 ) ;
if ( ! V_4 ) {
V_11 -> V_14 -> V_15 ( V_11 ) ;
return F_15 ( - V_27 ) ;
}
V_4 -> V_9 = V_11 -> V_28 ;
V_4 -> V_29 = V_4 -> V_30 = V_4 -> V_31 = F_16 ( V_4 ) ;
V_4 -> V_32 |= V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_12 = V_11 ;
V_1 = F_17 ( V_18 -> V_26 , & V_21 ) ;
if ( ! V_1 ) {
F_18 ( V_4 ) ;
return F_15 ( - V_27 ) ;
}
F_19 ( V_1 , V_4 ) ;
V_1 -> V_39 |= V_40 ;
V_1 -> V_7 = ( void * ) V_11 -> V_14 ;
V_22 = F_20 ( & V_11 -> V_13 , 0 , ( unsigned long ) V_1 ) ;
if ( V_22 ) {
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 () ;
return F_15 ( - V_41 ) ;
}
goto V_25;
}
void * F_24 ( struct V_16 * V_16 , struct V_42 * V_43 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
void * V_44 ;
V_45:
V_11 = V_6 -> V_46 ( V_43 ) ;
if ( ! V_11 )
return F_15 ( - V_47 ) ;
V_44 = F_8 ( V_16 , V_11 ) ;
if ( F_25 ( V_44 ) && F_26 ( V_44 ) == - V_41 )
goto V_45;
return V_44 ;
}
static long F_27 ( struct V_48 * V_49 , unsigned int V_50 ,
unsigned long V_51 )
{
struct V_52 * V_53 ;
struct V_10 * V_11 = F_28 ( F_29 ( V_49 ) ) ;
T_1 T_2 * V_54 ;
T_1 V_55 ;
switch ( V_50 ) {
case V_56 :
return F_30 ( V_11 , V_57 ) ;
case V_58 :
if ( ! V_11 -> V_14 -> V_59 )
return - V_60 ;
return F_30 ( V_11 , V_11 -> V_14 -> V_59 ) ;
case V_61 :
return V_11 -> V_14 -> type ;
case V_62 :
if ( V_11 -> V_14 -> type != V_63 )
return - V_60 ;
V_53 = F_31 ( V_11 , struct V_52 , V_11 ) ;
V_54 = ( T_1 T_2 * ) V_51 ;
V_55 = F_32 ( F_33 () , V_53 -> V_64 ) ;
return F_34 ( V_55 , V_54 ) ;
default:
return - V_65 ;
}
}
int F_35 ( char * V_66 , T_3 V_67 , struct V_42 * V_43 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_68 = - V_47 ;
const char * V_8 ;
V_11 = V_6 -> V_46 ( V_43 ) ;
if ( V_11 ) {
V_8 = V_6 -> V_69 ? : V_6 -> V_8 ;
V_68 = snprintf ( V_66 , V_67 , L_3 , V_8 , V_11 -> V_28 ) ;
V_6 -> V_15 ( V_11 ) ;
}
return V_68 ;
}
struct V_48 * F_36 ( int V_70 )
{
struct V_48 * V_48 ;
V_48 = F_37 ( V_70 ) ;
if ( ! V_48 )
return F_15 ( - V_71 ) ;
if ( V_48 -> V_72 != & V_38 )
goto V_73;
return V_48 ;
V_73:
F_38 ( V_48 ) ;
return F_15 ( - V_60 ) ;
}
static int F_39 ( struct V_74 * V_75 , struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = V_1 -> V_7 ;
F_40 ( V_75 , L_1 , V_6 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static struct V_1 * F_41 ( struct V_76 * V_77 ,
int V_78 , const char * V_79 , void * V_80 )
{
return F_42 ( V_77 , L_4 , & V_81 ,
& V_82 , V_83 ) ;
}
void T_4 F_43 ( void )
{
V_19 = F_44 ( & V_84 ) ;
if ( F_25 ( V_19 ) )
F_45 ( L_5 ) ;
V_19 -> V_26 -> V_85 &= ~ V_86 ;
}
