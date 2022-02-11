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
V_11 = F_1 ( V_2 , V_8 -> V_3 ) ;
if ( V_11 == V_2 -> V_5 )
return;
V_2 -> V_6 [ V_11 ] . V_14 = V_8 -> V_15 ;
memcpy ( & V_10 , & V_2 -> V_6 [ V_11 ] , sizeof( V_10 ) ) ;
memset ( & V_2 -> V_6 [ V_11 ] , 0 ,
sizeof( V_2 -> V_6 [ V_11 ] ) ) ;
memset ( & V_2 -> V_16 [ V_11 ] , 0 ,
sizeof( V_2 -> V_16 [ V_11 ] ) ) ;
if ( ! F_3 ( V_11 , V_2 -> V_17 ) )
return;
if ( V_8 -> V_15 ) {
struct V_18 * V_19 ;
F_4 (i, link->wr_tx_mask, link->wr_tx_cnt) {
memset ( & V_2 -> V_6 [ V_4 ] , 0 ,
sizeof( V_2 -> V_6 [ V_4 ] ) ) ;
memset ( & V_2 -> V_16 [ V_4 ] , 0 ,
sizeof( V_2 -> V_16 [ V_4 ] ) ) ;
F_5 ( V_4 , V_2 -> V_17 ) ;
}
V_19 = F_6 ( V_2 , struct V_18 ,
V_20 [ V_21 ] ) ;
F_7 ( V_19 ) ;
}
if ( V_10 . V_22 )
V_10 . V_22 ( & V_10 . V_23 , V_2 , V_8 -> V_15 ) ;
F_8 ( & V_2 -> V_24 ) ;
}
static void F_9 ( unsigned long V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
struct V_7 V_8 [ V_28 ] ;
int V_4 = 0 , V_29 ;
int V_30 = 0 ;
V_31:
V_30 ++ ;
do {
V_29 = F_10 ( V_27 -> V_32 , V_28 , V_8 ) ;
if ( V_30 == 1 ) {
F_11 ( V_27 -> V_32 ,
V_33 |
V_34 ) ;
}
if ( ! V_29 )
break;
for ( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
F_2 ( & V_8 [ V_4 ] ) ;
} while ( V_29 > 0 );
if ( V_30 == 1 )
goto V_31;
}
void F_12 ( struct V_35 * V_35 , void * V_36 )
{
struct V_26 * V_27 = (struct V_26 * ) V_36 ;
F_13 ( & V_27 -> V_37 ) ;
}
static inline int F_14 ( struct V_1 * V_2 , T_2 * V_38 )
{
* V_38 = V_2 -> V_5 ;
F_15 (*idx, link->wr_tx_mask, link->wr_tx_cnt) {
if ( ! F_16 ( * V_38 , V_2 -> V_17 ) )
return 0 ;
}
* V_38 = V_2 -> V_5 ;
return - V_39 ;
}
int F_17 ( struct V_1 * V_2 ,
T_3 V_22 ,
struct V_40 * * V_41 ,
struct V_42 * * V_43 )
{
struct V_9 * V_44 ;
struct V_45 * V_46 ;
T_1 V_3 ;
T_2 V_38 ;
int V_29 ;
* V_41 = NULL ;
* V_43 = NULL ;
if ( F_18 () ) {
V_29 = F_14 ( V_2 , & V_38 ) ;
if ( V_29 )
return V_29 ;
} else {
V_29 = F_19 (
V_2 -> V_24 ,
( F_14 ( V_2 , & V_38 ) != - V_39 ) ,
V_47 ) ;
if ( ! V_29 ) {
struct V_18 * V_19 ;
V_19 = F_6 ( V_2 , struct V_18 ,
V_20 [ V_21 ] ) ;
F_7 ( V_19 ) ;
return - V_48 ;
}
if ( V_29 == - V_49 )
return - V_50 ;
if ( V_38 == V_2 -> V_5 )
return - V_48 ;
}
V_3 = F_20 ( V_2 ) ;
V_44 = & V_2 -> V_6 [ V_38 ] ;
V_44 -> V_3 = V_3 ;
V_44 -> V_22 = V_22 ;
V_44 -> V_2 = V_2 ;
V_44 -> V_38 = V_38 ;
V_46 = & V_2 -> V_51 [ V_38 ] ;
V_46 -> V_3 = V_3 ;
* V_41 = & V_2 -> V_16 [ V_38 ] ;
* V_43 = & V_44 -> V_23 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_9 * V_52 ;
V_52 = F_6 ( V_43 , struct V_9 , V_23 ) ;
if ( V_52 -> V_38 < V_2 -> V_5 ) {
memset ( & V_2 -> V_6 [ V_52 -> V_38 ] , 0 ,
sizeof( V_2 -> V_6 [ V_52 -> V_38 ] ) ) ;
memset ( & V_2 -> V_16 [ V_52 -> V_38 ] , 0 ,
sizeof( V_2 -> V_16 [ V_52 -> V_38 ] ) ) ;
F_3 ( V_52 -> V_38 , V_2 -> V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_42 * V_23 )
{
struct V_45 * V_53 = NULL ;
struct V_9 * V_52 ;
int V_29 ;
F_11 ( V_2 -> V_54 -> V_32 ,
V_55 | V_34 ) ;
V_52 = F_6 ( V_23 , struct V_9 , V_23 ) ;
V_29 = F_23 ( V_2 -> V_56 , & V_2 -> V_51 [ V_52 -> V_38 ] ,
& V_53 ) ;
if ( V_29 )
F_21 ( V_2 , V_23 ) ;
return V_29 ;
}
void F_24 ( struct V_1 * V_2 , T_4 V_57 ,
T_5 V_58 ,
T_6 V_59 ,
unsigned long V_25 )
{
struct V_42 * V_60 ;
struct V_61 * V_62 ;
int V_4 ;
F_4 (i, link->wr_tx_mask, link->wr_tx_cnt) {
V_62 = (struct V_61 * ) & V_2 -> V_63 [ V_4 ] ;
if ( V_62 -> type != V_57 )
continue;
V_60 = & V_2 -> V_6 [ V_4 ] . V_23 ;
if ( V_58 ( V_60 , V_25 ) )
V_59 ( V_60 ) ;
}
}
bool F_25 ( struct V_1 * V_2 , T_4 V_57 ,
T_5 V_58 , unsigned long V_25 )
{
struct V_42 * V_60 ;
struct V_61 * V_62 ;
int V_4 ;
F_4 (i, link->wr_tx_mask, link->wr_tx_cnt) {
V_62 = (struct V_61 * ) & V_2 -> V_63 [ V_4 ] ;
if ( V_62 -> type != V_57 )
continue;
V_60 = & V_2 -> V_6 [ V_4 ] . V_23 ;
if ( V_58 ( V_60 , V_25 ) )
return true ;
}
return false ;
}
int F_26 ( struct V_64 * V_22 )
{
struct V_64 * V_65 ;
int V_29 = 0 ;
F_27 ( & V_66 ) ;
F_28 (smc_wr_rx_hash, h_iter, list, handler->type) {
if ( V_65 -> type == V_22 -> type ) {
V_29 = - V_67 ;
goto V_68;
}
}
F_29 ( V_69 , & V_22 -> V_70 , V_22 -> type ) ;
V_68:
F_30 ( & V_66 ) ;
return V_29 ;
}
static inline void F_31 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_12 -> V_13 ;
struct V_64 * V_22 ;
struct V_61 * V_62 ;
T_1 V_71 ;
T_2 V_72 ;
if ( V_8 -> V_73 < sizeof( * V_62 ) )
return;
V_71 = V_8 -> V_3 ;
V_72 = F_32 ( V_71 , V_2 -> V_74 ) ;
V_62 = (struct V_61 * ) & V_2 -> V_63 [ V_72 ] ;
F_28 (smc_wr_rx_hash, handler, list, wr_rx->type) {
if ( V_22 -> type == V_62 -> type )
V_22 -> V_22 ( V_8 , V_62 ) ;
}
}
static inline void F_33 ( struct V_7 V_8 [] , int V_75 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_75 ; V_4 ++ ) {
V_2 = V_8 [ V_4 ] . V_12 -> V_13 ;
if ( V_8 [ V_4 ] . V_15 == V_76 ) {
F_31 ( & V_8 [ V_4 ] ) ;
F_34 ( V_2 ) ;
} else {
struct V_18 * V_19 ;
switch ( V_8 [ V_4 ] . V_15 ) {
case V_77 :
case V_78 :
case V_79 :
V_19 = F_6 ( V_2 , struct V_18 ,
V_20 [ V_21 ] ) ;
F_7 ( V_19 ) ;
break;
default:
F_34 ( V_2 ) ;
break;
}
}
}
}
static void F_35 ( unsigned long V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
struct V_7 V_8 [ V_28 ] ;
int V_30 = 0 ;
int V_29 ;
V_31:
V_30 ++ ;
do {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_29 = F_10 ( V_27 -> V_80 , V_28 , V_8 ) ;
if ( V_30 == 1 ) {
F_11 ( V_27 -> V_80 ,
V_55
| V_34 ) ;
}
if ( ! V_29 )
break;
F_33 ( & V_8 [ 0 ] , V_29 ) ;
} while ( V_29 > 0 );
if ( V_30 == 1 )
goto V_31;
}
void F_36 ( struct V_35 * V_35 , void * V_36 )
{
struct V_26 * V_27 = (struct V_26 * ) V_36 ;
F_13 ( & V_27 -> V_81 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_29 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_74 ; V_4 ++ )
V_29 = F_34 ( V_2 ) ;
return V_29 ;
}
void F_38 ( struct V_1 * V_20 )
{
struct V_82 * V_83 = & V_20 -> V_84 ;
struct V_85 V_86 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
F_39 ( V_20 -> V_56 , V_83 ,
V_87 |
V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 ,
& V_86 ) ;
V_20 -> V_5 = F_40 ( V_104 , V_105 ,
V_20 -> V_84 . V_106 . V_107 ) ;
V_20 -> V_74 = F_40 ( V_104 , V_105 * 3 ,
V_20 -> V_84 . V_106 . V_108 ) ;
}
static void F_41 ( struct V_1 * V_20 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_5 ; V_4 ++ ) {
V_20 -> V_109 [ V_4 ] . V_110 =
V_20 -> V_111 + V_4 * V_112 ;
V_20 -> V_109 [ V_4 ] . V_113 = V_114 ;
V_20 -> V_109 [ V_4 ] . V_115 = V_20 -> V_116 -> V_117 ;
V_20 -> V_51 [ V_4 ] . V_118 = NULL ;
V_20 -> V_51 [ V_4 ] . V_119 = & V_20 -> V_109 [ V_4 ] ;
V_20 -> V_51 [ V_4 ] . V_120 = 1 ;
V_20 -> V_51 [ V_4 ] . V_121 = V_122 ;
V_20 -> V_51 [ V_4 ] . V_123 =
V_124 | V_125 | V_126 ;
}
for ( V_4 = 0 ; V_4 < V_20 -> V_74 ; V_4 ++ ) {
V_20 -> V_127 [ V_4 ] . V_110 =
V_20 -> V_128 + V_4 * V_112 ;
V_20 -> V_127 [ V_4 ] . V_113 = V_112 ;
V_20 -> V_127 [ V_4 ] . V_115 = V_20 -> V_116 -> V_117 ;
V_20 -> V_129 [ V_4 ] . V_118 = NULL ;
V_20 -> V_129 [ V_4 ] . V_119 = & V_20 -> V_127 [ V_4 ] ;
V_20 -> V_129 [ V_4 ] . V_120 = 1 ;
}
}
void F_42 ( struct V_1 * V_20 )
{
struct V_130 * V_131 ;
memset ( V_20 -> V_17 , 0 ,
F_43 ( V_105 ) * sizeof( * V_20 -> V_17 ) ) ;
if ( ! V_20 -> V_54 )
return;
V_131 = V_20 -> V_54 -> V_131 ;
if ( V_20 -> V_128 ) {
F_44 ( V_131 , V_20 -> V_128 ,
V_112 * V_20 -> V_74 ,
V_132 ) ;
V_20 -> V_128 = 0 ;
}
if ( V_20 -> V_111 ) {
F_44 ( V_131 , V_20 -> V_111 ,
V_112 * V_20 -> V_5 ,
V_133 ) ;
V_20 -> V_111 = 0 ;
}
}
void F_45 ( struct V_1 * V_20 )
{
F_46 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_46 ( V_20 -> V_17 ) ;
V_20 -> V_17 = NULL ;
F_46 ( V_20 -> V_109 ) ;
V_20 -> V_109 = NULL ;
F_46 ( V_20 -> V_127 ) ;
V_20 -> V_127 = NULL ;
F_46 ( V_20 -> V_129 ) ;
V_20 -> V_129 = NULL ;
F_46 ( V_20 -> V_51 ) ;
V_20 -> V_51 = NULL ;
F_46 ( V_20 -> V_16 ) ;
V_20 -> V_16 = NULL ;
F_46 ( V_20 -> V_63 ) ;
V_20 -> V_63 = NULL ;
}
int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_48 ( V_105 , V_112 , V_134 ) ;
if ( ! V_2 -> V_16 )
goto V_135;
V_2 -> V_63 = F_48 ( V_105 * 3 , V_112 ,
V_134 ) ;
if ( ! V_2 -> V_63 )
goto V_136;
V_2 -> V_51 = F_48 ( V_105 , sizeof( V_2 -> V_51 [ 0 ] ) ,
V_134 ) ;
if ( ! V_2 -> V_51 )
goto V_137;
V_2 -> V_129 = F_48 ( V_105 * 3 ,
sizeof( V_2 -> V_129 [ 0 ] ) ,
V_134 ) ;
if ( ! V_2 -> V_129 )
goto V_138;
V_2 -> V_109 = F_48 ( V_105 , sizeof( V_2 -> V_109 [ 0 ] ) ,
V_134 ) ;
if ( ! V_2 -> V_109 )
goto V_139;
V_2 -> V_127 = F_48 ( V_105 * 3 ,
sizeof( V_2 -> V_127 [ 0 ] ) ,
V_134 ) ;
if ( ! V_2 -> V_127 )
goto V_140;
V_2 -> V_17 = F_49 (
F_43 ( V_105 ) * sizeof( * V_2 -> V_17 ) ,
V_134 ) ;
if ( ! V_2 -> V_17 )
goto V_141;
V_2 -> V_6 = F_48 ( V_105 ,
sizeof( V_2 -> V_6 [ 0 ] ) ,
V_134 ) ;
if ( ! V_2 -> V_6 )
goto V_142;
return 0 ;
V_142:
F_46 ( V_2 -> V_17 ) ;
V_141:
F_46 ( V_2 -> V_127 ) ;
V_140:
F_46 ( V_2 -> V_109 ) ;
V_139:
F_46 ( V_2 -> V_129 ) ;
V_138:
F_46 ( V_2 -> V_51 ) ;
V_137:
F_46 ( V_2 -> V_63 ) ;
V_136:
F_46 ( V_2 -> V_16 ) ;
V_135:
return - V_143 ;
}
void F_50 ( struct V_26 * V_54 )
{
F_51 ( & V_54 -> V_81 ) ;
F_51 ( & V_54 -> V_37 ) ;
}
void F_52 ( struct V_26 * V_54 )
{
F_53 ( & V_54 -> V_81 , F_35 ,
( unsigned long ) V_54 ) ;
F_53 ( & V_54 -> V_37 , F_9 ,
( unsigned long ) V_54 ) ;
}
int F_54 ( struct V_1 * V_20 )
{
struct V_130 * V_131 = V_20 -> V_54 -> V_131 ;
int V_29 = 0 ;
F_55 ( & V_20 -> V_144 , 0 ) ;
V_20 -> V_145 = 0 ;
V_20 -> V_128 = F_56 (
V_131 , V_20 -> V_63 , V_112 * V_20 -> V_74 ,
V_132 ) ;
if ( F_57 ( V_131 , V_20 -> V_128 ) ) {
V_20 -> V_128 = 0 ;
V_29 = - V_146 ;
goto V_147;
}
V_20 -> V_111 = F_56 (
V_131 , V_20 -> V_16 , V_112 * V_20 -> V_5 ,
V_133 ) ;
if ( F_57 ( V_131 , V_20 -> V_111 ) ) {
V_29 = - V_146 ;
goto V_148;
}
F_41 ( V_20 ) ;
memset ( V_20 -> V_17 , 0 ,
F_43 ( V_105 ) * sizeof( * V_20 -> V_17 ) ) ;
return V_29 ;
V_148:
F_44 ( V_131 , V_20 -> V_128 ,
V_112 * V_20 -> V_74 ,
V_132 ) ;
V_20 -> V_128 = 0 ;
V_147:
return V_29 ;
}
