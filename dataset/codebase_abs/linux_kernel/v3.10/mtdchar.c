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
V_18 = F_5 ( & V_23 , & V_24 , & V_25 ) ;
if ( V_18 )
return V_18 ;
F_6 ( & V_26 ) ;
V_8 = F_7 ( NULL , V_17 ) ;
if ( F_8 ( V_8 ) ) {
V_18 = F_9 ( V_8 ) ;
goto V_27;
}
if ( V_8 -> type == V_28 ) {
V_18 = - V_29 ;
goto V_30;
}
V_19 = F_10 ( V_24 -> V_31 , V_17 ) ;
if ( ! V_19 ) {
V_18 = - V_32 ;
goto V_30;
}
if ( V_19 -> V_33 & V_34 ) {
V_19 -> V_35 = V_8 ;
V_19 -> V_36 = V_37 ;
V_19 -> V_38 . V_39 = V_8 -> V_39 ;
F_11 ( V_19 ) ;
}
V_1 -> V_40 = V_19 -> V_41 ;
if ( ( V_1 -> V_20 & V_21 ) && ! ( V_8 -> V_42 & V_43 ) ) {
V_18 = - V_22 ;
goto V_44;
}
V_5 = F_12 ( sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 ) {
V_18 = - V_32 ;
goto V_44;
}
V_5 -> V_46 = V_19 ;
V_5 -> V_8 = V_8 ;
V_1 -> V_6 = V_5 ;
F_13 ( & V_26 ) ;
return 0 ;
V_44:
F_14 ( V_19 ) ;
V_30:
F_15 ( V_8 ) ;
V_27:
F_13 ( & V_26 ) ;
F_16 ( & V_24 , & V_25 ) ;
return V_18 ;
}
static int F_17 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_4 ( L_2 ) ;
if ( ( V_1 -> V_20 & V_21 ) )
F_18 ( V_8 ) ;
F_14 ( V_5 -> V_46 ) ;
F_15 ( V_8 ) ;
V_1 -> V_6 = NULL ;
F_19 ( V_5 ) ;
F_16 ( & V_24 , & V_25 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_1 * V_1 , char T_3 * V_47 , T_4 V_25 ,
T_1 * V_48 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_49 ;
T_4 V_50 = 0 ;
int V_18 = 0 ;
int V_51 ;
T_4 V_13 = V_25 ;
char * V_52 ;
F_4 ( L_3 ) ;
if ( * V_48 + V_25 > V_8 -> V_13 )
V_25 = V_8 -> V_13 - * V_48 ;
if ( ! V_25 )
return 0 ;
V_52 = F_21 ( V_8 , & V_13 ) ;
if ( ! V_52 )
return - V_32 ;
while ( V_25 ) {
V_51 = F_22 ( T_4 , V_25 , V_13 ) ;
switch ( V_5 -> V_53 ) {
case V_54 :
V_18 = F_23 ( V_8 , * V_48 , V_51 ,
& V_49 , V_52 ) ;
break;
case V_55 :
V_18 = F_24 ( V_8 , * V_48 , V_51 ,
& V_49 , V_52 ) ;
break;
case V_56 :
{
struct V_57 V_58 ;
V_58 . V_53 = V_59 ;
V_58 . V_60 = V_52 ;
V_58 . V_61 = NULL ;
V_58 . V_51 = V_51 ;
V_18 = F_25 ( V_8 , * V_48 , & V_58 ) ;
V_49 = V_58 . V_49 ;
break;
}
default:
V_18 = F_26 ( V_8 , * V_48 , V_51 , & V_49 , V_52 ) ;
}
if ( ! V_18 || F_27 ( V_18 ) ) {
* V_48 += V_49 ;
if ( F_28 ( V_47 , V_52 , V_49 ) ) {
F_19 ( V_52 ) ;
return - V_62 ;
}
else
V_50 += V_49 ;
V_25 -= V_49 ;
V_47 += V_49 ;
if ( V_49 == 0 )
V_25 = 0 ;
}
else {
F_19 ( V_52 ) ;
return V_18 ;
}
}
F_19 ( V_52 ) ;
return V_50 ;
}
static T_2 F_29 ( struct V_1 * V_1 , const char T_3 * V_47 , T_4 V_25 ,
T_1 * V_48 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_13 = V_25 ;
char * V_52 ;
T_4 V_49 ;
T_4 V_50 = 0 ;
int V_18 = 0 ;
int V_51 ;
F_4 ( L_4 ) ;
if ( * V_48 == V_8 -> V_13 )
return - V_63 ;
if ( * V_48 + V_25 > V_8 -> V_13 )
V_25 = V_8 -> V_13 - * V_48 ;
if ( ! V_25 )
return 0 ;
V_52 = F_21 ( V_8 , & V_13 ) ;
if ( ! V_52 )
return - V_32 ;
while ( V_25 ) {
V_51 = F_22 ( T_4 , V_25 , V_13 ) ;
if ( F_30 ( V_52 , V_47 , V_51 ) ) {
F_19 ( V_52 ) ;
return - V_62 ;
}
switch ( V_5 -> V_53 ) {
case V_54 :
V_18 = - V_64 ;
break;
case V_55 :
V_18 = F_31 ( V_8 , * V_48 , V_51 ,
& V_49 , V_52 ) ;
break;
case V_56 :
{
struct V_57 V_58 ;
V_58 . V_53 = V_59 ;
V_58 . V_60 = V_52 ;
V_58 . V_61 = NULL ;
V_58 . V_65 = 0 ;
V_58 . V_51 = V_51 ;
V_18 = F_32 ( V_8 , * V_48 , & V_58 ) ;
V_49 = V_58 . V_49 ;
break;
}
default:
V_18 = F_33 ( V_8 , * V_48 , V_51 , & V_49 , V_52 ) ;
}
if ( ! V_18 ) {
* V_48 += V_49 ;
V_50 += V_49 ;
V_25 -= V_49 ;
V_47 += V_49 ;
}
else {
F_19 ( V_52 ) ;
return V_18 ;
}
}
F_19 ( V_52 ) ;
return V_50 ;
}
static void F_34 ( struct V_66 * V_67 )
{
F_35 ( ( V_68 * ) V_67 -> V_69 ) ;
}
static int F_36 ( struct V_4 * V_5 , int V_53 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_49 ;
switch ( V_53 ) {
case V_70 :
if ( F_23 ( V_8 , - 1 , 0 , & V_49 , NULL ) ==
- V_71 )
return - V_71 ;
V_5 -> V_53 = V_54 ;
break;
case V_72 :
if ( F_24 ( V_8 , - 1 , 0 , & V_49 , NULL ) ==
- V_71 )
return - V_71 ;
V_5 -> V_53 = V_55 ;
break;
case V_73 :
V_5 -> V_53 = V_74 ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_75 , T_6 V_76 , void T_3 * V_77 ,
T_6 T_3 * V_78 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_57 V_58 ;
T_6 V_49 ;
int V_18 = 0 ;
if ( ! ( V_1 -> V_20 & V_21 ) )
return - V_79 ;
if ( V_76 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_80 )
V_18 = - V_71 ;
else
V_18 = F_38 ( V_81 , V_77 , V_76 ) ? 0 : - V_62 ;
if ( V_18 )
return V_18 ;
V_58 . V_82 = V_76 ;
V_58 . V_65 = V_75 & ( V_8 -> V_83 - 1 ) ;
V_58 . V_60 = NULL ;
V_58 . V_53 = ( V_5 -> V_53 == V_56 ) ? V_59 :
V_84 ;
if ( V_58 . V_65 && V_58 . V_82 > ( V_8 -> V_85 - V_58 . V_65 ) )
return - V_14 ;
V_58 . V_61 = F_39 ( V_77 , V_76 ) ;
if ( F_8 ( V_58 . V_61 ) )
return F_9 ( V_58 . V_61 ) ;
V_75 &= ~ ( ( T_5 ) V_8 -> V_83 - 1 ) ;
V_18 = F_32 ( V_8 , V_75 , & V_58 ) ;
if ( V_58 . V_86 > 0xFFFFFFFFU )
V_18 = - V_87 ;
V_49 = V_58 . V_86 ;
if ( F_28 ( V_78 , & V_49 , sizeof( V_76 ) ) )
V_18 = - V_62 ;
F_19 ( V_58 . V_61 ) ;
return V_18 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_75 , T_6 V_76 , void T_3 * V_77 ,
T_6 T_3 * V_78 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_57 V_58 ;
int V_18 = 0 ;
if ( V_76 > 4096 )
return - V_14 ;
if ( ! F_38 ( V_88 , V_77 , V_76 ) )
return - V_62 ;
V_58 . V_82 = V_76 ;
V_58 . V_65 = V_75 & ( V_8 -> V_83 - 1 ) ;
V_58 . V_60 = NULL ;
V_58 . V_53 = ( V_5 -> V_53 == V_56 ) ? V_59 :
V_84 ;
if ( V_58 . V_65 && V_58 . V_82 > ( V_8 -> V_85 - V_58 . V_65 ) )
return - V_14 ;
V_58 . V_61 = F_41 ( V_76 , V_45 ) ;
if ( ! V_58 . V_61 )
return - V_32 ;
V_75 &= ~ ( ( T_5 ) V_8 -> V_83 - 1 ) ;
V_18 = F_25 ( V_8 , V_75 , & V_58 ) ;
if ( F_42 ( V_58 . V_86 , V_78 ) )
V_18 = - V_62 ;
else if ( V_58 . V_86 && F_28 ( V_77 , V_58 . V_61 ,
V_58 . V_86 ) )
V_18 = - V_62 ;
F_19 ( V_58 . V_61 ) ;
if ( F_27 ( V_18 ) )
return 0 ;
return V_18 ;
}
static int F_43 ( const struct V_89 * V_90 ,
struct V_91 * V_92 )
{
int V_93 ;
if ( ! V_90 || ! V_92 )
return - V_14 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_94 = F_44 ( ( int ) V_90 -> V_94 , V_95 ) ;
for ( V_93 = 0 ; V_93 < V_92 -> V_94 ; V_93 ++ )
V_92 -> V_96 [ V_93 ] = V_90 -> V_96 [ V_93 ] ;
for ( V_93 = 0 ; V_93 < V_97 ; V_93 ++ ) {
if ( V_90 -> V_98 [ V_93 ] . V_76 == 0 &&
V_90 -> V_98 [ V_93 ] . V_2 == 0 )
break;
V_92 -> V_99 += V_90 -> V_98 [ V_93 ] . V_76 ;
V_92 -> V_98 [ V_93 ] = V_90 -> V_98 [ V_93 ] ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
struct V_100 T_3 * V_101 )
{
struct V_100 V_102 ;
struct V_103 V_104 ;
if ( ! F_46 ( V_105 ) )
return - V_79 ;
if ( F_30 ( & V_102 , V_101 , sizeof( struct V_100 ) ) )
return - V_62 ;
if ( F_30 ( & V_104 , V_102 . V_106 , sizeof( struct V_103 ) ) )
return - V_62 ;
switch ( V_102 . V_107 ) {
case V_108 :
if ( F_47 ( V_8 ) )
return - V_14 ;
return F_48 ( V_8 , V_104 . V_109 , V_104 . V_75 , V_104 . V_76 ) ;
case V_110 :
if ( V_104 . V_111 < 0 )
return - V_14 ;
return F_49 ( V_8 , V_104 . V_111 ) ;
default:
return - V_14 ;
}
}
static int F_50 ( struct V_7 * V_8 ,
struct V_112 T_3 * V_113 )
{
struct V_112 V_114 ;
struct V_57 V_58 ;
void T_3 * V_115 , * V_116 ;
int V_18 ;
if ( F_30 ( & V_114 , V_113 , sizeof( V_114 ) ) ||
! F_38 ( V_81 , V_114 . V_115 , V_114 . V_51 ) ||
! F_38 ( V_81 , V_114 . V_116 , V_114 . V_82 ) )
return - V_62 ;
if ( ! V_8 -> V_80 )
return - V_71 ;
V_58 . V_53 = V_114 . V_53 ;
V_58 . V_51 = ( T_4 ) V_114 . V_51 ;
V_58 . V_82 = ( T_4 ) V_114 . V_82 ;
V_58 . V_65 = 0 ;
V_115 = ( void T_3 * ) ( V_117 ) V_114 . V_115 ;
V_116 = ( void T_3 * ) ( V_117 ) V_114 . V_116 ;
if ( V_114 . V_115 ) {
V_58 . V_60 = F_39 ( V_115 , V_58 . V_51 ) ;
if ( F_8 ( V_58 . V_60 ) )
return F_9 ( V_58 . V_60 ) ;
} else {
V_58 . V_60 = NULL ;
}
if ( V_114 . V_116 ) {
V_58 . V_61 = F_39 ( V_116 , V_58 . V_82 ) ;
if ( F_8 ( V_58 . V_61 ) ) {
F_19 ( V_58 . V_60 ) ;
return F_9 ( V_58 . V_61 ) ;
}
} else {
V_58 . V_61 = NULL ;
}
V_18 = F_32 ( V_8 , ( T_1 ) V_114 . V_75 , & V_58 ) ;
F_19 ( V_58 . V_60 ) ;
F_19 ( V_58 . V_61 ) ;
return V_18 ;
}
static int F_51 ( struct V_1 * V_1 , T_7 V_118 , T_8 V_101 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_113 = ( void T_3 * ) V_101 ;
int V_18 = 0 ;
T_8 V_13 ;
struct V_119 V_120 ;
F_4 ( L_5 ) ;
V_13 = ( V_118 & V_121 ) >> V_122 ;
if ( V_118 & V_123 ) {
if ( ! F_38 ( V_81 , V_113 , V_13 ) )
return - V_62 ;
}
if ( V_118 & V_124 ) {
if ( ! F_38 ( V_88 , V_113 , V_13 ) )
return - V_62 ;
}
switch ( V_118 ) {
case V_125 :
if ( F_28 ( V_113 , & ( V_8 -> V_126 ) , sizeof( int ) ) )
return - V_62 ;
break;
case V_127 :
{
T_6 V_128 ;
struct V_129 * V_130 ;
struct V_131 T_3 * V_132 = V_113 ;
if ( F_52 ( V_128 , & ( V_132 -> V_133 ) ) )
return - V_62 ;
if ( V_128 >= V_8 -> V_126 )
return - V_14 ;
V_130 = & ( V_8 -> V_134 [ V_128 ] ) ;
if ( F_42 ( V_130 -> V_2 , & ( V_132 -> V_2 ) )
|| F_42 ( V_130 -> V_135 , & ( V_132 -> V_135 ) )
|| F_42 ( V_130 -> V_136 , & ( V_132 -> V_136 ) ) )
return - V_62 ;
break;
}
case V_137 :
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . type = V_8 -> type ;
V_120 . V_42 = V_8 -> V_42 ;
V_120 . V_13 = V_8 -> V_13 ;
V_120 . V_135 = V_8 -> V_135 ;
V_120 . V_83 = V_8 -> V_83 ;
V_120 . V_85 = V_8 -> V_85 ;
V_120 . V_138 = 0 ;
if ( F_28 ( V_113 , & V_120 , sizeof( struct V_119 ) ) )
return - V_62 ;
break;
case V_139 :
case V_140 :
{
struct V_66 * V_141 ;
if( ! ( V_1 -> V_20 & V_21 ) )
return - V_79 ;
V_141 = F_12 ( sizeof( struct V_66 ) , V_45 ) ;
if ( ! V_141 )
V_18 = - V_32 ;
else {
V_68 V_142 ;
F_53 ( V_143 , V_144 ) ;
F_54 ( & V_142 ) ;
if ( V_118 == V_140 ) {
struct V_145 V_146 ;
if ( F_30 ( & V_146 , V_113 ,
sizeof( struct V_145 ) ) ) {
F_19 ( V_141 ) ;
return - V_62 ;
}
V_141 -> V_147 = V_146 . V_75 ;
V_141 -> V_51 = V_146 . V_76 ;
} else {
struct V_148 V_149 ;
if ( F_30 ( & V_149 , V_113 ,
sizeof( struct V_148 ) ) ) {
F_19 ( V_141 ) ;
return - V_62 ;
}
V_141 -> V_147 = V_149 . V_75 ;
V_141 -> V_51 = V_149 . V_76 ;
}
V_141 -> V_8 = V_8 ;
V_141 -> V_150 = F_34 ;
V_141 -> V_69 = ( unsigned long ) & V_142 ;
V_18 = F_55 ( V_8 , V_141 ) ;
if ( ! V_18 ) {
F_56 ( V_151 ) ;
F_57 ( & V_142 , & V_143 ) ;
if ( V_141 -> V_152 != V_153 &&
V_141 -> V_152 != V_154 )
F_58 () ;
F_59 ( & V_142 , & V_143 ) ;
F_56 ( V_155 ) ;
V_18 = ( V_141 -> V_152 == V_154 ) ? - V_156 : 0 ;
}
F_19 ( V_141 ) ;
}
break;
}
case V_157 :
{
struct V_158 V_47 ;
struct V_158 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_37 ( V_1 , V_8 , V_47 . V_75 , V_47 . V_76 ,
V_47 . V_77 , & V_159 -> V_76 ) ;
break;
}
case V_160 :
{
struct V_158 V_47 ;
struct V_158 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_40 ( V_1 , V_8 , V_47 . V_75 , V_47 . V_76 ,
V_47 . V_77 , & V_159 -> V_75 ) ;
break;
}
case V_161 :
{
struct V_162 V_47 ;
struct V_162 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_37 ( V_1 , V_8 , V_47 . V_75 , V_47 . V_76 ,
( void T_3 * ) ( V_117 ) V_47 . V_163 ,
& V_159 -> V_76 ) ;
break;
}
case V_164 :
{
struct V_162 V_47 ;
struct V_162 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_40 ( V_1 , V_8 , V_47 . V_75 , V_47 . V_76 ,
( void T_3 * ) ( V_117 ) V_47 . V_163 ,
& V_159 -> V_76 ) ;
break;
}
case V_165 :
{
V_18 = F_50 ( V_8 ,
(struct V_112 T_3 * ) V_101 ) ;
break;
}
case V_166 :
{
struct V_148 V_167 ;
if ( F_30 ( & V_167 , V_113 , sizeof( V_167 ) ) )
return - V_62 ;
V_18 = F_60 ( V_8 , V_167 . V_75 , V_167 . V_76 ) ;
break;
}
case V_168 :
{
struct V_148 V_167 ;
if ( F_30 ( & V_167 , V_113 , sizeof( V_167 ) ) )
return - V_62 ;
V_18 = F_61 ( V_8 , V_167 . V_75 , V_167 . V_76 ) ;
break;
}
case V_169 :
{
struct V_148 V_167 ;
if ( F_30 ( & V_167 , V_113 , sizeof( V_167 ) ) )
return - V_62 ;
V_18 = F_62 ( V_8 , V_167 . V_75 , V_167 . V_76 ) ;
break;
}
case V_170 :
{
struct V_171 V_172 ;
if ( ! V_8 -> V_173 )
return - V_71 ;
if ( V_8 -> V_173 -> V_94 > F_63 ( V_172 . V_96 ) )
return - V_14 ;
V_172 . V_174 = V_175 ;
memcpy ( & V_172 . V_96 , V_8 -> V_173 -> V_96 , sizeof( V_172 . V_96 ) ) ;
memcpy ( & V_172 . V_98 , V_8 -> V_173 -> V_98 ,
sizeof( V_172 . V_98 ) ) ;
V_172 . V_94 = V_8 -> V_173 -> V_94 ;
if ( F_28 ( V_113 , & V_172 , sizeof( struct V_171 ) ) )
return - V_62 ;
break;
}
case V_176 :
{
T_1 V_177 ;
if ( F_30 ( & V_177 , V_113 , sizeof( T_1 ) ) )
return - V_62 ;
return F_64 ( V_8 , V_177 ) ;
break;
}
case V_178 :
{
T_1 V_177 ;
if ( F_30 ( & V_177 , V_113 , sizeof( T_1 ) ) )
return - V_62 ;
return F_65 ( V_8 , V_177 ) ;
break;
}
case V_179 :
{
int V_53 ;
if ( F_30 ( & V_53 , V_113 , sizeof( int ) ) )
return - V_62 ;
V_5 -> V_53 = V_74 ;
V_18 = F_36 ( V_5 , V_53 ) ;
V_1 -> V_11 = 0 ;
break;
}
case V_180 :
case V_181 :
{
struct V_182 * V_47 = F_41 ( 4096 , V_45 ) ;
if ( ! V_47 )
return - V_32 ;
switch ( V_5 -> V_53 ) {
case V_54 :
V_18 = F_66 ( V_8 , V_47 , 4096 ) ;
break;
case V_55 :
V_18 = F_67 ( V_8 , V_47 , 4096 ) ;
break;
default:
V_18 = - V_14 ;
break;
}
if ( V_18 >= 0 ) {
if ( V_118 == V_180 ) {
int V_183 = V_18 / sizeof( struct V_182 ) ;
V_18 = F_28 ( V_113 , & V_183 , sizeof( int ) ) ;
} else
V_18 = F_28 ( V_113 , V_47 , V_18 ) ;
if ( V_18 )
V_18 = - V_62 ;
}
F_19 ( V_47 ) ;
break;
}
case V_184 :
{
struct V_182 V_185 ;
if ( V_5 -> V_53 != V_55 )
return - V_14 ;
if ( F_30 ( & V_185 , V_113 , sizeof( V_185 ) ) )
return - V_62 ;
V_18 = F_68 ( V_8 , V_185 . V_75 , V_185 . V_76 ) ;
break;
}
case V_186 :
{
struct V_91 * V_187 ;
if ( ! V_8 -> V_173 )
return - V_71 ;
V_187 = F_41 ( sizeof( * V_187 ) , V_45 ) ;
if ( ! V_187 )
return - V_32 ;
F_43 ( V_8 -> V_173 , V_187 ) ;
if ( F_28 ( V_113 , V_187 , sizeof( * V_187 ) ) )
V_18 = - V_62 ;
F_19 ( V_187 ) ;
break;
}
case V_188 :
{
if ( F_28 ( V_113 , & V_8 -> V_189 ,
sizeof( struct V_190 ) ) )
return - V_62 ;
break;
}
case V_191 :
{
V_5 -> V_53 = 0 ;
switch( V_101 ) {
case V_54 :
case V_55 :
V_18 = F_36 ( V_5 , V_101 ) ;
break;
case V_56 :
if ( ! F_69 ( V_8 ) )
return - V_71 ;
V_5 -> V_53 = V_101 ;
case V_74 :
break;
default:
V_18 = - V_14 ;
}
V_1 -> V_11 = 0 ;
break;
}
case V_192 :
{
V_18 = F_45 ( V_8 ,
(struct V_100 T_3 * ) V_101 ) ;
break;
}
case V_193 :
{
V_18 = 0 ;
break;
}
default:
V_18 = - V_194 ;
}
return V_18 ;
}
static long F_70 ( struct V_1 * V_1 , T_7 V_118 , T_8 V_101 )
{
int V_18 ;
F_6 ( & V_26 ) ;
V_18 = F_51 ( V_1 , V_118 , V_101 ) ;
F_13 ( & V_26 ) ;
return V_18 ;
}
static long F_71 ( struct V_1 * V_1 , unsigned int V_118 ,
unsigned long V_101 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_113 = F_72 ( V_101 ) ;
int V_18 = 0 ;
F_6 ( & V_26 ) ;
switch ( V_118 ) {
case V_195 :
{
struct V_196 V_47 ;
struct V_196 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_37 ( V_1 , V_8 , V_47 . V_75 ,
V_47 . V_76 , F_72 ( V_47 . V_77 ) ,
& V_159 -> V_76 ) ;
break;
}
case V_197 :
{
struct V_196 V_47 ;
struct V_196 T_3 * V_159 = V_113 ;
if ( F_30 ( & V_47 , V_113 , sizeof( V_47 ) ) )
V_18 = - V_62 ;
else
V_18 = F_40 ( V_1 , V_8 , V_47 . V_75 ,
V_47 . V_76 , F_72 ( V_47 . V_77 ) ,
& V_159 -> V_75 ) ;
break;
}
default:
V_18 = F_51 ( V_1 , V_118 , ( unsigned long ) V_113 ) ;
}
F_13 ( & V_26 ) ;
return V_18 ;
}
static unsigned long F_73 ( struct V_1 * V_1 ,
unsigned long V_147 ,
unsigned long V_51 ,
unsigned long V_198 ,
unsigned long V_42 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
unsigned long V_2 ;
int V_18 ;
if ( V_147 != 0 )
return ( unsigned long ) - V_14 ;
if ( V_51 > V_8 -> V_13 || V_198 >= ( V_8 -> V_13 >> V_199 ) )
return ( unsigned long ) - V_14 ;
V_2 = V_198 << V_199 ;
if ( V_2 > V_8 -> V_13 - V_51 )
return ( unsigned long ) - V_14 ;
V_18 = F_74 ( V_8 , V_51 , V_2 , V_42 ) ;
return V_18 == - V_71 ? - V_200 : V_18 ;
}
static int F_75 ( struct V_1 * V_1 , struct V_201 * V_202 )
{
#ifdef F_76
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_203 * V_204 = V_8 -> V_69 ;
if ( 0 ) {
#ifdef F_77
if ( V_1 -> V_205 & V_206 || V_204 -> V_207 >= F_78 ( V_208 ) )
V_202 -> V_209 = F_77 ( V_202 -> V_209 ) ;
#endif
return F_79 ( V_202 , V_204 -> V_207 , V_204 -> V_13 ) ;
}
return - V_200 ;
#else
return V_202 -> V_210 & V_211 ? 0 : - V_200 ;
#endif
}
static struct V_212 * F_80 ( struct V_213 * V_214 ,
int V_42 , const char * V_215 , void * V_106 )
{
return F_81 ( V_214 , L_6 , & V_216 , NULL , V_217 ) ;
}
int T_9 F_82 ( void )
{
int V_18 ;
V_18 = F_83 ( V_218 , 0 , 1 << V_219 ,
L_7 , & V_220 ) ;
if ( V_18 < 0 ) {
F_84 ( L_8 ,
V_218 ) ;
return V_18 ;
}
V_18 = F_85 ( & V_23 ) ;
if ( V_18 ) {
F_84 ( L_9 ,
V_18 ) ;
goto V_221;
}
return V_18 ;
V_221:
F_86 ( V_218 , 0 , 1 << V_219 , L_7 ) ;
return V_18 ;
}
void T_10 F_87 ( void )
{
F_88 ( & V_23 ) ;
F_86 ( V_218 , 0 , 1 << V_219 , L_7 ) ;
}
