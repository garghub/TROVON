static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = 0 ;
F_2 (tmp, list) {
V_4 ++ ;
}
return V_4 ;
}
static void F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_11 = V_12 ;
F_4 ( & V_10 -> V_13 ) ;
}
int F_5 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_6 (buf, &dev->rec_buff_list, buff_list) {
F_7 ( V_7 -> V_5 ) ;
V_7 -> V_11 = V_14 ;
}
F_8 ( & V_10 -> V_15 , V_10 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_18 )
{
struct V_1 * V_3 ;
struct V_1 * V_19 ;
struct V_6 * V_7 ;
struct V_5 * V_5 ;
for ( V_19 = V_18 -> V_20 ; V_19 != V_18 ; ) {
V_7 = F_10 ( V_19 , struct V_6 , V_21 ) ;
V_5 = V_7 -> V_5 ;
F_11 ( V_5 -> V_10 , V_5 -> V_22 ,
V_5 -> V_23 , V_5 -> V_24 ) ;
F_12 ( V_5 ) ;
V_3 = V_19 -> V_20 ;
F_13 ( V_19 ) ;
F_14 ( V_7 ) ;
V_19 = V_3 ;
}
return 0 ;
}
int F_15 ( struct V_9 * V_10 )
{
F_5 ( V_10 ) ;
F_9 ( & V_10 -> V_16 ) ;
F_9 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_16 ( struct V_9 * V_10 , T_1 V_4 )
{
T_1 V_25 ;
int V_26 = - V_27 ;
T_2 * V_28 ;
struct V_6 * V_7 ;
struct V_5 * V_5 ;
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_1 , V_4 ) ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ ) {
V_7 = F_18 ( sizeof( struct V_6 ) , V_32 ) ;
if ( ! V_7 ) {
F_19 ( & V_10 -> V_31 , L_2 ) ;
goto exit;
}
V_7 -> V_10 = V_10 ;
V_5 = F_20 ( 0 , V_32 ) ;
if ( ! V_5 ) {
F_19 ( & V_10 -> V_31 , L_3 ) ;
goto V_33;
}
V_7 -> V_5 = V_5 ;
V_28 = F_21 ( V_10 -> V_34 , V_10 -> V_35 , V_32 ,
& V_5 -> V_24 ) ;
if ( ! V_28 ) {
F_19 ( & V_10 -> V_31 ,
L_4 ) ;
goto V_36;
}
F_22 ( V_7 -> V_5 , V_10 -> V_34 ,
F_23 ( V_10 -> V_34 ,
V_10 -> V_37 ) ,
V_28 , V_10 -> V_35 ,
F_3 , V_7 ) ;
V_7 -> V_5 -> V_38 |= V_39 ;
V_7 -> V_11 = V_14 ;
F_24 ( & V_7 -> V_21 , & V_10 -> V_16 ) ;
}
return 0 ;
V_36:
F_12 ( V_5 ) ;
V_33:
F_14 ( V_7 ) ;
exit:
F_15 ( V_10 ) ;
return V_26 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_5 * V_5 ;
int V_40 = 0 , V_41 = 0 ;
F_26 ( & V_10 -> V_42 ) ;
while ( V_10 -> V_11 == V_43 &&
! F_27 ( & V_10 -> V_16 ) ) {
V_7 = F_10 ( V_10 -> V_16 . V_20 , struct V_6 ,
V_21 ) ;
if ( V_7 -> V_11 != V_14 ) {
F_19 ( & V_10 -> V_31 ,
L_5 ) ;
V_40 = - V_44 ;
goto V_45;
}
V_5 = V_7 -> V_5 ;
V_5 -> V_11 = 0 ;
V_5 -> V_46 = 0 ;
V_40 = F_28 ( V_5 , V_32 ) ;
if ( V_40 ) {
F_19 ( & V_10 -> V_31 ,
L_6 ,
V_47 , V_40 ) ;
if ( ++ V_41 > 2 )
break;
continue;
}
V_7 -> V_11 = V_48 ;
F_29 ( & V_7 -> V_21 , & V_10 -> V_15 ) ;
}
V_45:
F_30 () ;
F_31 ( & V_10 -> V_42 ) ;
return V_40 ;
}
static struct V_6 * F_32 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_26 ( & V_10 -> V_42 ) ;
if ( F_27 ( & V_10 -> V_15 ) ) {
F_31 ( & V_10 -> V_42 ) ;
return NULL ;
}
V_7 = F_10 ( V_10 -> V_15 . V_20 , struct V_6 ,
V_21 ) ;
F_31 ( & V_10 -> V_42 ) ;
return V_7 ;
}
static void F_33 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_34 ( V_50 , struct V_9 ,
V_51 ) ;
while ( V_10 -> V_11 == V_43 ) {
if ( F_25 ( V_10 ) ) {
F_19 ( & V_10 -> V_31 , L_7 ) ;
goto error;
}
if ( F_35 ( V_10 -> V_52 ,
! F_27 ( & V_10 -> V_16 ) ||
V_10 -> V_11 != V_43 ) )
goto error;
}
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_8 ) ;
return;
error:
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_9 ) ;
V_10 -> V_11 = V_53 ;
}
static int F_36 ( struct V_9 * V_10 )
{
int V_40 ;
struct V_54 V_55 ;
if ( V_10 -> V_11 == V_43 )
return 0 ;
if ( V_10 -> V_11 != V_56 )
return - V_57 ;
V_40 = F_37 ( V_10 , & V_55 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( ! V_55 . V_58 ) {
F_38 ( 250 ) ;
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_10 , V_10 -> V_59 . V_60 ) ;
return - V_57 ;
}
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_11 , V_55 . V_62 ,
V_55 . V_63 , V_55 . V_64 ) ;
V_40 = F_39 ( V_10 -> V_34 ,
F_40 ( V_10 -> V_34 , 0 ) ,
0xb8 , 0x38 , 0x1 , 0 , NULL , 0 , 8000 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_12 , V_40 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_41 ( V_10 , V_65 , 0x00 ) ;
if ( V_40 )
return V_40 ;
V_10 -> V_11 = V_43 ;
F_42 ( & V_10 -> V_51 , F_33 ) ;
F_43 ( V_10 -> V_66 , & V_10 -> V_51 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_13 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_46 ;
T_1 V_67 = 0 ;
T_2 * V_7 ;
if ( V_10 -> V_11 == V_56 )
return 0 ;
else if ( V_10 -> V_11 != V_43 )
return - V_57 ;
V_7 = F_45 ( V_10 -> V_35 , V_32 ) ;
if ( ! V_7 )
F_19 ( & V_10 -> V_31 , L_14
L_15
L_16 ) ;
V_10 -> V_11 = V_68 ;
F_41 ( V_10 , V_69 , 0x00 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_4 ( & V_10 -> V_52 ) ;
F_38 ( 50 ) ;
F_46 ( V_10 -> V_66 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_5 ( V_10 ) ;
while ( V_7 && ++ V_67 < 500 &&
! F_47 ( V_10 -> V_34 ,
F_23 ( V_10 -> V_34 ,
V_10 -> V_37 ) ,
V_7 , V_10 -> V_35 , & V_46 ,
V_70 ) ) {
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_17 , V_67 , V_46 ) ;
}
F_14 ( V_7 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_18 , V_67 - 1 ) ;
F_38 ( 10 ) ;
V_10 -> V_11 = V_56 ;
return 0 ;
}
static int F_48 ( struct V_71 * V_71 )
{
struct V_72 * V_73 = F_18 ( sizeof( * V_73 ) , V_32 ) ;
if ( V_73 == NULL )
return - V_27 ;
V_73 -> V_74 = true ;
F_49 ( & V_73 -> V_73 , F_50 ( V_71 ) ) ;
F_51 ( & V_73 -> V_73 ) ;
V_71 -> V_75 = V_73 ;
return 0 ;
}
static int F_52 ( struct V_71 * V_71 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_71 -> V_75 == V_10 -> V_76 ) {
F_44 ( V_10 ) ;
V_10 -> V_76 = NULL ;
}
F_31 ( & V_10 -> V_42 ) ;
return F_54 ( V_71 ) ;
}
static T_3 F_55 ( struct V_71 * V_71 , char T_4 * V_77 , T_5 V_4 ,
T_6 * V_78 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
unsigned int V_40 = 0 ;
int V_79 , V_80 ;
if ( * V_78 )
return - V_81 ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_19 ) ;
V_40 = - V_82 ;
F_38 ( 200 ) ;
V_10 -> V_11 = V_56 ;
F_31 ( & V_10 -> V_42 ) ;
goto V_45;
}
V_10 -> V_76 = V_71 -> V_75 ;
F_30 () ;
}
F_31 ( & V_10 -> V_42 ) ;
if ( ! ( V_71 -> V_83 & V_84 ) ) {
if ( F_35 ( V_10 -> V_13 ,
F_32 ( V_10 ) ) )
return - V_85 ;
}
V_7 = F_32 ( V_10 ) ;
while ( V_4 > 0 && V_7 ) {
if ( V_7 -> V_11 != V_12 &&
V_10 -> V_11 != V_86 ) {
if ( V_71 -> V_83 & V_84 ) {
if ( ! V_40 )
V_40 = - V_57 ;
goto V_45;
}
if ( F_35 ( V_10 -> V_13 ,
V_7 -> V_11 == V_12 ) ) {
V_40 = - V_85 ;
goto V_45;
}
}
if ( V_7 -> V_11 != V_12 )
break;
V_5 = V_7 -> V_5 ;
V_79 = V_5 -> V_46 - V_7 -> V_78 ;
V_80 = V_79 > V_4 ? V_4 : V_79 ;
if ( F_56 ( V_77 , V_5 -> V_23 + V_7 -> V_78 ,
V_80 ) ) {
F_19 ( & V_10 -> V_31 , L_20 ) ;
if ( ! V_40 )
V_40 = - V_44 ;
goto V_45;
}
V_7 -> V_78 += V_80 ;
V_4 -= V_80 ;
V_77 += V_80 ;
V_40 += V_80 ;
if ( V_7 -> V_78 == V_5 -> V_46 ) {
F_26 ( & V_10 -> V_42 ) ;
V_7 -> V_78 = 0 ;
V_7 -> V_11 = V_14 ;
F_29 ( & V_7 -> V_21 , & V_10 -> V_16 ) ;
F_30 () ;
F_31 ( & V_10 -> V_42 ) ;
F_4 ( & V_10 -> V_52 ) ;
V_7 = F_32 ( V_10 ) ;
}
}
V_45:
if ( ! V_40 && ! V_7 )
V_40 = - V_57 ;
return V_40 ;
}
static unsigned int F_57 ( struct V_71 * V_87 , T_7 * V_88 )
{
unsigned long V_89 = F_58 ( V_88 ) ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_10 = F_53 ( V_87 ) ;
unsigned int V_90 = F_59 ( V_87 , V_88 ) ;
if ( ! ( V_89 & ( V_91 | V_92 ) ) )
return V_90 ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_19 ) ;
V_10 -> V_11 = V_56 ;
} else {
V_10 -> V_76 = V_87 -> V_75 ;
}
F_30 () ;
}
F_31 ( & V_10 -> V_42 ) ;
V_7 = F_32 ( V_10 ) ;
if ( ! V_7 || V_7 -> V_11 != V_12 ) {
F_60 ( V_87 , & V_10 -> V_13 , V_88 ) ;
V_7 = F_32 ( V_10 ) ;
}
if ( V_7 && V_7 -> V_11 == V_12 )
V_90 |= V_91 | V_92 ;
return V_90 ;
}
static int F_61 ( struct V_71 * V_71 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
strcpy ( V_95 -> V_96 , L_21 ) ;
strcpy ( V_95 -> V_97 , L_22 ) ;
F_62 ( V_10 -> V_34 , V_95 -> V_98 , sizeof( V_95 -> V_98 ) ) ;
V_95 -> V_99 = V_100 | V_101 |
V_102 ;
V_95 -> V_103 = V_95 -> V_99 | V_104 ;
return 0 ;
}
static int F_63 ( struct V_71 * V_71 , void * V_105 ,
T_8 V_106 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
T_2 V_107 = 1 ;
if ( ! V_73 -> V_74 && V_10 -> V_59 . V_60 == V_108 )
return - V_109 ;
if ( V_10 -> V_11 != V_56 )
return - V_110 ;
if ( V_106 & V_111 )
V_107 = 0 ;
V_10 -> V_112 = V_106 ;
V_10 -> V_62 = 720 ;
V_10 -> V_63 = V_107 ? 576 : 480 ;
return F_41 ( V_10 , V_113 , V_107 ) ;
}
static int F_64 ( struct V_71 * V_71 , void * V_105 ,
T_8 * V_106 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
if ( ! V_73 -> V_74 && V_10 -> V_59 . V_60 == V_108 )
return - V_109 ;
* V_106 = V_10 -> V_112 ;
return 0 ;
}
static int F_65 ( struct V_71 * V_71 , void * V_105 , T_8 * V_114 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_54 V_115 ;
struct V_72 * V_73 = V_105 ;
int V_40 ;
* V_114 = V_116 ;
if ( V_10 -> V_59 . V_60 == V_108 )
return V_73 -> V_74 ? 0 : - V_109 ;
V_40 = F_37 ( V_10 , & V_115 ) ;
if ( V_115 . V_58 && V_115 . V_62 == 720 &&
( V_115 . V_63 == 480 || V_115 . V_63 == 576 ) ) {
* V_114 = ( V_115 . V_63 == 480 ) ?
V_111 : V_117 ;
}
return V_40 ;
}
static int F_66 ( struct V_71 * V_71 , void * V_105 ,
struct V_118 * V_119 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
int V_25 ;
V_73 -> V_74 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_109 ;
if ( V_10 -> V_11 != V_56 )
return - V_110 ;
for ( V_25 = 0 ; V_25 < F_67 ( V_120 ) ; V_25 ++ )
if ( F_68 ( V_119 , V_120 + V_25 , 0 ) )
break;
if ( V_25 == F_67 ( V_120 ) )
return - V_121 ;
V_10 -> V_122 = V_120 [ V_25 ] ;
V_10 -> V_62 = V_120 [ V_25 ] . V_123 . V_62 ;
V_10 -> V_63 = V_120 [ V_25 ] . V_123 . V_63 ;
return 0 ;
}
static int F_69 ( struct V_71 * V_71 , void * V_105 ,
struct V_118 * V_119 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
V_73 -> V_74 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_109 ;
* V_119 = V_10 -> V_122 ;
return 0 ;
}
static int F_70 ( struct V_71 * V_71 , void * V_105 ,
struct V_118 * V_119 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
struct V_54 V_115 ;
bool V_124 ;
int V_40 = 0 ;
int V_25 ;
V_73 -> V_74 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_109 ;
V_40 = F_37 ( V_10 , & V_115 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_115 . V_58 )
return - V_125 ;
V_124 = V_115 . V_64 <= 30 ;
for ( V_25 = 0 ; V_25 < F_67 ( V_120 ) ; V_25 ++ ) {
const struct V_126 * V_123 = & V_120 [ V_25 ] . V_123 ;
unsigned V_127 ;
unsigned V_128 ;
unsigned V_64 ;
V_127 = V_123 -> V_129 + V_123 -> V_130 + V_123 -> V_131 + V_123 -> V_62 ;
V_128 = V_123 -> V_132 + V_123 -> V_133 + V_123 -> V_134 +
V_123 -> V_135 + V_123 -> V_136 + V_123 -> V_137 +
V_123 -> V_63 ;
V_64 = ( unsigned ) V_123 -> V_138 / ( V_127 * V_128 ) ;
if ( V_123 -> V_62 != V_115 . V_62 ||
V_123 -> V_63 != V_115 . V_63 ||
V_123 -> V_124 != V_124 ||
( V_64 != V_115 . V_64 && V_64 + 1 != V_115 . V_64 ) )
continue;
* V_119 = V_120 [ V_25 ] ;
break;
}
if ( V_25 == F_67 ( V_120 ) )
V_40 = - V_139 ;
return V_40 ;
}
static int F_71 ( struct V_71 * V_71 , void * V_105 ,
struct V_140 * V_119 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
V_73 -> V_74 = false ;
memset ( V_119 -> V_141 , 0 , sizeof( V_119 -> V_141 ) ) ;
if ( V_10 -> V_59 . V_60 )
return - V_109 ;
if ( V_119 -> V_142 >= F_67 ( V_120 ) )
return - V_121 ;
V_119 -> V_119 = V_120 [ V_119 -> V_142 ] ;
return 0 ;
}
static int F_72 ( struct V_71 * V_71 , void * V_105 ,
struct V_143 * V_95 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
V_73 -> V_74 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_109 ;
V_95 -> type = V_144 ;
V_95 -> V_123 . V_145 = 720 ;
V_95 -> V_123 . V_146 = 1920 ;
V_95 -> V_123 . V_147 = 480 ;
V_95 -> V_123 . V_148 = 1080 ;
V_95 -> V_123 . V_149 = 27000000 ;
V_95 -> V_123 . V_150 = 74250000 ;
V_95 -> V_123 . V_151 = V_152 ;
V_95 -> V_123 . V_103 = V_153 | V_154 ;
return 0 ;
}
static int F_73 ( struct V_71 * V_71 , void * V_105 , struct V_155 * V_25 )
{
unsigned int V_156 ;
V_156 = V_25 -> V_142 ;
if ( V_156 >= V_157 )
return - V_121 ;
V_25 -> type = V_158 ;
strncpy ( V_25 -> V_159 , V_160 [ V_156 ] , sizeof( V_25 -> V_159 ) - 1 ) ;
V_25 -> V_159 [ sizeof( V_25 -> V_159 ) - 1 ] = '\0' ;
V_25 -> V_161 = 1 << V_162 | 1 << V_163 | 1 << V_164 ;
V_25 -> V_103 = V_156 ? V_165 : V_166 ;
V_25 -> V_106 = V_156 ? V_167 : 0 ;
return 0 ;
}
static int F_74 ( struct V_71 * V_71 , void * V_105 ,
unsigned int V_142 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
int V_26 ;
if ( V_142 >= V_157 )
return - V_121 ;
if ( V_10 -> V_11 != V_56 )
return - V_110 ;
V_26 = F_41 ( V_10 , V_168 , V_142 + 1 ) ;
if ( ! V_26 ) {
V_10 -> V_59 . V_60 = V_142 ;
}
return V_26 ;
}
static int F_75 ( struct V_71 * V_71 , void * V_75 ,
unsigned int * V_142 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
* V_142 = V_10 -> V_59 . V_60 ;
return 0 ;
}
static int F_76 ( struct V_71 * V_71 , void * V_93 ,
struct V_169 * V_170 )
{
unsigned int V_156 ;
V_156 = V_170 -> V_142 ;
if ( V_156 >= V_171 )
return - V_121 ;
V_170 -> V_172 = V_173 ;
strncpy ( V_170 -> V_159 , V_174 [ V_156 ] , sizeof( V_170 -> V_159 ) - 1 ) ;
V_170 -> V_159 [ sizeof( V_170 -> V_159 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_77 ( struct V_71 * V_71 , void * V_75 ,
const struct V_169 * V_170 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
int V_26 ;
if ( V_170 -> V_142 >= V_171 )
return - V_121 ;
if ( V_10 -> V_11 != V_56 )
return - V_110 ;
V_26 = F_78 ( V_10 , V_170 -> V_142 + 1 , V_10 -> V_59 . V_175 ) ;
if ( ! V_26 )
V_10 -> V_59 . V_176 = V_170 -> V_142 ;
return V_26 ;
}
static int F_79 ( struct V_71 * V_71 , void * V_75 ,
struct V_169 * V_170 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
V_170 -> V_142 = V_10 -> V_59 . V_176 ;
V_170 -> V_172 = V_173 ;
strncpy ( V_170 -> V_159 , V_174 [ V_170 -> V_142 ] , sizeof( V_170 -> V_159 ) ) ;
V_170 -> V_159 [ sizeof( V_170 -> V_159 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_80 ( struct V_177 * V_178 )
{
struct V_9 * V_10 =
F_34 ( V_178 -> V_179 , struct V_9 , V_180 ) ;
switch ( V_178 -> V_181 ) {
case V_182 :
if ( V_178 -> V_183 == V_184 &&
V_10 -> V_185 -> V_183 >= V_10 -> V_186 -> V_183 )
V_10 -> V_186 -> V_183 =
V_10 -> V_185 -> V_183 + 100000 ;
break;
}
return 0 ;
}
static int F_81 ( struct V_177 * V_178 )
{
struct V_9 * V_10 =
F_34 ( V_178 -> V_179 , struct V_9 , V_180 ) ;
struct V_187 * V_188 = & V_10 -> V_59 ;
int V_40 = - V_121 ;
switch ( V_178 -> V_181 ) {
case V_189 :
V_40 = F_41 ( V_10 , V_190 , V_178 -> V_183 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_191 = V_178 -> V_183 ;
return 0 ;
case V_192 :
V_40 = F_41 ( V_10 , V_193 , V_178 -> V_183 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_194 = V_178 -> V_183 ;
return 0 ;
case V_195 :
V_40 = F_41 ( V_10 , V_196 , V_178 -> V_183 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_197 = V_178 -> V_183 ;
return 0 ;
case V_198 :
V_40 = F_41 ( V_10 , V_199 , V_178 -> V_183 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_200 = V_178 -> V_183 ;
return 0 ;
case V_201 :
V_40 = F_41 ( V_10 , V_202 , V_178 -> V_183 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_203 = V_178 -> V_183 ;
return 0 ;
case V_204 :
if ( V_10 -> V_205 & V_206 ) {
V_188 -> V_175 = V_178 -> V_183 ;
return F_78 ( V_10 , V_188 -> V_176 ,
V_188 -> V_175 ) ;
}
return 0 ;
case V_207 :
return 0 ;
case V_182 : {
T_1 V_208 = V_10 -> V_186 -> V_183 / 100000 ;
T_1 V_209 = V_10 -> V_185 -> V_183 / 100000 ;
if ( V_178 -> V_210 ) {
if ( V_178 -> V_183 == V_211 )
V_188 -> V_212 = V_213 ;
else
V_188 -> V_212 = V_214 ;
F_41 ( V_10 , V_215 ,
V_188 -> V_212 ) ;
F_82 ( V_10 -> V_186 ,
V_178 -> V_183 != V_211 ) ;
}
if ( V_10 -> V_186 -> V_210 ||
V_10 -> V_185 -> V_210 ) {
V_188 -> V_209 = V_209 ;
V_188 -> V_208 = V_208 ;
F_83 ( V_10 ) ;
}
return 0 ;
}
case V_216 :
return 0 ;
default:
break;
}
return V_40 ;
}
static int F_84 ( struct V_71 * V_71 , void * V_75 ,
struct V_217 * V_218 )
{
if ( V_218 -> V_142 != 0 )
return - V_121 ;
V_218 -> V_205 = V_219 ;
strncpy ( V_218 -> V_220 , L_23 , 32 ) ;
V_218 -> V_221 = V_222 ;
return 0 ;
}
static int F_85 ( struct V_71 * V_71 , void * V_105 ,
struct V_223 * V_218 )
{
struct V_9 * V_10 = F_53 ( V_71 ) ;
struct V_72 * V_73 = V_105 ;
int V_40 ;
if ( V_73 -> V_74 ) {
struct V_54 V_115 ;
V_40 = F_37 ( V_10 , & V_115 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( ! V_115 . V_58 )
return - V_44 ;
V_218 -> V_224 . V_225 . V_62 = V_115 . V_62 ;
V_218 -> V_224 . V_225 . V_63 = V_115 . V_63 ;
} else {
V_218 -> V_224 . V_225 . V_62 = V_10 -> V_62 ;
V_218 -> V_224 . V_225 . V_63 = V_10 -> V_63 ;
}
V_218 -> V_224 . V_225 . V_221 = V_222 ;
V_218 -> V_224 . V_225 . V_226 = V_10 -> V_35 ;
V_218 -> V_224 . V_225 . V_227 = 0 ;
V_218 -> V_224 . V_225 . V_93 = 0 ;
if ( V_218 -> V_224 . V_225 . V_62 == 720 ) {
V_218 -> V_224 . V_225 . V_228 = V_229 ;
V_218 -> V_224 . V_225 . V_230 = V_231 ;
} else {
V_218 -> V_224 . V_225 . V_228 = V_232 ;
V_218 -> V_224 . V_225 . V_230 = V_233 ;
}
return 0 ;
}
static int F_86 ( struct V_71 * V_87 , void * V_93 ,
struct V_234 * V_114 )
{
struct V_9 * V_10 = F_53 ( V_87 ) ;
int V_235 = 0 ;
F_26 ( & V_10 -> V_42 ) ;
V_114 -> V_205 = 0 ;
switch ( V_114 -> V_236 ) {
case V_237 :
if ( V_10 -> V_76 && V_87 -> V_75 != V_10 -> V_76 ) {
V_235 = - V_110 ;
break;
}
if ( V_10 -> V_11 == V_43 )
break;
V_235 = F_36 ( V_10 ) ;
if ( ! V_235 )
V_10 -> V_76 = V_87 -> V_75 ;
else
V_10 -> V_11 = V_56 ;
break;
case V_238 :
if ( V_10 -> V_76 && V_87 -> V_75 != V_10 -> V_76 ) {
V_235 = - V_110 ;
break;
}
if ( V_10 -> V_11 == V_56 )
break;
V_235 = F_44 ( V_10 ) ;
if ( ! V_235 )
V_10 -> V_76 = NULL ;
break;
default:
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_24 , V_114 -> V_236 ) ;
V_235 = - V_121 ;
break;
}
F_31 ( & V_10 -> V_42 ) ;
return V_235 ;
}
static int F_87 ( struct V_71 * V_87 , void * V_93 ,
struct V_234 * V_114 )
{
V_114 -> V_205 = 0 ;
switch ( V_114 -> V_236 ) {
case V_237 :
case V_238 :
return 0 ;
default:
return - V_121 ;
}
}
static void F_88 ( struct V_239 * V_240 )
{
struct V_9 * V_10 = F_89 ( V_240 ) ;
F_90 ( V_10 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_91 ( V_10 -> V_66 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_92 ( & V_10 -> V_31 ) ;
F_93 ( & V_10 -> V_180 ) ;
#if F_94 ( V_241 )
F_26 ( & V_10 -> V_242 ) ;
F_95 ( & V_10 -> V_243 ) ;
F_31 ( & V_10 -> V_242 ) ;
#endif
F_14 ( V_10 -> V_244 ) ;
F_14 ( V_10 ) ;
}
int F_96 ( struct V_9 * V_10 , struct V_245 * V_246 ,
int V_247 )
{
struct V_248 * V_180 = & V_10 -> V_180 ;
bool V_249 = V_10 -> V_205 & V_206 ;
int V_235 ;
V_10 -> V_112 = V_111 ;
V_10 -> V_62 = 720 ;
V_10 -> V_63 = 480 ;
V_10 -> V_122 = V_120 [ V_250 ] ;
F_97 ( V_180 , 11 ) ;
if ( V_10 -> V_251 > 0x15 ) {
F_98 ( V_180 , & V_252 ,
V_189 , 0x0 , 0xff , 1 , 0x80 ) ;
F_98 ( V_180 , & V_252 ,
V_192 , 0x0 , 0xff , 1 , 0x40 ) ;
F_98 ( V_180 , & V_252 ,
V_195 , 0x0 , 0xff , 1 , 0x40 ) ;
F_98 ( V_180 , & V_252 ,
V_198 , 0x0 , 0x1e , 1 , 0xf ) ;
F_98 ( V_180 , & V_252 ,
V_201 , 0x0 , 0xff , 1 , 0x80 ) ;
} else {
F_98 ( V_180 , & V_252 ,
V_189 , 0x0 , 0xff , 1 , 0x86 ) ;
F_98 ( V_180 , & V_252 ,
V_192 , 0x0 , 0xff , 1 , 0x80 ) ;
F_98 ( V_180 , & V_252 ,
V_195 , 0x0 , 0xff , 1 , 0x80 ) ;
F_98 ( V_180 , & V_252 ,
V_198 , 0x0 , 0xff , 1 , 0x80 ) ;
F_98 ( V_180 , & V_252 ,
V_201 , 0x0 , 0xff , 1 , 0x80 ) ;
}
F_99 ( V_180 , & V_252 ,
V_216 ,
V_253 ,
0x1 , V_253 ) ;
F_99 ( V_180 , & V_252 ,
V_204 ,
V_249 ? V_254 : V_255 ,
0x7 , V_255 ) ;
F_99 ( V_180 , & V_252 ,
V_207 ,
V_256 , 0x3 ,
V_256 ) ;
V_10 -> V_257 = F_99 ( V_180 , & V_252 ,
V_182 ,
V_211 , 0 ,
V_211 ) ;
V_10 -> V_185 = F_98 ( V_180 , & V_252 ,
V_258 ,
1000000 , 13500000 , 100000 , 6500000 ) ;
V_10 -> V_186 = F_98 ( V_180 , & V_252 ,
V_259 ,
1100000 , 20200000 , 100000 , 9000000 ) ;
V_10 -> V_31 . V_260 = V_180 ;
if ( V_180 -> error ) {
V_235 = V_180 -> error ;
F_19 ( & V_10 -> V_31 , L_25 ) ;
goto error;
}
F_100 ( 3 , & V_10 -> V_257 ) ;
V_235 = F_101 ( V_180 ) ;
if ( V_235 < 0 ) {
F_19 ( & V_10 -> V_31 , L_26 ) ;
goto error;
}
V_10 -> V_261 = F_102 () ;
if ( ! V_10 -> V_261 ) {
F_19 ( & V_10 -> V_31 , L_27 ) ;
V_235 = - V_27 ;
goto error;
}
* V_10 -> V_261 = V_262 ;
strcpy ( V_10 -> V_261 -> V_159 , L_22 ) ;
V_10 -> V_261 -> V_31 = & V_10 -> V_31 ;
F_103 ( V_10 -> V_261 , V_10 ) ;
F_104 ( V_263 , & V_10 -> V_261 -> V_205 ) ;
V_235 = F_105 ( V_10 -> V_261 , V_264 , V_247 ) ;
if ( V_235 < 0 ) {
F_19 ( & V_10 -> V_31 , L_28 ) ;
goto error;
}
return 0 ;
error:
F_93 ( V_180 ) ;
return V_235 ;
}
