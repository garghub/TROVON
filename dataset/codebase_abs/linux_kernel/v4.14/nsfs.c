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
struct V_1 * V_1 ;
struct V_4 * V_4 ;
unsigned long V_20 ;
F_9 () ;
V_20 = F_10 ( & V_11 -> V_13 ) ;
if ( ! V_20 )
goto V_21;
V_1 = (struct V_1 * ) V_20 ;
if ( ! F_11 ( & V_1 -> V_22 ) )
goto V_21;
F_12 () ;
V_11 -> V_14 -> V_15 ( V_11 ) ;
V_23:
V_16 -> V_18 = F_13 ( V_18 ) ;
V_16 -> V_1 = V_1 ;
return NULL ;
V_21:
F_12 () ;
V_4 = F_14 ( V_18 -> V_24 ) ;
if ( ! V_4 ) {
V_11 -> V_14 -> V_15 ( V_11 ) ;
return F_15 ( - V_25 ) ;
}
V_4 -> V_9 = V_11 -> V_26 ;
V_4 -> V_27 = V_4 -> V_28 = V_4 -> V_29 = F_16 ( V_4 ) ;
V_4 -> V_30 |= V_31 ;
V_4 -> V_32 = V_33 | V_34 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_12 = V_11 ;
V_1 = F_17 ( V_18 -> V_24 , & V_37 ) ;
if ( ! V_1 ) {
F_18 ( V_4 ) ;
return F_15 ( - V_25 ) ;
}
F_19 ( V_1 , V_4 ) ;
V_1 -> V_38 |= V_39 ;
V_1 -> V_7 = ( void * ) V_11 -> V_14 ;
V_20 = F_20 ( & V_11 -> V_13 , 0 , ( unsigned long ) V_1 ) ;
if ( V_20 ) {
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 () ;
return F_15 ( - V_40 ) ;
}
goto V_23;
}
void * F_24 ( struct V_16 * V_16 , struct V_41 * V_42 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
void * V_43 ;
V_44:
V_11 = V_6 -> V_45 ( V_42 ) ;
if ( ! V_11 )
return F_15 ( - V_46 ) ;
V_43 = F_8 ( V_16 , V_11 ) ;
if ( F_25 ( V_43 ) && F_26 ( V_43 ) == - V_40 )
goto V_44;
return V_43 ;
}
static long F_27 ( struct V_47 * V_48 , unsigned int V_49 ,
unsigned long V_50 )
{
struct V_51 * V_52 ;
struct V_10 * V_11 = F_28 ( F_29 ( V_48 ) ) ;
T_1 T_2 * V_53 ;
T_1 V_54 ;
switch ( V_49 ) {
case V_55 :
return F_30 ( V_11 , V_56 ) ;
case V_57 :
if ( ! V_11 -> V_14 -> V_58 )
return - V_59 ;
return F_30 ( V_11 , V_11 -> V_14 -> V_58 ) ;
case V_60 :
return V_11 -> V_14 -> type ;
case V_61 :
if ( V_11 -> V_14 -> type != V_62 )
return - V_59 ;
V_52 = F_31 ( V_11 , struct V_51 , V_11 ) ;
V_53 = ( T_1 T_2 * ) V_50 ;
V_54 = F_32 ( F_33 () , V_52 -> V_63 ) ;
return F_34 ( V_54 , V_53 ) ;
default:
return - V_64 ;
}
}
int F_35 ( char * V_65 , T_3 V_66 , struct V_41 * V_42 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_67 = - V_46 ;
const char * V_8 ;
V_11 = V_6 -> V_45 ( V_42 ) ;
if ( V_11 ) {
V_8 = V_6 -> V_68 ? : V_6 -> V_8 ;
V_67 = snprintf ( V_65 , V_66 , L_2 , V_8 , V_11 -> V_26 ) ;
V_6 -> V_15 ( V_11 ) ;
}
return V_67 ;
}
struct V_47 * F_36 ( int V_69 )
{
struct V_47 * V_47 ;
V_47 = F_37 ( V_69 ) ;
if ( ! V_47 )
return F_15 ( - V_70 ) ;
if ( V_47 -> V_71 != & V_36 )
goto V_72;
return V_47 ;
V_72:
F_38 ( V_47 ) ;
return F_15 ( - V_59 ) ;
}
static int F_39 ( struct V_73 * V_74 , struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = V_1 -> V_7 ;
F_40 ( V_74 , L_1 , V_6 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static struct V_1 * F_41 ( struct V_75 * V_76 ,
int V_77 , const char * V_78 , void * V_79 )
{
return F_42 ( V_76 , L_3 , & V_80 ,
& V_81 , V_82 ) ;
}
void T_4 F_43 ( void )
{
V_19 = F_44 ( & V_83 ) ;
if ( F_25 ( V_19 ) )
F_45 ( L_4 ) ;
V_19 -> V_24 -> V_84 &= ~ V_85 ;
}
