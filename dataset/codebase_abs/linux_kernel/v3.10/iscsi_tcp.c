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
unsigned long V_70 = V_71 -> V_47 ;
int V_62 = 0 ;
V_71 -> V_47 |= V_72 ;
while ( F_28 ( V_7 ) ) {
V_62 = F_27 ( V_7 ) ;
if ( V_62 == 0 ) {
V_62 = - V_63 ;
break;
}
if ( V_62 < 0 )
break;
V_62 = 0 ;
}
F_30 ( V_71 , V_70 , V_72 ) ;
return V_62 ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_40 * V_30 )
{
struct V_31 * V_32 = V_25 -> V_27 ;
V_32 -> V_61 . V_30 = V_32 -> V_61 . V_73 ;
F_2 ( V_25 -> V_6 ,
L_7 ,
V_32 -> V_61 . V_30 . V_48 ,
V_32 -> V_61 . V_30 . V_50 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 , void * V_74 ,
T_2 V_75 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
F_2 ( V_7 , L_8 , V_7 -> V_76 ?
L_9 : L_10 ) ;
memset ( & V_32 -> V_61 . V_73 , 0 ,
sizeof( struct V_40 ) ) ;
if ( V_7 -> V_76 ) {
F_33 ( & V_32 -> V_77 , V_74 , V_75 ,
V_74 + V_75 ) ;
V_75 += V_78 ;
}
V_32 -> V_61 . V_74 = V_74 ;
F_34 ( & V_32 -> V_61 . V_30 , V_74 , V_75 ,
F_31 , NULL ) ;
}
static int
F_35 ( struct V_6 * V_7 , struct V_44 * V_45 ,
unsigned int V_28 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_79 * V_77 = NULL ;
unsigned int V_80 ;
F_2 ( V_7 , L_11 , V_4 , V_5 ,
V_7 -> V_81 ?
L_9 : L_10 ) ;
V_80 = F_36 ( V_32 -> V_61 . V_74 -> V_82 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_80 ) ) ;
if ( V_7 -> V_81 )
V_77 = & V_32 -> V_77 ;
return F_39 ( & V_32 -> V_61 . V_73 ,
V_45 , V_28 , V_4 , V_5 ,
NULL , V_77 ) ;
}
static void
F_40 ( struct V_6 * V_7 , void * V_9 ,
T_2 V_5 )
{
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_79 * V_77 = NULL ;
unsigned int V_80 ;
F_2 ( V_7 , L_12 , V_5 , V_7 -> V_81 ?
L_9 : L_10 ) ;
V_80 = F_36 ( V_32 -> V_61 . V_74 -> V_82 ) ;
F_37 ( F_38 ( V_5 ) != F_38 ( V_80 ) ) ;
if ( V_7 -> V_81 )
V_77 = & V_32 -> V_77 ;
F_34 ( & V_32 -> V_61 . V_73 ,
V_9 , V_5 , NULL , V_77 ) ;
}
static int F_41 ( struct V_68 * V_69 ,
unsigned int V_4 , unsigned int V_28 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
int V_83 = 0 ;
F_32 ( V_7 , V_69 -> V_74 , V_69 -> V_84 ) ;
if ( ! V_28 )
return 0 ;
if ( ! V_69 -> V_85 )
F_40 ( V_7 , V_69 -> V_9 , V_28 ) ;
else {
struct V_86 * V_87 = F_42 ( V_69 -> V_85 ) ;
V_83 = F_35 ( V_7 , V_87 -> V_88 . V_89 ,
V_87 -> V_88 . V_90 , V_4 ,
V_28 ) ;
}
if ( V_83 ) {
return - V_67 ;
}
return 0 ;
}
static int F_43 ( struct V_68 * V_69 , T_3 V_91 )
{
struct V_92 * V_93 = V_69 -> V_27 ;
V_69 -> V_74 = V_69 -> V_27 + sizeof( * V_93 ) ;
V_69 -> V_94 = sizeof( struct V_95 ) - V_78 ;
return 0 ;
}
static struct V_96 *
F_44 ( struct V_97 * V_98 ,
T_4 V_99 )
{
struct V_6 * V_7 ;
struct V_96 * V_100 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
V_100 = F_45 ( V_98 , sizeof( * V_32 ) ,
V_99 ) ;
if ( ! V_100 )
return NULL ;
V_7 = V_100 -> V_27 ;
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
V_32 -> V_77 . V_101 = F_46 ( L_13 , 0 ,
V_102 ) ;
V_32 -> V_77 . V_47 = 0 ;
if ( F_47 ( V_32 -> V_77 . V_101 ) )
goto V_103;
V_32 -> V_104 . V_101 = F_46 ( L_13 , 0 ,
V_102 ) ;
V_32 -> V_104 . V_47 = 0 ;
if ( F_47 ( V_32 -> V_104 . V_101 ) )
goto V_105;
V_25 -> V_104 = & V_32 -> V_104 ;
return V_100 ;
V_105:
F_48 ( V_32 -> V_77 . V_101 ) ;
V_103:
F_49 ( V_106 , V_7 ,
L_14
L_15
L_16
L_17 ) ;
F_50 ( V_100 ) ;
return NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_41 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
F_52 ( V_14 -> V_15 ) ;
F_22 ( V_7 ) ;
F_53 ( V_14 -> V_15 ) ;
F_54 ( & V_34 -> V_107 ) ;
V_32 -> V_14 = NULL ;
F_55 ( & V_34 -> V_107 ) ;
F_56 ( V_14 ) ;
}
static void F_57 ( struct V_96 * V_100 )
{
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
F_51 ( V_7 ) ;
if ( V_32 -> V_77 . V_101 )
F_48 ( V_32 -> V_77 . V_101 ) ;
if ( V_32 -> V_104 . V_101 )
F_48 ( V_32 -> V_104 . V_101 ) ;
F_50 ( V_100 ) ;
}
static void F_58 ( struct V_96 * V_100 , int V_23 )
{
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_41 * V_14 = V_32 -> V_14 ;
if ( ! V_14 )
return;
V_14 -> V_15 -> V_108 = V_67 ;
F_59 ( F_60 ( V_14 -> V_15 ) ) ;
F_61 ( V_7 ) ;
F_51 ( V_7 ) ;
F_62 ( V_100 , V_23 ) ;
}
static int
F_63 ( struct V_97 * V_98 ,
struct V_96 * V_100 , T_5 V_109 ,
int V_110 )
{
struct V_33 * V_34 = V_98 -> V_27 ;
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_14 * V_15 ;
struct V_41 * V_14 ;
int V_83 ;
V_14 = F_64 ( ( int ) V_109 , & V_83 ) ;
if ( ! V_14 ) {
F_49 ( V_106 , V_7 ,
L_18 , V_83 ) ;
return - V_111 ;
}
V_83 = F_65 ( V_98 , V_100 , V_110 ) ;
if ( V_83 )
goto V_112;
F_54 ( & V_34 -> V_107 ) ;
V_32 -> V_14 = V_14 ;
F_55 ( & V_34 -> V_107 ) ;
V_15 = V_14 -> V_15 ;
V_15 -> V_113 = V_114 ;
V_15 -> V_115 = 15 * V_116 ;
V_15 -> V_117 = V_118 ;
F_66 ( V_15 ) ;
F_19 ( V_7 ) ;
V_32 -> V_53 = V_32 -> V_14 -> V_119 -> V_53 ;
F_67 ( V_25 ) ;
return 0 ;
V_112:
F_56 ( V_14 ) ;
return V_83 ;
}
static int F_68 ( struct V_96 * V_100 ,
enum V_120 V_121 , char * V_122 ,
int V_123 )
{
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
switch( V_121 ) {
case V_124 :
F_69 ( V_100 , V_121 , V_122 , V_123 ) ;
break;
case V_125 :
F_69 ( V_100 , V_121 , V_122 , V_123 ) ;
V_32 -> V_53 = V_7 -> V_81 ?
V_126 : V_32 -> V_14 -> V_119 -> V_53 ;
break;
case V_127 :
return F_70 ( V_7 , V_122 ) ;
default:
return F_69 ( V_100 , V_121 , V_122 , V_123 ) ;
}
return 0 ;
}
static int F_71 ( struct V_96 * V_100 ,
enum V_120 V_121 , char * V_122 )
{
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
struct V_128 V_129 ;
int V_62 , V_5 ;
switch( V_121 ) {
case V_130 :
case V_131 :
F_54 ( & V_7 -> V_34 -> V_107 ) ;
if ( ! V_32 || ! V_32 -> V_14 ) {
F_55 ( & V_7 -> V_34 -> V_107 ) ;
return - V_132 ;
}
V_62 = F_72 ( V_32 -> V_14 ,
(struct V_133 * ) & V_129 , & V_5 ) ;
F_55 ( & V_7 -> V_34 -> V_107 ) ;
if ( V_62 )
return V_62 ;
return F_73 ( (struct V_134 * )
& V_129 , V_121 , V_122 ) ;
default:
return F_74 ( V_100 , V_121 , V_122 ) ;
}
return 0 ;
}
static int F_75 ( struct V_135 * V_136 ,
enum V_137 V_121 , char * V_122 )
{
struct V_138 * V_139 = F_76 ( V_136 ) ;
struct V_33 * V_34 = V_139 -> V_34 ;
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
struct V_128 V_129 ;
int V_62 , V_5 ;
switch ( V_121 ) {
case V_140 :
F_54 ( & V_34 -> V_107 ) ;
V_7 = V_34 -> V_141 ;
if ( ! V_7 ) {
F_55 ( & V_34 -> V_107 ) ;
return - V_132 ;
}
V_25 = V_7 -> V_27 ;
V_32 = V_25 -> V_27 ;
if ( ! V_32 -> V_14 ) {
F_55 ( & V_34 -> V_107 ) ;
return - V_132 ;
}
V_62 = F_77 ( V_32 -> V_14 ,
(struct V_133 * ) & V_129 , & V_5 ) ;
F_55 ( & V_34 -> V_107 ) ;
if ( V_62 )
return V_62 ;
return F_73 ( (struct V_134 * )
& V_129 , V_121 , V_122 ) ;
default:
return F_78 ( V_136 , V_121 , V_122 ) ;
}
return 0 ;
}
static void
F_79 ( struct V_96 * V_100 ,
struct V_142 * V_143 )
{
struct V_6 * V_7 = V_100 -> V_27 ;
struct V_24 * V_25 = V_7 -> V_27 ;
struct V_31 * V_32 = V_25 -> V_27 ;
V_143 -> V_144 = 3 ;
strcpy ( V_143 -> V_145 [ 0 ] . V_146 , L_19 ) ;
V_143 -> V_145 [ 0 ] . V_147 = V_32 -> V_148 ;
strcpy ( V_143 -> V_145 [ 1 ] . V_146 , L_20 ) ;
V_143 -> V_145 [ 1 ] . V_147 = V_32 -> V_149 ;
strcpy ( V_143 -> V_145 [ 2 ] . V_146 , L_21 ) ;
V_143 -> V_145 [ 2 ] . V_147 = V_7 -> V_150 ;
F_80 ( V_100 , V_143 ) ;
}
static struct V_97 *
F_81 ( struct V_151 * V_152 , T_6 V_153 ,
T_6 V_154 , T_4 V_155 )
{
struct V_97 * V_98 ;
struct V_33 * V_34 ;
struct V_138 * V_139 ;
struct V_135 * V_136 ;
if ( V_152 ) {
F_82 ( V_106 L_22 , V_152 ) ;
return NULL ;
}
V_136 = F_83 ( & V_156 ,
sizeof( struct V_138 ) , 1 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> V_157 = V_158 ;
V_136 -> V_159 = V_154 ;
V_136 -> V_160 = V_161 ;
V_136 -> V_162 = 0 ;
V_136 -> V_163 = 0 ;
V_136 -> V_164 = V_165 ;
if ( F_84 ( V_136 , NULL ) )
goto V_166;
V_98 = F_85 ( & V_167 , V_136 ,
V_153 , 0 ,
sizeof( struct V_92 ) +
sizeof( struct V_95 ) ,
V_155 , 0 ) ;
if ( ! V_98 )
goto V_168;
V_34 = V_98 -> V_27 ;
V_139 = F_76 ( V_136 ) ;
V_139 -> V_34 = V_34 ;
V_136 -> V_169 = V_34 -> V_170 ;
if ( F_86 ( V_34 ) )
goto V_171;
return V_98 ;
V_171:
F_87 ( V_98 ) ;
V_168:
F_88 ( V_136 ) ;
V_166:
F_89 ( V_136 ) ;
return NULL ;
}
static void F_90 ( struct V_97 * V_98 )
{
struct V_135 * V_136 = F_91 ( V_98 ) ;
F_92 ( V_98 -> V_27 ) ;
F_87 ( V_98 ) ;
F_88 ( V_136 ) ;
F_89 ( V_136 ) ;
}
static T_7 F_93 ( int V_172 , int V_121 )
{
switch ( V_172 ) {
case V_173 :
switch ( V_121 ) {
case V_174 :
case V_175 :
case V_140 :
case V_176 :
return V_177 ;
default:
return 0 ;
}
case V_178 :
switch ( V_121 ) {
case V_179 :
case V_180 :
case V_124 :
case V_125 :
case V_131 :
case V_130 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_127 :
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
case V_201 :
case V_202 :
case V_203 :
case V_204 :
return V_177 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_94 ( struct V_205 * V_206 )
{
F_95 ( V_207 , & V_206 -> V_208 -> V_209 ) ;
return 0 ;
}
static int F_96 ( struct V_205 * V_206 )
{
F_97 ( V_206 -> V_208 , V_210 ) ;
F_98 ( V_206 -> V_208 , 0 ) ;
return 0 ;
}
static int T_8 F_99 ( void )
{
if ( V_161 < 1 ) {
F_82 ( V_106 L_23 ,
V_161 ) ;
return - V_211 ;
}
V_158 = F_100 (
& V_167 ) ;
if ( ! V_158 )
return - V_212 ;
return 0 ;
}
static void T_9 F_101 ( void )
{
F_102 ( & V_167 ) ;
}
