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
switch ( V_14 ) {
case 16 :
V_22 = 256 ;
V_23 = 0xFF ;
break;
default:
F_12 ( V_25 L_1 ,
V_14 ) ;
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
V_39 = F_36 ( V_67 , V_68 , V_69 , V_70 , sizeof( * V_75 ) , V_74 ) ;
if ( ! V_39 )
return - V_76 ;
V_75 = F_37 ( V_39 ) ;
V_75 -> V_77 = V_78 ;
V_75 -> V_79 = V_73 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 = V_71 ;
V_75 -> V_83 = V_43 -> V_84 ;
V_75 -> V_85 = V_72 ;
V_75 -> V_86 = type ;
V_75 -> V_87 = V_43 -> V_88 ;
if ( F_38 ( V_67 , V_89 , V_71 ) < 0 )
goto V_90;
if ( V_75 -> V_79 &&
F_39 ( V_67 , V_91 , 2 , V_7 ) < 0 )
goto V_90;
if ( V_43 -> V_48 &&
F_38 ( V_67 , V_92 , V_43 -> V_48 ) < 0 )
goto V_90;
if ( F_40 ( V_67 , V_43 -> V_93 ) < 0 )
goto V_90;
if ( V_43 -> V_64 == 1 ) {
if ( V_43 -> V_51 -> V_53 &&
F_41 ( V_67 , V_61 , V_43 -> V_51 -> V_53 ) < 0 )
goto V_90;
if ( V_43 -> V_51 -> V_52 &&
F_38 ( V_67 , V_94 , V_43 -> V_51 -> V_52 ) < 0 )
goto V_90;
}
if ( V_43 -> V_64 > 1 ) {
struct V_44 * V_45 ;
struct V_95 * V_96 ;
if ( ! ( V_96 = F_42 ( V_67 , V_97 ) ) )
goto V_90;
F_27 (fi) {
if ( ! ( V_45 = F_43 ( V_67 , sizeof( * V_45 ) ) ) )
goto V_90;
V_45 -> V_98 = V_60 -> V_99 & 0xFF ;
V_45 -> V_100 = V_60 -> V_101 - 1 ;
V_45 -> V_59 = V_60 -> V_52 ;
if ( V_60 -> V_53 &&
F_41 ( V_67 , V_61 , V_60 -> V_53 ) < 0 )
goto V_90;
V_45 -> V_57 = F_44 ( V_67 ) - ( unsigned char * ) V_45 ;
} F_31 ( V_43 ) ;
F_45 ( V_67 , V_96 ) ;
}
return F_46 ( V_67 , V_39 ) ;
V_90:
F_47 ( V_67 , V_39 ) ;
return - V_76 ;
}
static void F_48 ( int V_70 , struct V_9 * V_15 , int V_31 , T_5 V_71 ,
struct V_38 * V_39 , struct V_102 * V_103 )
{
struct V_66 * V_67 ;
T_5 V_68 = V_103 ? V_103 -> V_68 : 0 ;
int V_104 = - V_105 ;
V_67 = F_49 ( F_32 ( F_19 ( V_15 ) ) , V_26 ) ;
if ( V_67 == NULL )
goto V_90;
V_104 = F_35 ( V_67 , V_68 , V_39 -> V_106 , V_70 , V_71 ,
V_15 -> V_107 , V_15 -> V_108 , & V_15 -> V_20 , V_31 ,
F_19 ( V_15 ) , 0 ) ;
if ( V_104 < 0 ) {
F_50 ( V_104 == - V_76 ) ;
F_51 ( V_67 ) ;
goto V_90;
}
F_52 ( V_67 , & V_109 , V_68 , V_110 , V_39 , V_26 ) ;
return;
V_90:
if ( V_104 < 0 )
F_53 ( & V_109 , V_110 , V_104 ) ;
}
static T_8 int F_54 ( struct V_66 * V_67 ,
struct V_111 * V_112 ,
struct V_113 * V_114 ,
struct V_2 * V_3 ,
struct V_9 * V_15 )
{
int V_18 , V_115 ;
V_115 = V_112 -> args [ 4 ] ;
for( V_18 = 0 ; V_15 ; V_18 ++ , V_15 = V_15 -> V_19 ) {
if ( V_18 < V_115 )
continue;
if ( V_15 -> V_116 & V_117 )
continue;
if ( F_35 ( V_67 , F_55 ( V_112 -> V_67 ) . V_68 ,
V_112 -> V_39 -> V_106 ,
V_118 ,
V_114 -> V_119 ,
( V_15 -> V_116 & V_117 ) ? 0 : V_15 -> V_107 ,
V_15 -> V_108 , & V_15 -> V_20 , V_3 -> V_6 ,
V_15 -> V_120 , V_121 ) < 0 ) {
V_112 -> args [ 4 ] = V_18 ;
return - 1 ;
}
}
V_112 -> args [ 4 ] = V_18 ;
return V_67 -> V_122 ;
}
static T_8 int F_56 ( struct V_66 * V_67 ,
struct V_111 * V_112 ,
struct V_113 * V_114 ,
struct V_2 * V_3 )
{
int V_4 , V_123 ;
V_123 = V_112 -> args [ 3 ] ;
for( V_4 = 0 ; V_4 < V_3 -> V_24 ; V_4 ++ ) {
if ( V_4 < V_123 )
continue;
if ( V_4 > V_123 )
memset ( & V_112 -> args [ 4 ] , 0 , sizeof( V_112 -> args ) - 4 * sizeof( V_112 -> args [ 0 ] ) ) ;
if ( V_3 -> V_10 == NULL || V_3 -> V_10 [ V_4 ] == NULL )
continue;
if ( F_54 ( V_67 , V_112 , V_114 , V_3 , V_3 -> V_10 [ V_4 ] ) < 0 ) {
V_112 -> args [ 3 ] = V_4 ;
return - 1 ;
}
}
V_112 -> args [ 3 ] = V_4 ;
return V_67 -> V_122 ;
}
static int F_57 ( struct V_113 * V_114 , struct V_66 * V_67 ,
struct V_111 * V_112 )
{
int V_124 , V_125 ;
struct V_2 * V_3 ;
struct F_1 * V_30 = (struct F_1 * ) V_114 -> V_126 ;
V_125 = V_112 -> args [ 2 ] ;
F_58 ( & V_27 ) ;
for( V_3 = V_30 -> V_35 , V_124 = 0 ; V_3 ; V_3 = V_3 -> V_34 , V_124 ++ ) {
if ( V_124 < V_125 )
continue;
if ( V_124 > V_125 )
memset ( & V_112 -> args [ 3 ] , 0 , sizeof( V_112 -> args ) - 3 * sizeof( V_112 -> args [ 0 ] ) ) ;
if ( F_56 ( V_67 , V_112 , V_114 , V_3 ) < 0 ) {
V_112 -> args [ 2 ] = V_124 ;
F_59 ( & V_27 ) ;
return - 1 ;
}
}
F_59 ( & V_27 ) ;
V_112 -> args [ 2 ] = V_124 ;
return V_67 -> V_122 ;
}
int F_60 ( struct V_66 * V_67 , struct V_111 * V_112 )
{
struct V_127 * V_127 = F_61 ( V_67 -> V_128 ) ;
unsigned int V_4 , V_123 ;
unsigned int V_129 = 0 , V_130 ;
struct V_113 * V_114 ;
struct V_131 * V_132 ;
int V_133 = 0 ;
if ( ! F_62 ( V_127 , & V_109 ) )
return 0 ;
if ( F_63 ( V_112 -> V_39 , 0 ) >= sizeof( struct V_36 ) &&
( (struct V_36 * ) F_37 ( V_112 -> V_39 ) ) -> V_83 & V_134 )
return F_64 ( V_67 , V_112 ) ;
V_123 = V_112 -> args [ 0 ] ;
V_130 = V_112 -> args [ 1 ] ;
for ( V_4 = V_123 ; V_4 < V_135 ; V_4 ++ , V_123 = 0 ) {
V_129 = 0 ;
F_65 (tb, node, &dn_fib_table_hash[h], hlist) {
if ( V_129 < V_130 )
goto V_17;
if ( V_133 )
memset ( & V_112 -> args [ 2 ] , 0 , sizeof( V_112 -> args ) -
2 * sizeof( V_112 -> args [ 0 ] ) ) ;
if ( V_114 -> V_136 ( V_114 , V_67 , V_112 ) < 0 )
goto V_137;
V_133 = 1 ;
V_17:
V_129 ++ ;
}
}
V_137:
V_112 -> args [ 1 ] = V_129 ;
V_112 -> args [ 0 ] = V_4 ;
return V_67 -> V_122 ;
}
static int F_66 ( struct V_113 * V_114 , struct V_36 * V_37 , struct V_40 * V_41 , struct V_38 * V_119 , struct V_102 * V_103 )
{
struct F_1 * V_30 = (struct F_1 * ) V_114 -> V_126 ;
struct V_9 * V_138 , * V_15 , * * V_16 , * * V_139 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
int V_31 = V_37 -> V_79 ;
int type = V_37 -> V_86 ;
T_2 V_1 ;
int V_104 ;
if ( V_31 > 16 )
return - V_58 ;
V_3 = V_30 -> V_33 [ V_31 ] ;
if ( ! V_3 && ! ( V_3 = F_21 ( V_30 , V_31 ) ) )
return - V_105 ;
F_67 ( V_1 ) ;
if ( V_41 -> V_140 ) {
T_4 V_7 ;
memcpy ( & V_7 , V_41 -> V_140 , 2 ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
if ( ( V_43 = F_68 ( V_37 , V_41 , V_119 , & V_104 ) ) == NULL )
return V_104 ;
if ( V_3 -> V_141 > ( V_3 -> V_24 << 2 ) &&
V_3 -> V_24 > V_142 &&
( V_31 == 16 || ( 1 << V_31 ) > V_3 -> V_24 ) )
F_11 ( V_3 ) ;
V_16 = F_6 ( V_1 , V_3 ) ;
F_69 (f, fp) {
if ( F_9 ( V_1 , V_15 -> V_20 ) )
break;
}
V_139 = NULL ;
if ( V_15 && ( V_15 -> V_116 & V_117 ) &&
F_8 ( V_15 -> V_20 , V_1 ) ) {
V_139 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_143;
}
F_70 (f, fp, key) {
if ( V_43 -> V_48 <= F_19 ( V_15 ) -> V_48 )
break;
}
if ( V_15 && F_8 ( V_15 -> V_20 , V_1 ) &&
V_43 -> V_48 == F_19 ( V_15 ) -> V_48 ) {
struct V_9 * * V_144 ;
V_104 = - V_145 ;
if ( V_119 -> V_146 & V_147 )
goto V_137;
if ( V_119 -> V_146 & V_148 ) {
V_139 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_149;
}
V_144 = V_16 ;
V_104 = - V_145 ;
F_70 (f, fp, key) {
if ( V_43 -> V_48 != F_19 ( V_15 ) -> V_48 )
break;
if ( V_15 -> V_107 == type &&
V_15 -> V_108 == V_37 -> V_85 &&
F_19 ( V_15 ) == V_43 )
goto V_137;
}
if ( ! ( V_119 -> V_146 & V_150 ) ) {
V_16 = V_144 ;
V_15 = * V_16 ;
}
}
V_143:
V_104 = - V_151 ;
if ( ! ( V_119 -> V_146 & V_152 ) )
goto V_137;
V_149:
V_104 = - V_105 ;
V_138 = F_71 ( V_29 , V_26 ) ;
if ( V_138 == NULL )
goto V_137;
V_138 -> V_20 = V_1 ;
V_138 -> V_107 = type ;
V_138 -> V_108 = V_37 -> V_85 ;
F_19 ( V_138 ) = V_43 ;
V_138 -> V_19 = V_15 ;
F_14 ( & V_27 ) ;
* V_16 = V_138 ;
F_15 ( & V_27 ) ;
V_3 -> V_141 ++ ;
if ( V_139 ) {
V_15 = * V_139 ;
F_14 ( & V_27 ) ;
* V_139 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( ! ( V_15 -> V_116 & V_117 ) )
F_48 ( V_153 , V_15 , V_31 , V_114 -> V_119 , V_119 , V_103 ) ;
if ( V_15 -> V_116 & V_154 )
F_72 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_141 -- ;
} else {
F_72 ( - 1 ) ;
}
F_48 ( V_118 , V_138 , V_31 , V_114 -> V_119 , V_119 , V_103 ) ;
return 0 ;
V_137:
F_18 ( V_43 ) ;
return V_104 ;
}
static int F_73 ( struct V_113 * V_114 , struct V_36 * V_37 , struct V_40 * V_41 , struct V_38 * V_119 , struct V_102 * V_103 )
{
struct F_1 * V_30 = (struct F_1 * ) V_114 -> V_126 ;
struct V_9 * * V_16 , * * V_139 , * V_15 ;
int V_31 = V_37 -> V_79 ;
struct V_2 * V_3 ;
T_2 V_1 ;
int V_155 ;
if ( V_31 > 16 )
return - V_58 ;
if ( ( V_3 = V_30 -> V_33 [ V_31 ] ) == NULL )
return - V_156 ;
F_67 ( V_1 ) ;
if ( V_41 -> V_140 ) {
T_4 V_7 ;
memcpy ( & V_7 , V_41 -> V_140 , 2 ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
V_16 = F_6 ( V_1 , V_3 ) ;
F_69 (f, fp) {
if ( F_8 ( V_15 -> V_20 , V_1 ) )
break;
if ( F_9 ( V_1 , V_15 -> V_20 ) )
return - V_156 ;
}
V_155 = 0 ;
V_139 = NULL ;
F_70 (f, fp, key) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_15 -> V_116 & V_117 )
return - V_156 ;
V_155 ++ ;
if ( V_139 == NULL &&
( ! V_37 -> V_86 || V_15 -> V_107 == V_37 -> V_86 ) &&
( V_37 -> V_85 == V_157 || V_15 -> V_108 == V_37 -> V_85 ) &&
( ! V_37 -> V_87 ||
V_43 -> V_88 == V_37 -> V_87 ) &&
F_24 ( V_37 , V_119 , V_41 , V_43 ) == 0 )
V_139 = V_16 ;
}
if ( V_139 ) {
V_15 = * V_139 ;
F_48 ( V_153 , V_15 , V_31 , V_114 -> V_119 , V_119 , V_103 ) ;
if ( V_155 != 1 ) {
F_14 ( & V_27 ) ;
* V_139 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( V_15 -> V_116 & V_154 )
F_72 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_141 -- ;
} else {
V_15 -> V_116 |= V_117 ;
if ( V_15 -> V_116 & V_154 ) {
V_15 -> V_116 &= ~ V_154 ;
F_72 ( - 1 ) ;
}
if ( ++ V_158 > 128 )
F_74 () ;
}
return 0 ;
}
return - V_156 ;
}
static inline int F_75 ( struct V_9 * * V_16 , int V_31 , struct F_1 * V_30 )
{
int V_159 = 0 ;
struct V_9 * V_15 ;
while( ( V_15 = * V_16 ) != NULL ) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_43 && ( ( V_15 -> V_116 & V_117 ) || ( V_43 -> V_84 & V_160 ) ) ) {
F_14 ( & V_27 ) ;
* V_16 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
F_17 ( V_15 ) ;
V_159 ++ ;
continue;
}
V_16 = & V_15 -> V_19 ;
}
return V_159 ;
}
static int F_76 ( struct V_113 * V_114 )
{
struct F_1 * V_30 = (struct F_1 * ) V_114 -> V_126 ;
struct V_2 * V_3 ;
int V_159 = 0 ;
V_158 = 0 ;
for( V_3 = V_30 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
int V_18 ;
int V_161 = 0 ;
for( V_18 = V_3 -> V_24 - 1 ; V_18 >= 0 ; V_18 -- )
V_161 += F_75 ( & V_3 -> V_10 [ V_18 ] , V_3 -> V_6 , V_30 ) ;
V_3 -> V_141 -= V_161 ;
V_159 += V_161 ;
}
return V_159 ;
}
static int F_77 ( struct V_113 * V_114 , const struct V_162 * V_163 , struct V_164 * V_165 )
{
int V_104 ;
struct V_2 * V_3 ;
struct F_1 * V_166 = (struct F_1 * ) V_114 -> V_126 ;
F_58 ( & V_27 ) ;
for( V_3 = V_166 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
struct V_9 * V_15 ;
T_2 V_8 = F_4 ( V_163 -> V_167 , V_3 ) ;
for( V_15 = F_7 ( V_8 , V_3 ) ; V_15 ; V_15 = V_15 -> V_19 ) {
if ( ! F_8 ( V_8 , V_15 -> V_20 ) ) {
if ( F_9 ( V_8 , V_15 -> V_20 ) )
break;
else
continue;
}
V_15 -> V_116 |= V_154 ;
if ( V_15 -> V_116 & V_117 )
continue;
if ( V_15 -> V_108 < V_163 -> V_168 )
continue;
V_104 = F_78 ( V_15 -> V_107 , F_19 ( V_15 ) , V_163 , V_165 ) ;
if ( V_104 == 0 ) {
V_165 -> type = V_15 -> V_107 ;
V_165 -> V_72 = V_15 -> V_108 ;
V_165 -> V_169 = V_3 -> V_6 ;
goto V_137;
}
if ( V_104 < 0 )
goto V_137;
}
}
V_104 = 1 ;
V_137:
F_59 ( & V_27 ) ;
return V_104 ;
}
struct V_113 * F_79 ( T_5 V_119 , int V_143 )
{
struct V_113 * V_166 ;
struct V_131 * V_132 ;
unsigned int V_4 ;
if ( V_119 < V_170 )
return NULL ;
if ( V_119 > V_171 )
return NULL ;
V_4 = V_119 & ( V_135 - 1 ) ;
F_80 () ;
F_81 (t, node, &dn_fib_table_hash[h], hlist) {
if ( V_166 -> V_119 == V_119 ) {
F_82 () ;
return V_166 ;
}
}
F_82 () ;
if ( ! V_143 )
return NULL ;
if ( F_83 () ) {
F_84 ( L_2 ) ;
return NULL ;
}
V_166 = F_22 ( sizeof( struct V_113 ) + sizeof( struct F_1 ) ,
V_26 ) ;
if ( V_166 == NULL )
return NULL ;
V_166 -> V_119 = V_119 ;
V_166 -> V_172 = F_66 ;
V_166 -> V_173 = F_73 ;
V_166 -> V_174 = F_77 ;
V_166 -> V_175 = F_76 ;
V_166 -> V_136 = F_57 ;
F_85 ( & V_166 -> V_176 , & V_177 [ V_4 ] ) ;
return V_166 ;
}
struct V_113 * F_86 ( void )
{
T_5 V_178 ;
for( V_178 = V_170 ; V_178 <= V_171 ; V_178 ++ )
if ( F_79 ( V_178 , 0 ) == NULL )
return F_79 ( V_178 , 1 ) ;
return NULL ;
}
void F_74 ( void )
{
int V_179 = 0 ;
struct V_113 * V_114 ;
struct V_131 * V_132 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_135 ; V_4 ++ ) {
F_65 (tb, node, &dn_fib_table_hash[h], hlist)
V_179 += V_114 -> V_175 ( V_114 ) ;
}
if ( V_179 )
F_72 ( - 1 ) ;
}
void T_9 F_87 ( void )
{
V_29 = F_88 ( L_3 ,
sizeof( struct V_42 ) ,
0 , V_180 ,
NULL ) ;
}
void T_10 F_89 ( void )
{
struct V_113 * V_166 ;
struct V_131 * V_132 , * V_17 ;
unsigned int V_4 ;
F_90 ( & V_27 ) ;
for ( V_4 = 0 ; V_4 < V_135 ; V_4 ++ ) {
F_91 (t, node, next, &dn_fib_table_hash[h],
hlist) {
F_92 ( & V_166 -> V_176 ) ;
F_16 ( V_166 ) ;
}
}
F_93 ( & V_27 ) ;
}
