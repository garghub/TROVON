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
V_8 = F_16 ( 0 , NULL , NULL , NULL , 0 ) ;
V_40 = F_17 ( 0 , NULL , NULL , NULL , 0 ) ;
V_6 = F_18 () ;
if ( ! V_6 || ( V_8 < 0 ) )
goto V_41;
F_19 ( V_1 , V_8 , V_6 ) ;
V_42 = F_20 ( 0 , NULL , NULL , NULL , 0 ) ;
V_38 = F_21 () ;
V_43 . V_44 = V_38 -> V_44 ;
V_43 . V_45 = V_38 -> V_45 ;
V_43 . V_46 = V_38 -> V_46 ;
V_43 . V_47 = V_38 -> V_47 ;
V_48 = F_22 ( 0 , NULL , NULL , NULL , 0 ) ;
V_39 = F_23 () ;
V_49 . V_50 = V_39 -> V_50 ;
V_49 . V_51 = V_39 -> V_51 ;
V_49 . V_47 = V_39 -> V_47 ;
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
V_41:
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
F_19 ( V_1 , V_8 , NULL ) ;
return 1 ;
}
static int F_34 ( T_1 * V_1 )
{
if ( ! F_35 ( V_1 , V_62 )
|| ! F_36 ( V_1 , V_63 )
|| ! F_37 ( V_1 , F_15 )
|| ! F_38 ( V_1 , F_32 )
|| ! F_39 ( V_1 , F_30 )
|| ! F_40 ( V_1 , & V_43 )
|| ! F_41 ( V_1 , & V_49 )
|| ! F_42 ( V_1 , V_64 )
|| ! F_43 ( V_1 ,
V_65 )
|| ! F_44 ( V_1 , V_66 )
|| ! F_45 ( V_1 , F_1 ) )
return 0 ;
F_46 () ;
return 1 ;
}
static int F_47 ( T_1 * V_1 , const char * V_67 )
{
if( V_67 && ( strcmp ( V_67 , V_62 ) != 0 ) )
return 0 ;
if( ! F_34 ( V_1 ) )
return 0 ;
return 1 ;
}
static T_1 * F_48 ( void )
{
T_1 * V_5 = F_49 () ;
if( ! V_5 )
return NULL ;
if( ! F_34 ( V_5 ) )
{
F_50 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
void F_51 ( void )
{
T_1 * V_68 = F_48 () ;
if( ! V_68 ) return;
F_52 ( V_68 ) ;
F_50 ( V_68 ) ;
F_53 () ;
}
static int F_54 ( T_7 * V_69 , unsigned char * V_70 , int V_71 )
{
int V_3 ;
for( V_3 = 0 ; V_3 < V_71 / 2 ; V_3 ++ )
{
unsigned char V_72 ;
V_72 = V_70 [ V_3 ] ;
V_70 [ V_3 ] = V_70 [ V_71 - V_3 - 1 ] ;
V_70 [ V_71 - V_3 - 1 ] = V_72 ;
}
if ( ! F_55 ( V_70 , V_71 , V_69 ) )
return 0 ;
return 1 ;
}
static T_8 * F_56 ( T_1 * V_73 , T_9 * V_74 )
{
unsigned char * V_75 = NULL ;
T_10 V_76 ;
T_11 * V_77 ;
T_12 * V_78 = NULL ;
T_13 * V_79 = NULL ;
T_8 * V_5 = NULL ;
if ( ! F_57 ( V_74 -> V_74 , 0 , V_80 , 0 , NULL , & V_76 ) )
{
F_3 ( V_81 , V_82 ) ;
F_58 () ;
return NULL ;
}
V_75 = F_59 ( V_76 ) ;
if ( ! V_75 )
goto V_41;
if ( ! F_57 ( V_74 -> V_74 , 0 , V_80 , 0 , V_75 , & V_76 ) )
{
F_3 ( V_81 , V_83 ) ;
F_58 () ;
goto V_84;
}
V_77 = ( T_11 * ) V_75 ;
if ( V_77 -> V_85 != V_80 )
{
F_3 ( V_81 , V_86 ) ;
goto V_84;
}
if ( V_77 -> V_87 == V_88 || V_77 -> V_87 == V_89 )
{
T_14 * V_90 ;
T_10 V_91 ;
unsigned char * V_92 ;
V_90 = ( T_14 * ) ( V_77 + 1 ) ;
if ( V_90 -> V_93 != 0x31415352 )
{
char V_94 [ 10 ] ;
F_60 ( V_94 , 10 , L_10 , V_90 -> V_93 ) ;
F_3 ( V_81 , V_95 ) ;
F_61 ( 2 , L_11 , V_94 ) ;
goto V_84;
}
V_92 = ( unsigned char * ) ( V_90 + 1 ) ;
V_78 = F_62 ( V_73 ) ;
if ( ! V_78 )
goto V_41;
V_78 -> V_1 = F_63 () ;
V_78 -> V_96 = F_63 () ;
if ( ! V_78 -> V_1 || ! V_78 -> V_96 )
goto V_41;
if ( ! F_64 ( V_78 -> V_1 , V_90 -> V_97 ) )
goto V_41;
V_91 = V_90 -> V_98 / 8 ;
if ( ! F_54 ( V_78 -> V_96 , V_92 , V_91 ) )
goto V_41;
F_65 ( V_78 , V_42 , V_74 ) ;
if ( ! ( V_5 = F_66 () ) )
goto V_41;
F_67 ( V_5 , V_78 ) ;
V_78 = NULL ;
}
else if ( V_77 -> V_87 == V_99 )
{
T_15 * V_100 ;
T_10 V_101 ;
unsigned char * V_102 ;
V_100 = ( T_15 * ) ( V_77 + 1 ) ;
if ( V_100 -> V_93 != 0x31535344 )
{
char V_94 [ 10 ] ;
F_60 ( V_94 , 10 , L_10 , V_100 -> V_93 ) ;
F_3 ( V_81 , V_103 ) ;
F_61 ( 2 , L_11 , V_94 ) ;
goto V_84;
}
V_101 = V_100 -> V_98 / 8 ;
V_102 = ( unsigned char * ) ( V_100 + 1 ) ;
V_79 = F_68 ( V_73 ) ;
if ( ! V_79 )
goto V_41;
V_79 -> V_4 = F_63 () ;
V_79 -> V_104 = F_63 () ;
V_79 -> V_105 = F_63 () ;
V_79 -> V_106 = F_63 () ;
if ( ! V_79 -> V_4 || ! V_79 -> V_104 || ! V_79 -> V_105 || ! V_79 -> V_106 )
goto V_41;
if ( ! F_54 ( V_79 -> V_4 , V_102 , V_101 ) )
goto V_41;
V_102 += V_101 ;
if ( ! F_54 ( V_79 -> V_104 , V_102 , 20 ) )
goto V_41;
V_102 += 20 ;
if ( ! F_54 ( V_79 -> V_105 , V_102 , V_101 ) )
goto V_41;
V_102 += V_101 ;
if ( ! F_54 ( V_79 -> V_106 , V_102 , V_101 ) )
goto V_41;
V_102 += V_101 ;
F_69 ( V_79 , V_48 , V_74 ) ;
if ( ! ( V_5 = F_66 () ) )
goto V_41;
F_70 ( V_5 , V_79 ) ;
V_79 = NULL ;
}
else
{
char V_107 [ 10 ] ;
F_60 ( V_107 , 10 , L_10 , V_77 -> V_87 ) ;
F_3 ( V_81 , V_108 ) ;
F_61 ( 2 , L_12 , V_107 ) ;
goto V_84;
}
V_84:
if ( V_75 )
F_9 ( V_75 ) ;
if ( ! V_5 )
{
if ( V_78 )
F_71 ( V_78 ) ;
if ( V_79 )
F_72 ( V_79 ) ;
}
return V_5 ;
V_41:
F_3 ( V_81 , V_61 ) ;
goto V_84;
}
static T_8 * V_64 ( T_1 * V_73 , const char * V_109 ,
T_16 * V_110 , void * V_111 )
{
T_2 * V_6 ;
T_9 * V_74 ;
T_8 * V_5 ;
V_6 = F_4 ( V_73 , V_8 ) ;
if ( ! V_6 )
{
F_3 ( V_112 , V_113 ) ;
return NULL ;
}
V_74 = F_73 ( V_6 , V_109 ) ;
if ( ! V_74 )
return NULL ;
V_5 = F_56 ( V_73 , V_74 ) ;
if ( ! V_5 )
F_74 ( V_74 ) ;
return V_5 ;
}
int F_75 ( int V_114 , const unsigned char * V_115 ,
unsigned char * V_116 , T_12 * V_117 , int V_118 )
{
F_3 ( V_119 , V_120 ) ;
return - 1 ;
}
int F_76 ( int V_121 , const unsigned char * V_122 , unsigned int V_123 ,
unsigned char * V_124 , unsigned int * V_125 , const T_12 * V_117 )
{
T_17 V_126 ;
T_18 V_127 ;
T_10 V_128 ;
unsigned int V_3 ;
int V_5 = - 1 ;
T_9 * V_129 ;
T_2 * V_6 ;
V_6 = F_4 ( V_117 -> V_130 , V_8 ) ;
F_11 ( V_6 , L_13 ) ;
V_129 = F_77 ( V_117 , V_42 ) ;
if ( ! V_129 )
{
F_3 ( V_131 , V_132 ) ;
return - 1 ;
}
switch( V_121 )
{
case V_133 :
V_126 = V_134 ;
break;
case V_135 :
V_126 = V_136 ;
break;
case V_137 :
V_126 = V_138 ;
break;
default:
{
char V_107 [ 10 ] ;
F_60 ( V_107 , 10 , L_10 , V_121 ) ;
F_3 ( V_131 , V_139 ) ;
F_61 ( 2 , L_14 , V_107 ) ;
return - 1 ;
}
}
if( ! F_78 ( V_129 -> V_140 , V_126 , 0 , 0 , & V_127 ) )
{
F_3 ( V_131 , V_141 ) ;
F_58 () ;
return - 1 ;
}
if( ! F_79 ( V_127 , V_142 , ( unsigned char * ) V_122 , 0 ) )
{
F_3 ( V_131 , V_143 ) ;
F_58 () ;
goto V_84;
}
V_128 = F_80 ( V_117 ) ;
if( ! F_81 ( V_127 , V_129 -> V_144 , NULL , 0 , V_124 , & V_128 ) )
{
F_3 ( V_131 , V_145 ) ;
F_58 () ;
goto V_84;
}
else
{
V_5 = 1 ;
for( V_3 = 0 ; V_3 < V_128 / 2 ; V_3 ++ )
{
unsigned char V_72 ;
V_72 = V_124 [ V_3 ] ;
V_124 [ V_3 ] = V_124 [ V_128 - V_3 - 1 ] ;
V_124 [ V_128 - V_3 - 1 ] = V_72 ;
}
* V_125 = V_128 ;
}
V_84:
F_82 ( V_127 ) ;
return V_5 ;
}
int F_83 ( int V_114 , const unsigned char * V_115 ,
unsigned char * V_116 , T_12 * V_117 , int V_118 )
{
int V_3 ;
unsigned char * V_146 ;
T_9 * V_129 ;
T_2 * V_6 ;
V_6 = F_4 ( V_117 -> V_130 , V_8 ) ;
F_11 ( V_6 , L_15 ) ;
V_129 = F_77 ( V_117 , V_42 ) ;
if ( ! V_129 )
{
F_3 ( V_147 , V_132 ) ;
return - 1 ;
}
if( V_118 != V_148 )
{
char V_149 [ 10 ] ;
F_60 ( V_149 , 10 , L_16 , V_118 ) ;
F_3 ( V_147 , V_150 ) ;
F_61 ( 2 , L_17 , V_149 ) ;
return - 1 ;
}
if( ! ( V_146 = F_59 ( V_114 ) ) )
{
F_3 ( V_147 , V_61 ) ;
return - 1 ;
}
for( V_3 = 0 ; V_3 < V_114 ; V_3 ++ )
V_146 [ V_114 - V_3 - 1 ] = V_115 [ V_3 ] ;
if( ! F_84 ( V_129 -> V_74 , 0 , TRUE , 0 , V_146 , & V_114 ) )
{
F_3 ( V_147 , V_151 ) ;
F_58 () ;
F_9 ( V_146 ) ;
return - 1 ;
}
else memcpy ( V_116 , V_146 , V_114 ) ;
F_9 ( V_146 ) ;
return V_114 ;
}
static int F_85 ( T_12 * V_117 )
{
T_9 * V_129 ;
V_129 = F_77 ( V_117 , V_42 ) ;
F_74 ( V_129 ) ;
F_65 ( V_117 , V_42 , 0 ) ;
return 1 ;
}
static T_19 * F_86 ( const unsigned char * V_152 , int V_153 ,
T_13 * V_154 )
{
T_18 V_127 ;
T_10 V_128 ;
T_19 * V_5 = NULL ;
T_9 * V_129 ;
T_2 * V_6 ;
unsigned char V_155 [ 40 ] ;
V_6 = F_4 ( V_154 -> V_130 , V_8 ) ;
F_11 ( V_6 , L_18 ) ;
V_129 = F_87 ( V_154 , V_48 ) ;
if ( ! V_129 )
{
F_3 ( V_156 , V_132 ) ;
return NULL ;
}
if ( V_153 != 20 )
{
F_3 ( V_156 , V_157 ) ;
return NULL ;
}
if( ! F_78 ( V_129 -> V_140 , V_134 , 0 , 0 , & V_127 ) )
{
F_3 ( V_156 , V_141 ) ;
F_58 () ;
return NULL ;
}
if( ! F_79 ( V_127 , V_142 , ( unsigned char * ) V_152 , 0 ) )
{
F_3 ( V_156 , V_143 ) ;
F_58 () ;
goto V_84;
}
V_128 = sizeof( V_155 ) ;
if( ! F_81 ( V_127 , V_129 -> V_144 , NULL , 0 , V_155 , & V_128 ) )
{
F_3 ( V_156 , V_145 ) ;
F_58 () ;
goto V_84;
}
else
{
V_5 = F_88 () ;
if ( ! V_5 )
goto V_84;
V_5 -> V_158 = F_63 () ;
V_5 -> V_159 = F_63 () ;
if ( ! V_5 -> V_158 || ! V_5 -> V_159 )
goto V_84;
if ( ! F_54 ( V_5 -> V_158 , V_155 , 20 )
|| ! F_54 ( V_5 -> V_159 , V_155 + 20 , 20 ) )
{
F_89 ( V_5 ) ;
V_5 = NULL ;
goto V_84;
}
}
V_84:
F_90 ( V_155 , 40 ) ;
F_82 ( V_127 ) ;
return V_5 ;
}
static int F_91 ( T_13 * V_154 )
{
T_9 * V_129 ;
V_129 = F_87 ( V_154 , V_48 ) ;
F_74 ( V_129 ) ;
F_69 ( V_154 , V_48 , 0 ) ;
return 1 ;
}
static void F_92 ( T_2 * V_6 , int V_160 , char * V_161 , T_20 V_162 )
{
T_3 * V_7 ;
if ( ! V_6 || ( V_6 -> V_23 < V_160 ) || ( ! V_6 -> V_25 ) )
return;
V_7 = F_93 ( V_6 -> V_25 , L_19 ) ;
F_94 ( V_7 , V_161 , V_162 ) ;
F_14 ( V_7 ) ;
}
static void F_11 ( T_2 * V_6 , char * V_161 , ... )
{
T_20 args ;
va_start ( args , V_161 ) ;
F_92 ( V_6 , V_163 , V_161 , args ) ;
va_end ( args ) ;
}
static void F_58 ( void )
{
F_95 ( F_96 () ) ;
}
static void F_95 ( T_10 V_84 )
{
char V_149 [ 10 ] ;
F_60 ( V_149 , 10 , L_20 , V_84 ) ;
F_61 ( 2 , L_21 , V_149 ) ;
}
static char * F_97 ( T_21 V_164 )
{
char * V_165 ;
int V_166 , V_167 ;
if ( ! V_164 )
return NULL ;
V_166 = ( int ) wcslen ( V_164 ) + 1 ;
V_167 = F_98 ( V_168 , 0 , V_164 , V_166 , NULL , 0 , NULL , NULL ) ;
if ( ! V_167 )
{
F_3 ( V_169 , V_170 ) ;
return NULL ;
}
V_165 = F_59 ( V_167 ) ;
if ( ! V_165 )
{
F_3 ( V_169 , V_61 ) ;
return NULL ;
}
if ( ! F_98 ( V_168 , 0 , V_164 , V_166 , V_165 , V_167 , NULL , NULL ) )
{
F_9 ( V_165 ) ;
F_3 ( V_169 , V_170 ) ;
return NULL ;
}
return V_165 ;
}
static int F_99 ( T_2 * V_6 , T_22 * V_171 , T_10 * V_172 , T_10 V_173 )
{
T_22 V_174 ;
T_10 V_76 , V_84 ;
F_11 ( V_6 , L_22 , V_173 ) ;
if ( ! F_100 ( V_173 , NULL , 0 , V_172 , NULL , & V_76 ) )
{
V_84 = F_96 () ;
if ( V_84 == V_175 )
return 2 ;
F_3 ( V_176 , V_177 ) ;
F_95 ( V_84 ) ;
return 0 ;
}
V_174 = F_59 ( V_76 ) ;
if ( ! F_100 ( V_173 , NULL , 0 , V_172 , V_174 , & V_76 ) )
{
V_84 = F_96 () ;
if ( V_84 == V_175 )
return 2 ;
F_3 ( V_176 , V_177 ) ;
F_95 ( V_84 ) ;
return 0 ;
}
* V_171 = V_174 ;
F_11 ( V_6 , L_23 , V_174 , * V_172 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_6 , T_3 * V_7 )
{
T_10 V_173 , V_172 ;
int V_5 ;
T_22 V_178 = NULL ;
F_11 ( V_6 , L_24 ) ;
F_101 ( V_7 , L_25 ) ;
for( V_173 = 0 ; ; V_173 ++ )
{
V_5 = F_99 ( V_6 , & V_178 , & V_172 , V_173 ) ;
if ( V_5 == 2 )
break;
if ( V_5 == 0 )
break;
F_101 ( V_7 , L_26 , V_173 , V_178 , V_172 ) ;
F_9 ( V_178 ) ;
}
return 1 ;
}
static int F_8 ( T_2 * V_6 , T_3 * V_7 )
{
int V_5 = 1 ;
T_23 V_140 ;
T_10 V_84 , V_173 , V_179 , V_180 = 0 , V_181 ;
T_22 V_182 ;
F_11 ( V_6 , L_27 , V_6 -> V_183 , V_6 -> V_35 ) ;
if ( ! F_102 ( & V_140 , NULL , V_6 -> V_183 , V_6 -> V_35 , V_184 ) )
{
F_3 ( V_185 , V_186 ) ;
F_58 () ;
return 0 ;
}
if ( ! F_103 ( V_140 , V_187 , NULL , & V_180 , V_188 ) )
{
F_3 ( V_185 , V_189 ) ;
F_58 () ;
return 0 ;
}
F_11 ( V_6 , L_28 , V_180 ) ;
if ( V_180 == 0 )
V_180 = 1024 ;
V_182 = F_59 ( V_180 ) ;
if ( ! V_182 )
{
F_3 ( V_185 , V_61 ) ;
goto V_84;
}
for ( V_173 = 0 ; ; V_173 ++ )
{
V_181 = V_180 ;
V_182 [ 0 ] = 0 ;
if ( V_173 == 0 )
V_179 = V_188 ;
else
V_179 = 0 ;
if( ! F_103 ( V_140 , V_187 , V_182 , & V_181 , V_179 ) )
{
V_84 = F_96 () ;
if ( V_84 == V_175 )
goto V_190;
F_3 ( V_185 , V_189 ) ;
F_95 ( V_84 ) ;
goto V_84;
}
F_11 ( V_6 , L_29 , V_182 , V_181 , V_173 , V_179 ) ;
if ( ! V_182 [ 0 ] && ( V_181 == V_180 ) )
{
F_11 ( V_6 , L_30 ) ;
goto V_190;
}
F_101 ( V_7 , L_31 , V_173 , V_182 ) ;
}
V_84:
V_5 = 0 ;
V_190:
if ( V_182 )
F_9 ( V_182 ) ;
F_104 ( V_140 , 0 ) ;
return V_5 ;
}
T_24 * F_105 ( T_2 * V_6 , T_25 V_191 )
{
T_10 V_76 ;
T_24 * V_192 ;
if( ! F_106 ( V_191 , V_193 , NULL , & V_76 ) )
return NULL ;
V_192 = F_59 ( V_76 ) ;
if ( ! V_192 )
{
F_3 ( V_194 , V_61 ) ;
return NULL ;
}
if( ! F_106 ( V_191 , V_193 , V_192 , & V_76 ) )
{
F_3 ( V_194 , V_195 ) ;
F_58 () ;
F_9 ( V_192 ) ;
return NULL ;
}
return V_192 ;
}
static void F_107 ( T_2 * V_6 , T_3 * V_7 , T_24 * V_192 )
{
char * V_178 = NULL , * V_196 = NULL ;
if ( ! V_192 )
{
F_101 ( V_7 , L_32 ) ;
return;
}
V_178 = F_97 ( V_192 -> V_197 ) ;
V_196 = F_97 ( V_192 -> V_198 ) ;
if ( ! V_178 || ! V_196 )
goto V_84;
F_101 ( V_7 , L_33 ) ;
F_101 ( V_7 , L_34 , V_178 , V_192 -> V_199 ) ;
F_101 ( V_7 , L_35 , V_196 , V_192 -> V_200 ) ;
V_84:
if ( V_178 )
F_9 ( V_178 ) ;
if ( V_196 )
F_9 ( V_196 ) ;
}
char * F_108 ( T_2 * V_6 , T_25 V_191 )
{
T_21 V_201 ;
T_10 V_153 ;
F_11 ( V_6 , L_36 ) ;
if ( ! F_106 ( V_191 , V_202 , NULL , & V_153 ) )
return NULL ;
V_201 = F_59 ( V_153 ) ;
if ( F_106 ( V_191 , V_202 , V_201 , & V_153 ) )
{
char * V_203 = F_97 ( V_201 ) ;
F_9 ( V_201 ) ;
return V_203 ;
}
F_3 ( V_204 , V_205 ) ;
F_58 () ;
F_9 ( V_201 ) ;
return NULL ;
}
void F_109 ( T_2 * V_6 , T_3 * V_7 , T_25 V_191 )
{
T_26 * V_206 ;
unsigned char * V_4 ;
unsigned long V_179 = V_6 -> V_30 ;
if ( V_179 & V_207 )
{
char * V_203 ;
V_203 = F_108 ( V_6 , V_191 ) ;
if ( V_203 )
{
F_101 ( V_7 , L_37 , V_203 ) ;
F_9 ( V_203 ) ;
}
else
F_101 ( V_7 , L_38 ) ;
}
V_4 = V_191 -> V_208 ;
V_206 = F_110 ( NULL , & V_4 , V_191 -> V_209 ) ;
if ( ! V_206 )
F_101 ( V_7 , L_39 ) ;
if ( V_179 & V_210 )
{
F_101 ( V_7 , L_40 ) ;
F_111 ( V_7 , F_112 ( V_206 ) , 0 , V_211 ) ;
F_101 ( V_7 , L_41 ) ;
F_111 ( V_7 , F_113 ( V_206 ) , 0 , V_211 ) ;
F_101 ( V_7 , L_42 ) ;
}
if ( V_179 & V_212 )
F_114 ( V_7 , V_206 , V_211 , 0 ) ;
if ( V_179 & V_213 )
{
T_24 * V_192 ;
V_192 = F_105 ( V_6 , V_191 ) ;
F_107 ( V_6 , V_7 , V_192 ) ;
if ( V_192 )
F_9 ( V_192 ) ;
}
if ( V_179 & V_214 )
F_115 ( V_7 , V_206 ) ;
F_116 ( V_206 ) ;
}
T_27 F_117 ( T_2 * V_6 , char * V_17 )
{
T_27 V_215 ;
if ( ! V_17 )
V_17 = V_6 -> V_17 ;
if ( ! V_17 )
V_17 = L_43 ;
F_11 ( V_6 , L_44 , V_17 ) ;
V_215 = F_118 ( V_216 , 0 , 0 ,
V_6 -> V_19 , V_17 ) ;
if ( ! V_215 )
{
F_3 ( V_217 , V_218 ) ;
F_58 () ;
}
return V_215 ;
}
int F_7 ( T_2 * V_6 , T_3 * V_7 , char * V_67 )
{
char * V_17 ;
int V_173 ;
int V_5 = 1 ;
T_27 V_215 ;
T_25 V_191 = NULL ;
V_17 = V_6 -> V_17 ;
if ( ! V_17 )
V_17 = L_43 ;
F_11 ( V_6 , L_45 , V_17 ) ;
V_215 = F_117 ( V_6 , V_17 ) ;
if ( ! V_215 )
return 0 ;
if ( V_67 )
{
V_191 = F_119 ( V_6 , V_67 , V_215 ) ;
if ( ! V_191 )
{
V_5 = 0 ;
goto V_84;
}
F_109 ( V_6 , V_7 , V_191 ) ;
F_120 ( V_191 ) ;
}
else
{
for( V_173 = 0 ; ; V_173 ++ )
{
T_21 V_203 = NULL ;
V_191 = F_121 ( V_215 , V_191 ) ;
if ( ! V_191 )
break;
F_101 ( V_7 , L_46 , V_173 ) ;
F_109 ( V_6 , V_7 , V_191 ) ;
}
}
V_84:
F_122 ( V_215 , 0 ) ;
return V_5 ;
}
static T_25 F_119 ( T_2 * V_6 , const char * V_67 , T_27 V_215 )
{
T_25 V_191 = NULL ;
char * V_203 = NULL ;
int V_219 ;
switch( V_6 -> V_33 )
{
case V_220 :
return F_123 ( V_215 ,
V_221 , 0 ,
V_222 , V_67 , NULL ) ;
case V_223 :
for(; ; )
{
V_191 = F_121 ( V_215 , V_191 ) ;
if ( ! V_191 )
return NULL ;
V_203 = F_108 ( V_6 , V_191 ) ;
if ( V_203 )
{
if ( strcmp ( V_203 , V_67 ) )
V_219 = 0 ;
else
V_219 = 1 ;
F_9 ( V_203 ) ;
if ( V_219 )
return V_191 ;
}
}
default:
return NULL ;
}
}
static T_9 * F_124 ( T_2 * V_6 , const char * V_196 , char * V_178 , T_10 V_172 , T_10 V_144 )
{
T_9 * V_74 ;
V_74 = F_59 ( sizeof( T_9 ) ) ;
F_11 ( V_6 , L_47 ,
V_196 , V_178 , V_172 ) ;
if ( ! F_102 ( & V_74 -> V_140 , V_196 , V_178 , V_172 , 0 ) )
{
F_3 ( V_224 , V_186 ) ;
F_58 () ;
goto V_84;
}
if ( ! F_125 ( V_74 -> V_140 , V_144 , & V_74 -> V_74 ) )
{
F_3 ( V_224 , V_225 ) ;
F_58 () ;
F_104 ( V_74 -> V_140 , 0 ) ;
goto V_84;
}
V_74 -> V_144 = V_144 ;
V_74 -> V_226 = NULL ;
return V_74 ;
V_84:
F_9 ( V_74 ) ;
return NULL ;
}
static T_9 * F_126 ( T_2 * V_6 , T_25 V_191 )
{
T_9 * V_74 = NULL ;
T_24 * V_192 = NULL ;
char * V_178 = NULL , * V_196 = NULL ;
V_192 = F_105 ( V_6 , V_191 ) ;
if ( ! V_192 )
goto V_84;
V_178 = F_97 ( V_192 -> V_197 ) ;
V_196 = F_97 ( V_192 -> V_198 ) ;
if ( ! V_178 || ! V_196 )
goto V_84;
V_74 = F_124 ( V_6 , V_196 , V_178 ,
V_192 -> V_199 , V_192 -> V_200 ) ;
V_84:
if ( V_192 )
F_9 ( V_192 ) ;
if ( V_178 )
F_9 ( V_178 ) ;
if ( V_196 )
F_9 ( V_196 ) ;
return V_74 ;
}
T_9 * F_73 ( T_2 * V_6 , const char * V_67 )
{
T_25 V_191 ;
T_27 V_215 ;
T_9 * V_74 = NULL ;
switch ( V_6 -> V_33 )
{
case V_220 :
case V_223 :
V_215 = F_117 ( V_6 , NULL ) ;
if ( ! V_215 )
return NULL ;
V_191 = F_119 ( V_6 , V_67 , V_215 ) ;
if ( V_191 )
{
V_74 = F_126 ( V_6 , V_191 ) ;
F_120 ( V_191 ) ;
}
F_122 ( V_215 , 0 ) ;
break;
case V_227 :
V_74 = F_124 ( V_6 , V_67 , V_6 -> V_183 , V_6 -> V_35 ,
V_6 -> V_27 ) ;
break;
}
return V_74 ;
}
void F_74 ( T_9 * V_74 )
{
if ( ! V_74 )
return;
F_127 ( V_74 -> V_74 ) ;
F_104 ( V_74 -> V_140 , 0 ) ;
if ( V_74 -> V_226 )
F_120 ( V_74 -> V_226 ) ;
F_9 ( V_74 ) ;
}
static T_2 * F_18 ()
{
T_2 * V_6 ;
V_6 = F_59 ( sizeof( T_2 ) ) ;
if ( ! V_6 )
{
F_3 ( V_228 , V_61 ) ;
return NULL ;
}
V_6 -> V_183 = NULL ;
V_6 -> V_35 = V_229 ;
V_6 -> V_30 = V_210 | V_207 ;
V_6 -> V_27 = V_230 ;
V_6 -> V_17 = NULL ;
V_6 -> V_231 = NULL ;
V_6 -> V_19 = V_232 |
V_233 |
V_21 ;
V_6 -> V_33 = V_220 ;
V_6 -> V_23 = 0 ;
V_6 -> V_25 = NULL ;
V_6 -> V_58 = V_234 ;
return V_6 ;
}
static void F_33 ( T_2 * V_6 )
{
F_11 ( V_6 , L_48 , V_6 ) ;
if ( ! V_6 )
return;
if ( V_6 -> V_183 )
F_9 ( V_6 -> V_183 ) ;
if ( V_6 -> V_25 )
F_9 ( V_6 -> V_25 ) ;
if ( V_6 -> V_17 )
F_9 ( V_6 -> V_17 ) ;
if ( V_6 -> V_231 )
F_9 ( V_6 -> V_231 ) ;
F_9 ( V_6 ) ;
}
static int F_13 ( T_2 * V_6 , T_22 V_171 , T_10 type , int V_235 )
{
F_11 ( V_6 , L_49 , V_171 , type ) ;
if ( V_235 )
{
T_23 V_140 ;
if ( ! F_102 ( & V_140 , NULL , V_171 , type ,
V_184 ) )
{
F_3 ( V_236 , V_186 ) ;
F_58 () ;
return 0 ;
}
F_104 ( V_140 , 0 ) ;
}
V_6 -> V_183 = F_10 ( V_171 ) ;
V_6 -> V_35 = type ;
return 1 ;
}
static int F_12 ( T_2 * V_6 , int V_173 )
{
T_22 V_171 ;
T_10 type ;
if ( F_99 ( V_6 , & V_171 , & type , V_173 ) != 1 )
return 0 ;
return F_13 ( V_6 , V_171 , type , 0 ) ;
}
T_28
int F_128 ( T_1 * V_1 , const char * V_67 , const T_29 * V_237 ) { return 0 ; }
void F_51 ( void ) {}
