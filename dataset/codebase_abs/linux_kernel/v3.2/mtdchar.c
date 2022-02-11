static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
switch ( V_3 ) {
case V_9 :
break;
case V_10 :
V_2 += V_1 -> V_11 ;
break;
case V_12 :
V_2 += V_8 -> V_13 ;
break;
default:
return - V_14 ;
}
if ( V_2 >= 0 && V_2 <= V_8 -> V_13 )
return V_1 -> V_11 = V_2 ;
return - V_14 ;
}
static int F_2 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
int V_16 = F_3 ( V_15 ) ;
int V_17 = V_16 >> 1 ;
int V_18 = 0 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
struct V_15 * V_19 ;
F_4 ( L_1 ) ;
if ( ( V_1 -> V_20 & V_21 ) && ( V_16 & 1 ) )
return - V_22 ;
F_5 ( & V_23 ) ;
V_8 = F_6 ( NULL , V_17 ) ;
if ( F_7 ( V_8 ) ) {
V_18 = F_8 ( V_8 ) ;
goto V_24;
}
if ( V_8 -> type == V_25 ) {
F_9 ( V_8 ) ;
V_18 = - V_26 ;
goto V_24;
}
V_19 = F_10 ( V_27 -> V_28 , V_17 ) ;
if ( ! V_19 ) {
F_9 ( V_8 ) ;
V_18 = - V_29 ;
goto V_24;
}
if ( V_19 -> V_30 & V_31 ) {
V_19 -> V_32 = V_8 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_35 . V_36 = V_8 -> V_36 ;
F_11 ( V_19 ) ;
}
V_1 -> V_37 = V_19 -> V_38 ;
if ( ( V_1 -> V_20 & V_21 ) && ! ( V_8 -> V_39 & V_40 ) ) {
F_12 ( V_19 ) ;
F_9 ( V_8 ) ;
V_18 = - V_22 ;
goto V_24;
}
V_5 = F_13 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 ) {
F_12 ( V_19 ) ;
F_9 ( V_8 ) ;
V_18 = - V_29 ;
goto V_24;
}
V_5 -> V_42 = V_19 ;
V_5 -> V_8 = V_8 ;
V_1 -> V_6 = V_5 ;
V_24:
F_14 ( & V_23 ) ;
return V_18 ;
}
static int F_15 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_4 ( L_2 ) ;
if ( ( V_1 -> V_20 & V_21 ) && V_8 -> V_43 )
V_8 -> V_43 ( V_8 ) ;
F_12 ( V_5 -> V_42 ) ;
F_9 ( V_8 ) ;
V_1 -> V_6 = NULL ;
F_16 ( V_5 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_1 * V_1 , char T_3 * V_44 , T_4 V_45 , T_1 * V_46 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_47 = 0 ;
T_4 V_48 = 0 ;
int V_18 = 0 ;
int V_49 ;
T_4 V_13 = V_45 ;
char * V_50 ;
F_4 ( L_3 ) ;
if ( * V_46 + V_45 > V_8 -> V_13 )
V_45 = V_8 -> V_13 - * V_46 ;
if ( ! V_45 )
return 0 ;
V_50 = F_18 ( V_8 , & V_13 ) ;
if ( ! V_50 )
return - V_29 ;
while ( V_45 ) {
V_49 = F_19 ( T_4 , V_45 , V_13 ) ;
switch ( V_5 -> V_51 ) {
case V_52 :
V_18 = V_8 -> V_53 ( V_8 , * V_46 , V_49 , & V_47 , V_50 ) ;
break;
case V_54 :
V_18 = V_8 -> V_55 ( V_8 , * V_46 , V_49 , & V_47 , V_50 ) ;
break;
case V_56 :
{
struct V_57 V_58 ;
V_58 . V_51 = V_59 ;
V_58 . V_60 = V_50 ;
V_58 . V_61 = NULL ;
V_58 . V_49 = V_49 ;
V_18 = V_8 -> V_62 ( V_8 , * V_46 , & V_58 ) ;
V_47 = V_58 . V_47 ;
break;
}
default:
V_18 = V_8 -> V_63 ( V_8 , * V_46 , V_49 , & V_47 , V_50 ) ;
}
if ( ! V_18 || F_20 ( V_18 ) ) {
* V_46 += V_47 ;
if ( F_21 ( V_44 , V_50 , V_47 ) ) {
F_16 ( V_50 ) ;
return - V_64 ;
}
else
V_48 += V_47 ;
V_45 -= V_47 ;
V_44 += V_47 ;
if ( V_47 == 0 )
V_45 = 0 ;
}
else {
F_16 ( V_50 ) ;
return V_18 ;
}
}
F_16 ( V_50 ) ;
return V_48 ;
}
static T_2 F_22 ( struct V_1 * V_1 , const char T_3 * V_44 , T_4 V_45 , T_1 * V_46 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_13 = V_45 ;
char * V_50 ;
T_4 V_47 ;
T_4 V_48 = 0 ;
int V_18 = 0 ;
int V_49 ;
F_4 ( L_4 ) ;
if ( * V_46 == V_8 -> V_13 )
return - V_65 ;
if ( * V_46 + V_45 > V_8 -> V_13 )
V_45 = V_8 -> V_13 - * V_46 ;
if ( ! V_45 )
return 0 ;
V_50 = F_18 ( V_8 , & V_13 ) ;
if ( ! V_50 )
return - V_29 ;
while ( V_45 ) {
V_49 = F_19 ( T_4 , V_45 , V_13 ) ;
if ( F_23 ( V_50 , V_44 , V_49 ) ) {
F_16 ( V_50 ) ;
return - V_64 ;
}
switch ( V_5 -> V_51 ) {
case V_52 :
V_18 = - V_66 ;
break;
case V_54 :
if ( ! V_8 -> V_67 ) {
V_18 = - V_68 ;
break;
}
V_18 = V_8 -> V_67 ( V_8 , * V_46 , V_49 , & V_47 , V_50 ) ;
break;
case V_56 :
{
struct V_57 V_58 ;
V_58 . V_51 = V_59 ;
V_58 . V_60 = V_50 ;
V_58 . V_61 = NULL ;
V_58 . V_69 = 0 ;
V_58 . V_49 = V_49 ;
V_18 = V_8 -> V_70 ( V_8 , * V_46 , & V_58 ) ;
V_47 = V_58 . V_47 ;
break;
}
default:
V_18 = ( * ( V_8 -> V_71 ) ) ( V_8 , * V_46 , V_49 , & V_47 , V_50 ) ;
}
if ( ! V_18 ) {
* V_46 += V_47 ;
V_48 += V_47 ;
V_45 -= V_47 ;
V_44 += V_47 ;
}
else {
F_16 ( V_50 ) ;
return V_18 ;
}
}
F_16 ( V_50 ) ;
return V_48 ;
}
static void F_24 ( struct V_72 * V_73 )
{
F_25 ( ( V_74 * ) V_73 -> V_75 ) ;
}
static int F_26 ( struct V_4 * V_5 , int V_51 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
int V_18 = 0 ;
switch ( V_51 ) {
case V_76 :
if ( ! V_8 -> V_53 )
V_18 = - V_68 ;
else
V_5 -> V_51 = V_52 ;
break;
case V_77 :
if ( ! V_8 -> V_53 )
V_18 = - V_68 ;
else
V_5 -> V_51 = V_54 ;
break;
default:
V_18 = - V_14 ;
case V_78 :
break;
}
return V_18 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_79 , T_6 V_80 , void T_3 * V_81 ,
T_6 T_3 * V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_57 V_58 ;
T_6 V_47 ;
int V_18 = 0 ;
if ( ! ( V_1 -> V_20 & V_21 ) )
return - V_83 ;
if ( V_80 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_70 )
V_18 = - V_68 ;
else
V_18 = F_28 ( V_84 , V_81 , V_80 ) ? 0 : - V_64 ;
if ( V_18 )
return V_18 ;
V_58 . V_85 = V_80 ;
V_58 . V_69 = V_79 & ( V_8 -> V_86 - 1 ) ;
V_58 . V_60 = NULL ;
V_58 . V_51 = ( V_5 -> V_51 == V_56 ) ? V_59 :
V_87 ;
if ( V_58 . V_69 && V_58 . V_85 > ( V_8 -> V_88 - V_58 . V_69 ) )
return - V_14 ;
V_58 . V_61 = F_29 ( V_81 , V_80 ) ;
if ( F_7 ( V_58 . V_61 ) )
return F_8 ( V_58 . V_61 ) ;
V_79 &= ~ ( ( T_5 ) V_8 -> V_86 - 1 ) ;
V_18 = V_8 -> V_70 ( V_8 , V_79 , & V_58 ) ;
if ( V_58 . V_89 > 0xFFFFFFFFU )
V_18 = - V_90 ;
V_47 = V_58 . V_89 ;
if ( F_21 ( V_82 , & V_47 , sizeof( V_80 ) ) )
V_18 = - V_64 ;
F_16 ( V_58 . V_61 ) ;
return V_18 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_79 , T_6 V_80 , void T_3 * V_81 ,
T_6 T_3 * V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_57 V_58 ;
int V_18 = 0 ;
if ( V_80 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_62 )
V_18 = - V_68 ;
else
V_18 = F_28 ( V_91 , V_81 ,
V_80 ) ? 0 : - V_64 ;
if ( V_18 )
return V_18 ;
V_58 . V_85 = V_80 ;
V_58 . V_69 = V_79 & ( V_8 -> V_86 - 1 ) ;
V_58 . V_60 = NULL ;
V_58 . V_51 = ( V_5 -> V_51 == V_56 ) ? V_59 :
V_87 ;
if ( V_58 . V_69 && V_58 . V_85 > ( V_8 -> V_88 - V_58 . V_69 ) )
return - V_14 ;
V_58 . V_61 = F_31 ( V_80 , V_41 ) ;
if ( ! V_58 . V_61 )
return - V_29 ;
V_79 &= ~ ( ( T_5 ) V_8 -> V_86 - 1 ) ;
V_18 = V_8 -> V_62 ( V_8 , V_79 , & V_58 ) ;
if ( F_32 ( V_58 . V_89 , V_82 ) )
V_18 = - V_64 ;
else if ( V_58 . V_89 && F_21 ( V_81 , V_58 . V_61 ,
V_58 . V_89 ) )
V_18 = - V_64 ;
F_16 ( V_58 . V_61 ) ;
if ( F_20 ( V_18 ) )
return 0 ;
return V_18 ;
}
static int F_33 ( const struct V_92 * V_93 ,
struct V_94 * V_95 )
{
int V_96 ;
if ( ! V_93 || ! V_95 )
return - V_14 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_97 = F_34 ( ( int ) V_93 -> V_97 , V_98 ) ;
for ( V_96 = 0 ; V_96 < V_95 -> V_97 ; V_96 ++ )
V_95 -> V_99 [ V_96 ] = V_93 -> V_99 [ V_96 ] ;
for ( V_96 = 0 ; V_96 < V_100 ; V_96 ++ ) {
if ( V_93 -> V_101 [ V_96 ] . V_80 == 0 &&
V_93 -> V_101 [ V_96 ] . V_2 == 0 )
break;
V_95 -> V_102 += V_93 -> V_101 [ V_96 ] . V_80 ;
V_95 -> V_101 [ V_96 ] = V_93 -> V_101 [ V_96 ] ;
}
return 0 ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_103 T_3 * V_104 )
{
struct V_103 V_105 ;
struct V_106 V_107 ;
if ( ! F_36 ( V_108 ) )
return - V_83 ;
if ( F_23 ( & V_105 , V_104 , sizeof( struct V_103 ) ) )
return - V_64 ;
if ( F_23 ( & V_107 , V_105 . V_109 , sizeof( struct V_106 ) ) )
return - V_64 ;
switch ( V_105 . V_110 ) {
case V_111 :
if ( F_37 ( V_8 ) )
return - V_14 ;
return F_38 ( V_8 , V_107 . V_112 , V_107 . V_79 , V_107 . V_80 ) ;
case V_113 :
if ( V_107 . V_114 < 0 )
return - V_14 ;
return F_39 ( V_8 , V_107 . V_114 ) ;
default:
return - V_14 ;
}
}
static int F_40 ( struct V_7 * V_8 ,
struct V_115 T_3 * V_116 )
{
struct V_115 V_117 ;
struct V_57 V_58 ;
void T_3 * V_118 , * V_119 ;
int V_18 ;
if ( F_23 ( & V_117 , V_116 , sizeof( V_117 ) ) ||
! F_28 ( V_84 , V_117 . V_118 , V_117 . V_49 ) ||
! F_28 ( V_84 , V_117 . V_119 , V_117 . V_85 ) )
return - V_64 ;
if ( ! V_8 -> V_70 )
return - V_68 ;
V_58 . V_51 = V_117 . V_51 ;
V_58 . V_49 = ( T_4 ) V_117 . V_49 ;
V_58 . V_85 = ( T_4 ) V_117 . V_85 ;
V_58 . V_69 = 0 ;
V_118 = ( void T_3 * ) ( V_120 ) V_117 . V_118 ;
V_119 = ( void T_3 * ) ( V_120 ) V_117 . V_119 ;
if ( V_117 . V_118 ) {
V_58 . V_60 = F_29 ( V_118 , V_58 . V_49 ) ;
if ( F_7 ( V_58 . V_60 ) )
return F_8 ( V_58 . V_60 ) ;
} else {
V_58 . V_60 = NULL ;
}
if ( V_117 . V_119 ) {
V_58 . V_61 = F_29 ( V_119 , V_58 . V_85 ) ;
if ( F_7 ( V_58 . V_61 ) ) {
F_16 ( V_58 . V_60 ) ;
return F_8 ( V_58 . V_61 ) ;
}
} else {
V_58 . V_61 = NULL ;
}
V_18 = V_8 -> V_70 ( V_8 , ( T_1 ) V_117 . V_79 , & V_58 ) ;
F_16 ( V_58 . V_60 ) ;
F_16 ( V_58 . V_61 ) ;
return V_18 ;
}
static int F_41 ( struct V_1 * V_1 , T_7 V_121 , T_8 V_104 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_116 = ( void T_3 * ) V_104 ;
int V_18 = 0 ;
T_8 V_13 ;
struct V_122 V_123 ;
F_4 ( L_5 ) ;
V_13 = ( V_121 & V_124 ) >> V_125 ;
if ( V_121 & V_126 ) {
if ( ! F_28 ( V_84 , V_116 , V_13 ) )
return - V_64 ;
}
if ( V_121 & V_127 ) {
if ( ! F_28 ( V_91 , V_116 , V_13 ) )
return - V_64 ;
}
switch ( V_121 ) {
case V_128 :
if ( F_21 ( V_116 , & ( V_8 -> V_129 ) , sizeof( int ) ) )
return - V_64 ;
break;
case V_130 :
{
T_6 V_131 ;
struct V_132 * V_133 ;
struct V_134 T_3 * V_135 = V_116 ;
if ( F_42 ( V_131 , & ( V_135 -> V_136 ) ) )
return - V_64 ;
if ( V_131 >= V_8 -> V_129 )
return - V_14 ;
V_133 = & ( V_8 -> V_137 [ V_131 ] ) ;
if ( F_32 ( V_133 -> V_2 , & ( V_135 -> V_2 ) )
|| F_32 ( V_133 -> V_138 , & ( V_135 -> V_138 ) )
|| F_32 ( V_133 -> V_139 , & ( V_135 -> V_139 ) ) )
return - V_64 ;
break;
}
case V_140 :
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . type = V_8 -> type ;
V_123 . V_39 = V_8 -> V_39 ;
V_123 . V_13 = V_8 -> V_13 ;
V_123 . V_138 = V_8 -> V_138 ;
V_123 . V_86 = V_8 -> V_86 ;
V_123 . V_88 = V_8 -> V_88 ;
V_123 . V_141 = 0 ;
if ( F_21 ( V_116 , & V_123 , sizeof( struct V_122 ) ) )
return - V_64 ;
break;
case V_142 :
case V_143 :
{
struct V_72 * V_144 ;
if( ! ( V_1 -> V_20 & V_21 ) )
return - V_83 ;
V_144 = F_13 ( sizeof( struct V_72 ) , V_41 ) ;
if ( ! V_144 )
V_18 = - V_29 ;
else {
V_74 V_145 ;
F_43 ( V_146 , V_147 ) ;
F_44 ( & V_145 ) ;
if ( V_121 == V_143 ) {
struct V_148 V_149 ;
if ( F_23 ( & V_149 , V_116 ,
sizeof( struct V_148 ) ) ) {
F_16 ( V_144 ) ;
return - V_64 ;
}
V_144 -> V_150 = V_149 . V_79 ;
V_144 -> V_49 = V_149 . V_80 ;
} else {
struct V_151 V_152 ;
if ( F_23 ( & V_152 , V_116 ,
sizeof( struct V_151 ) ) ) {
F_16 ( V_144 ) ;
return - V_64 ;
}
V_144 -> V_150 = V_152 . V_79 ;
V_144 -> V_49 = V_152 . V_80 ;
}
V_144 -> V_8 = V_8 ;
V_144 -> V_153 = F_24 ;
V_144 -> V_75 = ( unsigned long ) & V_145 ;
V_18 = V_8 -> V_144 ( V_8 , V_144 ) ;
if ( ! V_18 ) {
F_45 ( V_154 ) ;
F_46 ( & V_145 , & V_146 ) ;
if ( V_144 -> V_155 != V_156 &&
V_144 -> V_155 != V_157 )
F_47 () ;
F_48 ( & V_145 , & V_146 ) ;
F_45 ( V_158 ) ;
V_18 = ( V_144 -> V_155 == V_157 ) ? - V_159 : 0 ;
}
F_16 ( V_144 ) ;
}
break;
}
case V_160 :
{
struct V_161 V_44 ;
struct V_161 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_27 ( V_1 , V_8 , V_44 . V_79 , V_44 . V_80 ,
V_44 . V_81 , & V_162 -> V_80 ) ;
break;
}
case V_163 :
{
struct V_161 V_44 ;
struct V_161 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_30 ( V_1 , V_8 , V_44 . V_79 , V_44 . V_80 ,
V_44 . V_81 , & V_162 -> V_79 ) ;
break;
}
case V_164 :
{
struct V_165 V_44 ;
struct V_165 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_27 ( V_1 , V_8 , V_44 . V_79 , V_44 . V_80 ,
( void T_3 * ) ( V_120 ) V_44 . V_166 ,
& V_162 -> V_80 ) ;
break;
}
case V_167 :
{
struct V_165 V_44 ;
struct V_165 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_30 ( V_1 , V_8 , V_44 . V_79 , V_44 . V_80 ,
( void T_3 * ) ( V_120 ) V_44 . V_166 ,
& V_162 -> V_80 ) ;
break;
}
case V_168 :
{
V_18 = F_40 ( V_8 ,
(struct V_115 T_3 * ) V_104 ) ;
break;
}
case V_169 :
{
struct V_151 V_170 ;
if ( F_23 ( & V_170 , V_116 , sizeof( V_170 ) ) )
return - V_64 ;
if ( ! V_8 -> V_171 )
V_18 = - V_68 ;
else
V_18 = V_8 -> V_171 ( V_8 , V_170 . V_79 , V_170 . V_80 ) ;
break;
}
case V_172 :
{
struct V_151 V_170 ;
if ( F_23 ( & V_170 , V_116 , sizeof( V_170 ) ) )
return - V_64 ;
if ( ! V_8 -> V_173 )
V_18 = - V_68 ;
else
V_18 = V_8 -> V_173 ( V_8 , V_170 . V_79 , V_170 . V_80 ) ;
break;
}
case V_174 :
{
struct V_151 V_170 ;
if ( F_23 ( & V_170 , V_116 , sizeof( V_170 ) ) )
return - V_64 ;
if ( ! V_8 -> V_175 )
V_18 = - V_68 ;
else
V_18 = V_8 -> V_175 ( V_8 , V_170 . V_79 , V_170 . V_80 ) ;
break;
}
case V_176 :
{
struct V_177 V_178 ;
if ( ! V_8 -> V_179 )
return - V_68 ;
if ( V_8 -> V_179 -> V_97 > F_49 ( V_178 . V_99 ) )
return - V_14 ;
V_178 . V_180 = V_181 ;
memcpy ( & V_178 . V_99 , V_8 -> V_179 -> V_99 , sizeof( V_178 . V_99 ) ) ;
memcpy ( & V_178 . V_101 , V_8 -> V_179 -> V_101 ,
sizeof( V_178 . V_101 ) ) ;
V_178 . V_97 = V_8 -> V_179 -> V_97 ;
if ( F_21 ( V_116 , & V_178 , sizeof( struct V_177 ) ) )
return - V_64 ;
break;
}
case V_182 :
{
T_1 V_183 ;
if ( F_23 ( & V_183 , V_116 , sizeof( T_1 ) ) )
return - V_64 ;
if ( ! V_8 -> V_184 )
V_18 = - V_68 ;
else
return V_8 -> V_184 ( V_8 , V_183 ) ;
break;
}
case V_185 :
{
T_1 V_183 ;
if ( F_23 ( & V_183 , V_116 , sizeof( T_1 ) ) )
return - V_64 ;
if ( ! V_8 -> V_186 )
V_18 = - V_68 ;
else
return V_8 -> V_186 ( V_8 , V_183 ) ;
break;
}
#ifdef F_50
case V_187 :
{
int V_51 ;
if ( F_23 ( & V_51 , V_116 , sizeof( int ) ) )
return - V_64 ;
V_5 -> V_51 = V_188 ;
V_18 = F_26 ( V_5 , V_51 ) ;
V_1 -> V_11 = 0 ;
break;
}
case V_189 :
case V_190 :
{
struct V_191 * V_44 = F_31 ( 4096 , V_41 ) ;
if ( ! V_44 )
return - V_29 ;
V_18 = - V_68 ;
switch ( V_5 -> V_51 ) {
case V_52 :
if ( V_8 -> V_192 )
V_18 = V_8 -> V_192 ( V_8 , V_44 , 4096 ) ;
break;
case V_54 :
if ( V_8 -> V_193 )
V_18 = V_8 -> V_193 ( V_8 , V_44 , 4096 ) ;
break;
default:
break;
}
if ( V_18 >= 0 ) {
if ( V_121 == V_189 ) {
int V_194 = V_18 / sizeof( struct V_191 ) ;
V_18 = F_21 ( V_116 , & V_194 , sizeof( int ) ) ;
} else
V_18 = F_21 ( V_116 , V_44 , V_18 ) ;
if ( V_18 )
V_18 = - V_64 ;
}
F_16 ( V_44 ) ;
break;
}
case V_195 :
{
struct V_191 V_196 ;
if ( V_5 -> V_51 != V_54 )
return - V_14 ;
if ( F_23 ( & V_196 , V_116 , sizeof( V_196 ) ) )
return - V_64 ;
if ( ! V_8 -> V_197 )
return - V_68 ;
V_18 = V_8 -> V_197 ( V_8 , V_196 . V_79 , V_196 . V_80 ) ;
break;
}
#endif
case V_198 :
{
struct V_94 * V_199 ;
if ( ! V_8 -> V_179 )
return - V_68 ;
V_199 = F_31 ( sizeof( * V_199 ) , V_41 ) ;
if ( ! V_199 )
return - V_29 ;
F_33 ( V_8 -> V_179 , V_199 ) ;
if ( F_21 ( V_116 , V_199 , sizeof( * V_199 ) ) )
V_18 = - V_64 ;
F_16 ( V_199 ) ;
break;
}
case V_200 :
{
if ( F_21 ( V_116 , & V_8 -> V_201 ,
sizeof( struct V_202 ) ) )
return - V_64 ;
break;
}
case V_203 :
{
V_5 -> V_51 = 0 ;
switch( V_104 ) {
case V_52 :
case V_54 :
V_18 = F_26 ( V_5 , V_104 ) ;
break;
case V_56 :
if ( ! V_8 -> V_62 || ! V_8 -> V_70 )
return - V_68 ;
V_5 -> V_51 = V_104 ;
case V_188 :
break;
default:
V_18 = - V_14 ;
}
V_1 -> V_11 = 0 ;
break;
}
case V_204 :
{
V_18 = F_35 ( V_8 ,
(struct V_103 T_3 * ) V_104 ) ;
break;
}
case V_205 :
{
V_18 = 0 ;
break;
}
default:
V_18 = - V_206 ;
}
return V_18 ;
}
static long F_51 ( struct V_1 * V_1 , T_7 V_121 , T_8 V_104 )
{
int V_18 ;
F_5 ( & V_23 ) ;
V_18 = F_41 ( V_1 , V_121 , V_104 ) ;
F_14 ( & V_23 ) ;
return V_18 ;
}
static long F_52 ( struct V_1 * V_1 , unsigned int V_121 ,
unsigned long V_104 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_116 = F_53 ( V_104 ) ;
int V_18 = 0 ;
F_5 ( & V_23 ) ;
switch ( V_121 ) {
case V_207 :
{
struct V_208 V_44 ;
struct V_208 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_27 ( V_1 , V_8 , V_44 . V_79 ,
V_44 . V_80 , F_53 ( V_44 . V_81 ) ,
& V_162 -> V_80 ) ;
break;
}
case V_209 :
{
struct V_208 V_44 ;
struct V_208 T_3 * V_162 = V_116 ;
if ( F_23 ( & V_44 , V_116 , sizeof( V_44 ) ) )
V_18 = - V_64 ;
else
V_18 = F_30 ( V_1 , V_8 , V_44 . V_79 ,
V_44 . V_80 , F_53 ( V_44 . V_81 ) ,
& V_162 -> V_79 ) ;
break;
}
default:
V_18 = F_41 ( V_1 , V_121 , ( unsigned long ) V_116 ) ;
}
F_14 ( & V_23 ) ;
return V_18 ;
}
static unsigned long F_54 ( struct V_1 * V_1 ,
unsigned long V_150 ,
unsigned long V_49 ,
unsigned long V_210 ,
unsigned long V_39 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_8 -> V_211 ) {
unsigned long V_2 ;
if ( V_150 != 0 )
return ( unsigned long ) - V_14 ;
if ( V_49 > V_8 -> V_13 || V_210 >= ( V_8 -> V_13 >> V_212 ) )
return ( unsigned long ) - V_14 ;
V_2 = V_210 << V_212 ;
if ( V_2 > V_8 -> V_13 - V_49 )
return ( unsigned long ) - V_14 ;
return V_8 -> V_211 ( V_8 , V_49 , V_2 , V_39 ) ;
}
return ( unsigned long ) - V_213 ;
}
static int F_55 ( struct V_1 * V_1 , struct V_214 * V_215 )
{
#ifdef F_56
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_216 * V_217 = V_8 -> V_75 ;
unsigned long V_79 ;
unsigned long V_218 ;
T_9 V_49 ;
if ( V_8 -> type == V_219 || V_8 -> type == V_220 ) {
V_218 = V_215 -> V_221 << V_212 ;
V_79 = V_217 -> V_222 ;
V_49 = F_57 ( ( V_79 & ~ V_223 ) + V_217 -> V_13 ) ;
V_79 &= V_223 ;
if ( ( V_215 -> V_224 - V_215 -> V_225 + V_218 ) > V_49 )
return - V_14 ;
V_218 += V_79 ;
V_215 -> V_221 = V_218 >> V_212 ;
V_215 -> V_226 |= V_227 | V_228 ;
#ifdef F_58
if ( V_1 -> V_229 & V_230 || V_218 >= F_59 ( V_231 ) )
V_215 -> V_232 = F_58 ( V_215 -> V_232 ) ;
#endif
if ( F_60 ( V_215 , V_215 -> V_225 , V_218 >> V_212 ,
V_215 -> V_224 - V_215 -> V_225 ,
V_215 -> V_232 ) )
return - V_233 ;
return 0 ;
}
return - V_213 ;
#else
return V_215 -> V_226 & V_234 ? 0 : - V_213 ;
#endif
}
static struct V_235 * F_61 ( struct V_236 * V_237 ,
int V_39 , const char * V_238 , void * V_109 )
{
return F_62 ( V_237 , L_6 , NULL , NULL , V_239 ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_15 * V_19 = F_65 ( V_27 -> V_28 , V_8 -> V_240 ) ;
if ( V_19 ) {
F_66 ( V_19 ) ;
F_12 ( V_19 ) ;
}
}
static int T_10 F_67 ( void )
{
int V_18 ;
V_18 = F_68 ( V_241 , 0 , 1 << V_242 ,
L_7 , & V_243 ) ;
if ( V_18 < 0 ) {
F_69 ( L_8
L_9 , V_241 ) ;
return V_18 ;
}
V_18 = F_70 ( & V_244 ) ;
if ( V_18 ) {
F_69 ( L_10 , V_18 ) ;
goto V_245;
}
V_27 = F_71 ( & V_244 ) ;
if ( F_7 ( V_27 ) ) {
V_18 = F_8 ( V_27 ) ;
F_69 ( L_11 , V_18 ) ;
goto V_246;
}
F_72 ( & V_247 ) ;
return V_18 ;
V_246:
F_73 ( & V_244 ) ;
V_245:
F_74 ( V_241 , 0 , 1 << V_242 , L_7 ) ;
return V_18 ;
}
static void T_11 F_75 ( void )
{
F_76 ( & V_247 ) ;
F_77 ( V_27 ) ;
F_73 ( & V_244 ) ;
F_74 ( V_241 , 0 , 1 << V_242 , L_7 ) ;
}
