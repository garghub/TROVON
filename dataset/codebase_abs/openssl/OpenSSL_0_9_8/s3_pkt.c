int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
if ( ! V_4 )
{
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
V_1 -> V_8 -> V_9 . V_11 = 0 ;
V_1 -> V_12 = V_1 -> V_8 -> V_9 . V_13 + V_1 -> V_8 -> V_9 . V_11 ;
V_1 -> V_14 = 0 ;
}
if ( F_2 ( V_1 ) == V_15 &&
V_4 )
{
if ( V_1 -> V_8 -> V_9 . V_10 > 0 && V_2 > V_1 -> V_8 -> V_9 . V_10 )
V_2 = V_1 -> V_8 -> V_9 . V_10 ;
}
if ( V_1 -> V_8 -> V_9 . V_10 >= ( int ) V_2 )
{
V_1 -> V_14 += V_2 ;
V_1 -> V_8 -> V_9 . V_10 -= V_2 ;
V_1 -> V_8 -> V_9 . V_11 += V_2 ;
return ( V_2 ) ;
}
if ( ! V_1 -> V_16 )
V_3 = V_2 ;
{
int V_17 = V_1 -> V_8 -> V_9 . V_18 - V_1 -> V_14 ;
if ( V_3 > V_17 )
V_3 = V_17 ;
}
if ( V_2 > V_3 )
{
F_3 ( V_19 , V_20 ) ;
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
F_4 () ;
if ( V_1 -> V_21 != NULL )
{
V_1 -> V_22 = V_23 ;
V_5 = F_5 ( V_1 -> V_21 , & ( V_1 -> V_8 -> V_9 . V_13 [ V_6 + V_7 ] ) , V_3 - V_7 ) ;
}
else
{
F_3 ( V_19 , V_24 ) ;
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
V_1 -> V_22 = V_25 ;
return ( V_2 ) ;
}
static int F_6 ( T_1 * V_1 )
{
int V_26 , V_27 , V_28 ;
int V_29 , V_2 , V_5 , V_30 = - 1 ;
T_2 * V_31 ;
T_3 * V_32 ;
unsigned char * V_33 ;
unsigned char V_34 [ V_35 ] ;
short V_36 ;
unsigned int V_37 ;
int V_38 = 0 ;
T_4 V_39 ;
int V_40 = 0 ;
unsigned char * V_41 = NULL ;
V_31 = & ( V_1 -> V_8 -> V_42 ) ;
V_32 = V_1 -> V_43 ;
if ( V_1 -> V_44 & V_45 )
V_39 = V_46 ;
else
V_39 = 0 ;
if ( V_39 != V_1 -> V_8 -> V_9 . V_18 - V_47 )
{
F_3 ( V_48 , V_20 ) ;
return - 1 ;
}
V_49:
if ( ( V_1 -> V_50 != V_51 ) ||
( V_1 -> V_14 < V_52 ) )
{
V_2 = F_1 ( V_1 , V_52 , V_1 -> V_8 -> V_9 . V_18 , 0 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
V_1 -> V_50 = V_51 ;
V_33 = V_1 -> V_12 ;
V_31 -> type = * ( V_33 ++ ) ;
V_26 = * ( V_33 ++ ) ;
V_27 = * ( V_33 ++ ) ;
V_36 = ( V_26 << 8 ) | V_27 ;
F_7 ( V_33 , V_31 -> V_53 ) ;
if ( V_1 -> V_54 )
{
V_1 -> V_54 = 0 ;
}
else
{
if ( V_36 != V_1 -> V_36 )
{
F_3 ( V_48 , V_55 ) ;
V_1 -> V_36 = V_36 ;
V_28 = V_56 ;
goto V_57;
}
}
if ( ( V_36 >> 8 ) != V_58 )
{
F_3 ( V_48 , V_55 ) ;
goto V_59;
}
if ( V_31 -> V_53 > V_60 + V_39 )
{
V_28 = V_61 ;
F_3 ( V_48 , V_62 ) ;
goto V_57;
}
}
if ( V_31 -> V_53 > V_1 -> V_14 - V_52 )
{
V_5 = V_31 -> V_53 ;
V_2 = F_1 ( V_1 , V_5 , V_5 , 1 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
}
V_1 -> V_50 = V_63 ;
V_31 -> V_64 = & ( V_1 -> V_12 [ V_52 ] ) ;
if ( V_31 -> V_53 > V_60 + V_39 )
{
V_28 = V_61 ;
F_3 ( V_48 , V_65 ) ;
goto V_57;
}
V_31 -> V_66 = V_31 -> V_64 ;
V_29 = V_1 -> V_67 -> V_68 -> V_69 ( V_1 , 0 ) ;
if ( V_29 <= 0 )
{
if ( V_29 == 0 )
goto V_59;
V_40 = 1 ;
}
#ifdef F_8
printf ( L_1 , V_31 -> V_53 ) ;
{ unsigned int V_70 ; for ( V_70 = 0 ; V_70 < V_31 -> V_53 ; V_70 ++ ) printf ( L_2 , V_31 -> V_66 [ V_70 ] , ( ( V_70 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_32 == NULL ) ||
( V_1 -> V_71 == NULL ) ||
( V_1 -> V_72 == NULL ) )
V_38 = 1 ;
if ( ! V_38 )
{
V_37 = F_9 ( V_1 -> V_72 ) ;
if ( V_31 -> V_53 > V_73 + V_39 + V_37 )
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
V_40 = 1 ;
#endif
}
if ( V_31 -> V_53 >= V_37 )
{
V_31 -> V_53 -= V_37 ;
V_41 = & V_31 -> V_66 [ V_31 -> V_53 ] ;
}
else
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
V_40 = 1 ;
V_31 -> V_53 = 0 ;
#endif
}
V_5 = V_1 -> V_67 -> V_68 -> V_41 ( V_1 , V_34 , 0 ) ;
if ( V_41 == NULL || memcmp ( V_34 , V_41 , V_37 ) != 0 )
{
V_40 = 1 ;
}
}
if ( V_40 )
{
V_28 = V_74 ;
F_3 ( V_48 , V_75 ) ;
goto V_57;
}
if ( V_1 -> V_76 != NULL )
{
if ( V_31 -> V_53 > V_73 + V_39 )
{
V_28 = V_61 ;
F_3 ( V_48 , V_77 ) ;
goto V_57;
}
if ( ! F_10 ( V_1 ) )
{
V_28 = V_78 ;
F_3 ( V_48 , V_79 ) ;
goto V_57;
}
}
if ( V_31 -> V_53 > V_80 + V_39 )
{
V_28 = V_61 ;
F_3 ( V_48 , V_81 ) ;
goto V_57;
}
V_31 -> V_6 = 0 ;
V_1 -> V_14 = 0 ;
if ( V_31 -> V_53 == 0 ) goto V_49;
return ( 1 ) ;
V_57:
F_11 ( V_1 , V_82 , V_28 ) ;
V_59:
return ( V_30 ) ;
}
int F_10 ( T_1 * V_83 )
{
int V_5 ;
T_2 * V_31 ;
V_31 = & ( V_83 -> V_8 -> V_42 ) ;
V_5 = F_12 ( V_83 -> V_76 , V_31 -> V_84 ,
V_80 , V_31 -> V_66 , ( int ) V_31 -> V_53 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_31 -> V_53 = V_5 ;
V_31 -> V_66 = V_31 -> V_84 ;
return ( 1 ) ;
}
int F_13 ( T_1 * V_83 )
{
int V_5 ;
T_2 * V_85 ;
V_85 = & ( V_83 -> V_8 -> V_86 ) ;
V_5 = F_14 ( V_83 -> V_87 , V_85 -> V_66 ,
V_73 ,
V_85 -> V_64 , ( int ) V_85 -> V_53 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_85 -> V_53 = V_5 ;
V_85 -> V_64 = V_85 -> V_66 ;
return ( 1 ) ;
}
int F_15 ( T_1 * V_1 , int type , const void * V_88 , int V_18 )
{
const unsigned char * V_13 = V_88 ;
unsigned int V_89 , V_2 , V_90 ;
int V_5 ;
V_1 -> V_22 = V_25 ;
V_89 = V_1 -> V_8 -> V_91 ;
V_1 -> V_8 -> V_91 = 0 ;
if ( F_16 ( V_1 ) && ! V_1 -> V_92 )
{
V_5 = V_1 -> V_93 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_3 ( V_94 , V_95 ) ;
return - 1 ;
}
}
V_2 = ( V_18 - V_89 ) ;
for (; ; )
{
if ( V_2 > V_80 )
V_90 = V_80 ;
else
V_90 = V_2 ;
V_5 = F_17 ( V_1 , type , & ( V_13 [ V_89 ] ) , V_90 , 0 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_8 -> V_91 = V_89 ;
return V_5 ;
}
if ( ( V_5 == ( int ) V_2 ) ||
( type == V_96 &&
( V_1 -> V_97 & V_98 ) ) )
{
V_1 -> V_8 -> V_99 = 0 ;
return V_89 + V_5 ;
}
V_2 -= V_5 ;
V_89 += V_5 ;
}
}
static int F_17 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_18 , int V_100 )
{
unsigned char * V_33 , * V_101 ;
int V_5 , V_37 , V_38 = 0 ;
int V_102 = 0 ;
T_2 * V_85 ;
T_5 * V_103 ;
T_3 * V_32 ;
if ( V_1 -> V_8 -> V_104 . V_10 != 0 )
return ( F_18 ( V_1 , type , V_13 , V_18 ) ) ;
if ( V_1 -> V_8 -> V_105 )
{
V_5 = V_1 -> V_67 -> V_106 ( V_1 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
}
if ( V_18 == 0 && ! V_100 )
return 0 ;
V_85 = & ( V_1 -> V_8 -> V_86 ) ;
V_103 = & ( V_1 -> V_8 -> V_104 ) ;
V_32 = V_1 -> V_43 ;
if ( ( V_32 == NULL ) ||
( V_1 -> V_107 == NULL ) ||
( V_1 -> V_108 == NULL ) )
V_38 = 1 ;
if ( V_38 )
V_37 = 0 ;
else
V_37 = F_9 ( V_1 -> V_108 ) ;
if ( ! V_38 && ! V_100 && ! V_1 -> V_8 -> V_99 )
{
if ( V_1 -> V_8 -> V_109 && type == V_96 )
{
V_102 = F_17 ( V_1 , type , V_13 , 0 , 1 ) ;
if ( V_102 <= 0 )
goto V_59;
if ( V_1 -> V_8 -> V_104 . V_18 < ( T_4 ) V_102 + V_47 )
{
F_3 ( V_110 , V_20 ) ;
goto V_59;
}
}
V_1 -> V_8 -> V_99 = 1 ;
}
V_33 = V_103 -> V_13 + V_102 ;
* ( V_33 ++ ) = type & 0xff ;
V_85 -> type = type ;
* ( V_33 ++ ) = ( V_1 -> V_36 >> 8 ) ;
* ( V_33 ++ ) = V_1 -> V_36 & 0xff ;
V_101 = V_33 ;
V_33 += 2 ;
V_85 -> V_66 = V_33 ;
V_85 -> V_53 = ( int ) V_18 ;
V_85 -> V_64 = ( unsigned char * ) V_13 ;
if ( V_1 -> V_87 != NULL )
{
if ( ! F_13 ( V_1 ) )
{
F_3 ( V_110 , V_111 ) ;
goto V_59;
}
}
else
{
memcpy ( V_85 -> V_66 , V_85 -> V_64 , V_85 -> V_53 ) ;
V_85 -> V_64 = V_85 -> V_66 ;
}
if ( V_37 != 0 )
{
V_1 -> V_67 -> V_68 -> V_41 ( V_1 , & ( V_33 [ V_85 -> V_53 ] ) , 1 ) ;
V_85 -> V_53 += V_37 ;
V_85 -> V_64 = V_33 ;
V_85 -> V_66 = V_33 ;
}
V_1 -> V_67 -> V_68 -> V_69 ( V_1 , 1 ) ;
F_19 ( V_85 -> V_53 , V_101 ) ;
V_85 -> type = type ;
V_85 -> V_53 += V_52 ;
if ( V_100 )
{
return V_85 -> V_53 ;
}
V_103 -> V_10 = V_102 + V_85 -> V_53 ;
V_103 -> V_11 = 0 ;
V_1 -> V_8 -> V_112 = V_18 ;
V_1 -> V_8 -> V_113 = V_13 ;
V_1 -> V_8 -> V_114 = type ;
V_1 -> V_8 -> V_115 = V_18 ;
return F_18 ( V_1 , type , V_13 , V_18 ) ;
V_59:
return - 1 ;
}
int F_18 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_18 )
{
int V_5 ;
if ( ( V_1 -> V_8 -> V_112 > ( int ) V_18 )
|| ( ( V_1 -> V_8 -> V_113 != V_13 ) &&
! ( V_1 -> V_97 & V_116 ) )
|| ( V_1 -> V_8 -> V_114 != type ) )
{
F_3 ( V_117 , V_118 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_4 () ;
if ( V_1 -> V_119 != NULL )
{
V_1 -> V_22 = V_120 ;
V_5 = F_20 ( V_1 -> V_119 ,
( char * ) & ( V_1 -> V_8 -> V_104 . V_13 [ V_1 -> V_8 -> V_104 . V_11 ] ) ,
( unsigned int ) V_1 -> V_8 -> V_104 . V_10 ) ;
}
else
{
F_3 ( V_117 , V_121 ) ;
V_5 = - 1 ;
}
if ( V_5 == V_1 -> V_8 -> V_104 . V_10 )
{
V_1 -> V_8 -> V_104 . V_10 = 0 ;
V_1 -> V_22 = V_25 ;
return ( V_1 -> V_8 -> V_115 ) ;
}
else if ( V_5 <= 0 )
return ( V_5 ) ;
V_1 -> V_8 -> V_104 . V_11 += V_5 ;
V_1 -> V_8 -> V_104 . V_10 -= V_5 ;
}
}
int F_21 ( T_1 * V_1 , int type , unsigned char * V_13 , int V_18 , int V_122 )
{
int V_28 , V_5 , V_123 , V_30 ;
unsigned int V_2 ;
T_2 * V_31 ;
void (* F_22)( const T_1 * V_83 , int V_124 , int V_125 ) = NULL ;
if ( V_1 -> V_8 -> V_9 . V_13 == NULL )
if ( ! F_23 ( V_1 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_96 ) && ( type != V_126 ) && type ) ||
( V_122 && ( type != V_96 ) ) )
{
F_3 ( V_127 , V_20 ) ;
return - 1 ;
}
if ( ( type == V_126 ) && ( V_1 -> V_8 -> V_128 > 0 ) )
{
unsigned char * V_129 = V_1 -> V_8 -> V_130 ;
unsigned char * V_131 = V_13 ;
unsigned int V_132 ;
V_2 = 0 ;
while ( ( V_18 > 0 ) && ( V_1 -> V_8 -> V_128 > 0 ) )
{
* V_131 ++ = * V_129 ++ ;
V_18 -- ; V_1 -> V_8 -> V_128 -- ;
V_2 ++ ;
}
for ( V_132 = 0 ; V_132 < V_1 -> V_8 -> V_128 ; V_132 ++ )
V_1 -> V_8 -> V_130 [ V_132 ] = * V_129 ++ ;
return V_2 ;
}
if ( ! V_1 -> V_92 && F_16 ( V_1 ) )
{
V_5 = V_1 -> V_93 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_3 ( V_127 , V_95 ) ;
return ( - 1 ) ;
}
}
V_133:
V_1 -> V_22 = V_25 ;
V_31 = & ( V_1 -> V_8 -> V_42 ) ;
if ( ( V_31 -> V_53 == 0 ) || ( V_1 -> V_50 == V_51 ) )
{
V_30 = F_6 ( V_1 ) ;
if ( V_30 <= 0 ) return ( V_30 ) ;
}
if ( V_1 -> V_8 -> V_134
&& ( V_31 -> type != V_126 ) )
{
V_28 = V_135 ;
F_3 ( V_127 , V_136 ) ;
goto V_57;
}
if ( V_1 -> V_137 & V_138 )
{
V_31 -> V_53 = 0 ;
V_1 -> V_22 = V_25 ;
return ( 0 ) ;
}
if ( type == V_31 -> type )
{
if ( F_16 ( V_1 ) && ( type == V_96 ) &&
( V_1 -> V_71 == NULL ) )
{
V_28 = V_135 ;
F_3 ( V_127 , V_139 ) ;
goto V_57;
}
if ( V_18 <= 0 ) return ( V_18 ) ;
if ( ( unsigned int ) V_18 > V_31 -> V_53 )
V_2 = V_31 -> V_53 ;
else
V_2 = ( unsigned int ) V_18 ;
memcpy ( V_13 , & ( V_31 -> V_66 [ V_31 -> V_6 ] ) , V_2 ) ;
if ( ! V_122 )
{
V_31 -> V_53 -= V_2 ;
V_31 -> V_6 += V_2 ;
if ( V_31 -> V_53 == 0 )
{
V_1 -> V_50 = V_63 ;
V_31 -> V_6 = 0 ;
}
}
return ( V_2 ) ;
}
{
unsigned int V_140 = 0 ;
unsigned char * V_141 = NULL ;
unsigned int * V_142 = NULL ;
if ( V_31 -> type == V_126 )
{
V_140 = sizeof V_1 -> V_8 -> V_130 ;
V_141 = V_1 -> V_8 -> V_130 ;
V_142 = & V_1 -> V_8 -> V_128 ;
}
else if ( V_31 -> type == V_143 )
{
V_140 = sizeof V_1 -> V_8 -> V_144 ;
V_141 = V_1 -> V_8 -> V_144 ;
V_142 = & V_1 -> V_8 -> V_145 ;
}
if ( V_140 > 0 )
{
V_2 = V_140 - * V_142 ;
if ( V_31 -> V_53 < V_2 )
V_2 = V_31 -> V_53 ;
while ( V_2 -- > 0 )
{
V_141 [ ( * V_142 ) ++ ] = V_31 -> V_66 [ V_31 -> V_6 ++ ] ;
V_31 -> V_53 -- ;
}
if ( * V_142 < V_140 )
goto V_133;
}
}
if ( ( ! V_1 -> V_146 ) &&
( V_1 -> V_8 -> V_128 >= 4 ) &&
( V_1 -> V_8 -> V_130 [ 0 ] == V_147 ) &&
( V_1 -> V_43 != NULL ) && ( V_1 -> V_43 -> V_148 != NULL ) )
{
V_1 -> V_8 -> V_128 = 0 ;
if ( ( V_1 -> V_8 -> V_130 [ 1 ] != 0 ) ||
( V_1 -> V_8 -> V_130 [ 2 ] != 0 ) ||
( V_1 -> V_8 -> V_130 [ 3 ] != 0 ) )
{
V_28 = V_149 ;
F_3 ( V_127 , V_150 ) ;
goto V_57;
}
if ( V_1 -> V_151 )
V_1 -> V_151 ( 0 , V_1 -> V_36 , V_126 , V_1 -> V_8 -> V_130 , 4 , V_1 , V_1 -> V_152 ) ;
if ( F_24 ( V_1 ) &&
! ( V_1 -> V_8 -> V_153 & V_154 ) &&
! V_1 -> V_8 -> V_155 )
{
F_25 ( V_1 ) ;
if ( F_26 ( V_1 ) )
{
V_5 = V_1 -> V_93 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_3 ( V_127 , V_95 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_97 & V_156 ) )
{
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
{
T_6 * V_157 ;
V_1 -> V_22 = V_23 ;
V_157 = F_27 ( V_1 ) ;
F_28 ( V_157 ) ;
F_29 ( V_157 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_133;
}
if ( V_1 -> V_8 -> V_145 >= 2 )
{
int V_158 = V_1 -> V_8 -> V_144 [ 0 ] ;
int V_159 = V_1 -> V_8 -> V_144 [ 1 ] ;
V_1 -> V_8 -> V_145 = 0 ;
if ( V_1 -> V_151 )
V_1 -> V_151 ( 0 , V_1 -> V_36 , V_143 , V_1 -> V_8 -> V_144 , 2 , V_1 , V_1 -> V_152 ) ;
if ( V_1 -> V_160 != NULL )
F_22 = V_1 -> V_160 ;
else if ( V_1 -> V_161 -> V_160 != NULL )
F_22 = V_1 -> V_161 -> V_160 ;
if ( F_22 != NULL )
{
V_123 = ( V_158 << 8 ) | V_159 ;
F_22 ( V_1 , V_162 , V_123 ) ;
}
if ( V_158 == 1 )
{
V_1 -> V_8 -> V_163 = V_159 ;
if ( V_159 == V_164 )
{
V_1 -> V_137 |= V_138 ;
return ( 0 ) ;
}
}
else if ( V_158 == 2 )
{
char V_165 [ 16 ] ;
V_1 -> V_22 = V_25 ;
V_1 -> V_8 -> V_166 = V_159 ;
F_3 ( V_127 , V_167 + V_159 ) ;
F_30 ( V_165 , sizeof V_165 , L_4 , V_159 ) ;
F_31 ( 2 , L_5 , V_165 ) ;
V_1 -> V_137 |= V_138 ;
F_32 ( V_1 -> V_161 , V_1 -> V_43 ) ;
return ( 0 ) ;
}
else
{
V_28 = V_168 ;
F_3 ( V_127 , V_169 ) ;
goto V_57;
}
goto V_133;
}
if ( V_1 -> V_137 & V_170 )
{
V_1 -> V_22 = V_25 ;
V_31 -> V_53 = 0 ;
return ( 0 ) ;
}
if ( V_31 -> type == V_171 )
{
if ( ( V_31 -> V_53 != 1 ) || ( V_31 -> V_6 != 0 ) ||
( V_31 -> V_66 [ 0 ] != V_172 ) )
{
V_28 = V_168 ;
F_3 ( V_127 , V_173 ) ;
goto V_57;
}
if ( V_1 -> V_8 -> V_165 . V_174 == NULL )
{
V_28 = V_135 ;
F_3 ( V_127 , V_175 ) ;
goto V_57;
}
V_31 -> V_53 = 0 ;
if ( V_1 -> V_151 )
V_1 -> V_151 ( 0 , V_1 -> V_36 , V_171 , V_31 -> V_66 , 1 , V_1 , V_1 -> V_152 ) ;
V_1 -> V_8 -> V_134 = 1 ;
if ( ! F_33 ( V_1 ) )
goto V_59;
else
goto V_133;
}
if ( ( V_1 -> V_8 -> V_128 >= 4 ) && ! V_1 -> V_92 )
{
if ( ( ( V_1 -> V_176 & V_177 ) == V_178 ) &&
! ( V_1 -> V_8 -> V_153 & V_154 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_1 -> V_176 = V_1 -> V_146 ? V_179 : V_180 ;
#endif
V_1 -> V_181 = 1 ;
}
V_5 = V_1 -> V_93 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_3 ( V_127 , V_95 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_97 & V_156 ) )
{
if ( V_1 -> V_8 -> V_9 . V_10 == 0 )
{
T_6 * V_157 ;
V_1 -> V_22 = V_23 ;
V_157 = F_27 ( V_1 ) ;
F_28 ( V_157 ) ;
F_29 ( V_157 ) ;
return ( - 1 ) ;
}
}
goto V_133;
}
switch ( V_31 -> type )
{
default:
#ifndef F_34
if ( V_1 -> V_36 == V_182 )
{
V_31 -> V_53 = 0 ;
goto V_133;
}
#endif
V_28 = V_135 ;
F_3 ( V_127 , V_183 ) ;
goto V_57;
case V_171 :
case V_143 :
case V_126 :
V_28 = V_135 ;
F_3 ( V_127 , V_20 ) ;
goto V_57;
case V_96 :
if ( V_1 -> V_8 -> V_184 &&
( V_1 -> V_8 -> V_185 != 0 ) &&
( (
( V_1 -> V_176 & V_180 ) &&
( V_1 -> V_176 >= V_186 ) &&
( V_1 -> V_176 <= V_187 )
) || (
( V_1 -> V_176 & V_179 ) &&
( V_1 -> V_176 <= V_188 ) &&
( V_1 -> V_176 >= V_189 )
)
) )
{
V_1 -> V_8 -> V_184 = 2 ;
return ( - 1 ) ;
}
else
{
V_28 = V_135 ;
F_3 ( V_127 , V_183 ) ;
goto V_57;
}
}
V_57:
F_11 ( V_1 , V_82 , V_28 ) ;
V_59:
return ( - 1 ) ;
}
int F_33 ( T_1 * V_1 )
{
int V_5 ;
const char * V_190 ;
int V_191 ;
if ( V_1 -> V_176 & V_179 )
V_5 = V_192 ;
else
V_5 = V_193 ;
if ( V_1 -> V_8 -> V_165 . V_194 == NULL )
{
V_1 -> V_43 -> V_148 = V_1 -> V_8 -> V_165 . V_174 ;
if ( ! V_1 -> V_67 -> V_68 -> V_195 ( V_1 ) ) return ( 0 ) ;
}
if ( ! V_1 -> V_67 -> V_68 -> V_196 ( V_1 , V_5 ) )
return ( 0 ) ;
if ( V_1 -> V_176 & V_180 )
{
V_190 = V_1 -> V_67 -> V_68 -> V_197 ;
V_191 = V_1 -> V_67 -> V_68 -> V_198 ;
}
else
{
V_190 = V_1 -> V_67 -> V_68 -> V_199 ;
V_191 = V_1 -> V_67 -> V_68 -> V_200 ;
}
V_1 -> V_8 -> V_165 . V_201 = V_1 -> V_67 -> V_68 -> V_202 ( V_1 ,
& ( V_1 -> V_8 -> V_203 ) ,
& ( V_1 -> V_8 -> V_204 ) ,
V_190 , V_191 , V_1 -> V_8 -> V_165 . V_205 ) ;
return ( 1 ) ;
}
void F_11 ( T_1 * V_1 , int V_206 , int V_207 )
{
V_207 = V_1 -> V_67 -> V_68 -> V_208 ( V_207 ) ;
if ( V_1 -> V_36 == V_209 && V_207 == V_56 )
V_207 = V_210 ;
if ( V_207 < 0 ) return;
if ( ( V_206 == 2 ) && ( V_1 -> V_43 != NULL ) )
F_32 ( V_1 -> V_161 , V_1 -> V_43 ) ;
V_1 -> V_8 -> V_105 = 1 ;
V_1 -> V_8 -> V_211 [ 0 ] = V_206 ;
V_1 -> V_8 -> V_211 [ 1 ] = V_207 ;
if ( V_1 -> V_8 -> V_104 . V_10 == 0 )
V_1 -> V_67 -> V_106 ( V_1 ) ;
}
int F_35 ( T_1 * V_1 )
{
int V_5 , V_123 ;
void (* F_22)( const T_1 * V_83 , int type , int V_125 ) = NULL ;
V_1 -> V_8 -> V_105 = 0 ;
V_5 = F_17 ( V_1 , V_143 , & V_1 -> V_8 -> V_211 [ 0 ] , 2 , 0 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_8 -> V_105 = 1 ;
}
else
{
if ( V_1 -> V_8 -> V_211 [ 0 ] == V_82 )
( void ) F_36 ( V_1 -> V_119 ) ;
if ( V_1 -> V_151 )
V_1 -> V_151 ( 1 , V_1 -> V_36 , V_143 , V_1 -> V_8 -> V_211 , 2 , V_1 , V_1 -> V_152 ) ;
if ( V_1 -> V_160 != NULL )
F_22 = V_1 -> V_160 ;
else if ( V_1 -> V_161 -> V_160 != NULL )
F_22 = V_1 -> V_161 -> V_160 ;
if ( F_22 != NULL )
{
V_123 = ( V_1 -> V_8 -> V_211 [ 0 ] << 8 ) | V_1 -> V_8 -> V_211 [ 1 ] ;
F_22 ( V_1 , V_212 , V_123 ) ;
}
}
return ( V_5 ) ;
}
