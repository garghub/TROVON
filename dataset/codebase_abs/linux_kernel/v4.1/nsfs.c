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
void * F_8 ( struct V_16 * V_16 , struct V_17 * V_18 ,
const struct V_5 * V_6 )
{
struct V_19 * V_20 = F_9 ( V_21 ) ;
struct V_22 V_23 = { . V_8 = L_2 , } ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
struct V_10 * V_11 ;
unsigned long V_24 ;
V_25:
V_11 = V_6 -> V_26 ( V_18 ) ;
if ( ! V_11 ) {
F_10 ( V_20 ) ;
return F_11 ( - V_27 ) ;
}
F_12 () ;
V_24 = F_13 ( & V_11 -> V_13 ) ;
if ( ! V_24 )
goto V_28;
V_1 = (struct V_1 * ) V_24 ;
if ( ! F_14 ( & V_1 -> V_29 ) )
goto V_28;
F_15 () ;
V_6 -> V_15 ( V_11 ) ;
V_30:
V_16 -> V_20 = V_20 ;
V_16 -> V_1 = V_1 ;
return NULL ;
V_28:
F_15 () ;
V_4 = F_16 ( V_20 -> V_31 ) ;
if ( ! V_4 ) {
V_6 -> V_15 ( V_11 ) ;
F_10 ( V_20 ) ;
return F_11 ( - V_32 ) ;
}
V_4 -> V_9 = V_11 -> V_33 ;
V_4 -> V_34 = V_4 -> V_35 = V_4 -> V_36 = V_37 ;
V_4 -> V_38 |= V_39 ;
V_4 -> V_40 = V_41 | V_42 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_12 = V_11 ;
V_1 = F_17 ( V_20 -> V_31 , & V_23 ) ;
if ( ! V_1 ) {
F_18 ( V_4 ) ;
F_10 ( V_20 ) ;
return F_11 ( - V_32 ) ;
}
F_19 ( V_1 , V_4 ) ;
V_1 -> V_7 = ( void * ) V_6 ;
V_24 = F_20 ( & V_11 -> V_13 , 0 , ( unsigned long ) V_1 ) ;
if ( V_24 ) {
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 () ;
goto V_25;
}
goto V_30;
}
int F_24 ( char * V_45 , T_1 V_46 , struct V_17 * V_18 ,
const struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_47 = - V_27 ;
V_11 = V_6 -> V_26 ( V_18 ) ;
if ( V_11 ) {
V_47 = snprintf ( V_45 , V_46 , L_3 , V_6 -> V_8 , V_11 -> V_33 ) ;
V_6 -> V_15 ( V_11 ) ;
}
return V_47 ;
}
struct V_48 * F_25 ( int V_49 )
{
struct V_48 * V_48 ;
V_48 = F_26 ( V_49 ) ;
if ( ! V_48 )
return F_11 ( - V_50 ) ;
if ( V_48 -> V_51 != & V_44 )
goto V_52;
return V_48 ;
V_52:
F_27 ( V_48 ) ;
return F_11 ( - V_53 ) ;
}
static struct V_1 * F_28 ( struct V_54 * V_55 ,
int V_56 , const char * V_57 , void * V_58 )
{
return F_29 ( V_55 , L_4 , & V_59 ,
& V_60 , V_61 ) ;
}
void T_2 F_30 ( void )
{
V_21 = F_31 ( & V_62 ) ;
if ( F_32 ( V_21 ) )
F_33 ( L_5 ) ;
V_21 -> V_31 -> V_63 &= ~ V_64 ;
}
