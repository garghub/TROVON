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
struct V_75 * F_40 ( struct V_2 * V_3 ,
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
void F_58 ( struct V_2 * V_3 ,
struct V_77 * V_114 ,
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
F_62 ( & V_90 -> V_121 ) ;
V_90 -> V_121 . V_122 = ( unsigned long ) V_90 ;
V_90 -> V_121 . V_123 = V_124 ;
V_90 -> V_3 = V_3 ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
int V_125 )
{
struct V_126 * V_127 ;
struct V_128 * V_129 , * V_16 ;
bool V_130 = false ;
if ( V_56 -> V_131 == 0 ||
V_56 -> V_131 > F_64 ( V_3 -> V_132 ) ) {
F_32 ( V_3 , L_13 ) ;
return;
}
V_127 = & ( V_3 -> V_133 [ V_56 -> V_131 - 1 ] . V_134 ) ;
F_65 (tt_info, next, tt_list_head, tt_list) {
if ( V_129 -> V_125 == V_125 ) {
V_130 = true ;
F_66 ( & V_129 -> V_135 ) ;
F_4 ( V_129 ) ;
} else if ( V_130 ) {
break;
}
}
}
int F_67 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_136 * V_137 ,
struct V_138 * V_139 , T_1 V_39 )
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
V_129 = F_2 ( sizeof( * V_129 ) , V_39 ) ;
if ( ! V_129 )
goto V_146;
F_30 ( & V_129 -> V_135 ) ;
F_68 ( & V_129 -> V_135 ,
& V_3 -> V_133 [ V_56 -> V_131 - 1 ] . V_134 ) ;
V_129 -> V_125 = V_56 -> V_147 -> V_125 ;
if ( V_139 -> V_142 )
V_129 -> V_148 = V_8 + 1 ;
V_145 = & V_129 -> V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_30 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
return 0 ;
V_146:
F_63 ( V_3 , V_56 , V_56 -> V_147 -> V_125 ) ;
return - V_52 ;
}
void F_69 ( struct V_2 * V_3 , int V_125 )
{
struct V_55 * V_82 ;
int V_8 ;
int V_152 = 0 ;
if ( V_125 == 0 || ! V_3 -> V_153 [ V_125 ] )
return;
V_82 = V_3 -> V_153 [ V_125 ] ;
V_3 -> V_154 -> V_155 [ V_125 ] = 0 ;
if ( ! V_82 )
return;
if ( V_82 -> V_129 )
V_152 = V_82 -> V_129 -> V_156 ;
for ( V_8 = 0 ; V_8 < 31 ; ++ V_8 ) {
if ( V_82 -> V_62 [ V_8 ] . V_30 )
F_26 ( V_3 , V_82 -> V_62 [ V_8 ] . V_30 ) ;
if ( V_82 -> V_62 [ V_8 ] . V_94 )
F_60 ( V_3 ,
V_82 -> V_62 [ V_8 ] . V_94 ) ;
if ( ! F_70 ( & V_82 -> V_62 [ V_8 ] . V_157 ) )
F_71 ( V_3 , L_14
L_15 ,
V_125 , V_8 ) ;
}
F_63 ( V_3 , V_82 , V_125 ) ;
F_72 ( V_3 , V_82 , V_152 ) ;
if ( V_82 -> V_61 ) {
for ( V_8 = 0 ; V_8 < V_82 -> V_59 ; V_8 ++ )
F_26 ( V_3 , V_82 -> V_61 [ V_8 ] ) ;
F_4 ( V_82 -> V_61 ) ;
}
if ( V_82 -> V_158 )
F_39 ( V_3 , V_82 -> V_158 ) ;
if ( V_82 -> V_159 )
F_39 ( V_3 , V_82 -> V_159 ) ;
F_4 ( V_3 -> V_153 [ V_125 ] ) ;
V_3 -> V_153 [ V_125 ] = NULL ;
}
int F_73 ( struct V_2 * V_3 , int V_125 ,
struct V_136 * V_147 , T_1 V_5 )
{
struct V_55 * V_82 ;
int V_8 ;
if ( V_125 == 0 || V_3 -> V_153 [ V_125 ] ) {
F_71 ( V_3 , L_16 , V_125 ) ;
return 0 ;
}
V_3 -> V_153 [ V_125 ] = F_2 ( sizeof( * V_3 -> V_153 [ V_125 ] ) , V_5 ) ;
if ( ! V_3 -> V_153 [ V_125 ] )
return 0 ;
V_82 = V_3 -> V_153 [ V_125 ] ;
V_82 -> V_159 = F_36 ( V_3 , V_69 , V_5 ) ;
if ( ! V_82 -> V_159 )
goto V_54;
F_32 ( V_3 , L_17 , V_125 ,
( unsigned long long ) V_82 -> V_159 -> V_7 ) ;
V_82 -> V_158 = F_36 ( V_3 , V_70 , V_5 ) ;
if ( ! V_82 -> V_158 )
goto V_54;
F_32 ( V_3 , L_18 , V_125 ,
( unsigned long long ) V_82 -> V_158 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < 31 ; V_8 ++ ) {
F_61 ( V_3 , & V_82 -> V_62 [ V_8 ] ) ;
F_30 ( & V_82 -> V_62 [ V_8 ] . V_160 ) ;
F_30 ( & V_82 -> V_62 [ V_8 ] . V_157 ) ;
}
V_82 -> V_62 [ 0 ] . V_30 = F_29 ( V_3 , 2 , 1 , V_161 , V_5 ) ;
if ( ! V_82 -> V_62 [ 0 ] . V_30 )
goto V_54;
V_82 -> V_61 = F_2 (
sizeof( struct V_29 * ) * V_60 ,
V_5 ) ;
if ( ! V_82 -> V_61 )
goto V_54;
V_82 -> V_59 = 0 ;
F_74 ( & V_82 -> V_162 ) ;
V_82 -> V_147 = V_147 ;
V_3 -> V_154 -> V_155 [ V_125 ] = F_10 ( V_82 -> V_159 -> V_7 ) ;
F_32 ( V_3 , L_19 ,
V_125 ,
& V_3 -> V_154 -> V_155 [ V_125 ] ,
F_75 ( V_3 -> V_154 -> V_155 [ V_125 ] ) ) ;
return 1 ;
V_54:
F_69 ( V_3 , V_125 ) ;
return 0 ;
}
void F_76 ( struct V_2 * V_3 ,
struct V_136 * V_147 )
{
struct V_55 * V_56 ;
struct V_77 * V_163 ;
struct V_29 * V_164 ;
V_56 = V_3 -> V_153 [ V_147 -> V_125 ] ;
V_163 = F_42 ( V_3 , V_56 -> V_158 , 0 ) ;
V_164 = V_56 -> V_62 [ 0 ] . V_30 ;
V_163 -> V_120 = F_10 ( F_59 ( V_164 -> V_33 ,
V_164 -> V_47 )
| V_164 -> V_4 ) ;
}
static T_3 F_77 ( struct V_2 * V_3 ,
struct V_136 * V_147 )
{
struct V_136 * V_165 ;
struct V_166 * V_167 ;
if ( V_147 -> V_168 == V_169 )
V_167 = V_3 -> V_170 ;
else
V_167 = V_3 -> V_171 ;
for ( V_165 = V_147 ; V_165 -> V_172 && V_165 -> V_172 -> V_172 ;
V_165 = V_165 -> V_172 )
;
return F_78 ( V_167 , V_165 -> V_173 ) ;
}
int F_79 ( struct V_2 * V_3 , struct V_136 * V_147 )
{
struct V_55 * V_82 ;
struct V_77 * V_163 ;
struct V_76 * V_174 ;
T_3 V_175 ;
T_3 V_176 ;
struct V_136 * V_165 ;
V_82 = V_3 -> V_153 [ V_147 -> V_125 ] ;
if ( V_147 -> V_125 == 0 || ! V_82 ) {
F_71 ( V_3 , L_20 ,
V_147 -> V_125 ) ;
return - V_177 ;
}
V_163 = F_42 ( V_3 , V_82 -> V_158 , 0 ) ;
V_174 = F_41 ( V_3 , V_82 -> V_158 ) ;
V_174 -> V_178 |= F_5 ( F_80 ( 1 ) | V_147 -> V_179 ) ;
switch ( V_147 -> V_168 ) {
case V_169 :
V_174 -> V_178 |= F_5 ( V_180 ) ;
V_176 = F_81 ( 512 ) ;
break;
case V_181 :
V_174 -> V_178 |= F_5 ( V_182 ) ;
V_176 = F_81 ( 64 ) ;
break;
case V_183 :
V_174 -> V_178 |= F_5 ( V_184 ) ;
V_176 = F_81 ( 64 ) ;
break;
case V_185 :
V_174 -> V_178 |= F_5 ( V_186 ) ;
V_176 = F_81 ( 8 ) ;
break;
case V_187 :
F_32 ( V_3 , L_21 ) ;
return - V_177 ;
break;
default:
return - V_177 ;
}
V_175 = F_77 ( V_3 , V_147 ) ;
if ( ! V_175 )
return - V_177 ;
V_174 -> V_188 |= F_5 ( F_82 ( V_175 ) ) ;
for ( V_165 = V_147 ; V_165 -> V_172 && V_165 -> V_172 -> V_172 ;
V_165 = V_165 -> V_172 )
;
V_82 -> V_189 = V_165 -> V_173 ;
V_82 -> V_131 = V_175 ;
F_32 ( V_3 , L_22 , V_175 ) ;
F_32 ( V_3 , L_23 , V_82 -> V_189 ) ;
if ( ! V_147 -> V_139 || ! V_147 -> V_139 -> V_190 -> V_172 ) {
V_82 -> V_145 = & V_3 -> V_133 [ V_175 - 1 ] . V_145 ;
} else {
struct V_191 * V_133 ;
struct V_128 * V_192 ;
V_133 = & V_3 -> V_133 [ V_175 - 1 ] ;
F_83 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_192 -> V_125 != V_147 -> V_139 -> V_190 -> V_125 )
continue;
if ( ! V_82 -> V_147 -> V_139 -> V_142 ||
( V_147 -> V_139 -> V_142 &&
V_192 -> V_148 == V_82 -> V_147 -> V_148 ) ) {
V_82 -> V_145 = & V_192 -> V_145 ;
V_82 -> V_129 = V_192 ;
break;
}
}
if ( ! V_82 -> V_129 )
F_71 ( V_3 , L_24 ) ;
}
if ( V_147 -> V_139 && V_147 -> V_139 -> V_190 -> V_172 ) {
V_174 -> V_129 = F_5 ( V_147 -> V_139 -> V_190 -> V_125 |
( V_147 -> V_148 << 8 ) ) ;
if ( V_147 -> V_139 -> V_142 )
V_174 -> V_178 |= F_5 ( V_193 ) ;
}
F_32 ( V_3 , L_25 , V_147 -> V_139 ) ;
F_32 ( V_3 , L_26 , V_147 -> V_148 ) ;
V_163 -> V_194 = F_5 ( F_84 ( V_195 ) ) ;
V_163 -> V_194 |= F_5 ( F_85 ( 0 ) | F_86 ( 3 ) |
V_176 ) ;
V_163 -> V_120 = F_10 ( V_82 -> V_62 [ 0 ] . V_30 -> V_43 -> V_7 |
V_82 -> V_62 [ 0 ] . V_30 -> V_4 ) ;
return 0 ;
}
static unsigned int F_87 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
unsigned int V_197 ;
V_197 = F_88 ( V_90 -> V_198 . V_199 , 1 , 16 ) - 1 ;
if ( V_197 != V_90 -> V_198 . V_199 - 1 )
F_89 ( & V_147 -> V_82 ,
L_27 ,
V_90 -> V_198 . V_200 ,
1 << V_197 ,
V_147 -> V_168 == V_183 ? L_4 : L_28 ) ;
if ( V_147 -> V_168 == V_183 ) {
V_197 += 3 ;
}
return V_197 ;
}
static unsigned int F_90 ( struct V_136 * V_147 ,
struct V_196 * V_90 , unsigned int V_201 ,
unsigned int V_202 , unsigned int V_203 )
{
unsigned int V_197 ;
V_197 = F_56 ( V_201 ) - 1 ;
V_197 = F_88 ( V_197 , V_202 , V_203 ) ;
if ( ( 1 << V_197 ) != V_201 )
F_89 ( & V_147 -> V_82 ,
L_29 ,
V_90 -> V_198 . V_200 ,
1 << V_197 ,
V_201 ) ;
return V_197 ;
}
static unsigned int F_91 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
if ( V_90 -> V_198 . V_199 == 0 )
return 0 ;
return F_90 ( V_147 , V_90 ,
V_90 -> V_198 . V_199 , 0 , 15 ) ;
}
static unsigned int F_92 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
return F_90 ( V_147 , V_90 ,
V_90 -> V_198 . V_199 * 8 , 3 , 10 ) ;
}
static unsigned int F_93 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
unsigned int V_197 = 0 ;
switch ( V_147 -> V_168 ) {
case V_181 :
if ( F_94 ( & V_90 -> V_198 ) ||
F_95 ( & V_90 -> V_198 ) ) {
V_197 = F_91 ( V_147 , V_90 ) ;
break;
}
case V_169 :
if ( F_96 ( & V_90 -> V_198 ) ||
F_97 ( & V_90 -> V_198 ) ) {
V_197 = F_87 ( V_147 , V_90 ) ;
}
break;
case V_183 :
if ( F_97 ( & V_90 -> V_198 ) ) {
V_197 = F_87 ( V_147 , V_90 ) ;
break;
}
case V_185 :
if ( F_96 ( & V_90 -> V_198 ) ||
F_97 ( & V_90 -> V_198 ) ) {
V_197 = F_92 ( V_147 , V_90 ) ;
}
break;
default:
F_98 () ;
}
return F_99 ( V_197 ) ;
}
static T_3 F_100 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
if ( V_147 -> V_168 != V_169 ||
! F_97 ( & V_90 -> V_198 ) )
return 0 ;
return V_90 -> V_204 . V_205 ;
}
static T_3 F_101 ( struct V_136 * V_147 ,
struct V_196 * V_90 )
{
int V_206 ;
T_3 type ;
V_206 = F_102 ( & V_90 -> V_198 ) ;
if ( F_94 ( & V_90 -> V_198 ) ) {
type = F_84 ( V_195 ) ;
} else if ( F_95 ( & V_90 -> V_198 ) ) {
if ( V_206 )
type = F_84 ( V_207 ) ;
else
type = F_84 ( V_208 ) ;
} else if ( F_97 ( & V_90 -> V_198 ) ) {
if ( V_206 )
type = F_84 ( V_209 ) ;
else
type = F_84 ( V_210 ) ;
} else if ( F_96 ( & V_90 -> V_198 ) ) {
if ( V_206 )
type = F_84 ( V_211 ) ;
else
type = F_84 ( V_212 ) ;
} else {
type = 0 ;
}
return type ;
}
static T_3 F_103 ( struct V_2 * V_3 ,
struct V_136 * V_147 ,
struct V_196 * V_90 )
{
int V_213 ;
int V_214 ;
if ( F_94 ( & V_90 -> V_198 ) ||
F_95 ( & V_90 -> V_198 ) )
return 0 ;
if ( V_147 -> V_168 == V_169 )
return F_104 ( V_90 -> V_204 . V_215 ) ;
V_214 = F_105 ( F_106 ( & V_90 -> V_198 ) ) ;
V_213 = ( F_106 ( & V_90 -> V_198 ) & 0x1800 ) >> 11 ;
return V_214 * ( V_213 + 1 ) ;
}
int F_107 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_136 * V_147 ,
struct V_196 * V_90 ,
T_1 V_39 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
struct V_29 * V_164 ;
unsigned int V_214 ;
unsigned int V_213 ;
enum V_19 type ;
T_3 V_216 ;
T_3 V_217 ;
V_57 = F_108 ( & V_90 -> V_198 ) ;
V_114 = F_42 ( V_3 , V_56 -> V_158 , V_57 ) ;
V_217 = F_101 ( V_147 , V_90 ) ;
if ( ! V_217 )
return - V_177 ;
V_114 -> V_194 = F_5 ( V_217 ) ;
type = F_109 ( & V_90 -> V_198 ) ;
V_56 -> V_62 [ V_57 ] . V_218 =
F_29 ( V_3 , 2 , 1 , type , V_39 ) ;
if ( ! V_56 -> V_62 [ V_57 ] . V_218 ) {
if ( V_56 -> V_59 == 0 )
return - V_52 ;
V_56 -> V_62 [ V_57 ] . V_218 =
V_56 -> V_61 [ V_56 -> V_59 ] ;
V_56 -> V_61 [ V_56 -> V_59 ] = NULL ;
V_56 -> V_59 -- ;
F_33 ( V_3 , V_56 -> V_62 [ V_57 ] . V_218 ,
1 , type ) ;
}
V_56 -> V_62 [ V_57 ] . V_219 = false ;
V_164 = V_56 -> V_62 [ V_57 ] . V_218 ;
V_114 -> V_120 = F_10 ( V_164 -> V_43 -> V_7 | V_164 -> V_4 ) ;
V_114 -> V_117 = F_5 ( F_93 ( V_147 , V_90 )
| F_110 ( F_100 ( V_147 , V_90 ) ) ) ;
if ( ! F_97 ( & V_90 -> V_198 ) )
V_114 -> V_194 |= F_5 ( F_86 ( 3 ) ) ;
else
V_114 -> V_194 |= F_5 ( F_86 ( 0 ) ) ;
V_214 = F_105 ( F_106 ( & V_90 -> V_198 ) ) ;
V_213 = 0 ;
switch ( V_147 -> V_168 ) {
case V_169 :
V_213 = V_90 -> V_204 . V_220 ;
break;
case V_181 :
if ( F_95 ( & V_90 -> V_198 ) )
V_214 = 512 ;
if ( F_97 ( & V_90 -> V_198 ) ||
F_96 ( & V_90 -> V_198 ) ) {
V_213 = ( F_106 ( & V_90 -> V_198 )
& 0x1800 ) >> 11 ;
}
break;
case V_183 :
case V_185 :
break;
default:
F_98 () ;
}
V_114 -> V_194 |= F_5 ( F_81 ( V_214 ) |
F_85 ( V_213 ) ) ;
V_216 = F_103 ( V_3 , V_147 , V_90 ) ;
V_114 -> V_221 = F_5 ( F_111 ( V_216 ) ) ;
if ( F_94 ( & V_90 -> V_198 ) && V_3 -> V_222 == 0x100 )
V_114 -> V_221 |= F_5 ( F_112 ( 8 ) ) ;
else
V_114 -> V_221 |=
F_5 ( F_112 ( V_216 ) ) ;
return 0 ;
}
void F_113 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_196 * V_90 )
{
unsigned int V_57 ;
struct V_77 * V_114 ;
V_57 = F_108 ( & V_90 -> V_198 ) ;
V_114 = F_42 ( V_3 , V_56 -> V_158 , V_57 ) ;
V_114 -> V_117 = 0 ;
V_114 -> V_194 = 0 ;
V_114 -> V_120 = 0 ;
V_114 -> V_221 = 0 ;
}
void F_114 ( struct V_223 * V_224 )
{
V_224 -> V_225 = 0 ;
V_224 -> V_226 = 0 ;
V_224 -> V_227 = 0 ;
V_224 -> V_228 = 0 ;
V_224 -> type = 0 ;
V_224 -> V_216 = 0 ;
}
void F_115 ( struct V_2 * V_3 ,
struct V_67 * V_158 ,
struct V_75 * V_229 ,
struct V_55 * V_56 )
{
struct V_223 * V_224 ;
struct V_77 * V_114 ;
unsigned int V_230 ;
int V_8 ;
for ( V_8 = 1 ; V_8 < 31 ; ++ V_8 ) {
V_224 = & V_56 -> V_62 [ V_8 ] . V_224 ;
if ( ! F_116 ( V_229 , V_8 ) && F_117 ( V_229 , V_8 ) ) {
F_114 ( V_224 ) ;
continue;
}
if ( F_116 ( V_229 , V_8 ) ) {
V_114 = F_42 ( V_3 , V_158 , V_8 ) ;
V_230 = F_118 ( F_11 ( V_114 -> V_194 ) ) ;
if ( V_230 != V_210 && V_230 != V_212 &&
V_230 != V_209 &&
V_230 != V_211 )
continue;
V_224 -> V_225 = F_119 (
F_11 ( V_114 -> V_117 ) ) ;
V_224 -> V_226 = F_120 (
F_11 ( V_114 -> V_117 ) ) + 1 ;
V_224 -> V_227 = F_121 (
F_11 ( V_114 -> V_194 ) ) + 1 ;
V_224 -> V_228 = F_122 (
F_11 ( V_114 -> V_194 ) ) ;
V_224 -> type = V_230 ;
V_224 -> V_216 = F_123 (
F_11 ( V_114 -> V_221 ) ) ;
}
}
}
void F_124 ( struct V_2 * V_3 ,
struct V_67 * V_158 ,
struct V_67 * V_159 ,
unsigned int V_57 )
{
struct V_77 * V_231 ;
struct V_77 * V_232 ;
V_231 = F_42 ( V_3 , V_159 , V_57 ) ;
V_232 = F_42 ( V_3 , V_158 , V_57 ) ;
V_232 -> V_117 = V_231 -> V_117 ;
V_232 -> V_194 = V_231 -> V_194 ;
V_232 -> V_120 = V_231 -> V_120 ;
V_232 -> V_221 = V_231 -> V_221 ;
}
void F_125 ( struct V_2 * V_3 ,
struct V_67 * V_158 ,
struct V_67 * V_159 )
{
struct V_76 * V_233 ;
struct V_76 * V_234 ;
V_233 = F_41 ( V_3 , V_158 ) ;
V_234 = F_41 ( V_3 , V_159 ) ;
V_233 -> V_178 = V_234 -> V_178 ;
V_233 -> V_188 = V_234 -> V_188 ;
V_233 -> V_129 = V_234 -> V_129 ;
V_233 -> V_235 = V_234 -> V_235 ;
}
static int F_126 ( struct V_2 * V_3 , T_1 V_5 )
{
int V_8 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
int V_236 = F_127 ( V_3 -> V_237 ) ;
F_35 ( V_3 , V_238 ,
L_30 , V_236 ) ;
if ( ! V_236 )
return 0 ;
V_3 -> V_239 = F_2 ( sizeof( * V_3 -> V_239 ) , V_5 ) ;
if ( ! V_3 -> V_239 )
goto V_240;
V_3 -> V_239 -> V_241 = F_47 ( V_82 ,
V_236 * sizeof( T_5 ) ,
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
V_3 -> V_154 -> V_155 [ 0 ] = F_10 ( V_3 -> V_239 -> V_242 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
T_2 V_7 ;
void * V_248 = F_47 ( V_82 , V_3 -> V_249 , & V_7 ,
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
F_45 ( V_82 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
V_247:
F_4 ( V_3 -> V_239 -> V_244 ) ;
V_245:
F_45 ( V_82 , V_236 * sizeof( T_5 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
V_243:
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
V_240:
return - V_52 ;
}
static void F_128 ( struct V_2 * V_3 )
{
int V_236 ;
int V_8 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
if ( ! V_3 -> V_239 )
return;
V_236 = F_127 ( V_3 -> V_237 ) ;
for ( V_8 = 0 ; V_8 < V_236 ; V_8 ++ ) {
F_45 ( V_82 , V_3 -> V_249 ,
V_3 -> V_239 -> V_244 [ V_8 ] ,
V_3 -> V_239 -> V_246 [ V_8 ] ) ;
}
F_4 ( V_3 -> V_239 -> V_246 ) ;
F_4 ( V_3 -> V_239 -> V_244 ) ;
F_45 ( V_82 , V_236 * sizeof( T_5 ) ,
V_3 -> V_239 -> V_241 ,
V_3 -> V_239 -> V_242 ) ;
F_4 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
}
struct V_251 * F_51 ( struct V_2 * V_3 ,
bool V_252 , bool V_253 ,
T_1 V_39 )
{
struct V_251 * V_254 ;
V_254 = F_2 ( sizeof( * V_254 ) , V_39 ) ;
if ( ! V_254 )
return NULL ;
if ( V_252 ) {
V_254 -> V_158 =
F_36 ( V_3 , V_70 ,
V_39 ) ;
if ( ! V_254 -> V_158 ) {
F_4 ( V_254 ) ;
return NULL ;
}
}
if ( V_253 ) {
V_254 -> V_255 =
F_2 ( sizeof( struct V_255 ) , V_39 ) ;
if ( ! V_254 -> V_255 ) {
F_39 ( V_3 , V_254 -> V_158 ) ;
F_4 ( V_254 ) ;
return NULL ;
}
F_74 ( V_254 -> V_255 ) ;
}
V_254 -> V_256 = 0 ;
F_30 ( & V_254 -> V_257 ) ;
return V_254 ;
}
void F_129 ( struct V_2 * V_3 , struct V_258 * V_258 )
{
if ( V_258 ) {
F_4 ( V_258 -> V_259 [ 0 ] ) ;
F_4 ( V_258 ) ;
}
}
void F_54 ( struct V_2 * V_3 ,
struct V_251 * V_254 )
{
F_39 ( V_3 ,
V_254 -> V_158 ) ;
F_4 ( V_254 -> V_255 ) ;
F_4 ( V_254 ) ;
}
void F_130 ( struct V_2 * V_3 )
{
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
int V_71 ;
int V_8 , V_141 , V_140 ;
F_131 ( & V_3 -> V_260 ) ;
V_71 = sizeof( struct V_261 ) * ( V_3 -> V_262 . V_263 ) ;
if ( V_3 -> V_262 . V_264 )
F_45 ( V_82 , V_71 ,
V_3 -> V_262 . V_264 , V_3 -> V_262 . V_265 ) ;
V_3 -> V_262 . V_264 = NULL ;
F_35 ( V_3 , V_238 , L_31 ) ;
if ( V_3 -> V_266 )
F_26 ( V_3 , V_3 -> V_266 ) ;
V_3 -> V_266 = NULL ;
F_35 ( V_3 , V_238 , L_32 ) ;
if ( V_3 -> V_267 )
F_54 ( V_3 , V_3 -> V_267 ) ;
V_3 -> V_267 = NULL ;
if ( V_3 -> V_268 )
F_26 ( V_3 , V_3 -> V_268 ) ;
V_3 -> V_268 = NULL ;
F_35 ( V_3 , V_238 , L_33 ) ;
F_132 ( V_3 ) ;
V_140 = F_64 ( V_3 -> V_132 ) ;
for ( V_8 = 0 ; V_8 < V_140 && V_3 -> V_133 ; V_8 ++ ) {
struct V_144 * V_269 = & V_3 -> V_133 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ ) {
struct V_126 * V_90 = & V_269 -> V_150 [ V_141 ] . V_151 ;
while ( ! F_70 ( V_90 ) )
F_133 ( V_90 -> V_16 ) ;
}
}
for ( V_8 = 1 ; V_8 < V_270 ; ++ V_8 )
F_69 ( V_3 , V_8 ) ;
if ( V_3 -> V_10 )
F_134 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
F_35 ( V_3 , V_238 , L_34 ) ;
if ( V_3 -> V_74 )
F_134 ( V_3 -> V_74 ) ;
V_3 -> V_74 = NULL ;
F_35 ( V_3 , V_238 , L_35 ) ;
if ( V_3 -> V_87 )
F_134 ( V_3 -> V_87 ) ;
V_3 -> V_87 = NULL ;
F_35 ( V_3 , V_238 ,
L_36 ) ;
if ( V_3 -> V_88 )
F_134 ( V_3 -> V_88 ) ;
V_3 -> V_88 = NULL ;
F_35 ( V_3 , V_238 ,
L_37 ) ;
if ( V_3 -> V_154 )
F_45 ( V_82 , sizeof( * V_3 -> V_154 ) ,
V_3 -> V_154 , V_3 -> V_154 -> V_7 ) ;
V_3 -> V_154 = NULL ;
F_128 ( V_3 ) ;
if ( ! V_3 -> V_133 )
goto V_271;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_128 * V_139 , * V_272 ;
F_65 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_66 ( & V_139 -> V_135 ) ;
F_4 ( V_139 ) ;
}
}
V_271:
V_3 -> V_102 = 0 ;
V_3 -> V_273 = 0 ;
V_3 -> V_274 = 0 ;
V_3 -> V_275 = 0 ;
F_4 ( V_3 -> V_276 ) ;
F_4 ( V_3 -> V_277 ) ;
F_4 ( V_3 -> V_278 ) ;
F_4 ( V_3 -> V_133 ) ;
F_4 ( V_3 -> V_279 ) ;
V_3 -> V_249 = 0 ;
V_3 -> V_280 = 0 ;
V_3 -> V_281 [ 0 ] . V_282 = 0 ;
V_3 -> V_281 [ 1 ] . V_282 = 0 ;
}
static int F_135 ( struct V_2 * V_3 ,
struct V_1 * V_283 ,
union V_63 * V_284 ,
union V_63 * V_285 ,
T_2 V_286 ,
struct V_1 * V_287 ,
char * V_288 , int V_289 )
{
unsigned long long V_290 ;
unsigned long long V_291 ;
struct V_1 * V_6 ;
V_290 = F_59 ( V_283 , V_284 ) ;
V_291 = F_59 ( V_283 , V_285 ) ;
V_6 = F_136 ( V_283 , V_284 , V_285 , V_286 ) ;
if ( V_6 != V_287 ) {
F_71 ( V_3 , L_38 ,
V_288 , V_289 ) ;
F_71 ( V_3 , L_39
L_40 ,
V_283 ,
( unsigned long long ) V_286 ) ;
F_71 ( V_3 , L_41
L_42 ,
V_284 , V_290 ,
V_285 , V_291 ) ;
F_71 ( V_3 , L_43 ,
V_287 , V_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_137 ( struct V_2 * V_3 , T_1 V_39 )
{
struct {
T_2 V_286 ;
struct V_1 * V_287 ;
} V_292 [] = {
{ 0 , NULL } ,
{ V_3 -> V_266 -> V_43 -> V_7 - 16 , NULL } ,
{ V_3 -> V_266 -> V_43 -> V_7 - 1 , NULL } ,
{ V_3 -> V_266 -> V_43 -> V_7 , V_3 -> V_266 -> V_43 } ,
{ V_3 -> V_266 -> V_43 -> V_7 + ( V_12 - 1 ) * 16 ,
V_3 -> V_266 -> V_43 } ,
{ V_3 -> V_266 -> V_43 -> V_7 + ( V_12 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_266 -> V_43 -> V_7 + ( V_12 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_283 ;
union V_63 * V_284 ;
union V_63 * V_285 ;
T_2 V_286 ;
struct V_1 * V_287 ;
} V_293 [] = {
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = V_3 -> V_266 -> V_43 -> V_9 ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_268 -> V_43 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = V_3 -> V_266 -> V_43 -> V_9 ,
. V_285 = & V_3 -> V_268 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_268 -> V_43 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = V_3 -> V_268 -> V_43 -> V_9 ,
. V_285 = & V_3 -> V_268 -> V_43 -> V_9 [ V_12 - 1 ] ,
. V_286 = V_3 -> V_268 -> V_43 -> V_7 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = & V_3 -> V_266 -> V_43 -> V_9 [ 0 ] ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ 3 ] ,
. V_286 = V_3 -> V_266 -> V_43 -> V_7 + 4 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = & V_3 -> V_266 -> V_43 -> V_9 [ 3 ] ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ 6 ] ,
. V_286 = V_3 -> V_266 -> V_43 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_266 -> V_43 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_266 -> V_43 -> V_7 + ( V_12 - 4 ) * 16 ,
. V_287 = NULL ,
} ,
{ . V_283 = V_3 -> V_266 -> V_43 ,
. V_284 = & V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 3 ] ,
. V_285 = & V_3 -> V_266 -> V_43 -> V_9 [ 1 ] ,
. V_286 = V_3 -> V_268 -> V_43 -> V_7 + 2 * 16 ,
. V_287 = NULL ,
} ,
} ;
unsigned int V_294 ;
int V_8 , V_41 ;
V_294 = F_138 ( V_292 ) ;
for ( V_8 = 0 ; V_8 < V_294 ; V_8 ++ ) {
V_41 = F_135 ( V_3 ,
V_3 -> V_266 -> V_43 ,
V_3 -> V_266 -> V_43 -> V_9 ,
& V_3 -> V_266 -> V_43 -> V_9 [ V_12 - 1 ] ,
V_292 [ V_8 ] . V_286 ,
V_292 [ V_8 ] . V_287 ,
L_44 , V_8 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_294 = F_138 ( V_293 ) ;
for ( V_8 = 0 ; V_8 < V_294 ; V_8 ++ ) {
V_41 = F_135 ( V_3 ,
V_293 [ V_8 ] . V_283 ,
V_293 [ V_8 ] . V_284 ,
V_293 [ V_8 ] . V_285 ,
V_293 [ V_8 ] . V_286 ,
V_293 [ V_8 ] . V_287 ,
L_45 , V_8 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_32 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
T_5 V_295 ;
T_2 V_120 ;
V_120 = F_59 ( V_3 -> V_266 -> V_49 ,
V_3 -> V_266 -> V_48 ) ;
if ( V_120 == 0 && ! F_140 () )
F_71 ( V_3 , L_47
L_48 ) ;
V_295 = F_141 ( V_3 , & V_3 -> V_296 -> V_297 ) ;
V_295 &= V_298 ;
V_295 &= ~ V_299 ;
F_35 ( V_3 , V_238 ,
L_49
L_50 ) ;
F_142 ( V_3 , ( ( T_5 ) V_120 & ( T_5 ) ~ V_298 ) | V_295 ,
& V_3 -> V_296 -> V_297 ) ;
}
static void F_143 ( struct V_2 * V_3 , unsigned int V_140 ,
T_6 T_7 * V_101 , T_8 V_300 , int V_301 )
{
T_3 V_295 , V_302 , V_303 ;
int V_8 ;
if ( V_300 > 0x03 ) {
F_71 ( V_3 , L_51
L_52 ,
V_101 , V_300 ) ;
return;
}
V_295 = F_144 ( V_101 + 2 ) ;
V_302 = F_145 ( V_295 ) ;
V_303 = F_146 ( V_295 ) ;
F_35 ( V_3 , V_238 ,
L_53
L_54 ,
V_101 , V_302 , V_303 , V_300 ) ;
if ( V_302 == 0 || ( V_302 + V_303 - 1 ) > V_140 )
return;
if ( V_300 < 0x03 && V_3 -> V_304 < V_301 )
V_3 -> V_279 [ V_3 -> V_304 ++ ] = V_295 ;
if ( ( V_3 -> V_222 == 0x96 ) && ( V_300 != 0x03 ) &&
( V_295 & V_305 ) ) {
F_35 ( V_3 , V_238 ,
L_55 ) ;
V_3 -> V_306 = 1 ;
}
if ( ( V_3 -> V_222 >= 0x100 ) && ( V_300 != 0x03 ) ) {
F_35 ( V_3 , V_238 ,
L_56 ) ;
V_3 -> V_306 = 1 ;
if ( V_295 & V_307 ) {
F_35 ( V_3 , V_238 ,
L_57 ) ;
V_3 -> V_308 = 1 ;
}
}
V_302 -- ;
for ( V_8 = V_302 ; V_8 < ( V_302 + V_303 ) ; V_8 ++ ) {
if ( V_3 -> V_278 [ V_8 ] != 0 ) {
F_71 ( V_3 , L_58
L_59 , V_101 , V_8 ) ;
F_71 ( V_3 , L_60
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
static int F_147 ( struct V_2 * V_3 , T_1 V_5 )
{
T_6 T_7 * V_101 , * V_310 ;
T_3 V_311 , V_312 ;
unsigned int V_140 ;
int V_8 , V_141 , V_313 ;
int V_314 = 0 ;
V_101 = & V_3 -> V_315 -> V_72 ;
V_311 = F_148 ( F_144 ( V_101 ) ) ;
if ( V_311 == 0 ) {
F_149 ( V_3 , L_62
L_63 ) ;
return - V_316 ;
}
V_140 = F_64 ( V_3 -> V_132 ) ;
V_3 -> V_278 = F_2 ( sizeof( * V_3 -> V_278 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_278 )
return - V_52 ;
V_3 -> V_133 = F_2 ( sizeof( * V_3 -> V_133 ) * V_140 , V_5 ) ;
if ( ! V_3 -> V_133 )
return - V_52 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
struct V_144 * V_145 ;
F_30 ( & V_3 -> V_133 [ V_8 ] . V_134 ) ;
V_145 = & V_3 -> V_133 [ V_8 ] . V_145 ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_30 ( & V_145 -> V_150 [ V_141 ] . V_151 ) ;
}
V_101 = & V_3 -> V_315 -> V_317 + V_311 ;
V_310 = V_101 ;
V_312 = V_311 ;
do {
T_3 V_318 ;
V_318 = F_144 ( V_310 ) ;
if ( F_150 ( V_318 ) == V_319 )
V_314 ++ ;
V_312 = F_151 ( V_318 ) ;
V_310 += V_312 ;
} while ( V_312 );
V_3 -> V_279 = F_2 ( sizeof( * V_3 -> V_279 ) * V_314 , V_5 ) ;
if ( ! V_3 -> V_279 )
return - V_52 ;
while ( 1 ) {
T_3 V_318 ;
V_318 = F_144 ( V_101 ) ;
if ( F_150 ( V_318 ) == V_319 )
F_143 ( V_3 , V_140 , V_101 ,
( T_8 ) F_152 ( V_318 ) ,
V_314 ) ;
V_311 = F_151 ( V_318 ) ;
if ( ! V_311 || ( V_3 -> V_273 + V_3 -> V_274 )
== V_140 )
break;
V_101 += V_311 ;
}
if ( V_3 -> V_273 == 0 && V_3 -> V_274 == 0 ) {
F_71 ( V_3 , L_64 ) ;
return - V_316 ;
}
F_35 ( V_3 , V_238 ,
L_65 ,
V_3 -> V_273 , V_3 -> V_274 ) ;
if ( V_3 -> V_274 > 15 ) {
F_35 ( V_3 , V_238 ,
L_66 ) ;
V_3 -> V_274 = 15 ;
}
if ( V_3 -> V_273 > V_320 ) {
F_35 ( V_3 , V_238 ,
L_67 ,
V_320 ) ;
V_3 -> V_273 = V_320 ;
}
if ( V_3 -> V_273 ) {
V_3 -> V_276 = F_153 ( sizeof( * V_3 -> V_276 ) *
V_3 -> V_273 , V_5 ) ;
if ( ! V_3 -> V_276 )
return - V_52 ;
V_313 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ ) {
if ( V_3 -> V_278 [ V_8 ] == 0x03 ||
V_3 -> V_278 [ V_8 ] == 0 ||
V_3 -> V_278 [ V_8 ] == V_309 )
continue;
V_3 -> V_276 [ V_313 ] =
& V_3 -> V_321 -> V_322 +
V_323 * V_8 ;
F_35 ( V_3 , V_238 ,
L_68
L_69 , V_8 ,
V_3 -> V_276 [ V_313 ] ) ;
V_313 ++ ;
if ( V_313 == V_3 -> V_273 )
break;
}
}
if ( V_3 -> V_274 ) {
V_3 -> V_277 = F_153 ( sizeof( * V_3 -> V_277 ) *
V_3 -> V_274 , V_5 ) ;
if ( ! V_3 -> V_277 )
return - V_52 ;
V_313 = 0 ;
for ( V_8 = 0 ; V_8 < V_140 ; V_8 ++ )
if ( V_3 -> V_278 [ V_8 ] == 0x03 ) {
V_3 -> V_277 [ V_313 ] =
& V_3 -> V_321 -> V_322 +
V_323 * V_8 ;
F_35 ( V_3 , V_238 ,
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
int F_154 ( struct V_2 * V_3 , T_1 V_5 )
{
T_2 V_7 ;
struct V_81 * V_82 = F_44 ( V_3 ) -> V_83 . V_84 ;
unsigned int V_20 , V_324 ;
T_5 V_325 ;
struct V_1 * V_6 ;
T_3 V_249 , V_295 ;
int V_8 ;
F_30 ( & V_3 -> V_257 ) ;
V_249 = F_144 ( & V_3 -> V_321 -> V_249 ) ;
F_35 ( V_3 , V_238 ,
L_71 , V_249 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( ( 0x1 & V_249 ) != 0 )
break;
V_249 = V_249 >> 1 ;
}
if ( V_8 < 16 )
F_35 ( V_3 , V_238 ,
L_72 , ( 1 << ( V_8 + 12 ) ) / 1024 ) ;
else
F_71 ( V_3 , L_73 ) ;
V_3 -> V_280 = 12 ;
V_3 -> V_249 = 1 << V_3 -> V_280 ;
F_35 ( V_3 , V_238 ,
L_74 , V_3 -> V_249 / 1024 ) ;
V_20 = F_155 ( F_144 ( & V_3 -> V_315 -> V_132 ) ) ;
F_35 ( V_3 , V_238 ,
L_75 , V_20 ) ;
V_324 = F_144 ( & V_3 -> V_321 -> V_326 ) ;
V_20 |= ( V_324 & ~ V_327 ) ;
F_35 ( V_3 , V_238 ,
L_76 , V_20 ) ;
F_156 ( V_20 , & V_3 -> V_321 -> V_326 ) ;
V_3 -> V_154 = F_47 ( V_82 , sizeof( * V_3 -> V_154 ) , & V_7 ,
V_328 ) ;
if ( ! V_3 -> V_154 )
goto V_54;
memset ( V_3 -> V_154 , 0 , sizeof *( V_3 -> V_154 ) ) ;
V_3 -> V_154 -> V_7 = V_7 ;
F_35 ( V_3 , V_238 ,
L_77 ,
( unsigned long long ) V_3 -> V_154 -> V_7 , V_3 -> V_154 ) ;
F_142 ( V_3 , V_7 , & V_3 -> V_321 -> V_329 ) ;
V_3 -> V_10 = F_157 ( L_78 , V_82 ,
V_11 , V_11 , V_3 -> V_249 ) ;
V_3 -> V_74 = F_157 ( L_79 , V_82 ,
2112 , 64 , V_3 -> V_249 ) ;
if ( ! V_3 -> V_10 || ! V_3 -> V_74 )
goto V_54;
V_3 -> V_87 =
F_157 ( L_80 ,
V_82 , V_86 , 16 , 0 ) ;
V_3 -> V_88 =
F_157 ( L_81 ,
V_82 , V_85 , 16 , 0 ) ;
if ( ! V_3 -> V_87 || ! V_3 -> V_88 )
goto V_54;
V_3 -> V_268 = F_29 ( V_3 , 1 , 1 , V_330 , V_5 ) ;
if ( ! V_3 -> V_268 )
goto V_54;
F_35 ( V_3 , V_238 ,
L_82 , V_3 -> V_268 ) ;
F_35 ( V_3 , V_238 , L_83 ,
( unsigned long long ) V_3 -> V_268 -> V_43 -> V_7 ) ;
V_325 = F_141 ( V_3 , & V_3 -> V_321 -> V_268 ) ;
V_325 = ( V_325 & ( T_5 ) V_331 ) |
( V_3 -> V_268 -> V_43 -> V_7 & ( T_5 ) ~ V_331 ) |
V_3 -> V_268 -> V_4 ;
F_35 ( V_3 , V_238 ,
L_84 , V_20 ) ;
F_142 ( V_3 , V_325 , & V_3 -> V_321 -> V_268 ) ;
F_158 ( V_3 ) ;
V_3 -> V_267 = F_51 ( V_3 , true , true , V_5 ) ;
if ( ! V_3 -> V_267 )
goto V_54;
V_3 -> V_102 ++ ;
V_20 = F_144 ( & V_3 -> V_315 -> V_332 ) ;
V_20 &= V_333 ;
F_35 ( V_3 , V_238 ,
L_85
L_86 , V_20 ) ;
V_3 -> V_334 = ( void T_7 * ) V_3 -> V_315 + V_20 ;
F_159 ( V_3 ) ;
F_160 ( V_3 ) ;
V_3 -> V_296 = & V_3 -> V_335 -> V_296 [ 0 ] ;
F_35 ( V_3 , V_238 , L_87 ) ;
V_3 -> V_266 = F_29 ( V_3 , V_336 , 1 , V_21 ,
V_5 ) ;
if ( ! V_3 -> V_266 )
goto V_54;
if ( F_137 ( V_3 , V_5 ) < 0 )
goto V_54;
V_3 -> V_262 . V_264 = F_47 ( V_82 ,
sizeof( struct V_261 ) * V_336 , & V_7 ,
V_328 ) ;
if ( ! V_3 -> V_262 . V_264 )
goto V_54;
F_35 ( V_3 , V_238 ,
L_88 ,
( unsigned long long ) V_7 ) ;
memset ( V_3 -> V_262 . V_264 , 0 , sizeof( struct V_261 ) * V_336 ) ;
V_3 -> V_262 . V_263 = V_336 ;
V_3 -> V_262 . V_265 = V_7 ;
F_35 ( V_3 , V_238 ,
L_89 ,
V_3 -> V_262 . V_263 ,
V_3 -> V_262 . V_264 ,
( unsigned long long ) V_3 -> V_262 . V_265 ) ;
for ( V_20 = 0 , V_6 = V_3 -> V_266 -> V_43 ; V_20 < V_336 ; V_20 ++ ) {
struct V_261 * V_337 = & V_3 -> V_262 . V_264 [ V_20 ] ;
V_337 -> V_338 = F_10 ( V_6 -> V_7 ) ;
V_337 -> V_339 = F_5 ( V_12 ) ;
V_337 -> V_340 = 0 ;
V_6 = V_6 -> V_16 ;
}
V_20 = F_144 ( & V_3 -> V_296 -> V_341 ) ;
V_20 &= V_342 ;
V_20 |= V_336 ;
F_35 ( V_3 , V_238 ,
L_90 ,
V_20 ) ;
F_156 ( V_20 , & V_3 -> V_296 -> V_341 ) ;
F_35 ( V_3 , V_238 ,
L_91 ) ;
F_35 ( V_3 , V_238 ,
L_92 ,
( unsigned long long ) V_3 -> V_262 . V_265 ) ;
V_325 = F_141 ( V_3 , & V_3 -> V_296 -> V_343 ) ;
V_325 &= V_298 ;
V_325 |= ( V_3 -> V_262 . V_265 & ( T_5 ) ~ V_298 ) ;
F_142 ( V_3 , V_325 , & V_3 -> V_296 -> V_343 ) ;
F_139 ( V_3 ) ;
F_35 ( V_3 , V_238 ,
L_93 ) ;
F_161 ( V_3 , 0 ) ;
F_62 ( & V_3 -> V_260 ) ;
V_3 -> V_260 . V_122 = ( unsigned long ) V_3 ;
V_3 -> V_260 . V_123 = V_344 ;
F_74 ( & V_3 -> V_345 ) ;
for ( V_8 = 0 ; V_8 < V_270 ; ++ V_8 )
V_3 -> V_153 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_320 ; ++ V_8 ) {
V_3 -> V_281 [ 0 ] . V_346 [ V_8 ] = 0 ;
V_3 -> V_281 [ 1 ] . V_346 [ V_8 ] = 0 ;
F_74 ( & V_3 -> V_281 [ 1 ] . V_347 [ V_8 ] ) ;
}
if ( F_126 ( V_3 , V_5 ) )
goto V_54;
if ( F_147 ( V_3 , V_5 ) )
goto V_54;
V_295 = F_144 ( & V_3 -> V_321 -> V_348 ) ;
V_295 &= ~ V_349 ;
V_295 |= V_350 ;
F_156 ( V_295 , & V_3 -> V_321 -> V_348 ) ;
return 0 ;
V_54:
F_71 ( V_3 , L_94 ) ;
F_162 ( V_3 ) ;
F_163 ( V_3 ) ;
F_130 ( V_3 ) ;
return - V_52 ;
}
