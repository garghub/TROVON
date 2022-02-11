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
unsigned long V_10 , V_14 ;
T_3 V_15 ;
V_10 = ( unsigned long ) F_10 ( V_1 -> V_11 ) ;
V_14 = V_9 << V_12 ;
V_15 = F_11 ( V_14 ) ;
F_8 ( V_10 , V_10 + V_2 , V_14 , V_15 ) ;
return ( void T_1 * ) V_10 ;
}
static void F_12 ( void T_1 * V_16 )
{
unsigned long V_10 = ( unsigned long V_17 ) V_16 ;
void * V_18 = V_1 -> V_11 ;
F_13 ( V_10 != ( unsigned long ) F_7 ( V_18 ) ) ;
F_14 ( V_10 , V_2 ) ;
F_15 ( V_10 ) ;
}
static void F_16 ( void T_1 * V_16 )
{
unsigned long V_10 = ( unsigned long V_17 ) V_16 ;
void * V_18 = V_1 -> V_11 ;
F_13 ( V_10 != ( unsigned long ) F_10 ( V_18 ) ) ;
F_14 ( V_10 , V_2 ) ;
F_15 ( V_10 ) ;
}
static int F_17 ( void )
{
V_19 = F_18 ( V_20 , - 1 ) ;
if ( ! V_19 )
return - V_8 ;
return 0 ;
}
static void F_19 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
void * V_25 )
{
F_20 ( V_24 -> V_26 ) ;
}
static void F_21 ( void )
{
F_22 ( V_19 ,
F_19 , NULL ) ;
F_23 ( V_19 ) ;
}
static int F_24 ( unsigned long V_27 )
{
unsigned long V_28 , V_29 , V_30 , V_11 ;
int V_31 ;
V_32 += F_25 ( V_27 ) ;
V_30 = F_26 ( V_19 ) ;
if ( V_30 >= V_32 )
return 0 ;
V_29 = ( V_32 - V_30 ) / V_2 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_11 = F_27 ( V_33 ) ;
if ( ! V_11 )
return - V_8 ;
V_31 = F_28 ( V_19 , V_11 , V_2 , - 1 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static struct V_34 * F_29 ( struct V_35 * V_36 )
{
struct V_34 * V_34 ;
unsigned int V_37 ;
int V_38 ;
V_34 = F_30 ( sizeof( * V_34 ) , V_33 ) ;
if ( ! V_34 )
return F_31 ( - V_8 ) ;
V_34 -> V_36 = V_36 ;
V_38 = F_32 ( & V_36 -> V_39 ) ;
if ( V_38 )
goto V_40;
V_37 = V_36 -> V_37 ;
if ( V_37 > V_41 ) {
F_33 (FW_WARN GHES_PFX
L_2
L_3 ,
error_block_length, generic->header.source_id) ;
V_37 = V_41 ;
}
V_34 -> V_42 = F_34 ( V_37 , V_33 ) ;
if ( ! V_34 -> V_42 ) {
V_38 = - V_8 ;
goto V_43;
}
return V_34 ;
V_43:
F_35 ( & V_36 -> V_39 ) ;
V_40:
F_36 ( V_34 ) ;
return F_31 ( V_38 ) ;
}
static void F_37 ( struct V_34 * V_34 )
{
F_36 ( V_34 -> V_42 ) ;
F_35 ( & V_34 -> V_36 -> V_39 ) ;
}
static inline int F_38 ( int V_44 )
{
switch ( V_44 ) {
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
default:
return V_52 ;
}
}
static void F_39 ( void * V_53 , T_2 V_14 , T_4 V_27 ,
int V_54 )
{
void T_1 * V_10 ;
unsigned long V_55 = 0 ;
int V_56 = V_56 () ;
T_2 V_57 ;
T_4 V_58 ;
while ( V_27 > 0 ) {
V_57 = V_14 - ( V_14 & V_59 ) ;
if ( V_56 ) {
F_40 ( & V_60 ) ;
V_10 = F_6 ( V_14 >> V_12 ) ;
} else {
F_41 ( & V_61 , V_55 ) ;
V_10 = F_9 ( V_14 >> V_12 ) ;
}
V_58 = V_2 - V_57 ;
V_58 = F_42 ( V_58 , V_27 ) ;
if ( V_54 )
F_43 ( V_53 , V_10 + V_57 , V_58 ) ;
else
F_44 ( V_10 + V_57 , V_53 , V_58 ) ;
V_27 -= V_58 ;
V_14 += V_58 ;
V_53 += V_58 ;
if ( V_56 ) {
F_12 ( V_10 ) ;
F_45 ( & V_60 ) ;
} else {
F_16 ( V_10 ) ;
F_46 ( & V_61 , V_55 ) ;
}
}
}
static int F_47 ( struct V_34 * V_34 , int V_62 )
{
struct V_35 * V_63 = V_34 -> V_36 ;
T_2 V_64 ;
T_4 V_27 ;
int V_38 ;
V_38 = F_48 ( & V_64 , & V_63 -> V_39 ) ;
if ( V_38 ) {
if ( ! V_62 && F_49 () )
F_33 (FW_WARN GHES_PFX
L_4 ,
g->header.source_id) ;
return - V_65 ;
}
if ( ! V_64 )
return - V_66 ;
F_39 ( V_34 -> V_42 , V_64 ,
sizeof( * V_34 -> V_42 ) , 1 ) ;
if ( ! V_34 -> V_42 -> V_67 )
return - V_66 ;
V_34 -> V_68 = V_64 ;
V_34 -> V_55 |= V_69 ;
V_38 = - V_65 ;
V_27 = F_50 ( V_34 -> V_42 ) ;
if ( V_27 < sizeof( * V_34 -> V_42 ) )
goto V_70;
if ( V_27 > V_34 -> V_36 -> V_37 )
goto V_70;
if ( F_51 ( V_34 -> V_42 ) )
goto V_70;
F_39 ( V_34 -> V_42 + 1 ,
V_64 + sizeof( * V_34 -> V_42 ) ,
V_27 - sizeof( * V_34 -> V_42 ) , 1 ) ;
if ( F_52 ( V_34 -> V_42 ) )
goto V_70;
V_38 = 0 ;
V_70:
if ( V_38 && ! V_62 && F_49 () )
F_33 (FW_WARN GHES_PFX
L_5 ) ;
return V_38 ;
}
static void F_53 ( struct V_34 * V_34 )
{
V_34 -> V_42 -> V_67 = 0 ;
if ( ! ( V_34 -> V_55 & V_69 ) )
return;
F_39 ( V_34 -> V_42 , V_34 -> V_68 ,
sizeof( V_34 -> V_42 -> V_67 ) , 0 ) ;
V_34 -> V_55 &= ~ V_69 ;
}
static void F_54 ( struct V_71 * V_72 , int V_73 )
{
#ifdef F_55
unsigned long V_9 ;
int V_55 = - 1 ;
int V_74 = F_38 ( V_72 -> V_75 ) ;
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) ( V_72 + 1 ) ;
if ( ! ( V_77 -> V_78 & V_79 ) )
return;
V_9 = V_77 -> V_80 >> V_12 ;
if ( ! F_56 ( V_9 ) ) {
F_57 (FW_WARN GHES_PFX
L_6 ,
mem_err->physical_addr) ;
return;
}
if ( V_74 == V_48 &&
( V_72 -> V_55 & V_81 ) )
V_55 = V_82 ;
if ( V_73 == V_50 && V_74 == V_50 )
V_55 = 0 ;
if ( V_55 != - 1 )
F_58 ( V_9 , 0 , V_55 ) ;
#endif
}
static void F_59 ( struct V_34 * V_34 ,
const struct V_83 * V_42 )
{
int V_73 , V_74 ;
struct V_71 * V_72 ;
V_73 = F_38 ( V_42 -> V_75 ) ;
F_60 (estatus, gdata) {
V_74 = F_38 ( V_72 -> V_75 ) ;
if ( ! F_61 ( * ( V_84 * ) V_72 -> V_85 ,
V_86 ) ) {
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) ( V_72 + 1 ) ;
F_62 ( V_34 , V_73 , V_77 ) ;
F_63 ( V_73 , V_77 ) ;
F_54 ( V_72 , V_73 ) ;
}
#ifdef F_64
else if ( ! F_61 ( * ( V_84 * ) V_72 -> V_85 ,
V_87 ) ) {
struct V_88 * V_89 ;
V_89 = (struct V_88 * ) ( V_72 + 1 ) ;
if ( V_73 == V_50 &&
V_74 == V_50 &&
V_89 -> V_78 & V_90 &&
V_89 -> V_78 & V_91 ) {
unsigned int V_92 ;
int V_93 ;
V_92 = F_65 ( V_89 -> V_94 . V_95 ,
V_89 -> V_94 . V_96 ) ;
V_93 = F_66 ( V_73 ) ;
if ( V_72 -> V_55 & V_97 )
V_93 = V_98 ;
F_67 ( V_89 -> V_94 . V_99 ,
V_89 -> V_94 . V_100 ,
V_92 , V_93 ,
(struct V_101 * )
V_89 -> V_102 ) ;
}
}
#endif
}
}
static void F_68 ( const char * V_103 ,
const struct V_35 * V_36 ,
const struct V_83 * V_42 )
{
static T_5 V_104 ;
unsigned int V_105 ;
char V_106 [ 64 ] ;
if ( V_103 == NULL ) {
if ( F_38 ( V_42 -> V_75 ) <=
V_48 )
V_103 = V_107 ;
else
V_103 = V_108 ;
}
V_105 = F_69 ( & V_104 ) ;
snprintf ( V_106 , sizeof( V_106 ) , L_7 V_109 , V_103 , V_105 ) ;
F_70 ( L_8Hardware error from APEI Generic Hardware Error Source: %d\nL_9Poll interval is 0 for generic hardware error source: %d, disabled.\nL_10Fatal hardware error!L_11ghesL_12ghesL_13ID: %d, trying to add NMI notification which is not supported!\nL_14ID: %d, trying to remove NMI notification which is not supported!\nL_15Generic hardware error source: %d notified via NMI interrupt is not supported!\nL_16Generic hardware error source: %d notified via local interrupt is not supported!\nL_17Unknown notification type: %u for generic hardware error source: %d\nL_18Invalid error block length: %u for generic hardware error source: %d\nL_19Failed to map GSI to IRQ for generic hardware error source: %d\nL_20GHES IRQL_21Failed to register IRQ for generic hardware error source: %d\nL_22GHESL_23HEST is not enabled!\nL_24GHES is not enabled!\nL_25APEI firmware first mode is enabled by APEI bit and WHEA _OSC.\nL_26APEI firmware first mode is enabled by WHEA _OSC.\nL_27APEI firmware first mode is enabled by APEI bit.\nL_28Failed to enable APEI firmware first mode.\nL_29Huang YingL_30APEI Generic Hardware Error Source supportL_31GPLL_32platform:GHES"
