static inline T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 )
{
T_3 V_4 = F_2 ( V_1 . V_5 ) >> ( 16 - V_3 -> V_6 ) ;
V_4 ^= ( V_4 >> 10 ) ;
V_4 ^= ( V_4 >> 6 ) ;
V_4 &= F_3 ( V_3 ) ;
return * ( T_1 * ) & V_4 ;
}
static inline T_2 F_4 ( T_4 V_7 , struct V_2 * V_3 )
{
T_2 V_8 ;
V_8 . V_5 = V_7 & F_5 ( V_3 ) ;
return V_8 ;
}
static inline struct V_9 * * F_6 ( T_2 V_1 , struct V_2 * V_3 )
{
return & V_3 -> V_10 [ F_1 ( V_1 , V_3 ) . V_5 ] ;
}
static inline struct V_9 * F_7 ( T_2 V_1 , struct V_2 * V_3 )
{
return V_3 -> V_10 [ F_1 ( V_1 , V_3 ) . V_5 ] ;
}
static inline int F_8 ( T_2 V_11 , T_2 V_12 )
{
return V_11 . V_5 == V_12 . V_5 ;
}
static inline int F_9 ( T_2 V_11 , T_2 V_12 )
{
return V_11 . V_5 <= V_12 . V_5 ;
}
static inline void F_10 ( struct V_2 * V_3 ,
struct V_9 * * V_13 ,
int V_14 )
{
struct V_9 * V_15 , * * V_16 , * V_17 ;
int V_18 ;
for( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
for( V_15 = V_13 [ V_18 ] ; V_15 ; V_15 = V_17 ) {
V_17 = V_15 -> V_19 ;
for( V_16 = F_6 ( V_15 -> V_20 , V_3 ) ;
* V_16 && F_9 ( ( * V_16 ) -> V_20 , V_15 -> V_20 ) ;
V_16 = & ( * V_16 ) -> V_19 )
;
V_15 -> V_19 = * V_16 ;
* V_16 = V_15 ;
}
}
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_9 * * V_21 , * * V_13 ;
int V_14 , V_22 ;
T_5 V_23 ;
V_14 = V_3 -> V_24 ;
switch( V_14 ) {
case 16 :
V_22 = 256 ;
V_23 = 0xFF ;
break;
default:
F_12 ( V_25 L_1 , V_14 ) ;
case 256 :
V_22 = 1024 ;
V_23 = 0x3FF ;
break;
}
V_21 = F_13 ( V_22 , sizeof( struct V_9 * ) , V_26 ) ;
if ( V_21 == NULL )
return;
F_14 ( & V_27 ) ;
V_13 = V_3 -> V_10 ;
V_3 -> V_10 = V_21 ;
V_3 -> V_28 = V_23 ;
V_3 -> V_24 = V_22 ;
F_10 ( V_3 , V_13 , V_14 ) ;
F_15 ( & V_27 ) ;
F_16 ( V_13 ) ;
}
static void F_17 ( struct V_9 * V_15 )
{
F_18 ( F_19 ( V_15 ) ) ;
F_20 ( V_29 , V_15 ) ;
}
static struct V_2 * F_21 ( struct F_1 * V_30 , int V_31 )
{
int V_18 ;
struct V_2 * V_3 = F_22 ( sizeof( struct V_2 ) , V_26 ) ;
if ( ! V_3 )
return NULL ;
if ( V_31 ) {
V_3 -> V_24 = 16 ;
V_3 -> V_28 = 0x0F ;
} else {
V_3 -> V_24 = 1 ;
V_3 -> V_28 = 0 ;
}
V_3 -> V_10 = F_13 ( V_3 -> V_24 , sizeof( struct V_9 * ) , V_26 ) ;
if ( ! V_3 -> V_10 ) {
F_16 ( V_3 ) ;
return NULL ;
}
V_3 -> V_6 = V_31 ;
V_3 -> V_32 = F_23 ( V_31 ) ;
for( V_18 = V_31 + 1 ; V_18 <= 16 ; V_18 ++ )
if ( V_30 -> V_33 [ V_18 ] )
break;
F_14 ( & V_27 ) ;
if ( V_18 > 16 ) {
V_3 -> V_34 = V_30 -> V_35 ;
V_30 -> V_35 = V_3 ;
} else {
V_3 -> V_34 = V_30 -> V_33 [ V_18 ] -> V_34 ;
V_30 -> V_33 [ V_18 ] -> V_34 = V_3 ;
}
V_30 -> V_33 [ V_31 ] = V_3 ;
F_15 ( & V_27 ) ;
return V_3 ;
}
static int F_24 ( struct V_36 * V_37 , struct V_38 * V_39 , struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
if ( V_41 -> V_47 && * V_41 -> V_47 != V_43 -> V_48 )
return 1 ;
if ( V_41 -> V_49 || V_41 -> V_50 ) {
if ( ( ! V_41 -> V_49 || * V_41 -> V_49 == V_43 -> V_51 -> V_52 ) &&
( ! V_41 -> V_50 || memcmp ( V_41 -> V_50 , & V_43 -> V_51 -> V_53 , 2 ) == 0 ) )
return 0 ;
return 1 ;
}
if ( V_41 -> V_54 == NULL )
return 0 ;
V_45 = F_25 ( V_41 -> V_54 ) ;
V_46 = F_26 ( V_41 -> V_54 ) ;
F_27 (fi) {
int V_55 = V_46 - sizeof( struct V_44 ) ;
T_4 V_56 ;
if ( V_55 < 0 || ( V_46 -= V_45 -> V_57 ) < 0 )
return - V_58 ;
if ( V_45 -> V_59 && V_45 -> V_59 != V_60 -> V_52 )
return 1 ;
if ( V_55 ) {
V_56 = F_28 ( F_29 ( V_45 ) , V_55 , V_61 ) ;
if ( V_56 && V_56 != V_60 -> V_53 )
return 1 ;
}
V_45 = F_30 ( V_45 ) ;
} F_31 ( V_43 ) ;
return 0 ;
}
static inline T_6 F_32 ( struct V_42 * V_43 )
{
T_6 V_62 = F_33 ( sizeof( struct V_36 ) )
+ F_34 ( 4 )
+ F_34 ( 2 )
+ F_34 ( 4 ) ;
V_62 += F_34 ( ( V_63 * F_34 ( 4 ) ) ) ;
if ( V_43 -> V_64 ) {
T_6 V_65 = F_34 ( sizeof( struct V_44 ) ) ;
V_65 += F_34 ( 4 ) ;
V_62 += F_34 ( V_43 -> V_64 * V_65 ) ;
}
return V_62 ;
}
static int F_35 ( struct V_66 * V_67 , T_5 V_68 , T_5 V_69 , int V_70 ,
T_5 V_71 , T_7 type , T_7 V_72 , void * V_7 , int V_73 ,
struct V_42 * V_43 , unsigned int V_74 )
{
struct V_36 * V_75 ;
struct V_38 * V_39 ;
unsigned char * V_12 = F_36 ( V_67 ) ;
V_39 = F_37 ( V_67 , V_68 , V_69 , V_70 , sizeof( * V_75 ) , V_74 ) ;
V_75 = F_38 ( V_39 ) ;
V_75 -> V_76 = V_77 ;
V_75 -> V_78 = V_73 ;
V_75 -> V_79 = 0 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = V_71 ;
F_39 ( V_67 , V_82 , V_71 ) ;
V_75 -> V_83 = V_43 -> V_84 ;
V_75 -> V_85 = V_72 ;
V_75 -> V_86 = type ;
if ( V_75 -> V_78 )
F_40 ( V_67 , V_87 , 2 , V_7 ) ;
V_75 -> V_88 = V_43 -> V_89 ;
if ( V_43 -> V_48 )
F_40 ( V_67 , V_90 , 4 , & V_43 -> V_48 ) ;
if ( F_41 ( V_67 , V_43 -> V_91 ) < 0 )
goto V_92;
if ( V_43 -> V_64 == 1 ) {
if ( V_43 -> V_51 -> V_53 )
F_40 ( V_67 , V_61 , 2 , & V_43 -> V_51 -> V_53 ) ;
if ( V_43 -> V_51 -> V_52 )
F_40 ( V_67 , V_93 , sizeof( int ) , & V_43 -> V_51 -> V_52 ) ;
}
if ( V_43 -> V_64 > 1 ) {
struct V_44 * V_45 ;
struct V_94 * V_95 ;
if ( F_42 ( V_67 ) <= F_43 ( 0 ) )
goto V_92;
V_95 = (struct V_94 * ) F_44 ( V_67 , F_43 ( 0 ) ) ;
F_27 (fi) {
if ( F_42 ( V_67 ) < F_45 ( F_45 ( sizeof( * V_45 ) ) + 4 ) )
goto V_92;
V_45 = (struct V_44 * ) F_44 ( V_67 , F_45 ( sizeof( * V_45 ) ) ) ;
V_45 -> V_96 = V_60 -> V_97 & 0xFF ;
V_45 -> V_98 = V_60 -> V_99 - 1 ;
V_45 -> V_59 = V_60 -> V_52 ;
if ( V_60 -> V_53 )
F_40 ( V_67 , V_61 , 2 , & V_60 -> V_53 ) ;
V_45 -> V_57 = F_36 ( V_67 ) - ( unsigned char * ) V_45 ;
} F_31 ( V_43 ) ;
V_95 -> V_100 = V_101 ;
V_95 -> V_102 = F_36 ( V_67 ) - ( T_7 * ) V_95 ;
}
V_39 -> V_103 = F_36 ( V_67 ) - V_12 ;
return V_67 -> V_104 ;
V_105:
V_92:
F_46 ( V_67 , V_12 ) ;
return - V_106 ;
}
static void F_47 ( int V_70 , struct V_9 * V_15 , int V_31 , T_5 V_71 ,
struct V_38 * V_39 , struct V_107 * V_108 )
{
struct V_66 * V_67 ;
T_5 V_68 = V_108 ? V_108 -> V_68 : 0 ;
int V_109 = - V_110 ;
V_67 = F_48 ( F_32 ( F_19 ( V_15 ) ) , V_26 ) ;
if ( V_67 == NULL )
goto V_111;
V_109 = F_35 ( V_67 , V_68 , V_39 -> V_112 , V_70 , V_71 ,
V_15 -> V_113 , V_15 -> V_114 , & V_15 -> V_20 , V_31 ,
F_19 ( V_15 ) , 0 ) ;
if ( V_109 < 0 ) {
F_49 ( V_109 == - V_106 ) ;
F_50 ( V_67 ) ;
goto V_111;
}
F_51 ( V_67 , & V_115 , V_68 , V_116 , V_39 , V_26 ) ;
return;
V_111:
if ( V_109 < 0 )
F_52 ( & V_115 , V_116 , V_109 ) ;
}
static T_8 int F_53 ( struct V_66 * V_67 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_2 * V_3 ,
struct V_9 * V_15 )
{
int V_18 , V_121 ;
V_121 = V_118 -> args [ 4 ] ;
for( V_18 = 0 ; V_15 ; V_18 ++ , V_15 = V_15 -> V_19 ) {
if ( V_18 < V_121 )
continue;
if ( V_15 -> V_122 & V_123 )
continue;
if ( F_35 ( V_67 , F_54 ( V_118 -> V_67 ) . V_68 ,
V_118 -> V_39 -> V_112 ,
V_124 ,
V_120 -> V_125 ,
( V_15 -> V_122 & V_123 ) ? 0 : V_15 -> V_113 ,
V_15 -> V_114 , & V_15 -> V_20 , V_3 -> V_6 ,
V_15 -> V_126 , V_127 ) < 0 ) {
V_118 -> args [ 4 ] = V_18 ;
return - 1 ;
}
}
V_118 -> args [ 4 ] = V_18 ;
return V_67 -> V_104 ;
}
static T_8 int F_55 ( struct V_66 * V_67 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_2 * V_3 )
{
int V_4 , V_128 ;
V_128 = V_118 -> args [ 3 ] ;
for( V_4 = 0 ; V_4 < V_3 -> V_24 ; V_4 ++ ) {
if ( V_4 < V_128 )
continue;
if ( V_4 > V_128 )
memset ( & V_118 -> args [ 4 ] , 0 , sizeof( V_118 -> args ) - 4 * sizeof( V_118 -> args [ 0 ] ) ) ;
if ( V_3 -> V_10 == NULL || V_3 -> V_10 [ V_4 ] == NULL )
continue;
if ( F_53 ( V_67 , V_118 , V_120 , V_3 , V_3 -> V_10 [ V_4 ] ) < 0 ) {
V_118 -> args [ 3 ] = V_4 ;
return - 1 ;
}
}
V_118 -> args [ 3 ] = V_4 ;
return V_67 -> V_104 ;
}
static int F_56 ( struct V_119 * V_120 , struct V_66 * V_67 ,
struct V_117 * V_118 )
{
int V_129 , V_130 ;
struct V_2 * V_3 ;
struct F_1 * V_30 = (struct F_1 * ) V_120 -> V_131 ;
V_130 = V_118 -> args [ 2 ] ;
F_57 ( & V_27 ) ;
for( V_3 = V_30 -> V_35 , V_129 = 0 ; V_3 ; V_3 = V_3 -> V_34 , V_129 ++ ) {
if ( V_129 < V_130 )
continue;
if ( V_129 > V_130 )
memset ( & V_118 -> args [ 3 ] , 0 , sizeof( V_118 -> args ) - 3 * sizeof( V_118 -> args [ 0 ] ) ) ;
if ( F_55 ( V_67 , V_118 , V_120 , V_3 ) < 0 ) {
V_118 -> args [ 2 ] = V_129 ;
F_58 ( & V_27 ) ;
return - 1 ;
}
}
F_58 ( & V_27 ) ;
V_118 -> args [ 2 ] = V_129 ;
return V_67 -> V_104 ;
}
int F_59 ( struct V_66 * V_67 , struct V_117 * V_118 )
{
struct V_132 * V_132 = F_60 ( V_67 -> V_133 ) ;
unsigned int V_4 , V_128 ;
unsigned int V_134 = 0 , V_135 ;
struct V_119 * V_120 ;
struct V_136 * V_137 ;
int V_138 = 0 ;
if ( ! F_61 ( V_132 , & V_115 ) )
return 0 ;
if ( F_62 ( V_118 -> V_39 , 0 ) >= sizeof( struct V_36 ) &&
( (struct V_36 * ) F_38 ( V_118 -> V_39 ) ) -> V_83 & V_139 )
return F_63 ( V_67 , V_118 ) ;
V_128 = V_118 -> args [ 0 ] ;
V_135 = V_118 -> args [ 1 ] ;
for ( V_4 = V_128 ; V_4 < V_140 ; V_4 ++ , V_128 = 0 ) {
V_134 = 0 ;
F_64 (tb, node, &dn_fib_table_hash[h], hlist) {
if ( V_134 < V_135 )
goto V_17;
if ( V_138 )
memset ( & V_118 -> args [ 2 ] , 0 , sizeof( V_118 -> args ) -
2 * sizeof( V_118 -> args [ 0 ] ) ) ;
if ( V_120 -> V_141 ( V_120 , V_67 , V_118 ) < 0 )
goto V_142;
V_138 = 1 ;
V_17:
V_134 ++ ;
}
}
V_142:
V_118 -> args [ 1 ] = V_134 ;
V_118 -> args [ 0 ] = V_4 ;
return V_67 -> V_104 ;
}
static int F_65 ( struct V_119 * V_120 , struct V_36 * V_37 , struct V_40 * V_41 , struct V_38 * V_125 , struct V_107 * V_108 )
{
struct F_1 * V_30 = (struct F_1 * ) V_120 -> V_131 ;
struct V_9 * V_143 , * V_15 , * * V_16 , * * V_144 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
int V_31 = V_37 -> V_78 ;
int type = V_37 -> V_86 ;
T_2 V_1 ;
int V_109 ;
if ( V_31 > 16 )
return - V_58 ;
V_3 = V_30 -> V_33 [ V_31 ] ;
if ( ! V_3 && ! ( V_3 = F_21 ( V_30 , V_31 ) ) )
return - V_110 ;
F_66 ( V_1 ) ;
if ( V_41 -> V_145 ) {
T_4 V_7 ;
memcpy ( & V_7 , V_41 -> V_145 , 2 ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
if ( ( V_43 = F_67 ( V_37 , V_41 , V_125 , & V_109 ) ) == NULL )
return V_109 ;
if ( V_3 -> V_146 > ( V_3 -> V_24 << 2 ) &&
V_3 -> V_24 > V_147 &&
( V_31 == 16 || ( 1 << V_31 ) > V_3 -> V_24 ) )
F_11 ( V_3 ) ;
V_16 = F_6 ( V_1 , V_3 ) ;
F_68 (f, fp) {
if ( F_9 ( V_1 , V_15 -> V_20 ) )
break;
}
V_144 = NULL ;
if ( V_15 && ( V_15 -> V_122 & V_123 ) &&
F_8 ( V_15 -> V_20 , V_1 ) ) {
V_144 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_148;
}
F_69 (f, fp, key) {
if ( V_43 -> V_48 <= F_19 ( V_15 ) -> V_48 )
break;
}
if ( V_15 && F_8 ( V_15 -> V_20 , V_1 ) &&
V_43 -> V_48 == F_19 ( V_15 ) -> V_48 ) {
struct V_9 * * V_149 ;
V_109 = - V_150 ;
if ( V_125 -> V_151 & V_152 )
goto V_142;
if ( V_125 -> V_151 & V_153 ) {
V_144 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_154;
}
V_149 = V_16 ;
V_109 = - V_150 ;
F_69 (f, fp, key) {
if ( V_43 -> V_48 != F_19 ( V_15 ) -> V_48 )
break;
if ( V_15 -> V_113 == type &&
V_15 -> V_114 == V_37 -> V_85 &&
F_19 ( V_15 ) == V_43 )
goto V_142;
}
if ( ! ( V_125 -> V_151 & V_155 ) ) {
V_16 = V_149 ;
V_15 = * V_16 ;
}
}
V_148:
V_109 = - V_156 ;
if ( ! ( V_125 -> V_151 & V_157 ) )
goto V_142;
V_154:
V_109 = - V_110 ;
V_143 = F_70 ( V_29 , V_26 ) ;
if ( V_143 == NULL )
goto V_142;
V_143 -> V_20 = V_1 ;
V_143 -> V_113 = type ;
V_143 -> V_114 = V_37 -> V_85 ;
F_19 ( V_143 ) = V_43 ;
V_143 -> V_19 = V_15 ;
F_14 ( & V_27 ) ;
* V_16 = V_143 ;
F_15 ( & V_27 ) ;
V_3 -> V_146 ++ ;
if ( V_144 ) {
V_15 = * V_144 ;
F_14 ( & V_27 ) ;
* V_144 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( ! ( V_15 -> V_122 & V_123 ) )
F_47 ( V_158 , V_15 , V_31 , V_120 -> V_125 , V_125 , V_108 ) ;
if ( V_15 -> V_122 & V_159 )
F_71 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_146 -- ;
} else {
F_71 ( - 1 ) ;
}
F_47 ( V_124 , V_143 , V_31 , V_120 -> V_125 , V_125 , V_108 ) ;
return 0 ;
V_142:
F_18 ( V_43 ) ;
return V_109 ;
}
static int F_72 ( struct V_119 * V_120 , struct V_36 * V_37 , struct V_40 * V_41 , struct V_38 * V_125 , struct V_107 * V_108 )
{
struct F_1 * V_30 = (struct F_1 * ) V_120 -> V_131 ;
struct V_9 * * V_16 , * * V_144 , * V_15 ;
int V_31 = V_37 -> V_78 ;
struct V_2 * V_3 ;
T_2 V_1 ;
int V_160 ;
if ( V_31 > 16 )
return - V_58 ;
if ( ( V_3 = V_30 -> V_33 [ V_31 ] ) == NULL )
return - V_161 ;
F_66 ( V_1 ) ;
if ( V_41 -> V_145 ) {
T_4 V_7 ;
memcpy ( & V_7 , V_41 -> V_145 , 2 ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
V_16 = F_6 ( V_1 , V_3 ) ;
F_68 (f, fp) {
if ( F_8 ( V_15 -> V_20 , V_1 ) )
break;
if ( F_9 ( V_1 , V_15 -> V_20 ) )
return - V_161 ;
}
V_160 = 0 ;
V_144 = NULL ;
F_69 (f, fp, key) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_15 -> V_122 & V_123 )
return - V_161 ;
V_160 ++ ;
if ( V_144 == NULL &&
( ! V_37 -> V_86 || V_15 -> V_113 == V_37 -> V_86 ) &&
( V_37 -> V_85 == V_162 || V_15 -> V_114 == V_37 -> V_85 ) &&
( ! V_37 -> V_88 ||
V_43 -> V_89 == V_37 -> V_88 ) &&
F_24 ( V_37 , V_125 , V_41 , V_43 ) == 0 )
V_144 = V_16 ;
}
if ( V_144 ) {
V_15 = * V_144 ;
F_47 ( V_158 , V_15 , V_31 , V_120 -> V_125 , V_125 , V_108 ) ;
if ( V_160 != 1 ) {
F_14 ( & V_27 ) ;
* V_144 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( V_15 -> V_122 & V_159 )
F_71 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_146 -- ;
} else {
V_15 -> V_122 |= V_123 ;
if ( V_15 -> V_122 & V_159 ) {
V_15 -> V_122 &= ~ V_159 ;
F_71 ( - 1 ) ;
}
if ( ++ V_163 > 128 )
F_73 () ;
}
return 0 ;
}
return - V_161 ;
}
static inline int F_74 ( struct V_9 * * V_16 , int V_31 , struct F_1 * V_30 )
{
int V_164 = 0 ;
struct V_9 * V_15 ;
while( ( V_15 = * V_16 ) != NULL ) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_43 && ( ( V_15 -> V_122 & V_123 ) || ( V_43 -> V_84 & V_165 ) ) ) {
F_14 ( & V_27 ) ;
* V_16 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
F_17 ( V_15 ) ;
V_164 ++ ;
continue;
}
V_16 = & V_15 -> V_19 ;
}
return V_164 ;
}
static int F_75 ( struct V_119 * V_120 )
{
struct F_1 * V_30 = (struct F_1 * ) V_120 -> V_131 ;
struct V_2 * V_3 ;
int V_164 = 0 ;
V_163 = 0 ;
for( V_3 = V_30 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
int V_18 ;
int V_166 = 0 ;
for( V_18 = V_3 -> V_24 - 1 ; V_18 >= 0 ; V_18 -- )
V_166 += F_74 ( & V_3 -> V_10 [ V_18 ] , V_3 -> V_6 , V_30 ) ;
V_3 -> V_146 -= V_166 ;
V_164 += V_166 ;
}
return V_164 ;
}
static int F_76 ( struct V_119 * V_120 , const struct V_167 * V_168 , struct V_169 * V_170 )
{
int V_109 ;
struct V_2 * V_3 ;
struct F_1 * V_171 = (struct F_1 * ) V_120 -> V_131 ;
F_57 ( & V_27 ) ;
for( V_3 = V_171 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
struct V_9 * V_15 ;
T_2 V_8 = F_4 ( V_168 -> V_172 , V_3 ) ;
for( V_15 = F_7 ( V_8 , V_3 ) ; V_15 ; V_15 = V_15 -> V_19 ) {
if ( ! F_8 ( V_8 , V_15 -> V_20 ) ) {
if ( F_9 ( V_8 , V_15 -> V_20 ) )
break;
else
continue;
}
V_15 -> V_122 |= V_159 ;
if ( V_15 -> V_122 & V_123 )
continue;
if ( V_15 -> V_114 < V_168 -> V_173 )
continue;
V_109 = F_77 ( V_15 -> V_113 , F_19 ( V_15 ) , V_168 , V_170 ) ;
if ( V_109 == 0 ) {
V_170 -> type = V_15 -> V_113 ;
V_170 -> V_72 = V_15 -> V_114 ;
V_170 -> V_174 = V_3 -> V_6 ;
goto V_142;
}
if ( V_109 < 0 )
goto V_142;
}
}
V_109 = 1 ;
V_142:
F_58 ( & V_27 ) ;
return V_109 ;
}
struct V_119 * F_78 ( T_5 V_125 , int V_148 )
{
struct V_119 * V_171 ;
struct V_136 * V_137 ;
unsigned int V_4 ;
if ( V_125 < V_175 )
return NULL ;
if ( V_125 > V_176 )
return NULL ;
V_4 = V_125 & ( V_140 - 1 ) ;
F_79 () ;
F_80 (t, node, &dn_fib_table_hash[h], hlist) {
if ( V_171 -> V_125 == V_125 ) {
F_81 () ;
return V_171 ;
}
}
F_81 () ;
if ( ! V_148 )
return NULL ;
if ( F_82 () && F_83 () ) {
F_12 ( V_25 L_2 ) ;
return NULL ;
}
V_171 = F_22 ( sizeof( struct V_119 ) + sizeof( struct F_1 ) ,
V_26 ) ;
if ( V_171 == NULL )
return NULL ;
V_171 -> V_125 = V_125 ;
V_171 -> V_177 = F_65 ;
V_171 -> V_178 = F_72 ;
V_171 -> V_179 = F_76 ;
V_171 -> V_180 = F_75 ;
V_171 -> V_141 = F_56 ;
F_84 ( & V_171 -> V_181 , & V_182 [ V_4 ] ) ;
return V_171 ;
}
struct V_119 * F_85 ( void )
{
T_5 V_183 ;
for( V_183 = V_175 ; V_183 <= V_176 ; V_183 ++ )
if ( F_78 ( V_183 , 0 ) == NULL )
return F_78 ( V_183 , 1 ) ;
return NULL ;
}
void F_73 ( void )
{
int V_184 = 0 ;
struct V_119 * V_120 ;
struct V_136 * V_137 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_140 ; V_4 ++ ) {
F_64 (tb, node, &dn_fib_table_hash[h], hlist)
V_184 += V_120 -> V_180 ( V_120 ) ;
}
if ( V_184 )
F_71 ( - 1 ) ;
}
void T_9 F_86 ( void )
{
V_29 = F_87 ( L_3 ,
sizeof( struct V_42 ) ,
0 , V_185 ,
NULL ) ;
}
void T_10 F_88 ( void )
{
struct V_119 * V_171 ;
struct V_136 * V_137 , * V_17 ;
unsigned int V_4 ;
F_89 ( & V_27 ) ;
for ( V_4 = 0 ; V_4 < V_140 ; V_4 ++ ) {
F_90 (t, node, next, &dn_fib_table_hash[h],
hlist) {
F_91 ( & V_171 -> V_181 ) ;
F_16 ( V_171 ) ;
}
}
F_92 ( & V_27 ) ;
}
