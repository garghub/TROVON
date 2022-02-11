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
static int F_15 ( struct V_37 * V_38 ,
struct V_29 * V_30 ,
struct V_1 * V_6 ,
T_1 V_39 )
{
unsigned long V_40 ;
int V_41 ;
V_40 = ( unsigned long ) ( V_6 -> V_7 >> V_42 ) ;
if ( F_16 ( V_38 , V_40 ) )
return 0 ;
V_41 = F_17 ( V_39 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_18 ( V_38 ,
V_40 , V_30 ) ;
F_19 () ;
return V_41 ;
}
static void F_20 ( struct V_37 * V_38 ,
struct V_1 * V_6 )
{
unsigned long V_40 ;
V_40 = ( unsigned long ) ( V_6 -> V_7 >> V_42 ) ;
if ( F_16 ( V_38 , V_40 ) )
F_21 ( V_38 , V_40 ) ;
}
static int F_22 (
struct V_37 * V_38 ,
struct V_29 * V_30 ,
struct V_1 * V_43 ,
struct V_1 * V_35 ,
T_1 V_39 )
{
struct V_1 * V_6 ;
struct V_1 * V_44 ;
int V_41 ;
if ( F_23 ( V_38 == NULL ) )
return 0 ;
V_6 = V_43 ;
do {
V_41 = F_15 ( V_38 ,
V_30 , V_6 , V_39 ) ;
if ( V_41 )
goto V_45;
if ( V_6 == V_35 )
return 0 ;
V_6 = V_6 -> V_16 ;
} while ( V_6 != V_43 );
return 0 ;
V_45:
V_44 = V_6 ;
V_6 = V_43 ;
do {
F_20 ( V_38 , V_6 ) ;
if ( V_6 == V_44 )
return V_41 ;
V_6 = V_6 -> V_16 ;
} while ( V_6 != V_43 );
return V_41 ;
}
static void F_24 ( struct V_29 * V_30 )
{
struct V_1 * V_6 ;
if ( F_23 ( V_30 -> V_38 == NULL ) )
return;
V_6 = V_30 -> V_43 ;
do {
F_20 ( V_30 -> V_38 , V_6 ) ;
V_6 = V_6 -> V_16 ;
} while ( V_6 != V_30 -> V_43 );
}
static int F_25 ( struct V_29 * V_30 , T_1 V_39 )
{
return F_22 ( V_30 -> V_38 , V_30 ,
V_30 -> V_43 , V_30 -> V_35 , V_39 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
if ( ! V_30 )
return;
if ( V_30 -> V_43 ) {
if ( V_30 -> type == V_46 )
F_24 ( V_30 ) ;
F_8 ( V_3 , V_30 -> V_43 ) ;
}
F_4 ( V_30 ) ;
}
static void F_27 ( struct V_29 * V_30 ,
unsigned int V_4 )
{
V_30 -> V_47 = V_30 -> V_43 -> V_9 ;
V_30 -> V_33 = V_30 -> V_43 ;
V_30 -> V_48 = V_30 -> V_47 ;
V_30 -> V_49 = V_30 -> V_43 ;
V_30 -> V_4 = V_4 ;
V_30 -> V_50 = 0 ;
V_30 -> V_51 = 0 ;
V_30 -> V_34 = V_30 -> V_32 * ( V_12 - 1 ) - 1 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * * V_17 , struct V_1 * * V_31 ,
unsigned int V_32 , unsigned int V_4 ,
enum V_19 type , T_1 V_5 )
{
struct V_1 * V_18 ;
V_18 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_18 )
return - V_52 ;
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
return - V_52 ;
}
F_9 ( V_3 , V_18 , V_16 , type ) ;
V_18 = V_16 ;
V_32 -- ;
}
F_9 ( V_3 , V_18 , * V_17 , type ) ;
* V_31 = V_18 ;
return 0 ;
}
static struct V_29 * F_29 ( struct V_2 * V_3 ,
unsigned int V_32 , unsigned int V_4 ,
enum V_19 type , T_1 V_5 )
{
struct V_29 * V_30 ;
int V_41 ;
V_30 = F_2 ( sizeof *( V_30 ) , V_5 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_32 = V_32 ;
F_30 ( & V_30 -> V_53 ) ;
V_30 -> type = type ;
if ( V_32 == 0 )
return V_30 ;
V_41 = F_28 ( V_3 , & V_30 -> V_43 ,
& V_30 -> V_35 , V_32 , V_4 , type , V_5 ) ;
if ( V_41 )
goto V_54;
if ( type != V_21 ) {
V_30 -> V_35 -> V_9 [ V_12 - 1 ] . V_13 . V_14 |=
F_5 ( V_36 ) ;
}
F_27 ( V_30 , V_4 ) ;
return V_30 ;
V_54:
F_4 ( V_30 ) ;
return NULL ;
}
void F_31 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
unsigned int V_57 )
{
int V_58 ;
V_58 = V_56 -> V_59 ;
if ( V_58 < V_60 ) {
V_56 -> V_61 [ V_58 ] =
V_56 -> V_62 [ V_57 ] . V_30 ;
V_56 -> V_59 ++ ;
F_32 ( V_3 , L_1
L_2 ,
V_56 -> V_59 ,
( V_56 -> V_59 > 1 ) ? L_3 : L_4 ) ;
} else {
F_26 ( V_3 , V_56 -> V_62 [ V_57 ] . V_30 ) ;
F_32 ( V_3 , L_5
L_6 ,
V_56 -> V_59 ) ;
}
V_56 -> V_62 [ V_57 ] . V_30 = NULL ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned int V_4 ,
enum V_19 type )
{
struct V_1 * V_6 = V_30 -> V_43 ;
int V_8 ;
do {
memset ( V_6 -> V_9 , 0 ,
sizeof( union V_63 ) * V_12 ) ;
if ( V_4 == 0 ) {
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ )
V_6 -> V_9 [ V_8 ] . V_13 . V_14 |=
F_5 ( V_15 ) ;
}
F_9 ( V_3 , V_6 , V_6 -> V_16 , type ) ;
V_6 = V_6 -> V_16 ;
} while ( V_6 != V_30 -> V_43 );
V_30 -> type = type ;
F_27 ( V_30 , V_4 ) ;
F_30 ( & V_30 -> V_53 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_29 * V_30 ,
unsigned int V_64 , T_1 V_5 )
{
struct V_1 * V_17 ;
struct V_1 * V_31 ;
unsigned int V_32 ;
unsigned int V_65 ;
int V_41 ;
V_65 = ( V_64 + ( V_12 - 1 ) - 1 ) /
( V_12 - 1 ) ;
V_32 = V_30 -> V_32 > V_65 ?
V_30 -> V_32 : V_65 ;
V_41 = F_28 ( V_3 , & V_17 , & V_31 ,
V_32 , V_30 -> V_4 , V_30 -> type , V_5 ) ;
if ( V_41 )
return - V_52 ;
if ( V_30 -> type == V_46 )
V_41 = F_22 ( V_30 -> V_38 ,
V_30 , V_17 , V_31 , V_5 ) ;
if ( V_41 ) {
struct V_1 * V_16 ;
do {
V_16 = V_17 -> V_16 ;
F_6 ( V_3 , V_17 ) ;
if ( V_17 == V_31 )
break;
V_17 = V_16 ;
} while ( true );
return V_41 ;
}
F_14 ( V_3 , V_30 , V_17 , V_31 , V_32 ) ;
F_35 ( V_3 , V_66 ,
L_7 ,
V_30 -> V_32 ) ;
return 0 ;
}
static struct V_67 * F_36 ( struct V_2 * V_3 ,
int type , T_1 V_5 )
{
struct V_67 * V_68 ;
if ( ( type != V_69 ) && ( type != V_70 ) )
return NULL ;
V_68 = F_2 ( sizeof( * V_68 ) , V_5 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> type = type ;
V_68 -> V_71 = F_37 ( V_3 -> V_72 ) ? 2048 : 1024 ;
if ( type == V_70 )
V_68 -> V_71 += F_38 ( V_3 -> V_72 ) ;
V_68 -> V_73 = F_3 ( V_3 -> V_74 , V_5 , & V_68 -> V_7 ) ;
if ( ! V_68 -> V_73 ) {
F_4 ( V_68 ) ;
return NULL ;
}
memset ( V_68 -> V_73 , 0 , V_68 -> V_71 ) ;
return V_68 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
if ( ! V_68 )
return;
F_7 ( V_3 -> V_74 , V_68 -> V_73 , V_68 -> V_7 ) ;
F_4 ( V_68 ) ;
}
struct V_75 * F_40 (
struct V_67 * V_68 )
{
if ( V_68 -> type != V_70 )
return NULL ;
return (struct V_75 * ) V_68 -> V_73 ;
}
struct V_76 * F_41 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
if ( V_68 -> type == V_69 )
return (struct V_76 * ) V_68 -> V_73 ;
return (struct V_76 * )
( V_68 -> V_73 + F_38 ( V_3 -> V_72 ) ) ;
}
struct V_77 * F_42 ( struct V_2 * V_3 ,
struct V_67 * V_68 ,
unsigned int V_57 )
{
V_57 ++ ;
if ( V_68 -> type == V_70 )
V_57 ++ ;
return (struct V_77 * )
( V_68 -> V_73 + ( V_57 * F_38 ( V_3 -> V_72 ) ) ) ;
}
static void F_43 ( struct V_2 * V_3 ,
unsigned int V_78 ,
struct V_79 * V_80 , T_2 V_7 )
{
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
T_4 V_71 = sizeof( struct V_79 ) * V_78 ;
if ( V_71 > V_85 )
F_45 ( V_82 , V_71 ,
V_80 , V_7 ) ;
else if ( V_71 <= V_86 )
return F_7 ( V_3 -> V_87 ,
V_80 , V_7 ) ;
else
return F_7 ( V_3 -> V_88 ,
V_80 , V_7 ) ;
}
static struct V_79 * F_46 ( struct V_2 * V_3 ,
unsigned int V_78 , T_2 * V_7 ,
T_1 V_39 )
{
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
T_4 V_71 = sizeof( struct V_79 ) * V_78 ;
if ( V_71 > V_85 )
return F_47 ( V_82 , V_71 ,
V_7 , V_39 ) ;
else if ( V_71 <= V_86 )
return F_3 ( V_3 -> V_87 ,
V_39 , V_7 ) ;
else
return F_3 ( V_3 -> V_88 ,
V_39 , V_7 ) ;
}
struct V_29 * F_48 (
struct V_89 * V_90 ,
T_5 V_91 )
{
if ( V_90 -> V_92 & V_93 )
return F_16 ( & V_90 -> V_94 -> V_38 ,
V_91 >> V_42 ) ;
return V_90 -> V_30 ;
}
struct V_29 * F_49 (
struct V_55 * V_82 ,
unsigned int V_57 ,
unsigned int V_95 )
{
struct V_89 * V_90 = & V_82 -> V_62 [ V_57 ] ;
if ( V_95 == 0 )
return V_90 -> V_30 ;
if ( ! V_90 -> V_94 )
return NULL ;
if ( V_95 > V_90 -> V_94 -> V_96 )
return NULL ;
return V_90 -> V_94 -> V_97 [ V_95 ] ;
}
struct V_98 * F_50 ( struct V_2 * V_3 ,
unsigned int V_78 ,
unsigned int V_96 , T_1 V_39 )
{
struct V_98 * V_94 ;
T_3 V_99 ;
struct V_29 * V_100 ;
T_5 V_101 ;
int V_41 ;
F_32 ( V_3 , L_8
L_9 ,
V_96 , V_78 ) ;
if ( V_3 -> V_102 == V_103 ) {
F_32 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_102 ++ ;
V_94 = F_2 ( sizeof( struct V_98 ) , V_39 ) ;
if ( ! V_94 )
goto V_104;
V_94 -> V_96 = V_96 ;
V_94 -> V_78 = V_78 ;
V_94 -> V_97 = F_2 (
sizeof( struct V_29 * ) * V_96 ,
V_39 ) ;
if ( ! V_94 -> V_97 )
goto V_105;
V_94 -> V_106 = F_46 ( V_3 ,
V_78 , & V_94 -> V_107 ,
V_39 ) ;
if ( ! V_94 -> V_106 )
goto V_108;
memset ( V_94 -> V_106 , 0 ,
sizeof( struct V_79 ) * V_78 ) ;
V_94 -> V_109 =
F_51 ( V_3 , true , true , V_39 ) ;
if ( ! V_94 -> V_109 )
goto V_108;
F_52 ( & V_94 -> V_38 , V_110 ) ;
for ( V_99 = 1 ; V_99 < V_96 ; V_99 ++ ) {
V_94 -> V_97 [ V_99 ] =
F_29 ( V_3 , 2 , 1 , V_46 , V_39 ) ;
V_100 = V_94 -> V_97 [ V_99 ] ;
if ( ! V_100 )
goto V_111;
V_100 -> V_95 = V_99 ;
V_100 -> V_38 = & V_94 -> V_38 ;
V_101 = V_100 -> V_43 -> V_7 |
F_53 ( V_112 ) |
V_100 -> V_4 ;
V_94 -> V_106 [ V_99 ] . V_113 =
F_10 ( V_101 ) ;
F_32 ( V_3 , L_11 ,
V_99 , ( unsigned long long ) V_101 ) ;
V_41 = F_25 ( V_100 , V_39 ) ;
if ( V_41 ) {
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
F_54 ( V_3 , V_94 -> V_109 ) ;
V_108:
F_4 ( V_94 -> V_97 ) ;
V_105:
F_4 ( V_94 ) ;
V_104:
V_3 -> V_102 -- ;
return NULL ;
}
void F_55 ( struct V_2 * V_3 ,
struct V_77 * V_114 ,
struct V_98 * V_94 )
{
T_3 V_115 ;
V_115 = F_56 ( V_94 -> V_78 ) - 2 ;
F_35 ( V_3 , V_116 ,
L_12 ,
1 << ( V_115 + 1 ) ) ;
V_114 -> V_117 &= F_5 ( ~ V_118 ) ;
V_114 -> V_117 |= F_5 ( F_57 ( V_115 )
| V_119 ) ;
V_114 -> V_120 = F_10 ( V_94 -> V_107 ) ;
}
void F_58 ( struct V_77 * V_114 ,
struct V_89 * V_90 )
{
T_2 V_101 ;
V_114 -> V_117 &= F_5 ( ~ ( V_118 | V_119 ) ) ;
V_101 = F_59 ( V_90 -> V_30 -> V_49 , V_90 -> V_30 -> V_48 ) ;
V_114 -> V_120 = F_10 ( V_101 | V_90 -> V_30 -> V_4 ) ;
}
void F_60 ( struct V_2 * V_3 ,
struct V_98 * V_94 )
{
int V_99 ;
struct V_29 * V_100 ;
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
F_54 ( V_3 , V_94 -> V_109 ) ;
V_3 -> V_102 -- ;
if ( V_94 -> V_106 )
F_43 ( V_3 ,
V_94 -> V_78 ,
V_94 -> V_106 ,
V_94 -> V_107 ) ;
F_4 ( V_94 -> V_97 ) ;
F_4 ( V_94 ) ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
F_62 ( & V_90 -> V_121 , V_122 ,
( unsigned long ) V_90 ) ;
V_90 -> V_3 = V_3 ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
int V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 , * V_16 ;
bool V_128 = false ;
if ( V_56 -> V_129 == 0 ||
V_56 -> V_129 > F_64 ( V_3 -> V_130 ) ) {
F_32 ( V_3 , L_13 ) ;
return;
}
V_125 = & ( V_3 -> V_131 [ V_56 -> V_129 - 1 ] . V_132 ) ;
F_65 (tt_info, next, tt_list_head, tt_list) {
if ( V_127 -> V_123 == V_123 ) {
V_128 = true ;
F_66 ( & V_127 -> V_133 ) ;
F_4 ( V_127 ) ;
} else if ( V_128 ) {
break;
}
}
}
int F_67 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_134 * V_135 ,
struct V_136 * V_137 , T_1 V_39 )
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
V_127 = F_2 ( sizeof( * V_127 ) , V_39 ) ;
if ( ! V_127 )
goto V_144;
F_30 ( & V_127 -> V_133 ) ;
F_68 ( & V_127 -> V_133 ,
& V_3 -> V_131 [ V_56 -> V_129 - 1 ] . V_132 ) ;
V_127 -> V_123 = V_56 -> V_145 -> V_123 ;
if ( V_137 -> V_140 )
V_127 -> V_146 = V_8 + 1 ;
V_143 = & V_127 -> V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_30 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
return 0 ;
V_144:
F_63 ( V_3 , V_56 , V_56 -> V_145 -> V_123 ) ;
return - V_52 ;
}
void F_69 ( struct V_2 * V_3 , int V_123 )
{
struct V_55 * V_82 ;
int V_8 ;
int V_150 = 0 ;
if ( V_123 == 0 || ! V_3 -> V_151 [ V_123 ] )
return;
V_82 = V_3 -> V_151 [ V_123 ] ;
V_3 -> V_152 -> V_153 [ V_123 ] = 0 ;
if ( ! V_82 )
return;
if ( V_82 -> V_127 )
V_150 = V_82 -> V_127 -> V_154 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_82 -> V_62 [ V_8 ] . V_30 )
F_26 ( V_3 , V_82 -> V_62 [ V_8 ] . V_30 ) ;
if ( V_82 -> V_62 [ V_8 ] . V_94 )
F_60 ( V_3 ,
V_82 -> V_62 [ V_8 ] . V_94 ) ;
if ( ! F_70 ( & V_82 -> V_62 [ V_8 ] . V_155 ) )
F_71 ( V_3 , L_14
L_15 ,
V_123 , V_8 ) ;
}
F_63 ( V_3 , V_82 , V_123 ) ;
F_72 ( V_3 , V_82 , V_150 ) ;
if ( V_82 -> V_61 ) {
for ( V_8 = 0 ; V_8 < V_82 -> V_59 ; V_8 ++ )
F_26 ( V_3 , V_82 -> V_61 [ V_8 ] ) ;
F_4 ( V_82 -> V_61 ) ;
}
if ( V_82 -> V_156 )
F_39 ( V_3 , V_82 -> V_156 ) ;
if ( V_82 -> V_157 )
F_39 ( V_3 , V_82 -> V_157 ) ;
F_4 ( V_3 -> V_151 [ V_123 ] ) ;
V_3 -> V_151 [ V_123 ] = NULL ;
}
int F_73 ( struct V_2 * V_3 , int V_123 ,
struct V_134 * V_145 , T_1 V_5 )
{
struct V_55 * V_82 ;
int V_8 ;
if ( V_123 == 0 || V_3 -> V_151 [ V_123 ] ) {
F_71 ( V_3 , L_16 , V_123 ) ;
return 0 ;
}
V_3 -> V_151 [ V_123 ] = F_2 ( sizeof( * V_3 -> V_151 [ V_123 ] ) , V_5 ) ;
if ( ! V_3 -> V_151 [ V_123 ] )
return 0 ;
V_82 = V_3 -> V_151 [ V_123 ] ;
V_82 -> V_157 = F_36 ( V_3 , V_69 , V_5 ) ;
if ( ! V_82 -> V_157 )
goto V_54;
F_32 ( V_3 , L_17 , V_123 ,
( unsigned long long ) V_82 -> V_157 -> V_7 ) ;
V_82 -> V_156 = F_36 ( V_3 , V_70 , V_5 ) ;
if ( ! V_82 -> V_156 )
goto V_54;
F_32 ( V_3 , L_18 , V_123 ,
( unsigned long long ) V_82 -> V_156 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_61 ( V_3 , & V_82 -> V_62 [ V_8 ] ) ;
F_30 ( & V_82 -> V_62 [ V_8 ] . V_158 ) ;
F_30 ( & V_82 -> V_62 [ V_8 ] . V_155 ) ;
}
V_82 -> V_62 [ 0 ] . V_30 = F_29 ( V_3 , 2 , 1 , V_159 , V_5 ) ;
if ( ! V_82 -> V_62 [ 0 ] . V_30 )
goto V_54;
V_82 -> V_61 = F_2 (
sizeof( struct V_29 * ) * V_60 ,
V_5 ) ;
if ( ! V_82 -> V_61 )
goto V_54;
V_82 -> V_59 = 0 ;
F_74 ( & V_82 -> V_160 ) ;
V_82 -> V_145 = V_145 ;
V_3 -> V_152 -> V_153 [ V_123 ] = F_10 ( V_82 -> V_157 -> V_7 ) ;
F_32 ( V_3 , L_19 ,
V_123 ,
& V_3 -> V_152 -> V_153 [ V_123 ] ,
F_75 ( V_3 -> V_152 -> V_153 [ V_123 ] ) ) ;
return 1 ;
V_54:
F_69 ( V_3 , V_123 ) ;
return 0 ;
}
void F_76 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_55 * V_56 ;
struct V_77 * V_161 ;
struct V_29 * V_162 ;
V_56 = V_3 -> V_151 [ V_145 -> V_123 ] ;
V_161 = F_42 ( V_3 , V_56 -> V_156 , 0 ) ;
V_162 = V_56 -> V_62 [ 0 ] . V_30 ;
V_161 -> V_120 = F_10 ( F_59 ( V_162 -> V_33 ,
V_162 -> V_47 )
| V_162 -> V_4 ) ;
}
static T_3 F_77 ( struct V_2 * V_3 ,
struct V_134 * V_145 )
{
struct V_134 * V_163 ;
struct V_164 * V_165 ;
if ( V_145 -> V_166 == V_167 )
V_165 = V_3 -> V_168 ;
else
V_165 = V_3 -> V_169 ;
for ( V_163 = V_145 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
return F_78 ( V_165 , V_163 -> V_171 ) ;
}
int F_79 ( struct V_2 * V_3 , struct V_134 * V_145 )
{
struct V_55 * V_82 ;
struct V_77 * V_161 ;
struct V_76 * V_172 ;
T_3 V_173 ;
T_3 V_174 ;
struct V_134 * V_163 ;
V_82 = V_3 -> V_151 [ V_145 -> V_123 ] ;
if ( V_145 -> V_123 == 0 || ! V_82 ) {
F_71 ( V_3 , L_20 ,
V_145 -> V_123 ) ;
return - V_175 ;
}
V_161 = F_42 ( V_3 , V_82 -> V_156 , 0 ) ;
V_172 = F_41 ( V_3 , V_82 -> V_156 ) ;
V_172 -> V_176 |= F_5 ( F_80 ( 1 ) | V_145 -> V_177 ) ;
switch ( V_145 -> V_166 ) {
case V_167 :
V_172 -> V_176 |= F_5 ( V_178 ) ;
V_174 = F_81 ( 512 ) ;
break;
case V_179 :
V_172 -> V_176 |= F_5 ( V_180 ) ;
V_174 = F_81 ( 64 ) ;
break;
case V_181 :
V_172 -> V_176 |= F_5 ( V_182 ) ;
V_174 = F_81 ( 64 ) ;
break;
case V_183 :
V_172 -> V_176 |= F_5 ( V_184 ) ;
V_174 = F_81 ( 8 ) ;
break;
case V_185 :
F_32 ( V_3 , L_21 ) ;
return - V_175 ;
break;
default:
return - V_175 ;
}
V_173 = F_77 ( V_3 , V_145 ) ;
if ( ! V_173 )
return - V_175 ;
V_172 -> V_186 |= F_5 ( F_82 ( V_173 ) ) ;
for ( V_163 = V_145 ; V_163 -> V_170 && V_163 -> V_170 -> V_170 ;
V_163 = V_163 -> V_170 )
;
V_82 -> V_187 = V_163 -> V_171 ;
V_82 -> V_129 = V_173 ;
F_32 ( V_3 , L_22 , V_173 ) ;
F_32 ( V_3 , L_23 , V_82 -> V_187 ) ;
if ( ! V_145 -> V_137 || ! V_145 -> V_137 -> V_188 -> V_170 ) {
V_82 -> V_143 = & V_3 -> V_131 [ V_173 - 1 ] . V_143 ;
} else {
struct V_189 * V_131 ;
struct V_126 * V_190 ;
V_131 = & V_3 -> V_131 [ V_173 - 1 ] ;
F_83 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_190 -> V_123 != V_145 -> V_137 -> V_188 -> V_123 )
continue;
if ( ! V_82 -> V_145 -> V_137 -> V_140 ||
( V_145 -> V_137 -> V_140 &&
V_190 -> V_146 == V_82 -> V_145 -> V_146 ) ) {
V_82 -> V_143 = & V_190 -> V_143 ;
V_82 -> V_127 = V_190 ;
break;
}
}
if ( ! V_82 -> V_127 )
F_71 ( V_3 , L_24 ) ;
}
if ( V_145 -> V_137 && V_145 -> V_137 -> V_188 -> V_170 ) {
V_172 -> V_127 = F_5 ( V_145 -> V_137 -> V_188 -> V_123 |
( V_145 -> V_146 << 8 ) ) ;
if ( V_145 -> V_137 -> V_140 )
V_172 -> V_176 |= F_5 ( V_191 ) ;
}
F_32 ( V_3 , L_25 , V_145 -> V_137 ) ;
F_32 ( V_3 , L_26 , V_145 -> V_146 ) ;
V_161 -> V_192 = F_5 ( F_84 ( V_193 ) ) ;
V_161 -> V_192 |= F_5 ( F_85 ( 0 ) | F_86 ( 3 ) |
V_174 ) ;
V_161 -> V_120 = F_10 ( V_82 -> V_62 [ 0 ] . V_30 -> V_43 -> V_7 |
V_82 -> V_62 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_87 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
unsigned int V_195 ;
V_195 = F_88 ( V_90 -> V_196 . V_197 , 1 , 16 ) - 1 ;
if ( V_195 != V_90 -> V_196 . V_197 - 1 )
F_89 ( & V_145 -> V_82 ,
L_27 ,
V_90 -> V_196 . V_198 ,
1 << V_195 ,
V_145 -> V_166 == V_181 ? L_4 : L_28 ) ;
if ( V_145 -> V_166 == V_181 ) {
V_195 += 3 ;
}
return V_195 ;
}
static unsigned int F_90 ( struct V_134 * V_145 ,
struct V_194 * V_90 , unsigned int V_199 ,
unsigned int V_200 , unsigned int V_201 )
{
unsigned int V_195 ;
V_195 = F_56 ( V_199 ) - 1 ;
V_195 = F_88 ( V_195 , V_200 , V_201 ) ;
if ( ( 1 << V_195 ) != V_199 )
F_89 ( & V_145 -> V_82 ,
L_29 ,
V_90 -> V_196 . V_198 ,
1 << V_195 ,
V_199 ) ;
return V_195 ;
}
static unsigned int F_91 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
if ( V_90 -> V_196 . V_197 == 0 )
return 0 ;
return F_90 ( V_145 , V_90 ,
V_90 -> V_196 . V_197 , 0 , 15 ) ;
}
static unsigned int F_92 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
return F_90 ( V_145 , V_90 ,
V_90 -> V_196 . V_197 * 8 , 3 , 10 ) ;
}
static unsigned int F_93 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
unsigned int V_195 = 0 ;
switch ( V_145 -> V_166 ) {
case V_179 :
if ( F_94 ( & V_90 -> V_196 ) ||
F_95 ( & V_90 -> V_196 ) ) {
V_195 = F_91 ( V_145 , V_90 ) ;
break;
}
case V_167 :
if ( F_96 ( & V_90 -> V_196 ) ||
F_97 ( & V_90 -> V_196 ) ) {
V_195 = F_87 ( V_145 , V_90 ) ;
}
break;
case V_181 :
if ( F_97 ( & V_90 -> V_196 ) ) {
V_195 = F_87 ( V_145 , V_90 ) ;
break;
}
case V_183 :
if ( F_96 ( & V_90 -> V_196 ) ||
F_97 ( & V_90 -> V_196 ) ) {
V_195 = F_92 ( V_145 , V_90 ) ;
}
break;
default:
F_98 () ;
}
return F_99 ( V_195 ) ;
}
static T_3 F_100 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
if ( V_145 -> V_166 != V_167 ||
! F_97 ( & V_90 -> V_196 ) )
return 0 ;
return V_90 -> V_202 . V_203 ;
}
static T_3 F_101 ( struct V_194 * V_90 )
{
int V_204 ;
T_3 type ;
V_204 = F_102 ( & V_90 -> V_196 ) ;
if ( F_94 ( & V_90 -> V_196 ) ) {
type = F_84 ( V_193 ) ;
} else if ( F_95 ( & V_90 -> V_196 ) ) {
if ( V_204 )
type = F_84 ( V_205 ) ;
else
type = F_84 ( V_206 ) ;
} else if ( F_97 ( & V_90 -> V_196 ) ) {
if ( V_204 )
type = F_84 ( V_207 ) ;
else
type = F_84 ( V_208 ) ;
} else if ( F_96 ( & V_90 -> V_196 ) ) {
if ( V_204 )
type = F_84 ( V_209 ) ;
else
type = F_84 ( V_210 ) ;
} else {
type = 0 ;
}
return type ;
}
static T_3 F_103 ( struct V_134 * V_145 ,
struct V_194 * V_90 )
{
int V_211 ;
int V_212 ;
if ( F_94 ( & V_90 -> V_196 ) ||
F_95 ( & V_90 -> V_196 ) )
return 0 ;
if ( V_145 -> V_166 == V_167 )
return F_104 ( V_90 -> V_202 . V_213 ) ;
V_212 = F_105 ( F_106 ( & V_90 -> V_196 ) ) ;
V_211 = ( F_106 ( & V_90 -> V_196 ) & 0x1800 ) >> 11 ;
return V_212 * ( V_211 + 1 ) ;
}
int F_107 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_134 * V_145 ,
struct V_194 * V_90 ,
T_1 V_39 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
struct V_29 * V_162 ;
unsigned int V_212 ;
unsigned int V_211 ;
enum V_19 type ;
T_3 V_214 ;
T_3 V_215 ;
V_57 = F_108 ( & V_90 -> V_196 ) ;
V_114 = F_42 ( V_3 , V_56 -> V_156 , V_57 ) ;
V_215 = F_101 ( V_90 ) ;
if ( ! V_215 )
return - V_175 ;
V_114 -> V_192 = F_5 ( V_215 ) ;
type = F_109 ( & V_90 -> V_196 ) ;
V_56 -> V_62 [ V_57 ] . V_216 =
F_29 ( V_3 , 2 , 1 , type , V_39 ) ;
if ( ! V_56 -> V_62 [ V_57 ] . V_216 ) {
if ( V_56 -> V_59 == 0 )
return - V_52 ;
V_56 -> V_59 -- ;
V_56 -> V_62 [ V_57 ] . V_216 =
V_56 -> V_61 [ V_56 -> V_59 ] ;
V_56 -> V_61 [ V_56 -> V_59 ] = NULL ;
F_33 ( V_3 , V_56 -> V_62 [ V_57 ] . V_216 ,
1 , type ) ;
}
V_56 -> V_62 [ V_57 ] . V_217 = false ;
V_162 = V_56 -> V_62 [ V_57 ] . V_216 ;
V_114 -> V_120 = F_10 ( V_162 -> V_43 -> V_7 | V_162 -> V_4 ) ;
V_114 -> V_117 = F_5 ( F_93 ( V_145 , V_90 )
| F_110 ( F_100 ( V_145 , V_90 ) ) ) ;
if ( ! F_97 ( & V_90 -> V_196 ) )
V_114 -> V_192 |= F_5 ( F_86 ( 3 ) ) ;
else
V_114 -> V_192 |= F_5 ( F_86 ( 0 ) ) ;
V_212 = F_105 ( F_106 ( & V_90 -> V_196 ) ) ;
V_211 = 0 ;
switch ( V_145 -> V_166 ) {
case V_167 :
V_211 = V_90 -> V_202 . V_218 ;
break;
case V_179 :
if ( F_95 ( & V_90 -> V_196 ) )
V_212 = 512 ;
if ( F_97 ( & V_90 -> V_196 ) ||
F_96 ( & V_90 -> V_196 ) ) {
V_211 = ( F_106 ( & V_90 -> V_196 )
& 0x1800 ) >> 11 ;
}
break;
case V_181 :
case V_183 :
break;
default:
F_98 () ;
}
V_114 -> V_192 |= F_5 ( F_81 ( V_212 ) |
F_85 ( V_211 ) ) ;
V_214 = F_103 ( V_145 , V_90 ) ;
V_114 -> V_219 = F_5 ( F_111 ( V_214 ) ) ;
if ( F_94 ( & V_90 -> V_196 ) && V_3 -> V_220 >= 0x100 )
V_114 -> V_219 |= F_5 ( F_112 ( 8 ) ) ;
else
V_114 -> V_219 |=
F_5 ( F_112 ( V_214 ) ) ;
return 0 ;
}
void F_113 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_194 * V_90 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
V_57 = F_108 ( & V_90 -> V_196 ) ;
V_114 = F_42 ( V_3 , V_56 -> V_156 , V_57 ) ;
V_114 -> V_117 = 0 ;
V_114 -> V_192 = 0 ;
V_114 -> V_120 = 0 ;
V_114 -> V_219 = 0 ;
}
void F_114 ( struct V_221 * V_222 )
{
V_222 -> V_223 = 0 ;
V_222 -> V_224 = 0 ;
V_222 -> V_225 = 0 ;
V_222 -> V_226 = 0 ;
V_222 -> type = 0 ;
V_222 -> V_214 = 0 ;
}
void F_115 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_75 * V_227 ,
struct V_55 * V_56 )
{
struct V_221 * V_222 ;
struct V_77 * V_114 ;
unsigned int V_228 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_222 = & V_56 -> V_62 [ V_8 ] . V_222 ;
if ( ! F_116 ( V_227 , V_8 ) && F_117 ( V_227 , V_8 ) ) {
F_114 ( V_222 ) ;
continue;
}
if ( F_116 ( V_227 , V_8 ) ) {
V_114 = F_42 ( V_3 , V_156 , V_8 ) ;
V_228 = F_118 ( F_11 ( V_114 -> V_192 ) ) ;
if ( V_228 != V_208 && V_228 != V_210 &&
V_228 != V_207 &&
V_228 != V_209 )
continue;
V_222 -> V_223 = F_119 (
F_11 ( V_114 -> V_117 ) ) ;
V_222 -> V_224 = F_120 (
F_11 ( V_114 -> V_117 ) ) + 1 ;
V_222 -> V_225 = F_121 (
F_11 ( V_114 -> V_192 ) ) + 1 ;
V_222 -> V_226 = F_122 (
F_11 ( V_114 -> V_192 ) ) ;
V_222 -> type = V_228 ;
V_222 -> V_214 = F_123 (
F_11 ( V_114 -> V_219 ) ) ;
}
}
}
void F_124 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_67 * V_157 ,
unsigned int V_57 )
{
struct V_77 * V_229 ;
struct V_77 * V_230 ;
V_229 = F_42 ( V_3 , V_157 , V_57 ) ;
V_230 = F_42 ( V_3 , V_156 , V_57 ) ;
V_230 -> V_117 = V_229 -> V_117 ;
V_230 -> V_192 = V_229 -> V_192 ;
V_230 -> V_120 = V_229 -> V_120 ;
V_230 -> V_219 = V_229 -> V_219 ;
}
void F_125 ( struct V_2 * V_3 ,
struct V_67 * V_156 ,
struct V_67 * V_157 )
{
struct V_76 * V_231 ;
struct V_76 * V_232 ;
V_231 = F_41 ( V_3 , V_156 ) ;
V_232 = F_41 ( V_3 , V_157 ) ;
V_231 -> V_176 = V_232 -> V_176 ;
V_231 -> V_186 = V_232 -> V_186 ;
V_231 -> V_127 = V_232 -> V_127 ;
V_231 -> V_233 = V_232 -> V_233 ;
}
static int F_126 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
int V_234 = F_127 ( V_3 -> V_235 ) ;
F_35 ( V_3 , V_236 ,
L_30 , V_234 ) ;
if ( ! V_234 )
return 0 ;
V_3 -> V_237 = F_2 ( sizeof( * V_3 -> V_237 ) , V_5 ) ;
if ( ! V_3 -> V_237 )
goto V_238;
V_3 -> V_237 -> V_239 = F_47 ( V_82 ,
V_234 * sizeof( T_5 ) ,
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
V_3 -> V_152 -> V_153 [ 0 ] = F_10 ( V_3 -> V_237 -> V_240 ) ;
for ( V_8 = 0 ; V_8 < V_234 ; V_8 ++ ) {
T_2 V_7 ;
void * V_246 = F_47 ( V_82 , V_3 -> V_247 , & V_7 ,
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
F_45 ( V_82 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
V_245:
F_4 ( V_3 -> V_237 -> V_242 ) ;
V_243:
F_45 ( V_82 , V_234 * sizeof( T_5 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
V_241:
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
V_238:
return - V_52 ;
}
static void F_128 ( struct V_2 * V_3 )
{
int V_234 ;
int V_8 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
if ( ! V_3 -> V_237 )
return;
V_234 = F_127 ( V_3 -> V_235 ) ;
for ( V_8 = 0 ; V_8 < V_234 ; V_8 ++ ) {
F_45 ( V_82 , V_3 -> V_247 ,
V_3 -> V_237 -> V_242 [ V_8 ] ,
V_3 -> V_237 -> V_244 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_237 -> V_244 ) ;
F_4 ( V_3 -> V_237 -> V_242 ) ;
F_45 ( V_82 , V_234 * sizeof( T_5 ) ,
V_3 -> V_237 -> V_239 ,
V_3 -> V_237 -> V_240 ) ;
F_4 ( V_3 -> V_237 ) ;
V_3 -> V_237 = NULL ;
}
struct V_249 * F_51 ( struct V_2 * V_3 ,
bool V_250 , bool V_251 ,
T_1 V_39 )
{
struct V_249 * V_252 ;
V_252 = F_2 ( sizeof( * V_252 ) , V_39 ) ;
if ( ! V_252 )
return NULL ;
if ( V_250 ) {
V_252 -> V_156 =
F_36 ( V_3 , V_70 ,
V_39 ) ;
if ( ! V_252 -> V_156 ) {
F_4 ( V_252 ) ;
return NULL ;
}
}
if ( V_251 ) {
V_252 -> V_253 =
F_2 ( sizeof( struct V_253 ) , V_39 ) ;
if ( ! V_252 -> V_253 ) {
F_39 ( V_3 , V_252 -> V_156 ) ;
F_4 ( V_252 ) ;
return NULL ;
}
F_74 ( V_252 -> V_253 ) ;
}
V_252 -> V_254 = 0 ;
F_30 ( & V_252 -> V_255 ) ;
return V_252 ;
}
void F_129 ( struct V_256 * V_256 )
{
if ( V_256 ) {
F_4 ( V_256 -> V_257 [ 0 ] ) ;
F_4 ( V_256 ) ;
}
}
void F_54 ( struct V_2 * V_3 ,
struct V_249 * V_252 )
{
F_39 ( V_3 ,
V_252 -> V_156 ) ;
F_4 ( V_252 -> V_253 ) ;
F_4 ( V_252 ) ;
}
void F_130 ( struct V_2 * V_3 )
{
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
int V_71 ;
int V_8 , V_139 , V_138 ;
F_131 ( & V_3 -> V_258 ) ;
V_71 = sizeof( struct V_259 ) * ( V_3 -> V_260 . V_261 ) ;
if ( V_3 -> V_260 . V_262 )
F_45 ( V_82 , V_71 ,
V_3 -> V_260 . V_262 , V_3 -> V_260 . V_263 ) ;
V_3 -> V_260 . V_262 = NULL ;
F_35 ( V_3 , V_236 , L_31 ) ;
if ( V_3 -> V_264 )
F_26 ( V_3 , V_3 -> V_264 ) ;
V_3 -> V_264 = NULL ;
F_35 ( V_3 , V_236 , L_32 ) ;
if ( V_3 -> V_265 )
F_54 ( V_3 , V_3 -> V_265 ) ;
V_3 -> V_265 = NULL ;
if ( V_3 -> V_266 )
F_26 ( V_3 , V_3 -> V_266 ) ;
V_3 -> V_266 = NULL ;
F_35 ( V_3 , V_236 , L_33 ) ;
F_132 ( V_3 ) ;
V_138 = F_64 ( V_3 -> V_130 ) ;
for ( V_8 = 0 ; V_8 < V_138 && V_3 -> V_131 ; V_8 ++ ) {
struct V_142 * V_267 = & V_3 -> V_131 [ V_8 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ ) {
struct V_124 * V_90 = & V_267 -> V_148 [ V_139 ] . V_149 ;
while ( ! F_70 ( V_90 ) )
F_133 ( V_90 -> V_16 ) ;
}
}
for ( V_8 = 1 ; V_8 < V_268 ; ++ V_8 )
F_69 ( V_3 , V_8 ) ;
F_134 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_35 ( V_3 , V_236 , L_34 ) ;
F_134 ( V_3 -> V_74 ) ;
V_3 -> V_74 = NULL ;
F_35 ( V_3 , V_236 , L_35 ) ;
F_134 ( V_3 -> V_87 ) ;
V_3 -> V_87 = NULL ;
F_35 ( V_3 , V_236 ,
L_36 ) ;
F_134 ( V_3 -> V_88 ) ;
V_3 -> V_88 = NULL ;
F_35 ( V_3 , V_236 ,
L_37 ) ;
if ( V_3 -> V_152 )
F_45 ( V_82 , sizeof( * V_3 -> V_152 ) ,
V_3 -> V_152 , V_3 -> V_152 -> V_7 ) ;
V_3 -> V_152 = NULL ;
F_128 ( V_3 ) ;
if ( ! V_3 -> V_131 )
goto V_269;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
struct V_126 * V_137 , * V_270 ;
F_65 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_66 ( & V_137 -> V_133 ) ;
F_4 ( V_137 ) ;
}
}
V_269:
V_3 -> V_102 = 0 ;
V_3 -> V_271 = 0 ;
V_3 -> V_272 = 0 ;
V_3 -> V_273 = 0 ;
F_4 ( V_3 -> V_274 ) ;
F_4 ( V_3 -> V_275 ) ;
F_4 ( V_3 -> V_276 ) ;
F_4 ( V_3 -> V_131 ) ;
F_4 ( V_3 -> V_277 ) ;
V_3 -> V_247 = 0 ;
V_3 -> V_278 = 0 ;
V_3 -> V_279 [ 0 ] . V_280 = 0 ;
V_3 -> V_279 [ 1 ] . V_280 = 0 ;
}
static int F_135 ( struct V_2 * V_3 ,
struct V_1 * V_281 ,
union V_63 * V_282 ,
union V_63 * V_283 ,
T_2 V_284 ,
struct V_1 * V_285 ,
char * V_286 , int V_287 )
{
unsigned long long V_288 ;
unsigned long long V_289 ;
struct V_1 * V_6 ;
V_288 = F_59 ( V_281 , V_282 ) ;
V_289 = F_59 ( V_281 , V_283 ) ;
V_6 = F_136 ( V_3 , V_281 , V_282 , V_283 , V_284 , false ) ;
if ( V_6 != V_285 ) {
F_71 ( V_3 , L_38 ,
V_286 , V_287 ) ;
F_71 ( V_3 , L_39
L_40 ,
V_281 ,
( unsigned long long ) V_284 ) ;
F_71 ( V_3 , L_41
L_42 ,
V_282 , V_288 ,
V_283 , V_289 ) ;
F_71 ( V_3 , L_43 ,
V_285 , V_6 ) ;
F_136 ( V_3 , V_281 , V_282 , V_283 , V_284 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_137 ( struct V_2 * V_3 )
{
struct {
T_2 V_284 ;
struct V_1 * V_285 ;
} V_290 [] = {
{ 0 , NULL } ,
{ V_3 -> V_264 -> V_43 -> V_7 - 16 , NULL } ,
{ V_3 -> V_264 -> V_43 -> V_7 - 1 , NULL } ,
{ V_3 -> V_264 -> V_43 -> V_7 , V_3 -> V_264 -> V_43 } ,
{ V_3 -> V_264 -> V_43 -> V_7 + ( V_12 - 1 ) * 16 ,
V_3 -> V_264 -> V_43 } ,
{ V_3 -> V_264 -> V_43 -> V_7 + ( V_12 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_264 -> V_43 -> V_7 + ( V_12 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_281 ;
union V_63 * V_282 ;
union V_63 * V_283 ;
T_2 V_284 ;
struct V_1 * V_285 ;
} V_291 [] = {
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = V_3 -> V_264 -> V_43 -> V_9 ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_284 = V_3 -> V_266 -> V_43 -> V_7 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = V_3 -> V_264 -> V_43 -> V_9 ,
. V_283 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_284 = V_3 -> V_266 -> V_43 -> V_7 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = V_3 -> V_266 -> V_43 -> V_9 ,
. V_283 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_284 = V_3 -> V_266 -> V_43 -> V_7 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = & V_3 -> V_264 -> V_43 -> V_9 [ 0 ] ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ 3 ] ,
. V_284 = V_3 -> V_264 -> V_43 -> V_7 + 4 * 16 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = & V_3 -> V_264 -> V_43 -> V_9 [ 3 ] ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ 6 ] ,
. V_284 = V_3 -> V_264 -> V_43 -> V_7 + 2 * 16 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = & V_3 -> V_264 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ 1 ] ,
. V_284 = V_3 -> V_264 -> V_43 -> V_7 + 2 * 16 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = & V_3 -> V_264 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ 1 ] ,
. V_284 = V_3 -> V_264 -> V_43 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_285 = NULL ,
} ,
{ . V_281 = V_3 -> V_264 -> V_43 ,
. V_282 = & V_3 -> V_264 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_283 = & V_3 -> V_264 -> V_43 -> V_9 [ 1 ] ,
. V_284 = V_3 -> V_266 -> V_43 -> V_7 + 2 * 16 ,
. V_285 = NULL ,
} ,
} ;
unsigned int V_292 ;
int V_8 , V_41 ;
V_292 = F_138 ( V_290 ) ;
for ( V_8 = 0 ; V_8 < V_292 ; V_8 ++ ) {
V_41 = F_135 ( V_3 ,
V_3 -> V_264 -> V_43 ,
V_3 -> V_264 -> V_43 -> V_9 ,
& V_3 -> V_264 -> V_43 -> V_9 [ V_12 - 1 ] ,
V_290 [ V_8 ] . V_284 ,
V_290 [ V_8 ] . V_285 ,
L_44 , V_8 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_292 = F_138 ( V_291 ) ;
for ( V_8 = 0 ; V_8 < V_292 ; V_8 ++ ) {
V_41 = F_135 ( V_3 ,
V_291 [ V_8 ] . V_281 ,
V_291 [ V_8 ] . V_282 ,
V_291 [ V_8 ] . V_283 ,
V_291 [ V_8 ] . V_284 ,
V_291 [ V_8 ] . V_285 ,
L_45 , V_8 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_32 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
T_5 V_293 ;
T_2 V_120 ;
V_120 = F_59 ( V_3 -> V_264 -> V_49 ,
V_3 -> V_264 -> V_48 ) ;
if ( V_120 == 0 && ! F_140 () )
F_71 ( V_3 , L_47
L_48 ) ;
V_293 = F_141 ( V_3 , & V_3 -> V_294 -> V_295 ) ;
V_293 &= V_296 ;
V_293 &= ~ V_297 ;
F_35 ( V_3 , V_236 ,
L_49
L_50 ) ;
F_142 ( V_3 , ( ( T_5 ) V_120 & ( T_5 ) ~ V_296 ) | V_293 ,
& V_3 -> V_294 -> V_295 ) ;
}
static void F_143 ( struct V_2 * V_3 , unsigned int V_138 ,
T_6 T_7 * V_101 , T_8 V_298 , int V_299 )
{
T_3 V_293 , V_300 , V_301 ;
int V_8 ;
struct V_302 * V_303 ;
V_293 = F_144 ( V_101 ) ;
if ( F_145 ( V_293 ) == 0x03 ) {
V_303 = & V_3 -> V_304 ;
} else if ( F_145 ( V_293 ) <= 0x02 ) {
V_303 = & V_3 -> V_305 ;
} else {
F_71 ( V_3 , L_51
L_52 ,
V_101 , V_298 ) ;
return;
}
V_303 -> V_306 = F_145 ( V_293 ) ;
V_303 -> V_307 = F_146 ( V_293 ) ;
V_293 = F_144 ( V_101 + 2 ) ;
V_300 = F_147 ( V_293 ) ;
V_301 = F_148 ( V_293 ) ;
F_35 ( V_3 , V_236 ,
L_53
L_54 ,
V_101 , V_300 , V_301 , V_298 ) ;
if ( V_300 == 0 || ( V_300 + V_301 - 1 ) > V_138 )
return;
V_303 -> V_308 = F_149 ( V_293 ) ;
if ( V_303 -> V_308 ) {
V_303 -> V_309 = F_150 ( V_303 -> V_308 , sizeof( * V_303 -> V_309 ) ,
V_310 ) ;
if ( ! V_303 -> V_309 )
V_303 -> V_308 = 0 ;
V_303 -> V_311 ++ ;
for ( V_8 = 0 ; V_8 < V_303 -> V_308 ; V_8 ++ ) {
V_303 -> V_309 [ V_8 ] = F_144 ( V_101 + 4 + V_8 ) ;
if ( V_8 && ( F_151 ( V_303 -> V_309 [ V_8 ] ) !=
F_151 ( V_303 -> V_309 [ V_8 - 1 ] ) ) )
V_303 -> V_311 ++ ;
F_32 ( V_3 , L_55 ,
F_151 ( V_303 -> V_309 [ V_8 ] ) ,
F_152 ( V_303 -> V_309 [ V_8 ] ) ,
F_153 ( V_303 -> V_309 [ V_8 ] ) ,
F_154 ( V_303 -> V_309 [ V_8 ] ) ,
F_155 ( V_303 -> V_309 [ V_8 ] ) ,
F_156 ( V_303 -> V_309 [ V_8 ] ) ) ;
}
}
if ( V_298 < 0x03 && V_3 -> V_312 < V_299 )
V_3 -> V_277 [ V_3 -> V_312 ++ ] = V_293 ;
if ( ( V_3 -> V_220 == 0x96 ) && ( V_298 != 0x03 ) &&
( V_293 & V_313 ) ) {
F_35 ( V_3 , V_236 ,
L_56 ) ;
V_3 -> V_314 = 1 ;
}
if ( ( V_3 -> V_220 >= 0x100 ) && ( V_298 != 0x03 ) ) {
F_35 ( V_3 , V_236 ,
L_57 ) ;
V_3 -> V_314 = 1 ;
if ( V_293 & V_315 ) {
F_35 ( V_3 , V_236 ,
L_58 ) ;
V_3 -> V_316 = 1 ;
}
}
V_300 -- ;
for ( V_8 = V_300 ; V_8 < ( V_300 + V_301 ) ; V_8 ++ ) {
if ( V_3 -> V_276 [ V_8 ] != 0 ) {
F_71 ( V_3 , L_59
L_60 , V_101 , V_8 ) ;
F_71 ( V_3 , L_61
L_62 ,
V_3 -> V_276 [ V_8 ] , V_298 ) ;
if ( V_3 -> V_276 [ V_8 ] != V_298 &&
V_3 -> V_276 [ V_8 ] != V_317 ) {
if ( V_3 -> V_276 [ V_8 ] == 0x03 )
V_3 -> V_272 -- ;
else
V_3 -> V_271 -- ;
V_3 -> V_276 [ V_8 ] = V_317 ;
}
continue;
}
V_3 -> V_276 [ V_8 ] = V_298 ;
if ( V_298 == 0x03 )
V_3 -> V_272 ++ ;
else
V_3 -> V_271 ++ ;
}
}
static int F_157 ( struct V_2 * V_3 , T_1 V_5 )
{
T_6 T_7 * V_101 , * V_318 ;
T_3 V_319 , V_320 ;
unsigned int V_138 ;
int V_8 , V_139 , V_321 ;
int V_322 = 0 ;
V_101 = & V_3 -> V_323 -> V_72 ;
V_319 = F_158 ( F_144 ( V_101 ) ) ;
if ( V_319 == 0 ) {
F_159 ( V_3 , L_63
L_64 ) ;
return - V_324 ;
}
V_138 = F_64 ( V_3 -> V_130 ) ;
V_3 -> V_276 = F_2 ( sizeof( * V_3 -> V_276 ) * V_138 , V_5 ) ;
if ( ! V_3 -> V_276 )
return - V_52 ;
V_3 -> V_131 = F_2 ( sizeof( * V_3 -> V_131 ) * V_138 , V_5 ) ;
if ( ! V_3 -> V_131 )
return - V_52 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
struct V_142 * V_143 ;
F_30 ( & V_3 -> V_131 [ V_8 ] . V_132 ) ;
V_143 = & V_3 -> V_131 [ V_8 ] . V_143 ;
for ( V_139 = 0 ; V_139 < V_147 ; V_139 ++ )
F_30 ( & V_143 -> V_148 [ V_139 ] . V_149 ) ;
}
V_101 = & V_3 -> V_323 -> V_325 + V_319 ;
V_318 = V_101 ;
V_320 = V_319 ;
do {
T_3 V_326 ;
V_326 = F_144 ( V_318 ) ;
if ( F_160 ( V_326 ) == V_327 )
V_322 ++ ;
V_320 = F_161 ( V_326 ) ;
V_318 += V_320 ;
} while ( V_320 );
V_3 -> V_277 = F_2 ( sizeof( * V_3 -> V_277 ) * V_322 , V_5 ) ;
if ( ! V_3 -> V_277 )
return - V_52 ;
while ( 1 ) {
T_3 V_326 ;
V_326 = F_144 ( V_101 ) ;
if ( F_160 ( V_326 ) == V_327 )
F_143 ( V_3 , V_138 , V_101 ,
( T_8 ) F_145 ( V_326 ) ,
V_322 ) ;
V_319 = F_161 ( V_326 ) ;
if ( ! V_319 || ( V_3 -> V_271 + V_3 -> V_272 )
== V_138 )
break;
V_101 += V_319 ;
}
if ( V_3 -> V_271 == 0 && V_3 -> V_272 == 0 ) {
F_71 ( V_3 , L_65 ) ;
return - V_324 ;
}
F_35 ( V_3 , V_236 ,
L_66 ,
V_3 -> V_271 , V_3 -> V_272 ) ;
if ( V_3 -> V_272 > 15 ) {
F_35 ( V_3 , V_236 ,
L_67 ) ;
V_3 -> V_272 = 15 ;
}
if ( V_3 -> V_271 > V_328 ) {
F_35 ( V_3 , V_236 ,
L_68 ,
V_328 ) ;
V_3 -> V_271 = V_328 ;
}
if ( V_3 -> V_271 ) {
V_3 -> V_274 = F_162 ( sizeof( * V_3 -> V_274 ) *
V_3 -> V_271 , V_5 ) ;
if ( ! V_3 -> V_274 )
return - V_52 ;
V_321 = 0 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ ) {
if ( V_3 -> V_276 [ V_8 ] == 0x03 ||
V_3 -> V_276 [ V_8 ] == 0 ||
V_3 -> V_276 [ V_8 ] == V_317 )
continue;
V_3 -> V_274 [ V_321 ] =
& V_3 -> V_329 -> V_330 +
V_331 * V_8 ;
F_35 ( V_3 , V_236 ,
L_69
L_70 , V_8 ,
V_3 -> V_274 [ V_321 ] ) ;
V_321 ++ ;
if ( V_321 == V_3 -> V_271 )
break;
}
}
if ( V_3 -> V_272 ) {
V_3 -> V_275 = F_162 ( sizeof( * V_3 -> V_275 ) *
V_3 -> V_272 , V_5 ) ;
if ( ! V_3 -> V_275 )
return - V_52 ;
V_321 = 0 ;
for ( V_8 = 0 ; V_8 < V_138 ; V_8 ++ )
if ( V_3 -> V_276 [ V_8 ] == 0x03 ) {
V_3 -> V_275 [ V_321 ] =
& V_3 -> V_329 -> V_330 +
V_331 * V_8 ;
F_35 ( V_3 , V_236 ,
L_71
L_70 , V_8 ,
V_3 -> V_275 [ V_321 ] ) ;
V_321 ++ ;
if ( V_321 == V_3 -> V_272 )
break;
}
}
return 0 ;
}
int F_163 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
unsigned int V_20 , V_332 ;
T_5 V_333 ;
struct V_1 * V_6 ;
T_3 V_247 , V_293 ;
int V_8 ;
F_30 ( & V_3 -> V_255 ) ;
F_62 ( & V_3 -> V_258 , V_334 ,
( unsigned long ) V_3 ) ;
V_247 = F_144 ( & V_3 -> V_329 -> V_247 ) ;
F_35 ( V_3 , V_236 ,
L_72 , V_247 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_247 ) != 0 )
break;
V_247 = V_247 >> 1 ;
}
if ( V_8 < 16 )
F_35 ( V_3 , V_236 ,
L_73 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_71 ( V_3 , L_74 ) ;
V_3 -> V_278 = 12 ;
V_3 -> V_247 = 1 << V_3 -> V_278 ;
F_35 ( V_3 , V_236 ,
L_75 , V_3 -> V_247 / 1024 ) ;
V_20 = F_164 ( F_144 ( & V_3 -> V_323 -> V_130 ) ) ;
F_35 ( V_3 , V_236 ,
L_76 , V_20 ) ;
V_332 = F_144 ( & V_3 -> V_329 -> V_335 ) ;
V_20 |= ( V_332 & ~ V_336 ) ;
F_35 ( V_3 , V_236 ,
L_77 , V_20 ) ;
F_165 ( V_20 , & V_3 -> V_329 -> V_335 ) ;
V_3 -> V_152 = F_47 ( V_82 , sizeof( * V_3 -> V_152 ) , & V_7 ,
V_310 ) ;
if ( ! V_3 -> V_152 )
goto V_54;
memset ( V_3 -> V_152 , 0 , sizeof *( V_3 -> V_152 ) ) ;
V_3 -> V_152 -> V_7 = V_7 ;
F_35 ( V_3 , V_236 ,
L_78 ,
( unsigned long long ) V_3 -> V_152 -> V_7 , V_3 -> V_152 ) ;
F_142 ( V_3 , V_7 , & V_3 -> V_329 -> V_337 ) ;
V_3 -> V_10 = F_166 ( L_79 , V_82 ,
V_11 , V_11 , V_3 -> V_247 ) ;
V_3 -> V_74 = F_166 ( L_80 , V_82 ,
2112 , 64 , V_3 -> V_247 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_74 )
goto V_54;
V_3 -> V_87 =
F_166 ( L_81 ,
V_82 , V_86 , 16 , 0 ) ;
V_3 -> V_88 =
F_166 ( L_82 ,
V_82 , V_85 , 16 , 0 ) ;
if ( ! V_3 -> V_87 || ! V_3 -> V_88 )
goto V_54;
V_3 -> V_266 = F_29 ( V_3 , 1 , 1 , V_338 , V_5 ) ;
if ( ! V_3 -> V_266 )
goto V_54;
F_35 ( V_3 , V_236 ,
L_83 , V_3 -> V_266 ) ;
F_35 ( V_3 , V_236 , L_84 ,
( unsigned long long ) V_3 -> V_266 -> V_43 -> V_7 ) ;
V_333 = F_141 ( V_3 , & V_3 -> V_329 -> V_266 ) ;
V_333 = ( V_333 & ( T_5 ) V_339 ) |
( V_3 -> V_266 -> V_43 -> V_7 & ( T_5 ) ~ V_339 ) |
V_3 -> V_266 -> V_4 ;
F_35 ( V_3 , V_236 ,
L_85 , V_20 ) ;
F_142 ( V_3 , V_333 , & V_3 -> V_329 -> V_266 ) ;
F_167 ( V_3 ) ;
V_3 -> V_265 = F_51 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_265 )
goto V_54;
V_3 -> V_102 ++ ;
V_20 = F_144 ( & V_3 -> V_323 -> V_340 ) ;
V_20 &= V_341 ;
F_35 ( V_3 , V_236 ,
L_86
L_87 , V_20 ) ;
V_3 -> V_342 = ( void T_7 * ) V_3 -> V_323 + V_20 ;
F_168 ( V_3 ) ;
F_169 ( V_3 ) ;
V_3 -> V_294 = & V_3 -> V_343 -> V_294 [ 0 ] ;
F_35 ( V_3 , V_236 , L_88 ) ;
V_3 -> V_264 = F_29 ( V_3 , V_344 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_264 )
goto V_54;
if ( F_137 ( V_3 ) < 0 )
goto V_54;
V_3 -> V_260 . V_262 = F_47 ( V_82 ,
sizeof( struct V_259 ) * V_344 , & V_7 ,
V_310 ) ;
if ( ! V_3 -> V_260 . V_262 )
goto V_54;
F_35 ( V_3 , V_236 ,
L_89 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_260 . V_262 , 0 , sizeof( struct V_259 ) * V_344 ) ;
V_3 -> V_260 . V_261 = V_344 ;
V_3 -> V_260 . V_263 = V_7 ;
F_35 ( V_3 , V_236 ,
L_90 ,
V_3 -> V_260 . V_261 ,
V_3 -> V_260 . V_262 ,
( unsigned long long ) V_3 -> V_260 . V_263 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_264 -> V_43 ; V_20 < V_344 ; V_20 ++ ) {
struct V_259 * V_345 = & V_3 -> V_260 . V_262 [ V_20 ] ;
V_345 -> V_346 = F_10 ( V_6 -> V_7 ) ;
V_345 -> V_347 = F_5 ( V_12 ) ;
V_345 -> V_348 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_144 ( & V_3 -> V_294 -> V_349 ) ;
V_20 &= V_350 ;
V_20 |= V_344 ;
F_35 ( V_3 , V_236 ,
L_91 ,
V_20 ) ;
F_165 ( V_20 , & V_3 -> V_294 -> V_349 ) ;
F_35 ( V_3 , V_236 ,
L_92 ) ;
F_35 ( V_3 , V_236 ,
L_93 ,
( unsigned long long ) V_3 -> V_260 . V_263 ) ;
V_333 = F_141 ( V_3 , & V_3 -> V_294 -> V_351 ) ;
V_333 &= V_296 ;
V_333 |= ( V_3 -> V_260 . V_263 & ( T_5 ) ~ V_296 ) ;
F_142 ( V_3 , V_333 , & V_3 -> V_294 -> V_351 ) ;
F_139 ( V_3 ) ;
F_35 ( V_3 , V_236 ,
L_94 ) ;
F_170 ( V_3 , 0 ) ;
F_74 ( & V_3 -> V_352 ) ;
for ( V_8 = 0 ; V_8 < V_268 ; ++ V_8 )
V_3 -> V_151 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_328 ; ++ V_8 ) {
V_3 -> V_279 [ 0 ] . V_353 [ V_8 ] = 0 ;
V_3 -> V_279 [ 1 ] . V_353 [ V_8 ] = 0 ;
F_74 ( & V_3 -> V_279 [ 1 ] . V_354 [ V_8 ] ) ;
}
if ( F_126 ( V_3 , V_5 ) )
goto V_54;
if ( F_157 ( V_3 , V_5 ) )
goto V_54;
V_293 = F_144 ( & V_3 -> V_329 -> V_355 ) ;
V_293 &= ~ V_356 ;
V_293 |= V_357 ;
F_165 ( V_293 , & V_3 -> V_329 -> V_355 ) ;
return 0 ;
V_54:
F_71 ( V_3 , L_95 ) ;
F_171 ( V_3 ) ;
F_172 ( V_3 ) ;
F_130 ( V_3 ) ;
return - V_52 ;
}
