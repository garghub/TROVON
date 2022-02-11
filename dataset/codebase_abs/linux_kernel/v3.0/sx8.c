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
if ( ! V_53 ) {
F_17 ( & V_23 -> V_55 , V_51 ) ;
F_14 ( V_23 , V_29 ) ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
return NULL ;
}
V_29 -> V_53 = V_53 ;
return V_29 ;
}
static int F_21 ( struct V_22 * V_23 , unsigned int V_59 )
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
V_63 = ( T_1 ) ( V_27 + sizeof( struct F_21 ) ) ;
V_29 -> V_66 = V_67 ;
V_29 -> V_68 = V_69 ;
V_35 = F_2 ( sizeof( struct V_60 ) +
sizeof( struct F_21 ) ) ;
F_22 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_67 ;
V_61 -> V_70 = V_69 ;
V_61 -> V_71 = ( V_10 ) V_59 ;
V_61 -> V_72 = F_23 ( F_24 ( V_62 ) ) ;
V_61 -> V_73 = F_23 ( V_63 ) ;
F_25 ( & V_23 -> V_55 ) ;
assert ( V_23 -> V_74 == V_75 ||
V_23 -> V_74 == V_76 ) ;
F_26 ( & V_23 -> V_55 ) ;
F_11 ( L_4 , V_62 ) ;
F_27 ( V_23 -> V_56 , V_29 -> V_53 , 1 , V_29 ) ;
return 0 ;
V_65:
F_25 ( & V_23 -> V_55 ) ;
V_23 -> V_74 = V_77 ;
F_26 ( & V_23 -> V_55 ) ;
return V_35 ;
}
static int F_28 ( struct V_22 * V_23 , T_4 V_78 )
{
struct V_28 * V_29 ;
struct V_60 * V_61 ;
void * V_79 ;
unsigned int V_62 , V_16 ;
int V_35 ;
V_29 = F_16 ( V_23 ) ;
if ( ! V_29 )
return - V_64 ;
V_62 = V_29 -> V_31 ;
V_79 = F_6 ( V_23 , V_62 ) ;
V_16 = V_78 ( V_23 , V_62 , V_79 ) ;
V_61 = V_79 ;
V_29 -> V_66 = V_61 -> type ;
V_29 -> V_68 = V_61 -> V_70 ;
V_35 = F_2 ( V_16 ) ;
F_22 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
F_11 ( L_4 , V_62 ) ;
F_27 ( V_23 -> V_56 , V_29 -> V_53 , 1 , V_29 ) ;
return 0 ;
}
static unsigned int F_29 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_79 )
{
struct V_80 V_81 ;
struct V_82 * V_83 = V_79 ;
F_30 ( & V_81 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> type = V_84 ;
V_83 -> V_70 = V_85 ;
V_83 -> V_72 = F_23 ( F_24 ( V_62 ) ) ;
V_83 -> V_86 = F_23 ( V_81 . V_87 ) ;
return sizeof( struct V_82 ) ;
}
static unsigned int F_31 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_79 )
{
struct V_88 * V_89 = V_79 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> type = V_84 ;
V_89 -> V_70 = V_90 ;
V_89 -> V_72 = F_23 ( F_24 ( V_62 ) ) ;
V_89 -> V_91 = 1 ;
V_89 -> V_92 = V_93 ;
V_89 -> V_94 = F_23 ( V_23 -> V_95 + ( V_96 >> 1 ) ) ;
V_89 -> V_97 = F_23 ( V_96 >> 1 ) ;
V_89 -> V_98 = F_23 ( V_23 -> V_95 + ( 16 * 1024 ) ) ;
V_89 -> V_99 = F_23 ( 1024 ) ;
V_89 -> V_100 = F_23 ( V_23 -> V_95 ) ;
V_89 -> V_101 = F_23 ( V_102 ) ;
V_89 -> V_103 = F_23 ( V_23 -> V_95 + V_104 ) ;
V_89 -> V_105 = F_23 ( V_106 ) ;
V_89 -> V_49 [ 0 ] . V_107 = F_23 ( V_23 -> V_95 + ( V_96 >> 1 ) ) ;
V_89 -> V_49 [ 0 ] . V_97 = F_23 ( 65536 ) ;
return sizeof( struct V_88 ) ;
}
static unsigned int F_32 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_79 )
{
struct V_60 * V_61 = V_79 ;
T_1 V_63 = ( T_1 ) ( F_7 ( V_23 , V_62 ) +
V_108 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_109 ;
V_61 -> V_70 = V_110 ;
V_61 -> V_72 = F_23 ( F_24 ( V_62 ) ) ;
V_61 -> V_73 = F_23 ( V_63 ) ;
V_79 += V_108 ;
memset ( V_79 , V_111 , V_112 ) ;
return V_108 + V_112 ;
}
static unsigned int F_33 ( struct V_22 * V_23 ,
unsigned int V_62 , void * V_79 )
{
struct V_113 * V_61 = V_79 ;
T_1 V_63 = ( T_1 ) ( F_7 ( V_23 , V_62 ) + sizeof( * V_61 ) ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_84 ;
V_61 -> V_70 = V_114 ;
V_61 -> V_72 = F_23 ( F_24 ( V_62 ) ) ;
V_61 -> V_73 = F_23 ( V_63 ) ;
return sizeof( struct V_113 ) +
sizeof( struct V_115 ) ;
}
static inline void F_34 ( struct V_22 * V_23 ,
struct V_28 * V_29 ,
int error )
{
struct V_52 * V_45 = V_29 -> V_53 ;
int V_35 ;
F_35 ( V_45 , error ) ;
V_35 = F_14 ( V_23 , V_29 ) ;
assert ( V_35 == 0 ) ;
}
static inline void F_36 ( struct V_22 * V_23 , struct V_116 * V_117 )
{
unsigned int V_62 = V_23 -> V_118 % V_119 ;
F_37 ( V_117 ) ;
F_9 ( L_5 , V_117 ) ;
V_23 -> V_120 [ V_62 ] = V_117 ;
V_23 -> V_118 ++ ;
F_22 ( V_23 -> V_118 == V_23 -> V_121 ) ;
}
static inline struct V_116 * F_38 ( struct V_22 * V_23 )
{
unsigned int V_62 ;
if ( V_23 -> V_118 == V_23 -> V_121 )
return NULL ;
V_62 = V_23 -> V_121 % V_119 ;
V_23 -> V_121 ++ ;
return V_23 -> V_120 [ V_62 ] ;
}
static inline void F_39 ( struct V_22 * V_23 )
{
struct V_116 * V_117 = F_38 ( V_23 ) ;
if ( V_117 ) {
F_40 ( V_117 ) ;
F_9 ( L_6 , V_117 ) ;
}
}
static inline void F_41 ( struct V_22 * V_23 , struct V_28 * V_29 ,
int error )
{
F_34 ( V_23 , V_29 , error ) ;
if ( V_43 == 1 )
F_39 ( V_23 ) ;
else if ( ( V_23 -> V_47 <= V_122 ) &&
( V_23 -> V_40 <= V_123 ) ) {
F_39 ( V_23 ) ;
}
}
static void F_42 ( struct V_116 * V_117 )
{
struct V_22 * V_23 = V_117 -> V_124 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
int V_35 ;
while ( 1 ) {
F_11 ( L_7 ) ;
V_53 = F_43 ( V_117 ) ;
if ( ! V_53 )
break;
V_29 = V_53 -> V_125 ;
assert ( V_29 != NULL ) ;
assert ( V_29 -> V_53 == V_53 ) ;
V_29 -> V_46 = 0 ;
F_11 ( L_8 ) ;
V_35 = F_8 ( V_23 , V_29 ) ;
if ( V_35 ) {
F_44 ( V_117 , V_53 ) ;
F_36 ( V_23 , V_117 ) ;
return;
}
}
}
static void F_45 ( struct V_116 * V_117 )
{
struct V_5 * V_6 = V_117 -> V_124 ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_126 * V_30 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
struct V_127 * V_49 ;
int V_128 = 0 , V_129 , V_17 , V_46 , V_35 ;
T_1 V_34 ;
unsigned int V_16 ;
V_130:
F_9 ( L_7 ) ;
V_53 = F_46 ( V_117 ) ;
if ( ! V_53 )
return;
V_29 = F_12 ( V_23 ) ;
if ( ! V_29 ) {
F_36 ( V_23 , V_117 ) ;
return;
}
V_29 -> V_53 = V_53 ;
F_47 ( V_53 ) ;
if ( F_48 ( V_53 ) == V_57 ) {
V_128 = 1 ;
V_129 = V_131 ;
} else {
V_129 = V_132 ;
}
V_49 = & V_29 -> V_49 [ 0 ] ;
V_46 = F_49 ( V_117 , V_53 , V_49 ) ;
if ( V_46 <= 0 ) {
F_41 ( V_23 , V_29 , - V_133 ) ;
return;
}
V_46 = F_50 ( V_23 -> V_134 , V_49 , V_46 , V_129 ) ;
if ( V_46 <= 0 ) {
F_41 ( V_23 , V_29 , - V_133 ) ;
return;
}
V_29 -> V_46 = V_46 ;
V_29 -> V_6 = V_6 ;
V_23 -> V_40 += V_46 ;
F_9 ( L_9 ) ;
V_30 = (struct V_126 * ) F_6 ( V_23 , V_29 -> V_31 ) ;
if ( V_128 ) {
V_30 -> type = V_135 ;
V_29 -> V_66 = V_135 ;
} else {
V_30 -> type = V_136 ;
V_29 -> V_66 = V_136 ;
}
V_30 -> V_137 = V_6 -> V_138 ;
V_30 -> V_139 = V_46 ;
V_30 -> V_92 = V_93 ;
V_30 -> V_72 = F_23 ( F_24 ( V_29 -> V_31 ) ) ;
V_30 -> V_140 = F_23 ( F_51 ( V_53 ) & 0xffffffff ) ;
V_34 = ( F_51 ( V_53 ) >> 16 ) >> 16 ;
V_30 -> V_141 = F_52 ( ( V_142 ) V_34 ) ;
V_30 -> V_143 = F_52 ( F_53 ( V_53 ) ) ;
V_16 = sizeof( struct V_126 ) - sizeof( V_30 -> V_49 ) ;
for ( V_17 = 0 ; V_17 < V_46 ; V_17 ++ ) {
struct V_144 * V_145 = & V_30 -> V_49 [ V_17 ] ;
V_145 -> V_107 = F_23 ( F_54 ( & V_29 -> V_49 [ V_17 ] ) ) ;
V_145 -> V_97 = F_23 ( F_55 ( & V_29 -> V_49 [ V_17 ] ) ) ;
V_16 += sizeof( struct V_144 ) ;
}
V_35 = F_2 ( V_16 ) ;
F_22 ( V_35 < 0 ) ;
V_29 -> V_33 = ( T_1 ) V_35 ;
F_9 ( L_10 , V_29 -> V_31 ) ;
V_35 = F_8 ( V_23 , V_29 ) ;
if ( V_35 ) {
F_14 ( V_23 , V_29 ) ;
F_44 ( V_117 , V_53 ) ;
F_36 ( V_23 , V_117 ) ;
return;
}
goto V_130;
}
static void F_56 ( struct V_22 * V_23 ,
struct V_28 * V_29 , V_10 * V_79 ,
int error )
{
struct V_5 * V_6 ;
V_10 * V_63 = V_79 + sizeof( struct F_21 ) ;
struct F_21 * V_146 = (struct F_21 * ) V_63 ;
T_5 V_147 , V_148 ;
int V_149 ;
T_6 V_150 ;
F_11 ( L_1 ) ;
F_41 ( V_23 , V_29 , error ) ;
if ( error )
goto V_151;
if ( F_57 ( V_146 -> V_152 ) & V_153 )
goto V_151;
V_149 = V_23 -> V_154 ;
if ( ( V_149 < 0 ) || ( V_149 >= V_112 ) ) {
F_58 (KERN_ERR PFX L_11 ,
cur_port, (int) desc->array_id) ;
goto V_151;
}
V_6 = & V_23 -> V_6 [ V_149 ] ;
V_147 = ( T_5 ) F_57 ( V_146 -> V_155 ) ;
V_148 = ( T_5 ) F_59 ( V_146 -> V_156 ) ;
V_6 -> V_157 = V_147 | ( V_148 << 32 ) ;
V_6 -> V_11 = F_59 ( V_146 -> V_158 ) ;
V_6 -> V_13 = F_59 ( V_146 -> V_159 ) ;
V_6 -> V_15 = F_59 ( V_146 -> V_160 ) ;
V_23 -> V_161 |= ( 1 << V_149 ) ;
strncpy ( V_6 -> V_162 , V_146 -> V_162 , sizeof( V_6 -> V_162 ) ) ;
V_6 -> V_162 [ sizeof( V_6 -> V_162 ) - 1 ] = 0 ;
V_150 = strlen ( V_6 -> V_162 ) ;
while ( V_150 && ( V_6 -> V_162 [ V_150 - 1 ] == ' ' ) ) {
V_6 -> V_162 [ V_150 - 1 ] = 0 ;
V_150 -- ;
}
F_58 (KERN_INFO DRV_NAME L_12 ,
pci_name(host->pdev), port->port_no,
(unsigned long long) port->capacity) ;
F_58 (KERN_INFO DRV_NAME L_13 ,
pci_name(host->pdev), port->port_no, port->name) ;
V_151:
assert ( V_23 -> V_74 == V_76 ) ;
F_60 ( & V_23 -> V_163 ) ;
}
static void F_61 ( struct V_22 * V_23 ,
struct V_28 * V_29 , V_10 * V_79 ,
int error )
{
V_10 * V_63 = V_79 + V_108 ;
unsigned int V_17 , V_164 = 0 ;
int V_165 = V_75 ;
F_11 ( L_1 ) ;
F_41 ( V_23 , V_29 , error ) ;
if ( error ) {
V_165 = V_77 ;
goto V_151;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
if ( V_63 [ V_17 ] == 0 ) {
V_23 -> V_166 |= ( 1 << V_17 ) ;
V_164 ++ ;
}
F_58 (KERN_INFO DRV_NAME L_14 ,
pci_name(host->pdev), dev_count) ;
V_151:
assert ( V_23 -> V_74 == V_167 ) ;
V_23 -> V_74 = V_165 ;
F_60 ( & V_23 -> V_163 ) ;
}
static void F_62 ( struct V_22 * V_23 ,
struct V_28 * V_29 , int error ,
int V_168 , int V_169 )
{
F_11 ( L_1 ) ;
F_41 ( V_23 , V_29 , error ) ;
assert ( V_23 -> V_74 == V_168 ) ;
if ( error )
V_23 -> V_74 = V_77 ;
else
V_23 -> V_74 = V_169 ;
F_60 ( & V_23 -> V_163 ) ;
}
static inline void F_63 ( struct V_22 * V_23 ,
struct V_28 * V_29 , int error )
{
int V_129 ;
F_9 ( L_1 ) ;
if ( F_48 ( V_29 -> V_53 ) == V_57 )
V_129 = V_131 ;
else
V_129 = V_132 ;
F_64 ( V_23 -> V_134 , & V_29 -> V_49 [ 0 ] , V_29 -> V_46 , V_129 ) ;
F_41 ( V_23 , V_29 , error ) ;
}
static inline void F_65 ( struct V_22 * V_23 ,
T_7 V_170 , T_1 V_171 )
{
T_1 V_72 = F_57 ( V_170 ) ;
unsigned int V_24 ;
struct V_28 * V_29 ;
int error = ( V_171 == V_172 ) ? 0 : - V_133 ;
V_10 * V_79 ;
F_9 ( L_15 , V_72 ) ;
if ( F_15 ( ! F_66 ( V_72 ) ) ) {
F_58 (KERN_ERR DRV_NAME L_16 ,
pci_name(host->pdev), handle) ;
return;
}
V_24 = F_67 ( V_72 ) ;
F_9 ( L_17 , V_24 ) ;
V_29 = & V_23 -> V_45 [ V_24 ] ;
if ( F_68 ( V_29 -> V_66 == V_136 ||
V_29 -> V_66 == V_135 ) ) {
F_63 ( V_23 , V_29 , error ) ;
return;
}
V_79 = F_6 ( V_23 , V_24 ) ;
switch ( V_29 -> V_66 ) {
case V_109 : {
switch ( V_29 -> V_68 ) {
case V_110 :
F_61 ( V_23 , V_29 , V_79 , error ) ;
break;
default:
goto V_65;
}
break;
}
case V_84 : {
switch ( V_29 -> V_68 ) {
case V_90 :
F_62 ( V_23 , V_29 , error ,
V_173 , V_174 ) ;
break;
case V_85 :
F_62 ( V_23 , V_29 , error ,
V_174 , V_175 ) ;
break;
case V_114 : {
struct V_115 * V_176 = (struct V_115 * )
V_79 + sizeof( struct V_113 ) ;
if ( ! error ) {
V_23 -> V_177 = F_57 ( V_176 -> V_178 ) ;
V_23 -> V_51 |= ( V_176 -> V_179 & V_180 ) ;
}
F_62 ( V_23 , V_29 , error ,
V_175 , V_167 ) ;
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
F_56 ( V_23 , V_29 , V_79 , error ) ;
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
F_58 (KERN_WARNING DRV_NAME L_18 ,
pci_name(host->pdev), crq->msg_type, crq->msg_subtype) ;
F_41 ( V_23 , V_29 , - V_133 ) ;
}
static inline void F_69 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
struct V_181 * V_182 = (struct V_181 * ) V_23 -> V_183 ;
unsigned int V_184 = 0 ;
unsigned int V_62 = V_23 -> V_185 % V_102 ;
while ( 1 ) {
T_1 V_171 = F_57 ( V_182 [ V_62 ] . V_171 ) ;
if ( V_171 == 0xffffffff ) {
F_9 ( L_19 , V_62 ) ;
F_5 ( V_62 << 3 , V_20 + V_186 ) ;
break;
}
else if ( ( V_171 & ( 1 << 31 ) ) == 0 ) {
F_9 ( L_20 , V_62 ) ;
F_65 ( V_23 , V_182 [ V_62 ] . V_187 , V_171 ) ;
V_182 [ V_62 ] . V_171 = F_23 ( 0xffffffff ) ;
}
else if ( ( V_171 & 0xff000000 ) == ( 1 << 31 ) ) {
V_10 * V_188 = ( V_10 * ) & V_182 [ V_62 ] ;
V_10 V_189 = * V_188 ;
F_58 (KERN_WARNING DRV_NAME L_21 ,
pci_name(host->pdev), (int) evt_type) ;
V_182 [ V_62 ] . V_171 = F_23 ( 0xffffffff ) ;
}
V_62 = F_70 ( V_62 ) ;
V_184 ++ ;
}
F_9 ( L_22 , V_184 ) ;
V_23 -> V_185 += V_184 ;
}
static T_8 F_71 ( int V_190 , void * V_191 )
{
struct V_22 * V_23 = V_191 ;
void T_2 * V_20 ;
T_1 V_192 ;
int V_193 = 0 ;
unsigned long V_51 ;
if ( ! V_23 ) {
F_9 ( L_23 ) ;
return V_194 ;
}
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_20 = V_23 -> V_20 ;
V_192 = F_10 ( V_20 + V_195 ) ;
if ( V_192 == 0 || V_192 == 0xffffffff ) {
F_9 ( L_24 , V_192 ) ;
goto V_151;
}
if ( V_192 & V_196 )
F_5 ( V_192 , V_20 + V_195 ) ;
if ( F_15 ( V_23 -> V_74 == V_197 ) ) {
F_9 ( L_25 , V_192 ) ;
goto V_151;
}
if ( V_192 & V_198 ) {
V_193 = 1 ;
F_69 ( V_23 ) ;
}
V_151:
F_18 ( & V_23 -> V_55 , V_51 ) ;
F_9 ( L_26 ) ;
return F_72 ( V_193 ) ;
}
static void F_73 ( struct V_199 * V_184 )
{
struct V_22 * V_23 =
F_74 ( V_184 , struct V_22 , V_163 ) ;
unsigned long V_51 ;
unsigned int V_74 ;
int V_35 , V_17 , V_200 ;
int V_201 = 0 ;
int V_165 = V_197 ;
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_74 = V_23 -> V_74 ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
F_11 ( L_27 , V_202 [ V_74 ] ) ;
switch ( V_74 ) {
case V_203 :
V_165 = V_173 ;
V_201 = 1 ;
break;
case V_173 :
V_35 = F_28 ( V_23 , F_31 ) ;
if ( V_35 ) {
V_165 = V_77 ;
V_201 = 1 ;
}
break;
case V_174 :
V_35 = F_28 ( V_23 , F_29 ) ;
if ( V_35 ) {
V_165 = V_77 ;
V_201 = 1 ;
}
break;
case V_175 :
V_35 = F_28 ( V_23 , F_33 ) ;
if ( V_35 ) {
V_165 = V_77 ;
V_201 = 1 ;
}
break;
case V_167 :
V_35 = F_28 ( V_23 , F_32 ) ;
if ( V_35 ) {
V_165 = V_77 ;
V_201 = 1 ;
}
break;
case V_75 :
V_23 -> V_154 = - 1 ;
V_165 = V_76 ;
V_201 = 1 ;
break;
case V_76 :
V_200 = - 1 ;
for ( V_17 = V_23 -> V_154 + 1 ; V_17 < V_112 ; V_17 ++ )
if ( V_23 -> V_166 & ( 1 << V_17 ) ) {
V_200 = V_17 ;
break;
}
if ( V_200 >= 0 ) {
V_23 -> V_154 = V_200 ;
V_35 = F_21 ( V_23 , V_200 ) ;
if ( V_35 ) {
V_165 = V_77 ;
V_201 = 1 ;
}
} else {
V_165 = V_204 ;
V_201 = 1 ;
}
break;
case V_204 : {
int V_205 = 0 ;
for ( V_17 = 0 ; V_17 < V_112 ; V_17 ++ )
if ( V_23 -> V_161 & ( 1 << V_17 ) ) {
struct V_5 * V_6 = & V_23 -> V_6 [ V_17 ] ;
struct V_206 * V_207 = V_6 -> V_207 ;
F_75 ( V_207 , V_6 -> V_157 ) ;
F_76 ( V_207 ) ;
V_205 ++ ;
}
F_58 (KERN_INFO DRV_NAME L_28 ,
pci_name(host->pdev), activated) ;
V_165 = V_208 ;
V_201 = 1 ;
break;
}
case V_208 :
F_77 ( & V_23 -> V_209 ) ;
break;
case V_77 :
break;
default:
F_58 (KERN_ERR PFX L_29 , state) ;
assert ( 0 ) ;
break;
}
if ( V_165 != V_197 ) {
F_17 ( & V_23 -> V_55 , V_51 ) ;
V_23 -> V_74 = V_165 ;
F_18 ( & V_23 -> V_55 , V_51 ) ;
}
if ( V_201 )
F_60 ( & V_23 -> V_163 ) ;
}
static int F_78 ( void T_2 * V_20 , T_1 V_210 , unsigned int V_211 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < 50000 ; V_17 ++ ) {
T_1 V_34 = F_10 ( V_20 + V_212 ) ;
F_79 ( 100 ) ;
if ( V_211 ) {
if ( ( V_34 & V_210 ) == V_210 )
return 0 ;
} else {
if ( ( V_34 & V_210 ) == 0 )
return 0 ;
}
F_80 () ;
}
F_58 (KERN_ERR PFX L_30 ,
bits, test_bit ? L_31 : L_32 ) ;
return - V_38 ;
}
static void F_81 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
unsigned int V_17 ;
struct V_181 * V_182 = (struct V_181 * ) V_23 -> V_183 ;
for ( V_17 = 0 ; V_17 < V_102 ; V_17 ++ )
V_182 [ V_17 ] . V_171 = F_23 ( 0xffffffff ) ;
F_5 ( 0 , V_20 + V_186 ) ;
}
static int F_82 ( struct V_22 * V_23 )
{
void T_2 * V_20 = V_23 -> V_20 ;
T_1 V_34 ;
V_10 V_213 ;
int V_35 ;
F_11 ( L_1 ) ;
F_5 ( 0 , V_20 + V_214 ) ;
V_213 = F_83 ( V_20 + V_215 ) ;
if ( V_213 & 0x01 ) {
V_213 &= ~ 0x01 ;
F_84 ( V_213 , V_20 + V_215 ) ;
F_83 ( V_20 + V_215 ) ;
F_11 ( L_33 ) ;
F_19 ( 5000 ) ;
}
V_34 = F_10 ( V_20 + V_36 ) ;
if ( V_34 & V_216 ) {
F_11 ( L_34 ) ;
V_35 = F_78 ( V_20 , V_216 , 1 ) ;
if ( V_35 ) {
F_11 ( L_35 ) ;
return V_35 ;
}
}
if ( V_34 & V_217 ) {
F_11 ( L_36 ) ;
V_35 = F_78 ( V_20 , V_217 , 1 ) ;
if ( V_35 ) {
F_11 ( L_37 ) ;
return V_35 ;
}
}
V_34 &= ~ ( V_217 | V_216 ) ;
F_5 ( V_34 , V_20 + V_36 ) ;
F_10 ( V_20 + V_36 ) ;
V_35 = F_78 ( V_20 , V_217 | V_216 , 0 ) ;
if ( V_35 ) {
F_11 ( L_38 ) ;
return V_35 ;
}
F_4 ( V_20 ) ;
F_5 ( V_23 -> V_95 & 0xffffffff , V_20 + V_218 ) ;
F_5 ( ( V_23 -> V_95 >> 16 ) >> 16 , V_20 + V_219 ) ;
F_5 ( V_104 , V_20 + V_220 ) ;
V_34 = F_10 ( V_20 + V_36 ) ;
V_34 |= ( V_217 | V_216 | V_221 ) ;
F_5 ( V_34 , V_20 + V_36 ) ;
F_10 ( V_20 + V_36 ) ;
V_35 = F_78 ( V_20 , V_217 | V_216 , 1 ) ;
if ( V_35 ) {
F_11 ( L_39 ) ;
return V_35 ;
}
F_5 ( 0 , V_20 + V_222 ) ;
F_5 ( V_223 , V_20 + V_214 ) ;
F_81 ( V_23 ) ;
F_25 ( & V_23 -> V_55 ) ;
assert ( V_23 -> V_74 == V_197 ) ;
V_23 -> V_74 = V_203 ;
F_26 ( & V_23 -> V_55 ) ;
F_60 ( & V_23 -> V_163 ) ;
F_11 ( L_26 ) ;
return 0 ;
}
static int F_85 ( struct V_22 * V_23 )
{
unsigned int V_17 ;
int V_35 = 0 ;
for ( V_17 = 0 ; V_17 < V_112 ; V_17 ++ ) {
struct V_206 * V_207 ;
struct V_116 * V_117 ;
struct V_5 * V_6 ;
V_6 = & V_23 -> V_6 [ V_17 ] ;
V_6 -> V_23 = V_23 ;
V_6 -> V_138 = V_17 ;
V_207 = F_86 ( V_224 ) ;
if ( ! V_207 ) {
V_35 = - V_64 ;
break;
}
V_6 -> V_207 = V_207 ;
sprintf ( V_207 -> V_225 , V_226 L_40 ,
( unsigned int ) ( V_23 -> V_137 * V_112 ) + V_17 ) ;
V_207 -> V_227 = V_23 -> V_227 ;
V_207 -> V_228 = V_17 * V_224 ;
V_207 -> V_229 = & V_230 ;
V_207 -> V_8 = V_6 ;
V_117 = F_87 ( F_45 , & V_23 -> V_55 ) ;
if ( ! V_117 ) {
V_35 = - V_64 ;
break;
}
V_207 -> V_231 = V_117 ;
F_88 ( V_117 , V_42 ) ;
F_89 ( V_117 , V_232 ) ;
V_117 -> V_124 = V_6 ;
}
return V_35 ;
}
static void F_90 ( struct V_22 * V_23 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_112 ; V_17 ++ ) {
struct V_206 * V_207 = V_23 -> V_6 [ V_17 ] . V_207 ;
if ( V_207 ) {
struct V_116 * V_117 = V_207 -> V_231 ;
if ( V_207 -> V_51 & V_233 )
F_91 ( V_207 ) ;
if ( V_117 )
F_92 ( V_117 ) ;
F_93 ( V_207 ) ;
}
}
}
static int F_94 ( struct V_22 * V_23 )
{
V_23 -> V_183 = F_95 ( V_23 -> V_134 , V_234 ,
& V_23 -> V_95 ) ;
if ( ! V_23 -> V_183 )
return - V_64 ;
V_23 -> V_25 = V_23 -> V_183 + V_104 ;
V_23 -> V_27 = V_23 -> V_95 + V_104 ;
memset ( V_23 -> V_183 , 0xff , V_104 ) ;
memset ( V_23 -> V_25 , 0 , V_96 - V_104 ) ;
return 0 ;
}
static int F_96 ( struct V_235 * V_134 , const struct V_236 * V_237 )
{
struct V_22 * V_23 ;
unsigned int V_238 ;
int V_35 ;
struct V_116 * V_117 ;
unsigned int V_17 ;
F_97 (KERN_DEBUG DRV_NAME L_41 DRV_VERSION L_42 ) ;
V_35 = F_98 ( V_134 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_99 ( V_134 , V_226 ) ;
if ( V_35 )
goto V_65;
#ifdef F_100
V_35 = F_101 ( V_134 , F_102 ( 64 ) ) ;
if ( ! V_35 ) {
V_35 = F_103 ( V_134 , F_102 ( 64 ) ) ;
if ( V_35 ) {
F_58 (KERN_ERR DRV_NAME L_43 ,
pci_name(pdev)) ;
goto V_239;
}
V_238 = 1 ;
} else {
#endif
V_35 = F_101 ( V_134 , F_102 ( 32 ) ) ;
if ( V_35 ) {
F_58 (KERN_ERR DRV_NAME L_44 ,
pci_name(pdev)) ;
goto V_239;
}
V_238 = 0 ;
#ifdef F_100
}
#endif
V_23 = F_104 ( sizeof( * V_23 ) , V_58 ) ;
if ( ! V_23 ) {
F_58 (KERN_ERR DRV_NAME L_45 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_239;
}
V_23 -> V_134 = V_134 ;
V_23 -> V_51 = V_238 ? V_240 : 0 ;
F_105 ( & V_23 -> V_55 ) ;
F_106 ( & V_23 -> V_163 , F_73 ) ;
F_107 ( & V_23 -> V_209 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_23 -> V_45 ) ; V_17 ++ )
V_23 -> V_45 [ V_17 ] . V_31 = V_17 ;
V_23 -> V_20 = F_108 ( F_109 ( V_134 , 0 ) ,
F_110 ( V_134 , 0 ) ) ;
if ( ! V_23 -> V_20 ) {
F_58 (KERN_ERR DRV_NAME L_46 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_241;
}
V_35 = F_94 ( V_23 ) ;
if ( V_35 ) {
F_58 (KERN_ERR DRV_NAME L_47 ,
pci_name(pdev)) ;
goto V_242;
}
V_117 = F_87 ( F_42 , & V_23 -> V_55 ) ;
if ( ! V_117 ) {
F_58 (KERN_ERR DRV_NAME L_48 ,
pci_name(pdev)) ;
V_35 = - V_64 ;
goto V_243;
}
V_23 -> V_56 = V_117 ;
V_117 -> V_124 = V_23 ;
if ( ! F_111 ( 0 , & V_244 ) )
V_23 -> V_227 = 160 ;
else if ( ! F_111 ( 1 , & V_244 ) )
V_23 -> V_227 = 161 ;
else
V_23 -> V_51 |= V_245 ;
V_23 -> V_137 = V_246 ;
sprintf ( V_23 -> V_162 , V_226 L_49 , V_246 ) ;
V_35 = F_112 ( V_23 -> V_227 , V_23 -> V_162 ) ;
if ( V_35 < 0 )
goto V_247;
if ( V_23 -> V_51 & V_245 )
V_23 -> V_227 = V_35 ;
V_35 = F_85 ( V_23 ) ;
if ( V_35 )
goto V_248;
F_113 ( V_134 ) ;
V_35 = F_114 ( V_134 -> V_190 , F_71 , V_249 , V_226 , V_23 ) ;
if ( V_35 ) {
F_58 (KERN_ERR DRV_NAME L_50 ,
pci_name(pdev)) ;
goto V_248;
}
V_35 = F_82 ( V_23 ) ;
if ( V_35 )
goto V_250;
F_11 ( L_51 ) ;
F_115 ( & V_23 -> V_209 ) ;
F_58 ( V_251 L_52 ,
V_23 -> V_162 , F_116 ( V_134 ) , ( int ) V_112 ,
( unsigned long long ) F_109 ( V_134 , 0 ) ,
V_134 -> V_190 , V_23 -> V_227 ) ;
V_246 ++ ;
F_117 ( V_134 , V_23 ) ;
return 0 ;
V_250:
F_118 ( V_134 -> V_190 , V_23 ) ;
V_248:
F_90 ( V_23 ) ;
F_119 ( V_23 -> V_227 , V_23 -> V_162 ) ;
V_247:
if ( V_23 -> V_227 == 160 )
F_120 ( 0 , & V_244 ) ;
else if ( V_23 -> V_227 == 161 )
F_120 ( 1 , & V_244 ) ;
F_92 ( V_23 -> V_56 ) ;
V_243:
F_121 ( V_134 , V_234 , V_23 -> V_183 , V_23 -> V_95 ) ;
V_242:
F_122 ( V_23 -> V_20 ) ;
V_241:
F_123 ( V_23 ) ;
V_239:
F_124 ( V_134 ) ;
V_65:
F_125 ( V_134 ) ;
return V_35 ;
}
static void F_126 ( struct V_235 * V_134 )
{
struct V_22 * V_23 = F_127 ( V_134 ) ;
if ( ! V_23 ) {
F_58 (KERN_ERR PFX L_53 ,
pci_name(pdev)) ;
return;
}
F_118 ( V_134 -> V_190 , V_23 ) ;
F_90 ( V_23 ) ;
F_119 ( V_23 -> V_227 , V_23 -> V_162 ) ;
if ( V_23 -> V_227 == 160 )
F_120 ( 0 , & V_244 ) ;
else if ( V_23 -> V_227 == 161 )
F_120 ( 1 , & V_244 ) ;
F_92 ( V_23 -> V_56 ) ;
F_121 ( V_134 , V_234 , V_23 -> V_183 , V_23 -> V_95 ) ;
F_122 ( V_23 -> V_20 ) ;
F_123 ( V_23 ) ;
F_124 ( V_134 ) ;
F_125 ( V_134 ) ;
F_117 ( V_134 , NULL ) ;
}
static int T_9 F_128 ( void )
{
return F_129 ( & V_252 ) ;
}
static void T_10 F_130 ( void )
{
F_131 ( & V_252 ) ;
}
