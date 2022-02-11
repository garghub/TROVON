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
unsigned long V_71 = V_72 -> V_48 ;
int V_63 = 0 ;
V_72 -> V_48 |= V_73 ;
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
F_28 ( V_72 , V_71 , V_73 ) ;
return V_63 ;
}
static int F_29 ( struct V_26 * V_27 ,
struct V_41 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
V_34 -> V_62 . V_32 = V_34 -> V_62 . V_74 ;
F_2 ( V_27 -> V_6 ,
L_7 ,
V_34 -> V_62 . V_32 . V_49 ,
V_34 -> V_62 . V_32 . V_51 ) ;
return 0 ;
}
static void F_30 ( struct V_6 * V_7 , void * V_75 ,
T_2 V_76 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_2 ( V_7 , L_8 , V_7 -> V_77 ?
L_9 : L_10 ) ;
memset ( & V_34 -> V_62 . V_74 , 0 ,
sizeof( struct V_41 ) ) ;
if ( V_7 -> V_77 ) {
F_31 ( V_34 -> V_78 , V_75 , V_76 ,
V_75 + V_76 ) ;
V_76 += V_79 ;
}
V_34 -> V_62 . V_75 = V_75 ;
F_32 ( & V_34 -> V_62 . V_32 , V_75 , V_76 ,
F_29 , NULL ) ;
}
static int
F_33 ( struct V_6 * V_7 , struct V_45 * V_46 ,
unsigned int V_30 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_80 * V_78 = NULL ;
unsigned int V_81 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_82 ?
L_9 : L_10 ) ;
V_81 = F_34 ( V_34 -> V_62 . V_75 -> V_83 ) ;
F_35 ( F_36 ( V_5 ) != F_36 ( V_81 ) ) ;
if ( V_7 -> V_82 )
V_78 = V_34 -> V_78 ;
return F_37 ( & V_34 -> V_62 . V_74 ,
V_46 , V_30 , V_4 , V_5 ,
NULL , V_78 ) ;
}
static void
F_38 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_80 * V_78 = NULL ;
unsigned int V_81 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_82 ?
L_9 : L_10 ) ;
V_81 = F_34 ( V_34 -> V_62 . V_75 -> V_83 ) ;
F_35 ( F_36 ( V_5 ) != F_36 ( V_81 ) ) ;
if ( V_7 -> V_82 )
V_78 = V_34 -> V_78 ;
F_32 ( & V_34 -> V_62 . V_74 ,
V_9 , V_5 , NULL , V_78 ) ;
}
static int F_39 ( struct V_69 * V_70 ,
unsigned int V_4 , unsigned int V_30 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
int V_84 = 0 ;
F_30 ( V_7 , V_70 -> V_75 , V_70 -> V_85 ) ;
if ( ! V_30 )
return 0 ;
if ( ! V_70 -> V_86 )
F_38 ( V_7 , V_70 -> V_9 , V_30 ) ;
else {
struct V_87 * V_88 = F_40 ( V_70 -> V_86 ) ;
V_84 = F_33 ( V_7 , V_88 -> V_89 . V_90 ,
V_88 -> V_89 . V_91 , V_4 ,
V_30 ) ;
}
if ( V_84 ) {
return - V_68 ;
}
return 0 ;
}
static int F_41 ( struct V_69 * V_70 , T_3 V_92 )
{
struct V_93 * V_94 = V_70 -> V_29 ;
V_70 -> V_75 = V_70 -> V_29 + sizeof( * V_94 ) ;
V_70 -> V_95 = sizeof( struct V_96 ) - V_79 ;
return 0 ;
}
static struct V_97 *
F_42 ( struct V_98 * V_99 ,
T_4 V_100 )
{
struct V_6 * V_7 ;
struct V_97 * V_101 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_102 * V_103 ;
V_101 = F_43 ( V_99 , sizeof( * V_34 ) ,
V_100 ) ;
if ( ! V_101 )
return NULL ;
V_7 = V_101 -> V_29 ;
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
V_103 = F_44 ( L_13 , 0 , V_104 ) ;
if ( F_45 ( V_103 ) )
goto V_105;
V_34 -> V_78 = F_46 ( V_103 , V_106 ) ;
if ( ! V_34 -> V_78 )
goto V_107;
F_47 ( V_34 -> V_78 , 0 , NULL , NULL ) ;
V_34 -> V_108 = F_46 ( V_103 , V_106 ) ;
if ( ! V_34 -> V_108 )
goto V_109;
F_47 ( V_34 -> V_108 , 0 , NULL , NULL ) ;
V_27 -> V_108 = V_34 -> V_108 ;
return V_101 ;
V_109:
F_48 ( V_34 -> V_78 ) ;
V_107:
F_49 ( V_103 ) ;
V_105:
F_50 ( V_110 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_51 ( V_101 ) ;
return NULL ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_35 * V_20 = V_7 -> V_20 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
F_53 ( V_14 -> V_15 ) ;
F_20 ( V_7 ) ;
F_54 ( V_14 -> V_15 ) ;
F_55 ( & V_20 -> V_111 ) ;
V_34 -> V_14 = NULL ;
F_56 ( & V_20 -> V_111 ) ;
F_57 ( V_14 ) ;
}
static void F_58 ( struct V_97 * V_101 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_52 ( V_7 ) ;
F_48 ( V_34 -> V_108 ) ;
if ( V_34 -> V_78 ) {
struct V_102 * V_103 ;
V_103 = F_59 ( V_34 -> V_78 ) ;
F_48 ( V_34 -> V_78 ) ;
F_49 ( V_103 ) ;
}
F_51 ( V_101 ) ;
}
static void F_60 ( struct V_97 * V_101 , int V_112 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_113 = V_68 ;
F_61 ( F_62 ( V_14 -> V_15 ) ) ;
F_63 ( V_7 ) ;
F_52 ( V_7 ) ;
F_64 ( V_101 , V_112 ) ;
}
static int
F_65 ( struct V_98 * V_99 ,
struct V_97 * V_101 , T_5 V_114 ,
int V_115 )
{
struct V_35 * V_20 = V_99 -> V_29 ;
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 ;
struct V_42 * V_14 ;
int V_84 ;
V_14 = F_66 ( ( int ) V_114 , & V_84 ) ;
if ( ! V_14 ) {
F_50 ( V_110 , V_7 ,
L_18 , V_84 ) ;
return - V_116 ;
}
V_84 = F_67 ( V_99 , V_101 , V_115 ) ;
if ( V_84 )
goto V_117;
F_55 ( & V_20 -> V_111 ) ;
V_34 -> V_14 = V_14 ;
F_56 ( & V_20 -> V_111 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_118 = V_119 ;
V_15 -> V_120 = 15 * V_121 ;
V_15 -> V_122 = V_123 ;
F_68 ( V_15 ) ;
F_17 ( V_7 ) ;
V_34 -> V_54 = V_34 -> V_14 -> V_124 -> V_54 ;
F_69 ( V_27 ) ;
return 0 ;
V_117:
F_57 ( V_14 ) ;
return V_84 ;
}
static int F_70 ( struct V_97 * V_101 ,
enum V_125 V_126 , char * V_127 ,
int V_128 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
switch( V_126 ) {
case V_129 :
F_71 ( V_101 , V_126 , V_127 , V_128 ) ;
break;
case V_130 :
F_71 ( V_101 , V_126 , V_127 , V_128 ) ;
V_34 -> V_54 = V_7 -> V_82 ?
V_131 : V_34 -> V_14 -> V_124 -> V_54 ;
break;
case V_132 :
return F_72 ( V_7 , V_127 ) ;
default:
return F_71 ( V_101 , V_126 , V_127 , V_128 ) ;
}
return 0 ;
}
static int F_73 ( struct V_97 * V_101 ,
enum V_125 V_126 , char * V_127 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_133 V_134 ;
int V_63 , V_5 ;
switch( V_126 ) {
case V_135 :
case V_136 :
case V_137 :
F_55 ( & V_7 -> V_20 -> V_111 ) ;
if ( ! V_34 || ! V_34 -> V_14 ) {
F_56 ( & V_7 -> V_20 -> V_111 ) ;
return - V_138 ;
}
if ( V_126 == V_137 )
V_63 = F_74 ( V_34 -> V_14 ,
(struct V_139 * ) & V_134 , & V_5 ) ;
else
V_63 = F_75 ( V_34 -> V_14 ,
(struct V_139 * ) & V_134 , & V_5 ) ;
F_56 ( & V_7 -> V_20 -> V_111 ) ;
if ( V_63 )
return V_63 ;
return F_76 ( (struct V_140 * )
& V_134 , V_126 , V_127 ) ;
default:
return F_77 ( V_101 , V_126 , V_127 ) ;
}
return 0 ;
}
static int F_78 ( struct V_141 * V_142 ,
enum V_143 V_126 , char * V_127 )
{
struct V_144 * V_145 = F_79 ( V_142 ) ;
struct V_35 * V_20 = V_145 -> V_20 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_133 V_134 ;
int V_63 , V_5 ;
switch ( V_126 ) {
case V_146 :
if ( ! V_20 )
return - V_138 ;
F_55 ( & V_20 -> V_111 ) ;
V_7 = V_20 -> V_147 ;
if ( ! V_7 ) {
F_56 ( & V_20 -> V_111 ) ;
return - V_138 ;
}
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
if ( ! V_34 -> V_14 ) {
F_56 ( & V_20 -> V_111 ) ;
return - V_138 ;
}
V_63 = F_74 ( V_34 -> V_14 ,
(struct V_139 * ) & V_134 , & V_5 ) ;
F_56 ( & V_20 -> V_111 ) ;
if ( V_63 )
return V_63 ;
return F_76 ( (struct V_140 * )
& V_134 , V_126 , V_127 ) ;
default:
return F_80 ( V_142 , V_126 , V_127 ) ;
}
return 0 ;
}
static void
F_81 ( struct V_97 * V_101 ,
struct V_148 * V_149 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
V_149 -> V_150 = 3 ;
strcpy ( V_149 -> V_151 [ 0 ] . V_152 , L_19 ) ;
V_149 -> V_151 [ 0 ] . V_153 = V_34 -> V_154 ;
strcpy ( V_149 -> V_151 [ 1 ] . V_152 , L_20 ) ;
V_149 -> V_151 [ 1 ] . V_153 = V_34 -> V_155 ;
strcpy ( V_149 -> V_151 [ 2 ] . V_152 , L_21 ) ;
V_149 -> V_151 [ 2 ] . V_153 = V_7 -> V_156 ;
F_82 ( V_101 , V_149 ) ;
}
static struct V_98 *
F_83 ( struct V_157 * V_158 , T_6 V_159 ,
T_6 V_160 , T_4 V_161 )
{
struct V_98 * V_99 ;
struct V_35 * V_20 ;
struct V_144 * V_145 ;
struct V_141 * V_142 ;
if ( V_158 ) {
F_84 ( V_110 L_22 , V_158 ) ;
return NULL ;
}
V_142 = F_85 ( & V_162 ,
sizeof( struct V_144 ) , 1 ) ;
if ( ! V_142 )
return NULL ;
V_142 -> V_163 = V_164 ;
V_142 -> V_165 = V_160 ;
V_142 -> V_166 = V_167 ;
V_142 -> V_168 = 0 ;
V_142 -> V_169 = 0 ;
V_142 -> V_170 = V_171 ;
if ( F_86 ( V_142 , NULL ) )
goto V_172;
V_99 = F_87 ( & V_173 , V_142 ,
V_159 , 0 ,
sizeof( struct V_93 ) +
sizeof( struct V_96 ) ,
V_161 , 0 ) ;
if ( ! V_99 )
goto V_174;
V_20 = V_99 -> V_29 ;
V_145 = F_79 ( V_142 ) ;
V_145 -> V_20 = V_20 ;
V_142 -> V_175 = V_20 -> V_176 ;
if ( F_88 ( V_20 ) )
goto V_177;
return V_99 ;
V_177:
F_89 ( V_99 ) ;
V_174:
F_90 ( V_142 ) ;
V_172:
F_91 ( V_142 ) ;
return NULL ;
}
static void F_92 ( struct V_98 * V_99 )
{
struct V_141 * V_142 = F_93 ( V_99 ) ;
F_94 ( V_99 -> V_29 ) ;
F_89 ( V_99 ) ;
F_90 ( V_142 ) ;
F_91 ( V_142 ) ;
}
static T_7 F_95 ( int V_178 , int V_126 )
{
switch ( V_178 ) {
case V_179 :
switch ( V_126 ) {
case V_180 :
case V_181 :
case V_146 :
case V_182 :
return V_183 ;
default:
return 0 ;
}
case V_184 :
switch ( V_126 ) {
case V_185 :
case V_186 :
case V_129 :
case V_130 :
case V_136 :
case V_135 :
case V_137 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_132 :
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
case V_209 :
case V_210 :
return V_183 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_96 ( struct V_211 * V_212 )
{
F_97 ( V_213 , & V_212 -> V_214 -> V_215 ) ;
return 0 ;
}
static int F_98 ( struct V_211 * V_212 )
{
F_99 ( V_212 -> V_214 , V_216 ) ;
F_100 ( V_212 -> V_214 , 0 ) ;
return 0 ;
}
static int T_8 F_101 ( void )
{
if ( V_167 < 1 ) {
F_84 ( V_110 L_23 ,
V_167 ) ;
return - V_217 ;
}
V_164 = F_102 (
& V_173 ) ;
if ( ! V_164 )
return - V_218 ;
return 0 ;
}
static void T_9 F_103 ( void )
{
F_104 ( & V_173 ) ;
}
