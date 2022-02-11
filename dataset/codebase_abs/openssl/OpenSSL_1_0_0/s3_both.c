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
int F_8 ( T_1 * V_1 , int V_12 , int V_13 )
{
int V_35 , V_18 , V_36 ;
long V_37 ;
unsigned char * V_16 ;
V_37 = V_1 -> V_21 -> V_38 ( V_1 ,
V_12 ,
V_13 ,
V_34 ,
64 ,
& V_36 ) ;
if ( ! V_36 ) return ( ( int ) V_37 ) ;
if ( ! V_1 -> V_24 -> V_39 )
{
V_35 = V_40 ;
F_9 ( V_41 , V_42 ) ;
goto V_43;
}
V_1 -> V_24 -> V_39 = 0 ;
V_16 = ( unsigned char * ) V_1 -> V_44 ;
V_18 = V_1 -> V_24 -> V_25 . V_45 ;
if ( V_18 != V_37 )
{
V_35 = V_46 ;
F_9 ( V_41 , V_47 ) ;
goto V_43;
}
if ( memcmp ( V_16 , V_1 -> V_24 -> V_25 . V_48 , V_18 ) != 0 )
{
V_35 = V_49 ;
F_9 ( V_41 , V_50 ) ;
goto V_43;
}
if( V_1 -> type == V_51 )
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_30 ,
V_1 -> V_24 -> V_25 . V_48 , V_18 ) ;
V_1 -> V_24 -> V_31 = V_18 ;
}
else
{
F_5 ( V_18 <= V_29 ) ;
memcpy ( V_1 -> V_24 -> V_32 ,
V_1 -> V_24 -> V_25 . V_48 , V_18 ) ;
V_1 -> V_24 -> V_33 = V_18 ;
}
return ( 1 ) ;
V_43:
F_10 ( V_1 , V_52 , V_35 ) ;
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 , int V_12 , int V_13 )
{
unsigned char * V_16 ;
if ( V_1 -> V_20 == V_12 )
{
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_16 = V_53 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_54 ) ) ;
}
static int F_12 ( T_2 * V_55 , unsigned long * V_19 , T_3 * V_56 )
{
int V_37 ;
unsigned char * V_16 ;
V_37 = F_13 ( V_56 , NULL ) ;
if ( ! F_14 ( V_55 , ( int ) ( V_37 + ( * V_19 ) + 3 ) ) )
{
F_9 ( V_57 , V_58 ) ;
return ( - 1 ) ;
}
V_16 = ( unsigned char * ) & ( V_55 -> V_4 [ * V_19 ] ) ;
F_7 ( V_37 , V_16 ) ;
F_13 ( V_56 , & V_16 ) ;
* V_19 += V_37 + 3 ;
return ( 0 ) ;
}
unsigned long F_15 ( T_1 * V_1 , T_3 * V_56 )
{
unsigned char * V_16 ;
int V_18 ;
unsigned long V_19 = 7 ;
T_2 * V_55 ;
int V_59 ;
if ( ( V_1 -> V_60 & V_61 ) || V_1 -> V_62 -> V_63 )
V_59 = 1 ;
else
V_59 = 0 ;
V_55 = V_1 -> V_3 ;
if ( ! F_14 ( V_55 , 10 ) )
{
F_9 ( V_64 , V_58 ) ;
return ( 0 ) ;
}
if ( V_56 != NULL )
{
if ( V_59 )
{
if ( F_12 ( V_55 , & V_19 , V_56 ) )
return ( 0 ) ;
}
else
{
T_4 V_65 ;
if ( ! F_16 ( & V_65 , V_1 -> V_62 -> V_66 , V_56 , NULL ) )
{
F_9 ( V_64 , V_67 ) ;
return ( 0 ) ;
}
F_17 ( & V_65 ) ;
F_18 () ;
for ( V_18 = 0 ; V_18 < F_19 ( V_65 . V_68 ) ; V_18 ++ )
{
V_56 = F_20 ( V_65 . V_68 , V_18 ) ;
if ( F_12 ( V_55 , & V_19 , V_56 ) )
{
F_21 ( & V_65 ) ;
return 0 ;
}
}
F_21 ( & V_65 ) ;
}
}
for ( V_18 = 0 ; V_18 < F_19 ( V_1 -> V_62 -> V_63 ) ; V_18 ++ )
{
V_56 = F_20 ( V_1 -> V_62 -> V_63 , V_18 ) ;
if ( F_12 ( V_55 , & V_19 , V_56 ) )
return ( 0 ) ;
}
V_19 -= 7 ;
V_16 = ( unsigned char * ) & ( V_55 -> V_4 [ 4 ] ) ;
F_7 ( V_19 , V_16 ) ;
V_19 += 3 ;
V_16 = ( unsigned char * ) & ( V_55 -> V_4 [ 0 ] ) ;
* ( V_16 ++ ) = V_69 ;
F_7 ( V_19 , V_16 ) ;
V_19 += 4 ;
return ( V_19 ) ;
}
long F_22 ( T_1 * V_1 , int V_70 , int V_71 , int V_72 , long V_73 , int * V_36 )
{
unsigned char * V_16 ;
unsigned long V_19 ;
long V_37 ;
int V_18 , V_35 ;
if ( V_1 -> V_24 -> V_25 . V_74 )
{
V_1 -> V_24 -> V_25 . V_74 = 0 ;
if ( ( V_72 >= 0 ) && ( V_1 -> V_24 -> V_25 . V_75 != V_72 ) )
{
V_35 = V_40 ;
F_9 ( V_76 , V_77 ) ;
goto V_43;
}
* V_36 = 1 ;
V_1 -> V_44 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = ( int ) V_1 -> V_24 -> V_25 . V_78 ;
return V_1 -> V_6 ;
}
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_20 == V_70 )
{
int V_79 ;
do
{
while ( V_1 -> V_6 < 4 )
{
V_18 = V_1 -> V_21 -> V_80 ( V_1 , V_7 ,
& V_16 [ V_1 -> V_6 ] , 4 - V_1 -> V_6 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_81 = V_82 ;
* V_36 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
}
V_79 = 0 ;
if ( ! V_1 -> V_83 )
if ( V_16 [ 0 ] == V_84 )
if ( V_16 [ 1 ] == 0 && V_16 [ 2 ] == 0 && V_16 [ 3 ] == 0 )
{
V_1 -> V_6 = 0 ;
V_79 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_16 , 4 , V_1 , V_1 -> V_11 ) ;
}
}
while ( V_79 );
if ( ( V_72 >= 0 ) && ( * V_16 != V_72 ) )
{
V_35 = V_40 ;
F_9 ( V_76 , V_77 ) ;
goto V_43;
}
if ( ( V_72 < 0 ) && ( * V_16 == V_85 ) &&
( V_70 == V_86 ) &&
( V_71 == V_87 ) )
{
F_23 ( V_1 ) ;
}
V_1 -> V_24 -> V_25 . V_75 = * ( V_16 ++ ) ;
F_24 ( V_16 , V_19 ) ;
if ( V_19 > ( unsigned long ) V_73 )
{
V_35 = V_88 ;
F_9 ( V_76 , V_89 ) ;
goto V_43;
}
if ( V_19 > ( V_90 - 4 ) )
{
V_35 = V_88 ;
F_9 ( V_76 , V_89 ) ;
goto V_43;
}
if ( V_19 && ! F_14 ( V_1 -> V_3 , ( int ) V_19 + 4 ) )
{
F_9 ( V_76 , V_58 ) ;
goto V_91;
}
V_1 -> V_24 -> V_25 . V_78 = V_19 ;
V_1 -> V_20 = V_71 ;
V_1 -> V_44 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = 0 ;
}
V_16 = V_1 -> V_44 ;
V_37 = V_1 -> V_24 -> V_25 . V_78 - V_1 -> V_6 ;
while ( V_37 > 0 )
{
V_18 = V_1 -> V_21 -> V_80 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] , V_37 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_81 = V_82 ;
* V_36 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
V_37 -= V_18 ;
}
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , V_1 -> V_6 + 4 ) ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_1 -> V_3 -> V_4 , ( V_10 ) V_1 -> V_6 + 4 , V_1 , V_1 -> V_11 ) ;
* V_36 = 1 ;
return V_1 -> V_6 ;
V_43:
F_10 ( V_1 , V_52 , V_35 ) ;
V_91:
* V_36 = 0 ;
return ( - 1 ) ;
}
int F_25 ( T_3 * V_56 , T_5 * V_92 )
{
T_5 * V_93 ;
int V_2 = - 1 , V_18 ;
if ( V_92 == NULL )
V_93 = F_26 ( V_56 ) ;
else
V_93 = V_92 ;
if ( V_93 == NULL ) goto V_91;
V_18 = V_93 -> type ;
if ( V_18 == V_94 )
{
V_2 = V_95 ;
}
else if ( V_18 == V_96 )
{
V_2 = V_97 ;
}
#ifndef F_27
else if ( V_18 == V_98 )
{
V_2 = V_99 ;
}
#endif
else if ( V_18 == V_100 || V_18 == V_101 )
{
V_2 = V_102 ;
}
else if ( V_18 == V_103 || V_18 == V_104 )
{
V_2 = V_105 ;
}
V_91:
if( ! V_92 ) F_28 ( V_93 ) ;
return ( V_2 ) ;
}
int F_29 ( long type )
{
int V_35 ;
switch( type )
{
case V_106 :
case V_107 :
case V_108 :
V_35 = V_109 ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_35 = V_121 ;
break;
case V_122 :
case V_123 :
V_35 = V_49 ;
break;
case V_124 :
case V_125 :
V_35 = V_126 ;
break;
case V_127 :
V_35 = V_128 ;
break;
case V_129 :
V_35 = V_130 ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_35 = V_109 ;
break;
case V_138 :
V_35 = V_139 ;
break;
case V_140 :
V_35 = V_141 ;
break;
default:
V_35 = V_142 ;
break;
}
return ( V_35 ) ;
}
static void *
F_30 ( T_6 * V_62 , int V_143 , int V_144 )
{
T_7 * V_145 ;
T_8 * V_146 = NULL ;
void * V_147 = NULL ;
F_31 ( V_148 ) ;
V_145 = V_143 ? V_62 -> V_149 : V_62 -> V_150 ;
if ( V_145 != NULL && V_144 == ( int ) V_145 -> V_151 )
V_146 = V_145 -> V_152 ;
if ( V_146 != NULL )
{
V_145 -> V_152 = V_146 -> V_153 ;
V_147 = V_146 ;
if ( -- V_145 -> V_154 == 0 )
V_145 -> V_151 = 0 ;
}
F_32 ( V_148 ) ;
if ( ! V_147 )
V_147 = F_33 ( V_144 ) ;
return V_147 ;
}
static void
F_34 ( T_6 * V_62 , int V_143 , V_10 V_144 , void * V_155 )
{
T_7 * V_145 ;
T_8 * V_146 ;
F_31 ( V_148 ) ;
V_145 = V_143 ? V_62 -> V_149 : V_62 -> V_150 ;
if ( V_145 != NULL &&
( V_144 == V_145 -> V_151 || V_145 -> V_151 == 0 ) &&
V_145 -> V_154 < V_62 -> V_156 &&
V_144 >= sizeof( * V_146 ) )
{
V_145 -> V_151 = V_144 ;
V_146 = V_155 ;
V_146 -> V_153 = V_145 -> V_152 ;
V_145 -> V_152 = V_146 ;
++ V_145 -> V_154 ;
V_155 = NULL ;
}
F_32 ( V_148 ) ;
if ( V_155 )
F_35 ( V_155 ) ;
}
int F_36 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_154 , V_157 = 0 , V_158 ;
if ( F_37 ( V_1 ) == V_159 || F_37 ( V_1 ) == V_160 )
V_158 = V_161 ;
else
V_158 = V_162 ;
#if F_38 ( V_163 ) && V_163 != 0
V_157 = ( - V_162 ) & ( V_163 - 1 ) ;
#endif
if ( V_1 -> V_24 -> V_164 . V_55 == NULL )
{
V_154 = V_165
+ V_166
+ V_158 + V_157 ;
if ( V_1 -> V_167 & V_168 )
{
V_1 -> V_24 -> V_169 = 1 ;
V_154 += V_170 ;
}
#ifndef F_39
if ( ! ( V_1 -> V_167 & V_171 ) )
V_154 += V_172 ;
#endif
if ( ( V_16 = F_30 ( V_1 -> V_62 , 1 , V_154 ) ) == NULL )
goto V_91;
V_1 -> V_24 -> V_164 . V_55 = V_16 ;
V_1 -> V_24 -> V_164 . V_154 = V_154 ;
}
V_1 -> V_173 = & ( V_1 -> V_24 -> V_164 . V_55 [ 0 ] ) ;
return 1 ;
V_91:
F_9 ( V_174 , V_175 ) ;
return 0 ;
}
int F_40 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_154 , V_157 = 0 , V_158 ;
if ( F_37 ( V_1 ) == V_159 || F_37 ( V_1 ) == V_160 )
V_158 = V_161 + 1 ;
else
V_158 = V_162 ;
#if F_38 ( V_163 ) && V_163 != 0
V_157 = ( - V_162 ) & ( V_163 - 1 ) ;
#endif
if ( V_1 -> V_24 -> V_176 . V_55 == NULL )
{
V_154 = V_1 -> V_177
+ V_178
+ V_158 + V_157 ;
#ifndef F_39
if ( ! ( V_1 -> V_167 & V_171 ) )
V_154 += V_172 ;
#endif
if ( ! ( V_1 -> V_167 & V_179 ) )
V_154 += V_158 + V_157
+ V_178 ;
if ( ( V_16 = F_30 ( V_1 -> V_62 , 0 , V_154 ) ) == NULL )
goto V_91;
V_1 -> V_24 -> V_176 . V_55 = V_16 ;
V_1 -> V_24 -> V_176 . V_154 = V_154 ;
}
return 1 ;
V_91:
F_9 ( V_180 , V_175 ) ;
return 0 ;
}
int F_41 ( T_1 * V_1 )
{
if ( ! F_36 ( V_1 ) )
return 0 ;
if ( ! F_40 ( V_1 ) )
return 0 ;
return 1 ;
}
int F_42 ( T_1 * V_1 )
{
if ( V_1 -> V_24 -> V_176 . V_55 != NULL )
{
F_34 ( V_1 -> V_62 , 0 , V_1 -> V_24 -> V_176 . V_154 , V_1 -> V_24 -> V_176 . V_55 ) ;
V_1 -> V_24 -> V_176 . V_55 = NULL ;
}
return 1 ;
}
int F_43 ( T_1 * V_1 )
{
if ( V_1 -> V_24 -> V_164 . V_55 != NULL )
{
F_34 ( V_1 -> V_62 , 1 , V_1 -> V_24 -> V_164 . V_154 , V_1 -> V_24 -> V_164 . V_55 ) ;
V_1 -> V_24 -> V_164 . V_55 = NULL ;
}
return 1 ;
}
