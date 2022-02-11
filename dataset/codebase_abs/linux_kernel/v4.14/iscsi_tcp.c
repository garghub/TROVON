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
void (* F_13)( struct V_14 * );
F_8 ( & V_15 -> V_28 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_28 ) ;
return;
}
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
V_34 -> V_35 = V_15 -> V_36 ;
V_34 -> F_13 = V_15 -> V_37 ;
V_34 -> F_15 = V_15 -> V_38 ;
V_15 -> V_36 = F_7 ;
V_15 -> V_37 = F_12 ;
V_15 -> V_38 = F_14 ;
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
V_15 -> V_36 = V_34 -> V_35 ;
V_15 -> V_37 = V_34 -> F_13 ;
V_15 -> V_38 = V_34 -> F_15 ;
V_15 -> V_39 = 0 ;
F_19 ( & V_15 -> V_28 ) ;
}
static int F_21 ( struct V_26 * V_27 ,
struct V_40 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_15 = V_34 -> V_14 ;
unsigned int V_42 = 0 ;
int V_43 = 0 ;
while ( ! F_22 ( V_27 , V_32 , 0 , V_43 ) ) {
struct V_44 * V_45 ;
unsigned int V_4 , V_46 ;
int V_47 = 0 ;
V_43 = 0 ;
V_4 = V_32 -> V_42 ;
V_46 = V_32 -> V_48 - V_4 ;
if ( V_32 -> V_49 + V_32 -> V_48 < V_32 -> V_50 )
V_47 |= V_51 ;
if ( ! V_32 -> V_9 ) {
V_45 = V_32 -> V_45 ;
V_4 += V_32 -> V_52 + V_45 -> V_4 ;
V_43 = V_34 -> V_53 ( V_15 , F_23 ( V_45 ) , V_4 ,
V_46 , V_47 ) ;
} else {
struct V_54 V_55 = { . V_56 = V_47 } ;
struct V_57 V_58 = {
. V_59 = V_32 -> V_9 + V_4 ,
. V_60 = V_46
} ;
V_43 = F_24 ( V_15 , & V_55 , & V_58 , 1 , V_46 ) ;
}
if ( V_43 < 0 ) {
F_11 ( V_32 ) ;
return V_43 ;
}
V_42 += V_43 ;
}
return V_42 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_40 * V_32 = & V_34 -> V_61 . V_32 ;
unsigned int V_10 = 0 ;
int V_62 = 0 ;
while ( 1 ) {
V_62 = F_21 ( V_27 , V_32 ) ;
if ( V_62 == - V_63 )
return V_62 ;
else if ( V_62 < 0 ) {
V_62 = V_64 ;
goto error;
} else if ( V_62 == 0 )
break;
V_10 += V_62 ;
if ( V_32 -> V_49 >= V_32 -> V_50 ) {
if ( V_32 -> V_65 != NULL ) {
V_62 = V_32 -> V_65 ( V_27 , V_32 ) ;
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
static inline int F_26 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_40 * V_32 = & V_34 -> V_61 . V_32 ;
return V_32 -> V_49 - V_32 -> V_50 ;
}
static int F_27 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
unsigned int V_70 ;
int V_62 = 0 ;
V_70 = F_28 () ;
while ( F_26 ( V_7 ) ) {
V_62 = F_25 ( V_7 ) ;
if ( V_62 == 0 ) {
V_62 = - V_63 ;
break;
}
if ( V_62 < 0 )
break;
V_62 = 0 ;
}
F_29 ( V_70 ) ;
return V_62 ;
}
static int F_30 ( struct V_26 * V_27 ,
struct V_40 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
V_34 -> V_61 . V_32 = V_34 -> V_61 . V_71 ;
F_2 ( V_27 -> V_6 ,
L_7 ,
V_34 -> V_61 . V_32 . V_48 ,
V_34 -> V_61 . V_32 . V_50 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , void * V_72 ,
T_2 V_73 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_2 ( V_7 , L_8 , V_7 -> V_74 ?
L_9 : L_10 ) ;
memset ( & V_34 -> V_61 . V_71 , 0 ,
sizeof( struct V_40 ) ) ;
if ( V_7 -> V_74 ) {
F_32 ( V_34 -> V_75 , V_72 , V_73 ,
V_72 + V_73 ) ;
V_73 += V_76 ;
}
V_34 -> V_61 . V_72 = V_72 ;
F_33 ( & V_34 -> V_61 . V_32 , V_72 , V_73 ,
F_30 , NULL ) ;
}
static int
F_34 ( struct V_6 * V_7 , struct V_44 * V_45 ,
unsigned int V_30 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_77 * V_75 = NULL ;
unsigned int V_78 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_79 ?
L_9 : L_10 ) ;
V_78 = F_35 ( V_34 -> V_61 . V_72 -> V_80 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_78 ) ) ;
if ( V_7 -> V_79 )
V_75 = V_34 -> V_75 ;
return F_38 ( & V_34 -> V_61 . V_71 ,
V_45 , V_30 , V_4 , V_5 ,
NULL , V_75 ) ;
}
static void
F_39 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_77 * V_75 = NULL ;
unsigned int V_78 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_79 ?
L_9 : L_10 ) ;
V_78 = F_35 ( V_34 -> V_61 . V_72 -> V_80 ) ;
F_36 ( F_37 ( V_5 ) != F_37 ( V_78 ) ) ;
if ( V_7 -> V_79 )
V_75 = V_34 -> V_75 ;
F_33 ( & V_34 -> V_61 . V_71 ,
V_9 , V_5 , NULL , V_75 ) ;
}
static int F_40 ( struct V_68 * V_69 ,
unsigned int V_4 , unsigned int V_30 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
int V_81 = 0 ;
F_31 ( V_7 , V_69 -> V_72 , V_69 -> V_82 ) ;
if ( ! V_30 )
return 0 ;
if ( ! V_69 -> V_83 )
F_39 ( V_7 , V_69 -> V_9 , V_30 ) ;
else {
struct V_84 * V_85 = F_41 ( V_69 -> V_83 ) ;
V_81 = F_34 ( V_7 , V_85 -> V_86 . V_87 ,
V_85 -> V_86 . V_88 , V_4 ,
V_30 ) ;
}
if ( V_81 ) {
return - V_67 ;
}
return 0 ;
}
static int F_42 ( struct V_68 * V_69 , T_3 V_89 )
{
struct V_90 * V_91 = V_69 -> V_29 ;
V_69 -> V_72 = V_69 -> V_29 + sizeof( * V_91 ) ;
V_69 -> V_92 = sizeof( struct V_93 ) - V_76 ;
return 0 ;
}
static struct V_94 *
F_43 ( struct V_95 * V_96 ,
T_4 V_97 )
{
struct V_6 * V_7 ;
struct V_94 * V_98 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_99 * V_100 ;
V_98 = F_44 ( V_96 , sizeof( * V_34 ) ,
V_97 ) ;
if ( ! V_98 )
return NULL ;
V_7 = V_98 -> V_29 ;
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
V_100 = F_45 ( L_13 , 0 , V_101 ) ;
if ( F_46 ( V_100 ) )
goto V_102;
V_34 -> V_75 = F_47 ( V_100 , V_103 ) ;
if ( ! V_34 -> V_75 )
goto V_104;
F_48 ( V_34 -> V_75 , 0 , NULL , NULL ) ;
V_34 -> V_105 = F_47 ( V_100 , V_103 ) ;
if ( ! V_34 -> V_105 )
goto V_106;
F_48 ( V_34 -> V_105 , 0 , NULL , NULL ) ;
V_27 -> V_105 = V_34 -> V_105 ;
return V_98 ;
V_106:
F_49 ( V_34 -> V_75 ) ;
V_104:
F_50 ( V_100 ) ;
V_102:
F_51 ( V_107 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_52 ( V_98 ) ;
return NULL ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_108 * V_20 = V_7 -> V_20 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_14 = V_34 -> V_14 ;
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
static void F_59 ( struct V_94 * V_98 )
{
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_53 ( V_7 ) ;
F_49 ( V_34 -> V_105 ) ;
if ( V_34 -> V_75 ) {
struct V_99 * V_100 ;
V_100 = F_60 ( V_34 -> V_75 ) ;
F_49 ( V_34 -> V_75 ) ;
F_50 ( V_100 ) ;
}
F_52 ( V_98 ) ;
}
static void F_61 ( struct V_94 * V_98 , int V_110 )
{
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_111 = V_67 ;
F_62 ( F_63 ( V_14 -> V_15 ) ) ;
F_64 ( V_7 ) ;
F_53 ( V_7 ) ;
F_65 ( V_98 , V_110 ) ;
}
static int
F_66 ( struct V_95 * V_96 ,
struct V_94 * V_98 , T_5 V_112 ,
int V_113 )
{
struct V_108 * V_20 = V_96 -> V_29 ;
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 ;
struct V_41 * V_14 ;
int V_81 ;
V_14 = F_67 ( ( int ) V_112 , & V_81 ) ;
if ( ! V_14 ) {
F_51 ( V_107 , V_7 ,
L_18 , V_81 ) ;
return - V_114 ;
}
V_81 = F_68 ( V_96 , V_98 , V_113 ) ;
if ( V_81 )
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
V_34 -> V_53 = V_34 -> V_14 -> V_122 -> V_53 ;
F_70 ( V_27 ) ;
return 0 ;
V_115:
F_58 ( V_14 ) ;
return V_81 ;
}
static int F_71 ( struct V_94 * V_98 ,
enum V_123 V_124 , char * V_125 ,
int V_126 )
{
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
switch( V_124 ) {
case V_127 :
F_72 ( V_98 , V_124 , V_125 , V_126 ) ;
break;
case V_128 :
F_72 ( V_98 , V_124 , V_125 , V_126 ) ;
V_34 -> V_53 = V_7 -> V_79 ?
V_129 : V_34 -> V_14 -> V_122 -> V_53 ;
break;
case V_130 :
return F_73 ( V_7 , V_125 ) ;
default:
return F_72 ( V_98 , V_124 , V_125 , V_126 ) ;
}
return 0 ;
}
static int F_74 ( struct V_94 * V_98 ,
enum V_123 V_124 , char * V_125 )
{
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_131 V_132 ;
int V_62 , V_5 ;
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
V_62 = F_75 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
else
V_62 = F_76 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
F_57 ( & V_7 -> V_20 -> V_109 ) ;
if ( V_62 )
return V_62 ;
return F_77 ( (struct V_138 * )
& V_132 , V_124 , V_125 ) ;
default:
return F_78 ( V_98 , V_124 , V_125 ) ;
}
return 0 ;
}
static int F_79 ( struct V_139 * V_140 ,
enum V_141 V_124 , char * V_125 )
{
struct V_142 * V_143 = F_80 ( V_140 ) ;
struct V_108 * V_20 = V_143 -> V_20 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_131 V_132 ;
int V_62 , V_5 ;
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
V_62 = F_75 ( V_34 -> V_14 ,
(struct V_137 * ) & V_132 , & V_5 ) ;
F_57 ( & V_20 -> V_109 ) ;
if ( V_62 )
return V_62 ;
return F_77 ( (struct V_138 * )
& V_132 , V_124 , V_125 ) ;
default:
return F_81 ( V_140 , V_124 , V_125 ) ;
}
return 0 ;
}
static void
F_82 ( struct V_94 * V_98 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_98 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
V_147 -> V_148 = 3 ;
strcpy ( V_147 -> V_149 [ 0 ] . V_150 , L_19 ) ;
V_147 -> V_149 [ 0 ] . V_151 = V_34 -> V_152 ;
strcpy ( V_147 -> V_149 [ 1 ] . V_150 , L_20 ) ;
V_147 -> V_149 [ 1 ] . V_151 = V_34 -> V_153 ;
strcpy ( V_147 -> V_149 [ 2 ] . V_150 , L_21 ) ;
V_147 -> V_149 [ 2 ] . V_151 = V_7 -> V_154 ;
F_83 ( V_98 , V_147 ) ;
}
static struct V_95 *
F_84 ( struct V_155 * V_156 , T_6 V_157 ,
T_6 V_158 , T_4 V_159 )
{
struct V_95 * V_96 ;
struct V_108 * V_20 ;
struct V_142 * V_143 ;
struct V_139 * V_140 ;
if ( V_156 ) {
F_85 ( V_107 L_22 , V_156 ) ;
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
V_96 = F_88 ( & V_171 , V_140 ,
V_157 , 0 ,
sizeof( struct V_90 ) +
sizeof( struct V_93 ) ,
V_159 , 0 ) ;
if ( ! V_96 )
goto V_172;
V_20 = V_96 -> V_29 ;
V_143 = F_80 ( V_140 ) ;
V_143 -> V_20 = V_20 ;
V_140 -> V_173 = V_20 -> V_174 ;
if ( F_89 ( V_20 ) )
goto V_175;
return V_96 ;
V_175:
F_90 ( V_96 ) ;
V_172:
F_91 ( V_140 ) ;
V_170:
F_92 ( V_140 ) ;
return NULL ;
}
static void F_93 ( struct V_95 * V_96 )
{
struct V_139 * V_140 = F_94 ( V_96 ) ;
F_95 ( V_96 -> V_29 ) ;
F_90 ( V_96 ) ;
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
F_85 ( V_107 L_23 ,
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
