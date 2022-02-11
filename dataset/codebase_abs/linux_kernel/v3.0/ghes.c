static int F_1 ( void )
{
V_1 = F_2 ( V_2 * V_3 ,
V_4 , V_5 , V_6 ) ;
if ( ! V_1 ) {
F_3 ( V_7 L_1 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_4 ( void )
{
F_5 ( V_1 ) ;
}
static void T_1 * F_6 ( T_2 V_9 )
{
unsigned long V_10 ;
V_10 = ( unsigned long ) F_7 ( V_1 -> V_11 ) ;
F_8 ( V_10 , V_10 + V_2 ,
V_9 << V_12 , V_13 ) ;
return ( void T_1 * ) V_10 ;
}
static void T_1 * F_9 ( T_2 V_9 )
{
unsigned long V_10 ;
V_10 = ( unsigned long ) F_10 ( V_1 -> V_11 ) ;
F_8 ( V_10 , V_10 + V_2 ,
V_9 << V_12 , V_13 ) ;
return ( void T_1 * ) V_10 ;
}
static void F_11 ( void T_1 * V_14 )
{
unsigned long V_10 = ( unsigned long V_15 ) V_14 ;
void * V_16 = V_1 -> V_11 ;
F_12 ( V_10 != ( unsigned long ) F_7 ( V_16 ) ) ;
F_13 ( V_10 , V_2 ) ;
F_14 ( V_10 ) ;
}
static void F_15 ( void T_1 * V_14 )
{
unsigned long V_10 = ( unsigned long V_15 ) V_14 ;
void * V_16 = V_1 -> V_11 ;
F_12 ( V_10 != ( unsigned long ) F_10 ( V_16 ) ) ;
F_13 ( V_10 , V_2 ) ;
F_14 ( V_10 ) ;
}
static struct V_17 * F_16 ( struct V_18 * V_19 )
{
struct V_17 * V_17 ;
unsigned int V_20 ;
int V_21 ;
V_17 = F_17 ( sizeof( * V_17 ) , V_22 ) ;
if ( ! V_17 )
return F_18 ( - V_8 ) ;
V_17 -> V_19 = V_19 ;
V_21 = F_19 ( & V_19 -> V_23 ) ;
if ( V_21 )
goto V_24;
V_20 = V_19 -> V_20 ;
if ( V_20 > V_25 ) {
F_20 (FW_WARN GHES_PFX
L_2
L_3 ,
error_block_length, generic->header.source_id) ;
V_20 = V_25 ;
}
V_17 -> V_26 = F_21 ( V_20 , V_22 ) ;
if ( ! V_17 -> V_26 ) {
V_21 = - V_8 ;
goto V_27;
}
return V_17 ;
V_27:
F_22 ( & V_19 -> V_23 ) ;
V_24:
F_23 ( V_17 ) ;
return F_18 ( V_21 ) ;
}
static void F_24 ( struct V_17 * V_17 )
{
F_23 ( V_17 -> V_26 ) ;
F_22 ( & V_17 -> V_19 -> V_23 ) ;
}
static inline int F_25 ( int V_28 )
{
switch ( V_28 ) {
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
default:
return V_36 ;
}
}
static void F_26 ( void * V_37 , T_2 V_38 , T_3 V_39 ,
int V_40 )
{
void T_1 * V_10 ;
unsigned long V_41 = 0 ;
int V_42 = V_42 () ;
T_2 V_43 ;
T_3 V_44 ;
while ( V_39 > 0 ) {
V_43 = V_38 - ( V_38 & V_45 ) ;
if ( V_42 ) {
F_27 ( & V_46 ) ;
V_10 = F_6 ( V_38 >> V_12 ) ;
} else {
F_28 ( & V_47 , V_41 ) ;
V_10 = F_9 ( V_38 >> V_12 ) ;
}
V_44 = V_2 - V_43 ;
V_44 = F_29 ( V_44 , V_39 ) ;
if ( V_40 )
F_30 ( V_37 , V_10 + V_43 , V_44 ) ;
else
F_31 ( V_10 + V_43 , V_37 , V_44 ) ;
V_39 -= V_44 ;
V_38 += V_44 ;
V_37 += V_44 ;
if ( V_42 ) {
F_11 ( V_10 ) ;
F_32 ( & V_46 ) ;
} else {
F_15 ( V_10 ) ;
F_33 ( & V_47 , V_41 ) ;
}
}
}
static int F_34 ( struct V_17 * V_17 , int V_48 )
{
struct V_18 * V_49 = V_17 -> V_19 ;
T_2 V_50 ;
T_3 V_39 ;
int V_21 ;
V_21 = F_35 ( & V_50 , & V_49 -> V_23 ) ;
if ( V_21 ) {
if ( ! V_48 && F_36 () )
F_20 (FW_WARN GHES_PFX
L_4 ,
g->header.source_id) ;
return - V_51 ;
}
if ( ! V_50 )
return - V_52 ;
F_26 ( V_17 -> V_26 , V_50 ,
sizeof( * V_17 -> V_26 ) , 1 ) ;
if ( ! V_17 -> V_26 -> V_53 )
return - V_52 ;
V_17 -> V_54 = V_50 ;
V_17 -> V_41 |= V_55 ;
V_21 = - V_51 ;
V_39 = F_37 ( V_17 -> V_26 ) ;
if ( V_39 < sizeof( * V_17 -> V_26 ) )
goto V_56;
if ( V_39 > V_17 -> V_19 -> V_20 )
goto V_56;
if ( F_38 ( V_17 -> V_26 ) )
goto V_56;
F_26 ( V_17 -> V_26 + 1 ,
V_50 + sizeof( * V_17 -> V_26 ) ,
V_39 - sizeof( * V_17 -> V_26 ) , 1 ) ;
if ( F_39 ( V_17 -> V_26 ) )
goto V_56;
V_21 = 0 ;
V_56:
if ( V_21 && ! V_48 && F_36 () )
F_20 (FW_WARN GHES_PFX
L_5 ) ;
return V_21 ;
}
static void F_40 ( struct V_17 * V_17 )
{
V_17 -> V_26 -> V_53 = 0 ;
if ( ! ( V_17 -> V_41 & V_55 ) )
return;
F_26 ( V_17 -> V_26 , V_17 -> V_54 ,
sizeof( V_17 -> V_26 -> V_53 ) , 0 ) ;
V_17 -> V_41 &= ~ V_55 ;
}
static void F_41 ( struct V_17 * V_17 )
{
int V_57 , V_58 = 0 ;
struct V_59 * V_60 ;
V_57 = F_25 ( V_17 -> V_26 -> V_61 ) ;
F_42 (ghes->estatus, gdata) {
#ifdef F_43
if ( ! F_44 ( * ( V_62 * ) V_60 -> V_63 ,
V_64 ) ) {
F_45 (
V_57 == V_32 ,
(struct V_65 * ) ( V_60 + 1 ) ) ;
V_58 = 1 ;
}
#endif
}
}
static void F_46 ( const char * V_66 , struct V_17 * V_17 )
{
static F_47 ( V_67 , 5 * V_68 , 2 ) ;
if ( V_66 == NULL ) {
if ( F_25 ( V_17 -> V_26 -> V_61 ) <=
V_32 )
V_66 = V_69 V_70 ;
else
V_66 = V_71 V_70 ;
}
if ( F_48 ( & V_67 ) ) {
F_49 (
L_6Hardware error from APEI Generic Hardware Error Source: %d\nL_7Poll interval is 0 for generic hardware error source: %d, disabled.\nL_8Fatal hardware error!L_9Generic hardware error source: %d notified via local interrupt is not supported!\nL_10Unknown notification type: %u for generic hardware error source: %d\nL_11Invalid error block length: %u for generic hardware error source: %d\nL_12Failed to map GSI to IRQ for generic hardware error source: %d\nL_13GHES IRQL_14Failed to register IRQ for generic hardware error source: %d\nL_15GHESL_16HEST is not enabled!\nL_17Huang YingL_18APEI Generic Hardware Error Source supportL_19GPLL_20platform:GHES"
