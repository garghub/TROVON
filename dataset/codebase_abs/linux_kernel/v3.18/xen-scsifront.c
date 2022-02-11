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
static int F_29 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_3 V_24 , V_50 ;
int V_51 = 0 ;
unsigned long V_5 ;
F_4 ( V_2 -> V_31 -> V_52 , V_5 ) ;
V_50 = V_2 -> V_15 . V_53 -> V_54 ;
F_30 () ;
for ( V_24 = V_2 -> V_15 . V_55 ; V_24 != V_50 ; V_24 ++ ) {
V_35 = F_31 ( & V_2 -> V_15 , V_24 ) ;
if ( F_32 ( V_35 -> V_18 >= V_8 ||
F_33 ( V_35 -> V_18 , V_2 -> V_7 ) ,
L_3 ,
V_35 -> V_18 ) )
continue;
if ( V_2 -> V_11 [ V_35 -> V_18 ] -> V_56 == V_57 )
F_24 ( V_2 , V_35 ) ;
else
F_28 ( V_2 , V_35 ) ;
}
V_2 -> V_15 . V_55 = V_24 ;
if ( V_24 != V_2 -> V_15 . V_17 )
F_34 ( & V_2 -> V_15 , V_51 ) ;
else
V_2 -> V_15 . V_53 -> V_58 = V_24 + 1 ;
V_2 -> V_3 = 0 ;
F_7 ( V_2 -> V_31 -> V_52 , V_5 ) ;
F_2 ( & V_2 -> V_4 ) ;
return V_51 ;
}
static T_4 F_35 ( int V_21 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
while ( F_29 ( V_2 ) )
F_36 () ;
return V_60 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_36 * V_25 ,
struct V_13 * V_16 ,
struct V_22 * V_11 )
{
T_5 V_61 ;
struct V_62 * V_62 ;
int V_63 , V_64 , V_65 = 0 ;
int V_66 = ( V_25 -> V_26 == V_67 ) ;
unsigned int V_24 , V_68 , V_69 , V_70 ;
unsigned int V_71 = F_38 ( V_25 ) ;
unsigned int V_72 = 0 , V_73 = 0 ;
struct V_74 * V_33 ;
unsigned long V_75 ;
struct V_76 * V_77 ;
V_16 -> V_78 = 0 ;
if ( V_25 -> V_26 == V_27 || ! V_71 )
return 0 ;
F_39 (sc, sg, scsi_sg_count(sc), i)
V_72 += F_40 ( V_33 -> V_79 + V_33 -> V_80 ) ;
if ( V_72 > V_81 ) {
if ( V_72 > V_2 -> V_31 -> V_82 ) {
F_20 ( V_48 , V_2 -> V_31 , V_32
L_4 ) ;
return - V_83 ;
}
V_73 = F_41 ( V_72 ) ;
V_11 -> V_33 = F_42 ( V_72 ,
sizeof( struct V_76 ) , V_84 ) ;
if ( ! V_11 -> V_33 )
return - V_85 ;
}
V_77 = V_11 -> V_33 ? : V_16 -> V_77 ;
V_63 = F_43 ( V_73 + V_72 ,
& V_61 ) ;
if ( V_63 ) {
F_23 ( V_11 -> V_33 ) ;
F_20 ( V_48 , V_2 -> V_31 , V_32
L_5 ) ;
return - V_85 ;
}
if ( V_73 ) {
V_62 = F_44 ( V_77 ) ;
V_68 = ( unsigned long ) V_77 & ~ V_86 ;
V_69 = sizeof( struct V_76 ) * V_72 ;
while ( V_69 > 0 ) {
V_70 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_64 = F_45 ( & V_61 ) ;
F_25 ( V_64 == - V_87 ) ;
V_75 = F_46 ( F_47 ( V_62 ) ) ;
F_48 ( V_64 ,
V_2 -> V_88 -> V_89 , V_75 , 1 ) ;
V_11 -> V_29 [ V_65 ] = V_64 ;
V_16 -> V_77 [ V_65 ] . V_29 = V_64 ;
V_16 -> V_77 [ V_65 ] . V_79 = ( V_19 ) V_68 ;
V_16 -> V_77 [ V_65 ] . V_80 = ( V_19 ) V_70 ;
V_62 ++ ;
V_69 -= V_70 ;
V_68 = 0 ;
V_65 ++ ;
}
F_25 ( V_73 < V_65 ) ;
V_73 = V_65 ;
}
F_39 (sc, sg, scsi_sg_count(sc), i) {
V_62 = F_49 ( V_33 ) ;
V_68 = V_33 -> V_79 ;
V_69 = V_33 -> V_80 ;
while ( V_69 > 0 && V_71 > 0 ) {
V_70 = F_27 (unsigned int, len, PAGE_SIZE - off) ;
V_70 = F_50 ( V_70 , V_71 ) ;
V_64 = F_45 ( & V_61 ) ;
F_25 ( V_64 == - V_87 ) ;
V_75 = F_46 ( F_47 ( V_62 ) ) ;
F_48 ( V_64 ,
V_2 -> V_88 -> V_89 , V_75 , V_66 ) ;
V_11 -> V_29 [ V_65 ] = V_64 ;
V_77 -> V_29 = V_64 ;
V_77 -> V_79 = ( V_19 ) V_68 ;
V_77 -> V_80 = ( V_19 ) V_70 ;
V_62 ++ ;
V_77 ++ ;
V_69 -= V_70 ;
V_71 -= V_70 ;
V_68 = 0 ;
V_65 ++ ;
}
}
if ( V_73 )
V_16 -> V_78 = V_90 | V_73 ;
else
V_16 -> V_78 = ( T_2 ) V_65 ;
V_11 -> V_28 = V_65 ;
return 0 ;
}
static struct V_13 * F_51 (
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
V_16 -> V_9 = V_25 -> V_91 -> V_9 ;
V_16 -> V_92 = V_25 -> V_91 -> V_92 ;
V_16 -> V_93 = V_25 -> V_91 -> V_93 ;
V_16 -> V_94 = V_25 -> V_94 ;
F_25 ( V_25 -> V_94 > V_95 ) ;
memcpy ( V_16 -> V_96 , V_25 -> V_96 , V_25 -> V_94 ) ;
V_16 -> V_26 = ( T_2 ) V_25 -> V_26 ;
V_16 -> V_97 = V_25 -> V_98 -> V_99 / V_100 ;
return V_16 ;
}
static int F_52 ( struct V_101 * V_102 ,
struct V_36 * V_25 )
{
struct V_1 * V_2 = F_53 ( V_102 ) ;
struct V_13 * V_16 ;
struct V_22 * V_11 = F_54 ( V_25 ) ;
unsigned long V_5 ;
int V_63 ;
V_19 V_18 ;
F_4 ( V_102 -> V_52 , V_5 ) ;
if ( F_55 ( & V_2 -> V_15 ) )
goto V_103;
V_16 = F_51 ( V_2 , V_25 , V_11 ) ;
if ( ! V_16 )
goto V_103;
V_25 -> V_38 = 0 ;
V_18 = V_16 -> V_18 ;
V_16 -> V_56 = V_57 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_56 = V_57 ;
V_63 = F_37 ( V_2 , V_25 , V_16 , V_11 ) ;
if ( V_63 < 0 ) {
F_56 ( L_6 , V_104 , V_63 ) ;
F_11 ( V_2 , V_18 ) ;
F_7 ( V_102 -> V_52 , V_5 ) ;
if ( V_63 == - V_85 )
return V_105 ;
V_25 -> V_38 = V_106 << 16 ;
V_25 -> V_43 ( V_25 ) ;
return 0 ;
}
F_14 ( V_2 ) ;
F_7 ( V_102 -> V_52 , V_5 ) ;
return 0 ;
V_103:
F_7 ( V_102 -> V_52 , V_5 ) ;
F_56 ( L_7 , V_104 ) ;
return V_105 ;
}
static int F_57 ( struct V_36 * V_25 , T_2 V_56 )
{
struct V_101 * V_31 = V_25 -> V_91 -> V_31 ;
struct V_1 * V_2 = F_53 ( V_31 ) ;
struct V_22 * V_11 , * V_23 = F_54 ( V_25 ) ;
struct V_13 * V_16 ;
int V_63 = 0 ;
V_11 = F_58 ( sizeof( * V_11 ) , V_107 ) ;
if ( ! V_11 )
return V_108 ;
F_59 ( V_31 -> V_52 ) ;
for (; ; ) {
if ( ! F_55 ( & V_2 -> V_15 ) ) {
V_16 = F_51 ( V_2 , V_25 , V_11 ) ;
if ( V_16 )
break;
}
if ( V_63 ) {
F_60 ( V_31 -> V_52 ) ;
F_23 ( V_11 ) ;
return V_108 ;
}
V_2 -> V_3 = 1 ;
F_60 ( V_31 -> V_52 ) ;
V_63 = F_61 ( V_2 -> V_4 ,
! V_2 -> V_3 ) ;
F_59 ( V_31 -> V_52 ) ;
}
V_16 -> V_56 = V_56 ;
V_16 -> V_109 = V_23 -> V_18 ;
V_11 -> V_56 = V_56 ;
V_11 -> V_45 = V_46 ;
F_62 ( & V_11 -> V_49 ) ;
V_16 -> V_78 = 0 ;
F_14 ( V_2 ) ;
F_60 ( V_31 -> V_52 ) ;
V_63 = F_61 ( V_11 -> V_49 , V_11 -> V_44 ) ;
F_59 ( V_31 -> V_52 ) ;
if ( ! V_63 ) {
V_63 = V_11 -> V_45 ;
F_11 ( V_2 , V_11 -> V_18 ) ;
F_23 ( V_11 ) ;
} else {
F_63 ( & V_2 -> V_6 ) ;
V_11 -> V_45 = V_47 ;
F_64 ( & V_2 -> V_6 ) ;
V_63 = V_108 ;
}
F_60 ( V_31 -> V_52 ) ;
return V_63 ;
}
static int F_65 ( struct V_36 * V_25 )
{
F_56 ( L_8 , V_104 ) ;
return F_57 ( V_25 , V_110 ) ;
}
static int F_66 ( struct V_36 * V_25 )
{
F_56 ( L_8 , V_104 ) ;
return F_57 ( V_25 , V_111 ) ;
}
static int F_67 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_53 ( V_113 -> V_31 ) ;
if ( V_2 && V_114 == V_2 -> V_115 )
F_68 ( V_116 , V_2 -> V_88 -> V_117 ,
V_2 -> V_118 , L_9 , V_119 ) ;
return 0 ;
}
static void F_69 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_53 ( V_113 -> V_31 ) ;
if ( V_2 && V_114 == V_2 -> V_115 )
F_68 ( V_116 , V_2 -> V_88 -> V_117 ,
V_2 -> V_118 , L_9 , V_120 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_121 * V_88 = V_2 -> V_88 ;
struct V_122 * V_53 ;
int V_63 = - V_85 ;
V_53 = (struct V_122 * ) F_71 ( V_123 ) ;
if ( ! V_53 ) {
F_72 ( V_88 , V_63 ,
L_10 ) ;
return V_63 ;
}
F_73 ( V_53 ) ;
F_74 ( & V_2 -> V_15 , V_53 , V_124 ) ;
V_63 = F_75 ( V_88 , F_76 ( V_53 ) ) ;
if ( V_63 < 0 ) {
F_77 ( ( unsigned long ) V_53 ) ;
F_72 ( V_88 , V_63 ,
L_11 ) ;
return V_63 ;
}
V_2 -> V_125 = V_63 ;
V_63 = F_78 ( V_88 , & V_2 -> V_126 ) ;
if ( V_63 ) {
F_72 ( V_88 , V_63 , L_12 ) ;
goto V_127;
}
V_63 = F_79 ( V_2 -> V_126 ) ;
if ( V_63 <= 0 ) {
F_72 ( V_88 , V_63 , L_13 ) ;
goto V_127;
}
V_2 -> V_21 = V_63 ;
V_63 = F_80 ( V_2 -> V_21 , NULL , F_35 ,
V_128 , L_14 , V_2 ) ;
if ( V_63 ) {
F_72 ( V_88 , V_63 , L_15 ) ;
goto V_129;
}
return 0 ;
V_129:
F_81 ( V_2 -> V_21 , V_2 ) ;
V_127:
F_22 ( V_2 -> V_125 , 0 ,
( unsigned long ) V_2 -> V_15 . V_53 ) ;
return V_63 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_121 * V_88 = V_2 -> V_88 ;
struct V_130 V_131 ;
int V_63 ;
F_56 ( L_8 , V_104 ) ;
V_63 = F_70 ( V_2 ) ;
if ( V_63 )
return V_63 ;
F_56 ( L_16 , V_104 , V_2 -> V_125 , V_2 -> V_126 ) ;
V_132:
V_63 = F_83 ( & V_131 ) ;
if ( V_63 )
F_72 ( V_88 , V_63 , L_17 ) ;
V_63 = F_68 ( V_131 , V_88 -> V_117 , L_18 , L_19 ,
V_2 -> V_125 ) ;
if ( V_63 ) {
F_72 ( V_88 , V_63 , L_20 , L_21 ) ;
goto V_133;
}
V_63 = F_68 ( V_131 , V_88 -> V_117 , L_22 , L_19 ,
V_2 -> V_126 ) ;
if ( V_63 ) {
F_72 ( V_88 , V_63 , L_20 , L_23 ) ;
goto V_133;
}
V_63 = F_84 ( V_131 , 0 ) ;
if ( V_63 ) {
if ( V_63 == - V_134 )
goto V_132;
F_72 ( V_88 , V_63 , L_24 ) ;
goto V_135;
}
return 0 ;
V_133:
F_84 ( V_131 , 1 ) ;
V_135:
F_81 ( V_2 -> V_21 , V_2 ) ;
F_22 ( V_2 -> V_125 , 0 ,
( unsigned long ) V_2 -> V_15 . V_53 ) ;
return V_63 ;
}
static int F_85 ( struct V_121 * V_88 ,
const struct V_136 * V_9 )
{
struct V_1 * V_2 ;
struct V_101 * V_31 ;
int V_63 = - V_85 ;
char V_137 [ V_138 ] ;
V_31 = F_86 ( & V_139 , sizeof( * V_2 ) ) ;
if ( ! V_31 ) {
F_72 ( V_88 , V_63 , L_25 ) ;
return V_63 ;
}
V_2 = (struct V_1 * ) V_31 -> V_140 ;
F_87 ( & V_88 -> V_88 , V_2 ) ;
V_2 -> V_88 = V_88 ;
F_88 ( V_2 -> V_7 , V_8 ) ;
V_63 = F_82 ( V_2 ) ;
if ( V_63 ) {
F_89 ( V_31 ) ;
return V_63 ;
}
F_62 ( & V_2 -> V_4 ) ;
F_90 ( & V_2 -> V_6 ) ;
snprintf ( V_137 , V_138 , L_26 , V_31 -> V_141 ) ;
V_31 -> V_142 = V_143 ;
V_31 -> V_144 = 0 ;
V_31 -> V_145 = V_146 ;
V_31 -> V_147 = ( V_31 -> V_82 - 1 ) * V_124 / 512 ;
V_31 -> V_148 = V_95 ;
V_63 = F_91 ( V_31 , & V_88 -> V_88 ) ;
if ( V_63 ) {
F_92 ( & V_88 -> V_88 , L_27 , V_63 ) ;
goto V_135;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_149 = 1 ;
F_93 ( V_88 , V_150 ) ;
return 0 ;
V_135:
F_81 ( V_2 -> V_21 , V_2 ) ;
F_22 ( V_2 -> V_125 , 0 ,
( unsigned long ) V_2 -> V_15 . V_53 ) ;
F_89 ( V_31 ) ;
return V_63 ;
}
static int F_94 ( struct V_121 * V_88 )
{
struct V_1 * V_2 = F_95 ( & V_88 -> V_88 ) ;
F_56 ( L_28 , V_104 , V_88 -> V_117 ) ;
F_96 ( & V_151 ) ;
if ( V_2 -> V_149 ) {
F_97 ( V_2 -> V_31 ) ;
V_2 -> V_149 = 0 ;
}
F_98 ( & V_151 ) ;
F_22 ( V_2 -> V_125 , 0 ,
( unsigned long ) V_2 -> V_15 . V_53 ) ;
F_81 ( V_2 -> V_21 , V_2 ) ;
F_89 ( V_2 -> V_31 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_121 * V_88 = V_2 -> V_88 ;
struct V_101 * V_31 = V_2 -> V_31 ;
F_56 ( L_29 , V_104 , V_88 -> V_117 ) ;
F_96 ( & V_151 ) ;
if ( V_2 -> V_149 ) {
F_97 ( V_31 ) ;
V_2 -> V_149 = 0 ;
}
F_98 ( & V_151 ) ;
F_100 ( V_88 ) ;
}
static void F_101 ( struct V_1 * V_2 , int V_152 )
{
struct V_121 * V_88 = V_2 -> V_88 ;
int V_24 , V_63 = 0 ;
char V_153 [ 64 ] ;
char * * V_154 ;
unsigned int V_155 = 0 ;
unsigned int V_156 ;
unsigned int V_157 , V_158 , V_159 , V_92 ;
struct V_112 * V_113 ;
V_154 = F_102 ( V_116 , V_88 -> V_160 , L_30 , & V_155 ) ;
if ( F_103 ( V_154 ) )
return;
F_25 ( V_2 -> V_115 ) ;
V_2 -> V_115 = V_114 ;
for ( V_24 = 0 ; V_24 < V_155 ; V_24 ++ ) {
snprintf ( V_153 , sizeof( V_153 ) , L_31 , V_154 [ V_24 ] ) ;
V_63 = F_104 ( V_116 , V_88 -> V_160 , V_153 , L_19 ,
& V_156 ) ;
if ( F_105 ( V_63 ) )
continue;
snprintf ( V_153 , sizeof( V_153 ) , L_32 , V_154 [ V_24 ] ) ;
V_63 = F_104 ( V_116 , V_88 -> V_160 , V_153 ,
L_33 , & V_157 , & V_158 , & V_159 , & V_92 ) ;
if ( F_105 ( V_63 ) )
continue;
snprintf ( V_2 -> V_118 , sizeof( V_2 -> V_118 ) ,
L_31 , V_154 [ V_24 ] ) ;
switch ( V_152 ) {
case V_161 :
if ( V_156 != V_150 )
break;
if ( F_106 ( V_2 -> V_31 , V_158 , V_159 , V_92 ) ) {
F_92 ( & V_88 -> V_88 , L_34 ) ;
F_68 ( V_116 , V_88 -> V_117 ,
V_2 -> V_118 ,
L_9 , V_120 ) ;
}
break;
case V_162 :
if ( V_156 != V_163 )
break;
V_113 = F_107 ( V_2 -> V_31 , V_158 , V_159 , V_92 ) ;
if ( V_113 ) {
F_108 ( V_113 ) ;
F_109 ( V_113 ) ;
}
break;
default:
break;
}
}
V_2 -> V_115 = NULL ;
F_23 ( V_154 ) ;
}
static void F_110 ( struct V_121 * V_88 ,
struct V_1 * V_2 )
{
unsigned int V_164 ;
int V_165 ;
struct V_101 * V_31 = V_2 -> V_31 ;
V_165 = F_104 ( V_116 , V_88 -> V_160 , L_35 , L_19 ,
& V_164 ) ;
if ( V_165 == 1 && V_164 ) {
V_164 = F_27 (unsigned int, sg_grant, SG_ALL) ;
V_164 = F_111 (unsigned int, sg_grant, VSCSIIF_SG_TABLESIZE) ;
V_31 -> V_82 = F_27 (unsigned int, sg_grant,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment)) ;
V_31 -> V_147 = ( V_31 -> V_82 - 1 ) * V_124 / 512 ;
}
F_112 ( & V_88 -> V_88 , L_36 , V_31 -> V_82 ) ;
}
static void F_113 ( struct V_121 * V_88 ,
enum V_166 V_167 )
{
struct V_1 * V_2 = F_95 ( & V_88 -> V_88 ) ;
F_56 ( L_37 , V_104 , V_88 , V_88 -> V_168 , V_167 ) ;
switch ( V_167 ) {
case V_169 :
case V_170 :
case V_171 :
case V_150 :
break;
case V_119 :
F_110 ( V_88 , V_2 ) ;
if ( F_114 ( V_88 -> V_117 ) ==
V_150 )
F_101 ( V_2 , V_161 ) ;
if ( V_88 -> V_168 != V_119 )
F_93 ( V_88 , V_119 ) ;
break;
case V_120 :
if ( V_88 -> V_168 == V_120 )
break;
case V_163 :
F_99 ( V_2 ) ;
break;
case V_172 :
F_101 ( V_2 , V_162 ) ;
F_93 ( V_88 , V_172 ) ;
break;
case V_173 :
F_101 ( V_2 , V_161 ) ;
F_93 ( V_88 , V_119 ) ;
break;
}
}
static int T_6 F_115 ( void )
{
if ( ! F_116 () )
return - V_174 ;
return F_117 ( & V_175 ) ;
}
static void T_7 F_118 ( void )
{
F_119 ( & V_175 ) ;
}
