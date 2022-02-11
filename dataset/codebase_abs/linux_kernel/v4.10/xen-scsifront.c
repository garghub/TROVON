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
static int F_12 ( struct V_1 * V_2 ,
struct V_13 * V_11 )
{
struct V_14 * V_15 = & ( V_2 -> V_15 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 = V_11 -> V_19 ;
T_1 V_9 ;
int V_20 , V_21 ;
if ( F_13 ( & V_2 -> V_15 ) )
return - V_22 ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 >= V_8 )
return - V_22 ;
V_2 -> V_11 [ V_9 ] = V_11 ;
V_11 -> V_23 = V_9 ;
V_17 = F_14 ( & ( V_2 -> V_15 ) , V_15 -> V_24 ) ;
V_15 -> V_24 ++ ;
V_17 -> V_23 = V_9 ;
V_17 -> V_25 = V_11 -> V_25 ;
V_17 -> V_26 = V_11 -> V_26 ;
V_17 -> V_27 = V_11 -> V_27 ;
V_17 -> V_9 = V_19 -> V_28 -> V_9 ;
V_17 -> V_29 = V_19 -> V_28 -> V_29 ;
V_17 -> V_30 = V_19 -> V_28 -> V_30 ;
V_17 -> V_31 = V_19 -> V_31 ;
F_15 ( V_19 -> V_31 > V_32 ) ;
memcpy ( V_17 -> V_33 , V_19 -> V_33 , V_19 -> V_31 ) ;
V_17 -> V_34 = ( V_35 ) V_19 -> V_34 ;
V_17 -> V_36 = V_19 -> V_37 -> V_38 / V_39 ;
for ( V_20 = 0 ; V_20 < ( V_11 -> V_27 & ~ V_40 ) ; V_20 ++ )
V_17 -> V_41 [ V_20 ] = V_11 -> V_41 [ V_20 ] ;
F_16 ( V_15 , V_21 ) ;
if ( V_21 )
F_17 ( V_2 -> V_42 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_11 )
{
int V_20 ;
if ( V_11 -> V_19 -> V_34 == V_43 )
return;
for ( V_20 = 0 ; V_20 < V_11 -> V_44 ; V_20 ++ ) {
if ( F_19 ( F_20 ( V_11 -> V_45 [ V_20 ] ) ) ) {
F_21 ( V_46 , V_2 -> V_47 , V_48
L_1 ) ;
F_22 () ;
}
F_23 ( V_11 -> V_45 [ V_20 ] , 0 , 0UL ) ;
}
F_24 ( V_11 -> V_49 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_13 * V_11 ;
struct V_18 * V_19 ;
T_1 V_9 ;
V_35 V_52 ;
V_9 = V_51 -> V_23 ;
V_11 = V_2 -> V_11 [ V_9 ] ;
V_19 = V_11 -> V_19 ;
F_15 ( V_19 == NULL ) ;
F_18 ( V_2 , V_11 ) ;
F_11 ( V_2 , V_9 ) ;
V_19 -> V_53 = V_51 -> V_54 ;
F_26 ( V_19 , V_51 -> V_55 ) ;
V_52 = F_27 ( V_35 , V_56 ,
V_51 -> V_52 ) ;
if ( V_52 )
memcpy ( V_19 -> V_57 , V_51 -> V_57 , V_52 ) ;
V_19 -> V_58 ( V_19 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
T_2 V_9 = V_51 -> V_23 ;
unsigned long V_5 ;
struct V_13 * V_11 = V_2 -> V_11 [ V_9 ] ;
int V_12 ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
V_11 -> V_59 = 1 ;
switch ( V_11 -> V_60 ) {
case V_61 :
V_11 -> V_60 = V_51 -> V_54 ;
break;
case V_62 :
V_12 = F_8 ( V_2 , V_9 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
F_24 ( V_11 ) ;
if ( V_12 )
F_1 ( V_2 ) ;
return;
default:
F_21 ( V_63 , V_2 -> V_47 , V_48
L_2 ,
V_11 -> V_60 , V_9 ) ;
break;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
F_2 ( & V_11 -> V_64 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
if ( F_30 ( V_51 -> V_23 >= V_8 ||
F_31 ( V_51 -> V_23 , V_2 -> V_7 ) ,
L_3 , V_51 -> V_23 ) )
return;
if ( V_2 -> V_11 [ V_51 -> V_23 ] -> V_25 == V_65 )
F_25 ( V_2 , V_51 ) ;
else
F_28 ( V_2 , V_51 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
T_3 V_20 , V_66 ;
int V_67 = 0 ;
V_66 = V_2 -> V_15 . V_68 -> V_69 ;
F_33 () ;
for ( V_20 = V_2 -> V_15 . V_70 ; V_20 != V_66 ; V_20 ++ ) {
V_51 = F_34 ( & V_2 -> V_15 , V_20 ) ;
F_29 ( V_2 , V_51 ) ;
}
V_2 -> V_15 . V_70 = V_20 ;
if ( V_20 != V_2 -> V_15 . V_24 )
F_35 ( & V_2 -> V_15 , V_67 ) ;
else
V_2 -> V_15 . V_68 -> V_71 = V_20 + 1 ;
return V_67 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_67 ;
unsigned long V_5 ;
F_4 ( V_2 -> V_47 -> V_72 , V_5 ) ;
V_67 = F_32 ( V_2 ) ;
V_2 -> V_3 = 0 ;
F_7 ( V_2 -> V_47 -> V_72 , V_5 ) ;
F_2 ( & V_2 -> V_4 ) ;
return V_67 ;
}
static T_4 F_37 ( int V_42 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
while ( F_36 ( V_2 ) )
F_38 () ;
return V_74 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned V_20 ;
struct V_50 V_75 ;
F_32 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < V_8 ; V_20 ++ ) {
if ( F_31 ( V_20 , V_2 -> V_7 ) )
continue;
V_75 . V_23 = V_20 ;
V_75 . V_52 = 0 ;
V_75 . V_54 = V_76 << 16 ;
V_75 . V_55 = 0 ;
F_29 ( V_2 , & V_75 ) ;
}
}
static int F_40 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_13 * V_11 )
{
T_5 V_77 ;
struct V_78 * V_78 ;
int V_79 , V_80 , V_81 = 0 ;
int V_82 = ( V_19 -> V_34 == V_83 ) ;
unsigned int V_20 , V_84 , V_85 , V_86 ;
unsigned int V_87 = F_41 ( V_19 ) ;
unsigned int V_88 = 0 , V_89 = 0 ;
struct V_90 * V_49 ;
struct V_91 * V_41 ;
if ( V_19 -> V_34 == V_43 || ! V_87 )
return 0 ;
F_42 (sc, sg, scsi_sg_count(sc), i)
V_88 += F_43 ( V_49 -> V_92 + V_49 -> V_93 ) ;
if ( V_88 > V_94 ) {
if ( V_88 > V_2 -> V_47 -> V_95 ) {
F_21 ( V_63 , V_2 -> V_47 , V_48
L_4 ) ;
return - V_96 ;
}
V_89 = F_44 ( V_88 ) ;
V_11 -> V_49 = F_45 ( V_88 ,
sizeof( struct V_91 ) , V_97 ) ;
if ( ! V_11 -> V_49 )
return - V_98 ;
}
V_41 = V_11 -> V_49 ? : V_11 -> V_41 ;
V_79 = F_46 ( V_89 + V_88 ,
& V_77 ) ;
if ( V_79 ) {
F_24 ( V_11 -> V_49 ) ;
F_21 ( V_63 , V_2 -> V_47 , V_48
L_5 ) ;
return - V_98 ;
}
if ( V_89 ) {
V_78 = F_47 ( V_41 ) ;
V_84 = ( unsigned long ) V_41 & ~ V_99 ;
V_85 = sizeof( struct V_91 ) * V_88 ;
while ( V_85 > 0 ) {
V_86 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_80 = F_48 ( & V_77 ) ;
F_15 ( V_80 == - V_100 ) ;
F_49 ( V_80 ,
V_2 -> V_101 -> V_102 ,
F_50 ( V_78 ) , 1 ) ;
V_11 -> V_45 [ V_81 ] = V_80 ;
V_11 -> V_41 [ V_81 ] . V_45 = V_80 ;
V_11 -> V_41 [ V_81 ] . V_92 = ( T_2 ) V_84 ;
V_11 -> V_41 [ V_81 ] . V_93 = ( T_2 ) V_86 ;
V_78 ++ ;
V_85 -= V_86 ;
V_84 = 0 ;
V_81 ++ ;
}
F_15 ( V_89 < V_81 ) ;
V_89 = V_81 ;
}
F_42 (sc, sg, scsi_sg_count(sc), i) {
V_78 = F_51 ( V_49 ) ;
V_84 = V_49 -> V_92 ;
V_85 = V_49 -> V_93 ;
while ( V_85 > 0 && V_87 > 0 ) {
V_86 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_86 = F_52 ( V_86 , V_87 ) ;
V_80 = F_48 ( & V_77 ) ;
F_15 ( V_80 == - V_100 ) ;
F_49 ( V_80 ,
V_2 -> V_101 -> V_102 ,
F_50 ( V_78 ) ,
V_82 ) ;
V_11 -> V_45 [ V_81 ] = V_80 ;
V_41 -> V_45 = V_80 ;
V_41 -> V_92 = ( T_2 ) V_84 ;
V_41 -> V_93 = ( T_2 ) V_86 ;
V_78 ++ ;
V_41 ++ ;
V_85 -= V_86 ;
V_87 -= V_86 ;
V_84 = 0 ;
V_81 ++ ;
}
}
if ( V_89 )
V_11 -> V_27 = V_40 | V_89 ;
else
V_11 -> V_27 = ( V_35 ) V_81 ;
V_11 -> V_44 = V_81 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 )
return 1 ;
V_2 -> V_104 ++ ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_104 -- ;
if ( V_2 -> V_104 )
return;
if ( ! V_2 -> V_105 )
return;
V_2 -> V_105 = 0 ;
F_2 ( & V_2 -> V_106 ) ;
}
static int F_55 ( struct V_107 * V_108 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_56 ( V_108 ) ;
struct V_13 * V_11 = F_57 ( V_19 ) ;
unsigned long V_5 ;
int V_79 ;
V_19 -> V_53 = 0 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_19 = V_19 ;
V_11 -> V_25 = V_65 ;
F_4 ( V_108 -> V_72 , V_5 ) ;
if ( F_53 ( V_2 ) ) {
F_7 ( V_108 -> V_72 , V_5 ) ;
return V_109 ;
}
V_79 = F_40 ( V_2 , V_19 , V_11 ) ;
if ( V_79 < 0 ) {
F_58 ( L_6 , V_110 , V_79 ) ;
F_54 ( V_2 ) ;
F_7 ( V_108 -> V_72 , V_5 ) ;
if ( V_79 == - V_98 )
return V_109 ;
V_19 -> V_53 = V_111 << 16 ;
V_19 -> V_58 ( V_19 ) ;
return 0 ;
}
if ( F_12 ( V_2 , V_11 ) ) {
F_18 ( V_2 , V_11 ) ;
goto V_112;
}
F_54 ( V_2 ) ;
F_7 ( V_108 -> V_72 , V_5 ) ;
return 0 ;
V_112:
F_54 ( V_2 ) ;
F_7 ( V_108 -> V_72 , V_5 ) ;
F_58 ( L_7 , V_110 ) ;
return V_109 ;
}
static int F_59 ( struct V_18 * V_19 , V_35 V_25 )
{
struct V_107 * V_47 = V_19 -> V_28 -> V_47 ;
struct V_1 * V_2 = F_56 ( V_47 ) ;
struct V_13 * V_11 , * V_113 = F_57 ( V_19 ) ;
int V_79 = 0 ;
V_11 = F_60 ( sizeof( * V_11 ) , V_114 ) ;
if ( ! V_11 )
return V_115 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_60 = V_61 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_26 = V_113 -> V_23 ;
F_61 ( & V_11 -> V_64 ) ;
F_62 ( V_47 -> V_72 ) ;
for (; ; ) {
if ( F_53 ( V_2 ) )
goto V_116;
if ( ! F_12 ( V_2 , V_11 ) )
break;
F_54 ( V_2 ) ;
if ( V_79 )
goto V_116;
V_2 -> V_3 = 1 ;
F_63 ( V_47 -> V_72 ) ;
V_79 = F_64 ( V_2 -> V_4 ,
! V_2 -> V_3 ) ;
F_62 ( V_47 -> V_72 ) ;
}
F_63 ( V_47 -> V_72 ) ;
V_79 = F_64 ( V_11 -> V_64 , V_11 -> V_59 ) ;
F_62 ( V_47 -> V_72 ) ;
if ( ! V_79 ) {
V_79 = V_11 -> V_60 ;
F_11 ( V_2 , V_11 -> V_23 ) ;
F_24 ( V_11 ) ;
} else {
F_65 ( & V_2 -> V_6 ) ;
V_11 -> V_60 = V_62 ;
F_66 ( & V_2 -> V_6 ) ;
V_79 = V_115 ;
}
F_54 ( V_2 ) ;
F_63 ( V_47 -> V_72 ) ;
return V_79 ;
V_116:
F_63 ( V_47 -> V_72 ) ;
F_24 ( V_11 ) ;
return V_115 ;
}
static int F_67 ( struct V_18 * V_19 )
{
F_58 ( L_8 , V_110 ) ;
return F_59 ( V_19 , V_117 ) ;
}
static int F_68 ( struct V_18 * V_19 )
{
F_58 ( L_8 , V_110 ) ;
return F_59 ( V_19 , V_118 ) ;
}
static int F_69 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_56 ( V_120 -> V_47 ) ;
if ( V_2 && V_121 == V_2 -> V_122 )
F_70 ( V_123 , V_2 -> V_101 -> V_124 ,
V_2 -> V_125 , L_9 , V_126 ) ;
return 0 ;
}
static void F_71 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_56 ( V_120 -> V_47 ) ;
if ( V_2 && V_121 == V_2 -> V_122 )
F_70 ( V_123 , V_2 -> V_101 -> V_124 ,
V_2 -> V_125 , L_9 , V_127 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_128 * V_101 = V_2 -> V_101 ;
struct V_129 * V_68 ;
T_5 V_45 ;
int V_79 = - V_98 ;
V_68 = (struct V_129 * ) F_73 ( V_130 ) ;
if ( ! V_68 ) {
F_74 ( V_101 , V_79 ,
L_10 ) ;
return V_79 ;
}
F_75 ( V_68 ) ;
F_76 ( & V_2 -> V_15 , V_68 , V_131 ) ;
V_79 = F_77 ( V_101 , V_68 , 1 , & V_45 ) ;
if ( V_79 < 0 ) {
F_78 ( ( unsigned long ) V_68 ) ;
F_74 ( V_101 , V_79 ,
L_11 ) ;
return V_79 ;
}
V_2 -> V_132 = V_45 ;
V_79 = F_79 ( V_101 , & V_2 -> V_133 ) ;
if ( V_79 ) {
F_74 ( V_101 , V_79 , L_12 ) ;
goto V_134;
}
V_79 = F_80 ( V_2 -> V_133 ) ;
if ( V_79 <= 0 ) {
F_74 ( V_101 , V_79 , L_13 ) ;
goto V_134;
}
V_2 -> V_42 = V_79 ;
V_79 = F_81 ( V_2 -> V_42 , NULL , F_37 ,
V_135 , L_14 , V_2 ) ;
if ( V_79 ) {
F_74 ( V_101 , V_79 , L_15 ) ;
goto V_136;
}
return 0 ;
V_136:
F_82 ( V_2 -> V_42 , V_2 ) ;
V_134:
F_23 ( V_2 -> V_132 , 0 ,
( unsigned long ) V_2 -> V_15 . V_68 ) ;
return V_79 ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_82 ( V_2 -> V_42 , V_2 ) ;
F_23 ( V_2 -> V_132 , 0 ,
( unsigned long ) V_2 -> V_15 . V_68 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_128 * V_101 = V_2 -> V_101 ;
struct V_137 V_138 ;
int V_79 ;
F_58 ( L_8 , V_110 ) ;
V_79 = F_72 ( V_2 ) ;
if ( V_79 )
return V_79 ;
F_58 ( L_16 , V_110 , V_2 -> V_132 , V_2 -> V_133 ) ;
V_139:
V_79 = F_85 ( & V_138 ) ;
if ( V_79 )
F_74 ( V_101 , V_79 , L_17 ) ;
V_79 = F_70 ( V_138 , V_101 -> V_124 , L_18 , L_19 ,
V_2 -> V_132 ) ;
if ( V_79 ) {
F_74 ( V_101 , V_79 , L_20 , L_21 ) ;
goto V_116;
}
V_79 = F_70 ( V_138 , V_101 -> V_124 , L_22 , L_19 ,
V_2 -> V_133 ) ;
if ( V_79 ) {
F_74 ( V_101 , V_79 , L_20 , L_23 ) ;
goto V_116;
}
V_79 = F_86 ( V_138 , 0 ) ;
if ( V_79 ) {
if ( V_79 == - V_140 )
goto V_139;
F_74 ( V_101 , V_79 , L_24 ) ;
goto V_141;
}
return 0 ;
V_116:
F_86 ( V_138 , 1 ) ;
V_141:
F_83 ( V_2 ) ;
return V_79 ;
}
static int F_87 ( struct V_128 * V_101 ,
const struct V_142 * V_9 )
{
struct V_1 * V_2 ;
struct V_107 * V_47 ;
int V_79 = - V_98 ;
char V_143 [ V_144 ] ;
V_47 = F_88 ( & V_145 , sizeof( * V_2 ) ) ;
if ( ! V_47 ) {
F_74 ( V_101 , V_79 , L_25 ) ;
return V_79 ;
}
V_2 = (struct V_1 * ) V_47 -> V_146 ;
F_89 ( & V_101 -> V_101 , V_2 ) ;
V_2 -> V_101 = V_101 ;
F_90 ( V_2 -> V_7 , V_8 ) ;
V_79 = F_84 ( V_2 ) ;
if ( V_79 ) {
F_91 ( V_47 ) ;
return V_79 ;
}
F_61 ( & V_2 -> V_4 ) ;
F_61 ( & V_2 -> V_106 ) ;
F_92 ( & V_2 -> V_6 ) ;
snprintf ( V_143 , V_144 , L_26 , V_47 -> V_147 ) ;
V_47 -> V_148 = V_149 ;
V_47 -> V_150 = 0 ;
V_47 -> V_151 = V_152 ;
V_47 -> V_153 = ( V_47 -> V_95 - 1 ) * V_131 / 512 ;
V_47 -> V_154 = V_32 ;
V_79 = F_93 ( V_47 , & V_101 -> V_101 ) ;
if ( V_79 ) {
F_94 ( & V_101 -> V_101 , L_27 , V_79 ) ;
goto V_141;
}
V_2 -> V_47 = V_47 ;
V_2 -> V_155 = 1 ;
F_95 ( V_101 , V_156 ) ;
return 0 ;
V_141:
F_83 ( V_2 ) ;
F_91 ( V_47 ) ;
return V_79 ;
}
static int F_96 ( struct V_128 * V_101 )
{
struct V_1 * V_2 = F_97 ( & V_101 -> V_101 ) ;
struct V_107 * V_47 = V_2 -> V_47 ;
int V_79 ;
F_62 ( V_47 -> V_72 ) ;
F_39 ( V_2 ) ;
F_63 ( V_47 -> V_72 ) ;
F_83 ( V_2 ) ;
V_79 = F_84 ( V_2 ) ;
if ( V_79 ) {
F_94 ( & V_101 -> V_101 , L_28 , V_79 ) ;
F_91 ( V_47 ) ;
return V_79 ;
}
F_95 ( V_101 , V_156 ) ;
return 0 ;
}
static int F_98 ( struct V_128 * V_101 )
{
struct V_1 * V_2 = F_97 ( & V_101 -> V_101 ) ;
struct V_107 * V_47 = V_2 -> V_47 ;
int V_79 = 0 ;
F_62 ( V_47 -> V_72 ) ;
V_2 -> V_103 = 1 ;
while ( V_2 -> V_104 && ! V_79 ) {
V_2 -> V_105 = 1 ;
V_2 -> V_3 = 0 ;
F_63 ( V_47 -> V_72 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_79 = F_64 ( V_2 -> V_106 ,
! V_2 -> V_105 ) ;
F_62 ( V_47 -> V_72 ) ;
}
F_63 ( V_47 -> V_72 ) ;
return V_79 ;
}
static int F_99 ( struct V_128 * V_101 )
{
struct V_1 * V_2 = F_97 ( & V_101 -> V_101 ) ;
F_58 ( L_29 , V_110 , V_101 -> V_124 ) ;
F_100 ( & V_157 ) ;
if ( V_2 -> V_155 ) {
F_101 ( V_2 -> V_47 ) ;
V_2 -> V_155 = 0 ;
}
F_102 ( & V_157 ) ;
F_83 ( V_2 ) ;
F_91 ( V_2 -> V_47 ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_128 * V_101 = V_2 -> V_101 ;
struct V_107 * V_47 = V_2 -> V_47 ;
F_58 ( L_30 , V_110 , V_101 -> V_124 ) ;
F_100 ( & V_157 ) ;
if ( V_2 -> V_155 ) {
F_101 ( V_47 ) ;
V_2 -> V_155 = 0 ;
}
F_102 ( & V_157 ) ;
F_104 ( V_101 ) ;
}
static void F_105 ( struct V_1 * V_2 , int V_158 )
{
struct V_128 * V_101 = V_2 -> V_101 ;
int V_20 , V_79 = 0 ;
char V_159 [ 64 ] ;
char * * V_160 ;
unsigned int V_161 = 0 ;
unsigned int V_162 ;
unsigned int V_163 , V_164 , V_165 , V_29 ;
struct V_119 * V_120 ;
V_160 = F_106 ( V_123 , V_101 -> V_166 , L_31 , & V_161 ) ;
if ( F_107 ( V_160 ) )
return;
F_15 ( V_2 -> V_122 ) ;
V_2 -> V_122 = V_121 ;
for ( V_20 = 0 ; V_20 < V_161 ; V_20 ++ ) {
snprintf ( V_159 , sizeof( V_159 ) , L_32 , V_160 [ V_20 ] ) ;
V_79 = F_108 ( V_123 , V_101 -> V_166 , V_159 , L_19 ,
& V_162 ) ;
if ( F_109 ( V_79 ) )
continue;
snprintf ( V_159 , sizeof( V_159 ) , L_33 , V_160 [ V_20 ] ) ;
V_79 = F_108 ( V_123 , V_101 -> V_166 , V_159 ,
L_34 , & V_163 , & V_164 , & V_165 , & V_29 ) ;
if ( F_109 ( V_79 ) )
continue;
snprintf ( V_2 -> V_125 , sizeof( V_2 -> V_125 ) ,
L_32 , V_160 [ V_20 ] ) ;
switch ( V_158 ) {
case V_167 :
if ( V_162 != V_156 )
break;
if ( F_110 ( V_2 -> V_47 , V_164 , V_165 , V_29 ) ) {
F_94 ( & V_101 -> V_101 , L_35 ) ;
F_70 ( V_123 , V_101 -> V_124 ,
V_2 -> V_125 ,
L_9 , V_127 ) ;
}
break;
case V_168 :
if ( V_162 != V_169 )
break;
V_120 = F_111 ( V_2 -> V_47 , V_164 , V_165 , V_29 ) ;
if ( V_120 ) {
F_112 ( V_120 ) ;
F_113 ( V_120 ) ;
}
break;
case V_170 :
if ( V_162 == V_126 )
F_70 ( V_123 , V_101 -> V_124 ,
V_2 -> V_125 ,
L_9 , V_126 ) ;
break;
default:
break;
}
}
V_2 -> V_122 = NULL ;
F_24 ( V_160 ) ;
}
static void F_114 ( struct V_128 * V_101 ,
struct V_1 * V_2 )
{
unsigned int V_171 , V_172 ;
struct V_107 * V_47 = V_2 -> V_47 ;
V_171 = F_115 ( V_101 -> V_166 , L_36 , 0 ) ;
V_172 = F_27 (unsigned int, sg_grant, SG_ALL) ;
V_172 = F_116 (unsigned int, nr_segs, VSCSIIF_SG_TABLESIZE) ;
V_172 = F_27 (unsigned int, nr_segs,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment)) ;
if ( ! V_2 -> V_103 && V_171 )
F_117 ( & V_101 -> V_101 , L_37 , V_172 ) ;
else if ( V_2 -> V_103 && V_172 < V_47 -> V_95 )
F_118 ( & V_101 -> V_101 ,
L_38 ,
V_47 -> V_95 , V_172 ) ;
V_47 -> V_95 = V_172 ;
V_47 -> V_153 = ( V_172 - 1 ) * V_131 / 512 ;
}
static void F_119 ( struct V_128 * V_101 ,
enum V_173 V_174 )
{
struct V_1 * V_2 = F_97 ( & V_101 -> V_101 ) ;
F_58 ( L_39 , V_110 , V_101 , V_101 -> V_175 , V_174 ) ;
switch ( V_174 ) {
case V_176 :
case V_177 :
case V_178 :
case V_156 :
break;
case V_126 :
F_114 ( V_101 , V_2 ) ;
if ( V_2 -> V_103 ) {
F_105 ( V_2 , V_170 ) ;
F_95 ( V_101 , V_126 ) ;
V_2 -> V_103 = 0 ;
return;
}
if ( F_120 ( V_101 -> V_124 ) ==
V_156 )
F_105 ( V_2 , V_167 ) ;
if ( V_101 -> V_175 != V_126 )
F_95 ( V_101 , V_126 ) ;
break;
case V_127 :
if ( V_101 -> V_175 == V_127 )
break;
case V_169 :
F_103 ( V_2 ) ;
break;
case V_179 :
F_105 ( V_2 , V_168 ) ;
F_95 ( V_101 , V_179 ) ;
break;
case V_180 :
F_105 ( V_2 , V_167 ) ;
F_95 ( V_101 , V_126 ) ;
break;
}
}
static int T_6 F_121 ( void )
{
if ( ! F_122 () )
return - V_181 ;
return F_123 ( & V_182 ) ;
}
static void T_7 F_124 ( void )
{
F_125 ( & V_182 ) ;
}
