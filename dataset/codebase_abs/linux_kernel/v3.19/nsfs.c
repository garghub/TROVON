static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_6 * V_7 = V_1 -> V_8 ;
return F_2 ( V_1 , V_2 , V_3 , L_1 ,
V_7 -> V_9 , V_4 -> V_10 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
if ( V_4 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
F_4 ( & V_12 -> V_14 , 0 ) ;
}
}
static void F_5 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
F_6 ( V_4 ) ;
V_12 -> V_15 -> V_16 ( V_12 ) ;
}
void * F_7 ( struct V_17 * V_17 , struct V_18 * V_19 ,
const struct V_6 * V_7 )
{
struct V_20 * V_21 = F_8 ( V_22 ) ;
struct V_23 V_24 = { . V_9 = L_2 , } ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
struct V_11 * V_12 ;
unsigned long V_25 ;
V_26:
V_12 = V_7 -> V_27 ( V_19 ) ;
if ( ! V_12 ) {
F_9 ( V_21 ) ;
return F_10 ( - V_28 ) ;
}
F_11 () ;
V_25 = F_12 ( & V_12 -> V_14 ) ;
if ( ! V_25 )
goto V_29;
V_1 = (struct V_1 * ) V_25 ;
if ( ! F_13 ( & V_1 -> V_30 ) )
goto V_29;
F_14 () ;
V_7 -> V_16 ( V_12 ) ;
V_31:
V_17 -> V_21 = V_21 ;
V_17 -> V_1 = V_1 ;
return NULL ;
V_29:
F_14 () ;
V_4 = F_15 ( V_21 -> V_32 ) ;
if ( ! V_4 ) {
V_7 -> V_16 ( V_12 ) ;
F_9 ( V_21 ) ;
return F_10 ( - V_33 ) ;
}
V_4 -> V_10 = V_12 -> V_34 ;
V_4 -> V_35 = V_4 -> V_36 = V_4 -> V_37 = V_38 ;
V_4 -> V_39 |= V_40 ;
V_4 -> V_41 = V_42 | V_43 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_13 = V_12 ;
V_1 = F_16 ( V_21 -> V_32 , & V_24 ) ;
if ( ! V_1 ) {
F_17 ( V_4 ) ;
F_9 ( V_21 ) ;
return F_10 ( - V_33 ) ;
}
F_18 ( V_1 , V_4 ) ;
V_1 -> V_8 = ( void * ) V_7 ;
V_25 = F_19 ( & V_12 -> V_14 , 0 , ( unsigned long ) V_1 ) ;
if ( V_25 ) {
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 () ;
goto V_26;
}
goto V_31;
}
int F_23 ( char * V_46 , T_1 V_47 , struct V_18 * V_19 ,
const struct V_6 * V_7 )
{
struct V_11 * V_12 ;
int V_48 = - V_28 ;
V_12 = V_7 -> V_27 ( V_19 ) ;
if ( V_12 ) {
V_48 = snprintf ( V_46 , V_47 , L_3 , V_7 -> V_9 , V_12 -> V_34 ) ;
V_7 -> V_16 ( V_12 ) ;
}
return V_48 ;
}
struct V_49 * F_24 ( int V_50 )
{
struct V_49 * V_49 ;
V_49 = F_25 ( V_50 ) ;
if ( ! V_49 )
return F_10 ( - V_51 ) ;
if ( V_49 -> V_52 != & V_45 )
goto V_53;
return V_49 ;
V_53:
F_26 ( V_49 ) ;
return F_10 ( - V_54 ) ;
}
static struct V_1 * F_27 ( struct V_55 * V_56 ,
int V_57 , const char * V_58 , void * V_59 )
{
return F_28 ( V_56 , L_4 , & V_60 ,
& V_61 , V_62 ) ;
}
void T_2 F_29 ( void )
{
V_22 = F_30 ( & V_63 ) ;
if ( F_31 ( V_22 ) )
F_32 ( L_5 ) ;
V_22 -> V_32 -> V_64 &= ~ V_65 ;
}
