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
if ( ! V_5 )
goto V_33;
V_7 -> V_5 = V_5 ;
V_28 = F_21 ( V_10 -> V_34 , V_10 -> V_35 , V_32 ,
& V_5 -> V_24 ) ;
if ( ! V_28 ) {
F_19 ( & V_10 -> V_31 ,
L_3 ) ;
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
L_4 ) ;
V_40 = - V_44 ;
goto V_45;
}
V_5 = V_7 -> V_5 ;
V_5 -> V_11 = 0 ;
V_5 -> V_46 = 0 ;
V_40 = F_28 ( V_5 , V_32 ) ;
if ( V_40 ) {
F_19 ( & V_10 -> V_31 ,
L_5 ,
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
F_19 ( & V_10 -> V_31 , L_6 ) ;
goto error;
}
if ( F_35 ( V_10 -> V_52 ,
! F_27 ( & V_10 -> V_16 ) ||
V_10 -> V_11 != V_43 ) )
goto error;
}
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_7 ) ;
return;
error:
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_8 ) ;
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
L_9 , V_10 -> V_59 . V_60 ) ;
return - V_57 ;
}
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_10 , V_55 . V_62 ,
V_55 . V_63 , V_55 . V_64 ) ;
V_40 = F_39 ( V_10 -> V_34 ,
F_40 ( V_10 -> V_34 , 0 ) ,
0xb8 , 0x38 , 0x1 , 0 , NULL , 0 , 8000 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_11 , V_40 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_41 ( V_10 , V_65 , 0x00 ) ;
if ( V_40 )
return V_40 ;
V_10 -> V_11 = V_43 ;
F_42 ( & V_10 -> V_51 , F_33 ) ;
F_43 ( & V_10 -> V_51 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_12 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_46 ;
T_1 V_66 = 0 ;
T_2 * V_7 ;
if ( V_10 -> V_11 == V_56 )
return 0 ;
else if ( V_10 -> V_11 != V_43 )
return - V_57 ;
V_7 = F_45 ( V_10 -> V_35 , V_32 ) ;
if ( ! V_7 )
F_19 ( & V_10 -> V_31 , L_13 ) ;
V_10 -> V_11 = V_67 ;
F_41 ( V_10 , V_68 , 0x00 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_4 ( & V_10 -> V_52 ) ;
F_38 ( 50 ) ;
F_46 ( & V_10 -> V_51 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_5 ( V_10 ) ;
while ( V_7 && ++ V_66 < 500 &&
! F_47 ( V_10 -> V_34 ,
F_23 ( V_10 -> V_34 ,
V_10 -> V_37 ) ,
V_7 , V_10 -> V_35 , & V_46 ,
V_69 ) ) {
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_14 , V_66 , V_46 ) ;
}
F_14 ( V_7 ) ;
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_15 , V_66 - 1 ) ;
F_38 ( 10 ) ;
V_10 -> V_11 = V_56 ;
return 0 ;
}
static int F_48 ( struct V_70 * V_70 )
{
struct V_71 * V_72 = F_18 ( sizeof( * V_72 ) , V_32 ) ;
if ( V_72 == NULL )
return - V_27 ;
V_72 -> V_73 = true ;
F_49 ( & V_72 -> V_72 , F_50 ( V_70 ) ) ;
F_51 ( & V_72 -> V_72 ) ;
V_70 -> V_74 = V_72 ;
return 0 ;
}
static int F_52 ( struct V_70 * V_70 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_70 -> V_74 == V_10 -> V_75 ) {
F_44 ( V_10 ) ;
V_10 -> V_75 = NULL ;
}
F_31 ( & V_10 -> V_42 ) ;
return F_54 ( V_70 ) ;
}
static T_3 F_55 ( struct V_70 * V_70 , char T_4 * V_76 , T_5 V_4 ,
T_6 * V_77 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
unsigned int V_40 = 0 ;
int V_78 , V_79 ;
if ( * V_77 )
return - V_80 ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_16 ) ;
V_40 = - V_81 ;
F_38 ( 200 ) ;
V_10 -> V_11 = V_56 ;
F_31 ( & V_10 -> V_42 ) ;
goto V_45;
}
V_10 -> V_75 = V_70 -> V_74 ;
F_30 () ;
}
F_31 ( & V_10 -> V_42 ) ;
if ( ! ( V_70 -> V_82 & V_83 ) ) {
if ( F_35 ( V_10 -> V_13 ,
F_32 ( V_10 ) ) )
return - V_84 ;
}
V_7 = F_32 ( V_10 ) ;
while ( V_4 > 0 && V_7 ) {
if ( V_7 -> V_11 != V_12 &&
V_10 -> V_11 != V_85 ) {
int V_45 ;
if ( V_70 -> V_82 & V_83 ) {
if ( ! V_40 )
V_40 = - V_57 ;
goto V_45;
}
V_45 = F_56 ( V_10 -> V_13 ,
V_7 -> V_11 == V_12 ,
F_57 ( 1000 ) ) ;
if ( V_45 < 0 ) {
V_40 = V_45 ;
goto V_45;
}
if ( ! V_45 ) {
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_17 ) ;
F_44 ( V_10 ) ;
F_57 ( 4000 ) ;
V_45 = F_36 ( V_10 ) ;
if ( V_45 ) {
V_40 = V_45 ;
goto V_45;
}
}
}
if ( V_7 -> V_11 != V_12 )
break;
V_5 = V_7 -> V_5 ;
V_78 = V_5 -> V_46 - V_7 -> V_77 ;
V_79 = V_78 > V_4 ? V_4 : V_78 ;
if ( F_58 ( V_76 , V_5 -> V_23 + V_7 -> V_77 ,
V_79 ) ) {
F_19 ( & V_10 -> V_31 , L_18 ) ;
if ( ! V_40 )
V_40 = - V_44 ;
goto V_45;
}
V_7 -> V_77 += V_79 ;
V_4 -= V_79 ;
V_76 += V_79 ;
V_40 += V_79 ;
if ( V_7 -> V_77 == V_5 -> V_46 ) {
F_26 ( & V_10 -> V_42 ) ;
V_7 -> V_77 = 0 ;
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
static unsigned int F_59 ( struct V_70 * V_86 , T_7 * V_87 )
{
unsigned long V_88 = F_60 ( V_87 ) ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_10 = F_53 ( V_86 ) ;
unsigned int V_89 = F_61 ( V_86 , V_87 ) ;
if ( ! ( V_88 & ( V_90 | V_91 ) ) )
return V_89 ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_61 , V_30 , & V_10 -> V_31 ,
L_16 ) ;
V_10 -> V_11 = V_56 ;
} else {
V_10 -> V_75 = V_86 -> V_74 ;
}
F_30 () ;
}
F_31 ( & V_10 -> V_42 ) ;
V_7 = F_32 ( V_10 ) ;
if ( ! V_7 || V_7 -> V_11 != V_12 ) {
F_62 ( V_86 , & V_10 -> V_13 , V_87 ) ;
V_7 = F_32 ( V_10 ) ;
}
if ( V_7 && V_7 -> V_11 == V_12 )
V_89 |= V_90 | V_91 ;
return V_89 ;
}
static int F_63 ( struct V_70 * V_70 , void * V_92 ,
struct V_93 * V_94 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
strcpy ( V_94 -> V_95 , L_19 ) ;
strcpy ( V_94 -> V_96 , L_20 ) ;
F_64 ( V_10 -> V_34 , V_94 -> V_97 , sizeof( V_94 -> V_97 ) ) ;
V_94 -> V_98 = V_99 | V_100 |
V_101 ;
V_94 -> V_102 = V_94 -> V_98 | V_103 ;
return 0 ;
}
static int F_65 ( struct V_70 * V_70 , void * V_104 ,
T_8 V_105 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
T_2 V_106 = 1 ;
if ( ! V_72 -> V_73 && V_10 -> V_59 . V_60 == V_107 )
return - V_108 ;
if ( V_10 -> V_11 != V_56 )
return - V_109 ;
if ( V_105 & V_110 )
V_106 = 0 ;
V_10 -> V_111 = V_105 ;
V_10 -> V_62 = 720 ;
V_10 -> V_63 = V_106 ? 576 : 480 ;
return F_41 ( V_10 , V_112 , V_106 ) ;
}
static int F_66 ( struct V_70 * V_70 , void * V_104 ,
T_8 * V_105 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
if ( ! V_72 -> V_73 && V_10 -> V_59 . V_60 == V_107 )
return - V_108 ;
* V_105 = V_10 -> V_111 ;
return 0 ;
}
static int F_67 ( struct V_70 * V_70 , void * V_104 , T_8 * V_113 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_54 V_114 ;
struct V_71 * V_72 = V_104 ;
int V_40 ;
* V_113 = V_115 ;
if ( V_10 -> V_59 . V_60 == V_107 )
return V_72 -> V_73 ? 0 : - V_108 ;
V_40 = F_37 ( V_10 , & V_114 ) ;
if ( V_114 . V_58 && V_114 . V_62 == 720 &&
( V_114 . V_63 == 480 || V_114 . V_63 == 576 ) ) {
* V_113 = ( V_114 . V_63 == 480 ) ?
V_110 : V_116 ;
}
return V_40 ;
}
static int F_68 ( struct V_70 * V_70 , void * V_104 ,
struct V_117 * V_118 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
int V_25 ;
V_72 -> V_73 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_108 ;
if ( V_10 -> V_11 != V_56 )
return - V_109 ;
for ( V_25 = 0 ; V_25 < F_69 ( V_119 ) ; V_25 ++ )
if ( F_70 ( V_118 , V_119 + V_25 , 0 , false ) )
break;
if ( V_25 == F_69 ( V_119 ) )
return - V_120 ;
V_10 -> V_121 = V_119 [ V_25 ] ;
V_10 -> V_62 = V_119 [ V_25 ] . V_122 . V_62 ;
V_10 -> V_63 = V_119 [ V_25 ] . V_122 . V_63 ;
return 0 ;
}
static int F_71 ( struct V_70 * V_70 , void * V_104 ,
struct V_117 * V_118 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
V_72 -> V_73 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_108 ;
* V_118 = V_10 -> V_121 ;
return 0 ;
}
static int F_72 ( struct V_70 * V_70 , void * V_104 ,
struct V_117 * V_118 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
struct V_54 V_114 ;
bool V_123 ;
int V_40 = 0 ;
int V_25 ;
V_72 -> V_73 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_108 ;
V_40 = F_37 ( V_10 , & V_114 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_114 . V_58 )
return - V_124 ;
V_123 = V_114 . V_64 <= 30 ;
for ( V_25 = 0 ; V_25 < F_69 ( V_119 ) ; V_25 ++ ) {
const struct V_125 * V_122 = & V_119 [ V_25 ] . V_122 ;
unsigned V_126 ;
unsigned V_127 ;
unsigned V_64 ;
V_126 = F_73 ( V_122 ) ;
V_127 = F_74 ( V_122 ) ;
V_64 = ( unsigned ) V_122 -> V_128 / ( V_126 * V_127 ) ;
if ( V_122 -> V_62 != V_114 . V_62 ||
V_122 -> V_63 != V_114 . V_63 ||
V_122 -> V_123 != V_123 ||
( V_64 != V_114 . V_64 && V_64 + 1 != V_114 . V_64 ) )
continue;
* V_118 = V_119 [ V_25 ] ;
break;
}
if ( V_25 == F_69 ( V_119 ) )
V_40 = - V_129 ;
return V_40 ;
}
static int F_75 ( struct V_70 * V_70 , void * V_104 ,
struct V_130 * V_118 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
V_72 -> V_73 = false ;
memset ( V_118 -> V_131 , 0 , sizeof( V_118 -> V_131 ) ) ;
if ( V_10 -> V_59 . V_60 )
return - V_108 ;
if ( V_118 -> V_132 >= F_69 ( V_119 ) )
return - V_120 ;
V_118 -> V_118 = V_119 [ V_118 -> V_132 ] ;
return 0 ;
}
static int F_76 ( struct V_70 * V_70 , void * V_104 ,
struct V_133 * V_94 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
V_72 -> V_73 = false ;
if ( V_10 -> V_59 . V_60 )
return - V_108 ;
V_94 -> type = V_134 ;
V_94 -> V_122 . V_135 = 720 ;
V_94 -> V_122 . V_136 = 1920 ;
V_94 -> V_122 . V_137 = 480 ;
V_94 -> V_122 . V_138 = 1080 ;
V_94 -> V_122 . V_139 = 27000000 ;
V_94 -> V_122 . V_140 = 74250000 ;
V_94 -> V_122 . V_141 = V_142 ;
V_94 -> V_122 . V_102 = V_143 | V_144 ;
return 0 ;
}
static int F_77 ( struct V_70 * V_70 , void * V_104 , struct V_145 * V_25 )
{
unsigned int V_146 ;
V_146 = V_25 -> V_132 ;
if ( V_146 >= V_147 )
return - V_120 ;
V_25 -> type = V_148 ;
strncpy ( V_25 -> V_149 , V_150 [ V_146 ] , sizeof( V_25 -> V_149 ) - 1 ) ;
V_25 -> V_149 [ sizeof( V_25 -> V_149 ) - 1 ] = '\0' ;
V_25 -> V_151 = 1 << V_152 | 1 << V_153 | 1 << V_154 ;
V_25 -> V_102 = V_146 ? V_155 : V_156 ;
V_25 -> V_105 = V_146 ? V_157 : 0 ;
return 0 ;
}
static int F_78 ( struct V_70 * V_70 , void * V_104 ,
unsigned int V_132 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
int V_26 ;
if ( V_132 >= V_147 )
return - V_120 ;
if ( V_10 -> V_11 != V_56 )
return - V_109 ;
V_26 = F_41 ( V_10 , V_158 , V_132 + 1 ) ;
if ( ! V_26 ) {
V_10 -> V_59 . V_60 = V_132 ;
}
return V_26 ;
}
static int F_79 ( struct V_70 * V_70 , void * V_74 ,
unsigned int * V_132 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
* V_132 = V_10 -> V_59 . V_60 ;
return 0 ;
}
static int F_80 ( struct V_70 * V_70 , void * V_92 ,
struct V_159 * V_160 )
{
unsigned int V_146 ;
V_146 = V_160 -> V_132 ;
if ( V_146 >= V_161 )
return - V_120 ;
V_160 -> V_162 = V_163 ;
strncpy ( V_160 -> V_149 , V_164 [ V_146 ] , sizeof( V_160 -> V_149 ) - 1 ) ;
V_160 -> V_149 [ sizeof( V_160 -> V_149 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_81 ( struct V_70 * V_70 , void * V_74 ,
const struct V_159 * V_160 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
int V_26 ;
if ( V_160 -> V_132 >= V_161 )
return - V_120 ;
if ( V_10 -> V_11 != V_56 )
return - V_109 ;
V_26 = F_82 ( V_10 , V_160 -> V_132 + 1 , V_10 -> V_59 . V_165 ) ;
if ( ! V_26 )
V_10 -> V_59 . V_166 = V_160 -> V_132 ;
return V_26 ;
}
static int F_83 ( struct V_70 * V_70 , void * V_74 ,
struct V_159 * V_160 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
V_160 -> V_132 = V_10 -> V_59 . V_166 ;
V_160 -> V_162 = V_163 ;
strncpy ( V_160 -> V_149 , V_164 [ V_160 -> V_132 ] , sizeof( V_160 -> V_149 ) ) ;
V_160 -> V_149 [ sizeof( V_160 -> V_149 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_84 ( struct V_167 * V_168 )
{
struct V_9 * V_10 =
F_34 ( V_168 -> V_169 , struct V_9 , V_170 ) ;
switch ( V_168 -> V_171 ) {
case V_172 :
if ( V_168 -> V_173 == V_174 &&
V_10 -> V_175 -> V_173 >= V_10 -> V_176 -> V_173 )
V_10 -> V_176 -> V_173 =
V_10 -> V_175 -> V_173 + 100000 ;
break;
}
return 0 ;
}
static int F_85 ( struct V_167 * V_168 )
{
struct V_9 * V_10 =
F_34 ( V_168 -> V_169 , struct V_9 , V_170 ) ;
struct V_177 * V_178 = & V_10 -> V_59 ;
int V_40 = - V_120 ;
switch ( V_168 -> V_171 ) {
case V_179 :
V_40 = F_41 ( V_10 , V_180 , V_168 -> V_173 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_181 = V_168 -> V_173 ;
return 0 ;
case V_182 :
V_40 = F_41 ( V_10 , V_183 , V_168 -> V_173 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_184 = V_168 -> V_173 ;
return 0 ;
case V_185 :
V_40 = F_41 ( V_10 , V_186 , V_168 -> V_173 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_187 = V_168 -> V_173 ;
return 0 ;
case V_188 :
V_40 = F_41 ( V_10 , V_189 , V_168 -> V_173 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_190 = V_168 -> V_173 ;
return 0 ;
case V_191 :
V_40 = F_41 ( V_10 , V_192 , V_168 -> V_173 ) ;
if ( V_40 )
break;
V_10 -> V_59 . V_193 = V_168 -> V_173 ;
return 0 ;
case V_194 :
if ( V_10 -> V_195 & V_196 ) {
V_178 -> V_165 = V_168 -> V_173 ;
return F_82 ( V_10 , V_178 -> V_166 + 1 ,
V_178 -> V_165 ) ;
}
return 0 ;
case V_197 :
return 0 ;
case V_172 : {
T_1 V_198 = V_10 -> V_176 -> V_173 / 100000 ;
T_1 V_199 = V_10 -> V_175 -> V_173 / 100000 ;
if ( V_168 -> V_200 ) {
if ( V_168 -> V_173 == V_201 )
V_178 -> V_202 = V_203 ;
else
V_178 -> V_202 = V_204 ;
F_41 ( V_10 , V_205 ,
V_178 -> V_202 ) ;
F_86 ( V_10 -> V_176 ,
V_168 -> V_173 != V_201 ) ;
}
if ( V_10 -> V_176 -> V_200 ||
V_10 -> V_175 -> V_200 ) {
V_178 -> V_199 = V_199 ;
V_178 -> V_198 = V_198 ;
F_87 ( V_10 ) ;
}
return 0 ;
}
case V_206 :
return 0 ;
default:
break;
}
return V_40 ;
}
static int F_88 ( struct V_70 * V_70 , void * V_74 ,
struct V_207 * V_208 )
{
if ( V_208 -> V_132 != 0 )
return - V_120 ;
V_208 -> V_195 = V_209 ;
strncpy ( V_208 -> V_210 , L_21 , 32 ) ;
V_208 -> V_211 = V_212 ;
return 0 ;
}
static int F_89 ( struct V_70 * V_70 , void * V_104 ,
struct V_213 * V_208 )
{
struct V_9 * V_10 = F_53 ( V_70 ) ;
struct V_71 * V_72 = V_104 ;
int V_40 ;
if ( V_72 -> V_73 ) {
struct V_54 V_114 ;
V_40 = F_37 ( V_10 , & V_114 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( ! V_114 . V_58 )
return - V_44 ;
V_208 -> V_214 . V_215 . V_62 = V_114 . V_62 ;
V_208 -> V_214 . V_215 . V_63 = V_114 . V_63 ;
} else {
V_208 -> V_214 . V_215 . V_62 = V_10 -> V_62 ;
V_208 -> V_214 . V_215 . V_63 = V_10 -> V_63 ;
}
V_208 -> V_214 . V_215 . V_211 = V_212 ;
V_208 -> V_214 . V_215 . V_216 = V_10 -> V_35 ;
V_208 -> V_214 . V_215 . V_217 = 0 ;
if ( V_208 -> V_214 . V_215 . V_62 == 720 ) {
V_208 -> V_214 . V_215 . V_218 = V_219 ;
V_208 -> V_214 . V_215 . V_220 = V_221 ;
} else {
V_208 -> V_214 . V_215 . V_218 = V_222 ;
V_208 -> V_214 . V_215 . V_220 = V_223 ;
}
return 0 ;
}
static int F_90 ( struct V_70 * V_86 , void * V_92 ,
struct V_224 * V_113 )
{
struct V_9 * V_10 = F_53 ( V_86 ) ;
int V_225 = 0 ;
F_26 ( & V_10 -> V_42 ) ;
V_113 -> V_195 = 0 ;
switch ( V_113 -> V_226 ) {
case V_227 :
if ( V_10 -> V_75 && V_86 -> V_74 != V_10 -> V_75 ) {
V_225 = - V_109 ;
break;
}
if ( V_10 -> V_11 == V_43 )
break;
V_225 = F_36 ( V_10 ) ;
if ( ! V_225 )
V_10 -> V_75 = V_86 -> V_74 ;
else
V_10 -> V_11 = V_56 ;
break;
case V_228 :
if ( V_10 -> V_75 && V_86 -> V_74 != V_10 -> V_75 ) {
V_225 = - V_109 ;
break;
}
if ( V_10 -> V_11 == V_56 )
break;
V_225 = F_44 ( V_10 ) ;
if ( ! V_225 )
V_10 -> V_75 = NULL ;
break;
default:
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_22 , V_113 -> V_226 ) ;
V_225 = - V_120 ;
break;
}
F_31 ( & V_10 -> V_42 ) ;
return V_225 ;
}
static int F_91 ( struct V_70 * V_86 , void * V_92 ,
struct V_224 * V_113 )
{
V_113 -> V_195 = 0 ;
switch ( V_113 -> V_226 ) {
case V_227 :
case V_228 :
return 0 ;
default:
return - V_120 ;
}
}
static void F_92 ( struct V_229 * V_230 )
{
struct V_9 * V_10 = F_93 ( V_230 ) ;
F_94 ( V_10 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_46 ( & V_10 -> V_51 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_95 ( & V_10 -> V_31 ) ;
F_96 ( & V_10 -> V_170 ) ;
#if F_97 ( V_231 )
F_26 ( & V_10 -> V_232 ) ;
F_98 ( & V_10 -> V_233 ) ;
F_31 ( & V_10 -> V_232 ) ;
#endif
F_14 ( V_10 -> V_234 ) ;
F_14 ( V_10 ) ;
}
int F_99 ( struct V_9 * V_10 , struct V_235 * V_236 ,
int V_237 )
{
struct V_238 * V_170 = & V_10 -> V_170 ;
bool V_239 = V_10 -> V_195 & V_196 ;
int V_225 ;
V_10 -> V_111 = V_110 ;
V_10 -> V_62 = 720 ;
V_10 -> V_63 = 480 ;
V_10 -> V_121 = V_119 [ V_240 ] ;
F_100 ( V_170 , 11 ) ;
if ( V_10 -> V_241 > 0x15 ) {
F_101 ( V_170 , & V_242 ,
V_179 , 0x0 , 0xff , 1 , 0x80 ) ;
F_101 ( V_170 , & V_242 ,
V_182 , 0x0 , 0xff , 1 , 0x40 ) ;
F_101 ( V_170 , & V_242 ,
V_185 , 0x0 , 0xff , 1 , 0x40 ) ;
F_101 ( V_170 , & V_242 ,
V_188 , 0x0 , 0x1e , 1 , 0xf ) ;
F_101 ( V_170 , & V_242 ,
V_191 , 0x0 , 0xff , 1 , 0x80 ) ;
} else {
F_101 ( V_170 , & V_242 ,
V_179 , 0x0 , 0xff , 1 , 0x86 ) ;
F_101 ( V_170 , & V_242 ,
V_182 , 0x0 , 0xff , 1 , 0x80 ) ;
F_101 ( V_170 , & V_242 ,
V_185 , 0x0 , 0xff , 1 , 0x80 ) ;
F_101 ( V_170 , & V_242 ,
V_188 , 0x0 , 0xff , 1 , 0x80 ) ;
F_101 ( V_170 , & V_242 ,
V_191 , 0x0 , 0xff , 1 , 0x80 ) ;
}
F_102 ( V_170 , & V_242 ,
V_206 ,
V_243 ,
0x1 , V_243 ) ;
F_102 ( V_170 , & V_242 ,
V_194 ,
V_239 ? V_244 : V_245 ,
0x7 , V_239 ? V_10 -> V_59 . V_165 : V_245 ) ;
F_102 ( V_170 , & V_242 ,
V_197 ,
V_246 , 0x3 ,
V_246 ) ;
V_10 -> V_247 = F_102 ( V_170 , & V_242 ,
V_172 ,
V_201 , 0 ,
V_201 ) ;
V_10 -> V_175 = F_101 ( V_170 , & V_242 ,
V_248 ,
1000000 , 13500000 , 100000 , 6500000 ) ;
V_10 -> V_176 = F_101 ( V_170 , & V_242 ,
V_249 ,
1100000 , 20200000 , 100000 , 9000000 ) ;
V_10 -> V_31 . V_250 = V_170 ;
if ( V_170 -> error ) {
V_225 = V_170 -> error ;
F_19 ( & V_10 -> V_31 , L_23 ) ;
goto error;
}
F_103 ( 3 , & V_10 -> V_247 ) ;
V_225 = F_104 ( V_170 ) ;
if ( V_225 < 0 ) {
F_19 ( & V_10 -> V_31 , L_24 ) ;
goto error;
}
V_10 -> V_251 = V_252 ;
strcpy ( V_10 -> V_251 . V_149 , L_20 ) ;
V_10 -> V_251 . V_31 = & V_10 -> V_31 ;
F_105 ( & V_10 -> V_251 , V_10 ) ;
V_225 = F_106 ( & V_10 -> V_251 , V_253 , V_237 ) ;
if ( V_225 < 0 ) {
F_19 ( & V_10 -> V_31 , L_25 ) ;
goto error;
}
return 0 ;
error:
F_96 ( V_170 ) ;
return V_225 ;
}
