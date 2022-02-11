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
V_84 = F_48 ( V_41 ) ;
V_85 = sizeof( struct V_91 ) * V_88 ;
while ( V_85 > 0 ) {
V_86 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_80 = F_49 ( & V_77 ) ;
F_15 ( V_80 == - V_99 ) ;
F_50 ( V_80 ,
V_2 -> V_100 -> V_101 ,
F_51 ( V_78 ) , 1 ) ;
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
V_78 = F_52 ( V_49 ) ;
V_84 = V_49 -> V_92 ;
V_85 = V_49 -> V_93 ;
while ( V_85 > 0 && V_87 > 0 ) {
V_86 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_86 = F_53 ( V_86 , V_87 ) ;
V_80 = F_49 ( & V_77 ) ;
F_15 ( V_80 == - V_99 ) ;
F_50 ( V_80 ,
V_2 -> V_100 -> V_101 ,
F_51 ( V_78 ) ,
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
static int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_102 )
return 1 ;
V_2 -> V_103 ++ ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_103 -- ;
if ( V_2 -> V_103 )
return;
if ( ! V_2 -> V_104 )
return;
V_2 -> V_104 = 0 ;
F_2 ( & V_2 -> V_105 ) ;
}
static int F_56 ( struct V_106 * V_107 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_57 ( V_107 ) ;
struct V_13 * V_11 = F_58 ( V_19 ) ;
unsigned long V_5 ;
int V_79 ;
V_19 -> V_53 = 0 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_25 = V_65 ;
F_4 ( V_107 -> V_72 , V_5 ) ;
if ( F_54 ( V_2 ) ) {
F_7 ( V_107 -> V_72 , V_5 ) ;
return V_108 ;
}
V_79 = F_40 ( V_2 , V_19 , V_11 ) ;
if ( V_79 < 0 ) {
F_59 ( L_6 , V_109 , V_79 ) ;
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_72 , V_5 ) ;
if ( V_79 == - V_98 )
return V_108 ;
V_19 -> V_53 = V_110 << 16 ;
V_19 -> V_58 ( V_19 ) ;
return 0 ;
}
if ( F_12 ( V_2 , V_11 ) ) {
F_18 ( V_2 , V_11 ) ;
goto V_111;
}
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_72 , V_5 ) ;
return 0 ;
V_111:
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_72 , V_5 ) ;
F_59 ( L_7 , V_109 ) ;
return V_108 ;
}
static int F_60 ( struct V_18 * V_19 , V_35 V_25 )
{
struct V_106 * V_47 = V_19 -> V_28 -> V_47 ;
struct V_1 * V_2 = F_57 ( V_47 ) ;
struct V_13 * V_11 , * V_112 = F_58 ( V_19 ) ;
int V_79 = 0 ;
V_11 = F_61 ( sizeof( * V_11 ) , V_113 ) ;
if ( ! V_11 )
return V_114 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_60 = V_61 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_26 = V_112 -> V_23 ;
F_62 ( & V_11 -> V_64 ) ;
F_63 ( V_47 -> V_72 ) ;
for (; ; ) {
if ( F_54 ( V_2 ) )
goto V_115;
if ( ! F_12 ( V_2 , V_11 ) )
break;
F_55 ( V_2 ) ;
if ( V_79 )
goto V_115;
V_2 -> V_3 = 1 ;
F_64 ( V_47 -> V_72 ) ;
V_79 = F_65 ( V_2 -> V_4 ,
! V_2 -> V_3 ) ;
F_63 ( V_47 -> V_72 ) ;
}
F_64 ( V_47 -> V_72 ) ;
V_79 = F_65 ( V_11 -> V_64 , V_11 -> V_59 ) ;
F_63 ( V_47 -> V_72 ) ;
if ( ! V_79 ) {
V_79 = V_11 -> V_60 ;
F_11 ( V_2 , V_11 -> V_23 ) ;
F_24 ( V_11 ) ;
} else {
F_66 ( & V_2 -> V_6 ) ;
V_11 -> V_60 = V_62 ;
F_67 ( & V_2 -> V_6 ) ;
V_79 = V_114 ;
}
F_55 ( V_2 ) ;
F_64 ( V_47 -> V_72 ) ;
return V_79 ;
V_115:
F_64 ( V_47 -> V_72 ) ;
F_24 ( V_11 ) ;
return V_114 ;
}
static int F_68 ( struct V_18 * V_19 )
{
F_59 ( L_8 , V_109 ) ;
return F_60 ( V_19 , V_116 ) ;
}
static int F_69 ( struct V_18 * V_19 )
{
F_59 ( L_8 , V_109 ) ;
return F_60 ( V_19 , V_117 ) ;
}
static int F_70 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_57 ( V_119 -> V_47 ) ;
if ( V_2 && V_120 == V_2 -> V_121 )
F_71 ( V_122 , V_2 -> V_100 -> V_123 ,
V_2 -> V_124 , L_9 , V_125 ) ;
return 0 ;
}
static void F_72 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_57 ( V_119 -> V_47 ) ;
if ( V_2 && V_120 == V_2 -> V_121 )
F_71 ( V_122 , V_2 -> V_100 -> V_123 ,
V_2 -> V_124 , L_9 , V_126 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_127 * V_100 = V_2 -> V_100 ;
struct V_128 * V_68 ;
T_5 V_45 ;
int V_79 = - V_98 ;
V_68 = (struct V_128 * ) F_74 ( V_129 ) ;
if ( ! V_68 ) {
F_75 ( V_100 , V_79 ,
L_10 ) ;
return V_79 ;
}
F_76 ( V_68 ) ;
F_77 ( & V_2 -> V_15 , V_68 , V_130 ) ;
V_79 = F_78 ( V_100 , V_68 , 1 , & V_45 ) ;
if ( V_79 < 0 ) {
F_79 ( ( unsigned long ) V_68 ) ;
F_75 ( V_100 , V_79 ,
L_11 ) ;
return V_79 ;
}
V_2 -> V_131 = V_45 ;
V_79 = F_80 ( V_100 , & V_2 -> V_132 ) ;
if ( V_79 ) {
F_75 ( V_100 , V_79 , L_12 ) ;
goto V_133;
}
V_79 = F_81 ( V_2 -> V_132 ) ;
if ( V_79 <= 0 ) {
F_75 ( V_100 , V_79 , L_13 ) ;
goto V_133;
}
V_2 -> V_42 = V_79 ;
V_79 = F_82 ( V_2 -> V_42 , NULL , F_37 ,
V_134 , L_14 , V_2 ) ;
if ( V_79 ) {
F_75 ( V_100 , V_79 , L_15 ) ;
goto V_135;
}
return 0 ;
V_135:
F_83 ( V_2 -> V_42 , V_2 ) ;
V_133:
F_23 ( V_2 -> V_131 , 0 ,
( unsigned long ) V_2 -> V_15 . V_68 ) ;
return V_79 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_83 ( V_2 -> V_42 , V_2 ) ;
F_23 ( V_2 -> V_131 , 0 ,
( unsigned long ) V_2 -> V_15 . V_68 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_127 * V_100 = V_2 -> V_100 ;
struct V_136 V_137 ;
int V_79 ;
F_59 ( L_8 , V_109 ) ;
V_79 = F_73 ( V_2 ) ;
if ( V_79 )
return V_79 ;
F_59 ( L_16 , V_109 , V_2 -> V_131 , V_2 -> V_132 ) ;
V_138:
V_79 = F_86 ( & V_137 ) ;
if ( V_79 )
F_75 ( V_100 , V_79 , L_17 ) ;
V_79 = F_71 ( V_137 , V_100 -> V_123 , L_18 , L_19 ,
V_2 -> V_131 ) ;
if ( V_79 ) {
F_75 ( V_100 , V_79 , L_20 , L_21 ) ;
goto V_115;
}
V_79 = F_71 ( V_137 , V_100 -> V_123 , L_22 , L_19 ,
V_2 -> V_132 ) ;
if ( V_79 ) {
F_75 ( V_100 , V_79 , L_20 , L_23 ) ;
goto V_115;
}
V_79 = F_87 ( V_137 , 0 ) ;
if ( V_79 ) {
if ( V_79 == - V_139 )
goto V_138;
F_75 ( V_100 , V_79 , L_24 ) ;
goto V_140;
}
return 0 ;
V_115:
F_87 ( V_137 , 1 ) ;
V_140:
F_84 ( V_2 ) ;
return V_79 ;
}
static int F_88 ( struct V_127 * V_100 ,
const struct V_141 * V_9 )
{
struct V_1 * V_2 ;
struct V_106 * V_47 ;
int V_79 = - V_98 ;
char V_142 [ V_143 ] ;
V_47 = F_89 ( & V_144 , sizeof( * V_2 ) ) ;
if ( ! V_47 ) {
F_75 ( V_100 , V_79 , L_25 ) ;
return V_79 ;
}
V_2 = (struct V_1 * ) V_47 -> V_145 ;
F_90 ( & V_100 -> V_100 , V_2 ) ;
V_2 -> V_100 = V_100 ;
F_91 ( V_2 -> V_7 , V_8 ) ;
V_79 = F_85 ( V_2 ) ;
if ( V_79 ) {
F_92 ( V_47 ) ;
return V_79 ;
}
F_62 ( & V_2 -> V_4 ) ;
F_62 ( & V_2 -> V_105 ) ;
F_93 ( & V_2 -> V_6 ) ;
snprintf ( V_142 , V_143 , L_26 , V_47 -> V_146 ) ;
V_47 -> V_147 = V_148 ;
V_47 -> V_149 = 0 ;
V_47 -> V_150 = V_151 ;
V_47 -> V_152 = ( V_47 -> V_95 - 1 ) * V_130 / 512 ;
V_47 -> V_153 = V_32 ;
V_79 = F_94 ( V_47 , & V_100 -> V_100 ) ;
if ( V_79 ) {
F_95 ( & V_100 -> V_100 , L_27 , V_79 ) ;
goto V_140;
}
V_2 -> V_47 = V_47 ;
V_2 -> V_154 = 1 ;
F_96 ( V_100 , V_155 ) ;
return 0 ;
V_140:
F_84 ( V_2 ) ;
F_92 ( V_47 ) ;
return V_79 ;
}
static int F_97 ( struct V_127 * V_100 )
{
struct V_1 * V_2 = F_98 ( & V_100 -> V_100 ) ;
struct V_106 * V_47 = V_2 -> V_47 ;
int V_79 ;
F_63 ( V_47 -> V_72 ) ;
F_39 ( V_2 ) ;
F_64 ( V_47 -> V_72 ) ;
F_84 ( V_2 ) ;
V_79 = F_85 ( V_2 ) ;
if ( V_79 ) {
F_95 ( & V_100 -> V_100 , L_28 , V_79 ) ;
F_92 ( V_47 ) ;
return V_79 ;
}
F_96 ( V_100 , V_155 ) ;
return 0 ;
}
static int F_99 ( struct V_127 * V_100 )
{
struct V_1 * V_2 = F_98 ( & V_100 -> V_100 ) ;
struct V_106 * V_47 = V_2 -> V_47 ;
int V_79 = 0 ;
F_63 ( V_47 -> V_72 ) ;
V_2 -> V_102 = 1 ;
while ( V_2 -> V_103 && ! V_79 ) {
V_2 -> V_104 = 1 ;
V_2 -> V_3 = 0 ;
F_64 ( V_47 -> V_72 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_79 = F_65 ( V_2 -> V_105 ,
! V_2 -> V_104 ) ;
F_63 ( V_47 -> V_72 ) ;
}
F_64 ( V_47 -> V_72 ) ;
return V_79 ;
}
static int F_100 ( struct V_127 * V_100 )
{
struct V_1 * V_2 = F_98 ( & V_100 -> V_100 ) ;
F_59 ( L_29 , V_109 , V_100 -> V_123 ) ;
F_101 ( & V_156 ) ;
if ( V_2 -> V_154 ) {
F_102 ( V_2 -> V_47 ) ;
V_2 -> V_154 = 0 ;
}
F_103 ( & V_156 ) ;
F_84 ( V_2 ) ;
F_92 ( V_2 -> V_47 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_127 * V_100 = V_2 -> V_100 ;
struct V_106 * V_47 = V_2 -> V_47 ;
F_59 ( L_30 , V_109 , V_100 -> V_123 ) ;
F_101 ( & V_156 ) ;
if ( V_2 -> V_154 ) {
F_102 ( V_47 ) ;
V_2 -> V_154 = 0 ;
}
F_103 ( & V_156 ) ;
F_105 ( V_100 ) ;
}
static void F_106 ( struct V_1 * V_2 , int V_157 )
{
struct V_127 * V_100 = V_2 -> V_100 ;
int V_20 , V_79 = 0 ;
char V_158 [ 64 ] ;
char * * V_159 ;
unsigned int V_160 = 0 ;
unsigned int V_161 ;
unsigned int V_162 , V_163 , V_164 , V_29 ;
struct V_118 * V_119 ;
V_159 = F_107 ( V_122 , V_100 -> V_165 , L_31 , & V_160 ) ;
if ( F_108 ( V_159 ) )
return;
F_15 ( V_2 -> V_121 ) ;
V_2 -> V_121 = V_120 ;
for ( V_20 = 0 ; V_20 < V_160 ; V_20 ++ ) {
snprintf ( V_158 , sizeof( V_158 ) , L_32 , V_159 [ V_20 ] ) ;
V_79 = F_109 ( V_122 , V_100 -> V_165 , V_158 , L_19 ,
& V_161 ) ;
if ( F_110 ( V_79 ) )
continue;
snprintf ( V_158 , sizeof( V_158 ) , L_33 , V_159 [ V_20 ] ) ;
V_79 = F_109 ( V_122 , V_100 -> V_165 , V_158 ,
L_34 , & V_162 , & V_163 , & V_164 , & V_29 ) ;
if ( F_110 ( V_79 ) )
continue;
snprintf ( V_2 -> V_124 , sizeof( V_2 -> V_124 ) ,
L_32 , V_159 [ V_20 ] ) ;
switch ( V_157 ) {
case V_166 :
if ( V_161 != V_155 )
break;
if ( F_111 ( V_2 -> V_47 , V_163 , V_164 , V_29 ) ) {
F_95 ( & V_100 -> V_100 , L_35 ) ;
F_71 ( V_122 , V_100 -> V_123 ,
V_2 -> V_124 ,
L_9 , V_126 ) ;
}
break;
case V_167 :
if ( V_161 != V_168 )
break;
V_119 = F_112 ( V_2 -> V_47 , V_163 , V_164 , V_29 ) ;
if ( V_119 ) {
F_113 ( V_119 ) ;
F_114 ( V_119 ) ;
}
break;
case V_169 :
if ( V_161 == V_125 )
F_71 ( V_122 , V_100 -> V_123 ,
V_2 -> V_124 ,
L_9 , V_125 ) ;
break;
default:
break;
}
}
V_2 -> V_121 = NULL ;
F_24 ( V_159 ) ;
}
static void F_115 ( struct V_127 * V_100 ,
struct V_1 * V_2 )
{
unsigned int V_170 , V_171 ;
struct V_106 * V_47 = V_2 -> V_47 ;
V_170 = F_116 ( V_100 -> V_165 , L_36 , 0 ) ;
V_171 = F_27 (unsigned int, sg_grant, SG_ALL) ;
V_171 = F_117 (unsigned int, nr_segs, VSCSIIF_SG_TABLESIZE) ;
V_171 = F_27 (unsigned int, nr_segs,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment)) ;
if ( ! V_2 -> V_102 && V_170 )
F_118 ( & V_100 -> V_100 , L_37 , V_171 ) ;
else if ( V_2 -> V_102 && V_171 < V_47 -> V_95 )
F_119 ( & V_100 -> V_100 ,
L_38 ,
V_47 -> V_95 , V_171 ) ;
V_47 -> V_95 = V_171 ;
V_47 -> V_152 = ( V_171 - 1 ) * V_130 / 512 ;
}
static void F_120 ( struct V_127 * V_100 ,
enum V_172 V_173 )
{
struct V_1 * V_2 = F_98 ( & V_100 -> V_100 ) ;
F_59 ( L_39 , V_109 , V_100 , V_100 -> V_174 , V_173 ) ;
switch ( V_173 ) {
case V_175 :
case V_176 :
case V_177 :
case V_155 :
break;
case V_125 :
F_115 ( V_100 , V_2 ) ;
if ( V_2 -> V_102 ) {
F_106 ( V_2 , V_169 ) ;
F_96 ( V_100 , V_125 ) ;
V_2 -> V_102 = 0 ;
return;
}
if ( F_121 ( V_100 -> V_123 ) ==
V_155 )
F_106 ( V_2 , V_166 ) ;
if ( V_100 -> V_174 != V_125 )
F_96 ( V_100 , V_125 ) ;
break;
case V_126 :
if ( V_100 -> V_174 == V_126 )
break;
case V_168 :
F_104 ( V_2 ) ;
break;
case V_178 :
F_106 ( V_2 , V_167 ) ;
F_96 ( V_100 , V_178 ) ;
break;
case V_179 :
F_106 ( V_2 , V_166 ) ;
F_96 ( V_100 , V_125 ) ;
break;
}
}
static int T_6 F_122 ( void )
{
if ( ! F_123 () )
return - V_180 ;
return F_124 ( & V_181 ) ;
}
static void T_7 F_125 ( void )
{
F_126 ( & V_181 ) ;
}
