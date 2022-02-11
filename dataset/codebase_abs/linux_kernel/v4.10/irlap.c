int T_1 F_1 ( void )
{
F_2 (sizeof(struct xid_frame) == 14 , ;) ;
F_2 (sizeof(struct test_frame) == 10 , ;) ;
F_2 (sizeof(struct ua_frame) == 10 , ;) ;
F_2 (sizeof(struct snrm_frame) == 11 , ;) ;
V_1 = F_3 ( V_2 ) ;
if ( V_1 == NULL ) {
F_4 ( L_1 ,
V_3 ) ;
return - V_4 ;
}
return 0 ;
}
void F_5 ( void )
{
F_2 (irlap != NULL, return;) ;
F_6 ( V_1 , ( V_5 ) V_6 ) ;
}
struct V_7 * F_7 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 )
{
struct V_7 * V_13 ;
V_13 = F_8 ( sizeof( struct V_7 ) , V_14 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_15 = V_16 ;
V_13 -> V_17 = V_9 ;
V_13 -> V_18 = V_11 ;
if( V_12 != NULL ) {
F_9 ( V_13 -> V_12 , V_12 , sizeof( V_13 -> V_12 ) ) ;
} else {
V_13 -> V_12 [ 0 ] = '\0' ;
}
V_9 -> V_19 = V_13 ;
V_13 -> V_20 = V_21 ;
F_10 ( & V_13 -> V_22 ) ;
F_10 ( & V_13 -> V_23 ) ;
F_10 ( & V_13 -> V_24 ) ;
do {
F_11 ( & V_13 -> V_25 , sizeof( V_13 -> V_25 ) ) ;
} while ( ( V_13 -> V_25 == 0x0 ) || ( V_13 -> V_25 == V_26 ) ||
( F_12 ( V_1 , V_13 -> V_25 , NULL ) ) );
memcpy ( V_9 -> V_27 , & V_13 -> V_25 , 4 ) ;
F_13 ( & V_13 -> V_28 ) ;
F_13 ( & V_13 -> V_29 ) ;
F_13 ( & V_13 -> V_30 ) ;
F_13 ( & V_13 -> V_31 ) ;
F_13 ( & V_13 -> V_32 ) ;
F_13 ( & V_13 -> V_33 ) ;
F_13 ( & V_13 -> V_34 ) ;
F_13 ( & V_13 -> V_35 ) ;
F_14 ( V_13 ) ;
V_13 -> V_36 = 3 ;
V_13 -> V_20 = V_37 ;
F_15 ( V_1 , ( V_38 * ) V_13 , V_13 -> V_25 , NULL ) ;
F_16 ( V_13 , V_13 -> V_25 , & V_13 -> V_39 ) ;
return V_13 ;
}
static void V_6 ( struct V_7 * V_13 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_17 ( & V_13 -> V_28 ) ;
F_17 ( & V_13 -> V_29 ) ;
F_17 ( & V_13 -> V_30 ) ;
F_17 ( & V_13 -> V_31 ) ;
F_17 ( & V_13 -> V_32 ) ;
F_17 ( & V_13 -> V_33 ) ;
F_17 ( & V_13 -> V_34 ) ;
F_17 ( & V_13 -> V_35 ) ;
F_18 ( V_13 ) ;
V_13 -> V_15 = 0 ;
F_19 ( V_13 ) ;
}
void F_20 ( struct V_7 * V_13 )
{
struct V_7 * V_40 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_21 ( V_13 -> V_25 ) ;
V_13 -> V_39 . V_41 = NULL ;
V_40 = F_22 ( V_1 , V_13 -> V_25 , NULL ) ;
if ( ! V_40 ) {
F_23 ( L_2 , V_3 ) ;
return;
}
V_6 ( V_40 ) ;
}
void F_24 ( struct V_7 * V_13 , struct V_42 * V_43 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_25 ( V_13 , NULL ) ;
F_26 ( V_13 -> V_39 . V_41 , V_13 -> V_25 ,
V_13 -> V_44 , & V_13 -> V_45 , V_43 ) ;
}
void F_27 ( struct V_7 * V_13 , struct V_42 * V_46 )
{
F_28 ( V_13 , V_47 , V_46 , NULL ) ;
}
void F_29 ( struct V_7 * V_13 , T_2 V_44 ,
struct V_10 * V_48 , int V_49 )
{
F_23 ( L_3 , V_3 , V_44 ) ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
V_13 -> V_44 = V_44 ;
F_25 ( V_13 , V_48 ) ;
if ( ( V_13 -> V_20 == V_37 ) && ! V_13 -> V_50 )
F_28 ( V_13 , V_51 , NULL , NULL ) ;
else
V_13 -> V_52 = TRUE ;
}
void F_30 ( struct V_7 * V_13 , struct V_42 * V_43 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_31 ( V_13 -> V_39 . V_41 , & V_13 -> V_45 , V_43 ) ;
}
void F_32 ( struct V_7 * V_13 , struct V_42 * V_43 ,
int V_53 )
{
F_33 ( V_43 , V_54 + V_55 ) ;
F_34 ( V_13 -> V_39 . V_41 , V_43 , V_53 ) ;
}
void F_35 ( struct V_7 * V_13 , struct V_42 * V_43 ,
int V_53 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (skb_headroom(skb) >= (LAP_ADDR_HEADER+LAP_CTRL_HEADER),
return;) ;
F_36 ( V_43 , V_54 + V_55 ) ;
if ( V_53 )
V_43 -> V_56 [ 1 ] = V_57 ;
else
V_43 -> V_56 [ 1 ] = V_58 ;
F_37 ( V_43 ) ;
F_38 ( & V_13 -> V_22 , V_43 ) ;
if ( ( V_13 -> V_20 == V_59 ) || ( V_13 -> V_20 == V_60 ) ) {
if( ( F_39 ( & V_13 -> V_22 ) <= 1 ) && ( ! V_13 -> V_61 ) )
F_28 ( V_13 , V_62 , V_43 , NULL ) ;
}
}
void F_40 ( struct V_7 * V_13 , struct V_42 * V_43 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (skb_headroom(skb) >= (LAP_ADDR_HEADER+LAP_CTRL_HEADER),
return;) ;
F_36 ( V_43 , V_54 + V_55 ) ;
V_43 -> V_56 [ 0 ] = V_63 ;
V_43 -> V_56 [ 1 ] = V_57 ;
F_38 ( & V_13 -> V_23 , V_43 ) ;
F_28 ( V_13 , V_64 , NULL , NULL ) ;
}
void F_41 ( struct V_7 * V_13 , struct V_42 * V_43 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (skb != NULL, return;) ;
F_33 ( V_43 , V_54 + V_55 ) ;
F_42 ( V_13 -> V_39 . V_41 , V_43 ) ;
}
void F_43 ( struct V_7 * V_13 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
if ( ! F_44 ( & V_13 -> V_22 ) ) {
V_13 -> V_65 = TRUE ;
return;
}
switch ( V_13 -> V_20 ) {
case V_59 :
case V_60 :
case V_66 :
case V_67 :
case V_68 :
F_28 ( V_13 , V_69 , NULL , NULL ) ;
break;
default:
F_23 ( L_4 , V_3 ) ;
V_13 -> V_65 = TRUE ;
break;
}
}
void F_45 ( struct V_7 * V_13 , T_3 V_70 )
{
F_23 ( L_5 , V_3 , V_71 [ V_70 ] ) ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_18 ( V_13 ) ;
switch ( V_70 ) {
case V_72 :
F_23 ( L_6 , V_3 ) ;
F_28 ( V_13 , V_73 , NULL , NULL ) ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
F_46 ( V_13 -> V_39 . V_41 , V_13 ,
V_70 , NULL ) ;
break;
default:
F_4 ( L_7 ,
V_3 , V_70 ) ;
}
}
void F_47 ( struct V_7 * V_13 , T_4 * V_78 )
{
struct V_79 V_80 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (discovery != NULL, return;) ;
F_23 ( L_8 , V_3 , V_78 -> V_81 ) ;
F_2 ((discovery->nslots == 1) || (discovery->nslots == 6) ||
(discovery->nslots == 8) || (discovery->nslots == 16),
return;) ;
if ( V_13 -> V_20 != V_37 ) {
F_23 ( L_9 ,
V_3 ) ;
F_48 ( V_13 , NULL ) ;
return;
}
if ( V_13 -> V_82 != NULL ) {
F_6 ( V_13 -> V_82 , ( V_5 ) F_19 ) ;
V_13 -> V_82 = NULL ;
}
V_13 -> V_82 = F_3 ( V_83 ) ;
if ( V_13 -> V_82 == NULL ) {
F_49 ( L_10 ,
V_3 ) ;
return;
}
V_80 . V_84 = V_78 -> V_81 ;
V_80 . V_85 = 0 ;
V_13 -> V_86 = V_78 ;
V_80 . V_78 = V_78 ;
V_13 -> V_87 = F_50 ( V_88 ) ;
F_28 ( V_13 , V_89 , NULL , & V_80 ) ;
}
void F_48 ( struct V_7 * V_13 , T_5 * V_82 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (self->notify.instance != NULL, return;) ;
if ( V_82 )
F_51 ( V_13 -> V_17 , FALSE ) ;
F_52 ( V_13 -> V_39 . V_41 , V_82 ) ;
}
void F_53 ( struct V_7 * V_13 , T_4 * V_78 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (discovery != NULL, return;) ;
F_2 (self->notify.instance != NULL, return;) ;
F_51 ( V_13 -> V_17 , V_90 ) ;
F_54 ( V_13 -> V_39 . V_41 , V_78 ) ;
}
void F_55 ( struct V_7 * V_13 , int V_91 )
{
switch ( V_91 ) {
case V_92 :
F_56 ( L_11 ) ;
break;
case V_93 :
F_56 ( L_12 ) ;
break;
default:
break;
}
F_57 ( V_13 -> V_39 . V_41 ,
V_91 , V_94 ) ;
}
void F_58 ( struct V_7 * V_13 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
if ( V_13 -> V_20 == V_67 )
F_28 ( V_13 , V_73 , NULL , NULL ) ;
else
F_28 ( V_13 , V_95 , NULL , NULL ) ;
}
void F_59 ( void )
{
}
int F_60 ( int V_84 , int V_85 )
{
static int rand ;
int V_96 ;
F_2 ((S - s) > 0 , return 0;) ;
rand += V_97 ;
rand ^= ( rand << 12 ) ;
rand ^= ( rand >> 20 ) ;
V_96 = V_85 + rand % ( V_84 - V_85 ) ;
F_2 ((slot >= s) || (slot < S), return 0;) ;
return V_96 ;
}
void F_61 ( struct V_7 * V_13 , int V_98 )
{
struct V_42 * V_43 = NULL ;
int V_99 = 0 ;
if ( V_98 == V_13 -> V_100 ) {
while ( ( V_43 = F_62 ( & V_13 -> V_24 ) ) != NULL ) {
F_63 ( V_43 ) ;
}
V_13 -> V_101 = V_98 - 1 ;
} else {
while ( ( F_64 ( & V_13 -> V_24 ) != NULL ) &&
( ( ( V_13 -> V_101 + 1 ) % 8 ) != V_98 ) )
{
V_43 = F_62 ( & V_13 -> V_24 ) ;
F_63 ( V_43 ) ;
V_13 -> V_101 = ( V_13 -> V_101 + 1 ) % 8 ;
V_99 ++ ;
}
}
V_13 -> V_102 = V_13 -> V_103 - F_39 ( & V_13 -> V_24 ) ;
}
int F_65 ( struct V_7 * V_13 , int V_104 )
{
if ( V_104 == V_13 -> V_105 )
return V_106 ;
return V_107 ;
}
int F_66 ( struct V_7 * V_13 , int V_98 )
{
if ( V_98 == V_13 -> V_100 ) {
F_23 ( L_13 , V_3 ) ;
return V_108 ;
}
if ( V_13 -> V_101 < V_13 -> V_100 ) {
if ( ( V_98 >= V_13 -> V_101 ) && ( V_98 <= V_13 -> V_100 ) )
return V_109 ;
} else {
if ( ( V_98 >= V_13 -> V_101 ) || ( V_98 <= V_13 -> V_100 ) )
return V_109 ;
}
return V_110 ;
}
void F_67 ( struct V_7 * V_13 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
V_13 -> V_100 = V_13 -> V_105 = 0 ;
V_13 -> V_101 = 7 ;
V_13 -> V_102 = 1 ;
V_13 -> V_111 = FALSE ;
V_13 -> V_112 = 0 ;
}
void F_68 ( struct V_7 * V_13 , struct V_10 * V_11 )
{
T_2 V_113 ;
T_2 V_114 ;
V_114 = V_11 -> V_115 . V_116 ;
V_113 = V_11 -> V_113 . V_116 ;
if ( V_114 > 115200 ) {
V_13 -> V_117 = V_113 ;
return;
}
V_13 -> V_118 = F_69 ( V_114 , V_113 ) ;
}
void F_18 ( struct V_7 * V_13 )
{
struct V_42 * V_43 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
while ( ( V_43 = F_62 ( & V_13 -> V_22 ) ) != NULL )
F_63 ( V_43 ) ;
while ( ( V_43 = F_62 ( & V_13 -> V_23 ) ) != NULL )
F_63 ( V_43 ) ;
while ( ( V_43 = F_62 ( & V_13 -> V_24 ) ) != NULL )
F_63 ( V_43 ) ;
}
static void F_70 ( struct V_7 * V_13 , T_2 V_114 , int V_119 )
{
struct V_42 * V_43 ;
F_23 ( L_14 , V_3 , V_114 ) ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
V_13 -> V_114 = V_114 ;
if ( V_119 ) {
V_43 = F_71 ( 0 , V_120 ) ;
if ( V_43 )
F_72 ( V_13 , V_43 ) ;
}
}
static void F_25 ( struct V_7 * V_13 ,
struct V_10 * V_48 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_2 (self->netdev != NULL, return;) ;
F_73 ( & V_13 -> V_121 ) ;
F_74 ( & V_13 -> V_121 , V_13 -> V_18 ) ;
if ( V_48 ) {
F_23 ( L_15 , V_3 ) ;
if ( V_48 -> V_115 . V_122 )
V_13 -> V_121 . V_115 . V_122 &= V_48 -> V_115 . V_122 ;
if ( V_48 -> V_123 . V_122 )
V_13 -> V_121 . V_123 . V_122 &= V_48 -> V_123 . V_122 ;
if ( V_48 -> V_124 . V_122 )
V_13 -> V_121 . V_124 . V_122 &= V_48 -> V_124 . V_122 ;
if ( V_48 -> V_125 . V_122 )
V_13 -> V_121 . V_125 . V_122 &= V_48 -> V_125 . V_122 ;
}
V_13 -> V_121 . V_123 . V_122 &= 0x01 ;
F_75 ( & V_13 -> V_121 ) ;
}
void F_14 ( struct V_7 * V_13 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
V_13 -> V_126 = 12 ;
V_13 -> V_127 = 12 ;
F_70 ( V_13 , 9600 , TRUE ) ;
F_51 ( V_13 -> V_17 , TRUE ) ;
while ( ( V_13 -> V_128 == 0x00 ) || ( V_13 -> V_128 == 0xfe ) ) {
F_11 ( & V_13 -> V_128 , sizeof( V_13 -> V_128 ) ) ;
V_13 -> V_128 &= 0xfe ;
}
V_13 -> V_87 = V_88 ;
V_13 -> V_129 = V_130 ;
V_13 -> V_131 = V_132 ;
V_13 -> V_133 = V_134 ;
V_13 -> V_45 . V_115 . V_116 = 9600 ;
V_13 -> V_121 . V_115 . V_116 = 9600 ;
V_13 -> V_45 . V_123 . V_116 = 0 ;
V_13 -> V_121 . V_123 . V_116 = 0 ;
V_13 -> V_45 . V_113 . V_116 = 0 ;
V_13 -> V_121 . V_113 . V_116 = 0 ;
V_13 -> V_45 . V_124 . V_116 = 64 ;
V_13 -> V_121 . V_124 . V_116 = 64 ;
V_13 -> V_45 . V_103 . V_116 = 1 ;
V_13 -> V_121 . V_103 . V_116 = 1 ;
V_13 -> V_45 . V_135 . V_116 = 12 ;
V_13 -> V_121 . V_135 . V_116 = 12 ;
V_13 -> V_45 . V_125 . V_116 = 0 ;
V_13 -> V_121 . V_125 . V_116 = 0 ;
F_18 ( V_13 ) ;
V_13 -> V_65 = FALSE ;
V_13 -> V_52 = FALSE ;
}
void F_76 ( struct V_7 * V_13 , int V_119 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
V_13 -> V_126 = V_13 -> V_45 . V_135 . V_116 ;
if ( V_119 )
V_13 -> V_127 = V_13 -> V_126 ;
F_70 ( V_13 , V_13 -> V_45 . V_115 . V_116 , V_119 ) ;
V_13 -> V_103 = V_13 -> V_45 . V_103 . V_116 ;
V_13 -> V_102 = V_13 -> V_45 . V_103 . V_116 ;
#ifdef F_77
V_13 -> V_136 =
F_78 ( V_13 -> V_45 . V_115 . V_116 ,
V_13 -> V_45 . V_123 . V_116 ) ;
V_13 -> V_137 = V_13 -> V_136 ;
#endif
F_2 (self->qos_tx.max_turn_time.value != 0 , return;) ;
F_2 (self->qos_rx.max_turn_time.value != 0 , return;) ;
V_13 -> V_131 = F_50 (
V_13 -> V_45 . V_123 . V_116 ) ;
V_13 -> V_129 = F_50 (
V_13 -> V_121 . V_123 . V_116 ) ;
V_13 -> V_133 = V_13 -> V_129 * 2 ;
if ( V_13 -> V_45 . V_125 . V_116 == V_138 )
V_13 -> V_139 = - 2 ;
else
V_13 -> V_139 = V_138 * 1000 /
V_13 -> V_121 . V_123 . V_116 ;
F_23 ( L_16 , V_13 -> V_139 ) ;
V_13 -> V_140 = V_13 -> V_45 . V_125 . V_116 * 1000 /
V_13 -> V_121 . V_123 . V_116 ;
F_23 ( L_17 , V_13 -> V_140 ) ;
}
static void * F_79 ( struct V_141 * V_142 , T_6 * V_143 )
{
struct V_144 * V_145 = V_142 -> V_146 ;
struct V_7 * V_13 ;
F_80 ( & V_1 -> V_147 ) ;
V_145 -> V_148 = 0 ;
for ( V_13 = (struct V_7 * ) F_81 ( V_1 ) ;
V_13 ; V_13 = (struct V_7 * ) F_82 ( V_1 ) ) {
if ( V_145 -> V_148 == * V_143 )
break;
++ V_145 -> V_148 ;
}
return V_13 ;
}
static void * F_83 ( struct V_141 * V_142 , void * V_149 , T_6 * V_143 )
{
struct V_144 * V_145 = V_142 -> V_146 ;
++ * V_143 ;
++ V_145 -> V_148 ;
return ( void * ) F_82 ( V_1 ) ;
}
static void F_84 ( struct V_141 * V_142 , void * V_149 )
{
F_85 ( & V_1 -> V_147 ) ;
}
static int F_86 ( struct V_141 * V_142 , void * V_149 )
{
const struct V_144 * V_145 = V_142 -> V_146 ;
const struct V_7 * V_13 = V_149 ;
F_2 (self->magic == LAP_MAGIC, return -EINVAL;) ;
F_87 ( V_142 , L_18 , V_145 -> V_148 ) ;
F_87 ( V_142 , L_19 ,
V_150 [ V_13 -> V_20 ] ) ;
F_87 ( V_142 , L_20 ,
( V_13 -> V_17 ) ? V_13 -> V_17 -> V_151 : L_21 ) ;
F_87 ( V_142 , L_22 , V_13 -> V_12 ) ;
F_87 ( V_142 , L_23 , V_13 -> V_128 ) ;
F_87 ( V_142 , L_24 , V_13 -> V_25 ) ;
F_87 ( V_142 , L_25 , V_13 -> V_44 ) ;
F_87 ( V_142 , L_26 ,
V_13 -> V_103 ) ;
F_87 ( V_142 , L_27 , V_13 -> V_102 ) ;
#ifdef F_77
F_87 ( V_142 , L_28 ,
V_13 -> V_136 ) ;
F_87 ( V_142 , L_29 , V_13 -> V_137 ) ;
#endif
F_87 ( V_142 , L_30 ,
F_39 ( & V_13 -> V_22 ) ) ;
F_87 ( V_142 , L_31 ,
F_39 ( & V_13 -> V_24 ) ) ;
F_87 ( V_142 , L_32 , V_13 -> V_111 ?
L_33 : L_34 ) ;
F_87 ( V_142 , L_35 , V_13 -> V_50 ?
L_33 : L_34 ) ;
F_87 ( V_142 , L_36 , V_13 -> V_112 ) ;
F_87 ( V_142 , L_37 , V_13 -> V_100 ) ;
F_87 ( V_142 , L_38 , V_13 -> V_105 ) ;
F_87 ( V_142 , L_39 , V_13 -> V_101 ) ;
F_87 ( V_142 , L_40 ) ;
F_87 ( V_142 , L_41 ,
V_13 -> V_45 . V_115 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_123 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_124 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_103 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_135 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_113 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_45 . V_125 . V_116 ) ;
F_87 ( V_142 , L_43 ) ;
F_87 ( V_142 , L_44 ,
V_13 -> V_121 . V_115 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_121 . V_123 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_121 . V_124 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_121 . V_103 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_121 . V_135 . V_116 ) ;
F_87 ( V_142 , L_42 ,
V_13 -> V_121 . V_113 . V_116 ) ;
F_87 ( V_142 , L_45 ,
V_13 -> V_121 . V_125 . V_116 ) ;
return 0 ;
}
static int F_88 ( struct V_152 * V_152 , struct V_153 * V_153 )
{
if ( V_1 == NULL )
return - V_154 ;
return F_89 ( V_153 , & V_155 ,
sizeof( struct V_144 ) ) ;
}
