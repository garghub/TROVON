static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
int free ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
free = F_5 ( V_2 -> V_7 , V_8 ) ;
F_6 ( free , V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
return free ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_9 )
{
int V_10 = F_9 ( V_2 -> V_7 , V_8 ) ;
F_10 ( V_9 , V_2 -> V_7 ) ;
V_2 -> V_11 [ V_9 ] = NULL ;
return V_10 || V_2 -> V_3 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_9 )
{
unsigned long V_5 ;
int V_12 ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
V_12 = F_8 ( V_2 , V_9 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
if ( V_12 )
F_1 ( V_2 ) ;
}
static struct V_13 * F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & ( V_2 -> V_15 ) ;
struct V_13 * V_16 ;
T_1 V_9 ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 >= V_8 )
return NULL ;
V_16 = F_13 ( & ( V_2 -> V_15 ) , V_15 -> V_17 ) ;
V_15 -> V_17 ++ ;
V_16 -> V_18 = ( V_19 ) V_9 ;
return V_16 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & ( V_2 -> V_15 ) ;
int V_20 ;
F_15 ( V_15 , V_20 ) ;
if ( V_20 )
F_16 ( V_2 -> V_21 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_22 * V_23 = V_2 -> V_11 [ V_9 ] ;
int V_24 ;
if ( V_23 -> V_25 -> V_26 == V_27 )
return;
for ( V_24 = 0 ; V_24 < V_23 -> V_28 ; V_24 ++ ) {
if ( F_18 ( F_19 ( V_23 -> V_29 [ V_24 ] ) != 0 ) ) {
F_20 ( V_30 , V_2 -> V_31 , V_32
L_1 ) ;
F_21 () ;
}
F_22 ( V_23 -> V_29 [ V_24 ] , 0 , 0UL ) ;
}
F_23 ( V_23 -> V_33 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_36 * V_25 ;
T_1 V_9 ;
T_2 V_37 ;
V_9 = V_35 -> V_18 ;
V_25 = V_2 -> V_11 [ V_9 ] -> V_25 ;
F_25 ( V_25 == NULL ) ;
F_17 ( V_2 , V_9 ) ;
F_11 ( V_2 , V_9 ) ;
V_25 -> V_38 = V_35 -> V_39 ;
F_26 ( V_25 , V_35 -> V_40 ) ;
V_37 = F_27 ( T_2 , V_41 ,
V_35 -> V_37 ) ;
if ( V_37 )
memcpy ( V_25 -> V_42 , V_35 -> V_42 , V_37 ) ;
V_25 -> V_43 ( V_25 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
V_19 V_9 = V_35 -> V_18 ;
unsigned long V_5 ;
struct V_22 * V_11 = V_2 -> V_11 [ V_9 ] ;
int V_12 ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
V_11 -> V_44 = 1 ;
switch ( V_11 -> V_45 ) {
case V_46 :
V_11 -> V_45 = V_35 -> V_39 ;
break;
case V_47 :
V_12 = F_8 ( V_2 , V_9 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
F_23 ( V_11 ) ;
if ( V_12 )
F_1 ( V_2 ) ;
return;
default:
F_20 ( V_48 , V_2 -> V_31 , V_32
L_2 ,
V_11 -> V_45 , V_9 ) ;
break;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
F_2 ( & V_11 -> V_49 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
if ( F_30 ( V_35 -> V_18 >= V_8 ||
F_31 ( V_35 -> V_18 , V_2 -> V_7 ) ,
L_3 , V_35 -> V_18 ) )
return;
if ( V_2 -> V_11 [ V_35 -> V_18 ] -> V_50 == V_51 )
F_24 ( V_2 , V_35 ) ;
else
F_28 ( V_2 , V_35 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_3 V_24 , V_52 ;
int V_53 = 0 ;
V_52 = V_2 -> V_15 . V_54 -> V_55 ;
F_33 () ;
for ( V_24 = V_2 -> V_15 . V_56 ; V_24 != V_52 ; V_24 ++ ) {
V_35 = F_34 ( & V_2 -> V_15 , V_24 ) ;
F_29 ( V_2 , V_35 ) ;
}
V_2 -> V_15 . V_56 = V_24 ;
if ( V_24 != V_2 -> V_15 . V_17 )
F_35 ( & V_2 -> V_15 , V_53 ) ;
else
V_2 -> V_15 . V_54 -> V_57 = V_24 + 1 ;
return V_53 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_53 ;
unsigned long V_5 ;
F_4 ( V_2 -> V_31 -> V_58 , V_5 ) ;
V_53 = F_32 ( V_2 ) ;
V_2 -> V_3 = 0 ;
F_7 ( V_2 -> V_31 -> V_58 , V_5 ) ;
F_2 ( & V_2 -> V_4 ) ;
return V_53 ;
}
static T_4 F_37 ( int V_21 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
while ( F_36 ( V_2 ) )
F_38 () ;
return V_60 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned V_24 ;
struct V_34 V_61 ;
F_32 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_8 ; V_24 ++ ) {
if ( F_31 ( V_24 , V_2 -> V_7 ) )
continue;
V_61 . V_18 = V_24 ;
V_61 . V_37 = 0 ;
V_61 . V_39 = V_62 << 16 ;
V_61 . V_40 = 0 ;
F_29 ( V_2 , & V_61 ) ;
}
}
static int F_40 ( struct V_1 * V_2 ,
struct V_36 * V_25 ,
struct V_13 * V_16 ,
struct V_22 * V_11 )
{
T_5 V_63 ;
struct V_64 * V_64 ;
int V_65 , V_66 , V_67 = 0 ;
int V_68 = ( V_25 -> V_26 == V_69 ) ;
unsigned int V_24 , V_70 , V_71 , V_72 ;
unsigned int V_73 = F_41 ( V_25 ) ;
unsigned int V_74 = 0 , V_75 = 0 ;
struct V_76 * V_33 ;
unsigned long V_77 ;
struct V_78 * V_79 ;
V_16 -> V_80 = 0 ;
if ( V_25 -> V_26 == V_27 || ! V_73 )
return 0 ;
F_42 (sc, sg, scsi_sg_count(sc), i)
V_74 += F_43 ( V_33 -> V_81 + V_33 -> V_82 ) ;
if ( V_74 > V_83 ) {
if ( V_74 > V_2 -> V_31 -> V_84 ) {
F_20 ( V_48 , V_2 -> V_31 , V_32
L_4 ) ;
return - V_85 ;
}
V_75 = F_44 ( V_74 ) ;
V_11 -> V_33 = F_45 ( V_74 ,
sizeof( struct V_78 ) , V_86 ) ;
if ( ! V_11 -> V_33 )
return - V_87 ;
}
V_79 = V_11 -> V_33 ? : V_16 -> V_79 ;
V_65 = F_46 ( V_75 + V_74 ,
& V_63 ) ;
if ( V_65 ) {
F_23 ( V_11 -> V_33 ) ;
F_20 ( V_48 , V_2 -> V_31 , V_32
L_5 ) ;
return - V_87 ;
}
if ( V_75 ) {
V_64 = F_47 ( V_79 ) ;
V_70 = ( unsigned long ) V_79 & ~ V_88 ;
V_71 = sizeof( struct V_78 ) * V_74 ;
while ( V_71 > 0 ) {
V_72 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_66 = F_48 ( & V_63 ) ;
F_25 ( V_66 == - V_89 ) ;
V_77 = F_49 ( F_50 ( V_64 ) ) ;
F_51 ( V_66 ,
V_2 -> V_90 -> V_91 , V_77 , 1 ) ;
V_11 -> V_29 [ V_67 ] = V_66 ;
V_16 -> V_79 [ V_67 ] . V_29 = V_66 ;
V_16 -> V_79 [ V_67 ] . V_81 = ( V_19 ) V_70 ;
V_16 -> V_79 [ V_67 ] . V_82 = ( V_19 ) V_72 ;
V_64 ++ ;
V_71 -= V_72 ;
V_70 = 0 ;
V_67 ++ ;
}
F_25 ( V_75 < V_67 ) ;
V_75 = V_67 ;
}
F_42 (sc, sg, scsi_sg_count(sc), i) {
V_64 = F_52 ( V_33 ) ;
V_70 = V_33 -> V_81 ;
V_71 = V_33 -> V_82 ;
while ( V_71 > 0 && V_73 > 0 ) {
V_72 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_72 = F_53 ( V_72 , V_73 ) ;
V_66 = F_48 ( & V_63 ) ;
F_25 ( V_66 == - V_89 ) ;
V_77 = F_49 ( F_50 ( V_64 ) ) ;
F_51 ( V_66 ,
V_2 -> V_90 -> V_91 , V_77 , V_68 ) ;
V_11 -> V_29 [ V_67 ] = V_66 ;
V_79 -> V_29 = V_66 ;
V_79 -> V_81 = ( V_19 ) V_70 ;
V_79 -> V_82 = ( V_19 ) V_72 ;
V_64 ++ ;
V_79 ++ ;
V_71 -= V_72 ;
V_73 -= V_72 ;
V_70 = 0 ;
V_67 ++ ;
}
}
if ( V_75 )
V_16 -> V_80 = V_92 | V_75 ;
else
V_16 -> V_80 = ( T_2 ) V_67 ;
V_11 -> V_28 = V_67 ;
return 0 ;
}
static struct V_13 * F_54 (
struct V_1 * V_2 , struct V_36 * V_25 ,
struct V_22 * V_11 )
{
struct V_13 * V_16 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_16 = F_12 ( V_2 ) ;
if ( ! V_16 )
return NULL ;
V_2 -> V_11 [ V_16 -> V_18 ] = V_11 ;
V_11 -> V_18 = V_16 -> V_18 ;
V_16 -> V_9 = V_25 -> V_93 -> V_9 ;
V_16 -> V_94 = V_25 -> V_93 -> V_94 ;
V_16 -> V_95 = V_25 -> V_93 -> V_95 ;
V_16 -> V_96 = V_25 -> V_96 ;
F_25 ( V_25 -> V_96 > V_97 ) ;
memcpy ( V_16 -> V_98 , V_25 -> V_98 , V_25 -> V_96 ) ;
V_16 -> V_26 = ( T_2 ) V_25 -> V_26 ;
V_16 -> V_99 = V_25 -> V_100 -> V_101 / V_102 ;
return V_16 ;
}
static int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 )
return 1 ;
V_2 -> V_104 ++ ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_104 -- ;
if ( V_2 -> V_104 )
return;
if ( ! V_2 -> V_105 )
return;
V_2 -> V_105 = 0 ;
F_2 ( & V_2 -> V_106 ) ;
}
static int F_57 ( struct V_107 * V_108 ,
struct V_36 * V_25 )
{
struct V_1 * V_2 = F_58 ( V_108 ) ;
struct V_13 * V_16 ;
struct V_22 * V_11 = F_59 ( V_25 ) ;
unsigned long V_5 ;
int V_65 ;
V_19 V_18 ;
F_4 ( V_108 -> V_58 , V_5 ) ;
if ( F_55 ( V_2 ) ) {
F_7 ( V_108 -> V_58 , V_5 ) ;
return V_109 ;
}
if ( F_60 ( & V_2 -> V_15 ) )
goto V_110;
V_16 = F_54 ( V_2 , V_25 , V_11 ) ;
if ( ! V_16 )
goto V_110;
V_25 -> V_38 = 0 ;
V_18 = V_16 -> V_18 ;
V_16 -> V_50 = V_51 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_50 = V_51 ;
V_65 = F_40 ( V_2 , V_25 , V_16 , V_11 ) ;
if ( V_65 < 0 ) {
F_61 ( L_6 , V_111 , V_65 ) ;
F_11 ( V_2 , V_18 ) ;
F_56 ( V_2 ) ;
F_7 ( V_108 -> V_58 , V_5 ) ;
if ( V_65 == - V_87 )
return V_109 ;
V_25 -> V_38 = V_112 << 16 ;
V_25 -> V_43 ( V_25 ) ;
return 0 ;
}
F_14 ( V_2 ) ;
F_56 ( V_2 ) ;
F_7 ( V_108 -> V_58 , V_5 ) ;
return 0 ;
V_110:
F_56 ( V_2 ) ;
F_7 ( V_108 -> V_58 , V_5 ) ;
F_61 ( L_7 , V_111 ) ;
return V_109 ;
}
static int F_62 ( struct V_36 * V_25 , T_2 V_50 )
{
struct V_107 * V_31 = V_25 -> V_93 -> V_31 ;
struct V_1 * V_2 = F_58 ( V_31 ) ;
struct V_22 * V_11 , * V_23 = F_59 ( V_25 ) ;
struct V_13 * V_16 ;
int V_65 = 0 ;
V_11 = F_63 ( sizeof( * V_11 ) , V_113 ) ;
if ( ! V_11 )
return V_114 ;
F_64 ( V_31 -> V_58 ) ;
for (; ; ) {
if ( ! F_60 ( & V_2 -> V_15 ) ) {
V_16 = F_54 ( V_2 , V_25 , V_11 ) ;
if ( V_16 )
break;
}
if ( V_65 || V_2 -> V_103 ) {
F_65 ( V_31 -> V_58 ) ;
F_23 ( V_11 ) ;
return V_114 ;
}
V_2 -> V_3 = 1 ;
F_65 ( V_31 -> V_58 ) ;
V_65 = F_66 ( V_2 -> V_4 ,
! V_2 -> V_3 ) ;
F_64 ( V_31 -> V_58 ) ;
}
if ( F_55 ( V_2 ) ) {
F_65 ( V_31 -> V_58 ) ;
return V_114 ;
}
V_16 -> V_50 = V_50 ;
V_16 -> V_115 = V_23 -> V_18 ;
V_11 -> V_50 = V_50 ;
V_11 -> V_45 = V_46 ;
F_67 ( & V_11 -> V_49 ) ;
V_16 -> V_80 = 0 ;
F_14 ( V_2 ) ;
F_65 ( V_31 -> V_58 ) ;
V_65 = F_66 ( V_11 -> V_49 , V_11 -> V_44 ) ;
F_64 ( V_31 -> V_58 ) ;
if ( ! V_65 ) {
V_65 = V_11 -> V_45 ;
F_11 ( V_2 , V_11 -> V_18 ) ;
F_23 ( V_11 ) ;
} else {
F_68 ( & V_2 -> V_6 ) ;
V_11 -> V_45 = V_47 ;
F_69 ( & V_2 -> V_6 ) ;
V_65 = V_114 ;
}
F_56 ( V_2 ) ;
F_65 ( V_31 -> V_58 ) ;
return V_65 ;
}
static int F_70 ( struct V_36 * V_25 )
{
F_61 ( L_8 , V_111 ) ;
return F_62 ( V_25 , V_116 ) ;
}
static int F_71 ( struct V_36 * V_25 )
{
F_61 ( L_8 , V_111 ) ;
return F_62 ( V_25 , V_117 ) ;
}
static int F_72 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_58 ( V_119 -> V_31 ) ;
if ( V_2 && V_120 == V_2 -> V_121 )
F_73 ( V_122 , V_2 -> V_90 -> V_123 ,
V_2 -> V_124 , L_9 , V_125 ) ;
return 0 ;
}
static void F_74 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_58 ( V_119 -> V_31 ) ;
if ( V_2 && V_120 == V_2 -> V_121 )
F_73 ( V_122 , V_2 -> V_90 -> V_123 ,
V_2 -> V_124 , L_9 , V_126 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_127 * V_90 = V_2 -> V_90 ;
struct V_128 * V_54 ;
T_5 V_29 ;
int V_65 = - V_87 ;
V_54 = (struct V_128 * ) F_76 ( V_129 ) ;
if ( ! V_54 ) {
F_77 ( V_90 , V_65 ,
L_10 ) ;
return V_65 ;
}
F_78 ( V_54 ) ;
F_79 ( & V_2 -> V_15 , V_54 , V_130 ) ;
V_65 = F_80 ( V_90 , V_54 , 1 , & V_29 ) ;
if ( V_65 < 0 ) {
F_81 ( ( unsigned long ) V_54 ) ;
F_77 ( V_90 , V_65 ,
L_11 ) ;
return V_65 ;
}
V_2 -> V_131 = V_29 ;
V_65 = F_82 ( V_90 , & V_2 -> V_132 ) ;
if ( V_65 ) {
F_77 ( V_90 , V_65 , L_12 ) ;
goto V_133;
}
V_65 = F_83 ( V_2 -> V_132 ) ;
if ( V_65 <= 0 ) {
F_77 ( V_90 , V_65 , L_13 ) ;
goto V_133;
}
V_2 -> V_21 = V_65 ;
V_65 = F_84 ( V_2 -> V_21 , NULL , F_37 ,
V_134 , L_14 , V_2 ) ;
if ( V_65 ) {
F_77 ( V_90 , V_65 , L_15 ) ;
goto V_135;
}
return 0 ;
V_135:
F_85 ( V_2 -> V_21 , V_2 ) ;
V_133:
F_22 ( V_2 -> V_131 , 0 ,
( unsigned long ) V_2 -> V_15 . V_54 ) ;
return V_65 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_85 ( V_2 -> V_21 , V_2 ) ;
F_22 ( V_2 -> V_131 , 0 ,
( unsigned long ) V_2 -> V_15 . V_54 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_127 * V_90 = V_2 -> V_90 ;
struct V_136 V_137 ;
int V_65 ;
F_61 ( L_8 , V_111 ) ;
V_65 = F_75 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_61 ( L_16 , V_111 , V_2 -> V_131 , V_2 -> V_132 ) ;
V_138:
V_65 = F_88 ( & V_137 ) ;
if ( V_65 )
F_77 ( V_90 , V_65 , L_17 ) ;
V_65 = F_73 ( V_137 , V_90 -> V_123 , L_18 , L_19 ,
V_2 -> V_131 ) ;
if ( V_65 ) {
F_77 ( V_90 , V_65 , L_20 , L_21 ) ;
goto V_139;
}
V_65 = F_73 ( V_137 , V_90 -> V_123 , L_22 , L_19 ,
V_2 -> V_132 ) ;
if ( V_65 ) {
F_77 ( V_90 , V_65 , L_20 , L_23 ) ;
goto V_139;
}
V_65 = F_89 ( V_137 , 0 ) ;
if ( V_65 ) {
if ( V_65 == - V_140 )
goto V_138;
F_77 ( V_90 , V_65 , L_24 ) ;
goto V_141;
}
return 0 ;
V_139:
F_89 ( V_137 , 1 ) ;
V_141:
F_86 ( V_2 ) ;
return V_65 ;
}
static int F_90 ( struct V_127 * V_90 ,
const struct V_142 * V_9 )
{
struct V_1 * V_2 ;
struct V_107 * V_31 ;
int V_65 = - V_87 ;
char V_143 [ V_144 ] ;
V_31 = F_91 ( & V_145 , sizeof( * V_2 ) ) ;
if ( ! V_31 ) {
F_77 ( V_90 , V_65 , L_25 ) ;
return V_65 ;
}
V_2 = (struct V_1 * ) V_31 -> V_146 ;
F_92 ( & V_90 -> V_90 , V_2 ) ;
V_2 -> V_90 = V_90 ;
F_93 ( V_2 -> V_7 , V_8 ) ;
V_65 = F_87 ( V_2 ) ;
if ( V_65 ) {
F_94 ( V_31 ) ;
return V_65 ;
}
F_67 ( & V_2 -> V_4 ) ;
F_67 ( & V_2 -> V_106 ) ;
F_95 ( & V_2 -> V_6 ) ;
snprintf ( V_143 , V_144 , L_26 , V_31 -> V_147 ) ;
V_31 -> V_148 = V_149 ;
V_31 -> V_150 = 0 ;
V_31 -> V_151 = V_152 ;
V_31 -> V_153 = ( V_31 -> V_84 - 1 ) * V_130 / 512 ;
V_31 -> V_154 = V_97 ;
V_65 = F_96 ( V_31 , & V_90 -> V_90 ) ;
if ( V_65 ) {
F_97 ( & V_90 -> V_90 , L_27 , V_65 ) ;
goto V_141;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_155 = 1 ;
F_98 ( V_90 , V_156 ) ;
return 0 ;
V_141:
F_86 ( V_2 ) ;
F_94 ( V_31 ) ;
return V_65 ;
}
static int F_99 ( struct V_127 * V_90 )
{
struct V_1 * V_2 = F_100 ( & V_90 -> V_90 ) ;
struct V_107 * V_31 = V_2 -> V_31 ;
int V_65 ;
F_64 ( V_31 -> V_58 ) ;
F_39 ( V_2 ) ;
F_65 ( V_31 -> V_58 ) ;
F_86 ( V_2 ) ;
V_65 = F_87 ( V_2 ) ;
if ( V_65 ) {
F_97 ( & V_90 -> V_90 , L_28 , V_65 ) ;
F_94 ( V_31 ) ;
return V_65 ;
}
F_98 ( V_90 , V_156 ) ;
return 0 ;
}
static int F_101 ( struct V_127 * V_90 )
{
struct V_1 * V_2 = F_100 ( & V_90 -> V_90 ) ;
struct V_107 * V_31 = V_2 -> V_31 ;
int V_65 = 0 ;
F_64 ( V_31 -> V_58 ) ;
V_2 -> V_103 = 1 ;
while ( V_2 -> V_104 && ! V_65 ) {
V_2 -> V_105 = 1 ;
V_2 -> V_3 = 0 ;
F_65 ( V_31 -> V_58 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_65 = F_66 ( V_2 -> V_106 ,
! V_2 -> V_105 ) ;
F_64 ( V_31 -> V_58 ) ;
}
F_65 ( V_31 -> V_58 ) ;
return V_65 ;
}
static int F_102 ( struct V_127 * V_90 )
{
struct V_1 * V_2 = F_100 ( & V_90 -> V_90 ) ;
F_61 ( L_29 , V_111 , V_90 -> V_123 ) ;
F_103 ( & V_157 ) ;
if ( V_2 -> V_155 ) {
F_104 ( V_2 -> V_31 ) ;
V_2 -> V_155 = 0 ;
}
F_105 ( & V_157 ) ;
F_86 ( V_2 ) ;
F_94 ( V_2 -> V_31 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_127 * V_90 = V_2 -> V_90 ;
struct V_107 * V_31 = V_2 -> V_31 ;
F_61 ( L_30 , V_111 , V_90 -> V_123 ) ;
F_103 ( & V_157 ) ;
if ( V_2 -> V_155 ) {
F_104 ( V_31 ) ;
V_2 -> V_155 = 0 ;
}
F_105 ( & V_157 ) ;
F_107 ( V_90 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_158 )
{
struct V_127 * V_90 = V_2 -> V_90 ;
int V_24 , V_65 = 0 ;
char V_159 [ 64 ] ;
char * * V_160 ;
unsigned int V_161 = 0 ;
unsigned int V_162 ;
unsigned int V_163 , V_164 , V_165 , V_94 ;
struct V_118 * V_119 ;
V_160 = F_109 ( V_122 , V_90 -> V_166 , L_31 , & V_161 ) ;
if ( F_110 ( V_160 ) )
return;
F_25 ( V_2 -> V_121 ) ;
V_2 -> V_121 = V_120 ;
for ( V_24 = 0 ; V_24 < V_161 ; V_24 ++ ) {
snprintf ( V_159 , sizeof( V_159 ) , L_32 , V_160 [ V_24 ] ) ;
V_65 = F_111 ( V_122 , V_90 -> V_166 , V_159 , L_19 ,
& V_162 ) ;
if ( F_112 ( V_65 ) )
continue;
snprintf ( V_159 , sizeof( V_159 ) , L_33 , V_160 [ V_24 ] ) ;
V_65 = F_111 ( V_122 , V_90 -> V_166 , V_159 ,
L_34 , & V_163 , & V_164 , & V_165 , & V_94 ) ;
if ( F_112 ( V_65 ) )
continue;
snprintf ( V_2 -> V_124 , sizeof( V_2 -> V_124 ) ,
L_32 , V_160 [ V_24 ] ) ;
switch ( V_158 ) {
case V_167 :
if ( V_162 != V_156 )
break;
if ( F_113 ( V_2 -> V_31 , V_164 , V_165 , V_94 ) ) {
F_97 ( & V_90 -> V_90 , L_35 ) ;
F_73 ( V_122 , V_90 -> V_123 ,
V_2 -> V_124 ,
L_9 , V_126 ) ;
}
break;
case V_168 :
if ( V_162 != V_169 )
break;
V_119 = F_114 ( V_2 -> V_31 , V_164 , V_165 , V_94 ) ;
if ( V_119 ) {
F_115 ( V_119 ) ;
F_116 ( V_119 ) ;
}
break;
case V_170 :
if ( V_162 == V_125 )
F_73 ( V_122 , V_90 -> V_123 ,
V_2 -> V_124 ,
L_9 , V_125 ) ;
break;
default:
break;
}
}
V_2 -> V_121 = NULL ;
F_23 ( V_160 ) ;
}
static void F_117 ( struct V_127 * V_90 ,
struct V_1 * V_2 )
{
unsigned int V_171 , V_172 ;
int V_173 ;
struct V_107 * V_31 = V_2 -> V_31 ;
V_173 = F_111 ( V_122 , V_90 -> V_166 , L_36 , L_19 ,
& V_171 ) ;
if ( V_173 != 1 )
V_171 = 0 ;
V_172 = F_27 (unsigned int, sg_grant, SG_ALL) ;
V_172 = F_118 (unsigned int, nr_segs, VSCSIIF_SG_TABLESIZE) ;
V_172 = F_27 (unsigned int, nr_segs,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment)) ;
if ( ! V_2 -> V_103 && V_171 )
F_119 ( & V_90 -> V_90 , L_37 , V_172 ) ;
else if ( V_2 -> V_103 && V_172 < V_31 -> V_84 )
F_120 ( & V_90 -> V_90 ,
L_38 ,
V_31 -> V_84 , V_172 ) ;
V_31 -> V_84 = V_172 ;
V_31 -> V_153 = ( V_172 - 1 ) * V_130 / 512 ;
}
static void F_121 ( struct V_127 * V_90 ,
enum V_174 V_175 )
{
struct V_1 * V_2 = F_100 ( & V_90 -> V_90 ) ;
F_61 ( L_39 , V_111 , V_90 , V_90 -> V_176 , V_175 ) ;
switch ( V_175 ) {
case V_177 :
case V_178 :
case V_179 :
case V_156 :
break;
case V_125 :
F_117 ( V_90 , V_2 ) ;
if ( V_2 -> V_103 ) {
F_108 ( V_2 , V_170 ) ;
F_98 ( V_90 , V_125 ) ;
V_2 -> V_103 = 0 ;
return;
}
if ( F_122 ( V_90 -> V_123 ) ==
V_156 )
F_108 ( V_2 , V_167 ) ;
if ( V_90 -> V_176 != V_125 )
F_98 ( V_90 , V_125 ) ;
break;
case V_126 :
if ( V_90 -> V_176 == V_126 )
break;
case V_169 :
F_106 ( V_2 ) ;
break;
case V_180 :
F_108 ( V_2 , V_168 ) ;
F_98 ( V_90 , V_180 ) ;
break;
case V_181 :
F_108 ( V_2 , V_167 ) ;
F_98 ( V_90 , V_125 ) ;
break;
}
}
static int T_6 F_123 ( void )
{
if ( ! F_124 () )
return - V_182 ;
return F_125 ( & V_183 ) ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_183 ) ;
}
