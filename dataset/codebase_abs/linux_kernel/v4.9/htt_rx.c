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
F_38 ( & V_8 -> V_52 ) ;
F_38 ( & V_8 -> V_53 ) ;
F_5 ( V_8 ) ;
F_39 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_54 ) ;
F_39 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
V_8 -> V_13 . V_30 . V_31 ,
V_8 -> V_13 . V_30 . V_4 ) ;
F_40 ( V_8 -> V_13 . V_20 ) ;
}
static inline struct V_1 * F_41 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_27 ;
struct V_1 * V_55 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_13 . V_21 == 0 ) {
F_42 ( V_3 , L_1 ) ;
return NULL ;
}
V_27 = V_8 -> V_13 . V_56 . V_57 ;
V_55 = V_8 -> V_13 . V_20 [ V_27 ] ;
V_8 -> V_13 . V_20 [ V_27 ] = NULL ;
V_8 -> V_13 . V_39 [ V_27 ] = 0 ;
V_27 ++ ;
V_27 &= V_8 -> V_13 . V_40 ;
V_8 -> V_13 . V_56 . V_57 = V_27 ;
V_8 -> V_13 . V_21 -- ;
F_7 ( V_8 -> V_3 -> V_15 ,
F_11 ( V_55 ) -> V_4 ,
V_55 -> V_16 + F_8 ( V_55 ) ,
V_17 ) ;
F_43 ( V_3 , V_58 , NULL , L_2 ,
V_55 -> V_36 , V_55 -> V_16 + F_8 ( V_55 ) ) ;
return V_55 ;
}
static int F_44 ( struct V_7 * V_8 ,
struct V_59 * V_60 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
int V_61 , V_62 = 0 ;
struct V_1 * V_55 ;
struct V_24 * V_25 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
for (; ; ) {
int V_63 , V_64 , V_65 ;
V_55 = F_41 ( V_8 ) ;
if ( ! V_55 ) {
F_45 ( V_60 ) ;
return - V_66 ;
}
F_46 ( V_60 , V_55 ) ;
V_25 = (struct V_24 * ) V_55 -> V_36 ;
F_47 ( V_55 , F_48 ( struct V_24 , V_67 ) ) ;
F_18 ( V_55 , F_48 ( struct V_24 , V_67 ) ) ;
if ( ! ( F_15 ( V_25 -> V_37 . V_38 )
& V_68 ) ) {
F_45 ( V_60 ) ;
return - V_69 ;
}
V_64 = ! ! ( F_15 ( V_25 -> V_37 . V_38 )
& ( V_70 |
V_71 ) ) ;
V_61 = F_49 ( F_15 ( V_25 -> V_72 . V_73 . V_74 ) ,
V_75 ) ;
V_65 = V_25 -> V_76 . V_77 ;
if ( V_64 )
V_61 = 0 ;
F_50 ( V_55 , 0 ) ;
F_47 ( V_55 , F_30 ( V_61 , V_78 ) ) ;
V_61 -= V_55 -> V_16 ;
while ( V_65 -- ) {
V_55 = F_41 ( V_8 ) ;
if ( ! V_55 ) {
F_45 ( V_60 ) ;
return - V_66 ;
}
F_46 ( V_60 , V_55 ) ;
F_50 ( V_55 , 0 ) ;
F_47 ( V_55 , F_30 ( V_61 , V_32 ) ) ;
V_61 -= V_55 -> V_16 ;
V_62 = 1 ;
}
V_63 = F_15 ( V_25 -> V_79 . V_73 . V_74 ) &
V_80 ;
F_51 ( V_3 , & V_25 -> V_37 ,
sizeof( * V_25 ) - sizeof( T_1 ) ) ;
if ( V_63 )
break;
}
if ( F_52 ( V_60 ) )
V_62 = - 1 ;
return V_62 ;
}
static struct V_1 * F_53 ( struct V_7 * V_8 ,
T_1 V_4 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_5 * V_6 ;
struct V_1 * V_55 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_55 = F_1 ( V_3 , V_4 ) ;
if ( ! V_55 )
return NULL ;
V_6 = F_11 ( V_55 ) ;
F_9 ( & V_6 -> V_18 ) ;
V_8 -> V_13 . V_21 -- ;
F_7 ( V_8 -> V_3 -> V_15 , V_6 -> V_4 ,
V_55 -> V_16 + F_8 ( V_55 ) ,
V_17 ) ;
F_43 ( V_3 , V_58 , NULL , L_2 ,
V_55 -> V_36 , V_55 -> V_16 + F_8 ( V_55 ) ) ;
return V_55 ;
}
static int F_54 ( struct V_7 * V_8 ,
struct V_81 * V_82 ,
struct V_59 * V_83 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_84 * V_85 = V_82 -> V_86 ;
struct V_24 * V_87 ;
struct V_1 * V_55 ;
int V_88 ;
bool V_89 ;
T_1 V_4 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_88 = F_55 ( V_82 -> V_88 ) ;
V_89 = ! ! ( V_82 -> V_90 & V_91 ) ;
while ( V_88 -- ) {
V_4 = F_15 ( V_85 -> V_92 ) ;
V_55 = F_53 ( V_8 , V_4 ) ;
if ( ! V_55 ) {
F_45 ( V_83 ) ;
return - V_66 ;
}
F_46 ( V_83 , V_55 ) ;
if ( ! V_89 ) {
V_87 = ( void * ) V_55 -> V_36 ;
F_51 ( V_3 , V_87 , sizeof( * V_87 ) ) ;
F_47 ( V_55 , sizeof( * V_87 ) ) ;
F_18 ( V_55 , sizeof( * V_87 ) ) ;
F_47 ( V_55 , F_55 ( V_85 -> V_61 ) ) ;
if ( ! ( F_15 ( V_87 -> V_37 . V_38 ) &
V_68 ) ) {
F_42 ( V_8 -> V_3 , L_3 ) ;
return - V_69 ;
}
}
V_85 ++ ;
}
return 0 ;
}
int F_56 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_2 V_4 ;
void * V_31 ;
T_3 V_19 ;
struct V_93 * V_94 = & V_8 -> V_13 . V_46 ;
V_8 -> V_95 = false ;
V_8 -> V_13 . V_19 = V_29 ;
V_8 -> V_13 . V_40 = V_8 -> V_13 . V_19 - 1 ;
V_8 -> V_13 . V_44 = V_28 ;
if ( ! F_57 ( V_8 -> V_13 . V_19 ) ) {
F_42 ( V_3 , L_4 ) ;
return - V_96 ;
}
V_8 -> V_13 . V_20 =
F_58 ( V_8 -> V_13 . V_19 * sizeof( struct V_1 * ) ,
V_97 ) ;
if ( ! V_8 -> V_13 . V_20 )
goto V_98;
V_19 = V_8 -> V_13 . V_19 * sizeof( V_8 -> V_13 . V_39 ) ;
V_31 = F_59 ( V_8 -> V_3 -> V_15 , V_19 , & V_4 , V_97 ) ;
if ( ! V_31 )
goto V_99;
V_8 -> V_13 . V_39 = V_31 ;
V_8 -> V_13 . V_54 = V_4 ;
V_31 = F_59 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
& V_4 , V_97 ) ;
if ( ! V_31 )
goto V_100;
V_8 -> V_13 . V_30 . V_31 = V_31 ;
V_8 -> V_13 . V_30 . V_4 = V_4 ;
V_8 -> V_13 . V_56 . V_57 = V_8 -> V_13 . V_40 ;
* V_8 -> V_13 . V_30 . V_31 = 0 ;
F_60 ( V_94 , F_34 , ( unsigned long ) V_8 ) ;
F_61 ( & V_8 -> V_13 . V_41 ) ;
V_8 -> V_13 . V_21 = 0 ;
V_8 -> V_13 . V_56 . V_57 = 0 ;
F_12 ( V_8 -> V_13 . V_22 ) ;
F_62 ( & V_8 -> V_51 ) ;
F_62 ( & V_8 -> V_52 ) ;
F_62 ( & V_8 -> V_53 ) ;
F_63 ( & V_8 -> V_101 , 0 ) ;
F_64 ( V_3 , V_102 , L_5 ,
V_8 -> V_13 . V_19 , V_8 -> V_13 . V_44 ) ;
return 0 ;
V_100:
F_39 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_54 ) ;
V_99:
F_40 ( V_8 -> V_13 . V_20 ) ;
V_98:
return - V_34 ;
}
static int F_65 ( struct V_2 * V_3 ,
enum V_103 type )
{
switch ( type ) {
case V_104 :
return 0 ;
case V_105 :
case V_106 :
return V_107 ;
case V_108 :
case V_109 :
return V_110 ;
case V_111 :
return V_112 ;
case V_113 :
case V_114 :
break;
}
F_42 ( V_3 , L_6 , type ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 ,
enum V_103 type )
{
switch ( type ) {
case V_104 :
return 0 ;
case V_105 :
case V_106 :
return V_115 ;
case V_108 :
case V_109 :
return V_116 ;
case V_111 :
return V_117 ;
case V_113 :
case V_114 :
break;
}
F_42 ( V_3 , L_6 , type ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
struct V_120 * V_121 ;
T_4 V_122 , V_123 , V_124 , V_125 , V_126 , V_127 ;
T_4 V_128 = 0 ;
T_4 V_129 ;
T_1 V_130 , V_131 , V_132 ;
V_130 = F_15 ( V_87 -> V_133 . V_130 ) ;
V_131 = F_15 ( V_87 -> V_133 . V_131 ) ;
V_132 = F_15 ( V_87 -> V_133 . V_132 ) ;
V_128 = F_49 ( V_130 , V_134 ) ;
switch ( V_128 ) {
case V_135 :
if ( ! V_119 -> V_136 )
return;
V_122 = V_130 & V_137 ;
V_123 = F_49 ( V_130 , V_138 ) ;
V_123 &= ~ V_139 ;
V_121 = & V_3 -> V_140 . V_141 [ V_119 -> V_142 ] ;
V_119 -> V_143 = F_68 ( V_121 , V_123 , V_122 ) ;
break;
case V_144 :
case V_145 :
V_126 = V_131 & 0x1F ;
V_127 = V_126 >> 3 ;
V_124 = ( V_131 >> 7 ) & 1 ;
V_125 = ( V_132 >> 7 ) & 1 ;
V_119 -> V_143 = V_126 ;
V_119 -> V_146 |= V_147 ;
if ( V_125 )
V_119 -> V_146 |= V_148 ;
if ( V_124 )
V_119 -> V_146 |= V_149 ;
break;
case V_150 :
case V_151 :
V_124 = V_131 & 3 ;
V_125 = V_132 & 1 ;
V_129 = ( V_131 >> 4 ) & 0x3F ;
if ( F_69 ( V_129 ) ) {
V_126 = ( V_132 >> 4 ) & 0x0F ;
V_127 = ( ( V_131 >> 10 ) & 0x07 ) + 1 ;
} else {
V_126 = 0 ;
V_127 = 1 ;
}
if ( V_126 > 0x09 ) {
F_42 ( V_3 , L_7 , V_126 ) ;
F_42 ( V_3 , L_8 ,
F_15 ( V_87 -> V_37 . V_38 ) ,
F_15 ( V_87 -> V_152 . V_74 ) ,
F_15 ( V_87 -> V_152 . V_130 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_87 -> V_133 . V_74 ,
F_15 ( V_87 -> V_133 . V_130 ) ,
F_15 ( V_87 -> V_133 . V_131 ) ,
F_15 ( V_87 -> V_133 . V_132 ) ,
F_15 ( V_87 -> V_133 . V_153 ) ) ;
F_42 ( V_3 , L_9 ,
F_15 ( V_87 -> V_79 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_154 . V_74 ) ) ;
F_43 ( V_3 , V_58 , NULL ,
L_10 ,
V_87 -> V_67 , 50 ) ;
}
V_119 -> V_143 = V_126 ;
V_119 -> V_155 = V_127 ;
if ( V_125 )
V_119 -> V_146 |= V_148 ;
switch ( V_124 ) {
case 0 :
break;
case 1 :
V_119 -> V_146 |= V_149 ;
break;
case 2 :
V_119 -> V_156 |= V_157 ;
}
V_119 -> V_146 |= V_158 ;
break;
default:
break;
}
}
static struct V_159 *
F_70 ( struct V_2 * V_3 , struct V_24 * V_87 )
{
struct V_160 * V_161 ;
struct V_162 * V_163 ;
struct V_164 V_165 ;
T_5 V_166 ;
F_27 ( & V_3 -> V_167 ) ;
if ( ! V_87 )
return NULL ;
if ( V_87 -> V_37 . V_38 &
F_20 ( V_168 ) )
return NULL ;
if ( ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_169 ) ) )
return NULL ;
V_166 = F_49 ( F_15 ( V_87 -> V_152 . V_74 ) ,
V_170 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 )
return NULL ;
V_163 = F_72 ( V_3 , V_161 -> V_171 ) ;
if ( F_4 ( ! V_163 ) )
return NULL ;
if ( F_73 ( V_163 -> V_172 , & V_165 ) )
return NULL ;
return V_165 . V_173 ;
}
static struct V_159 *
F_74 ( struct V_2 * V_3 , T_1 V_171 )
{
struct V_162 * V_163 ;
struct V_164 V_165 ;
F_27 ( & V_3 -> V_167 ) ;
F_75 (arvif, &ar->arvifs, list) {
if ( V_163 -> V_171 == V_171 &&
F_73 ( V_163 -> V_172 , & V_165 ) == 0 )
return V_165 . V_173 ;
}
return NULL ;
}
static void
F_76 ( struct V_174 * V_175 ,
struct V_176 * V_177 ,
void * V_36 )
{
struct V_164 * V_165 = V_36 ;
* V_165 = V_177 -> V_165 ;
}
static struct V_159 *
F_77 ( struct V_2 * V_3 )
{
struct V_164 V_165 = {} ;
F_78 ( V_3 -> V_175 ,
F_76 ,
& V_165 ) ;
return V_165 . V_173 ;
}
static bool F_79 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 ,
T_1 V_171 )
{
struct V_159 * V_178 ;
F_29 ( & V_3 -> V_167 ) ;
V_178 = V_3 -> V_179 ;
if ( ! V_178 )
V_178 = V_3 -> V_180 ;
if ( ! V_178 )
V_178 = F_70 ( V_3 , V_87 ) ;
if ( ! V_178 )
V_178 = F_74 ( V_3 , V_171 ) ;
if ( ! V_178 )
V_178 = F_77 ( V_3 ) ;
if ( ! V_178 )
V_178 = V_3 -> V_181 ;
F_33 ( & V_3 -> V_167 ) ;
if ( ! V_178 )
return false ;
V_119 -> V_142 = V_178 -> V_142 ;
V_119 -> V_136 = V_178 -> V_182 ;
return true ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
V_119 -> signal = V_183 +
V_87 -> V_133 . V_184 ;
V_119 -> V_146 &= ~ V_185 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
V_119 -> V_186 = F_15 ( V_87 -> V_187 . V_73 . V_188 ) ;
V_119 -> V_146 |= V_189 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 ,
T_1 V_171 )
{
struct V_1 * V_190 ;
struct V_24 * V_87 ;
bool V_191 ;
bool V_192 ;
if ( F_52 ( V_60 ) )
return;
V_190 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_190 -> V_36 - sizeof( * V_87 ) ;
V_191 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_193 ) ) ;
V_192 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_194 ) ) ;
if ( V_191 ) {
V_119 -> V_136 = 0 ;
V_119 -> V_143 = 0 ;
V_119 -> V_155 = 0 ;
V_119 -> V_156 &= ~ V_157 ;
V_119 -> V_146 &= ~ ( V_147 |
V_158 |
V_148 |
V_149 |
V_189 ) ;
V_119 -> V_146 |= V_185 ;
F_80 ( V_3 , V_119 , V_87 ) ;
F_79 ( V_3 , V_119 , V_87 , V_171 ) ;
F_67 ( V_3 , V_119 , V_87 ) ;
}
if ( V_192 )
F_81 ( V_3 , V_119 , V_87 ) ;
}
static char * F_84 ( struct V_195 * V_196 , char * V_197 , T_3 V_19 )
{
T_4 * V_198 ;
int V_199 ;
if ( ! F_85 ( V_196 -> V_200 ) )
return L_11 ;
V_198 = F_86 ( V_196 ) ;
V_199 = * V_198 & V_201 ;
if ( V_199 < 8 )
snprintf ( V_197 , V_19 , L_12 , V_199 , V_202 [ V_199 ] ) ;
else
snprintf ( V_197 , V_19 , L_13 , V_199 ) ;
return V_197 ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_118 * V_203 ,
struct V_1 * V_9 )
{
struct V_118 * V_119 ;
struct V_195 * V_196 = (struct V_195 * ) V_9 -> V_36 ;
char V_199 [ 32 ] ;
V_119 = F_88 ( V_9 ) ;
* V_119 = * V_203 ;
F_64 ( V_3 , V_204 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_89 ( V_196 ) ,
F_84 ( V_196 , V_199 , sizeof( V_199 ) ) ,
F_90 ( F_91 ( V_196 ) ) ?
L_15 : L_16 ,
( F_55 ( V_196 -> V_205 ) & V_206 ) >> 4 ,
( V_119 -> V_146 & ( V_147 | V_158 ) ) == 0 ?
L_17 : L_11 ,
V_119 -> V_146 & V_147 ? L_18 : L_11 ,
V_119 -> V_146 & V_158 ? L_19 : L_11 ,
V_119 -> V_146 & V_149 ? L_20 : L_11 ,
V_119 -> V_156 & V_157 ? L_21 : L_11 ,
V_119 -> V_146 & V_148 ? L_22 : L_11 ,
V_119 -> V_143 ,
V_119 -> V_155 ,
V_119 -> V_136 ,
V_119 -> V_142 , V_119 -> V_146 ,
! ! ( V_119 -> V_146 & V_207 ) ,
! ! ( V_119 -> V_146 & V_208 ) ,
! ! ( V_119 -> V_146 & V_209 ) ) ;
F_43 ( V_3 , V_58 , NULL , L_23 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_92 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_93 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_94 ( V_3 -> V_175 , NULL , V_9 , & V_3 -> V_210 ) ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_195 * V_196 )
{
int V_16 = F_96 ( V_196 -> V_200 ) ;
if ( ! F_97 ( V_211 ,
V_3 -> V_212 -> V_213 . V_214 ) )
V_16 = F_98 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_99 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
enum V_103 V_215 ,
bool V_216 )
{
struct V_195 * V_196 ;
struct V_24 * V_87 ;
T_3 V_217 ;
T_3 V_218 ;
bool V_219 ;
bool V_220 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_219 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_169 ) ) ;
V_220 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
if ( F_22 ( F_4 ( ! V_219 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_219 && V_220 ) ) ) )
return;
F_50 ( V_55 , V_55 -> V_16 - V_221 ) ;
if ( ! V_216 )
return;
V_196 = ( void * ) V_55 -> V_36 ;
if ( V_119 -> V_146 & V_222 )
F_50 ( V_55 , V_55 -> V_16 -
F_66 ( V_3 , V_215 ) ) ;
if ( ( V_119 -> V_146 & V_223 ) &&
! F_100 ( V_196 -> V_200 ) &&
V_215 == V_109 )
F_50 ( V_55 , V_55 -> V_16 - 8 ) ;
if ( V_119 -> V_146 & V_222 ) {
V_217 = F_96 ( V_196 -> V_200 ) ;
V_218 = F_65 ( V_3 , V_215 ) ;
memmove ( ( void * ) V_55 -> V_36 + V_218 ,
( void * ) V_55 -> V_36 , V_217 ) ;
F_18 ( V_55 , V_218 ) ;
}
}
static void F_101 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_224 [ 64 ] )
{
struct V_195 * V_196 ;
struct V_24 * V_87 ;
T_3 V_217 ;
T_4 V_225 [ V_226 ] ;
T_4 V_227 [ V_226 ] ;
int V_228 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_228 = F_102 ( & V_3 -> V_229 , V_87 ) ;
F_47 ( V_55 , V_228 ) ;
V_196 = (struct V_195 * ) ( V_55 -> V_36 + V_228 ) ;
V_217 = F_95 ( V_3 , V_196 ) ;
F_103 ( V_225 , F_91 ( V_196 ) ) ;
F_103 ( V_227 , F_89 ( V_196 ) ) ;
F_18 ( V_55 , V_217 ) ;
V_196 = (struct V_195 * ) V_224 ;
V_217 = F_96 ( V_196 -> V_200 ) ;
memcpy ( F_104 ( V_55 , V_217 ) , V_196 , V_217 ) ;
V_196 = (struct V_195 * ) V_55 -> V_36 ;
F_103 ( F_91 ( V_196 ) , V_225 ) ;
F_103 ( F_89 ( V_196 ) , V_227 ) ;
}
static void * F_105 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
enum V_103 V_215 )
{
struct V_195 * V_196 ;
struct V_24 * V_87 ;
T_3 V_217 , V_218 ;
void * V_230 ;
bool V_219 , V_220 , V_231 ;
int V_232 = V_3 -> V_229 . V_233 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_196 = ( void * ) V_87 -> V_234 ;
V_219 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_169 ) ) ;
V_220 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
V_231 = ! ( V_219 && V_220 ) ;
V_230 = V_196 ;
if ( V_219 ) {
V_217 = F_96 ( V_196 -> V_200 ) ;
V_218 = F_65 ( V_3 , V_215 ) ;
V_230 += F_98 ( V_217 , V_232 ) +
F_98 ( V_218 , V_232 ) ;
}
if ( V_231 )
V_230 += sizeof( struct V_235 ) ;
return V_230 ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_224 [ 64 ] ,
enum V_103 V_215 )
{
struct V_195 * V_196 ;
struct V_236 * V_237 ;
T_3 V_217 ;
void * V_230 ;
T_4 V_225 [ V_226 ] ;
T_4 V_227 [ V_226 ] ;
int V_228 ;
struct V_24 * V_87 ;
V_230 = F_105 ( V_3 , V_55 , V_215 ) ;
if ( F_4 ( ! V_230 ) )
return;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_228 = F_102 ( & V_3 -> V_229 , V_87 ) ;
F_47 ( V_55 , V_228 ) ;
F_18 ( V_55 , V_228 ) ;
V_237 = (struct V_236 * ) V_55 -> V_36 ;
F_103 ( V_225 , V_237 -> V_238 ) ;
F_103 ( V_227 , V_237 -> V_239 ) ;
F_18 ( V_55 , sizeof( struct V_236 ) ) ;
memcpy ( F_104 ( V_55 , sizeof( struct V_240 ) ) , V_230 ,
sizeof( struct V_240 ) ) ;
V_196 = (struct V_195 * ) V_224 ;
V_217 = F_96 ( V_196 -> V_200 ) ;
memcpy ( F_104 ( V_55 , V_217 ) , V_196 , V_217 ) ;
V_196 = (struct V_195 * ) V_55 -> V_36 ;
F_103 ( F_91 ( V_196 ) , V_225 ) ;
F_103 ( F_89 ( V_196 ) , V_227 ) ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_224 [ 64 ] )
{
struct V_195 * V_196 ;
T_3 V_217 ;
int V_228 ;
struct V_24 * V_87 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_228 = F_102 ( & V_3 -> V_229 , V_87 ) ;
F_47 ( V_55 , V_228 ) ;
F_18 ( V_55 , sizeof( struct V_235 ) + V_228 ) ;
V_196 = (struct V_195 * ) V_224 ;
V_217 = F_96 ( V_196 -> V_200 ) ;
memcpy ( F_104 ( V_55 , V_217 ) , V_196 , V_217 ) ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
T_4 V_224 [ 64 ] ,
enum V_103 V_215 ,
bool V_216 )
{
struct V_24 * V_87 ;
enum V_241 V_242 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_242 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_243 ) ;
switch ( V_242 ) {
case V_244 :
F_99 ( V_3 , V_55 , V_119 , V_215 ,
V_216 ) ;
break;
case V_245 :
F_101 ( V_3 , V_55 , V_119 , V_224 ) ;
break;
case V_246 :
F_106 ( V_3 , V_55 , V_119 , V_224 , V_215 ) ;
break;
case V_247 :
F_107 ( V_3 , V_55 , V_119 , V_224 ) ;
break;
}
}
static int F_109 ( struct V_1 * V_9 )
{
struct V_24 * V_87 ;
T_1 V_38 , V_90 ;
bool V_248 , V_249 ;
bool V_250 , V_251 ;
bool V_252 , V_253 ;
V_87 = ( void * ) V_9 -> V_36 - sizeof( * V_87 ) ;
V_38 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_90 = F_15 ( V_87 -> V_72 . V_73 . V_130 ) ;
V_248 = ! ! ( V_90 & V_254 ) ;
V_249 = ! ! ( V_90 & V_255 ) ;
V_250 = ! ! ( V_90 & V_256 ) ;
V_251 = ! ! ( V_90 & V_257 ) ;
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
static void F_110 ( struct V_1 * V_55 )
{
V_55 -> V_262 = F_109 ( V_55 ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_190 ;
struct V_1 * V_263 ;
struct V_1 * V_55 ;
struct V_24 * V_87 ;
struct V_195 * V_196 ;
enum V_103 V_215 ;
T_4 V_224 [ 64 ] ;
T_4 * V_264 ;
T_3 V_217 ;
bool V_265 ;
bool V_266 ;
bool V_267 ;
bool V_268 ;
bool V_216 ;
bool V_269 ;
T_1 V_37 ;
if ( F_52 ( V_60 ) )
return;
V_190 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_190 -> V_36 - sizeof( * V_87 ) ;
V_269 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_270 ) ) ;
V_215 = F_49 ( F_15 ( V_87 -> V_152 . V_74 ) ,
V_271 ) ;
V_196 = ( void * ) V_87 -> V_234 ;
V_217 = F_96 ( V_196 -> V_200 ) ;
memcpy ( V_224 , V_196 , V_217 ) ;
V_196 = ( void * ) V_224 ;
V_264 = F_86 ( V_196 ) ;
V_264 [ 0 ] &= ~ V_272 ;
V_263 = F_112 ( V_60 ) ;
V_87 = ( void * ) V_263 -> V_36 - sizeof( * V_87 ) ;
V_37 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_265 = ! ! ( V_37 & V_273 ) ;
V_266 = ! ! ( V_37 & V_274 ) ;
V_267 = ! ! ( V_37 & V_275 ) ;
V_268 = ! ! ( V_37 & V_168 ) ;
V_216 = ( V_215 != V_104 &&
! V_265 &&
! V_266 &&
! V_268 ) ;
V_119 -> V_146 &= ~ ( V_207 |
V_208 |
V_276 |
V_222 |
V_277 |
V_223 ) ;
if ( V_265 )
V_119 -> V_146 |= V_207 ;
if ( V_267 )
V_119 -> V_146 |= V_208 ;
if ( V_269 )
V_119 -> V_146 |= V_277 ;
if ( V_216 ) {
V_119 -> V_146 |= V_276 ;
if ( F_113 ( ! V_269 ) )
V_119 -> V_146 |= V_222 |
V_223 ;
}
F_114 (amsdu, msdu) {
F_110 ( V_55 ) ;
F_108 ( V_3 , V_55 , V_119 , V_224 , V_215 ,
V_216 ) ;
if ( ! V_216 )
continue;
if ( V_269 )
continue;
V_196 = ( void * ) V_55 -> V_36 ;
V_196 -> V_200 &= ~ F_115 ( V_278 ) ;
}
}
static void F_116 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_55 ;
while ( ( V_55 = F_117 ( V_60 ) ) ) {
if ( F_52 ( V_60 ) )
V_119 -> V_146 &= ~ V_209 ;
else
V_119 -> V_146 |= V_209 ;
F_87 ( V_3 , V_119 , V_55 ) ;
}
}
static int F_118 ( struct V_59 * V_60 )
{
struct V_1 * V_9 , * V_190 ;
int V_279 ;
int V_280 = 0 ;
V_190 = F_117 ( V_60 ) ;
F_114 (amsdu, skb)
V_280 += V_9 -> V_16 ;
V_279 = V_280 - F_8 ( V_190 ) ;
if ( ( V_279 > 0 ) &&
( F_119 ( V_190 , 0 , V_279 , V_281 ) < 0 ) ) {
F_120 ( V_60 , V_190 ) ;
return - 1 ;
}
while ( ( V_9 = F_117 ( V_60 ) ) ) {
F_121 ( V_9 , F_47 ( V_190 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_120 ( V_60 , V_190 ) ;
return 0 ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
bool V_282 )
{
struct V_1 * V_190 ;
struct V_24 * V_87 ;
enum V_241 V_242 ;
V_190 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_190 -> V_36 - sizeof( * V_87 ) ;
V_242 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_243 ) ;
if ( ! V_282 )
return;
if ( V_242 != V_244 ||
F_123 ( V_60 ) != 1 + V_87 -> V_76 . V_77 ) {
F_45 ( V_60 ) ;
return;
}
F_118 ( V_60 ) ;
}
static bool F_124 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_203 )
{
if ( ! V_203 -> V_136 ) {
F_42 ( V_3 , L_24 ) ;
return false ;
}
if ( F_97 ( V_283 , & V_3 -> V_284 ) ) {
F_64 ( V_3 , V_285 , L_25 ) ;
return false ;
}
return true ;
}
static void F_125 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_203 )
{
if ( F_52 ( V_60 ) )
return;
if ( F_124 ( V_3 , V_60 , V_203 ) )
return;
F_45 ( V_60 ) ;
}
static int F_126 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_118 * V_203 = & V_8 -> V_203 ;
struct V_59 V_60 ;
int V_26 , V_286 ;
F_127 ( & V_60 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_95 ) {
F_33 ( & V_8 -> V_13 . V_41 ) ;
return - V_69 ;
}
V_26 = F_44 ( V_8 , & V_60 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_26 < 0 ) {
F_42 ( V_3 , L_26 , V_26 ) ;
F_45 ( & V_60 ) ;
V_8 -> V_95 = true ;
return V_26 ;
}
V_286 = F_123 ( & V_60 ) ;
F_82 ( V_3 , & V_60 , V_203 , 0xffff ) ;
F_122 ( V_3 , & V_60 , V_26 > 0 ) ;
F_125 ( V_3 , & V_60 , V_203 ) ;
F_111 ( V_3 , & V_60 , V_203 ) ;
F_116 ( V_3 , & V_60 , V_203 ) ;
return V_286 ;
}
static void F_128 ( struct V_7 * V_8 ,
struct V_287 * V_288 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_289 * V_290 ;
int V_291 ;
int V_12 , V_292 = 0 ;
V_291 = F_49 ( F_15 ( V_288 -> V_196 . V_130 ) ,
V_293 ) ;
V_290 = F_129 ( V_288 ) ;
F_43 ( V_3 , V_58 , NULL , L_27 ,
V_288 , sizeof( * V_288 ) +
( sizeof( struct V_289 ) *
V_291 ) ) ;
for ( V_12 = 0 ; V_12 < V_291 ; V_12 ++ )
V_292 += V_290 [ V_12 ] . V_292 ;
F_130 ( V_292 , & V_8 -> V_101 ) ;
}
static void F_131 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
struct V_296 V_297 = {} ;
int V_119 = F_49 ( V_295 -> V_298 . V_38 , V_299 ) ;
T_6 V_300 ;
int V_12 ;
switch ( V_119 ) {
case V_301 :
V_297 . V_119 = V_302 ;
break;
case V_303 :
V_297 . V_119 = V_304 ;
break;
case V_305 :
case V_306 :
case V_307 :
V_297 . V_119 = V_308 ;
break;
default:
F_42 ( V_3 , L_28 , V_119 ) ;
V_297 . V_119 = V_308 ;
break;
}
F_64 ( V_3 , V_285 , L_29 ,
V_295 -> V_298 . V_286 ) ;
for ( V_12 = 0 ; V_12 < V_295 -> V_298 . V_286 ; V_12 ++ ) {
V_300 = V_295 -> V_298 . V_309 [ V_12 ] ;
V_297 . V_300 = F_55 ( V_300 ) ;
if ( ! F_132 ( & V_8 -> V_310 , V_297 ) ) {
F_42 ( V_3 , L_30 ,
V_297 . V_300 , V_297 . V_119 ) ;
F_133 ( V_8 , & V_297 ) ;
}
}
}
static void F_134 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_311 * V_82 = & V_295 -> V_312 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_74 , V_199 , V_166 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_199 = F_49 ( V_74 , V_313 ) ;
V_166 = F_49 ( V_74 , V_314 ) ;
F_64 ( V_3 , V_285 ,
L_31 ,
V_199 , V_166 , V_82 -> V_315 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_42 ( V_3 , L_32 ,
V_166 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_72 ( V_3 , V_161 -> V_171 ) ;
if ( ! V_163 ) {
F_42 ( V_3 , L_33 ,
V_161 -> V_171 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
F_64 ( V_3 , V_285 ,
L_34 ,
V_161 -> V_316 , V_199 , V_82 -> V_315 ) ;
F_135 ( V_163 -> V_172 , V_161 -> V_316 , V_199 ) ;
F_33 ( & V_3 -> V_167 ) ;
}
static void F_136 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_317 * V_82 = & V_295 -> V_318 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_74 , V_199 , V_166 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_199 = F_49 ( V_74 , V_313 ) ;
V_166 = F_49 ( V_74 , V_314 ) ;
F_64 ( V_3 , V_285 ,
L_35 ,
V_199 , V_166 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_42 ( V_3 , L_32 ,
V_166 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_72 ( V_3 , V_161 -> V_171 ) ;
if ( ! V_163 ) {
F_42 ( V_3 , L_33 ,
V_161 -> V_171 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
F_64 ( V_3 , V_285 ,
L_36 ,
V_161 -> V_316 , V_199 ) ;
F_137 ( V_163 -> V_172 , V_161 -> V_316 , V_199 ) ;
F_33 ( & V_3 -> V_167 ) ;
}
static int F_138 ( struct V_59 * V_83 ,
struct V_59 * V_60 )
{
struct V_1 * V_55 ;
struct V_24 * V_87 ;
if ( F_52 ( V_83 ) )
return - V_319 ;
if ( F_139 ( ! F_52 ( V_60 ) ) )
return - V_96 ;
while ( ( V_55 = F_117 ( V_83 ) ) ) {
F_46 ( V_60 , V_55 ) ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
if ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) )
break;
}
V_55 = F_112 ( V_60 ) ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
if ( ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ) {
F_140 ( V_60 , V_83 ) ;
return - V_320 ;
}
return 0 ;
}
static void F_141 ( struct V_118 * V_119 ,
struct V_1 * V_9 )
{
struct V_195 * V_196 = (struct V_195 * ) V_9 -> V_36 ;
if ( ! F_142 ( V_196 -> V_200 ) )
return;
V_196 -> V_200 &= ~ F_115 ( V_278 ) ;
V_119 -> V_146 |= V_276 |
V_222 |
V_223 ;
}
static int F_143 ( struct V_2 * V_3 ,
struct V_59 * V_83 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_118 * V_119 = & V_8 -> V_203 ;
struct V_321 * V_288 ;
struct V_1 * V_55 ;
T_3 V_322 ;
int V_323 = 0 ;
while ( ( V_55 = F_117 ( V_83 ) ) ) {
V_288 = ( void * ) V_55 -> V_36 ;
F_47 ( V_55 , sizeof( * V_288 ) ) ;
F_18 ( V_55 , sizeof( * V_288 ) ) ;
if ( F_8 ( V_55 ) < F_55 ( V_288 -> V_61 ) ) {
F_42 ( V_3 , L_37 ) ;
F_10 ( V_55 ) ;
continue;
}
F_47 ( V_55 , F_55 ( V_288 -> V_61 ) ) ;
V_322 = 4 - ( ( unsigned long ) V_55 -> V_36 & 3 ) ;
F_47 ( V_55 , V_322 ) ;
memmove ( V_55 -> V_36 + V_322 , V_55 -> V_36 , V_55 -> V_16 ) ;
F_18 ( V_55 , V_322 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_146 |= V_185 ;
F_141 ( V_119 , V_55 ) ;
F_79 ( V_3 , V_119 , NULL , V_288 -> V_171 ) ;
F_87 ( V_3 , V_119 , V_55 ) ;
V_323 ++ ;
}
return V_323 ;
}
static int F_144 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = ( void * ) V_9 -> V_36 ;
struct V_118 * V_119 = & V_8 -> V_203 ;
struct V_59 V_83 ;
struct V_59 V_60 ;
T_5 V_166 ;
T_5 V_88 ;
T_4 V_171 ;
T_4 V_199 ;
bool V_324 ;
bool V_325 ;
int V_26 , V_286 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_95 )
return - V_69 ;
F_18 ( V_9 , sizeof( V_295 -> V_196 ) ) ;
F_18 ( V_9 , sizeof( V_295 -> V_326 ) ) ;
V_166 = F_55 ( V_295 -> V_326 . V_166 ) ;
V_88 = F_55 ( V_295 -> V_326 . V_88 ) ;
V_171 = V_295 -> V_326 . V_171 ;
V_199 = F_145 ( V_295 -> V_326 . V_90 , V_327 ) ;
V_324 = ! ! ( V_295 -> V_326 . V_90 &
V_91 ) ;
V_325 = ! ! ( V_295 -> V_326 . V_90 & V_328 ) ;
F_64 ( V_3 , V_285 ,
L_38 ,
V_171 , V_166 , V_199 , V_324 , V_325 , V_88 ) ;
if ( V_9 -> V_16 < V_88 * sizeof( * V_295 -> V_326 . V_86 ) ) {
F_42 ( V_3 , L_39 ) ;
return - V_96 ;
}
F_127 ( & V_83 ) ;
V_26 = F_54 ( V_8 , & V_295 -> V_326 , & V_83 ) ;
if ( V_26 < 0 ) {
F_42 ( V_3 , L_40 , V_26 ) ;
V_8 -> V_95 = true ;
return - V_69 ;
}
if ( V_324 )
V_286 = F_143 ( V_3 , & V_83 ) ;
while ( ! F_52 ( & V_83 ) ) {
F_127 ( & V_60 ) ;
V_26 = F_138 ( & V_83 , & V_60 ) ;
switch ( V_26 ) {
case 0 :
V_286 += F_123 ( & V_60 ) ;
F_82 ( V_3 , & V_60 , V_119 , V_171 ) ;
F_125 ( V_3 , & V_60 , V_119 ) ;
F_111 ( V_3 , & V_60 , V_119 ) ;
F_116 ( V_3 , & V_60 , V_119 ) ;
break;
case - V_320 :
default:
F_42 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_95 = true ;
F_45 ( & V_83 ) ;
return - V_69 ;
}
}
return V_286 ;
}
static void F_146 ( struct V_2 * V_3 ,
const T_7 * V_329 ,
int V_330 )
{
int V_12 ;
T_1 V_331 ;
F_64 ( V_3 , V_285 , L_42 ,
V_330 ) ;
for ( V_12 = 0 ; V_12 < V_330 ; V_12 ++ ) {
V_331 = F_147 ( V_329 [ V_12 ] ) ;
F_64 ( V_3 , V_285 , L_43 ,
V_331 ) ;
}
}
static void F_148 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_174 * V_175 = V_3 -> V_175 ;
struct V_332 * V_333 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
struct V_334 * V_335 ;
T_3 V_16 ;
T_3 V_336 ;
T_3 V_337 ;
T_3 V_338 ;
T_3 V_286 ;
const T_7 * V_329 ;
T_5 V_339 ;
T_5 V_330 ;
T_5 V_166 ;
T_4 V_199 ;
int V_26 ;
int V_12 ;
F_64 ( V_3 , V_285 , L_44 ) ;
V_16 = sizeof( V_295 -> V_196 ) + sizeof( V_295 -> V_340 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_45 ) ;
return;
}
V_339 = F_149 ( V_295 -> V_340 . V_339 ) ;
V_330 = F_149 ( V_295 -> V_340 . V_330 ) ;
V_16 += sizeof( V_295 -> V_340 . V_341 [ 0 ] ) * V_339 ;
V_16 += sizeof( V_295 -> V_340 . V_329 [ 0 ] ) * V_330 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_46 ) ;
return;
}
F_64 ( V_3 , V_285 , L_47 ,
V_339 , V_330 ,
F_149 ( V_295 -> V_340 . V_342 ) ) ;
if ( ! V_3 -> V_8 . V_343 . V_344 ) {
F_42 ( V_3 , L_48 ) ;
return;
}
if ( V_3 -> V_8 . V_343 . V_345 == V_346 ) {
F_42 ( V_3 , L_49 ) ;
return;
}
F_150 () ;
for ( V_12 = 0 ; V_12 < V_339 ; V_12 ++ ) {
V_335 = & V_295 -> V_340 . V_341 [ V_12 ] ;
V_166 = F_49 ( F_149 ( V_335 -> V_90 ) ,
V_347 ) ;
V_199 = F_49 ( F_149 ( V_335 -> V_90 ) ,
V_348 ) ;
V_337 = F_149 ( V_335 -> V_286 ) ;
V_336 = F_147 ( V_335 -> V_338 ) ;
F_64 ( V_3 , V_285 , L_50 ,
V_12 , V_166 , V_199 , V_337 , V_336 ) ;
if ( F_22 ( V_166 >= V_3 -> V_8 . V_343 . V_349 ) ||
F_22 ( V_199 >= V_3 -> V_8 . V_343 . V_350 ) ) {
F_42 ( V_3 , L_51 ,
V_166 , V_199 ) ;
continue;
}
F_29 ( & V_3 -> V_167 ) ;
V_333 = F_151 ( V_3 , V_166 , V_199 ) ;
F_33 ( & V_3 -> V_167 ) ;
if ( F_22 ( ! V_333 ) ) {
F_42 ( V_3 , L_52 ,
V_166 , V_199 ) ;
continue;
}
V_286 = 0 ;
V_338 = 0 ;
while ( V_286 < V_337 &&
V_338 < V_336 ) {
V_26 = F_152 ( V_175 , V_333 ) ;
if ( V_26 < 0 )
break;
V_286 ++ ;
V_338 += V_26 ;
}
V_335 -> V_286 = F_153 ( V_286 ) ;
V_335 -> V_338 = F_154 ( V_338 ) ;
F_155 ( V_175 , V_333 ) ;
}
F_156 () ;
V_329 = F_157 ( & V_295 -> V_340 ) ;
F_146 ( V_3 , V_329 , V_330 ) ;
V_26 = F_158 ( V_3 ,
V_295 -> V_340 . V_351 ,
V_295 -> V_340 . V_342 ,
V_295 -> V_340 . V_341 ,
V_339 ) ;
if ( F_22 ( V_26 ) ) {
F_42 ( V_3 , L_53 ,
F_147 ( V_295 -> V_340 . V_351 ) , V_26 ) ;
}
F_159 ( V_3 ) ;
}
static void F_160 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_294 * V_295 = ( void * ) V_9 -> V_36 ;
T_3 V_16 ;
int V_330 ;
F_64 ( V_3 , V_285 , L_54 ) ;
V_16 = sizeof( V_295 -> V_196 ) + sizeof( V_295 -> V_352 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_55 ) ;
return;
}
V_330 = F_149 ( V_295 -> V_352 . V_330 ) ;
V_16 += sizeof( V_295 -> V_352 . V_329 [ 0 ] ) * V_330 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_56 ) ;
return;
}
F_146 ( V_3 ,
V_295 -> V_352 . V_329 ,
V_330 ) ;
}
static void F_161 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_294 * V_295 = ( void * ) V_9 -> V_36 ;
const struct V_353 * V_335 ;
struct V_332 * V_333 ;
struct V_354 * V_355 ;
T_3 V_16 ;
T_3 V_339 ;
enum V_356 V_345 ;
bool V_357 ;
T_5 V_74 ;
T_5 V_130 ;
T_5 V_358 ;
T_5 V_166 ;
T_4 V_199 ;
int V_12 ;
F_64 ( V_3 , V_285 , L_57 ) ;
V_16 = sizeof( V_295 -> V_196 ) + sizeof( V_295 -> V_359 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_58 ) ;
return;
}
V_74 = F_149 ( V_295 -> V_359 . V_74 ) ;
V_130 = F_149 ( V_295 -> V_359 . V_130 ) ;
V_357 = ! ! ( V_74 & V_360 ) ;
V_339 = F_49 ( V_74 , V_361 ) ;
V_345 = F_49 ( V_130 , V_362 ) ;
V_358 = F_49 ( V_130 , V_361 ) ;
F_64 ( V_3 , V_285 ,
L_59 ,
V_74 , V_130 , V_357 , V_339 , V_345 , V_358 ) ;
V_16 += sizeof( V_295 -> V_359 . V_341 [ 0 ] ) * V_339 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_60 ) ;
return;
}
switch ( V_345 ) {
case V_346 :
case V_363 :
break;
default:
F_42 ( V_3 , L_61 ,
V_345 ) ;
return;
}
if ( ! V_357 )
return;
V_3 -> V_8 . V_343 . V_344 = V_357 ;
V_3 -> V_8 . V_343 . V_345 = V_345 ;
V_3 -> V_8 . V_343 . V_364 = V_358 ;
F_150 () ;
for ( V_12 = 0 ; V_12 < V_339 ; V_12 ++ ) {
V_335 = & V_295 -> V_359 . V_341 [ V_12 ] ;
V_74 = F_149 ( V_335 -> V_74 ) ;
V_166 = F_49 ( V_74 , V_365 ) ;
V_199 = F_49 ( V_74 , V_366 ) ;
if ( F_22 ( V_166 >= V_3 -> V_8 . V_343 . V_349 ) ||
F_22 ( V_199 >= V_3 -> V_8 . V_343 . V_350 ) ) {
F_42 ( V_3 , L_51 ,
V_166 , V_199 ) ;
continue;
}
F_29 ( & V_3 -> V_167 ) ;
V_333 = F_151 ( V_3 , V_166 , V_199 ) ;
F_33 ( & V_3 -> V_167 ) ;
if ( F_22 ( ! V_333 ) ) {
F_42 ( V_3 , L_52 ,
V_166 , V_199 ) ;
continue;
}
F_29 ( & V_3 -> V_8 . V_367 ) ;
V_355 = ( void * ) V_333 -> V_368 ;
V_355 -> V_364 = F_149 ( V_335 -> V_369 ) ;
F_33 ( & V_3 -> V_8 . V_367 ) ;
}
F_156 () ;
F_162 ( V_3 ) ;
}
void F_163 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
bool V_370 ;
V_370 = F_164 ( V_3 , V_9 ) ;
if ( V_370 )
F_10 ( V_9 ) ;
}
bool F_164 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
enum V_371 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_42 ( V_3 , L_62 ) ;
F_64 ( V_3 , V_285 , L_63 ,
V_295 -> V_196 . V_372 ) ;
if ( V_295 -> V_196 . V_372 >= V_3 -> V_8 . V_373 ) {
F_64 ( V_3 , V_285 , L_64 ,
V_295 -> V_196 . V_372 , V_3 -> V_8 . V_373 ) ;
return true ;
}
type = V_3 -> V_8 . V_374 [ V_295 -> V_196 . V_372 ] ;
switch ( type ) {
case V_375 : {
V_8 -> V_376 = V_295 -> V_377 . V_378 ;
V_8 -> V_379 = V_295 -> V_377 . V_380 ;
F_165 ( & V_8 -> V_381 ) ;
break;
}
case V_382 :
F_128 ( V_8 , & V_295 -> V_383 ) ;
break;
case V_384 : {
struct V_385 V_82 = {
. V_171 = V_295 -> V_386 . V_171 ,
. V_166 = F_55 ( V_295 -> V_386 . V_166 ) ,
} ;
memcpy ( V_82 . V_316 , V_295 -> V_386 . V_316 , sizeof( V_82 . V_316 ) ) ;
F_166 ( V_8 , & V_82 ) ;
break;
}
case V_387 : {
struct V_388 V_82 = {
. V_166 = F_55 ( V_295 -> V_389 . V_166 ) ,
} ;
F_167 ( V_8 , & V_82 ) ;
break;
}
case V_390 : {
struct V_296 V_297 = {} ;
int V_119 = F_15 ( V_295 -> V_391 . V_119 ) ;
V_297 . V_300 = F_15 ( V_295 -> V_391 . V_392 ) ;
switch ( V_119 ) {
case V_393 :
V_297 . V_119 = V_304 ;
break;
case V_394 :
V_297 . V_119 = V_302 ;
break;
case V_395 :
V_297 . V_119 = V_308 ;
break;
}
V_119 = F_133 ( V_8 , & V_297 ) ;
if ( ! V_119 ) {
F_29 ( & V_8 -> V_367 ) ;
F_168 ( V_8 ) ;
F_33 ( & V_8 -> V_367 ) ;
}
break;
}
case V_396 :
F_131 ( V_8 -> V_3 , V_9 ) ;
break;
case V_397 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_398 * V_82 = & V_295 -> V_399 ;
F_64 ( V_3 , V_285 ,
L_65 ,
F_55 ( V_82 -> V_166 ) ,
! ! ( V_82 -> V_38 & V_400 ) ,
F_49 ( V_82 -> V_38 , V_401 ) ) ;
F_165 ( & V_3 -> V_402 ) ;
break;
}
case V_403 : {
F_43 ( V_3 , V_58 , NULL , L_66 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_169 ( & V_8 -> V_101 ) ;
break;
}
case V_404 :
break;
case V_405 :
F_170 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_406 :
F_42 ( V_3 , L_67 ) ;
break;
case V_407 :
F_134 ( V_3 , V_295 ) ;
break;
case V_408 :
F_136 ( V_3 , V_295 ) ;
break;
case V_409 : {
F_171 ( V_3 , V_295 -> V_410 . V_411 ,
V_9 -> V_16 -
F_48 ( struct V_294 ,
V_410 . V_411 ) ) ;
break;
}
case V_412 : {
break;
}
case V_413 : {
F_46 ( & V_8 -> V_52 , V_9 ) ;
return false ;
}
case V_414 :
break;
case V_415 : {
T_1 V_416 = F_15 ( V_295 -> V_417 . V_416 ) ;
T_1 V_136 = F_15 ( V_295 -> V_417 . V_136 ) ;
V_3 -> V_181 =
F_172 ( V_3 -> V_175 -> V_418 , V_136 ) ;
F_64 ( V_3 , V_285 ,
L_68 ,
V_136 , F_173 ( V_416 ) ) ;
break;
}
case V_419 :
break;
case V_420 : {
struct V_1 * V_340 = F_174 ( V_9 , V_281 ) ;
if ( ! V_340 ) {
F_42 ( V_3 , L_69 ) ;
break;
}
F_175 ( & V_8 -> V_53 , V_340 ) ;
break;
}
case V_421 :
F_160 ( V_3 , V_9 ) ;
break;
case V_422 :
F_161 ( V_3 , V_9 ) ;
break;
case V_423 :
default:
F_42 ( V_3 , L_70 ,
V_295 -> V_196 . V_372 ) ;
F_43 ( V_3 , V_58 , NULL , L_66 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
return true ;
}
void F_176 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
F_171 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
int F_177 ( struct V_2 * V_3 , int V_424 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_296 V_297 = {} ;
struct V_59 V_425 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
int V_426 = 0 , V_427 , V_428 ;
bool V_429 = false ;
F_127 ( & V_425 ) ;
while ( V_426 < V_424 ) {
if ( F_52 ( & V_8 -> V_52 ) )
break;
V_9 = F_117 ( & V_8 -> V_52 ) ;
if ( ! V_9 ) {
V_429 = true ;
goto exit;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_428 = F_144 ( V_3 , V_9 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_428 < 0 ) {
V_429 = true ;
goto exit;
}
F_10 ( V_9 ) ;
if ( V_428 > 0 )
V_426 += V_428 ;
if ( ( V_426 > V_430 ) &&
! F_52 ( & V_8 -> V_52 ) ) {
V_429 = true ;
goto exit;
}
}
while ( V_426 < V_424 ) {
if ( ! F_178 ( & V_8 -> V_101 ) )
break;
V_428 = F_126 ( V_8 ) ;
if ( V_428 < 0 ) {
V_429 = true ;
goto exit;
}
V_426 += V_428 ;
F_179 ( & V_8 -> V_101 ) ;
if ( ( V_426 > V_430 ) &&
F_178 ( & V_8 -> V_101 ) ) {
V_429 = true ;
goto exit;
}
}
if ( ( V_426 < V_424 ) && ! F_180 ( & V_8 -> V_310 ) )
V_426 = V_424 ;
while ( F_181 ( & V_8 -> V_310 , & V_297 ) )
F_133 ( V_8 , & V_297 ) ;
F_162 ( V_3 ) ;
F_182 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_140 ( & V_8 -> V_53 , & V_425 ) ;
F_183 ( & V_8 -> V_53 . V_41 , V_38 ) ;
while ( ( V_9 = F_117 ( & V_425 ) ) ) {
F_148 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
exit:
F_28 ( V_8 ) ;
V_427 = V_429 ? V_424 : V_426 ;
return V_427 ;
}
