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
static T_1 F_9 ( struct V_13 * V_13 , char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
struct V_7 * V_8 = V_13 -> V_17 ;
struct V_18 * V_10 = V_8 -> V_10 ;
T_1 V_19 = 0 ;
unsigned V_20 ;
T_4 V_21 ;
int V_22 ;
V_21 = * V_16 ;
F_10 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_19 = - V_23 ;
goto V_24;
} else if ( V_21 < 0 ) {
V_19 = - V_25 ;
goto V_24;
}
if ( V_21 < sizeof( struct V_26 ) ) {
struct V_26 V_27 ;
memcpy ( & V_27 , & V_10 -> V_28 , sizeof( V_10 -> V_28 ) ) ;
F_11 ( & V_27 . V_29 ) ;
F_11 ( & V_27 . V_30 ) ;
F_11 ( & V_27 . V_31 ) ;
F_11 ( & V_27 . V_32 ) ;
V_20 = sizeof( struct V_26 ) - V_21 ;
if ( V_20 > V_15 )
V_20 = V_15 ;
if ( F_12 ( V_14 , ( ( char * ) & V_27 ) + V_21 , V_20 ) ) {
V_19 = - V_33 ;
goto V_24;
}
* V_16 += V_20 ;
V_14 += V_20 ;
V_15 -= V_20 ;
V_19 += V_20 ;
}
V_21 = sizeof( struct V_26 ) ;
for ( V_22 = 0 ; V_15 && V_22 < V_10 -> V_28 . V_34 ; V_22 ++ ) {
struct V_35 * V_36 =
(struct V_35 * ) V_10 -> V_37 [ V_22 ] ;
unsigned int V_38 = F_13 ( V_36 -> V_39 ) ;
if ( * V_16 < V_21 + V_38 ) {
unsigned V_40 =
F_13 ( V_10 -> V_36 [ V_22 ] . V_41 . V_39 ) ;
V_20 = V_38 - ( * V_16 - V_21 ) ;
if ( V_20 > V_15 )
V_20 = V_15 ;
if ( V_40 > ( * V_16 - V_21 ) ) {
V_40 -= ( * V_16 - V_21 ) ;
if ( F_12 ( V_14 ,
V_10 -> V_37 [ V_22 ] + ( * V_16 - V_21 ) ,
F_14 ( V_20 , V_40 ) ) ) {
V_19 = - V_33 ;
goto V_24;
}
}
* V_16 += V_20 ;
V_14 += V_20 ;
V_15 -= V_20 ;
V_19 += V_20 ;
}
V_21 += V_38 ;
}
V_24:
F_15 ( V_10 ) ;
return V_19 ;
}
static struct V_42 * F_16 ( unsigned int V_43 )
{
struct V_42 * V_44 ;
V_44 = F_17 ( sizeof( struct V_42 ) , V_45 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_46 = F_18 ( V_43 , V_45 ) ;
if ( ! V_44 -> V_46 ) {
F_19 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
static void F_20 ( struct V_42 * V_44 )
{
int V_22 ;
F_21 ( V_44 -> V_47 ) ;
if ( V_44 -> V_48 )
F_22 ( V_44 -> V_48 ) ;
for ( V_22 = 0 ; V_22 < V_44 -> V_46 -> V_49 ; V_22 ++ ) {
if ( F_23 ( & V_44 -> V_46 -> V_50 [ V_22 ] ) )
F_19 ( F_24 ( & V_44 -> V_46 -> V_50 [ V_22 ] ) ) ;
}
F_19 ( V_44 -> V_46 -> V_50 ) ;
F_19 ( V_44 -> V_46 -> V_51 ) ;
F_19 ( V_44 -> V_46 -> V_52 ) ;
F_25 ( V_44 -> V_46 ) ;
F_6 ( V_44 -> V_53 ) ;
F_19 ( V_44 ) ;
}
static void F_26 ( struct V_42 * V_44 )
{
struct V_7 * V_8 = V_44 -> V_8 ;
unsigned long V_54 ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
F_28 ( & V_44 -> V_56 , & V_8 -> V_57 ) ;
F_29 ( & V_8 -> V_55 , V_54 ) ;
}
static void F_30 ( struct V_42 * V_44 )
{
struct V_7 * V_8 = V_44 -> V_8 ;
unsigned long V_54 ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
F_31 ( & V_44 -> V_56 ) ;
F_29 ( & V_8 -> V_55 , V_54 ) ;
}
static struct V_42 * F_32 ( struct V_7 * V_8 )
{
unsigned long V_54 ;
struct V_42 * V_44 = NULL ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
if ( ! F_8 ( & V_8 -> V_58 ) ) {
V_44 = F_33 ( V_8 -> V_58 . V_59 , struct V_42 ,
V_56 ) ;
F_31 ( & V_44 -> V_56 ) ;
}
F_29 ( & V_8 -> V_55 , V_54 ) ;
return V_44 ;
}
static struct V_42 * F_34 ( struct V_7 * V_8 ,
void T_2 * V_60 )
{
struct V_42 * V_44 ;
F_35 (as, &ps->async_pending, asynclist)
if ( V_44 -> V_60 == V_60 ) {
F_31 ( & V_44 -> V_56 ) ;
return V_44 ;
}
return NULL ;
}
static void F_36 ( struct V_18 * V_61 ,
void T_2 * V_60 , int V_62 , unsigned V_38 ,
int V_63 , enum V_64 V_65 ,
unsigned char * V_66 , unsigned V_67 )
{
static const char * V_68 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_69 [] = { L_5 , L_6 } ;
int V_70 ;
const char * V_71 , * V_72 ;
if ( ! V_73 )
return;
V_70 = F_37 ( V_62 ) ;
V_71 = V_68 [ F_38 ( V_62 ) ] ;
V_72 = V_69 [ ! ! F_39 ( V_62 ) ] ;
if ( V_60 ) {
if ( V_65 == V_74 )
F_40 ( & V_61 -> V_10 , L_7
L_8 ,
V_60 , V_70 , V_71 , V_72 , V_38 ) ;
else
F_40 ( & V_61 -> V_10 , L_7
L_9 ,
V_60 , V_70 , V_71 , V_72 , V_38 ,
V_63 ) ;
} else {
if ( V_65 == V_74 )
F_40 ( & V_61 -> V_10 , L_10
L_11 ,
V_70 , V_71 , V_72 , V_38 , V_63 ) ;
else
F_40 ( & V_61 -> V_10 , L_12
L_13 ,
V_70 , V_71 , V_72 , V_38 , V_63 ) ;
}
V_67 = F_14 ( V_67 , V_75 ) ;
if ( V_66 && V_67 > 0 ) {
F_41 ( V_76 , L_14 , V_77 , 32 , 1 ,
V_66 , V_67 , 1 ) ;
}
}
static void F_42 ( struct V_46 * V_46 , unsigned V_20 )
{
int V_22 , V_78 ;
V_20 = F_14 ( V_20 , V_75 ) ;
if ( ! V_73 || V_20 == 0 )
return;
if ( V_46 -> V_49 == 0 ) {
F_41 ( V_76 , L_14 , V_77 , 32 , 1 ,
V_46 -> V_51 , V_20 , 1 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_46 -> V_49 && V_20 ; V_22 ++ ) {
V_78 = ( V_20 > V_79 ) ? V_79 : V_20 ;
F_41 ( V_76 , L_14 , V_77 , 32 , 1 ,
F_24 ( & V_46 -> V_50 [ V_22 ] ) , V_78 , 1 ) ;
V_20 -= V_78 ;
}
}
static int F_43 ( T_5 T_2 * V_80 , struct V_46 * V_46 )
{
unsigned V_22 , V_20 , V_78 ;
if ( V_46 -> V_81 > 0 )
V_20 = V_46 -> V_82 ;
else
V_20 = V_46 -> V_83 ;
if ( V_46 -> V_49 == 0 ) {
if ( F_12 ( V_80 , V_46 -> V_51 , V_20 ) )
return - V_33 ;
return 0 ;
}
for ( V_22 = 0 ; V_22 < V_46 -> V_49 && V_20 ; V_22 ++ ) {
V_78 = ( V_20 > V_79 ) ? V_79 : V_20 ;
if ( F_12 ( V_80 , F_24 ( & V_46 -> V_50 [ V_22 ] ) , V_78 ) )
return - V_33 ;
V_80 += V_78 ;
V_20 -= V_78 ;
}
return 0 ;
}
static void F_44 ( struct V_7 * V_8 , unsigned V_84 )
__releases( V_8 -> V_55 )
__acquires( V_8 -> V_55 )
{
struct V_46 * V_46 ;
struct V_42 * V_44 ;
F_35 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_84 == V_84 ) {
if ( V_44 -> V_85 != V_86 )
goto V_87;
V_44 -> V_85 = V_88 ;
V_44 -> V_84 = 0 ;
}
}
V_8 -> V_89 |= ( 1 << V_84 ) ;
V_87:
F_35 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_85 == V_88 ) {
V_44 -> V_85 = 0 ;
V_46 = V_44 -> V_46 ;
F_45 ( V_46 ) ;
F_46 ( & V_8 -> V_55 ) ;
F_47 ( V_46 ) ;
F_48 ( V_46 ) ;
F_49 ( & V_8 -> V_55 ) ;
goto V_87;
}
}
}
static void V_58 ( struct V_46 * V_46 )
{
struct V_42 * V_44 = V_46 -> V_90 ;
struct V_7 * V_8 = V_44 -> V_8 ;
struct V_91 V_92 ;
struct V_47 * V_47 = NULL ;
T_6 V_93 = 0 ;
const struct V_48 * V_48 = NULL ;
int V_94 ;
F_49 ( & V_8 -> V_55 ) ;
F_50 ( & V_44 -> V_56 , & V_8 -> V_58 ) ;
V_44 -> V_95 = V_46 -> V_95 ;
V_94 = V_44 -> V_94 ;
if ( V_94 ) {
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_96 = V_44 -> V_94 ;
V_92 . V_97 = V_44 -> V_95 ;
V_92 . V_98 = V_99 ;
V_92 . V_100 = V_44 -> V_60 ;
V_47 = F_51 ( V_44 -> V_47 ) ;
V_48 = F_52 ( V_44 -> V_48 ) ;
V_93 = V_44 -> V_93 ;
}
F_53 ( & V_46 -> V_10 -> V_10 , L_15 ) ;
F_36 ( V_46 -> V_10 , V_44 -> V_60 , V_46 -> V_62 , V_46 -> V_83 ,
V_44 -> V_95 , V_101 , NULL , 0 ) ;
if ( ( V_46 -> V_102 & V_103 ) == V_104 )
F_42 ( V_46 , V_46 -> V_83 ) ;
if ( V_44 -> V_95 < 0 && V_44 -> V_84 && V_44 -> V_95 != - V_105 &&
V_44 -> V_95 != - V_106 )
F_44 ( V_8 , V_44 -> V_84 ) ;
F_46 ( & V_8 -> V_55 ) ;
if ( V_94 ) {
F_54 ( V_92 . V_96 , & V_92 , V_47 , V_48 , V_93 ) ;
F_21 ( V_47 ) ;
F_22 ( V_48 ) ;
}
F_55 ( & V_8 -> V_107 ) ;
}
static void F_56 ( struct V_7 * V_8 , struct V_108 * V_9 )
{
struct V_46 * V_46 ;
struct V_42 * V_44 ;
unsigned long V_54 ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
while ( ! F_8 ( V_9 ) ) {
V_44 = F_33 ( V_9 -> V_59 , struct V_42 , V_56 ) ;
F_31 ( & V_44 -> V_56 ) ;
V_46 = V_44 -> V_46 ;
F_45 ( V_46 ) ;
F_29 ( & V_8 -> V_55 , V_54 ) ;
F_57 ( V_46 ) ;
F_48 ( V_46 ) ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
}
F_29 ( & V_8 -> V_55 , V_54 ) ;
}
static void F_58 ( struct V_7 * V_8 ,
unsigned int V_109 )
{
struct V_108 * V_110 , * V_111 , V_112 ;
unsigned long V_54 ;
F_59 ( & V_112 ) ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
F_60 (p, q, &ps->async_pending)
if ( V_109 == F_33 ( V_110 , struct V_42 , V_56 ) -> V_109 )
F_50 ( V_110 , & V_112 ) ;
F_29 ( & V_8 -> V_55 , V_54 ) ;
F_56 ( V_8 , & V_112 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
F_56 ( V_8 , & V_8 -> V_57 ) ;
}
static int F_62 ( struct V_113 * V_114 ,
const struct V_115 * V_116 )
{
return - V_23 ;
}
static void F_63 ( struct V_113 * V_114 )
{
struct V_7 * V_8 = F_64 ( V_114 ) ;
unsigned int V_109 = V_114 -> V_117 -> V_41 . V_118 ;
if ( ! V_8 )
return;
if ( F_65 ( V_109 < 8 * sizeof( V_8 -> V_119 ) ) )
F_66 ( V_109 , & V_8 -> V_119 ) ;
else
F_67 ( & V_114 -> V_10 , L_16 ,
V_109 ) ;
F_68 ( V_114 , NULL ) ;
F_58 ( V_8 , V_109 ) ;
}
static int F_69 ( struct V_113 * V_114 , T_7 V_120 )
{
return 0 ;
}
static int F_70 ( struct V_113 * V_114 )
{
return 0 ;
}
static int F_71 ( struct V_7 * V_8 , unsigned int V_109 )
{
struct V_18 * V_10 = V_8 -> V_10 ;
struct V_113 * V_114 ;
int V_24 ;
if ( V_109 >= 8 * sizeof( V_8 -> V_119 ) )
return - V_25 ;
if ( F_72 ( V_109 , & V_8 -> V_119 ) )
return 0 ;
V_114 = F_73 ( V_10 , V_109 ) ;
if ( ! V_114 )
V_24 = - V_106 ;
else
V_24 = F_74 ( & V_121 , V_114 , V_8 ) ;
if ( V_24 == 0 )
F_75 ( V_109 , & V_8 -> V_119 ) ;
return V_24 ;
}
static int F_76 ( struct V_7 * V_8 , unsigned int V_109 )
{
struct V_18 * V_10 ;
struct V_113 * V_114 ;
int V_24 ;
V_24 = - V_25 ;
if ( V_109 >= 8 * sizeof( V_8 -> V_119 ) )
return V_24 ;
V_10 = V_8 -> V_10 ;
V_114 = F_73 ( V_10 , V_109 ) ;
if ( ! V_114 )
V_24 = - V_106 ;
else if ( F_77 ( V_109 , & V_8 -> V_119 ) ) {
F_78 ( & V_121 , V_114 ) ;
V_24 = 0 ;
}
return V_24 ;
}
static int F_79 ( struct V_7 * V_8 , unsigned int V_109 )
{
if ( V_8 -> V_10 -> V_11 != V_122 )
return - V_123 ;
if ( V_109 >= 8 * sizeof( V_8 -> V_119 ) )
return - V_25 ;
if ( F_72 ( V_109 , & V_8 -> V_119 ) )
return 0 ;
F_67 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_80 ( V_124 ) ,
V_124 -> V_125 , V_109 ) ;
return F_71 ( V_8 , V_109 ) ;
}
static int F_81 ( struct V_18 * V_10 , unsigned int V_70 )
{
unsigned int V_22 , V_126 , V_127 ;
struct V_113 * V_114 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
if ( V_70 & ~ ( V_132 | 0xf ) )
return - V_25 ;
if ( ! V_10 -> V_133 )
return - V_134 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_133 -> V_41 . V_135 ; V_22 ++ ) {
V_114 = V_10 -> V_133 -> V_136 [ V_22 ] ;
for ( V_126 = 0 ; V_126 < V_114 -> V_137 ; V_126 ++ ) {
V_129 = & V_114 -> V_117 [ V_126 ] ;
for ( V_127 = 0 ; V_127 < V_129 -> V_41 . V_138 ; V_127 ++ ) {
V_131 = & V_129 -> V_139 [ V_127 ] . V_41 ;
if ( V_131 -> V_140 == V_70 )
return V_129 -> V_41 . V_118 ;
}
}
}
return - V_106 ;
}
static int F_82 ( struct V_7 * V_8 , unsigned int V_141 ,
unsigned int V_142 , unsigned int V_143 )
{
int V_19 = 0 ;
struct V_128 * V_144 ;
if ( V_8 -> V_10 -> V_11 != V_145
&& V_8 -> V_10 -> V_11 != V_146
&& V_8 -> V_10 -> V_11 != V_122 )
return - V_123 ;
if ( V_147 == ( V_148 & V_141 ) )
return 0 ;
if ( V_141 == 0xa1 && V_142 == 0 ) {
V_144 = F_83 ( V_8 -> V_10 -> V_133 ,
V_143 >> 8 , V_143 & 0xff ) ;
if ( V_144
&& V_144 -> V_41 . V_149 == V_150 )
return 0 ;
}
V_143 &= 0xff ;
switch ( V_141 & V_151 ) {
case V_152 :
if ( ( V_143 & ~ V_132 ) == 0 )
return 0 ;
V_19 = F_81 ( V_8 -> V_10 , V_143 ) ;
if ( V_19 < 0 ) {
V_19 = F_81 ( V_8 -> V_10 , V_143 ^ 0x80 ) ;
if ( V_19 >= 0 )
F_40 ( & V_8 -> V_10 -> V_10 ,
L_19 ,
V_153 , F_80 ( V_124 ) ,
V_124 -> V_125 , V_143 , V_143 ^ 0x80 ) ;
}
if ( V_19 >= 0 )
V_19 = F_79 ( V_8 , V_19 ) ;
break;
case V_154 :
V_19 = F_79 ( V_8 , V_143 ) ;
break;
}
return V_19 ;
}
static struct V_155 * F_84 ( struct V_18 * V_10 ,
unsigned char V_70 )
{
if ( V_70 & V_156 )
return V_10 -> V_157 [ V_70 & V_158 ] ;
else
return V_10 -> V_159 [ V_70 & V_158 ] ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_160 T_2 * V_161 ,
unsigned int * V_162 ,
unsigned int * V_163 ,
struct V_155 * * * V_164 ,
struct V_113 * * V_165 )
{
unsigned int V_22 , V_166 , V_167 ;
struct V_155 * * V_168 ;
struct V_113 * V_114 = NULL ;
unsigned char V_70 ;
int V_109 , V_19 ;
if ( F_86 ( V_166 , & V_161 -> V_166 ) ||
F_86 ( V_167 , & V_161 -> V_167 ) )
return - V_33 ;
if ( V_167 < 1 || V_167 > V_169 )
return - V_25 ;
if ( V_162 && ( V_166 < 2 || V_166 > 65536 ) )
return - V_25 ;
V_168 = F_87 ( V_167 * sizeof( * V_168 ) , V_45 ) ;
if ( ! V_168 )
return - V_6 ;
for ( V_22 = 0 ; V_22 < V_167 ; V_22 ++ ) {
if ( F_86 ( V_70 , & V_161 -> V_168 [ V_22 ] ) ) {
V_19 = - V_33 ;
goto error;
}
V_168 [ V_22 ] = F_84 ( V_8 -> V_10 , V_70 ) ;
if ( ! V_168 [ V_22 ] ) {
V_19 = - V_25 ;
goto error;
}
V_109 = F_81 ( V_8 -> V_10 , V_70 ) ;
if ( V_109 < 0 ) {
V_19 = V_109 ;
goto error;
}
if ( V_22 == 0 ) {
V_19 = F_79 ( V_8 , V_109 ) ;
if ( V_19 < 0 )
goto error;
V_114 = F_73 ( V_8 -> V_10 , V_109 ) ;
} else {
if ( V_109 != V_114 -> V_117 -> V_41 . V_118 ) {
V_19 = - V_25 ;
goto error;
}
}
}
if ( V_162 )
* V_162 = V_166 ;
* V_163 = V_167 ;
* V_164 = V_168 ;
* V_165 = V_114 ;
return 0 ;
error:
F_19 ( V_168 ) ;
return V_19 ;
}
static int F_88 ( struct V_170 * V_10 , void * V_66 )
{
return V_10 -> V_171 == ( V_172 ) ( unsigned long ) V_66 ;
}
static struct V_18 * F_89 ( V_172 V_171 )
{
struct V_170 * V_10 ;
V_10 = F_90 ( & V_173 , NULL ,
( void * ) ( unsigned long ) V_171 , F_88 ) ;
if ( ! V_10 )
return NULL ;
return F_91 ( V_10 , struct V_18 , V_10 ) ;
}
static int F_92 ( struct V_174 * V_174 , struct V_13 * V_13 )
{
struct V_18 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_19 ;
V_19 = - V_6 ;
V_8 = F_87 ( sizeof( struct V_7 ) , V_45 ) ;
if ( ! V_8 )
goto V_175;
V_19 = - V_23 ;
F_93 ( & V_176 ) ;
if ( F_94 ( V_174 ) == V_177 )
V_10 = F_89 ( V_174 -> V_178 ) ;
F_95 ( & V_176 ) ;
if ( ! V_10 )
goto V_175;
F_10 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_179;
V_19 = F_96 ( V_10 ) ;
if ( V_19 )
goto V_179;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_97 ( & V_8 -> V_55 ) ;
F_59 ( & V_8 -> V_9 ) ;
F_59 ( & V_8 -> V_57 ) ;
F_59 ( & V_8 -> V_58 ) ;
F_98 ( & V_8 -> V_107 ) ;
V_8 -> V_180 = 0 ;
V_8 -> V_181 = F_51 ( F_99 ( V_124 ) ) ;
V_8 -> V_48 = F_100 () ;
V_8 -> V_182 = NULL ;
V_8 -> V_119 = 0 ;
F_101 ( V_124 , & V_8 -> V_93 ) ;
F_102 () ;
F_28 ( & V_8 -> V_9 , & V_10 -> V_183 ) ;
V_13 -> V_17 = V_8 ;
F_15 ( V_10 ) ;
F_53 ( & V_10 -> V_10 , L_20 , F_80 ( V_124 ) ,
V_124 -> V_125 ) ;
return V_19 ;
V_179:
F_15 ( V_10 ) ;
F_103 ( V_10 ) ;
V_175:
F_19 ( V_8 ) ;
return V_19 ;
}
static int F_104 ( struct V_174 * V_174 , struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_17 ;
struct V_18 * V_10 = V_8 -> V_10 ;
unsigned int V_109 ;
struct V_42 * V_44 ;
F_10 ( V_10 ) ;
F_105 ( V_10 , V_8 ) ;
F_31 ( & V_8 -> V_9 ) ;
for ( V_109 = 0 ; V_8 -> V_119 && V_109 < 8 * sizeof( V_8 -> V_119 ) ;
V_109 ++ ) {
if ( F_72 ( V_109 , & V_8 -> V_119 ) )
F_76 ( V_8 , V_109 ) ;
}
F_61 ( V_8 ) ;
F_106 ( V_10 ) ;
F_15 ( V_10 ) ;
F_103 ( V_10 ) ;
F_21 ( V_8 -> V_181 ) ;
F_22 ( V_8 -> V_48 ) ;
V_44 = F_32 ( V_8 ) ;
while ( V_44 ) {
F_20 ( V_44 ) ;
V_44 = F_32 ( V_8 ) ;
}
F_19 ( V_8 ) ;
return 0 ;
}
static int F_107 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_18 * V_10 = V_8 -> V_10 ;
struct V_185 V_186 ;
unsigned int V_187 ;
unsigned char * V_188 ;
unsigned V_189 ;
int V_22 , V_62 , V_19 ;
if ( F_108 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_33 ;
V_19 = F_82 ( V_8 , V_186 . V_190 , V_186 . V_191 ,
V_186 . V_192 ) ;
if ( V_19 )
return V_19 ;
V_189 = V_186 . V_189 ;
if ( V_189 > V_193 )
return - V_25 ;
V_19 = F_1 ( V_193 + sizeof( struct V_46 ) +
sizeof( struct V_194 ) ) ;
if ( V_19 )
return V_19 ;
V_188 = ( unsigned char * ) F_109 ( V_45 ) ;
if ( ! V_188 ) {
V_19 = - V_6 ;
goto V_195;
}
V_187 = V_186 . V_196 ;
F_53 ( & V_10 -> V_10 , L_21
L_22
L_23 ,
V_186 . V_190 , V_186 . V_191 , V_186 . V_197 ,
V_186 . V_192 , V_186 . V_189 ) ;
if ( V_186 . V_190 & 0x80 ) {
if ( V_186 . V_189 && ! F_110 ( V_198 , V_186 . V_66 ,
V_186 . V_189 ) ) {
V_19 = - V_25 ;
goto V_195;
}
V_62 = F_111 ( V_10 , 0 ) ;
F_36 ( V_10 , NULL , V_62 , V_186 . V_189 , V_187 , V_74 , NULL , 0 ) ;
F_15 ( V_10 ) ;
V_22 = F_112 ( V_10 , V_62 , V_186 . V_191 ,
V_186 . V_190 , V_186 . V_197 , V_186 . V_192 ,
V_188 , V_186 . V_189 , V_187 ) ;
F_10 ( V_10 ) ;
F_36 ( V_10 , NULL , V_62 , F_113 ( V_22 , 0 ) , F_14 ( V_22 , 0 ) , V_101 ,
V_188 , F_113 ( V_22 , 0 ) ) ;
if ( ( V_22 > 0 ) && V_186 . V_189 ) {
if ( F_12 ( V_186 . V_66 , V_188 , V_22 ) ) {
V_19 = - V_33 ;
goto V_195;
}
}
} else {
if ( V_186 . V_189 ) {
if ( F_108 ( V_188 , V_186 . V_66 , V_186 . V_189 ) ) {
V_19 = - V_33 ;
goto V_195;
}
}
V_62 = F_114 ( V_10 , 0 ) ;
F_36 ( V_10 , NULL , V_62 , V_186 . V_189 , V_187 , V_74 ,
V_188 , V_186 . V_189 ) ;
F_15 ( V_10 ) ;
V_22 = F_112 ( V_10 , F_114 ( V_10 , 0 ) , V_186 . V_191 ,
V_186 . V_190 , V_186 . V_197 , V_186 . V_192 ,
V_188 , V_186 . V_189 , V_187 ) ;
F_10 ( V_10 ) ;
F_36 ( V_10 , NULL , V_62 , F_113 ( V_22 , 0 ) , F_14 ( V_22 , 0 ) , V_101 , NULL , 0 ) ;
}
if ( V_22 < 0 && V_22 != - V_199 ) {
F_115 ( V_76 , & V_10 -> V_10 , L_24
L_25 ,
V_124 -> V_125 , V_186 . V_190 , V_186 . V_191 ,
V_186 . V_189 , V_22 ) ;
}
V_19 = V_22 ;
V_195:
F_116 ( ( unsigned long ) V_188 ) ;
F_6 ( V_193 + sizeof( struct V_46 ) +
sizeof( struct V_194 ) ) ;
return V_19 ;
}
static int F_117 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_18 * V_10 = V_8 -> V_10 ;
struct V_200 V_201 ;
unsigned int V_187 , V_202 , V_62 ;
int V_203 ;
unsigned char * V_188 ;
int V_22 , V_19 ;
if ( F_108 ( & V_201 , V_184 , sizeof( V_201 ) ) )
return - V_33 ;
V_19 = F_81 ( V_8 -> V_10 , V_201 . V_70 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_79 ( V_8 , V_19 ) ;
if ( V_19 )
return V_19 ;
if ( V_201 . V_70 & V_132 )
V_62 = F_118 ( V_10 , V_201 . V_70 & 0x7f ) ;
else
V_62 = F_119 ( V_10 , V_201 . V_70 & 0x7f ) ;
if ( ! F_120 ( V_10 , V_62 , ! ( V_201 . V_70 & V_132 ) ) )
return - V_25 ;
V_202 = V_201 . V_20 ;
if ( V_202 >= V_4 )
return - V_25 ;
V_19 = F_1 ( V_202 + sizeof( struct V_46 ) ) ;
if ( V_19 )
return V_19 ;
V_188 = F_87 ( V_202 , V_45 ) ;
if ( ! V_188 ) {
V_19 = - V_6 ;
goto V_195;
}
V_187 = V_201 . V_196 ;
if ( V_201 . V_70 & 0x80 ) {
if ( V_202 && ! F_110 ( V_198 , V_201 . V_66 , V_202 ) ) {
V_19 = - V_25 ;
goto V_195;
}
F_36 ( V_10 , NULL , V_62 , V_202 , V_187 , V_74 , NULL , 0 ) ;
F_15 ( V_10 ) ;
V_22 = F_121 ( V_10 , V_62 , V_188 , V_202 , & V_203 , V_187 ) ;
F_10 ( V_10 ) ;
F_36 ( V_10 , NULL , V_62 , V_203 , V_22 , V_101 , V_188 , V_203 ) ;
if ( ! V_22 && V_203 ) {
if ( F_12 ( V_201 . V_66 , V_188 , V_203 ) ) {
V_19 = - V_33 ;
goto V_195;
}
}
} else {
if ( V_202 ) {
if ( F_108 ( V_188 , V_201 . V_66 , V_202 ) ) {
V_19 = - V_33 ;
goto V_195;
}
}
F_36 ( V_10 , NULL , V_62 , V_202 , V_187 , V_74 , V_188 , V_202 ) ;
F_15 ( V_10 ) ;
V_22 = F_121 ( V_10 , V_62 , V_188 , V_202 , & V_203 , V_187 ) ;
F_10 ( V_10 ) ;
F_36 ( V_10 , NULL , V_62 , V_203 , V_22 , V_101 , NULL , 0 ) ;
}
V_19 = ( V_22 < 0 ? V_22 : V_203 ) ;
V_195:
F_19 ( V_188 ) ;
F_6 ( V_202 + sizeof( struct V_46 ) ) ;
return V_19 ;
}
static void F_122 ( struct V_18 * V_61 ,
unsigned int V_204 , char * V_205 )
{
struct V_155 * * V_168 ;
struct V_155 * V_70 ;
V_168 = ( V_204 & V_132 ) ? V_61 -> V_157 : V_61 -> V_159 ;
V_70 = V_168 [ V_204 & 0x0f ] ;
if ( V_70 && ! F_8 ( & V_70 -> V_206 ) )
F_67 ( & V_61 -> V_10 , L_26 ,
F_80 ( V_124 ) , V_124 -> V_125 ,
V_205 , V_204 ) ;
}
static int F_123 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned int V_70 ;
int V_19 ;
if ( F_86 ( V_70 , ( unsigned int T_2 * ) V_184 ) )
return - V_33 ;
V_19 = F_81 ( V_8 -> V_10 , V_70 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_79 ( V_8 , V_19 ) ;
if ( V_19 )
return V_19 ;
F_122 ( V_8 -> V_10 , V_70 , L_27 ) ;
F_124 ( V_8 -> V_10 , V_70 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned int V_70 ;
int V_62 ;
int V_19 ;
if ( F_86 ( V_70 , ( unsigned int T_2 * ) V_184 ) )
return - V_33 ;
V_19 = F_81 ( V_8 -> V_10 , V_70 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_79 ( V_8 , V_19 ) ;
if ( V_19 )
return V_19 ;
F_122 ( V_8 -> V_10 , V_70 , L_28 ) ;
if ( V_70 & V_132 )
V_62 = F_118 ( V_8 -> V_10 , V_70 & 0x7f ) ;
else
V_62 = F_119 ( V_8 -> V_10 , V_70 & 0x7f ) ;
return F_126 ( V_8 -> V_10 , V_62 ) ;
}
static int F_127 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_207 V_208 ;
struct V_113 * V_114 ;
int V_19 ;
if ( F_108 ( & V_208 , V_184 , sizeof( V_208 ) ) )
return - V_33 ;
V_114 = F_73 ( V_8 -> V_10 , V_208 . V_136 ) ;
if ( ! V_114 || ! V_114 -> V_10 . V_209 )
V_19 = - V_210 ;
else {
F_128 ( V_208 . V_209 , V_114 -> V_10 . V_209 -> V_211 ,
sizeof( V_208 . V_209 ) ) ;
V_19 = ( F_12 ( V_184 , & V_208 , sizeof( V_208 ) ) ? - V_33 : 0 ) ;
}
return V_19 ;
}
static int F_129 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_212 V_213 = {
. V_214 = V_8 -> V_10 -> V_214 ,
. V_215 = V_8 -> V_10 -> V_216 == V_217
} ;
if ( F_12 ( V_184 , & V_213 , sizeof( V_213 ) ) )
return - V_33 ;
return 0 ;
}
static int F_130 ( struct V_7 * V_8 )
{
return F_131 ( V_8 -> V_10 ) ;
}
static int F_132 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_218 V_219 ;
int V_19 ;
if ( F_108 ( & V_219 , V_184 , sizeof( V_219 ) ) )
return - V_33 ;
V_19 = F_79 ( V_8 , V_219 . V_136 ) ;
if ( V_19 )
return V_19 ;
F_58 ( V_8 , V_219 . V_136 ) ;
return F_133 ( V_8 -> V_10 , V_219 . V_136 ,
V_219 . V_117 ) ;
}
static int F_134 ( struct V_7 * V_8 , void T_2 * V_184 )
{
int V_220 ;
int V_95 = 0 ;
struct V_221 * V_133 ;
if ( F_86 ( V_220 , ( int T_2 * ) V_184 ) )
return - V_33 ;
V_133 = V_8 -> V_10 -> V_133 ;
if ( V_133 ) {
int V_22 ;
for ( V_22 = 0 ; V_22 < V_133 -> V_41 . V_135 ; ++ V_22 ) {
if ( F_135 ( V_133 -> V_136 [ V_22 ] ) ) {
F_67 ( & V_8 -> V_10 -> V_10 ,
L_29
L_30 ,
V_133 -> V_136 [ V_22 ]
-> V_222
-> V_41 . V_118 ,
V_133 -> V_136 [ V_22 ]
-> V_10 . V_209 -> V_211 ,
V_124 -> V_125 , V_220 ) ;
V_95 = - V_223 ;
break;
}
}
}
if ( V_95 == 0 ) {
if ( V_133 && V_133 -> V_41 . V_224 == V_220 )
V_95 = F_136 ( V_8 -> V_10 ) ;
else
V_95 = F_137 ( V_8 -> V_10 , V_220 ) ;
}
return V_95 ;
}
static int F_138 ( struct V_7 * V_8 , struct V_225 * V_226 ,
struct V_227 T_2 * V_228 ,
void T_2 * V_184 )
{
struct V_227 * V_229 = NULL ;
struct V_155 * V_70 ;
struct V_42 * V_44 = NULL ;
struct V_194 * V_230 = NULL ;
unsigned int V_220 , V_231 , V_232 ;
int V_22 , V_19 , V_233 , V_49 = 0 , V_109 = - 1 ;
int V_81 = 0 ;
unsigned int V_234 = 0 ;
void * V_14 ;
if ( V_226 -> V_54 & ~ ( V_235 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 ) )
return - V_25 ;
if ( V_226 -> V_241 > 0 && ! V_226 -> V_242 )
return - V_25 ;
if ( ! ( V_226 -> type == V_243 &&
( V_226 -> V_139 & ~ V_156 ) == 0 ) ) {
V_109 = F_81 ( V_8 -> V_10 , V_226 -> V_139 ) ;
if ( V_109 < 0 )
return V_109 ;
V_19 = F_79 ( V_8 , V_109 ) ;
if ( V_19 )
return V_19 ;
}
V_70 = F_84 ( V_8 -> V_10 , V_226 -> V_139 ) ;
if ( ! V_70 )
return - V_106 ;
V_233 = ( V_226 -> V_139 & V_156 ) != 0 ;
V_220 = 0 ;
switch ( V_226 -> type ) {
case V_243 :
if ( ! F_139 ( & V_70 -> V_41 ) )
return - V_25 ;
if ( V_226 -> V_241 < 8 )
return - V_25 ;
V_230 = F_87 ( sizeof( struct V_194 ) , V_45 ) ;
if ( ! V_230 )
return - V_6 ;
if ( F_108 ( V_230 , V_226 -> V_242 , 8 ) ) {
V_19 = - V_33 ;
goto error;
}
if ( V_226 -> V_241 < ( F_140 ( & V_230 -> V_189 ) + 8 ) ) {
V_19 = - V_25 ;
goto error;
}
V_19 = F_82 ( V_8 , V_230 -> V_190 , V_230 -> V_191 ,
F_140 ( & V_230 -> V_192 ) ) ;
if ( V_19 )
goto error;
V_226 -> V_241 = F_140 ( & V_230 -> V_189 ) ;
V_226 -> V_242 += 8 ;
if ( ( V_230 -> V_190 & V_132 ) && V_226 -> V_241 ) {
V_233 = 1 ;
V_226 -> V_139 |= V_132 ;
} else {
V_233 = 0 ;
V_226 -> V_139 &= ~ V_132 ;
}
F_53 ( & V_8 -> V_10 -> V_10 , L_21
L_22
L_23 ,
V_230 -> V_190 , V_230 -> V_191 ,
F_141 ( & V_230 -> V_197 ) ,
F_141 ( & V_230 -> V_192 ) ,
F_141 ( & V_230 -> V_189 ) ) ;
V_220 = sizeof( struct V_194 ) ;
break;
case V_244 :
switch ( F_142 ( & V_70 -> V_41 ) ) {
case V_245 :
case V_246 :
return - V_25 ;
case V_247 :
V_226 -> type = V_248 ;
goto V_249;
}
V_49 = F_143 ( V_226 -> V_241 , V_79 ) ;
if ( V_49 == 1 || V_49 > V_8 -> V_10 -> V_250 -> V_251 )
V_49 = 0 ;
if ( V_70 -> V_161 )
V_234 = V_226 -> V_234 ;
break;
case V_248 :
if ( ! F_144 ( & V_70 -> V_41 ) )
return - V_25 ;
V_249:
break;
case V_252 :
if ( V_226 -> V_81 < 1 ||
V_226 -> V_81 > 128 )
return - V_25 ;
if ( ! F_145 ( & V_70 -> V_41 ) )
return - V_25 ;
V_81 = V_226 -> V_81 ;
V_232 = sizeof( struct V_227 ) *
V_81 ;
V_229 = F_87 ( V_232 , V_45 ) ;
if ( ! V_229 )
return - V_6 ;
if ( F_108 ( V_229 , V_228 , V_232 ) ) {
V_19 = - V_33 ;
goto error;
}
for ( V_231 = V_220 = 0 ; V_220 < V_81 ; V_220 ++ ) {
if ( V_229 [ V_220 ] . V_38 > 49152 ) {
V_19 = - V_25 ;
goto error;
}
V_231 += V_229 [ V_220 ] . V_38 ;
}
V_220 *= sizeof( struct V_253 ) ;
V_226 -> V_241 = V_231 ;
break;
default:
return - V_25 ;
}
if ( V_226 -> V_241 >= V_4 ) {
V_19 = - V_25 ;
goto error;
}
if ( V_226 -> V_241 > 0 &&
! F_110 ( V_233 ? V_198 : V_254 ,
V_226 -> V_242 , V_226 -> V_241 ) ) {
V_19 = - V_33 ;
goto error;
}
V_44 = F_16 ( V_81 ) ;
if ( ! V_44 ) {
V_19 = - V_6 ;
goto error;
}
V_220 += sizeof( struct V_42 ) + sizeof( struct V_46 ) + V_226 -> V_241 +
V_49 * sizeof( struct V_255 ) ;
V_19 = F_1 ( V_220 ) ;
if ( V_19 )
goto error;
V_44 -> V_53 = V_220 ;
if ( V_49 ) {
V_44 -> V_46 -> V_50 = F_87 ( V_49 * sizeof( struct V_255 ) ,
V_45 ) ;
if ( ! V_44 -> V_46 -> V_50 ) {
V_19 = - V_6 ;
goto error;
}
V_44 -> V_46 -> V_49 = V_49 ;
F_146 ( V_44 -> V_46 -> V_50 , V_44 -> V_46 -> V_49 ) ;
V_231 = V_226 -> V_241 ;
for ( V_22 = 0 ; V_22 < V_44 -> V_46 -> V_49 ; V_22 ++ ) {
V_220 = ( V_231 > V_79 ) ? V_79 : V_231 ;
V_14 = F_87 ( V_220 , V_45 ) ;
if ( ! V_14 ) {
V_19 = - V_6 ;
goto error;
}
F_147 ( & V_44 -> V_46 -> V_50 [ V_22 ] , V_14 , V_220 ) ;
if ( ! V_233 ) {
if ( F_108 ( V_14 , V_226 -> V_242 , V_220 ) ) {
V_19 = - V_33 ;
goto error;
}
V_226 -> V_242 += V_220 ;
}
V_231 -= V_220 ;
}
} else if ( V_226 -> V_241 > 0 ) {
V_44 -> V_46 -> V_51 = F_87 ( V_226 -> V_241 ,
V_45 ) ;
if ( ! V_44 -> V_46 -> V_51 ) {
V_19 = - V_6 ;
goto error;
}
if ( ! V_233 ) {
if ( F_108 ( V_44 -> V_46 -> V_51 ,
V_226 -> V_242 ,
V_226 -> V_241 ) ) {
V_19 = - V_33 ;
goto error;
}
} else if ( V_226 -> type == V_252 ) {
memset ( V_44 -> V_46 -> V_51 , 0 ,
V_226 -> V_241 ) ;
}
}
V_44 -> V_46 -> V_10 = V_8 -> V_10 ;
V_44 -> V_46 -> V_62 = ( V_226 -> type << 30 ) |
F_148 ( V_8 -> V_10 , V_226 -> V_139 & 0xf ) |
( V_226 -> V_139 & V_132 ) ;
V_220 = ( V_233 ? V_104 : V_256 ) ;
if ( V_226 -> V_54 & V_235 )
V_220 |= V_257 ;
if ( V_226 -> V_54 & V_236 && V_233 )
V_220 |= V_258 ;
if ( V_226 -> V_54 & V_238 )
V_220 |= V_259 ;
if ( V_226 -> V_54 & V_239 )
V_220 |= V_260 ;
if ( V_226 -> V_54 & V_240 )
V_220 |= V_261 ;
V_44 -> V_46 -> V_102 = V_220 ;
V_44 -> V_46 -> V_82 = V_226 -> V_241 ;
V_44 -> V_46 -> V_52 = ( unsigned char * ) V_230 ;
V_230 = NULL ;
V_44 -> V_46 -> V_262 = V_226 -> V_262 ;
V_44 -> V_46 -> V_81 = V_81 ;
V_44 -> V_46 -> V_234 = V_234 ;
if ( V_226 -> type == V_252 ||
V_8 -> V_10 -> V_216 == V_263 )
V_44 -> V_46 -> V_264 = 1 << F_14 ( 15 , V_70 -> V_41 . V_265 - 1 ) ;
else
V_44 -> V_46 -> V_264 = V_70 -> V_41 . V_265 ;
V_44 -> V_46 -> V_90 = V_44 ;
V_44 -> V_46 -> V_266 = V_58 ;
for ( V_231 = V_220 = 0 ; V_220 < V_81 ; V_220 ++ ) {
V_44 -> V_46 -> V_228 [ V_220 ] . V_267 = V_231 ;
V_44 -> V_46 -> V_228 [ V_220 ] . V_38 = V_229 [ V_220 ] . V_38 ;
V_231 += V_229 [ V_220 ] . V_38 ;
}
F_19 ( V_229 ) ;
V_229 = NULL ;
V_44 -> V_8 = V_8 ;
V_44 -> V_60 = V_184 ;
if ( V_233 && V_226 -> V_241 > 0 )
V_44 -> V_80 = V_226 -> V_242 ;
else
V_44 -> V_80 = NULL ;
V_44 -> V_94 = V_226 -> V_94 ;
V_44 -> V_109 = V_109 ;
V_44 -> V_47 = F_51 ( F_99 ( V_124 ) ) ;
V_44 -> V_48 = F_100 () ;
F_101 ( V_124 , & V_44 -> V_93 ) ;
F_36 ( V_8 -> V_10 , V_44 -> V_60 , V_44 -> V_46 -> V_62 ,
V_44 -> V_46 -> V_82 , 0 , V_74 ,
NULL , 0 ) ;
if ( ! V_233 )
F_42 ( V_44 -> V_46 , V_44 -> V_46 -> V_82 ) ;
F_26 ( V_44 ) ;
if ( F_149 ( & V_70 -> V_41 ) ) {
F_150 ( & V_8 -> V_55 ) ;
V_44 -> V_84 = F_151 ( & V_70 -> V_41 ) |
( ( V_70 -> V_41 . V_140 & V_156 )
>> 3 ) ;
if ( V_226 -> V_54 & V_237 )
V_44 -> V_85 = V_86 ;
else
V_8 -> V_89 &= ~ ( 1 << V_44 -> V_84 ) ;
if ( V_8 -> V_89 & ( 1 << V_44 -> V_84 ) )
V_19 = - V_268 ;
else
V_19 = F_152 ( V_44 -> V_46 , V_269 ) ;
F_153 ( & V_8 -> V_55 ) ;
} else {
V_19 = F_152 ( V_44 -> V_46 , V_45 ) ;
}
if ( V_19 ) {
F_115 ( V_76 , & V_8 -> V_10 -> V_10 ,
L_31 , V_19 ) ;
F_36 ( V_8 -> V_10 , V_44 -> V_60 , V_44 -> V_46 -> V_62 ,
0 , V_19 , V_101 , NULL , 0 ) ;
F_30 ( V_44 ) ;
goto error;
}
return 0 ;
error:
F_19 ( V_229 ) ;
F_19 ( V_230 ) ;
if ( V_44 )
F_20 ( V_44 ) ;
return V_19 ;
}
static int F_154 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_225 V_226 ;
if ( F_108 ( & V_226 , V_184 , sizeof( V_226 ) ) )
return - V_33 ;
return F_138 ( V_8 , & V_226 ,
( ( (struct V_225 T_2 * ) V_184 ) -> V_228 ) ,
V_184 ) ;
}
static int F_155 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_46 * V_46 ;
struct V_42 * V_44 ;
unsigned long V_54 ;
F_27 ( & V_8 -> V_55 , V_54 ) ;
V_44 = F_34 ( V_8 , V_184 ) ;
if ( ! V_44 ) {
F_29 ( & V_8 -> V_55 , V_54 ) ;
return - V_25 ;
}
V_46 = V_44 -> V_46 ;
F_45 ( V_46 ) ;
F_29 ( & V_8 -> V_55 , V_54 ) ;
F_57 ( V_46 ) ;
F_48 ( V_46 ) ;
return 0 ;
}
static int F_156 ( struct V_42 * V_44 , void T_2 * T_2 * V_184 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_225 T_2 * V_60 = V_44 -> V_60 ;
void T_2 * V_270 = V_44 -> V_60 ;
unsigned int V_22 ;
if ( V_44 -> V_80 && V_46 -> V_83 ) {
if ( F_43 ( V_44 -> V_80 , V_46 ) )
goto V_271;
}
if ( F_157 ( V_44 -> V_95 , & V_60 -> V_95 ) )
goto V_271;
if ( F_157 ( V_46 -> V_83 , & V_60 -> V_83 ) )
goto V_271;
if ( F_157 ( V_46 -> V_272 , & V_60 -> V_272 ) )
goto V_271;
if ( F_145 ( & V_46 -> V_70 -> V_41 ) ) {
for ( V_22 = 0 ; V_22 < V_46 -> V_81 ; V_22 ++ ) {
if ( F_157 ( V_46 -> V_228 [ V_22 ] . V_83 ,
& V_60 -> V_228 [ V_22 ] . V_83 ) )
goto V_271;
if ( F_157 ( V_46 -> V_228 [ V_22 ] . V_95 ,
& V_60 -> V_228 [ V_22 ] . V_95 ) )
goto V_271;
}
}
if ( F_157 ( V_270 , ( void T_2 * T_2 * ) V_184 ) )
return - V_33 ;
return 0 ;
V_271:
return - V_33 ;
}
static struct V_42 * F_158 ( struct V_7 * V_8 )
{
F_159 ( V_107 , V_124 ) ;
struct V_42 * V_44 = NULL ;
struct V_18 * V_10 = V_8 -> V_10 ;
F_160 ( & V_8 -> V_107 , & V_107 ) ;
for (; ; ) {
F_161 ( V_273 ) ;
V_44 = F_32 ( V_8 ) ;
if ( V_44 || ! F_7 ( V_8 ) )
break;
if ( F_162 ( V_124 ) )
break;
F_15 ( V_10 ) ;
F_163 () ;
F_10 ( V_10 ) ;
}
F_164 ( & V_8 -> V_107 , & V_107 ) ;
F_165 ( V_274 ) ;
return V_44 ;
}
static int F_166 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_42 * V_44 = F_158 ( V_8 ) ;
if ( V_44 ) {
int V_275 ;
F_53 ( & V_8 -> V_10 -> V_10 , L_32 , V_44 -> V_60 ) ;
V_275 = F_156 ( V_44 , ( void T_2 * T_2 * ) V_184 ) ;
F_20 ( V_44 ) ;
return V_275 ;
}
if ( F_162 ( V_124 ) )
return - V_276 ;
return - V_23 ;
}
static int F_167 ( struct V_7 * V_8 , void T_2 * V_184 )
{
int V_275 ;
struct V_42 * V_44 ;
V_44 = F_32 ( V_8 ) ;
if ( V_44 ) {
F_53 ( & V_8 -> V_10 -> V_10 , L_32 , V_44 -> V_60 ) ;
V_275 = F_156 ( V_44 , ( void T_2 * T_2 * ) V_184 ) ;
F_20 ( V_44 ) ;
} else {
V_275 = ( F_7 ( V_8 ) ? - V_277 : - V_23 ) ;
}
return V_275 ;
}
static int F_168 ( struct V_7 * V_8 ,
struct V_278 T_2 * V_279 )
{
struct V_185 T_2 * V_110 ;
T_8 V_280 ;
V_110 = F_169 ( sizeof( * V_110 ) ) ;
if ( F_170 ( V_110 , V_279 , ( sizeof( * V_279 ) - sizeof( V_281 ) ) ) ||
F_86 ( V_280 , & V_279 -> V_66 ) ||
F_157 ( F_171 ( V_280 ) , & V_110 -> V_66 ) )
return - V_33 ;
return F_107 ( V_8 , V_110 ) ;
}
static int F_172 ( struct V_7 * V_8 ,
struct V_282 T_2 * V_279 )
{
struct V_200 T_2 * V_110 ;
T_9 V_283 ;
V_281 V_270 ;
V_110 = F_169 ( sizeof( * V_110 ) ) ;
if ( F_86 ( V_283 , & V_279 -> V_70 ) || F_157 ( V_283 , & V_110 -> V_70 ) ||
F_86 ( V_283 , & V_279 -> V_20 ) || F_157 ( V_283 , & V_110 -> V_20 ) ||
F_86 ( V_283 , & V_279 -> V_196 ) || F_157 ( V_283 , & V_110 -> V_196 ) ||
F_86 ( V_270 , & V_279 -> V_66 ) || F_157 ( F_171 ( V_270 ) , & V_110 -> V_66 ) )
return - V_33 ;
return F_117 ( V_8 , V_110 ) ;
}
static int F_173 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_284 V_285 ;
if ( F_108 ( & V_285 , V_184 , sizeof( V_285 ) ) )
return - V_33 ;
V_8 -> V_180 = V_285 . V_94 ;
V_8 -> V_182 = F_171 ( V_285 . V_90 ) ;
return 0 ;
}
static int F_174 ( struct V_225 * V_286 ,
struct V_287 T_2 * V_226 )
{
T_8 V_288 ;
if ( ! F_110 ( V_254 , V_226 , sizeof( * V_226 ) ) ||
F_175 ( V_286 -> type , & V_226 -> type ) ||
F_175 ( V_286 -> V_139 , & V_226 -> V_139 ) ||
F_175 ( V_286 -> V_95 , & V_226 -> V_95 ) ||
F_175 ( V_286 -> V_54 , & V_226 -> V_54 ) ||
F_175 ( V_286 -> V_241 , & V_226 -> V_241 ) ||
F_175 ( V_286 -> V_83 , & V_226 -> V_83 ) ||
F_175 ( V_286 -> V_262 , & V_226 -> V_262 ) ||
F_175 ( V_286 -> V_81 , & V_226 -> V_81 ) ||
F_175 ( V_286 -> V_272 , & V_226 -> V_272 ) ||
F_175 ( V_286 -> V_94 , & V_226 -> V_94 ) )
return - V_33 ;
if ( F_175 ( V_288 , & V_226 -> V_242 ) )
return - V_33 ;
V_286 -> V_242 = F_171 ( V_288 ) ;
if ( F_175 ( V_288 , & V_226 -> V_289 ) )
return - V_33 ;
V_286 -> V_289 = F_171 ( V_288 ) ;
return 0 ;
}
static int F_176 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_225 V_226 ;
if ( F_174 ( & V_226 , (struct V_287 T_2 * ) V_184 ) )
return - V_33 ;
return F_138 ( V_8 , & V_226 ,
( (struct V_287 T_2 * ) V_184 ) -> V_228 ,
V_184 ) ;
}
static int F_177 ( struct V_42 * V_44 , void T_2 * T_2 * V_184 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_287 T_2 * V_60 = V_44 -> V_60 ;
void T_2 * V_270 = V_44 -> V_60 ;
unsigned int V_22 ;
if ( V_44 -> V_80 && V_46 -> V_83 ) {
if ( F_43 ( V_44 -> V_80 , V_46 ) )
return - V_33 ;
}
if ( F_157 ( V_44 -> V_95 , & V_60 -> V_95 ) )
return - V_33 ;
if ( F_157 ( V_46 -> V_83 , & V_60 -> V_83 ) )
return - V_33 ;
if ( F_157 ( V_46 -> V_272 , & V_60 -> V_272 ) )
return - V_33 ;
if ( F_145 ( & V_46 -> V_70 -> V_41 ) ) {
for ( V_22 = 0 ; V_22 < V_46 -> V_81 ; V_22 ++ ) {
if ( F_157 ( V_46 -> V_228 [ V_22 ] . V_83 ,
& V_60 -> V_228 [ V_22 ] . V_83 ) )
return - V_33 ;
if ( F_157 ( V_46 -> V_228 [ V_22 ] . V_95 ,
& V_60 -> V_228 [ V_22 ] . V_95 ) )
return - V_33 ;
}
}
if ( F_157 ( F_178 ( V_270 ) , ( T_6 T_2 * ) V_184 ) )
return - V_33 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_42 * V_44 = F_158 ( V_8 ) ;
if ( V_44 ) {
int V_275 ;
F_53 ( & V_8 -> V_10 -> V_10 , L_32 , V_44 -> V_60 ) ;
V_275 = F_177 ( V_44 , ( void T_2 * T_2 * ) V_184 ) ;
F_20 ( V_44 ) ;
return V_275 ;
}
if ( F_162 ( V_124 ) )
return - V_276 ;
return - V_23 ;
}
static int F_180 ( struct V_7 * V_8 , void T_2 * V_184 )
{
int V_275 ;
struct V_42 * V_44 ;
V_44 = F_32 ( V_8 ) ;
if ( V_44 ) {
F_53 ( & V_8 -> V_10 -> V_10 , L_32 , V_44 -> V_60 ) ;
V_275 = F_177 ( V_44 , ( void T_2 * T_2 * ) V_184 ) ;
F_20 ( V_44 ) ;
} else {
V_275 = ( F_7 ( V_8 ) ? - V_277 : - V_23 ) ;
}
return V_275 ;
}
static int F_181 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_290 V_285 ;
if ( F_108 ( & V_285 , V_184 , sizeof( V_285 ) ) )
return - V_33 ;
V_8 -> V_180 = V_285 . V_94 ;
V_8 -> V_182 = V_285 . V_90 ;
return 0 ;
}
static int F_182 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned int V_109 ;
if ( F_86 ( V_109 , ( unsigned int T_2 * ) V_184 ) )
return - V_33 ;
return F_71 ( V_8 , V_109 ) ;
}
static int F_183 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned int V_109 ;
int V_19 ;
if ( F_86 ( V_109 , ( unsigned int T_2 * ) V_184 ) )
return - V_33 ;
V_19 = F_76 ( V_8 , V_109 ) ;
if ( V_19 < 0 )
return V_19 ;
F_58 ( V_8 , V_109 ) ;
return 0 ;
}
static int F_184 ( struct V_7 * V_8 , struct V_291 * V_292 )
{
int V_78 ;
void * V_14 = NULL ;
int V_275 = 0 ;
struct V_113 * V_114 = NULL ;
struct V_293 * V_209 = NULL ;
V_78 = F_185 ( V_292 -> V_294 ) ;
if ( V_78 > 0 ) {
V_14 = F_87 ( V_78 , V_45 ) ;
if ( V_14 == NULL )
return - V_6 ;
if ( ( F_186 ( V_292 -> V_294 ) & V_295 ) ) {
if ( F_108 ( V_14 , V_292 -> V_66 , V_78 ) ) {
F_19 ( V_14 ) ;
return - V_33 ;
}
} else {
memset ( V_14 , 0 , V_78 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_19 ( V_14 ) ;
return - V_23 ;
}
if ( V_8 -> V_10 -> V_11 != V_122 )
V_275 = - V_123 ;
else if ( ! ( V_114 = F_73 ( V_8 -> V_10 , V_292 -> V_296 ) ) )
V_275 = - V_25 ;
else switch ( V_292 -> V_294 ) {
case V_297 :
if ( V_114 -> V_10 . V_209 ) {
V_209 = F_187 ( V_114 -> V_10 . V_209 ) ;
F_188 ( & V_114 -> V_10 , L_33 ) ;
F_78 ( V_209 , V_114 ) ;
} else
V_275 = - V_210 ;
break;
case V_298 :
if ( ! V_114 -> V_10 . V_209 )
V_275 = F_189 ( & V_114 -> V_10 ) ;
else
V_275 = - V_223 ;
break;
default:
if ( V_114 -> V_10 . V_209 )
V_209 = F_187 ( V_114 -> V_10 . V_209 ) ;
if ( V_209 == NULL || V_209 -> V_299 == NULL ) {
V_275 = - V_300 ;
} else {
V_275 = V_209 -> V_299 ( V_114 , V_292 -> V_294 , V_14 ) ;
if ( V_275 == - V_301 )
V_275 = - V_300 ;
}
}
if ( V_275 >= 0
&& ( F_186 ( V_292 -> V_294 ) & V_302 ) != 0
&& V_78 > 0
&& F_12 ( V_292 -> V_66 , V_14 , V_78 ) != 0 )
V_275 = - V_33 ;
F_19 ( V_14 ) ;
return V_275 ;
}
static int F_190 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_291 V_186 ;
if ( F_108 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_33 ;
return F_184 ( V_8 , & V_186 ) ;
}
static int F_191 ( struct V_7 * V_8 , T_10 V_184 )
{
struct V_303 T_2 * V_304 ;
struct V_291 V_186 ;
T_6 V_280 ;
V_304 = F_171 ( ( long ) V_184 ) ;
if ( ! F_110 ( V_254 , V_304 , sizeof( * V_304 ) ) ||
F_175 ( V_186 . V_296 , & V_304 -> V_296 ) ||
F_175 ( V_186 . V_294 , & V_304 -> V_294 ) ||
F_175 ( V_280 , & V_304 -> V_66 ) )
return - V_33 ;
V_186 . V_66 = F_171 ( V_280 ) ;
return F_184 ( V_8 , & V_186 ) ;
}
static int F_192 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned V_305 ;
int V_306 ;
if ( F_86 ( V_305 , ( unsigned T_2 * ) V_184 ) )
return - V_33 ;
V_306 = F_193 ( V_8 -> V_10 , V_305 , V_8 ) ;
if ( V_306 == 0 )
F_53 ( & V_8 -> V_10 -> V_10 , L_34 ,
V_305 , F_80 ( V_124 ) , V_124 -> V_125 ) ;
return V_306 ;
}
static int F_194 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned V_305 ;
if ( F_86 ( V_305 , ( unsigned T_2 * ) V_184 ) )
return - V_33 ;
return F_195 ( V_8 -> V_10 , V_305 , V_8 ) ;
}
static int F_196 ( struct V_7 * V_8 , void T_2 * V_184 )
{
T_8 V_307 ;
V_307 = V_308 | V_309 |
V_310 ;
if ( ! V_8 -> V_10 -> V_250 -> V_311 )
V_307 |= V_312 ;
if ( V_8 -> V_10 -> V_250 -> V_251 )
V_307 |= V_313 ;
if ( F_157 ( V_307 , ( T_8 T_2 * ) V_184 ) )
return - V_33 ;
return 0 ;
}
static int F_197 ( struct V_7 * V_8 , void T_2 * V_184 )
{
struct V_314 V_315 ;
struct V_113 * V_114 ;
if ( F_108 ( & V_315 , V_184 , sizeof( V_315 ) ) )
return - V_33 ;
V_114 = F_73 ( V_8 -> V_10 , V_315 . V_136 ) ;
if ( ! V_114 )
return - V_25 ;
if ( V_114 -> V_10 . V_209 ) {
struct V_293 * V_209 = F_187 ( V_114 -> V_10 . V_209 ) ;
if ( ( V_315 . V_54 & V_316 ) &&
strncmp ( V_315 . V_209 , V_114 -> V_10 . V_209 -> V_211 ,
sizeof( V_315 . V_209 ) ) != 0 )
return - V_223 ;
if ( ( V_315 . V_54 & V_317 ) &&
strncmp ( V_315 . V_209 , V_114 -> V_10 . V_209 -> V_211 ,
sizeof( V_315 . V_209 ) ) == 0 )
return - V_223 ;
F_188 ( & V_114 -> V_10 , L_33 ) ;
F_78 ( V_209 , V_114 ) ;
}
return F_71 ( V_8 , V_315 . V_136 ) ;
}
static int F_198 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned V_166 , V_167 ;
struct V_155 * * V_168 ;
struct V_113 * V_114 ;
int V_318 ;
V_318 = F_85 ( V_8 , V_184 , & V_166 , & V_167 ,
& V_168 , & V_114 ) ;
if ( V_318 )
return V_318 ;
F_58 ( V_8 ,
V_114 -> V_117 [ 0 ] . V_41 . V_118 ) ;
V_318 = F_199 ( V_114 , V_168 , V_167 , V_166 , V_45 ) ;
F_19 ( V_168 ) ;
return V_318 ;
}
static int F_200 ( struct V_7 * V_8 , void T_2 * V_184 )
{
unsigned V_167 ;
struct V_155 * * V_168 ;
struct V_113 * V_114 ;
int V_318 ;
V_318 = F_85 ( V_8 , V_184 , NULL , & V_167 , & V_168 , & V_114 ) ;
if ( V_318 )
return V_318 ;
F_58 ( V_8 ,
V_114 -> V_117 [ 0 ] . V_41 . V_118 ) ;
V_318 = F_201 ( V_114 , V_168 , V_167 , V_45 ) ;
F_19 ( V_168 ) ;
return V_318 ;
}
static long F_202 ( struct V_13 * V_13 , unsigned int V_319 ,
void T_2 * V_110 )
{
struct V_7 * V_8 = V_13 -> V_17 ;
struct V_174 * V_174 = F_203 ( V_13 ) ;
struct V_18 * V_10 = V_8 -> V_10 ;
int V_19 = - V_300 ;
if ( ! ( V_13 -> V_320 & V_321 ) )
return - V_322 ;
F_10 ( V_10 ) ;
switch ( V_319 ) {
case V_323 :
F_53 ( & V_10 -> V_10 , L_35 , V_153 ) ;
V_19 = F_166 ( V_8 , V_110 ) ;
goto V_195;
case V_324 :
F_53 ( & V_10 -> V_10 , L_36 , V_153 ) ;
V_19 = F_167 ( V_8 , V_110 ) ;
goto V_195;
#ifdef F_204
case V_325 :
F_53 ( & V_10 -> V_10 , L_37 , V_153 ) ;
V_19 = F_179 ( V_8 , V_110 ) ;
goto V_195;
case V_326 :
F_53 ( & V_10 -> V_10 , L_38 , V_153 ) ;
V_19 = F_180 ( V_8 , V_110 ) ;
goto V_195;
#endif
}
if ( ! F_7 ( V_8 ) ) {
F_15 ( V_10 ) ;
return - V_23 ;
}
switch ( V_319 ) {
case V_327 :
F_53 ( & V_10 -> V_10 , L_39 , V_153 ) ;
V_19 = F_107 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_330 :
F_53 ( & V_10 -> V_10 , L_40 , V_153 ) ;
V_19 = F_117 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_331 :
F_53 ( & V_10 -> V_10 , L_41 , V_153 ) ;
V_19 = F_123 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_332 :
F_53 ( & V_10 -> V_10 , L_42 , V_153 ) ;
V_19 = F_130 ( V_8 ) ;
break;
case V_333 :
F_53 ( & V_10 -> V_10 , L_43 , V_153 ) ;
V_19 = F_125 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_334 :
F_53 ( & V_10 -> V_10 , L_44 , V_153 ) ;
V_19 = F_127 ( V_8 , V_110 ) ;
break;
case V_335 :
F_53 ( & V_10 -> V_10 , L_45 , V_153 ) ;
V_19 = F_129 ( V_8 , V_110 ) ;
break;
case V_336 :
F_53 ( & V_10 -> V_10 , L_46 , V_153 ) ;
V_19 = F_132 ( V_8 , V_110 ) ;
break;
case V_337 :
F_53 ( & V_10 -> V_10 , L_47 , V_153 ) ;
V_19 = F_134 ( V_8 , V_110 ) ;
break;
case V_338 :
F_53 ( & V_10 -> V_10 , L_48 , V_153 ) ;
V_19 = F_154 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
#ifdef F_204
case V_339 :
F_53 ( & V_10 -> V_10 , L_49 , V_153 ) ;
V_19 = F_168 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_340 :
F_53 ( & V_10 -> V_10 , L_50 , V_153 ) ;
V_19 = F_172 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_341 :
F_53 ( & V_10 -> V_10 , L_51 , V_153 ) ;
V_19 = F_173 ( V_8 , V_110 ) ;
break;
case V_342 :
F_53 ( & V_10 -> V_10 , L_52 , V_153 ) ;
V_19 = F_176 ( V_8 , V_110 ) ;
if ( V_19 >= 0 )
V_174 -> V_328 = V_329 ;
break;
case V_343 :
F_53 ( & V_10 -> V_10 , L_53 , V_153 ) ;
V_19 = F_191 ( V_8 , F_178 ( V_110 ) ) ;
break;
#endif
case V_344 :
F_53 ( & V_10 -> V_10 , L_54 , V_153 , V_110 ) ;
V_19 = F_155 ( V_8 , V_110 ) ;
break;
case V_345 :
F_53 ( & V_10 -> V_10 , L_55 , V_153 ) ;
V_19 = F_181 ( V_8 , V_110 ) ;
break;
case V_346 :
F_53 ( & V_10 -> V_10 , L_56 , V_153 ) ;
V_19 = F_182 ( V_8 , V_110 ) ;
break;
case V_347 :
F_53 ( & V_10 -> V_10 , L_57 , V_153 ) ;
V_19 = F_183 ( V_8 , V_110 ) ;
break;
case V_348 :
F_53 ( & V_10 -> V_10 , L_58 , V_153 ) ;
V_19 = F_190 ( V_8 , V_110 ) ;
break;
case V_349 :
F_53 ( & V_10 -> V_10 , L_59 , V_153 ) ;
V_19 = F_192 ( V_8 , V_110 ) ;
break;
case V_350 :
F_53 ( & V_10 -> V_10 , L_60 , V_153 ) ;
V_19 = F_194 ( V_8 , V_110 ) ;
break;
case V_351 :
V_19 = F_196 ( V_8 , V_110 ) ;
break;
case V_352 :
V_19 = F_197 ( V_8 , V_110 ) ;
break;
case V_353 :
V_19 = F_198 ( V_8 , V_110 ) ;
break;
case V_354 :
V_19 = F_200 ( V_8 , V_110 ) ;
break;
}
V_195:
F_15 ( V_10 ) ;
if ( V_19 >= 0 )
V_174 -> V_355 = V_329 ;
return V_19 ;
}
static long F_205 ( struct V_13 * V_13 , unsigned int V_319 ,
unsigned long V_184 )
{
int V_19 ;
V_19 = F_202 ( V_13 , V_319 , ( void T_2 * ) V_184 ) ;
return V_19 ;
}
static long F_206 ( struct V_13 * V_13 , unsigned int V_319 ,
unsigned long V_184 )
{
int V_19 ;
V_19 = F_202 ( V_13 , V_319 , F_171 ( V_184 ) ) ;
return V_19 ;
}
static unsigned int F_207 ( struct V_13 * V_13 ,
struct V_356 * V_107 )
{
struct V_7 * V_8 = V_13 -> V_17 ;
unsigned int V_357 = 0 ;
F_208 ( V_13 , & V_8 -> V_107 , V_107 ) ;
if ( V_13 -> V_320 & V_321 && ! F_8 ( & V_8 -> V_58 ) )
V_357 |= V_358 | V_359 ;
if ( ! F_7 ( V_8 ) )
V_357 |= V_360 | V_361 ;
return V_357 ;
}
static void F_209 ( struct V_18 * V_61 )
{
struct V_7 * V_8 ;
struct V_91 V_92 ;
while ( ! F_8 ( & V_61 -> V_183 ) ) {
V_8 = F_33 ( V_61 -> V_183 . V_59 , struct V_7 , V_9 ) ;
F_61 ( V_8 ) ;
F_210 ( & V_8 -> V_107 ) ;
F_31 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_180 ) {
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_96 = V_8 -> V_180 ;
V_92 . V_97 = V_199 ;
V_92 . V_98 = V_99 ;
V_92 . V_100 = V_8 -> V_182 ;
F_54 ( V_8 -> V_180 , & V_92 ,
V_8 -> V_181 , V_8 -> V_48 , V_8 -> V_93 ) ;
}
}
}
static int F_211 ( struct V_362 * V_363 ,
unsigned long V_364 , void * V_10 )
{
switch ( V_364 ) {
case V_365 :
break;
case V_366 :
F_209 ( V_10 ) ;
break;
}
return V_367 ;
}
int T_11 F_212 ( void )
{
int V_275 ;
V_275 = F_213 ( V_368 , V_369 ,
L_61 ) ;
if ( V_275 ) {
F_214 ( V_370 L_62 ) ;
goto V_371;
}
F_215 ( & V_372 , & V_373 ) ;
V_275 = F_216 ( & V_372 , V_368 , V_369 ) ;
if ( V_275 ) {
F_214 ( V_370 L_63 ,
V_177 ) ;
goto V_374;
}
F_217 ( & V_375 ) ;
V_371:
return V_275 ;
V_374:
F_218 ( V_368 , V_369 ) ;
goto V_371;
}
void F_219 ( void )
{
F_220 ( & V_375 ) ;
F_221 ( & V_372 ) ;
F_218 ( V_368 , V_369 ) ;
}
