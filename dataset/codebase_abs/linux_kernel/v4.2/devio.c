static int F_1 ( unsigned V_1 )
{
unsigned V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( V_2 == 0 || V_2 > ( V_4 >> 20 ) )
V_2 = V_4 ;
else
V_2 <<= 20 ;
F_3 ( V_1 , & V_5 ) ;
if ( F_4 ( & V_5 ) <= V_2 )
return 0 ;
F_5 ( V_1 , & V_5 ) ;
return - V_6 ;
}
static void F_6 ( unsigned V_1 )
{
F_5 ( V_1 , & V_5 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
return ( ! F_8 ( & V_8 -> V_9 ) &&
V_8 -> V_10 -> V_11 != V_12 ) ;
}
static T_1 F_9 ( struct V_13 * V_13 , T_1 V_14 , int V_15 )
{
T_1 V_16 ;
F_10 ( & F_11 ( V_13 ) -> V_17 ) ;
switch ( V_15 ) {
case 0 :
V_13 -> V_18 = V_14 ;
V_16 = V_13 -> V_18 ;
break;
case 1 :
V_13 -> V_18 += V_14 ;
V_16 = V_13 -> V_18 ;
break;
case 2 :
default:
V_16 = - V_19 ;
}
F_12 ( & F_11 ( V_13 ) -> V_17 ) ;
return V_16 ;
}
static T_2 F_13 ( struct V_13 * V_13 , char T_3 * V_20 , T_4 V_21 ,
T_1 * V_22 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_24 * V_10 = V_8 -> V_10 ;
T_2 V_16 = 0 ;
unsigned V_25 ;
T_1 V_26 ;
int V_27 ;
V_26 = * V_22 ;
F_14 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_16 = - V_28 ;
goto V_29;
} else if ( V_26 < 0 ) {
V_16 = - V_19 ;
goto V_29;
}
if ( V_26 < sizeof( struct V_30 ) ) {
struct V_30 V_31 ;
memcpy ( & V_31 , & V_10 -> V_32 , sizeof( V_10 -> V_32 ) ) ;
F_15 ( & V_31 . V_33 ) ;
F_15 ( & V_31 . V_34 ) ;
F_15 ( & V_31 . V_35 ) ;
F_15 ( & V_31 . V_36 ) ;
V_25 = sizeof( struct V_30 ) - V_26 ;
if ( V_25 > V_21 )
V_25 = V_21 ;
if ( F_16 ( V_20 , ( ( char * ) & V_31 ) + V_26 , V_25 ) ) {
V_16 = - V_37 ;
goto V_29;
}
* V_22 += V_25 ;
V_20 += V_25 ;
V_21 -= V_25 ;
V_16 += V_25 ;
}
V_26 = sizeof( struct V_30 ) ;
for ( V_27 = 0 ; V_21 && V_27 < V_10 -> V_32 . V_38 ; V_27 ++ ) {
struct V_39 * V_40 =
(struct V_39 * ) V_10 -> V_41 [ V_27 ] ;
unsigned int V_42 = F_17 ( V_40 -> V_43 ) ;
if ( * V_22 < V_26 + V_42 ) {
unsigned V_44 =
F_17 ( V_10 -> V_40 [ V_27 ] . V_45 . V_43 ) ;
V_25 = V_42 - ( * V_22 - V_26 ) ;
if ( V_25 > V_21 )
V_25 = V_21 ;
if ( V_44 > ( * V_22 - V_26 ) ) {
V_44 -= ( * V_22 - V_26 ) ;
if ( F_16 ( V_20 ,
V_10 -> V_41 [ V_27 ] + ( * V_22 - V_26 ) ,
F_18 ( V_25 , V_44 ) ) ) {
V_16 = - V_37 ;
goto V_29;
}
}
* V_22 += V_25 ;
V_20 += V_25 ;
V_21 -= V_25 ;
V_16 += V_25 ;
}
V_26 += V_42 ;
}
V_29:
F_19 ( V_10 ) ;
return V_16 ;
}
static struct V_46 * F_20 ( unsigned int V_47 )
{
struct V_46 * V_48 ;
V_48 = F_21 ( sizeof( struct V_46 ) , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_50 = F_22 ( V_47 , V_49 ) ;
if ( ! V_48 -> V_50 ) {
F_23 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static void F_24 ( struct V_46 * V_48 )
{
int V_27 ;
F_25 ( V_48 -> V_51 ) ;
if ( V_48 -> V_52 )
F_26 ( V_48 -> V_52 ) ;
for ( V_27 = 0 ; V_27 < V_48 -> V_50 -> V_53 ; V_27 ++ ) {
if ( F_27 ( & V_48 -> V_50 -> V_54 [ V_27 ] ) )
F_23 ( F_28 ( & V_48 -> V_50 -> V_54 [ V_27 ] ) ) ;
}
F_23 ( V_48 -> V_50 -> V_54 ) ;
F_23 ( V_48 -> V_50 -> V_55 ) ;
F_23 ( V_48 -> V_50 -> V_56 ) ;
F_29 ( V_48 -> V_50 ) ;
F_6 ( V_48 -> V_57 ) ;
F_23 ( V_48 ) ;
}
static void F_30 ( struct V_46 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_32 ( & V_48 -> V_60 , & V_8 -> V_61 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_34 ( struct V_46 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_35 ( & V_48 -> V_60 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static struct V_46 * F_36 ( struct V_7 * V_8 )
{
unsigned long V_58 ;
struct V_46 * V_48 = NULL ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
if ( ! F_8 ( & V_8 -> V_62 ) ) {
V_48 = F_37 ( V_8 -> V_62 . V_63 , struct V_46 ,
V_60 ) ;
F_35 ( & V_48 -> V_60 ) ;
}
F_33 ( & V_8 -> V_59 , V_58 ) ;
return V_48 ;
}
static struct V_46 * F_38 ( struct V_7 * V_8 ,
void T_3 * V_64 )
{
struct V_46 * V_48 ;
F_39 (as, &ps->async_pending, asynclist)
if ( V_48 -> V_64 == V_64 ) {
F_35 ( & V_48 -> V_60 ) ;
return V_48 ;
}
return NULL ;
}
static void F_40 ( struct V_24 * V_65 ,
void T_3 * V_64 , int V_66 , unsigned V_42 ,
int V_67 , enum V_68 V_69 ,
unsigned char * V_70 , unsigned V_71 )
{
static const char * V_72 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_73 [] = { L_5 , L_6 } ;
int V_74 ;
const char * V_75 , * V_76 ;
if ( ! V_77 )
return;
V_74 = F_41 ( V_66 ) ;
V_75 = V_72 [ F_42 ( V_66 ) ] ;
V_76 = V_73 [ ! ! F_43 ( V_66 ) ] ;
if ( V_64 ) {
if ( V_69 == V_78 )
F_44 ( & V_65 -> V_10 , L_7
L_8 ,
V_64 , V_74 , V_75 , V_76 , V_42 ) ;
else
F_44 ( & V_65 -> V_10 , L_7
L_9 ,
V_64 , V_74 , V_75 , V_76 , V_42 ,
V_67 ) ;
} else {
if ( V_69 == V_78 )
F_44 ( & V_65 -> V_10 , L_10
L_11 ,
V_74 , V_75 , V_76 , V_42 , V_67 ) ;
else
F_44 ( & V_65 -> V_10 , L_12
L_13 ,
V_74 , V_75 , V_76 , V_42 , V_67 ) ;
}
if ( V_70 && V_71 > 0 ) {
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
V_70 , V_71 , 1 ) ;
}
}
static void F_46 ( struct V_50 * V_50 , unsigned V_25 )
{
int V_27 , V_81 ;
if ( ! V_77 )
return;
if ( V_50 -> V_53 == 0 ) {
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
V_50 -> V_55 , V_25 , 1 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_50 -> V_53 && V_25 ; V_27 ++ ) {
V_81 = ( V_25 > V_82 ) ? V_82 : V_25 ;
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
F_28 ( & V_50 -> V_54 [ V_27 ] ) , V_81 , 1 ) ;
V_25 -= V_81 ;
}
}
static int F_47 ( T_5 T_3 * V_83 , struct V_50 * V_50 )
{
unsigned V_27 , V_25 , V_81 ;
if ( V_50 -> V_84 > 0 )
V_25 = V_50 -> V_85 ;
else
V_25 = V_50 -> V_86 ;
if ( V_50 -> V_53 == 0 ) {
if ( F_16 ( V_83 , V_50 -> V_55 , V_25 ) )
return - V_37 ;
return 0 ;
}
for ( V_27 = 0 ; V_27 < V_50 -> V_53 && V_25 ; V_27 ++ ) {
V_81 = ( V_25 > V_82 ) ? V_82 : V_25 ;
if ( F_16 ( V_83 , F_28 ( & V_50 -> V_54 [ V_27 ] ) , V_81 ) )
return - V_37 ;
V_83 += V_81 ;
V_25 -= V_81 ;
}
return 0 ;
}
static void F_48 ( struct V_7 * V_8 , unsigned V_87 )
__releases( V_8 -> V_59 )
__acquires( V_8 -> V_59 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
F_39 (as, &ps->async_pending, asynclist) {
if ( V_48 -> V_87 == V_87 ) {
if ( V_48 -> V_88 != V_89 )
goto V_90;
V_48 -> V_88 = V_91 ;
V_48 -> V_87 = 0 ;
}
}
V_8 -> V_92 |= ( 1 << V_87 ) ;
V_90:
F_39 (as, &ps->async_pending, asynclist) {
if ( V_48 -> V_88 == V_91 ) {
V_48 -> V_88 = 0 ;
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_50 ( & V_8 -> V_59 ) ;
F_51 ( V_50 ) ;
F_52 ( V_50 ) ;
F_53 ( & V_8 -> V_59 ) ;
goto V_90;
}
}
}
static void V_62 ( struct V_50 * V_50 )
{
struct V_46 * V_48 = V_50 -> V_93 ;
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_94 V_95 ;
struct V_51 * V_51 = NULL ;
T_6 V_96 = 0 ;
const struct V_52 * V_52 = NULL ;
int V_97 ;
F_53 ( & V_8 -> V_59 ) ;
F_54 ( & V_48 -> V_60 , & V_8 -> V_62 ) ;
V_48 -> V_98 = V_50 -> V_98 ;
V_97 = V_48 -> V_97 ;
if ( V_97 ) {
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_99 = V_48 -> V_97 ;
V_95 . V_100 = V_48 -> V_98 ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_48 -> V_64 ;
V_51 = F_55 ( V_48 -> V_51 ) ;
V_52 = F_56 ( V_48 -> V_52 ) ;
V_96 = V_48 -> V_96 ;
}
F_57 ( & V_50 -> V_10 -> V_10 , L_15 ) ;
F_40 ( V_50 -> V_10 , V_48 -> V_64 , V_50 -> V_66 , V_50 -> V_86 ,
V_48 -> V_98 , V_104 , NULL , 0 ) ;
if ( ( V_50 -> V_105 & V_106 ) == V_107 )
F_46 ( V_50 , V_50 -> V_86 ) ;
if ( V_48 -> V_98 < 0 && V_48 -> V_87 && V_48 -> V_98 != - V_108 &&
V_48 -> V_98 != - V_109 )
F_48 ( V_8 , V_48 -> V_87 ) ;
F_50 ( & V_8 -> V_59 ) ;
if ( V_97 ) {
F_58 ( V_95 . V_99 , & V_95 , V_51 , V_52 , V_96 ) ;
F_25 ( V_51 ) ;
F_26 ( V_52 ) ;
}
F_59 ( & V_8 -> V_110 ) ;
}
static void F_60 ( struct V_7 * V_8 , struct V_111 * V_9 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
while ( ! F_8 ( V_9 ) ) {
V_48 = F_37 ( V_9 -> V_63 , struct V_46 , V_60 ) ;
F_35 ( & V_48 -> V_60 ) ;
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_61 ( V_50 ) ;
F_52 ( V_50 ) ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
}
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_62 ( struct V_7 * V_8 ,
unsigned int V_112 )
{
struct V_111 * V_113 , * V_114 , V_115 ;
unsigned long V_58 ;
F_63 ( & V_115 ) ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_64 (p, q, &ps->async_pending)
if ( V_112 == F_37 ( V_113 , struct V_46 , V_60 ) -> V_112 )
F_54 ( V_113 , & V_115 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_60 ( V_8 , & V_115 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
F_60 ( V_8 , & V_8 -> V_61 ) ;
}
static int F_66 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
return - V_28 ;
}
static void F_67 ( struct V_116 * V_117 )
{
struct V_7 * V_8 = F_68 ( V_117 ) ;
unsigned int V_112 = V_117 -> V_120 -> V_45 . V_121 ;
if ( ! V_8 )
return;
if ( F_69 ( V_112 < 8 * sizeof( V_8 -> V_122 ) ) )
F_70 ( V_112 , & V_8 -> V_122 ) ;
else
F_71 ( & V_117 -> V_10 , L_16 ,
V_112 ) ;
F_72 ( V_117 , NULL ) ;
F_62 ( V_8 , V_112 ) ;
}
static int F_73 ( struct V_116 * V_117 , T_7 V_123 )
{
return 0 ;
}
static int F_74 ( struct V_116 * V_117 )
{
return 0 ;
}
static int F_75 ( struct V_7 * V_8 , unsigned int V_112 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_116 * V_117 ;
int V_29 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return - V_19 ;
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
return 0 ;
V_117 = F_77 ( V_10 , V_112 ) ;
if ( ! V_117 )
V_29 = - V_109 ;
else
V_29 = F_78 ( & V_124 , V_117 , V_8 ) ;
if ( V_29 == 0 )
F_79 ( V_112 , & V_8 -> V_122 ) ;
return V_29 ;
}
static int F_80 ( struct V_7 * V_8 , unsigned int V_112 )
{
struct V_24 * V_10 ;
struct V_116 * V_117 ;
int V_29 ;
V_29 = - V_19 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return V_29 ;
V_10 = V_8 -> V_10 ;
V_117 = F_77 ( V_10 , V_112 ) ;
if ( ! V_117 )
V_29 = - V_109 ;
else if ( F_81 ( V_112 , & V_8 -> V_122 ) ) {
F_82 ( & V_124 , V_117 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_83 ( struct V_7 * V_8 , unsigned int V_112 )
{
if ( V_8 -> V_10 -> V_11 != V_125 )
return - V_126 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return - V_19 ;
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
return 0 ;
F_71 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_84 ( V_127 ) ,
V_127 -> V_128 , V_112 ) ;
return F_75 ( V_8 , V_112 ) ;
}
static int F_85 ( struct V_24 * V_10 , unsigned int V_74 )
{
unsigned int V_27 , V_129 , V_130 ;
struct V_116 * V_117 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
if ( V_74 & ~ ( V_135 | 0xf ) )
return - V_19 ;
if ( ! V_10 -> V_136 )
return - V_137 ;
for ( V_27 = 0 ; V_27 < V_10 -> V_136 -> V_45 . V_138 ; V_27 ++ ) {
V_117 = V_10 -> V_136 -> V_139 [ V_27 ] ;
for ( V_129 = 0 ; V_129 < V_117 -> V_140 ; V_129 ++ ) {
V_132 = & V_117 -> V_120 [ V_129 ] ;
for ( V_130 = 0 ; V_130 < V_132 -> V_45 . V_141 ; V_130 ++ ) {
V_134 = & V_132 -> V_142 [ V_130 ] . V_45 ;
if ( V_134 -> V_143 == V_74 )
return V_132 -> V_45 . V_121 ;
}
}
}
return - V_109 ;
}
static int F_86 ( struct V_7 * V_8 , unsigned int V_144 ,
unsigned int V_145 , unsigned int V_146 )
{
int V_16 = 0 ;
struct V_131 * V_147 ;
if ( V_8 -> V_10 -> V_11 != V_148
&& V_8 -> V_10 -> V_11 != V_149
&& V_8 -> V_10 -> V_11 != V_125 )
return - V_126 ;
if ( V_150 == ( V_151 & V_144 ) )
return 0 ;
if ( V_144 == 0xa1 && V_145 == 0 ) {
V_147 = F_87 ( V_8 -> V_10 -> V_136 ,
V_146 >> 8 , V_146 & 0xff ) ;
if ( V_147
&& V_147 -> V_45 . V_152 == V_153 )
return 0 ;
}
V_146 &= 0xff ;
switch ( V_144 & V_154 ) {
case V_155 :
if ( ( V_146 & ~ V_135 ) == 0 )
return 0 ;
V_16 = F_85 ( V_8 -> V_10 , V_146 ) ;
if ( V_16 < 0 ) {
V_16 = F_85 ( V_8 -> V_10 , V_146 ^ 0x80 ) ;
if ( V_16 >= 0 )
F_44 ( & V_8 -> V_10 -> V_10 ,
L_19 ,
V_156 , F_84 ( V_127 ) ,
V_127 -> V_128 , V_146 , V_146 ^ 0x80 ) ;
}
if ( V_16 >= 0 )
V_16 = F_83 ( V_8 , V_16 ) ;
break;
case V_157 :
V_16 = F_83 ( V_8 , V_146 ) ;
break;
}
return V_16 ;
}
static struct V_158 * F_88 ( struct V_24 * V_10 ,
unsigned char V_74 )
{
if ( V_74 & V_159 )
return V_10 -> V_160 [ V_74 & V_161 ] ;
else
return V_10 -> V_162 [ V_74 & V_161 ] ;
}
static int F_89 ( struct V_7 * V_8 ,
struct V_163 T_3 * V_164 ,
unsigned int * V_165 ,
unsigned int * V_166 ,
struct V_158 * * * V_167 ,
struct V_116 * * V_168 )
{
unsigned int V_27 , V_169 , V_170 ;
struct V_158 * * V_171 ;
struct V_116 * V_117 = NULL ;
unsigned char V_74 ;
int V_112 , V_16 ;
if ( F_90 ( V_169 , & V_164 -> V_169 ) ||
F_90 ( V_170 , & V_164 -> V_170 ) )
return - V_37 ;
if ( V_170 < 1 || V_170 > V_172 )
return - V_19 ;
if ( V_165 && ( V_169 < 2 || V_169 > 65536 ) )
return - V_19 ;
V_171 = F_91 ( V_170 * sizeof( * V_171 ) , V_49 ) ;
if ( ! V_171 )
return - V_6 ;
for ( V_27 = 0 ; V_27 < V_170 ; V_27 ++ ) {
if ( F_90 ( V_74 , & V_164 -> V_171 [ V_27 ] ) ) {
V_16 = - V_37 ;
goto error;
}
V_171 [ V_27 ] = F_88 ( V_8 -> V_10 , V_74 ) ;
if ( ! V_171 [ V_27 ] ) {
V_16 = - V_19 ;
goto error;
}
V_112 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_112 < 0 ) {
V_16 = V_112 ;
goto error;
}
if ( V_27 == 0 ) {
V_16 = F_83 ( V_8 , V_112 ) ;
if ( V_16 < 0 )
goto error;
V_117 = F_77 ( V_8 -> V_10 , V_112 ) ;
} else {
if ( V_112 != V_117 -> V_120 -> V_45 . V_121 ) {
V_16 = - V_19 ;
goto error;
}
}
}
if ( V_165 )
* V_165 = V_169 ;
* V_166 = V_170 ;
* V_167 = V_171 ;
* V_168 = V_117 ;
return 0 ;
error:
F_23 ( V_171 ) ;
return V_16 ;
}
static int F_92 ( struct V_173 * V_10 , void * V_70 )
{
return V_10 -> V_174 == ( V_175 ) ( unsigned long ) V_70 ;
}
static struct V_24 * F_93 ( V_175 V_174 )
{
struct V_173 * V_10 ;
V_10 = F_94 ( & V_176 , NULL ,
( void * ) ( unsigned long ) V_174 , F_92 ) ;
if ( ! V_10 )
return NULL ;
return F_95 ( V_10 , struct V_24 , V_10 ) ;
}
static int F_96 ( struct V_177 * V_177 , struct V_13 * V_13 )
{
struct V_24 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_91 ( sizeof( struct V_7 ) , V_49 ) ;
if ( ! V_8 )
goto V_178;
V_16 = - V_28 ;
F_10 ( & V_179 ) ;
if ( F_97 ( V_177 ) == V_180 )
V_10 = F_93 ( V_177 -> V_181 ) ;
F_12 ( & V_179 ) ;
if ( ! V_10 )
goto V_178;
F_14 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_182;
V_16 = F_98 ( V_10 ) ;
if ( V_16 )
goto V_182;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_99 ( & V_8 -> V_59 ) ;
F_63 ( & V_8 -> V_9 ) ;
F_63 ( & V_8 -> V_61 ) ;
F_63 ( & V_8 -> V_62 ) ;
F_100 ( & V_8 -> V_110 ) ;
V_8 -> V_183 = 0 ;
V_8 -> V_184 = F_55 ( F_101 ( V_127 ) ) ;
V_8 -> V_52 = F_102 () ;
V_8 -> V_185 = NULL ;
V_8 -> V_122 = 0 ;
F_103 ( V_127 , & V_8 -> V_96 ) ;
F_104 () ;
F_32 ( & V_8 -> V_9 , & V_10 -> V_186 ) ;
V_13 -> V_23 = V_8 ;
F_19 ( V_10 ) ;
F_57 ( & V_10 -> V_10 , L_20 , F_84 ( V_127 ) ,
V_127 -> V_128 ) ;
return V_16 ;
V_182:
F_19 ( V_10 ) ;
F_105 ( V_10 ) ;
V_178:
F_23 ( V_8 ) ;
return V_16 ;
}
static int F_106 ( struct V_177 * V_177 , struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_24 * V_10 = V_8 -> V_10 ;
unsigned int V_112 ;
struct V_46 * V_48 ;
F_14 ( V_10 ) ;
F_107 ( V_10 , V_8 ) ;
F_35 ( & V_8 -> V_9 ) ;
for ( V_112 = 0 ; V_8 -> V_122 && V_112 < 8 * sizeof( V_8 -> V_122 ) ;
V_112 ++ ) {
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
F_80 ( V_8 , V_112 ) ;
}
F_65 ( V_8 ) ;
F_108 ( V_10 ) ;
F_19 ( V_10 ) ;
F_105 ( V_10 ) ;
F_25 ( V_8 -> V_184 ) ;
F_26 ( V_8 -> V_52 ) ;
V_48 = F_36 ( V_8 ) ;
while ( V_48 ) {
F_24 ( V_48 ) ;
V_48 = F_36 ( V_8 ) ;
}
F_23 ( V_8 ) ;
return 0 ;
}
static int F_109 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_188 V_189 ;
unsigned int V_190 ;
unsigned char * V_191 ;
unsigned V_192 ;
int V_27 , V_66 , V_16 ;
if ( F_110 ( & V_189 , V_187 , sizeof( V_189 ) ) )
return - V_37 ;
V_16 = F_86 ( V_8 , V_189 . V_193 , V_189 . V_194 ,
V_189 . V_195 ) ;
if ( V_16 )
return V_16 ;
V_192 = V_189 . V_192 ;
if ( V_192 > V_196 )
return - V_19 ;
V_16 = F_1 ( V_196 + sizeof( struct V_50 ) +
sizeof( struct V_197 ) ) ;
if ( V_16 )
return V_16 ;
V_191 = ( unsigned char * ) F_111 ( V_49 ) ;
if ( ! V_191 ) {
V_16 = - V_6 ;
goto V_198;
}
V_190 = V_189 . V_199 ;
F_57 ( & V_10 -> V_10 , L_21
L_22
L_23 ,
V_189 . V_193 , V_189 . V_194 , V_189 . V_200 ,
V_189 . V_195 , V_189 . V_192 ) ;
if ( V_189 . V_193 & 0x80 ) {
if ( V_189 . V_192 && ! F_112 ( V_201 , V_189 . V_70 ,
V_189 . V_192 ) ) {
V_16 = - V_19 ;
goto V_198;
}
V_66 = F_113 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_189 . V_192 , V_190 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_114 ( V_10 , V_66 , V_189 . V_194 ,
V_189 . V_193 , V_189 . V_200 , V_189 . V_195 ,
V_191 , V_189 . V_192 , V_190 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_115 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 ,
V_191 , F_115 ( V_27 , 0 ) ) ;
if ( ( V_27 > 0 ) && V_189 . V_192 ) {
if ( F_16 ( V_189 . V_70 , V_191 , V_27 ) ) {
V_16 = - V_37 ;
goto V_198;
}
}
} else {
if ( V_189 . V_192 ) {
if ( F_110 ( V_191 , V_189 . V_70 , V_189 . V_192 ) ) {
V_16 = - V_37 ;
goto V_198;
}
}
V_66 = F_116 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_189 . V_192 , V_190 , V_78 ,
V_191 , V_189 . V_192 ) ;
F_19 ( V_10 ) ;
V_27 = F_114 ( V_10 , F_116 ( V_10 , 0 ) , V_189 . V_194 ,
V_189 . V_193 , V_189 . V_200 , V_189 . V_195 ,
V_191 , V_189 . V_192 , V_190 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_115 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 , NULL , 0 ) ;
}
if ( V_27 < 0 && V_27 != - V_202 ) {
F_117 ( V_79 , & V_10 -> V_10 , L_24
L_25 ,
V_127 -> V_128 , V_189 . V_193 , V_189 . V_194 ,
V_189 . V_192 , V_27 ) ;
}
V_16 = V_27 ;
V_198:
F_118 ( ( unsigned long ) V_191 ) ;
F_6 ( V_196 + sizeof( struct V_50 ) +
sizeof( struct V_197 ) ) ;
return V_16 ;
}
static int F_119 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_203 V_204 ;
unsigned int V_190 , V_205 , V_66 ;
int V_206 ;
unsigned char * V_191 ;
int V_27 , V_16 ;
if ( F_110 ( & V_204 , V_187 , sizeof( V_204 ) ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_204 . V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_204 . V_74 & V_135 )
V_66 = F_120 ( V_10 , V_204 . V_74 & 0x7f ) ;
else
V_66 = F_121 ( V_10 , V_204 . V_74 & 0x7f ) ;
if ( ! F_122 ( V_10 , V_66 , ! ( V_204 . V_74 & V_135 ) ) )
return - V_19 ;
V_205 = V_204 . V_25 ;
if ( V_205 >= V_4 )
return - V_19 ;
V_16 = F_1 ( V_205 + sizeof( struct V_50 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_191 = F_91 ( V_205 , V_49 ) ) ) {
V_16 = - V_6 ;
goto V_198;
}
V_190 = V_204 . V_199 ;
if ( V_204 . V_74 & 0x80 ) {
if ( V_205 && ! F_112 ( V_201 , V_204 . V_70 , V_205 ) ) {
V_16 = - V_19 ;
goto V_198;
}
F_40 ( V_10 , NULL , V_66 , V_205 , V_190 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_123 ( V_10 , V_66 , V_191 , V_205 , & V_206 , V_190 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_206 , V_27 , V_104 , V_191 , V_206 ) ;
if ( ! V_27 && V_206 ) {
if ( F_16 ( V_204 . V_70 , V_191 , V_206 ) ) {
V_16 = - V_37 ;
goto V_198;
}
}
} else {
if ( V_205 ) {
if ( F_110 ( V_191 , V_204 . V_70 , V_205 ) ) {
V_16 = - V_37 ;
goto V_198;
}
}
F_40 ( V_10 , NULL , V_66 , V_205 , V_190 , V_78 , V_191 , V_205 ) ;
F_19 ( V_10 ) ;
V_27 = F_123 ( V_10 , V_66 , V_191 , V_205 , & V_206 , V_190 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_206 , V_27 , V_104 , NULL , 0 ) ;
}
V_16 = ( V_27 < 0 ? V_27 : V_206 ) ;
V_198:
F_23 ( V_191 ) ;
F_6 ( V_205 + sizeof( struct V_50 ) ) ;
return V_16 ;
}
static void F_124 ( struct V_24 * V_65 ,
unsigned int V_207 , char * V_208 )
{
struct V_158 * * V_171 ;
struct V_158 * V_74 ;
V_171 = ( V_207 & V_135 ) ? V_65 -> V_160 : V_65 -> V_162 ;
V_74 = V_171 [ V_207 & 0x0f ] ;
if ( V_74 && ! F_8 ( & V_74 -> V_209 ) )
F_71 ( & V_65 -> V_10 , L_26 ,
F_84 ( V_127 ) , V_127 -> V_128 ,
V_208 , V_207 ) ;
}
static int F_125 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned int V_74 ;
int V_16 ;
if ( F_90 ( V_74 , ( unsigned int T_3 * ) V_187 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_124 ( V_8 -> V_10 , V_74 , L_27 ) ;
F_126 ( V_8 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_127 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned int V_74 ;
int V_66 ;
int V_16 ;
if ( F_90 ( V_74 , ( unsigned int T_3 * ) V_187 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_124 ( V_8 -> V_10 , V_74 , L_28 ) ;
if ( V_74 & V_135 )
V_66 = F_120 ( V_8 -> V_10 , V_74 & 0x7f ) ;
else
V_66 = F_121 ( V_8 -> V_10 , V_74 & 0x7f ) ;
return F_128 ( V_8 -> V_10 , V_66 ) ;
}
static int F_129 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_210 V_211 ;
struct V_116 * V_117 ;
int V_16 ;
if ( F_110 ( & V_211 , V_187 , sizeof( V_211 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_211 . V_139 ) ;
if ( ! V_117 || ! V_117 -> V_10 . V_212 )
V_16 = - V_213 ;
else {
F_130 ( V_211 . V_212 , V_117 -> V_10 . V_212 -> V_214 ,
sizeof( V_211 . V_212 ) ) ;
V_16 = ( F_16 ( V_187 , & V_211 , sizeof( V_211 ) ) ? - V_37 : 0 ) ;
}
return V_16 ;
}
static int F_131 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_215 V_216 = {
. V_217 = V_8 -> V_10 -> V_217 ,
. V_218 = V_8 -> V_10 -> V_219 == V_220
} ;
if ( F_16 ( V_187 , & V_216 , sizeof( V_216 ) ) )
return - V_37 ;
return 0 ;
}
static int F_132 ( struct V_7 * V_8 )
{
return F_133 ( V_8 -> V_10 ) ;
}
static int F_134 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_221 V_222 ;
int V_16 ;
if ( F_110 ( & V_222 , V_187 , sizeof( V_222 ) ) )
return - V_37 ;
if ( ( V_16 = F_83 ( V_8 , V_222 . V_139 ) ) )
return V_16 ;
F_62 ( V_8 , V_222 . V_139 ) ;
return F_135 ( V_8 -> V_10 , V_222 . V_139 ,
V_222 . V_120 ) ;
}
static int F_136 ( struct V_7 * V_8 , void T_3 * V_187 )
{
int V_223 ;
int V_98 = 0 ;
struct V_224 * V_136 ;
if ( F_90 ( V_223 , ( int T_3 * ) V_187 ) )
return - V_37 ;
V_136 = V_8 -> V_10 -> V_136 ;
if ( V_136 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < V_136 -> V_45 . V_138 ; ++ V_27 ) {
if ( F_137 ( V_136 -> V_139 [ V_27 ] ) ) {
F_71 ( & V_8 -> V_10 -> V_10 ,
L_29
L_30 ,
V_136 -> V_139 [ V_27 ]
-> V_225
-> V_45 . V_121 ,
V_136 -> V_139 [ V_27 ]
-> V_10 . V_212 -> V_214 ,
V_127 -> V_128 , V_223 ) ;
V_98 = - V_226 ;
break;
}
}
}
if ( V_98 == 0 ) {
if ( V_136 && V_136 -> V_45 . V_227 == V_223 )
V_98 = F_138 ( V_8 -> V_10 ) ;
else
V_98 = F_139 ( V_8 -> V_10 , V_223 ) ;
}
return V_98 ;
}
static int F_140 ( struct V_7 * V_8 , struct V_228 * V_229 ,
struct V_230 T_3 * V_231 ,
void T_3 * V_187 )
{
struct V_230 * V_232 = NULL ;
struct V_158 * V_74 ;
struct V_46 * V_48 = NULL ;
struct V_197 * V_233 = NULL ;
unsigned int V_223 , V_234 , V_235 ;
int V_27 , V_16 , V_236 , V_53 = 0 , V_112 = - 1 ;
int V_84 = 0 ;
unsigned int V_237 = 0 ;
void * V_20 ;
if ( V_229 -> V_58 & ~ ( V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_243 ) )
return - V_19 ;
if ( V_229 -> V_244 > 0 && ! V_229 -> V_245 )
return - V_19 ;
if ( ! ( V_229 -> type == V_246 &&
( V_229 -> V_142 & ~ V_159 ) == 0 ) ) {
V_112 = F_85 ( V_8 -> V_10 , V_229 -> V_142 ) ;
if ( V_112 < 0 )
return V_112 ;
V_16 = F_83 ( V_8 , V_112 ) ;
if ( V_16 )
return V_16 ;
}
V_74 = F_88 ( V_8 -> V_10 , V_229 -> V_142 ) ;
if ( ! V_74 )
return - V_109 ;
V_236 = ( V_229 -> V_142 & V_159 ) != 0 ;
V_223 = 0 ;
switch( V_229 -> type ) {
case V_246 :
if ( ! F_141 ( & V_74 -> V_45 ) )
return - V_19 ;
if ( V_229 -> V_244 < 8 )
return - V_19 ;
V_233 = F_91 ( sizeof( struct V_197 ) , V_49 ) ;
if ( ! V_233 )
return - V_6 ;
if ( F_110 ( V_233 , V_229 -> V_245 , 8 ) ) {
V_16 = - V_37 ;
goto error;
}
if ( V_229 -> V_244 < ( F_142 ( & V_233 -> V_192 ) + 8 ) ) {
V_16 = - V_19 ;
goto error;
}
V_16 = F_86 ( V_8 , V_233 -> V_193 , V_233 -> V_194 ,
F_142 ( & V_233 -> V_195 ) ) ;
if ( V_16 )
goto error;
V_229 -> V_244 = F_142 ( & V_233 -> V_192 ) ;
V_229 -> V_245 += 8 ;
if ( ( V_233 -> V_193 & V_135 ) && V_229 -> V_244 ) {
V_236 = 1 ;
V_229 -> V_142 |= V_135 ;
} else {
V_236 = 0 ;
V_229 -> V_142 &= ~ V_135 ;
}
F_57 ( & V_8 -> V_10 -> V_10 , L_21
L_22
L_23 ,
V_233 -> V_193 , V_233 -> V_194 ,
F_143 ( & V_233 -> V_200 ) ,
F_143 ( & V_233 -> V_195 ) ,
F_143 ( & V_233 -> V_192 ) ) ;
V_223 = sizeof( struct V_197 ) ;
break;
case V_247 :
switch ( F_144 ( & V_74 -> V_45 ) ) {
case V_248 :
case V_249 :
return - V_19 ;
case V_250 :
V_229 -> type = V_251 ;
goto V_252;
}
V_53 = F_145 ( V_229 -> V_244 , V_82 ) ;
if ( V_53 == 1 || V_53 > V_8 -> V_10 -> V_253 -> V_254 )
V_53 = 0 ;
if ( V_74 -> V_164 )
V_237 = V_229 -> V_237 ;
break;
case V_251 :
if ( ! F_146 ( & V_74 -> V_45 ) )
return - V_19 ;
V_252:
break;
case V_255 :
if ( V_229 -> V_84 < 1 ||
V_229 -> V_84 > 128 )
return - V_19 ;
if ( ! F_147 ( & V_74 -> V_45 ) )
return - V_19 ;
V_84 = V_229 -> V_84 ;
V_235 = sizeof( struct V_230 ) *
V_84 ;
if ( ! ( V_232 = F_91 ( V_235 , V_49 ) ) )
return - V_6 ;
if ( F_110 ( V_232 , V_231 , V_235 ) ) {
V_16 = - V_37 ;
goto error;
}
for ( V_234 = V_223 = 0 ; V_223 < V_84 ; V_223 ++ ) {
if ( V_232 [ V_223 ] . V_42 > 49152 ) {
V_16 = - V_19 ;
goto error;
}
V_234 += V_232 [ V_223 ] . V_42 ;
}
V_223 *= sizeof( struct V_256 ) ;
V_229 -> V_244 = V_234 ;
break;
default:
return - V_19 ;
}
if ( V_229 -> V_244 >= V_4 ) {
V_16 = - V_19 ;
goto error;
}
if ( V_229 -> V_244 > 0 &&
! F_112 ( V_236 ? V_201 : V_257 ,
V_229 -> V_245 , V_229 -> V_244 ) ) {
V_16 = - V_37 ;
goto error;
}
V_48 = F_20 ( V_84 ) ;
if ( ! V_48 ) {
V_16 = - V_6 ;
goto error;
}
V_223 += sizeof( struct V_46 ) + sizeof( struct V_50 ) + V_229 -> V_244 +
V_53 * sizeof( struct V_258 ) ;
V_16 = F_1 ( V_223 ) ;
if ( V_16 )
goto error;
V_48 -> V_57 = V_223 ;
if ( V_53 ) {
V_48 -> V_50 -> V_54 = F_91 ( V_53 * sizeof( struct V_258 ) ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_54 ) {
V_16 = - V_6 ;
goto error;
}
V_48 -> V_50 -> V_53 = V_53 ;
F_148 ( V_48 -> V_50 -> V_54 , V_48 -> V_50 -> V_53 ) ;
V_234 = V_229 -> V_244 ;
for ( V_27 = 0 ; V_27 < V_48 -> V_50 -> V_53 ; V_27 ++ ) {
V_223 = ( V_234 > V_82 ) ? V_82 : V_234 ;
V_20 = F_91 ( V_223 , V_49 ) ;
if ( ! V_20 ) {
V_16 = - V_6 ;
goto error;
}
F_149 ( & V_48 -> V_50 -> V_54 [ V_27 ] , V_20 , V_223 ) ;
if ( ! V_236 ) {
if ( F_110 ( V_20 , V_229 -> V_245 , V_223 ) ) {
V_16 = - V_37 ;
goto error;
}
V_229 -> V_245 += V_223 ;
}
V_234 -= V_223 ;
}
} else if ( V_229 -> V_244 > 0 ) {
V_48 -> V_50 -> V_55 = F_91 ( V_229 -> V_244 ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_55 ) {
V_16 = - V_6 ;
goto error;
}
if ( ! V_236 ) {
if ( F_110 ( V_48 -> V_50 -> V_55 ,
V_229 -> V_245 ,
V_229 -> V_244 ) ) {
V_16 = - V_37 ;
goto error;
}
} else if ( V_229 -> type == V_255 ) {
memset ( V_48 -> V_50 -> V_55 , 0 ,
V_229 -> V_244 ) ;
}
}
V_48 -> V_50 -> V_10 = V_8 -> V_10 ;
V_48 -> V_50 -> V_66 = ( V_229 -> type << 30 ) |
F_150 ( V_8 -> V_10 , V_229 -> V_142 & 0xf ) |
( V_229 -> V_142 & V_135 ) ;
V_223 = ( V_236 ? V_107 : V_259 ) ;
if ( V_229 -> V_58 & V_238 )
V_223 |= V_260 ;
if ( V_229 -> V_58 & V_239 && V_236 )
V_223 |= V_261 ;
if ( V_229 -> V_58 & V_241 )
V_223 |= V_262 ;
if ( V_229 -> V_58 & V_242 )
V_223 |= V_263 ;
if ( V_229 -> V_58 & V_243 )
V_223 |= V_264 ;
V_48 -> V_50 -> V_105 = V_223 ;
V_48 -> V_50 -> V_85 = V_229 -> V_244 ;
V_48 -> V_50 -> V_56 = ( unsigned char * ) V_233 ;
V_233 = NULL ;
V_48 -> V_50 -> V_265 = V_229 -> V_265 ;
V_48 -> V_50 -> V_84 = V_84 ;
V_48 -> V_50 -> V_237 = V_237 ;
if ( V_229 -> type == V_255 ||
V_8 -> V_10 -> V_219 == V_266 )
V_48 -> V_50 -> V_267 = 1 << F_18 ( 15 , V_74 -> V_45 . V_268 - 1 ) ;
else
V_48 -> V_50 -> V_267 = V_74 -> V_45 . V_268 ;
V_48 -> V_50 -> V_93 = V_48 ;
V_48 -> V_50 -> V_269 = V_62 ;
for ( V_234 = V_223 = 0 ; V_223 < V_84 ; V_223 ++ ) {
V_48 -> V_50 -> V_231 [ V_223 ] . V_14 = V_234 ;
V_48 -> V_50 -> V_231 [ V_223 ] . V_42 = V_232 [ V_223 ] . V_42 ;
V_234 += V_232 [ V_223 ] . V_42 ;
}
F_23 ( V_232 ) ;
V_232 = NULL ;
V_48 -> V_8 = V_8 ;
V_48 -> V_64 = V_187 ;
if ( V_236 && V_229 -> V_244 > 0 )
V_48 -> V_83 = V_229 -> V_245 ;
else
V_48 -> V_83 = NULL ;
V_48 -> V_97 = V_229 -> V_97 ;
V_48 -> V_112 = V_112 ;
V_48 -> V_51 = F_55 ( F_101 ( V_127 ) ) ;
V_48 -> V_52 = F_102 () ;
F_103 ( V_127 , & V_48 -> V_96 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
V_48 -> V_50 -> V_85 , 0 , V_78 ,
NULL , 0 ) ;
if ( ! V_236 )
F_46 ( V_48 -> V_50 , V_48 -> V_50 -> V_85 ) ;
F_30 ( V_48 ) ;
if ( F_151 ( & V_74 -> V_45 ) ) {
F_152 ( & V_8 -> V_59 ) ;
V_48 -> V_87 = F_153 ( & V_74 -> V_45 ) |
( ( V_74 -> V_45 . V_143 & V_159 )
>> 3 ) ;
if ( V_229 -> V_58 & V_240 )
V_48 -> V_88 = V_89 ;
else
V_8 -> V_92 &= ~ ( 1 << V_48 -> V_87 ) ;
if ( V_8 -> V_92 & ( 1 << V_48 -> V_87 ) )
V_16 = - V_270 ;
else
V_16 = F_154 ( V_48 -> V_50 , V_271 ) ;
F_155 ( & V_8 -> V_59 ) ;
} else {
V_16 = F_154 ( V_48 -> V_50 , V_49 ) ;
}
if ( V_16 ) {
F_117 ( V_79 , & V_8 -> V_10 -> V_10 ,
L_31 , V_16 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
0 , V_16 , V_104 , NULL , 0 ) ;
F_34 ( V_48 ) ;
goto error;
}
return 0 ;
error:
F_23 ( V_232 ) ;
F_23 ( V_233 ) ;
if ( V_48 )
F_24 ( V_48 ) ;
return V_16 ;
}
static int F_156 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_228 V_229 ;
if ( F_110 ( & V_229 , V_187 , sizeof( V_229 ) ) )
return - V_37 ;
return F_140 ( V_8 , & V_229 ,
( ( (struct V_228 T_3 * ) V_187 ) -> V_231 ) ,
V_187 ) ;
}
static int F_157 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
V_48 = F_38 ( V_8 , V_187 ) ;
if ( ! V_48 ) {
F_33 ( & V_8 -> V_59 , V_58 ) ;
return - V_19 ;
}
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_61 ( V_50 ) ;
F_52 ( V_50 ) ;
return 0 ;
}
static int F_158 ( struct V_46 * V_48 , void T_3 * T_3 * V_187 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_228 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_272 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
goto V_273;
}
if ( F_159 ( V_48 -> V_98 , & V_64 -> V_98 ) )
goto V_273;
if ( F_159 ( V_50 -> V_86 , & V_64 -> V_86 ) )
goto V_273;
if ( F_159 ( V_50 -> V_274 , & V_64 -> V_274 ) )
goto V_273;
if ( F_147 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_159 ( V_50 -> V_231 [ V_27 ] . V_86 ,
& V_64 -> V_231 [ V_27 ] . V_86 ) )
goto V_273;
if ( F_159 ( V_50 -> V_231 [ V_27 ] . V_98 ,
& V_64 -> V_231 [ V_27 ] . V_98 ) )
goto V_273;
}
}
if ( F_159 ( V_272 , ( void T_3 * T_3 * ) V_187 ) )
return - V_37 ;
return 0 ;
V_273:
return - V_37 ;
}
static struct V_46 * F_160 ( struct V_7 * V_8 )
{
F_161 ( V_110 , V_127 ) ;
struct V_46 * V_48 = NULL ;
struct V_24 * V_10 = V_8 -> V_10 ;
F_162 ( & V_8 -> V_110 , & V_110 ) ;
for (; ; ) {
F_163 ( V_275 ) ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 || ! F_7 ( V_8 ) )
break;
if ( F_164 ( V_127 ) )
break;
F_19 ( V_10 ) ;
F_165 () ;
F_14 ( V_10 ) ;
}
F_166 ( & V_8 -> V_110 , & V_110 ) ;
F_167 ( V_276 ) ;
return V_48 ;
}
static int F_168 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_46 * V_48 = F_160 ( V_8 ) ;
if ( V_48 ) {
int V_277 = F_158 ( V_48 , ( void T_3 * T_3 * ) V_187 ) ;
F_24 ( V_48 ) ;
return V_277 ;
}
if ( F_164 ( V_127 ) )
return - V_278 ;
return - V_28 ;
}
static int F_169 ( struct V_7 * V_8 , void T_3 * V_187 )
{
int V_277 ;
struct V_46 * V_48 ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 ) {
V_277 = F_158 ( V_48 , ( void T_3 * T_3 * ) V_187 ) ;
F_24 ( V_48 ) ;
} else {
V_277 = ( F_7 ( V_8 ) ? - V_279 : - V_28 ) ;
}
return V_277 ;
}
static int F_170 ( struct V_7 * V_8 ,
struct V_280 T_3 * V_281 )
{
struct V_188 T_3 * V_113 ;
T_8 V_282 ;
V_113 = F_171 ( sizeof( * V_113 ) ) ;
if ( F_172 ( V_113 , V_281 , ( sizeof( * V_281 ) - sizeof( V_283 ) ) ) ||
F_90 ( V_282 , & V_281 -> V_70 ) ||
F_159 ( F_173 ( V_282 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_109 ( V_8 , V_113 ) ;
}
static int F_174 ( struct V_7 * V_8 ,
struct V_284 T_3 * V_281 )
{
struct V_203 T_3 * V_113 ;
T_9 V_285 ;
V_283 V_272 ;
V_113 = F_171 ( sizeof( * V_113 ) ) ;
if ( F_90 ( V_285 , & V_281 -> V_74 ) || F_159 ( V_285 , & V_113 -> V_74 ) ||
F_90 ( V_285 , & V_281 -> V_25 ) || F_159 ( V_285 , & V_113 -> V_25 ) ||
F_90 ( V_285 , & V_281 -> V_199 ) || F_159 ( V_285 , & V_113 -> V_199 ) ||
F_90 ( V_272 , & V_281 -> V_70 ) || F_159 ( F_173 ( V_272 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_119 ( V_8 , V_113 ) ;
}
static int F_175 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_286 V_287 ;
if ( F_110 ( & V_287 , V_187 , sizeof( V_287 ) ) )
return - V_37 ;
V_8 -> V_183 = V_287 . V_97 ;
V_8 -> V_185 = F_173 ( V_287 . V_93 ) ;
return 0 ;
}
static int F_176 ( struct V_228 * V_288 ,
struct V_289 T_3 * V_229 )
{
T_8 V_290 ;
if ( ! F_112 ( V_257 , V_229 , sizeof( * V_229 ) ) ||
F_177 ( V_288 -> type , & V_229 -> type ) ||
F_177 ( V_288 -> V_142 , & V_229 -> V_142 ) ||
F_177 ( V_288 -> V_98 , & V_229 -> V_98 ) ||
F_177 ( V_288 -> V_58 , & V_229 -> V_58 ) ||
F_177 ( V_288 -> V_244 , & V_229 -> V_244 ) ||
F_177 ( V_288 -> V_86 , & V_229 -> V_86 ) ||
F_177 ( V_288 -> V_265 , & V_229 -> V_265 ) ||
F_177 ( V_288 -> V_84 , & V_229 -> V_84 ) ||
F_177 ( V_288 -> V_274 , & V_229 -> V_274 ) ||
F_177 ( V_288 -> V_97 , & V_229 -> V_97 ) )
return - V_37 ;
if ( F_177 ( V_290 , & V_229 -> V_245 ) )
return - V_37 ;
V_288 -> V_245 = F_173 ( V_290 ) ;
if ( F_177 ( V_290 , & V_229 -> V_291 ) )
return - V_37 ;
V_288 -> V_291 = F_173 ( V_290 ) ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_228 V_229 ;
if ( F_176 ( & V_229 , (struct V_289 T_3 * ) V_187 ) )
return - V_37 ;
return F_140 ( V_8 , & V_229 ,
( (struct V_289 T_3 * ) V_187 ) -> V_231 ,
V_187 ) ;
}
static int F_179 ( struct V_46 * V_48 , void T_3 * T_3 * V_187 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_289 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_272 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
return - V_37 ;
}
if ( F_159 ( V_48 -> V_98 , & V_64 -> V_98 ) )
return - V_37 ;
if ( F_159 ( V_50 -> V_86 , & V_64 -> V_86 ) )
return - V_37 ;
if ( F_159 ( V_50 -> V_274 , & V_64 -> V_274 ) )
return - V_37 ;
if ( F_147 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_159 ( V_50 -> V_231 [ V_27 ] . V_86 ,
& V_64 -> V_231 [ V_27 ] . V_86 ) )
return - V_37 ;
if ( F_159 ( V_50 -> V_231 [ V_27 ] . V_98 ,
& V_64 -> V_231 [ V_27 ] . V_98 ) )
return - V_37 ;
}
}
if ( F_159 ( F_180 ( V_272 ) , ( T_6 T_3 * ) V_187 ) )
return - V_37 ;
return 0 ;
}
static int F_181 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_46 * V_48 = F_160 ( V_8 ) ;
if ( V_48 ) {
int V_277 = F_179 ( V_48 , ( void T_3 * T_3 * ) V_187 ) ;
F_24 ( V_48 ) ;
return V_277 ;
}
if ( F_164 ( V_127 ) )
return - V_278 ;
return - V_28 ;
}
static int F_182 ( struct V_7 * V_8 , void T_3 * V_187 )
{
int V_277 ;
struct V_46 * V_48 ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 ) {
V_277 = F_179 ( V_48 , ( void T_3 * T_3 * ) V_187 ) ;
F_24 ( V_48 ) ;
} else {
V_277 = ( F_7 ( V_8 ) ? - V_279 : - V_28 ) ;
}
return V_277 ;
}
static int F_183 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_292 V_287 ;
if ( F_110 ( & V_287 , V_187 , sizeof( V_287 ) ) )
return - V_37 ;
V_8 -> V_183 = V_287 . V_97 ;
V_8 -> V_185 = V_287 . V_93 ;
return 0 ;
}
static int F_184 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned int V_112 ;
if ( F_90 ( V_112 , ( unsigned int T_3 * ) V_187 ) )
return - V_37 ;
return F_75 ( V_8 , V_112 ) ;
}
static int F_185 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned int V_112 ;
int V_16 ;
if ( F_90 ( V_112 , ( unsigned int T_3 * ) V_187 ) )
return - V_37 ;
if ( ( V_16 = F_80 ( V_8 , V_112 ) ) < 0 )
return V_16 ;
F_62 ( V_8 , V_112 ) ;
return 0 ;
}
static int F_186 ( struct V_7 * V_8 , struct V_293 * V_294 )
{
int V_81 ;
void * V_20 = NULL ;
int V_277 = 0 ;
struct V_116 * V_117 = NULL ;
struct V_295 * V_212 = NULL ;
if ( ( V_81 = F_187 ( V_294 -> V_296 ) ) > 0 ) {
V_20 = F_91 ( V_81 , V_49 ) ;
if ( V_20 == NULL )
return - V_6 ;
if ( ( F_188 ( V_294 -> V_296 ) & V_297 ) ) {
if ( F_110 ( V_20 , V_294 -> V_70 , V_81 ) ) {
F_23 ( V_20 ) ;
return - V_37 ;
}
} else {
memset ( V_20 , 0 , V_81 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_23 ( V_20 ) ;
return - V_28 ;
}
if ( V_8 -> V_10 -> V_11 != V_125 )
V_277 = - V_126 ;
else if ( ! ( V_117 = F_77 ( V_8 -> V_10 , V_294 -> V_298 ) ) )
V_277 = - V_19 ;
else switch ( V_294 -> V_296 ) {
case V_299 :
if ( V_117 -> V_10 . V_212 ) {
V_212 = F_189 ( V_117 -> V_10 . V_212 ) ;
F_190 ( & V_117 -> V_10 , L_32 ) ;
F_82 ( V_212 , V_117 ) ;
} else
V_277 = - V_213 ;
break;
case V_300 :
if ( ! V_117 -> V_10 . V_212 )
V_277 = F_191 ( & V_117 -> V_10 ) ;
else
V_277 = - V_226 ;
break;
default:
if ( V_117 -> V_10 . V_212 )
V_212 = F_189 ( V_117 -> V_10 . V_212 ) ;
if ( V_212 == NULL || V_212 -> V_301 == NULL ) {
V_277 = - V_302 ;
} else {
V_277 = V_212 -> V_301 ( V_117 , V_294 -> V_296 , V_20 ) ;
if ( V_277 == - V_303 )
V_277 = - V_302 ;
}
}
if ( V_277 >= 0
&& ( F_188 ( V_294 -> V_296 ) & V_304 ) != 0
&& V_81 > 0
&& F_16 ( V_294 -> V_70 , V_20 , V_81 ) != 0 )
V_277 = - V_37 ;
F_23 ( V_20 ) ;
return V_277 ;
}
static int F_192 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_293 V_189 ;
if ( F_110 ( & V_189 , V_187 , sizeof( V_189 ) ) )
return - V_37 ;
return F_186 ( V_8 , & V_189 ) ;
}
static int F_193 ( struct V_7 * V_8 , T_10 V_187 )
{
struct V_305 T_3 * V_306 ;
struct V_293 V_189 ;
T_6 V_282 ;
V_306 = F_173 ( ( long ) V_187 ) ;
if ( ! F_112 ( V_257 , V_306 , sizeof( * V_306 ) ) ||
F_177 ( V_189 . V_298 , & V_306 -> V_298 ) ||
F_177 ( V_189 . V_296 , & V_306 -> V_296 ) ||
F_177 ( V_282 , & V_306 -> V_70 ) )
return - V_37 ;
V_189 . V_70 = F_173 ( V_282 ) ;
return F_186 ( V_8 , & V_189 ) ;
}
static int F_194 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned V_307 ;
int V_308 ;
if ( F_90 ( V_307 , ( unsigned T_3 * ) V_187 ) )
return - V_37 ;
V_308 = F_195 ( V_8 -> V_10 , V_307 , V_8 ) ;
if ( V_308 == 0 )
F_57 ( & V_8 -> V_10 -> V_10 , L_33 ,
V_307 , F_84 ( V_127 ) , V_127 -> V_128 ) ;
return V_308 ;
}
static int F_196 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned V_307 ;
if ( F_90 ( V_307 , ( unsigned T_3 * ) V_187 ) )
return - V_37 ;
return F_197 ( V_8 -> V_10 , V_307 , V_8 ) ;
}
static int F_198 ( struct V_7 * V_8 , void T_3 * V_187 )
{
T_8 V_309 ;
V_309 = V_310 | V_311 |
V_312 ;
if ( ! V_8 -> V_10 -> V_253 -> V_313 )
V_309 |= V_314 ;
if ( V_8 -> V_10 -> V_253 -> V_254 )
V_309 |= V_315 ;
if ( F_159 ( V_309 , ( T_8 T_3 * ) V_187 ) )
return - V_37 ;
return 0 ;
}
static int F_199 ( struct V_7 * V_8 , void T_3 * V_187 )
{
struct V_316 V_317 ;
struct V_116 * V_117 ;
if ( F_110 ( & V_317 , V_187 , sizeof( V_317 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_317 . V_139 ) ;
if ( ! V_117 )
return - V_19 ;
if ( V_117 -> V_10 . V_212 ) {
struct V_295 * V_212 = F_189 ( V_117 -> V_10 . V_212 ) ;
if ( ( V_317 . V_58 & V_318 ) &&
strncmp ( V_317 . V_212 , V_117 -> V_10 . V_212 -> V_214 ,
sizeof( V_317 . V_212 ) ) != 0 )
return - V_226 ;
if ( ( V_317 . V_58 & V_319 ) &&
strncmp ( V_317 . V_212 , V_117 -> V_10 . V_212 -> V_214 ,
sizeof( V_317 . V_212 ) ) == 0 )
return - V_226 ;
F_190 ( & V_117 -> V_10 , L_32 ) ;
F_82 ( V_212 , V_117 ) ;
}
return F_75 ( V_8 , V_317 . V_139 ) ;
}
static int F_200 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned V_169 , V_170 ;
struct V_158 * * V_171 ;
struct V_116 * V_117 ;
int V_320 ;
V_320 = F_89 ( V_8 , V_187 , & V_169 , & V_170 ,
& V_171 , & V_117 ) ;
if ( V_320 )
return V_320 ;
F_62 ( V_8 ,
V_117 -> V_120 [ 0 ] . V_45 . V_121 ) ;
V_320 = F_201 ( V_117 , V_171 , V_170 , V_169 , V_49 ) ;
F_23 ( V_171 ) ;
return V_320 ;
}
static int F_202 ( struct V_7 * V_8 , void T_3 * V_187 )
{
unsigned V_170 ;
struct V_158 * * V_171 ;
struct V_116 * V_117 ;
int V_320 ;
V_320 = F_89 ( V_8 , V_187 , NULL , & V_170 , & V_171 , & V_117 ) ;
if ( V_320 )
return V_320 ;
F_62 ( V_8 ,
V_117 -> V_120 [ 0 ] . V_45 . V_121 ) ;
V_320 = F_203 ( V_117 , V_171 , V_170 , V_49 ) ;
F_23 ( V_171 ) ;
return V_320 ;
}
static long F_204 ( struct V_13 * V_13 , unsigned int V_321 ,
void T_3 * V_113 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_177 * V_177 = F_11 ( V_13 ) ;
struct V_24 * V_10 = V_8 -> V_10 ;
int V_16 = - V_302 ;
if ( ! ( V_13 -> V_322 & V_323 ) )
return - V_324 ;
F_14 ( V_10 ) ;
switch ( V_321 ) {
case V_325 :
F_57 ( & V_10 -> V_10 , L_34 , V_156 ) ;
V_16 = F_168 ( V_8 , V_113 ) ;
goto V_198;
case V_326 :
F_57 ( & V_10 -> V_10 , L_35 , V_156 ) ;
V_16 = F_169 ( V_8 , V_113 ) ;
goto V_198;
#ifdef F_205
case V_327 :
F_57 ( & V_10 -> V_10 , L_36 , V_156 ) ;
V_16 = F_181 ( V_8 , V_113 ) ;
goto V_198;
case V_328 :
F_57 ( & V_10 -> V_10 , L_37 , V_156 ) ;
V_16 = F_182 ( V_8 , V_113 ) ;
goto V_198;
#endif
}
if ( ! F_7 ( V_8 ) ) {
F_19 ( V_10 ) ;
return - V_28 ;
}
switch ( V_321 ) {
case V_329 :
F_57 ( & V_10 -> V_10 , L_38 , V_156 ) ;
V_16 = F_109 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_332 :
F_57 ( & V_10 -> V_10 , L_39 , V_156 ) ;
V_16 = F_119 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_333 :
F_57 ( & V_10 -> V_10 , L_40 , V_156 ) ;
V_16 = F_125 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_334 :
F_57 ( & V_10 -> V_10 , L_41 , V_156 ) ;
V_16 = F_132 ( V_8 ) ;
break;
case V_335 :
F_57 ( & V_10 -> V_10 , L_42 , V_156 ) ;
V_16 = F_127 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_336 :
F_57 ( & V_10 -> V_10 , L_43 , V_156 ) ;
V_16 = F_129 ( V_8 , V_113 ) ;
break;
case V_337 :
F_57 ( & V_10 -> V_10 , L_44 , V_156 ) ;
V_16 = F_131 ( V_8 , V_113 ) ;
break;
case V_338 :
F_57 ( & V_10 -> V_10 , L_45 , V_156 ) ;
V_16 = F_134 ( V_8 , V_113 ) ;
break;
case V_339 :
F_57 ( & V_10 -> V_10 , L_46 , V_156 ) ;
V_16 = F_136 ( V_8 , V_113 ) ;
break;
case V_340 :
F_57 ( & V_10 -> V_10 , L_47 , V_156 ) ;
V_16 = F_156 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
#ifdef F_205
case V_341 :
F_57 ( & V_10 -> V_10 , L_48 , V_156 ) ;
V_16 = F_170 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_342 :
F_57 ( & V_10 -> V_10 , L_49 , V_156 ) ;
V_16 = F_174 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_343 :
F_57 ( & V_10 -> V_10 , L_50 , V_156 ) ;
V_16 = F_175 ( V_8 , V_113 ) ;
break;
case V_344 :
F_57 ( & V_10 -> V_10 , L_51 , V_156 ) ;
V_16 = F_178 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_177 -> V_330 = V_331 ;
break;
case V_345 :
F_57 ( & V_10 -> V_10 , L_52 , V_156 ) ;
V_16 = F_193 ( V_8 , F_180 ( V_113 ) ) ;
break;
#endif
case V_346 :
F_57 ( & V_10 -> V_10 , L_53 , V_156 ) ;
V_16 = F_157 ( V_8 , V_113 ) ;
break;
case V_347 :
F_57 ( & V_10 -> V_10 , L_54 , V_156 ) ;
V_16 = F_183 ( V_8 , V_113 ) ;
break;
case V_348 :
F_57 ( & V_10 -> V_10 , L_55 , V_156 ) ;
V_16 = F_184 ( V_8 , V_113 ) ;
break;
case V_349 :
F_57 ( & V_10 -> V_10 , L_56 , V_156 ) ;
V_16 = F_185 ( V_8 , V_113 ) ;
break;
case V_350 :
F_57 ( & V_10 -> V_10 , L_57 , V_156 ) ;
V_16 = F_192 ( V_8 , V_113 ) ;
break;
case V_351 :
F_57 ( & V_10 -> V_10 , L_58 , V_156 ) ;
V_16 = F_194 ( V_8 , V_113 ) ;
break;
case V_352 :
F_57 ( & V_10 -> V_10 , L_59 , V_156 ) ;
V_16 = F_196 ( V_8 , V_113 ) ;
break;
case V_353 :
V_16 = F_198 ( V_8 , V_113 ) ;
break;
case V_354 :
V_16 = F_199 ( V_8 , V_113 ) ;
break;
case V_355 :
V_16 = F_200 ( V_8 , V_113 ) ;
break;
case V_356 :
V_16 = F_202 ( V_8 , V_113 ) ;
break;
}
V_198:
F_19 ( V_10 ) ;
if ( V_16 >= 0 )
V_177 -> V_357 = V_331 ;
return V_16 ;
}
static long F_206 ( struct V_13 * V_13 , unsigned int V_321 ,
unsigned long V_187 )
{
int V_16 ;
V_16 = F_204 ( V_13 , V_321 , ( void T_3 * ) V_187 ) ;
return V_16 ;
}
static long F_207 ( struct V_13 * V_13 , unsigned int V_321 ,
unsigned long V_187 )
{
int V_16 ;
V_16 = F_204 ( V_13 , V_321 , F_173 ( V_187 ) ) ;
return V_16 ;
}
static unsigned int F_208 ( struct V_13 * V_13 ,
struct V_358 * V_110 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
unsigned int V_359 = 0 ;
F_209 ( V_13 , & V_8 -> V_110 , V_110 ) ;
if ( V_13 -> V_322 & V_323 && ! F_8 ( & V_8 -> V_62 ) )
V_359 |= V_360 | V_361 ;
if ( ! F_7 ( V_8 ) )
V_359 |= V_362 | V_363 ;
return V_359 ;
}
static void F_210 ( struct V_24 * V_65 )
{
struct V_7 * V_8 ;
struct V_94 V_95 ;
while ( ! F_8 ( & V_65 -> V_186 ) ) {
V_8 = F_37 ( V_65 -> V_186 . V_63 , struct V_7 , V_9 ) ;
F_65 ( V_8 ) ;
F_211 ( & V_8 -> V_110 ) ;
F_35 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_183 ) {
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_99 = V_8 -> V_183 ;
V_95 . V_100 = V_202 ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_8 -> V_185 ;
F_58 ( V_8 -> V_183 , & V_95 ,
V_8 -> V_184 , V_8 -> V_52 , V_8 -> V_96 ) ;
}
}
}
static int F_212 ( struct V_364 * V_365 ,
unsigned long V_366 , void * V_10 )
{
switch ( V_366 ) {
case V_367 :
break;
case V_368 :
F_210 ( V_10 ) ;
break;
}
return V_369 ;
}
int T_11 F_213 ( void )
{
int V_277 ;
V_277 = F_214 ( V_370 , V_371 ,
L_60 ) ;
if ( V_277 ) {
F_215 ( V_372 L_61 ) ;
goto V_373;
}
F_216 ( & V_374 , & V_375 ) ;
V_277 = F_217 ( & V_374 , V_370 , V_371 ) ;
if ( V_277 ) {
F_215 ( V_372 L_62 ,
V_180 ) ;
goto V_376;
}
F_218 ( & V_377 ) ;
V_373:
return V_277 ;
V_376:
F_219 ( V_370 , V_371 ) ;
goto V_373;
}
void F_220 ( void )
{
F_221 ( & V_377 ) ;
F_222 ( & V_374 ) ;
F_219 ( V_370 , V_371 ) ;
}
