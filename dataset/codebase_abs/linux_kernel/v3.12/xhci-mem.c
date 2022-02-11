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
V_6 -> V_9 [ V_8 ] . V_13 . V_14 |= V_15 ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_16 = NULL ;
return V_6 ;
}
static void F_5 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_6 -> V_9 ) {
F_6 ( V_3 -> V_10 , V_6 -> V_9 , V_6 -> V_7 ) ;
V_6 -> V_9 = NULL ;
}
F_4 ( V_6 ) ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_17 )
{
struct V_1 * V_6 ;
V_6 = V_17 -> V_16 ;
while ( V_6 != V_17 ) {
struct V_1 * V_16 = V_6 -> V_16 ;
F_5 ( V_3 , V_6 ) ;
V_6 = V_16 ;
}
F_5 ( V_3 , V_17 ) ;
}
static void F_8 ( struct V_2 * V_3 , struct V_1 * V_18 ,
struct V_1 * V_16 , enum V_19 type )
{
T_3 V_20 ;
if ( ! V_18 || ! V_16 )
return;
V_18 -> V_16 = V_16 ;
if ( type != V_21 ) {
V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_22 =
F_9 ( V_16 -> V_7 ) ;
V_20 = F_10 ( V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_14 ) ;
V_20 &= ~ V_23 ;
V_20 |= F_11 ( V_24 ) ;
if ( F_12 ( V_3 ) ||
( type == V_25 &&
( V_3 -> V_26 & V_27 ) ) )
V_20 |= V_28 ;
V_18 -> V_9 [ V_12 - 1 ] . V_13 . V_14 = F_13 ( V_20 ) ;
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
F_8 ( V_3 , V_30 -> V_33 , V_17 , V_30 -> type ) ;
F_8 ( V_3 , V_31 , V_16 , V_30 -> type ) ;
V_30 -> V_32 += V_32 ;
V_30 -> V_34 += ( V_12 - 1 ) * V_32 ;
if ( V_30 -> type != V_21 && V_30 -> V_33 == V_30 -> V_35 ) {
V_30 -> V_35 -> V_9 [ V_12 - 1 ] . V_13 . V_14
&= ~ F_13 ( V_36 ) ;
V_31 -> V_9 [ V_12 - 1 ] . V_13 . V_14
|= F_13 ( V_36 ) ;
V_30 -> V_35 = V_31 ;
}
}
void F_15 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
if ( ! V_30 )
return;
if ( V_30 -> V_37 )
F_7 ( V_3 , V_30 -> V_37 ) ;
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
F_5 ( V_3 , V_18 ) ;
V_18 = V_16 ;
}
return - V_43 ;
}
F_8 ( V_3 , V_18 , V_16 , type ) ;
V_18 = V_16 ;
V_32 -- ;
}
F_8 ( V_3 , V_18 , * V_17 , type ) ;
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
F_13 ( V_36 ) ;
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
V_6 -> V_9 [ V_8 ] . V_13 . V_14 |= V_15 ;
}
F_8 ( V_3 , V_6 , V_6 -> V_16 , type ) ;
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
F_6 ( V_3 -> V_66 , V_60 -> V_65 , V_60 -> V_7 ) ;
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
struct V_73 * V_74 = F_33 ( F_34 ( V_3 ) -> V_75 . V_76 ) ;
if ( V_70 > V_77 )
F_35 ( & V_74 -> V_78 ,
sizeof( struct V_71 ) * V_70 ,
V_72 , V_7 ) ;
else if ( V_70 <= V_79 )
return F_6 ( V_3 -> V_80 ,
V_72 , V_7 ) ;
else
return F_6 ( V_3 -> V_81 ,
V_72 , V_7 ) ;
}
static struct V_71 * F_36 ( struct V_2 * V_3 ,
unsigned int V_70 , T_2 * V_7 ,
T_1 V_82 )
{
struct V_73 * V_74 = F_33 ( F_34 ( V_3 ) -> V_75 . V_76 ) ;
if ( V_70 > V_77 )
return F_37 ( & V_74 -> V_78 ,
sizeof( struct V_71 ) * V_70 ,
V_7 , V_82 ) ;
else if ( V_70 <= V_79 )
return F_3 ( V_3 -> V_80 ,
V_82 , V_7 ) ;
else
return F_3 ( V_3 -> V_81 ,
V_82 , V_7 ) ;
}
struct V_29 * F_38 (
struct V_83 * V_84 ,
T_4 V_85 )
{
if ( V_84 -> V_86 & V_87 )
return F_39 ( & V_84 -> V_88 -> V_89 ,
V_85 >> V_90 ) ;
return V_84 -> V_30 ;
}
struct V_29 * F_40 (
struct V_47 * V_78 ,
unsigned int V_49 ,
unsigned int V_91 )
{
struct V_83 * V_84 = & V_78 -> V_54 [ V_49 ] ;
if ( V_91 == 0 )
return V_84 -> V_30 ;
if ( ! V_84 -> V_88 )
return NULL ;
if ( V_91 > V_84 -> V_88 -> V_92 )
return NULL ;
return V_84 -> V_88 -> V_93 [ V_91 ] ;
}
struct V_94 * F_41 ( struct V_2 * V_3 ,
unsigned int V_70 ,
unsigned int V_92 , T_1 V_82 )
{
struct V_94 * V_88 ;
T_3 V_95 ;
struct V_29 * V_96 ;
unsigned long V_97 ;
T_4 V_98 ;
int V_44 ;
F_21 ( V_3 , L_8
L_9 ,
V_92 , V_70 ) ;
if ( V_3 -> V_99 == V_100 ) {
F_21 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_99 ++ ;
V_88 = F_2 ( sizeof( struct V_94 ) , V_82 ) ;
if ( ! V_88 )
goto V_101;
V_88 -> V_92 = V_92 ;
V_88 -> V_70 = V_70 ;
V_88 -> V_93 = F_2 (
sizeof( struct V_29 * ) * V_92 ,
V_82 ) ;
if ( ! V_88 -> V_93 )
goto V_102;
V_88 -> V_103 = F_36 ( V_3 ,
V_70 , & V_88 -> V_104 ,
V_82 ) ;
if ( ! V_88 -> V_103 )
goto V_105;
memset ( V_88 -> V_103 , 0 ,
sizeof( struct V_71 ) * V_70 ) ;
V_88 -> V_106 =
F_42 ( V_3 , true , true , V_82 ) ;
if ( ! V_88 -> V_106 )
goto V_105;
F_43 ( & V_88 -> V_89 , V_107 ) ;
for ( V_95 = 1 ; V_95 < V_92 ; V_95 ++ ) {
V_88 -> V_93 [ V_95 ] =
F_18 ( V_3 , 2 , 1 , V_108 , V_82 ) ;
V_96 = V_88 -> V_93 [ V_95 ] ;
if ( ! V_96 )
goto V_109;
V_96 -> V_91 = V_95 ;
V_98 = V_96 -> V_37 -> V_7 |
F_44 ( V_110 ) |
V_96 -> V_4 ;
V_88 -> V_103 [ V_95 ] . V_111 =
F_9 ( V_98 ) ;
F_21 ( V_3 , L_11 ,
V_95 , ( unsigned long long ) V_98 ) ;
V_97 = ( unsigned long )
( V_96 -> V_37 -> V_7 >> V_90 ) ;
V_44 = F_45 ( & V_88 -> V_89 ,
V_97 , V_96 ) ;
if ( V_44 ) {
F_15 ( V_3 , V_96 ) ;
V_88 -> V_93 [ V_95 ] = NULL ;
goto V_109;
}
}
return V_88 ;
V_109:
for ( V_95 = 1 ; V_95 < V_92 ; V_95 ++ ) {
V_96 = V_88 -> V_93 [ V_95 ] ;
if ( V_96 ) {
V_98 = V_96 -> V_37 -> V_7 ;
F_46 ( & V_88 -> V_89 ,
V_98 >> V_90 ) ;
F_15 ( V_3 , V_96 ) ;
V_88 -> V_93 [ V_95 ] = NULL ;
}
}
F_47 ( V_3 , V_88 -> V_106 ) ;
V_105:
F_4 ( V_88 -> V_93 ) ;
V_102:
F_4 ( V_88 ) ;
V_101:
V_3 -> V_99 -- ;
return NULL ;
}
void F_48 ( struct V_2 * V_3 ,
struct V_69 * V_112 ,
struct V_94 * V_88 )
{
T_3 V_113 ;
V_113 = F_49 ( V_88 -> V_70 ) - 2 ;
F_24 ( V_3 , V_114 ,
L_12 ,
1 << ( V_113 + 1 ) ) ;
V_112 -> V_115 &= F_13 ( ~ V_116 ) ;
V_112 -> V_115 |= F_13 ( F_50 ( V_113 )
| V_117 ) ;
V_112 -> V_118 = F_9 ( V_88 -> V_104 ) ;
}
void F_51 ( struct V_2 * V_3 ,
struct V_69 * V_112 ,
struct V_83 * V_84 )
{
T_2 V_98 ;
V_112 -> V_115 &= F_13 ( ~ ( V_116 | V_117 ) ) ;
V_98 = F_52 ( V_84 -> V_30 -> V_40 , V_84 -> V_30 -> V_39 ) ;
V_112 -> V_118 = F_9 ( V_98 | V_84 -> V_30 -> V_4 ) ;
}
void F_53 ( struct V_2 * V_3 ,
struct V_94 * V_88 )
{
int V_95 ;
struct V_29 * V_96 ;
T_2 V_98 ;
if ( ! V_88 )
return;
for ( V_95 = 1 ; V_95 < V_88 -> V_92 ;
V_95 ++ ) {
V_96 = V_88 -> V_93 [ V_95 ] ;
if ( V_96 ) {
V_98 = V_96 -> V_37 -> V_7 ;
F_46 ( & V_88 -> V_89 ,
V_98 >> V_90 ) ;
F_15 ( V_3 , V_96 ) ;
V_88 -> V_93 [ V_95 ] = NULL ;
}
}
F_47 ( V_3 , V_88 -> V_106 ) ;
V_3 -> V_99 -- ;
if ( V_88 -> V_103 )
F_32 ( V_3 ,
V_88 -> V_70 ,
V_88 -> V_103 ,
V_88 -> V_104 ) ;
if ( V_88 )
F_4 ( V_88 -> V_93 ) ;
F_4 ( V_88 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
F_55 ( & V_84 -> V_119 ) ;
V_84 -> V_119 . V_120 = ( unsigned long ) V_84 ;
V_84 -> V_119 . V_121 = V_122 ;
V_84 -> V_3 = V_3 ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
int V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 , * V_16 ;
bool V_128 = false ;
if ( V_48 -> V_129 == 0 ||
V_48 -> V_129 > F_57 ( V_3 -> V_130 ) ) {
F_21 ( V_3 , L_13 ) ;
return;
}
V_125 = & ( V_3 -> V_131 [ V_48 -> V_129 - 1 ] . V_132 ) ;
F_58 (tt_info, next, tt_list_head, tt_list) {
if ( V_127 -> V_123 == V_123 ) {
V_128 = true ;
F_59 ( & V_127 -> V_133 ) ;
F_4 ( V_127 ) ;
} else if ( V_128 ) {
break;
}
}
}
int F_60 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_134 * V_135 ,
struct V_136 * V_137 , T_1 V_82 )
{
struct V_126 * V_127 ;
unsigned int V_138 ;
int V_8 , V_139 ;
if ( ! V_137 -> V_140 )
V_138 = 1 ;
else
V_138 = V_135 -> V_141 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ , V_127 ++ ) {
struct V_142 * V_143 ;
V_127 = F_2 ( sizeof( * V_127 ) , V_82 ) ;
if ( ! V_127 )
goto V_144;
F_19 ( & V_127 -> V_133 ) ;
F_61 ( & V_127 -> V_133 ,
& V_3 -> V_131 [ V_48 -> V_129 - 1 ] . V_132 ) ;
V_127 -> V_123 = V_48 -> V_145 -> V_123 ;
if ( V_137 -> V_140 )
V_127 -> V_146 = V_8 + 1 ;
V_143 = & V_127 -> V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_19 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
return 0 ;
V_144:
F_56 ( V_3 , V_48 , V_48 -> V_145 -> V_123 ) ;
return - V_43 ;
}
void F_62 ( struct V_2 * V_3 , int V_123 )
{
struct V_47 * V_78 ;
int V_8 ;
int V_150 = 0 ;
if ( V_123 == 0 || ! V_3 -> V_151 [ V_123 ] )
return;
V_78 = V_3 -> V_151 [ V_123 ] ;
V_3 -> V_152 -> V_153 [ V_123 ] = 0 ;
if ( ! V_78 )
return;
if ( V_78 -> V_127 )
V_150 = V_78 -> V_127 -> V_154 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_78 -> V_54 [ V_8 ] . V_30 )
F_15 ( V_3 , V_78 -> V_54 [ V_8 ] . V_30 ) ;
if ( V_78 -> V_54 [ V_8 ] . V_88 )
F_53 ( V_3 ,
V_78 -> V_54 [ V_8 ] . V_88 ) ;
if ( ! F_63 ( & V_78 -> V_54 [ V_8 ] . V_155 ) )
F_64 ( V_3 , L_14
L_15 ,
V_123 , V_8 ) ;
}
F_56 ( V_3 , V_78 , V_123 ) ;
F_65 ( V_3 , V_78 , V_150 ) ;
if ( V_78 -> V_53 ) {
for ( V_8 = 0 ; V_8 < V_78 -> V_51 ; V_8 ++ )
F_15 ( V_3 , V_78 -> V_53 [ V_8 ] ) ;
F_4 ( V_78 -> V_53 ) ;
}
if ( V_78 -> V_156 )
F_28 ( V_3 , V_78 -> V_156 ) ;
if ( V_78 -> V_157 )
F_28 ( V_3 , V_78 -> V_157 ) ;
F_4 ( V_3 -> V_151 [ V_123 ] ) ;
V_3 -> V_151 [ V_123 ] = NULL ;
}
int F_66 ( struct V_2 * V_3 , int V_123 ,
struct V_134 * V_145 , T_1 V_5 )
{
struct V_47 * V_78 ;
int V_8 ;
if ( V_123 == 0 || V_3 -> V_151 [ V_123 ] ) {
F_64 ( V_3 , L_16 , V_123 ) ;
return 0 ;
}
V_3 -> V_151 [ V_123 ] = F_2 ( sizeof( * V_3 -> V_151 [ V_123 ] ) , V_5 ) ;
if ( ! V_3 -> V_151 [ V_123 ] )
return 0 ;
V_78 = V_3 -> V_151 [ V_123 ] ;
V_78 -> V_157 = F_25 ( V_3 , V_61 , V_5 ) ;
if ( ! V_78 -> V_157 )
goto V_46;
F_21 ( V_3 , L_17 , V_123 ,
( unsigned long long ) V_78 -> V_157 -> V_7 ) ;
V_78 -> V_156 = F_25 ( V_3 , V_62 , V_5 ) ;
if ( ! V_78 -> V_156 )
goto V_46;
F_21 ( V_3 , L_18 , V_123 ,
( unsigned long long ) V_78 -> V_156 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_54 ( V_3 , & V_78 -> V_54 [ V_8 ] ) ;
F_19 ( & V_78 -> V_54 [ V_8 ] . V_158 ) ;
F_19 ( & V_78 -> V_54 [ V_8 ] . V_155 ) ;
}
V_78 -> V_54 [ 0 ] . V_30 = F_18 ( V_3 , 2 , 1 , V_159 , V_5 ) ;
if ( ! V_78 -> V_54 [ 0 ] . V_30 )
goto V_46;
V_78 -> V_53 = F_2 (
sizeof( struct V_29 * ) * V_52 ,
V_5 ) ;
if ( ! V_78 -> V_53 )
goto V_46;
V_78 -> V_51 = 0 ;
F_67 ( & V_78 -> V_160 ) ;
F_19 ( & V_78 -> V_161 ) ;
V_78 -> V_145 = V_145 ;
V_3 -> V_152 -> V_153 [ V_123 ] = F_9 ( V_78 -> V_157 -> V_7 ) ;
F_21 ( V_3 , L_19 ,
V_123 ,
& V_3 -> V_152 -> V_153 [ V_123 ] ,
F_68 ( V_3 -> V_152 -> V_153 [ V_123 ] ) ) ;
return 1 ;
V_46:
F_62 ( V_3 , V_123 ) ;
return 0 ;
}
void F_69 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_47 * V_48 ;
struct V_69 * V_162 ;
struct V_29 * V_163 ;
V_48 = V_3 -> V_151 [ V_145 -> V_123 ] ;
V_162 = F_31 ( V_3 , V_48 -> V_156 , 0 ) ;
V_163 = V_48 -> V_54 [ 0 ] . V_30 ;
V_162 -> V_118 = F_9 ( F_52 ( V_163 -> V_33 ,
V_163 -> V_38 )
| V_163 -> V_4 ) ;
}
static T_3 F_70 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_134 * V_164 ;
struct V_165 * V_166 ;
if ( V_145 -> V_167 == V_168 )
V_166 = V_3 -> V_169 ;
else
V_166 = V_3 -> V_170 ;
for ( V_164 = V_145 ; V_164 -> V_171 && V_164 -> V_171 -> V_171 ;
V_164 = V_164 -> V_171 )
;
return F_71 ( V_166 , V_164 -> V_172 ) ;
}
int F_72 ( struct V_2 * V_3 , struct V_134 * V_145 )
{
struct V_47 * V_78 ;
struct V_69 * V_162 ;
struct V_68 * V_173 ;
T_3 V_174 ;
T_3 V_175 ;
struct V_134 * V_164 ;
V_78 = V_3 -> V_151 [ V_145 -> V_123 ] ;
if ( V_145 -> V_123 == 0 || ! V_78 ) {
F_64 ( V_3 , L_20 ,
V_145 -> V_123 ) ;
return - V_176 ;
}
V_162 = F_31 ( V_3 , V_78 -> V_156 , 0 ) ;
V_173 = F_30 ( V_3 , V_78 -> V_156 ) ;
V_173 -> V_177 |= F_13 ( F_73 ( 1 ) | V_145 -> V_178 ) ;
switch ( V_145 -> V_167 ) {
case V_168 :
V_173 -> V_177 |= F_13 ( V_179 ) ;
V_175 = F_74 ( 512 ) ;
break;
case V_180 :
V_173 -> V_177 |= F_13 ( V_181 ) ;
V_175 = F_74 ( 64 ) ;
break;
case V_182 :
V_173 -> V_177 |= F_13 ( V_183 ) ;
V_175 = F_74 ( 64 ) ;
break;
case V_184 :
V_173 -> V_177 |= F_13 ( V_185 ) ;
V_175 = F_74 ( 8 ) ;
break;
case V_186 :
F_21 ( V_3 , L_21 ) ;
return - V_176 ;
break;
default:
return - V_176 ;
}
V_174 = F_70 ( V_3 , V_145 ) ;
if ( ! V_174 )
return - V_176 ;
V_173 -> V_187 |= F_13 ( F_75 ( V_174 ) ) ;
for ( V_164 = V_145 ; V_164 -> V_171 && V_164 -> V_171 -> V_171 ;
V_164 = V_164 -> V_171 )
;
V_78 -> V_188 = V_164 -> V_172 ;
V_78 -> V_129 = V_174 ;
F_21 ( V_3 , L_22 , V_174 ) ;
F_21 ( V_3 , L_23 , V_78 -> V_188 ) ;
if ( ! V_145 -> V_137 || ! V_145 -> V_137 -> V_189 -> V_171 ) {
V_78 -> V_143 = & V_3 -> V_131 [ V_174 - 1 ] . V_143 ;
} else {
struct V_190 * V_131 ;
struct V_126 * V_191 ;
V_131 = & V_3 -> V_131 [ V_174 - 1 ] ;
F_76 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_191 -> V_123 != V_145 -> V_137 -> V_189 -> V_123 )
continue;
if ( ! V_78 -> V_145 -> V_137 -> V_140 ||
( V_145 -> V_137 -> V_140 &&
V_191 -> V_146 == V_78 -> V_145 -> V_146 ) ) {
V_78 -> V_143 = & V_191 -> V_143 ;
V_78 -> V_127 = V_191 ;
break;
}
}
if ( ! V_78 -> V_127 )
F_64 ( V_3 , L_24 ) ;
}
if ( V_145 -> V_137 && V_145 -> V_137 -> V_189 -> V_171 ) {
V_173 -> V_127 = F_13 ( V_145 -> V_137 -> V_189 -> V_123 |
( V_145 -> V_146 << 8 ) ) ;
if ( V_145 -> V_137 -> V_140 )
V_173 -> V_177 |= F_13 ( V_192 ) ;
}
F_21 ( V_3 , L_25 , V_145 -> V_137 ) ;
F_21 ( V_3 , L_26 , V_145 -> V_146 ) ;
V_162 -> V_193 = F_13 ( F_77 ( V_194 ) ) ;
V_162 -> V_193 |= F_13 ( F_78 ( 0 ) | F_79 ( 3 ) |
V_175 ) ;
V_162 -> V_118 = F_9 ( V_78 -> V_54 [ 0 ] . V_30 -> V_37 -> V_7 |
V_78 -> V_54 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_80 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
unsigned int V_196 ;
V_196 = F_81 ( V_84 -> V_197 . V_198 , 1 , 16 ) - 1 ;
if ( V_196 != V_84 -> V_197 . V_198 - 1 )
F_82 ( & V_145 -> V_78 ,
L_27 ,
V_84 -> V_197 . V_199 ,
1 << V_196 ,
V_145 -> V_167 == V_182 ? L_4 : L_28 ) ;
if ( V_145 -> V_167 == V_182 ) {
V_196 += 3 ;
}
return V_196 ;
}
static unsigned int F_83 ( struct V_134 * V_145 ,
struct V_195 * V_84 , unsigned int V_200 ,
unsigned int V_201 , unsigned int V_202 )
{
unsigned int V_196 ;
V_196 = F_49 ( V_200 ) - 1 ;
V_196 = F_81 ( V_196 , V_201 , V_202 ) ;
if ( ( 1 << V_196 ) != V_200 )
F_82 ( & V_145 -> V_78 ,
L_29 ,
V_84 -> V_197 . V_199 ,
1 << V_196 ,
V_200 ) ;
return V_196 ;
}
static unsigned int F_84 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
if ( V_84 -> V_197 . V_198 == 0 )
return 0 ;
return F_83 ( V_145 , V_84 ,
V_84 -> V_197 . V_198 , 0 , 15 ) ;
}
static unsigned int F_85 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
return F_83 ( V_145 , V_84 ,
V_84 -> V_197 . V_198 * 8 , 3 , 10 ) ;
}
static unsigned int F_86 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
unsigned int V_196 = 0 ;
switch ( V_145 -> V_167 ) {
case V_180 :
if ( F_87 ( & V_84 -> V_197 ) ||
F_88 ( & V_84 -> V_197 ) ) {
V_196 = F_84 ( V_145 , V_84 ) ;
break;
}
case V_168 :
if ( F_89 ( & V_84 -> V_197 ) ||
F_90 ( & V_84 -> V_197 ) ) {
V_196 = F_80 ( V_145 , V_84 ) ;
}
break;
case V_182 :
if ( F_90 ( & V_84 -> V_197 ) ) {
V_196 = F_80 ( V_145 , V_84 ) ;
break;
}
case V_184 :
if ( F_89 ( & V_84 -> V_197 ) ||
F_90 ( & V_84 -> V_197 ) ) {
V_196 = F_85 ( V_145 , V_84 ) ;
}
break;
default:
F_91 () ;
}
return F_92 ( V_196 ) ;
}
static T_3 F_93 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
if ( V_145 -> V_167 != V_168 ||
! F_90 ( & V_84 -> V_197 ) )
return 0 ;
return V_84 -> V_203 . V_204 ;
}
static T_3 F_94 ( struct V_134 * V_145 ,
struct V_195 * V_84 )
{
int V_205 ;
T_3 type ;
V_205 = F_95 ( & V_84 -> V_197 ) ;
if ( F_87 ( & V_84 -> V_197 ) ) {
type = F_77 ( V_194 ) ;
} else if ( F_88 ( & V_84 -> V_197 ) ) {
if ( V_205 )
type = F_77 ( V_206 ) ;
else
type = F_77 ( V_207 ) ;
} else if ( F_90 ( & V_84 -> V_197 ) ) {
if ( V_205 )
type = F_77 ( V_208 ) ;
else
type = F_77 ( V_209 ) ;
} else if ( F_89 ( & V_84 -> V_197 ) ) {
if ( V_205 )
type = F_77 ( V_210 ) ;
else
type = F_77 ( V_211 ) ;
} else {
type = 0 ;
}
return type ;
}
static T_3 F_96 ( struct V_2 * V_3 ,
struct V_134 * V_145 ,
struct V_195 * V_84 )
{
int V_212 ;
int V_213 ;
if ( F_87 ( & V_84 -> V_197 ) ||
F_88 ( & V_84 -> V_197 ) )
return 0 ;
if ( V_145 -> V_167 == V_168 )
return F_97 ( V_84 -> V_203 . V_214 ) ;
V_213 = F_98 ( F_99 ( & V_84 -> V_197 ) ) ;
V_212 = ( F_99 ( & V_84 -> V_197 ) & 0x1800 ) >> 11 ;
return V_213 * ( V_212 + 1 ) ;
}
int F_100 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_134 * V_145 ,
struct V_195 * V_84 ,
T_1 V_82 )
{
unsigned int V_49 ;
struct V_69 * V_112 ;
struct V_29 * V_163 ;
unsigned int V_213 ;
unsigned int V_212 ;
enum V_19 type ;
T_3 V_215 ;
T_3 V_216 ;
V_49 = F_101 ( & V_84 -> V_197 ) ;
V_112 = F_31 ( V_3 , V_48 -> V_156 , V_49 ) ;
V_216 = F_94 ( V_145 , V_84 ) ;
if ( ! V_216 )
return - V_176 ;
V_112 -> V_193 = F_13 ( V_216 ) ;
type = F_102 ( & V_84 -> V_197 ) ;
V_48 -> V_54 [ V_49 ] . V_217 =
F_18 ( V_3 , 2 , 1 , type , V_82 ) ;
if ( ! V_48 -> V_54 [ V_49 ] . V_217 ) {
if ( V_48 -> V_51 == 0 )
return - V_43 ;
V_48 -> V_54 [ V_49 ] . V_217 =
V_48 -> V_53 [ V_48 -> V_51 ] ;
V_48 -> V_53 [ V_48 -> V_51 ] = NULL ;
V_48 -> V_51 -- ;
F_22 ( V_3 , V_48 -> V_54 [ V_49 ] . V_217 ,
1 , type ) ;
}
V_48 -> V_54 [ V_49 ] . V_218 = false ;
V_163 = V_48 -> V_54 [ V_49 ] . V_217 ;
V_112 -> V_118 = F_9 ( V_163 -> V_37 -> V_7 | V_163 -> V_4 ) ;
V_112 -> V_115 = F_13 ( F_86 ( V_145 , V_84 )
| F_103 ( F_93 ( V_145 , V_84 ) ) ) ;
if ( ! F_90 ( & V_84 -> V_197 ) )
V_112 -> V_193 |= F_13 ( F_79 ( 3 ) ) ;
else
V_112 -> V_193 |= F_13 ( F_79 ( 0 ) ) ;
V_213 = F_98 ( F_99 ( & V_84 -> V_197 ) ) ;
V_212 = 0 ;
switch ( V_145 -> V_167 ) {
case V_168 :
V_212 = V_84 -> V_203 . V_219 ;
break;
case V_180 :
if ( F_88 ( & V_84 -> V_197 ) )
V_213 = 512 ;
if ( F_90 ( & V_84 -> V_197 ) ||
F_89 ( & V_84 -> V_197 ) ) {
V_212 = ( F_99 ( & V_84 -> V_197 )
& 0x1800 ) >> 11 ;
}
break;
case V_182 :
case V_184 :
break;
default:
F_91 () ;
}
V_112 -> V_193 |= F_13 ( F_74 ( V_213 ) |
F_78 ( V_212 ) ) ;
V_215 = F_96 ( V_3 , V_145 , V_84 ) ;
V_112 -> V_220 = F_13 ( F_104 ( V_215 ) ) ;
if ( F_87 ( & V_84 -> V_197 ) && V_3 -> V_221 == 0x100 )
V_112 -> V_220 |= F_13 ( F_105 ( 8 ) ) ;
else
V_112 -> V_220 |=
F_13 ( F_105 ( V_215 ) ) ;
return 0 ;
}
void F_106 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_195 * V_84 )
{
unsigned int V_49 ;
struct V_69 * V_112 ;
V_49 = F_101 ( & V_84 -> V_197 ) ;
V_112 = F_31 ( V_3 , V_48 -> V_156 , V_49 ) ;
V_112 -> V_115 = 0 ;
V_112 -> V_193 = 0 ;
V_112 -> V_118 = 0 ;
V_112 -> V_220 = 0 ;
}
void F_107 ( struct V_222 * V_223 )
{
V_223 -> V_224 = 0 ;
V_223 -> V_225 = 0 ;
V_223 -> V_226 = 0 ;
V_223 -> V_227 = 0 ;
V_223 -> type = 0 ;
V_223 -> V_215 = 0 ;
}
void F_108 ( struct V_2 * V_3 ,
struct V_59 * V_156 ,
struct V_67 * V_228 ,
struct V_47 * V_48 )
{
struct V_222 * V_223 ;
struct V_69 * V_112 ;
unsigned int V_229 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_223 = & V_48 -> V_54 [ V_8 ] . V_223 ;
if ( ! F_109 ( V_228 , V_8 ) && F_110 ( V_228 , V_8 ) ) {
F_107 ( V_223 ) ;
continue;
}
if ( F_109 ( V_228 , V_8 ) ) {
V_112 = F_31 ( V_3 , V_156 , V_8 ) ;
V_229 = F_111 ( F_10 ( V_112 -> V_193 ) ) ;
if ( V_229 != V_209 && V_229 != V_211 &&
V_229 != V_208 &&
V_229 != V_210 )
continue;
V_223 -> V_224 = F_112 (
F_10 ( V_112 -> V_115 ) ) ;
V_223 -> V_225 = F_113 (
F_10 ( V_112 -> V_115 ) ) + 1 ;
V_223 -> V_226 = F_114 (
F_10 ( V_112 -> V_193 ) ) + 1 ;
V_223 -> V_227 = F_115 (
F_10 ( V_112 -> V_193 ) ) ;
V_223 -> type = V_229 ;
V_223 -> V_215 = F_116 (
F_10 ( V_112 -> V_220 ) ) ;
}
}
}
void F_117 ( struct V_2 * V_3 ,
struct V_59 * V_156 ,
struct V_59 * V_157 ,
unsigned int V_49 )
{
struct V_69 * V_230 ;
struct V_69 * V_231 ;
V_230 = F_31 ( V_3 , V_157 , V_49 ) ;
V_231 = F_31 ( V_3 , V_156 , V_49 ) ;
V_231 -> V_115 = V_230 -> V_115 ;
V_231 -> V_193 = V_230 -> V_193 ;
V_231 -> V_118 = V_230 -> V_118 ;
V_231 -> V_220 = V_230 -> V_220 ;
}
void F_118 ( struct V_2 * V_3 ,
struct V_59 * V_156 ,
struct V_59 * V_157 )
{
struct V_68 * V_232 ;
struct V_68 * V_233 ;
V_232 = F_30 ( V_3 , V_156 ) ;
V_233 = F_30 ( V_3 , V_157 ) ;
V_232 -> V_177 = V_233 -> V_177 ;
V_232 -> V_187 = V_233 -> V_187 ;
V_232 -> V_127 = V_233 -> V_127 ;
V_232 -> V_234 = V_233 -> V_234 ;
}
static int F_119 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_235 * V_78 = F_34 ( V_3 ) -> V_75 . V_76 ;
int V_236 = F_120 ( V_3 -> V_237 ) ;
F_24 ( V_3 , V_238 ,
L_30 , V_236 ) ;
if ( ! V_236 )
return 0 ;
V_3 -> V_239 = F_2 ( sizeof( * V_3 -> V_239 ) , V_5 ) ;
if ( ! V_3 -> V_239 )
goto V_240;
V_3 -> V_239 -> V_241 = F_37 ( V_78 ,
V_236 * sizeof( T_4 ) ,
& V_3 -> V_239 -> V_242 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_241 )
goto V_243;
V_3 -> V_239 -> V_244 = F_2 ( sizeof( void * ) * V_236 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_244 )
goto V_245;
V_3 -> V_239 -> V_246 =
F_2 ( sizeof( T_2 ) * V_236 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_246 )
goto V_247;
V_3 -> V_152 -> V_153 [ 0 ] = F_9 ( V_3 -> V_239 -> V_242 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
T_2 V_7 ;
void * V_248 = F_37 ( V_78 , V_3 -> V_249 , & V_7 ,
V_5 ) ;
if ( ! V_248 )
goto V_250;
V_3 -> V_239 -> V_241 [ V_8 ] = V_7 ;
V_3 -> V_239 -> V_244 [ V_8 ] = V_248 ;
V_3 -> V_239 -> V_246 [ V_8 ] = V_7 ;
}
return 0 ;
V_250:
for ( V_8 = V_8 - 1 ; V_8 >= 0 ; V_8 -- ) {
F_35 ( V_78 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
V_247:
F_4 ( V_3 -> V_239 -> V_244 ) ;
V_245:
F_35 ( V_78 , V_236 * sizeof( T_4 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
V_243:
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
V_240:
return - V_43 ;
}
static void F_121 ( struct V_2 * V_3 )
{
int V_236 ;
int V_8 ;
struct V_73 * V_74 = F_33 ( F_34 ( V_3 ) -> V_75 . V_76 ) ;
if ( ! V_3 -> V_239 )
return;
V_236 = F_120 ( V_3 -> V_237 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
F_35 ( & V_74 -> V_78 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
F_4 ( V_3 -> V_239 -> V_244 ) ;
F_35 ( & V_74 -> V_78 , V_236 * sizeof( T_4 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
}
struct V_251 * F_42 ( struct V_2 * V_3 ,
bool V_252 , bool V_253 ,
T_1 V_82 )
{
struct V_251 * V_254 ;
V_254 = F_2 ( sizeof( * V_254 ) , V_82 ) ;
if ( ! V_254 )
return NULL ;
if ( V_252 ) {
V_254 -> V_156 =
F_25 ( V_3 , V_62 ,
V_82 ) ;
if ( ! V_254 -> V_156 ) {
F_4 ( V_254 ) ;
return NULL ;
}
}
if ( V_253 ) {
V_254 -> V_255 =
F_2 ( sizeof( struct V_255 ) , V_82 ) ;
if ( ! V_254 -> V_255 ) {
F_28 ( V_3 , V_254 -> V_156 ) ;
F_4 ( V_254 ) ;
return NULL ;
}
F_67 ( V_254 -> V_255 ) ;
}
V_254 -> V_256 = 0 ;
F_19 ( & V_254 -> V_161 ) ;
return V_254 ;
}
void F_122 ( struct V_2 * V_3 , struct V_257 * V_257 )
{
if ( V_257 ) {
F_4 ( V_257 -> V_258 [ 0 ] ) ;
F_4 ( V_257 ) ;
}
}
void F_47 ( struct V_2 * V_3 ,
struct V_251 * V_254 )
{
F_28 ( V_3 ,
V_254 -> V_156 ) ;
F_4 ( V_254 -> V_255 ) ;
F_4 ( V_254 ) ;
}
void F_123 ( struct V_2 * V_3 )
{
struct V_73 * V_74 = F_33 ( F_34 ( V_3 ) -> V_75 . V_76 ) ;
struct V_177 * V_177 , * V_16 ;
struct V_259 * V_260 , * V_261 ;
unsigned long V_5 ;
int V_63 ;
int V_8 , V_139 , V_138 ;
V_63 = sizeof( struct V_262 ) * ( V_3 -> V_263 . V_264 ) ;
if ( V_3 -> V_263 . V_265 )
F_35 ( & V_74 -> V_78 , V_63 ,
V_3 -> V_263 . V_265 , V_3 -> V_263 . V_266 ) ;
V_3 -> V_263 . V_265 = NULL ;
F_24 ( V_3 , V_238 , L_31 ) ;
if ( V_3 -> V_267 )
F_15 ( V_3 , V_3 -> V_267 ) ;
V_3 -> V_267 = NULL ;
F_24 ( V_3 , V_238 , L_32 ) ;
if ( V_3 -> V_268 )
F_47 ( V_3 , V_3 -> V_268 ) ;
V_3 -> V_99 = 0 ;
if ( V_3 -> V_269 )
F_15 ( V_3 , V_3 -> V_269 ) ;
V_3 -> V_269 = NULL ;
F_24 ( V_3 , V_238 , L_33 ) ;
F_58 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_59 ( & V_260 -> V_270 ) ;
F_4 ( V_260 ) ;
}
for ( V_8 = 1 ; V_8 < V_271 ; ++ V_8 )
F_62 ( V_3 , V_8 ) ;
if ( V_3 -> V_10 )
F_124 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_24 ( V_3 , V_238 , L_34 ) ;
if ( V_3 -> V_66 )
F_124 ( V_3 -> V_66 ) ;
V_3 -> V_66 = NULL ;
F_24 ( V_3 , V_238 , L_35 ) ;
if ( V_3 -> V_80 )
F_124 ( V_3 -> V_80 ) ;
V_3 -> V_80 = NULL ;
F_24 ( V_3 , V_238 ,
L_36 ) ;
if ( V_3 -> V_81 )
F_124 ( V_3 -> V_81 ) ;
V_3 -> V_81 = NULL ;
F_24 ( V_3 , V_238 ,
L_37 ) ;
if ( V_3 -> V_152 )
F_35 ( & V_74 -> V_78 , sizeof( * V_3 -> V_152 ) ,
V_3 -> V_152 , V_3 -> V_152 -> V_7 ) ;
V_3 -> V_152 = NULL ;
F_121 ( V_3 ) ;
F_125 ( & V_3 -> V_272 , V_5 ) ;
F_58 (dev_info, next, &xhci->lpm_failed_devs, list) {
F_59 ( & V_177 -> V_273 ) ;
F_4 ( V_177 ) ;
}
F_126 ( & V_3 -> V_272 , V_5 ) ;
if ( ! V_3 -> V_131 )
goto V_274;
V_138 = F_57 ( V_3 -> V_130 ) ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
struct V_142 * V_275 = & V_3 -> V_131 [ V_8 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ ) {
struct V_124 * V_84 = & V_275 -> V_148 [ V_139 ] . V_149 ;
while ( ! F_63 ( V_84 ) )
F_127 ( V_84 -> V_16 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
struct V_126 * V_137 , * V_276 ;
F_58 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_59 ( & V_137 -> V_133 ) ;
F_4 ( V_137 ) ;
}
}
V_274:
V_3 -> V_277 = 0 ;
V_3 -> V_278 = 0 ;
V_3 -> V_279 = 0 ;
F_4 ( V_3 -> V_280 ) ;
F_4 ( V_3 -> V_281 ) ;
F_4 ( V_3 -> V_282 ) ;
F_4 ( V_3 -> V_131 ) ;
F_4 ( V_3 -> V_283 ) ;
V_3 -> V_249 = 0 ;
V_3 -> V_284 = 0 ;
V_3 -> V_285 [ 0 ] . V_286 = 0 ;
V_3 -> V_285 [ 1 ] . V_286 = 0 ;
}
static int F_128 ( struct V_2 * V_3 ,
struct V_1 * V_287 ,
union V_55 * V_288 ,
union V_55 * V_289 ,
T_2 V_290 ,
struct V_1 * V_291 ,
char * V_292 , int V_293 )
{
unsigned long long V_294 ;
unsigned long long V_295 ;
struct V_1 * V_6 ;
V_294 = F_52 ( V_287 , V_288 ) ;
V_295 = F_52 ( V_287 , V_289 ) ;
V_6 = F_129 ( V_287 , V_288 , V_289 , V_290 ) ;
if ( V_6 != V_291 ) {
F_64 ( V_3 , L_38 ,
V_292 , V_293 ) ;
F_64 ( V_3 , L_39
L_40 ,
V_287 ,
( unsigned long long ) V_290 ) ;
F_64 ( V_3 , L_41
L_42 ,
V_288 , V_294 ,
V_289 , V_295 ) ;
F_64 ( V_3 , L_43 ,
V_291 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , T_1 V_82 )
{
struct {
T_2 V_290 ;
struct V_1 * V_291 ;
} V_296 [] = {
{ 0 , NULL } ,
{ V_3 -> V_267 -> V_37 -> V_7 - 16 , NULL } ,
{ V_3 -> V_267 -> V_37 -> V_7 - 1 , NULL } ,
{ V_3 -> V_267 -> V_37 -> V_7 , V_3 -> V_267 -> V_37 } ,
{ V_3 -> V_267 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 ,
V_3 -> V_267 -> V_37 } ,
{ V_3 -> V_267 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_267 -> V_37 -> V_7 + ( V_12 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_287 ;
union V_55 * V_288 ;
union V_55 * V_289 ;
T_2 V_290 ;
struct V_1 * V_291 ;
} V_297 [] = {
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = V_3 -> V_267 -> V_37 -> V_9 ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_290 = V_3 -> V_269 -> V_37 -> V_7 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = V_3 -> V_267 -> V_37 -> V_9 ,
. V_289 = & V_3 -> V_269 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_290 = V_3 -> V_269 -> V_37 -> V_7 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = V_3 -> V_269 -> V_37 -> V_9 ,
. V_289 = & V_3 -> V_269 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_290 = V_3 -> V_269 -> V_37 -> V_7 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = & V_3 -> V_267 -> V_37 -> V_9 [ 0 ] ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ 3 ] ,
. V_290 = V_3 -> V_267 -> V_37 -> V_7 + 4 * 16 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = & V_3 -> V_267 -> V_37 -> V_9 [ 3 ] ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ 6 ] ,
. V_290 = V_3 -> V_267 -> V_37 -> V_7 + 2 * 16 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ 1 ] ,
. V_290 = V_3 -> V_267 -> V_37 -> V_7 + 2 * 16 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ 1 ] ,
. V_290 = V_3 -> V_267 -> V_37 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_291 = NULL ,
} ,
{ . V_287 = V_3 -> V_267 -> V_37 ,
. V_288 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_289 = & V_3 -> V_267 -> V_37 -> V_9 [ 1 ] ,
. V_290 = V_3 -> V_269 -> V_37 -> V_7 + 2 * 16 ,
. V_291 = NULL ,
} ,
} ;
unsigned int V_298 ;
int V_8 , V_44 ;
V_298 = F_131 ( V_296 ) ;
for ( V_8 = 0 ; V_8 < V_298 ; V_8 ++ ) {
V_44 = F_128 ( V_3 ,
V_3 -> V_267 -> V_37 ,
V_3 -> V_267 -> V_37 -> V_9 ,
& V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
V_296 [ V_8 ] . V_290 ,
V_296 [ V_8 ] . V_291 ,
L_44 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_298 = F_131 ( V_297 ) ;
for ( V_8 = 0 ; V_8 < V_298 ; V_8 ++ ) {
V_44 = F_128 ( V_3 ,
V_297 [ V_8 ] . V_287 ,
V_297 [ V_8 ] . V_288 ,
V_297 [ V_8 ] . V_289 ,
V_297 [ V_8 ] . V_290 ,
V_297 [ V_8 ] . V_291 ,
L_45 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_21 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
T_4 V_299 ;
T_2 V_118 ;
V_118 = F_52 ( V_3 -> V_267 -> V_40 ,
V_3 -> V_267 -> V_39 ) ;
if ( V_118 == 0 && ! F_133 () )
F_64 ( V_3 , L_47
L_48 ) ;
V_299 = F_134 ( V_3 , & V_3 -> V_300 -> V_301 ) ;
V_299 &= V_302 ;
V_299 &= ~ V_303 ;
F_24 ( V_3 , V_238 ,
L_49
L_50 ) ;
F_135 ( V_3 , ( ( T_4 ) V_118 & ( T_4 ) ~ V_302 ) | V_299 ,
& V_3 -> V_300 -> V_301 ) ;
}
static void F_136 ( struct V_2 * V_3 , unsigned int V_138 ,
T_5 T_6 * V_98 , T_7 V_304 , int V_305 )
{
T_3 V_299 , V_306 , V_307 ;
int V_8 ;
if ( V_304 > 0x03 ) {
F_64 ( V_3 , L_51
L_52 ,
V_98 , V_304 ) ;
return;
}
V_299 = F_137 ( V_3 , V_98 + 2 ) ;
V_306 = F_138 ( V_299 ) ;
V_307 = F_139 ( V_299 ) ;
F_24 ( V_3 , V_238 ,
L_53
L_54 ,
V_98 , V_306 , V_307 , V_304 ) ;
if ( V_306 == 0 || ( V_306 + V_307 - 1 ) > V_138 )
return;
if ( V_304 < 0x03 && V_3 -> V_308 < V_305 )
V_3 -> V_283 [ V_3 -> V_308 ++ ] = V_299 ;
if ( ( V_3 -> V_221 == 0x96 ) && ( V_304 != 0x03 ) &&
( V_299 & V_309 ) ) {
F_24 ( V_3 , V_238 ,
L_55 ) ;
V_3 -> V_310 = 1 ;
}
if ( ( V_3 -> V_221 >= 0x100 ) && ( V_304 != 0x03 ) ) {
F_24 ( V_3 , V_238 ,
L_56 ) ;
V_3 -> V_310 = 1 ;
if ( V_299 & V_311 ) {
F_24 ( V_3 , V_238 ,
L_57 ) ;
V_3 -> V_312 = 1 ;
}
}
V_306 -- ;
for ( V_8 = V_306 ; V_8 < ( V_306 + V_307 ) ; V_8 ++ ) {
if ( V_3 -> V_282 [ V_8 ] != 0 ) {
F_64 ( V_3 , L_58
L_59 , V_98 , V_8 ) ;
F_64 ( V_3 , L_60
L_61 ,
V_3 -> V_282 [ V_8 ] , V_304 ) ;
if ( V_3 -> V_282 [ V_8 ] != V_304 &&
V_3 -> V_282 [ V_8 ] != V_313 ) {
if ( V_3 -> V_282 [ V_8 ] == 0x03 )
V_3 -> V_278 -- ;
else
V_3 -> V_277 -- ;
V_3 -> V_282 [ V_8 ] = V_313 ;
}
continue;
}
V_3 -> V_282 [ V_8 ] = V_304 ;
if ( V_304 == 0x03 )
V_3 -> V_278 ++ ;
else
V_3 -> V_277 ++ ;
}
}
static int F_140 ( struct V_2 * V_3 , T_1 V_5 )
{
T_5 T_6 * V_98 , * V_314 ;
T_3 V_315 , V_316 ;
unsigned int V_138 ;
int V_8 , V_139 , V_317 ;
int V_318 = 0 ;
V_98 = & V_3 -> V_319 -> V_64 ;
V_315 = F_141 ( F_137 ( V_3 , V_98 ) ) ;
if ( V_315 == 0 ) {
F_142 ( V_3 , L_62
L_63 ) ;
return - V_320 ;
}
V_138 = F_57 ( V_3 -> V_130 ) ;
V_3 -> V_282 = F_2 ( sizeof( * V_3 -> V_282 ) * V_138 , V_5 ) ;
if ( ! V_3 -> V_282 )
return - V_43 ;
V_3 -> V_131 = F_2 ( sizeof( * V_3 -> V_131 ) * V_138 , V_5 ) ;
if ( ! V_3 -> V_131 )
return - V_43 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
struct V_142 * V_143 ;
F_19 ( & V_3 -> V_131 [ V_8 ] . V_132 ) ;
V_143 = & V_3 -> V_131 [ V_8 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_19 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
V_98 = & V_3 -> V_319 -> V_321 + V_315 ;
V_314 = V_98 ;
V_316 = V_315 ;
do {
T_3 V_322 ;
V_322 = F_137 ( V_3 , V_314 ) ;
if ( F_143 ( V_322 ) == V_323 )
V_318 ++ ;
V_316 = F_144 ( V_322 ) ;
V_314 += V_316 ;
} while ( V_316 );
V_3 -> V_283 = F_2 ( sizeof( * V_3 -> V_283 ) * V_318 , V_5 ) ;
if ( ! V_3 -> V_283 )
return - V_43 ;
while ( 1 ) {
T_3 V_322 ;
V_322 = F_137 ( V_3 , V_98 ) ;
if ( F_143 ( V_322 ) == V_323 )
F_136 ( V_3 , V_138 , V_98 ,
( T_7 ) F_145 ( V_322 ) ,
V_318 ) ;
V_315 = F_144 ( V_322 ) ;
if ( ! V_315 || ( V_3 -> V_277 + V_3 -> V_278 )
== V_138 )
break;
V_98 += V_315 ;
}
if ( V_3 -> V_277 == 0 && V_3 -> V_278 == 0 ) {
F_64 ( V_3 , L_64 ) ;
return - V_320 ;
}
F_24 ( V_3 , V_238 ,
L_65 ,
V_3 -> V_277 , V_3 -> V_278 ) ;
if ( V_3 -> V_278 > 15 ) {
F_24 ( V_3 , V_238 ,
L_66 ) ;
V_3 -> V_278 = 15 ;
}
if ( V_3 -> V_277 > V_324 ) {
F_24 ( V_3 , V_238 ,
L_67 ,
V_324 ) ;
V_3 -> V_277 = V_324 ;
}
if ( V_3 -> V_277 ) {
V_3 -> V_280 = F_146 ( sizeof( * V_3 -> V_280 ) *
V_3 -> V_277 , V_5 ) ;
if ( ! V_3 -> V_280 )
return - V_43 ;
V_317 = 0 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
if ( V_3 -> V_282 [ V_8 ] == 0x03 ||
V_3 -> V_282 [ V_8 ] == 0 ||
V_3 -> V_282 [ V_8 ] == V_313 )
continue;
V_3 -> V_280 [ V_317 ] =
& V_3 -> V_325 -> V_326 +
V_327 * V_8 ;
F_24 ( V_3 , V_238 ,
L_68
L_69 , V_8 ,
V_3 -> V_280 [ V_317 ] ) ;
V_317 ++ ;
if ( V_317 == V_3 -> V_277 )
break;
}
}
if ( V_3 -> V_278 ) {
V_3 -> V_281 = F_146 ( sizeof( * V_3 -> V_281 ) *
V_3 -> V_278 , V_5 ) ;
if ( ! V_3 -> V_281 )
return - V_43 ;
V_317 = 0 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ )
if ( V_3 -> V_282 [ V_8 ] == 0x03 ) {
V_3 -> V_281 [ V_317 ] =
& V_3 -> V_325 -> V_326 +
V_327 * V_8 ;
F_24 ( V_3 , V_238 ,
L_70
L_69 , V_8 ,
V_3 -> V_281 [ V_317 ] ) ;
V_317 ++ ;
if ( V_317 == V_3 -> V_278 )
break;
}
}
return 0 ;
}
int F_147 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_235 * V_78 = F_34 ( V_3 ) -> V_75 . V_76 ;
unsigned int V_20 , V_328 ;
T_4 V_329 ;
struct V_1 * V_6 ;
T_3 V_249 , V_299 ;
int V_8 ;
F_19 ( & V_3 -> V_330 ) ;
F_19 ( & V_3 -> V_270 ) ;
V_249 = F_137 ( V_3 , & V_3 -> V_325 -> V_249 ) ;
F_24 ( V_3 , V_238 ,
L_71 , V_249 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_249 ) != 0 )
break;
V_249 = V_249 >> 1 ;
}
if ( V_8 < 16 )
F_24 ( V_3 , V_238 ,
L_72 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_64 ( V_3 , L_73 ) ;
V_3 -> V_284 = 12 ;
V_3 -> V_249 = 1 << V_3 -> V_284 ;
F_24 ( V_3 , V_238 ,
L_74 , V_3 -> V_249 / 1024 ) ;
V_20 = F_148 ( F_137 ( V_3 , & V_3 -> V_319 -> V_130 ) ) ;
F_24 ( V_3 , V_238 ,
L_75 , V_20 ) ;
V_328 = F_137 ( V_3 , & V_3 -> V_325 -> V_331 ) ;
V_20 |= ( V_328 & ~ V_332 ) ;
F_24 ( V_3 , V_238 ,
L_76 , V_20 ) ;
F_149 ( V_3 , V_20 , & V_3 -> V_325 -> V_331 ) ;
V_3 -> V_152 = F_37 ( V_78 , sizeof( * V_3 -> V_152 ) , & V_7 ,
V_333 ) ;
if ( ! V_3 -> V_152 )
goto V_46;
memset ( V_3 -> V_152 , 0 , sizeof *( V_3 -> V_152 ) ) ;
V_3 -> V_152 -> V_7 = V_7 ;
F_24 ( V_3 , V_238 ,
L_77 ,
( unsigned long long ) V_3 -> V_152 -> V_7 , V_3 -> V_152 ) ;
F_135 ( V_3 , V_7 , & V_3 -> V_325 -> V_334 ) ;
V_3 -> V_10 = F_150 ( L_78 , V_78 ,
V_11 , 64 , V_3 -> V_249 ) ;
V_3 -> V_66 = F_150 ( L_79 , V_78 ,
2112 , 64 , V_3 -> V_249 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_66 )
goto V_46;
V_3 -> V_80 =
F_150 ( L_80 ,
V_78 , V_79 , 16 , 0 ) ;
V_3 -> V_81 =
F_150 ( L_81 ,
V_78 , V_77 , 16 , 0 ) ;
if ( ! V_3 -> V_80 || ! V_3 -> V_81 )
goto V_46;
V_3 -> V_269 = F_18 ( V_3 , 1 , 1 , V_335 , V_5 ) ;
if ( ! V_3 -> V_269 )
goto V_46;
F_24 ( V_3 , V_238 ,
L_82 , V_3 -> V_269 ) ;
F_24 ( V_3 , V_238 , L_83 ,
( unsigned long long ) V_3 -> V_269 -> V_37 -> V_7 ) ;
V_329 = F_134 ( V_3 , & V_3 -> V_325 -> V_269 ) ;
V_329 = ( V_329 & ( T_4 ) V_336 ) |
( V_3 -> V_269 -> V_37 -> V_7 & ( T_4 ) ~ V_336 ) |
V_3 -> V_269 -> V_4 ;
F_24 ( V_3 , V_238 ,
L_84 , V_20 ) ;
F_135 ( V_3 , V_329 , & V_3 -> V_325 -> V_269 ) ;
F_151 ( V_3 ) ;
V_3 -> V_268 = F_42 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_268 )
goto V_46;
V_3 -> V_99 ++ ;
V_20 = F_137 ( V_3 , & V_3 -> V_319 -> V_337 ) ;
V_20 &= V_338 ;
F_24 ( V_3 , V_238 ,
L_85
L_86 , V_20 ) ;
V_3 -> V_339 = ( void T_6 * ) V_3 -> V_319 + V_20 ;
F_152 ( V_3 ) ;
F_153 ( V_3 ) ;
V_3 -> V_300 = & V_3 -> V_340 -> V_300 [ 0 ] ;
F_24 ( V_3 , V_238 , L_87 ) ;
V_3 -> V_267 = F_18 ( V_3 , V_341 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_267 )
goto V_46;
if ( F_130 ( V_3 , V_5 ) < 0 )
goto V_46;
V_3 -> V_263 . V_265 = F_37 ( V_78 ,
sizeof( struct V_262 ) * V_341 , & V_7 ,
V_333 ) ;
if ( ! V_3 -> V_263 . V_265 )
goto V_46;
F_24 ( V_3 , V_238 ,
L_88 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_263 . V_265 , 0 , sizeof( struct V_262 ) * V_341 ) ;
V_3 -> V_263 . V_264 = V_341 ;
V_3 -> V_263 . V_266 = V_7 ;
F_24 ( V_3 , V_238 ,
L_89 ,
V_3 -> V_263 . V_264 ,
V_3 -> V_263 . V_265 ,
( unsigned long long ) V_3 -> V_263 . V_266 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_267 -> V_37 ; V_20 < V_341 ; V_20 ++ ) {
struct V_262 * V_342 = & V_3 -> V_263 . V_265 [ V_20 ] ;
V_342 -> V_343 = F_9 ( V_6 -> V_7 ) ;
V_342 -> V_344 = F_13 ( V_12 ) ;
V_342 -> V_345 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_137 ( V_3 , & V_3 -> V_300 -> V_346 ) ;
V_20 &= V_347 ;
V_20 |= V_341 ;
F_24 ( V_3 , V_238 ,
L_90 ,
V_20 ) ;
F_149 ( V_3 , V_20 , & V_3 -> V_300 -> V_346 ) ;
F_24 ( V_3 , V_238 ,
L_91 ) ;
F_24 ( V_3 , V_238 ,
L_92 ,
( unsigned long long ) V_3 -> V_263 . V_266 ) ;
V_329 = F_134 ( V_3 , & V_3 -> V_300 -> V_348 ) ;
V_329 &= V_302 ;
V_329 |= ( V_3 -> V_263 . V_266 & ( T_4 ) ~ V_302 ) ;
F_135 ( V_3 , V_329 , & V_3 -> V_300 -> V_348 ) ;
F_132 ( V_3 ) ;
F_24 ( V_3 , V_238 ,
L_93 ) ;
F_154 ( V_3 , 0 ) ;
F_67 ( & V_3 -> V_349 ) ;
for ( V_8 = 0 ; V_8 < V_271 ; ++ V_8 )
V_3 -> V_151 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_324 ; ++ V_8 ) {
V_3 -> V_285 [ 0 ] . V_350 [ V_8 ] = 0 ;
V_3 -> V_285 [ 1 ] . V_350 [ V_8 ] = 0 ;
F_67 ( & V_3 -> V_285 [ 1 ] . V_351 [ V_8 ] ) ;
}
if ( F_119 ( V_3 , V_5 ) )
goto V_46;
if ( F_140 ( V_3 , V_5 ) )
goto V_46;
V_299 = F_137 ( V_3 , & V_3 -> V_325 -> V_352 ) ;
V_299 &= ~ V_353 ;
V_299 |= V_354 ;
F_149 ( V_3 , V_299 , & V_3 -> V_325 -> V_352 ) ;
return 0 ;
V_46:
F_64 ( V_3 , L_94 ) ;
F_155 ( V_3 ) ;
F_156 ( V_3 ) ;
F_123 ( V_3 ) ;
return - V_43 ;
}
