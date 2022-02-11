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
static void F_7 ( struct V_14 * V_15 , int V_26 )
{
struct V_6 * V_7 ;
struct V_27 * V_28 ;
T_1 V_1 ;
F_8 ( & V_15 -> V_29 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_29 ) ;
return;
}
V_28 = V_7 -> V_30 ;
V_1 . V_8 . V_9 = V_7 ;
V_1 . V_31 = 1 ;
F_10 ( V_15 , & V_1 , F_1 ) ;
F_4 ( V_15 ) ;
F_11 ( & V_28 -> V_32 . V_33 ) ;
F_9 ( & V_15 -> V_29 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_27 * V_28 ;
struct V_34 * V_35 ;
struct V_6 * V_7 ;
struct V_36 * V_20 ;
void (* F_13)( struct V_14 * );
F_8 ( & V_15 -> V_29 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_9 ( & V_15 -> V_29 ) ;
return;
}
V_20 = V_7 -> V_20 ;
F_4 ( V_15 ) ;
V_28 = V_7 -> V_30 ;
V_35 = V_28 -> V_30 ;
F_13 = V_35 -> F_13 ;
F_9 ( & V_15 -> V_29 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_27 * V_28 ;
struct V_34 * V_35 ;
void (* F_15)( struct V_14 * );
F_16 ( & V_15 -> V_29 ) ;
V_7 = V_15 -> V_16 ;
if ( ! V_7 ) {
F_17 ( & V_15 -> V_29 ) ;
return;
}
V_28 = V_7 -> V_30 ;
V_35 = V_28 -> V_30 ;
F_15 = V_35 -> F_15 ;
F_17 ( & V_15 -> V_29 ) ;
F_15 ( V_15 ) ;
F_2 ( V_7 , L_4 ) ;
F_18 ( V_7 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_14 * V_15 = V_35 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_29 ) ;
V_15 -> V_16 = V_7 ;
V_35 -> V_37 = V_15 -> V_38 ;
V_35 -> F_13 = V_15 -> V_39 ;
V_35 -> F_15 = V_15 -> V_40 ;
V_15 -> V_38 = F_7 ;
V_15 -> V_39 = F_12 ;
V_15 -> V_40 = F_14 ;
F_21 ( & V_15 -> V_29 ) ;
}
static void
F_22 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_14 * V_15 = V_35 -> V_14 -> V_15 ;
F_20 ( & V_15 -> V_29 ) ;
V_15 -> V_16 = NULL ;
V_15 -> V_38 = V_35 -> V_37 ;
V_15 -> V_39 = V_35 -> F_13 ;
V_15 -> V_40 = V_35 -> F_15 ;
V_15 -> V_41 = 0 ;
F_21 ( & V_15 -> V_29 ) ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_42 * V_33 )
{
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_43 * V_15 = V_35 -> V_14 ;
unsigned int V_44 = 0 ;
int V_45 = 0 ;
while ( ! F_24 ( V_28 , V_33 , 0 , V_45 ) ) {
struct V_46 * V_47 ;
unsigned int V_4 , V_48 ;
int V_49 = 0 ;
V_45 = 0 ;
V_4 = V_33 -> V_44 ;
V_48 = V_33 -> V_50 - V_4 ;
if ( V_33 -> V_51 + V_33 -> V_50 < V_33 -> V_52 )
V_49 |= V_53 ;
if ( ! V_33 -> V_9 ) {
V_47 = V_33 -> V_47 ;
V_4 += V_33 -> V_54 + V_47 -> V_4 ;
V_45 = V_35 -> V_55 ( V_15 , F_25 ( V_47 ) , V_4 ,
V_48 , V_49 ) ;
} else {
struct V_56 V_57 = { . V_58 = V_49 } ;
struct V_59 V_60 = {
. V_61 = V_33 -> V_9 + V_4 ,
. V_62 = V_48
} ;
V_45 = F_26 ( V_15 , & V_57 , & V_60 , 1 , V_48 ) ;
}
if ( V_45 < 0 ) {
F_11 ( V_33 ) ;
return V_45 ;
}
V_44 += V_45 ;
}
return V_44 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_42 * V_33 = & V_35 -> V_63 . V_33 ;
unsigned int V_10 = 0 ;
int V_64 = 0 ;
while ( 1 ) {
V_64 = F_23 ( V_28 , V_33 ) ;
if ( V_64 == - V_65 )
return V_64 ;
else if ( V_64 < 0 ) {
V_64 = V_66 ;
goto error;
} else if ( V_64 == 0 )
break;
V_10 += V_64 ;
if ( V_33 -> V_51 >= V_33 -> V_52 ) {
if ( V_33 -> V_67 != NULL ) {
V_64 = V_33 -> V_67 ( V_28 , V_33 ) ;
if ( V_64 != 0 )
goto error;
}
}
}
F_2 ( V_7 , L_5 , V_10 ) ;
V_7 -> V_68 += V_10 ;
return V_10 ;
error:
F_2 ( V_7 , L_6 , V_64 ) ;
F_6 ( V_7 , V_64 ) ;
return - V_69 ;
}
static inline int F_28 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_42 * V_33 = & V_35 -> V_63 . V_33 ;
return V_33 -> V_51 - V_33 -> V_52 ;
}
static int F_29 ( struct V_70 * V_71 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
unsigned long V_72 = V_73 -> V_49 ;
int V_64 = 0 ;
V_73 -> V_49 |= V_74 ;
while ( F_28 ( V_7 ) ) {
V_64 = F_27 ( V_7 ) ;
if ( V_64 == 0 ) {
V_64 = - V_65 ;
break;
}
if ( V_64 < 0 )
break;
V_64 = 0 ;
}
F_30 ( V_73 , V_72 , V_74 ) ;
return V_64 ;
}
static int F_31 ( struct V_27 * V_28 ,
struct V_42 * V_33 )
{
struct V_34 * V_35 = V_28 -> V_30 ;
V_35 -> V_63 . V_33 = V_35 -> V_63 . V_75 ;
F_2 ( V_28 -> V_6 ,
L_7 ,
V_35 -> V_63 . V_33 . V_50 ,
V_35 -> V_63 . V_33 . V_52 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 , void * V_76 ,
T_2 V_77 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
F_2 ( V_7 , L_8 , V_7 -> V_78 ?
L_9 : L_10 ) ;
memset ( & V_35 -> V_63 . V_75 , 0 ,
sizeof( struct V_42 ) ) ;
if ( V_7 -> V_78 ) {
F_33 ( & V_35 -> V_79 , V_76 , V_77 ,
V_76 + V_77 ) ;
V_77 += V_80 ;
}
V_35 -> V_63 . V_76 = V_76 ;
F_34 ( & V_35 -> V_63 . V_33 , V_76 , V_77 ,
F_31 , NULL ) ;
}
static int
F_35 ( struct V_6 * V_7 , struct V_46 * V_47 ,
unsigned int V_31 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_81 * V_79 = NULL ;
unsigned int V_82 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_83 ?
L_9 : L_10 ) ;
V_82 = F_36 ( V_35 -> V_63 . V_76 -> V_84 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_82 ) ) ;
if ( V_7 -> V_83 )
V_79 = & V_35 -> V_79 ;
return F_39 ( & V_35 -> V_63 . V_75 ,
V_47 , V_31 , V_4 , V_5 ,
NULL , V_79 ) ;
}
static void
F_40 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_81 * V_79 = NULL ;
unsigned int V_82 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_83 ?
L_9 : L_10 ) ;
V_82 = F_36 ( V_35 -> V_63 . V_76 -> V_84 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_82 ) ) ;
if ( V_7 -> V_83 )
V_79 = & V_35 -> V_79 ;
F_34 ( & V_35 -> V_63 . V_75 ,
V_9 , V_5 , NULL , V_79 ) ;
}
static int F_41 ( struct V_70 * V_71 ,
unsigned int V_4 , unsigned int V_31 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
int V_85 = 0 ;
F_32 ( V_7 , V_71 -> V_76 , V_71 -> V_86 ) ;
if ( ! V_31 )
return 0 ;
if ( ! V_71 -> V_87 )
F_40 ( V_7 , V_71 -> V_9 , V_31 ) ;
else {
struct V_88 * V_89 = F_42 ( V_71 -> V_87 ) ;
V_85 = F_35 ( V_7 , V_89 -> V_90 . V_91 ,
V_89 -> V_90 . V_92 , V_4 ,
V_31 ) ;
}
if ( V_85 ) {
return - V_69 ;
}
return 0 ;
}
static int F_43 ( struct V_70 * V_71 , T_3 V_93 )
{
struct V_94 * V_95 = V_71 -> V_30 ;
V_71 -> V_76 = V_71 -> V_30 + sizeof( * V_95 ) ;
V_71 -> V_96 = sizeof( struct V_97 ) - V_80 ;
return 0 ;
}
static struct V_98 *
F_44 ( struct V_99 * V_100 ,
T_4 V_101 )
{
struct V_6 * V_7 ;
struct V_98 * V_102 ;
struct V_27 * V_28 ;
struct V_34 * V_35 ;
V_102 = F_45 ( V_100 , sizeof( * V_35 ) ,
V_101 ) ;
if ( ! V_102 )
return NULL ;
V_7 = V_102 -> V_30 ;
V_28 = V_7 -> V_30 ;
V_35 = V_28 -> V_30 ;
V_35 -> V_79 . V_103 = F_46 ( L_13 , 0 ,
V_104 ) ;
V_35 -> V_79 . V_49 = 0 ;
if ( F_47 ( V_35 -> V_79 . V_103 ) )
goto V_105;
V_35 -> V_106 . V_103 = F_46 ( L_13 , 0 ,
V_104 ) ;
V_35 -> V_106 . V_49 = 0 ;
if ( F_47 ( V_35 -> V_106 . V_103 ) )
goto V_107;
V_28 -> V_106 = & V_35 -> V_106 ;
return V_102 ;
V_107:
F_48 ( V_35 -> V_79 . V_103 ) ;
V_105:
F_49 ( V_108 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_50 ( V_102 ) ;
return NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_36 * V_20 = V_7 -> V_20 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_43 * V_14 = V_35 -> V_14 ;
if ( ! V_14 )
return;
F_52 ( V_14 -> V_15 ) ;
F_22 ( V_7 ) ;
F_53 ( V_14 -> V_15 ) ;
F_54 ( & V_20 -> V_109 ) ;
V_35 -> V_14 = NULL ;
F_55 ( & V_20 -> V_109 ) ;
F_56 ( V_14 ) ;
}
static void F_57 ( struct V_98 * V_102 )
{
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
F_51 ( V_7 ) ;
if ( V_35 -> V_79 . V_103 )
F_48 ( V_35 -> V_79 . V_103 ) ;
if ( V_35 -> V_106 . V_103 )
F_48 ( V_35 -> V_106 . V_103 ) ;
F_50 ( V_102 ) ;
}
static void F_58 ( struct V_98 * V_102 , int V_26 )
{
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_43 * V_14 = V_35 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_110 = V_69 ;
F_59 ( F_60 ( V_14 -> V_15 ) ) ;
F_61 ( V_7 ) ;
F_51 ( V_7 ) ;
F_62 ( V_102 , V_26 ) ;
}
static int
F_63 ( struct V_99 * V_100 ,
struct V_98 * V_102 , T_5 V_111 ,
int V_112 )
{
struct V_36 * V_20 = V_100 -> V_30 ;
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_14 * V_15 ;
struct V_43 * V_14 ;
int V_85 ;
V_14 = F_64 ( ( int ) V_111 , & V_85 ) ;
if ( ! V_14 ) {
F_49 ( V_108 , V_7 ,
L_18 , V_85 ) ;
return - V_113 ;
}
V_85 = F_65 ( V_100 , V_102 , V_112 ) ;
if ( V_85 )
goto V_114;
F_54 ( & V_20 -> V_109 ) ;
V_35 -> V_14 = V_14 ;
F_55 ( & V_20 -> V_109 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_115 = V_116 ;
V_15 -> V_117 = 15 * V_118 ;
V_15 -> V_119 = V_120 ;
F_66 ( V_15 ) ;
F_19 ( V_7 ) ;
V_35 -> V_55 = V_35 -> V_14 -> V_121 -> V_55 ;
F_67 ( V_28 ) ;
return 0 ;
V_114:
F_56 ( V_14 ) ;
return V_85 ;
}
static int F_68 ( struct V_98 * V_102 ,
enum V_122 V_123 , char * V_124 ,
int V_125 )
{
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
switch( V_123 ) {
case V_126 :
F_69 ( V_102 , V_123 , V_124 , V_125 ) ;
break;
case V_127 :
F_69 ( V_102 , V_123 , V_124 , V_125 ) ;
V_35 -> V_55 = V_7 -> V_83 ?
V_128 : V_35 -> V_14 -> V_121 -> V_55 ;
break;
case V_129 :
return F_70 ( V_7 , V_124 ) ;
default:
return F_69 ( V_102 , V_123 , V_124 , V_125 ) ;
}
return 0 ;
}
static int F_71 ( struct V_98 * V_102 ,
enum V_122 V_123 , char * V_124 )
{
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
struct V_130 V_131 ;
int V_64 , V_5 ;
switch( V_123 ) {
case V_132 :
case V_133 :
F_54 ( & V_7 -> V_20 -> V_109 ) ;
if ( ! V_35 || ! V_35 -> V_14 ) {
F_55 ( & V_7 -> V_20 -> V_109 ) ;
return - V_134 ;
}
V_64 = F_72 ( V_35 -> V_14 ,
(struct V_135 * ) & V_131 , & V_5 ) ;
F_55 ( & V_7 -> V_20 -> V_109 ) ;
if ( V_64 )
return V_64 ;
return F_73 ( (struct V_136 * )
& V_131 , V_123 , V_124 ) ;
default:
return F_74 ( V_102 , V_123 , V_124 ) ;
}
return 0 ;
}
static int F_75 ( struct V_137 * V_138 ,
enum V_139 V_123 , char * V_124 )
{
struct V_140 * V_141 = F_76 ( V_138 ) ;
struct V_36 * V_20 = V_141 -> V_20 ;
struct V_6 * V_7 ;
struct V_27 * V_28 ;
struct V_34 * V_35 ;
struct V_130 V_131 ;
int V_64 , V_5 ;
switch ( V_123 ) {
case V_142 :
F_54 ( & V_20 -> V_109 ) ;
V_7 = V_20 -> V_143 ;
if ( ! V_7 ) {
F_55 ( & V_20 -> V_109 ) ;
return - V_134 ;
}
V_28 = V_7 -> V_30 ;
V_35 = V_28 -> V_30 ;
if ( ! V_35 -> V_14 ) {
F_55 ( & V_20 -> V_109 ) ;
return - V_134 ;
}
V_64 = F_77 ( V_35 -> V_14 ,
(struct V_135 * ) & V_131 , & V_5 ) ;
F_55 ( & V_20 -> V_109 ) ;
if ( V_64 )
return V_64 ;
return F_73 ( (struct V_136 * )
& V_131 , V_123 , V_124 ) ;
default:
return F_78 ( V_138 , V_123 , V_124 ) ;
}
return 0 ;
}
static void
F_79 ( struct V_98 * V_102 ,
struct V_144 * V_145 )
{
struct V_6 * V_7 = V_102 -> V_30 ;
struct V_27 * V_28 = V_7 -> V_30 ;
struct V_34 * V_35 = V_28 -> V_30 ;
V_145 -> V_146 = 3 ;
strcpy ( V_145 -> V_147 [ 0 ] . V_148 , L_19 ) ;
V_145 -> V_147 [ 0 ] . V_149 = V_35 -> V_150 ;
strcpy ( V_145 -> V_147 [ 1 ] . V_148 , L_20 ) ;
V_145 -> V_147 [ 1 ] . V_149 = V_35 -> V_151 ;
strcpy ( V_145 -> V_147 [ 2 ] . V_148 , L_21 ) ;
V_145 -> V_147 [ 2 ] . V_149 = V_7 -> V_152 ;
F_80 ( V_102 , V_145 ) ;
}
static struct V_99 *
F_81 ( struct V_153 * V_154 , T_6 V_155 ,
T_6 V_156 , T_4 V_157 )
{
struct V_99 * V_100 ;
struct V_36 * V_20 ;
struct V_140 * V_141 ;
struct V_137 * V_138 ;
if ( V_154 ) {
F_82 ( V_108 L_22 , V_154 ) ;
return NULL ;
}
V_138 = F_83 ( & V_158 ,
sizeof( struct V_140 ) , 1 ) ;
if ( ! V_138 )
return NULL ;
V_138 -> V_159 = V_160 ;
V_138 -> V_161 = V_156 ;
V_138 -> V_162 = V_163 ;
V_138 -> V_164 = 0 ;
V_138 -> V_165 = 0 ;
V_138 -> V_166 = V_167 ;
if ( F_84 ( V_138 , NULL ) )
goto V_168;
V_100 = F_85 ( & V_169 , V_138 ,
V_155 , 0 ,
sizeof( struct V_94 ) +
sizeof( struct V_97 ) ,
V_157 , 0 ) ;
if ( ! V_100 )
goto V_170;
V_20 = V_100 -> V_30 ;
V_141 = F_76 ( V_138 ) ;
V_141 -> V_20 = V_20 ;
V_138 -> V_171 = V_20 -> V_172 ;
if ( F_86 ( V_20 ) )
goto V_173;
return V_100 ;
V_173:
F_87 ( V_100 ) ;
V_170:
F_88 ( V_138 ) ;
V_168:
F_89 ( V_138 ) ;
return NULL ;
}
static void F_90 ( struct V_99 * V_100 )
{
struct V_137 * V_138 = F_91 ( V_100 ) ;
F_92 ( V_100 -> V_30 ) ;
F_87 ( V_100 ) ;
F_88 ( V_138 ) ;
F_89 ( V_138 ) ;
}
static T_7 F_93 ( int V_174 , int V_123 )
{
switch ( V_174 ) {
case V_175 :
switch ( V_123 ) {
case V_176 :
case V_177 :
case V_142 :
case V_178 :
return V_179 ;
default:
return 0 ;
}
case V_180 :
switch ( V_123 ) {
case V_181 :
case V_182 :
case V_126 :
case V_127 :
case V_133 :
case V_132 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_129 :
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
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
return V_179 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_94 ( struct V_207 * V_208 )
{
F_95 ( V_209 , & V_208 -> V_210 -> V_211 ) ;
return 0 ;
}
static int F_96 ( struct V_207 * V_208 )
{
F_97 ( V_208 -> V_210 , V_212 ) ;
F_98 ( V_208 -> V_210 , 0 ) ;
return 0 ;
}
static int T_8 F_99 ( void )
{
if ( V_163 < 1 ) {
F_82 ( V_108 L_23 ,
V_163 ) ;
return - V_213 ;
}
V_160 = F_100 (
& V_169 ) ;
if ( ! V_160 )
return - V_214 ;
return 0 ;
}
static void T_9 F_101 ( void )
{
F_102 ( & V_169 ) ;
}
