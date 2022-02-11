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
if ( V_1 -> V_29 & V_30 )
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
long V_8 = 0 ;
T_3 * V_91 ;
T_2 * V_108 = & ( V_1 -> V_11 -> V_109 ) ;
T_4 * V_38 ;
if ( V_108 -> V_13 == NULL )
if ( ! F_24 ( V_1 ) )
return - 1 ;
if ( V_108 -> V_7 != 0 )
return ( F_25 ( V_1 , type , V_13 , V_6 ) ) ;
if ( V_1 -> V_11 -> V_110 )
{
V_5 = V_1 -> V_72 -> V_111 ( V_1 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
}
if ( V_6 == 0 && ! V_105 )
return 0 ;
V_91 = & ( V_1 -> V_11 -> V_92 ) ;
V_38 = V_1 -> V_49 ;
if ( ( V_38 == NULL ) ||
( V_1 -> V_112 == NULL ) ||
( F_12 ( V_1 -> V_113 ) == NULL ) )
V_44 = 1 ;
if ( V_44 )
V_43 = 0 ;
else
{
V_43 = F_13 ( V_1 -> V_113 ) ;
if ( V_43 < 0 )
goto V_64;
}
if ( ! V_44 && ! V_105 && ! V_1 -> V_11 -> V_104 )
{
if ( V_1 -> V_11 -> V_114 && type == V_17 )
{
V_107 = F_23 ( V_1 , type , V_13 , 0 , 1 ) ;
if ( V_107 <= 0 )
goto V_64;
if ( V_107 >
( V_15 + V_115 ) )
{
F_5 ( V_116 , V_23 ) ;
goto V_64;
}
}
V_1 -> V_11 -> V_104 = 1 ;
}
if ( V_105 )
{
#if F_3 ( V_14 ) && V_14 != 0
V_8 = ( long ) V_108 -> V_13 + 2 * V_15 ;
V_8 = ( - V_8 ) & ( V_14 - 1 ) ;
#endif
V_39 = V_108 -> V_13 + V_8 ;
V_108 -> V_16 = V_8 ;
}
else if ( V_107 )
{
V_39 = V_108 -> V_13 + V_108 -> V_16 + V_107 ;
}
else
{
#if F_3 ( V_14 ) && V_14 != 0
V_8 = ( long ) V_108 -> V_13 + V_15 ;
V_8 = ( - V_8 ) & ( V_14 - 1 ) ;
#endif
V_39 = V_108 -> V_13 + V_8 ;
V_108 -> V_16 = V_8 ;
}
* ( V_39 ++ ) = type & 0xff ;
V_91 -> type = type ;
* ( V_39 ++ ) = ( V_1 -> V_42 >> 8 ) ;
* ( V_39 ++ ) = V_1 -> V_42 & 0xff ;
V_106 = V_39 ;
V_39 += 2 ;
V_91 -> V_71 = V_39 ;
V_91 -> V_58 = ( int ) V_6 ;
V_91 -> V_68 = ( unsigned char * ) V_13 ;
if ( V_1 -> V_93 != NULL )
{
if ( ! F_19 ( V_1 ) )
{
F_5 ( V_116 , V_117 ) ;
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
if ( V_1 -> V_72 -> V_73 -> V_47 ( V_1 , & ( V_39 [ V_91 -> V_58 ] ) , 1 ) < 0 )
goto V_64;
V_91 -> V_58 += V_43 ;
V_91 -> V_68 = V_39 ;
V_91 -> V_71 = V_39 ;
}
V_1 -> V_72 -> V_73 -> V_74 ( V_1 , 1 ) ;
F_26 ( V_91 -> V_58 , V_106 ) ;
V_91 -> type = type ;
V_91 -> V_58 += V_15 ;
if ( V_105 )
{
return V_91 -> V_58 ;
}
V_108 -> V_7 = V_107 + V_91 -> V_58 ;
V_1 -> V_11 -> V_118 = V_6 ;
V_1 -> V_11 -> V_119 = V_13 ;
V_1 -> V_11 -> V_120 = type ;
V_1 -> V_11 -> V_121 = V_6 ;
return F_25 ( V_1 , type , V_13 , V_6 ) ;
V_64:
return - 1 ;
}
int F_25 ( T_1 * V_1 , int type , const unsigned char * V_13 ,
unsigned int V_6 )
{
int V_5 ;
T_2 * V_108 = & ( V_1 -> V_11 -> V_109 ) ;
if ( ( V_1 -> V_11 -> V_118 > ( int ) V_6 )
|| ( ( V_1 -> V_11 -> V_119 != V_13 ) &&
! ( V_1 -> V_29 & V_122 ) )
|| ( V_1 -> V_11 -> V_120 != type ) )
{
F_5 ( V_123 , V_124 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_6 () ;
if ( V_1 -> V_125 != NULL )
{
V_1 -> V_26 = V_126 ;
V_5 = F_27 ( V_1 -> V_125 ,
( char * ) & ( V_108 -> V_13 [ V_108 -> V_16 ] ) ,
( unsigned int ) V_108 -> V_7 ) ;
}
else
{
F_5 ( V_123 , V_127 ) ;
V_5 = - 1 ;
}
if ( V_5 == V_108 -> V_7 )
{
V_108 -> V_7 = 0 ;
V_108 -> V_16 += V_5 ;
if ( V_1 -> V_29 & V_30 )
F_28 ( V_1 ) ;
V_1 -> V_26 = V_31 ;
return ( V_1 -> V_11 -> V_121 ) ;
}
else if ( V_5 <= 0 ) {
if ( V_1 -> V_42 == V_20 ||
V_1 -> V_42 == V_21 ) {
V_108 -> V_7 = 0 ;
}
return ( V_5 ) ;
}
V_108 -> V_16 += V_5 ;
V_108 -> V_7 -= V_5 ;
}
}
int F_29 ( T_1 * V_1 , int type , unsigned char * V_13 , int V_6 , int V_128 )
{
int V_34 , V_5 , V_129 , V_36 ;
unsigned int V_2 ;
T_3 * V_37 ;
void (* F_30)( const T_1 * V_89 , int V_130 , int V_131 ) = NULL ;
if ( V_1 -> V_11 -> V_12 . V_13 == NULL )
if ( ! F_2 ( V_1 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_17 ) && ( type != V_132 ) && type ) ||
( V_128 && ( type != V_17 ) ) )
{
F_5 ( V_133 , V_23 ) ;
return - 1 ;
}
if ( ( type == V_132 ) && ( V_1 -> V_11 -> V_134 > 0 ) )
{
unsigned char * V_135 = V_1 -> V_11 -> V_136 ;
unsigned char * V_137 = V_13 ;
unsigned int V_138 ;
V_2 = 0 ;
while ( ( V_6 > 0 ) && ( V_1 -> V_11 -> V_134 > 0 ) )
{
* V_137 ++ = * V_135 ++ ;
V_6 -- ; V_1 -> V_11 -> V_134 -- ;
V_2 ++ ;
}
for ( V_138 = 0 ; V_138 < V_1 -> V_11 -> V_134 ; V_138 ++ )
V_1 -> V_11 -> V_136 [ V_138 ] = * V_135 ++ ;
return V_2 ;
}
if ( ! V_1 -> V_98 && F_22 ( V_1 ) )
{
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_133 , V_101 ) ;
return ( - 1 ) ;
}
}
V_139:
V_1 -> V_26 = V_31 ;
V_37 = & ( V_1 -> V_11 -> V_48 ) ;
if ( ( V_37 -> V_58 == 0 ) || ( V_1 -> V_56 == V_57 ) )
{
V_36 = F_9 ( V_1 ) ;
if ( V_36 <= 0 ) return ( V_36 ) ;
}
if ( V_1 -> V_11 -> V_140
&& ( V_37 -> type != V_132 ) )
{
V_34 = V_141 ;
F_5 ( V_133 , V_142 ) ;
goto V_62;
}
if ( V_1 -> V_143 & V_144 )
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
V_34 = V_141 ;
F_5 ( V_133 , V_145 ) ;
goto V_62;
}
if ( V_6 <= 0 ) return ( V_6 ) ;
if ( ( unsigned int ) V_6 > V_37 -> V_58 )
V_2 = V_37 -> V_58 ;
else
V_2 = ( unsigned int ) V_6 ;
memcpy ( V_13 , & ( V_37 -> V_71 [ V_37 -> V_87 ] ) , V_2 ) ;
if ( ! V_128 )
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
unsigned int V_146 = 0 ;
unsigned char * V_147 = NULL ;
unsigned int * V_148 = NULL ;
if ( V_37 -> type == V_132 )
{
V_146 = sizeof V_1 -> V_11 -> V_136 ;
V_147 = V_1 -> V_11 -> V_136 ;
V_148 = & V_1 -> V_11 -> V_134 ;
}
else if ( V_37 -> type == V_149 )
{
V_146 = sizeof V_1 -> V_11 -> V_150 ;
V_147 = V_1 -> V_11 -> V_150 ;
V_148 = & V_1 -> V_11 -> V_151 ;
}
if ( V_146 > 0 )
{
V_2 = V_146 - * V_148 ;
if ( V_37 -> V_58 < V_2 )
V_2 = V_37 -> V_58 ;
while ( V_2 -- > 0 )
{
V_147 [ ( * V_148 ) ++ ] = V_37 -> V_71 [ V_37 -> V_87 ++ ] ;
V_37 -> V_58 -- ;
}
if ( * V_148 < V_146 )
goto V_139;
}
}
if ( ( ! V_1 -> V_152 ) &&
( V_1 -> V_11 -> V_134 >= 4 ) &&
( V_1 -> V_11 -> V_136 [ 0 ] == V_153 ) &&
( V_1 -> V_49 != NULL ) && ( V_1 -> V_49 -> V_154 != NULL ) )
{
V_1 -> V_11 -> V_134 = 0 ;
if ( ( V_1 -> V_11 -> V_136 [ 1 ] != 0 ) ||
( V_1 -> V_11 -> V_136 [ 2 ] != 0 ) ||
( V_1 -> V_11 -> V_136 [ 3 ] != 0 ) )
{
V_34 = V_155 ;
F_5 ( V_133 , V_156 ) ;
goto V_62;
}
if ( V_1 -> V_157 )
V_1 -> V_157 ( 0 , V_1 -> V_42 , V_132 , V_1 -> V_11 -> V_136 , 4 , V_1 , V_1 -> V_158 ) ;
if ( F_31 ( V_1 ) &&
! ( V_1 -> V_11 -> V_159 & V_160 ) &&
! V_1 -> V_11 -> V_161 )
{
F_32 ( V_1 ) ;
if ( F_33 ( V_1 ) )
{
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_133 , V_101 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_29 & V_162 ) )
{
if ( V_1 -> V_11 -> V_12 . V_7 == 0 )
{
T_6 * V_163 ;
V_1 -> V_26 = V_27 ;
V_163 = F_34 ( V_1 ) ;
F_35 ( V_163 ) ;
F_36 ( V_163 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_139;
}
if ( V_1 -> V_152 &&
F_31 ( V_1 ) &&
! V_1 -> V_11 -> V_164 &&
( V_1 -> V_42 > V_165 ) &&
( V_1 -> V_11 -> V_134 >= 4 ) &&
( V_1 -> V_11 -> V_136 [ 0 ] == V_166 ) &&
( V_1 -> V_49 != NULL ) && ( V_1 -> V_49 -> V_154 != NULL ) &&
! ( V_1 -> V_167 -> V_50 & V_168 ) )
{
V_37 -> V_58 = 0 ;
F_16 ( V_1 , V_169 , V_170 ) ;
goto V_139;
}
if ( V_1 -> V_11 -> V_151 >= 2 )
{
int V_171 = V_1 -> V_11 -> V_150 [ 0 ] ;
int V_172 = V_1 -> V_11 -> V_150 [ 1 ] ;
V_1 -> V_11 -> V_151 = 0 ;
if ( V_1 -> V_157 )
V_1 -> V_157 ( 0 , V_1 -> V_42 , V_149 , V_1 -> V_11 -> V_150 , 2 , V_1 , V_1 -> V_158 ) ;
if ( V_1 -> V_173 != NULL )
F_30 = V_1 -> V_173 ;
else if ( V_1 -> V_167 -> V_173 != NULL )
F_30 = V_1 -> V_167 -> V_173 ;
if ( F_30 != NULL )
{
V_129 = ( V_171 << 8 ) | V_172 ;
F_30 ( V_1 , V_174 , V_129 ) ;
}
if ( V_171 == 1 )
{
V_1 -> V_11 -> V_175 = V_172 ;
if ( V_172 == V_176 )
{
V_1 -> V_143 |= V_144 ;
return ( 0 ) ;
}
else if ( V_172 == V_170 )
{
V_34 = V_177 ;
F_5 ( V_133 , V_178 ) ;
goto V_62;
}
}
else if ( V_171 == 2 )
{
char V_179 [ 16 ] ;
V_1 -> V_26 = V_31 ;
V_1 -> V_11 -> V_180 = V_172 ;
F_5 ( V_133 , V_181 + V_172 ) ;
F_37 ( V_179 , sizeof V_179 , L_4 , V_172 ) ;
F_38 ( 2 , L_5 , V_179 ) ;
V_1 -> V_143 |= V_144 ;
F_39 ( V_1 -> V_167 , V_1 -> V_49 ) ;
return ( 0 ) ;
}
else
{
V_34 = V_182 ;
F_5 ( V_133 , V_183 ) ;
goto V_62;
}
goto V_139;
}
if ( V_1 -> V_143 & V_184 )
{
V_1 -> V_26 = V_31 ;
V_37 -> V_58 = 0 ;
return ( 0 ) ;
}
if ( V_37 -> type == V_185 )
{
if ( ( V_37 -> V_58 != 1 ) || ( V_37 -> V_87 != 0 ) ||
( V_37 -> V_71 [ 0 ] != V_186 ) )
{
V_34 = V_182 ;
F_5 ( V_133 , V_187 ) ;
goto V_62;
}
if ( V_1 -> V_11 -> V_179 . V_188 == NULL )
{
V_34 = V_141 ;
F_5 ( V_133 , V_189 ) ;
goto V_62;
}
V_37 -> V_58 = 0 ;
if ( V_1 -> V_157 )
V_1 -> V_157 ( 0 , V_1 -> V_42 , V_185 , V_37 -> V_71 , 1 , V_1 , V_1 -> V_158 ) ;
V_1 -> V_11 -> V_140 = 1 ;
if ( ! F_40 ( V_1 ) )
goto V_64;
else
goto V_139;
}
if ( ( V_1 -> V_11 -> V_134 >= 4 ) && ! V_1 -> V_98 )
{
if ( ( ( V_1 -> V_190 & V_191 ) == V_192 ) &&
! ( V_1 -> V_11 -> V_159 & V_160 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_1 -> V_190 = V_1 -> V_152 ? V_193 : V_194 ;
#endif
V_1 -> V_195 = 1 ;
}
V_5 = V_1 -> V_99 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_5 ( V_133 , V_101 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_29 & V_162 ) )
{
if ( V_1 -> V_11 -> V_12 . V_7 == 0 )
{
T_6 * V_163 ;
V_1 -> V_26 = V_27 ;
V_163 = F_34 ( V_1 ) ;
F_35 ( V_163 ) ;
F_36 ( V_163 ) ;
return ( - 1 ) ;
}
}
goto V_139;
}
switch ( V_37 -> type )
{
default:
#ifndef F_41
if ( V_1 -> V_42 == V_196 )
{
V_37 -> V_58 = 0 ;
goto V_139;
}
#endif
V_34 = V_141 ;
F_5 ( V_133 , V_197 ) ;
goto V_62;
case V_185 :
case V_149 :
case V_132 :
V_34 = V_141 ;
F_5 ( V_133 , V_23 ) ;
goto V_62;
case V_17 :
if ( V_1 -> V_11 -> V_198 &&
( V_1 -> V_11 -> V_199 != 0 ) &&
( (
( V_1 -> V_190 & V_194 ) &&
( V_1 -> V_190 >= V_200 ) &&
( V_1 -> V_190 <= V_201 )
) || (
( V_1 -> V_190 & V_193 ) &&
( V_1 -> V_190 <= V_202 ) &&
( V_1 -> V_190 >= V_203 )
)
) )
{
V_1 -> V_11 -> V_198 = 2 ;
return ( - 1 ) ;
}
else
{
V_34 = V_141 ;
F_5 ( V_133 , V_197 ) ;
goto V_62;
}
}
V_62:
F_16 ( V_1 , V_88 , V_34 ) ;
V_64:
return ( - 1 ) ;
}
int F_40 ( T_1 * V_1 )
{
int V_5 ;
const char * V_204 ;
int V_205 ;
if ( V_1 -> V_190 & V_193 )
V_5 = V_206 ;
else
V_5 = V_207 ;
if ( V_1 -> V_11 -> V_179 . V_208 == NULL )
{
if ( V_1 -> V_49 == NULL )
{
F_5 ( V_209 , V_189 ) ;
return ( 0 ) ;
}
V_1 -> V_49 -> V_154 = V_1 -> V_11 -> V_179 . V_188 ;
if ( ! V_1 -> V_72 -> V_73 -> V_210 ( V_1 ) ) return ( 0 ) ;
}
if ( ! V_1 -> V_72 -> V_73 -> V_211 ( V_1 , V_5 ) )
return ( 0 ) ;
if ( V_1 -> V_190 & V_194 )
{
V_204 = V_1 -> V_72 -> V_73 -> V_212 ;
V_205 = V_1 -> V_72 -> V_73 -> V_213 ;
}
else
{
V_204 = V_1 -> V_72 -> V_73 -> V_214 ;
V_205 = V_1 -> V_72 -> V_73 -> V_215 ;
}
V_1 -> V_11 -> V_179 . V_216 = V_1 -> V_72 -> V_73 -> V_217 ( V_1 ,
V_204 , V_205 , V_1 -> V_11 -> V_179 . V_218 ) ;
return ( 1 ) ;
}
int F_16 ( T_1 * V_1 , int V_219 , int V_220 )
{
V_220 = V_1 -> V_72 -> V_73 -> V_221 ( V_220 ) ;
if ( V_1 -> V_42 == V_165 && V_220 == V_61 )
V_220 = V_177 ;
if ( V_220 < 0 ) return - 1 ;
if ( ( V_219 == 2 ) && ( V_1 -> V_49 != NULL ) )
F_39 ( V_1 -> V_167 , V_1 -> V_49 ) ;
V_1 -> V_11 -> V_110 = 1 ;
V_1 -> V_11 -> V_222 [ 0 ] = V_219 ;
V_1 -> V_11 -> V_222 [ 1 ] = V_220 ;
if ( V_1 -> V_11 -> V_109 . V_7 == 0 )
return V_1 -> V_72 -> V_111 ( V_1 ) ;
return - 1 ;
}
int F_42 ( T_1 * V_1 )
{
int V_5 , V_129 ;
void (* F_30)( const T_1 * V_89 , int type , int V_131 ) = NULL ;
V_1 -> V_11 -> V_110 = 0 ;
V_5 = F_23 ( V_1 , V_149 , & V_1 -> V_11 -> V_222 [ 0 ] , 2 , 0 ) ;
if ( V_5 <= 0 )
{
V_1 -> V_11 -> V_110 = 1 ;
}
else
{
if ( V_1 -> V_11 -> V_222 [ 0 ] == V_88 )
( void ) F_43 ( V_1 -> V_125 ) ;
if ( V_1 -> V_157 )
V_1 -> V_157 ( 1 , V_1 -> V_42 , V_149 , V_1 -> V_11 -> V_222 , 2 , V_1 , V_1 -> V_158 ) ;
if ( V_1 -> V_173 != NULL )
F_30 = V_1 -> V_173 ;
else if ( V_1 -> V_167 -> V_173 != NULL )
F_30 = V_1 -> V_167 -> V_173 ;
if ( F_30 != NULL )
{
V_129 = ( V_1 -> V_11 -> V_222 [ 0 ] << 8 ) | V_1 -> V_11 -> V_222 [ 1 ] ;
F_30 ( V_1 , V_223 , V_129 ) ;
}
}
return ( V_5 ) ;
}
