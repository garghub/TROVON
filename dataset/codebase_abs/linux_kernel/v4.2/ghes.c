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
static int F_16 ( void )
{
V_17 = F_17 ( V_18 , - 1 ) ;
if ( ! V_17 )
return - V_8 ;
return 0 ;
}
static void F_18 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
void * V_23 )
{
F_19 ( V_22 -> V_24 ) ;
}
static void F_20 ( void )
{
F_21 ( V_17 ,
F_18 , NULL ) ;
F_22 ( V_17 ) ;
}
static int F_23 ( unsigned long V_25 )
{
unsigned long V_26 , V_27 , V_28 , V_11 ;
int V_29 ;
V_30 += F_24 ( V_25 ) ;
V_28 = F_25 ( V_17 ) ;
if ( V_28 >= V_30 )
return 0 ;
V_27 = ( V_30 - V_28 ) / V_2 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_11 = F_26 ( V_31 ) ;
if ( ! V_11 )
return - V_8 ;
V_29 = F_27 ( V_17 , V_11 , V_2 , - 1 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static struct V_32 * F_28 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
unsigned int V_35 ;
int V_36 ;
V_32 = F_29 ( sizeof( * V_32 ) , V_31 ) ;
if ( ! V_32 )
return F_30 ( - V_8 ) ;
V_32 -> V_34 = V_34 ;
V_36 = F_31 ( & V_34 -> V_37 ) ;
if ( V_36 )
goto V_38;
V_35 = V_34 -> V_35 ;
if ( V_35 > V_39 ) {
F_32 (FW_WARN GHES_PFX
L_2
L_3 ,
error_block_length, generic->header.source_id) ;
V_35 = V_39 ;
}
V_32 -> V_40 = F_33 ( V_35 , V_31 ) ;
if ( ! V_32 -> V_40 ) {
V_36 = - V_8 ;
goto V_41;
}
return V_32 ;
V_41:
F_34 ( & V_34 -> V_37 ) ;
V_38:
F_35 ( V_32 ) ;
return F_30 ( V_36 ) ;
}
static void F_36 ( struct V_32 * V_32 )
{
F_35 ( V_32 -> V_40 ) ;
F_34 ( & V_32 -> V_34 -> V_37 ) ;
}
static inline int F_37 ( int V_42 )
{
switch ( V_42 ) {
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
default:
return V_50 ;
}
}
static void F_38 ( void * V_51 , T_2 V_52 , T_3 V_25 ,
int V_53 )
{
void T_1 * V_10 ;
unsigned long V_54 = 0 ;
int V_55 = V_55 () ;
T_2 V_56 ;
T_3 V_57 ;
while ( V_25 > 0 ) {
V_56 = V_52 - ( V_52 & V_58 ) ;
if ( V_55 ) {
F_39 ( & V_59 ) ;
V_10 = F_6 ( V_52 >> V_12 ) ;
} else {
F_40 ( & V_60 , V_54 ) ;
V_10 = F_9 ( V_52 >> V_12 ) ;
}
V_57 = V_2 - V_56 ;
V_57 = F_41 ( V_57 , V_25 ) ;
if ( V_53 )
F_42 ( V_51 , V_10 + V_56 , V_57 ) ;
else
F_43 ( V_10 + V_56 , V_51 , V_57 ) ;
V_25 -= V_57 ;
V_52 += V_57 ;
V_51 += V_57 ;
if ( V_55 ) {
F_11 ( V_10 ) ;
F_44 ( & V_59 ) ;
} else {
F_15 ( V_10 ) ;
F_45 ( & V_60 , V_54 ) ;
}
}
}
static int F_46 ( struct V_32 * V_32 , int V_61 )
{
struct V_33 * V_62 = V_32 -> V_34 ;
T_2 V_63 ;
T_3 V_25 ;
int V_36 ;
V_36 = F_47 ( & V_63 , & V_62 -> V_37 ) ;
if ( V_36 ) {
if ( ! V_61 && F_48 () )
F_32 (FW_WARN GHES_PFX
L_4 ,
g->header.source_id) ;
return - V_64 ;
}
if ( ! V_63 )
return - V_65 ;
F_38 ( V_32 -> V_40 , V_63 ,
sizeof( * V_32 -> V_40 ) , 1 ) ;
if ( ! V_32 -> V_40 -> V_66 )
return - V_65 ;
V_32 -> V_67 = V_63 ;
V_32 -> V_54 |= V_68 ;
V_36 = - V_64 ;
V_25 = F_49 ( V_32 -> V_40 ) ;
if ( V_25 < sizeof( * V_32 -> V_40 ) )
goto V_69;
if ( V_25 > V_32 -> V_34 -> V_35 )
goto V_69;
if ( F_50 ( V_32 -> V_40 ) )
goto V_69;
F_38 ( V_32 -> V_40 + 1 ,
V_63 + sizeof( * V_32 -> V_40 ) ,
V_25 - sizeof( * V_32 -> V_40 ) , 1 ) ;
if ( F_51 ( V_32 -> V_40 ) )
goto V_69;
V_36 = 0 ;
V_69:
if ( V_36 && ! V_61 && F_48 () )
F_32 (FW_WARN GHES_PFX
L_5 ) ;
return V_36 ;
}
static void F_52 ( struct V_32 * V_32 )
{
V_32 -> V_40 -> V_66 = 0 ;
if ( ! ( V_32 -> V_54 & V_68 ) )
return;
F_38 ( V_32 -> V_40 , V_32 -> V_67 ,
sizeof( V_32 -> V_40 -> V_66 ) , 0 ) ;
V_32 -> V_54 &= ~ V_68 ;
}
static void F_53 ( struct V_70 * V_71 , int V_72 )
{
#ifdef F_54
unsigned long V_9 ;
int V_54 = - 1 ;
int V_73 = F_37 ( V_71 -> V_74 ) ;
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) ( V_71 + 1 ) ;
if ( ! ( V_76 -> V_77 & V_78 ) )
return;
V_9 = V_76 -> V_79 >> V_12 ;
if ( ! F_55 ( V_9 ) ) {
F_56 (FW_WARN GHES_PFX
L_6 ,
mem_err->physical_addr) ;
return;
}
if ( V_73 == V_46 &&
( V_71 -> V_54 & V_80 ) )
V_54 = V_81 ;
if ( V_72 == V_48 && V_73 == V_48 )
V_54 = 0 ;
if ( V_54 != - 1 )
F_57 ( V_9 , 0 , V_54 ) ;
#endif
}
static void F_58 ( struct V_32 * V_32 ,
const struct V_82 * V_40 )
{
int V_72 , V_73 ;
struct V_70 * V_71 ;
V_72 = F_37 ( V_40 -> V_74 ) ;
F_59 (estatus, gdata) {
V_73 = F_37 ( V_71 -> V_74 ) ;
if ( ! F_60 ( * ( V_83 * ) V_71 -> V_84 ,
V_85 ) ) {
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) ( V_71 + 1 ) ;
F_61 ( V_32 , V_72 , V_76 ) ;
F_62 ( V_72 , V_76 ) ;
F_53 ( V_71 , V_72 ) ;
}
#ifdef F_63
else if ( ! F_60 ( * ( V_83 * ) V_71 -> V_84 ,
V_86 ) ) {
struct V_87 * V_88 ;
V_88 = (struct V_87 * ) ( V_71 + 1 ) ;
if ( V_72 == V_48 &&
V_73 == V_48 &&
V_88 -> V_77 & V_89 &&
V_88 -> V_77 & V_90 ) {
unsigned int V_91 ;
int V_92 ;
V_91 = F_64 ( V_88 -> V_93 . V_94 ,
V_88 -> V_93 . V_95 ) ;
V_92 = F_65 ( V_72 ) ;
if ( V_71 -> V_54 & V_96 )
V_92 = V_97 ;
F_66 ( V_88 -> V_93 . V_98 ,
V_88 -> V_93 . V_99 ,
V_91 , V_92 ,
(struct V_100 * )
V_88 -> V_101 ) ;
}
}
#endif
}
}
static void F_67 ( const char * V_102 ,
const struct V_33 * V_34 ,
const struct V_82 * V_40 )
{
static T_4 V_103 ;
unsigned int V_104 ;
char V_105 [ 64 ] ;
if ( V_102 == NULL ) {
if ( F_37 ( V_40 -> V_74 ) <=
V_46 )
V_102 = V_106 ;
else
V_102 = V_107 ;
}
V_104 = F_68 ( & V_103 ) ;
snprintf ( V_105 , sizeof( V_105 ) , L_7 V_108 , V_102 , V_104 ) ;
F_69 ( L_8Hardware error from APEI Generic Hardware Error Source: %d\nL_9Poll interval is 0 for generic hardware error source: %d, disabled.\nL_10Fatal hardware error!L_11ghesL_12ghesL_13ID: %d, trying to add NMI notification which is not supported!\nL_14ID: %d, trying to remove NMI notification which is not supported!\nL_15Generic hardware error source: %d notified via NMI interrupt is not supported!\nL_16Generic hardware error source: %d notified via local interrupt is not supported!\nL_17Unknown notification type: %u for generic hardware error source: %d\nL_18Invalid error block length: %u for generic hardware error source: %d\nL_19Failed to map GSI to IRQ for generic hardware error source: %d\nL_20GHES IRQL_21Failed to register IRQ for generic hardware error source: %d\nL_22GHESL_23HEST is not enabled!\nL_24GHES is not enabled!\nL_25APEI firmware first mode is enabled by APEI bit and WHEA _OSC.\nL_26APEI firmware first mode is enabled by WHEA _OSC.\nL_27APEI firmware first mode is enabled by APEI bit.\nL_28Failed to enable APEI firmware first mode.\nL_29Huang YingL_30APEI Generic Hardware Error Source supportL_31GPLL_32platform:GHES"
