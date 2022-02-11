static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
V_4 -> V_9 = ( V_10 ) V_6 -> V_11 ;
V_4 -> V_12 = ( V_10 ) V_6 -> V_13 ;
V_4 -> V_14 = V_6 -> V_15 ;
return 0 ;
}
static inline int F_2 ( T_1 V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_3 ( V_18 ) ; V_17 ++ )
if ( V_16 <= V_18 [ V_17 ] )
return V_17 ;
return - V_19 ;
}
static void F_4 ( void T_2 * V_20 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < F_3 ( V_18 ) ; V_17 ++ )
F_5 ( V_18 [ V_17 ] , V_20 + V_21 + ( 4 * V_17 ) ) ;
}
static inline void * F_6 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
return V_23 -> V_25 + ( V_24 * V_26 ) ;
}
static inline T_3 F_7 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
return V_23 -> V_27 + ( V_24 * V_26 ) ;
}
static int F_8 ( struct V_22 * V_23 ,
struct V_28 * V_29 )
{
void T_2 * V_20 = V_23 -> V_20 ;
T_1 V_30 = ( T_1 ) F_7 ( V_23 , V_29 -> V_31 ) ;
T_1 V_32 = V_29 -> V_33 ;
T_1 V_34 ;
int V_35 = 0 ;
F_9 ( L_1 ) ;
V_34 = F_10 ( V_20 + V_36 ) ;
if ( V_34 & V_37 ) {
#if 0
tmp = readl(mmio + CARM_INT_MASK);
tmp |= INT_Q_AVAILABLE;
writel(tmp, mmio + CARM_INT_MASK);
readl(mmio + CARM_INT_MASK);
#endif
F_11 ( L_2 ) ;
V_35 = - V_38 ;
} else {
F_5 ( V_30 | ( V_32 << 1 ) , V_20 + V_39 ) ;
F_10 ( V_20 + V_39 ) ;
}
return V_35 ;
}
static struct V_28 * F_12 ( struct V_22 * V_23 )
{
unsigned int V_17 ;
if ( V_23 -> V_40 >= ( V_41 - V_42 ) )
return NULL ;
for ( V_17 = 0 ; V_17 < V_43 ; V_17 ++ )
if ( ( V_23 -> V_44 & ( 1ULL << V_17 ) ) == 0 ) {
struct V_28 * V_29 = & V_23 -> V_45 [ V_17 ] ;
V_29 -> V_6 = NULL ;
V_29 -> V_46 = 0 ;
V_23 -> V_44 |= ( 1ULL << V_17 ) ;
V_23 -> V_47 ++ ;
assert ( V_23 -> V_47 <= V_48 ) ;
F_13 ( V_29 -> V_49 , V_42 ) ;
return V_29 ;
}
F_11 ( L_3 ) ;
return NULL ;
}
static int F_14 ( struct V_22 * V_23 , struct V_28 * V_29 )
{
assert ( V_29 -> V_31 < V_43 ) ;
if ( F_15 ( ( V_23 -> V_44 & ( 1ULL << V_29 -> V_31 ) ) == 0 ) )
return - V_50 ;
assert ( V_23 -> V_40 >= V_29 -> V_46 ) ;
V_23 -> V_44 &= ~ ( 1ULL << V_29 -> V_31 ) ;
V_23 -> V_40 -= V_29 -> V_46 ;
V_23 -> V_47 -- ;
return 0 ;
}
static struct V_28 * F_16 ( struct V_22 * V_23 )
{
unsigned long V_51 ;
struct V_28 * V_29 = NULL ;
struct V_52 * V_53 ;
int V_54 = 5000 ;
while ( V_54 -- > 0 ) {
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_29 = F_12 ( V_23 ) ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
if ( V_29 )
break;
F_19 ( 10 ) ;
}
if ( ! V_29 )
return NULL ;
V_53 = F_20 ( V_23 -> V_56 , V_57 , V_58 ) ;
if ( F_21 ( V_53 ) ) {
F_17 ( & V_23 -> V_55 , V_51 ) ;
F_14 ( V_23 , V_29 ) ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
return NULL ;
}
V_29 -> V_53 = V_53 ;
return V_29 ;
}
static int F_22 ( struct V_22 * V_23 , unsigned int V_59 )
{
struct V_60 * V_61 ;
unsigned int V_62 ;
T_1 V_63 ;
T_3 V_27 ;
struct V_28 * V_29 ;
int V_35 ;
V_29 = F_16 ( V_23 ) ;
if ( ! V_29 ) {
V_35 = - V_64 ;
goto V_65;
}
V_62 = V_29 -> V_31 ;
V_61 = F_6 ( V_23 , V_62 ) ;
V_27 = F_7 ( V_23 , V_62 ) ;
V_63 = ( T_1 ) ( V_27 + sizeof( struct F_22 ) ) ;
V_29 -> V_66 = V_67 ;
V_29 -> V_68 = V_69 ;
V_35 = F_2 ( sizeof( struct V_60 ) +
sizeof( struct F_22 ) ) ;
F_23 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_67 ;
V_61 -> V_70 = V_69 ;
V_61 -> V_71 = ( V_10 ) V_59 ;
V_61 -> V_72 = F_24 ( F_25 ( V_62 ) ) ;
V_61 -> V_73 = F_24 ( V_63 ) ;
F_26 ( & V_23 -> V_55 ) ;
assert ( V_23 -> V_74 == V_75 ||
V_23 -> V_74 == V_76 ) ;
F_27 ( & V_23 -> V_55 ) ;
F_11 ( L_4 , V_62 ) ;
V_29 -> V_53 -> V_77 = V_29 ;
F_28 ( V_23 -> V_56 , NULL , V_29 -> V_53 , true , NULL ) ;
return 0 ;
V_65:
F_26 ( & V_23 -> V_55 ) ;
V_23 -> V_74 = V_78 ;
F_27 ( & V_23 -> V_55 ) ;
return V_35 ;
}
static int F_29 ( struct V_22 * V_23 , T_4 V_79 )
{
struct V_28 * V_29 ;
struct V_60 * V_61 ;
void * V_80 ;
unsigned int V_62 , V_16 ;
int V_35 ;
V_29 = F_16 ( V_23 ) ;
if ( ! V_29 )
return - V_64 ;
V_62 = V_29 -> V_31 ;
V_80 = F_6 ( V_23 , V_62 ) ;
V_16 = V_79 ( V_23 , V_62 , V_80 ) ;
V_61 = V_80 ;
V_29 -> V_66 = V_61 -> type ;
V_29 -> V_68 = V_61 -> V_70 ;
V_35 = F_2 ( V_16 ) ;
F_23 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
F_11 ( L_4 , V_62 ) ;
V_29 -> V_53 -> V_77 = V_29 ;
F_28 ( V_23 -> V_56 , NULL , V_29 -> V_53 , true , NULL ) ;
return 0 ;
}
static unsigned int F_30 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_80 )
{
struct V_81 * V_82 = V_80 ;
T_5 V_83 = F_31 () ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> type = V_84 ;
V_82 -> V_70 = V_85 ;
V_82 -> V_72 = F_24 ( F_25 ( V_62 ) ) ;
V_82 -> V_86 = F_24 ( V_83 ) ;
return sizeof( struct V_81 ) ;
}
static unsigned int F_32 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_80 )
{
struct V_87 * V_88 = V_80 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> type = V_84 ;
V_88 -> V_70 = V_89 ;
V_88 -> V_72 = F_24 ( F_25 ( V_62 ) ) ;
V_88 -> V_90 = 1 ;
V_88 -> V_91 = V_92 ;
V_88 -> V_93 = F_24 ( V_23 -> V_94 + ( V_95 >> 1 ) ) ;
V_88 -> V_96 = F_24 ( V_95 >> 1 ) ;
V_88 -> V_97 = F_24 ( V_23 -> V_94 + ( 16 * 1024 ) ) ;
V_88 -> V_98 = F_24 ( 1024 ) ;
V_88 -> V_99 = F_24 ( V_23 -> V_94 ) ;
V_88 -> V_100 = F_24 ( V_101 ) ;
V_88 -> V_102 = F_24 ( V_23 -> V_94 + V_103 ) ;
V_88 -> V_104 = F_24 ( V_105 ) ;
V_88 -> V_49 [ 0 ] . V_106 = F_24 ( V_23 -> V_94 + ( V_95 >> 1 ) ) ;
V_88 -> V_49 [ 0 ] . V_96 = F_24 ( 65536 ) ;
return sizeof( struct V_87 ) ;
}
static unsigned int F_33 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_80 )
{
struct V_60 * V_61 = V_80 ;
T_1 V_63 = ( T_1 ) ( F_7 ( V_23 , V_62 ) +
V_107 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_108 ;
V_61 -> V_70 = V_109 ;
V_61 -> V_72 = F_24 ( F_25 ( V_62 ) ) ;
V_61 -> V_73 = F_24 ( V_63 ) ;
V_80 += V_107 ;
memset ( V_80 , V_110 , V_111 ) ;
return V_107 + V_111 ;
}
static unsigned int F_34 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_80 )
{
struct V_112 * V_61 = V_80 ;
T_1 V_63 = ( T_1 ) ( F_7 ( V_23 , V_62 ) + sizeof( * V_61 ) ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_84 ;
V_61 -> V_70 = V_113 ;
V_61 -> V_72 = F_24 ( F_25 ( V_62 ) ) ;
V_61 -> V_73 = F_24 ( V_63 ) ;
return sizeof( struct V_112 ) +
sizeof( struct V_114 ) ;
}
static inline void F_35 ( struct V_22 * V_23 ,
struct V_28 * V_29 ,
T_6 error )
{
struct V_52 * V_45 = V_29 -> V_53 ;
int V_35 ;
F_36 ( V_45 , error ) ;
V_35 = F_14 ( V_23 , V_29 ) ;
assert ( V_35 == 0 ) ;
}
static inline void F_37 ( struct V_22 * V_23 , struct V_115 * V_116 )
{
unsigned int V_62 = V_23 -> V_117 % V_118 ;
F_38 ( V_116 ) ;
F_9 ( L_5 , V_116 ) ;
V_23 -> V_119 [ V_62 ] = V_116 ;
V_23 -> V_117 ++ ;
F_23 ( V_23 -> V_117 == V_23 -> V_120 ) ;
}
static inline struct V_115 * F_39 ( struct V_22 * V_23 )
{
unsigned int V_62 ;
if ( V_23 -> V_117 == V_23 -> V_120 )
return NULL ;
V_62 = V_23 -> V_120 % V_118 ;
V_23 -> V_120 ++ ;
return V_23 -> V_119 [ V_62 ] ;
}
static inline void F_40 ( struct V_22 * V_23 )
{
struct V_115 * V_116 = F_39 ( V_23 ) ;
if ( V_116 ) {
F_41 ( V_116 ) ;
F_9 ( L_6 , V_116 ) ;
}
}
static inline void F_42 ( struct V_22 * V_23 , struct V_28 * V_29 ,
T_6 error )
{
F_35 ( V_23 , V_29 , error ) ;
if ( V_43 == 1 )
F_40 ( V_23 ) ;
else if ( ( V_23 -> V_47 <= V_121 ) &&
( V_23 -> V_40 <= V_122 ) ) {
F_40 ( V_23 ) ;
}
}
static void F_43 ( struct V_115 * V_116 )
{
struct V_22 * V_23 = V_116 -> V_123 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
int V_35 ;
while ( 1 ) {
F_11 ( L_7 ) ;
V_53 = F_44 ( V_116 ) ;
if ( ! V_53 )
break;
V_29 = V_53 -> V_77 ;
assert ( V_29 != NULL ) ;
assert ( V_29 -> V_53 == V_53 ) ;
V_29 -> V_46 = 0 ;
F_11 ( L_8 ) ;
V_35 = F_8 ( V_23 , V_29 ) ;
if ( V_35 ) {
F_45 ( V_116 , V_53 ) ;
F_37 ( V_23 , V_116 ) ;
return;
}
}
}
static void F_46 ( struct V_115 * V_116 )
{
struct V_5 * V_6 = V_116 -> V_123 ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_124 * V_30 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
struct V_125 * V_49 ;
int V_126 = 0 , V_127 , V_17 , V_46 , V_35 ;
T_1 V_34 ;
unsigned int V_16 ;
V_128:
F_9 ( L_7 ) ;
V_53 = F_47 ( V_116 ) ;
if ( ! V_53 )
return;
V_29 = F_12 ( V_23 ) ;
if ( ! V_29 ) {
F_37 ( V_23 , V_116 ) ;
return;
}
V_29 -> V_53 = V_53 ;
F_48 ( V_53 ) ;
if ( F_49 ( V_53 ) == V_129 ) {
V_126 = 1 ;
V_127 = V_130 ;
} else {
V_127 = V_131 ;
}
V_49 = & V_29 -> V_49 [ 0 ] ;
V_46 = F_50 ( V_116 , V_53 , V_49 ) ;
if ( V_46 <= 0 ) {
F_42 ( V_23 , V_29 , V_132 ) ;
return;
}
V_46 = F_51 ( V_23 -> V_133 , V_49 , V_46 , V_127 ) ;
if ( V_46 <= 0 ) {
F_42 ( V_23 , V_29 , V_132 ) ;
return;
}
V_29 -> V_46 = V_46 ;
V_29 -> V_6 = V_6 ;
V_23 -> V_40 += V_46 ;
F_9 ( L_9 ) ;
V_30 = (struct V_124 * ) F_6 ( V_23 , V_29 -> V_31 ) ;
if ( V_126 ) {
V_30 -> type = V_134 ;
V_29 -> V_66 = V_134 ;
} else {
V_30 -> type = V_135 ;
V_29 -> V_66 = V_135 ;
}
V_30 -> V_136 = V_6 -> V_137 ;
V_30 -> V_138 = V_46 ;
V_30 -> V_91 = V_92 ;
V_30 -> V_72 = F_24 ( F_25 ( V_29 -> V_31 ) ) ;
V_30 -> V_139 = F_24 ( F_52 ( V_53 ) & 0xffffffff ) ;
V_34 = ( F_52 ( V_53 ) >> 16 ) >> 16 ;
V_30 -> V_140 = F_53 ( ( V_141 ) V_34 ) ;
V_30 -> V_142 = F_53 ( F_54 ( V_53 ) ) ;
V_16 = sizeof( struct V_124 ) - sizeof( V_30 -> V_49 ) ;
for ( V_17 = 0 ; V_17 < V_46 ; V_17 ++ ) {
struct V_143 * V_144 = & V_30 -> V_49 [ V_17 ] ;
V_144 -> V_106 = F_24 ( F_55 ( & V_29 -> V_49 [ V_17 ] ) ) ;
V_144 -> V_96 = F_24 ( F_56 ( & V_29 -> V_49 [ V_17 ] ) ) ;
V_16 += sizeof( struct V_143 ) ;
}
V_35 = F_2 ( V_16 ) ;
F_23 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
F_9 ( L_10 , V_29 -> V_31 ) ;
V_35 = F_8 ( V_23 , V_29 ) ;
if ( V_35 ) {
F_14 ( V_23 , V_29 ) ;
F_45 ( V_116 , V_53 ) ;
F_37 ( V_23 , V_116 ) ;
return;
}
goto V_128;
}
static void F_57 ( struct V_22 * V_23 ,
struct V_28 * V_29 , V_10 * V_80 ,
T_6 error )
{
struct V_5 * V_6 ;
V_10 * V_63 = V_80 + sizeof( struct F_22 ) ;
struct F_22 * V_145 = (struct F_22 * ) V_63 ;
T_7 V_146 , V_147 ;
int V_148 ;
T_8 V_149 ;
F_11 ( L_1 ) ;
F_42 ( V_23 , V_29 , error ) ;
if ( error )
goto V_150;
if ( F_58 ( V_145 -> V_151 ) & V_152 )
goto V_150;
V_148 = V_23 -> V_153 ;
if ( ( V_148 < 0 ) || ( V_148 >= V_111 ) ) {
F_59 (KERN_ERR PFX L_11 ,
cur_port, (int) desc->array_id) ;
goto V_150;
}
V_6 = & V_23 -> V_6 [ V_148 ] ;
V_146 = ( T_7 ) F_58 ( V_145 -> V_154 ) ;
V_147 = ( T_7 ) F_60 ( V_145 -> V_155 ) ;
V_6 -> V_156 = V_146 | ( V_147 << 32 ) ;
V_6 -> V_11 = F_60 ( V_145 -> V_157 ) ;
V_6 -> V_13 = F_60 ( V_145 -> V_158 ) ;
V_6 -> V_15 = F_60 ( V_145 -> V_159 ) ;
V_23 -> V_160 |= ( 1 << V_148 ) ;
strncpy ( V_6 -> V_161 , V_145 -> V_161 , sizeof( V_6 -> V_161 ) ) ;
V_6 -> V_161 [ sizeof( V_6 -> V_161 ) - 1 ] = 0 ;
V_149 = strlen ( V_6 -> V_161 ) ;
while ( V_149 && ( V_6 -> V_161 [ V_149 - 1 ] == ' ' ) ) {
V_6 -> V_161 [ V_149 - 1 ] = 0 ;
V_149 -- ;
}
F_59 (KERN_INFO DRV_NAME L_12 ,
pci_name(host->pdev), port->port_no,
(unsigned long long) port->capacity) ;
F_59 (KERN_INFO DRV_NAME L_13 ,
pci_name(host->pdev), port->port_no, port->name) ;
V_150:
assert ( V_23 -> V_74 == V_76 ) ;
F_61 ( & V_23 -> V_162 ) ;
}
static void F_62 ( struct V_22 * V_23 ,
struct V_28 * V_29 , V_10 * V_80 ,
T_6 error )
{
V_10 * V_63 = V_80 + V_107 ;
unsigned int V_17 , V_163 = 0 ;
int V_164 = V_75 ;
F_11 ( L_1 ) ;
F_42 ( V_23 , V_29 , error ) ;
if ( error ) {
V_164 = V_78 ;
goto V_150;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
if ( V_63 [ V_17 ] == 0 ) {
V_23 -> V_165 |= ( 1 << V_17 ) ;
V_163 ++ ;
}
F_59 (KERN_INFO DRV_NAME L_14 ,
pci_name(host->pdev), dev_count) ;
V_150:
assert ( V_23 -> V_74 == V_166 ) ;
V_23 -> V_74 = V_164 ;
F_61 ( & V_23 -> V_162 ) ;
}
static void F_63 ( struct V_22 * V_23 ,
struct V_28 * V_29 , T_6 error ,
int V_167 , int V_168 )
{
F_11 ( L_1 ) ;
F_42 ( V_23 , V_29 , error ) ;
assert ( V_23 -> V_74 == V_167 ) ;
if ( error )
V_23 -> V_74 = V_78 ;
else
V_23 -> V_74 = V_168 ;
F_61 ( & V_23 -> V_162 ) ;
}
static inline void F_64 ( struct V_22 * V_23 ,
struct V_28 * V_29 , T_6 error )
{
int V_127 ;
F_9 ( L_1 ) ;
if ( F_49 ( V_29 -> V_53 ) == V_129 )
V_127 = V_130 ;
else
V_127 = V_131 ;
F_65 ( V_23 -> V_133 , & V_29 -> V_49 [ 0 ] , V_29 -> V_46 , V_127 ) ;
F_42 ( V_23 , V_29 , error ) ;
}
static inline void F_66 ( struct V_22 * V_23 ,
T_9 V_169 , T_1 V_170 )
{
T_1 V_72 = F_58 ( V_169 ) ;
unsigned int V_24 ;
struct V_28 * V_29 ;
T_6 error = ( V_170 == V_171 ) ? 0 : V_132 ;
V_10 * V_80 ;
F_9 ( L_15 , V_72 ) ;
if ( F_15 ( ! F_67 ( V_72 ) ) ) {
F_59 (KERN_ERR DRV_NAME L_16 ,
pci_name(host->pdev), handle) ;
return;
}
V_24 = F_68 ( V_72 ) ;
F_9 ( L_17 , V_24 ) ;
V_29 = & V_23 -> V_45 [ V_24 ] ;
if ( F_69 ( V_29 -> V_66 == V_135 ||
V_29 -> V_66 == V_134 ) ) {
F_64 ( V_23 , V_29 , error ) ;
return;
}
V_80 = F_6 ( V_23 , V_24 ) ;
switch ( V_29 -> V_66 ) {
case V_108 : {
switch ( V_29 -> V_68 ) {
case V_109 :
F_62 ( V_23 , V_29 , V_80 , error ) ;
break;
default:
goto V_65;
}
break;
}
case V_84 : {
switch ( V_29 -> V_68 ) {
case V_89 :
F_63 ( V_23 , V_29 , error ,
V_172 , V_173 ) ;
break;
case V_85 :
F_63 ( V_23 , V_29 , error ,
V_173 , V_174 ) ;
break;
case V_113 : {
struct V_114 * V_175 = (struct V_114 * )
( V_80 + sizeof( struct V_112 ) ) ;
if ( ! error ) {
V_23 -> V_176 = F_58 ( V_175 -> V_177 ) ;
V_23 -> V_51 |= ( V_175 -> V_178 & V_179 ) ;
}
F_63 ( V_23 , V_29 , error ,
V_174 , V_166 ) ;
break;
}
default:
goto V_65;
}
break;
}
case V_67 : {
switch ( V_29 -> V_68 ) {
case V_69 :
F_57 ( V_23 , V_29 , V_80 , error ) ;
break;
default:
goto V_65;
}
break;
}
default:
goto V_65;
}
return;
V_65:
F_59 (KERN_WARNING DRV_NAME L_18 ,
pci_name(host->pdev), crq->msg_type, crq->msg_subtype) ;
F_42 ( V_23 , V_29 , V_132 ) ;
}
static inline void F_70 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
struct V_180 * V_181 = (struct V_180 * ) V_23 -> V_182 ;
unsigned int V_183 = 0 ;
unsigned int V_62 = V_23 -> V_184 % V_101 ;
while ( 1 ) {
T_1 V_170 = F_58 ( V_181 [ V_62 ] . V_170 ) ;
if ( V_170 == 0xffffffff ) {
F_9 ( L_19 , V_62 ) ;
F_5 ( V_62 << 3 , V_20 + V_185 ) ;
break;
}
else if ( ( V_170 & ( 1 << 31 ) ) == 0 ) {
F_9 ( L_20 , V_62 ) ;
F_66 ( V_23 , V_181 [ V_62 ] . V_186 , V_170 ) ;
V_181 [ V_62 ] . V_170 = F_24 ( 0xffffffff ) ;
}
else if ( ( V_170 & 0xff000000 ) == ( 1 << 31 ) ) {
V_10 * V_187 = ( V_10 * ) & V_181 [ V_62 ] ;
V_10 V_188 = * V_187 ;
F_59 (KERN_WARNING DRV_NAME L_21 ,
pci_name(host->pdev), (int) evt_type) ;
V_181 [ V_62 ] . V_170 = F_24 ( 0xffffffff ) ;
}
V_62 = F_71 ( V_62 ) ;
V_183 ++ ;
}
F_9 ( L_22 , V_183 ) ;
V_23 -> V_184 += V_183 ;
}
static T_10 F_72 ( int V_189 , void * V_190 )
{
struct V_22 * V_23 = V_190 ;
void T_2 * V_20 ;
T_1 V_191 ;
int V_192 = 0 ;
unsigned long V_51 ;
if ( ! V_23 ) {
F_9 ( L_23 ) ;
return V_193 ;
}
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_20 = V_23 -> V_20 ;
V_191 = F_10 ( V_20 + V_194 ) ;
if ( V_191 == 0 || V_191 == 0xffffffff ) {
F_9 ( L_24 , V_191 ) ;
goto V_150;
}
if ( V_191 & V_195 )
F_5 ( V_191 , V_20 + V_194 ) ;
if ( F_15 ( V_23 -> V_74 == V_196 ) ) {
F_9 ( L_25 , V_191 ) ;
goto V_150;
}
if ( V_191 & V_197 ) {
V_192 = 1 ;
F_70 ( V_23 ) ;
}
V_150:
F_18 ( & V_23 -> V_55 , V_51 ) ;
F_9 ( L_26 ) ;
return F_73 ( V_192 ) ;
}
static void F_74 ( struct V_198 * V_183 )
{
struct V_22 * V_23 =
F_75 ( V_183 , struct V_22 , V_162 ) ;
unsigned long V_51 ;
unsigned int V_74 ;
int V_35 , V_17 , V_199 ;
int V_200 = 0 ;
int V_164 = V_196 ;
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_74 = V_23 -> V_74 ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
F_11 ( L_27 , V_201 [ V_74 ] ) ;
switch ( V_74 ) {
case V_202 :
V_164 = V_172 ;
V_200 = 1 ;
break;
case V_172 :
V_35 = F_29 ( V_23 , F_32 ) ;
if ( V_35 ) {
V_164 = V_78 ;
V_200 = 1 ;
}
break;
case V_173 :
V_35 = F_29 ( V_23 , F_30 ) ;
if ( V_35 ) {
V_164 = V_78 ;
V_200 = 1 ;
}
break;
case V_174 :
V_35 = F_29 ( V_23 , F_34 ) ;
if ( V_35 ) {
V_164 = V_78 ;
V_200 = 1 ;
}
break;
case V_166 :
V_35 = F_29 ( V_23 , F_33 ) ;
if ( V_35 ) {
V_164 = V_78 ;
V_200 = 1 ;
}
break;
case V_75 :
V_23 -> V_153 = - 1 ;
V_164 = V_76 ;
V_200 = 1 ;
break;
case V_76 :
V_199 = - 1 ;
for ( V_17 = V_23 -> V_153 + 1 ; V_17 < V_111 ; V_17 ++ )
if ( V_23 -> V_165 & ( 1 << V_17 ) ) {
V_199 = V_17 ;
break;
}
if ( V_199 >= 0 ) {
V_23 -> V_153 = V_199 ;
V_35 = F_22 ( V_23 , V_199 ) ;
if ( V_35 ) {
V_164 = V_78 ;
V_200 = 1 ;
}
} else {
V_164 = V_203 ;
V_200 = 1 ;
}
break;
case V_203 : {
int V_204 = 0 ;
for ( V_17 = 0 ; V_17 < V_111 ; V_17 ++ )
if ( V_23 -> V_160 & ( 1 << V_17 ) ) {
struct V_5 * V_6 = & V_23 -> V_6 [ V_17 ] ;
struct V_205 * V_206 = V_6 -> V_206 ;
F_76 ( V_206 , V_6 -> V_156 ) ;
F_77 ( V_206 ) ;
V_204 ++ ;
}
F_59 (KERN_INFO DRV_NAME L_28 ,
pci_name(host->pdev), activated) ;
V_164 = V_207 ;
V_200 = 1 ;
break;
}
case V_207 :
F_78 ( & V_23 -> V_208 ) ;
break;
case V_78 :
break;
default:
F_59 (KERN_ERR PFX L_29 , state) ;
assert ( 0 ) ;
break;
}
if ( V_164 != V_196 ) {
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_23 -> V_74 = V_164 ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
}
if ( V_200 )
F_61 ( & V_23 -> V_162 ) ;
}
static int F_79 ( void T_2 * V_20 , T_1 V_209 , unsigned int V_210 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < 50000 ; V_17 ++ ) {
T_1 V_34 = F_10 ( V_20 + V_211 ) ;
F_80 ( 100 ) ;
if ( V_210 ) {
if ( ( V_34 & V_209 ) == V_209 )
return 0 ;
} else {
if ( ( V_34 & V_209 ) == 0 )
return 0 ;
}
F_81 () ;
}
F_59 (KERN_ERR PFX L_30 ,
bits, test_bit ? L_31 : L_32 ) ;
return - V_38 ;
}
static void F_82 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
unsigned int V_17 ;
struct V_180 * V_181 = (struct V_180 * ) V_23 -> V_182 ;
for ( V_17 = 0 ; V_17 < V_101 ; V_17 ++ )
V_181 [ V_17 ] . V_170 = F_24 ( 0xffffffff ) ;
F_5 ( 0 , V_20 + V_185 ) ;
}
static int F_83 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
T_1 V_34 ;
V_10 V_212 ;
int V_35 ;
F_11 ( L_1 ) ;
F_5 ( 0 , V_20 + V_213 ) ;
V_212 = F_84 ( V_20 + V_214 ) ;
if ( V_212 & 0x01 ) {
V_212 &= ~ 0x01 ;
F_85 ( V_212 , V_20 + V_214 ) ;
F_84 ( V_20 + V_214 ) ;
F_11 ( L_33 ) ;
F_19 ( 5000 ) ;
}
V_34 = F_10 ( V_20 + V_36 ) ;
if ( V_34 & V_215 ) {
F_11 ( L_34 ) ;
V_35 = F_79 ( V_20 , V_215 , 1 ) ;
if ( V_35 ) {
F_11 ( L_35 ) ;
return V_35 ;
}
}
if ( V_34 & V_216 ) {
F_11 ( L_36 ) ;
V_35 = F_79 ( V_20 , V_216 , 1 ) ;
if ( V_35 ) {
F_11 ( L_37 ) ;
return V_35 ;
}
}
V_34 &= ~ ( V_216 | V_215 ) ;
F_5 ( V_34 , V_20 + V_36 ) ;
F_10 ( V_20 + V_36 ) ;
V_35 = F_79 ( V_20 , V_216 | V_215 , 0 ) ;
if ( V_35 ) {
F_11 ( L_38 ) ;
return V_35 ;
}
F_4 ( V_20 ) ;
F_5 ( V_23 -> V_94 & 0xffffffff , V_20 + V_217 ) ;
F_5 ( ( V_23 -> V_94 >> 16 ) >> 16 , V_20 + V_218 ) ;
F_5 ( V_103 , V_20 + V_219 ) ;
V_34 = F_10 ( V_20 + V_36 ) ;
V_34 |= ( V_216 | V_215 | V_220 ) ;
F_5 ( V_34 , V_20 + V_36 ) ;
F_10 ( V_20 + V_36 ) ;
V_35 = F_79 ( V_20 , V_216 | V_215 , 1 ) ;
if ( V_35 ) {
F_11 ( L_39 ) ;
return V_35 ;
}
F_5 ( 0 , V_20 + V_221 ) ;
F_5 ( V_222 , V_20 + V_213 ) ;
F_82 ( V_23 ) ;
F_26 ( & V_23 -> V_55 ) ;
assert ( V_23 -> V_74 == V_196 ) ;
V_23 -> V_74 = V_202 ;
F_27 ( & V_23 -> V_55 ) ;
F_61 ( & V_23 -> V_162 ) ;
F_11 ( L_26 ) ;
return 0 ;
}
static int F_86 ( struct V_22 * V_23 )
{
unsigned int V_17 ;
int V_35 = 0 ;
for ( V_17 = 0 ; V_17 < V_111 ; V_17 ++ ) {
struct V_205 * V_206 ;
struct V_115 * V_116 ;
struct V_5 * V_6 ;
V_6 = & V_23 -> V_6 [ V_17 ] ;
V_6 -> V_23 = V_23 ;
V_6 -> V_137 = V_17 ;
V_206 = F_87 ( V_223 ) ;
if ( ! V_206 ) {
V_35 = - V_64 ;
break;
}
V_6 -> V_206 = V_206 ;
sprintf ( V_206 -> V_224 , V_225 L_40 ,
( unsigned int ) ( V_23 -> V_136 * V_111 ) + V_17 ) ;
V_206 -> V_226 = V_23 -> V_226 ;
V_206 -> V_227 = V_17 * V_223 ;
V_206 -> V_228 = & V_229 ;
V_206 -> V_8 = V_6 ;
V_116 = F_88 ( F_46 , & V_23 -> V_55 ) ;
if ( ! V_116 ) {
V_35 = - V_64 ;
break;
}
V_206 -> V_230 = V_116 ;
F_89 ( V_116 , V_42 ) ;
F_90 ( V_116 , V_231 ) ;
V_116 -> V_123 = V_6 ;
}
return V_35 ;
}
static void F_91 ( struct V_22 * V_23 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_111 ; V_17 ++ ) {
struct V_205 * V_206 = V_23 -> V_6 [ V_17 ] . V_206 ;
if ( V_206 ) {
struct V_115 * V_116 = V_206 -> V_230 ;
if ( V_206 -> V_51 & V_232 )
F_92 ( V_206 ) ;
if ( V_116 )
F_93 ( V_116 ) ;
F_94 ( V_206 ) ;
}
}
}
static int F_95 ( struct V_22 * V_23 )
{
V_23 -> V_182 = F_96 ( V_23 -> V_133 , V_233 ,
& V_23 -> V_94 ) ;
if ( ! V_23 -> V_182 )
return - V_64 ;
V_23 -> V_25 = V_23 -> V_182 + V_103 ;
V_23 -> V_27 = V_23 -> V_94 + V_103 ;
memset ( V_23 -> V_182 , 0xff , V_103 ) ;
memset ( V_23 -> V_25 , 0 , V_95 - V_103 ) ;
return 0 ;
}
static int F_97 ( struct V_234 * V_133 , const struct V_235 * V_236 )
{
struct V_22 * V_23 ;
unsigned int V_237 ;
int V_35 ;
struct V_115 * V_116 ;
unsigned int V_17 ;
F_98 (KERN_DEBUG DRV_NAME L_41 DRV_VERSION L_42 ) ;
V_35 = F_99 ( V_133 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_100 ( V_133 , V_225 ) ;
if ( V_35 )
goto V_65;
#ifdef F_101
V_35 = F_102 ( V_133 , F_103 ( 64 ) ) ;
if ( ! V_35 ) {
V_35 = F_104 ( V_133 , F_103 ( 64 ) ) ;
if ( V_35 ) {
F_59 (KERN_ERR DRV_NAME L_43 ,
pci_name(pdev)) ;
goto V_238;
}
V_237 = 1 ;
} else {
#endif
V_35 = F_102 ( V_133 , F_103 ( 32 ) ) ;
if ( V_35 ) {
F_59 (KERN_ERR DRV_NAME L_44 ,
pci_name(pdev)) ;
goto V_238;
}
V_237 = 0 ;
#ifdef F_101
}
#endif
V_23 = F_105 ( sizeof( * V_23 ) , V_58 ) ;
if ( ! V_23 ) {
F_59 (KERN_ERR DRV_NAME L_45 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_238;
}
V_23 -> V_133 = V_133 ;
V_23 -> V_51 = V_237 ? V_239 : 0 ;
F_106 ( & V_23 -> V_55 ) ;
F_107 ( & V_23 -> V_162 , F_74 ) ;
F_108 ( & V_23 -> V_208 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_23 -> V_45 ) ; V_17 ++ )
V_23 -> V_45 [ V_17 ] . V_31 = V_17 ;
V_23 -> V_20 = F_109 ( F_110 ( V_133 , 0 ) ,
F_111 ( V_133 , 0 ) ) ;
if ( ! V_23 -> V_20 ) {
F_59 (KERN_ERR DRV_NAME L_46 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_240;
}
V_35 = F_95 ( V_23 ) ;
if ( V_35 ) {
F_59 (KERN_ERR DRV_NAME L_47 ,
pci_name(pdev)) ;
goto V_241;
}
V_116 = F_88 ( F_43 , & V_23 -> V_55 ) ;
if ( ! V_116 ) {
F_59 (KERN_ERR DRV_NAME L_48 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_242;
}
V_23 -> V_56 = V_116 ;
V_116 -> V_123 = V_23 ;
if ( ! F_112 ( 0 , & V_243 ) )
V_23 -> V_226 = 160 ;
else if ( ! F_112 ( 1 , & V_243 ) )
V_23 -> V_226 = 161 ;
else
V_23 -> V_51 |= V_244 ;
V_23 -> V_136 = V_245 ;
sprintf ( V_23 -> V_161 , V_225 L_49 , V_245 ) ;
V_35 = F_113 ( V_23 -> V_226 , V_23 -> V_161 ) ;
if ( V_35 < 0 )
goto V_246;
if ( V_23 -> V_51 & V_244 )
V_23 -> V_226 = V_35 ;
V_35 = F_86 ( V_23 ) ;
if ( V_35 )
goto V_247;
F_114 ( V_133 ) ;
V_35 = F_115 ( V_133 -> V_189 , F_72 , V_248 , V_225 , V_23 ) ;
if ( V_35 ) {
F_59 (KERN_ERR DRV_NAME L_50 ,
pci_name(pdev)) ;
goto V_247;
}
V_35 = F_83 ( V_23 ) ;
if ( V_35 )
goto V_249;
F_11 ( L_51 ) ;
F_116 ( & V_23 -> V_208 ) ;
F_59 ( V_250 L_52 ,
V_23 -> V_161 , F_117 ( V_133 ) , ( int ) V_111 ,
( unsigned long long ) F_110 ( V_133 , 0 ) ,
V_133 -> V_189 , V_23 -> V_226 ) ;
V_245 ++ ;
F_118 ( V_133 , V_23 ) ;
return 0 ;
V_249:
F_119 ( V_133 -> V_189 , V_23 ) ;
V_247:
F_91 ( V_23 ) ;
F_120 ( V_23 -> V_226 , V_23 -> V_161 ) ;
V_246:
if ( V_23 -> V_226 == 160 )
F_121 ( 0 , & V_243 ) ;
else if ( V_23 -> V_226 == 161 )
F_121 ( 1 , & V_243 ) ;
F_93 ( V_23 -> V_56 ) ;
V_242:
F_122 ( V_133 , V_233 , V_23 -> V_182 , V_23 -> V_94 ) ;
V_241:
F_123 ( V_23 -> V_20 ) ;
V_240:
F_124 ( V_23 ) ;
V_238:
F_125 ( V_133 ) ;
V_65:
F_126 ( V_133 ) ;
return V_35 ;
}
static void F_127 ( struct V_234 * V_133 )
{
struct V_22 * V_23 = F_128 ( V_133 ) ;
if ( ! V_23 ) {
F_59 (KERN_ERR PFX L_53 ,
pci_name(pdev)) ;
return;
}
F_119 ( V_133 -> V_189 , V_23 ) ;
F_91 ( V_23 ) ;
F_120 ( V_23 -> V_226 , V_23 -> V_161 ) ;
if ( V_23 -> V_226 == 160 )
F_121 ( 0 , & V_243 ) ;
else if ( V_23 -> V_226 == 161 )
F_121 ( 1 , & V_243 ) ;
F_93 ( V_23 -> V_56 ) ;
F_122 ( V_133 , V_233 , V_23 -> V_182 , V_23 -> V_94 ) ;
F_123 ( V_23 -> V_20 ) ;
F_124 ( V_23 ) ;
F_125 ( V_133 ) ;
F_126 ( V_133 ) ;
}
