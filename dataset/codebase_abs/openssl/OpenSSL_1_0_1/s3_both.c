int F_1 ( T_1 * V_1 , int type )
{
int V_2 ;
V_2 = F_2 ( V_1 , type , & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_1 -> V_6 ) ;
if ( V_2 < 0 ) return ( - 1 ) ;
if ( type == V_7 )
F_3 ( V_1 , ( unsigned char * ) & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] , V_2 ) ;
if ( V_2 == V_1 -> V_6 )
{
if ( V_1 -> V_8 )
V_1 -> V_8 ( 1 , V_1 -> V_9 , type , V_1 -> V_3 -> V_4 , ( V_10 ) ( V_1 -> V_5 + V_1 -> V_6 ) , V_1 , V_1 -> V_11 ) ;
return ( 1 ) ;
}
V_1 -> V_5 += V_2 ;
V_1 -> V_6 -= V_2 ;
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , int V_15 )
{
unsigned char * V_16 , * V_17 ;
int V_18 ;
unsigned long V_19 ;
if ( V_1 -> V_20 == V_12 )
{
V_17 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
V_16 = & ( V_17 [ 4 ] ) ;
V_18 = V_1 -> V_21 -> V_22 -> V_23 ( V_1 ,
V_14 , V_15 , V_1 -> V_24 -> V_25 . V_26 ) ;
V_1 -> V_24 -> V_25 . V_27 = V_18 ;
memcpy ( V_16 , V_1 -> V_24 -> V_25 . V_26 , V_18 ) ;
V_16 += V_18 ;
V_19 = V_18 ;
if( V_1 -> type == V_28 )
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_30 ,
V_1 -> V_24 -> V_25 . V_26 , V_18 ) ;
V_1 -> V_24 -> V_31 = V_18 ;
}
else
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_32 ,
V_1 -> V_24 -> V_25 . V_26 , V_18 ) ;
V_1 -> V_24 -> V_33 = V_18 ;
}
#ifdef F_6
V_19 &= 0xffff ;
#endif
* ( V_17 ++ ) = V_34 ;
F_7 ( V_19 , V_17 ) ;
V_1 -> V_6 = ( int ) V_19 + 4 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_7 ) ) ;
}
static void F_8 ( T_1 * V_1 ) {
const char * V_14 ;
int V_15 ;
if ( V_1 -> V_20 & V_28 )
{
V_14 = V_1 -> V_21 -> V_22 -> V_35 ;
V_15 = V_1 -> V_21 -> V_22 -> V_36 ;
}
else
{
V_14 = V_1 -> V_21 -> V_22 -> V_37 ;
V_15 = V_1 -> V_21 -> V_22 -> V_38 ;
}
V_1 -> V_24 -> V_25 . V_39 = V_1 -> V_21 -> V_22 -> V_23 ( V_1 ,
V_14 , V_15 , V_1 -> V_24 -> V_25 . V_40 ) ;
}
int F_9 ( T_1 * V_1 , int V_12 , int V_13 )
{
int V_41 , V_18 , V_42 ;
long V_43 ;
unsigned char * V_16 ;
#ifdef F_10
#endif
V_43 = V_1 -> V_21 -> V_44 ( V_1 ,
V_12 ,
V_13 ,
V_34 ,
64 ,
& V_42 ) ;
if ( ! V_42 ) return ( ( int ) V_43 ) ;
if ( ! V_1 -> V_24 -> V_45 )
{
V_41 = V_46 ;
F_11 ( V_47 , V_48 ) ;
goto V_49;
}
V_1 -> V_24 -> V_45 = 0 ;
V_16 = ( unsigned char * ) V_1 -> V_50 ;
V_18 = V_1 -> V_24 -> V_25 . V_39 ;
if ( V_18 != V_43 )
{
V_41 = V_51 ;
F_11 ( V_47 , V_52 ) ;
goto V_49;
}
if ( memcmp ( V_16 , V_1 -> V_24 -> V_25 . V_40 , V_18 ) != 0 )
{
V_41 = V_53 ;
F_11 ( V_47 , V_54 ) ;
goto V_49;
}
if( V_1 -> type == V_55 )
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_30 ,
V_1 -> V_24 -> V_25 . V_40 , V_18 ) ;
V_1 -> V_24 -> V_31 = V_18 ;
}
else
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_32 ,
V_1 -> V_24 -> V_25 . V_40 , V_18 ) ;
V_1 -> V_24 -> V_33 = V_18 ;
}
return ( 1 ) ;
V_49:
F_12 ( V_1 , V_56 , V_41 ) ;
return ( 0 ) ;
}
int F_13 ( T_1 * V_1 , int V_12 , int V_13 )
{
unsigned char * V_16 ;
if ( V_1 -> V_20 == V_12 )
{
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_16 = V_57 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_58 ) ) ;
}
static int F_14 ( T_2 * V_59 , unsigned long * V_19 , T_3 * V_60 )
{
int V_43 ;
unsigned char * V_16 ;
V_43 = F_15 ( V_60 , NULL ) ;
if ( ! F_16 ( V_59 , ( int ) ( V_43 + ( * V_19 ) + 3 ) ) )
{
F_11 ( V_61 , V_62 ) ;
return ( - 1 ) ;
}
V_16 = ( unsigned char * ) & ( V_59 -> V_4 [ * V_19 ] ) ;
F_7 ( V_43 , V_16 ) ;
F_15 ( V_60 , & V_16 ) ;
* V_19 += V_43 + 3 ;
return ( 0 ) ;
}
unsigned long F_17 ( T_1 * V_1 , T_3 * V_60 )
{
unsigned char * V_16 ;
int V_18 ;
unsigned long V_19 = 7 ;
T_2 * V_59 ;
int V_63 ;
if ( ( V_1 -> V_64 & V_65 ) || V_1 -> V_66 -> V_67 )
V_63 = 1 ;
else
V_63 = 0 ;
V_59 = V_1 -> V_3 ;
if ( ! F_16 ( V_59 , 10 ) )
{
F_11 ( V_68 , V_62 ) ;
return ( 0 ) ;
}
if ( V_60 != NULL )
{
if ( V_63 )
{
if ( F_14 ( V_59 , & V_19 , V_60 ) )
return ( 0 ) ;
}
else
{
T_4 V_69 ;
if ( ! F_18 ( & V_69 , V_1 -> V_66 -> V_70 , V_60 , NULL ) )
{
F_11 ( V_68 , V_71 ) ;
return ( 0 ) ;
}
F_19 ( & V_69 ) ;
F_20 () ;
for ( V_18 = 0 ; V_18 < F_21 ( V_69 . V_72 ) ; V_18 ++ )
{
V_60 = F_22 ( V_69 . V_72 , V_18 ) ;
if ( F_14 ( V_59 , & V_19 , V_60 ) )
{
F_23 ( & V_69 ) ;
return 0 ;
}
}
F_23 ( & V_69 ) ;
}
}
for ( V_18 = 0 ; V_18 < F_21 ( V_1 -> V_66 -> V_67 ) ; V_18 ++ )
{
V_60 = F_22 ( V_1 -> V_66 -> V_67 , V_18 ) ;
if ( F_14 ( V_59 , & V_19 , V_60 ) )
return ( 0 ) ;
}
V_19 -= 7 ;
V_16 = ( unsigned char * ) & ( V_59 -> V_4 [ 4 ] ) ;
F_7 ( V_19 , V_16 ) ;
V_19 += 3 ;
V_16 = ( unsigned char * ) & ( V_59 -> V_4 [ 0 ] ) ;
* ( V_16 ++ ) = V_73 ;
F_7 ( V_19 , V_16 ) ;
V_19 += 4 ;
return ( V_19 ) ;
}
long F_24 ( T_1 * V_1 , int V_74 , int V_75 , int V_76 , long V_77 , int * V_42 )
{
unsigned char * V_16 ;
unsigned long V_19 ;
long V_43 ;
int V_18 , V_41 ;
if ( V_1 -> V_24 -> V_25 . V_78 )
{
V_1 -> V_24 -> V_25 . V_78 = 0 ;
if ( ( V_76 >= 0 ) && ( V_1 -> V_24 -> V_25 . V_79 != V_76 ) )
{
V_41 = V_46 ;
F_11 ( V_80 , V_81 ) ;
goto V_49;
}
* V_42 = 1 ;
V_1 -> V_50 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = ( int ) V_1 -> V_24 -> V_25 . V_82 ;
return V_1 -> V_6 ;
}
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_20 == V_74 )
{
int V_83 ;
do
{
while ( V_1 -> V_6 < 4 )
{
V_18 = V_1 -> V_21 -> V_84 ( V_1 , V_7 ,
& V_16 [ V_1 -> V_6 ] , 4 - V_1 -> V_6 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_85 = V_86 ;
* V_42 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
}
V_83 = 0 ;
if ( ! V_1 -> V_87 )
if ( V_16 [ 0 ] == V_88 )
if ( V_16 [ 1 ] == 0 && V_16 [ 2 ] == 0 && V_16 [ 3 ] == 0 )
{
V_1 -> V_6 = 0 ;
V_83 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_16 , 4 , V_1 , V_1 -> V_11 ) ;
}
}
while ( V_83 );
if ( ( V_76 >= 0 ) && ( * V_16 != V_76 ) )
{
V_41 = V_46 ;
F_11 ( V_80 , V_81 ) ;
goto V_49;
}
if ( ( V_76 < 0 ) && ( * V_16 == V_89 ) &&
( V_74 == V_90 ) &&
( V_75 == V_91 ) )
{
F_25 ( V_1 ) ;
}
V_1 -> V_24 -> V_25 . V_79 = * ( V_16 ++ ) ;
F_26 ( V_16 , V_19 ) ;
if ( V_19 > ( unsigned long ) V_77 )
{
V_41 = V_92 ;
F_11 ( V_80 , V_93 ) ;
goto V_49;
}
if ( V_19 > ( V_94 - 4 ) )
{
V_41 = V_92 ;
F_11 ( V_80 , V_93 ) ;
goto V_49;
}
if ( V_19 && ! F_16 ( V_1 -> V_3 , ( int ) V_19 + 4 ) )
{
F_11 ( V_80 , V_62 ) ;
goto V_95;
}
V_1 -> V_24 -> V_25 . V_82 = V_19 ;
V_1 -> V_20 = V_75 ;
V_1 -> V_50 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = 0 ;
}
V_16 = V_1 -> V_50 ;
V_43 = V_1 -> V_24 -> V_25 . V_82 - V_1 -> V_6 ;
while ( V_43 > 0 )
{
V_18 = V_1 -> V_21 -> V_84 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] , V_43 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_85 = V_86 ;
* V_42 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
V_43 -= V_18 ;
}
#ifndef F_10
if ( * V_1 -> V_3 -> V_4 == V_34 )
F_8 ( V_1 ) ;
#endif
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , V_1 -> V_6 + 4 ) ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_1 -> V_3 -> V_4 , ( V_10 ) V_1 -> V_6 + 4 , V_1 , V_1 -> V_11 ) ;
* V_42 = 1 ;
return V_1 -> V_6 ;
V_49:
F_12 ( V_1 , V_56 , V_41 ) ;
V_95:
* V_42 = 0 ;
return ( - 1 ) ;
}
int F_27 ( T_3 * V_60 , T_5 * V_96 )
{
T_5 * V_97 ;
int V_2 = - 1 , V_18 ;
if ( V_96 == NULL )
V_97 = F_28 ( V_60 ) ;
else
V_97 = V_96 ;
if ( V_97 == NULL ) goto V_95;
V_18 = V_97 -> type ;
if ( V_18 == V_98 )
{
V_2 = V_99 ;
}
else if ( V_18 == V_100 )
{
V_2 = V_101 ;
}
#ifndef F_29
else if ( V_18 == V_102 )
{
V_2 = V_103 ;
}
#endif
else if ( V_18 == V_104 || V_18 == V_105 )
{
V_2 = V_106 ;
}
else if ( V_18 == V_107 || V_18 == V_108 )
{
V_2 = V_109 ;
}
V_95:
if( ! V_96 ) F_30 ( V_97 ) ;
return ( V_2 ) ;
}
int F_31 ( long type )
{
int V_41 ;
switch( type )
{
case V_110 :
case V_111 :
case V_112 :
V_41 = V_113 ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_41 = V_125 ;
break;
case V_126 :
case V_127 :
V_41 = V_53 ;
break;
case V_128 :
case V_129 :
V_41 = V_130 ;
break;
case V_131 :
V_41 = V_132 ;
break;
case V_133 :
V_41 = V_134 ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_41 = V_113 ;
break;
case V_142 :
V_41 = V_143 ;
break;
case V_144 :
V_41 = V_145 ;
break;
default:
V_41 = V_146 ;
break;
}
return ( V_41 ) ;
}
static void *
F_32 ( T_6 * V_66 , int V_147 , int V_148 )
{
T_7 * V_149 ;
T_8 * V_150 = NULL ;
void * V_151 = NULL ;
F_33 ( V_152 ) ;
V_149 = V_147 ? V_66 -> V_153 : V_66 -> V_154 ;
if ( V_149 != NULL && V_148 == ( int ) V_149 -> V_155 )
V_150 = V_149 -> V_156 ;
if ( V_150 != NULL )
{
V_149 -> V_156 = V_150 -> V_157 ;
V_151 = V_150 ;
if ( -- V_149 -> V_158 == 0 )
V_149 -> V_155 = 0 ;
}
F_34 ( V_152 ) ;
if ( ! V_151 )
V_151 = F_35 ( V_148 ) ;
return V_151 ;
}
static void
F_36 ( T_6 * V_66 , int V_147 , V_10 V_148 , void * V_159 )
{
T_7 * V_149 ;
T_8 * V_150 ;
F_33 ( V_152 ) ;
V_149 = V_147 ? V_66 -> V_153 : V_66 -> V_154 ;
if ( V_149 != NULL &&
( V_148 == V_149 -> V_155 || V_149 -> V_155 == 0 ) &&
V_149 -> V_158 < V_66 -> V_160 &&
V_148 >= sizeof( * V_150 ) )
{
V_149 -> V_155 = V_148 ;
V_150 = V_159 ;
V_150 -> V_157 = V_149 -> V_156 ;
V_149 -> V_156 = V_150 ;
++ V_149 -> V_158 ;
V_159 = NULL ;
}
F_34 ( V_152 ) ;
if ( V_159 )
F_37 ( V_159 ) ;
}
int F_38 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_158 , V_161 = 0 , V_162 ;
if ( F_39 ( V_1 ) == V_163 || F_39 ( V_1 ) == V_164 )
V_162 = V_165 ;
else
V_162 = V_166 ;
#if F_40 ( V_167 ) && V_167 != 0
V_161 = ( - V_166 ) & ( V_167 - 1 ) ;
#endif
if ( V_1 -> V_24 -> V_168 . V_59 == NULL )
{
V_158 = V_169
+ V_170
+ V_162 + V_161 ;
if ( V_1 -> V_171 & V_172 )
{
V_1 -> V_24 -> V_173 = 1 ;
V_158 += V_174 ;
}
#ifndef F_41
if ( ! ( V_1 -> V_171 & V_175 ) )
V_158 += V_176 ;
#endif
if ( ( V_16 = F_32 ( V_1 -> V_66 , 1 , V_158 ) ) == NULL )
goto V_95;
V_1 -> V_24 -> V_168 . V_59 = V_16 ;
V_1 -> V_24 -> V_168 . V_158 = V_158 ;
}
V_1 -> V_177 = & ( V_1 -> V_24 -> V_168 . V_59 [ 0 ] ) ;
return 1 ;
V_95:
F_11 ( V_178 , V_179 ) ;
return 0 ;
}
int F_42 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_158 , V_161 = 0 , V_162 ;
if ( F_39 ( V_1 ) == V_163 || F_39 ( V_1 ) == V_164 )
V_162 = V_165 + 1 ;
else
V_162 = V_166 ;
#if F_40 ( V_167 ) && V_167 != 0
V_161 = ( - V_166 ) & ( V_167 - 1 ) ;
#endif
if ( V_1 -> V_24 -> V_180 . V_59 == NULL )
{
V_158 = V_1 -> V_181
+ V_182
+ V_162 + V_161 ;
#ifndef F_41
if ( ! ( V_1 -> V_171 & V_175 ) )
V_158 += V_176 ;
#endif
if ( ! ( V_1 -> V_171 & V_183 ) )
V_158 += V_162 + V_161
+ V_182 ;
if ( ( V_16 = F_32 ( V_1 -> V_66 , 0 , V_158 ) ) == NULL )
goto V_95;
V_1 -> V_24 -> V_180 . V_59 = V_16 ;
V_1 -> V_24 -> V_180 . V_158 = V_158 ;
}
return 1 ;
V_95:
F_11 ( V_184 , V_179 ) ;
return 0 ;
}
int F_43 ( T_1 * V_1 )
{
if ( ! F_38 ( V_1 ) )
return 0 ;
if ( ! F_42 ( V_1 ) )
return 0 ;
return 1 ;
}
int F_44 ( T_1 * V_1 )
{
if ( V_1 -> V_24 -> V_180 . V_59 != NULL )
{
F_36 ( V_1 -> V_66 , 0 , V_1 -> V_24 -> V_180 . V_158 , V_1 -> V_24 -> V_180 . V_59 ) ;
V_1 -> V_24 -> V_180 . V_59 = NULL ;
}
return 1 ;
}
int F_45 ( T_1 * V_1 )
{
if ( V_1 -> V_24 -> V_168 . V_59 != NULL )
{
F_36 ( V_1 -> V_66 , 1 , V_1 -> V_24 -> V_168 . V_158 , V_1 -> V_24 -> V_168 . V_59 ) ;
V_1 -> V_24 -> V_168 . V_59 = NULL ;
}
return 1 ;
}
