static inline bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 . type == V_4 ;
}
static int F_2 ( void )
{
V_5 = F_3 ( V_6 * V_7 ,
V_8 , V_9 , V_10 ) ;
if ( ! V_5 ) {
F_4 ( V_11 L_1 ) ;
return - V_12 ;
}
return 0 ;
}
static void F_5 ( void )
{
F_6 ( V_5 ) ;
}
static void T_1 * F_7 ( T_2 V_13 )
{
unsigned long V_14 ;
T_3 V_15 ;
T_4 V_16 ;
V_14 = ( unsigned long ) F_8 ( V_5 -> V_17 ) ;
V_15 = V_13 << V_18 ;
V_16 = F_9 ( V_15 ) ;
F_10 ( V_14 , V_14 + V_6 , V_15 , V_16 ) ;
return ( void T_1 * ) V_14 ;
}
static void T_1 * F_11 ( T_2 V_13 )
{
unsigned long V_14 , V_15 ;
T_4 V_16 ;
V_14 = ( unsigned long ) F_12 ( V_5 -> V_17 ) ;
V_15 = V_13 << V_18 ;
V_16 = F_9 ( V_15 ) ;
F_10 ( V_14 , V_14 + V_6 , V_15 , V_16 ) ;
return ( void T_1 * ) V_14 ;
}
static void F_13 ( void T_1 * V_19 )
{
unsigned long V_14 = ( unsigned long V_20 ) V_19 ;
void * V_21 = V_5 -> V_17 ;
F_14 ( V_14 != ( unsigned long ) F_8 ( V_21 ) ) ;
F_15 ( V_14 , V_6 ) ;
F_16 ( V_14 ) ;
}
static void F_17 ( void T_1 * V_19 )
{
unsigned long V_14 = ( unsigned long V_20 ) V_19 ;
void * V_21 = V_5 -> V_17 ;
F_14 ( V_14 != ( unsigned long ) F_12 ( V_21 ) ) ;
F_15 ( V_14 , V_6 ) ;
F_16 ( V_14 ) ;
}
static int F_18 ( void )
{
V_22 = F_19 ( V_23 , - 1 ) ;
if ( ! V_22 )
return - V_12 ;
return 0 ;
}
static void F_20 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
void * V_28 )
{
F_21 ( V_27 -> V_29 ) ;
}
static void F_22 ( void )
{
F_23 ( V_22 ,
F_20 , NULL ) ;
F_24 ( V_22 ) ;
}
static int F_25 ( unsigned long V_30 )
{
unsigned long V_31 , V_32 , V_33 , V_17 ;
int V_34 ;
V_35 += F_26 ( V_30 ) ;
V_33 = F_27 ( V_22 ) ;
if ( V_33 >= V_35 )
return 0 ;
V_32 = ( V_35 - V_33 ) / V_6 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_17 = F_28 ( V_36 ) ;
if ( ! V_17 )
return - V_12 ;
V_34 = F_29 ( V_22 , V_17 , V_6 , - 1 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
return F_31 ( & V_1 -> V_37 -> V_38 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
F_33 ( & V_1 -> V_37 -> V_38 ) ;
}
static struct V_1 * F_34 ( struct V_39 * V_2 )
{
struct V_1 * V_1 ;
unsigned int V_40 ;
int V_41 ;
V_1 = F_35 ( sizeof( * V_1 ) , V_36 ) ;
if ( ! V_1 )
return F_36 ( - V_12 ) ;
V_1 -> V_2 = V_2 ;
if ( F_1 ( V_1 ) ) {
V_41 = F_30 ( V_1 ) ;
if ( V_41 )
goto V_42;
}
V_41 = F_31 ( & V_2 -> V_43 ) ;
if ( V_41 )
goto V_44;
V_40 = V_2 -> V_40 ;
if ( V_40 > V_45 ) {
F_37 (FW_WARN GHES_PFX
L_2
L_3 ,
error_block_length, generic->header.source_id) ;
V_40 = V_45 ;
}
V_1 -> V_46 = F_38 ( V_40 , V_36 ) ;
if ( ! V_1 -> V_46 ) {
V_41 = - V_12 ;
goto V_47;
}
return V_1 ;
V_47:
F_33 ( & V_2 -> V_43 ) ;
V_44:
if ( F_1 ( V_1 ) )
F_32 ( V_1 ) ;
V_42:
F_39 ( V_1 ) ;
return F_36 ( V_41 ) ;
}
static void F_40 ( struct V_1 * V_1 )
{
F_39 ( V_1 -> V_46 ) ;
F_33 ( & V_1 -> V_2 -> V_43 ) ;
if ( F_1 ( V_1 ) )
F_32 ( V_1 ) ;
}
static inline int F_41 ( int V_48 )
{
switch ( V_48 ) {
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
default:
return V_56 ;
}
}
static void F_42 ( void * V_57 , T_2 V_15 , T_5 V_30 ,
int V_58 )
{
void T_1 * V_14 ;
unsigned long V_59 = 0 ;
int V_60 = V_60 () ;
T_2 V_61 ;
T_5 V_62 ;
while ( V_30 > 0 ) {
V_61 = V_15 - ( V_15 & V_63 ) ;
if ( V_60 ) {
F_43 ( & V_64 ) ;
V_14 = F_7 ( V_15 >> V_18 ) ;
} else {
F_44 ( & V_65 , V_59 ) ;
V_14 = F_11 ( V_15 >> V_18 ) ;
}
V_62 = V_6 - V_61 ;
V_62 = F_45 ( V_62 , V_30 ) ;
if ( V_58 )
F_46 ( V_57 , V_14 + V_61 , V_62 ) ;
else
F_47 ( V_14 + V_61 , V_57 , V_62 ) ;
V_30 -= V_62 ;
V_15 += V_62 ;
V_57 += V_62 ;
if ( V_60 ) {
F_13 ( V_14 ) ;
F_48 ( & V_64 ) ;
} else {
F_17 ( V_14 ) ;
F_49 ( & V_65 , V_59 ) ;
}
}
}
static int F_50 ( struct V_1 * V_1 , int V_66 )
{
struct V_39 * V_67 = V_1 -> V_2 ;
T_2 V_68 ;
T_5 V_30 ;
int V_41 ;
V_41 = F_51 ( & V_68 , & V_67 -> V_43 ) ;
if ( V_41 ) {
if ( ! V_66 && F_52 () )
F_37 (FW_WARN GHES_PFX
L_4 ,
g->header.source_id) ;
return - V_69 ;
}
if ( ! V_68 )
return - V_70 ;
F_42 ( V_1 -> V_46 , V_68 ,
sizeof( * V_1 -> V_46 ) , 1 ) ;
if ( ! V_1 -> V_46 -> V_71 )
return - V_70 ;
V_1 -> V_72 = V_68 ;
V_1 -> V_59 |= V_73 ;
V_41 = - V_69 ;
V_30 = F_53 ( V_1 -> V_46 ) ;
if ( V_30 < sizeof( * V_1 -> V_46 ) )
goto V_74;
if ( V_30 > V_1 -> V_2 -> V_40 )
goto V_74;
if ( F_54 ( V_1 -> V_46 ) )
goto V_74;
F_42 ( V_1 -> V_46 + 1 ,
V_68 + sizeof( * V_1 -> V_46 ) ,
V_30 - sizeof( * V_1 -> V_46 ) , 1 ) ;
if ( F_55 ( V_1 -> V_46 ) )
goto V_74;
V_41 = 0 ;
V_74:
if ( V_41 && ! V_66 && F_52 () )
F_37 (FW_WARN GHES_PFX
L_5 ) ;
return V_41 ;
}
static void F_56 ( struct V_1 * V_1 )
{
V_1 -> V_46 -> V_71 = 0 ;
if ( ! ( V_1 -> V_59 & V_73 ) )
return;
F_42 ( V_1 -> V_46 , V_1 -> V_72 ,
sizeof( V_1 -> V_46 -> V_71 ) , 0 ) ;
V_1 -> V_59 &= ~ V_73 ;
}
static void F_57 ( struct V_75 * V_76 , int V_77 )
{
#ifdef F_58
unsigned long V_13 ;
int V_59 = - 1 ;
int V_78 = F_41 ( V_76 -> V_79 ) ;
struct V_80 * V_81 = F_59 ( V_76 ) ;
if ( ! ( V_81 -> V_82 & V_83 ) )
return;
V_13 = V_81 -> V_84 >> V_18 ;
if ( ! F_60 ( V_13 ) ) {
F_61 (FW_WARN GHES_PFX
L_6 ,
mem_err->physical_addr) ;
return;
}
if ( V_78 == V_52 &&
( V_76 -> V_59 & V_85 ) )
V_59 = V_86 ;
if ( V_77 == V_54 && V_78 == V_54 )
V_59 = 0 ;
if ( V_59 != - 1 )
F_62 ( V_13 , 0 , V_59 ) ;
#endif
}
static void F_63 ( struct V_1 * V_1 ,
const struct V_87 * V_46 )
{
int V_77 , V_78 ;
struct V_75 * V_76 ;
T_6 * V_88 ;
T_6 * V_89 = & V_90 ;
char * V_91 = L_7 ;
V_77 = F_41 ( V_46 -> V_79 ) ;
F_64 (estatus, gdata) {
V_88 = ( T_6 * ) V_76 -> V_92 ;
V_78 = F_41 ( V_76 -> V_79 ) ;
if ( V_76 -> V_82 & V_93 )
V_89 = ( T_6 * ) V_76 -> V_89 ;
if ( V_76 -> V_82 & V_94 )
V_91 = V_76 -> V_91 ;
if ( F_65 ( V_88 , & V_95 ) ) {
struct V_80 * V_81 = F_59 ( V_76 ) ;
F_66 ( V_1 , V_77 , V_81 ) ;
F_67 ( V_77 , V_81 ) ;
F_57 ( V_76 , V_77 ) ;
}
#ifdef F_68
else if ( F_65 ( V_88 , & V_96 ) ) {
struct V_97 * V_98 = F_59 ( V_76 ) ;
if ( V_77 == V_54 &&
V_78 == V_54 &&
V_98 -> V_82 & V_99 &&
V_98 -> V_82 & V_100 ) {
unsigned int V_101 ;
int V_102 ;
V_101 = F_69 ( V_98 -> V_103 . V_104 ,
V_98 -> V_103 . V_105 ) ;
V_102 = F_70 ( V_76 -> V_79 ) ;
if ( V_76 -> V_59 & V_106 )
V_102 = V_107 ;
F_71 ( V_98 -> V_103 . V_108 ,
V_98 -> V_103 . V_109 ,
V_101 , V_102 ,
(struct V_110 * )
V_98 -> V_111 ) ;
}
}
#endif
else if ( F_65 ( V_88 , & V_112 ) ) {
struct V_113 * V_114 = F_59 ( V_76 ) ;
F_72 ( V_114 ) ;
} else {
void * V_114 = F_59 ( V_76 ) ;
F_73 ( V_88 , V_89 , V_91 ,
V_78 , V_114 ,
V_76 -> V_115 ) ;
}
}
}
static void F_74 ( const char * V_116 ,
const struct V_39 * V_2 ,
const struct V_87 * V_46 )
{
static T_7 V_117 ;
unsigned int V_118 ;
char V_119 [ 64 ] ;
if ( V_116 == NULL ) {
if ( F_41 ( V_46 -> V_79 ) <=
V_52 )
V_116 = V_120 ;
else
V_116 = V_121 ;
}
V_118 = F_75 ( & V_117 ) ;
snprintf ( V_119 , sizeof( V_119 ) , L_8 V_122 , V_116 , V_118 ) ;
F_76 ( L_9Hardware error from APEI Generic Hardware Error Source: %d\nL_10Fatal hardware error!L_11Poll interval is 0 for generic hardware error source: %d, disabled.\nL_12ID: %d, trying to add SEA notification which is not supported\nL_13ID: %d, trying to remove SEA notification which is not supported\nL_14ghesL_15ghesL_16ID: %d, trying to add NMI notification which is not supported!\nL_17ID: %d, trying to remove NMI notification which is not supported!\nL_18Generic hardware error source: %d notified via SEA is not supported\nL_19Generic hardware error source: %d notified via NMI interrupt is not supported!\nL_20Generic hardware error source: %d notified via local interrupt is not supported!\nL_21Unknown notification type: %u for generic hardware error source: %d\nL_22Invalid error block length: %u for generic hardware error source: %d\nL_23Failed to map GSI to IRQ for generic hardware error source: %d\nL_24GHES IRQL_25Failed to register IRQ for generic hardware error source: %d\nL_26GHESL_27HEST is not enabled!\nL_28GHES is not enabled!\nL_29APEI firmware first mode is enabled by APEI bit and WHEA _OSC.\nL_30APEI firmware first mode is enabled by WHEA _OSC.\nL_31APEI firmware first mode is enabled by APEI bit.\nL_32Failed to enable APEI firmware first mode.\n"
