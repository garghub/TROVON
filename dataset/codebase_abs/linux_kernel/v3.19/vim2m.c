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
V_29 = F_8 ( V_26 , 0 ) ;
V_30 = F_8 ( V_27 , 0 ) ;
if ( ! V_29 || ! V_30 ) {
F_9 ( & V_2 -> V_41 ,
L_1 ) ;
return - V_42 ;
}
if ( F_10 ( V_26 , 0 ) > F_10 ( V_27 , 0 ) ) {
F_9 ( & V_2 -> V_41 , L_2 ) ;
return - V_43 ;
}
V_35 = ( V_37 * ( V_21 [ V_24 ] . V_6 -> V_40 >> 3 ) )
/ V_44 ;
V_36 = V_39 - V_35 * V_44 ;
V_34 = 0 ;
V_27 -> V_45 . V_46 = F_5 ( V_18 , V_23 ) -> V_46 ++ ;
V_26 -> V_45 . V_46 = V_21 -> V_46 ++ ;
memcpy ( & V_27 -> V_45 . V_47 ,
& V_26 -> V_45 . V_47 ,
sizeof( struct V_48 ) ) ;
if ( V_26 -> V_45 . V_49 & V_50 )
memcpy ( & V_27 -> V_45 . V_51 , & V_26 -> V_45 . V_51 ,
sizeof( struct V_52 ) ) ;
V_27 -> V_45 . V_53 = V_26 -> V_45 . V_53 ;
V_27 -> V_45 . V_49 = V_26 -> V_45 . V_49 &
( V_50 |
V_54 |
V_55 |
V_56 |
V_57 ) ;
switch ( V_18 -> V_58 ) {
case V_59 | V_60 :
V_30 += V_39 * V_38 - V_36 ;
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_44 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ +
V_61 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ -
V_61 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 -= V_36 ;
}
break;
case V_59 :
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
V_30 += V_44 * V_35 ;
for ( V_33 = 0 ; V_33 < V_44 ; ++ V_33 ) {
if ( V_34 & 0x01 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ +
V_61 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* -- V_30 = * V_29 ++ -
V_61 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_39 ;
}
break;
case V_60 :
V_30 += V_39 * ( V_38 - 1 ) ;
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_44 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ +
V_61 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ -
V_61 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_36 - 2 * V_39 ;
}
break;
default:
for ( V_32 = 0 ; V_32 < V_38 ; ++ V_32 ) {
for ( V_33 = 0 ; V_33 < V_44 ; ++ V_33 ) {
if ( V_34 & 0x1 ) {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ +
V_61 ;
} else {
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 )
* V_30 ++ = * V_29 ++ -
V_61 ;
}
++ V_34 ;
}
V_29 += V_36 ;
V_30 += V_36 ;
}
}
return 0 ;
}
static void F_11 ( struct V_28 * V_2 , int V_62 )
{
F_12 ( V_2 , L_3 ) ;
F_13 ( & V_2 -> V_63 , V_64 + F_14 ( V_62 ) ) ;
}
static int F_15 ( void * V_65 )
{
struct V_13 * V_18 = V_65 ;
if ( F_16 ( V_18 -> V_16 . V_66 ) < V_18 -> V_67
|| F_17 ( V_18 -> V_16 . V_66 ) < V_18 -> V_67 ) {
F_12 ( V_18 -> V_2 , L_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_18 ( void * V_65 )
{
struct V_13 * V_18 = V_65 ;
V_18 -> V_68 = 1 ;
}
static void F_19 ( void * V_65 )
{
struct V_13 * V_18 = V_65 ;
struct V_28 * V_2 = V_18 -> V_2 ;
struct V_25 * V_69 , * V_70 ;
V_69 = F_20 ( V_18 -> V_16 . V_66 ) ;
V_70 = F_21 ( V_18 -> V_16 . V_66 ) ;
F_7 ( V_18 , V_69 , V_70 ) ;
F_11 ( V_2 , V_18 -> V_71 ) ;
}
static void F_22 ( unsigned long V_65 )
{
struct V_28 * V_28 = (struct V_28 * ) V_65 ;
struct V_13 * V_72 ;
struct V_25 * V_73 , * V_74 ;
unsigned long V_49 ;
V_72 = F_23 ( V_28 -> V_75 ) ;
if ( NULL == V_72 ) {
F_24 ( L_5 ) ;
return;
}
V_73 = F_25 ( V_72 -> V_16 . V_66 ) ;
V_74 = F_26 ( V_72 -> V_16 . V_66 ) ;
V_72 -> V_76 ++ ;
F_27 ( & V_28 -> V_77 , V_49 ) ;
F_28 ( V_73 , V_78 ) ;
F_28 ( V_74 , V_78 ) ;
F_29 ( & V_28 -> V_77 , V_49 ) ;
if ( V_72 -> V_76 == V_72 -> V_67
|| V_72 -> V_68 ) {
F_12 ( V_72 -> V_2 , L_6 ) ;
V_72 -> V_76 = 0 ;
F_30 ( V_28 -> V_75 , V_72 -> V_16 . V_66 ) ;
} else {
F_19 ( V_72 ) ;
}
}
static int F_31 ( struct V_14 * V_14 , void * V_65 ,
struct V_79 * V_80 )
{
strncpy ( V_80 -> V_81 , V_82 , sizeof( V_80 -> V_81 ) - 1 ) ;
strncpy ( V_80 -> V_83 , V_82 , sizeof( V_80 -> V_83 ) - 1 ) ;
snprintf ( V_80 -> V_84 , sizeof( V_80 -> V_84 ) ,
L_7 , V_82 ) ;
V_80 -> V_85 = V_86 | V_87 ;
V_80 -> V_88 = V_80 -> V_85 | V_89 ;
return 0 ;
}
static int F_32 ( struct V_90 * V_5 , T_2 type )
{
int V_91 , V_92 ;
struct V_3 * V_6 ;
V_92 = 0 ;
for ( V_91 = 0 ; V_91 < V_8 ; ++ V_91 ) {
if ( V_9 [ V_91 ] . V_93 & type ) {
if ( V_92 == V_5 -> V_94 )
break;
++ V_92 ;
}
}
if ( V_91 < V_8 ) {
V_6 = & V_9 [ V_91 ] ;
strncpy ( V_5 -> V_95 , V_6 -> V_96 , sizeof( V_5 -> V_95 ) - 1 ) ;
V_5 -> V_12 = V_6 -> V_10 ;
return 0 ;
}
return - V_43 ;
}
static int F_33 ( struct V_14 * V_14 , void * V_65 ,
struct V_90 * V_5 )
{
return F_32 ( V_5 , V_97 ) ;
}
static int F_34 ( struct V_14 * V_14 , void * V_65 ,
struct V_90 * V_5 )
{
return F_32 ( V_5 , V_98 ) ;
}
static int F_35 ( struct V_13 * V_18 , struct V_4 * V_5 )
{
struct V_99 * V_100 ;
struct V_17 * V_21 ;
V_100 = F_36 ( V_18 -> V_16 . V_66 , V_5 -> type ) ;
if ( ! V_100 )
return - V_43 ;
V_21 = F_5 ( V_18 , V_5 -> type ) ;
V_5 -> V_6 . V_11 . V_37 = V_21 -> V_37 ;
V_5 -> V_6 . V_11 . V_38 = V_21 -> V_38 ;
V_5 -> V_6 . V_11 . V_53 = V_101 ;
V_5 -> V_6 . V_11 . V_12 = V_21 -> V_6 -> V_10 ;
V_5 -> V_6 . V_11 . V_39 = ( V_21 -> V_37 * V_21 -> V_6 -> V_40 ) >> 3 ;
V_5 -> V_6 . V_11 . V_102 = V_21 -> V_102 ;
V_5 -> V_6 . V_11 . V_103 = V_18 -> V_103 ;
return 0 ;
}
static int F_37 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
return F_35 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_38 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
return F_35 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_39 ( struct V_4 * V_5 , struct V_3 * V_6 )
{
if ( V_5 -> V_6 . V_11 . V_38 < V_104 )
V_5 -> V_6 . V_11 . V_38 = V_104 ;
else if ( V_5 -> V_6 . V_11 . V_38 > V_105 )
V_5 -> V_6 . V_11 . V_38 = V_105 ;
if ( V_5 -> V_6 . V_11 . V_37 < V_106 )
V_5 -> V_6 . V_11 . V_37 = V_106 ;
else if ( V_5 -> V_6 . V_11 . V_37 > V_107 )
V_5 -> V_6 . V_11 . V_37 = V_107 ;
V_5 -> V_6 . V_11 . V_37 &= ~ V_108 ;
V_5 -> V_6 . V_11 . V_39 = ( V_5 -> V_6 . V_11 . V_37 * V_6 -> V_40 ) >> 3 ;
V_5 -> V_6 . V_11 . V_102 = V_5 -> V_6 . V_11 . V_38 * V_5 -> V_6 . V_11 . V_39 ;
V_5 -> V_6 . V_11 . V_53 = V_101 ;
return 0 ;
}
static int F_40 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
struct V_3 * V_6 ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 ) {
V_5 -> V_6 . V_11 . V_12 = V_9 [ 0 ] . V_10 ;
V_6 = F_2 ( V_5 ) ;
}
if ( ! ( V_6 -> V_93 & V_97 ) ) {
F_9 ( & V_18 -> V_2 -> V_41 ,
L_8 ,
V_5 -> V_6 . V_11 . V_12 ) ;
return - V_43 ;
}
V_5 -> V_6 . V_11 . V_103 = V_18 -> V_103 ;
return F_39 ( V_5 , V_6 ) ;
}
static int F_41 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
struct V_3 * V_6 ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 ) {
V_5 -> V_6 . V_11 . V_12 = V_9 [ 0 ] . V_10 ;
V_6 = F_2 ( V_5 ) ;
}
if ( ! ( V_6 -> V_93 & V_98 ) ) {
F_9 ( & V_18 -> V_2 -> V_41 ,
L_8 ,
V_5 -> V_6 . V_11 . V_12 ) ;
return - V_43 ;
}
if ( ! V_5 -> V_6 . V_11 . V_103 )
V_5 -> V_6 . V_11 . V_103 = V_109 ;
return F_39 ( V_5 , V_6 ) ;
}
static int F_42 ( struct V_13 * V_18 , struct V_4 * V_5 )
{
struct V_17 * V_21 ;
struct V_99 * V_100 ;
V_100 = F_36 ( V_18 -> V_16 . V_66 , V_5 -> type ) ;
if ( ! V_100 )
return - V_43 ;
V_21 = F_5 ( V_18 , V_5 -> type ) ;
if ( ! V_21 )
return - V_43 ;
if ( F_43 ( V_100 ) ) {
F_9 ( & V_18 -> V_2 -> V_41 , L_9 , V_110 ) ;
return - V_111 ;
}
V_21 -> V_6 = F_2 ( V_5 ) ;
V_21 -> V_37 = V_5 -> V_6 . V_11 . V_37 ;
V_21 -> V_38 = V_5 -> V_6 . V_11 . V_38 ;
V_21 -> V_102 = V_21 -> V_37 * V_21 -> V_38
* V_21 -> V_6 -> V_40 >> 3 ;
F_12 ( V_18 -> V_2 ,
L_10 ,
V_5 -> type , V_21 -> V_37 , V_21 -> V_38 , V_21 -> V_6 -> V_10 ) ;
return 0 ;
}
static int F_44 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
int V_112 ;
V_112 = F_40 ( V_14 , V_65 , V_5 ) ;
if ( V_112 )
return V_112 ;
return F_42 ( F_3 ( V_14 ) , V_5 ) ;
}
static int F_45 ( struct V_14 * V_14 , void * V_65 ,
struct V_4 * V_5 )
{
struct V_13 * V_18 = F_3 ( V_14 ) ;
int V_112 ;
V_112 = F_41 ( V_14 , V_65 , V_5 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_42 ( F_3 ( V_14 ) , V_5 ) ;
if ( ! V_112 )
V_18 -> V_103 = V_5 -> V_6 . V_11 . V_103 ;
return V_112 ;
}
static int F_46 ( struct V_113 * V_114 )
{
struct V_13 * V_18 =
F_4 ( V_114 -> V_115 , struct V_13 , V_116 ) ;
switch ( V_114 -> V_117 ) {
case V_118 :
if ( V_114 -> V_119 )
V_18 -> V_58 |= V_59 ;
else
V_18 -> V_58 &= ~ V_59 ;
break;
case V_120 :
if ( V_114 -> V_119 )
V_18 -> V_58 |= V_60 ;
else
V_18 -> V_58 &= ~ V_60 ;
break;
case V_121 :
V_18 -> V_71 = V_114 -> V_119 ;
break;
case V_122 :
V_18 -> V_67 = V_114 -> V_119 ;
break;
default:
F_9 ( & V_18 -> V_2 -> V_41 , L_11 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_47 ( struct V_99 * V_100 ,
const struct V_4 * V_6 ,
unsigned int * V_123 , unsigned int * V_124 ,
unsigned int V_125 [] , void * V_126 [] )
{
struct V_13 * V_18 = F_48 ( V_100 ) ;
struct V_17 * V_21 ;
unsigned int V_127 , V_128 = * V_123 ;
V_21 = F_5 ( V_18 , V_100 -> type ) ;
V_127 = V_21 -> V_37 * V_21 -> V_38 * V_21 -> V_6 -> V_40 >> 3 ;
while ( V_127 * V_128 > V_129 )
( V_128 ) -- ;
* V_124 = 1 ;
* V_123 = V_128 ;
V_125 [ 0 ] = V_127 ;
F_12 ( V_18 -> V_2 , L_12 , V_128 , V_127 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_130 )
{
struct V_13 * V_18 = F_48 ( V_130 -> V_99 ) ;
struct V_17 * V_21 ;
F_12 ( V_18 -> V_2 , L_13 , V_130 -> V_99 -> type ) ;
V_21 = F_5 ( V_18 , V_130 -> V_99 -> type ) ;
if ( F_50 ( V_130 -> V_99 -> type ) ) {
if ( V_130 -> V_45 . V_53 == V_131 )
V_130 -> V_45 . V_53 = V_101 ;
if ( V_130 -> V_45 . V_53 != V_101 ) {
F_12 ( V_18 -> V_2 , L_14 ,
V_110 ) ;
return - V_43 ;
}
}
if ( F_10 ( V_130 , 0 ) < V_21 -> V_102 ) {
F_12 ( V_18 -> V_2 , L_15 ,
V_110 , F_10 ( V_130 , 0 ) , ( long ) V_21 -> V_102 ) ;
return - V_43 ;
}
F_51 ( V_130 , 0 , V_21 -> V_102 ) ;
return 0 ;
}
static void F_52 ( struct V_25 * V_130 )
{
struct V_13 * V_18 = F_48 ( V_130 -> V_99 ) ;
F_53 ( V_18 -> V_16 . V_66 , V_130 ) ;
}
static int F_54 ( struct V_99 * V_132 , unsigned V_128 )
{
struct V_13 * V_18 = F_48 ( V_132 ) ;
struct V_17 * V_21 = F_5 ( V_18 , V_132 -> type ) ;
V_21 -> V_46 = 0 ;
return 0 ;
}
static void F_55 ( struct V_99 * V_132 )
{
struct V_13 * V_18 = F_48 ( V_132 ) ;
struct V_25 * V_130 ;
unsigned long V_49 ;
for (; ; ) {
if ( F_50 ( V_132 -> type ) )
V_130 = F_25 ( V_18 -> V_16 . V_66 ) ;
else
V_130 = F_26 ( V_18 -> V_16 . V_66 ) ;
if ( V_130 == NULL )
return;
F_27 ( & V_18 -> V_2 -> V_77 , V_49 ) ;
F_28 ( V_130 , V_133 ) ;
F_29 ( & V_18 -> V_2 -> V_77 , V_49 ) ;
}
}
static int F_56 ( void * V_65 , struct V_99 * V_134 , struct V_99 * V_135 )
{
struct V_13 * V_18 = V_65 ;
int V_112 ;
V_134 -> type = V_20 ;
V_134 -> V_136 = V_137 | V_138 | V_139 ;
V_134 -> V_140 = V_18 ;
V_134 -> V_141 = sizeof( struct V_142 ) ;
V_134 -> V_143 = & V_144 ;
V_134 -> V_145 = & V_146 ;
V_134 -> V_147 = V_148 ;
V_134 -> V_149 = & V_18 -> V_2 -> V_150 ;
V_112 = F_57 ( V_134 ) ;
if ( V_112 )
return V_112 ;
V_135 -> type = V_23 ;
V_135 -> V_136 = V_137 | V_138 | V_139 ;
V_135 -> V_140 = V_18 ;
V_135 -> V_141 = sizeof( struct V_142 ) ;
V_135 -> V_143 = & V_144 ;
V_135 -> V_145 = & V_146 ;
V_135 -> V_147 = V_148 ;
V_135 -> V_149 = & V_18 -> V_2 -> V_150 ;
return F_57 ( V_135 ) ;
}
static int F_58 ( struct V_14 * V_14 )
{
struct V_28 * V_2 = F_59 ( V_14 ) ;
struct V_13 * V_18 = NULL ;
struct V_151 * V_116 ;
int V_152 = 0 ;
if ( F_60 ( & V_2 -> V_150 ) )
return - V_153 ;
V_18 = F_61 ( sizeof( * V_18 ) , V_154 ) ;
if ( ! V_18 ) {
V_152 = - V_155 ;
goto V_156;
}
F_62 ( & V_18 -> V_16 , F_63 ( V_14 ) ) ;
V_14 -> V_15 = & V_18 -> V_16 ;
V_18 -> V_2 = V_2 ;
V_116 = & V_18 -> V_116 ;
F_64 ( V_116 , 4 ) ;
F_65 ( V_116 , & V_157 , V_118 , 0 , 1 , 1 , 0 ) ;
F_65 ( V_116 , & V_157 , V_120 , 0 , 1 , 1 , 0 ) ;
F_66 ( V_116 , & V_158 , NULL ) ;
F_66 ( V_116 , & V_159 , NULL ) ;
if ( V_116 -> error ) {
V_152 = V_116 -> error ;
F_67 ( V_116 ) ;
goto V_156;
}
V_18 -> V_16 . V_160 = V_116 ;
F_68 ( V_116 ) ;
V_18 -> V_21 [ V_22 ] . V_6 = & V_9 [ 0 ] ;
V_18 -> V_21 [ V_22 ] . V_37 = 640 ;
V_18 -> V_21 [ V_22 ] . V_38 = 480 ;
V_18 -> V_21 [ V_22 ] . V_102 =
V_18 -> V_21 [ V_22 ] . V_37 *
V_18 -> V_21 [ V_22 ] . V_38 *
( V_18 -> V_21 [ V_22 ] . V_6 -> V_40 >> 3 ) ;
V_18 -> V_21 [ V_24 ] = V_18 -> V_21 [ V_22 ] ;
V_18 -> V_103 = V_109 ;
V_18 -> V_16 . V_66 = F_69 ( V_2 -> V_75 , V_18 , & F_56 ) ;
if ( F_70 ( V_18 -> V_16 . V_66 ) ) {
V_152 = F_71 ( V_18 -> V_16 . V_66 ) ;
F_67 ( V_116 ) ;
F_72 ( V_18 ) ;
goto V_156;
}
F_73 ( & V_18 -> V_16 ) ;
F_74 ( & V_2 -> V_161 ) ;
F_12 ( V_2 , L_16 ,
V_18 , V_18 -> V_16 . V_66 ) ;
V_156:
F_75 ( & V_2 -> V_150 ) ;
return V_152 ;
}
static int F_76 ( struct V_14 * V_14 )
{
struct V_28 * V_2 = F_59 ( V_14 ) ;
struct V_13 * V_18 = F_3 ( V_14 ) ;
F_12 ( V_2 , L_17 , V_18 ) ;
F_77 ( & V_18 -> V_16 ) ;
F_78 ( & V_18 -> V_16 ) ;
F_67 ( & V_18 -> V_116 ) ;
F_79 ( & V_2 -> V_150 ) ;
F_80 ( V_18 -> V_16 . V_66 ) ;
F_75 ( & V_2 -> V_150 ) ;
F_72 ( V_18 ) ;
F_81 ( & V_2 -> V_161 ) ;
return 0 ;
}
static int F_82 ( struct V_162 * V_163 )
{
struct V_28 * V_2 ;
struct V_164 * V_165 ;
int V_112 ;
V_2 = F_83 ( & V_163 -> V_2 , sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 )
return - V_155 ;
F_84 ( & V_2 -> V_77 ) ;
V_112 = F_85 ( & V_163 -> V_2 , & V_2 -> V_41 ) ;
if ( V_112 )
return V_112 ;
F_86 ( & V_2 -> V_161 , 0 ) ;
F_87 ( & V_2 -> V_150 ) ;
V_165 = F_88 () ;
if ( ! V_165 ) {
F_9 ( & V_2 -> V_41 , L_18 ) ;
V_112 = - V_155 ;
goto V_166;
}
* V_165 = V_167 ;
V_165 -> V_149 = & V_2 -> V_150 ;
V_165 -> V_41 = & V_2 -> V_41 ;
V_112 = F_89 ( V_165 , V_168 , 0 ) ;
if ( V_112 ) {
F_9 ( & V_2 -> V_41 , L_19 ) ;
goto V_169;
}
F_90 ( V_165 , V_2 ) ;
snprintf ( V_165 -> V_96 , sizeof( V_165 -> V_96 ) , L_20 , V_167 . V_96 ) ;
V_2 -> V_165 = V_165 ;
F_91 ( & V_2 -> V_41 ,
L_21 , V_165 -> V_92 ) ;
F_92 ( & V_2 -> V_63 , F_22 , ( long ) V_2 ) ;
F_93 ( V_163 , V_2 ) ;
V_2 -> V_75 = F_94 ( & V_170 ) ;
if ( F_70 ( V_2 -> V_75 ) ) {
F_9 ( & V_2 -> V_41 , L_22 ) ;
V_112 = F_71 ( V_2 -> V_75 ) ;
goto V_171;
}
return 0 ;
V_171:
F_95 ( V_2 -> V_75 ) ;
F_96 ( V_2 -> V_165 ) ;
V_169:
F_97 ( V_165 ) ;
V_166:
F_98 ( & V_2 -> V_41 ) ;
return V_112 ;
}
static int F_99 ( struct V_162 * V_163 )
{
struct V_28 * V_2 = F_100 ( V_163 ) ;
F_91 ( & V_2 -> V_41 , L_23 V_82 ) ;
F_95 ( V_2 -> V_75 ) ;
F_101 ( & V_2 -> V_63 ) ;
F_96 ( V_2 -> V_165 ) ;
F_98 ( & V_2 -> V_41 ) ;
return 0 ;
}
static void T_3 F_102 ( void )
{
F_103 ( & V_172 ) ;
F_104 ( & V_173 ) ;
}
static int T_4 F_105 ( void )
{
int V_112 ;
V_112 = F_106 ( & V_173 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_107 ( & V_172 ) ;
if ( V_112 )
F_104 ( & V_173 ) ;
return 0 ;
}
