static void
F_1 ( char * V_1 , char * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ,
V_8 ,
V_9 ;
char V_10 [ 80 ] ;
if ( V_3 < V_4 )
V_4 = V_3 ;
for ( V_9 = 0 , V_7 = 0 ; V_7 < V_4 ; V_9 ++ ) {
for ( V_8 = 0 ; V_8 < 16 && V_7 < V_4 ; V_8 ++ , V_7 ++ )
sprintf ( V_10 + V_8 * 3 , L_1 , ( unsigned char ) V_2 [ V_7 ] ) ;
F_2 ( V_11 L_2 , V_5 , V_6 , V_1 , V_9 , V_10 ) ;
}
}
int
F_3 ( T_1 * V_12 )
{
struct V_13 * V_14 ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_3 ,
V_18 , V_12 -> V_15 ) ;
return 0 ;
}
#ifdef F_4
F_5 ( & V_12 -> V_19 -> V_20 -> V_21 ) ;
#endif
F_6 ( V_12 ) ;
#ifdef F_4
if ( V_12 -> V_19 -> V_20 -> V_22 == 1 )
F_7 ( V_12 ) ;
V_12 -> V_19 -> V_20 -> V_22 -- ;
F_8 ( & V_12 -> V_19 -> V_20 -> V_21 ) ;
#endif
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_4 ,
V_18 , V_12 -> V_15 ) ;
return 0 ;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
if ( ( V_14 -> V_24 & V_25 ) )
F_9 ( V_12 -> V_15 ) ;
else if ( V_14 -> V_24 & V_26 )
V_14 -> V_24 = V_27 ;
if ( V_14 -> V_28 & 0x1 )
F_2 ( V_11 L_5 , V_12 -> V_15 , ( long ) V_12 , ( long ) V_14 -> V_12 ) ;
V_14 -> V_12 = NULL ;
V_12 -> V_15 = - 1 ;
return 0 ;
}
int
F_10 ( T_1 * V_12 )
{
int V_9 ;
int V_5 = 0 ;
struct V_13 * V_14 ;
int V_29 ;
if ( V_12 -> V_30 < 0 ) {
T_2 * V_31 = V_32 -> V_19 ;
char V_33 [ V_16 ] ;
memset ( V_33 , 0 , V_16 ) ;
while ( V_31 ) {
T_1 * V_12 = V_31 -> V_34 ;
if ( V_12 -> V_30 >= 0 )
V_33 [ V_12 -> V_30 ] = 1 ;
V_31 = V_31 -> V_35 ;
}
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( V_23 [ V_9 ] -> V_24 == V_27 && ! V_33 [ V_23 [ V_9 ] -> V_36 ] ) {
break;
}
}
} else {
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( V_23 [ V_9 ] -> V_36 == V_12 -> V_30 &&
( V_23 [ V_9 ] -> V_24 & V_27 ) == V_27 )
break;
}
}
if ( V_9 >= V_16 ) {
F_2 ( V_37 L_6 ) ;
V_29 = - 1 ;
goto V_38;
}
V_5 = F_11 ( V_12 -> V_19 -> V_32 -> V_39 ) ;
if ( V_5 < 0 ) {
F_2 ( V_17 L_7 ,
V_12 -> V_19 -> V_32 -> V_39 ) ;
V_29 = - 1 ;
goto V_38;
}
V_12 -> V_15 = V_9 ;
V_14 = V_23 [ V_9 ] ;
V_14 -> V_12 = V_12 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_24 = V_27 | V_26 ;
#ifdef F_4
V_29 = F_12 ( V_12 , NULL ) ;
if ( V_29 < 0 )
goto V_38;
#endif
V_29 = V_12 -> V_15 ;
V_38:
return V_29 ;
}
void
F_13 ( T_1 * V_12 )
{
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_3 ,
V_18 , V_12 -> V_15 ) ;
return;
}
V_23 [ V_12 -> V_15 ] -> V_24 = V_27 | V_25 | V_40 ;
F_14 ( & V_23 [ V_12 -> V_15 ] -> V_41 ) ;
}
static int
F_9 ( int V_6 )
{
struct V_13 * V_14 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return 0 ;
}
V_14 = V_23 [ V_6 ] ;
if ( V_14 -> V_24 )
F_14 ( & V_14 -> V_41 ) ;
V_14 -> V_24 = V_42 ;
return 1 ;
}
static int
F_15 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( ! V_23 [ V_9 ] -> V_24 )
return V_9 ;
}
return - 1 ;
}
int
F_16 ( int V_43 , struct V_44 * V_44 )
{
int V_6 ;
struct V_13 * V_14 ;
if ( V_43 < 0 || V_43 >= V_16 )
return - V_45 ;
V_6 = F_15 () ;
if ( V_6 < 0 ) {
return - V_46 ;
}
V_14 = V_44 -> V_47 = V_23 [ V_6 ] ;
F_2 ( V_11 L_9 ,
V_6 , V_43 , V_14 -> V_24 ) ;
V_14 -> V_48 = V_14 -> V_49 = NULL ;
V_14 -> V_50 = V_14 -> V_51 = NULL ;
V_14 -> V_52 = V_14 -> V_53 = NULL ;
V_14 -> V_54 = V_14 -> V_55 = NULL ;
V_14 -> V_56 = 0 ;
V_14 -> V_57 = F_17 ( V_14 ) ;
V_14 -> V_12 = NULL ;
V_14 -> V_58 = 0 ;
V_14 -> V_59 = 0 ;
V_14 -> V_60 = 0 ;
V_14 -> V_61 = - 1 ;
V_14 -> V_5 = - 1 ;
V_14 -> V_62 = 1524 ;
V_14 -> V_63 = 16 ;
V_14 -> V_64 = V_65 ;
F_18 ( & V_14 -> V_41 ) ;
V_14 -> V_66 = V_14 -> V_67 + V_68 - 1 ;
V_14 -> V_69 = V_14 -> V_67 ;
V_14 -> V_36 = V_43 ;
#ifdef F_19
V_14 -> V_70 = F_20 ( 16 , 16 ) ;
#endif
#ifdef F_21
V_14 -> V_71 = NULL ;
V_14 -> V_72 = NULL ;
#endif
V_14 -> V_24 = V_27 ;
return 0 ;
}
void
F_22 ( int V_43 , struct V_44 * V_44 )
{
int V_9 ;
struct V_13 * V_14 ;
if ( V_43 < 0 || V_43 >= V_16 )
return;
V_14 = V_44 -> V_47 ;
if ( ! V_14 ) {
F_2 ( V_17 L_10 , V_18 ) ;
return;
}
if ( V_14 -> V_28 & 0x1 )
F_2 ( V_11 L_11 , V_43 , ( long ) V_14 -> V_12 ) ;
if ( V_14 -> V_12 ) {
T_2 * V_73 = V_14 -> V_12 -> V_19 ;
if ( ! V_73 ) {
F_2 ( V_17 L_12 , V_18 ) ;
return;
}
V_14 -> V_24 &= ~ V_25 ;
F_23 ( V_73 -> V_32 ) ;
}
for ( V_9 = 0 ; V_9 < V_68 ; V_9 ++ ) {
F_24 ( V_14 -> V_67 [ V_9 ] . V_10 ) ;
V_14 -> V_67 [ V_9 ] . V_10 = NULL ;
}
V_14 -> V_66 = V_14 -> V_67 + V_68 - 1 ;
V_14 -> V_69 = V_14 -> V_67 ;
#ifdef F_19
F_25 ( V_14 -> V_70 ) ;
V_14 -> V_70 = NULL ;
#endif
#ifdef F_21
F_24 ( V_14 -> V_71 ) ;
V_14 -> V_71 = NULL ;
F_24 ( V_14 -> V_72 ) ;
V_14 -> V_72 = NULL ;
#endif
if ( V_14 -> V_53 )
V_14 -> V_49 -> free ( V_14 -> V_53 ) ;
if ( V_14 -> V_52 )
V_14 -> V_48 -> free ( V_14 -> V_52 ) ;
if ( V_14 -> V_54 )
V_14 -> V_50 -> free ( V_14 -> V_54 ) ;
if ( V_14 -> V_55 )
V_14 -> V_51 -> free ( V_14 -> V_55 ) ;
V_14 -> V_49 = V_14 -> V_48 = NULL ;
V_14 -> V_51 = V_14 -> V_50 = NULL ;
V_14 -> V_53 = V_14 -> V_52 = NULL ;
V_14 -> V_55 = V_14 -> V_54 = NULL ;
if ( V_14 -> V_57 )
F_26 ( V_14 ) ;
V_14 -> V_24 = 0 ;
}
static int
F_27 ( void T_3 * V_74 , void * V_75 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_28 ( V_75 , V_74 , V_3 ) )
return - V_76 ;
return 0 ;
}
static int
F_29 ( void T_3 * V_74 , void * V_75 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_30 ( V_74 , V_75 , V_3 ) )
return - V_76 ;
return 0 ;
}
static int F_31 ( void T_3 * V_77 , struct V_78 * * V_73 )
{
struct V_79 V_80 ;
struct V_78 * V_81 = NULL ;
int V_3 , V_82 ;
if ( F_28 ( & V_80 , V_77 , sizeof( V_80 ) ) )
return - V_76 ;
if ( ! V_80 . V_3 ) {
* V_73 = NULL ;
return 0 ;
}
V_3 = V_80 . V_3 * sizeof( struct V_78 ) ;
V_81 = F_32 ( V_80 . V_83 , V_3 ) ;
if ( F_33 ( V_81 ) )
return F_34 ( V_81 ) ;
V_82 = F_35 ( V_81 , V_80 . V_3 ) ;
if ( V_82 ) {
F_24 ( V_81 ) ;
return V_82 ;
}
* V_73 = V_81 ;
return V_80 . V_3 ;
}
int
F_36 ( int V_43 , struct V_44 * V_44 , unsigned int V_84 , unsigned long V_77 )
{
unsigned long V_75 ;
int V_85 , V_9 , V_8 ;
struct V_13 * V_14 ;
T_1 * V_12 ;
struct V_86 V_2 ;
void T_3 * V_87 = ( void T_3 * ) V_77 ;
V_14 = V_44 -> V_47 ;
V_12 = V_14 -> V_12 ;
if ( V_14 -> V_28 & 0x1 )
F_2 ( V_11 L_13 , V_43 , V_84 , V_14 -> V_24 ) ;
if ( ! ( V_14 -> V_24 & V_27 ) )
return - V_88 ;
switch ( V_84 ) {
case V_89 :
#ifdef F_4
if ( ! ( V_14 -> V_24 & V_25 ) )
return - V_88 ;
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
F_2 ( V_11 L_14 ,
( int ) V_43 , ( int ) V_14 -> V_5 , ( int ) V_75 ) ;
return F_37 ( V_14 , V_75 ) ;
#else
return - 1 ;
#endif
break;
case V_90 :
if ( ( V_85 = F_29 ( V_87 , & V_14 -> V_5 , sizeof( V_14 -> V_5 ) ) ) )
return V_85 ;
break;
case V_91 :
if ( ! V_12 )
return - V_88 ;
if ( ( V_85 = F_29 ( V_87 , V_12 -> V_19 -> V_32 -> V_39 ,
strlen ( V_12 -> V_19 -> V_32 -> V_39 ) ) ) )
return V_85 ;
break;
case V_92 :
if ( ( V_85 = F_29 ( V_87 , & V_14 -> V_60 , sizeof( V_14 -> V_60 ) ) ) )
return V_85 ;
break;
case V_93 :
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_14 -> V_60 = V_75 ;
break;
case V_94 :
if ( ( V_85 = F_29 ( V_87 , & V_14 -> V_59 , sizeof( V_14 -> V_59 ) ) ) )
return V_85 ;
break;
case V_95 :
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) ) {
return V_85 ;
}
if ( V_75 & V_96 && ! ( V_14 -> V_59 & V_96 ) && ( V_14 -> V_24 & V_25 ) ) {
if ( V_12 ) {
V_14 -> V_59 = V_75 ;
F_38 ( V_12 -> V_19 -> V_32 ) ;
break;
}
}
V_14 -> V_59 = V_75 ;
break;
case V_97 :
if ( V_12 ) {
struct V_98 V_99 ;
V_99 . V_100 = V_99 . V_101 = V_12 -> V_102 ;
if ( ( V_85 = F_29 ( V_87 , & V_99 , sizeof( struct V_98 ) ) ) )
return V_85 ;
}
break;
case V_103 :
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_14 -> V_62 = V_75 ;
break;
case V_104 :
break;
case V_105 :
break;
case V_106 :
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_75 ++ ;
if ( V_14 -> V_63 != V_75 ) {
#ifdef F_19
struct V_107 * V_108 ;
#endif
if ( V_14 -> V_28 & 0x1 )
F_2 ( V_11 L_15 , V_75 ) ;
V_14 -> V_63 = V_75 ;
#ifdef F_19
V_108 = F_20 ( 16 , V_75 ) ;
if ( ! V_108 ) {
F_2 ( V_17 L_16 ) ;
return - V_109 ;
}
if ( V_14 -> V_70 )
F_25 ( V_14 -> V_70 ) ;
V_14 -> V_70 = V_108 ;
#endif
}
break;
case V_110 :
if ( ( V_85 = F_29 ( V_87 , & V_14 -> V_28 , sizeof( V_14 -> V_28 ) ) ) )
return V_85 ;
break;
case V_111 :
if ( ( V_85 = F_27 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_14 -> V_28 = V_75 ;
break;
case V_112 :
{
unsigned long V_113 [ 8 ] = { 0 ,} ;
struct V_114 * V_115 = V_116 ;
while ( V_115 ) {
V_8 = V_115 -> V_117 / ( sizeof( long ) * 8 ) ;
V_9 = V_115 -> V_117 % ( sizeof( long ) * 8 ) ;
if ( V_8 < 8 )
V_113 [ V_8 ] |= ( 1UL << V_9 ) ;
V_115 = V_115 -> V_35 ;
}
if ( ( V_85 = F_29 ( V_87 , V_113 , 8 * sizeof( long ) ) ) )
return V_85 ;
}
break;
case V_118 :
if ( ( V_85 = F_27 ( V_87 , & V_2 , sizeof( struct V_86 ) ) ) )
return V_85 ;
return F_39 ( V_14 , & V_2 ) ;
case V_119 :
{
struct V_120 V_121 ;
memset ( ( char * ) & V_121 , 0 , sizeof( struct V_120 ) ) ;
if ( V_12 )
{
strncpy ( V_121 . V_122 , V_12 -> V_123 , 63 ) ;
if ( V_12 -> V_124 ) {
strncpy ( V_121 . V_125 , V_12 -> V_124 -> V_117 , 63 ) ;
}
V_121 . V_126 = V_12 -> V_127 ;
if ( V_12 -> V_128 )
V_121 . V_129 = V_130 ;
else
V_121 . V_129 = V_131 ;
if ( V_12 -> V_132 & V_133 )
V_121 . V_129 |= V_134 ;
}
return F_29 ( V_87 , & V_121 , sizeof( struct V_120 ) ) ;
}
#ifdef F_21
case V_135 :
{
struct V_78 * V_81 ;
int V_3 = F_31 ( V_87 , & V_81 ) ;
if ( V_3 < 0 )
return V_3 ;
F_24 ( V_14 -> V_71 ) ;
V_14 -> V_71 = V_81 ;
V_14 -> V_136 = V_3 ;
break;
}
case V_137 :
{
struct V_78 * V_81 ;
int V_3 = F_31 ( V_87 , & V_81 ) ;
if ( V_3 < 0 )
return V_3 ;
F_24 ( V_14 -> V_72 ) ;
V_14 -> V_72 = V_81 ;
V_14 -> V_138 = V_3 ;
break;
}
#endif
default:
break;
}
return 0 ;
}
unsigned int
F_40 ( struct V_44 * V_44 , T_4 * V_139 )
{
T_5 V_140 ;
struct V_141 * V_142 , * V_143 ;
T_6 V_132 ;
struct V_13 * V_14 ;
V_14 = V_44 -> V_47 ;
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_17 ,
F_41 ( V_44 -> V_144 . V_145 -> V_146 ) ) ;
F_42 ( V_44 , & V_14 -> V_41 , V_139 ) ;
if ( ! ( V_14 -> V_24 & V_27 ) ) {
if ( V_14 -> V_24 == V_42 )
return V_147 ;
F_2 ( V_11 L_18 ) ;
return V_148 ;
}
V_140 = V_149 | V_150 ;
F_43 ( & V_14 -> V_151 , V_132 ) ;
V_143 = V_14 -> V_69 ;
V_142 = V_14 -> V_66 ;
if ( V_142 -> V_35 != V_143 || ( V_14 -> V_24 & V_40 ) ) {
V_14 -> V_24 &= ~ V_40 ;
V_140 |= V_152 | V_153 ;
}
F_44 ( & V_14 -> V_151 , V_132 ) ;
return V_140 ;
}
static int
F_45 ( unsigned char * V_10 , int V_3 , int V_154 , int V_6 )
{
struct V_141 * V_142 , * V_143 ;
T_6 V_132 ;
T_7 * V_155 ;
struct V_13 * V_14 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_37 L_19 , V_6 ) ;
return 0 ;
}
V_14 = V_23 [ V_6 ] ;
if ( ! ( V_14 -> V_24 & V_25 ) ) {
F_2 ( V_11 L_20 ) ;
return 0 ;
}
V_155 = F_46 ( V_3 + 4 , V_156 ) ;
if ( ! V_155 ) {
F_2 ( V_37 L_21 ) ;
return 0 ;
}
V_155 [ 0 ] = V_157 ;
V_155 [ 1 ] = V_158 ;
V_155 [ 2 ] = V_154 >> 8 ;
V_155 [ 3 ] = V_154 & 0xff ;
memcpy ( V_155 + 4 , V_10 , V_3 ) ;
F_43 ( & V_14 -> V_151 , V_132 ) ;
V_142 = V_14 -> V_66 ;
V_143 = V_14 -> V_69 ;
if ( V_142 == V_143 ) {
F_2 ( V_37 L_22 ) ;
V_142 = V_142 -> V_35 ;
F_24 ( V_142 -> V_10 ) ;
V_14 -> V_66 = V_142 ;
}
V_143 -> V_10 = ( char * ) V_155 ;
V_143 -> V_3 = V_3 + 4 ;
V_14 -> V_69 = V_143 -> V_35 ;
F_44 ( & V_14 -> V_151 , V_132 ) ;
F_14 ( & V_14 -> V_41 ) ;
return V_3 ;
}
int
F_47 ( int V_43 , struct V_44 * V_44 , char T_3 * V_10 , int V_159 )
{
struct V_13 * V_14 ;
struct V_141 * V_74 ;
T_6 V_132 ;
T_7 * V_160 ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_27 ) )
return 0 ;
if ( ! F_48 ( V_161 , V_10 , V_159 ) )
return - V_76 ;
F_43 ( & V_14 -> V_151 , V_132 ) ;
V_74 = V_14 -> V_66 -> V_35 ;
V_160 = V_74 -> V_10 ;
if ( ! V_160 ) {
F_44 ( & V_14 -> V_151 , V_132 ) ;
return - V_162 ;
}
if ( V_74 -> V_3 < V_159 )
V_159 = V_74 -> V_3 ;
V_74 -> V_10 = NULL ;
V_14 -> V_66 = V_74 ;
F_44 ( & V_14 -> V_151 , V_132 ) ;
if ( F_30 ( V_10 , V_160 , V_159 ) )
V_159 = - V_76 ;
F_24 ( V_160 ) ;
return V_159 ;
}
int
F_49 ( int V_43 , struct V_44 * V_44 , const char T_3 * V_10 , int V_159 )
{
T_1 * V_12 ;
struct V_13 * V_14 ;
int V_154 ;
unsigned char V_163 [ 4 ] ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_25 ) )
return 0 ;
V_12 = V_14 -> V_12 ;
if ( ! V_12 )
F_2 ( V_11 L_23 ) ;
else {
if ( F_28 ( V_163 , V_10 , 4 ) )
return - V_76 ;
V_154 = F_50 ( V_163 ) ;
if ( V_154 != V_164 )
V_12 -> V_102 = 0 ;
if ( V_12 -> V_165 < 0 || V_12 -> V_166 < 0 )
return 0 ;
if ( ( V_32 -> V_167 [ V_12 -> V_165 ] -> V_132 & V_168 ) &&
V_12 -> V_169 == 0 &&
( V_12 -> V_132 & V_170 ) ) {
unsigned short V_171 ;
struct V_172 * V_173 ;
V_171 = V_32 -> V_167 [ V_12 -> V_165 ] -> V_174 -> V_175 ;
V_173 = F_51 ( V_171 + V_159 , V_156 ) ;
if ( ! V_173 ) {
F_2 ( V_37 L_24 ) ;
return V_159 ;
}
F_52 ( V_173 , V_171 ) ;
if ( F_28 ( F_53 ( V_173 , V_159 ) , V_10 , V_159 ) )
{
F_54 ( V_173 ) ;
return - V_76 ;
}
if ( V_14 -> V_28 & 0x40 ) {
F_2 ( V_11 L_25 , ( int ) V_173 -> V_3 ) ;
F_1 ( L_26 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
F_55 ( V_12 -> V_19 , V_12 , V_173 ) ;
F_56 ( V_12 , V_173 ) ;
}
}
return V_159 ;
}
int
F_57 ( void )
{
int V_9 ,
V_8 ;
#ifdef F_4
if ( F_58 () < 0 )
return - V_109 ;
#endif
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( ! ( V_23 [ V_9 ] = F_59 ( sizeof( struct V_13 ) , V_176 ) ) ) {
F_2 ( V_37 L_27 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_24 ( V_23 [ V_8 ] ) ;
return - 1 ;
}
F_60 ( & V_23 [ V_9 ] -> V_151 ) ;
V_23 [ V_9 ] -> V_24 = 0 ;
V_23 [ V_9 ] -> V_66 = V_23 [ V_9 ] -> V_67 + V_68 - 1 ;
V_23 [ V_9 ] -> V_69 = V_23 [ V_9 ] -> V_67 ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
V_23 [ V_9 ] -> V_67 [ V_8 ] . V_10 = NULL ;
V_23 [ V_9 ] -> V_67 [ V_8 ] . V_69 = V_23 [ V_9 ] -> V_67 +
( V_68 + V_8 - 1 ) % V_68 ;
V_23 [ V_9 ] -> V_67 [ V_8 ] . V_35 = V_23 [ V_9 ] -> V_67 + ( V_8 + 1 ) % V_68 ;
}
}
return 0 ;
}
void
F_61 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_24 ( V_23 [ V_9 ] ) ;
#ifdef F_4
F_24 ( V_177 ) ;
#endif
}
static int F_62 ( struct V_13 * V_14 , struct V_172 * V_173 )
{
if ( V_173 -> V_3 < 1 )
return - 1 ;
if ( V_173 -> V_2 [ 0 ] == 0xff ) {
if ( V_173 -> V_3 < 2 )
return - 1 ;
if ( V_173 -> V_2 [ 1 ] != 0x03 )
return - 1 ;
F_63 ( V_173 , 2 ) ;
} else {
if ( V_14 -> V_59 & V_178 )
return - 1 ;
}
return 0 ;
}
static int F_64 ( struct V_172 * V_173 )
{
int V_154 ;
if ( V_173 -> V_3 < 1 )
return - 1 ;
if ( V_173 -> V_2 [ 0 ] & 0x1 ) {
V_154 = V_173 -> V_2 [ 0 ] ;
F_63 ( V_173 , 1 ) ;
} else {
if ( V_173 -> V_3 < 2 )
return - 1 ;
V_154 = ( ( int ) V_173 -> V_2 [ 0 ] << 8 ) + V_173 -> V_2 [ 1 ] ;
F_63 ( V_173 , 2 ) ;
}
return V_154 ;
}
void F_65 ( T_2 * V_31 , T_1 * V_12 , struct V_172 * V_173 )
{
struct V_13 * V_14 ;
int V_6 ;
int V_154 ;
F_66 ( V_31 -> V_34 -> V_179 ) ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_28 ,
V_12 -> V_15 ) ;
F_54 ( V_173 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x4 ) {
F_2 ( V_11 L_29 ,
( long ) V_14 , ( long ) V_12 , V_12 -> V_15 , V_14 -> V_5 , ( int ) V_173 -> V_3 ) ;
F_1 ( L_30 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( F_62 ( V_14 , V_173 ) < 0 ) {
F_54 ( V_173 ) ;
return;
}
V_154 = F_64 ( V_173 ) ;
if ( V_154 < 0 ) {
F_54 ( V_173 ) ;
return;
}
#ifdef F_4
if ( V_14 -> V_56 & V_180 ) {
V_173 = F_67 ( V_173 , V_14 , NULL , & V_154 ) ;
if ( ! V_173 )
return;
}
if ( ! ( V_14 -> V_60 & V_181 ) ) {
if ( V_154 == V_182 ) {
F_68 ( V_31 , V_12 , V_173 ) ;
return;
}
}
#endif
F_69 ( V_31 , V_12 , V_173 , V_154 ) ;
}
static void
F_69 ( T_2 * V_31 , T_1 * V_12 , struct V_172 * V_173 , int V_154 )
{
struct V_183 * V_32 = V_31 -> V_32 ;
struct V_13 * V_14 , * V_184 ;
T_1 * V_185 = NULL ;
int V_6 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_31 ,
V_12 -> V_15 ) ;
goto V_186;
}
V_14 = V_23 [ V_6 ] ;
if ( V_12 -> V_179 ) {
V_185 = F_70 ( V_12 ) ;
V_6 = V_185 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_32 ,
V_12 -> V_15 ) ;
goto V_186;
}
}
V_184 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x10 ) {
F_2 ( V_11 L_33 , ( int ) V_173 -> V_3 , V_154 ) ;
F_1 ( L_34 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( V_184 -> V_56 & V_187 ) {
V_173 = F_67 ( V_173 , V_14 , V_184 , & V_154 ) ;
if ( ! V_173 )
return;
}
switch ( V_154 ) {
case V_188 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_35 ) ;
V_173 -> V_189 = F_71 ( V_190 ) ;
break;
case V_191 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_36 ) ;
V_173 -> V_189 = F_71 ( V_192 ) ;
break;
case V_193 :
case V_194 :
F_2 ( V_195 L_37 ) ;
goto V_186;
#ifdef F_19
case V_196 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_38 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_39 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_186;
}
if ( F_72 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_70 , V_173 -> V_2 , V_173 -> V_3 ) <= 0 ) {
F_2 ( V_37 L_40 ) ;
goto V_186;
}
V_173 -> V_189 = F_71 ( V_192 ) ;
break;
case V_197 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_41 ) ;
{
struct V_172 * V_198 = V_173 ;
int V_199 ;
V_173 = F_73 ( V_198 -> V_3 + 128 ) ;
if ( ! V_173 ) {
F_2 ( V_37 L_42 , V_32 -> V_39 ) ;
V_173 = V_198 ;
goto V_186;
}
F_53 ( V_173 , V_198 -> V_3 + 128 ) ;
F_74 ( V_198 , V_173 -> V_2 ,
V_198 -> V_3 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_39 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_186;
}
V_199 = F_75 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_70 ,
V_173 -> V_2 , V_198 -> V_3 ) ;
F_54 ( V_198 ) ;
if ( V_199 < 0 )
goto V_186;
F_76 ( V_173 , V_199 ) ;
V_173 -> V_189 = F_71 ( V_192 ) ;
}
break;
#endif
case V_200 :
case V_201 :
F_77 ( V_31 , V_12 , V_173 , V_154 ) ;
if ( V_173 -> V_2 [ 0 ] == V_202 ||
V_173 -> V_2 [ 0 ] == V_203 )
break;
default:
F_45 ( V_173 -> V_2 , V_173 -> V_3 , V_154 , V_12 -> V_15 ) ;
F_54 ( V_173 ) ;
return;
}
#ifdef F_21
F_78 ( V_173 , 4 ) ;
{
T_8 * V_73 = ( T_8 * ) V_173 -> V_2 ;
* V_73 = 0 ;
}
if ( V_14 -> V_71
&& F_79 ( V_173 , V_14 -> V_71 ) == 0 ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_43 ) ;
F_54 ( V_173 ) ;
return;
}
if ( ! ( V_14 -> V_72
&& F_79 ( V_173 , V_14 -> V_72 ) == 0 ) ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_44 ) ;
V_12 -> V_102 = 0 ;
if ( V_185 )
V_185 -> V_102 = 0 ;
}
F_63 ( V_173 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
if ( V_185 )
V_185 -> V_102 = 0 ;
#endif
V_173 -> V_32 = V_32 ;
F_80 ( V_173 ) ;
F_81 ( V_173 ) ;
return;
V_186:
V_31 -> V_34 -> V_204 . V_205 ++ ;
F_54 ( V_173 ) ;
}
static unsigned char * F_82 ( struct V_172 * * V_206 , int V_3 )
{
struct V_172 * V_173 = * V_206 ;
if ( F_83 ( V_173 ) < V_3 ) {
struct V_172 * V_207 = F_84 ( V_173 , V_3 ) ;
if ( ! V_207 ) {
F_2 ( V_17 L_45 ) ;
F_85 ( V_173 ) ;
return NULL ;
}
F_2 ( V_11 L_46 , F_83 ( V_173 ) , V_3 ) ;
F_85 ( V_173 ) ;
* V_206 = V_207 ;
return F_78 ( V_207 , V_3 ) ;
}
return F_78 ( V_173 , V_3 ) ;
}
int
F_86 ( struct V_172 * V_173 , struct V_183 * V_19 )
{
T_1 * V_12 , * V_185 ;
T_2 * V_208 ;
unsigned int V_154 = V_191 ;
struct V_13 * V_209 , * V_210 ;
int V_6 , V_29 = V_211 ;
V_185 = F_87 ( V_19 ) ;
V_208 = V_185 -> V_19 ;
V_6 = V_185 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_47 ,
V_185 -> V_15 ) ;
F_54 ( V_173 ) ;
goto V_38;
}
V_210 = V_23 [ V_6 ] ;
if ( ! ( V_210 -> V_59 & V_96 ) ) {
if ( V_210 -> V_28 & 0x1 )
F_2 ( V_195 L_48 , V_19 -> V_39 ) ;
V_29 = V_212 ;
goto V_38;
}
switch ( F_88 ( V_173 -> V_189 ) ) {
case V_192 :
V_154 = V_191 ;
break;
case V_190 :
V_154 = V_188 ;
break;
default:
F_2 ( V_17 L_49 ,
V_173 -> V_189 ) ;
F_85 ( V_173 ) ;
goto V_38;
}
V_12 = F_89 ( V_208 ) ;
if ( ! V_12 ) {
F_2 ( V_37 L_50 , V_19 -> V_39 ) ;
V_29 = V_212 ;
goto V_38;
}
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_47 ,
V_12 -> V_15 ) ;
F_54 ( V_173 ) ;
goto V_213;
}
V_209 = V_23 [ V_6 ] ;
F_63 ( V_173 , V_214 ) ;
#ifdef F_21
* F_78 ( V_173 , 4 ) = 1 ;
{
T_9 * V_73 = ( T_9 * ) V_173 -> V_2 ;
V_73 ++ ;
* V_73 = F_71 ( V_154 ) ;
}
if ( V_209 -> V_71
&& F_79 ( V_173 , V_209 -> V_71 ) == 0 ) {
if ( V_209 -> V_28 & 0x4 )
F_2 ( V_11 L_51 ) ;
F_54 ( V_173 ) ;
goto V_213;
}
if ( ! ( V_209 -> V_72
&& F_79 ( V_173 , V_209 -> V_72 ) == 0 ) ) {
if ( V_209 -> V_28 & 0x4 )
F_2 ( V_11 L_44 ) ;
V_12 -> V_102 = 0 ;
}
F_63 ( V_173 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
#endif
if ( V_209 -> V_28 & 0x4 )
F_2 ( V_11 L_52 , ( int ) V_173 -> V_3 ) ;
if ( V_210 -> V_28 & 0x40 )
F_1 ( L_53 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_210 -> V_5 , V_12 -> V_15 ) ;
#ifdef F_19
if ( V_154 == V_191 && V_210 -> V_59 & V_215 ) {
struct V_172 * V_216 ;
unsigned short V_171 ;
V_171 = V_32 -> V_167 [ V_12 -> V_165 ] -> V_174 -> V_175 + V_214 ;
V_216 = F_51 ( V_171 + V_173 -> V_3 , V_156 ) ;
if ( V_216 ) {
T_7 * V_10 ;
int V_217 ;
F_52 ( V_216 , V_171 ) ;
V_216 -> V_32 = V_173 -> V_32 ;
F_53 ( V_216 , V_173 -> V_3 ) ;
V_10 = V_173 -> V_2 ;
V_217 = F_90 ( V_210 -> V_70 , V_173 -> V_2 , V_173 -> V_3 , V_216 -> V_2 ,
& V_10 , ! ( V_210 -> V_59 & V_218 ) ) ;
if ( V_10 != V_173 -> V_2 ) {
if ( V_216 -> V_2 != V_10 )
F_2 ( V_17 L_54 ) ;
F_85 ( V_173 ) ;
V_173 = V_216 ;
} else {
F_85 ( V_216 ) ;
}
F_76 ( V_173 , V_217 ) ;
if ( V_173 -> V_2 [ 0 ] & V_219 ) {
V_154 = V_197 ;
V_173 -> V_2 [ 0 ] ^= V_219 ;
} else {
if ( V_173 -> V_2 [ 0 ] >= V_220 )
V_154 = V_196 ;
V_173 -> V_2 [ 0 ] = ( V_173 -> V_2 [ 0 ] & 0x0f ) | 0x40 ;
}
}
}
#endif
if ( V_210 -> V_56 & V_221 ) {
if ( V_210 -> V_56 & V_187 ) {
V_173 = F_91 ( V_173 , & V_154 , V_209 , V_210 , 0 ) ;
} else {
F_2 ( V_11 L_55 ) ;
}
}
if ( V_209 -> V_28 & 0x24 )
F_2 ( V_11 L_56 , ( int ) V_173 -> V_3 , V_154 ) ;
#ifdef F_4
if ( V_209 -> V_60 & V_222 ) {
long V_58 = V_210 -> V_58 ;
V_210 -> V_58 ++ ;
if ( V_209 -> V_60 & V_223 ) {
unsigned char * V_2 = F_82 ( & V_173 , 3 ) ;
if ( ! V_2 )
goto V_213;
V_58 &= 0xfff ;
V_2 [ 0 ] = V_224 | V_225 | ( ( V_58 >> 8 ) & 0xf ) ;
V_2 [ 1 ] = V_58 & 0xff ;
V_2 [ 2 ] = V_154 ;
} else {
unsigned char * V_2 = F_82 ( & V_173 , 5 ) ;
if ( ! V_2 )
goto V_213;
V_2 [ 0 ] = V_224 | V_225 ;
V_2 [ 1 ] = ( V_58 >> 16 ) & 0xff ;
V_2 [ 2 ] = ( V_58 >> 8 ) & 0xff ;
V_2 [ 3 ] = ( V_58 >> 0 ) & 0xff ;
V_2 [ 4 ] = V_154 ;
}
V_154 = V_182 ;
}
#endif
if ( V_209 -> V_56 & V_226 )
V_173 = F_91 ( V_173 , & V_154 , V_209 , V_210 , 1 ) ;
if ( ( V_209 -> V_59 & V_227 ) && ( V_154 <= 0xff ) ) {
unsigned char * V_2 = F_82 ( & V_173 , 1 ) ;
if ( ! V_2 )
goto V_213;
V_2 [ 0 ] = V_154 & 0xff ;
}
else {
unsigned char * V_2 = F_82 ( & V_173 , 2 ) ;
if ( ! V_2 )
goto V_213;
V_2 [ 0 ] = ( V_154 >> 8 ) & 0xff ;
V_2 [ 1 ] = V_154 & 0xff ;
}
if ( ! ( V_209 -> V_59 & V_228 ) ) {
unsigned char * V_2 = F_82 ( & V_173 , 2 ) ;
if ( ! V_2 )
goto V_213;
V_2 [ 0 ] = 0xff ;
V_2 [ 1 ] = 0x03 ;
}
if ( V_210 -> V_28 & 0x40 ) {
F_2 ( V_11 L_57 , ( int ) V_173 -> V_3 ) ;
F_1 ( L_26 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_209 -> V_5 , V_12 -> V_15 ) ;
}
F_92 ( V_12 , V_173 ) ;
V_213:
F_93 ( & V_12 -> V_229 ) ;
V_38:
return V_29 ;
}
int F_94 ( struct V_172 * V_173 , T_1 * V_12 )
{
struct V_13 * V_14 = V_23 [ V_12 -> V_15 ] ;
T_8 V_154 ;
int V_230 = 0 ;
switch ( F_88 ( V_173 -> V_189 ) ) {
case V_192 :
V_154 = V_191 ;
break;
case V_190 :
V_154 = V_188 ;
break;
default:
F_2 ( V_17 L_58 ,
V_173 -> V_189 ) ;
return 1 ;
}
* F_63 ( V_173 , V_214 - 4 ) = 1 ;
{
T_9 * V_73 = ( T_9 * ) V_173 -> V_2 ;
V_73 ++ ;
* V_73 = F_71 ( V_154 ) ;
}
V_230 |= V_14 -> V_71
&& F_79 ( V_173 , V_14 -> V_71 ) == 0 ;
V_230 |= V_14 -> V_72
&& F_79 ( V_173 , V_14 -> V_72 ) == 0 ;
F_78 ( V_173 , V_214 - 4 ) ;
return V_230 ;
}
static int F_58 ( void )
{
int V_9 ;
int V_231 = V_16 * sizeof( V_232 ) ;
if ( ( V_177 = F_59 ( V_231 , V_176 ) ) == NULL )
return - V_109 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_60 ( & V_177 [ V_9 ] . V_21 ) ;
return 0 ;
}
static V_232 * F_95 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( V_177 [ V_9 ] . V_22 <= 0 )
return ( V_177 + V_9 ) ;
return NULL ;
}
static int F_12 ( T_1 * V_12 , V_232 * V_233 )
{
struct V_13 * V_14 ;
if ( V_12 -> V_15 < 0 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return ( - V_88 ) ;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
if ( V_233 ) {
if ( V_12 -> V_19 -> V_20 )
V_12 -> V_19 -> V_20 -> V_22 -- ;
V_12 -> V_19 -> V_20 = V_233 ;
} else {
V_14 -> V_58 = 0 ;
if ( ( V_12 -> V_19 -> V_20 = F_95 () ) == NULL )
return - V_109 ;
V_12 -> V_35 = V_12 -> V_69 = V_12 ;
V_12 -> V_19 -> V_20 -> V_234 = NULL ;
V_12 -> V_19 -> V_20 -> V_235 = 0 ;
V_12 -> V_19 -> V_20 -> V_236 = V_237 ;
}
V_12 -> V_19 -> V_20 -> V_22 ++ ;
V_14 -> V_61 = 0 ;
return 0 ;
}
static void F_68 ( T_2 * V_31 , T_1 * V_12 ,
struct V_172 * V_173 )
{
struct V_13 * V_14 ;
T_1 * V_238 ;
V_232 * V_239 ;
T_10 * V_204 ;
struct V_172 * V_240 , * V_241 , * V_242 , * V_243 ;
T_11 V_244 , V_245 , V_246 ;
unsigned long V_132 ;
int V_6 ;
F_43 ( & V_31 -> V_20 -> V_21 , V_132 ) ;
V_239 = V_31 -> V_20 ;
V_204 = & V_239 -> V_204 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_60 ,
V_18 , V_12 -> V_15 ) ;
V_204 -> V_247 ++ ;
F_85 ( V_173 ) ;
F_44 ( & V_239 -> V_21 , V_132 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( ++ V_239 -> V_235 > V_204 -> V_248 )
V_204 -> V_248 = V_239 -> V_235 ;
if ( V_14 -> V_28 & 0x8 )
F_96 ( V_12 -> V_15 , V_173 ) ;
V_244 = F_97 ( V_14 -> V_60 & V_249 ,
V_173 , V_14 -> V_61 ) ;
if ( V_239 -> V_236 > V_250 && ( V_244 & V_251 ) ) {
V_239 -> V_236 = V_244 ;
} else if ( F_98 ( V_244 , V_239 -> V_236 ) ) {
V_204 -> V_247 ++ ;
F_99 ( V_239 , V_173 ) ;
F_44 ( & V_239 -> V_21 , V_132 ) ;
return;
}
V_14 -> V_61 = V_245 = V_244 ;
for ( V_238 = V_31 -> V_252 ; ; ) {
V_6 = V_238 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_61 ,
V_18 , V_238 -> V_15 ) ;
} else {
T_11 V_253 = V_23 [ V_6 ] -> V_61 ;
if ( F_98 ( V_253 , V_245 ) )
V_245 = V_253 ;
}
if ( ( V_238 = V_238 -> V_35 ) == V_31 -> V_252 )
break;
}
if ( F_98 ( V_245 , V_239 -> V_236 ) )
V_245 = V_239 -> V_236 ;
V_240 = V_173 ;
if ( ( V_241 = V_239 -> V_234 ) == NULL || F_98 ( V_244 , F_100 ( V_241 ) ) ) {
V_240 -> V_35 = V_241 ;
V_239 -> V_234 = V_241 = V_240 ;
V_240 = NULL ;
}
V_242 = F_101 ( V_241 ) & V_224 &&
F_100 ( V_241 ) == V_239 -> V_236 ? V_241 : NULL ;
while ( V_242 != NULL || V_240 != NULL ) {
V_246 = F_100 ( V_241 ) ;
V_243 = V_241 -> V_35 ;
if ( V_240 != NULL && V_246 == V_244 ) {
F_99 ( V_239 , V_240 ) ;
V_240 = NULL ;
}
if ( V_240 != NULL && ( V_243 == NULL ||
F_98 ( V_244 , F_100 ( V_243 ) ) ) ) {
V_240 -> V_35 = V_243 ;
V_241 -> V_35 = V_243 = V_240 ;
V_240 = NULL ;
}
if ( V_242 != NULL ) {
if ( V_242 != V_241 && ( F_101 ( V_241 ) & V_224 ) ) {
F_2 ( V_37 L_62
L_63 , V_246 ) ;
V_204 -> V_254 ++ ;
V_204 -> V_247 ++ ;
V_242 = F_102 ( V_239 , V_242 , V_241 ) ;
V_243 = V_241 -> V_35 ;
}
} else if ( F_103 ( V_246 , V_245 ) ) {
if ( F_101 ( V_241 ) & V_224 )
V_242 = V_241 ;
else {
if ( F_101 ( V_241 ) & V_225 )
V_204 -> V_247 ++ ;
if ( V_239 -> V_234 == V_241 )
V_239 -> V_234 = V_243 ;
F_99 ( V_239 , V_241 ) ;
V_241 = V_243 ;
continue;
}
}
if ( V_242 != NULL && ( F_101 ( V_241 ) & V_225 ) ) {
V_245 = V_239 -> V_236 = ( V_246 + 1 ) & V_255 ;
F_104 ( V_31 , V_12 , V_242 , V_243 ) ;
V_242 = NULL ;
V_241 = NULL ;
V_239 -> V_234 = V_243 ;
}
if ( V_243 != NULL &&
( ( V_246 + 1 ) & V_255 ) == F_100 ( V_243 ) ) {
if ( V_241 == NULL ) {
if ( F_101 ( V_243 ) & V_224 )
V_242 = V_243 ;
else
{
F_2 ( V_37 L_64
L_65
L_66 , V_246 ) ;
V_204 -> V_254 ++ ;
}
}
} else {
if ( V_243 != NULL && V_241 != NULL &&
F_98 ( V_246 , V_245 ) ) {
V_204 -> V_247 ++ ;
V_239 -> V_234 = F_102 ( V_239 , V_242 , V_243 ) ;
}
V_242 = NULL ;
}
V_241 = V_243 ;
}
if ( V_239 -> V_234 == NULL )
V_239 -> V_234 = V_241 ;
if ( V_239 -> V_235 > V_256 ) {
V_204 -> V_257 ++ ;
while ( V_239 -> V_235 > V_256 ) {
V_241 = V_239 -> V_234 -> V_35 ;
F_99 ( V_239 , V_239 -> V_234 ) ;
V_239 -> V_234 = V_241 ;
}
}
F_44 ( & V_239 -> V_21 , V_132 ) ;
}
static void F_7 ( T_1 * V_12 )
{
struct V_172 * V_241 = V_12 -> V_19 -> V_20 -> V_234 ;
struct V_172 * V_258 ;
while ( V_241 ) {
V_258 = V_241 -> V_35 ;
F_99 ( V_12 -> V_19 -> V_20 , V_241 ) ;
V_241 = V_258 ;
}
V_12 -> V_19 -> V_20 -> V_234 = NULL ;
}
static T_11 F_97 ( int V_259 ,
struct V_172 * V_173 , T_11 V_260 )
{
T_11 V_236 ;
int V_132 = V_173 -> V_2 [ 0 ] & ( V_224 | V_225 ) ;
if ( ! V_259 )
{
V_236 = F_105 ( * ( V_261 * ) V_173 -> V_2 ) & V_255 ;
F_78 ( V_173 , 1 ) ;
}
else
{
V_236 = F_88 ( * ( T_9 * ) V_173 -> V_2 ) & V_262 ;
if ( ! ( V_236 & V_263 ) &&
( V_260 & V_263 ) &&
( unsigned long ) V_260 <= V_250 )
V_236 |= ( V_260 + V_264 + 1 ) &
( ~ V_262 & V_255 ) ;
else
V_236 |= V_260 & ( ~ V_262 & V_255 ) ;
F_78 ( V_173 , 3 ) ;
}
* ( T_11 * ) ( V_173 -> V_2 + 1 ) = V_236 ;
V_173 -> V_2 [ 0 ] = V_132 ;
return V_236 ;
}
struct V_172 * F_102 ( V_232 * V_239 ,
struct V_172 * V_265 , struct V_172 * V_266 )
{
if ( V_265 )
while ( V_265 != V_266 ) {
struct V_172 * V_35 = V_265 -> V_35 ;
F_99 ( V_239 , V_265 ) ;
V_265 = V_35 ;
}
return V_265 ;
}
void F_104 ( T_2 * V_31 , T_1 * V_12 ,
struct V_172 * V_265 , struct V_172 * V_266 )
{
V_232 * V_239 = V_31 -> V_20 ;
int V_154 ;
struct V_172 * V_173 ;
unsigned int V_267 ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return;
}
if ( F_101 ( V_265 ) == ( V_224 | V_225 ) ) {
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_67
L_68 , F_100 ( V_265 ) , V_265 -> V_3 ) ;
V_173 = V_265 ;
F_63 ( V_173 , V_268 ) ;
V_239 -> V_235 -- ;
} else {
struct V_172 * V_241 ;
int V_269 ;
for ( V_267 = V_269 = 0 , V_241 = V_265 ; V_241 != V_266 ; V_241 = V_241 -> V_35 , V_269 ++ )
V_267 += V_241 -> V_3 - V_268 ;
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_69
L_70 , F_100 ( V_265 ) ,
( F_100 ( V_265 ) + V_269 - 1 ) & V_255 , V_267 ) ;
if ( ( V_173 = F_73 ( V_267 ) ) == NULL ) {
F_2 ( V_17 L_71
L_72 , V_267 ) ;
F_102 ( V_239 , V_265 , V_266 ) ;
return;
}
while ( V_265 != V_266 ) {
unsigned int V_3 = V_265 -> V_3 - V_268 ;
F_106 ( V_265 , V_268 ,
F_53 ( V_173 , V_3 ) ,
V_3 ) ;
V_241 = V_265 -> V_35 ;
F_99 ( V_239 , V_265 ) ;
V_265 = V_241 ;
}
}
V_154 = F_64 ( V_173 ) ;
F_69 ( V_31 , V_12 , V_173 , V_154 ) ;
}
static void F_99 ( V_232 * V_239 , struct V_172 * V_173 )
{
F_85 ( V_173 ) ;
V_239 -> V_235 -- ;
}
static void F_96 ( int V_6 , struct V_172 * V_173 )
{
F_2 ( V_11 L_73 ,
V_6 , ( int ) V_173 -> V_3 ,
( int ) V_173 -> V_2 [ 0 ] , ( int ) V_173 -> V_2 [ 1 ] , ( int ) V_173 -> V_2 [ 2 ] ,
( int ) V_173 -> V_2 [ 3 ] , ( int ) V_173 -> V_2 [ 4 ] , ( int ) V_173 -> V_2 [ 5 ] ) ;
}
static int
F_37 ( struct V_13 * V_14 , int V_5 )
{
char V_270 [ V_271 + 1 ] ;
T_2 * V_73 ;
T_1 * V_12 , * V_272 ;
int V_273 ;
unsigned long V_132 ;
sprintf ( V_270 , L_74 , V_5 ) ;
V_73 = F_107 ( V_270 ) ;
if ( ! V_73 ) {
F_2 ( V_17 L_75 , V_270 ) ;
return - V_88 ;
}
F_43 ( & V_73 -> V_20 -> V_21 , V_132 ) ;
V_272 = V_14 -> V_12 ;
V_12 = V_73 -> V_252 ;
if ( V_272 -> V_15 < 0 || V_272 -> V_15 >= V_16 ||
V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_76 ,
V_272 -> V_15 < 0 || V_272 -> V_15 >= V_16 ?
V_272 -> V_15 : V_12 -> V_15 ) ;
V_273 = - V_88 ;
goto V_38;
}
F_108 ( V_73 , V_272 ) ;
V_23 [ V_272 -> V_15 ] -> V_5 = V_23 [ V_12 -> V_15 ] -> V_5 ;
V_23 [ V_272 -> V_15 ] -> V_59 |= V_23 [ V_12 -> V_15 ] -> V_59 &
( V_96 | V_218 | V_274 ) ;
V_23 [ V_272 -> V_15 ] -> V_60 |= V_23 [ V_12 -> V_15 ] -> V_60 &
( V_222 | V_181 | V_223 | V_249 ) ;
V_273 = F_12 ( V_272 , V_73 -> V_20 ) ;
V_38:
F_44 ( & V_73 -> V_20 -> V_21 , V_132 ) ;
return V_273 ;
}
static int
F_109 ( int V_6 , struct V_275 * V_276 , struct V_183 * V_32 )
{
struct V_277 T_3 * V_278 = V_276 -> V_279 ;
struct V_277 V_280 ;
T_1 * V_12 = F_87 ( V_32 ) ;
if ( ! F_48 ( V_161 , V_278 , sizeof( struct V_277 ) ) )
return - V_76 ;
memset ( & V_280 , 0 , sizeof( struct V_277 ) ) ;
if ( V_32 -> V_132 & V_281 ) {
V_280 . V_73 . V_282 = V_12 -> V_204 . V_283 ;
V_280 . V_73 . V_284 = V_12 -> V_204 . V_285 ;
V_280 . V_73 . V_286 = V_12 -> V_204 . V_287 ;
V_280 . V_73 . V_288 = V_12 -> V_204 . V_289 ;
V_280 . V_73 . V_290 = V_12 -> V_204 . V_291 ;
V_280 . V_73 . V_292 = V_12 -> V_204 . V_293 ;
#ifdef F_19
if ( V_6 >= 0 && V_23 [ V_6 ] -> V_70 ) {
struct V_107 * V_70 = V_23 [ V_6 ] -> V_70 ;
V_280 . V_294 . V_295 = V_70 -> V_296 + V_70 -> V_297 ;
V_280 . V_294 . V_298 = V_70 -> V_296 ;
V_280 . V_294 . V_299 = V_70 -> V_300 ;
V_280 . V_294 . V_301 = V_70 -> V_302 ;
V_280 . V_294 . V_303 = V_70 -> V_304 ;
V_280 . V_294 . V_305 = V_70 -> V_306 ;
V_280 . V_294 . V_307 = V_70 -> V_308 ;
V_280 . V_294 . V_309 = V_70 -> V_310 ;
}
#endif
}
if ( F_30 ( V_278 , & V_280 , sizeof( struct V_277 ) ) )
return - V_76 ;
return 0 ;
}
int
F_110 ( struct V_183 * V_32 , struct V_275 * V_276 , int V_84 )
{
int error = 0 ;
int V_3 ;
T_1 * V_12 = F_87 ( V_32 ) ;
if ( V_12 -> V_311 != V_312 )
return - V_88 ;
switch ( V_84 ) {
#define F_111 "2.3.7"
case V_313 :
V_3 = strlen ( F_111 ) + 1 ;
if ( F_30 ( V_276 -> V_279 , F_111 , V_3 ) )
error = - V_76 ;
break;
case V_314 :
error = F_109 ( V_12 -> V_15 , V_276 , V_32 ) ;
break;
default:
error = - V_88 ;
break;
}
return error ;
}
static int
F_11 ( char * V_39 )
{
int V_3 ,
V_9 ,
V_5 = 0 ,
V_315 ;
V_3 = strlen ( V_39 ) ;
if ( strncmp ( L_77 , V_39 , 4 ) || V_3 > 8 )
return - 1 ;
for ( V_9 = 0 , V_315 = 1 ; V_9 < V_3 ; V_9 ++ , V_315 *= 10 ) {
char V_316 = V_39 [ V_3 - V_9 - 1 ] ;
if ( V_316 >= '0' && V_316 <= '9' )
V_5 += ( V_316 - '0' ) * V_315 ;
else
break;
}
if ( ! V_9 || V_3 - V_9 != 4 )
V_5 = - 1 ;
return V_5 ;
}
int
F_112 ( char * V_39 )
{
#ifdef F_4
T_2 * V_317 ;
T_1 * V_12 ;
struct V_183 * V_318 ;
if ( ! ( V_317 = F_107 ( V_39 ) ) )
return 1 ;
V_12 = V_317 -> V_34 ;
if ( ! ( V_12 -> V_132 & V_170 ) )
return 5 ;
V_318 = V_12 -> V_319 ;
while ( V_318 ) {
T_1 * V_185 = F_87 ( V_318 ) ;
if ( ! ( V_185 -> V_132 & V_170 ) )
break;
V_318 = V_185 -> V_319 ;
}
if ( ! V_318 )
return 2 ;
F_113 ( F_87 ( V_318 ) ) ;
return 0 ;
#else
return - 1 ;
#endif
}
int
F_114 ( char * V_39 )
{
#ifdef F_4
T_2 * V_317 ;
T_1 * V_12 ;
struct V_183 * V_318 ;
if ( ! ( V_317 = F_107 ( V_39 ) ) )
return 1 ;
V_12 = V_317 -> V_34 ;
if ( ! ( V_12 -> V_132 & V_170 ) )
return 5 ;
V_318 = V_12 -> V_319 ;
while ( V_318 ) {
T_1 * V_185 = F_87 ( V_318 ) ;
if ( V_185 -> V_319 ) {
T_1 * V_272 = F_115 ( V_185 ) ;
if ( ! ( V_272 -> V_132 & V_170 ) )
break;
} else if ( V_185 -> V_132 & V_170 )
break;
V_318 = V_185 -> V_319 ;
}
if ( ! V_318 )
return 2 ;
F_23 ( V_318 ) ;
return 0 ;
#else
return - 1 ;
#endif
}
static void F_116 ( struct V_13 * V_14 )
{
F_45 ( NULL , 0 , V_193 , V_14 -> V_12 -> V_15 ) ;
}
static void F_117 ( struct V_13 * V_14 , int V_154 ,
unsigned char V_81 , unsigned char V_320 ,
unsigned char * V_2 , int V_3 )
{
struct V_172 * V_173 ;
unsigned char * V_73 ;
int V_171 ;
int V_7 = 0 ;
T_1 * V_12 = V_14 -> V_12 ;
V_171 = V_32 -> V_167 [ V_12 -> V_165 ] -> V_174 -> V_175 ;
V_173 = F_51 ( V_3 + V_171 + 16 , V_156 ) ;
if ( ! V_173 ) {
F_2 ( V_37
L_78 ) ;
return;
}
F_52 ( V_173 , V_171 ) ;
if ( ! ( V_14 -> V_59 & V_228 ) ) {
V_73 = F_53 ( V_173 , 2 ) ;
* V_73 ++ = 0xff ;
* V_73 ++ = 0x03 ;
}
V_73 = F_53 ( V_173 , 6 ) ;
* V_73 ++ = ( V_154 >> 8 ) ;
* V_73 ++ = ( V_154 & 0xff ) ;
* V_73 ++ = V_81 ;
* V_73 ++ = V_320 ;
V_7 = 4 + V_3 ;
* V_73 ++ = ( V_7 >> 8 ) ;
* V_73 ++ = ( V_7 & 0xff ) ;
if ( V_3 ) {
V_73 = F_53 ( V_173 , V_3 ) ;
memcpy ( V_73 , V_2 , V_3 ) ;
}
F_2 ( V_11 L_79 ) ;
F_1 ( L_80 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
F_56 ( V_12 , V_173 ) ;
}
static struct V_321 * F_17 ( struct V_13 * V_14 )
{
struct V_321 * V_85 ;
V_85 = F_59 ( sizeof( struct V_321 ) , V_176 ) ;
if ( ! V_85 ) {
F_2 ( V_17 L_81
L_82 ) ;
return NULL ;
}
F_2 ( V_11 L_83 , V_85 ) ;
V_14 -> V_57 = V_85 ;
return V_85 ;
}
static void F_26 ( struct V_13 * V_14 )
{
unsigned int V_320 ;
F_2 ( V_11 L_84 ,
V_14 -> V_57 ) ;
for ( V_320 = 0 ; V_320 < 256 ; V_320 ++ ) {
if ( V_14 -> V_57 -> V_322 [ V_320 ] ) {
F_118 ( V_14 , ( unsigned char ) V_320 ) ;
}
}
F_24 ( V_14 -> V_57 ) ;
V_14 -> V_57 = NULL ;
}
static void F_118 ( struct V_13 * V_14 ,
unsigned char V_320 )
{
struct V_323 * V_322 ;
if ( V_14 -> V_57 -> V_322 [ V_320 ] ) {
F_2 ( V_11 L_85 , V_320 ) ;
V_322 = V_14 -> V_57 -> V_322 [ V_320 ] ;
if ( V_322 -> V_324 )
F_119 ( & V_322 -> V_325 ) ;
V_14 -> V_57 -> V_322 [ V_320 ] = NULL ;
F_24 ( V_322 ) ;
} else {
F_2 ( V_37 L_86 , V_320 ) ;
}
}
static void F_120 ( unsigned long V_326 )
{
struct V_323 * V_322 =
(struct V_323 * ) V_326 ;
if ( ! V_322 ) {
F_2 ( V_17 L_87 ) ;
return;
}
if ( V_322 -> V_324 && V_322 -> V_24 == V_327 ) {
if ( ! V_322 -> V_328 ) {
V_322 -> V_324 = 0 ;
F_118 ( V_322 -> V_14 , V_322 -> V_320 ) ;
return;
}
F_2 ( V_11 L_88 ,
V_322 -> V_320 ) ;
F_117 ( V_322 -> V_14 , V_200 , V_202 , V_322 -> V_320 ,
V_322 -> V_2 , V_322 -> V_329 ) ;
V_322 -> V_325 . V_330 = V_331 + V_332 * 5 ;
F_121 ( & V_322 -> V_325 ) ;
} else {
F_2 ( V_37 L_89 ,
V_322 -> V_24 ) ;
}
}
static struct V_323 * F_122 ( struct V_13 * V_14 ,
unsigned char V_320 )
{
struct V_323 * V_322 ;
if ( V_14 -> V_57 -> V_322 [ V_320 ] ) {
F_2 ( V_37 L_90 ,
V_320 ) ;
return NULL ;
} else {
V_322 = F_59 ( sizeof( struct V_323 ) , V_176 ) ;
if ( ! V_322 )
return NULL ;
V_322 -> V_24 = V_333 ;
V_322 -> V_14 = V_14 ;
V_322 -> V_320 = V_320 ;
F_123 ( & V_322 -> V_325 ) ;
V_322 -> V_325 . V_2 = ( unsigned long ) V_322 ;
V_322 -> V_325 . V_334 = F_120 ;
V_14 -> V_57 -> V_322 [ V_320 ] = V_322 ;
}
return V_322 ;
}
static void F_124 ( struct V_13 * V_14 ,
struct V_335 * V_336 )
{
struct V_323 * V_322 ;
if ( V_336 -> V_337 ) {
if ( V_336 -> V_338 ) {
if ( ! ( V_336 -> V_339 ) ) {
F_2 ( V_17 L_91
L_92 ) ;
return;
}
if ( V_14 -> V_57 -> V_322 [ V_336 -> V_320 ] ) {
V_322 = V_14 -> V_57 -> V_322 [ V_336 -> V_320 ] ;
if ( V_322 -> V_24 == V_327 && V_322 -> V_324 ) {
F_2 ( V_11 L_93
L_94
L_95 , V_336 -> V_320 ) ;
} else {
F_2 ( V_37 L_93
L_96
L_97 , V_322 -> V_24 , V_336 -> V_320 ) ;
}
} else {
F_2 ( V_11 L_98
L_99 , V_336 -> V_320 ) ;
V_322 = F_122 ( V_14 , V_336 -> V_320 ) ;
if ( ! V_322 ) {
F_2 ( V_17 L_100
L_101 ) ;
return;
}
V_322 -> V_24 = V_327 ;
V_322 -> V_328 = V_336 -> V_328 ;
if ( V_336 -> V_340 ) {
V_322 -> V_329 = V_336 -> V_329 ;
memcpy ( V_322 -> V_2 , V_336 -> V_2 , V_336 -> V_329 ) ;
}
F_117 ( V_14 , V_200 ,
V_202 , V_322 -> V_320 ,
V_322 -> V_2 , V_322 -> V_329 ) ;
V_322 -> V_325 . V_330 = V_331 + 5 * V_332 ;
F_121 ( & V_322 -> V_325 ) ;
V_322 -> V_324 = 1 ;
}
} else {
F_2 ( V_11 L_102 ) ;
}
} else {
if ( V_14 -> V_57 -> V_322 [ V_14 -> V_57 -> V_341 ] ) {
V_322 = V_14 -> V_57 -> V_322 [ V_14 -> V_57 -> V_341 ] ;
if ( V_322 -> V_24 == V_327 && V_322 -> V_324 ) {
F_2 ( V_11 L_93
L_94
L_95 , V_336 -> V_320 ) ;
} else {
F_2 ( V_37 L_93
L_96
L_97 , V_322 -> V_24 , V_336 -> V_320 ) ;
}
} else {
F_2 ( V_11 L_98
L_99 , V_14 -> V_57 -> V_341 ) ;
V_322 = F_122 ( V_14 ,
V_14 -> V_57 -> V_341 ) ;
if ( ! V_322 ) {
F_2 ( V_17 L_100
L_101 ) ;
return;
}
V_322 -> V_24 = V_327 ;
V_322 -> V_328 = 1 ;
V_322 -> V_329 = 0 ;
F_117 ( V_14 , V_200 , V_202 ,
V_322 -> V_320 , NULL , 0 ) ;
V_322 -> V_325 . V_330 = V_331 + 5 * V_332 ;
F_121 ( & V_322 -> V_325 ) ;
V_322 -> V_324 = 1 ;
}
}
}
static void F_125 ( struct V_13 * V_14 ,
unsigned char V_320 )
{
struct V_323 * V_322 = V_14 -> V_57 -> V_322 [ V_320 ] ;
if ( V_322 ) {
if ( V_322 -> V_324 && V_322 -> V_24 == V_327 ) {
if ( ! V_322 -> V_328 )
F_2 ( V_11 L_103
L_104 , V_320 ) ;
} else {
F_2 ( V_195 L_105
L_106 , V_320 ) ;
}
if ( V_322 -> V_324 ) {
V_322 -> V_324 = 0 ;
F_119 ( & V_322 -> V_325 ) ;
}
F_118 ( V_14 , V_320 ) ;
} else {
F_2 ( V_195 L_107
L_108 , V_320 ) ;
}
V_14 -> V_57 -> V_341 ++ ;
}
static struct V_172 * F_67 ( struct V_172 * V_173 , struct V_13 * V_14 , struct V_13 * V_179 ,
int * V_154 )
{
void * V_342 = NULL ;
struct V_114 * V_115 = NULL ;
struct V_172 * V_343 ;
int V_3 ;
struct V_13 * V_344 ;
struct V_335 V_345 ;
unsigned char V_346 [ V_347 ] ;
if ( ! V_179 ) {
V_342 = V_14 -> V_54 ;
V_115 = V_14 -> V_50 ;
V_344 = V_14 ;
} else {
V_342 = V_179 -> V_55 ;
V_115 = V_179 -> V_51 ;
V_344 = V_179 ;
}
if ( ! V_115 ) {
F_2 ( V_11 L_109 ) ;
return V_173 ;
}
F_66 ( ! V_342 ) ;
if ( ( V_179 && * V_154 == V_193 ) || ( ! V_179 && * V_154 == V_194 ) ) {
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_345 . V_2 = V_346 ;
V_345 . V_348 = V_347 ;
V_343 = F_73 ( V_14 -> V_62 + V_349 ) ;
if ( ! V_343 ) {
F_54 ( V_173 ) ;
F_2 ( V_17 L_110 ) ;
return NULL ;
}
V_3 = V_115 -> V_350 ( V_342 , V_173 , V_343 , & V_345 ) ;
F_54 ( V_173 ) ;
if ( V_3 <= 0 ) {
switch ( V_3 ) {
case V_351 :
F_2 ( V_195 L_111 ,
V_345 . V_337 ? L_112 : L_113 ) ;
F_124 ( V_344 , & V_345 ) ;
break;
case V_352 :
V_344 -> V_59 |= V_353 ;
F_116 ( V_344 ) ;
break;
}
F_54 ( V_343 ) ;
return NULL ;
}
* V_154 = F_64 ( V_343 ) ;
if ( * V_154 < 0 ) {
F_54 ( V_343 ) ;
return NULL ;
}
return V_343 ;
} else {
V_115 -> V_354 ( V_342 , V_173 , * V_154 ) ;
return V_173 ;
}
}
static struct V_172 * F_91 ( struct V_172 * V_355 , int * V_154 ,
struct V_13 * V_14 , struct V_13 * V_179 , int type )
{
int V_356 ;
int V_357 ;
struct V_114 * V_49 ;
void * V_342 ;
struct V_172 * V_343 ;
if ( * V_154 < 0 || * V_154 > 0x3fff ) {
return V_355 ;
}
if ( type ) {
return V_355 ;
}
else {
if ( ! V_179 ) {
V_49 = V_14 -> V_49 ;
V_342 = V_14 -> V_53 ;
}
else {
V_49 = V_179 -> V_49 ;
V_342 = V_179 -> V_53 ;
}
V_357 = V_193 ;
}
if ( ! V_49 ) {
F_2 ( V_17 L_114 ) ;
return V_355 ;
}
if ( ! V_342 ) {
F_2 ( V_17 L_115 ) ;
return V_355 ;
}
V_343 = F_51 ( V_355 -> V_3 + V_355 -> V_3 / 2 + 32 +
F_83 ( V_355 ) , V_156 ) ;
if ( ! V_343 )
return V_355 ;
F_52 ( V_343 , F_83 ( V_355 ) ) ;
V_356 = ( V_49 -> V_358 ) ( V_342 , V_355 , V_343 , * V_154 ) ;
if ( ! V_356 ) {
F_85 ( V_343 ) ;
return V_355 ;
}
F_85 ( V_355 ) ;
* V_154 = V_357 ;
return V_343 ;
}
static void F_77 ( T_2 * V_31 , T_1 * V_12 ,
struct V_172 * V_173 , int V_154 )
{
struct V_13 * V_14 ;
struct V_13 * V_184 ;
int V_3 ;
struct V_335 V_345 ;
unsigned char V_346 [ V_347 ] ;
F_2 ( V_11 L_116 ,
V_12 -> V_15 ) ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
F_1 ( L_117 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_179 ) {
int V_6 = F_70 ( V_12 ) -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return;
}
V_184 = V_23 [ V_6 ] ;
} else
V_184 = V_14 ;
switch ( V_173 -> V_2 [ 0 ] ) {
case V_359 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_118 ) ;
if ( V_154 == V_200 )
V_184 -> V_56 &= ~ V_221 ;
else
V_14 -> V_56 &= ~ V_226 ;
break;
case V_360 :
case V_361 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_119 ) ;
if ( V_154 == V_200 )
V_184 -> V_56 &= ~ ( V_187 | V_221 ) ;
else
V_14 -> V_56 &= ~ ( V_180 | V_226 ) ;
break;
case V_362 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_120 ) ;
if ( V_154 == V_200 ) {
if ( ! V_184 -> V_51 )
break;
V_184 -> V_56 |= V_187 ;
} else {
if ( ! V_14 -> V_51 )
break;
V_14 -> V_56 |= V_180 ;
}
break;
case V_203 :
F_2 ( V_11 L_121 ) ;
V_3 = ( V_173 -> V_2 [ 2 ] << 8 ) | V_173 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_154 == V_200 ) {
F_125 ( V_184 , V_173 -> V_2 [ 1 ] ) ;
if ( V_184 -> V_51 && V_184 -> V_55 )
V_184 -> V_51 ->
V_57 ( V_184 -> V_55 ,
V_173 -> V_2 [ 0 ] ,
V_173 -> V_2 [ 1 ] ,
V_3 ? & V_173 -> V_2 [ 4 ] : NULL ,
V_3 , NULL ) ;
V_184 -> V_56 &= ~ V_363 ;
}
else {
F_125 ( V_14 , V_173 -> V_2 [ 1 ] ) ;
if ( V_14 -> V_50 && V_14 -> V_54 )
V_14 -> V_50 ->
V_57 ( V_14 -> V_54 ,
V_173 -> V_2 [ 0 ] ,
V_173 -> V_2 [ 1 ] ,
V_3 ? & V_173 -> V_2 [ 4 ] : NULL ,
V_3 , NULL ) ;
V_14 -> V_56 &= ~ V_364 ;
}
break;
case V_202 :
F_2 ( V_11 L_122 ) ;
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_345 . V_2 = V_346 ;
V_345 . V_348 = V_347 ;
V_3 = ( V_173 -> V_2 [ 2 ] << 8 ) | V_173 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_154 == V_200 ) {
if ( V_184 -> V_49 && V_184 -> V_53 )
V_184 -> V_49 ->
V_57 ( V_184 -> V_53 ,
V_173 -> V_2 [ 0 ] ,
V_173 -> V_2 [ 1 ] ,
V_3 ? & V_173 -> V_2 [ 4 ] : NULL ,
V_3 , & V_345 ) ;
}
else {
if ( V_14 -> V_48 && V_14 -> V_52 )
V_14 -> V_48 ->
V_57 ( V_14 -> V_52 ,
V_173 -> V_2 [ 0 ] ,
V_173 -> V_2 [ 1 ] ,
V_3 ? & V_173 -> V_2 [ 4 ] : NULL ,
V_3 , & V_345 ) ;
}
if ( V_345 . V_337 ) {
if ( V_345 . V_338 ) {
F_117 ( V_14 , V_154 , V_203 ,
V_345 . V_339 ? V_345 . V_320
: V_173 -> V_2 [ 1 ] ,
V_345 . V_340 ?
V_345 . V_2 : NULL ,
V_345 . V_340 ?
V_345 . V_329 : 0 ) ;
} else {
F_2 ( V_11 L_123 ) ;
}
} else {
F_117 ( V_14 , V_154 , V_203 ,
V_173 -> V_2 [ 1 ] ,
V_3 ? & V_173 -> V_2 [ 4 ] : NULL ,
V_3 ) ;
}
break;
}
}
static void F_55 ( T_2 * V_31 , T_1 * V_12 , struct V_172 * V_173 )
{
struct V_13 * V_184 , * V_14 ;
int V_154 , V_6 = V_12 -> V_15 ;
unsigned char * V_2 ;
if ( ! V_173 || V_173 -> V_3 < 3 )
return;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_6 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
V_2 = V_173 -> V_2 ;
if ( ! ( V_14 -> V_59 & V_228 ) && V_2 [ 0 ] == 0xff && V_2 [ 1 ] == 0x03 ) {
V_2 += 2 ;
if ( V_173 -> V_3 < 5 )
return;
}
V_154 = ( ( int ) V_2 [ 0 ] << 8 ) + V_2 [ 1 ] ;
if ( V_154 != V_200 && V_154 != V_201 )
return;
F_2 ( V_11 L_124 ) ;
F_1 ( L_80 , V_173 -> V_2 , V_173 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_179 ) {
V_6 = F_70 ( V_12 ) -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return;
}
V_184 = V_23 [ V_6 ] ;
} else
V_184 = V_14 ;
if ( V_184 != V_14 )
F_2 ( V_11 L_125 ) ;
switch ( V_2 [ 2 ] ) {
case V_359 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_126 ) ;
if ( V_154 == V_200 )
V_14 -> V_56 &= ~ V_187 ;
else
V_14 -> V_56 &= ~ V_180 ;
break;
case V_360 :
case V_361 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_119 ) ;
if ( V_154 == V_200 )
V_14 -> V_56 &= ~ ( V_187 | V_221 ) ;
else
V_14 -> V_56 &= ~ ( V_180 | V_226 ) ;
break;
case V_362 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_127 ) ;
if ( V_154 == V_200 ) {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_221 ;
} else {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_226 ;
}
break;
case V_203 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_128 ) ;
F_2 ( V_11 L_129 ) ;
if ( V_154 == V_200 ) {
if ( V_14 -> V_49 && V_14 -> V_53 )
V_14 -> V_49 -> V_57 ( V_14 -> V_53 , 0 , 0 ,
NULL , 0 , NULL ) ;
V_14 -> V_56 &= ~ V_365 ;
}
else {
if ( V_14 -> V_48 && V_14 -> V_52 )
V_14 -> V_48 -> V_57 ( V_14 -> V_52 ,
0 , 0 , NULL , 0 , NULL ) ;
V_14 -> V_56 &= ~ V_366 ;
}
break;
case V_202 :
F_2 ( V_11 L_130 ) ;
break;
}
}
int F_126 ( struct V_114 * V_115 )
{
V_115 -> V_35 = V_116 ;
V_115 -> V_367 = NULL ;
if ( V_116 ) {
V_116 -> V_367 = V_115 ;
}
V_116 = V_115 ;
return 0 ;
}
int F_127 ( struct V_114 * V_115 )
{
if ( V_115 -> V_367 )
V_115 -> V_367 -> V_35 = V_115 -> V_35 ;
else
V_116 = V_115 -> V_35 ;
if ( V_115 -> V_35 )
V_115 -> V_35 -> V_367 = V_115 -> V_367 ;
V_115 -> V_367 = V_115 -> V_35 = NULL ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 , struct V_86 * V_2 )
{
struct V_114 * V_115 = V_116 ;
int V_356 ;
void * V_342 ;
int V_117 = V_2 -> V_117 ;
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_131 , V_14 -> V_5 ,
( V_2 -> V_132 & V_368 ) ? L_132 : L_133 , V_117 ) ;
if ( ! ( V_2 -> V_132 & V_368 ) && ! V_14 -> V_57 ) {
F_2 ( V_17 L_134
L_135 ) ;
return - V_109 ;
}
while ( V_115 ) {
if ( V_115 -> V_117 == V_117 ) {
V_342 = V_115 -> V_369 ( V_2 ) ;
if ( V_342 ) {
V_356 = V_115 -> V_370 ( V_342 , V_2 , V_14 -> V_5 , 0 ) ;
if ( ! V_356 ) {
F_2 ( V_17 L_136 ) ;
V_115 -> free ( V_342 ) ;
V_342 = NULL ;
break;
}
}
else {
F_2 ( V_17 L_137 ) ;
break;
}
if ( V_2 -> V_132 & V_368 ) {
if ( V_2 -> V_132 & V_371 ) {
if ( V_14 -> V_52 )
V_14 -> V_48 -> free ( V_14 -> V_52 ) ;
V_14 -> V_52 = V_342 ;
V_14 -> V_48 = V_115 ;
}
else {
if ( V_14 -> V_53 )
V_14 -> V_49 -> free ( V_14 -> V_53 ) ;
V_14 -> V_53 = V_342 ;
V_14 -> V_49 = V_115 ;
}
}
else {
if ( V_2 -> V_132 & V_371 ) {
if ( V_14 -> V_54 )
V_14 -> V_50 -> free ( V_14 -> V_54 ) ;
V_14 -> V_54 = V_342 ;
V_14 -> V_50 = V_115 ;
}
else {
if ( V_14 -> V_55 )
V_14 -> V_51 -> free ( V_14 -> V_55 ) ;
V_14 -> V_55 = V_342 ;
V_14 -> V_51 = V_115 ;
}
}
return 0 ;
}
V_115 = V_115 -> V_35 ;
}
return - V_88 ;
}
