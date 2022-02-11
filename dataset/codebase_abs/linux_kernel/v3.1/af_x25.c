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
#if F_16 ( V_37 ) || F_16 ( V_38 )
|| V_22 -> type == V_39
#endif
) {
switch ( V_30 ) {
case V_40 :
F_17 ( V_22 ) ;
break;
case V_41 :
V_33 = F_18 ( V_22 ) ;
if ( V_33 ) {
F_19 ( V_33 ) ;
F_20 ( V_33 ) ;
}
break;
case V_42 :
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
F_24 ( V_19 , & V_43 ) ;
F_8 ( & V_20 ) ;
}
static struct V_18 * F_25 ( struct V_3 * V_44 ,
struct V_1 * V_2 )
{
struct V_18 * V_23 ;
struct V_18 * V_45 ;
struct V_24 * V_25 ;
F_26 ( & V_20 ) ;
V_45 = NULL ;
F_10 (s, node, &x25_list)
if ( ( ! strcmp ( V_44 -> V_11 ,
F_11 ( V_23 ) -> V_46 . V_11 ) ||
! strcmp ( V_44 -> V_11 ,
V_47 . V_11 ) ) &&
V_23 -> V_48 == V_49 ) {
if ( F_11 ( V_23 ) -> V_50 > 0 &&
V_2 -> V_6 >= F_11 ( V_23 ) -> V_50 ) {
if( ( memcmp ( F_11 ( V_23 ) -> V_51 . V_52 ,
V_2 -> V_10 ,
F_11 ( V_23 ) -> V_50 ) ) == 0 ) {
F_27 ( V_23 ) ;
goto V_53;
}
} else
V_45 = V_23 ;
}
if ( V_45 ) {
V_23 = V_45 ;
F_27 ( V_23 ) ;
goto V_53;
}
V_23 = NULL ;
V_53:
F_28 ( & V_20 ) ;
return V_23 ;
}
static struct V_18 * F_29 ( unsigned int V_54 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_10 (s, node, &x25_list)
if ( F_11 ( V_23 ) -> V_54 == V_54 && F_11 ( V_23 ) -> V_26 == V_33 ) {
F_27 ( V_23 ) ;
goto V_53;
}
V_23 = NULL ;
V_53:
return V_23 ;
}
struct V_18 * F_30 ( unsigned int V_54 , struct V_32 * V_33 )
{
struct V_18 * V_23 ;
F_26 ( & V_20 ) ;
V_23 = F_29 ( V_54 , V_33 ) ;
F_28 ( & V_20 ) ;
return V_23 ;
}
static unsigned int F_31 ( struct V_32 * V_33 )
{
unsigned int V_54 = 1 ;
struct V_18 * V_19 ;
F_26 ( & V_20 ) ;
while ( ( V_19 = F_29 ( V_54 , V_33 ) ) != NULL ) {
F_32 ( V_19 ) ;
if ( ++ V_54 == 4096 ) {
V_54 = 0 ;
break;
}
}
F_28 ( & V_20 ) ;
return V_54 ;
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
while ( ( V_2 = F_39 ( & V_19 -> V_55 ) ) != NULL ) {
if ( V_2 -> V_19 != V_19 ) {
V_2 -> V_19 -> V_48 = V_49 ;
F_40 ( V_2 -> V_19 , V_56 ) ;
F_41 ( V_2 -> V_19 ) ;
F_11 ( V_2 -> V_19 ) -> V_57 = V_58 ;
}
F_42 ( V_2 ) ;
}
if ( F_43 ( V_19 ) ) {
V_19 -> V_59 . V_60 = V_61 + 10 * V_62 ;
V_19 -> V_59 . V_63 = F_33 ;
V_19 -> V_59 . V_10 = ( unsigned long ) V_19 ;
F_44 ( & V_19 -> V_59 ) ;
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
static int F_48 ( struct V_64 * V_18 , int V_65 , int V_66 ,
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
if ( F_49 ( V_69 , ( int T_1 * ) V_67 ) )
goto V_73;
if ( V_69 )
F_50 ( V_76 , & F_11 ( V_19 ) -> V_77 ) ;
else
F_51 ( V_76 , & F_11 ( V_19 ) -> V_77 ) ;
V_8 = 0 ;
V_73:
return V_8 ;
}
static int F_52 ( struct V_64 * V_18 , int V_65 , int V_66 ,
char T_1 * V_67 , int T_1 * V_68 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_78 , V_6 , V_8 = - V_70 ;
if ( V_65 != V_71 || V_66 != V_72 )
goto V_73;
V_8 = - V_75 ;
if ( F_49 ( V_6 , V_68 ) )
goto V_73;
V_6 = F_53 (unsigned int, len, sizeof(int)) ;
V_8 = - V_74 ;
if ( V_6 < 0 )
goto V_73;
V_8 = - V_75 ;
if ( F_54 ( V_6 , V_68 ) )
goto V_73;
V_78 = F_55 ( V_76 , & F_11 ( V_19 ) -> V_77 ) ;
V_8 = F_56 ( V_67 , & V_78 , V_6 ) ? - V_75 : 0 ;
V_73:
return V_8 ;
}
static int F_57 ( struct V_64 * V_18 , int V_79 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_80 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 ) {
memset ( & F_11 ( V_19 ) -> V_81 , 0 , V_82 ) ;
V_19 -> V_83 = V_79 ;
V_19 -> V_48 = V_49 ;
V_8 = 0 ;
}
F_59 ( V_19 ) ;
return V_8 ;
}
static struct V_18 * F_60 ( struct V_84 * V_84 )
{
struct V_85 * V_86 ;
struct V_18 * V_19 = F_61 ( V_84 , V_87 , V_88 , & V_89 ) ;
if ( ! V_19 )
goto V_73;
F_62 ( NULL , V_19 ) ;
V_86 = F_11 ( V_19 ) ;
F_63 ( & V_86 -> V_90 ) ;
F_63 ( & V_86 -> V_91 ) ;
F_63 ( & V_86 -> V_92 ) ;
F_63 ( & V_86 -> V_93 ) ;
V_73:
return V_19 ;
}
static int F_64 ( struct V_84 * V_84 , struct V_64 * V_18 , int V_94 ,
int V_95 )
{
struct V_18 * V_19 ;
struct V_85 * V_86 ;
int V_8 = - V_96 ;
if ( ! F_14 ( V_84 , & V_34 ) )
goto V_73;
V_8 = - V_97 ;
if ( V_18 -> type != V_98 )
goto V_73;
V_8 = - V_74 ;
if ( V_94 )
goto V_73;
V_8 = - V_99 ;
if ( ( V_19 = F_60 ( V_84 ) ) == NULL )
goto V_73;
V_86 = F_11 ( V_19 ) ;
F_62 ( V_18 , V_19 ) ;
F_65 ( V_19 ) ;
V_18 -> V_100 = & V_101 ;
V_19 -> V_102 = V_94 ;
V_19 -> V_103 = V_104 ;
V_86 -> V_105 = V_106 ;
V_86 -> V_107 = V_108 ;
V_86 -> V_109 = V_110 ;
V_86 -> V_111 = V_112 ;
V_86 -> V_57 = V_58 ;
V_86 -> V_50 = 0 ;
F_50 ( V_113 , & V_86 -> V_77 ) ;
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
static struct V_18 * F_66 ( struct V_18 * V_127 )
{
struct V_18 * V_19 = NULL ;
struct V_85 * V_86 , * V_128 ;
if ( V_127 -> V_129 != V_98 )
goto V_73;
if ( ( V_19 = F_60 ( F_67 ( V_127 ) ) ) == NULL )
goto V_73;
V_86 = F_11 ( V_19 ) ;
V_19 -> V_129 = V_127 -> V_129 ;
V_19 -> V_130 = V_127 -> V_130 ;
V_19 -> V_102 = V_127 -> V_102 ;
V_19 -> V_131 = V_127 -> V_131 ;
V_19 -> V_132 = V_127 -> V_132 ;
V_19 -> V_48 = V_133 ;
V_19 -> V_103 = V_127 -> V_103 ;
F_68 ( V_19 , V_127 ) ;
V_128 = F_11 ( V_127 ) ;
V_86 -> V_105 = V_128 -> V_105 ;
V_86 -> V_107 = V_128 -> V_107 ;
V_86 -> V_109 = V_128 -> V_109 ;
V_86 -> V_111 = V_128 -> V_111 ;
V_86 -> V_77 = V_128 -> V_77 ;
V_86 -> V_114 = V_128 -> V_114 ;
V_86 -> V_124 = V_128 -> V_124 ;
V_86 -> V_50 = V_128 -> V_50 ;
F_51 ( V_134 , & V_86 -> V_77 ) ;
F_65 ( V_19 ) ;
V_73:
return V_19 ;
}
static int F_69 ( struct V_64 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 ;
if ( ! V_19 )
return 0 ;
V_86 = F_11 ( V_19 ) ;
F_27 ( V_19 ) ;
F_58 ( V_19 ) ;
switch ( V_86 -> V_57 ) {
case V_58 :
case V_135 :
F_12 ( V_19 , 0 , 0 , 0 ) ;
F_35 ( V_19 ) ;
goto V_73;
case V_136 :
case V_137 :
case V_138 :
F_38 ( V_19 ) ;
F_70 ( V_19 , V_139 ) ;
F_71 ( V_19 ) ;
V_86 -> V_57 = V_135 ;
V_19 -> V_48 = V_140 ;
V_19 -> V_141 |= V_142 ;
V_19 -> V_143 ( V_19 ) ;
F_40 ( V_19 , V_56 ) ;
F_40 ( V_19 , V_144 ) ;
break;
}
F_72 ( V_19 ) ;
V_73:
F_59 ( V_19 ) ;
F_32 ( V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_64 * V_18 , struct V_145 * V_146 , int V_147 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_148 * V_44 = (struct V_148 * ) V_146 ;
int V_6 , V_17 , V_8 = 0 ;
if ( ! F_74 ( V_19 , V_149 ) ||
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
F_58 ( V_19 ) ;
F_11 ( V_19 ) -> V_46 = V_44 -> V_151 ;
F_23 ( V_19 ) ;
F_75 ( V_19 , V_149 ) ;
F_59 ( V_19 ) ;
F_76 ( V_19 , L_1 ) ;
V_73:
return V_8 ;
}
static int F_77 ( struct V_18 * V_19 )
{
F_78 ( V_152 , V_153 ) ;
int V_8 ;
F_79 ( F_80 ( V_19 ) , & V_152 ) ;
for (; ; ) {
F_81 ( V_154 ) ;
V_8 = - V_155 ;
if ( F_82 ( V_153 ) )
break;
V_8 = F_83 ( V_19 ) ;
if ( V_8 ) {
V_19 -> V_156 -> V_57 = V_157 ;
break;
}
V_8 = 0 ;
if ( V_19 -> V_48 != V_133 ) {
F_59 ( V_19 ) ;
F_84 () ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_158 ) ;
F_85 ( F_80 ( V_19 ) , & V_152 ) ;
return V_8 ;
}
static int F_86 ( struct V_64 * V_18 , struct V_145 * V_146 ,
int V_147 , int V_77 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_11 ( V_19 ) ;
struct V_148 * V_44 = (struct V_148 * ) V_146 ;
struct V_159 * V_160 ;
int V_8 = 0 ;
F_58 ( V_19 ) ;
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
V_160 = F_87 ( & V_44 -> V_151 ) ;
if ( ! V_160 )
goto V_73;
V_86 -> V_26 = F_18 ( V_160 -> V_22 ) ;
if ( ! V_86 -> V_26 )
goto V_165;
F_88 ( & V_86 -> V_114 , V_86 -> V_26 ) ;
V_86 -> V_54 = F_31 ( V_86 -> V_26 ) ;
if ( ! V_86 -> V_54 )
goto V_166;
V_8 = - V_74 ;
if ( F_74 ( V_19 , V_149 ) )
goto V_166;
if ( ! strcmp ( V_86 -> V_46 . V_11 , V_47 . V_11 ) )
memset ( & V_86 -> V_46 , '\0' , V_82 ) ;
V_86 -> V_81 = V_44 -> V_151 ;
V_18 -> V_57 = V_161 ;
V_19 -> V_48 = V_167 ;
V_86 -> V_57 = V_136 ;
F_70 ( V_19 , V_168 ) ;
F_41 ( V_19 ) ;
F_89 ( V_19 ) ;
V_8 = - V_169 ;
if ( V_19 -> V_48 != V_133 && ( V_77 & V_170 ) )
goto V_166;
V_8 = F_77 ( V_19 ) ;
if ( V_8 )
goto V_166;
V_18 -> V_57 = V_162 ;
V_8 = 0 ;
V_166:
if ( V_8 )
F_20 ( V_86 -> V_26 ) ;
V_165:
F_90 ( V_160 ) ;
V_73:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_91 ( struct V_18 * V_19 , long V_171 )
{
F_78 ( V_152 , V_153 ) ;
int V_8 = 0 ;
F_79 ( F_80 ( V_19 ) , & V_152 ) ;
for (; ; ) {
F_81 ( V_154 ) ;
if ( V_19 -> V_141 & V_172 )
break;
V_8 = - V_155 ;
if ( F_82 ( V_153 ) )
break;
V_8 = - V_173 ;
if ( ! V_171 )
break;
V_8 = 0 ;
if ( F_92 ( & V_19 -> V_55 ) ) {
F_59 ( V_19 ) ;
V_171 = F_93 ( V_171 ) ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_158 ) ;
F_85 ( F_80 ( V_19 ) , & V_152 ) ;
return V_8 ;
}
static int F_94 ( struct V_64 * V_18 , struct V_64 * V_174 , int V_77 )
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
F_58 ( V_19 ) ;
V_8 = - V_74 ;
if ( V_19 -> V_48 != V_49 )
goto V_176;
V_8 = F_91 ( V_19 , V_19 -> V_177 ) ;
if ( V_8 )
goto V_176;
V_2 = F_39 ( & V_19 -> V_55 ) ;
V_8 = - V_74 ;
if ( ! V_2 -> V_19 )
goto V_176;
V_175 = V_2 -> V_19 ;
F_95 ( V_175 , V_174 ) ;
V_2 -> V_19 = NULL ;
F_42 ( V_2 ) ;
V_19 -> V_178 -- ;
V_174 -> V_57 = V_162 ;
V_8 = 0 ;
V_176:
F_59 ( V_19 ) ;
V_73:
return V_8 ;
}
static int F_96 ( struct V_64 * V_18 , struct V_145 * V_146 ,
int * V_179 , int V_180 )
{
struct V_148 * V_181 = (struct V_148 * ) V_146 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_11 ( V_19 ) ;
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
int F_97 ( struct V_1 * V_2 , struct V_32 * V_33 ,
unsigned int V_54 )
{
struct V_18 * V_19 ;
struct V_18 * V_183 ;
struct V_85 * V_184 ;
struct V_3 V_46 , V_81 ;
struct V_185 V_114 ;
struct V_186 V_124 ;
int V_6 , V_147 , V_8 ;
F_98 ( V_2 , V_187 ) ;
V_147 = F_1 ( V_2 , & V_46 , & V_81 ) ;
if ( V_147 <= 0 )
goto V_188;
F_98 ( V_2 , V_147 ) ;
if ( ! F_2 ( V_2 , 1 ) )
goto V_188;
V_6 = V_2 -> V_10 [ 0 ] + 1 ;
if ( ! F_2 ( V_2 , V_6 ) )
goto V_188;
F_98 ( V_2 , V_6 ) ;
if ( V_2 -> V_6 > V_189 )
goto V_188;
if ( ! F_2 ( V_2 , V_2 -> V_6 ) )
goto V_188;
V_19 = F_25 ( & V_46 , V_2 ) ;
F_99 ( V_2 , V_6 ) ;
if ( V_19 != NULL && F_100 ( V_19 ) ) {
goto V_190;
}
if ( V_19 == NULL ) {
F_99 ( V_2 , V_147 + V_187 ) ;
if ( V_191 &&
F_101 ( & V_81 , V_33 , V_2 , V_54 ) > 0 )
{
F_42 ( V_2 ) ;
V_8 = 1 ;
goto V_73;
} else {
goto V_188;
}
}
V_6 = F_102 ( V_2 , V_19 , & V_114 , & V_124 ) ;
if ( V_6 == - 1 )
goto V_190;
F_88 ( & V_114 , V_33 ) ;
V_183 = F_66 ( V_19 ) ;
if ( ! V_183 )
goto V_190;
F_98 ( V_2 , V_6 ) ;
V_2 -> V_19 = V_183 ;
V_183 -> V_48 = V_133 ;
V_184 = F_11 ( V_183 ) ;
V_184 -> V_54 = V_54 ;
V_184 -> V_81 = V_81 ;
V_184 -> V_46 = V_46 ;
V_184 -> V_26 = V_33 ;
V_184 -> V_114 = V_114 ;
V_184 -> V_124 = V_124 ;
V_184 -> V_192 = F_11 ( V_19 ) -> V_192 ;
V_184 -> V_192 &= ~ V_193 ;
V_184 -> V_192 &= ~ V_194 ;
V_184 -> V_50 = F_11 ( V_19 ) -> V_50 ;
if ( F_55 ( V_113 , & V_184 -> V_77 ) ) {
F_70 ( V_183 , V_195 ) ;
V_184 -> V_57 = V_137 ;
}
F_103 ( V_2 , V_184 -> V_51 . V_52 , V_2 -> V_6 ) ;
V_184 -> V_51 . V_196 = V_2 -> V_6 ;
V_19 -> V_178 ++ ;
F_23 ( V_183 ) ;
F_104 ( & V_19 -> V_55 , V_2 ) ;
F_41 ( V_183 ) ;
if ( ! F_74 ( V_19 , V_56 ) )
V_19 -> V_197 ( V_19 , V_2 -> V_6 ) ;
V_8 = 1 ;
F_32 ( V_19 ) ;
V_73:
return V_8 ;
V_190:
F_32 ( V_19 ) ;
V_188:
V_8 = 0 ;
F_105 ( V_33 , V_54 , 0x01 ) ;
goto V_73;
}
static int F_106 ( struct V_198 * V_199 , struct V_64 * V_18 ,
struct V_200 * V_201 , T_2 V_6 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_11 ( V_19 ) ;
struct V_148 * V_202 = (struct V_148 * ) V_201 -> V_203 ;
struct V_148 V_181 ;
struct V_1 * V_2 ;
unsigned char * V_204 ;
int V_205 = V_201 -> V_206 & V_207 ;
T_2 V_208 ;
int V_209 = 0 , V_8 = - V_74 ;
F_58 ( V_19 ) ;
if ( V_201 -> V_206 & ~ ( V_207 | V_210 | V_211 | V_212 ) )
goto V_73;
if ( ! ( V_201 -> V_206 & ( V_211 | V_210 ) ) )
goto V_73;
V_8 = - V_213 ;
if ( F_74 ( V_19 , V_149 ) )
goto V_73;
V_8 = - V_214 ;
if ( V_19 -> V_141 & V_142 ) {
F_107 ( V_215 , V_153 , 0 ) ;
goto V_73;
}
V_8 = - V_27 ;
if ( ! V_86 -> V_26 )
goto V_73;
if ( V_202 ) {
V_8 = - V_74 ;
if ( V_201 -> V_216 < sizeof( V_181 ) )
goto V_73;
memcpy ( & V_181 , V_202 , sizeof( V_181 ) ) ;
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
V_8 = - V_217 ;
goto V_73;
}
F_76 ( V_19 , L_2 ) ;
F_76 ( V_19 , L_3 ) ;
if ( ( V_201 -> V_206 & V_210 ) && V_6 > 32 )
V_6 = 32 ;
V_208 = V_6 + V_218 + V_219 ;
F_59 ( V_19 ) ;
V_2 = F_108 ( V_19 , V_208 , V_205 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_73;
F_109 ( V_2 ) -> V_77 = V_201 -> V_206 ;
F_110 ( V_2 , V_218 + V_219 ) ;
F_76 ( V_19 , L_4 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 , V_6 ) ;
V_8 = F_113 ( F_114 ( V_2 ) , V_201 -> V_220 , V_6 ) ;
if ( V_8 )
goto V_221;
if ( F_55 ( V_76 , & V_86 -> V_77 ) ) {
if ( ! F_2 ( V_2 , 1 ) )
goto V_221;
V_209 = V_2 -> V_10 [ 0 ] ;
F_98 ( V_2 , 1 ) ;
}
F_76 ( V_19 , L_5 ) ;
if ( V_201 -> V_206 & V_210 ) {
if ( V_86 -> V_26 -> V_222 ) {
V_204 = F_99 ( V_2 , V_187 ) ;
* V_204 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_223 ;
* V_204 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_204 ++ = V_224 ;
} else {
V_204 = F_99 ( V_2 , V_187 ) ;
* V_204 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_225 ;
* V_204 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_204 ++ = V_224 ;
}
} else {
if ( V_86 -> V_26 -> V_222 ) {
V_204 = F_99 ( V_2 , V_219 ) ;
* V_204 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_223 ;
* V_204 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_204 ++ = V_226 ;
* V_204 ++ = V_226 ;
} else {
V_204 = F_99 ( V_2 , V_187 ) ;
* V_204 ++ = ( ( V_86 -> V_54 >> 8 ) & 0x0F ) | V_225 ;
* V_204 ++ = ( V_86 -> V_54 >> 0 ) & 0xFF ;
* V_204 ++ = V_226 ;
}
if ( V_209 )
V_2 -> V_10 [ 0 ] |= V_227 ;
}
F_76 ( V_19 , L_6 ) ;
F_76 ( V_19 , L_7 ) ;
V_8 = - V_182 ;
if ( V_19 -> V_48 != V_133 )
goto V_221;
if ( V_201 -> V_206 & V_210 )
F_115 ( & V_86 -> V_93 , V_2 ) ;
else {
V_8 = F_116 ( V_19 , V_2 ) ;
V_6 = V_8 ;
if ( V_8 < 0 )
F_42 ( V_2 ) ;
else if ( F_55 ( V_76 , & V_86 -> V_77 ) )
V_6 ++ ;
}
F_117 ( V_19 ) ;
V_8 = V_6 ;
V_73:
F_59 ( V_19 ) ;
return V_8 ;
V_221:
F_42 ( V_2 ) ;
goto V_73;
}
static int F_118 ( struct V_198 * V_199 , struct V_64 * V_18 ,
struct V_200 * V_201 , T_2 V_208 ,
int V_77 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_11 ( V_19 ) ;
struct V_148 * V_181 = (struct V_148 * ) V_201 -> V_203 ;
T_2 V_228 ;
int V_209 , V_229 = V_86 -> V_26 -> V_222 ?
V_219 : V_187 ;
struct V_1 * V_2 ;
unsigned char * V_204 ;
int V_8 = - V_182 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_133 )
goto V_73;
if ( V_77 & V_210 ) {
V_8 = - V_74 ;
if ( F_74 ( V_19 , V_230 ) ||
! F_119 ( & V_86 -> V_92 ) )
goto V_73;
V_2 = F_39 ( & V_86 -> V_92 ) ;
if ( ! F_2 ( V_2 , V_187 ) )
goto V_231;
F_98 ( V_2 , V_187 ) ;
if ( F_55 ( V_76 , & V_86 -> V_77 ) ) {
V_204 = F_99 ( V_2 , 1 ) ;
* V_204 = 0x00 ;
}
V_201 -> V_206 |= V_210 ;
} else {
F_59 ( V_19 ) ;
V_2 = F_120 ( V_19 , V_77 & ~ V_207 ,
V_77 & V_207 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_73;
if ( ! F_2 ( V_2 , V_229 ) )
goto V_231;
V_209 = ( V_2 -> V_10 [ 0 ] & V_227 ) == V_227 ;
F_98 ( V_2 , V_229 ) ;
if ( F_55 ( V_76 , & V_86 -> V_77 ) ) {
V_204 = F_99 ( V_2 , 1 ) ;
* V_204 = V_209 ;
}
}
F_111 ( V_2 ) ;
V_228 = V_2 -> V_6 ;
if ( V_228 > V_208 ) {
V_228 = V_208 ;
V_201 -> V_206 |= V_232 ;
}
V_201 -> V_206 |= V_211 ;
V_8 = F_121 ( V_2 , 0 , V_201 -> V_220 , V_228 ) ;
if ( V_8 )
goto V_231;
if ( V_181 ) {
V_181 -> V_150 = V_87 ;
V_181 -> V_151 = V_86 -> V_81 ;
}
V_201 -> V_216 = sizeof( struct V_148 ) ;
F_122 ( V_19 ) ;
V_8 = V_228 ;
V_231:
F_123 ( V_19 , V_2 ) ;
V_73:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_124 ( struct V_64 * V_18 , unsigned int V_233 , unsigned long V_234 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_85 * V_86 = F_11 ( V_19 ) ;
void T_1 * V_235 = ( void T_1 * ) V_234 ;
int V_8 ;
switch ( V_233 ) {
case V_236 : {
int V_237 ;
V_237 = V_19 -> V_132 - F_125 ( V_19 ) ;
if ( V_237 < 0 )
V_237 = 0 ;
V_8 = F_54 ( V_237 , ( unsigned int T_1 * ) V_235 ) ;
break;
}
case V_238 : {
struct V_1 * V_2 ;
int V_237 = 0 ;
F_58 ( V_19 ) ;
if ( ( V_2 = F_119 ( & V_19 -> V_55 ) ) != NULL )
V_237 = V_2 -> V_6 ;
F_59 ( V_19 ) ;
V_8 = F_54 ( V_237 , ( unsigned int T_1 * ) V_235 ) ;
break;
}
case V_239 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_126 ( V_19 ,
(struct V_240 T_1 * ) V_235 ) ;
break;
case V_241 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_127 ( V_19 ,
(struct V_242 T_1 * ) V_235 ) ;
break;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_8 = - V_74 ;
break;
case V_253 :
case V_254 :
V_8 = - V_255 ;
if ( ! F_128 ( V_256 ) )
break;
V_8 = F_129 ( V_233 , V_235 ) ;
break;
case V_257 :
V_8 = F_130 ( V_233 , V_235 ) ;
break;
case V_258 :
V_8 = - V_255 ;
if ( ! F_128 ( V_256 ) )
break;
V_8 = F_130 ( V_233 , V_235 ) ;
break;
case V_259 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_235 , & V_86 -> V_114 ,
sizeof( V_86 -> V_114 ) )
? - V_75 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_260 : {
struct V_185 V_114 ;
V_8 = - V_75 ;
if ( F_131 ( & V_114 , V_235 , sizeof( V_114 ) ) )
break;
V_8 = - V_74 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 &&
V_19 -> V_48 != V_140 )
goto V_261;
if ( V_114 . V_118 < V_262 ||
V_114 . V_118 > V_263 )
goto V_261;
if ( V_114 . V_120 < V_262 ||
V_114 . V_120 > V_263 )
goto V_261;
if ( V_114 . V_115 < 1 ||
V_114 . V_115 > 127 )
goto V_261;
if ( V_114 . V_121 ) {
int V_73 = V_114 . V_121 & 0xf0 ;
int V_264 = V_114 . V_121 & 0x0f ;
if ( ! V_73 )
V_114 . V_121 |=
V_265 << 4 ;
else if ( V_73 < 0x30 || V_73 > 0xD0 )
goto V_261;
if ( ! V_264 )
V_114 . V_121 |=
V_265 ;
else if ( V_264 < 0x03 || V_264 > 0x0D )
goto V_261;
}
if ( V_114 . V_122 &&
( V_114 . V_122 & 0x81 ) != 0x81 )
goto V_261;
V_86 -> V_114 = V_114 ;
V_8 = 0 ;
V_261:
F_59 ( V_19 ) ;
break;
}
case V_266 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_235 , & V_86 -> V_124 ,
sizeof( V_86 -> V_124 ) ) ;
F_59 ( V_19 ) ;
if ( V_8 )
V_8 = - V_75 ;
break;
}
case V_267 : {
struct V_186 V_268 ;
V_8 = - V_75 ;
if ( F_131 ( & V_268 , V_235 , sizeof( V_268 ) ) )
break;
V_8 = - V_74 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_49 &&
V_19 -> V_48 != V_140 )
goto V_269;
if ( V_268 . V_14 > V_270 )
goto V_269;
if ( V_268 . V_126 == NULL )
goto V_269;
if ( V_268 . V_13 > V_270 )
goto V_269;
if ( V_268 . V_125 == NULL )
goto V_269;
V_86 -> V_124 = V_268 ;
V_8 = 0 ;
V_269:
F_59 ( V_19 ) ;
break;
}
case V_271 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_235 , & V_86 -> V_51 ,
sizeof( V_86 -> V_51 ) )
? - V_75 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_272 : {
struct V_273 V_51 ;
V_8 = - V_75 ;
if ( F_131 ( & V_51 , V_235 , sizeof( V_51 ) ) )
break;
V_8 = - V_74 ;
if ( V_51 . V_196 > V_189 )
break;
F_58 ( V_19 ) ;
V_86 -> V_51 = V_51 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_274 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_235 , & V_86 -> V_275 , sizeof( V_86 -> V_275 ) )
? - V_75 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_276 : {
struct V_277 V_275 ;
V_8 = - V_75 ;
if ( F_131 ( & V_275 , V_235 , sizeof( V_275 ) ) )
break;
F_58 ( V_19 ) ;
V_86 -> V_275 = V_275 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_278 : {
struct V_279 V_280 ;
V_8 = - V_74 ;
F_58 ( V_19 ) ;
if( V_19 -> V_48 != V_140 )
goto V_281;
V_8 = - V_75 ;
if ( F_131 ( & V_280 , V_235 ,
sizeof( V_280 ) ) )
goto V_281;
V_8 = - V_74 ;
if ( V_280 . V_50 > V_189 )
goto V_281;
V_86 -> V_50 = V_280 . V_50 ;
V_8 = 0 ;
V_281:
F_59 ( V_19 ) ;
break;
}
case V_282 : {
V_8 = - V_74 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_140 )
break;
F_51 ( V_113 , & V_86 -> V_77 ) ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_283 : {
V_8 = - V_74 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_48 != V_133 )
break;
if ( F_55 ( V_113 , & V_86 -> V_77 ) )
break;
F_70 ( V_19 , V_195 ) ;
V_86 -> V_57 = V_137 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
default:
V_8 = - V_284 ;
break;
}
return V_8 ;
}
static int F_132 ( unsigned int V_233 ,
struct V_285 T_1 * V_286 )
{
struct V_285 V_287 ;
struct V_32 * V_33 ;
struct V_21 * V_22 ;
int V_8 = - V_74 ;
V_8 = - V_75 ;
if ( F_131 ( & V_287 , V_286 , sizeof( * V_286 ) ) )
goto V_73;
V_8 = - V_74 ;
V_22 = F_133 ( V_287 . V_288 ) ;
if ( V_22 == NULL )
goto V_73;
V_33 = F_18 ( V_22 ) ;
if ( V_33 == NULL )
goto V_289;
F_134 ( V_22 ) ;
if ( V_233 == V_257 ) {
F_26 ( & V_290 ) ;
V_287 . V_222 = V_33 -> V_222 ;
V_287 . V_291 = V_33 -> V_291 ;
F_28 ( & V_290 ) ;
V_8 = F_56 ( V_286 , & V_287 ,
sizeof( * V_286 ) ) ? - V_75 : 0 ;
} else {
V_8 = - V_74 ;
if ( V_287 . V_222 == 0 || V_287 . V_222 == 1 ) {
V_8 = 0 ;
F_6 ( & V_290 ) ;
V_33 -> V_222 = V_287 . V_222 ;
V_33 -> V_291 = V_287 . V_291 ;
F_8 ( & V_290 ) ;
}
}
F_20 ( V_33 ) ;
V_73:
return V_8 ;
V_289:
F_134 ( V_22 ) ;
goto V_73;
}
static int F_135 ( struct V_64 * V_18 , unsigned int V_233 ,
unsigned long V_234 )
{
void T_1 * V_235 = F_136 ( V_234 ) ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_284 ;
switch( V_233 ) {
case V_236 :
case V_238 :
V_8 = F_124 ( V_18 , V_233 , ( unsigned long ) V_235 ) ;
break;
case V_239 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_137 ( V_19 ,
(struct V_240 T_1 * ) V_235 ) ;
break;
case V_241 :
V_8 = - V_74 ;
if ( V_19 )
V_8 = F_138 ( V_19 ,
(struct V_242 T_1 * ) V_235 ) ;
break;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_8 = - V_74 ;
break;
case V_253 :
case V_254 :
V_8 = - V_255 ;
if ( ! F_128 ( V_256 ) )
break;
V_8 = F_129 ( V_233 , V_235 ) ;
break;
case V_257 :
V_8 = F_132 ( V_233 , V_235 ) ;
break;
case V_258 :
V_8 = - V_255 ;
if ( ! F_128 ( V_256 ) )
break;
V_8 = F_132 ( V_233 , V_235 ) ;
break;
case V_259 :
case V_260 :
case V_266 :
case V_267 :
case V_271 :
case V_272 :
case V_274 :
case V_276 :
case V_278 :
case V_282 :
case V_283 :
V_8 = F_124 ( V_18 , V_233 , ( unsigned long ) V_235 ) ;
break;
default:
V_8 = - V_284 ;
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
int V_8 = F_142 ( & V_89 , 0 ) ;
if ( V_8 != 0 )
goto V_73;
V_8 = F_143 ( & V_292 ) ;
if ( V_8 != 0 )
goto V_293;
F_144 ( & V_294 ) ;
V_8 = F_145 ( & V_295 ) ;
if ( V_8 != 0 )
goto V_296;
F_146 ( V_297 L_8 ) ;
F_147 () ;
V_8 = F_148 () ;
if ( V_8 != 0 )
goto V_298;
V_73:
return V_8 ;
V_298:
F_149 ( & V_295 ) ;
V_296:
F_150 ( V_87 ) ;
V_293:
F_151 ( & V_89 ) ;
goto V_73;
}
static void T_4 F_152 ( void )
{
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
F_149 ( & V_295 ) ;
F_157 ( & V_294 ) ;
F_150 ( V_87 ) ;
F_151 ( & V_89 ) ;
}
