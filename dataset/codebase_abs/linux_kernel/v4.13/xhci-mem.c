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
F_26 ( V_3 , V_56 -> V_58 [ V_57 ] . V_31 ) ;
V_56 -> V_58 [ V_57 ] . V_31 = NULL ;
}
int F_34 ( struct V_2 * V_3 , struct V_30 * V_31 ,
unsigned int V_59 , T_1 V_6 )
{
struct V_1 * V_18 ;
struct V_1 * V_32 ;
unsigned int V_33 ;
unsigned int V_60 ;
int V_42 ;
V_60 = ( V_59 + ( V_13 - 1 ) - 1 ) /
( V_13 - 1 ) ;
V_33 = V_31 -> V_33 > V_60 ?
V_31 -> V_33 : V_60 ;
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
F_35 ( V_31 ) ;
F_36 ( V_3 , V_61 ,
L_1 ,
V_31 -> V_33 ) ;
return 0 ;
}
static struct V_62 * F_37 ( struct V_2 * V_3 ,
int type , T_1 V_6 )
{
struct V_62 * V_63 ;
if ( ( type != V_64 ) && ( type != V_65 ) )
return NULL ;
V_63 = F_2 ( sizeof( * V_63 ) , V_6 ) ;
if ( ! V_63 )
return NULL ;
V_63 -> type = type ;
V_63 -> V_66 = F_38 ( V_3 -> V_67 ) ? 2048 : 1024 ;
if ( type == V_65 )
V_63 -> V_66 += F_39 ( V_3 -> V_67 ) ;
V_63 -> V_68 = F_3 ( V_3 -> V_69 , V_6 , & V_63 -> V_8 ) ;
if ( ! V_63 -> V_68 ) {
F_4 ( V_63 ) ;
return NULL ;
}
return V_63 ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
if ( ! V_63 )
return;
F_5 ( V_3 -> V_69 , V_63 -> V_68 , V_63 -> V_8 ) ;
F_4 ( V_63 ) ;
}
struct V_70 * F_41 (
struct V_62 * V_63 )
{
if ( V_63 -> type != V_65 )
return NULL ;
return (struct V_70 * ) V_63 -> V_68 ;
}
struct V_71 * F_42 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
if ( V_63 -> type == V_64 )
return (struct V_71 * ) V_63 -> V_68 ;
return (struct V_71 * )
( V_63 -> V_68 + F_39 ( V_3 -> V_67 ) ) ;
}
struct V_72 * F_43 ( struct V_2 * V_3 ,
struct V_62 * V_63 ,
unsigned int V_57 )
{
V_57 ++ ;
if ( V_63 -> type == V_65 )
V_57 ++ ;
return (struct V_72 * )
( V_63 -> V_68 + ( V_57 * F_39 ( V_3 -> V_67 ) ) ) ;
}
static void F_44 ( struct V_2 * V_3 ,
unsigned int V_73 ,
struct V_74 * V_75 , T_2 V_8 )
{
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
T_4 V_66 = sizeof( struct V_74 ) * V_73 ;
if ( V_66 > V_80 )
F_46 ( V_77 , V_66 ,
V_75 , V_8 ) ;
else if ( V_66 <= V_81 )
return F_5 ( V_3 -> V_82 ,
V_75 , V_8 ) ;
else
return F_5 ( V_3 -> V_83 ,
V_75 , V_8 ) ;
}
static struct V_74 * F_47 ( struct V_2 * V_3 ,
unsigned int V_73 , T_2 * V_8 ,
T_1 V_40 )
{
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
T_4 V_66 = sizeof( struct V_74 ) * V_73 ;
if ( V_66 > V_80 )
return F_48 ( V_77 , V_66 ,
V_8 , V_40 ) ;
else if ( V_66 <= V_81 )
return F_49 ( V_3 -> V_82 ,
V_40 , V_8 ) ;
else
return F_49 ( V_3 -> V_83 ,
V_40 , V_8 ) ;
}
struct V_30 * F_50 (
struct V_84 * V_85 ,
T_5 V_86 )
{
if ( V_85 -> V_87 & V_88 )
return F_16 ( & V_85 -> V_89 -> V_39 ,
V_86 >> V_43 ) ;
return V_85 -> V_31 ;
}
struct V_30 * F_51 (
struct V_55 * V_77 ,
unsigned int V_57 ,
unsigned int V_90 )
{
struct V_84 * V_85 = & V_77 -> V_58 [ V_57 ] ;
if ( V_90 == 0 )
return V_85 -> V_31 ;
if ( ! V_85 -> V_89 )
return NULL ;
if ( V_90 > V_85 -> V_89 -> V_91 )
return NULL ;
return V_85 -> V_89 -> V_92 [ V_90 ] ;
}
struct V_93 * F_52 ( struct V_2 * V_3 ,
unsigned int V_73 ,
unsigned int V_91 ,
unsigned int V_5 , T_1 V_40 )
{
struct V_93 * V_89 ;
T_3 V_94 ;
struct V_30 * V_95 ;
T_5 V_96 ;
int V_42 ;
F_53 ( V_3 , L_2
L_3 ,
V_91 , V_73 ) ;
if ( V_3 -> V_97 == V_98 ) {
F_53 ( V_3 , L_4 ) ;
return NULL ;
}
V_3 -> V_97 ++ ;
V_89 = F_2 ( sizeof( struct V_93 ) , V_40 ) ;
if ( ! V_89 )
goto V_99;
V_89 -> V_91 = V_91 ;
V_89 -> V_73 = V_73 ;
V_89 -> V_92 = F_2 (
sizeof( struct V_30 * ) * V_91 ,
V_40 ) ;
if ( ! V_89 -> V_92 )
goto V_100;
V_89 -> V_101 = F_47 ( V_3 ,
V_73 , & V_89 -> V_102 ,
V_40 ) ;
if ( ! V_89 -> V_101 )
goto V_103;
memset ( V_89 -> V_101 , 0 ,
sizeof( struct V_74 ) * V_73 ) ;
V_89 -> V_104 =
F_54 ( V_3 , true , true , V_40 ) ;
if ( ! V_89 -> V_104 )
goto V_103;
F_55 ( & V_89 -> V_39 , V_105 ) ;
for ( V_94 = 1 ; V_94 < V_91 ; V_94 ++ ) {
V_89 -> V_92 [ V_94 ] =
F_30 ( V_3 , 2 , 1 , V_47 , V_5 ,
V_40 ) ;
V_95 = V_89 -> V_92 [ V_94 ] ;
if ( ! V_95 )
goto V_106;
V_95 -> V_90 = V_94 ;
V_95 -> V_39 = & V_89 -> V_39 ;
V_96 = V_95 -> V_44 -> V_8 |
F_56 ( V_107 ) |
V_95 -> V_4 ;
V_89 -> V_101 [ V_94 ] . V_108 =
F_10 ( V_96 ) ;
F_53 ( V_3 , L_5 ,
V_94 , ( unsigned long long ) V_96 ) ;
V_42 = F_25 ( V_95 , V_40 ) ;
if ( V_42 ) {
F_26 ( V_3 , V_95 ) ;
V_89 -> V_92 [ V_94 ] = NULL ;
goto V_106;
}
}
return V_89 ;
V_106:
for ( V_94 = 1 ; V_94 < V_91 ; V_94 ++ ) {
V_95 = V_89 -> V_92 [ V_94 ] ;
if ( V_95 ) {
F_26 ( V_3 , V_95 ) ;
V_89 -> V_92 [ V_94 ] = NULL ;
}
}
F_57 ( V_3 , V_89 -> V_104 ) ;
V_103:
F_4 ( V_89 -> V_92 ) ;
V_100:
F_4 ( V_89 ) ;
V_99:
V_3 -> V_97 -- ;
return NULL ;
}
void F_58 ( struct V_2 * V_3 ,
struct V_72 * V_109 ,
struct V_93 * V_89 )
{
T_3 V_110 ;
V_110 = F_59 ( V_89 -> V_73 ) - 2 ;
F_36 ( V_3 , V_111 ,
L_6 ,
1 << ( V_110 + 1 ) ) ;
V_109 -> V_112 &= F_6 ( ~ V_113 ) ;
V_109 -> V_112 |= F_6 ( F_60 ( V_110 )
| V_114 ) ;
V_109 -> V_115 = F_10 ( V_89 -> V_102 ) ;
}
void F_61 ( struct V_72 * V_109 ,
struct V_84 * V_85 )
{
T_2 V_96 ;
V_109 -> V_112 &= F_6 ( ~ ( V_113 | V_114 ) ) ;
V_96 = F_62 ( V_85 -> V_31 -> V_50 , V_85 -> V_31 -> V_49 ) ;
V_109 -> V_115 = F_10 ( V_96 | V_85 -> V_31 -> V_4 ) ;
}
void F_63 ( struct V_2 * V_3 ,
struct V_93 * V_89 )
{
int V_94 ;
struct V_30 * V_95 ;
if ( ! V_89 )
return;
for ( V_94 = 1 ; V_94 < V_89 -> V_91 ;
V_94 ++ ) {
V_95 = V_89 -> V_92 [ V_94 ] ;
if ( V_95 ) {
F_26 ( V_3 , V_95 ) ;
V_89 -> V_92 [ V_94 ] = NULL ;
}
}
F_57 ( V_3 , V_89 -> V_104 ) ;
V_3 -> V_97 -- ;
if ( V_89 -> V_101 )
F_44 ( V_3 ,
V_89 -> V_73 ,
V_89 -> V_101 ,
V_89 -> V_102 ) ;
F_4 ( V_89 -> V_92 ) ;
F_4 ( V_89 ) ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_84 * V_85 )
{
F_65 ( & V_85 -> V_116 , V_117 ,
( unsigned long ) V_85 ) ;
V_85 -> V_3 = V_3 ;
}
static void F_66 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
int V_118 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 , * V_17 ;
bool V_123 = false ;
if ( V_56 -> V_124 == 0 ||
V_56 -> V_124 > F_67 ( V_3 -> V_125 ) ) {
F_53 ( V_3 , L_7 ) ;
return;
}
V_120 = & ( V_3 -> V_126 [ V_56 -> V_124 - 1 ] . V_127 ) ;
F_68 (tt_info, next, tt_list_head, tt_list) {
if ( V_122 -> V_118 == V_118 ) {
V_123 = true ;
F_69 ( & V_122 -> V_128 ) ;
F_4 ( V_122 ) ;
} else if ( V_123 ) {
break;
}
}
}
int F_70 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_129 * V_130 ,
struct V_131 * V_132 , T_1 V_40 )
{
struct V_121 * V_122 ;
unsigned int V_133 ;
int V_9 , V_134 ;
if ( ! V_132 -> V_135 )
V_133 = 1 ;
else
V_133 = V_130 -> V_136 ;
for ( V_9 = 0 ; V_9 < V_133 ; V_9 ++ , V_122 ++ ) {
struct V_137 * V_138 ;
V_122 = F_2 ( sizeof( * V_122 ) , V_40 ) ;
if ( ! V_122 )
goto V_139;
F_31 ( & V_122 -> V_128 ) ;
F_71 ( & V_122 -> V_128 ,
& V_3 -> V_126 [ V_56 -> V_124 - 1 ] . V_127 ) ;
V_122 -> V_118 = V_56 -> V_140 -> V_118 ;
if ( V_132 -> V_135 )
V_122 -> V_141 = V_9 + 1 ;
V_138 = & V_122 -> V_138 ;
for ( V_134 = 0 ; V_134 < V_142 ; V_134 ++ )
F_31 ( & V_138 -> V_143 [ V_134 ] . V_144 ) ;
}
return 0 ;
V_139:
F_66 ( V_3 , V_56 , V_56 -> V_140 -> V_118 ) ;
return - V_51 ;
}
void F_72 ( struct V_2 * V_3 , int V_118 )
{
struct V_55 * V_77 ;
int V_9 ;
int V_145 = 0 ;
if ( V_118 == 0 || ! V_3 -> V_146 [ V_118 ] )
return;
V_77 = V_3 -> V_146 [ V_118 ] ;
F_73 ( V_77 ) ;
V_3 -> V_147 -> V_148 [ V_118 ] = 0 ;
if ( ! V_77 )
return;
if ( V_77 -> V_122 )
V_145 = V_77 -> V_122 -> V_149 ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
if ( V_77 -> V_58 [ V_9 ] . V_31 )
F_26 ( V_3 , V_77 -> V_58 [ V_9 ] . V_31 ) ;
if ( V_77 -> V_58 [ V_9 ] . V_89 )
F_63 ( V_3 ,
V_77 -> V_58 [ V_9 ] . V_89 ) ;
if ( ! F_74 ( & V_77 -> V_58 [ V_9 ] . V_150 ) )
F_75 ( V_3 , L_8
L_9 ,
V_118 , V_9 ) ;
}
F_66 ( V_3 , V_77 , V_118 ) ;
F_76 ( V_3 , V_77 , V_145 ) ;
if ( V_77 -> V_151 )
F_40 ( V_3 , V_77 -> V_151 ) ;
if ( V_77 -> V_152 )
F_40 ( V_3 , V_77 -> V_152 ) ;
F_4 ( V_3 -> V_146 [ V_118 ] ) ;
V_3 -> V_146 [ V_118 ] = NULL ;
}
void F_77 ( struct V_2 * V_3 , int V_118 )
{
struct V_55 * V_153 ;
struct V_119 * V_120 ;
struct V_121 * V_122 , * V_17 ;
int V_9 ;
V_153 = V_3 -> V_146 [ V_118 ] ;
if ( ! V_153 )
return;
V_120 = & ( V_3 -> V_126 [ V_153 -> V_124 - 1 ] . V_127 ) ;
F_68 (tt_info, next, tt_list_head, tt_list) {
if ( V_122 -> V_118 == V_118 ) {
for ( V_9 = 1 ; V_9 < F_78 ( V_3 -> V_125 ) ; V_9 ++ ) {
V_153 = V_3 -> V_146 [ V_9 ] ;
if ( V_153 && ( V_153 -> V_122 == V_122 ) )
F_77 (
V_3 , V_9 ) ;
}
}
}
F_72 ( V_3 , V_118 ) ;
}
int F_79 ( struct V_2 * V_3 , int V_118 ,
struct V_129 * V_140 , T_1 V_6 )
{
struct V_55 * V_77 ;
int V_9 ;
if ( V_118 == 0 || V_3 -> V_146 [ V_118 ] ) {
F_75 ( V_3 , L_10 , V_118 ) ;
return 0 ;
}
V_3 -> V_146 [ V_118 ] = F_2 ( sizeof( * V_3 -> V_146 [ V_118 ] ) , V_6 ) ;
if ( ! V_3 -> V_146 [ V_118 ] )
return 0 ;
V_77 = V_3 -> V_146 [ V_118 ] ;
V_77 -> V_152 = F_37 ( V_3 , V_64 , V_6 ) ;
if ( ! V_77 -> V_152 )
goto V_54;
F_53 ( V_3 , L_11 , V_118 ,
( unsigned long long ) V_77 -> V_152 -> V_8 ) ;
V_77 -> V_151 = F_37 ( V_3 , V_65 , V_6 ) ;
if ( ! V_77 -> V_151 )
goto V_54;
F_53 ( V_3 , L_12 , V_118 ,
( unsigned long long ) V_77 -> V_151 -> V_8 ) ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
F_64 ( V_3 , & V_77 -> V_58 [ V_9 ] ) ;
F_31 ( & V_77 -> V_58 [ V_9 ] . V_154 ) ;
F_31 ( & V_77 -> V_58 [ V_9 ] . V_150 ) ;
}
V_77 -> V_58 [ 0 ] . V_31 = F_30 ( V_3 , 2 , 1 , V_155 , 0 , V_6 ) ;
if ( ! V_77 -> V_58 [ 0 ] . V_31 )
goto V_54;
V_77 -> V_140 = V_140 ;
V_3 -> V_147 -> V_148 [ V_118 ] = F_10 ( V_77 -> V_152 -> V_8 ) ;
F_53 ( V_3 , L_13 ,
V_118 ,
& V_3 -> V_147 -> V_148 [ V_118 ] ,
F_80 ( V_3 -> V_147 -> V_148 [ V_118 ] ) ) ;
F_81 ( V_77 ) ;
return 1 ;
V_54:
F_72 ( V_3 , V_118 ) ;
return 0 ;
}
void F_82 ( struct V_2 * V_3 ,
struct V_129 * V_140 )
{
struct V_55 * V_56 ;
struct V_72 * V_156 ;
struct V_30 * V_157 ;
V_56 = V_3 -> V_146 [ V_140 -> V_118 ] ;
V_156 = F_43 ( V_3 , V_56 -> V_151 , 0 ) ;
V_157 = V_56 -> V_58 [ 0 ] . V_31 ;
V_156 -> V_115 = F_10 ( F_62 ( V_157 -> V_34 ,
V_157 -> V_48 )
| V_157 -> V_4 ) ;
}
static T_3 F_83 ( struct V_2 * V_3 ,
struct V_129 * V_140 )
{
struct V_129 * V_158 ;
struct V_159 * V_160 ;
if ( V_140 -> V_161 >= V_162 )
V_160 = V_3 -> V_163 ;
else
V_160 = V_3 -> V_164 ;
for ( V_158 = V_140 ; V_158 -> V_165 && V_158 -> V_165 -> V_165 ;
V_158 = V_158 -> V_165 )
;
return F_84 ( V_160 , V_158 -> V_166 ) ;
}
int F_85 ( struct V_2 * V_3 , struct V_129 * V_140 )
{
struct V_55 * V_77 ;
struct V_72 * V_156 ;
struct V_71 * V_167 ;
T_3 V_168 ;
T_3 V_169 ;
struct V_129 * V_158 ;
V_77 = V_3 -> V_146 [ V_140 -> V_118 ] ;
if ( V_140 -> V_118 == 0 || ! V_77 ) {
F_75 ( V_3 , L_14 ,
V_140 -> V_118 ) ;
return - V_170 ;
}
V_156 = F_43 ( V_3 , V_77 -> V_151 , 0 ) ;
V_167 = F_42 ( V_3 , V_77 -> V_151 ) ;
V_167 -> V_171 |= F_6 ( F_86 ( 1 ) | V_140 -> V_172 ) ;
switch ( V_140 -> V_161 ) {
case V_173 :
V_167 -> V_171 |= F_6 ( V_174 ) ;
V_169 = F_87 ( 512 ) ;
break;
case V_162 :
V_167 -> V_171 |= F_6 ( V_175 ) ;
V_169 = F_87 ( 512 ) ;
break;
case V_176 :
V_167 -> V_171 |= F_6 ( V_177 ) ;
V_169 = F_87 ( 64 ) ;
break;
case V_178 :
V_167 -> V_171 |= F_6 ( V_179 ) ;
V_169 = F_87 ( 64 ) ;
break;
case V_180 :
V_167 -> V_171 |= F_6 ( V_181 ) ;
V_169 = F_87 ( 8 ) ;
break;
case V_182 :
F_53 ( V_3 , L_15 ) ;
return - V_170 ;
break;
default:
return - V_170 ;
}
V_168 = F_83 ( V_3 , V_140 ) ;
if ( ! V_168 )
return - V_170 ;
V_167 -> V_183 |= F_6 ( F_88 ( V_168 ) ) ;
for ( V_158 = V_140 ; V_158 -> V_165 && V_158 -> V_165 -> V_165 ;
V_158 = V_158 -> V_165 )
;
V_77 -> V_184 = V_158 -> V_166 ;
V_77 -> V_124 = V_168 ;
F_53 ( V_3 , L_16 , V_168 ) ;
F_53 ( V_3 , L_17 , V_77 -> V_184 ) ;
if ( ! V_140 -> V_132 || ! V_140 -> V_132 -> V_185 -> V_165 ) {
V_77 -> V_138 = & V_3 -> V_126 [ V_168 - 1 ] . V_138 ;
} else {
struct V_186 * V_126 ;
struct V_121 * V_187 ;
V_126 = & V_3 -> V_126 [ V_168 - 1 ] ;
F_89 (tt_bw, &rh_bw->tts, tt_list) {
if ( V_187 -> V_118 != V_140 -> V_132 -> V_185 -> V_118 )
continue;
if ( ! V_77 -> V_140 -> V_132 -> V_135 ||
( V_140 -> V_132 -> V_135 &&
V_187 -> V_141 == V_77 -> V_140 -> V_141 ) ) {
V_77 -> V_138 = & V_187 -> V_138 ;
V_77 -> V_122 = V_187 ;
break;
}
}
if ( ! V_77 -> V_122 )
F_75 ( V_3 , L_18 ) ;
}
if ( V_140 -> V_132 && V_140 -> V_132 -> V_185 -> V_165 ) {
V_167 -> V_122 = F_6 ( V_140 -> V_132 -> V_185 -> V_118 |
( V_140 -> V_141 << 8 ) ) ;
if ( V_140 -> V_132 -> V_135 )
V_167 -> V_171 |= F_6 ( V_188 ) ;
}
F_53 ( V_3 , L_19 , V_140 -> V_132 ) ;
F_53 ( V_3 , L_20 , V_140 -> V_141 ) ;
V_156 -> V_189 = F_6 ( F_90 ( V_190 ) ) ;
V_156 -> V_189 |= F_6 ( F_91 ( 0 ) | F_92 ( 3 ) |
V_169 ) ;
V_156 -> V_115 = F_10 ( V_77 -> V_58 [ 0 ] . V_31 -> V_44 -> V_8 |
V_77 -> V_58 [ 0 ] . V_31 -> V_4 ) ;
F_93 ( V_77 ) ;
return 0 ;
}
static unsigned int F_94 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
unsigned int V_192 ;
V_192 = F_95 ( V_85 -> V_193 . V_194 , 1 , 16 ) - 1 ;
if ( V_192 != V_85 -> V_193 . V_194 - 1 )
F_96 ( & V_140 -> V_77 ,
L_21 ,
V_85 -> V_193 . V_195 ,
1 << V_192 ,
V_140 -> V_161 == V_178 ? L_22 : L_23 ) ;
if ( V_140 -> V_161 == V_178 ) {
V_192 += 3 ;
}
return V_192 ;
}
static unsigned int F_97 ( struct V_129 * V_140 ,
struct V_191 * V_85 , unsigned int V_196 ,
unsigned int V_197 , unsigned int V_198 )
{
unsigned int V_192 ;
V_192 = F_59 ( V_196 ) - 1 ;
V_192 = F_95 ( V_192 , V_197 , V_198 ) ;
if ( ( 1 << V_192 ) != V_196 )
F_98 ( & V_140 -> V_77 ,
L_24 ,
V_85 -> V_193 . V_195 ,
1 << V_192 ,
V_196 ) ;
return V_192 ;
}
static unsigned int F_99 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
if ( V_85 -> V_193 . V_194 == 0 )
return 0 ;
return F_97 ( V_140 , V_85 ,
V_85 -> V_193 . V_194 , 0 , 15 ) ;
}
static unsigned int F_100 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
return F_97 ( V_140 , V_85 ,
V_85 -> V_193 . V_194 * 8 , 3 , 10 ) ;
}
static unsigned int F_101 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
unsigned int V_192 = 0 ;
switch ( V_140 -> V_161 ) {
case V_176 :
if ( F_102 ( & V_85 -> V_193 ) ||
F_103 ( & V_85 -> V_193 ) ) {
V_192 = F_99 ( V_140 , V_85 ) ;
break;
}
case V_173 :
case V_162 :
if ( F_104 ( & V_85 -> V_193 ) ||
F_105 ( & V_85 -> V_193 ) ) {
V_192 = F_94 ( V_140 , V_85 ) ;
}
break;
case V_178 :
if ( F_105 ( & V_85 -> V_193 ) ) {
V_192 = F_94 ( V_140 , V_85 ) ;
break;
}
case V_180 :
if ( F_104 ( & V_85 -> V_193 ) ||
F_105 ( & V_85 -> V_193 ) ) {
V_192 = F_100 ( V_140 , V_85 ) ;
}
break;
default:
F_106 () ;
}
return V_192 ;
}
static T_3 F_107 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
if ( V_140 -> V_161 < V_162 ||
! F_105 ( & V_85 -> V_193 ) )
return 0 ;
return V_85 -> V_199 . V_200 ;
}
static T_3 F_108 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
if ( V_140 -> V_161 >= V_162 )
return V_85 -> V_199 . V_201 ;
if ( V_140 -> V_161 == V_176 &&
( F_105 ( & V_85 -> V_193 ) ||
F_104 ( & V_85 -> V_193 ) ) )
return F_109 ( & V_85 -> V_193 ) - 1 ;
return 0 ;
}
static T_3 F_110 ( struct V_191 * V_85 )
{
int V_202 ;
V_202 = F_111 ( & V_85 -> V_193 ) ;
switch ( F_112 ( & V_85 -> V_193 ) ) {
case V_203 :
return V_190 ;
case V_204 :
return V_202 ? V_205 : V_206 ;
case V_207 :
return V_202 ? V_208 : V_209 ;
case V_210 :
return V_202 ? V_211 : V_212 ;
}
return 0 ;
}
static T_3 F_113 ( struct V_129 * V_140 ,
struct V_191 * V_85 )
{
int V_213 ;
int V_5 ;
if ( F_102 ( & V_85 -> V_193 ) ||
F_103 ( & V_85 -> V_193 ) )
return 0 ;
if ( ( V_140 -> V_161 >= V_173 ) &&
F_114 ( V_85 -> V_199 . V_200 ) )
return F_11 ( V_85 -> V_214 . V_215 ) ;
else if ( V_140 -> V_161 >= V_162 )
return F_115 ( V_85 -> V_199 . V_216 ) ;
V_5 = F_116 ( & V_85 -> V_193 ) ;
V_213 = F_109 ( & V_85 -> V_193 ) ;
return V_5 * V_213 ;
}
int F_117 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_129 * V_140 ,
struct V_191 * V_85 ,
T_1 V_40 )
{
unsigned int V_57 ;
struct V_72 * V_109 ;
struct V_30 * V_157 ;
unsigned int V_5 ;
enum V_20 V_217 ;
T_3 V_218 ;
T_3 V_219 ;
unsigned int V_213 ;
unsigned int V_192 ;
unsigned int V_220 ;
unsigned int V_221 ;
unsigned int V_222 = 0 ;
V_57 = F_118 ( & V_85 -> V_193 ) ;
V_109 = F_43 ( V_3 , V_56 -> V_151 , V_57 ) ;
V_219 = F_110 ( V_85 ) ;
if ( ! V_219 )
return - V_170 ;
V_217 = F_112 ( & V_85 -> V_193 ) ;
V_218 = F_113 ( V_140 , V_85 ) ;
V_192 = F_101 ( V_140 , V_85 ) ;
if ( F_104 ( & V_85 -> V_193 ) ||
F_105 ( & V_85 -> V_193 ) ) {
if ( ( V_3 -> V_27 & V_223 ) &&
V_140 -> V_161 >= V_176 &&
V_192 >= 7 ) {
V_192 = 6 ;
}
}
V_220 = F_107 ( V_140 , V_85 ) ;
V_5 = F_116 ( & V_85 -> V_193 ) ;
V_213 = F_108 ( V_140 , V_85 ) ;
V_221 = V_218 ;
if ( ! F_105 ( & V_85 -> V_193 ) )
V_222 = 3 ;
if ( F_103 ( & V_85 -> V_193 ) && V_140 -> V_161 == V_176 )
V_5 = 512 ;
if ( F_102 ( & V_85 -> V_193 ) && V_3 -> V_224 >= 0x100 )
V_221 = 8 ;
if ( ( V_3 -> V_224 > 0x100 ) && F_119 ( V_3 -> V_225 ) )
V_220 = 0 ;
V_56 -> V_58 [ V_57 ] . V_226 =
F_30 ( V_3 , 2 , 1 , V_217 , V_5 , V_40 ) ;
if ( ! V_56 -> V_58 [ V_57 ] . V_226 )
return - V_51 ;
V_56 -> V_58 [ V_57 ] . V_227 = false ;
V_157 = V_56 -> V_58 [ V_57 ] . V_226 ;
V_109 -> V_112 = F_6 ( F_120 ( V_218 ) |
F_121 ( V_192 ) |
F_122 ( V_220 ) ) ;
V_109 -> V_189 = F_6 ( F_90 ( V_219 ) |
F_87 ( V_5 ) |
F_91 ( V_213 ) |
F_92 ( V_222 ) ) ;
V_109 -> V_115 = F_10 ( V_157 -> V_44 -> V_8 |
V_157 -> V_4 ) ;
V_109 -> V_228 = F_6 ( F_123 ( V_218 ) |
F_124 ( V_221 ) ) ;
return 0 ;
}
void F_125 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
struct V_191 * V_85 )
{
unsigned int V_57 ;
struct V_72 * V_109 ;
V_57 = F_118 ( & V_85 -> V_193 ) ;
V_109 = F_43 ( V_3 , V_56 -> V_151 , V_57 ) ;
V_109 -> V_112 = 0 ;
V_109 -> V_189 = 0 ;
V_109 -> V_115 = 0 ;
V_109 -> V_228 = 0 ;
}
void F_126 ( struct V_229 * V_230 )
{
V_230 -> V_231 = 0 ;
V_230 -> V_220 = 0 ;
V_230 -> V_232 = 0 ;
V_230 -> V_233 = 0 ;
V_230 -> type = 0 ;
V_230 -> V_218 = 0 ;
}
void F_127 ( struct V_2 * V_3 ,
struct V_62 * V_151 ,
struct V_70 * V_234 ,
struct V_55 * V_56 )
{
struct V_229 * V_230 ;
struct V_72 * V_109 ;
unsigned int V_235 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < 31 ; V_9 ++ ) {
V_230 = & V_56 -> V_58 [ V_9 ] . V_230 ;
if ( ! F_128 ( V_234 , V_9 ) && F_129 ( V_234 , V_9 ) ) {
F_126 ( V_230 ) ;
continue;
}
if ( F_128 ( V_234 , V_9 ) ) {
V_109 = F_43 ( V_3 , V_151 , V_9 ) ;
V_235 = F_130 ( F_11 ( V_109 -> V_189 ) ) ;
if ( V_235 != V_209 && V_235 != V_212 &&
V_235 != V_208 &&
V_235 != V_211 )
continue;
V_230 -> V_231 = F_131 (
F_11 ( V_109 -> V_112 ) ) ;
V_230 -> V_220 = F_132 (
F_11 ( V_109 -> V_112 ) ) + 1 ;
V_230 -> V_232 = F_133 (
F_11 ( V_109 -> V_189 ) ) + 1 ;
V_230 -> V_233 = F_134 (
F_11 ( V_109 -> V_189 ) ) ;
V_230 -> type = V_235 ;
V_230 -> V_218 = F_135 (
F_11 ( V_109 -> V_228 ) ) ;
}
}
}
void F_136 ( struct V_2 * V_3 ,
struct V_62 * V_151 ,
struct V_62 * V_152 ,
unsigned int V_57 )
{
struct V_72 * V_236 ;
struct V_72 * V_237 ;
V_236 = F_43 ( V_3 , V_152 , V_57 ) ;
V_237 = F_43 ( V_3 , V_151 , V_57 ) ;
V_237 -> V_112 = V_236 -> V_112 ;
V_237 -> V_189 = V_236 -> V_189 ;
V_237 -> V_115 = V_236 -> V_115 ;
V_237 -> V_228 = V_236 -> V_228 ;
}
void F_137 ( struct V_2 * V_3 ,
struct V_62 * V_151 ,
struct V_62 * V_152 )
{
struct V_71 * V_238 ;
struct V_71 * V_239 ;
V_238 = F_42 ( V_3 , V_151 ) ;
V_239 = F_42 ( V_3 , V_152 ) ;
V_238 -> V_171 = V_239 -> V_171 ;
V_238 -> V_183 = V_239 -> V_183 ;
V_238 -> V_122 = V_239 -> V_122 ;
V_238 -> V_240 = V_239 -> V_240 ;
}
static int F_138 ( struct V_2 * V_3 , T_1 V_6 )
{
int V_9 ;
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
int V_241 = F_139 ( V_3 -> V_242 ) ;
F_36 ( V_3 , V_243 ,
L_25 , V_241 ) ;
if ( ! V_241 )
return 0 ;
V_3 -> V_244 = F_2 ( sizeof( * V_3 -> V_244 ) , V_6 ) ;
if ( ! V_3 -> V_244 )
goto V_245;
V_3 -> V_244 -> V_246 = F_48 ( V_77 ,
V_241 * sizeof( T_5 ) ,
& V_3 -> V_244 -> V_247 , V_6 ) ;
if ( ! V_3 -> V_244 -> V_246 )
goto V_248;
V_3 -> V_244 -> V_249 = F_2 ( sizeof( void * ) * V_241 , V_6 ) ;
if ( ! V_3 -> V_244 -> V_249 )
goto V_250;
V_3 -> V_147 -> V_148 [ 0 ] = F_10 ( V_3 -> V_244 -> V_247 ) ;
for ( V_9 = 0 ; V_9 < V_241 ; V_9 ++ ) {
T_2 V_8 ;
void * V_251 = F_140 ( V_77 , V_3 -> V_252 , & V_8 ,
V_6 ) ;
if ( ! V_251 )
goto V_253;
V_3 -> V_244 -> V_246 [ V_9 ] = V_8 ;
V_3 -> V_244 -> V_249 [ V_9 ] = V_251 ;
}
return 0 ;
V_253:
for ( V_9 = V_9 - 1 ; V_9 >= 0 ; V_9 -- ) {
F_46 ( V_77 , V_3 -> V_252 ,
V_3 -> V_244 -> V_249 [ V_9 ] ,
V_3 -> V_244 -> V_246 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_244 -> V_249 ) ;
V_250:
F_46 ( V_77 , V_241 * sizeof( T_5 ) ,
V_3 -> V_244 -> V_246 ,
V_3 -> V_244 -> V_247 ) ;
V_248:
F_4 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
V_245:
return - V_51 ;
}
static void F_141 ( struct V_2 * V_3 )
{
int V_241 ;
int V_9 ;
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
if ( ! V_3 -> V_244 )
return;
V_241 = F_139 ( V_3 -> V_242 ) ;
for ( V_9 = 0 ; V_9 < V_241 ; V_9 ++ ) {
F_46 ( V_77 , V_3 -> V_252 ,
V_3 -> V_244 -> V_249 [ V_9 ] ,
V_3 -> V_244 -> V_246 [ V_9 ] ) ;
}
F_4 ( V_3 -> V_244 -> V_249 ) ;
F_46 ( V_77 , V_241 * sizeof( T_5 ) ,
V_3 -> V_244 -> V_246 ,
V_3 -> V_244 -> V_247 ) ;
F_4 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
}
struct V_254 * F_54 ( struct V_2 * V_3 ,
bool V_255 , bool V_256 ,
T_1 V_40 )
{
struct V_254 * V_257 ;
V_257 = F_2 ( sizeof( * V_257 ) , V_40 ) ;
if ( ! V_257 )
return NULL ;
if ( V_255 ) {
V_257 -> V_151 =
F_37 ( V_3 , V_65 ,
V_40 ) ;
if ( ! V_257 -> V_151 ) {
F_4 ( V_257 ) ;
return NULL ;
}
}
if ( V_256 ) {
V_257 -> V_258 =
F_2 ( sizeof( struct V_258 ) , V_40 ) ;
if ( ! V_257 -> V_258 ) {
F_40 ( V_3 , V_257 -> V_151 ) ;
F_4 ( V_257 ) ;
return NULL ;
}
F_142 ( V_257 -> V_258 ) ;
}
V_257 -> V_259 = 0 ;
F_31 ( & V_257 -> V_260 ) ;
return V_257 ;
}
void F_143 ( struct V_261 * V_261 )
{
F_4 ( V_261 ) ;
}
void F_57 ( struct V_2 * V_3 ,
struct V_254 * V_257 )
{
F_40 ( V_3 ,
V_257 -> V_151 ) ;
F_4 ( V_257 -> V_258 ) ;
F_4 ( V_257 ) ;
}
void F_144 ( struct V_2 * V_3 )
{
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
int V_66 ;
int V_9 , V_134 , V_133 ;
F_145 ( & V_3 -> V_262 ) ;
V_66 = sizeof( struct V_263 ) * ( V_3 -> V_264 . V_265 ) ;
if ( V_3 -> V_264 . V_266 )
F_46 ( V_77 , V_66 ,
V_3 -> V_264 . V_266 , V_3 -> V_264 . V_267 ) ;
V_3 -> V_264 . V_266 = NULL ;
F_36 ( V_3 , V_243 , L_26 ) ;
if ( V_3 -> V_268 )
F_26 ( V_3 , V_3 -> V_268 ) ;
V_3 -> V_268 = NULL ;
F_36 ( V_3 , V_243 , L_27 ) ;
if ( V_3 -> V_269 )
F_57 ( V_3 , V_3 -> V_269 ) ;
V_3 -> V_269 = NULL ;
if ( V_3 -> V_270 )
F_26 ( V_3 , V_3 -> V_270 ) ;
V_3 -> V_270 = NULL ;
F_36 ( V_3 , V_243 , L_28 ) ;
F_146 ( V_3 ) ;
V_133 = F_67 ( V_3 -> V_125 ) ;
for ( V_9 = 0 ; V_9 < V_133 && V_3 -> V_126 ; V_9 ++ ) {
struct V_137 * V_271 = & V_3 -> V_126 [ V_9 ] . V_138 ;
for ( V_134 = 0 ; V_134 < V_142 ; V_134 ++ ) {
struct V_119 * V_85 = & V_271 -> V_143 [ V_134 ] . V_144 ;
while ( ! F_74 ( V_85 ) )
F_147 ( V_85 -> V_17 ) ;
}
}
for ( V_9 = F_78 ( V_3 -> V_125 ) ; V_9 > 0 ; V_9 -- )
F_77 ( V_3 , V_9 ) ;
F_148 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
F_36 ( V_3 , V_243 , L_29 ) ;
F_148 ( V_3 -> V_69 ) ;
V_3 -> V_69 = NULL ;
F_36 ( V_3 , V_243 , L_30 ) ;
F_148 ( V_3 -> V_82 ) ;
V_3 -> V_82 = NULL ;
F_36 ( V_3 , V_243 ,
L_31 ) ;
F_148 ( V_3 -> V_83 ) ;
V_3 -> V_83 = NULL ;
F_36 ( V_3 , V_243 ,
L_32 ) ;
if ( V_3 -> V_147 )
F_46 ( V_77 , sizeof( * V_3 -> V_147 ) ,
V_3 -> V_147 , V_3 -> V_147 -> V_8 ) ;
V_3 -> V_147 = NULL ;
F_141 ( V_3 ) ;
if ( ! V_3 -> V_126 )
goto V_272;
for ( V_9 = 0 ; V_9 < V_133 ; V_9 ++ ) {
struct V_121 * V_132 , * V_273 ;
F_68 (tt, n, &xhci->rh_bw[i].tts, tt_list) {
F_69 ( & V_132 -> V_128 ) ;
F_4 ( V_132 ) ;
}
}
V_272:
V_3 -> V_97 = 0 ;
V_3 -> V_274 = 0 ;
V_3 -> V_275 = 0 ;
V_3 -> V_276 = 0 ;
F_4 ( V_3 -> V_277 ) ;
F_4 ( V_3 -> V_278 ) ;
F_4 ( V_3 -> V_279 ) ;
F_4 ( V_3 -> V_126 ) ;
F_4 ( V_3 -> V_280 ) ;
V_3 -> V_277 = NULL ;
V_3 -> V_278 = NULL ;
V_3 -> V_279 = NULL ;
V_3 -> V_126 = NULL ;
V_3 -> V_280 = NULL ;
V_3 -> V_252 = 0 ;
V_3 -> V_281 = 0 ;
V_3 -> V_282 [ 0 ] . V_283 = 0 ;
V_3 -> V_282 [ 1 ] . V_283 = 0 ;
}
static int F_149 ( struct V_2 * V_3 ,
struct V_1 * V_284 ,
union V_285 * V_286 ,
union V_285 * V_287 ,
T_2 V_288 ,
struct V_1 * V_289 ,
char * V_290 , int V_291 )
{
unsigned long long V_292 ;
unsigned long long V_293 ;
struct V_1 * V_7 ;
V_292 = F_62 ( V_284 , V_286 ) ;
V_293 = F_62 ( V_284 , V_287 ) ;
V_7 = F_150 ( V_3 , V_284 , V_286 , V_287 , V_288 , false ) ;
if ( V_7 != V_289 ) {
F_75 ( V_3 , L_33 ,
V_290 , V_291 ) ;
F_75 ( V_3 , L_34
L_35 ,
V_284 ,
( unsigned long long ) V_288 ) ;
F_75 ( V_3 , L_36
L_37 ,
V_286 , V_292 ,
V_287 , V_293 ) ;
F_75 ( V_3 , L_38 ,
V_289 , V_7 ) ;
F_150 ( V_3 , V_284 , V_286 , V_287 , V_288 ,
true ) ;
return - 1 ;
}
return 0 ;
}
static int F_151 ( struct V_2 * V_3 )
{
struct {
T_2 V_288 ;
struct V_1 * V_289 ;
} V_294 [] = {
{ 0 , NULL } ,
{ V_3 -> V_268 -> V_44 -> V_8 - 16 , NULL } ,
{ V_3 -> V_268 -> V_44 -> V_8 - 1 , NULL } ,
{ V_3 -> V_268 -> V_44 -> V_8 , V_3 -> V_268 -> V_44 } ,
{ V_3 -> V_268 -> V_44 -> V_8 + ( V_13 - 1 ) * 16 ,
V_3 -> V_268 -> V_44 } ,
{ V_3 -> V_268 -> V_44 -> V_8 + ( V_13 - 1 ) * 16 + 1 , NULL } ,
{ V_3 -> V_268 -> V_44 -> V_8 + ( V_13 ) * 16 , NULL } ,
{ ( T_2 ) ( ~ 0 ) , NULL } ,
} ;
struct {
struct V_1 * V_284 ;
union V_285 * V_286 ;
union V_285 * V_287 ;
T_2 V_288 ;
struct V_1 * V_289 ;
} V_295 [] = {
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = V_3 -> V_268 -> V_44 -> V_10 ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_288 = V_3 -> V_270 -> V_44 -> V_8 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = V_3 -> V_268 -> V_44 -> V_10 ,
. V_287 = & V_3 -> V_270 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_288 = V_3 -> V_270 -> V_44 -> V_8 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = V_3 -> V_270 -> V_44 -> V_10 ,
. V_287 = & V_3 -> V_270 -> V_44 -> V_10 [ V_13 - 1 ] ,
. V_288 = V_3 -> V_270 -> V_44 -> V_8 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = & V_3 -> V_268 -> V_44 -> V_10 [ 0 ] ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ 3 ] ,
. V_288 = V_3 -> V_268 -> V_44 -> V_8 + 4 * 16 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = & V_3 -> V_268 -> V_44 -> V_10 [ 3 ] ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ 6 ] ,
. V_288 = V_3 -> V_268 -> V_44 -> V_8 + 2 * 16 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = & V_3 -> V_268 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ 1 ] ,
. V_288 = V_3 -> V_268 -> V_44 -> V_8 + 2 * 16 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = & V_3 -> V_268 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ 1 ] ,
. V_288 = V_3 -> V_268 -> V_44 -> V_8 + ( V_13 - 4 ) * 16 ,
. V_289 = NULL ,
} ,
{ . V_284 = V_3 -> V_268 -> V_44 ,
. V_286 = & V_3 -> V_268 -> V_44 -> V_10 [ V_13 - 3 ] ,
. V_287 = & V_3 -> V_268 -> V_44 -> V_10 [ 1 ] ,
. V_288 = V_3 -> V_270 -> V_44 -> V_8 + 2 * 16 ,
. V_289 = NULL ,
} ,
} ;
unsigned int V_296 ;
int V_9 , V_42 ;
V_296 = F_152 ( V_294 ) ;
for ( V_9 = 0 ; V_9 < V_296 ; V_9 ++ ) {
V_42 = F_149 ( V_3 ,
V_3 -> V_268 -> V_44 ,
V_3 -> V_268 -> V_44 -> V_10 ,
& V_3 -> V_268 -> V_44 -> V_10 [ V_13 - 1 ] ,
V_294 [ V_9 ] . V_288 ,
V_294 [ V_9 ] . V_289 ,
L_39 , V_9 ) ;
if ( V_42 < 0 )
return V_42 ;
}
V_296 = F_152 ( V_295 ) ;
for ( V_9 = 0 ; V_9 < V_296 ; V_9 ++ ) {
V_42 = F_149 ( V_3 ,
V_295 [ V_9 ] . V_284 ,
V_295 [ V_9 ] . V_286 ,
V_295 [ V_9 ] . V_287 ,
V_295 [ V_9 ] . V_288 ,
V_295 [ V_9 ] . V_289 ,
L_40 , V_9 ) ;
if ( V_42 < 0 )
return V_42 ;
}
F_53 ( V_3 , L_41 ) ;
return 0 ;
}
static void F_153 ( struct V_2 * V_3 )
{
T_5 V_297 ;
T_2 V_115 ;
V_115 = F_62 ( V_3 -> V_268 -> V_50 ,
V_3 -> V_268 -> V_49 ) ;
if ( V_115 == 0 && ! F_154 () )
F_75 ( V_3 , L_42
L_43 ) ;
V_297 = F_155 ( V_3 , & V_3 -> V_298 -> V_299 ) ;
V_297 &= V_300 ;
V_297 &= ~ V_301 ;
F_36 ( V_3 , V_243 ,
L_44
L_45 ) ;
F_156 ( V_3 , ( ( T_5 ) V_115 & ( T_5 ) ~ V_300 ) | V_297 ,
& V_3 -> V_298 -> V_299 ) ;
}
static void F_157 ( struct V_2 * V_3 , unsigned int V_133 ,
T_6 T_7 * V_96 , int V_302 )
{
T_3 V_297 , V_303 , V_304 ;
int V_9 ;
T_8 V_305 , V_306 ;
struct V_307 * V_308 ;
V_297 = F_158 ( V_96 ) ;
V_305 = F_159 ( V_297 ) ;
V_306 = F_160 ( V_297 ) ;
if ( V_305 == 0x03 ) {
V_308 = & V_3 -> V_309 ;
} else if ( V_305 <= 0x02 ) {
V_308 = & V_3 -> V_310 ;
} else {
F_75 ( V_3 , L_46
L_47 ,
V_96 , V_305 ) ;
return;
}
V_308 -> V_311 = F_159 ( V_297 ) ;
if ( V_308 -> V_312 < V_306 )
V_308 -> V_312 = V_306 ;
V_297 = F_158 ( V_96 + 2 ) ;
V_303 = F_161 ( V_297 ) ;
V_304 = F_162 ( V_297 ) ;
F_36 ( V_3 , V_243 ,
L_48
L_49 ,
V_96 , V_303 , V_304 , V_305 ) ;
if ( V_303 == 0 || ( V_303 + V_304 - 1 ) > V_133 )
return;
V_308 -> V_313 = F_163 ( V_297 ) ;
if ( V_308 -> V_313 ) {
V_308 -> V_314 = F_164 ( V_308 -> V_313 , sizeof( * V_308 -> V_314 ) ,
V_315 ) ;
if ( ! V_308 -> V_314 )
V_308 -> V_313 = 0 ;
V_308 -> V_316 ++ ;
for ( V_9 = 0 ; V_9 < V_308 -> V_313 ; V_9 ++ ) {
V_308 -> V_314 [ V_9 ] = F_158 ( V_96 + 4 + V_9 ) ;
if ( V_9 && ( F_165 ( V_308 -> V_314 [ V_9 ] ) !=
F_165 ( V_308 -> V_314 [ V_9 - 1 ] ) ) )
V_308 -> V_316 ++ ;
F_53 ( V_3 , L_50 ,
F_165 ( V_308 -> V_314 [ V_9 ] ) ,
F_166 ( V_308 -> V_314 [ V_9 ] ) ,
F_167 ( V_308 -> V_314 [ V_9 ] ) ,
F_168 ( V_308 -> V_314 [ V_9 ] ) ,
F_169 ( V_308 -> V_314 [ V_9 ] ) ,
F_170 ( V_308 -> V_314 [ V_9 ] ) ) ;
}
}
if ( V_305 < 0x03 && V_3 -> V_317 < V_302 )
V_3 -> V_280 [ V_3 -> V_317 ++ ] = V_297 ;
if ( ( V_3 -> V_224 == 0x96 ) && ( V_305 != 0x03 ) &&
( V_297 & V_318 ) ) {
F_36 ( V_3 , V_243 ,
L_51 ) ;
V_3 -> V_319 = 1 ;
}
if ( ( V_3 -> V_224 >= 0x100 ) && ( V_305 != 0x03 ) ) {
F_36 ( V_3 , V_243 ,
L_52 ) ;
V_3 -> V_319 = 1 ;
if ( V_297 & V_320 ) {
F_36 ( V_3 , V_243 ,
L_53 ) ;
V_3 -> V_321 = 1 ;
}
}
V_303 -- ;
for ( V_9 = V_303 ; V_9 < ( V_303 + V_304 ) ; V_9 ++ ) {
if ( V_3 -> V_279 [ V_9 ] != 0 ) {
F_75 ( V_3 , L_54
L_55 , V_96 , V_9 ) ;
F_75 ( V_3 , L_56
L_57 ,
V_3 -> V_279 [ V_9 ] , V_305 ) ;
if ( V_3 -> V_279 [ V_9 ] != V_305 &&
V_3 -> V_279 [ V_9 ] != V_322 ) {
if ( V_3 -> V_279 [ V_9 ] == 0x03 )
V_3 -> V_275 -- ;
else
V_3 -> V_274 -- ;
V_3 -> V_279 [ V_9 ] = V_322 ;
}
continue;
}
V_3 -> V_279 [ V_9 ] = V_305 ;
if ( V_305 == 0x03 )
V_3 -> V_275 ++ ;
else
V_3 -> V_274 ++ ;
}
}
static int F_171 ( struct V_2 * V_3 , T_1 V_6 )
{
void T_7 * V_323 ;
T_3 V_324 ;
unsigned int V_133 ;
int V_9 , V_134 , V_325 ;
int V_326 = 0 ;
T_3 V_327 ;
V_133 = F_67 ( V_3 -> V_125 ) ;
V_3 -> V_279 = F_2 ( sizeof( * V_3 -> V_279 ) * V_133 , V_6 ) ;
if ( ! V_3 -> V_279 )
return - V_51 ;
V_3 -> V_126 = F_2 ( sizeof( * V_3 -> V_126 ) * V_133 , V_6 ) ;
if ( ! V_3 -> V_126 )
return - V_51 ;
for ( V_9 = 0 ; V_9 < V_133 ; V_9 ++ ) {
struct V_137 * V_138 ;
F_31 ( & V_3 -> V_126 [ V_9 ] . V_127 ) ;
V_138 = & V_3 -> V_126 [ V_9 ] . V_138 ;
for ( V_134 = 0 ; V_134 < V_142 ; V_134 ++ )
F_31 ( & V_138 -> V_143 [ V_134 ] . V_144 ) ;
}
V_323 = & V_3 -> V_328 -> V_329 ;
V_327 = F_172 ( V_323 , 0 , V_330 ) ;
if ( ! V_327 ) {
F_173 ( V_3 , L_58 ) ;
return - V_331 ;
}
V_324 = V_327 ;
while ( V_324 ) {
V_326 ++ ;
V_324 = F_172 ( V_323 , V_324 ,
V_330 ) ;
}
V_3 -> V_280 = F_2 ( sizeof( * V_3 -> V_280 ) * V_326 , V_6 ) ;
if ( ! V_3 -> V_280 )
return - V_51 ;
V_324 = V_327 ;
while ( V_324 ) {
F_157 ( V_3 , V_133 , V_323 + V_324 , V_326 ) ;
if ( V_3 -> V_274 + V_3 -> V_275 == V_133 )
break;
V_324 = F_172 ( V_323 , V_324 ,
V_330 ) ;
}
if ( V_3 -> V_274 == 0 && V_3 -> V_275 == 0 ) {
F_75 ( V_3 , L_59 ) ;
return - V_331 ;
}
F_36 ( V_3 , V_243 ,
L_60 ,
V_3 -> V_274 , V_3 -> V_275 ) ;
if ( V_3 -> V_275 > V_332 ) {
F_36 ( V_3 , V_243 ,
L_61 ,
V_332 ) ;
V_3 -> V_275 = V_332 ;
}
if ( V_3 -> V_274 > V_333 ) {
F_36 ( V_3 , V_243 ,
L_62 ,
V_333 ) ;
V_3 -> V_274 = V_333 ;
}
if ( V_3 -> V_274 ) {
V_3 -> V_277 = F_174 ( sizeof( * V_3 -> V_277 ) *
V_3 -> V_274 , V_6 ) ;
if ( ! V_3 -> V_277 )
return - V_51 ;
V_325 = 0 ;
for ( V_9 = 0 ; V_9 < V_133 ; V_9 ++ ) {
if ( V_3 -> V_279 [ V_9 ] == 0x03 ||
V_3 -> V_279 [ V_9 ] == 0 ||
V_3 -> V_279 [ V_9 ] == V_322 )
continue;
V_3 -> V_277 [ V_325 ] =
& V_3 -> V_334 -> V_335 +
V_336 * V_9 ;
F_36 ( V_3 , V_243 ,
L_63
L_64 , V_9 ,
V_3 -> V_277 [ V_325 ] ) ;
V_325 ++ ;
if ( V_325 == V_3 -> V_274 )
break;
}
}
if ( V_3 -> V_275 ) {
V_3 -> V_278 = F_174 ( sizeof( * V_3 -> V_278 ) *
V_3 -> V_275 , V_6 ) ;
if ( ! V_3 -> V_278 )
return - V_51 ;
V_325 = 0 ;
for ( V_9 = 0 ; V_9 < V_133 ; V_9 ++ )
if ( V_3 -> V_279 [ V_9 ] == 0x03 ) {
V_3 -> V_278 [ V_325 ] =
& V_3 -> V_334 -> V_335 +
V_336 * V_9 ;
F_36 ( V_3 , V_243 ,
L_65
L_64 , V_9 ,
V_3 -> V_278 [ V_325 ] ) ;
V_325 ++ ;
if ( V_325 == V_3 -> V_275 )
break;
}
}
return 0 ;
}
int F_175 ( struct V_2 * V_3 , T_1 V_6 )
{
T_2 V_8 ;
struct V_76 * V_77 = F_45 ( V_3 ) -> V_78 . V_79 ;
unsigned int V_21 , V_337 ;
T_5 V_338 ;
struct V_1 * V_7 ;
T_3 V_252 , V_297 ;
int V_9 ;
F_31 ( & V_3 -> V_260 ) ;
F_176 ( & V_3 -> V_262 , V_339 ) ;
F_142 ( & V_3 -> V_340 ) ;
V_252 = F_158 ( & V_3 -> V_334 -> V_252 ) ;
F_36 ( V_3 , V_243 ,
L_66 , V_252 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
if ( ( 0x1 & V_252 ) != 0 )
break;
V_252 = V_252 >> 1 ;
}
if ( V_9 < 16 )
F_36 ( V_3 , V_243 ,
L_67 , ( 1 << ( V_9 + 12 ) ) / 1024 ) ;
else
F_75 ( V_3 , L_68 ) ;
V_3 -> V_281 = 12 ;
V_3 -> V_252 = 1 << V_3 -> V_281 ;
F_36 ( V_3 , V_243 ,
L_69 , V_3 -> V_252 / 1024 ) ;
V_21 = F_78 ( F_158 ( & V_3 -> V_328 -> V_125 ) ) ;
F_36 ( V_3 , V_243 ,
L_70 , V_21 ) ;
V_337 = F_158 ( & V_3 -> V_334 -> V_341 ) ;
V_21 |= ( V_337 & ~ V_342 ) ;
F_36 ( V_3 , V_243 ,
L_71 , V_21 ) ;
F_177 ( V_21 , & V_3 -> V_334 -> V_341 ) ;
V_3 -> V_147 = F_48 ( V_77 , sizeof( * V_3 -> V_147 ) , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_147 )
goto V_54;
memset ( V_3 -> V_147 , 0 , sizeof *( V_3 -> V_147 ) ) ;
V_3 -> V_147 -> V_8 = V_8 ;
F_36 ( V_3 , V_243 ,
L_72 ,
( unsigned long long ) V_3 -> V_147 -> V_8 , V_3 -> V_147 ) ;
F_156 ( V_3 , V_8 , & V_3 -> V_334 -> V_343 ) ;
V_3 -> V_11 = F_178 ( L_73 , V_77 ,
V_344 , V_344 , V_3 -> V_252 ) ;
V_3 -> V_69 = F_178 ( L_74 , V_77 ,
2112 , 64 , V_3 -> V_252 ) ;
if ( ! V_3 -> V_11 || ! V_3 -> V_69 )
goto V_54;
V_3 -> V_82 =
F_178 ( L_75 ,
V_77 , V_81 , 16 , 0 ) ;
V_3 -> V_83 =
F_178 ( L_76 ,
V_77 , V_80 , 16 , 0 ) ;
if ( ! V_3 -> V_82 || ! V_3 -> V_83 )
goto V_54;
V_3 -> V_270 = F_30 ( V_3 , 1 , 1 , V_345 , 0 , V_6 ) ;
if ( ! V_3 -> V_270 )
goto V_54;
F_36 ( V_3 , V_243 ,
L_77 , V_3 -> V_270 ) ;
F_36 ( V_3 , V_243 , L_78 ,
( unsigned long long ) V_3 -> V_270 -> V_44 -> V_8 ) ;
V_338 = F_155 ( V_3 , & V_3 -> V_334 -> V_270 ) ;
V_338 = ( V_338 & ( T_5 ) V_346 ) |
( V_3 -> V_270 -> V_44 -> V_8 & ( T_5 ) ~ V_346 ) |
V_3 -> V_270 -> V_4 ;
F_36 ( V_3 , V_243 ,
L_79 , V_338 ) ;
F_156 ( V_3 , V_338 , & V_3 -> V_334 -> V_270 ) ;
F_179 ( V_3 ) ;
V_3 -> V_269 = F_54 ( V_3 , true , true , V_6 ) ;
if ( ! V_3 -> V_269 )
goto V_54;
V_3 -> V_97 ++ ;
V_21 = F_158 ( & V_3 -> V_328 -> V_347 ) ;
V_21 &= V_348 ;
F_36 ( V_3 , V_243 ,
L_80
L_81 , V_21 ) ;
V_3 -> V_349 = ( void T_7 * ) V_3 -> V_328 + V_21 ;
F_180 ( V_3 ) ;
F_181 ( V_3 ) ;
V_3 -> V_298 = & V_3 -> V_350 -> V_298 [ 0 ] ;
F_36 ( V_3 , V_243 , L_82 ) ;
V_3 -> V_268 = F_30 ( V_3 , V_351 , 1 , V_22 ,
0 , V_6 ) ;
if ( ! V_3 -> V_268 )
goto V_54;
if ( F_151 ( V_3 ) < 0 )
goto V_54;
V_3 -> V_264 . V_266 = F_48 ( V_77 ,
sizeof( struct V_263 ) * V_351 , & V_8 ,
V_6 ) ;
if ( ! V_3 -> V_264 . V_266 )
goto V_54;
F_36 ( V_3 , V_243 ,
L_83 ,
( unsigned long long ) V_8 ) ;
memset ( V_3 -> V_264 . V_266 , 0 , sizeof( struct V_263 ) * V_351 ) ;
V_3 -> V_264 . V_265 = V_351 ;
V_3 -> V_264 . V_267 = V_8 ;
F_36 ( V_3 , V_243 ,
L_84 ,
V_3 -> V_264 . V_265 ,
V_3 -> V_264 . V_266 ,
( unsigned long long ) V_3 -> V_264 . V_267 ) ;
for ( V_21 = 0 , V_7 = V_3 -> V_268 -> V_44 ; V_21 < V_351 ; V_21 ++ ) {
struct V_263 * V_352 = & V_3 -> V_264 . V_266 [ V_21 ] ;
V_352 -> V_353 = F_10 ( V_7 -> V_8 ) ;
V_352 -> V_354 = F_6 ( V_13 ) ;
V_352 -> V_355 = 0 ;
V_7 = V_7 -> V_17 ;
}
V_21 = F_158 ( & V_3 -> V_298 -> V_356 ) ;
V_21 &= V_357 ;
V_21 |= V_351 ;
F_36 ( V_3 , V_243 ,
L_85 ,
V_21 ) ;
F_177 ( V_21 , & V_3 -> V_298 -> V_356 ) ;
F_36 ( V_3 , V_243 ,
L_86 ) ;
F_36 ( V_3 , V_243 ,
L_87 ,
( unsigned long long ) V_3 -> V_264 . V_267 ) ;
V_338 = F_155 ( V_3 , & V_3 -> V_298 -> V_358 ) ;
V_338 &= V_300 ;
V_338 |= ( V_3 -> V_264 . V_267 & ( T_5 ) ~ V_300 ) ;
F_156 ( V_3 , V_338 , & V_3 -> V_298 -> V_358 ) ;
F_153 ( V_3 ) ;
F_36 ( V_3 , V_243 ,
L_88 ) ;
F_182 ( V_3 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_359 ; V_9 ++ )
V_3 -> V_146 [ V_9 ] = NULL ;
for ( V_9 = 0 ; V_9 < V_333 ; V_9 ++ ) {
V_3 -> V_282 [ 0 ] . V_360 [ V_9 ] = 0 ;
V_3 -> V_282 [ 1 ] . V_360 [ V_9 ] = 0 ;
F_142 ( & V_3 -> V_282 [ 1 ] . V_361 [ V_9 ] ) ;
}
if ( F_138 ( V_3 , V_6 ) )
goto V_54;
if ( F_171 ( V_3 , V_6 ) )
goto V_54;
V_297 = F_158 ( & V_3 -> V_334 -> V_362 ) ;
V_297 &= ~ V_363 ;
V_297 |= V_364 ;
F_177 ( V_297 , & V_3 -> V_334 -> V_362 ) ;
return 0 ;
V_54:
F_183 ( V_3 ) ;
F_184 ( V_3 ) ;
F_144 ( V_3 ) ;
return - V_51 ;
}
