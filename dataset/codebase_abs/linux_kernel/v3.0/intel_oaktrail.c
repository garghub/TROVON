static int F_1 ( void * V_1 , bool V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
unsigned long V_5 = ( unsigned long ) V_1 ;
F_2 ( V_6 , & V_4 ) ;
if ( ! V_2 )
V_3 = ( T_1 ) ( V_4 | V_5 ) ;
else
V_3 = ( T_1 ) ( V_4 & ~ V_5 ) ;
F_3 ( V_6 , V_3 ) ;
return 0 ;
}
static struct V_7 * F_4 ( char * V_8 , enum V_9 type ,
unsigned long V_10 )
{
struct V_7 * V_11 ;
T_1 V_3 ;
int V_12 ;
V_11 = F_5 ( V_8 , & V_13 -> V_14 , type ,
& V_15 , ( void * ) V_10 ) ;
if ( ! V_11 )
return F_6 ( - V_16 ) ;
F_2 ( V_6 , & V_3 ) ;
F_7 ( V_11 , ( V_3 & V_10 ) != 1 ) ;
V_12 = F_8 ( V_11 ) ;
if ( V_12 ) {
F_9 ( V_11 ) ;
return F_6 ( V_12 ) ;
}
return V_11 ;
}
static inline void F_10 ( struct V_7 * V_17 )
{
if ( V_17 ) {
F_11 ( V_17 ) ;
F_9 ( V_17 ) ;
}
}
static void F_12 ( void )
{
F_10 ( V_18 ) ;
F_10 ( V_19 ) ;
F_10 ( V_20 ) ;
F_10 ( V_21 ) ;
}
static int F_13 ( void )
{
int V_22 ;
V_18 = F_4 ( L_1 ,
V_23 ,
V_24 ) ;
if ( F_14 ( V_18 ) ) {
V_22 = F_15 ( V_18 ) ;
V_18 = NULL ;
goto V_25;
}
V_19 = F_4 ( L_2 ,
V_26 ,
V_27 ) ;
if ( F_14 ( V_19 ) ) {
V_22 = F_15 ( V_19 ) ;
V_19 = NULL ;
goto V_25;
}
V_20 = F_4 ( L_3 ,
V_28 ,
V_29 ) ;
if ( F_14 ( V_20 ) ) {
V_22 = F_15 ( V_20 ) ;
V_20 = NULL ;
goto V_25;
}
V_21 = F_4 ( L_4 ,
V_30 ,
V_31 ) ;
if ( F_14 ( V_21 ) ) {
V_22 = F_15 ( V_21 ) ;
V_21 = NULL ;
goto V_25;
}
return 0 ;
V_25:
F_12 () ;
return V_22 ;
}
static int F_16 ( struct V_32 * V_33 )
{
T_1 V_3 ;
F_2 ( V_34 , & V_3 ) ;
return V_3 ;
}
static int F_17 ( struct V_32 * V_33 )
{
T_1 V_35 = ( T_1 ) V_33 -> V_36 . V_37 ;
if ( V_35 < 0 || V_35 > V_38 )
return - V_39 ;
F_3 ( V_34 , V_35 ) ;
F_3 ( V_40 , V_41 ) ;
return 0 ;
}
static int F_18 ( void )
{
struct V_32 * V_42 ;
struct V_43 V_36 ;
memset ( & V_36 , 0 , sizeof( struct V_43 ) ) ;
V_36 . type = V_44 ;
V_36 . V_45 = V_38 ;
V_42 = F_19 ( V_46 ,
& V_13 -> V_14 , NULL ,
& V_47 ,
& V_36 ) ;
if ( F_14 ( V_42 ) ) {
V_48 = NULL ;
F_20 ( L_5 ) ;
return F_15 ( V_42 ) ;
}
V_48 = V_42 ;
V_42 -> V_36 . V_37 = F_16 ( V_42 ) ;
V_42 -> V_36 . V_49 = V_50 ;
F_21 ( V_42 ) ;
return 0 ;
}
static void F_22 ( void )
{
if ( V_48 )
F_23 ( V_48 ) ;
}
static int T_2 F_24 ( struct V_51 * V_52 )
{
return 0 ;
}
static int T_3 F_25 ( struct V_51 * V_52 )
{
return 0 ;
}
static int F_26 ( const struct V_53 * V_54 )
{
F_27 ( L_6 , V_54 -> V_55 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
int V_22 ;
if ( V_56 ) {
F_29 ( L_7 ) ;
return - V_57 ;
}
if ( ! V_58 && ! F_30 ( V_59 ) ) {
F_29 ( L_8 ) ;
return - V_57 ;
}
V_22 = F_31 ( & V_60 ) ;
if ( V_22 ) {
F_20 ( L_9 ) ;
goto V_61;
}
V_13 = F_32 ( V_46 , - 1 ) ;
if ( ! V_13 ) {
F_20 ( L_10 ) ;
V_22 = - V_16 ;
goto V_62;
}
V_22 = F_33 ( V_13 ) ;
if ( V_22 ) {
F_20 ( L_11 ) ;
goto V_63;
}
if ( ! F_34 () ) {
V_22 = F_18 () ;
if ( V_22 )
goto V_64;
} else
F_27 ( L_12 ) ;
V_22 = F_13 () ;
if ( V_22 ) {
F_20 ( L_13 ) ;
goto V_65;
}
F_27 ( L_14 V_66 L_15 ) ;
return 0 ;
V_65:
F_22 () ;
V_64:
F_35 ( V_13 ) ;
V_63:
F_36 ( V_13 ) ;
V_62:
F_37 ( & V_60 ) ;
V_61:
return V_22 ;
}
static void T_5 F_38 ( void )
{
F_22 () ;
F_12 () ;
F_39 ( V_13 ) ;
F_37 ( & V_60 ) ;
F_27 ( L_16 ) ;
}
