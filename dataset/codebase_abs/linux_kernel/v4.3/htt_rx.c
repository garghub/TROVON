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
V_64 = F_51 ( F_15 ( V_25 -> V_76 . V_77 . V_73 ) ,
V_78 ) ;
V_68 = V_25 -> V_79 . V_80 ;
if ( V_67 )
V_64 = 0 ;
F_52 ( V_56 , 0 ) ;
F_49 ( V_56 , F_30 ( V_64 , V_81 ) ) ;
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
V_66 = F_15 ( V_25 -> V_82 . V_77 . V_73 ) &
V_83 ;
F_53 ( V_3 , & V_25 -> V_37 ,
sizeof( * V_25 ) - sizeof( T_1 ) ) ;
if ( V_66 )
break;
}
if ( F_54 ( V_63 ) )
V_65 = - 1 ;
return V_65 ;
}
static void F_55 ( unsigned long V_84 )
{
struct V_7 * V_8 = (struct V_7 * ) V_84 ;
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
struct V_85 * V_86 ,
struct V_62 * V_87 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_24 * V_91 ;
struct V_1 * V_56 ;
int V_92 ;
bool V_93 ;
T_1 V_4 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
V_92 = F_58 ( V_86 -> V_92 ) ;
V_93 = ! ! ( V_86 -> V_94 & V_95 ) ;
while ( V_92 -- ) {
V_4 = F_15 ( V_89 -> V_96 ) ;
V_56 = F_56 ( V_8 , V_4 ) ;
if ( ! V_56 ) {
F_47 ( V_87 ) ;
return - V_69 ;
}
F_48 ( V_87 , V_56 ) ;
if ( ! V_93 ) {
V_91 = ( void * ) V_56 -> V_36 ;
F_53 ( V_3 , V_91 , sizeof( * V_91 ) ) ;
F_49 ( V_56 , sizeof( * V_91 ) ) ;
F_18 ( V_56 , sizeof( * V_91 ) ) ;
F_49 ( V_56 , F_58 ( V_89 -> V_64 ) ) ;
if ( ! ( F_15 ( V_91 -> V_37 . V_38 ) &
V_71 ) ) {
F_44 ( V_8 -> V_3 , L_3 ) ;
return - V_72 ;
}
}
V_89 ++ ;
}
return 0 ;
}
int F_59 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_2 V_4 ;
void * V_31 ;
T_4 V_19 ;
struct V_97 * V_98 = & V_8 -> V_13 . V_46 ;
V_8 -> V_99 = false ;
V_8 -> V_13 . V_19 = V_29 ;
V_8 -> V_13 . V_40 = V_8 -> V_13 . V_19 - 1 ;
V_8 -> V_13 . V_44 = V_28 ;
if ( ! F_60 ( V_8 -> V_13 . V_19 ) ) {
F_44 ( V_3 , L_4 ) ;
return - V_100 ;
}
V_8 -> V_13 . V_20 =
F_61 ( V_8 -> V_13 . V_19 * sizeof( struct V_1 * ) ,
V_101 ) ;
if ( ! V_8 -> V_13 . V_20 )
goto V_102;
V_19 = V_8 -> V_13 . V_19 * sizeof( V_8 -> V_13 . V_39 ) ;
V_31 = F_62 ( V_8 -> V_3 -> V_15 , V_19 , & V_4 , V_103 ) ;
if ( ! V_31 )
goto V_104;
V_8 -> V_13 . V_39 = V_31 ;
V_8 -> V_13 . V_55 = V_4 ;
V_31 = F_62 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
& V_4 , V_103 ) ;
if ( ! V_31 )
goto V_105;
V_8 -> V_13 . V_30 . V_31 = V_31 ;
V_8 -> V_13 . V_30 . V_4 = V_4 ;
V_8 -> V_13 . V_57 . V_58 = V_8 -> V_13 . V_40 ;
* V_8 -> V_13 . V_30 . V_31 = 0 ;
F_63 ( V_98 , F_35 , ( unsigned long ) V_8 ) ;
F_64 ( & V_8 -> V_13 . V_41 ) ;
V_8 -> V_13 . V_21 = 0 ;
V_8 -> V_13 . V_57 . V_58 = 0 ;
F_12 ( V_8 -> V_13 . V_22 ) ;
F_65 ( & V_8 -> V_49 , F_55 ,
( unsigned long ) V_8 ) ;
F_66 ( & V_8 -> V_52 ) ;
F_66 ( & V_8 -> V_53 ) ;
F_66 ( & V_8 -> V_54 ) ;
F_65 ( & V_8 -> V_51 , V_106 ,
( unsigned long ) V_8 ) ;
F_67 ( V_3 , V_107 , L_5 ,
V_8 -> V_13 . V_19 , V_8 -> V_13 . V_44 ) ;
return 0 ;
V_105:
F_41 ( V_8 -> V_3 -> V_15 ,
( V_8 -> V_13 . V_19 *
sizeof( V_8 -> V_13 . V_39 ) ) ,
V_8 -> V_13 . V_39 ,
V_8 -> V_13 . V_55 ) ;
V_104:
F_42 ( V_8 -> V_13 . V_20 ) ;
V_102:
return - V_34 ;
}
static int F_68 ( struct V_2 * V_3 ,
enum V_108 type )
{
switch ( type ) {
case V_109 :
return 0 ;
case V_110 :
case V_111 :
return V_112 ;
case V_113 :
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
case V_118 :
case V_119 :
break;
}
F_44 ( V_3 , L_6 , type ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
enum V_108 type )
{
switch ( type ) {
case V_109 :
return 0 ;
case V_110 :
case V_111 :
return V_120 ;
case V_113 :
case V_114 :
return V_121 ;
case V_116 :
return V_122 ;
case V_118 :
case V_119 :
break;
}
F_44 ( V_3 , L_6 , type ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 )
{
struct V_125 * V_126 ;
T_3 V_127 , V_128 , V_129 , V_130 , V_131 , V_132 ;
T_3 V_133 = 0 ;
T_1 V_134 , V_135 , V_136 ;
V_134 = F_15 ( V_91 -> V_137 . V_134 ) ;
V_135 = F_15 ( V_91 -> V_137 . V_135 ) ;
V_136 = F_15 ( V_91 -> V_137 . V_136 ) ;
V_133 = F_51 ( V_134 , V_138 ) ;
switch ( V_133 ) {
case V_139 :
if ( ! V_124 -> V_140 )
return;
V_127 = V_134 & V_141 ;
V_128 = F_51 ( V_134 , V_142 ) ;
V_128 &= ~ V_143 ;
V_126 = & V_3 -> V_144 . V_145 [ V_124 -> V_146 ] ;
V_124 -> V_147 = F_71 ( V_126 , V_128 ) ;
break;
case V_148 :
case V_149 :
V_131 = V_135 & 0x1F ;
V_132 = V_131 >> 3 ;
V_129 = ( V_135 >> 7 ) & 1 ;
V_130 = ( V_136 >> 7 ) & 1 ;
V_124 -> V_147 = V_131 ;
V_124 -> V_150 |= V_151 ;
if ( V_130 )
V_124 -> V_150 |= V_152 ;
if ( V_129 )
V_124 -> V_150 |= V_153 ;
break;
case V_154 :
case V_155 :
V_131 = ( V_136 >> 4 ) & 0x0F ;
V_132 = ( ( V_135 >> 10 ) & 0x07 ) + 1 ;
V_129 = V_135 & 3 ;
V_130 = V_136 & 1 ;
V_124 -> V_147 = V_131 ;
V_124 -> V_156 = V_132 ;
if ( V_130 )
V_124 -> V_150 |= V_152 ;
switch ( V_129 ) {
case 0 :
break;
case 1 :
V_124 -> V_150 |= V_153 ;
break;
case 2 :
V_124 -> V_157 |= V_158 ;
}
V_124 -> V_150 |= V_159 ;
break;
default:
break;
}
}
static struct V_160 *
F_72 ( struct V_2 * V_3 , struct V_24 * V_91 )
{
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_165 V_166 ;
T_5 V_167 ;
F_27 ( & V_3 -> V_168 ) ;
if ( ! V_91 )
return NULL ;
if ( V_91 -> V_37 . V_38 &
F_20 ( V_169 ) )
return NULL ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_170 ) ) )
return NULL ;
V_167 = F_51 ( F_15 ( V_91 -> V_171 . V_73 ) ,
V_172 ) ;
V_162 = F_73 ( V_3 , V_167 ) ;
if ( ! V_162 )
return NULL ;
V_164 = F_74 ( V_3 , V_162 -> V_173 ) ;
if ( F_4 ( ! V_164 ) )
return NULL ;
if ( F_75 ( F_76 ( V_164 -> V_174 , & V_166 ) ) )
return NULL ;
return V_166 . V_175 ;
}
static struct V_160 *
F_77 ( struct V_2 * V_3 , T_1 V_173 )
{
struct V_163 * V_164 ;
struct V_165 V_166 ;
F_27 ( & V_3 -> V_168 ) ;
F_78 (arvif, &ar->arvifs, list) {
if ( V_164 -> V_173 == V_173 &&
F_76 ( V_164 -> V_174 , & V_166 ) == 0 )
return V_166 . V_175 ;
}
return NULL ;
}
static void
F_79 ( struct V_176 * V_177 ,
struct V_178 * V_179 ,
void * V_36 )
{
struct V_165 * V_166 = V_36 ;
* V_166 = V_179 -> V_166 ;
}
static struct V_160 *
F_80 ( struct V_2 * V_3 )
{
struct V_165 V_166 = {} ;
F_81 ( V_3 -> V_177 ,
F_79 ,
& V_166 ) ;
return V_166 . V_175 ;
}
static bool F_82 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 ,
T_1 V_173 )
{
struct V_160 * V_180 ;
F_29 ( & V_3 -> V_168 ) ;
V_180 = V_3 -> V_181 ;
if ( ! V_180 )
V_180 = V_3 -> V_182 ;
if ( ! V_180 )
V_180 = F_72 ( V_3 , V_91 ) ;
if ( ! V_180 )
V_180 = F_77 ( V_3 , V_173 ) ;
if ( ! V_180 )
V_180 = F_80 ( V_3 ) ;
F_34 ( & V_3 -> V_168 ) ;
if ( ! V_180 )
return false ;
V_124 -> V_146 = V_180 -> V_146 ;
V_124 -> V_140 = V_180 -> V_183 ;
return true ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 )
{
V_124 -> signal = V_184 +
V_91 -> V_137 . V_185 ;
V_124 -> V_150 &= ~ V_186 ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 )
{
V_124 -> V_187 = F_15 ( V_91 -> V_188 . V_77 . V_189 ) ;
V_124 -> V_150 |= V_190 ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_124 ,
T_1 V_173 )
{
struct V_1 * V_191 ;
struct V_24 * V_91 ;
bool V_192 ;
bool V_193 ;
if ( F_54 ( V_63 ) )
return;
V_191 = F_86 ( V_63 ) ;
V_91 = ( void * ) V_191 -> V_36 - sizeof( * V_91 ) ;
V_192 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_194 ) ) ;
V_193 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_195 ) ) ;
if ( V_192 ) {
V_124 -> V_140 = 0 ;
V_124 -> V_147 = 0 ;
V_124 -> V_156 = 0 ;
V_124 -> V_157 &= ~ V_158 ;
V_124 -> V_150 &= ~ ( V_151 |
V_159 |
V_152 |
V_153 |
V_190 ) ;
V_124 -> V_150 |= V_186 ;
F_83 ( V_3 , V_124 , V_91 ) ;
F_82 ( V_3 , V_124 , V_91 , V_173 ) ;
F_70 ( V_3 , V_124 , V_91 ) ;
}
if ( V_193 )
F_84 ( V_3 , V_124 , V_91 ) ;
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
struct V_123 * V_204 ,
struct V_1 * V_9 )
{
struct V_123 * V_124 ;
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
char V_200 [ 32 ] ;
V_124 = F_91 ( V_9 ) ;
* V_124 = * V_204 ;
F_67 ( V_3 , V_205 ,
L_10 ,
V_9 ,
V_9 -> V_16 ,
F_92 ( V_197 ) ,
F_87 ( V_197 , V_200 , sizeof( V_200 ) ) ,
F_93 ( F_94 ( V_197 ) ) ?
L_11 : L_12 ,
( F_58 ( V_197 -> V_206 ) & V_207 ) >> 4 ,
V_124 -> V_150 == 0 ? L_13 : L_7 ,
V_124 -> V_150 & V_151 ? L_14 : L_7 ,
V_124 -> V_150 & V_159 ? L_15 : L_7 ,
V_124 -> V_150 & V_153 ? L_16 : L_7 ,
V_124 -> V_157 & V_158 ? L_17 : L_7 ,
V_124 -> V_150 & V_152 ? L_18 : L_7 ,
V_124 -> V_147 ,
V_124 -> V_156 ,
V_124 -> V_140 ,
V_124 -> V_146 , V_124 -> V_150 ,
! ! ( V_124 -> V_150 & V_208 ) ,
! ! ( V_124 -> V_150 & V_209 ) ,
! ! ( V_124 -> V_150 & V_210 ) ) ;
F_45 ( V_3 , V_59 , NULL , L_19 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_95 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_96 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_97 ( V_3 -> V_177 , V_9 ) ;
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
struct V_123 * V_124 ,
enum V_108 V_213 ,
bool V_214 )
{
struct V_196 * V_197 ;
struct V_24 * V_91 ;
T_4 V_215 ;
T_4 V_216 ;
bool V_217 ;
bool V_218 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_217 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_170 ) ) ;
V_218 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
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
V_213 == V_114 )
F_52 ( V_56 , V_56 -> V_16 - 8 ) ;
V_215 = F_99 ( V_197 -> V_201 ) ;
V_216 = F_68 ( V_3 , V_213 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_216 ,
( void * ) V_56 -> V_36 , V_215 ) ;
F_18 ( V_56 , V_216 ) ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
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
enum V_108 V_213 )
{
struct V_196 * V_197 ;
struct V_24 * V_91 ;
T_4 V_215 , V_216 ;
void * V_224 ;
bool V_217 , V_218 , V_225 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_197 = ( void * ) V_91 -> V_226 ;
V_217 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_170 ) ) ;
V_218 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
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
struct V_123 * V_124 ,
const T_3 V_220 [ 64 ] ,
enum V_108 V_213 )
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
struct V_123 * V_124 ,
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
struct V_123 * V_124 ,
T_3 V_220 [ 64 ] ,
enum V_108 V_213 ,
bool V_214 )
{
struct V_24 * V_91 ;
enum V_233 V_234 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_234 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_134 ) ,
V_235 ) ;
switch ( V_234 ) {
case V_236 :
F_102 ( V_3 , V_56 , V_124 , V_213 ,
V_214 ) ;
break;
case V_237 :
F_104 ( V_3 , V_56 , V_124 , V_220 ) ;
break;
case V_238 :
F_108 ( V_3 , V_56 , V_124 , V_220 , V_213 ) ;
break;
case V_239 :
F_109 ( V_3 , V_56 , V_124 , V_220 ) ;
break;
}
}
static int F_111 ( struct V_1 * V_9 )
{
struct V_24 * V_91 ;
T_1 V_38 , V_94 ;
bool V_240 , V_241 ;
bool V_242 , V_243 ;
bool V_244 , V_245 ;
V_91 = ( void * ) V_9 -> V_36 - sizeof( * V_91 ) ;
V_38 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_94 = F_15 ( V_91 -> V_76 . V_77 . V_134 ) ;
V_240 = ! ! ( V_94 & V_246 ) ;
V_241 = ! ! ( V_94 & V_247 ) ;
V_242 = ! ! ( V_94 & V_248 ) ;
V_243 = ! ! ( V_94 & V_249 ) ;
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
struct V_123 * V_124 )
{
struct V_1 * V_191 ;
struct V_1 * V_255 ;
struct V_1 * V_56 ;
struct V_24 * V_91 ;
struct V_196 * V_197 ;
enum V_108 V_213 ;
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
V_91 = ( void * ) V_191 -> V_36 - sizeof( * V_91 ) ;
V_213 = F_51 ( F_15 ( V_91 -> V_171 . V_73 ) ,
V_261 ) ;
V_197 = ( void * ) V_91 -> V_226 ;
V_215 = F_99 ( V_197 -> V_201 ) ;
memcpy ( V_220 , V_197 , V_215 ) ;
V_197 = ( void * ) V_220 ;
V_256 = F_89 ( V_197 ) ;
V_256 [ 0 ] &= ~ V_262 ;
V_255 = F_114 ( V_63 ) ;
V_91 = ( void * ) V_255 -> V_36 - sizeof( * V_91 ) ;
V_37 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_257 = ! ! ( V_37 & V_263 ) ;
V_258 = ! ! ( V_37 & V_264 ) ;
V_259 = ! ! ( V_37 & V_265 ) ;
V_260 = ! ! ( V_37 & V_169 ) ;
V_214 = ( V_213 != V_109 &&
! V_257 &&
! V_258 &&
! V_260 ) ;
V_124 -> V_150 &= ~ ( V_208 |
V_209 |
V_266 |
V_267 |
V_268 ) ;
if ( V_257 )
V_124 -> V_150 |= V_208 ;
if ( V_259 )
V_124 -> V_150 |= V_209 ;
if ( V_214 )
V_124 -> V_150 |= V_266 |
V_267 |
V_268 ;
F_115 (amsdu, msdu) {
F_112 ( V_56 ) ;
F_110 ( V_3 , V_56 , V_124 , V_220 , V_213 ,
V_214 ) ;
if ( ! V_214 )
continue;
V_197 = ( void * ) V_56 -> V_36 ;
V_197 -> V_201 &= ~ F_116 ( V_269 ) ;
}
}
static void F_117 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_124 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_118 ( V_63 ) ) ) {
if ( F_54 ( V_63 ) )
V_124 -> V_150 &= ~ V_210 ;
else
V_124 -> V_150 |= V_210 ;
F_90 ( V_3 , V_124 , V_56 ) ;
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
struct V_24 * V_91 ;
enum V_233 V_234 ;
V_191 = F_86 ( V_63 ) ;
V_91 = ( void * ) V_191 -> V_36 - sizeof( * V_91 ) ;
V_234 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_134 ) ,
V_235 ) ;
if ( ! V_273 )
return;
if ( V_234 != V_236 ||
F_124 ( V_63 ) != 1 + V_91 -> V_79 . V_80 ) {
F_47 ( V_63 ) ;
return;
}
F_119 ( V_63 ) ;
}
static bool F_125 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_204 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
bool V_274 ;
bool V_257 ;
V_56 = F_86 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! V_204 -> V_140 ) {
F_44 ( V_3 , L_20 ) ;
return false ;
}
V_274 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_275 ) ) ;
V_257 = ! ! ( V_91 -> V_37 . V_38 &
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
struct V_123 * V_204 )
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
struct V_123 * V_204 = & V_8 -> V_204 ;
struct V_281 * V_282 ;
struct V_62 V_63 ;
int V_283 ;
int V_61 ;
T_3 * V_60 ;
int V_12 , V_26 , V_284 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
V_61 = F_58 ( V_280 -> V_285 . V_286 ) ;
V_60 = ( T_3 * ) & V_280 -> V_60 ;
V_283 = F_51 ( F_15 ( V_280 -> V_197 . V_134 ) ,
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
V_8 -> V_99 = true ;
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
struct V_123 * V_204 = & V_8 -> V_204 ;
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
int V_124 = F_51 ( V_292 -> V_295 . V_38 , V_296 ) ;
T_6 V_297 ;
int V_12 ;
switch ( V_124 ) {
case V_298 :
V_294 . V_299 = true ;
break;
case V_300 :
V_294 . V_301 = true ;
break;
case V_302 :
case V_303 :
case V_304 :
V_294 . V_305 = true ;
break;
default:
F_44 ( V_3 , L_29 , V_124 ) ;
V_294 . V_305 = true ;
break;
}
F_67 ( V_3 , V_276 , L_30 ,
V_292 -> V_295 . V_306 ) ;
for ( V_12 = 0 ; V_12 < V_292 -> V_295 . V_306 ; V_12 ++ ) {
V_297 = V_292 -> V_295 . V_307 [ V_12 ] ;
V_294 . V_297 = F_58 ( V_297 ) ;
F_132 ( V_8 , & V_294 ) ;
}
}
static void F_133 ( struct V_2 * V_3 , struct V_291 * V_292 )
{
struct V_308 * V_86 = & V_292 -> V_309 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
T_5 V_73 , V_200 , V_167 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_200 = F_51 ( V_73 , V_310 ) ;
V_167 = F_51 ( V_73 , V_311 ) ;
F_67 ( V_3 , V_276 ,
L_31 ,
V_200 , V_167 , V_86 -> V_312 ) ;
F_29 ( & V_3 -> V_168 ) ;
V_162 = F_73 ( V_3 , V_167 ) ;
if ( ! V_162 ) {
F_44 ( V_3 , L_32 ,
V_167 ) ;
F_34 ( & V_3 -> V_168 ) ;
return;
}
V_164 = F_74 ( V_3 , V_162 -> V_173 ) ;
if ( ! V_164 ) {
F_44 ( V_3 , L_33 ,
V_162 -> V_173 ) ;
F_34 ( & V_3 -> V_168 ) ;
return;
}
F_67 ( V_3 , V_276 ,
L_34 ,
V_162 -> V_313 , V_200 , V_86 -> V_312 ) ;
F_134 ( V_164 -> V_174 , V_162 -> V_313 , V_200 ) ;
F_34 ( & V_3 -> V_168 ) ;
}
static void F_135 ( struct V_2 * V_3 , struct V_291 * V_292 )
{
struct V_314 * V_86 = & V_292 -> V_315 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
T_5 V_73 , V_200 , V_167 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_200 = F_51 ( V_73 , V_310 ) ;
V_167 = F_51 ( V_73 , V_311 ) ;
F_67 ( V_3 , V_276 ,
L_35 ,
V_200 , V_167 ) ;
F_29 ( & V_3 -> V_168 ) ;
V_162 = F_73 ( V_3 , V_167 ) ;
if ( ! V_162 ) {
F_44 ( V_3 , L_32 ,
V_167 ) ;
F_34 ( & V_3 -> V_168 ) ;
return;
}
V_164 = F_74 ( V_3 , V_162 -> V_173 ) ;
if ( ! V_164 ) {
F_44 ( V_3 , L_33 ,
V_162 -> V_173 ) ;
F_34 ( & V_3 -> V_168 ) ;
return;
}
F_67 ( V_3 , V_276 ,
L_36 ,
V_162 -> V_313 , V_200 ) ;
F_136 ( V_164 -> V_174 , V_162 -> V_313 , V_200 ) ;
F_34 ( & V_3 -> V_168 ) ;
}
static int F_137 ( struct V_62 * V_87 ,
struct V_62 * V_63 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
if ( F_54 ( V_87 ) )
return - V_316 ;
if ( F_75 ( ! F_54 ( V_63 ) ) )
return - V_100 ;
while ( ( V_56 = F_118 ( V_87 ) ) ) {
F_48 ( V_63 , V_56 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) )
break;
}
V_56 = F_114 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ) {
F_138 ( V_63 , V_87 ) ;
return - V_317 ;
}
return 0 ;
}
static void F_139 ( struct V_123 * V_124 ,
struct V_1 * V_9 )
{
struct V_196 * V_197 = (struct V_196 * ) V_9 -> V_36 ;
if ( ! F_140 ( V_197 -> V_201 ) )
return;
V_197 -> V_201 &= ~ F_116 ( V_269 ) ;
V_124 -> V_150 |= V_266 |
V_267 |
V_268 ;
}
static void F_141 ( struct V_2 * V_3 ,
struct V_62 * V_87 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_123 * V_124 = & V_8 -> V_204 ;
struct V_318 * V_280 ;
struct V_1 * V_56 ;
T_4 V_319 ;
while ( ( V_56 = F_118 ( V_87 ) ) ) {
V_280 = ( void * ) V_56 -> V_36 ;
F_49 ( V_56 , sizeof( * V_280 ) ) ;
F_18 ( V_56 , sizeof( * V_280 ) ) ;
if ( F_8 ( V_56 ) < F_58 ( V_280 -> V_64 ) ) {
F_44 ( V_3 , L_37 ) ;
F_10 ( V_56 ) ;
continue;
}
F_49 ( V_56 , F_58 ( V_280 -> V_64 ) ) ;
V_319 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_49 ( V_56 , V_319 ) ;
memmove ( V_56 -> V_36 + V_319 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_319 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_150 |= V_186 ;
F_139 ( V_124 , V_56 ) ;
F_82 ( V_3 , V_124 , NULL , V_280 -> V_173 ) ;
F_90 ( V_3 , V_124 , V_56 ) ;
}
}
static void F_142 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_291 * V_292 = ( void * ) V_9 -> V_36 ;
struct V_123 * V_124 = & V_8 -> V_204 ;
struct V_62 V_87 ;
struct V_62 V_63 ;
T_5 V_167 ;
T_5 V_92 ;
T_3 V_173 ;
T_3 V_200 ;
bool V_320 ;
bool V_289 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
F_18 ( V_9 , sizeof( V_292 -> V_197 ) ) ;
F_18 ( V_9 , sizeof( V_292 -> V_321 ) ) ;
V_167 = F_58 ( V_292 -> V_321 . V_167 ) ;
V_92 = F_58 ( V_292 -> V_321 . V_92 ) ;
V_173 = V_292 -> V_321 . V_173 ;
V_200 = F_143 ( V_292 -> V_321 . V_94 , V_322 ) ;
V_320 = ! ! ( V_292 -> V_321 . V_94 &
V_95 ) ;
V_289 = ! ! ( V_292 -> V_321 . V_94 & V_323 ) ;
F_67 ( V_3 , V_276 ,
L_38 ,
V_173 , V_167 , V_200 , V_320 , V_289 , V_92 ) ;
if ( V_9 -> V_16 < V_92 * sizeof( * V_292 -> V_321 . V_90 ) ) {
F_44 ( V_3 , L_39 ) ;
return;
}
F_129 ( & V_87 ) ;
V_26 = F_57 ( V_8 , & V_292 -> V_321 , & V_87 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_40 , V_26 ) ;
V_8 -> V_99 = true ;
return;
}
if ( V_320 )
F_141 ( V_3 , & V_87 ) ;
while ( ! F_54 ( & V_87 ) ) {
F_129 ( & V_63 ) ;
V_26 = F_137 ( & V_87 , & V_63 ) ;
switch ( V_26 ) {
case 0 :
F_85 ( V_3 , & V_63 , V_124 , V_173 ) ;
F_126 ( V_3 , & V_63 , V_124 ) ;
F_113 ( V_3 , & V_63 , V_124 ) ;
F_117 ( V_3 , & V_63 , V_124 ) ;
break;
case - V_317 :
default:
F_44 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_99 = true ;
F_47 ( & V_87 ) ;
return;
}
}
F_33 ( & V_8 -> V_49 ) ;
}
void F_144 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_291 * V_292 = (struct V_291 * ) V_9 -> V_36 ;
enum V_324 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_44 ( V_3 , L_42 ) ;
F_67 ( V_3 , V_276 , L_43 ,
V_292 -> V_197 . V_325 ) ;
if ( V_292 -> V_197 . V_325 >= V_3 -> V_8 . V_326 ) {
F_67 ( V_3 , V_276 , L_44 ,
V_292 -> V_197 . V_325 , V_3 -> V_8 . V_326 ) ;
F_10 ( V_9 ) ;
return;
}
type = V_3 -> V_8 . V_327 [ V_292 -> V_197 . V_325 ] ;
switch ( type ) {
case V_328 : {
V_8 -> V_329 = V_292 -> V_330 . V_331 ;
V_8 -> V_332 = V_292 -> V_330 . V_333 ;
F_145 ( & V_8 -> V_334 ) ;
break;
}
case V_335 :
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_53 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_336 : {
struct V_337 V_86 = {
. V_173 = V_292 -> V_338 . V_173 ,
. V_167 = F_58 ( V_292 -> V_338 . V_167 ) ,
} ;
memcpy ( V_86 . V_313 , V_292 -> V_338 . V_313 , sizeof( V_86 . V_313 ) ) ;
F_146 ( V_8 , & V_86 ) ;
break;
}
case V_339 : {
struct V_340 V_86 = {
. V_167 = F_58 ( V_292 -> V_341 . V_167 ) ,
} ;
F_147 ( V_8 , & V_86 ) ;
break;
}
case V_342 : {
struct V_293 V_294 = {} ;
int V_124 = F_15 ( V_292 -> V_343 . V_124 ) ;
V_294 . V_297 =
F_15 ( V_292 -> V_343 . V_344 ) ;
switch ( V_124 ) {
case V_345 :
V_294 . V_301 = true ;
break;
case V_346 :
V_294 . V_299 = true ;
break;
case V_347 :
V_294 . V_305 = true ;
break;
}
F_132 ( V_8 , & V_294 ) ;
break;
}
case V_348 :
F_148 ( & V_8 -> V_52 , V_9 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_349 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_350 * V_86 = & V_292 -> V_351 ;
F_67 ( V_3 , V_276 ,
L_45 ,
F_58 ( V_86 -> V_167 ) ,
! ! ( V_86 -> V_38 & V_352 ) ,
F_51 ( V_86 -> V_38 , V_353 ) ) ;
F_145 ( & V_3 -> V_354 ) ;
break;
}
case V_355 : {
F_45 ( V_3 , V_59 , NULL , L_46 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_130 ( V_8 , & V_292 -> V_356 ) ;
break;
}
case V_357 :
break;
case V_358 :
F_149 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_359 :
F_44 ( V_3 , L_47 ) ;
break;
case V_360 :
F_133 ( V_3 , V_292 ) ;
break;
case V_361 :
F_135 ( V_3 , V_292 ) ;
break;
case V_362 : {
struct V_363 * V_197 =
(struct V_363 * ) V_292 -> V_364 . V_365 ;
F_150 ( V_3 , V_292 -> V_364 . V_365 ,
sizeof( * V_197 ) +
F_58 ( V_197 -> V_19 ) ) ;
break;
}
case V_366 : {
break;
}
case V_367 : {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_54 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
}
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
case V_372 :
case V_373 :
case V_374 :
default:
F_44 ( V_3 , L_48 ,
V_292 -> V_197 . V_325 ) ;
F_45 ( V_3 , V_59 , NULL , L_46 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
F_10 ( V_9 ) ;
}
static void V_106 ( unsigned long V_84 )
{
struct V_7 * V_8 = (struct V_7 * ) V_84 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_291 * V_292 ;
struct V_1 * V_9 ;
while ( ( V_9 = F_151 ( & V_8 -> V_52 ) ) ) {
F_131 ( V_8 -> V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
while ( ( V_9 = F_118 ( & V_8 -> V_53 ) ) ) {
V_292 = (struct V_291 * ) V_9 -> V_36 ;
F_127 ( V_8 , & V_292 -> V_375 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_118 ( & V_8 -> V_54 ) ) ) {
F_142 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_13 . V_41 ) ;
}
