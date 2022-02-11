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
enum V_124 V_125 ;
T_3 V_126 , V_127 , V_128 , V_129 , V_130 , V_131 , V_132 ;
T_3 V_133 = 0 ;
T_1 V_134 , V_135 , V_136 ;
if ( ! V_123 -> V_137 )
return;
V_125 = V_123 -> V_125 ;
V_134 = F_15 ( V_90 -> V_138 . V_134 ) ;
V_135 = F_15 ( V_90 -> V_138 . V_135 ) ;
V_136 = F_15 ( V_90 -> V_138 . V_136 ) ;
V_133 = F_51 ( V_134 , V_139 ) ;
switch ( V_133 ) {
case V_140 :
V_126 = V_134 & V_141 ;
V_127 = F_51 ( V_134 , V_142 ) ;
V_128 = 0 ;
if ( V_127 < 0x08 || V_127 > 0x0F )
break;
switch ( V_125 ) {
case V_143 :
if ( V_126 )
V_127 &= ~ F_71 ( 3 ) ;
V_128 = V_144 [ V_127 ] ;
break;
case V_145 :
V_128 = V_144 [ V_127 ] ;
V_128 -= 4 ;
break;
default:
break;
}
V_123 -> V_128 = V_128 ;
break;
case V_146 :
case V_147 :
V_131 = V_135 & 0x1F ;
V_132 = V_131 >> 3 ;
V_129 = ( V_135 >> 7 ) & 1 ;
V_130 = ( V_136 >> 7 ) & 1 ;
V_123 -> V_128 = V_131 ;
V_123 -> V_148 |= V_149 ;
if ( V_130 )
V_123 -> V_148 |= V_150 ;
if ( V_129 )
V_123 -> V_148 |= V_151 ;
break;
case V_152 :
case V_153 :
V_131 = ( V_136 >> 4 ) & 0x0F ;
V_132 = ( ( V_135 >> 10 ) & 0x07 ) + 1 ;
V_129 = V_135 & 3 ;
V_130 = V_136 & 1 ;
V_123 -> V_128 = V_131 ;
V_123 -> V_154 = V_132 ;
if ( V_130 )
V_123 -> V_148 |= V_150 ;
switch ( V_129 ) {
case 0 :
break;
case 1 :
V_123 -> V_148 |= V_151 ;
break;
case 2 :
V_123 -> V_155 |= V_156 ;
}
V_123 -> V_148 |= V_157 ;
break;
default:
break;
}
}
static bool F_72 ( struct V_2 * V_3 ,
struct V_122 * V_123 )
{
struct V_158 * V_159 ;
F_29 ( & V_3 -> V_160 ) ;
V_159 = V_3 -> V_161 ;
if ( ! V_159 )
V_159 = V_3 -> V_162 ;
F_34 ( & V_3 -> V_160 ) ;
if ( ! V_159 )
return false ;
V_123 -> V_125 = V_159 -> V_125 ;
V_123 -> V_137 = V_159 -> V_163 ;
return true ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 )
{
V_123 -> signal = V_164 +
V_90 -> V_138 . V_165 ;
V_123 -> V_148 &= ~ V_166 ;
}
static void F_74 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_24 * V_90 )
{
V_123 -> V_167 = F_15 ( V_90 -> V_168 . V_169 . V_170 ) ;
V_123 -> V_148 |= V_171 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_172 ;
struct V_24 * V_90 ;
bool V_173 ;
bool V_174 ;
if ( F_54 ( V_63 ) )
return;
V_172 = F_76 ( V_63 ) ;
V_90 = ( void * ) V_172 -> V_36 - sizeof( * V_90 ) ;
V_173 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_175 ) ) ;
V_174 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_176 ) ) ;
if ( V_173 ) {
V_123 -> V_137 = 0 ;
V_123 -> V_128 = 0 ;
V_123 -> V_154 = 0 ;
V_123 -> V_155 &= ~ V_156 ;
V_123 -> V_148 &= ~ ( V_149 |
V_157 |
V_150 |
V_151 |
V_171 ) ;
V_123 -> V_148 |= V_166 ;
F_73 ( V_3 , V_123 , V_90 ) ;
F_72 ( V_3 , V_123 ) ;
F_70 ( V_3 , V_123 , V_90 ) ;
}
if ( V_174 )
F_74 ( V_3 , V_123 , V_90 ) ;
}
static char * F_77 ( struct V_177 * V_178 , char * V_179 , T_4 V_19 )
{
T_3 * V_180 ;
int V_181 ;
if ( ! F_78 ( V_178 -> V_182 ) )
return L_7 ;
V_180 = F_79 ( V_178 ) ;
V_181 = * V_180 & V_183 ;
if ( V_181 < 8 )
snprintf ( V_179 , V_19 , L_8 , V_181 , V_184 [ V_181 ] ) ;
else
snprintf ( V_179 , V_19 , L_9 , V_181 ) ;
return V_179 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_122 * V_185 ,
struct V_1 * V_9 )
{
struct V_122 * V_123 ;
struct V_177 * V_178 = (struct V_177 * ) V_9 -> V_36 ;
char V_181 [ 32 ] ;
V_123 = F_81 ( V_9 ) ;
* V_123 = * V_185 ;
F_67 ( V_3 , V_186 ,
L_10 ,
V_9 ,
V_9 -> V_16 ,
F_82 ( V_178 ) ,
F_77 ( V_178 , V_181 , sizeof( V_181 ) ) ,
F_83 ( F_84 ( V_178 ) ) ?
L_11 : L_12 ,
( F_58 ( V_178 -> V_187 ) & V_188 ) >> 4 ,
V_123 -> V_148 == 0 ? L_13 : L_7 ,
V_123 -> V_148 & V_149 ? L_14 : L_7 ,
V_123 -> V_148 & V_157 ? L_15 : L_7 ,
V_123 -> V_148 & V_151 ? L_16 : L_7 ,
V_123 -> V_155 & V_156 ? L_17 : L_7 ,
V_123 -> V_148 & V_150 ? L_18 : L_7 ,
V_123 -> V_128 ,
V_123 -> V_154 ,
V_123 -> V_137 ,
V_123 -> V_125 , V_123 -> V_148 ,
! ! ( V_123 -> V_148 & V_189 ) ,
! ! ( V_123 -> V_148 & V_190 ) ,
! ! ( V_123 -> V_148 & V_191 ) ) ;
F_45 ( V_3 , V_59 , NULL , L_19 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_85 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_86 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
F_87 ( V_3 -> V_192 , V_9 ) ;
}
static int F_88 ( struct V_177 * V_178 )
{
return F_89 ( F_90 ( V_178 -> V_182 ) , 4 ) ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
enum V_107 V_193 ,
bool V_194 )
{
struct V_177 * V_178 ;
struct V_24 * V_90 ;
T_4 V_195 ;
T_4 V_196 ;
bool V_197 ;
bool V_198 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_197 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_199 ) ) ;
V_198 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ;
if ( F_22 ( F_4 ( ! V_197 ) ) )
return;
if ( F_22 ( F_4 ( ! ( V_197 && V_198 ) ) ) )
return;
F_52 ( V_56 , V_56 -> V_16 - V_200 ) ;
if ( ! V_194 )
return;
V_178 = ( void * ) V_56 -> V_36 ;
F_52 ( V_56 , V_56 -> V_16 - F_69 ( V_3 , V_193 ) ) ;
if ( ! F_92 ( V_178 -> V_182 ) &&
V_193 == V_113 )
F_52 ( V_56 , V_56 -> V_16 - 8 ) ;
V_195 = F_90 ( V_178 -> V_182 ) ;
V_196 = F_68 ( V_3 , V_193 ) ;
memmove ( ( void * ) V_56 -> V_36 + V_196 ,
( void * ) V_56 -> V_36 , V_195 ) ;
F_18 ( V_56 , V_196 ) ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_201 [ 64 ] )
{
struct V_177 * V_178 ;
T_4 V_195 ;
T_3 V_202 [ V_203 ] ;
T_3 V_204 [ V_203 ] ;
V_178 = (struct V_177 * ) V_56 -> V_36 ;
V_195 = F_88 ( V_178 ) ;
F_94 ( V_202 , F_84 ( V_178 ) ) ;
F_94 ( V_204 , F_82 ( V_178 ) ) ;
F_18 ( V_56 , V_195 ) ;
V_178 = (struct V_177 * ) V_201 ;
V_195 = F_90 ( V_178 -> V_182 ) ;
memcpy ( F_95 ( V_56 , V_195 ) , V_178 , V_195 ) ;
V_178 = (struct V_177 * ) V_56 -> V_36 ;
F_94 ( F_84 ( V_178 ) , V_202 ) ;
F_94 ( F_82 ( V_178 ) , V_204 ) ;
}
static void * F_96 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
enum V_107 V_193 )
{
struct V_177 * V_178 ;
struct V_24 * V_90 ;
T_4 V_195 , V_196 ;
void * V_205 ;
bool V_197 , V_198 , V_206 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_178 = ( void * ) V_90 -> V_207 ;
V_197 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_199 ) ) ;
V_198 = ! ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ;
V_206 = ! ( V_197 && V_198 ) ;
V_205 = V_178 ;
if ( V_197 ) {
V_195 = F_90 ( V_178 -> V_182 ) ;
V_196 = F_68 ( V_3 , V_193 ) ;
V_205 += F_89 ( V_195 , 4 ) +
F_89 ( V_196 , 4 ) ;
}
if ( V_206 )
V_205 += sizeof( struct V_208 ) ;
return V_205 ;
}
static void F_97 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_201 [ 64 ] ,
enum V_107 V_193 )
{
struct V_177 * V_178 ;
struct V_209 * V_210 ;
T_4 V_195 ;
void * V_205 ;
T_3 V_202 [ V_203 ] ;
T_3 V_204 [ V_203 ] ;
V_205 = F_96 ( V_3 , V_56 , V_193 ) ;
if ( F_4 ( ! V_205 ) )
return;
V_210 = (struct V_209 * ) V_56 -> V_36 ;
F_94 ( V_202 , V_210 -> V_211 ) ;
F_94 ( V_204 , V_210 -> V_212 ) ;
F_18 ( V_56 , sizeof( struct V_209 ) ) ;
memcpy ( F_95 ( V_56 , sizeof( struct V_213 ) ) , V_205 ,
sizeof( struct V_213 ) ) ;
V_178 = (struct V_177 * ) V_201 ;
V_195 = F_90 ( V_178 -> V_182 ) ;
memcpy ( F_95 ( V_56 , V_195 ) , V_178 , V_195 ) ;
V_178 = (struct V_177 * ) V_56 -> V_36 ;
F_94 ( F_84 ( V_178 ) , V_202 ) ;
F_94 ( F_82 ( V_178 ) , V_204 ) ;
}
static void F_98 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
const T_3 V_201 [ 64 ] )
{
struct V_177 * V_178 ;
T_4 V_195 ;
F_18 ( V_56 , sizeof( struct V_208 ) ) ;
V_178 = (struct V_177 * ) V_201 ;
V_195 = F_90 ( V_178 -> V_182 ) ;
memcpy ( F_95 ( V_56 , V_195 ) , V_178 , V_195 ) ;
}
static void F_99 ( struct V_2 * V_3 ,
struct V_1 * V_56 ,
struct V_122 * V_123 ,
T_3 V_201 [ 64 ] ,
enum V_107 V_193 ,
bool V_194 )
{
struct V_24 * V_90 ;
enum V_214 V_215 ;
struct V_177 * V_178 ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
V_178 = ( void * ) V_90 -> V_207 ;
V_215 = F_51 ( F_15 ( V_90 -> V_76 . V_134 ) ,
V_216 ) ;
switch ( V_215 ) {
case V_217 :
F_91 ( V_3 , V_56 , V_123 , V_193 ,
V_194 ) ;
break;
case V_218 :
F_93 ( V_3 , V_56 , V_123 , V_201 ) ;
break;
case V_219 :
F_97 ( V_3 , V_56 , V_123 , V_201 , V_193 ) ;
break;
case V_220 :
F_98 ( V_3 , V_56 , V_123 , V_201 ) ;
break;
}
}
static int F_100 ( struct V_1 * V_9 )
{
struct V_24 * V_90 ;
T_1 V_38 , V_93 ;
bool V_221 , V_222 ;
bool V_223 , V_224 ;
bool V_225 , V_226 ;
V_90 = ( void * ) V_9 -> V_36 - sizeof( * V_90 ) ;
V_38 = F_15 ( V_90 -> V_37 . V_38 ) ;
V_93 = F_15 ( V_90 -> V_76 . V_134 ) ;
V_221 = ! ! ( V_93 & V_227 ) ;
V_222 = ! ! ( V_93 & V_228 ) ;
V_223 = ! ! ( V_93 & V_229 ) ;
V_224 = ! ! ( V_93 & V_230 ) ;
V_225 = ! ( V_38 & V_231 ) ;
V_226 = ! ( V_38 & V_232 ) ;
if ( ! V_221 && ! V_222 )
return V_233 ;
if ( ! V_223 && ! V_224 )
return V_233 ;
if ( ! V_225 )
return V_233 ;
if ( ! V_226 )
return V_233 ;
return V_234 ;
}
static void F_101 ( struct V_1 * V_56 )
{
V_56 -> V_235 = F_100 ( V_56 ) ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_172 ;
struct V_1 * V_236 ;
struct V_1 * V_56 ;
struct V_24 * V_90 ;
struct V_177 * V_178 ;
enum V_107 V_193 ;
T_3 V_201 [ 64 ] ;
T_3 * V_237 ;
T_4 V_195 ;
bool V_238 ;
bool V_239 ;
bool V_240 ;
bool V_241 ;
bool V_194 ;
T_1 V_37 ;
if ( F_54 ( V_63 ) )
return;
V_172 = F_76 ( V_63 ) ;
V_90 = ( void * ) V_172 -> V_36 - sizeof( * V_90 ) ;
V_193 = F_51 ( F_15 ( V_90 -> V_242 . V_73 ) ,
V_243 ) ;
V_178 = ( void * ) V_90 -> V_207 ;
V_195 = F_90 ( V_178 -> V_182 ) ;
memcpy ( V_201 , V_178 , V_195 ) ;
V_178 = ( void * ) V_201 ;
V_237 = F_79 ( V_178 ) ;
V_237 [ 0 ] &= ~ V_244 ;
V_236 = F_103 ( V_63 ) ;
V_90 = ( void * ) V_236 -> V_36 - sizeof( * V_90 ) ;
V_37 = F_15 ( V_90 -> V_37 . V_38 ) ;
V_238 = ! ! ( V_37 & V_245 ) ;
V_239 = ! ! ( V_37 & V_246 ) ;
V_240 = ! ! ( V_37 & V_247 ) ;
V_241 = ! ! ( V_37 & V_248 ) ;
V_194 = ( V_193 != V_108 &&
! V_238 &&
! V_239 &&
! V_241 ) ;
V_123 -> V_148 &= ~ ( V_189 |
V_190 |
V_249 |
V_250 |
V_251 ) ;
if ( V_238 )
V_123 -> V_148 |= V_189 ;
if ( V_240 )
V_123 -> V_148 |= V_190 ;
if ( V_194 )
V_123 -> V_148 |= V_249 |
V_250 |
V_251 ;
F_104 (amsdu, msdu) {
F_101 ( V_56 ) ;
F_99 ( V_3 , V_56 , V_123 , V_201 , V_193 ,
V_194 ) ;
if ( ! V_194 )
continue;
V_178 = ( void * ) V_56 -> V_36 ;
V_178 -> V_182 &= ~ F_105 ( V_252 ) ;
}
}
static void F_106 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_123 )
{
struct V_1 * V_56 ;
while ( ( V_56 = F_107 ( V_63 ) ) ) {
if ( F_54 ( V_63 ) )
V_123 -> V_148 &= ~ V_191 ;
else
V_123 -> V_148 |= V_191 ;
F_80 ( V_3 , V_123 , V_56 ) ;
}
}
static int F_108 ( struct V_62 * V_63 )
{
struct V_1 * V_9 , * V_172 ;
int V_253 ;
int V_254 = 0 ;
V_172 = F_107 ( V_63 ) ;
F_104 (amsdu, skb)
V_254 += V_9 -> V_16 ;
V_253 = V_254 - F_8 ( V_172 ) ;
if ( ( V_253 > 0 ) &&
( F_109 ( V_172 , 0 , V_253 , V_255 ) < 0 ) ) {
F_110 ( V_63 , V_172 ) ;
return - 1 ;
}
while ( ( V_9 = F_107 ( V_63 ) ) ) {
F_111 ( V_9 , F_49 ( V_172 , V_9 -> V_16 ) ,
V_9 -> V_16 ) ;
F_10 ( V_9 ) ;
}
F_110 ( V_63 , V_172 ) ;
return 0 ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
bool V_256 )
{
struct V_1 * V_172 ;
struct V_24 * V_90 ;
enum V_214 V_215 ;
V_172 = F_76 ( V_63 ) ;
V_90 = ( void * ) V_172 -> V_36 - sizeof( * V_90 ) ;
V_215 = F_51 ( F_15 ( V_90 -> V_76 . V_134 ) ,
V_216 ) ;
if ( ! V_256 )
return;
if ( V_215 != V_217 ||
F_113 ( V_63 ) != 1 + V_90 -> V_78 . V_79 ) {
F_47 ( V_63 ) ;
return;
}
F_108 ( V_63 ) ;
}
static bool F_114 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_185 )
{
struct V_1 * V_56 ;
struct V_24 * V_90 ;
bool V_257 ;
bool V_238 ;
V_56 = F_76 ( V_63 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( ! V_185 -> V_137 ) {
F_44 ( V_3 , L_20 ) ;
return false ;
}
V_257 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_258 ) ) ;
V_238 = ! ! ( V_90 -> V_37 . V_38 &
F_20 ( V_245 ) ) ;
if ( V_257 && ! V_238 ) {
F_67 ( V_3 , V_259 , L_21 ) ;
return false ;
}
if ( F_115 ( V_260 , & V_3 -> V_261 ) ) {
F_67 ( V_3 , V_259 , L_22 ) ;
return false ;
}
return true ;
}
static void F_116 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
struct V_122 * V_185 )
{
if ( F_54 ( V_63 ) )
return;
if ( F_114 ( V_3 , V_63 , V_185 ) )
return;
F_47 ( V_63 ) ;
}
static void F_117 ( struct V_7 * V_8 ,
struct V_262 * V_263 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_185 = & V_8 -> V_185 ;
struct V_264 * V_265 ;
struct V_62 V_63 ;
int V_266 ;
int V_61 ;
T_3 * V_60 ;
int V_12 , V_26 , V_267 = 0 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_98 )
return;
V_61 = F_58 ( V_263 -> V_268 . V_269 ) ;
V_60 = ( T_3 * ) & V_263 -> V_60 ;
V_266 = F_51 ( F_15 ( V_263 -> V_178 . V_134 ) ,
V_270 ) ;
V_265 = F_118 ( V_263 ) ;
F_45 ( V_3 , V_59 , NULL , L_23 ,
V_263 , sizeof( * V_263 ) +
( sizeof( struct V_264 ) *
V_266 ) ) ;
for ( V_12 = 0 ; V_12 < V_266 ; V_12 ++ )
V_267 += V_265 [ V_12 ] . V_267 ;
while ( V_267 -- ) {
F_119 ( & V_63 ) ;
V_26 = F_46 ( V_8 , & V_60 ,
& V_61 , & V_63 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_24 , V_26 ) ;
F_47 ( & V_63 ) ;
V_8 -> V_98 = true ;
break;
}
F_75 ( V_3 , & V_63 , V_185 ) ;
F_112 ( V_3 , & V_63 , V_26 > 0 ) ;
F_116 ( V_3 , & V_63 , V_185 ) ;
F_102 ( V_3 , & V_63 , V_185 ) ;
F_106 ( V_3 , & V_63 , V_185 ) ;
}
F_33 ( & V_8 -> V_49 ) ;
}
static void F_120 ( struct V_7 * V_8 ,
struct V_271 * V_272 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_122 * V_185 = & V_8 -> V_185 ;
struct V_62 V_63 ;
int V_26 ;
T_3 * V_60 ;
int V_61 ;
V_61 = F_58 ( V_272 -> V_269 ) ;
V_60 = ( T_3 * ) V_272 -> V_273 ;
F_119 ( & V_63 ) ;
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
if ( F_113 ( & V_63 ) != 1 ) {
F_44 ( V_3 , L_27 ) ;
F_47 ( & V_63 ) ;
return;
}
F_75 ( V_3 , & V_63 , V_185 ) ;
F_116 ( V_3 , & V_63 , V_185 ) ;
F_102 ( V_3 , & V_63 , V_185 ) ;
F_106 ( V_3 , & V_63 , V_185 ) ;
if ( V_61 > 0 ) {
F_67 ( V_3 , V_259 ,
L_28 ,
V_61 ) ;
}
}
static void F_121 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_274 * V_275 = (struct V_274 * ) V_9 -> V_36 ;
struct V_276 V_277 = {} ;
int V_123 = F_51 ( V_275 -> V_278 . V_38 , V_279 ) ;
T_5 V_280 ;
int V_12 ;
F_27 ( & V_8 -> V_281 ) ;
switch ( V_123 ) {
case V_282 :
V_277 . V_283 = true ;
break;
case V_284 :
break;
case V_285 :
case V_286 :
case V_287 :
V_277 . V_288 = true ;
break;
default:
F_44 ( V_3 , L_29 , V_123 ) ;
V_277 . V_288 = true ;
break;
}
F_67 ( V_3 , V_259 , L_30 ,
V_275 -> V_278 . V_289 ) ;
for ( V_12 = 0 ; V_12 < V_275 -> V_278 . V_289 ; V_12 ++ ) {
V_280 = V_275 -> V_278 . V_290 [ V_12 ] ;
V_277 . V_280 = F_58 ( V_280 ) ;
F_122 ( V_8 , & V_277 ) ;
}
}
static void F_123 ( struct V_2 * V_3 , struct V_274 * V_275 )
{
struct V_291 * V_85 = & V_275 -> V_292 ;
struct V_293 * V_294 ;
struct V_295 * V_296 ;
T_6 V_73 , V_181 , V_297 ;
V_73 = F_58 ( V_85 -> V_73 ) ;
V_181 = F_51 ( V_73 , V_298 ) ;
V_297 = F_51 ( V_73 , V_299 ) ;
F_67 ( V_3 , V_259 ,
L_31 ,
V_181 , V_297 , V_85 -> V_300 ) ;
F_29 ( & V_3 -> V_160 ) ;
V_294 = F_124 ( V_3 , V_297 ) ;
if ( ! V_294 ) {
F_44 ( V_3 , L_32 ,
V_297 ) ;
F_34 ( & V_3 -> V_160 ) ;
return;
}
V_296 = F_125 ( V_3 , V_294 -> V_301 ) ;
if ( ! V_296 ) {
F_44 ( V_3 , L_33 ,
V_294 -> V_301 ) ;
F_34 ( & V_3 -> V_160 ) ;
return;
}
F_67 ( V_3 , V_259 ,
L_34 ,
V_294 -> V_302 , V_181 , V_85 -> V_300 ) ;
F_126 ( V_296 -> V_303 , V_294 -> V_302 , V_181 ) ;
F_34 ( & V_3 -> V_160 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_274 * V_275 )
{
struct V_304 * V_85 = & V_275 -> V_305 ;
struct V_293 * V_294 ;
struct V_295 * V_296 ;
T_6 V_73 , V_181 , V_297 ;
V_73 = F_58 ( V_85 -> V_73 ) ;
V_181 = F_51 ( V_73 , V_298 ) ;
V_297 = F_51 ( V_73 , V_299 ) ;
F_67 ( V_3 , V_259 ,
L_35 ,
V_181 , V_297 ) ;
F_29 ( & V_3 -> V_160 ) ;
V_294 = F_124 ( V_3 , V_297 ) ;
if ( ! V_294 ) {
F_44 ( V_3 , L_32 ,
V_297 ) ;
F_34 ( & V_3 -> V_160 ) ;
return;
}
V_296 = F_125 ( V_3 , V_294 -> V_301 ) ;
if ( ! V_296 ) {
F_44 ( V_3 , L_33 ,
V_294 -> V_301 ) ;
F_34 ( & V_3 -> V_160 ) ;
return;
}
F_67 ( V_3 , V_259 ,
L_36 ,
V_294 -> V_302 , V_181 ) ;
F_128 ( V_296 -> V_303 , V_294 -> V_302 , V_181 ) ;
F_34 ( & V_3 -> V_160 ) ;
}
static int F_129 ( struct V_62 * V_86 ,
struct V_62 * V_63 )
{
struct V_1 * V_56 ;
struct V_24 * V_90 ;
if ( F_54 ( V_86 ) )
return - V_306 ;
if ( F_130 ( ! F_54 ( V_63 ) ) )
return - V_99 ;
while ( ( V_56 = F_107 ( V_86 ) ) ) {
F_48 ( V_63 , V_56 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) )
break;
}
V_56 = F_103 ( V_63 ) ;
V_90 = ( void * ) V_56 -> V_36 - sizeof( * V_90 ) ;
if ( ! ( V_90 -> V_81 . V_73 &
F_20 ( V_82 ) ) ) {
F_131 ( V_63 , V_86 ) ;
return - V_307 ;
}
return 0 ;
}
static void F_132 ( struct V_122 * V_123 ,
struct V_1 * V_9 )
{
struct V_177 * V_178 = (struct V_177 * ) V_9 -> V_36 ;
if ( ! F_133 ( V_178 -> V_182 ) )
return;
V_178 -> V_182 &= ~ F_105 ( V_252 ) ;
V_123 -> V_148 |= V_249 |
V_250 |
V_251 ;
}
static void F_134 ( struct V_2 * V_3 ,
struct V_62 * V_86 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_122 * V_123 = & V_8 -> V_185 ;
struct V_308 * V_263 ;
struct V_1 * V_56 ;
T_4 V_309 ;
while ( ( V_56 = F_107 ( V_86 ) ) ) {
V_263 = ( void * ) V_56 -> V_36 ;
F_49 ( V_56 , sizeof( * V_263 ) ) ;
F_18 ( V_56 , sizeof( * V_263 ) ) ;
if ( F_8 ( V_56 ) < F_58 ( V_263 -> V_64 ) ) {
F_44 ( V_3 , L_37 ) ;
F_10 ( V_56 ) ;
continue;
}
F_49 ( V_56 , F_58 ( V_263 -> V_64 ) ) ;
V_309 = 4 - ( ( unsigned long ) V_56 -> V_36 & 3 ) ;
F_49 ( V_56 , V_309 ) ;
memmove ( V_56 -> V_36 + V_309 , V_56 -> V_36 , V_56 -> V_16 ) ;
F_18 ( V_56 , V_309 ) ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_148 |= V_166 ;
F_132 ( V_123 , V_56 ) ;
F_72 ( V_3 , V_123 ) ;
F_80 ( V_3 , V_123 , V_56 ) ;
}
}
static void F_135 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_274 * V_275 = ( void * ) V_9 -> V_36 ;
struct V_122 * V_123 = & V_8 -> V_185 ;
struct V_62 V_86 ;
struct V_62 V_63 ;
T_6 V_297 ;
T_6 V_91 ;
T_3 V_301 ;
T_3 V_181 ;
bool V_310 ;
bool V_272 ;
int V_26 ;
F_27 ( & V_8 -> V_13 . V_41 ) ;
if ( V_8 -> V_98 )
return;
F_18 ( V_9 , sizeof( V_275 -> V_178 ) ) ;
F_18 ( V_9 , sizeof( V_275 -> V_311 ) ) ;
V_297 = F_58 ( V_275 -> V_311 . V_297 ) ;
V_91 = F_58 ( V_275 -> V_311 . V_91 ) ;
V_301 = V_275 -> V_311 . V_301 ;
V_181 = F_136 ( V_275 -> V_311 . V_93 , V_312 ) ;
V_310 = ! ! ( V_275 -> V_311 . V_93 &
V_94 ) ;
V_272 = ! ! ( V_275 -> V_311 . V_93 & V_313 ) ;
F_67 ( V_3 , V_259 ,
L_38 ,
V_301 , V_297 , V_181 , V_310 , V_272 , V_91 ) ;
if ( V_9 -> V_16 < V_91 * sizeof( * V_275 -> V_311 . V_89 ) ) {
F_44 ( V_3 , L_39 ) ;
return;
}
F_119 ( & V_86 ) ;
V_26 = F_57 ( V_8 , & V_275 -> V_311 , & V_86 ) ;
if ( V_26 < 0 ) {
F_44 ( V_3 , L_40 , V_26 ) ;
V_8 -> V_98 = true ;
return;
}
if ( V_310 )
F_134 ( V_3 , & V_86 ) ;
while ( ! F_54 ( & V_86 ) ) {
F_119 ( & V_63 ) ;
V_26 = F_129 ( & V_86 , & V_63 ) ;
switch ( V_26 ) {
case 0 :
F_75 ( V_3 , & V_63 , V_123 ) ;
F_116 ( V_3 , & V_63 , V_123 ) ;
F_102 ( V_3 , & V_63 , V_123 ) ;
F_106 ( V_3 , & V_63 , V_123 ) ;
break;
case - V_307 :
default:
F_44 ( V_3 , L_41 , V_26 ) ;
V_8 -> V_98 = true ;
F_47 ( & V_86 ) ;
return;
}
}
F_33 ( & V_8 -> V_49 ) ;
}
void F_137 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_274 * V_275 = (struct V_274 * ) V_9 -> V_36 ;
if ( ! F_17 ( ( unsigned long ) V_9 -> V_36 , 4 ) )
F_44 ( V_3 , L_42 ) ;
F_67 ( V_3 , V_259 , L_43 ,
V_275 -> V_178 . V_314 ) ;
switch ( V_275 -> V_178 . V_314 ) {
case V_315 : {
V_8 -> V_316 = V_275 -> V_317 . V_318 ;
V_8 -> V_319 = V_275 -> V_317 . V_320 ;
F_138 ( & V_8 -> V_321 ) ;
break;
}
case V_322 :
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_53 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_323 : {
struct V_324 V_85 = {
. V_301 = V_275 -> V_325 . V_301 ,
. V_297 = F_58 ( V_275 -> V_325 . V_297 ) ,
} ;
memcpy ( V_85 . V_302 , V_275 -> V_325 . V_302 , sizeof( V_85 . V_302 ) ) ;
F_139 ( V_8 , & V_85 ) ;
break;
}
case V_326 : {
struct V_327 V_85 = {
. V_297 = F_58 ( V_275 -> V_328 . V_297 ) ,
} ;
F_140 ( V_8 , & V_85 ) ;
break;
}
case V_329 : {
struct V_276 V_277 = {} ;
int V_123 = F_15 ( V_275 -> V_330 . V_123 ) ;
V_277 . V_280 =
F_15 ( V_275 -> V_330 . V_331 ) ;
switch ( V_123 ) {
case V_332 :
break;
case V_333 :
V_277 . V_283 = true ;
break;
case V_334 :
V_277 . V_288 = true ;
break;
}
F_29 ( & V_8 -> V_281 ) ;
F_122 ( V_8 , & V_277 ) ;
F_34 ( & V_8 -> V_281 ) ;
break;
}
case V_335 :
F_29 ( & V_8 -> V_281 ) ;
F_48 ( & V_8 -> V_52 , V_9 ) ;
F_34 ( & V_8 -> V_281 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
case V_336 : {
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_337 * V_85 = & V_275 -> V_338 ;
F_67 ( V_3 , V_259 ,
L_44 ,
F_58 ( V_85 -> V_297 ) ,
! ! ( V_85 -> V_38 & V_339 ) ,
F_51 ( V_85 -> V_38 , V_340 ) ) ;
F_138 ( & V_3 -> V_341 ) ;
break;
}
case V_342 : {
F_45 ( V_3 , V_59 , NULL , L_45 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
F_120 ( V_8 , & V_275 -> V_343 ) ;
break;
}
case V_344 :
break;
case V_345 :
F_141 ( V_3 , V_9 -> V_36 , V_9 -> V_16 ) ;
break;
case V_346 :
F_44 ( V_3 , L_46 ) ;
break;
case V_347 :
F_123 ( V_3 , V_275 ) ;
break;
case V_348 :
F_127 ( V_3 , V_275 ) ;
break;
case V_349 : {
struct V_350 * V_178 =
(struct V_350 * ) V_275 -> V_351 . V_352 ;
F_142 ( V_3 , V_275 -> V_351 . V_352 ,
sizeof( * V_178 ) +
F_58 ( V_178 -> V_19 ) ) ;
break;
}
case V_353 : {
break;
}
case V_354 : {
F_29 ( & V_8 -> V_13 . V_41 ) ;
F_48 ( & V_8 -> V_54 , V_9 ) ;
F_34 ( & V_8 -> V_13 . V_41 ) ;
F_33 ( & V_8 -> V_51 ) ;
return;
}
case V_355 :
break;
default:
F_44 ( V_3 , L_47 ,
V_275 -> V_178 . V_314 ) ;
F_45 ( V_3 , V_59 , NULL , L_45 ,
V_9 -> V_36 , V_9 -> V_16 ) ;
break;
} ;
F_10 ( V_9 ) ;
}
static void V_105 ( unsigned long V_83 )
{
struct V_7 * V_8 = (struct V_7 * ) V_83 ;
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_274 * V_275 ;
struct V_1 * V_9 ;
F_29 ( & V_8 -> V_281 ) ;
while ( ( V_9 = F_107 ( & V_8 -> V_52 ) ) ) {
F_121 ( V_8 -> V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_281 ) ;
F_29 ( & V_8 -> V_13 . V_41 ) ;
while ( ( V_9 = F_107 ( & V_8 -> V_53 ) ) ) {
V_275 = (struct V_274 * ) V_9 -> V_36 ;
F_117 ( V_8 , & V_275 -> V_356 ) ;
F_10 ( V_9 ) ;
}
while ( ( V_9 = F_107 ( & V_8 -> V_54 ) ) ) {
F_135 ( V_3 , V_9 ) ;
F_10 ( V_9 ) ;
}
F_34 ( & V_8 -> V_13 . V_41 ) ;
}
