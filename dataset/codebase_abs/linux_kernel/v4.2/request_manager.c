static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 -> V_6 [ V_3 ] ;
return V_5 -> V_7 ;
}
int F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 = NULL ;
T_1 V_11 ;
struct V_12 * V_13 ;
if ( F_3 ( V_2 ) )
V_10 = & ( F_4 ( F_5 ( V_2 , V_14 , V_10 ) ) ) ;
if ( ! V_10 ) {
F_6 ( & V_2 -> V_15 -> V_16 , L_1 ,
V_2 -> V_17 ) ;
return 1 ;
}
if ( V_8 & ( V_8 - 1 ) ) {
F_6 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_3 ) ;
return 1 ;
}
V_11 = ( T_1 ) V_10 -> V_18 * V_8 ;
V_5 = V_2 -> V_6 [ V_3 ] ;
V_5 -> V_19 = F_7 ( V_2 , V_11 ,
( V_20 * ) & V_5 -> V_21 ) ;
if ( ! V_5 -> V_19 ) {
F_6 ( & V_2 -> V_15 -> V_16 , L_3 ,
V_3 ) ;
return 1 ;
}
V_5 -> V_22 = V_8 ;
V_5 -> V_23 = F_8 ( sizeof( * V_5 -> V_23 ) * V_8 ) ;
if ( ! V_5 -> V_23 ) {
F_9 ( V_2 , V_11 , V_5 -> V_19 , V_5 -> V_21 ) ;
F_6 ( & V_2 -> V_15 -> V_16 , L_4 ,
V_3 ) ;
return 1 ;
}
memset ( V_5 -> V_23 , 0 , sizeof( * V_5 -> V_23 ) * V_8 ) ;
F_10 ( & V_2 -> V_15 -> V_16 , L_5 ,
V_3 , V_5 -> V_19 , V_5 -> V_21 , V_5 -> V_22 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_24 = ( T_1 ) V_10 -> V_25 ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 0 ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 0 ;
V_5 -> V_31 = 1 ;
V_5 -> V_32 = ( T_1 ) V_10 -> V_32 ;
F_11 ( & V_5 -> V_33 , 0 ) ;
F_12 ( & V_5 -> V_34 ) ;
V_2 -> V_35 . V_5 |= ( 1 << V_3 ) ;
V_2 -> V_35 . V_36 |= ( ( V_10 -> V_18 == 64 ) << V_3 ) ;
V_5 -> V_7 = ( V_10 -> V_18 == 64 ) ;
V_2 -> V_37 . V_38 ( V_2 , V_3 ) ;
V_2 -> V_39 [ V_3 ] . V_40 = F_13 ( L_6 ) ;
if ( ! V_2 -> V_39 [ V_3 ] . V_40 ) {
F_9 ( V_2 , V_11 , V_5 -> V_19 , V_5 -> V_21 ) ;
F_6 ( & V_2 -> V_15 -> V_16 , L_7 ,
V_3 ) ;
return 1 ;
}
V_13 = & V_2 -> V_39 [ V_3 ] ;
F_14 ( & V_13 -> V_41 . V_42 , V_43 ) ;
V_13 -> V_41 . V_44 = V_2 ;
V_13 -> V_41 . V_45 = V_3 ;
F_15 ( V_13 -> V_40 , & V_13 -> V_41 . V_42 , F_16 ( 1 ) ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_46 = 0 , V_11 ;
struct V_4 * V_5 = V_2 -> V_6 [ V_3 ] ;
F_18 ( & V_2 -> V_39 [ V_3 ] . V_41 . V_42 ) ;
F_19 ( V_2 -> V_39 [ V_3 ] . V_40 ) ;
F_20 ( V_2 -> V_39 [ V_3 ] . V_40 ) ;
if ( F_3 ( V_2 ) )
V_46 =
F_21 ( F_5 ( V_2 , V_14 , V_10 ) ) ;
F_22 ( V_5 -> V_23 ) ;
if ( V_5 -> V_19 ) {
V_11 = V_5 -> V_22 * V_46 ;
F_9 ( V_2 , ( T_1 ) V_11 , V_5 -> V_19 ,
V_5 -> V_21 ) ;
return 0 ;
}
return 1 ;
}
int F_23 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_8 ,
void * V_47 )
{
if ( V_2 -> V_6 [ V_3 ] ) {
F_10 ( & V_2 -> V_15 -> V_16 , L_8 ,
V_3 ) ;
V_2 -> V_6 [ V_3 ] -> V_47 = V_47 ;
return 0 ;
}
V_2 -> V_6 [ V_3 ] =
F_8 ( sizeof( struct V_4 ) ) ;
if ( ! V_2 -> V_6 [ V_3 ] )
return 1 ;
memset ( V_2 -> V_6 [ V_3 ] , 0 ,
sizeof( struct V_4 ) ) ;
V_2 -> V_6 [ V_3 ] -> V_47 = V_47 ;
if ( F_2 ( V_2 , V_3 , V_8 ) ) {
F_22 ( V_2 -> V_6 [ V_3 ] ) ;
V_2 -> V_6 [ V_3 ] = NULL ;
return 1 ;
}
V_2 -> V_48 ++ ;
V_2 -> V_37 . V_49 ( V_2 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_50 , V_51 = 1000 , V_52 , V_53 = 0 ;
do {
V_53 = 0 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
if ( ! ( V_2 -> V_35 . V_5 & ( 1UL << V_50 ) ) )
continue;
V_52 =
F_25 ( & V_2 ->
V_6 [ V_50 ] -> V_33 ) ;
if ( V_52 )
F_26 ( V_2 , V_50 ) ;
V_53 += V_52 ;
}
if ( V_53 == 0 )
break;
F_27 ( 1 ) ;
} while ( V_51 -- && V_53 );
return V_53 ;
}
static inline void
F_28 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
if ( F_25 ( & V_2 -> V_55 ) == V_56 ) {
F_29 ( V_5 -> V_26 , V_5 -> V_57 ) ;
F_30 () ;
V_5 -> V_26 = 0 ;
V_5 -> V_30 = V_58 ;
return;
}
}
static inline void F_31 ( struct V_4 * V_5 ,
T_3 * V_59 )
{
T_3 * V_60 , V_61 ;
V_61 = ( ( V_5 -> V_7 ) ? 64 : 32 ) ;
V_60 = V_5 -> V_19 + ( V_61 * V_5 -> V_27 ) ;
memcpy ( V_60 , V_59 , V_61 ) ;
}
int
F_32 ( struct V_1 * V_2 , int V_62 ,
void (* F_33)( void * ) )
{
if ( V_62 > V_63 ) {
F_6 ( & V_2 -> V_15 -> V_16 , L_9 ,
V_64 , V_62 ) ;
return - V_65 ;
}
V_66 [ V_2 -> V_67 ] [ V_62 ] = F_33 ;
return 0 ;
}
static inline void
F_34 ( struct V_4 * V_5 ,
int V_68 , void * V_69 , int V_62 )
{
V_5 -> V_23 [ V_68 ] . V_69 = V_69 ;
V_5 -> V_23 [ V_68 ] . V_62 = V_62 ;
}
int
F_35 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_62 ;
void * V_69 ;
T_1 V_70 = V_5 -> V_29 ;
T_1 V_71 = 0 ;
unsigned V_72 = 0 , V_73 = 0 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
while ( V_70 != V_5 -> V_28 ) {
V_62 = V_5 -> V_23 [ V_70 ] . V_62 ;
V_69 = V_5 -> V_23 [ V_70 ] . V_69 ;
if ( V_62 == V_78 )
goto V_79;
F_36 ( V_69 , V_62 , & V_72 ,
& V_73 ) ;
switch ( V_62 ) {
case V_80 :
case V_81 :
case V_82 :
V_66 [ V_2 -> V_67 ] [ V_62 ] ( V_69 ) ;
break;
case V_83 :
case V_84 :
V_75 = V_69 ;
V_77 = (struct V_76 * ) & V_75 -> V_59 . V_77 ;
if ( V_77 -> V_85 ) {
F_37 ( & V_2 -> V_86
[ V_87 ] . V_34 ) ;
F_38 ( & V_2 -> V_86
[ V_87 ] .
V_88 ) ;
F_39 ( & V_75 -> V_89 , & V_2 -> V_86
[ V_87 ] . V_90 ) ;
F_40 ( & V_2 -> V_86
[ V_87 ] . V_34 ) ;
} else {
if ( V_75 -> V_91 ) {
V_75 -> V_91 ( V_2 , V_92 ,
V_75 -> V_93 ) ;
}
}
break;
default:
F_6 ( & V_2 -> V_15 -> V_16 ,
L_10 ,
V_64 , V_62 , V_69 , V_70 ) ;
}
V_5 -> V_23 [ V_70 ] . V_69 = NULL ;
V_5 -> V_23 [ V_70 ] . V_62 = 0 ;
V_79:
V_71 ++ ;
F_41 ( V_70 , V_5 -> V_22 ) ;
}
if ( V_73 )
F_42 ( V_5 -> V_47 , V_72 ,
V_73 ) ;
V_5 -> V_29 = V_70 ;
return V_71 ;
}
static inline void
F_43 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_1 V_94 = 0 ;
V_5 -> V_28 = V_2 -> V_37 . V_95 ( V_2 , V_5 ) ;
if ( V_5 -> V_29 != V_5 -> V_28 )
V_94 = F_35 ( V_2 , V_5 ) ;
if ( V_94 ) {
F_44 ( V_94 , & V_5 -> V_33 ) ;
V_5 -> V_96 . V_97 += V_94 ;
}
}
static void
F_45 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_1 V_98 )
{
if ( F_25 ( & V_5 -> V_33 ) >= ( V_99 ) V_98 ) {
F_37 ( & V_5 -> V_34 ) ;
F_43 ( V_2 , V_5 ) ;
F_40 ( & V_5 -> V_34 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
T_2 V_100 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_6 [ V_3 ] ;
if ( ! V_5 )
return;
V_100 = V_5 -> V_30 + V_5 -> V_32 ;
if ( ! F_46 ( V_58 , ( unsigned long ) V_100 ) )
return;
V_5 -> V_30 = V_58 ;
F_37 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_26 != 0 )
F_28 ( V_2 , V_5 ) ;
F_40 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_31 )
F_45 ( V_2 , V_5 , 1 ) ;
}
static void V_43 ( struct V_101 * V_42 )
{
struct V_102 * V_41 = (struct V_102 * ) V_42 ;
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_44 ;
unsigned long V_3 = V_41 -> V_45 ;
struct V_12 * V_13 = & V_2 -> V_39 [ V_3 ] ;
F_26 ( V_2 , V_3 ) ;
F_15 ( V_13 -> V_40 , & V_13 -> V_41 . V_42 , F_16 ( 1 ) ) ;
}
int
F_47 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_103 , void * V_59 , void * V_69 ,
T_1 V_104 , T_1 V_62 )
{
struct V_105 V_106 ;
struct V_4 * V_5 = V_2 -> V_6 [ V_3 ] ;
F_37 ( & V_5 -> V_34 ) ;
V_106 = F_48 ( V_2 , V_5 , V_103 , V_59 ) ;
if ( V_106 . V_55 != V_107 ) {
F_49 ( V_69 , V_62 ) ;
F_34 ( V_5 , V_106 . V_108 , V_69 , V_62 ) ;
F_50 ( V_2 , V_3 , V_109 , V_104 ) ;
F_50 ( V_2 , V_3 , V_110 , 1 ) ;
if ( V_5 -> V_26 >= V_5 -> V_24 || V_103 )
F_28 ( V_2 , V_5 ) ;
} else {
F_50 ( V_2 , V_3 , V_111 , 1 ) ;
}
F_40 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_31 )
F_45 ( V_2 , V_5 , 2 ) ;
return V_106 . V_55 ;
}
void
F_51 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
T_3 V_112 ,
T_3 V_113 ,
T_1 V_114 ,
T_2 V_115 ,
T_2 V_116 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_76 * V_77 ;
struct V_121 * V_122 ;
F_52 ( V_112 > 15 ) ;
F_52 ( V_113 > 127 ) ;
V_118 = F_53 ( V_2 ) ;
V_120 = (struct V_119 * ) & V_75 -> V_59 . V_120 ;
V_120 -> V_123 = V_124 ;
V_120 -> V_125 = V_126 ;
V_120 -> V_127 = 1 ;
V_120 -> V_128 = F_54 ( V_118 ) ;
if ( V_75 -> V_104 ) {
V_120 -> V_129 = V_75 -> V_104 ;
V_120 -> V_130 = 1 ;
}
V_77 = (struct V_76 * ) & V_75 -> V_59 . V_77 ;
V_77 -> V_112 = V_112 ;
V_77 -> V_113 = V_113 ;
V_77 -> V_131 = V_114 ;
V_75 -> V_59 . V_131 [ 0 ] = V_115 ;
V_75 -> V_59 . V_131 [ 1 ] = V_116 ;
if ( V_75 -> V_132 ) {
V_122 = (struct V_121 * ) & V_75 -> V_59 . V_122 ;
V_122 -> V_133 = V_2 -> V_133 ;
V_122 -> V_134 = V_75 -> V_132 ;
V_77 -> V_85 = 1 ;
V_77 -> V_135 = 4 ;
V_120 -> V_136 = 40 ;
} else {
V_77 -> V_85 = 0 ;
V_77 -> V_135 = 2 ;
V_120 -> V_136 = 24 ;
}
while ( ! ( V_2 -> V_35 . V_5 & ( 1 << V_75 -> V_3 ) ) )
V_75 -> V_3 ++ ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_119 * V_120 ;
struct V_76 * V_77 ;
struct V_121 * V_122 ;
V_120 = (struct V_119 * ) & V_75 -> V_59 . V_120 ;
if ( V_120 -> V_129 ) {
F_52 ( ! V_75 -> V_137 ) ;
V_75 -> V_59 . V_138 = V_75 -> V_137 ;
}
V_77 = (struct V_76 * ) & V_75 -> V_59 . V_77 ;
if ( V_77 -> V_85 ) {
F_52 ( ! V_75 -> V_139 ) ;
F_52 ( ! V_75 -> V_140 ) ;
* V_75 -> V_140 = V_141 ;
V_122 = (struct V_121 * ) & V_75 -> V_59 . V_122 ;
V_75 -> V_59 . V_142 = V_75 -> V_139 ;
}
if ( V_75 -> V_143 )
V_75 -> V_144 = V_58 + V_75 -> V_143 ;
return F_47 ( V_2 , V_75 -> V_3 , 1 , & V_75 -> V_59 , V_75 ,
( T_1 ) V_120 -> V_129 , V_84 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_50 ;
T_2 V_145 ;
struct V_74 * V_75 ;
F_57 ( & V_2 -> V_146 . V_90 ) ;
F_12 ( & V_2 -> V_146 . V_34 ) ;
F_11 ( & V_2 -> V_146 . V_147 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_148 ; V_50 ++ ) {
V_75 = (struct V_74 * )
F_7 ( V_2 ,
V_149 ,
( V_20 * ) & V_145 ) ;
if ( ! V_75 )
return 1 ;
V_75 -> V_145 = V_145 ;
V_75 -> V_150 = V_149 ;
F_39 ( & V_75 -> V_89 , & V_2 -> V_146 . V_90 ) ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_151 * V_152 , * V_153 ;
struct V_74 * V_75 ;
F_59 ( & V_2 -> V_146 . V_34 ) ;
F_60 (tmp, tmp2, &oct->sc_buf_pool.head) {
F_61 ( V_152 ) ;
V_75 = (struct V_74 * ) V_152 ;
F_9 ( V_2 , V_75 -> V_150 , V_75 , V_75 -> V_145 ) ;
}
F_57 ( & V_2 -> V_146 . V_90 ) ;
F_62 ( & V_2 -> V_146 . V_34 ) ;
return 0 ;
}
struct V_74 * F_63 ( struct V_1 * V_2 ,
T_1 V_104 ,
T_1 V_132 ,
T_1 V_154 )
{
T_2 V_145 ;
T_1 V_150 ;
T_1 V_155 = sizeof( struct V_74 ) ;
struct V_74 * V_75 = NULL ;
struct V_151 * V_152 ;
F_52 ( ( V_155 + V_104 + V_132 + V_154 ) >
V_149 ) ;
F_59 ( & V_2 -> V_146 . V_34 ) ;
if ( F_64 ( & V_2 -> V_146 . V_90 ) ) {
F_62 ( & V_2 -> V_146 . V_34 ) ;
return NULL ;
}
F_65 (tmp, &oct->sc_buf_pool.head)
break;
F_61 ( V_152 ) ;
F_38 ( & V_2 -> V_146 . V_147 ) ;
F_62 ( & V_2 -> V_146 . V_34 ) ;
V_75 = (struct V_74 * ) V_152 ;
V_145 = V_75 -> V_145 ;
V_150 = V_75 -> V_150 ;
memset ( V_75 , 0 , V_75 -> V_150 ) ;
V_75 -> V_145 = V_145 ;
V_75 -> V_150 = V_150 ;
if ( V_154 ) {
V_75 -> V_44 = ( T_3 * ) V_75 + V_155 ;
V_75 -> V_154 = V_154 ;
}
V_155 = ( V_155 + V_154 + 127 ) & 0xffffff80 ;
if ( V_104 ) {
V_75 -> V_156 = ( T_3 * ) V_75 + V_155 ;
V_75 -> V_137 = V_145 + V_155 ;
V_75 -> V_104 = V_104 ;
}
V_155 = ( V_155 + V_104 + 127 ) & 0xffffff80 ;
if ( V_132 ) {
F_52 ( V_132 < 16 ) ;
V_75 -> V_157 = ( T_3 * ) V_75 + V_155 ;
V_75 -> V_139 = V_145 + V_155 ;
V_75 -> V_132 = V_132 ;
V_75 -> V_140 = ( T_2 * ) ( ( T_3 * ) ( V_75 -> V_157 ) + V_132 - 8 ) ;
}
return V_75 ;
}
void F_66 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
F_59 ( & V_2 -> V_146 . V_34 ) ;
F_39 ( & V_75 -> V_89 , & V_2 -> V_146 . V_90 ) ;
F_67 ( & V_2 -> V_146 . V_147 ) ;
F_62 ( & V_2 -> V_146 . V_34 ) ;
}
