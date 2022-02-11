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
return V_114 ;
case V_115 :
case V_116 :
return V_117 ;
case V_118 :
case V_119 :
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
return V_120 ;
case V_108 :
case V_109 :
return V_121 ;
case V_111 :
return V_122 ;
case V_113 :
return V_123 ;
case V_115 :
case V_116 :
return V_124 ;
case V_118 :
case V_119 :
break;
}
F_42 ( V_3 , L_6 , type ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_24 * V_87 )
{
struct V_127 * V_128 ;
T_4 V_129 , V_130 , V_131 , V_132 , V_133 , V_134 ;
T_4 V_135 = 0 ;
T_4 V_136 ;
T_1 V_137 , V_138 , V_139 ;
V_137 = F_15 ( V_87 -> V_140 . V_137 ) ;
V_138 = F_15 ( V_87 -> V_140 . V_138 ) ;
V_139 = F_15 ( V_87 -> V_140 . V_139 ) ;
V_135 = F_49 ( V_137 , V_141 ) ;
switch ( V_135 ) {
case V_142 :
if ( ! V_126 -> V_143 )
return;
V_129 = V_137 & V_144 ;
V_130 = F_49 ( V_137 , V_145 ) ;
V_130 &= ~ V_146 ;
V_128 = & V_3 -> V_147 . V_148 [ V_126 -> V_149 ] ;
V_126 -> V_150 = F_68 ( V_128 , V_130 , V_129 ) ;
break;
case V_151 :
case V_152 :
V_133 = V_138 & 0x1F ;
V_134 = V_133 >> 3 ;
V_131 = ( V_138 >> 7 ) & 1 ;
V_132 = ( V_139 >> 7 ) & 1 ;
V_126 -> V_150 = V_133 ;
V_126 -> V_153 = V_154 ;
if ( V_132 )
V_126 -> V_155 |= V_156 ;
if ( V_131 )
V_126 -> V_131 = V_157 ;
break;
case V_158 :
case V_159 :
V_131 = V_138 & 3 ;
V_132 = V_139 & 1 ;
V_136 = ( V_138 >> 4 ) & 0x3F ;
if ( F_69 ( V_136 ) ) {
V_133 = ( V_139 >> 4 ) & 0x0F ;
V_134 = ( ( V_138 >> 10 ) & 0x07 ) + 1 ;
} else {
V_133 = 0 ;
V_134 = 1 ;
}
if ( V_133 > 0x09 ) {
F_42 ( V_3 , L_7 , V_133 ) ;
F_42 ( V_3 , L_8 ,
F_15 ( V_87 -> V_37 . V_38 ) ,
F_15 ( V_87 -> V_160 . V_74 ) ,
F_15 ( V_87 -> V_160 . V_137 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_137 ) ,
V_87 -> V_140 . V_74 ,
F_15 ( V_87 -> V_140 . V_137 ) ,
F_15 ( V_87 -> V_140 . V_138 ) ,
F_15 ( V_87 -> V_140 . V_139 ) ,
F_15 ( V_87 -> V_140 . V_161 ) ) ;
F_42 ( V_3 , L_9 ,
F_15 ( V_87 -> V_79 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_162 . V_74 ) ) ;
F_43 ( V_3 , V_58 , NULL ,
L_10 ,
V_87 -> V_67 , 50 ) ;
}
V_126 -> V_150 = V_133 ;
V_126 -> V_134 = V_134 ;
if ( V_132 )
V_126 -> V_155 |= V_156 ;
switch ( V_131 ) {
case 0 :
break;
case 1 :
V_126 -> V_131 = V_157 ;
break;
case 2 :
V_126 -> V_131 = V_163 ;
break;
case 3 :
V_126 -> V_131 = V_164 ;
break;
}
V_126 -> V_153 = V_165 ;
break;
default:
break;
}
}
static struct V_166 *
F_70 ( struct V_2 * V_3 , struct V_24 * V_87 )
{
struct V_167 * V_168 ;
struct V_169 * V_170 ;
struct V_171 V_172 ;
T_5 V_173 ;
F_27 ( & V_3 -> V_174 ) ;
if ( ! V_87 )
return NULL ;
if ( V_87 -> V_37 . V_38 &
F_20 ( V_175 ) )
return NULL ;
if ( ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_176 ) ) )
return NULL ;
V_173 = F_49 ( F_15 ( V_87 -> V_160 . V_74 ) ,
V_177 ) ;
V_168 = F_71 ( V_3 , V_173 ) ;
if ( ! V_168 )
return NULL ;
V_170 = F_72 ( V_3 , V_168 -> V_178 ) ;
if ( F_4 ( ! V_170 ) )
return NULL ;
if ( F_73 ( V_170 -> V_179 , & V_172 ) )
return NULL ;
return V_172 . V_180 ;
}
static struct V_166 *
F_74 ( struct V_2 * V_3 , T_1 V_178 )
{
struct V_169 * V_170 ;
struct V_171 V_172 ;
F_27 ( & V_3 -> V_174 ) ;
F_75 (arvif, &ar->arvifs, list) {
if ( V_170 -> V_178 == V_178 &&
F_73 ( V_170 -> V_179 , & V_172 ) == 0 )
return V_172 . V_180 ;
}
return NULL ;
}
static void
F_76 ( struct V_181 * V_182 ,
struct V_183 * V_184 ,
void * V_36 )
{
struct V_171 * V_172 = V_36 ;
* V_172 = V_184 -> V_172 ;
}
static struct V_166 *
F_77 ( struct V_2 * V_3 )
{
struct V_171 V_172 = {} ;
F_78 ( V_3 -> V_182 ,
F_76 ,
& V_172 ) ;
return V_172 . V_180 ;
}
static bool F_79 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_24 * V_87 ,
T_1 V_178 )
{
struct V_166 * V_185 ;
F_29 ( & V_3 -> V_174 ) ;
V_185 = V_3 -> V_186 ;
if ( ! V_185 )
V_185 = V_3 -> V_187 ;
if ( ! V_185 )
V_185 = F_70 ( V_3 , V_87 ) ;
if ( ! V_185 )
V_185 = F_74 ( V_3 , V_178 ) ;
if ( ! V_185 )
V_185 = F_77 ( V_3 ) ;
if ( ! V_185 )
V_185 = V_3 -> V_188 ;
F_33 ( & V_3 -> V_174 ) ;
if ( ! V_185 )
return false ;
V_126 -> V_149 = V_185 -> V_149 ;
V_126 -> V_143 = V_185 -> V_189 ;
return true ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_24 * V_87 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_190 ; V_12 ++ ) {
V_126 -> V_191 &= ~ F_81 ( V_12 ) ;
if ( V_87 -> V_140 . V_192 [ V_12 ] . V_193 != 0x80 ) {
V_126 -> V_194 [ V_12 ] = V_195 +
V_87 -> V_140 . V_192 [ V_12 ] . V_193 ;
V_126 -> V_191 |= F_81 ( V_12 ) ;
}
}
V_126 -> signal = V_195 +
V_87 -> V_140 . V_196 ;
V_126 -> V_197 &= ~ V_198 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_24 * V_87 )
{
V_126 -> V_199 = F_15 ( V_87 -> V_200 . V_73 . V_201 ) ;
V_126 -> V_197 |= V_202 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_125 * V_126 ,
T_1 V_178 )
{
struct V_1 * V_203 ;
struct V_24 * V_87 ;
bool V_204 ;
bool V_205 ;
if ( F_52 ( V_60 ) )
return;
V_203 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_203 -> V_36 - sizeof( * V_87 ) ;
V_204 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_206 ) ) ;
V_205 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_207 ) ) ;
if ( V_204 ) {
V_126 -> V_143 = 0 ;
V_126 -> V_150 = 0 ;
V_126 -> V_134 = 0 ;
V_126 -> V_153 = V_208 ;
V_126 -> V_131 = V_209 ;
V_126 -> V_197 &= ~ V_202 ;
V_126 -> V_197 |= V_198 ;
V_126 -> V_197 &= ~ ( V_210 ) ;
V_126 -> V_197 |= V_211 | V_212 ;
V_126 -> V_213 = V_3 -> V_213 ;
F_80 ( V_3 , V_126 , V_87 ) ;
F_79 ( V_3 , V_126 , V_87 , V_178 ) ;
F_67 ( V_3 , V_126 , V_87 ) ;
}
if ( V_205 ) {
F_82 ( V_3 , V_126 , V_87 ) ;
V_126 -> V_197 |= V_210 ;
V_3 -> V_213 ++ ;
}
}
static char * F_85 ( struct V_214 * V_215 , char * V_216 , T_3 V_19 )
{
T_4 * V_217 ;
int V_218 ;
if ( ! F_86 ( V_215 -> V_219 ) )
return L_11 ;
V_217 = F_87 ( V_215 ) ;
V_218 = * V_217 & V_220 ;
if ( V_218 < 8 )
snprintf ( V_216 , V_19 , L_12 , V_218 , V_221 [ V_218 ] ) ;
else
snprintf ( V_216 , V_19 , L_13 , V_218 ) ;
return V_216 ;
}
static void F_88 ( struct V_2 * V_3 ,
struct V_125 * V_222 ,
struct V_1 * V_9 )
{
struct V_125 * V_126 ;
struct V_214 * V_215 = (struct V_214 * ) V_9 -> V_36 ;
char V_218 [ 32 ] ;
V_126 = F_89 ( V_9 ) ;
* V_126 = * V_222 ;
F_64 ( V_3 , V_223 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_90 ( V_215 ) ,
F_85 ( V_215 , V_218 , sizeof( V_218 ) ) ,
F_91 ( F_92 ( V_215 ) ) ?
L_15 : L_16 ,
( F_55 ( V_215 -> V_224 ) & V_225 ) >> 4 ,
( V_126 -> V_153 == V_208 ) ? L_17 : L_11 ,
( V_126 -> V_153 == V_154 ) ? L_18 : L_11 ,
( V_126 -> V_153 == V_165 ) ? L_19 : L_11 ,
( V_126 -> V_131 == V_157 ) ? L_20 : L_11 ,
( V_126 -> V_131 == V_163 ) ? L_21 : L_11 ,
( V_126 -> V_131 == V_164 ) ? L_22 : L_11 ,
V_126 -> V_155 & V_156 ? L_23 : L_11 ,
V_126 -> V_150 ,
V_126 -> V_134 ,
V_126 -> V_143 ,
V_126 -> V_149 , V_126 -> V_197 ,
! ! ( V_126 -> V_197 & V_226 ) ,
! ! ( V_126 -> V_197 & V_227 ) ,
! ! ( V_126 -> V_197 & V_228 ) ) ;
F_43 ( V_3 , V_58 , NULL , L_24 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_93 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_94 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_95 ( V_3 -> V_182 , NULL , V_9 , & V_3 -> V_229 ) ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_214 * V_215 )
{
int V_16 = F_97 ( V_215 -> V_219 ) ;
if ( ! F_98 ( V_230 ,
V_3 -> V_231 -> V_232 . V_233 ) )
V_16 = F_99 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_100 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_125 * V_126 ,
enum V_103 V_234 ,
bool V_235 )
{
struct V_214 * V_215 ;
struct V_24 * V_87 ;
T_3 V_236 ;
T_3 V_237 ;
bool V_238 ;
bool V_239 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_238 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_176 ) ) ;
V_239 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
if ( F_22 ( F_4 ( ! V_238 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_238 && V_239 ) ) ) )
return;
F_50 ( V_55 , V_55 -> V_16 - V_240 ) ;
if ( ! V_235 )
return;
V_215 = ( void * ) V_55 -> V_36 ;
if ( V_126 -> V_197 & V_241 ) {
F_50 ( V_55 , V_55 -> V_16 -
F_66 ( V_3 , V_234 ) ) ;
} else {
if ( ( V_126 -> V_197 & V_242 ) &&
V_234 == V_111 )
F_50 ( V_55 , V_55 -> V_16 - 8 ) ;
if ( V_126 -> V_197 & V_243 &&
V_234 != V_111 )
F_50 ( V_55 , V_55 -> V_16 -
F_66 ( V_3 , V_234 ) ) ;
}
if ( ( V_126 -> V_197 & V_244 ) &&
! F_101 ( V_215 -> V_219 ) &&
V_234 == V_109 )
F_50 ( V_55 , V_55 -> V_16 - 8 ) ;
if ( V_126 -> V_197 & V_241 ) {
V_236 = F_97 ( V_215 -> V_219 ) ;
V_237 = F_65 ( V_3 , V_234 ) ;
memmove ( ( void * ) V_55 -> V_36 + V_237 ,
( void * ) V_55 -> V_36 , V_236 ) ;
F_18 ( V_55 , V_237 ) ;
}
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_125 * V_126 ,
const T_4 V_245 [ 64 ] ,
enum V_103 V_234 )
{
struct V_214 * V_215 ;
struct V_24 * V_87 ;
T_3 V_236 ;
T_4 V_246 [ V_247 ] ;
T_4 V_248 [ V_247 ] ;
int V_249 ;
int V_250 = V_3 -> V_251 . V_252 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_249 = F_103 ( & V_3 -> V_251 , V_87 ) ;
F_47 ( V_55 , V_249 ) ;
V_215 = (struct V_214 * ) ( V_55 -> V_36 + V_249 ) ;
V_236 = F_96 ( V_3 , V_215 ) ;
F_104 ( V_246 , F_92 ( V_215 ) ) ;
F_104 ( V_248 , F_90 ( V_215 ) ) ;
F_18 ( V_55 , V_236 ) ;
V_215 = (struct V_214 * ) V_245 ;
V_236 = F_97 ( V_215 -> V_219 ) ;
if ( ! ( V_126 -> V_197 & V_241 ) ) {
memcpy ( F_105 ( V_55 ,
F_65 ( V_3 , V_234 ) ) ,
( void * ) V_215 + F_99 ( V_236 , V_250 ) ,
F_65 ( V_3 , V_234 ) ) ;
}
memcpy ( F_105 ( V_55 , V_236 ) , V_215 , V_236 ) ;
V_215 = (struct V_214 * ) V_55 -> V_36 ;
F_104 ( F_92 ( V_215 ) , V_246 ) ;
F_104 ( F_90 ( V_215 ) , V_248 ) ;
}
static void * F_106 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
enum V_103 V_234 )
{
struct V_214 * V_215 ;
struct V_24 * V_87 ;
T_3 V_236 , V_237 ;
void * V_253 ;
bool V_238 , V_239 , V_254 ;
int V_250 = V_3 -> V_251 . V_252 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_215 = ( void * ) V_87 -> V_255 ;
V_238 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_176 ) ) ;
V_239 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
V_254 = ! ( V_238 && V_239 ) ;
V_253 = V_215 ;
if ( V_238 ) {
V_236 = F_97 ( V_215 -> V_219 ) ;
V_237 = F_65 ( V_3 , V_234 ) ;
V_253 += F_99 ( V_236 , V_250 ) +
F_99 ( V_237 , V_250 ) ;
}
if ( V_254 )
V_253 += sizeof( struct V_256 ) ;
return V_253 ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_125 * V_126 ,
const T_4 V_245 [ 64 ] ,
enum V_103 V_234 )
{
struct V_214 * V_215 ;
struct V_257 * V_258 ;
T_3 V_236 ;
void * V_253 ;
T_4 V_246 [ V_247 ] ;
T_4 V_248 [ V_247 ] ;
int V_249 ;
struct V_24 * V_87 ;
int V_250 = V_3 -> V_251 . V_252 ;
V_253 = F_106 ( V_3 , V_55 , V_234 ) ;
if ( F_4 ( ! V_253 ) )
return;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_249 = F_103 ( & V_3 -> V_251 , V_87 ) ;
F_47 ( V_55 , V_249 ) ;
F_18 ( V_55 , V_249 ) ;
V_258 = (struct V_257 * ) V_55 -> V_36 ;
F_104 ( V_246 , V_258 -> V_259 ) ;
F_104 ( V_248 , V_258 -> V_260 ) ;
F_18 ( V_55 , sizeof( struct V_257 ) ) ;
memcpy ( F_105 ( V_55 , sizeof( struct V_261 ) ) , V_253 ,
sizeof( struct V_261 ) ) ;
V_215 = (struct V_214 * ) V_245 ;
V_236 = F_97 ( V_215 -> V_219 ) ;
if ( ! ( V_126 -> V_197 & V_241 ) ) {
memcpy ( F_105 ( V_55 ,
F_65 ( V_3 , V_234 ) ) ,
( void * ) V_215 + F_99 ( V_236 , V_250 ) ,
F_65 ( V_3 , V_234 ) ) ;
}
memcpy ( F_105 ( V_55 , V_236 ) , V_215 , V_236 ) ;
V_215 = (struct V_214 * ) V_55 -> V_36 ;
F_104 ( F_92 ( V_215 ) , V_246 ) ;
F_104 ( F_90 ( V_215 ) , V_248 ) ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_125 * V_126 ,
const T_4 V_245 [ 64 ] ,
enum V_103 V_234 )
{
struct V_214 * V_215 ;
T_3 V_236 ;
int V_249 ;
struct V_24 * V_87 ;
int V_250 = V_3 -> V_251 . V_252 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_249 = F_103 ( & V_3 -> V_251 , V_87 ) ;
F_47 ( V_55 , V_249 ) ;
F_18 ( V_55 , sizeof( struct V_256 ) + V_249 ) ;
V_215 = (struct V_214 * ) V_245 ;
V_236 = F_97 ( V_215 -> V_219 ) ;
if ( ! ( V_126 -> V_197 & V_241 ) ) {
memcpy ( F_105 ( V_55 ,
F_65 ( V_3 , V_234 ) ) ,
( void * ) V_215 + F_99 ( V_236 , V_250 ) ,
F_65 ( V_3 , V_234 ) ) ;
}
memcpy ( F_105 ( V_55 , V_236 ) , V_215 , V_236 ) ;
}
static void F_109 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_125 * V_126 ,
T_4 V_245 [ 64 ] ,
enum V_103 V_234 ,
bool V_235 )
{
struct V_24 * V_87 ;
enum V_262 V_263 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_263 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_137 ) ,
V_264 ) ;
switch ( V_263 ) {
case V_265 :
F_100 ( V_3 , V_55 , V_126 , V_234 ,
V_235 ) ;
break;
case V_266 :
F_102 ( V_3 , V_55 , V_126 , V_245 ,
V_234 ) ;
break;
case V_267 :
F_107 ( V_3 , V_55 , V_126 , V_245 , V_234 ) ;
break;
case V_268 :
F_108 ( V_3 , V_55 , V_126 , V_245 ,
V_234 ) ;
break;
}
}
static int F_110 ( struct V_1 * V_9 )
{
struct V_24 * V_87 ;
T_1 V_38 , V_90 ;
bool V_269 , V_270 ;
bool V_271 , V_272 ;
bool V_273 , V_274 ;
V_87 = ( void * ) V_9 -> V_36 - sizeof( * V_87 ) ;
V_38 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_90 = F_15 ( V_87 -> V_72 . V_73 . V_137 ) ;
V_269 = ! ! ( V_90 & V_275 ) ;
V_270 = ! ! ( V_90 & V_276 ) ;
V_271 = ! ! ( V_90 & V_277 ) ;
V_272 = ! ! ( V_90 & V_278 ) ;
V_273 = ! ( V_38 & V_279 ) ;
V_274 = ! ( V_38 & V_280 ) ;
if ( ! V_269 && ! V_270 )
return V_281 ;
if ( ! V_271 && ! V_272 )
return V_281 ;
if ( ! V_273 )
return V_281 ;
if ( ! V_274 )
return V_281 ;
return V_282 ;
}
static void F_111 ( struct V_1 * V_55 )
{
V_55 -> V_283 = F_110 ( V_55 ) ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_125 * V_126 ,
bool V_284 )
{
struct V_1 * V_203 ;
struct V_1 * V_285 ;
struct V_1 * V_55 ;
struct V_24 * V_87 ;
struct V_214 * V_215 ;
enum V_103 V_234 ;
T_4 V_245 [ 64 ] ;
T_4 * V_286 ;
bool V_287 ;
bool V_288 ;
bool V_289 ;
bool V_290 ;
bool V_235 ;
bool V_291 ;
T_1 V_37 ;
if ( F_52 ( V_60 ) )
return;
V_203 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_203 -> V_36 - sizeof( * V_87 ) ;
V_291 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_292 ) ) ;
V_234 = F_49 ( F_15 ( V_87 -> V_160 . V_74 ) ,
V_293 ) ;
V_215 = ( void * ) V_87 -> V_255 ;
memcpy ( V_245 , V_215 , V_294 ) ;
V_215 = ( void * ) V_245 ;
if ( F_86 ( V_215 -> V_219 ) ) {
V_286 = F_87 ( V_215 ) ;
V_286 [ 0 ] &= ~ V_295 ;
}
V_285 = F_113 ( V_60 ) ;
V_87 = ( void * ) V_285 -> V_36 - sizeof( * V_87 ) ;
V_37 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_287 = ! ! ( V_37 & V_296 ) ;
V_288 = ! ! ( V_37 & V_297 ) ;
V_289 = ! ! ( V_37 & V_298 ) ;
V_290 = ! ! ( V_37 & V_175 ) ;
V_235 = ( V_234 != V_104 &&
! V_287 &&
! V_288 &&
! V_290 ) ;
V_126 -> V_197 &= ~ ( V_226 |
V_227 |
V_299 |
V_241 |
V_300 |
V_244 ) ;
if ( V_287 )
V_126 -> V_197 |= V_226 ;
if ( V_289 )
V_126 -> V_197 |= V_227 ;
if ( V_291 )
V_126 -> V_197 |= V_300 ;
if ( V_235 ) {
V_126 -> V_197 |= V_299 ;
if ( F_114 ( ! V_291 ) )
V_126 -> V_197 |= V_244 ;
if ( V_284 )
V_126 -> V_197 |= V_242 |
V_243 ;
else
V_126 -> V_197 |= V_241 ;
}
F_115 (amsdu, msdu) {
F_111 ( V_55 ) ;
F_109 ( V_3 , V_55 , V_126 , V_245 , V_234 ,
V_235 ) ;
if ( ! V_235 )
continue;
if ( V_291 )
continue;
if ( V_284 )
continue;
V_215 = ( void * ) V_55 -> V_36 ;
V_215 -> V_219 &= ~ F_116 ( V_301 ) ;
}
}
static void F_117 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_125 * V_126 )
{
struct V_1 * V_55 ;
struct V_1 * V_302 ;
V_302 = F_84 ( V_60 ) ;
while ( ( V_55 = F_118 ( V_60 ) ) ) {
if ( F_52 ( V_60 ) )
V_126 -> V_197 &= ~ V_228 ;
else
V_126 -> V_197 |= V_228 ;
if ( V_55 == V_302 ) {
V_302 = NULL ;
V_126 -> V_197 &= ~ V_303 ;
} else {
V_126 -> V_197 |= V_303 ;
}
F_88 ( V_3 , V_126 , V_55 ) ;
}
}
static int F_119 ( struct V_59 * V_60 )
{
struct V_1 * V_9 , * V_203 ;
int V_304 ;
int V_305 = 0 ;
V_203 = F_118 ( V_60 ) ;
F_115 (amsdu, skb)
V_305 += V_9 -> V_16 ;
V_304 = V_305 - F_8 ( V_203 ) ;
if ( ( V_304 > 0 ) &&
( F_120 ( V_203 , 0 , V_304 , V_306 ) < 0 ) ) {
F_121 ( V_60 , V_203 ) ;
return - 1 ;
}
while ( ( V_9 = F_118 ( V_60 ) ) ) {
F_122 ( V_9 , F_47 ( V_203 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_121 ( V_60 , V_203 ) ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_1 * V_203 ;
struct V_24 * V_87 ;
enum V_262 V_263 ;
V_203 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_203 -> V_36 - sizeof( * V_87 ) ;
V_263 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_137 ) ,
V_264 ) ;
if ( V_263 != V_265 ||
F_124 ( V_60 ) != 1 + V_87 -> V_76 . V_77 ) {
F_45 ( V_60 ) ;
return;
}
F_119 ( V_60 ) ;
}
static bool F_125 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_125 * V_222 )
{
if ( ! V_222 -> V_143 ) {
F_64 ( V_3 , V_307 , L_25 ) ;
return false ;
}
if ( F_98 ( V_308 , & V_3 -> V_309 ) ) {
F_64 ( V_3 , V_307 , L_26 ) ;
return false ;
}
return true ;
}
static void F_126 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_125 * V_222 )
{
if ( F_52 ( V_60 ) )
return;
if ( F_125 ( V_3 , V_60 , V_222 ) )
return;
F_45 ( V_60 ) ;
}
static int F_127 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_125 * V_222 = & V_8 -> V_222 ;
struct V_59 V_60 ;
int V_26 , V_310 ;
F_128 ( & V_60 ) ;
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
V_310 = F_124 ( & V_60 ) ;
F_83 ( V_3 , & V_60 , V_222 , 0xffff ) ;
if ( V_26 > 0 )
F_123 ( V_3 , & V_60 ) ;
F_126 ( V_3 , & V_60 , V_222 ) ;
F_112 ( V_3 , & V_60 , V_222 , true ) ;
F_117 ( V_3 , & V_60 , V_222 ) ;
return V_310 ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_311 * V_312 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_313 * V_314 ;
int V_315 ;
int V_12 , V_316 = 0 ;
V_315 = F_49 ( F_15 ( V_312 -> V_215 . V_137 ) ,
V_317 ) ;
V_314 = F_130 ( V_312 ) ;
F_43 ( V_3 , V_58 , NULL , L_28 ,
V_312 , sizeof( * V_312 ) +
( sizeof( struct V_313 ) *
V_315 ) ) ;
for ( V_12 = 0 ; V_12 < V_315 ; V_12 ++ )
V_316 += V_314 [ V_12 ] . V_316 ;
F_131 ( V_316 , & V_8 -> V_101 ) ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_318 * V_319 = (struct V_318 * ) V_9 -> V_36 ;
struct V_320 V_321 = {} ;
int V_126 = F_49 ( V_319 -> V_322 . V_38 , V_323 ) ;
T_6 V_324 ;
int V_12 ;
switch ( V_126 ) {
case V_325 :
V_321 . V_126 = V_326 ;
break;
case V_327 :
V_321 . V_126 = V_328 ;
break;
case V_329 :
case V_330 :
case V_331 :
V_321 . V_126 = V_332 ;
break;
default:
F_42 ( V_3 , L_29 , V_126 ) ;
V_321 . V_126 = V_332 ;
break;
}
F_64 ( V_3 , V_307 , L_30 ,
V_319 -> V_322 . V_310 ) ;
for ( V_12 = 0 ; V_12 < V_319 -> V_322 . V_310 ; V_12 ++ ) {
V_324 = V_319 -> V_322 . V_333 [ V_12 ] ;
V_321 . V_324 = F_55 ( V_324 ) ;
if ( ! F_133 ( & V_8 -> V_334 , V_321 ) ) {
F_42 ( V_3 , L_31 ,
V_321 . V_324 , V_321 . V_126 ) ;
F_134 ( V_8 , & V_321 ) ;
}
}
}
static void F_135 ( struct V_2 * V_3 , struct V_318 * V_319 )
{
struct V_335 * V_82 = & V_319 -> V_336 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
T_5 V_74 , V_218 , V_173 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_218 = F_49 ( V_74 , V_337 ) ;
V_173 = F_49 ( V_74 , V_338 ) ;
F_64 ( V_3 , V_307 ,
L_32 ,
V_218 , V_173 , V_82 -> V_339 ) ;
F_29 ( & V_3 -> V_174 ) ;
V_168 = F_71 ( V_3 , V_173 ) ;
if ( ! V_168 ) {
F_42 ( V_3 , L_33 ,
V_173 ) ;
F_33 ( & V_3 -> V_174 ) ;
return;
}
V_170 = F_72 ( V_3 , V_168 -> V_178 ) ;
if ( ! V_170 ) {
F_42 ( V_3 , L_34 ,
V_168 -> V_178 ) ;
F_33 ( & V_3 -> V_174 ) ;
return;
}
F_64 ( V_3 , V_307 ,
L_35 ,
V_168 -> V_340 , V_218 , V_82 -> V_339 ) ;
F_136 ( V_170 -> V_179 , V_168 -> V_340 , V_218 ) ;
F_33 ( & V_3 -> V_174 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_318 * V_319 )
{
struct V_341 * V_82 = & V_319 -> V_342 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
T_5 V_74 , V_218 , V_173 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_218 = F_49 ( V_74 , V_337 ) ;
V_173 = F_49 ( V_74 , V_338 ) ;
F_64 ( V_3 , V_307 ,
L_36 ,
V_218 , V_173 ) ;
F_29 ( & V_3 -> V_174 ) ;
V_168 = F_71 ( V_3 , V_173 ) ;
if ( ! V_168 ) {
F_42 ( V_3 , L_33 ,
V_173 ) ;
F_33 ( & V_3 -> V_174 ) ;
return;
}
V_170 = F_72 ( V_3 , V_168 -> V_178 ) ;
if ( ! V_170 ) {
F_42 ( V_3 , L_34 ,
V_168 -> V_178 ) ;
F_33 ( & V_3 -> V_174 ) ;
return;
}
F_64 ( V_3 , V_307 ,
L_37 ,
V_168 -> V_340 , V_218 ) ;
F_138 ( V_170 -> V_179 , V_168 -> V_340 , V_218 ) ;
F_33 ( & V_3 -> V_174 ) ;
}
static int F_139 ( struct V_59 * V_83 ,
struct V_59 * V_60 )
{
struct V_1 * V_55 ;
struct V_24 * V_87 ;
if ( F_52 ( V_83 ) )
return - V_343 ;
if ( F_140 ( ! F_52 ( V_60 ) ) )
return - V_96 ;
while ( ( V_55 = F_118 ( V_83 ) ) ) {
F_46 ( V_60 , V_55 ) ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
if ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) )
break;
}
V_55 = F_113 ( V_60 ) ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
if ( ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ) {
F_141 ( V_60 , V_83 ) ;
return - V_344 ;
}
return 0 ;
}
static void F_142 ( struct V_125 * V_126 ,
struct V_1 * V_9 )
{
struct V_214 * V_215 = (struct V_214 * ) V_9 -> V_36 ;
if ( ! F_143 ( V_215 -> V_219 ) )
return;
V_215 -> V_219 &= ~ F_116 ( V_301 ) ;
V_126 -> V_197 |= V_299 |
V_241 |
V_244 ;
}
static int F_144 ( struct V_2 * V_3 ,
struct V_59 * V_83 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_125 * V_126 = & V_8 -> V_222 ;
struct V_345 * V_312 ;
struct V_1 * V_55 ;
T_3 V_346 ;
int V_347 = 0 ;
while ( ( V_55 = F_118 ( V_83 ) ) ) {
V_312 = ( void * ) V_55 -> V_36 ;
F_47 ( V_55 , sizeof( * V_312 ) ) ;
F_18 ( V_55 , sizeof( * V_312 ) ) ;
if ( F_8 ( V_55 ) < F_55 ( V_312 -> V_61 ) ) {
F_42 ( V_3 , L_38 ) ;
F_10 ( V_55 ) ;
continue;
}
F_47 ( V_55 , F_55 ( V_312 -> V_61 ) ) ;
V_346 = 4 - ( ( unsigned long ) V_55 -> V_36 & 3 ) ;
F_47 ( V_55 , V_346 ) ;
memmove ( V_55 -> V_36 + V_346 , V_55 -> V_36 , V_55 -> V_16 ) ;
F_18 ( V_55 , V_346 ) ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> V_197 |= V_198 ;
F_142 ( V_126 , V_55 ) ;
F_79 ( V_3 , V_126 , NULL , V_312 -> V_178 ) ;
F_88 ( V_3 , V_126 , V_55 ) ;
V_347 ++ ;
}
return V_347 ;
}
static int F_145 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_318 * V_319 = ( void * ) V_9 -> V_36 ;
struct V_125 * V_126 = & V_8 -> V_222 ;
struct V_59 V_83 ;
struct V_59 V_60 ;
T_5 V_173 ;
T_5 V_88 ;
T_4 V_178 ;
T_4 V_218 ;
bool V_348 ;
bool V_349 ;
int V_26 , V_310 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_95 )
return - V_69 ;
F_18 ( V_9 , sizeof( V_319 -> V_215 ) ) ;
F_18 ( V_9 , sizeof( V_319 -> V_350 ) ) ;
V_173 = F_55 ( V_319 -> V_350 . V_173 ) ;
V_88 = F_55 ( V_319 -> V_350 . V_88 ) ;
V_178 = V_319 -> V_350 . V_178 ;
V_218 = F_146 ( V_319 -> V_350 . V_90 , V_351 ) ;
V_348 = ! ! ( V_319 -> V_350 . V_90 &
V_91 ) ;
V_349 = ! ! ( V_319 -> V_350 . V_90 & V_352 ) ;
F_64 ( V_3 , V_307 ,
L_39 ,
V_178 , V_173 , V_218 , V_348 , V_349 , V_88 ) ;
if ( V_9 -> V_16 < V_88 * sizeof( * V_319 -> V_350 . V_86 ) ) {
F_42 ( V_3 , L_40 ) ;
return - V_96 ;
}
F_128 ( & V_83 ) ;
V_26 = F_54 ( V_8 , & V_319 -> V_350 , & V_83 ) ;
if ( V_26 < 0 ) {
F_42 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_95 = true ;
return - V_69 ;
}
if ( V_348 )
V_310 = F_144 ( V_3 , & V_83 ) ;
while ( ! F_52 ( & V_83 ) ) {
F_128 ( & V_60 ) ;
V_26 = F_139 ( & V_83 , & V_60 ) ;
switch ( V_26 ) {
case 0 :
V_310 += F_124 ( & V_60 ) ;
F_83 ( V_3 , & V_60 , V_126 , V_178 ) ;
F_126 ( V_3 , & V_60 , V_126 ) ;
F_112 ( V_3 , & V_60 , V_126 , false ) ;
F_117 ( V_3 , & V_60 , V_126 ) ;
break;
case - V_344 :
default:
F_42 ( V_3 , L_42 , V_26 ) ;
V_8 -> V_95 = true ;
F_45 ( & V_83 ) ;
return - V_69 ;
}
}
return V_310 ;
}
static void F_147 ( struct V_2 * V_3 ,
const T_7 * V_353 ,
int V_354 )
{
int V_12 ;
T_1 V_355 ;
F_64 ( V_3 , V_307 , L_43 ,
V_354 ) ;
for ( V_12 = 0 ; V_12 < V_354 ; V_12 ++ ) {
V_355 = F_148 ( V_353 [ V_12 ] ) ;
F_64 ( V_3 , V_307 , L_44 ,
V_355 ) ;
}
}
static void F_149 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_181 * V_182 = V_3 -> V_182 ;
struct V_356 * V_357 ;
struct V_318 * V_319 = (struct V_318 * ) V_9 -> V_36 ;
struct V_358 * V_359 ;
T_3 V_16 ;
T_3 V_360 ;
T_3 V_361 ;
T_3 V_362 ;
T_3 V_310 ;
const T_7 * V_353 ;
T_5 V_363 ;
T_5 V_354 ;
T_5 V_173 ;
T_4 V_218 ;
int V_26 ;
int V_12 ;
F_64 ( V_3 , V_307 , L_45 ) ;
V_16 = sizeof( V_319 -> V_215 ) + sizeof( V_319 -> V_364 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_46 ) ;
return;
}
V_363 = F_150 ( V_319 -> V_364 . V_363 ) ;
V_354 = F_150 ( V_319 -> V_364 . V_354 ) ;
V_16 += sizeof( V_319 -> V_364 . V_365 [ 0 ] ) * V_363 ;
V_16 += sizeof( V_319 -> V_364 . V_353 [ 0 ] ) * V_354 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_47 ) ;
return;
}
F_64 ( V_3 , V_307 , L_48 ,
V_363 , V_354 ,
F_150 ( V_319 -> V_364 . V_366 ) ) ;
if ( ! V_3 -> V_8 . V_367 . V_368 ) {
F_42 ( V_3 , L_49 ) ;
return;
}
if ( V_3 -> V_8 . V_367 . V_369 == V_370 ) {
F_42 ( V_3 , L_50 ) ;
return;
}
F_151 () ;
for ( V_12 = 0 ; V_12 < V_363 ; V_12 ++ ) {
V_359 = & V_319 -> V_364 . V_365 [ V_12 ] ;
V_173 = F_49 ( F_150 ( V_359 -> V_90 ) ,
V_371 ) ;
V_218 = F_49 ( F_150 ( V_359 -> V_90 ) ,
V_372 ) ;
V_361 = F_150 ( V_359 -> V_310 ) ;
V_360 = F_148 ( V_359 -> V_362 ) ;
F_64 ( V_3 , V_307 , L_51 ,
V_12 , V_173 , V_218 , V_361 , V_360 ) ;
if ( F_22 ( V_173 >= V_3 -> V_8 . V_367 . V_373 ) ||
F_22 ( V_218 >= V_3 -> V_8 . V_367 . V_374 ) ) {
F_42 ( V_3 , L_52 ,
V_173 , V_218 ) ;
continue;
}
F_29 ( & V_3 -> V_174 ) ;
V_357 = F_152 ( V_3 , V_173 , V_218 ) ;
F_33 ( & V_3 -> V_174 ) ;
if ( F_22 ( ! V_357 ) ) {
F_42 ( V_3 , L_53 ,
V_173 , V_218 ) ;
continue;
}
V_310 = 0 ;
V_362 = 0 ;
while ( V_310 < V_361 &&
V_362 < V_360 ) {
V_26 = F_153 ( V_182 , V_357 ) ;
if ( V_26 < 0 )
break;
V_310 ++ ;
V_362 += V_26 ;
}
V_359 -> V_310 = F_154 ( V_310 ) ;
V_359 -> V_362 = F_155 ( V_362 ) ;
F_156 ( V_182 , V_357 ) ;
}
F_157 () ;
V_353 = F_158 ( & V_319 -> V_364 ) ;
F_147 ( V_3 , V_353 , V_354 ) ;
V_26 = F_159 ( V_3 ,
V_319 -> V_364 . V_375 ,
V_319 -> V_364 . V_366 ,
V_319 -> V_364 . V_365 ,
V_363 ) ;
if ( F_22 ( V_26 ) ) {
F_42 ( V_3 , L_54 ,
F_148 ( V_319 -> V_364 . V_375 ) , V_26 ) ;
}
F_160 ( V_3 ) ;
}
static void F_161 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_318 * V_319 = ( void * ) V_9 -> V_36 ;
T_3 V_16 ;
int V_354 ;
F_64 ( V_3 , V_307 , L_55 ) ;
V_16 = sizeof( V_319 -> V_215 ) + sizeof( V_319 -> V_376 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_56 ) ;
return;
}
V_354 = F_150 ( V_319 -> V_376 . V_354 ) ;
V_16 += sizeof( V_319 -> V_376 . V_353 [ 0 ] ) * V_354 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_57 ) ;
return;
}
F_147 ( V_3 ,
V_319 -> V_376 . V_353 ,
V_354 ) ;
}
static void F_162 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_318 * V_319 = ( void * ) V_9 -> V_36 ;
const struct V_377 * V_359 ;
struct V_356 * V_357 ;
struct V_378 * V_379 ;
T_3 V_16 ;
T_3 V_363 ;
enum V_380 V_369 ;
bool V_381 ;
T_5 V_74 ;
T_5 V_137 ;
T_5 V_382 ;
T_5 V_173 ;
T_4 V_218 ;
int V_12 ;
F_64 ( V_3 , V_307 , L_58 ) ;
V_16 = sizeof( V_319 -> V_215 ) + sizeof( V_319 -> V_383 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_59 ) ;
return;
}
V_74 = F_150 ( V_319 -> V_383 . V_74 ) ;
V_137 = F_150 ( V_319 -> V_383 . V_137 ) ;
V_381 = ! ! ( V_74 & V_384 ) ;
V_363 = F_49 ( V_74 , V_385 ) ;
V_369 = F_49 ( V_137 , V_386 ) ;
V_382 = F_49 ( V_137 , V_385 ) ;
F_64 ( V_3 , V_307 ,
L_60 ,
V_74 , V_137 , V_381 , V_363 , V_369 , V_382 ) ;
V_16 += sizeof( V_319 -> V_383 . V_365 [ 0 ] ) * V_363 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_61 ) ;
return;
}
switch ( V_369 ) {
case V_370 :
case V_387 :
break;
default:
F_42 ( V_3 , L_62 ,
V_369 ) ;
return;
}
if ( ! V_381 )
return;
V_3 -> V_8 . V_367 . V_368 = V_381 ;
V_3 -> V_8 . V_367 . V_369 = V_369 ;
V_3 -> V_8 . V_367 . V_388 = V_382 ;
F_151 () ;
for ( V_12 = 0 ; V_12 < V_363 ; V_12 ++ ) {
V_359 = & V_319 -> V_383 . V_365 [ V_12 ] ;
V_74 = F_150 ( V_359 -> V_74 ) ;
V_173 = F_49 ( V_74 , V_389 ) ;
V_218 = F_49 ( V_74 , V_390 ) ;
if ( F_22 ( V_173 >= V_3 -> V_8 . V_367 . V_373 ) ||
F_22 ( V_218 >= V_3 -> V_8 . V_367 . V_374 ) ) {
F_42 ( V_3 , L_52 ,
V_173 , V_218 ) ;
continue;
}
F_29 ( & V_3 -> V_174 ) ;
V_357 = F_152 ( V_3 , V_173 , V_218 ) ;
F_33 ( & V_3 -> V_174 ) ;
if ( F_22 ( ! V_357 ) ) {
F_42 ( V_3 , L_53 ,
V_173 , V_218 ) ;
continue;
}
F_29 ( & V_3 -> V_8 . V_391 ) ;
V_379 = ( void * ) V_357 -> V_392 ;
V_379 -> V_388 = F_150 ( V_359 -> V_393 ) ;
F_33 ( & V_3 -> V_8 . V_391 ) ;
}
F_157 () ;
F_163 ( V_3 ) ;
}
void F_164 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
bool V_394 ;
V_394 = F_165 ( V_3 , V_9 ) ;
if ( V_394 )
F_10 ( V_9 ) ;
}
static inline bool F_166 ( T_4 V_130 )
{
static const T_4 V_395 [] = { 1 , 2 , 5 , 11 , 6 , 9 , 12 ,
18 , 24 , 36 , 48 , 54 } ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_167 ( V_395 ) ; V_12 ++ ) {
if ( V_130 == V_395 [ V_12 ] )
return true ;
}
return false ;
}
static void
F_168 ( struct V_2 * V_3 ,
struct V_396 * V_397 ,
struct V_398 * V_399 )
{
struct V_400 * V_401 = (struct V_400 * ) V_397 -> V_392 ;
T_4 V_130 = 0 , V_132 ;
struct V_402 V_403 ;
F_27 ( & V_3 -> V_174 ) ;
V_403 . V_38 = F_169 ( V_399 -> V_404 ) ;
V_403 . V_131 = F_170 ( V_399 -> V_38 ) ;
V_403 . V_134 = F_171 ( V_399 -> V_404 ) ;
V_403 . V_133 = F_172 ( V_399 -> V_404 ) ;
V_132 = F_173 ( V_399 -> V_38 ) ;
if ( V_403 . V_38 == V_405 && V_403 . V_133 > 9 ) {
F_42 ( V_3 , L_63 , V_403 . V_133 ) ;
return;
}
if ( V_403 . V_38 == V_406 &&
( V_403 . V_133 > 7 || V_403 . V_134 < 1 ) ) {
F_42 ( V_3 , L_64 ,
V_403 . V_133 , V_403 . V_134 ) ;
return;
}
memset ( & V_401 -> V_403 , 0 , sizeof( V_401 -> V_403 ) ) ;
if ( V_403 . V_38 == V_407 ||
V_403 . V_38 == V_408 ) {
V_130 = F_174 ( V_399 -> V_404 ) ;
if ( ! F_166 ( V_130 ) ) {
F_42 ( V_3 , L_65 ,
V_130 ) ;
return;
}
V_130 *= 10 ;
if ( V_130 == 60 && V_403 . V_38 == V_407 )
V_130 = V_130 - 5 ;
V_401 -> V_403 . V_409 = V_130 ;
} else if ( V_403 . V_38 == V_406 ) {
V_401 -> V_403 . V_38 = V_410 ;
V_401 -> V_403 . V_133 = V_403 . V_133 + 8 * ( V_403 . V_134 - 1 ) ;
} else {
V_401 -> V_403 . V_38 = V_411 ;
V_401 -> V_403 . V_133 = V_403 . V_133 ;
}
if ( V_132 )
V_401 -> V_403 . V_38 |= V_412 ;
V_401 -> V_403 . V_134 = V_403 . V_134 ;
V_401 -> V_403 . V_131 = V_403 . V_131 + V_209 ;
}
static void F_175 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_318 * V_319 = (struct V_318 * ) V_9 -> V_36 ;
struct V_398 * V_413 = & V_3 -> V_414 ;
struct V_415 * V_416 ;
struct V_396 * V_397 ;
struct V_167 * V_168 ;
int V_173 , V_12 ;
T_4 V_417 , V_418 ;
V_418 = V_319 -> V_414 . V_418 ;
V_417 = V_319 -> V_414 . V_417 * sizeof( T_7 ) ;
if ( V_9 -> V_16 < sizeof( struct V_419 ) + V_418 * V_417 ) {
F_42 ( V_3 , L_66 , V_9 -> V_16 ) ;
return;
}
V_416 = (struct V_415 * )
( V_319 -> V_414 . V_420 ) ;
V_173 = F_55 ( V_416 -> V_173 ) ;
F_151 () ;
F_29 ( & V_3 -> V_174 ) ;
V_168 = F_71 ( V_3 , V_173 ) ;
if ( ! V_168 ) {
F_42 ( V_3 , L_67 ,
V_173 ) ;
goto V_216;
}
V_397 = V_168 -> V_397 ;
for ( V_12 = 0 ; V_12 < V_418 ; V_12 ++ ) {
V_416 = (struct V_415 * )
( V_319 -> V_414 . V_420 + V_12 * V_417 ) ;
V_413 -> V_421 = F_15 ( V_416 -> V_421 ) ;
V_413 -> V_422 = F_15 ( V_416 -> V_422 ) ;
V_413 -> V_423 =
F_15 ( V_416 -> V_423 ) ;
V_413 -> V_404 = V_416 -> V_404 ;
V_413 -> V_38 = V_416 -> V_38 ;
V_413 -> V_424 = F_55 ( V_416 -> V_424 ) ;
V_413 -> V_425 = F_55 ( V_416 -> V_425 ) ;
V_413 -> V_426 = F_55 ( V_416 -> V_426 ) ;
F_168 ( V_3 , V_397 , V_413 ) ;
}
V_216:
F_33 ( & V_3 -> V_174 ) ;
F_157 () ;
}
bool F_165 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_318 * V_319 = (struct V_318 * ) V_9 -> V_36 ;
enum V_427 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_42 ( V_3 , L_68 ) ;
F_64 ( V_3 , V_307 , L_69 ,
V_319 -> V_215 . V_428 ) ;
if ( V_319 -> V_215 . V_428 >= V_3 -> V_8 . V_429 ) {
F_64 ( V_3 , V_307 , L_70 ,
V_319 -> V_215 . V_428 , V_3 -> V_8 . V_429 ) ;
return true ;
}
type = V_3 -> V_8 . V_430 [ V_319 -> V_215 . V_428 ] ;
switch ( type ) {
case V_431 : {
V_8 -> V_432 = V_319 -> V_433 . V_434 ;
V_8 -> V_435 = V_319 -> V_433 . V_436 ;
F_176 ( & V_8 -> V_437 ) ;
break;
}
case V_438 :
F_129 ( V_8 , & V_319 -> V_439 ) ;
break;
case V_440 : {
struct V_441 V_82 = {
. V_178 = V_319 -> V_442 . V_178 ,
. V_173 = F_55 ( V_319 -> V_442 . V_173 ) ,
} ;
memcpy ( V_82 . V_340 , V_319 -> V_442 . V_340 , sizeof( V_82 . V_340 ) ) ;
F_177 ( V_8 , & V_82 ) ;
break;
}
case V_443 : {
struct V_444 V_82 = {
. V_173 = F_55 ( V_319 -> V_445 . V_173 ) ,
} ;
F_178 ( V_8 , & V_82 ) ;
break;
}
case V_446 : {
struct V_320 V_321 = {} ;
int V_126 = F_15 ( V_319 -> V_447 . V_126 ) ;
V_321 . V_324 = F_15 ( V_319 -> V_447 . V_448 ) ;
switch ( V_126 ) {
case V_449 :
V_321 . V_126 = V_328 ;
break;
case V_450 :
V_321 . V_126 = V_326 ;
break;
case V_451 :
V_321 . V_126 = V_332 ;
break;
}
V_126 = F_134 ( V_8 , & V_321 ) ;
if ( ! V_126 ) {
F_29 ( & V_8 -> V_391 ) ;
F_179 ( V_8 ) ;
F_33 ( & V_8 -> V_391 ) ;
}
break;
}
case V_452 :
F_132 ( V_8 -> V_3 , V_9 ) ;
break;
case V_453 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_454 * V_82 = & V_319 -> V_455 ;
F_64 ( V_3 , V_307 ,
L_71 ,
F_55 ( V_82 -> V_173 ) ,
! ! ( V_82 -> V_38 & V_456 ) ,
F_49 ( V_82 -> V_38 , V_457 ) ) ;
F_176 ( & V_3 -> V_458 ) ;
break;
}
case V_459 : {
F_43 ( V_3 , V_58 , NULL , L_72 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_180 ( & V_8 -> V_101 ) ;
break;
}
case V_460 :
break;
case V_461 :
F_181 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_462 :
F_42 ( V_3 , L_73 ) ;
break;
case V_463 :
F_135 ( V_3 , V_319 ) ;
break;
case V_464 :
F_137 ( V_3 , V_319 ) ;
break;
case V_465 : {
F_182 ( V_3 , V_319 -> V_466 . V_420 ,
V_9 -> V_16 -
F_48 ( struct V_318 ,
V_466 . V_420 ) ) ;
break;
}
case V_467 : {
break;
}
case V_468 : {
F_46 ( & V_8 -> V_52 , V_9 ) ;
return false ;
}
case V_469 :
break;
case V_470 : {
T_1 V_471 = F_15 ( V_319 -> V_472 . V_471 ) ;
T_1 V_143 = F_15 ( V_319 -> V_472 . V_143 ) ;
V_3 -> V_188 = F_183 ( V_3 -> V_182 -> V_473 , V_143 ) ;
F_64 ( V_3 , V_307 ,
L_74 ,
V_143 , F_184 ( V_471 ) ) ;
break;
}
case V_474 :
break;
case V_475 : {
struct V_1 * V_364 = F_185 ( V_9 , V_306 ) ;
if ( ! V_364 ) {
F_42 ( V_3 , L_75 ) ;
break;
}
F_186 ( & V_8 -> V_53 , V_364 ) ;
break;
}
case V_476 :
F_161 ( V_3 , V_9 ) ;
break;
case V_477 :
F_162 ( V_3 , V_9 ) ;
break;
case V_478 :
F_175 ( V_3 , V_9 ) ;
break;
case V_479 :
default:
F_42 ( V_3 , L_76 ,
V_319 -> V_215 . V_428 ) ;
F_43 ( V_3 , V_58 , NULL , L_72 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
}
return true ;
}
void F_187 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
F_182 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
int F_188 ( struct V_2 * V_3 , int V_480 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_320 V_321 = {} ;
struct V_59 V_481 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
int V_482 = 0 , V_483 , V_484 ;
bool V_485 = false ;
F_128 ( & V_481 ) ;
while ( V_482 < V_480 ) {
if ( F_52 ( & V_8 -> V_52 ) )
break;
V_9 = F_118 ( & V_8 -> V_52 ) ;
if ( ! V_9 ) {
V_485 = true ;
goto exit;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_484 = F_145 ( V_3 , V_9 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_484 < 0 ) {
V_485 = true ;
goto exit;
}
F_10 ( V_9 ) ;
if ( V_484 > 0 )
V_482 += V_484 ;
if ( ( V_482 > V_486 ) &&
! F_52 ( & V_8 -> V_52 ) ) {
V_485 = true ;
goto exit;
}
}
while ( V_482 < V_480 ) {
if ( ! F_189 ( & V_8 -> V_101 ) )
break;
V_484 = F_127 ( V_8 ) ;
if ( V_484 < 0 ) {
V_485 = true ;
goto exit;
}
V_482 += V_484 ;
F_190 ( & V_8 -> V_101 ) ;
if ( ( V_482 > V_486 ) &&
F_189 ( & V_8 -> V_101 ) ) {
V_485 = true ;
goto exit;
}
}
if ( ( V_482 < V_480 ) && ! F_191 ( & V_8 -> V_334 ) )
V_482 = V_480 ;
while ( F_192 ( & V_8 -> V_334 , & V_321 ) )
F_134 ( V_8 , & V_321 ) ;
F_163 ( V_3 ) ;
F_193 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_141 ( & V_8 -> V_53 , & V_481 ) ;
F_194 ( & V_8 -> V_53 . V_41 , V_38 ) ;
while ( ( V_9 = F_118 ( & V_481 ) ) ) {
F_149 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
exit:
F_28 ( V_8 ) ;
V_483 = V_485 ? V_480 : V_482 ;
return V_483 ;
}
