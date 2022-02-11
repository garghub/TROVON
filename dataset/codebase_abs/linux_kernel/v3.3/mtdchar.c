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
if ( ( V_1 -> V_20 & V_21 ) )
F_16 ( V_8 ) ;
F_12 ( V_5 -> V_42 ) ;
F_9 ( V_8 ) ;
V_1 -> V_6 = NULL ;
F_17 ( V_5 ) ;
return 0 ;
}
static T_2 F_18 ( struct V_1 * V_1 , char T_3 * V_43 , T_4 V_44 ,
T_1 * V_45 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_46 ;
T_4 V_47 = 0 ;
int V_18 = 0 ;
int V_48 ;
T_4 V_13 = V_44 ;
char * V_49 ;
F_4 ( L_3 ) ;
if ( * V_45 + V_44 > V_8 -> V_13 )
V_44 = V_8 -> V_13 - * V_45 ;
if ( ! V_44 )
return 0 ;
V_49 = F_19 ( V_8 , & V_13 ) ;
if ( ! V_49 )
return - V_29 ;
while ( V_44 ) {
V_48 = F_20 ( T_4 , V_44 , V_13 ) ;
switch ( V_5 -> V_50 ) {
case V_51 :
V_18 = F_21 ( V_8 , * V_45 , V_48 ,
& V_46 , V_49 ) ;
break;
case V_52 :
V_18 = F_22 ( V_8 , * V_45 , V_48 ,
& V_46 , V_49 ) ;
break;
case V_53 :
{
struct V_54 V_55 ;
V_55 . V_50 = V_56 ;
V_55 . V_57 = V_49 ;
V_55 . V_58 = NULL ;
V_55 . V_48 = V_48 ;
V_18 = F_23 ( V_8 , * V_45 , & V_55 ) ;
V_46 = V_55 . V_46 ;
break;
}
default:
V_18 = F_24 ( V_8 , * V_45 , V_48 , & V_46 , V_49 ) ;
}
if ( ! V_18 || F_25 ( V_18 ) ) {
* V_45 += V_46 ;
if ( F_26 ( V_43 , V_49 , V_46 ) ) {
F_17 ( V_49 ) ;
return - V_59 ;
}
else
V_47 += V_46 ;
V_44 -= V_46 ;
V_43 += V_46 ;
if ( V_46 == 0 )
V_44 = 0 ;
}
else {
F_17 ( V_49 ) ;
return V_18 ;
}
}
F_17 ( V_49 ) ;
return V_47 ;
}
static T_2 F_27 ( struct V_1 * V_1 , const char T_3 * V_43 , T_4 V_44 ,
T_1 * V_45 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_13 = V_44 ;
char * V_49 ;
T_4 V_46 ;
T_4 V_47 = 0 ;
int V_18 = 0 ;
int V_48 ;
F_4 ( L_4 ) ;
if ( * V_45 == V_8 -> V_13 )
return - V_60 ;
if ( * V_45 + V_44 > V_8 -> V_13 )
V_44 = V_8 -> V_13 - * V_45 ;
if ( ! V_44 )
return 0 ;
V_49 = F_19 ( V_8 , & V_13 ) ;
if ( ! V_49 )
return - V_29 ;
while ( V_44 ) {
V_48 = F_20 ( T_4 , V_44 , V_13 ) ;
if ( F_28 ( V_49 , V_43 , V_48 ) ) {
F_17 ( V_49 ) ;
return - V_59 ;
}
switch ( V_5 -> V_50 ) {
case V_51 :
V_18 = - V_61 ;
break;
case V_52 :
V_18 = F_29 ( V_8 , * V_45 , V_48 ,
& V_46 , V_49 ) ;
break;
case V_53 :
{
struct V_54 V_55 ;
V_55 . V_50 = V_56 ;
V_55 . V_57 = V_49 ;
V_55 . V_58 = NULL ;
V_55 . V_62 = 0 ;
V_55 . V_48 = V_48 ;
V_18 = F_30 ( V_8 , * V_45 , & V_55 ) ;
V_46 = V_55 . V_46 ;
break;
}
default:
V_18 = F_31 ( V_8 , * V_45 , V_48 , & V_46 , V_49 ) ;
}
if ( ! V_18 ) {
* V_45 += V_46 ;
V_47 += V_46 ;
V_44 -= V_46 ;
V_43 += V_46 ;
}
else {
F_17 ( V_49 ) ;
return V_18 ;
}
}
F_17 ( V_49 ) ;
return V_47 ;
}
static void F_32 ( struct V_63 * V_64 )
{
F_33 ( ( V_65 * ) V_64 -> V_66 ) ;
}
static int F_34 ( struct V_4 * V_5 , int V_50 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_46 ;
int V_18 = 0 ;
if ( F_21 ( V_8 , - 1 , - 1 , & V_46 , NULL ) == - V_67 )
return - V_67 ;
switch ( V_50 ) {
case V_68 :
V_5 -> V_50 = V_51 ;
break;
case V_69 :
V_5 -> V_50 = V_52 ;
break;
default:
V_18 = - V_14 ;
case V_70 :
break;
}
return V_18 ;
}
static int F_35 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_71 , T_6 V_72 , void T_3 * V_73 ,
T_6 T_3 * V_74 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_54 V_55 ;
T_6 V_46 ;
int V_18 = 0 ;
if ( ! ( V_1 -> V_20 & V_21 ) )
return - V_75 ;
if ( V_72 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_76 )
V_18 = - V_67 ;
else
V_18 = F_36 ( V_77 , V_73 , V_72 ) ? 0 : - V_59 ;
if ( V_18 )
return V_18 ;
V_55 . V_78 = V_72 ;
V_55 . V_62 = V_71 & ( V_8 -> V_79 - 1 ) ;
V_55 . V_57 = NULL ;
V_55 . V_50 = ( V_5 -> V_50 == V_53 ) ? V_56 :
V_80 ;
if ( V_55 . V_62 && V_55 . V_78 > ( V_8 -> V_81 - V_55 . V_62 ) )
return - V_14 ;
V_55 . V_58 = F_37 ( V_73 , V_72 ) ;
if ( F_7 ( V_55 . V_58 ) )
return F_8 ( V_55 . V_58 ) ;
V_71 &= ~ ( ( T_5 ) V_8 -> V_79 - 1 ) ;
V_18 = F_30 ( V_8 , V_71 , & V_55 ) ;
if ( V_55 . V_82 > 0xFFFFFFFFU )
V_18 = - V_83 ;
V_46 = V_55 . V_82 ;
if ( F_26 ( V_74 , & V_46 , sizeof( V_72 ) ) )
V_18 = - V_59 ;
F_17 ( V_55 . V_58 ) ;
return V_18 ;
}
static int F_38 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_71 , T_6 V_72 , void T_3 * V_73 ,
T_6 T_3 * V_74 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_54 V_55 ;
int V_18 = 0 ;
if ( V_72 > 4096 )
return - V_14 ;
if ( ! F_36 ( V_84 , V_73 , V_72 ) )
return - V_59 ;
V_55 . V_78 = V_72 ;
V_55 . V_62 = V_71 & ( V_8 -> V_79 - 1 ) ;
V_55 . V_57 = NULL ;
V_55 . V_50 = ( V_5 -> V_50 == V_53 ) ? V_56 :
V_80 ;
if ( V_55 . V_62 && V_55 . V_78 > ( V_8 -> V_81 - V_55 . V_62 ) )
return - V_14 ;
V_55 . V_58 = F_39 ( V_72 , V_41 ) ;
if ( ! V_55 . V_58 )
return - V_29 ;
V_71 &= ~ ( ( T_5 ) V_8 -> V_79 - 1 ) ;
V_18 = F_23 ( V_8 , V_71 , & V_55 ) ;
if ( F_40 ( V_55 . V_82 , V_74 ) )
V_18 = - V_59 ;
else if ( V_55 . V_82 && F_26 ( V_73 , V_55 . V_58 ,
V_55 . V_82 ) )
V_18 = - V_59 ;
F_17 ( V_55 . V_58 ) ;
if ( F_25 ( V_18 ) )
return 0 ;
return V_18 ;
}
static int F_41 ( const struct V_85 * V_86 ,
struct V_87 * V_88 )
{
int V_89 ;
if ( ! V_86 || ! V_88 )
return - V_14 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_90 = F_42 ( ( int ) V_86 -> V_90 , V_91 ) ;
for ( V_89 = 0 ; V_89 < V_88 -> V_90 ; V_89 ++ )
V_88 -> V_92 [ V_89 ] = V_86 -> V_92 [ V_89 ] ;
for ( V_89 = 0 ; V_89 < V_93 ; V_89 ++ ) {
if ( V_86 -> V_94 [ V_89 ] . V_72 == 0 &&
V_86 -> V_94 [ V_89 ] . V_2 == 0 )
break;
V_88 -> V_95 += V_86 -> V_94 [ V_89 ] . V_72 ;
V_88 -> V_94 [ V_89 ] = V_86 -> V_94 [ V_89 ] ;
}
return 0 ;
}
static int F_43 ( struct V_7 * V_8 ,
struct V_96 T_3 * V_97 )
{
struct V_96 V_98 ;
struct V_99 V_100 ;
if ( ! F_44 ( V_101 ) )
return - V_75 ;
if ( F_28 ( & V_98 , V_97 , sizeof( struct V_96 ) ) )
return - V_59 ;
if ( F_28 ( & V_100 , V_98 . V_102 , sizeof( struct V_99 ) ) )
return - V_59 ;
switch ( V_98 . V_103 ) {
case V_104 :
if ( F_45 ( V_8 ) )
return - V_14 ;
return F_46 ( V_8 , V_100 . V_105 , V_100 . V_71 , V_100 . V_72 ) ;
case V_106 :
if ( V_100 . V_107 < 0 )
return - V_14 ;
return F_47 ( V_8 , V_100 . V_107 ) ;
default:
return - V_14 ;
}
}
static int F_48 ( struct V_7 * V_8 ,
struct V_108 T_3 * V_109 )
{
struct V_108 V_110 ;
struct V_54 V_55 ;
void T_3 * V_111 , * V_112 ;
int V_18 ;
if ( F_28 ( & V_110 , V_109 , sizeof( V_110 ) ) ||
! F_36 ( V_77 , V_110 . V_111 , V_110 . V_48 ) ||
! F_36 ( V_77 , V_110 . V_112 , V_110 . V_78 ) )
return - V_59 ;
if ( ! V_8 -> V_76 )
return - V_67 ;
V_55 . V_50 = V_110 . V_50 ;
V_55 . V_48 = ( T_4 ) V_110 . V_48 ;
V_55 . V_78 = ( T_4 ) V_110 . V_78 ;
V_55 . V_62 = 0 ;
V_111 = ( void T_3 * ) ( V_113 ) V_110 . V_111 ;
V_112 = ( void T_3 * ) ( V_113 ) V_110 . V_112 ;
if ( V_110 . V_111 ) {
V_55 . V_57 = F_37 ( V_111 , V_55 . V_48 ) ;
if ( F_7 ( V_55 . V_57 ) )
return F_8 ( V_55 . V_57 ) ;
} else {
V_55 . V_57 = NULL ;
}
if ( V_110 . V_112 ) {
V_55 . V_58 = F_37 ( V_112 , V_55 . V_78 ) ;
if ( F_7 ( V_55 . V_58 ) ) {
F_17 ( V_55 . V_57 ) ;
return F_8 ( V_55 . V_58 ) ;
}
} else {
V_55 . V_58 = NULL ;
}
V_18 = F_30 ( V_8 , ( T_1 ) V_110 . V_71 , & V_55 ) ;
F_17 ( V_55 . V_57 ) ;
F_17 ( V_55 . V_58 ) ;
return V_18 ;
}
static int F_49 ( struct V_1 * V_1 , T_7 V_114 , T_8 V_97 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_109 = ( void T_3 * ) V_97 ;
int V_18 = 0 ;
T_8 V_13 ;
struct V_115 V_116 ;
F_4 ( L_5 ) ;
V_13 = ( V_114 & V_117 ) >> V_118 ;
if ( V_114 & V_119 ) {
if ( ! F_36 ( V_77 , V_109 , V_13 ) )
return - V_59 ;
}
if ( V_114 & V_120 ) {
if ( ! F_36 ( V_84 , V_109 , V_13 ) )
return - V_59 ;
}
switch ( V_114 ) {
case V_121 :
if ( F_26 ( V_109 , & ( V_8 -> V_122 ) , sizeof( int ) ) )
return - V_59 ;
break;
case V_123 :
{
T_6 V_124 ;
struct V_125 * V_126 ;
struct V_127 T_3 * V_128 = V_109 ;
if ( F_50 ( V_124 , & ( V_128 -> V_129 ) ) )
return - V_59 ;
if ( V_124 >= V_8 -> V_122 )
return - V_14 ;
V_126 = & ( V_8 -> V_130 [ V_124 ] ) ;
if ( F_40 ( V_126 -> V_2 , & ( V_128 -> V_2 ) )
|| F_40 ( V_126 -> V_131 , & ( V_128 -> V_131 ) )
|| F_40 ( V_126 -> V_132 , & ( V_128 -> V_132 ) ) )
return - V_59 ;
break;
}
case V_133 :
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . type = V_8 -> type ;
V_116 . V_39 = V_8 -> V_39 ;
V_116 . V_13 = V_8 -> V_13 ;
V_116 . V_131 = V_8 -> V_131 ;
V_116 . V_79 = V_8 -> V_79 ;
V_116 . V_81 = V_8 -> V_81 ;
V_116 . V_134 = 0 ;
if ( F_26 ( V_109 , & V_116 , sizeof( struct V_115 ) ) )
return - V_59 ;
break;
case V_135 :
case V_136 :
{
struct V_63 * V_137 ;
if( ! ( V_1 -> V_20 & V_21 ) )
return - V_75 ;
V_137 = F_13 ( sizeof( struct V_63 ) , V_41 ) ;
if ( ! V_137 )
V_18 = - V_29 ;
else {
V_65 V_138 ;
F_51 ( V_139 , V_140 ) ;
F_52 ( & V_138 ) ;
if ( V_114 == V_136 ) {
struct V_141 V_142 ;
if ( F_28 ( & V_142 , V_109 ,
sizeof( struct V_141 ) ) ) {
F_17 ( V_137 ) ;
return - V_59 ;
}
V_137 -> V_143 = V_142 . V_71 ;
V_137 -> V_48 = V_142 . V_72 ;
} else {
struct V_144 V_145 ;
if ( F_28 ( & V_145 , V_109 ,
sizeof( struct V_144 ) ) ) {
F_17 ( V_137 ) ;
return - V_59 ;
}
V_137 -> V_143 = V_145 . V_71 ;
V_137 -> V_48 = V_145 . V_72 ;
}
V_137 -> V_8 = V_8 ;
V_137 -> V_146 = F_32 ;
V_137 -> V_66 = ( unsigned long ) & V_138 ;
V_18 = F_53 ( V_8 , V_137 ) ;
if ( ! V_18 ) {
F_54 ( V_147 ) ;
F_55 ( & V_138 , & V_139 ) ;
if ( V_137 -> V_148 != V_149 &&
V_137 -> V_148 != V_150 )
F_56 () ;
F_57 ( & V_138 , & V_139 ) ;
F_54 ( V_151 ) ;
V_18 = ( V_137 -> V_148 == V_150 ) ? - V_152 : 0 ;
}
F_17 ( V_137 ) ;
}
break;
}
case V_153 :
{
struct V_154 V_43 ;
struct V_154 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_35 ( V_1 , V_8 , V_43 . V_71 , V_43 . V_72 ,
V_43 . V_73 , & V_155 -> V_72 ) ;
break;
}
case V_156 :
{
struct V_154 V_43 ;
struct V_154 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_38 ( V_1 , V_8 , V_43 . V_71 , V_43 . V_72 ,
V_43 . V_73 , & V_155 -> V_71 ) ;
break;
}
case V_157 :
{
struct V_158 V_43 ;
struct V_158 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_35 ( V_1 , V_8 , V_43 . V_71 , V_43 . V_72 ,
( void T_3 * ) ( V_113 ) V_43 . V_159 ,
& V_155 -> V_72 ) ;
break;
}
case V_160 :
{
struct V_158 V_43 ;
struct V_158 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_38 ( V_1 , V_8 , V_43 . V_71 , V_43 . V_72 ,
( void T_3 * ) ( V_113 ) V_43 . V_159 ,
& V_155 -> V_72 ) ;
break;
}
case V_161 :
{
V_18 = F_48 ( V_8 ,
(struct V_108 T_3 * ) V_97 ) ;
break;
}
case V_162 :
{
struct V_144 V_163 ;
if ( F_28 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_59 ;
V_18 = F_58 ( V_8 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_164 :
{
struct V_144 V_163 ;
if ( F_28 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_59 ;
V_18 = F_59 ( V_8 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_165 :
{
struct V_144 V_163 ;
if ( F_28 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_59 ;
V_18 = F_60 ( V_8 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_166 :
{
struct V_167 V_168 ;
if ( ! V_8 -> V_169 )
return - V_67 ;
if ( V_8 -> V_169 -> V_90 > F_61 ( V_168 . V_92 ) )
return - V_14 ;
V_168 . V_170 = V_171 ;
memcpy ( & V_168 . V_92 , V_8 -> V_169 -> V_92 , sizeof( V_168 . V_92 ) ) ;
memcpy ( & V_168 . V_94 , V_8 -> V_169 -> V_94 ,
sizeof( V_168 . V_94 ) ) ;
V_168 . V_90 = V_8 -> V_169 -> V_90 ;
if ( F_26 ( V_109 , & V_168 , sizeof( struct V_167 ) ) )
return - V_59 ;
break;
}
case V_172 :
{
T_1 V_173 ;
if ( F_28 ( & V_173 , V_109 , sizeof( T_1 ) ) )
return - V_59 ;
return F_62 ( V_8 , V_173 ) ;
break;
}
case V_174 :
{
T_1 V_173 ;
if ( F_28 ( & V_173 , V_109 , sizeof( T_1 ) ) )
return - V_59 ;
return F_63 ( V_8 , V_173 ) ;
break;
}
#ifdef F_64
case V_175 :
{
int V_50 ;
if ( F_28 ( & V_50 , V_109 , sizeof( int ) ) )
return - V_59 ;
V_5 -> V_50 = V_176 ;
V_18 = F_34 ( V_5 , V_50 ) ;
V_1 -> V_11 = 0 ;
break;
}
case V_177 :
case V_178 :
{
struct V_179 * V_43 = F_39 ( 4096 , V_41 ) ;
if ( ! V_43 )
return - V_29 ;
switch ( V_5 -> V_50 ) {
case V_51 :
V_18 = F_65 ( V_8 , V_43 , 4096 ) ;
break;
case V_52 :
V_18 = F_66 ( V_8 , V_43 , 4096 ) ;
break;
default:
V_18 = - V_14 ;
break;
}
if ( V_18 >= 0 ) {
if ( V_114 == V_177 ) {
int V_180 = V_18 / sizeof( struct V_179 ) ;
V_18 = F_26 ( V_109 , & V_180 , sizeof( int ) ) ;
} else
V_18 = F_26 ( V_109 , V_43 , V_18 ) ;
if ( V_18 )
V_18 = - V_59 ;
}
F_17 ( V_43 ) ;
break;
}
case V_181 :
{
struct V_179 V_182 ;
if ( V_5 -> V_50 != V_52 )
return - V_14 ;
if ( F_28 ( & V_182 , V_109 , sizeof( V_182 ) ) )
return - V_59 ;
V_18 = F_67 ( V_8 , V_182 . V_71 , V_182 . V_72 ) ;
break;
}
#endif
case V_183 :
{
struct V_87 * V_184 ;
if ( ! V_8 -> V_169 )
return - V_67 ;
V_184 = F_39 ( sizeof( * V_184 ) , V_41 ) ;
if ( ! V_184 )
return - V_29 ;
F_41 ( V_8 -> V_169 , V_184 ) ;
if ( F_26 ( V_109 , V_184 , sizeof( * V_184 ) ) )
V_18 = - V_59 ;
F_17 ( V_184 ) ;
break;
}
case V_185 :
{
if ( F_26 ( V_109 , & V_8 -> V_186 ,
sizeof( struct V_187 ) ) )
return - V_59 ;
break;
}
case V_188 :
{
V_5 -> V_50 = 0 ;
switch( V_97 ) {
case V_51 :
case V_52 :
V_18 = F_34 ( V_5 , V_97 ) ;
break;
case V_53 :
if ( ! F_68 ( V_8 ) )
return - V_67 ;
V_5 -> V_50 = V_97 ;
case V_176 :
break;
default:
V_18 = - V_14 ;
}
V_1 -> V_11 = 0 ;
break;
}
case V_189 :
{
V_18 = F_43 ( V_8 ,
(struct V_96 T_3 * ) V_97 ) ;
break;
}
case V_190 :
{
V_18 = 0 ;
break;
}
default:
V_18 = - V_191 ;
}
return V_18 ;
}
static long F_69 ( struct V_1 * V_1 , T_7 V_114 , T_8 V_97 )
{
int V_18 ;
F_5 ( & V_23 ) ;
V_18 = F_49 ( V_1 , V_114 , V_97 ) ;
F_14 ( & V_23 ) ;
return V_18 ;
}
static long F_70 ( struct V_1 * V_1 , unsigned int V_114 ,
unsigned long V_97 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_109 = F_71 ( V_97 ) ;
int V_18 = 0 ;
F_5 ( & V_23 ) ;
switch ( V_114 ) {
case V_192 :
{
struct V_193 V_43 ;
struct V_193 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_35 ( V_1 , V_8 , V_43 . V_71 ,
V_43 . V_72 , F_71 ( V_43 . V_73 ) ,
& V_155 -> V_72 ) ;
break;
}
case V_194 :
{
struct V_193 V_43 ;
struct V_193 T_3 * V_155 = V_109 ;
if ( F_28 ( & V_43 , V_109 , sizeof( V_43 ) ) )
V_18 = - V_59 ;
else
V_18 = F_38 ( V_1 , V_8 , V_43 . V_71 ,
V_43 . V_72 , F_71 ( V_43 . V_73 ) ,
& V_155 -> V_71 ) ;
break;
}
default:
V_18 = F_49 ( V_1 , V_114 , ( unsigned long ) V_109 ) ;
}
F_14 ( & V_23 ) ;
return V_18 ;
}
static unsigned long F_72 ( struct V_1 * V_1 ,
unsigned long V_143 ,
unsigned long V_48 ,
unsigned long V_195 ,
unsigned long V_39 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
unsigned long V_2 ;
int V_18 ;
if ( V_143 != 0 )
return ( unsigned long ) - V_14 ;
if ( V_48 > V_8 -> V_13 || V_195 >= ( V_8 -> V_13 >> V_196 ) )
return ( unsigned long ) - V_14 ;
V_2 = V_195 << V_196 ;
if ( V_2 > V_8 -> V_13 - V_48 )
return ( unsigned long ) - V_14 ;
V_18 = F_73 ( V_8 , V_48 , V_2 , V_39 ) ;
return V_18 == - V_67 ? - V_197 : V_18 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_198 * V_199 )
{
#ifdef F_75
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_200 * V_201 = V_8 -> V_66 ;
unsigned long V_71 ;
unsigned long V_202 ;
T_9 V_48 ;
if ( V_8 -> type == V_203 || V_8 -> type == V_204 ) {
V_202 = V_199 -> V_205 << V_196 ;
V_71 = V_201 -> V_206 ;
V_48 = F_76 ( ( V_71 & ~ V_207 ) + V_201 -> V_13 ) ;
V_71 &= V_207 ;
if ( ( V_199 -> V_208 - V_199 -> V_209 + V_202 ) > V_48 )
return - V_14 ;
V_202 += V_71 ;
V_199 -> V_205 = V_202 >> V_196 ;
V_199 -> V_210 |= V_211 | V_212 ;
#ifdef F_77
if ( V_1 -> V_213 & V_214 || V_202 >= F_78 ( V_215 ) )
V_199 -> V_216 = F_77 ( V_199 -> V_216 ) ;
#endif
if ( F_79 ( V_199 , V_199 -> V_209 , V_202 >> V_196 ,
V_199 -> V_208 - V_199 -> V_209 ,
V_199 -> V_216 ) )
return - V_217 ;
return 0 ;
}
return - V_197 ;
#else
return V_199 -> V_210 & V_218 ? 0 : - V_197 ;
#endif
}
static struct V_219 * F_80 ( struct V_220 * V_221 ,
int V_39 , const char * V_222 , void * V_102 )
{
return F_81 ( V_221 , L_6 , NULL , NULL , V_223 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_15 * V_19 = F_84 ( V_27 -> V_28 , V_8 -> V_224 ) ;
if ( V_19 ) {
F_85 ( V_19 ) ;
F_12 ( V_19 ) ;
}
}
static int T_10 F_86 ( void )
{
int V_18 ;
V_18 = F_87 ( V_225 , 0 , 1 << V_226 ,
L_7 , & V_227 ) ;
if ( V_18 < 0 ) {
F_88 ( L_8
L_9 , V_225 ) ;
return V_18 ;
}
V_18 = F_89 ( & V_228 ) ;
if ( V_18 ) {
F_88 ( L_10 , V_18 ) ;
goto V_229;
}
V_27 = F_90 ( & V_228 ) ;
if ( F_7 ( V_27 ) ) {
V_18 = F_8 ( V_27 ) ;
F_88 ( L_11 , V_18 ) ;
goto V_230;
}
F_91 ( & V_231 ) ;
return V_18 ;
V_230:
F_92 ( & V_228 ) ;
V_229:
F_93 ( V_225 , 0 , 1 << V_226 , L_7 ) ;
return V_18 ;
}
static void T_11 F_94 ( void )
{
F_95 ( & V_231 ) ;
F_96 ( V_27 ) ;
F_92 ( & V_228 ) ;
F_93 ( V_225 , 0 , 1 << V_226 , L_7 ) ;
}
