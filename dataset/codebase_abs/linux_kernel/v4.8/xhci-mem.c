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
V_3 -> V_155 -> V_156 [ V_126 ] = 0 ;
if ( ! V_85 )
return;
if ( V_85 -> V_130 )
V_153 = V_85 -> V_130 -> V_157 ;
for ( V_9 = 0 ; V_9 < 31 ; ++ V_9 ) {
if ( V_85 -> V_65 [ V_9 ] . V_32 )
F_26 ( V_3 , V_85 -> V_65 [ V_9 ] . V_32 ) ;
if ( V_85 -> V_65 [ V_9 ] . V_97 )
F_61 ( V_3 ,
V_85 -> V_65 [ V_9 ] . V_97 ) ;
if ( ! F_71 ( & V_85 -> V_65 [ V_9 ] . V_158 ) )
F_72 ( V_3 , L_14
L_15 ,
V_126 , V_9 ) ;
}
F_64 ( V_3 , V_85 , V_126 ) ;
F_73 ( V_3 , V_85 , V_153 ) ;
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
int F_74 ( struct V_2 * V_3 , int V_126 ,
struct V_137 * V_148 , T_1 V_6 )
{
struct V_58 * V_85 ;
int V_9 ;
if ( V_126 == 0 || V_3 -> V_154 [ V_126 ] ) {
F_72 ( V_3 , L_16 , V_126 ) ;
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
F_30 ( & V_85 -> V_65 [ V_9 ] . V_161 ) ;
F_30 ( & V_85 -> V_65 [ V_9 ] . V_158 ) ;
}
V_85 -> V_65 [ 0 ] . V_32 = F_29 ( V_3 , 2 , 1 , V_162 , 0 , V_6 ) ;
if ( ! V_85 -> V_65 [ 0 ] . V_32 )
goto V_57;
V_85 -> V_64 = F_2 (
sizeof( struct V_31 * ) * V_63 ,
V_6 ) ;
if ( ! V_85 -> V_64 )
goto V_57;
V_85 -> V_62 = 0 ;
F_75 ( & V_85 -> V_163 ) ;
V_85 -> V_148 = V_148 ;
V_3 -> V_155 -> V_156 [ V_126 ] = F_10 ( V_85 -> V_160 -> V_8 ) ;
F_32 ( V_3 , L_19 ,
V_126 ,
& V_3 -> V_155 -> V_156 [ V_126 ] ,
F_76 ( V_3 -> V_155 -> V_156 [ V_126 ] ) ) ;
return 1 ;
V_57:
F_70 ( V_3 , V_126 ) ;
return 0 ;
}
void F_77 ( struct V_2 * V_3 ,
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
static T_3 F_78 ( struct V_2 * V_3 ,
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
return F_79 ( V_168 , V_166 -> V_174 ) ;
}
int F_80 ( struct V_2 * V_3 , struct V_137 * V_148 )
{
struct V_58 * V_85 ;
struct V_80 * V_164 ;
struct V_79 * V_175 ;
T_3 V_176 ;
T_3 V_177 ;
struct V_137 * V_166 ;
V_85 = V_3 -> V_154 [ V_148 -> V_126 ] ;
if ( V_148 -> V_126 == 0 || ! V_85 ) {
F_72 ( V_3 , L_20 ,
V_148 -> V_126 ) ;
return - V_178 ;
}
V_164 = F_42 ( V_3 , V_85 -> V_159 , 0 ) ;
V_175 = F_41 ( V_3 , V_85 -> V_159 ) ;
V_175 -> V_179 |= F_6 ( F_81 ( 1 ) | V_148 -> V_180 ) ;
switch ( V_148 -> V_169 ) {
case V_181 :
V_175 -> V_179 |= F_6 ( V_182 ) ;
V_177 = F_82 ( 512 ) ;
break;
case V_170 :
V_175 -> V_179 |= F_6 ( V_183 ) ;
V_177 = F_82 ( 512 ) ;
break;
case V_184 :
V_175 -> V_179 |= F_6 ( V_185 ) ;
V_177 = F_82 ( 64 ) ;
break;
case V_186 :
V_175 -> V_179 |= F_6 ( V_187 ) ;
V_177 = F_82 ( 64 ) ;
break;
case V_188 :
V_175 -> V_179 |= F_6 ( V_189 ) ;
V_177 = F_82 ( 8 ) ;
break;
case V_190 :
F_32 ( V_3 , L_21 ) ;
return - V_178 ;
break;
default:
return - V_178 ;
}
V_176 = F_78 ( V_3 , V_148 ) ;
if ( ! V_176 )
return - V_178 ;
V_175 -> V_191 |= F_6 ( F_83 ( V_176 ) ) ;
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
F_84 (tt_bw, &rh_bw->tts, tt_list) {
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
F_72 ( V_3 , L_24 ) ;
}
if ( V_148 -> V_140 && V_148 -> V_140 -> V_193 -> V_173 ) {
V_175 -> V_130 = F_6 ( V_148 -> V_140 -> V_193 -> V_126 |
( V_148 -> V_149 << 8 ) ) ;
if ( V_148 -> V_140 -> V_143 )
V_175 -> V_179 |= F_6 ( V_196 ) ;
}
F_32 ( V_3 , L_25 , V_148 -> V_140 ) ;
F_32 ( V_3 , L_26 , V_148 -> V_149 ) ;
V_164 -> V_197 = F_6 ( F_85 ( V_198 ) ) ;
V_164 -> V_197 |= F_6 ( F_86 ( 0 ) | F_87 ( 3 ) |
V_177 ) ;
V_164 -> V_123 = F_10 ( V_85 -> V_65 [ 0 ] . V_32 -> V_45 -> V_8 |
V_85 -> V_65 [ 0 ] . V_32 -> V_4 ) ;
return 0 ;
}
static unsigned int F_88 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
unsigned int V_200 ;
V_200 = F_89 ( V_93 -> V_201 . V_202 , 1 , 16 ) - 1 ;
if ( V_200 != V_93 -> V_201 . V_202 - 1 )
F_90 ( & V_148 -> V_85 ,
L_27 ,
V_93 -> V_201 . V_203 ,
1 << V_200 ,
V_148 -> V_169 == V_186 ? L_4 : L_28 ) ;
if ( V_148 -> V_169 == V_186 ) {
V_200 += 3 ;
}
return V_200 ;
}
static unsigned int F_91 ( struct V_137 * V_148 ,
struct V_199 * V_93 , unsigned int V_204 ,
unsigned int V_205 , unsigned int V_206 )
{
unsigned int V_200 ;
V_200 = F_57 ( V_204 ) - 1 ;
V_200 = F_89 ( V_200 , V_205 , V_206 ) ;
if ( ( 1 << V_200 ) != V_204 )
F_92 ( & V_148 -> V_85 ,
L_29 ,
V_93 -> V_201 . V_203 ,
1 << V_200 ,
V_204 ) ;
return V_200 ;
}
static unsigned int F_93 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_93 -> V_201 . V_202 == 0 )
return 0 ;
return F_91 ( V_148 , V_93 ,
V_93 -> V_201 . V_202 , 0 , 15 ) ;
}
static unsigned int F_94 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
return F_91 ( V_148 , V_93 ,
V_93 -> V_201 . V_202 * 8 , 3 , 10 ) ;
}
static unsigned int F_95 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
unsigned int V_200 = 0 ;
switch ( V_148 -> V_169 ) {
case V_184 :
if ( F_96 ( & V_93 -> V_201 ) ||
F_97 ( & V_93 -> V_201 ) ) {
V_200 = F_93 ( V_148 , V_93 ) ;
break;
}
case V_181 :
case V_170 :
if ( F_98 ( & V_93 -> V_201 ) ||
F_99 ( & V_93 -> V_201 ) ) {
V_200 = F_88 ( V_148 , V_93 ) ;
}
break;
case V_186 :
if ( F_99 ( & V_93 -> V_201 ) ) {
V_200 = F_88 ( V_148 , V_93 ) ;
break;
}
case V_188 :
if ( F_98 ( & V_93 -> V_201 ) ||
F_99 ( & V_93 -> V_201 ) ) {
V_200 = F_94 ( V_148 , V_93 ) ;
}
break;
default:
F_100 () ;
}
return V_200 ;
}
static T_3 F_101 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_148 -> V_169 < V_170 ||
! F_99 ( & V_93 -> V_201 ) )
return 0 ;
return V_93 -> V_207 . V_208 ;
}
static T_3 F_102 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
if ( V_148 -> V_169 >= V_170 )
return V_93 -> V_207 . V_209 ;
if ( V_148 -> V_169 == V_184 &&
( F_99 ( & V_93 -> V_201 ) ||
F_98 ( & V_93 -> V_201 ) ) )
return ( F_103 ( & V_93 -> V_201 ) & 0x1800 ) >> 11 ;
return 0 ;
}
static T_3 F_104 ( struct V_199 * V_93 )
{
int V_210 ;
V_210 = F_105 ( & V_93 -> V_201 ) ;
if ( F_96 ( & V_93 -> V_201 ) )
return V_198 ;
if ( F_97 ( & V_93 -> V_201 ) )
return V_210 ? V_211 : V_212 ;
if ( F_99 ( & V_93 -> V_201 ) )
return V_210 ? V_213 : V_214 ;
if ( F_98 ( & V_93 -> V_201 ) )
return V_210 ? V_215 : V_216 ;
return 0 ;
}
static T_3 F_106 ( struct V_137 * V_148 ,
struct V_199 * V_93 )
{
int V_217 ;
int V_5 ;
if ( F_96 ( & V_93 -> V_201 ) ||
F_97 ( & V_93 -> V_201 ) )
return 0 ;
if ( ( V_148 -> V_169 >= V_181 ) &&
F_107 ( V_93 -> V_207 . V_208 ) )
return F_11 ( V_93 -> V_218 . V_219 ) ;
else if ( V_148 -> V_169 >= V_170 )
return F_108 ( V_93 -> V_207 . V_220 ) ;
V_5 = F_109 ( F_103 ( & V_93 -> V_201 ) ) ;
V_217 = ( F_103 ( & V_93 -> V_201 ) & 0x1800 ) >> 11 ;
return V_5 * ( V_217 + 1 ) ;
}
int F_110 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
struct V_137 * V_148 ,
struct V_199 * V_93 ,
T_1 V_41 )
{
unsigned int V_60 ;
struct V_80 * V_117 ;
struct V_31 * V_165 ;
unsigned int V_5 ;
enum V_21 V_221 ;
T_3 V_222 ;
T_3 V_223 ;
unsigned int V_217 ;
unsigned int V_200 ;
unsigned int V_224 ;
unsigned int V_225 ;
unsigned int V_226 = 0 ;
V_60 = F_111 ( & V_93 -> V_201 ) ;
V_117 = F_42 ( V_3 , V_59 -> V_159 , V_60 ) ;
V_223 = F_104 ( V_93 ) ;
if ( ! V_223 )
return - V_178 ;
V_221 = F_112 ( & V_93 -> V_201 ) ;
V_222 = F_106 ( V_148 , V_93 ) ;
V_200 = F_95 ( V_148 , V_93 ) ;
V_224 = F_101 ( V_148 , V_93 ) ;
V_5 = F_109 ( F_103 ( & V_93 -> V_201 ) ) ;
V_217 = F_102 ( V_148 , V_93 ) ;
V_225 = V_222 ;
if ( ! F_99 ( & V_93 -> V_201 ) )
V_226 = 3 ;
if ( F_97 ( & V_93 -> V_201 ) && V_148 -> V_169 == V_184 )
V_5 = 512 ;
if ( F_96 ( & V_93 -> V_201 ) && V_3 -> V_227 >= 0x100 )
V_225 = 8 ;
if ( ( V_3 -> V_227 > 0x100 ) && F_113 ( V_3 -> V_228 ) )
V_224 = 0 ;
V_59 -> V_65 [ V_60 ] . V_229 =
F_29 ( V_3 , 2 , 1 , V_221 , V_5 , V_41 ) ;
if ( ! V_59 -> V_65 [ V_60 ] . V_229 ) {
if ( V_59 -> V_62 == 0 )
return - V_54 ;
V_59 -> V_62 -- ;
V_59 -> V_65 [ V_60 ] . V_229 =
V_59 -> V_64 [ V_59 -> V_62 ] ;
V_59 -> V_64 [ V_59 -> V_62 ] = NULL ;
F_33 ( V_3 , V_59 -> V_65 [ V_60 ] . V_229 ,
1 , V_221 ) ;
}
V_59 -> V_65 [ V_60 ] . V_230 = false ;
V_165 = V_59 -> V_65 [ V_60 ] . V_229 ;
V_117 -> V_120 = F_6 ( F_114 ( V_222 ) |
F_115 ( V_200 ) |
F_116 ( V_224 ) ) ;
V_117 -> V_197 = F_6 ( F_85 ( V_223 ) |
F_82 ( V_5 ) |
F_86 ( V_217 ) |
F_87 ( V_226 ) ) ;
V_117 -> V_123 = F_10 ( V_165 -> V_45 -> V_8 |
V_165 -> V_4 ) ;
V_117 -> V_231 = F_6 ( F_117 ( V_222 ) |
F_118 ( V_225 ) ) ;
return 0 ;
}
void F_119 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
struct V_199 * V_93 )
{
unsigned int V_60 ;
struct V_80 * V_117 ;
V_60 = F_111 ( & V_93 -> V_201 ) ;
V_117 = F_42 ( V_3 , V_59 -> V_159 , V_60 ) ;
V_117 -> V_120 = 0 ;
V_117 -> V_197 = 0 ;
V_117 -> V_123 = 0 ;
V_117 -> V_231 = 0 ;
}
void F_120 ( struct V_232 * V_233 )
{
V_233 -> V_234 = 0 ;
V_233 -> V_224 = 0 ;
V_233 -> V_235 = 0 ;
V_233 -> V_236 = 0 ;
V_233 -> type = 0 ;
V_233 -> V_222 = 0 ;
}
void F_121 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_78 * V_237 ,
struct V_58 * V_59 )
{
struct V_232 * V_233 ;
struct V_80 * V_117 ;
unsigned int V_238 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < 31 ; ++ V_9 ) {
V_233 = & V_59 -> V_65 [ V_9 ] . V_233 ;
if ( ! F_122 ( V_237 , V_9 ) && F_123 ( V_237 , V_9 ) ) {
F_120 ( V_233 ) ;
continue;
}
if ( F_122 ( V_237 , V_9 ) ) {
V_117 = F_42 ( V_3 , V_159 , V_9 ) ;
V_238 = F_124 ( F_11 ( V_117 -> V_197 ) ) ;
if ( V_238 != V_214 && V_238 != V_216 &&
V_238 != V_213 &&
V_238 != V_215 )
continue;
V_233 -> V_234 = F_125 (
F_11 ( V_117 -> V_120 ) ) ;
V_233 -> V_224 = F_126 (
F_11 ( V_117 -> V_120 ) ) + 1 ;
V_233 -> V_235 = F_127 (
F_11 ( V_117 -> V_197 ) ) + 1 ;
V_233 -> V_236 = F_128 (
F_11 ( V_117 -> V_197 ) ) ;
V_233 -> type = V_238 ;
V_233 -> V_222 = F_129 (
F_11 ( V_117 -> V_231 ) ) ;
}
}
}
void F_130 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_70 * V_160 ,
unsigned int V_60 )
{
struct V_80 * V_239 ;
struct V_80 * V_240 ;
V_239 = F_42 ( V_3 , V_160 , V_60 ) ;
V_240 = F_42 ( V_3 , V_159 , V_60 ) ;
V_240 -> V_120 = V_239 -> V_120 ;
V_240 -> V_197 = V_239 -> V_197 ;
V_240 -> V_123 = V_239 -> V_123 ;
V_240 -> V_231 = V_239 -> V_231 ;
}
void F_131 ( struct V_2 * V_3 ,
struct V_70 * V_159 ,
struct V_70 * V_160 )
{
struct V_79 * V_241 ;
struct V_79 * V_242 ;
V_241 = F_41 ( V_3 , V_159 ) ;
V_242 = F_41 ( V_3 , V_160 ) ;
V_241 -> V_179 = V_242 -> V_179 ;
V_241 -> V_191 = V_242 -> V_191 ;
V_241 -> V_130 = V_242 -> V_130 ;
V_241 -> V_243 = V_242 -> V_243 ;
}
static int F_132 ( struct V_2 * V_3 , T_1 V_6 )
{
int V_9 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
int V_244 = F_133 ( V_3 -> V_245 ) ;
F_35 ( V_3 , V_246 ,
L_30 , V_244 ) ;
if ( ! V_244 )
return 0 ;
V_3 -> V_247 = F_2 ( sizeof( * V_3 -> V_247 ) , V_6 ) ;
if ( ! V_3 -> V_247 )
goto V_248;
V_3 -> V_247 -> V_249 = F_47 ( V_85 ,
V_244 * sizeof( T_5 ) ,
& V_3 -> V_247 -> V_250 , V_6 ) ;
if ( ! V_3 -> V_247 -> V_249 )
goto V_251;
V_3 -> V_247 -> V_252 = F_2 ( sizeof( void * ) * V_244 , V_6 ) ;
if ( ! V_3 -> V_247 -> V_252 )
goto V_253;
V_3 -> V_247 -> V_254 =
F_2 ( sizeof( T_2 ) * V_244 , V_6 ) ;
if ( ! V_3 -> V_247 -> V_254 )
goto V_255;
V_3 -> V_155 -> V_156 [ 0 ] = F_10 ( V_3 -> V_247 -> V_250 ) ;
for ( V_9 = 0 ; V_9 < V_244 ; V_9 ++ ) {
T_2 V_8 ;
void * V_256 = F_47 ( V_85 , V_3 -> V_257 , & V_8 ,
V_6 ) ;
if ( ! V_256 )
goto V_258;
V_3 -> V_247 -> V_249 [ V_9 ] = V_8 ;
V_3 -> V_247 -> V_252 [ V_9 ] = V_256 ;
V_3 -> V_247 -> V_254 [ V_9 ] = V_8 ;
}
return 0 ;
V_258:
for ( V_9 = V_9 - 1 ; V_9 >= 0 ; V_9 -- ) {
F_45 ( V_85 , V_3 -> V_257 ,
V_3 -> V_247 -> V_252 [ V_9 ] ,
V_3 -> V_247 -> V_254 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_247 -> V_254 ) ;
V_255:
F_4 ( V_3 -> V_247 -> V_252 ) ;
V_253:
F_45 ( V_85 , V_244 * sizeof( T_5 ) ,
V_3 -> V_247 -> V_249 ,
V_3 -> V_247 -> V_250 ) ;
V_251:
F_4 ( V_3 -> V_247 ) ;
V_3 -> V_247 = NULL ;
V_248:
return - V_54 ;
}
static void F_134 ( struct V_2 * V_3 )
{
int V_244 ;
int V_9 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
if ( ! V_3 -> V_247 )
return;
V_244 = F_133 ( V_3 -> V_245 ) ;
for ( V_9 = 0 ; V_9 < V_244 ; V_9 ++ ) {
F_45 ( V_85 , V_3 -> V_257 ,
V_3 -> V_247 -> V_252 [ V_9 ] ,
V_3 -> V_247 -> V_254 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_247 -> V_254 ) ;
F_4 ( V_3 -> V_247 -> V_252 ) ;
F_45 ( V_85 , V_244 * sizeof( T_5 ) ,
V_3 -> V_247 -> V_249 ,
V_3 -> V_247 -> V_250 ) ;
F_4 ( V_3 -> V_247 ) ;
V_3 -> V_247 = NULL ;
}
struct V_259 * F_52 ( struct V_2 * V_3 ,
bool V_260 , bool V_261 ,
T_1 V_41 )
{
struct V_259 * V_262 ;
V_262 = F_2 ( sizeof( * V_262 ) , V_41 ) ;
if ( ! V_262 )
return NULL ;
if ( V_260 ) {
V_262 -> V_159 =
F_36 ( V_3 , V_73 ,
V_41 ) ;
if ( ! V_262 -> V_159 ) {
F_4 ( V_262 ) ;
return NULL ;
}
}
if ( V_261 ) {
V_262 -> V_263 =
F_2 ( sizeof( struct V_263 ) , V_41 ) ;
if ( ! V_262 -> V_263 ) {
F_39 ( V_3 , V_262 -> V_159 ) ;
F_4 ( V_262 ) ;
return NULL ;
}
F_75 ( V_262 -> V_263 ) ;
}
V_262 -> V_264 = 0 ;
F_30 ( & V_262 -> V_265 ) ;
return V_262 ;
}
void F_135 ( struct V_266 * V_266 )
{
if ( V_266 ) {
F_4 ( V_266 -> V_267 [ 0 ] ) ;
F_4 ( V_266 ) ;
}
}
void F_55 ( struct V_2 * V_3 ,
struct V_259 * V_262 )
{
F_39 ( V_3 ,
V_262 -> V_159 ) ;
F_4 ( V_262 -> V_263 ) ;
F_4 ( V_262 ) ;
}
void F_136 ( struct V_2 * V_3 )
{
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
int V_74 ;
int V_9 , V_142 , V_141 ;
F_137 ( & V_3 -> V_268 ) ;
V_74 = sizeof( struct V_269 ) * ( V_3 -> V_270 . V_271 ) ;
if ( V_3 -> V_270 . V_272 )
F_45 ( V_85 , V_74 ,
V_3 -> V_270 . V_272 , V_3 -> V_270 . V_273 ) ;
V_3 -> V_270 . V_272 = NULL ;
F_35 ( V_3 , V_246 , L_31 ) ;
if ( V_3 -> V_274 )
F_26 ( V_3 , V_3 -> V_274 ) ;
V_3 -> V_274 = NULL ;
F_35 ( V_3 , V_246 , L_32 ) ;
if ( V_3 -> V_275 )
F_55 ( V_3 , V_3 -> V_275 ) ;
V_3 -> V_275 = NULL ;
if ( V_3 -> V_276 )
F_26 ( V_3 , V_3 -> V_276 ) ;
V_3 -> V_276 = NULL ;
F_35 ( V_3 , V_246 , L_33 ) ;
F_138 ( V_3 ) ;
V_141 = F_65 ( V_3 -> V_133 ) ;
for ( V_9 = 0 ; V_9 < V_141 && V_3 -> V_134 ; V_9 ++ ) {
struct V_145 * V_277 = & V_3 -> V_134 [ V_9 ] . V_146 ;
for ( V_142 = 0 ; V_142 < V_150 ; V_142 ++ ) {
struct V_127 * V_93 = & V_277 -> V_151 [ V_142 ] . V_152 ;
while ( ! F_71 ( V_93 ) )
F_139 ( V_93 -> V_18 ) ;
}
}
for ( V_9 = 1 ; V_9 < V_278 ; ++ V_9 )
F_70 ( V_3 , V_9 ) ;
F_140 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
F_35 ( V_3 , V_246 , L_34 ) ;
F_140 ( V_3 -> V_77 ) ;
V_3 -> V_77 = NULL ;
F_35 ( V_3 , V_246 , L_35 ) ;
F_140 ( V_3 -> V_90 ) ;
V_3 -> V_90 = NULL ;
F_35 ( V_3 , V_246 ,
L_36 ) ;
F_140 ( V_3 -> V_91 ) ;
V_3 -> V_91 = NULL ;
F_35 ( V_3 , V_246 ,
L_37 ) ;
if ( V_3 -> V_155 )
F_45 ( V_85 , sizeof( * V_3 -> V_155 ) ,
V_3 -> V_155 , V_3 -> V_155 -> V_8 ) ;
V_3 -> V_155 = NULL ;
F_134 ( V_3 ) ;
if ( ! V_3 -> V_134 )
goto V_279;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ ) {
struct V_129 * V_140 , * V_280 ;
F_66 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_67 ( & V_140 -> V_136 ) ;
F_4 ( V_140 ) ;
}
}
V_279:
V_3 -> V_105 = 0 ;
V_3 -> V_281 = 0 ;
V_3 -> V_282 = 0 ;
V_3 -> V_283 = 0 ;
F_4 ( V_3 -> V_284 ) ;
F_4 ( V_3 -> V_285 ) ;
F_4 ( V_3 -> V_286 ) ;
F_4 ( V_3 -> V_134 ) ;
F_4 ( V_3 -> V_287 ) ;
V_3 -> V_284 = NULL ;
V_3 -> V_285 = NULL ;
V_3 -> V_286 = NULL ;
V_3 -> V_134 = NULL ;
V_3 -> V_287 = NULL ;
V_3 -> V_257 = 0 ;
V_3 -> V_288 = 0 ;
V_3 -> V_289 [ 0 ] . V_290 = 0 ;
V_3 -> V_289 [ 1 ] . V_290 = 0 ;
}
static int F_141 ( struct V_2 * V_3 ,
struct V_1 * V_291 ,
union V_66 * V_292 ,
union V_66 * V_293 ,
T_2 V_294 ,
struct V_1 * V_295 ,
char * V_296 , int V_297 )
{
unsigned long long V_298 ;
unsigned long long V_299 ;
struct V_1 * V_7 ;
V_298 = F_60 ( V_291 , V_292 ) ;
V_299 = F_60 ( V_291 , V_293 ) ;
V_7 = F_142 ( V_3 , V_291 , V_292 , V_293 , V_294 , false ) ;
if ( V_7 != V_295 ) {
F_72 ( V_3 , L_38 ,
V_296 , V_297 ) ;
F_72 ( V_3 , L_39
L_40 ,
V_291 ,
( unsigned long long ) V_294 ) ;
F_72 ( V_3 , L_41
L_42 ,
V_292 , V_298 ,
V_293 , V_299 ) ;
F_72 ( V_3 , L_43 ,
V_295 , V_7 ) ;
F_142 ( V_3 , V_291 , V_292 , V_293 , V_294 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct {
T_2 V_294 ;
struct V_1 * V_295 ;
} V_300 [] = {
{ 0 , NULL } ,
{ V_3 -> V_274 -> V_45 -> V_8 - 16 , NULL } ,
{ V_3 -> V_274 -> V_45 -> V_8 - 1 , NULL } ,
{ V_3 -> V_274 -> V_45 -> V_8 , V_3 -> V_274 -> V_45 } ,
{ V_3 -> V_274 -> V_45 -> V_8 + ( V_14 - 1 ) * 16 ,
V_3 -> V_274 -> V_45 } ,
{ V_3 -> V_274 -> V_45 -> V_8 + ( V_14 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_274 -> V_45 -> V_8 + ( V_14 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_291 ;
union V_66 * V_292 ;
union V_66 * V_293 ;
T_2 V_294 ;
struct V_1 * V_295 ;
} V_301 [] = {
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = V_3 -> V_274 -> V_45 -> V_10 ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_294 = V_3 -> V_276 -> V_45 -> V_8 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = V_3 -> V_274 -> V_45 -> V_10 ,
. V_293 = & V_3 -> V_276 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_294 = V_3 -> V_276 -> V_45 -> V_8 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = V_3 -> V_276 -> V_45 -> V_10 ,
. V_293 = & V_3 -> V_276 -> V_45 -> V_10 [ V_14 - 1 ] ,
. V_294 = V_3 -> V_276 -> V_45 -> V_8 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = & V_3 -> V_274 -> V_45 -> V_10 [ 0 ] ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ 3 ] ,
. V_294 = V_3 -> V_274 -> V_45 -> V_8 + 4 * 16 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = & V_3 -> V_274 -> V_45 -> V_10 [ 3 ] ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ 6 ] ,
. V_294 = V_3 -> V_274 -> V_45 -> V_8 + 2 * 16 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = & V_3 -> V_274 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ 1 ] ,
. V_294 = V_3 -> V_274 -> V_45 -> V_8 + 2 * 16 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = & V_3 -> V_274 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ 1 ] ,
. V_294 = V_3 -> V_274 -> V_45 -> V_8 + ( V_14 - 4 ) * 16 ,
. V_295 = NULL ,
} ,
{ . V_291 = V_3 -> V_274 -> V_45 ,
. V_292 = & V_3 -> V_274 -> V_45 -> V_10 [ V_14 - 3 ] ,
. V_293 = & V_3 -> V_274 -> V_45 -> V_10 [ 1 ] ,
. V_294 = V_3 -> V_276 -> V_45 -> V_8 + 2 * 16 ,
. V_295 = NULL ,
} ,
} ;
unsigned int V_302 ;
int V_9 , V_43 ;
V_302 = F_144 ( V_300 ) ;
for ( V_9 = 0 ; V_9 < V_302 ; V_9 ++ ) {
V_43 = F_141 ( V_3 ,
V_3 -> V_274 -> V_45 ,
V_3 -> V_274 -> V_45 -> V_10 ,
& V_3 -> V_274 -> V_45 -> V_10 [ V_14 - 1 ] ,
V_300 [ V_9 ] . V_294 ,
V_300 [ V_9 ] . V_295 ,
L_44 , V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_302 = F_144 ( V_301 ) ;
for ( V_9 = 0 ; V_9 < V_302 ; V_9 ++ ) {
V_43 = F_141 ( V_3 ,
V_301 [ V_9 ] . V_291 ,
V_301 [ V_9 ] . V_292 ,
V_301 [ V_9 ] . V_293 ,
V_301 [ V_9 ] . V_294 ,
V_301 [ V_9 ] . V_295 ,
L_45 , V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
}
F_32 ( V_3 , L_46 ) ;
return 0 ;
}
static void F_145 ( struct V_2 * V_3 )
{
T_5 V_303 ;
T_2 V_123 ;
V_123 = F_60 ( V_3 -> V_274 -> V_51 ,
V_3 -> V_274 -> V_50 ) ;
if ( V_123 == 0 && ! F_146 () )
F_72 ( V_3 , L_47
L_48 ) ;
V_303 = F_147 ( V_3 , & V_3 -> V_304 -> V_305 ) ;
V_303 &= V_306 ;
V_303 &= ~ V_307 ;
F_35 ( V_3 , V_246 ,
L_49
L_50 ) ;
F_148 ( V_3 , ( ( T_5 ) V_123 & ( T_5 ) ~ V_306 ) | V_303 ,
& V_3 -> V_304 -> V_305 ) ;
}
static void F_149 ( struct V_2 * V_3 , unsigned int V_141 ,
T_6 T_7 * V_104 , int V_308 )
{
T_3 V_303 , V_309 , V_310 ;
int V_9 ;
T_8 V_311 ;
struct V_312 * V_313 ;
V_303 = F_150 ( V_104 ) ;
V_311 = F_151 ( V_303 ) ;
if ( V_311 == 0x03 ) {
V_313 = & V_3 -> V_314 ;
} else if ( V_311 <= 0x02 ) {
V_313 = & V_3 -> V_315 ;
} else {
F_72 ( V_3 , L_51
L_52 ,
V_104 , V_311 ) ;
return;
}
V_313 -> V_316 = F_151 ( V_303 ) ;
V_313 -> V_317 = F_152 ( V_303 ) ;
V_303 = F_150 ( V_104 + 2 ) ;
V_309 = F_153 ( V_303 ) ;
V_310 = F_154 ( V_303 ) ;
F_35 ( V_3 , V_246 ,
L_53
L_54 ,
V_104 , V_309 , V_310 , V_311 ) ;
if ( V_309 == 0 || ( V_309 + V_310 - 1 ) > V_141 )
return;
V_313 -> V_318 = F_155 ( V_303 ) ;
if ( V_313 -> V_318 ) {
V_313 -> V_319 = F_156 ( V_313 -> V_318 , sizeof( * V_313 -> V_319 ) ,
V_320 ) ;
if ( ! V_313 -> V_319 )
V_313 -> V_318 = 0 ;
V_313 -> V_321 ++ ;
for ( V_9 = 0 ; V_9 < V_313 -> V_318 ; V_9 ++ ) {
V_313 -> V_319 [ V_9 ] = F_150 ( V_104 + 4 + V_9 ) ;
if ( V_9 && ( F_157 ( V_313 -> V_319 [ V_9 ] ) !=
F_157 ( V_313 -> V_319 [ V_9 - 1 ] ) ) )
V_313 -> V_321 ++ ;
F_32 ( V_3 , L_55 ,
F_157 ( V_313 -> V_319 [ V_9 ] ) ,
F_158 ( V_313 -> V_319 [ V_9 ] ) ,
F_159 ( V_313 -> V_319 [ V_9 ] ) ,
F_160 ( V_313 -> V_319 [ V_9 ] ) ,
F_161 ( V_313 -> V_319 [ V_9 ] ) ,
F_162 ( V_313 -> V_319 [ V_9 ] ) ) ;
}
}
if ( V_311 < 0x03 && V_3 -> V_322 < V_308 )
V_3 -> V_287 [ V_3 -> V_322 ++ ] = V_303 ;
if ( ( V_3 -> V_227 == 0x96 ) && ( V_311 != 0x03 ) &&
( V_303 & V_323 ) ) {
F_35 ( V_3 , V_246 ,
L_56 ) ;
V_3 -> V_324 = 1 ;
}
if ( ( V_3 -> V_227 >= 0x100 ) && ( V_311 != 0x03 ) ) {
F_35 ( V_3 , V_246 ,
L_57 ) ;
V_3 -> V_324 = 1 ;
if ( V_303 & V_325 ) {
F_35 ( V_3 , V_246 ,
L_58 ) ;
V_3 -> V_326 = 1 ;
}
}
V_309 -- ;
for ( V_9 = V_309 ; V_9 < ( V_309 + V_310 ) ; V_9 ++ ) {
if ( V_3 -> V_286 [ V_9 ] != 0 ) {
F_72 ( V_3 , L_59
L_60 , V_104 , V_9 ) ;
F_72 ( V_3 , L_61
L_62 ,
V_3 -> V_286 [ V_9 ] , V_311 ) ;
if ( V_3 -> V_286 [ V_9 ] != V_311 &&
V_3 -> V_286 [ V_9 ] != V_327 ) {
if ( V_3 -> V_286 [ V_9 ] == 0x03 )
V_3 -> V_282 -- ;
else
V_3 -> V_281 -- ;
V_3 -> V_286 [ V_9 ] = V_327 ;
}
continue;
}
V_3 -> V_286 [ V_9 ] = V_311 ;
if ( V_311 == 0x03 )
V_3 -> V_282 ++ ;
else
V_3 -> V_281 ++ ;
}
}
static int F_163 ( struct V_2 * V_3 , T_1 V_6 )
{
void T_7 * V_328 ;
T_3 V_329 ;
unsigned int V_141 ;
int V_9 , V_142 , V_330 ;
int V_331 = 0 ;
T_3 V_332 ;
V_141 = F_65 ( V_3 -> V_133 ) ;
V_3 -> V_286 = F_2 ( sizeof( * V_3 -> V_286 ) * V_141 , V_6 ) ;
if ( ! V_3 -> V_286 )
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
V_328 = & V_3 -> V_333 -> V_334 ;
V_332 = F_164 ( V_328 , 0 , V_335 ) ;
if ( ! V_332 ) {
F_165 ( V_3 , L_63 ) ;
return - V_336 ;
}
V_329 = V_332 ;
while ( V_329 ) {
V_331 ++ ;
V_329 = F_164 ( V_328 , V_329 ,
V_335 ) ;
}
V_3 -> V_287 = F_2 ( sizeof( * V_3 -> V_287 ) * V_331 , V_6 ) ;
if ( ! V_3 -> V_287 )
return - V_54 ;
V_329 = V_332 ;
while ( V_329 ) {
F_149 ( V_3 , V_141 , V_328 + V_329 , V_331 ) ;
if ( V_3 -> V_281 + V_3 -> V_282 == V_141 )
break;
V_329 = F_164 ( V_328 , V_329 ,
V_335 ) ;
}
if ( V_3 -> V_281 == 0 && V_3 -> V_282 == 0 ) {
F_72 ( V_3 , L_64 ) ;
return - V_336 ;
}
F_35 ( V_3 , V_246 ,
L_65 ,
V_3 -> V_281 , V_3 -> V_282 ) ;
if ( V_3 -> V_282 > 15 ) {
F_35 ( V_3 , V_246 ,
L_66 ) ;
V_3 -> V_282 = 15 ;
}
if ( V_3 -> V_281 > V_337 ) {
F_35 ( V_3 , V_246 ,
L_67 ,
V_337 ) ;
V_3 -> V_281 = V_337 ;
}
if ( V_3 -> V_281 ) {
V_3 -> V_284 = F_166 ( sizeof( * V_3 -> V_284 ) *
V_3 -> V_281 , V_6 ) ;
if ( ! V_3 -> V_284 )
return - V_54 ;
V_330 = 0 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ ) {
if ( V_3 -> V_286 [ V_9 ] == 0x03 ||
V_3 -> V_286 [ V_9 ] == 0 ||
V_3 -> V_286 [ V_9 ] == V_327 )
continue;
V_3 -> V_284 [ V_330 ] =
& V_3 -> V_338 -> V_339 +
V_340 * V_9 ;
F_35 ( V_3 , V_246 ,
L_68
L_69 , V_9 ,
V_3 -> V_284 [ V_330 ] ) ;
V_330 ++ ;
if ( V_330 == V_3 -> V_281 )
break;
}
}
if ( V_3 -> V_282 ) {
V_3 -> V_285 = F_166 ( sizeof( * V_3 -> V_285 ) *
V_3 -> V_282 , V_6 ) ;
if ( ! V_3 -> V_285 )
return - V_54 ;
V_330 = 0 ;
for ( V_9 = 0 ; V_9 < V_141 ; V_9 ++ )
if ( V_3 -> V_286 [ V_9 ] == 0x03 ) {
V_3 -> V_285 [ V_330 ] =
& V_3 -> V_338 -> V_339 +
V_340 * V_9 ;
F_35 ( V_3 , V_246 ,
L_70
L_69 , V_9 ,
V_3 -> V_285 [ V_330 ] ) ;
V_330 ++ ;
if ( V_330 == V_3 -> V_282 )
break;
}
}
return 0 ;
}
int F_167 ( struct V_2 * V_3 , T_1 V_6 )
{
T_2 V_8 ;
struct V_84 * V_85 = F_44 ( V_3 ) -> V_86 . V_87 ;
unsigned int V_22 , V_341 ;
T_5 V_342 ;
struct V_1 * V_7 ;
T_3 V_257 , V_303 ;
int V_9 ;
F_30 ( & V_3 -> V_265 ) ;
F_63 ( & V_3 -> V_268 , V_343 ,
( unsigned long ) V_3 ) ;
V_257 = F_150 ( & V_3 -> V_338 -> V_257 ) ;
F_35 ( V_3 , V_246 ,
L_71 , V_257 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
if ( ( 0x1 & V_257 ) != 0 )
break;
V_257 = V_257 >> 1 ;
}
if ( V_9 < 16 )
F_35 ( V_3 , V_246 ,
L_72 , ( 1 << ( V_9 + 12 ) ) / 1024 ) ;
else
F_72 ( V_3 , L_73 ) ;
V_3 -> V_288 = 12 ;
V_3 -> V_257 = 1 << V_3 -> V_288 ;
F_35 ( V_3 , V_246 ,
L_74 , V_3 -> V_257 / 1024 ) ;
V_22 = F_168 ( F_150 ( & V_3 -> V_333 -> V_133 ) ) ;
F_35 ( V_3 , V_246 ,
L_75 , V_22 ) ;
V_341 = F_150 ( & V_3 -> V_338 -> V_344 ) ;
V_22 |= ( V_341 & ~ V_345 ) ;
F_35 ( V_3 , V_246 ,
L_76 , V_22 ) ;
F_169 ( V_22 , & V_3 -> V_338 -> V_344 ) ;
V_3 -> V_155 = F_47 ( V_85 , sizeof( * V_3 -> V_155 ) , & V_8 ,
V_320 ) ;
if ( ! V_3 -> V_155 )
goto V_57;
memset ( V_3 -> V_155 , 0 , sizeof *( V_3 -> V_155 ) ) ;
V_3 -> V_155 -> V_8 = V_8 ;
F_35 ( V_3 , V_246 ,
L_77 ,
( unsigned long long ) V_3 -> V_155 -> V_8 , V_3 -> V_155 ) ;
F_148 ( V_3 , V_8 , & V_3 -> V_338 -> V_346 ) ;
V_3 -> V_11 = F_170 ( L_78 , V_85 ,
V_347 , V_347 , V_3 -> V_257 ) ;
V_3 -> V_77 = F_170 ( L_79 , V_85 ,
2112 , 64 , V_3 -> V_257 ) ;
if ( ! V_3 -> V_11 || ! V_3 -> V_77 )
goto V_57;
V_3 -> V_90 =
F_170 ( L_80 ,
V_85 , V_89 , 16 , 0 ) ;
V_3 -> V_91 =
F_170 ( L_81 ,
V_85 , V_88 , 16 , 0 ) ;
if ( ! V_3 -> V_90 || ! V_3 -> V_91 )
goto V_57;
V_3 -> V_276 = F_29 ( V_3 , 1 , 1 , V_348 , 0 , V_6 ) ;
if ( ! V_3 -> V_276 )
goto V_57;
F_35 ( V_3 , V_246 ,
L_82 , V_3 -> V_276 ) ;
F_35 ( V_3 , V_246 , L_83 ,
( unsigned long long ) V_3 -> V_276 -> V_45 -> V_8 ) ;
V_342 = F_147 ( V_3 , & V_3 -> V_338 -> V_276 ) ;
V_342 = ( V_342 & ( T_5 ) V_349 ) |
( V_3 -> V_276 -> V_45 -> V_8 & ( T_5 ) ~ V_349 ) |
V_3 -> V_276 -> V_4 ;
F_35 ( V_3 , V_246 ,
L_84 , V_22 ) ;
F_148 ( V_3 , V_342 , & V_3 -> V_338 -> V_276 ) ;
F_171 ( V_3 ) ;
V_3 -> V_275 = F_52 ( V_3 , true , true , V_6 ) ;
if ( ! V_3 -> V_275 )
goto V_57;
V_3 -> V_105 ++ ;
V_22 = F_150 ( & V_3 -> V_333 -> V_350 ) ;
V_22 &= V_351 ;
F_35 ( V_3 , V_246 ,
L_85
L_86 , V_22 ) ;
V_3 -> V_352 = ( void T_7 * ) V_3 -> V_333 + V_22 ;
F_172 ( V_3 ) ;
F_173 ( V_3 ) ;
V_3 -> V_304 = & V_3 -> V_353 -> V_304 [ 0 ] ;
F_35 ( V_3 , V_246 , L_87 ) ;
V_3 -> V_274 = F_29 ( V_3 , V_354 , 1 , V_23 ,
0 , V_6 ) ;
if ( ! V_3 -> V_274 )
goto V_57;
if ( F_143 ( V_3 ) < 0 )
goto V_57;
V_3 -> V_270 . V_272 = F_47 ( V_85 ,
sizeof( struct V_269 ) * V_354 , & V_8 ,
V_320 ) ;
if ( ! V_3 -> V_270 . V_272 )
goto V_57;
F_35 ( V_3 , V_246 ,
L_88 ,
( unsigned long long ) V_8 ) ;
memset ( V_3 -> V_270 . V_272 , 0 , sizeof( struct V_269 ) * V_354 ) ;
V_3 -> V_270 . V_271 = V_354 ;
V_3 -> V_270 . V_273 = V_8 ;
F_35 ( V_3 , V_246 ,
L_89 ,
V_3 -> V_270 . V_271 ,
V_3 -> V_270 . V_272 ,
( unsigned long long ) V_3 -> V_270 . V_273 ) ;
for ( V_22 = 0 , V_7 = V_3 -> V_274 -> V_45 ; V_22 < V_354 ; V_22 ++ ) {
struct V_269 * V_355 = & V_3 -> V_270 . V_272 [ V_22 ] ;
V_355 -> V_356 = F_10 ( V_7 -> V_8 ) ;
V_355 -> V_357 = F_6 ( V_14 ) ;
V_355 -> V_358 = 0 ;
V_7 = V_7 -> V_18 ;
}
V_22 = F_150 ( & V_3 -> V_304 -> V_359 ) ;
V_22 &= V_360 ;
V_22 |= V_354 ;
F_35 ( V_3 , V_246 ,
L_90 ,
V_22 ) ;
F_169 ( V_22 , & V_3 -> V_304 -> V_359 ) ;
F_35 ( V_3 , V_246 ,
L_91 ) ;
F_35 ( V_3 , V_246 ,
L_92 ,
( unsigned long long ) V_3 -> V_270 . V_273 ) ;
V_342 = F_147 ( V_3 , & V_3 -> V_304 -> V_361 ) ;
V_342 &= V_306 ;
V_342 |= ( V_3 -> V_270 . V_273 & ( T_5 ) ~ V_306 ) ;
F_148 ( V_3 , V_342 , & V_3 -> V_304 -> V_361 ) ;
F_145 ( V_3 ) ;
F_35 ( V_3 , V_246 ,
L_93 ) ;
F_174 ( V_3 , 0 ) ;
F_75 ( & V_3 -> V_362 ) ;
for ( V_9 = 0 ; V_9 < V_278 ; ++ V_9 )
V_3 -> V_154 [ V_9 ] = NULL ;
for ( V_9 = 0 ; V_9 < V_337 ; ++ V_9 ) {
V_3 -> V_289 [ 0 ] . V_363 [ V_9 ] = 0 ;
V_3 -> V_289 [ 1 ] . V_363 [ V_9 ] = 0 ;
F_75 ( & V_3 -> V_289 [ 1 ] . V_364 [ V_9 ] ) ;
}
if ( F_132 ( V_3 , V_6 ) )
goto V_57;
if ( F_163 ( V_3 , V_6 ) )
goto V_57;
V_303 = F_150 ( & V_3 -> V_338 -> V_365 ) ;
V_303 &= ~ V_366 ;
V_303 |= V_367 ;
F_169 ( V_303 , & V_3 -> V_338 -> V_365 ) ;
return 0 ;
V_57:
F_72 ( V_3 , L_94 ) ;
F_175 ( V_3 ) ;
F_176 ( V_3 ) ;
F_136 ( V_3 ) ;
return - V_54 ;
}
