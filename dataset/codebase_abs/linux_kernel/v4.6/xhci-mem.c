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
if ( V_4 == 0 ) {
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_6 -> V_9 [ V_8 ] . V_12 . V_13 |= F_5 ( V_14 ) ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_15 = NULL ;
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
struct V_1 * V_16 )
{
struct V_1 * V_6 ;
V_6 = V_16 -> V_15 ;
while ( V_6 != V_16 ) {
struct V_1 * V_15 = V_6 -> V_15 ;
F_6 ( V_3 , V_6 ) ;
V_6 = V_15 ;
}
F_6 ( V_3 , V_16 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_1 * V_17 ,
struct V_1 * V_15 , enum V_18 type )
{
T_3 V_19 ;
if ( ! V_17 || ! V_15 )
return;
V_17 -> V_15 = V_15 ;
if ( type != V_20 ) {
V_17 -> V_9 [ V_11 - 1 ] . V_12 . V_21 =
F_10 ( V_15 -> V_7 ) ;
V_19 = F_11 ( V_17 -> V_9 [ V_11 - 1 ] . V_12 . V_13 ) ;
V_19 &= ~ V_22 ;
V_19 |= F_12 ( V_23 ) ;
if ( F_13 ( V_3 ) ||
( type == V_24 &&
( V_3 -> V_25 & V_26 ) ) )
V_19 |= V_27 ;
V_17 -> V_9 [ V_11 - 1 ] . V_12 . V_13 = F_5 ( V_19 ) ;
}
}
static void F_14 ( struct V_2 * V_3 , struct V_28 * V_29 ,
struct V_1 * V_16 , struct V_1 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_15 ;
if ( ! V_29 || ! V_16 || ! V_30 )
return;
V_15 = V_29 -> V_32 -> V_15 ;
F_9 ( V_3 , V_29 -> V_32 , V_16 , V_29 -> type ) ;
F_9 ( V_3 , V_30 , V_15 , V_29 -> type ) ;
V_29 -> V_31 += V_31 ;
V_29 -> V_33 += ( V_11 - 1 ) * V_31 ;
if ( V_29 -> type != V_20 && V_29 -> V_32 == V_29 -> V_34 ) {
V_29 -> V_34 -> V_9 [ V_11 - 1 ] . V_12 . V_13
&= ~ F_5 ( V_35 ) ;
V_30 -> V_9 [ V_11 - 1 ] . V_12 . V_13
|= F_5 ( V_35 ) ;
V_29 -> V_34 = V_30 ;
}
}
static int F_15 ( struct V_36 * V_37 ,
struct V_28 * V_29 ,
struct V_1 * V_6 ,
T_1 V_38 )
{
unsigned long V_39 ;
int V_40 ;
V_39 = ( unsigned long ) ( V_6 -> V_7 >> V_41 ) ;
if ( F_16 ( V_37 , V_39 ) )
return 0 ;
V_40 = F_17 ( V_38 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_18 ( V_37 ,
V_39 , V_29 ) ;
F_19 () ;
return V_40 ;
}
static void F_20 ( struct V_36 * V_37 ,
struct V_1 * V_6 )
{
unsigned long V_39 ;
V_39 = ( unsigned long ) ( V_6 -> V_7 >> V_41 ) ;
if ( F_16 ( V_37 , V_39 ) )
F_21 ( V_37 , V_39 ) ;
}
static int F_22 (
struct V_36 * V_37 ,
struct V_28 * V_29 ,
struct V_1 * V_42 ,
struct V_1 * V_34 ,
T_1 V_38 )
{
struct V_1 * V_6 ;
struct V_1 * V_43 ;
int V_40 ;
if ( F_23 ( V_37 == NULL ) )
return 0 ;
V_6 = V_42 ;
do {
V_40 = F_15 ( V_37 ,
V_29 , V_6 , V_38 ) ;
if ( V_40 )
goto V_44;
if ( V_6 == V_34 )
return 0 ;
V_6 = V_6 -> V_15 ;
} while ( V_6 != V_42 );
return 0 ;
V_44:
V_43 = V_6 ;
V_6 = V_42 ;
do {
F_20 ( V_37 , V_6 ) ;
if ( V_6 == V_43 )
return V_40 ;
V_6 = V_6 -> V_15 ;
} while ( V_6 != V_42 );
return V_40 ;
}
static void F_24 ( struct V_28 * V_29 )
{
struct V_1 * V_6 ;
if ( F_23 ( V_29 -> V_37 == NULL ) )
return;
V_6 = V_29 -> V_42 ;
do {
F_20 ( V_29 -> V_37 , V_6 ) ;
V_6 = V_6 -> V_15 ;
} while ( V_6 != V_29 -> V_42 );
}
static int F_25 ( struct V_28 * V_29 , T_1 V_38 )
{
return F_22 ( V_29 -> V_37 , V_29 ,
V_29 -> V_42 , V_29 -> V_34 , V_38 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
if ( ! V_29 )
return;
if ( V_29 -> V_42 ) {
if ( V_29 -> type == V_45 )
F_24 ( V_29 ) ;
F_8 ( V_3 , V_29 -> V_42 ) ;
}
F_4 ( V_29 ) ;
}
static void F_27 ( struct V_28 * V_29 ,
unsigned int V_4 )
{
V_29 -> V_46 = V_29 -> V_42 -> V_9 ;
V_29 -> V_32 = V_29 -> V_42 ;
V_29 -> V_47 = V_29 -> V_46 ;
V_29 -> V_48 = V_29 -> V_42 ;
V_29 -> V_4 = V_4 ;
V_29 -> V_49 = 0 ;
V_29 -> V_50 = 0 ;
V_29 -> V_33 = V_29 -> V_31 * ( V_11 - 1 ) - 1 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * * V_16 , struct V_1 * * V_30 ,
unsigned int V_31 , unsigned int V_4 ,
enum V_18 type , T_1 V_5 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_17 )
return - V_51 ;
V_31 -- ;
* V_16 = V_17 ;
while ( V_31 > 0 ) {
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_15 ) {
V_17 = * V_16 ;
while ( V_17 ) {
V_15 = V_17 -> V_15 ;
F_6 ( V_3 , V_17 ) ;
V_17 = V_15 ;
}
return - V_51 ;
}
F_9 ( V_3 , V_17 , V_15 , type ) ;
V_17 = V_15 ;
V_31 -- ;
}
F_9 ( V_3 , V_17 , * V_16 , type ) ;
* V_30 = V_17 ;
return 0 ;
}
static struct V_28 * F_29 ( struct V_2 * V_3 ,
unsigned int V_31 , unsigned int V_4 ,
enum V_18 type , T_1 V_5 )
{
struct V_28 * V_29 ;
int V_40 ;
V_29 = F_2 ( sizeof *( V_29 ) , V_5 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_31 = V_31 ;
F_30 ( & V_29 -> V_52 ) ;
V_29 -> type = type ;
if ( V_31 == 0 )
return V_29 ;
V_40 = F_28 ( V_3 , & V_29 -> V_42 ,
& V_29 -> V_34 , V_31 , V_4 , type , V_5 ) ;
if ( V_40 )
goto V_53;
if ( type != V_20 ) {
V_29 -> V_34 -> V_9 [ V_11 - 1 ] . V_12 . V_13 |=
F_5 ( V_35 ) ;
}
F_27 ( V_29 , V_4 ) ;
return V_29 ;
V_53:
F_4 ( V_29 ) ;
return NULL ;
}
void F_31 ( struct V_2 * V_3 ,
struct V_54 * V_55 ,
unsigned int V_56 )
{
int V_57 ;
V_57 = V_55 -> V_58 ;
if ( V_57 < V_59 ) {
V_55 -> V_60 [ V_57 ] =
V_55 -> V_61 [ V_56 ] . V_29 ;
V_55 -> V_58 ++ ;
F_32 ( V_3 , L_1
L_2 ,
V_55 -> V_58 ,
( V_55 -> V_58 > 1 ) ? L_3 : L_4 ) ;
} else {
F_26 ( V_3 , V_55 -> V_61 [ V_56 ] . V_29 ) ;
F_32 ( V_3 , L_5
L_6 ,
V_55 -> V_58 ) ;
}
V_55 -> V_61 [ V_56 ] . V_29 = NULL ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_28 * V_29 , unsigned int V_4 ,
enum V_18 type )
{
struct V_1 * V_6 = V_29 -> V_42 ;
int V_8 ;
do {
memset ( V_6 -> V_9 , 0 ,
sizeof( union V_62 ) * V_11 ) ;
if ( V_4 == 0 ) {
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_6 -> V_9 [ V_8 ] . V_12 . V_13 |=
F_5 ( V_14 ) ;
}
F_9 ( V_3 , V_6 , V_6 -> V_15 , type ) ;
V_6 = V_6 -> V_15 ;
} while ( V_6 != V_29 -> V_42 );
V_29 -> type = type ;
F_27 ( V_29 , V_4 ) ;
F_30 ( & V_29 -> V_52 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_28 * V_29 ,
unsigned int V_63 , T_1 V_5 )
{
struct V_1 * V_16 ;
struct V_1 * V_30 ;
unsigned int V_31 ;
unsigned int V_64 ;
int V_40 ;
V_64 = ( V_63 + ( V_11 - 1 ) - 1 ) /
( V_11 - 1 ) ;
V_31 = V_29 -> V_31 > V_64 ?
V_29 -> V_31 : V_64 ;
V_40 = F_28 ( V_3 , & V_16 , & V_30 ,
V_31 , V_29 -> V_4 , V_29 -> type , V_5 ) ;
if ( V_40 )
return - V_51 ;
if ( V_29 -> type == V_45 )
V_40 = F_22 ( V_29 -> V_37 ,
V_29 , V_16 , V_30 , V_5 ) ;
if ( V_40 ) {
struct V_1 * V_15 ;
do {
V_15 = V_16 -> V_15 ;
F_6 ( V_3 , V_16 ) ;
if ( V_16 == V_30 )
break;
V_16 = V_15 ;
} while ( true );
return V_40 ;
}
F_14 ( V_3 , V_29 , V_16 , V_30 , V_31 ) ;
F_35 ( V_3 , V_65 ,
L_7 ,
V_29 -> V_31 ) ;
return 0 ;
}
static struct V_66 * F_36 ( struct V_2 * V_3 ,
int type , T_1 V_5 )
{
struct V_66 * V_67 ;
if ( ( type != V_68 ) && ( type != V_69 ) )
return NULL ;
V_67 = F_2 ( sizeof( * V_67 ) , V_5 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> type = type ;
V_67 -> V_70 = F_37 ( V_3 -> V_71 ) ? 2048 : 1024 ;
if ( type == V_69 )
V_67 -> V_70 += F_38 ( V_3 -> V_71 ) ;
V_67 -> V_72 = F_3 ( V_3 -> V_73 , V_5 , & V_67 -> V_7 ) ;
if ( ! V_67 -> V_72 ) {
F_4 ( V_67 ) ;
return NULL ;
}
return V_67 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_7 ( V_3 -> V_73 , V_67 -> V_72 , V_67 -> V_7 ) ;
F_4 ( V_67 ) ;
}
struct V_74 * F_40 (
struct V_66 * V_67 )
{
if ( V_67 -> type != V_69 )
return NULL ;
return (struct V_74 * ) V_67 -> V_72 ;
}
struct V_75 * F_41 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
if ( V_67 -> type == V_68 )
return (struct V_75 * ) V_67 -> V_72 ;
return (struct V_75 * )
( V_67 -> V_72 + F_38 ( V_3 -> V_71 ) ) ;
}
struct V_76 * F_42 ( struct V_2 * V_3 ,
struct V_66 * V_67 ,
unsigned int V_56 )
{
V_56 ++ ;
if ( V_67 -> type == V_69 )
V_56 ++ ;
return (struct V_76 * )
( V_67 -> V_72 + ( V_56 * F_38 ( V_3 -> V_71 ) ) ) ;
}
static void F_43 ( struct V_2 * V_3 ,
unsigned int V_77 ,
struct V_78 * V_79 , T_2 V_7 )
{
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
T_4 V_70 = sizeof( struct V_78 ) * V_77 ;
if ( V_70 > V_84 )
F_45 ( V_81 , V_70 ,
V_79 , V_7 ) ;
else if ( V_70 <= V_85 )
return F_7 ( V_3 -> V_86 ,
V_79 , V_7 ) ;
else
return F_7 ( V_3 -> V_87 ,
V_79 , V_7 ) ;
}
static struct V_78 * F_46 ( struct V_2 * V_3 ,
unsigned int V_77 , T_2 * V_7 ,
T_1 V_38 )
{
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
T_4 V_70 = sizeof( struct V_78 ) * V_77 ;
if ( V_70 > V_84 )
return F_47 ( V_81 , V_70 ,
V_7 , V_38 ) ;
else if ( V_70 <= V_85 )
return F_48 ( V_3 -> V_86 ,
V_38 , V_7 ) ;
else
return F_48 ( V_3 -> V_87 ,
V_38 , V_7 ) ;
}
struct V_28 * F_49 (
struct V_88 * V_89 ,
T_5 V_90 )
{
if ( V_89 -> V_91 & V_92 )
return F_16 ( & V_89 -> V_93 -> V_37 ,
V_90 >> V_41 ) ;
return V_89 -> V_29 ;
}
struct V_28 * F_50 (
struct V_54 * V_81 ,
unsigned int V_56 ,
unsigned int V_94 )
{
struct V_88 * V_89 = & V_81 -> V_61 [ V_56 ] ;
if ( V_94 == 0 )
return V_89 -> V_29 ;
if ( ! V_89 -> V_93 )
return NULL ;
if ( V_94 > V_89 -> V_93 -> V_95 )
return NULL ;
return V_89 -> V_93 -> V_96 [ V_94 ] ;
}
struct V_97 * F_51 ( struct V_2 * V_3 ,
unsigned int V_77 ,
unsigned int V_95 , T_1 V_38 )
{
struct V_97 * V_93 ;
T_3 V_98 ;
struct V_28 * V_99 ;
T_5 V_100 ;
int V_40 ;
F_32 ( V_3 , L_8
L_9 ,
V_95 , V_77 ) ;
if ( V_3 -> V_101 == V_102 ) {
F_32 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_101 ++ ;
V_93 = F_2 ( sizeof( struct V_97 ) , V_38 ) ;
if ( ! V_93 )
goto V_103;
V_93 -> V_95 = V_95 ;
V_93 -> V_77 = V_77 ;
V_93 -> V_96 = F_2 (
sizeof( struct V_28 * ) * V_95 ,
V_38 ) ;
if ( ! V_93 -> V_96 )
goto V_104;
V_93 -> V_105 = F_46 ( V_3 ,
V_77 , & V_93 -> V_106 ,
V_38 ) ;
if ( ! V_93 -> V_105 )
goto V_107;
memset ( V_93 -> V_105 , 0 ,
sizeof( struct V_78 ) * V_77 ) ;
V_93 -> V_108 =
F_52 ( V_3 , true , true , V_38 ) ;
if ( ! V_93 -> V_108 )
goto V_107;
F_53 ( & V_93 -> V_37 , V_109 ) ;
for ( V_98 = 1 ; V_98 < V_95 ; V_98 ++ ) {
V_93 -> V_96 [ V_98 ] =
F_29 ( V_3 , 2 , 1 , V_45 , V_38 ) ;
V_99 = V_93 -> V_96 [ V_98 ] ;
if ( ! V_99 )
goto V_110;
V_99 -> V_94 = V_98 ;
V_99 -> V_37 = & V_93 -> V_37 ;
V_100 = V_99 -> V_42 -> V_7 |
F_54 ( V_111 ) |
V_99 -> V_4 ;
V_93 -> V_105 [ V_98 ] . V_112 =
F_10 ( V_100 ) ;
F_32 ( V_3 , L_11 ,
V_98 , ( unsigned long long ) V_100 ) ;
V_40 = F_25 ( V_99 , V_38 ) ;
if ( V_40 ) {
F_26 ( V_3 , V_99 ) ;
V_93 -> V_96 [ V_98 ] = NULL ;
goto V_110;
}
}
return V_93 ;
V_110:
for ( V_98 = 1 ; V_98 < V_95 ; V_98 ++ ) {
V_99 = V_93 -> V_96 [ V_98 ] ;
if ( V_99 ) {
F_26 ( V_3 , V_99 ) ;
V_93 -> V_96 [ V_98 ] = NULL ;
}
}
F_55 ( V_3 , V_93 -> V_108 ) ;
V_107:
F_4 ( V_93 -> V_96 ) ;
V_104:
F_4 ( V_93 ) ;
V_103:
V_3 -> V_101 -- ;
return NULL ;
}
void F_56 ( struct V_2 * V_3 ,
struct V_76 * V_113 ,
struct V_97 * V_93 )
{
T_3 V_114 ;
V_114 = F_57 ( V_93 -> V_77 ) - 2 ;
F_35 ( V_3 , V_115 ,
L_12 ,
1 << ( V_114 + 1 ) ) ;
V_113 -> V_116 &= F_5 ( ~ V_117 ) ;
V_113 -> V_116 |= F_5 ( F_58 ( V_114 )
| V_118 ) ;
V_113 -> V_119 = F_10 ( V_93 -> V_106 ) ;
}
void F_59 ( struct V_76 * V_113 ,
struct V_88 * V_89 )
{
T_2 V_100 ;
V_113 -> V_116 &= F_5 ( ~ ( V_117 | V_118 ) ) ;
V_100 = F_60 ( V_89 -> V_29 -> V_48 , V_89 -> V_29 -> V_47 ) ;
V_113 -> V_119 = F_10 ( V_100 | V_89 -> V_29 -> V_4 ) ;
}
void F_61 ( struct V_2 * V_3 ,
struct V_97 * V_93 )
{
int V_98 ;
struct V_28 * V_99 ;
if ( ! V_93 )
return;
for ( V_98 = 1 ; V_98 < V_93 -> V_95 ;
V_98 ++ ) {
V_99 = V_93 -> V_96 [ V_98 ] ;
if ( V_99 ) {
F_26 ( V_3 , V_99 ) ;
V_93 -> V_96 [ V_98 ] = NULL ;
}
}
F_55 ( V_3 , V_93 -> V_108 ) ;
V_3 -> V_101 -- ;
if ( V_93 -> V_105 )
F_43 ( V_3 ,
V_93 -> V_77 ,
V_93 -> V_105 ,
V_93 -> V_106 ) ;
F_4 ( V_93 -> V_96 ) ;
F_4 ( V_93 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
F_63 ( & V_89 -> V_120 , V_121 ,
( unsigned long ) V_89 ) ;
V_89 -> V_3 = V_3 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_54 * V_55 ,
int V_122 )
{
struct V_123 * V_124 ;
struct V_125 * V_126 , * V_15 ;
bool V_127 = false ;
if ( V_55 -> V_128 == 0 ||
V_55 -> V_128 > F_65 ( V_3 -> V_129 ) ) {
F_32 ( V_3 , L_13 ) ;
return;
}
V_124 = & ( V_3 -> V_130 [ V_55 -> V_128 - 1 ] . V_131 ) ;
F_66 (tt_info, next, tt_list_head, tt_list) {
if ( V_126 -> V_122 == V_122 ) {
V_127 = true ;
F_67 ( & V_126 -> V_132 ) ;
F_4 ( V_126 ) ;
} else if ( V_127 ) {
break;
}
}
}
int F_68 ( struct V_2 * V_3 ,
struct V_54 * V_55 ,
struct V_133 * V_134 ,
struct V_135 * V_136 , T_1 V_38 )
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
V_126 = F_2 ( sizeof( * V_126 ) , V_38 ) ;
if ( ! V_126 )
goto V_143;
F_30 ( & V_126 -> V_132 ) ;
F_69 ( & V_126 -> V_132 ,
& V_3 -> V_130 [ V_55 -> V_128 - 1 ] . V_131 ) ;
V_126 -> V_122 = V_55 -> V_144 -> V_122 ;
if ( V_136 -> V_139 )
V_126 -> V_145 = V_8 + 1 ;
V_142 = & V_126 -> V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ )
F_30 ( & V_142 -> V_147 [ V_138 ] . V_148 ) ;
}
return 0 ;
V_143:
F_64 ( V_3 , V_55 , V_55 -> V_144 -> V_122 ) ;
return - V_51 ;
}
void F_70 ( struct V_2 * V_3 , int V_122 )
{
struct V_54 * V_81 ;
int V_8 ;
int V_149 = 0 ;
if ( V_122 == 0 || ! V_3 -> V_150 [ V_122 ] )
return;
V_81 = V_3 -> V_150 [ V_122 ] ;
V_3 -> V_151 -> V_152 [ V_122 ] = 0 ;
if ( ! V_81 )
return;
if ( V_81 -> V_126 )
V_149 = V_81 -> V_126 -> V_153 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_81 -> V_61 [ V_8 ] . V_29 )
F_26 ( V_3 , V_81 -> V_61 [ V_8 ] . V_29 ) ;
if ( V_81 -> V_61 [ V_8 ] . V_93 )
F_61 ( V_3 ,
V_81 -> V_61 [ V_8 ] . V_93 ) ;
if ( ! F_71 ( & V_81 -> V_61 [ V_8 ] . V_154 ) )
F_72 ( V_3 , L_14
L_15 ,
V_122 , V_8 ) ;
}
F_64 ( V_3 , V_81 , V_122 ) ;
F_73 ( V_3 , V_81 , V_149 ) ;
if ( V_81 -> V_60 ) {
for ( V_8 = 0 ; V_8 < V_81 -> V_58 ; V_8 ++ )
F_26 ( V_3 , V_81 -> V_60 [ V_8 ] ) ;
F_4 ( V_81 -> V_60 ) ;
}
if ( V_81 -> V_155 )
F_39 ( V_3 , V_81 -> V_155 ) ;
if ( V_81 -> V_156 )
F_39 ( V_3 , V_81 -> V_156 ) ;
F_4 ( V_3 -> V_150 [ V_122 ] ) ;
V_3 -> V_150 [ V_122 ] = NULL ;
}
int F_74 ( struct V_2 * V_3 , int V_122 ,
struct V_133 * V_144 , T_1 V_5 )
{
struct V_54 * V_81 ;
int V_8 ;
if ( V_122 == 0 || V_3 -> V_150 [ V_122 ] ) {
F_72 ( V_3 , L_16 , V_122 ) ;
return 0 ;
}
V_3 -> V_150 [ V_122 ] = F_2 ( sizeof( * V_3 -> V_150 [ V_122 ] ) , V_5 ) ;
if ( ! V_3 -> V_150 [ V_122 ] )
return 0 ;
V_81 = V_3 -> V_150 [ V_122 ] ;
V_81 -> V_156 = F_36 ( V_3 , V_68 , V_5 ) ;
if ( ! V_81 -> V_156 )
goto V_53;
F_32 ( V_3 , L_17 , V_122 ,
( unsigned long long ) V_81 -> V_156 -> V_7 ) ;
V_81 -> V_155 = F_36 ( V_3 , V_69 , V_5 ) ;
if ( ! V_81 -> V_155 )
goto V_53;
F_32 ( V_3 , L_18 , V_122 ,
( unsigned long long ) V_81 -> V_155 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_62 ( V_3 , & V_81 -> V_61 [ V_8 ] ) ;
F_30 ( & V_81 -> V_61 [ V_8 ] . V_157 ) ;
F_30 ( & V_81 -> V_61 [ V_8 ] . V_154 ) ;
}
V_81 -> V_61 [ 0 ] . V_29 = F_29 ( V_3 , 2 , 1 , V_158 , V_5 ) ;
if ( ! V_81 -> V_61 [ 0 ] . V_29 )
goto V_53;
V_81 -> V_60 = F_2 (
sizeof( struct V_28 * ) * V_59 ,
V_5 ) ;
if ( ! V_81 -> V_60 )
goto V_53;
V_81 -> V_58 = 0 ;
F_75 ( & V_81 -> V_159 ) ;
V_81 -> V_144 = V_144 ;
V_3 -> V_151 -> V_152 [ V_122 ] = F_10 ( V_81 -> V_156 -> V_7 ) ;
F_32 ( V_3 , L_19 ,
V_122 ,
& V_3 -> V_151 -> V_152 [ V_122 ] ,
F_76 ( V_3 -> V_151 -> V_152 [ V_122 ] ) ) ;
return 1 ;
V_53:
F_70 ( V_3 , V_122 ) ;
return 0 ;
}
void F_77 ( struct V_2 * V_3 ,
struct V_133 * V_144 )
{
struct V_54 * V_55 ;
struct V_76 * V_160 ;
struct V_28 * V_161 ;
V_55 = V_3 -> V_150 [ V_144 -> V_122 ] ;
V_160 = F_42 ( V_3 , V_55 -> V_155 , 0 ) ;
V_161 = V_55 -> V_61 [ 0 ] . V_29 ;
V_160 -> V_119 = F_10 ( F_60 ( V_161 -> V_32 ,
V_161 -> V_46 )
| V_161 -> V_4 ) ;
}
static T_3 F_78 ( struct V_2 * V_3 ,
struct V_133 * V_144 )
{
struct V_133 * V_162 ;
struct V_163 * V_164 ;
if ( V_144 -> V_165 >= V_166 )
V_164 = V_3 -> V_167 ;
else
V_164 = V_3 -> V_168 ;
for ( V_162 = V_144 ; V_162 -> V_169 && V_162 -> V_169 -> V_169 ;
V_162 = V_162 -> V_169 )
;
return F_79 ( V_164 , V_162 -> V_170 ) ;
}
int F_80 ( struct V_2 * V_3 , struct V_133 * V_144 )
{
struct V_54 * V_81 ;
struct V_76 * V_160 ;
struct V_75 * V_171 ;
T_3 V_172 ;
T_3 V_173 ;
struct V_133 * V_162 ;
V_81 = V_3 -> V_150 [ V_144 -> V_122 ] ;
if ( V_144 -> V_122 == 0 || ! V_81 ) {
F_72 ( V_3 , L_20 ,
V_144 -> V_122 ) ;
return - V_174 ;
}
V_160 = F_42 ( V_3 , V_81 -> V_155 , 0 ) ;
V_171 = F_41 ( V_3 , V_81 -> V_155 ) ;
V_171 -> V_175 |= F_5 ( F_81 ( 1 ) | V_144 -> V_176 ) ;
switch ( V_144 -> V_165 ) {
case V_177 :
V_171 -> V_175 |= F_5 ( V_178 ) ;
V_173 = F_82 ( 512 ) ;
break;
case V_166 :
V_171 -> V_175 |= F_5 ( V_179 ) ;
V_173 = F_82 ( 512 ) ;
break;
case V_180 :
V_171 -> V_175 |= F_5 ( V_181 ) ;
V_173 = F_82 ( 64 ) ;
break;
case V_182 :
V_171 -> V_175 |= F_5 ( V_183 ) ;
V_173 = F_82 ( 64 ) ;
break;
case V_184 :
V_171 -> V_175 |= F_5 ( V_185 ) ;
V_173 = F_82 ( 8 ) ;
break;
case V_186 :
F_32 ( V_3 , L_21 ) ;
return - V_174 ;
break;
default:
return - V_174 ;
}
V_172 = F_78 ( V_3 , V_144 ) ;
if ( ! V_172 )
return - V_174 ;
V_171 -> V_187 |= F_5 ( F_83 ( V_172 ) ) ;
for ( V_162 = V_144 ; V_162 -> V_169 && V_162 -> V_169 -> V_169 ;
V_162 = V_162 -> V_169 )
;
V_81 -> V_188 = V_162 -> V_170 ;
V_81 -> V_128 = V_172 ;
F_32 ( V_3 , L_22 , V_172 ) ;
F_32 ( V_3 , L_23 , V_81 -> V_188 ) ;
if ( ! V_144 -> V_136 || ! V_144 -> V_136 -> V_189 -> V_169 ) {
V_81 -> V_142 = & V_3 -> V_130 [ V_172 - 1 ] . V_142 ;
} else {
struct V_190 * V_130 ;
struct V_125 * V_191 ;
V_130 = & V_3 -> V_130 [ V_172 - 1 ] ;
F_84 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_191 -> V_122 != V_144 -> V_136 -> V_189 -> V_122 )
continue;
if ( ! V_81 -> V_144 -> V_136 -> V_139 ||
( V_144 -> V_136 -> V_139 &&
V_191 -> V_145 == V_81 -> V_144 -> V_145 ) ) {
V_81 -> V_142 = & V_191 -> V_142 ;
V_81 -> V_126 = V_191 ;
break;
}
}
if ( ! V_81 -> V_126 )
F_72 ( V_3 , L_24 ) ;
}
if ( V_144 -> V_136 && V_144 -> V_136 -> V_189 -> V_169 ) {
V_171 -> V_126 = F_5 ( V_144 -> V_136 -> V_189 -> V_122 |
( V_144 -> V_145 << 8 ) ) ;
if ( V_144 -> V_136 -> V_139 )
V_171 -> V_175 |= F_5 ( V_192 ) ;
}
F_32 ( V_3 , L_25 , V_144 -> V_136 ) ;
F_32 ( V_3 , L_26 , V_144 -> V_145 ) ;
V_160 -> V_193 = F_5 ( F_85 ( V_194 ) ) ;
V_160 -> V_193 |= F_5 ( F_86 ( 0 ) | F_87 ( 3 ) |
V_173 ) ;
V_160 -> V_119 = F_10 ( V_81 -> V_61 [ 0 ] . V_29 -> V_42 -> V_7 |
V_81 -> V_61 [ 0 ] . V_29 -> V_4 ) ;
return 0 ;
}
static unsigned int F_88 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
unsigned int V_196 ;
V_196 = F_89 ( V_89 -> V_197 . V_198 , 1 , 16 ) - 1 ;
if ( V_196 != V_89 -> V_197 . V_198 - 1 )
F_90 ( & V_144 -> V_81 ,
L_27 ,
V_89 -> V_197 . V_199 ,
1 << V_196 ,
V_144 -> V_165 == V_182 ? L_4 : L_28 ) ;
if ( V_144 -> V_165 == V_182 ) {
V_196 += 3 ;
}
return V_196 ;
}
static unsigned int F_91 ( struct V_133 * V_144 ,
struct V_195 * V_89 , unsigned int V_200 ,
unsigned int V_201 , unsigned int V_202 )
{
unsigned int V_196 ;
V_196 = F_57 ( V_200 ) - 1 ;
V_196 = F_89 ( V_196 , V_201 , V_202 ) ;
if ( ( 1 << V_196 ) != V_200 )
F_92 ( & V_144 -> V_81 ,
L_29 ,
V_89 -> V_197 . V_199 ,
1 << V_196 ,
V_200 ) ;
return V_196 ;
}
static unsigned int F_93 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
if ( V_89 -> V_197 . V_198 == 0 )
return 0 ;
return F_91 ( V_144 , V_89 ,
V_89 -> V_197 . V_198 , 0 , 15 ) ;
}
static unsigned int F_94 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
return F_91 ( V_144 , V_89 ,
V_89 -> V_197 . V_198 * 8 , 3 , 10 ) ;
}
static unsigned int F_95 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
unsigned int V_196 = 0 ;
switch ( V_144 -> V_165 ) {
case V_180 :
if ( F_96 ( & V_89 -> V_197 ) ||
F_97 ( & V_89 -> V_197 ) ) {
V_196 = F_93 ( V_144 , V_89 ) ;
break;
}
case V_177 :
case V_166 :
if ( F_98 ( & V_89 -> V_197 ) ||
F_99 ( & V_89 -> V_197 ) ) {
V_196 = F_88 ( V_144 , V_89 ) ;
}
break;
case V_182 :
if ( F_99 ( & V_89 -> V_197 ) ) {
V_196 = F_88 ( V_144 , V_89 ) ;
break;
}
case V_184 :
if ( F_98 ( & V_89 -> V_197 ) ||
F_99 ( & V_89 -> V_197 ) ) {
V_196 = F_94 ( V_144 , V_89 ) ;
}
break;
default:
F_100 () ;
}
return V_196 ;
}
static T_3 F_101 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
if ( V_144 -> V_165 < V_166 ||
! F_99 ( & V_89 -> V_197 ) )
return 0 ;
return V_89 -> V_203 . V_204 ;
}
static T_3 F_102 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
if ( V_144 -> V_165 >= V_166 )
return V_89 -> V_203 . V_205 ;
if ( V_144 -> V_165 == V_180 &&
( F_99 ( & V_89 -> V_197 ) ||
F_98 ( & V_89 -> V_197 ) ) )
return ( F_103 ( & V_89 -> V_197 ) & 0x1800 ) >> 11 ;
return 0 ;
}
static T_3 F_104 ( struct V_195 * V_89 )
{
int V_206 ;
V_206 = F_105 ( & V_89 -> V_197 ) ;
if ( F_96 ( & V_89 -> V_197 ) )
return V_194 ;
if ( F_97 ( & V_89 -> V_197 ) )
return V_206 ? V_207 : V_208 ;
if ( F_99 ( & V_89 -> V_197 ) )
return V_206 ? V_209 : V_210 ;
if ( F_98 ( & V_89 -> V_197 ) )
return V_206 ? V_211 : V_212 ;
return 0 ;
}
static T_3 F_106 ( struct V_133 * V_144 ,
struct V_195 * V_89 )
{
int V_213 ;
int V_214 ;
if ( F_96 ( & V_89 -> V_197 ) ||
F_97 ( & V_89 -> V_197 ) )
return 0 ;
if ( ( V_144 -> V_165 >= V_177 ) &&
F_107 ( V_89 -> V_203 . V_204 ) )
return F_11 ( V_89 -> V_215 . V_216 ) ;
else if ( V_144 -> V_165 >= V_166 )
return F_108 ( V_89 -> V_203 . V_217 ) ;
V_214 = F_109 ( F_103 ( & V_89 -> V_197 ) ) ;
V_213 = ( F_103 ( & V_89 -> V_197 ) & 0x1800 ) >> 11 ;
return V_214 * ( V_213 + 1 ) ;
}
int F_110 ( struct V_2 * V_3 ,
struct V_54 * V_55 ,
struct V_133 * V_144 ,
struct V_195 * V_89 ,
T_1 V_38 )
{
unsigned int V_56 ;
struct V_76 * V_113 ;
struct V_28 * V_161 ;
unsigned int V_214 ;
enum V_18 V_218 ;
T_3 V_219 ;
T_3 V_220 ;
unsigned int V_213 ;
unsigned int V_196 ;
unsigned int V_221 ;
unsigned int V_222 ;
unsigned int V_223 = 0 ;
V_56 = F_111 ( & V_89 -> V_197 ) ;
V_113 = F_42 ( V_3 , V_55 -> V_155 , V_56 ) ;
V_220 = F_104 ( V_89 ) ;
if ( ! V_220 )
return - V_174 ;
V_218 = F_112 ( & V_89 -> V_197 ) ;
V_55 -> V_61 [ V_56 ] . V_224 =
F_29 ( V_3 , 2 , 1 , V_218 , V_38 ) ;
if ( ! V_55 -> V_61 [ V_56 ] . V_224 ) {
if ( V_55 -> V_58 == 0 )
return - V_51 ;
V_55 -> V_58 -- ;
V_55 -> V_61 [ V_56 ] . V_224 =
V_55 -> V_60 [ V_55 -> V_58 ] ;
V_55 -> V_60 [ V_55 -> V_58 ] = NULL ;
F_33 ( V_3 , V_55 -> V_61 [ V_56 ] . V_224 ,
1 , V_218 ) ;
}
V_55 -> V_61 [ V_56 ] . V_225 = false ;
V_161 = V_55 -> V_61 [ V_56 ] . V_224 ;
V_219 = F_106 ( V_144 , V_89 ) ;
V_196 = F_95 ( V_144 , V_89 ) ;
V_221 = F_101 ( V_144 , V_89 ) ;
V_214 = F_109 ( F_103 ( & V_89 -> V_197 ) ) ;
V_213 = F_102 ( V_144 , V_89 ) ;
V_222 = V_219 ;
if ( ! F_99 ( & V_89 -> V_197 ) )
V_223 = 3 ;
if ( F_97 ( & V_89 -> V_197 ) && V_144 -> V_165 == V_180 )
V_214 = 512 ;
if ( F_96 ( & V_89 -> V_197 ) && V_3 -> V_226 >= 0x100 )
V_222 = 8 ;
if ( ( V_3 -> V_226 > 0x100 ) && F_113 ( V_3 -> V_227 ) )
V_221 = 0 ;
V_113 -> V_116 = F_5 ( F_114 ( V_219 ) |
F_115 ( V_196 ) |
F_116 ( V_221 ) ) ;
V_113 -> V_193 = F_5 ( F_85 ( V_220 ) |
F_82 ( V_214 ) |
F_86 ( V_213 ) |
F_87 ( V_223 ) ) ;
V_113 -> V_119 = F_10 ( V_161 -> V_42 -> V_7 |
V_161 -> V_4 ) ;
V_113 -> V_228 = F_5 ( F_117 ( V_219 ) |
F_118 ( V_222 ) ) ;
return 0 ;
}
void F_119 ( struct V_2 * V_3 ,
struct V_54 * V_55 ,
struct V_195 * V_89 )
{
unsigned int V_56 ;
struct V_76 * V_113 ;
V_56 = F_111 ( & V_89 -> V_197 ) ;
V_113 = F_42 ( V_3 , V_55 -> V_155 , V_56 ) ;
V_113 -> V_116 = 0 ;
V_113 -> V_193 = 0 ;
V_113 -> V_119 = 0 ;
V_113 -> V_228 = 0 ;
}
void F_120 ( struct V_229 * V_230 )
{
V_230 -> V_231 = 0 ;
V_230 -> V_221 = 0 ;
V_230 -> V_232 = 0 ;
V_230 -> V_233 = 0 ;
V_230 -> type = 0 ;
V_230 -> V_219 = 0 ;
}
void F_121 ( struct V_2 * V_3 ,
struct V_66 * V_155 ,
struct V_74 * V_234 ,
struct V_54 * V_55 )
{
struct V_229 * V_230 ;
struct V_76 * V_113 ;
unsigned int V_235 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_230 = & V_55 -> V_61 [ V_8 ] . V_230 ;
if ( ! F_122 ( V_234 , V_8 ) && F_123 ( V_234 , V_8 ) ) {
F_120 ( V_230 ) ;
continue;
}
if ( F_122 ( V_234 , V_8 ) ) {
V_113 = F_42 ( V_3 , V_155 , V_8 ) ;
V_235 = F_124 ( F_11 ( V_113 -> V_193 ) ) ;
if ( V_235 != V_210 && V_235 != V_212 &&
V_235 != V_209 &&
V_235 != V_211 )
continue;
V_230 -> V_231 = F_125 (
F_11 ( V_113 -> V_116 ) ) ;
V_230 -> V_221 = F_126 (
F_11 ( V_113 -> V_116 ) ) + 1 ;
V_230 -> V_232 = F_127 (
F_11 ( V_113 -> V_193 ) ) + 1 ;
V_230 -> V_233 = F_128 (
F_11 ( V_113 -> V_193 ) ) ;
V_230 -> type = V_235 ;
V_230 -> V_219 = F_129 (
F_11 ( V_113 -> V_228 ) ) ;
}
}
}
void F_130 ( struct V_2 * V_3 ,
struct V_66 * V_155 ,
struct V_66 * V_156 ,
unsigned int V_56 )
{
struct V_76 * V_236 ;
struct V_76 * V_237 ;
V_236 = F_42 ( V_3 , V_156 , V_56 ) ;
V_237 = F_42 ( V_3 , V_155 , V_56 ) ;
V_237 -> V_116 = V_236 -> V_116 ;
V_237 -> V_193 = V_236 -> V_193 ;
V_237 -> V_119 = V_236 -> V_119 ;
V_237 -> V_228 = V_236 -> V_228 ;
}
void F_131 ( struct V_2 * V_3 ,
struct V_66 * V_155 ,
struct V_66 * V_156 )
{
struct V_75 * V_238 ;
struct V_75 * V_239 ;
V_238 = F_41 ( V_3 , V_155 ) ;
V_239 = F_41 ( V_3 , V_156 ) ;
V_238 -> V_175 = V_239 -> V_175 ;
V_238 -> V_187 = V_239 -> V_187 ;
V_238 -> V_126 = V_239 -> V_126 ;
V_238 -> V_240 = V_239 -> V_240 ;
}
static int F_132 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
int V_241 = F_133 ( V_3 -> V_242 ) ;
F_35 ( V_3 , V_243 ,
L_30 , V_241 ) ;
if ( ! V_241 )
return 0 ;
V_3 -> V_244 = F_2 ( sizeof( * V_3 -> V_244 ) , V_5 ) ;
if ( ! V_3 -> V_244 )
goto V_245;
V_3 -> V_244 -> V_246 = F_47 ( V_81 ,
V_241 * sizeof( T_5 ) ,
& V_3 -> V_244 -> V_247 , V_5 ) ;
if ( ! V_3 -> V_244 -> V_246 )
goto V_248;
V_3 -> V_244 -> V_249 = F_2 ( sizeof( void * ) * V_241 , V_5 ) ;
if ( ! V_3 -> V_244 -> V_249 )
goto V_250;
V_3 -> V_244 -> V_251 =
F_2 ( sizeof( T_2 ) * V_241 , V_5 ) ;
if ( ! V_3 -> V_244 -> V_251 )
goto V_252;
V_3 -> V_151 -> V_152 [ 0 ] = F_10 ( V_3 -> V_244 -> V_247 ) ;
for ( V_8 = 0 ; V_8 < V_241 ; V_8 ++ ) {
T_2 V_7 ;
void * V_253 = F_47 ( V_81 , V_3 -> V_254 , & V_7 ,
V_5 ) ;
if ( ! V_253 )
goto V_255;
V_3 -> V_244 -> V_246 [ V_8 ] = V_7 ;
V_3 -> V_244 -> V_249 [ V_8 ] = V_253 ;
V_3 -> V_244 -> V_251 [ V_8 ] = V_7 ;
}
return 0 ;
V_255:
for ( V_8 = V_8 - 1 ; V_8 >= 0 ; V_8 -- ) {
F_45 ( V_81 , V_3 -> V_254 ,
V_3 -> V_244 -> V_249 [ V_8 ] ,
V_3 -> V_244 -> V_251 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_244 -> V_251 ) ;
V_252:
F_4 ( V_3 -> V_244 -> V_249 ) ;
V_250:
F_45 ( V_81 , V_241 * sizeof( T_5 ) ,
V_3 -> V_244 -> V_246 ,
V_3 -> V_244 -> V_247 ) ;
V_248:
F_4 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
V_245:
return - V_51 ;
}
static void F_134 ( struct V_2 * V_3 )
{
int V_241 ;
int V_8 ;
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
if ( ! V_3 -> V_244 )
return;
V_241 = F_133 ( V_3 -> V_242 ) ;
for ( V_8 = 0 ; V_8 < V_241 ; V_8 ++ ) {
F_45 ( V_81 , V_3 -> V_254 ,
V_3 -> V_244 -> V_249 [ V_8 ] ,
V_3 -> V_244 -> V_251 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_244 -> V_251 ) ;
F_4 ( V_3 -> V_244 -> V_249 ) ;
F_45 ( V_81 , V_241 * sizeof( T_5 ) ,
V_3 -> V_244 -> V_246 ,
V_3 -> V_244 -> V_247 ) ;
F_4 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
}
struct V_256 * F_52 ( struct V_2 * V_3 ,
bool V_257 , bool V_258 ,
T_1 V_38 )
{
struct V_256 * V_259 ;
V_259 = F_2 ( sizeof( * V_259 ) , V_38 ) ;
if ( ! V_259 )
return NULL ;
if ( V_257 ) {
V_259 -> V_155 =
F_36 ( V_3 , V_69 ,
V_38 ) ;
if ( ! V_259 -> V_155 ) {
F_4 ( V_259 ) ;
return NULL ;
}
}
if ( V_258 ) {
V_259 -> V_260 =
F_2 ( sizeof( struct V_260 ) , V_38 ) ;
if ( ! V_259 -> V_260 ) {
F_39 ( V_3 , V_259 -> V_155 ) ;
F_4 ( V_259 ) ;
return NULL ;
}
F_75 ( V_259 -> V_260 ) ;
}
V_259 -> V_261 = 0 ;
F_30 ( & V_259 -> V_262 ) ;
return V_259 ;
}
void F_135 ( struct V_263 * V_263 )
{
if ( V_263 ) {
F_4 ( V_263 -> V_264 [ 0 ] ) ;
F_4 ( V_263 ) ;
}
}
void F_55 ( struct V_2 * V_3 ,
struct V_256 * V_259 )
{
F_39 ( V_3 ,
V_259 -> V_155 ) ;
F_4 ( V_259 -> V_260 ) ;
F_4 ( V_259 ) ;
}
void F_136 ( struct V_2 * V_3 )
{
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
int V_70 ;
int V_8 , V_138 , V_137 ;
F_137 ( & V_3 -> V_265 ) ;
V_70 = sizeof( struct V_266 ) * ( V_3 -> V_267 . V_268 ) ;
if ( V_3 -> V_267 . V_269 )
F_45 ( V_81 , V_70 ,
V_3 -> V_267 . V_269 , V_3 -> V_267 . V_270 ) ;
V_3 -> V_267 . V_269 = NULL ;
F_35 ( V_3 , V_243 , L_31 ) ;
if ( V_3 -> V_271 )
F_26 ( V_3 , V_3 -> V_271 ) ;
V_3 -> V_271 = NULL ;
F_35 ( V_3 , V_243 , L_32 ) ;
if ( V_3 -> V_272 )
F_55 ( V_3 , V_3 -> V_272 ) ;
V_3 -> V_272 = NULL ;
if ( V_3 -> V_273 )
F_26 ( V_3 , V_3 -> V_273 ) ;
V_3 -> V_273 = NULL ;
F_35 ( V_3 , V_243 , L_33 ) ;
F_138 ( V_3 ) ;
V_137 = F_65 ( V_3 -> V_129 ) ;
for ( V_8 = 0 ; V_8 < V_137 && V_3 -> V_130 ; V_8 ++ ) {
struct V_141 * V_274 = & V_3 -> V_130 [ V_8 ] . V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ ) {
struct V_123 * V_89 = & V_274 -> V_147 [ V_138 ] . V_148 ;
while ( ! F_71 ( V_89 ) )
F_139 ( V_89 -> V_15 ) ;
}
}
for ( V_8 = 1 ; V_8 < V_275 ; ++ V_8 )
F_70 ( V_3 , V_8 ) ;
F_140 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_35 ( V_3 , V_243 , L_34 ) ;
F_140 ( V_3 -> V_73 ) ;
V_3 -> V_73 = NULL ;
F_35 ( V_3 , V_243 , L_35 ) ;
F_140 ( V_3 -> V_86 ) ;
V_3 -> V_86 = NULL ;
F_35 ( V_3 , V_243 ,
L_36 ) ;
F_140 ( V_3 -> V_87 ) ;
V_3 -> V_87 = NULL ;
F_35 ( V_3 , V_243 ,
L_37 ) ;
if ( V_3 -> V_151 )
F_45 ( V_81 , sizeof( * V_3 -> V_151 ) ,
V_3 -> V_151 , V_3 -> V_151 -> V_7 ) ;
V_3 -> V_151 = NULL ;
F_134 ( V_3 ) ;
if ( ! V_3 -> V_130 )
goto V_276;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
struct V_125 * V_136 , * V_277 ;
F_66 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_67 ( & V_136 -> V_132 ) ;
F_4 ( V_136 ) ;
}
}
V_276:
V_3 -> V_101 = 0 ;
V_3 -> V_278 = 0 ;
V_3 -> V_279 = 0 ;
V_3 -> V_280 = 0 ;
F_4 ( V_3 -> V_281 ) ;
F_4 ( V_3 -> V_282 ) ;
F_4 ( V_3 -> V_283 ) ;
F_4 ( V_3 -> V_130 ) ;
F_4 ( V_3 -> V_284 ) ;
V_3 -> V_281 = NULL ;
V_3 -> V_282 = NULL ;
V_3 -> V_283 = NULL ;
V_3 -> V_130 = NULL ;
V_3 -> V_284 = NULL ;
V_3 -> V_254 = 0 ;
V_3 -> V_285 = 0 ;
V_3 -> V_286 [ 0 ] . V_287 = 0 ;
V_3 -> V_286 [ 1 ] . V_287 = 0 ;
}
static int F_141 ( struct V_2 * V_3 ,
struct V_1 * V_288 ,
union V_62 * V_289 ,
union V_62 * V_290 ,
T_2 V_291 ,
struct V_1 * V_292 ,
char * V_293 , int V_294 )
{
unsigned long long V_295 ;
unsigned long long V_296 ;
struct V_1 * V_6 ;
V_295 = F_60 ( V_288 , V_289 ) ;
V_296 = F_60 ( V_288 , V_290 ) ;
V_6 = F_142 ( V_3 , V_288 , V_289 , V_290 , V_291 , false ) ;
if ( V_6 != V_292 ) {
F_72 ( V_3 , L_38 ,
V_293 , V_294 ) ;
F_72 ( V_3 , L_39
L_40 ,
V_288 ,
( unsigned long long ) V_291 ) ;
F_72 ( V_3 , L_41
L_42 ,
V_289 , V_295 ,
V_290 , V_296 ) ;
F_72 ( V_3 , L_43 ,
V_292 , V_6 ) ;
F_142 ( V_3 , V_288 , V_289 , V_290 , V_291 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct {
T_2 V_291 ;
struct V_1 * V_292 ;
} V_297 [] = {
{ 0 , NULL } ,
{ V_3 -> V_271 -> V_42 -> V_7 - 16 , NULL } ,
{ V_3 -> V_271 -> V_42 -> V_7 - 1 , NULL } ,
{ V_3 -> V_271 -> V_42 -> V_7 , V_3 -> V_271 -> V_42 } ,
{ V_3 -> V_271 -> V_42 -> V_7 + ( V_11 - 1 ) * 16 ,
V_3 -> V_271 -> V_42 } ,
{ V_3 -> V_271 -> V_42 -> V_7 + ( V_11 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_271 -> V_42 -> V_7 + ( V_11 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_288 ;
union V_62 * V_289 ;
union V_62 * V_290 ;
T_2 V_291 ;
struct V_1 * V_292 ;
} V_298 [] = {
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = V_3 -> V_271 -> V_42 -> V_9 ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ V_11 - 1 ] ,
. V_291 = V_3 -> V_273 -> V_42 -> V_7 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = V_3 -> V_271 -> V_42 -> V_9 ,
. V_290 = & V_3 -> V_273 -> V_42 -> V_9 [ V_11 - 1 ] ,
. V_291 = V_3 -> V_273 -> V_42 -> V_7 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = V_3 -> V_273 -> V_42 -> V_9 ,
. V_290 = & V_3 -> V_273 -> V_42 -> V_9 [ V_11 - 1 ] ,
. V_291 = V_3 -> V_273 -> V_42 -> V_7 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = & V_3 -> V_271 -> V_42 -> V_9 [ 0 ] ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ 3 ] ,
. V_291 = V_3 -> V_271 -> V_42 -> V_7 + 4 * 16 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = & V_3 -> V_271 -> V_42 -> V_9 [ 3 ] ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ 6 ] ,
. V_291 = V_3 -> V_271 -> V_42 -> V_7 + 2 * 16 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = & V_3 -> V_271 -> V_42 -> V_9 [ V_11 - 3 ] ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ 1 ] ,
. V_291 = V_3 -> V_271 -> V_42 -> V_7 + 2 * 16 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = & V_3 -> V_271 -> V_42 -> V_9 [ V_11 - 3 ] ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ 1 ] ,
. V_291 = V_3 -> V_271 -> V_42 -> V_7 + ( V_11 - 4 ) * 16 ,
. V_292 = NULL ,
} ,
{ . V_288 = V_3 -> V_271 -> V_42 ,
. V_289 = & V_3 -> V_271 -> V_42 -> V_9 [ V_11 - 3 ] ,
. V_290 = & V_3 -> V_271 -> V_42 -> V_9 [ 1 ] ,
. V_291 = V_3 -> V_273 -> V_42 -> V_7 + 2 * 16 ,
. V_292 = NULL ,
} ,
} ;
unsigned int V_299 ;
int V_8 , V_40 ;
V_299 = F_144 ( V_297 ) ;
for ( V_8 = 0 ; V_8 < V_299 ; V_8 ++ ) {
V_40 = F_141 ( V_3 ,
V_3 -> V_271 -> V_42 ,
V_3 -> V_271 -> V_42 -> V_9 ,
& V_3 -> V_271 -> V_42 -> V_9 [ V_11 - 1 ] ,
V_297 [ V_8 ] . V_291 ,
V_297 [ V_8 ] . V_292 ,
L_44 , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
}
V_299 = F_144 ( V_298 ) ;
for ( V_8 = 0 ; V_8 < V_299 ; V_8 ++ ) {
V_40 = F_141 ( V_3 ,
V_298 [ V_8 ] . V_288 ,
V_298 [ V_8 ] . V_289 ,
V_298 [ V_8 ] . V_290 ,
V_298 [ V_8 ] . V_291 ,
V_298 [ V_8 ] . V_292 ,
L_45 , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_32 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_145 ( struct V_2 * V_3 )
{
T_5 V_300 ;
T_2 V_119 ;
V_119 = F_60 ( V_3 -> V_271 -> V_48 ,
V_3 -> V_271 -> V_47 ) ;
if ( V_119 == 0 && ! F_146 () )
F_72 ( V_3 , L_47
L_48 ) ;
V_300 = F_147 ( V_3 , & V_3 -> V_301 -> V_302 ) ;
V_300 &= V_303 ;
V_300 &= ~ V_304 ;
F_35 ( V_3 , V_243 ,
L_49
L_50 ) ;
F_148 ( V_3 , ( ( T_5 ) V_119 & ( T_5 ) ~ V_303 ) | V_300 ,
& V_3 -> V_301 -> V_302 ) ;
}
static void F_149 ( struct V_2 * V_3 , unsigned int V_137 ,
T_6 T_7 * V_100 , int V_305 )
{
T_3 V_300 , V_306 , V_307 ;
int V_8 ;
T_8 V_308 ;
struct V_309 * V_310 ;
V_300 = F_150 ( V_100 ) ;
V_308 = F_151 ( V_300 ) ;
if ( V_308 == 0x03 ) {
V_310 = & V_3 -> V_311 ;
} else if ( V_308 <= 0x02 ) {
V_310 = & V_3 -> V_312 ;
} else {
F_72 ( V_3 , L_51
L_52 ,
V_100 , V_308 ) ;
return;
}
V_310 -> V_313 = F_151 ( V_300 ) ;
V_310 -> V_314 = F_152 ( V_300 ) ;
V_300 = F_150 ( V_100 + 2 ) ;
V_306 = F_153 ( V_300 ) ;
V_307 = F_154 ( V_300 ) ;
F_35 ( V_3 , V_243 ,
L_53
L_54 ,
V_100 , V_306 , V_307 , V_308 ) ;
if ( V_306 == 0 || ( V_306 + V_307 - 1 ) > V_137 )
return;
V_310 -> V_315 = F_155 ( V_300 ) ;
if ( V_310 -> V_315 ) {
V_310 -> V_316 = F_156 ( V_310 -> V_315 , sizeof( * V_310 -> V_316 ) ,
V_317 ) ;
if ( ! V_310 -> V_316 )
V_310 -> V_315 = 0 ;
V_310 -> V_318 ++ ;
for ( V_8 = 0 ; V_8 < V_310 -> V_315 ; V_8 ++ ) {
V_310 -> V_316 [ V_8 ] = F_150 ( V_100 + 4 + V_8 ) ;
if ( V_8 && ( F_157 ( V_310 -> V_316 [ V_8 ] ) !=
F_157 ( V_310 -> V_316 [ V_8 - 1 ] ) ) )
V_310 -> V_318 ++ ;
F_32 ( V_3 , L_55 ,
F_157 ( V_310 -> V_316 [ V_8 ] ) ,
F_158 ( V_310 -> V_316 [ V_8 ] ) ,
F_159 ( V_310 -> V_316 [ V_8 ] ) ,
F_160 ( V_310 -> V_316 [ V_8 ] ) ,
F_161 ( V_310 -> V_316 [ V_8 ] ) ,
F_162 ( V_310 -> V_316 [ V_8 ] ) ) ;
}
}
if ( V_308 < 0x03 && V_3 -> V_319 < V_305 )
V_3 -> V_284 [ V_3 -> V_319 ++ ] = V_300 ;
if ( ( V_3 -> V_226 == 0x96 ) && ( V_308 != 0x03 ) &&
( V_300 & V_320 ) ) {
F_35 ( V_3 , V_243 ,
L_56 ) ;
V_3 -> V_321 = 1 ;
}
if ( ( V_3 -> V_226 >= 0x100 ) && ( V_308 != 0x03 ) ) {
F_35 ( V_3 , V_243 ,
L_57 ) ;
V_3 -> V_321 = 1 ;
if ( V_300 & V_322 ) {
F_35 ( V_3 , V_243 ,
L_58 ) ;
V_3 -> V_323 = 1 ;
}
}
V_306 -- ;
for ( V_8 = V_306 ; V_8 < ( V_306 + V_307 ) ; V_8 ++ ) {
if ( V_3 -> V_283 [ V_8 ] != 0 ) {
F_72 ( V_3 , L_59
L_60 , V_100 , V_8 ) ;
F_72 ( V_3 , L_61
L_62 ,
V_3 -> V_283 [ V_8 ] , V_308 ) ;
if ( V_3 -> V_283 [ V_8 ] != V_308 &&
V_3 -> V_283 [ V_8 ] != V_324 ) {
if ( V_3 -> V_283 [ V_8 ] == 0x03 )
V_3 -> V_279 -- ;
else
V_3 -> V_278 -- ;
V_3 -> V_283 [ V_8 ] = V_324 ;
}
continue;
}
V_3 -> V_283 [ V_8 ] = V_308 ;
if ( V_308 == 0x03 )
V_3 -> V_279 ++ ;
else
V_3 -> V_278 ++ ;
}
}
static int F_163 ( struct V_2 * V_3 , T_1 V_5 )
{
void T_7 * V_325 ;
T_3 V_326 ;
unsigned int V_137 ;
int V_8 , V_138 , V_327 ;
int V_328 = 0 ;
T_3 V_329 ;
V_137 = F_65 ( V_3 -> V_129 ) ;
V_3 -> V_283 = F_2 ( sizeof( * V_3 -> V_283 ) * V_137 , V_5 ) ;
if ( ! V_3 -> V_283 )
return - V_51 ;
V_3 -> V_130 = F_2 ( sizeof( * V_3 -> V_130 ) * V_137 , V_5 ) ;
if ( ! V_3 -> V_130 )
return - V_51 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
struct V_141 * V_142 ;
F_30 ( & V_3 -> V_130 [ V_8 ] . V_131 ) ;
V_142 = & V_3 -> V_130 [ V_8 ] . V_142 ;
for ( V_138 = 0 ; V_138 < V_146 ; V_138 ++ )
F_30 ( & V_142 -> V_147 [ V_138 ] . V_148 ) ;
}
V_325 = & V_3 -> V_330 -> V_331 ;
V_329 = F_164 ( V_325 , 0 , V_332 ) ;
if ( ! V_329 ) {
F_165 ( V_3 , L_63 ) ;
return - V_333 ;
}
V_326 = V_329 ;
while ( V_326 ) {
V_328 ++ ;
V_326 = F_164 ( V_325 , V_326 ,
V_332 ) ;
}
V_3 -> V_284 = F_2 ( sizeof( * V_3 -> V_284 ) * V_328 , V_5 ) ;
if ( ! V_3 -> V_284 )
return - V_51 ;
V_326 = V_329 ;
while ( V_326 ) {
F_149 ( V_3 , V_137 , V_325 + V_326 , V_328 ) ;
if ( V_3 -> V_278 + V_3 -> V_279 == V_137 )
break;
V_326 = F_164 ( V_325 , V_326 ,
V_332 ) ;
}
if ( V_3 -> V_278 == 0 && V_3 -> V_279 == 0 ) {
F_72 ( V_3 , L_64 ) ;
return - V_333 ;
}
F_35 ( V_3 , V_243 ,
L_65 ,
V_3 -> V_278 , V_3 -> V_279 ) ;
if ( V_3 -> V_279 > 15 ) {
F_35 ( V_3 , V_243 ,
L_66 ) ;
V_3 -> V_279 = 15 ;
}
if ( V_3 -> V_278 > V_334 ) {
F_35 ( V_3 , V_243 ,
L_67 ,
V_334 ) ;
V_3 -> V_278 = V_334 ;
}
if ( V_3 -> V_278 ) {
V_3 -> V_281 = F_166 ( sizeof( * V_3 -> V_281 ) *
V_3 -> V_278 , V_5 ) ;
if ( ! V_3 -> V_281 )
return - V_51 ;
V_327 = 0 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
if ( V_3 -> V_283 [ V_8 ] == 0x03 ||
V_3 -> V_283 [ V_8 ] == 0 ||
V_3 -> V_283 [ V_8 ] == V_324 )
continue;
V_3 -> V_281 [ V_327 ] =
& V_3 -> V_335 -> V_336 +
V_337 * V_8 ;
F_35 ( V_3 , V_243 ,
L_68
L_69 , V_8 ,
V_3 -> V_281 [ V_327 ] ) ;
V_327 ++ ;
if ( V_327 == V_3 -> V_278 )
break;
}
}
if ( V_3 -> V_279 ) {
V_3 -> V_282 = F_166 ( sizeof( * V_3 -> V_282 ) *
V_3 -> V_279 , V_5 ) ;
if ( ! V_3 -> V_282 )
return - V_51 ;
V_327 = 0 ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ )
if ( V_3 -> V_283 [ V_8 ] == 0x03 ) {
V_3 -> V_282 [ V_327 ] =
& V_3 -> V_335 -> V_336 +
V_337 * V_8 ;
F_35 ( V_3 , V_243 ,
L_70
L_69 , V_8 ,
V_3 -> V_282 [ V_327 ] ) ;
V_327 ++ ;
if ( V_327 == V_3 -> V_279 )
break;
}
}
return 0 ;
}
int F_167 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_80 * V_81 = F_44 ( V_3 ) -> V_82 . V_83 ;
unsigned int V_19 , V_338 ;
T_5 V_339 ;
struct V_1 * V_6 ;
T_3 V_254 , V_300 ;
int V_8 ;
F_30 ( & V_3 -> V_262 ) ;
F_63 ( & V_3 -> V_265 , V_340 ,
( unsigned long ) V_3 ) ;
V_254 = F_150 ( & V_3 -> V_335 -> V_254 ) ;
F_35 ( V_3 , V_243 ,
L_71 , V_254 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_254 ) != 0 )
break;
V_254 = V_254 >> 1 ;
}
if ( V_8 < 16 )
F_35 ( V_3 , V_243 ,
L_72 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_72 ( V_3 , L_73 ) ;
V_3 -> V_285 = 12 ;
V_3 -> V_254 = 1 << V_3 -> V_285 ;
F_35 ( V_3 , V_243 ,
L_74 , V_3 -> V_254 / 1024 ) ;
V_19 = F_168 ( F_150 ( & V_3 -> V_330 -> V_129 ) ) ;
F_35 ( V_3 , V_243 ,
L_75 , V_19 ) ;
V_338 = F_150 ( & V_3 -> V_335 -> V_341 ) ;
V_19 |= ( V_338 & ~ V_342 ) ;
F_35 ( V_3 , V_243 ,
L_76 , V_19 ) ;
F_169 ( V_19 , & V_3 -> V_335 -> V_341 ) ;
V_3 -> V_151 = F_47 ( V_81 , sizeof( * V_3 -> V_151 ) , & V_7 ,
V_317 ) ;
if ( ! V_3 -> V_151 )
goto V_53;
memset ( V_3 -> V_151 , 0 , sizeof *( V_3 -> V_151 ) ) ;
V_3 -> V_151 -> V_7 = V_7 ;
F_35 ( V_3 , V_243 ,
L_77 ,
( unsigned long long ) V_3 -> V_151 -> V_7 , V_3 -> V_151 ) ;
F_148 ( V_3 , V_7 , & V_3 -> V_335 -> V_343 ) ;
V_3 -> V_10 = F_170 ( L_78 , V_81 ,
V_344 , V_344 , V_3 -> V_254 ) ;
V_3 -> V_73 = F_170 ( L_79 , V_81 ,
2112 , 64 , V_3 -> V_254 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_73 )
goto V_53;
V_3 -> V_86 =
F_170 ( L_80 ,
V_81 , V_85 , 16 , 0 ) ;
V_3 -> V_87 =
F_170 ( L_81 ,
V_81 , V_84 , 16 , 0 ) ;
if ( ! V_3 -> V_86 || ! V_3 -> V_87 )
goto V_53;
V_3 -> V_273 = F_29 ( V_3 , 1 , 1 , V_345 , V_5 ) ;
if ( ! V_3 -> V_273 )
goto V_53;
F_35 ( V_3 , V_243 ,
L_82 , V_3 -> V_273 ) ;
F_35 ( V_3 , V_243 , L_83 ,
( unsigned long long ) V_3 -> V_273 -> V_42 -> V_7 ) ;
V_339 = F_147 ( V_3 , & V_3 -> V_335 -> V_273 ) ;
V_339 = ( V_339 & ( T_5 ) V_346 ) |
( V_3 -> V_273 -> V_42 -> V_7 & ( T_5 ) ~ V_346 ) |
V_3 -> V_273 -> V_4 ;
F_35 ( V_3 , V_243 ,
L_84 , V_19 ) ;
F_148 ( V_3 , V_339 , & V_3 -> V_335 -> V_273 ) ;
F_171 ( V_3 ) ;
V_3 -> V_272 = F_52 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_272 )
goto V_53;
V_3 -> V_101 ++ ;
V_19 = F_150 ( & V_3 -> V_330 -> V_347 ) ;
V_19 &= V_348 ;
F_35 ( V_3 , V_243 ,
L_85
L_86 , V_19 ) ;
V_3 -> V_349 = ( void T_7 * ) V_3 -> V_330 + V_19 ;
F_172 ( V_3 ) ;
F_173 ( V_3 ) ;
V_3 -> V_301 = & V_3 -> V_350 -> V_301 [ 0 ] ;
F_35 ( V_3 , V_243 , L_87 ) ;
V_3 -> V_271 = F_29 ( V_3 , V_351 , 1 , V_20 ,
V_5 ) ;
if ( ! V_3 -> V_271 )
goto V_53;
if ( F_143 ( V_3 ) < 0 )
goto V_53;
V_3 -> V_267 . V_269 = F_47 ( V_81 ,
sizeof( struct V_266 ) * V_351 , & V_7 ,
V_317 ) ;
if ( ! V_3 -> V_267 . V_269 )
goto V_53;
F_35 ( V_3 , V_243 ,
L_88 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_267 . V_269 , 0 , sizeof( struct V_266 ) * V_351 ) ;
V_3 -> V_267 . V_268 = V_351 ;
V_3 -> V_267 . V_270 = V_7 ;
F_35 ( V_3 , V_243 ,
L_89 ,
V_3 -> V_267 . V_268 ,
V_3 -> V_267 . V_269 ,
( unsigned long long ) V_3 -> V_267 . V_270 ) ;
for ( V_19 = 0 , V_6 = V_3 -> V_271 -> V_42 ; V_19 < V_351 ; V_19 ++ ) {
struct V_266 * V_352 = & V_3 -> V_267 . V_269 [ V_19 ] ;
V_352 -> V_353 = F_10 ( V_6 -> V_7 ) ;
V_352 -> V_354 = F_5 ( V_11 ) ;
V_352 -> V_355 = 0 ;
V_6 = V_6 -> V_15 ;
}
V_19 = F_150 ( & V_3 -> V_301 -> V_356 ) ;
V_19 &= V_357 ;
V_19 |= V_351 ;
F_35 ( V_3 , V_243 ,
L_90 ,
V_19 ) ;
F_169 ( V_19 , & V_3 -> V_301 -> V_356 ) ;
F_35 ( V_3 , V_243 ,
L_91 ) ;
F_35 ( V_3 , V_243 ,
L_92 ,
( unsigned long long ) V_3 -> V_267 . V_270 ) ;
V_339 = F_147 ( V_3 , & V_3 -> V_301 -> V_358 ) ;
V_339 &= V_303 ;
V_339 |= ( V_3 -> V_267 . V_270 & ( T_5 ) ~ V_303 ) ;
F_148 ( V_3 , V_339 , & V_3 -> V_301 -> V_358 ) ;
F_145 ( V_3 ) ;
F_35 ( V_3 , V_243 ,
L_93 ) ;
F_174 ( V_3 , 0 ) ;
F_75 ( & V_3 -> V_359 ) ;
for ( V_8 = 0 ; V_8 < V_275 ; ++ V_8 )
V_3 -> V_150 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_334 ; ++ V_8 ) {
V_3 -> V_286 [ 0 ] . V_360 [ V_8 ] = 0 ;
V_3 -> V_286 [ 1 ] . V_360 [ V_8 ] = 0 ;
F_75 ( & V_3 -> V_286 [ 1 ] . V_361 [ V_8 ] ) ;
}
if ( F_132 ( V_3 , V_5 ) )
goto V_53;
if ( F_163 ( V_3 , V_5 ) )
goto V_53;
V_300 = F_150 ( & V_3 -> V_335 -> V_362 ) ;
V_300 &= ~ V_363 ;
V_300 |= V_364 ;
F_169 ( V_300 , & V_3 -> V_335 -> V_362 ) ;
return 0 ;
V_53:
F_72 ( V_3 , L_94 ) ;
F_175 ( V_3 ) ;
F_176 ( V_3 ) ;
F_136 ( V_3 ) ;
return - V_51 ;
}
