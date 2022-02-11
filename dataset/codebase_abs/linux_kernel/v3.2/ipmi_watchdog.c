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
V_6 = F_21 ( V_9 ,
(struct V_51 * ) & V_29 ,
0 ,
& V_19 ,
NULL ,
& V_59 ,
& V_60 ,
1 ) ;
if ( ! V_6 )
F_32 ( 2 , & V_57 ) ;
}
static void F_33 ( void )
{
int V_25 ;
int V_6 ;
while ( F_34 ( & V_57 ) != 0 )
F_35 ( V_9 ) ;
V_6 = F_16 ( & V_61 ,
& V_62 ,
& V_25 ) ;
if ( ! V_6 ) {
F_32 ( 2 , & V_57 ) ;
if ( V_25 )
F_31 () ;
} else
F_22 (KERN_WARNING PFX
L_2 ) ;
while ( F_34 ( & V_57 ) != 0 )
F_35 ( V_9 ) ;
}
static void F_36 ( struct V_18 * V_19 )
{
if ( F_13 ( & V_63 ) )
F_14 ( & V_64 ) ;
}
static void F_37 ( struct V_22 * V_19 )
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
static int F_38 ( struct V_77 * V_77 ,
unsigned int V_48 , unsigned long V_8 )
{
void T_2 * V_78 = ( void T_2 * ) V_8 ;
int V_79 ;
int V_1 ;
switch ( V_48 ) {
case V_80 :
V_79 = F_39 ( V_78 , & V_81 , sizeof( V_81 ) ) ;
return V_79 ? - V_82 : 0 ;
case V_83 :
V_79 = F_40 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
V_41 = V_1 ;
return F_3 ( V_10 ) ;
case V_84 :
V_79 = F_39 ( V_78 , & V_41 , sizeof( V_41 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
case V_85 :
case V_86 :
V_79 = F_40 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
V_38 = V_1 ;
return F_3 ( V_10 ) ;
case V_87 :
case V_88 :
V_79 = F_39 ( V_78 , & V_38 , sizeof( V_38 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
case V_89 :
return F_27 () ;
case V_90 :
V_79 = F_40 ( & V_1 , V_78 , sizeof( int ) ) ;
if ( V_79 )
return - V_82 ;
if ( V_1 & V_91 ) {
V_36 = V_37 ;
F_3 ( V_76 ) ;
V_67 = 0 ;
}
if ( V_1 & V_92 ) {
V_36 = V_68 ;
F_3 ( V_56 ) ;
}
return 0 ;
case V_93 :
V_1 = 0 ;
V_79 = F_39 ( V_78 , & V_1 , sizeof( V_1 ) ) ;
if ( V_79 )
return - V_82 ;
return 0 ;
default:
return - V_94 ;
}
}
static long F_41 ( struct V_77 * V_77 ,
unsigned int V_48 ,
unsigned long V_8 )
{
int V_95 ;
F_23 ( & V_96 ) ;
V_95 = F_38 ( V_77 , V_48 , V_8 ) ;
F_25 ( & V_96 ) ;
return V_95 ;
}
static T_3 F_42 ( struct V_77 * V_77 ,
const char T_2 * V_97 ,
T_4 V_98 ,
T_5 * V_99 )
{
int V_6 ;
if ( V_98 ) {
if ( ! V_100 ) {
T_4 V_79 ;
V_101 = 0 ;
for ( V_79 = 0 ; V_79 != V_98 ; V_79 ++ ) {
char V_102 ;
if ( F_43 ( V_102 , V_97 + V_79 ) )
return - V_82 ;
if ( V_102 == 'V' )
V_101 = 42 ;
}
}
V_6 = F_27 () ;
if ( V_6 )
return V_6 ;
}
return V_98 ;
}
static T_3 F_44 ( struct V_77 * V_77 ,
char T_2 * V_97 ,
T_4 V_103 ,
T_5 * V_99 )
{
int V_6 = 0 ;
T_6 V_104 ;
if ( V_103 <= 0 )
return 0 ;
F_45 ( & V_105 ) ;
if ( ! V_106 ) {
if ( V_77 -> V_107 & V_108 ) {
V_6 = - V_109 ;
goto V_14;
}
F_46 ( & V_104 , V_110 ) ;
F_47 ( & V_111 , & V_104 ) ;
while ( ! V_106 ) {
F_48 ( V_112 ) ;
F_49 ( & V_105 ) ;
F_50 () ;
F_45 ( & V_105 ) ;
}
F_51 ( & V_111 , & V_104 ) ;
if ( F_52 ( V_110 ) ) {
V_6 = - V_113 ;
goto V_14;
}
}
V_106 = 0 ;
V_14:
F_49 ( & V_105 ) ;
if ( V_6 == 0 ) {
if ( F_39 ( V_97 , & V_106 , 1 ) )
V_6 = - V_82 ;
else
V_6 = 1 ;
}
return V_6 ;
}
static int F_53 ( struct V_114 * V_115 , struct V_77 * V_116 )
{
switch ( F_54 ( V_115 ) ) {
case V_117 :
if ( F_55 ( 0 , & V_118 ) )
return - V_119 ;
V_67 = 1 ;
return F_56 ( V_115 , V_116 ) ;
default:
return ( - V_120 ) ;
}
}
static unsigned int F_57 ( struct V_77 * V_77 , T_7 * V_104 )
{
unsigned int V_121 = 0 ;
F_58 ( V_77 , & V_111 , V_104 ) ;
F_45 ( & V_105 ) ;
if ( V_106 )
V_121 |= ( V_122 | V_123 ) ;
F_49 ( & V_105 ) ;
return V_121 ;
}
static int F_59 ( int V_124 , struct V_77 * V_77 , int V_125 )
{
int V_126 ;
V_126 = F_60 ( V_124 , V_77 , V_125 , & V_127 ) ;
return ( V_126 ) ;
}
static int F_61 ( struct V_114 * V_115 , struct V_77 * V_116 )
{
if ( F_54 ( V_115 ) == V_117 ) {
if ( V_101 == 42 ) {
V_36 = V_37 ;
F_3 ( V_76 ) ;
} else {
F_22 (KERN_CRIT PFX
L_8 ) ;
F_27 () ;
}
F_62 ( 0 , & V_118 ) ;
}
V_101 = 0 ;
return 0 ;
}
static void F_63 ( struct V_22 * V_19 ,
void * V_128 )
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
F_64 ( V_19 ) ;
}
static void F_65 ( void * V_128 )
{
if ( V_39 != V_40 ) {
if ( V_129 == V_130 ) {
if ( F_66 ( & V_131 ) )
F_67 ( L_13 ) ;
} else if ( V_129 == V_132 ) {
F_45 ( & V_105 ) ;
V_106 = 1 ;
F_68 ( & V_111 ) ;
F_69 ( & V_127 , V_133 , V_134 ) ;
F_49 ( & V_105 ) ;
}
}
V_31 = 1 ;
}
static void F_11 ( int V_135 )
{
int V_6 = - V_119 ;
if ( V_9 )
goto V_14;
if ( ( V_16 >= 0 ) && ( V_16 != V_135 ) )
goto V_14;
V_17 = V_135 ;
V_6 = F_70 ( V_135 , & V_136 , NULL , & V_9 ) ;
if ( V_6 < 0 ) {
F_22 (KERN_CRIT PFX L_14 ) ;
goto V_14;
}
F_71 ( V_9 ,
& V_33 ,
& V_34 ) ;
V_6 = F_72 ( & V_137 ) ;
if ( V_6 < 0 ) {
F_73 ( V_9 ) ;
V_9 = NULL ;
F_22 (KERN_CRIT PFX L_15 ) ;
}
#ifdef F_74
if ( V_138 ) {
int V_139 = V_38 ;
int V_140 = V_41 ;
int V_141 = V_129 ;
V_36 = V_142 ;
V_129 = V_143 ;
V_38 = 99 ;
V_41 = 100 ;
V_144 = 1 ;
V_6 = F_3 ( V_56 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_16
L_17
L_18 , rv) ;
V_6 = 0 ;
goto V_145;
}
F_75 ( 1500 ) ;
if ( V_144 != 2 ) {
F_22 (KERN_WARNING PFX L_19
L_20
L_18 ) ;
}
V_145:
V_144 = 0 ;
V_129 = V_141 ;
V_38 = V_139 ;
V_41 = V_140 ;
}
#endif
V_14:
if ( ( V_146 ) && ( V_6 == 0 ) ) {
V_146 = 0 ;
V_36 = V_68 ;
F_3 ( V_56 ) ;
F_22 (KERN_INFO PFX L_21 ) ;
} else {
V_36 = V_37 ;
F_3 ( V_76 ) ;
}
}
static void F_10 ( int V_135 )
{
int V_6 ;
if ( ! V_9 )
goto V_14;
if ( V_17 != V_135 )
goto V_14;
F_76 ( & V_137 ) ;
while ( F_34 ( & V_20 ) )
F_77 ( 1 ) ;
V_6 = F_73 ( V_9 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_22 ,
rv) ;
}
V_9 = NULL ;
V_14:
return;
}
static int
F_78 ( unsigned int V_1 , struct V_147 * V_148 )
{
if ( V_144 ) {
V_144 = 2 ;
return V_149 ;
}
if ( V_36 == V_37 )
return V_150 ;
if ( V_39 != V_151 )
return V_150 ;
if ( V_129 == V_130 ) {
V_31 = 1 ;
if ( F_66 ( & V_131 ) )
F_67 ( V_152 L_23 ) ;
}
return V_149 ;
}
static int F_79 ( struct V_153 * V_154 ,
unsigned long V_155 ,
void * V_156 )
{
static int V_157 ;
if ( ( V_9 ) && ( ! V_157 ) ) {
V_157 = 1 ;
if ( V_155 == V_158 || V_155 == V_159 ) {
V_36 = V_37 ;
F_33 () ;
} else if ( V_36 != V_37 ) {
V_41 = 120 ;
V_38 = 0 ;
V_36 = V_142 ;
F_33 () ;
}
}
return V_160 ;
}
static int F_80 ( struct V_153 * V_154 ,
unsigned long V_161 ,
void * V_156 )
{
static int V_162 ;
if ( V_9 && ! V_162 &&
V_36 != V_37 ) {
V_162 = 1 ;
V_41 = 255 ;
V_38 = 0 ;
F_33 () ;
}
return V_160 ;
}
static void F_81 ( int V_163 , struct V_164 * V_164 )
{
F_11 ( V_163 ) ;
}
static void F_82 ( int V_163 )
{
F_10 ( V_163 ) ;
}
static int F_83 ( const char * V_165 , char * V_166 )
{
if ( V_166 )
strcpy ( V_166 , V_167 ) ;
if ( ! V_165 )
return 0 ;
if ( strcmp ( V_165 , L_24 ) == 0 )
V_68 = V_142 ;
else if ( strcmp ( V_165 , L_25 ) == 0 )
V_68 = V_37 ;
else if ( strcmp ( V_165 , L_26 ) == 0 )
V_68 = V_168 ;
else if ( strcmp ( V_165 , L_27 ) == 0 )
V_68 = V_169 ;
else
return - V_7 ;
strcpy ( V_167 , V_165 ) ;
return 0 ;
}
static int F_84 ( const char * V_165 , char * V_166 )
{
if ( V_166 )
strcpy ( V_166 , V_170 ) ;
if ( ! V_165 )
return 0 ;
if ( strcmp ( V_165 , L_28 ) == 0 )
V_39 = V_40 ;
else if ( strcmp ( V_165 , L_29 ) == 0 )
V_39 = V_171 ;
#ifdef F_74
else if ( strcmp ( V_165 , L_30 ) == 0 )
V_39 = V_151 ;
#endif
else if ( strcmp ( V_165 , L_31 ) == 0 )
V_39 = V_172 ;
else
return - V_7 ;
strcpy ( V_170 , V_165 ) ;
return 0 ;
}
static int F_85 ( const char * V_165 , char * V_166 )
{
if ( V_166 )
strcpy ( V_166 , V_173 ) ;
if ( ! V_165 )
return 0 ;
if ( strcmp ( V_165 , L_32 ) == 0 )
V_129 = V_143 ;
else if ( strcmp ( V_165 , L_33 ) == 0 )
V_129 = V_130 ;
else if ( strcmp ( V_165 , L_34 ) == 0 )
V_129 = V_132 ;
else
return - V_7 ;
strcpy ( V_173 , V_165 ) ;
return 0 ;
}
static void F_6 ( void )
{
#ifdef F_74
int V_174 = 0 ;
int V_6 ;
if ( V_39 == V_151 ) {
V_174 = 1 ;
if ( V_129 == V_132 ) {
F_22 (KERN_WARNING PFX L_35
L_36
L_37 ) ;
F_85 ( L_32 , NULL ) ;
V_174 = 0 ;
}
}
if ( V_174 && ! V_138 ) {
V_6 = F_86 ( V_175 , F_78 , 0 ,
L_38 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX
L_39 ) ;
return;
} else
V_138 = 1 ;
} else if ( ! V_174 && V_138 ) {
F_87 ( V_175 , L_38 ) ;
V_138 = 0 ;
}
#endif
}
static int T_8 F_88 ( void )
{
int V_6 ;
if ( F_83 ( V_167 , NULL ) ) {
F_83 ( L_24 , NULL ) ;
F_22 (KERN_INFO PFX L_40
L_41 , action) ;
}
if ( F_84 ( V_170 , NULL ) ) {
F_84 ( L_28 , NULL ) ;
F_22 (KERN_INFO PFX L_42
L_43 , preaction) ;
}
if ( F_85 ( V_173 , NULL ) ) {
F_85 ( L_32 , NULL ) ;
F_22 (KERN_INFO PFX L_44
L_43 , preop) ;
}
F_6 () ;
F_89 ( & V_176 ) ;
F_90 ( & V_177 ,
& V_178 ) ;
V_6 = F_91 ( & V_179 ) ;
if ( V_6 ) {
#ifdef F_74
if ( V_138 )
F_87 ( V_175 , L_38 ) ;
#endif
F_92 ( & V_177 ,
& V_178 ) ;
F_93 ( & V_176 ) ;
F_22 (KERN_WARNING PFX L_45 ) ;
return V_6 ;
}
F_22 (KERN_INFO PFX L_46 ) ;
return 0 ;
}
static void T_9 F_94 ( void )
{
F_95 ( & V_179 ) ;
F_10 ( V_17 ) ;
#ifdef F_74
if ( V_138 )
F_87 ( V_175 , L_38 ) ;
#endif
F_92 ( & V_177 ,
& V_178 ) ;
F_93 ( & V_176 ) ;
}
