static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
return F_2 ( V_1 , V_2 , V_3 , V_5 -> V_7 -> V_8 ) ;
}
static int F_3 ( struct V_9 * V_9 , struct V_1 * V_1 )
{
int V_10 = F_4 ( V_9 ) ;
int V_11 = V_10 >> 1 ;
int V_12 = 0 ;
struct V_13 * V_7 ;
struct V_4 * V_5 ;
struct V_9 * V_14 ;
F_5 ( L_1 ) ;
if ( ( V_1 -> V_15 & V_16 ) && ( V_10 & 1 ) )
return - V_17 ;
V_12 = F_6 ( & V_18 , & V_19 , & V_20 ) ;
if ( V_12 )
return V_12 ;
F_7 ( & V_21 ) ;
V_7 = F_8 ( NULL , V_11 ) ;
if ( F_9 ( V_7 ) ) {
V_12 = F_10 ( V_7 ) ;
goto V_22;
}
if ( V_7 -> type == V_23 ) {
V_12 = - V_24 ;
goto V_25;
}
V_14 = F_11 ( V_19 -> V_26 , V_11 ) ;
if ( ! V_14 ) {
V_12 = - V_27 ;
goto V_25;
}
if ( V_14 -> V_28 & V_29 ) {
V_14 -> V_30 = V_7 ;
V_14 -> V_31 = V_32 ;
V_14 -> V_33 . V_34 = V_7 -> V_34 ;
F_12 ( V_14 ) ;
}
V_1 -> V_35 = V_14 -> V_36 ;
if ( ( V_1 -> V_15 & V_16 ) && ! ( V_7 -> V_37 & V_38 ) ) {
V_12 = - V_17 ;
goto V_39;
}
V_5 = F_13 ( sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 ) {
V_12 = - V_27 ;
goto V_39;
}
V_5 -> V_41 = V_14 ;
V_5 -> V_7 = V_7 ;
V_1 -> V_6 = V_5 ;
F_14 ( & V_21 ) ;
return 0 ;
V_39:
F_15 ( V_14 ) ;
V_25:
F_16 ( V_7 ) ;
V_22:
F_14 ( & V_21 ) ;
F_17 ( & V_19 , & V_20 ) ;
return V_12 ;
}
static int F_18 ( struct V_9 * V_9 , struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
F_5 ( L_2 ) ;
if ( ( V_1 -> V_15 & V_16 ) )
F_19 ( V_7 ) ;
F_15 ( V_5 -> V_41 ) ;
F_16 ( V_7 ) ;
V_1 -> V_6 = NULL ;
F_20 ( V_5 ) ;
F_17 ( & V_19 , & V_20 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_1 * V_1 , char T_3 * V_42 , T_4 V_20 ,
T_1 * V_43 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_44 ;
T_4 V_45 = 0 ;
int V_12 = 0 ;
int V_46 ;
T_4 V_8 = V_20 ;
char * V_47 ;
F_5 ( L_3 ) ;
if ( * V_43 + V_20 > V_7 -> V_8 )
V_20 = V_7 -> V_8 - * V_43 ;
if ( ! V_20 )
return 0 ;
V_47 = F_22 ( V_7 , & V_8 ) ;
if ( ! V_47 )
return - V_27 ;
while ( V_20 ) {
V_46 = F_23 ( T_4 , V_20 , V_8 ) ;
switch ( V_5 -> V_48 ) {
case V_49 :
V_12 = F_24 ( V_7 , * V_43 , V_46 ,
& V_44 , V_47 ) ;
break;
case V_50 :
V_12 = F_25 ( V_7 , * V_43 , V_46 ,
& V_44 , V_47 ) ;
break;
case V_51 :
{
struct V_52 V_53 ;
V_53 . V_48 = V_54 ;
V_53 . V_55 = V_47 ;
V_53 . V_56 = NULL ;
V_53 . V_46 = V_46 ;
V_12 = F_26 ( V_7 , * V_43 , & V_53 ) ;
V_44 = V_53 . V_44 ;
break;
}
default:
V_12 = F_27 ( V_7 , * V_43 , V_46 , & V_44 , V_47 ) ;
}
if ( ! V_12 || F_28 ( V_12 ) ) {
* V_43 += V_44 ;
if ( F_29 ( V_42 , V_47 , V_44 ) ) {
F_20 ( V_47 ) ;
return - V_57 ;
}
else
V_45 += V_44 ;
V_20 -= V_44 ;
V_42 += V_44 ;
if ( V_44 == 0 )
V_20 = 0 ;
}
else {
F_20 ( V_47 ) ;
return V_12 ;
}
}
F_20 ( V_47 ) ;
return V_45 ;
}
static T_2 F_30 ( struct V_1 * V_1 , const char T_3 * V_42 , T_4 V_20 ,
T_1 * V_43 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_8 = V_20 ;
char * V_47 ;
T_4 V_44 ;
T_4 V_45 = 0 ;
int V_12 = 0 ;
int V_46 ;
F_5 ( L_4 ) ;
if ( * V_43 == V_7 -> V_8 )
return - V_58 ;
if ( * V_43 + V_20 > V_7 -> V_8 )
V_20 = V_7 -> V_8 - * V_43 ;
if ( ! V_20 )
return 0 ;
V_47 = F_22 ( V_7 , & V_8 ) ;
if ( ! V_47 )
return - V_27 ;
while ( V_20 ) {
V_46 = F_23 ( T_4 , V_20 , V_8 ) ;
if ( F_31 ( V_47 , V_42 , V_46 ) ) {
F_20 ( V_47 ) ;
return - V_57 ;
}
switch ( V_5 -> V_48 ) {
case V_49 :
V_12 = - V_59 ;
break;
case V_50 :
V_12 = F_32 ( V_7 , * V_43 , V_46 ,
& V_44 , V_47 ) ;
break;
case V_51 :
{
struct V_52 V_53 ;
V_53 . V_48 = V_54 ;
V_53 . V_55 = V_47 ;
V_53 . V_56 = NULL ;
V_53 . V_60 = 0 ;
V_53 . V_46 = V_46 ;
V_12 = F_33 ( V_7 , * V_43 , & V_53 ) ;
V_44 = V_53 . V_44 ;
break;
}
default:
V_12 = F_34 ( V_7 , * V_43 , V_46 , & V_44 , V_47 ) ;
}
if ( ( V_12 == - V_58 ) && ( V_45 ) )
break;
if ( ! V_12 ) {
* V_43 += V_44 ;
V_45 += V_44 ;
V_20 -= V_44 ;
V_42 += V_44 ;
}
else {
F_20 ( V_47 ) ;
return V_12 ;
}
}
F_20 ( V_47 ) ;
return V_45 ;
}
static void F_35 ( struct V_61 * V_62 )
{
F_36 ( ( V_63 * ) V_62 -> V_64 ) ;
}
static int F_37 ( struct V_4 * V_5 , int V_48 )
{
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_44 ;
switch ( V_48 ) {
case V_65 :
if ( F_24 ( V_7 , - 1 , 0 , & V_44 , NULL ) ==
- V_66 )
return - V_66 ;
V_5 -> V_48 = V_49 ;
break;
case V_67 :
if ( F_25 ( V_7 , - 1 , 0 , & V_44 , NULL ) ==
- V_66 )
return - V_66 ;
V_5 -> V_48 = V_50 ;
break;
case V_68 :
V_5 -> V_48 = V_69 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , struct V_13 * V_7 ,
T_5 V_71 , T_6 V_72 , void T_3 * V_73 ,
T_6 T_3 * V_74 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_52 V_53 ;
T_6 V_44 ;
int V_12 = 0 ;
if ( ! ( V_1 -> V_15 & V_16 ) )
return - V_75 ;
if ( V_72 > 4096 )
return - V_70 ;
if ( ! V_7 -> V_76 )
V_12 = - V_66 ;
else
V_12 = F_39 ( V_77 , V_73 , V_72 ) ? 0 : - V_57 ;
if ( V_12 )
return V_12 ;
V_53 . V_78 = V_72 ;
V_53 . V_60 = V_71 & ( V_7 -> V_79 - 1 ) ;
V_53 . V_55 = NULL ;
V_53 . V_48 = ( V_5 -> V_48 == V_51 ) ? V_54 :
V_80 ;
if ( V_53 . V_60 && V_53 . V_78 > ( V_7 -> V_81 - V_53 . V_60 ) )
return - V_70 ;
V_53 . V_56 = F_40 ( V_73 , V_72 ) ;
if ( F_9 ( V_53 . V_56 ) )
return F_10 ( V_53 . V_56 ) ;
V_71 &= ~ ( ( T_5 ) V_7 -> V_79 - 1 ) ;
V_12 = F_33 ( V_7 , V_71 , & V_53 ) ;
if ( V_53 . V_82 > 0xFFFFFFFFU )
V_12 = - V_83 ;
V_44 = V_53 . V_82 ;
if ( F_29 ( V_74 , & V_44 , sizeof( V_72 ) ) )
V_12 = - V_57 ;
F_20 ( V_53 . V_56 ) ;
return V_12 ;
}
static int F_41 ( struct V_1 * V_1 , struct V_13 * V_7 ,
T_5 V_71 , T_6 V_72 , void T_3 * V_73 ,
T_6 T_3 * V_74 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_52 V_53 ;
int V_12 = 0 ;
if ( V_72 > 4096 )
return - V_70 ;
if ( ! F_39 ( V_84 , V_73 , V_72 ) )
return - V_57 ;
V_53 . V_78 = V_72 ;
V_53 . V_60 = V_71 & ( V_7 -> V_79 - 1 ) ;
V_53 . V_55 = NULL ;
V_53 . V_48 = ( V_5 -> V_48 == V_51 ) ? V_54 :
V_80 ;
if ( V_53 . V_60 && V_53 . V_78 > ( V_7 -> V_81 - V_53 . V_60 ) )
return - V_70 ;
V_53 . V_56 = F_42 ( V_72 , V_40 ) ;
if ( ! V_53 . V_56 )
return - V_27 ;
V_71 &= ~ ( ( T_5 ) V_7 -> V_79 - 1 ) ;
V_12 = F_26 ( V_7 , V_71 , & V_53 ) ;
if ( F_43 ( V_53 . V_82 , V_74 ) )
V_12 = - V_57 ;
else if ( V_53 . V_82 && F_29 ( V_73 , V_53 . V_56 ,
V_53 . V_82 ) )
V_12 = - V_57 ;
F_20 ( V_53 . V_56 ) ;
if ( F_28 ( V_12 ) )
return 0 ;
return V_12 ;
}
static int F_44 ( const struct V_85 * V_86 ,
struct V_87 * V_88 )
{
int V_89 ;
if ( ! V_86 || ! V_88 )
return - V_70 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_90 = F_45 ( ( int ) V_86 -> V_90 , V_91 ) ;
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
static int F_46 ( struct V_13 * V_7 ,
struct V_96 T_3 * V_97 )
{
struct V_96 V_98 ;
struct V_99 V_100 ;
if ( ! F_47 ( V_101 ) )
return - V_75 ;
if ( F_31 ( & V_98 , V_97 , sizeof( struct V_96 ) ) )
return - V_57 ;
if ( F_31 ( & V_100 , V_98 . V_102 , sizeof( struct V_99 ) ) )
return - V_57 ;
switch ( V_98 . V_103 ) {
case V_104 :
if ( F_48 ( V_7 ) )
return - V_70 ;
return F_49 ( V_7 , V_100 . V_105 , V_100 . V_71 , V_100 . V_72 ) ;
case V_106 :
if ( V_100 . V_107 < 0 )
return - V_70 ;
return F_50 ( V_7 , V_100 . V_107 ) ;
default:
return - V_70 ;
}
}
static int F_51 ( struct V_13 * V_7 ,
struct V_108 T_3 * V_109 )
{
struct V_108 V_110 ;
struct V_52 V_53 ;
void T_3 * V_111 , * V_112 ;
int V_12 ;
if ( F_31 ( & V_110 , V_109 , sizeof( V_110 ) ) ||
! F_39 ( V_77 , V_110 . V_111 , V_110 . V_46 ) ||
! F_39 ( V_77 , V_110 . V_112 , V_110 . V_78 ) )
return - V_57 ;
if ( ! V_7 -> V_76 )
return - V_66 ;
V_53 . V_48 = V_110 . V_48 ;
V_53 . V_46 = ( T_4 ) V_110 . V_46 ;
V_53 . V_78 = ( T_4 ) V_110 . V_78 ;
V_53 . V_60 = 0 ;
V_111 = ( void T_3 * ) ( V_113 ) V_110 . V_111 ;
V_112 = ( void T_3 * ) ( V_113 ) V_110 . V_112 ;
if ( V_110 . V_111 ) {
V_53 . V_55 = F_40 ( V_111 , V_53 . V_46 ) ;
if ( F_9 ( V_53 . V_55 ) )
return F_10 ( V_53 . V_55 ) ;
} else {
V_53 . V_55 = NULL ;
}
if ( V_110 . V_112 ) {
V_53 . V_56 = F_40 ( V_112 , V_53 . V_78 ) ;
if ( F_9 ( V_53 . V_56 ) ) {
F_20 ( V_53 . V_55 ) ;
return F_10 ( V_53 . V_56 ) ;
}
} else {
V_53 . V_56 = NULL ;
}
V_12 = F_33 ( V_7 , ( T_1 ) V_110 . V_71 , & V_53 ) ;
F_20 ( V_53 . V_55 ) ;
F_20 ( V_53 . V_56 ) ;
return V_12 ;
}
static int F_52 ( struct V_1 * V_1 , T_7 V_114 , T_8 V_97 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_109 = ( void T_3 * ) V_97 ;
int V_12 = 0 ;
T_8 V_8 ;
struct V_115 V_116 ;
F_5 ( L_5 ) ;
V_8 = ( V_114 & V_117 ) >> V_118 ;
if ( V_114 & V_119 ) {
if ( ! F_39 ( V_77 , V_109 , V_8 ) )
return - V_57 ;
}
if ( V_114 & V_120 ) {
if ( ! F_39 ( V_84 , V_109 , V_8 ) )
return - V_57 ;
}
switch ( V_114 ) {
case V_121 :
if ( F_29 ( V_109 , & ( V_7 -> V_122 ) , sizeof( int ) ) )
return - V_57 ;
break;
case V_123 :
{
T_6 V_124 ;
struct V_125 * V_126 ;
struct V_127 T_3 * V_128 = V_109 ;
if ( F_53 ( V_124 , & ( V_128 -> V_129 ) ) )
return - V_57 ;
if ( V_124 >= V_7 -> V_122 )
return - V_70 ;
V_126 = & ( V_7 -> V_130 [ V_124 ] ) ;
if ( F_43 ( V_126 -> V_2 , & ( V_128 -> V_2 ) )
|| F_43 ( V_126 -> V_131 , & ( V_128 -> V_131 ) )
|| F_43 ( V_126 -> V_132 , & ( V_128 -> V_132 ) ) )
return - V_57 ;
break;
}
case V_133 :
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . type = V_7 -> type ;
V_116 . V_37 = V_7 -> V_37 ;
V_116 . V_8 = V_7 -> V_8 ;
V_116 . V_131 = V_7 -> V_131 ;
V_116 . V_79 = V_7 -> V_79 ;
V_116 . V_81 = V_7 -> V_81 ;
V_116 . V_134 = 0 ;
if ( F_29 ( V_109 , & V_116 , sizeof( struct V_115 ) ) )
return - V_57 ;
break;
case V_135 :
case V_136 :
{
struct V_61 * V_137 ;
if( ! ( V_1 -> V_15 & V_16 ) )
return - V_75 ;
V_137 = F_13 ( sizeof( struct V_61 ) , V_40 ) ;
if ( ! V_137 )
V_12 = - V_27 ;
else {
V_63 V_138 ;
F_54 ( V_139 , V_140 ) ;
F_55 ( & V_138 ) ;
if ( V_114 == V_136 ) {
struct V_141 V_142 ;
if ( F_31 ( & V_142 , V_109 ,
sizeof( struct V_141 ) ) ) {
F_20 ( V_137 ) ;
return - V_57 ;
}
V_137 -> V_143 = V_142 . V_71 ;
V_137 -> V_46 = V_142 . V_72 ;
} else {
struct V_144 V_145 ;
if ( F_31 ( & V_145 , V_109 ,
sizeof( struct V_144 ) ) ) {
F_20 ( V_137 ) ;
return - V_57 ;
}
V_137 -> V_143 = V_145 . V_71 ;
V_137 -> V_46 = V_145 . V_72 ;
}
V_137 -> V_7 = V_7 ;
V_137 -> V_146 = F_35 ;
V_137 -> V_64 = ( unsigned long ) & V_138 ;
V_12 = F_56 ( V_7 , V_137 ) ;
if ( ! V_12 ) {
F_57 ( V_147 ) ;
F_58 ( & V_138 , & V_139 ) ;
if ( V_137 -> V_148 != V_149 &&
V_137 -> V_148 != V_150 )
F_59 () ;
F_60 ( & V_138 , & V_139 ) ;
F_57 ( V_151 ) ;
V_12 = ( V_137 -> V_148 == V_150 ) ? - V_152 : 0 ;
}
F_20 ( V_137 ) ;
}
break;
}
case V_153 :
{
struct V_154 V_42 ;
struct V_154 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_38 ( V_1 , V_7 , V_42 . V_71 , V_42 . V_72 ,
V_42 . V_73 , & V_155 -> V_72 ) ;
break;
}
case V_156 :
{
struct V_154 V_42 ;
struct V_154 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_41 ( V_1 , V_7 , V_42 . V_71 , V_42 . V_72 ,
V_42 . V_73 , & V_155 -> V_71 ) ;
break;
}
case V_157 :
{
struct V_158 V_42 ;
struct V_158 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_38 ( V_1 , V_7 , V_42 . V_71 , V_42 . V_72 ,
( void T_3 * ) ( V_113 ) V_42 . V_159 ,
& V_155 -> V_72 ) ;
break;
}
case V_160 :
{
struct V_158 V_42 ;
struct V_158 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_41 ( V_1 , V_7 , V_42 . V_71 , V_42 . V_72 ,
( void T_3 * ) ( V_113 ) V_42 . V_159 ,
& V_155 -> V_72 ) ;
break;
}
case V_161 :
{
V_12 = F_51 ( V_7 ,
(struct V_108 T_3 * ) V_97 ) ;
break;
}
case V_162 :
{
struct V_144 V_163 ;
if ( F_31 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_57 ;
V_12 = F_61 ( V_7 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_164 :
{
struct V_144 V_163 ;
if ( F_31 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_57 ;
V_12 = F_62 ( V_7 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_165 :
{
struct V_144 V_163 ;
if ( F_31 ( & V_163 , V_109 , sizeof( V_163 ) ) )
return - V_57 ;
V_12 = F_63 ( V_7 , V_163 . V_71 , V_163 . V_72 ) ;
break;
}
case V_166 :
{
struct V_167 V_168 ;
if ( ! V_7 -> V_169 )
return - V_66 ;
if ( V_7 -> V_169 -> V_90 > F_64 ( V_168 . V_92 ) )
return - V_70 ;
V_168 . V_170 = V_171 ;
memcpy ( & V_168 . V_92 , V_7 -> V_169 -> V_92 , sizeof( V_168 . V_92 ) ) ;
memcpy ( & V_168 . V_94 , V_7 -> V_169 -> V_94 ,
sizeof( V_168 . V_94 ) ) ;
V_168 . V_90 = V_7 -> V_169 -> V_90 ;
if ( F_29 ( V_109 , & V_168 , sizeof( struct V_167 ) ) )
return - V_57 ;
break;
}
case V_172 :
{
T_1 V_173 ;
if ( F_31 ( & V_173 , V_109 , sizeof( T_1 ) ) )
return - V_57 ;
return F_65 ( V_7 , V_173 ) ;
break;
}
case V_174 :
{
T_1 V_173 ;
if ( F_31 ( & V_173 , V_109 , sizeof( T_1 ) ) )
return - V_57 ;
return F_66 ( V_7 , V_173 ) ;
break;
}
case V_175 :
{
int V_48 ;
if ( F_31 ( & V_48 , V_109 , sizeof( int ) ) )
return - V_57 ;
V_5 -> V_48 = V_69 ;
V_12 = F_37 ( V_5 , V_48 ) ;
V_1 -> V_176 = 0 ;
break;
}
case V_177 :
case V_178 :
{
struct V_179 * V_42 = F_42 ( 4096 , V_40 ) ;
T_4 V_44 ;
if ( ! V_42 )
return - V_27 ;
switch ( V_5 -> V_48 ) {
case V_49 :
V_12 = F_67 ( V_7 , 4096 , & V_44 , V_42 ) ;
break;
case V_50 :
V_12 = F_68 ( V_7 , 4096 , & V_44 , V_42 ) ;
break;
default:
V_12 = - V_70 ;
break;
}
if ( ! V_12 ) {
if ( V_114 == V_177 ) {
int V_180 = V_44 / sizeof( struct V_179 ) ;
V_12 = F_29 ( V_109 , & V_180 , sizeof( int ) ) ;
} else
V_12 = F_29 ( V_109 , V_42 , V_44 ) ;
if ( V_12 )
V_12 = - V_57 ;
}
F_20 ( V_42 ) ;
break;
}
case V_181 :
{
struct V_179 V_182 ;
if ( V_5 -> V_48 != V_50 )
return - V_70 ;
if ( F_31 ( & V_182 , V_109 , sizeof( V_182 ) ) )
return - V_57 ;
V_12 = F_69 ( V_7 , V_182 . V_71 , V_182 . V_72 ) ;
break;
}
case V_183 :
{
struct V_87 * V_184 ;
if ( ! V_7 -> V_169 )
return - V_66 ;
V_184 = F_42 ( sizeof( * V_184 ) , V_40 ) ;
if ( ! V_184 )
return - V_27 ;
F_44 ( V_7 -> V_169 , V_184 ) ;
if ( F_29 ( V_109 , V_184 , sizeof( * V_184 ) ) )
V_12 = - V_57 ;
F_20 ( V_184 ) ;
break;
}
case V_185 :
{
if ( F_29 ( V_109 , & V_7 -> V_186 ,
sizeof( struct V_187 ) ) )
return - V_57 ;
break;
}
case V_188 :
{
V_5 -> V_48 = 0 ;
switch( V_97 ) {
case V_49 :
case V_50 :
V_12 = F_37 ( V_5 , V_97 ) ;
break;
case V_51 :
if ( ! F_70 ( V_7 ) )
return - V_66 ;
V_5 -> V_48 = V_97 ;
case V_69 :
break;
default:
V_12 = - V_70 ;
}
V_1 -> V_176 = 0 ;
break;
}
case V_189 :
{
V_12 = F_46 ( V_7 ,
(struct V_96 T_3 * ) V_97 ) ;
break;
}
case V_190 :
{
V_12 = 0 ;
break;
}
default:
V_12 = - V_191 ;
}
return V_12 ;
}
static long F_71 ( struct V_1 * V_1 , T_7 V_114 , T_8 V_97 )
{
int V_12 ;
F_7 ( & V_21 ) ;
V_12 = F_52 ( V_1 , V_114 , V_97 ) ;
F_14 ( & V_21 ) ;
return V_12 ;
}
static long F_72 ( struct V_1 * V_1 , unsigned int V_114 ,
unsigned long V_97 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_109 = F_73 ( V_97 ) ;
int V_12 = 0 ;
F_7 ( & V_21 ) ;
switch ( V_114 ) {
case V_192 :
{
struct V_193 V_42 ;
struct V_193 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_38 ( V_1 , V_7 , V_42 . V_71 ,
V_42 . V_72 , F_73 ( V_42 . V_73 ) ,
& V_155 -> V_72 ) ;
break;
}
case V_194 :
{
struct V_193 V_42 ;
struct V_193 T_3 * V_155 = V_109 ;
if ( F_31 ( & V_42 , V_109 , sizeof( V_42 ) ) )
V_12 = - V_57 ;
else
V_12 = F_41 ( V_1 , V_7 , V_42 . V_71 ,
V_42 . V_72 , F_73 ( V_42 . V_73 ) ,
& V_155 -> V_71 ) ;
break;
}
default:
V_12 = F_52 ( V_1 , V_114 , ( unsigned long ) V_109 ) ;
}
F_14 ( & V_21 ) ;
return V_12 ;
}
static unsigned long F_74 ( struct V_1 * V_1 ,
unsigned long V_143 ,
unsigned long V_46 ,
unsigned long V_195 ,
unsigned long V_37 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
unsigned long V_2 ;
int V_12 ;
if ( V_143 != 0 )
return ( unsigned long ) - V_70 ;
if ( V_46 > V_7 -> V_8 || V_195 >= ( V_7 -> V_8 >> V_196 ) )
return ( unsigned long ) - V_70 ;
V_2 = V_195 << V_196 ;
if ( V_2 > V_7 -> V_8 - V_46 )
return ( unsigned long ) - V_70 ;
V_12 = F_75 ( V_7 , V_46 , V_2 , V_37 ) ;
return V_12 == - V_66 ? - V_24 : V_12 ;
}
static int F_76 ( struct V_1 * V_1 , struct V_197 * V_198 )
{
#ifdef F_77
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
struct V_199 * V_200 = V_7 -> V_64 ;
if ( 0 ) {
#ifdef F_78
if ( V_1 -> V_201 & V_202 || V_200 -> V_203 >= F_79 ( V_204 ) )
V_198 -> V_205 = F_78 ( V_198 -> V_205 ) ;
#endif
return F_80 ( V_198 , V_200 -> V_203 , V_200 -> V_8 ) ;
}
return - V_24 ;
#else
return V_198 -> V_206 & V_207 ? 0 : - V_17 ;
#endif
}
static struct V_208 * F_81 ( struct V_209 * V_210 ,
int V_37 , const char * V_211 , void * V_102 )
{
return F_82 ( V_210 , L_6 , & V_212 , NULL , V_213 ) ;
}
int T_9 F_83 ( void )
{
int V_12 ;
V_12 = F_84 ( V_214 , 0 , 1 << V_215 ,
L_7 , & V_216 ) ;
if ( V_12 < 0 ) {
F_85 ( L_8 ,
V_214 ) ;
return V_12 ;
}
V_12 = F_86 ( & V_18 ) ;
if ( V_12 ) {
F_85 ( L_9 ,
V_12 ) ;
goto V_217;
}
return V_12 ;
V_217:
F_87 ( V_214 , 0 , 1 << V_215 , L_7 ) ;
return V_12 ;
}
void T_10 F_88 ( void )
{
F_89 ( & V_18 ) ;
F_87 ( V_214 , 0 , 1 << V_215 , L_7 ) ;
}
