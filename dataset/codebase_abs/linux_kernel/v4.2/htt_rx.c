static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
F_2 (ar->htt.rx_ring.skb_table, rxcb, hlist, paddr)
if ( V_6 -> V_4 == V_4 )
return F_3 ( V_6 ) ;
F_4 ( 1 ) ;
return NULL ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_12 ;
if ( V_8 -> V_13 . V_14 ) {
F_6 (htt->rx_ring.skb_table, i, n, rxcb, hlist) {
V_9 = F_3 ( V_6 ) ;
F_7 ( V_8 -> V_3 -> V_15 , V_6 -> V_4 ,
V_9 -> V_16 + F_8 ( V_9 ) ,
V_17 ) ;
F_9 ( & V_6 -> V_18 ) ;
F_10 ( V_9 ) ;
}
} else {
for ( V_12 = 0 ; V_12 < V_8 -> V_13 . V_19 ; V_12 ++ ) {
V_9 = V_8 -> V_13 . V_20 [ V_12 ] ;
if ( ! V_9 )
continue;
V_6 = F_11 ( V_9 ) ;
F_7 ( V_8 -> V_3 -> V_15 , V_6 -> V_4 ,
V_9 -> V_16 + F_8 ( V_9 ) ,
V_17 ) ;
F_10 ( V_9 ) ;
}
}
V_8 -> V_13 . V_21 = 0 ;
F_12 ( V_8 -> V_13 . V_22 ) ;
memset ( V_8 -> V_13 . V_20 , 0 ,
V_8 -> V_13 . V_19 * sizeof( V_8 -> V_13 . V_20 [ 0 ] ) ) ;
}
static int F_13 ( struct V_7 * V_8 , int V_23 )
{
struct V_24 * V_25 ;
struct V_5 * V_6 ;
struct V_1 * V_9 ;
T_2 V_4 ;
int V_26 = 0 , V_27 ;
F_14 ( V_28 >= V_29 / 2 ) ;
V_27 = F_15 ( * V_8 -> V_13 . V_30 . V_31 ) ;
while ( V_23 > 0 ) {
V_9 = F_16 ( V_32 + V_33 ) ;
if ( ! V_9 ) {
V_26 = - V_34 ;
goto V_35;
}
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , V_33 ) )
F_18 ( V_9 ,
F_19 ( V_9 -> V_36 , V_33 ) -
V_9 -> V_36 ) ;
V_25 = (struct V_24 * ) V_9 -> V_36 ;
V_25 -> V_37 . V_38 = F_20 ( 0 ) ;
V_4 = F_21 ( V_8 -> V_3 -> V_15 , V_9 -> V_36 ,
V_9 -> V_16 + F_8 ( V_9 ) ,
V_17 ) ;
if ( F_22 ( F_23 ( V_8 -> V_3 -> V_15 , V_4 ) ) ) {
F_10 ( V_9 ) ;
V_26 = - V_34 ;
goto V_35;
}
V_6 = F_11 ( V_9 ) ;
V_6 -> V_4 = V_4 ;
V_8 -> V_13 . V_20 [ V_27 ] = V_9 ;
V_8 -> V_13 . V_39 [ V_27 ] = F_20 ( V_4 ) ;
V_8 -> V_13 . V_21 ++ ;
if ( V_8 -> V_13 . V_14 ) {
F_24 ( V_8 -> V_13 . V_22 ,
& F_11 ( V_9 ) -> V_18 ,
( T_1 ) V_4 ) ;
}
V_23 -- ;
V_27 ++ ;
V_27 &= V_8 -> V_13 . V_40 ;
}
V_35:
F_25 () ;
* V_8 -> V_13 . V_30 . V_31 = F_20 ( V_27 ) ;
return V_26 ;
}
static int F_26 ( struct V_7 * V_8 , int V_23 )
{
F_27 ( & V_8 -> V_13 . V_41 ) ;
return F_13 ( V_8 , V_23 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
int V_26 , V_42 , V_43 ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_42 = V_8 -> V_13 . V_44 - V_8 -> V_13 . V_21 ;
V_43 = F_30 ( V_45 , V_42 ) ;
V_42 -= V_43 ;
V_26 = F_26 ( V_8 , V_43 ) ;
if ( V_26 == - V_34 ) {
F_31 ( & V_8 -> V_13 . V_46 , V_47 +
F_32 ( V_48 ) ) ;
} else if ( V_42 > 0 ) {
F_33 ( & V_8 -> V_49 ) ;
}
F_34 ( & V_8 -> V_13 . V_41 ) ;
}
static void F_35 ( unsigned long V_50 )
{
struct V_7 * V_8 = (struct V_7 * ) V_50 ;
F_28 ( V_8 ) ;
}
int F_36 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
int V_26 ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_26 = F_26 ( V_8 , ( V_8 -> V_13 . V_44 -
V_8 -> V_13 . V_21 ) ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
if ( V_26 )
F_5 ( V_8 ) ;
return V_26 ;
}
void F_37 ( struct V_7 * V_8 )
{
F_38 ( & V_8 -> V_13 . V_46 ) ;
F_39 ( & V_8 -> V_49 ) ;
F_39 ( & V_8 -> V_51 ) ;
F_40 ( & V_8 -> V_52 ) ;
F_40 ( & V_8 -> V_53 ) ;
F_40 ( & V_8 -> V_54 ) ;
F_5 ( V_8 ) ;
F_41 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_55 ) ;
F_41 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
V_8 -> V_13 . V_30 . V_31 ,
V_8 -> V_13 . V_30 . V_4 ) ;
F_42 ( V_8 -> V_13 . V_20 ) ;
}
static inline struct V_1 * F_43 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_27 ;
struct V_1 * V_56 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_13 . V_21 == 0 ) {
F_44 ( V_3 , L_1 ) ;
return NULL ;
}
V_27 = V_8 -> V_13 . V_57 . V_58 ;
V_56 = V_8 -> V_13 . V_20 [ V_27 ] ;
V_8 -> V_13 . V_20 [ V_27 ] = NULL ;
V_8 -> V_13 . V_39 [ V_27 ] = 0 ;
V_27 ++ ;
V_27 &= V_8 -> V_13 . V_40 ;
V_8 -> V_13 . V_57 . V_58 = V_27 ;
V_8 -> V_13 . V_21 -- ;
F_7 ( V_8 -> V_3 -> V_15 ,
F_11 ( V_56 ) -> V_4 ,
V_56 -> V_16 + F_8 ( V_56 ) ,
V_17 ) ;
F_45 ( V_3 , V_59 , NULL , L_2 ,
V_56 -> V_36 , V_56 -> V_16 + F_8 ( V_56 ) ) ;
return V_56 ;
}
static int F_46 ( struct V_7 * V_8 ,
T_3 * * V_60 , int * V_61 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_64 , V_65 = 0 ;
struct V_1 * V_56 ;
struct V_24 * V_25 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
for (; ; ) {
int V_66 , V_67 , V_68 ;
V_56 = F_43 ( V_8 ) ;
if ( ! V_56 ) {
F_47 ( V_63 ) ;
return - V_69 ;
}
F_48 ( V_63 , V_56 ) ;
V_25 = (struct V_24 * ) V_56 -> V_36 ;
F_49 ( V_56 , F_50 ( struct V_24 , V_70 ) ) ;
F_18 ( V_56 , F_50 ( struct V_24 , V_70 ) ) ;
if ( ! ( F_15 ( V_25 -> V_37 . V_38 )
& V_71 ) ) {
F_47 ( V_63 ) ;
return - V_72 ;
}
if ( * V_61 > 0 ) {
V_25 -> V_60 . V_73 = * * V_60 ;
( * V_60 ) ++ ;
( * V_61 ) -- ;
} else {
V_25 -> V_60 . V_73 = 0 ;
}
V_67 = ! ! ( F_15 ( V_25 -> V_37 . V_38 )
& ( V_74 |
V_75 ) ) ;
V_64 = F_51 ( F_15 ( V_25 -> V_76 . V_73 ) ,
V_77 ) ;
V_68 = V_25 -> V_78 . V_79 ;
if ( V_67 )
V_64 = 0 ;
F_52 ( V_56 , 0 ) ;
F_49 ( V_56 , F_30 ( V_64 , V_80 ) ) ;
V_64 -= V_56 -> V_16 ;
while ( V_68 -- ) {
V_56 = F_43 ( V_8 ) ;
if ( ! V_56 ) {
F_47 ( V_63 ) ;
return - V_69 ;
}
F_48 ( V_63 , V_56 ) ;
F_52 ( V_56 , 0 ) ;
F_49 ( V_56 , F_30 ( V_64 , V_32 ) ) ;
V_64 -= V_56 -> V_16 ;
V_65 = 1 ;
}
V_66 = F_15 ( V_25 -> V_81 . V_73 ) &
V_82 ;
F_53 ( V_3 , & V_25 -> V_37 ,
sizeof( * V_25 ) - sizeof( T_1 ) ) ;
if ( V_66 )
break;
}
if ( F_54 ( V_63 ) )
V_65 = - 1 ;
return V_65 ;
}
static void F_55 ( unsigned long V_83 )
{
struct V_7 * V_8 = (struct V_7 * ) V_83 ;
F_28 ( V_8 ) ;
}
static struct V_1 * F_56 ( struct V_7 * V_8 ,
T_1 V_4 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_5 * V_6 ;
struct V_1 * V_56 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_56 = F_1 ( V_3 , V_4 ) ;
if ( ! V_56 )
return NULL ;
V_6 = F_11 ( V_56 ) ;
F_9 ( & V_6 -> V_18 ) ;
V_8 -> V_13 . V_21 -- ;
F_7 ( V_8 -> V_3 -> V_15 , V_6 -> V_4 ,
V_56 -> V_16 + F_8 ( V_56 ) ,
V_17 ) ;
F_45 ( V_3 , V_59 , NULL , L_2 ,
V_56 -> V_36 , V_56 -> V_16 + F_8 ( V_56 ) ) ;
return V_56 ;
}
static int F_57 ( struct V_7 * V_8 ,
struct V_84 * V_85 ,
struct V_62 * V_86 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_24 * V_90 ;
struct V_1 * V_56 ;
int V_91 ;
bool V_92 ;
T_1 V_4 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_91 = F_58 ( V_85 -> V_91 ) ;
V_92 = ! ! ( V_85 -> V_93 & V_94 ) ;
while ( V_91 -- ) {
V_4 = F_15 ( V_88 -> V_95 ) ;
V_56 = F_56 ( V_8 , V_4 ) ;
if ( ! V_56 ) {
F_47 ( V_86 ) ;
return - V_69 ;
}
F_48 ( V_86 , V_56 ) ;
if ( ! V_92 ) {
V_90 = ( void * ) V_56 -> V_36 ;
F_53 ( V_3 , V_90 , sizeof( * V_90 ) ) ;
F_49 ( V_56 , sizeof( * V_90 ) ) ;
F_18 ( V_56 , sizeof( * V_90 ) ) ;
F_49 ( V_56 , F_58 ( V_88 -> V_64 ) ) ;
if ( ! ( F_15 ( V_90 -> V_37 . V_38 ) &
V_71 ) ) {
F_44 ( V_8 -> V_3 , L_3 ) ;
return - V_72 ;
}
}
V_88 ++ ;
}
return 0 ;
}
int F_59 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_2 V_4 ;
void * V_31 ;
T_4 V_19 ;
struct V_96 * V_97 = & V_8 -> V_13 . V_46 ;
V_8 -> V_98 = false ;
V_8 -> V_13 . V_19 = V_29 ;
V_8 -> V_13 . V_40 = V_8 -> V_13 . V_19 - 1 ;
V_8 -> V_13 . V_44 = V_28 ;
if ( ! F_60 ( V_8 -> V_13 . V_19 ) ) {
F_44 ( V_3 , L_4 ) ;
return - V_99 ;
}
V_8 -> V_13 . V_20 =
F_61 ( V_8 -> V_13 . V_19 * sizeof( struct V_1 * ) ,
V_100 ) ;
if ( ! V_8 -> V_13 . V_20 )
goto V_101;
V_19 = V_8 -> V_13 . V_19 * sizeof( V_8 -> V_13 . V_39 ) ;
V_31 = F_62 ( V_8 -> V_3 -> V_15 , V_19 , & V_4 , V_102 ) ;
if ( ! V_31 )
goto V_103;
V_8 -> V_13 . V_39 = V_31 ;
V_8 -> V_13 . V_55 = V_4 ;
V_31 = F_62 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
& V_4 , V_102 ) ;
if ( ! V_31 )
goto V_104;
V_8 -> V_13 . V_30 . V_31 = V_31 ;
V_8 -> V_13 . V_30 . V_4 = V_4 ;
V_8 -> V_13 . V_57 . V_58 = V_8 -> V_13 . V_40 ;
* V_8 -> V_13 . V_30 . V_31 = 0 ;
F_63 ( V_97 , F_35 , ( unsigned long ) V_8 ) ;
F_64 ( & V_8 -> V_13 . V_41 ) ;
V_8 -> V_13 . V_21 = 0 ;
V_8 -> V_13 . V_57 . V_58 = 0 ;
F_12 ( V_8 -> V_13 . V_22 ) ;
F_65 ( & V_8 -> V_49 , F_55 ,
( unsigned long ) V_8 ) ;
F_66 ( & V_8 -> V_52 ) ;
F_66 ( & V_8 -> V_53 ) ;
F_66 ( & V_8 -> V_54 ) ;
F_65 ( & V_8 -> V_51 , V_105 ,
( unsigned long ) V_8 ) ;
F_67 ( V_3 , V_106 , L_5 ,
V_8 -> V_13 . V_19 , V_8 -> V_13 . V_44 ) ;
return 0 ;
V_104:
F_41 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_55 ) ;
V_103:
F_42 ( V_8 -> V_13 . V_20 ) ;
V_101:
return - V_34 ;
}
static int F_68 ( struct V_2 * V_3 ,
enum V_107 type )
{
switch ( type ) {
case V_108 :
return 0 ;
case V_109 :
case V_110 :
return V_111 ;
case V_112 :
case V_113 :
return V_114 ;
case V_115 :
return V_116 ;
case V_117 :
case V_118 :
break;
}
F_44 ( V_3 , L_6 , type ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
enum V_107 type )
{
switch ( type ) {
case V_108 :
return 0 ;
case V_109 :
case V_110 :
return V_119 ;
case V_112 :
case V_113 :
return V_120 ;
case V_115 :
return V_121 ;
case V_117 :
case V_118 :
break;
}
F_44 ( V_3 , L_6 , type ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 )
{
struct V_124 * V_125 ;
T_3 V_126 , V_127 , V_128 , V_129 , V_130 , V_131 ;
T_3 V_132 = 0 ;
T_1 V_133 , V_134 , V_135 ;
V_133 = F_15 ( V_90 -> V_136 . V_133 ) ;
V_134 = F_15 ( V_90 -> V_136 . V_134 ) ;
V_135 = F_15 ( V_90 -> V_136 . V_135 ) ;
V_132 = F_51 ( V_133 , V_137 ) ;
switch ( V_132 ) {
case V_138 :
if ( ! V_123 -> V_139 )
return;
V_126 = V_133 & V_140 ;
V_127 = F_51 ( V_133 , V_141 ) ;
V_127 &= ~ V_142 ;
V_125 = & V_3 -> V_143 . V_144 [ V_123 -> V_145 ] ;
V_123 -> V_146 = F_71 ( V_125 , V_127 ) ;
break;
case V_147 :
case V_148 :
V_130 = V_134 & 0x1F ;
V_131 = V_130 >> 3 ;
V_128 = ( V_134 >> 7 ) & 1 ;
V_129 = ( V_135 >> 7 ) & 1 ;
V_123 -> V_146 = V_130 ;
V_123 -> V_149 |= V_150 ;
if ( V_129 )
V_123 -> V_149 |= V_151 ;
if ( V_128 )
V_123 -> V_149 |= V_152 ;
break;
case V_153 :
case V_154 :
V_130 = ( V_135 >> 4 ) & 0x0F ;
V_131 = ( ( V_134 >> 10 ) & 0x07 ) + 1 ;
V_128 = V_134 & 3 ;
V_129 = V_135 & 1 ;
V_123 -> V_146 = V_130 ;
V_123 -> V_155 = V_131 ;
if ( V_129 )
V_123 -> V_149 |= V_151 ;
switch ( V_128 ) {
case 0 :
break;
case 1 :
V_123 -> V_149 |= V_152 ;
break;
case 2 :
V_123 -> V_156 |= V_157 ;
}
V_123 -> V_149 |= V_158 ;
break;
default:
break;
}
}
static struct V_159 *
F_72 ( struct V_2 * V_3 , struct V_24 * V_90 )
{
struct V_160 * V_161 ;
struct V_162 * V_163 ;
struct V_164 V_165 ;
T_5 V_166 ;
F_27 ( & V_3 -> V_167 ) ;
if ( ! V_90 )
return NULL ;
if ( V_90 -> V_37 . V_38 &
F_20 ( V_168 ) )
return NULL ;
if ( ! ( V_90 -> V_81 . V_73 &
F_20 ( V_169 ) ) )
return NULL ;
V_166 = F_51 ( F_15 ( V_90 -> V_170 . V_73 ) ,
V_171 ) ;
V_161 = F_73 ( V_3 , V_166 ) ;
if ( ! V_161 )
return NULL ;
V_163 = F_74 ( V_3 , V_161 -> V_172 ) ;
if ( F_4 ( ! V_163 ) )
return NULL ;
if ( F_75 ( F_76 ( V_163 -> V_173 , & V_165 ) ) )
return NULL ;
return V_165 . V_174 ;
}
static struct V_159 *
F_77 ( struct V_2 * V_3 , T_1 V_172 )
{
struct V_162 * V_163 ;
struct V_164 V_165 ;
F_27 ( & V_3 -> V_167 ) ;
F_78 (arvif, &ar->arvifs, list) {
if ( V_163 -> V_172 == V_172 &&
F_76 ( V_163 -> V_173 , & V_165 ) == 0 )
return V_165 . V_174 ;
}
return NULL ;
}
static void
F_79 ( struct V_175 * V_176 ,
struct V_177 * V_178 ,
void * V_36 )
{
struct V_164 * V_165 = V_36 ;
* V_165 = V_178 -> V_165 ;
}
static struct V_159 *
F_80 ( struct V_2 * V_3 )
{
struct V_164 V_165 = {} ;
F_81 ( V_3 -> V_176 ,
F_79 ,
& V_165 ) ;
return V_165 . V_174 ;
}
static bool F_82 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 ,
T_1 V_172 )
{
struct V_159 * V_179 ;
F_29 ( & V_3 -> V_167 ) ;
V_179 = V_3 -> V_180 ;
if ( ! V_179 )
V_179 = V_3 -> V_181 ;
if ( ! V_179 )
V_179 = F_72 ( V_3 , V_90 ) ;
if ( ! V_179 )
V_179 = F_77 ( V_3 , V_172 ) ;
if ( ! V_179 )
V_179 = F_80 ( V_3 ) ;
F_34 ( & V_3 -> V_167 ) ;
if ( ! V_179 )
return false ;
V_123 -> V_145 = V_179 -> V_145 ;
V_123 -> V_139 = V_179 -> V_182 ;
return true ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 )
{
V_123 -> signal = V_183 +
V_90 -> V_136 . V_184 ;
V_123 -> V_149 &= ~ V_185 ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 )
{
V_123 -> V_186 = F_15 ( V_90 -> V_187 . V_188 . V_189 ) ;
V_123 -> V_149 |= V_190 ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 ,
T_1 V_172 )
{
struct V_1 * V_191 ;
struct V_24 * V_90 ;
bool V_192 ;
bool V_193 ;
if ( F_54 ( V_63 ) )
return;
V_191 = F_86 ( V_63 ) ;
V_90 = ( void * ) V_191 -> V_36 - sizeof( * V_90 ) ;
V_192 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_194 ) ) ;
V_193 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_195 ) ) ;
if ( V_192 ) {
V_123 -> V_139 = 0 ;
V_123 -> V_146 = 0 ;
V_123 -> V_155 = 0 ;
V_123 -> V_156 &= ~ V_157 ;
V_123 -> V_149 &= ~ ( V_150 |
V_158 |
V_151 |
V_152 |
V_190 ) ;
V_123 -> V_149 |= V_185 ;
F_83 ( V_3 , V_123 , V_90 ) ;
F_82 ( V_3 , V_123 , V_90 , V_172 ) ;
F_70 ( V_3 , V_123 , V_90 ) ;
}
if ( V_193 )
F_84 ( V_3 , V_123 , V_90 ) ;
}
static char * F_87 ( struct V_196 * V_197 , char * V_198 , T_4 V_19 )
{
T_3 * V_199 ;
int V_200 ;
if ( ! F_88 ( V_197 -> V_201 ) )
return L_7 ;
V_199 = F_89 ( V_197 ) ;
V_200 = * V_199 & V_202 ;
if ( V_200 < 8 )
snprintf ( V_198 , V_19 , L_8 , V_200 , V_203 [ V_200 ] ) ;
else
snprintf ( V_198 , V_19 , L_9 , V_200 ) ;
return V_198 ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_122 * V_204 ,
struct V_1 * V_9 )
{
struct V_122 * V_123 ;
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
char V_200 [ 32 ] ;
V_123 = F_91 ( V_9 ) ;
* V_123 = * V_204 ;
F_67 ( V_3 , V_205 ,
L_10 ,
V_9 ,
V_9 -> V_16 ,
F_92 ( V_197 ) ,
F_87 ( V_197 , V_200 , sizeof( V_200 ) ) ,
F_93 ( F_94 ( V_197 ) ) ?
L_11 : L_12 ,
( F_58 ( V_197 -> V_206 ) & V_207 ) >> 4 ,
V_123 -> V_149 == 0 ? L_13 : L_7 ,
V_123 -> V_149 & V_150 ? L_14 : L_7 ,
V_123 -> V_149 & V_158 ? L_15 : L_7 ,
V_123 -> V_149 & V_152 ? L_16 : L_7 ,
V_123 -> V_156 & V_157 ? L_17 : L_7 ,
V_123 -> V_149 & V_151 ? L_18 : L_7 ,
V_123 -> V_146 ,
V_123 -> V_155 ,
V_123 -> V_139 ,
V_123 -> V_145 , V_123 -> V_149 ,
! ! ( V_123 -> V_149 & V_208 ) ,
! ! ( V_123 -> V_149 & V_209 ) ,
! ! ( V_123 -> V_149 & V_210 ) ) ;
F_45 ( V_3 , V_59 , NULL , L_19 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_95 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_96 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_97 ( V_3 -> V_176 , V_9 ) ;
}
static int F_98 ( struct V_2 * V_3 ,
struct V_196 * V_197 )
{
int V_16 = F_99 ( V_197 -> V_201 ) ;
if ( ! F_100 ( V_211 ,
V_3 -> V_212 ) )
V_16 = F_101 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
enum V_107 V_213 ,
bool V_214 )
{
struct V_196 * V_197 ;
struct V_24 * V_90 ;
T_4 V_215 ;
T_4 V_216 ;
bool V_217 ;
bool V_218 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_217 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_169 ) ) ;
V_218 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ;
if ( F_22 ( F_4 ( ! V_217 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_217 && V_218 ) ) ) )
return;
F_52 ( V_56 , V_56 -> V_16 - V_219 ) ;
if ( ! V_214 )
return;
V_197 = ( void * ) V_56 -> V_36 ;
F_52 ( V_56 , V_56 -> V_16 - F_69 ( V_3 , V_213 ) ) ;
if ( ! F_103 ( V_197 -> V_201 ) &&
V_213 == V_113 )
F_52 ( V_56 , V_56 -> V_16 - 8 ) ;
V_215 = F_99 ( V_197 -> V_201 ) ;
V_216 = F_68 ( V_3 , V_213 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_216 ,
( void * ) V_56 -> V_36 , V_215 ) ;
F_18 ( V_56 , V_216 ) ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_220 [ 64 ] )
{
struct V_196 * V_197 ;
T_4 V_215 ;
T_3 V_221 [ V_222 ] ;
T_3 V_223 [ V_222 ] ;
V_197 = (struct V_196 * ) V_56 -> V_36 ;
V_215 = F_98 ( V_3 , V_197 ) ;
F_105 ( V_221 , F_94 ( V_197 ) ) ;
F_105 ( V_223 , F_92 ( V_197 ) ) ;
F_18 ( V_56 , V_215 ) ;
V_197 = (struct V_196 * ) V_220 ;
V_215 = F_99 ( V_197 -> V_201 ) ;
memcpy ( F_106 ( V_56 , V_215 ) , V_197 , V_215 ) ;
V_197 = (struct V_196 * ) V_56 -> V_36 ;
F_105 ( F_94 ( V_197 ) , V_221 ) ;
F_105 ( F_92 ( V_197 ) , V_223 ) ;
}
static void * F_107 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
enum V_107 V_213 )
{
struct V_196 * V_197 ;
struct V_24 * V_90 ;
T_4 V_215 , V_216 ;
void * V_224 ;
bool V_217 , V_218 , V_225 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_197 = ( void * ) V_90 -> V_226 ;
V_217 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_169 ) ) ;
V_218 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ;
V_225 = ! ( V_217 && V_218 ) ;
V_224 = V_197 ;
if ( V_217 ) {
V_215 = F_99 ( V_197 -> V_201 ) ;
V_216 = F_68 ( V_3 , V_213 ) ;
V_224 += F_101 ( V_215 , 4 ) +
F_101 ( V_216 , 4 ) ;
}
if ( V_225 )
V_224 += sizeof( struct V_227 ) ;
return V_224 ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_220 [ 64 ] ,
enum V_107 V_213 )
{
struct V_196 * V_197 ;
struct V_228 * V_229 ;
T_4 V_215 ;
void * V_224 ;
T_3 V_221 [ V_222 ] ;
T_3 V_223 [ V_222 ] ;
V_224 = F_107 ( V_3 , V_56 , V_213 ) ;
if ( F_4 ( ! V_224 ) )
return;
V_229 = (struct V_228 * ) V_56 -> V_36 ;
F_105 ( V_221 , V_229 -> V_230 ) ;
F_105 ( V_223 , V_229 -> V_231 ) ;
F_18 ( V_56 , sizeof( struct V_228 ) ) ;
memcpy ( F_106 ( V_56 , sizeof( struct V_232 ) ) , V_224 ,
sizeof( struct V_232 ) ) ;
V_197 = (struct V_196 * ) V_220 ;
V_215 = F_99 ( V_197 -> V_201 ) ;
memcpy ( F_106 ( V_56 , V_215 ) , V_197 , V_215 ) ;
V_197 = (struct V_196 * ) V_56 -> V_36 ;
F_105 ( F_94 ( V_197 ) , V_221 ) ;
F_105 ( F_92 ( V_197 ) , V_223 ) ;
}
static void F_109 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_220 [ 64 ] )
{
struct V_196 * V_197 ;
T_4 V_215 ;
F_18 ( V_56 , sizeof( struct V_227 ) ) ;
V_197 = (struct V_196 * ) V_220 ;
V_215 = F_99 ( V_197 -> V_201 ) ;
memcpy ( F_106 ( V_56 , V_215 ) , V_197 , V_215 ) ;
}
static void F_110 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
T_3 V_220 [ 64 ] ,
enum V_107 V_213 ,
bool V_214 )
{
struct V_24 * V_90 ;
enum V_233 V_234 ;
struct V_196 * V_197 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_197 = ( void * ) V_90 -> V_226 ;
V_234 = F_51 ( F_15 ( V_90 -> V_76 . V_133 ) ,
V_235 ) ;
switch ( V_234 ) {
case V_236 :
F_102 ( V_3 , V_56 , V_123 , V_213 ,
V_214 ) ;
break;
case V_237 :
F_104 ( V_3 , V_56 , V_123 , V_220 ) ;
break;
case V_238 :
F_108 ( V_3 , V_56 , V_123 , V_220 , V_213 ) ;
break;
case V_239 :
F_109 ( V_3 , V_56 , V_123 , V_220 ) ;
break;
}
}
static int F_111 ( struct V_1 * V_9 )
{
struct V_24 * V_90 ;
T_1 V_38 , V_93 ;
bool V_240 , V_241 ;
bool V_242 , V_243 ;
bool V_244 , V_245 ;
V_90 = ( void * ) V_9 -> V_36 - sizeof( * V_90 ) ;
V_38 = F_15 ( V_90 -> V_37 . V_38 ) ;
V_93 = F_15 ( V_90 -> V_76 . V_133 ) ;
V_240 = ! ! ( V_93 & V_246 ) ;
V_241 = ! ! ( V_93 & V_247 ) ;
V_242 = ! ! ( V_93 & V_248 ) ;
V_243 = ! ! ( V_93 & V_249 ) ;
V_244 = ! ( V_38 & V_250 ) ;
V_245 = ! ( V_38 & V_251 ) ;
if ( ! V_240 && ! V_241 )
return V_252 ;
if ( ! V_242 && ! V_243 )
return V_252 ;
if ( ! V_244 )
return V_252 ;
if ( ! V_245 )
return V_252 ;
return V_253 ;
}
static void F_112 ( struct V_1 * V_56 )
{
V_56 -> V_254 = F_111 ( V_56 ) ;
}
static void F_113 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_191 ;
struct V_1 * V_255 ;
struct V_1 * V_56 ;
struct V_24 * V_90 ;
struct V_196 * V_197 ;
enum V_107 V_213 ;
T_3 V_220 [ 64 ] ;
T_3 * V_256 ;
T_4 V_215 ;
bool V_257 ;
bool V_258 ;
bool V_259 ;
bool V_260 ;
bool V_214 ;
T_1 V_37 ;
if ( F_54 ( V_63 ) )
return;
V_191 = F_86 ( V_63 ) ;
V_90 = ( void * ) V_191 -> V_36 - sizeof( * V_90 ) ;
V_213 = F_51 ( F_15 ( V_90 -> V_170 . V_73 ) ,
V_261 ) ;
V_197 = ( void * ) V_90 -> V_226 ;
V_215 = F_99 ( V_197 -> V_201 ) ;
memcpy ( V_220 , V_197 , V_215 ) ;
V_197 = ( void * ) V_220 ;
V_256 = F_89 ( V_197 ) ;
V_256 [ 0 ] &= ~ V_262 ;
V_255 = F_114 ( V_63 ) ;
V_90 = ( void * ) V_255 -> V_36 - sizeof( * V_90 ) ;
V_37 = F_15 ( V_90 -> V_37 . V_38 ) ;
V_257 = ! ! ( V_37 & V_263 ) ;
V_258 = ! ! ( V_37 & V_264 ) ;
V_259 = ! ! ( V_37 & V_265 ) ;
V_260 = ! ! ( V_37 & V_168 ) ;
V_214 = ( V_213 != V_108 &&
! V_257 &&
! V_258 &&
! V_260 ) ;
V_123 -> V_149 &= ~ ( V_208 |
V_209 |
V_266 |
V_267 |
V_268 ) ;
if ( V_257 )
V_123 -> V_149 |= V_208 ;
if ( V_259 )
V_123 -> V_149 |= V_209 ;
if ( V_214 )
V_123 -> V_149 |= V_266 |
V_267 |
V_268 ;
F_115 (amsdu, msdu) {
F_112 ( V_56 ) ;
F_110 ( V_3 , V_56 , V_123 , V_220 , V_213 ,
V_214 ) ;
if ( ! V_214 )
continue;
V_197 = ( void * ) V_56 -> V_36 ;
V_197 -> V_201 &= ~ F_116 ( V_269 ) ;
}
}
static void F_117 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_118 ( V_63 ) ) ) {
if ( F_54 ( V_63 ) )
V_123 -> V_149 &= ~ V_210 ;
else
V_123 -> V_149 |= V_210 ;
F_90 ( V_3 , V_123 , V_56 ) ;
}
}
static int F_119 ( struct V_62 * V_63 )
{
struct V_1 * V_9 , * V_191 ;
int V_270 ;
int V_271 = 0 ;
V_191 = F_118 ( V_63 ) ;
F_115 (amsdu, skb)
V_271 += V_9 -> V_16 ;
V_270 = V_271 - F_8 ( V_191 ) ;
if ( ( V_270 > 0 ) &&
( F_120 ( V_191 , 0 , V_270 , V_272 ) < 0 ) ) {
F_121 ( V_63 , V_191 ) ;
return - 1 ;
}
while ( ( V_9 = F_118 ( V_63 ) ) ) {
F_122 ( V_9 , F_49 ( V_191 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_121 ( V_63 , V_191 ) ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
bool V_273 )
{
struct V_1 * V_191 ;
struct V_24 * V_90 ;
enum V_233 V_234 ;
V_191 = F_86 ( V_63 ) ;
V_90 = ( void * ) V_191 -> V_36 - sizeof( * V_90 ) ;
V_234 = F_51 ( F_15 ( V_90 -> V_76 . V_133 ) ,
V_235 ) ;
if ( ! V_273 )
return;
if ( V_234 != V_236 ||
F_124 ( V_63 ) != 1 + V_90 -> V_78 . V_79 ) {
F_47 ( V_63 ) ;
return;
}
F_119 ( V_63 ) ;
}
static bool F_125 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_204 )
{
struct V_1 * V_56 ;
struct V_24 * V_90 ;
bool V_274 ;
bool V_257 ;
V_56 = F_86 ( V_63 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( ! V_204 -> V_139 ) {
F_44 ( V_3 , L_20 ) ;
return false ;
}
V_274 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_275 ) ) ;
V_257 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_263 ) ) ;
if ( V_274 && ! V_257 ) {
F_67 ( V_3 , V_276 , L_21 ) ;
return false ;
}
if ( F_100 ( V_277 , & V_3 -> V_278 ) ) {
F_67 ( V_3 , V_276 , L_22 ) ;
return false ;
}
return true ;
}
static void F_126 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_204 )
{
if ( F_54 ( V_63 ) )
return;
if ( F_125 ( V_3 , V_63 , V_204 ) )
return;
F_47 ( V_63 ) ;
}
static void F_127 ( struct V_7 * V_8 ,
struct V_279 * V_280 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_204 = & V_8 -> V_204 ;
struct V_281 * V_282 ;
struct V_62 V_63 ;
int V_283 ;
int V_61 ;
T_3 * V_60 ;
int V_12 , V_26 , V_284 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_98 )
return;
V_61 = F_58 ( V_280 -> V_285 . V_286 ) ;
V_60 = ( T_3 * ) & V_280 -> V_60 ;
V_283 = F_51 ( F_15 ( V_280 -> V_197 . V_133 ) ,
V_287 ) ;
V_282 = F_128 ( V_280 ) ;
F_45 ( V_3 , V_59 , NULL , L_23 ,
V_280 , sizeof( * V_280 ) +
( sizeof( struct V_281 ) *
V_283 ) ) ;
for ( V_12 = 0 ; V_12 < V_283 ; V_12 ++ )
V_284 += V_282 [ V_12 ] . V_284 ;
while ( V_284 -- ) {
F_129 ( & V_63 ) ;
V_26 = F_46 ( V_8 , & V_60 ,
& V_61 , & V_63 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_24 , V_26 ) ;
F_47 ( & V_63 ) ;
V_8 -> V_98 = true ;
break;
}
F_85 ( V_3 , & V_63 , V_204 , 0xffff ) ;
F_123 ( V_3 , & V_63 , V_26 > 0 ) ;
F_126 ( V_3 , & V_63 , V_204 ) ;
F_113 ( V_3 , & V_63 , V_204 ) ;
F_117 ( V_3 , & V_63 , V_204 ) ;
}
F_33 ( & V_8 -> V_49 ) ;
}
static void F_130 ( struct V_7 * V_8 ,
struct V_288 * V_289 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_204 = & V_8 -> V_204 ;
struct V_62 V_63 ;
int V_26 ;
T_3 * V_60 ;
int V_61 ;
V_61 = F_58 ( V_289 -> V_286 ) ;
V_60 = ( T_3 * ) V_289 -> V_290 ;
F_129 ( & V_63 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_26 = F_46 ( V_8 , & V_60 , & V_61 ,
& V_63 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_49 ) ;
F_67 ( V_3 , V_59 , L_25 ) ;
if ( V_26 ) {
F_44 ( V_3 , L_26 ,
V_26 ) ;
F_47 ( & V_63 ) ;
return;
}
if ( F_124 ( & V_63 ) != 1 ) {
F_44 ( V_3 , L_27 ) ;
F_47 ( & V_63 ) ;
return;
}
F_85 ( V_3 , & V_63 , V_204 , 0xffff ) ;
F_126 ( V_3 , & V_63 , V_204 ) ;
F_113 ( V_3 , & V_63 , V_204 ) ;
F_117 ( V_3 , & V_63 , V_204 ) ;
if ( V_61 > 0 ) {
F_67 ( V_3 , V_276 ,
L_28 ,
V_61 ) ;
}
}
static void F_131 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_291 * V_292 = (struct V_291 * ) V_9 -> V_36 ;
struct V_293 V_294 = {} ;
int V_123 = F_51 ( V_292 -> V_295 . V_38 , V_296 ) ;
T_6 V_297 ;
int V_12 ;
F_27 ( & V_8 -> V_298 ) ;
switch ( V_123 ) {
case V_299 :
V_294 . V_300 = true ;
break;
case V_301 :
V_294 . V_302 = true ;
break;
case V_303 :
case V_304 :
case V_305 :
V_294 . V_306 = true ;
break;
default:
F_44 ( V_3 , L_29 , V_123 ) ;
V_294 . V_306 = true ;
break;
}
F_67 ( V_3 , V_276 , L_30 ,
V_292 -> V_295 . V_307 ) ;
for ( V_12 = 0 ; V_12 < V_292 -> V_295 . V_307 ; V_12 ++ ) {
V_297 = V_292 -> V_295 . V_308 [ V_12 ] ;
V_294 . V_297 = F_58 ( V_297 ) ;
F_132 ( V_8 , & V_294 ) ;
}
}
static void F_133 ( struct V_2 * V_3 , struct V_291 * V_292 )
{
struct V_309 * V_85 = & V_292 -> V_310 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_73 , V_200 , V_166 ;
V_73 = F_58 ( V_85 -> V_73 ) ;
V_200 = F_51 ( V_73 , V_311 ) ;
V_166 = F_51 ( V_73 , V_312 ) ;
F_67 ( V_3 , V_276 ,
L_31 ,
V_200 , V_166 , V_85 -> V_313 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_73 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_44 ( V_3 , L_32 ,
V_166 ) ;
F_34 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_74 ( V_3 , V_161 -> V_172 ) ;
if ( ! V_163 ) {
F_44 ( V_3 , L_33 ,
V_161 -> V_172 ) ;
F_34 ( & V_3 -> V_167 ) ;
return;
}
F_67 ( V_3 , V_276 ,
L_34 ,
V_161 -> V_314 , V_200 , V_85 -> V_313 ) ;
F_134 ( V_163 -> V_173 , V_161 -> V_314 , V_200 ) ;
F_34 ( & V_3 -> V_167 ) ;
}
static void F_135 ( struct V_2 * V_3 , struct V_291 * V_292 )
{
struct V_315 * V_85 = & V_292 -> V_316 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_73 , V_200 , V_166 ;
V_73 = F_58 ( V_85 -> V_73 ) ;
V_200 = F_51 ( V_73 , V_311 ) ;
V_166 = F_51 ( V_73 , V_312 ) ;
F_67 ( V_3 , V_276 ,
L_35 ,
V_200 , V_166 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_73 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_44 ( V_3 , L_32 ,
V_166 ) ;
F_34 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_74 ( V_3 , V_161 -> V_172 ) ;
if ( ! V_163 ) {
F_44 ( V_3 , L_33 ,
V_161 -> V_172 ) ;
F_34 ( & V_3 -> V_167 ) ;
return;
}
F_67 ( V_3 , V_276 ,
L_36 ,
V_161 -> V_314 , V_200 ) ;
F_136 ( V_163 -> V_173 , V_161 -> V_314 , V_200 ) ;
F_34 ( & V_3 -> V_167 ) ;
}
static int F_137 ( struct V_62 * V_86 ,
struct V_62 * V_63 )
{
struct V_1 * V_56 ;
struct V_24 * V_90 ;
if ( F_54 ( V_86 ) )
return - V_317 ;
if ( F_75 ( ! F_54 ( V_63 ) ) )
return - V_99 ;
while ( ( V_56 = F_118 ( V_86 ) ) ) {
F_48 ( V_63 , V_56 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) )
break;
}
V_56 = F_114 ( V_63 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ) {
F_138 ( V_63 , V_86 ) ;
return - V_318 ;
}
return 0 ;
}
static void F_139 ( struct V_122 * V_123 ,
struct V_1 * V_9 )
{
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
if ( ! F_140 ( V_197 -> V_201 ) )
return;
V_197 -> V_201 &= ~ F_116 ( V_269 ) ;
V_123 -> V_149 |= V_266 |
V_267 |
V_268 ;
}
static void F_141 ( struct V_2 * V_3 ,
struct V_62 * V_86 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_122 * V_123 = & V_8 -> V_204 ;
struct V_319 * V_280 ;
struct V_1 * V_56 ;
T_4 V_320 ;
while ( ( V_56 = F_118 ( V_86 ) ) ) {
V_280 = ( void * ) V_56 -> V_36 ;
F_49 ( V_56 , sizeof( * V_280 ) ) ;
F_18 ( V_56 , sizeof( * V_280 ) ) ;
if ( F_8 ( V_56 ) < F_58 ( V_280 -> V_64 ) ) {
F_44 ( V_3 , L_37 ) ;
F_10 ( V_56 ) ;
continue;
}
F_49 ( V_56 , F_58 ( V_280 -> V_64 ) ) ;
V_320 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_49 ( V_56 , V_320 ) ;
memmove ( V_56 -> V_36 + V_320 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_320 ) ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_149 |= V_185 ;
F_139 ( V_123 , V_56 ) ;
F_82 ( V_3 , V_123 , NULL , V_280 -> V_172 ) ;
F_90 ( V_3 , V_123 , V_56 ) ;
}
}
static void F_142 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_291 * V_292 = ( void * ) V_9 -> V_36 ;
struct V_122 * V_123 = & V_8 -> V_204 ;
struct V_62 V_86 ;
struct V_62 V_63 ;
T_5 V_166 ;
T_5 V_91 ;
T_3 V_172 ;
T_3 V_200 ;
bool V_321 ;
bool V_289 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_98 )
return;
F_18 ( V_9 , sizeof( V_292 -> V_197 ) ) ;
F_18 ( V_9 , sizeof( V_292 -> V_322 ) ) ;
V_166 = F_58 ( V_292 -> V_322 . V_166 ) ;
V_91 = F_58 ( V_292 -> V_322 . V_91 ) ;
V_172 = V_292 -> V_322 . V_172 ;
V_200 = F_143 ( V_292 -> V_322 . V_93 , V_323 ) ;
V_321 = ! ! ( V_292 -> V_322 . V_93 &
V_94 ) ;
V_289 = ! ! ( V_292 -> V_322 . V_93 & V_324 ) ;
F_67 ( V_3 , V_276 ,
L_38 ,
V_172 , V_166 , V_200 , V_321 , V_289 , V_91 ) ;
if ( V_9 -> V_16 < V_91 * sizeof( * V_292 -> V_322 . V_89 ) ) {
F_44 ( V_3 , L_39 ) ;
return;
}
F_129 ( & V_86 ) ;
V_26 = F_57 ( V_8 , & V_292 -> V_322 , & V_86 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_40 , V_26 ) ;
V_8 -> V_98 = true ;
return;
}
if ( V_321 )
F_141 ( V_3 , & V_86 ) ;
while ( ! F_54 ( & V_86 ) ) {
F_129 ( & V_63 ) ;
V_26 = F_137 ( & V_86 , & V_63 ) ;
switch ( V_26 ) {
case 0 :
F_85 ( V_3 , & V_63 , V_123 , V_172 ) ;
F_126 ( V_3 , & V_63 , V_123 ) ;
F_113 ( V_3 , & V_63 , V_123 ) ;
F_117 ( V_3 , & V_63 , V_123 ) ;
break;
case - V_318 :
default:
F_44 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_98 = true ;
F_47 ( & V_86 ) ;
return;
}
}
F_33 ( & V_8 -> V_49 ) ;
}
void F_144 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_291 * V_292 = (struct V_291 * ) V_9 -> V_36 ;
enum V_325 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_44 ( V_3 , L_42 ) ;
F_67 ( V_3 , V_276 , L_43 ,
V_292 -> V_197 . V_326 ) ;
if ( V_292 -> V_197 . V_326 >= V_3 -> V_8 . V_327 ) {
F_67 ( V_3 , V_276 , L_44 ,
V_292 -> V_197 . V_326 , V_3 -> V_8 . V_327 ) ;
F_10 ( V_9 ) ;
return;
}
type = V_3 -> V_8 . V_328 [ V_292 -> V_197 . V_326 ] ;
switch ( type ) {
case V_329 : {
V_8 -> V_330 = V_292 -> V_331 . V_332 ;
V_8 -> V_333 = V_292 -> V_331 . V_334 ;
F_145 ( & V_8 -> V_335 ) ;
break;
}
case V_336 :
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_53 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_337 : {
struct V_338 V_85 = {
. V_172 = V_292 -> V_339 . V_172 ,
. V_166 = F_58 ( V_292 -> V_339 . V_166 ) ,
} ;
memcpy ( V_85 . V_314 , V_292 -> V_339 . V_314 , sizeof( V_85 . V_314 ) ) ;
F_146 ( V_8 , & V_85 ) ;
break;
}
case V_340 : {
struct V_341 V_85 = {
. V_166 = F_58 ( V_292 -> V_342 . V_166 ) ,
} ;
F_147 ( V_8 , & V_85 ) ;
break;
}
case V_343 : {
struct V_293 V_294 = {} ;
int V_123 = F_15 ( V_292 -> V_344 . V_123 ) ;
V_294 . V_297 =
F_15 ( V_292 -> V_344 . V_345 ) ;
switch ( V_123 ) {
case V_346 :
V_294 . V_302 = true ;
break;
case V_347 :
V_294 . V_300 = true ;
break;
case V_348 :
V_294 . V_306 = true ;
break;
}
F_29 ( & V_8 -> V_298 ) ;
F_132 ( V_8 , & V_294 ) ;
F_34 ( & V_8 -> V_298 ) ;
break;
}
case V_349 :
F_29 ( & V_8 -> V_298 ) ;
F_48 ( & V_8 -> V_52 , V_9 ) ;
F_34 ( & V_8 -> V_298 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_350 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_351 * V_85 = & V_292 -> V_352 ;
F_67 ( V_3 , V_276 ,
L_45 ,
F_58 ( V_85 -> V_166 ) ,
! ! ( V_85 -> V_38 & V_353 ) ,
F_51 ( V_85 -> V_38 , V_354 ) ) ;
F_145 ( & V_3 -> V_355 ) ;
break;
}
case V_356 : {
F_45 ( V_3 , V_59 , NULL , L_46 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_130 ( V_8 , & V_292 -> V_357 ) ;
break;
}
case V_358 :
break;
case V_359 :
F_148 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_360 :
F_44 ( V_3 , L_47 ) ;
break;
case V_361 :
F_133 ( V_3 , V_292 ) ;
break;
case V_362 :
F_135 ( V_3 , V_292 ) ;
break;
case V_363 : {
struct V_364 * V_197 =
(struct V_364 * ) V_292 -> V_365 . V_366 ;
F_149 ( V_3 , V_292 -> V_365 . V_366 ,
sizeof( * V_197 ) +
F_58 ( V_197 -> V_19 ) ) ;
break;
}
case V_367 : {
break;
}
case V_368 : {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_54 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
}
case V_369 :
break;
case V_370 :
break;
default:
F_44 ( V_3 , L_48 ,
V_292 -> V_197 . V_326 ) ;
F_45 ( V_3 , V_59 , NULL , L_46 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
F_10 ( V_9 ) ;
}
static void V_105 ( unsigned long V_83 )
{
struct V_7 * V_8 = (struct V_7 * ) V_83 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_291 * V_292 ;
struct V_1 * V_9 ;
F_29 ( & V_8 -> V_298 ) ;
while ( ( V_9 = F_118 ( & V_8 -> V_52 ) ) ) {
F_131 ( V_8 -> V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_298 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
while ( ( V_9 = F_118 ( & V_8 -> V_53 ) ) ) {
V_292 = (struct V_291 * ) V_9 -> V_36 ;
F_127 ( V_8 , & V_292 -> V_371 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_118 ( & V_8 -> V_54 ) ) ) {
F_142 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_13 . V_41 ) ;
}
