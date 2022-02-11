static void F_1 ( struct V_1 * V_2 )
{}
static struct V_3 * F_2 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_6 = & V_9 [ V_7 ] ;
if ( V_6 -> V_10 == V_5 -> V_6 . V_11 . V_12 )
break;
}
if ( V_7 == V_8 )
return NULL ;
return & V_9 [ V_7 ] ;
}
static inline struct V_13 * F_3 ( struct V_14 * V_14 )
{
return F_4 ( V_14 -> V_15 , struct V_13 , V_16 ) ;
}
static struct V_17 * F_5 ( struct V_13 * V_18 ,
enum V_19 type )
{
switch ( type ) {
case V_20 :
return & V_18 -> V_21 [ V_22 ] ;
case V_23 :
return & V_18 -> V_21 [ V_24 ] ;
default:
F_6 () ;
}
return NULL ;
}
static int F_7 ( struct V_13 * V_18 ,
struct V_25 * V_26 ,
struct V_25 * V_27 )
{
struct V_28 * V_2 = V_18 -> V_2 ;
struct V_17 * V_21 ;
T_1 * V_29 , * V_30 ;
int V_31 , V_32 , V_33 , V_34 ;
int V_35 , V_36 ;
int V_37 , V_38 , V_39 ;
V_21 = F_5 ( V_18 , V_20 ) ;
V_37 = V_21 -> V_37 ;
V_38 = V_21 -> V_38 ;
V_39 = ( V_21 -> V_37 * V_21 -> V_6 -> V_40 ) >> 3 ;
V_29 = F_8 ( & V_26 -> V_41 , 0 ) ;
V_30 = F_8 ( & V_27 -> V_41 , 0 ) ;
if ( ! V_29 || ! V_30 ) {
F_9 ( & V_2 -> V_42 ,
L_1 ) ;
return - V_43 ;
}
if ( F_10 ( & V_26 -> V_41 , 0 ) >
F_10 ( & V_27 -> V_41 , 0 ) ) {
F_9 ( & V_2 -> V_42 , L_2 ) ;
return - V_44 ;
}
V_35 = ( V_37 * ( V_21 [ V_24 ] . V_6 -> V_40 >> 3 ) )
/ V_45 ;
V_36 = V_39 - V_35 * V_45 ;
V_34 = 0 ;
V_27 -> V_46 =
F_5 ( V_18 , V_23 ) -> V_46 ++ ;
V_26 -> V_46 = V_21 -> V_46 ++ ;
V_27 -> V_41 . V_47 = V_26 -> V_41 . V_47 ;
if ( V_26 -> V_48 & V_49 )
V_27 -> V_50 = V_26 -> V_50 ;
V_27 -> V_51 = V_26 -> V_51 ;
V_27 -> V_48 = V_26 -> V_48 &
( V_49 |
V_52 |
V_53 |
V_54 |
V_55 ) ;
switch ( V_18 -> V_56 ) {
case V_57 | V_58 :
V_30 += V_39 * V_38 - V_36 ;
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_45 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ +
V_59 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ -
V_59 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 -= V_36 ;
}
break;
case V_57 :
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
V_30 += V_45 * V_35 ;
for ( V_33 = 0 ; V_33 < V_45 ; ++ V_33 ) {
if ( V_34 & 0x01 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ +
V_59 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ -
V_59 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_39 ;
}
break;
case V_58 :
V_30 += V_39 * ( V_38 - 1 ) ;
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_45 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ +
V_59 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ -
V_59 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_36 - 2 * V_39 ;
}
break;
default:
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_45 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ +
V_59 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ -
V_59 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_36 ;
}
}
return 0 ;
}
static void F_11 ( struct V_28 * V_2 , int V_60 )
{
F_12 ( V_2 , L_3 ) ;
F_13 ( & V_2 -> V_61 , V_62 + F_14 ( V_60 ) ) ;
}
static int F_15 ( void * V_63 )
{
struct V_13 * V_18 = V_63 ;
if ( F_16 ( V_18 -> V_16 . V_64 ) < V_18 -> V_65
|| F_17 ( V_18 -> V_16 . V_64 ) < V_18 -> V_65 ) {
F_12 ( V_18 -> V_2 , L_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_18 ( void * V_63 )
{
struct V_13 * V_18 = V_63 ;
V_18 -> V_66 = 1 ;
}
static void F_19 ( void * V_63 )
{
struct V_13 * V_18 = V_63 ;
struct V_28 * V_2 = V_18 -> V_2 ;
struct V_25 * V_67 , * V_68 ;
V_67 = F_20 ( V_18 -> V_16 . V_64 ) ;
V_68 = F_21 ( V_18 -> V_16 . V_64 ) ;
F_7 ( V_18 , V_67 , V_68 ) ;
F_11 ( V_2 , V_18 -> V_69 ) ;
}
static void F_22 ( unsigned long V_63 )
{
struct V_28 * V_28 = (struct V_28 * ) V_63 ;
struct V_13 * V_70 ;
struct V_25 * V_71 , * V_72 ;
unsigned long V_48 ;
V_70 = F_23 ( V_28 -> V_73 ) ;
if ( NULL == V_70 ) {
F_24 ( L_5 ) ;
return;
}
V_71 = F_25 ( V_70 -> V_16 . V_64 ) ;
V_72 = F_26 ( V_70 -> V_16 . V_64 ) ;
V_70 -> V_74 ++ ;
F_27 ( & V_28 -> V_75 , V_48 ) ;
F_28 ( V_71 , V_76 ) ;
F_28 ( V_72 , V_76 ) ;
F_29 ( & V_28 -> V_75 , V_48 ) ;
if ( V_70 -> V_74 == V_70 -> V_65
|| V_70 -> V_66 ) {
F_12 ( V_70 -> V_2 , L_6 ) ;
V_70 -> V_74 = 0 ;
F_30 ( V_28 -> V_73 , V_70 -> V_16 . V_64 ) ;
} else {
F_19 ( V_70 ) ;
}
}
static int F_31 ( struct V_14 * V_14 , void * V_63 ,
struct V_77 * V_78 )
{
strncpy ( V_78 -> V_79 , V_80 , sizeof( V_78 -> V_79 ) - 1 ) ;
strncpy ( V_78 -> V_81 , V_80 , sizeof( V_78 -> V_81 ) - 1 ) ;
snprintf ( V_78 -> V_82 , sizeof( V_78 -> V_82 ) ,
L_7 , V_80 ) ;
V_78 -> V_83 = V_84 | V_85 ;
V_78 -> V_86 = V_78 -> V_83 | V_87 ;
return 0 ;
}
static int F_32 ( struct V_88 * V_5 , T_2 type )
{
int V_89 , V_90 ;
struct V_3 * V_6 ;
V_90 = 0 ;
for ( V_89 = 0 ; V_89 < V_8 ; ++ V_89 ) {
if ( V_9 [ V_89 ] . V_91 & type ) {
if ( V_90 == V_5 -> V_92 )
break;
++ V_90 ;
}
}
if ( V_89 < V_8 ) {
V_6 = & V_9 [ V_89 ] ;
V_5 -> V_12 = V_6 -> V_10 ;
return 0 ;
}
return - V_44 ;
}
static int F_33 ( struct V_14 * V_14 , void * V_63 ,
struct V_88 * V_5 )
{
return F_32 ( V_5 , V_93 ) ;
}
static int F_34 ( struct V_14 * V_14 , void * V_63 ,
struct V_88 * V_5 )
{
return F_32 ( V_5 , V_94 ) ;
}
static int F_35 ( struct V_13 * V_18 , struct V_4 * V_5 )
{
struct V_95 * V_96 ;
struct V_17 * V_21 ;
V_96 = F_36 ( V_18 -> V_16 . V_64 , V_5 -> type ) ;
if ( ! V_96 )
return - V_44 ;
V_21 = F_5 ( V_18 , V_5 -> type ) ;
V_5 -> V_6 . V_11 . V_37 = V_21 -> V_37 ;
V_5 -> V_6 . V_11 . V_38 = V_21 -> V_38 ;
V_5 -> V_6 . V_11 . V_51 = V_97 ;
V_5 -> V_6 . V_11 . V_12 = V_21 -> V_6 -> V_10 ;
V_5 -> V_6 . V_11 . V_39 = ( V_21 -> V_37 * V_21 -> V_6 -> V_40 ) >> 3 ;
V_5 -> V_6 . V_11 . V_98 = V_21 -> V_98 ;
V_5 -> V_6 . V_11 . V_99 = V_18 -> V_99 ;
return 0 ;
}
static int F_37 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
return F_35 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_38 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
return F_35 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_39 ( struct V_4 * V_5 , struct V_3 * V_6 )
{
if ( V_5 -> V_6 . V_11 . V_38 < V_100 )
V_5 -> V_6 . V_11 . V_38 = V_100 ;
else if ( V_5 -> V_6 . V_11 . V_38 > V_101 )
V_5 -> V_6 . V_11 . V_38 = V_101 ;
if ( V_5 -> V_6 . V_11 . V_37 < V_102 )
V_5 -> V_6 . V_11 . V_37 = V_102 ;
else if ( V_5 -> V_6 . V_11 . V_37 > V_103 )
V_5 -> V_6 . V_11 . V_37 = V_103 ;
V_5 -> V_6 . V_11 . V_37 &= ~ V_104 ;
V_5 -> V_6 . V_11 . V_39 = ( V_5 -> V_6 . V_11 . V_37 * V_6 -> V_40 ) >> 3 ;
V_5 -> V_6 . V_11 . V_98 = V_5 -> V_6 . V_11 . V_38 * V_5 -> V_6 . V_11 . V_39 ;
V_5 -> V_6 . V_11 . V_51 = V_97 ;
return 0 ;
}
static int F_40 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
struct V_3 * V_6 ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 ) {
V_5 -> V_6 . V_11 . V_12 = V_9 [ 0 ] . V_10 ;
V_6 = F_2 ( V_5 ) ;
}
if ( ! ( V_6 -> V_91 & V_93 ) ) {
F_9 ( & V_18 -> V_2 -> V_42 ,
L_8 ,
V_5 -> V_6 . V_11 . V_12 ) ;
return - V_44 ;
}
V_5 -> V_6 . V_11 . V_99 = V_18 -> V_99 ;
return F_39 ( V_5 , V_6 ) ;
}
static int F_41 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
struct V_3 * V_6 ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 ) {
V_5 -> V_6 . V_11 . V_12 = V_9 [ 0 ] . V_10 ;
V_6 = F_2 ( V_5 ) ;
}
if ( ! ( V_6 -> V_91 & V_94 ) ) {
F_9 ( & V_18 -> V_2 -> V_42 ,
L_8 ,
V_5 -> V_6 . V_11 . V_12 ) ;
return - V_44 ;
}
if ( ! V_5 -> V_6 . V_11 . V_99 )
V_5 -> V_6 . V_11 . V_99 = V_105 ;
return F_39 ( V_5 , V_6 ) ;
}
static int F_42 ( struct V_13 * V_18 , struct V_4 * V_5 )
{
struct V_17 * V_21 ;
struct V_95 * V_96 ;
V_96 = F_36 ( V_18 -> V_16 . V_64 , V_5 -> type ) ;
if ( ! V_96 )
return - V_44 ;
V_21 = F_5 ( V_18 , V_5 -> type ) ;
if ( ! V_21 )
return - V_44 ;
if ( F_43 ( V_96 ) ) {
F_9 ( & V_18 -> V_2 -> V_42 , L_9 , V_106 ) ;
return - V_107 ;
}
V_21 -> V_6 = F_2 ( V_5 ) ;
V_21 -> V_37 = V_5 -> V_6 . V_11 . V_37 ;
V_21 -> V_38 = V_5 -> V_6 . V_11 . V_38 ;
V_21 -> V_98 = V_21 -> V_37 * V_21 -> V_38
* V_21 -> V_6 -> V_40 >> 3 ;
F_12 ( V_18 -> V_2 ,
L_10 ,
V_5 -> type , V_21 -> V_37 , V_21 -> V_38 , V_21 -> V_6 -> V_10 ) ;
return 0 ;
}
static int F_44 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
int V_108 ;
V_108 = F_40 ( V_14 , V_63 , V_5 ) ;
if ( V_108 )
return V_108 ;
return F_42 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_45 ( struct V_14 * V_14 , void * V_63 ,
struct V_4 * V_5 )
{
struct V_13 * V_18 = F_3 ( V_14 ) ;
int V_108 ;
V_108 = F_41 ( V_14 , V_63 , V_5 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_42 ( F_3 ( V_14 ) , V_5 ) ;
if ( ! V_108 )
V_18 -> V_99 = V_5 -> V_6 . V_11 . V_99 ;
return V_108 ;
}
static int F_46 ( struct V_109 * V_110 )
{
struct V_13 * V_18 =
F_4 ( V_110 -> V_111 , struct V_13 , V_112 ) ;
switch ( V_110 -> V_113 ) {
case V_114 :
if ( V_110 -> V_115 )
V_18 -> V_56 |= V_57 ;
else
V_18 -> V_56 &= ~ V_57 ;
break;
case V_116 :
if ( V_110 -> V_115 )
V_18 -> V_56 |= V_58 ;
else
V_18 -> V_56 &= ~ V_58 ;
break;
case V_117 :
V_18 -> V_69 = V_110 -> V_115 ;
break;
case V_118 :
V_18 -> V_65 = V_110 -> V_115 ;
break;
default:
F_9 ( & V_18 -> V_2 -> V_42 , L_11 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_47 ( struct V_95 * V_96 ,
unsigned int * V_119 , unsigned int * V_120 ,
unsigned int V_121 [] , void * V_122 [] )
{
struct V_13 * V_18 = F_48 ( V_96 ) ;
struct V_17 * V_21 ;
unsigned int V_123 , V_124 = * V_119 ;
V_21 = F_5 ( V_18 , V_96 -> type ) ;
V_123 = V_21 -> V_37 * V_21 -> V_38 * V_21 -> V_6 -> V_40 >> 3 ;
while ( V_123 * V_124 > V_125 )
( V_124 ) -- ;
* V_119 = V_124 ;
if ( * V_120 )
return V_121 [ 0 ] < V_123 ? - V_44 : 0 ;
* V_120 = 1 ;
V_121 [ 0 ] = V_123 ;
F_12 ( V_18 -> V_2 , L_12 , V_124 , V_123 ) ;
return 0 ;
}
static int F_49 ( struct V_126 * V_127 )
{
struct V_25 * V_128 = F_50 ( V_127 ) ;
struct V_13 * V_18 = F_48 ( V_127 -> V_95 ) ;
struct V_17 * V_21 ;
F_12 ( V_18 -> V_2 , L_13 , V_127 -> V_95 -> type ) ;
V_21 = F_5 ( V_18 , V_127 -> V_95 -> type ) ;
if ( F_51 ( V_127 -> V_95 -> type ) ) {
if ( V_128 -> V_51 == V_129 )
V_128 -> V_51 = V_97 ;
if ( V_128 -> V_51 != V_97 ) {
F_12 ( V_18 -> V_2 , L_14 ,
V_106 ) ;
return - V_44 ;
}
}
if ( F_10 ( V_127 , 0 ) < V_21 -> V_98 ) {
F_12 ( V_18 -> V_2 , L_15 ,
V_106 , F_10 ( V_127 , 0 ) , ( long ) V_21 -> V_98 ) ;
return - V_44 ;
}
F_52 ( V_127 , 0 , V_21 -> V_98 ) ;
return 0 ;
}
static void F_53 ( struct V_126 * V_127 )
{
struct V_25 * V_128 = F_50 ( V_127 ) ;
struct V_13 * V_18 = F_48 ( V_127 -> V_95 ) ;
F_54 ( V_18 -> V_16 . V_64 , V_128 ) ;
}
static int F_55 ( struct V_95 * V_130 , unsigned V_124 )
{
struct V_13 * V_18 = F_48 ( V_130 ) ;
struct V_17 * V_21 = F_5 ( V_18 , V_130 -> type ) ;
V_21 -> V_46 = 0 ;
return 0 ;
}
static void F_56 ( struct V_95 * V_130 )
{
struct V_13 * V_18 = F_48 ( V_130 ) ;
struct V_25 * V_128 ;
unsigned long V_48 ;
for (; ; ) {
if ( F_51 ( V_130 -> type ) )
V_128 = F_25 ( V_18 -> V_16 . V_64 ) ;
else
V_128 = F_26 ( V_18 -> V_16 . V_64 ) ;
if ( V_128 == NULL )
return;
F_27 ( & V_18 -> V_2 -> V_75 , V_48 ) ;
F_28 ( V_128 , V_131 ) ;
F_29 ( & V_18 -> V_2 -> V_75 , V_48 ) ;
}
}
static int F_57 ( void * V_63 , struct V_95 * V_132 , struct V_95 * V_133 )
{
struct V_13 * V_18 = V_63 ;
int V_108 ;
V_132 -> type = V_20 ;
V_132 -> V_134 = V_135 | V_136 | V_137 ;
V_132 -> V_138 = V_18 ;
V_132 -> V_139 = sizeof( struct V_140 ) ;
V_132 -> V_141 = & V_142 ;
V_132 -> V_143 = & V_144 ;
V_132 -> V_145 = V_146 ;
V_132 -> V_147 = & V_18 -> V_2 -> V_148 ;
V_108 = F_58 ( V_132 ) ;
if ( V_108 )
return V_108 ;
V_133 -> type = V_23 ;
V_133 -> V_134 = V_135 | V_136 | V_137 ;
V_133 -> V_138 = V_18 ;
V_133 -> V_139 = sizeof( struct V_140 ) ;
V_133 -> V_141 = & V_142 ;
V_133 -> V_143 = & V_144 ;
V_133 -> V_145 = V_146 ;
V_133 -> V_147 = & V_18 -> V_2 -> V_148 ;
return F_58 ( V_133 ) ;
}
static int F_59 ( struct V_14 * V_14 )
{
struct V_28 * V_2 = F_60 ( V_14 ) ;
struct V_13 * V_18 = NULL ;
struct V_149 * V_112 ;
int V_150 = 0 ;
if ( F_61 ( & V_2 -> V_148 ) )
return - V_151 ;
V_18 = F_62 ( sizeof( * V_18 ) , V_152 ) ;
if ( ! V_18 ) {
V_150 = - V_153 ;
goto V_154;
}
F_63 ( & V_18 -> V_16 , F_64 ( V_14 ) ) ;
V_14 -> V_15 = & V_18 -> V_16 ;
V_18 -> V_2 = V_2 ;
V_112 = & V_18 -> V_112 ;
F_65 ( V_112 , 4 ) ;
F_66 ( V_112 , & V_155 , V_114 , 0 , 1 , 1 , 0 ) ;
F_66 ( V_112 , & V_155 , V_116 , 0 , 1 , 1 , 0 ) ;
F_67 ( V_112 , & V_156 , NULL ) ;
F_67 ( V_112 , & V_157 , NULL ) ;
if ( V_112 -> error ) {
V_150 = V_112 -> error ;
F_68 ( V_112 ) ;
goto V_154;
}
V_18 -> V_16 . V_158 = V_112 ;
F_69 ( V_112 ) ;
V_18 -> V_21 [ V_22 ] . V_6 = & V_9 [ 0 ] ;
V_18 -> V_21 [ V_22 ] . V_37 = 640 ;
V_18 -> V_21 [ V_22 ] . V_38 = 480 ;
V_18 -> V_21 [ V_22 ] . V_98 =
V_18 -> V_21 [ V_22 ] . V_37 *
V_18 -> V_21 [ V_22 ] . V_38 *
( V_18 -> V_21 [ V_22 ] . V_6 -> V_40 >> 3 ) ;
V_18 -> V_21 [ V_24 ] = V_18 -> V_21 [ V_22 ] ;
V_18 -> V_99 = V_105 ;
V_18 -> V_16 . V_64 = F_70 ( V_2 -> V_73 , V_18 , & F_57 ) ;
if ( F_71 ( V_18 -> V_16 . V_64 ) ) {
V_150 = F_72 ( V_18 -> V_16 . V_64 ) ;
F_68 ( V_112 ) ;
F_73 ( V_18 ) ;
goto V_154;
}
F_74 ( & V_18 -> V_16 ) ;
F_75 ( & V_2 -> V_159 ) ;
F_12 ( V_2 , L_16 ,
V_18 , V_18 -> V_16 . V_64 ) ;
V_154:
F_76 ( & V_2 -> V_148 ) ;
return V_150 ;
}
static int F_77 ( struct V_14 * V_14 )
{
struct V_28 * V_2 = F_60 ( V_14 ) ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
F_12 ( V_2 , L_17 , V_18 ) ;
F_78 ( & V_18 -> V_16 ) ;
F_79 ( & V_18 -> V_16 ) ;
F_68 ( & V_18 -> V_112 ) ;
F_80 ( & V_2 -> V_148 ) ;
F_81 ( V_18 -> V_16 . V_64 ) ;
F_76 ( & V_2 -> V_148 ) ;
F_73 ( V_18 ) ;
F_82 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int F_83 ( struct V_160 * V_161 )
{
struct V_28 * V_2 ;
struct V_162 * V_163 ;
int V_108 ;
V_2 = F_84 ( & V_161 -> V_2 , sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 )
return - V_153 ;
F_85 ( & V_2 -> V_75 ) ;
V_108 = F_86 ( & V_161 -> V_2 , & V_2 -> V_42 ) ;
if ( V_108 )
return V_108 ;
F_87 ( & V_2 -> V_159 , 0 ) ;
F_88 ( & V_2 -> V_148 ) ;
V_2 -> V_163 = V_164 ;
V_163 = & V_2 -> V_163 ;
V_163 -> V_147 = & V_2 -> V_148 ;
V_163 -> V_42 = & V_2 -> V_42 ;
V_108 = F_89 ( V_163 , V_165 , 0 ) ;
if ( V_108 ) {
F_9 ( & V_2 -> V_42 , L_18 ) ;
goto V_166;
}
F_90 ( V_163 , V_2 ) ;
snprintf ( V_163 -> V_167 , sizeof( V_163 -> V_167 ) , L_19 , V_164 . V_167 ) ;
F_91 ( & V_2 -> V_42 ,
L_20 , V_163 -> V_90 ) ;
F_92 ( & V_2 -> V_61 , F_22 , ( long ) V_2 ) ;
F_93 ( V_161 , V_2 ) ;
V_2 -> V_73 = F_94 ( & V_168 ) ;
if ( F_71 ( V_2 -> V_73 ) ) {
F_9 ( & V_2 -> V_42 , L_21 ) ;
V_108 = F_72 ( V_2 -> V_73 ) ;
goto V_169;
}
return 0 ;
V_169:
F_95 ( V_2 -> V_73 ) ;
F_96 ( & V_2 -> V_163 ) ;
V_166:
F_97 ( & V_2 -> V_42 ) ;
return V_108 ;
}
static int F_98 ( struct V_160 * V_161 )
{
struct V_28 * V_2 = F_99 ( V_161 ) ;
F_91 ( & V_2 -> V_42 , L_22 V_80 ) ;
F_95 ( V_2 -> V_73 ) ;
F_100 ( & V_2 -> V_61 ) ;
F_96 ( & V_2 -> V_163 ) ;
F_97 ( & V_2 -> V_42 ) ;
return 0 ;
}
static void T_3 F_101 ( void )
{
F_102 ( & V_170 ) ;
F_103 ( & V_171 ) ;
}
static int T_4 F_104 ( void )
{
int V_108 ;
V_108 = F_105 ( & V_171 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_106 ( & V_170 ) ;
if ( V_108 )
F_103 ( & V_171 ) ;
return V_108 ;
}
