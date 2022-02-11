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
F_7 ( V_3 , * V_17 ) ;
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
F_15 ( V_3 , V_30 ) ;
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
struct V_58 * V_59 = F_2 ( sizeof( * V_59 ) , V_5 ) ;
if ( ! V_59 )
return NULL ;
F_25 ( ( type != V_60 ) && ( type != V_61 ) ) ;
V_59 -> type = type ;
V_59 -> V_62 = F_26 ( V_3 -> V_63 ) ? 2048 : 1024 ;
if ( type == V_61 )
V_59 -> V_62 += F_27 ( V_3 -> V_63 ) ;
V_59 -> V_64 = F_3 ( V_3 -> V_65 , V_5 , & V_59 -> V_7 ) ;
memset ( V_59 -> V_64 , 0 , V_59 -> V_62 ) ;
return V_59 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_6 ( V_3 -> V_65 , V_59 -> V_64 , V_59 -> V_7 ) ;
F_4 ( V_59 ) ;
}
struct V_66 * F_29 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
F_25 ( V_59 -> type != V_61 ) ;
return (struct V_66 * ) V_59 -> V_64 ;
}
struct V_67 * F_30 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
if ( V_59 -> type == V_60 )
return (struct V_67 * ) V_59 -> V_64 ;
return (struct V_67 * )
( V_59 -> V_64 + F_27 ( V_3 -> V_63 ) ) ;
}
struct V_68 * F_31 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
unsigned int V_49 )
{
V_49 ++ ;
if ( V_59 -> type == V_61 )
V_49 ++ ;
return (struct V_68 * )
( V_59 -> V_64 + ( V_49 * F_27 ( V_3 -> V_63 ) ) ) ;
}
static void F_32 ( struct V_2 * V_3 ,
unsigned int V_69 ,
struct V_70 * V_71 , T_2 V_7 )
{
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
if ( V_69 > V_76 )
F_35 ( & V_73 -> V_77 ,
sizeof( struct V_70 ) * V_69 ,
V_71 , V_7 ) ;
else if ( V_69 <= V_78 )
return F_6 ( V_3 -> V_79 ,
V_71 , V_7 ) ;
else
return F_6 ( V_3 -> V_80 ,
V_71 , V_7 ) ;
}
static struct V_70 * F_36 ( struct V_2 * V_3 ,
unsigned int V_69 , T_2 * V_7 ,
T_1 V_81 )
{
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
if ( V_69 > V_76 )
return F_37 ( & V_73 -> V_77 ,
sizeof( struct V_70 ) * V_69 ,
V_7 , V_81 ) ;
else if ( V_69 <= V_78 )
return F_3 ( V_3 -> V_79 ,
V_81 , V_7 ) ;
else
return F_3 ( V_3 -> V_80 ,
V_81 , V_7 ) ;
}
struct V_29 * F_38 (
struct V_82 * V_83 ,
T_4 V_84 )
{
if ( V_83 -> V_85 & V_86 )
return F_39 ( & V_83 -> V_87 -> V_88 ,
V_84 >> V_89 ) ;
return V_83 -> V_30 ;
}
static struct V_29 * F_40 (
struct V_90 * V_87 ,
T_4 V_84 )
{
return F_39 ( & V_87 -> V_88 ,
V_84 >> V_89 ) ;
}
struct V_29 * F_41 (
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
static int F_42 ( struct V_2 * V_3 ,
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
V_97 = F_40 ( V_87 , V_96 ) ;
if ( V_95 != V_97 ) {
F_43 ( V_3 , L_8
L_9
L_10 ,
( unsigned long long ) V_96 ,
V_94 ,
V_97 ) ;
return - V_99 ;
}
}
V_97 = F_40 ( V_87 , V_96 ) ;
if ( V_97 != V_95 ) {
V_96 = V_95 -> V_37 -> V_7 - V_98 ;
V_97 = F_40 ( V_87 , V_96 ) ;
}
if ( V_97 == V_95 ) {
F_43 ( V_3 , L_11
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
struct V_90 * F_44 ( struct V_2 * V_3 ,
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
V_87 -> V_105 = F_36 ( V_3 ,
V_69 , & V_87 -> V_106 ,
V_81 ) ;
if ( ! V_87 -> V_105 )
goto V_107;
memset ( V_87 -> V_105 , 0 ,
sizeof( struct V_70 ) * V_69 ) ;
V_87 -> V_108 =
F_45 ( V_3 , true , true , V_81 ) ;
if ( ! V_87 -> V_108 )
goto V_107;
F_46 ( & V_87 -> V_88 , V_109 ) ;
for ( V_94 = 1 ; V_94 < V_92 ; V_94 ++ ) {
V_87 -> V_93 [ V_94 ] =
F_18 ( V_3 , 2 , 1 , V_110 , V_81 ) ;
V_95 = V_87 -> V_93 [ V_94 ] ;
if ( ! V_95 )
goto V_111;
V_95 -> V_91 = V_94 ;
V_96 = V_95 -> V_37 -> V_7 |
F_47 ( V_112 ) |
V_95 -> V_4 ;
V_87 -> V_105 [ V_94 ] . V_113 =
F_9 ( V_96 ) ;
F_21 ( V_3 , L_17 ,
V_94 , ( unsigned long long ) V_96 ) ;
V_100 = ( unsigned long )
( V_95 -> V_37 -> V_7 >> V_89 ) ;
V_44 = F_48 ( & V_87 -> V_88 ,
V_100 , V_95 ) ;
if ( V_44 ) {
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
goto V_111;
}
}
#if V_114
if ( F_42 ( V_3 , V_92 , V_87 ) )
goto V_111;
#endif
return V_87 ;
V_111:
for ( V_94 = 1 ; V_94 < V_92 ; V_94 ++ ) {
V_95 = V_87 -> V_93 [ V_94 ] ;
if ( V_95 ) {
V_96 = V_95 -> V_37 -> V_7 ;
F_49 ( & V_87 -> V_88 ,
V_96 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
}
}
F_50 ( V_3 , V_87 -> V_108 ) ;
V_107:
F_4 ( V_87 -> V_93 ) ;
V_104:
F_4 ( V_87 ) ;
V_103:
V_3 -> V_101 -- ;
return NULL ;
}
void F_51 ( struct V_2 * V_3 ,
struct V_68 * V_115 ,
struct V_90 * V_87 )
{
T_3 V_116 ;
V_116 = F_52 ( V_87 -> V_69 ) - 2 ;
F_21 ( V_3 , L_18 ,
1 << ( V_116 + 1 ) ) ;
V_115 -> V_117 &= F_13 ( ~ V_118 ) ;
V_115 -> V_117 |= F_13 ( F_53 ( V_116 )
| V_119 ) ;
V_115 -> V_120 = F_9 ( V_87 -> V_106 ) ;
}
void F_54 ( struct V_2 * V_3 ,
struct V_68 * V_115 ,
struct V_82 * V_83 )
{
T_2 V_96 ;
V_115 -> V_117 &= F_13 ( ~ ( V_118 | V_119 ) ) ;
V_96 = F_55 ( V_83 -> V_30 -> V_40 , V_83 -> V_30 -> V_39 ) ;
V_115 -> V_120 = F_9 ( V_96 | V_83 -> V_30 -> V_4 ) ;
}
void F_56 ( struct V_2 * V_3 ,
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
F_49 ( & V_87 -> V_88 ,
V_96 >> V_89 ) ;
F_15 ( V_3 , V_95 ) ;
V_87 -> V_93 [ V_94 ] = NULL ;
}
}
F_50 ( V_3 , V_87 -> V_108 ) ;
V_3 -> V_101 -- ;
if ( V_87 -> V_105 )
F_32 ( V_3 ,
V_87 -> V_69 ,
V_87 -> V_105 ,
V_87 -> V_106 ) ;
if ( V_87 )
F_4 ( V_87 -> V_93 ) ;
F_4 ( V_87 ) ;
}
static void F_57 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
F_58 ( & V_83 -> V_121 ) ;
V_83 -> V_121 . V_122 = ( unsigned long ) V_83 ;
V_83 -> V_121 . V_123 = V_124 ;
V_83 -> V_3 = V_3 ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
int V_125 )
{
struct V_126 * V_127 ;
struct V_126 * V_128 ;
struct V_126 * V_129 ;
struct V_130 * V_131 ;
if ( V_48 -> V_132 == 0 ||
V_48 -> V_132 > F_60 ( V_3 -> V_133 ) ) {
F_21 ( V_3 , L_19 ) ;
return;
}
V_128 = & ( V_3 -> V_134 [ V_48 -> V_132 - 1 ] . V_135 ) ;
if ( F_61 ( V_128 ) )
return;
F_62 (tt, tt_list_head) {
V_131 = F_63 ( V_127 , struct V_130 , V_136 ) ;
if ( V_131 -> V_125 == V_125 )
break;
}
if ( V_131 -> V_125 != V_125 )
return;
V_129 = V_127 -> V_16 ;
V_131 = F_63 ( V_127 , struct V_130 ,
V_136 ) ;
do {
F_64 ( V_127 ) ;
F_4 ( V_131 ) ;
V_127 = V_129 ;
if ( F_61 ( V_128 ) )
break;
V_129 = V_127 -> V_16 ;
V_131 = F_63 ( V_127 , struct V_130 ,
V_136 ) ;
} while ( V_131 -> V_125 == V_125 );
}
int F_65 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_137 * V_138 ,
struct V_139 * V_127 , T_1 V_81 )
{
struct V_130 * V_131 ;
unsigned int V_140 ;
int V_8 , V_141 ;
if ( ! V_127 -> V_142 )
V_140 = 1 ;
else
V_140 = V_138 -> V_143 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ , V_131 ++ ) {
struct V_144 * V_145 ;
V_131 = F_2 ( sizeof( * V_131 ) , V_81 ) ;
if ( ! V_131 )
goto V_146;
F_19 ( & V_131 -> V_136 ) ;
F_66 ( & V_131 -> V_136 ,
& V_3 -> V_134 [ V_48 -> V_132 - 1 ] . V_135 ) ;
V_131 -> V_125 = V_48 -> V_147 -> V_125 ;
if ( V_127 -> V_142 )
V_131 -> V_148 = V_8 + 1 ;
V_145 = & V_131 -> V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_19 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
return 0 ;
V_146:
F_59 ( V_3 , V_48 , V_48 -> V_147 -> V_125 ) ;
return - V_43 ;
}
void F_67 ( struct V_2 * V_3 , int V_125 )
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
if ( V_77 -> V_131 )
V_152 = V_77 -> V_131 -> V_156 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_77 -> V_54 [ V_8 ] . V_30 )
F_15 ( V_3 , V_77 -> V_54 [ V_8 ] . V_30 ) ;
if ( V_77 -> V_54 [ V_8 ] . V_87 )
F_56 ( V_3 ,
V_77 -> V_54 [ V_8 ] . V_87 ) ;
if ( ! F_61 ( & V_77 -> V_54 [ V_8 ] . V_157 ) )
F_43 ( V_3 , L_20
L_21 ,
V_125 , V_8 ) ;
}
F_59 ( V_3 , V_77 , V_125 ) ;
F_68 ( V_3 , V_77 , V_152 ) ;
if ( V_77 -> V_53 ) {
for ( V_8 = 0 ; V_8 < V_77 -> V_51 ; V_8 ++ )
F_15 ( V_3 , V_77 -> V_53 [ V_8 ] ) ;
F_4 ( V_77 -> V_53 ) ;
}
if ( V_77 -> V_158 )
F_28 ( V_3 , V_77 -> V_158 ) ;
if ( V_77 -> V_159 )
F_28 ( V_3 , V_77 -> V_159 ) ;
F_4 ( V_3 -> V_153 [ V_125 ] ) ;
V_3 -> V_153 [ V_125 ] = NULL ;
}
int F_69 ( struct V_2 * V_3 , int V_125 ,
struct V_137 * V_147 , T_1 V_5 )
{
struct V_47 * V_77 ;
int V_8 ;
if ( V_125 == 0 || V_3 -> V_153 [ V_125 ] ) {
F_43 ( V_3 , L_22 , V_125 ) ;
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
F_57 ( V_3 , & V_77 -> V_54 [ V_8 ] ) ;
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
F_70 ( & V_77 -> V_162 ) ;
F_19 ( & V_77 -> V_163 ) ;
V_77 -> V_147 = V_147 ;
V_3 -> V_154 -> V_155 [ V_125 ] = F_9 ( V_77 -> V_159 -> V_7 ) ;
F_21 ( V_3 , L_25 ,
V_125 ,
& V_3 -> V_154 -> V_155 [ V_125 ] ,
F_71 ( V_3 -> V_154 -> V_155 [ V_125 ] ) ) ;
return 1 ;
V_46:
F_67 ( V_3 , V_125 ) ;
return 0 ;
}
void F_72 ( struct V_2 * V_3 ,
struct V_137 * V_147 )
{
struct V_47 * V_48 ;
struct V_68 * V_164 ;
struct V_29 * V_165 ;
V_48 = V_3 -> V_153 [ V_147 -> V_125 ] ;
V_164 = F_31 ( V_3 , V_48 -> V_158 , 0 ) ;
V_165 = V_48 -> V_54 [ 0 ] . V_30 ;
V_164 -> V_120 = F_9 ( F_55 ( V_165 -> V_33 ,
V_165 -> V_38 )
| V_165 -> V_4 ) ;
}
static T_3 F_73 ( struct V_2 * V_3 ,
struct V_137 * V_147 )
{
struct V_137 * V_166 ;
unsigned int V_167 ;
unsigned int V_168 ;
int V_8 ;
for ( V_166 = V_147 ; V_166 -> V_169 && V_166 -> V_169 -> V_169 ;
V_166 = V_166 -> V_169 )
;
V_168 = V_166 -> V_170 ;
for ( V_8 = 0 , V_167 = 0 ;
V_8 < F_60 ( V_3 -> V_133 ) ; V_8 ++ ) {
T_5 V_171 = V_3 -> V_172 [ V_8 ] ;
if ( V_171 == 0 || V_171 == V_173 )
continue;
if ( ( V_171 == 0x03 ) == ( V_147 -> V_174 == V_175 ) )
V_167 ++ ;
if ( V_167 == V_168 )
return V_8 + 1 ;
}
return 0 ;
}
int F_74 ( struct V_2 * V_3 , struct V_137 * V_147 )
{
struct V_47 * V_77 ;
struct V_68 * V_164 ;
struct V_67 * V_176 ;
T_3 V_177 ;
struct V_137 * V_166 ;
V_77 = V_3 -> V_153 [ V_147 -> V_125 ] ;
if ( V_147 -> V_125 == 0 || ! V_77 ) {
F_43 ( V_3 , L_26 ,
V_147 -> V_125 ) ;
return - V_99 ;
}
V_164 = F_31 ( V_3 , V_77 -> V_158 , 0 ) ;
V_176 = F_30 ( V_3 , V_77 -> V_158 ) ;
V_176 -> V_178 |= F_13 ( F_75 ( 1 ) | V_147 -> V_179 ) ;
switch ( V_147 -> V_174 ) {
case V_175 :
V_176 -> V_178 |= F_13 ( V_180 ) ;
break;
case V_181 :
V_176 -> V_178 |= F_13 ( V_182 ) ;
break;
case V_183 :
V_176 -> V_178 |= F_13 ( V_184 ) ;
break;
case V_185 :
V_176 -> V_178 |= F_13 ( V_186 ) ;
break;
case V_187 :
F_21 ( V_3 , L_27 ) ;
return - V_99 ;
break;
default:
F_76 () ;
}
V_177 = F_73 ( V_3 , V_147 ) ;
if ( ! V_177 )
return - V_99 ;
V_176 -> V_188 |= F_13 ( F_77 ( V_177 ) ) ;
for ( V_166 = V_147 ; V_166 -> V_169 && V_166 -> V_169 -> V_169 ;
V_166 = V_166 -> V_169 )
;
V_77 -> V_189 = V_166 -> V_170 ;
V_77 -> V_132 = V_177 ;
F_21 ( V_3 , L_28 , V_177 ) ;
F_21 ( V_3 , L_29 , V_77 -> V_189 ) ;
if ( ! V_147 -> V_127 || ! V_147 -> V_127 -> V_190 -> V_169 ) {
V_77 -> V_145 = & V_3 -> V_134 [ V_177 - 1 ] . V_145 ;
} else {
struct V_191 * V_134 ;
struct V_130 * V_192 ;
V_134 = & V_3 -> V_134 [ V_177 - 1 ] ;
F_78 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_192 -> V_125 != V_147 -> V_127 -> V_190 -> V_125 )
continue;
if ( ! V_77 -> V_147 -> V_127 -> V_142 ||
( V_147 -> V_127 -> V_142 &&
V_192 -> V_148 == V_77 -> V_147 -> V_148 ) ) {
V_77 -> V_145 = & V_192 -> V_145 ;
V_77 -> V_131 = V_192 ;
break;
}
}
if ( ! V_77 -> V_131 )
F_43 ( V_3 , L_30 ) ;
}
if ( V_147 -> V_127 && V_147 -> V_127 -> V_190 -> V_169 ) {
V_176 -> V_131 = F_13 ( V_147 -> V_127 -> V_190 -> V_125 |
( V_147 -> V_148 << 8 ) ) ;
if ( V_147 -> V_127 -> V_142 )
V_176 -> V_178 |= F_13 ( V_193 ) ;
}
F_21 ( V_3 , L_31 , V_147 -> V_127 ) ;
F_21 ( V_3 , L_32 , V_147 -> V_148 ) ;
V_164 -> V_194 = F_13 ( F_79 ( V_195 ) ) ;
switch ( V_147 -> V_174 ) {
case V_175 :
V_164 -> V_194 |= F_13 ( F_80 ( 512 ) ) ;
break;
case V_181 :
case V_183 :
V_164 -> V_194 |= F_13 ( F_80 ( 64 ) ) ;
break;
case V_185 :
V_164 -> V_194 |= F_13 ( F_80 ( 8 ) ) ;
break;
case V_187 :
F_21 ( V_3 , L_27 ) ;
return - V_99 ;
break;
default:
F_76 () ;
}
V_164 -> V_194 |= F_13 ( F_81 ( 0 ) | F_82 ( 3 ) ) ;
V_164 -> V_120 = F_9 ( V_77 -> V_54 [ 0 ] . V_30 -> V_37 -> V_7 |
V_77 -> V_54 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
unsigned int V_197 ;
V_197 = F_84 ( V_83 -> V_198 . V_199 , 1 , 16 ) - 1 ;
if ( V_197 != V_83 -> V_198 . V_199 - 1 )
F_85 ( & V_147 -> V_77 ,
L_33 ,
V_83 -> V_198 . V_200 ,
1 << V_197 ,
V_147 -> V_174 == V_183 ? L_4 : L_34 ) ;
if ( V_147 -> V_174 == V_183 ) {
V_197 += 3 ;
}
return V_197 ;
}
static unsigned int F_86 ( struct V_137 * V_147 ,
struct V_196 * V_83 , unsigned int V_201 ,
unsigned int V_202 , unsigned int V_203 )
{
unsigned int V_197 ;
V_197 = F_52 ( V_201 ) - 1 ;
V_197 = F_84 ( V_197 , V_202 , V_203 ) ;
if ( ( 1 << V_197 ) != V_201 )
F_85 ( & V_147 -> V_77 ,
L_35 ,
V_83 -> V_198 . V_200 ,
1 << V_197 ,
V_201 ) ;
return V_197 ;
}
static unsigned int F_87 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
return F_86 ( V_147 , V_83 ,
V_83 -> V_198 . V_199 , 0 , 15 ) ;
}
static unsigned int F_88 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
return F_86 ( V_147 , V_83 ,
V_83 -> V_198 . V_199 * 8 , 3 , 10 ) ;
}
static unsigned int F_89 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
unsigned int V_197 = 0 ;
switch ( V_147 -> V_174 ) {
case V_181 :
if ( F_90 ( & V_83 -> V_198 ) ||
F_91 ( & V_83 -> V_198 ) ) {
V_197 = F_87 ( V_147 , V_83 ) ;
break;
}
case V_175 :
if ( F_92 ( & V_83 -> V_198 ) ||
F_93 ( & V_83 -> V_198 ) ) {
V_197 = F_83 ( V_147 , V_83 ) ;
}
break;
case V_183 :
if ( F_93 ( & V_83 -> V_198 ) ) {
V_197 = F_83 ( V_147 , V_83 ) ;
break;
}
case V_185 :
if ( F_92 ( & V_83 -> V_198 ) ||
F_93 ( & V_83 -> V_198 ) ) {
V_197 = F_88 ( V_147 , V_83 ) ;
}
break;
default:
F_76 () ;
}
return F_94 ( V_197 ) ;
}
static T_3 F_95 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
if ( V_147 -> V_174 != V_175 ||
! F_93 ( & V_83 -> V_198 ) )
return 0 ;
return V_83 -> V_204 . V_205 ;
}
static T_3 F_96 ( struct V_137 * V_147 ,
struct V_196 * V_83 )
{
int V_206 ;
T_3 type ;
V_206 = F_97 ( & V_83 -> V_198 ) ;
if ( F_90 ( & V_83 -> V_198 ) ) {
type = F_79 ( V_195 ) ;
} else if ( F_91 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_79 ( V_207 ) ;
else
type = F_79 ( V_208 ) ;
} else if ( F_93 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_79 ( V_209 ) ;
else
type = F_79 ( V_210 ) ;
} else if ( F_92 ( & V_83 -> V_198 ) ) {
if ( V_206 )
type = F_79 ( V_211 ) ;
else
type = F_79 ( V_212 ) ;
} else {
F_76 () ;
}
return type ;
}
static T_3 F_98 ( struct V_2 * V_3 ,
struct V_137 * V_147 ,
struct V_196 * V_83 )
{
int V_213 ;
int V_214 ;
if ( F_90 ( & V_83 -> V_198 ) ||
F_91 ( & V_83 -> V_198 ) )
return 0 ;
if ( V_147 -> V_174 == V_175 )
return F_99 ( V_83 -> V_204 . V_215 ) ;
V_214 = F_100 ( F_101 ( & V_83 -> V_198 ) ) ;
V_213 = ( F_101 ( & V_83 -> V_198 ) & 0x1800 ) >> 11 ;
return V_214 * ( V_213 + 1 ) ;
}
int F_102 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_137 * V_147 ,
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
V_49 = F_103 ( & V_83 -> V_198 ) ;
V_115 = F_31 ( V_3 , V_48 -> V_158 , V_49 ) ;
type = F_104 ( & V_83 -> V_198 ) ;
V_48 -> V_54 [ V_49 ] . V_217 =
F_18 ( V_3 , 2 , 1 , type , V_81 ) ;
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
V_165 = V_48 -> V_54 [ V_49 ] . V_217 ;
V_115 -> V_120 = F_9 ( V_165 -> V_37 -> V_7 | V_165 -> V_4 ) ;
V_115 -> V_117 = F_13 ( F_89 ( V_147 , V_83 )
| F_105 ( F_95 ( V_147 , V_83 ) ) ) ;
if ( ! F_93 ( & V_83 -> V_198 ) )
V_115 -> V_194 = F_13 ( F_82 ( 3 ) ) ;
else
V_115 -> V_194 = F_13 ( F_82 ( 0 ) ) ;
V_115 -> V_194 |= F_13 ( F_96 ( V_147 , V_83 ) ) ;
switch ( V_147 -> V_174 ) {
case V_175 :
V_214 = F_101 ( & V_83 -> V_198 ) ;
V_115 -> V_194 |= F_13 ( F_80 ( V_214 ) ) ;
V_214 = V_83 -> V_204 . V_219 ;
V_115 -> V_194 |= F_13 ( F_81 ( V_214 ) ) ;
break;
case V_181 :
if ( F_93 ( & V_83 -> V_198 ) ||
F_92 ( & V_83 -> V_198 ) ) {
V_213 = ( F_101 ( & V_83 -> V_198 )
& 0x1800 ) >> 11 ;
V_115 -> V_194 |= F_13 ( F_81 ( V_213 ) ) ;
}
case V_183 :
case V_185 :
V_214 = F_100 ( F_101 ( & V_83 -> V_198 ) ) ;
V_115 -> V_194 |= F_13 ( F_80 ( V_214 ) ) ;
break;
default:
F_76 () ;
}
V_216 = F_98 ( V_3 , V_147 , V_83 ) ;
V_115 -> V_220 = F_13 ( F_106 ( V_216 ) ) ;
if ( F_90 ( & V_83 -> V_198 ) && V_3 -> V_221 == 0x100 )
V_115 -> V_220 |= F_13 ( F_107 ( 8 ) ) ;
else
V_115 -> V_220 |=
F_13 ( F_107 ( V_216 ) ) ;
return 0 ;
}
void F_108 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_196 * V_83 )
{
unsigned int V_49 ;
struct V_68 * V_115 ;
V_49 = F_103 ( & V_83 -> V_198 ) ;
V_115 = F_31 ( V_3 , V_48 -> V_158 , V_49 ) ;
V_115 -> V_117 = 0 ;
V_115 -> V_194 = 0 ;
V_115 -> V_120 = 0 ;
V_115 -> V_220 = 0 ;
}
void F_109 ( struct V_222 * V_223 )
{
V_223 -> V_224 = 0 ;
V_223 -> V_225 = 0 ;
V_223 -> V_226 = 0 ;
V_223 -> V_227 = 0 ;
V_223 -> type = 0 ;
V_223 -> V_216 = 0 ;
}
void F_110 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_66 * V_228 ,
struct V_47 * V_48 )
{
struct V_222 * V_223 ;
struct V_68 * V_115 ;
unsigned int V_229 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_223 = & V_48 -> V_54 [ V_8 ] . V_223 ;
if ( ! F_111 ( V_228 , V_8 ) && F_112 ( V_228 , V_8 ) ) {
F_109 ( V_223 ) ;
continue;
}
if ( F_111 ( V_228 , V_8 ) ) {
V_115 = F_31 ( V_3 , V_158 , V_8 ) ;
V_229 = F_113 ( F_10 ( V_115 -> V_194 ) ) ;
if ( V_229 != V_210 && V_229 != V_212 &&
V_229 != V_209 &&
V_229 != V_211 )
continue;
V_223 -> V_224 = F_114 (
F_10 ( V_115 -> V_117 ) ) ;
V_223 -> V_225 = F_115 (
F_10 ( V_115 -> V_117 ) ) + 1 ;
V_223 -> V_226 = F_116 (
F_10 ( V_115 -> V_194 ) ) + 1 ;
V_223 -> V_227 = F_117 (
F_10 ( V_115 -> V_194 ) ) ;
V_223 -> type = V_229 ;
V_223 -> V_216 = F_118 (
F_10 ( V_115 -> V_220 ) ) ;
}
}
}
void F_119 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 ,
unsigned int V_49 )
{
struct V_68 * V_230 ;
struct V_68 * V_231 ;
V_230 = F_31 ( V_3 , V_159 , V_49 ) ;
V_231 = F_31 ( V_3 , V_158 , V_49 ) ;
V_231 -> V_117 = V_230 -> V_117 ;
V_231 -> V_194 = V_230 -> V_194 ;
V_231 -> V_120 = V_230 -> V_120 ;
V_231 -> V_220 = V_230 -> V_220 ;
}
void F_120 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 )
{
struct V_67 * V_232 ;
struct V_67 * V_233 ;
V_232 = F_30 ( V_3 , V_158 ) ;
V_233 = F_30 ( V_3 , V_159 ) ;
V_232 -> V_178 = V_233 -> V_178 ;
V_232 -> V_188 = V_233 -> V_188 ;
V_232 -> V_131 = V_233 -> V_131 ;
V_232 -> V_234 = V_233 -> V_234 ;
}
static int F_121 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_235 * V_77 = F_34 ( V_3 ) -> V_74 . V_75 ;
int V_236 = F_122 ( V_3 -> V_237 ) ;
F_21 ( V_3 , L_36 , V_236 ) ;
if ( ! V_236 )
return 0 ;
V_3 -> V_238 = F_2 ( sizeof( * V_3 -> V_238 ) , V_5 ) ;
if ( ! V_3 -> V_238 )
goto V_239;
V_3 -> V_238 -> V_240 = F_37 ( V_77 ,
V_236 * sizeof( T_4 ) ,
& V_3 -> V_238 -> V_241 , V_5 ) ;
if ( ! V_3 -> V_238 -> V_240 )
goto V_242;
V_3 -> V_238 -> V_243 = F_2 ( sizeof( void * ) * V_236 , V_5 ) ;
if ( ! V_3 -> V_238 -> V_243 )
goto V_244;
V_3 -> V_238 -> V_245 =
F_2 ( sizeof( T_2 ) * V_236 , V_5 ) ;
if ( ! V_3 -> V_238 -> V_245 )
goto V_246;
V_3 -> V_154 -> V_155 [ 0 ] = F_9 ( V_3 -> V_238 -> V_241 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
T_2 V_7 ;
void * V_247 = F_37 ( V_77 , V_3 -> V_248 , & V_7 ,
V_5 ) ;
if ( ! V_247 )
goto V_249;
V_3 -> V_238 -> V_240 [ V_8 ] = V_7 ;
V_3 -> V_238 -> V_243 [ V_8 ] = V_247 ;
V_3 -> V_238 -> V_245 [ V_8 ] = V_7 ;
}
return 0 ;
V_249:
for ( V_8 = V_8 - 1 ; V_8 >= 0 ; V_8 -- ) {
F_35 ( V_77 , V_3 -> V_248 ,
V_3 -> V_238 -> V_243 [ V_8 ] ,
V_3 -> V_238 -> V_245 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_238 -> V_245 ) ;
V_246:
F_4 ( V_3 -> V_238 -> V_243 ) ;
V_244:
F_35 ( V_77 , V_236 * sizeof( T_4 ) ,
V_3 -> V_238 -> V_240 ,
V_3 -> V_238 -> V_241 ) ;
V_242:
F_4 ( V_3 -> V_238 ) ;
V_3 -> V_238 = NULL ;
V_239:
return - V_43 ;
}
static void F_123 ( struct V_2 * V_3 )
{
int V_236 ;
int V_8 ;
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
if ( ! V_3 -> V_238 )
return;
V_236 = F_122 ( V_3 -> V_237 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
F_35 ( & V_73 -> V_77 , V_3 -> V_248 ,
V_3 -> V_238 -> V_243 [ V_8 ] ,
V_3 -> V_238 -> V_245 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_238 -> V_245 ) ;
F_4 ( V_3 -> V_238 -> V_243 ) ;
F_35 ( & V_73 -> V_77 , V_236 * sizeof( T_4 ) ,
V_3 -> V_238 -> V_240 ,
V_3 -> V_238 -> V_241 ) ;
F_4 ( V_3 -> V_238 ) ;
V_3 -> V_238 = NULL ;
}
struct V_250 * F_45 ( struct V_2 * V_3 ,
bool V_251 , bool V_252 ,
T_1 V_81 )
{
struct V_250 * V_253 ;
V_253 = F_2 ( sizeof( * V_253 ) , V_81 ) ;
if ( ! V_253 )
return NULL ;
if ( V_251 ) {
V_253 -> V_158 =
F_24 ( V_3 , V_61 ,
V_81 ) ;
if ( ! V_253 -> V_158 ) {
F_4 ( V_253 ) ;
return NULL ;
}
}
if ( V_252 ) {
V_253 -> V_254 =
F_2 ( sizeof( struct V_254 ) , V_81 ) ;
if ( ! V_253 -> V_254 ) {
F_28 ( V_3 , V_253 -> V_158 ) ;
F_4 ( V_253 ) ;
return NULL ;
}
F_70 ( V_253 -> V_254 ) ;
}
V_253 -> V_255 = 0 ;
F_19 ( & V_253 -> V_163 ) ;
return V_253 ;
}
void F_124 ( struct V_2 * V_3 , struct V_256 * V_256 )
{
if ( V_256 ) {
F_4 ( V_256 -> V_257 [ 0 ] ) ;
F_4 ( V_256 ) ;
}
}
void F_50 ( struct V_2 * V_3 ,
struct V_250 * V_253 )
{
F_28 ( V_3 ,
V_253 -> V_158 ) ;
F_4 ( V_253 -> V_254 ) ;
F_4 ( V_253 ) ;
}
void F_125 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
struct V_178 * V_178 , * V_16 ;
unsigned long V_5 ;
int V_62 ;
int V_8 ;
V_62 = sizeof( struct V_258 ) * ( V_3 -> V_259 . V_260 ) ;
if ( V_3 -> V_259 . V_261 )
F_35 ( & V_73 -> V_77 , V_62 ,
V_3 -> V_259 . V_261 , V_3 -> V_259 . V_262 ) ;
V_3 -> V_259 . V_261 = NULL ;
F_21 ( V_3 , L_37 ) ;
if ( V_3 -> V_263 )
F_15 ( V_3 , V_3 -> V_263 ) ;
V_3 -> V_263 = NULL ;
F_21 ( V_3 , L_38 ) ;
if ( V_3 -> V_264 )
F_15 ( V_3 , V_3 -> V_264 ) ;
V_3 -> V_264 = NULL ;
F_21 ( V_3 , L_39 ) ;
for ( V_8 = 1 ; V_8 < V_265 ; ++ V_8 )
F_67 ( V_3 , V_8 ) ;
if ( V_3 -> V_10 )
F_126 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_21 ( V_3 , L_40 ) ;
if ( V_3 -> V_65 )
F_126 ( V_3 -> V_65 ) ;
V_3 -> V_65 = NULL ;
F_21 ( V_3 , L_41 ) ;
if ( V_3 -> V_79 )
F_126 ( V_3 -> V_79 ) ;
V_3 -> V_79 = NULL ;
F_21 ( V_3 , L_42 ) ;
if ( V_3 -> V_80 )
F_126 ( V_3 -> V_80 ) ;
V_3 -> V_80 = NULL ;
F_21 ( V_3 , L_43 ) ;
if ( V_3 -> V_154 )
F_35 ( & V_73 -> V_77 , sizeof( * V_3 -> V_154 ) ,
V_3 -> V_154 , V_3 -> V_154 -> V_7 ) ;
V_3 -> V_154 = NULL ;
F_123 ( V_3 ) ;
F_127 ( & V_3 -> V_266 , V_5 ) ;
F_128 (dev_info, next, &xhci->lpm_failed_devs, list) {
F_64 ( & V_178 -> V_267 ) ;
F_4 ( V_178 ) ;
}
F_129 ( & V_3 -> V_266 , V_5 ) ;
V_3 -> V_268 = 0 ;
V_3 -> V_269 = 0 ;
F_4 ( V_3 -> V_270 ) ;
F_4 ( V_3 -> V_271 ) ;
F_4 ( V_3 -> V_172 ) ;
F_4 ( V_3 -> V_134 ) ;
V_3 -> V_248 = 0 ;
V_3 -> V_272 = 0 ;
V_3 -> V_273 [ 0 ] . V_274 = 0 ;
V_3 -> V_273 [ 1 ] . V_274 = 0 ;
}
static int F_130 ( struct V_2 * V_3 ,
struct V_1 * V_275 ,
union V_55 * V_276 ,
union V_55 * V_277 ,
T_2 V_278 ,
struct V_1 * V_279 ,
char * V_280 , int V_281 )
{
unsigned long long V_282 ;
unsigned long long V_283 ;
struct V_1 * V_6 ;
V_282 = F_55 ( V_275 , V_276 ) ;
V_283 = F_55 ( V_275 , V_277 ) ;
V_6 = F_131 ( V_275 , V_276 , V_277 , V_278 ) ;
if ( V_6 != V_279 ) {
F_43 ( V_3 , L_44 ,
V_280 , V_281 ) ;
F_43 ( V_3 , L_45
L_46 ,
V_275 ,
( unsigned long long ) V_278 ) ;
F_43 ( V_3 , L_47
L_48 ,
V_276 , V_282 ,
V_277 , V_283 ) ;
F_43 ( V_3 , L_49 ,
V_279 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , T_1 V_81 )
{
struct {
T_2 V_278 ;
struct V_1 * V_279 ;
} V_284 [] = {
{ 0 , NULL } ,
{ V_3 -> V_263 -> V_37 -> V_7 - 16 , NULL } ,
{ V_3 -> V_263 -> V_37 -> V_7 - 1 , NULL } ,
{ V_3 -> V_263 -> V_37 -> V_7 , V_3 -> V_263 -> V_37 } ,
{ V_3 -> V_263 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 ,
V_3 -> V_263 -> V_37 } ,
{ V_3 -> V_263 -> V_37 -> V_7 + ( V_12 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_263 -> V_37 -> V_7 + ( V_12 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_275 ;
union V_55 * V_276 ;
union V_55 * V_277 ;
T_2 V_278 ;
struct V_1 * V_279 ;
} V_285 [] = {
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = V_3 -> V_263 -> V_37 -> V_9 ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_278 = V_3 -> V_264 -> V_37 -> V_7 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = V_3 -> V_263 -> V_37 -> V_9 ,
. V_277 = & V_3 -> V_264 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_278 = V_3 -> V_264 -> V_37 -> V_7 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = V_3 -> V_264 -> V_37 -> V_9 ,
. V_277 = & V_3 -> V_264 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_278 = V_3 -> V_264 -> V_37 -> V_7 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = & V_3 -> V_263 -> V_37 -> V_9 [ 0 ] ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ 3 ] ,
. V_278 = V_3 -> V_263 -> V_37 -> V_7 + 4 * 16 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = & V_3 -> V_263 -> V_37 -> V_9 [ 3 ] ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ 6 ] ,
. V_278 = V_3 -> V_263 -> V_37 -> V_7 + 2 * 16 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = & V_3 -> V_263 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ 1 ] ,
. V_278 = V_3 -> V_263 -> V_37 -> V_7 + 2 * 16 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = & V_3 -> V_263 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ 1 ] ,
. V_278 = V_3 -> V_263 -> V_37 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_279 = NULL ,
} ,
{ . V_275 = V_3 -> V_263 -> V_37 ,
. V_276 = & V_3 -> V_263 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_277 = & V_3 -> V_263 -> V_37 -> V_9 [ 1 ] ,
. V_278 = V_3 -> V_264 -> V_37 -> V_7 + 2 * 16 ,
. V_279 = NULL ,
} ,
} ;
unsigned int V_286 ;
int V_8 , V_44 ;
V_286 = F_133 ( V_284 ) ;
for ( V_8 = 0 ; V_8 < V_286 ; V_8 ++ ) {
V_44 = F_130 ( V_3 ,
V_3 -> V_263 -> V_37 ,
V_3 -> V_263 -> V_37 -> V_9 ,
& V_3 -> V_263 -> V_37 -> V_9 [ V_12 - 1 ] ,
V_284 [ V_8 ] . V_278 ,
V_284 [ V_8 ] . V_279 ,
L_50 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_286 = F_133 ( V_285 ) ;
for ( V_8 = 0 ; V_8 < V_286 ; V_8 ++ ) {
V_44 = F_130 ( V_3 ,
V_285 [ V_8 ] . V_275 ,
V_285 [ V_8 ] . V_276 ,
V_285 [ V_8 ] . V_277 ,
V_285 [ V_8 ] . V_278 ,
V_285 [ V_8 ] . V_279 ,
L_51 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_21 ( V_3 , L_52 ) ;
return 0 ;
}
static void F_134 ( struct V_2 * V_3 )
{
T_4 V_287 ;
T_2 V_120 ;
V_120 = F_55 ( V_3 -> V_263 -> V_40 ,
V_3 -> V_263 -> V_39 ) ;
if ( V_120 == 0 && ! F_135 () )
F_43 ( V_3 , L_53
L_54 ) ;
V_287 = F_136 ( V_3 , & V_3 -> V_288 -> V_289 ) ;
V_287 &= V_290 ;
V_287 &= ~ V_291 ;
F_21 ( V_3 , L_55
L_56 ) ;
F_137 ( V_3 , ( ( T_4 ) V_120 & ( T_4 ) ~ V_290 ) | V_287 ,
& V_3 -> V_288 -> V_289 ) ;
}
static void F_138 ( struct V_2 * V_3 , unsigned int V_140 ,
T_6 T_7 * V_96 , T_5 V_292 )
{
T_3 V_287 , V_293 , V_294 ;
int V_8 ;
if ( V_292 > 0x03 ) {
F_43 ( V_3 , L_57
L_58 ,
V_96 , V_292 ) ;
return;
}
V_287 = F_139 ( V_3 , V_96 + 2 ) ;
V_293 = F_140 ( V_287 ) ;
V_294 = F_141 ( V_287 ) ;
F_21 ( V_3 , L_59
L_60 ,
V_96 , V_293 , V_294 , V_292 ) ;
if ( V_293 == 0 || ( V_293 + V_294 - 1 ) > V_140 )
return;
if ( ( V_3 -> V_221 == 0x96 ) && ( V_292 != 0x03 ) &&
( V_287 & V_295 ) ) {
F_21 ( V_3 , L_61 ) ;
V_3 -> V_296 = 1 ;
}
if ( ( V_3 -> V_221 >= 0x100 ) && ( V_292 != 0x03 ) ) {
F_21 ( V_3 , L_62 ) ;
V_3 -> V_296 = 1 ;
if ( V_287 & V_297 ) {
F_21 ( V_3 , L_63 ) ;
V_3 -> V_298 = 1 ;
}
}
V_293 -- ;
for ( V_8 = V_293 ; V_8 < ( V_293 + V_294 ) ; V_8 ++ ) {
if ( V_3 -> V_172 [ V_8 ] != 0 ) {
F_43 ( V_3 , L_64
L_65 , V_96 , V_8 ) ;
F_43 ( V_3 , L_66
L_67 ,
V_3 -> V_172 [ V_8 ] , V_292 ) ;
if ( V_3 -> V_172 [ V_8 ] != V_292 &&
V_3 -> V_172 [ V_8 ] != V_173 ) {
if ( V_3 -> V_172 [ V_8 ] == 0x03 )
V_3 -> V_269 -- ;
else
V_3 -> V_268 -- ;
V_3 -> V_172 [ V_8 ] = V_173 ;
}
continue;
}
V_3 -> V_172 [ V_8 ] = V_292 ;
if ( V_292 == 0x03 )
V_3 -> V_269 ++ ;
else
V_3 -> V_268 ++ ;
}
}
static int F_142 ( struct V_2 * V_3 , T_1 V_5 )
{
T_6 T_7 * V_96 ;
T_3 V_299 ;
unsigned int V_140 ;
int V_8 , V_141 , V_300 ;
V_96 = & V_3 -> V_301 -> V_63 ;
V_299 = F_143 ( F_139 ( V_3 , V_96 ) ) ;
if ( V_299 == 0 ) {
F_144 ( V_3 , L_68
L_69 ) ;
return - V_302 ;
}
V_140 = F_60 ( V_3 -> V_133 ) ;
V_3 -> V_172 = F_2 ( sizeof( * V_3 -> V_172 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_172 )
return - V_43 ;
V_3 -> V_134 = F_2 ( sizeof( * V_3 -> V_134 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_134 )
return - V_43 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_144 * V_145 ;
F_19 ( & V_3 -> V_134 [ V_8 ] . V_135 ) ;
V_145 = & V_3 -> V_134 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_19 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
V_96 = & V_3 -> V_301 -> V_303 + V_299 ;
while ( 1 ) {
T_3 V_304 ;
V_304 = F_139 ( V_3 , V_96 ) ;
if ( F_145 ( V_304 ) == V_305 )
F_138 ( V_3 , V_140 , V_96 ,
( T_5 ) F_146 ( V_304 ) ) ;
V_299 = F_147 ( V_304 ) ;
if ( ! V_299 || ( V_3 -> V_268 + V_3 -> V_269 )
== V_140 )
break;
V_96 += V_299 ;
}
if ( V_3 -> V_268 == 0 && V_3 -> V_269 == 0 ) {
F_43 ( V_3 , L_70 ) ;
return - V_302 ;
}
F_21 ( V_3 , L_71 ,
V_3 -> V_268 , V_3 -> V_269 ) ;
if ( V_3 -> V_269 > 15 ) {
F_21 ( V_3 , L_72 ) ;
V_3 -> V_269 = 15 ;
}
if ( V_3 -> V_268 > V_306 ) {
F_21 ( V_3 , L_73 ,
V_306 ) ;
V_3 -> V_268 = V_306 ;
}
if ( V_3 -> V_268 ) {
V_3 -> V_270 = F_148 ( sizeof( * V_3 -> V_270 ) *
V_3 -> V_268 , V_5 ) ;
if ( ! V_3 -> V_270 )
return - V_43 ;
V_300 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
if ( V_3 -> V_172 [ V_8 ] == 0x03 ||
V_3 -> V_172 [ V_8 ] == 0 ||
V_3 -> V_172 [ V_8 ] == V_173 )
continue;
V_3 -> V_270 [ V_300 ] =
& V_3 -> V_307 -> V_308 +
V_309 * V_8 ;
F_21 ( V_3 , L_74
L_75 , V_8 ,
V_3 -> V_270 [ V_300 ] ) ;
V_300 ++ ;
if ( V_300 == V_3 -> V_268 )
break;
}
}
if ( V_3 -> V_269 ) {
V_3 -> V_271 = F_148 ( sizeof( * V_3 -> V_271 ) *
V_3 -> V_269 , V_5 ) ;
if ( ! V_3 -> V_271 )
return - V_43 ;
V_300 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ )
if ( V_3 -> V_172 [ V_8 ] == 0x03 ) {
V_3 -> V_271 [ V_300 ] =
& V_3 -> V_307 -> V_308 +
V_309 * V_8 ;
F_21 ( V_3 , L_76
L_75 , V_8 ,
V_3 -> V_271 [ V_300 ] ) ;
V_300 ++ ;
if ( V_300 == V_3 -> V_269 )
break;
}
}
return 0 ;
}
int F_149 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_235 * V_77 = F_34 ( V_3 ) -> V_74 . V_75 ;
unsigned int V_20 , V_310 ;
T_4 V_311 ;
struct V_1 * V_6 ;
T_3 V_248 , V_287 ;
int V_8 ;
V_248 = F_139 ( V_3 , & V_3 -> V_307 -> V_248 ) ;
F_21 ( V_3 , L_77 , V_248 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_248 ) != 0 )
break;
V_248 = V_248 >> 1 ;
}
if ( V_8 < 16 )
F_21 ( V_3 , L_78 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_43 ( V_3 , L_79 ) ;
V_3 -> V_272 = 12 ;
V_3 -> V_248 = 1 << V_3 -> V_272 ;
F_21 ( V_3 , L_80 , V_3 -> V_248 / 1024 ) ;
V_20 = F_150 ( F_139 ( V_3 , & V_3 -> V_301 -> V_133 ) ) ;
F_21 ( V_3 , L_81 ,
( unsigned int ) V_20 ) ;
V_310 = F_139 ( V_3 , & V_3 -> V_307 -> V_312 ) ;
V_20 |= ( V_310 & ~ V_313 ) ;
F_21 ( V_3 , L_82 ,
( unsigned int ) V_20 ) ;
F_151 ( V_3 , V_20 , & V_3 -> V_307 -> V_312 ) ;
V_3 -> V_154 = F_37 ( V_77 , sizeof( * V_3 -> V_154 ) , & V_7 ,
V_314 ) ;
if ( ! V_3 -> V_154 )
goto V_46;
memset ( V_3 -> V_154 , 0 , sizeof *( V_3 -> V_154 ) ) ;
V_3 -> V_154 -> V_7 = V_7 ;
F_21 ( V_3 , L_83 ,
( unsigned long long ) V_3 -> V_154 -> V_7 , V_3 -> V_154 ) ;
F_137 ( V_3 , V_7 , & V_3 -> V_307 -> V_315 ) ;
V_3 -> V_10 = F_152 ( L_84 , V_77 ,
V_11 , 64 , V_3 -> V_248 ) ;
V_3 -> V_65 = F_152 ( L_85 , V_77 ,
2112 , 64 , V_3 -> V_248 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_65 )
goto V_46;
V_3 -> V_79 =
F_152 ( L_86 ,
V_77 , V_78 , 16 , 0 ) ;
V_3 -> V_80 =
F_152 ( L_87 ,
V_77 , V_76 , 16 , 0 ) ;
if ( ! V_3 -> V_79 || ! V_3 -> V_80 )
goto V_46;
V_3 -> V_264 = F_18 ( V_3 , 1 , 1 , V_316 , V_5 ) ;
if ( ! V_3 -> V_264 )
goto V_46;
F_21 ( V_3 , L_88 , V_3 -> V_264 ) ;
F_21 ( V_3 , L_89 ,
( unsigned long long ) V_3 -> V_264 -> V_37 -> V_7 ) ;
V_311 = F_136 ( V_3 , & V_3 -> V_307 -> V_264 ) ;
V_311 = ( V_311 & ( T_4 ) V_317 ) |
( V_3 -> V_264 -> V_37 -> V_7 & ( T_4 ) ~ V_317 ) |
V_3 -> V_264 -> V_4 ;
F_21 ( V_3 , L_90 , V_20 ) ;
F_137 ( V_3 , V_311 , & V_3 -> V_307 -> V_264 ) ;
F_153 ( V_3 ) ;
V_20 = F_139 ( V_3 , & V_3 -> V_301 -> V_318 ) ;
V_20 &= V_319 ;
F_21 ( V_3 , L_91
L_92 , V_20 ) ;
V_3 -> V_320 = ( void T_7 * ) V_3 -> V_301 + V_20 ;
F_154 ( V_3 ) ;
F_155 ( V_3 ) ;
V_3 -> V_288 = & V_3 -> V_321 -> V_288 [ 0 ] ;
F_21 ( V_3 , L_93 ) ;
V_3 -> V_263 = F_18 ( V_3 , V_322 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_263 )
goto V_46;
if ( F_132 ( V_3 , V_5 ) < 0 )
goto V_46;
V_3 -> V_259 . V_261 = F_37 ( V_77 ,
sizeof( struct V_258 ) * V_322 , & V_7 ,
V_314 ) ;
if ( ! V_3 -> V_259 . V_261 )
goto V_46;
F_21 ( V_3 , L_94 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_259 . V_261 , 0 , sizeof( struct V_258 ) * V_322 ) ;
V_3 -> V_259 . V_260 = V_322 ;
V_3 -> V_259 . V_262 = V_7 ;
F_21 ( V_3 , L_95 ,
V_3 -> V_259 . V_260 ,
V_3 -> V_259 . V_261 ,
( unsigned long long ) V_3 -> V_259 . V_262 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_263 -> V_37 ; V_20 < V_322 ; V_20 ++ ) {
struct V_258 * V_323 = & V_3 -> V_259 . V_261 [ V_20 ] ;
V_323 -> V_324 = F_9 ( V_6 -> V_7 ) ;
V_323 -> V_325 = F_13 ( V_12 ) ;
V_323 -> V_326 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_139 ( V_3 , & V_3 -> V_288 -> V_327 ) ;
V_20 &= V_328 ;
V_20 |= V_322 ;
F_21 ( V_3 , L_96 ,
V_20 ) ;
F_151 ( V_3 , V_20 , & V_3 -> V_288 -> V_327 ) ;
F_21 ( V_3 , L_97 ) ;
F_21 ( V_3 , L_98 ,
( unsigned long long ) V_3 -> V_259 . V_262 ) ;
V_311 = F_136 ( V_3 , & V_3 -> V_288 -> V_329 ) ;
V_311 &= V_290 ;
V_311 |= ( V_3 -> V_259 . V_262 & ( T_4 ) ~ V_290 ) ;
F_137 ( V_3 , V_311 , & V_3 -> V_288 -> V_329 ) ;
F_134 ( V_3 ) ;
F_21 ( V_3 , L_99 ) ;
F_156 ( V_3 , 0 ) ;
F_70 ( & V_3 -> V_330 ) ;
for ( V_8 = 0 ; V_8 < V_265 ; ++ V_8 )
V_3 -> V_153 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_306 ; ++ V_8 ) {
V_3 -> V_273 [ 0 ] . V_331 [ V_8 ] = 0 ;
V_3 -> V_273 [ 1 ] . V_331 [ V_8 ] = 0 ;
}
if ( F_121 ( V_3 , V_5 ) )
goto V_46;
if ( F_142 ( V_3 , V_5 ) )
goto V_46;
F_19 ( & V_3 -> V_332 ) ;
V_287 = F_139 ( V_3 , & V_3 -> V_307 -> V_333 ) ;
V_287 &= ~ V_334 ;
V_287 |= V_335 ;
F_151 ( V_3 , V_287 , & V_3 -> V_307 -> V_333 ) ;
return 0 ;
V_46:
F_43 ( V_3 , L_100 ) ;
F_157 ( V_3 ) ;
F_158 ( V_3 ) ;
F_125 ( V_3 ) ;
return - V_43 ;
}
