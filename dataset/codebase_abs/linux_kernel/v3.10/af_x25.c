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
F_6 ( & V_20 ) ;
F_10 (s, &x25_list)
if ( F_11 ( V_23 ) -> V_24 && F_11 ( V_23 ) -> V_24 -> V_22 == V_22 )
F_12 ( V_23 , V_25 , 0 , 0 ) ;
F_8 ( & V_20 ) ;
}
static int F_13 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_29 )
{
struct V_21 * V_22 = V_29 ;
struct V_30 * V_31 ;
if ( ! F_14 ( F_15 ( V_22 ) , & V_32 ) )
return V_33 ;
if ( V_22 -> type == V_34
#if F_16 ( V_35 )
|| V_22 -> type == V_36
#endif
) {
switch ( V_28 ) {
case V_37 :
F_17 ( V_22 ) ;
break;
case V_38 :
V_31 = F_18 ( V_22 ) ;
if ( V_31 ) {
F_19 ( V_31 ) ;
F_20 ( V_31 ) ;
}
break;
case V_39 :
F_9 ( V_22 ) ;
F_21 ( V_22 ) ;
F_22 ( V_22 ) ;
break;
}
}
return V_33 ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_6 ( & V_20 ) ;
F_24 ( V_19 , & V_40 ) ;
F_8 ( & V_20 ) ;
}
static struct V_18 * F_25 ( struct V_3 * V_41 ,
struct V_1 * V_2 )
{
struct V_18 * V_23 ;
struct V_18 * V_42 ;
F_26 ( & V_20 ) ;
V_42 = NULL ;
F_10 (s, &x25_list)
if ( ( ! strcmp ( V_41 -> V_11 ,
F_11 ( V_23 ) -> V_43 . V_11 ) ||
! strcmp ( V_41 -> V_11 ,
V_44 . V_11 ) ) &&
V_23 -> V_45 == V_46 ) {
if ( F_11 ( V_23 ) -> V_47 > 0 &&
V_2 -> V_6 >= F_11 ( V_23 ) -> V_47 ) {
if( ( memcmp ( F_11 ( V_23 ) -> V_48 . V_49 ,
V_2 -> V_10 ,
F_11 ( V_23 ) -> V_47 ) ) == 0 ) {
F_27 ( V_23 ) ;
goto V_50;
}
} else
V_42 = V_23 ;
}
if ( V_42 ) {
V_23 = V_42 ;
F_27 ( V_23 ) ;
goto V_50;
}
V_23 = NULL ;
V_50:
F_28 ( & V_20 ) ;
return V_23 ;
}
static struct V_18 * F_29 ( unsigned int V_51 , struct V_30 * V_31 )
{
struct V_18 * V_23 ;
F_10 (s, &x25_list)
if ( F_11 ( V_23 ) -> V_51 == V_51 && F_11 ( V_23 ) -> V_24 == V_31 ) {
F_27 ( V_23 ) ;
goto V_50;
}
V_23 = NULL ;
V_50:
return V_23 ;
}
struct V_18 * F_30 ( unsigned int V_51 , struct V_30 * V_31 )
{
struct V_18 * V_23 ;
F_26 ( & V_20 ) ;
V_23 = F_29 ( V_51 , V_31 ) ;
F_28 ( & V_20 ) ;
return V_23 ;
}
static unsigned int F_31 ( struct V_30 * V_31 )
{
unsigned int V_51 = 1 ;
struct V_18 * V_19 ;
F_26 ( & V_20 ) ;
while ( ( V_19 = F_29 ( V_51 , V_31 ) ) != NULL ) {
F_32 ( V_19 ) ;
if ( ++ V_51 == 4096 ) {
V_51 = 0 ;
break;
}
}
F_28 ( & V_20 ) ;
return V_51 ;
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
while ( ( V_2 = F_39 ( & V_19 -> V_52 ) ) != NULL ) {
if ( V_2 -> V_19 != V_19 ) {
V_2 -> V_19 -> V_45 = V_46 ;
F_40 ( V_2 -> V_19 , V_53 ) ;
F_41 ( V_2 -> V_19 ) ;
F_11 ( V_2 -> V_19 ) -> V_54 = V_55 ;
}
F_42 ( V_2 ) ;
}
if ( F_43 ( V_19 ) ) {
V_19 -> V_56 . V_57 = V_58 + 10 * V_59 ;
V_19 -> V_56 . V_60 = F_33 ;
V_19 -> V_56 . V_10 = ( unsigned long ) V_19 ;
F_44 ( & V_19 -> V_56 ) ;
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
static int F_48 ( struct V_61 * V_18 , int V_62 , int V_63 ,
char T_1 * V_64 , unsigned int V_65 )
{
int V_66 ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_67 ;
if ( V_62 != V_68 || V_63 != V_69 )
goto V_70;
V_8 = - V_71 ;
if ( V_65 < sizeof( int ) )
goto V_70;
V_8 = - V_72 ;
if ( F_49 ( V_66 , ( int T_1 * ) V_64 ) )
goto V_70;
if ( V_66 )
F_50 ( V_73 , & F_11 ( V_19 ) -> V_74 ) ;
else
F_51 ( V_73 , & F_11 ( V_19 ) -> V_74 ) ;
V_8 = 0 ;
V_70:
return V_8 ;
}
static int F_52 ( struct V_61 * V_18 , int V_62 , int V_63 ,
char T_1 * V_64 , int T_1 * V_65 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_75 , V_6 , V_8 = - V_67 ;
if ( V_62 != V_68 || V_63 != V_69 )
goto V_70;
V_8 = - V_72 ;
if ( F_49 ( V_6 , V_65 ) )
goto V_70;
V_6 = F_53 (unsigned int, len, sizeof(int)) ;
V_8 = - V_71 ;
if ( V_6 < 0 )
goto V_70;
V_8 = - V_72 ;
if ( F_54 ( V_6 , V_65 ) )
goto V_70;
V_75 = F_55 ( V_73 , & F_11 ( V_19 ) -> V_74 ) ;
V_8 = F_56 ( V_64 , & V_75 , V_6 ) ? - V_72 : 0 ;
V_70:
return V_8 ;
}
static int F_57 ( struct V_61 * V_18 , int V_76 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_77 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 != V_46 ) {
memset ( & F_11 ( V_19 ) -> V_78 , 0 , V_79 ) ;
V_19 -> V_80 = V_76 ;
V_19 -> V_45 = V_46 ;
V_8 = 0 ;
}
F_59 ( V_19 ) ;
return V_8 ;
}
static struct V_18 * F_60 ( struct V_81 * V_81 )
{
struct V_82 * V_83 ;
struct V_18 * V_19 = F_61 ( V_81 , V_84 , V_85 , & V_86 ) ;
if ( ! V_19 )
goto V_70;
F_62 ( NULL , V_19 ) ;
V_83 = F_11 ( V_19 ) ;
F_63 ( & V_83 -> V_87 ) ;
F_63 ( & V_83 -> V_88 ) ;
F_63 ( & V_83 -> V_89 ) ;
F_63 ( & V_83 -> V_90 ) ;
V_70:
return V_19 ;
}
static int F_64 ( struct V_81 * V_81 , struct V_61 * V_18 , int V_91 ,
int V_92 )
{
struct V_18 * V_19 ;
struct V_82 * V_83 ;
int V_8 = - V_93 ;
if ( ! F_14 ( V_81 , & V_32 ) )
goto V_70;
V_8 = - V_94 ;
if ( V_18 -> type != V_95 )
goto V_70;
V_8 = - V_71 ;
if ( V_91 )
goto V_70;
V_8 = - V_96 ;
if ( ( V_19 = F_60 ( V_81 ) ) == NULL )
goto V_70;
V_83 = F_11 ( V_19 ) ;
F_62 ( V_18 , V_19 ) ;
F_65 ( V_19 ) ;
V_18 -> V_97 = & V_98 ;
V_19 -> V_99 = V_91 ;
V_19 -> V_100 = V_101 ;
V_83 -> V_102 = V_103 ;
V_83 -> V_104 = V_105 ;
V_83 -> V_106 = V_107 ;
V_83 -> V_108 = V_109 ;
V_83 -> V_54 = V_55 ;
V_83 -> V_47 = 0 ;
F_50 ( V_110 , & V_83 -> V_74 ) ;
V_83 -> V_111 . V_112 = V_113 ;
V_83 -> V_111 . V_114 = V_113 ;
V_83 -> V_111 . V_115 = V_116 ;
V_83 -> V_111 . V_117 = V_116 ;
V_83 -> V_111 . V_118 = 0 ;
V_83 -> V_111 . V_119 = V_120 ;
V_83 -> V_121 . V_14 = 0 ;
V_83 -> V_121 . V_13 = 0 ;
memset ( V_83 -> V_121 . V_122 , '\0' ,
sizeof( V_83 -> V_121 . V_122 ) ) ;
memset ( V_83 -> V_121 . V_123 , '\0' ,
sizeof( V_83 -> V_121 . V_123 ) ) ;
V_8 = 0 ;
V_70:
return V_8 ;
}
static struct V_18 * F_66 ( struct V_18 * V_124 )
{
struct V_18 * V_19 = NULL ;
struct V_82 * V_83 , * V_125 ;
if ( V_124 -> V_126 != V_95 )
goto V_70;
if ( ( V_19 = F_60 ( F_67 ( V_124 ) ) ) == NULL )
goto V_70;
V_83 = F_11 ( V_19 ) ;
V_19 -> V_126 = V_124 -> V_126 ;
V_19 -> V_127 = V_124 -> V_127 ;
V_19 -> V_99 = V_124 -> V_99 ;
V_19 -> V_128 = V_124 -> V_128 ;
V_19 -> V_129 = V_124 -> V_129 ;
V_19 -> V_45 = V_130 ;
V_19 -> V_100 = V_124 -> V_100 ;
F_68 ( V_19 , V_124 ) ;
V_125 = F_11 ( V_124 ) ;
V_83 -> V_102 = V_125 -> V_102 ;
V_83 -> V_104 = V_125 -> V_104 ;
V_83 -> V_106 = V_125 -> V_106 ;
V_83 -> V_108 = V_125 -> V_108 ;
V_83 -> V_74 = V_125 -> V_74 ;
V_83 -> V_111 = V_125 -> V_111 ;
V_83 -> V_121 = V_125 -> V_121 ;
V_83 -> V_47 = V_125 -> V_47 ;
F_51 ( V_131 , & V_83 -> V_74 ) ;
F_65 ( V_19 ) ;
V_70:
return V_19 ;
}
static int F_69 ( struct V_61 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 ;
if ( ! V_19 )
return 0 ;
V_83 = F_11 ( V_19 ) ;
F_27 ( V_19 ) ;
F_58 ( V_19 ) ;
switch ( V_83 -> V_54 ) {
case V_55 :
case V_132 :
F_12 ( V_19 , 0 , 0 , 0 ) ;
F_35 ( V_19 ) ;
goto V_70;
case V_133 :
case V_134 :
case V_135 :
F_38 ( V_19 ) ;
F_70 ( V_19 , V_136 ) ;
F_71 ( V_19 ) ;
V_83 -> V_54 = V_132 ;
V_19 -> V_45 = V_137 ;
V_19 -> V_138 |= V_139 ;
V_19 -> V_140 ( V_19 ) ;
F_40 ( V_19 , V_53 ) ;
F_40 ( V_19 , V_141 ) ;
break;
}
F_72 ( V_19 ) ;
V_70:
F_59 ( V_19 ) ;
F_32 ( V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_61 * V_18 , struct V_142 * V_143 , int V_144 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_145 * V_41 = (struct V_145 * ) V_143 ;
int V_6 , V_17 , V_8 = 0 ;
if ( ! F_74 ( V_19 , V_146 ) ||
V_144 != sizeof( struct V_145 ) ||
V_41 -> V_147 != V_84 ) {
V_8 = - V_71 ;
goto V_70;
}
V_6 = strlen ( V_41 -> V_148 . V_11 ) ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
if ( ! isdigit ( V_41 -> V_148 . V_11 [ V_17 ] ) ) {
V_8 = - V_71 ;
goto V_70;
}
}
F_58 ( V_19 ) ;
F_11 ( V_19 ) -> V_43 = V_41 -> V_148 ;
F_23 ( V_19 ) ;
F_75 ( V_19 , V_146 ) ;
F_59 ( V_19 ) ;
F_76 ( V_19 , L_1 ) ;
V_70:
return V_8 ;
}
static int F_77 ( struct V_18 * V_19 )
{
F_78 ( V_149 , V_150 ) ;
int V_8 ;
F_79 ( F_80 ( V_19 ) , & V_149 ) ;
for (; ; ) {
F_81 ( V_151 ) ;
V_8 = - V_152 ;
if ( F_82 ( V_150 ) )
break;
V_8 = F_83 ( V_19 ) ;
if ( V_8 ) {
V_19 -> V_153 -> V_54 = V_154 ;
break;
}
V_8 = 0 ;
if ( V_19 -> V_45 != V_130 ) {
F_59 ( V_19 ) ;
F_84 () ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_155 ) ;
F_85 ( F_80 ( V_19 ) , & V_149 ) ;
return V_8 ;
}
static int F_86 ( struct V_61 * V_18 , struct V_142 * V_143 ,
int V_144 , int V_74 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 = F_11 ( V_19 ) ;
struct V_145 * V_41 = (struct V_145 * ) V_143 ;
struct V_156 * V_157 ;
int V_8 = 0 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 == V_130 && V_18 -> V_54 == V_158 ) {
V_18 -> V_54 = V_159 ;
goto V_70;
}
V_8 = - V_160 ;
if ( V_19 -> V_45 == V_137 && V_18 -> V_54 == V_158 ) {
V_18 -> V_54 = V_154 ;
goto V_70;
}
V_8 = - V_161 ;
if ( V_19 -> V_45 == V_130 )
goto V_70;
V_19 -> V_45 = V_137 ;
V_18 -> V_54 = V_154 ;
V_8 = - V_71 ;
if ( V_144 != sizeof( struct V_145 ) ||
V_41 -> V_147 != V_84 )
goto V_70;
V_8 = - V_25 ;
V_157 = F_87 ( & V_41 -> V_148 ) ;
if ( ! V_157 )
goto V_70;
V_83 -> V_24 = F_18 ( V_157 -> V_22 ) ;
if ( ! V_83 -> V_24 )
goto V_162;
F_88 ( & V_83 -> V_111 , V_83 -> V_24 ) ;
V_83 -> V_51 = F_31 ( V_83 -> V_24 ) ;
if ( ! V_83 -> V_51 )
goto V_163;
V_8 = - V_71 ;
if ( F_74 ( V_19 , V_146 ) )
goto V_163;
if ( ! strcmp ( V_83 -> V_43 . V_11 , V_44 . V_11 ) )
memset ( & V_83 -> V_43 , '\0' , V_79 ) ;
V_83 -> V_78 = V_41 -> V_148 ;
V_18 -> V_54 = V_158 ;
V_19 -> V_45 = V_164 ;
V_83 -> V_54 = V_133 ;
F_70 ( V_19 , V_165 ) ;
F_41 ( V_19 ) ;
F_89 ( V_19 ) ;
V_8 = - V_166 ;
if ( V_19 -> V_45 != V_130 && ( V_74 & V_167 ) )
goto V_163;
V_8 = F_77 ( V_19 ) ;
if ( V_8 )
goto V_163;
V_18 -> V_54 = V_159 ;
V_8 = 0 ;
V_163:
if ( V_8 )
F_20 ( V_83 -> V_24 ) ;
V_162:
F_90 ( V_157 ) ;
V_70:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_91 ( struct V_18 * V_19 , long V_168 )
{
F_78 ( V_149 , V_150 ) ;
int V_8 = 0 ;
F_79 ( F_80 ( V_19 ) , & V_149 ) ;
for (; ; ) {
F_81 ( V_151 ) ;
if ( V_19 -> V_138 & V_169 )
break;
V_8 = - V_152 ;
if ( F_82 ( V_150 ) )
break;
V_8 = - V_170 ;
if ( ! V_168 )
break;
V_8 = 0 ;
if ( F_92 ( & V_19 -> V_52 ) ) {
F_59 ( V_19 ) ;
V_168 = F_93 ( V_168 ) ;
F_58 ( V_19 ) ;
} else
break;
}
F_81 ( V_155 ) ;
F_85 ( F_80 ( V_19 ) , & V_149 ) ;
return V_8 ;
}
static int F_94 ( struct V_61 * V_18 , struct V_61 * V_171 , int V_74 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_18 * V_172 ;
struct V_1 * V_2 ;
int V_8 = - V_71 ;
if ( ! V_19 )
goto V_70;
V_8 = - V_77 ;
if ( V_19 -> V_126 != V_95 )
goto V_70;
F_58 ( V_19 ) ;
V_8 = - V_71 ;
if ( V_19 -> V_45 != V_46 )
goto V_173;
V_8 = F_91 ( V_19 , V_19 -> V_174 ) ;
if ( V_8 )
goto V_173;
V_2 = F_39 ( & V_19 -> V_52 ) ;
V_8 = - V_71 ;
if ( ! V_2 -> V_19 )
goto V_173;
V_172 = V_2 -> V_19 ;
F_95 ( V_172 , V_171 ) ;
V_2 -> V_19 = NULL ;
F_42 ( V_2 ) ;
V_19 -> V_175 -- ;
V_171 -> V_54 = V_159 ;
V_8 = 0 ;
V_173:
F_59 ( V_19 ) ;
V_70:
return V_8 ;
}
static int F_96 ( struct V_61 * V_18 , struct V_142 * V_143 ,
int * V_176 , int V_177 )
{
struct V_145 * V_178 = (struct V_145 * ) V_143 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 = F_11 ( V_19 ) ;
int V_8 = 0 ;
if ( V_177 ) {
if ( V_19 -> V_45 != V_130 ) {
V_8 = - V_179 ;
goto V_70;
}
V_178 -> V_148 = V_83 -> V_78 ;
} else
V_178 -> V_148 = V_83 -> V_43 ;
V_178 -> V_147 = V_84 ;
* V_176 = sizeof( * V_178 ) ;
V_70:
return V_8 ;
}
int F_97 ( struct V_1 * V_2 , struct V_30 * V_31 ,
unsigned int V_51 )
{
struct V_18 * V_19 ;
struct V_18 * V_180 ;
struct V_82 * V_181 ;
struct V_3 V_43 , V_78 ;
struct V_182 V_111 ;
struct V_183 V_121 ;
int V_6 , V_144 , V_8 ;
F_98 ( V_2 , V_184 ) ;
V_144 = F_1 ( V_2 , & V_43 , & V_78 ) ;
if ( V_144 <= 0 )
goto V_185;
F_98 ( V_2 , V_144 ) ;
if ( ! F_2 ( V_2 , 1 ) )
goto V_185;
V_6 = V_2 -> V_10 [ 0 ] + 1 ;
if ( ! F_2 ( V_2 , V_6 ) )
goto V_185;
F_98 ( V_2 , V_6 ) ;
if ( V_2 -> V_6 > V_186 )
goto V_185;
if ( ! F_2 ( V_2 , V_2 -> V_6 ) )
goto V_185;
V_19 = F_25 ( & V_43 , V_2 ) ;
F_99 ( V_2 , V_6 ) ;
if ( V_19 != NULL && F_100 ( V_19 ) ) {
goto V_187;
}
if ( V_19 == NULL ) {
F_99 ( V_2 , V_144 + V_184 ) ;
if ( V_188 &&
F_101 ( & V_78 , V_31 , V_2 , V_51 ) > 0 )
{
F_42 ( V_2 ) ;
V_8 = 1 ;
goto V_70;
} else {
goto V_185;
}
}
V_6 = F_102 ( V_2 , V_19 , & V_111 , & V_121 ) ;
if ( V_6 == - 1 )
goto V_187;
F_88 ( & V_111 , V_31 ) ;
V_180 = F_66 ( V_19 ) ;
if ( ! V_180 )
goto V_187;
F_98 ( V_2 , V_6 ) ;
V_2 -> V_19 = V_180 ;
V_180 -> V_45 = V_130 ;
V_181 = F_11 ( V_180 ) ;
V_181 -> V_51 = V_51 ;
V_181 -> V_78 = V_78 ;
V_181 -> V_43 = V_43 ;
V_181 -> V_24 = V_31 ;
V_181 -> V_111 = V_111 ;
V_181 -> V_121 = V_121 ;
V_181 -> V_189 = F_11 ( V_19 ) -> V_189 ;
V_181 -> V_189 &= ~ V_190 ;
V_181 -> V_189 &= ~ V_191 ;
V_181 -> V_47 = F_11 ( V_19 ) -> V_47 ;
if ( F_55 ( V_110 , & V_181 -> V_74 ) ) {
F_70 ( V_180 , V_192 ) ;
V_181 -> V_54 = V_134 ;
}
F_103 ( V_2 , V_181 -> V_48 . V_49 , V_2 -> V_6 ) ;
V_181 -> V_48 . V_193 = V_2 -> V_6 ;
V_19 -> V_175 ++ ;
F_23 ( V_180 ) ;
F_104 ( & V_19 -> V_52 , V_2 ) ;
F_41 ( V_180 ) ;
if ( ! F_74 ( V_19 , V_53 ) )
V_19 -> V_194 ( V_19 , V_2 -> V_6 ) ;
V_8 = 1 ;
F_32 ( V_19 ) ;
V_70:
return V_8 ;
V_187:
F_32 ( V_19 ) ;
V_185:
V_8 = 0 ;
F_105 ( V_31 , V_51 , 0x01 ) ;
goto V_70;
}
static int F_106 ( struct V_195 * V_196 , struct V_61 * V_18 ,
struct V_197 * V_198 , T_2 V_6 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 = F_11 ( V_19 ) ;
struct V_145 * V_199 = (struct V_145 * ) V_198 -> V_200 ;
struct V_145 V_178 ;
struct V_1 * V_2 ;
unsigned char * V_201 ;
int V_202 = V_198 -> V_203 & V_204 ;
T_2 V_205 ;
int V_206 = 0 , V_8 = - V_71 ;
F_58 ( V_19 ) ;
if ( V_198 -> V_203 & ~ ( V_204 | V_207 | V_208 | V_209 ) )
goto V_70;
if ( ! ( V_198 -> V_203 & ( V_208 | V_207 ) ) )
goto V_70;
V_8 = - V_210 ;
if ( F_74 ( V_19 , V_146 ) )
goto V_70;
V_8 = - V_211 ;
if ( V_19 -> V_138 & V_139 ) {
F_107 ( V_212 , V_150 , 0 ) ;
goto V_70;
}
V_8 = - V_25 ;
if ( ! V_83 -> V_24 )
goto V_70;
if ( V_199 ) {
V_8 = - V_71 ;
if ( V_198 -> V_213 < sizeof( V_178 ) )
goto V_70;
memcpy ( & V_178 , V_199 , sizeof( V_178 ) ) ;
V_8 = - V_161 ;
if ( strcmp ( V_83 -> V_78 . V_11 , V_178 . V_148 . V_11 ) )
goto V_70;
V_8 = - V_71 ;
if ( V_178 . V_147 != V_84 )
goto V_70;
} else {
V_8 = - V_179 ;
if ( V_19 -> V_45 != V_130 )
goto V_70;
V_178 . V_147 = V_84 ;
V_178 . V_148 = V_83 -> V_78 ;
}
if ( V_6 > 65535 ) {
V_8 = - V_214 ;
goto V_70;
}
F_76 ( V_19 , L_2 ) ;
F_76 ( V_19 , L_3 ) ;
if ( ( V_198 -> V_203 & V_207 ) && V_6 > 32 )
V_6 = 32 ;
V_205 = V_6 + V_215 + V_216 ;
F_59 ( V_19 ) ;
V_2 = F_108 ( V_19 , V_205 , V_202 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_70;
F_109 ( V_2 ) -> V_74 = V_198 -> V_203 ;
F_110 ( V_2 , V_215 + V_216 ) ;
F_76 ( V_19 , L_4 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 , V_6 ) ;
V_8 = F_113 ( F_114 ( V_2 ) , V_198 -> V_217 , V_6 ) ;
if ( V_8 )
goto V_218;
if ( F_55 ( V_73 , & V_83 -> V_74 ) ) {
if ( ! F_2 ( V_2 , 1 ) )
goto V_218;
V_206 = V_2 -> V_10 [ 0 ] ;
F_98 ( V_2 , 1 ) ;
}
F_76 ( V_19 , L_5 ) ;
if ( V_198 -> V_203 & V_207 ) {
if ( V_83 -> V_24 -> V_219 ) {
V_201 = F_99 ( V_2 , V_184 ) ;
* V_201 ++ = ( ( V_83 -> V_51 >> 8 ) & 0x0F ) | V_220 ;
* V_201 ++ = ( V_83 -> V_51 >> 0 ) & 0xFF ;
* V_201 ++ = V_221 ;
} else {
V_201 = F_99 ( V_2 , V_184 ) ;
* V_201 ++ = ( ( V_83 -> V_51 >> 8 ) & 0x0F ) | V_222 ;
* V_201 ++ = ( V_83 -> V_51 >> 0 ) & 0xFF ;
* V_201 ++ = V_221 ;
}
} else {
if ( V_83 -> V_24 -> V_219 ) {
V_201 = F_99 ( V_2 , V_216 ) ;
* V_201 ++ = ( ( V_83 -> V_51 >> 8 ) & 0x0F ) | V_220 ;
* V_201 ++ = ( V_83 -> V_51 >> 0 ) & 0xFF ;
* V_201 ++ = V_223 ;
* V_201 ++ = V_223 ;
} else {
V_201 = F_99 ( V_2 , V_184 ) ;
* V_201 ++ = ( ( V_83 -> V_51 >> 8 ) & 0x0F ) | V_222 ;
* V_201 ++ = ( V_83 -> V_51 >> 0 ) & 0xFF ;
* V_201 ++ = V_223 ;
}
if ( V_206 )
V_2 -> V_10 [ 0 ] |= V_224 ;
}
F_76 ( V_19 , L_6 ) ;
F_76 ( V_19 , L_7 ) ;
V_8 = - V_179 ;
if ( V_19 -> V_45 != V_130 )
goto V_218;
if ( V_198 -> V_203 & V_207 )
F_115 ( & V_83 -> V_90 , V_2 ) ;
else {
V_8 = F_116 ( V_19 , V_2 ) ;
V_6 = V_8 ;
if ( V_8 < 0 )
F_42 ( V_2 ) ;
else if ( F_55 ( V_73 , & V_83 -> V_74 ) )
V_6 ++ ;
}
F_117 ( V_19 ) ;
V_8 = V_6 ;
V_70:
F_59 ( V_19 ) ;
return V_8 ;
V_218:
F_42 ( V_2 ) ;
goto V_70;
}
static int F_118 ( struct V_195 * V_196 , struct V_61 * V_18 ,
struct V_197 * V_198 , T_2 V_205 ,
int V_74 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 = F_11 ( V_19 ) ;
struct V_145 * V_178 = (struct V_145 * ) V_198 -> V_200 ;
T_2 V_225 ;
int V_206 , V_226 ;
struct V_1 * V_2 ;
unsigned char * V_201 ;
int V_8 = - V_179 ;
F_58 ( V_19 ) ;
if ( V_83 -> V_24 == NULL )
goto V_70;
V_226 = V_83 -> V_24 -> V_219 ?
V_216 : V_184 ;
if ( V_19 -> V_45 != V_130 )
goto V_70;
if ( V_74 & V_207 ) {
V_8 = - V_71 ;
if ( F_74 ( V_19 , V_227 ) ||
! F_119 ( & V_83 -> V_89 ) )
goto V_70;
V_2 = F_39 ( & V_83 -> V_89 ) ;
if ( ! F_2 ( V_2 , V_184 ) )
goto V_228;
F_98 ( V_2 , V_184 ) ;
if ( F_55 ( V_73 , & V_83 -> V_74 ) ) {
V_201 = F_99 ( V_2 , 1 ) ;
* V_201 = 0x00 ;
}
V_198 -> V_203 |= V_207 ;
} else {
F_59 ( V_19 ) ;
V_2 = F_120 ( V_19 , V_74 & ~ V_204 ,
V_74 & V_204 , & V_8 ) ;
F_58 ( V_19 ) ;
if ( ! V_2 )
goto V_70;
if ( ! F_2 ( V_2 , V_226 ) )
goto V_228;
V_206 = ( V_2 -> V_10 [ 0 ] & V_224 ) == V_224 ;
F_98 ( V_2 , V_226 ) ;
if ( F_55 ( V_73 , & V_83 -> V_74 ) ) {
V_201 = F_99 ( V_2 , 1 ) ;
* V_201 = V_206 ;
}
}
F_111 ( V_2 ) ;
V_225 = V_2 -> V_6 ;
if ( V_225 > V_205 ) {
V_225 = V_205 ;
V_198 -> V_203 |= V_229 ;
}
V_198 -> V_203 |= V_208 ;
V_8 = F_121 ( V_2 , 0 , V_198 -> V_217 , V_225 ) ;
if ( V_8 )
goto V_228;
if ( V_178 ) {
V_178 -> V_147 = V_84 ;
V_178 -> V_148 = V_83 -> V_78 ;
}
V_198 -> V_213 = sizeof( struct V_145 ) ;
F_122 ( V_19 ) ;
V_8 = V_225 ;
V_228:
F_123 ( V_19 , V_2 ) ;
V_70:
F_59 ( V_19 ) ;
return V_8 ;
}
static int F_124 ( struct V_61 * V_18 , unsigned int V_230 , unsigned long V_231 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_82 * V_83 = F_11 ( V_19 ) ;
void T_1 * V_232 = ( void T_1 * ) V_231 ;
int V_8 ;
switch ( V_230 ) {
case V_233 : {
int V_234 ;
V_234 = V_19 -> V_129 - F_125 ( V_19 ) ;
if ( V_234 < 0 )
V_234 = 0 ;
V_8 = F_54 ( V_234 , ( unsigned int T_1 * ) V_232 ) ;
break;
}
case V_235 : {
struct V_1 * V_2 ;
int V_234 = 0 ;
F_58 ( V_19 ) ;
if ( ( V_2 = F_119 ( & V_19 -> V_52 ) ) != NULL )
V_234 = V_2 -> V_6 ;
F_59 ( V_19 ) ;
V_8 = F_54 ( V_234 , ( unsigned int T_1 * ) V_232 ) ;
break;
}
case V_236 :
V_8 = - V_71 ;
if ( V_19 )
V_8 = F_126 ( V_19 ,
(struct V_237 T_1 * ) V_232 ) ;
break;
case V_238 :
V_8 = - V_71 ;
if ( V_19 )
V_8 = F_127 ( V_19 ,
(struct V_239 T_1 * ) V_232 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
V_8 = - V_71 ;
break;
case V_250 :
case V_251 :
V_8 = - V_252 ;
if ( ! F_128 ( V_253 ) )
break;
V_8 = F_129 ( V_230 , V_232 ) ;
break;
case V_254 :
V_8 = F_130 ( V_230 , V_232 ) ;
break;
case V_255 :
V_8 = - V_252 ;
if ( ! F_128 ( V_253 ) )
break;
V_8 = F_130 ( V_230 , V_232 ) ;
break;
case V_256 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_232 , & V_83 -> V_111 ,
sizeof( V_83 -> V_111 ) )
? - V_72 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_257 : {
struct V_182 V_111 ;
V_8 = - V_72 ;
if ( F_131 ( & V_111 , V_232 , sizeof( V_111 ) ) )
break;
V_8 = - V_71 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 != V_46 &&
V_19 -> V_45 != V_137 )
goto V_258;
if ( V_111 . V_115 < V_259 ||
V_111 . V_115 > V_260 )
goto V_258;
if ( V_111 . V_117 < V_259 ||
V_111 . V_117 > V_260 )
goto V_258;
if ( V_111 . V_112 < 1 ||
V_111 . V_112 > 127 )
goto V_258;
if ( V_111 . V_118 ) {
int V_70 = V_111 . V_118 & 0xf0 ;
int V_261 = V_111 . V_118 & 0x0f ;
if ( ! V_70 )
V_111 . V_118 |=
V_262 << 4 ;
else if ( V_70 < 0x30 || V_70 > 0xD0 )
goto V_258;
if ( ! V_261 )
V_111 . V_118 |=
V_262 ;
else if ( V_261 < 0x03 || V_261 > 0x0D )
goto V_258;
}
if ( V_111 . V_119 &&
( V_111 . V_119 & 0x81 ) != 0x81 )
goto V_258;
V_83 -> V_111 = V_111 ;
V_8 = 0 ;
V_258:
F_59 ( V_19 ) ;
break;
}
case V_263 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_232 , & V_83 -> V_121 ,
sizeof( V_83 -> V_121 ) ) ;
F_59 ( V_19 ) ;
if ( V_8 )
V_8 = - V_72 ;
break;
}
case V_264 : {
struct V_183 V_265 ;
V_8 = - V_72 ;
if ( F_131 ( & V_265 , V_232 , sizeof( V_265 ) ) )
break;
V_8 = - V_71 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 != V_46 &&
V_19 -> V_45 != V_137 )
goto V_266;
if ( V_265 . V_14 > V_267 )
goto V_266;
if ( V_265 . V_123 == NULL )
goto V_266;
if ( V_265 . V_13 > V_267 )
goto V_266;
if ( V_265 . V_122 == NULL )
goto V_266;
V_83 -> V_121 = V_265 ;
V_8 = 0 ;
V_266:
F_59 ( V_19 ) ;
break;
}
case V_268 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_232 , & V_83 -> V_48 ,
sizeof( V_83 -> V_48 ) )
? - V_72 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_269 : {
struct V_270 V_48 ;
V_8 = - V_72 ;
if ( F_131 ( & V_48 , V_232 , sizeof( V_48 ) ) )
break;
V_8 = - V_71 ;
if ( V_48 . V_193 > V_186 )
break;
F_58 ( V_19 ) ;
V_83 -> V_48 = V_48 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_271 : {
F_58 ( V_19 ) ;
V_8 = F_56 ( V_232 , & V_83 -> V_272 , sizeof( V_83 -> V_272 ) )
? - V_72 : 0 ;
F_59 ( V_19 ) ;
break;
}
case V_273 : {
struct V_274 V_272 ;
V_8 = - V_72 ;
if ( F_131 ( & V_272 , V_232 , sizeof( V_272 ) ) )
break;
F_58 ( V_19 ) ;
V_83 -> V_272 = V_272 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_275 : {
struct V_276 V_277 ;
V_8 = - V_71 ;
F_58 ( V_19 ) ;
if( V_19 -> V_45 != V_137 )
goto V_278;
V_8 = - V_72 ;
if ( F_131 ( & V_277 , V_232 ,
sizeof( V_277 ) ) )
goto V_278;
V_8 = - V_71 ;
if ( V_277 . V_47 > V_186 )
goto V_278;
V_83 -> V_47 = V_277 . V_47 ;
V_8 = 0 ;
V_278:
F_59 ( V_19 ) ;
break;
}
case V_279 : {
V_8 = - V_71 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 != V_137 )
break;
F_51 ( V_110 , & V_83 -> V_74 ) ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
case V_280 : {
V_8 = - V_71 ;
F_58 ( V_19 ) ;
if ( V_19 -> V_45 != V_130 )
break;
if ( F_55 ( V_110 , & V_83 -> V_74 ) )
break;
F_70 ( V_19 , V_192 ) ;
V_83 -> V_54 = V_134 ;
F_59 ( V_19 ) ;
V_8 = 0 ;
break;
}
default:
V_8 = - V_281 ;
break;
}
return V_8 ;
}
static int F_132 ( unsigned int V_230 ,
struct V_282 T_1 * V_283 )
{
struct V_282 V_284 ;
struct V_30 * V_31 ;
struct V_21 * V_22 ;
int V_8 = - V_71 ;
V_8 = - V_72 ;
if ( F_131 ( & V_284 , V_283 , sizeof( * V_283 ) ) )
goto V_70;
V_8 = - V_71 ;
V_22 = F_133 ( V_284 . V_285 ) ;
if ( V_22 == NULL )
goto V_70;
V_31 = F_18 ( V_22 ) ;
if ( V_31 == NULL )
goto V_286;
F_134 ( V_22 ) ;
if ( V_230 == V_254 ) {
F_26 ( & V_287 ) ;
V_284 . V_219 = V_31 -> V_219 ;
V_284 . V_288 = V_31 -> V_288 ;
F_28 ( & V_287 ) ;
V_8 = F_56 ( V_283 , & V_284 ,
sizeof( * V_283 ) ) ? - V_72 : 0 ;
} else {
V_8 = - V_71 ;
if ( V_284 . V_219 == 0 || V_284 . V_219 == 1 ) {
V_8 = 0 ;
F_6 ( & V_287 ) ;
V_31 -> V_219 = V_284 . V_219 ;
V_31 -> V_288 = V_284 . V_288 ;
F_8 ( & V_287 ) ;
}
}
F_20 ( V_31 ) ;
V_70:
return V_8 ;
V_286:
F_134 ( V_22 ) ;
goto V_70;
}
static int F_135 ( struct V_61 * V_18 , unsigned int V_230 ,
unsigned long V_231 )
{
void T_1 * V_232 = F_136 ( V_231 ) ;
struct V_18 * V_19 = V_18 -> V_19 ;
int V_8 = - V_281 ;
switch( V_230 ) {
case V_233 :
case V_235 :
V_8 = F_124 ( V_18 , V_230 , ( unsigned long ) V_232 ) ;
break;
case V_236 :
V_8 = - V_71 ;
if ( V_19 )
V_8 = F_137 ( V_19 ,
(struct V_237 T_1 * ) V_232 ) ;
break;
case V_238 :
V_8 = - V_71 ;
if ( V_19 )
V_8 = F_138 ( V_19 ,
(struct V_239 T_1 * ) V_232 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
V_8 = - V_71 ;
break;
case V_250 :
case V_251 :
V_8 = - V_252 ;
if ( ! F_128 ( V_253 ) )
break;
V_8 = F_129 ( V_230 , V_232 ) ;
break;
case V_254 :
V_8 = F_132 ( V_230 , V_232 ) ;
break;
case V_255 :
V_8 = - V_252 ;
if ( ! F_128 ( V_253 ) )
break;
V_8 = F_132 ( V_230 , V_232 ) ;
break;
case V_256 :
case V_257 :
case V_263 :
case V_264 :
case V_268 :
case V_269 :
case V_271 :
case V_273 :
case V_275 :
case V_279 :
case V_280 :
V_8 = F_124 ( V_18 , V_230 , ( unsigned long ) V_232 ) ;
break;
default:
V_8 = - V_281 ;
break;
}
return V_8 ;
}
void F_139 ( struct V_30 * V_31 )
{
struct V_18 * V_23 ;
F_6 ( & V_20 ) ;
F_10 (s, &x25_list)
if ( F_11 ( V_23 ) -> V_24 == V_31 )
F_12 ( V_23 , V_25 , 0 , 0 ) ;
F_8 ( & V_20 ) ;
F_140 ( V_31 -> V_22 ) ;
}
static int T_3 F_141 ( void )
{
int V_8 = F_142 ( & V_86 , 0 ) ;
if ( V_8 != 0 )
goto V_70;
V_8 = F_143 ( & V_289 ) ;
if ( V_8 != 0 )
goto V_290;
F_144 ( & V_291 ) ;
V_8 = F_145 ( & V_292 ) ;
if ( V_8 != 0 )
goto V_293;
F_146 ( V_294 L_8 ) ;
F_147 () ;
V_8 = F_148 () ;
if ( V_8 != 0 )
goto V_295;
V_70:
return V_8 ;
V_295:
F_149 ( & V_292 ) ;
V_293:
F_150 ( V_84 ) ;
V_290:
F_151 ( & V_86 ) ;
goto V_70;
}
static void T_4 F_152 ( void )
{
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
F_149 ( & V_292 ) ;
F_157 ( & V_291 ) ;
F_150 ( V_84 ) ;
F_151 ( & V_86 ) ;
}
