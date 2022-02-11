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
struct V_77 * V_78 ;
V_16 -> V_79 = 0 ;
if ( V_25 -> V_26 == V_27 || ! V_73 )
return 0 ;
F_42 (sc, sg, scsi_sg_count(sc), i)
V_74 += F_43 ( V_33 -> V_80 + V_33 -> V_81 ) ;
if ( V_74 > V_82 ) {
if ( V_74 > V_2 -> V_31 -> V_83 ) {
F_20 ( V_48 , V_2 -> V_31 , V_32
L_4 ) ;
return - V_84 ;
}
V_75 = F_44 ( V_74 ) ;
V_11 -> V_33 = F_45 ( V_74 ,
sizeof( struct V_77 ) , V_85 ) ;
if ( ! V_11 -> V_33 )
return - V_86 ;
}
V_78 = V_11 -> V_33 ? : V_16 -> V_78 ;
V_65 = F_46 ( V_75 + V_74 ,
& V_63 ) ;
if ( V_65 ) {
F_23 ( V_11 -> V_33 ) ;
F_20 ( V_48 , V_2 -> V_31 , V_32
L_5 ) ;
return - V_86 ;
}
if ( V_75 ) {
V_64 = F_47 ( V_78 ) ;
V_70 = ( unsigned long ) V_78 & ~ V_87 ;
V_71 = sizeof( struct V_77 ) * V_74 ;
while ( V_71 > 0 ) {
V_72 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_66 = F_48 ( & V_63 ) ;
F_25 ( V_66 == - V_88 ) ;
F_49 ( V_66 ,
V_2 -> V_89 -> V_90 ,
F_50 ( V_64 ) , 1 ) ;
V_11 -> V_29 [ V_67 ] = V_66 ;
V_16 -> V_78 [ V_67 ] . V_29 = V_66 ;
V_16 -> V_78 [ V_67 ] . V_80 = ( V_19 ) V_70 ;
V_16 -> V_78 [ V_67 ] . V_81 = ( V_19 ) V_72 ;
V_64 ++ ;
V_71 -= V_72 ;
V_70 = 0 ;
V_67 ++ ;
}
F_25 ( V_75 < V_67 ) ;
V_75 = V_67 ;
}
F_42 (sc, sg, scsi_sg_count(sc), i) {
V_64 = F_51 ( V_33 ) ;
V_70 = V_33 -> V_80 ;
V_71 = V_33 -> V_81 ;
while ( V_71 > 0 && V_73 > 0 ) {
V_72 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_72 = F_52 ( V_72 , V_73 ) ;
V_66 = F_48 ( & V_63 ) ;
F_25 ( V_66 == - V_88 ) ;
F_49 ( V_66 ,
V_2 -> V_89 -> V_90 ,
F_50 ( V_64 ) ,
V_68 ) ;
V_11 -> V_29 [ V_67 ] = V_66 ;
V_78 -> V_29 = V_66 ;
V_78 -> V_80 = ( V_19 ) V_70 ;
V_78 -> V_81 = ( V_19 ) V_72 ;
V_64 ++ ;
V_78 ++ ;
V_71 -= V_72 ;
V_73 -= V_72 ;
V_70 = 0 ;
V_67 ++ ;
}
}
if ( V_75 )
V_16 -> V_79 = V_91 | V_75 ;
else
V_16 -> V_79 = ( T_2 ) V_67 ;
V_11 -> V_28 = V_67 ;
return 0 ;
}
static struct V_13 * F_53 (
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
V_16 -> V_9 = V_25 -> V_92 -> V_9 ;
V_16 -> V_93 = V_25 -> V_92 -> V_93 ;
V_16 -> V_94 = V_25 -> V_92 -> V_94 ;
V_16 -> V_95 = V_25 -> V_95 ;
F_25 ( V_25 -> V_95 > V_96 ) ;
memcpy ( V_16 -> V_97 , V_25 -> V_97 , V_25 -> V_95 ) ;
V_16 -> V_26 = ( T_2 ) V_25 -> V_26 ;
V_16 -> V_98 = V_25 -> V_99 -> V_100 / V_101 ;
return V_16 ;
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
struct V_36 * V_25 )
{
struct V_1 * V_2 = F_57 ( V_107 ) ;
struct V_13 * V_16 ;
struct V_22 * V_11 = F_58 ( V_25 ) ;
unsigned long V_5 ;
int V_65 ;
V_19 V_18 ;
F_4 ( V_107 -> V_58 , V_5 ) ;
if ( F_54 ( V_2 ) ) {
F_7 ( V_107 -> V_58 , V_5 ) ;
return V_108 ;
}
if ( F_59 ( & V_2 -> V_15 ) )
goto V_109;
V_16 = F_53 ( V_2 , V_25 , V_11 ) ;
if ( ! V_16 )
goto V_109;
V_25 -> V_38 = 0 ;
V_18 = V_16 -> V_18 ;
V_16 -> V_50 = V_51 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_50 = V_51 ;
V_65 = F_40 ( V_2 , V_25 , V_16 , V_11 ) ;
if ( V_65 < 0 ) {
F_60 ( L_6 , V_110 , V_65 ) ;
F_11 ( V_2 , V_18 ) ;
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_58 , V_5 ) ;
if ( V_65 == - V_86 )
return V_108 ;
V_25 -> V_38 = V_111 << 16 ;
V_25 -> V_43 ( V_25 ) ;
return 0 ;
}
F_14 ( V_2 ) ;
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_58 , V_5 ) ;
return 0 ;
V_109:
F_55 ( V_2 ) ;
F_7 ( V_107 -> V_58 , V_5 ) ;
F_60 ( L_7 , V_110 ) ;
return V_108 ;
}
static int F_61 ( struct V_36 * V_25 , T_2 V_50 )
{
struct V_106 * V_31 = V_25 -> V_92 -> V_31 ;
struct V_1 * V_2 = F_57 ( V_31 ) ;
struct V_22 * V_11 , * V_23 = F_58 ( V_25 ) ;
struct V_13 * V_16 ;
int V_65 = 0 ;
V_11 = F_62 ( sizeof( * V_11 ) , V_112 ) ;
if ( ! V_11 )
return V_113 ;
F_63 ( V_31 -> V_58 ) ;
for (; ; ) {
if ( ! F_59 ( & V_2 -> V_15 ) ) {
V_16 = F_53 ( V_2 , V_25 , V_11 ) ;
if ( V_16 )
break;
}
if ( V_65 || V_2 -> V_102 ) {
F_64 ( V_31 -> V_58 ) ;
F_23 ( V_11 ) ;
return V_113 ;
}
V_2 -> V_3 = 1 ;
F_64 ( V_31 -> V_58 ) ;
V_65 = F_65 ( V_2 -> V_4 ,
! V_2 -> V_3 ) ;
F_63 ( V_31 -> V_58 ) ;
}
if ( F_54 ( V_2 ) ) {
F_64 ( V_31 -> V_58 ) ;
return V_113 ;
}
V_16 -> V_50 = V_50 ;
V_16 -> V_114 = V_23 -> V_18 ;
V_11 -> V_50 = V_50 ;
V_11 -> V_45 = V_46 ;
F_66 ( & V_11 -> V_49 ) ;
V_16 -> V_79 = 0 ;
F_14 ( V_2 ) ;
F_64 ( V_31 -> V_58 ) ;
V_65 = F_65 ( V_11 -> V_49 , V_11 -> V_44 ) ;
F_63 ( V_31 -> V_58 ) ;
if ( ! V_65 ) {
V_65 = V_11 -> V_45 ;
F_11 ( V_2 , V_11 -> V_18 ) ;
F_23 ( V_11 ) ;
} else {
F_67 ( & V_2 -> V_6 ) ;
V_11 -> V_45 = V_47 ;
F_68 ( & V_2 -> V_6 ) ;
V_65 = V_113 ;
}
F_55 ( V_2 ) ;
F_64 ( V_31 -> V_58 ) ;
return V_65 ;
}
static int F_69 ( struct V_36 * V_25 )
{
F_60 ( L_8 , V_110 ) ;
return F_61 ( V_25 , V_115 ) ;
}
static int F_70 ( struct V_36 * V_25 )
{
F_60 ( L_8 , V_110 ) ;
return F_61 ( V_25 , V_116 ) ;
}
static int F_71 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_57 ( V_118 -> V_31 ) ;
if ( V_2 && V_119 == V_2 -> V_120 )
F_72 ( V_121 , V_2 -> V_89 -> V_122 ,
V_2 -> V_123 , L_9 , V_124 ) ;
return 0 ;
}
static void F_73 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_57 ( V_118 -> V_31 ) ;
if ( V_2 && V_119 == V_2 -> V_120 )
F_72 ( V_121 , V_2 -> V_89 -> V_122 ,
V_2 -> V_123 , L_9 , V_125 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_126 * V_89 = V_2 -> V_89 ;
struct V_127 * V_54 ;
T_5 V_29 ;
int V_65 = - V_86 ;
V_54 = (struct V_127 * ) F_75 ( V_128 ) ;
if ( ! V_54 ) {
F_76 ( V_89 , V_65 ,
L_10 ) ;
return V_65 ;
}
F_77 ( V_54 ) ;
F_78 ( & V_2 -> V_15 , V_54 , V_129 ) ;
V_65 = F_79 ( V_89 , V_54 , 1 , & V_29 ) ;
if ( V_65 < 0 ) {
F_80 ( ( unsigned long ) V_54 ) ;
F_76 ( V_89 , V_65 ,
L_11 ) ;
return V_65 ;
}
V_2 -> V_130 = V_29 ;
V_65 = F_81 ( V_89 , & V_2 -> V_131 ) ;
if ( V_65 ) {
F_76 ( V_89 , V_65 , L_12 ) ;
goto V_132;
}
V_65 = F_82 ( V_2 -> V_131 ) ;
if ( V_65 <= 0 ) {
F_76 ( V_89 , V_65 , L_13 ) ;
goto V_132;
}
V_2 -> V_21 = V_65 ;
V_65 = F_83 ( V_2 -> V_21 , NULL , F_37 ,
V_133 , L_14 , V_2 ) ;
if ( V_65 ) {
F_76 ( V_89 , V_65 , L_15 ) ;
goto V_134;
}
return 0 ;
V_134:
F_84 ( V_2 -> V_21 , V_2 ) ;
V_132:
F_22 ( V_2 -> V_130 , 0 ,
( unsigned long ) V_2 -> V_15 . V_54 ) ;
return V_65 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_84 ( V_2 -> V_21 , V_2 ) ;
F_22 ( V_2 -> V_130 , 0 ,
( unsigned long ) V_2 -> V_15 . V_54 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_126 * V_89 = V_2 -> V_89 ;
struct V_135 V_136 ;
int V_65 ;
F_60 ( L_8 , V_110 ) ;
V_65 = F_74 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_60 ( L_16 , V_110 , V_2 -> V_130 , V_2 -> V_131 ) ;
V_137:
V_65 = F_87 ( & V_136 ) ;
if ( V_65 )
F_76 ( V_89 , V_65 , L_17 ) ;
V_65 = F_72 ( V_136 , V_89 -> V_122 , L_18 , L_19 ,
V_2 -> V_130 ) ;
if ( V_65 ) {
F_76 ( V_89 , V_65 , L_20 , L_21 ) ;
goto V_138;
}
V_65 = F_72 ( V_136 , V_89 -> V_122 , L_22 , L_19 ,
V_2 -> V_131 ) ;
if ( V_65 ) {
F_76 ( V_89 , V_65 , L_20 , L_23 ) ;
goto V_138;
}
V_65 = F_88 ( V_136 , 0 ) ;
if ( V_65 ) {
if ( V_65 == - V_139 )
goto V_137;
F_76 ( V_89 , V_65 , L_24 ) ;
goto V_140;
}
return 0 ;
V_138:
F_88 ( V_136 , 1 ) ;
V_140:
F_85 ( V_2 ) ;
return V_65 ;
}
static int F_89 ( struct V_126 * V_89 ,
const struct V_141 * V_9 )
{
struct V_1 * V_2 ;
struct V_106 * V_31 ;
int V_65 = - V_86 ;
char V_142 [ V_143 ] ;
V_31 = F_90 ( & V_144 , sizeof( * V_2 ) ) ;
if ( ! V_31 ) {
F_76 ( V_89 , V_65 , L_25 ) ;
return V_65 ;
}
V_2 = (struct V_1 * ) V_31 -> V_145 ;
F_91 ( & V_89 -> V_89 , V_2 ) ;
V_2 -> V_89 = V_89 ;
F_92 ( V_2 -> V_7 , V_8 ) ;
V_65 = F_86 ( V_2 ) ;
if ( V_65 ) {
F_93 ( V_31 ) ;
return V_65 ;
}
F_66 ( & V_2 -> V_4 ) ;
F_66 ( & V_2 -> V_105 ) ;
F_94 ( & V_2 -> V_6 ) ;
snprintf ( V_142 , V_143 , L_26 , V_31 -> V_146 ) ;
V_31 -> V_147 = V_148 ;
V_31 -> V_149 = 0 ;
V_31 -> V_150 = V_151 ;
V_31 -> V_152 = ( V_31 -> V_83 - 1 ) * V_129 / 512 ;
V_31 -> V_153 = V_96 ;
V_65 = F_95 ( V_31 , & V_89 -> V_89 ) ;
if ( V_65 ) {
F_96 ( & V_89 -> V_89 , L_27 , V_65 ) ;
goto V_140;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_154 = 1 ;
F_97 ( V_89 , V_155 ) ;
return 0 ;
V_140:
F_85 ( V_2 ) ;
F_93 ( V_31 ) ;
return V_65 ;
}
static int F_98 ( struct V_126 * V_89 )
{
struct V_1 * V_2 = F_99 ( & V_89 -> V_89 ) ;
struct V_106 * V_31 = V_2 -> V_31 ;
int V_65 ;
F_63 ( V_31 -> V_58 ) ;
F_39 ( V_2 ) ;
F_64 ( V_31 -> V_58 ) ;
F_85 ( V_2 ) ;
V_65 = F_86 ( V_2 ) ;
if ( V_65 ) {
F_96 ( & V_89 -> V_89 , L_28 , V_65 ) ;
F_93 ( V_31 ) ;
return V_65 ;
}
F_97 ( V_89 , V_155 ) ;
return 0 ;
}
static int F_100 ( struct V_126 * V_89 )
{
struct V_1 * V_2 = F_99 ( & V_89 -> V_89 ) ;
struct V_106 * V_31 = V_2 -> V_31 ;
int V_65 = 0 ;
F_63 ( V_31 -> V_58 ) ;
V_2 -> V_102 = 1 ;
while ( V_2 -> V_103 && ! V_65 ) {
V_2 -> V_104 = 1 ;
V_2 -> V_3 = 0 ;
F_64 ( V_31 -> V_58 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_65 = F_65 ( V_2 -> V_105 ,
! V_2 -> V_104 ) ;
F_63 ( V_31 -> V_58 ) ;
}
F_64 ( V_31 -> V_58 ) ;
return V_65 ;
}
static int F_101 ( struct V_126 * V_89 )
{
struct V_1 * V_2 = F_99 ( & V_89 -> V_89 ) ;
F_60 ( L_29 , V_110 , V_89 -> V_122 ) ;
F_102 ( & V_156 ) ;
if ( V_2 -> V_154 ) {
F_103 ( V_2 -> V_31 ) ;
V_2 -> V_154 = 0 ;
}
F_104 ( & V_156 ) ;
F_85 ( V_2 ) ;
F_93 ( V_2 -> V_31 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_126 * V_89 = V_2 -> V_89 ;
struct V_106 * V_31 = V_2 -> V_31 ;
F_60 ( L_30 , V_110 , V_89 -> V_122 ) ;
F_102 ( & V_156 ) ;
if ( V_2 -> V_154 ) {
F_103 ( V_31 ) ;
V_2 -> V_154 = 0 ;
}
F_104 ( & V_156 ) ;
F_106 ( V_89 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_157 )
{
struct V_126 * V_89 = V_2 -> V_89 ;
int V_24 , V_65 = 0 ;
char V_158 [ 64 ] ;
char * * V_159 ;
unsigned int V_160 = 0 ;
unsigned int V_161 ;
unsigned int V_162 , V_163 , V_164 , V_93 ;
struct V_117 * V_118 ;
V_159 = F_108 ( V_121 , V_89 -> V_165 , L_31 , & V_160 ) ;
if ( F_109 ( V_159 ) )
return;
F_25 ( V_2 -> V_120 ) ;
V_2 -> V_120 = V_119 ;
for ( V_24 = 0 ; V_24 < V_160 ; V_24 ++ ) {
snprintf ( V_158 , sizeof( V_158 ) , L_32 , V_159 [ V_24 ] ) ;
V_65 = F_110 ( V_121 , V_89 -> V_165 , V_158 , L_19 ,
& V_161 ) ;
if ( F_111 ( V_65 ) )
continue;
snprintf ( V_158 , sizeof( V_158 ) , L_33 , V_159 [ V_24 ] ) ;
V_65 = F_110 ( V_121 , V_89 -> V_165 , V_158 ,
L_34 , & V_162 , & V_163 , & V_164 , & V_93 ) ;
if ( F_111 ( V_65 ) )
continue;
snprintf ( V_2 -> V_123 , sizeof( V_2 -> V_123 ) ,
L_32 , V_159 [ V_24 ] ) ;
switch ( V_157 ) {
case V_166 :
if ( V_161 != V_155 )
break;
if ( F_112 ( V_2 -> V_31 , V_163 , V_164 , V_93 ) ) {
F_96 ( & V_89 -> V_89 , L_35 ) ;
F_72 ( V_121 , V_89 -> V_122 ,
V_2 -> V_123 ,
L_9 , V_125 ) ;
}
break;
case V_167 :
if ( V_161 != V_168 )
break;
V_118 = F_113 ( V_2 -> V_31 , V_163 , V_164 , V_93 ) ;
if ( V_118 ) {
F_114 ( V_118 ) ;
F_115 ( V_118 ) ;
}
break;
case V_169 :
if ( V_161 == V_124 )
F_72 ( V_121 , V_89 -> V_122 ,
V_2 -> V_123 ,
L_9 , V_124 ) ;
break;
default:
break;
}
}
V_2 -> V_120 = NULL ;
F_23 ( V_159 ) ;
}
static void F_116 ( struct V_126 * V_89 ,
struct V_1 * V_2 )
{
unsigned int V_170 , V_171 ;
int V_172 ;
struct V_106 * V_31 = V_2 -> V_31 ;
V_172 = F_110 ( V_121 , V_89 -> V_165 , L_36 , L_19 ,
& V_170 ) ;
if ( V_172 != 1 )
V_170 = 0 ;
V_171 = F_27 (unsigned int, sg_grant, SG_ALL) ;
V_171 = F_117 (unsigned int, nr_segs, VSCSIIF_SG_TABLESIZE) ;
V_171 = F_27 (unsigned int, nr_segs,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment)) ;
if ( ! V_2 -> V_102 && V_170 )
F_118 ( & V_89 -> V_89 , L_37 , V_171 ) ;
else if ( V_2 -> V_102 && V_171 < V_31 -> V_83 )
F_119 ( & V_89 -> V_89 ,
L_38 ,
V_31 -> V_83 , V_171 ) ;
V_31 -> V_83 = V_171 ;
V_31 -> V_152 = ( V_171 - 1 ) * V_129 / 512 ;
}
static void F_120 ( struct V_126 * V_89 ,
enum V_173 V_174 )
{
struct V_1 * V_2 = F_99 ( & V_89 -> V_89 ) ;
F_60 ( L_39 , V_110 , V_89 , V_89 -> V_175 , V_174 ) ;
switch ( V_174 ) {
case V_176 :
case V_177 :
case V_178 :
case V_155 :
break;
case V_124 :
F_116 ( V_89 , V_2 ) ;
if ( V_2 -> V_102 ) {
F_107 ( V_2 , V_169 ) ;
F_97 ( V_89 , V_124 ) ;
V_2 -> V_102 = 0 ;
return;
}
if ( F_121 ( V_89 -> V_122 ) ==
V_155 )
F_107 ( V_2 , V_166 ) ;
if ( V_89 -> V_175 != V_124 )
F_97 ( V_89 , V_124 ) ;
break;
case V_125 :
if ( V_89 -> V_175 == V_125 )
break;
case V_168 :
F_105 ( V_2 ) ;
break;
case V_179 :
F_107 ( V_2 , V_167 ) ;
F_97 ( V_89 , V_179 ) ;
break;
case V_180 :
F_107 ( V_2 , V_166 ) ;
F_97 ( V_89 , V_124 ) ;
break;
}
}
static int T_6 F_122 ( void )
{
if ( ! F_123 () )
return - V_181 ;
return F_124 ( & V_182 ) ;
}
static void T_7 F_125 ( void )
{
F_126 ( & V_182 ) ;
}
