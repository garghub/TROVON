static int F_1 ( struct V_1 * V_2 )
{
const T_1 * * V_3 ;
T_2 * V_4 ;
T_2 V_5 = V_6 ;
int V_7 = ( ( int ) V_5 ) + 1 ;
T_3 V_8 ;
if ( V_2 -> V_3 != NULL )
return 1 ;
V_3 = F_2 ( V_7 * sizeof( * V_3 ) ) ;
V_4 = F_2 ( V_7 * sizeof( * V_4 ) ) ;
if ( V_4 == NULL || V_3 == NULL ) {
F_3 ( V_4 ) ;
F_3 ( V_3 ) ;
F_4 ( V_9 , V_10 ) ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < F_5 ( V_11 ) ; ++ V_8 ) {
const T_1 * V_12 ;
if ( V_11 [ V_8 ] . V_13 == V_14 ||
( V_12 = F_6 ( V_11 [ V_8 ] . V_13 ) ) == NULL )
continue;
V_3 [ V_11 [ V_8 ] . V_15 ] = V_12 ;
V_4 [ V_11 [ V_8 ] . V_15 ] = V_11 [ V_8 ] . V_16 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
return 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = 0 ;
}
static void F_8 ( T_4 * V_17 )
{
if ( V_17 == NULL )
return;
F_3 ( V_17 -> V_18 ) ;
F_9 ( V_17 -> V_19 ) ;
F_3 ( V_17 ) ;
}
static void F_10 ( T_5 * V_20 )
{
F_11 ( V_20 -> V_21 , F_8 ) ;
V_20 -> V_21 = NULL ;
F_12 ( V_20 -> V_22 , V_23 ) ;
V_20 -> V_22 = NULL ;
V_23 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
V_20 -> V_25 = NULL ;
V_20 -> V_26 = - 1 ;
V_20 -> V_27 = - 1 ;
}
static int F_13 ( T_6 * V_28 , T_6 * V_29 )
{
int V_30 ;
int V_8 ;
if ( ! F_14 ( & V_29 -> V_20 ) )
return 1 ;
F_10 ( & V_28 -> V_20 ) ;
V_28 -> V_20 . V_31 = V_29 -> V_20 . V_31 ;
V_28 -> V_20 . V_2 = & V_28 -> V_32 -> V_20 ;
V_28 -> V_20 . V_21 = F_15 () ;
if ( V_28 -> V_20 . V_21 == NULL ) {
F_4 ( V_33 , V_10 ) ;
return 0 ;
}
V_30 = F_16 ( V_29 -> V_20 . V_21 ) ;
for ( V_8 = 0 ; V_8 < V_30 ; ++ V_8 ) {
T_4 * V_17 = F_17 ( V_29 -> V_20 . V_21 , V_8 ) ;
if ( F_18 ( V_28 , V_17 -> V_34 , V_17 -> V_35 , V_17 -> V_15 ,
V_17 -> V_18 , V_17 -> V_36 ) <= 0 )
return 0 ;
}
return 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
const T_1 * V_12 , T_2 V_15 , T_2 V_16 )
{
int V_8 ;
if ( V_15 == V_37 && V_12 != NULL ) {
F_4 ( V_38 , V_39 ) ;
return 0 ;
}
if ( V_15 > V_2 -> V_5 ) {
const T_1 * * V_3 ;
T_2 * V_4 ;
int V_7 = ( ( int ) V_15 ) + 1 ;
V_3 = F_20 ( V_2 -> V_3 , V_7 * sizeof( * V_3 ) ) ;
if ( V_3 == NULL ) {
F_4 ( V_38 , V_10 ) ;
return - 1 ;
}
V_2 -> V_3 = V_3 ;
V_4 = F_20 ( V_2 -> V_4 , V_7 * sizeof( * V_4 ) ) ;
if ( V_4 == NULL ) {
F_4 ( V_38 , V_10 ) ;
return - 1 ;
}
V_2 -> V_4 = V_4 ;
for ( V_8 = V_2 -> V_5 + 1 ; V_8 < V_15 ; ++ V_8 ) {
V_3 [ V_8 ] = NULL ;
V_4 [ V_8 ] = 0 ;
}
V_2 -> V_5 = V_15 ;
}
V_2 -> V_3 [ V_15 ] = V_12 ;
V_2 -> V_4 [ V_15 ] = ( V_12 == NULL ) ? 0 : V_16 ;
return 1 ;
}
static const T_1 * F_21 ( T_5 * V_20 , T_2 V_15 )
{
if ( V_15 > V_20 -> V_2 -> V_5 )
return NULL ;
return V_20 -> V_2 -> V_3 [ V_15 ] ;
}
static int F_22 ( T_5 * V_20 ,
T_2 V_34 ,
T_2 V_35 ,
T_2 V_15 , unsigned char * V_18 , T_3 V_36 )
{
T_4 * V_17 ;
const T_1 * V_12 = NULL ;
int V_40 = ( int ) V_36 ;
int V_8 ;
int V_30 ;
if ( V_20 -> V_21 == NULL ) {
F_4 ( V_41 , V_42 ) ;
return - 1 ;
}
if ( V_40 < 0 || V_36 != ( T_3 ) V_40 ) {
F_4 ( V_41 , V_43 ) ;
return 0 ;
}
if ( V_34 > V_44 ) {
F_4 ( V_41 , V_45 ) ;
return 0 ;
}
if ( V_35 > V_46 ) {
F_4 ( V_41 , V_47 ) ;
return 0 ;
}
if ( V_15 != V_37 ) {
V_12 = F_21 ( V_20 , V_15 ) ;
if ( V_12 == NULL ) {
F_4 ( V_41 , V_48 ) ;
return 0 ;
}
}
if ( V_12 != NULL && V_36 != ( T_3 ) F_23 ( V_12 ) ) {
F_4 ( V_41 , V_49 ) ;
return 0 ;
}
if ( ! V_18 ) {
F_4 ( V_41 , V_50 ) ;
return 0 ;
}
if ( ( V_17 = F_2 ( sizeof( * V_17 ) ) ) == NULL ) {
F_4 ( V_41 , V_10 ) ;
return - 1 ;
}
V_17 -> V_34 = V_34 ;
V_17 -> V_35 = V_35 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_18 = F_24 ( V_40 ) ;
if ( V_17 -> V_18 == NULL ) {
F_8 ( V_17 ) ;
F_4 ( V_41 , V_10 ) ;
return - 1 ;
}
memcpy ( V_17 -> V_18 , V_18 , V_40 ) ;
V_17 -> V_36 = V_40 ;
if ( V_15 == V_37 ) {
const unsigned char * V_51 = V_18 ;
T_7 * V_52 = NULL ;
T_8 * V_53 = NULL ;
switch ( V_35 ) {
case V_54 :
if ( ! F_25 ( & V_52 , & V_51 , V_36 ) || V_51 < V_18 ||
V_36 != ( T_3 ) ( V_51 - V_18 ) ) {
F_8 ( V_17 ) ;
F_4 ( V_41 , V_55 ) ;
return 0 ;
}
if ( F_26 ( V_52 ) == NULL ) {
F_8 ( V_17 ) ;
F_4 ( V_41 , V_55 ) ;
return 0 ;
}
if ( ( F_27 ( V_34 ) & V_56 ) == 0 ) {
V_23 ( V_52 ) ;
break;
}
if ( ( V_20 -> V_22 == NULL &&
( V_20 -> V_22 = F_28 () ) == NULL ) ||
! F_29 ( V_20 -> V_22 , V_52 ) ) {
F_4 ( V_41 , V_10 ) ;
V_23 ( V_52 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
break;
case V_57 :
if ( ! F_30 ( & V_53 , & V_51 , V_36 ) || V_51 < V_18 ||
V_36 != ( T_3 ) ( V_51 - V_18 ) ) {
F_8 ( V_17 ) ;
F_4 ( V_41 , V_58 ) ;
return 0 ;
}
if ( V_34 == V_59 )
V_17 -> V_19 = V_53 ;
else
F_9 ( V_53 ) ;
break;
}
}
V_30 = F_16 ( V_20 -> V_21 ) ;
for ( V_8 = 0 ; V_8 < V_30 ; ++ V_8 ) {
T_4 * V_60 = F_17 ( V_20 -> V_21 , V_8 ) ;
if ( V_60 -> V_34 > V_34 )
continue;
if ( V_60 -> V_34 < V_34 )
break;
if ( V_60 -> V_35 > V_35 )
continue;
if ( V_60 -> V_35 < V_35 )
break;
if ( V_20 -> V_2 -> V_4 [ V_60 -> V_15 ] > V_20 -> V_2 -> V_4 [ V_15 ] )
continue;
break;
}
if ( ! F_31 ( V_20 -> V_21 , V_17 , V_8 ) ) {
F_8 ( V_17 ) ;
F_4 ( V_41 , V_10 ) ;
return - 1 ;
}
V_20 -> V_61 |= F_27 ( V_34 ) ;
return 1 ;
}
static void F_32 ( T_6 * V_62 )
{
F_33 ( V_62 ) ;
F_34 ( & V_62 -> V_63 ) ;
F_34 ( & V_62 -> V_64 ) ;
}
int F_35 ( T_6 * V_62 )
{
if ( V_62 -> V_65 == NULL ) {
F_4 ( V_66 , V_67 ) ;
return ( 0 ) ;
}
if ( F_36 ( V_62 ) ) {
F_37 ( V_62 -> V_68 ) ;
V_62 -> V_68 = NULL ;
}
V_62 -> error = 0 ;
V_62 -> V_69 = 0 ;
V_62 -> V_70 = 0 ;
if ( V_62 -> V_71 ) {
F_4 ( V_66 , V_72 ) ;
return 0 ;
}
F_38 ( V_62 ) ;
V_62 -> V_73 = V_62 -> V_65 -> V_73 ;
V_62 -> V_74 = V_62 -> V_73 ;
V_62 -> V_75 = V_76 ;
F_39 ( V_62 -> V_77 ) ;
V_62 -> V_77 = NULL ;
F_32 ( V_62 ) ;
V_62 -> V_78 = 0 ;
V_62 -> V_20 . V_26 = - 1 ;
V_62 -> V_20 . V_27 = - 1 ;
V_23 ( V_62 -> V_20 . V_24 ) ;
V_62 -> V_20 . V_24 = NULL ;
V_62 -> V_20 . V_25 = NULL ;
F_40 ( V_62 -> V_79 , NULL ) ;
if ( ! F_41 ( V_62 ) && ( V_62 -> V_68 == NULL )
&& ( V_62 -> V_65 != V_62 -> V_32 -> V_65 ) ) {
V_62 -> V_65 -> V_80 ( V_62 ) ;
V_62 -> V_65 = V_62 -> V_32 -> V_65 ;
if ( ! V_62 -> V_65 -> V_81 ( V_62 ) )
return ( 0 ) ;
} else
V_62 -> V_65 -> V_82 ( V_62 ) ;
F_42 ( & V_62 -> V_83 ) ;
return ( 1 ) ;
}
int F_43 ( T_9 * V_32 , const T_10 * V_84 )
{
F_44 ( V_85 ) * V_86 ;
V_32 -> V_65 = V_84 ;
V_86 = F_45 ( V_32 -> V_65 , & ( V_32 -> V_87 ) ,
& ( V_32 -> V_88 ) ,
V_89 , V_32 -> V_52 ) ;
if ( ( V_86 == NULL ) || ( F_46 ( V_86 ) <= 0 ) ) {
F_4 ( V_90 , V_91 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
T_6 * F_47 ( T_9 * V_32 )
{
T_6 * V_62 ;
if ( V_32 == NULL ) {
F_4 ( V_92 , V_93 ) ;
return ( NULL ) ;
}
if ( V_32 -> V_65 == NULL ) {
F_4 ( V_92 , V_94 ) ;
return ( NULL ) ;
}
V_62 = F_2 ( sizeof( * V_62 ) ) ;
if ( V_62 == NULL )
goto V_95;
V_62 -> V_96 = F_48 () ;
if ( V_62 -> V_96 == NULL ) {
F_4 ( V_92 , V_10 ) ;
F_3 ( V_62 ) ;
return NULL ;
}
F_49 ( & V_62 -> V_83 , V_62 ) ;
V_62 -> V_97 = V_32 -> V_97 ;
V_62 -> V_20 . V_31 = V_32 -> V_20 . V_31 ;
V_62 -> V_98 = V_32 -> V_98 ;
V_62 -> V_99 = V_32 -> V_99 ;
V_62 -> V_100 = V_32 -> V_100 ;
V_62 -> V_101 = V_32 -> V_101 ;
V_62 -> V_102 = 1 ;
V_62 -> V_52 = F_50 ( V_32 -> V_52 ) ;
if ( V_62 -> V_52 == NULL )
goto V_95;
F_51 ( & V_62 -> V_83 , V_32 -> V_103 ) ;
V_62 -> V_104 = V_32 -> V_104 ;
V_62 -> V_105 = V_32 -> V_105 ;
V_62 -> V_106 = V_32 -> V_106 ;
V_62 -> V_107 = V_32 -> V_107 ;
V_62 -> V_108 = V_32 -> V_108 ;
F_52 ( V_62 -> V_108 <= sizeof V_62 -> V_109 ) ;
memcpy ( & V_62 -> V_109 , & V_32 -> V_109 , sizeof( V_62 -> V_109 ) ) ;
V_62 -> V_110 = V_32 -> V_111 ;
V_62 -> V_112 = V_32 -> V_112 ;
V_62 -> V_79 = F_53 () ;
if ( V_62 -> V_79 == NULL )
goto V_95;
F_54 ( V_62 -> V_79 , V_32 -> V_79 ) ;
V_62 -> V_113 = V_32 -> V_113 ;
V_62 -> V_114 = V_32 -> V_114 ;
V_62 -> V_115 = V_32 -> V_115 ;
V_62 -> V_116 = V_32 -> V_116 ;
if ( V_62 -> V_116 > 1 )
F_51 ( & V_62 -> V_83 , 1 ) ;
if ( V_32 -> V_117 > 0 )
F_55 ( V_62 , V_32 -> V_117 ) ;
F_56 ( V_32 ) ;
V_62 -> V_32 = V_32 ;
V_62 -> V_118 = 0 ;
V_62 -> V_119 = NULL ;
V_62 -> V_120 = 0 ;
V_62 -> V_121 = V_32 -> V_121 ;
V_62 -> V_122 = 0 ;
V_62 -> V_123 = NULL ;
V_62 -> V_124 = NULL ;
V_62 -> V_125 = NULL ;
V_62 -> V_126 = - 1 ;
F_56 ( V_32 ) ;
V_62 -> V_127 = V_32 ;
#ifndef F_57
if ( V_32 -> V_128 ) {
V_62 -> V_128 =
F_58 ( V_32 -> V_128 ,
V_32 -> V_129 ) ;
if ( ! V_62 -> V_128 )
goto V_95;
V_62 -> V_129 =
V_32 -> V_129 ;
}
if ( V_32 -> V_130 ) {
V_62 -> V_130 =
F_58 ( V_32 -> V_130 ,
V_32 -> V_131 ) ;
if ( ! V_62 -> V_130 )
goto V_95;
V_62 -> V_131 =
V_32 -> V_131 ;
}
#endif
#ifndef F_59
V_62 -> V_132 = NULL ;
#endif
if ( V_62 -> V_32 -> V_133 ) {
V_62 -> V_133 =
F_24 ( V_62 -> V_32 -> V_134 ) ;
if ( V_62 -> V_133 == NULL )
goto V_95;
memcpy ( V_62 -> V_133 , V_62 -> V_32 -> V_133 ,
V_62 -> V_32 -> V_134 ) ;
V_62 -> V_134 = V_62 -> V_32 -> V_134 ;
}
V_62 -> V_135 = NULL ;
V_62 -> V_136 = V_137 ;
V_62 -> V_138 = V_32 -> V_138 ;
V_62 -> V_139 = V_32 -> V_139 ;
V_62 -> V_65 = V_32 -> V_65 ;
if ( ! V_62 -> V_65 -> V_81 ( V_62 ) )
goto V_95;
V_62 -> V_140 = ( V_32 -> V_65 -> V_141 == V_142 ) ? 0 : 1 ;
if ( ! F_35 ( V_62 ) )
goto V_95;
if ( ! F_60 ( V_143 , V_62 , & V_62 -> V_144 ) )
goto V_95;
#ifndef F_61
V_62 -> V_145 = V_32 -> V_145 ;
V_62 -> V_146 = V_32 -> V_146 ;
#endif
V_62 -> V_147 = NULL ;
#ifndef F_62
if ( ! F_63 ( V_62 , V_32 -> V_148 ,
V_32 -> V_149 ) )
goto V_95;
#endif
return V_62 ;
V_95:
F_64 ( V_62 ) ;
F_4 ( V_92 , V_10 ) ;
return NULL ;
}
int F_65 ( const T_6 * V_62 )
{
return F_66 ( V_62 ) ? 1 : 0 ;
}
int F_67 ( T_6 * V_62 )
{
int V_8 ;
if ( F_68 ( & V_62 -> V_102 , 1 , & V_8 , V_62 -> V_96 ) <= 0 )
return 0 ;
F_69 ( L_1 , V_62 ) ;
F_70 ( V_8 < 2 ) ;
return ( ( V_8 > 1 ) ? 1 : 0 ) ;
}
int F_71 ( T_9 * V_32 , const unsigned char * V_109 ,
unsigned int V_150 )
{
if ( V_150 > sizeof V_32 -> V_109 ) {
F_4 ( V_151 ,
V_152 ) ;
return 0 ;
}
V_32 -> V_108 = V_150 ;
memcpy ( V_32 -> V_109 , V_109 , V_150 ) ;
return 1 ;
}
int F_72 ( T_6 * V_153 , const unsigned char * V_109 ,
unsigned int V_150 )
{
if ( V_150 > V_154 ) {
F_4 ( V_155 ,
V_152 ) ;
return 0 ;
}
V_153 -> V_108 = V_150 ;
memcpy ( V_153 -> V_109 , V_109 , V_150 ) ;
return 1 ;
}
int F_73 ( T_9 * V_32 , T_11 V_156 )
{
F_74 ( V_32 -> V_96 ) ;
V_32 -> V_112 = V_156 ;
F_75 ( V_32 -> V_96 ) ;
return 1 ;
}
int F_76 ( T_6 * V_153 , T_11 V_156 )
{
F_74 ( V_153 -> V_96 ) ;
V_153 -> V_112 = V_156 ;
F_75 ( V_153 -> V_96 ) ;
return 1 ;
}
int F_77 ( const T_6 * V_153 , const unsigned char * V_157 ,
unsigned int V_158 )
{
T_12 V_159 , * V_51 ;
if ( V_158 > sizeof V_159 . V_160 )
return 0 ;
V_159 . V_161 = V_153 -> V_73 ;
V_159 . V_162 = V_158 ;
memcpy ( V_159 . V_160 , V_157 , V_158 ) ;
F_78 ( V_153 -> V_163 -> V_96 ) ;
V_51 = F_79 ( V_153 -> V_163 -> V_164 , & V_159 ) ;
F_75 ( V_153 -> V_163 -> V_96 ) ;
return ( V_51 != NULL ) ;
}
int F_80 ( T_9 * V_62 , int V_165 )
{
return F_81 ( V_62 -> V_79 , V_165 ) ;
}
int F_82 ( T_6 * V_62 , int V_165 )
{
return F_81 ( V_62 -> V_79 , V_165 ) ;
}
int F_83 ( T_9 * V_62 , int V_166 )
{
return F_84 ( V_62 -> V_79 , V_166 ) ;
}
int F_85 ( T_6 * V_62 , int V_166 )
{
return F_84 ( V_62 -> V_79 , V_166 ) ;
}
int F_86 ( T_6 * V_62 , const char * V_167 )
{
return F_87 ( V_62 -> V_79 , V_167 , 0 ) ;
}
int F_88 ( T_6 * V_62 , const char * V_167 )
{
return F_89 ( V_62 -> V_79 , V_167 , 0 ) ;
}
void F_90 ( T_6 * V_62 , unsigned int V_31 )
{
F_91 ( V_62 -> V_79 , V_31 ) ;
}
const char * F_92 ( T_6 * V_62 )
{
return F_93 ( V_62 -> V_79 ) ;
}
int F_94 ( T_9 * V_32 )
{
return F_1 ( & V_32 -> V_20 ) ;
}
unsigned long F_95 ( T_9 * V_32 , unsigned long V_31 )
{
unsigned long V_168 = V_32 -> V_20 . V_31 ;
V_32 -> V_20 . V_31 |= V_31 ;
return V_168 ;
}
unsigned long F_96 ( T_9 * V_32 , unsigned long V_31 )
{
unsigned long V_168 = V_32 -> V_20 . V_31 ;
V_32 -> V_20 . V_31 &= ~ V_31 ;
return V_168 ;
}
int F_97 ( T_6 * V_62 , const char * V_169 )
{
T_5 * V_20 = & V_62 -> V_20 ;
if ( V_62 -> V_32 -> V_20 . V_5 == 0 ) {
F_4 ( V_170 , V_171 ) ;
return 0 ;
}
if ( V_20 -> V_21 != NULL ) {
F_4 ( V_170 , V_172 ) ;
return 0 ;
}
if ( V_62 -> V_173 == NULL ) {
if ( ! F_98 ( V_62 , V_169 ) ) {
F_4 ( V_170 , V_174 ) ;
return - 1 ;
}
}
if ( ! F_87 ( V_62 -> V_79 , V_169 , 0 ) ) {
F_4 ( V_170 , V_174 ) ;
return - 1 ;
}
V_20 -> V_26 = - 1 ;
V_20 -> V_27 = - 1 ;
V_20 -> V_2 = & V_62 -> V_32 -> V_20 ;
V_20 -> V_21 = F_15 () ;
if ( V_20 -> V_21 == NULL ) {
F_4 ( V_170 , V_10 ) ;
return - 1 ;
}
return 1 ;
}
unsigned long F_99 ( T_6 * V_153 , unsigned long V_31 )
{
unsigned long V_168 = V_153 -> V_20 . V_31 ;
V_153 -> V_20 . V_31 |= V_31 ;
return V_168 ;
}
unsigned long F_100 ( T_6 * V_153 , unsigned long V_31 )
{
unsigned long V_168 = V_153 -> V_20 . V_31 ;
V_153 -> V_20 . V_31 &= ~ V_31 ;
return V_168 ;
}
int F_101 ( T_6 * V_62 , T_7 * * V_24 , T_8 * * V_175 )
{
T_5 * V_20 = & V_62 -> V_20 ;
if ( ! F_14 ( V_20 ) || V_62 -> V_136 != V_137 )
return - 1 ;
if ( V_20 -> V_25 ) {
if ( V_24 )
* V_24 = V_20 -> V_24 ;
if ( V_175 )
* V_175 = ( V_20 -> V_24 == NULL ) ? V_20 -> V_25 -> V_19 : NULL ;
}
return V_20 -> V_26 ;
}
int F_102 ( T_6 * V_62 , T_2 * V_34 , T_2 * V_35 ,
T_2 * V_15 , unsigned const char * * V_18 , T_3 * V_36 )
{
T_5 * V_20 = & V_62 -> V_20 ;
if ( ! F_14 ( V_20 ) || V_62 -> V_136 != V_137 )
return - 1 ;
if ( V_20 -> V_25 ) {
if ( V_34 )
* V_34 = V_20 -> V_25 -> V_34 ;
if ( V_35 )
* V_35 = V_20 -> V_25 -> V_35 ;
if ( V_15 )
* V_15 = V_20 -> V_25 -> V_15 ;
if ( V_18 )
* V_18 = V_20 -> V_25 -> V_18 ;
if ( V_36 )
* V_36 = V_20 -> V_25 -> V_36 ;
}
return V_20 -> V_26 ;
}
T_5 * F_103 ( T_6 * V_62 )
{
return & V_62 -> V_20 ;
}
int F_18 ( T_6 * V_62 , T_2 V_34 , T_2 V_35 ,
T_2 V_15 , unsigned char * V_18 , T_3 V_36 )
{
return F_22 ( & V_62 -> V_20 , V_34 , V_35 , V_15 , V_18 , V_36 ) ;
}
int F_104 ( T_9 * V_32 , const T_1 * V_12 , T_2 V_15 ,
T_2 V_16 )
{
return F_19 ( & V_32 -> V_20 , V_12 , V_15 , V_16 ) ;
}
int F_105 ( T_9 * V_32 , T_13 * V_176 )
{
return F_106 ( V_32 -> V_79 , V_176 ) ;
}
int F_107 ( T_6 * V_153 , T_13 * V_176 )
{
return F_106 ( V_153 -> V_79 , V_176 ) ;
}
T_13 * F_108 ( T_9 * V_32 )
{
return V_32 -> V_79 ;
}
T_13 * F_109 ( T_6 * V_153 )
{
return V_153 -> V_79 ;
}
void F_110 ( T_6 * V_62 )
{
F_111 ( V_62 -> V_52 ) ;
}
void F_64 ( T_6 * V_62 )
{
int V_8 ;
if ( V_62 == NULL )
return;
F_68 ( & V_62 -> V_102 , - 1 , & V_8 , V_62 -> V_96 ) ;
F_69 ( L_1 , V_62 ) ;
if ( V_8 > 0 )
return;
F_70 ( V_8 < 0 ) ;
F_112 ( V_62 -> V_79 ) ;
F_10 ( & V_62 -> V_20 ) ;
F_113 ( V_143 , V_62 , & V_62 -> V_144 ) ;
F_114 ( V_62 ) ;
F_115 ( V_62 -> V_177 ) ;
F_115 ( V_62 -> V_178 ) ;
F_39 ( V_62 -> V_77 ) ;
F_116 ( V_62 -> V_87 ) ;
F_116 ( V_62 -> V_88 ) ;
if ( V_62 -> V_68 != NULL ) {
F_36 ( V_62 ) ;
F_37 ( V_62 -> V_68 ) ;
}
F_32 ( V_62 ) ;
F_117 ( V_62 -> V_52 ) ;
F_3 ( V_62 -> V_173 ) ;
F_118 ( V_62 -> V_127 ) ;
#ifndef F_57
F_3 ( V_62 -> V_128 ) ;
F_3 ( V_62 -> V_130 ) ;
#endif
F_119 ( V_62 -> V_124 , V_179 ) ;
#ifndef F_120
F_121 ( V_62 -> V_123 , V_180 ) ;
#endif
#ifndef F_62
F_122 ( V_62 -> V_181 ) ;
F_3 ( V_62 -> V_182 ) ;
#endif
F_3 ( V_62 -> V_125 ) ;
F_3 ( V_62 -> V_133 ) ;
F_123 ( V_62 -> V_183 , V_184 ) ;
F_12 ( V_62 -> V_135 , V_23 ) ;
if ( V_62 -> V_65 != NULL )
V_62 -> V_65 -> V_80 ( V_62 ) ;
F_124 ( & V_62 -> V_83 ) ;
F_118 ( V_62 -> V_32 ) ;
F_125 ( V_62 -> V_185 ) ;
#if ! F_126 ( F_59 )
F_3 ( V_62 -> V_132 ) ;
#endif
#ifndef F_127
F_128 ( V_62 -> V_186 ) ;
#endif
F_129 ( V_62 -> V_96 ) ;
F_3 ( V_62 ) ;
}
void F_130 ( T_6 * V_62 , T_14 * V_178 )
{
F_115 ( V_62 -> V_178 ) ;
V_62 -> V_178 = V_178 ;
}
void F_131 ( T_6 * V_62 , T_14 * V_177 )
{
if ( V_62 -> V_187 != NULL )
V_62 -> V_177 = F_132 ( V_62 -> V_177 ) ;
F_115 ( V_62 -> V_177 ) ;
V_62 -> V_177 = V_177 ;
if ( V_62 -> V_187 != NULL )
V_62 -> V_177 = F_133 ( V_62 -> V_187 , V_62 -> V_177 ) ;
}
void F_134 ( T_6 * V_62 , T_14 * V_178 , T_14 * V_177 )
{
if ( V_178 == F_135 ( V_62 ) && V_177 == F_136 ( V_62 ) )
return;
if ( V_178 != NULL && V_178 == V_177 )
F_137 ( V_178 ) ;
if ( V_178 == F_135 ( V_62 ) ) {
F_131 ( V_62 , V_177 ) ;
return;
}
if ( V_177 == F_136 ( V_62 ) && F_135 ( V_62 ) != F_136 ( V_62 ) ) {
F_130 ( V_62 , V_178 ) ;
return;
}
F_130 ( V_62 , V_178 ) ;
F_131 ( V_62 , V_177 ) ;
}
T_14 * F_135 ( const T_6 * V_62 )
{
return V_62 -> V_178 ;
}
T_14 * F_136 ( const T_6 * V_62 )
{
if ( V_62 -> V_187 != NULL ) {
return F_138 ( V_62 -> V_187 ) ;
}
return V_62 -> V_177 ;
}
int F_139 ( const T_6 * V_62 )
{
return F_140 ( V_62 ) ;
}
int F_140 ( const T_6 * V_62 )
{
int V_188 = - 1 ;
T_14 * V_189 , * V_159 ;
V_189 = F_135 ( V_62 ) ;
V_159 = F_141 ( V_189 , V_190 ) ;
if ( V_159 != NULL )
F_142 ( V_159 , & V_188 ) ;
return ( V_188 ) ;
}
int F_143 ( const T_6 * V_62 )
{
int V_188 = - 1 ;
T_14 * V_189 , * V_159 ;
V_189 = F_136 ( V_62 ) ;
V_159 = F_141 ( V_189 , V_190 ) ;
if ( V_159 != NULL )
F_142 ( V_159 , & V_188 ) ;
return ( V_188 ) ;
}
int F_144 ( T_6 * V_62 , int V_191 )
{
int V_188 = 0 ;
T_14 * V_192 = NULL ;
V_192 = F_145 ( F_146 () ) ;
if ( V_192 == NULL ) {
F_4 ( V_193 , V_194 ) ;
goto V_95;
}
F_147 ( V_192 , V_191 , V_195 ) ;
F_134 ( V_62 , V_192 , V_192 ) ;
V_188 = 1 ;
V_95:
return ( V_188 ) ;
}
int F_148 ( T_6 * V_62 , int V_191 )
{
T_14 * V_178 = F_135 ( V_62 ) ;
if ( V_178 == NULL || F_149 ( V_178 ) != V_196
|| ( int ) F_142 ( V_178 , NULL ) != V_191 ) {
T_14 * V_192 = F_145 ( F_146 () ) ;
if ( V_192 == NULL ) {
F_4 ( V_197 , V_194 ) ;
return 0 ;
}
F_147 ( V_192 , V_191 , V_195 ) ;
F_131 ( V_62 , V_192 ) ;
} else {
F_137 ( V_178 ) ;
F_131 ( V_62 , V_178 ) ;
}
return 1 ;
}
int F_150 ( T_6 * V_62 , int V_191 )
{
T_14 * V_177 = F_136 ( V_62 ) ;
if ( V_177 == NULL || F_149 ( V_177 ) != V_196
|| ( ( int ) F_142 ( V_177 , NULL ) != V_191 ) ) {
T_14 * V_192 = F_145 ( F_146 () ) ;
if ( V_192 == NULL ) {
F_4 ( V_198 , V_194 ) ;
return 0 ;
}
F_147 ( V_192 , V_191 , V_195 ) ;
F_130 ( V_62 , V_192 ) ;
} else {
F_137 ( V_177 ) ;
F_130 ( V_62 , V_177 ) ;
}
return 1 ;
}
T_3 F_151 ( const T_6 * V_62 , void * V_199 , T_3 V_200 )
{
T_3 V_188 = 0 ;
if ( V_62 -> V_201 != NULL ) {
V_188 = V_62 -> V_201 -> V_202 . V_203 ;
if ( V_200 > V_188 )
V_200 = V_188 ;
memcpy ( V_199 , V_62 -> V_201 -> V_202 . V_204 , V_200 ) ;
}
return V_188 ;
}
T_3 F_152 ( const T_6 * V_62 , void * V_199 , T_3 V_200 )
{
T_3 V_188 = 0 ;
if ( V_62 -> V_201 != NULL ) {
V_188 = V_62 -> V_201 -> V_202 . V_205 ;
if ( V_200 > V_188 )
V_200 = V_188 ;
memcpy ( V_199 , V_62 -> V_201 -> V_202 . V_206 , V_200 ) ;
}
return V_188 ;
}
int F_153 ( const T_6 * V_62 )
{
return ( V_62 -> V_106 ) ;
}
int F_154 ( const T_6 * V_62 )
{
return F_155 ( V_62 -> V_79 ) ;
}
int F_156 ( const T_9 * V_32 )
{
return ( V_32 -> V_106 ) ;
}
int F_157 ( const T_9 * V_32 )
{
return F_155 ( V_32 -> V_79 ) ;
}
void F_158 ( T_6 * V_62 , int V_100 ,
int (* F_159) ( int V_207 , T_15 * V_32 ) )
{
V_62 -> V_106 = V_100 ;
if ( F_159 != NULL )
V_62 -> V_110 = F_159 ;
}
void F_160 ( T_6 * V_62 , int V_208 )
{
F_161 ( V_62 -> V_79 , V_208 ) ;
}
void F_162 ( T_6 * V_62 , int V_209 )
{
F_51 ( & V_62 -> V_83 , V_209 ) ;
}
int F_163 ( const T_6 * V_62 )
{
return F_164 ( & V_62 -> V_83 ) ;
}
int F_165 ( const T_6 * V_62 )
{
return ( V_62 -> V_65 -> V_210 ( V_62 ) ) ;
}
int F_166 ( const T_6 * V_62 )
{
if ( F_165 ( V_62 ) )
return 1 ;
return F_167 ( & V_62 -> V_83 ) ;
}
T_7 * F_168 ( const T_6 * V_62 )
{
T_7 * V_159 ;
if ( ( V_62 == NULL ) || ( V_62 -> V_68 == NULL ) )
V_159 = NULL ;
else
V_159 = V_62 -> V_68 -> V_211 ;
if ( V_159 == NULL )
return ( V_159 ) ;
F_169 ( V_159 ) ;
return ( V_159 ) ;
}
int F_170 ( const T_9 * V_32 )
{
if ( ( V_32 == NULL ) || ( V_32 -> V_52 -> V_212 -> V_213 == NULL ) ) {
F_4 ( V_214 , V_215 ) ;
return ( 0 ) ;
}
if ( V_32 -> V_52 -> V_212 -> V_216 == NULL ) {
F_4 ( V_214 , V_217 ) ;
return ( 0 ) ;
}
return ( F_171
( V_32 -> V_52 -> V_212 -> V_213 , V_32 -> V_52 -> V_212 -> V_216 ) ) ;
}
int F_172 ( const T_6 * V_153 )
{
if ( V_153 == NULL ) {
F_4 ( V_218 , V_219 ) ;
return ( 0 ) ;
}
if ( V_153 -> V_52 -> V_212 -> V_213 == NULL ) {
F_4 ( V_218 , V_215 ) ;
return ( 0 ) ;
}
if ( V_153 -> V_52 -> V_212 -> V_216 == NULL ) {
F_4 ( V_218 , V_217 ) ;
return ( 0 ) ;
}
return ( F_171 ( V_153 -> V_52 -> V_212 -> V_213 ,
V_153 -> V_52 -> V_212 -> V_216 ) ) ;
}
int F_173 ( T_6 * V_62 )
{
if ( V_62 -> V_147 )
return 1 ;
return 0 ;
}
int F_174 ( T_6 * V_62 , T_16 * V_220 , T_3 * V_221 )
{
T_17 * V_32 = V_62 -> V_185 ;
if ( V_32 == NULL )
return 0 ;
return F_175 ( V_32 , V_220 , V_221 ) ;
}
int F_176 ( T_6 * V_62 , T_16 * V_222 , T_3 * V_223 ,
T_16 * V_224 , T_3 * V_225 )
{
T_17 * V_32 = V_62 -> V_185 ;
if ( V_32 == NULL )
return 0 ;
return F_177 ( V_32 , V_222 , V_223 , V_224 ,
V_225 ) ;
}
int F_178 ( T_6 * V_62 )
{
if ( V_62 -> V_226 == NULL ) {
F_179 ( V_62 ) ;
}
return F_180 ( V_62 ) ;
}
int F_181 ( T_6 * V_62 )
{
if ( V_62 -> V_226 == NULL ) {
F_182 ( V_62 ) ;
}
return F_180 ( V_62 ) ;
}
long F_183 ( const T_6 * V_62 )
{
return ( V_62 -> V_65 -> V_227 () ) ;
}
static int F_184 ( T_6 * V_62 , struct V_228 * args ,
int (* F_185) ( void * ) )
{
int V_188 ;
if ( V_62 -> V_185 == NULL ) {
V_62 -> V_185 = F_186 () ;
if ( V_62 -> V_185 == NULL )
return - 1 ;
}
switch ( F_187 ( & V_62 -> V_147 , V_62 -> V_185 , & V_188 , F_185 , args ,
sizeof( struct V_228 ) ) ) {
case V_229 :
V_62 -> V_75 = V_76 ;
F_4 ( V_230 , V_231 ) ;
return - 1 ;
case V_232 :
V_62 -> V_75 = V_233 ;
return - 1 ;
case V_234 :
V_62 -> V_75 = V_235 ;
return - 1 ;
case V_236 :
V_62 -> V_147 = NULL ;
return V_188 ;
default:
V_62 -> V_75 = V_76 ;
F_4 ( V_230 , V_72 ) ;
return - 1 ;
}
}
static int F_188 ( void * V_237 )
{
struct V_228 * args ;
T_6 * V_62 ;
void * V_199 ;
int V_30 ;
args = (struct V_228 * ) V_237 ;
V_62 = args -> V_62 ;
V_199 = args -> V_199 ;
V_30 = args -> V_30 ;
switch ( args -> type ) {
case V_238 :
return args -> V_239 . V_240 ( V_62 , V_199 , V_30 ) ;
case V_241 :
return args -> V_239 . V_242 ( V_62 , V_199 , V_30 ) ;
case V_243 :
return args -> V_239 . V_244 ( V_62 ) ;
}
return - 1 ;
}
int F_189 ( T_6 * V_62 , void * V_199 , int V_30 )
{
if ( V_62 -> V_226 == NULL ) {
F_4 ( V_245 , V_246 ) ;
return - 1 ;
}
if ( V_62 -> V_70 & V_247 ) {
V_62 -> V_75 = V_76 ;
return ( 0 ) ;
}
if ( ( V_62 -> V_100 & V_248 ) && F_190 () == NULL ) {
struct V_228 args ;
args . V_62 = V_62 ;
args . V_199 = V_199 ;
args . V_30 = V_30 ;
args . type = V_238 ;
args . V_239 . V_240 = V_62 -> V_65 -> V_249 ;
return F_184 ( V_62 , & args , F_188 ) ;
} else {
return V_62 -> V_65 -> V_249 ( V_62 , V_199 , V_30 ) ;
}
}
int F_191 ( T_6 * V_62 , void * V_199 , int V_30 )
{
if ( V_62 -> V_226 == NULL ) {
F_4 ( V_250 , V_246 ) ;
return - 1 ;
}
if ( V_62 -> V_70 & V_247 ) {
return ( 0 ) ;
}
if ( ( V_62 -> V_100 & V_248 ) && F_190 () == NULL ) {
struct V_228 args ;
args . V_62 = V_62 ;
args . V_199 = V_199 ;
args . V_30 = V_30 ;
args . type = V_238 ;
args . V_239 . V_240 = V_62 -> V_65 -> V_251 ;
return F_184 ( V_62 , & args , F_188 ) ;
} else {
return V_62 -> V_65 -> V_251 ( V_62 , V_199 , V_30 ) ;
}
}
int F_192 ( T_6 * V_62 , const void * V_199 , int V_30 )
{
if ( V_62 -> V_226 == NULL ) {
F_4 ( V_252 , V_246 ) ;
return - 1 ;
}
if ( V_62 -> V_70 & V_253 ) {
V_62 -> V_75 = V_76 ;
F_4 ( V_252 , V_254 ) ;
return ( - 1 ) ;
}
if ( ( V_62 -> V_100 & V_248 ) && F_190 () == NULL ) {
struct V_228 args ;
args . V_62 = V_62 ;
args . V_199 = ( void * ) V_199 ;
args . V_30 = V_30 ;
args . type = V_241 ;
args . V_239 . V_242 = V_62 -> V_65 -> V_255 ;
return F_184 ( V_62 , & args , F_188 ) ;
} else {
return V_62 -> V_65 -> V_255 ( V_62 , V_199 , V_30 ) ;
}
}
int F_193 ( T_6 * V_62 )
{
if ( V_62 -> V_226 == NULL ) {
F_4 ( V_256 , V_246 ) ;
return - 1 ;
}
if ( ! F_194 ( V_62 ) ) {
if ( ( V_62 -> V_100 & V_248 ) && F_190 () == NULL ) {
struct V_228 args ;
args . V_62 = V_62 ;
args . type = V_243 ;
args . V_239 . V_244 = V_62 -> V_65 -> V_257 ;
return F_184 ( V_62 , & args , F_188 ) ;
} else {
return V_62 -> V_65 -> V_257 ( V_62 ) ;
}
} else {
F_4 ( V_256 , V_258 ) ;
return - 1 ;
}
}
int F_195 ( T_6 * V_62 )
{
if ( V_62 -> V_71 == 0 )
V_62 -> V_71 = 1 ;
V_62 -> V_259 = 1 ;
return ( V_62 -> V_65 -> V_260 ( V_62 ) ) ;
}
int F_196 ( T_6 * V_62 )
{
if ( V_62 -> V_71 == 0 )
V_62 -> V_71 = 1 ;
V_62 -> V_259 = 0 ;
return ( V_62 -> V_65 -> V_260 ( V_62 ) ) ;
}
int F_197 ( T_6 * V_62 )
{
return ( V_62 -> V_71 != 0 ) ;
}
long F_198 ( T_6 * V_62 , int V_261 , long V_262 , void * V_263 )
{
long V_264 ;
switch ( V_261 ) {
case V_265 :
return ( F_164 ( & V_62 -> V_83 ) ) ;
case V_266 :
V_264 = F_164 ( & V_62 -> V_83 ) ;
F_51 ( & V_62 -> V_83 , V_262 ) ;
return ( V_264 ) ;
case V_267 :
V_62 -> V_105 = V_263 ;
return 1 ;
case V_268 :
return ( V_62 -> V_100 |= V_262 ) ;
case V_269 :
return ( V_62 -> V_100 &= ~ V_262 ) ;
case V_270 :
return ( V_62 -> V_101 ) ;
case V_271 :
V_264 = V_62 -> V_101 ;
V_62 -> V_101 = V_262 ;
return ( V_264 ) ;
case V_272 :
if ( V_262 < 512 || V_262 > V_273 )
return 0 ;
V_62 -> V_114 = V_262 ;
if ( V_62 -> V_114 < V_62 -> V_115 )
V_62 -> V_115 = V_62 -> V_114 ;
return 1 ;
case V_274 :
if ( ( unsigned int ) V_262 > V_62 -> V_114 || V_262 == 0 )
return 0 ;
V_62 -> V_115 = V_262 ;
return 1 ;
case V_275 :
if ( V_262 < 1 || V_262 > V_276 )
return 0 ;
V_62 -> V_116 = V_262 ;
if ( V_262 > 1 )
F_51 ( & V_62 -> V_83 , 1 ) ;
return 1 ;
case V_277 :
if ( V_62 -> V_201 )
return V_62 -> V_201 -> V_278 ;
else
return 0 ;
case V_279 :
return ( V_62 -> V_52 -> V_280 |= V_262 ) ;
case V_281 :
return ( V_62 -> V_52 -> V_280 &= ~ V_262 ) ;
case V_282 :
if ( V_263 ) {
if ( V_62 -> V_201 -> V_202 . V_283 == NULL )
return 0 ;
* ( unsigned char * * ) V_263 = V_62 -> V_201 -> V_202 . V_283 ;
return ( int ) V_62 -> V_201 -> V_202 . V_284 ;
} else {
return V_285 ;
}
case V_286 :
if ( ! V_62 -> V_68 || F_194 ( V_62 ) || F_41 ( V_62 ) )
return - 1 ;
if ( V_62 -> V_68 -> V_31 & V_287 )
return 1 ;
else
return 0 ;
case V_288 :
return F_199 ( V_62 -> V_32 -> V_65 -> V_73 , ( int ) V_262 ,
& V_62 -> V_98 ) ;
case V_289 :
return F_199 ( V_62 -> V_32 -> V_65 -> V_73 , ( int ) V_262 ,
& V_62 -> V_99 ) ;
default:
return ( V_62 -> V_65 -> V_290 ( V_62 , V_261 , V_262 , V_263 ) ) ;
}
}
long F_200 ( T_6 * V_62 , int V_261 , void (* F_201) ( void ) )
{
switch ( V_261 ) {
case V_291 :
V_62 -> V_104 = ( void (*)
( int V_292 , int V_73 , int V_293 ,
const void * V_199 , T_3 V_294 , T_6 * V_153 ,
void * V_295 ) ) ( F_201 ) ;
return 1 ;
default:
return ( V_62 -> V_65 -> V_296 ( V_62 , V_261 , F_201 ) ) ;
}
}
long F_202 ( T_9 * V_32 , int V_261 , long V_262 , void * V_263 )
{
long V_264 ;
if ( V_32 == NULL ) {
switch ( V_261 ) {
#ifndef F_57
case V_297 :
return F_203 ( NULL , NULL , V_263 ) ;
#endif
case V_298 :
case V_299 :
return F_204 ( NULL , V_263 , 0 ) ;
default:
return 0 ;
}
}
switch ( V_261 ) {
case V_265 :
return ( V_32 -> V_103 ) ;
case V_266 :
V_264 = V_32 -> V_103 ;
V_32 -> V_103 = V_262 ;
return ( V_264 ) ;
case V_267 :
V_32 -> V_105 = V_263 ;
return 1 ;
case V_270 :
return ( V_32 -> V_101 ) ;
case V_271 :
V_264 = V_32 -> V_101 ;
V_32 -> V_101 = V_262 ;
return ( V_264 ) ;
case V_300 :
V_264 = V_32 -> V_301 ;
V_32 -> V_301 = V_262 ;
return ( V_264 ) ;
case V_302 :
return ( V_32 -> V_301 ) ;
case V_303 :
V_264 = V_32 -> V_304 ;
V_32 -> V_304 = V_262 ;
return ( V_264 ) ;
case V_305 :
return ( V_32 -> V_304 ) ;
case V_306 :
return ( F_205 ( V_32 -> V_164 ) ) ;
case V_307 :
return ( V_32 -> V_308 . V_309 ) ;
case V_310 :
return ( V_32 -> V_308 . V_311 ) ;
case V_312 :
return ( V_32 -> V_308 . V_313 ) ;
case V_314 :
return ( V_32 -> V_308 . V_315 ) ;
case V_316 :
return ( V_32 -> V_308 . V_317 ) ;
case V_318 :
return ( V_32 -> V_308 . V_319 ) ;
case V_320 :
return ( V_32 -> V_308 . V_321 ) ;
case V_322 :
return ( V_32 -> V_308 . V_323 ) ;
case V_324 :
return ( V_32 -> V_308 . V_325 ) ;
case V_326 :
return ( V_32 -> V_308 . V_327 ) ;
case V_328 :
return ( V_32 -> V_308 . V_329 ) ;
case V_268 :
return ( V_32 -> V_100 |= V_262 ) ;
case V_269 :
return ( V_32 -> V_100 &= ~ V_262 ) ;
case V_272 :
if ( V_262 < 512 || V_262 > V_273 )
return 0 ;
V_32 -> V_114 = V_262 ;
if ( V_32 -> V_114 < V_32 -> V_115 )
V_32 -> V_115 = V_32 -> V_114 ;
return 1 ;
case V_274 :
if ( ( unsigned int ) V_262 > V_32 -> V_114 || V_262 == 0 )
return 0 ;
V_32 -> V_115 = V_262 ;
return 1 ;
case V_275 :
if ( V_262 < 1 || V_262 > V_276 )
return 0 ;
V_32 -> V_116 = V_262 ;
return 1 ;
case V_279 :
return ( V_32 -> V_52 -> V_280 |= V_262 ) ;
case V_281 :
return ( V_32 -> V_52 -> V_280 &= ~ V_262 ) ;
case V_288 :
return F_199 ( V_32 -> V_65 -> V_73 , ( int ) V_262 ,
& V_32 -> V_98 ) ;
case V_289 :
return F_199 ( V_32 -> V_65 -> V_73 , ( int ) V_262 ,
& V_32 -> V_99 ) ;
default:
return ( V_32 -> V_65 -> V_330 ( V_32 , V_261 , V_262 , V_263 ) ) ;
}
}
long F_206 ( T_9 * V_32 , int V_261 , void (* F_201) ( void ) )
{
switch ( V_261 ) {
case V_291 :
V_32 -> V_104 = ( void (*)
( int V_292 , int V_73 , int V_293 ,
const void * V_199 , T_3 V_294 , T_6 * V_153 ,
void * V_295 ) ) ( F_201 ) ;
return 1 ;
default:
return ( V_32 -> V_65 -> V_331 ( V_32 , V_261 , F_201 ) ) ;
}
}
int F_207 ( const V_85 * V_332 , const V_85 * V_189 )
{
if ( V_332 -> V_157 > V_189 -> V_157 )
return 1 ;
if ( V_332 -> V_157 < V_189 -> V_157 )
return - 1 ;
return 0 ;
}
int F_208 ( const V_85 * const * V_333 ,
const V_85 * const * V_334 )
{
if ( ( * V_333 ) -> V_157 > ( * V_334 ) -> V_157 )
return 1 ;
if ( ( * V_333 ) -> V_157 < ( * V_334 ) -> V_157 )
return - 1 ;
return 0 ;
}
char * F_209 ( const T_6 * V_62 , int V_7 )
{
const V_85 * V_335 ;
F_44 ( V_85 ) * V_86 ;
if ( V_62 == NULL )
return ( NULL ) ;
V_86 = F_210 ( V_62 ) ;
if ( ( V_86 == NULL ) || ( F_46 ( V_86 ) <= V_7 ) )
return ( NULL ) ;
V_335 = F_211 ( V_86 , V_7 ) ;
if ( V_335 == NULL )
return ( NULL ) ;
return ( V_335 -> V_336 ) ;
}
int F_212 ( T_6 * V_62 , const char * V_337 )
{
F_44 ( V_85 ) * V_86 ;
V_86 = F_45 ( V_62 -> V_32 -> V_65 , & V_62 -> V_87 ,
& V_62 -> V_88 , V_337 , V_62 -> V_52 ) ;
if ( V_86 == NULL )
return 0 ;
else if ( F_46 ( V_86 ) == 0 ) {
F_4 ( V_338 , V_339 ) ;
return 0 ;
}
return 1 ;
}
char * F_213 ( const T_6 * V_62 , char * V_199 , int V_294 )
{
char * V_51 ;
F_44 ( V_85 ) * V_86 ;
const V_85 * V_335 ;
int V_8 ;
if ( ( V_62 -> V_68 == NULL ) || ( V_62 -> V_68 -> V_340 == NULL ) || ( V_294 < 2 ) )
return ( NULL ) ;
V_51 = V_199 ;
V_86 = V_62 -> V_68 -> V_340 ;
if ( F_46 ( V_86 ) == 0 )
return NULL ;
for ( V_8 = 0 ; V_8 < F_46 ( V_86 ) ; V_8 ++ ) {
int V_7 ;
V_335 = F_211 ( V_86 , V_8 ) ;
V_7 = strlen ( V_335 -> V_336 ) ;
if ( V_7 + 1 > V_294 ) {
if ( V_51 != V_199 )
-- V_51 ;
* V_51 = '\0' ;
return V_199 ;
}
memcpy ( V_51 , V_335 -> V_336 , V_7 + 1 ) ;
V_51 += V_7 ;
* ( V_51 ++ ) = ':' ;
V_294 -= V_7 + 1 ;
}
V_51 [ - 1 ] = '\0' ;
return ( V_199 ) ;
}
const char * F_214 ( const T_6 * V_62 , const int type )
{
if ( type != V_341 )
return NULL ;
return V_62 -> V_68 && ! V_62 -> V_173 ?
V_62 -> V_68 -> V_173 : V_62 -> V_173 ;
}
int F_215 ( const T_6 * V_62 )
{
if ( V_62 -> V_68
&& ( ! V_62 -> V_173 ? V_62 -> V_68 ->
V_173 : V_62 -> V_173 ) )
return V_341 ;
return - 1 ;
}
int F_216 ( unsigned char * * V_342 , unsigned char * V_343 ,
const unsigned char * V_140 ,
unsigned int V_344 ,
const unsigned char * V_345 , unsigned int V_346 )
{
unsigned int V_8 , V_347 ;
const unsigned char * V_348 ;
int V_349 = V_350 ;
for ( V_8 = 0 ; V_8 < V_344 ; ) {
for ( V_347 = 0 ; V_347 < V_346 ; ) {
if ( V_140 [ V_8 ] == V_345 [ V_347 ] &&
memcmp ( & V_140 [ V_8 + 1 ] , & V_345 [ V_347 + 1 ] , V_140 [ V_8 ] ) == 0 ) {
V_348 = & V_140 [ V_8 ] ;
V_349 = V_351 ;
goto V_352;
}
V_347 += V_345 [ V_347 ] ;
V_347 ++ ;
}
V_8 += V_140 [ V_8 ] ;
V_8 ++ ;
}
V_348 = V_345 ;
V_349 = V_353 ;
V_352:
* V_342 = ( unsigned char * ) V_348 + 1 ;
* V_343 = V_348 [ 0 ] ;
return V_349 ;
}
void F_217 ( const T_6 * V_62 , const unsigned char * * V_18 ,
unsigned * V_294 )
{
* V_18 = V_62 -> V_132 ;
if ( ! * V_18 ) {
* V_294 = 0 ;
} else {
* V_294 = V_62 -> V_354 ;
}
}
void F_218 ( T_9 * V_32 ,
int (* V_156) ( T_6 * V_153 ,
const unsigned char
* * V_342 ,
unsigned int * V_343 ,
void * V_295 ) , void * V_295 )
{
V_32 -> V_355 = V_156 ;
V_32 -> V_356 = V_295 ;
}
void F_219 ( T_9 * V_32 ,
int (* V_156) ( T_6 * V_62 , unsigned char * * V_342 ,
unsigned char * V_343 ,
const unsigned char * V_357 ,
unsigned int V_358 ,
void * V_295 ) , void * V_295 )
{
V_32 -> V_359 = V_156 ;
V_32 -> V_360 = V_295 ;
}
int F_220 ( T_9 * V_32 , const unsigned char * V_361 ,
unsigned int V_362 )
{
F_3 ( V_32 -> V_133 ) ;
V_32 -> V_133 = F_58 ( V_361 , V_362 ) ;
if ( V_32 -> V_133 == NULL ) {
F_4 ( V_363 , V_10 ) ;
return 1 ;
}
V_32 -> V_134 = V_362 ;
return 0 ;
}
int F_221 ( T_6 * V_153 , const unsigned char * V_361 ,
unsigned int V_362 )
{
F_3 ( V_153 -> V_133 ) ;
V_153 -> V_133 = F_58 ( V_361 , V_362 ) ;
if ( V_153 -> V_133 == NULL ) {
F_4 ( V_364 , V_10 ) ;
return 1 ;
}
V_153 -> V_134 = V_362 ;
return 0 ;
}
void F_222 ( T_9 * V_32 ,
int (* V_156) ( T_6 * V_153 ,
const unsigned char * * V_342 ,
unsigned char * V_343 ,
const unsigned char * V_357 ,
unsigned int V_358 ,
void * V_295 ) , void * V_295 )
{
V_32 -> V_365 = V_156 ;
V_32 -> V_366 = V_295 ;
}
void F_223 ( const T_6 * V_153 , const unsigned char * * V_18 ,
unsigned int * V_294 )
{
* V_18 = NULL ;
if ( V_153 -> V_201 )
* V_18 = V_153 -> V_201 -> V_367 ;
if ( * V_18 == NULL )
* V_294 = 0 ;
else
* V_294 = V_153 -> V_201 -> V_368 ;
}
int F_224 ( T_6 * V_62 , unsigned char * V_342 , T_3 V_369 ,
const char * V_370 , T_3 V_371 ,
const unsigned char * V_51 , T_3 V_372 ,
int V_373 )
{
if ( V_62 -> V_73 < V_374 && V_62 -> V_73 != V_375 )
return - 1 ;
return V_62 -> V_65 -> V_376 -> V_377 ( V_62 , V_342 , V_369 , V_370 ,
V_371 , V_51 , V_372 ,
V_373 ) ;
}
static unsigned long F_225 ( const T_12 * V_332 )
{
unsigned long V_264 ;
V_264 = ( unsigned long )
( ( unsigned int ) V_332 -> V_160 [ 0 ] ) |
( ( unsigned int ) V_332 -> V_160 [ 1 ] << 8L ) |
( ( unsigned long ) V_332 -> V_160 [ 2 ] << 16L ) |
( ( unsigned long ) V_332 -> V_160 [ 3 ] << 24L ) ;
return ( V_264 ) ;
}
static int F_226 ( const T_12 * V_332 , const T_12 * V_189 )
{
if ( V_332 -> V_161 != V_189 -> V_161 )
return ( 1 ) ;
if ( V_332 -> V_162 != V_189 -> V_162 )
return ( 1 ) ;
return ( memcmp ( V_332 -> V_160 , V_189 -> V_160 , V_332 -> V_162 ) ) ;
}
T_9 * F_227 ( const T_10 * V_84 )
{
T_9 * V_188 = NULL ;
if ( V_84 == NULL ) {
F_4 ( V_378 , V_379 ) ;
return ( NULL ) ;
}
if ( ! F_228 ( V_380 , NULL ) )
return NULL ;
if ( F_229 () && ( V_84 -> V_73 < V_374 ) ) {
F_4 ( V_378 , V_381 ) ;
return NULL ;
}
if ( F_230 () < 0 ) {
F_4 ( V_378 , V_382 ) ;
goto V_95;
}
V_188 = F_2 ( sizeof( * V_188 ) ) ;
if ( V_188 == NULL )
goto V_95;
V_188 -> V_65 = V_84 ;
V_188 -> V_98 = 0 ;
V_188 -> V_99 = 0 ;
V_188 -> V_304 = V_383 ;
V_188 -> V_301 = V_384 ;
V_188 -> V_385 = V_84 -> V_227 () ;
V_188 -> V_102 = 1 ;
V_188 -> V_96 = F_48 () ;
if ( V_188 -> V_96 == NULL ) {
F_4 ( V_378 , V_10 ) ;
F_3 ( V_188 ) ;
return NULL ;
}
V_188 -> V_101 = V_386 ;
V_188 -> V_106 = V_387 ;
if ( ( V_188 -> V_52 = F_231 () ) == NULL )
goto V_95;
V_188 -> V_164 = F_232 ( F_225 , F_226 ) ;
if ( V_188 -> V_164 == NULL )
goto V_95;
V_188 -> V_388 = F_233 () ;
if ( V_188 -> V_388 == NULL )
goto V_95;
#ifndef F_62
V_188 -> V_389 = F_234 () ;
if ( V_188 -> V_389 == NULL )
goto V_95;
#endif
if ( ! F_45 ( V_188 -> V_65 ,
& V_188 -> V_87 , & V_188 -> V_88 ,
V_89 , V_188 -> V_52 )
|| F_46 ( V_188 -> V_87 ) <= 0 ) {
F_4 ( V_378 , V_390 ) ;
goto V_391;
}
V_188 -> V_79 = F_53 () ;
if ( V_188 -> V_79 == NULL )
goto V_95;
if ( ( V_188 -> V_392 = F_235 ( L_2 ) ) == NULL ) {
F_4 ( V_378 , V_393 ) ;
goto V_391;
}
if ( ( V_188 -> V_394 = F_235 ( L_3 ) ) == NULL ) {
F_4 ( V_378 , V_395 ) ;
goto V_391;
}
if ( ( V_188 -> V_183 = F_236 () ) == NULL )
goto V_95;
if ( ! F_60 ( V_396 , V_188 , & V_188 -> V_144 ) )
goto V_95;
if ( ! ( V_84 -> V_376 -> V_397 & V_398 ) )
V_188 -> V_399 = F_237 () ;
V_188 -> V_114 = V_273 ;
V_188 -> V_115 = V_273 ;
if ( ( F_238 ( V_188 -> V_400 ,
sizeof( V_188 -> V_400 ) ) <= 0 )
|| ( F_238 ( V_188 -> V_401 ,
sizeof( V_188 -> V_401 ) ) <= 0 )
|| ( F_238 ( V_188 -> V_402 ,
sizeof( V_188 -> V_402 ) ) <= 0 ) )
V_188 -> V_97 |= V_403 ;
#ifndef F_239
if ( ! F_240 ( V_188 ) )
goto V_95;
#endif
#ifndef F_241
# ifdef F_242
# define F_243 ( T_18 ) #x
# define F_244 ( T_18 ) eng_strx(x)
{
T_19 * V_404 ;
V_404 = F_245 ( F_244 ( F_242 ) ) ;
if ( ! V_404 ) {
F_246 () ;
F_247 () ;
V_404 = F_245 ( F_244 ( F_242 ) ) ;
}
if ( ! V_404 || ! F_248 ( V_188 , V_404 ) )
F_246 () ;
}
# endif
#endif
V_188 -> V_97 |= V_405 ;
V_188 -> V_97 |= V_406 ;
V_188 -> V_121 = - 1 ;
return V_188 ;
V_95:
F_4 ( V_378 , V_10 ) ;
V_391:
F_118 ( V_188 ) ;
return NULL ;
}
int F_56 ( T_9 * V_32 )
{
int V_8 ;
if ( F_68 ( & V_32 -> V_102 , 1 , & V_8 , V_32 -> V_96 ) <= 0 )
return 0 ;
F_69 ( L_4 , V_32 ) ;
F_70 ( V_8 < 2 ) ;
return ( ( V_8 > 1 ) ? 1 : 0 ) ;
}
void F_118 ( T_9 * V_332 )
{
int V_8 ;
if ( V_332 == NULL )
return;
F_68 ( & V_332 -> V_102 , - 1 , & V_8 , V_332 -> V_96 ) ;
F_69 ( L_4 , V_332 ) ;
if ( V_8 > 0 )
return;
F_70 ( V_8 < 0 ) ;
F_112 ( V_332 -> V_79 ) ;
F_7 ( & V_332 -> V_20 ) ;
if ( V_332 -> V_164 != NULL )
F_249 ( V_332 , 0 ) ;
F_113 ( V_396 , V_332 , & V_332 -> V_144 ) ;
F_250 ( V_332 -> V_164 ) ;
F_251 ( V_332 -> V_388 ) ;
#ifndef F_62
F_252 ( V_332 -> V_389 ) ;
#endif
F_116 ( V_332 -> V_87 ) ;
F_116 ( V_332 -> V_88 ) ;
F_117 ( V_332 -> V_52 ) ;
F_123 ( V_332 -> V_183 , V_184 ) ;
F_12 ( V_332 -> V_407 , V_23 ) ;
V_332 -> V_399 = NULL ;
#ifndef F_127
F_128 ( V_332 -> V_186 ) ;
#endif
#ifndef F_239
F_253 ( V_332 ) ;
#endif
#ifndef F_241
F_254 ( V_332 -> V_408 ) ;
#endif
#ifndef F_57
F_3 ( V_332 -> V_128 ) ;
F_3 ( V_332 -> V_130 ) ;
#endif
F_3 ( V_332 -> V_133 ) ;
F_129 ( V_332 -> V_96 ) ;
F_3 ( V_332 ) ;
}
void F_255 ( T_9 * V_32 , T_20 * V_156 )
{
V_32 -> V_138 = V_156 ;
}
void F_256 ( T_9 * V_32 , void * V_409 )
{
V_32 -> V_139 = V_409 ;
}
T_20 * F_257 ( T_9 * V_32 )
{
return V_32 -> V_138 ;
}
void * F_258 ( T_9 * V_32 )
{
return V_32 -> V_139 ;
}
void F_259 ( T_6 * V_62 , T_20 * V_156 )
{
V_62 -> V_138 = V_156 ;
}
void F_260 ( T_6 * V_62 , void * V_409 )
{
V_62 -> V_139 = V_409 ;
}
T_20 * F_261 ( T_6 * V_62 )
{
return V_62 -> V_138 ;
}
void * F_262 ( T_6 * V_62 )
{
return V_62 -> V_139 ;
}
void F_263 ( T_9 * V_32 ,
int (* V_156) ( T_15 * , void * ) ,
void * V_295 )
{
V_32 -> V_410 = V_156 ;
V_32 -> V_411 = V_295 ;
}
void F_264 ( T_9 * V_32 , int V_100 ,
int (* V_156) ( int , T_15 * ) )
{
V_32 -> V_106 = V_100 ;
V_32 -> V_111 = V_156 ;
}
void F_265 ( T_9 * V_32 , int V_208 )
{
F_161 ( V_32 -> V_79 , V_208 ) ;
}
void F_266 ( T_9 * V_335 , int (* V_156) ( T_6 * V_153 , void * V_295 ) , void * V_295 )
{
F_267 ( V_335 -> V_52 , V_156 , V_295 ) ;
}
void F_268 ( T_6 * V_62 , int (* V_156) ( T_6 * V_153 , void * V_295 ) , void * V_295 )
{
F_267 ( V_62 -> V_52 , V_156 , V_295 ) ;
}
void F_269 ( T_6 * V_62 )
{
#if ! F_126 ( F_57 ) || ! F_126 ( V_412 )
T_21 * V_413 ;
#endif
T_22 * V_335 = V_62 -> V_52 ;
T_23 * V_414 = V_62 -> V_201 -> V_202 . V_415 ;
int V_416 , V_417 , V_418 , V_419 ;
unsigned long V_420 , V_421 ;
#ifndef F_57
int V_422 , V_423 ;
T_7 * T_18 = NULL ;
#endif
if ( V_335 == NULL )
return;
#ifndef F_270
V_418 = ( V_335 -> V_418 != NULL || V_335 -> V_424 != NULL || V_335 -> V_425 ) ;
#else
V_418 = 0 ;
#endif
V_416 = V_414 [ V_426 ] & V_427 ;
V_417 = V_414 [ V_428 ] & V_429 ;
V_419 = V_414 [ V_430 ] & V_429 ;
#ifndef F_57
V_422 = V_414 [ V_431 ] & V_427 ;
#endif
V_420 = 0 ;
V_421 = 0 ;
#ifdef F_271
fprintf ( V_432 , L_5 ,
V_418 , V_416 , V_417 , V_419 ) ;
#endif
#ifndef V_412
V_413 = & ( V_335 -> V_433 [ V_434 ] ) ;
if ( V_413 -> V_213 != NULL && V_413 -> V_216 != NULL ) {
V_420 |= V_435 ;
V_421 |= V_436 ;
}
V_413 = & ( V_335 -> V_433 [ V_437 ] ) ;
if ( V_413 -> V_213 != NULL && V_413 -> V_216 != NULL ) {
V_420 |= V_435 ;
V_421 |= V_436 ;
}
V_413 = & ( V_335 -> V_433 [ V_438 ] ) ;
if ( V_413 -> V_213 != NULL && V_413 -> V_216 != NULL ) {
V_420 |= V_435 ;
V_421 |= V_439 ;
}
#endif
if ( V_416 )
V_420 |= V_440 ;
if ( V_418 )
V_420 |= V_441 ;
if ( V_416 || V_417 ) {
V_421 |= V_442 ;
}
if ( V_419 ) {
V_421 |= V_443 ;
}
V_421 |= V_444 ;
#ifndef F_57
if ( V_422 ) {
T_23 V_445 ;
V_413 = & V_335 -> V_433 [ V_431 ] ;
T_18 = V_413 -> V_213 ;
V_445 = F_272 ( T_18 ) ;
V_423 = V_445 & V_446 ;
if ( ! ( V_414 [ V_431 ] & V_429 ) )
V_423 = 0 ;
if ( V_423 )
V_421 |= V_447 ;
}
#endif
#ifndef F_57
V_420 |= V_448 ;
#endif
#ifndef F_61
V_420 |= V_449 ;
V_421 |= V_450 ;
if ( V_420 & V_440 )
V_420 |= V_451 ;
if ( V_420 & V_441 )
V_420 |= V_452 ;
if ( V_420 & V_448 )
V_420 |= V_453 ;
#endif
V_62 -> V_201 -> V_202 . V_420 = V_420 ;
V_62 -> V_201 -> V_202 . V_421 = V_421 ;
}
int F_273 ( T_7 * T_18 , T_6 * V_62 )
{
if ( V_62 -> V_201 -> V_202 . V_454 -> V_455 & V_447 ) {
if ( ! ( F_272 ( T_18 ) & V_446 ) ) {
F_4 ( V_456 ,
V_457 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_274 ( const T_6 * V_62 )
{
int V_458 ;
V_458 = F_275 ( V_62 -> V_201 -> V_202 . V_454 ) ;
if ( V_458 == V_426 && ! V_62 -> V_52 -> V_433 [ V_426 ] . V_213 )
V_458 = V_428 ;
if ( V_458 == V_459 ) {
if ( V_62 -> V_52 -> V_433 [ V_434 ] . V_213 )
V_458 = V_434 ;
else if ( V_62 -> V_52 -> V_433 [ V_437 ] . V_213 )
V_458 = V_437 ;
else if ( V_62 -> V_52 -> V_433 [ V_438 ] . V_213 )
V_458 = V_438 ;
else
V_458 = - 1 ;
}
if ( V_458 == - 1 )
F_4 ( V_460 , V_72 ) ;
return V_458 ;
}
T_21 * F_276 ( T_6 * V_62 )
{
T_22 * V_335 ;
int V_8 ;
V_335 = V_62 -> V_52 ;
if ( ! V_62 -> V_201 || ! V_62 -> V_201 -> V_202 . V_454 )
return NULL ;
F_269 ( V_62 ) ;
V_8 = F_274 ( V_62 ) ;
if ( V_8 < 0 )
return NULL ;
return & V_335 -> V_433 [ V_8 ] ;
}
T_8 * F_277 ( T_6 * V_62 , const V_85 * V_461 ,
const T_1 * * V_462 )
{
unsigned long V_463 ;
T_22 * V_335 ;
int V_458 = - 1 ;
V_463 = V_461 -> V_455 ;
V_335 = V_62 -> V_52 ;
if ( ( V_463 & V_443 ) && ( V_335 -> V_433 [ V_430 ] . V_216 != NULL ) )
V_458 = V_430 ;
else if ( V_463 & V_442 ) {
if ( V_335 -> V_433 [ V_428 ] . V_216 != NULL )
V_458 = V_428 ;
else if ( V_335 -> V_433 [ V_426 ] . V_216 != NULL )
V_458 = V_426 ;
} else if ( ( V_463 & V_447 ) &&
( V_335 -> V_433 [ V_431 ] . V_216 != NULL ) )
V_458 = V_431 ;
if ( V_458 == - 1 ) {
F_4 ( V_464 , V_72 ) ;
return ( NULL ) ;
}
if ( V_462 )
* V_462 = V_62 -> V_201 -> V_202 . V_12 [ V_458 ] ;
return V_335 -> V_433 [ V_458 ] . V_216 ;
}
int F_278 ( T_6 * V_62 , const unsigned char * * V_465 ,
T_3 * V_466 )
{
T_22 * V_335 = NULL ;
int V_8 = 0 ;
* V_466 = 0 ;
V_335 = V_62 -> V_52 ;
V_8 = F_274 ( V_62 ) ;
if ( V_8 == - 1 )
return 0 ;
if ( V_335 -> V_433 [ V_8 ] . V_465 == NULL )
return 0 ;
* V_465 = V_335 -> V_433 [ V_8 ] . V_465 ;
* V_466 = V_335 -> V_433 [ V_8 ] . V_466 ;
return 1 ;
}
void F_279 ( T_6 * V_62 , int V_100 )
{
int V_8 ;
if ( V_62 -> V_68 -> V_162 == 0 )
return;
V_8 = V_62 -> V_163 -> V_304 ;
if ( ( V_8 & V_100 ) && ( ! V_62 -> V_69 )
&& ( ( V_8 & V_467 )
|| F_280 ( V_62 -> V_163 , V_62 -> V_68 ) )
&& ( V_62 -> V_163 -> V_468 != NULL ) ) {
F_281 ( V_62 -> V_68 ) ;
if ( ! V_62 -> V_163 -> V_468 ( V_62 , V_62 -> V_68 ) )
F_37 ( V_62 -> V_68 ) ;
}
if ( ( ! ( V_8 & V_469 ) ) && ( ( V_8 & V_100 ) == V_100 ) ) {
if ( ( ( ( V_100 & V_470 )
? V_62 -> V_163 -> V_308 . V_311
: V_62 -> V_163 -> V_308 . V_317 ) & 0xff ) == 0xff ) {
F_249 ( V_62 -> V_163 , ( unsigned long ) time ( NULL ) ) ;
}
}
}
const T_10 * F_282 ( T_9 * V_32 )
{
return V_32 -> V_65 ;
}
const T_10 * F_283 ( T_6 * V_62 )
{
return ( V_62 -> V_65 ) ;
}
int F_284 ( T_6 * V_62 , const T_10 * V_84 )
{
int V_188 = 1 ;
if ( V_62 -> V_65 != V_84 ) {
const T_10 * V_471 = V_62 -> V_65 ;
int (* F_285) ( T_6 * ) = V_62 -> V_226 ;
if ( V_471 -> V_73 == V_84 -> V_73 )
V_62 -> V_65 = V_84 ;
else {
V_471 -> V_80 ( V_62 ) ;
V_62 -> V_65 = V_84 ;
V_188 = V_62 -> V_65 -> V_81 ( V_62 ) ;
}
if ( F_285 == V_471 -> V_472 )
V_62 -> V_226 = V_84 -> V_472 ;
else if ( F_285 == V_471 -> V_141 )
V_62 -> V_226 = V_84 -> V_141 ;
}
return ( V_188 ) ;
}
int F_286 ( const T_6 * V_62 , int V_8 )
{
int V_473 ;
unsigned long V_264 ;
T_14 * V_192 ;
if ( V_8 > 0 )
return ( V_474 ) ;
if ( ( V_264 = F_287 () ) != 0 ) {
if ( F_288 ( V_264 ) == V_475 )
return ( V_476 ) ;
else
return ( V_477 ) ;
}
if ( V_8 < 0 ) {
if ( F_289 ( V_62 ) ) {
V_192 = F_135 ( V_62 ) ;
if ( F_290 ( V_192 ) )
return ( V_478 ) ;
else if ( F_291 ( V_192 ) )
return ( V_479 ) ;
else if ( F_292 ( V_192 ) ) {
V_473 = F_293 ( V_192 ) ;
if ( V_473 == V_480 )
return ( V_481 ) ;
else if ( V_473 == V_482 )
return ( V_483 ) ;
else
return ( V_476 ) ;
}
}
if ( F_294 ( V_62 ) ) {
V_192 = V_62 -> V_177 ;
if ( F_291 ( V_192 ) )
return ( V_479 ) ;
else if ( F_290 ( V_192 ) )
return ( V_478 ) ;
else if ( F_292 ( V_192 ) ) {
V_473 = F_293 ( V_192 ) ;
if ( V_473 == V_480 )
return ( V_481 ) ;
else if ( V_473 == V_482 )
return ( V_483 ) ;
else
return ( V_476 ) ;
}
}
if ( F_295 ( V_62 ) ) {
return ( V_484 ) ;
}
if ( F_296 ( V_62 ) ) {
return V_485 ;
}
if ( F_297 ( V_62 ) ) {
return V_486 ;
}
}
if ( V_8 == 0 ) {
if ( ( V_62 -> V_70 & V_247 ) &&
( V_62 -> V_201 -> V_487 == V_488 ) )
return ( V_489 ) ;
}
return ( V_476 ) ;
}
static int F_298 ( void * V_237 )
{
struct V_228 * args ;
T_6 * V_62 ;
args = (struct V_228 * ) V_237 ;
V_62 = args -> V_62 ;
return V_62 -> V_226 ( V_62 ) ;
}
int F_180 ( T_6 * V_62 )
{
int V_188 = 1 ;
if ( V_62 -> V_226 == NULL ) {
F_4 ( V_490 , V_491 ) ;
return - 1 ;
}
V_62 -> V_65 -> V_492 ( V_62 ) ;
if ( F_194 ( V_62 ) || F_299 ( V_62 ) ) {
if ( ( V_62 -> V_100 & V_248 ) && F_190 () == NULL ) {
struct V_228 args ;
args . V_62 = V_62 ;
V_188 = F_184 ( V_62 , & args , F_298 ) ;
} else {
V_188 = V_62 -> V_226 ( V_62 ) ;
}
}
return V_188 ;
}
void F_179 ( T_6 * V_62 )
{
V_62 -> V_140 = 1 ;
V_62 -> V_70 = 0 ;
F_38 ( V_62 ) ;
V_62 -> V_226 = V_62 -> V_65 -> V_141 ;
F_32 ( V_62 ) ;
}
void F_182 ( T_6 * V_62 )
{
V_62 -> V_140 = 0 ;
V_62 -> V_70 = 0 ;
F_38 ( V_62 ) ;
V_62 -> V_226 = V_62 -> V_65 -> V_472 ;
F_32 ( V_62 ) ;
}
int V_142 ( T_6 * V_62 )
{
F_4 ( V_493 , V_494 ) ;
return ( 0 ) ;
}
int F_300 ( void )
{
F_4 ( V_495 ,
V_494 ) ;
return ( 0 ) ;
}
int F_301 ( const T_6 * V_62 )
{
return ( 0 ) ;
}
const T_10 * F_302 ( int V_496 )
{
F_4 ( V_497 , V_494 ) ;
return ( NULL ) ;
}
const char * F_303 ( int V_73 )
{
if ( V_73 == V_498 )
return L_6 ;
else if ( V_73 == V_499 )
return L_7 ;
else if ( V_73 == V_374 )
return L_8 ;
else if ( V_73 == V_500 )
return L_9 ;
else if ( V_73 == V_375 )
return L_10 ;
else if ( V_73 == V_501 )
return L_11 ;
else if ( V_73 == V_502 )
return L_12 ;
else
return ( L_13 ) ;
}
const char * F_304 ( const T_6 * V_62 )
{
return F_303 ( V_62 -> V_73 ) ;
}
T_6 * F_305 ( T_6 * V_62 )
{
F_44 ( V_503 ) * V_86 ;
V_503 * V_504 ;
T_6 * V_188 ;
int V_8 ;
if ( ! F_194 ( V_62 ) || ! F_299 ( V_62 ) ) {
F_68 ( & V_62 -> V_102 , 1 , & V_8 , V_62 -> V_96 ) ;
return V_62 ;
}
if ( ( V_188 = F_47 ( F_306 ( V_62 ) ) ) == NULL )
return ( NULL ) ;
if ( V_62 -> V_68 != NULL ) {
if ( ! F_307 ( V_188 , V_62 ) )
goto V_95;
} else {
if ( ! F_284 ( V_188 , V_62 -> V_65 ) )
goto V_95;
if ( V_62 -> V_52 != NULL ) {
F_117 ( V_188 -> V_52 ) ;
V_188 -> V_52 = F_50 ( V_62 -> V_52 ) ;
if ( V_188 -> V_52 == NULL )
goto V_95;
}
if ( ! F_72 ( V_188 , V_62 -> V_109 , V_62 -> V_108 ) )
goto V_95;
}
if ( ! F_13 ( V_188 , V_62 ) )
goto V_95;
V_188 -> V_73 = V_62 -> V_73 ;
V_188 -> V_97 = V_62 -> V_97 ;
V_188 -> V_100 = V_62 -> V_100 ;
F_308 ( V_188 , F_309 ( V_62 ) ) ;
F_162 ( V_188 , F_163 ( V_62 ) ) ;
V_188 -> V_104 = V_62 -> V_104 ;
V_188 -> V_105 = V_62 -> V_105 ;
F_158 ( V_188 , F_153 ( V_62 ) , F_310 ( V_62 ) ) ;
F_160 ( V_188 , F_154 ( V_62 ) ) ;
V_188 -> V_112 = V_62 -> V_112 ;
F_311 ( V_188 , F_312 ( V_62 ) ) ;
if ( ! F_313 ( V_143 , & V_188 -> V_144 , & V_62 -> V_144 ) )
goto V_95;
if ( V_62 -> V_178 != NULL ) {
if ( ! F_314 ( V_62 -> V_178 , ( char * ) & V_188 -> V_178 ) )
goto V_95;
}
if ( V_62 -> V_177 != NULL ) {
if ( V_62 -> V_177 != V_62 -> V_178 ) {
if ( ! F_314 ( V_62 -> V_177 , ( char * ) & V_188 -> V_177 ) )
goto V_95;
} else {
F_137 ( V_188 -> V_178 ) ;
V_188 -> V_177 = V_188 -> V_178 ;
}
}
V_188 -> V_140 = V_62 -> V_140 ;
if ( V_62 -> V_226 ) {
if ( V_62 -> V_140 )
F_179 ( V_188 ) ;
else
F_182 ( V_188 ) ;
}
V_188 -> V_70 = V_62 -> V_70 ;
V_188 -> V_69 = V_62 -> V_69 ;
V_188 -> V_138 = V_62 -> V_138 ;
V_188 -> V_139 = V_62 -> V_139 ;
F_54 ( V_188 -> V_79 , V_62 -> V_79 ) ;
if ( V_62 -> V_87 != NULL ) {
if ( ( V_188 -> V_87 = F_315 ( V_62 -> V_87 ) ) == NULL )
goto V_95;
}
if ( V_62 -> V_88 != NULL )
if ( ( V_188 -> V_88 = F_315 ( V_62 -> V_88 ) )
== NULL )
goto V_95;
if ( V_62 -> V_183 != NULL ) {
if ( ( V_86 = F_316 ( V_62 -> V_183 ) ) == NULL )
goto V_95;
V_188 -> V_183 = V_86 ;
for ( V_8 = 0 ; V_8 < F_317 ( V_86 ) ; V_8 ++ ) {
V_504 = F_318 ( V_86 , V_8 ) ;
if ( F_319 ( V_86 , V_8 , F_320 ( V_504 ) ) == NULL ) {
V_184 ( V_504 ) ;
goto V_95;
}
}
}
return V_188 ;
V_95:
F_64 ( V_188 ) ;
return NULL ;
}
void F_33 ( T_6 * V_62 )
{
if ( V_62 -> V_505 != NULL ) {
F_321 ( V_62 -> V_505 ) ;
V_62 -> V_505 = NULL ;
}
if ( V_62 -> V_506 != NULL ) {
F_321 ( V_62 -> V_506 ) ;
V_62 -> V_506 = NULL ;
}
#ifndef F_322
F_323 ( V_62 -> V_507 ) ;
V_62 -> V_507 = NULL ;
F_323 ( V_62 -> V_508 ) ;
V_62 -> V_508 = NULL ;
#endif
}
T_7 * F_324 ( const T_6 * V_62 )
{
if ( V_62 -> V_52 != NULL )
return ( V_62 -> V_52 -> V_212 -> V_213 ) ;
else
return ( NULL ) ;
}
T_8 * F_325 ( const T_6 * V_62 )
{
if ( V_62 -> V_52 != NULL )
return ( V_62 -> V_52 -> V_212 -> V_216 ) ;
else
return ( NULL ) ;
}
T_7 * F_326 ( const T_9 * V_32 )
{
if ( V_32 -> V_52 != NULL )
return V_32 -> V_52 -> V_212 -> V_213 ;
else
return NULL ;
}
T_8 * F_327 ( const T_9 * V_32 )
{
if ( V_32 -> V_52 != NULL )
return V_32 -> V_52 -> V_212 -> V_216 ;
else
return NULL ;
}
const V_85 * F_328 ( const T_6 * V_62 )
{
if ( ( V_62 -> V_68 != NULL ) && ( V_62 -> V_68 -> V_461 != NULL ) )
return ( V_62 -> V_68 -> V_461 ) ;
return ( NULL ) ;
}
const T_24 * F_329 ( T_6 * V_62 )
{
#ifndef F_322
return V_62 -> V_508 ? F_330 ( V_62 -> V_508 ) : NULL ;
#else
return NULL ;
#endif
}
const T_24 * F_331 ( T_6 * V_62 )
{
#ifndef F_322
return V_62 -> V_507 ? F_330 ( V_62 -> V_507 ) : NULL ;
#else
return NULL ;
#endif
}
int F_332 ( T_6 * V_62 )
{
T_14 * V_187 ;
if ( V_62 -> V_187 != NULL ) {
return 1 ;
}
V_187 = F_145 ( F_333 () ) ;
if ( V_187 == NULL || ! F_334 ( V_187 , 1 ) ) {
F_335 ( V_187 ) ;
F_4 ( V_509 , V_194 ) ;
return 0 ;
}
V_62 -> V_187 = V_187 ;
V_62 -> V_177 = F_133 ( V_187 , V_62 -> V_177 ) ;
return 1 ;
}
void F_114 ( T_6 * V_62 )
{
if ( V_62 -> V_187 == NULL )
return;
V_62 -> V_177 = F_132 ( V_62 -> V_177 ) ;
assert ( V_62 -> V_177 != NULL ) ;
F_335 ( V_62 -> V_187 ) ;
V_62 -> V_187 = NULL ;
}
void F_336 ( T_9 * V_32 , int V_100 )
{
V_32 -> V_113 = V_100 ;
}
int F_337 ( const T_9 * V_32 )
{
return ( V_32 -> V_113 ) ;
}
void F_338 ( T_6 * V_62 , int V_100 )
{
V_62 -> V_113 = V_100 ;
}
int F_339 ( const T_6 * V_62 )
{
return ( V_62 -> V_113 ) ;
}
void F_340 ( T_6 * V_62 , int V_100 )
{
V_62 -> V_70 = V_100 ;
}
int F_341 ( const T_6 * V_62 )
{
return V_62 -> V_70 ;
}
int F_342 ( const T_6 * V_62 )
{
return V_62 -> V_73 ;
}
int F_343 ( const T_6 * V_62 )
{
return V_62 -> V_74 ;
}
T_9 * F_306 ( const T_6 * V_153 )
{
return V_153 -> V_32 ;
}
T_9 * F_344 ( T_6 * V_153 , T_9 * V_32 )
{
T_22 * V_510 ;
if ( V_153 -> V_32 == V_32 )
return V_153 -> V_32 ;
if ( V_32 == NULL )
V_32 = V_153 -> V_127 ;
V_510 = F_50 ( V_32 -> V_52 ) ;
if ( V_510 == NULL ) {
return NULL ;
}
F_117 ( V_153 -> V_52 ) ;
V_153 -> V_52 = V_510 ;
F_52 ( V_153 -> V_108 <= sizeof( V_153 -> V_109 ) ) ;
if ( ( V_153 -> V_32 != NULL ) &&
( V_153 -> V_108 == V_153 -> V_32 -> V_108 ) &&
( memcmp ( V_153 -> V_109 , V_153 -> V_32 -> V_109 , V_153 -> V_108 ) == 0 ) ) {
V_153 -> V_108 = V_32 -> V_108 ;
memcpy ( & V_153 -> V_109 , & V_32 -> V_109 , sizeof( V_153 -> V_109 ) ) ;
}
F_56 ( V_32 ) ;
F_118 ( V_153 -> V_32 ) ;
V_153 -> V_32 = V_32 ;
return V_153 -> V_32 ;
}
int F_345 ( T_9 * V_32 )
{
return ( F_346 ( V_32 -> V_388 ) ) ;
}
int F_347 ( T_9 * V_32 )
{
T_25 * V_511 ;
V_511 = F_348 ( V_32 -> V_388 , F_349 () ) ;
if ( V_511 == NULL )
return 0 ;
F_350 ( V_511 , NULL , V_512 ) ;
F_246 () ;
return 1 ;
}
int F_351 ( T_9 * V_32 )
{
T_25 * V_511 ;
V_511 = F_348 ( V_32 -> V_388 , F_352 () ) ;
if ( V_511 == NULL )
return 0 ;
F_353 ( V_511 , NULL , V_512 ) ;
F_246 () ;
return 1 ;
}
int F_354 ( T_9 * V_32 , const char * V_513 ,
const char * V_514 )
{
return ( F_355 ( V_32 -> V_388 , V_513 , V_514 ) ) ;
}
void F_311 ( T_6 * V_153 ,
void (* V_156) ( const T_6 * V_153 , int type , int V_515 ) )
{
V_153 -> V_516 = V_156 ;
}
void F_356 ( T_6 * V_153 , long V_295 )
{
V_153 -> V_136 = V_295 ;
}
long F_357 ( const T_6 * V_153 )
{
return ( V_153 -> V_136 ) ;
}
T_3 F_358 ( const T_6 * V_153 , unsigned char * V_342 , T_3 V_343 )
{
if ( V_343 == 0 )
return sizeof( V_153 -> V_201 -> V_517 ) ;
if ( V_343 > sizeof( V_153 -> V_201 -> V_517 ) )
V_343 = sizeof( V_153 -> V_201 -> V_517 ) ;
memcpy ( V_342 , V_153 -> V_201 -> V_517 , V_343 ) ;
return V_343 ;
}
T_3 F_359 ( const T_6 * V_153 , unsigned char * V_342 , T_3 V_343 )
{
if ( V_343 == 0 )
return sizeof( V_153 -> V_201 -> V_518 ) ;
if ( V_343 > sizeof( V_153 -> V_201 -> V_518 ) )
V_343 = sizeof( V_153 -> V_201 -> V_518 ) ;
memcpy ( V_342 , V_153 -> V_201 -> V_518 , V_343 ) ;
return V_343 ;
}
T_3 F_360 ( const T_12 * V_68 ,
unsigned char * V_342 , T_3 V_343 )
{
if ( V_68 -> V_519 < 0 ) {
return 0 ;
}
if ( V_343 == 0 )
return V_68 -> V_519 ;
if ( V_343 > ( T_3 ) V_68 -> V_519 )
V_343 = V_68 -> V_519 ;
memcpy ( V_342 , V_68 -> V_520 , V_343 ) ;
return V_343 ;
}
int F_361 ( T_6 * V_62 , int V_458 , void * V_295 )
{
return ( F_362 ( & V_62 -> V_144 , V_458 , V_295 ) ) ;
}
void * F_363 ( const T_6 * V_62 , int V_458 )
{
return ( F_364 ( & V_62 -> V_144 , V_458 ) ) ;
}
int F_365 ( T_9 * V_62 , int V_458 , void * V_295 )
{
return ( F_362 ( & V_62 -> V_144 , V_458 , V_295 ) ) ;
}
void * F_366 ( const T_9 * V_62 , int V_458 )
{
return ( F_364 ( & V_62 -> V_144 , V_458 ) ) ;
}
int F_367 ( T_6 * V_62 )
{
return ( 1 ) ;
}
T_26 * F_368 ( const T_9 * V_32 )
{
return ( V_32 -> V_388 ) ;
}
void F_369 ( T_9 * V_32 , T_26 * V_521 )
{
F_251 ( V_32 -> V_388 ) ;
V_32 -> V_388 = V_521 ;
}
int F_370 ( const T_6 * V_62 )
{
return ( V_62 -> V_75 ) ;
}
void F_371 ( T_9 * V_32 ,
T_27 * (* F_372) ( T_6 * V_153 , int V_522 ,
int V_523 ) )
{
F_206 ( V_32 , V_524 , ( void ( * ) ( void ) ) F_372 ) ;
}
void F_373 ( T_6 * V_153 , T_27 * (* F_372) ( T_6 * V_153 , int V_522 ,
int V_523 ) )
{
F_200 ( V_153 , V_524 , ( void ( * ) ( void ) ) F_372 ) ;
}
int F_374 ( T_9 * V_32 , const char * V_525 )
{
if ( V_525 != NULL && strlen ( V_525 ) > V_526 ) {
F_4 ( V_527 , V_528 ) ;
return 0 ;
}
F_3 ( V_32 -> V_52 -> V_529 ) ;
if ( V_525 != NULL ) {
V_32 -> V_52 -> V_529 = F_375 ( V_525 ) ;
if ( V_32 -> V_52 -> V_529 == NULL )
return 0 ;
} else
V_32 -> V_52 -> V_529 = NULL ;
return 1 ;
}
int F_376 ( T_6 * V_62 , const char * V_525 )
{
if ( V_62 == NULL )
return 0 ;
if ( V_525 != NULL && strlen ( V_525 ) > V_526 ) {
F_4 ( V_530 , V_528 ) ;
return 0 ;
}
F_3 ( V_62 -> V_52 -> V_529 ) ;
if ( V_525 != NULL ) {
V_62 -> V_52 -> V_529 = F_375 ( V_525 ) ;
if ( V_62 -> V_52 -> V_529 == NULL )
return 0 ;
} else
V_62 -> V_52 -> V_529 = NULL ;
return 1 ;
}
const char * F_377 ( const T_6 * V_62 )
{
if ( V_62 == NULL || V_62 -> V_68 == NULL )
return NULL ;
return ( V_62 -> V_68 -> V_529 ) ;
}
const char * F_378 ( const T_6 * V_62 )
{
if ( V_62 == NULL || V_62 -> V_68 == NULL )
return NULL ;
return ( V_62 -> V_68 -> V_531 ) ;
}
void F_379 ( T_9 * V_32 ,
void (* V_156) ( int V_292 , int V_73 ,
int V_293 , const void * V_199 ,
T_3 V_294 , T_6 * V_153 , void * V_295 ) )
{
F_206 ( V_32 , V_291 , ( void ( * ) ( void ) ) V_156 ) ;
}
void F_380 ( T_6 * V_153 ,
void (* V_156) ( int V_292 , int V_73 ,
int V_293 , const void * V_199 ,
T_3 V_294 , T_6 * V_153 , void * V_295 ) )
{
F_200 ( V_153 , V_291 , ( void ( * ) ( void ) ) V_156 ) ;
}
void F_381 ( T_9 * V_32 ,
int (* V_156) ( T_6 * V_153 ,
int
V_532 ) )
{
F_206 ( V_32 , V_533 ,
( void ( * ) ( void ) ) V_156 ) ;
}
void F_382 ( T_6 * V_153 ,
int (* V_156) ( T_6 * V_153 ,
int V_532 ) )
{
F_200 ( V_153 , V_533 ,
( void ( * ) ( void ) ) V_156 ) ;
}
T_28 * F_383 ( T_28 * * V_534 , const T_1 * V_12 )
{
F_34 ( V_534 ) ;
* V_534 = F_384 () ;
if ( * V_534 == NULL || ( V_12 && F_385 ( * V_534 , V_12 , NULL ) <= 0 ) ) {
F_386 ( * V_534 ) ;
* V_534 = NULL ;
return NULL ;
}
return * V_534 ;
}
void F_34 ( T_28 * * V_534 )
{
if ( * V_534 )
F_386 ( * V_534 ) ;
* V_534 = NULL ;
}
int F_387 ( T_6 * V_62 , unsigned char * V_342 , int V_343 )
{
T_28 * V_32 = NULL ;
T_28 * V_535 = V_62 -> V_201 -> V_536 ;
int V_188 = F_388 ( V_535 ) ;
if ( V_188 < 0 || V_188 > V_343 ) {
V_188 = 0 ;
goto V_95;
}
V_32 = F_384 () ;
if ( V_32 == NULL ) {
V_188 = 0 ;
goto V_95;
}
if ( ! F_389 ( V_32 , V_535 )
|| F_390 ( V_32 , V_342 , NULL ) <= 0 )
V_188 = 0 ;
V_95:
F_386 ( V_32 ) ;
return V_188 ;
}
int F_391 ( T_6 * V_62 )
{
return V_62 -> V_69 ;
}
int F_392 ( T_6 * V_62 )
{
return V_62 -> V_140 ;
}
void F_393 ( T_6 * V_62 , int V_537 )
{
( void ) V_62 ;
( void ) V_537 ;
}
void F_394 ( T_6 * V_62 , int V_538 )
{
V_62 -> V_52 -> V_539 = V_538 ;
}
int F_395 ( const T_6 * V_62 )
{
return V_62 -> V_52 -> V_539 ;
}
void F_396 ( T_6 * V_62 ,
int (* V_156) ( const T_6 * V_62 , const T_9 * V_32 ,
int V_540 , int V_541 , int V_13 ,
void * V_542 , void * V_543 ) )
{
V_62 -> V_52 -> V_544 = V_156 ;
}
void F_397 ( T_6 * V_62 , void * V_543 )
{
V_62 -> V_52 -> V_545 = V_543 ;
}
void * F_398 ( const T_6 * V_62 )
{
return V_62 -> V_52 -> V_545 ;
}
void F_399 ( T_9 * V_32 , int V_538 )
{
V_32 -> V_52 -> V_539 = V_538 ;
}
int F_400 ( const T_9 * V_32 )
{
return V_32 -> V_52 -> V_539 ;
}
void F_401 ( T_9 * V_32 ,
int (* V_156) ( const T_6 * V_62 , const T_9 * V_32 ,
int V_540 , int V_541 , int V_13 ,
void * V_542 , void * V_543 ) )
{
V_32 -> V_52 -> V_544 = V_156 ;
}
void F_402 ( T_9 * V_32 , void * V_543 )
{
V_32 -> V_52 -> V_545 = V_543 ;
}
void * F_403 ( const T_9 * V_32 )
{
return V_32 -> V_52 -> V_545 ;
}
unsigned long F_404 ( const T_9 * V_32 )
{
return V_32 -> V_97 ;
}
unsigned long F_405 ( const T_6 * V_62 )
{
return V_62 -> V_97 ;
}
unsigned long F_406 ( T_9 * V_32 , unsigned long V_540 )
{
return V_32 -> V_97 |= V_540 ;
}
unsigned long F_407 ( T_6 * V_62 , unsigned long V_540 )
{
return V_62 -> V_97 |= V_540 ;
}
unsigned long F_408 ( T_9 * V_32 , unsigned long V_540 )
{
return V_32 -> V_97 &= ~ V_540 ;
}
unsigned long F_409 ( T_6 * V_62 , unsigned long V_540 )
{
return V_62 -> V_97 &= ~ V_540 ;
}
static int F_410 ( T_6 * V_62 )
{
int V_546 = 0 ;
if ( V_62 -> V_182 != NULL ) {
const unsigned char * V_51 = V_62 -> V_182 ;
F_44 ( V_547 ) * V_181 = F_411 ( NULL , & V_51 , V_62 -> V_548 ) ;
V_546 = F_412 ( & V_62 -> V_181 , V_181 , V_549 ) ;
F_122 ( V_181 ) ;
}
return V_546 ;
}
static int F_413 ( T_6 * V_62 )
{
# ifndef F_120
int V_546 = 0 ;
const unsigned char * V_51 ;
T_29 * V_550 = NULL ;
T_30 * V_551 = NULL ;
F_44 ( V_547 ) * V_181 = NULL ;
int V_8 ;
if ( V_62 -> V_125 == NULL || V_62 -> V_126 == 0 )
goto V_95;
V_51 = V_62 -> V_125 ;
V_551 = F_414 ( NULL , & V_51 , V_62 -> V_126 ) ;
if ( V_551 == NULL )
goto V_95;
V_550 = F_415 ( V_551 ) ;
if ( V_550 == NULL )
goto V_95;
for ( V_8 = 0 ; V_8 < F_416 ( V_550 ) ; ++ V_8 ) {
T_31 * V_552 = F_417 ( V_550 , V_8 ) ;
if ( V_552 == NULL )
continue;
V_181 =
F_418 ( V_552 , V_553 , NULL , NULL ) ;
V_546 =
F_412 ( & V_62 -> V_181 , V_181 , V_554 ) ;
if ( V_546 < 0 )
goto V_95;
}
V_95:
F_122 ( V_181 ) ;
F_419 ( V_550 ) ;
F_420 ( V_551 ) ;
return V_546 ;
# else
return 0 ;
# endif
}
static int F_421 ( T_6 * V_62 )
{
int V_546 = 0 ;
T_7 * V_52 = V_62 -> V_68 != NULL ? V_62 -> V_68 -> V_211 : NULL ;
if ( V_52 != NULL ) {
F_44 ( V_547 ) * V_181 =
F_422 ( V_52 , V_555 , NULL , NULL ) ;
V_546 =
F_412 ( & V_62 -> V_181 , V_181 , V_556 ) ;
F_122 ( V_181 ) ;
}
return V_546 ;
}
int F_63 ( T_6 * V_62 , T_32 F_159 ,
void * V_295 )
{
if ( F_159 != NULL && F_423 ( V_62 -> V_32 ,
V_557 ) )
{
F_4 ( V_558 ,
V_559 ) ;
return 0 ;
}
if ( F_159 != NULL ) {
if ( ! F_424 ( V_62 , V_560 ) )
return 0 ;
}
V_62 -> V_148 = F_159 ;
V_62 -> V_149 = V_295 ;
return 1 ;
}
int F_425 ( T_9 * V_32 ,
T_32 F_159 , void * V_295 )
{
if ( F_159 != NULL && F_423 ( V_32 ,
V_557 ) )
{
F_4 ( V_561 ,
V_559 ) ;
return 0 ;
}
V_32 -> V_148 = F_159 ;
V_32 -> V_149 = V_295 ;
return 1 ;
}
int F_426 ( const T_6 * V_62 )
{
return V_62 -> V_148 != NULL ;
}
int F_427 ( const T_9 * V_32 )
{
return V_32 -> V_148 != NULL ;
}
int F_428 ( T_6 * V_62 )
{
int V_188 = 0 ;
T_7 * V_52 = V_62 -> V_68 != NULL ? V_62 -> V_68 -> V_211 : NULL ;
T_7 * V_562 ;
T_5 * V_20 = & V_62 -> V_20 ;
T_33 * V_32 = NULL ;
const F_44 ( V_547 ) * V_181 ;
if ( V_62 -> V_148 == NULL || V_52 == NULL ||
V_62 -> V_136 != V_137 ||
V_62 -> V_135 == NULL || F_429 ( V_62 -> V_135 ) <= 1 )
return 1 ;
if ( F_14 ( V_20 ) && V_20 -> V_25 != NULL ) {
switch ( V_20 -> V_25 -> V_34 ) {
case V_59 :
case V_563 :
return 1 ;
}
}
V_32 = F_430 () ;
if ( V_32 == NULL ) {
F_4 ( V_564 , V_10 ) ;
goto V_565;
}
V_562 = F_431 ( V_62 -> V_135 , 1 ) ;
F_432 ( V_32 , V_52 ) ;
F_433 ( V_32 , V_562 ) ;
F_434 ( V_32 , V_62 -> V_32 -> V_389 ) ;
V_181 = F_435 ( V_62 ) ;
if ( F_436 ( V_181 , V_32 ) < 0 ) {
F_4 ( V_564 , V_566 ) ;
goto V_565;
}
V_188 = V_62 -> V_148 ( V_32 , V_181 , V_62 -> V_149 ) ;
if ( V_188 < 0 )
V_188 = 0 ;
V_565:
F_437 ( V_32 ) ;
if ( V_188 <= 0 )
V_62 -> V_136 = V_567 ;
return V_188 ;
}
int F_438 ( T_9 * V_32 , int V_568 )
{
switch ( V_568 ) {
default:
F_4 ( V_569 , V_570 ) ;
return 0 ;
case V_571 :
return F_425 ( V_32 , V_572 , NULL ) ;
case V_573 :
return F_425 ( V_32 , V_574 , NULL ) ;
}
}
int F_439 ( T_6 * V_62 , int V_568 )
{
switch ( V_568 ) {
default:
F_4 ( V_575 , V_570 ) ;
return 0 ;
case V_571 :
return F_63 ( V_62 , V_572 , NULL ) ;
case V_573 :
return F_63 ( V_62 , V_574 , NULL ) ;
}
}
int F_440 ( T_9 * V_32 )
{
return F_441 ( V_32 -> V_389 ) ;
}
int F_442 ( T_9 * V_32 , const char * V_576 )
{
return F_443 ( V_32 -> V_389 , V_576 ) ;
}
void F_444 ( T_9 * V_32 , T_34 * V_577 )
{
F_252 ( V_32 -> V_389 ) ;
V_32 -> V_389 = V_577 ;
}
const T_34 * F_445 ( const T_9 * V_32 )
{
return V_32 -> V_389 ;
}
