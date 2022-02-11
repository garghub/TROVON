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
+ F_35 ( 4 ) ;
V_62 += F_35 ( ( V_63 * F_35 ( 4 ) ) ) ;
if ( V_43 -> V_64 ) {
T_6 V_65 = F_35 ( sizeof( struct V_44 ) ) ;
V_65 += F_35 ( 4 ) ;
V_62 += F_35 ( V_43 -> V_64 * V_65 ) ;
}
return V_62 ;
}
static int F_36 ( struct V_66 * V_67 , T_5 V_68 , T_5 V_69 , int V_70 ,
T_5 V_71 , T_7 type , T_7 V_72 , void * V_7 , int V_73 ,
struct V_42 * V_43 , unsigned int V_74 )
{
struct V_36 * V_75 ;
struct V_38 * V_39 ;
V_39 = F_37 ( V_67 , V_68 , V_69 , V_70 , sizeof( * V_75 ) , V_74 ) ;
if ( ! V_39 )
return - V_76 ;
V_75 = F_38 ( V_39 ) ;
V_75 -> V_77 = V_78 ;
V_75 -> V_79 = V_73 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 = V_71 ;
V_75 -> V_83 = V_43 -> V_84 ;
V_75 -> V_85 = V_72 ;
V_75 -> V_86 = type ;
V_75 -> V_87 = V_43 -> V_88 ;
if ( F_39 ( V_67 , V_89 , V_71 ) < 0 )
goto V_90;
if ( V_75 -> V_79 &&
F_40 ( V_67 , V_91 , 2 , V_7 ) < 0 )
goto V_90;
if ( V_43 -> V_48 &&
F_39 ( V_67 , V_47 , V_43 -> V_48 ) < 0 )
goto V_90;
if ( F_41 ( V_67 , V_43 -> V_92 ) < 0 )
goto V_90;
if ( V_43 -> V_64 == 1 ) {
if ( V_43 -> V_51 -> V_53 &&
F_42 ( V_67 , V_50 , V_43 -> V_51 -> V_53 ) < 0 )
goto V_90;
if ( V_43 -> V_51 -> V_52 &&
F_39 ( V_67 , V_49 , V_43 -> V_51 -> V_52 ) < 0 )
goto V_90;
}
if ( V_43 -> V_64 > 1 ) {
struct V_44 * V_45 ;
struct V_40 * V_93 ;
if ( ! ( V_93 = F_43 ( V_67 , V_54 ) ) )
goto V_90;
F_29 (fi) {
if ( ! ( V_45 = F_44 ( V_67 , sizeof( * V_45 ) ) ) )
goto V_90;
V_45 -> V_94 = V_60 -> V_95 & 0xFF ;
V_45 -> V_96 = V_60 -> V_97 - 1 ;
V_45 -> V_59 = V_60 -> V_52 ;
if ( V_60 -> V_53 &&
F_42 ( V_67 , V_50 , V_60 -> V_53 ) < 0 )
goto V_90;
V_45 -> V_57 = F_45 ( V_67 ) - ( unsigned char * ) V_45 ;
} F_32 ( V_43 ) ;
F_46 ( V_67 , V_93 ) ;
}
return F_47 ( V_67 , V_39 ) ;
V_90:
F_48 ( V_67 , V_39 ) ;
return - V_76 ;
}
static void F_49 ( int V_70 , struct V_9 * V_15 , int V_31 , T_5 V_71 ,
struct V_38 * V_39 , struct V_98 * V_99 )
{
struct V_66 * V_67 ;
T_5 V_68 = V_99 ? V_99 -> V_68 : 0 ;
int V_100 = - V_101 ;
V_67 = F_50 ( F_33 ( F_19 ( V_15 ) ) , V_26 ) ;
if ( V_67 == NULL )
goto V_90;
V_100 = F_36 ( V_67 , V_68 , V_39 -> V_102 , V_70 , V_71 ,
V_15 -> V_103 , V_15 -> V_104 , & V_15 -> V_20 , V_31 ,
F_19 ( V_15 ) , 0 ) ;
if ( V_100 < 0 ) {
F_51 ( V_100 == - V_76 ) ;
F_52 ( V_67 ) ;
goto V_90;
}
F_53 ( V_67 , & V_105 , V_68 , V_106 , V_39 , V_26 ) ;
return;
V_90:
if ( V_100 < 0 )
F_54 ( & V_105 , V_106 , V_100 ) ;
}
static T_8 int F_55 ( struct V_66 * V_67 ,
struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_2 * V_3 ,
struct V_9 * V_15 )
{
int V_18 , V_111 ;
V_111 = V_108 -> args [ 4 ] ;
for( V_18 = 0 ; V_15 ; V_18 ++ , V_15 = V_15 -> V_19 ) {
if ( V_18 < V_111 )
continue;
if ( V_15 -> V_112 & V_113 )
continue;
if ( F_36 ( V_67 , F_56 ( V_108 -> V_67 ) . V_68 ,
V_108 -> V_39 -> V_102 ,
V_114 ,
V_110 -> V_115 ,
( V_15 -> V_112 & V_113 ) ? 0 : V_15 -> V_103 ,
V_15 -> V_104 , & V_15 -> V_20 , V_3 -> V_6 ,
V_15 -> V_116 , V_117 ) < 0 ) {
V_108 -> args [ 4 ] = V_18 ;
return - 1 ;
}
}
V_108 -> args [ 4 ] = V_18 ;
return V_67 -> V_118 ;
}
static T_8 int F_57 ( struct V_66 * V_67 ,
struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_2 * V_3 )
{
int V_4 , V_119 ;
V_119 = V_108 -> args [ 3 ] ;
for( V_4 = 0 ; V_4 < V_3 -> V_24 ; V_4 ++ ) {
if ( V_4 < V_119 )
continue;
if ( V_4 > V_119 )
memset ( & V_108 -> args [ 4 ] , 0 , sizeof( V_108 -> args ) - 4 * sizeof( V_108 -> args [ 0 ] ) ) ;
if ( V_3 -> V_10 == NULL || V_3 -> V_10 [ V_4 ] == NULL )
continue;
if ( F_55 ( V_67 , V_108 , V_110 , V_3 , V_3 -> V_10 [ V_4 ] ) < 0 ) {
V_108 -> args [ 3 ] = V_4 ;
return - 1 ;
}
}
V_108 -> args [ 3 ] = V_4 ;
return V_67 -> V_118 ;
}
static int F_58 ( struct V_109 * V_110 , struct V_66 * V_67 ,
struct V_107 * V_108 )
{
int V_120 , V_121 ;
struct V_2 * V_3 ;
struct F_1 * V_30 = (struct F_1 * ) V_110 -> V_122 ;
V_121 = V_108 -> args [ 2 ] ;
F_59 ( & V_27 ) ;
for( V_3 = V_30 -> V_35 , V_120 = 0 ; V_3 ; V_3 = V_3 -> V_34 , V_120 ++ ) {
if ( V_120 < V_121 )
continue;
if ( V_120 > V_121 )
memset ( & V_108 -> args [ 3 ] , 0 , sizeof( V_108 -> args ) - 3 * sizeof( V_108 -> args [ 0 ] ) ) ;
if ( F_57 ( V_67 , V_108 , V_110 , V_3 ) < 0 ) {
V_108 -> args [ 2 ] = V_120 ;
F_60 ( & V_27 ) ;
return - 1 ;
}
}
F_60 ( & V_27 ) ;
V_108 -> args [ 2 ] = V_120 ;
return V_67 -> V_118 ;
}
int F_61 ( struct V_66 * V_67 , struct V_107 * V_108 )
{
struct V_123 * V_123 = F_62 ( V_67 -> V_124 ) ;
unsigned int V_4 , V_119 ;
unsigned int V_125 = 0 , V_126 ;
struct V_109 * V_110 ;
int V_127 = 0 ;
if ( ! F_63 ( V_123 , & V_105 ) )
return 0 ;
if ( F_64 ( V_108 -> V_39 ) >= sizeof( struct V_36 ) &&
( (struct V_36 * ) F_38 ( V_108 -> V_39 ) ) -> V_83 & V_128 )
return F_65 ( V_67 , V_108 ) ;
V_119 = V_108 -> args [ 0 ] ;
V_126 = V_108 -> args [ 1 ] ;
for ( V_4 = V_119 ; V_4 < V_129 ; V_4 ++ , V_119 = 0 ) {
V_125 = 0 ;
F_66 (tb, &dn_fib_table_hash[h], hlist) {
if ( V_125 < V_126 )
goto V_17;
if ( V_127 )
memset ( & V_108 -> args [ 2 ] , 0 , sizeof( V_108 -> args ) -
2 * sizeof( V_108 -> args [ 0 ] ) ) ;
if ( V_110 -> V_130 ( V_110 , V_67 , V_108 ) < 0 )
goto V_131;
V_127 = 1 ;
V_17:
V_125 ++ ;
}
}
V_131:
V_108 -> args [ 1 ] = V_125 ;
V_108 -> args [ 0 ] = V_4 ;
return V_67 -> V_118 ;
}
static int F_67 ( struct V_109 * V_110 , struct V_36 * V_37 , struct V_40 * V_41 [] ,
struct V_38 * V_115 , struct V_98 * V_99 )
{
struct F_1 * V_30 = (struct F_1 * ) V_110 -> V_122 ;
struct V_9 * V_132 , * V_15 , * * V_16 , * * V_133 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
int V_31 = V_37 -> V_79 ;
int type = V_37 -> V_86 ;
T_2 V_1 ;
int V_100 ;
if ( V_31 > 16 )
return - V_58 ;
V_3 = V_30 -> V_33 [ V_31 ] ;
if ( ! V_3 && ! ( V_3 = F_21 ( V_30 , V_31 ) ) )
return - V_101 ;
F_68 ( V_1 ) ;
if ( V_41 [ V_91 ] ) {
T_4 V_7 = F_26 ( V_41 [ V_91 ] ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
if ( ( V_43 = F_69 ( V_37 , V_41 , V_115 , & V_100 ) ) == NULL )
return V_100 ;
if ( V_3 -> V_134 > ( V_3 -> V_24 << 2 ) &&
V_3 -> V_24 > V_135 &&
( V_31 == 16 || ( 1 << V_31 ) > V_3 -> V_24 ) )
F_11 ( V_3 ) ;
V_16 = F_6 ( V_1 , V_3 ) ;
F_70 (f, fp) {
if ( F_9 ( V_1 , V_15 -> V_20 ) )
break;
}
V_133 = NULL ;
if ( V_15 && ( V_15 -> V_112 & V_113 ) &&
F_8 ( V_15 -> V_20 , V_1 ) ) {
V_133 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_136;
}
F_71 (f, fp, key) {
if ( V_43 -> V_48 <= F_19 ( V_15 ) -> V_48 )
break;
}
if ( V_15 && F_8 ( V_15 -> V_20 , V_1 ) &&
V_43 -> V_48 == F_19 ( V_15 ) -> V_48 ) {
struct V_9 * * V_137 ;
V_100 = - V_138 ;
if ( V_115 -> V_139 & V_140 )
goto V_131;
if ( V_115 -> V_139 & V_141 ) {
V_133 = V_16 ;
V_16 = & V_15 -> V_19 ;
V_15 = * V_16 ;
goto V_142;
}
V_137 = V_16 ;
V_100 = - V_138 ;
F_71 (f, fp, key) {
if ( V_43 -> V_48 != F_19 ( V_15 ) -> V_48 )
break;
if ( V_15 -> V_103 == type &&
V_15 -> V_104 == V_37 -> V_85 &&
F_19 ( V_15 ) == V_43 )
goto V_131;
}
if ( ! ( V_115 -> V_139 & V_143 ) ) {
V_16 = V_137 ;
V_15 = * V_16 ;
}
}
V_136:
V_100 = - V_144 ;
if ( ! ( V_115 -> V_139 & V_145 ) )
goto V_131;
V_142:
V_100 = - V_101 ;
V_132 = F_72 ( V_29 , V_26 ) ;
if ( V_132 == NULL )
goto V_131;
V_132 -> V_20 = V_1 ;
V_132 -> V_103 = type ;
V_132 -> V_104 = V_37 -> V_85 ;
F_19 ( V_132 ) = V_43 ;
V_132 -> V_19 = V_15 ;
F_14 ( & V_27 ) ;
* V_16 = V_132 ;
F_15 ( & V_27 ) ;
V_3 -> V_134 ++ ;
if ( V_133 ) {
V_15 = * V_133 ;
F_14 ( & V_27 ) ;
* V_133 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( ! ( V_15 -> V_112 & V_113 ) )
F_49 ( V_146 , V_15 , V_31 , V_110 -> V_115 , V_115 , V_99 ) ;
if ( V_15 -> V_112 & V_147 )
F_73 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_134 -- ;
} else {
F_73 ( - 1 ) ;
}
F_49 ( V_114 , V_132 , V_31 , V_110 -> V_115 , V_115 , V_99 ) ;
return 0 ;
V_131:
F_18 ( V_43 ) ;
return V_100 ;
}
static int F_74 ( struct V_109 * V_110 , struct V_36 * V_37 , struct V_40 * V_41 [] ,
struct V_38 * V_115 , struct V_98 * V_99 )
{
struct F_1 * V_30 = (struct F_1 * ) V_110 -> V_122 ;
struct V_9 * * V_16 , * * V_133 , * V_15 ;
int V_31 = V_37 -> V_79 ;
struct V_2 * V_3 ;
T_2 V_1 ;
int V_148 ;
if ( V_31 > 16 )
return - V_58 ;
if ( ( V_3 = V_30 -> V_33 [ V_31 ] ) == NULL )
return - V_149 ;
F_68 ( V_1 ) ;
if ( V_41 [ V_91 ] ) {
T_4 V_7 = F_26 ( V_41 [ V_91 ] ) ;
if ( V_7 & ~ F_5 ( V_3 ) )
return - V_58 ;
V_1 = F_4 ( V_7 , V_3 ) ;
}
V_16 = F_6 ( V_1 , V_3 ) ;
F_70 (f, fp) {
if ( F_8 ( V_15 -> V_20 , V_1 ) )
break;
if ( F_9 ( V_1 , V_15 -> V_20 ) )
return - V_149 ;
}
V_148 = 0 ;
V_133 = NULL ;
F_71 (f, fp, key) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_15 -> V_112 & V_113 )
return - V_149 ;
V_148 ++ ;
if ( V_133 == NULL &&
( ! V_37 -> V_86 || V_15 -> V_103 == V_37 -> V_86 ) &&
( V_37 -> V_85 == V_150 || V_15 -> V_104 == V_37 -> V_85 ) &&
( ! V_37 -> V_87 ||
V_43 -> V_88 == V_37 -> V_87 ) &&
F_24 ( V_37 , V_115 , V_41 , V_43 ) == 0 )
V_133 = V_16 ;
}
if ( V_133 ) {
V_15 = * V_133 ;
F_49 ( V_146 , V_15 , V_31 , V_110 -> V_115 , V_115 , V_99 ) ;
if ( V_148 != 1 ) {
F_14 ( & V_27 ) ;
* V_133 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
if ( V_15 -> V_112 & V_147 )
F_73 ( - 1 ) ;
F_17 ( V_15 ) ;
V_3 -> V_134 -- ;
} else {
V_15 -> V_112 |= V_113 ;
if ( V_15 -> V_112 & V_147 ) {
V_15 -> V_112 &= ~ V_147 ;
F_73 ( - 1 ) ;
}
if ( ++ V_151 > 128 )
F_75 () ;
}
return 0 ;
}
return - V_149 ;
}
static inline int F_76 ( struct V_9 * * V_16 , int V_31 , struct F_1 * V_30 )
{
int V_152 = 0 ;
struct V_9 * V_15 ;
while( ( V_15 = * V_16 ) != NULL ) {
struct V_42 * V_43 = F_19 ( V_15 ) ;
if ( V_43 && ( ( V_15 -> V_112 & V_113 ) || ( V_43 -> V_84 & V_153 ) ) ) {
F_14 ( & V_27 ) ;
* V_16 = V_15 -> V_19 ;
F_15 ( & V_27 ) ;
F_17 ( V_15 ) ;
V_152 ++ ;
continue;
}
V_16 = & V_15 -> V_19 ;
}
return V_152 ;
}
static int F_77 ( struct V_109 * V_110 )
{
struct F_1 * V_30 = (struct F_1 * ) V_110 -> V_122 ;
struct V_2 * V_3 ;
int V_152 = 0 ;
V_151 = 0 ;
for( V_3 = V_30 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
int V_18 ;
int V_154 = 0 ;
for( V_18 = V_3 -> V_24 - 1 ; V_18 >= 0 ; V_18 -- )
V_154 += F_76 ( & V_3 -> V_10 [ V_18 ] , V_3 -> V_6 , V_30 ) ;
V_3 -> V_134 -= V_154 ;
V_152 += V_154 ;
}
return V_152 ;
}
static int F_78 ( struct V_109 * V_110 , const struct V_155 * V_156 , struct V_157 * V_158 )
{
int V_100 ;
struct V_2 * V_3 ;
struct F_1 * V_159 = (struct F_1 * ) V_110 -> V_122 ;
F_59 ( & V_27 ) ;
for( V_3 = V_159 -> V_35 ; V_3 ; V_3 = V_3 -> V_34 ) {
struct V_9 * V_15 ;
T_2 V_8 = F_4 ( V_156 -> V_160 , V_3 ) ;
for( V_15 = F_7 ( V_8 , V_3 ) ; V_15 ; V_15 = V_15 -> V_19 ) {
if ( ! F_8 ( V_8 , V_15 -> V_20 ) ) {
if ( F_9 ( V_8 , V_15 -> V_20 ) )
break;
else
continue;
}
V_15 -> V_112 |= V_147 ;
if ( V_15 -> V_112 & V_113 )
continue;
if ( V_15 -> V_104 < V_156 -> V_161 )
continue;
V_100 = F_79 ( V_15 -> V_103 , F_19 ( V_15 ) , V_156 , V_158 ) ;
if ( V_100 == 0 ) {
V_158 -> type = V_15 -> V_103 ;
V_158 -> V_72 = V_15 -> V_104 ;
V_158 -> V_162 = V_3 -> V_6 ;
goto V_131;
}
if ( V_100 < 0 )
goto V_131;
}
}
V_100 = 1 ;
V_131:
F_60 ( & V_27 ) ;
return V_100 ;
}
struct V_109 * F_80 ( T_5 V_115 , int V_136 )
{
struct V_109 * V_159 ;
unsigned int V_4 ;
if ( V_115 < V_163 )
return NULL ;
if ( V_115 > V_164 )
return NULL ;
V_4 = V_115 & ( V_129 - 1 ) ;
F_81 () ;
F_82 (t, &dn_fib_table_hash[h], hlist) {
if ( V_159 -> V_115 == V_115 ) {
F_83 () ;
return V_159 ;
}
}
F_83 () ;
if ( ! V_136 )
return NULL ;
if ( F_84 () ) {
F_85 ( L_2 ) ;
return NULL ;
}
V_159 = F_22 ( sizeof( struct V_109 ) + sizeof( struct F_1 ) ,
V_26 ) ;
if ( V_159 == NULL )
return NULL ;
V_159 -> V_115 = V_115 ;
V_159 -> V_165 = F_67 ;
V_159 -> V_166 = F_74 ;
V_159 -> V_167 = F_78 ;
V_159 -> V_168 = F_77 ;
V_159 -> V_130 = F_58 ;
F_86 ( & V_159 -> V_169 , & V_170 [ V_4 ] ) ;
return V_159 ;
}
struct V_109 * F_87 ( void )
{
T_5 V_171 ;
for( V_171 = V_163 ; V_171 <= V_164 ; V_171 ++ )
if ( F_80 ( V_171 , 0 ) == NULL )
return F_80 ( V_171 , 1 ) ;
return NULL ;
}
void F_75 ( void )
{
int V_172 = 0 ;
struct V_109 * V_110 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_129 ; V_4 ++ ) {
F_66 (tb, &dn_fib_table_hash[h], hlist)
V_172 += V_110 -> V_168 ( V_110 ) ;
}
if ( V_172 )
F_73 ( - 1 ) ;
}
void T_9 F_88 ( void )
{
V_29 = F_89 ( L_3 ,
sizeof( struct V_42 ) ,
0 , V_173 ,
NULL ) ;
}
void T_10 F_90 ( void )
{
struct V_109 * V_159 ;
struct V_174 * V_17 ;
unsigned int V_4 ;
F_91 ( & V_27 ) ;
for ( V_4 = 0 ; V_4 < V_129 ; V_4 ++ ) {
F_92 (t, next, &dn_fib_table_hash[h],
hlist) {
F_93 ( & V_159 -> V_169 ) ;
F_16 ( V_159 ) ;
}
}
F_94 ( & V_27 ) ;
}
