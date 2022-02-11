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
F_21 ( V_3 , L_7 ,
V_30 -> V_32 ) ;
return 0 ;
}
static struct V_58 * F_24 ( struct V_2 * V_3 ,
int type , T_1 V_5 )
{
struct V_58 * V_59 ;
if ( ( type != V_60 ) && ( type != V_61 ) )
return NULL ;
V_59 = F_2 ( sizeof( * V_59 ) , V_5 ) ;
if ( ! V_59 )
return NULL ;
V_59 -> type = type ;
V_59 -> V_62 = F_25 ( V_3 -> V_63 ) ? 2048 : 1024 ;
if ( type == V_61 )
V_59 -> V_62 += F_26 ( V_3 -> V_63 ) ;
V_59 -> V_64 = F_3 ( V_3 -> V_65 , V_5 , & V_59 -> V_7 ) ;
if ( ! V_59 -> V_64 ) {
F_4 ( V_59 ) ;
return NULL ;
}
memset ( V_59 -> V_64 , 0 , V_59 -> V_62 ) ;
return V_59 ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_6 ( V_3 -> V_65 , V_59 -> V_64 , V_59 -> V_7 ) ;
F_4 ( V_59 ) ;
}
struct V_66 * F_28 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
if ( V_59 -> type != V_61 )
return NULL ;
return (struct V_66 * ) V_59 -> V_64 ;
}
struct V_67 * F_29 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
if ( V_59 -> type == V_60 )
return (struct V_67 * ) V_59 -> V_64 ;
return (struct V_67 * )
( V_59 -> V_64 + F_26 ( V_3 -> V_63 ) ) ;
}
struct V_68 * F_30 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
unsigned int V_49 )
{
V_49 ++ ;
if ( V_59 -> type == V_61 )
V_49 ++ ;
return (struct V_68 * )
( V_59 -> V_64 + ( V_49 * F_26 ( V_3 -> V_63 ) ) ) ;
}
static void F_31 ( struct V_2 * V_3 ,
unsigned int V_69 ,
struct V_70 * V_71 , T_2 V_7 )
{
struct V_72 * V_73 = F_32 ( F_33 ( V_3 ) -> V_74 . V_75 ) ;
if ( V_69 > V_76 )
F_34 ( & V_73 -> V_77 ,
sizeof( struct V_70 ) * V_69 ,
V_71 , V_7 ) ;
else if ( V_69 <= V_78 )
return F_6 ( V_3 -> V_79 ,
V_71 , V_7 ) ;
else
return F_6 ( V_3 -> V_80 ,
V_71 , V_7 ) ;
}
static struct V_70 * F_35 ( struct V_2 * V_3 ,
unsigned int V_69 , T_2 * V_7 ,
T_1 V_81 )
{
struct V_72 * V_73 = F_32 ( F_33 ( V_3 ) -> V_74 . V_75 ) ;
if ( V_69 > V_76 )
return F_36 ( & V_73 -> V_77 ,
sizeof( struct V_70 ) * V_69 ,
V_7 , V_81 ) ;
else if ( V_69 <= V_78 )
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
static struct V_29 * F_39 (
struct V_90 * V_87 ,
T_4 V_84 )
{
return F_38 ( & V_87 -> V_88 ,
V_84 >> V_89 ) ;
}
struct V_29 * F_40 (
struct V_47 * V_77 ,
unsigned int V_49 ,
unsigned int V_91 )
{
struct V_82 * V_83 = & V_77 -> V_54 [ V_49 ] ;
if ( V_91 == 0 )
return V_83 -> V_30 ;
if ( ! V_83 -> V_87 )
return NULL ;
if ( V_91 > V_83 -> V_87 -> V_92 )
return NULL ;
return V_83 -> V_87 -> V_93 [ V_91 ] ;
}
static int F_41 ( struct V_2 * V_3 ,
unsigned int V_92 ,
struct V_90 * V_87 )
{
T_3 V_94 ;
struct V_29 * V_95 ;
T_4 V_96 ;
for ( V_94 = 1 ; V_94 < V_92 ; V_94 ++ ) {
struct V_29 * V_97 ;
int V_98 = sizeof( union V_55 ) ;
V_95 = V_87 -> V_93 [ V_94 ] ;
for ( V_96 = V_95 -> V_37 -> V_7 ;
V_96 < V_95 -> V_37 -> V_7 + V_11 ;
V_96 += V_98 ) {
V_97 = F_39 ( V_87 , V_96 ) ;
if ( V_95 != V_97 ) {
F_42 ( V_3 , L_8
L_9
L_10 ,
( unsigned long long ) V_96 ,
V_94 ,
V_97 ) ;
return - V_99 ;
}
}
V_97 = F_39 ( V_87 , V_96 ) ;
if ( V_97 != V_95 ) {
V_96 = V_95 -> V_37 -> V_7 - V_98 ;
V_97 = F_39 ( V_87 , V_96 ) ;
}
if ( V_97 == V_95 ) {
F_42 ( V_3 , L_11
L_12
L_13 ,
( unsigned long long ) V_96 ,
V_94 ,
V_97 ) ;
return - V_99 ;
}
}
return 0 ;
}
struct V_90 * F_43 ( struct V_2 * V_3 ,
unsigned int V_69 ,
unsigned int V_92 , T_1 V_81 )
{
struct V_90 * V_87 ;
T_3 V_94 ;
struct V_29 * V_95 ;
unsigned long V_100 ;
T_4 V_96 ;
int V_44 ;
F_21 ( V_3 , L_14
L_15 ,
V_92 , V_69 ) ;
if ( V_3 -> V_101 == V_102 ) {
F_21 ( V_3 , L_16 ) ;
return NULL ;
}
V_3 -> V_101 ++ ;
V_87 = F_2 ( sizeof( struct V_90 ) , V_81 ) ;
if ( ! V_87 )
goto V_103;
V_87 -> V_92 = V_92 ;
V_87 -> V_69 = V_69 ;
V_87 -> V_93 = F_2 (
sizeof( struct V_29 * ) * V_92 ,
V_81 ) ;
if ( ! V_87 -> V_93 )
goto V_104;
V_87 -> V_105 = F_35 ( V_3 ,
V_69 , & V_87 -> V_106 ,
V_81 ) ;
if ( ! V_87 -> V_105 )
goto V_107;
memset ( V_87 -> V_105 , 0 ,
sizeof( struct V_70 ) * V_69 ) ;
V_87 -> V_108 =
F_44 ( V_3 , true , true , V_81 ) ;
if ( ! V_87 -> V_108 )
goto V_107;
F_45 ( & V_87 -> V_88 , V_109 ) ;
for ( V_94 = 1 ; V_94 < V_92 ; V_94 ++ ) {
V_87 -> V_93 [ V_94 ] =
F_18 ( V_3 , 2 , 1 , V_110 , V_81 ) ;
V_95 = V_87 -> V_93 [ V_94 ] ;
if ( ! V_95 )
goto V_111;
V_95 -> V_91 = V_94 ;
V_96 = V_95 -> V_37 -> V_7 |
F_46 ( V_112 ) |
V_95 -> V_4 ;
V_87 -> V_105 [ V_94 ] . V_113 =
F_9 ( V_96 ) ;
F_21 ( V_3 , L_17 ,
V_94 , ( unsigned long long ) V_96 ) ;
V_100 = ( unsigned long )
( V_95 -> V_37 -> V_7 >> V_89 ) ;
V_44 = F_47 ( & V_87 -> V_88 ,
V_100 , V_95 ) ;
if ( V_44 ) {
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
goto V_111;
}
}
#if V_114
if ( F_41 ( V_3 , V_92 , V_87 ) )
goto V_111;
#endif
return V_87 ;
V_111:
for ( V_94 = 1 ; V_94 < V_92 ; V_94 ++ ) {
V_95 = V_87 -> V_93 [ V_94 ] ;
if ( V_95 ) {
V_96 = V_95 -> V_37 -> V_7 ;
F_48 ( & V_87 -> V_88 ,
V_96 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
}
}
F_49 ( V_3 , V_87 -> V_108 ) ;
V_107:
F_4 ( V_87 -> V_93 ) ;
V_104:
F_4 ( V_87 ) ;
V_103:
V_3 -> V_101 -- ;
return NULL ;
}
void F_50 ( struct V_2 * V_3 ,
struct V_68 * V_115 ,
struct V_90 * V_87 )
{
T_3 V_116 ;
V_116 = F_51 ( V_87 -> V_69 ) - 2 ;
F_21 ( V_3 , L_18 ,
1 << ( V_116 + 1 ) ) ;
V_115 -> V_117 &= F_13 ( ~ V_118 ) ;
V_115 -> V_117 |= F_13 ( F_52 ( V_116 )
| V_119 ) ;
V_115 -> V_120 = F_9 ( V_87 -> V_106 ) ;
}
void F_53 ( struct V_2 * V_3 ,
struct V_68 * V_115 ,
struct V_82 * V_83 )
{
T_2 V_96 ;
V_115 -> V_117 &= F_13 ( ~ ( V_118 | V_119 ) ) ;
V_96 = F_54 ( V_83 -> V_30 -> V_40 , V_83 -> V_30 -> V_39 ) ;
V_115 -> V_120 = F_9 ( V_96 | V_83 -> V_30 -> V_4 ) ;
}
void F_55 ( struct V_2 * V_3 ,
struct V_90 * V_87 )
{
int V_94 ;
struct V_29 * V_95 ;
T_2 V_96 ;
if ( ! V_87 )
return;
for ( V_94 = 1 ; V_94 < V_87 -> V_92 ;
V_94 ++ ) {
V_95 = V_87 -> V_93 [ V_94 ] ;
if ( V_95 ) {
V_96 = V_95 -> V_37 -> V_7 ;
F_48 ( & V_87 -> V_88 ,
V_96 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
}
}
F_49 ( V_3 , V_87 -> V_108 ) ;
V_3 -> V_101 -- ;
if ( V_87 -> V_105 )
F_31 ( V_3 ,
V_87 -> V_69 ,
V_87 -> V_105 ,
V_87 -> V_106 ) ;
if ( V_87 )
F_4 ( V_87 -> V_93 ) ;
F_4 ( V_87 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
F_57 ( & V_83 -> V_121 ) ;
V_83 -> V_121 . V_122 = ( unsigned long ) V_83 ;
V_83 -> V_121 . V_123 = V_124 ;
V_83 -> V_3 = V_3 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
int V_125 )
{
struct V_126 * V_127 ;
struct V_128 * V_129 , * V_16 ;
bool V_130 = false ;
if ( V_48 -> V_131 == 0 ||
V_48 -> V_131 > F_59 ( V_3 -> V_132 ) ) {
F_21 ( V_3 , L_19 ) ;
return;
}
V_127 = & ( V_3 -> V_133 [ V_48 -> V_131 - 1 ] . V_134 ) ;
F_60 (tt_info, next, tt_list_head, tt_list) {
if ( V_129 -> V_125 == V_125 ) {
V_130 = true ;
F_61 ( & V_129 -> V_135 ) ;
F_4 ( V_129 ) ;
} else if ( V_130 ) {
break;
}
}
}
int F_62 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_136 * V_137 ,
struct V_138 * V_139 , T_1 V_81 )
{
struct V_128 * V_129 ;
unsigned int V_140 ;
int V_8 , V_141 ;
if ( ! V_139 -> V_142 )
V_140 = 1 ;
else
V_140 = V_137 -> V_143 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ , V_129 ++ ) {
struct V_144 * V_145 ;
V_129 = F_2 ( sizeof( * V_129 ) , V_81 ) ;
if ( ! V_129 )
goto V_146;
F_19 ( & V_129 -> V_135 ) ;
F_63 ( & V_129 -> V_135 ,
& V_3 -> V_133 [ V_48 -> V_131 - 1 ] . V_134 ) ;
V_129 -> V_125 = V_48 -> V_147 -> V_125 ;
if ( V_139 -> V_142 )
V_129 -> V_148 = V_8 + 1 ;
V_145 = & V_129 -> V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_19 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
return 0 ;
V_146:
F_58 ( V_3 , V_48 , V_48 -> V_147 -> V_125 ) ;
return - V_43 ;
}
void F_64 ( struct V_2 * V_3 , int V_125 )
{
struct V_47 * V_77 ;
int V_8 ;
int V_152 = 0 ;
if ( V_125 == 0 || ! V_3 -> V_153 [ V_125 ] )
return;
V_77 = V_3 -> V_153 [ V_125 ] ;
V_3 -> V_154 -> V_155 [ V_125 ] = 0 ;
if ( ! V_77 )
return;
if ( V_77 -> V_129 )
V_152 = V_77 -> V_129 -> V_156 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_77 -> V_54 [ V_8 ] . V_30 )
F_15 ( V_3 , V_77 -> V_54 [ V_8 ] . V_30 ) ;
if ( V_77 -> V_54 [ V_8 ] . V_87 )
F_55 ( V_3 ,
V_77 -> V_54 [ V_8 ] . V_87 ) ;
if ( ! F_65 ( & V_77 -> V_54 [ V_8 ] . V_157 ) )
F_42 ( V_3 , L_20
L_21 ,
V_125 , V_8 ) ;
}
F_58 ( V_3 , V_77 , V_125 ) ;
F_66 ( V_3 , V_77 , V_152 ) ;
if ( V_77 -> V_53 ) {
for ( V_8 = 0 ; V_8 < V_77 -> V_51 ; V_8 ++ )
F_15 ( V_3 , V_77 -> V_53 [ V_8 ] ) ;
F_4 ( V_77 -> V_53 ) ;
}
if ( V_77 -> V_158 )
F_27 ( V_3 , V_77 -> V_158 ) ;
if ( V_77 -> V_159 )
F_27 ( V_3 , V_77 -> V_159 ) ;
F_4 ( V_3 -> V_153 [ V_125 ] ) ;
V_3 -> V_153 [ V_125 ] = NULL ;
}
int F_67 ( struct V_2 * V_3 , int V_125 ,
struct V_136 * V_147 , T_1 V_5 )
{
struct V_47 * V_77 ;
int V_8 ;
if ( V_125 == 0 || V_3 -> V_153 [ V_125 ] ) {
F_42 ( V_3 , L_22 , V_125 ) ;
return 0 ;
}
V_3 -> V_153 [ V_125 ] = F_2 ( sizeof( * V_3 -> V_153 [ V_125 ] ) , V_5 ) ;
if ( ! V_3 -> V_153 [ V_125 ] )
return 0 ;
V_77 = V_3 -> V_153 [ V_125 ] ;
V_77 -> V_159 = F_24 ( V_3 , V_60 , V_5 ) ;
if ( ! V_77 -> V_159 )
goto V_46;
F_21 ( V_3 , L_23 , V_125 ,
( unsigned long long ) V_77 -> V_159 -> V_7 ) ;
V_77 -> V_158 = F_24 ( V_3 , V_61 , V_5 ) ;
if ( ! V_77 -> V_158 )
goto V_46;
F_21 ( V_3 , L_24 , V_125 ,
( unsigned long long ) V_77 -> V_158 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_56 ( V_3 , & V_77 -> V_54 [ V_8 ] ) ;
F_19 ( & V_77 -> V_54 [ V_8 ] . V_160 ) ;
F_19 ( & V_77 -> V_54 [ V_8 ] . V_157 ) ;
}
V_77 -> V_54 [ 0 ] . V_30 = F_18 ( V_3 , 2 , 1 , V_161 , V_5 ) ;
if ( ! V_77 -> V_54 [ 0 ] . V_30 )
goto V_46;
V_77 -> V_53 = F_2 (
sizeof( struct V_29 * ) * V_52 ,
V_5 ) ;
if ( ! V_77 -> V_53 )
goto V_46;
V_77 -> V_51 = 0 ;
F_68 ( & V_77 -> V_162 ) ;
F_19 ( & V_77 -> V_163 ) ;
V_77 -> V_147 = V_147 ;
V_3 -> V_154 -> V_155 [ V_125 ] = F_9 ( V_77 -> V_159 -> V_7 ) ;
F_21 ( V_3 , L_25 ,
V_125 ,
& V_3 -> V_154 -> V_155 [ V_125 ] ,
F_69 ( V_3 -> V_154 -> V_155 [ V_125 ] ) ) ;
return 1 ;
V_46:
F_64 ( V_3 , V_125 ) ;
return 0 ;
}
void F_70 ( struct V_2 * V_3 ,
struct V_136 * V_147 )
{
struct V_47 * V_48 ;
struct V_68 * V_164 ;
struct V_29 * V_165 ;
V_48 = V_3 -> V_153 [ V_147 -> V_125 ] ;
V_164 = F_30 ( V_3 , V_48 -> V_158 , 0 ) ;
V_165 = V_48 -> V_54 [ 0 ] . V_30 ;
V_164 -> V_120 = F_9 ( F_54 ( V_165 -> V_33 ,
V_165 -> V_38 )
| V_165 -> V_4 ) ;
}
static T_3 F_71 ( struct V_2 * V_3 ,
struct V_136 * V_147 )
{
struct V_136 * V_166 ;
struct V_167 * V_168 ;
if ( V_147 -> V_169 == V_170 )
V_168 = V_3 -> V_171 ;
else
V_168 = V_3 -> V_172 ;
for ( V_166 = V_147 ; V_166 -> V_173 && V_166 -> V_173 -> V_173 ;
V_166 = V_166 -> V_173 )
;
return F_72 ( V_168 , V_166 -> V_174 ) ;
}
int F_73 ( struct V_2 * V_3 , struct V_136 * V_147 )
{
struct V_47 * V_77 ;
struct V_68 * V_164 ;
struct V_67 * V_175 ;
T_3 V_176 ;
T_3 V_177 ;
struct V_136 * V_166 ;
V_77 = V_3 -> V_153 [ V_147 -> V_125 ] ;
if ( V_147 -> V_125 == 0 || ! V_77 ) {
F_42 ( V_3 , L_26 ,
V_147 -> V_125 ) ;
return - V_99 ;
}
V_164 = F_30 ( V_3 , V_77 -> V_158 , 0 ) ;
V_175 = F_29 ( V_3 , V_77 -> V_158 ) ;
V_175 -> V_178 |= F_13 ( F_74 ( 1 ) | V_147 -> V_179 ) ;
switch ( V_147 -> V_169 ) {
case V_170 :
V_175 -> V_178 |= F_13 ( V_180 ) ;
V_177 = F_75 ( 512 ) ;
break;
case V_181 :
V_175 -> V_178 |= F_13 ( V_182 ) ;
V_177 = F_75 ( 64 ) ;
break;
case V_183 :
V_175 -> V_178 |= F_13 ( V_184 ) ;
V_177 = F_75 ( 64 ) ;
break;
case V_185 :
V_175 -> V_178 |= F_13 ( V_186 ) ;
V_177 = F_75 ( 8 ) ;
break;
case V_187 :
F_21 ( V_3 , L_27 ) ;
return - V_99 ;
break;
default:
return - V_99 ;
}
V_176 = F_71 ( V_3 , V_147 ) ;
if ( ! V_176 )
return - V_99 ;
V_175 -> V_188 |= F_13 ( F_76 ( V_176 ) ) ;
for ( V_166 = V_147 ; V_166 -> V_173 && V_166 -> V_173 -> V_173 ;
V_166 = V_166 -> V_173 )
;
V_77 -> V_189 = V_166 -> V_174 ;
V_77 -> V_131 = V_176 ;
F_21 ( V_3 , L_28 , V_176 ) ;
F_21 ( V_3 , L_29 , V_77 -> V_189 ) ;
if ( ! V_147 -> V_139 || ! V_147 -> V_139 -> V_190 -> V_173 ) {
V_77 -> V_145 = & V_3 -> V_133 [ V_176 - 1 ] . V_145 ;
} else {
struct V_191 * V_133 ;
struct V_128 * V_192 ;
V_133 = & V_3 -> V_133 [ V_176 - 1 ] ;
F_77 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_192 -> V_125 != V_147 -> V_139 -> V_190 -> V_125 )
continue;
if ( ! V_77 -> V_147 -> V_139 -> V_142 ||
( V_147 -> V_139 -> V_142 &&
V_192 -> V_148 == V_77 -> V_147 -> V_148 ) ) {
V_77 -> V_145 = & V_192 -> V_145 ;
V_77 -> V_129 = V_192 ;
break;
}
}
if ( ! V_77 -> V_129 )
F_42 ( V_3 , L_30 ) ;
}
if ( V_147 -> V_139 && V_147 -> V_139 -> V_190 -> V_173 ) {
V_175 -> V_129 = F_13 ( V_147 -> V_139 -> V_190 -> V_125 |
( V_147 -> V_148 << 8 ) ) ;
if ( V_147 -> V_139 -> V_142 )
V_175 -> V_178 |= F_13 ( V_193 ) ;
}
F_21 ( V_3 , L_31 , V_147 -> V_139 ) ;
F_21 ( V_3 , L_32 , V_147 -> V_148 ) ;
V_164 -> V_194 = F_13 ( F_78 ( V_195 ) ) ;
V_164 -> V_194 |= F_13 ( F_79 ( 0 ) | F_80 ( 3 ) |
V_177 ) ;
V_164 -> V_120 = F_9 ( V_77 -> V_54 [ 0 ] . V_30 -> V_37 -> V_7 |
V_77 -> V_54 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_81 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
unsigned int V_197 ;
V_197 = F_82 ( V_83 -> V_198 . V_199 , 1 , 16 ) - 1 ;
if ( V_197 != V_83 -> V_198 . V_199 - 1 )
F_83 ( & V_147 -> V_77 ,
L_33 ,
V_83 -> V_198 . V_200 ,
1 << V_197 ,
V_147 -> V_169 == V_183 ? L_4 : L_34 ) ;
if ( V_147 -> V_169 == V_183 ) {
V_197 += 3 ;
}
return V_197 ;
}
static unsigned int F_84 ( struct V_136 * V_147 ,
struct V_196 * V_83 , unsigned int V_201 ,
unsigned int V_202 , unsigned int V_203 )
{
unsigned int V_197 ;
V_197 = F_51 ( V_201 ) - 1 ;
V_197 = F_82 ( V_197 , V_202 , V_203 ) ;
if ( ( 1 << V_197 ) != V_201 )
F_83 ( & V_147 -> V_77 ,
L_35 ,
V_83 -> V_198 . V_200 ,
1 << V_197 ,
V_201 ) ;
return V_197 ;
}
static unsigned int F_85 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
if ( V_83 -> V_198 . V_199 == 0 )
return 0 ;
return F_84 ( V_147 , V_83 ,
V_83 -> V_198 . V_199 , 0 , 15 ) ;
}
static unsigned int F_86 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
return F_84 ( V_147 , V_83 ,
V_83 -> V_198 . V_199 * 8 , 3 , 10 ) ;
}
static unsigned int F_87 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
unsigned int V_197 = 0 ;
switch ( V_147 -> V_169 ) {
case V_181 :
if ( F_88 ( & V_83 -> V_198 ) ||
F_89 ( & V_83 -> V_198 ) ) {
V_197 = F_85 ( V_147 , V_83 ) ;
break;
}
case V_170 :
if ( F_90 ( & V_83 -> V_198 ) ||
F_91 ( & V_83 -> V_198 ) ) {
V_197 = F_81 ( V_147 , V_83 ) ;
}
break;
case V_183 :
if ( F_91 ( & V_83 -> V_198 ) ) {
V_197 = F_81 ( V_147 , V_83 ) ;
break;
}
case V_185 :
if ( F_90 ( & V_83 -> V_198 ) ||
F_91 ( & V_83 -> V_198 ) ) {
V_197 = F_86 ( V_147 , V_83 ) ;
}
break;
default:
F_92 () ;
}
return F_93 ( V_197 ) ;
}
static T_3 F_94 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
if ( V_147 -> V_169 != V_170 ||
! F_91 ( & V_83 -> V_198 ) )
return 0 ;
return V_83 -> V_204 . V_205 ;
}
static T_3 F_95 ( struct V_136 * V_147 ,
struct V_196 * V_83 )
{
int V_206 ;
T_3 type ;
V_206 = F_96 ( & V_83 -> V_198 ) ;
if ( F_88 ( & V_83 -> V_198 ) ) {
type = F_78 ( V_195 ) ;
} else if ( F_89 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_78 ( V_207 ) ;
else
type = F_78 ( V_208 ) ;
} else if ( F_91 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_78 ( V_209 ) ;
else
type = F_78 ( V_210 ) ;
} else if ( F_90 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_78 ( V_211 ) ;
else
type = F_78 ( V_212 ) ;
} else {
type = 0 ;
}
return type ;
}
static T_3 F_97 ( struct V_2 * V_3 ,
struct V_136 * V_147 ,
struct V_196 * V_83 )
{
int V_213 ;
int V_214 ;
if ( F_88 ( & V_83 -> V_198 ) ||
F_89 ( & V_83 -> V_198 ) )
return 0 ;
if ( V_147 -> V_169 == V_170 )
return F_98 ( V_83 -> V_204 . V_215 ) ;
V_214 = F_99 ( F_100 ( & V_83 -> V_198 ) ) ;
V_213 = ( F_100 ( & V_83 -> V_198 ) & 0x1800 ) >> 11 ;
return V_214 * ( V_213 + 1 ) ;
}
int F_101 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_136 * V_147 ,
struct V_196 * V_83 ,
T_1 V_81 )
{
unsigned int V_49 ;
struct V_68 * V_115 ;
struct V_29 * V_165 ;
unsigned int V_214 ;
unsigned int V_213 ;
enum V_19 type ;
T_3 V_216 ;
T_3 V_217 ;
V_49 = F_102 ( & V_83 -> V_198 ) ;
V_115 = F_30 ( V_3 , V_48 -> V_158 , V_49 ) ;
V_217 = F_95 ( V_147 , V_83 ) ;
if ( ! V_217 )
return - V_99 ;
V_115 -> V_194 = F_13 ( V_217 ) ;
type = F_103 ( & V_83 -> V_198 ) ;
V_48 -> V_54 [ V_49 ] . V_218 =
F_18 ( V_3 , 2 , 1 , type , V_81 ) ;
if ( ! V_48 -> V_54 [ V_49 ] . V_218 ) {
if ( V_48 -> V_51 == 0 )
return - V_43 ;
V_48 -> V_54 [ V_49 ] . V_218 =
V_48 -> V_53 [ V_48 -> V_51 ] ;
V_48 -> V_53 [ V_48 -> V_51 ] = NULL ;
V_48 -> V_51 -- ;
F_22 ( V_3 , V_48 -> V_54 [ V_49 ] . V_218 ,
1 , type ) ;
}
V_48 -> V_54 [ V_49 ] . V_219 = false ;
V_165 = V_48 -> V_54 [ V_49 ] . V_218 ;
V_115 -> V_120 = F_9 ( V_165 -> V_37 -> V_7 | V_165 -> V_4 ) ;
V_115 -> V_117 = F_13 ( F_87 ( V_147 , V_83 )
| F_104 ( F_94 ( V_147 , V_83 ) ) ) ;
if ( ! F_91 ( & V_83 -> V_198 ) )
V_115 -> V_194 |= F_13 ( F_80 ( 3 ) ) ;
else
V_115 -> V_194 |= F_13 ( F_80 ( 0 ) ) ;
V_214 = F_99 ( F_100 ( & V_83 -> V_198 ) ) ;
V_213 = 0 ;
switch ( V_147 -> V_169 ) {
case V_170 :
V_213 = V_83 -> V_204 . V_220 ;
break;
case V_181 :
if ( F_89 ( & V_83 -> V_198 ) )
V_214 = 512 ;
if ( F_91 ( & V_83 -> V_198 ) ||
F_90 ( & V_83 -> V_198 ) ) {
V_213 = ( F_100 ( & V_83 -> V_198 )
& 0x1800 ) >> 11 ;
}
break;
case V_183 :
case V_185 :
break;
default:
F_92 () ;
}
V_115 -> V_194 |= F_13 ( F_75 ( V_214 ) |
F_79 ( V_213 ) ) ;
V_216 = F_97 ( V_3 , V_147 , V_83 ) ;
V_115 -> V_221 = F_13 ( F_105 ( V_216 ) ) ;
if ( F_88 ( & V_83 -> V_198 ) && V_3 -> V_222 == 0x100 )
V_115 -> V_221 |= F_13 ( F_106 ( 8 ) ) ;
else
V_115 -> V_221 |=
F_13 ( F_106 ( V_216 ) ) ;
return 0 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_196 * V_83 )
{
unsigned int V_49 ;
struct V_68 * V_115 ;
V_49 = F_102 ( & V_83 -> V_198 ) ;
V_115 = F_30 ( V_3 , V_48 -> V_158 , V_49 ) ;
V_115 -> V_117 = 0 ;
V_115 -> V_194 = 0 ;
V_115 -> V_120 = 0 ;
V_115 -> V_221 = 0 ;
}
void F_108 ( struct V_223 * V_224 )
{
V_224 -> V_225 = 0 ;
V_224 -> V_226 = 0 ;
V_224 -> V_227 = 0 ;
V_224 -> V_228 = 0 ;
V_224 -> type = 0 ;
V_224 -> V_216 = 0 ;
}
void F_109 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_66 * V_229 ,
struct V_47 * V_48 )
{
struct V_223 * V_224 ;
struct V_68 * V_115 ;
unsigned int V_230 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_224 = & V_48 -> V_54 [ V_8 ] . V_224 ;
if ( ! F_110 ( V_229 , V_8 ) && F_111 ( V_229 , V_8 ) ) {
F_108 ( V_224 ) ;
continue;
}
if ( F_110 ( V_229 , V_8 ) ) {
V_115 = F_30 ( V_3 , V_158 , V_8 ) ;
V_230 = F_112 ( F_10 ( V_115 -> V_194 ) ) ;
if ( V_230 != V_210 && V_230 != V_212 &&
V_230 != V_209 &&
V_230 != V_211 )
continue;
V_224 -> V_225 = F_113 (
F_10 ( V_115 -> V_117 ) ) ;
V_224 -> V_226 = F_114 (
F_10 ( V_115 -> V_117 ) ) + 1 ;
V_224 -> V_227 = F_115 (
F_10 ( V_115 -> V_194 ) ) + 1 ;
V_224 -> V_228 = F_116 (
F_10 ( V_115 -> V_194 ) ) ;
V_224 -> type = V_230 ;
V_224 -> V_216 = F_117 (
F_10 ( V_115 -> V_221 ) ) ;
}
}
}
void F_118 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 ,
unsigned int V_49 )
{
struct V_68 * V_231 ;
struct V_68 * V_232 ;
V_231 = F_30 ( V_3 , V_159 , V_49 ) ;
V_232 = F_30 ( V_3 , V_158 , V_49 ) ;
V_232 -> V_117 = V_231 -> V_117 ;
V_232 -> V_194 = V_231 -> V_194 ;
V_232 -> V_120 = V_231 -> V_120 ;
V_232 -> V_221 = V_231 -> V_221 ;
}
void F_119 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 )
{
struct V_67 * V_233 ;
struct V_67 * V_234 ;
V_233 = F_29 ( V_3 , V_158 ) ;
V_234 = F_29 ( V_3 , V_159 ) ;
V_233 -> V_178 = V_234 -> V_178 ;
V_233 -> V_188 = V_234 -> V_188 ;
V_233 -> V_129 = V_234 -> V_129 ;
V_233 -> V_235 = V_234 -> V_235 ;
}
static int F_120 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_236 * V_77 = F_33 ( V_3 ) -> V_74 . V_75 ;
int V_237 = F_121 ( V_3 -> V_238 ) ;
F_21 ( V_3 , L_36 , V_237 ) ;
if ( ! V_237 )
return 0 ;
V_3 -> V_239 = F_2 ( sizeof( * V_3 -> V_239 ) , V_5 ) ;
if ( ! V_3 -> V_239 )
goto V_240;
V_3 -> V_239 -> V_241 = F_36 ( V_77 ,
V_237 * sizeof( T_4 ) ,
& V_3 -> V_239 -> V_242 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_241 )
goto V_243;
V_3 -> V_239 -> V_244 = F_2 ( sizeof( void * ) * V_237 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_244 )
goto V_245;
V_3 -> V_239 -> V_246 =
F_2 ( sizeof( T_2 ) * V_237 , V_5 ) ;
if ( ! V_3 -> V_239 -> V_246 )
goto V_247;
V_3 -> V_154 -> V_155 [ 0 ] = F_9 ( V_3 -> V_239 -> V_242 ) ;
for ( V_8 = 0 ; V_8 < V_237 ; V_8 ++ ) {
T_2 V_7 ;
void * V_248 = F_36 ( V_77 , V_3 -> V_249 , & V_7 ,
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
F_34 ( V_77 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
V_247:
F_4 ( V_3 -> V_239 -> V_244 ) ;
V_245:
F_34 ( V_77 , V_237 * sizeof( T_4 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
V_243:
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
V_240:
return - V_43 ;
}
static void F_122 ( struct V_2 * V_3 )
{
int V_237 ;
int V_8 ;
struct V_72 * V_73 = F_32 ( F_33 ( V_3 ) -> V_74 . V_75 ) ;
if ( ! V_3 -> V_239 )
return;
V_237 = F_121 ( V_3 -> V_238 ) ;
for ( V_8 = 0 ; V_8 < V_237 ; V_8 ++ ) {
F_34 ( & V_73 -> V_77 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
F_4 ( V_3 -> V_239 -> V_244 ) ;
F_34 ( & V_73 -> V_77 , V_237 * sizeof( T_4 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
}
struct V_251 * F_44 ( struct V_2 * V_3 ,
bool V_252 , bool V_253 ,
T_1 V_81 )
{
struct V_251 * V_254 ;
V_254 = F_2 ( sizeof( * V_254 ) , V_81 ) ;
if ( ! V_254 )
return NULL ;
if ( V_252 ) {
V_254 -> V_158 =
F_24 ( V_3 , V_61 ,
V_81 ) ;
if ( ! V_254 -> V_158 ) {
F_4 ( V_254 ) ;
return NULL ;
}
}
if ( V_253 ) {
V_254 -> V_255 =
F_2 ( sizeof( struct V_255 ) , V_81 ) ;
if ( ! V_254 -> V_255 ) {
F_27 ( V_3 , V_254 -> V_158 ) ;
F_4 ( V_254 ) ;
return NULL ;
}
F_68 ( V_254 -> V_255 ) ;
}
V_254 -> V_256 = 0 ;
F_19 ( & V_254 -> V_163 ) ;
return V_254 ;
}
void F_123 ( struct V_2 * V_3 , struct V_257 * V_257 )
{
if ( V_257 ) {
F_4 ( V_257 -> V_258 [ 0 ] ) ;
F_4 ( V_257 ) ;
}
}
void F_49 ( struct V_2 * V_3 ,
struct V_251 * V_254 )
{
F_27 ( V_3 ,
V_254 -> V_158 ) ;
F_4 ( V_254 -> V_255 ) ;
F_4 ( V_254 ) ;
}
void F_124 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = F_32 ( F_33 ( V_3 ) -> V_74 . V_75 ) ;
struct V_178 * V_178 , * V_16 ;
struct V_259 * V_260 , * V_261 ;
unsigned long V_5 ;
int V_62 ;
int V_8 , V_141 , V_140 ;
V_62 = sizeof( struct V_262 ) * ( V_3 -> V_263 . V_264 ) ;
if ( V_3 -> V_263 . V_265 )
F_34 ( & V_73 -> V_77 , V_62 ,
V_3 -> V_263 . V_265 , V_3 -> V_263 . V_266 ) ;
V_3 -> V_263 . V_265 = NULL ;
F_21 ( V_3 , L_37 ) ;
if ( V_3 -> V_267 )
F_15 ( V_3 , V_3 -> V_267 ) ;
V_3 -> V_267 = NULL ;
F_21 ( V_3 , L_38 ) ;
if ( V_3 -> V_268 )
F_49 ( V_3 , V_3 -> V_268 ) ;
V_3 -> V_101 = 0 ;
if ( V_3 -> V_269 )
F_15 ( V_3 , V_3 -> V_269 ) ;
V_3 -> V_269 = NULL ;
F_21 ( V_3 , L_39 ) ;
F_60 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_61 ( & V_260 -> V_270 ) ;
F_4 ( V_260 ) ;
}
for ( V_8 = 1 ; V_8 < V_271 ; ++ V_8 )
F_64 ( V_3 , V_8 ) ;
if ( V_3 -> V_10 )
F_125 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_21 ( V_3 , L_40 ) ;
if ( V_3 -> V_65 )
F_125 ( V_3 -> V_65 ) ;
V_3 -> V_65 = NULL ;
F_21 ( V_3 , L_41 ) ;
if ( V_3 -> V_79 )
F_125 ( V_3 -> V_79 ) ;
V_3 -> V_79 = NULL ;
F_21 ( V_3 , L_42 ) ;
if ( V_3 -> V_80 )
F_125 ( V_3 -> V_80 ) ;
V_3 -> V_80 = NULL ;
F_21 ( V_3 , L_43 ) ;
if ( V_3 -> V_154 )
F_34 ( & V_73 -> V_77 , sizeof( * V_3 -> V_154 ) ,
V_3 -> V_154 , V_3 -> V_154 -> V_7 ) ;
V_3 -> V_154 = NULL ;
F_122 ( V_3 ) ;
F_126 ( & V_3 -> V_272 , V_5 ) ;
F_60 (dev_info, next, &xhci->lpm_failed_devs, list) {
F_61 ( & V_178 -> V_273 ) ;
F_4 ( V_178 ) ;
}
F_127 ( & V_3 -> V_272 , V_5 ) ;
if ( ! V_3 -> V_133 )
goto V_274;
V_140 = F_59 ( V_3 -> V_132 ) ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_144 * V_275 = & V_3 -> V_133 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ ) {
struct V_126 * V_83 = & V_275 -> V_150 [ V_141 ] . V_151 ;
while ( ! F_65 ( V_83 ) )
F_128 ( V_83 -> V_16 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_128 * V_139 , * V_276 ;
F_60 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_61 ( & V_139 -> V_135 ) ;
F_4 ( V_139 ) ;
}
}
V_274:
V_3 -> V_277 = 0 ;
V_3 -> V_278 = 0 ;
V_3 -> V_279 = 0 ;
F_4 ( V_3 -> V_280 ) ;
F_4 ( V_3 -> V_281 ) ;
F_4 ( V_3 -> V_282 ) ;
F_4 ( V_3 -> V_133 ) ;
F_4 ( V_3 -> V_283 ) ;
V_3 -> V_249 = 0 ;
V_3 -> V_284 = 0 ;
V_3 -> V_285 [ 0 ] . V_286 = 0 ;
V_3 -> V_285 [ 1 ] . V_286 = 0 ;
}
static int F_129 ( struct V_2 * V_3 ,
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
V_294 = F_54 ( V_287 , V_288 ) ;
V_295 = F_54 ( V_287 , V_289 ) ;
V_6 = F_130 ( V_287 , V_288 , V_289 , V_290 ) ;
if ( V_6 != V_291 ) {
F_42 ( V_3 , L_44 ,
V_292 , V_293 ) ;
F_42 ( V_3 , L_45
L_46 ,
V_287 ,
( unsigned long long ) V_290 ) ;
F_42 ( V_3 , L_47
L_48 ,
V_288 , V_294 ,
V_289 , V_295 ) ;
F_42 ( V_3 , L_49 ,
V_291 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_131 ( struct V_2 * V_3 , T_1 V_81 )
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
V_298 = F_132 ( V_296 ) ;
for ( V_8 = 0 ; V_8 < V_298 ; V_8 ++ ) {
V_44 = F_129 ( V_3 ,
V_3 -> V_267 -> V_37 ,
V_3 -> V_267 -> V_37 -> V_9 ,
& V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
V_296 [ V_8 ] . V_290 ,
V_296 [ V_8 ] . V_291 ,
L_50 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_298 = F_132 ( V_297 ) ;
for ( V_8 = 0 ; V_8 < V_298 ; V_8 ++ ) {
V_44 = F_129 ( V_3 ,
V_297 [ V_8 ] . V_287 ,
V_297 [ V_8 ] . V_288 ,
V_297 [ V_8 ] . V_289 ,
V_297 [ V_8 ] . V_290 ,
V_297 [ V_8 ] . V_291 ,
L_51 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_21 ( V_3 , L_52 ) ;
return 0 ;
}
static void F_133 ( struct V_2 * V_3 )
{
T_4 V_299 ;
T_2 V_120 ;
V_120 = F_54 ( V_3 -> V_267 -> V_40 ,
V_3 -> V_267 -> V_39 ) ;
if ( V_120 == 0 && ! F_134 () )
F_42 ( V_3 , L_53
L_54 ) ;
V_299 = F_135 ( V_3 , & V_3 -> V_300 -> V_301 ) ;
V_299 &= V_302 ;
V_299 &= ~ V_303 ;
F_21 ( V_3 , L_55
L_56 ) ;
F_136 ( V_3 , ( ( T_4 ) V_120 & ( T_4 ) ~ V_302 ) | V_299 ,
& V_3 -> V_300 -> V_301 ) ;
}
static void F_137 ( struct V_2 * V_3 , unsigned int V_140 ,
T_5 T_6 * V_96 , T_7 V_304 , int V_305 )
{
T_3 V_299 , V_306 , V_307 ;
int V_8 ;
if ( V_304 > 0x03 ) {
F_42 ( V_3 , L_57
L_58 ,
V_96 , V_304 ) ;
return;
}
V_299 = F_138 ( V_3 , V_96 + 2 ) ;
V_306 = F_139 ( V_299 ) ;
V_307 = F_140 ( V_299 ) ;
F_21 ( V_3 , L_59
L_60 ,
V_96 , V_306 , V_307 , V_304 ) ;
if ( V_306 == 0 || ( V_306 + V_307 - 1 ) > V_140 )
return;
if ( V_304 < 0x03 && V_3 -> V_308 < V_305 )
V_3 -> V_283 [ V_3 -> V_308 ++ ] = V_299 ;
if ( ( V_3 -> V_222 == 0x96 ) && ( V_304 != 0x03 ) &&
( V_299 & V_309 ) ) {
F_21 ( V_3 , L_61 ) ;
V_3 -> V_310 = 1 ;
}
if ( ( V_3 -> V_222 >= 0x100 ) && ( V_304 != 0x03 ) ) {
F_21 ( V_3 , L_62 ) ;
V_3 -> V_310 = 1 ;
if ( V_299 & V_311 ) {
F_21 ( V_3 , L_63 ) ;
V_3 -> V_312 = 1 ;
}
}
V_306 -- ;
for ( V_8 = V_306 ; V_8 < ( V_306 + V_307 ) ; V_8 ++ ) {
if ( V_3 -> V_282 [ V_8 ] != 0 ) {
F_42 ( V_3 , L_64
L_65 , V_96 , V_8 ) ;
F_42 ( V_3 , L_66
L_67 ,
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
static int F_141 ( struct V_2 * V_3 , T_1 V_5 )
{
T_5 T_6 * V_96 , * V_314 ;
T_3 V_315 , V_316 ;
unsigned int V_140 ;
int V_8 , V_141 , V_317 ;
int V_318 = 0 ;
V_96 = & V_3 -> V_319 -> V_63 ;
V_315 = F_142 ( F_138 ( V_3 , V_96 ) ) ;
if ( V_315 == 0 ) {
F_143 ( V_3 , L_68
L_69 ) ;
return - V_320 ;
}
V_140 = F_59 ( V_3 -> V_132 ) ;
V_3 -> V_282 = F_2 ( sizeof( * V_3 -> V_282 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_282 )
return - V_43 ;
V_3 -> V_133 = F_2 ( sizeof( * V_3 -> V_133 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_133 )
return - V_43 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_144 * V_145 ;
F_19 ( & V_3 -> V_133 [ V_8 ] . V_134 ) ;
V_145 = & V_3 -> V_133 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_19 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
V_96 = & V_3 -> V_319 -> V_321 + V_315 ;
V_314 = V_96 ;
V_316 = V_315 ;
do {
T_3 V_322 ;
V_322 = F_138 ( V_3 , V_314 ) ;
if ( F_144 ( V_322 ) == V_323 )
V_318 ++ ;
V_316 = F_145 ( V_322 ) ;
V_314 += V_316 ;
} while ( V_316 );
V_3 -> V_283 = F_2 ( sizeof( * V_3 -> V_283 ) * V_318 , V_5 ) ;
if ( ! V_3 -> V_283 )
return - V_43 ;
while ( 1 ) {
T_3 V_322 ;
V_322 = F_138 ( V_3 , V_96 ) ;
if ( F_144 ( V_322 ) == V_323 )
F_137 ( V_3 , V_140 , V_96 ,
( T_7 ) F_146 ( V_322 ) ,
V_318 ) ;
V_315 = F_145 ( V_322 ) ;
if ( ! V_315 || ( V_3 -> V_277 + V_3 -> V_278 )
== V_140 )
break;
V_96 += V_315 ;
}
if ( V_3 -> V_277 == 0 && V_3 -> V_278 == 0 ) {
F_42 ( V_3 , L_70 ) ;
return - V_320 ;
}
F_21 ( V_3 , L_71 ,
V_3 -> V_277 , V_3 -> V_278 ) ;
if ( V_3 -> V_278 > 15 ) {
F_21 ( V_3 , L_72 ) ;
V_3 -> V_278 = 15 ;
}
if ( V_3 -> V_277 > V_324 ) {
F_21 ( V_3 , L_73 ,
V_324 ) ;
V_3 -> V_277 = V_324 ;
}
if ( V_3 -> V_277 ) {
V_3 -> V_280 = F_147 ( sizeof( * V_3 -> V_280 ) *
V_3 -> V_277 , V_5 ) ;
if ( ! V_3 -> V_280 )
return - V_43 ;
V_317 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
if ( V_3 -> V_282 [ V_8 ] == 0x03 ||
V_3 -> V_282 [ V_8 ] == 0 ||
V_3 -> V_282 [ V_8 ] == V_313 )
continue;
V_3 -> V_280 [ V_317 ] =
& V_3 -> V_325 -> V_326 +
V_327 * V_8 ;
F_21 ( V_3 , L_74
L_75 , V_8 ,
V_3 -> V_280 [ V_317 ] ) ;
V_317 ++ ;
if ( V_317 == V_3 -> V_277 )
break;
}
}
if ( V_3 -> V_278 ) {
V_3 -> V_281 = F_147 ( sizeof( * V_3 -> V_281 ) *
V_3 -> V_278 , V_5 ) ;
if ( ! V_3 -> V_281 )
return - V_43 ;
V_317 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ )
if ( V_3 -> V_282 [ V_8 ] == 0x03 ) {
V_3 -> V_281 [ V_317 ] =
& V_3 -> V_325 -> V_326 +
V_327 * V_8 ;
F_21 ( V_3 , L_76
L_75 , V_8 ,
V_3 -> V_281 [ V_317 ] ) ;
V_317 ++ ;
if ( V_317 == V_3 -> V_278 )
break;
}
}
return 0 ;
}
int F_148 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_236 * V_77 = F_33 ( V_3 ) -> V_74 . V_75 ;
unsigned int V_20 , V_328 ;
T_4 V_329 ;
struct V_1 * V_6 ;
T_3 V_249 , V_299 ;
int V_8 ;
F_19 ( & V_3 -> V_330 ) ;
F_19 ( & V_3 -> V_270 ) ;
V_249 = F_138 ( V_3 , & V_3 -> V_325 -> V_249 ) ;
F_21 ( V_3 , L_77 , V_249 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_249 ) != 0 )
break;
V_249 = V_249 >> 1 ;
}
if ( V_8 < 16 )
F_21 ( V_3 , L_78 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_42 ( V_3 , L_79 ) ;
V_3 -> V_284 = 12 ;
V_3 -> V_249 = 1 << V_3 -> V_284 ;
F_21 ( V_3 , L_80 , V_3 -> V_249 / 1024 ) ;
V_20 = F_149 ( F_138 ( V_3 , & V_3 -> V_319 -> V_132 ) ) ;
F_21 ( V_3 , L_81 ,
( unsigned int ) V_20 ) ;
V_328 = F_138 ( V_3 , & V_3 -> V_325 -> V_331 ) ;
V_20 |= ( V_328 & ~ V_332 ) ;
F_21 ( V_3 , L_82 ,
( unsigned int ) V_20 ) ;
F_150 ( V_3 , V_20 , & V_3 -> V_325 -> V_331 ) ;
V_3 -> V_154 = F_36 ( V_77 , sizeof( * V_3 -> V_154 ) , & V_7 ,
V_333 ) ;
if ( ! V_3 -> V_154 )
goto V_46;
memset ( V_3 -> V_154 , 0 , sizeof *( V_3 -> V_154 ) ) ;
V_3 -> V_154 -> V_7 = V_7 ;
F_21 ( V_3 , L_83 ,
( unsigned long long ) V_3 -> V_154 -> V_7 , V_3 -> V_154 ) ;
F_136 ( V_3 , V_7 , & V_3 -> V_325 -> V_334 ) ;
V_3 -> V_10 = F_151 ( L_84 , V_77 ,
V_11 , 64 , V_3 -> V_249 ) ;
V_3 -> V_65 = F_151 ( L_85 , V_77 ,
2112 , 64 , V_3 -> V_249 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_65 )
goto V_46;
V_3 -> V_79 =
F_151 ( L_86 ,
V_77 , V_78 , 16 , 0 ) ;
V_3 -> V_80 =
F_151 ( L_87 ,
V_77 , V_76 , 16 , 0 ) ;
if ( ! V_3 -> V_79 || ! V_3 -> V_80 )
goto V_46;
V_3 -> V_269 = F_18 ( V_3 , 1 , 1 , V_335 , V_5 ) ;
if ( ! V_3 -> V_269 )
goto V_46;
F_21 ( V_3 , L_88 , V_3 -> V_269 ) ;
F_21 ( V_3 , L_89 ,
( unsigned long long ) V_3 -> V_269 -> V_37 -> V_7 ) ;
V_329 = F_135 ( V_3 , & V_3 -> V_325 -> V_269 ) ;
V_329 = ( V_329 & ( T_4 ) V_336 ) |
( V_3 -> V_269 -> V_37 -> V_7 & ( T_4 ) ~ V_336 ) |
V_3 -> V_269 -> V_4 ;
F_21 ( V_3 , L_90 , V_20 ) ;
F_136 ( V_3 , V_329 , & V_3 -> V_325 -> V_269 ) ;
F_152 ( V_3 ) ;
V_3 -> V_268 = F_44 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_268 )
goto V_46;
V_3 -> V_101 ++ ;
V_20 = F_138 ( V_3 , & V_3 -> V_319 -> V_337 ) ;
V_20 &= V_338 ;
F_21 ( V_3 , L_91
L_92 , V_20 ) ;
V_3 -> V_339 = ( void T_6 * ) V_3 -> V_319 + V_20 ;
F_153 ( V_3 ) ;
F_154 ( V_3 ) ;
V_3 -> V_300 = & V_3 -> V_340 -> V_300 [ 0 ] ;
F_21 ( V_3 , L_93 ) ;
V_3 -> V_267 = F_18 ( V_3 , V_341 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_267 )
goto V_46;
if ( F_131 ( V_3 , V_5 ) < 0 )
goto V_46;
V_3 -> V_263 . V_265 = F_36 ( V_77 ,
sizeof( struct V_262 ) * V_341 , & V_7 ,
V_333 ) ;
if ( ! V_3 -> V_263 . V_265 )
goto V_46;
F_21 ( V_3 , L_94 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_263 . V_265 , 0 , sizeof( struct V_262 ) * V_341 ) ;
V_3 -> V_263 . V_264 = V_341 ;
V_3 -> V_263 . V_266 = V_7 ;
F_21 ( V_3 , L_95 ,
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
V_20 = F_138 ( V_3 , & V_3 -> V_300 -> V_346 ) ;
V_20 &= V_347 ;
V_20 |= V_341 ;
F_21 ( V_3 , L_96 ,
V_20 ) ;
F_150 ( V_3 , V_20 , & V_3 -> V_300 -> V_346 ) ;
F_21 ( V_3 , L_97 ) ;
F_21 ( V_3 , L_98 ,
( unsigned long long ) V_3 -> V_263 . V_266 ) ;
V_329 = F_135 ( V_3 , & V_3 -> V_300 -> V_348 ) ;
V_329 &= V_302 ;
V_329 |= ( V_3 -> V_263 . V_266 & ( T_4 ) ~ V_302 ) ;
F_136 ( V_3 , V_329 , & V_3 -> V_300 -> V_348 ) ;
F_133 ( V_3 ) ;
F_21 ( V_3 , L_99 ) ;
F_155 ( V_3 , 0 ) ;
F_68 ( & V_3 -> V_349 ) ;
for ( V_8 = 0 ; V_8 < V_271 ; ++ V_8 )
V_3 -> V_153 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_324 ; ++ V_8 ) {
V_3 -> V_285 [ 0 ] . V_350 [ V_8 ] = 0 ;
V_3 -> V_285 [ 1 ] . V_350 [ V_8 ] = 0 ;
}
if ( F_120 ( V_3 , V_5 ) )
goto V_46;
if ( F_141 ( V_3 , V_5 ) )
goto V_46;
V_299 = F_138 ( V_3 , & V_3 -> V_325 -> V_351 ) ;
V_299 &= ~ V_352 ;
V_299 |= V_353 ;
F_150 ( V_3 , V_299 , & V_3 -> V_325 -> V_351 ) ;
return 0 ;
V_46:
F_42 ( V_3 , L_100 ) ;
F_156 ( V_3 ) ;
F_157 ( V_3 ) ;
F_124 ( V_3 ) ;
return - V_43 ;
}
