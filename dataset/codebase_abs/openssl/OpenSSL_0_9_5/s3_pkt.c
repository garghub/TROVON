static int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
if ( ! V_4 )
{
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
V_1 -> V_8 -> V_9 . V_11 = 0 ;
V_1 -> V_12 = V_1 -> V_8 -> V_9 . V_13 + V_1 -> V_8 -> V_9 . V_11 ;
V_1 -> V_14 = 0 ;
}
if ( V_1 -> V_8 -> V_9 . V_10 >= ( int ) V_2 )
{
V_1 -> V_14 += V_2 ;
V_1 -> V_8 -> V_9 . V_10 -= V_2 ;
V_1 -> V_8 -> V_9 . V_11 += V_2 ;
return ( V_2 ) ;
}
if ( ! V_1 -> V_15 )
V_3 = V_2 ;
{
int V_16 = V_17 - V_1 -> V_14 ;
if ( V_1 -> V_18 & V_19 )
V_16 += V_20 ;
if ( V_3 > V_16 )
V_3 = V_16 ;
}
if ( V_2 > V_3 )
{
F_2 ( V_21 , V_22 ) ;
return - 1 ;
}
V_6 = V_1 -> V_14 ;
V_7 = V_1 -> V_8 -> V_9 . V_10 ;
if ( V_1 -> V_12 != V_1 -> V_8 -> V_9 . V_13 )
{
memmove ( V_1 -> V_8 -> V_9 . V_13 , V_1 -> V_12 , V_6 + V_7 ) ;
V_1 -> V_12 = V_1 -> V_8 -> V_9 . V_13 ;
}
while ( V_7 < V_2 )
{
F_3 () ;
if ( V_1 -> V_23 != NULL )
{
V_1 -> V_24 = V_25 ;
V_5 = F_4 ( V_1 -> V_23 , & ( V_1 -> V_8 -> V_9 . V_13 [ V_6 + V_7 ] ) , V_3 - V_7 ) ;
}
else
{
F_2 ( V_21 , V_26 ) ;
V_5 = - 1 ;
}
if ( V_5 <= 0 )
{
V_1 -> V_8 -> V_9 . V_10 = V_7 ;
return ( V_5 ) ;
}
V_7 += V_5 ;
}
V_1 -> V_8 -> V_9 . V_11 = V_6 + V_2 ;
V_1 -> V_8 -> V_9 . V_10 = V_7 - V_2 ;
V_1 -> V_14 += V_2 ;
V_1 -> V_24 = V_27 ;
return ( V_2 ) ;
}
static int F_5 ( T_1 * V_1 )
{
int V_28 , V_29 , V_30 ;
int V_2 , V_5 , V_31 = - 1 ;
T_2 * V_32 ;
T_3 * V_33 ;
unsigned char * V_34 ;
unsigned char V_35 [ V_36 ] ;
short V_37 ;
unsigned int V_38 ;
int V_39 = 0 , V_40 ;
V_32 = & ( V_1 -> V_8 -> V_41 ) ;
V_33 = V_1 -> V_42 ;
if ( V_1 -> V_18 & V_19 )
V_40 = V_20 ;
else
V_40 = 0 ;
V_43:
if ( ( V_1 -> V_44 != V_45 ) ||
( V_1 -> V_14 < V_46 ) )
{
V_2 = F_1 ( V_1 , V_46 ,
V_17 , 0 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
V_1 -> V_44 = V_45 ;
V_34 = V_1 -> V_12 ;
V_32 -> type = * ( V_34 ++ ) ;
V_28 = * ( V_34 ++ ) ;
V_29 = * ( V_34 ++ ) ;
V_37 = ( V_28 << 8 ) | V_29 ;
F_6 ( V_34 , V_32 -> V_47 ) ;
if ( V_1 -> V_48 )
{
V_1 -> V_48 = 0 ;
}
else
{
if ( V_37 != V_1 -> V_37 )
{
F_2 ( V_49 , V_50 ) ;
V_1 -> V_37 = V_37 ;
V_30 = V_51 ;
goto V_52;
}
}
if ( ( V_37 >> 8 ) != V_53 )
{
F_2 ( V_49 , V_50 ) ;
goto V_54;
}
if ( V_32 -> V_47 >
( unsigned int ) V_55 + V_40 )
{
V_30 = V_56 ;
F_2 ( V_49 , V_57 ) ;
goto V_52;
}
}
if ( V_32 -> V_47 > ( V_1 -> V_14 - V_46 ) )
{
V_5 = V_32 -> V_47 ;
V_2 = F_1 ( V_1 , V_5 , V_5 , 1 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
}
V_1 -> V_44 = V_58 ;
V_32 -> V_59 = & ( V_1 -> V_12 [ V_46 ] ) ;
if ( V_32 -> V_47 > ( unsigned int ) V_55 + V_40 )
{
V_30 = V_56 ;
F_2 ( V_49 , V_60 ) ;
goto V_52;
}
V_32 -> V_61 = V_32 -> V_59 ;
if ( ! V_1 -> V_62 -> V_63 -> V_64 ( V_1 , 0 ) )
{
V_30 = V_65 ;
goto V_52;
}
#ifdef F_7
printf ( L_1 , V_32 -> V_47 ) ;
{ unsigned int V_66 ; for ( V_66 = 0 ; V_66 < V_32 -> V_47 ; V_66 ++ ) printf ( L_2 , V_32 -> V_61 [ V_66 ] , ( ( V_66 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_33 == NULL ) ||
( V_1 -> V_67 == NULL ) ||
( V_1 -> V_68 == NULL ) )
V_39 = 1 ;
if ( ! V_39 )
{
V_38 = F_8 ( V_1 -> V_68 ) ;
if ( V_32 -> V_47 > V_69 + V_40 + V_38 )
{
V_30 = V_56 ;
F_2 ( V_49 , V_70 ) ;
goto V_52;
}
if ( V_32 -> V_47 < V_38 )
{
V_30 = V_71 ;
F_2 ( V_49 , V_72 ) ;
goto V_52;
}
V_32 -> V_47 -= V_38 ;
V_5 = V_1 -> V_62 -> V_63 -> V_73 ( V_1 , V_35 , 0 ) ;
if ( memcmp ( V_35 , & ( V_32 -> V_61 [ V_32 -> V_47 ] ) , V_38 ) != 0 )
{
V_30 = V_74 ;
F_2 ( V_49 , V_75 ) ;
V_31 = - 1 ;
goto V_52;
}
}
if ( V_1 -> V_76 != NULL )
{
if ( V_32 -> V_47 >
( unsigned int ) V_69 + V_40 )
{
V_30 = V_56 ;
F_2 ( V_49 , V_77 ) ;
goto V_52;
}
if ( ! F_9 ( V_1 ) )
{
V_30 = V_78 ;
F_2 ( V_49 , V_79 ) ;
goto V_52;
}
}
if ( V_32 -> V_47 > ( unsigned int ) V_80 + V_40 )
{
V_30 = V_56 ;
F_2 ( V_49 , V_81 ) ;
goto V_52;
}
V_32 -> V_6 = 0 ;
V_1 -> V_14 = 0 ;
if ( V_32 -> V_47 == 0 ) goto V_43;
return ( 1 ) ;
V_52:
F_10 ( V_1 , V_82 , V_30 ) ;
V_54:
return ( V_31 ) ;
}
static int F_9 ( T_1 * V_83 )
{
int V_5 ;
T_2 * V_32 ;
V_32 = & ( V_83 -> V_8 -> V_41 ) ;
V_5 = F_11 ( V_83 -> V_76 , V_32 -> V_84 ,
V_80 , V_32 -> V_61 , ( int ) V_32 -> V_47 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_32 -> V_47 = V_5 ;
V_32 -> V_61 = V_32 -> V_84 ;
return ( 1 ) ;
}
static int F_12 ( T_1 * V_83 )
{
int V_5 ;
T_2 * V_85 ;
V_85 = & ( V_83 -> V_8 -> V_86 ) ;
V_5 = F_13 ( V_83 -> V_87 , V_85 -> V_61 ,
V_69 ,
V_85 -> V_59 , ( int ) V_85 -> V_47 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_85 -> V_47 = V_5 ;
V_85 -> V_59 = V_85 -> V_61 ;
return ( 1 ) ;
}
int F_14 ( T_1 * V_1 , int type , const void * V_88 , int V_89 )
{
const unsigned char * V_13 = V_88 ;
unsigned int V_90 , V_2 , V_91 ;
int V_5 ;
V_1 -> V_24 = V_27 ;
V_90 = V_1 -> V_8 -> V_92 ;
V_1 -> V_8 -> V_92 = 0 ;
if ( F_15 ( V_1 ) && ! V_1 -> V_93 )
{
V_5 = V_1 -> V_94 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_2 ( V_95 , V_96 ) ;
return ( - 1 ) ;
}
}
V_2 = ( V_89 - V_90 ) ;
for (; ; )
{
if ( V_2 > V_80 )
V_91 = V_80 ;
else
V_91 = V_2 ;
V_5 = F_16 ( V_1 , type , & ( V_13 [ V_90 ] ) , V_91 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_8 -> V_92 = V_90 ;
return ( V_5 ) ;
}
if ( ( V_5 == ( int ) V_2 ) ||
( type == V_97 &&
( V_1 -> V_98 & V_99 ) ) )
{
return ( V_90 + V_5 ) ;
}
V_2 -= V_5 ;
V_90 += V_5 ;
}
}
static int F_16 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_89 )
{
unsigned char * V_34 , * V_100 ;
int V_5 , V_38 , V_39 = 0 ;
T_2 * V_85 ;
T_4 * V_101 ;
T_3 * V_33 ;
if ( V_1 -> V_8 -> V_102 . V_10 != 0 )
return ( F_17 ( V_1 , type , V_13 , V_89 ) ) ;
if ( V_1 -> V_8 -> V_103 )
{
V_5 = F_18 ( V_1 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
}
if ( V_89 == 0 ) return ( V_89 ) ;
V_85 = & ( V_1 -> V_8 -> V_86 ) ;
V_101 = & ( V_1 -> V_8 -> V_102 ) ;
V_33 = V_1 -> V_42 ;
if ( ( V_33 == NULL ) ||
( V_1 -> V_104 == NULL ) ||
( V_1 -> V_105 == NULL ) )
V_39 = 1 ;
if ( V_39 )
V_38 = 0 ;
else
V_38 = F_8 ( V_1 -> V_105 ) ;
V_34 = V_101 -> V_13 ;
* ( V_34 ++ ) = type & 0xff ;
V_85 -> type = type ;
* ( V_34 ++ ) = ( V_1 -> V_37 >> 8 ) ;
* ( V_34 ++ ) = V_1 -> V_37 & 0xff ;
V_100 = V_34 ;
V_34 += 2 ;
V_85 -> V_61 = V_34 ;
V_85 -> V_47 = ( int ) V_89 ;
V_85 -> V_59 = ( unsigned char * ) V_13 ;
if ( V_1 -> V_87 != NULL )
{
if ( ! F_12 ( V_1 ) )
{
F_2 ( V_106 , V_107 ) ;
goto V_54;
}
}
else
{
memcpy ( V_85 -> V_61 , V_85 -> V_59 , V_85 -> V_47 ) ;
V_85 -> V_59 = V_85 -> V_61 ;
}
if ( V_38 != 0 )
{
V_1 -> V_62 -> V_63 -> V_73 ( V_1 , & ( V_34 [ V_85 -> V_47 ] ) , 1 ) ;
V_85 -> V_47 += V_38 ;
V_85 -> V_59 = V_34 ;
V_85 -> V_61 = V_34 ;
}
V_1 -> V_62 -> V_63 -> V_64 ( V_1 , 1 ) ;
F_19 ( V_85 -> V_47 , V_100 ) ;
V_85 -> type = type ;
V_85 -> V_47 += V_46 ;
V_101 -> V_10 = V_85 -> V_47 ;
V_101 -> V_11 = 0 ;
V_1 -> V_8 -> V_108 = V_89 ;
V_1 -> V_8 -> V_109 = V_13 ;
V_1 -> V_8 -> V_110 = type ;
V_1 -> V_8 -> V_111 = V_89 ;
return ( F_17 ( V_1 , type , V_13 , V_89 ) ) ;
V_54:
return ( - 1 ) ;
}
static int F_17 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_89 )
{
int V_5 ;
if ( ( V_1 -> V_8 -> V_108 > ( int ) V_89 )
|| ( ( V_1 -> V_8 -> V_109 != V_13 ) &&
! ( V_1 -> V_98 & V_112 ) )
|| ( V_1 -> V_8 -> V_110 != type ) )
{
F_2 ( V_113 , V_114 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_3 () ;
if ( V_1 -> V_115 != NULL )
{
V_1 -> V_24 = V_116 ;
V_5 = F_20 ( V_1 -> V_115 ,
( char * ) & ( V_1 -> V_8 -> V_102 . V_13 [ V_1 -> V_8 -> V_102 . V_11 ] ) ,
( unsigned int ) V_1 -> V_8 -> V_102 . V_10 ) ;
}
else
{
F_2 ( V_113 , V_117 ) ;
V_5 = - 1 ;
}
if ( V_5 == V_1 -> V_8 -> V_102 . V_10 )
{
V_1 -> V_8 -> V_102 . V_10 = 0 ;
V_1 -> V_24 = V_27 ;
return ( V_1 -> V_8 -> V_111 ) ;
}
else if ( V_5 <= 0 )
return ( V_5 ) ;
V_1 -> V_8 -> V_102 . V_11 += V_5 ;
V_1 -> V_8 -> V_102 . V_10 -= V_5 ;
}
}
int F_21 ( T_1 * V_1 , int type , unsigned char * V_13 , int V_89 )
{
int V_30 , V_5 , V_118 , V_31 ;
unsigned int V_2 ;
T_2 * V_32 ;
void (* F_22)() = NULL ;
if ( V_1 -> V_8 -> V_9 . V_13 == NULL )
if ( ! F_23 ( V_1 ) )
return ( - 1 ) ;
if ( ( type != V_97 ) && ( type != V_119 ) && type )
{
F_2 ( V_120 , V_22 ) ;
return - 1 ;
}
if ( ( type == V_119 ) && ( V_1 -> V_8 -> V_121 > 0 ) )
{
unsigned char * V_122 = V_1 -> V_8 -> V_123 ;
unsigned char * V_124 = V_13 ;
unsigned int V_125 ;
V_2 = 0 ;
while ( ( V_89 > 0 ) && ( V_1 -> V_8 -> V_121 > 0 ) )
{
* V_124 ++ = * V_122 ++ ;
V_89 -- ; V_1 -> V_8 -> V_121 -- ;
V_2 ++ ;
}
for ( V_125 = 0 ; V_125 < V_1 -> V_8 -> V_121 ; V_125 ++ )
V_1 -> V_8 -> V_123 [ V_125 ] = * V_122 ++ ;
return V_2 ;
}
if ( ! V_1 -> V_93 && F_15 ( V_1 ) )
{
V_5 = V_1 -> V_94 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_2 ( V_120 , V_96 ) ;
return ( - 1 ) ;
}
}
V_126:
V_1 -> V_24 = V_27 ;
V_32 = & ( V_1 -> V_8 -> V_41 ) ;
if ( ( V_32 -> V_47 == 0 ) || ( V_1 -> V_44 == V_45 ) )
{
V_31 = F_5 ( V_1 ) ;
if ( V_31 <= 0 ) return ( V_31 ) ;
}
if ( V_1 -> V_8 -> V_127
&& ( V_32 -> type != V_119 ) )
{
V_30 = V_128 ;
F_2 ( V_120 , V_129 ) ;
goto V_54;
}
if ( V_1 -> V_130 & V_131 )
{
V_32 -> V_47 = 0 ;
V_1 -> V_24 = V_27 ;
return ( 0 ) ;
}
if ( type == V_32 -> type )
{
if ( F_15 ( V_1 ) && ( type == V_97 ) &&
( V_1 -> V_67 == NULL ) )
{
V_30 = V_128 ;
F_2 ( V_120 , V_132 ) ;
goto V_52;
}
if ( V_89 <= 0 ) return ( V_89 ) ;
if ( ( unsigned int ) V_89 > V_32 -> V_47 )
V_2 = V_32 -> V_47 ;
else
V_2 = ( unsigned int ) V_89 ;
memcpy ( V_13 , & ( V_32 -> V_61 [ V_32 -> V_6 ] ) , V_2 ) ;
V_32 -> V_47 -= V_2 ;
V_32 -> V_6 += V_2 ;
if ( V_32 -> V_47 == 0 )
{
V_1 -> V_44 = V_58 ;
V_32 -> V_6 = 0 ;
}
return ( V_2 ) ;
}
{
unsigned int V_133 = 0 ;
unsigned char * V_134 = NULL ;
unsigned int * V_135 = NULL ;
if ( V_32 -> type == V_119 )
{
V_133 = sizeof V_1 -> V_8 -> V_123 ;
V_134 = V_1 -> V_8 -> V_123 ;
V_135 = & V_1 -> V_8 -> V_121 ;
}
else if ( V_32 -> type == V_136 )
{
V_133 = sizeof V_1 -> V_8 -> V_137 ;
V_134 = V_1 -> V_8 -> V_137 ;
V_135 = & V_1 -> V_8 -> V_138 ;
}
if ( V_133 > 0 )
{
V_2 = V_133 - * V_135 ;
if ( V_32 -> V_47 < V_2 )
V_2 = V_32 -> V_47 ;
while ( V_2 -- > 0 )
{
V_134 [ ( * V_135 ) ++ ] = V_32 -> V_61 [ V_32 -> V_6 ++ ] ;
V_32 -> V_47 -- ;
}
if ( * V_135 < V_133 )
goto V_126;
}
}
if ( ( ! V_1 -> V_139 ) &&
( V_1 -> V_8 -> V_121 >= 4 ) &&
( V_1 -> V_8 -> V_123 [ 0 ] == V_140 ) &&
( V_1 -> V_42 != NULL ) && ( V_1 -> V_42 -> V_141 != NULL ) )
{
V_1 -> V_8 -> V_121 = 0 ;
if ( ( V_1 -> V_8 -> V_123 [ 1 ] != 0 ) ||
( V_1 -> V_8 -> V_123 [ 2 ] != 0 ) ||
( V_1 -> V_8 -> V_123 [ 3 ] != 0 ) )
{
V_30 = V_71 ;
F_2 ( V_120 , V_142 ) ;
goto V_54;
}
if ( F_24 ( V_1 ) &&
! ( V_1 -> V_8 -> V_143 & V_144 ) &&
! V_1 -> V_8 -> V_145 )
{
F_25 ( V_1 ) ;
if ( F_26 ( V_1 ) )
{
V_5 = V_1 -> V_94 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_2 ( V_120 , V_96 ) ;
return ( - 1 ) ;
}
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
{
T_5 * V_146 ;
V_1 -> V_24 = V_25 ;
V_146 = F_27 ( V_1 ) ;
F_28 ( V_146 ) ;
F_29 ( V_146 ) ;
return ( - 1 ) ;
}
}
}
goto V_126;
}
if ( V_1 -> V_8 -> V_138 >= 2 )
{
int V_147 = V_1 -> V_8 -> V_137 [ 0 ] ;
int V_148 = V_1 -> V_8 -> V_137 [ 1 ] ;
V_1 -> V_8 -> V_138 = 0 ;
if ( V_1 -> V_149 != NULL )
F_22 = V_1 -> V_149 ;
else if ( V_1 -> V_150 -> V_149 != NULL )
F_22 = V_1 -> V_150 -> V_149 ;
if ( F_22 != NULL )
{
V_118 = ( V_147 << 8 ) | V_148 ;
F_22 ( V_1 , V_151 , V_118 ) ;
}
if ( V_147 == 1 )
{
V_1 -> V_8 -> V_152 = V_148 ;
if ( V_148 == V_153 )
{
V_1 -> V_130 |= V_131 ;
return ( 0 ) ;
}
}
else if ( V_147 == 2 )
{
char V_154 [ 16 ] ;
V_1 -> V_24 = V_27 ;
V_1 -> V_8 -> V_155 = V_148 ;
F_2 ( V_120 , V_156 + V_148 ) ;
sprintf ( V_154 , L_4 , V_148 ) ;
F_30 ( 2 , L_5 , V_154 ) ;
V_1 -> V_130 |= V_131 ;
F_31 ( V_1 -> V_150 , V_1 -> V_42 ) ;
return ( 0 ) ;
}
else
{
V_30 = V_157 ;
F_2 ( V_120 , V_158 ) ;
goto V_52;
}
goto V_126;
}
if ( V_1 -> V_130 & V_159 )
{
V_1 -> V_24 = V_27 ;
V_32 -> V_47 = 0 ;
return ( 0 ) ;
}
if ( V_32 -> type == V_160 )
{
if ( ( V_32 -> V_47 != 1 ) || ( V_32 -> V_6 != 0 ) ||
( V_32 -> V_61 [ 0 ] != V_161 ) )
{
V_5 = V_157 ;
F_2 ( V_120 , V_162 ) ;
goto V_54;
}
V_32 -> V_47 = 0 ;
V_1 -> V_8 -> V_127 = 1 ;
if ( ! F_32 ( V_1 ) )
goto V_54;
else
goto V_126;
}
if ( ( V_1 -> V_8 -> V_121 >= 4 ) && ! V_1 -> V_93 )
{
if ( ( ( V_1 -> V_163 & V_164 ) == V_165 ) &&
! ( V_1 -> V_8 -> V_143 & V_144 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_1 -> V_163 = V_1 -> V_139 ? V_166 : V_167 ;
#endif
V_1 -> V_168 = 1 ;
}
V_5 = V_1 -> V_94 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_2 ( V_120 , V_96 ) ;
return ( - 1 ) ;
}
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
{
T_5 * V_146 ;
V_1 -> V_24 = V_25 ;
V_146 = F_27 ( V_1 ) ;
F_28 ( V_146 ) ;
F_29 ( V_146 ) ;
return ( - 1 ) ;
}
goto V_126;
}
switch ( V_32 -> type )
{
default:
#ifndef F_33
if ( V_1 -> V_37 == V_169 )
{
goto V_126;
}
#endif
V_30 = V_128 ;
F_2 ( V_120 , V_170 ) ;
goto V_52;
case V_160 :
case V_136 :
case V_119 :
V_30 = V_128 ;
F_2 ( V_120 , V_22 ) ;
goto V_52;
case V_97 :
if ( V_1 -> V_8 -> V_171 &&
( V_1 -> V_8 -> V_172 != 0 ) &&
( (
( V_1 -> V_163 & V_167 ) &&
( V_1 -> V_163 >= V_173 ) &&
( V_1 -> V_163 <= V_174 )
) || (
( V_1 -> V_163 & V_166 ) &&
( V_1 -> V_163 <= V_175 ) &&
( V_1 -> V_163 >= V_176 )
)
) )
{
V_1 -> V_8 -> V_171 = 0 ;
return ( - 1 ) ;
}
else
{
V_30 = V_128 ;
F_2 ( V_120 , V_170 ) ;
goto V_52;
}
}
V_52:
F_10 ( V_1 , V_82 , V_30 ) ;
V_54:
return ( - 1 ) ;
}
static int F_32 ( T_1 * V_1 )
{
int V_5 ;
const char * V_177 ;
int V_178 ;
if ( V_1 -> V_163 & V_166 )
V_5 = V_179 ;
else
V_5 = V_180 ;
if ( V_1 -> V_8 -> V_154 . V_181 == NULL )
{
V_1 -> V_42 -> V_141 = V_1 -> V_8 -> V_154 . V_182 ;
if ( ! V_1 -> V_62 -> V_63 -> V_183 ( V_1 ) ) return ( 0 ) ;
}
if ( ! V_1 -> V_62 -> V_63 -> V_184 ( V_1 , V_5 ) )
return ( 0 ) ;
if ( V_1 -> V_163 & V_167 )
{
V_177 = V_1 -> V_62 -> V_63 -> V_185 ;
V_178 = V_1 -> V_62 -> V_63 -> V_186 ;
}
else
{
V_177 = V_1 -> V_62 -> V_63 -> V_187 ;
V_178 = V_1 -> V_62 -> V_63 -> V_188 ;
}
V_1 -> V_8 -> V_154 . V_189 = V_1 -> V_62 -> V_63 -> V_190 ( V_1 ,
& ( V_1 -> V_8 -> V_191 ) ,
& ( V_1 -> V_8 -> V_192 ) ,
V_177 , V_178 , V_1 -> V_8 -> V_154 . V_193 ) ;
return ( 1 ) ;
}
void F_10 ( T_1 * V_1 , int V_194 , int V_195 )
{
V_195 = V_1 -> V_62 -> V_63 -> V_196 ( V_195 ) ;
if ( V_195 < 0 ) return;
if ( ( V_194 == 2 ) && ( V_1 -> V_42 != NULL ) )
F_31 ( V_1 -> V_150 , V_1 -> V_42 ) ;
V_1 -> V_8 -> V_103 = 1 ;
V_1 -> V_8 -> V_197 [ 0 ] = V_194 ;
V_1 -> V_8 -> V_197 [ 1 ] = V_195 ;
if ( V_1 -> V_8 -> V_102 . V_10 == 0 )
F_18 ( V_1 ) ;
}
int F_18 ( T_1 * V_1 )
{
int V_5 , V_118 ;
void (* F_22)() = NULL ;
V_1 -> V_8 -> V_103 = 0 ;
V_5 = F_16 ( V_1 , V_136 , & V_1 -> V_8 -> V_197 [ 0 ] , 2 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_8 -> V_103 = 1 ;
}
else
{
if ( V_1 -> V_8 -> V_197 [ 0 ] == V_82 )
( void ) F_34 ( V_1 -> V_115 ) ;
if ( V_1 -> V_149 != NULL )
F_22 = V_1 -> V_149 ;
else if ( V_1 -> V_150 -> V_149 != NULL )
F_22 = V_1 -> V_150 -> V_149 ;
if ( F_22 != NULL )
{
V_118 = ( V_1 -> V_8 -> V_197 [ 0 ] << 8 ) | V_1 -> V_8 -> V_197 [ 1 ] ;
F_22 ( V_1 , V_198 , V_118 ) ;
}
}
return ( V_5 ) ;
}
