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
F_16 ( & V_15 -> V_28 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_17 ( & V_15 -> V_28 ) ;
return;
}
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
F_15 = V_34 -> F_15 ;
F_17 ( & V_15 -> V_28 ) ;
F_15 ( V_15 ) ;
F_2 ( V_7 , L_4 ) ;
F_18 ( V_7 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 = V_34 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_28 ) ;
V_15 -> V_16 = V_7 ;
V_34 -> V_36 = V_15 -> V_37 ;
V_34 -> F_13 = V_15 -> V_38 ;
V_34 -> F_15 = V_15 -> V_39 ;
V_15 -> V_37 = F_7 ;
V_15 -> V_38 = F_12 ;
V_15 -> V_39 = F_14 ;
F_21 ( & V_15 -> V_28 ) ;
}
static void
F_22 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 = V_34 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_28 ) ;
V_15 -> V_16 = NULL ;
V_15 -> V_37 = V_34 -> V_36 ;
V_15 -> V_38 = V_34 -> F_13 ;
V_15 -> V_39 = V_34 -> F_15 ;
V_15 -> V_40 = 0 ;
F_21 ( & V_15 -> V_28 ) ;
}
static int F_23 ( struct V_26 * V_27 ,
struct V_41 * V_32 )
{
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_15 = V_34 -> V_14 ;
unsigned int V_43 = 0 ;
int V_44 = 0 ;
while ( ! F_24 ( V_27 , V_32 , 0 , V_44 ) ) {
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
V_44 = V_34 -> V_54 ( V_15 , F_25 ( V_46 ) , V_4 ,
V_47 , V_48 ) ;
} else {
struct V_55 V_56 = { . V_57 = V_48 } ;
struct V_58 V_59 = {
. V_60 = V_32 -> V_9 + V_4 ,
. V_61 = V_47
} ;
V_44 = F_26 ( V_15 , & V_56 , & V_59 , 1 , V_47 ) ;
}
if ( V_44 < 0 ) {
F_11 ( V_32 ) ;
return V_44 ;
}
V_43 += V_44 ;
}
return V_43 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_32 = & V_34 -> V_62 . V_32 ;
unsigned int V_10 = 0 ;
int V_63 = 0 ;
while ( 1 ) {
V_63 = F_23 ( V_27 , V_32 ) ;
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
static inline int F_28 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_41 * V_32 = & V_34 -> V_62 . V_32 ;
return V_32 -> V_50 - V_32 -> V_51 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
unsigned long V_71 = V_72 -> V_48 ;
int V_63 = 0 ;
V_72 -> V_48 |= V_73 ;
while ( F_28 ( V_7 ) ) {
V_63 = F_27 ( V_7 ) ;
if ( V_63 == 0 ) {
V_63 = - V_64 ;
break;
}
if ( V_63 < 0 )
break;
V_63 = 0 ;
}
F_30 ( V_72 , V_71 , V_73 ) ;
return V_63 ;
}
static int F_31 ( struct V_26 * V_27 ,
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
static void F_32 ( struct V_6 * V_7 , void * V_75 ,
T_2 V_76 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_2 ( V_7 , L_8 , V_7 -> V_77 ?
L_9 : L_10 ) ;
memset ( & V_34 -> V_62 . V_74 , 0 ,
sizeof( struct V_41 ) ) ;
if ( V_7 -> V_77 ) {
F_33 ( & V_34 -> V_78 , V_75 , V_76 ,
V_75 + V_76 ) ;
V_76 += V_79 ;
}
V_34 -> V_62 . V_75 = V_75 ;
F_34 ( & V_34 -> V_62 . V_32 , V_75 , V_76 ,
F_31 , NULL ) ;
}
static int
F_35 ( struct V_6 * V_7 , struct V_45 * V_46 ,
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
V_81 = F_36 ( V_34 -> V_62 . V_75 -> V_83 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_81 ) ) ;
if ( V_7 -> V_82 )
V_78 = & V_34 -> V_78 ;
return F_39 ( & V_34 -> V_62 . V_74 ,
V_46 , V_30 , V_4 , V_5 ,
NULL , V_78 ) ;
}
static void
F_40 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_80 * V_78 = NULL ;
unsigned int V_81 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_82 ?
L_9 : L_10 ) ;
V_81 = F_36 ( V_34 -> V_62 . V_75 -> V_83 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_81 ) ) ;
if ( V_7 -> V_82 )
V_78 = & V_34 -> V_78 ;
F_34 ( & V_34 -> V_62 . V_74 ,
V_9 , V_5 , NULL , V_78 ) ;
}
static int F_41 ( struct V_69 * V_70 ,
unsigned int V_4 , unsigned int V_30 )
{
struct V_6 * V_7 = V_70 -> V_7 ;
int V_84 = 0 ;
F_32 ( V_7 , V_70 -> V_75 , V_70 -> V_85 ) ;
if ( ! V_30 )
return 0 ;
if ( ! V_70 -> V_86 )
F_40 ( V_7 , V_70 -> V_9 , V_30 ) ;
else {
struct V_87 * V_88 = F_42 ( V_70 -> V_86 ) ;
V_84 = F_35 ( V_7 , V_88 -> V_89 . V_90 ,
V_88 -> V_89 . V_91 , V_4 ,
V_30 ) ;
}
if ( V_84 ) {
return - V_68 ;
}
return 0 ;
}
static int F_43 ( struct V_69 * V_70 , T_3 V_92 )
{
struct V_93 * V_94 = V_70 -> V_29 ;
V_70 -> V_75 = V_70 -> V_29 + sizeof( * V_94 ) ;
V_70 -> V_95 = sizeof( struct V_96 ) - V_79 ;
return 0 ;
}
static struct V_97 *
F_44 ( struct V_98 * V_99 ,
T_4 V_100 )
{
struct V_6 * V_7 ;
struct V_97 * V_101 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
V_101 = F_45 ( V_99 , sizeof( * V_34 ) ,
V_100 ) ;
if ( ! V_101 )
return NULL ;
V_7 = V_101 -> V_29 ;
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
V_34 -> V_78 . V_102 = F_46 ( L_13 , 0 ,
V_103 ) ;
V_34 -> V_78 . V_48 = 0 ;
if ( F_47 ( V_34 -> V_78 . V_102 ) )
goto V_104;
V_34 -> V_105 . V_102 = F_46 ( L_13 , 0 ,
V_103 ) ;
V_34 -> V_105 . V_48 = 0 ;
if ( F_47 ( V_34 -> V_105 . V_102 ) )
goto V_106;
V_27 -> V_105 = & V_34 -> V_105 ;
return V_101 ;
V_106:
F_48 ( V_34 -> V_78 . V_102 ) ;
V_104:
F_49 ( V_107 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_50 ( V_101 ) ;
return NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_35 * V_20 = V_7 -> V_20 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
F_52 ( V_14 -> V_15 ) ;
F_22 ( V_7 ) ;
F_53 ( V_14 -> V_15 ) ;
F_54 ( & V_20 -> V_108 ) ;
V_34 -> V_14 = NULL ;
F_55 ( & V_20 -> V_108 ) ;
F_56 ( V_14 ) ;
}
static void F_57 ( struct V_97 * V_101 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
F_51 ( V_7 ) ;
if ( V_34 -> V_78 . V_102 )
F_48 ( V_34 -> V_78 . V_102 ) ;
if ( V_34 -> V_105 . V_102 )
F_48 ( V_34 -> V_105 . V_102 ) ;
F_50 ( V_101 ) ;
}
static void F_58 ( struct V_97 * V_101 , int V_109 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_42 * V_14 = V_34 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_110 = V_68 ;
F_59 ( F_60 ( V_14 -> V_15 ) ) ;
F_61 ( V_7 ) ;
F_51 ( V_7 ) ;
F_62 ( V_101 , V_109 ) ;
}
static int
F_63 ( struct V_98 * V_99 ,
struct V_97 * V_101 , T_5 V_111 ,
int V_112 )
{
struct V_35 * V_20 = V_99 -> V_29 ;
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_14 * V_15 ;
struct V_42 * V_14 ;
int V_84 ;
V_14 = F_64 ( ( int ) V_111 , & V_84 ) ;
if ( ! V_14 ) {
F_49 ( V_107 , V_7 ,
L_18 , V_84 ) ;
return - V_113 ;
}
V_84 = F_65 ( V_99 , V_101 , V_112 ) ;
if ( V_84 )
goto V_114;
F_54 ( & V_20 -> V_108 ) ;
V_34 -> V_14 = V_14 ;
F_55 ( & V_20 -> V_108 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_115 = V_116 ;
V_15 -> V_117 = 15 * V_118 ;
V_15 -> V_119 = V_120 ;
F_66 ( V_15 ) ;
F_19 ( V_7 ) ;
V_34 -> V_54 = V_34 -> V_14 -> V_121 -> V_54 ;
F_67 ( V_27 ) ;
return 0 ;
V_114:
F_56 ( V_14 ) ;
return V_84 ;
}
static int F_68 ( struct V_97 * V_101 ,
enum V_122 V_123 , char * V_124 ,
int V_125 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
switch( V_123 ) {
case V_126 :
F_69 ( V_101 , V_123 , V_124 , V_125 ) ;
break;
case V_127 :
F_69 ( V_101 , V_123 , V_124 , V_125 ) ;
V_34 -> V_54 = V_7 -> V_82 ?
V_128 : V_34 -> V_14 -> V_121 -> V_54 ;
break;
case V_129 :
return F_70 ( V_7 , V_124 ) ;
default:
return F_69 ( V_101 , V_123 , V_124 , V_125 ) ;
}
return 0 ;
}
static int F_71 ( struct V_97 * V_101 ,
enum V_122 V_123 , char * V_124 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_130 V_131 ;
int V_63 , V_5 ;
switch( V_123 ) {
case V_132 :
case V_133 :
case V_134 :
F_54 ( & V_7 -> V_20 -> V_108 ) ;
if ( ! V_34 || ! V_34 -> V_14 ) {
F_55 ( & V_7 -> V_20 -> V_108 ) ;
return - V_135 ;
}
if ( V_123 == V_134 )
V_63 = F_72 ( V_34 -> V_14 ,
(struct V_136 * ) & V_131 , & V_5 ) ;
else
V_63 = F_73 ( V_34 -> V_14 ,
(struct V_136 * ) & V_131 , & V_5 ) ;
F_55 ( & V_7 -> V_20 -> V_108 ) ;
if ( V_63 )
return V_63 ;
return F_74 ( (struct V_137 * )
& V_131 , V_123 , V_124 ) ;
default:
return F_75 ( V_101 , V_123 , V_124 ) ;
}
return 0 ;
}
static int F_76 ( struct V_138 * V_139 ,
enum V_140 V_123 , char * V_124 )
{
struct V_141 * V_142 = F_77 ( V_139 ) ;
struct V_35 * V_20 = V_142 -> V_20 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_130 V_131 ;
int V_63 , V_5 ;
switch ( V_123 ) {
case V_143 :
if ( ! V_20 )
return - V_135 ;
F_54 ( & V_20 -> V_108 ) ;
V_7 = V_20 -> V_144 ;
if ( ! V_7 ) {
F_55 ( & V_20 -> V_108 ) ;
return - V_135 ;
}
V_27 = V_7 -> V_29 ;
V_34 = V_27 -> V_29 ;
if ( ! V_34 -> V_14 ) {
F_55 ( & V_20 -> V_108 ) ;
return - V_135 ;
}
V_63 = F_72 ( V_34 -> V_14 ,
(struct V_136 * ) & V_131 , & V_5 ) ;
F_55 ( & V_20 -> V_108 ) ;
if ( V_63 )
return V_63 ;
return F_74 ( (struct V_137 * )
& V_131 , V_123 , V_124 ) ;
default:
return F_78 ( V_139 , V_123 , V_124 ) ;
}
return 0 ;
}
static void
F_79 ( struct V_97 * V_101 ,
struct V_145 * V_146 )
{
struct V_6 * V_7 = V_101 -> V_29 ;
struct V_26 * V_27 = V_7 -> V_29 ;
struct V_33 * V_34 = V_27 -> V_29 ;
V_146 -> V_147 = 3 ;
strcpy ( V_146 -> V_148 [ 0 ] . V_149 , L_19 ) ;
V_146 -> V_148 [ 0 ] . V_150 = V_34 -> V_151 ;
strcpy ( V_146 -> V_148 [ 1 ] . V_149 , L_20 ) ;
V_146 -> V_148 [ 1 ] . V_150 = V_34 -> V_152 ;
strcpy ( V_146 -> V_148 [ 2 ] . V_149 , L_21 ) ;
V_146 -> V_148 [ 2 ] . V_150 = V_7 -> V_153 ;
F_80 ( V_101 , V_146 ) ;
}
static struct V_98 *
F_81 ( struct V_154 * V_155 , T_6 V_156 ,
T_6 V_157 , T_4 V_158 )
{
struct V_98 * V_99 ;
struct V_35 * V_20 ;
struct V_141 * V_142 ;
struct V_138 * V_139 ;
if ( V_155 ) {
F_82 ( V_107 L_22 , V_155 ) ;
return NULL ;
}
V_139 = F_83 ( & V_159 ,
sizeof( struct V_141 ) , 1 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_160 = V_161 ;
V_139 -> V_162 = V_157 ;
V_139 -> V_163 = V_164 ;
V_139 -> V_165 = 0 ;
V_139 -> V_166 = 0 ;
V_139 -> V_167 = V_168 ;
if ( F_84 ( V_139 , NULL ) )
goto V_169;
V_99 = F_85 ( & V_170 , V_139 ,
V_156 , 0 ,
sizeof( struct V_93 ) +
sizeof( struct V_96 ) ,
V_158 , 0 ) ;
if ( ! V_99 )
goto V_171;
V_20 = V_99 -> V_29 ;
V_142 = F_77 ( V_139 ) ;
V_142 -> V_20 = V_20 ;
V_139 -> V_172 = V_20 -> V_173 ;
if ( F_86 ( V_20 ) )
goto V_174;
return V_99 ;
V_174:
F_87 ( V_99 ) ;
V_171:
F_88 ( V_139 ) ;
V_169:
F_89 ( V_139 ) ;
return NULL ;
}
static void F_90 ( struct V_98 * V_99 )
{
struct V_138 * V_139 = F_91 ( V_99 ) ;
F_92 ( V_99 -> V_29 ) ;
F_87 ( V_99 ) ;
F_88 ( V_139 ) ;
F_89 ( V_139 ) ;
}
static T_7 F_93 ( int V_175 , int V_123 )
{
switch ( V_175 ) {
case V_176 :
switch ( V_123 ) {
case V_177 :
case V_178 :
case V_143 :
case V_179 :
return V_180 ;
default:
return 0 ;
}
case V_181 :
switch ( V_123 ) {
case V_182 :
case V_183 :
case V_126 :
case V_127 :
case V_133 :
case V_132 :
case V_134 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_129 :
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
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
return V_180 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_94 ( struct V_208 * V_209 )
{
F_95 ( V_210 , & V_209 -> V_211 -> V_212 ) ;
return 0 ;
}
static int F_96 ( struct V_208 * V_209 )
{
F_97 ( V_209 -> V_211 , V_213 ) ;
F_98 ( V_209 -> V_211 , 0 ) ;
return 0 ;
}
static int T_8 F_99 ( void )
{
if ( V_164 < 1 ) {
F_82 ( V_107 L_23 ,
V_164 ) ;
return - V_214 ;
}
V_161 = F_100 (
& V_170 ) ;
if ( ! V_161 )
return - V_215 ;
return 0 ;
}
static void T_9 F_101 ( void )
{
F_102 ( & V_170 ) ;
}
