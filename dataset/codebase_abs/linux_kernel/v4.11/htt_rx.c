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
break;
case 3 :
V_119 -> V_156 |= V_158 ;
break;
}
V_119 -> V_146 |= V_159 ;
break;
default:
break;
}
}
static struct V_160 *
F_70 ( struct V_2 * V_3 , struct V_24 * V_87 )
{
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_165 V_166 ;
T_5 V_167 ;
F_27 ( & V_3 -> V_168 ) ;
if ( ! V_87 )
return NULL ;
if ( V_87 -> V_37 . V_38 &
F_20 ( V_169 ) )
return NULL ;
if ( ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_170 ) ) )
return NULL ;
V_167 = F_49 ( F_15 ( V_87 -> V_152 . V_74 ) ,
V_171 ) ;
V_162 = F_71 ( V_3 , V_167 ) ;
if ( ! V_162 )
return NULL ;
V_164 = F_72 ( V_3 , V_162 -> V_172 ) ;
if ( F_4 ( ! V_164 ) )
return NULL ;
if ( F_73 ( V_164 -> V_173 , & V_166 ) )
return NULL ;
return V_166 . V_174 ;
}
static struct V_160 *
F_74 ( struct V_2 * V_3 , T_1 V_172 )
{
struct V_163 * V_164 ;
struct V_165 V_166 ;
F_27 ( & V_3 -> V_168 ) ;
F_75 (arvif, &ar->arvifs, list) {
if ( V_164 -> V_172 == V_172 &&
F_73 ( V_164 -> V_173 , & V_166 ) == 0 )
return V_166 . V_174 ;
}
return NULL ;
}
static void
F_76 ( struct V_175 * V_176 ,
struct V_177 * V_178 ,
void * V_36 )
{
struct V_165 * V_166 = V_36 ;
* V_166 = V_178 -> V_166 ;
}
static struct V_160 *
F_77 ( struct V_2 * V_3 )
{
struct V_165 V_166 = {} ;
F_78 ( V_3 -> V_176 ,
F_76 ,
& V_166 ) ;
return V_166 . V_174 ;
}
static bool F_79 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 ,
T_1 V_172 )
{
struct V_160 * V_179 ;
F_29 ( & V_3 -> V_168 ) ;
V_179 = V_3 -> V_180 ;
if ( ! V_179 )
V_179 = V_3 -> V_181 ;
if ( ! V_179 )
V_179 = F_70 ( V_3 , V_87 ) ;
if ( ! V_179 )
V_179 = F_74 ( V_3 , V_172 ) ;
if ( ! V_179 )
V_179 = F_77 ( V_3 ) ;
if ( ! V_179 )
V_179 = V_3 -> V_182 ;
F_33 ( & V_3 -> V_168 ) ;
if ( ! V_179 )
return false ;
V_119 -> V_142 = V_179 -> V_142 ;
V_119 -> V_136 = V_179 -> V_183 ;
return true ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
V_119 -> signal = V_184 +
V_87 -> V_133 . V_185 ;
V_119 -> V_146 &= ~ V_186 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
V_119 -> V_187 = F_15 ( V_87 -> V_188 . V_73 . V_189 ) ;
V_119 -> V_146 |= V_190 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 ,
T_1 V_172 )
{
struct V_1 * V_191 ;
struct V_24 * V_87 ;
bool V_192 ;
bool V_193 ;
if ( F_52 ( V_60 ) )
return;
V_191 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_191 -> V_36 - sizeof( * V_87 ) ;
V_192 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_194 ) ) ;
V_193 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_195 ) ) ;
if ( V_192 ) {
V_119 -> V_136 = 0 ;
V_119 -> V_143 = 0 ;
V_119 -> V_155 = 0 ;
V_119 -> V_156 &= ~ V_157 ;
V_119 -> V_146 &= ~ ( V_147 |
V_159 |
V_148 |
V_149 |
V_190 ) ;
V_119 -> V_146 |= V_186 ;
F_80 ( V_3 , V_119 , V_87 ) ;
F_79 ( V_3 , V_119 , V_87 , V_172 ) ;
F_67 ( V_3 , V_119 , V_87 ) ;
}
if ( V_193 )
F_81 ( V_3 , V_119 , V_87 ) ;
}
static char * F_84 ( struct V_196 * V_197 , char * V_198 , T_3 V_19 )
{
T_4 * V_199 ;
int V_200 ;
if ( ! F_85 ( V_197 -> V_201 ) )
return L_11 ;
V_199 = F_86 ( V_197 ) ;
V_200 = * V_199 & V_202 ;
if ( V_200 < 8 )
snprintf ( V_198 , V_19 , L_12 , V_200 , V_203 [ V_200 ] ) ;
else
snprintf ( V_198 , V_19 , L_13 , V_200 ) ;
return V_198 ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_118 * V_204 ,
struct V_1 * V_9 )
{
struct V_118 * V_119 ;
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
char V_200 [ 32 ] ;
V_119 = F_88 ( V_9 ) ;
* V_119 = * V_204 ;
F_64 ( V_3 , V_205 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_89 ( V_197 ) ,
F_84 ( V_197 , V_200 , sizeof( V_200 ) ) ,
F_90 ( F_91 ( V_197 ) ) ?
L_15 : L_16 ,
( F_55 ( V_197 -> V_206 ) & V_207 ) >> 4 ,
( V_119 -> V_146 & ( V_147 | V_159 ) ) == 0 ?
L_17 : L_11 ,
V_119 -> V_146 & V_147 ? L_18 : L_11 ,
V_119 -> V_146 & V_159 ? L_19 : L_11 ,
V_119 -> V_146 & V_149 ? L_20 : L_11 ,
V_119 -> V_156 & V_157 ? L_21 : L_11 ,
V_119 -> V_156 & V_158 ? L_22 : L_11 ,
V_119 -> V_146 & V_148 ? L_23 : L_11 ,
V_119 -> V_143 ,
V_119 -> V_155 ,
V_119 -> V_136 ,
V_119 -> V_142 , V_119 -> V_146 ,
! ! ( V_119 -> V_146 & V_208 ) ,
! ! ( V_119 -> V_146 & V_209 ) ,
! ! ( V_119 -> V_146 & V_210 ) ) ;
F_43 ( V_3 , V_58 , NULL , L_24 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_92 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_93 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_94 ( V_3 -> V_176 , NULL , V_9 , & V_3 -> V_211 ) ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_196 * V_197 )
{
int V_16 = F_96 ( V_197 -> V_201 ) ;
if ( ! F_97 ( V_212 ,
V_3 -> V_213 -> V_214 . V_215 ) )
V_16 = F_98 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_99 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
enum V_103 V_216 ,
bool V_217 )
{
struct V_196 * V_197 ;
struct V_24 * V_87 ;
T_3 V_218 ;
T_3 V_219 ;
bool V_220 ;
bool V_221 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_220 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_170 ) ) ;
V_221 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
if ( F_22 ( F_4 ( ! V_220 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_220 && V_221 ) ) ) )
return;
F_50 ( V_55 , V_55 -> V_16 - V_222 ) ;
if ( ! V_217 )
return;
V_197 = ( void * ) V_55 -> V_36 ;
if ( V_119 -> V_146 & V_223 )
F_50 ( V_55 , V_55 -> V_16 -
F_66 ( V_3 , V_216 ) ) ;
if ( ( V_119 -> V_146 & V_224 ) &&
! F_100 ( V_197 -> V_201 ) &&
V_216 == V_109 )
F_50 ( V_55 , V_55 -> V_16 - 8 ) ;
if ( V_119 -> V_146 & V_223 ) {
V_218 = F_96 ( V_197 -> V_201 ) ;
V_219 = F_65 ( V_3 , V_216 ) ;
memmove ( ( void * ) V_55 -> V_36 + V_219 ,
( void * ) V_55 -> V_36 , V_218 ) ;
F_18 ( V_55 , V_219 ) ;
}
}
static void F_101 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_225 [ 64 ] )
{
struct V_196 * V_197 ;
struct V_24 * V_87 ;
T_3 V_218 ;
T_4 V_226 [ V_227 ] ;
T_4 V_228 [ V_227 ] ;
int V_229 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_229 = F_102 ( & V_3 -> V_230 , V_87 ) ;
F_47 ( V_55 , V_229 ) ;
V_197 = (struct V_196 * ) ( V_55 -> V_36 + V_229 ) ;
V_218 = F_95 ( V_3 , V_197 ) ;
F_103 ( V_226 , F_91 ( V_197 ) ) ;
F_103 ( V_228 , F_89 ( V_197 ) ) ;
F_18 ( V_55 , V_218 ) ;
V_197 = (struct V_196 * ) V_225 ;
V_218 = F_96 ( V_197 -> V_201 ) ;
memcpy ( F_104 ( V_55 , V_218 ) , V_197 , V_218 ) ;
V_197 = (struct V_196 * ) V_55 -> V_36 ;
F_103 ( F_91 ( V_197 ) , V_226 ) ;
F_103 ( F_89 ( V_197 ) , V_228 ) ;
}
static void * F_105 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
enum V_103 V_216 )
{
struct V_196 * V_197 ;
struct V_24 * V_87 ;
T_3 V_218 , V_219 ;
void * V_231 ;
bool V_220 , V_221 , V_232 ;
int V_233 = V_3 -> V_230 . V_234 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_197 = ( void * ) V_87 -> V_235 ;
V_220 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_170 ) ) ;
V_221 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
V_232 = ! ( V_220 && V_221 ) ;
V_231 = V_197 ;
if ( V_220 ) {
V_218 = F_96 ( V_197 -> V_201 ) ;
V_219 = F_65 ( V_3 , V_216 ) ;
V_231 += F_98 ( V_218 , V_233 ) +
F_98 ( V_219 , V_233 ) ;
}
if ( V_232 )
V_231 += sizeof( struct V_236 ) ;
return V_231 ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_225 [ 64 ] ,
enum V_103 V_216 )
{
struct V_196 * V_197 ;
struct V_237 * V_238 ;
T_3 V_218 ;
void * V_231 ;
T_4 V_226 [ V_227 ] ;
T_4 V_228 [ V_227 ] ;
int V_229 ;
struct V_24 * V_87 ;
V_231 = F_105 ( V_3 , V_55 , V_216 ) ;
if ( F_4 ( ! V_231 ) )
return;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_229 = F_102 ( & V_3 -> V_230 , V_87 ) ;
F_47 ( V_55 , V_229 ) ;
F_18 ( V_55 , V_229 ) ;
V_238 = (struct V_237 * ) V_55 -> V_36 ;
F_103 ( V_226 , V_238 -> V_239 ) ;
F_103 ( V_228 , V_238 -> V_240 ) ;
F_18 ( V_55 , sizeof( struct V_237 ) ) ;
memcpy ( F_104 ( V_55 , sizeof( struct V_241 ) ) , V_231 ,
sizeof( struct V_241 ) ) ;
V_197 = (struct V_196 * ) V_225 ;
V_218 = F_96 ( V_197 -> V_201 ) ;
memcpy ( F_104 ( V_55 , V_218 ) , V_197 , V_218 ) ;
V_197 = (struct V_196 * ) V_55 -> V_36 ;
F_103 ( F_91 ( V_197 ) , V_226 ) ;
F_103 ( F_89 ( V_197 ) , V_228 ) ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_225 [ 64 ] )
{
struct V_196 * V_197 ;
T_3 V_218 ;
int V_229 ;
struct V_24 * V_87 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_229 = F_102 ( & V_3 -> V_230 , V_87 ) ;
F_47 ( V_55 , V_229 ) ;
F_18 ( V_55 , sizeof( struct V_236 ) + V_229 ) ;
V_197 = (struct V_196 * ) V_225 ;
V_218 = F_96 ( V_197 -> V_201 ) ;
memcpy ( F_104 ( V_55 , V_218 ) , V_197 , V_218 ) ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
T_4 V_225 [ 64 ] ,
enum V_103 V_216 ,
bool V_217 )
{
struct V_24 * V_87 ;
enum V_242 V_243 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_243 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_244 ) ;
switch ( V_243 ) {
case V_245 :
F_99 ( V_3 , V_55 , V_119 , V_216 ,
V_217 ) ;
break;
case V_246 :
F_101 ( V_3 , V_55 , V_119 , V_225 ) ;
break;
case V_247 :
F_106 ( V_3 , V_55 , V_119 , V_225 , V_216 ) ;
break;
case V_248 :
F_107 ( V_3 , V_55 , V_119 , V_225 ) ;
break;
}
}
static int F_109 ( struct V_1 * V_9 )
{
struct V_24 * V_87 ;
T_1 V_38 , V_90 ;
bool V_249 , V_250 ;
bool V_251 , V_252 ;
bool V_253 , V_254 ;
V_87 = ( void * ) V_9 -> V_36 - sizeof( * V_87 ) ;
V_38 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_90 = F_15 ( V_87 -> V_72 . V_73 . V_130 ) ;
V_249 = ! ! ( V_90 & V_255 ) ;
V_250 = ! ! ( V_90 & V_256 ) ;
V_251 = ! ! ( V_90 & V_257 ) ;
V_252 = ! ! ( V_90 & V_258 ) ;
V_253 = ! ( V_38 & V_259 ) ;
V_254 = ! ( V_38 & V_260 ) ;
if ( ! V_249 && ! V_250 )
return V_261 ;
if ( ! V_251 && ! V_252 )
return V_261 ;
if ( ! V_253 )
return V_261 ;
if ( ! V_254 )
return V_261 ;
return V_262 ;
}
static void F_110 ( struct V_1 * V_55 )
{
V_55 -> V_263 = F_109 ( V_55 ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_191 ;
struct V_1 * V_264 ;
struct V_1 * V_55 ;
struct V_24 * V_87 ;
struct V_196 * V_197 ;
enum V_103 V_216 ;
T_4 V_225 [ 64 ] ;
T_4 * V_265 ;
T_3 V_218 ;
bool V_266 ;
bool V_267 ;
bool V_268 ;
bool V_269 ;
bool V_217 ;
bool V_270 ;
T_1 V_37 ;
if ( F_52 ( V_60 ) )
return;
V_191 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_191 -> V_36 - sizeof( * V_87 ) ;
V_270 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_271 ) ) ;
V_216 = F_49 ( F_15 ( V_87 -> V_152 . V_74 ) ,
V_272 ) ;
V_197 = ( void * ) V_87 -> V_235 ;
V_218 = F_96 ( V_197 -> V_201 ) ;
memcpy ( V_225 , V_197 , V_218 ) ;
V_197 = ( void * ) V_225 ;
V_265 = F_86 ( V_197 ) ;
V_265 [ 0 ] &= ~ V_273 ;
V_264 = F_112 ( V_60 ) ;
V_87 = ( void * ) V_264 -> V_36 - sizeof( * V_87 ) ;
V_37 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_266 = ! ! ( V_37 & V_274 ) ;
V_267 = ! ! ( V_37 & V_275 ) ;
V_268 = ! ! ( V_37 & V_276 ) ;
V_269 = ! ! ( V_37 & V_169 ) ;
V_217 = ( V_216 != V_104 &&
! V_266 &&
! V_267 &&
! V_269 ) ;
V_119 -> V_146 &= ~ ( V_208 |
V_209 |
V_277 |
V_223 |
V_278 |
V_224 ) ;
if ( V_266 )
V_119 -> V_146 |= V_208 ;
if ( V_268 )
V_119 -> V_146 |= V_209 ;
if ( V_270 )
V_119 -> V_146 |= V_278 ;
if ( V_217 ) {
V_119 -> V_146 |= V_277 ;
if ( F_113 ( ! V_270 ) )
V_119 -> V_146 |= V_223 |
V_224 ;
}
F_114 (amsdu, msdu) {
F_110 ( V_55 ) ;
F_108 ( V_3 , V_55 , V_119 , V_225 , V_216 ,
V_217 ) ;
if ( ! V_217 )
continue;
if ( V_270 )
continue;
V_197 = ( void * ) V_55 -> V_36 ;
V_197 -> V_201 &= ~ F_115 ( V_279 ) ;
}
}
static void F_116 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_55 ;
while ( ( V_55 = F_117 ( V_60 ) ) ) {
if ( F_52 ( V_60 ) )
V_119 -> V_146 &= ~ V_210 ;
else
V_119 -> V_146 |= V_210 ;
F_87 ( V_3 , V_119 , V_55 ) ;
}
}
static int F_118 ( struct V_59 * V_60 )
{
struct V_1 * V_9 , * V_191 ;
int V_280 ;
int V_281 = 0 ;
V_191 = F_117 ( V_60 ) ;
F_114 (amsdu, skb)
V_281 += V_9 -> V_16 ;
V_280 = V_281 - F_8 ( V_191 ) ;
if ( ( V_280 > 0 ) &&
( F_119 ( V_191 , 0 , V_280 , V_282 ) < 0 ) ) {
F_120 ( V_60 , V_191 ) ;
return - 1 ;
}
while ( ( V_9 = F_117 ( V_60 ) ) ) {
F_121 ( V_9 , F_47 ( V_191 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_120 ( V_60 , V_191 ) ;
return 0 ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_1 * V_191 ;
struct V_24 * V_87 ;
enum V_242 V_243 ;
V_191 = F_83 ( V_60 ) ;
V_87 = ( void * ) V_191 -> V_36 - sizeof( * V_87 ) ;
V_243 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_244 ) ;
if ( V_243 != V_245 ||
F_123 ( V_60 ) != 1 + V_87 -> V_76 . V_77 ) {
F_45 ( V_60 ) ;
return;
}
F_118 ( V_60 ) ;
}
static bool F_124 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_204 )
{
if ( ! V_204 -> V_136 ) {
F_42 ( V_3 , L_25 ) ;
return false ;
}
if ( F_97 ( V_283 , & V_3 -> V_284 ) ) {
F_64 ( V_3 , V_285 , L_26 ) ;
return false ;
}
return true ;
}
static void F_125 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_204 )
{
if ( F_52 ( V_60 ) )
return;
if ( F_124 ( V_3 , V_60 , V_204 ) )
return;
F_45 ( V_60 ) ;
}
static int F_126 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_118 * V_204 = & V_8 -> V_204 ;
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
F_42 ( V_3 , L_27 , V_26 ) ;
F_45 ( & V_60 ) ;
V_8 -> V_95 = true ;
return V_26 ;
}
V_286 = F_123 ( & V_60 ) ;
F_82 ( V_3 , & V_60 , V_204 , 0xffff ) ;
if ( V_26 > 0 )
F_122 ( V_3 , & V_60 ) ;
F_125 ( V_3 , & V_60 , V_204 ) ;
F_111 ( V_3 , & V_60 , V_204 ) ;
F_116 ( V_3 , & V_60 , V_204 ) ;
return V_286 ;
}
static void F_128 ( struct V_7 * V_8 ,
struct V_287 * V_288 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_289 * V_290 ;
int V_291 ;
int V_12 , V_292 = 0 ;
V_291 = F_49 ( F_15 ( V_288 -> V_197 . V_130 ) ,
V_293 ) ;
V_290 = F_129 ( V_288 ) ;
F_43 ( V_3 , V_58 , NULL , L_28 ,
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
F_42 ( V_3 , L_29 , V_119 ) ;
V_297 . V_119 = V_308 ;
break;
}
F_64 ( V_3 , V_285 , L_30 ,
V_295 -> V_298 . V_286 ) ;
for ( V_12 = 0 ; V_12 < V_295 -> V_298 . V_286 ; V_12 ++ ) {
V_300 = V_295 -> V_298 . V_309 [ V_12 ] ;
V_297 . V_300 = F_55 ( V_300 ) ;
if ( ! F_132 ( & V_8 -> V_310 , V_297 ) ) {
F_42 ( V_3 , L_31 ,
V_297 . V_300 , V_297 . V_119 ) ;
F_133 ( V_8 , & V_297 ) ;
}
}
}
static void F_134 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_311 * V_82 = & V_295 -> V_312 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
T_5 V_74 , V_200 , V_167 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_200 = F_49 ( V_74 , V_313 ) ;
V_167 = F_49 ( V_74 , V_314 ) ;
F_64 ( V_3 , V_285 ,
L_32 ,
V_200 , V_167 , V_82 -> V_315 ) ;
F_29 ( & V_3 -> V_168 ) ;
V_162 = F_71 ( V_3 , V_167 ) ;
if ( ! V_162 ) {
F_42 ( V_3 , L_33 ,
V_167 ) ;
F_33 ( & V_3 -> V_168 ) ;
return;
}
V_164 = F_72 ( V_3 , V_162 -> V_172 ) ;
if ( ! V_164 ) {
F_42 ( V_3 , L_34 ,
V_162 -> V_172 ) ;
F_33 ( & V_3 -> V_168 ) ;
return;
}
F_64 ( V_3 , V_285 ,
L_35 ,
V_162 -> V_316 , V_200 , V_82 -> V_315 ) ;
F_135 ( V_164 -> V_173 , V_162 -> V_316 , V_200 ) ;
F_33 ( & V_3 -> V_168 ) ;
}
static void F_136 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_317 * V_82 = & V_295 -> V_318 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
T_5 V_74 , V_200 , V_167 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_200 = F_49 ( V_74 , V_313 ) ;
V_167 = F_49 ( V_74 , V_314 ) ;
F_64 ( V_3 , V_285 ,
L_36 ,
V_200 , V_167 ) ;
F_29 ( & V_3 -> V_168 ) ;
V_162 = F_71 ( V_3 , V_167 ) ;
if ( ! V_162 ) {
F_42 ( V_3 , L_33 ,
V_167 ) ;
F_33 ( & V_3 -> V_168 ) ;
return;
}
V_164 = F_72 ( V_3 , V_162 -> V_172 ) ;
if ( ! V_164 ) {
F_42 ( V_3 , L_34 ,
V_162 -> V_172 ) ;
F_33 ( & V_3 -> V_168 ) ;
return;
}
F_64 ( V_3 , V_285 ,
L_37 ,
V_162 -> V_316 , V_200 ) ;
F_137 ( V_164 -> V_173 , V_162 -> V_316 , V_200 ) ;
F_33 ( & V_3 -> V_168 ) ;
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
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
if ( ! F_142 ( V_197 -> V_201 ) )
return;
V_197 -> V_201 &= ~ F_115 ( V_279 ) ;
V_119 -> V_146 |= V_277 |
V_223 |
V_224 ;
}
static int F_143 ( struct V_2 * V_3 ,
struct V_59 * V_83 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_118 * V_119 = & V_8 -> V_204 ;
struct V_321 * V_288 ;
struct V_1 * V_55 ;
T_3 V_322 ;
int V_323 = 0 ;
while ( ( V_55 = F_117 ( V_83 ) ) ) {
V_288 = ( void * ) V_55 -> V_36 ;
F_47 ( V_55 , sizeof( * V_288 ) ) ;
F_18 ( V_55 , sizeof( * V_288 ) ) ;
if ( F_8 ( V_55 ) < F_55 ( V_288 -> V_61 ) ) {
F_42 ( V_3 , L_38 ) ;
F_10 ( V_55 ) ;
continue;
}
F_47 ( V_55 , F_55 ( V_288 -> V_61 ) ) ;
V_322 = 4 - ( ( unsigned long ) V_55 -> V_36 & 3 ) ;
F_47 ( V_55 , V_322 ) ;
memmove ( V_55 -> V_36 + V_322 , V_55 -> V_36 , V_55 -> V_16 ) ;
F_18 ( V_55 , V_322 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_146 |= V_186 ;
F_141 ( V_119 , V_55 ) ;
F_79 ( V_3 , V_119 , NULL , V_288 -> V_172 ) ;
F_87 ( V_3 , V_119 , V_55 ) ;
V_323 ++ ;
}
return V_323 ;
}
static int F_144 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = ( void * ) V_9 -> V_36 ;
struct V_118 * V_119 = & V_8 -> V_204 ;
struct V_59 V_83 ;
struct V_59 V_60 ;
T_5 V_167 ;
T_5 V_88 ;
T_4 V_172 ;
T_4 V_200 ;
bool V_324 ;
bool V_325 ;
int V_26 , V_286 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_95 )
return - V_69 ;
F_18 ( V_9 , sizeof( V_295 -> V_197 ) ) ;
F_18 ( V_9 , sizeof( V_295 -> V_326 ) ) ;
V_167 = F_55 ( V_295 -> V_326 . V_167 ) ;
V_88 = F_55 ( V_295 -> V_326 . V_88 ) ;
V_172 = V_295 -> V_326 . V_172 ;
V_200 = F_145 ( V_295 -> V_326 . V_90 , V_327 ) ;
V_324 = ! ! ( V_295 -> V_326 . V_90 &
V_91 ) ;
V_325 = ! ! ( V_295 -> V_326 . V_90 & V_328 ) ;
F_64 ( V_3 , V_285 ,
L_39 ,
V_172 , V_167 , V_200 , V_324 , V_325 , V_88 ) ;
if ( V_9 -> V_16 < V_88 * sizeof( * V_295 -> V_326 . V_86 ) ) {
F_42 ( V_3 , L_40 ) ;
return - V_96 ;
}
F_127 ( & V_83 ) ;
V_26 = F_54 ( V_8 , & V_295 -> V_326 , & V_83 ) ;
if ( V_26 < 0 ) {
F_42 ( V_3 , L_41 , V_26 ) ;
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
F_82 ( V_3 , & V_60 , V_119 , V_172 ) ;
F_125 ( V_3 , & V_60 , V_119 ) ;
F_111 ( V_3 , & V_60 , V_119 ) ;
F_116 ( V_3 , & V_60 , V_119 ) ;
break;
case - V_320 :
default:
F_42 ( V_3 , L_42 , V_26 ) ;
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
F_64 ( V_3 , V_285 , L_43 ,
V_330 ) ;
for ( V_12 = 0 ; V_12 < V_330 ; V_12 ++ ) {
V_331 = F_147 ( V_329 [ V_12 ] ) ;
F_64 ( V_3 , V_285 , L_44 ,
V_331 ) ;
}
}
static void F_148 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_175 * V_176 = V_3 -> V_176 ;
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
T_5 V_167 ;
T_4 V_200 ;
int V_26 ;
int V_12 ;
F_64 ( V_3 , V_285 , L_45 ) ;
V_16 = sizeof( V_295 -> V_197 ) + sizeof( V_295 -> V_340 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_46 ) ;
return;
}
V_339 = F_149 ( V_295 -> V_340 . V_339 ) ;
V_330 = F_149 ( V_295 -> V_340 . V_330 ) ;
V_16 += sizeof( V_295 -> V_340 . V_341 [ 0 ] ) * V_339 ;
V_16 += sizeof( V_295 -> V_340 . V_329 [ 0 ] ) * V_330 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_47 ) ;
return;
}
F_64 ( V_3 , V_285 , L_48 ,
V_339 , V_330 ,
F_149 ( V_295 -> V_340 . V_342 ) ) ;
if ( ! V_3 -> V_8 . V_343 . V_344 ) {
F_42 ( V_3 , L_49 ) ;
return;
}
if ( V_3 -> V_8 . V_343 . V_345 == V_346 ) {
F_42 ( V_3 , L_50 ) ;
return;
}
F_150 () ;
for ( V_12 = 0 ; V_12 < V_339 ; V_12 ++ ) {
V_335 = & V_295 -> V_340 . V_341 [ V_12 ] ;
V_167 = F_49 ( F_149 ( V_335 -> V_90 ) ,
V_347 ) ;
V_200 = F_49 ( F_149 ( V_335 -> V_90 ) ,
V_348 ) ;
V_337 = F_149 ( V_335 -> V_286 ) ;
V_336 = F_147 ( V_335 -> V_338 ) ;
F_64 ( V_3 , V_285 , L_51 ,
V_12 , V_167 , V_200 , V_337 , V_336 ) ;
if ( F_22 ( V_167 >= V_3 -> V_8 . V_343 . V_349 ) ||
F_22 ( V_200 >= V_3 -> V_8 . V_343 . V_350 ) ) {
F_42 ( V_3 , L_52 ,
V_167 , V_200 ) ;
continue;
}
F_29 ( & V_3 -> V_168 ) ;
V_333 = F_151 ( V_3 , V_167 , V_200 ) ;
F_33 ( & V_3 -> V_168 ) ;
if ( F_22 ( ! V_333 ) ) {
F_42 ( V_3 , L_53 ,
V_167 , V_200 ) ;
continue;
}
V_286 = 0 ;
V_338 = 0 ;
while ( V_286 < V_337 &&
V_338 < V_336 ) {
V_26 = F_152 ( V_176 , V_333 ) ;
if ( V_26 < 0 )
break;
V_286 ++ ;
V_338 += V_26 ;
}
V_335 -> V_286 = F_153 ( V_286 ) ;
V_335 -> V_338 = F_154 ( V_338 ) ;
F_155 ( V_176 , V_333 ) ;
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
F_42 ( V_3 , L_54 ,
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
F_64 ( V_3 , V_285 , L_55 ) ;
V_16 = sizeof( V_295 -> V_197 ) + sizeof( V_295 -> V_352 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_56 ) ;
return;
}
V_330 = F_149 ( V_295 -> V_352 . V_330 ) ;
V_16 += sizeof( V_295 -> V_352 . V_329 [ 0 ] ) * V_330 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_57 ) ;
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
T_5 V_167 ;
T_4 V_200 ;
int V_12 ;
F_64 ( V_3 , V_285 , L_58 ) ;
V_16 = sizeof( V_295 -> V_197 ) + sizeof( V_295 -> V_359 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_59 ) ;
return;
}
V_74 = F_149 ( V_295 -> V_359 . V_74 ) ;
V_130 = F_149 ( V_295 -> V_359 . V_130 ) ;
V_357 = ! ! ( V_74 & V_360 ) ;
V_339 = F_49 ( V_74 , V_361 ) ;
V_345 = F_49 ( V_130 , V_362 ) ;
V_358 = F_49 ( V_130 , V_361 ) ;
F_64 ( V_3 , V_285 ,
L_60 ,
V_74 , V_130 , V_357 , V_339 , V_345 , V_358 ) ;
V_16 += sizeof( V_295 -> V_359 . V_341 [ 0 ] ) * V_339 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_61 ) ;
return;
}
switch ( V_345 ) {
case V_346 :
case V_363 :
break;
default:
F_42 ( V_3 , L_62 ,
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
V_167 = F_49 ( V_74 , V_365 ) ;
V_200 = F_49 ( V_74 , V_366 ) ;
if ( F_22 ( V_167 >= V_3 -> V_8 . V_343 . V_349 ) ||
F_22 ( V_200 >= V_3 -> V_8 . V_343 . V_350 ) ) {
F_42 ( V_3 , L_52 ,
V_167 , V_200 ) ;
continue;
}
F_29 ( & V_3 -> V_168 ) ;
V_333 = F_151 ( V_3 , V_167 , V_200 ) ;
F_33 ( & V_3 -> V_168 ) ;
if ( F_22 ( ! V_333 ) ) {
F_42 ( V_3 , L_53 ,
V_167 , V_200 ) ;
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
static inline bool F_165 ( T_4 V_123 )
{
static const T_4 V_371 [] = { 1 , 2 , 5 , 11 , 6 , 9 , 12 ,
18 , 24 , 36 , 48 , 54 } ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_166 ( V_371 ) ; V_12 ++ ) {
if ( V_123 == V_371 [ V_12 ] )
return true ;
}
return false ;
}
static void
F_167 ( struct V_2 * V_3 ,
struct V_372 * V_373 ,
struct V_374 * V_375 )
{
struct V_376 * V_377 = (struct V_376 * ) V_373 -> V_368 ;
T_4 V_123 = 0 , V_125 ;
struct V_378 V_379 ;
F_27 ( & V_3 -> V_168 ) ;
V_379 . V_38 = F_168 ( V_375 -> V_380 ) ;
V_379 . V_124 = F_169 ( V_375 -> V_38 ) ;
V_379 . V_127 = F_170 ( V_375 -> V_380 ) ;
V_379 . V_126 = F_171 ( V_375 -> V_380 ) ;
V_125 = F_172 ( V_375 -> V_38 ) ;
if ( ( ( V_379 . V_38 == V_381 ) ||
( V_379 . V_38 == V_382 ) ) && V_379 . V_126 > 9 ) {
F_42 ( V_3 , L_63 , V_379 . V_126 ) ;
return;
}
memset ( & V_377 -> V_379 , 0 , sizeof( V_377 -> V_379 ) ) ;
if ( V_379 . V_38 == V_383 ||
V_379 . V_38 == V_384 ) {
V_123 = F_173 ( V_375 -> V_380 ) ;
if ( ! F_165 ( V_123 ) ) {
F_42 ( V_3 , L_64 ,
V_123 ) ;
return;
}
V_123 *= 10 ;
if ( V_123 == 60 && V_379 . V_38 == V_383 )
V_123 = V_123 - 5 ;
V_377 -> V_379 . V_385 = V_123 ;
} else if ( V_379 . V_38 == V_381 ) {
V_377 -> V_379 . V_38 = V_386 ;
V_377 -> V_379 . V_126 = V_379 . V_126 ;
} else {
V_377 -> V_379 . V_38 = V_387 ;
V_377 -> V_379 . V_126 = V_379 . V_126 ;
}
if ( V_125 )
V_377 -> V_379 . V_38 |= V_388 ;
V_377 -> V_379 . V_127 = V_379 . V_127 ;
V_377 -> V_379 . V_124 = V_379 . V_124 + V_389 ;
}
static void F_174 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
struct V_374 * V_390 = & V_3 -> V_391 ;
struct V_392 * V_393 ;
struct V_372 * V_373 ;
struct V_161 * V_162 ;
int V_167 , V_12 ;
T_4 V_394 , V_395 ;
V_395 = V_295 -> V_391 . V_395 ;
V_394 = V_295 -> V_391 . V_394 * sizeof( T_7 ) ;
if ( V_9 -> V_16 < sizeof( struct V_396 ) + V_395 * V_394 ) {
F_42 ( V_3 , L_65 , V_9 -> V_16 ) ;
return;
}
V_393 = (struct V_392 * )
( V_295 -> V_391 . V_397 ) ;
V_167 = F_55 ( V_393 -> V_167 ) ;
F_150 () ;
F_29 ( & V_3 -> V_168 ) ;
V_162 = F_71 ( V_3 , V_167 ) ;
if ( ! V_162 ) {
F_42 ( V_3 , L_66 ,
V_167 ) ;
goto V_198;
}
V_373 = V_162 -> V_373 ;
for ( V_12 = 0 ; V_12 < V_395 ; V_12 ++ ) {
V_393 = (struct V_392 * )
( V_295 -> V_391 . V_397 + V_12 * V_394 ) ;
V_390 -> V_398 = F_15 ( V_393 -> V_398 ) ;
V_390 -> V_399 = F_15 ( V_393 -> V_399 ) ;
V_390 -> V_400 =
F_15 ( V_393 -> V_400 ) ;
V_390 -> V_380 = V_393 -> V_380 ;
V_390 -> V_38 = V_393 -> V_38 ;
V_390 -> V_401 = F_55 ( V_393 -> V_401 ) ;
V_390 -> V_402 = F_55 ( V_393 -> V_402 ) ;
V_390 -> V_403 = F_55 ( V_393 -> V_403 ) ;
F_167 ( V_3 , V_373 , V_390 ) ;
}
V_198:
F_33 ( & V_3 -> V_168 ) ;
F_156 () ;
}
bool F_164 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
enum V_404 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_42 ( V_3 , L_67 ) ;
F_64 ( V_3 , V_285 , L_68 ,
V_295 -> V_197 . V_405 ) ;
if ( V_295 -> V_197 . V_405 >= V_3 -> V_8 . V_406 ) {
F_64 ( V_3 , V_285 , L_69 ,
V_295 -> V_197 . V_405 , V_3 -> V_8 . V_406 ) ;
return true ;
}
type = V_3 -> V_8 . V_407 [ V_295 -> V_197 . V_405 ] ;
switch ( type ) {
case V_408 : {
V_8 -> V_409 = V_295 -> V_410 . V_411 ;
V_8 -> V_412 = V_295 -> V_410 . V_413 ;
F_175 ( & V_8 -> V_414 ) ;
break;
}
case V_415 :
F_128 ( V_8 , & V_295 -> V_416 ) ;
break;
case V_417 : {
struct V_418 V_82 = {
. V_172 = V_295 -> V_419 . V_172 ,
. V_167 = F_55 ( V_295 -> V_419 . V_167 ) ,
} ;
memcpy ( V_82 . V_316 , V_295 -> V_419 . V_316 , sizeof( V_82 . V_316 ) ) ;
F_176 ( V_8 , & V_82 ) ;
break;
}
case V_420 : {
struct V_421 V_82 = {
. V_167 = F_55 ( V_295 -> V_422 . V_167 ) ,
} ;
F_177 ( V_8 , & V_82 ) ;
break;
}
case V_423 : {
struct V_296 V_297 = {} ;
int V_119 = F_15 ( V_295 -> V_424 . V_119 ) ;
V_297 . V_300 = F_15 ( V_295 -> V_424 . V_425 ) ;
switch ( V_119 ) {
case V_426 :
V_297 . V_119 = V_304 ;
break;
case V_427 :
V_297 . V_119 = V_302 ;
break;
case V_428 :
V_297 . V_119 = V_308 ;
break;
}
V_119 = F_133 ( V_8 , & V_297 ) ;
if ( ! V_119 ) {
F_29 ( & V_8 -> V_367 ) ;
F_178 ( V_8 ) ;
F_33 ( & V_8 -> V_367 ) ;
}
break;
}
case V_429 :
F_131 ( V_8 -> V_3 , V_9 ) ;
break;
case V_430 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_431 * V_82 = & V_295 -> V_432 ;
F_64 ( V_3 , V_285 ,
L_70 ,
F_55 ( V_82 -> V_167 ) ,
! ! ( V_82 -> V_38 & V_433 ) ,
F_49 ( V_82 -> V_38 , V_434 ) ) ;
F_175 ( & V_3 -> V_435 ) ;
break;
}
case V_436 : {
F_43 ( V_3 , V_58 , NULL , L_71 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_179 ( & V_8 -> V_101 ) ;
break;
}
case V_437 :
break;
case V_438 :
F_180 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_439 :
F_42 ( V_3 , L_72 ) ;
break;
case V_440 :
F_134 ( V_3 , V_295 ) ;
break;
case V_441 :
F_136 ( V_3 , V_295 ) ;
break;
case V_442 : {
F_181 ( V_3 , V_295 -> V_443 . V_397 ,
V_9 -> V_16 -
F_48 ( struct V_294 ,
V_443 . V_397 ) ) ;
break;
}
case V_444 : {
break;
}
case V_445 : {
F_46 ( & V_8 -> V_52 , V_9 ) ;
return false ;
}
case V_446 :
break;
case V_447 : {
T_1 V_448 = F_15 ( V_295 -> V_449 . V_448 ) ;
T_1 V_136 = F_15 ( V_295 -> V_449 . V_136 ) ;
V_3 -> V_182 = F_182 ( V_3 -> V_176 -> V_450 , V_136 ) ;
F_64 ( V_3 , V_285 ,
L_73 ,
V_136 , F_183 ( V_448 ) ) ;
break;
}
case V_451 :
break;
case V_452 : {
struct V_1 * V_340 = F_184 ( V_9 , V_282 ) ;
if ( ! V_340 ) {
F_42 ( V_3 , L_74 ) ;
break;
}
F_185 ( & V_8 -> V_53 , V_340 ) ;
break;
}
case V_453 :
F_160 ( V_3 , V_9 ) ;
break;
case V_454 :
F_161 ( V_3 , V_9 ) ;
break;
case V_455 :
F_174 ( V_3 , V_9 ) ;
break;
case V_456 :
default:
F_42 ( V_3 , L_75 ,
V_295 -> V_197 . V_405 ) ;
F_43 ( V_3 , V_58 , NULL , L_71 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
}
return true ;
}
void F_186 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
F_181 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
int F_187 ( struct V_2 * V_3 , int V_457 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_296 V_297 = {} ;
struct V_59 V_458 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
int V_459 = 0 , V_460 , V_461 ;
bool V_462 = false ;
F_127 ( & V_458 ) ;
while ( V_459 < V_457 ) {
if ( F_52 ( & V_8 -> V_52 ) )
break;
V_9 = F_117 ( & V_8 -> V_52 ) ;
if ( ! V_9 ) {
V_462 = true ;
goto exit;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_461 = F_144 ( V_3 , V_9 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_461 < 0 ) {
V_462 = true ;
goto exit;
}
F_10 ( V_9 ) ;
if ( V_461 > 0 )
V_459 += V_461 ;
if ( ( V_459 > V_463 ) &&
! F_52 ( & V_8 -> V_52 ) ) {
V_462 = true ;
goto exit;
}
}
while ( V_459 < V_457 ) {
if ( ! F_188 ( & V_8 -> V_101 ) )
break;
V_461 = F_126 ( V_8 ) ;
if ( V_461 < 0 ) {
V_462 = true ;
goto exit;
}
V_459 += V_461 ;
F_189 ( & V_8 -> V_101 ) ;
if ( ( V_459 > V_463 ) &&
F_188 ( & V_8 -> V_101 ) ) {
V_462 = true ;
goto exit;
}
}
if ( ( V_459 < V_457 ) && ! F_190 ( & V_8 -> V_310 ) )
V_459 = V_457 ;
while ( F_191 ( & V_8 -> V_310 , & V_297 ) )
F_133 ( V_8 , & V_297 ) ;
F_162 ( V_3 ) ;
F_192 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_140 ( & V_8 -> V_53 , & V_458 ) ;
F_193 ( & V_8 -> V_53 . V_41 , V_38 ) ;
while ( ( V_9 = F_117 ( & V_458 ) ) ) {
F_148 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
exit:
F_28 ( V_8 ) ;
V_460 = V_462 ? V_457 : V_459 ;
return V_460 ;
}
