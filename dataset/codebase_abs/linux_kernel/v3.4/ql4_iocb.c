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
T_4 V_61 = 0 ;
V_61 = 0x14 | ( V_2 -> V_62 << 5 ) ;
V_61 = V_61 | ( 0 << 8 ) | ( V_2 -> V_8 << 16 ) ;
F_22 ( V_2 , V_2 -> V_63 , V_2 -> V_8 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_64 , & V_2 -> V_65 -> V_66 ) ;
F_25 ( & V_2 -> V_65 -> V_66 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_8 , & V_2 -> V_67 -> V_68 ) ;
F_25 ( & V_2 -> V_67 -> V_68 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_64 , & V_2 -> V_67 -> V_66 ) ;
F_25 ( & V_2 -> V_67 -> V_66 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
struct V_47 * V_48 = V_40 -> V_48 ;
struct V_15 * V_15 ;
struct V_41 * V_42 ;
int V_69 ;
T_1 V_43 ;
T_1 V_3 ;
unsigned long V_20 ;
T_4 V_70 ;
char V_71 [ 2 ] ;
V_15 = V_40 -> V_72 ;
V_43 = 0 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_70 = ( T_4 ) V_48 -> V_73 -> V_71 ;
if ( ! F_29 ( V_74 , & V_2 -> V_20 ) ) {
F_30 ( F_31 ( L_1
L_2 ,
V_2 -> V_75 , V_76 ) ) ;
goto V_77;
}
V_69 = F_32 ( V_48 ) ;
if ( V_69 < 0 )
goto V_77;
V_43 = V_69 ;
V_3 = F_11 ( V_43 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
goto V_77;
if ( ( V_2 -> V_78 + V_3 ) >= V_9 )
goto V_77;
V_42 = (struct V_41 * ) V_2 -> V_10 ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 -> V_24 . V_25 = V_79 ;
V_42 -> V_80 = F_17 ( V_70 ) ;
V_42 -> V_28 = F_6 ( V_15 -> V_29 ) ;
F_7 ( V_48 -> V_81 -> V_16 , & V_42 -> V_16 ) ;
V_42 -> V_54 = F_17 ( F_13 ( V_48 ) ) ;
memcpy ( V_42 -> V_82 , V_48 -> V_83 , V_48 -> V_84 ) ;
V_42 -> V_85 = F_6 ( V_43 ) ;
V_42 -> V_24 . V_27 = V_3 ;
V_42 -> V_86 = V_87 ;
if ( F_13 ( V_48 ) ) {
if ( V_48 -> V_52 == V_88 )
V_42 -> V_86 = V_89 ;
else if ( V_48 -> V_52 == V_90 )
V_42 -> V_86 = V_91 ;
V_2 -> V_92 += F_13 ( V_48 ) ;
if ( V_2 -> V_92 & ~ 0xFFFFF ) {
V_2 -> V_93 += V_2 -> V_92 >> 20 ;
V_2 -> V_92 &= 0xFFFFF ;
}
}
V_42 -> V_86 |= V_94 ;
if ( F_33 ( V_48 , V_71 ) )
switch ( V_71 [ 0 ] ) {
case V_95 :
V_42 -> V_86 |= V_96 ;
break;
case V_97 :
V_42 -> V_86 |= V_98 ;
break;
}
F_2 ( V_2 ) ;
F_12 ( V_40 , V_42 , V_43 ) ;
F_8 () ;
V_40 -> V_48 -> V_99 = ( unsigned char * ) ( unsigned long ) V_70 ;
V_40 -> V_100 = V_101 ;
V_40 -> V_20 |= V_102 ;
V_2 -> V_78 += V_3 ;
V_40 -> V_78 = V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_13 ;
V_77:
if ( V_43 )
F_34 ( V_48 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_14 ;
}
int F_35 ( struct V_103 * V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 = V_104 -> V_109 -> V_110 ;
struct V_15 * V_15 = V_108 -> V_111 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_112 * V_113 = V_104 -> V_111 ;
T_1 V_114 = 0 ;
unsigned long V_20 ;
int V_115 = V_14 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_113 -> V_116 = 1 ;
if ( ! F_1 ( V_2 , V_113 -> V_116 ) )
goto V_77;
V_106 = (struct V_105 * ) V_2 -> V_10 ;
memset ( V_106 , 0 , sizeof( struct V_105 ) ) ;
V_106 -> V_24 . V_25 = V_117 ;
V_106 -> V_24 . V_35 = V_118 ;
V_106 -> V_24 . V_27 = V_113 -> V_116 ;
V_106 -> V_80 = V_104 -> V_119 ;
V_106 -> V_28 = F_6 ( V_15 -> V_29 ) ;
V_106 -> V_120 = F_6 ( V_121 ) ;
if ( V_113 -> V_122 ) {
memcpy ( ( T_2 * ) V_113 -> V_123 +
sizeof( struct V_124 ) , V_104 -> V_125 , V_104 -> V_126 ) ;
V_114 |= V_127 ;
V_106 -> V_128 . V_57 . V_58 =
F_17 ( F_18 ( V_113 -> V_129 ) ) ;
V_106 -> V_128 . V_57 . V_59 =
F_17 ( F_19 ( V_113 -> V_129 ) ) ;
V_106 -> V_128 . V_60 =
F_17 ( V_104 -> V_126 +
sizeof( struct V_124 ) ) ;
}
if ( V_113 -> V_130 ) {
V_106 -> V_131 . V_57 . V_58 =
F_17 ( F_18 ( V_113 -> V_132 ) ) ;
V_106 -> V_131 . V_57 . V_59 =
F_17 ( F_19 ( V_113 -> V_132 ) ) ;
V_106 -> V_131 . V_60 =
F_17 ( V_113 -> V_130 ) ;
}
V_114 |= ( V_133 | V_134 ) ;
V_106 -> V_86 = F_6 ( V_114 ) ;
F_2 ( V_2 ) ;
F_8 () ;
V_2 -> V_78 += V_113 -> V_116 ;
V_2 -> V_5 -= V_113 -> V_116 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_115 = V_13 ;
V_77:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_115 ;
}
static struct V_135 * F_36 ( struct V_1 * V_2 )
{
struct V_135 * V_135 ;
V_135 = F_37 ( sizeof( * V_135 ) , V_136 ) ;
if ( ! V_135 )
return V_135 ;
V_135 -> V_2 = V_2 ;
return V_135 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_135 * V_135 ,
T_4 * V_137 )
{
int V_138 = V_13 ;
T_4 V_51 ;
unsigned long V_20 ;
T_4 V_70 = 0 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_138 = F_3 ( V_2 , (struct V_12 * * ) & ( V_135 -> V_139 ) ) ;
if ( V_138 != V_13 )
goto V_140;
V_70 = V_2 -> V_141 ;
for ( V_51 = 0 ; V_51 < V_142 ; V_51 ++ ) {
V_70 ++ ;
if ( V_70 == V_142 )
V_70 = 1 ;
if ( V_2 -> V_143 [ V_70 ] == NULL ) {
V_2 -> V_141 = V_70 ;
break;
}
}
V_135 -> V_78 = 1 ;
V_2 -> V_143 [ V_70 ] = V_135 ;
V_135 -> V_139 -> V_80 = V_70 ;
V_135 -> V_139 -> V_24 . V_25 = V_144 ;
V_135 -> V_139 -> V_24 . V_27 = V_135 -> V_78 ;
memcpy ( V_135 -> V_139 -> V_137 , V_137 , 32 ) ;
V_135 -> V_145 = V_137 [ 0 ] ;
F_8 () ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_140:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_138 ;
}
int F_39 ( struct V_1 * V_2 , T_4 V_146 ,
T_4 V_147 , T_4 V_148 , T_2 * V_149 )
{
T_4 V_137 [ 8 ] ;
struct V_135 * V_135 = NULL ;
int V_138 = V_13 ;
memset ( V_137 , 0 , sizeof( V_137 ) ) ;
V_135 = F_36 ( V_2 ) ;
if ( ! V_135 ) {
F_30 ( F_40 ( V_150 , V_2 , L_3 ,
V_76 ) ) ;
V_138 = V_14 ;
goto V_151;
}
V_137 [ 0 ] = V_152 ;
V_137 [ 1 ] = V_146 ;
memcpy ( & V_137 [ 2 ] , & V_149 [ 0 ] , 4 ) ;
memcpy ( & V_137 [ 3 ] , & V_149 [ 4 ] , 4 ) ;
memcpy ( & V_137 [ 4 ] , & V_149 [ 8 ] , 4 ) ;
memcpy ( & V_137 [ 5 ] , & V_149 [ 12 ] , 4 ) ;
V_137 [ 6 ] = V_147 ;
V_135 -> V_148 = V_148 ;
V_138 = F_38 ( V_2 , V_135 , V_137 ) ;
if ( V_138 != V_13 )
goto V_151;
return V_138 ;
V_151:
F_41 ( V_135 ) ;
return V_138 ;
}
