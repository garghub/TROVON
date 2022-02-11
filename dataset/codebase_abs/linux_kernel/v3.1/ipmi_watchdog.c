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
if ( V_65 )
return 0 ;
if ( V_66 ) {
V_66 = 0 ;
V_36 = V_67 ;
return F_3 ( V_56 ) ;
} else if ( V_31 ) {
return F_3 ( V_10 ) ;
}
F_23 ( & V_68 ) ;
F_24 ( & V_63 , 2 ) ;
if ( V_36 == V_37 ) {
F_25 ( & V_68 ) ;
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
& V_69 ,
& V_70 ,
1 ) ;
if ( V_6 ) {
F_25 ( & V_68 ) ;
F_22 (KERN_WARNING PFX L_3 ,
rv) ;
return V_6 ;
}
F_26 ( & V_64 ) ;
if ( V_70 . V_19 . V_27 [ 0 ] != 0 ) {
V_6 = - V_7 ;
}
F_25 ( & V_68 ) ;
return V_6 ;
}
static int F_38 ( struct V_71 * V_71 ,
unsigned int V_48 , unsigned long V_8 )
{
void T_2 * V_72 = ( void T_2 * ) V_8 ;
int V_73 ;
int V_1 ;
switch ( V_48 ) {
case V_74 :
V_73 = F_39 ( V_72 , & V_75 , sizeof( V_75 ) ) ;
return V_73 ? - V_76 : 0 ;
case V_77 :
V_73 = F_40 ( & V_1 , V_72 , sizeof( int ) ) ;
if ( V_73 )
return - V_76 ;
V_41 = V_1 ;
return F_3 ( V_10 ) ;
case V_78 :
V_73 = F_39 ( V_72 , & V_41 , sizeof( V_41 ) ) ;
if ( V_73 )
return - V_76 ;
return 0 ;
case V_79 :
case V_80 :
V_73 = F_40 ( & V_1 , V_72 , sizeof( int ) ) ;
if ( V_73 )
return - V_76 ;
V_38 = V_1 ;
return F_3 ( V_10 ) ;
case V_81 :
case V_82 :
V_73 = F_39 ( V_72 , & V_38 , sizeof( V_38 ) ) ;
if ( V_73 )
return - V_76 ;
return 0 ;
case V_83 :
return F_27 () ;
case V_84 :
V_73 = F_40 ( & V_1 , V_72 , sizeof( int ) ) ;
if ( V_73 )
return - V_76 ;
if ( V_1 & V_85 ) {
V_36 = V_37 ;
F_3 ( V_86 ) ;
V_66 = 0 ;
}
if ( V_1 & V_87 ) {
V_36 = V_67 ;
F_3 ( V_56 ) ;
}
return 0 ;
case V_88 :
V_1 = 0 ;
V_73 = F_39 ( V_72 , & V_1 , sizeof( V_1 ) ) ;
if ( V_73 )
return - V_76 ;
return 0 ;
default:
return - V_89 ;
}
}
static long F_41 ( struct V_71 * V_71 ,
unsigned int V_48 ,
unsigned long V_8 )
{
int V_90 ;
F_23 ( & V_91 ) ;
V_90 = F_38 ( V_71 , V_48 , V_8 ) ;
F_25 ( & V_91 ) ;
return V_90 ;
}
static T_3 F_42 ( struct V_71 * V_71 ,
const char T_2 * V_92 ,
T_4 V_93 ,
T_5 * V_94 )
{
int V_6 ;
if ( V_93 ) {
if ( ! V_95 ) {
T_4 V_73 ;
V_96 = 0 ;
for ( V_73 = 0 ; V_73 != V_93 ; V_73 ++ ) {
char V_97 ;
if ( F_43 ( V_97 , V_92 + V_73 ) )
return - V_76 ;
if ( V_97 == 'V' )
V_96 = 42 ;
}
}
V_6 = F_27 () ;
if ( V_6 )
return V_6 ;
}
return V_93 ;
}
static T_3 F_44 ( struct V_71 * V_71 ,
char T_2 * V_92 ,
T_4 V_98 ,
T_5 * V_94 )
{
int V_6 = 0 ;
T_6 V_99 ;
if ( V_98 <= 0 )
return 0 ;
F_45 ( & V_100 ) ;
if ( ! V_101 ) {
if ( V_71 -> V_102 & V_103 ) {
V_6 = - V_104 ;
goto V_14;
}
F_46 ( & V_99 , V_105 ) ;
F_47 ( & V_106 , & V_99 ) ;
while ( ! V_101 ) {
F_48 ( V_107 ) ;
F_49 ( & V_100 ) ;
F_50 () ;
F_45 ( & V_100 ) ;
}
F_51 ( & V_106 , & V_99 ) ;
if ( F_52 ( V_105 ) ) {
V_6 = - V_108 ;
goto V_14;
}
}
V_101 = 0 ;
V_14:
F_49 ( & V_100 ) ;
if ( V_6 == 0 ) {
if ( F_39 ( V_92 , & V_101 , 1 ) )
V_6 = - V_76 ;
else
V_6 = 1 ;
}
return V_6 ;
}
static int F_53 ( struct V_109 * V_110 , struct V_71 * V_111 )
{
switch ( F_54 ( V_110 ) ) {
case V_112 :
if ( F_55 ( 0 , & V_113 ) )
return - V_114 ;
V_66 = 1 ;
return F_56 ( V_110 , V_111 ) ;
default:
return ( - V_115 ) ;
}
}
static unsigned int F_57 ( struct V_71 * V_71 , T_7 * V_99 )
{
unsigned int V_116 = 0 ;
F_58 ( V_71 , & V_106 , V_99 ) ;
F_45 ( & V_100 ) ;
if ( V_101 )
V_116 |= ( V_117 | V_118 ) ;
F_49 ( & V_100 ) ;
return V_116 ;
}
static int F_59 ( int V_119 , struct V_71 * V_71 , int V_120 )
{
int V_121 ;
V_121 = F_60 ( V_119 , V_71 , V_120 , & V_122 ) ;
return ( V_121 ) ;
}
static int F_61 ( struct V_109 * V_110 , struct V_71 * V_111 )
{
if ( F_54 ( V_110 ) == V_112 ) {
if ( V_96 == 42 ) {
V_36 = V_37 ;
F_3 ( V_86 ) ;
} else {
F_22 (KERN_CRIT PFX
L_4 ) ;
F_27 () ;
}
F_62 ( 0 , & V_113 ) ;
}
V_96 = 0 ;
return 0 ;
}
static void F_63 ( struct V_22 * V_19 ,
void * V_123 )
{
if ( V_19 -> V_19 . V_27 [ 0 ] != 0 ) {
F_22 (KERN_ERR PFX L_5 ,
msg->msg.data[0],
msg->msg.cmd) ;
}
F_64 ( V_19 ) ;
}
static void F_65 ( void * V_123 )
{
if ( V_39 != V_40 ) {
if ( V_124 == V_125 ) {
if ( F_66 ( & V_126 ) )
F_67 ( L_6 ) ;
} else if ( V_124 == V_127 ) {
F_45 ( & V_100 ) ;
V_101 = 1 ;
F_68 ( & V_106 ) ;
F_69 ( & V_122 , V_128 , V_129 ) ;
F_49 ( & V_100 ) ;
}
}
V_31 = 1 ;
}
static void F_11 ( int V_130 )
{
int V_6 = - V_114 ;
if ( V_9 )
goto V_14;
if ( ( V_16 >= 0 ) && ( V_16 != V_130 ) )
goto V_14;
V_17 = V_130 ;
V_6 = F_70 ( V_130 , & V_131 , NULL , & V_9 ) ;
if ( V_6 < 0 ) {
F_22 (KERN_CRIT PFX L_7 ) ;
goto V_14;
}
F_71 ( V_9 ,
& V_33 ,
& V_34 ) ;
V_6 = F_72 ( & V_132 ) ;
if ( V_6 < 0 ) {
F_73 ( V_9 ) ;
V_9 = NULL ;
F_22 (KERN_CRIT PFX L_8 ) ;
}
#ifdef F_74
if ( V_133 ) {
int V_134 = V_38 ;
int V_135 = V_41 ;
int V_136 = V_124 ;
V_36 = V_137 ;
V_124 = V_138 ;
V_38 = 99 ;
V_41 = 100 ;
V_139 = 1 ;
V_6 = F_3 ( V_56 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_9
L_10
L_11 , rv) ;
V_6 = 0 ;
goto V_140;
}
F_75 ( 1500 ) ;
if ( V_139 != 2 ) {
F_22 (KERN_WARNING PFX L_12
L_13
L_11 ) ;
}
V_140:
V_139 = 0 ;
V_124 = V_136 ;
V_38 = V_134 ;
V_41 = V_135 ;
}
#endif
V_14:
if ( ( V_141 ) && ( V_6 == 0 ) ) {
V_141 = 0 ;
V_36 = V_67 ;
F_3 ( V_56 ) ;
F_22 (KERN_INFO PFX L_14 ) ;
} else {
V_36 = V_37 ;
F_3 ( V_86 ) ;
}
}
static void F_10 ( int V_130 )
{
int V_6 ;
if ( ! V_9 )
goto V_14;
if ( V_17 != V_130 )
goto V_14;
F_76 ( & V_132 ) ;
while ( F_34 ( & V_20 ) )
F_77 ( 1 ) ;
V_6 = F_73 ( V_9 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX L_15 ,
rv) ;
}
V_9 = NULL ;
V_14:
return;
}
static int
F_78 ( struct V_142 * V_143 , unsigned long V_1 , void * V_27 )
{
struct V_144 * args = V_27 ;
if ( V_1 != V_145 )
return V_146 ;
if ( args -> V_147 & 0xc0 )
return V_146 ;
if ( V_139 ) {
V_139 = 2 ;
return V_148 ;
}
if ( V_36 == V_37 )
return V_146 ;
if ( V_39 != V_149 )
return V_146 ;
if ( V_124 == V_125 ) {
V_31 = 1 ;
if ( F_66 ( & V_126 ) )
F_67 ( V_150 L_16 ) ;
}
return V_148 ;
}
static int F_79 ( struct V_142 * V_151 ,
unsigned long V_152 ,
void * V_153 )
{
static int V_154 ;
if ( ( V_9 ) && ( ! V_154 ) ) {
V_154 = 1 ;
if ( V_152 == V_155 || V_152 == V_156 ) {
V_36 = V_37 ;
F_33 () ;
} else if ( V_36 != V_37 ) {
V_41 = 120 ;
V_38 = 0 ;
V_36 = V_137 ;
F_33 () ;
}
}
return V_146 ;
}
static int F_80 ( struct V_142 * V_151 ,
unsigned long V_157 ,
void * V_153 )
{
static int V_158 ;
if ( V_9 && ! V_158 &&
V_36 != V_37 ) {
V_158 = 1 ;
V_41 = 255 ;
V_38 = 0 ;
F_33 () ;
}
return V_146 ;
}
static void F_81 ( int V_159 , struct V_160 * V_160 )
{
F_11 ( V_159 ) ;
}
static void F_82 ( int V_159 )
{
F_10 ( V_159 ) ;
}
static int F_83 ( const char * V_161 , char * V_162 )
{
if ( V_162 )
strcpy ( V_162 , V_163 ) ;
if ( ! V_161 )
return 0 ;
if ( strcmp ( V_161 , L_17 ) == 0 )
V_67 = V_137 ;
else if ( strcmp ( V_161 , L_18 ) == 0 )
V_67 = V_37 ;
else if ( strcmp ( V_161 , L_19 ) == 0 )
V_67 = V_164 ;
else if ( strcmp ( V_161 , L_20 ) == 0 )
V_67 = V_165 ;
else
return - V_7 ;
strcpy ( V_163 , V_161 ) ;
return 0 ;
}
static int F_84 ( const char * V_161 , char * V_162 )
{
if ( V_162 )
strcpy ( V_162 , V_166 ) ;
if ( ! V_161 )
return 0 ;
if ( strcmp ( V_161 , L_21 ) == 0 )
V_39 = V_40 ;
else if ( strcmp ( V_161 , L_22 ) == 0 )
V_39 = V_167 ;
#ifdef F_74
else if ( strcmp ( V_161 , L_23 ) == 0 )
V_39 = V_149 ;
#endif
else if ( strcmp ( V_161 , L_24 ) == 0 )
V_39 = V_168 ;
else
return - V_7 ;
strcpy ( V_166 , V_161 ) ;
return 0 ;
}
static int F_85 ( const char * V_161 , char * V_162 )
{
if ( V_162 )
strcpy ( V_162 , V_169 ) ;
if ( ! V_161 )
return 0 ;
if ( strcmp ( V_161 , L_25 ) == 0 )
V_124 = V_138 ;
else if ( strcmp ( V_161 , L_26 ) == 0 )
V_124 = V_125 ;
else if ( strcmp ( V_161 , L_27 ) == 0 )
V_124 = V_127 ;
else
return - V_7 ;
strcpy ( V_169 , V_161 ) ;
return 0 ;
}
static void F_6 ( void )
{
#ifdef F_74
int V_170 = 0 ;
int V_6 ;
if ( V_39 == V_149 ) {
V_170 = 1 ;
if ( V_124 == V_127 ) {
F_22 (KERN_WARNING PFX L_28
L_29
L_30 ) ;
F_85 ( L_25 , NULL ) ;
V_170 = 0 ;
}
}
if ( V_170 && ! V_133 ) {
V_6 = F_86 ( & V_171 ) ;
if ( V_6 ) {
F_22 (KERN_WARNING PFX
L_31 ) ;
return;
} else
V_133 = 1 ;
} else if ( ! V_170 && V_133 ) {
F_87 ( & V_171 ) ;
V_133 = 0 ;
}
#endif
}
static int T_8 F_88 ( void )
{
int V_6 ;
if ( F_83 ( V_163 , NULL ) ) {
F_83 ( L_17 , NULL ) ;
F_22 (KERN_INFO PFX L_32
L_33 , action) ;
}
if ( F_84 ( V_166 , NULL ) ) {
F_84 ( L_21 , NULL ) ;
F_22 (KERN_INFO PFX L_34
L_35 , preaction) ;
}
if ( F_85 ( V_169 , NULL ) ) {
F_85 ( L_25 , NULL ) ;
F_22 (KERN_INFO PFX L_36
L_35 , preop) ;
}
F_6 () ;
F_89 ( & V_172 ) ;
F_90 ( & V_173 ,
& V_174 ) ;
V_6 = F_91 ( & V_175 ) ;
if ( V_6 ) {
#ifdef F_74
if ( V_133 )
F_87 ( & V_171 ) ;
#endif
F_92 ( & V_173 ,
& V_174 ) ;
F_93 ( & V_172 ) ;
F_22 (KERN_WARNING PFX L_37 ) ;
return V_6 ;
}
F_22 (KERN_INFO PFX L_38 ) ;
return 0 ;
}
static void T_9 F_94 ( void )
{
F_95 ( & V_175 ) ;
F_10 ( V_17 ) ;
#ifdef F_74
if ( V_133 )
F_87 ( & V_171 ) ;
#endif
F_92 ( & V_173 ,
& V_174 ) ;
F_93 ( & V_172 ) ;
}
