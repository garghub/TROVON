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
T_3 V_134 ;
T_1 V_135 , V_136 , V_137 ;
V_135 = F_15 ( V_91 -> V_138 . V_135 ) ;
V_136 = F_15 ( V_91 -> V_138 . V_136 ) ;
V_137 = F_15 ( V_91 -> V_138 . V_137 ) ;
V_133 = F_51 ( V_135 , V_139 ) ;
switch ( V_133 ) {
case V_140 :
if ( ! V_124 -> V_141 )
return;
V_127 = V_135 & V_142 ;
V_128 = F_51 ( V_135 , V_143 ) ;
V_128 &= ~ V_144 ;
V_126 = & V_3 -> V_145 . V_146 [ V_124 -> V_147 ] ;
V_124 -> V_148 = F_71 ( V_126 , V_128 ) ;
break;
case V_149 :
case V_150 :
V_131 = V_136 & 0x1F ;
V_132 = V_131 >> 3 ;
V_129 = ( V_136 >> 7 ) & 1 ;
V_130 = ( V_137 >> 7 ) & 1 ;
V_124 -> V_148 = V_131 ;
V_124 -> V_151 |= V_152 ;
if ( V_130 )
V_124 -> V_151 |= V_153 ;
if ( V_129 )
V_124 -> V_151 |= V_154 ;
break;
case V_155 :
case V_156 :
V_129 = V_136 & 3 ;
V_130 = V_137 & 1 ;
V_134 = ( V_136 >> 4 ) & 0x3F ;
if ( F_72 ( V_134 ) ) {
V_131 = ( V_137 >> 4 ) & 0x0F ;
V_132 = ( ( V_136 >> 10 ) & 0x07 ) + 1 ;
} else {
V_131 = 0 ;
V_132 = 1 ;
}
if ( V_131 > 0x09 ) {
F_44 ( V_3 , L_7 , V_131 ) ;
F_44 ( V_3 , L_8 ,
F_15 ( V_91 -> V_37 . V_38 ) ,
F_15 ( V_91 -> V_157 . V_73 ) ,
F_15 ( V_91 -> V_157 . V_135 ) ,
F_15 ( V_91 -> V_76 . V_77 . V_73 ) ,
F_15 ( V_91 -> V_76 . V_77 . V_135 ) ,
V_91 -> V_138 . V_73 ,
F_15 ( V_91 -> V_138 . V_135 ) ,
F_15 ( V_91 -> V_138 . V_136 ) ,
F_15 ( V_91 -> V_138 . V_137 ) ,
F_15 ( V_91 -> V_138 . V_158 ) ) ;
F_44 ( V_3 , L_9 ,
F_15 ( V_91 -> V_82 . V_77 . V_73 ) ,
F_15 ( V_91 -> V_159 . V_73 ) ) ;
F_45 ( V_3 , V_59 , NULL ,
L_10 ,
V_91 -> V_70 , 50 ) ;
}
V_124 -> V_148 = V_131 ;
V_124 -> V_160 = V_132 ;
if ( V_130 )
V_124 -> V_151 |= V_153 ;
switch ( V_129 ) {
case 0 :
break;
case 1 :
V_124 -> V_151 |= V_154 ;
break;
case 2 :
V_124 -> V_161 |= V_162 ;
}
V_124 -> V_151 |= V_163 ;
break;
default:
break;
}
}
static struct V_164 *
F_73 ( struct V_2 * V_3 , struct V_24 * V_91 )
{
struct V_165 * V_166 ;
struct V_167 * V_168 ;
struct V_169 V_170 ;
T_5 V_171 ;
F_27 ( & V_3 -> V_172 ) ;
if ( ! V_91 )
return NULL ;
if ( V_91 -> V_37 . V_38 &
F_20 ( V_173 ) )
return NULL ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_174 ) ) )
return NULL ;
V_171 = F_51 ( F_15 ( V_91 -> V_157 . V_73 ) ,
V_175 ) ;
V_166 = F_74 ( V_3 , V_171 ) ;
if ( ! V_166 )
return NULL ;
V_168 = F_75 ( V_3 , V_166 -> V_176 ) ;
if ( F_4 ( ! V_168 ) )
return NULL ;
if ( F_76 ( F_77 ( V_168 -> V_177 , & V_170 ) ) )
return NULL ;
return V_170 . V_178 ;
}
static struct V_164 *
F_78 ( struct V_2 * V_3 , T_1 V_176 )
{
struct V_167 * V_168 ;
struct V_169 V_170 ;
F_27 ( & V_3 -> V_172 ) ;
F_79 (arvif, &ar->arvifs, list) {
if ( V_168 -> V_176 == V_176 &&
F_77 ( V_168 -> V_177 , & V_170 ) == 0 )
return V_170 . V_178 ;
}
return NULL ;
}
static void
F_80 ( struct V_179 * V_180 ,
struct V_181 * V_182 ,
void * V_36 )
{
struct V_169 * V_170 = V_36 ;
* V_170 = V_182 -> V_170 ;
}
static struct V_164 *
F_81 ( struct V_2 * V_3 )
{
struct V_169 V_170 = {} ;
F_82 ( V_3 -> V_180 ,
F_80 ,
& V_170 ) ;
return V_170 . V_178 ;
}
static bool F_83 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 ,
T_1 V_176 )
{
struct V_164 * V_183 ;
F_29 ( & V_3 -> V_172 ) ;
V_183 = V_3 -> V_184 ;
if ( ! V_183 )
V_183 = V_3 -> V_185 ;
if ( ! V_183 )
V_183 = F_73 ( V_3 , V_91 ) ;
if ( ! V_183 )
V_183 = F_78 ( V_3 , V_176 ) ;
if ( ! V_183 )
V_183 = F_81 ( V_3 ) ;
F_34 ( & V_3 -> V_172 ) ;
if ( ! V_183 )
return false ;
V_124 -> V_147 = V_183 -> V_147 ;
V_124 -> V_141 = V_183 -> V_186 ;
return true ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 )
{
V_124 -> signal = V_187 +
V_91 -> V_138 . V_188 ;
V_124 -> V_151 &= ~ V_189 ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_24 * V_91 )
{
V_124 -> V_190 = F_15 ( V_91 -> V_191 . V_77 . V_192 ) ;
V_124 -> V_151 |= V_193 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_124 ,
T_1 V_176 )
{
struct V_1 * V_194 ;
struct V_24 * V_91 ;
bool V_195 ;
bool V_196 ;
if ( F_54 ( V_63 ) )
return;
V_194 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_194 -> V_36 - sizeof( * V_91 ) ;
V_195 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_197 ) ) ;
V_196 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_198 ) ) ;
if ( V_195 ) {
V_124 -> V_141 = 0 ;
V_124 -> V_148 = 0 ;
V_124 -> V_160 = 0 ;
V_124 -> V_161 &= ~ V_162 ;
V_124 -> V_151 &= ~ ( V_152 |
V_163 |
V_153 |
V_154 |
V_193 ) ;
V_124 -> V_151 |= V_189 ;
F_84 ( V_3 , V_124 , V_91 ) ;
F_83 ( V_3 , V_124 , V_91 , V_176 ) ;
F_70 ( V_3 , V_124 , V_91 ) ;
}
if ( V_196 )
F_85 ( V_3 , V_124 , V_91 ) ;
}
static char * F_88 ( struct V_199 * V_200 , char * V_201 , T_4 V_19 )
{
T_3 * V_202 ;
int V_203 ;
if ( ! F_89 ( V_200 -> V_204 ) )
return L_11 ;
V_202 = F_90 ( V_200 ) ;
V_203 = * V_202 & V_205 ;
if ( V_203 < 8 )
snprintf ( V_201 , V_19 , L_12 , V_203 , V_206 [ V_203 ] ) ;
else
snprintf ( V_201 , V_19 , L_13 , V_203 ) ;
return V_201 ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_123 * V_207 ,
struct V_1 * V_9 )
{
struct V_123 * V_124 ;
struct V_199 * V_200 = (struct V_199 * ) V_9 -> V_36 ;
char V_203 [ 32 ] ;
V_124 = F_92 ( V_9 ) ;
* V_124 = * V_207 ;
F_67 ( V_3 , V_208 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_93 ( V_200 ) ,
F_88 ( V_200 , V_203 , sizeof( V_203 ) ) ,
F_94 ( F_95 ( V_200 ) ) ?
L_15 : L_16 ,
( F_58 ( V_200 -> V_209 ) & V_210 ) >> 4 ,
V_124 -> V_151 == 0 ? L_17 : L_11 ,
V_124 -> V_151 & V_152 ? L_18 : L_11 ,
V_124 -> V_151 & V_163 ? L_19 : L_11 ,
V_124 -> V_151 & V_154 ? L_20 : L_11 ,
V_124 -> V_161 & V_162 ? L_21 : L_11 ,
V_124 -> V_151 & V_153 ? L_22 : L_11 ,
V_124 -> V_148 ,
V_124 -> V_160 ,
V_124 -> V_141 ,
V_124 -> V_147 , V_124 -> V_151 ,
! ! ( V_124 -> V_151 & V_211 ) ,
! ! ( V_124 -> V_151 & V_212 ) ,
! ! ( V_124 -> V_151 & V_213 ) ) ;
F_45 ( V_3 , V_59 , NULL , L_23 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_96 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_97 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_98 ( V_3 -> V_180 , V_9 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_199 * V_200 )
{
int V_16 = F_100 ( V_200 -> V_204 ) ;
if ( ! F_101 ( V_214 ,
V_3 -> V_215 ) )
V_16 = F_102 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
enum V_108 V_216 ,
bool V_217 )
{
struct V_199 * V_200 ;
struct V_24 * V_91 ;
T_4 V_218 ;
T_4 V_219 ;
bool V_220 ;
bool V_221 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_220 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_174 ) ) ;
V_221 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
if ( F_22 ( F_4 ( ! V_220 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_220 && V_221 ) ) ) )
return;
F_52 ( V_56 , V_56 -> V_16 - V_222 ) ;
if ( ! V_217 )
return;
V_200 = ( void * ) V_56 -> V_36 ;
F_52 ( V_56 , V_56 -> V_16 - F_69 ( V_3 , V_216 ) ) ;
if ( ! F_104 ( V_200 -> V_204 ) &&
V_216 == V_114 )
F_52 ( V_56 , V_56 -> V_16 - 8 ) ;
V_218 = F_100 ( V_200 -> V_204 ) ;
V_219 = F_68 ( V_3 , V_216 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_219 ,
( void * ) V_56 -> V_36 , V_218 ) ;
F_18 ( V_56 , V_219 ) ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
const T_3 V_223 [ 64 ] )
{
struct V_199 * V_200 ;
T_4 V_218 ;
T_3 V_224 [ V_225 ] ;
T_3 V_226 [ V_225 ] ;
V_200 = (struct V_199 * ) V_56 -> V_36 ;
V_218 = F_99 ( V_3 , V_200 ) ;
F_106 ( V_224 , F_95 ( V_200 ) ) ;
F_106 ( V_226 , F_93 ( V_200 ) ) ;
F_18 ( V_56 , V_218 ) ;
V_200 = (struct V_199 * ) V_223 ;
V_218 = F_100 ( V_200 -> V_204 ) ;
memcpy ( F_107 ( V_56 , V_218 ) , V_200 , V_218 ) ;
V_200 = (struct V_199 * ) V_56 -> V_36 ;
F_106 ( F_95 ( V_200 ) , V_224 ) ;
F_106 ( F_93 ( V_200 ) , V_226 ) ;
}
static void * F_108 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
enum V_108 V_216 )
{
struct V_199 * V_200 ;
struct V_24 * V_91 ;
T_4 V_218 , V_219 ;
void * V_227 ;
bool V_220 , V_221 , V_228 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_200 = ( void * ) V_91 -> V_229 ;
V_220 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_174 ) ) ;
V_221 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
V_228 = ! ( V_220 && V_221 ) ;
V_227 = V_200 ;
if ( V_220 ) {
V_218 = F_100 ( V_200 -> V_204 ) ;
V_219 = F_68 ( V_3 , V_216 ) ;
V_227 += F_102 ( V_218 , 4 ) +
F_102 ( V_219 , 4 ) ;
}
if ( V_228 )
V_227 += sizeof( struct V_230 ) ;
return V_227 ;
}
static void F_109 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
const T_3 V_223 [ 64 ] ,
enum V_108 V_216 )
{
struct V_199 * V_200 ;
struct V_231 * V_232 ;
T_4 V_218 ;
void * V_227 ;
T_3 V_224 [ V_225 ] ;
T_3 V_226 [ V_225 ] ;
V_227 = F_108 ( V_3 , V_56 , V_216 ) ;
if ( F_4 ( ! V_227 ) )
return;
V_232 = (struct V_231 * ) V_56 -> V_36 ;
F_106 ( V_224 , V_232 -> V_233 ) ;
F_106 ( V_226 , V_232 -> V_234 ) ;
F_18 ( V_56 , sizeof( struct V_231 ) ) ;
memcpy ( F_107 ( V_56 , sizeof( struct V_235 ) ) , V_227 ,
sizeof( struct V_235 ) ) ;
V_200 = (struct V_199 * ) V_223 ;
V_218 = F_100 ( V_200 -> V_204 ) ;
memcpy ( F_107 ( V_56 , V_218 ) , V_200 , V_218 ) ;
V_200 = (struct V_199 * ) V_56 -> V_36 ;
F_106 ( F_95 ( V_200 ) , V_224 ) ;
F_106 ( F_93 ( V_200 ) , V_226 ) ;
}
static void F_110 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
const T_3 V_223 [ 64 ] )
{
struct V_199 * V_200 ;
T_4 V_218 ;
F_18 ( V_56 , sizeof( struct V_230 ) ) ;
V_200 = (struct V_199 * ) V_223 ;
V_218 = F_100 ( V_200 -> V_204 ) ;
memcpy ( F_107 ( V_56 , V_218 ) , V_200 , V_218 ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_123 * V_124 ,
T_3 V_223 [ 64 ] ,
enum V_108 V_216 ,
bool V_217 )
{
struct V_24 * V_91 ;
enum V_236 V_237 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_237 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_135 ) ,
V_238 ) ;
switch ( V_237 ) {
case V_239 :
F_103 ( V_3 , V_56 , V_124 , V_216 ,
V_217 ) ;
break;
case V_240 :
F_105 ( V_3 , V_56 , V_124 , V_223 ) ;
break;
case V_241 :
F_109 ( V_3 , V_56 , V_124 , V_223 , V_216 ) ;
break;
case V_242 :
F_110 ( V_3 , V_56 , V_124 , V_223 ) ;
break;
}
}
static int F_112 ( struct V_1 * V_9 )
{
struct V_24 * V_91 ;
T_1 V_38 , V_94 ;
bool V_243 , V_244 ;
bool V_245 , V_246 ;
bool V_247 , V_248 ;
V_91 = ( void * ) V_9 -> V_36 - sizeof( * V_91 ) ;
V_38 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_94 = F_15 ( V_91 -> V_76 . V_77 . V_135 ) ;
V_243 = ! ! ( V_94 & V_249 ) ;
V_244 = ! ! ( V_94 & V_250 ) ;
V_245 = ! ! ( V_94 & V_251 ) ;
V_246 = ! ! ( V_94 & V_252 ) ;
V_247 = ! ( V_38 & V_253 ) ;
V_248 = ! ( V_38 & V_254 ) ;
if ( ! V_243 && ! V_244 )
return V_255 ;
if ( ! V_245 && ! V_246 )
return V_255 ;
if ( ! V_247 )
return V_255 ;
if ( ! V_248 )
return V_255 ;
return V_256 ;
}
static void F_113 ( struct V_1 * V_56 )
{
V_56 -> V_257 = F_112 ( V_56 ) ;
}
static void F_114 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_124 )
{
struct V_1 * V_194 ;
struct V_1 * V_258 ;
struct V_1 * V_56 ;
struct V_24 * V_91 ;
struct V_199 * V_200 ;
enum V_108 V_216 ;
T_3 V_223 [ 64 ] ;
T_3 * V_259 ;
T_4 V_218 ;
bool V_260 ;
bool V_261 ;
bool V_262 ;
bool V_263 ;
bool V_217 ;
T_1 V_37 ;
if ( F_54 ( V_63 ) )
return;
V_194 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_194 -> V_36 - sizeof( * V_91 ) ;
V_216 = F_51 ( F_15 ( V_91 -> V_157 . V_73 ) ,
V_264 ) ;
V_200 = ( void * ) V_91 -> V_229 ;
V_218 = F_100 ( V_200 -> V_204 ) ;
memcpy ( V_223 , V_200 , V_218 ) ;
V_200 = ( void * ) V_223 ;
V_259 = F_90 ( V_200 ) ;
V_259 [ 0 ] &= ~ V_265 ;
V_258 = F_115 ( V_63 ) ;
V_91 = ( void * ) V_258 -> V_36 - sizeof( * V_91 ) ;
V_37 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_260 = ! ! ( V_37 & V_266 ) ;
V_261 = ! ! ( V_37 & V_267 ) ;
V_262 = ! ! ( V_37 & V_268 ) ;
V_263 = ! ! ( V_37 & V_173 ) ;
V_217 = ( V_216 != V_109 &&
! V_260 &&
! V_261 &&
! V_263 ) ;
V_124 -> V_151 &= ~ ( V_211 |
V_212 |
V_269 |
V_270 |
V_271 ) ;
if ( V_260 )
V_124 -> V_151 |= V_211 ;
if ( V_262 )
V_124 -> V_151 |= V_212 ;
if ( V_217 )
V_124 -> V_151 |= V_269 |
V_270 |
V_271 ;
F_116 (amsdu, msdu) {
F_113 ( V_56 ) ;
F_111 ( V_3 , V_56 , V_124 , V_223 , V_216 ,
V_217 ) ;
if ( ! V_217 )
continue;
V_200 = ( void * ) V_56 -> V_36 ;
V_200 -> V_204 &= ~ F_117 ( V_272 ) ;
}
}
static void F_118 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_124 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_119 ( V_63 ) ) ) {
if ( F_54 ( V_63 ) )
V_124 -> V_151 &= ~ V_213 ;
else
V_124 -> V_151 |= V_213 ;
F_91 ( V_3 , V_124 , V_56 ) ;
}
}
static int F_120 ( struct V_62 * V_63 )
{
struct V_1 * V_9 , * V_194 ;
int V_273 ;
int V_274 = 0 ;
V_194 = F_119 ( V_63 ) ;
F_116 (amsdu, skb)
V_274 += V_9 -> V_16 ;
V_273 = V_274 - F_8 ( V_194 ) ;
if ( ( V_273 > 0 ) &&
( F_121 ( V_194 , 0 , V_273 , V_275 ) < 0 ) ) {
F_122 ( V_63 , V_194 ) ;
return - 1 ;
}
while ( ( V_9 = F_119 ( V_63 ) ) ) {
F_123 ( V_9 , F_49 ( V_194 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_122 ( V_63 , V_194 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
bool V_276 )
{
struct V_1 * V_194 ;
struct V_24 * V_91 ;
enum V_236 V_237 ;
V_194 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_194 -> V_36 - sizeof( * V_91 ) ;
V_237 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_135 ) ,
V_238 ) ;
if ( ! V_276 )
return;
if ( V_237 != V_239 ||
F_125 ( V_63 ) != 1 + V_91 -> V_79 . V_80 ) {
F_47 ( V_63 ) ;
return;
}
F_120 ( V_63 ) ;
}
static bool F_126 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_207 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
bool V_277 ;
bool V_260 ;
V_56 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! V_207 -> V_141 ) {
F_44 ( V_3 , L_24 ) ;
return false ;
}
V_277 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_278 ) ) ;
V_260 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_266 ) ) ;
if ( V_277 && ! V_260 ) {
F_67 ( V_3 , V_279 , L_25 ) ;
return false ;
}
if ( F_101 ( V_280 , & V_3 -> V_281 ) ) {
F_67 ( V_3 , V_279 , L_26 ) ;
return false ;
}
return true ;
}
static void F_127 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_123 * V_207 )
{
if ( F_54 ( V_63 ) )
return;
if ( F_126 ( V_3 , V_63 , V_207 ) )
return;
F_47 ( V_63 ) ;
}
static void F_128 ( struct V_7 * V_8 ,
struct V_282 * V_283 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_123 * V_207 = & V_8 -> V_207 ;
struct V_284 * V_285 ;
struct V_62 V_63 ;
int V_286 ;
int V_61 ;
T_3 * V_60 ;
int V_12 , V_26 , V_287 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
V_61 = F_58 ( V_283 -> V_288 . V_289 ) ;
V_60 = ( T_3 * ) & V_283 -> V_60 ;
V_286 = F_51 ( F_15 ( V_283 -> V_200 . V_135 ) ,
V_290 ) ;
V_285 = F_129 ( V_283 ) ;
F_45 ( V_3 , V_59 , NULL , L_27 ,
V_283 , sizeof( * V_283 ) +
( sizeof( struct V_284 ) *
V_286 ) ) ;
for ( V_12 = 0 ; V_12 < V_286 ; V_12 ++ )
V_287 += V_285 [ V_12 ] . V_287 ;
while ( V_287 -- ) {
F_130 ( & V_63 ) ;
V_26 = F_46 ( V_8 , & V_60 ,
& V_61 , & V_63 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_28 , V_26 ) ;
F_47 ( & V_63 ) ;
V_8 -> V_99 = true ;
break;
}
F_86 ( V_3 , & V_63 , V_207 , 0xffff ) ;
F_124 ( V_3 , & V_63 , V_26 > 0 ) ;
F_127 ( V_3 , & V_63 , V_207 ) ;
F_114 ( V_3 , & V_63 , V_207 ) ;
F_118 ( V_3 , & V_63 , V_207 ) ;
}
F_33 ( & V_8 -> V_49 ) ;
}
static void F_131 ( struct V_7 * V_8 ,
struct V_291 * V_292 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_123 * V_207 = & V_8 -> V_207 ;
struct V_62 V_63 ;
int V_26 ;
T_3 * V_60 ;
int V_61 ;
V_61 = F_58 ( V_292 -> V_289 ) ;
V_60 = ( T_3 * ) V_292 -> V_293 ;
F_130 ( & V_63 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
V_26 = F_46 ( V_8 , & V_60 , & V_61 ,
& V_63 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_49 ) ;
F_67 ( V_3 , V_59 , L_29 ) ;
if ( V_26 ) {
F_44 ( V_3 , L_30 ,
V_26 ) ;
F_47 ( & V_63 ) ;
return;
}
if ( F_125 ( & V_63 ) != 1 ) {
F_44 ( V_3 , L_31 ) ;
F_47 ( & V_63 ) ;
return;
}
F_86 ( V_3 , & V_63 , V_207 , 0xffff ) ;
F_127 ( V_3 , & V_63 , V_207 ) ;
F_114 ( V_3 , & V_63 , V_207 ) ;
F_118 ( V_3 , & V_63 , V_207 ) ;
if ( V_61 > 0 ) {
F_67 ( V_3 , V_279 ,
L_32 ,
V_61 ) ;
}
}
static void F_132 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
struct V_296 V_297 = {} ;
int V_124 = F_51 ( V_295 -> V_298 . V_38 , V_299 ) ;
T_6 V_300 ;
int V_12 ;
switch ( V_124 ) {
case V_301 :
V_297 . V_302 = true ;
break;
case V_303 :
V_297 . V_304 = true ;
break;
case V_305 :
case V_306 :
case V_307 :
V_297 . V_308 = true ;
break;
default:
F_44 ( V_3 , L_33 , V_124 ) ;
V_297 . V_308 = true ;
break;
}
F_67 ( V_3 , V_279 , L_34 ,
V_295 -> V_298 . V_309 ) ;
for ( V_12 = 0 ; V_12 < V_295 -> V_298 . V_309 ; V_12 ++ ) {
V_300 = V_295 -> V_298 . V_310 [ V_12 ] ;
V_297 . V_300 = F_58 ( V_300 ) ;
F_133 ( V_8 , & V_297 ) ;
}
}
static void F_134 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_311 * V_86 = & V_295 -> V_312 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
T_5 V_73 , V_203 , V_171 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_203 = F_51 ( V_73 , V_313 ) ;
V_171 = F_51 ( V_73 , V_314 ) ;
F_67 ( V_3 , V_279 ,
L_35 ,
V_203 , V_171 , V_86 -> V_315 ) ;
F_29 ( & V_3 -> V_172 ) ;
V_166 = F_74 ( V_3 , V_171 ) ;
if ( ! V_166 ) {
F_44 ( V_3 , L_36 ,
V_171 ) ;
F_34 ( & V_3 -> V_172 ) ;
return;
}
V_168 = F_75 ( V_3 , V_166 -> V_176 ) ;
if ( ! V_168 ) {
F_44 ( V_3 , L_37 ,
V_166 -> V_176 ) ;
F_34 ( & V_3 -> V_172 ) ;
return;
}
F_67 ( V_3 , V_279 ,
L_38 ,
V_166 -> V_316 , V_203 , V_86 -> V_315 ) ;
F_135 ( V_168 -> V_177 , V_166 -> V_316 , V_203 ) ;
F_34 ( & V_3 -> V_172 ) ;
}
static void F_136 ( struct V_2 * V_3 , struct V_294 * V_295 )
{
struct V_317 * V_86 = & V_295 -> V_318 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
T_5 V_73 , V_203 , V_171 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_203 = F_51 ( V_73 , V_313 ) ;
V_171 = F_51 ( V_73 , V_314 ) ;
F_67 ( V_3 , V_279 ,
L_39 ,
V_203 , V_171 ) ;
F_29 ( & V_3 -> V_172 ) ;
V_166 = F_74 ( V_3 , V_171 ) ;
if ( ! V_166 ) {
F_44 ( V_3 , L_36 ,
V_171 ) ;
F_34 ( & V_3 -> V_172 ) ;
return;
}
V_168 = F_75 ( V_3 , V_166 -> V_176 ) ;
if ( ! V_168 ) {
F_44 ( V_3 , L_37 ,
V_166 -> V_176 ) ;
F_34 ( & V_3 -> V_172 ) ;
return;
}
F_67 ( V_3 , V_279 ,
L_40 ,
V_166 -> V_316 , V_203 ) ;
F_137 ( V_168 -> V_177 , V_166 -> V_316 , V_203 ) ;
F_34 ( & V_3 -> V_172 ) ;
}
static int F_138 ( struct V_62 * V_87 ,
struct V_62 * V_63 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
if ( F_54 ( V_87 ) )
return - V_319 ;
if ( F_76 ( ! F_54 ( V_63 ) ) )
return - V_100 ;
while ( ( V_56 = F_119 ( V_87 ) ) ) {
F_48 ( V_63 , V_56 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) )
break;
}
V_56 = F_115 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ) {
F_139 ( V_63 , V_87 ) ;
return - V_320 ;
}
return 0 ;
}
static void F_140 ( struct V_123 * V_124 ,
struct V_1 * V_9 )
{
struct V_199 * V_200 = (struct V_199 * ) V_9 -> V_36 ;
if ( ! F_141 ( V_200 -> V_204 ) )
return;
V_200 -> V_204 &= ~ F_117 ( V_272 ) ;
V_124 -> V_151 |= V_269 |
V_270 |
V_271 ;
}
static void F_142 ( struct V_2 * V_3 ,
struct V_62 * V_87 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_123 * V_124 = & V_8 -> V_207 ;
struct V_321 * V_283 ;
struct V_1 * V_56 ;
T_4 V_322 ;
while ( ( V_56 = F_119 ( V_87 ) ) ) {
V_283 = ( void * ) V_56 -> V_36 ;
F_49 ( V_56 , sizeof( * V_283 ) ) ;
F_18 ( V_56 , sizeof( * V_283 ) ) ;
if ( F_8 ( V_56 ) < F_58 ( V_283 -> V_64 ) ) {
F_44 ( V_3 , L_41 ) ;
F_10 ( V_56 ) ;
continue;
}
F_49 ( V_56 , F_58 ( V_283 -> V_64 ) ) ;
V_322 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_49 ( V_56 , V_322 ) ;
memmove ( V_56 -> V_36 + V_322 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_322 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_151 |= V_189 ;
F_140 ( V_124 , V_56 ) ;
F_83 ( V_3 , V_124 , NULL , V_283 -> V_176 ) ;
F_91 ( V_3 , V_124 , V_56 ) ;
}
}
static void F_143 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = ( void * ) V_9 -> V_36 ;
struct V_123 * V_124 = & V_8 -> V_207 ;
struct V_62 V_87 ;
struct V_62 V_63 ;
T_5 V_171 ;
T_5 V_92 ;
T_3 V_176 ;
T_3 V_203 ;
bool V_323 ;
bool V_292 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
F_18 ( V_9 , sizeof( V_295 -> V_200 ) ) ;
F_18 ( V_9 , sizeof( V_295 -> V_324 ) ) ;
V_171 = F_58 ( V_295 -> V_324 . V_171 ) ;
V_92 = F_58 ( V_295 -> V_324 . V_92 ) ;
V_176 = V_295 -> V_324 . V_176 ;
V_203 = F_144 ( V_295 -> V_324 . V_94 , V_325 ) ;
V_323 = ! ! ( V_295 -> V_324 . V_94 &
V_95 ) ;
V_292 = ! ! ( V_295 -> V_324 . V_94 & V_326 ) ;
F_67 ( V_3 , V_279 ,
L_42 ,
V_176 , V_171 , V_203 , V_323 , V_292 , V_92 ) ;
if ( V_9 -> V_16 < V_92 * sizeof( * V_295 -> V_324 . V_90 ) ) {
F_44 ( V_3 , L_43 ) ;
return;
}
F_130 ( & V_87 ) ;
V_26 = F_57 ( V_8 , & V_295 -> V_324 , & V_87 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_44 , V_26 ) ;
V_8 -> V_99 = true ;
return;
}
if ( V_323 )
F_142 ( V_3 , & V_87 ) ;
while ( ! F_54 ( & V_87 ) ) {
F_130 ( & V_63 ) ;
V_26 = F_138 ( & V_87 , & V_63 ) ;
switch ( V_26 ) {
case 0 :
F_86 ( V_3 , & V_63 , V_124 , V_176 ) ;
F_127 ( V_3 , & V_63 , V_124 ) ;
F_114 ( V_3 , & V_63 , V_124 ) ;
F_118 ( V_3 , & V_63 , V_124 ) ;
break;
case - V_320 :
default:
F_44 ( V_3 , L_45 , V_26 ) ;
V_8 -> V_99 = true ;
F_47 ( & V_87 ) ;
return;
}
}
F_33 ( & V_8 -> V_49 ) ;
}
void F_145 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_294 * V_295 = (struct V_294 * ) V_9 -> V_36 ;
enum V_327 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_44 ( V_3 , L_46 ) ;
F_67 ( V_3 , V_279 , L_47 ,
V_295 -> V_200 . V_328 ) ;
if ( V_295 -> V_200 . V_328 >= V_3 -> V_8 . V_329 ) {
F_67 ( V_3 , V_279 , L_48 ,
V_295 -> V_200 . V_328 , V_3 -> V_8 . V_329 ) ;
F_10 ( V_9 ) ;
return;
}
type = V_3 -> V_8 . V_330 [ V_295 -> V_200 . V_328 ] ;
switch ( type ) {
case V_331 : {
V_8 -> V_332 = V_295 -> V_333 . V_334 ;
V_8 -> V_335 = V_295 -> V_333 . V_336 ;
F_146 ( & V_8 -> V_337 ) ;
break;
}
case V_338 :
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_53 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_339 : {
struct V_340 V_86 = {
. V_176 = V_295 -> V_341 . V_176 ,
. V_171 = F_58 ( V_295 -> V_341 . V_171 ) ,
} ;
memcpy ( V_86 . V_316 , V_295 -> V_341 . V_316 , sizeof( V_86 . V_316 ) ) ;
F_147 ( V_8 , & V_86 ) ;
break;
}
case V_342 : {
struct V_343 V_86 = {
. V_171 = F_58 ( V_295 -> V_344 . V_171 ) ,
} ;
F_148 ( V_8 , & V_86 ) ;
break;
}
case V_345 : {
struct V_296 V_297 = {} ;
int V_124 = F_15 ( V_295 -> V_346 . V_124 ) ;
V_297 . V_300 =
F_15 ( V_295 -> V_346 . V_347 ) ;
switch ( V_124 ) {
case V_348 :
V_297 . V_304 = true ;
break;
case V_349 :
V_297 . V_302 = true ;
break;
case V_350 :
V_297 . V_308 = true ;
break;
}
F_133 ( V_8 , & V_297 ) ;
break;
}
case V_351 :
F_149 ( & V_8 -> V_52 , V_9 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_352 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_353 * V_86 = & V_295 -> V_354 ;
F_67 ( V_3 , V_279 ,
L_49 ,
F_58 ( V_86 -> V_171 ) ,
! ! ( V_86 -> V_38 & V_355 ) ,
F_51 ( V_86 -> V_38 , V_356 ) ) ;
F_146 ( & V_3 -> V_357 ) ;
break;
}
case V_358 : {
F_45 ( V_3 , V_59 , NULL , L_50 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_131 ( V_8 , & V_295 -> V_359 ) ;
break;
}
case V_360 :
break;
case V_361 :
F_150 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_362 :
F_44 ( V_3 , L_51 ) ;
break;
case V_363 :
F_134 ( V_3 , V_295 ) ;
break;
case V_364 :
F_136 ( V_3 , V_295 ) ;
break;
case V_365 : {
struct V_366 * V_200 =
(struct V_366 * ) V_295 -> V_367 . V_368 ;
F_151 ( V_3 , V_295 -> V_367 . V_368 ,
sizeof( * V_200 ) +
F_58 ( V_200 -> V_19 ) ) ;
break;
}
case V_369 : {
break;
}
case V_370 : {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_54 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
}
case V_371 :
break;
case V_372 :
break;
case V_373 :
break;
case V_374 :
case V_375 :
case V_376 :
case V_377 :
default:
F_44 ( V_3 , L_52 ,
V_295 -> V_200 . V_328 ) ;
F_45 ( V_3 , V_59 , NULL , L_50 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
F_10 ( V_9 ) ;
}
static void V_106 ( unsigned long V_84 )
{
struct V_7 * V_8 = (struct V_7 * ) V_84 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_294 * V_295 ;
struct V_1 * V_9 ;
while ( ( V_9 = F_152 ( & V_8 -> V_52 ) ) ) {
F_132 ( V_8 -> V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_29 ( & V_8 -> V_13 . V_41 ) ;
while ( ( V_9 = F_119 ( & V_8 -> V_53 ) ) ) {
V_295 = (struct V_294 * ) V_9 -> V_36 ;
F_128 ( V_8 , & V_295 -> V_378 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_119 ( & V_8 -> V_54 ) ) ) {
F_143 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_13 . V_41 ) ;
}
