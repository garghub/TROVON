int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
long V_8 = 0 ;
unsigned char * V_9 ;
T_2 * V_10 ;
if ( V_2 <= 0 ) return V_2 ;
V_10 = & ( V_1 -> V_11 -> V_12 ) ;
if ( V_10 -> V_13 == NULL )
if ( ! F_2 ( V_1 ) )
return - 1 ;
V_7 = V_10 -> V_7 ;
#if F_3 ( V_14 ) && V_14 != 0
V_8 = ( long ) V_10 -> V_13 + V_15 ;
V_8 = ( - V_8 ) & ( V_14 - 1 ) ;
#endif
if ( ! V_4 )
{
if ( V_7 == 0 )
V_10 -> V_16 = V_8 ;
else if ( V_8 != 0 && V_7 >= V_15 )
{
V_9 = V_10 -> V_13 + V_10 -> V_16 ;
if ( V_9 [ 0 ] == V_17
&& ( V_9 [ 3 ] << 8 | V_9 [ 4 ] ) >= 128 )
{
memmove ( V_10 -> V_13 + V_8 , V_9 , V_7 ) ;
V_10 -> V_16 = V_8 ;
}
}
V_1 -> V_18 = V_10 -> V_13 + V_10 -> V_16 ;
V_1 -> V_19 = 0 ;
}
if ( F_4 ( V_1 ) == V_20 || F_4 ( V_1 ) == V_21 )
{
if ( V_7 > 0 && V_2 > V_7 )
V_2 = V_7 ;
}
if ( V_7 >= V_2 )
{
V_1 -> V_19 += V_2 ;
V_10 -> V_7 = V_7 - V_2 ;
V_10 -> V_16 += V_2 ;
return ( V_2 ) ;
}
V_6 = V_1 -> V_19 ;
V_9 = V_10 -> V_13 + V_8 ;
if ( V_1 -> V_18 != V_9 )
{
memmove ( V_9 , V_1 -> V_18 , V_6 + V_7 ) ;
V_1 -> V_18 = V_9 ;
V_10 -> V_16 = V_6 + V_8 ;
}
if ( V_2 > ( int ) ( V_10 -> V_6 - V_10 -> V_16 ) )
{
F_5 ( V_22 , V_23 ) ;
return - 1 ;
}
if ( ! V_1 -> V_24 )
V_3 = V_2 ;
else
{
if ( V_3 < V_2 )
V_3 = V_2 ;
if ( V_3 > ( int ) ( V_10 -> V_6 - V_10 -> V_16 ) )
V_3 = V_10 -> V_6 - V_10 -> V_16 ;
}
while ( V_7 < V_2 )
{
F_6 () ;
if ( V_1 -> V_25 != NULL )
{
V_1 -> V_26 = V_27 ;
V_5 = F_7 ( V_1 -> V_25 , V_9 + V_6 + V_7 , V_3 - V_7 ) ;
}
else
{
F_5 ( V_22 , V_28 ) ;
V_5 = - 1 ;
}
if ( V_5 <= 0 )
{
V_10 -> V_7 = V_7 ;
if ( V_1 -> V_29 & V_30 &&
F_4 ( V_1 ) != V_20 && F_4 ( V_1 ) != V_21 )
if ( V_6 + V_7 == 0 )
F_8 ( V_1 ) ;
return ( V_5 ) ;
}
V_7 += V_5 ;
if ( F_4 ( V_1 ) == V_20 || F_4 ( V_1 ) == V_21 )
{
if ( V_2 > V_7 )
V_2 = V_7 ;
}
}
V_10 -> V_16 += V_2 ;
V_10 -> V_7 = V_7 - V_2 ;
V_1 -> V_19 += V_2 ;
V_1 -> V_26 = V_31 ;
return ( V_2 ) ;
}
static int F_9 ( T_1 * V_1 )
{
int V_32 , V_33 , V_34 ;
int V_35 , V_2 , V_5 , V_36 = - 1 ;
T_3 * V_37 ;
T_4 * V_38 ;
unsigned char * V_39 ;
unsigned char V_40 [ V_41 ] ;
short V_42 ;
int V_43 ;
int V_44 = 0 ;
T_5 V_45 ;
int V_46 = 0 ;
unsigned char * V_47 = NULL ;
V_37 = & ( V_1 -> V_11 -> V_48 ) ;
V_38 = V_1 -> V_49 ;
if ( V_1 -> V_50 & V_51 )
V_45 = V_52 ;
else
V_45 = 0 ;
if ( V_45 && ! V_1 -> V_11 -> V_53 )
{
F_5 ( V_54 , V_23 ) ;
return - 1 ;
}
V_55:
if ( ( V_1 -> V_56 != V_57 ) ||
( V_1 -> V_19 < V_15 ) )
{
V_2 = F_1 ( V_1 , V_15 , V_1 -> V_11 -> V_12 . V_6 , 0 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
V_1 -> V_56 = V_57 ;
V_39 = V_1 -> V_18 ;
V_37 -> type = * ( V_39 ++ ) ;
V_32 = * ( V_39 ++ ) ;
V_33 = * ( V_39 ++ ) ;
V_42 = ( V_32 << 8 ) | V_33 ;
F_10 ( V_39 , V_37 -> V_58 ) ;
#if 0
fprintf(stderr, "Record type=%d, Length=%d\n", rr->type, rr->length);
#endif
if ( ! V_1 -> V_59 )
{
if ( V_42 != V_1 -> V_42 )
{
F_5 ( V_54 , V_60 ) ;
if ( ( V_1 -> V_42 & 0xFF00 ) == ( V_42 & 0xFF00 ) )
V_1 -> V_42 = ( unsigned short ) V_42 ;
V_34 = V_61 ;
goto V_62;
}
}
if ( ( V_42 >> 8 ) != V_63 )
{
F_5 ( V_54 , V_60 ) ;
goto V_64;
}
if ( V_37 -> V_58 > V_1 -> V_11 -> V_12 . V_6 - V_15 )
{
V_34 = V_65 ;
F_5 ( V_54 , V_66 ) ;
goto V_62;
}
}
if ( V_37 -> V_58 > V_1 -> V_19 - V_15 )
{
V_5 = V_37 -> V_58 ;
V_2 = F_1 ( V_1 , V_5 , V_5 , 1 ) ;
if ( V_2 <= 0 ) return ( V_2 ) ;
}
V_1 -> V_56 = V_67 ;
V_37 -> V_68 = & ( V_1 -> V_18 [ V_15 ] ) ;
if ( V_37 -> V_58 > V_69 + V_45 )
{
V_34 = V_65 ;
F_5 ( V_54 , V_70 ) ;
goto V_62;
}
V_37 -> V_71 = V_37 -> V_68 ;
V_35 = V_1 -> V_72 -> V_73 -> V_74 ( V_1 , 0 ) ;
if ( V_35 <= 0 )
{
if ( V_35 == 0 )
goto V_64;
V_46 = 1 ;
}
#ifdef F_11
printf ( L_1 , V_37 -> V_58 ) ;
{ unsigned int V_75 ; for ( V_75 = 0 ; V_75 < V_37 -> V_58 ; V_75 ++ ) printf ( L_2 , V_37 -> V_71 [ V_75 ] , ( ( V_75 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_38 == NULL ) ||
( V_1 -> V_76 == NULL ) ||
( F_12 ( V_1 -> V_77 ) == NULL ) )
V_44 = 1 ;
if ( ! V_44 )
{
V_43 = F_13 ( V_1 -> V_77 ) ;
F_14 ( V_43 >= 0 ) ;
if ( V_37 -> V_58 > V_78 + V_45 + V_43 )
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
V_46 = 1 ;
#endif
}
if ( V_37 -> V_58 >= ( unsigned int ) V_43 )
{
V_37 -> V_58 -= V_43 ;
V_47 = & V_37 -> V_71 [ V_37 -> V_58 ] ;
}
else
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
V_46 = 1 ;
V_37 -> V_58 = 0 ;
#endif
}
V_5 = V_1 -> V_72 -> V_73 -> V_47 ( V_1 , V_40 , 0 ) ;
if ( V_5 < 0 || V_47 == NULL || memcmp ( V_40 , V_47 , ( T_5 ) V_43 ) != 0 )
{
V_46 = 1 ;
}
}
if ( V_46 )
{
V_34 = V_79 ;
F_5 ( V_54 , V_80 ) ;
goto V_62;
}
if ( V_1 -> V_81 != NULL )
{
if ( V_37 -> V_58 > V_78 + V_45 )
{
V_34 = V_65 ;
F_5 ( V_54 , V_82 ) ;
goto V_62;
}
if ( ! F_15 ( V_1 ) )
{
V_34 = V_83 ;
F_5 ( V_54 , V_84 ) ;
goto V_62;
}
}
if ( V_37 -> V_58 > V_85 + V_45 )
{
V_34 = V_65 ;
F_5 ( V_54 , V_86 ) ;
goto V_62;
}
V_37 -> V_87 = 0 ;
V_1 -> V_19 = 0 ;
if ( V_37 -> V_58 == 0 ) goto V_55;
#if 0
fprintf(stderr, "Ultimate Record type=%d, Length=%d\n", rr->type, rr->length);
#endif
return ( 1 ) ;
V_62:
F_16 ( V_1 , V_88 , V_34 ) ;
V_64:
return ( V_36 ) ;
}
int F_15 ( T_1 * V_89 )
{
#ifndef F_17
int V_5 ;
T_3 * V_37 ;
V_37 = & ( V_89 -> V_11 -> V_48 ) ;
V_5 = F_18 ( V_89 -> V_81 , V_37 -> V_90 ,
V_85 , V_37 -> V_71 , ( int ) V_37 -> V_58 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_37 -> V_58 = V_5 ;
V_37 -> V_71 = V_37 -> V_90 ;
#endif
return ( 1 ) ;
}
int F_19 ( T_1 * V_89 )
{
#ifndef F_17
int V_5 ;
T_3 * V_91 ;
V_91 = & ( V_89 -> V_11 -> V_92 ) ;
V_5 = F_20 ( V_89 -> V_93 , V_91 -> V_71 ,
V_78 ,
V_91 -> V_68 , ( int ) V_91 -> V_58 ) ;
if ( V_5 < 0 )
return ( 0 ) ;
else
V_91 -> V_58 = V_5 ;
V_91 -> V_68 = V_91 -> V_71 ;
#endif
return ( 1 ) ;
}
int F_21 ( T_1 * V_1 , int type , const void * V_94 , int V_6 )
{
const unsigned char * V_13 = V_94 ;
unsigned int V_95 , V_2 , V_96 ;
int V_5 ;
V_1 -> V_26 = V_31 ;
V_95 = V_1 -> V_11 -> V_97 ;
V_1 -> V_11 -> V_97 = 0 ;
if ( F_22 ( V_1 ) && ! V_1 -> V_98 )
{
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_100 , V_101 ) ;
return - 1 ;
}
}
V_2 = ( V_6 - V_95 ) ;
for (; ; )
{
if ( V_2 > V_1 -> V_102 )
V_96 = V_1 -> V_102 ;
else
V_96 = V_2 ;
V_5 = F_23 ( V_1 , type , & ( V_13 [ V_95 ] ) , V_96 , 0 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_11 -> V_97 = V_95 ;
return V_5 ;
}
if ( ( V_5 == ( int ) V_2 ) ||
( type == V_17 &&
( V_1 -> V_29 & V_103 ) ) )
{
V_1 -> V_11 -> V_104 = 0 ;
return V_95 + V_5 ;
}
V_2 -= V_5 ;
V_95 += V_5 ;
}
}
static int F_23 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_6 , int V_105 )
{
unsigned char * V_39 , * V_106 ;
int V_5 , V_43 , V_44 = 0 ;
int V_107 = 0 ;
int V_108 ;
long V_8 = 0 ;
T_3 * V_91 ;
T_2 * V_109 = & ( V_1 -> V_11 -> V_110 ) ;
T_4 * V_38 ;
if ( V_109 -> V_13 == NULL )
if ( ! F_24 ( V_1 ) )
return - 1 ;
if ( V_109 -> V_7 != 0 )
return ( F_25 ( V_1 , type , V_13 , V_6 ) ) ;
if ( V_1 -> V_11 -> V_111 )
{
V_5 = V_1 -> V_72 -> V_112 ( V_1 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
}
if ( V_6 == 0 && ! V_105 )
return 0 ;
V_91 = & ( V_1 -> V_11 -> V_92 ) ;
V_38 = V_1 -> V_49 ;
if ( ( V_38 == NULL ) ||
( V_1 -> V_113 == NULL ) ||
( F_12 ( V_1 -> V_114 ) == NULL ) )
V_44 = 1 ;
if ( V_44 )
V_43 = 0 ;
else
{
V_43 = F_13 ( V_1 -> V_114 ) ;
if ( V_43 < 0 )
goto V_64;
}
if ( ! V_44 && ! V_105 && ! V_1 -> V_11 -> V_104 )
{
if ( V_1 -> V_11 -> V_115 && type == V_17 )
{
V_107 = F_23 ( V_1 , type , V_13 , 0 , 1 ) ;
if ( V_107 <= 0 )
goto V_64;
if ( V_107 >
( V_15 + V_116 ) )
{
F_5 ( V_117 , V_23 ) ;
goto V_64;
}
}
V_1 -> V_11 -> V_104 = 1 ;
}
if ( V_105 )
{
#if F_3 ( V_14 ) && V_14 != 0
V_8 = ( long ) V_109 -> V_13 + 2 * V_15 ;
V_8 = ( - V_8 ) & ( V_14 - 1 ) ;
#endif
V_39 = V_109 -> V_13 + V_8 ;
V_109 -> V_16 = V_8 ;
}
else if ( V_107 )
{
V_39 = V_109 -> V_13 + V_109 -> V_16 + V_107 ;
}
else
{
#if F_3 ( V_14 ) && V_14 != 0
V_8 = ( long ) V_109 -> V_13 + V_15 ;
V_8 = ( - V_8 ) & ( V_14 - 1 ) ;
#endif
V_39 = V_109 -> V_13 + V_8 ;
V_109 -> V_16 = V_8 ;
}
* ( V_39 ++ ) = type & 0xff ;
V_91 -> type = type ;
* ( V_39 ++ ) = ( V_1 -> V_42 >> 8 ) ;
* ( V_39 ++ ) = V_1 -> V_42 & 0xff ;
V_106 = V_39 ;
V_39 += 2 ;
if ( V_1 -> V_113 && V_1 -> V_42 >= V_118 )
{
int V_29 = F_26 ( V_1 -> V_113 ) ;
if ( V_29 == V_119 )
{
V_108 = F_27 ( V_1 -> V_113 ) ;
if ( V_108 <= 1 )
V_108 = 0 ;
}
else if ( V_29 == V_120 )
V_108 = V_121 ;
else
V_108 = 0 ;
}
else
V_108 = 0 ;
V_91 -> V_71 = V_39 + V_108 ;
V_91 -> V_58 = ( int ) V_6 ;
V_91 -> V_68 = ( unsigned char * ) V_13 ;
if ( V_1 -> V_93 != NULL )
{
if ( ! F_19 ( V_1 ) )
{
F_5 ( V_117 , V_122 ) ;
goto V_64;
}
}
else
{
memcpy ( V_91 -> V_71 , V_91 -> V_68 , V_91 -> V_58 ) ;
V_91 -> V_68 = V_91 -> V_71 ;
}
if ( V_43 != 0 )
{
if ( V_1 -> V_72 -> V_73 -> V_47 ( V_1 , & ( V_39 [ V_91 -> V_58 + V_108 ] ) , 1 ) < 0 )
goto V_64;
V_91 -> V_58 += V_43 ;
}
V_91 -> V_68 = V_39 ;
V_91 -> V_71 = V_39 ;
if ( V_108 )
{
V_91 -> V_58 += V_108 ;
}
V_1 -> V_72 -> V_73 -> V_74 ( V_1 , 1 ) ;
F_28 ( V_91 -> V_58 , V_106 ) ;
V_91 -> type = type ;
V_91 -> V_58 += V_15 ;
if ( V_105 )
{
return V_91 -> V_58 ;
}
V_109 -> V_7 = V_107 + V_91 -> V_58 ;
V_1 -> V_11 -> V_123 = V_6 ;
V_1 -> V_11 -> V_124 = V_13 ;
V_1 -> V_11 -> V_125 = type ;
V_1 -> V_11 -> V_126 = V_6 ;
return F_25 ( V_1 , type , V_13 , V_6 ) ;
V_64:
return - 1 ;
}
int F_25 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_6 )
{
int V_5 ;
T_2 * V_109 = & ( V_1 -> V_11 -> V_110 ) ;
if ( ( V_1 -> V_11 -> V_123 > ( int ) V_6 )
|| ( ( V_1 -> V_11 -> V_124 != V_13 ) &&
! ( V_1 -> V_29 & V_127 ) )
|| ( V_1 -> V_11 -> V_125 != type ) )
{
F_5 ( V_128 , V_129 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_6 () ;
if ( V_1 -> V_130 != NULL )
{
V_1 -> V_26 = V_131 ;
V_5 = F_29 ( V_1 -> V_130 ,
( char * ) & ( V_109 -> V_13 [ V_109 -> V_16 ] ) ,
( unsigned int ) V_109 -> V_7 ) ;
}
else
{
F_5 ( V_128 , V_132 ) ;
V_5 = - 1 ;
}
if ( V_5 == V_109 -> V_7 )
{
V_109 -> V_7 = 0 ;
V_109 -> V_16 += V_5 ;
if ( V_1 -> V_29 & V_30 &&
F_4 ( V_1 ) != V_20 && F_4 ( V_1 ) != V_21 )
F_30 ( V_1 ) ;
V_1 -> V_26 = V_31 ;
return ( V_1 -> V_11 -> V_126 ) ;
}
else if ( V_5 <= 0 ) {
if ( V_1 -> V_42 == V_20 ||
V_1 -> V_42 == V_21 ) {
V_109 -> V_7 = 0 ;
}
return ( V_5 ) ;
}
V_109 -> V_16 += V_5 ;
V_109 -> V_7 -= V_5 ;
}
}
int F_31 ( T_1 * V_1 , int type , unsigned char * V_13 , int V_6 , int V_133 )
{
int V_34 , V_5 , V_134 , V_36 ;
unsigned int V_2 ;
T_3 * V_37 ;
void (* F_32)( const T_1 * V_89 , int V_135 , int V_136 ) = NULL ;
if ( V_1 -> V_11 -> V_12 . V_13 == NULL )
if ( ! F_2 ( V_1 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_17 ) && ( type != V_137 ) && type ) ||
( V_133 && ( type != V_17 ) ) )
{
F_5 ( V_138 , V_23 ) ;
return - 1 ;
}
if ( ( type == V_137 ) && ( V_1 -> V_11 -> V_139 > 0 ) )
{
unsigned char * V_140 = V_1 -> V_11 -> V_141 ;
unsigned char * V_142 = V_13 ;
unsigned int V_143 ;
V_2 = 0 ;
while ( ( V_6 > 0 ) && ( V_1 -> V_11 -> V_139 > 0 ) )
{
* V_142 ++ = * V_140 ++ ;
V_6 -- ; V_1 -> V_11 -> V_139 -- ;
V_2 ++ ;
}
for ( V_143 = 0 ; V_143 < V_1 -> V_11 -> V_139 ; V_143 ++ )
V_1 -> V_11 -> V_141 [ V_143 ] = * V_140 ++ ;
return V_2 ;
}
if ( ! V_1 -> V_98 && F_22 ( V_1 ) )
{
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_138 , V_101 ) ;
return ( - 1 ) ;
}
}
V_144:
V_1 -> V_26 = V_31 ;
V_37 = & ( V_1 -> V_11 -> V_48 ) ;
if ( ( V_37 -> V_58 == 0 ) || ( V_1 -> V_56 == V_57 ) )
{
V_36 = F_9 ( V_1 ) ;
if ( V_36 <= 0 ) return ( V_36 ) ;
}
if ( V_1 -> V_11 -> V_145
&& ( V_37 -> type != V_137 ) )
{
V_34 = V_146 ;
F_5 ( V_138 , V_147 ) ;
goto V_62;
}
if ( V_1 -> V_148 & V_149 )
{
V_37 -> V_58 = 0 ;
V_1 -> V_26 = V_31 ;
return ( 0 ) ;
}
if ( type == V_37 -> type )
{
if ( F_22 ( V_1 ) && ( type == V_17 ) &&
( V_1 -> V_76 == NULL ) )
{
V_34 = V_146 ;
F_5 ( V_138 , V_150 ) ;
goto V_62;
}
if ( V_6 <= 0 ) return ( V_6 ) ;
if ( ( unsigned int ) V_6 > V_37 -> V_58 )
V_2 = V_37 -> V_58 ;
else
V_2 = ( unsigned int ) V_6 ;
memcpy ( V_13 , & ( V_37 -> V_71 [ V_37 -> V_87 ] ) , V_2 ) ;
if ( ! V_133 )
{
V_37 -> V_58 -= V_2 ;
V_37 -> V_87 += V_2 ;
if ( V_37 -> V_58 == 0 )
{
V_1 -> V_56 = V_67 ;
V_37 -> V_87 = 0 ;
if ( V_1 -> V_29 & V_30 )
F_8 ( V_1 ) ;
}
}
return ( V_2 ) ;
}
{
unsigned int V_151 = 0 ;
unsigned char * V_152 = NULL ;
unsigned int * V_153 = NULL ;
if ( V_37 -> type == V_137 )
{
V_151 = sizeof V_1 -> V_11 -> V_141 ;
V_152 = V_1 -> V_11 -> V_141 ;
V_153 = & V_1 -> V_11 -> V_139 ;
}
else if ( V_37 -> type == V_154 )
{
V_151 = sizeof V_1 -> V_11 -> V_155 ;
V_152 = V_1 -> V_11 -> V_155 ;
V_153 = & V_1 -> V_11 -> V_156 ;
}
#ifndef F_33
else if ( V_37 -> type == V_157 )
{
F_34 ( V_1 ) ;
V_37 -> V_58 = 0 ;
V_1 -> V_26 = V_27 ;
F_35 ( F_36 ( V_1 ) ) ;
F_37 ( F_36 ( V_1 ) ) ;
return ( - 1 ) ;
}
#endif
if ( V_151 > 0 )
{
V_2 = V_151 - * V_153 ;
if ( V_37 -> V_58 < V_2 )
V_2 = V_37 -> V_58 ;
while ( V_2 -- > 0 )
{
V_152 [ ( * V_153 ) ++ ] = V_37 -> V_71 [ V_37 -> V_87 ++ ] ;
V_37 -> V_58 -- ;
}
if ( * V_153 < V_151 )
goto V_144;
}
}
if ( ( ! V_1 -> V_158 ) &&
( V_1 -> V_11 -> V_139 >= 4 ) &&
( V_1 -> V_11 -> V_141 [ 0 ] == V_159 ) &&
( V_1 -> V_49 != NULL ) && ( V_1 -> V_49 -> V_160 != NULL ) )
{
V_1 -> V_11 -> V_139 = 0 ;
if ( ( V_1 -> V_11 -> V_141 [ 1 ] != 0 ) ||
( V_1 -> V_11 -> V_141 [ 2 ] != 0 ) ||
( V_1 -> V_11 -> V_141 [ 3 ] != 0 ) )
{
V_34 = V_161 ;
F_5 ( V_138 , V_162 ) ;
goto V_62;
}
if ( V_1 -> V_163 )
V_1 -> V_163 ( 0 , V_1 -> V_42 , V_137 , V_1 -> V_11 -> V_141 , 4 , V_1 , V_1 -> V_164 ) ;
if ( F_38 ( V_1 ) &&
! ( V_1 -> V_11 -> V_165 & V_166 ) &&
! V_1 -> V_11 -> V_167 )
{
F_39 ( V_1 ) ;
if ( F_40 ( V_1 ) )
{
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_138 , V_101 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_29 & V_168 ) )
{
if ( V_1 -> V_11 -> V_12 . V_7 == 0 )
{
T_6 * V_169 ;
V_1 -> V_26 = V_27 ;
V_169 = F_36 ( V_1 ) ;
F_35 ( V_169 ) ;
F_37 ( V_169 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_144;
}
if ( V_1 -> V_158 &&
F_38 ( V_1 ) &&
! V_1 -> V_11 -> V_170 &&
( V_1 -> V_42 > V_171 ) &&
( V_1 -> V_11 -> V_139 >= 4 ) &&
( V_1 -> V_11 -> V_141 [ 0 ] == V_172 ) &&
( V_1 -> V_49 != NULL ) && ( V_1 -> V_49 -> V_160 != NULL ) &&
! ( V_1 -> V_173 -> V_50 & V_174 ) )
{
V_37 -> V_58 = 0 ;
F_16 ( V_1 , V_175 , V_176 ) ;
goto V_144;
}
if ( V_1 -> V_11 -> V_156 >= 2 )
{
int V_177 = V_1 -> V_11 -> V_155 [ 0 ] ;
int V_178 = V_1 -> V_11 -> V_155 [ 1 ] ;
V_1 -> V_11 -> V_156 = 0 ;
if ( V_1 -> V_163 )
V_1 -> V_163 ( 0 , V_1 -> V_42 , V_154 , V_1 -> V_11 -> V_155 , 2 , V_1 , V_1 -> V_164 ) ;
if ( V_1 -> V_179 != NULL )
F_32 = V_1 -> V_179 ;
else if ( V_1 -> V_173 -> V_179 != NULL )
F_32 = V_1 -> V_173 -> V_179 ;
if ( F_32 != NULL )
{
V_134 = ( V_177 << 8 ) | V_178 ;
F_32 ( V_1 , V_180 , V_134 ) ;
}
if ( V_177 == 1 )
{
V_1 -> V_11 -> V_181 = V_178 ;
if ( V_178 == V_182 )
{
V_1 -> V_148 |= V_149 ;
return ( 0 ) ;
}
else if ( V_178 == V_176 )
{
V_34 = V_183 ;
F_5 ( V_138 , V_184 ) ;
goto V_62;
}
#ifdef F_41
if ( V_178 == F_41 )
return ( 0 ) ;
#endif
}
else if ( V_177 == 2 )
{
char V_185 [ 16 ] ;
V_1 -> V_26 = V_31 ;
V_1 -> V_11 -> V_186 = V_178 ;
F_5 ( V_138 , V_187 + V_178 ) ;
F_42 ( V_185 , sizeof V_185 , L_4 , V_178 ) ;
F_43 ( 2 , L_5 , V_185 ) ;
V_1 -> V_148 |= V_149 ;
F_44 ( V_1 -> V_173 , V_1 -> V_49 ) ;
return ( 0 ) ;
}
else
{
V_34 = V_188 ;
F_5 ( V_138 , V_189 ) ;
goto V_62;
}
goto V_144;
}
if ( V_1 -> V_148 & V_190 )
{
V_1 -> V_26 = V_31 ;
V_37 -> V_58 = 0 ;
return ( 0 ) ;
}
if ( V_37 -> type == V_191 )
{
if ( ( V_37 -> V_58 != 1 ) || ( V_37 -> V_87 != 0 ) ||
( V_37 -> V_71 [ 0 ] != V_192 ) )
{
V_34 = V_188 ;
F_5 ( V_138 , V_193 ) ;
goto V_62;
}
if ( V_1 -> V_11 -> V_185 . V_194 == NULL )
{
V_34 = V_146 ;
F_5 ( V_138 , V_195 ) ;
goto V_62;
}
V_37 -> V_58 = 0 ;
if ( V_1 -> V_163 )
V_1 -> V_163 ( 0 , V_1 -> V_42 , V_191 , V_37 -> V_71 , 1 , V_1 , V_1 -> V_164 ) ;
V_1 -> V_11 -> V_145 = 1 ;
if ( ! F_45 ( V_1 ) )
goto V_64;
else
goto V_144;
}
if ( ( V_1 -> V_11 -> V_139 >= 4 ) && ! V_1 -> V_98 )
{
if ( ( ( V_1 -> V_196 & V_197 ) == V_198 ) &&
! ( V_1 -> V_11 -> V_165 & V_166 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_1 -> V_196 = V_1 -> V_158 ? V_199 : V_200 ;
#endif
V_1 -> V_167 = 1 ;
V_1 -> V_201 = 1 ;
}
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_138 , V_101 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_29 & V_168 ) )
{
if ( V_1 -> V_11 -> V_12 . V_7 == 0 )
{
T_6 * V_169 ;
V_1 -> V_26 = V_27 ;
V_169 = F_36 ( V_1 ) ;
F_35 ( V_169 ) ;
F_37 ( V_169 ) ;
return ( - 1 ) ;
}
}
goto V_144;
}
switch ( V_37 -> type )
{
default:
#ifndef F_46
if ( V_1 -> V_42 >= V_202 && V_1 -> V_42 <= V_118 )
{
V_37 -> V_58 = 0 ;
goto V_144;
}
#endif
V_34 = V_146 ;
F_5 ( V_138 , V_203 ) ;
goto V_62;
case V_191 :
case V_154 :
case V_137 :
V_34 = V_146 ;
F_5 ( V_138 , V_23 ) ;
goto V_62;
case V_17 :
if ( V_1 -> V_11 -> V_204 &&
( V_1 -> V_11 -> V_205 != 0 ) &&
( (
( V_1 -> V_196 & V_200 ) &&
( V_1 -> V_196 >= V_206 ) &&
( V_1 -> V_196 <= V_207 )
) || (
( V_1 -> V_196 & V_199 ) &&
( V_1 -> V_196 <= V_208 ) &&
( V_1 -> V_196 >= V_209 )
)
) )
{
V_1 -> V_11 -> V_204 = 2 ;
return ( - 1 ) ;
}
else
{
V_34 = V_146 ;
F_5 ( V_138 , V_203 ) ;
goto V_62;
}
}
V_62:
F_16 ( V_1 , V_88 , V_34 ) ;
V_64:
return ( - 1 ) ;
}
int F_45 ( T_1 * V_1 )
{
int V_5 ;
const char * V_210 ;
int V_211 ;
if ( V_1 -> V_196 & V_199 )
V_5 = V_212 ;
else
V_5 = V_213 ;
if ( V_1 -> V_11 -> V_185 . V_214 == NULL )
{
if ( V_1 -> V_49 == NULL )
{
F_5 ( V_215 , V_195 ) ;
return ( 0 ) ;
}
V_1 -> V_49 -> V_160 = V_1 -> V_11 -> V_185 . V_194 ;
if ( ! V_1 -> V_72 -> V_73 -> V_216 ( V_1 ) ) return ( 0 ) ;
}
if ( ! V_1 -> V_72 -> V_73 -> V_217 ( V_1 , V_5 ) )
return ( 0 ) ;
if ( V_1 -> V_196 & V_200 )
{
V_210 = V_1 -> V_72 -> V_73 -> V_218 ;
V_211 = V_1 -> V_72 -> V_73 -> V_219 ;
}
else
{
V_210 = V_1 -> V_72 -> V_73 -> V_220 ;
V_211 = V_1 -> V_72 -> V_73 -> V_221 ;
}
V_1 -> V_11 -> V_185 . V_222 = V_1 -> V_72 -> V_73 -> V_223 ( V_1 ,
V_210 , V_211 , V_1 -> V_11 -> V_185 . V_224 ) ;
return ( 1 ) ;
}
int F_16 ( T_1 * V_1 , int V_225 , int V_226 )
{
V_226 = V_1 -> V_72 -> V_73 -> V_227 ( V_226 ) ;
if ( V_1 -> V_42 == V_171 && V_226 == V_61 )
V_226 = V_183 ;
if ( V_226 < 0 ) return - 1 ;
if ( ( V_225 == 2 ) && ( V_1 -> V_49 != NULL ) )
F_44 ( V_1 -> V_173 , V_1 -> V_49 ) ;
V_1 -> V_11 -> V_111 = 1 ;
V_1 -> V_11 -> V_228 [ 0 ] = V_225 ;
V_1 -> V_11 -> V_228 [ 1 ] = V_226 ;
if ( V_1 -> V_11 -> V_110 . V_7 == 0 )
return V_1 -> V_72 -> V_112 ( V_1 ) ;
return - 1 ;
}
int F_47 ( T_1 * V_1 )
{
int V_5 , V_134 ;
void (* F_32)( const T_1 * V_89 , int type , int V_136 ) = NULL ;
V_1 -> V_11 -> V_111 = 0 ;
V_5 = F_23 ( V_1 , V_154 , & V_1 -> V_11 -> V_228 [ 0 ] , 2 , 0 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_11 -> V_111 = 1 ;
}
else
{
if ( V_1 -> V_11 -> V_228 [ 0 ] == V_88 )
( void ) F_48 ( V_1 -> V_130 ) ;
if ( V_1 -> V_163 )
V_1 -> V_163 ( 1 , V_1 -> V_42 , V_154 , V_1 -> V_11 -> V_228 , 2 , V_1 , V_1 -> V_164 ) ;
if ( V_1 -> V_179 != NULL )
F_32 = V_1 -> V_179 ;
else if ( V_1 -> V_173 -> V_179 != NULL )
F_32 = V_1 -> V_173 -> V_179 ;
if ( F_32 != NULL )
{
V_134 = ( V_1 -> V_11 -> V_228 [ 0 ] << 8 ) | V_1 -> V_11 -> V_228 [ 1 ] ;
F_32 ( V_1 , V_229 , V_134 ) ;
}
}
return ( V_5 ) ;
}
