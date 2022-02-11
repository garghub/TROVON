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
static int F_24 ( struct V_36 * V_37 , struct V_38 * V_39 , struct V_40 * V_41 [] , struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
if ( V_41 [ V_47 ] &&
F_25 ( V_41 [ V_47 ] ) != V_43 -> V_48 )
return 1 ;
if ( V_41 [ V_49 ] || V_41 [ V_50 ] ) {
if ( ( ! V_41 [ V_49 ] || F_25 ( V_41 [ V_49 ] ) == V_43 -> V_51 -> V_52 ) &&
( ! V_41 [ V_50 ] || F_26 ( V_41 [ V_50 ] ) != V_43 -> V_51 -> V_53 ) )
return 0 ;
return 1 ;
}
if ( ! V_41 [ V_54 ] )
return 0 ;
V_45 = F_27 ( V_41 [ V_54 ] ) ;
V_46 = F_28 ( V_41 [ V_54 ] ) ;
F_29 (fi) {
int V_55 = V_46 - sizeof( struct V_44 ) ;
T_4 V_56 ;
if ( V_55 < 0 || ( V_46 -= V_45 -> V_57 ) < 0 )
return - V_58 ;
if ( V_45 -> V_59 && V_45 -> V_59 != V_60 -> V_52 )
return 1 ;
if ( V_55 ) {
struct V_40 * V_61 ;
V_61 = F_30 ( (struct V_40 * ) ( V_45 + 1 ) , V_55 , V_50 ) ;
V_56 = V_61 ? F_26 ( V_61 ) : 0 ;
if ( V_56 && V_56 != V_60 -> V_53 )
return 1 ;
}
V_45 = F_31 ( V_45 ) ;
} F_32 ( V_43 ) ;
return 0 ;
}
static inline T_6 F_33 ( struct V_42 * V_43 )
{
T_6 V_62 = F_34 ( sizeof( struct V_36 ) )
+ F_35 ( 4 )
+ F_35 ( 2 )
+ F_35 ( 4 )
+ F_35 ( V_63 ) ;
V_62 += F_35 ( ( V_64 * F_35 ( 4 ) ) ) ;
if ( V_43 -> V_65 ) {
T_6 V_66 = F_35 ( sizeof( struct V_44 ) ) ;
V_66 += F_35 ( 4 ) ;
V_62 += F_35 ( V_43 -> V_65 * V_66 ) ;
}
return V_62 ;
}
static int F_36 ( struct V_67 * V_68 , T_5 V_69 , T_5 V_70 , int V_71 ,
T_5 V_72 , T_7 type , T_7 V_73 , void * V_7 , int V_74 ,
struct V_42 * V_43 , unsigned int V_75 )
{
struct V_36 * V_76 ;
struct V_38 * V_39 ;
V_39 = F_37 ( V_68 , V_69 , V_70 , V_71 , sizeof( * V_76 ) , V_75 ) ;
if ( ! V_39 )
return - V_77 ;
V_76 = F_38 ( V_39 ) ;
V_76 -> V_78 = V_79 ;
V_76 -> V_80 = V_74 ;
V_76 -> V_81 = 0 ;
V_76 -> V_82 = 0 ;
V_76 -> V_83 = V_72 ;
V_76 -> V_84 = V_43 -> V_85 ;
V_76 -> V_86 = V_73 ;
V_76 -> V_87 = type ;
V_76 -> V_88 = V_43 -> V_89 ;
if ( F_39 ( V_68 , V_90 , V_72 ) < 0 )
goto V_91;
if ( V_76 -> V_80 &&
F_40 ( V_68 , V_92 , 2 , V_7 ) < 0 )
goto V_91;
if ( V_43 -> V_48 &&
F_39 ( V_68 , V_47 , V_43 -> V_48 ) < 0 )
goto V_91;
if ( F_41 ( V_68 , V_43 -> V_93 ) < 0 )
goto V_91;
if ( V_43 -> V_65 == 1 ) {
if ( V_43 -> V_51 -> V_53 &&
F_42 ( V_68 , V_50 , V_43 -> V_51 -> V_53 ) < 0 )
goto V_91;
if ( V_43 -> V_51 -> V_52 &&
F_39 ( V_68 , V_49 , V_43 -> V_51 -> V_52 ) < 0 )
goto V_91;
}
if ( V_43 -> V_65 > 1 ) {
struct V_44 * V_45 ;
struct V_40 * V_94 ;
if ( ! ( V_94 = F_43 ( V_68 , V_54 ) ) )
goto V_91;
F_29 (fi) {
if ( ! ( V_45 = F_44 ( V_68 , sizeof( * V_45 ) ) ) )
goto V_91;
V_45 -> V_95 = V_60 -> V_96 & 0xFF ;
V_45 -> V_97 = V_60 -> V_98 - 1 ;
V_45 -> V_59 = V_60 -> V_52 ;
if ( V_60 -> V_53 &&
F_42 ( V_68 , V_50 , V_60 -> V_53 ) < 0 )
goto V_91;
V_45 -> V_57 = F_45 ( V_68 ) - ( unsigned char * ) V_45 ;
} F_32 ( V_43 ) ;
F_46 ( V_68 , V_94 ) ;
}
F_47 ( V_68 , V_39 ) ;
return 0 ;
V_91:
F_48 ( V_68 , V_39 ) ;
return - V_77 ;
}
static void F_49 ( int V_71 , struct V_9 * V_15 , int V_31 , T_5 V_72 ,
struct V_38 * V_39 , struct V_99 * V_100 )
{
struct V_67 * V_68 ;
T_5 V_69 = V_100 ? V_100 -> V_69 : 0 ;
int V_101 = - V_102 ;
V_68 = F_50 ( F_33 ( F_19 ( V_15 ) ) , V_26 ) ;
if ( V_68 == NULL )
goto V_91;
V_101 = F_36 ( V_68 , V_69 , V_39 -> V_103 , V_71 , V_72 ,
V_15 -> V_104 , V_15 -> V_105 , & V_15 -> V_20 , V_31 ,
F_19 ( V_15 ) , 0 ) ;
if ( V_101 < 0 ) {
F_51 ( V_101 == - V_77 ) ;
F_52 ( V_68 ) ;
goto V_91;
}
F_53 ( V_68 , & V_106 , V_69 , V_107 , V_39 , V_26 ) ;
return;
V_91:
if ( V_101 < 0 )
F_54 ( & V_106 , V_107 , V_101 ) ;
}
static T_8 int F_55 ( struct V_67 * V_68 ,
struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_2 * V_3 ,
struct V_9 * V_15 )
{
int V_18 , V_112 ;
V_112 = V_109 -> args [ 4 ] ;
for( V_18 = 0 ; V_15 ; V_18 ++ , V_15 = V_15 -> V_19 ) {
if ( V_18 < V_112 )
continue;
if ( V_15 -> V_113 & V_114 )
continue;
if ( F_36 ( V_68 , F_56 ( V_109 -> V_68 ) . V_69 ,
V_109 -> V_39 -> V_103 ,
V_115 ,
V_111 -> V_116 ,
( V_15 -> V_113 & V_114 ) ? 0 : V_15 -> V_104 ,
V_15 -> V_105 , & V_15 -> V_20 , V_3 -> V_6 ,
V_15 -> V_117 , V_118 ) < 0 ) {
V_109 -> args [ 4 ] = V_18 ;
return - 1 ;
}
}
V_109 -> args [ 4 ] = V_18 ;
return V_68 -> V_119 ;
}
static T_8 int F_57 ( struct V_67 * V_68 ,
struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_2 * V_3 )
{
int V_4 , V_120 ;
V_120 = V_109 -> args [ 3 ] ;
for( V_4 = 0 ; V_4 < V_3 -> V_24 ; V_4 ++ ) {
if ( V_4 < V_120 )
continue;
if ( V_4 > V_120 )
memset ( & V_109 -> args [ 4 ] , 0 , sizeof( V_109 -> args ) - 4 * sizeof( V_109 -> args [ 0 ] ) ) ;
if ( V_3 -> V_10 == NULL || V_3 -> V_10 [ V_4 ] == NULL )
continue;
if ( F_55 ( V_68 , V_109 , V_111 , V_3 , V_3 -> V_10 [ V_4 ] ) < 0 ) {
V_109 -> args [ 3 ] = V_4 ;
return - 1 ;
}
}
V_109 -> args [ 3 ] = V_4 ;
return V_68 -> V_119 ;
}
static int F_58 ( struct V_110 * V_111 , struct V_67 * V_68 ,
struct V_108 * V_109 )
{
int V_121 , V_122 ;
struct V_2 * V_3 ;
struct F_1 * V_30 = (struct F_1 * ) V_111 -> V_123 ;
V_122 = V_109 -> args [ 2 ] ;
F_59 ( & V_27 ) ;
for( V_3 = V_30 -> V_35 , V_121 = 0 ; V_3 ; V_3 = V_3 -> V_34 , V_121 ++ ) {
if ( V_121 < V_122 )
continue;
if ( V_121 > V_122 )
memset ( & V_109 -> args [ 3 ] , 0 , sizeof( V_109 -> args ) - 3 * sizeof( V_109 -> args [ 0 ] ) ) ;
if ( F_57 ( V_68 , V_109 , V_111 , V_3 ) < 0 ) {
V_109 -> args [ 2 ] = V_121 ;
F_60 ( & V_27 ) ;
return - 1 ;
}
}
F_60 ( & V_27 ) ;
V_109 -> args [ 2 ] = V_121 ;
return V_68 -> V_119 ;
}
int F_61 ( struct V_67 * V_68 , struct V_108 * V_109 )
{
struct V_124 * V_124 = F_62 ( V_68 -> V_125 ) ;
unsigned int V_4 , V_120 ;
unsigned int V_126 = 0 , V_127 ;
struct V_110 * V_111 ;
int V_128 = 0 ;
if ( ! F_63 ( V_124 , & V_106 ) )
return 0 ;
if ( F_64 ( V_109 -> V_39 ) >= sizeof( struct V_36 ) &&
( (struct V_36 * ) F_38 ( V_109 -> V_39 ) ) -> V_84 & V_129 )
return F_65 ( V_68 , V_109 ) ;
V_120 = V_109 -> args [ 0 ] ;
V_127 = V_109 -> args [ 1 ] ;
for ( V_4 = V_120 ; V_4 < V_130 ; V_4 ++ , V_120 = 0 ) {
V_126 = 0 ;
F_66 (tb, &dn_fib_table_hash[h], hlist) {
if ( V_126 < V_127 )
goto V_17;
if ( V_128 )
memset ( & V_109 -> args [ 2 ] , 0 , sizeof( V_109 -> args ) -
2 * sizeof( V_109 -> args [ 0 ] ) ) ;
if ( V_111 -> V_131 ( V_111 , V_68 , V_109 ) < 0 )
goto V_132;
V_128 = 1 ;
V_17:
V_126 ++ ;
}
}
V_132:
V_109 -> args [ 1 ] = V_126 ;
V_109 -> args [ 0 ] = V_4 ;
return V_68 -> V_119 ;
}
static int F_67 ( struct V_110 * V_111 , struct V_36 * V_37 , struct V_40 * V_41 [] ,
struct V_38 * V_116 , struct V_99 * V_100 )
{
struct F_1 * V_30 = (struct F_1 * ) V_111 -> V_123 ;
struct V_9 * V_133 , * V_15 , * * V_16 , * * V_134 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
int V_31 = V_37 -> V_80 ;
int type = V_37 -> V_87 ;
T_2 V_1 ;
int V_101 ;
if ( V_31 > 16 )
return - V_58 ;
V_3 = V_30 -> V_33 [ V_31 ] ;
if ( ! V_3 && ! ( V_3 = F_21 ( V_30 , V_31 ) ) )
return - V_102 ;
F_68 ( V_1 ) ;
if ( V_41 [ V_92 ] ) {
T_4 V_7 = F_26 ( V_41 [ V_92 ] ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
if ( ( V_43 = F_69 ( V_37 , V_41 , V_116 , & V_101 ) ) == NULL )
return V_101 ;
if ( V_3 -> V_135 > ( V_3 -> V_24 << 2 ) &&
V_3 -> V_24 > V_136 &&
( V_31 == 16 || ( 1 << V_31 ) > V_3 -> V_24 ) )
F_11 ( V_3 ) ;
V_16 = F_6 ( V_1 , V_3 ) ;
F_70 (f, fp) {
if ( F_9 ( V_1 , V_15 -> V_20 ) )
break;
}
V_134 = NULL ;
if ( V_15 && ( V_15 -> V_113 & V_114 ) &&
F_8 ( V_15 -> V_20 , V_1 ) ) {
V_134 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_137;
}
F_71 (f, fp, key) {
if ( V_43 -> V_48 <= F_19 ( V_15 ) -> V_48 )
break;
}
if ( V_15 && F_8 ( V_15 -> V_20 , V_1 ) &&
V_43 -> V_48 == F_19 ( V_15 ) -> V_48 ) {
struct V_9 * * V_138 ;
V_101 = - V_139 ;
if ( V_116 -> V_140 & V_141 )
goto V_132;
if ( V_116 -> V_140 & V_142 ) {
V_134 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_143;
}
V_138 = V_16 ;
V_101 = - V_139 ;
F_71 (f, fp, key) {
if ( V_43 -> V_48 != F_19 ( V_15 ) -> V_48 )
break;
if ( V_15 -> V_104 == type &&
V_15 -> V_105 == V_37 -> V_86 &&
F_19 ( V_15 ) == V_43 )
goto V_132;
}
if ( ! ( V_116 -> V_140 & V_144 ) ) {
V_16 = V_138 ;
V_15 = * V_16 ;
}
}
V_137:
V_101 = - V_145 ;
if ( ! ( V_116 -> V_140 & V_146 ) )
goto V_132;
V_143:
V_101 = - V_102 ;
V_133 = F_72 ( V_29 , V_26 ) ;
if ( V_133 == NULL )
goto V_132;
V_133 -> V_20 = V_1 ;
V_133 -> V_104 = type ;
V_133 -> V_105 = V_37 -> V_86 ;
F_19 ( V_133 ) = V_43 ;
V_133 -> V_19 = V_15 ;
F_14 ( & V_27 ) ;
* V_16 = V_133 ;
F_15 ( & V_27 ) ;
V_3 -> V_135 ++ ;
if ( V_134 ) {
V_15 = * V_134 ;
F_14 ( & V_27 ) ;
* V_134 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( ! ( V_15 -> V_113 & V_114 ) )
F_49 ( V_147 , V_15 , V_31 , V_111 -> V_116 , V_116 , V_100 ) ;
if ( V_15 -> V_113 & V_148 )
F_73 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_135 -- ;
} else {
F_73 ( - 1 ) ;
}
F_49 ( V_115 , V_133 , V_31 , V_111 -> V_116 , V_116 , V_100 ) ;
return 0 ;
V_132:
F_18 ( V_43 ) ;
return V_101 ;
}
static int F_74 ( struct V_110 * V_111 , struct V_36 * V_37 , struct V_40 * V_41 [] ,
struct V_38 * V_116 , struct V_99 * V_100 )
{
struct F_1 * V_30 = (struct F_1 * ) V_111 -> V_123 ;
struct V_9 * * V_16 , * * V_134 , * V_15 ;
int V_31 = V_37 -> V_80 ;
struct V_2 * V_3 ;
T_2 V_1 ;
int V_149 ;
if ( V_31 > 16 )
return - V_58 ;
if ( ( V_3 = V_30 -> V_33 [ V_31 ] ) == NULL )
return - V_150 ;
F_68 ( V_1 ) ;
if ( V_41 [ V_92 ] ) {
T_4 V_7 = F_26 ( V_41 [ V_92 ] ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
V_16 = F_6 ( V_1 , V_3 ) ;
F_70 (f, fp) {
if ( F_8 ( V_15 -> V_20 , V_1 ) )
break;
if ( F_9 ( V_1 , V_15 -> V_20 ) )
return - V_150 ;
}
V_149 = 0 ;
V_134 = NULL ;
F_71 (f, fp, key) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_15 -> V_113 & V_114 )
return - V_150 ;
V_149 ++ ;
if ( V_134 == NULL &&
( ! V_37 -> V_87 || V_15 -> V_104 == V_37 -> V_87 ) &&
( V_37 -> V_86 == V_151 || V_15 -> V_105 == V_37 -> V_86 ) &&
( ! V_37 -> V_88 ||
V_43 -> V_89 == V_37 -> V_88 ) &&
F_24 ( V_37 , V_116 , V_41 , V_43 ) == 0 )
V_134 = V_16 ;
}
if ( V_134 ) {
V_15 = * V_134 ;
F_49 ( V_147 , V_15 , V_31 , V_111 -> V_116 , V_116 , V_100 ) ;
if ( V_149 != 1 ) {
F_14 ( & V_27 ) ;
* V_134 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( V_15 -> V_113 & V_148 )
F_73 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_135 -- ;
} else {
V_15 -> V_113 |= V_114 ;
if ( V_15 -> V_113 & V_148 ) {
V_15 -> V_113 &= ~ V_148 ;
F_73 ( - 1 ) ;
}
if ( ++ V_152 > 128 )
F_75 () ;
}
return 0 ;
}
return - V_150 ;
}
static inline int F_76 ( struct V_9 * * V_16 , int V_31 , struct F_1 * V_30 )
{
int V_153 = 0 ;
struct V_9 * V_15 ;
while( ( V_15 = * V_16 ) != NULL ) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_43 && ( ( V_15 -> V_113 & V_114 ) || ( V_43 -> V_85 & V_154 ) ) ) {
F_14 ( & V_27 ) ;
* V_16 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
F_17 ( V_15 ) ;
V_153 ++ ;
continue;
}
V_16 = & V_15 -> V_19 ;
}
return V_153 ;
}
static int F_77 ( struct V_110 * V_111 )
{
struct F_1 * V_30 = (struct F_1 * ) V_111 -> V_123 ;
struct V_2 * V_3 ;
int V_153 = 0 ;
V_152 = 0 ;
for( V_3 = V_30 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
int V_18 ;
int V_155 = 0 ;
for( V_18 = V_3 -> V_24 - 1 ; V_18 >= 0 ; V_18 -- )
V_155 += F_76 ( & V_3 -> V_10 [ V_18 ] , V_3 -> V_6 , V_30 ) ;
V_3 -> V_135 -= V_155 ;
V_153 += V_155 ;
}
return V_153 ;
}
static int F_78 ( struct V_110 * V_111 , const struct V_156 * V_157 , struct V_158 * V_159 )
{
int V_101 ;
struct V_2 * V_3 ;
struct F_1 * V_160 = (struct F_1 * ) V_111 -> V_123 ;
F_59 ( & V_27 ) ;
for( V_3 = V_160 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
struct V_9 * V_15 ;
T_2 V_8 = F_4 ( V_157 -> V_161 , V_3 ) ;
for( V_15 = F_7 ( V_8 , V_3 ) ; V_15 ; V_15 = V_15 -> V_19 ) {
if ( ! F_8 ( V_8 , V_15 -> V_20 ) ) {
if ( F_9 ( V_8 , V_15 -> V_20 ) )
break;
else
continue;
}
V_15 -> V_113 |= V_148 ;
if ( V_15 -> V_113 & V_114 )
continue;
if ( V_15 -> V_105 < V_157 -> V_162 )
continue;
V_101 = F_79 ( V_15 -> V_104 , F_19 ( V_15 ) , V_157 , V_159 ) ;
if ( V_101 == 0 ) {
V_159 -> type = V_15 -> V_104 ;
V_159 -> V_73 = V_15 -> V_105 ;
V_159 -> V_163 = V_3 -> V_6 ;
goto V_132;
}
if ( V_101 < 0 )
goto V_132;
}
}
V_101 = 1 ;
V_132:
F_60 ( & V_27 ) ;
return V_101 ;
}
struct V_110 * F_80 ( T_5 V_116 , int V_137 )
{
struct V_110 * V_160 ;
unsigned int V_4 ;
if ( V_116 < V_164 )
return NULL ;
if ( V_116 > V_165 )
return NULL ;
V_4 = V_116 & ( V_130 - 1 ) ;
F_81 () ;
F_82 (t, &dn_fib_table_hash[h], hlist) {
if ( V_160 -> V_116 == V_116 ) {
F_83 () ;
return V_160 ;
}
}
F_83 () ;
if ( ! V_137 )
return NULL ;
if ( F_84 () ) {
F_85 ( L_2 ) ;
return NULL ;
}
V_160 = F_22 ( sizeof( struct V_110 ) + sizeof( struct F_1 ) ,
V_26 ) ;
if ( V_160 == NULL )
return NULL ;
V_160 -> V_116 = V_116 ;
V_160 -> V_166 = F_67 ;
V_160 -> V_167 = F_74 ;
V_160 -> V_168 = F_78 ;
V_160 -> V_169 = F_77 ;
V_160 -> V_131 = F_58 ;
F_86 ( & V_160 -> V_170 , & V_171 [ V_4 ] ) ;
return V_160 ;
}
struct V_110 * F_87 ( void )
{
T_5 V_172 ;
for( V_172 = V_164 ; V_172 <= V_165 ; V_172 ++ )
if ( F_80 ( V_172 , 0 ) == NULL )
return F_80 ( V_172 , 1 ) ;
return NULL ;
}
void F_75 ( void )
{
int V_173 = 0 ;
struct V_110 * V_111 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_130 ; V_4 ++ ) {
F_66 (tb, &dn_fib_table_hash[h], hlist)
V_173 += V_111 -> V_169 ( V_111 ) ;
}
if ( V_173 )
F_73 ( - 1 ) ;
}
void T_9 F_88 ( void )
{
V_29 = F_89 ( L_3 ,
sizeof( struct V_42 ) ,
0 , V_174 ,
NULL ) ;
}
void T_10 F_90 ( void )
{
struct V_110 * V_160 ;
struct V_175 * V_17 ;
unsigned int V_4 ;
F_91 ( & V_27 ) ;
for ( V_4 = 0 ; V_4 < V_130 ; V_4 ++ ) {
F_92 (t, next, &dn_fib_table_hash[h],
hlist) {
F_93 ( & V_160 -> V_170 ) ;
F_16 ( V_160 ) ;
}
}
F_94 ( & V_27 ) ;
}
