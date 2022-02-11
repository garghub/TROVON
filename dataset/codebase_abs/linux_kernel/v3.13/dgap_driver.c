int F_1 ( void )
{
int V_1 = 0 ;
F_2 ( ( L_1 , V_2 , V_3 ) ) ;
V_1 = F_3 () ;
if ( V_1 < 0 ) {
return ( V_1 ) ;
}
V_1 = F_4 () ;
if ( V_1 < 0 ) {
if ( V_4 )
F_5 ( & V_5 ) ;
else
F_6 ( L_2 ) ;
F_7 () ;
}
else {
F_8 ( & V_5 ) ;
}
F_9 ( ( L_3 , V_1 ) ) ;
return ( V_1 ) ;
}
static int F_3 ( void )
{
int V_1 = 0 ;
unsigned long V_6 ;
if ( V_7 == FALSE ) {
V_7 = TRUE ;
F_10 () ;
V_4 = 0 ;
F_2 ( ( L_4 ) ) ;
if ( ! V_8 ) {
V_1 = F_11 ( V_9 , L_5 , & V_10 ) ;
if ( V_1 < 0 ) {
F_2 ( ( L_6 , V_1 ) ) ;
return ( V_1 ) ;
}
V_11 = F_12 ( V_12 , L_7 ) ;
F_13 ( V_11 , NULL ,
F_14 ( V_9 , 0 ) ,
NULL , L_7 ) ;
F_13 ( V_11 , NULL ,
F_14 ( V_9 , 1 ) ,
NULL , L_8 ) ;
V_8 = TRUE ;
}
V_1 = F_15 () ;
if ( V_1 < 0 ) {
F_2 ( ( L_9 , V_1 ) ) ;
return ( V_1 ) ;
}
F_16 ( V_13 , V_6 ) ;
F_17 ( & V_14 ) ;
V_14 . V_15 = V_16 ;
V_14 . V_17 = 0 ;
V_18 = V_19 + F_18 ( V_20 ) ;
V_14 . V_21 = V_18 ;
F_19 ( V_13 , V_6 ) ;
F_20 ( & V_14 ) ;
V_22 = V_23 ;
}
return ( V_1 ) ;
}
static int F_4 ( void )
{
return F_21 ( & V_5 ) ;
}
static int F_22 ( struct V_24 * V_25 , const struct V_26 * V_27 )
{
int V_1 ;
V_1 = F_23 ( V_25 ) ;
if ( V_1 < 0 ) {
V_1 = - V_28 ;
} else {
V_1 = F_24 ( V_25 , V_27 -> V_29 ) ;
if ( V_1 == 0 ) {
V_4 ++ ;
F_9 ( ( L_10 , V_4 ) ) ;
}
}
return V_1 ;
}
static int F_24 ( struct V_24 * V_25 , int V_30 )
{
return F_25 ( V_25 , V_30 ) ;
}
static void F_26 ( struct V_24 * V_31 )
{
}
void F_7 ( void )
{
int V_32 ;
T_1 V_33 ;
F_16 ( V_13 , V_33 ) ;
V_34 = 1 ;
F_19 ( V_13 , V_33 ) ;
F_27 ( & V_14 ) ;
F_28 ( & V_5 ) ;
if ( V_8 ) {
F_29 ( V_11 , F_14 ( V_9 , 0 ) ) ;
F_29 ( V_11 , F_14 ( V_9 , 1 ) ) ;
F_30 ( V_11 ) ;
F_31 ( V_9 , L_5 ) ;
}
F_32 ( V_35 ) ;
for ( V_32 = 0 ; V_32 < V_4 ; ++ V_32 ) {
F_33 ( V_36 [ V_32 ] ) ;
F_34 ( V_36 [ V_32 ] ) ;
F_35 ( V_36 [ V_32 ] ) ;
}
F_36 () ;
#if F_37 ( V_37 )
F_38 () ;
#endif
if ( V_4 )
F_5 ( & V_5 ) ;
}
static void F_35 ( struct V_38 * V_39 )
{
int V_32 = 0 ;
if( ! V_39 || V_39 -> V_40 != V_41 )
return;
if ( V_39 -> V_42 && V_39 -> V_43 )
F_39 ( V_39 -> V_43 , V_39 ) ;
F_40 ( & V_39 -> V_44 ) ;
if ( V_39 -> V_45 ) {
F_41 ( V_39 -> V_46 + 0x200000 , 0x200000 ) ;
F_42 ( V_39 -> V_45 ) ;
V_39 -> V_45 = NULL ;
}
if ( V_39 -> V_47 ) {
F_41 ( V_39 -> V_46 , 0x200000 ) ;
F_42 ( V_39 -> V_47 ) ;
V_39 -> V_47 = NULL ;
}
if ( V_39 -> V_48 ) {
unsigned long V_6 ;
F_16 ( V_49 , V_6 ) ;
V_39 -> V_50 = NULL ;
F_6 ( L_11 , V_39 -> V_48 ) ;
F_32 ( V_39 -> V_48 ) ;
V_39 -> V_48 = NULL ;
F_19 ( V_49 , V_6 ) ;
}
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
if ( V_39 -> V_52 [ V_32 ] ) {
F_32 ( V_39 -> V_52 [ V_32 ] ) ;
V_39 -> V_52 [ V_32 ] = NULL ;
}
}
F_32 ( V_39 -> V_53 ) ;
F_32 ( V_39 -> V_54 ) ;
V_36 [ V_39 -> V_55 ] = NULL ;
F_32 ( V_39 ) ;
}
static int F_25 ( struct V_24 * V_25 , int V_56 )
{
struct V_38 * V_39 ;
unsigned int V_57 ;
int V_32 = 0 ;
unsigned long V_6 ;
V_39 = V_36 [ V_4 ] =
(struct V_38 * ) F_43 ( sizeof( struct V_38 ) , V_58 ) ;
if ( ! V_39 ) {
F_2 ( ( L_12 ) ) ;
return ( - V_59 ) ;
}
V_39 -> V_50 = V_39 -> V_48 =
( char * ) F_43 ( sizeof( char ) * 8192 , V_58 ) ;
if( ! V_39 -> V_50 ) {
F_32 ( V_39 ) ;
F_2 ( ( L_13 ) ) ;
return ( - V_59 ) ;
}
V_39 -> V_40 = V_41 ;
V_39 -> V_55 = V_4 ;
V_39 -> V_60 = 0 ;
V_39 -> V_61 = V_62 [ V_56 ] . V_61 ;
V_39 -> V_63 = V_62 [ V_56 ] . V_63 ;
V_39 -> V_25 = V_25 ;
V_39 -> V_64 = V_25 -> V_65 -> V_66 ;
V_39 -> V_67 = F_44 ( V_25 -> V_68 ) ;
V_39 -> V_69 = V_70 [ V_56 ] . V_69 ;
V_39 -> V_71 = V_70 [ V_56 ] . V_71 ;
V_39 -> type = V_70 [ V_56 ] . V_72 ;
V_39 -> V_73 = V_70 [ V_56 ] . V_73 ;
V_39 -> V_74 = V_75 ;
F_45 ( & V_39 -> V_76 ) ;
F_46 ( V_39 -> V_77 ) ;
V_39 -> V_78 = V_79 ;
V_39 -> V_80 = 0 ;
V_39 -> V_81 = FALSE ;
V_39 -> V_82 = 0 ;
V_39 -> V_83 = 0 ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_39 -> V_52 [ V_32 ] = NULL ;
}
F_47 ( V_25 , V_84 , & V_39 -> V_85 ) ;
F_47 ( V_25 , V_86 , & V_39 -> V_87 ) ;
F_48 ( V_25 , V_88 , & V_39 -> V_89 ) ;
V_57 = V_25 -> V_43 ;
V_39 -> V_43 = V_57 ;
if ( V_39 -> V_63 == V_90 || V_39 -> V_63 == V_91 ) {
V_39 -> V_46 = F_49 ( V_25 , 2 ) ;
V_39 -> V_92 = F_50 ( V_25 , 2 ) ;
}
else {
V_39 -> V_46 = F_49 ( V_25 , 0 ) ;
V_39 -> V_92 = F_50 ( V_25 , 0 ) ;
}
if ( ! V_39 -> V_46 ) {
F_2 ( ( L_14 ) ) ;
return - V_93 ;
}
if ( V_39 -> V_46 & 1 )
V_39 -> V_46 &= ~ 3 ;
else
V_39 -> V_46 &= ~ 15 ;
V_39 -> V_94 = V_39 -> V_46 + V_95 ;
V_39 -> V_96 = V_39 -> V_94 + V_97 ;
if ( V_39 -> V_63 != V_90 && V_39 -> V_63 != V_91 ) {
unsigned short V_98 ;
F_51 ( V_25 , 0x40 , 0 ) ;
F_51 ( V_25 , 0x46 , 0 ) ;
F_51 ( V_25 , 0x42 , 1 ) ;
F_47 ( V_25 , V_99 , & V_98 ) ;
V_98 |= ( V_100 | V_101 ) ;
F_52 ( V_25 , V_99 , V_98 ) ;
}
F_53 ( & V_39 -> V_44 , V_102 , ( unsigned long ) V_39 ) ;
F_54 ( V_39 , V_103 L_15 ,
V_4 , V_39 -> V_69 , V_39 -> V_89 , V_39 -> V_43 ) ;
F_9 ( ( L_16 , V_32 ) ) ;
F_16 ( V_49 , V_6 ) ;
V_39 -> V_50 = NULL ;
F_6 ( L_11 , V_39 -> V_48 ) ;
F_32 ( V_39 -> V_48 ) ;
V_39 -> V_48 = NULL ;
F_19 ( V_49 , V_6 ) ;
V_32 = F_55 ( V_39 ) ;
if ( V_32 )
V_39 -> V_78 = V_104 ;
else
V_39 -> V_78 = V_105 ;
return ( 0 ) ;
}
int F_56 ( struct V_38 * V_39 ) {
int V_1 ;
F_9 ( ( L_17 ) ) ;
if ( ! V_39 || V_39 -> V_40 != V_41 )
return ( - V_93 ) ;
F_9 ( ( L_18 ) ) ;
V_39 -> V_106 = F_57 ( V_39 ) ;
if ( V_39 -> V_106 && V_39 -> V_43 ) {
V_1 = F_58 ( V_39 -> V_43 , V_107 , V_108 , L_19 , V_39 ) ;
if ( V_1 ) {
F_54 ( V_39 , V_103 L_20 ,
V_39 -> V_43 ) ;
V_39 -> V_42 = 0 ;
}
else
V_39 -> V_42 = 1 ;
} else {
V_39 -> V_42 = 0 ;
}
return ( 0 ) ;
}
static int F_55 ( struct V_38 * V_39 )
{
if ( ! V_39 || V_39 -> V_40 != V_41 )
return - V_109 ;
if ( ! F_59 ( V_39 -> V_46 , 0x200000 , L_5 ) ) {
F_2 ( ( L_21 , V_39 -> V_46 ) ) ;
return - V_59 ;
}
if ( ! F_59 ( V_39 -> V_46 + V_95 , 0x200000 , L_5 ) ) {
F_2 ( ( L_22 ,
V_39 -> V_46 + V_95 ) ) ;
F_41 ( V_39 -> V_46 , 0x200000 ) ;
return - V_59 ;
}
V_39 -> V_47 = F_60 ( V_39 -> V_46 , 0x200000 ) ;
if ( ! V_39 -> V_47 ) {
F_2 ( ( L_23 , V_39 -> V_46 ) ) ;
F_41 ( V_39 -> V_46 , 0x200000 ) ;
F_41 ( V_39 -> V_46 + V_95 , 0x200000 ) ;
return - V_59 ;
}
V_39 -> V_45 = F_60 ( ( V_39 -> V_46 + V_95 ) , 0x200000 ) ;
if ( ! V_39 -> V_45 ) {
F_41 ( V_39 -> V_46 , 0x200000 ) ;
F_41 ( V_39 -> V_46 + V_95 , 0x200000 ) ;
F_42 ( V_39 -> V_47 ) ;
F_2 ( ( L_24 ,
V_39 -> V_46 + V_95 ) ) ;
return - V_59 ;
}
F_9 ( ( L_25 ,
V_39 -> V_45 , V_39 -> V_47 ) ) ;
return 0 ;
}
static void V_16 ( T_1 V_110 )
{
int V_32 ;
struct V_38 * V_39 ;
unsigned long V_33 ;
unsigned long V_111 ;
T_1 V_112 ;
V_113 ++ ;
if ( V_22 == V_23 ) {
F_16 ( V_114 , V_111 ) ;
if ( V_115 != 1 ) {
V_115 = 1 ;
F_61 ( & V_116 ) ;
}
F_19 ( V_114 , V_111 ) ;
goto V_117;
}
else if ( V_22 != V_118 ) {
goto V_117;
}
if ( ( V_4 == 1 ) || ( F_62 () <= 1 ) ) {
for ( V_32 = 0 ; V_32 < V_4 ; V_32 ++ ) {
V_39 = V_36 [ V_32 ] ;
if ( V_39 -> V_78 == V_104 ) {
continue;
}
if ( ! V_39 -> V_119 ) {
V_102 ( ( unsigned long ) V_39 ) ;
}
}
}
else {
for ( V_32 = 0 ; V_32 < V_4 ; V_32 ++ ) {
V_39 = V_36 [ V_32 ] ;
if ( ! F_63 ( & V_39 -> V_77 ) ) {
continue;
}
if ( V_39 -> V_78 == V_104 ) {
F_64 ( & V_39 -> V_77 ) ;
continue;
}
if ( ! V_39 -> V_119 ) {
F_65 ( & V_39 -> V_44 ) ;
}
F_64 ( & V_39 -> V_77 ) ;
}
}
V_117:
F_16 ( V_13 , V_33 ) ;
V_18 += F_18 ( V_20 ) ;
V_112 = V_18 - V_19 ;
if ( ( T_1 ) V_112 >= 2 * V_20 ) {
V_18 = V_19 + F_18 ( V_20 ) ;
}
V_14 . V_15 = V_16 ;
V_14 . V_17 = 0 ;
V_14 . V_21 = V_18 ;
F_19 ( V_13 , V_33 ) ;
if ( ! V_34 )
F_20 ( & V_14 ) ;
}
static T_2 V_107 ( int V_43 , void * V_120 )
{
struct V_38 * V_39 = (struct V_38 * ) V_120 ;
if ( ! V_39 ) {
F_2 ( ( L_26 , V_43 ) ) ;
return V_121 ;
}
if ( V_39 -> V_40 != V_41 ) {
F_2 ( ( L_27 , V_43 ) ) ;
return V_121 ;
}
V_39 -> V_122 ++ ;
F_65 ( & V_39 -> V_44 ) ;
return V_123 ;
}
static void F_10 ( void )
{
int V_32 = 0 ;
V_124 = V_125 ;
V_126 = V_127 ;
V_128 = V_129 ;
for ( V_32 = 0 ; V_32 < V_130 ; V_32 ++ ) {
V_36 [ V_32 ] = NULL ;
}
F_17 ( & V_14 ) ;
F_45 ( & V_116 ) ;
V_115 = 0 ;
}
void * F_43 ( T_3 V_131 , int V_132 )
{
void * V_133 = F_66 ( V_131 , V_132 ) ;
if( V_133 )
memset ( V_133 , 0 , V_131 ) ;
return ( V_133 ) ;
}
static void F_54 ( struct V_38 * V_39 , const char * V_134 , ... ) {
T_4 V_135 ;
char V_136 [ 1024 ] ;
int V_32 ;
unsigned long V_6 ;
T_3 V_137 ;
F_16 ( V_49 , V_6 ) ;
va_start ( V_135 , V_134 ) ;
V_32 = vsnprintf ( V_136 , sizeof( V_136 ) , V_134 , V_135 ) ;
va_end ( V_135 ) ;
F_67 ( ( V_136 ) ) ;
if ( ! V_39 || ! V_39 -> V_50 ) {
F_6 ( L_11 , V_136 ) ;
F_19 ( V_49 , V_6 ) ;
return;
}
V_137 = strlen ( V_136 ) + 1 ;
if ( V_39 -> V_50 - V_39 -> V_48 < V_137 )
V_137 = V_39 -> V_50 - V_39 -> V_48 ;
memcpy ( V_39 -> V_50 , V_136 , V_137 ) ;
V_39 -> V_50 += V_137 ;
F_19 ( V_49 , V_6 ) ;
}
int F_68 ( T_1 V_138 )
{
V_139 -> V_78 = V_140 ;
F_69 ( ( V_138 * V_141 ) / 1000 ) ;
return ( F_70 ( V_139 ) ) ;
}
char * F_71 ( int V_98 )
{
switch( V_98 ) {
case V_142 : return ( L_28 ) ;
case V_143 : return ( L_29 ) ;
case V_144 : return ( L_30 ) ;
case V_145 : return ( L_31 ) ;
case V_146 : return ( L_32 ) ;
case V_147 : return ( L_33 ) ;
case V_148 : return ( L_34 ) ;
case V_149 : return ( L_35 ) ;
case V_150 : return ( L_36 ) ;
case V_151 : return ( L_37 ) ;
case V_152 : return ( L_38 ) ;
case V_153 : return ( L_39 ) ;
case V_154 : return ( L_40 ) ;
case V_155 : return ( L_41 ) ;
case V_156 : return ( L_42 ) ;
case V_157 : return ( L_43 ) ;
case V_158 : return ( L_44 ) ;
case V_159 : return ( L_45 ) ;
case V_160 : return ( L_46 ) ;
case V_161 : return ( L_47 ) ;
case V_162 : return ( L_48 ) ;
case V_163 : return ( L_49 ) ;
case V_164 : return ( L_50 ) ;
case V_165 : return ( L_51 ) ;
case V_166 : return ( L_52 ) ;
case V_167 : return ( L_53 ) ;
case V_168 : return ( L_54 ) ;
case V_169 : return ( L_55 ) ;
case V_170 : return ( L_56 ) ;
case V_171 : return ( L_57 ) ;
case V_172 : return ( L_58 ) ;
case V_173 : return ( L_59 ) ;
case V_174 : return ( L_60 ) ;
case V_175 : return ( L_61 ) ;
case V_176 : return ( L_62 ) ;
case V_177 : return ( L_63 ) ;
default: return ( L_64 ) ;
}
}
