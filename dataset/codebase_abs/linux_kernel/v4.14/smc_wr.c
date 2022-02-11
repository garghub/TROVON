static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_2 -> V_6 [ V_4 ] . V_3 == V_3 )
return V_4 ;
}
return V_2 -> V_5 ;
}
static inline void F_2 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
struct V_1 * V_2 ;
T_2 V_11 ;
int V_4 ;
V_2 = V_8 -> V_12 -> V_13 ;
if ( V_8 -> V_14 == V_15 ) {
if ( V_8 -> V_16 )
V_2 -> V_17 = V_18 ;
else
V_2 -> V_17 = V_19 ;
F_3 ( & V_2 -> V_20 ) ;
return;
}
V_11 = F_1 ( V_2 , V_8 -> V_3 ) ;
if ( V_11 == V_2 -> V_5 )
return;
V_2 -> V_6 [ V_11 ] . V_21 = V_8 -> V_16 ;
memcpy ( & V_10 , & V_2 -> V_6 [ V_11 ] , sizeof( V_10 ) ) ;
memset ( & V_2 -> V_6 [ V_11 ] , 0 ,
sizeof( V_2 -> V_6 [ V_11 ] ) ) ;
memset ( & V_2 -> V_22 [ V_11 ] , 0 ,
sizeof( V_2 -> V_22 [ V_11 ] ) ) ;
if ( ! F_4 ( V_11 , V_2 -> V_23 ) )
return;
if ( V_8 -> V_16 ) {
struct V_24 * V_25 ;
F_5 (i, link->wr_tx_mask, link->wr_tx_cnt) {
memset ( & V_2 -> V_6 [ V_4 ] , 0 ,
sizeof( V_2 -> V_6 [ V_4 ] ) ) ;
memset ( & V_2 -> V_22 [ V_4 ] , 0 ,
sizeof( V_2 -> V_22 [ V_4 ] ) ) ;
F_6 ( V_4 , V_2 -> V_23 ) ;
}
V_25 = F_7 ( V_2 , struct V_24 ,
V_26 [ V_27 ] ) ;
F_8 ( V_25 ) ;
}
if ( V_10 . V_28 )
V_10 . V_28 ( & V_10 . V_29 , V_2 , V_8 -> V_16 ) ;
F_3 ( & V_2 -> V_30 ) ;
}
static void F_9 ( unsigned long V_31 )
{
struct V_32 * V_33 = (struct V_32 * ) V_31 ;
struct V_7 V_8 [ V_34 ] ;
int V_4 = 0 , V_35 ;
int V_36 = 0 ;
V_37:
V_36 ++ ;
do {
V_35 = F_10 ( V_33 -> V_38 , V_34 , V_8 ) ;
if ( V_36 == 1 ) {
F_11 ( V_33 -> V_38 ,
V_39 |
V_40 ) ;
}
if ( ! V_35 )
break;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ )
F_2 ( & V_8 [ V_4 ] ) ;
} while ( V_35 > 0 );
if ( V_36 == 1 )
goto V_37;
}
void F_12 ( struct V_41 * V_41 , void * V_42 )
{
struct V_32 * V_33 = (struct V_32 * ) V_42 ;
F_13 ( & V_33 -> V_43 ) ;
}
static inline int F_14 ( struct V_1 * V_2 , T_2 * V_44 )
{
* V_44 = V_2 -> V_5 ;
F_15 (*idx, link->wr_tx_mask, link->wr_tx_cnt) {
if ( ! F_16 ( * V_44 , V_2 -> V_23 ) )
return 0 ;
}
* V_44 = V_2 -> V_5 ;
return - V_45 ;
}
int F_17 ( struct V_1 * V_2 ,
T_3 V_28 ,
struct V_46 * * V_47 ,
struct V_48 * * V_49 )
{
struct V_9 * V_50 ;
struct V_51 * V_52 ;
T_1 V_3 ;
T_2 V_44 ;
int V_35 ;
* V_47 = NULL ;
* V_49 = NULL ;
if ( F_18 () ) {
V_35 = F_14 ( V_2 , & V_44 ) ;
if ( V_35 )
return V_35 ;
} else {
V_35 = F_19 (
V_2 -> V_30 ,
( F_14 ( V_2 , & V_44 ) != - V_45 ) ,
V_53 ) ;
if ( ! V_35 ) {
struct V_24 * V_25 ;
V_25 = F_7 ( V_2 , struct V_24 ,
V_26 [ V_27 ] ) ;
F_8 ( V_25 ) ;
return - V_54 ;
}
if ( V_35 == - V_55 )
return - V_56 ;
if ( V_44 == V_2 -> V_5 )
return - V_54 ;
}
V_3 = F_20 ( V_2 ) ;
V_50 = & V_2 -> V_6 [ V_44 ] ;
V_50 -> V_3 = V_3 ;
V_50 -> V_28 = V_28 ;
V_50 -> V_2 = V_2 ;
V_50 -> V_44 = V_44 ;
V_52 = & V_2 -> V_57 [ V_44 ] ;
V_52 -> V_3 = V_3 ;
* V_47 = & V_2 -> V_22 [ V_44 ] ;
* V_49 = & V_50 -> V_29 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_9 * V_58 ;
V_58 = F_7 ( V_49 , struct V_9 , V_29 ) ;
if ( V_58 -> V_44 < V_2 -> V_5 ) {
memset ( & V_2 -> V_6 [ V_58 -> V_44 ] , 0 ,
sizeof( V_2 -> V_6 [ V_58 -> V_44 ] ) ) ;
memset ( & V_2 -> V_22 [ V_58 -> V_44 ] , 0 ,
sizeof( V_2 -> V_22 [ V_58 -> V_44 ] ) ) ;
F_4 ( V_58 -> V_44 , V_2 -> V_23 ) ;
return 1 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_48 * V_29 )
{
struct V_51 * V_59 = NULL ;
struct V_9 * V_58 ;
int V_35 ;
F_11 ( V_2 -> V_60 -> V_38 ,
V_39 | V_40 ) ;
V_58 = F_7 ( V_29 , struct V_9 , V_29 ) ;
V_35 = F_23 ( V_2 -> V_61 , & V_2 -> V_57 [ V_58 -> V_44 ] ,
& V_59 ) ;
if ( V_35 )
F_21 ( V_2 , V_29 ) ;
return V_35 ;
}
int F_24 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_51 * V_59 = NULL ;
int V_35 ;
F_11 ( V_2 -> V_60 -> V_38 ,
V_39 | V_40 ) ;
V_2 -> V_17 = V_64 ;
V_2 -> V_65 . V_66 . V_3 = ( T_1 ) ( V_67 ) V_63 ;
V_2 -> V_65 . V_63 = V_63 ;
V_2 -> V_65 . V_68 = V_63 -> V_69 ;
V_59 = & V_2 -> V_65 . V_66 ;
V_35 = F_23 ( V_2 -> V_61 , & V_2 -> V_65 . V_66 , & V_59 ) ;
F_25 ( V_59 != & V_2 -> V_65 . V_66 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_19 ( V_2 -> V_20 ,
( V_2 -> V_17 != V_64 ) ,
V_70 ) ;
if ( ! V_35 ) {
struct V_24 * V_25 ;
V_25 = F_7 ( V_2 , struct V_24 ,
V_26 [ V_27 ] ) ;
F_8 ( V_25 ) ;
return - V_54 ;
}
if ( V_35 == - V_55 )
return - V_56 ;
switch ( V_2 -> V_17 ) {
case V_19 :
V_35 = 0 ;
break;
case V_18 :
V_35 = - V_71 ;
break;
case V_64 :
V_35 = - V_54 ;
break;
}
return V_35 ;
}
void F_26 ( struct V_1 * V_2 , T_4 V_72 ,
T_5 V_73 ,
T_6 V_74 ,
unsigned long V_31 )
{
struct V_48 * V_75 ;
struct V_76 * V_77 ;
int V_4 ;
F_5 (i, link->wr_tx_mask, link->wr_tx_cnt) {
V_77 = (struct V_76 * ) & V_2 -> V_78 [ V_4 ] ;
if ( V_77 -> type != V_72 )
continue;
V_75 = & V_2 -> V_6 [ V_4 ] . V_29 ;
if ( V_73 ( V_75 , V_31 ) )
V_74 ( V_75 ) ;
}
}
bool F_27 ( struct V_1 * V_2 , T_4 V_72 ,
T_5 V_73 , unsigned long V_31 )
{
struct V_48 * V_75 ;
struct V_76 * V_77 ;
int V_4 ;
F_5 (i, link->wr_tx_mask, link->wr_tx_cnt) {
V_77 = (struct V_76 * ) & V_2 -> V_78 [ V_4 ] ;
if ( V_77 -> type != V_72 )
continue;
V_75 = & V_2 -> V_6 [ V_4 ] . V_29 ;
if ( V_73 ( V_75 , V_31 ) )
return true ;
}
return false ;
}
int F_28 ( struct V_79 * V_28 )
{
struct V_79 * V_80 ;
int V_35 = 0 ;
F_29 ( & V_81 ) ;
F_30 (smc_wr_rx_hash, h_iter, list, handler->type) {
if ( V_80 -> type == V_28 -> type ) {
V_35 = - V_82 ;
goto V_83;
}
}
F_31 ( V_84 , & V_28 -> V_85 , V_28 -> type ) ;
V_83:
F_32 ( & V_81 ) ;
return V_35 ;
}
static inline void F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_12 -> V_13 ;
struct V_79 * V_28 ;
struct V_76 * V_77 ;
T_1 V_86 ;
T_2 V_87 ;
if ( V_8 -> V_88 < sizeof( * V_77 ) )
return;
V_86 = V_8 -> V_3 ;
V_87 = F_34 ( V_86 , V_2 -> V_89 ) ;
V_77 = (struct V_76 * ) & V_2 -> V_78 [ V_87 ] ;
F_30 (smc_wr_rx_hash, handler, list, wr_rx->type) {
if ( V_28 -> type == V_77 -> type )
V_28 -> V_28 ( V_8 , V_77 ) ;
}
}
static inline void F_35 ( struct V_7 V_8 [] , int V_90 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
V_2 = V_8 [ V_4 ] . V_12 -> V_13 ;
if ( V_8 [ V_4 ] . V_16 == V_91 ) {
F_33 ( & V_8 [ V_4 ] ) ;
F_36 ( V_2 ) ;
} else {
struct V_24 * V_25 ;
switch ( V_8 [ V_4 ] . V_16 ) {
case V_92 :
case V_93 :
case V_94 :
V_25 = F_7 ( V_2 , struct V_24 ,
V_26 [ V_27 ] ) ;
F_8 ( V_25 ) ;
break;
default:
F_36 ( V_2 ) ;
break;
}
}
}
}
static void F_37 ( unsigned long V_31 )
{
struct V_32 * V_33 = (struct V_32 * ) V_31 ;
struct V_7 V_8 [ V_34 ] ;
int V_36 = 0 ;
int V_35 ;
V_37:
V_36 ++ ;
do {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_35 = F_10 ( V_33 -> V_95 , V_34 , V_8 ) ;
if ( V_36 == 1 ) {
F_11 ( V_33 -> V_95 ,
V_96
| V_40 ) ;
}
if ( ! V_35 )
break;
F_35 ( & V_8 [ 0 ] , V_35 ) ;
} while ( V_35 > 0 );
if ( V_36 == 1 )
goto V_37;
}
void F_38 ( struct V_41 * V_41 , void * V_42 )
{
struct V_32 * V_33 = (struct V_32 * ) V_42 ;
F_13 ( & V_33 -> V_97 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_35 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_89 ; V_4 ++ )
V_35 = F_36 ( V_2 ) ;
return V_35 ;
}
void F_40 ( struct V_1 * V_26 )
{
struct V_98 * V_99 = & V_26 -> V_100 ;
struct V_101 V_102 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_41 ( V_26 -> V_61 , V_99 ,
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ,
& V_102 ) ;
V_26 -> V_5 = F_42 ( V_120 , V_121 ,
V_26 -> V_100 . V_122 . V_123 ) ;
V_26 -> V_89 = F_42 ( V_120 , V_121 * 3 ,
V_26 -> V_100 . V_122 . V_124 ) ;
}
static void F_43 ( struct V_1 * V_26 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_26 -> V_5 ; V_4 ++ ) {
V_26 -> V_125 [ V_4 ] . V_126 =
V_26 -> V_127 + V_4 * V_128 ;
V_26 -> V_125 [ V_4 ] . V_129 = V_130 ;
V_26 -> V_125 [ V_4 ] . V_131 = V_26 -> V_132 -> V_133 ;
V_26 -> V_57 [ V_4 ] . V_134 = NULL ;
V_26 -> V_57 [ V_4 ] . V_135 = & V_26 -> V_125 [ V_4 ] ;
V_26 -> V_57 [ V_4 ] . V_136 = 1 ;
V_26 -> V_57 [ V_4 ] . V_14 = V_137 ;
V_26 -> V_57 [ V_4 ] . V_138 =
V_139 | V_140 ;
}
for ( V_4 = 0 ; V_4 < V_26 -> V_89 ; V_4 ++ ) {
V_26 -> V_141 [ V_4 ] . V_126 =
V_26 -> V_142 + V_4 * V_128 ;
V_26 -> V_141 [ V_4 ] . V_129 = V_128 ;
V_26 -> V_141 [ V_4 ] . V_131 = V_26 -> V_132 -> V_133 ;
V_26 -> V_143 [ V_4 ] . V_134 = NULL ;
V_26 -> V_143 [ V_4 ] . V_135 = & V_26 -> V_141 [ V_4 ] ;
V_26 -> V_143 [ V_4 ] . V_136 = 1 ;
}
V_26 -> V_65 . V_66 . V_134 = NULL ;
V_26 -> V_65 . V_66 . V_136 = 0 ;
V_26 -> V_65 . V_66 . V_138 = V_139 ;
V_26 -> V_65 . V_66 . V_14 = V_144 ;
V_26 -> V_65 . V_145 = V_146 | V_147 ;
}
void F_44 ( struct V_1 * V_26 )
{
struct V_148 * V_149 ;
memset ( V_26 -> V_23 , 0 ,
F_45 ( V_121 ) * sizeof( * V_26 -> V_23 ) ) ;
if ( ! V_26 -> V_60 )
return;
V_149 = V_26 -> V_60 -> V_149 ;
if ( V_26 -> V_142 ) {
F_46 ( V_149 , V_26 -> V_142 ,
V_128 * V_26 -> V_89 ,
V_150 ) ;
V_26 -> V_142 = 0 ;
}
if ( V_26 -> V_127 ) {
F_46 ( V_149 , V_26 -> V_127 ,
V_128 * V_26 -> V_5 ,
V_151 ) ;
V_26 -> V_127 = 0 ;
}
}
void F_47 ( struct V_1 * V_26 )
{
F_48 ( V_26 -> V_6 ) ;
V_26 -> V_6 = NULL ;
F_48 ( V_26 -> V_23 ) ;
V_26 -> V_23 = NULL ;
F_48 ( V_26 -> V_125 ) ;
V_26 -> V_125 = NULL ;
F_48 ( V_26 -> V_141 ) ;
V_26 -> V_141 = NULL ;
F_48 ( V_26 -> V_143 ) ;
V_26 -> V_143 = NULL ;
F_48 ( V_26 -> V_57 ) ;
V_26 -> V_57 = NULL ;
F_48 ( V_26 -> V_22 ) ;
V_26 -> V_22 = NULL ;
F_48 ( V_26 -> V_78 ) ;
V_26 -> V_78 = NULL ;
}
int F_49 ( struct V_1 * V_2 )
{
V_2 -> V_22 = F_50 ( V_121 , V_128 , V_152 ) ;
if ( ! V_2 -> V_22 )
goto V_153;
V_2 -> V_78 = F_50 ( V_121 * 3 , V_128 ,
V_152 ) ;
if ( ! V_2 -> V_78 )
goto V_154;
V_2 -> V_57 = F_50 ( V_121 , sizeof( V_2 -> V_57 [ 0 ] ) ,
V_152 ) ;
if ( ! V_2 -> V_57 )
goto V_155;
V_2 -> V_143 = F_50 ( V_121 * 3 ,
sizeof( V_2 -> V_143 [ 0 ] ) ,
V_152 ) ;
if ( ! V_2 -> V_143 )
goto V_156;
V_2 -> V_125 = F_50 ( V_121 , sizeof( V_2 -> V_125 [ 0 ] ) ,
V_152 ) ;
if ( ! V_2 -> V_125 )
goto V_157;
V_2 -> V_141 = F_50 ( V_121 * 3 ,
sizeof( V_2 -> V_141 [ 0 ] ) ,
V_152 ) ;
if ( ! V_2 -> V_141 )
goto V_158;
V_2 -> V_23 = F_51 (
F_45 ( V_121 ) * sizeof( * V_2 -> V_23 ) ,
V_152 ) ;
if ( ! V_2 -> V_23 )
goto V_159;
V_2 -> V_6 = F_50 ( V_121 ,
sizeof( V_2 -> V_6 [ 0 ] ) ,
V_152 ) ;
if ( ! V_2 -> V_6 )
goto V_160;
return 0 ;
V_160:
F_48 ( V_2 -> V_23 ) ;
V_159:
F_48 ( V_2 -> V_141 ) ;
V_158:
F_48 ( V_2 -> V_125 ) ;
V_157:
F_48 ( V_2 -> V_143 ) ;
V_156:
F_48 ( V_2 -> V_57 ) ;
V_155:
F_48 ( V_2 -> V_78 ) ;
V_154:
F_48 ( V_2 -> V_22 ) ;
V_153:
return - V_161 ;
}
void F_52 ( struct V_32 * V_60 )
{
F_53 ( & V_60 -> V_97 ) ;
F_53 ( & V_60 -> V_43 ) ;
}
void F_54 ( struct V_32 * V_60 )
{
F_55 ( & V_60 -> V_97 , F_37 ,
( unsigned long ) V_60 ) ;
F_55 ( & V_60 -> V_43 , F_9 ,
( unsigned long ) V_60 ) ;
}
int F_56 ( struct V_1 * V_26 )
{
struct V_148 * V_149 = V_26 -> V_60 -> V_149 ;
int V_35 = 0 ;
F_57 ( & V_26 -> V_162 , 0 ) ;
V_26 -> V_163 = 0 ;
V_26 -> V_142 = F_58 (
V_149 , V_26 -> V_78 , V_128 * V_26 -> V_89 ,
V_150 ) ;
if ( F_59 ( V_149 , V_26 -> V_142 ) ) {
V_26 -> V_142 = 0 ;
V_35 = - V_71 ;
goto V_164;
}
V_26 -> V_127 = F_58 (
V_149 , V_26 -> V_22 , V_128 * V_26 -> V_5 ,
V_151 ) ;
if ( F_59 ( V_149 , V_26 -> V_127 ) ) {
V_35 = - V_71 ;
goto V_165;
}
F_43 ( V_26 ) ;
memset ( V_26 -> V_23 , 0 ,
F_45 ( V_121 ) * sizeof( * V_26 -> V_23 ) ) ;
F_60 ( & V_26 -> V_30 ) ;
F_60 ( & V_26 -> V_20 ) ;
return V_35 ;
V_165:
F_46 ( V_149 , V_26 -> V_142 ,
V_128 * V_26 -> V_89 ,
V_150 ) ;
V_26 -> V_142 = 0 ;
V_164:
return V_35 ;
}
