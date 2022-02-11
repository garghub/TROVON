static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
T_2 V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof *V_6 , V_5 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_9 = F_3 ( V_3 -> V_10 , V_5 , & V_7 ) ;
if ( ! V_6 -> V_9 ) {
F_4 ( V_6 ) ;
return NULL ;
}
memset ( V_6 -> V_9 , 0 , V_11 ) ;
if ( V_4 == 0 ) {
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ )
V_6 -> V_9 [ V_8 ] . V_13 . V_14 |= F_5 ( V_15 ) ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_16 = NULL ;
return V_6 ;
}
static void F_6 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_6 -> V_9 ) {
F_7 ( V_3 -> V_10 , V_6 -> V_9 , V_6 -> V_7 ) ;
V_6 -> V_9 = NULL ;
}
F_4 ( V_6 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_17 )
{
struct V_1 * V_6 ;
V_6 = V_17 -> V_16 ;
while ( V_6 != V_17 ) {
struct V_1 * V_16 = V_6 -> V_16 ;
F_6 ( V_3 , V_6 ) ;
V_6 = V_16 ;
}
F_6 ( V_3 , V_17 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_1 * V_18 ,
struct V_1 * V_16 , enum V_19 type )
{
T_3 V_20 ;
if ( ! V_18 || ! V_16 )
return;
V_18 -> V_16 = V_16 ;
if ( type != V_21 ) {
V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_22 =
F_10 ( V_16 -> V_7 ) ;
V_20 = F_11 ( V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_14 ) ;
V_20 &= ~ V_23 ;
V_20 |= F_12 ( V_24 ) ;
if ( F_13 ( V_3 ) ||
( type == V_25 &&
( V_3 -> V_26 & V_27 ) ) )
V_20 |= V_28 ;
V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_14 = F_5 ( V_20 ) ;
}
}
static void F_14 ( struct V_2 * V_3 , struct V_29 * V_30 ,
struct V_1 * V_17 , struct V_1 * V_31 ,
unsigned int V_32 )
{
struct V_1 * V_16 ;
if ( ! V_30 || ! V_17 || ! V_31 )
return;
V_16 = V_30 -> V_33 -> V_16 ;
F_9 ( V_3 , V_30 -> V_33 , V_17 , V_30 -> type ) ;
F_9 ( V_3 , V_31 , V_16 , V_30 -> type ) ;
V_30 -> V_32 += V_32 ;
V_30 -> V_34 += ( V_12 - 1 ) * V_32 ;
if ( V_30 -> type != V_21 && V_30 -> V_33 == V_30 -> V_35 ) {
V_30 -> V_35 -> V_9 [ V_12 - 1 ] . V_13 . V_14
&= ~ F_5 ( V_36 ) ;
V_31 -> V_9 [ V_12 - 1 ] . V_13 . V_14
|= F_5 ( V_36 ) ;
V_30 -> V_35 = V_31 ;
}
}
void F_15 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
if ( ! V_30 )
return;
if ( V_30 -> V_37 )
F_8 ( V_3 , V_30 -> V_37 ) ;
F_4 ( V_30 ) ;
}
static void F_16 ( struct V_29 * V_30 ,
unsigned int V_4 )
{
V_30 -> V_38 = V_30 -> V_37 -> V_9 ;
V_30 -> V_33 = V_30 -> V_37 ;
V_30 -> V_39 = V_30 -> V_38 ;
V_30 -> V_40 = V_30 -> V_37 ;
V_30 -> V_4 = V_4 ;
V_30 -> V_41 = 0 ;
V_30 -> V_42 = 0 ;
V_30 -> V_34 = V_30 -> V_32 * ( V_12 - 1 ) - 1 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_1 * * V_17 , struct V_1 * * V_31 ,
unsigned int V_32 , unsigned int V_4 ,
enum V_19 type , T_1 V_5 )
{
struct V_1 * V_18 ;
V_18 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_18 )
return - V_43 ;
V_32 -- ;
* V_17 = V_18 ;
while ( V_32 > 0 ) {
struct V_1 * V_16 ;
V_16 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_16 ) {
V_18 = * V_17 ;
while ( V_18 ) {
V_16 = V_18 -> V_16 ;
F_6 ( V_3 , V_18 ) ;
V_18 = V_16 ;
}
return - V_43 ;
}
F_9 ( V_3 , V_18 , V_16 , type ) ;
V_18 = V_16 ;
V_32 -- ;
}
F_9 ( V_3 , V_18 , * V_17 , type ) ;
* V_31 = V_18 ;
return 0 ;
}
static struct V_29 * F_18 ( struct V_2 * V_3 ,
unsigned int V_32 , unsigned int V_4 ,
enum V_19 type , T_1 V_5 )
{
struct V_29 * V_30 ;
int V_44 ;
V_30 = F_2 ( sizeof *( V_30 ) , V_5 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_32 = V_32 ;
F_19 ( & V_30 -> V_45 ) ;
V_30 -> type = type ;
if ( V_32 == 0 )
return V_30 ;
V_44 = F_17 ( V_3 , & V_30 -> V_37 ,
& V_30 -> V_35 , V_32 , V_4 , type , V_5 ) ;
if ( V_44 )
goto V_46;
if ( type != V_21 ) {
V_30 -> V_35 -> V_9 [ V_12 - 1 ] . V_13 . V_14 |=
F_5 ( V_36 ) ;
}
F_16 ( V_30 , V_4 ) ;
return V_30 ;
V_46:
F_4 ( V_30 ) ;
return NULL ;
}
void F_20 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
unsigned int V_49 )
{
int V_50 ;
V_50 = V_48 -> V_51 ;
if ( V_50 < V_52 ) {
V_48 -> V_53 [ V_50 ] =
V_48 -> V_54 [ V_49 ] . V_30 ;
V_48 -> V_51 ++ ;
F_21 ( V_3 , L_1
L_2 ,
V_48 -> V_51 ,
( V_48 -> V_51 > 1 ) ? L_3 : L_4 ) ;
} else {
F_15 ( V_3 , V_48 -> V_54 [ V_49 ] . V_30 ) ;
F_21 ( V_3 , L_5
L_6 ,
V_48 -> V_51 ) ;
}
V_48 -> V_54 [ V_49 ] . V_30 = NULL ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned int V_4 ,
enum V_19 type )
{
struct V_1 * V_6 = V_30 -> V_37 ;
int V_8 ;
do {
memset ( V_6 -> V_9 , 0 ,
sizeof( union V_55 ) * V_12 ) ;
if ( V_4 == 0 ) {
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ )
V_6 -> V_9 [ V_8 ] . V_13 . V_14 |=
F_5 ( V_15 ) ;
}
F_9 ( V_3 , V_6 , V_6 -> V_16 , type ) ;
V_6 = V_6 -> V_16 ;
} while ( V_6 != V_30 -> V_37 );
V_30 -> type = type ;
F_16 ( V_30 , V_4 ) ;
F_19 ( & V_30 -> V_45 ) ;
}
int F_23 ( struct V_2 * V_3 , struct V_29 * V_30 ,
unsigned int V_56 , T_1 V_5 )
{
struct V_1 * V_17 ;
struct V_1 * V_31 ;
unsigned int V_32 ;
unsigned int V_57 ;
int V_44 ;
V_57 = ( V_56 + ( V_12 - 1 ) - 1 ) /
( V_12 - 1 ) ;
V_32 = V_30 -> V_32 > V_57 ?
V_30 -> V_32 : V_57 ;
V_44 = F_17 ( V_3 , & V_17 , & V_31 ,
V_32 , V_30 -> V_4 , V_30 -> type , V_5 ) ;
if ( V_44 )
return - V_43 ;
F_14 ( V_3 , V_30 , V_17 , V_31 , V_32 ) ;
F_24 ( V_3 , V_58 ,
L_7 ,
V_30 -> V_32 ) ;
return 0 ;
}
static struct V_59 * F_25 ( struct V_2 * V_3 ,
int type , T_1 V_5 )
{
struct V_59 * V_60 ;
if ( ( type != V_61 ) && ( type != V_62 ) )
return NULL ;
V_60 = F_2 ( sizeof( * V_60 ) , V_5 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> type = type ;
V_60 -> V_63 = F_26 ( V_3 -> V_64 ) ? 2048 : 1024 ;
if ( type == V_62 )
V_60 -> V_63 += F_27 ( V_3 -> V_64 ) ;
V_60 -> V_65 = F_3 ( V_3 -> V_66 , V_5 , & V_60 -> V_7 ) ;
if ( ! V_60 -> V_65 ) {
F_4 ( V_60 ) ;
return NULL ;
}
memset ( V_60 -> V_65 , 0 , V_60 -> V_63 ) ;
return V_60 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
if ( ! V_60 )
return;
F_7 ( V_3 -> V_66 , V_60 -> V_65 , V_60 -> V_7 ) ;
F_4 ( V_60 ) ;
}
struct V_67 * F_29 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
if ( V_60 -> type != V_62 )
return NULL ;
return (struct V_67 * ) V_60 -> V_65 ;
}
struct V_68 * F_30 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
if ( V_60 -> type == V_61 )
return (struct V_68 * ) V_60 -> V_65 ;
return (struct V_68 * )
( V_60 -> V_65 + F_27 ( V_3 -> V_64 ) ) ;
}
struct V_69 * F_31 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
unsigned int V_49 )
{
V_49 ++ ;
if ( V_60 -> type == V_62 )
V_49 ++ ;
return (struct V_69 * )
( V_60 -> V_65 + ( V_49 * F_27 ( V_3 -> V_64 ) ) ) ;
}
static void F_32 ( struct V_2 * V_3 ,
unsigned int V_70 ,
struct V_71 * V_72 , T_2 V_7 )
{
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
if ( V_70 > V_77 )
F_34 ( V_74 ,
sizeof( struct V_71 ) * V_70 ,
V_72 , V_7 ) ;
else if ( V_70 <= V_78 )
return F_7 ( V_3 -> V_79 ,
V_72 , V_7 ) ;
else
return F_7 ( V_3 -> V_80 ,
V_72 , V_7 ) ;
}
static struct V_71 * F_35 ( struct V_2 * V_3 ,
unsigned int V_70 , T_2 * V_7 ,
T_1 V_81 )
{
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
if ( V_70 > V_77 )
return F_36 ( V_74 ,
sizeof( struct V_71 ) * V_70 ,
V_7 , V_81 ) ;
else if ( V_70 <= V_78 )
return F_3 ( V_3 -> V_79 ,
V_81 , V_7 ) ;
else
return F_3 ( V_3 -> V_80 ,
V_81 , V_7 ) ;
}
struct V_29 * F_37 (
struct V_82 * V_83 ,
T_4 V_84 )
{
if ( V_83 -> V_85 & V_86 )
return F_38 ( & V_83 -> V_87 -> V_88 ,
V_84 >> V_89 ) ;
return V_83 -> V_30 ;
}
struct V_29 * F_39 (
struct V_47 * V_74 ,
unsigned int V_49 ,
unsigned int V_90 )
{
struct V_82 * V_83 = & V_74 -> V_54 [ V_49 ] ;
if ( V_90 == 0 )
return V_83 -> V_30 ;
if ( ! V_83 -> V_87 )
return NULL ;
if ( V_90 > V_83 -> V_87 -> V_91 )
return NULL ;
return V_83 -> V_87 -> V_92 [ V_90 ] ;
}
struct V_93 * F_40 ( struct V_2 * V_3 ,
unsigned int V_70 ,
unsigned int V_91 , T_1 V_81 )
{
struct V_93 * V_87 ;
T_3 V_94 ;
struct V_29 * V_95 ;
unsigned long V_96 ;
T_4 V_97 ;
int V_44 ;
F_21 ( V_3 , L_8
L_9 ,
V_91 , V_70 ) ;
if ( V_3 -> V_98 == V_99 ) {
F_21 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_98 ++ ;
V_87 = F_2 ( sizeof( struct V_93 ) , V_81 ) ;
if ( ! V_87 )
goto V_100;
V_87 -> V_91 = V_91 ;
V_87 -> V_70 = V_70 ;
V_87 -> V_92 = F_2 (
sizeof( struct V_29 * ) * V_91 ,
V_81 ) ;
if ( ! V_87 -> V_92 )
goto V_101;
V_87 -> V_102 = F_35 ( V_3 ,
V_70 , & V_87 -> V_103 ,
V_81 ) ;
if ( ! V_87 -> V_102 )
goto V_104;
memset ( V_87 -> V_102 , 0 ,
sizeof( struct V_71 ) * V_70 ) ;
V_87 -> V_105 =
F_41 ( V_3 , true , true , V_81 ) ;
if ( ! V_87 -> V_105 )
goto V_104;
F_42 ( & V_87 -> V_88 , V_106 ) ;
for ( V_94 = 1 ; V_94 < V_91 ; V_94 ++ ) {
V_87 -> V_92 [ V_94 ] =
F_18 ( V_3 , 2 , 1 , V_107 , V_81 ) ;
V_95 = V_87 -> V_92 [ V_94 ] ;
if ( ! V_95 )
goto V_108;
V_95 -> V_90 = V_94 ;
V_97 = V_95 -> V_37 -> V_7 |
F_43 ( V_109 ) |
V_95 -> V_4 ;
V_87 -> V_102 [ V_94 ] . V_110 =
F_10 ( V_97 ) ;
F_21 ( V_3 , L_11 ,
V_94 , ( unsigned long long ) V_97 ) ;
V_96 = ( unsigned long )
( V_95 -> V_37 -> V_7 >> V_89 ) ;
V_44 = F_44 ( & V_87 -> V_88 ,
V_96 , V_95 ) ;
if ( V_44 ) {
F_15 ( V_3 , V_95 ) ;
V_87 -> V_92 [ V_94 ] = NULL ;
goto V_108;
}
}
return V_87 ;
V_108:
for ( V_94 = 1 ; V_94 < V_91 ; V_94 ++ ) {
V_95 = V_87 -> V_92 [ V_94 ] ;
if ( V_95 ) {
V_97 = V_95 -> V_37 -> V_7 ;
F_45 ( & V_87 -> V_88 ,
V_97 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_92 [ V_94 ] = NULL ;
}
}
F_46 ( V_3 , V_87 -> V_105 ) ;
V_104:
F_4 ( V_87 -> V_92 ) ;
V_101:
F_4 ( V_87 ) ;
V_100:
V_3 -> V_98 -- ;
return NULL ;
}
void F_47 ( struct V_2 * V_3 ,
struct V_69 * V_111 ,
struct V_93 * V_87 )
{
T_3 V_112 ;
V_112 = F_48 ( V_87 -> V_70 ) - 2 ;
F_24 ( V_3 , V_113 ,
L_12 ,
1 << ( V_112 + 1 ) ) ;
V_111 -> V_114 &= F_5 ( ~ V_115 ) ;
V_111 -> V_114 |= F_5 ( F_49 ( V_112 )
| V_116 ) ;
V_111 -> V_117 = F_10 ( V_87 -> V_103 ) ;
}
void F_50 ( struct V_2 * V_3 ,
struct V_69 * V_111 ,
struct V_82 * V_83 )
{
T_2 V_97 ;
V_111 -> V_114 &= F_5 ( ~ ( V_115 | V_116 ) ) ;
V_97 = F_51 ( V_83 -> V_30 -> V_40 , V_83 -> V_30 -> V_39 ) ;
V_111 -> V_117 = F_10 ( V_97 | V_83 -> V_30 -> V_4 ) ;
}
void F_52 ( struct V_2 * V_3 ,
struct V_93 * V_87 )
{
int V_94 ;
struct V_29 * V_95 ;
T_2 V_97 ;
if ( ! V_87 )
return;
for ( V_94 = 1 ; V_94 < V_87 -> V_91 ;
V_94 ++ ) {
V_95 = V_87 -> V_92 [ V_94 ] ;
if ( V_95 ) {
V_97 = V_95 -> V_37 -> V_7 ;
F_45 ( & V_87 -> V_88 ,
V_97 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_92 [ V_94 ] = NULL ;
}
}
F_46 ( V_3 , V_87 -> V_105 ) ;
V_3 -> V_98 -- ;
if ( V_87 -> V_102 )
F_32 ( V_3 ,
V_87 -> V_70 ,
V_87 -> V_102 ,
V_87 -> V_103 ) ;
F_4 ( V_87 -> V_92 ) ;
F_4 ( V_87 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
F_54 ( & V_83 -> V_118 ) ;
V_83 -> V_118 . V_119 = ( unsigned long ) V_83 ;
V_83 -> V_118 . V_120 = V_121 ;
V_83 -> V_3 = V_3 ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
int V_122 )
{
struct V_123 * V_124 ;
struct V_125 * V_126 , * V_16 ;
bool V_127 = false ;
if ( V_48 -> V_128 == 0 ||
V_48 -> V_128 > F_56 ( V_3 -> V_129 ) ) {
F_21 ( V_3 , L_13 ) ;
return;
}
V_124 = & ( V_3 -> V_130 [ V_48 -> V_128 - 1 ] . V_131 ) ;
F_57 (tt_info, next, tt_list_head, tt_list) {
if ( V_126 -> V_122 == V_122 ) {
V_127 = true ;
F_58 ( & V_126 -> V_132 ) ;
F_4 ( V_126 ) ;
} else if ( V_127 ) {
break;
}
}
}
int F_59 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_133 * V_134 ,
struct V_135 * V_136 , T_1 V_81 )
{
struct V_125 * V_126 ;
unsigned int V_137 ;
int V_8 , V_138 ;
if ( ! V_136 -> V_139 )
V_137 = 1 ;
else
V_137 = V_134 -> V_140 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ , V_126 ++ ) {
struct V_141 * V_142 ;
V_126 = F_2 ( sizeof( * V_126 ) , V_81 ) ;
if ( ! V_126 )
goto V_143;
F_19 ( & V_126 -> V_132 ) ;
F_60 ( & V_126 -> V_132 ,
& V_3 -> V_130 [ V_48 -> V_128 - 1 ] . V_131 ) ;
V_126 -> V_122 = V_48 -> V_144 -> V_122 ;
if ( V_136 -> V_139 )
V_126 -> V_145 = V_8 + 1 ;
V_142 = & V_126 -> V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ )
F_19 ( & V_142 -> V_147 [ V_138 ] . V_148 ) ;
}
return 0 ;
V_143:
F_55 ( V_3 , V_48 , V_48 -> V_144 -> V_122 ) ;
return - V_43 ;
}
void F_61 ( struct V_2 * V_3 , int V_122 )
{
struct V_47 * V_74 ;
int V_8 ;
int V_149 = 0 ;
if ( V_122 == 0 || ! V_3 -> V_150 [ V_122 ] )
return;
V_74 = V_3 -> V_150 [ V_122 ] ;
V_3 -> V_151 -> V_152 [ V_122 ] = 0 ;
if ( ! V_74 )
return;
if ( V_74 -> V_126 )
V_149 = V_74 -> V_126 -> V_153 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_74 -> V_54 [ V_8 ] . V_30 )
F_15 ( V_3 , V_74 -> V_54 [ V_8 ] . V_30 ) ;
if ( V_74 -> V_54 [ V_8 ] . V_87 )
F_52 ( V_3 ,
V_74 -> V_54 [ V_8 ] . V_87 ) ;
if ( ! F_62 ( & V_74 -> V_54 [ V_8 ] . V_154 ) )
F_63 ( V_3 , L_14
L_15 ,
V_122 , V_8 ) ;
}
F_55 ( V_3 , V_74 , V_122 ) ;
F_64 ( V_3 , V_74 , V_149 ) ;
if ( V_74 -> V_53 ) {
for ( V_8 = 0 ; V_8 < V_74 -> V_51 ; V_8 ++ )
F_15 ( V_3 , V_74 -> V_53 [ V_8 ] ) ;
F_4 ( V_74 -> V_53 ) ;
}
if ( V_74 -> V_155 )
F_28 ( V_3 , V_74 -> V_155 ) ;
if ( V_74 -> V_156 )
F_28 ( V_3 , V_74 -> V_156 ) ;
F_4 ( V_3 -> V_150 [ V_122 ] ) ;
V_3 -> V_150 [ V_122 ] = NULL ;
}
int F_65 ( struct V_2 * V_3 , int V_122 ,
struct V_133 * V_144 , T_1 V_5 )
{
struct V_47 * V_74 ;
int V_8 ;
if ( V_122 == 0 || V_3 -> V_150 [ V_122 ] ) {
F_63 ( V_3 , L_16 , V_122 ) ;
return 0 ;
}
V_3 -> V_150 [ V_122 ] = F_2 ( sizeof( * V_3 -> V_150 [ V_122 ] ) , V_5 ) ;
if ( ! V_3 -> V_150 [ V_122 ] )
return 0 ;
V_74 = V_3 -> V_150 [ V_122 ] ;
V_74 -> V_156 = F_25 ( V_3 , V_61 , V_5 ) ;
if ( ! V_74 -> V_156 )
goto V_46;
F_21 ( V_3 , L_17 , V_122 ,
( unsigned long long ) V_74 -> V_156 -> V_7 ) ;
V_74 -> V_155 = F_25 ( V_3 , V_62 , V_5 ) ;
if ( ! V_74 -> V_155 )
goto V_46;
F_21 ( V_3 , L_18 , V_122 ,
( unsigned long long ) V_74 -> V_155 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_53 ( V_3 , & V_74 -> V_54 [ V_8 ] ) ;
F_19 ( & V_74 -> V_54 [ V_8 ] . V_157 ) ;
F_19 ( & V_74 -> V_54 [ V_8 ] . V_154 ) ;
}
V_74 -> V_54 [ 0 ] . V_30 = F_18 ( V_3 , 2 , 1 , V_158 , V_5 ) ;
if ( ! V_74 -> V_54 [ 0 ] . V_30 )
goto V_46;
V_74 -> V_53 = F_2 (
sizeof( struct V_29 * ) * V_52 ,
V_5 ) ;
if ( ! V_74 -> V_53 )
goto V_46;
V_74 -> V_51 = 0 ;
F_66 ( & V_74 -> V_159 ) ;
F_19 ( & V_74 -> V_160 ) ;
V_74 -> V_144 = V_144 ;
V_3 -> V_151 -> V_152 [ V_122 ] = F_10 ( V_74 -> V_156 -> V_7 ) ;
F_21 ( V_3 , L_19 ,
V_122 ,
& V_3 -> V_151 -> V_152 [ V_122 ] ,
F_67 ( V_3 -> V_151 -> V_152 [ V_122 ] ) ) ;
return 1 ;
V_46:
F_61 ( V_3 , V_122 ) ;
return 0 ;
}
void F_68 ( struct V_2 * V_3 ,
struct V_133 * V_144 )
{
struct V_47 * V_48 ;
struct V_69 * V_161 ;
struct V_29 * V_162 ;
V_48 = V_3 -> V_150 [ V_144 -> V_122 ] ;
V_161 = F_31 ( V_3 , V_48 -> V_155 , 0 ) ;
V_162 = V_48 -> V_54 [ 0 ] . V_30 ;
V_161 -> V_117 = F_10 ( F_51 ( V_162 -> V_33 ,
V_162 -> V_38 )
| V_162 -> V_4 ) ;
}
static T_3 F_69 ( struct V_2 * V_3 ,
struct V_133 * V_144 )
{
struct V_133 * V_163 ;
struct V_164 * V_165 ;
if ( V_144 -> V_166 == V_167 )
V_165 = V_3 -> V_168 ;
else
V_165 = V_3 -> V_169 ;
for ( V_163 = V_144 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
return F_70 ( V_165 , V_163 -> V_171 ) ;
}
int F_71 ( struct V_2 * V_3 , struct V_133 * V_144 )
{
struct V_47 * V_74 ;
struct V_69 * V_161 ;
struct V_68 * V_172 ;
T_3 V_173 ;
T_3 V_174 ;
struct V_133 * V_163 ;
V_74 = V_3 -> V_150 [ V_144 -> V_122 ] ;
if ( V_144 -> V_122 == 0 || ! V_74 ) {
F_63 ( V_3 , L_20 ,
V_144 -> V_122 ) ;
return - V_175 ;
}
V_161 = F_31 ( V_3 , V_74 -> V_155 , 0 ) ;
V_172 = F_30 ( V_3 , V_74 -> V_155 ) ;
V_172 -> V_176 |= F_5 ( F_72 ( 1 ) | V_144 -> V_177 ) ;
switch ( V_144 -> V_166 ) {
case V_167 :
V_172 -> V_176 |= F_5 ( V_178 ) ;
V_174 = F_73 ( 512 ) ;
break;
case V_179 :
V_172 -> V_176 |= F_5 ( V_180 ) ;
V_174 = F_73 ( 64 ) ;
break;
case V_181 :
V_172 -> V_176 |= F_5 ( V_182 ) ;
V_174 = F_73 ( 64 ) ;
break;
case V_183 :
V_172 -> V_176 |= F_5 ( V_184 ) ;
V_174 = F_73 ( 8 ) ;
break;
case V_185 :
F_21 ( V_3 , L_21 ) ;
return - V_175 ;
break;
default:
return - V_175 ;
}
V_173 = F_69 ( V_3 , V_144 ) ;
if ( ! V_173 )
return - V_175 ;
V_172 -> V_186 |= F_5 ( F_74 ( V_173 ) ) ;
for ( V_163 = V_144 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
V_74 -> V_187 = V_163 -> V_171 ;
V_74 -> V_128 = V_173 ;
F_21 ( V_3 , L_22 , V_173 ) ;
F_21 ( V_3 , L_23 , V_74 -> V_187 ) ;
if ( ! V_144 -> V_136 || ! V_144 -> V_136 -> V_188 -> V_170 ) {
V_74 -> V_142 = & V_3 -> V_130 [ V_173 - 1 ] . V_142 ;
} else {
struct V_189 * V_130 ;
struct V_125 * V_190 ;
V_130 = & V_3 -> V_130 [ V_173 - 1 ] ;
F_75 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_190 -> V_122 != V_144 -> V_136 -> V_188 -> V_122 )
continue;
if ( ! V_74 -> V_144 -> V_136 -> V_139 ||
( V_144 -> V_136 -> V_139 &&
V_190 -> V_145 == V_74 -> V_144 -> V_145 ) ) {
V_74 -> V_142 = & V_190 -> V_142 ;
V_74 -> V_126 = V_190 ;
break;
}
}
if ( ! V_74 -> V_126 )
F_63 ( V_3 , L_24 ) ;
}
if ( V_144 -> V_136 && V_144 -> V_136 -> V_188 -> V_170 ) {
V_172 -> V_126 = F_5 ( V_144 -> V_136 -> V_188 -> V_122 |
( V_144 -> V_145 << 8 ) ) ;
if ( V_144 -> V_136 -> V_139 )
V_172 -> V_176 |= F_5 ( V_191 ) ;
}
F_21 ( V_3 , L_25 , V_144 -> V_136 ) ;
F_21 ( V_3 , L_26 , V_144 -> V_145 ) ;
V_161 -> V_192 = F_5 ( F_76 ( V_193 ) ) ;
V_161 -> V_192 |= F_5 ( F_77 ( 0 ) | F_78 ( 3 ) |
V_174 ) ;
V_161 -> V_117 = F_10 ( V_74 -> V_54 [ 0 ] . V_30 -> V_37 -> V_7 |
V_74 -> V_54 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_79 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
unsigned int V_195 ;
V_195 = F_80 ( V_83 -> V_196 . V_197 , 1 , 16 ) - 1 ;
if ( V_195 != V_83 -> V_196 . V_197 - 1 )
F_81 ( & V_144 -> V_74 ,
L_27 ,
V_83 -> V_196 . V_198 ,
1 << V_195 ,
V_144 -> V_166 == V_181 ? L_4 : L_28 ) ;
if ( V_144 -> V_166 == V_181 ) {
V_195 += 3 ;
}
return V_195 ;
}
static unsigned int F_82 ( struct V_133 * V_144 ,
struct V_194 * V_83 , unsigned int V_199 ,
unsigned int V_200 , unsigned int V_201 )
{
unsigned int V_195 ;
V_195 = F_48 ( V_199 ) - 1 ;
V_195 = F_80 ( V_195 , V_200 , V_201 ) ;
if ( ( 1 << V_195 ) != V_199 )
F_81 ( & V_144 -> V_74 ,
L_29 ,
V_83 -> V_196 . V_198 ,
1 << V_195 ,
V_199 ) ;
return V_195 ;
}
static unsigned int F_83 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
if ( V_83 -> V_196 . V_197 == 0 )
return 0 ;
return F_82 ( V_144 , V_83 ,
V_83 -> V_196 . V_197 , 0 , 15 ) ;
}
static unsigned int F_84 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
return F_82 ( V_144 , V_83 ,
V_83 -> V_196 . V_197 * 8 , 3 , 10 ) ;
}
static unsigned int F_85 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
unsigned int V_195 = 0 ;
switch ( V_144 -> V_166 ) {
case V_179 :
if ( F_86 ( & V_83 -> V_196 ) ||
F_87 ( & V_83 -> V_196 ) ) {
V_195 = F_83 ( V_144 , V_83 ) ;
break;
}
case V_167 :
if ( F_88 ( & V_83 -> V_196 ) ||
F_89 ( & V_83 -> V_196 ) ) {
V_195 = F_79 ( V_144 , V_83 ) ;
}
break;
case V_181 :
if ( F_89 ( & V_83 -> V_196 ) ) {
V_195 = F_79 ( V_144 , V_83 ) ;
break;
}
case V_183 :
if ( F_88 ( & V_83 -> V_196 ) ||
F_89 ( & V_83 -> V_196 ) ) {
V_195 = F_84 ( V_144 , V_83 ) ;
}
break;
default:
F_90 () ;
}
return F_91 ( V_195 ) ;
}
static T_3 F_92 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
if ( V_144 -> V_166 != V_167 ||
! F_89 ( & V_83 -> V_196 ) )
return 0 ;
return V_83 -> V_202 . V_203 ;
}
static T_3 F_93 ( struct V_133 * V_144 ,
struct V_194 * V_83 )
{
int V_204 ;
T_3 type ;
V_204 = F_94 ( & V_83 -> V_196 ) ;
if ( F_86 ( & V_83 -> V_196 ) ) {
type = F_76 ( V_193 ) ;
} else if ( F_87 ( & V_83 -> V_196 ) ) {
if ( V_204 )
type = F_76 ( V_205 ) ;
else
type = F_76 ( V_206 ) ;
} else if ( F_89 ( & V_83 -> V_196 ) ) {
if ( V_204 )
type = F_76 ( V_207 ) ;
else
type = F_76 ( V_208 ) ;
} else if ( F_88 ( & V_83 -> V_196 ) ) {
if ( V_204 )
type = F_76 ( V_209 ) ;
else
type = F_76 ( V_210 ) ;
} else {
type = 0 ;
}
return type ;
}
static T_3 F_95 ( struct V_2 * V_3 ,
struct V_133 * V_144 ,
struct V_194 * V_83 )
{
int V_211 ;
int V_212 ;
if ( F_86 ( & V_83 -> V_196 ) ||
F_87 ( & V_83 -> V_196 ) )
return 0 ;
if ( V_144 -> V_166 == V_167 )
return F_96 ( V_83 -> V_202 . V_213 ) ;
V_212 = F_97 ( F_98 ( & V_83 -> V_196 ) ) ;
V_211 = ( F_98 ( & V_83 -> V_196 ) & 0x1800 ) >> 11 ;
return V_212 * ( V_211 + 1 ) ;
}
int F_99 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_133 * V_144 ,
struct V_194 * V_83 ,
T_1 V_81 )
{
unsigned int V_49 ;
struct V_69 * V_111 ;
struct V_29 * V_162 ;
unsigned int V_212 ;
unsigned int V_211 ;
enum V_19 type ;
T_3 V_214 ;
T_3 V_215 ;
V_49 = F_100 ( & V_83 -> V_196 ) ;
V_111 = F_31 ( V_3 , V_48 -> V_155 , V_49 ) ;
V_215 = F_93 ( V_144 , V_83 ) ;
if ( ! V_215 )
return - V_175 ;
V_111 -> V_192 = F_5 ( V_215 ) ;
type = F_101 ( & V_83 -> V_196 ) ;
V_48 -> V_54 [ V_49 ] . V_216 =
F_18 ( V_3 , 2 , 1 , type , V_81 ) ;
if ( ! V_48 -> V_54 [ V_49 ] . V_216 ) {
if ( V_48 -> V_51 == 0 )
return - V_43 ;
V_48 -> V_54 [ V_49 ] . V_216 =
V_48 -> V_53 [ V_48 -> V_51 ] ;
V_48 -> V_53 [ V_48 -> V_51 ] = NULL ;
V_48 -> V_51 -- ;
F_22 ( V_3 , V_48 -> V_54 [ V_49 ] . V_216 ,
1 , type ) ;
}
V_48 -> V_54 [ V_49 ] . V_217 = false ;
V_162 = V_48 -> V_54 [ V_49 ] . V_216 ;
V_111 -> V_117 = F_10 ( V_162 -> V_37 -> V_7 | V_162 -> V_4 ) ;
V_111 -> V_114 = F_5 ( F_85 ( V_144 , V_83 )
| F_102 ( F_92 ( V_144 , V_83 ) ) ) ;
if ( ! F_89 ( & V_83 -> V_196 ) )
V_111 -> V_192 |= F_5 ( F_78 ( 3 ) ) ;
else
V_111 -> V_192 |= F_5 ( F_78 ( 0 ) ) ;
V_212 = F_97 ( F_98 ( & V_83 -> V_196 ) ) ;
V_211 = 0 ;
switch ( V_144 -> V_166 ) {
case V_167 :
V_211 = V_83 -> V_202 . V_218 ;
break;
case V_179 :
if ( F_87 ( & V_83 -> V_196 ) )
V_212 = 512 ;
if ( F_89 ( & V_83 -> V_196 ) ||
F_88 ( & V_83 -> V_196 ) ) {
V_211 = ( F_98 ( & V_83 -> V_196 )
& 0x1800 ) >> 11 ;
}
break;
case V_181 :
case V_183 :
break;
default:
F_90 () ;
}
V_111 -> V_192 |= F_5 ( F_73 ( V_212 ) |
F_77 ( V_211 ) ) ;
V_214 = F_95 ( V_3 , V_144 , V_83 ) ;
V_111 -> V_219 = F_5 ( F_103 ( V_214 ) ) ;
if ( F_86 ( & V_83 -> V_196 ) && V_3 -> V_220 == 0x100 )
V_111 -> V_219 |= F_5 ( F_104 ( 8 ) ) ;
else
V_111 -> V_219 |=
F_5 ( F_104 ( V_214 ) ) ;
return 0 ;
}
void F_105 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_194 * V_83 )
{
unsigned int V_49 ;
struct V_69 * V_111 ;
V_49 = F_100 ( & V_83 -> V_196 ) ;
V_111 = F_31 ( V_3 , V_48 -> V_155 , V_49 ) ;
V_111 -> V_114 = 0 ;
V_111 -> V_192 = 0 ;
V_111 -> V_117 = 0 ;
V_111 -> V_219 = 0 ;
}
void F_106 ( struct V_221 * V_222 )
{
V_222 -> V_223 = 0 ;
V_222 -> V_224 = 0 ;
V_222 -> V_225 = 0 ;
V_222 -> V_226 = 0 ;
V_222 -> type = 0 ;
V_222 -> V_214 = 0 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_59 * V_155 ,
struct V_67 * V_227 ,
struct V_47 * V_48 )
{
struct V_221 * V_222 ;
struct V_69 * V_111 ;
unsigned int V_228 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_222 = & V_48 -> V_54 [ V_8 ] . V_222 ;
if ( ! F_108 ( V_227 , V_8 ) && F_109 ( V_227 , V_8 ) ) {
F_106 ( V_222 ) ;
continue;
}
if ( F_108 ( V_227 , V_8 ) ) {
V_111 = F_31 ( V_3 , V_155 , V_8 ) ;
V_228 = F_110 ( F_11 ( V_111 -> V_192 ) ) ;
if ( V_228 != V_208 && V_228 != V_210 &&
V_228 != V_207 &&
V_228 != V_209 )
continue;
V_222 -> V_223 = F_111 (
F_11 ( V_111 -> V_114 ) ) ;
V_222 -> V_224 = F_112 (
F_11 ( V_111 -> V_114 ) ) + 1 ;
V_222 -> V_225 = F_113 (
F_11 ( V_111 -> V_192 ) ) + 1 ;
V_222 -> V_226 = F_114 (
F_11 ( V_111 -> V_192 ) ) ;
V_222 -> type = V_228 ;
V_222 -> V_214 = F_115 (
F_11 ( V_111 -> V_219 ) ) ;
}
}
}
void F_116 ( struct V_2 * V_3 ,
struct V_59 * V_155 ,
struct V_59 * V_156 ,
unsigned int V_49 )
{
struct V_69 * V_229 ;
struct V_69 * V_230 ;
V_229 = F_31 ( V_3 , V_156 , V_49 ) ;
V_230 = F_31 ( V_3 , V_155 , V_49 ) ;
V_230 -> V_114 = V_229 -> V_114 ;
V_230 -> V_192 = V_229 -> V_192 ;
V_230 -> V_117 = V_229 -> V_117 ;
V_230 -> V_219 = V_229 -> V_219 ;
}
void F_117 ( struct V_2 * V_3 ,
struct V_59 * V_155 ,
struct V_59 * V_156 )
{
struct V_68 * V_231 ;
struct V_68 * V_232 ;
V_231 = F_30 ( V_3 , V_155 ) ;
V_232 = F_30 ( V_3 , V_156 ) ;
V_231 -> V_176 = V_232 -> V_176 ;
V_231 -> V_186 = V_232 -> V_186 ;
V_231 -> V_126 = V_232 -> V_126 ;
V_231 -> V_233 = V_232 -> V_233 ;
}
static int F_118 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
int V_234 = F_119 ( V_3 -> V_235 ) ;
F_24 ( V_3 , V_236 ,
L_30 , V_234 ) ;
if ( ! V_234 )
return 0 ;
V_3 -> V_237 = F_2 ( sizeof( * V_3 -> V_237 ) , V_5 ) ;
if ( ! V_3 -> V_237 )
goto V_238;
V_3 -> V_237 -> V_239 = F_36 ( V_74 ,
V_234 * sizeof( T_4 ) ,
& V_3 -> V_237 -> V_240 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_239 )
goto V_241;
V_3 -> V_237 -> V_242 = F_2 ( sizeof( void * ) * V_234 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_242 )
goto V_243;
V_3 -> V_237 -> V_244 =
F_2 ( sizeof( T_2 ) * V_234 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_244 )
goto V_245;
V_3 -> V_151 -> V_152 [ 0 ] = F_10 ( V_3 -> V_237 -> V_240 ) ;
for ( V_8 = 0 ; V_8 < V_234 ; V_8 ++ ) {
T_2 V_7 ;
void * V_246 = F_36 ( V_74 , V_3 -> V_247 , & V_7 ,
V_5 ) ;
if ( ! V_246 )
goto V_248;
V_3 -> V_237 -> V_239 [ V_8 ] = V_7 ;
V_3 -> V_237 -> V_242 [ V_8 ] = V_246 ;
V_3 -> V_237 -> V_244 [ V_8 ] = V_7 ;
}
return 0 ;
V_248:
for ( V_8 = V_8 - 1 ; V_8 >= 0 ; V_8 -- ) {
F_34 ( V_74 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
V_245:
F_4 ( V_3 -> V_237 -> V_242 ) ;
V_243:
F_34 ( V_74 , V_234 * sizeof( T_4 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
V_241:
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
V_238:
return - V_43 ;
}
static void F_120 ( struct V_2 * V_3 )
{
int V_234 ;
int V_8 ;
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
if ( ! V_3 -> V_237 )
return;
V_234 = F_119 ( V_3 -> V_235 ) ;
for ( V_8 = 0 ; V_8 < V_234 ; V_8 ++ ) {
F_34 ( V_74 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
F_4 ( V_3 -> V_237 -> V_242 ) ;
F_34 ( V_74 , V_234 * sizeof( T_4 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
}
struct V_249 * F_41 ( struct V_2 * V_3 ,
bool V_250 , bool V_251 ,
T_1 V_81 )
{
struct V_249 * V_252 ;
V_252 = F_2 ( sizeof( * V_252 ) , V_81 ) ;
if ( ! V_252 )
return NULL ;
if ( V_250 ) {
V_252 -> V_155 =
F_25 ( V_3 , V_62 ,
V_81 ) ;
if ( ! V_252 -> V_155 ) {
F_4 ( V_252 ) ;
return NULL ;
}
}
if ( V_251 ) {
V_252 -> V_253 =
F_2 ( sizeof( struct V_253 ) , V_81 ) ;
if ( ! V_252 -> V_253 ) {
F_28 ( V_3 , V_252 -> V_155 ) ;
F_4 ( V_252 ) ;
return NULL ;
}
F_66 ( V_252 -> V_253 ) ;
}
V_252 -> V_254 = 0 ;
F_19 ( & V_252 -> V_160 ) ;
return V_252 ;
}
void F_121 ( struct V_2 * V_3 , struct V_255 * V_255 )
{
if ( V_255 ) {
F_4 ( V_255 -> V_256 [ 0 ] ) ;
F_4 ( V_255 ) ;
}
}
void F_46 ( struct V_2 * V_3 ,
struct V_249 * V_252 )
{
F_28 ( V_3 ,
V_252 -> V_155 ) ;
F_4 ( V_252 -> V_253 ) ;
F_4 ( V_252 ) ;
}
void F_122 ( struct V_2 * V_3 )
{
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
struct V_257 * V_258 , * V_259 ;
int V_63 ;
int V_8 , V_138 , V_137 ;
V_63 = sizeof( struct V_260 ) * ( V_3 -> V_261 . V_262 ) ;
if ( V_3 -> V_261 . V_263 )
F_34 ( V_74 , V_63 ,
V_3 -> V_261 . V_263 , V_3 -> V_261 . V_264 ) ;
V_3 -> V_261 . V_263 = NULL ;
F_24 ( V_3 , V_236 , L_31 ) ;
if ( V_3 -> V_265 )
F_15 ( V_3 , V_3 -> V_265 ) ;
V_3 -> V_265 = NULL ;
F_24 ( V_3 , V_236 , L_32 ) ;
if ( V_3 -> V_266 )
F_46 ( V_3 , V_3 -> V_266 ) ;
V_3 -> V_98 = 0 ;
if ( V_3 -> V_267 )
F_15 ( V_3 , V_3 -> V_267 ) ;
V_3 -> V_267 = NULL ;
F_24 ( V_3 , V_236 , L_33 ) ;
F_57 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_58 ( & V_258 -> V_268 ) ;
F_4 ( V_258 ) ;
}
for ( V_8 = 1 ; V_8 < V_269 ; ++ V_8 )
F_61 ( V_3 , V_8 ) ;
if ( V_3 -> V_10 )
F_123 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_24 ( V_3 , V_236 , L_34 ) ;
if ( V_3 -> V_66 )
F_123 ( V_3 -> V_66 ) ;
V_3 -> V_66 = NULL ;
F_24 ( V_3 , V_236 , L_35 ) ;
if ( V_3 -> V_79 )
F_123 ( V_3 -> V_79 ) ;
V_3 -> V_79 = NULL ;
F_24 ( V_3 , V_236 ,
L_36 ) ;
if ( V_3 -> V_80 )
F_123 ( V_3 -> V_80 ) ;
V_3 -> V_80 = NULL ;
F_24 ( V_3 , V_236 ,
L_37 ) ;
if ( V_3 -> V_151 )
F_34 ( V_74 , sizeof( * V_3 -> V_151 ) ,
V_3 -> V_151 , V_3 -> V_151 -> V_7 ) ;
V_3 -> V_151 = NULL ;
F_120 ( V_3 ) ;
if ( ! V_3 -> V_130 )
goto V_270;
V_137 = F_56 ( V_3 -> V_129 ) ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
struct V_141 * V_271 = & V_3 -> V_130 [ V_8 ] . V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ ) {
struct V_123 * V_83 = & V_271 -> V_147 [ V_138 ] . V_148 ;
while ( ! F_62 ( V_83 ) )
F_124 ( V_83 -> V_16 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
struct V_125 * V_136 , * V_272 ;
F_57 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_58 ( & V_136 -> V_132 ) ;
F_4 ( V_136 ) ;
}
}
V_270:
V_3 -> V_273 = 0 ;
V_3 -> V_274 = 0 ;
V_3 -> V_275 = 0 ;
F_4 ( V_3 -> V_276 ) ;
F_4 ( V_3 -> V_277 ) ;
F_4 ( V_3 -> V_278 ) ;
F_4 ( V_3 -> V_130 ) ;
F_4 ( V_3 -> V_279 ) ;
V_3 -> V_247 = 0 ;
V_3 -> V_280 = 0 ;
V_3 -> V_281 [ 0 ] . V_282 = 0 ;
V_3 -> V_281 [ 1 ] . V_282 = 0 ;
}
static int F_125 ( struct V_2 * V_3 ,
struct V_1 * V_283 ,
union V_55 * V_284 ,
union V_55 * V_285 ,
T_2 V_286 ,
struct V_1 * V_287 ,
char * V_288 , int V_289 )
{
unsigned long long V_290 ;
unsigned long long V_291 ;
struct V_1 * V_6 ;
V_290 = F_51 ( V_283 , V_284 ) ;
V_291 = F_51 ( V_283 , V_285 ) ;
V_6 = F_126 ( V_283 , V_284 , V_285 , V_286 ) ;
if ( V_6 != V_287 ) {
F_63 ( V_3 , L_38 ,
V_288 , V_289 ) ;
F_63 ( V_3 , L_39
L_40 ,
V_283 ,
( unsigned long long ) V_286 ) ;
F_63 ( V_3 , L_41
L_42 ,
V_284 , V_290 ,
V_285 , V_291 ) ;
F_63 ( V_3 , L_43 ,
V_287 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , T_1 V_81 )
{
struct {
T_2 V_286 ;
struct V_1 * V_287 ;
} V_292 [] = {
{ 0 , NULL } ,
{ V_3 -> V_265 -> V_37 -> V_7 - 16 , NULL } ,
{ V_3 -> V_265 -> V_37 -> V_7 - 1 , NULL } ,
{ V_3 -> V_265 -> V_37 -> V_7 , V_3 -> V_265 -> V_37 } ,
{ V_3 -> V_265 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 ,
V_3 -> V_265 -> V_37 } ,
{ V_3 -> V_265 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_265 -> V_37 -> V_7 + ( V_12 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_283 ;
union V_55 * V_284 ;
union V_55 * V_285 ;
T_2 V_286 ;
struct V_1 * V_287 ;
} V_293 [] = {
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = V_3 -> V_265 -> V_37 -> V_9 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = V_3 -> V_265 -> V_37 -> V_9 ,
. V_285 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = V_3 -> V_267 -> V_37 -> V_9 ,
. V_285 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = & V_3 -> V_265 -> V_37 -> V_9 [ 0 ] ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 3 ] ,
. V_286 = V_3 -> V_265 -> V_37 -> V_7 + 4 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = & V_3 -> V_265 -> V_37 -> V_9 [ 3 ] ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 6 ] ,
. V_286 = V_3 -> V_265 -> V_37 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_265 -> V_37 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_265 -> V_37 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_265 -> V_37 ,
. V_284 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_267 -> V_37 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
} ;
unsigned int V_294 ;
int V_8 , V_44 ;
V_294 = F_128 ( V_292 ) ;
for ( V_8 = 0 ; V_8 < V_294 ; V_8 ++ ) {
V_44 = F_125 ( V_3 ,
V_3 -> V_265 -> V_37 ,
V_3 -> V_265 -> V_37 -> V_9 ,
& V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 1 ] ,
V_292 [ V_8 ] . V_286 ,
V_292 [ V_8 ] . V_287 ,
L_44 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_294 = F_128 ( V_293 ) ;
for ( V_8 = 0 ; V_8 < V_294 ; V_8 ++ ) {
V_44 = F_125 ( V_3 ,
V_293 [ V_8 ] . V_283 ,
V_293 [ V_8 ] . V_284 ,
V_293 [ V_8 ] . V_285 ,
V_293 [ V_8 ] . V_286 ,
V_293 [ V_8 ] . V_287 ,
L_45 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_21 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_129 ( struct V_2 * V_3 )
{
T_4 V_295 ;
T_2 V_117 ;
V_117 = F_51 ( V_3 -> V_265 -> V_40 ,
V_3 -> V_265 -> V_39 ) ;
if ( V_117 == 0 && ! F_130 () )
F_63 ( V_3 , L_47
L_48 ) ;
V_295 = F_131 ( V_3 , & V_3 -> V_296 -> V_297 ) ;
V_295 &= V_298 ;
V_295 &= ~ V_299 ;
F_24 ( V_3 , V_236 ,
L_49
L_50 ) ;
F_132 ( V_3 , ( ( T_4 ) V_117 & ( T_4 ) ~ V_298 ) | V_295 ,
& V_3 -> V_296 -> V_297 ) ;
}
static void F_133 ( struct V_2 * V_3 , unsigned int V_137 ,
T_5 T_6 * V_97 , T_7 V_300 , int V_301 )
{
T_3 V_295 , V_302 , V_303 ;
int V_8 ;
if ( V_300 > 0x03 ) {
F_63 ( V_3 , L_51
L_52 ,
V_97 , V_300 ) ;
return;
}
V_295 = F_134 ( V_97 + 2 ) ;
V_302 = F_135 ( V_295 ) ;
V_303 = F_136 ( V_295 ) ;
F_24 ( V_3 , V_236 ,
L_53
L_54 ,
V_97 , V_302 , V_303 , V_300 ) ;
if ( V_302 == 0 || ( V_302 + V_303 - 1 ) > V_137 )
return;
if ( V_300 < 0x03 && V_3 -> V_304 < V_301 )
V_3 -> V_279 [ V_3 -> V_304 ++ ] = V_295 ;
if ( ( V_3 -> V_220 == 0x96 ) && ( V_300 != 0x03 ) &&
( V_295 & V_305 ) ) {
F_24 ( V_3 , V_236 ,
L_55 ) ;
V_3 -> V_306 = 1 ;
}
if ( ( V_3 -> V_220 >= 0x100 ) && ( V_300 != 0x03 ) ) {
F_24 ( V_3 , V_236 ,
L_56 ) ;
V_3 -> V_306 = 1 ;
if ( V_295 & V_307 ) {
F_24 ( V_3 , V_236 ,
L_57 ) ;
V_3 -> V_308 = 1 ;
}
}
V_302 -- ;
for ( V_8 = V_302 ; V_8 < ( V_302 + V_303 ) ; V_8 ++ ) {
if ( V_3 -> V_278 [ V_8 ] != 0 ) {
F_63 ( V_3 , L_58
L_59 , V_97 , V_8 ) ;
F_63 ( V_3 , L_60
L_61 ,
V_3 -> V_278 [ V_8 ] , V_300 ) ;
if ( V_3 -> V_278 [ V_8 ] != V_300 &&
V_3 -> V_278 [ V_8 ] != V_309 ) {
if ( V_3 -> V_278 [ V_8 ] == 0x03 )
V_3 -> V_274 -- ;
else
V_3 -> V_273 -- ;
V_3 -> V_278 [ V_8 ] = V_309 ;
}
continue;
}
V_3 -> V_278 [ V_8 ] = V_300 ;
if ( V_300 == 0x03 )
V_3 -> V_274 ++ ;
else
V_3 -> V_273 ++ ;
}
}
static int F_137 ( struct V_2 * V_3 , T_1 V_5 )
{
T_5 T_6 * V_97 , * V_310 ;
T_3 V_311 , V_312 ;
unsigned int V_137 ;
int V_8 , V_138 , V_313 ;
int V_314 = 0 ;
V_97 = & V_3 -> V_315 -> V_64 ;
V_311 = F_138 ( F_134 ( V_97 ) ) ;
if ( V_311 == 0 ) {
F_139 ( V_3 , L_62
L_63 ) ;
return - V_316 ;
}
V_137 = F_56 ( V_3 -> V_129 ) ;
V_3 -> V_278 = F_2 ( sizeof( * V_3 -> V_278 ) * V_137 , V_5 ) ;
if ( ! V_3 -> V_278 )
return - V_43 ;
V_3 -> V_130 = F_2 ( sizeof( * V_3 -> V_130 ) * V_137 , V_5 ) ;
if ( ! V_3 -> V_130 )
return - V_43 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
struct V_141 * V_142 ;
F_19 ( & V_3 -> V_130 [ V_8 ] . V_131 ) ;
V_142 = & V_3 -> V_130 [ V_8 ] . V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ )
F_19 ( & V_142 -> V_147 [ V_138 ] . V_148 ) ;
}
V_97 = & V_3 -> V_315 -> V_317 + V_311 ;
V_310 = V_97 ;
V_312 = V_311 ;
do {
T_3 V_318 ;
V_318 = F_134 ( V_310 ) ;
if ( F_140 ( V_318 ) == V_319 )
V_314 ++ ;
V_312 = F_141 ( V_318 ) ;
V_310 += V_312 ;
} while ( V_312 );
V_3 -> V_279 = F_2 ( sizeof( * V_3 -> V_279 ) * V_314 , V_5 ) ;
if ( ! V_3 -> V_279 )
return - V_43 ;
while ( 1 ) {
T_3 V_318 ;
V_318 = F_134 ( V_97 ) ;
if ( F_140 ( V_318 ) == V_319 )
F_133 ( V_3 , V_137 , V_97 ,
( T_7 ) F_142 ( V_318 ) ,
V_314 ) ;
V_311 = F_141 ( V_318 ) ;
if ( ! V_311 || ( V_3 -> V_273 + V_3 -> V_274 )
== V_137 )
break;
V_97 += V_311 ;
}
if ( V_3 -> V_273 == 0 && V_3 -> V_274 == 0 ) {
F_63 ( V_3 , L_64 ) ;
return - V_316 ;
}
F_24 ( V_3 , V_236 ,
L_65 ,
V_3 -> V_273 , V_3 -> V_274 ) ;
if ( V_3 -> V_274 > 15 ) {
F_24 ( V_3 , V_236 ,
L_66 ) ;
V_3 -> V_274 = 15 ;
}
if ( V_3 -> V_273 > V_320 ) {
F_24 ( V_3 , V_236 ,
L_67 ,
V_320 ) ;
V_3 -> V_273 = V_320 ;
}
if ( V_3 -> V_273 ) {
V_3 -> V_276 = F_143 ( sizeof( * V_3 -> V_276 ) *
V_3 -> V_273 , V_5 ) ;
if ( ! V_3 -> V_276 )
return - V_43 ;
V_313 = 0 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
if ( V_3 -> V_278 [ V_8 ] == 0x03 ||
V_3 -> V_278 [ V_8 ] == 0 ||
V_3 -> V_278 [ V_8 ] == V_309 )
continue;
V_3 -> V_276 [ V_313 ] =
& V_3 -> V_321 -> V_322 +
V_323 * V_8 ;
F_24 ( V_3 , V_236 ,
L_68
L_69 , V_8 ,
V_3 -> V_276 [ V_313 ] ) ;
V_313 ++ ;
if ( V_313 == V_3 -> V_273 )
break;
}
}
if ( V_3 -> V_274 ) {
V_3 -> V_277 = F_143 ( sizeof( * V_3 -> V_277 ) *
V_3 -> V_274 , V_5 ) ;
if ( ! V_3 -> V_277 )
return - V_43 ;
V_313 = 0 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ )
if ( V_3 -> V_278 [ V_8 ] == 0x03 ) {
V_3 -> V_277 [ V_313 ] =
& V_3 -> V_321 -> V_322 +
V_323 * V_8 ;
F_24 ( V_3 , V_236 ,
L_70
L_69 , V_8 ,
V_3 -> V_277 [ V_313 ] ) ;
V_313 ++ ;
if ( V_313 == V_3 -> V_274 )
break;
}
}
return 0 ;
}
int F_144 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_73 * V_74 = F_33 ( V_3 ) -> V_75 . V_76 ;
unsigned int V_20 , V_324 ;
T_4 V_325 ;
struct V_1 * V_6 ;
T_3 V_247 , V_295 ;
int V_8 ;
F_19 ( & V_3 -> V_268 ) ;
V_247 = F_134 ( & V_3 -> V_321 -> V_247 ) ;
F_24 ( V_3 , V_236 ,
L_71 , V_247 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_247 ) != 0 )
break;
V_247 = V_247 >> 1 ;
}
if ( V_8 < 16 )
F_24 ( V_3 , V_236 ,
L_72 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_63 ( V_3 , L_73 ) ;
V_3 -> V_280 = 12 ;
V_3 -> V_247 = 1 << V_3 -> V_280 ;
F_24 ( V_3 , V_236 ,
L_74 , V_3 -> V_247 / 1024 ) ;
V_20 = F_145 ( F_134 ( & V_3 -> V_315 -> V_129 ) ) ;
F_24 ( V_3 , V_236 ,
L_75 , V_20 ) ;
V_324 = F_134 ( & V_3 -> V_321 -> V_326 ) ;
V_20 |= ( V_324 & ~ V_327 ) ;
F_24 ( V_3 , V_236 ,
L_76 , V_20 ) ;
F_146 ( V_20 , & V_3 -> V_321 -> V_326 ) ;
V_3 -> V_151 = F_36 ( V_74 , sizeof( * V_3 -> V_151 ) , & V_7 ,
V_328 ) ;
if ( ! V_3 -> V_151 )
goto V_46;
memset ( V_3 -> V_151 , 0 , sizeof *( V_3 -> V_151 ) ) ;
V_3 -> V_151 -> V_7 = V_7 ;
F_24 ( V_3 , V_236 ,
L_77 ,
( unsigned long long ) V_3 -> V_151 -> V_7 , V_3 -> V_151 ) ;
F_132 ( V_3 , V_7 , & V_3 -> V_321 -> V_329 ) ;
V_3 -> V_10 = F_147 ( L_78 , V_74 ,
V_11 , 64 , V_3 -> V_247 ) ;
V_3 -> V_66 = F_147 ( L_79 , V_74 ,
2112 , 64 , V_3 -> V_247 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_66 )
goto V_46;
V_3 -> V_79 =
F_147 ( L_80 ,
V_74 , V_78 , 16 , 0 ) ;
V_3 -> V_80 =
F_147 ( L_81 ,
V_74 , V_77 , 16 , 0 ) ;
if ( ! V_3 -> V_79 || ! V_3 -> V_80 )
goto V_46;
V_3 -> V_267 = F_18 ( V_3 , 1 , 1 , V_330 , V_5 ) ;
if ( ! V_3 -> V_267 )
goto V_46;
F_24 ( V_3 , V_236 ,
L_82 , V_3 -> V_267 ) ;
F_24 ( V_3 , V_236 , L_83 ,
( unsigned long long ) V_3 -> V_267 -> V_37 -> V_7 ) ;
V_325 = F_131 ( V_3 , & V_3 -> V_321 -> V_267 ) ;
V_325 = ( V_325 & ( T_4 ) V_331 ) |
( V_3 -> V_267 -> V_37 -> V_7 & ( T_4 ) ~ V_331 ) |
V_3 -> V_267 -> V_4 ;
F_24 ( V_3 , V_236 ,
L_84 , V_20 ) ;
F_132 ( V_3 , V_325 , & V_3 -> V_321 -> V_267 ) ;
F_148 ( V_3 ) ;
V_3 -> V_266 = F_41 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_266 )
goto V_46;
V_3 -> V_98 ++ ;
V_20 = F_134 ( & V_3 -> V_315 -> V_332 ) ;
V_20 &= V_333 ;
F_24 ( V_3 , V_236 ,
L_85
L_86 , V_20 ) ;
V_3 -> V_334 = ( void T_6 * ) V_3 -> V_315 + V_20 ;
F_149 ( V_3 ) ;
F_150 ( V_3 ) ;
V_3 -> V_296 = & V_3 -> V_335 -> V_296 [ 0 ] ;
F_24 ( V_3 , V_236 , L_87 ) ;
V_3 -> V_265 = F_18 ( V_3 , V_336 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_265 )
goto V_46;
if ( F_127 ( V_3 , V_5 ) < 0 )
goto V_46;
V_3 -> V_261 . V_263 = F_36 ( V_74 ,
sizeof( struct V_260 ) * V_336 , & V_7 ,
V_328 ) ;
if ( ! V_3 -> V_261 . V_263 )
goto V_46;
F_24 ( V_3 , V_236 ,
L_88 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_261 . V_263 , 0 , sizeof( struct V_260 ) * V_336 ) ;
V_3 -> V_261 . V_262 = V_336 ;
V_3 -> V_261 . V_264 = V_7 ;
F_24 ( V_3 , V_236 ,
L_89 ,
V_3 -> V_261 . V_262 ,
V_3 -> V_261 . V_263 ,
( unsigned long long ) V_3 -> V_261 . V_264 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_265 -> V_37 ; V_20 < V_336 ; V_20 ++ ) {
struct V_260 * V_337 = & V_3 -> V_261 . V_263 [ V_20 ] ;
V_337 -> V_338 = F_10 ( V_6 -> V_7 ) ;
V_337 -> V_339 = F_5 ( V_12 ) ;
V_337 -> V_340 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_134 ( & V_3 -> V_296 -> V_341 ) ;
V_20 &= V_342 ;
V_20 |= V_336 ;
F_24 ( V_3 , V_236 ,
L_90 ,
V_20 ) ;
F_146 ( V_20 , & V_3 -> V_296 -> V_341 ) ;
F_24 ( V_3 , V_236 ,
L_91 ) ;
F_24 ( V_3 , V_236 ,
L_92 ,
( unsigned long long ) V_3 -> V_261 . V_264 ) ;
V_325 = F_131 ( V_3 , & V_3 -> V_296 -> V_343 ) ;
V_325 &= V_298 ;
V_325 |= ( V_3 -> V_261 . V_264 & ( T_4 ) ~ V_298 ) ;
F_132 ( V_3 , V_325 , & V_3 -> V_296 -> V_343 ) ;
F_129 ( V_3 ) ;
F_24 ( V_3 , V_236 ,
L_93 ) ;
F_151 ( V_3 , 0 ) ;
F_66 ( & V_3 -> V_344 ) ;
for ( V_8 = 0 ; V_8 < V_269 ; ++ V_8 )
V_3 -> V_150 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_320 ; ++ V_8 ) {
V_3 -> V_281 [ 0 ] . V_345 [ V_8 ] = 0 ;
V_3 -> V_281 [ 1 ] . V_345 [ V_8 ] = 0 ;
F_66 ( & V_3 -> V_281 [ 1 ] . V_346 [ V_8 ] ) ;
}
if ( F_118 ( V_3 , V_5 ) )
goto V_46;
if ( F_137 ( V_3 , V_5 ) )
goto V_46;
V_295 = F_134 ( & V_3 -> V_321 -> V_347 ) ;
V_295 &= ~ V_348 ;
V_295 |= V_349 ;
F_146 ( V_295 , & V_3 -> V_321 -> V_347 ) ;
return 0 ;
V_46:
F_63 ( V_3 , L_94 ) ;
F_152 ( V_3 ) ;
F_153 ( V_3 ) ;
F_122 ( V_3 ) ;
return - V_43 ;
}
