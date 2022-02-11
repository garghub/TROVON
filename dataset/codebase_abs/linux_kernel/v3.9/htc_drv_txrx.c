int F_1 ( T_1 V_1 , int * V_2 )
{
switch ( V_1 ) {
case 0 :
return V_2 [ V_3 ] ;
case 1 :
return V_2 [ V_4 ] ;
case 2 :
return V_2 [ V_5 ] ;
case 3 :
return V_2 [ V_6 ] ;
default:
return V_2 [ V_5 ] ;
}
}
void F_2 ( struct V_7 * V_8 )
{
F_3 ( & V_8 -> V_9 . V_10 ) ;
V_8 -> V_9 . V_11 ++ ;
if ( ( V_8 -> V_9 . V_11 >= V_12 ) &&
! ( V_8 -> V_9 . V_13 & V_14 ) ) {
V_8 -> V_9 . V_13 |= V_14 ;
F_4 ( V_8 -> V_15 ) ;
}
F_5 ( & V_8 -> V_9 . V_10 ) ;
}
void F_6 ( struct V_7 * V_8 )
{
F_3 ( & V_8 -> V_9 . V_10 ) ;
if ( ( V_8 -> V_9 . V_11 < V_12 ) &&
( V_8 -> V_9 . V_13 & V_14 ) ) {
V_8 -> V_9 . V_13 &= ~ V_14 ;
F_7 ( V_8 -> V_15 ) ;
}
F_5 ( & V_8 -> V_9 . V_10 ) ;
}
int F_8 ( struct V_7 * V_8 )
{
int V_16 ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
V_16 = F_9 ( V_8 -> V_9 . V_17 , V_18 ) ;
if ( V_16 >= V_18 ) {
F_5 ( & V_8 -> V_9 . V_10 ) ;
return - V_19 ;
}
F_10 ( V_16 , V_8 -> V_9 . V_17 ) ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
return V_16 ;
}
void F_11 ( struct V_7 * V_8 , int V_16 )
{
F_3 ( & V_8 -> V_9 . V_10 ) ;
F_12 ( V_16 , V_8 -> V_9 . V_17 ) ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
}
static inline enum V_20 F_13 ( struct V_7 * V_8 ,
T_1 V_21 )
{
enum V_20 V_22 ;
switch ( V_21 ) {
case 0 :
F_14 ( V_3 ) ;
V_22 = V_8 -> V_23 ;
break;
case 1 :
F_14 ( V_4 ) ;
V_22 = V_8 -> V_24 ;
break;
case 2 :
F_14 ( V_5 ) ;
V_22 = V_8 -> V_25 ;
break;
case 3 :
default:
F_14 ( V_6 ) ;
V_22 = V_8 -> V_26 ;
break;
}
return V_22 ;
}
static inline struct V_27 *
F_15 ( struct V_7 * V_8 , T_2 V_22 )
{
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_27 * V_31 = NULL ;
if ( V_22 == V_8 -> V_32 )
V_31 = & V_8 -> V_9 . V_33 ;
else if ( V_22 == V_8 -> V_34 )
V_31 = & V_8 -> V_9 . V_35 ;
else if ( V_22 == V_8 -> V_25 )
V_31 = & V_8 -> V_9 . V_36 ;
else if ( V_22 == V_8 -> V_26 )
V_31 = & V_8 -> V_9 . V_37 ;
else if ( V_22 == V_8 -> V_24 )
V_31 = & V_8 -> V_9 . V_38 ;
else if ( V_22 == V_8 -> V_23 )
V_31 = & V_8 -> V_9 . V_39 ;
else
F_17 ( V_29 , L_1 , V_22 ) ;
return V_31 ;
}
static inline int F_18 ( struct V_7 * V_8 ,
struct V_40 * V_41 )
{
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_42 * V_43 ;
int V_16 ;
V_43 = F_19 ( V_41 ) ;
if ( V_43 -> V_22 == V_8 -> V_32 ) {
struct V_44 * V_45 =
(struct V_44 * ) V_41 -> V_46 ;
V_16 = V_45 -> V_47 ;
F_20 ( V_41 , sizeof( struct V_44 ) ) ;
} else if ( ( V_43 -> V_22 == V_8 -> V_26 ) ||
( V_43 -> V_22 == V_8 -> V_25 ) ||
( V_43 -> V_22 == V_8 -> V_24 ) ||
( V_43 -> V_22 == V_8 -> V_23 ) ||
( V_43 -> V_22 == V_8 -> V_34 ) ) {
struct V_48 * V_49 =
(struct V_48 * ) V_41 -> V_46 ;
V_16 = V_49 -> V_47 ;
F_20 ( V_41 , sizeof( struct V_48 ) ) ;
} else {
F_17 ( V_29 , L_2 , V_43 -> V_22 ) ;
V_16 = - V_50 ;
}
return V_16 ;
}
int F_21 ( struct V_7 * V_8 , int V_21 ,
struct V_51 * V_52 )
{
struct V_53 * V_30 = V_8 -> V_30 ;
int error = 0 ;
struct V_51 V_54 ;
F_22 ( V_30 , V_21 , & V_54 ) ;
V_54 . V_55 = V_52 -> V_55 ;
V_54 . V_56 = V_52 -> V_56 / 2 ;
V_54 . V_57 = V_52 -> V_57 ;
V_54 . V_58 = V_52 -> V_58 ;
V_54 . V_59 = V_52 -> V_59 ;
if ( ! F_23 ( V_30 , V_21 , & V_54 ) ) {
F_17 ( F_16 ( V_30 ) ,
L_3 , V_21 ) ;
error = - V_60 ;
} else {
F_24 ( V_30 , V_21 ) ;
}
return error ;
}
static void F_25 ( struct V_7 * V_8 ,
struct V_61 * V_62 ,
struct V_40 * V_41 ,
T_2 V_63 , T_2 V_64 , T_2 V_16 )
{
struct V_65 * V_66 = F_26 ( V_41 ) ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_44 V_71 ;
struct V_42 * V_43 ;
T_2 * V_49 ;
V_43 = F_19 ( V_41 ) ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
memset ( & V_71 , 0 , sizeof( struct V_44 ) ) ;
if ( V_62 && F_27 ( F_28 ( V_70 -> V_72 ) ) ) {
V_68 = (struct V_67 * ) V_41 -> V_46 ;
V_68 -> V_73 . V_74 . V_75 = V_62 -> V_76 ;
}
V_43 -> type = V_77 ;
V_71 . V_78 = V_63 ;
V_71 . V_64 = V_64 ;
V_71 . V_79 = 0 ;
V_71 . V_13 = 0 ;
V_71 . V_47 = V_16 ;
V_71 . V_80 = F_29 ( V_41 ) ;
if ( V_71 . V_80 == V_81 )
V_71 . V_82 = ( T_2 ) V_83 ;
else
V_71 . V_82 = V_66 -> V_84 . V_85 -> V_86 ;
V_49 = F_30 ( V_41 , sizeof( V_71 ) ) ;
memcpy ( V_49 , ( T_2 * ) & V_71 , sizeof( V_71 ) ) ;
V_43 -> V_22 = V_8 -> V_32 ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_87 * V_88 ,
struct V_40 * V_41 ,
T_2 V_63 , T_2 V_64 , T_2 V_16 ,
bool V_89 )
{
struct V_65 * V_66 = F_26 ( V_41 ) ;
struct V_69 * V_70 ;
struct V_42 * V_43 ;
struct V_48 V_90 ;
T_3 V_13 = 0 ;
T_2 * V_91 , * V_49 ;
T_1 V_21 ;
V_43 = F_19 ( V_41 ) ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
memset ( & V_90 , 0 , sizeof( struct V_48 ) ) ;
V_90 . V_78 = V_63 ;
V_90 . V_64 = V_64 ;
V_90 . V_47 = V_16 ;
V_43 -> V_63 = V_63 ;
if ( V_66 -> V_13 & V_92 ) {
V_43 -> type = V_93 ;
V_90 . V_94 = V_93 ;
} else {
V_43 -> type = V_95 ;
V_90 . V_94 = V_95 ;
}
if ( F_32 ( V_70 -> V_72 ) ) {
V_91 = F_33 ( V_70 ) ;
V_90 . V_79 = V_91 [ 0 ] & V_96 ;
}
if ( V_8 -> V_15 -> V_97 -> V_98 != ( T_3 ) - 1 )
if ( V_41 -> V_99 > V_8 -> V_15 -> V_97 -> V_98 )
V_13 |= V_100 ;
if ( ! ( V_13 & V_100 ) &&
( V_88 && V_88 -> V_101 . V_102 ) )
V_13 |= V_103 ;
V_90 . V_13 = F_34 ( V_13 ) ;
V_90 . V_80 = F_29 ( V_41 ) ;
if ( V_90 . V_80 == V_81 )
V_90 . V_82 = ( T_2 ) V_83 ;
else
V_90 . V_82 = V_66 -> V_84 . V_85 -> V_86 ;
V_49 = F_30 ( V_41 , sizeof( V_90 ) ) ;
memcpy ( V_49 , ( T_2 * ) & V_90 , sizeof( V_90 ) ) ;
if ( V_89 ) {
V_104 ;
V_43 -> V_22 = V_8 -> V_34 ;
return;
}
V_21 = F_35 ( V_41 ) ;
V_43 -> V_22 = F_13 ( V_8 , V_21 ) ;
}
int F_36 ( struct V_7 * V_8 ,
struct V_105 * V_106 ,
struct V_40 * V_41 ,
T_2 V_16 , bool V_89 )
{
struct V_69 * V_70 ;
struct V_65 * V_66 = F_26 ( V_41 ) ;
struct V_87 * V_88 = V_66 -> V_84 . V_88 ;
struct V_107 * V_108 ;
struct V_61 * V_62 = NULL ;
T_2 V_63 , V_64 ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
if ( V_88 ) {
V_62 = (struct V_61 * ) V_88 -> V_109 ;
V_64 = V_62 -> V_110 ;
} else {
if ( ! V_8 -> V_30 -> V_111 ) {
F_37 ( F_16 ( V_8 -> V_30 ) , V_112 ,
L_4 ) ;
return - V_50 ;
}
V_64 = V_8 -> V_113 ;
}
if ( V_106 ) {
V_108 = (struct V_107 * ) V_106 -> V_109 ;
V_63 = V_108 -> V_110 ;
} else {
V_63 = V_8 -> V_114 [ V_64 ] ;
}
if ( F_38 ( V_70 -> V_72 ) )
F_31 ( V_8 , V_88 , V_41 ,
V_63 , V_64 , V_16 , V_89 ) ;
else
F_25 ( V_8 , V_62 , V_41 ,
V_63 , V_64 , V_16 ) ;
return F_39 ( V_8 -> V_115 , V_41 ) ;
}
static inline bool F_40 ( struct V_7 * V_8 ,
struct V_107 * V_108 , T_2 V_116 )
{
bool V_117 = false ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
if ( ( V_116 < V_118 ) && ( V_108 -> V_119 [ V_116 ] == V_120 ) )
V_117 = true ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
return V_117 ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_87 * V_88 ,
struct V_40 * V_41 )
{
struct V_105 * V_106 ;
struct V_69 * V_70 ;
T_4 V_121 ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
V_121 = V_70 -> V_72 ;
F_42 () ;
V_106 = F_43 ( V_88 , V_70 -> V_122 ) ;
if ( ! V_106 ) {
F_44 () ;
return;
}
if ( V_106 && F_45 ( & V_8 -> V_15 -> V_123 ) &&
! ( V_41 -> V_124 == F_46 ( V_125 ) ) ) {
if ( F_32 ( V_121 ) ) {
T_2 * V_91 , V_116 ;
struct V_107 * V_108 ;
V_91 = F_33 ( V_70 ) ;
V_116 = V_91 [ 0 ] & 0xf ;
V_108 = (struct V_107 * ) V_106 -> V_109 ;
if ( F_40 ( V_8 , V_108 , V_116 ) ) {
F_47 ( V_106 , V_116 , 0 ) ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
V_108 -> V_119 [ V_116 ] = V_126 ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
}
}
}
F_44 () ;
}
static void F_48 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
struct V_127 * V_128 )
{
struct V_87 * V_88 ;
struct V_42 * V_43 ;
struct V_65 * V_66 ;
struct V_129 * V_130 ;
struct V_131 * V_132 = & V_8 -> V_15 -> V_123 ;
bool V_133 ;
int V_16 ;
V_16 = F_18 ( V_8 , V_41 ) ;
if ( V_16 < 0 ) {
F_49 ( V_41 ) ;
return;
}
V_43 = F_19 ( V_41 ) ;
V_133 = V_43 -> V_133 ;
V_66 = F_26 ( V_41 ) ;
V_88 = V_66 -> V_84 . V_88 ;
V_130 = & V_66 -> V_134 . V_135 [ 0 ] ;
memset ( & V_66 -> V_134 , 0 , sizeof( V_66 -> V_134 ) ) ;
if ( ! V_133 || ! V_88 || ! V_128 )
goto V_136;
if ( V_128 -> V_137 & V_138 )
V_66 -> V_13 |= V_139 ;
if ( V_128 -> V_137 & V_140 )
V_66 -> V_13 |= V_141 ;
if ( V_128 -> V_137 & V_142 )
V_130 -> V_13 |= V_143 ;
V_130 -> V_144 = 1 ;
V_130 -> V_145 = F_50 ( V_128 -> V_146 , V_147 ) ;
if ( V_128 -> V_137 & V_148 ) {
V_130 -> V_13 |= V_149 ;
if ( V_128 -> V_137 & V_150 )
V_130 -> V_13 |= V_151 ;
if ( V_128 -> V_137 & V_152 )
V_130 -> V_13 |= V_153 ;
} else {
if ( V_132 -> V_154 -> V_155 == V_156 )
V_130 -> V_145 += 4 ;
}
F_41 ( V_8 , V_88 , V_41 ) ;
V_136:
F_3 ( & V_8 -> V_9 . V_10 ) ;
if ( F_51 ( -- V_8 -> V_9 . V_11 < 0 ) )
V_8 -> V_9 . V_11 = 0 ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
F_11 ( V_8 , V_16 ) ;
F_52 ( V_8 -> V_15 , V_41 ) ;
}
static inline void F_53 ( struct V_7 * V_8 ,
struct V_27 * V_1 )
{
struct V_40 * V_41 ;
while ( ( V_41 = F_54 ( V_1 ) ) != NULL ) {
F_48 ( V_8 , V_41 , NULL ) ;
}
}
void F_55 ( struct V_7 * V_8 )
{
struct V_157 * V_158 , * V_159 ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
V_8 -> V_9 . V_13 |= V_160 ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
F_56 ( V_8 -> V_115 ) ;
F_57 ( & V_8 -> V_161 -> V_162 ) ;
F_57 ( & V_8 -> V_163 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_33 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_35 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_36 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_37 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_38 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_39 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_164 ) ;
F_3 ( & V_8 -> V_161 -> V_165 ) ;
F_58 (event, tmp, &priv->wmi->pending_tx_events, list) {
F_59 ( & V_158 -> V_166 ) ;
F_60 ( V_158 ) ;
}
F_5 ( & V_8 -> V_161 -> V_165 ) ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
V_8 -> V_9 . V_13 &= ~ V_160 ;
F_5 ( & V_8 -> V_9 . V_10 ) ;
}
void F_61 ( unsigned long V_46 )
{
struct V_7 * V_8 = (struct V_7 * ) V_46 ;
F_3 ( & V_8 -> V_9 . V_10 ) ;
if ( V_8 -> V_9 . V_13 & V_160 ) {
F_5 ( & V_8 -> V_9 . V_10 ) ;
return;
}
F_5 ( & V_8 -> V_9 . V_10 ) ;
F_53 ( V_8 , & V_8 -> V_9 . V_164 ) ;
}
static inline bool F_62 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
T_2 V_47 , T_2 V_22 )
{
T_2 V_167 = 0 ;
if ( V_22 == V_8 -> V_32 ) {
struct V_44 * V_70 ;
V_70 = (struct V_44 * ) V_41 -> V_46 ;
V_167 = V_70 -> V_47 ;
} else if ( ( V_22 == V_8 -> V_26 ) ||
( V_22 == V_8 -> V_25 ) ||
( V_22 == V_8 -> V_24 ) ||
( V_22 == V_8 -> V_23 ) ||
( V_22 == V_8 -> V_34 ) ) {
struct V_48 * V_70 ;
V_70 = (struct V_48 * ) V_41 -> V_46 ;
V_167 = V_70 -> V_47 ;
}
if ( V_167 == V_47 )
return true ;
return false ;
}
static struct V_40 * F_63 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_27 * V_31 ;
struct V_40 * V_41 , * V_159 ;
unsigned long V_13 ;
T_2 V_22 = F_50 ( V_128 -> V_146 , V_168 ) ;
V_31 = F_15 ( V_8 , V_22 ) ;
if ( ! V_31 )
return NULL ;
F_64 ( & V_31 -> V_169 , V_13 ) ;
F_65 (epid_queue, skb, tmp) {
if ( F_62 ( V_8 , V_41 , V_128 -> V_47 , V_22 ) ) {
F_66 ( V_41 , V_31 ) ;
F_67 ( & V_31 -> V_169 , V_13 ) ;
return V_41 ;
}
}
F_67 ( & V_31 -> V_169 , V_13 ) ;
F_37 ( V_29 , V_112 , L_5 ,
V_128 -> V_47 , V_22 ) ;
return NULL ;
}
void F_68 ( struct V_7 * V_8 , void * V_170 )
{
struct V_171 * V_128 = (struct V_171 * ) V_170 ;
struct V_127 * V_172 ;
struct V_40 * V_41 ;
struct V_157 * V_173 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_128 -> V_175 ; V_174 ++ ) {
F_51 ( V_128 -> V_175 > V_176 ) ;
V_172 = & V_128 -> V_177 [ V_174 ] ;
V_41 = F_63 ( V_8 , V_172 ) ;
if ( ! V_41 ) {
V_173 = F_69 ( sizeof( struct V_157 ) ,
V_178 ) ;
if ( ! V_173 )
continue;
memcpy ( & V_173 -> V_128 , V_172 ,
sizeof( struct V_127 ) ) ;
F_70 ( & V_8 -> V_161 -> V_165 ) ;
F_71 ( & V_173 -> V_166 ,
& V_8 -> V_161 -> V_179 ) ;
F_72 ( & V_8 -> V_161 -> V_165 ) ;
continue;
}
F_48 ( V_8 , V_41 , V_172 ) ;
}
F_6 ( V_8 ) ;
}
void F_73 ( void * V_109 , struct V_40 * V_41 ,
enum V_20 V_180 , bool V_133 )
{
struct V_7 * V_8 = (struct V_7 * ) V_109 ;
struct V_42 * V_43 ;
struct V_27 * V_31 ;
V_43 = F_19 ( V_41 ) ;
V_43 -> V_133 = V_133 ;
V_43 -> V_75 = V_181 ;
if ( ! V_133 ) {
F_74 ( & V_8 -> V_9 . V_164 , V_41 ) ;
F_75 ( & V_8 -> V_163 ) ;
return;
}
V_31 = F_15 ( V_8 , V_180 ) ;
if ( ! V_31 ) {
F_49 ( V_41 ) ;
return;
}
F_74 ( V_31 , V_41 ) ;
}
static inline bool F_76 ( struct V_7 * V_8 , struct V_40 * V_41 )
{
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_42 * V_43 ;
V_43 = F_19 ( V_41 ) ;
if ( F_77 ( V_181 ,
V_43 -> V_75 +
F_78 ( V_182 ) ) ) {
F_37 ( V_29 , V_112 , L_6 ) ;
return true ;
}
return false ;
}
static void F_79 ( struct V_7 * V_8 ,
struct V_27 * V_31 )
{
bool V_183 = false ;
unsigned long V_13 ;
struct V_40 * V_41 , * V_159 ;
struct V_27 V_1 ;
F_80 ( & V_1 ) ;
F_64 ( & V_31 -> V_169 , V_13 ) ;
F_65 (epid_queue, skb, tmp) {
if ( F_76 ( V_8 , V_41 ) ) {
F_66 ( V_41 , V_31 ) ;
F_81 ( & V_1 , V_41 ) ;
V_183 = true ;
}
}
F_67 ( & V_31 -> V_169 , V_13 ) ;
if ( V_183 ) {
F_65 (&queue, skb, tmp) {
F_66 ( V_41 , & V_1 ) ;
F_48 ( V_8 , V_41 , NULL ) ;
}
}
}
void F_82 ( unsigned long V_46 )
{
struct V_7 * V_8 = (struct V_7 * ) V_46 ;
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_157 * V_158 , * V_159 ;
struct V_40 * V_41 ;
F_70 ( & V_8 -> V_161 -> V_165 ) ;
F_58 (event, tmp, &priv->wmi->pending_tx_events, list) {
V_41 = F_63 ( V_8 , & V_158 -> V_128 ) ;
if ( V_41 ) {
F_37 ( V_29 , V_112 ,
L_7 ,
V_158 -> V_128 . V_47 ,
F_50 ( V_158 -> V_128 . V_146 , V_168 ) ) ;
F_48 ( V_8 , V_41 , & V_158 -> V_128 ) ;
F_59 ( & V_158 -> V_166 ) ;
F_60 ( V_158 ) ;
continue;
}
if ( ++ V_158 -> V_144 >= V_184 ) {
F_59 ( & V_158 -> V_166 ) ;
F_60 ( V_158 ) ;
}
}
F_72 ( & V_8 -> V_161 -> V_165 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_33 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_35 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_36 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_37 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_38 ) ;
F_79 ( V_8 , & V_8 -> V_9 . V_39 ) ;
F_6 ( V_8 ) ;
F_83 ( & V_8 -> V_9 . V_185 ,
V_181 + F_78 ( V_186 ) ) ;
}
int F_84 ( struct V_7 * V_8 )
{
F_80 ( & V_8 -> V_9 . V_33 ) ;
F_80 ( & V_8 -> V_9 . V_35 ) ;
F_80 ( & V_8 -> V_9 . V_36 ) ;
F_80 ( & V_8 -> V_9 . V_37 ) ;
F_80 ( & V_8 -> V_9 . V_38 ) ;
F_80 ( & V_8 -> V_9 . V_39 ) ;
F_80 ( & V_8 -> V_9 . V_164 ) ;
return 0 ;
}
void F_85 ( struct V_7 * V_8 )
{
}
bool F_86 ( struct V_7 * V_8 , int V_187 )
{
struct V_53 * V_30 = V_8 -> V_30 ;
struct V_28 * V_29 = F_16 ( V_30 ) ;
struct V_51 V_54 ;
int V_21 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_87 ( V_187 ) ;
V_21 = F_88 ( V_8 -> V_30 , V_188 , & V_54 ) ;
if ( V_21 == - 1 )
return false ;
if ( V_21 >= F_89 ( V_8 -> V_2 ) ) {
F_17 ( V_29 , L_8 ,
V_21 , F_89 ( V_8 -> V_2 ) ) ;
F_90 ( V_30 , V_21 ) ;
return false ;
}
V_8 -> V_2 [ V_187 ] = V_21 ;
return true ;
}
int F_91 ( struct V_7 * V_8 )
{
struct V_51 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_87 ( 0 ) ;
return F_88 ( V_8 -> V_30 , V_189 , & V_54 ) ;
}
T_3 F_92 ( struct V_7 * V_8 )
{
#define F_93 (ATH9K_RX_FILTER_PHYERR | ATH9K_RX_FILTER_PHYRADAR)
struct V_53 * V_30 = V_8 -> V_30 ;
T_3 V_190 ;
V_190 = ( F_94 ( V_30 ) & F_93 )
| V_191 | V_192
| V_193 ;
if ( V_8 -> V_194 & V_195 )
V_190 |= V_196 ;
if ( ( ( V_30 -> V_197 != V_198 ) &&
( V_8 -> V_194 & V_199 ) ) ||
V_30 -> V_111 )
V_190 |= V_200 ;
if ( V_8 -> V_194 & V_201 )
V_190 |= V_202 ;
if ( ( V_30 -> V_197 == V_203 ) &&
( V_8 -> V_204 <= 1 ) &&
! ( V_8 -> V_194 & V_205 ) )
V_190 |= V_206 ;
else
V_190 |= V_207 ;
if ( F_45 ( & V_8 -> V_15 -> V_123 ) ) {
V_190 |= V_208 ;
V_190 |= V_209 ;
}
if ( V_8 -> V_194 & V_210 )
V_190 |= V_211 ;
if ( V_8 -> V_204 > 1 )
V_190 |= V_212 ;
return V_190 ;
#undef F_93
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_53 * V_30 = V_8 -> V_30 ;
T_3 V_190 , V_213 [ 2 ] ;
V_190 = F_92 ( V_8 ) ;
F_96 ( V_30 , V_190 ) ;
V_213 [ 0 ] = V_213 [ 1 ] = ~ 0 ;
F_97 ( V_30 , V_213 [ 0 ] , V_213 [ 1 ] ) ;
}
void F_98 ( struct V_7 * V_8 )
{
F_99 ( V_8 -> V_30 ) ;
F_95 ( V_8 ) ;
F_100 ( V_8 -> V_30 , F_101 ( V_214 , & V_8 -> V_215 ) ) ;
V_8 -> V_216 . V_217 = V_218 ;
}
static void F_102 ( struct V_219 * V_15 ,
struct V_220 * V_221 ,
T_2 V_222 , T_2 V_223 )
{
struct V_224 * V_225 ;
enum V_226 V_155 ;
unsigned int V_174 = 0 ;
if ( V_222 & 0x80 ) {
V_221 -> V_227 |= V_228 ;
if ( V_223 & V_229 )
V_221 -> V_227 |= V_230 ;
if ( V_223 & V_231 )
V_221 -> V_227 |= V_232 ;
V_221 -> V_233 = V_222 & 0x7f ;
return;
}
V_155 = V_15 -> V_123 . V_154 -> V_155 ;
V_225 = V_15 -> V_97 -> V_234 [ V_155 ] ;
for ( V_174 = 0 ; V_174 < V_225 -> V_235 ; V_174 ++ ) {
if ( V_225 -> V_236 [ V_174 ] . V_237 == V_222 ) {
V_221 -> V_233 = V_174 ;
return;
}
if ( V_225 -> V_236 [ V_174 ] . V_238 == V_222 ) {
V_221 -> V_233 = V_174 ;
V_221 -> V_227 |= V_239 ;
return;
}
}
}
static bool F_103 ( struct V_7 * V_8 ,
struct V_240 * V_241 ,
struct V_220 * V_242 )
{
struct V_69 * V_70 ;
struct V_219 * V_15 = V_8 -> V_15 ;
struct V_40 * V_41 = V_241 -> V_41 ;
struct V_28 * V_29 = F_16 ( V_8 -> V_30 ) ;
struct V_243 * V_244 ;
int V_245 , V_246 , V_247 ;
int V_217 = V_218 ;
T_4 V_121 ;
if ( V_41 -> V_99 < V_248 ) {
F_17 ( V_29 , L_9 ,
V_41 -> V_99 ) ;
goto V_249;
}
V_244 = (struct V_243 * ) V_41 -> V_46 ;
if ( F_104 ( V_244 -> V_250 ) -
( V_41 -> V_99 - V_248 ) != 0 ) {
F_17 ( V_29 ,
L_10 ,
V_244 -> V_250 , V_41 -> V_99 ) ;
goto V_249;
}
F_105 ( V_8 , V_244 ) ;
memcpy ( & V_241 -> V_244 , V_244 , V_248 ) ;
F_20 ( V_41 , V_248 ) ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
V_121 = V_70 -> V_72 ;
V_245 = F_106 ( V_41 ) ;
V_246 = F_107 ( V_121 ) ;
V_247 = V_246 & 3 ;
if ( V_247 && V_41 -> V_99 >= V_246 + V_247 + V_251 ) {
memmove ( V_41 -> V_46 + V_247 , V_41 -> V_46 , V_246 ) ;
F_20 ( V_41 , V_247 ) ;
}
memset ( V_242 , 0 , sizeof( struct V_220 ) ) ;
if ( V_241 -> V_244 . V_252 != 0 ) {
if ( V_241 -> V_244 . V_252 & V_253 )
V_242 -> V_227 |= V_254 ;
if ( V_241 -> V_244 . V_252 & V_255 )
goto V_249;
if ( V_241 -> V_244 . V_252 & V_256 ) {
} else if ( V_241 -> V_244 . V_252 & V_257 ) {
if ( F_108 ( V_121 ) )
V_241 -> V_244 . V_252 &= ~ V_257 ;
else
V_242 -> V_227 |= V_258 ;
}
if ( V_8 -> V_30 -> V_197 == V_259 ) {
if ( V_241 -> V_244 . V_252 &
~ ( V_256 | V_257 |
V_253 ) )
goto V_249;
} else {
if ( V_241 -> V_244 . V_252 &
~ ( V_256 | V_257 ) ) {
goto V_249;
}
}
}
if ( ! ( V_241 -> V_244 . V_252 & V_256 ) ) {
T_2 V_82 ;
V_82 = V_241 -> V_244 . V_260 ;
if ( V_82 != V_261 ) {
V_242 -> V_227 |= V_262 ;
} else if ( F_109 ( V_121 ) &&
V_41 -> V_99 >= V_245 + 4 ) {
V_82 = V_41 -> V_46 [ V_245 + 3 ] >> 6 ;
if ( F_101 ( V_82 , V_29 -> V_263 ) )
V_242 -> V_227 |= V_262 ;
}
}
F_102 ( V_15 , V_242 , V_241 -> V_244 . V_264 ,
V_241 -> V_244 . V_223 ) ;
if ( V_241 -> V_244 . V_265 != V_266 &&
! V_241 -> V_244 . V_267 )
F_110 ( V_8 -> V_216 . V_217 ,
V_241 -> V_244 . V_265 ) ;
V_217 = V_8 -> V_216 . V_217 ;
if ( F_111 ( V_70 -> V_72 ) &&
! F_112 ( V_29 -> V_268 ) &&
F_113 ( V_70 -> V_269 , V_29 -> V_268 ) ) {
T_5 V_270 = V_241 -> V_244 . V_265 ;
if ( F_114 ( V_217 != V_218 ) )
V_270 = F_115 ( V_217 , V_271 ) ;
if ( V_270 < 0 )
V_270 = 0 ;
V_8 -> V_30 -> V_272 . V_273 = V_270 ;
}
V_242 -> V_274 = F_116 ( V_241 -> V_244 . V_275 ) ;
V_242 -> V_155 = V_15 -> V_123 . V_154 -> V_155 ;
V_242 -> V_276 = V_15 -> V_123 . V_154 -> V_277 ;
V_242 -> signal = V_241 -> V_244 . V_265 + V_278 ;
V_242 -> V_279 = V_241 -> V_244 . V_280 ;
V_242 -> V_227 |= V_281 ;
return true ;
V_249:
return false ;
}
void F_117 ( unsigned long V_46 )
{
struct V_7 * V_8 = (struct V_7 * ) V_46 ;
struct V_240 * V_241 = NULL , * V_282 = NULL ;
struct V_220 V_242 ;
struct V_40 * V_41 ;
unsigned long V_13 ;
struct V_69 * V_70 ;
do {
F_64 ( & V_8 -> V_216 . V_283 , V_13 ) ;
F_118 (tmp_buf, &priv->rx.rxbuf, list) {
if ( V_282 -> V_284 ) {
V_241 = V_282 ;
break;
}
}
if ( V_241 == NULL ) {
F_67 ( & V_8 -> V_216 . V_283 , V_13 ) ;
break;
}
if ( ! V_241 -> V_41 )
goto V_285;
if ( ! F_103 ( V_8 , V_241 , & V_242 ) ) {
F_49 ( V_241 -> V_41 ) ;
goto V_285;
}
memcpy ( F_119 ( V_241 -> V_41 ) , & V_242 ,
sizeof( struct V_220 ) ) ;
V_41 = V_241 -> V_41 ;
V_70 = (struct V_69 * ) V_41 -> V_46 ;
if ( F_111 ( V_70 -> V_72 ) && V_8 -> V_286 )
F_120 ( V_8 -> V_15 , & V_8 -> V_287 ) ;
F_67 ( & V_8 -> V_216 . V_283 , V_13 ) ;
F_121 ( V_8 -> V_15 , V_41 ) ;
F_64 ( & V_8 -> V_216 . V_283 , V_13 ) ;
V_285:
V_241 -> V_284 = false ;
V_241 -> V_41 = NULL ;
F_122 ( & V_241 -> V_166 , & V_8 -> V_216 . V_241 ) ;
V_241 = NULL ;
F_67 ( & V_8 -> V_216 . V_283 , V_13 ) ;
} while ( 1 );
}
void F_123 ( void * V_109 , struct V_40 * V_41 ,
enum V_20 V_180 )
{
struct V_7 * V_8 = (struct V_7 * ) V_109 ;
struct V_53 * V_30 = V_8 -> V_30 ;
struct V_28 * V_29 = F_16 ( V_30 ) ;
struct V_240 * V_241 = NULL , * V_282 = NULL ;
F_70 ( & V_8 -> V_216 . V_283 ) ;
F_118 (tmp_buf, &priv->rx.rxbuf, list) {
if ( ! V_282 -> V_284 ) {
V_241 = V_282 ;
break;
}
}
F_72 ( & V_8 -> V_216 . V_283 ) ;
if ( V_241 == NULL ) {
F_37 ( V_29 , V_288 , L_11 ) ;
goto V_289;
}
F_70 ( & V_8 -> V_216 . V_283 ) ;
V_241 -> V_41 = V_41 ;
V_241 -> V_284 = true ;
F_72 ( & V_8 -> V_216 . V_283 ) ;
F_75 ( & V_8 -> V_290 ) ;
return;
V_289:
F_49 ( V_41 ) ;
}
void F_124 ( struct V_7 * V_8 )
{
struct V_240 * V_241 , * V_291 ;
F_58 (rxbuf, tbuf, &priv->rx.rxbuf, list) {
F_59 ( & V_241 -> V_166 ) ;
if ( V_241 -> V_41 )
F_49 ( V_241 -> V_41 ) ;
F_60 ( V_241 ) ;
}
}
int F_125 ( struct V_7 * V_8 )
{
int V_174 = 0 ;
F_126 ( & V_8 -> V_216 . V_241 ) ;
F_127 ( & V_8 -> V_216 . V_283 ) ;
for ( V_174 = 0 ; V_174 < V_292 ; V_174 ++ ) {
struct V_240 * V_241 =
F_69 ( sizeof( struct V_240 ) , V_293 ) ;
if ( V_241 == NULL )
goto V_289;
F_71 ( & V_241 -> V_166 , & V_8 -> V_216 . V_241 ) ;
}
return 0 ;
V_289:
F_124 ( V_8 ) ;
return - V_294 ;
}
