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
struct V_6 * V_7 = (struct V_6 * ) V_15 -> V_16 ;
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
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_24 * V_25 = V_7 -> V_26 ;
T_1 V_1 ;
F_8 ( & V_15 -> V_27 ) ;
V_1 . V_8 . V_9 = V_7 ;
V_1 . V_28 = 1 ;
F_9 ( V_15 , & V_1 , F_1 ) ;
F_4 ( V_15 ) ;
F_10 ( & V_15 -> V_27 ) ;
F_11 ( & V_25 -> V_29 . V_30 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_24 * V_25 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
void (* F_13)( struct V_14 * );
F_8 ( & V_15 -> V_27 ) ;
V_7 = (struct V_6 * ) V_15 -> V_16 ;
V_34 = V_7 -> V_34 ;
F_4 ( V_15 ) ;
V_25 = V_7 -> V_26 ;
V_32 = V_25 -> V_26 ;
F_13 = V_32 -> F_13 ;
F_10 ( & V_15 -> V_27 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = (struct V_6 * ) V_15 -> V_16 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
V_32 -> V_35 ( V_15 ) ;
F_2 ( V_7 , L_4 ) ;
F_15 ( V_7 ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_14 * V_15 = V_32 -> V_14 -> V_15 ;
F_17 ( & V_15 -> V_27 ) ;
V_15 -> V_16 = V_7 ;
V_32 -> V_36 = V_15 -> V_37 ;
V_32 -> F_13 = V_15 -> V_38 ;
V_32 -> V_35 = V_15 -> V_39 ;
V_15 -> V_37 = F_7 ;
V_15 -> V_38 = F_12 ;
V_15 -> V_39 = F_14 ;
F_18 ( & V_15 -> V_27 ) ;
}
static void
F_19 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_14 * V_15 = V_32 -> V_14 -> V_15 ;
F_17 ( & V_15 -> V_27 ) ;
V_15 -> V_16 = NULL ;
V_15 -> V_37 = V_32 -> V_36 ;
V_15 -> V_38 = V_32 -> F_13 ;
V_15 -> V_39 = V_32 -> V_35 ;
V_15 -> V_40 = 0 ;
F_18 ( & V_15 -> V_27 ) ;
}
static int F_20 ( struct V_24 * V_25 ,
struct V_41 * V_30 )
{
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_42 * V_15 = V_32 -> V_14 ;
unsigned int V_43 = 0 ;
int V_44 = 0 ;
while ( ! F_21 ( V_25 , V_30 , 0 , V_44 ) ) {
struct V_45 * V_46 ;
unsigned int V_4 , V_47 ;
int V_48 = 0 ;
V_44 = 0 ;
V_4 = V_30 -> V_43 ;
V_47 = V_30 -> V_49 - V_4 ;
if ( V_30 -> V_50 + V_30 -> V_49 < V_30 -> V_51 )
V_48 |= V_52 ;
if ( ! V_30 -> V_9 ) {
V_46 = V_30 -> V_46 ;
V_4 += V_30 -> V_53 + V_46 -> V_4 ;
V_44 = V_32 -> V_54 ( V_15 , F_22 ( V_46 ) , V_4 ,
V_47 , V_48 ) ;
} else {
struct V_55 V_56 = { . V_57 = V_48 } ;
struct V_58 V_59 = {
. V_60 = V_30 -> V_9 + V_4 ,
. V_61 = V_47
} ;
V_44 = F_23 ( V_15 , & V_56 , & V_59 , 1 , V_47 ) ;
}
if ( V_44 < 0 ) {
F_11 ( V_30 ) ;
return V_44 ;
}
V_43 += V_44 ;
}
return V_43 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_41 * V_30 = & V_32 -> V_62 . V_30 ;
unsigned int V_10 = 0 ;
int V_63 = 0 ;
while ( 1 ) {
V_63 = F_20 ( V_25 , V_30 ) ;
if ( V_63 == - V_64 )
return V_63 ;
else if ( V_63 < 0 ) {
V_63 = V_65 ;
goto error;
} else if ( V_63 == 0 )
break;
V_10 += V_63 ;
if ( V_30 -> V_50 >= V_30 -> V_51 ) {
if ( V_30 -> V_66 != NULL ) {
V_63 = V_30 -> V_66 ( V_25 , V_30 ) ;
if ( V_63 != 0 )
goto error;
}
}
}
F_2 ( V_7 , L_5 , V_10 ) ;
V_7 -> V_67 += V_10 ;
return V_10 ;
error:
F_2 ( V_7 , L_6 , V_63 ) ;
F_6 ( V_7 , V_63 ) ;
return - V_68 ;
}
static inline int F_25 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_41 * V_30 = & V_32 -> V_62 . V_30 ;
return V_30 -> V_50 - V_30 -> V_51 ;
}
static int F_26 ( struct V_69 * V_70 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
int V_63 ;
while ( F_25 ( V_7 ) ) {
V_63 = F_24 ( V_7 ) ;
if ( V_63 == 0 )
return - V_64 ;
if ( V_63 < 0 )
return V_63 ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
struct V_41 * V_30 )
{
struct V_31 * V_32 = V_25 -> V_26 ;
V_32 -> V_62 . V_30 = V_32 -> V_62 . V_71 ;
F_2 ( V_25 -> V_6 ,
L_7 ,
V_32 -> V_62 . V_30 . V_49 ,
V_32 -> V_62 . V_30 . V_51 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 , void * V_72 ,
T_2 V_73 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
F_2 ( V_7 , L_8 , V_7 -> V_74 ?
L_9 : L_10 ) ;
memset ( & V_32 -> V_62 . V_71 , 0 ,
sizeof( struct V_41 ) ) ;
if ( V_7 -> V_74 ) {
F_29 ( & V_32 -> V_75 , V_72 , V_73 ,
V_72 + V_73 ) ;
V_73 += V_76 ;
}
V_32 -> V_62 . V_72 = V_72 ;
F_30 ( & V_32 -> V_62 . V_30 , V_72 , V_73 ,
F_27 , NULL ) ;
}
static int
F_31 ( struct V_6 * V_7 , struct V_45 * V_46 ,
unsigned int V_28 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_77 * V_75 = NULL ;
unsigned int V_78 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_79 ?
L_9 : L_10 ) ;
V_78 = F_32 ( V_32 -> V_62 . V_72 -> V_80 ) ;
F_33 ( F_34 ( V_5 ) != F_34 ( V_78 ) ) ;
if ( V_7 -> V_79 )
V_75 = & V_32 -> V_75 ;
return F_35 ( & V_32 -> V_62 . V_71 ,
V_46 , V_28 , V_4 , V_5 ,
NULL , V_75 ) ;
}
static void
F_36 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_77 * V_75 = NULL ;
unsigned int V_78 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_79 ?
L_9 : L_10 ) ;
V_78 = F_32 ( V_32 -> V_62 . V_72 -> V_80 ) ;
F_33 ( F_34 ( V_5 ) != F_34 ( V_78 ) ) ;
if ( V_7 -> V_79 )
V_75 = & V_32 -> V_75 ;
F_30 ( & V_32 -> V_62 . V_71 ,
V_9 , V_5 , NULL , V_75 ) ;
}
static int F_37 ( struct V_69 * V_70 ,
unsigned int V_4 , unsigned int V_28 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
int V_81 = 0 ;
F_28 ( V_7 , V_70 -> V_72 , V_70 -> V_82 ) ;
if ( ! V_28 )
return 0 ;
if ( ! V_70 -> V_83 )
F_36 ( V_7 , V_70 -> V_9 , V_28 ) ;
else {
struct V_84 * V_85 = F_38 ( V_70 -> V_83 ) ;
V_81 = F_31 ( V_7 , V_85 -> V_86 . V_87 ,
V_85 -> V_86 . V_88 , V_4 ,
V_28 ) ;
}
if ( V_81 ) {
return - V_68 ;
}
return 0 ;
}
static int F_39 ( struct V_69 * V_70 , T_3 V_89 )
{
struct V_90 * V_91 = V_70 -> V_26 ;
V_70 -> V_72 = V_70 -> V_26 + sizeof( * V_91 ) ;
V_70 -> V_92 = sizeof( struct V_93 ) - V_76 ;
return 0 ;
}
static struct V_94 *
F_40 ( struct V_95 * V_96 ,
T_4 V_97 )
{
struct V_6 * V_7 ;
struct V_94 * V_98 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
V_98 = F_41 ( V_96 , sizeof( * V_32 ) ,
V_97 ) ;
if ( ! V_98 )
return NULL ;
V_7 = V_98 -> V_26 ;
V_25 = V_7 -> V_26 ;
V_32 = V_25 -> V_26 ;
V_32 -> V_75 . V_99 = F_42 ( L_13 , 0 ,
V_100 ) ;
V_32 -> V_75 . V_48 = 0 ;
if ( F_43 ( V_32 -> V_75 . V_99 ) )
goto V_101;
V_32 -> V_102 . V_99 = F_42 ( L_13 , 0 ,
V_100 ) ;
V_32 -> V_102 . V_48 = 0 ;
if ( F_43 ( V_32 -> V_102 . V_99 ) )
goto V_103;
V_25 -> V_102 = & V_32 -> V_102 ;
return V_98 ;
V_103:
F_44 ( V_32 -> V_75 . V_99 ) ;
V_101:
F_45 ( V_104 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_46 ( V_98 ) ;
return NULL ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_42 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
F_48 ( V_14 -> V_15 ) ;
F_19 ( V_7 ) ;
F_49 ( V_14 -> V_15 ) ;
F_50 ( & V_34 -> V_105 ) ;
V_32 -> V_14 = NULL ;
F_51 ( & V_34 -> V_105 ) ;
F_52 ( V_14 ) ;
}
static void F_53 ( struct V_94 * V_98 )
{
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
F_47 ( V_7 ) ;
if ( V_32 -> V_75 . V_99 )
F_44 ( V_32 -> V_75 . V_99 ) ;
if ( V_32 -> V_102 . V_99 )
F_44 ( V_32 -> V_102 . V_99 ) ;
F_46 ( V_98 ) ;
}
static void F_54 ( struct V_94 * V_98 , int V_23 )
{
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_42 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
F_17 ( & V_32 -> V_14 -> V_15 -> V_27 ) ;
F_55 ( V_106 , & V_7 -> V_107 ) ;
F_18 ( & V_32 -> V_14 -> V_15 -> V_27 ) ;
V_14 -> V_15 -> V_108 = V_68 ;
F_56 ( F_57 ( V_14 -> V_15 ) ) ;
F_58 ( V_98 , V_23 ) ;
F_47 ( V_7 ) ;
}
static int
F_59 ( struct V_95 * V_96 ,
struct V_94 * V_98 , T_5 V_109 ,
int V_110 )
{
struct V_33 * V_34 = V_96 -> V_26 ;
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_14 * V_15 ;
struct V_42 * V_14 ;
int V_81 ;
V_14 = F_60 ( ( int ) V_109 , & V_81 ) ;
if ( ! V_14 ) {
F_45 ( V_104 , V_7 ,
L_18 , V_81 ) ;
return - V_111 ;
}
V_81 = F_61 ( V_96 , V_98 , V_110 ) ;
if ( V_81 )
goto V_112;
F_50 ( & V_34 -> V_105 ) ;
V_32 -> V_14 = V_14 ;
F_51 ( & V_34 -> V_105 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_113 = 1 ;
V_15 -> V_114 = 15 * V_115 ;
V_15 -> V_116 = V_117 ;
F_16 ( V_7 ) ;
V_32 -> V_54 = V_32 -> V_14 -> V_118 -> V_54 ;
F_62 ( V_25 ) ;
return 0 ;
V_112:
F_52 ( V_14 ) ;
return V_81 ;
}
static int F_63 ( struct V_94 * V_98 ,
enum V_119 V_120 , char * V_121 ,
int V_122 )
{
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
int V_123 ;
switch( V_120 ) {
case V_124 :
F_64 ( V_98 , V_120 , V_121 , V_122 ) ;
break;
case V_125 :
F_64 ( V_98 , V_120 , V_121 , V_122 ) ;
V_32 -> V_54 = V_7 -> V_79 ?
V_126 : V_32 -> V_14 -> V_118 -> V_54 ;
break;
case V_127 :
sscanf ( V_121 , L_19 , & V_123 ) ;
if ( V_123 <= 0 || ! F_65 ( V_123 ) )
return - V_128 ;
if ( V_34 -> V_129 == V_123 )
break;
F_66 ( V_34 ) ;
F_64 ( V_98 , V_120 , V_121 , V_122 ) ;
if ( F_67 ( V_34 ) )
return - V_130 ;
break;
default:
return F_64 ( V_98 , V_120 , V_121 , V_122 ) ;
}
return 0 ;
}
static int F_68 ( struct V_94 * V_98 ,
enum V_119 V_120 , char * V_121 )
{
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
struct V_131 V_132 ;
int V_63 , V_5 ;
switch( V_120 ) {
case V_133 :
case V_134 :
F_50 ( & V_7 -> V_34 -> V_105 ) ;
if ( ! V_32 || ! V_32 -> V_14 ) {
F_51 ( & V_7 -> V_34 -> V_105 ) ;
return - V_135 ;
}
V_63 = F_69 ( V_32 -> V_14 ,
(struct V_136 * ) & V_132 , & V_5 ) ;
F_51 ( & V_7 -> V_34 -> V_105 ) ;
if ( V_63 )
return V_63 ;
return F_70 ( (struct V_137 * )
& V_132 , V_120 , V_121 ) ;
default:
return F_71 ( V_98 , V_120 , V_121 ) ;
}
return 0 ;
}
static int F_72 ( struct V_138 * V_139 ,
enum V_140 V_120 , char * V_121 )
{
struct V_141 * V_142 = F_73 ( V_139 ) ;
struct V_33 * V_34 = V_142 -> V_34 ;
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
struct V_131 V_132 ;
int V_63 , V_5 ;
switch ( V_120 ) {
case V_143 :
F_50 ( & V_34 -> V_105 ) ;
V_7 = V_34 -> V_144 ;
if ( ! V_7 ) {
F_51 ( & V_34 -> V_105 ) ;
return - V_135 ;
}
V_25 = V_7 -> V_26 ;
V_32 = V_25 -> V_26 ;
if ( ! V_32 -> V_14 ) {
F_51 ( & V_34 -> V_105 ) ;
return - V_135 ;
}
V_63 = F_74 ( V_32 -> V_14 ,
(struct V_136 * ) & V_132 , & V_5 ) ;
F_51 ( & V_34 -> V_105 ) ;
if ( V_63 )
return V_63 ;
return F_70 ( (struct V_137 * )
& V_132 , V_120 , V_121 ) ;
default:
return F_75 ( V_139 , V_120 , V_121 ) ;
}
return 0 ;
}
static void
F_76 ( struct V_94 * V_98 ,
struct V_145 * V_146 )
{
struct V_6 * V_7 = V_98 -> V_26 ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_31 * V_32 = V_25 -> V_26 ;
V_146 -> V_147 = 3 ;
strcpy ( V_146 -> V_148 [ 0 ] . V_149 , L_20 ) ;
V_146 -> V_148 [ 0 ] . V_123 = V_32 -> V_150 ;
strcpy ( V_146 -> V_148 [ 1 ] . V_149 , L_21 ) ;
V_146 -> V_148 [ 1 ] . V_123 = V_32 -> V_151 ;
strcpy ( V_146 -> V_148 [ 2 ] . V_149 , L_22 ) ;
V_146 -> V_148 [ 2 ] . V_123 = V_7 -> V_152 ;
F_77 ( V_98 , V_146 ) ;
}
static struct V_95 *
F_78 ( struct V_153 * V_154 , T_6 V_155 ,
T_6 V_156 , T_4 V_157 )
{
struct V_95 * V_96 ;
struct V_33 * V_34 ;
struct V_141 * V_142 ;
struct V_138 * V_139 ;
if ( V_154 ) {
F_79 ( V_104 L_23 , V_154 ) ;
return NULL ;
}
V_139 = F_80 ( & V_158 ,
sizeof( struct V_141 ) , 1 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_159 = V_160 ;
V_139 -> V_161 = V_156 ;
V_139 -> V_162 = V_163 ;
V_139 -> V_164 = 0 ;
V_139 -> V_165 = 0 ;
V_139 -> V_166 = V_167 ;
if ( F_81 ( V_139 , NULL ) )
goto V_168;
V_96 = F_82 ( & V_169 , V_139 ,
V_155 , 0 ,
sizeof( struct V_90 ) +
sizeof( struct V_93 ) ,
V_157 , 0 ) ;
if ( ! V_96 )
goto V_170;
V_34 = V_96 -> V_26 ;
V_142 = F_73 ( V_139 ) ;
V_142 -> V_34 = V_34 ;
V_139 -> V_171 = V_34 -> V_172 ;
if ( F_67 ( V_34 ) )
goto V_173;
return V_96 ;
V_173:
F_83 ( V_96 ) ;
V_170:
F_84 ( V_139 ) ;
V_168:
F_85 ( V_139 ) ;
return NULL ;
}
static void F_86 ( struct V_95 * V_96 )
{
struct V_138 * V_139 = F_87 ( V_96 ) ;
F_66 ( V_96 -> V_26 ) ;
F_83 ( V_96 ) ;
F_84 ( V_139 ) ;
F_85 ( V_139 ) ;
}
static int F_88 ( struct V_174 * V_175 )
{
F_55 ( V_176 , & V_175 -> V_177 -> V_178 ) ;
return 0 ;
}
static int F_89 ( struct V_174 * V_175 )
{
F_90 ( V_175 -> V_177 , V_179 ) ;
F_91 ( V_175 -> V_177 , 0 ) ;
return 0 ;
}
static int T_7 F_92 ( void )
{
if ( V_163 < 1 ) {
F_79 ( V_104 L_24 ,
V_163 ) ;
return - V_128 ;
}
V_160 = F_93 (
& V_169 ) ;
if ( ! V_160 )
return - V_180 ;
return 0 ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_169 ) ;
}
