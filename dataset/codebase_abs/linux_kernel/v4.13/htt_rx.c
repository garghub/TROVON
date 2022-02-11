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
V_119 -> V_146 = V_147 ;
if ( V_125 )
V_119 -> V_148 |= V_149 ;
if ( V_124 )
V_119 -> V_124 = V_150 ;
break;
case V_151 :
case V_152 :
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
F_15 ( V_87 -> V_153 . V_74 ) ,
F_15 ( V_87 -> V_153 . V_130 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_87 -> V_133 . V_74 ,
F_15 ( V_87 -> V_133 . V_130 ) ,
F_15 ( V_87 -> V_133 . V_131 ) ,
F_15 ( V_87 -> V_133 . V_132 ) ,
F_15 ( V_87 -> V_133 . V_154 ) ) ;
F_42 ( V_3 , L_9 ,
F_15 ( V_87 -> V_79 . V_73 . V_74 ) ,
F_15 ( V_87 -> V_155 . V_74 ) ) ;
F_43 ( V_3 , V_58 , NULL ,
L_10 ,
V_87 -> V_67 , 50 ) ;
}
V_119 -> V_143 = V_126 ;
V_119 -> V_127 = V_127 ;
if ( V_125 )
V_119 -> V_148 |= V_149 ;
switch ( V_124 ) {
case 0 :
break;
case 1 :
V_119 -> V_124 = V_150 ;
break;
case 2 :
V_119 -> V_124 = V_156 ;
break;
case 3 :
V_119 -> V_124 = V_157 ;
break;
}
V_119 -> V_146 = V_158 ;
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
V_166 = F_49 ( F_15 ( V_87 -> V_153 . V_74 ) ,
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
int V_12 ;
for ( V_12 = 0 ; V_12 < V_183 ; V_12 ++ ) {
V_119 -> V_184 &= ~ F_81 ( V_12 ) ;
if ( V_87 -> V_133 . V_185 [ V_12 ] . V_186 != 0x80 ) {
V_119 -> V_187 [ V_12 ] = V_188 +
V_87 -> V_133 . V_185 [ V_12 ] . V_186 ;
V_119 -> V_184 |= F_81 ( V_12 ) ;
}
}
V_119 -> signal = V_188 +
V_87 -> V_133 . V_189 ;
V_119 -> V_190 &= ~ V_191 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_24 * V_87 )
{
V_119 -> V_192 = F_15 ( V_87 -> V_193 . V_73 . V_194 ) ;
V_119 -> V_190 |= V_195 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 ,
T_1 V_171 )
{
struct V_1 * V_196 ;
struct V_24 * V_87 ;
bool V_197 ;
bool V_198 ;
if ( F_52 ( V_60 ) )
return;
V_196 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_196 -> V_36 - sizeof( * V_87 ) ;
V_197 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_199 ) ) ;
V_198 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_200 ) ) ;
if ( V_197 ) {
V_119 -> V_136 = 0 ;
V_119 -> V_143 = 0 ;
V_119 -> V_127 = 0 ;
V_119 -> V_146 = V_201 ;
V_119 -> V_124 = V_202 ;
V_119 -> V_190 &= ~ V_195 ;
V_119 -> V_190 |= V_191 ;
F_80 ( V_3 , V_119 , V_87 ) ;
F_79 ( V_3 , V_119 , V_87 , V_171 ) ;
F_67 ( V_3 , V_119 , V_87 ) ;
}
if ( V_198 )
F_82 ( V_3 , V_119 , V_87 ) ;
}
static char * F_85 ( struct V_203 * V_204 , char * V_205 , T_3 V_19 )
{
T_4 * V_206 ;
int V_207 ;
if ( ! F_86 ( V_204 -> V_208 ) )
return L_11 ;
V_206 = F_87 ( V_204 ) ;
V_207 = * V_206 & V_209 ;
if ( V_207 < 8 )
snprintf ( V_205 , V_19 , L_12 , V_207 , V_210 [ V_207 ] ) ;
else
snprintf ( V_205 , V_19 , L_13 , V_207 ) ;
return V_205 ;
}
static void F_88 ( struct V_2 * V_3 ,
struct V_118 * V_211 ,
struct V_1 * V_9 )
{
struct V_118 * V_119 ;
struct V_203 * V_204 = (struct V_203 * ) V_9 -> V_36 ;
char V_207 [ 32 ] ;
V_119 = F_89 ( V_9 ) ;
* V_119 = * V_211 ;
F_64 ( V_3 , V_212 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_90 ( V_204 ) ,
F_85 ( V_204 , V_207 , sizeof( V_207 ) ) ,
F_91 ( F_92 ( V_204 ) ) ?
L_15 : L_16 ,
( F_55 ( V_204 -> V_213 ) & V_214 ) >> 4 ,
( V_119 -> V_146 == V_201 ) ? L_17 : L_11 ,
( V_119 -> V_146 == V_147 ) ? L_18 : L_11 ,
( V_119 -> V_146 == V_158 ) ? L_19 : L_11 ,
( V_119 -> V_124 == V_150 ) ? L_20 : L_11 ,
( V_119 -> V_124 == V_156 ) ? L_21 : L_11 ,
( V_119 -> V_124 == V_157 ) ? L_22 : L_11 ,
V_119 -> V_148 & V_149 ? L_23 : L_11 ,
V_119 -> V_143 ,
V_119 -> V_127 ,
V_119 -> V_136 ,
V_119 -> V_142 , V_119 -> V_190 ,
! ! ( V_119 -> V_190 & V_215 ) ,
! ! ( V_119 -> V_190 & V_216 ) ,
! ! ( V_119 -> V_190 & V_217 ) ) ;
F_43 ( V_3 , V_58 , NULL , L_24 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_93 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_94 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_95 ( V_3 -> V_175 , NULL , V_9 , & V_3 -> V_218 ) ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_203 * V_204 )
{
int V_16 = F_97 ( V_204 -> V_208 ) ;
if ( ! F_98 ( V_219 ,
V_3 -> V_220 -> V_221 . V_222 ) )
V_16 = F_99 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_100 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
enum V_103 V_223 ,
bool V_224 )
{
struct V_203 * V_204 ;
struct V_24 * V_87 ;
T_3 V_225 ;
T_3 V_226 ;
bool V_227 ;
bool V_228 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_227 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_169 ) ) ;
V_228 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
if ( F_22 ( F_4 ( ! V_227 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_227 && V_228 ) ) ) )
return;
F_50 ( V_55 , V_55 -> V_16 - V_229 ) ;
if ( ! V_224 )
return;
V_204 = ( void * ) V_55 -> V_36 ;
if ( V_119 -> V_190 & V_230 )
F_50 ( V_55 , V_55 -> V_16 -
F_66 ( V_3 , V_223 ) ) ;
if ( ( V_119 -> V_190 & V_231 ) &&
! F_101 ( V_204 -> V_208 ) &&
V_223 == V_109 )
F_50 ( V_55 , V_55 -> V_16 - 8 ) ;
if ( V_119 -> V_190 & V_230 ) {
V_225 = F_97 ( V_204 -> V_208 ) ;
V_226 = F_65 ( V_3 , V_223 ) ;
memmove ( ( void * ) V_55 -> V_36 + V_226 ,
( void * ) V_55 -> V_36 , V_225 ) ;
F_18 ( V_55 , V_226 ) ;
}
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_232 [ 64 ] )
{
struct V_203 * V_204 ;
struct V_24 * V_87 ;
T_3 V_225 ;
T_4 V_233 [ V_234 ] ;
T_4 V_235 [ V_234 ] ;
int V_236 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_236 = F_103 ( & V_3 -> V_237 , V_87 ) ;
F_47 ( V_55 , V_236 ) ;
V_204 = (struct V_203 * ) ( V_55 -> V_36 + V_236 ) ;
V_225 = F_96 ( V_3 , V_204 ) ;
F_104 ( V_233 , F_92 ( V_204 ) ) ;
F_104 ( V_235 , F_90 ( V_204 ) ) ;
F_18 ( V_55 , V_225 ) ;
V_204 = (struct V_203 * ) V_232 ;
V_225 = F_97 ( V_204 -> V_208 ) ;
memcpy ( F_105 ( V_55 , V_225 ) , V_204 , V_225 ) ;
V_204 = (struct V_203 * ) V_55 -> V_36 ;
F_104 ( F_92 ( V_204 ) , V_233 ) ;
F_104 ( F_90 ( V_204 ) , V_235 ) ;
}
static void * F_106 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
enum V_103 V_223 )
{
struct V_203 * V_204 ;
struct V_24 * V_87 ;
T_3 V_225 , V_226 ;
void * V_238 ;
bool V_227 , V_228 , V_239 ;
int V_240 = V_3 -> V_237 . V_241 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_204 = ( void * ) V_87 -> V_242 ;
V_227 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_169 ) ) ;
V_228 = ! ! ( V_87 -> V_79 . V_73 . V_74 &
F_20 ( V_80 ) ) ;
V_239 = ! ( V_227 && V_228 ) ;
V_238 = V_204 ;
if ( V_227 ) {
V_225 = F_97 ( V_204 -> V_208 ) ;
V_226 = F_65 ( V_3 , V_223 ) ;
V_238 += F_99 ( V_225 , V_240 ) +
F_99 ( V_226 , V_240 ) ;
}
if ( V_239 )
V_238 += sizeof( struct V_243 ) ;
return V_238 ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_232 [ 64 ] ,
enum V_103 V_223 )
{
struct V_203 * V_204 ;
struct V_244 * V_245 ;
T_3 V_225 ;
void * V_238 ;
T_4 V_233 [ V_234 ] ;
T_4 V_235 [ V_234 ] ;
int V_236 ;
struct V_24 * V_87 ;
V_238 = F_106 ( V_3 , V_55 , V_223 ) ;
if ( F_4 ( ! V_238 ) )
return;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_236 = F_103 ( & V_3 -> V_237 , V_87 ) ;
F_47 ( V_55 , V_236 ) ;
F_18 ( V_55 , V_236 ) ;
V_245 = (struct V_244 * ) V_55 -> V_36 ;
F_104 ( V_233 , V_245 -> V_246 ) ;
F_104 ( V_235 , V_245 -> V_247 ) ;
F_18 ( V_55 , sizeof( struct V_244 ) ) ;
memcpy ( F_105 ( V_55 , sizeof( struct V_248 ) ) , V_238 ,
sizeof( struct V_248 ) ) ;
V_204 = (struct V_203 * ) V_232 ;
V_225 = F_97 ( V_204 -> V_208 ) ;
memcpy ( F_105 ( V_55 , V_225 ) , V_204 , V_225 ) ;
V_204 = (struct V_203 * ) V_55 -> V_36 ;
F_104 ( F_92 ( V_204 ) , V_233 ) ;
F_104 ( F_90 ( V_204 ) , V_235 ) ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
const T_4 V_232 [ 64 ] )
{
struct V_203 * V_204 ;
T_3 V_225 ;
int V_236 ;
struct V_24 * V_87 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_236 = F_103 ( & V_3 -> V_237 , V_87 ) ;
F_47 ( V_55 , V_236 ) ;
F_18 ( V_55 , sizeof( struct V_243 ) + V_236 ) ;
V_204 = (struct V_203 * ) V_232 ;
V_225 = F_97 ( V_204 -> V_208 ) ;
memcpy ( F_105 ( V_55 , V_225 ) , V_204 , V_225 ) ;
}
static void F_109 ( struct V_2 * V_3 ,
struct V_1 * V_55 ,
struct V_118 * V_119 ,
T_4 V_232 [ 64 ] ,
enum V_103 V_223 ,
bool V_224 )
{
struct V_24 * V_87 ;
enum V_249 V_250 ;
V_87 = ( void * ) V_55 -> V_36 - sizeof( * V_87 ) ;
V_250 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_251 ) ;
switch ( V_250 ) {
case V_252 :
F_100 ( V_3 , V_55 , V_119 , V_223 ,
V_224 ) ;
break;
case V_253 :
F_102 ( V_3 , V_55 , V_119 , V_232 ) ;
break;
case V_254 :
F_107 ( V_3 , V_55 , V_119 , V_232 , V_223 ) ;
break;
case V_255 :
F_108 ( V_3 , V_55 , V_119 , V_232 ) ;
break;
}
}
static int F_110 ( struct V_1 * V_9 )
{
struct V_24 * V_87 ;
T_1 V_38 , V_90 ;
bool V_256 , V_257 ;
bool V_258 , V_259 ;
bool V_260 , V_261 ;
V_87 = ( void * ) V_9 -> V_36 - sizeof( * V_87 ) ;
V_38 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_90 = F_15 ( V_87 -> V_72 . V_73 . V_130 ) ;
V_256 = ! ! ( V_90 & V_262 ) ;
V_257 = ! ! ( V_90 & V_263 ) ;
V_258 = ! ! ( V_90 & V_264 ) ;
V_259 = ! ! ( V_90 & V_265 ) ;
V_260 = ! ( V_38 & V_266 ) ;
V_261 = ! ( V_38 & V_267 ) ;
if ( ! V_256 && ! V_257 )
return V_268 ;
if ( ! V_258 && ! V_259 )
return V_268 ;
if ( ! V_260 )
return V_268 ;
if ( ! V_261 )
return V_268 ;
return V_269 ;
}
static void F_111 ( struct V_1 * V_55 )
{
V_55 -> V_270 = F_110 ( V_55 ) ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_196 ;
struct V_1 * V_271 ;
struct V_1 * V_55 ;
struct V_24 * V_87 ;
struct V_203 * V_204 ;
enum V_103 V_223 ;
T_4 V_232 [ 64 ] ;
T_4 * V_272 ;
T_3 V_225 ;
bool V_273 ;
bool V_274 ;
bool V_275 ;
bool V_276 ;
bool V_224 ;
bool V_277 ;
T_1 V_37 ;
if ( F_52 ( V_60 ) )
return;
V_196 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_196 -> V_36 - sizeof( * V_87 ) ;
V_277 = ! ! ( V_87 -> V_37 . V_38 &
F_20 ( V_278 ) ) ;
V_223 = F_49 ( F_15 ( V_87 -> V_153 . V_74 ) ,
V_279 ) ;
V_204 = ( void * ) V_87 -> V_242 ;
V_225 = F_97 ( V_204 -> V_208 ) ;
memcpy ( V_232 , V_204 , V_225 ) ;
V_204 = ( void * ) V_232 ;
V_272 = F_87 ( V_204 ) ;
V_272 [ 0 ] &= ~ V_280 ;
V_271 = F_113 ( V_60 ) ;
V_87 = ( void * ) V_271 -> V_36 - sizeof( * V_87 ) ;
V_37 = F_15 ( V_87 -> V_37 . V_38 ) ;
V_273 = ! ! ( V_37 & V_281 ) ;
V_274 = ! ! ( V_37 & V_282 ) ;
V_275 = ! ! ( V_37 & V_283 ) ;
V_276 = ! ! ( V_37 & V_168 ) ;
V_224 = ( V_223 != V_104 &&
! V_273 &&
! V_274 &&
! V_276 ) ;
V_119 -> V_190 &= ~ ( V_215 |
V_216 |
V_284 |
V_230 |
V_285 |
V_231 ) ;
if ( V_273 )
V_119 -> V_190 |= V_215 ;
if ( V_275 )
V_119 -> V_190 |= V_216 ;
if ( V_277 )
V_119 -> V_190 |= V_285 ;
if ( V_224 ) {
V_119 -> V_190 |= V_284 ;
if ( F_114 ( ! V_277 ) )
V_119 -> V_190 |= V_230 |
V_231 ;
}
F_115 (amsdu, msdu) {
F_111 ( V_55 ) ;
F_109 ( V_3 , V_55 , V_119 , V_232 , V_223 ,
V_224 ) ;
if ( ! V_224 )
continue;
if ( V_277 )
continue;
V_204 = ( void * ) V_55 -> V_36 ;
V_204 -> V_208 &= ~ F_116 ( V_286 ) ;
}
}
static void F_117 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_119 )
{
struct V_1 * V_55 ;
while ( ( V_55 = F_118 ( V_60 ) ) ) {
if ( F_52 ( V_60 ) )
V_119 -> V_190 &= ~ V_217 ;
else
V_119 -> V_190 |= V_217 ;
F_88 ( V_3 , V_119 , V_55 ) ;
}
}
static int F_119 ( struct V_59 * V_60 )
{
struct V_1 * V_9 , * V_196 ;
int V_287 ;
int V_288 = 0 ;
V_196 = F_118 ( V_60 ) ;
F_115 (amsdu, skb)
V_288 += V_9 -> V_16 ;
V_287 = V_288 - F_8 ( V_196 ) ;
if ( ( V_287 > 0 ) &&
( F_120 ( V_196 , 0 , V_287 , V_289 ) < 0 ) ) {
F_121 ( V_60 , V_196 ) ;
return - 1 ;
}
while ( ( V_9 = F_118 ( V_60 ) ) ) {
F_122 ( V_9 , F_47 ( V_196 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_121 ( V_60 , V_196 ) ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_1 * V_196 ;
struct V_24 * V_87 ;
enum V_249 V_250 ;
V_196 = F_84 ( V_60 ) ;
V_87 = ( void * ) V_196 -> V_36 - sizeof( * V_87 ) ;
V_250 = F_49 ( F_15 ( V_87 -> V_72 . V_73 . V_130 ) ,
V_251 ) ;
if ( V_250 != V_252 ||
F_124 ( V_60 ) != 1 + V_87 -> V_76 . V_77 ) {
F_45 ( V_60 ) ;
return;
}
F_119 ( V_60 ) ;
}
static bool F_125 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_211 )
{
if ( ! V_211 -> V_136 ) {
F_42 ( V_3 , L_25 ) ;
return false ;
}
if ( F_98 ( V_290 , & V_3 -> V_291 ) ) {
F_64 ( V_3 , V_292 , L_26 ) ;
return false ;
}
return true ;
}
static void F_126 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
struct V_118 * V_211 )
{
if ( F_52 ( V_60 ) )
return;
if ( F_125 ( V_3 , V_60 , V_211 ) )
return;
F_45 ( V_60 ) ;
}
static int F_127 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_118 * V_211 = & V_8 -> V_211 ;
struct V_59 V_60 ;
int V_26 , V_293 ;
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
V_293 = F_124 ( & V_60 ) ;
F_83 ( V_3 , & V_60 , V_211 , 0xffff ) ;
if ( V_26 > 0 )
F_123 ( V_3 , & V_60 ) ;
F_126 ( V_3 , & V_60 , V_211 ) ;
F_112 ( V_3 , & V_60 , V_211 ) ;
F_117 ( V_3 , & V_60 , V_211 ) ;
return V_293 ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_294 * V_295 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_296 * V_297 ;
int V_298 ;
int V_12 , V_299 = 0 ;
V_298 = F_49 ( F_15 ( V_295 -> V_204 . V_130 ) ,
V_300 ) ;
V_297 = F_130 ( V_295 ) ;
F_43 ( V_3 , V_58 , NULL , L_28 ,
V_295 , sizeof( * V_295 ) +
( sizeof( struct V_296 ) *
V_298 ) ) ;
for ( V_12 = 0 ; V_12 < V_298 ; V_12 ++ )
V_299 += V_297 [ V_12 ] . V_299 ;
F_131 ( V_299 , & V_8 -> V_101 ) ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_301 * V_302 = (struct V_301 * ) V_9 -> V_36 ;
struct V_303 V_304 = {} ;
int V_119 = F_49 ( V_302 -> V_305 . V_38 , V_306 ) ;
T_6 V_307 ;
int V_12 ;
switch ( V_119 ) {
case V_308 :
V_304 . V_119 = V_309 ;
break;
case V_310 :
V_304 . V_119 = V_311 ;
break;
case V_312 :
case V_313 :
case V_314 :
V_304 . V_119 = V_315 ;
break;
default:
F_42 ( V_3 , L_29 , V_119 ) ;
V_304 . V_119 = V_315 ;
break;
}
F_64 ( V_3 , V_292 , L_30 ,
V_302 -> V_305 . V_293 ) ;
for ( V_12 = 0 ; V_12 < V_302 -> V_305 . V_293 ; V_12 ++ ) {
V_307 = V_302 -> V_305 . V_316 [ V_12 ] ;
V_304 . V_307 = F_55 ( V_307 ) ;
if ( ! F_133 ( & V_8 -> V_317 , V_304 ) ) {
F_42 ( V_3 , L_31 ,
V_304 . V_307 , V_304 . V_119 ) ;
F_134 ( V_8 , & V_304 ) ;
}
}
}
static void F_135 ( struct V_2 * V_3 , struct V_301 * V_302 )
{
struct V_318 * V_82 = & V_302 -> V_319 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_74 , V_207 , V_166 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_207 = F_49 ( V_74 , V_320 ) ;
V_166 = F_49 ( V_74 , V_321 ) ;
F_64 ( V_3 , V_292 ,
L_32 ,
V_207 , V_166 , V_82 -> V_322 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_42 ( V_3 , L_33 ,
V_166 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_72 ( V_3 , V_161 -> V_171 ) ;
if ( ! V_163 ) {
F_42 ( V_3 , L_34 ,
V_161 -> V_171 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
F_64 ( V_3 , V_292 ,
L_35 ,
V_161 -> V_323 , V_207 , V_82 -> V_322 ) ;
F_136 ( V_163 -> V_172 , V_161 -> V_323 , V_207 ) ;
F_33 ( & V_3 -> V_167 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_301 * V_302 )
{
struct V_324 * V_82 = & V_302 -> V_325 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
T_5 V_74 , V_207 , V_166 ;
V_74 = F_55 ( V_82 -> V_74 ) ;
V_207 = F_49 ( V_74 , V_320 ) ;
V_166 = F_49 ( V_74 , V_321 ) ;
F_64 ( V_3 , V_292 ,
L_36 ,
V_207 , V_166 ) ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_42 ( V_3 , L_33 ,
V_166 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
V_163 = F_72 ( V_3 , V_161 -> V_171 ) ;
if ( ! V_163 ) {
F_42 ( V_3 , L_34 ,
V_161 -> V_171 ) ;
F_33 ( & V_3 -> V_167 ) ;
return;
}
F_64 ( V_3 , V_292 ,
L_37 ,
V_161 -> V_323 , V_207 ) ;
F_138 ( V_163 -> V_172 , V_161 -> V_323 , V_207 ) ;
F_33 ( & V_3 -> V_167 ) ;
}
static int F_139 ( struct V_59 * V_83 ,
struct V_59 * V_60 )
{
struct V_1 * V_55 ;
struct V_24 * V_87 ;
if ( F_52 ( V_83 ) )
return - V_326 ;
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
return - V_327 ;
}
return 0 ;
}
static void F_142 ( struct V_118 * V_119 ,
struct V_1 * V_9 )
{
struct V_203 * V_204 = (struct V_203 * ) V_9 -> V_36 ;
if ( ! F_143 ( V_204 -> V_208 ) )
return;
V_204 -> V_208 &= ~ F_116 ( V_286 ) ;
V_119 -> V_190 |= V_284 |
V_230 |
V_231 ;
}
static int F_144 ( struct V_2 * V_3 ,
struct V_59 * V_83 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_118 * V_119 = & V_8 -> V_211 ;
struct V_328 * V_295 ;
struct V_1 * V_55 ;
T_3 V_329 ;
int V_330 = 0 ;
while ( ( V_55 = F_118 ( V_83 ) ) ) {
V_295 = ( void * ) V_55 -> V_36 ;
F_47 ( V_55 , sizeof( * V_295 ) ) ;
F_18 ( V_55 , sizeof( * V_295 ) ) ;
if ( F_8 ( V_55 ) < F_55 ( V_295 -> V_61 ) ) {
F_42 ( V_3 , L_38 ) ;
F_10 ( V_55 ) ;
continue;
}
F_47 ( V_55 , F_55 ( V_295 -> V_61 ) ) ;
V_329 = 4 - ( ( unsigned long ) V_55 -> V_36 & 3 ) ;
F_47 ( V_55 , V_329 ) ;
memmove ( V_55 -> V_36 + V_329 , V_55 -> V_36 , V_55 -> V_16 ) ;
F_18 ( V_55 , V_329 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_190 |= V_191 ;
F_142 ( V_119 , V_55 ) ;
F_79 ( V_3 , V_119 , NULL , V_295 -> V_171 ) ;
F_88 ( V_3 , V_119 , V_55 ) ;
V_330 ++ ;
}
return V_330 ;
}
static int F_145 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_301 * V_302 = ( void * ) V_9 -> V_36 ;
struct V_118 * V_119 = & V_8 -> V_211 ;
struct V_59 V_83 ;
struct V_59 V_60 ;
T_5 V_166 ;
T_5 V_88 ;
T_4 V_171 ;
T_4 V_207 ;
bool V_331 ;
bool V_332 ;
int V_26 , V_293 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_95 )
return - V_69 ;
F_18 ( V_9 , sizeof( V_302 -> V_204 ) ) ;
F_18 ( V_9 , sizeof( V_302 -> V_333 ) ) ;
V_166 = F_55 ( V_302 -> V_333 . V_166 ) ;
V_88 = F_55 ( V_302 -> V_333 . V_88 ) ;
V_171 = V_302 -> V_333 . V_171 ;
V_207 = F_146 ( V_302 -> V_333 . V_90 , V_334 ) ;
V_331 = ! ! ( V_302 -> V_333 . V_90 &
V_91 ) ;
V_332 = ! ! ( V_302 -> V_333 . V_90 & V_335 ) ;
F_64 ( V_3 , V_292 ,
L_39 ,
V_171 , V_166 , V_207 , V_331 , V_332 , V_88 ) ;
if ( V_9 -> V_16 < V_88 * sizeof( * V_302 -> V_333 . V_86 ) ) {
F_42 ( V_3 , L_40 ) ;
return - V_96 ;
}
F_128 ( & V_83 ) ;
V_26 = F_54 ( V_8 , & V_302 -> V_333 , & V_83 ) ;
if ( V_26 < 0 ) {
F_42 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_95 = true ;
return - V_69 ;
}
if ( V_331 )
V_293 = F_144 ( V_3 , & V_83 ) ;
while ( ! F_52 ( & V_83 ) ) {
F_128 ( & V_60 ) ;
V_26 = F_139 ( & V_83 , & V_60 ) ;
switch ( V_26 ) {
case 0 :
V_293 += F_124 ( & V_60 ) ;
F_83 ( V_3 , & V_60 , V_119 , V_171 ) ;
F_126 ( V_3 , & V_60 , V_119 ) ;
F_112 ( V_3 , & V_60 , V_119 ) ;
F_117 ( V_3 , & V_60 , V_119 ) ;
break;
case - V_327 :
default:
F_42 ( V_3 , L_42 , V_26 ) ;
V_8 -> V_95 = true ;
F_45 ( & V_83 ) ;
return - V_69 ;
}
}
return V_293 ;
}
static void F_147 ( struct V_2 * V_3 ,
const T_7 * V_336 ,
int V_337 )
{
int V_12 ;
T_1 V_338 ;
F_64 ( V_3 , V_292 , L_43 ,
V_337 ) ;
for ( V_12 = 0 ; V_12 < V_337 ; V_12 ++ ) {
V_338 = F_148 ( V_336 [ V_12 ] ) ;
F_64 ( V_3 , V_292 , L_44 ,
V_338 ) ;
}
}
static void F_149 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_174 * V_175 = V_3 -> V_175 ;
struct V_339 * V_340 ;
struct V_301 * V_302 = (struct V_301 * ) V_9 -> V_36 ;
struct V_341 * V_342 ;
T_3 V_16 ;
T_3 V_343 ;
T_3 V_344 ;
T_3 V_345 ;
T_3 V_293 ;
const T_7 * V_336 ;
T_5 V_346 ;
T_5 V_337 ;
T_5 V_166 ;
T_4 V_207 ;
int V_26 ;
int V_12 ;
F_64 ( V_3 , V_292 , L_45 ) ;
V_16 = sizeof( V_302 -> V_204 ) + sizeof( V_302 -> V_347 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_46 ) ;
return;
}
V_346 = F_150 ( V_302 -> V_347 . V_346 ) ;
V_337 = F_150 ( V_302 -> V_347 . V_337 ) ;
V_16 += sizeof( V_302 -> V_347 . V_348 [ 0 ] ) * V_346 ;
V_16 += sizeof( V_302 -> V_347 . V_336 [ 0 ] ) * V_337 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_47 ) ;
return;
}
F_64 ( V_3 , V_292 , L_48 ,
V_346 , V_337 ,
F_150 ( V_302 -> V_347 . V_349 ) ) ;
if ( ! V_3 -> V_8 . V_350 . V_351 ) {
F_42 ( V_3 , L_49 ) ;
return;
}
if ( V_3 -> V_8 . V_350 . V_352 == V_353 ) {
F_42 ( V_3 , L_50 ) ;
return;
}
F_151 () ;
for ( V_12 = 0 ; V_12 < V_346 ; V_12 ++ ) {
V_342 = & V_302 -> V_347 . V_348 [ V_12 ] ;
V_166 = F_49 ( F_150 ( V_342 -> V_90 ) ,
V_354 ) ;
V_207 = F_49 ( F_150 ( V_342 -> V_90 ) ,
V_355 ) ;
V_344 = F_150 ( V_342 -> V_293 ) ;
V_343 = F_148 ( V_342 -> V_345 ) ;
F_64 ( V_3 , V_292 , L_51 ,
V_12 , V_166 , V_207 , V_344 , V_343 ) ;
if ( F_22 ( V_166 >= V_3 -> V_8 . V_350 . V_356 ) ||
F_22 ( V_207 >= V_3 -> V_8 . V_350 . V_357 ) ) {
F_42 ( V_3 , L_52 ,
V_166 , V_207 ) ;
continue;
}
F_29 ( & V_3 -> V_167 ) ;
V_340 = F_152 ( V_3 , V_166 , V_207 ) ;
F_33 ( & V_3 -> V_167 ) ;
if ( F_22 ( ! V_340 ) ) {
F_42 ( V_3 , L_53 ,
V_166 , V_207 ) ;
continue;
}
V_293 = 0 ;
V_345 = 0 ;
while ( V_293 < V_344 &&
V_345 < V_343 ) {
V_26 = F_153 ( V_175 , V_340 ) ;
if ( V_26 < 0 )
break;
V_293 ++ ;
V_345 += V_26 ;
}
V_342 -> V_293 = F_154 ( V_293 ) ;
V_342 -> V_345 = F_155 ( V_345 ) ;
F_156 ( V_175 , V_340 ) ;
}
F_157 () ;
V_336 = F_158 ( & V_302 -> V_347 ) ;
F_147 ( V_3 , V_336 , V_337 ) ;
V_26 = F_159 ( V_3 ,
V_302 -> V_347 . V_358 ,
V_302 -> V_347 . V_349 ,
V_302 -> V_347 . V_348 ,
V_346 ) ;
if ( F_22 ( V_26 ) ) {
F_42 ( V_3 , L_54 ,
F_148 ( V_302 -> V_347 . V_358 ) , V_26 ) ;
}
F_160 ( V_3 ) ;
}
static void F_161 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_301 * V_302 = ( void * ) V_9 -> V_36 ;
T_3 V_16 ;
int V_337 ;
F_64 ( V_3 , V_292 , L_55 ) ;
V_16 = sizeof( V_302 -> V_204 ) + sizeof( V_302 -> V_359 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_56 ) ;
return;
}
V_337 = F_150 ( V_302 -> V_359 . V_337 ) ;
V_16 += sizeof( V_302 -> V_359 . V_336 [ 0 ] ) * V_337 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_57 ) ;
return;
}
F_147 ( V_3 ,
V_302 -> V_359 . V_336 ,
V_337 ) ;
}
static void F_162 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
const struct V_301 * V_302 = ( void * ) V_9 -> V_36 ;
const struct V_360 * V_342 ;
struct V_339 * V_340 ;
struct V_361 * V_362 ;
T_3 V_16 ;
T_3 V_346 ;
enum V_363 V_352 ;
bool V_364 ;
T_5 V_74 ;
T_5 V_130 ;
T_5 V_365 ;
T_5 V_166 ;
T_4 V_207 ;
int V_12 ;
F_64 ( V_3 , V_292 , L_58 ) ;
V_16 = sizeof( V_302 -> V_204 ) + sizeof( V_302 -> V_366 ) ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_59 ) ;
return;
}
V_74 = F_150 ( V_302 -> V_366 . V_74 ) ;
V_130 = F_150 ( V_302 -> V_366 . V_130 ) ;
V_364 = ! ! ( V_74 & V_367 ) ;
V_346 = F_49 ( V_74 , V_368 ) ;
V_352 = F_49 ( V_130 , V_369 ) ;
V_365 = F_49 ( V_130 , V_368 ) ;
F_64 ( V_3 , V_292 ,
L_60 ,
V_74 , V_130 , V_364 , V_346 , V_352 , V_365 ) ;
V_16 += sizeof( V_302 -> V_366 . V_348 [ 0 ] ) * V_346 ;
if ( F_22 ( V_9 -> V_16 < V_16 ) ) {
F_42 ( V_3 , L_61 ) ;
return;
}
switch ( V_352 ) {
case V_353 :
case V_370 :
break;
default:
F_42 ( V_3 , L_62 ,
V_352 ) ;
return;
}
if ( ! V_364 )
return;
V_3 -> V_8 . V_350 . V_351 = V_364 ;
V_3 -> V_8 . V_350 . V_352 = V_352 ;
V_3 -> V_8 . V_350 . V_371 = V_365 ;
F_151 () ;
for ( V_12 = 0 ; V_12 < V_346 ; V_12 ++ ) {
V_342 = & V_302 -> V_366 . V_348 [ V_12 ] ;
V_74 = F_150 ( V_342 -> V_74 ) ;
V_166 = F_49 ( V_74 , V_372 ) ;
V_207 = F_49 ( V_74 , V_373 ) ;
if ( F_22 ( V_166 >= V_3 -> V_8 . V_350 . V_356 ) ||
F_22 ( V_207 >= V_3 -> V_8 . V_350 . V_357 ) ) {
F_42 ( V_3 , L_52 ,
V_166 , V_207 ) ;
continue;
}
F_29 ( & V_3 -> V_167 ) ;
V_340 = F_152 ( V_3 , V_166 , V_207 ) ;
F_33 ( & V_3 -> V_167 ) ;
if ( F_22 ( ! V_340 ) ) {
F_42 ( V_3 , L_53 ,
V_166 , V_207 ) ;
continue;
}
F_29 ( & V_3 -> V_8 . V_374 ) ;
V_362 = ( void * ) V_340 -> V_375 ;
V_362 -> V_371 = F_150 ( V_342 -> V_376 ) ;
F_33 ( & V_3 -> V_8 . V_374 ) ;
}
F_157 () ;
F_163 ( V_3 ) ;
}
void F_164 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
bool V_377 ;
V_377 = F_165 ( V_3 , V_9 ) ;
if ( V_377 )
F_10 ( V_9 ) ;
}
static inline bool F_166 ( T_4 V_123 )
{
static const T_4 V_378 [] = { 1 , 2 , 5 , 11 , 6 , 9 , 12 ,
18 , 24 , 36 , 48 , 54 } ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_167 ( V_378 ) ; V_12 ++ ) {
if ( V_123 == V_378 [ V_12 ] )
return true ;
}
return false ;
}
static void
F_168 ( struct V_2 * V_3 ,
struct V_379 * V_380 ,
struct V_381 * V_382 )
{
struct V_383 * V_384 = (struct V_383 * ) V_380 -> V_375 ;
T_4 V_123 = 0 , V_125 ;
struct V_385 V_386 ;
F_27 ( & V_3 -> V_167 ) ;
V_386 . V_38 = F_169 ( V_382 -> V_387 ) ;
V_386 . V_124 = F_170 ( V_382 -> V_38 ) ;
V_386 . V_127 = F_171 ( V_382 -> V_387 ) ;
V_386 . V_126 = F_172 ( V_382 -> V_387 ) ;
V_125 = F_173 ( V_382 -> V_38 ) ;
if ( V_386 . V_38 == V_388 && V_386 . V_126 > 9 ) {
F_42 ( V_3 , L_63 , V_386 . V_126 ) ;
return;
}
if ( V_386 . V_38 == V_389 &&
( V_386 . V_126 > 7 || V_386 . V_127 < 1 ) ) {
F_42 ( V_3 , L_64 ,
V_386 . V_126 , V_386 . V_127 ) ;
return;
}
memset ( & V_384 -> V_386 , 0 , sizeof( V_384 -> V_386 ) ) ;
if ( V_386 . V_38 == V_390 ||
V_386 . V_38 == V_391 ) {
V_123 = F_174 ( V_382 -> V_387 ) ;
if ( ! F_166 ( V_123 ) ) {
F_42 ( V_3 , L_65 ,
V_123 ) ;
return;
}
V_123 *= 10 ;
if ( V_123 == 60 && V_386 . V_38 == V_390 )
V_123 = V_123 - 5 ;
V_384 -> V_386 . V_392 = V_123 ;
} else if ( V_386 . V_38 == V_389 ) {
V_384 -> V_386 . V_38 = V_393 ;
V_384 -> V_386 . V_126 = V_386 . V_126 + 8 * ( V_386 . V_127 - 1 ) ;
} else {
V_384 -> V_386 . V_38 = V_394 ;
V_384 -> V_386 . V_126 = V_386 . V_126 ;
}
if ( V_125 )
V_384 -> V_386 . V_38 |= V_395 ;
V_384 -> V_386 . V_127 = V_386 . V_127 ;
V_384 -> V_386 . V_124 = V_386 . V_124 + V_202 ;
}
static void F_175 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_301 * V_302 = (struct V_301 * ) V_9 -> V_36 ;
struct V_381 * V_396 = & V_3 -> V_397 ;
struct V_398 * V_399 ;
struct V_379 * V_380 ;
struct V_160 * V_161 ;
int V_166 , V_12 ;
T_4 V_400 , V_401 ;
V_401 = V_302 -> V_397 . V_401 ;
V_400 = V_302 -> V_397 . V_400 * sizeof( T_7 ) ;
if ( V_9 -> V_16 < sizeof( struct V_402 ) + V_401 * V_400 ) {
F_42 ( V_3 , L_66 , V_9 -> V_16 ) ;
return;
}
V_399 = (struct V_398 * )
( V_302 -> V_397 . V_403 ) ;
V_166 = F_55 ( V_399 -> V_166 ) ;
F_151 () ;
F_29 ( & V_3 -> V_167 ) ;
V_161 = F_71 ( V_3 , V_166 ) ;
if ( ! V_161 ) {
F_42 ( V_3 , L_67 ,
V_166 ) ;
goto V_205;
}
V_380 = V_161 -> V_380 ;
for ( V_12 = 0 ; V_12 < V_401 ; V_12 ++ ) {
V_399 = (struct V_398 * )
( V_302 -> V_397 . V_403 + V_12 * V_400 ) ;
V_396 -> V_404 = F_15 ( V_399 -> V_404 ) ;
V_396 -> V_405 = F_15 ( V_399 -> V_405 ) ;
V_396 -> V_406 =
F_15 ( V_399 -> V_406 ) ;
V_396 -> V_387 = V_399 -> V_387 ;
V_396 -> V_38 = V_399 -> V_38 ;
V_396 -> V_407 = F_55 ( V_399 -> V_407 ) ;
V_396 -> V_408 = F_55 ( V_399 -> V_408 ) ;
V_396 -> V_409 = F_55 ( V_399 -> V_409 ) ;
F_168 ( V_3 , V_380 , V_396 ) ;
}
V_205:
F_33 ( & V_3 -> V_167 ) ;
F_157 () ;
}
bool F_165 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_301 * V_302 = (struct V_301 * ) V_9 -> V_36 ;
enum V_410 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_42 ( V_3 , L_68 ) ;
F_64 ( V_3 , V_292 , L_69 ,
V_302 -> V_204 . V_411 ) ;
if ( V_302 -> V_204 . V_411 >= V_3 -> V_8 . V_412 ) {
F_64 ( V_3 , V_292 , L_70 ,
V_302 -> V_204 . V_411 , V_3 -> V_8 . V_412 ) ;
return true ;
}
type = V_3 -> V_8 . V_413 [ V_302 -> V_204 . V_411 ] ;
switch ( type ) {
case V_414 : {
V_8 -> V_415 = V_302 -> V_416 . V_417 ;
V_8 -> V_418 = V_302 -> V_416 . V_419 ;
F_176 ( & V_8 -> V_420 ) ;
break;
}
case V_421 :
F_129 ( V_8 , & V_302 -> V_422 ) ;
break;
case V_423 : {
struct V_424 V_82 = {
. V_171 = V_302 -> V_425 . V_171 ,
. V_166 = F_55 ( V_302 -> V_425 . V_166 ) ,
} ;
memcpy ( V_82 . V_323 , V_302 -> V_425 . V_323 , sizeof( V_82 . V_323 ) ) ;
F_177 ( V_8 , & V_82 ) ;
break;
}
case V_426 : {
struct V_427 V_82 = {
. V_166 = F_55 ( V_302 -> V_428 . V_166 ) ,
} ;
F_178 ( V_8 , & V_82 ) ;
break;
}
case V_429 : {
struct V_303 V_304 = {} ;
int V_119 = F_15 ( V_302 -> V_430 . V_119 ) ;
V_304 . V_307 = F_15 ( V_302 -> V_430 . V_431 ) ;
switch ( V_119 ) {
case V_432 :
V_304 . V_119 = V_311 ;
break;
case V_433 :
V_304 . V_119 = V_309 ;
break;
case V_434 :
V_304 . V_119 = V_315 ;
break;
}
V_119 = F_134 ( V_8 , & V_304 ) ;
if ( ! V_119 ) {
F_29 ( & V_8 -> V_374 ) ;
F_179 ( V_8 ) ;
F_33 ( & V_8 -> V_374 ) ;
}
break;
}
case V_435 :
F_132 ( V_8 -> V_3 , V_9 ) ;
break;
case V_436 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_437 * V_82 = & V_302 -> V_438 ;
F_64 ( V_3 , V_292 ,
L_71 ,
F_55 ( V_82 -> V_166 ) ,
! ! ( V_82 -> V_38 & V_439 ) ,
F_49 ( V_82 -> V_38 , V_440 ) ) ;
F_176 ( & V_3 -> V_441 ) ;
break;
}
case V_442 : {
F_43 ( V_3 , V_58 , NULL , L_72 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_180 ( & V_8 -> V_101 ) ;
break;
}
case V_443 :
break;
case V_444 :
F_181 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_445 :
F_42 ( V_3 , L_73 ) ;
break;
case V_446 :
F_135 ( V_3 , V_302 ) ;
break;
case V_447 :
F_137 ( V_3 , V_302 ) ;
break;
case V_448 : {
F_182 ( V_3 , V_302 -> V_449 . V_403 ,
V_9 -> V_16 -
F_48 ( struct V_301 ,
V_449 . V_403 ) ) ;
break;
}
case V_450 : {
break;
}
case V_451 : {
F_46 ( & V_8 -> V_52 , V_9 ) ;
return false ;
}
case V_452 :
break;
case V_453 : {
T_1 V_454 = F_15 ( V_302 -> V_455 . V_454 ) ;
T_1 V_136 = F_15 ( V_302 -> V_455 . V_136 ) ;
V_3 -> V_181 = F_183 ( V_3 -> V_175 -> V_456 , V_136 ) ;
F_64 ( V_3 , V_292 ,
L_74 ,
V_136 , F_184 ( V_454 ) ) ;
break;
}
case V_457 :
break;
case V_458 : {
struct V_1 * V_347 = F_185 ( V_9 , V_289 ) ;
if ( ! V_347 ) {
F_42 ( V_3 , L_75 ) ;
break;
}
F_186 ( & V_8 -> V_53 , V_347 ) ;
break;
}
case V_459 :
F_161 ( V_3 , V_9 ) ;
break;
case V_460 :
F_162 ( V_3 , V_9 ) ;
break;
case V_461 :
F_175 ( V_3 , V_9 ) ;
break;
case V_462 :
default:
F_42 ( V_3 , L_76 ,
V_302 -> V_204 . V_411 ) ;
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
int F_188 ( struct V_2 * V_3 , int V_463 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_303 V_304 = {} ;
struct V_59 V_464 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
int V_465 = 0 , V_466 , V_467 ;
bool V_468 = false ;
F_128 ( & V_464 ) ;
while ( V_465 < V_463 ) {
if ( F_52 ( & V_8 -> V_52 ) )
break;
V_9 = F_118 ( & V_8 -> V_52 ) ;
if ( ! V_9 ) {
V_468 = true ;
goto exit;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_467 = F_145 ( V_3 , V_9 ) ;
F_33 ( & V_8 -> V_13 . V_41 ) ;
if ( V_467 < 0 ) {
V_468 = true ;
goto exit;
}
F_10 ( V_9 ) ;
if ( V_467 > 0 )
V_465 += V_467 ;
if ( ( V_465 > V_469 ) &&
! F_52 ( & V_8 -> V_52 ) ) {
V_468 = true ;
goto exit;
}
}
while ( V_465 < V_463 ) {
if ( ! F_189 ( & V_8 -> V_101 ) )
break;
V_467 = F_127 ( V_8 ) ;
if ( V_467 < 0 ) {
V_468 = true ;
goto exit;
}
V_465 += V_467 ;
F_190 ( & V_8 -> V_101 ) ;
if ( ( V_465 > V_469 ) &&
F_189 ( & V_8 -> V_101 ) ) {
V_468 = true ;
goto exit;
}
}
if ( ( V_465 < V_463 ) && ! F_191 ( & V_8 -> V_317 ) )
V_465 = V_463 ;
while ( F_192 ( & V_8 -> V_317 , & V_304 ) )
F_134 ( V_8 , & V_304 ) ;
F_163 ( V_3 ) ;
F_193 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_141 ( & V_8 -> V_53 , & V_464 ) ;
F_194 ( & V_8 -> V_53 . V_41 , V_38 ) ;
while ( ( V_9 = F_118 ( & V_464 ) ) ) {
F_149 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
exit:
F_28 ( V_8 ) ;
V_466 = V_468 ? V_463 : V_465 ;
return V_466 ;
}
