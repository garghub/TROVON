static int F_1 ( const unsigned char * V_1 , const unsigned char * V_2 )
{ int V_3 , V_4 , V_5 , V_6 ;
if ( sizeof( long ) == 8 ) do
{ const union { long V_7 ; char V_8 ; } V_9 = { 1 } ;
long V_10 ;
if ( V_9 . V_8 ) break;
if ( ( ( V_11 ) V_1 | ( V_11 ) V_2 ) & 0x7 ) break;
V_10 = * ( ( long * ) V_1 ) ;
V_10 -= * ( ( long * ) V_2 ) ;
if ( V_10 > 128 ) return 128 ;
else if ( V_10 < - 128 ) return - 128 ;
else return ( int ) V_10 ;
} while ( 0 );
V_3 = ( int ) V_1 [ 7 ] - ( int ) V_2 [ 7 ] ;
V_4 = 0 ;
V_5 = V_3 >> 8 ;
if ( V_3 & 0x80 )
{ for ( V_6 = 6 ; V_6 >= 0 ; V_6 -- )
{ V_5 += ( int ) V_1 [ V_6 ] - ( int ) V_2 [ V_6 ] ;
V_4 |= ~ V_5 ;
V_5 >>= 8 ;
}
}
else
{ for ( V_6 = 6 ; V_6 >= 0 ; V_6 -- )
{ V_5 += ( int ) V_1 [ V_6 ] - ( int ) V_2 [ V_6 ] ;
V_4 |= V_5 ;
V_5 >>= 8 ;
}
}
V_5 <<= 8 ;
if ( V_4 & 0xff ) return V_5 | 0x80 ;
else return V_5 + ( V_3 & 0xFF ) ;
}
static int
F_2 ( T_1 * V_12 , T_2 * V_13 )
{
T_3 * V_14 ;
V_14 = ( T_3 * ) V_13 -> V_15 ;
if ( V_12 -> V_16 -> V_17 . V_18 != NULL )
F_3 ( V_12 -> V_16 -> V_17 . V_18 ) ;
V_12 -> V_19 = V_14 -> V_19 ;
V_12 -> V_20 = V_14 -> V_20 ;
memcpy ( & ( V_12 -> V_16 -> V_17 ) , & ( V_14 -> V_17 ) , sizeof( V_21 ) ) ;
memcpy ( & ( V_12 -> V_16 -> V_22 ) , & ( V_14 -> V_22 ) , sizeof( V_23 ) ) ;
return ( 1 ) ;
}
static int
F_4 ( T_1 * V_12 , T_4 * V_24 , unsigned char * V_25 )
{
T_3 * V_14 ;
T_2 * V_13 ;
if ( F_5 ( V_24 -> V_26 ) >= 100 )
return 0 ;
V_14 = F_6 ( sizeof( T_3 ) ) ;
V_13 = F_7 ( V_25 , V_14 ) ;
if ( V_14 == NULL || V_13 == NULL )
{
if ( V_14 != NULL ) F_3 ( V_14 ) ;
if ( V_13 != NULL ) F_8 ( V_13 ) ;
F_9 ( V_27 , V_28 ) ;
return ( 0 ) ;
}
V_14 -> V_19 = V_12 -> V_19 ;
V_14 -> V_20 = V_12 -> V_20 ;
memcpy ( & ( V_14 -> V_17 ) , & ( V_12 -> V_16 -> V_17 ) , sizeof( V_21 ) ) ;
memcpy ( & ( V_14 -> V_22 ) , & ( V_12 -> V_16 -> V_22 ) , sizeof( V_23 ) ) ;
V_13 -> V_15 = V_14 ;
if ( F_10 ( V_24 -> V_26 , V_13 ) == NULL )
{
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( 0 ) ;
}
V_12 -> V_19 = NULL ;
V_12 -> V_20 = 0 ;
memset ( & ( V_12 -> V_16 -> V_17 ) , 0 , sizeof( V_21 ) ) ;
memset ( & ( V_12 -> V_16 -> V_22 ) , 0 , sizeof( V_23 ) ) ;
if ( ! F_11 ( V_12 ) )
{
F_9 ( V_27 , V_28 ) ;
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int
F_12 ( T_1 * V_12 , T_4 * V_24 )
{
T_2 * V_13 ;
V_13 = F_13 ( V_24 -> V_26 ) ;
if ( V_13 )
{
F_2 ( V_12 , V_13 ) ;
F_3 ( V_13 -> V_15 ) ;
F_8 ( V_13 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static int
F_14 ( T_1 * V_12 )
{
T_2 * V_13 ;
V_13 = F_15 ( V_12 -> V_29 -> V_30 . V_26 ) ;
if ( V_13 )
{
T_3 * V_14 ;
V_14 = ( T_3 * ) V_13 -> V_15 ;
if ( V_12 -> V_29 -> V_30 . V_31 != V_12 -> V_29 -> V_32 )
return ( 1 ) ;
while ( F_15 ( V_12 -> V_29 -> V_30 . V_26 ) )
{
F_16 ( V_12 ) ;
if ( ! F_17 ( V_12 ) )
return ( 0 ) ;
F_4 ( V_12 , & ( V_12 -> V_29 -> V_33 ) ,
V_12 -> V_16 -> V_22 . V_34 ) ;
}
}
V_12 -> V_29 -> V_33 . V_31 = V_12 -> V_29 -> V_32 ;
V_12 -> V_29 -> V_30 . V_31 = V_12 -> V_29 -> V_32 + 1 ;
return ( 1 ) ;
}
static int
F_17 ( T_1 * V_12 )
{
int V_6 , V_35 ;
int V_36 = 0 ;
int V_37 ;
T_5 * V_38 ;
V_23 * V_39 ;
unsigned int V_40 ;
unsigned char V_41 [ V_42 ] ;
V_39 = & ( V_12 -> V_16 -> V_22 ) ;
V_38 = V_12 -> V_43 ;
V_39 -> V_44 = & ( V_12 -> V_19 [ V_45 ] ) ;
if ( V_39 -> V_46 > V_47 )
{
V_35 = V_48 ;
F_9 ( V_49 , V_50 ) ;
goto V_51;
}
V_39 -> V_15 = V_39 -> V_44 ;
V_37 = V_12 -> V_52 -> V_53 -> V_54 ( V_12 , 0 ) ;
if ( V_37 <= 0 )
{
if ( V_37 == 0 )
goto V_55;
goto V_56;
}
#ifdef F_18
printf ( L_1 , V_39 -> V_46 ) ;
{ unsigned int V_57 ; for ( V_57 = 0 ; V_57 < V_39 -> V_46 ; V_57 ++ ) printf ( L_2 , V_39 -> V_15 [ V_57 ] , ( ( V_57 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_38 == NULL ) ||
( V_12 -> V_58 == NULL ) ||
( V_12 -> V_59 == NULL ) )
V_36 = 1 ;
if ( ! V_36 )
{
int V_60 ;
V_60 = F_19 ( V_12 -> V_59 ) ;
F_20 ( V_60 >= 0 ) ;
V_40 = V_60 ;
if ( V_39 -> V_46 > V_61 + V_40 )
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
goto V_56;
#endif
}
if ( V_39 -> V_46 < V_40 )
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
goto V_56;
#endif
}
V_39 -> V_46 -= V_40 ;
V_6 = V_12 -> V_52 -> V_53 -> V_62 ( V_12 , V_41 , 0 ) ;
if ( V_6 < 0 || memcmp ( V_41 , & ( V_39 -> V_15 [ V_39 -> V_46 ] ) , V_40 ) != 0 )
{
goto V_56;
}
}
if ( V_12 -> V_63 != NULL )
{
if ( V_39 -> V_46 > V_61 )
{
V_35 = V_48 ;
F_9 ( V_49 , V_64 ) ;
goto V_51;
}
if ( ! F_21 ( V_12 ) )
{
V_35 = V_65 ;
F_9 ( V_49 , V_66 ) ;
goto V_51;
}
}
if ( V_39 -> V_46 > V_67 )
{
V_35 = V_48 ;
F_9 ( V_49 , V_68 ) ;
goto V_51;
}
V_39 -> V_69 = 0 ;
V_12 -> V_20 = 0 ;
F_22 ( V_12 , & ( V_12 -> V_29 -> V_70 ) ) ;
return ( 1 ) ;
V_56:
V_35 = V_71 ;
F_9 ( V_49 , V_72 ) ;
V_51:
F_23 ( V_12 , V_73 , V_35 ) ;
V_55:
return ( 0 ) ;
}
int F_24 ( T_1 * V_12 )
{
int V_74 , V_75 ;
int V_6 , V_76 ;
V_23 * V_39 ;
T_5 * V_38 ;
unsigned char * V_77 = NULL ;
unsigned short V_78 ;
T_6 * V_70 ;
unsigned int V_79 ;
V_39 = & ( V_12 -> V_16 -> V_22 ) ;
V_38 = V_12 -> V_43 ;
if ( ! F_14 ( V_12 ) )
return 0 ;
if ( F_25 ( V_12 ) )
return 1 ;
V_80:
if ( ( V_12 -> V_81 != V_82 ) ||
( V_12 -> V_20 < V_45 ) )
{
V_76 = F_26 ( V_12 , V_45 , V_12 -> V_16 -> V_17 . V_83 , 0 ) ;
if ( V_76 <= 0 ) return ( V_76 ) ;
if ( V_12 -> V_20 != V_45 )
{
V_12 -> V_20 = 0 ;
goto V_80;
}
V_12 -> V_81 = V_82 ;
V_77 = V_12 -> V_19 ;
V_39 -> type = * ( V_77 ++ ) ;
V_74 = * ( V_77 ++ ) ;
V_75 = * ( V_77 ++ ) ;
V_78 = ( V_74 << 8 ) | V_75 ;
F_27 ( V_77 , V_39 -> V_31 ) ;
memcpy ( & ( V_12 -> V_16 -> V_84 [ 2 ] ) , V_77 , 6 ) ;
V_77 += 6 ;
F_27 ( V_77 , V_39 -> V_46 ) ;
if ( ! V_12 -> V_85 )
{
if ( V_78 != V_12 -> V_78 )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
}
if ( ( V_78 & 0xff00 ) != ( V_12 -> V_78 & 0xff00 ) )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
if ( V_39 -> V_46 > V_47 )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
}
if ( V_39 -> V_46 > V_12 -> V_20 - V_45 )
{
V_6 = V_39 -> V_46 ;
V_76 = F_26 ( V_12 , V_6 , V_6 , 1 ) ;
if ( V_76 <= 0 ) return ( V_76 ) ;
if ( V_76 != V_6 )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
}
V_12 -> V_81 = V_86 ;
V_70 = F_28 ( V_12 , V_39 , & V_79 ) ;
if ( V_70 == NULL )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
if ( ! ( V_12 -> V_29 -> V_87 && V_39 -> type == V_88 &&
* V_77 == V_89 ) &&
! F_29 ( V_12 , V_70 ) )
{
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
if ( V_39 -> V_46 == 0 ) goto V_80;
if ( V_79 )
{
F_22 ( V_12 , V_70 ) ;
F_4 ( V_12 , & ( V_12 -> V_29 -> V_30 ) , V_39 -> V_34 ) ;
V_39 -> V_46 = 0 ;
V_12 -> V_20 = 0 ;
goto V_80;
}
if ( ! F_17 ( V_12 ) )
return ( 0 ) ;
F_30 ( V_12 ) ;
return ( 1 ) ;
}
int F_31 ( T_1 * V_12 , int type , unsigned char * V_18 , int V_83 , int V_90 )
{
int V_35 , V_6 , V_91 , V_3 ;
unsigned int V_76 ;
V_23 * V_39 ;
void (* F_32)( const T_1 * V_92 , int V_93 , int V_94 ) = NULL ;
if ( V_12 -> V_16 -> V_17 . V_18 == NULL )
if ( ! F_11 ( V_12 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_95 ) &&
( type != V_88 ) && type ) ||
( V_90 && ( type != V_95 ) ) )
{
F_9 ( V_96 , V_28 ) ;
return - 1 ;
}
if ( ( V_3 = F_33 ( V_12 , type , V_18 , V_83 , V_90 ) ) )
return V_3 ;
if ( ! V_12 -> V_97 && F_34 ( V_12 ) )
{
V_6 = V_12 -> V_98 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_96 , V_99 ) ;
return ( - 1 ) ;
}
}
V_100:
V_12 -> V_101 = V_102 ;
V_39 = & ( V_12 -> V_16 -> V_22 ) ;
if ( V_12 -> V_103 == V_104 && V_39 -> V_46 == 0 )
{
T_2 * V_13 ;
V_13 = F_13 ( V_12 -> V_29 -> V_105 . V_26 ) ;
if ( V_13 )
{
F_2 ( V_12 , V_13 ) ;
F_3 ( V_13 -> V_15 ) ;
F_8 ( V_13 ) ;
}
}
if ( F_35 ( V_12 ) > 0 )
goto V_100;
if ( ( V_39 -> V_46 == 0 ) || ( V_12 -> V_81 == V_82 ) )
{
V_3 = F_24 ( V_12 ) ;
if ( V_3 <= 0 )
{
V_3 = F_36 ( V_12 , V_3 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
else
goto V_100;
}
}
if ( V_12 -> V_16 -> V_106
&& ( V_39 -> type != V_88 ) )
{
F_4 ( V_12 , & ( V_12 -> V_29 -> V_105 ) , 0 ) ;
V_39 -> V_46 = 0 ;
goto V_100;
}
if ( V_12 -> V_107 & V_108 )
{
V_39 -> V_46 = 0 ;
V_12 -> V_101 = V_102 ;
return ( 0 ) ;
}
if ( type == V_39 -> type )
{
if ( F_34 ( V_12 ) && ( type == V_95 ) &&
( V_12 -> V_58 == NULL ) )
{
V_35 = V_109 ;
F_9 ( V_96 , V_110 ) ;
goto V_51;
}
if ( V_83 <= 0 ) return ( V_83 ) ;
if ( ( unsigned int ) V_83 > V_39 -> V_46 )
V_76 = V_39 -> V_46 ;
else
V_76 = ( unsigned int ) V_83 ;
memcpy ( V_18 , & ( V_39 -> V_15 [ V_39 -> V_69 ] ) , V_76 ) ;
if ( ! V_90 )
{
V_39 -> V_46 -= V_76 ;
V_39 -> V_69 += V_76 ;
if ( V_39 -> V_46 == 0 )
{
V_12 -> V_81 = V_86 ;
V_39 -> V_69 = 0 ;
}
}
return ( V_76 ) ;
}
{
unsigned int V_111 , V_112 = 0 ;
unsigned char * V_113 = NULL ;
unsigned int * V_114 = NULL ;
if ( V_39 -> type == V_88 )
{
V_112 = sizeof V_12 -> V_29 -> V_115 ;
V_113 = V_12 -> V_29 -> V_115 ;
V_114 = & V_12 -> V_29 -> V_116 ;
}
else if ( V_39 -> type == V_117 )
{
V_112 = sizeof( V_12 -> V_29 -> V_118 ) ;
V_113 = V_12 -> V_29 -> V_118 ;
V_114 = & V_12 -> V_29 -> V_119 ;
}
else if ( V_39 -> type != V_120 )
{
if ( V_39 -> type == V_95 )
{
T_7 * V_121 ;
V_12 -> V_16 -> V_122 = 2 ;
V_121 = F_37 ( V_12 ) ;
V_12 -> V_101 = V_123 ;
F_38 ( V_121 ) ;
F_39 ( V_121 ) ;
return ( - 1 ) ;
}
V_35 = V_109 ;
F_9 ( V_96 , V_124 ) ;
goto V_51;
}
if ( V_112 > 0 )
{
if ( V_39 -> V_46 < V_112 )
{
#ifdef F_40
T_8 T_9
#endif
V_12 -> V_81 = V_86 ;
V_39 -> V_46 = 0 ;
goto V_100;
}
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
{
V_113 [ V_111 ] = V_39 -> V_15 [ V_39 -> V_69 ++ ] ;
V_39 -> V_46 -- ;
}
* V_114 = V_112 ;
}
}
if ( ( ! V_12 -> V_125 ) &&
( V_12 -> V_29 -> V_116 >= V_126 ) &&
( V_12 -> V_29 -> V_115 [ 0 ] == V_127 ) &&
( V_12 -> V_43 != NULL ) && ( V_12 -> V_43 -> V_128 != NULL ) )
{
V_12 -> V_29 -> V_116 = 0 ;
if ( ( V_12 -> V_29 -> V_115 [ 1 ] != 0 ) ||
( V_12 -> V_29 -> V_115 [ 2 ] != 0 ) ||
( V_12 -> V_29 -> V_115 [ 3 ] != 0 ) )
{
V_35 = V_129 ;
F_9 ( V_96 , V_130 ) ;
goto V_55;
}
if ( V_12 -> V_131 )
V_12 -> V_131 ( 0 , V_12 -> V_78 , V_88 ,
V_12 -> V_29 -> V_115 , 4 , V_12 , V_12 -> V_132 ) ;
if ( F_41 ( V_12 ) &&
! ( V_12 -> V_16 -> V_133 & V_134 ) &&
! V_12 -> V_16 -> V_135 )
{
F_42 ( V_12 ) ;
if ( F_43 ( V_12 ) )
{
V_6 = V_12 -> V_98 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_96 , V_99 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_136 & V_137 ) )
{
if ( V_12 -> V_16 -> V_17 . V_138 == 0 )
{
T_7 * V_121 ;
V_12 -> V_101 = V_123 ;
V_121 = F_37 ( V_12 ) ;
F_38 ( V_121 ) ;
F_39 ( V_121 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_100;
}
if ( V_12 -> V_29 -> V_119 >= V_139 )
{
int V_140 = V_12 -> V_29 -> V_118 [ 0 ] ;
int V_141 = V_12 -> V_29 -> V_118 [ 1 ] ;
V_12 -> V_29 -> V_119 = 0 ;
if ( V_12 -> V_131 )
V_12 -> V_131 ( 0 , V_12 -> V_78 , V_117 ,
V_12 -> V_29 -> V_118 , 2 , V_12 , V_12 -> V_132 ) ;
if ( V_12 -> V_142 != NULL )
F_32 = V_12 -> V_142 ;
else if ( V_12 -> V_143 -> V_142 != NULL )
F_32 = V_12 -> V_143 -> V_142 ;
if ( F_32 != NULL )
{
V_91 = ( V_140 << 8 ) | V_141 ;
F_32 ( V_12 , V_144 , V_91 ) ;
}
if ( V_140 == 1 )
{
V_12 -> V_16 -> V_145 = V_141 ;
if ( V_141 == V_146 )
{
V_12 -> V_107 |= V_108 ;
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
dtls1_retransmit_message(s,
dtls1_get_queue_priority(frag->msg_header.seq, 0),
frag_off, &found);
if ( ! found && SSL_in_init(s))
{
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
}
}
#endif
}
else if ( V_140 == 2 )
{
char V_147 [ 16 ] ;
V_12 -> V_101 = V_102 ;
V_12 -> V_16 -> V_148 = V_141 ;
F_9 ( V_96 , V_149 + V_141 ) ;
F_44 ( V_147 , sizeof V_147 , L_4 , V_141 ) ;
F_45 ( 2 , L_5 , V_147 ) ;
V_12 -> V_107 |= V_108 ;
F_46 ( V_12 -> V_143 , V_12 -> V_43 ) ;
return ( 0 ) ;
}
else
{
V_35 = V_150 ;
F_9 ( V_96 , V_151 ) ;
goto V_51;
}
goto V_100;
}
if ( V_12 -> V_107 & V_152 )
{
V_12 -> V_101 = V_102 ;
V_39 -> V_46 = 0 ;
return ( 0 ) ;
}
if ( V_39 -> type == V_120 )
{
struct V_153 V_154 ;
unsigned int V_155 = V_156 ;
F_47 ( V_39 -> V_15 , & V_154 ) ;
if ( V_12 -> V_78 == V_157 )
V_155 = 3 ;
if ( ( V_39 -> V_46 != V_155 ) ||
( V_39 -> V_69 != 0 ) || ( V_39 -> V_15 [ 0 ] != V_158 ) )
{
V_6 = V_150 ;
F_9 ( V_96 , V_159 ) ;
goto V_55;
}
V_39 -> V_46 = 0 ;
if ( V_12 -> V_131 )
V_12 -> V_131 ( 0 , V_12 -> V_78 , V_120 ,
V_39 -> V_15 , 1 , V_12 , V_12 -> V_132 ) ;
if ( ! V_12 -> V_29 -> V_160 )
{
goto V_100;
}
V_12 -> V_29 -> V_160 = 0 ;
V_12 -> V_16 -> V_106 = 1 ;
if ( ! F_48 ( V_12 ) )
goto V_55;
F_49 ( V_12 , V_161 ) ;
if ( V_12 -> V_78 == V_157 )
V_12 -> V_29 -> V_162 ++ ;
goto V_100;
}
if ( ( V_12 -> V_29 -> V_116 >= V_126 ) &&
! V_12 -> V_97 )
{
struct V_163 V_164 ;
F_50 ( V_39 -> V_15 , & V_164 ) ;
if( V_39 -> V_31 != V_12 -> V_29 -> V_32 )
{
V_39 -> V_46 = 0 ;
goto V_100;
}
if ( V_164 . type == V_165 )
{
F_51 ( V_12 ) ;
V_39 -> V_46 = 0 ;
goto V_100;
}
if ( ( ( V_12 -> V_103 & V_166 ) == V_104 ) &&
! ( V_12 -> V_16 -> V_133 & V_134 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_12 -> V_103 = V_12 -> V_125 ? V_167 : V_168 ;
#endif
V_12 -> V_169 = 1 ;
}
V_6 = V_12 -> V_98 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_96 , V_99 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_136 & V_137 ) )
{
if ( V_12 -> V_16 -> V_17 . V_138 == 0 )
{
T_7 * V_121 ;
V_12 -> V_101 = V_123 ;
V_121 = F_37 ( V_12 ) ;
F_38 ( V_121 ) ;
F_39 ( V_121 ) ;
return ( - 1 ) ;
}
}
goto V_100;
}
switch ( V_39 -> type )
{
default:
#ifndef F_52
if ( V_12 -> V_78 == V_170 )
{
V_39 -> V_46 = 0 ;
goto V_100;
}
#endif
V_35 = V_109 ;
F_9 ( V_96 , V_124 ) ;
goto V_51;
case V_120 :
case V_117 :
case V_88 :
V_35 = V_109 ;
F_9 ( V_96 , V_28 ) ;
goto V_51;
case V_95 :
if ( V_12 -> V_16 -> V_122 &&
( V_12 -> V_16 -> V_171 != 0 ) &&
( (
( V_12 -> V_103 & V_168 ) &&
( V_12 -> V_103 >= V_172 ) &&
( V_12 -> V_103 <= V_173 )
) || (
( V_12 -> V_103 & V_167 ) &&
( V_12 -> V_103 <= V_174 ) &&
( V_12 -> V_103 >= V_175 )
)
) )
{
V_12 -> V_16 -> V_122 = 2 ;
return ( - 1 ) ;
}
else
{
V_35 = V_109 ;
F_9 ( V_96 , V_124 ) ;
goto V_51;
}
}
V_51:
F_23 ( V_12 , V_73 , V_35 ) ;
V_55:
return ( - 1 ) ;
}
int
F_53 ( T_1 * V_12 , int type , const void * V_176 , int V_83 )
{
int V_6 ;
if ( F_34 ( V_12 ) && ! V_12 -> V_97 )
{
V_6 = V_12 -> V_98 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_177 , V_99 ) ;
return - 1 ;
}
}
if ( V_83 > V_67 )
{
F_9 ( V_177 , V_178 ) ;
return - 1 ;
}
V_6 = F_54 ( V_12 , type , V_176 , V_83 ) ;
return V_6 ;
}
static int
F_33 ( T_1 * V_12 , int type , unsigned char * V_18 ,
int V_83 , int V_90 )
{
if ( ( type == V_88 ) && ( V_12 -> V_29 -> V_116 > 0 ) )
{
unsigned char * V_179 = V_12 -> V_29 -> V_115 ;
unsigned char * V_180 = V_18 ;
unsigned int V_111 , V_76 ;
V_76 = 0 ;
while ( ( V_83 > 0 ) && ( V_12 -> V_29 -> V_116 > 0 ) )
{
* V_180 ++ = * V_179 ++ ;
V_83 -- ; V_12 -> V_29 -> V_116 -- ;
V_76 ++ ;
}
for ( V_111 = 0 ; V_111 < V_12 -> V_29 -> V_116 ; V_111 ++ )
V_12 -> V_29 -> V_115 [ V_111 ] = * V_179 ++ ;
return V_76 ;
}
return 0 ;
}
int F_54 ( T_1 * V_12 , int type , const void * V_18 , int V_83 )
{
int V_6 ;
F_20 ( V_83 <= V_67 ) ;
V_12 -> V_101 = V_102 ;
V_6 = F_55 ( V_12 , type , V_18 , V_83 , 0 ) ;
return V_6 ;
}
int F_55 ( T_1 * V_12 , int type , const unsigned char * V_18 , unsigned int V_83 , int V_181 )
{
unsigned char * V_77 , * V_182 ;
int V_6 , V_40 , V_36 = 0 ;
int V_183 = 0 ;
V_23 * V_184 ;
V_21 * V_185 ;
T_5 * V_38 ;
int V_186 ;
if ( V_12 -> V_16 -> V_187 . V_138 != 0 )
{
F_20 ( 0 ) ;
return ( F_56 ( V_12 , type , V_18 , V_83 ) ) ;
}
if ( V_12 -> V_16 -> V_188 )
{
V_6 = V_12 -> V_52 -> V_189 ( V_12 ) ;
if ( V_6 <= 0 )
return ( V_6 ) ;
}
if ( V_83 == 0 && ! V_181 )
return 0 ;
V_184 = & ( V_12 -> V_16 -> V_190 ) ;
V_185 = & ( V_12 -> V_16 -> V_187 ) ;
V_38 = V_12 -> V_43 ;
if ( ( V_38 == NULL ) ||
( V_12 -> V_191 == NULL ) ||
( F_57 ( V_12 -> V_192 ) == NULL ) )
V_36 = 1 ;
if ( V_36 )
V_40 = 0 ;
else
{
V_40 = F_19 ( V_12 -> V_192 ) ;
if ( V_40 < 0 )
goto V_55;
}
#if 0
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done
&& SSL_version(s) != DTLS1_VERSION && SSL_version(s) != DTLS1_BAD_VER)
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
V_77 = V_185 -> V_18 + V_183 ;
* ( V_77 ++ ) = type & 0xff ;
V_184 -> type = type ;
* ( V_77 ++ ) = ( V_12 -> V_78 >> 8 ) ;
* ( V_77 ++ ) = V_12 -> V_78 & 0xff ;
V_182 = V_77 ;
V_77 += 10 ;
if ( V_12 -> V_191 &&
( F_58 ( V_12 -> V_191 -> V_128 ) & V_193 ) )
V_186 = F_59 ( V_12 -> V_191 -> V_128 ) ;
else
V_186 = 0 ;
V_184 -> V_15 = V_77 + V_186 ;
V_184 -> V_46 = ( int ) V_83 ;
V_184 -> V_44 = ( unsigned char * ) V_18 ;
if ( V_12 -> V_194 != NULL )
{
if ( ! F_60 ( V_12 ) )
{
F_9 ( V_195 , V_196 ) ;
goto V_55;
}
}
else
{
memcpy ( V_184 -> V_15 , V_184 -> V_44 , V_184 -> V_46 ) ;
V_184 -> V_44 = V_184 -> V_15 ;
}
if ( V_40 != 0 )
{
if( V_12 -> V_52 -> V_53 -> V_62 ( V_12 , & ( V_77 [ V_184 -> V_46 + V_186 ] ) , 1 ) < 0 )
goto V_55;
V_184 -> V_46 += V_40 ;
}
V_184 -> V_44 = V_77 ;
V_184 -> V_15 = V_77 ;
if ( V_186 )
{
F_61 ( V_77 , V_186 ) ;
V_184 -> V_46 += V_186 ;
}
V_12 -> V_52 -> V_53 -> V_54 ( V_12 , 1 ) ;
F_62 ( V_12 -> V_29 -> V_197 , V_182 ) ;
memcpy ( V_182 , & ( V_12 -> V_16 -> V_198 [ 2 ] ) , 6 ) ;
V_182 += 6 ;
F_62 ( V_184 -> V_46 , V_182 ) ;
V_184 -> type = type ;
V_184 -> V_46 += V_45 ;
#if 0
if ( type == SSL3_RT_HANDSHAKE || type == SSL3_RT_CHANGE_CIPHER_SPEC)
dtls1_buffer_record(s, wr->data, wr->length,
*((PQ_64BIT *)&(s->s3->write_sequence[0])));
#endif
F_63 ( & ( V_12 -> V_16 -> V_198 [ 0 ] ) ) ;
if ( V_181 )
{
return V_184 -> V_46 ;
}
V_185 -> V_138 = V_183 + V_184 -> V_46 ;
V_185 -> V_199 = 0 ;
V_12 -> V_16 -> V_200 = V_83 ;
V_12 -> V_16 -> V_201 = V_18 ;
V_12 -> V_16 -> V_202 = type ;
V_12 -> V_16 -> V_203 = V_83 ;
return F_56 ( V_12 , type , V_18 , V_83 ) ;
V_55:
return - 1 ;
}
static int F_29 ( T_1 * V_12 , T_6 * V_70 )
{
int V_204 ;
unsigned int V_205 ;
const unsigned char * V_206 = V_12 -> V_16 -> V_84 ;
V_204 = F_1 ( V_206 , V_70 -> V_207 ) ;
if ( V_204 > 0 )
{
memcpy ( V_12 -> V_16 -> V_22 . V_34 , V_206 , 8 ) ;
return 1 ;
}
V_205 = - V_204 ;
if ( V_205 >= sizeof( V_70 -> V_208 ) * 8 )
return 0 ;
else if ( V_70 -> V_208 & ( 1UL << V_205 ) )
return 0 ;
memcpy ( V_12 -> V_16 -> V_22 . V_34 , V_206 , 8 ) ;
return 1 ;
}
static void F_22 ( T_1 * V_12 , T_6 * V_70 )
{
int V_204 ;
unsigned int V_205 ;
const unsigned char * V_206 = V_12 -> V_16 -> V_84 ;
V_204 = F_1 ( V_206 , V_70 -> V_207 ) ;
if ( V_204 > 0 )
{
V_205 = V_204 ;
if ( V_205 < sizeof( V_70 -> V_208 ) * 8 )
V_70 -> V_208 <<= V_205 , V_70 -> V_208 |= 1UL ;
else
V_70 -> V_208 = 1UL ;
memcpy ( V_70 -> V_207 , V_206 , 8 ) ;
}
else {
V_205 = - V_204 ;
if ( V_205 < sizeof( V_70 -> V_208 ) * 8 )
V_70 -> V_208 |= 1UL << V_205 ;
}
}
int F_64 ( T_1 * V_12 )
{
int V_6 , V_91 ;
void (* F_32)( const T_1 * V_92 , int type , int V_94 ) = NULL ;
unsigned char V_18 [ V_139 ] ;
unsigned char * V_209 = & V_18 [ 0 ] ;
V_12 -> V_16 -> V_188 = 0 ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
* V_209 ++ = V_12 -> V_16 -> V_210 [ 0 ] ;
* V_209 ++ = V_12 -> V_16 -> V_210 [ 1 ] ;
#ifdef F_40
if ( V_12 -> V_16 -> V_210 [ 1 ] == F_40 )
{
F_62 ( V_12 -> V_29 -> V_162 , V_209 ) ;
#if 0
if ( s->d1->r_msg_hdr.frag_off == 0)
else
s2n(s->d1->r_msg_hdr.seq, ptr);
#endif
#if 0
fprintf(stderr, "s->d1->handshake_read_seq = %d, s->d1->r_msg_hdr.seq = %d\n",s->d1->handshake_read_seq,s->d1->r_msg_hdr.seq);
#endif
F_65 ( V_12 -> V_29 -> V_211 . V_212 , V_209 ) ;
}
#endif
V_6 = F_55 ( V_12 , V_117 , & V_18 [ 0 ] , sizeof( V_18 ) , 0 ) ;
if ( V_6 <= 0 )
{
V_12 -> V_16 -> V_188 = 1 ;
}
else
{
if ( V_12 -> V_16 -> V_210 [ 0 ] == V_73
#ifdef F_40
|| V_12 -> V_16 -> V_210 [ 1 ] == F_40
#endif
)
( void ) F_66 ( V_12 -> V_213 ) ;
if ( V_12 -> V_131 )
V_12 -> V_131 ( 1 , V_12 -> V_78 , V_117 , V_12 -> V_16 -> V_210 ,
2 , V_12 , V_12 -> V_132 ) ;
if ( V_12 -> V_142 != NULL )
F_32 = V_12 -> V_142 ;
else if ( V_12 -> V_143 -> V_142 != NULL )
F_32 = V_12 -> V_143 -> V_142 ;
if ( F_32 != NULL )
{
V_91 = ( V_12 -> V_16 -> V_210 [ 0 ] << 8 ) | V_12 -> V_16 -> V_210 [ 1 ] ;
F_32 ( V_12 , V_214 , V_91 ) ;
}
}
return ( V_6 ) ;
}
static T_6 *
F_28 ( T_1 * V_12 , V_23 * V_39 , unsigned int * V_79 )
{
* V_79 = 0 ;
if ( V_39 -> V_31 == V_12 -> V_29 -> V_32 )
return & V_12 -> V_29 -> V_70 ;
else if ( V_39 -> V_31 == ( unsigned long ) ( V_12 -> V_29 -> V_32 + 1 ) &&
( V_39 -> type == V_88 ||
V_39 -> type == V_117 ) )
{
* V_79 = 1 ;
return & V_12 -> V_29 -> V_215 ;
}
return NULL ;
}
void
F_49 ( T_1 * V_12 , int V_216 )
{
unsigned char * V_206 ;
unsigned int V_217 = sizeof( V_12 -> V_16 -> V_84 ) ;
if ( V_216 & V_161 )
{
V_206 = V_12 -> V_16 -> V_84 ;
V_12 -> V_29 -> V_32 ++ ;
memcpy ( & ( V_12 -> V_29 -> V_70 ) , & ( V_12 -> V_29 -> V_215 ) , sizeof( T_6 ) ) ;
memset ( & ( V_12 -> V_29 -> V_215 ) , 0x00 , sizeof( T_6 ) ) ;
}
else
{
V_206 = V_12 -> V_16 -> V_198 ;
memcpy ( V_12 -> V_29 -> V_218 , V_206 , sizeof( V_12 -> V_16 -> V_198 ) ) ;
V_12 -> V_29 -> V_197 ++ ;
}
memset ( V_206 , 0x00 , V_217 ) ;
}
static void
F_30 ( T_1 * V_12 )
{
memset ( & ( V_12 -> V_29 -> V_219 ) , 0x00 , sizeof( struct V_220 ) ) ;
}
