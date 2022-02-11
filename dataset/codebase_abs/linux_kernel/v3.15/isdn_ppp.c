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
if ( V_14 -> V_71 ) {
F_26 ( V_14 -> V_71 ) ;
V_14 -> V_71 = NULL ;
}
if ( V_14 -> V_72 ) {
F_26 ( V_14 -> V_72 ) ;
V_14 -> V_72 = NULL ;
}
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
F_27 ( V_14 ) ;
V_14 -> V_24 = 0 ;
}
static int
F_28 ( void T_3 * V_74 , void * V_75 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_29 ( V_75 , V_74 , V_3 ) )
return - V_76 ;
return 0 ;
}
static int
F_30 ( void T_3 * V_74 , void * V_75 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_31 ( V_74 , V_75 , V_3 ) )
return - V_76 ;
return 0 ;
}
static int F_32 ( void T_3 * V_77 , struct V_78 * * V_73 )
{
struct V_79 V_80 ;
struct V_78 * V_81 = NULL ;
int V_3 , V_82 ;
if ( F_29 ( & V_80 , V_77 , sizeof( V_80 ) ) )
return - V_76 ;
if ( ! V_80 . V_3 ) {
* V_73 = NULL ;
return 0 ;
}
V_3 = V_80 . V_3 * sizeof( struct V_78 ) ;
V_81 = F_33 ( V_80 . V_83 , V_3 ) ;
if ( F_34 ( V_81 ) )
return F_35 ( V_81 ) ;
V_82 = F_36 ( V_81 , V_80 . V_3 ) ;
if ( V_82 ) {
F_24 ( V_81 ) ;
return V_82 ;
}
* V_73 = V_81 ;
return V_80 . V_3 ;
}
int
F_37 ( int V_43 , struct V_44 * V_44 , unsigned int V_84 , unsigned long V_77 )
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
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
F_2 ( V_11 L_14 ,
( int ) V_43 , ( int ) V_14 -> V_5 , ( int ) V_75 ) ;
return F_38 ( V_14 , V_75 ) ;
#else
return - 1 ;
#endif
break;
case V_90 :
if ( ( V_85 = F_30 ( V_87 , & V_14 -> V_5 , sizeof( V_14 -> V_5 ) ) ) )
return V_85 ;
break;
case V_91 :
if ( ! V_12 )
return - V_88 ;
if ( ( V_85 = F_30 ( V_87 , V_12 -> V_19 -> V_32 -> V_39 ,
strlen ( V_12 -> V_19 -> V_32 -> V_39 ) ) ) )
return V_85 ;
break;
case V_92 :
if ( ( V_85 = F_30 ( V_87 , & V_14 -> V_60 , sizeof( V_14 -> V_60 ) ) ) )
return V_85 ;
break;
case V_93 :
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_14 -> V_60 = V_75 ;
break;
case V_94 :
if ( ( V_85 = F_30 ( V_87 , & V_14 -> V_59 , sizeof( V_14 -> V_59 ) ) ) )
return V_85 ;
break;
case V_95 :
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) ) {
return V_85 ;
}
if ( V_75 & V_96 && ! ( V_14 -> V_59 & V_96 ) && ( V_14 -> V_24 & V_25 ) ) {
if ( V_12 ) {
V_14 -> V_59 = V_75 ;
F_39 ( V_12 -> V_19 -> V_32 ) ;
break;
}
}
V_14 -> V_59 = V_75 ;
break;
case V_97 :
if ( V_12 ) {
struct V_98 V_99 ;
V_99 . V_100 = V_99 . V_101 = V_12 -> V_102 ;
if ( ( V_85 = F_30 ( V_87 , & V_99 , sizeof( struct V_98 ) ) ) )
return V_85 ;
}
break;
case V_103 :
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
return V_85 ;
V_14 -> V_62 = V_75 ;
break;
case V_104 :
break;
case V_105 :
break;
case V_106 :
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
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
if ( ( V_85 = F_30 ( V_87 , & V_14 -> V_28 , sizeof( V_14 -> V_28 ) ) ) )
return V_85 ;
break;
case V_111 :
if ( ( V_85 = F_28 ( V_87 , & V_75 , sizeof( V_75 ) ) ) )
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
if ( ( V_85 = F_30 ( V_87 , V_113 , 8 * sizeof( long ) ) ) )
return V_85 ;
}
break;
case V_118 :
if ( ( V_85 = F_28 ( V_87 , & V_2 , sizeof( struct V_86 ) ) ) )
return V_85 ;
return F_40 ( V_14 , & V_2 ) ;
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
return F_30 ( V_87 , & V_121 , sizeof( struct V_120 ) ) ;
}
#ifdef F_21
case V_135 :
{
struct V_79 V_136 ;
struct V_78 * V_81 ;
int V_82 , V_3 = F_32 ( V_87 , & V_81 ) ;
if ( V_3 < 0 )
return V_3 ;
V_136 . V_3 = V_3 ;
V_136 . V_83 = V_81 ;
if ( V_14 -> V_71 )
F_26 ( V_14 -> V_71 ) ;
V_82 = F_41 ( & V_14 -> V_71 , & V_136 ) ;
F_24 ( V_81 ) ;
return V_82 ;
}
case V_137 :
{
struct V_79 V_136 ;
struct V_78 * V_81 ;
int V_82 , V_3 = F_32 ( V_87 , & V_81 ) ;
if ( V_3 < 0 )
return V_3 ;
V_136 . V_3 = V_3 ;
V_136 . V_83 = V_81 ;
if ( V_14 -> V_72 )
F_26 ( V_14 -> V_72 ) ;
V_82 = F_41 ( & V_14 -> V_72 , & V_136 ) ;
F_24 ( V_81 ) ;
return V_82 ;
}
#endif
default:
break;
}
return 0 ;
}
unsigned int
F_42 ( struct V_44 * V_44 , T_4 * V_138 )
{
T_5 V_139 ;
struct V_140 * V_141 , * V_142 ;
T_6 V_132 ;
struct V_13 * V_14 ;
V_14 = V_44 -> V_47 ;
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_17 ,
F_43 ( F_44 ( V_44 ) ) ) ;
F_45 ( V_44 , & V_14 -> V_41 , V_138 ) ;
if ( ! ( V_14 -> V_24 & V_27 ) ) {
if ( V_14 -> V_24 == V_42 )
return V_143 ;
F_2 ( V_11 L_18 ) ;
return V_144 ;
}
V_139 = V_145 | V_146 ;
F_46 ( & V_14 -> V_147 , V_132 ) ;
V_142 = V_14 -> V_69 ;
V_141 = V_14 -> V_66 ;
if ( V_141 -> V_35 != V_142 || ( V_14 -> V_24 & V_40 ) ) {
V_14 -> V_24 &= ~ V_40 ;
V_139 |= V_148 | V_149 ;
}
F_47 ( & V_14 -> V_147 , V_132 ) ;
return V_139 ;
}
static int
F_48 ( unsigned char * V_10 , int V_3 , int V_150 , int V_6 )
{
struct V_140 * V_141 , * V_142 ;
T_6 V_132 ;
T_7 * V_151 ;
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
V_151 = F_49 ( V_3 + 4 , V_152 ) ;
if ( ! V_151 ) {
F_2 ( V_37 L_21 ) ;
return 0 ;
}
V_151 [ 0 ] = V_153 ;
V_151 [ 1 ] = V_154 ;
V_151 [ 2 ] = V_150 >> 8 ;
V_151 [ 3 ] = V_150 & 0xff ;
memcpy ( V_151 + 4 , V_10 , V_3 ) ;
F_46 ( & V_14 -> V_147 , V_132 ) ;
V_141 = V_14 -> V_66 ;
V_142 = V_14 -> V_69 ;
if ( V_141 == V_142 ) {
F_2 ( V_37 L_22 ) ;
V_141 = V_141 -> V_35 ;
F_24 ( V_141 -> V_10 ) ;
V_14 -> V_66 = V_141 ;
}
V_142 -> V_10 = ( char * ) V_151 ;
V_142 -> V_3 = V_3 + 4 ;
V_14 -> V_69 = V_142 -> V_35 ;
F_47 ( & V_14 -> V_147 , V_132 ) ;
F_14 ( & V_14 -> V_41 ) ;
return V_3 ;
}
int
F_50 ( int V_43 , struct V_44 * V_44 , char T_3 * V_10 , int V_155 )
{
struct V_13 * V_14 ;
struct V_140 * V_74 ;
T_6 V_132 ;
T_7 * V_156 ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_27 ) )
return 0 ;
if ( ! F_51 ( V_157 , V_10 , V_155 ) )
return - V_76 ;
F_46 ( & V_14 -> V_147 , V_132 ) ;
V_74 = V_14 -> V_66 -> V_35 ;
V_156 = V_74 -> V_10 ;
if ( ! V_156 ) {
F_47 ( & V_14 -> V_147 , V_132 ) ;
return - V_158 ;
}
if ( V_74 -> V_3 < V_155 )
V_155 = V_74 -> V_3 ;
V_74 -> V_10 = NULL ;
V_14 -> V_66 = V_74 ;
F_47 ( & V_14 -> V_147 , V_132 ) ;
if ( F_31 ( V_10 , V_156 , V_155 ) )
V_155 = - V_76 ;
F_24 ( V_156 ) ;
return V_155 ;
}
int
F_52 ( int V_43 , struct V_44 * V_44 , const char T_3 * V_10 , int V_155 )
{
T_1 * V_12 ;
struct V_13 * V_14 ;
int V_150 ;
unsigned char V_159 [ 4 ] ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_25 ) )
return 0 ;
V_12 = V_14 -> V_12 ;
if ( ! V_12 )
F_2 ( V_11 L_23 ) ;
else {
if ( F_29 ( V_159 , V_10 , 4 ) )
return - V_76 ;
V_150 = F_53 ( V_159 ) ;
if ( V_150 != V_160 )
V_12 -> V_102 = 0 ;
if ( V_12 -> V_161 < 0 || V_12 -> V_162 < 0 )
return 0 ;
if ( ( V_32 -> V_163 [ V_12 -> V_161 ] -> V_132 & V_164 ) &&
V_12 -> V_165 == 0 &&
( V_12 -> V_132 & V_166 ) ) {
unsigned short V_167 ;
struct V_168 * V_169 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 ;
V_169 = F_54 ( V_167 + V_155 , V_152 ) ;
if ( ! V_169 ) {
F_2 ( V_37 L_24 ) ;
return V_155 ;
}
F_55 ( V_169 , V_167 ) ;
if ( F_29 ( F_56 ( V_169 , V_155 ) , V_10 , V_155 ) )
{
F_57 ( V_169 ) ;
return - V_76 ;
}
if ( V_14 -> V_28 & 0x40 ) {
F_2 ( V_11 L_25 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_26 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
F_58 ( V_12 -> V_19 , V_12 , V_169 ) ;
F_59 ( V_12 , V_169 ) ;
}
}
return V_155 ;
}
int
F_60 ( void )
{
int V_9 ,
V_8 ;
#ifdef F_4
if ( F_61 () < 0 )
return - V_109 ;
#endif
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( ! ( V_23 [ V_9 ] = F_62 ( sizeof( struct V_13 ) , V_172 ) ) ) {
F_2 ( V_37 L_27 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_24 ( V_23 [ V_8 ] ) ;
return - 1 ;
}
F_63 ( & V_23 [ V_9 ] -> V_147 ) ;
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
F_64 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_24 ( V_23 [ V_9 ] ) ;
#ifdef F_4
F_24 ( V_173 ) ;
#endif
}
static int F_65 ( struct V_13 * V_14 , struct V_168 * V_169 )
{
if ( V_169 -> V_3 < 1 )
return - 1 ;
if ( V_169 -> V_2 [ 0 ] == 0xff ) {
if ( V_169 -> V_3 < 2 )
return - 1 ;
if ( V_169 -> V_2 [ 1 ] != 0x03 )
return - 1 ;
F_66 ( V_169 , 2 ) ;
} else {
if ( V_14 -> V_59 & V_174 )
return - 1 ;
}
return 0 ;
}
static int F_67 ( struct V_168 * V_169 )
{
int V_150 ;
if ( V_169 -> V_3 < 1 )
return - 1 ;
if ( V_169 -> V_2 [ 0 ] & 0x1 ) {
V_150 = V_169 -> V_2 [ 0 ] ;
F_66 ( V_169 , 1 ) ;
} else {
if ( V_169 -> V_3 < 2 )
return - 1 ;
V_150 = ( ( int ) V_169 -> V_2 [ 0 ] << 8 ) + V_169 -> V_2 [ 1 ] ;
F_66 ( V_169 , 2 ) ;
}
return V_150 ;
}
void F_68 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 )
{
struct V_13 * V_14 ;
int V_6 ;
int V_150 ;
F_69 ( V_31 -> V_34 -> V_175 ) ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_28 ,
V_12 -> V_15 ) ;
F_57 ( V_169 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x4 ) {
F_2 ( V_11 L_29 ,
( long ) V_14 , ( long ) V_12 , V_12 -> V_15 , V_14 -> V_5 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_30 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( F_65 ( V_14 , V_169 ) < 0 ) {
F_57 ( V_169 ) ;
return;
}
V_150 = F_67 ( V_169 ) ;
if ( V_150 < 0 ) {
F_57 ( V_169 ) ;
return;
}
#ifdef F_4
if ( V_14 -> V_56 & V_176 ) {
V_169 = F_70 ( V_169 , V_14 , NULL , & V_150 ) ;
if ( ! V_169 )
return;
}
if ( ! ( V_14 -> V_60 & V_177 ) ) {
if ( V_150 == V_178 ) {
F_71 ( V_31 , V_12 , V_169 ) ;
return;
}
}
#endif
F_72 ( V_31 , V_12 , V_169 , V_150 ) ;
}
static void
F_72 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 , int V_150 )
{
struct V_179 * V_32 = V_31 -> V_32 ;
struct V_13 * V_14 , * V_180 ;
T_1 * V_181 = NULL ;
int V_6 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_31 ,
V_12 -> V_15 ) ;
goto V_182;
}
V_14 = V_23 [ V_6 ] ;
if ( V_12 -> V_175 ) {
V_181 = F_73 ( V_12 ) ;
V_6 = V_181 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_32 ,
V_12 -> V_15 ) ;
goto V_182;
}
}
V_180 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x10 ) {
F_2 ( V_11 L_33 , ( int ) V_169 -> V_3 , V_150 ) ;
F_1 ( L_34 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( V_180 -> V_56 & V_183 ) {
V_169 = F_70 ( V_169 , V_14 , V_180 , & V_150 ) ;
if ( ! V_169 )
return;
}
switch ( V_150 ) {
case V_184 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_35 ) ;
V_169 -> V_185 = F_74 ( V_186 ) ;
break;
case V_187 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_36 ) ;
V_169 -> V_185 = F_74 ( V_188 ) ;
break;
case V_189 :
case V_190 :
F_2 ( V_191 L_37 ) ;
goto V_182;
#ifdef F_19
case V_192 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_38 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_39 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_182;
}
if ( F_75 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_70 , V_169 -> V_2 , V_169 -> V_3 ) <= 0 ) {
F_2 ( V_37 L_40 ) ;
goto V_182;
}
V_169 -> V_185 = F_74 ( V_188 ) ;
break;
case V_193 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_41 ) ;
{
struct V_168 * V_194 = V_169 ;
int V_195 ;
V_169 = F_76 ( V_194 -> V_3 + 128 ) ;
if ( ! V_169 ) {
F_2 ( V_37 L_42 , V_32 -> V_39 ) ;
V_169 = V_194 ;
goto V_182;
}
F_56 ( V_169 , V_194 -> V_3 + 128 ) ;
F_77 ( V_194 , V_169 -> V_2 ,
V_194 -> V_3 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_39 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_182;
}
V_195 = F_78 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_70 ,
V_169 -> V_2 , V_194 -> V_3 ) ;
F_57 ( V_194 ) ;
if ( V_195 < 0 )
goto V_182;
F_79 ( V_169 , V_195 ) ;
V_169 -> V_185 = F_74 ( V_188 ) ;
}
break;
#endif
case V_196 :
case V_197 :
F_80 ( V_31 , V_12 , V_169 , V_150 ) ;
if ( V_169 -> V_2 [ 0 ] == V_198 ||
V_169 -> V_2 [ 0 ] == V_199 )
break;
default:
F_48 ( V_169 -> V_2 , V_169 -> V_3 , V_150 , V_12 -> V_15 ) ;
F_57 ( V_169 ) ;
return;
}
#ifdef F_21
F_81 ( V_169 , 4 ) ;
{
T_8 * V_73 = ( T_8 * ) V_169 -> V_2 ;
* V_73 = 0 ;
}
if ( V_14 -> V_71
&& F_82 ( V_14 -> V_71 , V_169 ) == 0 ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_43 ) ;
F_57 ( V_169 ) ;
return;
}
if ( ! ( V_14 -> V_72
&& F_82 ( V_14 -> V_72 , V_169 ) == 0 ) ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_44 ) ;
V_12 -> V_102 = 0 ;
if ( V_181 )
V_181 -> V_102 = 0 ;
}
F_66 ( V_169 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
if ( V_181 )
V_181 -> V_102 = 0 ;
#endif
V_169 -> V_32 = V_32 ;
F_83 ( V_169 ) ;
F_84 ( V_169 ) ;
return;
V_182:
V_31 -> V_34 -> V_200 . V_201 ++ ;
F_57 ( V_169 ) ;
}
static unsigned char * F_85 ( struct V_168 * * V_202 , int V_3 )
{
struct V_168 * V_169 = * V_202 ;
if ( F_86 ( V_169 ) < V_3 ) {
struct V_168 * V_203 = F_87 ( V_169 , V_3 ) ;
if ( ! V_203 ) {
F_2 ( V_17 L_45 ) ;
F_88 ( V_169 ) ;
return NULL ;
}
F_2 ( V_11 L_46 , F_86 ( V_169 ) , V_3 ) ;
F_88 ( V_169 ) ;
* V_202 = V_203 ;
return F_81 ( V_203 , V_3 ) ;
}
return F_81 ( V_169 , V_3 ) ;
}
int
F_89 ( struct V_168 * V_169 , struct V_179 * V_19 )
{
T_1 * V_12 , * V_181 ;
T_2 * V_204 ;
unsigned int V_150 = V_187 ;
struct V_13 * V_205 , * V_206 ;
int V_6 , V_29 = V_207 ;
V_181 = F_90 ( V_19 ) ;
V_204 = V_181 -> V_19 ;
V_6 = V_181 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_47 ,
V_181 -> V_15 ) ;
F_57 ( V_169 ) ;
goto V_38;
}
V_206 = V_23 [ V_6 ] ;
if ( ! ( V_206 -> V_59 & V_96 ) ) {
if ( V_206 -> V_28 & 0x1 )
F_2 ( V_191 L_48 , V_19 -> V_39 ) ;
V_29 = V_208 ;
goto V_38;
}
switch ( F_91 ( V_169 -> V_185 ) ) {
case V_188 :
V_150 = V_187 ;
break;
case V_186 :
V_150 = V_184 ;
break;
default:
F_2 ( V_17 L_49 ,
V_169 -> V_185 ) ;
F_88 ( V_169 ) ;
goto V_38;
}
V_12 = F_92 ( V_204 ) ;
if ( ! V_12 ) {
F_2 ( V_37 L_50 , V_19 -> V_39 ) ;
V_29 = V_208 ;
goto V_38;
}
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_47 ,
V_12 -> V_15 ) ;
F_57 ( V_169 ) ;
goto V_209;
}
V_205 = V_23 [ V_6 ] ;
F_66 ( V_169 , V_210 ) ;
#ifdef F_21
* F_81 ( V_169 , 4 ) = 1 ;
{
T_9 * V_73 = ( T_9 * ) V_169 -> V_2 ;
V_73 ++ ;
* V_73 = F_74 ( V_150 ) ;
}
if ( V_205 -> V_71
&& F_82 ( V_205 -> V_71 , V_169 ) == 0 ) {
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_51 ) ;
F_57 ( V_169 ) ;
goto V_209;
}
if ( ! ( V_205 -> V_72
&& F_82 ( V_205 -> V_72 , V_169 ) == 0 ) ) {
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_44 ) ;
V_12 -> V_102 = 0 ;
}
F_66 ( V_169 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
#endif
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_52 , ( int ) V_169 -> V_3 ) ;
if ( V_206 -> V_28 & 0x40 )
F_1 ( L_53 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_206 -> V_5 , V_12 -> V_15 ) ;
#ifdef F_19
if ( V_150 == V_187 && V_206 -> V_59 & V_211 ) {
struct V_168 * V_212 ;
unsigned short V_167 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 + V_210 ;
V_212 = F_54 ( V_167 + V_169 -> V_3 , V_152 ) ;
if ( V_212 ) {
T_7 * V_10 ;
int V_213 ;
F_55 ( V_212 , V_167 ) ;
V_212 -> V_32 = V_169 -> V_32 ;
F_56 ( V_212 , V_169 -> V_3 ) ;
V_10 = V_169 -> V_2 ;
V_213 = F_93 ( V_206 -> V_70 , V_169 -> V_2 , V_169 -> V_3 , V_212 -> V_2 ,
& V_10 , ! ( V_206 -> V_59 & V_214 ) ) ;
if ( V_10 != V_169 -> V_2 ) {
if ( V_212 -> V_2 != V_10 )
F_2 ( V_17 L_54 ) ;
F_88 ( V_169 ) ;
V_169 = V_212 ;
} else {
F_88 ( V_212 ) ;
}
F_79 ( V_169 , V_213 ) ;
if ( V_169 -> V_2 [ 0 ] & V_215 ) {
V_150 = V_193 ;
V_169 -> V_2 [ 0 ] ^= V_215 ;
} else {
if ( V_169 -> V_2 [ 0 ] >= V_216 )
V_150 = V_192 ;
V_169 -> V_2 [ 0 ] = ( V_169 -> V_2 [ 0 ] & 0x0f ) | 0x40 ;
}
}
}
#endif
if ( V_206 -> V_56 & V_217 ) {
if ( V_206 -> V_56 & V_183 ) {
V_169 = F_94 ( V_169 , & V_150 , V_205 , V_206 , 0 ) ;
} else {
F_2 ( V_11 L_55 ) ;
}
}
if ( V_205 -> V_28 & 0x24 )
F_2 ( V_11 L_56 , ( int ) V_169 -> V_3 , V_150 ) ;
#ifdef F_4
if ( V_205 -> V_60 & V_218 ) {
long V_58 = V_206 -> V_58 ;
V_206 -> V_58 ++ ;
if ( V_205 -> V_60 & V_219 ) {
unsigned char * V_2 = F_85 ( & V_169 , 3 ) ;
if ( ! V_2 )
goto V_209;
V_58 &= 0xfff ;
V_2 [ 0 ] = V_220 | V_221 | ( ( V_58 >> 8 ) & 0xf ) ;
V_2 [ 1 ] = V_58 & 0xff ;
V_2 [ 2 ] = V_150 ;
} else {
unsigned char * V_2 = F_85 ( & V_169 , 5 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = V_220 | V_221 ;
V_2 [ 1 ] = ( V_58 >> 16 ) & 0xff ;
V_2 [ 2 ] = ( V_58 >> 8 ) & 0xff ;
V_2 [ 3 ] = ( V_58 >> 0 ) & 0xff ;
V_2 [ 4 ] = V_150 ;
}
V_150 = V_178 ;
}
#endif
if ( V_205 -> V_56 & V_222 )
V_169 = F_94 ( V_169 , & V_150 , V_205 , V_206 , 1 ) ;
if ( ( V_205 -> V_59 & V_223 ) && ( V_150 <= 0xff ) ) {
unsigned char * V_2 = F_85 ( & V_169 , 1 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = V_150 & 0xff ;
}
else {
unsigned char * V_2 = F_85 ( & V_169 , 2 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = ( V_150 >> 8 ) & 0xff ;
V_2 [ 1 ] = V_150 & 0xff ;
}
if ( ! ( V_205 -> V_59 & V_224 ) ) {
unsigned char * V_2 = F_85 ( & V_169 , 2 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = 0xff ;
V_2 [ 1 ] = 0x03 ;
}
if ( V_206 -> V_28 & 0x40 ) {
F_2 ( V_11 L_57 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_26 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_205 -> V_5 , V_12 -> V_15 ) ;
}
F_95 ( V_12 , V_169 ) ;
V_209:
F_96 ( & V_12 -> V_225 ) ;
V_38:
return V_29 ;
}
int F_97 ( struct V_168 * V_169 , T_1 * V_12 )
{
struct V_13 * V_14 = V_23 [ V_12 -> V_15 ] ;
T_8 V_150 ;
int V_226 = 0 ;
switch ( F_91 ( V_169 -> V_185 ) ) {
case V_188 :
V_150 = V_187 ;
break;
case V_186 :
V_150 = V_184 ;
break;
default:
F_2 ( V_17 L_58 ,
V_169 -> V_185 ) ;
return 1 ;
}
* F_66 ( V_169 , V_210 - 4 ) = 1 ;
{
T_9 * V_73 = ( T_9 * ) V_169 -> V_2 ;
V_73 ++ ;
* V_73 = F_74 ( V_150 ) ;
}
V_226 |= V_14 -> V_71
&& F_82 ( V_14 -> V_71 , V_169 ) == 0 ;
V_226 |= V_14 -> V_72
&& F_82 ( V_14 -> V_72 , V_169 ) == 0 ;
F_81 ( V_169 , V_210 - 4 ) ;
return V_226 ;
}
static int F_61 ( void )
{
int V_9 ;
int V_227 = V_16 * sizeof( V_228 ) ;
if ( ( V_173 = F_62 ( V_227 , V_172 ) ) == NULL )
return - V_109 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_63 ( & V_173 [ V_9 ] . V_21 ) ;
return 0 ;
}
static V_228 * F_98 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( V_173 [ V_9 ] . V_22 <= 0 )
return ( V_173 + V_9 ) ;
return NULL ;
}
static int F_12 ( T_1 * V_12 , V_228 * V_229 )
{
struct V_13 * V_14 ;
if ( V_12 -> V_15 < 0 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return ( - V_88 ) ;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
if ( V_229 ) {
if ( V_12 -> V_19 -> V_20 )
V_12 -> V_19 -> V_20 -> V_22 -- ;
V_12 -> V_19 -> V_20 = V_229 ;
} else {
V_14 -> V_58 = 0 ;
if ( ( V_12 -> V_19 -> V_20 = F_98 () ) == NULL )
return - V_109 ;
V_12 -> V_35 = V_12 -> V_69 = V_12 ;
V_12 -> V_19 -> V_20 -> V_230 = NULL ;
V_12 -> V_19 -> V_20 -> V_231 = 0 ;
V_12 -> V_19 -> V_20 -> V_232 = V_233 ;
}
V_12 -> V_19 -> V_20 -> V_22 ++ ;
V_14 -> V_61 = 0 ;
return 0 ;
}
static void F_71 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 ;
T_1 * V_234 ;
V_228 * V_235 ;
T_10 * V_200 ;
struct V_168 * V_236 , * V_237 , * V_238 , * V_239 ;
T_11 V_240 , V_241 , V_242 ;
unsigned long V_132 ;
int V_6 ;
F_46 ( & V_31 -> V_20 -> V_21 , V_132 ) ;
V_235 = V_31 -> V_20 ;
V_200 = & V_235 -> V_200 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_60 ,
V_18 , V_12 -> V_15 ) ;
V_200 -> V_243 ++ ;
F_88 ( V_169 ) ;
F_47 ( & V_235 -> V_21 , V_132 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( ++ V_235 -> V_231 > V_200 -> V_244 )
V_200 -> V_244 = V_235 -> V_231 ;
if ( V_14 -> V_28 & 0x8 )
F_99 ( V_12 -> V_15 , V_169 ) ;
V_240 = F_100 ( V_14 -> V_60 & V_245 ,
V_169 , V_14 -> V_61 ) ;
if ( V_235 -> V_232 > V_246 && ( V_240 & V_247 ) ) {
V_235 -> V_232 = V_240 ;
} else if ( F_101 ( V_240 , V_235 -> V_232 ) ) {
V_200 -> V_243 ++ ;
F_102 ( V_235 , V_169 ) ;
F_47 ( & V_235 -> V_21 , V_132 ) ;
return;
}
V_14 -> V_61 = V_241 = V_240 ;
for ( V_234 = V_31 -> V_248 ; ; ) {
V_6 = V_234 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_61 ,
V_18 , V_234 -> V_15 ) ;
} else {
T_11 V_249 = V_23 [ V_6 ] -> V_61 ;
if ( F_101 ( V_249 , V_241 ) )
V_241 = V_249 ;
}
if ( ( V_234 = V_234 -> V_35 ) == V_31 -> V_248 )
break;
}
if ( F_101 ( V_241 , V_235 -> V_232 ) )
V_241 = V_235 -> V_232 ;
V_236 = V_169 ;
if ( ( V_237 = V_235 -> V_230 ) == NULL || F_101 ( V_240 , F_103 ( V_237 ) ) ) {
V_236 -> V_35 = V_237 ;
V_235 -> V_230 = V_237 = V_236 ;
V_236 = NULL ;
}
V_238 = F_104 ( V_237 ) & V_220 &&
F_103 ( V_237 ) == V_235 -> V_232 ? V_237 : NULL ;
while ( V_238 != NULL || V_236 != NULL ) {
V_242 = F_103 ( V_237 ) ;
V_239 = V_237 -> V_35 ;
if ( V_236 != NULL && V_242 == V_240 ) {
F_102 ( V_235 , V_236 ) ;
V_236 = NULL ;
}
if ( V_236 != NULL && ( V_239 == NULL ||
F_101 ( V_240 , F_103 ( V_239 ) ) ) ) {
V_236 -> V_35 = V_239 ;
V_237 -> V_35 = V_239 = V_236 ;
V_236 = NULL ;
}
if ( V_238 != NULL ) {
if ( V_238 != V_237 && ( F_104 ( V_237 ) & V_220 ) ) {
F_2 ( V_37 L_62
L_63 , V_242 ) ;
V_200 -> V_250 ++ ;
V_200 -> V_243 ++ ;
V_238 = F_105 ( V_235 , V_238 , V_237 ) ;
V_239 = V_237 -> V_35 ;
}
} else if ( F_106 ( V_242 , V_241 ) ) {
if ( F_104 ( V_237 ) & V_220 )
V_238 = V_237 ;
else {
if ( F_104 ( V_237 ) & V_221 )
V_200 -> V_243 ++ ;
if ( V_235 -> V_230 == V_237 )
V_235 -> V_230 = V_239 ;
F_102 ( V_235 , V_237 ) ;
V_237 = V_239 ;
continue;
}
}
if ( V_238 != NULL && ( F_104 ( V_237 ) & V_221 ) ) {
V_241 = V_235 -> V_232 = ( V_242 + 1 ) & V_251 ;
F_107 ( V_31 , V_12 , V_238 , V_239 ) ;
V_238 = NULL ;
V_237 = NULL ;
V_235 -> V_230 = V_239 ;
}
if ( V_239 != NULL &&
( ( V_242 + 1 ) & V_251 ) == F_103 ( V_239 ) ) {
if ( V_237 == NULL ) {
if ( F_104 ( V_239 ) & V_220 )
V_238 = V_239 ;
else
{
F_2 ( V_37 L_64
L_65
L_66 , V_242 ) ;
V_200 -> V_250 ++ ;
}
}
} else {
if ( V_239 != NULL && V_237 != NULL &&
F_101 ( V_242 , V_241 ) ) {
V_200 -> V_243 ++ ;
V_235 -> V_230 = F_105 ( V_235 , V_238 , V_239 ) ;
}
V_238 = NULL ;
}
V_237 = V_239 ;
}
if ( V_235 -> V_230 == NULL )
V_235 -> V_230 = V_237 ;
if ( V_235 -> V_231 > V_252 ) {
V_200 -> V_253 ++ ;
while ( V_235 -> V_231 > V_252 ) {
V_237 = V_235 -> V_230 -> V_35 ;
F_102 ( V_235 , V_235 -> V_230 ) ;
V_235 -> V_230 = V_237 ;
}
}
F_47 ( & V_235 -> V_21 , V_132 ) ;
}
static void F_7 ( T_1 * V_12 )
{
struct V_168 * V_237 = V_12 -> V_19 -> V_20 -> V_230 ;
struct V_168 * V_254 ;
while ( V_237 ) {
V_254 = V_237 -> V_35 ;
F_102 ( V_12 -> V_19 -> V_20 , V_237 ) ;
V_237 = V_254 ;
}
V_12 -> V_19 -> V_20 -> V_230 = NULL ;
}
static T_11 F_100 ( int V_255 ,
struct V_168 * V_169 , T_11 V_256 )
{
T_11 V_232 ;
int V_132 = V_169 -> V_2 [ 0 ] & ( V_220 | V_221 ) ;
if ( ! V_255 )
{
V_232 = F_108 ( * ( V_257 * ) V_169 -> V_2 ) & V_251 ;
F_81 ( V_169 , 1 ) ;
}
else
{
V_232 = F_91 ( * ( T_9 * ) V_169 -> V_2 ) & V_258 ;
if ( ! ( V_232 & V_259 ) &&
( V_256 & V_259 ) &&
( unsigned long ) V_256 <= V_246 )
V_232 |= ( V_256 + V_260 + 1 ) &
( ~ V_258 & V_251 ) ;
else
V_232 |= V_256 & ( ~ V_258 & V_251 ) ;
F_81 ( V_169 , 3 ) ;
}
* ( T_11 * ) ( V_169 -> V_2 + 1 ) = V_232 ;
V_169 -> V_2 [ 0 ] = V_132 ;
return V_232 ;
}
struct V_168 * F_105 ( V_228 * V_235 ,
struct V_168 * V_261 , struct V_168 * V_262 )
{
if ( V_261 )
while ( V_261 != V_262 ) {
struct V_168 * V_35 = V_261 -> V_35 ;
F_102 ( V_235 , V_261 ) ;
V_261 = V_35 ;
}
return V_261 ;
}
void F_107 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_261 , struct V_168 * V_262 )
{
V_228 * V_235 = V_31 -> V_20 ;
int V_150 ;
struct V_168 * V_169 ;
unsigned int V_263 ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return;
}
if ( F_104 ( V_261 ) == ( V_220 | V_221 ) ) {
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_67
L_68 , F_103 ( V_261 ) , V_261 -> V_3 ) ;
V_169 = V_261 ;
F_66 ( V_169 , V_264 ) ;
V_235 -> V_231 -- ;
} else {
struct V_168 * V_237 ;
int V_265 ;
for ( V_263 = V_265 = 0 , V_237 = V_261 ; V_237 != V_262 ; V_237 = V_237 -> V_35 , V_265 ++ )
V_263 += V_237 -> V_3 - V_264 ;
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_69
L_70 , F_103 ( V_261 ) ,
( F_103 ( V_261 ) + V_265 - 1 ) & V_251 , V_263 ) ;
if ( ( V_169 = F_76 ( V_263 ) ) == NULL ) {
F_2 ( V_17 L_71
L_72 , V_263 ) ;
F_105 ( V_235 , V_261 , V_262 ) ;
return;
}
while ( V_261 != V_262 ) {
unsigned int V_3 = V_261 -> V_3 - V_264 ;
F_109 ( V_261 , V_264 ,
F_56 ( V_169 , V_3 ) ,
V_3 ) ;
V_237 = V_261 -> V_35 ;
F_102 ( V_235 , V_261 ) ;
V_261 = V_237 ;
}
}
V_150 = F_67 ( V_169 ) ;
F_72 ( V_31 , V_12 , V_169 , V_150 ) ;
}
static void F_102 ( V_228 * V_235 , struct V_168 * V_169 )
{
F_88 ( V_169 ) ;
V_235 -> V_231 -- ;
}
static void F_99 ( int V_6 , struct V_168 * V_169 )
{
F_2 ( V_11 L_73 ,
V_6 , ( int ) V_169 -> V_3 ,
( int ) V_169 -> V_2 [ 0 ] , ( int ) V_169 -> V_2 [ 1 ] , ( int ) V_169 -> V_2 [ 2 ] ,
( int ) V_169 -> V_2 [ 3 ] , ( int ) V_169 -> V_2 [ 4 ] , ( int ) V_169 -> V_2 [ 5 ] ) ;
}
static int
F_38 ( struct V_13 * V_14 , int V_5 )
{
char V_266 [ V_267 + 1 ] ;
T_2 * V_73 ;
T_1 * V_12 , * V_268 ;
int V_269 ;
unsigned long V_132 ;
sprintf ( V_266 , L_74 , V_5 ) ;
V_73 = F_110 ( V_266 ) ;
if ( ! V_73 ) {
F_2 ( V_17 L_75 , V_266 ) ;
return - V_88 ;
}
F_46 ( & V_73 -> V_20 -> V_21 , V_132 ) ;
V_268 = V_14 -> V_12 ;
V_12 = V_73 -> V_248 ;
if ( V_268 -> V_15 < 0 || V_268 -> V_15 >= V_16 ||
V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_76 ,
V_268 -> V_15 < 0 || V_268 -> V_15 >= V_16 ?
V_268 -> V_15 : V_12 -> V_15 ) ;
V_269 = - V_88 ;
goto V_38;
}
F_111 ( V_73 , V_268 ) ;
V_23 [ V_268 -> V_15 ] -> V_5 = V_23 [ V_12 -> V_15 ] -> V_5 ;
V_23 [ V_268 -> V_15 ] -> V_59 |= V_23 [ V_12 -> V_15 ] -> V_59 &
( V_96 | V_214 | V_270 ) ;
V_23 [ V_268 -> V_15 ] -> V_60 |= V_23 [ V_12 -> V_15 ] -> V_60 &
( V_218 | V_177 | V_219 | V_245 ) ;
V_269 = F_12 ( V_268 , V_73 -> V_20 ) ;
V_38:
F_47 ( & V_73 -> V_20 -> V_21 , V_132 ) ;
return V_269 ;
}
static int
F_112 ( int V_6 , struct V_271 * V_272 , struct V_179 * V_32 )
{
struct V_273 T_3 * V_274 = V_272 -> V_275 ;
struct V_273 V_276 ;
T_1 * V_12 = F_90 ( V_32 ) ;
if ( ! F_51 ( V_157 , V_274 , sizeof( struct V_273 ) ) )
return - V_76 ;
memset ( & V_276 , 0 , sizeof( struct V_273 ) ) ;
if ( V_32 -> V_132 & V_277 ) {
V_276 . V_73 . V_278 = V_12 -> V_200 . V_279 ;
V_276 . V_73 . V_280 = V_12 -> V_200 . V_281 ;
V_276 . V_73 . V_282 = V_12 -> V_200 . V_283 ;
V_276 . V_73 . V_284 = V_12 -> V_200 . V_285 ;
V_276 . V_73 . V_286 = V_12 -> V_200 . V_287 ;
V_276 . V_73 . V_288 = V_12 -> V_200 . V_289 ;
#ifdef F_19
if ( V_6 >= 0 && V_23 [ V_6 ] -> V_70 ) {
struct V_107 * V_70 = V_23 [ V_6 ] -> V_70 ;
V_276 . V_290 . V_291 = V_70 -> V_292 + V_70 -> V_293 ;
V_276 . V_290 . V_294 = V_70 -> V_292 ;
V_276 . V_290 . V_295 = V_70 -> V_296 ;
V_276 . V_290 . V_297 = V_70 -> V_298 ;
V_276 . V_290 . V_299 = V_70 -> V_300 ;
V_276 . V_290 . V_301 = V_70 -> V_302 ;
V_276 . V_290 . V_303 = V_70 -> V_304 ;
V_276 . V_290 . V_305 = V_70 -> V_306 ;
}
#endif
}
if ( F_31 ( V_274 , & V_276 , sizeof( struct V_273 ) ) )
return - V_76 ;
return 0 ;
}
int
F_113 ( struct V_179 * V_32 , struct V_271 * V_272 , int V_84 )
{
int error = 0 ;
int V_3 ;
T_1 * V_12 = F_90 ( V_32 ) ;
if ( V_12 -> V_307 != V_308 )
return - V_88 ;
switch ( V_84 ) {
#define F_114 "2.3.7"
case V_309 :
V_3 = strlen ( F_114 ) + 1 ;
if ( F_31 ( V_272 -> V_275 , F_114 , V_3 ) )
error = - V_76 ;
break;
case V_310 :
error = F_112 ( V_12 -> V_15 , V_272 , V_32 ) ;
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
V_311 ;
V_3 = strlen ( V_39 ) ;
if ( strncmp ( L_77 , V_39 , 4 ) || V_3 > 8 )
return - 1 ;
for ( V_9 = 0 , V_311 = 1 ; V_9 < V_3 ; V_9 ++ , V_311 *= 10 ) {
char V_312 = V_39 [ V_3 - V_9 - 1 ] ;
if ( V_312 >= '0' && V_312 <= '9' )
V_5 += ( V_312 - '0' ) * V_311 ;
else
break;
}
if ( ! V_9 || V_3 - V_9 != 4 )
V_5 = - 1 ;
return V_5 ;
}
int
F_115 ( char * V_39 )
{
#ifdef F_4
T_2 * V_313 ;
T_1 * V_12 ;
struct V_179 * V_314 ;
if ( ! ( V_313 = F_110 ( V_39 ) ) )
return 1 ;
V_12 = V_313 -> V_34 ;
if ( ! ( V_12 -> V_132 & V_166 ) )
return 5 ;
V_314 = V_12 -> V_315 ;
while ( V_314 ) {
T_1 * V_181 = F_90 ( V_314 ) ;
if ( ! ( V_181 -> V_132 & V_166 ) )
break;
V_314 = V_181 -> V_315 ;
}
if ( ! V_314 )
return 2 ;
F_116 ( F_90 ( V_314 ) ) ;
return 0 ;
#else
return - 1 ;
#endif
}
int
F_117 ( char * V_39 )
{
#ifdef F_4
T_2 * V_313 ;
T_1 * V_12 ;
struct V_179 * V_314 ;
if ( ! ( V_313 = F_110 ( V_39 ) ) )
return 1 ;
V_12 = V_313 -> V_34 ;
if ( ! ( V_12 -> V_132 & V_166 ) )
return 5 ;
V_314 = V_12 -> V_315 ;
while ( V_314 ) {
T_1 * V_181 = F_90 ( V_314 ) ;
if ( V_181 -> V_315 ) {
T_1 * V_268 = F_118 ( V_181 ) ;
if ( ! ( V_268 -> V_132 & V_166 ) )
break;
} else if ( V_181 -> V_132 & V_166 )
break;
V_314 = V_181 -> V_315 ;
}
if ( ! V_314 )
return 2 ;
F_23 ( V_314 ) ;
return 0 ;
#else
return - 1 ;
#endif
}
static void F_119 ( struct V_13 * V_14 )
{
F_48 ( NULL , 0 , V_189 , V_14 -> V_12 -> V_15 ) ;
}
static void F_120 ( struct V_13 * V_14 , int V_150 ,
unsigned char V_81 , unsigned char V_316 ,
unsigned char * V_2 , int V_3 )
{
struct V_168 * V_169 ;
unsigned char * V_73 ;
int V_167 ;
int V_7 = 0 ;
T_1 * V_12 = V_14 -> V_12 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 ;
V_169 = F_54 ( V_3 + V_167 + 16 , V_152 ) ;
if ( ! V_169 ) {
F_2 ( V_37
L_78 ) ;
return;
}
F_55 ( V_169 , V_167 ) ;
if ( ! ( V_14 -> V_59 & V_224 ) ) {
V_73 = F_56 ( V_169 , 2 ) ;
* V_73 ++ = 0xff ;
* V_73 ++ = 0x03 ;
}
V_73 = F_56 ( V_169 , 6 ) ;
* V_73 ++ = ( V_150 >> 8 ) ;
* V_73 ++ = ( V_150 & 0xff ) ;
* V_73 ++ = V_81 ;
* V_73 ++ = V_316 ;
V_7 = 4 + V_3 ;
* V_73 ++ = ( V_7 >> 8 ) ;
* V_73 ++ = ( V_7 & 0xff ) ;
if ( V_3 ) {
V_73 = F_56 ( V_169 , V_3 ) ;
memcpy ( V_73 , V_2 , V_3 ) ;
}
F_2 ( V_11 L_79 ) ;
F_1 ( L_80 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
F_59 ( V_12 , V_169 ) ;
}
static struct V_317 * F_17 ( struct V_13 * V_14 )
{
struct V_317 * V_85 ;
V_85 = F_62 ( sizeof( struct V_317 ) , V_172 ) ;
if ( ! V_85 ) {
F_2 ( V_17 L_81
L_82 ) ;
return NULL ;
}
F_2 ( V_11 L_83 , V_85 ) ;
V_14 -> V_57 = V_85 ;
return V_85 ;
}
static void F_27 ( struct V_13 * V_14 )
{
unsigned int V_316 ;
F_2 ( V_11 L_84 ,
V_14 -> V_57 ) ;
for ( V_316 = 0 ; V_316 < 256 ; V_316 ++ ) {
if ( V_14 -> V_57 -> V_318 [ V_316 ] ) {
F_121 ( V_14 , ( unsigned char ) V_316 ) ;
}
}
F_24 ( V_14 -> V_57 ) ;
V_14 -> V_57 = NULL ;
}
static void F_121 ( struct V_13 * V_14 ,
unsigned char V_316 )
{
struct V_319 * V_318 ;
if ( V_14 -> V_57 -> V_318 [ V_316 ] ) {
F_2 ( V_11 L_85 , V_316 ) ;
V_318 = V_14 -> V_57 -> V_318 [ V_316 ] ;
if ( V_318 -> V_320 )
F_122 ( & V_318 -> V_321 ) ;
V_14 -> V_57 -> V_318 [ V_316 ] = NULL ;
F_24 ( V_318 ) ;
} else {
F_2 ( V_37 L_86 , V_316 ) ;
}
}
static void F_123 ( unsigned long V_322 )
{
struct V_319 * V_318 =
(struct V_319 * ) V_322 ;
if ( ! V_318 ) {
F_2 ( V_17 L_87 ) ;
return;
}
if ( V_318 -> V_320 && V_318 -> V_24 == V_323 ) {
if ( ! V_318 -> V_324 ) {
V_318 -> V_320 = 0 ;
F_121 ( V_318 -> V_14 , V_318 -> V_316 ) ;
return;
}
F_2 ( V_11 L_88 ,
V_318 -> V_316 ) ;
F_120 ( V_318 -> V_14 , V_196 , V_198 , V_318 -> V_316 ,
V_318 -> V_2 , V_318 -> V_325 ) ;
V_318 -> V_321 . V_326 = V_327 + V_328 * 5 ;
F_124 ( & V_318 -> V_321 ) ;
} else {
F_2 ( V_37 L_89 ,
V_318 -> V_24 ) ;
}
}
static struct V_319 * F_125 ( struct V_13 * V_14 ,
unsigned char V_316 )
{
struct V_319 * V_318 ;
if ( V_14 -> V_57 -> V_318 [ V_316 ] ) {
F_2 ( V_37 L_90 ,
V_316 ) ;
return NULL ;
} else {
V_318 = F_62 ( sizeof( struct V_319 ) , V_172 ) ;
if ( ! V_318 )
return NULL ;
V_318 -> V_24 = V_329 ;
V_318 -> V_14 = V_14 ;
V_318 -> V_316 = V_316 ;
F_126 ( & V_318 -> V_321 ) ;
V_318 -> V_321 . V_2 = ( unsigned long ) V_318 ;
V_318 -> V_321 . V_330 = F_123 ;
V_14 -> V_57 -> V_318 [ V_316 ] = V_318 ;
}
return V_318 ;
}
static void F_127 ( struct V_13 * V_14 ,
struct V_331 * V_332 )
{
struct V_319 * V_318 ;
if ( V_332 -> V_333 ) {
if ( V_332 -> V_334 ) {
if ( ! ( V_332 -> V_335 ) ) {
F_2 ( V_17 L_91
L_92 ) ;
return;
}
if ( V_14 -> V_57 -> V_318 [ V_332 -> V_316 ] ) {
V_318 = V_14 -> V_57 -> V_318 [ V_332 -> V_316 ] ;
if ( V_318 -> V_24 == V_323 && V_318 -> V_320 ) {
F_2 ( V_11 L_93
L_94
L_95 , V_332 -> V_316 ) ;
} else {
F_2 ( V_37 L_93
L_96
L_97 , V_318 -> V_24 , V_332 -> V_316 ) ;
}
} else {
F_2 ( V_11 L_98
L_99 , V_332 -> V_316 ) ;
V_318 = F_125 ( V_14 , V_332 -> V_316 ) ;
if ( ! V_318 ) {
F_2 ( V_17 L_100
L_101 ) ;
return;
}
V_318 -> V_24 = V_323 ;
V_318 -> V_324 = V_332 -> V_324 ;
if ( V_332 -> V_336 ) {
V_318 -> V_325 = V_332 -> V_325 ;
memcpy ( V_318 -> V_2 , V_332 -> V_2 , V_332 -> V_325 ) ;
}
F_120 ( V_14 , V_196 ,
V_198 , V_318 -> V_316 ,
V_318 -> V_2 , V_318 -> V_325 ) ;
V_318 -> V_321 . V_326 = V_327 + 5 * V_328 ;
F_124 ( & V_318 -> V_321 ) ;
V_318 -> V_320 = 1 ;
}
} else {
F_2 ( V_11 L_102 ) ;
}
} else {
if ( V_14 -> V_57 -> V_318 [ V_14 -> V_57 -> V_337 ] ) {
V_318 = V_14 -> V_57 -> V_318 [ V_14 -> V_57 -> V_337 ] ;
if ( V_318 -> V_24 == V_323 && V_318 -> V_320 ) {
F_2 ( V_11 L_93
L_94
L_95 , V_332 -> V_316 ) ;
} else {
F_2 ( V_37 L_93
L_96
L_97 , V_318 -> V_24 , V_332 -> V_316 ) ;
}
} else {
F_2 ( V_11 L_98
L_99 , V_14 -> V_57 -> V_337 ) ;
V_318 = F_125 ( V_14 ,
V_14 -> V_57 -> V_337 ) ;
if ( ! V_318 ) {
F_2 ( V_17 L_100
L_101 ) ;
return;
}
V_318 -> V_24 = V_323 ;
V_318 -> V_324 = 1 ;
V_318 -> V_325 = 0 ;
F_120 ( V_14 , V_196 , V_198 ,
V_318 -> V_316 , NULL , 0 ) ;
V_318 -> V_321 . V_326 = V_327 + 5 * V_328 ;
F_124 ( & V_318 -> V_321 ) ;
V_318 -> V_320 = 1 ;
}
}
}
static void F_128 ( struct V_13 * V_14 ,
unsigned char V_316 )
{
struct V_319 * V_318 = V_14 -> V_57 -> V_318 [ V_316 ] ;
if ( V_318 ) {
if ( V_318 -> V_320 && V_318 -> V_24 == V_323 ) {
if ( ! V_318 -> V_324 )
F_2 ( V_11 L_103
L_104 , V_316 ) ;
} else {
F_2 ( V_191 L_105
L_106 , V_316 ) ;
}
if ( V_318 -> V_320 ) {
V_318 -> V_320 = 0 ;
F_122 ( & V_318 -> V_321 ) ;
}
F_121 ( V_14 , V_316 ) ;
} else {
F_2 ( V_191 L_107
L_108 , V_316 ) ;
}
V_14 -> V_57 -> V_337 ++ ;
}
static struct V_168 * F_70 ( struct V_168 * V_169 , struct V_13 * V_14 , struct V_13 * V_175 ,
int * V_150 )
{
void * V_338 = NULL ;
struct V_114 * V_115 = NULL ;
struct V_168 * V_339 ;
int V_3 ;
struct V_13 * V_340 ;
struct V_331 V_341 ;
unsigned char V_342 [ V_343 ] ;
if ( ! V_175 ) {
V_338 = V_14 -> V_54 ;
V_115 = V_14 -> V_50 ;
V_340 = V_14 ;
} else {
V_338 = V_175 -> V_55 ;
V_115 = V_175 -> V_51 ;
V_340 = V_175 ;
}
if ( ! V_115 ) {
F_2 ( V_11 L_109 ) ;
return V_169 ;
}
F_69 ( ! V_338 ) ;
if ( ( V_175 && * V_150 == V_189 ) || ( ! V_175 && * V_150 == V_190 ) ) {
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_2 = V_342 ;
V_341 . V_344 = V_343 ;
V_339 = F_76 ( V_14 -> V_62 + V_345 ) ;
if ( ! V_339 ) {
F_57 ( V_169 ) ;
F_2 ( V_17 L_110 ) ;
return NULL ;
}
V_3 = V_115 -> V_346 ( V_338 , V_169 , V_339 , & V_341 ) ;
F_57 ( V_169 ) ;
if ( V_3 <= 0 ) {
switch ( V_3 ) {
case V_347 :
F_2 ( V_191 L_111 ,
V_341 . V_333 ? L_112 : L_113 ) ;
F_127 ( V_340 , & V_341 ) ;
break;
case V_348 :
V_340 -> V_59 |= V_349 ;
F_119 ( V_340 ) ;
break;
}
F_57 ( V_339 ) ;
return NULL ;
}
* V_150 = F_67 ( V_339 ) ;
if ( * V_150 < 0 ) {
F_57 ( V_339 ) ;
return NULL ;
}
return V_339 ;
} else {
V_115 -> V_350 ( V_338 , V_169 , * V_150 ) ;
return V_169 ;
}
}
static struct V_168 * F_94 ( struct V_168 * V_351 , int * V_150 ,
struct V_13 * V_14 , struct V_13 * V_175 , int type )
{
int V_352 ;
int V_353 ;
struct V_114 * V_49 ;
void * V_338 ;
struct V_168 * V_339 ;
if ( * V_150 < 0 || * V_150 > 0x3fff ) {
return V_351 ;
}
if ( type ) {
return V_351 ;
}
else {
if ( ! V_175 ) {
V_49 = V_14 -> V_49 ;
V_338 = V_14 -> V_53 ;
}
else {
V_49 = V_175 -> V_49 ;
V_338 = V_175 -> V_53 ;
}
V_353 = V_189 ;
}
if ( ! V_49 ) {
F_2 ( V_17 L_114 ) ;
return V_351 ;
}
if ( ! V_338 ) {
F_2 ( V_17 L_115 ) ;
return V_351 ;
}
V_339 = F_54 ( V_351 -> V_3 + V_351 -> V_3 / 2 + 32 +
F_86 ( V_351 ) , V_152 ) ;
if ( ! V_339 )
return V_351 ;
F_55 ( V_339 , F_86 ( V_351 ) ) ;
V_352 = ( V_49 -> V_354 ) ( V_338 , V_351 , V_339 , * V_150 ) ;
if ( ! V_352 ) {
F_88 ( V_339 ) ;
return V_351 ;
}
F_88 ( V_351 ) ;
* V_150 = V_353 ;
return V_339 ;
}
static void F_80 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_169 , int V_150 )
{
struct V_13 * V_14 ;
struct V_13 * V_180 ;
int V_3 ;
struct V_331 V_341 ;
unsigned char V_342 [ V_343 ] ;
F_2 ( V_11 L_116 ,
V_12 -> V_15 ) ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
return;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
F_1 ( L_117 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_175 ) {
int V_6 = F_73 ( V_12 ) -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return;
}
V_180 = V_23 [ V_6 ] ;
} else
V_180 = V_14 ;
switch ( V_169 -> V_2 [ 0 ] ) {
case V_355 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_118 ) ;
if ( V_150 == V_196 )
V_180 -> V_56 &= ~ V_217 ;
else
V_14 -> V_56 &= ~ V_222 ;
break;
case V_356 :
case V_357 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_119 ) ;
if ( V_150 == V_196 )
V_180 -> V_56 &= ~ ( V_183 | V_217 ) ;
else
V_14 -> V_56 &= ~ ( V_176 | V_222 ) ;
break;
case V_358 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_120 ) ;
if ( V_150 == V_196 ) {
if ( ! V_180 -> V_51 )
break;
V_180 -> V_56 |= V_183 ;
} else {
if ( ! V_14 -> V_51 )
break;
V_14 -> V_56 |= V_176 ;
}
break;
case V_199 :
F_2 ( V_11 L_121 ) ;
V_3 = ( V_169 -> V_2 [ 2 ] << 8 ) | V_169 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_150 == V_196 ) {
F_128 ( V_180 , V_169 -> V_2 [ 1 ] ) ;
if ( V_180 -> V_51 && V_180 -> V_55 )
V_180 -> V_51 ->
V_57 ( V_180 -> V_55 ,
V_169 -> V_2 [ 0 ] ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 , NULL ) ;
V_180 -> V_56 &= ~ V_359 ;
}
else {
F_128 ( V_14 , V_169 -> V_2 [ 1 ] ) ;
if ( V_14 -> V_50 && V_14 -> V_54 )
V_14 -> V_50 ->
V_57 ( V_14 -> V_54 ,
V_169 -> V_2 [ 0 ] ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 , NULL ) ;
V_14 -> V_56 &= ~ V_360 ;
}
break;
case V_198 :
F_2 ( V_11 L_122 ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_2 = V_342 ;
V_341 . V_344 = V_343 ;
V_3 = ( V_169 -> V_2 [ 2 ] << 8 ) | V_169 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_150 == V_196 ) {
if ( V_180 -> V_49 && V_180 -> V_53 )
V_180 -> V_49 ->
V_57 ( V_180 -> V_53 ,
V_169 -> V_2 [ 0 ] ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 , & V_341 ) ;
}
else {
if ( V_14 -> V_48 && V_14 -> V_52 )
V_14 -> V_48 ->
V_57 ( V_14 -> V_52 ,
V_169 -> V_2 [ 0 ] ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 , & V_341 ) ;
}
if ( V_341 . V_333 ) {
if ( V_341 . V_334 ) {
F_120 ( V_14 , V_150 , V_199 ,
V_341 . V_335 ? V_341 . V_316
: V_169 -> V_2 [ 1 ] ,
V_341 . V_336 ?
V_341 . V_2 : NULL ,
V_341 . V_336 ?
V_341 . V_325 : 0 ) ;
} else {
F_2 ( V_11 L_123 ) ;
}
} else {
F_120 ( V_14 , V_150 , V_199 ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 ) ;
}
break;
}
}
static void F_58 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 )
{
struct V_13 * V_180 , * V_14 ;
int V_150 , V_6 = V_12 -> V_15 ;
unsigned char * V_2 ;
if ( ! V_169 || V_169 -> V_3 < 3 )
return;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_6 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
V_2 = V_169 -> V_2 ;
if ( ! ( V_14 -> V_59 & V_224 ) && V_2 [ 0 ] == 0xff && V_2 [ 1 ] == 0x03 ) {
V_2 += 2 ;
if ( V_169 -> V_3 < 5 )
return;
}
V_150 = ( ( int ) V_2 [ 0 ] << 8 ) + V_2 [ 1 ] ;
if ( V_150 != V_196 && V_150 != V_197 )
return;
F_2 ( V_11 L_124 ) ;
F_1 ( L_80 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_175 ) {
V_6 = F_73 ( V_12 ) -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return;
}
V_180 = V_23 [ V_6 ] ;
} else
V_180 = V_14 ;
if ( V_180 != V_14 )
F_2 ( V_11 L_125 ) ;
switch ( V_2 [ 2 ] ) {
case V_355 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_126 ) ;
if ( V_150 == V_196 )
V_14 -> V_56 &= ~ V_183 ;
else
V_14 -> V_56 &= ~ V_176 ;
break;
case V_356 :
case V_357 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_119 ) ;
if ( V_150 == V_196 )
V_14 -> V_56 &= ~ ( V_183 | V_217 ) ;
else
V_14 -> V_56 &= ~ ( V_176 | V_222 ) ;
break;
case V_358 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_127 ) ;
if ( V_150 == V_196 ) {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_217 ;
} else {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_222 ;
}
break;
case V_199 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_128 ) ;
F_2 ( V_11 L_129 ) ;
if ( V_150 == V_196 ) {
if ( V_14 -> V_49 && V_14 -> V_53 )
V_14 -> V_49 -> V_57 ( V_14 -> V_53 , 0 , 0 ,
NULL , 0 , NULL ) ;
V_14 -> V_56 &= ~ V_361 ;
}
else {
if ( V_14 -> V_48 && V_14 -> V_52 )
V_14 -> V_48 -> V_57 ( V_14 -> V_52 ,
0 , 0 , NULL , 0 , NULL ) ;
V_14 -> V_56 &= ~ V_362 ;
}
break;
case V_198 :
F_2 ( V_11 L_130 ) ;
break;
}
}
int F_129 ( struct V_114 * V_115 )
{
V_115 -> V_35 = V_116 ;
V_115 -> V_363 = NULL ;
if ( V_116 ) {
V_116 -> V_363 = V_115 ;
}
V_116 = V_115 ;
return 0 ;
}
int F_130 ( struct V_114 * V_115 )
{
if ( V_115 -> V_363 )
V_115 -> V_363 -> V_35 = V_115 -> V_35 ;
else
V_116 = V_115 -> V_35 ;
if ( V_115 -> V_35 )
V_115 -> V_35 -> V_363 = V_115 -> V_363 ;
V_115 -> V_363 = V_115 -> V_35 = NULL ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , struct V_86 * V_2 )
{
struct V_114 * V_115 = V_116 ;
int V_352 ;
void * V_338 ;
int V_117 = V_2 -> V_117 ;
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_131 , V_14 -> V_5 ,
( V_2 -> V_132 & V_364 ) ? L_132 : L_133 , V_117 ) ;
if ( ! ( V_2 -> V_132 & V_364 ) && ! V_14 -> V_57 ) {
F_2 ( V_17 L_134
L_135 ) ;
return - V_109 ;
}
while ( V_115 ) {
if ( V_115 -> V_117 == V_117 ) {
V_338 = V_115 -> V_365 ( V_2 ) ;
if ( V_338 ) {
V_352 = V_115 -> V_366 ( V_338 , V_2 , V_14 -> V_5 , 0 ) ;
if ( ! V_352 ) {
F_2 ( V_17 L_136 ) ;
V_115 -> free ( V_338 ) ;
V_338 = NULL ;
break;
}
}
else {
F_2 ( V_17 L_137 ) ;
break;
}
if ( V_2 -> V_132 & V_364 ) {
if ( V_2 -> V_132 & V_367 ) {
if ( V_14 -> V_52 )
V_14 -> V_48 -> free ( V_14 -> V_52 ) ;
V_14 -> V_52 = V_338 ;
V_14 -> V_48 = V_115 ;
}
else {
if ( V_14 -> V_53 )
V_14 -> V_49 -> free ( V_14 -> V_53 ) ;
V_14 -> V_53 = V_338 ;
V_14 -> V_49 = V_115 ;
}
}
else {
if ( V_2 -> V_132 & V_367 ) {
if ( V_14 -> V_54 )
V_14 -> V_50 -> free ( V_14 -> V_54 ) ;
V_14 -> V_54 = V_338 ;
V_14 -> V_50 = V_115 ;
}
else {
if ( V_14 -> V_55 )
V_14 -> V_51 -> free ( V_14 -> V_55 ) ;
V_14 -> V_55 = V_338 ;
V_14 -> V_51 = V_115 ;
}
}
return 0 ;
}
V_115 = V_115 -> V_35 ;
}
return - V_88 ;
}
