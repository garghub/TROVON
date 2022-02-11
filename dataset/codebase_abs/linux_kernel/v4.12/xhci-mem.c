static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 ;
T_2 V_8 ;
int V_9 ;
V_7 = F_2 ( sizeof *V_7 , V_6 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_10 = F_3 ( V_3 -> V_11 , V_6 , & V_8 ) ;
if ( ! V_7 -> V_10 ) {
F_4 ( V_7 ) ;
return NULL ;
}
if ( V_5 ) {
V_7 -> V_12 = F_2 ( V_5 , V_6 ) ;
if ( ! V_7 -> V_12 ) {
F_5 ( V_3 -> V_11 , V_7 -> V_10 , V_8 ) ;
F_4 ( V_7 ) ;
return NULL ;
}
}
if ( V_4 == 0 ) {
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
V_7 -> V_10 [ V_9 ] . V_14 . V_15 |= F_6 ( V_16 ) ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_17 = NULL ;
return V_7 ;
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
if ( V_7 -> V_10 ) {
F_5 ( V_3 -> V_11 , V_7 -> V_10 , V_7 -> V_8 ) ;
V_7 -> V_10 = NULL ;
}
F_4 ( V_7 -> V_12 ) ;
F_4 ( V_7 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_18 )
{
struct V_1 * V_7 ;
V_7 = V_18 -> V_17 ;
while ( V_7 != V_18 ) {
struct V_1 * V_17 = V_7 -> V_17 ;
F_7 ( V_3 , V_7 ) ;
V_7 = V_17 ;
}
F_7 ( V_3 , V_18 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_1 * V_19 ,
struct V_1 * V_17 , enum V_20 type )
{
T_3 V_21 ;
if ( ! V_19 || ! V_17 )
return;
V_19 -> V_17 = V_17 ;
if ( type != V_22 ) {
V_19 -> V_10 [ V_13 - 1 ] . V_14 . V_23 =
F_10 ( V_17 -> V_8 ) ;
V_21 = F_11 ( V_19 -> V_10 [ V_13 - 1 ] . V_14 . V_15 ) ;
V_21 &= ~ V_24 ;
V_21 |= F_12 ( V_25 ) ;
if ( F_13 ( V_3 ) ||
( type == V_26 &&
( V_3 -> V_27 & V_28 ) ) )
V_21 |= V_29 ;
V_19 -> V_10 [ V_13 - 1 ] . V_14 . V_15 = F_6 ( V_21 ) ;
}
}
static void F_14 ( struct V_2 * V_3 , struct V_30 * V_31 ,
struct V_1 * V_18 , struct V_1 * V_32 ,
unsigned int V_33 )
{
struct V_1 * V_17 ;
if ( ! V_31 || ! V_18 || ! V_32 )
return;
V_17 = V_31 -> V_34 -> V_17 ;
F_9 ( V_3 , V_31 -> V_34 , V_18 , V_31 -> type ) ;
F_9 ( V_3 , V_32 , V_17 , V_31 -> type ) ;
V_31 -> V_33 += V_33 ;
V_31 -> V_35 += ( V_13 - 1 ) * V_33 ;
if ( V_31 -> type != V_22 && V_31 -> V_34 == V_31 -> V_36 ) {
V_31 -> V_36 -> V_10 [ V_13 - 1 ] . V_14 . V_15
&= ~ F_6 ( V_37 ) ;
V_32 -> V_10 [ V_13 - 1 ] . V_14 . V_15
|= F_6 ( V_37 ) ;
V_31 -> V_36 = V_32 ;
}
}
static int F_15 ( struct V_38 * V_39 ,
struct V_30 * V_31 ,
struct V_1 * V_7 ,
T_1 V_40 )
{
unsigned long V_41 ;
int V_42 ;
V_41 = ( unsigned long ) ( V_7 -> V_8 >> V_43 ) ;
if ( F_16 ( V_39 , V_41 ) )
return 0 ;
V_42 = F_17 ( V_40 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_18 ( V_39 ,
V_41 , V_31 ) ;
F_19 () ;
return V_42 ;
}
static void F_20 ( struct V_38 * V_39 ,
struct V_1 * V_7 )
{
unsigned long V_41 ;
V_41 = ( unsigned long ) ( V_7 -> V_8 >> V_43 ) ;
if ( F_16 ( V_39 , V_41 ) )
F_21 ( V_39 , V_41 ) ;
}
static int F_22 (
struct V_38 * V_39 ,
struct V_30 * V_31 ,
struct V_1 * V_44 ,
struct V_1 * V_36 ,
T_1 V_40 )
{
struct V_1 * V_7 ;
struct V_1 * V_45 ;
int V_42 ;
if ( F_23 ( V_39 == NULL ) )
return 0 ;
V_7 = V_44 ;
do {
V_42 = F_15 ( V_39 ,
V_31 , V_7 , V_40 ) ;
if ( V_42 )
goto V_46;
if ( V_7 == V_36 )
return 0 ;
V_7 = V_7 -> V_17 ;
} while ( V_7 != V_44 );
return 0 ;
V_46:
V_45 = V_7 ;
V_7 = V_44 ;
do {
F_20 ( V_39 , V_7 ) ;
if ( V_7 == V_45 )
return V_42 ;
V_7 = V_7 -> V_17 ;
} while ( V_7 != V_44 );
return V_42 ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_1 * V_7 ;
if ( F_23 ( V_31 -> V_39 == NULL ) )
return;
V_7 = V_31 -> V_44 ;
do {
F_20 ( V_31 -> V_39 , V_7 ) ;
V_7 = V_7 -> V_17 ;
} while ( V_7 != V_31 -> V_44 );
}
static int F_25 ( struct V_30 * V_31 , T_1 V_40 )
{
return F_22 ( V_31 -> V_39 , V_31 ,
V_31 -> V_44 , V_31 -> V_36 , V_40 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
if ( ! V_31 )
return;
F_27 ( V_31 ) ;
if ( V_31 -> V_44 ) {
if ( V_31 -> type == V_47 )
F_24 ( V_31 ) ;
F_8 ( V_3 , V_31 -> V_44 ) ;
}
F_4 ( V_31 ) ;
}
static void F_28 ( struct V_30 * V_31 ,
unsigned int V_4 )
{
V_31 -> V_48 = V_31 -> V_44 -> V_10 ;
V_31 -> V_34 = V_31 -> V_44 ;
V_31 -> V_49 = V_31 -> V_48 ;
V_31 -> V_50 = V_31 -> V_44 ;
V_31 -> V_4 = V_4 ;
V_31 -> V_35 = V_31 -> V_33 * ( V_13 - 1 ) - 1 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_1 * * V_18 , struct V_1 * * V_32 ,
unsigned int V_33 , unsigned int V_4 ,
enum V_20 type , unsigned int V_5 , T_1 V_6 )
{
struct V_1 * V_19 ;
V_19 = F_1 ( V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_19 )
return - V_51 ;
V_33 -- ;
* V_18 = V_19 ;
while ( V_33 > 0 ) {
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_17 ) {
V_19 = * V_18 ;
while ( V_19 ) {
V_17 = V_19 -> V_17 ;
F_7 ( V_3 , V_19 ) ;
V_19 = V_17 ;
}
return - V_51 ;
}
F_9 ( V_3 , V_19 , V_17 , type ) ;
V_19 = V_17 ;
V_33 -- ;
}
F_9 ( V_3 , V_19 , * V_18 , type ) ;
* V_32 = V_19 ;
return 0 ;
}
static struct V_30 * F_30 ( struct V_2 * V_3 ,
unsigned int V_33 , unsigned int V_4 ,
enum V_20 type , unsigned int V_5 , T_1 V_6 )
{
struct V_30 * V_31 ;
int V_42 ;
V_31 = F_2 ( sizeof *( V_31 ) , V_6 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_33 = V_33 ;
V_31 -> V_52 = V_5 ;
F_31 ( & V_31 -> V_53 ) ;
V_31 -> type = type ;
if ( V_33 == 0 )
return V_31 ;
V_42 = F_29 ( V_3 , & V_31 -> V_44 ,
& V_31 -> V_36 , V_33 , V_4 , type ,
V_5 , V_6 ) ;
if ( V_42 )
goto V_54;
if ( type != V_22 ) {
V_31 -> V_36 -> V_10 [ V_13 - 1 ] . V_14 . V_15 |=
F_6 ( V_37 ) ;
}
F_28 ( V_31 , V_4 ) ;
F_32 ( V_31 ) ;
return V_31 ;
V_54:
F_4 ( V_31 ) ;
return NULL ;
}
void F_33 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
unsigned int V_57 )
{
int V_58 ;
V_58 = V_56 -> V_59 ;
if ( V_58 < V_60 ) {
V_56 -> V_61 [ V_58 ] =
V_56 -> V_62 [ V_57 ] . V_31 ;
V_56 -> V_59 ++ ;
F_34 ( V_3 , L_1
L_2 ,
V_56 -> V_59 ,
( V_56 -> V_59 > 1 ) ? L_3 : L_4 ) ;
} else {
F_26 ( V_3 , V_56 -> V_62 [ V_57 ] . V_31 ) ;
F_34 ( V_3 , L_5
L_6 ,
V_56 -> V_59 ) ;
}
V_56 -> V_62 [ V_57 ] . V_31 = NULL ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_30 * V_31 , unsigned int V_4 ,
enum V_20 type )
{
struct V_1 * V_7 = V_31 -> V_44 ;
int V_9 ;
do {
memset ( V_7 -> V_10 , 0 ,
sizeof( union V_63 ) * V_13 ) ;
if ( V_4 == 0 ) {
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
V_7 -> V_10 [ V_9 ] . V_14 . V_15 |=
F_6 ( V_16 ) ;
}
F_9 ( V_3 , V_7 , V_7 -> V_17 , type ) ;
V_7 = V_7 -> V_17 ;
} while ( V_7 != V_31 -> V_44 );
V_31 -> type = type ;
F_28 ( V_31 , V_4 ) ;
F_31 ( & V_31 -> V_53 ) ;
}
int F_36 ( struct V_2 * V_3 , struct V_30 * V_31 ,
unsigned int V_64 , T_1 V_6 )
{
struct V_1 * V_18 ;
struct V_1 * V_32 ;
unsigned int V_33 ;
unsigned int V_65 ;
int V_42 ;
V_65 = ( V_64 + ( V_13 - 1 ) - 1 ) /
( V_13 - 1 ) ;
V_33 = V_31 -> V_33 > V_65 ?
V_31 -> V_33 : V_65 ;
V_42 = F_29 ( V_3 , & V_18 , & V_32 ,
V_33 , V_31 -> V_4 , V_31 -> type ,
V_31 -> V_52 , V_6 ) ;
if ( V_42 )
return - V_51 ;
if ( V_31 -> type == V_47 )
V_42 = F_22 ( V_31 -> V_39 ,
V_31 , V_18 , V_32 , V_6 ) ;
if ( V_42 ) {
struct V_1 * V_17 ;
do {
V_17 = V_18 -> V_17 ;
F_7 ( V_3 , V_18 ) ;
if ( V_18 == V_32 )
break;
V_18 = V_17 ;
} while ( true );
return V_42 ;
}
F_14 ( V_3 , V_31 , V_18 , V_32 , V_33 ) ;
F_37 ( V_31 ) ;
F_38 ( V_3 , V_66 ,
L_7 ,
V_31 -> V_33 ) ;
return 0 ;
}
static struct V_67 * F_39 ( struct V_2 * V_3 ,
int type , T_1 V_6 )
{
struct V_67 * V_68 ;
if ( ( type != V_69 ) && ( type != V_70 ) )
return NULL ;
V_68 = F_2 ( sizeof( * V_68 ) , V_6 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> type = type ;
V_68 -> V_71 = F_40 ( V_3 -> V_72 ) ? 2048 : 1024 ;
if ( type == V_70 )
V_68 -> V_71 += F_41 ( V_3 -> V_72 ) ;
V_68 -> V_73 = F_3 ( V_3 -> V_74 , V_6 , & V_68 -> V_8 ) ;
if ( ! V_68 -> V_73 ) {
F_4 ( V_68 ) ;
return NULL ;
}
return V_68 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
if ( ! V_68 )
return;
F_5 ( V_3 -> V_74 , V_68 -> V_73 , V_68 -> V_8 ) ;
F_4 ( V_68 ) ;
}
struct V_75 * F_43 (
struct V_67 * V_68 )
{
if ( V_68 -> type != V_70 )
return NULL ;
return (struct V_75 * ) V_68 -> V_73 ;
}
struct V_76 * F_44 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
if ( V_68 -> type == V_69 )
return (struct V_76 * ) V_68 -> V_73 ;
return (struct V_76 * )
( V_68 -> V_73 + F_41 ( V_3 -> V_72 ) ) ;
}
struct V_77 * F_45 ( struct V_2 * V_3 ,
struct V_67 * V_68 ,
unsigned int V_57 )
{
V_57 ++ ;
if ( V_68 -> type == V_70 )
V_57 ++ ;
return (struct V_77 * )
( V_68 -> V_73 + ( V_57 * F_41 ( V_3 -> V_72 ) ) ) ;
}
static void F_46 ( struct V_2 * V_3 ,
unsigned int V_78 ,
struct V_79 * V_80 , T_2 V_8 )
{
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
T_4 V_71 = sizeof( struct V_79 ) * V_78 ;
if ( V_71 > V_85 )
F_48 ( V_82 , V_71 ,
V_80 , V_8 ) ;
else if ( V_71 <= V_86 )
return F_5 ( V_3 -> V_87 ,
V_80 , V_8 ) ;
else
return F_5 ( V_3 -> V_88 ,
V_80 , V_8 ) ;
}
static struct V_79 * F_49 ( struct V_2 * V_3 ,
unsigned int V_78 , T_2 * V_8 ,
T_1 V_40 )
{
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
T_4 V_71 = sizeof( struct V_79 ) * V_78 ;
if ( V_71 > V_85 )
return F_50 ( V_82 , V_71 ,
V_8 , V_40 ) ;
else if ( V_71 <= V_86 )
return F_51 ( V_3 -> V_87 ,
V_40 , V_8 ) ;
else
return F_51 ( V_3 -> V_88 ,
V_40 , V_8 ) ;
}
struct V_30 * F_52 (
struct V_89 * V_90 ,
T_5 V_91 )
{
if ( V_90 -> V_92 & V_93 )
return F_16 ( & V_90 -> V_94 -> V_39 ,
V_91 >> V_43 ) ;
return V_90 -> V_31 ;
}
struct V_30 * F_53 (
struct V_55 * V_82 ,
unsigned int V_57 ,
unsigned int V_95 )
{
struct V_89 * V_90 = & V_82 -> V_62 [ V_57 ] ;
if ( V_95 == 0 )
return V_90 -> V_31 ;
if ( ! V_90 -> V_94 )
return NULL ;
if ( V_95 > V_90 -> V_94 -> V_96 )
return NULL ;
return V_90 -> V_94 -> V_97 [ V_95 ] ;
}
struct V_98 * F_54 ( struct V_2 * V_3 ,
unsigned int V_78 ,
unsigned int V_96 ,
unsigned int V_5 , T_1 V_40 )
{
struct V_98 * V_94 ;
T_3 V_99 ;
struct V_30 * V_100 ;
T_5 V_101 ;
int V_42 ;
F_34 ( V_3 , L_8
L_9 ,
V_96 , V_78 ) ;
if ( V_3 -> V_102 == V_103 ) {
F_34 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_102 ++ ;
V_94 = F_2 ( sizeof( struct V_98 ) , V_40 ) ;
if ( ! V_94 )
goto V_104;
V_94 -> V_96 = V_96 ;
V_94 -> V_78 = V_78 ;
V_94 -> V_97 = F_2 (
sizeof( struct V_30 * ) * V_96 ,
V_40 ) ;
if ( ! V_94 -> V_97 )
goto V_105;
V_94 -> V_106 = F_49 ( V_3 ,
V_78 , & V_94 -> V_107 ,
V_40 ) ;
if ( ! V_94 -> V_106 )
goto V_108;
memset ( V_94 -> V_106 , 0 ,
sizeof( struct V_79 ) * V_78 ) ;
V_94 -> V_109 =
F_55 ( V_3 , true , true , V_40 ) ;
if ( ! V_94 -> V_109 )
goto V_108;
F_56 ( & V_94 -> V_39 , V_110 ) ;
for ( V_99 = 1 ; V_99 < V_96 ; V_99 ++ ) {
V_94 -> V_97 [ V_99 ] =
F_30 ( V_3 , 2 , 1 , V_47 , V_5 ,
V_40 ) ;
V_100 = V_94 -> V_97 [ V_99 ] ;
if ( ! V_100 )
goto V_111;
V_100 -> V_95 = V_99 ;
V_100 -> V_39 = & V_94 -> V_39 ;
V_101 = V_100 -> V_44 -> V_8 |
F_57 ( V_112 ) |
V_100 -> V_4 ;
V_94 -> V_106 [ V_99 ] . V_113 =
F_10 ( V_101 ) ;
F_34 ( V_3 , L_11 ,
V_99 , ( unsigned long long ) V_101 ) ;
V_42 = F_25 ( V_100 , V_40 ) ;
if ( V_42 ) {
F_26 ( V_3 , V_100 ) ;
V_94 -> V_97 [ V_99 ] = NULL ;
goto V_111;
}
}
return V_94 ;
V_111:
for ( V_99 = 1 ; V_99 < V_96 ; V_99 ++ ) {
V_100 = V_94 -> V_97 [ V_99 ] ;
if ( V_100 ) {
F_26 ( V_3 , V_100 ) ;
V_94 -> V_97 [ V_99 ] = NULL ;
}
}
F_58 ( V_3 , V_94 -> V_109 ) ;
V_108:
F_4 ( V_94 -> V_97 ) ;
V_105:
F_4 ( V_94 ) ;
V_104:
V_3 -> V_102 -- ;
return NULL ;
}
void F_59 ( struct V_2 * V_3 ,
struct V_77 * V_114 ,
struct V_98 * V_94 )
{
T_3 V_115 ;
V_115 = F_60 ( V_94 -> V_78 ) - 2 ;
F_38 ( V_3 , V_116 ,
L_12 ,
1 << ( V_115 + 1 ) ) ;
V_114 -> V_117 &= F_6 ( ~ V_118 ) ;
V_114 -> V_117 |= F_6 ( F_61 ( V_115 )
| V_119 ) ;
V_114 -> V_120 = F_10 ( V_94 -> V_107 ) ;
}
void F_62 ( struct V_77 * V_114 ,
struct V_89 * V_90 )
{
T_2 V_101 ;
V_114 -> V_117 &= F_6 ( ~ ( V_118 | V_119 ) ) ;
V_101 = F_63 ( V_90 -> V_31 -> V_50 , V_90 -> V_31 -> V_49 ) ;
V_114 -> V_120 = F_10 ( V_101 | V_90 -> V_31 -> V_4 ) ;
}
void F_64 ( struct V_2 * V_3 ,
struct V_98 * V_94 )
{
int V_99 ;
struct V_30 * V_100 ;
if ( ! V_94 )
return;
for ( V_99 = 1 ; V_99 < V_94 -> V_96 ;
V_99 ++ ) {
V_100 = V_94 -> V_97 [ V_99 ] ;
if ( V_100 ) {
F_26 ( V_3 , V_100 ) ;
V_94 -> V_97 [ V_99 ] = NULL ;
}
}
F_58 ( V_3 , V_94 -> V_109 ) ;
V_3 -> V_102 -- ;
if ( V_94 -> V_106 )
F_46 ( V_3 ,
V_94 -> V_78 ,
V_94 -> V_106 ,
V_94 -> V_107 ) ;
F_4 ( V_94 -> V_97 ) ;
F_4 ( V_94 ) ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
F_66 ( & V_90 -> V_121 , V_122 ,
( unsigned long ) V_90 ) ;
V_90 -> V_3 = V_3 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
int V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 , * V_17 ;
bool V_128 = false ;
if ( V_56 -> V_129 == 0 ||
V_56 -> V_129 > F_68 ( V_3 -> V_130 ) ) {
F_34 ( V_3 , L_13 ) ;
return;
}
V_125 = & ( V_3 -> V_131 [ V_56 -> V_129 - 1 ] . V_132 ) ;
F_69 (tt_info, next, tt_list_head, tt_list) {
if ( V_127 -> V_123 == V_123 ) {
V_128 = true ;
F_70 ( & V_127 -> V_133 ) ;
F_4 ( V_127 ) ;
} else if ( V_128 ) {
break;
}
}
}
int F_71 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_134 * V_135 ,
struct V_136 * V_137 , T_1 V_40 )
{
struct V_126 * V_127 ;
unsigned int V_138 ;
int V_9 , V_139 ;
if ( ! V_137 -> V_140 )
V_138 = 1 ;
else
V_138 = V_135 -> V_141 ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ , V_127 ++ ) {
struct V_142 * V_143 ;
V_127 = F_2 ( sizeof( * V_127 ) , V_40 ) ;
if ( ! V_127 )
goto V_144;
F_31 ( & V_127 -> V_133 ) ;
F_72 ( & V_127 -> V_133 ,
& V_3 -> V_131 [ V_56 -> V_129 - 1 ] . V_132 ) ;
V_127 -> V_123 = V_56 -> V_145 -> V_123 ;
if ( V_137 -> V_140 )
V_127 -> V_146 = V_9 + 1 ;
V_143 = & V_127 -> V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_31 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
return 0 ;
V_144:
F_67 ( V_3 , V_56 , V_56 -> V_145 -> V_123 ) ;
return - V_51 ;
}
void F_73 ( struct V_2 * V_3 , int V_123 )
{
struct V_55 * V_82 ;
int V_9 ;
int V_150 = 0 ;
if ( V_123 == 0 || ! V_3 -> V_151 [ V_123 ] )
return;
V_82 = V_3 -> V_151 [ V_123 ] ;
F_74 ( V_82 ) ;
V_3 -> V_152 -> V_153 [ V_123 ] = 0 ;
if ( ! V_82 )
return;
if ( V_82 -> V_127 )
V_150 = V_82 -> V_127 -> V_154 ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
if ( V_82 -> V_62 [ V_9 ] . V_31 )
F_26 ( V_3 , V_82 -> V_62 [ V_9 ] . V_31 ) ;
if ( V_82 -> V_62 [ V_9 ] . V_94 )
F_64 ( V_3 ,
V_82 -> V_62 [ V_9 ] . V_94 ) ;
if ( ! F_75 ( & V_82 -> V_62 [ V_9 ] . V_155 ) )
F_76 ( V_3 , L_14
L_15 ,
V_123 , V_9 ) ;
}
F_67 ( V_3 , V_82 , V_123 ) ;
F_77 ( V_3 , V_82 , V_150 ) ;
if ( V_82 -> V_61 ) {
for ( V_9 = 0 ; V_9 < V_82 -> V_59 ; V_9 ++ )
F_26 ( V_3 , V_82 -> V_61 [ V_9 ] ) ;
F_4 ( V_82 -> V_61 ) ;
}
if ( V_82 -> V_156 )
F_42 ( V_3 , V_82 -> V_156 ) ;
if ( V_82 -> V_157 )
F_42 ( V_3 , V_82 -> V_157 ) ;
F_4 ( V_3 -> V_151 [ V_123 ] ) ;
V_3 -> V_151 [ V_123 ] = NULL ;
}
void F_78 ( struct V_2 * V_3 , int V_123 )
{
struct V_55 * V_158 ;
struct V_124 * V_125 ;
struct V_126 * V_127 , * V_17 ;
int V_9 ;
V_158 = V_3 -> V_151 [ V_123 ] ;
if ( ! V_158 )
return;
V_125 = & ( V_3 -> V_131 [ V_158 -> V_129 - 1 ] . V_132 ) ;
F_69 (tt_info, next, tt_list_head, tt_list) {
if ( V_127 -> V_123 == V_123 ) {
for ( V_9 = 1 ; V_9 < F_79 ( V_3 -> V_130 ) ; V_9 ++ ) {
V_158 = V_3 -> V_151 [ V_9 ] ;
if ( V_158 && ( V_158 -> V_127 == V_127 ) )
F_78 (
V_3 , V_9 ) ;
}
}
}
F_73 ( V_3 , V_123 ) ;
}
int F_80 ( struct V_2 * V_3 , int V_123 ,
struct V_134 * V_145 , T_1 V_6 )
{
struct V_55 * V_82 ;
int V_9 ;
if ( V_123 == 0 || V_3 -> V_151 [ V_123 ] ) {
F_76 ( V_3 , L_16 , V_123 ) ;
return 0 ;
}
V_3 -> V_151 [ V_123 ] = F_2 ( sizeof( * V_3 -> V_151 [ V_123 ] ) , V_6 ) ;
if ( ! V_3 -> V_151 [ V_123 ] )
return 0 ;
V_82 = V_3 -> V_151 [ V_123 ] ;
V_82 -> V_157 = F_39 ( V_3 , V_69 , V_6 ) ;
if ( ! V_82 -> V_157 )
goto V_54;
F_34 ( V_3 , L_17 , V_123 ,
( unsigned long long ) V_82 -> V_157 -> V_8 ) ;
V_82 -> V_156 = F_39 ( V_3 , V_70 , V_6 ) ;
if ( ! V_82 -> V_156 )
goto V_54;
F_34 ( V_3 , L_18 , V_123 ,
( unsigned long long ) V_82 -> V_156 -> V_8 ) ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
F_65 ( V_3 , & V_82 -> V_62 [ V_9 ] ) ;
F_31 ( & V_82 -> V_62 [ V_9 ] . V_159 ) ;
F_31 ( & V_82 -> V_62 [ V_9 ] . V_155 ) ;
}
V_82 -> V_62 [ 0 ] . V_31 = F_30 ( V_3 , 2 , 1 , V_160 , 0 , V_6 ) ;
if ( ! V_82 -> V_62 [ 0 ] . V_31 )
goto V_54;
V_82 -> V_61 = F_2 (
sizeof( struct V_30 * ) * V_60 ,
V_6 ) ;
if ( ! V_82 -> V_61 )
goto V_54;
V_82 -> V_59 = 0 ;
V_82 -> V_145 = V_145 ;
V_3 -> V_152 -> V_153 [ V_123 ] = F_10 ( V_82 -> V_157 -> V_8 ) ;
F_34 ( V_3 , L_19 ,
V_123 ,
& V_3 -> V_152 -> V_153 [ V_123 ] ,
F_81 ( V_3 -> V_152 -> V_153 [ V_123 ] ) ) ;
F_82 ( V_82 ) ;
return 1 ;
V_54:
F_73 ( V_3 , V_123 ) ;
return 0 ;
}
void F_83 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_55 * V_56 ;
struct V_77 * V_161 ;
struct V_30 * V_162 ;
V_56 = V_3 -> V_151 [ V_145 -> V_123 ] ;
V_161 = F_45 ( V_3 , V_56 -> V_156 , 0 ) ;
V_162 = V_56 -> V_62 [ 0 ] . V_31 ;
V_161 -> V_120 = F_10 ( F_63 ( V_162 -> V_34 ,
V_162 -> V_48 )
| V_162 -> V_4 ) ;
}
static T_3 F_84 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_134 * V_163 ;
struct V_164 * V_165 ;
if ( V_145 -> V_166 >= V_167 )
V_165 = V_3 -> V_168 ;
else
V_165 = V_3 -> V_169 ;
for ( V_163 = V_145 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
return F_85 ( V_165 , V_163 -> V_171 ) ;
}
int F_86 ( struct V_2 * V_3 , struct V_134 * V_145 )
{
struct V_55 * V_82 ;
struct V_77 * V_161 ;
struct V_76 * V_172 ;
T_3 V_173 ;
T_3 V_174 ;
struct V_134 * V_163 ;
V_82 = V_3 -> V_151 [ V_145 -> V_123 ] ;
if ( V_145 -> V_123 == 0 || ! V_82 ) {
F_76 ( V_3 , L_20 ,
V_145 -> V_123 ) ;
return - V_175 ;
}
V_161 = F_45 ( V_3 , V_82 -> V_156 , 0 ) ;
V_172 = F_44 ( V_3 , V_82 -> V_156 ) ;
V_172 -> V_176 |= F_6 ( F_87 ( 1 ) | V_145 -> V_177 ) ;
switch ( V_145 -> V_166 ) {
case V_178 :
V_172 -> V_176 |= F_6 ( V_179 ) ;
V_174 = F_88 ( 512 ) ;
break;
case V_167 :
V_172 -> V_176 |= F_6 ( V_180 ) ;
V_174 = F_88 ( 512 ) ;
break;
case V_181 :
V_172 -> V_176 |= F_6 ( V_182 ) ;
V_174 = F_88 ( 64 ) ;
break;
case V_183 :
V_172 -> V_176 |= F_6 ( V_184 ) ;
V_174 = F_88 ( 64 ) ;
break;
case V_185 :
V_172 -> V_176 |= F_6 ( V_186 ) ;
V_174 = F_88 ( 8 ) ;
break;
case V_187 :
F_34 ( V_3 , L_21 ) ;
return - V_175 ;
break;
default:
return - V_175 ;
}
V_173 = F_84 ( V_3 , V_145 ) ;
if ( ! V_173 )
return - V_175 ;
V_172 -> V_188 |= F_6 ( F_89 ( V_173 ) ) ;
for ( V_163 = V_145 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
V_82 -> V_189 = V_163 -> V_171 ;
V_82 -> V_129 = V_173 ;
F_34 ( V_3 , L_22 , V_173 ) ;
F_34 ( V_3 , L_23 , V_82 -> V_189 ) ;
if ( ! V_145 -> V_137 || ! V_145 -> V_137 -> V_190 -> V_170 ) {
V_82 -> V_143 = & V_3 -> V_131 [ V_173 - 1 ] . V_143 ;
} else {
struct V_191 * V_131 ;
struct V_126 * V_192 ;
V_131 = & V_3 -> V_131 [ V_173 - 1 ] ;
F_90 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_192 -> V_123 != V_145 -> V_137 -> V_190 -> V_123 )
continue;
if ( ! V_82 -> V_145 -> V_137 -> V_140 ||
( V_145 -> V_137 -> V_140 &&
V_192 -> V_146 == V_82 -> V_145 -> V_146 ) ) {
V_82 -> V_143 = & V_192 -> V_143 ;
V_82 -> V_127 = V_192 ;
break;
}
}
if ( ! V_82 -> V_127 )
F_76 ( V_3 , L_24 ) ;
}
if ( V_145 -> V_137 && V_145 -> V_137 -> V_190 -> V_170 ) {
V_172 -> V_127 = F_6 ( V_145 -> V_137 -> V_190 -> V_123 |
( V_145 -> V_146 << 8 ) ) ;
if ( V_145 -> V_137 -> V_140 )
V_172 -> V_176 |= F_6 ( V_193 ) ;
}
F_34 ( V_3 , L_25 , V_145 -> V_137 ) ;
F_34 ( V_3 , L_26 , V_145 -> V_146 ) ;
V_161 -> V_194 = F_6 ( F_91 ( V_195 ) ) ;
V_161 -> V_194 |= F_6 ( F_92 ( 0 ) | F_93 ( 3 ) |
V_174 ) ;
V_161 -> V_120 = F_10 ( V_82 -> V_62 [ 0 ] . V_31 -> V_44 -> V_8 |
V_82 -> V_62 [ 0 ] . V_31 -> V_4 ) ;
F_94 ( V_82 ) ;
return 0 ;
}
static unsigned int F_95 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
unsigned int V_197 ;
V_197 = F_96 ( V_90 -> V_198 . V_199 , 1 , 16 ) - 1 ;
if ( V_197 != V_90 -> V_198 . V_199 - 1 )
F_97 ( & V_145 -> V_82 ,
L_27 ,
V_90 -> V_198 . V_200 ,
1 << V_197 ,
V_145 -> V_166 == V_183 ? L_4 : L_28 ) ;
if ( V_145 -> V_166 == V_183 ) {
V_197 += 3 ;
}
return V_197 ;
}
static unsigned int F_98 ( struct V_134 * V_145 ,
struct V_196 * V_90 , unsigned int V_201 ,
unsigned int V_202 , unsigned int V_203 )
{
unsigned int V_197 ;
V_197 = F_60 ( V_201 ) - 1 ;
V_197 = F_96 ( V_197 , V_202 , V_203 ) ;
if ( ( 1 << V_197 ) != V_201 )
F_99 ( & V_145 -> V_82 ,
L_29 ,
V_90 -> V_198 . V_200 ,
1 << V_197 ,
V_201 ) ;
return V_197 ;
}
static unsigned int F_100 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
if ( V_90 -> V_198 . V_199 == 0 )
return 0 ;
return F_98 ( V_145 , V_90 ,
V_90 -> V_198 . V_199 , 0 , 15 ) ;
}
static unsigned int F_101 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
return F_98 ( V_145 , V_90 ,
V_90 -> V_198 . V_199 * 8 , 3 , 10 ) ;
}
static unsigned int F_102 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
unsigned int V_197 = 0 ;
switch ( V_145 -> V_166 ) {
case V_181 :
if ( F_103 ( & V_90 -> V_198 ) ||
F_104 ( & V_90 -> V_198 ) ) {
V_197 = F_100 ( V_145 , V_90 ) ;
break;
}
case V_178 :
case V_167 :
if ( F_105 ( & V_90 -> V_198 ) ||
F_106 ( & V_90 -> V_198 ) ) {
V_197 = F_95 ( V_145 , V_90 ) ;
}
break;
case V_183 :
if ( F_106 ( & V_90 -> V_198 ) ) {
V_197 = F_95 ( V_145 , V_90 ) ;
break;
}
case V_185 :
if ( F_105 ( & V_90 -> V_198 ) ||
F_106 ( & V_90 -> V_198 ) ) {
V_197 = F_101 ( V_145 , V_90 ) ;
}
break;
default:
F_107 () ;
}
return V_197 ;
}
static T_3 F_108 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
if ( V_145 -> V_166 < V_167 ||
! F_106 ( & V_90 -> V_198 ) )
return 0 ;
return V_90 -> V_204 . V_205 ;
}
static T_3 F_109 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
if ( V_145 -> V_166 >= V_167 )
return V_90 -> V_204 . V_206 ;
if ( V_145 -> V_166 == V_181 &&
( F_106 ( & V_90 -> V_198 ) ||
F_105 ( & V_90 -> V_198 ) ) )
return F_110 ( & V_90 -> V_198 ) - 1 ;
return 0 ;
}
static T_3 F_111 ( struct V_196 * V_90 )
{
int V_207 ;
V_207 = F_112 ( & V_90 -> V_198 ) ;
switch ( F_113 ( & V_90 -> V_198 ) ) {
case V_208 :
return V_195 ;
case V_209 :
return V_207 ? V_210 : V_211 ;
case V_212 :
return V_207 ? V_213 : V_214 ;
case V_215 :
return V_207 ? V_216 : V_217 ;
}
return 0 ;
}
static T_3 F_114 ( struct V_134 * V_145 ,
struct V_196 * V_90 )
{
int V_218 ;
int V_5 ;
if ( F_103 ( & V_90 -> V_198 ) ||
F_104 ( & V_90 -> V_198 ) )
return 0 ;
if ( ( V_145 -> V_166 >= V_178 ) &&
F_115 ( V_90 -> V_204 . V_205 ) )
return F_11 ( V_90 -> V_219 . V_220 ) ;
else if ( V_145 -> V_166 >= V_167 )
return F_116 ( V_90 -> V_204 . V_221 ) ;
V_5 = F_117 ( & V_90 -> V_198 ) ;
V_218 = F_110 ( & V_90 -> V_198 ) ;
return V_5 * V_218 ;
}
int F_118 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_134 * V_145 ,
struct V_196 * V_90 ,
T_1 V_40 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
struct V_30 * V_162 ;
unsigned int V_5 ;
enum V_20 V_222 ;
T_3 V_223 ;
T_3 V_224 ;
unsigned int V_218 ;
unsigned int V_197 ;
unsigned int V_225 ;
unsigned int V_226 ;
unsigned int V_227 = 0 ;
V_57 = F_119 ( & V_90 -> V_198 ) ;
V_114 = F_45 ( V_3 , V_56 -> V_156 , V_57 ) ;
V_224 = F_111 ( V_90 ) ;
if ( ! V_224 )
return - V_175 ;
V_222 = F_113 ( & V_90 -> V_198 ) ;
V_223 = F_114 ( V_145 , V_90 ) ;
V_197 = F_102 ( V_145 , V_90 ) ;
if ( F_105 ( & V_90 -> V_198 ) ||
F_106 ( & V_90 -> V_198 ) ) {
if ( ( V_3 -> V_27 & V_228 ) &&
V_145 -> V_166 >= V_181 &&
V_197 >= 7 ) {
V_197 = 6 ;
}
}
V_225 = F_108 ( V_145 , V_90 ) ;
V_5 = F_117 ( & V_90 -> V_198 ) ;
V_218 = F_109 ( V_145 , V_90 ) ;
V_226 = V_223 ;
if ( ! F_106 ( & V_90 -> V_198 ) )
V_227 = 3 ;
if ( F_104 ( & V_90 -> V_198 ) && V_145 -> V_166 == V_181 )
V_5 = 512 ;
if ( F_103 ( & V_90 -> V_198 ) && V_3 -> V_229 >= 0x100 )
V_226 = 8 ;
if ( ( V_3 -> V_229 > 0x100 ) && F_120 ( V_3 -> V_230 ) )
V_225 = 0 ;
V_56 -> V_62 [ V_57 ] . V_231 =
F_30 ( V_3 , 2 , 1 , V_222 , V_5 , V_40 ) ;
if ( ! V_56 -> V_62 [ V_57 ] . V_231 ) {
if ( V_56 -> V_59 == 0 )
return - V_51 ;
V_56 -> V_59 -- ;
V_56 -> V_62 [ V_57 ] . V_231 =
V_56 -> V_61 [ V_56 -> V_59 ] ;
V_56 -> V_61 [ V_56 -> V_59 ] = NULL ;
F_35 ( V_3 , V_56 -> V_62 [ V_57 ] . V_231 ,
1 , V_222 ) ;
}
V_56 -> V_62 [ V_57 ] . V_232 = false ;
V_162 = V_56 -> V_62 [ V_57 ] . V_231 ;
V_114 -> V_117 = F_6 ( F_121 ( V_223 ) |
F_122 ( V_197 ) |
F_123 ( V_225 ) ) ;
V_114 -> V_194 = F_6 ( F_91 ( V_224 ) |
F_88 ( V_5 ) |
F_92 ( V_218 ) |
F_93 ( V_227 ) ) ;
V_114 -> V_120 = F_10 ( V_162 -> V_44 -> V_8 |
V_162 -> V_4 ) ;
V_114 -> V_233 = F_6 ( F_124 ( V_223 ) |
F_125 ( V_226 ) ) ;
return 0 ;
}
void F_126 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_196 * V_90 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
V_57 = F_119 ( & V_90 -> V_198 ) ;
V_114 = F_45 ( V_3 , V_56 -> V_156 , V_57 ) ;
V_114 -> V_117 = 0 ;
V_114 -> V_194 = 0 ;
V_114 -> V_120 = 0 ;
V_114 -> V_233 = 0 ;
}
void F_127 ( struct V_234 * V_235 )
{
V_235 -> V_236 = 0 ;
V_235 -> V_225 = 0 ;
V_235 -> V_237 = 0 ;
V_235 -> V_238 = 0 ;
V_235 -> type = 0 ;
V_235 -> V_223 = 0 ;
}
void F_128 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_75 * V_239 ,
struct V_55 * V_56 )
{
struct V_234 * V_235 ;
struct V_77 * V_114 ;
unsigned int V_240 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < 31 ; V_9 ++ ) {
V_235 = & V_56 -> V_62 [ V_9 ] . V_235 ;
if ( ! F_129 ( V_239 , V_9 ) && F_130 ( V_239 , V_9 ) ) {
F_127 ( V_235 ) ;
continue;
}
if ( F_129 ( V_239 , V_9 ) ) {
V_114 = F_45 ( V_3 , V_156 , V_9 ) ;
V_240 = F_131 ( F_11 ( V_114 -> V_194 ) ) ;
if ( V_240 != V_214 && V_240 != V_217 &&
V_240 != V_213 &&
V_240 != V_216 )
continue;
V_235 -> V_236 = F_132 (
F_11 ( V_114 -> V_117 ) ) ;
V_235 -> V_225 = F_133 (
F_11 ( V_114 -> V_117 ) ) + 1 ;
V_235 -> V_237 = F_134 (
F_11 ( V_114 -> V_194 ) ) + 1 ;
V_235 -> V_238 = F_135 (
F_11 ( V_114 -> V_194 ) ) ;
V_235 -> type = V_240 ;
V_235 -> V_223 = F_136 (
F_11 ( V_114 -> V_233 ) ) ;
}
}
}
void F_137 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_67 * V_157 ,
unsigned int V_57 )
{
struct V_77 * V_241 ;
struct V_77 * V_242 ;
V_241 = F_45 ( V_3 , V_157 , V_57 ) ;
V_242 = F_45 ( V_3 , V_156 , V_57 ) ;
V_242 -> V_117 = V_241 -> V_117 ;
V_242 -> V_194 = V_241 -> V_194 ;
V_242 -> V_120 = V_241 -> V_120 ;
V_242 -> V_233 = V_241 -> V_233 ;
}
void F_138 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_67 * V_157 )
{
struct V_76 * V_243 ;
struct V_76 * V_244 ;
V_243 = F_44 ( V_3 , V_156 ) ;
V_244 = F_44 ( V_3 , V_157 ) ;
V_243 -> V_176 = V_244 -> V_176 ;
V_243 -> V_188 = V_244 -> V_188 ;
V_243 -> V_127 = V_244 -> V_127 ;
V_243 -> V_245 = V_244 -> V_245 ;
}
static int F_139 ( struct V_2 * V_3 , T_1 V_6 )
{
int V_9 ;
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
int V_246 = F_140 ( V_3 -> V_247 ) ;
F_38 ( V_3 , V_248 ,
L_30 , V_246 ) ;
if ( ! V_246 )
return 0 ;
V_3 -> V_249 = F_2 ( sizeof( * V_3 -> V_249 ) , V_6 ) ;
if ( ! V_3 -> V_249 )
goto V_250;
V_3 -> V_249 -> V_251 = F_50 ( V_82 ,
V_246 * sizeof( T_5 ) ,
& V_3 -> V_249 -> V_252 , V_6 ) ;
if ( ! V_3 -> V_249 -> V_251 )
goto V_253;
V_3 -> V_249 -> V_254 = F_2 ( sizeof( void * ) * V_246 , V_6 ) ;
if ( ! V_3 -> V_249 -> V_254 )
goto V_255;
V_3 -> V_152 -> V_153 [ 0 ] = F_10 ( V_3 -> V_249 -> V_252 ) ;
for ( V_9 = 0 ; V_9 < V_246 ; V_9 ++ ) {
T_2 V_8 ;
void * V_256 = F_141 ( V_82 , V_3 -> V_257 , & V_8 ,
V_6 ) ;
if ( ! V_256 )
goto V_258;
V_3 -> V_249 -> V_251 [ V_9 ] = V_8 ;
V_3 -> V_249 -> V_254 [ V_9 ] = V_256 ;
}
return 0 ;
V_258:
for ( V_9 = V_9 - 1 ; V_9 >= 0 ; V_9 -- ) {
F_48 ( V_82 , V_3 -> V_257 ,
V_3 -> V_249 -> V_254 [ V_9 ] ,
V_3 -> V_249 -> V_251 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_249 -> V_254 ) ;
V_255:
F_48 ( V_82 , V_246 * sizeof( T_5 ) ,
V_3 -> V_249 -> V_251 ,
V_3 -> V_249 -> V_252 ) ;
V_253:
F_4 ( V_3 -> V_249 ) ;
V_3 -> V_249 = NULL ;
V_250:
return - V_51 ;
}
static void F_142 ( struct V_2 * V_3 )
{
int V_246 ;
int V_9 ;
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
if ( ! V_3 -> V_249 )
return;
V_246 = F_140 ( V_3 -> V_247 ) ;
for ( V_9 = 0 ; V_9 < V_246 ; V_9 ++ ) {
F_48 ( V_82 , V_3 -> V_257 ,
V_3 -> V_249 -> V_254 [ V_9 ] ,
V_3 -> V_249 -> V_251 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_249 -> V_254 ) ;
F_48 ( V_82 , V_246 * sizeof( T_5 ) ,
V_3 -> V_249 -> V_251 ,
V_3 -> V_249 -> V_252 ) ;
F_4 ( V_3 -> V_249 ) ;
V_3 -> V_249 = NULL ;
}
struct V_259 * F_55 ( struct V_2 * V_3 ,
bool V_260 , bool V_261 ,
T_1 V_40 )
{
struct V_259 * V_262 ;
V_262 = F_2 ( sizeof( * V_262 ) , V_40 ) ;
if ( ! V_262 )
return NULL ;
if ( V_260 ) {
V_262 -> V_156 =
F_39 ( V_3 , V_70 ,
V_40 ) ;
if ( ! V_262 -> V_156 ) {
F_4 ( V_262 ) ;
return NULL ;
}
}
if ( V_261 ) {
V_262 -> V_263 =
F_2 ( sizeof( struct V_263 ) , V_40 ) ;
if ( ! V_262 -> V_263 ) {
F_42 ( V_3 , V_262 -> V_156 ) ;
F_4 ( V_262 ) ;
return NULL ;
}
F_143 ( V_262 -> V_263 ) ;
}
V_262 -> V_264 = 0 ;
F_31 ( & V_262 -> V_265 ) ;
return V_262 ;
}
void F_144 ( struct V_266 * V_266 )
{
F_4 ( V_266 ) ;
}
void F_58 ( struct V_2 * V_3 ,
struct V_259 * V_262 )
{
F_42 ( V_3 ,
V_262 -> V_156 ) ;
F_4 ( V_262 -> V_263 ) ;
F_4 ( V_262 ) ;
}
void F_145 ( struct V_2 * V_3 )
{
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
int V_71 ;
int V_9 , V_139 , V_138 ;
F_146 ( & V_3 -> V_267 ) ;
V_71 = sizeof( struct V_268 ) * ( V_3 -> V_269 . V_270 ) ;
if ( V_3 -> V_269 . V_271 )
F_48 ( V_82 , V_71 ,
V_3 -> V_269 . V_271 , V_3 -> V_269 . V_272 ) ;
V_3 -> V_269 . V_271 = NULL ;
F_38 ( V_3 , V_248 , L_31 ) ;
if ( V_3 -> V_273 )
F_26 ( V_3 , V_3 -> V_273 ) ;
V_3 -> V_273 = NULL ;
F_38 ( V_3 , V_248 , L_32 ) ;
if ( V_3 -> V_274 )
F_58 ( V_3 , V_3 -> V_274 ) ;
V_3 -> V_274 = NULL ;
if ( V_3 -> V_275 )
F_26 ( V_3 , V_3 -> V_275 ) ;
V_3 -> V_275 = NULL ;
F_38 ( V_3 , V_248 , L_33 ) ;
F_147 ( V_3 ) ;
V_138 = F_68 ( V_3 -> V_130 ) ;
for ( V_9 = 0 ; V_9 < V_138 && V_3 -> V_131 ; V_9 ++ ) {
struct V_142 * V_276 = & V_3 -> V_131 [ V_9 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ ) {
struct V_124 * V_90 = & V_276 -> V_148 [ V_139 ] . V_149 ;
while ( ! F_75 ( V_90 ) )
F_148 ( V_90 -> V_17 ) ;
}
}
for ( V_9 = F_79 ( V_3 -> V_130 ) ; V_9 > 0 ; V_9 -- )
F_78 ( V_3 , V_9 ) ;
F_149 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
F_38 ( V_3 , V_248 , L_34 ) ;
F_149 ( V_3 -> V_74 ) ;
V_3 -> V_74 = NULL ;
F_38 ( V_3 , V_248 , L_35 ) ;
F_149 ( V_3 -> V_87 ) ;
V_3 -> V_87 = NULL ;
F_38 ( V_3 , V_248 ,
L_36 ) ;
F_149 ( V_3 -> V_88 ) ;
V_3 -> V_88 = NULL ;
F_38 ( V_3 , V_248 ,
L_37 ) ;
if ( V_3 -> V_152 )
F_48 ( V_82 , sizeof( * V_3 -> V_152 ) ,
V_3 -> V_152 , V_3 -> V_152 -> V_8 ) ;
V_3 -> V_152 = NULL ;
F_142 ( V_3 ) ;
if ( ! V_3 -> V_131 )
goto V_277;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
struct V_126 * V_137 , * V_278 ;
F_69 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_70 ( & V_137 -> V_133 ) ;
F_4 ( V_137 ) ;
}
}
V_277:
V_3 -> V_102 = 0 ;
V_3 -> V_279 = 0 ;
V_3 -> V_280 = 0 ;
V_3 -> V_281 = 0 ;
F_4 ( V_3 -> V_282 ) ;
F_4 ( V_3 -> V_283 ) ;
F_4 ( V_3 -> V_284 ) ;
F_4 ( V_3 -> V_131 ) ;
F_4 ( V_3 -> V_285 ) ;
V_3 -> V_282 = NULL ;
V_3 -> V_283 = NULL ;
V_3 -> V_284 = NULL ;
V_3 -> V_131 = NULL ;
V_3 -> V_285 = NULL ;
V_3 -> V_257 = 0 ;
V_3 -> V_286 = 0 ;
V_3 -> V_287 [ 0 ] . V_288 = 0 ;
V_3 -> V_287 [ 1 ] . V_288 = 0 ;
}
static int F_150 ( struct V_2 * V_3 ,
struct V_1 * V_289 ,
union V_63 * V_290 ,
union V_63 * V_291 ,
T_2 V_292 ,
struct V_1 * V_293 ,
char * V_294 , int V_295 )
{
unsigned long long V_296 ;
unsigned long long V_297 ;
struct V_1 * V_7 ;
V_296 = F_63 ( V_289 , V_290 ) ;
V_297 = F_63 ( V_289 , V_291 ) ;
V_7 = F_151 ( V_3 , V_289 , V_290 , V_291 , V_292 , false ) ;
if ( V_7 != V_293 ) {
F_76 ( V_3 , L_38 ,
V_294 , V_295 ) ;
F_76 ( V_3 , L_39
L_40 ,
V_289 ,
( unsigned long long ) V_292 ) ;
F_76 ( V_3 , L_41
L_42 ,
V_290 , V_296 ,
V_291 , V_297 ) ;
F_76 ( V_3 , L_43 ,
V_293 , V_7 ) ;
F_151 ( V_3 , V_289 , V_290 , V_291 , V_292 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_152 ( struct V_2 * V_3 )
{
struct {
T_2 V_292 ;
struct V_1 * V_293 ;
} V_298 [] = {
{ 0 , NULL } ,
{ V_3 -> V_273 -> V_44 -> V_8 - 16 , NULL } ,
{ V_3 -> V_273 -> V_44 -> V_8 - 1 , NULL } ,
{ V_3 -> V_273 -> V_44 -> V_8 , V_3 -> V_273 -> V_44 } ,
{ V_3 -> V_273 -> V_44 -> V_8 + ( V_13 - 1 ) * 16 ,
V_3 -> V_273 -> V_44 } ,
{ V_3 -> V_273 -> V_44 -> V_8 + ( V_13 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_273 -> V_44 -> V_8 + ( V_13 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_289 ;
union V_63 * V_290 ;
union V_63 * V_291 ;
T_2 V_292 ;
struct V_1 * V_293 ;
} V_299 [] = {
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = V_3 -> V_273 -> V_44 -> V_10 ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_292 = V_3 -> V_275 -> V_44 -> V_8 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = V_3 -> V_273 -> V_44 -> V_10 ,
. V_291 = & V_3 -> V_275 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_292 = V_3 -> V_275 -> V_44 -> V_8 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = V_3 -> V_275 -> V_44 -> V_10 ,
. V_291 = & V_3 -> V_275 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_292 = V_3 -> V_275 -> V_44 -> V_8 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = & V_3 -> V_273 -> V_44 -> V_10 [ 0 ] ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ 3 ] ,
. V_292 = V_3 -> V_273 -> V_44 -> V_8 + 4 * 16 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = & V_3 -> V_273 -> V_44 -> V_10 [ 3 ] ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ 6 ] ,
. V_292 = V_3 -> V_273 -> V_44 -> V_8 + 2 * 16 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = & V_3 -> V_273 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ 1 ] ,
. V_292 = V_3 -> V_273 -> V_44 -> V_8 + 2 * 16 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = & V_3 -> V_273 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ 1 ] ,
. V_292 = V_3 -> V_273 -> V_44 -> V_8 + ( V_13 - 4 ) * 16 ,
. V_293 = NULL ,
} ,
{ . V_289 = V_3 -> V_273 -> V_44 ,
. V_290 = & V_3 -> V_273 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_291 = & V_3 -> V_273 -> V_44 -> V_10 [ 1 ] ,
. V_292 = V_3 -> V_275 -> V_44 -> V_8 + 2 * 16 ,
. V_293 = NULL ,
} ,
} ;
unsigned int V_300 ;
int V_9 , V_42 ;
V_300 = F_153 ( V_298 ) ;
for ( V_9 = 0 ; V_9 < V_300 ; V_9 ++ ) {
V_42 = F_150 ( V_3 ,
V_3 -> V_273 -> V_44 ,
V_3 -> V_273 -> V_44 -> V_10 ,
& V_3 -> V_273 -> V_44 -> V_10 [ V_13 - 1 ] ,
V_298 [ V_9 ] . V_292 ,
V_298 [ V_9 ] . V_293 ,
L_44 , V_9 ) ;
if ( V_42 < 0 )
return V_42 ;
}
V_300 = F_153 ( V_299 ) ;
for ( V_9 = 0 ; V_9 < V_300 ; V_9 ++ ) {
V_42 = F_150 ( V_3 ,
V_299 [ V_9 ] . V_289 ,
V_299 [ V_9 ] . V_290 ,
V_299 [ V_9 ] . V_291 ,
V_299 [ V_9 ] . V_292 ,
V_299 [ V_9 ] . V_293 ,
L_45 , V_9 ) ;
if ( V_42 < 0 )
return V_42 ;
}
F_34 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 )
{
T_5 V_301 ;
T_2 V_120 ;
V_120 = F_63 ( V_3 -> V_273 -> V_50 ,
V_3 -> V_273 -> V_49 ) ;
if ( V_120 == 0 && ! F_155 () )
F_76 ( V_3 , L_47
L_48 ) ;
V_301 = F_156 ( V_3 , & V_3 -> V_302 -> V_303 ) ;
V_301 &= V_304 ;
V_301 &= ~ V_305 ;
F_38 ( V_3 , V_248 ,
L_49
L_50 ) ;
F_157 ( V_3 , ( ( T_5 ) V_120 & ( T_5 ) ~ V_304 ) | V_301 ,
& V_3 -> V_302 -> V_303 ) ;
}
static void F_158 ( struct V_2 * V_3 , unsigned int V_138 ,
T_6 T_7 * V_101 , int V_306 )
{
T_3 V_301 , V_307 , V_308 ;
int V_9 ;
T_8 V_309 , V_310 ;
struct V_311 * V_312 ;
V_301 = F_159 ( V_101 ) ;
V_309 = F_160 ( V_301 ) ;
V_310 = F_161 ( V_301 ) ;
if ( V_309 == 0x03 ) {
V_312 = & V_3 -> V_313 ;
} else if ( V_309 <= 0x02 ) {
V_312 = & V_3 -> V_314 ;
} else {
F_76 ( V_3 , L_51
L_52 ,
V_101 , V_309 ) ;
return;
}
V_312 -> V_315 = F_160 ( V_301 ) ;
if ( V_312 -> V_316 < V_310 )
V_312 -> V_316 = V_310 ;
V_301 = F_159 ( V_101 + 2 ) ;
V_307 = F_162 ( V_301 ) ;
V_308 = F_163 ( V_301 ) ;
F_38 ( V_3 , V_248 ,
L_53
L_54 ,
V_101 , V_307 , V_308 , V_309 ) ;
if ( V_307 == 0 || ( V_307 + V_308 - 1 ) > V_138 )
return;
V_312 -> V_317 = F_164 ( V_301 ) ;
if ( V_312 -> V_317 ) {
V_312 -> V_318 = F_165 ( V_312 -> V_317 , sizeof( * V_312 -> V_318 ) ,
V_319 ) ;
if ( ! V_312 -> V_318 )
V_312 -> V_317 = 0 ;
V_312 -> V_320 ++ ;
for ( V_9 = 0 ; V_9 < V_312 -> V_317 ; V_9 ++ ) {
V_312 -> V_318 [ V_9 ] = F_159 ( V_101 + 4 + V_9 ) ;
if ( V_9 && ( F_166 ( V_312 -> V_318 [ V_9 ] ) !=
F_166 ( V_312 -> V_318 [ V_9 - 1 ] ) ) )
V_312 -> V_320 ++ ;
F_34 ( V_3 , L_55 ,
F_166 ( V_312 -> V_318 [ V_9 ] ) ,
F_167 ( V_312 -> V_318 [ V_9 ] ) ,
F_168 ( V_312 -> V_318 [ V_9 ] ) ,
F_169 ( V_312 -> V_318 [ V_9 ] ) ,
F_170 ( V_312 -> V_318 [ V_9 ] ) ,
F_171 ( V_312 -> V_318 [ V_9 ] ) ) ;
}
}
if ( V_309 < 0x03 && V_3 -> V_321 < V_306 )
V_3 -> V_285 [ V_3 -> V_321 ++ ] = V_301 ;
if ( ( V_3 -> V_229 == 0x96 ) && ( V_309 != 0x03 ) &&
( V_301 & V_322 ) ) {
F_38 ( V_3 , V_248 ,
L_56 ) ;
V_3 -> V_323 = 1 ;
}
if ( ( V_3 -> V_229 >= 0x100 ) && ( V_309 != 0x03 ) ) {
F_38 ( V_3 , V_248 ,
L_57 ) ;
V_3 -> V_323 = 1 ;
if ( V_301 & V_324 ) {
F_38 ( V_3 , V_248 ,
L_58 ) ;
V_3 -> V_325 = 1 ;
}
}
V_307 -- ;
for ( V_9 = V_307 ; V_9 < ( V_307 + V_308 ) ; V_9 ++ ) {
if ( V_3 -> V_284 [ V_9 ] != 0 ) {
F_76 ( V_3 , L_59
L_60 , V_101 , V_9 ) ;
F_76 ( V_3 , L_61
L_62 ,
V_3 -> V_284 [ V_9 ] , V_309 ) ;
if ( V_3 -> V_284 [ V_9 ] != V_309 &&
V_3 -> V_284 [ V_9 ] != V_326 ) {
if ( V_3 -> V_284 [ V_9 ] == 0x03 )
V_3 -> V_280 -- ;
else
V_3 -> V_279 -- ;
V_3 -> V_284 [ V_9 ] = V_326 ;
}
continue;
}
V_3 -> V_284 [ V_9 ] = V_309 ;
if ( V_309 == 0x03 )
V_3 -> V_280 ++ ;
else
V_3 -> V_279 ++ ;
}
}
static int F_172 ( struct V_2 * V_3 , T_1 V_6 )
{
void T_7 * V_327 ;
T_3 V_328 ;
unsigned int V_138 ;
int V_9 , V_139 , V_329 ;
int V_330 = 0 ;
T_3 V_331 ;
V_138 = F_68 ( V_3 -> V_130 ) ;
V_3 -> V_284 = F_2 ( sizeof( * V_3 -> V_284 ) * V_138 , V_6 ) ;
if ( ! V_3 -> V_284 )
return - V_51 ;
V_3 -> V_131 = F_2 ( sizeof( * V_3 -> V_131 ) * V_138 , V_6 ) ;
if ( ! V_3 -> V_131 )
return - V_51 ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
struct V_142 * V_143 ;
F_31 ( & V_3 -> V_131 [ V_9 ] . V_132 ) ;
V_143 = & V_3 -> V_131 [ V_9 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_31 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
V_327 = & V_3 -> V_332 -> V_333 ;
V_331 = F_173 ( V_327 , 0 , V_334 ) ;
if ( ! V_331 ) {
F_174 ( V_3 , L_63 ) ;
return - V_335 ;
}
V_328 = V_331 ;
while ( V_328 ) {
V_330 ++ ;
V_328 = F_173 ( V_327 , V_328 ,
V_334 ) ;
}
V_3 -> V_285 = F_2 ( sizeof( * V_3 -> V_285 ) * V_330 , V_6 ) ;
if ( ! V_3 -> V_285 )
return - V_51 ;
V_328 = V_331 ;
while ( V_328 ) {
F_158 ( V_3 , V_138 , V_327 + V_328 , V_330 ) ;
if ( V_3 -> V_279 + V_3 -> V_280 == V_138 )
break;
V_328 = F_173 ( V_327 , V_328 ,
V_334 ) ;
}
if ( V_3 -> V_279 == 0 && V_3 -> V_280 == 0 ) {
F_76 ( V_3 , L_64 ) ;
return - V_335 ;
}
F_38 ( V_3 , V_248 ,
L_65 ,
V_3 -> V_279 , V_3 -> V_280 ) ;
if ( V_3 -> V_280 > V_336 ) {
F_38 ( V_3 , V_248 ,
L_66 ,
V_336 ) ;
V_3 -> V_280 = V_336 ;
}
if ( V_3 -> V_279 > V_337 ) {
F_38 ( V_3 , V_248 ,
L_67 ,
V_337 ) ;
V_3 -> V_279 = V_337 ;
}
if ( V_3 -> V_279 ) {
V_3 -> V_282 = F_175 ( sizeof( * V_3 -> V_282 ) *
V_3 -> V_279 , V_6 ) ;
if ( ! V_3 -> V_282 )
return - V_51 ;
V_329 = 0 ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
if ( V_3 -> V_284 [ V_9 ] == 0x03 ||
V_3 -> V_284 [ V_9 ] == 0 ||
V_3 -> V_284 [ V_9 ] == V_326 )
continue;
V_3 -> V_282 [ V_329 ] =
& V_3 -> V_338 -> V_339 +
V_340 * V_9 ;
F_38 ( V_3 , V_248 ,
L_68
L_69 , V_9 ,
V_3 -> V_282 [ V_329 ] ) ;
V_329 ++ ;
if ( V_329 == V_3 -> V_279 )
break;
}
}
if ( V_3 -> V_280 ) {
V_3 -> V_283 = F_175 ( sizeof( * V_3 -> V_283 ) *
V_3 -> V_280 , V_6 ) ;
if ( ! V_3 -> V_283 )
return - V_51 ;
V_329 = 0 ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ )
if ( V_3 -> V_284 [ V_9 ] == 0x03 ) {
V_3 -> V_283 [ V_329 ] =
& V_3 -> V_338 -> V_339 +
V_340 * V_9 ;
F_38 ( V_3 , V_248 ,
L_70
L_69 , V_9 ,
V_3 -> V_283 [ V_329 ] ) ;
V_329 ++ ;
if ( V_329 == V_3 -> V_280 )
break;
}
}
return 0 ;
}
int F_176 ( struct V_2 * V_3 , T_1 V_6 )
{
T_2 V_8 ;
struct V_81 * V_82 = F_47 ( V_3 ) -> V_83 . V_84 ;
unsigned int V_21 , V_341 ;
T_5 V_342 ;
struct V_1 * V_7 ;
T_3 V_257 , V_301 ;
int V_9 ;
F_31 ( & V_3 -> V_265 ) ;
F_177 ( & V_3 -> V_267 , V_343 ) ;
F_143 ( & V_3 -> V_344 ) ;
V_257 = F_159 ( & V_3 -> V_338 -> V_257 ) ;
F_38 ( V_3 , V_248 ,
L_71 , V_257 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
if ( ( 0x1 & V_257 ) != 0 )
break;
V_257 = V_257 >> 1 ;
}
if ( V_9 < 16 )
F_38 ( V_3 , V_248 ,
L_72 , ( 1 << ( V_9 + 12 ) ) / 1024 ) ;
else
F_76 ( V_3 , L_73 ) ;
V_3 -> V_286 = 12 ;
V_3 -> V_257 = 1 << V_3 -> V_286 ;
F_38 ( V_3 , V_248 ,
L_74 , V_3 -> V_257 / 1024 ) ;
V_21 = F_79 ( F_159 ( & V_3 -> V_332 -> V_130 ) ) ;
F_38 ( V_3 , V_248 ,
L_75 , V_21 ) ;
V_341 = F_159 ( & V_3 -> V_338 -> V_345 ) ;
V_21 |= ( V_341 & ~ V_346 ) ;
F_38 ( V_3 , V_248 ,
L_76 , V_21 ) ;
F_178 ( V_21 , & V_3 -> V_338 -> V_345 ) ;
V_3 -> V_152 = F_50 ( V_82 , sizeof( * V_3 -> V_152 ) , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_152 )
goto V_54;
memset ( V_3 -> V_152 , 0 , sizeof *( V_3 -> V_152 ) ) ;
V_3 -> V_152 -> V_8 = V_8 ;
F_38 ( V_3 , V_248 ,
L_77 ,
( unsigned long long ) V_3 -> V_152 -> V_8 , V_3 -> V_152 ) ;
F_157 ( V_3 , V_8 , & V_3 -> V_338 -> V_347 ) ;
V_3 -> V_11 = F_179 ( L_78 , V_82 ,
V_348 , V_348 , V_3 -> V_257 ) ;
V_3 -> V_74 = F_179 ( L_79 , V_82 ,
2112 , 64 , V_3 -> V_257 ) ;
if ( ! V_3 -> V_11 || ! V_3 -> V_74 )
goto V_54;
V_3 -> V_87 =
F_179 ( L_80 ,
V_82 , V_86 , 16 , 0 ) ;
V_3 -> V_88 =
F_179 ( L_81 ,
V_82 , V_85 , 16 , 0 ) ;
if ( ! V_3 -> V_87 || ! V_3 -> V_88 )
goto V_54;
V_3 -> V_275 = F_30 ( V_3 , 1 , 1 , V_349 , 0 , V_6 ) ;
if ( ! V_3 -> V_275 )
goto V_54;
F_38 ( V_3 , V_248 ,
L_82 , V_3 -> V_275 ) ;
F_38 ( V_3 , V_248 , L_83 ,
( unsigned long long ) V_3 -> V_275 -> V_44 -> V_8 ) ;
V_342 = F_156 ( V_3 , & V_3 -> V_338 -> V_275 ) ;
V_342 = ( V_342 & ( T_5 ) V_350 ) |
( V_3 -> V_275 -> V_44 -> V_8 & ( T_5 ) ~ V_350 ) |
V_3 -> V_275 -> V_4 ;
F_38 ( V_3 , V_248 ,
L_84 , V_342 ) ;
F_157 ( V_3 , V_342 , & V_3 -> V_338 -> V_275 ) ;
F_180 ( V_3 ) ;
V_3 -> V_274 = F_55 ( V_3 , true , true , V_6 ) ;
if ( ! V_3 -> V_274 )
goto V_54;
V_3 -> V_102 ++ ;
V_21 = F_159 ( & V_3 -> V_332 -> V_351 ) ;
V_21 &= V_352 ;
F_38 ( V_3 , V_248 ,
L_85
L_86 , V_21 ) ;
V_3 -> V_353 = ( void T_7 * ) V_3 -> V_332 + V_21 ;
F_181 ( V_3 ) ;
F_182 ( V_3 ) ;
V_3 -> V_302 = & V_3 -> V_354 -> V_302 [ 0 ] ;
F_38 ( V_3 , V_248 , L_87 ) ;
V_3 -> V_273 = F_30 ( V_3 , V_355 , 1 , V_22 ,
0 , V_6 ) ;
if ( ! V_3 -> V_273 )
goto V_54;
if ( F_152 ( V_3 ) < 0 )
goto V_54;
V_3 -> V_269 . V_271 = F_50 ( V_82 ,
sizeof( struct V_268 ) * V_355 , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_269 . V_271 )
goto V_54;
F_38 ( V_3 , V_248 ,
L_88 ,
( unsigned long long ) V_8 ) ;
memset ( V_3 -> V_269 . V_271 , 0 , sizeof( struct V_268 ) * V_355 ) ;
V_3 -> V_269 . V_270 = V_355 ;
V_3 -> V_269 . V_272 = V_8 ;
F_38 ( V_3 , V_248 ,
L_89 ,
V_3 -> V_269 . V_270 ,
V_3 -> V_269 . V_271 ,
( unsigned long long ) V_3 -> V_269 . V_272 ) ;
for ( V_21 = 0 , V_7 = V_3 -> V_273 -> V_44 ; V_21 < V_355 ; V_21 ++ ) {
struct V_268 * V_356 = & V_3 -> V_269 . V_271 [ V_21 ] ;
V_356 -> V_357 = F_10 ( V_7 -> V_8 ) ;
V_356 -> V_358 = F_6 ( V_13 ) ;
V_356 -> V_359 = 0 ;
V_7 = V_7 -> V_17 ;
}
V_21 = F_159 ( & V_3 -> V_302 -> V_360 ) ;
V_21 &= V_361 ;
V_21 |= V_355 ;
F_38 ( V_3 , V_248 ,
L_90 ,
V_21 ) ;
F_178 ( V_21 , & V_3 -> V_302 -> V_360 ) ;
F_38 ( V_3 , V_248 ,
L_91 ) ;
F_38 ( V_3 , V_248 ,
L_92 ,
( unsigned long long ) V_3 -> V_269 . V_272 ) ;
V_342 = F_156 ( V_3 , & V_3 -> V_302 -> V_362 ) ;
V_342 &= V_304 ;
V_342 |= ( V_3 -> V_269 . V_272 & ( T_5 ) ~ V_304 ) ;
F_157 ( V_3 , V_342 , & V_3 -> V_302 -> V_362 ) ;
F_154 ( V_3 ) ;
F_38 ( V_3 , V_248 ,
L_93 ) ;
F_183 ( V_3 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_363 ; V_9 ++ )
V_3 -> V_151 [ V_9 ] = NULL ;
for ( V_9 = 0 ; V_9 < V_337 ; V_9 ++ ) {
V_3 -> V_287 [ 0 ] . V_364 [ V_9 ] = 0 ;
V_3 -> V_287 [ 1 ] . V_364 [ V_9 ] = 0 ;
F_143 ( & V_3 -> V_287 [ 1 ] . V_365 [ V_9 ] ) ;
}
if ( F_139 ( V_3 , V_6 ) )
goto V_54;
if ( F_172 ( V_3 , V_6 ) )
goto V_54;
V_301 = F_159 ( & V_3 -> V_338 -> V_366 ) ;
V_301 &= ~ V_367 ;
V_301 |= V_368 ;
F_178 ( V_301 , & V_3 -> V_338 -> V_366 ) ;
return 0 ;
V_54:
F_184 ( V_3 ) ;
F_185 ( V_3 ) ;
F_145 ( V_3 ) ;
return - V_51 ;
}
