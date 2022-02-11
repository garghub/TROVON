static void T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_4 , & V_5 ) ;
else
F_3 ( & V_2 -> V_4 , & V_5 ) ;
}
static int T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * * V_9 , T_2 V_10 )
{
struct V_11 * V_12 ;
struct V_8 * V_13 = NULL ;
struct V_14 * V_15 ;
int V_16 ;
V_12 = F_5 ( V_10 , V_7 -> V_12 ) ;
V_15 = (struct V_14 * ) ( V_7 + 1 ) ;
V_16 = ( V_7 -> V_17 - sizeof( struct V_6 ) )
/ sizeof( struct V_14 ) ;
while ( V_16 ) {
if ( V_13 )
F_6 ( V_13 ) ;
if ( ! V_12 ) {
F_7 (KERN_WARNING
PREFIX L_1 ,
scope->bus) ;
break;
}
V_13 = F_8 ( V_12 , F_9 ( V_15 -> V_9 , V_15 -> V_18 ) ) ;
if ( ! V_13 ) {
F_7 (KERN_WARNING PREFIX
L_2 ,
segment, bus->number, path->dev, path->fn) ;
break;
}
V_15 ++ ;
V_16 -- ;
V_12 = V_13 -> V_19 ;
}
if ( ! V_13 ) {
F_7 (KERN_WARNING PREFIX
L_2 ,
segment, scope->bus, path->dev, path->fn) ;
* V_9 = NULL ;
return 0 ;
}
if ( ( V_7 -> V_20 == V_21 && \
V_13 -> V_19 ) || ( V_7 -> V_20 == \
V_22 && ! V_13 -> V_19 ) ) {
F_6 ( V_13 ) ;
F_7 (KERN_WARNING PREFIX
L_3 ,
pci_name(pdev)) ;
return - V_23 ;
}
* V_9 = V_13 ;
return 0 ;
}
static int T_1 F_10 ( void * V_24 , void * V_25 , int * V_26 ,
struct V_8 * * * V_27 , T_2 V_10 )
{
struct V_6 * V_7 ;
void * V_28 = V_24 ;
int V_29 ;
int V_30 ;
* V_26 = 0 ;
while ( V_24 < V_25 ) {
V_7 = V_24 ;
if ( V_7 -> V_20 == V_21 ||
V_7 -> V_20 == V_22 )
( * V_26 ) ++ ;
else if ( V_7 -> V_20 != V_31 ) {
F_7 (KERN_WARNING PREFIX
L_4 ) ;
}
V_24 += V_7 -> V_17 ;
}
if ( * V_26 == 0 )
return 0 ;
* V_27 = F_11 ( * V_26 , sizeof( struct V_8 * ) , V_32 ) ;
if ( ! * V_27 )
return - V_33 ;
V_24 = V_28 ;
V_29 = 0 ;
while ( V_24 < V_25 ) {
V_7 = V_24 ;
if ( V_7 -> V_20 == V_21 ||
V_7 -> V_20 == V_22 ) {
V_30 = F_4 ( V_7 ,
& ( * V_27 ) [ V_29 ] , V_10 ) ;
if ( V_30 ) {
F_12 ( * V_27 ) ;
return V_30 ;
}
V_29 ++ ;
}
V_24 += V_7 -> V_17 ;
}
return 0 ;
}
static int T_1
F_13 ( struct V_34 * V_35 )
{
struct V_36 * V_2 ;
struct V_1 * V_37 ;
int V_30 = 0 ;
V_2 = (struct V_36 * ) V_35 ;
V_37 = F_14 ( sizeof( * V_37 ) , V_32 ) ;
if ( ! V_37 )
return - V_33 ;
V_37 -> V_38 = V_35 ;
V_37 -> V_39 = V_2 -> V_40 ;
V_37 -> V_10 = V_2 -> V_10 ;
V_37 -> V_3 = V_2 -> V_41 & 0x1 ;
V_30 = F_15 ( V_37 ) ;
if ( V_30 ) {
F_12 ( V_37 ) ;
return V_30 ;
}
F_1 ( V_37 ) ;
return 0 ;
}
static int T_1 F_16 ( struct V_1 * V_37 )
{
struct V_36 * V_2 ;
int V_30 = 0 ;
V_2 = (struct V_36 * ) V_37 -> V_38 ;
if ( V_37 -> V_3 )
return 0 ;
V_30 = F_10 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_35 . V_17 ,
& V_37 -> V_42 , & V_37 -> V_27 ,
V_2 -> V_10 ) ;
if ( V_30 ) {
F_17 ( & V_37 -> V_4 ) ;
F_12 ( V_37 ) ;
}
return V_30 ;
}
static void T_1 F_18 ( struct V_43 * V_44 )
{
F_3 ( & V_44 -> V_4 , & V_45 ) ;
}
static int T_1
F_19 ( struct V_34 * V_35 )
{
struct V_46 * V_44 ;
struct V_43 * V_47 ;
V_47 = F_14 ( sizeof( * V_47 ) , V_32 ) ;
if ( ! V_47 )
return - V_33 ;
V_47 -> V_38 = V_35 ;
V_44 = (struct V_46 * ) V_35 ;
V_47 -> V_48 = V_44 -> V_48 ;
V_47 -> V_49 = V_44 -> V_49 ;
F_18 ( V_47 ) ;
return 0 ;
}
static int T_1
F_20 ( struct V_43 * V_47 )
{
struct V_46 * V_44 ;
int V_30 ;
V_44 = (struct V_46 * ) V_47 -> V_38 ;
V_30 = F_10 ( ( void * ) ( V_44 + 1 ) ,
( ( void * ) V_44 ) + V_44 -> V_35 . V_17 ,
& V_47 -> V_42 , & V_47 -> V_27 , V_44 -> V_10 ) ;
if ( V_30 || ( V_47 -> V_42 == 0 ) ) {
F_17 ( & V_47 -> V_4 ) ;
F_12 ( V_47 ) ;
}
return V_30 ;
}
static int T_1 F_21 ( struct V_34 * V_38 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = F_22 ( V_38 , struct V_50 , V_35 ) ;
V_53 = F_14 ( sizeof( * V_53 ) , V_32 ) ;
if ( ! V_53 )
return - V_33 ;
V_53 -> V_38 = V_38 ;
V_53 -> V_3 = V_51 -> V_41 & 0x1 ;
F_3 ( & V_53 -> V_4 , & V_54 ) ;
return 0 ;
}
static int T_1 F_23 ( struct V_52 * V_53 )
{
int V_55 ;
struct V_50 * V_51 ;
if ( V_53 -> V_3 )
return 0 ;
V_51 = F_22 ( V_53 -> V_38 , struct V_50 , V_35 ) ;
V_55 = F_10 ( ( void * ) ( V_51 + 1 ) ,
( void * ) V_51 + V_51 -> V_35 . V_17 ,
& V_53 -> V_42 , & V_53 -> V_27 ,
V_51 -> V_10 ) ;
if ( V_55 || ! V_53 -> V_42 ) {
F_17 ( & V_53 -> V_4 ) ;
F_12 ( V_53 ) ;
}
return V_55 ;
}
int F_24 ( struct V_8 * V_9 )
{
int V_56 ;
struct V_11 * V_12 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_9 = F_25 ( V_9 ) ;
F_26 (atsru, &dmar_atsr_units, list) {
V_51 = F_22 ( V_53 -> V_38 , struct V_50 , V_35 ) ;
if ( V_51 -> V_10 == F_27 ( V_9 -> V_12 ) )
goto V_57;
}
return 0 ;
V_57:
for ( V_12 = V_9 -> V_12 ; V_12 ; V_12 = V_12 -> V_58 ) {
struct V_8 * V_59 = V_12 -> V_60 ;
if ( ! V_59 || ! F_28 ( V_59 ) ||
V_59 -> V_61 == V_62 )
return 0 ;
if ( V_59 -> V_61 == V_63 ) {
for ( V_56 = 0 ; V_56 < V_53 -> V_42 ; V_56 ++ )
if ( V_53 -> V_27 [ V_56 ] == V_59 )
return 1 ;
break;
}
}
if ( V_53 -> V_3 )
return 1 ;
return 0 ;
}
static int T_1
F_29 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
V_65 = (struct V_64 * ) V_35 ;
F_30 (drhd) {
if ( V_2 -> V_39 == V_65 -> V_48 ) {
int V_66 = F_31 ( V_65 -> V_67 ) ;
if ( ! F_32 ( V_66 ) )
V_66 = - 1 ;
V_2 -> V_68 -> V_66 = V_66 ;
return 0 ;
}
}
F_33 (
1 , V_69 ,
L_5
L_6 ,
V_2 -> V_39 ,
F_34 ( V_70 ) ,
F_34 ( V_71 ) ,
F_34 ( V_72 ) ) ;
return 0 ;
}
static void T_1
F_35 ( struct V_34 * V_35 )
{
struct V_36 * V_2 ;
struct V_46 * V_44 ;
struct V_50 * V_51 ;
struct V_64 * V_65 ;
switch ( V_35 -> type ) {
case V_73 :
V_2 = F_22 ( V_35 , struct V_36 ,
V_35 ) ;
F_7 (KERN_INFO PREFIX
L_7 ,
(unsigned long long)drhd->address, drhd->flags) ;
break;
case V_74 :
V_44 = F_22 ( V_35 , struct V_46 ,
V_35 ) ;
F_7 (KERN_INFO PREFIX
L_8 ,
(unsigned long long)rmrr->base_address,
(unsigned long long)rmrr->end_address) ;
break;
case V_75 :
V_51 = F_22 ( V_35 , struct V_50 , V_35 ) ;
F_7 (KERN_INFO PREFIX L_9 , atsr->flags) ;
break;
case V_76 :
V_65 = F_22 ( V_35 , struct V_64 , V_35 ) ;
F_7 (KERN_INFO PREFIX L_10 ,
(unsigned long long)rhsa->base_address,
rhsa->proximity_domain) ;
break;
}
}
static int T_1 F_36 ( void )
{
T_3 V_77 = V_78 ;
V_77 = F_37 ( V_79 , 0 ,
(struct V_80 * * ) & V_81 ,
& V_82 ) ;
if ( F_38 ( V_77 ) && ! V_81 ) {
F_7 (KERN_WARNING PREFIX L_11 ) ;
V_77 = V_83 ;
}
return ( F_38 ( V_77 ) ? 1 : 0 ) ;
}
static int T_1
F_39 ( void )
{
struct V_84 * V_85 ;
struct V_34 * V_86 ;
int V_30 = 0 ;
F_36 () ;
V_81 = F_40 ( V_81 ) ;
V_85 = (struct V_84 * ) V_81 ;
if ( ! V_85 )
return - V_87 ;
if ( V_85 -> V_88 < V_89 - 1 ) {
F_7 (KERN_WARNING PREFIX L_12 ) ;
return - V_23 ;
}
F_7 (KERN_INFO PREFIX L_13 ,
dmar->width + 1 ) ;
V_86 = (struct V_34 * ) ( V_85 + 1 ) ;
while ( ( ( unsigned long ) V_86 ) <
( ( ( unsigned long ) V_85 ) + V_81 -> V_17 ) ) {
if ( V_86 -> V_17 == 0 ) {
F_7 (KERN_WARNING PREFIX
L_14 ) ;
V_30 = - V_23 ;
break;
}
F_35 ( V_86 ) ;
switch ( V_86 -> type ) {
case V_73 :
V_30 = F_13 ( V_86 ) ;
break;
case V_74 :
#ifdef F_41
V_30 = F_19 ( V_86 ) ;
#endif
break;
case V_75 :
#ifdef F_41
V_30 = F_21 ( V_86 ) ;
#endif
break;
case V_76 :
#ifdef F_42
V_30 = F_29 ( V_86 ) ;
#endif
break;
default:
F_7 (KERN_WARNING PREFIX
L_15 ,
entry_header->type) ;
V_30 = 0 ;
break;
}
if ( V_30 )
break;
V_86 = ( ( void * ) V_86 + V_86 -> V_17 ) ;
}
return V_30 ;
}
static int F_43 ( struct V_8 * V_27 [] , int V_26 ,
struct V_8 * V_9 )
{
int V_29 ;
while ( V_9 ) {
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ )
if ( V_9 == V_27 [ V_29 ] )
return 1 ;
V_9 = V_9 -> V_12 -> V_60 ;
}
return 0 ;
}
struct V_1 *
F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_37 = NULL ;
struct V_36 * V_2 ;
V_9 = F_25 ( V_9 ) ;
F_26 (dmaru, &dmar_drhd_units, list) {
V_2 = F_22 ( V_37 -> V_38 ,
struct V_36 ,
V_35 ) ;
if ( V_37 -> V_3 &&
V_2 -> V_10 == F_27 ( V_9 -> V_12 ) )
return V_37 ;
if ( F_43 ( V_37 -> V_27 ,
V_37 -> V_42 , V_9 ) )
return V_37 ;
}
return NULL ;
}
int T_1 F_45 ( void )
{
struct V_1 * V_2 , * V_90 ;
int V_30 = - V_87 ;
F_46 (drhd, drhd_n, &dmar_drhd_units, list) {
V_30 = F_16 ( V_2 ) ;
if ( V_30 )
return V_30 ;
}
#ifdef F_41
{
struct V_43 * V_44 , * V_91 ;
struct V_52 * V_51 , * V_92 ;
F_46 (rmrr, rmrr_n, &dmar_rmrr_units, list) {
V_30 = F_20 ( V_44 ) ;
if ( V_30 )
return V_30 ;
}
F_46 (atsr, atsr_n, &dmar_atsr_units, list) {
V_30 = F_23 ( V_51 ) ;
if ( V_30 )
return V_30 ;
}
}
#endif
return V_30 ;
}
int T_1 F_47 ( void )
{
static int V_93 ;
int V_30 ;
if ( V_93 )
return 0 ;
V_93 = 1 ;
V_30 = F_39 () ;
if ( V_30 ) {
if ( V_30 != - V_87 )
F_7 (KERN_INFO PREFIX L_16 ) ;
return V_30 ;
}
if ( F_48 ( & V_5 ) ) {
F_7 (KERN_INFO PREFIX L_17 ) ;
return - V_87 ;
}
#ifdef F_41
if ( F_48 ( & V_45 ) )
F_7 (KERN_INFO PREFIX L_18 ) ;
if ( F_48 ( & V_54 ) )
F_7 (KERN_INFO PREFIX L_19 ) ;
#endif
return 0 ;
}
static void F_49 ( T_4 V_94 , const char * V_95 )
{
F_50 (
1 , V_69 ,
L_20
L_6 ,
V_94 , V_95 ,
F_34 ( V_70 ) ,
F_34 ( V_71 ) ,
F_34 ( V_72 ) ) ;
}
int T_1 F_51 ( void )
{
struct V_84 * V_85 ;
struct V_34 * V_86 ;
struct V_36 * V_2 ;
V_85 = (struct V_84 * ) V_81 ;
V_86 = (struct V_34 * ) ( V_85 + 1 ) ;
while ( ( ( unsigned long ) V_86 ) <
( ( ( unsigned long ) V_85 ) + V_81 -> V_17 ) ) {
if ( V_86 -> V_17 == 0 ) {
F_7 (KERN_WARNING PREFIX
L_14 ) ;
return 0 ;
}
if ( V_86 -> type == V_73 ) {
void T_5 * V_94 ;
T_4 V_96 , V_97 ;
V_2 = ( void * ) V_86 ;
if ( ! V_2 -> V_40 ) {
F_49 ( 0 , L_21 ) ;
goto V_98;
}
V_94 = F_52 ( V_2 -> V_40 , V_99 ) ;
if ( ! V_94 ) {
F_7 ( L_22 , V_2 -> V_40 ) ;
goto V_98;
}
V_96 = F_53 ( V_94 + V_100 ) ;
V_97 = F_53 ( V_94 + V_101 ) ;
F_54 ( V_94 , V_99 ) ;
if ( V_96 == ( V_102 ) - 1 && V_97 == ( V_102 ) - 1 ) {
F_49 ( V_2 -> V_40 ,
L_23 ) ;
goto V_98;
}
}
V_86 = ( ( void * ) V_86 + V_86 -> V_17 ) ;
}
return 1 ;
V_98:
#ifdef F_41
V_103 = 1 ;
#endif
return 0 ;
}
int T_1 F_55 ( void )
{
int V_30 ;
V_30 = F_36 () ;
if ( V_30 )
V_30 = F_51 () ;
{
#ifdef F_56
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) V_81 ;
if ( V_30 && V_104 && V_85 -> V_41 & 0x1 )
F_7 ( V_105
L_24
L_25 ) ;
#endif
#ifdef F_41
if ( V_30 && ! V_106 && ! V_107 && ! V_103 ) {
V_107 = 1 ;
F_57 () ;
}
#endif
#ifdef F_58
if ( V_30 )
V_108 . V_68 . V_109 = V_110 ;
#endif
}
F_59 ( V_81 , V_82 ) ;
V_81 = NULL ;
return V_30 ? 1 : - V_87 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_111 * V_68 ;
int V_112 ;
T_6 V_113 ;
static int V_114 = 0 ;
int V_115 = 0 ;
int V_116 = 0 ;
if ( ! V_2 -> V_39 ) {
F_49 ( 0 , L_21 ) ;
return - V_23 ;
}
V_68 = F_14 ( sizeof( * V_68 ) , V_32 ) ;
if ( ! V_68 )
return - V_33 ;
V_68 -> V_117 = V_114 ++ ;
sprintf ( V_68 -> V_118 , L_26 , V_68 -> V_117 ) ;
V_68 -> V_119 = F_60 ( V_2 -> V_39 , V_99 ) ;
if ( ! V_68 -> V_119 ) {
F_7 ( V_120 L_27 ) ;
goto error;
}
V_68 -> V_96 = F_53 ( V_68 -> V_119 + V_100 ) ;
V_68 -> V_97 = F_53 ( V_68 -> V_119 + V_101 ) ;
if ( V_68 -> V_96 == ( V_102 ) - 1 && V_68 -> V_97 == ( V_102 ) - 1 ) {
F_49 ( V_2 -> V_39 , L_23 ) ;
goto V_121;
}
#ifdef F_41
V_115 = F_61 ( V_68 ) ;
if ( V_115 < 0 ) {
F_7 ( V_120
L_28 ,
V_68 -> V_117 ) ;
goto V_121;
}
V_116 = F_62 ( V_68 ) ;
if ( V_116 < 0 ) {
F_7 ( V_120
L_29 ,
V_68 -> V_117 ) ;
goto V_121;
}
#endif
V_68 -> V_115 = V_115 ;
V_68 -> V_116 = V_116 ;
V_68 -> V_66 = - 1 ;
V_112 = F_63 ( int , F_64 ( V_68 -> V_97 ) ,
F_65 ( V_68 -> V_96 ) ) ;
V_112 = F_66 ( V_112 ) ;
if ( V_112 > V_99 ) {
F_67 ( V_68 -> V_119 ) ;
V_68 -> V_119 = F_60 ( V_2 -> V_39 , V_112 ) ;
if ( ! V_68 -> V_119 ) {
F_7 ( V_120 L_27 ) ;
goto error;
}
}
V_113 = F_68 ( V_68 -> V_119 + V_122 ) ;
F_69 ( L_30 ,
V_68 -> V_117 ,
( unsigned long long ) V_2 -> V_39 ,
F_70 ( V_113 ) , F_71 ( V_113 ) ,
( unsigned long long ) V_68 -> V_96 ,
( unsigned long long ) V_68 -> V_97 ) ;
F_72 ( & V_68 -> V_123 ) ;
V_2 -> V_68 = V_68 ;
return 0 ;
V_121:
F_67 ( V_68 -> V_119 ) ;
error:
F_12 ( V_68 ) ;
return - 1 ;
}
void F_73 ( struct V_111 * V_68 )
{
if ( ! V_68 )
return;
#ifdef F_41
F_74 ( V_68 ) ;
#endif
if ( V_68 -> V_119 )
F_67 ( V_68 -> V_119 ) ;
F_12 ( V_68 ) ;
}
static inline void F_75 ( struct V_124 * V_125 )
{
while ( V_125 -> V_126 [ V_125 -> V_127 ] == V_128 ||
V_125 -> V_126 [ V_125 -> V_127 ] == V_129 ) {
V_125 -> V_126 [ V_125 -> V_127 ] = V_130 ;
V_125 -> V_127 = ( V_125 -> V_127 + 1 ) % V_131 ;
V_125 -> V_132 ++ ;
}
}
static int F_76 ( struct V_111 * V_68 , int V_29 )
{
T_6 V_133 ;
int V_134 , V_135 ;
struct V_124 * V_125 = V_68 -> V_125 ;
int V_136 = ( V_29 + 1 ) % V_131 ;
if ( V_125 -> V_126 [ V_136 ] == V_129 )
return - V_137 ;
V_133 = F_68 ( V_68 -> V_119 + V_138 ) ;
if ( V_133 & V_139 ) {
V_134 = F_68 ( V_68 -> V_119 + V_140 ) ;
if ( ( V_134 >> V_141 ) == V_29 ) {
F_7 ( V_120 L_31
L_32 ,
( unsigned long long ) V_125 -> V_142 [ V_29 ] . V_143 ,
( unsigned long long ) V_125 -> V_142 [ V_29 ] . V_144 ) ;
memcpy ( & V_125 -> V_142 [ V_29 ] , & V_125 -> V_142 [ V_136 ] ,
sizeof( struct V_145 ) ) ;
F_77 ( V_68 , & V_125 -> V_142 [ V_29 ] ,
sizeof( struct V_145 ) ) ;
F_78 ( V_139 , V_68 -> V_119 + V_138 ) ;
return - V_23 ;
}
}
if ( V_133 & V_146 ) {
V_134 = F_68 ( V_68 -> V_119 + V_140 ) ;
V_134 = ( ( V_134 >> V_141 ) - 1 + V_131 ) % V_131 ;
V_134 |= 1 ;
V_135 = F_68 ( V_68 -> V_119 + V_147 ) ;
V_135 = ( ( V_135 >> V_141 ) - 1 + V_131 ) % V_131 ;
F_78 ( V_146 , V_68 -> V_119 + V_138 ) ;
do {
if ( V_125 -> V_126 [ V_134 ] == V_148 )
V_125 -> V_126 [ V_134 ] = V_129 ;
V_134 = ( V_134 - 2 + V_131 ) % V_131 ;
} while ( V_134 != V_135 );
if ( V_125 -> V_126 [ V_136 ] == V_129 )
return - V_137 ;
}
if ( V_133 & V_149 )
F_78 ( V_149 , V_68 -> V_119 + V_138 ) ;
return 0 ;
}
int F_79 ( struct V_145 * V_142 , struct V_111 * V_68 )
{
int V_55 ;
struct V_124 * V_125 = V_68 -> V_125 ;
struct V_145 * V_150 , V_151 ;
int V_136 , V_29 ;
unsigned long V_41 ;
if ( ! V_125 )
return 0 ;
V_150 = V_125 -> V_142 ;
V_152:
V_55 = 0 ;
F_80 ( & V_125 -> V_153 , V_41 ) ;
while ( V_125 -> V_132 < 3 ) {
F_81 ( & V_125 -> V_153 , V_41 ) ;
F_82 () ;
F_80 ( & V_125 -> V_153 , V_41 ) ;
}
V_29 = V_125 -> V_154 ;
V_136 = ( V_29 + 1 ) % V_131 ;
V_125 -> V_126 [ V_29 ] = V_125 -> V_126 [ V_136 ] = V_148 ;
V_150 [ V_29 ] = * V_142 ;
V_151 . V_143 = F_83 ( V_128 ) |
V_155 | V_156 ;
V_151 . V_144 = F_84 ( & V_125 -> V_126 [ V_136 ] ) ;
V_150 [ V_136 ] = V_151 ;
F_77 ( V_68 , & V_150 [ V_29 ] , sizeof( struct V_145 ) ) ;
F_77 ( V_68 , & V_150 [ V_136 ] , sizeof( struct V_145 ) ) ;
V_125 -> V_154 = ( V_125 -> V_154 + 2 ) % V_131 ;
V_125 -> V_132 -= 2 ;
F_78 ( V_125 -> V_154 << V_141 , V_68 -> V_119 + V_147 ) ;
while ( V_125 -> V_126 [ V_136 ] != V_128 ) {
V_55 = F_76 ( V_68 , V_29 ) ;
if ( V_55 )
break;
F_85 ( & V_125 -> V_153 ) ;
F_82 () ;
F_86 ( & V_125 -> V_153 ) ;
}
V_125 -> V_126 [ V_29 ] = V_128 ;
F_75 ( V_125 ) ;
F_81 ( & V_125 -> V_153 , V_41 ) ;
if ( V_55 == - V_137 )
goto V_152;
return V_55 ;
}
void F_87 ( struct V_111 * V_68 )
{
struct V_145 V_142 ;
V_142 . V_143 = V_157 ;
V_142 . V_144 = 0 ;
F_79 ( & V_142 , V_68 ) ;
}
void F_88 ( struct V_111 * V_68 , T_2 V_158 , T_2 V_159 , T_7 V_160 ,
T_4 type )
{
struct V_145 V_142 ;
V_142 . V_143 = F_89 ( V_160 ) | F_90 ( V_159 ) | F_91 ( V_158 )
| F_92 ( type ) | V_161 ;
V_142 . V_144 = 0 ;
F_79 ( & V_142 , V_68 ) ;
}
void F_93 ( struct V_111 * V_68 , T_2 V_158 , T_4 V_94 ,
unsigned int V_162 , T_4 type )
{
T_7 V_163 = 0 , V_164 = 0 ;
struct V_145 V_142 ;
int V_165 = 0 ;
if ( F_94 ( V_68 -> V_96 ) )
V_163 = 1 ;
if ( F_95 ( V_68 -> V_96 ) )
V_164 = 1 ;
V_142 . V_143 = F_96 ( V_158 ) | F_97 ( V_164 ) | F_98 ( V_163 )
| F_99 ( type ) | V_166 ;
V_142 . V_144 = F_100 ( V_94 ) | F_101 ( V_165 )
| F_102 ( V_162 ) ;
F_79 ( & V_142 , V_68 ) ;
}
void F_103 ( struct V_111 * V_68 , T_2 V_159 , T_2 V_167 ,
T_4 V_94 , unsigned V_168 )
{
struct V_145 V_142 ;
if ( V_168 ) {
F_104 ( V_94 & ( ( 1 << ( V_169 + V_168 ) ) - 1 ) ) ;
V_94 |= ( 1 << ( V_169 + V_168 - 1 ) ) - 1 ;
V_142 . V_144 = F_105 ( V_94 ) | V_170 ;
} else
V_142 . V_144 = F_105 ( V_94 ) ;
if ( V_167 >= V_171 )
V_167 = 0 ;
V_142 . V_143 = F_106 ( V_159 ) | F_107 ( V_167 ) |
V_172 ;
F_79 ( & V_142 , V_68 ) ;
}
void F_108 ( struct V_111 * V_68 )
{
unsigned long V_41 ;
T_6 V_173 ;
T_8 V_174 = F_109 () ;
if ( ! F_110 ( V_68 -> V_97 ) )
return;
F_80 ( & V_68 -> V_123 , V_41 ) ;
V_173 = F_53 ( V_68 -> V_119 + V_175 ) ;
if ( ! ( V_173 & V_176 ) )
goto V_25;
while ( ( F_68 ( V_68 -> V_119 + V_147 ) !=
F_68 ( V_68 -> V_119 + V_140 ) ) &&
( V_177 > ( F_109 () - V_174 ) ) )
F_82 () ;
V_68 -> V_178 &= ~ V_179 ;
F_78 ( V_68 -> V_178 , V_68 -> V_119 + V_180 ) ;
F_111 ( V_68 , V_175 , F_68 ,
! ( V_173 & V_176 ) , V_173 ) ;
V_25:
F_81 ( & V_68 -> V_123 , V_41 ) ;
}
static void F_112 ( struct V_111 * V_68 )
{
T_6 V_173 ;
unsigned long V_41 ;
struct V_124 * V_125 = V_68 -> V_125 ;
V_125 -> V_154 = V_125 -> V_127 = 0 ;
V_125 -> V_132 = V_131 ;
F_80 ( & V_68 -> V_123 , V_41 ) ;
F_78 ( 0 , V_68 -> V_119 + V_147 ) ;
F_113 ( V_68 -> V_119 + V_181 , F_84 ( V_125 -> V_142 ) ) ;
V_68 -> V_178 |= V_179 ;
F_78 ( V_68 -> V_178 , V_68 -> V_119 + V_180 ) ;
F_111 ( V_68 , V_175 , F_68 , ( V_173 & V_176 ) , V_173 ) ;
F_81 ( & V_68 -> V_123 , V_41 ) ;
}
int F_114 ( struct V_111 * V_68 )
{
struct V_124 * V_125 ;
struct V_182 * V_183 ;
if ( ! F_110 ( V_68 -> V_97 ) )
return - V_184 ;
if ( V_68 -> V_125 )
return 0 ;
V_68 -> V_125 = F_115 ( sizeof( * V_125 ) , V_185 ) ;
if ( ! V_68 -> V_125 )
return - V_33 ;
V_125 = V_68 -> V_125 ;
V_183 = F_116 ( V_68 -> V_66 , V_185 | V_186 , 0 ) ;
if ( ! V_183 ) {
F_12 ( V_125 ) ;
V_68 -> V_125 = 0 ;
return - V_33 ;
}
V_125 -> V_142 = F_117 ( V_183 ) ;
V_125 -> V_126 = F_115 ( V_131 * sizeof( int ) , V_185 ) ;
if ( ! V_125 -> V_126 ) {
F_118 ( ( unsigned long ) V_125 -> V_142 ) ;
F_12 ( V_125 ) ;
V_68 -> V_125 = 0 ;
return - V_33 ;
}
V_125 -> V_154 = V_125 -> V_127 = 0 ;
V_125 -> V_132 = V_131 ;
F_72 ( & V_125 -> V_153 ) ;
F_112 ( V_68 ) ;
return 0 ;
}
const char * F_119 ( T_7 V_187 , int * V_188 )
{
if ( V_187 >= 0x20 && ( V_187 <= 0x20 +
F_120 ( V_189 ) ) ) {
* V_188 = V_190 ;
return V_189 [ V_187 - 0x20 ] ;
} else if ( V_187 < F_120 ( V_191 ) ) {
* V_188 = V_192 ;
return V_191 [ V_187 ] ;
} else {
* V_188 = V_193 ;
return L_33 ;
}
}
void F_121 ( struct V_194 * V_195 )
{
struct V_111 * V_68 = F_122 ( V_195 ) ;
unsigned long V_196 ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
F_78 ( 0 , V_68 -> V_119 + V_197 ) ;
F_68 ( V_68 -> V_119 + V_197 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
}
void F_123 ( struct V_194 * V_195 )
{
unsigned long V_196 ;
struct V_111 * V_68 = F_122 ( V_195 ) ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
F_78 ( V_198 , V_68 -> V_119 + V_197 ) ;
F_68 ( V_68 -> V_119 + V_197 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
}
void F_124 ( int V_199 , struct V_200 * V_201 )
{
struct V_111 * V_68 = F_125 ( V_199 ) ;
unsigned long V_196 ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
F_78 ( V_201 -> V_195 , V_68 -> V_119 + V_202 ) ;
F_78 ( V_201 -> V_203 , V_68 -> V_119 + V_204 ) ;
F_78 ( V_201 -> V_205 , V_68 -> V_119 + V_206 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
}
void F_126 ( int V_199 , struct V_200 * V_201 )
{
struct V_111 * V_68 = F_125 ( V_199 ) ;
unsigned long V_196 ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
V_201 -> V_195 = F_68 ( V_68 -> V_119 + V_202 ) ;
V_201 -> V_203 = F_68 ( V_68 -> V_119 + V_204 ) ;
V_201 -> V_205 = F_68 ( V_68 -> V_119 + V_206 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
}
static int F_127 ( struct V_111 * V_68 , int type ,
T_7 V_187 , T_2 V_207 , unsigned long long V_94 )
{
const char * V_208 ;
int V_188 ;
V_208 = F_119 ( V_187 , & V_188 ) ;
if ( V_188 == V_190 )
F_7 ( V_120 L_34
L_35
L_36 ,
( V_207 >> 8 ) , F_128 ( V_207 & 0xFF ) ,
F_129 ( V_207 & 0xFF ) , V_94 >> 48 ,
V_187 , V_208 ) ;
else
F_7 ( V_120
L_37
L_38
L_39 ,
( type ? L_40 : L_41 ) ,
( V_207 >> 8 ) , F_128 ( V_207 & 0xFF ) ,
F_129 ( V_207 & 0xFF ) , V_94 , V_187 , V_208 ) ;
return 0 ;
}
T_9 F_130 ( int V_199 , void * V_209 )
{
struct V_111 * V_68 = V_209 ;
int V_119 , V_210 ;
T_6 V_211 ;
unsigned long V_196 ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
V_211 = F_68 ( V_68 -> V_119 + V_138 ) ;
if ( V_211 )
F_7 ( V_120 L_42 ,
V_211 ) ;
if ( ! ( V_211 & V_212 ) )
goto V_213;
V_210 = F_131 ( V_211 ) ;
V_119 = F_132 ( V_68 -> V_96 ) ;
while ( 1 ) {
T_7 V_187 ;
T_2 V_207 ;
T_4 V_214 ;
int type ;
T_6 V_195 ;
V_195 = F_68 ( V_68 -> V_119 + V_119 +
V_210 * V_215 + 12 ) ;
if ( ! ( V_195 & V_216 ) )
break;
V_187 = F_133 ( V_195 ) ;
type = F_134 ( V_195 ) ;
V_195 = F_68 ( V_68 -> V_119 + V_119 +
V_210 * V_215 + 8 ) ;
V_207 = F_135 ( V_195 ) ;
V_214 = F_53 ( V_68 -> V_119 + V_119 +
V_210 * V_215 ) ;
V_214 = F_136 ( V_214 ) ;
F_78 ( V_216 , V_68 -> V_119 + V_119 +
V_210 * V_215 + 12 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
F_127 ( V_68 , type , V_187 ,
V_207 , V_214 ) ;
V_210 ++ ;
if ( V_210 >= F_137 ( V_68 -> V_96 ) )
V_210 = 0 ;
F_80 ( & V_68 -> V_123 , V_196 ) ;
}
V_213:
V_211 = F_68 ( V_68 -> V_119 + V_138 ) ;
F_78 ( V_211 , V_68 -> V_119 + V_138 ) ;
F_81 ( & V_68 -> V_123 , V_196 ) ;
return V_217 ;
}
int F_138 ( struct V_111 * V_68 )
{
int V_199 , V_30 ;
if ( V_68 -> V_199 )
return 0 ;
V_199 = F_139 () ;
if ( ! V_199 ) {
F_7 ( V_120 L_43 ) ;
return - V_23 ;
}
F_140 ( V_199 , V_68 ) ;
V_68 -> V_199 = V_199 ;
V_30 = F_141 ( V_199 ) ;
if ( V_30 ) {
F_140 ( V_199 , NULL ) ;
V_68 -> V_199 = 0 ;
F_142 ( V_199 ) ;
return V_30 ;
}
V_30 = F_143 ( V_199 , F_130 , 0 , V_68 -> V_118 , V_68 ) ;
if ( V_30 )
F_7 ( V_120 L_44 ) ;
return V_30 ;
}
int T_1 F_144 ( void )
{
struct V_1 * V_2 ;
F_30 (drhd) {
int V_30 ;
struct V_111 * V_68 = V_2 -> V_68 ;
V_30 = F_138 ( V_68 ) ;
if ( V_30 ) {
F_7 ( V_120 L_45
L_46 ,
( unsigned long long ) V_2 -> V_39 , V_30 ) ;
return - 1 ;
}
F_130 ( V_68 -> V_199 , V_68 ) ;
}
return 0 ;
}
int F_145 ( struct V_111 * V_68 )
{
if ( ! F_110 ( V_68 -> V_97 ) )
return - V_184 ;
if ( ! V_68 -> V_125 )
return - V_184 ;
F_108 ( V_68 ) ;
F_112 ( V_68 ) ;
return 0 ;
}
int T_1 F_146 ( void )
{
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) V_81 ;
if ( ! V_85 )
return 0 ;
return V_85 -> V_41 & 0x1 ;
}
