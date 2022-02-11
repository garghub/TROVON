static int F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_4 , T_2 V_5 )
{
struct V_6 * V_7 = V_1 -> V_8 . V_9 ;
unsigned int V_10 , V_11 = 0 ;
int V_12 ;
F_2 ( V_7 , L_1 , V_3 -> V_5 - V_4 ) ;
do {
V_12 = 0 ;
V_10 = F_3 ( V_7 , V_3 , V_4 , 0 , & V_12 ) ;
V_4 += V_10 ;
V_11 += V_10 ;
} while ( V_10 != 0 && V_12 != V_13 );
F_2 ( V_7 , L_2 ,
V_3 -> V_5 - V_4 , V_12 ) ;
return V_11 ;
}
static inline int F_4 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
if ( ( V_15 -> V_17 == V_18 || V_15 -> V_17 == V_19 ) &&
! F_5 ( & V_15 -> V_20 ) ) {
F_2 ( V_7 , L_3 ) ;
F_6 ( V_7 , V_21 ) ;
return - V_22 ;
}
return 0 ;
}
static void F_7 ( struct V_14 * V_15 , int V_23 )
{
struct V_6 * V_7 ;
struct V_24 * V_25 ;
T_1 V_1 ;
F_8 ( & V_15 -> V_26 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_26 ) ;
return;
}
V_25 = V_7 -> V_27 ;
V_1 . V_8 . V_9 = V_7 ;
V_1 . V_28 = 1 ;
F_10 ( V_15 , & V_1 , F_1 ) ;
F_4 ( V_15 ) ;
F_11 ( & V_25 -> V_29 . V_30 ) ;
F_9 ( & V_15 -> V_26 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_24 * V_25 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
void (* F_13)( struct V_14 * );
F_8 ( & V_15 -> V_26 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_26 ) ;
return;
}
V_34 = V_7 -> V_34 ;
F_4 ( V_15 ) ;
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
F_13 = V_32 -> F_13 ;
F_9 ( & V_15 -> V_26 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
void (* F_15)( struct V_14 * );
F_16 ( & V_15 -> V_26 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_17 ( & V_15 -> V_26 ) ;
return;
}
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
F_15 = V_32 -> F_15 ;
F_17 ( & V_15 -> V_26 ) ;
F_15 ( V_15 ) ;
F_2 ( V_7 , L_4 ) ;
F_18 ( V_7 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_14 * V_15 = V_32 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_26 ) ;
V_15 -> V_16 = V_7 ;
V_32 -> V_35 = V_15 -> V_36 ;
V_32 -> F_13 = V_15 -> V_37 ;
V_32 -> F_15 = V_15 -> V_38 ;
V_15 -> V_36 = F_7 ;
V_15 -> V_37 = F_12 ;
V_15 -> V_38 = F_14 ;
F_21 ( & V_15 -> V_26 ) ;
}
static void
F_22 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_14 * V_15 = V_32 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_26 ) ;
V_15 -> V_16 = NULL ;
V_15 -> V_36 = V_32 -> V_35 ;
V_15 -> V_37 = V_32 -> F_13 ;
V_15 -> V_38 = V_32 -> F_15 ;
V_15 -> V_39 = 0 ;
F_21 ( & V_15 -> V_26 ) ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_40 * V_30 )
{
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_41 * V_15 = V_32 -> V_14 ;
unsigned int V_42 = 0 ;
int V_43 = 0 ;
while ( ! F_24 ( V_25 , V_30 , 0 , V_43 ) ) {
struct V_44 * V_45 ;
unsigned int V_4 , V_46 ;
int V_47 = 0 ;
V_43 = 0 ;
V_4 = V_30 -> V_42 ;
V_46 = V_30 -> V_48 - V_4 ;
if ( V_30 -> V_49 + V_30 -> V_48 < V_30 -> V_50 )
V_47 |= V_51 ;
if ( ! V_30 -> V_9 ) {
V_45 = V_30 -> V_45 ;
V_4 += V_30 -> V_52 + V_45 -> V_4 ;
V_43 = V_32 -> V_53 ( V_15 , F_25 ( V_45 ) , V_4 ,
V_46 , V_47 ) ;
} else {
struct V_54 V_55 = { . V_56 = V_47 } ;
struct V_57 V_58 = {
. V_59 = V_30 -> V_9 + V_4 ,
. V_60 = V_46
} ;
V_43 = F_26 ( V_15 , & V_55 , & V_58 , 1 , V_46 ) ;
}
if ( V_43 < 0 ) {
F_11 ( V_30 ) ;
return V_43 ;
}
V_42 += V_43 ;
}
return V_42 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_40 * V_30 = & V_32 -> V_61 . V_30 ;
unsigned int V_10 = 0 ;
int V_62 = 0 ;
while ( 1 ) {
V_62 = F_23 ( V_25 , V_30 ) ;
if ( V_62 == - V_63 )
return V_62 ;
else if ( V_62 < 0 ) {
V_62 = V_64 ;
goto error;
} else if ( V_62 == 0 )
break;
V_10 += V_62 ;
if ( V_30 -> V_49 >= V_30 -> V_50 ) {
if ( V_30 -> V_65 != NULL ) {
V_62 = V_30 -> V_65 ( V_25 , V_30 ) ;
if ( V_62 != 0 )
goto error;
}
}
}
F_2 ( V_7 , L_5 , V_10 ) ;
V_7 -> V_66 += V_10 ;
return V_10 ;
error:
F_2 ( V_7 , L_6 , V_62 ) ;
F_6 ( V_7 , V_62 ) ;
return - V_67 ;
}
static inline int F_28 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_40 * V_30 = & V_32 -> V_61 . V_30 ;
return V_30 -> V_49 - V_30 -> V_50 ;
}
static int F_29 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
int V_62 ;
while ( F_28 ( V_7 ) ) {
V_62 = F_27 ( V_7 ) ;
if ( V_62 == 0 )
return - V_63 ;
if ( V_62 < 0 )
return V_62 ;
}
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_40 * V_30 )
{
struct V_31 * V_32 = V_25 -> V_27 ;
V_32 -> V_61 . V_30 = V_32 -> V_61 . V_70 ;
F_2 ( V_25 -> V_6 ,
L_7 ,
V_32 -> V_61 . V_30 . V_48 ,
V_32 -> V_61 . V_30 . V_50 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , void * V_71 ,
T_2 V_72 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
F_2 ( V_7 , L_8 , V_7 -> V_73 ?
L_9 : L_10 ) ;
memset ( & V_32 -> V_61 . V_70 , 0 ,
sizeof( struct V_40 ) ) ;
if ( V_7 -> V_73 ) {
F_32 ( & V_32 -> V_74 , V_71 , V_72 ,
V_71 + V_72 ) ;
V_72 += V_75 ;
}
V_32 -> V_61 . V_71 = V_71 ;
F_33 ( & V_32 -> V_61 . V_30 , V_71 , V_72 ,
F_30 , NULL ) ;
}
static int
F_34 ( struct V_6 * V_7 , struct V_44 * V_45 ,
unsigned int V_28 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_76 * V_74 = NULL ;
unsigned int V_77 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_78 ?
L_9 : L_10 ) ;
V_77 = F_35 ( V_32 -> V_61 . V_71 -> V_79 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_77 ) ) ;
if ( V_7 -> V_78 )
V_74 = & V_32 -> V_74 ;
return F_38 ( & V_32 -> V_61 . V_70 ,
V_45 , V_28 , V_4 , V_5 ,
NULL , V_74 ) ;
}
static void
F_39 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_76 * V_74 = NULL ;
unsigned int V_77 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_78 ?
L_9 : L_10 ) ;
V_77 = F_35 ( V_32 -> V_61 . V_71 -> V_79 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_77 ) ) ;
if ( V_7 -> V_78 )
V_74 = & V_32 -> V_74 ;
F_33 ( & V_32 -> V_61 . V_70 ,
V_9 , V_5 , NULL , V_74 ) ;
}
static int F_40 ( struct V_68 * V_69 ,
unsigned int V_4 , unsigned int V_28 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
int V_80 = 0 ;
F_31 ( V_7 , V_69 -> V_71 , V_69 -> V_81 ) ;
if ( ! V_28 )
return 0 ;
if ( ! V_69 -> V_82 )
F_39 ( V_7 , V_69 -> V_9 , V_28 ) ;
else {
struct V_83 * V_84 = F_41 ( V_69 -> V_82 ) ;
V_80 = F_34 ( V_7 , V_84 -> V_85 . V_86 ,
V_84 -> V_85 . V_87 , V_4 ,
V_28 ) ;
}
if ( V_80 ) {
return - V_67 ;
}
return 0 ;
}
static int F_42 ( struct V_68 * V_69 , T_3 V_88 )
{
struct V_89 * V_90 = V_69 -> V_27 ;
V_69 -> V_71 = V_69 -> V_27 + sizeof( * V_90 ) ;
V_69 -> V_91 = sizeof( struct V_92 ) - V_75 ;
return 0 ;
}
static struct V_93 *
F_43 ( struct V_94 * V_95 ,
T_4 V_96 )
{
struct V_6 * V_7 ;
struct V_93 * V_97 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
V_97 = F_44 ( V_95 , sizeof( * V_32 ) ,
V_96 ) ;
if ( ! V_97 )
return NULL ;
V_7 = V_97 -> V_27 ;
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
V_32 -> V_74 . V_98 = F_45 ( L_13 , 0 ,
V_99 ) ;
V_32 -> V_74 . V_47 = 0 ;
if ( F_46 ( V_32 -> V_74 . V_98 ) )
goto V_100;
V_32 -> V_101 . V_98 = F_45 ( L_13 , 0 ,
V_99 ) ;
V_32 -> V_101 . V_47 = 0 ;
if ( F_46 ( V_32 -> V_101 . V_98 ) )
goto V_102;
V_25 -> V_101 = & V_32 -> V_101 ;
return V_97 ;
V_102:
F_47 ( V_32 -> V_74 . V_98 ) ;
V_100:
F_48 ( V_103 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_49 ( V_97 ) ;
return NULL ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_41 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
F_51 ( V_14 -> V_15 ) ;
F_22 ( V_7 ) ;
F_52 ( V_14 -> V_15 ) ;
F_53 ( & V_34 -> V_104 ) ;
V_32 -> V_14 = NULL ;
F_54 ( & V_34 -> V_104 ) ;
F_55 ( V_14 ) ;
}
static void F_56 ( struct V_93 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
F_50 ( V_7 ) ;
if ( V_32 -> V_74 . V_98 )
F_47 ( V_32 -> V_74 . V_98 ) ;
if ( V_32 -> V_101 . V_98 )
F_47 ( V_32 -> V_101 . V_98 ) ;
F_49 ( V_97 ) ;
}
static void F_57 ( struct V_93 * V_97 , int V_23 )
{
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_41 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_105 = V_67 ;
F_58 ( F_59 ( V_14 -> V_15 ) ) ;
F_60 ( V_7 ) ;
F_50 ( V_7 ) ;
F_61 ( V_97 , V_23 ) ;
}
static int
F_62 ( struct V_94 * V_95 ,
struct V_93 * V_97 , T_5 V_106 ,
int V_107 )
{
struct V_33 * V_34 = V_95 -> V_27 ;
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_14 * V_15 ;
struct V_41 * V_14 ;
int V_80 ;
V_14 = F_63 ( ( int ) V_106 , & V_80 ) ;
if ( ! V_14 ) {
F_48 ( V_103 , V_7 ,
L_18 , V_80 ) ;
return - V_108 ;
}
V_80 = F_64 ( V_95 , V_97 , V_107 ) ;
if ( V_80 )
goto V_109;
F_53 ( & V_34 -> V_104 ) ;
V_32 -> V_14 = V_14 ;
F_54 ( & V_34 -> V_104 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_110 = 1 ;
V_15 -> V_111 = 15 * V_112 ;
V_15 -> V_113 = V_114 ;
F_19 ( V_7 ) ;
V_32 -> V_53 = V_32 -> V_14 -> V_115 -> V_53 ;
F_65 ( V_25 ) ;
return 0 ;
V_109:
F_55 ( V_14 ) ;
return V_80 ;
}
static int F_66 ( struct V_93 * V_97 ,
enum V_116 V_117 , char * V_118 ,
int V_119 )
{
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
switch( V_117 ) {
case V_120 :
F_67 ( V_97 , V_117 , V_118 , V_119 ) ;
break;
case V_121 :
F_67 ( V_97 , V_117 , V_118 , V_119 ) ;
V_32 -> V_53 = V_7 -> V_78 ?
V_122 : V_32 -> V_14 -> V_115 -> V_53 ;
break;
case V_123 :
return F_68 ( V_7 , V_118 ) ;
default:
return F_67 ( V_97 , V_117 , V_118 , V_119 ) ;
}
return 0 ;
}
static int F_69 ( struct V_93 * V_97 ,
enum V_116 V_117 , char * V_118 )
{
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_124 V_125 ;
int V_62 , V_5 ;
switch( V_117 ) {
case V_126 :
case V_127 :
F_53 ( & V_7 -> V_34 -> V_104 ) ;
if ( ! V_32 || ! V_32 -> V_14 ) {
F_54 ( & V_7 -> V_34 -> V_104 ) ;
return - V_128 ;
}
V_62 = F_70 ( V_32 -> V_14 ,
(struct V_129 * ) & V_125 , & V_5 ) ;
F_54 ( & V_7 -> V_34 -> V_104 ) ;
if ( V_62 )
return V_62 ;
return F_71 ( (struct V_130 * )
& V_125 , V_117 , V_118 ) ;
default:
return F_72 ( V_97 , V_117 , V_118 ) ;
}
return 0 ;
}
static int F_73 ( struct V_131 * V_132 ,
enum V_133 V_117 , char * V_118 )
{
struct V_134 * V_135 = F_74 ( V_132 ) ;
struct V_33 * V_34 = V_135 -> V_34 ;
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
struct V_124 V_125 ;
int V_62 , V_5 ;
switch ( V_117 ) {
case V_136 :
F_53 ( & V_34 -> V_104 ) ;
V_7 = V_34 -> V_137 ;
if ( ! V_7 ) {
F_54 ( & V_34 -> V_104 ) ;
return - V_128 ;
}
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
if ( ! V_32 -> V_14 ) {
F_54 ( & V_34 -> V_104 ) ;
return - V_128 ;
}
V_62 = F_75 ( V_32 -> V_14 ,
(struct V_129 * ) & V_125 , & V_5 ) ;
F_54 ( & V_34 -> V_104 ) ;
if ( V_62 )
return V_62 ;
return F_71 ( (struct V_130 * )
& V_125 , V_117 , V_118 ) ;
default:
return F_76 ( V_132 , V_117 , V_118 ) ;
}
return 0 ;
}
static void
F_77 ( struct V_93 * V_97 ,
struct V_138 * V_139 )
{
struct V_6 * V_7 = V_97 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
V_139 -> V_140 = 3 ;
strcpy ( V_139 -> V_141 [ 0 ] . V_142 , L_19 ) ;
V_139 -> V_141 [ 0 ] . V_143 = V_32 -> V_144 ;
strcpy ( V_139 -> V_141 [ 1 ] . V_142 , L_20 ) ;
V_139 -> V_141 [ 1 ] . V_143 = V_32 -> V_145 ;
strcpy ( V_139 -> V_141 [ 2 ] . V_142 , L_21 ) ;
V_139 -> V_141 [ 2 ] . V_143 = V_7 -> V_146 ;
F_78 ( V_97 , V_139 ) ;
}
static struct V_94 *
F_79 ( struct V_147 * V_148 , T_6 V_149 ,
T_6 V_150 , T_4 V_151 )
{
struct V_94 * V_95 ;
struct V_33 * V_34 ;
struct V_134 * V_135 ;
struct V_131 * V_132 ;
if ( V_148 ) {
F_80 ( V_103 L_22 , V_148 ) ;
return NULL ;
}
V_132 = F_81 ( & V_152 ,
sizeof( struct V_134 ) , 1 ) ;
if ( ! V_132 )
return NULL ;
V_132 -> V_153 = V_154 ;
V_132 -> V_155 = V_150 ;
V_132 -> V_156 = V_157 ;
V_132 -> V_158 = 0 ;
V_132 -> V_159 = 0 ;
V_132 -> V_160 = V_161 ;
if ( F_82 ( V_132 , NULL ) )
goto V_162;
V_95 = F_83 ( & V_163 , V_132 ,
V_149 , 0 ,
sizeof( struct V_89 ) +
sizeof( struct V_92 ) ,
V_151 , 0 ) ;
if ( ! V_95 )
goto V_164;
V_34 = V_95 -> V_27 ;
V_135 = F_74 ( V_132 ) ;
V_135 -> V_34 = V_34 ;
V_132 -> V_165 = V_34 -> V_166 ;
if ( F_84 ( V_34 ) )
goto V_167;
return V_95 ;
V_167:
F_85 ( V_95 ) ;
V_164:
F_86 ( V_132 ) ;
V_162:
F_87 ( V_132 ) ;
return NULL ;
}
static void F_88 ( struct V_94 * V_95 )
{
struct V_131 * V_132 = F_89 ( V_95 ) ;
F_90 ( V_95 -> V_27 ) ;
F_85 ( V_95 ) ;
F_86 ( V_132 ) ;
F_87 ( V_132 ) ;
}
static T_7 F_91 ( int V_168 , int V_117 )
{
switch ( V_168 ) {
case V_169 :
switch ( V_117 ) {
case V_170 :
case V_171 :
case V_136 :
case V_172 :
return V_173 ;
default:
return 0 ;
}
case V_174 :
switch ( V_117 ) {
case V_175 :
case V_176 :
case V_120 :
case V_121 :
case V_127 :
case V_126 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_123 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
return V_173 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_92 ( struct V_201 * V_202 )
{
F_93 ( V_203 , & V_202 -> V_204 -> V_205 ) ;
return 0 ;
}
static int F_94 ( struct V_201 * V_202 )
{
F_95 ( V_202 -> V_204 , V_206 ) ;
F_96 ( V_202 -> V_204 , 0 ) ;
return 0 ;
}
static int T_8 F_97 ( void )
{
if ( V_157 < 1 ) {
F_80 ( V_103 L_23 ,
V_157 ) ;
return - V_207 ;
}
V_154 = F_98 (
& V_163 ) ;
if ( ! V_154 )
return - V_208 ;
return 0 ;
}
static void T_9 F_99 ( void )
{
F_100 ( & V_163 ) ;
}
