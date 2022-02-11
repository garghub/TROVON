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
V_1 -> V_7 = ( void * ) V_11 -> V_14 ;
V_22 = F_20 ( & V_11 -> V_13 , 0 , ( unsigned long ) V_1 ) ;
if ( V_22 ) {
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 () ;
return F_15 ( - V_39 ) ;
}
goto V_25;
}
void * F_24 ( struct V_16 * V_16 , struct V_40 * V_41 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
void * V_42 ;
V_43:
V_11 = V_6 -> V_44 ( V_41 ) ;
if ( ! V_11 )
return F_15 ( - V_45 ) ;
V_42 = F_8 ( V_16 , V_11 ) ;
if ( F_25 ( V_42 ) && F_26 ( V_42 ) == - V_39 )
goto V_43;
return V_42 ;
}
static long F_27 ( struct V_46 * V_47 , unsigned int V_48 ,
unsigned long V_49 )
{
struct V_10 * V_11 = F_28 ( F_29 ( V_47 ) ) ;
switch ( V_48 ) {
case V_50 :
return F_30 ( V_11 , V_51 ) ;
case V_52 :
if ( ! V_11 -> V_14 -> V_53 )
return - V_54 ;
return F_30 ( V_11 , V_11 -> V_14 -> V_53 ) ;
default:
return - V_55 ;
}
}
int F_31 ( char * V_56 , T_1 V_57 , struct V_40 * V_41 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_58 = - V_45 ;
V_11 = V_6 -> V_44 ( V_41 ) ;
if ( V_11 ) {
V_58 = snprintf ( V_56 , V_57 , L_3 , V_6 -> V_8 , V_11 -> V_28 ) ;
V_6 -> V_15 ( V_11 ) ;
}
return V_58 ;
}
struct V_46 * F_32 ( int V_59 )
{
struct V_46 * V_46 ;
V_46 = F_33 ( V_59 ) ;
if ( ! V_46 )
return F_15 ( - V_60 ) ;
if ( V_46 -> V_61 != & V_38 )
goto V_62;
return V_46 ;
V_62:
F_34 ( V_46 ) ;
return F_15 ( - V_54 ) ;
}
static int F_35 ( struct V_63 * V_64 , struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = V_1 -> V_7 ;
F_36 ( V_64 , L_1 , V_6 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static struct V_1 * F_37 ( struct V_65 * V_66 ,
int V_67 , const char * V_68 , void * V_69 )
{
return F_38 ( V_66 , L_4 , & V_70 ,
& V_71 , V_72 ) ;
}
void T_2 F_39 ( void )
{
V_19 = F_40 ( & V_73 ) ;
if ( F_25 ( V_19 ) )
F_41 ( L_5 ) ;
V_19 -> V_26 -> V_74 &= ~ V_75 ;
}
