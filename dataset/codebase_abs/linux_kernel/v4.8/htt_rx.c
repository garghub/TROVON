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
F_31 ( & V_8 -> V_13 . V_46 , V_47 +
F_32 ( V_49 ) ) ;
}
F_33 ( & V_8 -> V_13 . V_41 ) ;
}
static void F_34 ( unsigned long V_50 )
{
struct V_7 * V_8 = (struct V_7 * ) V_50 ;
F_28 ( V_8 ) ;
}
int F_35 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
int V_26 ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_26 = F_26 ( V_8 , ( V_8 -> V_13 . V_44 -
V_8 -> V_13 . V_21 ) ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_26 )
F_5 ( V_8 ) ;
return V_26 ;
}
void F_36 ( struct V_7 * V_8 )
{
F_37 ( & V_8 -> V_13 . V_46 ) ;
F_38 ( & V_8 -> V_51 ) ;
F_39 ( & V_8 -> V_52 ) ;
F_39 ( & V_8 -> V_53 ) ;
F_39 ( & V_8 -> V_54 ) ;
F_5 ( V_8 ) ;
F_40 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_55 ) ;
F_40 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
V_8 -> V_13 . V_30 . V_31 ,
V_8 -> V_13 . V_30 . V_4 ) ;
F_41 ( V_8 -> V_13 . V_20 ) ;
}
static inline struct V_1 * F_42 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_27 ;
struct V_1 * V_56 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_13 . V_21 == 0 ) {
F_43 ( V_3 , L_1 ) ;
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
F_44 ( V_3 , V_59 , NULL , L_2 ,
V_56 -> V_36 , V_56 -> V_16 + F_8 ( V_56 ) ) ;
return V_56 ;
}
static int F_45 ( struct V_7 * V_8 ,
struct V_60 * V_61 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_62 , V_63 = 0 ;
struct V_1 * V_56 ;
struct V_24 * V_25 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
for (; ; ) {
int V_64 , V_65 , V_66 ;
V_56 = F_42 ( V_8 ) ;
if ( ! V_56 ) {
F_46 ( V_61 ) ;
return - V_67 ;
}
F_47 ( V_61 , V_56 ) ;
V_25 = (struct V_24 * ) V_56 -> V_36 ;
F_48 ( V_56 , F_49 ( struct V_24 , V_68 ) ) ;
F_18 ( V_56 , F_49 ( struct V_24 , V_68 ) ) ;
if ( ! ( F_15 ( V_25 -> V_37 . V_38 )
& V_69 ) ) {
F_46 ( V_61 ) ;
return - V_70 ;
}
V_65 = ! ! ( F_15 ( V_25 -> V_37 . V_38 )
& ( V_71 |
V_72 ) ) ;
V_62 = F_50 ( F_15 ( V_25 -> V_73 . V_74 . V_75 ) ,
V_76 ) ;
V_66 = V_25 -> V_77 . V_78 ;
if ( V_65 )
V_62 = 0 ;
F_51 ( V_56 , 0 ) ;
F_48 ( V_56 , F_30 ( V_62 , V_79 ) ) ;
V_62 -= V_56 -> V_16 ;
while ( V_66 -- ) {
V_56 = F_42 ( V_8 ) ;
if ( ! V_56 ) {
F_46 ( V_61 ) ;
return - V_67 ;
}
F_47 ( V_61 , V_56 ) ;
F_51 ( V_56 , 0 ) ;
F_48 ( V_56 , F_30 ( V_62 , V_32 ) ) ;
V_62 -= V_56 -> V_16 ;
V_63 = 1 ;
}
V_64 = F_15 ( V_25 -> V_80 . V_74 . V_75 ) &
V_81 ;
F_52 ( V_3 , & V_25 -> V_37 ,
sizeof( * V_25 ) - sizeof( T_1 ) ) ;
if ( V_64 )
break;
}
if ( F_53 ( V_61 ) )
V_63 = - 1 ;
return V_63 ;
}
static struct V_1 * F_54 ( struct V_7 * V_8 ,
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
F_44 ( V_3 , V_59 , NULL , L_2 ,
V_56 -> V_36 , V_56 -> V_16 + F_8 ( V_56 ) ) ;
return V_56 ;
}
static int F_55 ( struct V_7 * V_8 ,
struct V_82 * V_83 ,
struct V_60 * V_84 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_85 * V_86 = V_83 -> V_87 ;
struct V_24 * V_88 ;
struct V_1 * V_56 ;
int V_89 ;
bool V_90 ;
T_1 V_4 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_89 = F_56 ( V_83 -> V_89 ) ;
V_90 = ! ! ( V_83 -> V_91 & V_92 ) ;
while ( V_89 -- ) {
V_4 = F_15 ( V_86 -> V_93 ) ;
V_56 = F_54 ( V_8 , V_4 ) ;
if ( ! V_56 ) {
F_46 ( V_84 ) ;
return - V_67 ;
}
F_47 ( V_84 , V_56 ) ;
if ( ! V_90 ) {
V_88 = ( void * ) V_56 -> V_36 ;
F_52 ( V_3 , V_88 , sizeof( * V_88 ) ) ;
F_48 ( V_56 , sizeof( * V_88 ) ) ;
F_18 ( V_56 , sizeof( * V_88 ) ) ;
F_48 ( V_56 , F_56 ( V_86 -> V_62 ) ) ;
if ( ! ( F_15 ( V_88 -> V_37 . V_38 ) &
V_69 ) ) {
F_43 ( V_8 -> V_3 , L_3 ) ;
return - V_70 ;
}
}
V_86 ++ ;
}
return 0 ;
}
int F_57 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_2 V_4 ;
void * V_31 ;
T_3 V_19 ;
struct V_94 * V_95 = & V_8 -> V_13 . V_46 ;
V_8 -> V_96 = false ;
V_8 -> V_13 . V_19 = V_29 ;
V_8 -> V_13 . V_40 = V_8 -> V_13 . V_19 - 1 ;
V_8 -> V_13 . V_44 = V_28 ;
if ( ! F_58 ( V_8 -> V_13 . V_19 ) ) {
F_43 ( V_3 , L_4 ) ;
return - V_97 ;
}
V_8 -> V_13 . V_20 =
F_59 ( V_8 -> V_13 . V_19 * sizeof( struct V_1 * ) ,
V_98 ) ;
if ( ! V_8 -> V_13 . V_20 )
goto V_99;
V_19 = V_8 -> V_13 . V_19 * sizeof( V_8 -> V_13 . V_39 ) ;
V_31 = F_60 ( V_8 -> V_3 -> V_15 , V_19 , & V_4 , V_98 ) ;
if ( ! V_31 )
goto V_100;
V_8 -> V_13 . V_39 = V_31 ;
V_8 -> V_13 . V_55 = V_4 ;
V_31 = F_60 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
& V_4 , V_98 ) ;
if ( ! V_31 )
goto V_101;
V_8 -> V_13 . V_30 . V_31 = V_31 ;
V_8 -> V_13 . V_30 . V_4 = V_4 ;
V_8 -> V_13 . V_57 . V_58 = V_8 -> V_13 . V_40 ;
* V_8 -> V_13 . V_30 . V_31 = 0 ;
F_61 ( V_95 , F_34 , ( unsigned long ) V_8 ) ;
F_62 ( & V_8 -> V_13 . V_41 ) ;
V_8 -> V_13 . V_21 = 0 ;
V_8 -> V_13 . V_57 . V_58 = 0 ;
F_12 ( V_8 -> V_13 . V_22 ) ;
F_63 ( & V_8 -> V_52 ) ;
F_63 ( & V_8 -> V_53 ) ;
F_63 ( & V_8 -> V_54 ) ;
F_64 ( & V_8 -> V_102 , 0 ) ;
F_65 ( & V_8 -> V_51 , V_103 ,
( unsigned long ) V_8 ) ;
F_66 ( V_3 , V_104 , L_5 ,
V_8 -> V_13 . V_19 , V_8 -> V_13 . V_44 ) ;
return 0 ;
V_101:
F_40 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_55 ) ;
V_100:
F_41 ( V_8 -> V_13 . V_20 ) ;
V_99:
return - V_34 ;
}
static int F_67 ( struct V_2 * V_3 ,
enum V_105 type )
{
switch ( type ) {
case V_106 :
return 0 ;
case V_107 :
case V_108 :
return V_109 ;
case V_110 :
case V_111 :
return V_112 ;
case V_113 :
return V_114 ;
case V_115 :
case V_116 :
break;
}
F_43 ( V_3 , L_6 , type ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
enum V_105 type )
{
switch ( type ) {
case V_106 :
return 0 ;
case V_107 :
case V_108 :
return V_117 ;
case V_110 :
case V_111 :
return V_118 ;
case V_113 :
return V_119 ;
case V_115 :
case V_116 :
break;
}
F_43 ( V_3 , L_6 , type ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_120 * V_121 ,
struct V_24 * V_88 )
{
struct V_122 * V_123 ;
T_4 V_124 , V_125 , V_126 , V_127 , V_128 , V_129 ;
T_4 V_130 = 0 ;
T_4 V_131 ;
T_1 V_132 , V_133 , V_134 ;
V_132 = F_15 ( V_88 -> V_135 . V_132 ) ;
V_133 = F_15 ( V_88 -> V_135 . V_133 ) ;
V_134 = F_15 ( V_88 -> V_135 . V_134 ) ;
V_130 = F_50 ( V_132 , V_136 ) ;
switch ( V_130 ) {
case V_137 :
if ( ! V_121 -> V_138 )
return;
V_124 = V_132 & V_139 ;
V_125 = F_50 ( V_132 , V_140 ) ;
V_125 &= ~ V_141 ;
V_123 = & V_3 -> V_142 . V_143 [ V_121 -> V_144 ] ;
V_121 -> V_145 = F_70 ( V_123 , V_125 , V_124 ) ;
break;
case V_146 :
case V_147 :
V_128 = V_133 & 0x1F ;
V_129 = V_128 >> 3 ;
V_126 = ( V_133 >> 7 ) & 1 ;
V_127 = ( V_134 >> 7 ) & 1 ;
V_121 -> V_145 = V_128 ;
V_121 -> V_148 |= V_149 ;
if ( V_127 )
V_121 -> V_148 |= V_150 ;
if ( V_126 )
V_121 -> V_148 |= V_151 ;
break;
case V_152 :
case V_153 :
V_126 = V_133 & 3 ;
V_127 = V_134 & 1 ;
V_131 = ( V_133 >> 4 ) & 0x3F ;
if ( F_71 ( V_131 ) ) {
V_128 = ( V_134 >> 4 ) & 0x0F ;
V_129 = ( ( V_133 >> 10 ) & 0x07 ) + 1 ;
} else {
V_128 = 0 ;
V_129 = 1 ;
}
if ( V_128 > 0x09 ) {
F_43 ( V_3 , L_7 , V_128 ) ;
F_43 ( V_3 , L_8 ,
F_15 ( V_88 -> V_37 . V_38 ) ,
F_15 ( V_88 -> V_154 . V_75 ) ,
F_15 ( V_88 -> V_154 . V_132 ) ,
F_15 ( V_88 -> V_73 . V_74 . V_75 ) ,
F_15 ( V_88 -> V_73 . V_74 . V_132 ) ,
V_88 -> V_135 . V_75 ,
F_15 ( V_88 -> V_135 . V_132 ) ,
F_15 ( V_88 -> V_135 . V_133 ) ,
F_15 ( V_88 -> V_135 . V_134 ) ,
F_15 ( V_88 -> V_135 . V_155 ) ) ;
F_43 ( V_3 , L_9 ,
F_15 ( V_88 -> V_80 . V_74 . V_75 ) ,
F_15 ( V_88 -> V_156 . V_75 ) ) ;
F_44 ( V_3 , V_59 , NULL ,
L_10 ,
V_88 -> V_68 , 50 ) ;
}
V_121 -> V_145 = V_128 ;
V_121 -> V_157 = V_129 ;
if ( V_127 )
V_121 -> V_148 |= V_150 ;
switch ( V_126 ) {
case 0 :
break;
case 1 :
V_121 -> V_148 |= V_151 ;
break;
case 2 :
V_121 -> V_158 |= V_159 ;
}
V_121 -> V_148 |= V_160 ;
break;
default:
break;
}
}
static struct V_161 *
F_72 ( struct V_2 * V_3 , struct V_24 * V_88 )
{
struct V_162 * V_163 ;
struct V_164 * V_165 ;
struct V_166 V_167 ;
T_5 V_168 ;
F_27 ( & V_3 -> V_169 ) ;
if ( ! V_88 )
return NULL ;
if ( V_88 -> V_37 . V_38 &
F_20 ( V_170 ) )
return NULL ;
if ( ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_171 ) ) )
return NULL ;
V_168 = F_50 ( F_15 ( V_88 -> V_154 . V_75 ) ,
V_172 ) ;
V_163 = F_73 ( V_3 , V_168 ) ;
if ( ! V_163 )
return NULL ;
V_165 = F_74 ( V_3 , V_163 -> V_173 ) ;
if ( F_4 ( ! V_165 ) )
return NULL ;
if ( F_75 ( V_165 -> V_174 , & V_167 ) )
return NULL ;
return V_167 . V_175 ;
}
static struct V_161 *
F_76 ( struct V_2 * V_3 , T_1 V_173 )
{
struct V_164 * V_165 ;
struct V_166 V_167 ;
F_27 ( & V_3 -> V_169 ) ;
F_77 (arvif, &ar->arvifs, list) {
if ( V_165 -> V_173 == V_173 &&
F_75 ( V_165 -> V_174 , & V_167 ) == 0 )
return V_167 . V_175 ;
}
return NULL ;
}
static void
F_78 ( struct V_176 * V_177 ,
struct V_178 * V_179 ,
void * V_36 )
{
struct V_166 * V_167 = V_36 ;
* V_167 = V_179 -> V_167 ;
}
static struct V_161 *
F_79 ( struct V_2 * V_3 )
{
struct V_166 V_167 = {} ;
F_80 ( V_3 -> V_177 ,
F_78 ,
& V_167 ) ;
return V_167 . V_175 ;
}
static bool F_81 ( struct V_2 * V_3 ,
struct V_120 * V_121 ,
struct V_24 * V_88 ,
T_1 V_173 )
{
struct V_161 * V_180 ;
F_29 ( & V_3 -> V_169 ) ;
V_180 = V_3 -> V_181 ;
if ( ! V_180 )
V_180 = V_3 -> V_182 ;
if ( ! V_180 )
V_180 = F_72 ( V_3 , V_88 ) ;
if ( ! V_180 )
V_180 = F_76 ( V_3 , V_173 ) ;
if ( ! V_180 )
V_180 = F_79 ( V_3 ) ;
if ( ! V_180 )
V_180 = V_3 -> V_183 ;
F_33 ( & V_3 -> V_169 ) ;
if ( ! V_180 )
return false ;
V_121 -> V_144 = V_180 -> V_144 ;
V_121 -> V_138 = V_180 -> V_184 ;
return true ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_120 * V_121 ,
struct V_24 * V_88 )
{
V_121 -> signal = V_185 +
V_88 -> V_135 . V_186 ;
V_121 -> V_148 &= ~ V_187 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_120 * V_121 ,
struct V_24 * V_88 )
{
V_121 -> V_188 = F_15 ( V_88 -> V_189 . V_74 . V_190 ) ;
V_121 -> V_148 |= V_191 ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_120 * V_121 ,
T_1 V_173 )
{
struct V_1 * V_192 ;
struct V_24 * V_88 ;
bool V_193 ;
bool V_194 ;
if ( F_53 ( V_61 ) )
return;
V_192 = F_85 ( V_61 ) ;
V_88 = ( void * ) V_192 -> V_36 - sizeof( * V_88 ) ;
V_193 = ! ! ( V_88 -> V_37 . V_38 &
F_20 ( V_195 ) ) ;
V_194 = ! ! ( V_88 -> V_37 . V_38 &
F_20 ( V_196 ) ) ;
if ( V_193 ) {
V_121 -> V_138 = 0 ;
V_121 -> V_145 = 0 ;
V_121 -> V_157 = 0 ;
V_121 -> V_158 &= ~ V_159 ;
V_121 -> V_148 &= ~ ( V_149 |
V_160 |
V_150 |
V_151 |
V_191 ) ;
V_121 -> V_148 |= V_187 ;
F_82 ( V_3 , V_121 , V_88 ) ;
F_81 ( V_3 , V_121 , V_88 , V_173 ) ;
F_69 ( V_3 , V_121 , V_88 ) ;
}
if ( V_194 )
F_83 ( V_3 , V_121 , V_88 ) ;
}
static char * F_86 ( struct V_197 * V_198 , char * V_199 , T_3 V_19 )
{
T_4 * V_200 ;
int V_201 ;
if ( ! F_87 ( V_198 -> V_202 ) )
return L_11 ;
V_200 = F_88 ( V_198 ) ;
V_201 = * V_200 & V_203 ;
if ( V_201 < 8 )
snprintf ( V_199 , V_19 , L_12 , V_201 , V_204 [ V_201 ] ) ;
else
snprintf ( V_199 , V_19 , L_13 , V_201 ) ;
return V_199 ;
}
static void F_89 ( struct V_2 * V_3 ,
struct V_120 * V_205 ,
struct V_1 * V_9 )
{
struct V_120 * V_121 ;
struct V_197 * V_198 = (struct V_197 * ) V_9 -> V_36 ;
char V_201 [ 32 ] ;
V_121 = F_90 ( V_9 ) ;
* V_121 = * V_205 ;
F_66 ( V_3 , V_206 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_91 ( V_198 ) ,
F_86 ( V_198 , V_201 , sizeof( V_201 ) ) ,
F_92 ( F_93 ( V_198 ) ) ?
L_15 : L_16 ,
( F_56 ( V_198 -> V_207 ) & V_208 ) >> 4 ,
( V_121 -> V_148 & ( V_149 | V_160 ) ) == 0 ?
L_17 : L_11 ,
V_121 -> V_148 & V_149 ? L_18 : L_11 ,
V_121 -> V_148 & V_160 ? L_19 : L_11 ,
V_121 -> V_148 & V_151 ? L_20 : L_11 ,
V_121 -> V_158 & V_159 ? L_21 : L_11 ,
V_121 -> V_148 & V_150 ? L_22 : L_11 ,
V_121 -> V_145 ,
V_121 -> V_157 ,
V_121 -> V_138 ,
V_121 -> V_144 , V_121 -> V_148 ,
! ! ( V_121 -> V_148 & V_209 ) ,
! ! ( V_121 -> V_148 & V_210 ) ,
! ! ( V_121 -> V_148 & V_211 ) ) ;
F_44 ( V_3 , V_59 , NULL , L_23 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_94 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_95 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_96 ( V_3 -> V_177 , V_9 ) ;
}
static int F_97 ( struct V_2 * V_3 ,
struct V_197 * V_198 )
{
int V_16 = F_98 ( V_198 -> V_202 ) ;
if ( ! F_99 ( V_212 ,
V_3 -> V_213 -> V_214 . V_215 ) )
V_16 = F_100 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_101 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_120 * V_121 ,
enum V_105 V_216 ,
bool V_217 )
{
struct V_197 * V_198 ;
struct V_24 * V_88 ;
T_3 V_218 ;
T_3 V_219 ;
bool V_220 ;
bool V_221 ;
V_88 = ( void * ) V_56 -> V_36 - sizeof( * V_88 ) ;
V_220 = ! ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_171 ) ) ;
V_221 = ! ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_81 ) ) ;
if ( F_22 ( F_4 ( ! V_220 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_220 && V_221 ) ) ) )
return;
F_51 ( V_56 , V_56 -> V_16 - V_222 ) ;
if ( ! V_217 )
return;
V_198 = ( void * ) V_56 -> V_36 ;
if ( V_121 -> V_148 & V_223 )
F_51 ( V_56 , V_56 -> V_16 -
F_68 ( V_3 , V_216 ) ) ;
if ( ( V_121 -> V_148 & V_224 ) &&
! F_102 ( V_198 -> V_202 ) &&
V_216 == V_111 )
F_51 ( V_56 , V_56 -> V_16 - 8 ) ;
if ( V_121 -> V_148 & V_223 ) {
V_218 = F_98 ( V_198 -> V_202 ) ;
V_219 = F_67 ( V_3 , V_216 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_219 ,
( void * ) V_56 -> V_36 , V_218 ) ;
F_18 ( V_56 , V_219 ) ;
}
}
static void F_103 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_120 * V_121 ,
const T_4 V_225 [ 64 ] )
{
struct V_197 * V_198 ;
T_3 V_218 ;
T_4 V_226 [ V_227 ] ;
T_4 V_228 [ V_227 ] ;
if ( ( V_3 -> V_229 . V_230 == V_231 ) &&
F_104 ( ( (struct V_197 * ) V_225 ) -> V_202 ) ) {
V_198 = (struct V_197 * ) ( V_56 -> V_36 + 2 ) ;
F_48 ( V_56 , 2 ) ;
} else {
V_198 = (struct V_197 * ) ( V_56 -> V_36 ) ;
}
V_218 = F_97 ( V_3 , V_198 ) ;
F_105 ( V_226 , F_93 ( V_198 ) ) ;
F_105 ( V_228 , F_91 ( V_198 ) ) ;
F_18 ( V_56 , V_218 ) ;
V_198 = (struct V_197 * ) V_225 ;
V_218 = F_98 ( V_198 -> V_202 ) ;
memcpy ( F_106 ( V_56 , V_218 ) , V_198 , V_218 ) ;
V_198 = (struct V_197 * ) V_56 -> V_36 ;
F_105 ( F_93 ( V_198 ) , V_226 ) ;
F_105 ( F_91 ( V_198 ) , V_228 ) ;
}
static void * F_107 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
enum V_105 V_216 )
{
struct V_197 * V_198 ;
struct V_24 * V_88 ;
T_3 V_218 , V_219 ;
void * V_232 ;
bool V_220 , V_221 , V_233 ;
V_88 = ( void * ) V_56 -> V_36 - sizeof( * V_88 ) ;
V_198 = ( void * ) V_88 -> V_234 ;
V_220 = ! ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_171 ) ) ;
V_221 = ! ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_81 ) ) ;
V_233 = ! ( V_220 && V_221 ) ;
V_232 = V_198 ;
if ( V_220 ) {
V_218 = F_98 ( V_198 -> V_202 ) ;
V_219 = F_67 ( V_3 , V_216 ) ;
V_232 += F_100 ( V_218 , 4 ) +
F_100 ( V_219 , 4 ) ;
}
if ( V_233 )
V_232 += sizeof( struct V_235 ) ;
return V_232 ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_120 * V_121 ,
const T_4 V_225 [ 64 ] ,
enum V_105 V_216 )
{
struct V_197 * V_198 ;
struct V_236 * V_237 ;
T_3 V_218 ;
void * V_232 ;
T_4 V_226 [ V_227 ] ;
T_4 V_228 [ V_227 ] ;
V_232 = F_107 ( V_3 , V_56 , V_216 ) ;
if ( F_4 ( ! V_232 ) )
return;
V_237 = (struct V_236 * ) V_56 -> V_36 ;
F_105 ( V_226 , V_237 -> V_238 ) ;
F_105 ( V_228 , V_237 -> V_239 ) ;
F_18 ( V_56 , sizeof( struct V_236 ) ) ;
memcpy ( F_106 ( V_56 , sizeof( struct V_240 ) ) , V_232 ,
sizeof( struct V_240 ) ) ;
V_198 = (struct V_197 * ) V_225 ;
V_218 = F_98 ( V_198 -> V_202 ) ;
memcpy ( F_106 ( V_56 , V_218 ) , V_198 , V_218 ) ;
V_198 = (struct V_197 * ) V_56 -> V_36 ;
F_105 ( F_93 ( V_198 ) , V_226 ) ;
F_105 ( F_91 ( V_198 ) , V_228 ) ;
}
static void F_109 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_120 * V_121 ,
const T_4 V_225 [ 64 ] )
{
struct V_197 * V_198 ;
T_3 V_218 ;
F_18 ( V_56 , sizeof( struct V_235 ) ) ;
V_198 = (struct V_197 * ) V_225 ;
V_218 = F_98 ( V_198 -> V_202 ) ;
memcpy ( F_106 ( V_56 , V_218 ) , V_198 , V_218 ) ;
}
static void F_110 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_120 * V_121 ,
T_4 V_225 [ 64 ] ,
enum V_105 V_216 ,
bool V_217 )
{
struct V_24 * V_88 ;
enum V_241 V_242 ;
V_88 = ( void * ) V_56 -> V_36 - sizeof( * V_88 ) ;
V_242 = F_50 ( F_15 ( V_88 -> V_73 . V_74 . V_132 ) ,
V_243 ) ;
switch ( V_242 ) {
case V_244 :
F_101 ( V_3 , V_56 , V_121 , V_216 ,
V_217 ) ;
break;
case V_245 :
F_103 ( V_3 , V_56 , V_121 , V_225 ) ;
break;
case V_246 :
F_108 ( V_3 , V_56 , V_121 , V_225 , V_216 ) ;
break;
case V_247 :
F_109 ( V_3 , V_56 , V_121 , V_225 ) ;
break;
}
}
static int F_111 ( struct V_1 * V_9 )
{
struct V_24 * V_88 ;
T_1 V_38 , V_91 ;
bool V_248 , V_249 ;
bool V_250 , V_251 ;
bool V_252 , V_253 ;
V_88 = ( void * ) V_9 -> V_36 - sizeof( * V_88 ) ;
V_38 = F_15 ( V_88 -> V_37 . V_38 ) ;
V_91 = F_15 ( V_88 -> V_73 . V_74 . V_132 ) ;
V_248 = ! ! ( V_91 & V_254 ) ;
V_249 = ! ! ( V_91 & V_255 ) ;
V_250 = ! ! ( V_91 & V_256 ) ;
V_251 = ! ! ( V_91 & V_257 ) ;
V_252 = ! ( V_38 & V_258 ) ;
V_253 = ! ( V_38 & V_259 ) ;
if ( ! V_248 && ! V_249 )
return V_260 ;
if ( ! V_250 && ! V_251 )
return V_260 ;
if ( ! V_252 )
return V_260 ;
if ( ! V_253 )
return V_260 ;
return V_261 ;
}
static void F_112 ( struct V_1 * V_56 )
{
V_56 -> V_262 = F_111 ( V_56 ) ;
}
static void F_113 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_120 * V_121 )
{
struct V_1 * V_192 ;
struct V_1 * V_263 ;
struct V_1 * V_56 ;
struct V_24 * V_88 ;
struct V_197 * V_198 ;
enum V_105 V_216 ;
T_4 V_225 [ 64 ] ;
T_4 * V_264 ;
T_3 V_218 ;
bool V_265 ;
bool V_266 ;
bool V_267 ;
bool V_268 ;
bool V_217 ;
bool V_269 ;
T_1 V_37 ;
if ( F_53 ( V_61 ) )
return;
V_192 = F_85 ( V_61 ) ;
V_88 = ( void * ) V_192 -> V_36 - sizeof( * V_88 ) ;
V_269 = ! ! ( V_88 -> V_37 . V_38 &
F_20 ( V_270 ) ) ;
V_216 = F_50 ( F_15 ( V_88 -> V_154 . V_75 ) ,
V_271 ) ;
V_198 = ( void * ) V_88 -> V_234 ;
V_218 = F_98 ( V_198 -> V_202 ) ;
memcpy ( V_225 , V_198 , V_218 ) ;
V_198 = ( void * ) V_225 ;
V_264 = F_88 ( V_198 ) ;
V_264 [ 0 ] &= ~ V_272 ;
V_263 = F_114 ( V_61 ) ;
V_88 = ( void * ) V_263 -> V_36 - sizeof( * V_88 ) ;
V_37 = F_15 ( V_88 -> V_37 . V_38 ) ;
V_265 = ! ! ( V_37 & V_273 ) ;
V_266 = ! ! ( V_37 & V_274 ) ;
V_267 = ! ! ( V_37 & V_275 ) ;
V_268 = ! ! ( V_37 & V_170 ) ;
V_217 = ( V_216 != V_106 &&
! V_265 &&
! V_266 &&
! V_268 ) ;
V_121 -> V_148 &= ~ ( V_209 |
V_210 |
V_276 |
V_223 |
V_277 |
V_224 ) ;
if ( V_265 )
V_121 -> V_148 |= V_209 ;
if ( V_267 )
V_121 -> V_148 |= V_210 ;
if ( V_269 )
V_121 -> V_148 |= V_277 ;
if ( V_217 ) {
V_121 -> V_148 |= V_276 ;
if ( F_115 ( ! V_269 ) )
V_121 -> V_148 |= V_223 |
V_224 ;
}
F_116 (amsdu, msdu) {
F_112 ( V_56 ) ;
F_110 ( V_3 , V_56 , V_121 , V_225 , V_216 ,
V_217 ) ;
if ( ! V_217 )
continue;
if ( V_269 )
continue;
V_198 = ( void * ) V_56 -> V_36 ;
V_198 -> V_202 &= ~ F_117 ( V_278 ) ;
}
}
static void F_118 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_120 * V_121 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_119 ( V_61 ) ) ) {
if ( F_53 ( V_61 ) )
V_121 -> V_148 &= ~ V_211 ;
else
V_121 -> V_148 |= V_211 ;
F_89 ( V_3 , V_121 , V_56 ) ;
}
}
static int F_120 ( struct V_60 * V_61 )
{
struct V_1 * V_9 , * V_192 ;
int V_279 ;
int V_280 = 0 ;
V_192 = F_119 ( V_61 ) ;
F_116 (amsdu, skb)
V_280 += V_9 -> V_16 ;
V_279 = V_280 - F_8 ( V_192 ) ;
if ( ( V_279 > 0 ) &&
( F_121 ( V_192 , 0 , V_279 , V_281 ) < 0 ) ) {
F_122 ( V_61 , V_192 ) ;
return - 1 ;
}
while ( ( V_9 = F_119 ( V_61 ) ) ) {
F_123 ( V_9 , F_48 ( V_192 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_122 ( V_61 , V_192 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
bool V_282 )
{
struct V_1 * V_192 ;
struct V_24 * V_88 ;
enum V_241 V_242 ;
V_192 = F_85 ( V_61 ) ;
V_88 = ( void * ) V_192 -> V_36 - sizeof( * V_88 ) ;
V_242 = F_50 ( F_15 ( V_88 -> V_73 . V_74 . V_132 ) ,
V_243 ) ;
if ( ! V_282 )
return;
if ( V_242 != V_244 ||
F_125 ( V_61 ) != 1 + V_88 -> V_77 . V_78 ) {
F_46 ( V_61 ) ;
return;
}
F_120 ( V_61 ) ;
}
static bool F_126 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_120 * V_205 )
{
if ( ! V_205 -> V_138 ) {
F_43 ( V_3 , L_24 ) ;
return false ;
}
if ( F_99 ( V_283 , & V_3 -> V_284 ) ) {
F_66 ( V_3 , V_285 , L_25 ) ;
return false ;
}
return true ;
}
static void F_127 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_120 * V_205 )
{
if ( F_53 ( V_61 ) )
return;
if ( F_126 ( V_3 , V_61 , V_205 ) )
return;
F_46 ( V_61 ) ;
}
static int F_128 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_120 * V_205 = & V_8 -> V_205 ;
struct V_60 V_61 ;
int V_26 ;
F_129 ( & V_61 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_96 ) {
F_33 ( & V_8 -> V_13 . V_41 ) ;
return - V_70 ;
}
V_26 = F_45 ( V_8 , & V_61 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_26 < 0 ) {
F_43 ( V_3 , L_26 , V_26 ) ;
F_46 ( & V_61 ) ;
V_8 -> V_96 = true ;
return V_26 ;
}
F_84 ( V_3 , & V_61 , V_205 , 0xffff ) ;
F_124 ( V_3 , & V_61 , V_26 > 0 ) ;
F_127 ( V_3 , & V_61 , V_205 ) ;
F_113 ( V_3 , & V_61 , V_205 ) ;
F_118 ( V_3 , & V_61 , V_205 ) ;
return 0 ;
}
static void F_130 ( struct V_7 * V_8 ,
struct V_286 * V_287 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_288 * V_289 ;
int V_290 ;
int V_12 , V_291 = 0 ;
V_290 = F_50 ( F_15 ( V_287 -> V_198 . V_132 ) ,
V_292 ) ;
V_289 = F_131 ( V_287 ) ;
F_44 ( V_3 , V_59 , NULL , L_27 ,
V_287 , sizeof( * V_287 ) +
( sizeof( struct V_288 ) *
V_290 ) ) ;
for ( V_12 = 0 ; V_12 < V_290 ; V_12 ++ )
V_291 += V_289 [ V_12 ] . V_291 ;
F_132 ( V_291 , & V_8 -> V_102 ) ;
F_133 ( & V_8 -> V_51 ) ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_135 ( & V_8 -> V_102 ) ;
F_133 ( & V_8 -> V_51 ) ;
}
static void F_136 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_293 * V_294 = (struct V_293 * ) V_9 -> V_36 ;
struct V_295 V_296 = {} ;
int V_121 = F_50 ( V_294 -> V_297 . V_38 , V_298 ) ;
T_6 V_299 ;
int V_12 ;
switch ( V_121 ) {
case V_300 :
V_296 . V_121 = V_301 ;
break;
case V_302 :
V_296 . V_121 = V_303 ;
break;
case V_304 :
case V_305 :
case V_306 :
V_296 . V_121 = V_307 ;
break;
default:
F_43 ( V_3 , L_28 , V_121 ) ;
V_296 . V_121 = V_307 ;
break;
}
F_66 ( V_3 , V_285 , L_29 ,
V_294 -> V_297 . V_308 ) ;
for ( V_12 = 0 ; V_12 < V_294 -> V_297 . V_308 ; V_12 ++ ) {
V_299 = V_294 -> V_297 . V_309 [ V_12 ] ;
V_296 . V_299 = F_56 ( V_299 ) ;
if ( ! F_137 ( & V_8 -> V_310 , V_296 ) ) {
F_43 ( V_3 , L_30 ,
V_296 . V_299 , V_296 . V_121 ) ;
F_138 ( V_8 , & V_296 ) ;
}
}
}
static void F_139 ( struct V_2 * V_3 , struct V_293 * V_294 )
{
struct V_311 * V_83 = & V_294 -> V_312 ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
T_5 V_75 , V_201 , V_168 ;
V_75 = F_56 ( V_83 -> V_75 ) ;
V_201 = F_50 ( V_75 , V_313 ) ;
V_168 = F_50 ( V_75 , V_314 ) ;
F_66 ( V_3 , V_285 ,
L_31 ,
V_201 , V_168 , V_83 -> V_315 ) ;
F_29 ( & V_3 -> V_169 ) ;
V_163 = F_73 ( V_3 , V_168 ) ;
if ( ! V_163 ) {
F_43 ( V_3 , L_32 ,
V_168 ) ;
F_33 ( & V_3 -> V_169 ) ;
return;
}
V_165 = F_74 ( V_3 , V_163 -> V_173 ) ;
if ( ! V_165 ) {
F_43 ( V_3 , L_33 ,
V_163 -> V_173 ) ;
F_33 ( & V_3 -> V_169 ) ;
return;
}
F_66 ( V_3 , V_285 ,
L_34 ,
V_163 -> V_316 , V_201 , V_83 -> V_315 ) ;
F_140 ( V_165 -> V_174 , V_163 -> V_316 , V_201 ) ;
F_33 ( & V_3 -> V_169 ) ;
}
static void F_141 ( struct V_2 * V_3 , struct V_293 * V_294 )
{
struct V_317 * V_83 = & V_294 -> V_318 ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
T_5 V_75 , V_201 , V_168 ;
V_75 = F_56 ( V_83 -> V_75 ) ;
V_201 = F_50 ( V_75 , V_313 ) ;
V_168 = F_50 ( V_75 , V_314 ) ;
F_66 ( V_3 , V_285 ,
L_35 ,
V_201 , V_168 ) ;
F_29 ( & V_3 -> V_169 ) ;
V_163 = F_73 ( V_3 , V_168 ) ;
if ( ! V_163 ) {
F_43 ( V_3 , L_32 ,
V_168 ) ;
F_33 ( & V_3 -> V_169 ) ;
return;
}
V_165 = F_74 ( V_3 , V_163 -> V_173 ) ;
if ( ! V_165 ) {
F_43 ( V_3 , L_33 ,
V_163 -> V_173 ) ;
F_33 ( & V_3 -> V_169 ) ;
return;
}
F_66 ( V_3 , V_285 ,
L_36 ,
V_163 -> V_316 , V_201 ) ;
F_142 ( V_165 -> V_174 , V_163 -> V_316 , V_201 ) ;
F_33 ( & V_3 -> V_169 ) ;
}
static int F_143 ( struct V_60 * V_84 ,
struct V_60 * V_61 )
{
struct V_1 * V_56 ;
struct V_24 * V_88 ;
if ( F_53 ( V_84 ) )
return - V_319 ;
if ( F_144 ( ! F_53 ( V_61 ) ) )
return - V_97 ;
while ( ( V_56 = F_119 ( V_84 ) ) ) {
F_47 ( V_61 , V_56 ) ;
V_88 = ( void * ) V_56 -> V_36 - sizeof( * V_88 ) ;
if ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_81 ) )
break;
}
V_56 = F_114 ( V_61 ) ;
V_88 = ( void * ) V_56 -> V_36 - sizeof( * V_88 ) ;
if ( ! ( V_88 -> V_80 . V_74 . V_75 &
F_20 ( V_81 ) ) ) {
F_145 ( V_61 , V_84 ) ;
return - V_320 ;
}
return 0 ;
}
static void F_146 ( struct V_120 * V_121 ,
struct V_1 * V_9 )
{
struct V_197 * V_198 = (struct V_197 * ) V_9 -> V_36 ;
if ( ! F_147 ( V_198 -> V_202 ) )
return;
V_198 -> V_202 &= ~ F_117 ( V_278 ) ;
V_121 -> V_148 |= V_276 |
V_223 |
V_224 ;
}
static void F_148 ( struct V_2 * V_3 ,
struct V_60 * V_84 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_120 * V_121 = & V_8 -> V_205 ;
struct V_321 * V_287 ;
struct V_1 * V_56 ;
T_3 V_322 ;
while ( ( V_56 = F_119 ( V_84 ) ) ) {
V_287 = ( void * ) V_56 -> V_36 ;
F_48 ( V_56 , sizeof( * V_287 ) ) ;
F_18 ( V_56 , sizeof( * V_287 ) ) ;
if ( F_8 ( V_56 ) < F_56 ( V_287 -> V_62 ) ) {
F_43 ( V_3 , L_37 ) ;
F_10 ( V_56 ) ;
continue;
}
F_48 ( V_56 , F_56 ( V_287 -> V_62 ) ) ;
V_322 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_48 ( V_56 , V_322 ) ;
memmove ( V_56 -> V_36 + V_322 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_322 ) ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_148 |= V_187 ;
F_146 ( V_121 , V_56 ) ;
F_81 ( V_3 , V_121 , NULL , V_287 -> V_173 ) ;
F_89 ( V_3 , V_121 , V_56 ) ;
}
}
static void F_149 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_293 * V_294 = ( void * ) V_9 -> V_36 ;
struct V_120 * V_121 = & V_8 -> V_205 ;
struct V_60 V_84 ;
struct V_60 V_61 ;
T_5 V_168 ;
T_5 V_89 ;
T_4 V_173 ;
T_4 V_201 ;
bool V_323 ;
bool V_324 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_96 )
return;
F_18 ( V_9 , sizeof( V_294 -> V_198 ) ) ;
F_18 ( V_9 , sizeof( V_294 -> V_325 ) ) ;
V_168 = F_56 ( V_294 -> V_325 . V_168 ) ;
V_89 = F_56 ( V_294 -> V_325 . V_89 ) ;
V_173 = V_294 -> V_325 . V_173 ;
V_201 = F_150 ( V_294 -> V_325 . V_91 , V_326 ) ;
V_323 = ! ! ( V_294 -> V_325 . V_91 &
V_92 ) ;
V_324 = ! ! ( V_294 -> V_325 . V_91 & V_327 ) ;
F_66 ( V_3 , V_285 ,
L_38 ,
V_173 , V_168 , V_201 , V_323 , V_324 , V_89 ) ;
if ( V_9 -> V_16 < V_89 * sizeof( * V_294 -> V_325 . V_87 ) ) {
F_43 ( V_3 , L_39 ) ;
return;
}
F_129 ( & V_84 ) ;
V_26 = F_55 ( V_8 , & V_294 -> V_325 , & V_84 ) ;
if ( V_26 < 0 ) {
F_43 ( V_3 , L_40 , V_26 ) ;
V_8 -> V_96 = true ;
return;
}
if ( V_323 )
F_148 ( V_3 , & V_84 ) ;
while ( ! F_53 ( & V_84 ) ) {
F_129 ( & V_61 ) ;
V_26 = F_143 ( & V_84 , & V_61 ) ;
switch ( V_26 ) {
case 0 :
F_84 ( V_3 , & V_61 , V_121 , V_173 ) ;
F_127 ( V_3 , & V_61 , V_121 ) ;
F_113 ( V_3 , & V_61 , V_121 ) ;
F_118 ( V_3 , & V_61 , V_121 ) ;
break;
case - V_320 :
default:
F_43 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_96 = true ;
F_46 ( & V_84 ) ;
return;
}
}
}
static void F_151 ( struct V_2 * V_3 ,
const T_7 * V_328 ,
int V_329 )
{
int V_12 ;
T_1 V_330 ;
F_66 ( V_3 , V_285 , L_42 ,
V_329 ) ;
for ( V_12 = 0 ; V_12 < V_329 ; V_12 ++ ) {
V_330 = F_152 ( V_328 [ V_12 ] ) ;
F_66 ( V_3 , V_285 , L_43 ,
V_330 ) ;
}
}
static void F_153 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_176 * V_177 = V_3 -> V_177 ;
struct V_331 * V_332 ;
struct V_293 * V_294 = (struct V_293 * ) V_9 -> V_36 ;
struct V_333 * V_334 ;
T_3 V_16 ;
T_3 V_335 ;
T_3 V_336 ;
T_3 V_337 ;
T_3 V_308 ;
const T_7 * V_328 ;
T_5 V_338 ;
T_5 V_329 ;
T_5 V_168 ;
T_4 V_201 ;
int V_26 ;
int V_12 ;
F_66 ( V_3 , V_285 , L_44 ) ;
V_16 = sizeof( V_294 -> V_198 ) + sizeof( V_294 -> V_339 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_45 ) ;
return;
}
V_338 = F_154 ( V_294 -> V_339 . V_338 ) ;
V_329 = F_154 ( V_294 -> V_339 . V_329 ) ;
V_16 += sizeof( V_294 -> V_339 . V_340 [ 0 ] ) * V_338 ;
V_16 += sizeof( V_294 -> V_339 . V_328 [ 0 ] ) * V_329 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_46 ) ;
return;
}
F_66 ( V_3 , V_285 , L_47 ,
V_338 , V_329 ,
F_154 ( V_294 -> V_339 . V_341 ) ) ;
if ( ! V_3 -> V_8 . V_342 . V_343 ) {
F_43 ( V_3 , L_48 ) ;
return;
}
if ( V_3 -> V_8 . V_342 . V_344 == V_345 ) {
F_43 ( V_3 , L_49 ) ;
return;
}
F_155 () ;
for ( V_12 = 0 ; V_12 < V_338 ; V_12 ++ ) {
V_334 = & V_294 -> V_339 . V_340 [ V_12 ] ;
V_168 = F_50 ( F_154 ( V_334 -> V_91 ) ,
V_346 ) ;
V_201 = F_50 ( F_154 ( V_334 -> V_91 ) ,
V_347 ) ;
V_336 = F_154 ( V_334 -> V_308 ) ;
V_335 = F_152 ( V_334 -> V_337 ) ;
F_66 ( V_3 , V_285 , L_50 ,
V_12 , V_168 , V_201 , V_336 , V_335 ) ;
if ( F_22 ( V_168 >= V_3 -> V_8 . V_342 . V_348 ) ||
F_22 ( V_201 >= V_3 -> V_8 . V_342 . V_349 ) ) {
F_43 ( V_3 , L_51 ,
V_168 , V_201 ) ;
continue;
}
F_29 ( & V_3 -> V_169 ) ;
V_332 = F_156 ( V_3 , V_168 , V_201 ) ;
F_33 ( & V_3 -> V_169 ) ;
if ( F_22 ( ! V_332 ) ) {
F_43 ( V_3 , L_52 ,
V_168 , V_201 ) ;
continue;
}
V_308 = 0 ;
V_337 = 0 ;
while ( V_308 < V_336 &&
V_337 < V_335 ) {
V_26 = F_157 ( V_177 , V_332 ) ;
if ( V_26 < 0 )
break;
V_308 ++ ;
V_337 += V_26 ;
}
V_334 -> V_308 = F_158 ( V_308 ) ;
V_334 -> V_337 = F_159 ( V_337 ) ;
F_160 ( V_177 , V_332 ) ;
}
F_161 () ;
V_328 = F_162 ( & V_294 -> V_339 ) ;
F_151 ( V_3 , V_328 , V_329 ) ;
V_26 = F_163 ( V_3 ,
V_294 -> V_339 . V_350 ,
V_294 -> V_339 . V_341 ,
V_294 -> V_339 . V_340 ,
V_338 ) ;
if ( F_22 ( V_26 ) ) {
F_43 ( V_3 , L_53 ,
F_152 ( V_294 -> V_339 . V_350 ) , V_26 ) ;
}
F_164 ( V_3 ) ;
}
static void F_165 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_293 * V_294 = ( void * ) V_9 -> V_36 ;
T_3 V_16 ;
int V_329 ;
F_66 ( V_3 , V_285 , L_54 ) ;
V_16 = sizeof( V_294 -> V_198 ) + sizeof( V_294 -> V_351 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_55 ) ;
return;
}
V_329 = F_154 ( V_294 -> V_351 . V_329 ) ;
V_16 += sizeof( V_294 -> V_351 . V_328 [ 0 ] ) * V_329 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_56 ) ;
return;
}
F_151 ( V_3 ,
V_294 -> V_351 . V_328 ,
V_329 ) ;
}
static void F_166 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_293 * V_294 = ( void * ) V_9 -> V_36 ;
const struct V_352 * V_334 ;
struct V_331 * V_332 ;
struct V_353 * V_354 ;
T_3 V_16 ;
T_3 V_338 ;
enum V_355 V_344 ;
bool V_356 ;
T_5 V_75 ;
T_5 V_132 ;
T_5 V_357 ;
T_5 V_168 ;
T_4 V_201 ;
int V_12 ;
F_66 ( V_3 , V_285 , L_57 ) ;
V_16 = sizeof( V_294 -> V_198 ) + sizeof( V_294 -> V_358 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_58 ) ;
return;
}
V_75 = F_154 ( V_294 -> V_358 . V_75 ) ;
V_132 = F_154 ( V_294 -> V_358 . V_132 ) ;
V_356 = ! ! ( V_75 & V_359 ) ;
V_338 = F_50 ( V_75 , V_360 ) ;
V_344 = F_50 ( V_132 , V_361 ) ;
V_357 = F_50 ( V_132 , V_360 ) ;
F_66 ( V_3 , V_285 ,
L_59 ,
V_75 , V_132 , V_356 , V_338 , V_344 , V_357 ) ;
V_16 += sizeof( V_294 -> V_358 . V_340 [ 0 ] ) * V_338 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_43 ( V_3 , L_60 ) ;
return;
}
switch ( V_344 ) {
case V_345 :
case V_362 :
break;
default:
F_43 ( V_3 , L_61 ,
V_344 ) ;
return;
}
if ( ! V_356 )
return;
V_3 -> V_8 . V_342 . V_343 = V_356 ;
V_3 -> V_8 . V_342 . V_344 = V_344 ;
V_3 -> V_8 . V_342 . V_363 = V_357 ;
F_155 () ;
for ( V_12 = 0 ; V_12 < V_338 ; V_12 ++ ) {
V_334 = & V_294 -> V_358 . V_340 [ V_12 ] ;
V_75 = F_154 ( V_334 -> V_75 ) ;
V_168 = F_50 ( V_75 , V_364 ) ;
V_201 = F_50 ( V_75 , V_365 ) ;
if ( F_22 ( V_168 >= V_3 -> V_8 . V_342 . V_348 ) ||
F_22 ( V_201 >= V_3 -> V_8 . V_342 . V_349 ) ) {
F_43 ( V_3 , L_51 ,
V_168 , V_201 ) ;
continue;
}
F_29 ( & V_3 -> V_169 ) ;
V_332 = F_156 ( V_3 , V_168 , V_201 ) ;
F_33 ( & V_3 -> V_169 ) ;
if ( F_22 ( ! V_332 ) ) {
F_43 ( V_3 , L_52 ,
V_168 , V_201 ) ;
continue;
}
F_29 ( & V_3 -> V_8 . V_366 ) ;
V_354 = ( void * ) V_332 -> V_367 ;
V_354 -> V_363 = F_154 ( V_334 -> V_368 ) ;
F_33 ( & V_3 -> V_8 . V_366 ) ;
}
F_161 () ;
F_167 ( V_3 ) ;
}
void F_168 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
bool V_369 ;
V_369 = F_169 ( V_3 , V_9 ) ;
if ( V_369 )
F_10 ( V_9 ) ;
}
bool F_169 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_293 * V_294 = (struct V_293 * ) V_9 -> V_36 ;
enum V_370 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_43 ( V_3 , L_62 ) ;
F_66 ( V_3 , V_285 , L_63 ,
V_294 -> V_198 . V_371 ) ;
if ( V_294 -> V_198 . V_371 >= V_3 -> V_8 . V_372 ) {
F_66 ( V_3 , V_285 , L_64 ,
V_294 -> V_198 . V_371 , V_3 -> V_8 . V_372 ) ;
return true ;
}
type = V_3 -> V_8 . V_373 [ V_294 -> V_198 . V_371 ] ;
switch ( type ) {
case V_374 : {
V_8 -> V_375 = V_294 -> V_376 . V_377 ;
V_8 -> V_378 = V_294 -> V_376 . V_379 ;
F_170 ( & V_8 -> V_380 ) ;
break;
}
case V_381 :
F_130 ( V_8 , & V_294 -> V_382 ) ;
break;
case V_383 : {
struct V_384 V_83 = {
. V_173 = V_294 -> V_385 . V_173 ,
. V_168 = F_56 ( V_294 -> V_385 . V_168 ) ,
} ;
memcpy ( V_83 . V_316 , V_294 -> V_385 . V_316 , sizeof( V_83 . V_316 ) ) ;
F_171 ( V_8 , & V_83 ) ;
break;
}
case V_386 : {
struct V_387 V_83 = {
. V_168 = F_56 ( V_294 -> V_388 . V_168 ) ,
} ;
F_172 ( V_8 , & V_83 ) ;
break;
}
case V_389 : {
struct V_295 V_296 = {} ;
int V_121 = F_15 ( V_294 -> V_390 . V_121 ) ;
V_296 . V_299 = F_15 ( V_294 -> V_390 . V_391 ) ;
switch ( V_121 ) {
case V_392 :
V_296 . V_121 = V_303 ;
break;
case V_393 :
V_296 . V_121 = V_301 ;
break;
case V_394 :
V_296 . V_121 = V_307 ;
break;
}
V_121 = F_138 ( V_8 , & V_296 ) ;
if ( ! V_121 ) {
F_29 ( & V_8 -> V_366 ) ;
F_173 ( V_8 ) ;
F_33 ( & V_8 -> V_366 ) ;
}
break;
}
case V_395 :
F_136 ( V_8 -> V_3 , V_9 ) ;
F_133 ( & V_8 -> V_51 ) ;
break;
case V_396 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_397 * V_83 = & V_294 -> V_398 ;
F_66 ( V_3 , V_285 ,
L_65 ,
F_56 ( V_83 -> V_168 ) ,
! ! ( V_83 -> V_38 & V_399 ) ,
F_50 ( V_83 -> V_38 , V_400 ) ) ;
F_170 ( & V_3 -> V_401 ) ;
break;
}
case V_402 : {
F_44 ( V_3 , V_59 , NULL , L_66 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_134 ( V_8 ) ;
break;
}
case V_403 :
break;
case V_404 :
F_174 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_405 :
F_43 ( V_3 , L_67 ) ;
break;
case V_406 :
F_139 ( V_3 , V_294 ) ;
break;
case V_407 :
F_141 ( V_3 , V_294 ) ;
break;
case V_408 : {
F_175 ( V_3 , V_294 -> V_409 . V_410 ,
V_9 -> V_16 -
F_49 ( struct V_293 ,
V_409 . V_410 ) ) ;
break;
}
case V_411 : {
break;
}
case V_412 : {
F_176 ( & V_8 -> V_53 , V_9 ) ;
F_133 ( & V_8 -> V_51 ) ;
return false ;
}
case V_413 :
break;
case V_414 : {
T_1 V_415 = F_15 ( V_294 -> V_416 . V_415 ) ;
T_1 V_138 = F_15 ( V_294 -> V_416 . V_138 ) ;
V_3 -> V_183 =
F_177 ( V_3 -> V_177 -> V_417 , V_138 ) ;
F_66 ( V_3 , V_285 ,
L_68 ,
V_138 , F_178 ( V_415 ) ) ;
break;
}
case V_418 :
break;
case V_419 : {
struct V_1 * V_339 = F_179 ( V_9 , V_281 ) ;
if ( ! V_339 ) {
F_43 ( V_3 , L_69 ) ;
break;
}
F_176 ( & V_8 -> V_54 , V_339 ) ;
F_133 ( & V_8 -> V_51 ) ;
break;
}
case V_420 :
F_165 ( V_3 , V_9 ) ;
break;
case V_421 :
F_166 ( V_3 , V_9 ) ;
break;
case V_422 :
default:
F_43 ( V_3 , L_70 ,
V_294 -> V_198 . V_371 ) ;
F_44 ( V_3 , V_59 , NULL , L_66 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
return true ;
}
void F_180 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
F_175 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
static void V_103 ( unsigned long V_423 )
{
struct V_7 * V_8 = (struct V_7 * ) V_423 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_295 V_296 = {} ;
struct V_60 V_424 ;
struct V_60 V_425 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
int V_426 ;
F_129 ( & V_424 ) ;
F_129 ( & V_425 ) ;
F_181 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_145 ( & V_8 -> V_53 , & V_424 ) ;
F_182 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_181 ( & V_8 -> V_54 . V_41 , V_38 ) ;
F_145 ( & V_8 -> V_54 , & V_425 ) ;
F_182 ( & V_8 -> V_54 . V_41 , V_38 ) ;
while ( F_183 ( & V_8 -> V_310 , & V_296 ) )
F_138 ( V_8 , & V_296 ) ;
while ( ( V_9 = F_119 ( & V_425 ) ) ) {
F_153 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
V_426 = F_184 ( & V_8 -> V_102 ) ;
while ( V_426 ) {
if ( F_128 ( V_8 ) )
break;
V_426 -- ;
F_185 ( & V_8 -> V_102 ) ;
}
while ( ( V_9 = F_119 ( & V_424 ) ) ) {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_149 ( V_3 , V_9 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
F_10 ( V_9 ) ;
}
F_28 ( V_8 ) ;
}
