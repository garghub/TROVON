static int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 ) - 1 ) / 2 ;
}
static int F_3 ( int V_3 )
{
return V_3 * 2 + 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) / 2 ;
}
static int F_5 ( int V_4 )
{
return V_4 * 2 ;
}
static inline struct V_5 * V_5 ( struct V_6 * V_7 )
{
return (struct V_5 * ) V_7 -> V_8 ;
}
static void F_6 ( struct V_9 * V_10 , struct V_11 * V_11 )
{
struct V_11 * V_12 ;
for ( V_12 = V_11 ; V_12 -> V_13 ; V_12 = (struct V_11 * ) V_12 -> V_13 ) ;
V_12 -> V_13 = ( unsigned long ) V_10 -> V_14 ;
V_10 -> V_14 = V_11 ;
}
static struct V_11 * F_7 ( struct V_9 * V_10 , T_1 V_15 )
{
struct V_11 * V_16 = V_10 -> V_14 ;
if ( V_16 ) {
V_10 -> V_14 = (struct V_11 * ) V_16 -> V_13 ;
V_16 -> V_13 = 0 ;
} else
V_16 = F_8 ( V_15 ) ;
return V_16 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 -> V_20 ;
F_10 ( V_2 ) ;
F_11 ( V_18 -> V_21 , F_1 ( V_2 ) ) ;
}
static void F_12 ( struct V_6 * V_7 , struct V_11 * V_11 ,
unsigned int V_22 , unsigned int * V_23 )
{
int V_24 = F_13 ( ( unsigned ) V_25 - V_22 , * V_23 ) ;
int V_26 = F_14 ( V_7 ) -> V_27 ;
F_15 ( V_7 , V_26 , V_11 , V_22 , V_24 ) ;
V_7 -> V_28 += V_24 ;
V_7 -> V_23 += V_24 ;
V_7 -> V_29 += V_25 ;
F_14 ( V_7 ) -> V_27 ++ ;
* V_23 -= V_24 ;
}
static struct V_6 * F_16 ( struct V_9 * V_10 ,
struct V_11 * V_11 , unsigned int V_23 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_6 * V_7 ;
struct V_5 * V_30 ;
unsigned int V_31 , V_32 , V_22 ;
char * V_16 ;
V_16 = F_17 ( V_11 ) ;
V_7 = F_18 ( V_18 -> V_21 , V_33 ) ;
if ( F_19 ( ! V_7 ) )
return NULL ;
V_30 = V_5 ( V_7 ) ;
if ( V_18 -> V_34 ) {
V_32 = sizeof V_30 -> V_35 ;
V_22 = V_32 ;
} else {
V_32 = sizeof V_30 -> V_30 ;
V_22 = sizeof( struct V_36 ) ;
}
memcpy ( V_30 , V_16 , V_32 ) ;
V_23 -= V_32 ;
V_16 += V_22 ;
V_31 = V_23 ;
if ( V_31 > F_20 ( V_7 ) )
V_31 = F_20 ( V_7 ) ;
memcpy ( F_21 ( V_7 , V_31 ) , V_16 , V_31 ) ;
V_23 -= V_31 ;
V_22 += V_31 ;
if ( F_19 ( V_23 > V_37 * V_25 ) ) {
F_22 ( L_1 , V_7 -> V_21 -> V_38 ) ;
F_23 ( V_7 ) ;
return NULL ;
}
while ( V_23 ) {
F_12 ( V_7 , V_11 , V_22 , & V_23 ) ;
V_11 = (struct V_11 * ) V_11 -> V_13 ;
V_22 = 0 ;
}
if ( V_11 )
F_6 ( V_10 , V_11 ) ;
return V_7 ;
}
static int F_24 ( struct V_9 * V_10 , struct V_6 * V_7 )
{
struct V_5 * V_30 = V_5 ( V_7 ) ;
struct V_11 * V_11 ;
int V_39 , V_26 , V_23 ;
V_39 = V_30 -> V_35 . V_40 ;
while ( -- V_39 ) {
V_26 = F_14 ( V_7 ) -> V_27 ;
if ( V_26 >= V_37 ) {
F_25 ( L_2 , V_7 -> V_21 -> V_38 ) ;
V_7 -> V_21 -> V_41 . V_42 ++ ;
return - V_43 ;
}
V_11 = F_26 ( V_10 -> V_2 , & V_23 ) ;
if ( ! V_11 ) {
F_25 ( L_3 ,
V_7 -> V_21 -> V_38 , V_30 -> V_35 . V_40 ) ;
V_7 -> V_21 -> V_41 . V_42 ++ ;
return - V_43 ;
}
if ( V_23 > V_25 )
V_23 = V_25 ;
F_12 ( V_7 , V_11 , 0 , & V_23 ) ;
-- V_10 -> V_44 ;
}
return 0 ;
}
static void F_27 ( struct V_9 * V_10 , void * V_45 , unsigned int V_23 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_46 * V_21 = V_18 -> V_21 ;
struct V_47 * V_41 = F_28 ( V_18 -> V_41 ) ;
struct V_6 * V_7 ;
struct V_11 * V_11 ;
struct V_5 * V_30 ;
if ( F_19 ( V_23 < sizeof( struct V_48 ) + V_49 ) ) {
F_25 ( L_4 , V_21 -> V_38 , V_23 ) ;
V_21 -> V_41 . V_42 ++ ;
if ( V_18 -> V_34 || V_18 -> V_50 )
F_6 ( V_10 , V_45 ) ;
else
F_23 ( V_45 ) ;
return;
}
if ( ! V_18 -> V_34 && ! V_18 -> V_50 ) {
V_7 = V_45 ;
V_23 -= sizeof( struct V_48 ) ;
F_29 ( V_7 , V_23 ) ;
} else {
V_11 = V_45 ;
V_7 = F_16 ( V_10 , V_11 , V_23 ) ;
if ( F_19 ( ! V_7 ) ) {
V_21 -> V_41 . V_51 ++ ;
F_6 ( V_10 , V_11 ) ;
return;
}
if ( V_18 -> V_34 )
if ( F_24 ( V_10 , V_7 ) ) {
F_23 ( V_7 ) ;
return;
}
}
V_30 = V_5 ( V_7 ) ;
F_30 ( & V_41 -> V_52 ) ;
V_41 -> V_53 += V_7 -> V_23 ;
V_41 -> V_54 ++ ;
F_31 ( & V_41 -> V_52 ) ;
if ( V_30 -> V_30 . V_55 & V_56 ) {
F_25 ( L_5 ) ;
if ( ! F_32 ( V_7 ,
V_30 -> V_30 . V_57 ,
V_30 -> V_30 . V_58 ) )
goto V_59;
} else if ( V_30 -> V_30 . V_55 & V_60 ) {
V_7 -> V_61 = V_62 ;
}
V_7 -> V_63 = F_33 ( V_7 , V_21 ) ;
F_25 ( L_6 ,
F_34 ( V_7 -> V_63 ) , V_7 -> V_23 , V_7 -> V_64 ) ;
if ( V_30 -> V_30 . V_65 != V_66 ) {
F_25 ( L_7 ) ;
switch ( V_30 -> V_30 . V_65 & ~ V_67 ) {
case V_68 :
F_14 ( V_7 ) -> V_65 = V_69 ;
break;
case V_70 :
F_14 ( V_7 ) -> V_65 = V_71 ;
break;
case V_72 :
F_14 ( V_7 ) -> V_65 = V_73 ;
break;
default:
F_35 ( L_8 ,
V_21 -> V_38 , V_30 -> V_30 . V_65 ) ;
goto V_59;
}
if ( V_30 -> V_30 . V_65 & V_67 )
F_14 ( V_7 ) -> V_65 |= V_74 ;
F_14 ( V_7 ) -> V_75 = V_30 -> V_30 . V_75 ;
if ( F_14 ( V_7 ) -> V_75 == 0 ) {
F_35 ( L_9 , V_21 -> V_38 ) ;
goto V_59;
}
F_14 ( V_7 ) -> V_65 |= V_76 ;
F_14 ( V_7 ) -> V_77 = 0 ;
}
F_36 ( V_7 ) ;
return;
V_59:
V_21 -> V_41 . V_78 ++ ;
F_23 ( V_7 ) ;
}
static int F_37 ( struct V_9 * V_10 , T_1 V_79 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_6 * V_7 ;
struct V_5 * V_30 ;
int V_80 ;
V_7 = F_38 ( V_18 -> V_21 , V_81 , V_79 ) ;
if ( F_19 ( ! V_7 ) )
return - V_82 ;
F_21 ( V_7 , V_81 ) ;
V_30 = V_5 ( V_7 ) ;
F_39 ( V_10 -> V_83 , & V_30 -> V_30 , sizeof V_30 -> V_30 ) ;
F_40 ( V_7 , V_10 -> V_83 + 1 , 0 , V_7 -> V_23 ) ;
V_80 = F_41 ( V_10 -> V_2 , V_10 -> V_83 , 0 , 2 , V_7 , V_79 ) ;
if ( V_80 < 0 )
F_23 ( V_7 ) ;
return V_80 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_79 )
{
struct V_11 * V_84 , * V_85 = NULL ;
char * V_16 ;
int V_26 , V_80 , V_22 ;
for ( V_26 = V_37 + 1 ; V_26 > 1 ; -- V_26 ) {
V_84 = F_7 ( V_10 , V_79 ) ;
if ( ! V_84 ) {
if ( V_85 )
F_6 ( V_10 , V_85 ) ;
return - V_82 ;
}
F_39 ( & V_10 -> V_83 [ V_26 ] , F_17 ( V_84 ) , V_25 ) ;
V_84 -> V_13 = ( unsigned long ) V_85 ;
V_85 = V_84 ;
}
V_84 = F_7 ( V_10 , V_79 ) ;
if ( ! V_84 ) {
F_6 ( V_10 , V_85 ) ;
return - V_82 ;
}
V_16 = F_17 ( V_84 ) ;
F_39 ( & V_10 -> V_83 [ 0 ] , V_16 , sizeof( struct V_48 ) ) ;
V_22 = sizeof( struct V_36 ) ;
F_39 ( & V_10 -> V_83 [ 1 ] , V_16 + V_22 , V_25 - V_22 ) ;
V_84 -> V_13 = ( unsigned long ) V_85 ;
V_80 = F_41 ( V_10 -> V_2 , V_10 -> V_83 , 0 , V_37 + 2 ,
V_84 , V_79 ) ;
if ( V_80 < 0 )
F_6 ( V_10 , V_84 ) ;
return V_80 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 V_79 )
{
struct V_11 * V_11 ;
int V_80 ;
V_11 = F_7 ( V_10 , V_79 ) ;
if ( ! V_11 )
return - V_82 ;
F_44 ( V_10 -> V_83 , F_17 ( V_11 ) , V_25 ) ;
V_80 = F_41 ( V_10 -> V_2 , V_10 -> V_83 , 0 , 1 , V_11 , V_79 ) ;
if ( V_80 < 0 )
F_6 ( V_10 , V_11 ) ;
return V_80 ;
}
static bool F_45 ( struct V_9 * V_10 , T_1 V_79 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
int V_80 ;
bool V_86 ;
do {
if ( V_18 -> V_34 )
V_80 = F_43 ( V_10 , V_79 ) ;
else if ( V_18 -> V_50 )
V_80 = F_42 ( V_10 , V_79 ) ;
else
V_80 = F_37 ( V_10 , V_79 ) ;
V_86 = V_80 == - V_82 ;
if ( V_80 )
break;
++ V_10 -> V_44 ;
} while ( V_10 -> V_2 -> V_87 );
if ( F_19 ( V_10 -> V_44 > V_10 -> V_88 ) )
V_10 -> V_88 = V_10 -> V_44 ;
F_46 ( V_10 -> V_2 ) ;
return ! V_86 ;
}
static void F_47 ( struct V_1 * V_89 )
{
struct V_17 * V_18 = V_89 -> V_19 -> V_20 ;
struct V_9 * V_10 = & V_18 -> V_10 [ F_4 ( V_89 ) ] ;
if ( F_48 ( & V_10 -> V_90 ) ) {
F_10 ( V_89 ) ;
F_49 ( & V_10 -> V_90 ) ;
}
}
static void F_50 ( struct V_9 * V_10 )
{
F_51 ( & V_10 -> V_90 ) ;
if ( F_48 ( & V_10 -> V_90 ) ) {
F_10 ( V_10 -> V_2 ) ;
F_52 () ;
F_49 ( & V_10 -> V_90 ) ;
F_53 () ;
}
}
static void F_54 ( struct V_91 * V_92 )
{
struct V_17 * V_18 =
F_55 ( V_92 , struct V_17 , V_93 . V_92 ) ;
bool V_94 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
struct V_9 * V_10 = & V_18 -> V_10 [ V_26 ] ;
F_56 ( & V_10 -> V_90 ) ;
V_94 = ! F_45 ( V_10 , V_96 ) ;
F_50 ( V_10 ) ;
if ( V_94 )
F_57 ( & V_18 -> V_93 , V_97 / 2 ) ;
}
}
static int F_58 ( struct V_98 * V_90 , int V_99 )
{
struct V_9 * V_10 =
F_55 ( V_90 , struct V_9 , V_90 ) ;
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
void * V_45 ;
unsigned int V_23 , V_100 = 0 ;
V_101:
while ( V_100 < V_99 &&
( V_45 = F_26 ( V_10 -> V_2 , & V_23 ) ) != NULL ) {
F_27 ( V_10 , V_45 , V_23 ) ;
-- V_10 -> V_44 ;
V_100 ++ ;
}
if ( V_10 -> V_44 < V_10 -> V_88 / 2 ) {
if ( ! F_45 ( V_10 , V_102 ) )
F_57 ( & V_18 -> V_93 , 0 ) ;
}
if ( V_100 < V_99 ) {
F_59 ( V_90 ) ;
if ( F_19 ( ! F_60 ( V_10 -> V_2 ) ) &&
F_48 ( V_90 ) ) {
F_10 ( V_10 -> V_2 ) ;
F_49 ( V_90 ) ;
goto V_101;
}
}
return V_100 ;
}
static int F_61 ( struct V_46 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
if ( ! F_45 ( & V_18 -> V_10 [ V_26 ] , V_96 ) )
F_57 ( & V_18 -> V_93 , 0 ) ;
F_50 ( & V_18 -> V_10 [ V_26 ] ) ;
}
return 0 ;
}
static void F_63 ( struct V_103 * V_104 )
{
struct V_6 * V_7 ;
unsigned int V_23 ;
struct V_17 * V_18 = V_104 -> V_2 -> V_19 -> V_20 ;
struct V_47 * V_41 = F_28 ( V_18 -> V_41 ) ;
while ( ( V_7 = F_26 ( V_104 -> V_2 , & V_23 ) ) != NULL ) {
F_25 ( L_10 , V_7 ) ;
F_30 ( & V_41 -> V_105 ) ;
V_41 -> V_106 += V_7 -> V_23 ;
V_41 -> V_107 ++ ;
F_31 ( & V_41 -> V_105 ) ;
F_64 ( V_7 ) ;
}
}
static int F_65 ( struct V_103 * V_104 , struct V_6 * V_7 )
{
struct V_5 * V_30 = V_5 ( V_7 ) ;
const unsigned char * V_108 = ( (struct V_109 * ) V_7 -> V_110 ) -> V_111 ;
struct V_17 * V_18 = V_104 -> V_2 -> V_19 -> V_20 ;
unsigned V_112 ;
F_25 ( L_11 , V_18 -> V_21 -> V_38 , V_7 , V_108 ) ;
if ( V_7 -> V_61 == V_113 ) {
V_30 -> V_30 . V_55 = V_56 ;
V_30 -> V_30 . V_57 = F_66 ( V_7 ) ;
V_30 -> V_30 . V_58 = V_7 -> V_58 ;
} else {
V_30 -> V_30 . V_55 = 0 ;
V_30 -> V_30 . V_58 = V_30 -> V_30 . V_57 = 0 ;
}
if ( F_67 ( V_7 ) ) {
V_30 -> V_30 . V_32 = F_68 ( V_7 ) ;
V_30 -> V_30 . V_75 = F_14 ( V_7 ) -> V_75 ;
if ( F_14 ( V_7 ) -> V_65 & V_69 )
V_30 -> V_30 . V_65 = V_68 ;
else if ( F_14 ( V_7 ) -> V_65 & V_73 )
V_30 -> V_30 . V_65 = V_72 ;
else if ( F_14 ( V_7 ) -> V_65 & V_71 )
V_30 -> V_30 . V_65 = V_70 ;
else
F_69 () ;
if ( F_14 ( V_7 ) -> V_65 & V_74 )
V_30 -> V_30 . V_65 |= V_67 ;
} else {
V_30 -> V_30 . V_65 = V_66 ;
V_30 -> V_30 . V_75 = V_30 -> V_30 . V_32 = 0 ;
}
V_30 -> V_35 . V_40 = 0 ;
if ( V_18 -> V_34 )
F_39 ( V_104 -> V_83 , & V_30 -> V_35 , sizeof V_30 -> V_35 ) ;
else
F_39 ( V_104 -> V_83 , & V_30 -> V_30 , sizeof V_30 -> V_30 ) ;
V_112 = F_40 ( V_7 , V_104 -> V_83 + 1 , 0 , V_7 -> V_23 ) + 1 ;
return F_41 ( V_104 -> V_2 , V_104 -> V_83 , V_112 ,
0 , V_7 , V_102 ) ;
}
static T_2 F_70 ( struct V_6 * V_7 , struct V_46 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_114 = F_71 ( V_7 ) ;
struct V_103 * V_104 = & V_18 -> V_104 [ V_114 ] ;
int V_80 ;
F_63 ( V_104 ) ;
V_80 = F_65 ( V_104 , V_7 ) ;
if ( F_19 ( V_80 ) ) {
V_21 -> V_41 . V_115 ++ ;
if ( F_72 () )
F_73 ( & V_21 -> V_21 ,
L_12 , V_114 , V_80 ) ;
V_21 -> V_41 . V_116 ++ ;
F_74 ( V_7 ) ;
return V_117 ;
}
F_46 ( V_104 -> V_2 ) ;
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
if ( V_104 -> V_2 -> V_87 < 2 + V_37 ) {
F_77 ( V_21 , V_114 ) ;
if ( F_19 ( ! F_78 ( V_104 -> V_2 ) ) ) {
F_63 ( V_104 ) ;
if ( V_104 -> V_2 -> V_87 >= 2 + V_37 ) {
F_79 ( V_21 , V_114 ) ;
F_10 ( V_104 -> V_2 ) ;
}
}
}
return V_117 ;
}
static int F_80 ( struct V_46 * V_21 , void * V_16 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_118 * V_19 = V_18 -> V_19 ;
int V_119 ;
V_119 = F_81 ( V_21 , V_16 ) ;
if ( V_119 )
return V_119 ;
if ( F_82 ( V_19 , V_120 ) )
V_19 -> V_121 -> V_122 ( V_19 , F_83 ( struct V_123 , V_124 ) ,
V_21 -> V_125 , V_21 -> V_126 ) ;
return 0 ;
}
static struct V_127 * V_47 ( struct V_46 * V_21 ,
struct V_127 * V_128 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_129 ;
unsigned int V_130 ;
F_84 (cpu) {
struct V_47 * V_41 = F_85 ( V_18 -> V_41 , V_129 ) ;
T_3 V_131 , V_132 , V_133 , V_134 ;
do {
V_130 = F_86 ( & V_41 -> V_105 ) ;
V_131 = V_41 -> V_107 ;
V_132 = V_41 -> V_106 ;
} while ( F_87 ( & V_41 -> V_105 , V_130 ) );
do {
V_130 = F_86 ( & V_41 -> V_52 ) ;
V_133 = V_41 -> V_54 ;
V_134 = V_41 -> V_53 ;
} while ( F_87 ( & V_41 -> V_52 , V_130 ) );
V_128 -> V_54 += V_133 ;
V_128 -> V_107 += V_131 ;
V_128 -> V_53 += V_134 ;
V_128 -> V_106 += V_132 ;
}
V_128 -> V_116 = V_21 -> V_41 . V_116 ;
V_128 -> V_115 = V_21 -> V_41 . V_115 ;
V_128 -> V_51 = V_21 -> V_41 . V_51 ;
V_128 -> V_42 = V_21 -> V_41 . V_42 ;
V_128 -> V_78 = V_21 -> V_41 . V_78 ;
return V_128 ;
}
static void F_88 ( struct V_46 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_135 ; V_26 ++ )
F_89 ( & V_18 -> V_10 [ V_26 ] . V_90 ) ;
}
static bool F_90 ( struct V_17 * V_18 , T_4 V_136 , T_4 V_137 ,
struct V_138 * V_110 , int V_139 , int V_140 )
{
struct V_138 * V_141 , V_83 [ V_142 + 2 ] ;
struct V_143 V_144 ;
T_5 V_145 = ~ 0 ;
unsigned int V_146 ;
int V_26 ;
F_91 ( ! F_82 ( V_18 -> V_19 , V_147 ) ||
( V_139 + V_140 > V_142 ) ) ;
V_139 ++ ;
V_140 ++ ;
V_144 . V_136 = V_136 ;
V_144 . V_137 = V_137 ;
F_92 ( V_83 , V_139 + V_140 ) ;
F_39 ( & V_83 [ 0 ] , & V_144 , sizeof( V_144 ) ) ;
F_93 (data, s, out + in - 2 , i)
F_39 ( & V_83 [ V_26 + 1 ] , F_94 ( V_141 ) , V_141 -> V_148 ) ;
F_39 ( & V_83 [ V_139 + V_140 - 1 ] , & V_145 , sizeof( V_145 ) ) ;
F_91 ( F_41 ( V_18 -> V_149 , V_83 , V_139 , V_140 , V_18 , V_102 ) < 0 ) ;
F_46 ( V_18 -> V_149 ) ;
while ( ! F_26 ( V_18 -> V_149 , & V_146 ) )
F_95 () ;
return V_145 == V_150 ;
}
static void F_96 ( struct V_17 * V_18 )
{
F_97 () ;
if ( ! F_90 ( V_18 , V_151 ,
V_152 , NULL ,
0 , 0 ) )
F_73 ( & V_18 -> V_21 -> V_21 , L_13 ) ;
F_98 () ;
}
static int F_99 ( struct V_17 * V_18 , T_6 V_153 )
{
struct V_138 V_83 ;
struct V_154 V_141 ;
struct V_46 * V_21 = V_18 -> V_21 ;
if ( ! V_18 -> V_155 || ! F_82 ( V_18 -> V_19 , V_156 ) )
return 0 ;
V_141 . V_157 = V_153 ;
F_44 ( & V_83 , & V_141 , sizeof( V_141 ) ) ;
if ( ! F_90 ( V_18 , V_158 ,
V_159 , & V_83 , 1 , 0 ) ) {
F_73 ( & V_21 -> V_21 , L_14 ,
V_153 ) ;
return - V_43 ;
} else
V_18 -> V_135 = V_153 ;
return 0 ;
}
static int F_100 ( struct V_46 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
F_101 ( & V_18 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ )
F_56 ( & V_18 -> V_10 [ V_26 ] . V_90 ) ;
return 0 ;
}
static void F_102 ( struct V_46 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_138 V_83 [ 2 ] ;
T_4 V_160 , V_161 ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
int V_166 ;
int V_167 ;
void * V_45 ;
int V_26 ;
if ( ! F_82 ( V_18 -> V_19 , V_168 ) )
return;
V_160 = ( ( V_21 -> V_55 & V_169 ) != 0 ) ;
V_161 = ( ( V_21 -> V_55 & V_170 ) != 0 ) ;
F_44 ( V_83 , & V_160 , sizeof( V_160 ) ) ;
if ( ! F_90 ( V_18 , V_171 ,
V_172 ,
V_83 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_15 ,
V_160 ? L_16 : L_17 ) ;
F_44 ( V_83 , & V_161 , sizeof( V_161 ) ) ;
if ( ! F_90 ( V_18 , V_171 ,
V_173 ,
V_83 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_18 ,
V_161 ? L_16 : L_17 ) ;
V_166 = F_103 ( V_21 ) ;
V_167 = F_104 ( V_21 ) ;
V_45 = F_105 ( ( ( V_166 + V_167 ) * V_174 ) +
( 2 * sizeof( V_163 -> V_175 ) ) , V_102 ) ;
V_163 = V_45 ;
if ( ! V_45 ) {
F_73 ( & V_21 -> V_21 , L_19 ) ;
return;
}
F_92 ( V_83 , 2 ) ;
V_163 -> V_175 = V_166 ;
V_26 = 0 ;
F_106 (ha, dev)
memcpy ( & V_163 -> V_176 [ V_26 ++ ] [ 0 ] , V_165 -> V_177 , V_174 ) ;
F_39 ( & V_83 [ 0 ] , V_163 ,
sizeof( V_163 -> V_175 ) + ( V_166 * V_174 ) ) ;
V_163 = ( void * ) & V_163 -> V_176 [ V_166 ] [ 0 ] ;
V_163 -> V_175 = V_167 ;
V_26 = 0 ;
F_107 (ha, dev)
memcpy ( & V_163 -> V_176 [ V_26 ++ ] [ 0 ] , V_165 -> V_177 , V_174 ) ;
F_39 ( & V_83 [ 1 ] , V_163 ,
sizeof( V_163 -> V_175 ) + ( V_167 * V_174 ) ) ;
if ( ! F_90 ( V_18 , V_178 ,
V_179 ,
V_83 , 2 , 0 ) )
F_73 ( & V_21 -> V_21 , L_20 ) ;
F_108 ( V_45 ) ;
}
static int F_109 ( struct V_46 * V_21 , T_6 V_180 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_138 V_83 ;
F_44 ( & V_83 , & V_180 , sizeof( V_180 ) ) ;
if ( ! F_90 ( V_18 , V_181 ,
V_182 , & V_83 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_21 , V_180 ) ;
return 0 ;
}
static int F_110 ( struct V_46 * V_21 , T_6 V_180 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_138 V_83 ;
F_44 ( & V_83 , & V_180 , sizeof( V_180 ) ) ;
if ( ! F_90 ( V_18 , V_181 ,
V_183 , & V_83 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_22 , V_180 ) ;
return 0 ;
}
static void F_111 ( struct V_17 * V_18 , long V_184 )
{
int V_26 ;
int V_129 ;
if ( V_18 -> V_185 ) {
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
F_112 ( V_18 -> V_10 [ V_26 ] . V_2 , - 1 ) ;
F_112 ( V_18 -> V_104 [ V_26 ] . V_2 , - 1 ) ;
}
V_18 -> V_185 = false ;
}
V_26 = 0 ;
F_113 (cpu) {
if ( V_129 == V_184 ) {
* F_85 ( V_18 -> V_186 , V_129 ) = - 1 ;
} else {
* F_85 ( V_18 -> V_186 , V_129 ) =
++ V_26 % V_18 -> V_135 ;
}
}
}
static void F_114 ( struct V_17 * V_18 )
{
int V_26 ;
int V_129 ;
if ( V_18 -> V_135 == 1 ||
V_18 -> V_95 != F_115 () ) {
F_111 ( V_18 , - 1 ) ;
return;
}
V_26 = 0 ;
F_113 (cpu) {
F_112 ( V_18 -> V_10 [ V_26 ] . V_2 , V_129 ) ;
F_112 ( V_18 -> V_104 [ V_26 ] . V_2 , V_129 ) ;
* F_85 ( V_18 -> V_186 , V_129 ) = V_26 ;
V_26 ++ ;
}
V_18 -> V_185 = true ;
}
static int F_116 ( struct V_187 * V_188 ,
unsigned long V_189 , void * V_184 )
{
struct V_17 * V_18 = F_55 ( V_188 , struct V_17 , V_190 ) ;
switch( V_189 & ~ V_191 ) {
case V_192 :
case V_193 :
case V_194 :
F_114 ( V_18 ) ;
break;
case V_195 :
F_111 ( V_18 , ( long ) V_184 ) ;
break;
default:
break;
}
return V_196 ;
}
static void F_117 ( struct V_46 * V_21 ,
struct V_197 * V_198 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
V_198 -> V_199 = F_118 ( V_18 -> V_10 [ 0 ] . V_2 ) ;
V_198 -> V_200 = F_118 ( V_18 -> V_104 [ 0 ] . V_2 ) ;
V_198 -> V_201 = V_198 -> V_199 ;
V_198 -> V_202 = V_198 -> V_200 ;
}
static void F_119 ( struct V_46 * V_21 ,
struct V_203 * V_204 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_118 * V_19 = V_18 -> V_19 ;
F_120 ( V_204 -> V_205 , V_206 , sizeof( V_204 -> V_205 ) ) ;
F_120 ( V_204 -> V_207 , V_208 , sizeof( V_204 -> V_207 ) ) ;
F_120 ( V_204 -> V_209 , F_121 ( V_19 ) , sizeof( V_204 -> V_209 ) ) ;
}
static int F_122 ( struct V_46 * V_21 ,
struct V_210 * V_211 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
T_6 V_153 = V_211 -> V_212 ;
int V_80 ;
if ( V_211 -> V_213 || V_211 -> V_214 || V_211 -> V_215 )
return - V_43 ;
if ( V_153 > V_18 -> V_95 )
return - V_43 ;
F_123 () ;
V_80 = F_99 ( V_18 , V_153 ) ;
if ( ! V_80 ) {
F_124 ( V_21 , V_153 ) ;
F_125 ( V_21 , V_153 ) ;
F_114 ( V_18 ) ;
}
F_126 () ;
return V_80 ;
}
static void F_127 ( struct V_46 * V_21 ,
struct V_210 * V_211 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
V_211 -> V_212 = V_18 -> V_135 ;
V_211 -> V_216 = V_18 -> V_95 ;
V_211 -> V_217 = 0 ;
V_211 -> V_213 = 0 ;
V_211 -> V_214 = 0 ;
V_211 -> V_215 = 0 ;
}
static int F_128 ( struct V_46 * V_21 , int V_218 )
{
if ( V_218 < V_219 || V_218 > V_220 )
return - V_43 ;
V_21 -> V_221 = V_218 ;
return 0 ;
}
static T_6 F_129 ( struct V_46 * V_21 , struct V_6 * V_7 )
{
int V_3 ;
struct V_17 * V_18 = F_62 ( V_21 ) ;
if ( F_130 ( V_7 ) ) {
V_3 = F_131 ( V_7 ) ;
} else {
V_3 = * F_132 ( V_18 -> V_186 ) ;
if ( V_3 == - 1 )
V_3 = 0 ;
}
while ( F_19 ( V_3 >= V_21 -> V_222 ) )
V_3 -= V_21 -> V_222 ;
return V_3 ;
}
static void F_133 ( struct V_91 * V_92 )
{
struct V_17 * V_18 =
F_55 ( V_92 , struct V_17 , V_223 ) ;
T_6 V_224 ;
F_134 ( & V_18 -> V_225 ) ;
if ( ! V_18 -> V_226 )
goto V_227;
if ( F_135 ( V_18 -> V_19 , V_228 ,
F_83 ( struct V_123 , V_145 ) ,
& V_224 ) < 0 )
goto V_227;
if ( V_224 & V_229 ) {
F_136 ( V_18 -> V_21 ) ;
F_96 ( V_18 ) ;
}
V_224 &= V_230 ;
if ( V_18 -> V_145 == V_224 )
goto V_227;
V_18 -> V_145 = V_224 ;
if ( V_18 -> V_145 & V_230 ) {
F_137 ( V_18 -> V_21 ) ;
F_138 ( V_18 -> V_21 ) ;
} else {
F_139 ( V_18 -> V_21 ) ;
F_140 ( V_18 -> V_21 ) ;
}
V_227:
F_141 ( & V_18 -> V_225 ) ;
}
static void F_142 ( struct V_118 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
F_143 ( & V_18 -> V_223 ) ;
}
static void F_144 ( struct V_17 * V_18 )
{
F_108 ( V_18 -> V_10 ) ;
F_108 ( V_18 -> V_104 ) ;
}
static void F_145 ( struct V_17 * V_18 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
while ( V_18 -> V_10 [ V_26 ] . V_14 )
F_146 ( F_7 ( & V_18 -> V_10 [ V_26 ] , V_96 ) , 0 ) ;
}
}
static void F_147 ( struct V_17 * V_18 )
{
void * V_45 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
struct V_1 * V_2 = V_18 -> V_104 [ V_26 ] . V_2 ;
while ( ( V_45 = F_148 ( V_2 ) ) != NULL )
F_23 ( V_45 ) ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
struct V_1 * V_2 = V_18 -> V_10 [ V_26 ] . V_2 ;
while ( ( V_45 = F_148 ( V_2 ) ) != NULL ) {
if ( V_18 -> V_34 || V_18 -> V_50 )
F_6 ( & V_18 -> V_10 [ V_26 ] , V_45 ) ;
else
F_23 ( V_45 ) ;
-- V_18 -> V_10 [ V_26 ] . V_44 ;
}
F_91 ( V_18 -> V_10 [ V_26 ] . V_44 != 0 ) ;
}
}
static void F_149 ( struct V_17 * V_18 )
{
struct V_118 * V_19 = V_18 -> V_19 ;
F_111 ( V_18 , - 1 ) ;
V_19 -> V_121 -> V_231 ( V_19 ) ;
F_144 ( V_18 ) ;
}
static int F_150 ( struct V_17 * V_18 )
{
T_7 * * V_232 ;
struct V_1 * * V_233 ;
int V_119 = - V_82 ;
int V_26 , V_234 ;
const char * * V_235 ;
V_234 = V_18 -> V_95 * 2 +
F_82 ( V_18 -> V_19 , V_147 ) ;
V_233 = F_105 ( V_234 * sizeof( * V_233 ) , V_96 ) ;
if ( ! V_233 )
goto V_236;
V_232 = F_151 ( V_234 * sizeof( * V_232 ) , V_96 ) ;
if ( ! V_232 )
goto V_237;
V_235 = F_151 ( V_234 * sizeof( * V_235 ) , V_96 ) ;
if ( ! V_235 )
goto V_238;
if ( V_18 -> V_155 ) {
V_232 [ V_234 - 1 ] = NULL ;
V_235 [ V_234 - 1 ] = L_23 ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
V_232 [ F_5 ( V_26 ) ] = F_47 ;
V_232 [ F_3 ( V_26 ) ] = F_9 ;
sprintf ( V_18 -> V_10 [ V_26 ] . V_38 , L_24 , V_26 ) ;
sprintf ( V_18 -> V_104 [ V_26 ] . V_38 , L_25 , V_26 ) ;
V_235 [ F_5 ( V_26 ) ] = V_18 -> V_10 [ V_26 ] . V_38 ;
V_235 [ F_3 ( V_26 ) ] = V_18 -> V_104 [ V_26 ] . V_38 ;
}
V_119 = V_18 -> V_19 -> V_121 -> V_239 ( V_18 -> V_19 , V_234 , V_233 , V_232 ,
V_235 ) ;
if ( V_119 )
goto V_240;
if ( V_18 -> V_155 ) {
V_18 -> V_149 = V_233 [ V_234 - 1 ] ;
if ( F_82 ( V_18 -> V_19 , V_241 ) )
V_18 -> V_21 -> V_242 |= V_243 ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
V_18 -> V_10 [ V_26 ] . V_2 = V_233 [ F_5 ( V_26 ) ] ;
V_18 -> V_104 [ V_26 ] . V_2 = V_233 [ F_3 ( V_26 ) ] ;
}
F_108 ( V_235 ) ;
F_108 ( V_232 ) ;
F_108 ( V_233 ) ;
return 0 ;
V_240:
F_108 ( V_235 ) ;
V_238:
F_108 ( V_232 ) ;
V_237:
F_108 ( V_233 ) ;
V_236:
return V_119 ;
}
static int F_152 ( struct V_17 * V_18 )
{
int V_26 ;
V_18 -> V_104 = F_105 ( sizeof( * V_18 -> V_104 ) * V_18 -> V_95 , V_96 ) ;
if ( ! V_18 -> V_104 )
goto V_244;
V_18 -> V_10 = F_105 ( sizeof( * V_18 -> V_10 ) * V_18 -> V_95 , V_96 ) ;
if ( ! V_18 -> V_10 )
goto V_245;
F_153 ( & V_18 -> V_93 , F_54 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
V_18 -> V_10 [ V_26 ] . V_14 = NULL ;
F_154 ( V_18 -> V_21 , & V_18 -> V_10 [ V_26 ] . V_90 , F_58 ,
V_246 ) ;
F_92 ( V_18 -> V_10 [ V_26 ] . V_83 , F_155 ( V_18 -> V_10 [ V_26 ] . V_83 ) ) ;
F_92 ( V_18 -> V_104 [ V_26 ] . V_83 , F_155 ( V_18 -> V_104 [ V_26 ] . V_83 ) ) ;
}
return 0 ;
V_245:
F_108 ( V_18 -> V_104 ) ;
V_244:
return - V_82 ;
}
static int F_156 ( struct V_17 * V_18 )
{
int V_119 ;
V_119 = F_152 ( V_18 ) ;
if ( V_119 )
goto V_80;
V_119 = F_150 ( V_18 ) ;
if ( V_119 )
goto V_247;
F_123 () ;
F_114 ( V_18 ) ;
F_126 () ;
return 0 ;
V_247:
F_144 ( V_18 ) ;
V_80:
return V_119 ;
}
static int F_157 ( struct V_118 * V_19 )
{
int V_26 , V_80 ;
struct V_46 * V_21 ;
struct V_17 * V_18 ;
T_6 V_95 ;
V_80 = F_135 ( V_19 , V_156 ,
F_83 ( struct V_123 ,
V_248 ) , & V_95 ) ;
if ( V_80 || V_95 < V_249 ||
V_95 > V_250 ||
! F_82 ( V_19 , V_147 ) )
V_95 = 1 ;
V_21 = F_158 ( sizeof( struct V_17 ) , V_95 ) ;
if ( ! V_21 )
return - V_82 ;
V_21 -> V_251 |= V_252 | V_253 ;
V_21 -> V_254 = & V_255 ;
V_21 -> V_242 = V_256 ;
F_159 ( V_21 , & V_257 ) ;
F_160 ( V_21 , & V_19 -> V_21 ) ;
if ( F_82 ( V_19 , V_258 ) ) {
V_21 -> V_259 |= V_260 | V_261 | V_262 ;
if ( V_263 )
V_21 -> V_242 |= V_260 | V_261 | V_262 ;
if ( F_82 ( V_19 , V_264 ) ) {
V_21 -> V_259 |= V_265 | V_266
| V_267 | V_268 ;
}
if ( F_82 ( V_19 , V_269 ) )
V_21 -> V_259 |= V_265 ;
if ( F_82 ( V_19 , V_270 ) )
V_21 -> V_259 |= V_268 ;
if ( F_82 ( V_19 , V_271 ) )
V_21 -> V_259 |= V_267 ;
if ( F_82 ( V_19 , V_272 ) )
V_21 -> V_259 |= V_266 ;
if ( V_273 )
V_21 -> V_242 |= V_21 -> V_259 & ( V_274 | V_266 ) ;
}
if ( F_161 ( V_19 , V_120 ,
F_83 ( struct V_123 , V_124 ) ,
V_21 -> V_125 , V_21 -> V_126 ) < 0 )
F_162 ( V_21 ) ;
V_18 = F_62 ( V_21 ) ;
V_18 -> V_21 = V_21 ;
V_18 -> V_19 = V_19 ;
V_19 -> V_20 = V_18 ;
V_18 -> V_41 = F_163 ( struct V_47 ) ;
V_80 = - V_82 ;
if ( V_18 -> V_41 == NULL )
goto free;
V_18 -> V_186 = F_163 ( int ) ;
if ( V_18 -> V_186 == NULL )
goto V_275;
F_164 ( & V_18 -> V_225 ) ;
V_18 -> V_226 = true ;
F_165 ( & V_18 -> V_223 , F_133 ) ;
if ( F_82 ( V_19 , V_276 ) ||
F_82 ( V_19 , V_277 ) ||
F_82 ( V_19 , V_278 ) )
V_18 -> V_50 = true ;
if ( F_82 ( V_19 , V_279 ) )
V_18 -> V_34 = true ;
if ( F_82 ( V_19 , V_147 ) )
V_18 -> V_155 = true ;
V_18 -> V_135 = 1 ;
V_18 -> V_95 = V_95 ;
V_80 = F_156 ( V_18 ) ;
if ( V_80 )
goto V_280;
F_124 ( V_21 , 1 ) ;
F_125 ( V_21 , 1 ) ;
V_80 = F_166 ( V_21 ) ;
if ( V_80 ) {
F_25 ( L_26 ) ;
goto V_281;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
F_45 ( & V_18 -> V_10 [ V_26 ] , V_96 ) ;
if ( V_18 -> V_10 [ V_26 ] . V_44 == 0 ) {
F_147 ( V_18 ) ;
V_80 = - V_82 ;
goto V_282;
}
}
V_18 -> V_190 . V_283 = & F_116 ;
V_80 = F_167 ( & V_18 -> V_190 ) ;
if ( V_80 ) {
F_25 ( L_27 ) ;
goto V_282;
}
if ( F_82 ( V_18 -> V_19 , V_228 ) ) {
F_139 ( V_21 ) ;
F_143 ( & V_18 -> V_223 ) ;
} else {
V_18 -> V_145 = V_230 ;
F_137 ( V_21 ) ;
}
F_25 ( L_28 ,
V_21 -> V_38 , V_95 ) ;
return 0 ;
V_282:
F_145 ( V_18 ) ;
F_168 ( V_21 ) ;
V_281:
F_101 ( & V_18 -> V_93 ) ;
F_149 ( V_18 ) ;
V_280:
F_169 ( V_18 -> V_186 ) ;
V_275:
F_169 ( V_18 -> V_41 ) ;
free:
F_170 ( V_21 ) ;
return V_80 ;
}
static void F_171 ( struct V_17 * V_18 )
{
V_18 -> V_19 -> V_121 -> V_284 ( V_18 -> V_19 ) ;
F_147 ( V_18 ) ;
F_145 ( V_18 ) ;
F_149 ( V_18 ) ;
}
static void F_172 ( struct V_118 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
F_173 ( & V_18 -> V_190 ) ;
F_134 ( & V_18 -> V_225 ) ;
V_18 -> V_226 = false ;
F_141 ( & V_18 -> V_225 ) ;
F_168 ( V_18 -> V_21 ) ;
F_171 ( V_18 ) ;
F_174 ( & V_18 -> V_223 ) ;
F_169 ( V_18 -> V_186 ) ;
F_169 ( V_18 -> V_41 ) ;
F_170 ( V_18 -> V_21 ) ;
}
static int F_175 ( struct V_118 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
int V_26 ;
F_134 ( & V_18 -> V_225 ) ;
V_18 -> V_226 = false ;
F_141 ( & V_18 -> V_225 ) ;
F_176 ( V_18 -> V_21 ) ;
F_101 ( & V_18 -> V_93 ) ;
if ( F_177 ( V_18 -> V_21 ) )
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ ) {
F_56 ( & V_18 -> V_10 [ V_26 ] . V_90 ) ;
F_178 ( & V_18 -> V_10 [ V_26 ] . V_90 ) ;
}
F_171 ( V_18 ) ;
F_174 ( & V_18 -> V_223 ) ;
return 0 ;
}
static int F_179 ( struct V_118 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
int V_80 , V_26 ;
V_80 = F_156 ( V_18 ) ;
if ( V_80 )
return V_80 ;
if ( F_177 ( V_18 -> V_21 ) )
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ )
F_50 ( & V_18 -> V_10 [ V_26 ] ) ;
F_180 ( V_18 -> V_21 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_95 ; V_26 ++ )
if ( ! F_45 ( & V_18 -> V_10 [ V_26 ] , V_96 ) )
F_57 ( & V_18 -> V_93 , 0 ) ;
F_134 ( & V_18 -> V_225 ) ;
V_18 -> V_226 = true ;
F_141 ( & V_18 -> V_225 ) ;
F_99 ( V_18 , V_18 -> V_135 ) ;
return 0 ;
}
static int T_8 F_181 ( void )
{
return F_182 ( & V_285 ) ;
}
static void T_9 F_183 ( void )
{
F_184 ( & V_285 ) ;
}
