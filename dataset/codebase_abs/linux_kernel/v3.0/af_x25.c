int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned char V_6 ;
int V_7 ;
int V_8 ;
if ( V_2 -> V_6 < 1 ) {
V_8 = 0 ;
goto V_9;
}
V_6 = * V_2 -> V_10 ;
V_7 = 1 + ( V_6 >> 4 ) + ( V_6 & 0x0f ) ;
if ( V_2 -> V_6 < V_7 ) {
V_8 = - 1 ;
goto V_9;
}
return F_2 ( V_2 -> V_10 , V_4 , V_5 ) ;
V_9:
* V_4 -> V_11 = 0 ;
* V_5 -> V_11 = 0 ;
return V_8 ;
}
int F_2 ( unsigned char * V_12 , struct V_3 * V_4 ,
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
int F_3 ( unsigned char * V_12 , struct V_3 * V_4 ,
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
static void F_4 ( struct V_18 * V_19 )
{
F_5 ( & V_20 ) ;
F_6 ( V_19 ) ;
F_7 ( & V_20 ) ;
}
static void F_8 ( struct V_21 * V_22 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_5 ( & V_20 ) ;
F_9 (s, node, &x25_list)
if ( F_10 ( V_23 ) -> V_26 && F_10 ( V_23 ) -> V_26 -> V_22 == V_22 )
F_11 ( V_23 , V_27 , 0 , 0 ) ;
F_7 ( & V_20 ) ;
}
static int F_12 ( struct V_28 * V_29 , unsigned long V_30 ,
void * V_31 )
{
struct V_21 * V_22 = V_31 ;
struct V_32 * V_33 ;
if ( ! F_13 ( F_14 ( V_22 ) , & V_34 ) )
return V_35 ;
if ( V_22 -> type == V_36
#if F_15 ( V_37 ) || F_15 ( V_38 )
|| V_22 -> type == V_39
#endif
) {
switch ( V_30 ) {
case V_40 :
F_16 ( V_22 ) ;
break;
case V_41 :
V_33 = F_17 ( V_22 ) ;
if ( V_33 ) {
F_18 ( V_33 ) ;
F_19 ( V_33 ) ;
}
break;
case V_42 :
F_8 ( V_22 ) ;
F_20 ( V_22 ) ;
F_21 ( V_22 ) ;
break;
}
}
return V_35 ;
}
static void F_22 ( struct V_18 * V_19 )
{
F_5 ( & V_20 ) ;
F_23 ( V_19 , & V_43 ) ;
F_7 ( & V_20 ) ;
}
static struct V_18 * F_24 ( struct V_3 * V_44 ,
struct V_1 * V_2 )
{
struct V_18 * V_23 ;
struct V_18 * V_45 ;
struct V_24 * V_25 ;
F_25 ( & V_20 ) ;
V_45 = NULL ;
F_9 (s, node, &x25_list)
if ( ( ! strcmp ( V_44 -> V_11 ,
F_10 ( V_23 ) -> V_46 . V_11 ) ||
! strcmp ( V_44 -> V_11 ,
V_47 . V_11 ) ) &&
V_23 -> V_48 == V_49 ) {
if( V_2 -> V_6 > 0 && F_10 ( V_23 ) -> V_50 > 0 ) {
if( ( memcmp ( F_10 ( V_23 ) -> V_51 . V_52 ,
V_2 -> V_10 ,
F_10 ( V_23 ) -> V_50 ) ) == 0 ) {
F_26 ( V_23 ) ;
goto V_53;
}
} else
V_45 = V_23 ;
}
if ( V_45 ) {
V_23 = V_45 ;
F_26 ( V_23 ) ;
goto V_53;
}
V_23 = NULL ;
V_53:
F_27 ( & V_20 ) ;
return V_23 ;
}
static struct V_18 * F_28 ( unsigned int V_54 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_9 (s, node, &x25_list)
if ( F_10 ( V_23 ) -> V_54 == V_54 && F_10 ( V_23 ) -> V_26 == V_33 ) {
F_26 ( V_23 ) ;
goto V_53;
}
V_23 = NULL ;
V_53:
return V_23 ;
}
struct V_18 * F_29 ( unsigned int V_54 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
F_25 ( & V_20 ) ;
V_23 = F_28 ( V_54 , V_33 ) ;
F_27 ( & V_20 ) ;
return V_23 ;
}
static unsigned int F_30 ( struct V_32 * V_33 )
{
unsigned int V_54 = 1 ;
struct V_18 * V_19 ;
F_25 ( & V_20 ) ;
while ( ( V_19 = F_28 ( V_54 , V_33 ) ) != NULL ) {
F_31 ( V_19 ) ;
if ( ++ V_54 == 4096 ) {
V_54 = 0 ;
break;
}
}
F_27 ( & V_20 ) ;
return V_54 ;
}
static void F_32 ( unsigned long V_10 )
{
F_33 ( (struct V_18 * ) V_10 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_35 ( V_19 ) ;
F_36 ( V_19 ) ;
F_4 ( V_19 ) ;
F_37 ( V_19 ) ;
while ( ( V_2 = F_38 ( & V_19 -> V_55 ) ) != NULL ) {
if ( V_2 -> V_19 != V_19 ) {
V_2 -> V_19 -> V_48 = V_49 ;
F_39 ( V_2 -> V_19 , V_56 ) ;
F_40 ( V_2 -> V_19 ) ;
F_10 ( V_2 -> V_19 ) -> V_57 = V_58 ;
}
F_41 ( V_2 ) ;
}
if ( F_42 ( V_19 ) ) {
V_19 -> V_59 . V_60 = V_61 + 10 * V_62 ;
V_19 -> V_59 . V_63 = F_32 ;
V_19 -> V_59 . V_10 = ( unsigned long ) V_19 ;
F_43 ( & V_19 -> V_59 ) ;
} else {
F_44 ( V_19 ) ;
}
}
void F_33 ( struct V_18 * V_19 )
{
F_26 ( V_19 ) ;
F_45 ( V_19 ) ;
F_34 ( V_19 ) ;
F_46 ( V_19 ) ;
F_31 ( V_19 ) ;
}
static int F_47 ( struct V_64 * V_18 , int V_65 , int V_66 ,
char T_1 * V_67 , unsigned int V_68 )
{
int V_69 ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_70 ;
if ( V_65 != V_71 || V_66 != V_72 )
goto V_73;
V_8 = - V_74 ;
if ( V_68 < sizeof( int ) )
goto V_73;
V_8 = - V_75 ;
if ( F_48 ( V_69 , ( int T_1 * ) V_67 ) )
goto V_73;
if ( V_69 )
F_49 ( V_76 , & F_10 ( V_19 ) -> V_77 ) ;
else
F_50 ( V_76 , & F_10 ( V_19 ) -> V_77 ) ;
V_8 = 0 ;
V_73:
return V_8 ;
}
static int F_51 ( struct V_64 * V_18 , int V_65 , int V_66 ,
char T_1 * V_67 , int T_1 * V_68 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_78 , V_6 , V_8 = - V_70 ;
if ( V_65 != V_71 || V_66 != V_72 )
goto V_73;
V_8 = - V_75 ;
if ( F_48 ( V_6 , V_68 ) )
goto V_73;
V_6 = F_52 (unsigned int, len, sizeof(int)) ;
V_8 = - V_74 ;
if ( V_6 < 0 )
goto V_73;
V_8 = - V_75 ;
if ( F_53 ( V_6 , V_68 ) )
goto V_73;
V_78 = F_54 ( V_76 , & F_10 ( V_19 ) -> V_77 ) ;
V_8 = F_55 ( V_67 , & V_78 , V_6 ) ? - V_75 : 0 ;
V_73:
return V_8 ;
}
static int F_56 ( struct V_64 * V_18 , int V_79 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_80 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 ) {
memset ( & F_10 ( V_19 ) -> V_81 , 0 , V_82 ) ;
V_19 -> V_83 = V_79 ;
V_19 -> V_48 = V_49 ;
V_8 = 0 ;
}
F_58 ( V_19 ) ;
return V_8 ;
}
static struct V_18 * F_59 ( struct V_84 * V_84 )
{
struct V_85 * V_86 ;
struct V_18 * V_19 = F_60 ( V_84 , V_87 , V_88 , & V_89 ) ;
if ( ! V_19 )
goto V_73;
F_61 ( NULL , V_19 ) ;
V_86 = F_10 ( V_19 ) ;
F_62 ( & V_86 -> V_90 ) ;
F_62 ( & V_86 -> V_91 ) ;
F_62 ( & V_86 -> V_92 ) ;
F_62 ( & V_86 -> V_93 ) ;
V_73:
return V_19 ;
}
static int F_63 ( struct V_84 * V_84 , struct V_64 * V_18 , int V_94 ,
int V_95 )
{
struct V_18 * V_19 ;
struct V_85 * V_86 ;
int V_8 = - V_96 ;
if ( ! F_13 ( V_84 , & V_34 ) )
goto V_73;
V_8 = - V_97 ;
if ( V_18 -> type != V_98 )
goto V_73;
V_8 = - V_74 ;
if ( V_94 )
goto V_73;
V_8 = - V_99 ;
if ( ( V_19 = F_59 ( V_84 ) ) == NULL )
goto V_73;
V_86 = F_10 ( V_19 ) ;
F_61 ( V_18 , V_19 ) ;
F_64 ( V_19 ) ;
V_18 -> V_100 = & V_101 ;
V_19 -> V_102 = V_94 ;
V_19 -> V_103 = V_104 ;
V_86 -> V_105 = V_106 ;
V_86 -> V_107 = V_108 ;
V_86 -> V_109 = V_110 ;
V_86 -> V_111 = V_112 ;
V_86 -> V_57 = V_58 ;
V_86 -> V_50 = 0 ;
F_49 ( V_113 , & V_86 -> V_77 ) ;
V_86 -> V_114 . V_115 = V_116 ;
V_86 -> V_114 . V_117 = V_116 ;
V_86 -> V_114 . V_118 = V_119 ;
V_86 -> V_114 . V_120 = V_119 ;
V_86 -> V_114 . V_121 = 0 ;
V_86 -> V_114 . V_122 = V_123 ;
V_86 -> V_124 . V_14 = 0 ;
V_86 -> V_124 . V_13 = 0 ;
memset ( V_86 -> V_124 . V_125 , '\0' ,
sizeof( V_86 -> V_124 . V_125 ) ) ;
memset ( V_86 -> V_124 . V_126 , '\0' ,
sizeof( V_86 -> V_124 . V_126 ) ) ;
V_8 = 0 ;
V_73:
return V_8 ;
}
static struct V_18 * F_65 ( struct V_18 * V_127 )
{
struct V_18 * V_19 = NULL ;
struct V_85 * V_86 , * V_128 ;
if ( V_127 -> V_129 != V_98 )
goto V_73;
if ( ( V_19 = F_59 ( F_66 ( V_127 ) ) ) == NULL )
goto V_73;
V_86 = F_10 ( V_19 ) ;
V_19 -> V_129 = V_127 -> V_129 ;
V_19 -> V_130 = V_127 -> V_130 ;
V_19 -> V_102 = V_127 -> V_102 ;
V_19 -> V_131 = V_127 -> V_131 ;
V_19 -> V_132 = V_127 -> V_132 ;
V_19 -> V_48 = V_133 ;
V_19 -> V_103 = V_127 -> V_103 ;
F_67 ( V_19 , V_127 ) ;
V_128 = F_10 ( V_127 ) ;
V_86 -> V_105 = V_128 -> V_105 ;
V_86 -> V_107 = V_128 -> V_107 ;
V_86 -> V_109 = V_128 -> V_109 ;
V_86 -> V_111 = V_128 -> V_111 ;
V_86 -> V_77 = V_128 -> V_77 ;
V_86 -> V_114 = V_128 -> V_114 ;
V_86 -> V_124 = V_128 -> V_124 ;
V_86 -> V_50 = V_128 -> V_50 ;
F_50 ( V_134 , & V_86 -> V_77 ) ;
F_64 ( V_19 ) ;
V_73:
return V_19 ;
}
static int F_68 ( struct V_64 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 ;
if ( ! V_19 )
return 0 ;
V_86 = F_10 ( V_19 ) ;
F_26 ( V_19 ) ;
F_57 ( V_19 ) ;
switch ( V_86 -> V_57 ) {
case V_58 :
case V_135 :
F_11 ( V_19 , 0 , 0 , 0 ) ;
F_34 ( V_19 ) ;
goto V_73;
case V_136 :
case V_137 :
case V_138 :
F_37 ( V_19 ) ;
F_69 ( V_19 , V_139 ) ;
F_70 ( V_19 ) ;
V_86 -> V_57 = V_135 ;
V_19 -> V_48 = V_140 ;
V_19 -> V_141 |= V_142 ;
V_19 -> V_143 ( V_19 ) ;
F_39 ( V_19 , V_56 ) ;
F_39 ( V_19 , V_144 ) ;
break;
}
F_71 ( V_19 ) ;
V_73:
F_58 ( V_19 ) ;
F_31 ( V_19 ) ;
return 0 ;
}
static int F_72 ( struct V_64 * V_18 , struct V_145 * V_146 , int V_147 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_148 * V_44 = (struct V_148 * ) V_146 ;
int V_6 , V_17 , V_8 = 0 ;
if ( ! F_73 ( V_19 , V_149 ) ||
V_147 != sizeof( struct V_148 ) ||
V_44 -> V_150 != V_87 ) {
V_8 = - V_74 ;
goto V_73;
}
V_6 = strlen ( V_44 -> V_151 . V_11 ) ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
if ( ! isdigit ( V_44 -> V_151 . V_11 [ V_17 ] ) ) {
V_8 = - V_74 ;
goto V_73;
}
}
F_57 ( V_19 ) ;
F_10 ( V_19 ) -> V_46 = V_44 -> V_151 ;
F_22 ( V_19 ) ;
F_74 ( V_19 , V_149 ) ;
F_58 ( V_19 ) ;
F_75 ( V_19 , L_1 ) ;
V_73:
return V_8 ;
}
static int F_76 ( struct V_18 * V_19 )
{
F_77 ( V_152 , V_153 ) ;
int V_8 ;
F_78 ( F_79 ( V_19 ) , & V_152 ) ;
for (; ; ) {
F_80 ( V_154 ) ;
V_8 = - V_155 ;
if ( F_81 ( V_153 ) )
break;
V_8 = F_82 ( V_19 ) ;
if ( V_8 ) {
V_19 -> V_156 -> V_57 = V_157 ;
break;
}
V_8 = 0 ;
if ( V_19 -> V_48 != V_133 ) {
F_58 ( V_19 ) ;
F_83 () ;
F_57 ( V_19 ) ;
} else
break;
}
F_80 ( V_158 ) ;
F_84 ( F_79 ( V_19 ) , & V_152 ) ;
return V_8 ;
}
static int F_85 ( struct V_64 * V_18 , struct V_145 * V_146 ,
int V_147 , int V_77 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_10 ( V_19 ) ;
struct V_148 * V_44 = (struct V_148 * ) V_146 ;
struct V_159 * V_160 ;
int V_8 = 0 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 == V_133 && V_18 -> V_57 == V_161 ) {
V_18 -> V_57 = V_162 ;
goto V_73;
}
V_8 = - V_163 ;
if ( V_19 -> V_48 == V_140 && V_18 -> V_57 == V_161 ) {
V_18 -> V_57 = V_157 ;
goto V_73;
}
V_8 = - V_164 ;
if ( V_19 -> V_48 == V_133 )
goto V_73;
V_19 -> V_48 = V_140 ;
V_18 -> V_57 = V_157 ;
V_8 = - V_74 ;
if ( V_147 != sizeof( struct V_148 ) ||
V_44 -> V_150 != V_87 )
goto V_73;
V_8 = - V_27 ;
V_160 = F_86 ( & V_44 -> V_151 ) ;
if ( ! V_160 )
goto V_73;
V_86 -> V_26 = F_17 ( V_160 -> V_22 ) ;
if ( ! V_86 -> V_26 )
goto V_165;
F_87 ( & V_86 -> V_114 , V_86 -> V_26 ) ;
V_86 -> V_54 = F_30 ( V_86 -> V_26 ) ;
if ( ! V_86 -> V_54 )
goto V_166;
V_8 = - V_74 ;
if ( F_73 ( V_19 , V_149 ) )
goto V_166;
if ( ! strcmp ( V_86 -> V_46 . V_11 , V_47 . V_11 ) )
memset ( & V_86 -> V_46 , '\0' , V_82 ) ;
V_86 -> V_81 = V_44 -> V_151 ;
V_18 -> V_57 = V_161 ;
V_19 -> V_48 = V_167 ;
V_86 -> V_57 = V_136 ;
F_69 ( V_19 , V_168 ) ;
F_40 ( V_19 ) ;
F_88 ( V_19 ) ;
V_8 = - V_169 ;
if ( V_19 -> V_48 != V_133 && ( V_77 & V_170 ) )
goto V_166;
V_8 = F_76 ( V_19 ) ;
if ( V_8 )
goto V_166;
V_18 -> V_57 = V_162 ;
V_8 = 0 ;
V_166:
if ( V_8 )
F_19 ( V_86 -> V_26 ) ;
V_165:
F_89 ( V_160 ) ;
V_73:
F_58 ( V_19 ) ;
return V_8 ;
}
static int F_90 ( struct V_18 * V_19 , long V_171 )
{
F_77 ( V_152 , V_153 ) ;
int V_8 = 0 ;
F_78 ( F_79 ( V_19 ) , & V_152 ) ;
for (; ; ) {
F_80 ( V_154 ) ;
if ( V_19 -> V_141 & V_172 )
break;
V_8 = - V_155 ;
if ( F_81 ( V_153 ) )
break;
V_8 = - V_173 ;
if ( ! V_171 )
break;
V_8 = 0 ;
if ( F_91 ( & V_19 -> V_55 ) ) {
F_58 ( V_19 ) ;
V_171 = F_92 ( V_171 ) ;
F_57 ( V_19 ) ;
} else
break;
}
F_80 ( V_158 ) ;
F_84 ( F_79 ( V_19 ) , & V_152 ) ;
return V_8 ;
}
static int F_93 ( struct V_64 * V_18 , struct V_64 * V_174 , int V_77 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_18 * V_175 ;
struct V_1 * V_2 ;
int V_8 = - V_74 ;
if ( ! V_19 )
goto V_73;
V_8 = - V_80 ;
if ( V_19 -> V_129 != V_98 )
goto V_73;
F_57 ( V_19 ) ;
V_8 = - V_74 ;
if ( V_19 -> V_48 != V_49 )
goto V_176;
V_8 = F_90 ( V_19 , V_19 -> V_177 ) ;
if ( V_8 )
goto V_176;
V_2 = F_38 ( & V_19 -> V_55 ) ;
V_8 = - V_74 ;
if ( ! V_2 -> V_19 )
goto V_176;
V_175 = V_2 -> V_19 ;
F_94 ( V_175 , V_174 ) ;
V_2 -> V_19 = NULL ;
F_41 ( V_2 ) ;
V_19 -> V_178 -- ;
V_174 -> V_57 = V_162 ;
V_8 = 0 ;
V_176:
F_58 ( V_19 ) ;
V_73:
return V_8 ;
}
static int F_95 ( struct V_64 * V_18 , struct V_145 * V_146 ,
int * V_179 , int V_180 )
{
struct V_148 * V_181 = (struct V_148 * ) V_146 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_10 ( V_19 ) ;
int V_8 = 0 ;
if ( V_180 ) {
if ( V_19 -> V_48 != V_133 ) {
V_8 = - V_182 ;
goto V_73;
}
V_181 -> V_151 = V_86 -> V_81 ;
} else
V_181 -> V_151 = V_86 -> V_46 ;
V_181 -> V_150 = V_87 ;
* V_179 = sizeof( * V_181 ) ;
V_73:
return V_8 ;
}
int F_96 ( struct V_1 * V_2 , struct V_32 * V_33 ,
unsigned int V_54 )
{
struct V_18 * V_19 ;
struct V_18 * V_183 ;
struct V_85 * V_184 ;
struct V_3 V_46 , V_81 ;
struct V_185 V_114 ;
struct V_186 V_124 ;
int V_6 , V_147 , V_8 ;
F_97 ( V_2 , V_187 ) ;
V_147 = F_1 ( V_2 , & V_46 , & V_81 ) ;
if ( V_147 <= 0 )
goto V_188;
F_97 ( V_2 , V_147 ) ;
if ( V_2 -> V_6 < 1 )
goto V_188;
V_6 = V_2 -> V_10 [ 0 ] + 1 ;
if ( V_2 -> V_6 < V_6 )
goto V_188;
F_97 ( V_2 , V_6 ) ;
V_19 = F_24 ( & V_46 , V_2 ) ;
F_98 ( V_2 , V_6 ) ;
if ( V_19 != NULL && F_99 ( V_19 ) ) {
goto V_189;
}
if ( V_19 == NULL ) {
F_98 ( V_2 , V_147 + V_187 ) ;
if ( V_190 &&
F_100 ( & V_81 , V_33 , V_2 , V_54 ) > 0 )
{
F_41 ( V_2 ) ;
V_8 = 1 ;
goto V_73;
} else {
goto V_188;
}
}
V_6 = F_101 ( V_2 , V_19 , & V_114 , & V_124 ) ;
if ( V_6 == - 1 )
goto V_189;
F_87 ( & V_114 , V_33 ) ;
V_183 = F_65 ( V_19 ) ;
if ( ! V_183 )
goto V_189;
F_97 ( V_2 , V_6 ) ;
V_2 -> V_19 = V_183 ;
V_183 -> V_48 = V_133 ;
V_184 = F_10 ( V_183 ) ;
V_184 -> V_54 = V_54 ;
V_184 -> V_81 = V_81 ;
V_184 -> V_46 = V_46 ;
V_184 -> V_26 = V_33 ;
V_184 -> V_114 = V_114 ;
V_184 -> V_124 = V_124 ;
V_184 -> V_191 = F_10 ( V_19 ) -> V_191 ;
V_184 -> V_191 &= ~ V_192 ;
V_184 -> V_191 &= ~ V_193 ;
V_184 -> V_50 = F_10 ( V_19 ) -> V_50 ;
if ( F_54 ( V_113 , & V_184 -> V_77 ) ) {
F_69 ( V_183 , V_194 ) ;
V_184 -> V_57 = V_137 ;
}
F_102 ( V_2 , V_184 -> V_51 . V_52 , V_2 -> V_6 ) ;
V_184 -> V_51 . V_195 = V_2 -> V_6 ;
V_19 -> V_178 ++ ;
F_22 ( V_183 ) ;
F_103 ( & V_19 -> V_55 , V_2 ) ;
F_40 ( V_183 ) ;
if ( ! F_73 ( V_19 , V_56 ) )
V_19 -> V_196 ( V_19 , V_2 -> V_6 ) ;
V_8 = 1 ;
F_31 ( V_19 ) ;
V_73:
return V_8 ;
V_189:
F_31 ( V_19 ) ;
V_188:
V_8 = 0 ;
F_104 ( V_33 , V_54 , 0x01 ) ;
goto V_73;
}
static int F_105 ( struct V_197 * V_198 , struct V_64 * V_18 ,
struct V_199 * V_200 , T_2 V_6 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_10 ( V_19 ) ;
struct V_148 * V_201 = (struct V_148 * ) V_200 -> V_202 ;
struct V_148 V_181 ;
struct V_1 * V_2 ;
unsigned char * V_203 ;
int V_204 = V_200 -> V_205 & V_206 ;
T_2 V_207 ;
int V_208 = 0 , V_8 = - V_74 ;
F_57 ( V_19 ) ;
if ( V_200 -> V_205 & ~ ( V_206 | V_209 | V_210 | V_211 ) )
goto V_73;
if ( ! ( V_200 -> V_205 & ( V_210 | V_209 ) ) )
goto V_73;
V_8 = - V_212 ;
if ( F_73 ( V_19 , V_149 ) )
goto V_73;
V_8 = - V_213 ;
if ( V_19 -> V_141 & V_142 ) {
F_106 ( V_214 , V_153 , 0 ) ;
goto V_73;
}
V_8 = - V_27 ;
if ( ! V_86 -> V_26 )
goto V_73;
if ( V_201 ) {
V_8 = - V_74 ;
if ( V_200 -> V_215 < sizeof( V_181 ) )
goto V_73;
memcpy ( & V_181 , V_201 , sizeof( V_181 ) ) ;
V_8 = - V_164 ;
if ( strcmp ( V_86 -> V_81 . V_11 , V_181 . V_151 . V_11 ) )
goto V_73;
V_8 = - V_74 ;
if ( V_181 . V_150 != V_87 )
goto V_73;
} else {
V_8 = - V_182 ;
if ( V_19 -> V_48 != V_133 )
goto V_73;
V_181 . V_150 = V_87 ;
V_181 . V_151 = V_86 -> V_81 ;
}
if ( V_6 > 65535 ) {
V_8 = - V_216 ;
goto V_73;
}
F_75 ( V_19 , L_2 ) ;
F_75 ( V_19 , L_3 ) ;
if ( ( V_200 -> V_205 & V_209 ) && V_6 > 32 )
V_6 = 32 ;
V_207 = V_6 + V_217 + V_218 ;
F_58 ( V_19 ) ;
V_2 = F_107 ( V_19 , V_207 , V_204 , & V_8 ) ;
F_57 ( V_19 ) ;
if ( ! V_2 )
goto V_73;
F_108 ( V_2 ) -> V_77 = V_200 -> V_205 ;
F_109 ( V_2 , V_217 + V_218 ) ;
F_75 ( V_19 , L_4 ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 , V_6 ) ;
V_8 = F_112 ( F_113 ( V_2 ) , V_200 -> V_219 , V_6 ) ;
if ( V_8 )
goto V_220;
if ( F_54 ( V_76 , & V_86 -> V_77 ) ) {
V_208 = V_2 -> V_10 [ 0 ] ;
F_97 ( V_2 , 1 ) ;
}
F_75 ( V_19 , L_5 ) ;
if ( V_200 -> V_205 & V_209 ) {
if ( V_86 -> V_26 -> V_221 ) {
V_203 = F_98 ( V_2 , V_187 ) ;
* V_203 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_222 ;
* V_203 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_203 ++ = V_223 ;
} else {
V_203 = F_98 ( V_2 , V_187 ) ;
* V_203 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_224 ;
* V_203 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_203 ++ = V_223 ;
}
} else {
if ( V_86 -> V_26 -> V_221 ) {
V_203 = F_98 ( V_2 , V_218 ) ;
* V_203 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_222 ;
* V_203 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_203 ++ = V_225 ;
* V_203 ++ = V_225 ;
} else {
V_203 = F_98 ( V_2 , V_187 ) ;
* V_203 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_224 ;
* V_203 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_203 ++ = V_225 ;
}
if ( V_208 )
V_2 -> V_10 [ 0 ] |= V_226 ;
}
F_75 ( V_19 , L_6 ) ;
F_75 ( V_19 , L_7 ) ;
V_8 = - V_182 ;
if ( V_19 -> V_48 != V_133 )
goto V_220;
if ( V_200 -> V_205 & V_209 )
F_114 ( & V_86 -> V_93 , V_2 ) ;
else {
V_8 = F_115 ( V_19 , V_2 ) ;
V_6 = V_8 ;
if ( V_8 < 0 )
F_41 ( V_2 ) ;
else if ( F_54 ( V_76 , & V_86 -> V_77 ) )
V_6 ++ ;
}
F_116 ( V_19 ) ;
V_8 = V_6 ;
V_73:
F_58 ( V_19 ) ;
return V_8 ;
V_220:
F_41 ( V_2 ) ;
goto V_73;
}
static int F_117 ( struct V_197 * V_198 , struct V_64 * V_18 ,
struct V_199 * V_200 , T_2 V_207 ,
int V_77 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_10 ( V_19 ) ;
struct V_148 * V_181 = (struct V_148 * ) V_200 -> V_202 ;
T_2 V_227 ;
int V_208 ;
struct V_1 * V_2 ;
unsigned char * V_203 ;
int V_8 = - V_182 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_133 )
goto V_73;
if ( V_77 & V_209 ) {
V_8 = - V_74 ;
if ( F_73 ( V_19 , V_228 ) ||
! F_118 ( & V_86 -> V_92 ) )
goto V_73;
V_2 = F_38 ( & V_86 -> V_92 ) ;
F_97 ( V_2 , V_187 ) ;
if ( F_54 ( V_76 , & V_86 -> V_77 ) ) {
V_203 = F_98 ( V_2 , 1 ) ;
* V_203 = 0x00 ;
}
V_200 -> V_205 |= V_209 ;
} else {
F_58 ( V_19 ) ;
V_2 = F_119 ( V_19 , V_77 & ~ V_206 ,
V_77 & V_206 , & V_8 ) ;
F_57 ( V_19 ) ;
if ( ! V_2 )
goto V_73;
V_208 = ( V_2 -> V_10 [ 0 ] & V_226 ) == V_226 ;
F_97 ( V_2 , V_86 -> V_26 -> V_221 ?
V_218 : V_187 ) ;
if ( F_54 ( V_76 , & V_86 -> V_77 ) ) {
V_203 = F_98 ( V_2 , 1 ) ;
* V_203 = V_208 ;
}
}
F_110 ( V_2 ) ;
V_227 = V_2 -> V_6 ;
if ( V_227 > V_207 ) {
V_227 = V_207 ;
V_200 -> V_205 |= V_229 ;
}
V_200 -> V_205 |= V_210 ;
V_8 = F_120 ( V_2 , 0 , V_200 -> V_219 , V_227 ) ;
if ( V_8 )
goto V_230;
if ( V_181 ) {
V_181 -> V_150 = V_87 ;
V_181 -> V_151 = V_86 -> V_81 ;
}
V_200 -> V_215 = sizeof( struct V_148 ) ;
F_121 ( V_19 ) ;
V_8 = V_227 ;
V_230:
F_122 ( V_19 , V_2 ) ;
V_73:
F_58 ( V_19 ) ;
return V_8 ;
}
static int F_123 ( struct V_64 * V_18 , unsigned int V_231 , unsigned long V_232 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_10 ( V_19 ) ;
void T_1 * V_233 = ( void T_1 * ) V_232 ;
int V_8 ;
switch ( V_231 ) {
case V_234 : {
int V_235 ;
V_235 = V_19 -> V_132 - F_124 ( V_19 ) ;
if ( V_235 < 0 )
V_235 = 0 ;
V_8 = F_53 ( V_235 , ( unsigned int T_1 * ) V_233 ) ;
break;
}
case V_236 : {
struct V_1 * V_2 ;
int V_235 = 0 ;
F_57 ( V_19 ) ;
if ( ( V_2 = F_118 ( & V_19 -> V_55 ) ) != NULL )
V_235 = V_2 -> V_6 ;
F_58 ( V_19 ) ;
V_8 = F_53 ( V_235 , ( unsigned int T_1 * ) V_233 ) ;
break;
}
case V_237 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_125 ( V_19 ,
(struct V_238 T_1 * ) V_233 ) ;
break;
case V_239 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_126 ( V_19 ,
(struct V_240 T_1 * ) V_233 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_8 = - V_74 ;
break;
case V_251 :
case V_252 :
V_8 = - V_253 ;
if ( ! F_127 ( V_254 ) )
break;
V_8 = F_128 ( V_231 , V_233 ) ;
break;
case V_255 :
V_8 = F_129 ( V_231 , V_233 ) ;
break;
case V_256 :
V_8 = - V_253 ;
if ( ! F_127 ( V_254 ) )
break;
V_8 = F_129 ( V_231 , V_233 ) ;
break;
case V_257 : {
F_57 ( V_19 ) ;
V_8 = F_55 ( V_233 , & V_86 -> V_114 ,
sizeof( V_86 -> V_114 ) )
? - V_75 : 0 ;
F_58 ( V_19 ) ;
break;
}
case V_258 : {
struct V_185 V_114 ;
V_8 = - V_75 ;
if ( F_130 ( & V_114 , V_233 ,
sizeof( V_114 ) ) )
break;
V_8 = - V_74 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 &&
V_19 -> V_48 != V_140 )
goto V_259;
if ( V_114 . V_118 < V_260 ||
V_114 . V_118 > V_261 )
goto V_259;
if ( V_114 . V_120 < V_260 ||
V_114 . V_120 > V_261 )
goto V_259;
if ( V_114 . V_115 < 1 ||
V_114 . V_115 > 127 )
goto V_259;
if ( V_114 . V_121 ) {
int V_73 = V_114 . V_121 & 0xf0 ;
int V_262 = V_114 . V_121 & 0x0f ;
if ( ! V_73 )
V_114 . V_121 |=
V_263 << 4 ;
else if ( V_73 < 0x30 || V_73 > 0xD0 )
goto V_259;
if ( ! V_262 )
V_114 . V_121 |=
V_263 ;
else if ( V_262 < 0x03 || V_262 > 0x0D )
goto V_259;
}
if ( V_114 . V_122 &&
( V_114 . V_122 & 0x81 ) != 0x81 )
goto V_259;
V_86 -> V_114 = V_114 ;
V_8 = 0 ;
V_259:
F_58 ( V_19 ) ;
break;
}
case V_264 : {
F_57 ( V_19 ) ;
V_8 = F_55 ( V_233 , & V_86 -> V_124 ,
sizeof( V_86 -> V_124 ) ) ;
F_58 ( V_19 ) ;
if ( V_8 )
V_8 = - V_75 ;
break;
}
case V_265 : {
struct V_186 V_266 ;
V_8 = - V_75 ;
if ( F_130 ( & V_266 , V_233 , sizeof( V_266 ) ) )
break;
V_8 = - V_74 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 &&
V_19 -> V_48 != V_140 )
goto V_267;
if ( V_266 . V_14 > V_268 )
goto V_267;
if ( V_266 . V_126 == NULL )
goto V_267;
if ( V_266 . V_13 > V_268 )
goto V_267;
if ( V_266 . V_125 == NULL )
goto V_267;
V_86 -> V_124 = V_266 ;
V_8 = 0 ;
V_267:
F_58 ( V_19 ) ;
break;
}
case V_269 : {
F_57 ( V_19 ) ;
V_8 = F_55 ( V_233 , & V_86 -> V_51 ,
sizeof( V_86 -> V_51 ) )
? - V_75 : 0 ;
F_58 ( V_19 ) ;
break;
}
case V_270 : {
struct V_271 V_51 ;
V_8 = - V_75 ;
if ( F_130 ( & V_51 , V_233 ,
sizeof( V_51 ) ) )
break;
V_8 = - V_74 ;
if ( V_51 . V_195 > V_272 )
break;
F_57 ( V_19 ) ;
V_86 -> V_51 = V_51 ;
F_58 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_273 : {
F_57 ( V_19 ) ;
V_8 = F_55 ( V_233 , & V_86 -> V_274 ,
sizeof( V_86 -> V_274 ) )
? - V_75 : 0 ;
F_58 ( V_19 ) ;
break;
}
case V_275 : {
struct V_276 V_274 ;
V_8 = - V_75 ;
if ( F_130 ( & V_274 , V_233 , sizeof( V_274 ) ) )
break;
F_57 ( V_19 ) ;
V_86 -> V_274 = V_274 ;
F_58 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_277 : {
struct V_278 V_279 ;
V_8 = - V_74 ;
F_57 ( V_19 ) ;
if( V_19 -> V_48 != V_140 )
goto V_280;
V_8 = - V_75 ;
if ( F_130 ( & V_279 , V_233 ,
sizeof( V_279 ) ) )
goto V_280;
V_8 = - V_74 ;
if( V_279 . V_50 > V_272 )
goto V_280;
V_86 -> V_50 = V_279 . V_50 ;
V_8 = 0 ;
V_280:
F_58 ( V_19 ) ;
break;
}
case V_281 : {
V_8 = - V_74 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_140 )
break;
F_50 ( V_113 , & V_86 -> V_77 ) ;
F_58 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_282 : {
V_8 = - V_74 ;
F_57 ( V_19 ) ;
if ( V_19 -> V_48 != V_133 )
break;
if ( F_54 ( V_113 , & V_86 -> V_77 ) )
break;
F_69 ( V_19 , V_194 ) ;
V_86 -> V_57 = V_137 ;
F_58 ( V_19 ) ;
V_8 = 0 ;
break;
}
default:
V_8 = - V_283 ;
break;
}
return V_8 ;
}
static int F_131 ( unsigned int V_231 ,
struct V_284 T_1 * V_285 )
{
struct V_284 V_286 ;
struct V_32 * V_33 ;
struct V_21 * V_22 ;
int V_8 = - V_74 ;
V_8 = - V_75 ;
if ( F_130 ( & V_286 , V_285 , sizeof( * V_285 ) ) )
goto V_73;
V_8 = - V_74 ;
V_22 = F_132 ( V_286 . V_287 ) ;
if ( V_22 == NULL )
goto V_73;
V_33 = F_17 ( V_22 ) ;
if ( V_33 == NULL )
goto V_288;
F_133 ( V_22 ) ;
if ( V_231 == V_255 ) {
F_25 ( & V_289 ) ;
V_286 . V_221 = V_33 -> V_221 ;
V_286 . V_290 = V_33 -> V_290 ;
F_27 ( & V_289 ) ;
V_8 = F_55 ( V_285 , & V_286 ,
sizeof( * V_285 ) ) ? - V_75 : 0 ;
} else {
V_8 = - V_74 ;
if ( V_286 . V_221 == 0 || V_286 . V_221 == 1 ) {
V_8 = 0 ;
F_5 ( & V_289 ) ;
V_33 -> V_221 = V_286 . V_221 ;
V_33 -> V_290 = V_286 . V_290 ;
F_7 ( & V_289 ) ;
}
}
F_19 ( V_33 ) ;
V_73:
return V_8 ;
V_288:
F_133 ( V_22 ) ;
goto V_73;
}
static int F_134 ( struct V_64 * V_18 , unsigned int V_231 ,
unsigned long V_232 )
{
void T_1 * V_233 = F_135 ( V_232 ) ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_283 ;
switch( V_231 ) {
case V_234 :
case V_236 :
V_8 = F_123 ( V_18 , V_231 , ( unsigned long ) V_233 ) ;
break;
case V_237 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_136 ( V_19 ,
(struct V_238 T_1 * ) V_233 ) ;
break;
case V_239 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_137 ( V_19 ,
(struct V_240 T_1 * ) V_233 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_8 = - V_74 ;
break;
case V_251 :
case V_252 :
V_8 = - V_253 ;
if ( ! F_127 ( V_254 ) )
break;
V_8 = F_128 ( V_231 , V_233 ) ;
break;
case V_255 :
V_8 = F_131 ( V_231 , V_233 ) ;
break;
case V_256 :
V_8 = - V_253 ;
if ( ! F_127 ( V_254 ) )
break;
V_8 = F_131 ( V_231 , V_233 ) ;
break;
case V_257 :
case V_258 :
case V_264 :
case V_265 :
case V_269 :
case V_270 :
case V_273 :
case V_275 :
case V_277 :
case V_281 :
case V_282 :
V_8 = F_123 ( V_18 , V_231 , ( unsigned long ) V_233 ) ;
break;
default:
V_8 = - V_283 ;
break;
}
return V_8 ;
}
void F_138 ( struct V_32 * V_33 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_5 ( & V_20 ) ;
F_9 (s, node, &x25_list)
if ( F_10 ( V_23 ) -> V_26 == V_33 )
F_11 ( V_23 , V_27 , 0 , 0 ) ;
F_7 ( & V_20 ) ;
F_139 ( V_33 -> V_22 ) ;
}
static int T_3 F_140 ( void )
{
int V_8 = F_141 ( & V_89 , 0 ) ;
if ( V_8 != 0 )
goto V_73;
V_8 = F_142 ( & V_291 ) ;
if ( V_8 != 0 )
goto V_292;
F_143 ( & V_293 ) ;
V_8 = F_144 ( & V_294 ) ;
if ( V_8 != 0 )
goto V_295;
F_145 ( V_296 L_8 ) ;
F_146 () ;
V_8 = F_147 () ;
if ( V_8 != 0 )
goto V_297;
V_73:
return V_8 ;
V_297:
F_148 ( & V_294 ) ;
V_295:
F_149 ( V_87 ) ;
V_292:
F_150 ( & V_89 ) ;
goto V_73;
}
static void T_4 F_151 ( void )
{
F_152 () ;
F_153 () ;
F_154 () ;
F_155 () ;
F_148 ( & V_294 ) ;
F_156 ( & V_293 ) ;
F_149 ( V_87 ) ;
F_150 ( & V_89 ) ;
}
