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
V_7 -> V_12 = F_2 ( V_5 , V_6 | V_13 ) ;
if ( ! V_7 -> V_12 ) {
F_5 ( V_3 -> V_11 , V_7 -> V_10 , V_8 ) ;
F_4 ( V_7 ) ;
return NULL ;
}
}
if ( V_4 == 0 ) {
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ )
V_7 -> V_10 [ V_9 ] . V_15 . V_16 |= F_6 ( V_17 ) ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_18 = NULL ;
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
struct V_1 * V_19 )
{
struct V_1 * V_7 ;
V_7 = V_19 -> V_18 ;
while ( V_7 != V_19 ) {
struct V_1 * V_18 = V_7 -> V_18 ;
F_7 ( V_3 , V_7 ) ;
V_7 = V_18 ;
}
F_7 ( V_3 , V_19 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_1 * V_20 ,
struct V_1 * V_18 , enum V_21 type )
{
T_3 V_22 ;
if ( ! V_20 || ! V_18 )
return;
V_20 -> V_18 = V_18 ;
if ( type != V_23 ) {
V_20 -> V_10 [ V_14 - 1 ] . V_15 . V_24 =
F_10 ( V_18 -> V_8 ) ;
V_22 = F_11 ( V_20 -> V_10 [ V_14 - 1 ] . V_15 . V_16 ) ;
V_22 &= ~ V_25 ;
V_22 |= F_12 ( V_26 ) ;
if ( F_13 ( V_3 ) ||
( type == V_27 &&
( V_3 -> V_28 & V_29 ) ) )
V_22 |= V_30 ;
V_20 -> V_10 [ V_14 - 1 ] . V_15 . V_16 = F_6 ( V_22 ) ;
}
}
static void F_14 ( struct V_2 * V_3 , struct V_31 * V_32 ,
struct V_1 * V_19 , struct V_1 * V_33 ,
unsigned int V_34 )
{
struct V_1 * V_18 ;
if ( ! V_32 || ! V_19 || ! V_33 )
return;
V_18 = V_32 -> V_35 -> V_18 ;
F_9 ( V_3 , V_32 -> V_35 , V_19 , V_32 -> type ) ;
F_9 ( V_3 , V_33 , V_18 , V_32 -> type ) ;
V_32 -> V_34 += V_34 ;
V_32 -> V_36 += ( V_14 - 1 ) * V_34 ;
if ( V_32 -> type != V_23 && V_32 -> V_35 == V_32 -> V_37 ) {
V_32 -> V_37 -> V_10 [ V_14 - 1 ] . V_15 . V_16
&= ~ F_6 ( V_38 ) ;
V_33 -> V_10 [ V_14 - 1 ] . V_15 . V_16
|= F_6 ( V_38 ) ;
V_32 -> V_37 = V_33 ;
}
}
static int F_15 ( struct V_39 * V_40 ,
struct V_31 * V_32 ,
struct V_1 * V_7 ,
T_1 V_41 )
{
unsigned long V_42 ;
int V_43 ;
V_42 = ( unsigned long ) ( V_7 -> V_8 >> V_44 ) ;
if ( F_16 ( V_40 , V_42 ) )
return 0 ;
V_43 = F_17 ( V_41 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_18 ( V_40 ,
V_42 , V_32 ) ;
F_19 () ;
return V_43 ;
}
static void F_20 ( struct V_39 * V_40 ,
struct V_1 * V_7 )
{
unsigned long V_42 ;
V_42 = ( unsigned long ) ( V_7 -> V_8 >> V_44 ) ;
if ( F_16 ( V_40 , V_42 ) )
F_21 ( V_40 , V_42 ) ;
}
static int F_22 (
struct V_39 * V_40 ,
struct V_31 * V_32 ,
struct V_1 * V_45 ,
struct V_1 * V_37 ,
T_1 V_41 )
{
struct V_1 * V_7 ;
struct V_1 * V_46 ;
int V_43 ;
if ( F_23 ( V_40 == NULL ) )
return 0 ;
V_7 = V_45 ;
do {
V_43 = F_15 ( V_40 ,
V_32 , V_7 , V_41 ) ;
if ( V_43 )
goto V_47;
if ( V_7 == V_37 )
return 0 ;
V_7 = V_7 -> V_18 ;
} while ( V_7 != V_45 );
return 0 ;
V_47:
V_46 = V_7 ;
V_7 = V_45 ;
do {
F_20 ( V_40 , V_7 ) ;
if ( V_7 == V_46 )
return V_43 ;
V_7 = V_7 -> V_18 ;
} while ( V_7 != V_45 );
return V_43 ;
}
static void F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_7 ;
if ( F_23 ( V_32 -> V_40 == NULL ) )
return;
V_7 = V_32 -> V_45 ;
do {
F_20 ( V_32 -> V_40 , V_7 ) ;
V_7 = V_7 -> V_18 ;
} while ( V_7 != V_32 -> V_45 );
}
static int F_25 ( struct V_31 * V_32 , T_1 V_41 )
{
return F_22 ( V_32 -> V_40 , V_32 ,
V_32 -> V_45 , V_32 -> V_37 , V_41 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
if ( ! V_32 )
return;
if ( V_32 -> V_45 ) {
if ( V_32 -> type == V_48 )
F_24 ( V_32 ) ;
F_8 ( V_3 , V_32 -> V_45 ) ;
}
F_4 ( V_32 ) ;
}
static void F_27 ( struct V_31 * V_32 ,
unsigned int V_4 )
{
V_32 -> V_49 = V_32 -> V_45 -> V_10 ;
V_32 -> V_35 = V_32 -> V_45 ;
V_32 -> V_50 = V_32 -> V_49 ;
V_32 -> V_51 = V_32 -> V_45 ;
V_32 -> V_4 = V_4 ;
V_32 -> V_52 = 0 ;
V_32 -> V_53 = 0 ;
V_32 -> V_36 = V_32 -> V_34 * ( V_14 - 1 ) - 1 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * * V_19 , struct V_1 * * V_33 ,
unsigned int V_34 , unsigned int V_4 ,
enum V_21 type , unsigned int V_5 , T_1 V_6 )
{
struct V_1 * V_20 ;
V_20 = F_1 ( V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_20 )
return - V_54 ;
V_34 -- ;
* V_19 = V_20 ;
while ( V_34 > 0 ) {
struct V_1 * V_18 ;
V_18 = F_1 ( V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_18 ) {
V_20 = * V_19 ;
while ( V_20 ) {
V_18 = V_20 -> V_18 ;
F_7 ( V_3 , V_20 ) ;
V_20 = V_18 ;
}
return - V_54 ;
}
F_9 ( V_3 , V_20 , V_18 , type ) ;
V_20 = V_18 ;
V_34 -- ;
}
F_9 ( V_3 , V_20 , * V_19 , type ) ;
* V_33 = V_20 ;
return 0 ;
}
static struct V_31 * F_29 ( struct V_2 * V_3 ,
unsigned int V_34 , unsigned int V_4 ,
enum V_21 type , unsigned int V_5 , T_1 V_6 )
{
struct V_31 * V_32 ;
int V_43 ;
V_32 = F_2 ( sizeof *( V_32 ) , V_6 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_34 = V_34 ;
V_32 -> V_55 = V_5 ;
F_30 ( & V_32 -> V_56 ) ;
V_32 -> type = type ;
if ( V_34 == 0 )
return V_32 ;
V_43 = F_28 ( V_3 , & V_32 -> V_45 ,
& V_32 -> V_37 , V_34 , V_4 , type ,
V_5 , V_6 ) ;
if ( V_43 )
goto V_57;
if ( type != V_23 ) {
V_32 -> V_37 -> V_10 [ V_14 - 1 ] . V_15 . V_16 |=
F_6 ( V_38 ) ;
}
F_27 ( V_32 , V_4 ) ;
return V_32 ;
V_57:
F_4 ( V_32 ) ;
return NULL ;
}
void F_31 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
unsigned int V_60 )
{
int V_61 ;
V_61 = V_59 -> V_62 ;
if ( V_61 < V_63 ) {
V_59 -> V_64 [ V_61 ] =
V_59 -> V_65 [ V_60 ] . V_32 ;
V_59 -> V_62 ++ ;
F_32 ( V_3 , L_1
L_2 ,
V_59 -> V_62 ,
( V_59 -> V_62 > 1 ) ? L_3 : L_4 ) ;
} else {
F_26 ( V_3 , V_59 -> V_65 [ V_60 ] . V_32 ) ;
F_32 ( V_3 , L_5
L_6 ,
V_59 -> V_62 ) ;
}
V_59 -> V_65 [ V_60 ] . V_32 = NULL ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_31 * V_32 , unsigned int V_4 ,
enum V_21 type )
{
struct V_1 * V_7 = V_32 -> V_45 ;
int V_9 ;
do {
memset ( V_7 -> V_10 , 0 ,
sizeof( union V_66 ) * V_14 ) ;
if ( V_4 == 0 ) {
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ )
V_7 -> V_10 [ V_9 ] . V_15 . V_16 |=
F_6 ( V_17 ) ;
}
F_9 ( V_3 , V_7 , V_7 -> V_18 , type ) ;
V_7 = V_7 -> V_18 ;
} while ( V_7 != V_32 -> V_45 );
V_32 -> type = type ;
F_27 ( V_32 , V_4 ) ;
F_30 ( & V_32 -> V_56 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_31 * V_32 ,
unsigned int V_67 , T_1 V_6 )
{
struct V_1 * V_19 ;
struct V_1 * V_33 ;
unsigned int V_34 ;
unsigned int V_68 ;
int V_43 ;
V_68 = ( V_67 + ( V_14 - 1 ) - 1 ) /
( V_14 - 1 ) ;
V_34 = V_32 -> V_34 > V_68 ?
V_32 -> V_34 : V_68 ;
V_43 = F_28 ( V_3 , & V_19 , & V_33 ,
V_34 , V_32 -> V_4 , V_32 -> type ,
V_32 -> V_55 , V_6 ) ;
if ( V_43 )
return - V_54 ;
if ( V_32 -> type == V_48 )
V_43 = F_22 ( V_32 -> V_40 ,
V_32 , V_19 , V_33 , V_6 ) ;
if ( V_43 ) {
struct V_1 * V_18 ;
do {
V_18 = V_19 -> V_18 ;
F_7 ( V_3 , V_19 ) ;
if ( V_19 == V_33 )
break;
V_19 = V_18 ;
} while ( true );
return V_43 ;
}
F_14 ( V_3 , V_32 , V_19 , V_33 , V_34 ) ;
F_35 ( V_3 , V_69 ,
L_7 ,
V_32 -> V_34 ) ;
return 0 ;
}
static struct V_70 * F_36 ( struct V_2 * V_3 ,
int type , T_1 V_6 )
{
struct V_70 * V_71 ;
if ( ( type != V_72 ) && ( type != V_73 ) )
return NULL ;
V_71 = F_2 ( sizeof( * V_71 ) , V_6 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> type = type ;
V_71 -> V_74 = F_37 ( V_3 -> V_75 ) ? 2048 : 1024 ;
if ( type == V_73 )
V_71 -> V_74 += F_38 ( V_3 -> V_75 ) ;
V_71 -> V_76 = F_3 ( V_3 -> V_77 , V_6 , & V_71 -> V_8 ) ;
if ( ! V_71 -> V_76 ) {
F_4 ( V_71 ) ;
return NULL ;
}
return V_71 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
if ( ! V_71 )
return;
F_5 ( V_3 -> V_77 , V_71 -> V_76 , V_71 -> V_8 ) ;
F_4 ( V_71 ) ;
}
struct V_78 * F_40 (
struct V_70 * V_71 )
{
if ( V_71 -> type != V_73 )
return NULL ;
return (struct V_78 * ) V_71 -> V_76 ;
}
struct V_79 * F_41 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
if ( V_71 -> type == V_72 )
return (struct V_79 * ) V_71 -> V_76 ;
return (struct V_79 * )
( V_71 -> V_76 + F_38 ( V_3 -> V_75 ) ) ;
}
struct V_80 * F_42 ( struct V_2 * V_3 ,
struct V_70 * V_71 ,
unsigned int V_60 )
{
V_60 ++ ;
if ( V_71 -> type == V_73 )
V_60 ++ ;
return (struct V_80 * )
( V_71 -> V_76 + ( V_60 * F_38 ( V_3 -> V_75 ) ) ) ;
}
static void F_43 ( struct V_2 * V_3 ,
unsigned int V_81 ,
struct V_82 * V_83 , T_2 V_8 )
{
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
T_4 V_74 = sizeof( struct V_82 ) * V_81 ;
if ( V_74 > V_88 )
F_45 ( V_85 , V_74 ,
V_83 , V_8 ) ;
else if ( V_74 <= V_89 )
return F_5 ( V_3 -> V_90 ,
V_83 , V_8 ) ;
else
return F_5 ( V_3 -> V_91 ,
V_83 , V_8 ) ;
}
static struct V_82 * F_46 ( struct V_2 * V_3 ,
unsigned int V_81 , T_2 * V_8 ,
T_1 V_41 )
{
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
T_4 V_74 = sizeof( struct V_82 ) * V_81 ;
if ( V_74 > V_88 )
return F_47 ( V_85 , V_74 ,
V_8 , V_41 ) ;
else if ( V_74 <= V_89 )
return F_48 ( V_3 -> V_90 ,
V_41 , V_8 ) ;
else
return F_48 ( V_3 -> V_91 ,
V_41 , V_8 ) ;
}
struct V_31 * F_49 (
struct V_92 * V_93 ,
T_5 V_94 )
{
if ( V_93 -> V_95 & V_96 )
return F_16 ( & V_93 -> V_97 -> V_40 ,
V_94 >> V_44 ) ;
return V_93 -> V_32 ;
}
struct V_31 * F_50 (
struct V_58 * V_85 ,
unsigned int V_60 ,
unsigned int V_98 )
{
struct V_92 * V_93 = & V_85 -> V_65 [ V_60 ] ;
if ( V_98 == 0 )
return V_93 -> V_32 ;
if ( ! V_93 -> V_97 )
return NULL ;
if ( V_98 > V_93 -> V_97 -> V_99 )
return NULL ;
return V_93 -> V_97 -> V_100 [ V_98 ] ;
}
struct V_101 * F_51 ( struct V_2 * V_3 ,
unsigned int V_81 ,
unsigned int V_99 ,
unsigned int V_5 , T_1 V_41 )
{
struct V_101 * V_97 ;
T_3 V_102 ;
struct V_31 * V_103 ;
T_5 V_104 ;
int V_43 ;
F_32 ( V_3 , L_8
L_9 ,
V_99 , V_81 ) ;
if ( V_3 -> V_105 == V_106 ) {
F_32 ( V_3 , L_10 ) ;
return NULL ;
}
V_3 -> V_105 ++ ;
V_97 = F_2 ( sizeof( struct V_101 ) , V_41 ) ;
if ( ! V_97 )
goto V_107;
V_97 -> V_99 = V_99 ;
V_97 -> V_81 = V_81 ;
V_97 -> V_100 = F_2 (
sizeof( struct V_31 * ) * V_99 ,
V_41 ) ;
if ( ! V_97 -> V_100 )
goto V_108;
V_97 -> V_109 = F_46 ( V_3 ,
V_81 , & V_97 -> V_110 ,
V_41 ) ;
if ( ! V_97 -> V_109 )
goto V_111;
memset ( V_97 -> V_109 , 0 ,
sizeof( struct V_82 ) * V_81 ) ;
V_97 -> V_112 =
F_52 ( V_3 , true , true , V_41 ) ;
if ( ! V_97 -> V_112 )
goto V_111;
F_53 ( & V_97 -> V_40 , V_113 ) ;
for ( V_102 = 1 ; V_102 < V_99 ; V_102 ++ ) {
V_97 -> V_100 [ V_102 ] =
F_29 ( V_3 , 2 , 1 , V_48 , V_5 ,
V_41 ) ;
V_103 = V_97 -> V_100 [ V_102 ] ;
if ( ! V_103 )
goto V_114;
V_103 -> V_98 = V_102 ;
V_103 -> V_40 = & V_97 -> V_40 ;
V_104 = V_103 -> V_45 -> V_8 |
F_54 ( V_115 ) |
V_103 -> V_4 ;
V_97 -> V_109 [ V_102 ] . V_116 =
F_10 ( V_104 ) ;
F_32 ( V_3 , L_11 ,
V_102 , ( unsigned long long ) V_104 ) ;
V_43 = F_25 ( V_103 , V_41 ) ;
if ( V_43 ) {
F_26 ( V_3 , V_103 ) ;
V_97 -> V_100 [ V_102 ] = NULL ;
goto V_114;
}
}
return V_97 ;
V_114:
for ( V_102 = 1 ; V_102 < V_99 ; V_102 ++ ) {
V_103 = V_97 -> V_100 [ V_102 ] ;
if ( V_103 ) {
F_26 ( V_3 , V_103 ) ;
V_97 -> V_100 [ V_102 ] = NULL ;
}
}
F_55 ( V_3 , V_97 -> V_112 ) ;
V_111:
F_4 ( V_97 -> V_100 ) ;
V_108:
F_4 ( V_97 ) ;
V_107:
V_3 -> V_105 -- ;
return NULL ;
}
void F_56 ( struct V_2 * V_3 ,
struct V_80 * V_117 ,
struct V_101 * V_97 )
{
T_3 V_118 ;
V_118 = F_57 ( V_97 -> V_81 ) - 2 ;
F_35 ( V_3 , V_119 ,
L_12 ,
1 << ( V_118 + 1 ) ) ;
V_117 -> V_120 &= F_6 ( ~ V_121 ) ;
V_117 -> V_120 |= F_6 ( F_58 ( V_118 )
| V_122 ) ;
V_117 -> V_123 = F_10 ( V_97 -> V_110 ) ;
}
void F_59 ( struct V_80 * V_117 ,
struct V_92 * V_93 )
{
T_2 V_104 ;
V_117 -> V_120 &= F_6 ( ~ ( V_121 | V_122 ) ) ;
V_104 = F_60 ( V_93 -> V_32 -> V_51 , V_93 -> V_32 -> V_50 ) ;
V_117 -> V_123 = F_10 ( V_104 | V_93 -> V_32 -> V_4 ) ;
}
void F_61 ( struct V_2 * V_3 ,
struct V_101 * V_97 )
{
int V_102 ;
struct V_31 * V_103 ;
if ( ! V_97 )
return;
for ( V_102 = 1 ; V_102 < V_97 -> V_99 ;
V_102 ++ ) {
V_103 = V_97 -> V_100 [ V_102 ] ;
if ( V_103 ) {
F_26 ( V_3 , V_103 ) ;
V_97 -> V_100 [ V_102 ] = NULL ;
}
}
F_55 ( V_3 , V_97 -> V_112 ) ;
V_3 -> V_105 -- ;
if ( V_97 -> V_109 )
F_43 ( V_3 ,
V_97 -> V_81 ,
V_97 -> V_109 ,
V_97 -> V_110 ) ;
F_4 ( V_97 -> V_100 ) ;
F_4 ( V_97 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_92 * V_93 )
{
F_63 ( & V_93 -> V_124 , V_125 ,
( unsigned long ) V_93 ) ;
V_93 -> V_3 = V_3 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
int V_126 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 , * V_18 ;
bool V_131 = false ;
if ( V_59 -> V_132 == 0 ||
V_59 -> V_132 > F_65 ( V_3 -> V_133 ) ) {
F_32 ( V_3 , L_13 ) ;
return;
}
V_128 = & ( V_3 -> V_134 [ V_59 -> V_132 - 1 ] . V_135 ) ;
F_66 (tt_info, next, tt_list_head, tt_list) {
if ( V_130 -> V_126 == V_126 ) {
V_131 = true ;
F_67 ( & V_130 -> V_136 ) ;
F_4 ( V_130 ) ;
} else if ( V_131 ) {
break;
}
}
}
int F_68 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
struct V_137 * V_138 ,
struct V_139 * V_140 , T_1 V_41 )
{
struct V_129 * V_130 ;
unsigned int V_141 ;
int V_9 , V_142 ;
if ( ! V_140 -> V_143 )
V_141 = 1 ;
else
V_141 = V_138 -> V_144 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ , V_130 ++ ) {
struct V_145 * V_146 ;
V_130 = F_2 ( sizeof( * V_130 ) , V_41 ) ;
if ( ! V_130 )
goto V_147;
F_30 ( & V_130 -> V_136 ) ;
F_69 ( & V_130 -> V_136 ,
& V_3 -> V_134 [ V_59 -> V_132 - 1 ] . V_135 ) ;
V_130 -> V_126 = V_59 -> V_148 -> V_126 ;
if ( V_140 -> V_143 )
V_130 -> V_149 = V_9 + 1 ;
V_146 = & V_130 -> V_146 ;
for ( V_142 = 0 ; V_142 < V_150 ; V_142 ++ )
F_30 ( & V_146 -> V_151 [ V_142 ] . V_152 ) ;
}
return 0 ;
V_147:
F_64 ( V_3 , V_59 , V_59 -> V_148 -> V_126 ) ;
return - V_54 ;
}
void F_70 ( struct V_2 * V_3 , int V_126 )
{
struct V_58 * V_85 ;
int V_9 ;
int V_153 = 0 ;
if ( V_126 == 0 || ! V_3 -> V_154 [ V_126 ] )
return;
V_85 = V_3 -> V_154 [ V_126 ] ;
F_71 ( V_85 ) ;
V_3 -> V_155 -> V_156 [ V_126 ] = 0 ;
if ( ! V_85 )
return;
if ( V_85 -> V_130 )
V_153 = V_85 -> V_130 -> V_157 ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
if ( V_85 -> V_65 [ V_9 ] . V_32 )
F_26 ( V_3 , V_85 -> V_65 [ V_9 ] . V_32 ) ;
if ( V_85 -> V_65 [ V_9 ] . V_97 )
F_61 ( V_3 ,
V_85 -> V_65 [ V_9 ] . V_97 ) ;
if ( ! F_72 ( & V_85 -> V_65 [ V_9 ] . V_158 ) )
F_73 ( V_3 , L_14
L_15 ,
V_126 , V_9 ) ;
}
F_64 ( V_3 , V_85 , V_126 ) ;
F_74 ( V_3 , V_85 , V_153 ) ;
if ( V_85 -> V_64 ) {
for ( V_9 = 0 ; V_9 < V_85 -> V_62 ; V_9 ++ )
F_26 ( V_3 , V_85 -> V_64 [ V_9 ] ) ;
F_4 ( V_85 -> V_64 ) ;
}
if ( V_85 -> V_159 )
F_39 ( V_3 , V_85 -> V_159 ) ;
if ( V_85 -> V_160 )
F_39 ( V_3 , V_85 -> V_160 ) ;
F_4 ( V_3 -> V_154 [ V_126 ] ) ;
V_3 -> V_154 [ V_126 ] = NULL ;
}
void F_75 ( struct V_2 * V_3 , int V_126 )
{
struct V_58 * V_161 ;
struct V_127 * V_128 ;
struct V_129 * V_130 , * V_18 ;
int V_9 ;
V_161 = V_3 -> V_154 [ V_126 ] ;
if ( ! V_161 )
return;
V_128 = & ( V_3 -> V_134 [ V_161 -> V_132 - 1 ] . V_135 ) ;
F_66 (tt_info, next, tt_list_head, tt_list) {
if ( V_130 -> V_126 == V_126 ) {
for ( V_9 = 1 ; V_9 < F_76 ( V_3 -> V_133 ) ; V_9 ++ ) {
V_161 = V_3 -> V_154 [ V_9 ] ;
if ( V_161 && ( V_161 -> V_130 == V_130 ) )
F_75 (
V_3 , V_9 ) ;
}
}
}
F_70 ( V_3 , V_126 ) ;
}
int F_77 ( struct V_2 * V_3 , int V_126 ,
struct V_137 * V_148 , T_1 V_6 )
{
struct V_58 * V_85 ;
int V_9 ;
if ( V_126 == 0 || V_3 -> V_154 [ V_126 ] ) {
F_73 ( V_3 , L_16 , V_126 ) ;
return 0 ;
}
V_3 -> V_154 [ V_126 ] = F_2 ( sizeof( * V_3 -> V_154 [ V_126 ] ) , V_6 ) ;
if ( ! V_3 -> V_154 [ V_126 ] )
return 0 ;
V_85 = V_3 -> V_154 [ V_126 ] ;
V_85 -> V_160 = F_36 ( V_3 , V_72 , V_6 ) ;
if ( ! V_85 -> V_160 )
goto V_57;
F_32 ( V_3 , L_17 , V_126 ,
( unsigned long long ) V_85 -> V_160 -> V_8 ) ;
V_85 -> V_159 = F_36 ( V_3 , V_73 , V_6 ) ;
if ( ! V_85 -> V_159 )
goto V_57;
F_32 ( V_3 , L_18 , V_126 ,
( unsigned long long ) V_85 -> V_159 -> V_8 ) ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
F_62 ( V_3 , & V_85 -> V_65 [ V_9 ] ) ;
F_30 ( & V_85 -> V_65 [ V_9 ] . V_162 ) ;
F_30 ( & V_85 -> V_65 [ V_9 ] . V_158 ) ;
}
V_85 -> V_65 [ 0 ] . V_32 = F_29 ( V_3 , 2 , 1 , V_163 , 0 , V_6 ) ;
if ( ! V_85 -> V_65 [ 0 ] . V_32 )
goto V_57;
V_85 -> V_64 = F_2 (
sizeof( struct V_31 * ) * V_63 ,
V_6 ) ;
if ( ! V_85 -> V_64 )
goto V_57;
V_85 -> V_62 = 0 ;
V_85 -> V_148 = V_148 ;
V_3 -> V_155 -> V_156 [ V_126 ] = F_10 ( V_85 -> V_160 -> V_8 ) ;
F_32 ( V_3 , L_19 ,
V_126 ,
& V_3 -> V_155 -> V_156 [ V_126 ] ,
F_78 ( V_3 -> V_155 -> V_156 [ V_126 ] ) ) ;
F_79 ( V_85 ) ;
return 1 ;
V_57:
F_70 ( V_3 , V_126 ) ;
return 0 ;
}
void F_80 ( struct V_2 * V_3 ,
struct V_137 * V_148 )
{
struct V_58 * V_59 ;
struct V_80 * V_164 ;
struct V_31 * V_165 ;
V_59 = V_3 -> V_154 [ V_148 -> V_126 ] ;
V_164 = F_42 ( V_3 , V_59 -> V_159 , 0 ) ;
V_165 = V_59 -> V_65 [ 0 ] . V_32 ;
V_164 -> V_123 = F_10 ( F_60 ( V_165 -> V_35 ,
V_165 -> V_49 )
| V_165 -> V_4 ) ;
}
static T_3 F_81 ( struct V_2 * V_3 ,
struct V_137 * V_148 )
{
struct V_137 * V_166 ;
struct V_167 * V_168 ;
if ( V_148 -> V_169 >= V_170 )
V_168 = V_3 -> V_171 ;
else
V_168 = V_3 -> V_172 ;
for ( V_166 = V_148 ; V_166 -> V_173 && V_166 -> V_173 -> V_173 ;
V_166 = V_166 -> V_173 )
;
return F_82 ( V_168 , V_166 -> V_174 ) ;
}
int F_83 ( struct V_2 * V_3 , struct V_137 * V_148 )
{
struct V_58 * V_85 ;
struct V_80 * V_164 ;
struct V_79 * V_175 ;
T_3 V_176 ;
T_3 V_177 ;
struct V_137 * V_166 ;
V_85 = V_3 -> V_154 [ V_148 -> V_126 ] ;
if ( V_148 -> V_126 == 0 || ! V_85 ) {
F_73 ( V_3 , L_20 ,
V_148 -> V_126 ) ;
return - V_178 ;
}
V_164 = F_42 ( V_3 , V_85 -> V_159 , 0 ) ;
V_175 = F_41 ( V_3 , V_85 -> V_159 ) ;
V_175 -> V_179 |= F_6 ( F_84 ( 1 ) | V_148 -> V_180 ) ;
switch ( V_148 -> V_169 ) {
case V_181 :
V_175 -> V_179 |= F_6 ( V_182 ) ;
V_177 = F_85 ( 512 ) ;
break;
case V_170 :
V_175 -> V_179 |= F_6 ( V_183 ) ;
V_177 = F_85 ( 512 ) ;
break;
case V_184 :
V_175 -> V_179 |= F_6 ( V_185 ) ;
V_177 = F_85 ( 64 ) ;
break;
case V_186 :
V_175 -> V_179 |= F_6 ( V_187 ) ;
V_177 = F_85 ( 64 ) ;
break;
case V_188 :
V_175 -> V_179 |= F_6 ( V_189 ) ;
V_177 = F_85 ( 8 ) ;
break;
case V_190 :
F_32 ( V_3 , L_21 ) ;
return - V_178 ;
break;
default:
return - V_178 ;
}
V_176 = F_81 ( V_3 , V_148 ) ;
if ( ! V_176 )
return - V_178 ;
V_175 -> V_191 |= F_6 ( F_86 ( V_176 ) ) ;
for ( V_166 = V_148 ; V_166 -> V_173 && V_166 -> V_173 -> V_173 ;
V_166 = V_166 -> V_173 )
;
V_85 -> V_192 = V_166 -> V_174 ;
V_85 -> V_132 = V_176 ;
F_32 ( V_3 , L_22 , V_176 ) ;
F_32 ( V_3 , L_23 , V_85 -> V_192 ) ;
if ( ! V_148 -> V_140 || ! V_148 -> V_140 -> V_193 -> V_173 ) {
V_85 -> V_146 = & V_3 -> V_134 [ V_176 - 1 ] . V_146 ;
} else {
struct V_194 * V_134 ;
struct V_129 * V_195 ;
V_134 = & V_3 -> V_134 [ V_176 - 1 ] ;
F_87 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_195 -> V_126 != V_148 -> V_140 -> V_193 -> V_126 )
continue;
if ( ! V_85 -> V_148 -> V_140 -> V_143 ||
( V_148 -> V_140 -> V_143 &&
V_195 -> V_149 == V_85 -> V_148 -> V_149 ) ) {
V_85 -> V_146 = & V_195 -> V_146 ;
V_85 -> V_130 = V_195 ;
break;
}
}
if ( ! V_85 -> V_130 )
F_73 ( V_3 , L_24 ) ;
}
if ( V_148 -> V_140 && V_148 -> V_140 -> V_193 -> V_173 ) {
V_175 -> V_130 = F_6 ( V_148 -> V_140 -> V_193 -> V_126 |
( V_148 -> V_149 << 8 ) ) ;
if ( V_148 -> V_140 -> V_143 )
V_175 -> V_179 |= F_6 ( V_196 ) ;
}
F_32 ( V_3 , L_25 , V_148 -> V_140 ) ;
F_32 ( V_3 , L_26 , V_148 -> V_149 ) ;
V_164 -> V_197 = F_6 ( F_88 ( V_198 ) ) ;
V_164 -> V_197 |= F_6 ( F_89 ( 0 ) | F_90 ( 3 ) |
V_177 ) ;
V_164 -> V_123 = F_10 ( V_85 -> V_65 [ 0 ] . V_32 -> V_45 -> V_8 |
V_85 -> V_65 [ 0 ] . V_32 -> V_4 ) ;
F_91 ( V_85 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
unsigned int V_200 ;
V_200 = F_93 ( V_93 -> V_201 . V_202 , 1 , 16 ) - 1 ;
if ( V_200 != V_93 -> V_201 . V_202 - 1 )
F_94 ( & V_148 -> V_85 ,
L_27 ,
V_93 -> V_201 . V_203 ,
1 << V_200 ,
V_148 -> V_169 == V_186 ? L_4 : L_28 ) ;
if ( V_148 -> V_169 == V_186 ) {
V_200 += 3 ;
}
return V_200 ;
}
static unsigned int F_95 ( struct V_137 * V_148 ,
struct V_199 * V_93 , unsigned int V_204 ,
unsigned int V_205 , unsigned int V_206 )
{
unsigned int V_200 ;
V_200 = F_57 ( V_204 ) - 1 ;
V_200 = F_93 ( V_200 , V_205 , V_206 ) ;
if ( ( 1 << V_200 ) != V_204 )
F_96 ( & V_148 -> V_85 ,
L_29 ,
V_93 -> V_201 . V_203 ,
1 << V_200 ,
V_204 ) ;
return V_200 ;
}
static unsigned int F_97 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_93 -> V_201 . V_202 == 0 )
return 0 ;
return F_95 ( V_148 , V_93 ,
V_93 -> V_201 . V_202 , 0 , 15 ) ;
}
static unsigned int F_98 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
return F_95 ( V_148 , V_93 ,
V_93 -> V_201 . V_202 * 8 , 3 , 10 ) ;
}
static unsigned int F_99 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
unsigned int V_200 = 0 ;
switch ( V_148 -> V_169 ) {
case V_184 :
if ( F_100 ( & V_93 -> V_201 ) ||
F_101 ( & V_93 -> V_201 ) ) {
V_200 = F_97 ( V_148 , V_93 ) ;
break;
}
case V_181 :
case V_170 :
if ( F_102 ( & V_93 -> V_201 ) ||
F_103 ( & V_93 -> V_201 ) ) {
V_200 = F_92 ( V_148 , V_93 ) ;
}
break;
case V_186 :
if ( F_103 ( & V_93 -> V_201 ) ) {
V_200 = F_92 ( V_148 , V_93 ) ;
break;
}
case V_188 :
if ( F_102 ( & V_93 -> V_201 ) ||
F_103 ( & V_93 -> V_201 ) ) {
V_200 = F_98 ( V_148 , V_93 ) ;
}
break;
default:
F_104 () ;
}
return V_200 ;
}
static T_3 F_105 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_148 -> V_169 < V_170 ||
! F_103 ( & V_93 -> V_201 ) )
return 0 ;
return V_93 -> V_207 . V_208 ;
}
static T_3 F_106 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_148 -> V_169 >= V_170 )
return V_93 -> V_207 . V_209 ;
if ( V_148 -> V_169 == V_184 &&
( F_103 ( & V_93 -> V_201 ) ||
F_102 ( & V_93 -> V_201 ) ) )
return F_107 ( & V_93 -> V_201 ) - 1 ;
return 0 ;
}
static T_3 F_108 ( struct V_199 * V_93 )
{
int V_210 ;
V_210 = F_109 ( & V_93 -> V_201 ) ;
switch ( F_110 ( & V_93 -> V_201 ) ) {
case V_211 :
return V_198 ;
case V_212 :
return V_210 ? V_213 : V_214 ;
case V_215 :
return V_210 ? V_216 : V_217 ;
case V_218 :
return V_210 ? V_219 : V_220 ;
}
return 0 ;
}
static T_3 F_111 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
int V_221 ;
int V_5 ;
if ( F_100 ( & V_93 -> V_201 ) ||
F_101 ( & V_93 -> V_201 ) )
return 0 ;
if ( ( V_148 -> V_169 >= V_181 ) &&
F_112 ( V_93 -> V_207 . V_208 ) )
return F_11 ( V_93 -> V_222 . V_223 ) ;
else if ( V_148 -> V_169 >= V_170 )
return F_113 ( V_93 -> V_207 . V_224 ) ;
V_5 = F_114 ( & V_93 -> V_201 ) ;
V_221 = F_107 ( & V_93 -> V_201 ) ;
return V_5 * V_221 ;
}
int F_115 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
struct V_137 * V_148 ,
struct V_199 * V_93 ,
T_1 V_41 )
{
unsigned int V_60 ;
struct V_80 * V_117 ;
struct V_31 * V_165 ;
unsigned int V_5 ;
enum V_21 V_225 ;
T_3 V_226 ;
T_3 V_227 ;
unsigned int V_221 ;
unsigned int V_200 ;
unsigned int V_228 ;
unsigned int V_229 ;
unsigned int V_230 = 0 ;
V_60 = F_116 ( & V_93 -> V_201 ) ;
V_117 = F_42 ( V_3 , V_59 -> V_159 , V_60 ) ;
V_227 = F_108 ( V_93 ) ;
if ( ! V_227 )
return - V_178 ;
V_225 = F_110 ( & V_93 -> V_201 ) ;
V_226 = F_111 ( V_148 , V_93 ) ;
V_200 = F_99 ( V_148 , V_93 ) ;
V_228 = F_105 ( V_148 , V_93 ) ;
V_5 = F_114 ( & V_93 -> V_201 ) ;
V_221 = F_106 ( V_148 , V_93 ) ;
V_229 = V_226 ;
if ( ! F_103 ( & V_93 -> V_201 ) )
V_230 = 3 ;
if ( F_101 ( & V_93 -> V_201 ) && V_148 -> V_169 == V_184 )
V_5 = 512 ;
if ( F_100 ( & V_93 -> V_201 ) && V_3 -> V_231 >= 0x100 )
V_229 = 8 ;
if ( ( V_3 -> V_231 > 0x100 ) && F_117 ( V_3 -> V_232 ) )
V_228 = 0 ;
V_59 -> V_65 [ V_60 ] . V_233 =
F_29 ( V_3 , 2 , 1 , V_225 , V_5 , V_41 ) ;
if ( ! V_59 -> V_65 [ V_60 ] . V_233 ) {
if ( V_59 -> V_62 == 0 )
return - V_54 ;
V_59 -> V_62 -- ;
V_59 -> V_65 [ V_60 ] . V_233 =
V_59 -> V_64 [ V_59 -> V_62 ] ;
V_59 -> V_64 [ V_59 -> V_62 ] = NULL ;
F_33 ( V_3 , V_59 -> V_65 [ V_60 ] . V_233 ,
1 , V_225 ) ;
}
V_59 -> V_65 [ V_60 ] . V_234 = false ;
V_165 = V_59 -> V_65 [ V_60 ] . V_233 ;
V_117 -> V_120 = F_6 ( F_118 ( V_226 ) |
F_119 ( V_200 ) |
F_120 ( V_228 ) ) ;
V_117 -> V_197 = F_6 ( F_88 ( V_227 ) |
F_85 ( V_5 ) |
F_89 ( V_221 ) |
F_90 ( V_230 ) ) ;
V_117 -> V_123 = F_10 ( V_165 -> V_45 -> V_8 |
V_165 -> V_4 ) ;
V_117 -> V_235 = F_6 ( F_121 ( V_226 ) |
F_122 ( V_229 ) ) ;
return 0 ;
}
void F_123 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
struct V_199 * V_93 )
{
unsigned int V_60 ;
struct V_80 * V_117 ;
V_60 = F_116 ( & V_93 -> V_201 ) ;
V_117 = F_42 ( V_3 , V_59 -> V_159 , V_60 ) ;
V_117 -> V_120 = 0 ;
V_117 -> V_197 = 0 ;
V_117 -> V_123 = 0 ;
V_117 -> V_235 = 0 ;
}
void F_124 ( struct V_236 * V_237 )
{
V_237 -> V_238 = 0 ;
V_237 -> V_228 = 0 ;
V_237 -> V_239 = 0 ;
V_237 -> V_240 = 0 ;
V_237 -> type = 0 ;
V_237 -> V_226 = 0 ;
}
void F_125 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_78 * V_241 ,
struct V_58 * V_59 )
{
struct V_236 * V_237 ;
struct V_80 * V_117 ;
unsigned int V_242 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < 31 ; V_9 ++ ) {
V_237 = & V_59 -> V_65 [ V_9 ] . V_237 ;
if ( ! F_126 ( V_241 , V_9 ) && F_127 ( V_241 , V_9 ) ) {
F_124 ( V_237 ) ;
continue;
}
if ( F_126 ( V_241 , V_9 ) ) {
V_117 = F_42 ( V_3 , V_159 , V_9 ) ;
V_242 = F_128 ( F_11 ( V_117 -> V_197 ) ) ;
if ( V_242 != V_217 && V_242 != V_220 &&
V_242 != V_216 &&
V_242 != V_219 )
continue;
V_237 -> V_238 = F_129 (
F_11 ( V_117 -> V_120 ) ) ;
V_237 -> V_228 = F_130 (
F_11 ( V_117 -> V_120 ) ) + 1 ;
V_237 -> V_239 = F_131 (
F_11 ( V_117 -> V_197 ) ) + 1 ;
V_237 -> V_240 = F_132 (
F_11 ( V_117 -> V_197 ) ) ;
V_237 -> type = V_242 ;
V_237 -> V_226 = F_133 (
F_11 ( V_117 -> V_235 ) ) ;
}
}
}
void F_134 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_70 * V_160 ,
unsigned int V_60 )
{
struct V_80 * V_243 ;
struct V_80 * V_244 ;
V_243 = F_42 ( V_3 , V_160 , V_60 ) ;
V_244 = F_42 ( V_3 , V_159 , V_60 ) ;
V_244 -> V_120 = V_243 -> V_120 ;
V_244 -> V_197 = V_243 -> V_197 ;
V_244 -> V_123 = V_243 -> V_123 ;
V_244 -> V_235 = V_243 -> V_235 ;
}
void F_135 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_70 * V_160 )
{
struct V_79 * V_245 ;
struct V_79 * V_246 ;
V_245 = F_41 ( V_3 , V_159 ) ;
V_246 = F_41 ( V_3 , V_160 ) ;
V_245 -> V_179 = V_246 -> V_179 ;
V_245 -> V_191 = V_246 -> V_191 ;
V_245 -> V_130 = V_246 -> V_130 ;
V_245 -> V_247 = V_246 -> V_247 ;
}
static int F_136 ( struct V_2 * V_3 , T_1 V_6 )
{
int V_9 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
int V_248 = F_137 ( V_3 -> V_249 ) ;
F_35 ( V_3 , V_250 ,
L_30 , V_248 ) ;
if ( ! V_248 )
return 0 ;
V_3 -> V_251 = F_2 ( sizeof( * V_3 -> V_251 ) , V_6 ) ;
if ( ! V_3 -> V_251 )
goto V_252;
V_3 -> V_251 -> V_253 = F_47 ( V_85 ,
V_248 * sizeof( T_5 ) ,
& V_3 -> V_251 -> V_254 , V_6 ) ;
if ( ! V_3 -> V_251 -> V_253 )
goto V_255;
V_3 -> V_251 -> V_256 = F_2 ( sizeof( void * ) * V_248 , V_6 ) ;
if ( ! V_3 -> V_251 -> V_256 )
goto V_257;
V_3 -> V_251 -> V_258 =
F_2 ( sizeof( T_2 ) * V_248 , V_6 ) ;
if ( ! V_3 -> V_251 -> V_258 )
goto V_259;
V_3 -> V_155 -> V_156 [ 0 ] = F_10 ( V_3 -> V_251 -> V_254 ) ;
for ( V_9 = 0 ; V_9 < V_248 ; V_9 ++ ) {
T_2 V_8 ;
void * V_260 = F_47 ( V_85 , V_3 -> V_261 , & V_8 ,
V_6 ) ;
if ( ! V_260 )
goto V_262;
V_3 -> V_251 -> V_253 [ V_9 ] = V_8 ;
V_3 -> V_251 -> V_256 [ V_9 ] = V_260 ;
V_3 -> V_251 -> V_258 [ V_9 ] = V_8 ;
}
return 0 ;
V_262:
for ( V_9 = V_9 - 1 ; V_9 >= 0 ; V_9 -- ) {
F_45 ( V_85 , V_3 -> V_261 ,
V_3 -> V_251 -> V_256 [ V_9 ] ,
V_3 -> V_251 -> V_258 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_251 -> V_258 ) ;
V_259:
F_4 ( V_3 -> V_251 -> V_256 ) ;
V_257:
F_45 ( V_85 , V_248 * sizeof( T_5 ) ,
V_3 -> V_251 -> V_253 ,
V_3 -> V_251 -> V_254 ) ;
V_255:
F_4 ( V_3 -> V_251 ) ;
V_3 -> V_251 = NULL ;
V_252:
return - V_54 ;
}
static void F_138 ( struct V_2 * V_3 )
{
int V_248 ;
int V_9 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
if ( ! V_3 -> V_251 )
return;
V_248 = F_137 ( V_3 -> V_249 ) ;
for ( V_9 = 0 ; V_9 < V_248 ; V_9 ++ ) {
F_45 ( V_85 , V_3 -> V_261 ,
V_3 -> V_251 -> V_256 [ V_9 ] ,
V_3 -> V_251 -> V_258 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_251 -> V_258 ) ;
F_4 ( V_3 -> V_251 -> V_256 ) ;
F_45 ( V_85 , V_248 * sizeof( T_5 ) ,
V_3 -> V_251 -> V_253 ,
V_3 -> V_251 -> V_254 ) ;
F_4 ( V_3 -> V_251 ) ;
V_3 -> V_251 = NULL ;
}
struct V_263 * F_52 ( struct V_2 * V_3 ,
bool V_264 , bool V_265 ,
T_1 V_41 )
{
struct V_263 * V_266 ;
V_266 = F_2 ( sizeof( * V_266 ) , V_41 ) ;
if ( ! V_266 )
return NULL ;
if ( V_264 ) {
V_266 -> V_159 =
F_36 ( V_3 , V_73 ,
V_41 ) ;
if ( ! V_266 -> V_159 ) {
F_4 ( V_266 ) ;
return NULL ;
}
}
if ( V_265 ) {
V_266 -> V_267 =
F_2 ( sizeof( struct V_267 ) , V_41 ) ;
if ( ! V_266 -> V_267 ) {
F_39 ( V_3 , V_266 -> V_159 ) ;
F_4 ( V_266 ) ;
return NULL ;
}
F_139 ( V_266 -> V_267 ) ;
}
V_266 -> V_268 = 0 ;
F_30 ( & V_266 -> V_269 ) ;
return V_266 ;
}
void F_140 ( struct V_270 * V_270 )
{
F_4 ( V_270 ) ;
}
void F_55 ( struct V_2 * V_3 ,
struct V_263 * V_266 )
{
F_39 ( V_3 ,
V_266 -> V_159 ) ;
F_4 ( V_266 -> V_267 ) ;
F_4 ( V_266 ) ;
}
void F_141 ( struct V_2 * V_3 )
{
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
int V_74 ;
int V_9 , V_142 , V_141 ;
F_142 ( & V_3 -> V_271 ) ;
V_74 = sizeof( struct V_272 ) * ( V_3 -> V_273 . V_274 ) ;
if ( V_3 -> V_273 . V_275 )
F_45 ( V_85 , V_74 ,
V_3 -> V_273 . V_275 , V_3 -> V_273 . V_276 ) ;
V_3 -> V_273 . V_275 = NULL ;
F_35 ( V_3 , V_250 , L_31 ) ;
if ( V_3 -> V_277 )
F_26 ( V_3 , V_3 -> V_277 ) ;
V_3 -> V_277 = NULL ;
F_35 ( V_3 , V_250 , L_32 ) ;
if ( V_3 -> V_278 )
F_55 ( V_3 , V_3 -> V_278 ) ;
V_3 -> V_278 = NULL ;
if ( V_3 -> V_279 )
F_26 ( V_3 , V_3 -> V_279 ) ;
V_3 -> V_279 = NULL ;
F_35 ( V_3 , V_250 , L_33 ) ;
F_143 ( V_3 ) ;
V_141 = F_65 ( V_3 -> V_133 ) ;
for ( V_9 = 0 ; V_9 < V_141 && V_3 -> V_134 ; V_9 ++ ) {
struct V_145 * V_280 = & V_3 -> V_134 [ V_9 ] . V_146 ;
for ( V_142 = 0 ; V_142 < V_150 ; V_142 ++ ) {
struct V_127 * V_93 = & V_280 -> V_151 [ V_142 ] . V_152 ;
while ( ! F_72 ( V_93 ) )
F_144 ( V_93 -> V_18 ) ;
}
}
for ( V_9 = F_76 ( V_3 -> V_133 ) ; V_9 > 0 ; V_9 -- )
F_75 ( V_3 , V_9 ) ;
F_145 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
F_35 ( V_3 , V_250 , L_34 ) ;
F_145 ( V_3 -> V_77 ) ;
V_3 -> V_77 = NULL ;
F_35 ( V_3 , V_250 , L_35 ) ;
F_145 ( V_3 -> V_90 ) ;
V_3 -> V_90 = NULL ;
F_35 ( V_3 , V_250 ,
L_36 ) ;
F_145 ( V_3 -> V_91 ) ;
V_3 -> V_91 = NULL ;
F_35 ( V_3 , V_250 ,
L_37 ) ;
if ( V_3 -> V_155 )
F_45 ( V_85 , sizeof( * V_3 -> V_155 ) ,
V_3 -> V_155 , V_3 -> V_155 -> V_8 ) ;
V_3 -> V_155 = NULL ;
F_138 ( V_3 ) ;
if ( ! V_3 -> V_134 )
goto V_281;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ ) {
struct V_129 * V_140 , * V_282 ;
F_66 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_67 ( & V_140 -> V_136 ) ;
F_4 ( V_140 ) ;
}
}
V_281:
V_3 -> V_105 = 0 ;
V_3 -> V_283 = 0 ;
V_3 -> V_284 = 0 ;
V_3 -> V_285 = 0 ;
F_4 ( V_3 -> V_286 ) ;
F_4 ( V_3 -> V_287 ) ;
F_4 ( V_3 -> V_288 ) ;
F_4 ( V_3 -> V_134 ) ;
F_4 ( V_3 -> V_289 ) ;
V_3 -> V_286 = NULL ;
V_3 -> V_287 = NULL ;
V_3 -> V_288 = NULL ;
V_3 -> V_134 = NULL ;
V_3 -> V_289 = NULL ;
V_3 -> V_261 = 0 ;
V_3 -> V_290 = 0 ;
V_3 -> V_291 [ 0 ] . V_292 = 0 ;
V_3 -> V_291 [ 1 ] . V_292 = 0 ;
}
static int F_146 ( struct V_2 * V_3 ,
struct V_1 * V_293 ,
union V_66 * V_294 ,
union V_66 * V_295 ,
T_2 V_296 ,
struct V_1 * V_297 ,
char * V_298 , int V_299 )
{
unsigned long long V_300 ;
unsigned long long V_301 ;
struct V_1 * V_7 ;
V_300 = F_60 ( V_293 , V_294 ) ;
V_301 = F_60 ( V_293 , V_295 ) ;
V_7 = F_147 ( V_3 , V_293 , V_294 , V_295 , V_296 , false ) ;
if ( V_7 != V_297 ) {
F_73 ( V_3 , L_38 ,
V_298 , V_299 ) ;
F_73 ( V_3 , L_39
L_40 ,
V_293 ,
( unsigned long long ) V_296 ) ;
F_73 ( V_3 , L_41
L_42 ,
V_294 , V_300 ,
V_295 , V_301 ) ;
F_73 ( V_3 , L_43 ,
V_297 , V_7 ) ;
F_147 ( V_3 , V_293 , V_294 , V_295 , V_296 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct {
T_2 V_296 ;
struct V_1 * V_297 ;
} V_302 [] = {
{ 0 , NULL } ,
{ V_3 -> V_277 -> V_45 -> V_8 - 16 , NULL } ,
{ V_3 -> V_277 -> V_45 -> V_8 - 1 , NULL } ,
{ V_3 -> V_277 -> V_45 -> V_8 , V_3 -> V_277 -> V_45 } ,
{ V_3 -> V_277 -> V_45 -> V_8 + ( V_14 - 1 ) * 16 ,
V_3 -> V_277 -> V_45 } ,
{ V_3 -> V_277 -> V_45 -> V_8 + ( V_14 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_277 -> V_45 -> V_8 + ( V_14 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_293 ;
union V_66 * V_294 ;
union V_66 * V_295 ;
T_2 V_296 ;
struct V_1 * V_297 ;
} V_303 [] = {
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = V_3 -> V_277 -> V_45 -> V_10 ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_296 = V_3 -> V_279 -> V_45 -> V_8 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = V_3 -> V_277 -> V_45 -> V_10 ,
. V_295 = & V_3 -> V_279 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_296 = V_3 -> V_279 -> V_45 -> V_8 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = V_3 -> V_279 -> V_45 -> V_10 ,
. V_295 = & V_3 -> V_279 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_296 = V_3 -> V_279 -> V_45 -> V_8 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = & V_3 -> V_277 -> V_45 -> V_10 [ 0 ] ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ 3 ] ,
. V_296 = V_3 -> V_277 -> V_45 -> V_8 + 4 * 16 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = & V_3 -> V_277 -> V_45 -> V_10 [ 3 ] ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ 6 ] ,
. V_296 = V_3 -> V_277 -> V_45 -> V_8 + 2 * 16 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = & V_3 -> V_277 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ 1 ] ,
. V_296 = V_3 -> V_277 -> V_45 -> V_8 + 2 * 16 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = & V_3 -> V_277 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ 1 ] ,
. V_296 = V_3 -> V_277 -> V_45 -> V_8 + ( V_14 - 4 ) * 16 ,
. V_297 = NULL ,
} ,
{ . V_293 = V_3 -> V_277 -> V_45 ,
. V_294 = & V_3 -> V_277 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_295 = & V_3 -> V_277 -> V_45 -> V_10 [ 1 ] ,
. V_296 = V_3 -> V_279 -> V_45 -> V_8 + 2 * 16 ,
. V_297 = NULL ,
} ,
} ;
unsigned int V_304 ;
int V_9 , V_43 ;
V_304 = F_149 ( V_302 ) ;
for ( V_9 = 0 ; V_9 < V_304 ; V_9 ++ ) {
V_43 = F_146 ( V_3 ,
V_3 -> V_277 -> V_45 ,
V_3 -> V_277 -> V_45 -> V_10 ,
& V_3 -> V_277 -> V_45 -> V_10 [ V_14 - 1 ] ,
V_302 [ V_9 ] . V_296 ,
V_302 [ V_9 ] . V_297 ,
L_44 , V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_304 = F_149 ( V_303 ) ;
for ( V_9 = 0 ; V_9 < V_304 ; V_9 ++ ) {
V_43 = F_146 ( V_3 ,
V_303 [ V_9 ] . V_293 ,
V_303 [ V_9 ] . V_294 ,
V_303 [ V_9 ] . V_295 ,
V_303 [ V_9 ] . V_296 ,
V_303 [ V_9 ] . V_297 ,
L_45 , V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
}
F_32 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_150 ( struct V_2 * V_3 )
{
T_5 V_305 ;
T_2 V_123 ;
V_123 = F_60 ( V_3 -> V_277 -> V_51 ,
V_3 -> V_277 -> V_50 ) ;
if ( V_123 == 0 && ! F_151 () )
F_73 ( V_3 , L_47
L_48 ) ;
V_305 = F_152 ( V_3 , & V_3 -> V_306 -> V_307 ) ;
V_305 &= V_308 ;
V_305 &= ~ V_309 ;
F_35 ( V_3 , V_250 ,
L_49
L_50 ) ;
F_153 ( V_3 , ( ( T_5 ) V_123 & ( T_5 ) ~ V_308 ) | V_305 ,
& V_3 -> V_306 -> V_307 ) ;
}
static void F_154 ( struct V_2 * V_3 , unsigned int V_141 ,
T_6 T_7 * V_104 , int V_310 )
{
T_3 V_305 , V_311 , V_312 ;
int V_9 ;
T_8 V_313 ;
struct V_314 * V_315 ;
V_305 = F_155 ( V_104 ) ;
V_313 = F_156 ( V_305 ) ;
if ( V_313 == 0x03 ) {
V_315 = & V_3 -> V_316 ;
} else if ( V_313 <= 0x02 ) {
V_315 = & V_3 -> V_317 ;
} else {
F_73 ( V_3 , L_51
L_52 ,
V_104 , V_313 ) ;
return;
}
V_315 -> V_318 = F_156 ( V_305 ) ;
V_315 -> V_319 = F_157 ( V_305 ) ;
V_305 = F_155 ( V_104 + 2 ) ;
V_311 = F_158 ( V_305 ) ;
V_312 = F_159 ( V_305 ) ;
F_35 ( V_3 , V_250 ,
L_53
L_54 ,
V_104 , V_311 , V_312 , V_313 ) ;
if ( V_311 == 0 || ( V_311 + V_312 - 1 ) > V_141 )
return;
V_315 -> V_320 = F_160 ( V_305 ) ;
if ( V_315 -> V_320 ) {
V_315 -> V_321 = F_161 ( V_315 -> V_320 , sizeof( * V_315 -> V_321 ) ,
V_322 ) ;
if ( ! V_315 -> V_321 )
V_315 -> V_320 = 0 ;
V_315 -> V_323 ++ ;
for ( V_9 = 0 ; V_9 < V_315 -> V_320 ; V_9 ++ ) {
V_315 -> V_321 [ V_9 ] = F_155 ( V_104 + 4 + V_9 ) ;
if ( V_9 && ( F_162 ( V_315 -> V_321 [ V_9 ] ) !=
F_162 ( V_315 -> V_321 [ V_9 - 1 ] ) ) )
V_315 -> V_323 ++ ;
F_32 ( V_3 , L_55 ,
F_162 ( V_315 -> V_321 [ V_9 ] ) ,
F_163 ( V_315 -> V_321 [ V_9 ] ) ,
F_164 ( V_315 -> V_321 [ V_9 ] ) ,
F_165 ( V_315 -> V_321 [ V_9 ] ) ,
F_166 ( V_315 -> V_321 [ V_9 ] ) ,
F_167 ( V_315 -> V_321 [ V_9 ] ) ) ;
}
}
if ( V_313 < 0x03 && V_3 -> V_324 < V_310 )
V_3 -> V_289 [ V_3 -> V_324 ++ ] = V_305 ;
if ( ( V_3 -> V_231 == 0x96 ) && ( V_313 != 0x03 ) &&
( V_305 & V_325 ) ) {
F_35 ( V_3 , V_250 ,
L_56 ) ;
V_3 -> V_326 = 1 ;
}
if ( ( V_3 -> V_231 >= 0x100 ) && ( V_313 != 0x03 ) ) {
F_35 ( V_3 , V_250 ,
L_57 ) ;
V_3 -> V_326 = 1 ;
if ( V_305 & V_327 ) {
F_35 ( V_3 , V_250 ,
L_58 ) ;
V_3 -> V_328 = 1 ;
}
}
V_311 -- ;
for ( V_9 = V_311 ; V_9 < ( V_311 + V_312 ) ; V_9 ++ ) {
if ( V_3 -> V_288 [ V_9 ] != 0 ) {
F_73 ( V_3 , L_59
L_60 , V_104 , V_9 ) ;
F_73 ( V_3 , L_61
L_62 ,
V_3 -> V_288 [ V_9 ] , V_313 ) ;
if ( V_3 -> V_288 [ V_9 ] != V_313 &&
V_3 -> V_288 [ V_9 ] != V_329 ) {
if ( V_3 -> V_288 [ V_9 ] == 0x03 )
V_3 -> V_284 -- ;
else
V_3 -> V_283 -- ;
V_3 -> V_288 [ V_9 ] = V_329 ;
}
continue;
}
V_3 -> V_288 [ V_9 ] = V_313 ;
if ( V_313 == 0x03 )
V_3 -> V_284 ++ ;
else
V_3 -> V_283 ++ ;
}
}
static int F_168 ( struct V_2 * V_3 , T_1 V_6 )
{
void T_7 * V_330 ;
T_3 V_331 ;
unsigned int V_141 ;
int V_9 , V_142 , V_332 ;
int V_333 = 0 ;
T_3 V_334 ;
V_141 = F_65 ( V_3 -> V_133 ) ;
V_3 -> V_288 = F_2 ( sizeof( * V_3 -> V_288 ) * V_141 , V_6 ) ;
if ( ! V_3 -> V_288 )
return - V_54 ;
V_3 -> V_134 = F_2 ( sizeof( * V_3 -> V_134 ) * V_141 , V_6 ) ;
if ( ! V_3 -> V_134 )
return - V_54 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ ) {
struct V_145 * V_146 ;
F_30 ( & V_3 -> V_134 [ V_9 ] . V_135 ) ;
V_146 = & V_3 -> V_134 [ V_9 ] . V_146 ;
for ( V_142 = 0 ; V_142 < V_150 ; V_142 ++ )
F_30 ( & V_146 -> V_151 [ V_142 ] . V_152 ) ;
}
V_330 = & V_3 -> V_335 -> V_336 ;
V_334 = F_169 ( V_330 , 0 , V_337 ) ;
if ( ! V_334 ) {
F_170 ( V_3 , L_63 ) ;
return - V_338 ;
}
V_331 = V_334 ;
while ( V_331 ) {
V_333 ++ ;
V_331 = F_169 ( V_330 , V_331 ,
V_337 ) ;
}
V_3 -> V_289 = F_2 ( sizeof( * V_3 -> V_289 ) * V_333 , V_6 ) ;
if ( ! V_3 -> V_289 )
return - V_54 ;
V_331 = V_334 ;
while ( V_331 ) {
F_154 ( V_3 , V_141 , V_330 + V_331 , V_333 ) ;
if ( V_3 -> V_283 + V_3 -> V_284 == V_141 )
break;
V_331 = F_169 ( V_330 , V_331 ,
V_337 ) ;
}
if ( V_3 -> V_283 == 0 && V_3 -> V_284 == 0 ) {
F_73 ( V_3 , L_64 ) ;
return - V_338 ;
}
F_35 ( V_3 , V_250 ,
L_65 ,
V_3 -> V_283 , V_3 -> V_284 ) ;
if ( V_3 -> V_284 > 15 ) {
F_35 ( V_3 , V_250 ,
L_66 ) ;
V_3 -> V_284 = 15 ;
}
if ( V_3 -> V_283 > V_339 ) {
F_35 ( V_3 , V_250 ,
L_67 ,
V_339 ) ;
V_3 -> V_283 = V_339 ;
}
if ( V_3 -> V_283 ) {
V_3 -> V_286 = F_171 ( sizeof( * V_3 -> V_286 ) *
V_3 -> V_283 , V_6 ) ;
if ( ! V_3 -> V_286 )
return - V_54 ;
V_332 = 0 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ ) {
if ( V_3 -> V_288 [ V_9 ] == 0x03 ||
V_3 -> V_288 [ V_9 ] == 0 ||
V_3 -> V_288 [ V_9 ] == V_329 )
continue;
V_3 -> V_286 [ V_332 ] =
& V_3 -> V_340 -> V_341 +
V_342 * V_9 ;
F_35 ( V_3 , V_250 ,
L_68
L_69 , V_9 ,
V_3 -> V_286 [ V_332 ] ) ;
V_332 ++ ;
if ( V_332 == V_3 -> V_283 )
break;
}
}
if ( V_3 -> V_284 ) {
V_3 -> V_287 = F_171 ( sizeof( * V_3 -> V_287 ) *
V_3 -> V_284 , V_6 ) ;
if ( ! V_3 -> V_287 )
return - V_54 ;
V_332 = 0 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ )
if ( V_3 -> V_288 [ V_9 ] == 0x03 ) {
V_3 -> V_287 [ V_332 ] =
& V_3 -> V_340 -> V_341 +
V_342 * V_9 ;
F_35 ( V_3 , V_250 ,
L_70
L_69 , V_9 ,
V_3 -> V_287 [ V_332 ] ) ;
V_332 ++ ;
if ( V_332 == V_3 -> V_284 )
break;
}
}
return 0 ;
}
int F_172 ( struct V_2 * V_3 , T_1 V_6 )
{
T_2 V_8 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
unsigned int V_22 , V_343 ;
T_5 V_344 ;
struct V_1 * V_7 ;
T_3 V_261 , V_305 ;
int V_9 ;
F_30 ( & V_3 -> V_269 ) ;
F_173 ( & V_3 -> V_271 , V_345 ) ;
F_139 ( & V_3 -> V_346 ) ;
V_261 = F_155 ( & V_3 -> V_340 -> V_261 ) ;
F_35 ( V_3 , V_250 ,
L_71 , V_261 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
if ( ( 0x1 & V_261 ) != 0 )
break;
V_261 = V_261 >> 1 ;
}
if ( V_9 < 16 )
F_35 ( V_3 , V_250 ,
L_72 , ( 1 << ( V_9 + 12 ) ) / 1024 ) ;
else
F_73 ( V_3 , L_73 ) ;
V_3 -> V_290 = 12 ;
V_3 -> V_261 = 1 << V_3 -> V_290 ;
F_35 ( V_3 , V_250 ,
L_74 , V_3 -> V_261 / 1024 ) ;
V_22 = F_76 ( F_155 ( & V_3 -> V_335 -> V_133 ) ) ;
F_35 ( V_3 , V_250 ,
L_75 , V_22 ) ;
V_343 = F_155 ( & V_3 -> V_340 -> V_347 ) ;
V_22 |= ( V_343 & ~ V_348 ) ;
F_35 ( V_3 , V_250 ,
L_76 , V_22 ) ;
F_174 ( V_22 , & V_3 -> V_340 -> V_347 ) ;
V_3 -> V_155 = F_47 ( V_85 , sizeof( * V_3 -> V_155 ) , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_155 )
goto V_57;
memset ( V_3 -> V_155 , 0 , sizeof *( V_3 -> V_155 ) ) ;
V_3 -> V_155 -> V_8 = V_8 ;
F_35 ( V_3 , V_250 ,
L_77 ,
( unsigned long long ) V_3 -> V_155 -> V_8 , V_3 -> V_155 ) ;
F_153 ( V_3 , V_8 , & V_3 -> V_340 -> V_349 ) ;
V_3 -> V_11 = F_175 ( L_78 , V_85 ,
V_350 , V_350 , V_3 -> V_261 ) ;
V_3 -> V_77 = F_175 ( L_79 , V_85 ,
2112 , 64 , V_3 -> V_261 ) ;
if ( ! V_3 -> V_11 || ! V_3 -> V_77 )
goto V_57;
V_3 -> V_90 =
F_175 ( L_80 ,
V_85 , V_89 , 16 , 0 ) ;
V_3 -> V_91 =
F_175 ( L_81 ,
V_85 , V_88 , 16 , 0 ) ;
if ( ! V_3 -> V_90 || ! V_3 -> V_91 )
goto V_57;
V_3 -> V_279 = F_29 ( V_3 , 1 , 1 , V_351 , 0 , V_6 ) ;
if ( ! V_3 -> V_279 )
goto V_57;
F_35 ( V_3 , V_250 ,
L_82 , V_3 -> V_279 ) ;
F_35 ( V_3 , V_250 , L_83 ,
( unsigned long long ) V_3 -> V_279 -> V_45 -> V_8 ) ;
V_344 = F_152 ( V_3 , & V_3 -> V_340 -> V_279 ) ;
V_344 = ( V_344 & ( T_5 ) V_352 ) |
( V_3 -> V_279 -> V_45 -> V_8 & ( T_5 ) ~ V_352 ) |
V_3 -> V_279 -> V_4 ;
F_35 ( V_3 , V_250 ,
L_84 , V_22 ) ;
F_153 ( V_3 , V_344 , & V_3 -> V_340 -> V_279 ) ;
F_176 ( V_3 ) ;
V_3 -> V_278 = F_52 ( V_3 , true , true , V_6 ) ;
if ( ! V_3 -> V_278 )
goto V_57;
V_3 -> V_105 ++ ;
V_22 = F_155 ( & V_3 -> V_335 -> V_353 ) ;
V_22 &= V_354 ;
F_35 ( V_3 , V_250 ,
L_85
L_86 , V_22 ) ;
V_3 -> V_355 = ( void T_7 * ) V_3 -> V_335 + V_22 ;
F_177 ( V_3 ) ;
F_178 ( V_3 ) ;
V_3 -> V_306 = & V_3 -> V_356 -> V_306 [ 0 ] ;
F_35 ( V_3 , V_250 , L_87 ) ;
V_3 -> V_277 = F_29 ( V_3 , V_357 , 1 , V_23 ,
0 , V_6 ) ;
if ( ! V_3 -> V_277 )
goto V_57;
if ( F_148 ( V_3 ) < 0 )
goto V_57;
V_3 -> V_273 . V_275 = F_47 ( V_85 ,
sizeof( struct V_272 ) * V_357 , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_273 . V_275 )
goto V_57;
F_35 ( V_3 , V_250 ,
L_88 ,
( unsigned long long ) V_8 ) ;
memset ( V_3 -> V_273 . V_275 , 0 , sizeof( struct V_272 ) * V_357 ) ;
V_3 -> V_273 . V_274 = V_357 ;
V_3 -> V_273 . V_276 = V_8 ;
F_35 ( V_3 , V_250 ,
L_89 ,
V_3 -> V_273 . V_274 ,
V_3 -> V_273 . V_275 ,
( unsigned long long ) V_3 -> V_273 . V_276 ) ;
for ( V_22 = 0 , V_7 = V_3 -> V_277 -> V_45 ; V_22 < V_357 ; V_22 ++ ) {
struct V_272 * V_358 = & V_3 -> V_273 . V_275 [ V_22 ] ;
V_358 -> V_359 = F_10 ( V_7 -> V_8 ) ;
V_358 -> V_360 = F_6 ( V_14 ) ;
V_358 -> V_361 = 0 ;
V_7 = V_7 -> V_18 ;
}
V_22 = F_155 ( & V_3 -> V_306 -> V_362 ) ;
V_22 &= V_363 ;
V_22 |= V_357 ;
F_35 ( V_3 , V_250 ,
L_90 ,
V_22 ) ;
F_174 ( V_22 , & V_3 -> V_306 -> V_362 ) ;
F_35 ( V_3 , V_250 ,
L_91 ) ;
F_35 ( V_3 , V_250 ,
L_92 ,
( unsigned long long ) V_3 -> V_273 . V_276 ) ;
V_344 = F_152 ( V_3 , & V_3 -> V_306 -> V_364 ) ;
V_344 &= V_308 ;
V_344 |= ( V_3 -> V_273 . V_276 & ( T_5 ) ~ V_308 ) ;
F_153 ( V_3 , V_344 , & V_3 -> V_306 -> V_364 ) ;
F_150 ( V_3 ) ;
F_35 ( V_3 , V_250 ,
L_93 ) ;
F_179 ( V_3 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_365 ; V_9 ++ )
V_3 -> V_154 [ V_9 ] = NULL ;
for ( V_9 = 0 ; V_9 < V_339 ; V_9 ++ ) {
V_3 -> V_291 [ 0 ] . V_366 [ V_9 ] = 0 ;
V_3 -> V_291 [ 1 ] . V_366 [ V_9 ] = 0 ;
F_139 ( & V_3 -> V_291 [ 1 ] . V_367 [ V_9 ] ) ;
}
if ( F_136 ( V_3 , V_6 ) )
goto V_57;
if ( F_168 ( V_3 , V_6 ) )
goto V_57;
V_305 = F_155 ( & V_3 -> V_340 -> V_368 ) ;
V_305 &= ~ V_369 ;
V_305 |= V_370 ;
F_174 ( V_305 , & V_3 -> V_340 -> V_368 ) ;
return 0 ;
V_57:
F_73 ( V_3 , L_94 ) ;
F_180 ( V_3 ) ;
F_181 ( V_3 ) ;
F_141 ( V_3 ) ;
return - V_54 ;
}
