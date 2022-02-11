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
struct V_128 * V_129 , * V_16 ;
bool V_130 = false ;
if ( V_48 -> V_131 == 0 ||
V_48 -> V_131 > F_60 ( V_3 -> V_132 ) ) {
F_21 ( V_3 , L_19 ) ;
return;
}
V_127 = & ( V_3 -> V_133 [ V_48 -> V_131 - 1 ] . V_134 ) ;
F_61 (tt_info, next, tt_list_head, tt_list) {
if ( V_129 -> V_125 == V_125 ) {
V_130 = true ;
F_62 ( & V_129 -> V_135 ) ;
F_4 ( V_129 ) ;
} else if ( V_130 ) {
break;
}
}
}
int F_63 ( struct V_2 * V_3 ,
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
F_64 ( & V_129 -> V_135 ,
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
F_59 ( V_3 , V_48 , V_48 -> V_147 -> V_125 ) ;
return - V_43 ;
}
void F_65 ( struct V_2 * V_3 , int V_125 )
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
F_56 ( V_3 ,
V_77 -> V_54 [ V_8 ] . V_87 ) ;
if ( ! F_66 ( & V_77 -> V_54 [ V_8 ] . V_157 ) )
F_43 ( V_3 , L_20
L_21 ,
V_125 , V_8 ) ;
}
F_59 ( V_3 , V_77 , V_125 ) ;
F_67 ( V_3 , V_77 , V_152 ) ;
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
int F_68 ( struct V_2 * V_3 , int V_125 ,
struct V_136 * V_147 , T_1 V_5 )
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
F_69 ( & V_77 -> V_162 ) ;
F_19 ( & V_77 -> V_163 ) ;
V_77 -> V_147 = V_147 ;
V_3 -> V_154 -> V_155 [ V_125 ] = F_9 ( V_77 -> V_159 -> V_7 ) ;
F_21 ( V_3 , L_25 ,
V_125 ,
& V_3 -> V_154 -> V_155 [ V_125 ] ,
F_70 ( V_3 -> V_154 -> V_155 [ V_125 ] ) ) ;
return 1 ;
V_46:
F_65 ( V_3 , V_125 ) ;
return 0 ;
}
void F_71 ( struct V_2 * V_3 ,
struct V_136 * V_147 )
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
static T_3 F_72 ( struct V_2 * V_3 ,
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
return F_73 ( V_168 , V_166 -> V_174 ) ;
}
int F_74 ( struct V_2 * V_3 , struct V_136 * V_147 )
{
struct V_47 * V_77 ;
struct V_68 * V_164 ;
struct V_67 * V_175 ;
T_3 V_176 ;
struct V_136 * V_166 ;
V_77 = V_3 -> V_153 [ V_147 -> V_125 ] ;
if ( V_147 -> V_125 == 0 || ! V_77 ) {
F_43 ( V_3 , L_26 ,
V_147 -> V_125 ) ;
return - V_99 ;
}
V_164 = F_31 ( V_3 , V_77 -> V_158 , 0 ) ;
V_175 = F_30 ( V_3 , V_77 -> V_158 ) ;
V_175 -> V_177 |= F_13 ( F_75 ( 1 ) | V_147 -> V_178 ) ;
switch ( V_147 -> V_169 ) {
case V_170 :
V_175 -> V_177 |= F_13 ( V_179 ) ;
break;
case V_180 :
V_175 -> V_177 |= F_13 ( V_181 ) ;
break;
case V_182 :
V_175 -> V_177 |= F_13 ( V_183 ) ;
break;
case V_184 :
V_175 -> V_177 |= F_13 ( V_185 ) ;
break;
case V_186 :
F_21 ( V_3 , L_27 ) ;
return - V_99 ;
break;
default:
F_76 () ;
}
V_176 = F_72 ( V_3 , V_147 ) ;
if ( ! V_176 )
return - V_99 ;
V_175 -> V_187 |= F_13 ( F_77 ( V_176 ) ) ;
for ( V_166 = V_147 ; V_166 -> V_173 && V_166 -> V_173 -> V_173 ;
V_166 = V_166 -> V_173 )
;
V_77 -> V_188 = V_166 -> V_174 ;
V_77 -> V_131 = V_176 ;
F_21 ( V_3 , L_28 , V_176 ) ;
F_21 ( V_3 , L_29 , V_77 -> V_188 ) ;
if ( ! V_147 -> V_139 || ! V_147 -> V_139 -> V_189 -> V_173 ) {
V_77 -> V_145 = & V_3 -> V_133 [ V_176 - 1 ] . V_145 ;
} else {
struct V_190 * V_133 ;
struct V_128 * V_191 ;
V_133 = & V_3 -> V_133 [ V_176 - 1 ] ;
F_78 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_191 -> V_125 != V_147 -> V_139 -> V_189 -> V_125 )
continue;
if ( ! V_77 -> V_147 -> V_139 -> V_142 ||
( V_147 -> V_139 -> V_142 &&
V_191 -> V_148 == V_77 -> V_147 -> V_148 ) ) {
V_77 -> V_145 = & V_191 -> V_145 ;
V_77 -> V_129 = V_191 ;
break;
}
}
if ( ! V_77 -> V_129 )
F_43 ( V_3 , L_30 ) ;
}
if ( V_147 -> V_139 && V_147 -> V_139 -> V_189 -> V_173 ) {
V_175 -> V_129 = F_13 ( V_147 -> V_139 -> V_189 -> V_125 |
( V_147 -> V_148 << 8 ) ) ;
if ( V_147 -> V_139 -> V_142 )
V_175 -> V_177 |= F_13 ( V_192 ) ;
}
F_21 ( V_3 , L_31 , V_147 -> V_139 ) ;
F_21 ( V_3 , L_32 , V_147 -> V_148 ) ;
V_164 -> V_193 = F_13 ( F_79 ( V_194 ) ) ;
switch ( V_147 -> V_169 ) {
case V_170 :
V_164 -> V_193 |= F_13 ( F_80 ( 512 ) ) ;
break;
case V_180 :
case V_182 :
V_164 -> V_193 |= F_13 ( F_80 ( 64 ) ) ;
break;
case V_184 :
V_164 -> V_193 |= F_13 ( F_80 ( 8 ) ) ;
break;
case V_186 :
F_21 ( V_3 , L_27 ) ;
return - V_99 ;
break;
default:
F_76 () ;
}
V_164 -> V_193 |= F_13 ( F_81 ( 0 ) | F_82 ( 3 ) ) ;
V_164 -> V_120 = F_9 ( V_77 -> V_54 [ 0 ] . V_30 -> V_37 -> V_7 |
V_77 -> V_54 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
unsigned int V_196 ;
V_196 = F_84 ( V_83 -> V_197 . V_198 , 1 , 16 ) - 1 ;
if ( V_196 != V_83 -> V_197 . V_198 - 1 )
F_85 ( & V_147 -> V_77 ,
L_33 ,
V_83 -> V_197 . V_199 ,
1 << V_196 ,
V_147 -> V_169 == V_182 ? L_4 : L_34 ) ;
if ( V_147 -> V_169 == V_182 ) {
V_196 += 3 ;
}
return V_196 ;
}
static unsigned int F_86 ( struct V_136 * V_147 ,
struct V_195 * V_83 , unsigned int V_200 ,
unsigned int V_201 , unsigned int V_202 )
{
unsigned int V_196 ;
V_196 = F_52 ( V_200 ) - 1 ;
V_196 = F_84 ( V_196 , V_201 , V_202 ) ;
if ( ( 1 << V_196 ) != V_200 )
F_85 ( & V_147 -> V_77 ,
L_35 ,
V_83 -> V_197 . V_199 ,
1 << V_196 ,
V_200 ) ;
return V_196 ;
}
static unsigned int F_87 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
if ( V_83 -> V_197 . V_198 == 0 )
return 0 ;
return F_86 ( V_147 , V_83 ,
V_83 -> V_197 . V_198 , 0 , 15 ) ;
}
static unsigned int F_88 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
return F_86 ( V_147 , V_83 ,
V_83 -> V_197 . V_198 * 8 , 3 , 10 ) ;
}
static unsigned int F_89 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
unsigned int V_196 = 0 ;
switch ( V_147 -> V_169 ) {
case V_180 :
if ( F_90 ( & V_83 -> V_197 ) ||
F_91 ( & V_83 -> V_197 ) ) {
V_196 = F_87 ( V_147 , V_83 ) ;
break;
}
case V_170 :
if ( F_92 ( & V_83 -> V_197 ) ||
F_93 ( & V_83 -> V_197 ) ) {
V_196 = F_83 ( V_147 , V_83 ) ;
}
break;
case V_182 :
if ( F_93 ( & V_83 -> V_197 ) ) {
V_196 = F_83 ( V_147 , V_83 ) ;
break;
}
case V_184 :
if ( F_92 ( & V_83 -> V_197 ) ||
F_93 ( & V_83 -> V_197 ) ) {
V_196 = F_88 ( V_147 , V_83 ) ;
}
break;
default:
F_76 () ;
}
return F_94 ( V_196 ) ;
}
static T_3 F_95 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
if ( V_147 -> V_169 != V_170 ||
! F_93 ( & V_83 -> V_197 ) )
return 0 ;
return V_83 -> V_203 . V_204 ;
}
static T_3 F_96 ( struct V_136 * V_147 ,
struct V_195 * V_83 )
{
int V_205 ;
T_3 type ;
V_205 = F_97 ( & V_83 -> V_197 ) ;
if ( F_90 ( & V_83 -> V_197 ) ) {
type = F_79 ( V_194 ) ;
} else if ( F_91 ( & V_83 -> V_197 ) ) {
if ( V_205 )
type = F_79 ( V_206 ) ;
else
type = F_79 ( V_207 ) ;
} else if ( F_93 ( & V_83 -> V_197 ) ) {
if ( V_205 )
type = F_79 ( V_208 ) ;
else
type = F_79 ( V_209 ) ;
} else if ( F_92 ( & V_83 -> V_197 ) ) {
if ( V_205 )
type = F_79 ( V_210 ) ;
else
type = F_79 ( V_211 ) ;
} else {
F_76 () ;
}
return type ;
}
static T_3 F_98 ( struct V_2 * V_3 ,
struct V_136 * V_147 ,
struct V_195 * V_83 )
{
int V_212 ;
int V_213 ;
if ( F_90 ( & V_83 -> V_197 ) ||
F_91 ( & V_83 -> V_197 ) )
return 0 ;
if ( V_147 -> V_169 == V_170 )
return F_99 ( V_83 -> V_203 . V_214 ) ;
V_213 = F_100 ( F_101 ( & V_83 -> V_197 ) ) ;
V_212 = ( F_101 ( & V_83 -> V_197 ) & 0x1800 ) >> 11 ;
return V_213 * ( V_212 + 1 ) ;
}
int F_102 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_136 * V_147 ,
struct V_195 * V_83 ,
T_1 V_81 )
{
unsigned int V_49 ;
struct V_68 * V_115 ;
struct V_29 * V_165 ;
unsigned int V_213 ;
unsigned int V_212 ;
enum V_19 type ;
T_3 V_215 ;
V_49 = F_103 ( & V_83 -> V_197 ) ;
V_115 = F_31 ( V_3 , V_48 -> V_158 , V_49 ) ;
type = F_104 ( & V_83 -> V_197 ) ;
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
V_165 = V_48 -> V_54 [ V_49 ] . V_216 ;
V_115 -> V_120 = F_9 ( V_165 -> V_37 -> V_7 | V_165 -> V_4 ) ;
V_115 -> V_117 = F_13 ( F_89 ( V_147 , V_83 )
| F_105 ( F_95 ( V_147 , V_83 ) ) ) ;
if ( ! F_93 ( & V_83 -> V_197 ) )
V_115 -> V_193 = F_13 ( F_82 ( 3 ) ) ;
else
V_115 -> V_193 = F_13 ( F_82 ( 0 ) ) ;
V_115 -> V_193 |= F_13 ( F_96 ( V_147 , V_83 ) ) ;
V_213 = F_100 ( F_101 ( & V_83 -> V_197 ) ) ;
V_212 = 0 ;
switch ( V_147 -> V_169 ) {
case V_170 :
V_212 = V_83 -> V_203 . V_218 ;
break;
case V_180 :
if ( F_91 ( & V_83 -> V_197 ) )
V_213 = 512 ;
if ( F_93 ( & V_83 -> V_197 ) ||
F_92 ( & V_83 -> V_197 ) ) {
V_212 = ( F_101 ( & V_83 -> V_197 )
& 0x1800 ) >> 11 ;
}
break;
case V_182 :
case V_184 :
break;
default:
F_76 () ;
}
V_115 -> V_193 |= F_13 ( F_80 ( V_213 ) |
F_81 ( V_212 ) ) ;
V_215 = F_98 ( V_3 , V_147 , V_83 ) ;
V_115 -> V_219 = F_13 ( F_106 ( V_215 ) ) ;
if ( F_90 ( & V_83 -> V_197 ) && V_3 -> V_220 == 0x100 )
V_115 -> V_219 |= F_13 ( F_107 ( 8 ) ) ;
else
V_115 -> V_219 |=
F_13 ( F_107 ( V_215 ) ) ;
return 0 ;
}
void F_108 ( struct V_2 * V_3 ,
struct V_47 * V_48 ,
struct V_195 * V_83 )
{
unsigned int V_49 ;
struct V_68 * V_115 ;
V_49 = F_103 ( & V_83 -> V_197 ) ;
V_115 = F_31 ( V_3 , V_48 -> V_158 , V_49 ) ;
V_115 -> V_117 = 0 ;
V_115 -> V_193 = 0 ;
V_115 -> V_120 = 0 ;
V_115 -> V_219 = 0 ;
}
void F_109 ( struct V_221 * V_222 )
{
V_222 -> V_223 = 0 ;
V_222 -> V_224 = 0 ;
V_222 -> V_225 = 0 ;
V_222 -> V_226 = 0 ;
V_222 -> type = 0 ;
V_222 -> V_215 = 0 ;
}
void F_110 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_66 * V_227 ,
struct V_47 * V_48 )
{
struct V_221 * V_222 ;
struct V_68 * V_115 ;
unsigned int V_228 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_222 = & V_48 -> V_54 [ V_8 ] . V_222 ;
if ( ! F_111 ( V_227 , V_8 ) && F_112 ( V_227 , V_8 ) ) {
F_109 ( V_222 ) ;
continue;
}
if ( F_111 ( V_227 , V_8 ) ) {
V_115 = F_31 ( V_3 , V_158 , V_8 ) ;
V_228 = F_113 ( F_10 ( V_115 -> V_193 ) ) ;
if ( V_228 != V_209 && V_228 != V_211 &&
V_228 != V_208 &&
V_228 != V_210 )
continue;
V_222 -> V_223 = F_114 (
F_10 ( V_115 -> V_117 ) ) ;
V_222 -> V_224 = F_115 (
F_10 ( V_115 -> V_117 ) ) + 1 ;
V_222 -> V_225 = F_116 (
F_10 ( V_115 -> V_193 ) ) + 1 ;
V_222 -> V_226 = F_117 (
F_10 ( V_115 -> V_193 ) ) ;
V_222 -> type = V_228 ;
V_222 -> V_215 = F_118 (
F_10 ( V_115 -> V_219 ) ) ;
}
}
}
void F_119 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 ,
unsigned int V_49 )
{
struct V_68 * V_229 ;
struct V_68 * V_230 ;
V_229 = F_31 ( V_3 , V_159 , V_49 ) ;
V_230 = F_31 ( V_3 , V_158 , V_49 ) ;
V_230 -> V_117 = V_229 -> V_117 ;
V_230 -> V_193 = V_229 -> V_193 ;
V_230 -> V_120 = V_229 -> V_120 ;
V_230 -> V_219 = V_229 -> V_219 ;
}
void F_120 ( struct V_2 * V_3 ,
struct V_58 * V_158 ,
struct V_58 * V_159 )
{
struct V_67 * V_231 ;
struct V_67 * V_232 ;
V_231 = F_30 ( V_3 , V_158 ) ;
V_232 = F_30 ( V_3 , V_159 ) ;
V_231 -> V_177 = V_232 -> V_177 ;
V_231 -> V_187 = V_232 -> V_187 ;
V_231 -> V_129 = V_232 -> V_129 ;
V_231 -> V_233 = V_232 -> V_233 ;
}
static int F_121 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_234 * V_77 = F_34 ( V_3 ) -> V_74 . V_75 ;
int V_235 = F_122 ( V_3 -> V_236 ) ;
F_21 ( V_3 , L_36 , V_235 ) ;
if ( ! V_235 )
return 0 ;
V_3 -> V_237 = F_2 ( sizeof( * V_3 -> V_237 ) , V_5 ) ;
if ( ! V_3 -> V_237 )
goto V_238;
V_3 -> V_237 -> V_239 = F_37 ( V_77 ,
V_235 * sizeof( T_4 ) ,
& V_3 -> V_237 -> V_240 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_239 )
goto V_241;
V_3 -> V_237 -> V_242 = F_2 ( sizeof( void * ) * V_235 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_242 )
goto V_243;
V_3 -> V_237 -> V_244 =
F_2 ( sizeof( T_2 ) * V_235 , V_5 ) ;
if ( ! V_3 -> V_237 -> V_244 )
goto V_245;
V_3 -> V_154 -> V_155 [ 0 ] = F_9 ( V_3 -> V_237 -> V_240 ) ;
for ( V_8 = 0 ; V_8 < V_235 ; V_8 ++ ) {
T_2 V_7 ;
void * V_246 = F_37 ( V_77 , V_3 -> V_247 , & V_7 ,
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
F_35 ( V_77 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
V_245:
F_4 ( V_3 -> V_237 -> V_242 ) ;
V_243:
F_35 ( V_77 , V_235 * sizeof( T_4 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
V_241:
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
V_238:
return - V_43 ;
}
static void F_123 ( struct V_2 * V_3 )
{
int V_235 ;
int V_8 ;
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
if ( ! V_3 -> V_237 )
return;
V_235 = F_122 ( V_3 -> V_236 ) ;
for ( V_8 = 0 ; V_8 < V_235 ; V_8 ++ ) {
F_35 ( & V_73 -> V_77 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
F_4 ( V_3 -> V_237 -> V_242 ) ;
F_35 ( & V_73 -> V_77 , V_235 * sizeof( T_4 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
}
struct V_249 * F_45 ( struct V_2 * V_3 ,
bool V_250 , bool V_251 ,
T_1 V_81 )
{
struct V_249 * V_252 ;
V_252 = F_2 ( sizeof( * V_252 ) , V_81 ) ;
if ( ! V_252 )
return NULL ;
if ( V_250 ) {
V_252 -> V_158 =
F_24 ( V_3 , V_61 ,
V_81 ) ;
if ( ! V_252 -> V_158 ) {
F_4 ( V_252 ) ;
return NULL ;
}
}
if ( V_251 ) {
V_252 -> V_253 =
F_2 ( sizeof( struct V_253 ) , V_81 ) ;
if ( ! V_252 -> V_253 ) {
F_28 ( V_3 , V_252 -> V_158 ) ;
F_4 ( V_252 ) ;
return NULL ;
}
F_69 ( V_252 -> V_253 ) ;
}
V_252 -> V_254 = 0 ;
F_19 ( & V_252 -> V_163 ) ;
return V_252 ;
}
void F_124 ( struct V_2 * V_3 , struct V_255 * V_255 )
{
if ( V_255 ) {
F_4 ( V_255 -> V_256 [ 0 ] ) ;
F_4 ( V_255 ) ;
}
}
void F_50 ( struct V_2 * V_3 ,
struct V_249 * V_252 )
{
F_28 ( V_3 ,
V_252 -> V_158 ) ;
F_4 ( V_252 -> V_253 ) ;
F_4 ( V_252 ) ;
}
void F_125 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = F_33 ( F_34 ( V_3 ) -> V_74 . V_75 ) ;
struct V_177 * V_177 , * V_16 ;
struct V_257 * V_258 , * V_259 ;
unsigned long V_5 ;
int V_62 ;
int V_8 , V_141 , V_140 ;
V_62 = sizeof( struct V_260 ) * ( V_3 -> V_261 . V_262 ) ;
if ( V_3 -> V_261 . V_263 )
F_35 ( & V_73 -> V_77 , V_62 ,
V_3 -> V_261 . V_263 , V_3 -> V_261 . V_264 ) ;
V_3 -> V_261 . V_263 = NULL ;
F_21 ( V_3 , L_37 ) ;
if ( V_3 -> V_265 )
F_15 ( V_3 , V_3 -> V_265 ) ;
V_3 -> V_265 = NULL ;
F_21 ( V_3 , L_38 ) ;
if ( V_3 -> V_266 )
F_50 ( V_3 , V_3 -> V_266 ) ;
V_3 -> V_101 = 0 ;
if ( V_3 -> V_267 )
F_15 ( V_3 , V_3 -> V_267 ) ;
V_3 -> V_267 = NULL ;
F_21 ( V_3 , L_39 ) ;
F_61 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_62 ( & V_258 -> V_268 ) ;
F_4 ( V_258 ) ;
}
for ( V_8 = 1 ; V_8 < V_269 ; ++ V_8 )
F_65 ( V_3 , V_8 ) ;
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
F_127 ( & V_3 -> V_270 , V_5 ) ;
F_61 (dev_info, next, &xhci->lpm_failed_devs, list) {
F_62 ( & V_177 -> V_271 ) ;
F_4 ( V_177 ) ;
}
F_128 ( & V_3 -> V_270 , V_5 ) ;
if ( ! V_3 -> V_133 )
goto V_272;
V_140 = F_60 ( V_3 -> V_132 ) ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_144 * V_273 = & V_3 -> V_133 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ ) {
struct V_126 * V_83 = & V_273 -> V_150 [ V_141 ] . V_151 ;
while ( ! F_66 ( V_83 ) )
F_129 ( V_83 -> V_16 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_128 * V_139 , * V_274 ;
F_61 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_62 ( & V_139 -> V_135 ) ;
F_4 ( V_139 ) ;
}
}
V_272:
V_3 -> V_275 = 0 ;
V_3 -> V_276 = 0 ;
V_3 -> V_277 = 0 ;
F_4 ( V_3 -> V_278 ) ;
F_4 ( V_3 -> V_279 ) ;
F_4 ( V_3 -> V_280 ) ;
F_4 ( V_3 -> V_133 ) ;
V_3 -> V_247 = 0 ;
V_3 -> V_281 = 0 ;
V_3 -> V_282 [ 0 ] . V_283 = 0 ;
V_3 -> V_282 [ 1 ] . V_283 = 0 ;
}
static int F_130 ( struct V_2 * V_3 ,
struct V_1 * V_284 ,
union V_55 * V_285 ,
union V_55 * V_286 ,
T_2 V_287 ,
struct V_1 * V_288 ,
char * V_289 , int V_290 )
{
unsigned long long V_291 ;
unsigned long long V_292 ;
struct V_1 * V_6 ;
V_291 = F_55 ( V_284 , V_285 ) ;
V_292 = F_55 ( V_284 , V_286 ) ;
V_6 = F_131 ( V_284 , V_285 , V_286 , V_287 ) ;
if ( V_6 != V_288 ) {
F_43 ( V_3 , L_44 ,
V_289 , V_290 ) ;
F_43 ( V_3 , L_45
L_46 ,
V_284 ,
( unsigned long long ) V_287 ) ;
F_43 ( V_3 , L_47
L_48 ,
V_285 , V_291 ,
V_286 , V_292 ) ;
F_43 ( V_3 , L_49 ,
V_288 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , T_1 V_81 )
{
struct {
T_2 V_287 ;
struct V_1 * V_288 ;
} V_293 [] = {
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
struct V_1 * V_284 ;
union V_55 * V_285 ;
union V_55 * V_286 ;
T_2 V_287 ;
struct V_1 * V_288 ;
} V_294 [] = {
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = V_3 -> V_265 -> V_37 -> V_9 ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_287 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = V_3 -> V_265 -> V_37 -> V_9 ,
. V_286 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_287 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = V_3 -> V_267 -> V_37 -> V_9 ,
. V_286 = & V_3 -> V_267 -> V_37 -> V_9 [ V_12 - 1 ] ,
. V_287 = V_3 -> V_267 -> V_37 -> V_7 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 0 ] ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ 3 ] ,
. V_287 = V_3 -> V_265 -> V_37 -> V_7 + 4 * 16 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ 3 ] ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ 6 ] ,
. V_287 = V_3 -> V_265 -> V_37 -> V_7 + 2 * 16 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_287 = V_3 -> V_265 -> V_37 -> V_7 + 2 * 16 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_287 = V_3 -> V_265 -> V_37 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_288 = NULL ,
} ,
{ . V_284 = V_3 -> V_265 -> V_37 ,
. V_285 = & V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 3 ] ,
. V_286 = & V_3 -> V_265 -> V_37 -> V_9 [ 1 ] ,
. V_287 = V_3 -> V_267 -> V_37 -> V_7 + 2 * 16 ,
. V_288 = NULL ,
} ,
} ;
unsigned int V_295 ;
int V_8 , V_44 ;
V_295 = F_133 ( V_293 ) ;
for ( V_8 = 0 ; V_8 < V_295 ; V_8 ++ ) {
V_44 = F_130 ( V_3 ,
V_3 -> V_265 -> V_37 ,
V_3 -> V_265 -> V_37 -> V_9 ,
& V_3 -> V_265 -> V_37 -> V_9 [ V_12 - 1 ] ,
V_293 [ V_8 ] . V_287 ,
V_293 [ V_8 ] . V_288 ,
L_50 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_295 = F_133 ( V_294 ) ;
for ( V_8 = 0 ; V_8 < V_295 ; V_8 ++ ) {
V_44 = F_130 ( V_3 ,
V_294 [ V_8 ] . V_284 ,
V_294 [ V_8 ] . V_285 ,
V_294 [ V_8 ] . V_286 ,
V_294 [ V_8 ] . V_287 ,
V_294 [ V_8 ] . V_288 ,
L_51 , V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_21 ( V_3 , L_52 ) ;
return 0 ;
}
static void F_134 ( struct V_2 * V_3 )
{
T_4 V_296 ;
T_2 V_120 ;
V_120 = F_55 ( V_3 -> V_265 -> V_40 ,
V_3 -> V_265 -> V_39 ) ;
if ( V_120 == 0 && ! F_135 () )
F_43 ( V_3 , L_53
L_54 ) ;
V_296 = F_136 ( V_3 , & V_3 -> V_297 -> V_298 ) ;
V_296 &= V_299 ;
V_296 &= ~ V_300 ;
F_21 ( V_3 , L_55
L_56 ) ;
F_137 ( V_3 , ( ( T_4 ) V_120 & ( T_4 ) ~ V_299 ) | V_296 ,
& V_3 -> V_297 -> V_298 ) ;
}
static void F_138 ( struct V_2 * V_3 , unsigned int V_140 ,
T_5 T_6 * V_96 , T_7 V_301 )
{
T_3 V_296 , V_302 , V_303 ;
int V_8 ;
if ( V_301 > 0x03 ) {
F_43 ( V_3 , L_57
L_58 ,
V_96 , V_301 ) ;
return;
}
V_296 = F_139 ( V_3 , V_96 + 2 ) ;
V_302 = F_140 ( V_296 ) ;
V_303 = F_141 ( V_296 ) ;
F_21 ( V_3 , L_59
L_60 ,
V_96 , V_302 , V_303 , V_301 ) ;
if ( V_302 == 0 || ( V_302 + V_303 - 1 ) > V_140 )
return;
if ( ( V_3 -> V_220 == 0x96 ) && ( V_301 != 0x03 ) &&
( V_296 & V_304 ) ) {
F_21 ( V_3 , L_61 ) ;
V_3 -> V_305 = 1 ;
}
if ( ( V_3 -> V_220 >= 0x100 ) && ( V_301 != 0x03 ) ) {
F_21 ( V_3 , L_62 ) ;
V_3 -> V_305 = 1 ;
if ( V_296 & V_306 ) {
F_21 ( V_3 , L_63 ) ;
V_3 -> V_307 = 1 ;
}
}
V_302 -- ;
for ( V_8 = V_302 ; V_8 < ( V_302 + V_303 ) ; V_8 ++ ) {
if ( V_3 -> V_280 [ V_8 ] != 0 ) {
F_43 ( V_3 , L_64
L_65 , V_96 , V_8 ) ;
F_43 ( V_3 , L_66
L_67 ,
V_3 -> V_280 [ V_8 ] , V_301 ) ;
if ( V_3 -> V_280 [ V_8 ] != V_301 &&
V_3 -> V_280 [ V_8 ] != V_308 ) {
if ( V_3 -> V_280 [ V_8 ] == 0x03 )
V_3 -> V_276 -- ;
else
V_3 -> V_275 -- ;
V_3 -> V_280 [ V_8 ] = V_308 ;
}
continue;
}
V_3 -> V_280 [ V_8 ] = V_301 ;
if ( V_301 == 0x03 )
V_3 -> V_276 ++ ;
else
V_3 -> V_275 ++ ;
}
}
static int F_142 ( struct V_2 * V_3 , T_1 V_5 )
{
T_5 T_6 * V_96 ;
T_3 V_309 ;
unsigned int V_140 ;
int V_8 , V_141 , V_310 ;
V_96 = & V_3 -> V_311 -> V_63 ;
V_309 = F_143 ( F_139 ( V_3 , V_96 ) ) ;
if ( V_309 == 0 ) {
F_144 ( V_3 , L_68
L_69 ) ;
return - V_312 ;
}
V_140 = F_60 ( V_3 -> V_132 ) ;
V_3 -> V_280 = F_2 ( sizeof( * V_3 -> V_280 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_280 )
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
V_96 = & V_3 -> V_311 -> V_313 + V_309 ;
while ( 1 ) {
T_3 V_314 ;
V_314 = F_139 ( V_3 , V_96 ) ;
if ( F_145 ( V_314 ) == V_315 )
F_138 ( V_3 , V_140 , V_96 ,
( T_7 ) F_146 ( V_314 ) ) ;
V_309 = F_147 ( V_314 ) ;
if ( ! V_309 || ( V_3 -> V_275 + V_3 -> V_276 )
== V_140 )
break;
V_96 += V_309 ;
}
if ( V_3 -> V_275 == 0 && V_3 -> V_276 == 0 ) {
F_43 ( V_3 , L_70 ) ;
return - V_312 ;
}
F_21 ( V_3 , L_71 ,
V_3 -> V_275 , V_3 -> V_276 ) ;
if ( V_3 -> V_276 > 15 ) {
F_21 ( V_3 , L_72 ) ;
V_3 -> V_276 = 15 ;
}
if ( V_3 -> V_275 > V_316 ) {
F_21 ( V_3 , L_73 ,
V_316 ) ;
V_3 -> V_275 = V_316 ;
}
if ( V_3 -> V_275 ) {
V_3 -> V_278 = F_148 ( sizeof( * V_3 -> V_278 ) *
V_3 -> V_275 , V_5 ) ;
if ( ! V_3 -> V_278 )
return - V_43 ;
V_310 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
if ( V_3 -> V_280 [ V_8 ] == 0x03 ||
V_3 -> V_280 [ V_8 ] == 0 ||
V_3 -> V_280 [ V_8 ] == V_308 )
continue;
V_3 -> V_278 [ V_310 ] =
& V_3 -> V_317 -> V_318 +
V_319 * V_8 ;
F_21 ( V_3 , L_74
L_75 , V_8 ,
V_3 -> V_278 [ V_310 ] ) ;
V_310 ++ ;
if ( V_310 == V_3 -> V_275 )
break;
}
}
if ( V_3 -> V_276 ) {
V_3 -> V_279 = F_148 ( sizeof( * V_3 -> V_279 ) *
V_3 -> V_276 , V_5 ) ;
if ( ! V_3 -> V_279 )
return - V_43 ;
V_310 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ )
if ( V_3 -> V_280 [ V_8 ] == 0x03 ) {
V_3 -> V_279 [ V_310 ] =
& V_3 -> V_317 -> V_318 +
V_319 * V_8 ;
F_21 ( V_3 , L_76
L_75 , V_8 ,
V_3 -> V_279 [ V_310 ] ) ;
V_310 ++ ;
if ( V_310 == V_3 -> V_276 )
break;
}
}
return 0 ;
}
int F_149 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_234 * V_77 = F_34 ( V_3 ) -> V_74 . V_75 ;
unsigned int V_20 , V_320 ;
T_4 V_321 ;
struct V_1 * V_6 ;
T_3 V_247 , V_296 ;
int V_8 ;
F_19 ( & V_3 -> V_322 ) ;
F_19 ( & V_3 -> V_268 ) ;
V_247 = F_139 ( V_3 , & V_3 -> V_317 -> V_247 ) ;
F_21 ( V_3 , L_77 , V_247 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_247 ) != 0 )
break;
V_247 = V_247 >> 1 ;
}
if ( V_8 < 16 )
F_21 ( V_3 , L_78 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_43 ( V_3 , L_79 ) ;
V_3 -> V_281 = 12 ;
V_3 -> V_247 = 1 << V_3 -> V_281 ;
F_21 ( V_3 , L_80 , V_3 -> V_247 / 1024 ) ;
V_20 = F_150 ( F_139 ( V_3 , & V_3 -> V_311 -> V_132 ) ) ;
F_21 ( V_3 , L_81 ,
( unsigned int ) V_20 ) ;
V_320 = F_139 ( V_3 , & V_3 -> V_317 -> V_323 ) ;
V_20 |= ( V_320 & ~ V_324 ) ;
F_21 ( V_3 , L_82 ,
( unsigned int ) V_20 ) ;
F_151 ( V_3 , V_20 , & V_3 -> V_317 -> V_323 ) ;
V_3 -> V_154 = F_37 ( V_77 , sizeof( * V_3 -> V_154 ) , & V_7 ,
V_325 ) ;
if ( ! V_3 -> V_154 )
goto V_46;
memset ( V_3 -> V_154 , 0 , sizeof *( V_3 -> V_154 ) ) ;
V_3 -> V_154 -> V_7 = V_7 ;
F_21 ( V_3 , L_83 ,
( unsigned long long ) V_3 -> V_154 -> V_7 , V_3 -> V_154 ) ;
F_137 ( V_3 , V_7 , & V_3 -> V_317 -> V_326 ) ;
V_3 -> V_10 = F_152 ( L_84 , V_77 ,
V_11 , 64 , V_3 -> V_247 ) ;
V_3 -> V_65 = F_152 ( L_85 , V_77 ,
2112 , 64 , V_3 -> V_247 ) ;
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
V_3 -> V_267 = F_18 ( V_3 , 1 , 1 , V_327 , V_5 ) ;
if ( ! V_3 -> V_267 )
goto V_46;
F_21 ( V_3 , L_88 , V_3 -> V_267 ) ;
F_21 ( V_3 , L_89 ,
( unsigned long long ) V_3 -> V_267 -> V_37 -> V_7 ) ;
V_321 = F_136 ( V_3 , & V_3 -> V_317 -> V_267 ) ;
V_321 = ( V_321 & ( T_4 ) V_328 ) |
( V_3 -> V_267 -> V_37 -> V_7 & ( T_4 ) ~ V_328 ) |
V_3 -> V_267 -> V_4 ;
F_21 ( V_3 , L_90 , V_20 ) ;
F_137 ( V_3 , V_321 , & V_3 -> V_317 -> V_267 ) ;
F_153 ( V_3 ) ;
V_3 -> V_266 = F_45 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_266 )
goto V_46;
V_3 -> V_101 ++ ;
V_20 = F_139 ( V_3 , & V_3 -> V_311 -> V_329 ) ;
V_20 &= V_330 ;
F_21 ( V_3 , L_91
L_92 , V_20 ) ;
V_3 -> V_331 = ( void T_6 * ) V_3 -> V_311 + V_20 ;
F_154 ( V_3 ) ;
F_155 ( V_3 ) ;
V_3 -> V_297 = & V_3 -> V_332 -> V_297 [ 0 ] ;
F_21 ( V_3 , L_93 ) ;
V_3 -> V_265 = F_18 ( V_3 , V_333 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_265 )
goto V_46;
if ( F_132 ( V_3 , V_5 ) < 0 )
goto V_46;
V_3 -> V_261 . V_263 = F_37 ( V_77 ,
sizeof( struct V_260 ) * V_333 , & V_7 ,
V_325 ) ;
if ( ! V_3 -> V_261 . V_263 )
goto V_46;
F_21 ( V_3 , L_94 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_261 . V_263 , 0 , sizeof( struct V_260 ) * V_333 ) ;
V_3 -> V_261 . V_262 = V_333 ;
V_3 -> V_261 . V_264 = V_7 ;
F_21 ( V_3 , L_95 ,
V_3 -> V_261 . V_262 ,
V_3 -> V_261 . V_263 ,
( unsigned long long ) V_3 -> V_261 . V_264 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_265 -> V_37 ; V_20 < V_333 ; V_20 ++ ) {
struct V_260 * V_334 = & V_3 -> V_261 . V_263 [ V_20 ] ;
V_334 -> V_335 = F_9 ( V_6 -> V_7 ) ;
V_334 -> V_336 = F_13 ( V_12 ) ;
V_334 -> V_337 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_139 ( V_3 , & V_3 -> V_297 -> V_338 ) ;
V_20 &= V_339 ;
V_20 |= V_333 ;
F_21 ( V_3 , L_96 ,
V_20 ) ;
F_151 ( V_3 , V_20 , & V_3 -> V_297 -> V_338 ) ;
F_21 ( V_3 , L_97 ) ;
F_21 ( V_3 , L_98 ,
( unsigned long long ) V_3 -> V_261 . V_264 ) ;
V_321 = F_136 ( V_3 , & V_3 -> V_297 -> V_340 ) ;
V_321 &= V_299 ;
V_321 |= ( V_3 -> V_261 . V_264 & ( T_4 ) ~ V_299 ) ;
F_137 ( V_3 , V_321 , & V_3 -> V_297 -> V_340 ) ;
F_134 ( V_3 ) ;
F_21 ( V_3 , L_99 ) ;
F_156 ( V_3 , 0 ) ;
F_69 ( & V_3 -> V_341 ) ;
for ( V_8 = 0 ; V_8 < V_269 ; ++ V_8 )
V_3 -> V_153 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_316 ; ++ V_8 ) {
V_3 -> V_282 [ 0 ] . V_342 [ V_8 ] = 0 ;
V_3 -> V_282 [ 1 ] . V_342 [ V_8 ] = 0 ;
}
if ( F_121 ( V_3 , V_5 ) )
goto V_46;
if ( F_142 ( V_3 , V_5 ) )
goto V_46;
V_296 = F_139 ( V_3 , & V_3 -> V_317 -> V_343 ) ;
V_296 &= ~ V_344 ;
V_296 |= V_345 ;
F_151 ( V_3 , V_296 , & V_3 -> V_317 -> V_343 ) ;
return 0 ;
V_46:
F_43 ( V_3 , L_100 ) ;
F_157 ( V_3 ) ;
F_158 ( V_3 ) ;
F_125 ( V_3 ) ;
return - V_43 ;
}
