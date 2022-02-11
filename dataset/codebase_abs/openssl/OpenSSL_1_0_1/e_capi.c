static int F_1 ( T_1 * V_1 , int V_2 , long V_3 , void * V_4 , void (* F_2)( void ) )
{
int V_5 = 1 ;
T_2 * V_6 ;
T_3 * V_7 ;
if ( V_8 == - 1 )
{
F_3 ( V_9 , V_10 ) ;
return 0 ;
}
V_6 = F_4 ( V_1 , V_8 ) ;
V_7 = F_5 ( stdout , V_11 ) ;
switch ( V_2 )
{
case V_12 :
V_5 = F_6 ( V_6 , V_7 ) ;
break;
case V_13 :
V_5 = F_7 ( V_6 , V_7 , NULL ) ;
break;
case V_14 :
V_5 = F_7 ( V_6 , V_7 , V_4 ) ;
break;
case V_15 :
V_5 = F_8 ( V_6 , V_7 ) ;
break;
case V_16 :
if ( V_6 -> V_17 )
F_9 ( V_6 -> V_17 ) ;
V_6 -> V_17 = F_10 ( V_4 ) ;
F_11 ( V_6 , L_1 , V_4 ) ;
break;
case V_18 :
if ( V_3 & 1 )
{
V_6 -> V_19 |= V_20 ;
V_6 -> V_19 &= ~ V_21 ;
}
else
{
V_6 -> V_19 |= V_21 ;
V_6 -> V_19 &= ~ V_20 ;
}
F_11 ( V_6 , L_2 , V_3 ) ;
break;
case V_22 :
V_6 -> V_23 = ( int ) V_3 ;
F_11 ( V_6 , L_3 , V_6 -> V_23 ) ;
break;
case V_24 :
V_6 -> V_25 = F_10 ( V_4 ) ;
F_11 ( V_6 , L_4 , V_6 -> V_25 ) ;
break;
case V_26 :
V_6 -> V_27 = V_3 ;
F_11 ( V_6 , L_5 , V_6 -> V_27 ) ;
break;
case V_28 :
V_5 = F_12 ( V_6 , V_3 ) ;
break;
case V_29 :
V_6 -> V_30 = V_3 ;
break;
case V_31 :
if ( V_3 < 1 || V_3 > 3 )
{
F_3 ( V_9 , V_32 ) ;
return 0 ;
}
V_6 -> V_33 = V_3 ;
break;
case V_34 :
V_5 = F_13 ( V_6 , V_4 , V_6 -> V_35 , 1 ) ;
break;
case V_36 :
V_6 -> V_35 = V_3 ;
break;
default:
F_3 ( V_9 , V_37 ) ;
V_5 = 0 ;
}
F_14 ( V_7 ) ;
return V_5 ;
}
static int F_15 ( T_1 * V_1 )
{
T_2 * V_6 ;
const T_4 * V_38 ;
const T_5 * V_39 ;
if ( V_8 < 0 )
{
V_8 = F_16 ( 0 , NULL , NULL , NULL , 0 ) ;
if ( V_8 < 0 )
goto V_40;
V_41 = F_17 ( 0 , NULL , NULL , NULL , 0 ) ;
V_42 = F_18 ( 0 , NULL , NULL , NULL , 0 ) ;
V_38 = F_19 () ;
V_43 . V_44 = V_38 -> V_44 ;
V_43 . V_45 = V_38 -> V_45 ;
V_43 . V_46 = V_38 -> V_46 ;
V_43 . V_47 = V_38 -> V_47 ;
V_48 = F_20 ( 0 , NULL , NULL , NULL , 0 ) ;
V_39 = F_21 () ;
V_49 . V_50 = V_39 -> V_50 ;
V_49 . V_51 = V_39 -> V_51 ;
V_49 . V_47 = V_39 -> V_47 ;
}
V_6 = F_22 () ;
if ( ! V_6 )
goto V_40;
F_23 ( V_1 , V_8 , V_6 ) ;
#ifdef F_24
{
T_6 V_52 = F_25 ( F_26 ( L_6 ) ) ;
T_6 V_53 = F_27 ( F_26 ( L_7 ) ) ;
if ( V_52 )
V_6 -> V_54 = ( V_55 ) F_28 ( V_52 , L_8 ) ;
if ( V_53 )
V_6 -> V_56 = ( V_57 ) F_28 ( V_53 , L_9 ) ;
if ( V_52 && ! F_29 () )
V_6 -> V_58 = V_59 ;
}
#endif
return 1 ;
V_40:
F_3 ( V_60 , V_61 ) ;
return 0 ;
return 1 ;
}
static int F_30 ( T_1 * V_1 )
{
F_31 () ;
return 1 ;
}
static int F_32 ( T_1 * V_1 )
{
T_2 * V_6 ;
V_6 = F_4 ( V_1 , V_8 ) ;
F_33 ( V_6 ) ;
F_23 ( V_1 , V_8 , NULL ) ;
return 1 ;
}
static int F_34 ( T_1 * V_1 )
{
if ( ! F_35 ( V_1 , V_62 )
|| ! F_36 ( V_1 , V_63 )
|| ! F_37 ( V_1 , V_64 )
|| ! F_38 ( V_1 , F_15 )
|| ! F_39 ( V_1 , F_32 )
|| ! F_40 ( V_1 , F_30 )
|| ! F_41 ( V_1 , & V_43 )
|| ! F_42 ( V_1 , & V_49 )
|| ! F_43 ( V_1 , V_65 )
|| ! F_44 ( V_1 ,
V_66 )
|| ! F_45 ( V_1 , V_67 )
|| ! F_46 ( V_1 , F_1 ) )
return 0 ;
F_47 () ;
return 1 ;
}
static int F_48 ( T_1 * V_1 , const char * V_68 )
{
if( V_68 && ( strcmp ( V_68 , V_62 ) != 0 ) )
return 0 ;
if( ! F_34 ( V_1 ) )
return 0 ;
return 1 ;
}
static T_1 * F_49 ( void )
{
T_1 * V_5 = F_50 () ;
if( ! V_5 )
return NULL ;
if( ! F_34 ( V_5 ) )
{
F_51 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
void F_52 ( void )
{
T_1 * V_69 = F_49 () ;
if( ! V_69 ) return;
F_53 ( V_69 ) ;
F_51 ( V_69 ) ;
F_54 () ;
}
static int F_55 ( T_7 * V_70 , unsigned char * V_71 , int V_72 )
{
int V_3 ;
for( V_3 = 0 ; V_3 < V_72 / 2 ; V_3 ++ )
{
unsigned char V_73 ;
V_73 = V_71 [ V_3 ] ;
V_71 [ V_3 ] = V_71 [ V_72 - V_3 - 1 ] ;
V_71 [ V_72 - V_3 - 1 ] = V_73 ;
}
if ( ! F_56 ( V_71 , V_72 , V_70 ) )
return 0 ;
return 1 ;
}
static T_8 * F_57 ( T_1 * V_74 , T_9 * V_75 )
{
unsigned char * V_76 = NULL ;
T_10 V_77 ;
T_11 * V_78 ;
T_12 * V_79 = NULL ;
T_13 * V_80 = NULL ;
T_8 * V_5 = NULL ;
if ( ! F_58 ( V_75 -> V_75 , 0 , V_81 , 0 , NULL , & V_77 ) )
{
F_3 ( V_82 , V_83 ) ;
F_59 () ;
return NULL ;
}
V_76 = F_60 ( V_77 ) ;
if ( ! V_76 )
goto V_40;
if ( ! F_58 ( V_75 -> V_75 , 0 , V_81 , 0 , V_76 , & V_77 ) )
{
F_3 ( V_82 , V_84 ) ;
F_59 () ;
goto V_85;
}
V_78 = ( T_11 * ) V_76 ;
if ( V_78 -> V_86 != V_81 )
{
F_3 ( V_82 , V_87 ) ;
goto V_85;
}
if ( V_78 -> V_88 == V_89 || V_78 -> V_88 == V_90 )
{
T_14 * V_91 ;
T_10 V_92 ;
unsigned char * V_93 ;
V_91 = ( T_14 * ) ( V_78 + 1 ) ;
if ( V_91 -> V_94 != 0x31415352 )
{
char V_95 [ 10 ] ;
F_61 ( V_95 , 10 , L_10 , V_91 -> V_94 ) ;
F_3 ( V_82 , V_96 ) ;
F_62 ( 2 , L_11 , V_95 ) ;
goto V_85;
}
V_93 = ( unsigned char * ) ( V_91 + 1 ) ;
V_79 = F_63 ( V_74 ) ;
if ( ! V_79 )
goto V_40;
V_79 -> V_1 = F_64 () ;
V_79 -> V_97 = F_64 () ;
if ( ! V_79 -> V_1 || ! V_79 -> V_97 )
goto V_40;
if ( ! F_65 ( V_79 -> V_1 , V_91 -> V_98 ) )
goto V_40;
V_92 = V_91 -> V_99 / 8 ;
if ( ! F_55 ( V_79 -> V_97 , V_93 , V_92 ) )
goto V_40;
F_66 ( V_79 , V_42 , V_75 ) ;
if ( ! ( V_5 = F_67 () ) )
goto V_40;
F_68 ( V_5 , V_79 ) ;
V_79 = NULL ;
}
else if ( V_78 -> V_88 == V_100 )
{
T_15 * V_101 ;
T_10 V_102 ;
unsigned char * V_103 ;
V_101 = ( T_15 * ) ( V_78 + 1 ) ;
if ( V_101 -> V_94 != 0x31535344 )
{
char V_95 [ 10 ] ;
F_61 ( V_95 , 10 , L_10 , V_101 -> V_94 ) ;
F_3 ( V_82 , V_104 ) ;
F_62 ( 2 , L_11 , V_95 ) ;
goto V_85;
}
V_102 = V_101 -> V_99 / 8 ;
V_103 = ( unsigned char * ) ( V_101 + 1 ) ;
V_80 = F_69 ( V_74 ) ;
if ( ! V_80 )
goto V_40;
V_80 -> V_4 = F_64 () ;
V_80 -> V_105 = F_64 () ;
V_80 -> V_106 = F_64 () ;
V_80 -> V_107 = F_64 () ;
if ( ! V_80 -> V_4 || ! V_80 -> V_105 || ! V_80 -> V_106 || ! V_80 -> V_107 )
goto V_40;
if ( ! F_55 ( V_80 -> V_4 , V_103 , V_102 ) )
goto V_40;
V_103 += V_102 ;
if ( ! F_55 ( V_80 -> V_105 , V_103 , 20 ) )
goto V_40;
V_103 += 20 ;
if ( ! F_55 ( V_80 -> V_106 , V_103 , V_102 ) )
goto V_40;
V_103 += V_102 ;
if ( ! F_55 ( V_80 -> V_107 , V_103 , V_102 ) )
goto V_40;
V_103 += V_102 ;
F_70 ( V_80 , V_48 , V_75 ) ;
if ( ! ( V_5 = F_67 () ) )
goto V_40;
F_71 ( V_5 , V_80 ) ;
V_80 = NULL ;
}
else
{
char V_108 [ 10 ] ;
F_61 ( V_108 , 10 , L_10 , V_78 -> V_88 ) ;
F_3 ( V_82 , V_109 ) ;
F_62 ( 2 , L_12 , V_108 ) ;
goto V_85;
}
V_85:
if ( V_76 )
F_9 ( V_76 ) ;
if ( ! V_5 )
{
if ( V_79 )
F_72 ( V_79 ) ;
if ( V_80 )
F_73 ( V_80 ) ;
}
return V_5 ;
V_40:
F_3 ( V_82 , V_61 ) ;
goto V_85;
}
static T_8 * V_65 ( T_1 * V_74 , const char * V_110 ,
T_16 * V_111 , void * V_112 )
{
T_2 * V_6 ;
T_9 * V_75 ;
T_8 * V_5 ;
V_6 = F_4 ( V_74 , V_8 ) ;
if ( ! V_6 )
{
F_3 ( V_113 , V_114 ) ;
return NULL ;
}
V_75 = F_74 ( V_6 , V_110 ) ;
if ( ! V_75 )
return NULL ;
V_5 = F_57 ( V_74 , V_75 ) ;
if ( ! V_5 )
F_75 ( V_75 ) ;
return V_5 ;
}
int F_76 ( int V_115 , const unsigned char * V_116 ,
unsigned char * V_117 , T_12 * V_118 , int V_119 )
{
F_3 ( V_120 , V_121 ) ;
return - 1 ;
}
int F_77 ( int V_122 , const unsigned char * V_123 , unsigned int V_124 ,
unsigned char * V_125 , unsigned int * V_126 , const T_12 * V_118 )
{
T_17 V_127 ;
T_18 V_128 ;
T_10 V_129 ;
unsigned int V_3 ;
int V_5 = - 1 ;
T_9 * V_130 ;
T_2 * V_6 ;
V_6 = F_4 ( V_118 -> V_131 , V_8 ) ;
F_11 ( V_6 , L_13 ) ;
V_130 = F_78 ( V_118 , V_42 ) ;
if ( ! V_130 )
{
F_3 ( V_132 , V_133 ) ;
return - 1 ;
}
switch( V_122 )
{
case V_134 :
V_127 = V_135 ;
break;
case V_136 :
V_127 = V_137 ;
break;
case V_138 :
V_127 = V_139 ;
break;
default:
{
char V_108 [ 10 ] ;
F_61 ( V_108 , 10 , L_10 , V_122 ) ;
F_3 ( V_132 , V_140 ) ;
F_62 ( 2 , L_14 , V_108 ) ;
return - 1 ;
}
}
if( ! F_79 ( V_130 -> V_141 , V_127 , 0 , 0 , & V_128 ) )
{
F_3 ( V_132 , V_142 ) ;
F_59 () ;
return - 1 ;
}
if( ! F_80 ( V_128 , V_143 , ( unsigned char * ) V_123 , 0 ) )
{
F_3 ( V_132 , V_144 ) ;
F_59 () ;
goto V_85;
}
V_129 = F_81 ( V_118 ) ;
if( ! F_82 ( V_128 , V_130 -> V_145 , NULL , 0 , V_125 , & V_129 ) )
{
F_3 ( V_132 , V_146 ) ;
F_59 () ;
goto V_85;
}
else
{
V_5 = 1 ;
for( V_3 = 0 ; V_3 < V_129 / 2 ; V_3 ++ )
{
unsigned char V_73 ;
V_73 = V_125 [ V_3 ] ;
V_125 [ V_3 ] = V_125 [ V_129 - V_3 - 1 ] ;
V_125 [ V_129 - V_3 - 1 ] = V_73 ;
}
* V_126 = V_129 ;
}
V_85:
F_83 ( V_128 ) ;
return V_5 ;
}
int F_84 ( int V_115 , const unsigned char * V_116 ,
unsigned char * V_117 , T_12 * V_118 , int V_119 )
{
int V_3 ;
unsigned char * V_147 ;
T_9 * V_130 ;
T_2 * V_6 ;
V_6 = F_4 ( V_118 -> V_131 , V_8 ) ;
F_11 ( V_6 , L_15 ) ;
V_130 = F_78 ( V_118 , V_42 ) ;
if ( ! V_130 )
{
F_3 ( V_148 , V_133 ) ;
return - 1 ;
}
if( V_119 != V_149 )
{
char V_150 [ 10 ] ;
F_61 ( V_150 , 10 , L_16 , V_119 ) ;
F_3 ( V_148 , V_151 ) ;
F_62 ( 2 , L_17 , V_150 ) ;
return - 1 ;
}
if( ! ( V_147 = F_60 ( V_115 ) ) )
{
F_3 ( V_148 , V_61 ) ;
return - 1 ;
}
for( V_3 = 0 ; V_3 < V_115 ; V_3 ++ )
V_147 [ V_115 - V_3 - 1 ] = V_116 [ V_3 ] ;
if( ! F_85 ( V_130 -> V_75 , 0 , TRUE , 0 , V_147 , & V_115 ) )
{
F_3 ( V_148 , V_152 ) ;
F_59 () ;
F_9 ( V_147 ) ;
return - 1 ;
}
else memcpy ( V_117 , V_147 , V_115 ) ;
F_9 ( V_147 ) ;
return V_115 ;
}
static int F_86 ( T_12 * V_118 )
{
T_9 * V_130 ;
V_130 = F_78 ( V_118 , V_42 ) ;
F_75 ( V_130 ) ;
F_66 ( V_118 , V_42 , 0 ) ;
return 1 ;
}
static T_19 * F_87 ( const unsigned char * V_153 , int V_154 ,
T_13 * V_155 )
{
T_18 V_128 ;
T_10 V_129 ;
T_19 * V_5 = NULL ;
T_9 * V_130 ;
T_2 * V_6 ;
unsigned char V_156 [ 40 ] ;
V_6 = F_4 ( V_155 -> V_131 , V_8 ) ;
F_11 ( V_6 , L_18 ) ;
V_130 = F_88 ( V_155 , V_48 ) ;
if ( ! V_130 )
{
F_3 ( V_157 , V_133 ) ;
return NULL ;
}
if ( V_154 != 20 )
{
F_3 ( V_157 , V_158 ) ;
return NULL ;
}
if( ! F_79 ( V_130 -> V_141 , V_135 , 0 , 0 , & V_128 ) )
{
F_3 ( V_157 , V_142 ) ;
F_59 () ;
return NULL ;
}
if( ! F_80 ( V_128 , V_143 , ( unsigned char * ) V_153 , 0 ) )
{
F_3 ( V_157 , V_144 ) ;
F_59 () ;
goto V_85;
}
V_129 = sizeof( V_156 ) ;
if( ! F_82 ( V_128 , V_130 -> V_145 , NULL , 0 , V_156 , & V_129 ) )
{
F_3 ( V_157 , V_146 ) ;
F_59 () ;
goto V_85;
}
else
{
V_5 = F_89 () ;
if ( ! V_5 )
goto V_85;
V_5 -> V_159 = F_64 () ;
V_5 -> V_160 = F_64 () ;
if ( ! V_5 -> V_159 || ! V_5 -> V_160 )
goto V_85;
if ( ! F_55 ( V_5 -> V_159 , V_156 , 20 )
|| ! F_55 ( V_5 -> V_160 , V_156 + 20 , 20 ) )
{
F_90 ( V_5 ) ;
V_5 = NULL ;
goto V_85;
}
}
V_85:
F_91 ( V_156 , 40 ) ;
F_83 ( V_128 ) ;
return V_5 ;
}
static int F_92 ( T_13 * V_155 )
{
T_9 * V_130 ;
V_130 = F_88 ( V_155 , V_48 ) ;
F_75 ( V_130 ) ;
F_70 ( V_155 , V_48 , 0 ) ;
return 1 ;
}
static void F_93 ( T_2 * V_6 , int V_161 , char * V_162 , T_20 V_163 )
{
T_3 * V_7 ;
if ( ! V_6 || ( V_6 -> V_23 < V_161 ) || ( ! V_6 -> V_25 ) )
return;
V_7 = F_94 ( V_6 -> V_25 , L_19 ) ;
F_95 ( V_7 , V_162 , V_163 ) ;
F_14 ( V_7 ) ;
}
static void F_11 ( T_2 * V_6 , char * V_162 , ... )
{
T_20 args ;
va_start ( args , V_162 ) ;
F_93 ( V_6 , V_164 , V_162 , args ) ;
va_end ( args ) ;
}
static void F_59 ( void )
{
F_96 ( F_97 () ) ;
}
static void F_96 ( T_10 V_85 )
{
char V_150 [ 10 ] ;
F_61 ( V_150 , 10 , L_20 , V_85 ) ;
F_62 ( 2 , L_21 , V_150 ) ;
}
static char * F_98 ( T_21 V_165 )
{
char * V_166 ;
int V_167 , V_168 ;
if ( ! V_165 )
return NULL ;
V_167 = ( int ) wcslen ( V_165 ) + 1 ;
V_168 = F_99 ( V_169 , 0 , V_165 , V_167 , NULL , 0 , NULL , NULL ) ;
if ( ! V_168 )
{
F_3 ( V_170 , V_171 ) ;
return NULL ;
}
V_166 = F_60 ( V_168 ) ;
if ( ! V_166 )
{
F_3 ( V_170 , V_61 ) ;
return NULL ;
}
if ( ! F_99 ( V_169 , 0 , V_165 , V_167 , V_166 , V_168 , NULL , NULL ) )
{
F_9 ( V_166 ) ;
F_3 ( V_170 , V_171 ) ;
return NULL ;
}
return V_166 ;
}
static int F_100 ( T_2 * V_6 , T_22 * V_172 , T_10 * V_173 , T_10 V_174 )
{
T_22 V_175 ;
T_10 V_77 , V_85 ;
F_11 ( V_6 , L_22 , V_174 ) ;
if ( ! F_101 ( V_174 , NULL , 0 , V_173 , NULL , & V_77 ) )
{
V_85 = F_97 () ;
if ( V_85 == V_176 )
return 2 ;
F_3 ( V_177 , V_178 ) ;
F_96 ( V_85 ) ;
return 0 ;
}
V_175 = F_60 ( V_77 ) ;
if ( ! F_101 ( V_174 , NULL , 0 , V_173 , V_175 , & V_77 ) )
{
V_85 = F_97 () ;
if ( V_85 == V_176 )
return 2 ;
F_3 ( V_177 , V_178 ) ;
F_96 ( V_85 ) ;
return 0 ;
}
* V_172 = V_175 ;
F_11 ( V_6 , L_23 , V_175 , * V_173 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_6 , T_3 * V_7 )
{
T_10 V_174 , V_173 ;
int V_5 ;
T_22 V_179 = NULL ;
F_11 ( V_6 , L_24 ) ;
F_102 ( V_7 , L_25 ) ;
for( V_174 = 0 ; ; V_174 ++ )
{
V_5 = F_100 ( V_6 , & V_179 , & V_173 , V_174 ) ;
if ( V_5 == 2 )
break;
if ( V_5 == 0 )
break;
F_102 ( V_7 , L_26 , V_174 , V_179 , V_173 ) ;
F_9 ( V_179 ) ;
}
return 1 ;
}
static int F_8 ( T_2 * V_6 , T_3 * V_7 )
{
int V_5 = 1 ;
T_23 V_141 ;
T_10 V_85 , V_174 , V_180 , V_181 = 0 , V_182 ;
T_22 V_183 ;
F_11 ( V_6 , L_27 , V_6 -> V_184 , V_6 -> V_35 ) ;
if ( ! F_103 ( & V_141 , NULL , V_6 -> V_184 , V_6 -> V_35 , V_185 ) )
{
F_3 ( V_186 , V_187 ) ;
F_59 () ;
return 0 ;
}
if ( ! F_104 ( V_141 , V_188 , NULL , & V_181 , V_189 ) )
{
F_3 ( V_186 , V_190 ) ;
F_59 () ;
F_105 ( V_141 , 0 ) ;
return 0 ;
}
F_11 ( V_6 , L_28 , V_181 ) ;
if ( V_181 == 0 )
V_181 = 1024 ;
V_183 = F_60 ( V_181 ) ;
if ( ! V_183 )
{
F_3 ( V_186 , V_61 ) ;
goto V_85;
}
for ( V_174 = 0 ; ; V_174 ++ )
{
V_182 = V_181 ;
V_183 [ 0 ] = 0 ;
if ( V_174 == 0 )
V_180 = V_189 ;
else
V_180 = 0 ;
if( ! F_104 ( V_141 , V_188 , V_183 , & V_182 , V_180 ) )
{
V_85 = F_97 () ;
if ( V_85 == V_176 )
goto V_191;
F_3 ( V_186 , V_190 ) ;
F_96 ( V_85 ) ;
goto V_85;
}
F_11 ( V_6 , L_29 , V_183 , V_182 , V_174 , V_180 ) ;
if ( ! V_183 [ 0 ] && ( V_182 == V_181 ) )
{
F_11 ( V_6 , L_30 ) ;
goto V_191;
}
F_102 ( V_7 , L_31 , V_174 , V_183 ) ;
}
V_85:
V_5 = 0 ;
V_191:
if ( V_183 )
F_9 ( V_183 ) ;
F_105 ( V_141 , 0 ) ;
return V_5 ;
}
T_24 * F_106 ( T_2 * V_6 , T_25 V_192 )
{
T_10 V_77 ;
T_24 * V_193 ;
if( ! F_107 ( V_192 , V_194 , NULL , & V_77 ) )
return NULL ;
V_193 = F_60 ( V_77 ) ;
if ( ! V_193 )
{
F_3 ( V_195 , V_61 ) ;
return NULL ;
}
if( ! F_107 ( V_192 , V_194 , V_193 , & V_77 ) )
{
F_3 ( V_195 , V_196 ) ;
F_59 () ;
F_9 ( V_193 ) ;
return NULL ;
}
return V_193 ;
}
static void F_108 ( T_2 * V_6 , T_3 * V_7 , T_24 * V_193 )
{
char * V_179 = NULL , * V_197 = NULL ;
if ( ! V_193 )
{
F_102 ( V_7 , L_32 ) ;
return;
}
V_179 = F_98 ( V_193 -> V_198 ) ;
V_197 = F_98 ( V_193 -> V_199 ) ;
if ( ! V_179 || ! V_197 )
goto V_85;
F_102 ( V_7 , L_33 ) ;
F_102 ( V_7 , L_34 , V_179 , V_193 -> V_200 ) ;
F_102 ( V_7 , L_35 , V_197 , V_193 -> V_201 ) ;
V_85:
if ( V_179 )
F_9 ( V_179 ) ;
if ( V_197 )
F_9 ( V_197 ) ;
}
char * F_109 ( T_2 * V_6 , T_25 V_192 )
{
T_21 V_202 ;
T_10 V_154 ;
F_11 ( V_6 , L_36 ) ;
if ( ! F_107 ( V_192 , V_203 , NULL , & V_154 ) )
return NULL ;
V_202 = F_60 ( V_154 ) ;
if ( F_107 ( V_192 , V_203 , V_202 , & V_154 ) )
{
char * V_204 = F_98 ( V_202 ) ;
F_9 ( V_202 ) ;
return V_204 ;
}
F_3 ( V_205 , V_206 ) ;
F_59 () ;
F_9 ( V_202 ) ;
return NULL ;
}
void F_110 ( T_2 * V_6 , T_3 * V_7 , T_25 V_192 )
{
T_26 * V_207 ;
unsigned char * V_4 ;
unsigned long V_180 = V_6 -> V_30 ;
if ( V_180 & V_208 )
{
char * V_204 ;
V_204 = F_109 ( V_6 , V_192 ) ;
if ( V_204 )
{
F_102 ( V_7 , L_37 , V_204 ) ;
F_9 ( V_204 ) ;
}
else
F_102 ( V_7 , L_38 ) ;
}
V_4 = V_192 -> V_209 ;
V_207 = F_111 ( NULL , & V_4 , V_192 -> V_210 ) ;
if ( ! V_207 )
F_102 ( V_7 , L_39 ) ;
if ( V_180 & V_211 )
{
F_102 ( V_7 , L_40 ) ;
F_112 ( V_7 , F_113 ( V_207 ) , 0 , V_212 ) ;
F_102 ( V_7 , L_41 ) ;
F_112 ( V_7 , F_114 ( V_207 ) , 0 , V_212 ) ;
F_102 ( V_7 , L_42 ) ;
}
if ( V_180 & V_213 )
F_115 ( V_7 , V_207 , V_212 , 0 ) ;
if ( V_180 & V_214 )
{
T_24 * V_193 ;
V_193 = F_106 ( V_6 , V_192 ) ;
F_108 ( V_6 , V_7 , V_193 ) ;
if ( V_193 )
F_9 ( V_193 ) ;
}
if ( V_180 & V_215 )
F_116 ( V_7 , V_207 ) ;
F_117 ( V_207 ) ;
}
T_27 F_118 ( T_2 * V_6 , char * V_17 )
{
T_27 V_216 ;
if ( ! V_17 )
V_17 = V_6 -> V_17 ;
if ( ! V_17 )
V_17 = L_43 ;
F_11 ( V_6 , L_44 , V_17 ) ;
V_216 = F_119 ( V_217 , 0 , 0 ,
V_6 -> V_19 , V_17 ) ;
if ( ! V_216 )
{
F_3 ( V_218 , V_219 ) ;
F_59 () ;
}
return V_216 ;
}
int F_7 ( T_2 * V_6 , T_3 * V_7 , char * V_68 )
{
char * V_17 ;
int V_174 ;
int V_5 = 1 ;
T_27 V_216 ;
T_25 V_192 = NULL ;
V_17 = V_6 -> V_17 ;
if ( ! V_17 )
V_17 = L_43 ;
F_11 ( V_6 , L_45 , V_17 ) ;
V_216 = F_118 ( V_6 , V_17 ) ;
if ( ! V_216 )
return 0 ;
if ( V_68 )
{
V_192 = F_120 ( V_6 , V_68 , V_216 ) ;
if ( ! V_192 )
{
V_5 = 0 ;
goto V_85;
}
F_110 ( V_6 , V_7 , V_192 ) ;
F_121 ( V_192 ) ;
}
else
{
for( V_174 = 0 ; ; V_174 ++ )
{
T_21 V_204 = NULL ;
V_192 = F_122 ( V_216 , V_192 ) ;
if ( ! V_192 )
break;
F_102 ( V_7 , L_46 , V_174 ) ;
F_110 ( V_6 , V_7 , V_192 ) ;
}
}
V_85:
F_123 ( V_216 , 0 ) ;
return V_5 ;
}
static T_25 F_120 ( T_2 * V_6 , const char * V_68 , T_27 V_216 )
{
T_25 V_192 = NULL ;
char * V_204 = NULL ;
int V_220 ;
switch( V_6 -> V_33 )
{
case V_221 :
return F_124 ( V_216 ,
V_222 , 0 ,
V_223 , V_68 , NULL ) ;
case V_224 :
for(; ; )
{
V_192 = F_122 ( V_216 , V_192 ) ;
if ( ! V_192 )
return NULL ;
V_204 = F_109 ( V_6 , V_192 ) ;
if ( V_204 )
{
if ( strcmp ( V_204 , V_68 ) )
V_220 = 0 ;
else
V_220 = 1 ;
F_9 ( V_204 ) ;
if ( V_220 )
return V_192 ;
}
}
default:
return NULL ;
}
}
static T_9 * F_125 ( T_2 * V_6 , const char * V_197 , char * V_179 , T_10 V_173 , T_10 V_145 )
{
T_9 * V_75 ;
V_75 = F_60 ( sizeof( T_9 ) ) ;
F_11 ( V_6 , L_47 ,
V_197 , V_179 , V_173 ) ;
if ( ! F_103 ( & V_75 -> V_141 , V_197 , V_179 , V_173 , 0 ) )
{
F_3 ( V_225 , V_187 ) ;
F_59 () ;
goto V_85;
}
if ( ! F_126 ( V_75 -> V_141 , V_145 , & V_75 -> V_75 ) )
{
F_3 ( V_225 , V_226 ) ;
F_59 () ;
F_105 ( V_75 -> V_141 , 0 ) ;
goto V_85;
}
V_75 -> V_145 = V_145 ;
V_75 -> V_227 = NULL ;
return V_75 ;
V_85:
F_9 ( V_75 ) ;
return NULL ;
}
static T_9 * F_127 ( T_2 * V_6 , T_25 V_192 )
{
T_9 * V_75 = NULL ;
T_24 * V_193 = NULL ;
char * V_179 = NULL , * V_197 = NULL ;
V_193 = F_106 ( V_6 , V_192 ) ;
if ( ! V_193 )
goto V_85;
V_179 = F_98 ( V_193 -> V_198 ) ;
V_197 = F_98 ( V_193 -> V_199 ) ;
if ( ! V_179 || ! V_197 )
goto V_85;
V_75 = F_125 ( V_6 , V_197 , V_179 ,
V_193 -> V_200 , V_193 -> V_201 ) ;
V_85:
if ( V_193 )
F_9 ( V_193 ) ;
if ( V_179 )
F_9 ( V_179 ) ;
if ( V_197 )
F_9 ( V_197 ) ;
return V_75 ;
}
T_9 * F_74 ( T_2 * V_6 , const char * V_68 )
{
T_25 V_192 ;
T_27 V_216 ;
T_9 * V_75 = NULL ;
switch ( V_6 -> V_33 )
{
case V_221 :
case V_224 :
V_216 = F_118 ( V_6 , NULL ) ;
if ( ! V_216 )
return NULL ;
V_192 = F_120 ( V_6 , V_68 , V_216 ) ;
if ( V_192 )
{
V_75 = F_127 ( V_6 , V_192 ) ;
F_121 ( V_192 ) ;
}
F_123 ( V_216 , 0 ) ;
break;
case V_228 :
V_75 = F_125 ( V_6 , V_68 , V_6 -> V_184 , V_6 -> V_35 ,
V_6 -> V_27 ) ;
break;
}
return V_75 ;
}
void F_75 ( T_9 * V_75 )
{
if ( ! V_75 )
return;
F_128 ( V_75 -> V_75 ) ;
F_105 ( V_75 -> V_141 , 0 ) ;
if ( V_75 -> V_227 )
F_121 ( V_75 -> V_227 ) ;
F_9 ( V_75 ) ;
}
static T_2 * F_22 ()
{
T_2 * V_6 ;
V_6 = F_60 ( sizeof( T_2 ) ) ;
if ( ! V_6 )
{
F_3 ( V_229 , V_61 ) ;
return NULL ;
}
V_6 -> V_184 = NULL ;
V_6 -> V_35 = V_230 ;
V_6 -> V_30 = V_211 | V_208 ;
V_6 -> V_27 = V_231 ;
V_6 -> V_17 = NULL ;
V_6 -> V_232 = NULL ;
V_6 -> V_19 = V_233 |
V_234 |
V_21 ;
V_6 -> V_33 = V_221 ;
V_6 -> V_23 = 0 ;
V_6 -> V_25 = NULL ;
V_6 -> V_58 = V_235 ;
return V_6 ;
}
static void F_33 ( T_2 * V_6 )
{
F_11 ( V_6 , L_48 , V_6 ) ;
if ( ! V_6 )
return;
if ( V_6 -> V_184 )
F_9 ( V_6 -> V_184 ) ;
if ( V_6 -> V_25 )
F_9 ( V_6 -> V_25 ) ;
if ( V_6 -> V_17 )
F_9 ( V_6 -> V_17 ) ;
if ( V_6 -> V_232 )
F_9 ( V_6 -> V_232 ) ;
F_9 ( V_6 ) ;
}
static int F_13 ( T_2 * V_6 , T_22 V_172 , T_10 type , int V_236 )
{
F_11 ( V_6 , L_49 , V_172 , type ) ;
if ( V_236 )
{
T_23 V_141 ;
if ( ! F_103 ( & V_141 , NULL , V_172 , type ,
V_185 ) )
{
F_3 ( V_237 , V_187 ) ;
F_59 () ;
return 0 ;
}
F_105 ( V_141 , 0 ) ;
}
if ( V_6 -> V_184 )
F_9 ( V_6 -> V_184 ) ;
V_6 -> V_184 = F_10 ( V_172 ) ;
V_6 -> V_35 = type ;
return 1 ;
}
static int F_12 ( T_2 * V_6 , int V_174 )
{
T_22 V_172 ;
T_10 type ;
int V_238 ;
if ( F_100 ( V_6 , & V_172 , & type , V_174 ) != 1 )
return 0 ;
V_238 = F_13 ( V_6 , V_172 , type , 0 ) ;
F_9 ( V_172 ) ;
return V_238 ;
}
T_28
int F_129 ( T_1 * V_1 , const char * V_68 , const T_29 * V_239 ) { return 0 ; }
void F_52 ( void ) {}
