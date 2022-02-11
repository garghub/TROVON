static T_1
F_1 ( struct V_1 * V_2 , T_1 T_2 * * V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
T_3 V_7 = 0 , V_8 = 0 ;
while ( true ) {
V_6 = F_2 ( * V_3 ) ;
( * V_3 ) ++ ;
if ( V_4 == 0 )
break;
if ( ( V_6 & V_9 ) == 0 ) {
V_7 ++ ;
continue;
}
if ( V_6 == ( V_10 | V_9 ) )
break;
if ( ( V_6 & V_4 ) == V_5 )
break;
V_8 ++ ;
}
return V_6 ;
}
static T_1
F_3 ( struct V_1 * V_2 , T_1 T_2 * * V_3 , T_3 V_11 , T_3 V_12 , T_3 V_13 ,
T_1 * V_14 , T_1 * V_15 , T_1 * V_16 , T_1 * V_17 )
{
T_1 V_18 , V_19 , V_20 ;
V_18 = F_1 ( V_2 , V_3 , V_9 , V_9 ) ;
if ( ( ( V_18 & V_21 ) != V_22 ) ||
( ( ( V_18 & V_23 ) >> V_24 ) != V_11 ) ||
( ( V_18 & V_25 ) != V_13 ) ) {
( * V_3 ) -- ;
return 0 ;
}
* V_14 = V_18 & V_26 ;
if ( V_18 & V_27 )
* V_15 = F_1 ( V_2 , V_3 , 0 , 0 ) ;
else
* V_15 = 0 ;
* V_17 = 0 ;
V_19 = V_18 & V_28 ;
if ( V_19 == V_29 ) {
V_20 = F_1 ( V_2 , V_3 , 0 , 0 ) ;
* V_16 = V_20 & V_30 ;
if ( V_20 & V_31 )
* V_17 = F_1 ( V_2 , V_3 , 0 , 0 ) ;
} else
* V_16 = V_32 << ( V_19 >> V_33 ) ;
return V_18 ;
}
static void F_4 ( struct V_34 * V_35 )
{
}
static void F_5 ( struct V_1 * V_2 , struct V_36 T_2 * V_37 )
{
struct V_34 * V_35 = (struct V_34 * ) V_2 ;
T_1 V_38 ;
T_1 T_2 * V_3 , * V_39 ;
void T_2 * V_40 = V_37 ;
V_38 = F_2 ( & V_37 -> V_3 ) ;
V_35 -> V_41 = ( void * ) ( ( unsigned long ) V_37 + V_42 ) ;
F_6 ( V_35 -> V_43 , V_44 , V_38 ) ;
V_3 = V_40 ;
V_39 = V_3 + ( V_45 / sizeof( T_1 ) ) ;
while ( V_3 < V_39 ) {
T_1 V_46 , V_47 , V_48 , V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ;
T_1 V_55 , V_18 , V_14 , V_15 , V_16 , V_17 ;
T_1 T_2 * V_56 ;
T_3 V_57 , V_58 , V_59 ;
bool V_60 ;
V_60 = false ;
V_46 = F_1 ( V_2 , & V_3 , V_61 , V_62 ) ;
if ( V_46 == ( V_10 | V_9 ) ) {
F_4 ( V_35 ) ;
return;
}
V_56 = V_3 - 1 ;
V_47 = F_1 ( V_2 , & V_3 , 0 , 0 ) ;
if ( ( V_47 & V_61 ) != V_62 ) {
goto error;
}
V_48 = ( V_46 & V_63 ) >> V_64 ;
V_49 = ( V_46 & V_65 ) >> V_66 ;
V_50 = ( V_47 & V_67 ) >> V_68 ;
V_51 = ( V_47 & V_69 ) >> V_70 ;
V_52 = ( V_47 & V_71 ) >> V_72 ;
V_53 = ( V_47 & V_73 ) >> V_74 ;
V_54 = ( V_47 & V_75 ) >> V_76 ;
if ( ( ( V_49 == V_77 ) && ( V_48 == V_78 ) ) || ( V_54 == 0 ) )
continue;
if ( ( V_51 + V_52 == 0 ) ) {
if ( V_48 == V_79 ) {
V_18 = F_3 ( V_2 , & V_3 , 0 , 0 , V_80 ,
& V_14 , & V_15 , & V_16 , & V_17 ) ;
if ( V_18 != 0 )
V_35 -> V_81 = V_14 ;
}
continue;
}
V_59 = V_35 -> V_82 ;
V_35 -> V_46 [ V_59 ] = V_46 ;
V_35 -> V_47 [ V_59 ] = V_47 ;
V_35 -> V_83 [ V_59 ] = V_48 ;
for ( V_57 = 0 ; V_57 < V_53 ; V_57 ++ ) {
V_55 = F_1 ( V_2 , & V_3 , V_9 , V_9 ) ;
if ( ( V_55 & V_61 ) != V_84 ) {
goto error;
}
}
V_18 =
F_3 ( V_2 , & V_3 , 0 , 0 , V_80 , & V_14 , & V_15 ,
& V_16 , & V_17 ) ;
if ( V_18 == 0 ) {
V_18 =
F_3 ( V_2 , & V_3 , 0 , 0 , V_85 , & V_14 ,
& V_15 , & V_16 , & V_17 ) ;
if ( V_18 != 0 )
V_60 = true ;
else if ( ( V_15 != 0 ) || ( V_17 != 0 )
|| ( V_16 != V_42 ) ) {
goto error;
}
}
V_35 -> V_86 [ V_59 ] = V_14 ;
V_35 -> V_87 [ V_59 ] = V_16 ;
V_58 = 1 ;
do {
V_18 =
F_3 ( V_2 , & V_3 , 0 , V_58 , V_80 , & V_14 ,
& V_15 , & V_16 , & V_17 ) ;
if ( ( V_18 != 0 ) && ( V_58 == 1 ) && ( V_16 == V_42 ) ) {
V_35 -> V_88 [ V_59 ] = V_14 ;
V_35 -> V_89 [ V_59 ] = V_16 ;
}
V_58 ++ ;
} while ( V_18 != 0 );
for ( V_57 = 1 ; V_57 < V_54 ; V_57 ++ ) {
V_58 = 0 ;
do {
V_18 =
F_3 ( V_2 , & V_3 , V_57 , V_58 ++ , V_80 ,
& V_14 , & V_15 , & V_16 , & V_17 ) ;
} while ( V_18 != 0 );
if ( V_58 == 0 ) {
goto error;
}
}
for ( V_57 = 0 ; V_57 < V_51 ; V_57 ++ ) {
V_18 =
F_3 ( V_2 , & V_3 , V_57 , 0 , V_90 , & V_14 ,
& V_15 , & V_16 , & V_17 ) ;
if ( V_18 == 0 ) {
goto error;
}
if ( ( V_17 != 0 ) || ( V_16 != V_42 ) ) {
goto error;
}
if ( V_57 == 0 )
V_35 -> V_91 [ V_59 ] = V_14 ;
}
for ( V_57 = 0 ; V_57 < V_52 ; V_57 ++ ) {
T_3 V_92 = ( V_54 == 1 ) ? 0 : 1 ;
V_18 =
F_3 ( V_2 , & V_3 , V_92 + V_57 , 0 , V_93 ,
& V_14 , & V_15 , & V_16 , & V_17 ) ;
if ( V_18 == 0 ) {
goto error;
}
if ( ( V_17 != 0 ) || ( V_16 != V_42 ) ) {
goto error;
}
if ( ( V_51 == 0 ) && ( V_57 == 0 ) )
V_35 -> V_91 [ V_59 ] = V_14 ;
}
if ( V_60 )
continue;
V_35 -> V_82 ++ ;
}
error:
V_35 -> V_82 = 0 ;
return;
}
void T_2 * F_7 ( struct V_1 * V_2 , T_3 V_94 )
{
struct V_34 * V_35 = (struct V_34 * ) V_2 ;
T_1 V_95 = V_35 -> V_86 [ V_94 ] ;
T_1 V_96 = V_35 -> V_91 [ V_94 ] ;
if ( V_94 >= V_35 -> V_82 )
return NULL ;
F_6 ( V_35 -> V_43 , V_44 , V_95 ) ;
F_6 ( V_35 -> V_43 , V_97 , V_96 ) ;
V_35 -> V_98 = V_94 ;
return V_35 -> V_99 ;
}
int F_8 ( struct V_1 * V_2 )
{
return 2 ;
}
T_1 F_9 ( struct V_1 * V_2 , T_3 V_100 )
{
struct V_34 * V_35 ;
T_3 V_101 ;
V_35 = (struct V_34 * ) V_2 ;
V_101 = V_35 -> V_98 ;
if ( V_100 == 0 )
return V_35 -> V_86 [ V_101 ] ;
else if ( V_100 == 1 )
return V_35 -> V_88 [ V_101 ] ;
else {
return 0 ;
}
}
T_1 F_10 ( struct V_1 * V_2 , T_3 V_100 )
{
struct V_34 * V_35 ;
T_3 V_101 ;
V_35 = (struct V_34 * ) V_2 ;
V_101 = V_35 -> V_98 ;
if ( V_100 == 0 )
return V_35 -> V_87 [ V_101 ] ;
else if ( V_100 == 1 )
return V_35 -> V_89 [ V_101 ] ;
else {
return 0 ;
}
}
T_3 F_11 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
return F_2 ( & V_103 -> V_104 ) & 0x1f ;
}
void F_12 ( struct V_1 * V_2 , int V_105 )
{
}
T_3 F_13 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_1 V_46 ;
V_35 = (struct V_34 * ) V_2 ;
V_46 = V_35 -> V_46 [ V_35 -> V_98 ] ;
return ( V_46 & V_65 ) >> V_66 ;
}
T_3 F_14 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_1 V_47 ;
V_35 = (struct V_34 * ) V_2 ;
V_47 = V_35 -> V_47 [ V_35 -> V_98 ] ;
return ( V_47 & V_67 ) >> V_68 ;
}
bool F_15 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
return ( ( ( F_2 ( & V_103 -> V_106 ) & ( V_107 | V_108 ) ) ==
V_108 )
&& ( ( F_2 ( & V_103 -> V_109 ) & V_110 ) == 0 ) ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_111 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
T_1 V_112 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
if ( V_4 || V_111 ) {
V_112 = ( ( F_2 ( & V_103 -> V_106 ) & ~ V_4 ) | V_111 ) ;
F_17 ( & V_103 -> V_106 , V_112 ) ;
}
}
T_1 F_18 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_111 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
T_1 V_112 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
if ( V_4 || V_111 ) {
V_112 = ( ( F_2 ( & V_103 -> V_106 ) & ~ V_4 ) | V_111 ) ;
F_17 ( & V_103 -> V_106 , V_112 ) ;
}
return F_2 ( & V_103 -> V_106 ) ;
}
static bool F_19 ( struct V_34 * V_35 )
{
T_4 V_113 ;
V_113 =
F_20 ( V_35 -> V_43 , V_114 , NULL ,
NULL ) ;
if ( ! V_113 )
return false ;
return true ;
}
static bool F_21 ( struct V_34 * V_35 )
{
if ( ! F_19 ( V_35 ) )
F_22 ( & V_35 -> V_115 , V_116 | V_117 , V_118 ) ;
return true ;
}
T_1 F_23 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_111 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
T_1 V_112 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
if ( V_4 || V_111 ) {
V_112 = ( ( F_2 ( & V_103 -> V_119 ) & ~ V_4 ) | V_111 ) ;
F_17 ( & V_103 -> V_119 , V_112 ) ;
}
return F_2 ( & V_103 -> V_119 ) ;
}
static bool
F_24 ( struct V_34 * V_35 , T_1 V_120 , T_3 * V_121 )
{
bool V_122 , V_123 ;
T_3 V_57 ;
T_3 V_124 , V_125 , V_126 , V_127 ;
struct V_36 T_2 * V_37 ;
V_37 = F_7 ( & V_35 -> V_115 , V_128 ) ;
V_35 -> V_115 . V_129 = ( int ) F_14 ( & V_35 -> V_115 ) ;
if ( V_35 -> V_115 . V_129 >= 11 )
V_35 -> V_115 . V_130 = F_2 ( & V_37 -> V_131 ) ;
V_35 -> V_115 . V_132 = F_2 ( & V_37 -> V_133 ) ;
if ( V_35 -> V_115 . V_129 >= 35 )
V_35 -> V_115 . V_134 = F_2 ( & V_37 -> V_135 ) ;
if ( V_35 -> V_115 . V_132 & V_136 ) {
V_35 -> V_115 . V_137 = F_2 ( & V_37 -> V_138 ) ;
V_35 -> V_115 . V_139 = V_35 -> V_115 . V_137 & V_140 ;
}
V_35 -> V_115 . V_141 = V_142 ;
V_35 -> V_115 . V_143 = V_144 ;
V_35 -> V_115 . V_145 = V_146 ;
V_122 = V_123 = false ;
V_126 = V_127 = V_144 ;
V_124 = V_125 = V_146 ;
for ( V_57 = 0 ; V_57 < V_35 -> V_82 ; V_57 ++ ) {
T_3 V_48 , V_50 ;
F_7 ( & V_35 -> V_115 , V_57 ) ;
V_48 = F_25 ( & V_35 -> V_115 ) ;
V_50 = F_14 ( & V_35 -> V_115 ) ;
if ( V_48 == V_147 ) {
V_124 = V_57 ;
V_126 = V_50 ;
V_122 = true ;
} else if ( V_48 == V_148 ) {
V_125 = V_57 ;
V_127 = V_50 ;
V_123 = true ;
}
if ( ( V_120 && ( V_120 == V_35 -> V_86 [ V_57 ] ) ) ||
( V_37 == V_35 -> V_40 [ V_57 ] ) )
* V_121 = V_57 ;
}
if ( V_122 && V_123 ) {
if ( F_19 ( V_35 ) )
V_122 = false ;
else
V_123 = false ;
}
if ( V_122 ) {
V_35 -> V_115 . V_141 = V_147 ;
V_35 -> V_115 . V_143 = V_126 ;
V_35 -> V_115 . V_145 = V_124 ;
} else if ( V_123 ) {
V_35 -> V_115 . V_141 = V_148 ;
V_35 -> V_115 . V_143 = V_127 ;
V_35 -> V_115 . V_145 = V_125 ;
}
if ( F_26 ( V_35 ) ) {
if ( ! V_35 -> V_149 ) {
V_35 -> V_149 = F_27 ( & V_35 -> V_115 , V_35 -> V_43 ,
( T_2 void * ) F_28 ( V_35 ) ) ;
if ( V_35 -> V_149 == NULL )
return false ;
}
}
if ( F_29 ( & V_35 -> V_115 ) ) {
return false ;
}
F_7 ( & V_35 -> V_115 , * V_121 ) ;
return true ;
}
static T_5 void F_30 ( struct V_34 * V_35 )
{
T_3 V_112 = 0 ;
F_31 ( V_35 -> V_43 , V_150 , & V_112 ) ;
V_35 -> V_115 . V_151 = V_112 & 0xffff ;
V_35 -> V_115 . V_152 = ( V_112 >> 16 ) & 0xffff ;
V_35 -> V_115 . V_153 = F_32 ( & V_35 -> V_115 , V_154 ) ;
}
static struct V_34 * F_33 ( struct V_34 * V_35 ,
void T_2 * V_40 , struct V_155 * V_43 )
{
struct V_1 * V_2 = & V_35 -> V_115 ;
T_1 V_112 , V_120 ;
struct V_36 T_2 * V_37 ;
T_3 V_156 ;
T_3 V_121 ;
memset ( ( unsigned char * ) V_35 , 0 , sizeof( struct V_34 ) ) ;
V_120 = 0 ;
V_2 -> V_145 = V_146 ;
V_35 -> V_99 = V_40 ;
V_35 -> V_43 = V_43 ;
F_31 ( V_35 -> V_43 , V_44 , & V_120 ) ;
if ( ! F_34 ( V_120 , V_157 ) )
V_120 = V_157 ;
F_6 ( V_35 -> V_43 , V_44 ,
V_157 ) ;
V_37 = (struct V_36 T_2 * ) V_40 ;
if ( ! F_21 ( V_35 ) )
return NULL ;
V_112 = F_2 ( & V_37 -> V_158 ) ;
V_156 = ( V_112 & V_159 ) >> V_160 ;
V_2 -> V_161 = V_112 & V_162 ;
V_2 -> V_163 = ( V_112 & V_164 ) >> V_165 ;
V_2 -> V_166 = ( V_112 & V_167 ) >> V_168 ;
V_2 -> V_169 = false ;
if ( V_156 == V_170 ) {
F_35 ( ( L_1 , V_112 ) ) ;
F_5 ( & V_35 -> V_115 , V_37 ) ;
} else {
return NULL ;
}
if ( V_35 -> V_82 == 0 )
return NULL ;
V_121 = V_128 ;
if ( ! F_24 ( V_35 , V_120 , & V_121 ) )
goto exit;
if ( F_36 ( & V_35 -> V_115 , V_37 ) )
goto exit;
F_30 ( V_35 ) ;
V_37 = (struct V_36 T_2 * ) F_37 ( V_2 , V_171 , 0 ) ;
F_17 ( & V_37 -> V_172 , 0 ) ;
F_17 ( & V_37 -> V_173 , 0 ) ;
F_7 ( V_2 , V_121 ) ;
if ( V_2 -> V_132 & V_136 ) {
T_1 V_174 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_174 = F_40 ( V_2 ) ;
F_41 ( V_2 , V_174 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
}
V_112 = F_32 ( V_2 , V_175 ) ;
if ( V_112 == 0 )
V_112 = V_176 ;
F_44 ( V_2 , V_128 , F_45 ( struct V_36 , V_177 ) ,
~ 0 , V_112 ) ;
if ( F_46 ( V_35 ) )
F_47 ( V_35 -> V_149 , V_178 ) ;
if ( V_2 -> V_161 == V_179 ) {
if ( V_2 -> V_163 == 0 ) {
F_35 ( ( L_2 ) ) ;
F_44 ( V_2 , V_128 ,
F_45 ( struct V_36 , V_180 ) ,
V_181 ,
V_181 ) ;
F_48 ( V_2 , 0 , V_182 ,
V_182 ) ;
}
if ( V_2 -> V_163 >= 1 ) {
F_35 ( ( L_3 ) ) ;
F_48 ( V_2 , 0 , V_183 ,
V_183 ) ;
}
}
if ( V_2 -> V_161 == V_184 ) {
F_35 ( ( L_4 ) ) ;
F_48 ( V_2 , 0 , V_185 ,
V_185 ) ;
}
return V_35 ;
exit:
if ( V_35 -> V_149 )
F_49 ( V_35 -> V_149 ) ;
V_35 -> V_149 = NULL ;
return NULL ;
}
struct V_1 *
F_50 ( void T_2 * V_40 , struct V_155 * V_186 )
{
struct V_34 * V_35 ;
V_35 = F_51 ( sizeof( struct V_34 ) , V_187 ) ;
if ( V_35 == NULL )
return NULL ;
if ( F_33 ( V_35 , V_40 , V_186 ) == NULL ) {
F_52 ( V_35 ) ;
return NULL ;
}
return (struct V_1 * ) V_35 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_1 * V_188 = NULL ;
memcpy ( & V_188 , & V_2 , sizeof( struct V_1 * * ) ) ;
V_35 = (struct V_34 * ) V_2 ;
if ( V_35 == NULL )
return;
if ( V_35 -> V_149 )
F_49 ( V_35 -> V_149 ) ;
V_35 -> V_149 = NULL ;
F_54 ( V_2 ) ;
F_52 ( V_35 ) ;
}
void
F_55 ( struct V_1 * V_2 , void * V_189 ,
void * V_190 ,
void * V_191 , void * V_192 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
V_35 -> V_192 = V_192 ;
V_35 -> V_189 = ( T_1 ( * ) ( void * ) ) V_189 ;
V_35 -> V_190 = ( void ( * ) ( void * , T_1 ) ) V_190 ;
V_35 -> V_191 = ( bool ( * ) ( void * ) ) V_191 ;
V_35 -> V_193 = V_35 -> V_83 [ V_35 -> V_98 ] ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
V_35 -> V_189 = NULL ;
}
T_3 F_25 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
return V_35 -> V_83 [ V_35 -> V_98 ] ;
}
T_3 F_57 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
return V_35 -> V_98 ;
}
bool F_58 ( struct V_1 * V_2 )
{
return ( V_2 -> V_132 & V_194 ) != 0 ;
}
T_3 F_59 ( struct V_1 * V_2 , T_3 V_83 , T_3 V_195 )
{
struct V_34 * V_35 ;
T_3 V_196 ;
T_3 V_57 ;
V_35 = (struct V_34 * ) V_2 ;
V_196 = 0 ;
for ( V_57 = 0 ; V_57 < V_35 -> V_82 ; V_57 ++ )
if ( V_35 -> V_83 [ V_57 ] == V_83 ) {
if ( V_196 == V_195 )
return V_57 ;
V_196 ++ ;
}
return V_146 ;
}
void T_2 * F_37 ( struct V_1 * V_2 , T_3 V_83 , T_3 V_195 )
{
T_3 V_59 ;
V_59 = F_59 ( V_2 , V_83 , V_195 ) ;
if ( V_59 >= V_197 )
return NULL ;
return F_7 ( V_2 , V_59 ) ;
}
void T_2 * F_60 ( struct V_1 * V_2 , T_3 V_83 , T_3 * V_121 ,
T_3 * V_198 )
{
void T_2 * V_37 ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_26 ( V_35 ) ) {
* V_121 = V_83 ;
if ( V_83 == V_171 )
return F_61 ( V_35 ) ;
else if ( V_83 == V_2 -> V_141 )
return F_28 ( V_35 ) ;
}
F_62 ( V_35 , * V_198 ) ;
* V_121 = V_35 -> V_98 ;
V_37 = F_37 ( V_2 , V_83 , 0 ) ;
return V_37 ;
}
void F_63 ( struct V_1 * V_2 , T_3 V_83 , T_3 V_198 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_26 ( V_35 )
&& ( ( V_83 == V_171 ) || ( V_83 == V_2 -> V_141 ) ) )
return;
F_7 ( V_2 , V_83 ) ;
F_64 ( V_35 , V_198 ) ;
}
void F_65 ( struct V_1 * V_2 , T_1 V_199 , T_1 V_111 )
{
struct V_34 * V_35 = (struct V_34 * ) V_2 ;
T_1 * V_112 = ( T_1 * ) V_35 -> V_41 ;
F_17 ( V_112 + ( V_199 / 4 ) , V_111 ) ;
return;
}
T_3 F_44 ( struct V_1 * V_2 , T_3 V_94 , T_3 V_200 , T_3 V_4 ,
T_3 V_111 )
{
T_3 V_121 = 0 ;
T_1 T_2 * V_201 = NULL ;
T_3 V_112 ;
T_3 V_198 = 0 ;
bool V_202 = false ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( V_94 >= V_197 )
return 0 ;
if ( ( V_35 -> V_83 [ V_94 ] == V_171 ) && F_26 ( V_35 ) ) {
V_202 = true ;
V_201 = ( T_1 T_2 * ) ( ( T_2 char * ) V_35 -> V_99 +
V_203 + V_200 ) ;
} else if ( V_35 -> V_115 . V_145 == V_94 ) {
V_202 = true ;
if ( F_26 ( V_35 ) )
V_201 = ( T_1 T_2 * ) ( ( T_2 char * ) V_35 -> V_99 +
V_204 + V_200 ) ;
else
V_201 = ( T_1 T_2 * ) ( ( T_2 char * ) V_35 -> V_99 +
( ( V_200 >= V_205 ) ?
V_206 :
V_207 ) + V_200 ) ;
}
if ( ! V_202 ) {
F_62 ( V_35 , V_198 ) ;
V_121 = F_57 ( & V_35 -> V_115 ) ;
V_201 = ( T_1 T_2 * ) ( ( unsigned char T_2 * )
F_7 ( & V_35 -> V_115 , V_94 ) + V_200 ) ;
}
if ( V_4 || V_111 ) {
V_112 = ( F_2 ( V_201 ) & ~ V_4 ) | V_111 ;
F_17 ( V_201 , V_112 ) ;
}
V_112 = F_2 ( V_201 ) ;
if ( ! V_202 ) {
if ( V_121 != V_94 )
F_7 ( & V_35 -> V_115 , V_121 ) ;
F_64 ( V_35 , V_198 ) ;
}
return V_112 ;
}
void F_66 ( struct V_1 * V_2 , T_1 V_208 )
{
struct V_34 * V_35 ;
T_1 V_209 ;
struct V_102 * V_103 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
if ( F_2 ( & V_103 -> V_109 ) & V_110 )
return;
F_17 ( & V_103 -> V_106 , V_208 ) ;
V_209 = F_2 ( & V_103 -> V_106 ) ;
F_67 ( 10 ) ;
F_17 ( & V_103 -> V_109 , V_110 ) ;
F_67 ( 1 ) ;
}
void F_68 ( struct V_1 * V_2 , T_1 V_208 , T_1 V_210 )
{
struct V_34 * V_35 ;
struct V_102 * V_103 ;
T_1 V_209 ;
V_35 = (struct V_34 * ) V_2 ;
V_103 = V_35 -> V_41 ;
F_66 ( V_2 , ( V_208 | V_210 ) ) ;
F_17 ( & V_103 -> V_106 , ( V_208 | V_107 | V_108 ) ) ;
V_209 = F_2 ( & V_103 -> V_106 ) ;
F_17 ( & V_103 -> V_109 , 0 ) ;
F_67 ( 1 ) ;
F_17 ( & V_103 -> V_106 , ( V_208 | V_108 ) ) ;
V_209 = F_2 ( & V_103 -> V_106 ) ;
F_67 ( 1 ) ;
}
static T_3 F_69 ( struct V_34 * V_35 )
{
struct V_36 T_2 * V_37 ;
T_1 V_111 ;
if ( V_35 -> V_115 . V_129 < 6 ) {
F_31 ( V_35 -> V_43 , V_211 ,
& V_111 ) ;
if ( V_111 & V_212 )
return V_213 ;
return V_214 ;
} else if ( V_35 -> V_115 . V_129 < 10 ) {
V_37 = (struct V_36 T_2 * )
F_7 ( & V_35 -> V_115 , V_35 -> V_98 ) ;
return F_2 ( & V_37 -> V_215 ) & V_216 ;
} else
return V_214 ;
}
static T_3 F_70 ( struct V_34 * V_35 , bool V_217 ,
struct V_36 T_2 * V_37 )
{
T_1 V_218 ;
T_3 div ;
V_218 = F_69 ( V_35 ) ;
if ( V_35 -> V_115 . V_129 < 6 ) {
if ( V_218 == V_213 )
return V_217 ? ( V_219 / 64 )
: ( V_220 / 64 ) ;
else
return V_217 ? ( V_221 / 32 )
: ( V_222 / 32 ) ;
} else if ( V_35 -> V_115 . V_129 < 10 ) {
div = 4 *
( ( ( F_2 ( & V_37 -> V_215 ) & V_223 ) >>
V_224 ) + 1 ) ;
if ( V_218 == V_225 )
return V_217 ? V_226 : V_227 ;
else if ( V_218 == V_214 )
return V_217 ? ( V_221 / div )
: ( V_222 / div ) ;
else if ( V_218 == V_213 )
return V_217 ? ( V_219 / div )
: ( V_220 / div ) ;
} else {
div = F_2 ( & V_37 -> V_228 ) >> V_229 ;
div = 4 * ( div + 1 ) ;
return V_217 ? V_221 : ( V_222 / div ) ;
}
return 0 ;
}
static void
F_71 ( struct V_34 * V_35 , struct V_36 T_2 * V_37 )
{
T_3 V_230 , V_231 , V_218 ;
T_3 V_232 , V_233 ;
V_231 = V_234 ;
V_218 = F_69 ( V_35 ) ;
if ( V_218 != V_214 )
V_231 += V_235 ;
V_230 =
F_70 ( V_35 , ( V_35 -> V_115 . V_129 >= 10 ) ? false : true , V_37 ) ;
V_232 = ( ( V_230 * V_231 ) + 999999 ) / 1000000 ;
V_233 = ( ( V_230 * V_236 ) + 999999 ) / 1000000 ;
F_17 ( & V_37 -> V_232 , V_232 ) ;
F_17 ( & V_37 -> V_233 , V_233 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_3 V_121 = 0 ;
struct V_36 T_2 * V_37 ;
bool V_202 ;
if ( ! ( V_2 -> V_132 & V_237 ) )
return;
V_35 = (struct V_34 * ) V_2 ;
V_202 = F_26 ( V_35 ) ;
if ( ! V_202 ) {
V_121 = V_35 -> V_98 ;
V_37 = (struct V_36 T_2 * )
F_37 ( V_2 , V_171 , 0 ) ;
if ( V_37 == NULL )
return;
} else {
V_37 = (struct V_36 T_2 * ) F_61 ( V_35 ) ;
if ( V_37 == NULL )
return;
}
if ( V_2 -> V_129 >= 10 )
F_73 ( & V_37 -> V_228 , V_238 ,
( V_239 << V_229 ) ) ;
F_71 ( V_35 , V_37 ) ;
if ( ! V_202 )
F_7 ( V_2 , V_121 ) ;
}
T_6 F_74 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_3 V_121 = 0 ;
struct V_36 T_2 * V_37 ;
T_3 V_240 ;
T_6 V_241 ;
T_3 V_198 = 0 ;
bool V_202 ;
V_35 = (struct V_34 * ) V_2 ;
if ( V_2 -> V_132 & V_136 ) {
F_62 ( V_35 , V_198 ) ;
V_241 = F_75 ( V_2 ) ;
F_64 ( V_35 , V_198 ) ;
return V_241 ;
}
if ( ! ( V_2 -> V_132 & V_237 ) )
return 0 ;
V_202 = F_26 ( V_35 ) ;
V_241 = 0 ;
if ( ! V_202 ) {
V_121 = V_35 -> V_98 ;
F_62 ( V_35 , V_198 ) ;
V_37 = (struct V_36 T_2 * )
F_37 ( V_2 , V_171 , 0 ) ;
if ( V_37 == NULL )
goto V_242;
} else {
V_37 = (struct V_36 T_2 * ) F_61 ( V_35 ) ;
if ( V_37 == NULL )
goto V_242;
}
V_240 = F_70 ( V_35 , false , V_37 ) ;
V_241 = ( ( ( F_2 ( & V_37 -> V_232 ) + 2 ) * 1000000 ) +
( V_240 - 1 ) ) / V_240 ;
V_242:
if ( ! V_202 ) {
F_7 ( V_2 , V_121 ) ;
F_64 ( V_35 , V_198 ) ;
}
return V_241 ;
}
int F_22 ( struct V_1 * V_2 , T_3 V_243 , bool V_244 )
{
struct V_34 * V_35 ;
T_1 V_245 , V_246 , V_247 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_46 ( V_35 ) )
return - 1 ;
F_31 ( V_35 -> V_43 , V_248 , & V_245 ) ;
F_31 ( V_35 -> V_43 , V_211 , & V_246 ) ;
F_31 ( V_35 -> V_43 , V_249 , & V_247 ) ;
if ( V_244 && ( V_245 & V_250 ) )
return 0 ;
if ( V_243 & V_116 )
V_247 |= V_250 ;
if ( V_243 & V_117 )
V_247 |= V_251 ;
if ( V_244 ) {
if ( V_243 & V_116 ) {
V_246 |= V_250 ;
if ( V_243 & V_117 )
V_246 |= V_251 ;
F_6 ( V_35 -> V_43 ,
V_211 , V_246 ) ;
F_6 ( V_35 -> V_43 ,
V_249 , V_247 ) ;
F_67 ( V_235 ) ;
}
if ( V_243 & V_117 ) {
V_246 &= ~ V_251 ;
F_6 ( V_35 -> V_43 ,
V_211 , V_246 ) ;
F_76 ( 2 ) ;
}
} else {
if ( V_243 & V_116 )
V_246 &= ~ V_250 ;
if ( V_243 & V_117 )
V_246 |= V_251 ;
F_6 ( V_35 -> V_43 ,
V_211 , V_246 ) ;
F_6 ( V_35 -> V_43 ,
V_249 , V_247 ) ;
}
return 0 ;
}
static bool F_77 ( struct V_34 * V_35 , T_3 V_252 )
{
T_3 V_121 = 0 ;
struct V_36 T_2 * V_37 ;
T_1 V_253 ;
T_3 V_198 = 0 ;
bool V_202 = F_26 ( V_35 ) ;
if ( V_35 -> V_115 . V_129 < 6 )
return false ;
if ( ! V_202 ) {
F_62 ( V_35 , V_198 ) ;
V_121 = V_35 -> V_98 ;
V_37 = (struct V_36 T_2 * )
F_37 ( & V_35 -> V_115 , V_171 , 0 ) ;
} else {
V_37 = (struct V_36 T_2 * ) F_61 ( V_35 ) ;
if ( V_37 == NULL )
goto V_242;
}
if ( ! ( V_35 -> V_115 . V_132 & V_237 ) && ( V_35 -> V_115 . V_129 < 20 ) )
goto V_242;
switch ( V_252 ) {
case V_254 :
if ( V_35 -> V_115 . V_129 < 10 ) {
F_22 ( & V_35 -> V_115 , V_116 , V_118 ) ;
F_73 ( & V_37 -> V_215 ,
( V_255 | V_256 | V_257 ) , V_257 ) ;
} else if ( V_35 -> V_115 . V_129 < 20 ) {
F_78 ( & V_37 -> V_228 , V_258 ) ;
} else {
F_78 ( & V_37 -> V_259 , V_260 ) ;
}
if ( V_35 -> V_115 . V_132 & V_136 ) {
T_1 V_261 = V_262 ;
F_79 ( ( ( F_2 ( & V_37 -> V_259 ) & V_261 )
== 0 ) , V_263 ) ;
} else {
F_67 ( V_234 ) ;
}
break;
case V_264 :
if ( V_35 -> V_115 . V_129 < 10 ) {
V_253 = F_2 ( & V_37 -> V_215 ) ;
V_253 &= ~ ( V_256 | V_257 | V_255 ) ;
if ( ( V_253 & V_216 ) != V_214 )
V_253 |= V_255 ;
F_17 ( & V_37 -> V_215 , V_253 ) ;
if ( V_253 & V_255 )
F_22 ( & V_35 -> V_115 , V_116 , V_265 ) ;
} else if ( V_35 -> V_115 . V_129 < 20 ) {
F_80 ( & V_37 -> V_228 , ~ V_258 ) ;
} else {
F_80 ( & V_37 -> V_259 , ~ V_260 ) ;
}
break;
default:
break;
}
V_242:
if ( ! V_202 ) {
F_7 ( & V_35 -> V_115 , V_121 ) ;
F_64 ( V_35 , V_198 ) ;
}
return V_252 == V_254 ;
}
bool F_81 ( struct V_1 * V_2 , T_3 V_252 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( V_2 -> V_129 < 6 )
return false ;
if ( F_82 ( V_35 ) )
return V_252 == V_254 ;
return F_77 ( V_35 , V_252 ) ;
}
int F_83 ( struct V_1 * V_2 , char * V_266 , int V_267 )
{
int V_268 ;
if ( ! V_266 || V_267 <= 0 )
return - 1 ;
V_268 = snprintf ( V_266 , ( V_269 ) V_267 , L_5 ,
( (struct V_34 * ) V_2 ) -> V_43 -> V_270 -> V_271 ,
F_84 ( ( (struct V_155 * )
( ( (struct V_34 * ) ( V_2 ) ) -> V_43 ) ) -> V_272 ) ) ;
if ( V_268 < 0 || V_268 >= V_267 ) {
V_266 [ 0 ] = '\0' ;
return - 1 ;
}
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_82 ( V_35 ) )
F_77 ( V_35 , V_254 ) ;
if ( F_46 ( V_35 ) )
F_86 ( V_35 -> V_149 , V_273 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
F_88 ( V_35 -> V_149 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_82 ( V_35 ) )
F_77 ( V_35 , V_264 ) ;
F_90 ( V_35 -> V_149 , V_274 ) ;
}
void F_91 ( struct V_1 * V_2 , T_3 V_275 )
{
struct V_34 * V_35 ;
struct V_276 T_2 * V_40 = NULL ;
T_1 V_105 = 0 , V_112 ;
T_3 V_59 = 0 ;
V_35 = (struct V_34 * ) V_2 ;
if ( F_92 ( V_35 ) ) {
V_59 = V_35 -> V_98 ;
V_105 = F_11 ( V_2 ) ;
V_40 = F_7 ( V_2 , V_35 -> V_115 . V_145 ) ;
}
if ( F_46 ( V_35 ) || ( F_92 ( V_35 ) && ( ( V_35 -> V_115 . V_143 ) >= 6 ) ) ) {
F_31 ( V_35 -> V_43 , V_277 , & V_112 ) ;
V_112 |= ( V_275 << V_278 ) ;
F_6 ( V_35 -> V_43 , V_277 , V_112 ) ;
} else {
F_12 ( V_2 , V_105 ) ;
}
if ( F_92 ( V_35 ) ) {
F_93 ( V_35 -> V_149 , V_40 ) ;
F_7 ( V_2 , V_59 ) ;
}
}
int F_29 ( struct V_1 * V_2 )
{
T_3 V_121 ;
void T_2 * V_40 = NULL ;
struct V_34 * V_35 = (struct V_34 * ) V_2 ;
V_121 = F_57 ( & V_35 -> V_115 ) ;
V_40 = F_37 ( & V_35 -> V_115 , V_35 -> V_115 . V_141 , 0 ) ;
if ( V_35 -> V_115 . V_141 == V_148 )
F_94 ( V_35 -> V_149 ,
(struct V_279 T_2 * ) V_40 ) ;
else if ( V_35 -> V_115 . V_141 == V_147 )
F_95 ( V_35 -> V_149 , (struct V_276 T_2 * ) V_40 ) ;
F_7 ( & V_35 -> V_115 , V_121 ) ;
F_96 ( V_35 -> V_149 ) ;
return 0 ;
}
T_1 F_97 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_111 , T_4 V_280 )
{
T_3 V_200 ;
V_200 = F_45 ( struct V_36 , V_281 ) ;
return F_44 ( V_2 , V_128 , V_200 , V_4 , V_111 ) ;
}
void F_98 ( struct V_1 * V_2 , bool V_244 )
{
struct V_34 * V_35 ;
struct V_36 T_2 * V_37 ;
T_3 V_121 ;
T_1 V_111 ;
V_35 = (struct V_34 * ) V_2 ;
V_121 = F_57 ( V_2 ) ;
V_37 = (struct V_36 T_2 * ) F_37 ( V_2 , V_171 , 0 ) ;
V_111 = F_2 ( & V_37 -> V_180 ) ;
if ( V_244 ) {
if ( V_2 -> V_166 == 9 || V_2 -> V_166 == 0xb )
F_17 ( & V_37 -> V_180 , V_111 |
V_282 |
V_283 ) ;
else
F_17 ( & V_37 -> V_180 ,
V_111 | V_282 ) ;
} else {
V_111 &= ~ ( V_282 | V_283 ) ;
F_17 ( & V_37 -> V_180 , V_111 ) ;
}
F_7 ( V_2 , V_121 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_36 T_2 * V_37 ;
T_3 V_121 ;
V_35 = (struct V_34 * ) V_2 ;
V_121 = F_57 ( V_2 ) ;
V_37 = F_37 ( V_2 , V_171 , 0 ) ;
F_17 ( & V_37 -> V_281 ,
F_2 ( & V_37 -> V_281 ) | V_284 ) ;
F_7 ( V_2 , V_121 ) ;
}
bool F_100 ( struct V_1 * V_2 )
{
T_1 V_112 ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_2 ;
F_31 ( V_35 -> V_43 , V_285 , & V_112 ) ;
if ( ( V_112 & 0xFFFF ) != V_286 )
return true ;
return false ;
}
bool F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_129 >= 31 ) {
struct V_34 * V_35 ;
T_3 V_121 ;
struct V_36 T_2 * V_37 ;
T_1 V_287 ;
if ( ( V_2 -> V_132 & V_288 ) == 0 )
return false ;
V_35 = (struct V_34 * ) V_2 ;
V_121 = V_35 -> V_98 ;
V_37 = F_7 ( V_2 , V_128 ) ;
V_287 = F_2 ( & V_37 -> V_289 ) ;
F_7 ( V_2 , V_121 ) ;
return V_287 & V_290 ;
}
switch ( V_2 -> V_161 ) {
case V_184 :
return ( V_2 -> V_130 & V_291 ) != 0 ;
default:
return true ;
}
}
bool F_102 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_161 ) {
case V_184 :
return ( V_2 -> V_130 & V_292 ) == 0 ;
case V_179 :
case V_293 :
default:
return false ;
}
}
