static int
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) V_2 -> V_4 ;
if ( V_1 -> V_5 -> V_6 . V_7 != NULL )
F_2 ( V_1 -> V_5 -> V_6 . V_7 ) ;
V_1 -> V_8 = V_3 -> V_8 ;
V_1 -> V_9 = V_3 -> V_9 ;
memcpy ( & ( V_1 -> V_5 -> V_6 ) , & ( V_3 -> V_6 ) , sizeof( V_10 ) ) ;
memcpy ( & ( V_1 -> V_5 -> V_11 ) , & ( V_3 -> V_11 ) , sizeof( V_12 ) ) ;
return ( 1 ) ;
}
static int
F_3 ( T_1 * V_1 , T_4 * V_13 , T_5 V_14 )
{
T_3 * V_3 ;
T_2 * V_2 ;
V_3 = F_4 ( sizeof( T_3 ) ) ;
V_2 = F_5 ( V_14 , V_3 ) ;
if ( V_3 == NULL || V_2 == NULL )
{
if ( V_3 != NULL ) F_2 ( V_3 ) ;
if ( V_2 != NULL ) F_6 ( V_2 ) ;
F_7 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
V_3 -> V_8 = V_1 -> V_8 ;
V_3 -> V_9 = V_1 -> V_9 ;
memcpy ( & ( V_3 -> V_6 ) , & ( V_1 -> V_5 -> V_6 ) , sizeof( V_10 ) ) ;
memcpy ( & ( V_3 -> V_11 ) , & ( V_1 -> V_5 -> V_11 ) , sizeof( V_12 ) ) ;
V_2 -> V_4 = V_3 ;
if ( F_8 ( V_13 -> V_17 , V_2 ) == NULL )
{
F_2 ( V_3 ) ;
F_6 ( V_2 ) ;
return ( 0 ) ;
}
V_1 -> V_8 = NULL ;
V_1 -> V_9 = 0 ;
memset ( & ( V_1 -> V_5 -> V_6 ) , 0 , sizeof( V_10 ) ) ;
memset ( & ( V_1 -> V_5 -> V_11 ) , 0 , sizeof( V_12 ) ) ;
F_9 ( V_1 ) ;
return ( 1 ) ;
}
static int
F_10 ( T_1 * V_1 , T_4 * V_13 )
{
T_2 * V_2 ;
V_2 = F_11 ( V_13 -> V_17 ) ;
if ( V_2 )
{
F_1 ( V_1 , V_2 ) ;
F_2 ( V_2 -> V_4 ) ;
F_6 ( V_2 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static int
F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_13 ( V_1 -> V_18 -> V_19 . V_17 ) ;
if ( V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) V_2 -> V_4 ;
if ( V_1 -> V_18 -> V_19 . V_20 != V_1 -> V_18 -> V_21 )
return ( 1 ) ;
while ( F_13 ( V_1 -> V_18 -> V_19 . V_17 ) )
{
F_14 ( V_1 ) ;
if ( ! F_15 ( V_1 ) )
return ( 0 ) ;
F_3 ( V_1 , & ( V_1 -> V_18 -> V_22 ) ,
V_1 -> V_5 -> V_11 . V_23 ) ;
}
}
V_1 -> V_18 -> V_22 . V_20 = V_1 -> V_18 -> V_21 ;
V_1 -> V_18 -> V_19 . V_20 = V_1 -> V_18 -> V_21 + 1 ;
return ( 1 ) ;
}
static int
F_15 ( T_1 * V_1 )
{
int V_24 , V_25 ;
int V_26 = 0 ;
int V_27 ;
T_6 * V_28 ;
V_12 * V_29 ;
unsigned int V_30 ;
unsigned char V_31 [ V_32 ] ;
V_29 = & ( V_1 -> V_5 -> V_11 ) ;
V_28 = V_1 -> V_33 ;
V_29 -> V_34 = & ( V_1 -> V_8 [ V_35 ] ) ;
if ( V_29 -> V_36 > V_37 )
{
V_25 = V_38 ;
F_7 ( V_39 , V_40 ) ;
goto V_41;
}
V_29 -> V_4 = V_29 -> V_34 ;
V_27 = V_1 -> V_42 -> V_43 -> V_44 ( V_1 , 0 ) ;
if ( V_27 <= 0 )
{
if ( V_27 == 0 )
goto V_45;
goto V_46;
}
#ifdef F_16
printf ( L_1 , V_29 -> V_36 ) ;
{ unsigned int V_47 ; for ( V_47 = 0 ; V_47 < V_29 -> V_36 ; V_47 ++ ) printf ( L_2 , V_29 -> V_4 [ V_47 ] , ( ( V_47 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_28 == NULL ) ||
( V_1 -> V_48 == NULL ) ||
( V_1 -> V_49 == NULL ) )
V_26 = 1 ;
if ( ! V_26 )
{
V_30 = F_17 ( V_1 -> V_49 ) ;
if ( V_29 -> V_36 > V_50 + V_30 )
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
goto V_46;
#endif
}
if ( V_29 -> V_36 < V_30 )
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
goto V_46;
#endif
}
V_29 -> V_36 -= V_30 ;
V_24 = V_1 -> V_42 -> V_43 -> V_51 ( V_1 , V_31 , 0 ) ;
if ( memcmp ( V_31 , & ( V_29 -> V_4 [ V_29 -> V_36 ] ) , V_30 ) != 0 )
{
goto V_46;
}
}
if ( V_1 -> V_52 != NULL )
{
if ( V_29 -> V_36 > V_50 )
{
V_25 = V_38 ;
F_7 ( V_39 , V_53 ) ;
goto V_41;
}
if ( ! F_18 ( V_1 ) )
{
V_25 = V_54 ;
F_7 ( V_39 , V_55 ) ;
goto V_41;
}
}
if ( V_29 -> V_36 > V_56 )
{
V_25 = V_38 ;
F_7 ( V_39 , V_57 ) ;
goto V_41;
}
V_29 -> V_58 = 0 ;
V_1 -> V_9 = 0 ;
F_19 ( V_1 , & ( V_1 -> V_18 -> V_59 ) ) ;
return ( 1 ) ;
V_46:
V_25 = V_60 ;
F_7 ( V_39 , V_61 ) ;
V_41:
F_20 ( V_1 , V_62 , V_25 ) ;
V_45:
return ( 0 ) ;
}
int F_21 ( T_1 * V_1 )
{
int V_63 , V_64 , V_25 ;
int V_24 , V_65 ;
V_12 * V_29 ;
T_6 * V_28 ;
unsigned char * V_66 ;
short V_67 ;
T_7 * V_59 ;
unsigned int V_68 ;
V_29 = & ( V_1 -> V_5 -> V_11 ) ;
V_28 = V_1 -> V_33 ;
if ( ! F_12 ( V_1 ) )
return 0 ;
if ( F_22 ( V_1 ) )
return 1 ;
V_69:
if ( ( V_1 -> V_70 != V_71 ) ||
( V_1 -> V_9 < V_35 ) )
{
V_65 = F_23 ( V_1 , V_35 , V_1 -> V_5 -> V_6 . V_72 , 0 ) ;
if ( V_65 <= 0 ) return ( V_65 ) ;
F_24 ( V_1 -> V_9 == V_35 ) ;
V_1 -> V_70 = V_71 ;
V_66 = V_1 -> V_8 ;
V_29 -> type = * ( V_66 ++ ) ;
V_63 = * ( V_66 ++ ) ;
V_64 = * ( V_66 ++ ) ;
V_67 = ( V_63 << 8 ) | V_64 ;
F_25 ( V_66 , V_29 -> V_20 ) ;
memcpy ( & ( V_1 -> V_5 -> V_73 [ 2 ] ) , V_66 , 6 ) ;
V_66 += 6 ;
F_25 ( V_66 , V_29 -> V_36 ) ;
if ( V_1 -> V_74 )
{
V_1 -> V_74 = 0 ;
}
else
{
if ( V_67 != V_1 -> V_67 )
{
F_7 ( V_75 , V_76 ) ;
V_1 -> V_67 = V_67 ;
V_25 = V_77 ;
goto V_41;
}
}
if ( ( V_67 & 0xff00 ) != ( V_78 & 0xff00 ) )
{
F_7 ( V_75 , V_76 ) ;
goto V_45;
}
if ( V_29 -> V_36 > V_37 )
{
V_25 = V_38 ;
F_7 ( V_75 , V_79 ) ;
goto V_41;
}
}
if ( V_29 -> V_36 > V_1 -> V_9 - V_35 )
{
V_24 = V_29 -> V_36 ;
V_65 = F_23 ( V_1 , V_24 , V_24 , 1 ) ;
if ( V_65 <= 0 ) return ( V_65 ) ;
if ( V_65 != V_24 )
{
V_1 -> V_9 = 0 ;
goto V_69;
}
}
V_1 -> V_70 = V_80 ;
V_59 = F_26 ( V_1 , V_29 , & V_68 ) ;
if ( V_59 == NULL )
{
V_1 -> V_9 = 0 ;
goto V_69;
}
if ( ! F_27 ( V_1 , V_59 , & ( V_29 -> V_23 ) ) )
{
V_1 -> V_9 = 0 ;
goto V_69;
}
if ( V_29 -> V_36 == 0 ) goto V_69;
if ( V_68 )
{
F_19 ( V_1 , V_59 ) ;
F_3 ( V_1 , & ( V_1 -> V_18 -> V_19 ) , V_29 -> V_23 ) ;
V_1 -> V_9 = 0 ;
goto V_69;
}
if ( ! F_15 ( V_1 ) )
return ( 0 ) ;
F_28 ( V_1 ) ;
return ( 1 ) ;
V_41:
F_20 ( V_1 , V_62 , V_25 ) ;
V_45:
return ( 0 ) ;
}
int F_29 ( T_1 * V_1 , int type , unsigned char * V_7 , int V_72 , int V_81 )
{
int V_25 , V_24 , V_82 , V_83 ;
unsigned int V_65 ;
V_12 * V_29 ;
void (* F_30)( const T_1 * V_84 , int V_85 , int V_86 ) = NULL ;
if ( V_1 -> V_5 -> V_6 . V_7 == NULL )
if ( ! F_9 ( V_1 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_87 ) &&
( type != V_88 ) && type ) ||
( V_81 && ( type != V_87 ) ) )
{
F_7 ( V_89 , V_16 ) ;
return - 1 ;
}
if ( ( V_83 = F_31 ( V_1 , type , V_7 , V_72 , V_81 ) ) )
return V_83 ;
if ( ! V_1 -> V_90 && F_32 ( V_1 ) )
{
V_24 = V_1 -> V_91 ( V_1 ) ;
if ( V_24 < 0 ) return ( V_24 ) ;
if ( V_24 == 0 )
{
F_7 ( V_89 , V_92 ) ;
return ( - 1 ) ;
}
}
V_93:
V_1 -> V_94 = V_95 ;
V_29 = & ( V_1 -> V_5 -> V_11 ) ;
if ( ( V_29 -> V_36 == 0 ) || ( V_1 -> V_70 == V_71 ) )
{
V_83 = F_21 ( V_1 ) ;
if ( V_83 <= 0 )
{
V_83 = F_33 ( V_1 , V_83 ) ;
if ( V_83 <= 0 )
return ( V_83 ) ;
else
goto V_93;
}
}
if ( V_1 -> V_5 -> V_96
&& ( V_29 -> type != V_88 ) )
{
V_25 = V_97 ;
F_7 ( V_89 , V_98 ) ;
goto V_45;
}
if ( V_1 -> V_99 & V_100 )
{
V_29 -> V_36 = 0 ;
V_1 -> V_94 = V_95 ;
return ( 0 ) ;
}
if ( type == V_29 -> type )
{
if ( F_32 ( V_1 ) && ( type == V_87 ) &&
( V_1 -> V_48 == NULL ) )
{
V_25 = V_97 ;
F_7 ( V_89 , V_101 ) ;
goto V_41;
}
if ( V_72 <= 0 ) return ( V_72 ) ;
if ( ( unsigned int ) V_72 > V_29 -> V_36 )
V_65 = V_29 -> V_36 ;
else
V_65 = ( unsigned int ) V_72 ;
memcpy ( V_7 , & ( V_29 -> V_4 [ V_29 -> V_58 ] ) , V_65 ) ;
if ( ! V_81 )
{
V_29 -> V_36 -= V_65 ;
V_29 -> V_58 += V_65 ;
if ( V_29 -> V_36 == 0 )
{
V_1 -> V_70 = V_80 ;
V_29 -> V_58 = 0 ;
}
}
return ( V_65 ) ;
}
{
unsigned int V_102 , V_103 = 0 ;
unsigned char * V_104 = NULL ;
unsigned int * V_105 = NULL ;
if ( V_29 -> type == V_88 )
{
V_103 = sizeof V_1 -> V_18 -> V_106 ;
V_104 = V_1 -> V_18 -> V_106 ;
V_105 = & V_1 -> V_18 -> V_107 ;
}
else if ( V_29 -> type == V_108 )
{
V_103 = sizeof( V_1 -> V_18 -> V_109 ) ;
V_104 = V_1 -> V_18 -> V_109 ;
V_105 = & V_1 -> V_18 -> V_110 ;
}
else
F_24 ( V_29 -> type == V_111 ) ;
if ( V_103 > 0 )
{
if ( V_29 -> V_36 < V_103 )
{
V_1 -> V_70 = V_80 ;
V_29 -> V_36 = 0 ;
goto V_93;
}
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ )
{
V_104 [ V_102 ] = V_29 -> V_4 [ V_29 -> V_58 ++ ] ;
V_29 -> V_36 -- ;
}
* V_105 = V_103 ;
}
}
if ( ( ! V_1 -> V_112 ) &&
( V_1 -> V_18 -> V_107 >= V_113 ) &&
( V_1 -> V_18 -> V_106 [ 0 ] == V_114 ) &&
( V_1 -> V_33 != NULL ) && ( V_1 -> V_33 -> V_115 != NULL ) )
{
V_1 -> V_18 -> V_107 = 0 ;
if ( ( V_1 -> V_18 -> V_106 [ 1 ] != 0 ) ||
( V_1 -> V_18 -> V_106 [ 2 ] != 0 ) ||
( V_1 -> V_18 -> V_106 [ 3 ] != 0 ) )
{
V_25 = V_116 ;
F_7 ( V_89 , V_117 ) ;
goto V_45;
}
if ( V_1 -> V_118 )
V_1 -> V_118 ( 0 , V_1 -> V_67 , V_88 ,
V_1 -> V_18 -> V_106 , 4 , V_1 , V_1 -> V_119 ) ;
if ( F_34 ( V_1 ) &&
! ( V_1 -> V_5 -> V_120 & V_121 ) &&
! V_1 -> V_5 -> V_122 )
{
F_35 ( V_1 ) ;
if ( F_36 ( V_1 ) )
{
V_24 = V_1 -> V_91 ( V_1 ) ;
if ( V_24 < 0 ) return ( V_24 ) ;
if ( V_24 == 0 )
{
F_7 ( V_89 , V_92 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_123 & V_124 ) )
{
if ( V_1 -> V_5 -> V_6 . V_125 == 0 )
{
T_8 * V_126 ;
V_1 -> V_94 = V_127 ;
V_126 = F_37 ( V_1 ) ;
F_38 ( V_126 ) ;
F_39 ( V_126 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_93;
}
if ( V_1 -> V_18 -> V_110 >= V_128 )
{
int V_129 = V_1 -> V_18 -> V_109 [ 0 ] ;
int V_130 = V_1 -> V_18 -> V_109 [ 1 ] ;
V_1 -> V_18 -> V_110 = 0 ;
if ( V_1 -> V_118 )
V_1 -> V_118 ( 0 , V_1 -> V_67 , V_108 ,
V_1 -> V_18 -> V_109 , 2 , V_1 , V_1 -> V_119 ) ;
if ( V_1 -> V_131 != NULL )
F_30 = V_1 -> V_131 ;
else if ( V_1 -> V_132 -> V_131 != NULL )
F_30 = V_1 -> V_132 -> V_131 ;
if ( F_30 != NULL )
{
V_82 = ( V_129 << 8 ) | V_130 ;
F_30 ( V_1 , V_133 , V_82 ) ;
}
if ( V_129 == 1 )
{
V_1 -> V_5 -> V_134 = V_130 ;
if ( V_130 == V_135 )
{
V_1 -> V_99 |= V_100 ;
return ( 0 ) ;
}
#if 0
if (alert_descr == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE)
{
unsigned short seq;
unsigned int frag_off;
unsigned char *p = &(s->d1->alert_fragment[2]);
n2s(p, seq);
n2l3(p, frag_off);
dtls1_retransmit_message(s, seq, frag_off, &found);
if ( ! found && SSL_in_init(s))
{
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
}
}
#endif
}
else if ( V_129 == 2 )
{
char V_136 [ 16 ] ;
V_1 -> V_94 = V_95 ;
V_1 -> V_5 -> V_137 = V_130 ;
F_7 ( V_89 , V_138 + V_130 ) ;
F_40 ( V_136 , sizeof V_136 , L_4 , V_130 ) ;
F_41 ( 2 , L_5 , V_136 ) ;
V_1 -> V_99 |= V_100 ;
F_42 ( V_1 -> V_132 , V_1 -> V_33 ) ;
return ( 0 ) ;
}
else
{
V_25 = V_139 ;
F_7 ( V_89 , V_140 ) ;
goto V_41;
}
goto V_93;
}
if ( V_1 -> V_99 & V_141 )
{
V_1 -> V_94 = V_95 ;
V_29 -> V_36 = 0 ;
return ( 0 ) ;
}
if ( V_29 -> type == V_111 )
{
struct V_142 V_143 ;
F_43 ( V_29 -> V_4 , & V_143 ) ;
if ( V_143 . V_144 == V_1 -> V_18 -> V_145 )
{
if ( ( V_29 -> V_36 != V_146 ) ||
( V_29 -> V_58 != 0 ) || ( V_29 -> V_4 [ 0 ] != V_147 ) )
{
V_24 = V_139 ;
F_7 ( V_89 , V_148 ) ;
goto V_45;
}
V_29 -> V_36 = 0 ;
if ( V_1 -> V_118 )
V_1 -> V_118 ( 0 , V_1 -> V_67 , V_111 ,
V_29 -> V_4 , 1 , V_1 , V_1 -> V_119 ) ;
V_1 -> V_5 -> V_96 = 1 ;
if ( ! F_44 ( V_1 ) )
goto V_45;
F_45 ( V_1 , V_149 ) ;
V_1 -> V_18 -> V_145 ++ ;
goto V_93;
}
else
{
V_29 -> V_36 = 0 ;
goto V_93;
}
}
if ( ( V_1 -> V_18 -> V_107 >= V_113 ) &&
! V_1 -> V_90 )
{
struct V_150 V_151 ;
F_46 ( V_29 -> V_4 , & V_151 ) ;
if( V_29 -> V_20 != V_1 -> V_18 -> V_21 )
{
V_29 -> V_36 = 0 ;
goto V_93;
}
if ( ( ( V_1 -> V_152 & V_153 ) == V_154 ) &&
! ( V_1 -> V_5 -> V_120 & V_121 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_1 -> V_152 = V_1 -> V_112 ? V_155 : V_156 ;
#endif
V_1 -> V_157 = 1 ;
}
V_24 = V_1 -> V_91 ( V_1 ) ;
if ( V_24 < 0 ) return ( V_24 ) ;
if ( V_24 == 0 )
{
F_7 ( V_89 , V_92 ) ;
return ( - 1 ) ;
}
if ( ! ( V_1 -> V_123 & V_124 ) )
{
if ( V_1 -> V_5 -> V_6 . V_125 == 0 )
{
T_8 * V_126 ;
V_1 -> V_94 = V_127 ;
V_126 = F_37 ( V_1 ) ;
F_38 ( V_126 ) ;
F_39 ( V_126 ) ;
return ( - 1 ) ;
}
}
goto V_93;
}
switch ( V_29 -> type )
{
default:
#ifndef F_47
if ( V_1 -> V_67 == V_158 )
{
V_29 -> V_36 = 0 ;
goto V_93;
}
#endif
V_25 = V_97 ;
F_7 ( V_89 , V_159 ) ;
goto V_41;
case V_111 :
case V_108 :
case V_88 :
V_25 = V_97 ;
F_7 ( V_89 , V_16 ) ;
goto V_41;
case V_87 :
if ( V_1 -> V_5 -> V_160 &&
( V_1 -> V_5 -> V_161 != 0 ) &&
( (
( V_1 -> V_152 & V_156 ) &&
( V_1 -> V_152 >= V_162 ) &&
( V_1 -> V_152 <= V_163 )
) || (
( V_1 -> V_152 & V_155 ) &&
( V_1 -> V_152 <= V_164 ) &&
( V_1 -> V_152 >= V_165 )
)
) )
{
V_1 -> V_5 -> V_160 = 2 ;
return ( - 1 ) ;
}
else
{
V_25 = V_97 ;
F_7 ( V_89 , V_159 ) ;
goto V_41;
}
}
V_41:
F_20 ( V_1 , V_62 , V_25 ) ;
V_45:
return ( - 1 ) ;
}
int
F_48 ( T_1 * V_1 , int type , const void * V_166 , int V_72 )
{
unsigned int V_65 , V_167 ;
int V_24 ;
if ( F_32 ( V_1 ) && ! V_1 -> V_90 )
{
V_24 = V_1 -> V_91 ( V_1 ) ;
if ( V_24 < 0 ) return ( V_24 ) ;
if ( V_24 == 0 )
{
F_7 ( V_168 , V_92 ) ;
return - 1 ;
}
}
V_167 = V_1 -> V_5 -> V_169 ;
V_65 = V_72 - V_167 ;
while( V_65 )
{
V_24 = F_49 ( V_1 , type , V_166 , V_72 ) ;
if ( V_24 <= 0 ) return V_24 ;
if ( ( V_24 == ( int ) V_65 ) ||
( type == V_87 &&
( V_1 -> V_123 & V_170 ) ) )
{
V_1 -> V_5 -> V_171 = 0 ;
return V_167 + V_24 ;
}
V_167 += V_24 ;
V_65 -= V_24 ;
}
return V_167 ;
}
static int
F_31 ( T_1 * V_1 , int type , unsigned char * V_7 ,
int V_72 , int V_81 )
{
if ( ( type == V_88 ) && ( V_1 -> V_18 -> V_107 > 0 ) )
{
unsigned char * V_172 = V_1 -> V_18 -> V_106 ;
unsigned char * V_173 = V_7 ;
unsigned int V_102 , V_65 ;
V_65 = 0 ;
while ( ( V_72 > 0 ) && ( V_1 -> V_18 -> V_107 > 0 ) )
{
* V_173 ++ = * V_172 ++ ;
V_72 -- ; V_1 -> V_18 -> V_107 -- ;
V_65 ++ ;
}
for ( V_102 = 0 ; V_102 < V_1 -> V_18 -> V_107 ; V_102 ++ )
V_1 -> V_18 -> V_106 [ V_102 ] = * V_172 ++ ;
return V_65 ;
}
return 0 ;
}
int F_49 ( T_1 * V_1 , int type , const void * V_166 , int V_72 )
{
const unsigned char * V_7 = V_166 ;
unsigned int V_167 , V_65 , V_174 ;
int V_24 ;
unsigned int V_175 ;
V_1 -> V_94 = V_95 ;
V_167 = V_1 -> V_5 -> V_169 ;
V_65 = ( V_72 - V_167 ) ;
#if 0
mtu = BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_GET_MTU, 0, NULL);
mtu += DTLS1_HM_HEADER_LENGTH;
#endif
V_175 = V_1 -> V_18 -> V_175 ;
if ( V_175 > V_56 )
V_175 = V_56 ;
if ( V_65 > V_175 )
V_174 = V_175 ;
else
V_174 = V_65 ;
V_24 = F_50 ( V_1 , type , & ( V_7 [ V_167 ] ) , V_174 , 0 ) ;
if ( V_24 <= 0 )
{
V_1 -> V_5 -> V_169 = V_167 ;
return V_24 ;
}
if ( ( int ) V_1 -> V_5 -> V_169 + V_24 == V_72 )
V_1 -> V_5 -> V_169 = 0 ;
else
V_1 -> V_5 -> V_169 += V_24 ;
return V_167 + V_24 ;
}
int F_50 ( T_1 * V_1 , int type , const unsigned char * V_7 , unsigned int V_72 , int V_176 )
{
unsigned char * V_66 , * V_177 ;
int V_24 , V_30 , V_26 = 0 ;
int V_178 = 0 ;
V_12 * V_179 ;
V_10 * V_180 ;
T_6 * V_28 ;
int V_181 ;
if ( V_1 -> V_5 -> V_182 . V_125 != 0 )
{
F_24 ( 0 ) ;
return ( F_51 ( V_1 , type , V_7 , V_72 ) ) ;
}
if ( V_1 -> V_5 -> V_183 )
{
V_24 = V_1 -> V_42 -> V_184 ( V_1 ) ;
if ( V_24 <= 0 )
return ( V_24 ) ;
}
if ( V_72 == 0 && ! V_176 )
return 0 ;
V_179 = & ( V_1 -> V_5 -> V_185 ) ;
V_180 = & ( V_1 -> V_5 -> V_182 ) ;
V_28 = V_1 -> V_33 ;
if ( ( V_28 == NULL ) ||
( V_1 -> V_186 == NULL ) ||
( V_1 -> V_187 == NULL ) )
V_26 = 1 ;
if ( V_26 )
V_30 = 0 ;
else
V_30 = F_17 ( V_1 -> V_187 ) ;
#if 0
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done
&& SSL_version(s) != DTLS1_VERSION)
{
if (s->s3->need_empty_fragments && type == SSL3_RT_APPLICATION_DATA)
{
prefix_len = s->method->do_ssl_write(s, type, buf, 0, 1);
if (prefix_len <= 0)
goto err;
if (s->s3->wbuf.len < (size_t)prefix_len + SSL3_RT_MAX_PACKET_SIZE)
{
SSLerr(SSL_F_DO_DTLS1_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
}
s->s3->empty_fragment_done = 1;
}
#endif
V_66 = V_180 -> V_7 + V_178 ;
* ( V_66 ++ ) = type & 0xff ;
V_179 -> type = type ;
* ( V_66 ++ ) = ( V_1 -> V_67 >> 8 ) ;
* ( V_66 ++ ) = V_1 -> V_67 & 0xff ;
V_177 = V_66 ;
V_66 += 10 ;
if ( V_1 -> V_186 &&
( F_52 ( V_1 -> V_186 -> V_115 ) & V_188 ) )
V_181 = F_53 ( V_1 -> V_186 -> V_115 ) ;
else
V_181 = 0 ;
V_179 -> V_4 = V_66 + V_181 ;
V_179 -> V_36 = ( int ) V_72 ;
V_179 -> V_34 = ( unsigned char * ) V_7 ;
if ( V_1 -> V_189 != NULL )
{
if ( ! F_54 ( V_1 ) )
{
F_7 ( V_190 , V_191 ) ;
goto V_45;
}
}
else
{
memcpy ( V_179 -> V_4 , V_179 -> V_34 , V_179 -> V_36 ) ;
V_179 -> V_34 = V_179 -> V_4 ;
}
if ( V_30 != 0 )
{
V_1 -> V_42 -> V_43 -> V_51 ( V_1 , & ( V_66 [ V_179 -> V_36 + V_181 ] ) , 1 ) ;
V_179 -> V_36 += V_30 ;
}
V_179 -> V_34 = V_66 ;
V_179 -> V_4 = V_66 ;
V_179 -> V_36 += V_181 ;
V_1 -> V_42 -> V_43 -> V_44 ( V_1 , 1 ) ;
F_55 ( V_1 -> V_18 -> V_192 , V_177 ) ;
memcpy ( V_177 , & ( V_1 -> V_5 -> V_193 [ 2 ] ) , 6 ) ;
V_177 += 6 ;
F_55 ( V_179 -> V_36 , V_177 ) ;
V_179 -> type = type ;
V_179 -> V_36 += V_35 ;
#if 0
if ( type == SSL3_RT_HANDSHAKE || type == SSL3_RT_CHANGE_CIPHER_SPEC)
dtls1_buffer_record(s, wr->data, wr->length,
*((PQ_64BIT *)&(s->s3->write_sequence[0])));
#endif
F_56 ( & ( V_1 -> V_5 -> V_193 [ 0 ] ) ) ;
if ( V_176 )
{
return V_179 -> V_36 ;
}
V_180 -> V_125 = V_178 + V_179 -> V_36 ;
V_180 -> V_194 = 0 ;
V_1 -> V_5 -> V_195 = V_72 ;
V_1 -> V_5 -> V_196 = V_7 ;
V_1 -> V_5 -> V_197 = type ;
V_1 -> V_5 -> V_198 = V_72 ;
return F_51 ( V_1 , type , V_7 , V_72 ) ;
V_45:
return - 1 ;
}
static int F_27 ( T_1 * V_1 , T_7 * V_59 ,
T_5 * V_23 )
{
#if V_199
T_5 V_200 = 0x0000000000000001L ;
#endif
T_5 V_201 , V_136 ;
F_57 ( & V_201 ) ;
F_57 ( & V_136 ) ;
F_58 ( & V_201 , V_1 -> V_5 -> V_73 , 8 ) ;
if ( F_59 ( & V_201 , & ( V_59 -> V_202 ) ) ||
F_60 ( & V_201 , & ( V_59 -> V_202 ) ) )
{
F_61 ( V_23 , & V_201 ) ;
F_62 ( & V_201 ) ;
F_62 ( & V_136 ) ;
return 1 ;
}
F_63 ( & V_136 , & ( V_59 -> V_202 ) , & V_201 ) ;
if ( F_64 ( & V_136 ) > V_59 -> V_36 )
{
F_62 ( & V_201 ) ;
F_62 ( & V_136 ) ;
return 0 ;
}
#if V_203
{
int V_194 ;
F_63 ( & V_136 , & ( V_59 -> V_202 ) , & V_201 ) ;
F_65 ( & V_136 , 1 ) ;
V_194 = F_64 ( & V_136 ) ;
if ( F_66 ( & ( V_59 -> V_204 ) , V_194 ) )
{
F_62 ( & V_201 ) ;
F_62 ( & V_136 ) ;
return 0 ;
}
}
#else
V_200 <<= ( V_59 -> V_202 - V_201 - 1 ) ;
if ( V_59 -> V_204 & V_200 )
return 0 ;
#endif
F_61 ( V_23 , & V_201 ) ;
F_62 ( & V_201 ) ;
F_62 ( & V_136 ) ;
return 1 ;
}
static void F_19 ( T_1 * V_1 , T_7 * V_59 )
{
unsigned int V_205 ;
T_5 V_201 ;
T_5 V_136 ;
T_9 * V_132 ;
F_57 ( & V_201 ) ;
F_57 ( & V_136 ) ;
F_58 ( & V_201 , V_1 -> V_5 -> V_73 , 8 ) ;
if ( F_59 ( & V_201 , & ( V_59 -> V_202 ) ) ||
F_60 ( & V_201 , & ( V_59 -> V_202 ) ) )
{
F_63 ( & V_136 , & V_201 , & ( V_59 -> V_202 ) ) ;
F_67 ( & V_136 , 1 ) ;
V_205 = ( unsigned int ) F_64 ( & V_136 ) ;
F_68 ( & ( V_136 ) , & ( V_59 -> V_204 ) , V_205 ) ;
F_61 ( & ( V_59 -> V_204 ) , & V_136 ) ;
F_69 ( & ( V_59 -> V_204 ) , 0 ) ;
F_67 ( & V_201 , 1 ) ;
F_61 ( & ( V_59 -> V_202 ) , & V_201 ) ;
F_70 ( & V_136 , 1 ) ;
F_68 ( & V_136 , & V_136 , V_59 -> V_36 ) ;
V_132 = F_71 ( & V_132 ) ;
F_72 ( & ( V_59 -> V_204 ) , & ( V_59 -> V_204 ) , & V_136 , V_132 ) ;
F_73 ( V_132 ) ;
}
else
{
F_63 ( & V_136 , & ( V_59 -> V_202 ) , & V_201 ) ;
F_65 ( & V_136 , 1 ) ;
V_205 = ( unsigned int ) F_64 ( & V_136 ) ;
F_69 ( & ( V_59 -> V_204 ) , V_205 ) ;
}
F_62 ( & V_201 ) ;
F_62 ( & V_136 ) ;
}
int F_74 ( T_1 * V_1 )
{
int V_24 , V_82 ;
void (* F_30)( const T_1 * V_84 , int type , int V_86 ) = NULL ;
unsigned char V_7 [ 2 + 2 + 3 ] ;
unsigned char * V_206 = & V_7 [ 0 ] ;
V_1 -> V_5 -> V_183 = 0 ;
memset ( V_7 , 0x00 , sizeof( V_7 ) ) ;
* V_206 ++ = V_1 -> V_5 -> V_207 [ 0 ] ;
* V_206 ++ = V_1 -> V_5 -> V_207 [ 1 ] ;
if ( V_1 -> V_5 -> V_207 [ 1 ] == V_208 )
{
F_55 ( V_1 -> V_18 -> V_145 , V_206 ) ;
#if 0
if ( s->d1->r_msg_hdr.frag_off == 0)
else
s2n(s->d1->r_msg_hdr.seq, ptr);
#endif
#if 0
fprintf(stderr, "s->d1->handshake_read_seq = %d, s->d1->r_msg_hdr.seq = %d\n",s->d1->handshake_read_seq,s->d1->r_msg_hdr.seq);
#endif
F_75 ( V_1 -> V_18 -> V_209 . V_210 , V_206 ) ;
}
V_24 = F_50 ( V_1 , V_108 , & V_7 [ 0 ] , sizeof( V_7 ) , 0 ) ;
if ( V_24 <= 0 )
{
V_1 -> V_5 -> V_183 = 1 ;
}
else
{
if ( V_1 -> V_5 -> V_207 [ 0 ] == V_62 ||
V_1 -> V_5 -> V_207 [ 1 ] == V_208 )
( void ) F_76 ( V_1 -> V_211 ) ;
if ( V_1 -> V_118 )
V_1 -> V_118 ( 1 , V_1 -> V_67 , V_108 , V_1 -> V_5 -> V_207 ,
2 , V_1 , V_1 -> V_119 ) ;
if ( V_1 -> V_131 != NULL )
F_30 = V_1 -> V_131 ;
else if ( V_1 -> V_132 -> V_131 != NULL )
F_30 = V_1 -> V_132 -> V_131 ;
if ( F_30 != NULL )
{
V_82 = ( V_1 -> V_5 -> V_207 [ 0 ] << 8 ) | V_1 -> V_5 -> V_207 [ 1 ] ;
F_30 ( V_1 , V_212 , V_82 ) ;
}
}
return ( V_24 ) ;
}
static T_7 *
F_26 ( T_1 * V_1 , V_12 * V_29 , unsigned int * V_68 )
{
* V_68 = 0 ;
if ( V_29 -> V_20 == V_1 -> V_18 -> V_21 )
return & V_1 -> V_18 -> V_59 ;
else if ( V_29 -> V_20 == ( unsigned long ) ( V_1 -> V_18 -> V_21 + 1 ) &&
( V_29 -> type == V_88 ||
V_29 -> type == V_108 ) )
{
* V_68 = 1 ;
return & V_1 -> V_18 -> V_213 ;
}
return NULL ;
}
void
F_45 ( T_1 * V_1 , int V_214 )
{
unsigned char * V_144 ;
unsigned int V_215 = sizeof( V_1 -> V_5 -> V_73 ) ;
if ( V_214 & V_149 )
{
V_144 = V_1 -> V_5 -> V_73 ;
V_1 -> V_18 -> V_21 ++ ;
F_61 ( & ( V_1 -> V_18 -> V_59 . V_204 ) , & ( V_1 -> V_18 -> V_213 . V_204 ) ) ;
V_1 -> V_18 -> V_59 . V_36 = V_1 -> V_18 -> V_213 . V_36 ;
F_61 ( & ( V_1 -> V_18 -> V_59 . V_202 ) ,
& ( V_1 -> V_18 -> V_213 . V_202 ) ) ;
F_62 ( & ( V_1 -> V_18 -> V_213 . V_204 ) ) ;
F_62 ( & ( V_1 -> V_18 -> V_213 . V_202 ) ) ;
memset ( & ( V_1 -> V_18 -> V_213 ) , 0x00 , sizeof( T_7 ) ) ;
F_57 ( & ( V_1 -> V_18 -> V_213 . V_204 ) ) ;
F_57 ( & ( V_1 -> V_18 -> V_213 . V_202 ) ) ;
}
else
{
V_144 = V_1 -> V_5 -> V_193 ;
V_1 -> V_18 -> V_192 ++ ;
}
memset ( V_144 , 0x00 , V_215 ) ;
}
static T_5
F_77 ( unsigned char * V_216 , T_5 * V_217 )
{
T_5 V_218 ;
V_218 = ( ( ( T_5 ) V_216 [ 0 ] ) << 56 ) |
( ( ( T_5 ) V_216 [ 1 ] ) << 48 ) |
( ( ( T_5 ) V_216 [ 2 ] ) << 40 ) |
( ( ( T_5 ) V_216 [ 3 ] ) << 32 ) |
( ( ( T_5 ) V_216 [ 4 ] ) << 24 ) |
( ( ( T_5 ) V_216 [ 5 ] ) << 16 ) |
( ( ( T_5 ) V_216 [ 6 ] ) << 8 ) |
( ( ( T_5 ) V_216 [ 7 ] ) ) ;
* V_217 = V_218 ;
return V_218 ;
}
static void
F_28 ( T_1 * V_1 )
{
memset ( & ( V_1 -> V_18 -> V_219 ) , 0x00 , sizeof( struct V_220 ) ) ;
}
