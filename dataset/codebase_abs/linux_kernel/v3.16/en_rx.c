static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 )
{
int V_8 ;
struct V_9 * V_9 ;
T_2 V_10 ;
for ( V_8 = V_11 ; ; ) {
T_1 V_12 = V_7 ;
if ( V_8 )
V_12 |= V_13 | V_14 ;
V_9 = F_2 ( V_12 , V_8 ) ;
if ( F_3 ( V_9 ) )
break;
if ( -- V_8 < 0 ||
( ( V_15 << V_8 ) < V_6 -> V_16 ) )
return - V_17 ;
}
V_10 = F_4 ( V_2 -> V_18 , V_9 , 0 , V_15 << V_8 ,
V_19 ) ;
if ( F_5 ( V_2 -> V_18 , V_10 ) ) {
F_6 ( V_9 ) ;
return - V_17 ;
}
V_4 -> V_20 = V_15 << V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_21 = V_6 -> V_22 ;
F_7 ( & V_9 -> V_23 ,
V_4 -> V_20 / V_6 -> V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_3 * V_27 ,
struct V_3 * V_28 ,
T_1 V_12 )
{
struct V_3 V_4 [ V_29 ] ;
const struct V_5 * V_6 ;
struct V_9 * V_9 ;
T_2 V_10 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_6 = & V_2 -> V_6 [ V_30 ] ;
V_4 [ V_30 ] = V_28 [ V_30 ] ;
V_4 [ V_30 ] . V_21 += V_6 -> V_24 ;
if ( V_4 [ V_30 ] . V_21 + V_6 -> V_24 <=
V_28 [ V_30 ] . V_20 )
continue;
if ( F_1 ( V_2 , & V_4 [ V_30 ] , V_6 , V_12 ) )
goto V_32;
}
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_27 [ V_30 ] = V_28 [ V_30 ] ;
V_10 = V_28 [ V_30 ] . V_10 + V_28 [ V_30 ] . V_21 ;
V_28 [ V_30 ] = V_4 [ V_30 ] ;
V_26 -> V_33 [ V_30 ] . V_34 = F_9 ( V_10 ) ;
}
return 0 ;
V_32:
while ( V_30 -- ) {
V_6 = & V_2 -> V_6 [ V_30 ] ;
if ( V_4 [ V_30 ] . V_9 != V_28 [ V_30 ] . V_9 ) {
F_10 ( V_2 -> V_18 , V_4 [ V_30 ] . V_10 ,
V_4 [ V_30 ] . V_20 , V_19 ) ;
V_9 = V_4 [ V_30 ] . V_9 ;
F_7 ( & V_9 -> V_23 , 1 ) ;
F_6 ( V_9 ) ;
}
}
return - V_17 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_27 ,
int V_30 )
{
const struct V_5 * V_6 = & V_2 -> V_6 [ V_30 ] ;
T_3 V_35 = V_27 [ V_30 ] . V_21 + 2 * V_6 -> V_24 ;
if ( V_35 > V_27 [ V_30 ] . V_20 )
F_10 ( V_2 -> V_18 , V_27 [ V_30 ] . V_10 , V_27 [ V_30 ] . V_20 ,
V_19 ) ;
if ( V_27 [ V_30 ] . V_9 )
F_6 ( V_27 [ V_30 ] . V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_30 ;
struct V_3 * V_4 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
const struct V_5 * V_6 = & V_2 -> V_6 [ V_30 ] ;
if ( F_1 ( V_2 , & V_37 -> V_4 [ V_30 ] ,
V_6 , V_38 ) )
goto V_32;
}
return 0 ;
V_32:
while ( V_30 -- ) {
struct V_9 * V_9 ;
V_4 = & V_37 -> V_4 [ V_30 ] ;
F_10 ( V_2 -> V_18 , V_4 -> V_10 ,
V_4 -> V_20 , V_19 ) ;
V_9 = V_4 -> V_9 ;
F_7 ( & V_9 -> V_23 , 1 ) ;
F_6 ( V_9 ) ;
V_4 -> V_9 = NULL ;
}
return - V_17 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
const struct V_5 * V_6 = & V_2 -> V_6 [ V_30 ] ;
V_4 = & V_37 -> V_4 [ V_30 ] ;
F_14 ( V_39 , V_2 , L_1 ,
V_30 , F_15 ( V_4 -> V_9 ) ) ;
F_10 ( V_2 -> V_18 , V_4 -> V_10 ,
V_4 -> V_20 , V_19 ) ;
while ( V_4 -> V_21 + V_6 -> V_24 <
V_4 -> V_20 ) {
F_6 ( V_4 -> V_9 ) ;
V_4 -> V_21 += V_6 -> V_24 ;
}
V_4 -> V_9 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_36 * V_37 , int V_40 )
{
struct V_25 * V_26 = V_37 -> V_41 + V_37 -> V_42 * V_40 ;
int V_43 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_26 -> V_33 [ V_30 ] . V_44 =
F_17 ( V_2 -> V_6 [ V_30 ] . V_16 ) ;
V_26 -> V_33 [ V_30 ] . V_45 = F_17 ( V_2 -> V_46 -> V_47 . V_48 ) ;
}
V_43 = ( V_37 -> V_42 - sizeof( struct V_25 ) ) / V_49 ;
for ( V_30 = V_2 -> V_31 ; V_30 < V_43 ; V_30 ++ ) {
V_26 -> V_33 [ V_30 ] . V_44 = 0 ;
V_26 -> V_33 [ V_30 ] . V_45 = F_17 ( V_50 ) ;
V_26 -> V_33 [ V_30 ] . V_34 = 0 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_36 * V_37 , int V_40 ,
T_1 V_12 )
{
struct V_25 * V_26 = V_37 -> V_41 + ( V_40 * V_37 -> V_42 ) ;
struct V_3 * V_27 = V_37 -> V_51 +
( V_40 << V_2 -> V_52 ) ;
return F_8 ( V_2 , V_26 , V_27 , V_37 -> V_4 , V_12 ) ;
}
static inline void F_19 ( struct V_36 * V_37 )
{
* V_37 -> V_53 . V_54 . V_54 = F_17 ( V_37 -> V_55 & 0xffff ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_40 )
{
struct V_3 * V_27 ;
int V_56 ;
V_27 = V_37 -> V_51 + ( V_40 << V_2 -> V_52 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_31 ; V_56 ++ ) {
F_14 ( V_39 , V_2 , L_2 , V_56 ) ;
F_11 ( V_2 , V_27 , V_56 ) ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_57 ;
int V_58 ;
int V_59 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_60 -> V_61 ; V_58 ++ ) {
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ ) {
V_37 = V_2 -> V_63 [ V_57 ] ;
if ( F_18 ( V_2 , V_37 ,
V_37 -> V_64 ,
V_38 ) ) {
if ( V_37 -> V_64 < V_65 ) {
F_22 ( V_2 , L_3 ) ;
return - V_17 ;
} else {
V_59 = F_23 ( V_37 -> V_64 ) ;
F_24 ( V_2 , L_4 ,
V_37 -> V_64 , V_59 ) ;
goto V_66;
}
}
V_37 -> V_64 ++ ;
V_37 -> V_55 ++ ;
}
}
return 0 ;
V_66:
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ ) {
V_37 = V_2 -> V_63 [ V_57 ] ;
while ( V_37 -> V_64 > V_59 ) {
V_37 -> V_64 -- ;
V_37 -> V_55 -- ;
F_20 ( V_2 , V_37 , V_37 -> V_64 ) ;
}
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_40 ;
F_14 ( V_39 , V_2 , L_5 ,
V_37 -> V_67 , V_37 -> V_55 ) ;
F_26 ( ( T_3 ) ( V_37 -> V_55 - V_37 -> V_67 ) > V_37 -> V_64 ) ;
while ( V_37 -> V_67 != V_37 -> V_55 ) {
V_40 = V_37 -> V_67 & V_37 -> V_68 ;
F_14 ( V_39 , V_2 , L_6 , V_40 ) ;
F_20 ( V_2 , V_37 , V_40 ) ;
++ V_37 -> V_67 ;
}
}
void F_27 ( struct V_69 * V_46 )
{
int V_30 ;
int V_70 ;
int V_71 ;
struct V_72 * V_73 = V_46 -> V_73 ;
F_28 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_73 -> V_74 . V_75 )
V_70 = F_29 ( int , V_76 ,
F_30 ( int ,
V_73 -> V_74 . V_77 ,
V_78 ) ) ;
else
V_70 = F_30 ( int , V_79 ,
V_73 -> V_74 . V_75 /
V_73 -> V_74 . V_80 ) - 1 ;
V_71 = F_30 ( int , V_70 ,
F_31 () ) ;
V_46 -> V_81 . V_60 [ V_30 ] . V_62 =
F_23 ( V_71 ) ;
}
}
int F_32 ( struct V_1 * V_2 ,
struct V_36 * * V_82 ,
T_3 V_83 , T_4 V_42 , int V_84 )
{
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_36 * V_37 ;
int V_85 = - V_17 ;
int V_86 ;
V_37 = F_33 ( sizeof( * V_37 ) , V_38 , V_84 ) ;
if ( ! V_37 ) {
V_37 = F_34 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 ) {
F_22 ( V_2 , L_7 ) ;
return - V_17 ;
}
}
V_37 -> V_55 = 0 ;
V_37 -> V_67 = 0 ;
V_37 -> V_83 = V_83 ;
V_37 -> V_68 = V_83 - 1 ;
V_37 -> V_42 = V_42 ;
V_37 -> V_87 = F_35 ( V_37 -> V_42 ) - 1 ;
V_37 -> V_88 = V_37 -> V_83 * V_37 -> V_42 + V_89 ;
V_86 = V_83 * F_36 ( V_29 *
sizeof( struct V_3 ) ) ;
V_37 -> V_51 = F_37 ( V_86 , V_84 ) ;
if ( ! V_37 -> V_51 ) {
V_37 -> V_51 = F_38 ( V_86 ) ;
if ( ! V_37 -> V_51 ) {
V_85 = - V_17 ;
goto V_90;
}
}
F_14 ( V_39 , V_2 , L_8 ,
V_37 -> V_51 , V_86 ) ;
F_39 ( & V_46 -> V_73 -> V_91 -> V_73 , V_84 ) ;
V_85 = F_40 ( V_46 -> V_73 , & V_37 -> V_53 ,
V_37 -> V_88 , 2 * V_15 ) ;
F_39 ( & V_46 -> V_73 -> V_91 -> V_73 , V_46 -> V_73 -> V_92 ) ;
if ( V_85 )
goto V_93;
V_85 = F_41 ( & V_37 -> V_53 . V_41 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_9 ) ;
goto V_94;
}
V_37 -> V_41 = V_37 -> V_53 . V_41 . V_95 . V_41 ;
V_37 -> V_96 = V_2 -> V_97 . V_98 ;
* V_82 = V_37 ;
return 0 ;
V_94:
F_42 ( V_46 -> V_73 , & V_37 -> V_53 , V_37 -> V_88 ) ;
V_93:
F_43 ( V_37 -> V_51 ) ;
V_37 -> V_51 = NULL ;
V_90:
F_44 ( V_37 ) ;
* V_82 = NULL ;
return V_85 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_30 ;
int V_57 ;
int V_85 ;
int V_42 = F_36 ( sizeof( struct V_25 ) +
V_49 * V_2 -> V_31 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ ) {
V_37 = V_2 -> V_63 [ V_57 ] ;
V_37 -> V_55 = 0 ;
V_37 -> V_67 = 0 ;
V_37 -> V_64 = 0 ;
V_37 -> V_99 = V_2 -> V_100 [ V_57 ] -> V_101 . V_99 ;
V_37 -> V_42 = V_42 ;
if ( V_37 -> V_42 <= V_89 )
V_37 -> V_41 += V_89 ;
V_37 -> V_87 = F_35 ( V_37 -> V_42 ) - 1 ;
V_37 -> V_88 = V_37 -> V_83 * V_37 -> V_42 ;
memset ( V_37 -> V_41 , 0 , V_37 -> V_88 ) ;
F_19 ( V_37 ) ;
for ( V_30 = 0 ; V_30 < V_37 -> V_83 ; V_30 ++ )
F_16 ( V_2 , V_37 , V_30 ) ;
V_85 = F_12 ( V_2 , V_37 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_10 ) ;
if ( V_37 -> V_42 <= V_89 )
V_37 -> V_41 -= V_89 ;
V_57 -- ;
goto V_102;
}
}
V_85 = F_21 ( V_2 ) ;
if ( V_85 )
goto V_103;
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ ) {
V_37 = V_2 -> V_63 [ V_57 ] ;
V_37 -> V_68 = V_37 -> V_64 - 1 ;
F_19 ( V_37 ) ;
}
return 0 ;
V_103:
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ )
F_25 ( V_2 , V_2 -> V_63 [ V_57 ] ) ;
V_57 = V_2 -> V_62 - 1 ;
V_102:
while ( V_57 >= 0 ) {
if ( V_2 -> V_63 [ V_57 ] -> V_42 <= V_89 )
V_2 -> V_63 [ V_57 ] -> V_41 -= V_89 ;
F_13 ( V_2 , V_2 -> V_63 [ V_57 ] ) ;
V_57 -- ;
}
return V_85 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_36 * * V_82 ,
T_3 V_83 , T_4 V_42 )
{
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_36 * V_37 = * V_82 ;
F_47 ( & V_37 -> V_53 . V_41 ) ;
F_42 ( V_46 -> V_73 , & V_37 -> V_53 , V_83 * V_42 + V_89 ) ;
F_43 ( V_37 -> V_51 ) ;
V_37 -> V_51 = NULL ;
F_44 ( V_37 ) ;
* V_82 = NULL ;
#ifdef F_48
F_49 ( V_2 ) ;
#endif
}
void F_50 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
F_25 ( V_2 , V_37 ) ;
if ( V_37 -> V_42 <= V_89 )
V_37 -> V_41 -= V_89 ;
F_13 ( V_2 , V_37 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_3 * V_27 ,
struct V_104 * V_105 ,
int V_106 )
{
struct V_107 * V_108 = F_52 ( V_105 ) -> V_27 ;
struct V_5 * V_6 ;
int V_56 ;
T_2 V_10 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_31 ; V_56 ++ ) {
V_6 = & V_2 -> V_6 [ V_56 ] ;
if ( V_106 <= V_6 -> V_109 )
break;
if ( ! V_27 [ V_56 ] . V_9 )
goto V_110;
V_10 = F_53 ( V_26 -> V_33 [ V_56 ] . V_34 ) ;
F_54 ( V_2 -> V_18 , V_10 , V_6 -> V_16 ,
V_111 ) ;
F_55 ( & V_108 [ V_56 ] , V_27 [ V_56 ] . V_9 ) ;
F_56 ( & V_108 [ V_56 ] , V_6 -> V_16 ) ;
V_108 [ V_56 ] . V_21 = V_27 [ V_56 ] . V_21 ;
V_105 -> V_112 += V_6 -> V_24 ;
V_27 [ V_56 ] . V_9 = NULL ;
}
if ( V_56 > 0 )
F_56 ( & V_108 [ V_56 - 1 ] ,
V_106 - V_2 -> V_6 [ V_56 - 1 ] . V_109 ) ;
return V_56 ;
V_110:
while ( V_56 > 0 ) {
V_56 -- ;
F_57 ( & V_108 [ V_56 ] ) ;
}
return 0 ;
}
static struct V_104 * F_58 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_3 * V_27 ,
unsigned int V_106 )
{
struct V_104 * V_105 ;
void * V_113 ;
int V_114 ;
T_2 V_10 ;
V_105 = F_59 ( V_2 -> V_73 , V_115 + V_116 ) ;
if ( ! V_105 ) {
F_14 ( V_117 , V_2 , L_11 ) ;
return NULL ;
}
F_60 ( V_105 , V_116 ) ;
V_105 -> V_118 = V_106 ;
V_113 = F_61 ( V_27 [ 0 ] . V_9 ) + V_27 [ 0 ] . V_21 ;
if ( V_106 <= V_115 ) {
V_10 = F_53 ( V_26 -> V_33 [ 0 ] . V_34 ) ;
F_54 ( V_2 -> V_18 , V_10 , V_106 ,
V_111 ) ;
F_62 ( V_105 , V_113 , V_106 ) ;
V_105 -> V_119 += V_106 ;
} else {
V_114 = F_51 ( V_2 , V_26 , V_27 ,
V_105 , V_106 ) ;
if ( F_63 ( ! V_114 ) ) {
F_64 ( V_105 ) ;
return NULL ;
}
F_52 ( V_105 ) -> V_120 = V_114 ;
memcpy ( V_105 -> V_33 , V_113 , V_121 ) ;
V_105 -> V_119 += V_121 ;
F_52 ( V_105 ) -> V_27 [ 0 ] . V_21 += V_121 ;
F_65 ( & F_52 ( V_105 ) -> V_27 [ 0 ] , V_121 ) ;
V_105 -> V_122 = V_106 - V_121 ;
}
return V_105 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
int V_30 ;
int V_123 = V_124 ;
for ( V_30 = 0 ; V_30 < V_125 ; V_30 ++ , V_123 ++ ) {
if ( * ( V_105 -> V_33 + V_123 ) != ( unsigned char ) ( V_30 & 0xff ) )
goto V_126;
}
V_2 -> V_127 = 1 ;
V_126:
F_67 ( V_105 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_40 = V_37 -> V_55 & V_37 -> V_68 ;
while ( ( T_3 ) ( V_37 -> V_55 - V_37 -> V_67 ) < V_37 -> V_64 ) {
if ( F_18 ( V_2 , V_37 , V_40 , V_128 ) )
break;
V_37 -> V_55 ++ ;
V_40 = V_37 -> V_55 & V_37 -> V_68 ;
}
}
int F_69 ( struct V_129 * V_73 , struct V_130 * V_131 , int V_132 )
{
struct V_1 * V_2 = F_70 ( V_73 ) ;
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_133 * V_134 ;
struct V_36 * V_37 = V_2 -> V_63 [ V_131 -> V_37 ] ;
struct V_3 * V_27 ;
struct V_25 * V_26 ;
struct V_104 * V_105 ;
int V_40 ;
int V_56 ;
unsigned int V_106 ;
int V_135 = 0 ;
int V_136 ;
int V_137 = V_2 -> V_138 ;
T_5 V_139 ;
bool V_140 ;
if ( ! V_2 -> V_141 )
return 0 ;
if ( V_132 <= 0 )
return V_135 ;
V_40 = V_131 -> V_101 . V_142 & V_37 -> V_68 ;
V_134 = & V_131 -> V_41 [ ( V_40 << V_137 ) + V_137 ] ;
while ( F_71 ( V_134 -> V_143 & V_144 ,
V_131 -> V_101 . V_142 & V_131 -> V_83 ) ) {
V_27 = V_37 -> V_51 + ( V_40 << V_2 -> V_52 ) ;
V_26 = V_37 -> V_41 + ( V_40 << V_37 -> V_87 ) ;
F_72 () ;
if ( F_63 ( ( V_134 -> V_143 & V_145 ) ==
V_146 ) ) {
F_22 ( V_2 , L_12 ,
( (struct V_147 * ) V_134 ) -> V_148 ,
( (struct V_147 * ) V_134 ) -> V_149 ) ;
goto V_150;
}
if ( F_63 ( V_134 -> V_151 & V_152 ) ) {
F_14 ( V_117 , V_2 , L_13 ) ;
goto V_150;
}
if ( V_2 -> V_153 & V_154 ) {
struct V_155 * V_156 ;
T_2 V_10 ;
V_10 = F_53 ( V_26 -> V_33 [ 0 ] . V_34 ) ;
F_54 ( V_2 -> V_18 , V_10 , sizeof( * V_156 ) ,
V_111 ) ;
V_156 = (struct V_155 * ) ( F_61 ( V_27 [ 0 ] . V_9 ) +
V_27 [ 0 ] . V_21 ) ;
if ( F_73 ( V_156 -> V_157 ) ) {
struct V_158 * V_159 ;
struct V_160 * V_161 ;
unsigned int V_162 ;
V_162 = V_156 -> V_163 [ V_164 ] ;
V_161 = & V_2 -> V_162 [ V_162 ] ;
F_74 () ;
F_75 (entry, bucket, hlist) {
if ( F_76 ( V_159 -> V_165 ,
V_156 -> V_163 ) ) {
F_77 () ;
goto V_150;
}
}
F_77 () ;
}
}
V_106 = F_78 ( V_134 -> V_166 ) ;
V_106 -= V_37 -> V_167 ;
V_37 -> V_168 += V_106 ;
V_37 -> V_169 ++ ;
V_140 = ( V_73 -> V_170 & V_171 ) &&
( V_134 -> V_172 & F_17 ( V_173 ) ) ;
if ( F_3 ( V_73 -> V_174 & V_171 ) ) {
if ( ( V_134 -> V_175 & F_79 ( V_176 ) ) &&
( V_134 -> V_177 == F_79 ( 0xffff ) ) ) {
V_37 -> V_178 ++ ;
if ( ! F_80 ( V_131 ) &&
( V_73 -> V_174 & V_179 ) ) {
struct V_104 * V_180 = F_81 ( & V_131 -> V_181 ) ;
if ( ! V_180 )
goto V_150;
V_56 = F_51 ( V_2 ,
V_26 , V_27 , V_180 ,
V_106 ) ;
if ( ! V_56 )
goto V_150;
F_52 ( V_180 ) -> V_120 = V_56 ;
V_180 -> V_118 = V_106 ;
V_180 -> V_122 = V_106 ;
V_180 -> V_136 = V_182 ;
if ( V_140 )
V_180 -> V_183 = 1 ;
if ( ( V_134 -> V_172 &
F_17 ( V_184 ) ) &&
( V_73 -> V_174 & V_185 ) ) {
T_4 V_186 = F_82 ( V_134 -> V_187 ) ;
F_83 ( V_180 , F_84 ( V_188 ) , V_186 ) ;
}
if ( V_73 -> V_174 & V_189 )
F_85 ( V_180 ,
F_78 ( V_134 -> V_190 ) ,
V_191 ) ;
F_86 ( V_180 , V_131 -> V_37 ) ;
F_87 ( V_180 , & V_131 -> V_181 ) ;
if ( V_37 -> V_96 == V_192 ) {
V_139 = F_88 ( V_134 ) ;
F_89 ( V_46 ,
F_90 ( V_180 ) ,
V_139 ) ;
}
F_91 ( & V_131 -> V_181 ) ;
goto V_150;
}
V_136 = V_182 ;
} else {
V_136 = V_193 ;
V_37 -> V_194 ++ ;
}
} else {
V_136 = V_193 ;
V_37 -> V_194 ++ ;
}
V_105 = F_58 ( V_2 , V_26 , V_27 , V_106 ) ;
if ( ! V_105 ) {
V_2 -> V_195 . V_196 ++ ;
goto V_150;
}
if ( F_63 ( V_2 -> F_66 ) ) {
F_66 ( V_2 , V_105 ) ;
goto V_150;
}
V_105 -> V_136 = V_136 ;
V_105 -> V_197 = F_92 ( V_105 , V_73 ) ;
F_86 ( V_105 , V_131 -> V_37 ) ;
if ( V_140 )
V_105 -> V_183 = 1 ;
if ( V_73 -> V_174 & V_189 )
F_85 ( V_105 ,
F_78 ( V_134 -> V_190 ) ,
V_191 ) ;
if ( ( F_78 ( V_134 -> V_172 ) &
V_184 ) &&
( V_73 -> V_174 & V_185 ) )
F_83 ( V_105 , F_84 ( V_188 ) , F_82 ( V_134 -> V_187 ) ) ;
if ( V_37 -> V_96 == V_192 ) {
V_139 = F_88 ( V_134 ) ;
F_89 ( V_46 , F_90 ( V_105 ) ,
V_139 ) ;
}
F_87 ( V_105 , & V_131 -> V_181 ) ;
if ( ! F_80 ( V_131 ) )
F_93 ( & V_131 -> V_181 , V_105 ) ;
else
F_94 ( V_105 ) ;
V_150:
for ( V_56 = 0 ; V_56 < V_2 -> V_31 ; V_56 ++ )
F_11 ( V_2 , V_27 , V_56 ) ;
++ V_131 -> V_101 . V_142 ;
V_40 = ( V_131 -> V_101 . V_142 ) & V_37 -> V_68 ;
V_134 = & V_131 -> V_41 [ ( V_40 << V_137 ) + V_137 ] ;
if ( ++ V_135 == V_132 )
goto V_32;
}
V_32:
F_95 ( V_2 -> V_198 . V_199 , V_135 ) ;
F_96 ( & V_131 -> V_101 ) ;
F_97 () ;
V_37 -> V_67 = V_131 -> V_101 . V_142 ;
F_68 ( V_2 , V_37 ) ;
F_19 ( V_37 ) ;
return V_135 ;
}
void F_98 ( struct V_200 * V_101 )
{
struct V_130 * V_131 = F_99 ( V_101 , struct V_130 , V_101 ) ;
struct V_1 * V_2 = F_70 ( V_131 -> V_73 ) ;
if ( V_2 -> V_141 )
F_100 ( & V_131 -> V_181 ) ;
else
F_101 ( V_2 , V_131 ) ;
}
int F_102 ( struct V_201 * V_181 , int V_132 )
{
struct V_130 * V_131 = F_99 ( V_181 , struct V_130 , V_181 ) ;
struct V_129 * V_73 = V_131 -> V_73 ;
struct V_1 * V_2 = F_70 ( V_73 ) ;
int V_202 ;
if ( ! F_103 ( V_131 ) )
return V_132 ;
V_202 = F_69 ( V_73 , V_131 , V_132 ) ;
F_104 ( V_131 ) ;
if ( V_202 == V_132 ) {
int V_203 ;
const struct V_204 * V_205 ;
F_105 ( V_2 -> V_198 . V_206 ) ;
V_203 = F_106 () ;
V_205 = F_107 ( V_131 -> V_207 ) -> V_208 ;
if ( F_63 ( ! F_108 ( V_203 , V_205 ) ) ) {
F_109 ( V_181 ) ;
F_101 ( V_2 , V_131 ) ;
return 0 ;
}
} else {
F_109 ( V_181 ) ;
F_101 ( V_2 , V_131 ) ;
}
return V_202 ;
}
void F_110 ( struct V_129 * V_73 )
{
struct V_1 * V_2 = F_70 ( V_73 ) ;
int V_209 = V_73 -> V_210 + V_124 + V_211 + V_212 ;
int V_88 = 0 ;
int V_30 = 0 ;
while ( V_88 < V_209 ) {
V_2 -> V_6 [ V_30 ] . V_16 =
( V_209 > V_88 + V_213 [ V_30 ] ) ?
V_213 [ V_30 ] : V_209 - V_88 ;
V_2 -> V_6 [ V_30 ] . V_109 = V_88 ;
if ( ! V_30 ) {
V_2 -> V_6 [ V_30 ] . V_22 = V_116 ;
V_2 -> V_6 [ V_30 ] . V_24 =
F_111 ( V_213 [ V_30 ] + V_116 , V_214 ) ;
} else {
V_2 -> V_6 [ V_30 ] . V_22 = 0 ;
V_2 -> V_6 [ V_30 ] . V_24 =
F_111 ( V_213 [ V_30 ] , V_214 ) ;
}
V_88 += V_2 -> V_6 [ V_30 ] . V_16 ;
V_30 ++ ;
}
V_2 -> V_31 = V_30 ;
V_2 -> V_215 = V_209 ;
V_2 -> V_52 = F_112 ( V_30 * sizeof( struct V_3 ) ) ;
F_14 ( V_39 , V_2 , L_14 ,
V_209 , V_2 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
F_22 ( V_2 ,
L_15 ,
V_30 ,
V_2 -> V_6 [ V_30 ] . V_16 ,
V_2 -> V_6 [ V_30 ] . V_109 ,
V_2 -> V_6 [ V_30 ] . V_22 ,
V_2 -> V_6 [ V_30 ] . V_24 ) ;
}
}
static int F_113 ( struct V_1 * V_2 , int V_216 ,
struct V_36 * V_37 ,
enum V_217 * V_218 ,
struct V_219 * V_220 )
{
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_221 * V_222 ;
int V_85 = 0 ;
V_222 = F_114 ( sizeof( * V_222 ) , V_38 ) ;
if ( ! V_222 )
return - V_17 ;
V_85 = F_115 ( V_46 -> V_73 , V_216 , V_220 , V_38 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_16 , V_216 ) ;
goto V_32;
}
V_220 -> V_223 = V_224 ;
memset ( V_222 , 0 , sizeof *V_222 ) ;
F_116 ( V_2 , V_37 -> V_64 , V_37 -> V_42 , 0 , 0 ,
V_216 , V_37 -> V_99 , - 1 , V_222 ) ;
V_222 -> V_225 = F_9 ( V_37 -> V_53 . V_54 . V_10 ) ;
if ( V_46 -> V_73 -> V_74 . V_153 & V_226 ) {
V_222 -> V_227 |= F_17 ( 1 << 29 ) ;
V_37 -> V_167 = V_228 ;
} else
V_37 -> V_167 = 0 ;
V_85 = F_117 ( V_46 -> V_73 , & V_37 -> V_53 . V_229 , V_222 , V_220 , V_218 ) ;
if ( V_85 ) {
F_118 ( V_46 -> V_73 , V_220 ) ;
F_119 ( V_46 -> V_73 , V_220 ) ;
}
F_19 ( V_37 ) ;
V_32:
F_44 ( V_222 ) ;
return V_85 ;
}
int F_120 ( struct V_1 * V_2 )
{
int V_85 ;
T_3 V_216 ;
V_85 = F_121 ( V_2 -> V_46 -> V_73 , 1 , 1 , & V_216 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_17 ) ;
return V_85 ;
}
V_85 = F_115 ( V_2 -> V_46 -> V_73 , V_216 , & V_2 -> V_230 , V_38 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_18 ) ;
F_122 ( V_2 -> V_46 -> V_73 , V_216 , 1 ) ;
return V_85 ;
}
return 0 ;
}
void F_123 ( struct V_1 * V_2 )
{
T_3 V_216 ;
V_216 = V_2 -> V_230 . V_216 ;
F_118 ( V_2 -> V_46 -> V_73 , & V_2 -> V_230 ) ;
F_119 ( V_2 -> V_46 -> V_73 , & V_2 -> V_230 ) ;
F_122 ( V_2 -> V_46 -> V_73 , V_216 , 1 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_231 * V_232 = & V_2 -> V_232 ;
struct V_221 V_222 ;
struct V_233 * V_234 ;
int V_235 ;
void * V_236 ;
T_6 V_237 = ( V_238 | V_239 | V_240 |
V_241 ) ;
int V_30 , V_216 ;
int V_85 = 0 ;
int V_242 = 0 ;
static const T_3 V_243 [ 10 ] = { 0xD181C62C , 0xF7F4DB5B , 0x1983A2FC ,
0x943E1ADB , 0xD9389E6B , 0xD1039C2C , 0xA74499AD ,
0x593D56D9 , 0xF3253C06 , 0x2ADC1FFC } ;
F_14 ( V_39 , V_2 , L_19 ) ;
V_85 = F_121 ( V_46 -> V_73 , V_2 -> V_62 ,
V_2 -> V_62 ,
& V_232 -> V_244 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_20 , V_2 -> V_62 ) ;
return V_85 ;
}
for ( V_30 = 0 ; V_30 < V_2 -> V_62 ; V_30 ++ ) {
V_216 = V_232 -> V_244 + V_30 ;
V_85 = F_113 ( V_2 , V_216 , V_2 -> V_63 [ V_30 ] ,
& V_232 -> V_218 [ V_30 ] ,
& V_232 -> V_245 [ V_30 ] ) ;
if ( V_85 )
goto V_246;
++ V_242 ;
}
V_85 = F_115 ( V_46 -> V_73 , V_2 -> V_244 , & V_232 -> V_247 , V_38 ) ;
if ( V_85 ) {
F_22 ( V_2 , L_21 ) ;
goto V_246;
}
V_232 -> V_247 . V_223 = V_224 ;
F_116 ( V_2 , 0 , 0 , 0 , 1 , V_2 -> V_244 ,
V_2 -> V_63 [ 0 ] -> V_99 , - 1 , & V_222 ) ;
if ( ! V_2 -> V_60 -> V_235 || V_2 -> V_60 -> V_235 > V_2 -> V_62 )
V_235 = V_2 -> V_62 ;
else
V_235 = V_2 -> V_60 -> V_235 ;
V_236 = ( ( void * ) & V_222 ) + F_125 ( struct V_221 , V_248 )
+ V_249 ;
V_234 = V_236 ;
V_234 -> V_244 = F_17 ( F_126 ( V_235 ) << 24 |
( V_232 -> V_244 ) ) ;
V_234 -> V_250 = F_17 ( V_232 -> V_244 ) ;
if ( V_2 -> V_46 -> V_81 . V_251 ) {
V_237 |= V_252 | V_253 ;
V_234 -> V_254 = V_234 -> V_250 ;
}
if ( V_46 -> V_73 -> V_74 . V_255 == V_256 ) {
F_127 ( V_2 , L_22 ) ;
V_237 |= V_257 ;
}
V_234 -> V_153 = V_237 ;
V_234 -> V_258 = V_259 ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ )
V_234 -> V_260 [ V_30 ] = F_17 ( V_243 [ V_30 ] ) ;
V_85 = F_117 ( V_46 -> V_73 , & V_2 -> V_261 . V_229 , & V_222 ,
& V_232 -> V_247 , & V_232 -> V_262 ) ;
if ( V_85 )
goto V_263;
return 0 ;
V_263:
F_128 ( V_46 -> V_73 , NULL , V_232 -> V_262 ,
V_264 , NULL , 0 , 0 , & V_232 -> V_247 ) ;
F_118 ( V_46 -> V_73 , & V_232 -> V_247 ) ;
F_119 ( V_46 -> V_73 , & V_232 -> V_247 ) ;
V_246:
for ( V_30 = 0 ; V_30 < V_242 ; V_30 ++ ) {
F_128 ( V_46 -> V_73 , NULL , V_232 -> V_218 [ V_30 ] ,
V_264 , NULL , 0 , 0 , & V_232 -> V_245 [ V_30 ] ) ;
F_118 ( V_46 -> V_73 , & V_232 -> V_245 [ V_30 ] ) ;
F_119 ( V_46 -> V_73 , & V_232 -> V_245 [ V_30 ] ) ;
}
F_122 ( V_46 -> V_73 , V_232 -> V_244 , V_2 -> V_62 ) ;
return V_85 ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_69 * V_46 = V_2 -> V_46 ;
struct V_231 * V_232 = & V_2 -> V_232 ;
int V_30 ;
F_128 ( V_46 -> V_73 , NULL , V_232 -> V_262 ,
V_264 , NULL , 0 , 0 , & V_232 -> V_247 ) ;
F_118 ( V_46 -> V_73 , & V_232 -> V_247 ) ;
F_119 ( V_46 -> V_73 , & V_232 -> V_247 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_62 ; V_30 ++ ) {
F_128 ( V_46 -> V_73 , NULL , V_232 -> V_218 [ V_30 ] ,
V_264 , NULL , 0 , 0 , & V_232 -> V_245 [ V_30 ] ) ;
F_118 ( V_46 -> V_73 , & V_232 -> V_245 [ V_30 ] ) ;
F_119 ( V_46 -> V_73 , & V_232 -> V_245 [ V_30 ] ) ;
}
F_122 ( V_46 -> V_73 , V_232 -> V_244 , V_2 -> V_62 ) ;
}
