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
( V_7 -> V_20 -> V_21 != V_22 ) &&
! F_5 ( & V_15 -> V_23 ) ) {
F_2 ( V_7 , L_3 ) ;
F_6 ( V_7 , V_24 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_26 * V_27 ;
T_1 V_1 ;
F_8 ( & V_15 -> V_28 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_28 ) ;
return;
}
V_27 = V_7 -> V_29 ;
V_1 . V_8 . V_9 = V_7 ;
V_1 . V_30 = 1 ;
F_10 ( V_15 , & V_1 , F_1 ) ;
F_4 ( V_15 ) ;
F_11 ( & V_27 -> V_31 . V_32 ) ;
F_9 ( & V_15 -> V_28 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_6 * V_7 ;
struct V_35 * V_20 ;
void (* F_13)( struct V_14 * );
F_8 ( & V_15 -> V_28 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_28 ) ;
return;
}
V_20 = V_7 -> V_20 ;
F_4 ( V_15 ) ;
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
F_13 = V_34 -> F_13 ;
F_9 ( & V_15 -> V_28 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
void (* F_15)( struct V_14 * );
F_8 ( & V_15 -> V_28 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_28 ) ;
return;
}
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
F_15 = V_34 -> F_15 ;
F_9 ( & V_15 -> V_28 ) ;
F_15 ( V_15 ) ;
F_2 ( V_7 , L_4 ) ;
F_16 ( V_7 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 = V_34 -> V_14 -> V_15 ;
F_18 ( & V_15 -> V_28 ) ;
V_15 -> V_16 = V_7 ;
V_34 -> V_36 = V_15 -> V_37 ;
V_34 -> F_13 = V_15 -> V_38 ;
V_34 -> F_15 = V_15 -> V_39 ;
V_15 -> V_37 = F_7 ;
V_15 -> V_38 = F_12 ;
V_15 -> V_39 = F_14 ;
F_19 ( & V_15 -> V_28 ) ;
}
static void
F_20 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 = V_34 -> V_14 -> V_15 ;
F_18 ( & V_15 -> V_28 ) ;
V_15 -> V_16 = NULL ;
V_15 -> V_37 = V_34 -> V_36 ;
V_15 -> V_38 = V_34 -> F_13 ;
V_15 -> V_39 = V_34 -> F_15 ;
V_15 -> V_40 = 0 ;
F_19 ( & V_15 -> V_28 ) ;
}
static int F_21 ( struct V_26 * V_27 ,
struct V_41 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_15 = V_34 -> V_14 ;
unsigned int V_43 = 0 ;
int V_44 = 0 ;
while ( ! F_22 ( V_27 , V_32 , 0 , V_44 ) ) {
struct V_45 * V_46 ;
unsigned int V_4 , V_47 ;
int V_48 = 0 ;
V_44 = 0 ;
V_4 = V_32 -> V_43 ;
V_47 = V_32 -> V_49 - V_4 ;
if ( V_32 -> V_50 + V_32 -> V_49 < V_32 -> V_51 )
V_48 |= V_52 ;
if ( ! V_32 -> V_9 ) {
V_46 = V_32 -> V_46 ;
V_4 += V_32 -> V_53 + V_46 -> V_4 ;
V_44 = V_34 -> V_54 ( V_15 , F_23 ( V_46 ) , V_4 ,
V_47 , V_48 ) ;
} else {
struct V_55 V_56 = { . V_57 = V_48 } ;
struct V_58 V_59 = {
. V_60 = V_32 -> V_9 + V_4 ,
. V_61 = V_47
} ;
V_44 = F_24 ( V_15 , & V_56 , & V_59 , 1 , V_47 ) ;
}
if ( V_44 < 0 ) {
F_11 ( V_32 ) ;
return V_44 ;
}
V_43 += V_44 ;
}
return V_43 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_32 = & V_34 -> V_62 . V_32 ;
unsigned int V_10 = 0 ;
int V_63 = 0 ;
while ( 1 ) {
V_63 = F_21 ( V_27 , V_32 ) ;
if ( V_63 == - V_64 )
return V_63 ;
else if ( V_63 < 0 ) {
V_63 = V_65 ;
goto error;
} else if ( V_63 == 0 )
break;
V_10 += V_63 ;
if ( V_32 -> V_50 >= V_32 -> V_51 ) {
if ( V_32 -> V_66 != NULL ) {
V_63 = V_32 -> V_66 ( V_27 , V_32 ) ;
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
static inline int F_26 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_32 = & V_34 -> V_62 . V_32 ;
return V_32 -> V_50 - V_32 -> V_51 ;
}
static int F_27 ( struct V_69 * V_70 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
unsigned int V_71 ;
int V_63 = 0 ;
V_71 = F_28 () ;
while ( F_26 ( V_7 ) ) {
V_63 = F_25 ( V_7 ) ;
if ( V_63 == 0 ) {
V_63 = - V_64 ;
break;
}
if ( V_63 < 0 )
break;
V_63 = 0 ;
}
F_29 ( V_71 ) ;
return V_63 ;
}
static int F_30 ( struct V_26 * V_27 ,
struct V_41 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
V_34 -> V_62 . V_32 = V_34 -> V_62 . V_72 ;
F_2 ( V_27 -> V_6 ,
L_7 ,
V_34 -> V_62 . V_32 . V_49 ,
V_34 -> V_62 . V_32 . V_51 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , void * V_73 ,
T_2 V_74 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_2 ( V_7 , L_8 , V_7 -> V_75 ?
L_9 : L_10 ) ;
memset ( & V_34 -> V_62 . V_72 , 0 ,
sizeof( struct V_41 ) ) ;
if ( V_7 -> V_75 ) {
F_32 ( V_34 -> V_76 , V_73 , V_74 ,
V_73 + V_74 ) ;
V_74 += V_77 ;
}
V_34 -> V_62 . V_73 = V_73 ;
F_33 ( & V_34 -> V_62 . V_32 , V_73 , V_74 ,
F_30 , NULL ) ;
}
static int
F_34 ( struct V_6 * V_7 , struct V_45 * V_46 ,
unsigned int V_30 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_78 * V_76 = NULL ;
unsigned int V_79 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_80 ?
L_9 : L_10 ) ;
V_79 = F_35 ( V_34 -> V_62 . V_73 -> V_81 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_79 ) ) ;
if ( V_7 -> V_80 )
V_76 = V_34 -> V_76 ;
return F_38 ( & V_34 -> V_62 . V_72 ,
V_46 , V_30 , V_4 , V_5 ,
NULL , V_76 ) ;
}
static void
F_39 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_78 * V_76 = NULL ;
unsigned int V_79 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_80 ?
L_9 : L_10 ) ;
V_79 = F_35 ( V_34 -> V_62 . V_73 -> V_81 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_79 ) ) ;
if ( V_7 -> V_80 )
V_76 = V_34 -> V_76 ;
F_33 ( & V_34 -> V_62 . V_72 ,
V_9 , V_5 , NULL , V_76 ) ;
}
static int F_40 ( struct V_69 * V_70 ,
unsigned int V_4 , unsigned int V_30 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
int V_82 = 0 ;
F_31 ( V_7 , V_70 -> V_73 , V_70 -> V_83 ) ;
if ( ! V_30 )
return 0 ;
if ( ! V_70 -> V_84 )
F_39 ( V_7 , V_70 -> V_9 , V_30 ) ;
else {
struct V_85 * V_86 = F_41 ( V_70 -> V_84 ) ;
V_82 = F_34 ( V_7 , V_86 -> V_87 . V_88 ,
V_86 -> V_87 . V_89 , V_4 ,
V_30 ) ;
}
if ( V_82 ) {
return - V_68 ;
}
return 0 ;
}
static int F_42 ( struct V_69 * V_70 , T_3 V_90 )
{
struct V_91 * V_92 = V_70 -> V_29 ;
V_70 -> V_73 = V_70 -> V_29 + sizeof( * V_92 ) ;
V_70 -> V_93 = sizeof( struct V_94 ) - V_77 ;
return 0 ;
}
static struct V_95 *
F_43 ( struct V_96 * V_97 ,
T_4 V_98 )
{
struct V_6 * V_7 ;
struct V_95 * V_99 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_100 * V_101 ;
V_99 = F_44 ( V_97 , sizeof( * V_34 ) ,
V_98 ) ;
if ( ! V_99 )
return NULL ;
V_7 = V_99 -> V_29 ;
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
V_101 = F_45 ( L_13 , 0 , V_102 ) ;
if ( F_46 ( V_101 ) )
goto V_103;
V_34 -> V_76 = F_47 ( V_101 , V_104 ) ;
if ( ! V_34 -> V_76 )
goto V_105;
F_48 ( V_34 -> V_76 , 0 , NULL , NULL ) ;
V_34 -> V_106 = F_47 ( V_101 , V_104 ) ;
if ( ! V_34 -> V_106 )
goto V_107;
F_48 ( V_34 -> V_106 , 0 , NULL , NULL ) ;
V_27 -> V_106 = V_34 -> V_106 ;
return V_99 ;
V_107:
F_49 ( V_34 -> V_76 ) ;
V_105:
F_50 ( V_101 ) ;
V_103:
F_51 ( V_108 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_52 ( V_99 ) ;
return NULL ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_35 * V_20 = V_7 -> V_20 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
F_54 ( V_14 -> V_15 ) ;
F_20 ( V_7 ) ;
F_55 ( V_14 -> V_15 ) ;
F_56 ( & V_20 -> V_109 ) ;
V_34 -> V_14 = NULL ;
F_57 ( & V_20 -> V_109 ) ;
F_58 ( V_14 ) ;
}
static void F_59 ( struct V_95 * V_99 )
{
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_53 ( V_7 ) ;
F_49 ( V_34 -> V_106 ) ;
if ( V_34 -> V_76 ) {
struct V_100 * V_101 ;
V_101 = F_60 ( V_34 -> V_76 ) ;
F_49 ( V_34 -> V_76 ) ;
F_50 ( V_101 ) ;
}
F_52 ( V_99 ) ;
}
static void F_61 ( struct V_95 * V_99 , int V_110 )
{
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_111 = V_68 ;
F_62 ( F_63 ( V_14 -> V_15 ) ) ;
F_64 ( V_7 ) ;
F_53 ( V_7 ) ;
F_65 ( V_99 , V_110 ) ;
}
static int
F_66 ( struct V_96 * V_97 ,
struct V_95 * V_99 , T_5 V_112 ,
int V_113 )
{
struct V_35 * V_20 = V_97 -> V_29 ;
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 ;
struct V_42 * V_14 ;
int V_82 ;
V_14 = F_67 ( ( int ) V_112 , & V_82 ) ;
if ( ! V_14 ) {
F_51 ( V_108 , V_7 ,
L_18 , V_82 ) ;
return - V_114 ;
}
V_82 = F_68 ( V_97 , V_99 , V_113 ) ;
if ( V_82 )
goto V_115;
F_56 ( & V_20 -> V_109 ) ;
V_34 -> V_14 = V_14 ;
F_57 ( & V_20 -> V_109 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_116 = V_117 ;
V_15 -> V_118 = 15 * V_119 ;
V_15 -> V_120 = V_121 ;
F_69 ( V_15 ) ;
F_17 ( V_7 ) ;
V_34 -> V_54 = V_34 -> V_14 -> V_122 -> V_54 ;
F_70 ( V_27 ) ;
return 0 ;
V_115:
F_58 ( V_14 ) ;
return V_82 ;
}
static int F_71 ( struct V_95 * V_99 ,
enum V_123 V_124 , char * V_125 ,
int V_126 )
{
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
switch( V_124 ) {
case V_127 :
F_72 ( V_99 , V_124 , V_125 , V_126 ) ;
break;
case V_128 :
F_72 ( V_99 , V_124 , V_125 , V_126 ) ;
V_34 -> V_54 = V_7 -> V_80 ?
V_129 : V_34 -> V_14 -> V_122 -> V_54 ;
break;
case V_130 :
return F_73 ( V_7 , V_125 ) ;
default:
return F_72 ( V_99 , V_124 , V_125 , V_126 ) ;
}
return 0 ;
}
static int F_74 ( struct V_95 * V_99 ,
enum V_123 V_124 , char * V_125 )
{
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_131 V_132 ;
int V_63 , V_5 ;
switch( V_124 ) {
case V_133 :
case V_134 :
case V_135 :
F_56 ( & V_7 -> V_20 -> V_109 ) ;
if ( ! V_34 || ! V_34 -> V_14 ) {
F_57 ( & V_7 -> V_20 -> V_109 ) ;
return - V_136 ;
}
if ( V_124 == V_135 )
V_63 = F_75 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
else
V_63 = F_76 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
F_57 ( & V_7 -> V_20 -> V_109 ) ;
if ( V_63 )
return V_63 ;
return F_77 ( (struct V_138 * )
& V_132 , V_124 , V_125 ) ;
default:
return F_78 ( V_99 , V_124 , V_125 ) ;
}
return 0 ;
}
static int F_79 ( struct V_139 * V_140 ,
enum V_141 V_124 , char * V_125 )
{
struct V_142 * V_143 = F_80 ( V_140 ) ;
struct V_35 * V_20 = V_143 -> V_20 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_131 V_132 ;
int V_63 , V_5 ;
switch ( V_124 ) {
case V_144 :
if ( ! V_20 )
return - V_136 ;
F_56 ( & V_20 -> V_109 ) ;
V_7 = V_20 -> V_145 ;
if ( ! V_7 ) {
F_57 ( & V_20 -> V_109 ) ;
return - V_136 ;
}
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
if ( ! V_34 -> V_14 ) {
F_57 ( & V_20 -> V_109 ) ;
return - V_136 ;
}
V_63 = F_75 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
F_57 ( & V_20 -> V_109 ) ;
if ( V_63 )
return V_63 ;
return F_77 ( (struct V_138 * )
& V_132 , V_124 , V_125 ) ;
default:
return F_81 ( V_140 , V_124 , V_125 ) ;
}
return 0 ;
}
static void
F_82 ( struct V_95 * V_99 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_99 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
V_147 -> V_148 = 3 ;
strcpy ( V_147 -> V_149 [ 0 ] . V_150 , L_19 ) ;
V_147 -> V_149 [ 0 ] . V_151 = V_34 -> V_152 ;
strcpy ( V_147 -> V_149 [ 1 ] . V_150 , L_20 ) ;
V_147 -> V_149 [ 1 ] . V_151 = V_34 -> V_153 ;
strcpy ( V_147 -> V_149 [ 2 ] . V_150 , L_21 ) ;
V_147 -> V_149 [ 2 ] . V_151 = V_7 -> V_154 ;
F_83 ( V_99 , V_147 ) ;
}
static struct V_96 *
F_84 ( struct V_155 * V_156 , T_6 V_157 ,
T_6 V_158 , T_4 V_159 )
{
struct V_96 * V_97 ;
struct V_35 * V_20 ;
struct V_142 * V_143 ;
struct V_139 * V_140 ;
if ( V_156 ) {
F_85 ( V_108 L_22 , V_156 ) ;
return NULL ;
}
V_140 = F_86 ( & V_160 ,
sizeof( struct V_142 ) , 1 ) ;
if ( ! V_140 )
return NULL ;
V_140 -> V_161 = V_162 ;
V_140 -> V_163 = V_158 ;
V_140 -> V_164 = V_165 ;
V_140 -> V_166 = 0 ;
V_140 -> V_167 = 0 ;
V_140 -> V_168 = V_169 ;
if ( F_87 ( V_140 , NULL ) )
goto V_170;
V_97 = F_88 ( & V_171 , V_140 ,
V_157 , 0 ,
sizeof( struct V_91 ) +
sizeof( struct V_94 ) ,
V_159 , 0 ) ;
if ( ! V_97 )
goto V_172;
V_20 = V_97 -> V_29 ;
V_143 = F_80 ( V_140 ) ;
V_143 -> V_20 = V_20 ;
V_140 -> V_173 = V_20 -> V_174 ;
if ( F_89 ( V_20 ) )
goto V_175;
return V_97 ;
V_175:
F_90 ( V_97 ) ;
V_172:
F_91 ( V_140 ) ;
V_170:
F_92 ( V_140 ) ;
return NULL ;
}
static void F_93 ( struct V_96 * V_97 )
{
struct V_139 * V_140 = F_94 ( V_97 ) ;
F_95 ( V_97 -> V_29 ) ;
F_90 ( V_97 ) ;
F_91 ( V_140 ) ;
F_92 ( V_140 ) ;
}
static T_7 F_96 ( int V_176 , int V_124 )
{
switch ( V_176 ) {
case V_177 :
switch ( V_124 ) {
case V_178 :
case V_179 :
case V_144 :
case V_180 :
return V_181 ;
default:
return 0 ;
}
case V_182 :
switch ( V_124 ) {
case V_183 :
case V_184 :
case V_127 :
case V_128 :
case V_134 :
case V_133 :
case V_135 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_130 :
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
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
return V_181 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_97 ( struct V_209 * V_210 )
{
F_98 ( V_211 , & V_210 -> V_212 -> V_213 ) ;
return 0 ;
}
static int F_99 ( struct V_209 * V_210 )
{
F_100 ( V_210 -> V_212 , V_214 ) ;
F_101 ( V_210 -> V_212 , 0 ) ;
return 0 ;
}
static int T_8 F_102 ( void )
{
if ( V_165 < 1 ) {
F_85 ( V_108 L_23 ,
V_165 ) ;
return - V_215 ;
}
V_162 = F_103 (
& V_171 ) ;
if ( ! V_162 )
return - V_216 ;
return 0 ;
}
static void T_9 F_104 ( void )
{
F_105 ( & V_171 ) ;
}
