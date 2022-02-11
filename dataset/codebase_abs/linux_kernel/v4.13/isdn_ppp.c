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
if ( ! V_14 -> V_57 )
return - V_58 ;
V_14 -> V_12 = NULL ;
V_14 -> V_59 = 0 ;
V_14 -> V_60 = 0 ;
V_14 -> V_61 = 0 ;
V_14 -> V_62 = - 1 ;
V_14 -> V_5 = - 1 ;
V_14 -> V_63 = 1524 ;
V_14 -> V_64 = 16 ;
V_14 -> V_65 = V_66 ;
F_18 ( & V_14 -> V_41 ) ;
V_14 -> V_67 = V_14 -> V_68 + V_69 - 1 ;
V_14 -> V_70 = V_14 -> V_68 ;
V_14 -> V_36 = V_43 ;
#ifdef F_19
V_14 -> V_71 = F_20 ( 16 , 16 ) ;
if ( F_21 ( V_14 -> V_71 ) ) {
F_22 ( V_14 ) ;
return F_23 ( V_14 -> V_71 ) ;
}
#endif
#ifdef F_24
V_14 -> V_72 = NULL ;
V_14 -> V_73 = NULL ;
#endif
V_14 -> V_24 = V_27 ;
return 0 ;
}
void
F_25 ( int V_43 , struct V_44 * V_44 )
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
T_2 * V_74 = V_14 -> V_12 -> V_19 ;
if ( ! V_74 ) {
F_2 ( V_17 L_12 , V_18 ) ;
return;
}
V_14 -> V_24 &= ~ V_25 ;
F_26 ( V_74 -> V_32 ) ;
}
for ( V_9 = 0 ; V_9 < V_69 ; V_9 ++ ) {
F_27 ( V_14 -> V_68 [ V_9 ] . V_10 ) ;
V_14 -> V_68 [ V_9 ] . V_10 = NULL ;
}
V_14 -> V_67 = V_14 -> V_68 + V_69 - 1 ;
V_14 -> V_70 = V_14 -> V_68 ;
#ifdef F_19
F_28 ( V_14 -> V_71 ) ;
V_14 -> V_71 = NULL ;
#endif
#ifdef F_24
if ( V_14 -> V_72 ) {
F_29 ( V_14 -> V_72 ) ;
V_14 -> V_72 = NULL ;
}
if ( V_14 -> V_73 ) {
F_29 ( V_14 -> V_73 ) ;
V_14 -> V_73 = NULL ;
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
F_22 ( V_14 ) ;
V_14 -> V_24 = 0 ;
}
static int
F_30 ( void T_3 * V_75 , void * V_76 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_31 ( V_76 , V_75 , V_3 ) )
return - V_77 ;
return 0 ;
}
static int
F_32 ( void T_3 * V_75 , void * V_76 , int V_3 )
{
if ( V_3 <= 0 )
V_3 = sizeof( void * ) ;
if ( F_33 ( V_75 , V_76 , V_3 ) )
return - V_77 ;
return 0 ;
}
static int F_34 ( void T_3 * V_78 , struct V_79 * * V_74 )
{
struct V_80 V_81 ;
struct V_79 * V_82 = NULL ;
int V_3 ;
if ( F_31 ( & V_81 , V_78 , sizeof( V_81 ) ) )
return - V_77 ;
if ( ! V_81 . V_3 ) {
* V_74 = NULL ;
return 0 ;
}
V_3 = V_81 . V_3 * sizeof( struct V_79 ) ;
V_82 = F_35 ( V_81 . V_83 , V_3 ) ;
if ( F_21 ( V_82 ) )
return F_23 ( V_82 ) ;
* V_74 = V_82 ;
return V_81 . V_3 ;
}
int
F_36 ( int V_43 , struct V_44 * V_44 , unsigned int V_84 , unsigned long V_78 )
{
unsigned long V_76 ;
int V_85 , V_9 , V_8 ;
struct V_13 * V_14 ;
T_1 * V_12 ;
struct V_86 V_2 ;
void T_3 * V_87 = ( void T_3 * ) V_78 ;
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
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) )
return V_85 ;
F_2 ( V_11 L_14 ,
( int ) V_43 , ( int ) V_14 -> V_5 , ( int ) V_76 ) ;
return F_37 ( V_14 , V_76 ) ;
#else
return - 1 ;
#endif
break;
case V_90 :
if ( ( V_85 = F_32 ( V_87 , & V_14 -> V_5 , sizeof( V_14 -> V_5 ) ) ) )
return V_85 ;
break;
case V_91 :
if ( ! V_12 )
return - V_88 ;
if ( ( V_85 = F_32 ( V_87 , V_12 -> V_19 -> V_32 -> V_39 ,
strlen ( V_12 -> V_19 -> V_32 -> V_39 ) ) ) )
return V_85 ;
break;
case V_92 :
if ( ( V_85 = F_32 ( V_87 , & V_14 -> V_61 , sizeof( V_14 -> V_61 ) ) ) )
return V_85 ;
break;
case V_93 :
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) )
return V_85 ;
V_14 -> V_61 = V_76 ;
break;
case V_94 :
if ( ( V_85 = F_32 ( V_87 , & V_14 -> V_60 , sizeof( V_14 -> V_60 ) ) ) )
return V_85 ;
break;
case V_95 :
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) ) {
return V_85 ;
}
if ( V_76 & V_96 && ! ( V_14 -> V_60 & V_96 ) && ( V_14 -> V_24 & V_25 ) ) {
if ( V_12 ) {
V_14 -> V_60 = V_76 ;
F_38 ( V_12 -> V_19 -> V_32 ) ;
break;
}
}
V_14 -> V_60 = V_76 ;
break;
case V_97 :
if ( V_12 ) {
struct V_98 V_99 ;
V_99 . V_100 = V_99 . V_101 = V_12 -> V_102 ;
if ( ( V_85 = F_32 ( V_87 , & V_99 , sizeof( struct V_98 ) ) ) )
return V_85 ;
}
break;
case V_103 :
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) )
return V_85 ;
V_14 -> V_63 = V_76 ;
break;
case V_104 :
break;
case V_105 :
break;
case V_106 :
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) )
return V_85 ;
V_76 ++ ;
if ( V_14 -> V_64 != V_76 ) {
#ifdef F_19
struct V_107 * V_108 ;
#endif
if ( V_14 -> V_28 & 0x1 )
F_2 ( V_11 L_15 , V_76 ) ;
V_14 -> V_64 = V_76 ;
#ifdef F_19
V_108 = F_20 ( 16 , V_76 ) ;
if ( F_21 ( V_108 ) )
return F_23 ( V_108 ) ;
if ( V_14 -> V_71 )
F_28 ( V_14 -> V_71 ) ;
V_14 -> V_71 = V_108 ;
#endif
}
break;
case V_109 :
if ( ( V_85 = F_32 ( V_87 , & V_14 -> V_28 , sizeof( V_14 -> V_28 ) ) ) )
return V_85 ;
break;
case V_110 :
if ( ( V_85 = F_30 ( V_87 , & V_76 , sizeof( V_76 ) ) ) )
return V_85 ;
V_14 -> V_28 = V_76 ;
break;
case V_111 :
{
unsigned long V_112 [ 8 ] = { 0 ,} ;
struct V_113 * V_114 = V_115 ;
while ( V_114 ) {
V_8 = V_114 -> V_116 / ( sizeof( long ) * 8 ) ;
V_9 = V_114 -> V_116 % ( sizeof( long ) * 8 ) ;
if ( V_8 < 8 )
V_112 [ V_8 ] |= ( 1UL << V_9 ) ;
V_114 = V_114 -> V_35 ;
}
if ( ( V_85 = F_32 ( V_87 , V_112 , 8 * sizeof( long ) ) ) )
return V_85 ;
}
break;
case V_117 :
if ( ( V_85 = F_30 ( V_87 , & V_2 , sizeof( struct V_86 ) ) ) )
return V_85 ;
return F_39 ( V_14 , & V_2 ) ;
case V_118 :
{
struct V_119 V_120 ;
memset ( ( char * ) & V_120 , 0 , sizeof( struct V_119 ) ) ;
if ( V_12 )
{
strncpy ( V_120 . V_121 , V_12 -> V_122 , 63 ) ;
if ( V_12 -> V_123 ) {
strncpy ( V_120 . V_124 , V_12 -> V_123 -> V_116 , 63 ) ;
}
V_120 . V_125 = V_12 -> V_126 ;
if ( V_12 -> V_127 )
V_120 . V_128 = V_129 ;
else
V_120 . V_128 = V_130 ;
if ( V_12 -> V_131 & V_132 )
V_120 . V_128 |= V_133 ;
}
return F_32 ( V_87 , & V_120 , sizeof( struct V_119 ) ) ;
}
#ifdef F_24
case V_134 :
{
struct V_135 V_136 ;
struct V_79 * V_82 ;
int V_137 , V_3 = F_34 ( V_87 , & V_82 ) ;
if ( V_3 < 0 )
return V_3 ;
V_136 . V_3 = V_3 ;
V_136 . V_83 = V_82 ;
if ( V_14 -> V_72 ) {
F_29 ( V_14 -> V_72 ) ;
V_14 -> V_72 = NULL ;
}
if ( V_136 . V_83 != NULL )
V_137 = F_40 ( & V_14 -> V_72 , & V_136 ) ;
else
V_137 = 0 ;
F_27 ( V_82 ) ;
return V_137 ;
}
case V_138 :
{
struct V_135 V_136 ;
struct V_79 * V_82 ;
int V_137 , V_3 = F_34 ( V_87 , & V_82 ) ;
if ( V_3 < 0 )
return V_3 ;
V_136 . V_3 = V_3 ;
V_136 . V_83 = V_82 ;
if ( V_14 -> V_73 ) {
F_29 ( V_14 -> V_73 ) ;
V_14 -> V_73 = NULL ;
}
if ( V_136 . V_83 != NULL )
V_137 = F_40 ( & V_14 -> V_73 , & V_136 ) ;
else
V_137 = 0 ;
F_27 ( V_82 ) ;
return V_137 ;
}
#endif
default:
break;
}
return 0 ;
}
unsigned int
F_41 ( struct V_44 * V_44 , T_4 * V_139 )
{
T_5 V_140 ;
struct V_141 * V_142 , * V_143 ;
T_6 V_131 ;
struct V_13 * V_14 ;
V_14 = V_44 -> V_47 ;
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_16 ,
F_42 ( F_43 ( V_44 ) ) ) ;
F_44 ( V_44 , & V_14 -> V_41 , V_139 ) ;
if ( ! ( V_14 -> V_24 & V_27 ) ) {
if ( V_14 -> V_24 == V_42 )
return V_144 ;
F_2 ( V_11 L_17 ) ;
return V_145 ;
}
V_140 = V_146 | V_147 ;
F_45 ( & V_14 -> V_148 , V_131 ) ;
V_143 = V_14 -> V_70 ;
V_142 = V_14 -> V_67 ;
if ( V_142 -> V_35 != V_143 || ( V_14 -> V_24 & V_40 ) ) {
V_14 -> V_24 &= ~ V_40 ;
V_140 |= V_149 | V_150 ;
}
F_46 ( & V_14 -> V_148 , V_131 ) ;
return V_140 ;
}
static int
F_47 ( unsigned char * V_10 , int V_3 , int V_151 , int V_6 )
{
struct V_141 * V_142 , * V_143 ;
T_6 V_131 ;
T_7 * V_152 ;
struct V_13 * V_14 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_37 L_18 , V_6 ) ;
return 0 ;
}
V_14 = V_23 [ V_6 ] ;
if ( ! ( V_14 -> V_24 & V_25 ) ) {
F_2 ( V_11 L_19 ) ;
return 0 ;
}
V_152 = F_48 ( V_3 + 4 , V_153 ) ;
if ( ! V_152 ) {
F_2 ( V_37 L_20 ) ;
return 0 ;
}
V_152 [ 0 ] = V_154 ;
V_152 [ 1 ] = V_155 ;
V_152 [ 2 ] = V_151 >> 8 ;
V_152 [ 3 ] = V_151 & 0xff ;
memcpy ( V_152 + 4 , V_10 , V_3 ) ;
F_45 ( & V_14 -> V_148 , V_131 ) ;
V_142 = V_14 -> V_67 ;
V_143 = V_14 -> V_70 ;
if ( V_142 == V_143 ) {
F_2 ( V_37 L_21 ) ;
V_142 = V_142 -> V_35 ;
F_27 ( V_142 -> V_10 ) ;
V_14 -> V_67 = V_142 ;
}
V_143 -> V_10 = ( char * ) V_152 ;
V_143 -> V_3 = V_3 + 4 ;
V_14 -> V_70 = V_143 -> V_35 ;
F_46 ( & V_14 -> V_148 , V_131 ) ;
F_14 ( & V_14 -> V_41 ) ;
return V_3 ;
}
int
F_49 ( int V_43 , struct V_44 * V_44 , char T_3 * V_10 , int V_156 )
{
struct V_13 * V_14 ;
struct V_141 * V_75 ;
T_6 V_131 ;
T_7 * V_157 ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_27 ) )
return 0 ;
F_45 ( & V_14 -> V_148 , V_131 ) ;
V_75 = V_14 -> V_67 -> V_35 ;
V_157 = V_75 -> V_10 ;
if ( ! V_157 ) {
F_46 ( & V_14 -> V_148 , V_131 ) ;
return - V_158 ;
}
if ( V_75 -> V_3 < V_156 )
V_156 = V_75 -> V_3 ;
V_75 -> V_10 = NULL ;
V_14 -> V_67 = V_75 ;
F_46 ( & V_14 -> V_148 , V_131 ) ;
if ( F_33 ( V_10 , V_157 , V_156 ) )
V_156 = - V_77 ;
F_27 ( V_157 ) ;
return V_156 ;
}
int
F_50 ( int V_43 , struct V_44 * V_44 , const char T_3 * V_10 , int V_156 )
{
T_1 * V_12 ;
struct V_13 * V_14 ;
int V_151 ;
unsigned char V_159 [ 4 ] ;
V_14 = V_44 -> V_47 ;
if ( ! ( V_14 -> V_24 & V_25 ) )
return 0 ;
V_12 = V_14 -> V_12 ;
if ( ! V_12 )
F_2 ( V_11 L_22 ) ;
else {
if ( F_31 ( V_159 , V_10 , 4 ) )
return - V_77 ;
V_151 = F_51 ( V_159 ) ;
if ( V_151 != V_160 )
V_12 -> V_102 = 0 ;
if ( V_12 -> V_161 < 0 || V_12 -> V_162 < 0 )
return 0 ;
if ( ( V_32 -> V_163 [ V_12 -> V_161 ] -> V_131 & V_164 ) &&
V_12 -> V_165 == 0 &&
( V_12 -> V_131 & V_166 ) ) {
unsigned short V_167 ;
struct V_168 * V_169 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 ;
V_169 = F_52 ( V_167 + V_156 , V_153 ) ;
if ( ! V_169 ) {
F_2 ( V_37 L_23 ) ;
return V_156 ;
}
F_53 ( V_169 , V_167 ) ;
if ( F_31 ( F_54 ( V_169 , V_156 ) , V_10 , V_156 ) )
{
F_55 ( V_169 ) ;
return - V_77 ;
}
if ( V_14 -> V_28 & 0x40 ) {
F_2 ( V_11 L_24 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_25 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
F_56 ( V_12 -> V_19 , V_12 , V_169 ) ;
F_57 ( V_12 , V_169 ) ;
}
}
return V_156 ;
}
int
F_58 ( void )
{
int V_9 ,
V_8 ;
#ifdef F_4
if ( F_59 () < 0 )
return - V_58 ;
#endif
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( ! ( V_23 [ V_9 ] = F_60 ( sizeof( struct V_13 ) , V_172 ) ) ) {
F_2 ( V_37 L_26 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_27 ( V_23 [ V_8 ] ) ;
return - 1 ;
}
F_61 ( & V_23 [ V_9 ] -> V_148 ) ;
V_23 [ V_9 ] -> V_24 = 0 ;
V_23 [ V_9 ] -> V_67 = V_23 [ V_9 ] -> V_68 + V_69 - 1 ;
V_23 [ V_9 ] -> V_70 = V_23 [ V_9 ] -> V_68 ;
for ( V_8 = 0 ; V_8 < V_69 ; V_8 ++ ) {
V_23 [ V_9 ] -> V_68 [ V_8 ] . V_10 = NULL ;
V_23 [ V_9 ] -> V_68 [ V_8 ] . V_70 = V_23 [ V_9 ] -> V_68 +
( V_69 + V_8 - 1 ) % V_69 ;
V_23 [ V_9 ] -> V_68 [ V_8 ] . V_35 = V_23 [ V_9 ] -> V_68 + ( V_8 + 1 ) % V_69 ;
}
}
return 0 ;
}
void
F_62 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_27 ( V_23 [ V_9 ] ) ;
#ifdef F_4
F_27 ( V_173 ) ;
#endif
}
static int F_63 ( struct V_13 * V_14 , struct V_168 * V_169 )
{
if ( V_169 -> V_3 < 1 )
return - 1 ;
if ( V_169 -> V_2 [ 0 ] == 0xff ) {
if ( V_169 -> V_3 < 2 )
return - 1 ;
if ( V_169 -> V_2 [ 1 ] != 0x03 )
return - 1 ;
F_64 ( V_169 , 2 ) ;
} else {
if ( V_14 -> V_60 & V_174 )
return - 1 ;
}
return 0 ;
}
static int F_65 ( struct V_168 * V_169 )
{
int V_151 ;
if ( V_169 -> V_3 < 1 )
return - 1 ;
if ( V_169 -> V_2 [ 0 ] & 0x1 ) {
V_151 = V_169 -> V_2 [ 0 ] ;
F_64 ( V_169 , 1 ) ;
} else {
if ( V_169 -> V_3 < 2 )
return - 1 ;
V_151 = ( ( int ) V_169 -> V_2 [ 0 ] << 8 ) + V_169 -> V_2 [ 1 ] ;
F_64 ( V_169 , 2 ) ;
}
return V_151 ;
}
void F_66 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 )
{
struct V_13 * V_14 ;
int V_6 ;
int V_151 ;
F_67 ( V_31 -> V_34 -> V_175 ) ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_27 ,
V_12 -> V_15 ) ;
F_55 ( V_169 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x4 ) {
F_2 ( V_11 L_28 ,
( long ) V_14 , ( long ) V_12 , V_12 -> V_15 , V_14 -> V_5 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_29 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( F_63 ( V_14 , V_169 ) < 0 ) {
F_55 ( V_169 ) ;
return;
}
V_151 = F_65 ( V_169 ) ;
if ( V_151 < 0 ) {
F_55 ( V_169 ) ;
return;
}
#ifdef F_4
if ( V_14 -> V_56 & V_176 ) {
V_169 = F_68 ( V_169 , V_14 , NULL , & V_151 ) ;
if ( ! V_169 )
return;
}
if ( ! ( V_14 -> V_61 & V_177 ) ) {
if ( V_151 == V_178 ) {
F_69 ( V_31 , V_12 , V_169 ) ;
return;
}
}
#endif
F_70 ( V_31 , V_12 , V_169 , V_151 ) ;
}
static void
F_70 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 , int V_151 )
{
struct V_179 * V_32 = V_31 -> V_32 ;
struct V_13 * V_14 , * V_180 ;
T_1 * V_181 = NULL ;
int V_6 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_30 ,
V_12 -> V_15 ) ;
goto V_182;
}
V_14 = V_23 [ V_6 ] ;
if ( V_12 -> V_175 ) {
V_181 = F_71 ( V_12 ) ;
V_6 = V_181 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_31 ,
V_12 -> V_15 ) ;
goto V_182;
}
}
V_180 = V_23 [ V_6 ] ;
if ( V_14 -> V_28 & 0x10 ) {
F_2 ( V_11 L_32 , ( int ) V_169 -> V_3 , V_151 ) ;
F_1 ( L_33 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
}
if ( V_180 -> V_56 & V_183 ) {
V_169 = F_68 ( V_169 , V_14 , V_180 , & V_151 ) ;
if ( ! V_169 )
return;
}
switch ( V_151 ) {
case V_184 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_34 ) ;
V_169 -> V_185 = F_72 ( V_186 ) ;
break;
case V_187 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_35 ) ;
V_169 -> V_185 = F_72 ( V_188 ) ;
break;
case V_189 :
case V_190 :
F_2 ( V_191 L_36 ) ;
goto V_182;
#ifdef F_19
case V_192 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_37 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_38 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_182;
}
if ( F_73 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_71 , V_169 -> V_2 , V_169 -> V_3 ) <= 0 ) {
F_2 ( V_37 L_39 ) ;
goto V_182;
}
V_169 -> V_185 = F_72 ( V_188 ) ;
break;
case V_193 :
if ( V_14 -> V_28 & 0x20 )
F_2 ( V_11 L_40 ) ;
{
struct V_168 * V_194 = V_169 ;
int V_195 ;
V_169 = F_74 ( V_194 -> V_3 + 128 ) ;
if ( ! V_169 ) {
F_2 ( V_37 L_41 , V_32 -> V_39 ) ;
V_169 = V_194 ;
goto V_182;
}
F_54 ( V_169 , V_194 -> V_3 + 128 ) ;
F_75 ( V_194 , V_169 -> V_2 ,
V_194 -> V_3 ) ;
if ( V_31 -> V_34 -> V_15 < 0 ) {
F_2 ( V_17 L_38 ,
V_18 , V_31 -> V_34 -> V_15 ) ;
goto V_182;
}
V_195 = F_76 ( V_23 [ V_31 -> V_34 -> V_15 ] -> V_71 ,
V_169 -> V_2 , V_194 -> V_3 ) ;
F_55 ( V_194 ) ;
if ( V_195 < 0 )
goto V_182;
F_77 ( V_169 , V_195 ) ;
V_169 -> V_185 = F_72 ( V_188 ) ;
}
break;
#endif
case V_196 :
case V_197 :
F_78 ( V_31 , V_12 , V_169 , V_151 ) ;
if ( V_169 -> V_2 [ 0 ] == V_198 ||
V_169 -> V_2 [ 0 ] == V_199 )
break;
default:
F_47 ( V_169 -> V_2 , V_169 -> V_3 , V_151 , V_12 -> V_15 ) ;
F_55 ( V_169 ) ;
return;
}
#ifdef F_24
F_79 ( V_169 , 4 ) ;
{
T_8 * V_74 = ( T_8 * ) V_169 -> V_2 ;
* V_74 = 0 ;
}
if ( V_14 -> V_72
&& F_80 ( V_14 -> V_72 , V_169 ) == 0 ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_42 ) ;
F_55 ( V_169 ) ;
return;
}
if ( ! ( V_14 -> V_73
&& F_80 ( V_14 -> V_73 , V_169 ) == 0 ) ) {
if ( V_14 -> V_28 & 0x2 )
F_2 ( V_11 L_43 ) ;
V_12 -> V_102 = 0 ;
if ( V_181 )
V_181 -> V_102 = 0 ;
}
F_64 ( V_169 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
if ( V_181 )
V_181 -> V_102 = 0 ;
#endif
V_169 -> V_32 = V_32 ;
F_81 ( V_169 ) ;
F_82 ( V_169 ) ;
return;
V_182:
V_31 -> V_34 -> V_200 . V_201 ++ ;
F_55 ( V_169 ) ;
}
static unsigned char * F_83 ( struct V_168 * * V_202 , int V_3 )
{
struct V_168 * V_169 = * V_202 ;
if ( F_84 ( V_169 ) < V_3 ) {
struct V_168 * V_203 = F_85 ( V_169 , V_3 ) ;
if ( ! V_203 ) {
F_2 ( V_17 L_44 ) ;
F_86 ( V_169 ) ;
return NULL ;
}
F_2 ( V_11 L_45 , F_84 ( V_169 ) , V_3 ) ;
F_86 ( V_169 ) ;
* V_202 = V_203 ;
return F_79 ( V_203 , V_3 ) ;
}
return F_79 ( V_169 , V_3 ) ;
}
int
F_87 ( struct V_168 * V_169 , struct V_179 * V_19 )
{
T_1 * V_12 , * V_181 ;
T_2 * V_204 ;
unsigned int V_151 = V_187 ;
struct V_13 * V_205 , * V_206 ;
int V_6 , V_29 = V_207 ;
V_181 = F_88 ( V_19 ) ;
V_204 = V_181 -> V_19 ;
V_6 = V_181 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_46 ,
V_181 -> V_15 ) ;
F_55 ( V_169 ) ;
goto V_38;
}
V_206 = V_23 [ V_6 ] ;
if ( ! ( V_206 -> V_60 & V_96 ) ) {
if ( V_206 -> V_28 & 0x1 )
F_2 ( V_191 L_47 , V_19 -> V_39 ) ;
V_29 = V_208 ;
goto V_38;
}
switch ( F_89 ( V_169 -> V_185 ) ) {
case V_188 :
V_151 = V_187 ;
break;
case V_186 :
V_151 = V_184 ;
break;
default:
F_2 ( V_17 L_48 ,
V_169 -> V_185 ) ;
F_86 ( V_169 ) ;
goto V_38;
}
V_12 = F_90 ( V_204 ) ;
if ( ! V_12 ) {
F_2 ( V_37 L_49 , V_19 -> V_39 ) ;
V_29 = V_208 ;
goto V_38;
}
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_46 ,
V_12 -> V_15 ) ;
F_55 ( V_169 ) ;
goto V_209;
}
V_205 = V_23 [ V_6 ] ;
F_64 ( V_169 , V_210 ) ;
#ifdef F_24
* ( V_211 * ) F_79 ( V_169 , 4 ) = 1 ;
{
T_9 * V_74 = ( T_9 * ) V_169 -> V_2 ;
V_74 ++ ;
* V_74 = F_72 ( V_151 ) ;
}
if ( V_205 -> V_72
&& F_80 ( V_205 -> V_72 , V_169 ) == 0 ) {
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_50 ) ;
F_55 ( V_169 ) ;
goto V_209;
}
if ( ! ( V_205 -> V_73
&& F_80 ( V_205 -> V_73 , V_169 ) == 0 ) ) {
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_43 ) ;
V_12 -> V_102 = 0 ;
}
F_64 ( V_169 , 4 ) ;
#else
V_12 -> V_102 = 0 ;
#endif
if ( V_205 -> V_28 & 0x4 )
F_2 ( V_11 L_51 , ( int ) V_169 -> V_3 ) ;
if ( V_206 -> V_28 & 0x40 )
F_1 ( L_52 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_206 -> V_5 , V_12 -> V_15 ) ;
#ifdef F_19
if ( V_151 == V_187 && V_206 -> V_60 & V_212 ) {
struct V_168 * V_213 ;
unsigned short V_167 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 + V_210 ;
V_213 = F_52 ( V_167 + V_169 -> V_3 , V_153 ) ;
if ( V_213 ) {
T_7 * V_10 ;
int V_214 ;
F_53 ( V_213 , V_167 ) ;
V_213 -> V_32 = V_169 -> V_32 ;
F_54 ( V_213 , V_169 -> V_3 ) ;
V_10 = V_169 -> V_2 ;
V_214 = F_91 ( V_206 -> V_71 , V_169 -> V_2 , V_169 -> V_3 , V_213 -> V_2 ,
& V_10 , ! ( V_206 -> V_60 & V_215 ) ) ;
if ( V_10 != V_169 -> V_2 ) {
if ( V_213 -> V_2 != V_10 )
F_2 ( V_17 L_53 ) ;
F_86 ( V_169 ) ;
V_169 = V_213 ;
} else {
F_86 ( V_213 ) ;
}
F_77 ( V_169 , V_214 ) ;
if ( V_169 -> V_2 [ 0 ] & V_216 ) {
V_151 = V_193 ;
V_169 -> V_2 [ 0 ] ^= V_216 ;
} else {
if ( V_169 -> V_2 [ 0 ] >= V_217 )
V_151 = V_192 ;
V_169 -> V_2 [ 0 ] = ( V_169 -> V_2 [ 0 ] & 0x0f ) | 0x40 ;
}
}
}
#endif
if ( V_206 -> V_56 & V_218 ) {
if ( V_206 -> V_56 & V_183 ) {
V_169 = F_92 ( V_169 , & V_151 , V_205 , V_206 , 0 ) ;
} else {
F_2 ( V_11 L_54 ) ;
}
}
if ( V_205 -> V_28 & 0x24 )
F_2 ( V_11 L_55 , ( int ) V_169 -> V_3 , V_151 ) ;
#ifdef F_4
if ( V_205 -> V_61 & V_219 ) {
long V_59 = V_206 -> V_59 ;
V_206 -> V_59 ++ ;
if ( V_205 -> V_61 & V_220 ) {
unsigned char * V_2 = F_83 ( & V_169 , 3 ) ;
if ( ! V_2 )
goto V_209;
V_59 &= 0xfff ;
V_2 [ 0 ] = V_221 | V_222 | ( ( V_59 >> 8 ) & 0xf ) ;
V_2 [ 1 ] = V_59 & 0xff ;
V_2 [ 2 ] = V_151 ;
} else {
unsigned char * V_2 = F_83 ( & V_169 , 5 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = V_221 | V_222 ;
V_2 [ 1 ] = ( V_59 >> 16 ) & 0xff ;
V_2 [ 2 ] = ( V_59 >> 8 ) & 0xff ;
V_2 [ 3 ] = ( V_59 >> 0 ) & 0xff ;
V_2 [ 4 ] = V_151 ;
}
V_151 = V_178 ;
}
#endif
if ( V_205 -> V_56 & V_223 )
V_169 = F_92 ( V_169 , & V_151 , V_205 , V_206 , 1 ) ;
if ( ( V_205 -> V_60 & V_224 ) && ( V_151 <= 0xff ) ) {
unsigned char * V_2 = F_83 ( & V_169 , 1 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = V_151 & 0xff ;
}
else {
unsigned char * V_2 = F_83 ( & V_169 , 2 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = ( V_151 >> 8 ) & 0xff ;
V_2 [ 1 ] = V_151 & 0xff ;
}
if ( ! ( V_205 -> V_60 & V_225 ) ) {
unsigned char * V_2 = F_83 ( & V_169 , 2 ) ;
if ( ! V_2 )
goto V_209;
V_2 [ 0 ] = 0xff ;
V_2 [ 1 ] = 0x03 ;
}
if ( V_206 -> V_28 & 0x40 ) {
F_2 ( V_11 L_56 , ( int ) V_169 -> V_3 ) ;
F_1 ( L_25 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_205 -> V_5 , V_12 -> V_15 ) ;
}
F_93 ( V_12 , V_169 ) ;
V_209:
F_94 ( & V_12 -> V_226 ) ;
V_38:
return V_29 ;
}
int F_95 ( struct V_168 * V_169 , T_1 * V_12 )
{
struct V_13 * V_14 = V_23 [ V_12 -> V_15 ] ;
T_8 V_151 ;
int V_227 = 0 ;
switch ( F_89 ( V_169 -> V_185 ) ) {
case V_188 :
V_151 = V_187 ;
break;
case V_186 :
V_151 = V_184 ;
break;
default:
F_2 ( V_17 L_57 ,
V_169 -> V_185 ) ;
return 1 ;
}
* ( V_211 * ) F_64 ( V_169 , V_210 - 4 ) = 1 ;
{
T_9 * V_74 = ( T_9 * ) V_169 -> V_2 ;
V_74 ++ ;
* V_74 = F_72 ( V_151 ) ;
}
V_227 |= V_14 -> V_72
&& F_80 ( V_14 -> V_72 , V_169 ) == 0 ;
V_227 |= V_14 -> V_73
&& F_80 ( V_14 -> V_73 , V_169 ) == 0 ;
F_79 ( V_169 , V_210 - 4 ) ;
return V_227 ;
}
static int F_59 ( void )
{
int V_9 ;
int V_228 = V_16 * sizeof( V_229 ) ;
if ( ( V_173 = F_60 ( V_228 , V_172 ) ) == NULL )
return - V_58 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_61 ( & V_173 [ V_9 ] . V_21 ) ;
return 0 ;
}
static V_229 * F_96 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( V_173 [ V_9 ] . V_22 <= 0 )
return ( V_173 + V_9 ) ;
return NULL ;
}
static int F_12 ( T_1 * V_12 , V_229 * V_230 )
{
struct V_13 * V_14 ;
if ( V_12 -> V_15 < 0 ) {
F_2 ( V_17 L_58 ,
V_18 , V_12 -> V_15 ) ;
return ( - V_88 ) ;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
if ( V_230 ) {
if ( V_12 -> V_19 -> V_20 )
V_12 -> V_19 -> V_20 -> V_22 -- ;
V_12 -> V_19 -> V_20 = V_230 ;
} else {
V_14 -> V_59 = 0 ;
if ( ( V_12 -> V_19 -> V_20 = F_96 () ) == NULL )
return - V_58 ;
V_12 -> V_35 = V_12 -> V_70 = V_12 ;
V_12 -> V_19 -> V_20 -> V_231 = NULL ;
V_12 -> V_19 -> V_20 -> V_232 = 0 ;
V_12 -> V_19 -> V_20 -> V_233 = V_234 ;
}
V_12 -> V_19 -> V_20 -> V_22 ++ ;
V_14 -> V_62 = 0 ;
return 0 ;
}
static void F_69 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 ;
T_1 * V_235 ;
V_229 * V_236 ;
T_10 * V_200 ;
struct V_168 * V_237 , * V_238 , * V_239 , * V_240 ;
T_11 V_241 , V_242 , V_243 ;
unsigned long V_131 ;
int V_6 ;
F_45 ( & V_31 -> V_20 -> V_21 , V_131 ) ;
V_236 = V_31 -> V_20 ;
V_200 = & V_236 -> V_200 ;
V_6 = V_12 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_59 ,
V_18 , V_12 -> V_15 ) ;
V_200 -> V_244 ++ ;
F_86 ( V_169 ) ;
F_46 ( & V_236 -> V_21 , V_131 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
if ( ++ V_236 -> V_232 > V_200 -> V_245 )
V_200 -> V_245 = V_236 -> V_232 ;
if ( V_14 -> V_28 & 0x8 )
F_97 ( V_12 -> V_15 , V_169 ) ;
V_241 = F_98 ( V_14 -> V_61 & V_246 ,
V_169 , V_14 -> V_62 ) ;
if ( V_236 -> V_233 > V_247 && ( V_241 & V_248 ) ) {
V_236 -> V_233 = V_241 ;
} else if ( F_99 ( V_241 , V_236 -> V_233 ) ) {
V_200 -> V_244 ++ ;
F_100 ( V_236 , V_169 ) ;
F_46 ( & V_236 -> V_21 , V_131 ) ;
return;
}
V_14 -> V_62 = V_242 = V_241 ;
for ( V_235 = V_31 -> V_249 ; ; ) {
V_6 = V_235 -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_60 ,
V_18 , V_235 -> V_15 ) ;
} else {
T_11 V_250 = V_23 [ V_6 ] -> V_62 ;
if ( F_99 ( V_250 , V_242 ) )
V_242 = V_250 ;
}
if ( ( V_235 = V_235 -> V_35 ) == V_31 -> V_249 )
break;
}
if ( F_99 ( V_242 , V_236 -> V_233 ) )
V_242 = V_236 -> V_233 ;
V_237 = V_169 ;
if ( ( V_238 = V_236 -> V_231 ) == NULL || F_99 ( V_241 , F_101 ( V_238 ) ) ) {
V_237 -> V_35 = V_238 ;
V_236 -> V_231 = V_238 = V_237 ;
V_237 = NULL ;
}
V_239 = F_102 ( V_238 ) & V_221 &&
F_101 ( V_238 ) == V_236 -> V_233 ? V_238 : NULL ;
while ( V_239 != NULL || V_237 != NULL ) {
V_243 = F_101 ( V_238 ) ;
V_240 = V_238 -> V_35 ;
if ( V_237 != NULL && V_243 == V_241 ) {
F_100 ( V_236 , V_237 ) ;
V_237 = NULL ;
}
if ( V_237 != NULL && ( V_240 == NULL ||
F_99 ( V_241 , F_101 ( V_240 ) ) ) ) {
V_237 -> V_35 = V_240 ;
V_238 -> V_35 = V_240 = V_237 ;
V_237 = NULL ;
}
if ( V_239 != NULL ) {
if ( V_239 != V_238 && ( F_102 ( V_238 ) & V_221 ) ) {
F_2 ( V_37 L_61
L_62 , V_243 ) ;
V_200 -> V_251 ++ ;
V_200 -> V_244 ++ ;
V_239 = F_103 ( V_236 , V_239 , V_238 ) ;
V_240 = V_238 -> V_35 ;
}
} else if ( F_104 ( V_243 , V_242 ) ) {
if ( F_102 ( V_238 ) & V_221 )
V_239 = V_238 ;
else {
if ( F_102 ( V_238 ) & V_222 )
V_200 -> V_244 ++ ;
if ( V_236 -> V_231 == V_238 )
V_236 -> V_231 = V_240 ;
F_100 ( V_236 , V_238 ) ;
V_238 = V_240 ;
continue;
}
}
if ( V_239 != NULL && ( F_102 ( V_238 ) & V_222 ) ) {
V_242 = V_236 -> V_233 = ( V_243 + 1 ) & V_252 ;
F_105 ( V_31 , V_12 , V_239 , V_240 ) ;
V_239 = NULL ;
V_238 = NULL ;
V_236 -> V_231 = V_240 ;
}
if ( V_240 != NULL &&
( ( V_243 + 1 ) & V_252 ) == F_101 ( V_240 ) ) {
if ( V_238 == NULL ) {
if ( F_102 ( V_240 ) & V_221 )
V_239 = V_240 ;
else
{
F_2 ( V_37 L_63
L_64
L_65 , V_243 ) ;
V_200 -> V_251 ++ ;
}
}
} else {
if ( V_240 != NULL && V_238 != NULL &&
F_99 ( V_243 , V_242 ) ) {
V_200 -> V_244 ++ ;
V_236 -> V_231 = F_103 ( V_236 , V_239 , V_240 ) ;
}
V_239 = NULL ;
}
V_238 = V_240 ;
}
if ( V_236 -> V_231 == NULL )
V_236 -> V_231 = V_238 ;
if ( V_236 -> V_232 > V_253 ) {
V_200 -> V_254 ++ ;
while ( V_236 -> V_232 > V_253 ) {
V_238 = V_236 -> V_231 -> V_35 ;
F_100 ( V_236 , V_236 -> V_231 ) ;
V_236 -> V_231 = V_238 ;
}
}
F_46 ( & V_236 -> V_21 , V_131 ) ;
}
static void F_7 ( T_1 * V_12 )
{
struct V_168 * V_238 = V_12 -> V_19 -> V_20 -> V_231 ;
struct V_168 * V_255 ;
while ( V_238 ) {
V_255 = V_238 -> V_35 ;
F_100 ( V_12 -> V_19 -> V_20 , V_238 ) ;
V_238 = V_255 ;
}
V_12 -> V_19 -> V_20 -> V_231 = NULL ;
}
static T_11 F_98 ( int V_256 ,
struct V_168 * V_169 , T_11 V_257 )
{
T_11 V_233 ;
int V_131 = V_169 -> V_2 [ 0 ] & ( V_221 | V_222 ) ;
if ( ! V_256 )
{
V_233 = F_106 ( * ( V_258 * ) V_169 -> V_2 ) & V_252 ;
F_79 ( V_169 , 1 ) ;
}
else
{
V_233 = F_89 ( * ( T_9 * ) V_169 -> V_2 ) & V_259 ;
if ( ! ( V_233 & V_260 ) &&
( V_257 & V_260 ) &&
( unsigned long ) V_257 <= V_247 )
V_233 |= ( V_257 + V_261 + 1 ) &
( ~ V_259 & V_252 ) ;
else
V_233 |= V_257 & ( ~ V_259 & V_252 ) ;
F_79 ( V_169 , 3 ) ;
}
* ( T_11 * ) ( V_169 -> V_2 + 1 ) = V_233 ;
V_169 -> V_2 [ 0 ] = V_131 ;
return V_233 ;
}
struct V_168 * F_103 ( V_229 * V_236 ,
struct V_168 * V_262 , struct V_168 * V_263 )
{
if ( V_262 )
while ( V_262 != V_263 ) {
struct V_168 * V_35 = V_262 -> V_35 ;
F_100 ( V_236 , V_262 ) ;
V_262 = V_35 ;
}
return V_262 ;
}
void F_105 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_262 , struct V_168 * V_263 )
{
V_229 * V_236 = V_31 -> V_20 ;
int V_151 ;
struct V_168 * V_169 ;
unsigned int V_264 ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_58 ,
V_18 , V_12 -> V_15 ) ;
return;
}
if ( F_102 ( V_262 ) == ( V_221 | V_222 ) ) {
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_66
L_67 , F_101 ( V_262 ) , V_262 -> V_3 ) ;
V_169 = V_262 ;
F_64 ( V_169 , V_265 ) ;
V_236 -> V_232 -- ;
} else {
struct V_168 * V_238 ;
int V_266 ;
for ( V_264 = V_266 = 0 , V_238 = V_262 ; V_238 != V_263 ; V_238 = V_238 -> V_35 , V_266 ++ )
V_264 += V_238 -> V_3 - V_265 ;
if ( V_23 [ V_12 -> V_15 ] -> V_28 & 0x40 )
F_2 ( V_11 L_68
L_69 , F_101 ( V_262 ) ,
( F_101 ( V_262 ) + V_266 - 1 ) & V_252 , V_264 ) ;
if ( ( V_169 = F_74 ( V_264 ) ) == NULL ) {
F_2 ( V_17 L_70
L_71 , V_264 ) ;
F_103 ( V_236 , V_262 , V_263 ) ;
return;
}
while ( V_262 != V_263 ) {
unsigned int V_3 = V_262 -> V_3 - V_265 ;
F_107 ( V_262 , V_265 ,
F_54 ( V_169 , V_3 ) ,
V_3 ) ;
V_238 = V_262 -> V_35 ;
F_100 ( V_236 , V_262 ) ;
V_262 = V_238 ;
}
}
V_151 = F_65 ( V_169 ) ;
F_70 ( V_31 , V_12 , V_169 , V_151 ) ;
}
static void F_100 ( V_229 * V_236 , struct V_168 * V_169 )
{
F_86 ( V_169 ) ;
V_236 -> V_232 -- ;
}
static void F_97 ( int V_6 , struct V_168 * V_169 )
{
F_2 ( V_11 L_72 ,
V_6 , ( int ) V_169 -> V_3 ,
( int ) V_169 -> V_2 [ 0 ] , ( int ) V_169 -> V_2 [ 1 ] , ( int ) V_169 -> V_2 [ 2 ] ,
( int ) V_169 -> V_2 [ 3 ] , ( int ) V_169 -> V_2 [ 4 ] , ( int ) V_169 -> V_2 [ 5 ] ) ;
}
static int
F_37 ( struct V_13 * V_14 , int V_5 )
{
char V_267 [ V_268 + 1 ] ;
T_2 * V_74 ;
T_1 * V_12 , * V_269 ;
int V_270 ;
unsigned long V_131 ;
sprintf ( V_267 , L_73 , V_5 ) ;
V_74 = F_108 ( V_267 ) ;
if ( ! V_74 ) {
F_2 ( V_17 L_74 , V_267 ) ;
return - V_88 ;
}
F_45 ( & V_74 -> V_20 -> V_21 , V_131 ) ;
V_269 = V_14 -> V_12 ;
V_12 = V_74 -> V_249 ;
if ( V_269 -> V_15 < 0 || V_269 -> V_15 >= V_16 ||
V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_75 ,
V_269 -> V_15 < 0 || V_269 -> V_15 >= V_16 ?
V_269 -> V_15 : V_12 -> V_15 ) ;
V_270 = - V_88 ;
goto V_38;
}
F_109 ( V_74 , V_269 ) ;
V_23 [ V_269 -> V_15 ] -> V_5 = V_23 [ V_12 -> V_15 ] -> V_5 ;
V_23 [ V_269 -> V_15 ] -> V_60 |= V_23 [ V_12 -> V_15 ] -> V_60 &
( V_96 | V_215 | V_271 ) ;
V_23 [ V_269 -> V_15 ] -> V_61 |= V_23 [ V_12 -> V_15 ] -> V_61 &
( V_219 | V_177 | V_220 | V_246 ) ;
V_270 = F_12 ( V_269 , V_74 -> V_20 ) ;
V_38:
F_46 ( & V_74 -> V_20 -> V_21 , V_131 ) ;
return V_270 ;
}
static int
F_110 ( int V_6 , struct V_272 * V_273 , struct V_179 * V_32 )
{
struct V_274 T_3 * V_275 = V_273 -> V_276 ;
struct V_274 V_277 ;
T_1 * V_12 = F_88 ( V_32 ) ;
memset ( & V_277 , 0 , sizeof( struct V_274 ) ) ;
if ( V_32 -> V_131 & V_278 ) {
V_277 . V_74 . V_279 = V_12 -> V_200 . V_280 ;
V_277 . V_74 . V_281 = V_12 -> V_200 . V_282 ;
V_277 . V_74 . V_283 = V_12 -> V_200 . V_284 ;
V_277 . V_74 . V_285 = V_12 -> V_200 . V_286 ;
V_277 . V_74 . V_287 = V_12 -> V_200 . V_288 ;
V_277 . V_74 . V_289 = V_12 -> V_200 . V_290 ;
#ifdef F_19
if ( V_6 >= 0 && V_23 [ V_6 ] -> V_71 ) {
struct V_107 * V_71 = V_23 [ V_6 ] -> V_71 ;
V_277 . V_291 . V_292 = V_71 -> V_293 + V_71 -> V_294 ;
V_277 . V_291 . V_295 = V_71 -> V_293 ;
V_277 . V_291 . V_296 = V_71 -> V_297 ;
V_277 . V_291 . V_298 = V_71 -> V_299 ;
V_277 . V_291 . V_300 = V_71 -> V_301 ;
V_277 . V_291 . V_302 = V_71 -> V_303 ;
V_277 . V_291 . V_304 = V_71 -> V_305 ;
V_277 . V_291 . V_306 = V_71 -> V_307 ;
}
#endif
}
if ( F_33 ( V_275 , & V_277 , sizeof( struct V_274 ) ) )
return - V_77 ;
return 0 ;
}
int
F_111 ( struct V_179 * V_32 , struct V_272 * V_273 , int V_84 )
{
int error = 0 ;
int V_3 ;
T_1 * V_12 = F_88 ( V_32 ) ;
if ( V_12 -> V_308 != V_309 )
return - V_88 ;
switch ( V_84 ) {
#define F_112 "2.3.7"
case V_310 :
V_3 = strlen ( F_112 ) + 1 ;
if ( F_33 ( V_273 -> V_276 , F_112 , V_3 ) )
error = - V_77 ;
break;
case V_311 :
error = F_110 ( V_12 -> V_15 , V_273 , V_32 ) ;
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
V_312 ;
V_3 = strlen ( V_39 ) ;
if ( strncmp ( L_76 , V_39 , 4 ) || V_3 > 8 )
return - 1 ;
for ( V_9 = 0 , V_312 = 1 ; V_9 < V_3 ; V_9 ++ , V_312 *= 10 ) {
char V_313 = V_39 [ V_3 - V_9 - 1 ] ;
if ( V_313 >= '0' && V_313 <= '9' )
V_5 += ( V_313 - '0' ) * V_312 ;
else
break;
}
if ( ! V_9 || V_3 - V_9 != 4 )
V_5 = - 1 ;
return V_5 ;
}
int
F_113 ( char * V_39 )
{
#ifdef F_4
T_2 * V_314 ;
T_1 * V_12 ;
struct V_179 * V_315 ;
if ( ! ( V_314 = F_108 ( V_39 ) ) )
return 1 ;
V_12 = V_314 -> V_34 ;
if ( ! ( V_12 -> V_131 & V_166 ) )
return 5 ;
V_315 = V_12 -> V_316 ;
while ( V_315 ) {
T_1 * V_181 = F_88 ( V_315 ) ;
if ( ! ( V_181 -> V_131 & V_166 ) )
break;
V_315 = V_181 -> V_316 ;
}
if ( ! V_315 )
return 2 ;
F_114 ( F_88 ( V_315 ) ) ;
return 0 ;
#else
return - 1 ;
#endif
}
int
F_115 ( char * V_39 )
{
#ifdef F_4
T_2 * V_314 ;
T_1 * V_12 ;
struct V_179 * V_315 ;
if ( ! ( V_314 = F_108 ( V_39 ) ) )
return 1 ;
V_12 = V_314 -> V_34 ;
if ( ! ( V_12 -> V_131 & V_166 ) )
return 5 ;
V_315 = V_12 -> V_316 ;
while ( V_315 ) {
T_1 * V_181 = F_88 ( V_315 ) ;
if ( V_181 -> V_316 ) {
T_1 * V_269 = F_116 ( V_181 ) ;
if ( ! ( V_269 -> V_131 & V_166 ) )
break;
} else if ( V_181 -> V_131 & V_166 )
break;
V_315 = V_181 -> V_316 ;
}
if ( ! V_315 )
return 2 ;
F_26 ( V_315 ) ;
return 0 ;
#else
return - 1 ;
#endif
}
static void F_117 ( struct V_13 * V_14 )
{
F_47 ( NULL , 0 , V_189 , V_14 -> V_12 -> V_15 ) ;
}
static void F_118 ( struct V_13 * V_14 , int V_151 ,
unsigned char V_82 , unsigned char V_317 ,
unsigned char * V_2 , int V_3 )
{
struct V_168 * V_169 ;
unsigned char * V_74 ;
int V_167 ;
int V_7 = 0 ;
T_1 * V_12 = V_14 -> V_12 ;
V_167 = V_32 -> V_163 [ V_12 -> V_161 ] -> V_170 -> V_171 ;
V_169 = F_52 ( V_3 + V_167 + 16 , V_153 ) ;
if ( ! V_169 ) {
F_2 ( V_37
L_77 ) ;
return;
}
F_53 ( V_169 , V_167 ) ;
if ( ! ( V_14 -> V_60 & V_225 ) ) {
V_74 = F_54 ( V_169 , 2 ) ;
* V_74 ++ = 0xff ;
* V_74 ++ = 0x03 ;
}
V_74 = F_54 ( V_169 , 6 ) ;
* V_74 ++ = ( V_151 >> 8 ) ;
* V_74 ++ = ( V_151 & 0xff ) ;
* V_74 ++ = V_82 ;
* V_74 ++ = V_317 ;
V_7 = 4 + V_3 ;
* V_74 ++ = ( V_7 >> 8 ) ;
* V_74 ++ = ( V_7 & 0xff ) ;
if ( V_3 ) {
F_119 ( V_169 , V_2 , V_3 ) ;
}
F_2 ( V_11 L_78 ) ;
F_1 ( L_79 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
F_57 ( V_12 , V_169 ) ;
}
static struct V_318 * F_17 ( struct V_13 * V_14 )
{
struct V_318 * V_85 ;
V_85 = F_60 ( sizeof( struct V_318 ) , V_172 ) ;
if ( ! V_85 ) {
F_2 ( V_17 L_80
L_81 ) ;
return NULL ;
}
F_2 ( V_11 L_82 , V_85 ) ;
V_14 -> V_57 = V_85 ;
return V_85 ;
}
static void F_22 ( struct V_13 * V_14 )
{
unsigned int V_317 ;
F_2 ( V_11 L_83 ,
V_14 -> V_57 ) ;
for ( V_317 = 0 ; V_317 < 256 ; V_317 ++ ) {
if ( V_14 -> V_57 -> V_319 [ V_317 ] ) {
F_120 ( V_14 , ( unsigned char ) V_317 ) ;
}
}
F_27 ( V_14 -> V_57 ) ;
V_14 -> V_57 = NULL ;
}
static void F_120 ( struct V_13 * V_14 ,
unsigned char V_317 )
{
struct V_320 * V_319 ;
if ( V_14 -> V_57 -> V_319 [ V_317 ] ) {
F_2 ( V_11 L_84 , V_317 ) ;
V_319 = V_14 -> V_57 -> V_319 [ V_317 ] ;
if ( V_319 -> V_321 )
F_121 ( & V_319 -> V_322 ) ;
V_14 -> V_57 -> V_319 [ V_317 ] = NULL ;
F_27 ( V_319 ) ;
} else {
F_2 ( V_37 L_85 , V_317 ) ;
}
}
static void F_122 ( unsigned long V_323 )
{
struct V_320 * V_319 =
(struct V_320 * ) V_323 ;
if ( ! V_319 ) {
F_2 ( V_17 L_86 ) ;
return;
}
if ( V_319 -> V_321 && V_319 -> V_24 == V_324 ) {
if ( ! V_319 -> V_325 ) {
V_319 -> V_321 = 0 ;
F_120 ( V_319 -> V_14 , V_319 -> V_317 ) ;
return;
}
F_2 ( V_11 L_87 ,
V_319 -> V_317 ) ;
F_118 ( V_319 -> V_14 , V_196 , V_198 , V_319 -> V_317 ,
V_319 -> V_2 , V_319 -> V_326 ) ;
V_319 -> V_322 . V_327 = V_328 + V_329 * 5 ;
F_123 ( & V_319 -> V_322 ) ;
} else {
F_2 ( V_37 L_88 ,
V_319 -> V_24 ) ;
}
}
static struct V_320 * F_124 ( struct V_13 * V_14 ,
unsigned char V_317 )
{
struct V_320 * V_319 ;
if ( V_14 -> V_57 -> V_319 [ V_317 ] ) {
F_2 ( V_37 L_89 ,
V_317 ) ;
return NULL ;
} else {
V_319 = F_60 ( sizeof( struct V_320 ) , V_153 ) ;
if ( ! V_319 )
return NULL ;
V_319 -> V_24 = V_330 ;
V_319 -> V_14 = V_14 ;
V_319 -> V_317 = V_317 ;
F_125 ( & V_319 -> V_322 , F_122 ,
( unsigned long ) V_319 ) ;
V_14 -> V_57 -> V_319 [ V_317 ] = V_319 ;
}
return V_319 ;
}
static void F_126 ( struct V_13 * V_14 ,
struct V_331 * V_332 )
{
struct V_320 * V_319 ;
if ( V_332 -> V_333 ) {
if ( V_332 -> V_334 ) {
if ( ! ( V_332 -> V_335 ) ) {
F_2 ( V_17 L_90
L_91 ) ;
return;
}
if ( V_14 -> V_57 -> V_319 [ V_332 -> V_317 ] ) {
V_319 = V_14 -> V_57 -> V_319 [ V_332 -> V_317 ] ;
if ( V_319 -> V_24 == V_324 && V_319 -> V_321 ) {
F_2 ( V_11 L_92
L_93
L_94 , V_332 -> V_317 ) ;
} else {
F_2 ( V_37 L_92
L_95
L_96 , V_319 -> V_24 , V_332 -> V_317 ) ;
}
} else {
F_2 ( V_11 L_97
L_98 , V_332 -> V_317 ) ;
V_319 = F_124 ( V_14 , V_332 -> V_317 ) ;
if ( ! V_319 ) {
F_2 ( V_17 L_99
L_100 ) ;
return;
}
V_319 -> V_24 = V_324 ;
V_319 -> V_325 = V_332 -> V_325 ;
if ( V_332 -> V_336 ) {
V_319 -> V_326 = V_332 -> V_326 ;
memcpy ( V_319 -> V_2 , V_332 -> V_2 , V_332 -> V_326 ) ;
}
F_118 ( V_14 , V_196 ,
V_198 , V_319 -> V_317 ,
V_319 -> V_2 , V_319 -> V_326 ) ;
V_319 -> V_322 . V_327 = V_328 + 5 * V_329 ;
F_123 ( & V_319 -> V_322 ) ;
V_319 -> V_321 = 1 ;
}
} else {
F_2 ( V_11 L_101 ) ;
}
} else {
if ( V_14 -> V_57 -> V_319 [ V_14 -> V_57 -> V_337 ] ) {
V_319 = V_14 -> V_57 -> V_319 [ V_14 -> V_57 -> V_337 ] ;
if ( V_319 -> V_24 == V_324 && V_319 -> V_321 ) {
F_2 ( V_11 L_92
L_93
L_94 , V_332 -> V_317 ) ;
} else {
F_2 ( V_37 L_92
L_95
L_96 , V_319 -> V_24 , V_332 -> V_317 ) ;
}
} else {
F_2 ( V_11 L_97
L_98 , V_14 -> V_57 -> V_337 ) ;
V_319 = F_124 ( V_14 ,
V_14 -> V_57 -> V_337 ) ;
if ( ! V_319 ) {
F_2 ( V_17 L_99
L_100 ) ;
return;
}
V_319 -> V_24 = V_324 ;
V_319 -> V_325 = 1 ;
V_319 -> V_326 = 0 ;
F_118 ( V_14 , V_196 , V_198 ,
V_319 -> V_317 , NULL , 0 ) ;
V_319 -> V_322 . V_327 = V_328 + 5 * V_329 ;
F_123 ( & V_319 -> V_322 ) ;
V_319 -> V_321 = 1 ;
}
}
}
static void F_127 ( struct V_13 * V_14 ,
unsigned char V_317 )
{
struct V_320 * V_319 = V_14 -> V_57 -> V_319 [ V_317 ] ;
if ( V_319 ) {
if ( V_319 -> V_321 && V_319 -> V_24 == V_324 ) {
if ( ! V_319 -> V_325 )
F_2 ( V_11 L_102
L_103 , V_317 ) ;
} else {
F_2 ( V_191 L_104
L_105 , V_317 ) ;
}
if ( V_319 -> V_321 ) {
V_319 -> V_321 = 0 ;
F_121 ( & V_319 -> V_322 ) ;
}
F_120 ( V_14 , V_317 ) ;
} else {
F_2 ( V_191 L_106
L_107 , V_317 ) ;
}
V_14 -> V_57 -> V_337 ++ ;
}
static struct V_168 * F_68 ( struct V_168 * V_169 , struct V_13 * V_14 , struct V_13 * V_175 ,
int * V_151 )
{
void * V_338 = NULL ;
struct V_113 * V_114 = NULL ;
struct V_168 * V_339 ;
int V_3 ;
struct V_13 * V_340 ;
struct V_331 V_341 ;
unsigned char V_342 [ V_343 ] ;
if ( ! V_175 ) {
V_338 = V_14 -> V_54 ;
V_114 = V_14 -> V_50 ;
V_340 = V_14 ;
} else {
V_338 = V_175 -> V_55 ;
V_114 = V_175 -> V_51 ;
V_340 = V_175 ;
}
if ( ! V_114 ) {
F_2 ( V_11 L_108 ) ;
return V_169 ;
}
F_67 ( ! V_338 ) ;
if ( ( V_175 && * V_151 == V_189 ) || ( ! V_175 && * V_151 == V_190 ) ) {
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_2 = V_342 ;
V_341 . V_344 = V_343 ;
V_339 = F_74 ( V_14 -> V_63 + V_345 ) ;
if ( ! V_339 ) {
F_55 ( V_169 ) ;
F_2 ( V_17 L_109 ) ;
return NULL ;
}
V_3 = V_114 -> V_346 ( V_338 , V_169 , V_339 , & V_341 ) ;
F_55 ( V_169 ) ;
if ( V_3 <= 0 ) {
switch ( V_3 ) {
case V_347 :
F_2 ( V_191 L_110 ,
V_341 . V_333 ? L_111 : L_112 ) ;
F_126 ( V_340 , & V_341 ) ;
break;
case V_348 :
V_340 -> V_60 |= V_349 ;
F_117 ( V_340 ) ;
break;
}
F_55 ( V_339 ) ;
return NULL ;
}
* V_151 = F_65 ( V_339 ) ;
if ( * V_151 < 0 ) {
F_55 ( V_339 ) ;
return NULL ;
}
return V_339 ;
} else {
V_114 -> V_350 ( V_338 , V_169 , * V_151 ) ;
return V_169 ;
}
}
static struct V_168 * F_92 ( struct V_168 * V_351 , int * V_151 ,
struct V_13 * V_14 , struct V_13 * V_175 , int type )
{
int V_352 ;
int V_353 ;
struct V_113 * V_49 ;
void * V_338 ;
struct V_168 * V_339 ;
if ( * V_151 < 0 || * V_151 > 0x3fff ) {
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
F_2 ( V_17 L_113 ) ;
return V_351 ;
}
if ( ! V_338 ) {
F_2 ( V_17 L_114 ) ;
return V_351 ;
}
V_339 = F_52 ( V_351 -> V_3 + V_351 -> V_3 / 2 + 32 +
F_84 ( V_351 ) , V_153 ) ;
if ( ! V_339 )
return V_351 ;
F_53 ( V_339 , F_84 ( V_351 ) ) ;
V_352 = ( V_49 -> V_354 ) ( V_338 , V_351 , V_339 , * V_151 ) ;
if ( ! V_352 ) {
F_86 ( V_339 ) ;
return V_351 ;
}
F_86 ( V_351 ) ;
* V_151 = V_353 ;
return V_339 ;
}
static void F_78 ( T_2 * V_31 , T_1 * V_12 ,
struct V_168 * V_169 , int V_151 )
{
struct V_13 * V_14 ;
struct V_13 * V_180 ;
int V_3 ;
struct V_331 V_341 ;
unsigned char V_342 [ V_343 ] ;
F_2 ( V_11 L_115 ,
V_12 -> V_15 ) ;
if ( V_12 -> V_15 < 0 || V_12 -> V_15 >= V_16 ) {
F_2 ( V_17 L_58 ,
V_18 , V_12 -> V_15 ) ;
return;
}
V_14 = V_23 [ V_12 -> V_15 ] ;
F_1 ( L_116 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_175 ) {
int V_6 = F_71 ( V_12 ) -> V_15 ;
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
F_2 ( V_11 L_117 ) ;
if ( V_151 == V_196 )
V_180 -> V_56 &= ~ V_218 ;
else
V_14 -> V_56 &= ~ V_223 ;
break;
case V_356 :
case V_357 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_118 ) ;
if ( V_151 == V_196 )
V_180 -> V_56 &= ~ ( V_183 | V_218 ) ;
else
V_14 -> V_56 &= ~ ( V_176 | V_223 ) ;
break;
case V_358 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_119 ) ;
if ( V_151 == V_196 ) {
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
F_2 ( V_11 L_120 ) ;
V_3 = ( V_169 -> V_2 [ 2 ] << 8 ) | V_169 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_151 == V_196 ) {
F_127 ( V_180 , V_169 -> V_2 [ 1 ] ) ;
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
F_127 ( V_14 , V_169 -> V_2 [ 1 ] ) ;
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
F_2 ( V_11 L_121 ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_2 = V_342 ;
V_341 . V_344 = V_343 ;
V_3 = ( V_169 -> V_2 [ 2 ] << 8 ) | V_169 -> V_2 [ 3 ] ;
V_3 -= 4 ;
if ( V_151 == V_196 ) {
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
F_118 ( V_14 , V_151 , V_199 ,
V_341 . V_335 ? V_341 . V_317
: V_169 -> V_2 [ 1 ] ,
V_341 . V_336 ?
V_341 . V_2 : NULL ,
V_341 . V_336 ?
V_341 . V_326 : 0 ) ;
} else {
F_2 ( V_11 L_122 ) ;
}
} else {
F_118 ( V_14 , V_151 , V_199 ,
V_169 -> V_2 [ 1 ] ,
V_3 ? & V_169 -> V_2 [ 4 ] : NULL ,
V_3 ) ;
}
break;
}
}
static void F_56 ( T_2 * V_31 , T_1 * V_12 , struct V_168 * V_169 )
{
struct V_13 * V_180 , * V_14 ;
int V_151 , V_6 = V_12 -> V_15 ;
unsigned char * V_2 ;
if ( ! V_169 || V_169 -> V_3 < 3 )
return;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_58 ,
V_18 , V_6 ) ;
return;
}
V_14 = V_23 [ V_6 ] ;
V_2 = V_169 -> V_2 ;
if ( ! ( V_14 -> V_60 & V_225 ) && V_2 [ 0 ] == 0xff && V_2 [ 1 ] == 0x03 ) {
V_2 += 2 ;
if ( V_169 -> V_3 < 5 )
return;
}
V_151 = ( ( int ) V_2 [ 0 ] << 8 ) + V_2 [ 1 ] ;
if ( V_151 != V_196 && V_151 != V_197 )
return;
F_2 ( V_11 L_123 ) ;
F_1 ( L_79 , V_169 -> V_2 , V_169 -> V_3 , 32 , V_14 -> V_5 , V_12 -> V_15 ) ;
if ( V_12 -> V_175 ) {
V_6 = F_71 ( V_12 ) -> V_15 ;
if ( V_6 < 0 || V_6 >= V_16 ) {
F_2 ( V_17 L_8 ,
V_18 , V_6 ) ;
return;
}
V_180 = V_23 [ V_6 ] ;
} else
V_180 = V_14 ;
if ( V_180 != V_14 )
F_2 ( V_11 L_124 ) ;
switch ( V_2 [ 2 ] ) {
case V_355 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_125 ) ;
if ( V_151 == V_196 )
V_14 -> V_56 &= ~ V_183 ;
else
V_14 -> V_56 &= ~ V_176 ;
break;
case V_356 :
case V_357 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_118 ) ;
if ( V_151 == V_196 )
V_14 -> V_56 &= ~ ( V_183 | V_218 ) ;
else
V_14 -> V_56 &= ~ ( V_176 | V_223 ) ;
break;
case V_358 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_126 ) ;
if ( V_151 == V_196 ) {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_218 ;
} else {
if ( ! V_14 -> V_49 )
break;
V_14 -> V_56 |= V_223 ;
}
break;
case V_199 :
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_127 ) ;
F_2 ( V_11 L_128 ) ;
if ( V_151 == V_196 ) {
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
F_2 ( V_11 L_129 ) ;
break;
}
}
int F_128 ( struct V_113 * V_114 )
{
V_114 -> V_35 = V_115 ;
V_114 -> V_363 = NULL ;
if ( V_115 ) {
V_115 -> V_363 = V_114 ;
}
V_115 = V_114 ;
return 0 ;
}
int F_129 ( struct V_113 * V_114 )
{
if ( V_114 -> V_363 )
V_114 -> V_363 -> V_35 = V_114 -> V_35 ;
else
V_115 = V_114 -> V_35 ;
if ( V_114 -> V_35 )
V_114 -> V_35 -> V_363 = V_114 -> V_363 ;
V_114 -> V_363 = V_114 -> V_35 = NULL ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 , struct V_86 * V_2 )
{
struct V_113 * V_114 = V_115 ;
int V_352 ;
void * V_338 ;
int V_116 = V_2 -> V_116 ;
if ( V_14 -> V_28 & 0x10 )
F_2 ( V_11 L_130 , V_14 -> V_5 ,
( V_2 -> V_131 & V_364 ) ? L_131 : L_132 , V_116 ) ;
if ( ! ( V_2 -> V_131 & V_364 ) && ! V_14 -> V_57 ) {
F_2 ( V_17 L_133
L_134 ) ;
return - V_58 ;
}
while ( V_114 ) {
if ( V_114 -> V_116 == V_116 ) {
V_338 = V_114 -> V_365 ( V_2 ) ;
if ( V_338 ) {
V_352 = V_114 -> V_366 ( V_338 , V_2 , V_14 -> V_5 , 0 ) ;
if ( ! V_352 ) {
F_2 ( V_17 L_135 ) ;
V_114 -> free ( V_338 ) ;
V_338 = NULL ;
break;
}
}
else {
F_2 ( V_17 L_136 ) ;
break;
}
if ( V_2 -> V_131 & V_364 ) {
if ( V_2 -> V_131 & V_367 ) {
if ( V_14 -> V_52 )
V_14 -> V_48 -> free ( V_14 -> V_52 ) ;
V_14 -> V_52 = V_338 ;
V_14 -> V_48 = V_114 ;
}
else {
if ( V_14 -> V_53 )
V_14 -> V_49 -> free ( V_14 -> V_53 ) ;
V_14 -> V_53 = V_338 ;
V_14 -> V_49 = V_114 ;
}
}
else {
if ( V_2 -> V_131 & V_367 ) {
if ( V_14 -> V_54 )
V_14 -> V_50 -> free ( V_14 -> V_54 ) ;
V_14 -> V_54 = V_338 ;
V_14 -> V_50 = V_114 ;
}
else {
if ( V_14 -> V_55 )
V_14 -> V_51 -> free ( V_14 -> V_55 ) ;
V_14 -> V_55 = V_338 ;
V_14 -> V_51 = V_114 ;
}
}
return 0 ;
}
V_114 = V_114 -> V_35 ;
}
return - V_88 ;
}
