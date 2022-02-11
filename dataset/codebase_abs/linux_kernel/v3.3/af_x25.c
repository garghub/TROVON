int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned char V_6 ;
int V_7 ;
int V_8 ;
if ( ! F_2 ( V_2 , 1 ) ) {
V_8 = 0 ;
goto V_9;
}
V_6 = * V_2 -> V_10 ;
V_7 = 1 + ( V_6 >> 4 ) + ( V_6 & 0x0f ) ;
if ( ! F_2 ( V_2 , V_7 ) ) {
V_8 = - 1 ;
goto V_9;
}
return F_3 ( V_2 -> V_10 , V_4 , V_5 ) ;
V_9:
* V_4 -> V_11 = 0 ;
* V_5 -> V_11 = 0 ;
return V_8 ;
}
int F_3 ( unsigned char * V_12 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned int V_13 , V_14 ;
char * V_15 , * V_16 ;
unsigned int V_17 ;
V_13 = ( * V_12 >> 0 ) & 0x0F ;
V_14 = ( * V_12 >> 4 ) & 0x0F ;
V_15 = V_4 -> V_11 ;
V_16 = V_5 -> V_11 ;
V_12 ++ ;
for ( V_17 = 0 ; V_17 < ( V_13 + V_14 ) ; V_17 ++ ) {
if ( V_17 < V_13 ) {
if ( V_17 % 2 != 0 ) {
* V_15 ++ = ( ( * V_12 >> 0 ) & 0x0F ) + '0' ;
V_12 ++ ;
} else {
* V_15 ++ = ( ( * V_12 >> 4 ) & 0x0F ) + '0' ;
}
} else {
if ( V_17 % 2 != 0 ) {
* V_16 ++ = ( ( * V_12 >> 0 ) & 0x0F ) + '0' ;
V_12 ++ ;
} else {
* V_16 ++ = ( ( * V_12 >> 4 ) & 0x0F ) + '0' ;
}
}
}
* V_15 = * V_16 = '\0' ;
return 1 + ( V_13 + V_14 + 1 ) / 2 ;
}
int F_4 ( unsigned char * V_12 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned int V_13 , V_14 ;
char * V_15 , * V_16 ;
int V_17 ;
V_15 = V_4 -> V_11 ;
V_16 = V_5 -> V_11 ;
V_13 = strlen ( V_15 ) ;
V_14 = strlen ( V_16 ) ;
* V_12 ++ = ( V_14 << 4 ) | ( V_13 << 0 ) ;
for ( V_17 = 0 ; V_17 < ( V_13 + V_14 ) ; V_17 ++ ) {
if ( V_17 < V_13 ) {
if ( V_17 % 2 != 0 ) {
* V_12 |= ( * V_15 ++ - '0' ) << 0 ;
V_12 ++ ;
} else {
* V_12 = 0x00 ;
* V_12 |= ( * V_15 ++ - '0' ) << 4 ;
}
} else {
if ( V_17 % 2 != 0 ) {
* V_12 |= ( * V_16 ++ - '0' ) << 0 ;
V_12 ++ ;
} else {
* V_12 = 0x00 ;
* V_12 |= ( * V_16 ++ - '0' ) << 4 ;
}
}
}
return 1 + ( V_13 + V_14 + 1 ) / 2 ;
}
static void F_5 ( struct V_18 * V_19 )
{
F_6 ( & V_20 ) ;
F_7 ( V_19 ) ;
F_8 ( & V_20 ) ;
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_6 ( & V_20 ) ;
F_10 (s, node, &x25_list)
if ( F_11 ( V_23 ) -> V_26 && F_11 ( V_23 ) -> V_26 -> V_22 == V_22 )
F_12 ( V_23 , V_27 , 0 , 0 ) ;
F_8 ( & V_20 ) ;
}
static int F_13 ( struct V_28 * V_29 , unsigned long V_30 ,
void * V_31 )
{
struct V_21 * V_22 = V_31 ;
struct V_32 * V_33 ;
if ( ! F_14 ( F_15 ( V_22 ) , & V_34 ) )
return V_35 ;
if ( V_22 -> type == V_36
#if F_16 ( V_37 )
|| V_22 -> type == V_38
#endif
) {
switch ( V_30 ) {
case V_39 :
F_17 ( V_22 ) ;
break;
case V_40 :
V_33 = F_18 ( V_22 ) ;
if ( V_33 ) {
F_19 ( V_33 ) ;
F_20 ( V_33 ) ;
}
break;
case V_41 :
F_9 ( V_22 ) ;
F_21 ( V_22 ) ;
F_22 ( V_22 ) ;
break;
}
}
return V_35 ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_6 ( & V_20 ) ;
F_24 ( V_19 , & V_42 ) ;
F_8 ( & V_20 ) ;
}
static struct V_18 * F_25 ( struct V_3 * V_43 ,
struct V_1 * V_2 )
{
struct V_18 * V_23 ;
struct V_18 * V_44 ;
struct V_24 * V_25 ;
F_26 ( & V_20 ) ;
V_44 = NULL ;
F_10 (s, node, &x25_list)
if ( ( ! strcmp ( V_43 -> V_11 ,
F_11 ( V_23 ) -> V_45 . V_11 ) ||
! strcmp ( V_43 -> V_11 ,
V_46 . V_11 ) ) &&
V_23 -> V_47 == V_48 ) {
if ( F_11 ( V_23 ) -> V_49 > 0 &&
V_2 -> V_6 >= F_11 ( V_23 ) -> V_49 ) {
if( ( memcmp ( F_11 ( V_23 ) -> V_50 . V_51 ,
V_2 -> V_10 ,
F_11 ( V_23 ) -> V_49 ) ) == 0 ) {
F_27 ( V_23 ) ;
goto V_52;
}
} else
V_44 = V_23 ;
}
if ( V_44 ) {
V_23 = V_44 ;
F_27 ( V_23 ) ;
goto V_52;
}
V_23 = NULL ;
V_52:
F_28 ( & V_20 ) ;
return V_23 ;
}
static struct V_18 * F_29 ( unsigned int V_53 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_10 (s, node, &x25_list)
if ( F_11 ( V_23 ) -> V_53 == V_53 && F_11 ( V_23 ) -> V_26 == V_33 ) {
F_27 ( V_23 ) ;
goto V_52;
}
V_23 = NULL ;
V_52:
return V_23 ;
}
struct V_18 * F_30 ( unsigned int V_53 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
F_26 ( & V_20 ) ;
V_23 = F_29 ( V_53 , V_33 ) ;
F_28 ( & V_20 ) ;
return V_23 ;
}
static unsigned int F_31 ( struct V_32 * V_33 )
{
unsigned int V_53 = 1 ;
struct V_18 * V_19 ;
F_26 ( & V_20 ) ;
while ( ( V_19 = F_29 ( V_53 , V_33 ) ) != NULL ) {
F_32 ( V_19 ) ;
if ( ++ V_53 == 4096 ) {
V_53 = 0 ;
break;
}
}
F_28 ( & V_20 ) ;
return V_53 ;
}
static void F_33 ( unsigned long V_10 )
{
F_34 ( (struct V_18 * ) V_10 ) ;
}
static void F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_36 ( V_19 ) ;
F_37 ( V_19 ) ;
F_5 ( V_19 ) ;
F_38 ( V_19 ) ;
while ( ( V_2 = F_39 ( & V_19 -> V_54 ) ) != NULL ) {
if ( V_2 -> V_19 != V_19 ) {
V_2 -> V_19 -> V_47 = V_48 ;
F_40 ( V_2 -> V_19 , V_55 ) ;
F_41 ( V_2 -> V_19 ) ;
F_11 ( V_2 -> V_19 ) -> V_56 = V_57 ;
}
F_42 ( V_2 ) ;
}
if ( F_43 ( V_19 ) ) {
V_19 -> V_58 . V_59 = V_60 + 10 * V_61 ;
V_19 -> V_58 . V_62 = F_33 ;
V_19 -> V_58 . V_10 = ( unsigned long ) V_19 ;
F_44 ( & V_19 -> V_58 ) ;
} else {
F_45 ( V_19 ) ;
}
}
void F_34 ( struct V_18 * V_19 )
{
F_27 ( V_19 ) ;
F_46 ( V_19 ) ;
F_35 ( V_19 ) ;
F_47 ( V_19 ) ;
F_32 ( V_19 ) ;
}
static int F_48 ( struct V_63 * V_18 , int V_64 , int V_65 ,
char T_1 * V_66 , unsigned int V_67 )
{
int V_68 ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_69 ;
if ( V_64 != V_70 || V_65 != V_71 )
goto V_72;
V_8 = - V_73 ;
if ( V_67 < sizeof( int ) )
goto V_72;
V_8 = - V_74 ;
if ( F_49 ( V_68 , ( int T_1 * ) V_66 ) )
goto V_72;
if ( V_68 )
F_50 ( V_75 , & F_11 ( V_19 ) -> V_76 ) ;
else
F_51 ( V_75 , & F_11 ( V_19 ) -> V_76 ) ;
V_8 = 0 ;
V_72:
return V_8 ;
}
static int F_52 ( struct V_63 * V_18 , int V_64 , int V_65 ,
char T_1 * V_66 , int T_1 * V_67 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_77 , V_6 , V_8 = - V_69 ;
if ( V_64 != V_70 || V_65 != V_71 )
goto V_72;
V_8 = - V_74 ;
if ( F_49 ( V_6 , V_67 ) )
goto V_72;
V_6 = F_53 (unsigned int, len, sizeof(int)) ;
V_8 = - V_73 ;
if ( V_6 < 0 )
goto V_72;
V_8 = - V_74 ;
if ( F_54 ( V_6 , V_67 ) )
goto V_72;
V_77 = F_55 ( V_75 , & F_11 ( V_19 ) -> V_76 ) ;
V_8 = F_56 ( V_66 , & V_77 , V_6 ) ? - V_74 : 0 ;
V_72:
return V_8 ;
}
static int F_57 ( struct V_63 * V_18 , int V_78 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_79 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 != V_48 ) {
memset ( & F_11 ( V_19 ) -> V_80 , 0 , V_81 ) ;
V_19 -> V_82 = V_78 ;
V_19 -> V_47 = V_48 ;
V_8 = 0 ;
}
F_59 ( V_19 ) ;
return V_8 ;
}
static struct V_18 * F_60 ( struct V_83 * V_83 )
{
struct V_84 * V_85 ;
struct V_18 * V_19 = F_61 ( V_83 , V_86 , V_87 , & V_88 ) ;
if ( ! V_19 )
goto V_72;
F_62 ( NULL , V_19 ) ;
V_85 = F_11 ( V_19 ) ;
F_63 ( & V_85 -> V_89 ) ;
F_63 ( & V_85 -> V_90 ) ;
F_63 ( & V_85 -> V_91 ) ;
F_63 ( & V_85 -> V_92 ) ;
V_72:
return V_19 ;
}
static int F_64 ( struct V_83 * V_83 , struct V_63 * V_18 , int V_93 ,
int V_94 )
{
struct V_18 * V_19 ;
struct V_84 * V_85 ;
int V_8 = - V_95 ;
if ( ! F_14 ( V_83 , & V_34 ) )
goto V_72;
V_8 = - V_96 ;
if ( V_18 -> type != V_97 )
goto V_72;
V_8 = - V_73 ;
if ( V_93 )
goto V_72;
V_8 = - V_98 ;
if ( ( V_19 = F_60 ( V_83 ) ) == NULL )
goto V_72;
V_85 = F_11 ( V_19 ) ;
F_62 ( V_18 , V_19 ) ;
F_65 ( V_19 ) ;
V_18 -> V_99 = & V_100 ;
V_19 -> V_101 = V_93 ;
V_19 -> V_102 = V_103 ;
V_85 -> V_104 = V_105 ;
V_85 -> V_106 = V_107 ;
V_85 -> V_108 = V_109 ;
V_85 -> V_110 = V_111 ;
V_85 -> V_56 = V_57 ;
V_85 -> V_49 = 0 ;
F_50 ( V_112 , & V_85 -> V_76 ) ;
V_85 -> V_113 . V_114 = V_115 ;
V_85 -> V_113 . V_116 = V_115 ;
V_85 -> V_113 . V_117 = V_118 ;
V_85 -> V_113 . V_119 = V_118 ;
V_85 -> V_113 . V_120 = 0 ;
V_85 -> V_113 . V_121 = V_122 ;
V_85 -> V_123 . V_14 = 0 ;
V_85 -> V_123 . V_13 = 0 ;
memset ( V_85 -> V_123 . V_124 , '\0' ,
sizeof( V_85 -> V_123 . V_124 ) ) ;
memset ( V_85 -> V_123 . V_125 , '\0' ,
sizeof( V_85 -> V_123 . V_125 ) ) ;
V_8 = 0 ;
V_72:
return V_8 ;
}
static struct V_18 * F_66 ( struct V_18 * V_126 )
{
struct V_18 * V_19 = NULL ;
struct V_84 * V_85 , * V_127 ;
if ( V_126 -> V_128 != V_97 )
goto V_72;
if ( ( V_19 = F_60 ( F_67 ( V_126 ) ) ) == NULL )
goto V_72;
V_85 = F_11 ( V_19 ) ;
V_19 -> V_128 = V_126 -> V_128 ;
V_19 -> V_129 = V_126 -> V_129 ;
V_19 -> V_101 = V_126 -> V_101 ;
V_19 -> V_130 = V_126 -> V_130 ;
V_19 -> V_131 = V_126 -> V_131 ;
V_19 -> V_47 = V_132 ;
V_19 -> V_102 = V_126 -> V_102 ;
F_68 ( V_19 , V_126 ) ;
V_127 = F_11 ( V_126 ) ;
V_85 -> V_104 = V_127 -> V_104 ;
V_85 -> V_106 = V_127 -> V_106 ;
V_85 -> V_108 = V_127 -> V_108 ;
V_85 -> V_110 = V_127 -> V_110 ;
V_85 -> V_76 = V_127 -> V_76 ;
V_85 -> V_113 = V_127 -> V_113 ;
V_85 -> V_123 = V_127 -> V_123 ;
V_85 -> V_49 = V_127 -> V_49 ;
F_51 ( V_133 , & V_85 -> V_76 ) ;
F_65 ( V_19 ) ;
V_72:
return V_19 ;
}
static int F_69 ( struct V_63 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 ;
if ( ! V_19 )
return 0 ;
V_85 = F_11 ( V_19 ) ;
F_27 ( V_19 ) ;
F_58 ( V_19 ) ;
switch ( V_85 -> V_56 ) {
case V_57 :
case V_134 :
F_12 ( V_19 , 0 , 0 , 0 ) ;
F_35 ( V_19 ) ;
goto V_72;
case V_135 :
case V_136 :
case V_137 :
F_38 ( V_19 ) ;
F_70 ( V_19 , V_138 ) ;
F_71 ( V_19 ) ;
V_85 -> V_56 = V_134 ;
V_19 -> V_47 = V_139 ;
V_19 -> V_140 |= V_141 ;
V_19 -> V_142 ( V_19 ) ;
F_40 ( V_19 , V_55 ) ;
F_40 ( V_19 , V_143 ) ;
break;
}
F_72 ( V_19 ) ;
V_72:
F_59 ( V_19 ) ;
F_32 ( V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_63 * V_18 , struct V_144 * V_145 , int V_146 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_147 * V_43 = (struct V_147 * ) V_145 ;
int V_6 , V_17 , V_8 = 0 ;
if ( ! F_74 ( V_19 , V_148 ) ||
V_146 != sizeof( struct V_147 ) ||
V_43 -> V_149 != V_86 ) {
V_8 = - V_73 ;
goto V_72;
}
V_6 = strlen ( V_43 -> V_150 . V_11 ) ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
if ( ! isdigit ( V_43 -> V_150 . V_11 [ V_17 ] ) ) {
V_8 = - V_73 ;
goto V_72;
}
}
F_58 ( V_19 ) ;
F_11 ( V_19 ) -> V_45 = V_43 -> V_150 ;
F_23 ( V_19 ) ;
F_75 ( V_19 , V_148 ) ;
F_59 ( V_19 ) ;
F_76 ( V_19 , L_1 ) ;
V_72:
return V_8 ;
}
static int F_77 ( struct V_18 * V_19 )
{
F_78 ( V_151 , V_152 ) ;
int V_8 ;
F_79 ( F_80 ( V_19 ) , & V_151 ) ;
for (; ; ) {
F_81 ( V_153 ) ;
V_8 = - V_154 ;
if ( F_82 ( V_152 ) )
break;
V_8 = F_83 ( V_19 ) ;
if ( V_8 ) {
V_19 -> V_155 -> V_56 = V_156 ;
break;
}
V_8 = 0 ;
if ( V_19 -> V_47 != V_132 ) {
F_59 ( V_19 ) ;
F_84 () ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_157 ) ;
F_85 ( F_80 ( V_19 ) , & V_151 ) ;
return V_8 ;
}
static int F_86 ( struct V_63 * V_18 , struct V_144 * V_145 ,
int V_146 , int V_76 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 = F_11 ( V_19 ) ;
struct V_147 * V_43 = (struct V_147 * ) V_145 ;
struct V_158 * V_159 ;
int V_8 = 0 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 == V_132 && V_18 -> V_56 == V_160 ) {
V_18 -> V_56 = V_161 ;
goto V_72;
}
V_8 = - V_162 ;
if ( V_19 -> V_47 == V_139 && V_18 -> V_56 == V_160 ) {
V_18 -> V_56 = V_156 ;
goto V_72;
}
V_8 = - V_163 ;
if ( V_19 -> V_47 == V_132 )
goto V_72;
V_19 -> V_47 = V_139 ;
V_18 -> V_56 = V_156 ;
V_8 = - V_73 ;
if ( V_146 != sizeof( struct V_147 ) ||
V_43 -> V_149 != V_86 )
goto V_72;
V_8 = - V_27 ;
V_159 = F_87 ( & V_43 -> V_150 ) ;
if ( ! V_159 )
goto V_72;
V_85 -> V_26 = F_18 ( V_159 -> V_22 ) ;
if ( ! V_85 -> V_26 )
goto V_164;
F_88 ( & V_85 -> V_113 , V_85 -> V_26 ) ;
V_85 -> V_53 = F_31 ( V_85 -> V_26 ) ;
if ( ! V_85 -> V_53 )
goto V_165;
V_8 = - V_73 ;
if ( F_74 ( V_19 , V_148 ) )
goto V_165;
if ( ! strcmp ( V_85 -> V_45 . V_11 , V_46 . V_11 ) )
memset ( & V_85 -> V_45 , '\0' , V_81 ) ;
V_85 -> V_80 = V_43 -> V_150 ;
V_18 -> V_56 = V_160 ;
V_19 -> V_47 = V_166 ;
V_85 -> V_56 = V_135 ;
F_70 ( V_19 , V_167 ) ;
F_41 ( V_19 ) ;
F_89 ( V_19 ) ;
V_8 = - V_168 ;
if ( V_19 -> V_47 != V_132 && ( V_76 & V_169 ) )
goto V_165;
V_8 = F_77 ( V_19 ) ;
if ( V_8 )
goto V_165;
V_18 -> V_56 = V_161 ;
V_8 = 0 ;
V_165:
if ( V_8 )
F_20 ( V_85 -> V_26 ) ;
V_164:
F_90 ( V_159 ) ;
V_72:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_91 ( struct V_18 * V_19 , long V_170 )
{
F_78 ( V_151 , V_152 ) ;
int V_8 = 0 ;
F_79 ( F_80 ( V_19 ) , & V_151 ) ;
for (; ; ) {
F_81 ( V_153 ) ;
if ( V_19 -> V_140 & V_171 )
break;
V_8 = - V_154 ;
if ( F_82 ( V_152 ) )
break;
V_8 = - V_172 ;
if ( ! V_170 )
break;
V_8 = 0 ;
if ( F_92 ( & V_19 -> V_54 ) ) {
F_59 ( V_19 ) ;
V_170 = F_93 ( V_170 ) ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_157 ) ;
F_85 ( F_80 ( V_19 ) , & V_151 ) ;
return V_8 ;
}
static int F_94 ( struct V_63 * V_18 , struct V_63 * V_173 , int V_76 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_18 * V_174 ;
struct V_1 * V_2 ;
int V_8 = - V_73 ;
if ( ! V_19 )
goto V_72;
V_8 = - V_79 ;
if ( V_19 -> V_128 != V_97 )
goto V_72;
F_58 ( V_19 ) ;
V_8 = - V_73 ;
if ( V_19 -> V_47 != V_48 )
goto V_175;
V_8 = F_91 ( V_19 , V_19 -> V_176 ) ;
if ( V_8 )
goto V_175;
V_2 = F_39 ( & V_19 -> V_54 ) ;
V_8 = - V_73 ;
if ( ! V_2 -> V_19 )
goto V_175;
V_174 = V_2 -> V_19 ;
F_95 ( V_174 , V_173 ) ;
V_2 -> V_19 = NULL ;
F_42 ( V_2 ) ;
V_19 -> V_177 -- ;
V_173 -> V_56 = V_161 ;
V_8 = 0 ;
V_175:
F_59 ( V_19 ) ;
V_72:
return V_8 ;
}
static int F_96 ( struct V_63 * V_18 , struct V_144 * V_145 ,
int * V_178 , int V_179 )
{
struct V_147 * V_180 = (struct V_147 * ) V_145 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 = F_11 ( V_19 ) ;
int V_8 = 0 ;
if ( V_179 ) {
if ( V_19 -> V_47 != V_132 ) {
V_8 = - V_181 ;
goto V_72;
}
V_180 -> V_150 = V_85 -> V_80 ;
} else
V_180 -> V_150 = V_85 -> V_45 ;
V_180 -> V_149 = V_86 ;
* V_178 = sizeof( * V_180 ) ;
V_72:
return V_8 ;
}
int F_97 ( struct V_1 * V_2 , struct V_32 * V_33 ,
unsigned int V_53 )
{
struct V_18 * V_19 ;
struct V_18 * V_182 ;
struct V_84 * V_183 ;
struct V_3 V_45 , V_80 ;
struct V_184 V_113 ;
struct V_185 V_123 ;
int V_6 , V_146 , V_8 ;
F_98 ( V_2 , V_186 ) ;
V_146 = F_1 ( V_2 , & V_45 , & V_80 ) ;
if ( V_146 <= 0 )
goto V_187;
F_98 ( V_2 , V_146 ) ;
if ( ! F_2 ( V_2 , 1 ) )
goto V_187;
V_6 = V_2 -> V_10 [ 0 ] + 1 ;
if ( ! F_2 ( V_2 , V_6 ) )
goto V_187;
F_98 ( V_2 , V_6 ) ;
if ( V_2 -> V_6 > V_188 )
goto V_187;
if ( ! F_2 ( V_2 , V_2 -> V_6 ) )
goto V_187;
V_19 = F_25 ( & V_45 , V_2 ) ;
F_99 ( V_2 , V_6 ) ;
if ( V_19 != NULL && F_100 ( V_19 ) ) {
goto V_189;
}
if ( V_19 == NULL ) {
F_99 ( V_2 , V_146 + V_186 ) ;
if ( V_190 &&
F_101 ( & V_80 , V_33 , V_2 , V_53 ) > 0 )
{
F_42 ( V_2 ) ;
V_8 = 1 ;
goto V_72;
} else {
goto V_187;
}
}
V_6 = F_102 ( V_2 , V_19 , & V_113 , & V_123 ) ;
if ( V_6 == - 1 )
goto V_189;
F_88 ( & V_113 , V_33 ) ;
V_182 = F_66 ( V_19 ) ;
if ( ! V_182 )
goto V_189;
F_98 ( V_2 , V_6 ) ;
V_2 -> V_19 = V_182 ;
V_182 -> V_47 = V_132 ;
V_183 = F_11 ( V_182 ) ;
V_183 -> V_53 = V_53 ;
V_183 -> V_80 = V_80 ;
V_183 -> V_45 = V_45 ;
V_183 -> V_26 = V_33 ;
V_183 -> V_113 = V_113 ;
V_183 -> V_123 = V_123 ;
V_183 -> V_191 = F_11 ( V_19 ) -> V_191 ;
V_183 -> V_191 &= ~ V_192 ;
V_183 -> V_191 &= ~ V_193 ;
V_183 -> V_49 = F_11 ( V_19 ) -> V_49 ;
if ( F_55 ( V_112 , & V_183 -> V_76 ) ) {
F_70 ( V_182 , V_194 ) ;
V_183 -> V_56 = V_136 ;
}
F_103 ( V_2 , V_183 -> V_50 . V_51 , V_2 -> V_6 ) ;
V_183 -> V_50 . V_195 = V_2 -> V_6 ;
V_19 -> V_177 ++ ;
F_23 ( V_182 ) ;
F_104 ( & V_19 -> V_54 , V_2 ) ;
F_41 ( V_182 ) ;
if ( ! F_74 ( V_19 , V_55 ) )
V_19 -> V_196 ( V_19 , V_2 -> V_6 ) ;
V_8 = 1 ;
F_32 ( V_19 ) ;
V_72:
return V_8 ;
V_189:
F_32 ( V_19 ) ;
V_187:
V_8 = 0 ;
F_105 ( V_33 , V_53 , 0x01 ) ;
goto V_72;
}
static int F_106 ( struct V_197 * V_198 , struct V_63 * V_18 ,
struct V_199 * V_200 , T_2 V_6 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 = F_11 ( V_19 ) ;
struct V_147 * V_201 = (struct V_147 * ) V_200 -> V_202 ;
struct V_147 V_180 ;
struct V_1 * V_2 ;
unsigned char * V_203 ;
int V_204 = V_200 -> V_205 & V_206 ;
T_2 V_207 ;
int V_208 = 0 , V_8 = - V_73 ;
F_58 ( V_19 ) ;
if ( V_200 -> V_205 & ~ ( V_206 | V_209 | V_210 | V_211 ) )
goto V_72;
if ( ! ( V_200 -> V_205 & ( V_210 | V_209 ) ) )
goto V_72;
V_8 = - V_212 ;
if ( F_74 ( V_19 , V_148 ) )
goto V_72;
V_8 = - V_213 ;
if ( V_19 -> V_140 & V_141 ) {
F_107 ( V_214 , V_152 , 0 ) ;
goto V_72;
}
V_8 = - V_27 ;
if ( ! V_85 -> V_26 )
goto V_72;
if ( V_201 ) {
V_8 = - V_73 ;
if ( V_200 -> V_215 < sizeof( V_180 ) )
goto V_72;
memcpy ( & V_180 , V_201 , sizeof( V_180 ) ) ;
V_8 = - V_163 ;
if ( strcmp ( V_85 -> V_80 . V_11 , V_180 . V_150 . V_11 ) )
goto V_72;
V_8 = - V_73 ;
if ( V_180 . V_149 != V_86 )
goto V_72;
} else {
V_8 = - V_181 ;
if ( V_19 -> V_47 != V_132 )
goto V_72;
V_180 . V_149 = V_86 ;
V_180 . V_150 = V_85 -> V_80 ;
}
if ( V_6 > 65535 ) {
V_8 = - V_216 ;
goto V_72;
}
F_76 ( V_19 , L_2 ) ;
F_76 ( V_19 , L_3 ) ;
if ( ( V_200 -> V_205 & V_209 ) && V_6 > 32 )
V_6 = 32 ;
V_207 = V_6 + V_217 + V_218 ;
F_59 ( V_19 ) ;
V_2 = F_108 ( V_19 , V_207 , V_204 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_72;
F_109 ( V_2 ) -> V_76 = V_200 -> V_205 ;
F_110 ( V_2 , V_217 + V_218 ) ;
F_76 ( V_19 , L_4 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 , V_6 ) ;
V_8 = F_113 ( F_114 ( V_2 ) , V_200 -> V_219 , V_6 ) ;
if ( V_8 )
goto V_220;
if ( F_55 ( V_75 , & V_85 -> V_76 ) ) {
if ( ! F_2 ( V_2 , 1 ) )
goto V_220;
V_208 = V_2 -> V_10 [ 0 ] ;
F_98 ( V_2 , 1 ) ;
}
F_76 ( V_19 , L_5 ) ;
if ( V_200 -> V_205 & V_209 ) {
if ( V_85 -> V_26 -> V_221 ) {
V_203 = F_99 ( V_2 , V_186 ) ;
* V_203 ++ = ( ( V_85 -> V_53 >> 8 ) & 0x0F ) | V_222 ;
* V_203 ++ = ( V_85 -> V_53 >> 0 ) & 0xFF ;
* V_203 ++ = V_223 ;
} else {
V_203 = F_99 ( V_2 , V_186 ) ;
* V_203 ++ = ( ( V_85 -> V_53 >> 8 ) & 0x0F ) | V_224 ;
* V_203 ++ = ( V_85 -> V_53 >> 0 ) & 0xFF ;
* V_203 ++ = V_223 ;
}
} else {
if ( V_85 -> V_26 -> V_221 ) {
V_203 = F_99 ( V_2 , V_218 ) ;
* V_203 ++ = ( ( V_85 -> V_53 >> 8 ) & 0x0F ) | V_222 ;
* V_203 ++ = ( V_85 -> V_53 >> 0 ) & 0xFF ;
* V_203 ++ = V_225 ;
* V_203 ++ = V_225 ;
} else {
V_203 = F_99 ( V_2 , V_186 ) ;
* V_203 ++ = ( ( V_85 -> V_53 >> 8 ) & 0x0F ) | V_224 ;
* V_203 ++ = ( V_85 -> V_53 >> 0 ) & 0xFF ;
* V_203 ++ = V_225 ;
}
if ( V_208 )
V_2 -> V_10 [ 0 ] |= V_226 ;
}
F_76 ( V_19 , L_6 ) ;
F_76 ( V_19 , L_7 ) ;
V_8 = - V_181 ;
if ( V_19 -> V_47 != V_132 )
goto V_220;
if ( V_200 -> V_205 & V_209 )
F_115 ( & V_85 -> V_92 , V_2 ) ;
else {
V_8 = F_116 ( V_19 , V_2 ) ;
V_6 = V_8 ;
if ( V_8 < 0 )
F_42 ( V_2 ) ;
else if ( F_55 ( V_75 , & V_85 -> V_76 ) )
V_6 ++ ;
}
F_117 ( V_19 ) ;
V_8 = V_6 ;
V_72:
F_59 ( V_19 ) ;
return V_8 ;
V_220:
F_42 ( V_2 ) ;
goto V_72;
}
static int F_118 ( struct V_197 * V_198 , struct V_63 * V_18 ,
struct V_199 * V_200 , T_2 V_207 ,
int V_76 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 = F_11 ( V_19 ) ;
struct V_147 * V_180 = (struct V_147 * ) V_200 -> V_202 ;
T_2 V_227 ;
int V_208 , V_228 ;
struct V_1 * V_2 ;
unsigned char * V_203 ;
int V_8 = - V_181 ;
F_58 ( V_19 ) ;
if ( V_85 -> V_26 == NULL )
goto V_72;
V_228 = V_85 -> V_26 -> V_221 ?
V_218 : V_186 ;
if ( V_19 -> V_47 != V_132 )
goto V_72;
if ( V_76 & V_209 ) {
V_8 = - V_73 ;
if ( F_74 ( V_19 , V_229 ) ||
! F_119 ( & V_85 -> V_91 ) )
goto V_72;
V_2 = F_39 ( & V_85 -> V_91 ) ;
if ( ! F_2 ( V_2 , V_186 ) )
goto V_230;
F_98 ( V_2 , V_186 ) ;
if ( F_55 ( V_75 , & V_85 -> V_76 ) ) {
V_203 = F_99 ( V_2 , 1 ) ;
* V_203 = 0x00 ;
}
V_200 -> V_205 |= V_209 ;
} else {
F_59 ( V_19 ) ;
V_2 = F_120 ( V_19 , V_76 & ~ V_206 ,
V_76 & V_206 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_72;
if ( ! F_2 ( V_2 , V_228 ) )
goto V_230;
V_208 = ( V_2 -> V_10 [ 0 ] & V_226 ) == V_226 ;
F_98 ( V_2 , V_228 ) ;
if ( F_55 ( V_75 , & V_85 -> V_76 ) ) {
V_203 = F_99 ( V_2 , 1 ) ;
* V_203 = V_208 ;
}
}
F_111 ( V_2 ) ;
V_227 = V_2 -> V_6 ;
if ( V_227 > V_207 ) {
V_227 = V_207 ;
V_200 -> V_205 |= V_231 ;
}
V_200 -> V_205 |= V_210 ;
V_8 = F_121 ( V_2 , 0 , V_200 -> V_219 , V_227 ) ;
if ( V_8 )
goto V_230;
if ( V_180 ) {
V_180 -> V_149 = V_86 ;
V_180 -> V_150 = V_85 -> V_80 ;
}
V_200 -> V_215 = sizeof( struct V_147 ) ;
F_122 ( V_19 ) ;
V_8 = V_227 ;
V_230:
F_123 ( V_19 , V_2 ) ;
V_72:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_124 ( struct V_63 * V_18 , unsigned int V_232 , unsigned long V_233 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_84 * V_85 = F_11 ( V_19 ) ;
void T_1 * V_234 = ( void T_1 * ) V_233 ;
int V_8 ;
switch ( V_232 ) {
case V_235 : {
int V_236 ;
V_236 = V_19 -> V_131 - F_125 ( V_19 ) ;
if ( V_236 < 0 )
V_236 = 0 ;
V_8 = F_54 ( V_236 , ( unsigned int T_1 * ) V_234 ) ;
break;
}
case V_237 : {
struct V_1 * V_2 ;
int V_236 = 0 ;
F_58 ( V_19 ) ;
if ( ( V_2 = F_119 ( & V_19 -> V_54 ) ) != NULL )
V_236 = V_2 -> V_6 ;
F_59 ( V_19 ) ;
V_8 = F_54 ( V_236 , ( unsigned int T_1 * ) V_234 ) ;
break;
}
case V_238 :
V_8 = - V_73 ;
if ( V_19 )
V_8 = F_126 ( V_19 ,
(struct V_239 T_1 * ) V_234 ) ;
break;
case V_240 :
V_8 = - V_73 ;
if ( V_19 )
V_8 = F_127 ( V_19 ,
(struct V_241 T_1 * ) V_234 ) ;
break;
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
V_8 = - V_73 ;
break;
case V_252 :
case V_253 :
V_8 = - V_254 ;
if ( ! F_128 ( V_255 ) )
break;
V_8 = F_129 ( V_232 , V_234 ) ;
break;
case V_256 :
V_8 = F_130 ( V_232 , V_234 ) ;
break;
case V_257 :
V_8 = - V_254 ;
if ( ! F_128 ( V_255 ) )
break;
V_8 = F_130 ( V_232 , V_234 ) ;
break;
case V_258 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_234 , & V_85 -> V_113 ,
sizeof( V_85 -> V_113 ) )
? - V_74 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_259 : {
struct V_184 V_113 ;
V_8 = - V_74 ;
if ( F_131 ( & V_113 , V_234 , sizeof( V_113 ) ) )
break;
V_8 = - V_73 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 != V_48 &&
V_19 -> V_47 != V_139 )
goto V_260;
if ( V_113 . V_117 < V_261 ||
V_113 . V_117 > V_262 )
goto V_260;
if ( V_113 . V_119 < V_261 ||
V_113 . V_119 > V_262 )
goto V_260;
if ( V_113 . V_114 < 1 ||
V_113 . V_114 > 127 )
goto V_260;
if ( V_113 . V_120 ) {
int V_72 = V_113 . V_120 & 0xf0 ;
int V_263 = V_113 . V_120 & 0x0f ;
if ( ! V_72 )
V_113 . V_120 |=
V_264 << 4 ;
else if ( V_72 < 0x30 || V_72 > 0xD0 )
goto V_260;
if ( ! V_263 )
V_113 . V_120 |=
V_264 ;
else if ( V_263 < 0x03 || V_263 > 0x0D )
goto V_260;
}
if ( V_113 . V_121 &&
( V_113 . V_121 & 0x81 ) != 0x81 )
goto V_260;
V_85 -> V_113 = V_113 ;
V_8 = 0 ;
V_260:
F_59 ( V_19 ) ;
break;
}
case V_265 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_234 , & V_85 -> V_123 ,
sizeof( V_85 -> V_123 ) ) ;
F_59 ( V_19 ) ;
if ( V_8 )
V_8 = - V_74 ;
break;
}
case V_266 : {
struct V_185 V_267 ;
V_8 = - V_74 ;
if ( F_131 ( & V_267 , V_234 , sizeof( V_267 ) ) )
break;
V_8 = - V_73 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 != V_48 &&
V_19 -> V_47 != V_139 )
goto V_268;
if ( V_267 . V_14 > V_269 )
goto V_268;
if ( V_267 . V_125 == NULL )
goto V_268;
if ( V_267 . V_13 > V_269 )
goto V_268;
if ( V_267 . V_124 == NULL )
goto V_268;
V_85 -> V_123 = V_267 ;
V_8 = 0 ;
V_268:
F_59 ( V_19 ) ;
break;
}
case V_270 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_234 , & V_85 -> V_50 ,
sizeof( V_85 -> V_50 ) )
? - V_74 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_271 : {
struct V_272 V_50 ;
V_8 = - V_74 ;
if ( F_131 ( & V_50 , V_234 , sizeof( V_50 ) ) )
break;
V_8 = - V_73 ;
if ( V_50 . V_195 > V_188 )
break;
F_58 ( V_19 ) ;
V_85 -> V_50 = V_50 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_273 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_234 , & V_85 -> V_274 , sizeof( V_85 -> V_274 ) )
? - V_74 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_275 : {
struct V_276 V_274 ;
V_8 = - V_74 ;
if ( F_131 ( & V_274 , V_234 , sizeof( V_274 ) ) )
break;
F_58 ( V_19 ) ;
V_85 -> V_274 = V_274 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_277 : {
struct V_278 V_279 ;
V_8 = - V_73 ;
F_58 ( V_19 ) ;
if( V_19 -> V_47 != V_139 )
goto V_280;
V_8 = - V_74 ;
if ( F_131 ( & V_279 , V_234 ,
sizeof( V_279 ) ) )
goto V_280;
V_8 = - V_73 ;
if ( V_279 . V_49 > V_188 )
goto V_280;
V_85 -> V_49 = V_279 . V_49 ;
V_8 = 0 ;
V_280:
F_59 ( V_19 ) ;
break;
}
case V_281 : {
V_8 = - V_73 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 != V_139 )
break;
F_51 ( V_112 , & V_85 -> V_76 ) ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_282 : {
V_8 = - V_73 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_47 != V_132 )
break;
if ( F_55 ( V_112 , & V_85 -> V_76 ) )
break;
F_70 ( V_19 , V_194 ) ;
V_85 -> V_56 = V_136 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
default:
V_8 = - V_283 ;
break;
}
return V_8 ;
}
static int F_132 ( unsigned int V_232 ,
struct V_284 T_1 * V_285 )
{
struct V_284 V_286 ;
struct V_32 * V_33 ;
struct V_21 * V_22 ;
int V_8 = - V_73 ;
V_8 = - V_74 ;
if ( F_131 ( & V_286 , V_285 , sizeof( * V_285 ) ) )
goto V_72;
V_8 = - V_73 ;
V_22 = F_133 ( V_286 . V_287 ) ;
if ( V_22 == NULL )
goto V_72;
V_33 = F_18 ( V_22 ) ;
if ( V_33 == NULL )
goto V_288;
F_134 ( V_22 ) ;
if ( V_232 == V_256 ) {
F_26 ( & V_289 ) ;
V_286 . V_221 = V_33 -> V_221 ;
V_286 . V_290 = V_33 -> V_290 ;
F_28 ( & V_289 ) ;
V_8 = F_56 ( V_285 , & V_286 ,
sizeof( * V_285 ) ) ? - V_74 : 0 ;
} else {
V_8 = - V_73 ;
if ( V_286 . V_221 == 0 || V_286 . V_221 == 1 ) {
V_8 = 0 ;
F_6 ( & V_289 ) ;
V_33 -> V_221 = V_286 . V_221 ;
V_33 -> V_290 = V_286 . V_290 ;
F_8 ( & V_289 ) ;
}
}
F_20 ( V_33 ) ;
V_72:
return V_8 ;
V_288:
F_134 ( V_22 ) ;
goto V_72;
}
static int F_135 ( struct V_63 * V_18 , unsigned int V_232 ,
unsigned long V_233 )
{
void T_1 * V_234 = F_136 ( V_233 ) ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_283 ;
switch( V_232 ) {
case V_235 :
case V_237 :
V_8 = F_124 ( V_18 , V_232 , ( unsigned long ) V_234 ) ;
break;
case V_238 :
V_8 = - V_73 ;
if ( V_19 )
V_8 = F_137 ( V_19 ,
(struct V_239 T_1 * ) V_234 ) ;
break;
case V_240 :
V_8 = - V_73 ;
if ( V_19 )
V_8 = F_138 ( V_19 ,
(struct V_241 T_1 * ) V_234 ) ;
break;
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
V_8 = - V_73 ;
break;
case V_252 :
case V_253 :
V_8 = - V_254 ;
if ( ! F_128 ( V_255 ) )
break;
V_8 = F_129 ( V_232 , V_234 ) ;
break;
case V_256 :
V_8 = F_132 ( V_232 , V_234 ) ;
break;
case V_257 :
V_8 = - V_254 ;
if ( ! F_128 ( V_255 ) )
break;
V_8 = F_132 ( V_232 , V_234 ) ;
break;
case V_258 :
case V_259 :
case V_265 :
case V_266 :
case V_270 :
case V_271 :
case V_273 :
case V_275 :
case V_277 :
case V_281 :
case V_282 :
V_8 = F_124 ( V_18 , V_232 , ( unsigned long ) V_234 ) ;
break;
default:
V_8 = - V_283 ;
break;
}
return V_8 ;
}
void F_139 ( struct V_32 * V_33 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_6 ( & V_20 ) ;
F_10 (s, node, &x25_list)
if ( F_11 ( V_23 ) -> V_26 == V_33 )
F_12 ( V_23 , V_27 , 0 , 0 ) ;
F_8 ( & V_20 ) ;
F_140 ( V_33 -> V_22 ) ;
}
static int T_3 F_141 ( void )
{
int V_8 = F_142 ( & V_88 , 0 ) ;
if ( V_8 != 0 )
goto V_72;
V_8 = F_143 ( & V_291 ) ;
if ( V_8 != 0 )
goto V_292;
F_144 ( & V_293 ) ;
V_8 = F_145 ( & V_294 ) ;
if ( V_8 != 0 )
goto V_295;
F_146 ( V_296 L_8 ) ;
F_147 () ;
V_8 = F_148 () ;
if ( V_8 != 0 )
goto V_297;
V_72:
return V_8 ;
V_297:
F_149 ( & V_294 ) ;
V_295:
F_150 ( V_86 ) ;
V_292:
F_151 ( & V_88 ) ;
goto V_72;
}
static void T_4 F_152 ( void )
{
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
F_149 ( & V_294 ) ;
F_157 ( & V_293 ) ;
F_150 ( V_86 ) ;
F_151 ( & V_88 ) ;
}
