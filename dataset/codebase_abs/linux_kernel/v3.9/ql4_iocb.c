static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
if ( ( V_3 + 2 ) >= V_2 -> V_5 ) {
V_4 = ( T_1 ) V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( V_2 -> V_8 < V_4 )
V_2 -> V_5 = V_4 - V_2 -> V_8 ;
else
V_2 -> V_5 = V_9 -
( V_2 -> V_8 - V_4 ) ;
}
if ( ( V_3 + 2 ) < V_2 -> V_5 )
return 1 ;
else
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == ( V_9 - 1 ) ) {
V_2 -> V_8 = 0 ;
V_2 -> V_10 = V_2 -> V_11 ;
} else {
V_2 -> V_8 ++ ;
V_2 -> V_10 ++ ;
}
}
static int F_3 ( struct V_1 * V_2 ,
struct V_12 * * V_12 )
{
T_1 V_3 = 1 ;
if ( F_1 ( V_2 , V_3 ) ) {
* V_12 = V_2 -> V_10 ;
memset ( * V_12 , 0 , sizeof( * * V_12 ) ) ;
F_2 ( V_2 ) ;
V_2 -> V_5 -= V_3 ;
return V_13 ;
}
return V_14 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_15 , int V_16 , T_1 V_17 )
{
struct V_18 * V_19 ;
unsigned long V_20 = 0 ;
T_2 V_21 = V_13 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
if ( F_3 ( V_2 , (struct V_12 * * ) & V_19 ) !=
V_13 ) {
V_21 = V_14 ;
goto V_23;
}
V_19 -> V_24 . V_25 = V_26 ;
V_19 -> V_24 . V_27 = 1 ;
V_19 -> V_28 = F_6 ( V_15 -> V_29 ) ;
V_19 -> V_30 = F_6 ( V_17 ) ;
F_7 ( V_16 , & V_19 -> V_16 ) ;
F_8 () ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_23:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_21 ;
}
static struct V_32 *
F_10 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_2 -> V_10 ;
F_2 ( V_2 ) ;
V_33 -> V_24 . V_25 = V_34 ;
V_33 -> V_24 . V_27 = 1 ;
V_33 -> V_24 . V_35 = ( T_2 ) F_6 ( V_2 -> V_8 ) ;
return V_33 ;
}
static T_1 F_11 ( T_1 V_36 )
{
T_1 V_37 ;
V_37 = 1 ;
if ( V_36 > V_38 ) {
V_37 += ( V_36 - V_38 ) / V_39 ;
if ( ( V_36 - V_38 ) % V_39 )
V_37 ++ ;
}
return V_37 ;
}
static void F_12 ( struct V_40 * V_40 ,
struct V_41 * V_42 ,
T_1 V_43 )
{
struct V_1 * V_2 ;
T_1 V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 ;
V_48 = V_40 -> V_48 ;
V_2 = V_40 -> V_2 ;
if ( ! F_13 ( V_48 ) || V_48 -> V_52 == V_53 ) {
V_42 -> V_54 = F_14 ( 0 ) ;
return;
}
V_44 = V_38 ;
V_46 = (struct V_45 * ) & ( V_42 -> V_55 [ 0 ] ) ;
F_15 (cmd, sg, tot_dsds, i) {
T_3 V_56 ;
if ( V_44 == 0 ) {
struct V_32 * V_33 ;
V_33 = F_10 ( V_2 ) ;
V_46 =
(struct V_45 * )
& V_33 -> V_55 [ 0 ] ;
V_44 = V_39 ;
}
V_56 = F_16 ( V_50 ) ;
V_46 -> V_57 . V_58 = F_17 ( F_18 ( V_56 ) ) ;
V_46 -> V_57 . V_59 = F_17 ( F_19 ( V_56 ) ) ;
V_46 -> V_60 = F_17 ( F_20 ( V_50 ) ) ;
V_44 -- ;
V_46 ++ ;
}
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_8 , & V_2 -> V_61 -> V_62 ) ;
F_23 ( & V_2 -> V_61 -> V_62 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_63 , & V_2 -> V_61 -> V_64 ) ;
F_23 ( & V_2 -> V_61 -> V_64 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
T_4 V_65 = 0 ;
V_65 = 0x14 | ( V_2 -> V_66 << 5 ) ;
V_65 = V_65 | ( 0 << 8 ) | ( V_2 -> V_8 << 16 ) ;
F_26 ( V_2 , V_2 -> V_67 , V_2 -> V_8 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_63 , & V_2 -> V_68 -> V_64 ) ;
F_23 ( & V_2 -> V_68 -> V_64 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_8 , & V_2 -> V_69 -> V_62 ) ;
F_23 ( & V_2 -> V_69 -> V_62 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_63 , & V_2 -> V_69 -> V_64 ) ;
F_23 ( & V_2 -> V_69 -> V_64 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
struct V_47 * V_48 = V_40 -> V_48 ;
struct V_15 * V_15 ;
struct V_41 * V_42 ;
int V_70 ;
T_1 V_43 ;
T_1 V_3 ;
unsigned long V_20 ;
T_4 V_71 ;
char V_72 [ 2 ] ;
V_15 = V_40 -> V_73 ;
V_43 = 0 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_71 = ( T_4 ) V_48 -> V_74 -> V_72 ;
if ( ! F_31 ( V_75 , & V_2 -> V_20 ) ) {
F_32 ( F_33 ( L_1
L_2 ,
V_2 -> V_76 , V_77 ) ) ;
goto V_78;
}
V_70 = F_34 ( V_48 ) ;
if ( V_70 < 0 )
goto V_78;
V_43 = V_70 ;
V_3 = F_11 ( V_43 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
goto V_78;
if ( ( V_2 -> V_79 + V_3 ) >= V_2 -> V_80 )
goto V_78;
V_42 = (struct V_41 * ) V_2 -> V_10 ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 -> V_24 . V_25 = V_81 ;
V_42 -> V_82 = F_17 ( V_71 ) ;
V_42 -> V_28 = F_6 ( V_15 -> V_29 ) ;
F_7 ( V_48 -> V_83 -> V_16 , & V_42 -> V_16 ) ;
V_42 -> V_54 = F_17 ( F_13 ( V_48 ) ) ;
memcpy ( V_42 -> V_84 , V_48 -> V_85 , V_48 -> V_86 ) ;
V_42 -> V_87 = F_6 ( V_43 ) ;
V_42 -> V_24 . V_27 = V_3 ;
V_42 -> V_88 = V_89 ;
if ( F_13 ( V_48 ) ) {
if ( V_48 -> V_52 == V_90 )
V_42 -> V_88 = V_91 ;
else if ( V_48 -> V_52 == V_92 )
V_42 -> V_88 = V_93 ;
V_2 -> V_94 += F_13 ( V_48 ) ;
if ( V_2 -> V_94 & ~ 0xFFFFF ) {
V_2 -> V_95 += V_2 -> V_94 >> 20 ;
V_2 -> V_94 &= 0xFFFFF ;
}
}
V_42 -> V_88 |= V_96 ;
if ( F_35 ( V_48 , V_72 ) )
switch ( V_72 [ 0 ] ) {
case V_97 :
V_42 -> V_88 |= V_98 ;
break;
case V_99 :
V_42 -> V_88 |= V_100 ;
break;
}
F_2 ( V_2 ) ;
F_12 ( V_40 , V_42 , V_43 ) ;
F_8 () ;
V_40 -> V_48 -> V_101 = ( unsigned char * ) ( unsigned long ) V_71 ;
V_40 -> V_102 = V_103 ;
V_40 -> V_20 |= V_104 ;
V_2 -> V_79 += V_3 ;
V_40 -> V_79 = V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_13 ;
V_78:
if ( V_43 )
F_36 ( V_48 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_14 ;
}
int F_37 ( struct V_105 * V_106 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 = V_106 -> V_111 -> V_112 ;
struct V_15 * V_15 = V_110 -> V_113 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_114 * V_115 = V_106 -> V_113 ;
T_1 V_116 = 0 ;
unsigned long V_20 ;
int V_117 = V_14 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_115 -> V_118 = 1 ;
if ( ! F_1 ( V_2 , V_115 -> V_118 ) )
goto V_78;
V_108 = (struct V_107 * ) V_2 -> V_10 ;
memset ( V_108 , 0 , sizeof( struct V_107 ) ) ;
V_108 -> V_24 . V_25 = V_119 ;
V_108 -> V_24 . V_35 = V_120 ;
V_108 -> V_24 . V_27 = V_115 -> V_118 ;
V_108 -> V_82 = V_106 -> V_121 ;
V_108 -> V_28 = F_6 ( V_15 -> V_29 ) ;
V_108 -> V_122 = F_6 ( V_123 ) ;
if ( V_115 -> V_124 ) {
memcpy ( ( T_2 * ) V_115 -> V_125 +
sizeof( struct V_126 ) , V_106 -> V_127 , V_106 -> V_128 ) ;
V_116 |= V_129 ;
V_108 -> V_130 . V_57 . V_58 =
F_17 ( F_18 ( V_115 -> V_131 ) ) ;
V_108 -> V_130 . V_57 . V_59 =
F_17 ( F_19 ( V_115 -> V_131 ) ) ;
V_108 -> V_130 . V_60 =
F_17 ( V_106 -> V_128 +
sizeof( struct V_126 ) ) ;
}
if ( V_115 -> V_132 ) {
V_108 -> V_133 . V_57 . V_58 =
F_17 ( F_18 ( V_115 -> V_134 ) ) ;
V_108 -> V_133 . V_57 . V_59 =
F_17 ( F_19 ( V_115 -> V_134 ) ) ;
V_108 -> V_133 . V_60 =
F_17 ( V_115 -> V_132 ) ;
}
V_116 |= ( V_135 | V_136 ) ;
V_108 -> V_88 = F_6 ( V_116 ) ;
F_2 ( V_2 ) ;
F_8 () ;
V_2 -> V_79 += V_115 -> V_118 ;
V_2 -> V_5 -= V_115 -> V_118 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_117 = V_13 ;
V_78:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_117 ;
}
static struct V_137 * F_38 ( struct V_1 * V_2 )
{
struct V_137 * V_137 ;
V_137 = F_39 ( sizeof( * V_137 ) , V_138 ) ;
if ( ! V_137 )
return V_137 ;
V_137 -> V_2 = V_2 ;
return V_137 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_137 * V_137 ,
T_4 * V_139 )
{
int V_140 = V_13 ;
T_4 V_51 ;
unsigned long V_20 ;
T_4 V_71 = 0 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_140 = F_3 ( V_2 , (struct V_12 * * ) & ( V_137 -> V_141 ) ) ;
if ( V_140 != V_13 )
goto V_142;
V_71 = V_2 -> V_143 ;
for ( V_51 = 0 ; V_51 < V_144 ; V_51 ++ ) {
V_71 ++ ;
if ( V_71 == V_144 )
V_71 = 1 ;
if ( V_2 -> V_145 [ V_71 ] == NULL ) {
V_2 -> V_143 = V_71 ;
break;
}
}
V_137 -> V_79 = 1 ;
V_2 -> V_145 [ V_71 ] = V_137 ;
V_137 -> V_141 -> V_82 = V_71 ;
V_137 -> V_141 -> V_24 . V_25 = V_146 ;
V_137 -> V_141 -> V_24 . V_27 = V_137 -> V_79 ;
memcpy ( V_137 -> V_141 -> V_139 , V_139 , 32 ) ;
V_137 -> V_147 = V_139 [ 0 ] ;
F_8 () ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_142:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_140 ;
}
int F_41 ( struct V_1 * V_2 , T_4 V_148 ,
T_4 V_149 , T_4 V_150 , T_2 * V_151 )
{
T_4 V_139 [ 8 ] ;
struct V_137 * V_137 = NULL ;
int V_140 = V_13 ;
memset ( V_139 , 0 , sizeof( V_139 ) ) ;
V_137 = F_38 ( V_2 ) ;
if ( ! V_137 ) {
F_32 ( F_42 ( V_152 , V_2 , L_3 ,
V_77 ) ) ;
V_140 = V_14 ;
goto V_153;
}
V_139 [ 0 ] = V_154 ;
V_139 [ 1 ] = V_148 ;
memcpy ( & V_139 [ 2 ] , & V_151 [ 0 ] , 4 ) ;
memcpy ( & V_139 [ 3 ] , & V_151 [ 4 ] , 4 ) ;
memcpy ( & V_139 [ 4 ] , & V_151 [ 8 ] , 4 ) ;
memcpy ( & V_139 [ 5 ] , & V_151 [ 12 ] , 4 ) ;
V_139 [ 6 ] = V_149 ;
V_137 -> V_150 = V_150 ;
V_140 = F_40 ( V_2 , V_137 , V_139 ) ;
if ( V_140 != V_13 )
goto V_153;
return V_140 ;
V_153:
F_43 ( V_137 ) ;
return V_140 ;
}
