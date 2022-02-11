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
V_31 = F_62 ( V_8 -> V_3 -> V_15 , V_19 , & V_4 , V_101 ) ;
if ( ! V_31 )
goto V_103;
V_8 -> V_13 . V_39 = V_31 ;
V_8 -> V_13 . V_55 = V_4 ;
V_31 = F_62 ( V_8 -> V_3 -> V_15 ,
sizeof( * V_8 -> V_13 . V_30 . V_31 ) ,
& V_4 , V_101 ) ;
if ( ! V_31 )
goto V_104;
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
V_102:
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
struct V_24 * V_91 )
{
struct V_124 * V_125 ;
T_3 V_126 , V_127 , V_128 , V_129 , V_130 , V_131 ;
T_3 V_132 = 0 ;
T_3 V_133 ;
T_1 V_134 , V_135 , V_136 ;
V_134 = F_15 ( V_91 -> V_137 . V_134 ) ;
V_135 = F_15 ( V_91 -> V_137 . V_135 ) ;
V_136 = F_15 ( V_91 -> V_137 . V_136 ) ;
V_132 = F_51 ( V_134 , V_138 ) ;
switch ( V_132 ) {
case V_139 :
if ( ! V_123 -> V_140 )
return;
V_126 = V_134 & V_141 ;
V_127 = F_51 ( V_134 , V_142 ) ;
V_127 &= ~ V_143 ;
V_125 = & V_3 -> V_144 . V_145 [ V_123 -> V_146 ] ;
V_123 -> V_147 = F_71 ( V_125 , V_127 , V_126 ) ;
break;
case V_148 :
case V_149 :
V_130 = V_135 & 0x1F ;
V_131 = V_130 >> 3 ;
V_128 = ( V_135 >> 7 ) & 1 ;
V_129 = ( V_136 >> 7 ) & 1 ;
V_123 -> V_147 = V_130 ;
V_123 -> V_150 |= V_151 ;
if ( V_129 )
V_123 -> V_150 |= V_152 ;
if ( V_128 )
V_123 -> V_150 |= V_153 ;
break;
case V_154 :
case V_155 :
V_128 = V_135 & 3 ;
V_129 = V_136 & 1 ;
V_133 = ( V_135 >> 4 ) & 0x3F ;
if ( F_72 ( V_133 ) ) {
V_130 = ( V_136 >> 4 ) & 0x0F ;
V_131 = ( ( V_135 >> 10 ) & 0x07 ) + 1 ;
} else {
V_130 = 0 ;
V_131 = 1 ;
}
if ( V_130 > 0x09 ) {
F_44 ( V_3 , L_7 , V_130 ) ;
F_44 ( V_3 , L_8 ,
F_15 ( V_91 -> V_37 . V_38 ) ,
F_15 ( V_91 -> V_156 . V_73 ) ,
F_15 ( V_91 -> V_156 . V_134 ) ,
F_15 ( V_91 -> V_76 . V_77 . V_73 ) ,
F_15 ( V_91 -> V_76 . V_77 . V_134 ) ,
V_91 -> V_137 . V_73 ,
F_15 ( V_91 -> V_137 . V_134 ) ,
F_15 ( V_91 -> V_137 . V_135 ) ,
F_15 ( V_91 -> V_137 . V_136 ) ,
F_15 ( V_91 -> V_137 . V_157 ) ) ;
F_44 ( V_3 , L_9 ,
F_15 ( V_91 -> V_82 . V_77 . V_73 ) ,
F_15 ( V_91 -> V_158 . V_73 ) ) ;
F_45 ( V_3 , V_59 , NULL ,
L_10 ,
V_91 -> V_70 , 50 ) ;
}
V_123 -> V_147 = V_130 ;
V_123 -> V_159 = V_131 ;
if ( V_129 )
V_123 -> V_150 |= V_152 ;
switch ( V_128 ) {
case 0 :
break;
case 1 :
V_123 -> V_150 |= V_153 ;
break;
case 2 :
V_123 -> V_160 |= V_161 ;
}
V_123 -> V_150 |= V_162 ;
break;
default:
break;
}
}
static struct V_163 *
F_73 ( struct V_2 * V_3 , struct V_24 * V_91 )
{
struct V_164 * V_165 ;
struct V_166 * V_167 ;
struct V_168 V_169 ;
T_5 V_170 ;
F_27 ( & V_3 -> V_171 ) ;
if ( ! V_91 )
return NULL ;
if ( V_91 -> V_37 . V_38 &
F_20 ( V_172 ) )
return NULL ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_173 ) ) )
return NULL ;
V_170 = F_51 ( F_15 ( V_91 -> V_156 . V_73 ) ,
V_174 ) ;
V_165 = F_74 ( V_3 , V_170 ) ;
if ( ! V_165 )
return NULL ;
V_167 = F_75 ( V_3 , V_165 -> V_175 ) ;
if ( F_4 ( ! V_167 ) )
return NULL ;
if ( F_76 ( F_77 ( V_167 -> V_176 , & V_169 ) ) )
return NULL ;
return V_169 . V_177 ;
}
static struct V_163 *
F_78 ( struct V_2 * V_3 , T_1 V_175 )
{
struct V_166 * V_167 ;
struct V_168 V_169 ;
F_27 ( & V_3 -> V_171 ) ;
F_79 (arvif, &ar->arvifs, list) {
if ( V_167 -> V_175 == V_175 &&
F_77 ( V_167 -> V_176 , & V_169 ) == 0 )
return V_169 . V_177 ;
}
return NULL ;
}
static void
F_80 ( struct V_178 * V_179 ,
struct V_180 * V_181 ,
void * V_36 )
{
struct V_168 * V_169 = V_36 ;
* V_169 = V_181 -> V_169 ;
}
static struct V_163 *
F_81 ( struct V_2 * V_3 )
{
struct V_168 V_169 = {} ;
F_82 ( V_3 -> V_179 ,
F_80 ,
& V_169 ) ;
return V_169 . V_177 ;
}
static bool F_83 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_91 ,
T_1 V_175 )
{
struct V_163 * V_182 ;
F_29 ( & V_3 -> V_171 ) ;
V_182 = V_3 -> V_183 ;
if ( ! V_182 )
V_182 = V_3 -> V_184 ;
if ( ! V_182 )
V_182 = F_73 ( V_3 , V_91 ) ;
if ( ! V_182 )
V_182 = F_78 ( V_3 , V_175 ) ;
if ( ! V_182 )
V_182 = F_81 ( V_3 ) ;
F_34 ( & V_3 -> V_171 ) ;
if ( ! V_182 )
return false ;
V_123 -> V_146 = V_182 -> V_146 ;
V_123 -> V_140 = V_182 -> V_185 ;
return true ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_91 )
{
V_123 -> signal = V_186 +
V_91 -> V_137 . V_187 ;
V_123 -> V_150 &= ~ V_188 ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_91 )
{
V_123 -> V_189 = F_15 ( V_91 -> V_190 . V_77 . V_191 ) ;
V_123 -> V_150 |= V_192 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 ,
T_1 V_175 )
{
struct V_1 * V_193 ;
struct V_24 * V_91 ;
bool V_194 ;
bool V_195 ;
if ( F_54 ( V_63 ) )
return;
V_193 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_193 -> V_36 - sizeof( * V_91 ) ;
V_194 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_196 ) ) ;
V_195 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_197 ) ) ;
if ( V_194 ) {
V_123 -> V_140 = 0 ;
V_123 -> V_147 = 0 ;
V_123 -> V_159 = 0 ;
V_123 -> V_160 &= ~ V_161 ;
V_123 -> V_150 &= ~ ( V_151 |
V_162 |
V_152 |
V_153 |
V_192 ) ;
V_123 -> V_150 |= V_188 ;
F_84 ( V_3 , V_123 , V_91 ) ;
F_83 ( V_3 , V_123 , V_91 , V_175 ) ;
F_70 ( V_3 , V_123 , V_91 ) ;
}
if ( V_195 )
F_85 ( V_3 , V_123 , V_91 ) ;
}
static char * F_88 ( struct V_198 * V_199 , char * V_200 , T_4 V_19 )
{
T_3 * V_201 ;
int V_202 ;
if ( ! F_89 ( V_199 -> V_203 ) )
return L_11 ;
V_201 = F_90 ( V_199 ) ;
V_202 = * V_201 & V_204 ;
if ( V_202 < 8 )
snprintf ( V_200 , V_19 , L_12 , V_202 , V_205 [ V_202 ] ) ;
else
snprintf ( V_200 , V_19 , L_13 , V_202 ) ;
return V_200 ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_122 * V_206 ,
struct V_1 * V_9 )
{
struct V_122 * V_123 ;
struct V_198 * V_199 = (struct V_198 * ) V_9 -> V_36 ;
char V_202 [ 32 ] ;
V_123 = F_92 ( V_9 ) ;
* V_123 = * V_206 ;
F_67 ( V_3 , V_207 ,
L_14 ,
V_9 ,
V_9 -> V_16 ,
F_93 ( V_199 ) ,
F_88 ( V_199 , V_202 , sizeof( V_202 ) ) ,
F_94 ( F_95 ( V_199 ) ) ?
L_15 : L_16 ,
( F_58 ( V_199 -> V_208 ) & V_209 ) >> 4 ,
V_123 -> V_150 == 0 ? L_17 : L_11 ,
V_123 -> V_150 & V_151 ? L_18 : L_11 ,
V_123 -> V_150 & V_162 ? L_19 : L_11 ,
V_123 -> V_150 & V_153 ? L_20 : L_11 ,
V_123 -> V_160 & V_161 ? L_21 : L_11 ,
V_123 -> V_150 & V_152 ? L_22 : L_11 ,
V_123 -> V_147 ,
V_123 -> V_159 ,
V_123 -> V_140 ,
V_123 -> V_146 , V_123 -> V_150 ,
! ! ( V_123 -> V_150 & V_210 ) ,
! ! ( V_123 -> V_150 & V_211 ) ,
! ! ( V_123 -> V_150 & V_212 ) ) ;
F_45 ( V_3 , V_59 , NULL , L_23 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_96 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_97 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_98 ( V_3 -> V_179 , V_9 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_198 * V_199 )
{
int V_16 = F_100 ( V_199 -> V_203 ) ;
if ( ! F_101 ( V_213 ,
V_3 -> V_214 ) )
V_16 = F_102 ( V_16 , 4 ) ;
return V_16 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
enum V_107 V_215 ,
bool V_216 )
{
struct V_198 * V_199 ;
struct V_24 * V_91 ;
T_4 V_217 ;
T_4 V_218 ;
bool V_219 ;
bool V_220 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_219 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_173 ) ) ;
V_220 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
if ( F_22 ( F_4 ( ! V_219 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_219 && V_220 ) ) ) )
return;
F_52 ( V_56 , V_56 -> V_16 - V_221 ) ;
if ( ! V_216 )
return;
V_199 = ( void * ) V_56 -> V_36 ;
F_52 ( V_56 , V_56 -> V_16 - F_69 ( V_3 , V_215 ) ) ;
if ( ! F_104 ( V_199 -> V_203 ) &&
V_215 == V_113 )
F_52 ( V_56 , V_56 -> V_16 - 8 ) ;
V_217 = F_100 ( V_199 -> V_203 ) ;
V_218 = F_68 ( V_3 , V_215 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_218 ,
( void * ) V_56 -> V_36 , V_217 ) ;
F_18 ( V_56 , V_218 ) ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_222 [ 64 ] )
{
struct V_198 * V_199 ;
T_4 V_217 ;
T_3 V_223 [ V_224 ] ;
T_3 V_225 [ V_224 ] ;
if ( ( V_3 -> V_226 . V_227 == V_228 ) &&
F_106 ( ( (struct V_198 * ) V_222 ) -> V_203 ) ) {
V_199 = (struct V_198 * ) ( V_56 -> V_36 + 2 ) ;
F_49 ( V_56 , 2 ) ;
} else {
V_199 = (struct V_198 * ) ( V_56 -> V_36 ) ;
}
V_217 = F_99 ( V_3 , V_199 ) ;
F_107 ( V_223 , F_95 ( V_199 ) ) ;
F_107 ( V_225 , F_93 ( V_199 ) ) ;
F_18 ( V_56 , V_217 ) ;
V_199 = (struct V_198 * ) V_222 ;
V_217 = F_100 ( V_199 -> V_203 ) ;
memcpy ( F_108 ( V_56 , V_217 ) , V_199 , V_217 ) ;
V_199 = (struct V_198 * ) V_56 -> V_36 ;
F_107 ( F_95 ( V_199 ) , V_223 ) ;
F_107 ( F_93 ( V_199 ) , V_225 ) ;
}
static void * F_109 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
enum V_107 V_215 )
{
struct V_198 * V_199 ;
struct V_24 * V_91 ;
T_4 V_217 , V_218 ;
void * V_229 ;
bool V_219 , V_220 , V_230 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_199 = ( void * ) V_91 -> V_231 ;
V_219 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_173 ) ) ;
V_220 = ! ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ;
V_230 = ! ( V_219 && V_220 ) ;
V_229 = V_199 ;
if ( V_219 ) {
V_217 = F_100 ( V_199 -> V_203 ) ;
V_218 = F_68 ( V_3 , V_215 ) ;
V_229 += F_102 ( V_217 , 4 ) +
F_102 ( V_218 , 4 ) ;
}
if ( V_230 )
V_229 += sizeof( struct V_232 ) ;
return V_229 ;
}
static void F_110 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_222 [ 64 ] ,
enum V_107 V_215 )
{
struct V_198 * V_199 ;
struct V_233 * V_234 ;
T_4 V_217 ;
void * V_229 ;
T_3 V_223 [ V_224 ] ;
T_3 V_225 [ V_224 ] ;
V_229 = F_109 ( V_3 , V_56 , V_215 ) ;
if ( F_4 ( ! V_229 ) )
return;
V_234 = (struct V_233 * ) V_56 -> V_36 ;
F_107 ( V_223 , V_234 -> V_235 ) ;
F_107 ( V_225 , V_234 -> V_236 ) ;
F_18 ( V_56 , sizeof( struct V_233 ) ) ;
memcpy ( F_108 ( V_56 , sizeof( struct V_237 ) ) , V_229 ,
sizeof( struct V_237 ) ) ;
V_199 = (struct V_198 * ) V_222 ;
V_217 = F_100 ( V_199 -> V_203 ) ;
memcpy ( F_108 ( V_56 , V_217 ) , V_199 , V_217 ) ;
V_199 = (struct V_198 * ) V_56 -> V_36 ;
F_107 ( F_95 ( V_199 ) , V_223 ) ;
F_107 ( F_93 ( V_199 ) , V_225 ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_222 [ 64 ] )
{
struct V_198 * V_199 ;
T_4 V_217 ;
F_18 ( V_56 , sizeof( struct V_232 ) ) ;
V_199 = (struct V_198 * ) V_222 ;
V_217 = F_100 ( V_199 -> V_203 ) ;
memcpy ( F_108 ( V_56 , V_217 ) , V_199 , V_217 ) ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
T_3 V_222 [ 64 ] ,
enum V_107 V_215 ,
bool V_216 )
{
struct V_24 * V_91 ;
enum V_238 V_239 ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
V_239 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_134 ) ,
V_240 ) ;
switch ( V_239 ) {
case V_241 :
F_103 ( V_3 , V_56 , V_123 , V_215 ,
V_216 ) ;
break;
case V_242 :
F_105 ( V_3 , V_56 , V_123 , V_222 ) ;
break;
case V_243 :
F_110 ( V_3 , V_56 , V_123 , V_222 , V_215 ) ;
break;
case V_244 :
F_111 ( V_3 , V_56 , V_123 , V_222 ) ;
break;
}
}
static int F_113 ( struct V_1 * V_9 )
{
struct V_24 * V_91 ;
T_1 V_38 , V_94 ;
bool V_245 , V_246 ;
bool V_247 , V_248 ;
bool V_249 , V_250 ;
V_91 = ( void * ) V_9 -> V_36 - sizeof( * V_91 ) ;
V_38 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_94 = F_15 ( V_91 -> V_76 . V_77 . V_134 ) ;
V_245 = ! ! ( V_94 & V_251 ) ;
V_246 = ! ! ( V_94 & V_252 ) ;
V_247 = ! ! ( V_94 & V_253 ) ;
V_248 = ! ! ( V_94 & V_254 ) ;
V_249 = ! ( V_38 & V_255 ) ;
V_250 = ! ( V_38 & V_256 ) ;
if ( ! V_245 && ! V_246 )
return V_257 ;
if ( ! V_247 && ! V_248 )
return V_257 ;
if ( ! V_249 )
return V_257 ;
if ( ! V_250 )
return V_257 ;
return V_258 ;
}
static void F_114 ( struct V_1 * V_56 )
{
V_56 -> V_259 = F_113 ( V_56 ) ;
}
static void F_115 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_193 ;
struct V_1 * V_260 ;
struct V_1 * V_56 ;
struct V_24 * V_91 ;
struct V_198 * V_199 ;
enum V_107 V_215 ;
T_3 V_222 [ 64 ] ;
T_3 * V_261 ;
T_4 V_217 ;
bool V_262 ;
bool V_263 ;
bool V_264 ;
bool V_265 ;
bool V_216 ;
T_1 V_37 ;
if ( F_54 ( V_63 ) )
return;
V_193 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_193 -> V_36 - sizeof( * V_91 ) ;
V_215 = F_51 ( F_15 ( V_91 -> V_156 . V_73 ) ,
V_266 ) ;
V_199 = ( void * ) V_91 -> V_231 ;
V_217 = F_100 ( V_199 -> V_203 ) ;
memcpy ( V_222 , V_199 , V_217 ) ;
V_199 = ( void * ) V_222 ;
V_261 = F_90 ( V_199 ) ;
V_261 [ 0 ] &= ~ V_267 ;
V_260 = F_116 ( V_63 ) ;
V_91 = ( void * ) V_260 -> V_36 - sizeof( * V_91 ) ;
V_37 = F_15 ( V_91 -> V_37 . V_38 ) ;
V_262 = ! ! ( V_37 & V_268 ) ;
V_263 = ! ! ( V_37 & V_269 ) ;
V_264 = ! ! ( V_37 & V_270 ) ;
V_265 = ! ! ( V_37 & V_172 ) ;
V_216 = ( V_215 != V_108 &&
! V_262 &&
! V_263 &&
! V_265 ) ;
V_123 -> V_150 &= ~ ( V_210 |
V_211 |
V_271 |
V_272 |
V_273 ) ;
if ( V_262 )
V_123 -> V_150 |= V_210 ;
if ( V_264 )
V_123 -> V_150 |= V_211 ;
if ( V_216 )
V_123 -> V_150 |= V_271 |
V_272 |
V_273 ;
F_117 (amsdu, msdu) {
F_114 ( V_56 ) ;
F_112 ( V_3 , V_56 , V_123 , V_222 , V_215 ,
V_216 ) ;
if ( ! V_216 )
continue;
V_199 = ( void * ) V_56 -> V_36 ;
V_199 -> V_203 &= ~ F_118 ( V_274 ) ;
}
}
static void F_119 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_120 ( V_63 ) ) ) {
if ( F_54 ( V_63 ) )
V_123 -> V_150 &= ~ V_212 ;
else
V_123 -> V_150 |= V_212 ;
F_91 ( V_3 , V_123 , V_56 ) ;
}
}
static int F_121 ( struct V_62 * V_63 )
{
struct V_1 * V_9 , * V_193 ;
int V_275 ;
int V_276 = 0 ;
V_193 = F_120 ( V_63 ) ;
F_117 (amsdu, skb)
V_276 += V_9 -> V_16 ;
V_275 = V_276 - F_8 ( V_193 ) ;
if ( ( V_275 > 0 ) &&
( F_122 ( V_193 , 0 , V_275 , V_277 ) < 0 ) ) {
F_123 ( V_63 , V_193 ) ;
return - 1 ;
}
while ( ( V_9 = F_120 ( V_63 ) ) ) {
F_124 ( V_9 , F_49 ( V_193 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_123 ( V_63 , V_193 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
bool V_278 )
{
struct V_1 * V_193 ;
struct V_24 * V_91 ;
enum V_238 V_239 ;
V_193 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_193 -> V_36 - sizeof( * V_91 ) ;
V_239 = F_51 ( F_15 ( V_91 -> V_76 . V_77 . V_134 ) ,
V_240 ) ;
if ( ! V_278 )
return;
if ( V_239 != V_241 ||
F_126 ( V_63 ) != 1 + V_91 -> V_79 . V_80 ) {
F_47 ( V_63 ) ;
return;
}
F_121 ( V_63 ) ;
}
static bool F_127 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_206 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
bool V_279 ;
bool V_262 ;
V_56 = F_87 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! V_206 -> V_140 ) {
F_44 ( V_3 , L_24 ) ;
return false ;
}
V_279 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_280 ) ) ;
V_262 = ! ! ( V_91 -> V_37 . V_38 &
F_20 ( V_268 ) ) ;
if ( V_279 && ! V_262 ) {
F_67 ( V_3 , V_281 , L_25 ) ;
return false ;
}
if ( F_101 ( V_282 , & V_3 -> V_283 ) ) {
F_67 ( V_3 , V_281 , L_26 ) ;
return false ;
}
return true ;
}
static void F_128 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_206 )
{
if ( F_54 ( V_63 ) )
return;
if ( F_127 ( V_3 , V_63 , V_206 ) )
return;
F_47 ( V_63 ) ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_284 * V_285 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_206 = & V_8 -> V_206 ;
struct V_286 * V_287 ;
struct V_62 V_63 ;
int V_288 ;
int V_61 ;
T_3 * V_60 ;
int V_12 , V_26 , V_289 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
V_61 = F_58 ( V_285 -> V_290 . V_291 ) ;
V_60 = ( T_3 * ) & V_285 -> V_60 ;
V_288 = F_51 ( F_15 ( V_285 -> V_199 . V_134 ) ,
V_292 ) ;
V_287 = F_130 ( V_285 ) ;
F_45 ( V_3 , V_59 , NULL , L_27 ,
V_285 , sizeof( * V_285 ) +
( sizeof( struct V_286 ) *
V_288 ) ) ;
for ( V_12 = 0 ; V_12 < V_288 ; V_12 ++ )
V_289 += V_287 [ V_12 ] . V_289 ;
while ( V_289 -- ) {
F_131 ( & V_63 ) ;
V_26 = F_46 ( V_8 , & V_60 ,
& V_61 , & V_63 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_28 , V_26 ) ;
F_47 ( & V_63 ) ;
V_8 -> V_99 = true ;
break;
}
F_86 ( V_3 , & V_63 , V_206 , 0xffff ) ;
F_125 ( V_3 , & V_63 , V_26 > 0 ) ;
F_128 ( V_3 , & V_63 , V_206 ) ;
F_115 ( V_3 , & V_63 , V_206 ) ;
F_119 ( V_3 , & V_63 , V_206 ) ;
}
F_33 ( & V_8 -> V_49 ) ;
}
static void F_132 ( struct V_7 * V_8 ,
struct V_293 * V_294 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_206 = & V_8 -> V_206 ;
struct V_62 V_63 ;
int V_26 ;
T_3 * V_60 ;
int V_61 ;
V_61 = F_58 ( V_294 -> V_291 ) ;
V_60 = ( T_3 * ) V_294 -> V_295 ;
F_131 ( & V_63 ) ;
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
if ( F_126 ( & V_63 ) != 1 ) {
F_44 ( V_3 , L_31 ) ;
F_47 ( & V_63 ) ;
return;
}
F_86 ( V_3 , & V_63 , V_206 , 0xffff ) ;
F_128 ( V_3 , & V_63 , V_206 ) ;
F_115 ( V_3 , & V_63 , V_206 ) ;
F_119 ( V_3 , & V_63 , V_206 ) ;
if ( V_61 > 0 ) {
F_67 ( V_3 , V_281 ,
L_32 ,
V_61 ) ;
}
}
static void F_133 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_296 * V_297 = (struct V_296 * ) V_9 -> V_36 ;
struct V_298 V_299 = {} ;
int V_123 = F_51 ( V_297 -> V_300 . V_38 , V_301 ) ;
T_6 V_302 ;
int V_12 ;
switch ( V_123 ) {
case V_303 :
V_299 . V_304 = true ;
break;
case V_305 :
V_299 . V_306 = true ;
break;
case V_307 :
case V_308 :
case V_309 :
V_299 . V_310 = true ;
break;
default:
F_44 ( V_3 , L_33 , V_123 ) ;
V_299 . V_310 = true ;
break;
}
F_67 ( V_3 , V_281 , L_34 ,
V_297 -> V_300 . V_311 ) ;
for ( V_12 = 0 ; V_12 < V_297 -> V_300 . V_311 ; V_12 ++ ) {
V_302 = V_297 -> V_300 . V_312 [ V_12 ] ;
V_299 . V_302 = F_58 ( V_302 ) ;
F_134 ( V_8 , & V_299 ) ;
}
}
static void F_135 ( struct V_2 * V_3 , struct V_296 * V_297 )
{
struct V_313 * V_86 = & V_297 -> V_314 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
T_5 V_73 , V_202 , V_170 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_202 = F_51 ( V_73 , V_315 ) ;
V_170 = F_51 ( V_73 , V_316 ) ;
F_67 ( V_3 , V_281 ,
L_35 ,
V_202 , V_170 , V_86 -> V_317 ) ;
F_29 ( & V_3 -> V_171 ) ;
V_165 = F_74 ( V_3 , V_170 ) ;
if ( ! V_165 ) {
F_44 ( V_3 , L_36 ,
V_170 ) ;
F_34 ( & V_3 -> V_171 ) ;
return;
}
V_167 = F_75 ( V_3 , V_165 -> V_175 ) ;
if ( ! V_167 ) {
F_44 ( V_3 , L_37 ,
V_165 -> V_175 ) ;
F_34 ( & V_3 -> V_171 ) ;
return;
}
F_67 ( V_3 , V_281 ,
L_38 ,
V_165 -> V_318 , V_202 , V_86 -> V_317 ) ;
F_136 ( V_167 -> V_176 , V_165 -> V_318 , V_202 ) ;
F_34 ( & V_3 -> V_171 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_296 * V_297 )
{
struct V_319 * V_86 = & V_297 -> V_320 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
T_5 V_73 , V_202 , V_170 ;
V_73 = F_58 ( V_86 -> V_73 ) ;
V_202 = F_51 ( V_73 , V_315 ) ;
V_170 = F_51 ( V_73 , V_316 ) ;
F_67 ( V_3 , V_281 ,
L_39 ,
V_202 , V_170 ) ;
F_29 ( & V_3 -> V_171 ) ;
V_165 = F_74 ( V_3 , V_170 ) ;
if ( ! V_165 ) {
F_44 ( V_3 , L_36 ,
V_170 ) ;
F_34 ( & V_3 -> V_171 ) ;
return;
}
V_167 = F_75 ( V_3 , V_165 -> V_175 ) ;
if ( ! V_167 ) {
F_44 ( V_3 , L_37 ,
V_165 -> V_175 ) ;
F_34 ( & V_3 -> V_171 ) ;
return;
}
F_67 ( V_3 , V_281 ,
L_40 ,
V_165 -> V_318 , V_202 ) ;
F_138 ( V_167 -> V_176 , V_165 -> V_318 , V_202 ) ;
F_34 ( & V_3 -> V_171 ) ;
}
static int F_139 ( struct V_62 * V_87 ,
struct V_62 * V_63 )
{
struct V_1 * V_56 ;
struct V_24 * V_91 ;
if ( F_54 ( V_87 ) )
return - V_321 ;
if ( F_76 ( ! F_54 ( V_63 ) ) )
return - V_100 ;
while ( ( V_56 = F_120 ( V_87 ) ) ) {
F_48 ( V_63 , V_56 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) )
break;
}
V_56 = F_116 ( V_63 ) ;
V_91 = ( void * ) V_56 -> V_36 - sizeof( * V_91 ) ;
if ( ! ( V_91 -> V_82 . V_77 . V_73 &
F_20 ( V_83 ) ) ) {
F_140 ( V_63 , V_87 ) ;
return - V_322 ;
}
return 0 ;
}
static void F_141 ( struct V_122 * V_123 ,
struct V_1 * V_9 )
{
struct V_198 * V_199 = (struct V_198 * ) V_9 -> V_36 ;
if ( ! F_142 ( V_199 -> V_203 ) )
return;
V_199 -> V_203 &= ~ F_118 ( V_274 ) ;
V_123 -> V_150 |= V_271 |
V_272 |
V_273 ;
}
static void F_143 ( struct V_2 * V_3 ,
struct V_62 * V_87 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_122 * V_123 = & V_8 -> V_206 ;
struct V_323 * V_285 ;
struct V_1 * V_56 ;
T_4 V_324 ;
while ( ( V_56 = F_120 ( V_87 ) ) ) {
V_285 = ( void * ) V_56 -> V_36 ;
F_49 ( V_56 , sizeof( * V_285 ) ) ;
F_18 ( V_56 , sizeof( * V_285 ) ) ;
if ( F_8 ( V_56 ) < F_58 ( V_285 -> V_64 ) ) {
F_44 ( V_3 , L_41 ) ;
F_10 ( V_56 ) ;
continue;
}
F_49 ( V_56 , F_58 ( V_285 -> V_64 ) ) ;
V_324 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_49 ( V_56 , V_324 ) ;
memmove ( V_56 -> V_36 + V_324 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_324 ) ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_150 |= V_188 ;
F_141 ( V_123 , V_56 ) ;
F_83 ( V_3 , V_123 , NULL , V_285 -> V_175 ) ;
F_91 ( V_3 , V_123 , V_56 ) ;
}
}
static void F_144 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_296 * V_297 = ( void * ) V_9 -> V_36 ;
struct V_122 * V_123 = & V_8 -> V_206 ;
struct V_62 V_87 ;
struct V_62 V_63 ;
T_5 V_170 ;
T_5 V_92 ;
T_3 V_175 ;
T_3 V_202 ;
bool V_325 ;
bool V_294 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_99 )
return;
F_18 ( V_9 , sizeof( V_297 -> V_199 ) ) ;
F_18 ( V_9 , sizeof( V_297 -> V_326 ) ) ;
V_170 = F_58 ( V_297 -> V_326 . V_170 ) ;
V_92 = F_58 ( V_297 -> V_326 . V_92 ) ;
V_175 = V_297 -> V_326 . V_175 ;
V_202 = F_145 ( V_297 -> V_326 . V_94 , V_327 ) ;
V_325 = ! ! ( V_297 -> V_326 . V_94 &
V_95 ) ;
V_294 = ! ! ( V_297 -> V_326 . V_94 & V_328 ) ;
F_67 ( V_3 , V_281 ,
L_42 ,
V_175 , V_170 , V_202 , V_325 , V_294 , V_92 ) ;
if ( V_9 -> V_16 < V_92 * sizeof( * V_297 -> V_326 . V_90 ) ) {
F_44 ( V_3 , L_43 ) ;
return;
}
F_131 ( & V_87 ) ;
V_26 = F_57 ( V_8 , & V_297 -> V_326 , & V_87 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_44 , V_26 ) ;
V_8 -> V_99 = true ;
return;
}
if ( V_325 )
F_143 ( V_3 , & V_87 ) ;
while ( ! F_54 ( & V_87 ) ) {
F_131 ( & V_63 ) ;
V_26 = F_139 ( & V_87 , & V_63 ) ;
switch ( V_26 ) {
case 0 :
F_86 ( V_3 , & V_63 , V_123 , V_175 ) ;
F_128 ( V_3 , & V_63 , V_123 ) ;
F_115 ( V_3 , & V_63 , V_123 ) ;
F_119 ( V_3 , & V_63 , V_123 ) ;
break;
case - V_322 :
default:
F_44 ( V_3 , L_45 , V_26 ) ;
V_8 -> V_99 = true ;
F_47 ( & V_87 ) ;
return;
}
}
F_33 ( & V_8 -> V_49 ) ;
}
void F_146 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_296 * V_297 = (struct V_296 * ) V_9 -> V_36 ;
enum V_329 type ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_44 ( V_3 , L_46 ) ;
F_67 ( V_3 , V_281 , L_47 ,
V_297 -> V_199 . V_330 ) ;
if ( V_297 -> V_199 . V_330 >= V_3 -> V_8 . V_331 ) {
F_67 ( V_3 , V_281 , L_48 ,
V_297 -> V_199 . V_330 , V_3 -> V_8 . V_331 ) ;
F_10 ( V_9 ) ;
return;
}
type = V_3 -> V_8 . V_332 [ V_297 -> V_199 . V_330 ] ;
switch ( type ) {
case V_333 : {
V_8 -> V_334 = V_297 -> V_335 . V_336 ;
V_8 -> V_337 = V_297 -> V_335 . V_338 ;
F_147 ( & V_8 -> V_339 ) ;
break;
}
case V_340 :
F_148 ( & V_8 -> V_53 , V_9 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_341 : {
struct V_342 V_86 = {
. V_175 = V_297 -> V_343 . V_175 ,
. V_170 = F_58 ( V_297 -> V_343 . V_170 ) ,
} ;
memcpy ( V_86 . V_318 , V_297 -> V_343 . V_318 , sizeof( V_86 . V_318 ) ) ;
F_149 ( V_8 , & V_86 ) ;
break;
}
case V_344 : {
struct V_345 V_86 = {
. V_170 = F_58 ( V_297 -> V_346 . V_170 ) ,
} ;
F_150 ( V_8 , & V_86 ) ;
break;
}
case V_347 : {
struct V_298 V_299 = {} ;
int V_123 = F_15 ( V_297 -> V_348 . V_123 ) ;
V_299 . V_302 =
F_15 ( V_297 -> V_348 . V_349 ) ;
switch ( V_123 ) {
case V_350 :
V_299 . V_306 = true ;
break;
case V_351 :
V_299 . V_304 = true ;
break;
case V_352 :
V_299 . V_310 = true ;
break;
}
F_134 ( V_8 , & V_299 ) ;
break;
}
case V_353 :
F_148 ( & V_8 -> V_52 , V_9 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_354 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_355 * V_86 = & V_297 -> V_356 ;
F_67 ( V_3 , V_281 ,
L_49 ,
F_58 ( V_86 -> V_170 ) ,
! ! ( V_86 -> V_38 & V_357 ) ,
F_51 ( V_86 -> V_38 , V_358 ) ) ;
F_147 ( & V_3 -> V_359 ) ;
break;
}
case V_360 : {
F_45 ( V_3 , V_59 , NULL , L_50 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_132 ( V_8 , & V_297 -> V_361 ) ;
break;
}
case V_362 :
break;
case V_363 :
F_151 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_364 :
F_44 ( V_3 , L_51 ) ;
break;
case V_365 :
F_135 ( V_3 , V_297 ) ;
break;
case V_366 :
F_137 ( V_3 , V_297 ) ;
break;
case V_367 : {
struct V_368 * V_199 =
(struct V_368 * ) V_297 -> V_369 . V_370 ;
F_152 ( V_3 , V_297 -> V_369 . V_370 ,
sizeof( * V_199 ) +
F_58 ( V_199 -> V_19 ) ) ;
break;
}
case V_371 : {
break;
}
case V_372 : {
F_148 ( & V_8 -> V_54 , V_9 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
}
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
case V_377 :
case V_378 :
break;
case V_379 :
default:
F_44 ( V_3 , L_52 ,
V_297 -> V_199 . V_330 ) ;
F_45 ( V_3 , V_59 , NULL , L_50 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
F_10 ( V_9 ) ;
}
void F_153 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
F_152 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
static void V_105 ( unsigned long V_84 )
{
struct V_7 * V_8 = (struct V_7 * ) V_84 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_62 V_380 ;
struct V_62 V_381 ;
struct V_62 V_382 ;
struct V_296 * V_297 ;
struct V_1 * V_9 ;
unsigned long V_38 ;
F_131 ( & V_380 ) ;
F_131 ( & V_381 ) ;
F_131 ( & V_382 ) ;
F_154 ( & V_8 -> V_52 . V_41 , V_38 ) ;
F_140 ( & V_8 -> V_52 , & V_380 ) ;
F_155 ( & V_8 -> V_52 . V_41 , V_38 ) ;
F_154 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_140 ( & V_8 -> V_53 , & V_381 ) ;
F_155 ( & V_8 -> V_53 . V_41 , V_38 ) ;
F_154 ( & V_8 -> V_54 . V_41 , V_38 ) ;
F_140 ( & V_8 -> V_54 , & V_382 ) ;
F_155 ( & V_8 -> V_54 . V_41 , V_38 ) ;
while ( ( V_9 = F_120 ( & V_380 ) ) ) {
F_133 ( V_8 -> V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_120 ( & V_381 ) ) ) {
V_297 = (struct V_296 * ) V_9 -> V_36 ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_129 ( V_8 , & V_297 -> V_383 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_120 ( & V_382 ) ) ) {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_144 ( V_3 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_10 ( V_9 ) ;
}
}
