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
int T_1 F_10 ( void * V_24 , void * V_25 , int * V_26 ,
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
static int T_1
F_18 ( struct V_34 * V_35 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
V_44 = (struct V_43 * ) V_35 ;
F_19 (drhd) {
if ( V_2 -> V_39 == V_44 -> V_45 ) {
int V_46 = F_20 ( V_44 -> V_47 ) ;
if ( ! F_21 ( V_46 ) )
V_46 = - 1 ;
V_2 -> V_48 -> V_46 = V_46 ;
return 0 ;
}
}
F_22 (
1 , V_49 ,
L_5
L_6 ,
V_2 -> V_39 ,
F_23 ( V_50 ) ,
F_23 ( V_51 ) ,
F_23 ( V_52 ) ) ;
return 0 ;
}
static void T_1
F_24 ( struct V_34 * V_35 )
{
struct V_36 * V_2 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_43 * V_44 ;
switch ( V_35 -> type ) {
case V_57 :
V_2 = F_25 ( V_35 , struct V_36 ,
V_35 ) ;
F_7 (KERN_INFO PREFIX
L_7 ,
(unsigned long long)drhd->address, drhd->flags) ;
break;
case V_58 :
V_54 = F_25 ( V_35 , struct V_53 ,
V_35 ) ;
F_7 (KERN_INFO PREFIX
L_8 ,
(unsigned long long)rmrr->base_address,
(unsigned long long)rmrr->end_address) ;
break;
case V_59 :
V_56 = F_25 ( V_35 , struct V_55 , V_35 ) ;
F_7 (KERN_INFO PREFIX L_9 , atsr->flags) ;
break;
case V_60 :
V_44 = F_25 ( V_35 , struct V_43 , V_35 ) ;
F_7 (KERN_INFO PREFIX L_10 ,
(unsigned long long)rhsa->base_address,
rhsa->proximity_domain) ;
break;
}
}
static int T_1 F_26 ( void )
{
T_3 V_61 = V_62 ;
V_61 = F_27 ( V_63 , 0 ,
(struct V_64 * * ) & V_65 ,
& V_66 ) ;
if ( F_28 ( V_61 ) && ! V_65 ) {
F_7 (KERN_WARNING PREFIX L_11 ) ;
V_61 = V_67 ;
}
return ( F_28 ( V_61 ) ? 1 : 0 ) ;
}
static int T_1
F_29 ( void )
{
struct V_68 * V_69 ;
struct V_34 * V_70 ;
int V_30 = 0 ;
F_26 () ;
V_65 = F_30 ( V_65 ) ;
V_69 = (struct V_68 * ) V_65 ;
if ( ! V_69 )
return - V_71 ;
if ( V_69 -> V_72 < V_73 - 1 ) {
F_7 (KERN_WARNING PREFIX L_12 ) ;
return - V_23 ;
}
F_7 (KERN_INFO PREFIX L_13 ,
dmar->width + 1 ) ;
V_70 = (struct V_34 * ) ( V_69 + 1 ) ;
while ( ( ( unsigned long ) V_70 ) <
( ( ( unsigned long ) V_69 ) + V_65 -> V_17 ) ) {
if ( V_70 -> V_17 == 0 ) {
F_7 (KERN_WARNING PREFIX
L_14 ) ;
V_30 = - V_23 ;
break;
}
F_24 ( V_70 ) ;
switch ( V_70 -> type ) {
case V_57 :
V_30 = F_13 ( V_70 ) ;
break;
case V_58 :
V_30 = F_31 ( V_70 ) ;
break;
case V_59 :
V_30 = F_32 ( V_70 ) ;
break;
case V_60 :
#ifdef F_33
V_30 = F_18 ( V_70 ) ;
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
V_70 = ( ( void * ) V_70 + V_70 -> V_17 ) ;
}
return V_30 ;
}
static int F_34 ( struct V_8 * V_27 [] , int V_26 ,
struct V_8 * V_9 )
{
int V_29 ;
while ( V_9 ) {
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ )
if ( V_9 == V_27 [ V_29 ] )
return 1 ;
V_9 = V_9 -> V_12 -> V_74 ;
}
return 0 ;
}
struct V_1 *
F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_37 = NULL ;
struct V_36 * V_2 ;
V_9 = F_36 ( V_9 ) ;
F_37 (dmaru, &dmar_drhd_units, list) {
V_2 = F_25 ( V_37 -> V_38 ,
struct V_36 ,
V_35 ) ;
if ( V_37 -> V_3 &&
V_2 -> V_10 == F_38 ( V_9 -> V_12 ) )
return V_37 ;
if ( F_34 ( V_37 -> V_27 ,
V_37 -> V_42 , V_9 ) )
return V_37 ;
}
return NULL ;
}
int T_1 F_39 ( void )
{
static int V_75 ;
struct V_1 * V_2 , * V_76 ;
int V_30 = - V_71 ;
if ( V_75 )
return V_75 ;
if ( F_40 ( & V_5 ) )
goto V_77;
F_41 (drhd, drhd_n, &dmar_drhd_units, list) {
V_30 = F_16 ( V_2 ) ;
if ( V_30 )
goto V_77;
}
V_30 = F_42 () ;
if ( V_30 )
goto V_77;
V_75 = 1 ;
return 0 ;
V_77:
V_75 = V_30 ;
return V_30 ;
}
int T_1 F_43 ( void )
{
static int V_78 ;
int V_30 ;
if ( V_78 )
return 0 ;
V_78 = 1 ;
V_30 = F_29 () ;
if ( V_30 ) {
if ( V_30 != - V_71 )
F_7 (KERN_INFO PREFIX L_16 ) ;
return V_30 ;
}
if ( F_40 ( & V_5 ) ) {
F_7 (KERN_INFO PREFIX L_17 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_44 ( T_4 V_79 , const char * V_80 )
{
F_45 (
1 , V_49 ,
L_18
L_6 ,
V_79 , V_80 ,
F_23 ( V_50 ) ,
F_23 ( V_51 ) ,
F_23 ( V_52 ) ) ;
}
int T_1 F_46 ( void )
{
struct V_68 * V_69 ;
struct V_34 * V_70 ;
struct V_36 * V_2 ;
V_69 = (struct V_68 * ) V_65 ;
V_70 = (struct V_34 * ) ( V_69 + 1 ) ;
while ( ( ( unsigned long ) V_70 ) <
( ( ( unsigned long ) V_69 ) + V_65 -> V_17 ) ) {
if ( V_70 -> V_17 == 0 ) {
F_7 (KERN_WARNING PREFIX
L_14 ) ;
return 0 ;
}
if ( V_70 -> type == V_57 ) {
void T_5 * V_79 ;
T_4 V_81 , V_82 ;
V_2 = ( void * ) V_70 ;
if ( ! V_2 -> V_40 ) {
F_44 ( 0 , L_19 ) ;
goto V_83;
}
V_79 = F_47 ( V_2 -> V_40 , V_84 ) ;
if ( ! V_79 ) {
F_7 ( L_20 , V_2 -> V_40 ) ;
goto V_83;
}
V_81 = F_48 ( V_79 + V_85 ) ;
V_82 = F_48 ( V_79 + V_86 ) ;
F_49 ( V_79 , V_84 ) ;
if ( V_81 == ( V_87 ) - 1 && V_82 == ( V_87 ) - 1 ) {
F_44 ( V_2 -> V_40 ,
L_21 ) ;
goto V_83;
}
}
V_70 = ( ( void * ) V_70 + V_70 -> V_17 ) ;
}
return 1 ;
V_83:
return 0 ;
}
int T_1 F_50 ( void )
{
int V_30 ;
V_30 = F_26 () ;
if ( V_30 )
V_30 = F_46 () ;
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) V_65 ;
if ( V_30 && V_88 && V_89 &&
V_69 -> V_41 & 0x1 )
F_7 ( V_90
L_22 ) ;
if ( V_30 && ! V_91 && ! V_92 && ! V_93 ) {
V_92 = 1 ;
F_51 () ;
}
#ifdef F_52
if ( V_30 )
V_94 . V_48 . V_95 = V_96 ;
#endif
}
F_53 ( V_65 , V_66 ) ;
V_65 = NULL ;
return V_30 ? 1 : - V_71 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_97 * V_48 ;
int V_98 ;
T_6 V_99 ;
static int V_100 = 0 ;
int V_101 = 0 ;
int V_102 = 0 ;
if ( ! V_2 -> V_39 ) {
F_44 ( 0 , L_19 ) ;
return - V_23 ;
}
V_48 = F_14 ( sizeof( * V_48 ) , V_32 ) ;
if ( ! V_48 )
return - V_33 ;
V_48 -> V_103 = V_100 ++ ;
sprintf ( V_48 -> V_104 , L_23 , V_48 -> V_103 ) ;
V_48 -> V_105 = F_54 ( V_2 -> V_39 , V_84 ) ;
if ( ! V_48 -> V_105 ) {
F_7 ( V_106 L_24 ) ;
goto error;
}
V_48 -> V_81 = F_48 ( V_48 -> V_105 + V_85 ) ;
V_48 -> V_82 = F_48 ( V_48 -> V_105 + V_86 ) ;
if ( V_48 -> V_81 == ( V_87 ) - 1 && V_48 -> V_82 == ( V_87 ) - 1 ) {
F_44 ( V_2 -> V_39 , L_21 ) ;
goto V_107;
}
V_101 = F_55 ( V_48 ) ;
if ( V_101 < 0 ) {
F_7 ( V_106
L_25 ,
V_48 -> V_103 ) ;
goto V_107;
}
V_102 = F_56 ( V_48 ) ;
if ( V_102 < 0 ) {
F_7 ( V_106
L_26 ,
V_48 -> V_103 ) ;
goto V_107;
}
V_48 -> V_101 = V_101 ;
V_48 -> V_102 = V_102 ;
V_48 -> V_46 = - 1 ;
V_98 = F_57 ( int , F_58 ( V_48 -> V_82 ) ,
F_59 ( V_48 -> V_81 ) ) ;
V_98 = F_60 ( V_98 ) ;
if ( V_98 > V_84 ) {
F_61 ( V_48 -> V_105 ) ;
V_48 -> V_105 = F_54 ( V_2 -> V_39 , V_98 ) ;
if ( ! V_48 -> V_105 ) {
F_7 ( V_106 L_24 ) ;
goto error;
}
}
V_99 = F_62 ( V_48 -> V_105 + V_108 ) ;
F_63 ( L_27 ,
V_48 -> V_103 ,
( unsigned long long ) V_2 -> V_39 ,
F_64 ( V_99 ) , F_65 ( V_99 ) ,
( unsigned long long ) V_48 -> V_81 ,
( unsigned long long ) V_48 -> V_82 ) ;
F_66 ( & V_48 -> V_109 ) ;
V_2 -> V_48 = V_48 ;
return 0 ;
V_107:
F_61 ( V_48 -> V_105 ) ;
error:
F_12 ( V_48 ) ;
return - 1 ;
}
void F_67 ( struct V_97 * V_48 )
{
if ( ! V_48 )
return;
F_68 ( V_48 ) ;
if ( V_48 -> V_105 )
F_61 ( V_48 -> V_105 ) ;
F_12 ( V_48 ) ;
}
static inline void F_69 ( struct V_110 * V_111 )
{
while ( V_111 -> V_112 [ V_111 -> V_113 ] == V_114 ||
V_111 -> V_112 [ V_111 -> V_113 ] == V_115 ) {
V_111 -> V_112 [ V_111 -> V_113 ] = V_116 ;
V_111 -> V_113 = ( V_111 -> V_113 + 1 ) % V_117 ;
V_111 -> V_118 ++ ;
}
}
static int F_70 ( struct V_97 * V_48 , int V_29 )
{
T_6 V_119 ;
int V_120 , V_121 ;
struct V_110 * V_111 = V_48 -> V_111 ;
int V_122 = ( V_29 + 1 ) % V_117 ;
if ( V_111 -> V_112 [ V_122 ] == V_115 )
return - V_123 ;
V_119 = F_62 ( V_48 -> V_105 + V_124 ) ;
if ( V_119 & V_125 ) {
V_120 = F_62 ( V_48 -> V_105 + V_126 ) ;
if ( ( V_120 >> V_127 ) == V_29 ) {
F_7 ( V_106 L_28
L_29 ,
( unsigned long long ) V_111 -> V_128 [ V_29 ] . V_129 ,
( unsigned long long ) V_111 -> V_128 [ V_29 ] . V_130 ) ;
memcpy ( & V_111 -> V_128 [ V_29 ] , & V_111 -> V_128 [ V_122 ] ,
sizeof( struct V_131 ) ) ;
F_71 ( V_48 , & V_111 -> V_128 [ V_29 ] ,
sizeof( struct V_131 ) ) ;
F_72 ( V_125 , V_48 -> V_105 + V_124 ) ;
return - V_23 ;
}
}
if ( V_119 & V_132 ) {
V_120 = F_62 ( V_48 -> V_105 + V_126 ) ;
V_120 = ( ( V_120 >> V_127 ) - 1 + V_117 ) % V_117 ;
V_120 |= 1 ;
V_121 = F_62 ( V_48 -> V_105 + V_133 ) ;
V_121 = ( ( V_121 >> V_127 ) - 1 + V_117 ) % V_117 ;
F_72 ( V_132 , V_48 -> V_105 + V_124 ) ;
do {
if ( V_111 -> V_112 [ V_120 ] == V_134 )
V_111 -> V_112 [ V_120 ] = V_115 ;
V_120 = ( V_120 - 2 + V_117 ) % V_117 ;
} while ( V_120 != V_121 );
if ( V_111 -> V_112 [ V_122 ] == V_115 )
return - V_123 ;
}
if ( V_119 & V_135 )
F_72 ( V_135 , V_48 -> V_105 + V_124 ) ;
return 0 ;
}
int F_73 ( struct V_131 * V_128 , struct V_97 * V_48 )
{
int V_136 ;
struct V_110 * V_111 = V_48 -> V_111 ;
struct V_131 * V_137 , V_138 ;
int V_122 , V_29 ;
unsigned long V_41 ;
if ( ! V_111 )
return 0 ;
V_137 = V_111 -> V_128 ;
V_139:
V_136 = 0 ;
F_74 ( & V_111 -> V_140 , V_41 ) ;
while ( V_111 -> V_118 < 3 ) {
F_75 ( & V_111 -> V_140 , V_41 ) ;
F_76 () ;
F_74 ( & V_111 -> V_140 , V_41 ) ;
}
V_29 = V_111 -> V_141 ;
V_122 = ( V_29 + 1 ) % V_117 ;
V_111 -> V_112 [ V_29 ] = V_111 -> V_112 [ V_122 ] = V_134 ;
V_137 [ V_29 ] = * V_128 ;
V_138 . V_129 = F_77 ( V_114 ) |
V_142 | V_143 ;
V_138 . V_130 = F_78 ( & V_111 -> V_112 [ V_122 ] ) ;
V_137 [ V_122 ] = V_138 ;
F_71 ( V_48 , & V_137 [ V_29 ] , sizeof( struct V_131 ) ) ;
F_71 ( V_48 , & V_137 [ V_122 ] , sizeof( struct V_131 ) ) ;
V_111 -> V_141 = ( V_111 -> V_141 + 2 ) % V_117 ;
V_111 -> V_118 -= 2 ;
F_72 ( V_111 -> V_141 << V_127 , V_48 -> V_105 + V_133 ) ;
while ( V_111 -> V_112 [ V_122 ] != V_114 ) {
V_136 = F_70 ( V_48 , V_29 ) ;
if ( V_136 )
break;
F_79 ( & V_111 -> V_140 ) ;
F_76 () ;
F_80 ( & V_111 -> V_140 ) ;
}
V_111 -> V_112 [ V_29 ] = V_114 ;
F_69 ( V_111 ) ;
F_75 ( & V_111 -> V_140 , V_41 ) ;
if ( V_136 == - V_123 )
goto V_139;
return V_136 ;
}
void F_81 ( struct V_97 * V_48 )
{
struct V_131 V_128 ;
V_128 . V_129 = V_144 ;
V_128 . V_130 = 0 ;
F_73 ( & V_128 , V_48 ) ;
}
void F_82 ( struct V_97 * V_48 , T_2 V_145 , T_2 V_146 , T_7 V_147 ,
T_4 type )
{
struct V_131 V_128 ;
V_128 . V_129 = F_83 ( V_147 ) | F_84 ( V_146 ) | F_85 ( V_145 )
| F_86 ( type ) | V_148 ;
V_128 . V_130 = 0 ;
F_73 ( & V_128 , V_48 ) ;
}
void F_87 ( struct V_97 * V_48 , T_2 V_145 , T_4 V_79 ,
unsigned int V_149 , T_4 type )
{
T_7 V_150 = 0 , V_151 = 0 ;
struct V_131 V_128 ;
int V_152 = 0 ;
if ( F_88 ( V_48 -> V_81 ) )
V_150 = 1 ;
if ( F_89 ( V_48 -> V_81 ) )
V_151 = 1 ;
V_128 . V_129 = F_90 ( V_145 ) | F_91 ( V_151 ) | F_92 ( V_150 )
| F_93 ( type ) | V_153 ;
V_128 . V_130 = F_94 ( V_79 ) | F_95 ( V_152 )
| F_96 ( V_149 ) ;
F_73 ( & V_128 , V_48 ) ;
}
void F_97 ( struct V_97 * V_48 , T_2 V_146 , T_2 V_154 ,
T_4 V_79 , unsigned V_155 )
{
struct V_131 V_128 ;
if ( V_155 ) {
F_98 ( V_79 & ( ( 1 << ( V_156 + V_155 ) ) - 1 ) ) ;
V_79 |= ( 1 << ( V_156 + V_155 - 1 ) ) - 1 ;
V_128 . V_130 = F_99 ( V_79 ) | V_157 ;
} else
V_128 . V_130 = F_99 ( V_79 ) ;
if ( V_154 >= V_158 )
V_154 = 0 ;
V_128 . V_129 = F_100 ( V_146 ) | F_101 ( V_154 ) |
V_159 ;
F_73 ( & V_128 , V_48 ) ;
}
void F_102 ( struct V_97 * V_48 )
{
unsigned long V_41 ;
T_6 V_160 ;
T_8 V_161 = F_103 () ;
if ( ! F_104 ( V_48 -> V_82 ) )
return;
F_74 ( & V_48 -> V_109 , V_41 ) ;
V_160 = F_48 ( V_48 -> V_105 + V_162 ) ;
if ( ! ( V_160 & V_163 ) )
goto V_25;
while ( ( F_62 ( V_48 -> V_105 + V_133 ) !=
F_62 ( V_48 -> V_105 + V_126 ) ) &&
( V_164 > ( F_103 () - V_161 ) ) )
F_76 () ;
V_48 -> V_165 &= ~ V_166 ;
F_72 ( V_48 -> V_165 , V_48 -> V_105 + V_167 ) ;
F_105 ( V_48 , V_162 , F_62 ,
! ( V_160 & V_163 ) , V_160 ) ;
V_25:
F_75 ( & V_48 -> V_109 , V_41 ) ;
}
static void F_106 ( struct V_97 * V_48 )
{
T_6 V_160 ;
unsigned long V_41 ;
struct V_110 * V_111 = V_48 -> V_111 ;
V_111 -> V_141 = V_111 -> V_113 = 0 ;
V_111 -> V_118 = V_117 ;
F_74 ( & V_48 -> V_109 , V_41 ) ;
F_72 ( 0 , V_48 -> V_105 + V_133 ) ;
F_107 ( V_48 -> V_105 + V_168 , F_78 ( V_111 -> V_128 ) ) ;
V_48 -> V_165 |= V_166 ;
F_72 ( V_48 -> V_165 , V_48 -> V_105 + V_167 ) ;
F_105 ( V_48 , V_162 , F_62 , ( V_160 & V_163 ) , V_160 ) ;
F_75 ( & V_48 -> V_109 , V_41 ) ;
}
int F_108 ( struct V_97 * V_48 )
{
struct V_110 * V_111 ;
struct V_169 * V_170 ;
if ( ! F_104 ( V_48 -> V_82 ) )
return - V_171 ;
if ( V_48 -> V_111 )
return 0 ;
V_48 -> V_111 = F_109 ( sizeof( * V_111 ) , V_172 ) ;
if ( ! V_48 -> V_111 )
return - V_33 ;
V_111 = V_48 -> V_111 ;
V_170 = F_110 ( V_48 -> V_46 , V_172 | V_173 , 0 ) ;
if ( ! V_170 ) {
F_12 ( V_111 ) ;
V_48 -> V_111 = 0 ;
return - V_33 ;
}
V_111 -> V_128 = F_111 ( V_170 ) ;
V_111 -> V_112 = F_109 ( V_117 * sizeof( int ) , V_172 ) ;
if ( ! V_111 -> V_112 ) {
F_112 ( ( unsigned long ) V_111 -> V_128 ) ;
F_12 ( V_111 ) ;
V_48 -> V_111 = 0 ;
return - V_33 ;
}
V_111 -> V_141 = V_111 -> V_113 = 0 ;
V_111 -> V_118 = V_117 ;
F_66 ( & V_111 -> V_140 ) ;
F_106 ( V_48 ) ;
return 0 ;
}
const char * F_113 ( T_7 V_174 , int * V_175 )
{
if ( V_174 >= 0x20 && ( V_174 - 0x20 <
F_114 ( V_176 ) ) ) {
* V_175 = V_177 ;
return V_176 [ V_174 - 0x20 ] ;
} else if ( V_174 < F_114 ( V_178 ) ) {
* V_175 = V_179 ;
return V_178 [ V_174 ] ;
} else {
* V_175 = V_180 ;
return L_30 ;
}
}
void F_115 ( struct V_181 * V_182 )
{
struct V_97 * V_48 = F_116 ( V_182 ) ;
unsigned long V_183 ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
F_72 ( 0 , V_48 -> V_105 + V_184 ) ;
F_62 ( V_48 -> V_105 + V_184 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
}
void F_117 ( struct V_181 * V_182 )
{
unsigned long V_183 ;
struct V_97 * V_48 = F_116 ( V_182 ) ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
F_72 ( V_185 , V_48 -> V_105 + V_184 ) ;
F_62 ( V_48 -> V_105 + V_184 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
}
void F_118 ( int V_186 , struct V_187 * V_188 )
{
struct V_97 * V_48 = F_119 ( V_186 ) ;
unsigned long V_183 ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
F_72 ( V_188 -> V_182 , V_48 -> V_105 + V_189 ) ;
F_72 ( V_188 -> V_190 , V_48 -> V_105 + V_191 ) ;
F_72 ( V_188 -> V_192 , V_48 -> V_105 + V_193 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
}
void F_120 ( int V_186 , struct V_187 * V_188 )
{
struct V_97 * V_48 = F_119 ( V_186 ) ;
unsigned long V_183 ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
V_188 -> V_182 = F_62 ( V_48 -> V_105 + V_189 ) ;
V_188 -> V_190 = F_62 ( V_48 -> V_105 + V_191 ) ;
V_188 -> V_192 = F_62 ( V_48 -> V_105 + V_193 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
}
static int F_121 ( struct V_97 * V_48 , int type ,
T_7 V_174 , T_2 V_194 , unsigned long long V_79 )
{
const char * V_195 ;
int V_175 ;
V_195 = F_113 ( V_174 , & V_175 ) ;
if ( V_175 == V_177 )
F_7 ( V_106 L_31
L_32
L_33 ,
( V_194 >> 8 ) , F_122 ( V_194 & 0xFF ) ,
F_123 ( V_194 & 0xFF ) , V_79 >> 48 ,
V_174 , V_195 ) ;
else
F_7 ( V_106
L_34
L_35
L_36 ,
( type ? L_37 : L_38 ) ,
( V_194 >> 8 ) , F_122 ( V_194 & 0xFF ) ,
F_123 ( V_194 & 0xFF ) , V_79 , V_174 , V_195 ) ;
return 0 ;
}
T_9 F_124 ( int V_186 , void * V_196 )
{
struct V_97 * V_48 = V_196 ;
int V_105 , V_197 ;
T_6 V_198 ;
unsigned long V_183 ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
V_198 = F_62 ( V_48 -> V_105 + V_124 ) ;
if ( V_198 )
F_7 ( V_106 L_39 ,
V_198 ) ;
if ( ! ( V_198 & V_199 ) )
goto V_200;
V_197 = F_125 ( V_198 ) ;
V_105 = F_126 ( V_48 -> V_81 ) ;
while ( 1 ) {
T_7 V_174 ;
T_2 V_194 ;
T_4 V_201 ;
int type ;
T_6 V_182 ;
V_182 = F_62 ( V_48 -> V_105 + V_105 +
V_197 * V_202 + 12 ) ;
if ( ! ( V_182 & V_203 ) )
break;
V_174 = F_127 ( V_182 ) ;
type = F_128 ( V_182 ) ;
V_182 = F_62 ( V_48 -> V_105 + V_105 +
V_197 * V_202 + 8 ) ;
V_194 = F_129 ( V_182 ) ;
V_201 = F_48 ( V_48 -> V_105 + V_105 +
V_197 * V_202 ) ;
V_201 = F_130 ( V_201 ) ;
F_72 ( V_203 , V_48 -> V_105 + V_105 +
V_197 * V_202 + 12 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
F_121 ( V_48 , type , V_174 ,
V_194 , V_201 ) ;
V_197 ++ ;
if ( V_197 >= F_131 ( V_48 -> V_81 ) )
V_197 = 0 ;
F_74 ( & V_48 -> V_109 , V_183 ) ;
}
V_200:
V_198 = F_62 ( V_48 -> V_105 + V_124 ) ;
F_72 ( V_198 , V_48 -> V_105 + V_124 ) ;
F_75 ( & V_48 -> V_109 , V_183 ) ;
return V_204 ;
}
int F_132 ( struct V_97 * V_48 )
{
int V_186 , V_30 ;
if ( V_48 -> V_186 )
return 0 ;
V_186 = F_133 () ;
if ( ! V_186 ) {
F_7 ( V_106 L_40 ) ;
return - V_23 ;
}
F_134 ( V_186 , V_48 ) ;
V_48 -> V_186 = V_186 ;
V_30 = F_135 ( V_186 ) ;
if ( V_30 ) {
F_134 ( V_186 , NULL ) ;
V_48 -> V_186 = 0 ;
F_136 ( V_186 ) ;
return V_30 ;
}
V_30 = F_137 ( V_186 , F_124 , V_205 , V_48 -> V_104 , V_48 ) ;
if ( V_30 )
F_7 ( V_106 L_41 ) ;
return V_30 ;
}
int T_1 F_138 ( void )
{
struct V_1 * V_2 ;
F_19 (drhd) {
int V_30 ;
struct V_97 * V_48 = V_2 -> V_48 ;
V_30 = F_132 ( V_48 ) ;
if ( V_30 ) {
F_7 ( V_106 L_42
L_43 ,
( unsigned long long ) V_2 -> V_39 , V_30 ) ;
return - 1 ;
}
F_124 ( V_48 -> V_186 , V_48 ) ;
}
return 0 ;
}
int F_139 ( struct V_97 * V_48 )
{
if ( ! F_104 ( V_48 -> V_82 ) )
return - V_171 ;
if ( ! V_48 -> V_111 )
return - V_171 ;
F_102 ( V_48 ) ;
F_106 ( V_48 ) ;
return 0 ;
}
int T_1 F_140 ( void )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) V_65 ;
if ( ! V_69 )
return 0 ;
return V_69 -> V_41 & 0x1 ;
}
