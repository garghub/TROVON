static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
char * V_4 ;
int V_5 ;
int V_6 = 0 ;
if ( ! V_1 )
return - V_7 ;
V_5 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( V_4 == V_1 )
return - V_7 ;
* ( ( int * ) V_3 -> V_8 ) = V_5 ;
if ( V_9 )
V_6 = F_3 ( V_10 ) ;
return V_6 ;
}
static int F_4 ( const char * V_1 , const struct V_2 * V_3 )
{
T_1 V_11 = ( T_1 ) V_3 -> V_8 ;
int V_6 = 0 ;
char V_12 [ 16 ] ;
char * V_13 ;
strncpy ( V_12 , V_1 , 16 ) ;
V_12 [ 15 ] = '\0' ;
V_13 = F_5 ( V_12 ) ;
V_6 = V_11 ( V_13 , NULL ) ;
if ( V_6 )
goto V_14;
F_6 () ;
if ( V_9 )
V_6 = F_3 ( V_10 ) ;
V_14:
return V_6 ;
}
static int F_7 ( char * V_15 , const struct V_2 * V_3 )
{
T_1 V_11 = ( T_1 ) V_3 -> V_8 ;
int V_6 ;
V_6 = V_11 ( NULL , V_15 ) ;
if ( V_6 )
return V_6 ;
return strlen ( V_15 ) ;
}
static int F_8 ( const char * V_1 , const struct V_2 * V_3 )
{
int V_6 = F_9 ( V_1 , V_3 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_16 < 0 ) || ( V_16 == V_17 ) )
return 0 ;
F_10 ( V_17 ) ;
F_11 ( V_16 ) ;
return 0 ;
}
static void F_12 ( struct V_18 * V_19 )
{
if ( F_13 ( & V_20 ) )
F_14 ( & V_21 ) ;
}
static void F_15 ( struct V_22 * V_19 )
{
if ( F_13 ( & V_20 ) )
F_14 ( & V_21 ) ;
}
static int F_16 ( struct V_18 * V_23 ,
struct V_22 * V_24 ,
int * V_25 )
{
struct V_26 V_19 ;
unsigned char V_27 [ 6 ] ;
int V_6 ;
struct V_28 V_29 ;
int V_30 = 0 ;
V_31 = 0 ;
V_27 [ 0 ] = 0 ;
F_17 ( V_27 [ 0 ] , V_32 ) ;
if ( ( V_33 > 1 )
|| ( ( V_33 == 1 ) && ( V_34 >= 5 ) ) ) {
V_27 [ 0 ] |= V_35 ;
} else if ( V_36 != V_37 ) {
V_30 = 1 ;
}
V_27 [ 1 ] = 0 ;
F_18 ( V_27 [ 1 ] , V_36 ) ;
if ( ( V_38 > 0 ) && ( V_36 != V_37 ) ) {
F_19 ( V_27 [ 1 ] , V_39 ) ;
V_27 [ 2 ] = V_38 ;
} else {
F_19 ( V_27 [ 1 ] , V_40 ) ;
V_27 [ 2 ] = 0 ;
}
V_27 [ 3 ] = 0 ;
F_20 ( V_27 [ 4 ] , V_27 [ 5 ] , V_41 ) ;
V_29 . V_42 = V_43 ;
V_29 . V_44 = V_45 ;
V_29 . V_46 = 0 ;
V_19 . V_47 = 0x06 ;
V_19 . V_48 = V_49 ;
V_19 . V_27 = V_27 ;
V_19 . V_50 = sizeof( V_27 ) ;
V_6 = F_21 ( V_9 ,
(struct V_51 * ) & V_29 ,
0 ,
& V_19 ,
NULL ,
V_23 ,
V_24 ,
1 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_1 ,
rv) ;
}
if ( V_25 )
* V_25 = V_30 ;
return V_6 ;
}
static int F_3 ( int V_52 )
{
int V_25 ;
int V_6 ;
F_23 ( & V_53 ) ;
F_24 ( & V_20 , 2 ) ;
V_6 = F_16 ( & V_54 ,
& V_55 ,
& V_25 ) ;
if ( V_6 ) {
F_25 ( & V_53 ) ;
goto V_14;
}
F_26 ( & V_21 ) ;
F_25 ( & V_53 ) ;
if ( ( V_52 == V_56 )
|| ( ( V_25 )
&& ( V_52 == V_10 ) ) )
V_6 = F_27 () ;
V_14:
return V_6 ;
}
static void F_28 ( struct V_18 * V_19 )
{
F_29 ( & V_57 ) ;
}
static void F_30 ( struct V_22 * V_19 )
{
F_29 ( & V_57 ) ;
}
static void F_31 ( void )
{
struct V_26 V_19 ;
struct V_28 V_29 ;
int V_6 ;
if ( V_36 == V_37 )
return;
V_29 . V_42 = V_43 ;
V_29 . V_44 = V_45 ;
V_29 . V_46 = 0 ;
V_19 . V_47 = 0x06 ;
V_19 . V_48 = V_58 ;
V_19 . V_27 = NULL ;
V_19 . V_50 = 0 ;
F_32 ( 2 , & V_57 ) ;
V_6 = F_21 ( V_9 ,
(struct V_51 * ) & V_29 ,
0 ,
& V_19 ,
NULL ,
& V_59 ,
& V_60 ,
1 ) ;
if ( V_6 )
F_33 ( 2 , & V_57 ) ;
}
static void F_34 ( void )
{
int V_25 ;
int V_6 ;
while ( F_35 ( & V_57 ) != 0 )
F_36 ( V_9 ) ;
F_32 ( 2 , & V_57 ) ;
V_6 = F_16 ( & V_61 ,
& V_62 ,
& V_25 ) ;
if ( V_6 ) {
F_33 ( 2 , & V_57 ) ;
F_22 (KERN_WARNING PFX
L_2 ) ;
} else {
if ( V_25 )
F_31 () ;
}
while ( F_35 ( & V_57 ) != 0 )
F_36 ( V_9 ) ;
}
static void F_37 ( struct V_18 * V_19 )
{
if ( F_13 ( & V_63 ) )
F_14 ( & V_64 ) ;
}
static void F_38 ( struct V_22 * V_19 )
{
if ( F_13 ( & V_63 ) )
F_14 ( & V_64 ) ;
}
static int F_27 ( void )
{
struct V_26 V_19 ;
int V_6 ;
struct V_28 V_29 ;
int V_65 = 0 ;
if ( V_66 )
return 0 ;
if ( V_67 ) {
V_67 = 0 ;
V_36 = V_68 ;
return F_3 ( V_56 ) ;
} else if ( V_31 ) {
return F_3 ( V_10 ) ;
}
F_23 ( & V_69 ) ;
V_70:
F_24 ( & V_63 , 2 ) ;
if ( V_36 == V_37 ) {
F_25 ( & V_69 ) ;
return 0 ;
}
V_29 . V_42 = V_43 ;
V_29 . V_44 = V_45 ;
V_29 . V_46 = 0 ;
V_19 . V_47 = 0x06 ;
V_19 . V_48 = V_58 ;
V_19 . V_27 = NULL ;
V_19 . V_50 = 0 ;
V_6 = F_21 ( V_9 ,
(struct V_51 * ) & V_29 ,
0 ,
& V_19 ,
NULL ,
& V_71 ,
& V_72 ,
1 ) ;
if ( V_6 ) {
F_25 ( & V_69 ) ;
F_22 (KERN_WARNING PFX L_3 ,
rv) ;
return V_6 ;
}
F_26 ( & V_64 ) ;
if ( V_72 . V_19 . V_27 [ 0 ] == V_73 ) {
V_65 ++ ;
if ( V_65 > 3 ) {
F_22 (KERN_ERR PFX L_4
L_5 ) ;
V_6 = - V_74 ;
goto V_75;
}
V_6 = F_3 ( V_76 ) ;
if ( V_6 ) {
F_22 (KERN_ERR PFX L_6
L_7 ) ;
goto V_75;
}
goto V_70;
} else if ( V_72 . V_19 . V_27 [ 0 ] != 0 ) {
V_6 = - V_7 ;
}
V_75:
F_25 ( & V_69 ) ;
return V_6 ;
}
static int F_39 ( struct V_77 * V_77 ,
unsigned int V_48 , unsigned long V_8 )
{
void T_2 * V_78 = ( void T_2 * ) V_8 ;
int V_79 ;
int V_1 ;
switch ( V_48 ) {
case V_80 :
V_79 = F_40 ( V_78 , & V_81 , sizeof( V_81 ) ) ;
return V_79 ? - V_82 : 0 ;
case V_83 :
V_79 = F_41 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
V_41 = V_1 ;
return F_3 ( V_10 ) ;
case V_84 :
V_79 = F_40 ( V_78 , & V_41 , sizeof( V_41 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
case V_85 :
V_79 = F_41 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
V_38 = V_1 ;
return F_3 ( V_10 ) ;
case V_86 :
V_79 = F_40 ( V_78 , & V_38 , sizeof( V_38 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
case V_87 :
return F_27 () ;
case V_88 :
V_79 = F_41 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
if ( V_1 & V_89 ) {
V_36 = V_37 ;
F_3 ( V_76 ) ;
V_67 = 0 ;
}
if ( V_1 & V_90 ) {
V_36 = V_68 ;
F_3 ( V_56 ) ;
}
return 0 ;
case V_91 :
V_1 = 0 ;
V_79 = F_40 ( V_78 , & V_1 , sizeof( V_1 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
default:
return - V_92 ;
}
}
static long F_42 ( struct V_77 * V_77 ,
unsigned int V_48 ,
unsigned long V_8 )
{
int V_93 ;
F_23 ( & V_94 ) ;
V_93 = F_39 ( V_77 , V_48 , V_8 ) ;
F_25 ( & V_94 ) ;
return V_93 ;
}
static T_3 F_43 ( struct V_77 * V_77 ,
const char T_2 * V_95 ,
T_4 V_96 ,
T_5 * V_97 )
{
int V_6 ;
if ( V_96 ) {
if ( ! V_98 ) {
T_4 V_79 ;
V_99 = 0 ;
for ( V_79 = 0 ; V_79 != V_96 ; V_79 ++ ) {
char V_100 ;
if ( F_44 ( V_100 , V_95 + V_79 ) )
return - V_82 ;
if ( V_100 == 'V' )
V_99 = 42 ;
}
}
V_6 = F_27 () ;
if ( V_6 )
return V_6 ;
}
return V_96 ;
}
static T_3 F_45 ( struct V_77 * V_77 ,
char T_2 * V_95 ,
T_4 V_101 ,
T_5 * V_97 )
{
int V_6 = 0 ;
T_6 V_102 ;
if ( V_101 <= 0 )
return 0 ;
F_46 ( & V_103 ) ;
if ( ! V_104 ) {
if ( V_77 -> V_105 & V_106 ) {
V_6 = - V_107 ;
goto V_14;
}
F_47 ( & V_102 , V_108 ) ;
F_48 ( & V_109 , & V_102 ) ;
while ( ! V_104 ) {
F_49 ( V_110 ) ;
F_50 ( & V_103 ) ;
F_51 () ;
F_46 ( & V_103 ) ;
}
F_52 ( & V_109 , & V_102 ) ;
if ( F_53 ( V_108 ) ) {
V_6 = - V_111 ;
goto V_14;
}
}
V_104 = 0 ;
V_14:
F_50 ( & V_103 ) ;
if ( V_6 == 0 ) {
if ( F_40 ( V_95 , & V_104 , 1 ) )
V_6 = - V_82 ;
else
V_6 = 1 ;
}
return V_6 ;
}
static int F_54 ( struct V_112 * V_113 , struct V_77 * V_114 )
{
switch ( F_55 ( V_113 ) ) {
case V_115 :
if ( F_56 ( 0 , & V_116 ) )
return - V_117 ;
V_67 = 1 ;
return F_57 ( V_113 , V_114 ) ;
default:
return ( - V_118 ) ;
}
}
static unsigned int F_58 ( struct V_77 * V_77 , T_7 * V_102 )
{
unsigned int V_119 = 0 ;
F_59 ( V_77 , & V_109 , V_102 ) ;
F_46 ( & V_103 ) ;
if ( V_104 )
V_119 |= ( V_120 | V_121 ) ;
F_50 ( & V_103 ) ;
return V_119 ;
}
static int F_60 ( int V_122 , struct V_77 * V_77 , int V_123 )
{
int V_124 ;
V_124 = F_61 ( V_122 , V_77 , V_123 , & V_125 ) ;
return ( V_124 ) ;
}
static int F_62 ( struct V_112 * V_113 , struct V_77 * V_114 )
{
if ( F_55 ( V_113 ) == V_115 ) {
if ( V_99 == 42 ) {
V_36 = V_37 ;
F_3 ( V_76 ) ;
} else {
F_22 (KERN_CRIT PFX
L_8 ) ;
F_27 () ;
}
F_63 ( 0 , & V_116 ) ;
}
V_99 = 0 ;
return 0 ;
}
static void F_64 ( struct V_22 * V_19 ,
void * V_126 )
{
if ( V_19 -> V_19 . V_48 == V_58 &&
V_19 -> V_19 . V_27 [ 0 ] == V_73 )
F_22 (KERN_INFO PFX L_9
L_10
L_11 ) ;
else if ( V_19 -> V_19 . V_27 [ 0 ] != 0 )
F_22 (KERN_ERR PFX L_12 ,
msg->msg.data[0],
msg->msg.cmd) ;
F_65 ( V_19 ) ;
}
static void F_66 ( void * V_126 )
{
if ( V_39 != V_40 ) {
if ( V_127 == V_128 ) {
if ( F_67 ( & V_129 ) )
F_68 ( L_13 ) ;
} else if ( V_127 == V_130 ) {
F_46 ( & V_103 ) ;
V_104 = 1 ;
F_69 ( & V_109 ) ;
F_70 ( & V_125 , V_131 , V_132 ) ;
F_50 ( & V_103 ) ;
}
}
V_31 = 1 ;
}
static void F_11 ( int V_133 )
{
int V_6 = - V_117 ;
if ( V_9 )
goto V_14;
if ( ( V_16 >= 0 ) && ( V_16 != V_133 ) )
goto V_14;
V_17 = V_133 ;
V_6 = F_71 ( V_133 , & V_134 , NULL , & V_9 ) ;
if ( V_6 < 0 ) {
F_22 (KERN_CRIT PFX L_14 ) ;
goto V_14;
}
F_72 ( V_9 ,
& V_33 ,
& V_34 ) ;
V_6 = F_73 ( & V_135 ) ;
if ( V_6 < 0 ) {
F_74 ( V_9 ) ;
V_9 = NULL ;
F_22 (KERN_CRIT PFX L_15 ) ;
}
#ifdef F_75
if ( V_136 ) {
int V_137 = V_38 ;
int V_138 = V_41 ;
int V_139 = V_127 ;
V_36 = V_140 ;
V_127 = V_141 ;
V_38 = 99 ;
V_41 = 100 ;
V_142 = 1 ;
V_6 = F_3 ( V_56 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_16
L_17
L_18 , rv) ;
V_6 = 0 ;
goto V_143;
}
F_76 ( 1500 ) ;
if ( V_142 != 2 ) {
F_22 (KERN_WARNING PFX L_19
L_20
L_18 ) ;
}
V_143:
V_142 = 0 ;
V_127 = V_139 ;
V_38 = V_137 ;
V_41 = V_138 ;
}
#endif
V_14:
if ( ( V_144 ) && ( V_6 == 0 ) ) {
V_144 = 0 ;
V_36 = V_68 ;
F_3 ( V_56 ) ;
F_22 (KERN_INFO PFX L_21 ) ;
} else {
V_36 = V_37 ;
F_3 ( V_76 ) ;
}
}
static void F_10 ( int V_133 )
{
int V_6 ;
if ( ! V_9 )
goto V_14;
if ( V_17 != V_133 )
goto V_14;
F_77 ( & V_135 ) ;
while ( F_35 ( & V_20 ) )
F_78 ( 1 ) ;
V_6 = F_74 ( V_9 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_22 ,
rv) ;
}
V_9 = NULL ;
V_14:
return;
}
static int
F_79 ( unsigned int V_1 , struct V_145 * V_146 )
{
if ( V_142 ) {
V_142 = 2 ;
return V_147 ;
}
if ( V_36 == V_37 )
return V_148 ;
if ( V_39 != V_149 )
return V_148 ;
if ( V_127 == V_128 ) {
V_31 = 1 ;
if ( F_67 ( & V_129 ) )
F_68 ( V_150 L_23 ) ;
}
return V_147 ;
}
static int F_80 ( struct V_151 * V_152 ,
unsigned long V_153 ,
void * V_154 )
{
static int V_155 ;
if ( ( V_9 ) && ( ! V_155 ) ) {
V_155 = 1 ;
if ( V_153 == V_156 || V_153 == V_157 ) {
V_36 = V_37 ;
F_3 ( V_76 ) ;
} else if ( V_36 != V_37 ) {
V_41 = 120 ;
V_38 = 0 ;
V_36 = V_140 ;
F_3 ( V_76 ) ;
}
}
return V_158 ;
}
static int F_81 ( struct V_151 * V_152 ,
unsigned long V_159 ,
void * V_154 )
{
static int V_160 ;
if ( V_9 && ! V_160 &&
V_36 != V_37 ) {
V_160 = 1 ;
V_41 = 255 ;
V_38 = 0 ;
F_34 () ;
}
return V_158 ;
}
static void F_82 ( int V_161 , struct V_162 * V_162 )
{
F_11 ( V_161 ) ;
}
static void F_83 ( int V_161 )
{
F_10 ( V_161 ) ;
}
static int F_84 ( const char * V_163 , char * V_164 )
{
if ( V_164 )
strcpy ( V_164 , V_165 ) ;
if ( ! V_163 )
return 0 ;
if ( strcmp ( V_163 , L_24 ) == 0 )
V_68 = V_140 ;
else if ( strcmp ( V_163 , L_25 ) == 0 )
V_68 = V_37 ;
else if ( strcmp ( V_163 , L_26 ) == 0 )
V_68 = V_166 ;
else if ( strcmp ( V_163 , L_27 ) == 0 )
V_68 = V_167 ;
else
return - V_7 ;
strcpy ( V_165 , V_163 ) ;
return 0 ;
}
static int F_85 ( const char * V_163 , char * V_164 )
{
if ( V_164 )
strcpy ( V_164 , V_168 ) ;
if ( ! V_163 )
return 0 ;
if ( strcmp ( V_163 , L_28 ) == 0 )
V_39 = V_40 ;
else if ( strcmp ( V_163 , L_29 ) == 0 )
V_39 = V_169 ;
#ifdef F_75
else if ( strcmp ( V_163 , L_30 ) == 0 )
V_39 = V_149 ;
#endif
else if ( strcmp ( V_163 , L_31 ) == 0 )
V_39 = V_170 ;
else
return - V_7 ;
strcpy ( V_168 , V_163 ) ;
return 0 ;
}
static int F_86 ( const char * V_163 , char * V_164 )
{
if ( V_164 )
strcpy ( V_164 , V_171 ) ;
if ( ! V_163 )
return 0 ;
if ( strcmp ( V_163 , L_32 ) == 0 )
V_127 = V_141 ;
else if ( strcmp ( V_163 , L_33 ) == 0 )
V_127 = V_128 ;
else if ( strcmp ( V_163 , L_34 ) == 0 )
V_127 = V_130 ;
else
return - V_7 ;
strcpy ( V_171 , V_163 ) ;
return 0 ;
}
static void F_6 ( void )
{
#ifdef F_75
int V_172 = 0 ;
int V_6 ;
if ( V_39 == V_149 ) {
V_172 = 1 ;
if ( V_127 == V_130 ) {
F_22 (KERN_WARNING PFX L_35
L_36
L_37 ) ;
F_86 ( L_32 , NULL ) ;
V_172 = 0 ;
}
}
if ( V_172 && ! V_136 ) {
V_6 = F_87 ( V_173 , F_79 , 0 ,
L_38 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX
L_39 ) ;
return;
} else
V_136 = 1 ;
} else if ( ! V_172 && V_136 ) {
F_88 ( V_173 , L_38 ) ;
V_136 = 0 ;
}
#endif
}
static int T_8 F_89 ( void )
{
int V_6 ;
if ( F_84 ( V_165 , NULL ) ) {
F_84 ( L_24 , NULL ) ;
F_22 (KERN_INFO PFX L_40
L_41 , action) ;
}
if ( F_85 ( V_168 , NULL ) ) {
F_85 ( L_28 , NULL ) ;
F_22 (KERN_INFO PFX L_42
L_43 , preaction) ;
}
if ( F_86 ( V_171 , NULL ) ) {
F_86 ( L_32 , NULL ) ;
F_22 (KERN_INFO PFX L_44
L_43 , preop) ;
}
F_6 () ;
F_90 ( & V_174 ) ;
F_91 ( & V_175 ,
& V_176 ) ;
V_6 = F_92 ( & V_177 ) ;
if ( V_6 ) {
#ifdef F_75
if ( V_136 )
F_88 ( V_173 , L_38 ) ;
#endif
F_93 ( & V_175 ,
& V_176 ) ;
F_94 ( & V_174 ) ;
F_22 (KERN_WARNING PFX L_45 ) ;
return V_6 ;
}
F_22 (KERN_INFO PFX L_46 ) ;
return 0 ;
}
static void T_9 F_95 ( void )
{
F_96 ( & V_177 ) ;
F_10 ( V_17 ) ;
#ifdef F_75
if ( V_136 )
F_88 ( V_173 , L_38 ) ;
#endif
F_93 ( & V_175 ,
& V_176 ) ;
F_94 ( & V_174 ) ;
}
