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
struct V_54 * V_55 ;
if ( V_10 -> V_11 == V_43 )
return 0 ;
else if ( V_10 -> V_11 != V_56 )
return - V_57 ;
V_55 = F_37 ( V_10 ) ;
if ( V_55 ) {
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_10 , V_55 -> V_59 ,
V_55 -> V_60 , V_55 -> V_61 ) ;
F_14 ( V_55 ) ;
V_40 = F_38 ( V_10 -> V_34 ,
F_39 ( V_10 -> V_34 , 0 ) ,
0xb8 , 0x38 , 0x1 , 0 , NULL , 0 , 8000 ) ;
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_11 , V_40 ) ;
F_40 ( V_10 , V_62 , 0x00 ) ;
F_41 ( & V_10 -> V_51 , F_33 ) ;
F_42 ( V_10 -> V_63 , & V_10 -> V_51 ) ;
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_12 ) ;
V_10 -> V_11 = V_43 ;
return 0 ;
}
F_43 ( 250 ) ;
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_13 , V_10 -> V_64 . V_65 ) ;
return - V_57 ;
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
F_19 ( & V_10 -> V_31 , L_14
L_15
L_16 ) ;
V_10 -> V_11 = V_67 ;
F_40 ( V_10 , V_68 , 0x00 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_4 ( & V_10 -> V_52 ) ;
F_43 ( 50 ) ;
F_46 ( V_10 -> V_63 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_5 ( V_10 ) ;
while ( V_7 && ++ V_66 < 500 &&
! F_47 ( V_10 -> V_34 ,
F_23 ( V_10 -> V_34 ,
V_10 -> V_37 ) ,
V_7 , V_10 -> V_35 , & V_46 ,
V_69 ) ) {
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_17 , V_66 , V_46 ) ;
}
F_14 ( V_7 ) ;
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_18 , V_66 - 1 ) ;
F_43 ( 10 ) ;
V_10 -> V_11 = V_56 ;
return 0 ;
}
static int F_48 ( struct V_70 * V_70 )
{
struct V_9 * V_10 ;
struct V_71 * V_72 ;
int V_26 = - V_27 ;
V_10 = (struct V_9 * ) F_49 ( F_50 ( V_70 ) ) ;
if ( ! V_10 ) {
F_51 ( L_19 ) ;
V_26 = - V_73 ;
goto V_45;
}
V_72 = F_18 ( sizeof( struct V_71 ) , V_32 ) ;
if ( ! V_72 ) {
F_19 ( & V_10 -> V_31 , L_20 ) ;
goto V_45;
}
F_26 ( & V_10 -> V_42 ) ;
V_10 -> V_74 ++ ;
F_31 ( & V_10 -> V_42 ) ;
V_72 -> V_10 = V_10 ;
V_70 -> V_75 = V_72 ;
V_26 = 0 ;
V_45:
return V_26 ;
}
static int F_52 ( struct V_70 * V_70 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
if ( ! V_10 )
return - V_73 ;
F_26 ( & V_10 -> V_42 ) ;
if ( ! ( -- V_10 -> V_74 ) && V_10 -> V_11 == V_43 )
F_44 ( V_10 ) ;
F_31 ( & V_10 -> V_42 ) ;
return 0 ;
}
static T_3 F_53 ( struct V_70 * V_70 , char T_4 * V_76 , T_5 V_4 ,
T_6 * V_77 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
unsigned int V_40 = 0 ;
int V_78 , V_79 ;
if ( * V_77 )
return - V_80 ;
if ( ! V_10 )
return - V_73 ;
F_26 ( & V_10 -> V_42 ) ;
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_21 ) ;
V_40 = - V_81 ;
F_43 ( 200 ) ;
V_10 -> V_11 = V_56 ;
F_31 ( & V_10 -> V_42 ) ;
goto V_45;
}
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
if ( V_70 -> V_82 & V_83 ) {
if ( ! V_40 )
V_40 = - V_57 ;
goto V_45;
}
if ( F_35 ( V_10 -> V_13 ,
V_7 -> V_11 == V_12 ) ) {
V_40 = - V_84 ;
goto V_45;
}
}
if ( V_7 -> V_11 != V_12 )
break;
V_5 = V_7 -> V_5 ;
V_78 = V_5 -> V_46 - V_7 -> V_77 ;
V_79 = V_78 > V_4 ? V_4 : V_78 ;
if ( F_54 ( V_76 , V_5 -> V_23 + V_7 -> V_77 ,
V_79 ) ) {
F_19 ( & V_10 -> V_31 , L_22 ) ;
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
static unsigned int F_55 ( struct V_70 * V_86 , T_7 * V_87 )
{
struct V_6 * V_7 = NULL ;
struct V_71 * V_72 = V_86 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
unsigned int V_88 = 0 ;
F_26 ( & V_10 -> V_42 ) ;
if ( ! F_56 ( V_10 -> V_89 ) ) {
F_31 ( & V_10 -> V_42 ) ;
return - V_81 ;
}
if ( V_10 -> V_11 == V_56 ) {
if ( F_36 ( V_10 ) ) {
F_17 ( V_58 , V_30 , & V_10 -> V_31 ,
L_21 ) ;
V_10 -> V_11 = V_56 ;
}
F_30 () ;
}
F_31 ( & V_10 -> V_42 ) ;
V_7 = F_32 ( V_10 ) ;
if ( ! V_7 || V_7 -> V_11 != V_12 ) {
F_57 ( V_86 , & V_10 -> V_13 , V_87 ) ;
V_7 = F_32 ( V_10 ) ;
}
if ( V_7 && V_7 -> V_11 == V_12 )
V_88 |= V_90 | V_91 ;
return V_88 ;
}
static int F_58 ( struct V_70 * V_70 , void * V_92 ,
struct V_93 * V_94 )
{
struct V_9 * V_10 = F_59 ( V_70 ) ;
strcpy ( V_94 -> V_95 , L_23 ) ;
strcpy ( V_94 -> V_96 , L_24 ) ;
F_60 ( V_10 -> V_34 , V_94 -> V_97 , sizeof( V_94 -> V_97 ) ) ;
V_94 -> V_98 = V_99 ;
V_94 -> V_100 = V_101 |
V_102 |
V_103 ;
return 0 ;
}
static int F_61 ( struct V_70 * V_70 , void * V_75 ,
T_8 * V_104 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
T_2 V_105 = 1 ;
if ( * V_104 & ( V_106 | V_107 ) )
V_105 = 0 ;
return F_40 ( V_10 , V_108 , V_105 ) ;
}
static int F_62 ( struct V_70 * V_70 , void * V_92 ,
struct V_109 * V_25 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
unsigned int V_110 ;
V_110 = V_25 -> V_111 ;
if ( V_110 >= V_112 )
return - V_113 ;
V_25 -> type = V_114 ;
strncpy ( V_25 -> V_115 , V_116 [ V_110 ] , sizeof( V_25 -> V_115 ) - 1 ) ;
V_25 -> V_115 [ sizeof( V_25 -> V_115 ) - 1 ] = '\0' ;
V_25 -> V_117 = 1 << V_118 | 1 << V_119 | 1 << V_120 ;
V_25 -> V_104 = V_10 -> V_89 -> V_121 ;
return 0 ;
}
static int F_63 ( struct V_70 * V_70 , void * V_75 ,
unsigned int V_111 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_26 ;
if ( V_111 >= V_112 )
return - V_113 ;
if ( V_10 -> V_11 != V_56 )
return - V_57 ;
V_26 = F_40 ( V_10 , V_122 , V_111 + 1 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_65 = V_111 ;
return V_26 ;
}
static int F_64 ( struct V_70 * V_70 , void * V_75 ,
unsigned int * V_111 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
* V_111 = V_10 -> V_64 . V_65 ;
return 0 ;
}
static int F_65 ( struct V_70 * V_70 , void * V_92 ,
struct V_123 * V_124 )
{
unsigned int V_110 ;
V_110 = V_124 -> V_111 ;
if ( V_110 >= V_125 )
return - V_113 ;
V_124 -> V_126 = V_127 ;
strncpy ( V_124 -> V_115 , V_128 [ V_110 ] , sizeof( V_124 -> V_115 ) - 1 ) ;
V_124 -> V_115 [ sizeof( V_124 -> V_115 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_66 ( struct V_70 * V_70 , void * V_75 ,
struct V_123 * V_124 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_26 ;
if ( V_124 -> V_111 >= V_125 )
return - V_113 ;
if ( V_10 -> V_11 != V_56 )
return - V_57 ;
V_26 = F_67 ( V_10 , V_124 -> V_111 + 1 , V_10 -> V_64 . V_129 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_130 = V_124 -> V_111 ;
return V_26 ;
}
static int F_68 ( struct V_70 * V_70 , void * V_75 ,
struct V_123 * V_124 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
V_124 -> V_111 = V_10 -> V_64 . V_130 ;
V_124 -> V_126 = V_127 ;
strncpy ( V_124 -> V_115 , V_128 [ V_124 -> V_111 ] , sizeof( V_124 -> V_115 ) ) ;
V_124 -> V_115 [ sizeof( V_124 -> V_115 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_69 ( struct V_131 * V_132 , struct V_133 * V_134 ,
int V_135 )
{
int V_45 ;
switch ( V_134 -> V_136 ) {
case V_137 :
return F_70 ( V_134 , 0x0 , 0xff , 1 , 0x86 ) ;
case V_138 :
return F_70 ( V_134 , 0x0 , 0xff , 1 , 0x80 ) ;
case V_139 :
return F_70 ( V_134 , 0x0 , 0xff , 1 , 0x80 ) ;
case V_140 :
return F_70 ( V_134 , 0x0 , 0xff , 1 , 0x80 ) ;
case V_141 :
return F_70 ( V_134 , 0x0 , 0xff , 1 , 0x80 ) ;
case V_142 :
return F_70 (
V_134 , V_143 ,
V_135 ? V_144
: V_143 ,
1 , V_143 ) ;
case V_145 :
return F_70 (
V_134 , V_146 ,
V_146 , 1 ,
V_146 ) ;
case V_147 :
return F_70 (
V_134 , V_148 ,
V_149 , 1 ,
V_149 ) ;
case V_150 :
return F_70 ( V_134 , 1000000 , 13500000 , 100000 ,
6500000 ) ;
case V_151 :
V_45 = F_70 ( V_134 , 1100000 , 20200000 , 100000 ,
9000000 ) ;
if ( ! V_45 && V_132 -> V_152 == V_153 )
V_134 -> V_154 |= V_155 ;
return V_45 ;
default:
return - V_113 ;
}
}
static int F_71 ( struct V_70 * V_70 , void * V_75 ,
struct V_133 * V_134 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_25 , V_20 ;
T_9 V_136 = V_134 -> V_136 ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
V_20 = ! ! ( V_136 & V_156 ) ;
V_134 -> V_136 = V_136 & ~ V_156 ;
for ( V_25 = 0 ; V_25 < F_72 ( V_157 ) ; V_25 ++ ) {
if ( V_20 ) {
if ( V_134 -> V_136 < V_157 [ V_25 ] )
V_134 -> V_136 = V_157 [ V_25 ] ;
else
continue;
}
if ( V_134 -> V_136 == V_157 [ V_25 ] )
return F_69 ( & V_10 -> V_64 , V_134 ,
V_10 -> V_154 & V_158 ) ;
if ( V_134 -> V_136 < V_157 [ V_25 ] )
break;
}
return - V_113 ;
}
static int F_73 ( struct V_70 * V_70 , void * V_75 ,
struct V_159 * V_160 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
switch ( V_160 -> V_136 ) {
case V_137 :
V_160 -> V_161 = V_10 -> V_64 . V_162 ;
break;
case V_138 :
V_160 -> V_161 = V_10 -> V_64 . V_163 ;
break;
case V_139 :
V_160 -> V_161 = V_10 -> V_64 . V_164 ;
break;
case V_140 :
V_160 -> V_161 = V_10 -> V_64 . V_165 ;
break;
case V_141 :
V_160 -> V_161 = V_10 -> V_64 . V_166 ;
break;
default:
return - V_113 ;
}
return 0 ;
}
static int F_74 ( struct V_70 * V_70 , void * V_75 ,
struct V_159 * V_160 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_26 ;
switch ( V_160 -> V_136 ) {
case V_137 :
V_26 = F_40 ( V_10 , V_167 , V_160 -> V_161 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_162 = V_160 -> V_161 ;
break;
case V_138 :
V_26 = F_40 ( V_10 , V_168 , V_160 -> V_161 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_163 = V_160 -> V_161 ;
break;
case V_139 :
V_26 = F_40 ( V_10 , V_169 , V_160 -> V_161 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_164 = V_160 -> V_161 ;
break;
case V_140 :
V_26 = F_40 ( V_10 , V_170 , V_160 -> V_161 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_165 = V_160 -> V_161 ;
break;
case V_141 :
V_26 = F_40 ( V_10 , V_171 , V_160 -> V_161 ) ;
if ( ! V_26 )
V_10 -> V_64 . V_166 = V_160 -> V_161 ;
break;
default:
return - V_113 ;
}
return V_26 ;
}
static int F_75 ( struct V_131 * V_132 ,
struct V_172 * V_160 )
{
switch ( V_160 -> V_136 ) {
case V_142 :
V_160 -> V_161 = V_132 -> V_129 ;
break;
case V_145 :
V_160 -> V_161 = V_146 ;
break;
case V_147 :
V_160 -> V_161 = V_132 -> V_152 == V_153
? V_149
: V_148 ;
break;
case V_150 :
V_160 -> V_161 = V_132 -> V_173 * 100000 ;
break;
case V_151 :
V_160 -> V_161 = V_132 -> V_174 * 100000 ;
break;
case V_175 :
V_160 -> V_161 = V_176 ;
break;
default:
return - V_113 ;
}
return 0 ;
}
static int F_76 ( struct V_70 * V_70 , void * V_92 ,
struct V_177 * V_178 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_25 , V_45 = 0 ;
if ( V_178 -> V_179 == V_180 ) {
for ( V_25 = 0 ; V_25 < V_178 -> V_4 ; V_25 ++ ) {
struct V_172 * V_160 = V_178 -> V_181 + V_25 ;
V_45 = F_75 ( & V_10 -> V_64 , V_160 ) ;
if ( V_45 ) {
V_178 -> V_182 = V_25 ;
break;
}
}
return V_45 ;
}
return - V_113 ;
}
static int F_77 ( struct V_172 * V_160 , int V_135 )
{
int V_40 = - V_113 ;
switch ( V_160 -> V_136 ) {
case V_142 :
if ( V_160 -> V_161 == V_143 ||
( V_135 && V_160 -> V_161 == V_144 ) )
V_40 = 0 ;
break;
case V_145 :
if ( V_160 -> V_161 == V_146 )
V_40 = 0 ;
break;
case V_147 :
if ( V_160 -> V_161 == V_149 ||
V_160 -> V_161 == V_148 )
V_40 = 0 ;
break;
case V_150 :
{
T_1 V_173 = V_160 -> V_161 / 100000 ;
if ( V_173 >= 10 && V_173 <= 135 )
V_40 = 0 ;
break;
}
case V_151 :
{
T_1 V_174 = V_160 -> V_161 / 100000 ;
if ( V_174 >= 10 && V_174 <= 202 )
V_40 = 0 ;
break;
}
case V_175 :
if ( V_160 -> V_161 == V_176 )
V_40 = 0 ;
break;
default:
return - V_113 ;
}
return 0 ;
}
static int F_78 ( struct V_70 * V_70 , void * V_92 ,
struct V_177 * V_178 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_25 , V_45 = 0 ;
if ( V_178 -> V_179 == V_180 ) {
for ( V_25 = 0 ; V_25 < V_178 -> V_4 ; V_25 ++ ) {
struct V_172 * V_160 = V_178 -> V_181 + V_25 ;
V_45 = F_77 ( V_160 ,
V_10 -> V_154 & V_158 ) ;
if ( V_45 ) {
V_178 -> V_182 = V_25 ;
break;
}
}
return V_45 ;
}
return - V_113 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_172 * V_160 )
{
struct V_131 * V_132 = & V_10 -> V_64 ;
int V_40 = 0 ;
switch ( V_160 -> V_136 ) {
case V_142 :
if ( V_10 -> V_154 & V_158 ) {
V_132 -> V_129 = V_160 -> V_161 ;
V_40 = F_67 ( V_10 , V_132 -> V_130 ,
V_132 -> V_129 ) ;
}
break;
case V_145 :
break;
case V_147 :
if ( V_160 -> V_161 == V_149 &&
V_132 -> V_152 != V_153 ) {
V_132 -> V_152 = V_153 ;
F_40 ( V_10 , V_183 ,
V_132 -> V_152 ) ;
}
if ( V_160 -> V_161 == V_148 &&
V_132 -> V_152 == V_153 ) {
V_132 -> V_152 = V_184 ;
F_40 ( V_10 , V_183 ,
V_132 -> V_152 ) ;
}
break;
case V_150 : {
T_1 V_173 = V_160 -> V_161 / 100000 ;
V_132 -> V_173 = V_173 ;
if ( V_173 >= V_132 -> V_174 )
V_132 -> V_174 = V_173 + 1 ;
F_80 ( V_10 ) ;
break;
}
case V_151 : {
T_1 V_174 = V_160 -> V_161 / 100000 ;
if ( V_132 -> V_152 == V_153 )
break;
if ( V_132 -> V_173 < V_174 ) {
V_132 -> V_174 = V_174 ;
F_80 ( V_10 ) ;
} else
V_40 = - V_113 ;
break;
}
case V_175 :
break;
default:
return - V_113 ;
}
return V_40 ;
}
static int F_81 ( struct V_70 * V_70 , void * V_92 ,
struct V_177 * V_178 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_25 , V_45 = 0 ;
if ( V_178 -> V_179 == V_180 ) {
for ( V_25 = 0 ; V_25 < V_178 -> V_4 ; V_25 ++ ) {
struct V_172 * V_160 = V_178 -> V_181 + V_25 ;
V_45 = F_77 ( V_160 ,
V_10 -> V_154 & V_158 ) ;
if ( V_45 ) {
V_178 -> V_182 = V_25 ;
break;
}
V_45 = F_79 ( V_10 , V_160 ) ;
if ( V_45 ) {
V_178 -> V_182 = V_25 ;
break;
}
}
return V_45 ;
}
return - V_113 ;
}
static int F_82 ( struct V_70 * V_70 , void * V_75 ,
struct V_185 * V_186 )
{
if ( V_186 -> V_111 != 0 || V_186 -> type != V_187 )
return - V_113 ;
V_186 -> V_154 = V_188 ;
strncpy ( V_186 -> V_189 , L_25 , 32 ) ;
V_186 -> V_190 = V_191 ;
return 0 ;
}
static int F_83 ( struct V_70 * V_70 , void * V_75 ,
struct V_192 * V_186 )
{
struct V_71 * V_72 = V_70 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
struct V_54 * V_193 ;
if ( ! V_10 )
return - V_73 ;
V_193 = F_37 ( V_10 ) ;
if ( ! V_193 )
return - V_44 ;
V_186 -> type = V_187 ;
V_186 -> V_194 . V_195 . V_190 = V_191 ;
V_186 -> V_194 . V_195 . V_59 = V_193 -> V_59 ;
V_186 -> V_194 . V_195 . V_60 = V_193 -> V_60 ;
V_186 -> V_194 . V_195 . V_196 = V_10 -> V_35 ;
V_186 -> V_194 . V_195 . V_197 = 0 ;
V_186 -> V_194 . V_195 . V_198 = 0 ;
V_186 -> V_194 . V_195 . V_199 = V_200 ;
F_14 ( V_193 ) ;
return 0 ;
}
static int F_84 ( struct V_70 * V_86 , void * V_92 ,
struct V_201 * V_202 )
{
struct V_71 * V_72 = V_86 -> V_75 ;
struct V_9 * V_10 = V_72 -> V_10 ;
int V_203 ;
F_26 ( & V_10 -> V_42 ) ;
memset ( & V_202 -> V_204 , 0 , sizeof( V_202 -> V_204 ) ) ;
switch ( V_202 -> V_205 ) {
case V_206 :
V_202 -> V_154 = 0 ;
V_203 = F_36 ( V_10 ) ;
break;
case V_207 :
V_203 = F_44 ( V_10 ) ;
break;
default:
F_17 ( V_29 , V_30 , & V_10 -> V_31 ,
L_26 , V_202 -> V_205 ) ;
V_203 = - V_113 ;
}
F_31 ( & V_10 -> V_42 ) ;
return V_203 ;
}
static int F_85 ( struct V_70 * V_86 , void * V_92 ,
struct V_201 * V_202 )
{
switch ( V_202 -> V_205 ) {
case V_206 :
case V_207 :
return 0 ;
default:
return - V_113 ;
}
}
static void F_86 ( struct V_208 * V_209 )
{
struct V_9 * V_10 = F_49 ( V_209 ) ;
F_87 ( V_10 ) ;
F_26 ( & V_10 -> V_42 ) ;
F_88 ( V_10 -> V_63 ) ;
F_31 ( & V_10 -> V_42 ) ;
F_89 ( & V_10 -> V_31 ) ;
#if F_90 ( V_210 ) || ( V_211 )
F_26 ( & V_10 -> V_212 ) ;
F_91 ( & V_10 -> V_213 ) ;
F_31 ( & V_10 -> V_212 ) ;
#endif
F_14 ( V_10 -> V_214 ) ;
F_14 ( V_10 ) ;
}
int F_92 ( struct V_9 * V_10 , struct V_215 * V_216 ,
int V_217 )
{
V_10 -> V_89 = F_93 () ;
if ( ! V_10 -> V_89 ) {
F_19 ( & V_10 -> V_31 , L_27 ) ;
goto error;
}
* ( V_10 -> V_89 ) = V_218 ;
strcpy ( V_10 -> V_89 -> V_115 , L_24 ) ;
V_10 -> V_89 -> V_216 = V_216 ;
F_94 ( V_10 -> V_89 , V_10 ) ;
if ( F_95 ( V_10 -> V_89 , V_219 , V_217 ) ) {
F_19 ( & V_10 -> V_31 , L_28 ) ;
goto error;
}
return 0 ;
error:
return - V_27 ;
}
