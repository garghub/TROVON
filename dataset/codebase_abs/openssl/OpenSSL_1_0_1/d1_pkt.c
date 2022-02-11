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
memcpy ( & ( V_12 -> V_16 -> V_24 [ 2 ] ) , & ( V_14 -> V_19 [ 5 ] ) , 6 ) ;
return ( 1 ) ;
}
static int
F_4 ( T_1 * V_12 , T_4 * V_25 , unsigned char * V_26 )
{
T_3 * V_14 ;
T_2 * V_13 ;
if ( F_5 ( V_25 -> V_27 ) >= 100 )
return 0 ;
V_14 = F_6 ( sizeof( T_3 ) ) ;
V_13 = F_7 ( V_26 , V_14 ) ;
if ( V_14 == NULL || V_13 == NULL )
{
if ( V_14 != NULL ) F_3 ( V_14 ) ;
if ( V_13 != NULL ) F_8 ( V_13 ) ;
F_9 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
V_14 -> V_19 = V_12 -> V_19 ;
V_14 -> V_20 = V_12 -> V_20 ;
memcpy ( & ( V_14 -> V_17 ) , & ( V_12 -> V_16 -> V_17 ) , sizeof( V_21 ) ) ;
memcpy ( & ( V_14 -> V_22 ) , & ( V_12 -> V_16 -> V_22 ) , sizeof( V_23 ) ) ;
V_13 -> V_15 = V_14 ;
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) &&
( V_12 -> V_30 == V_31 || V_12 -> V_30 == V_32 ) ) {
F_13 ( F_12 ( V_12 ) , V_33 , sizeof( V_14 -> V_34 ) , & V_14 -> V_34 ) ;
}
#endif
if ( F_14 ( V_25 -> V_27 , V_13 ) == NULL )
{
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( 0 ) ;
}
V_12 -> V_19 = NULL ;
V_12 -> V_20 = 0 ;
memset ( & ( V_12 -> V_16 -> V_17 ) , 0 , sizeof( V_21 ) ) ;
memset ( & ( V_12 -> V_16 -> V_22 ) , 0 , sizeof( V_23 ) ) ;
if ( ! F_15 ( V_12 ) )
{
F_9 ( V_28 , V_29 ) ;
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int
F_16 ( T_1 * V_12 , T_4 * V_25 )
{
T_2 * V_13 ;
V_13 = F_17 ( V_25 -> V_27 ) ;
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
F_18 ( T_1 * V_12 )
{
T_2 * V_13 ;
V_13 = F_19 ( V_12 -> V_35 -> V_36 . V_27 ) ;
if ( V_13 )
{
if ( V_12 -> V_35 -> V_36 . V_37 != V_12 -> V_35 -> V_38 )
return ( 1 ) ;
while ( F_19 ( V_12 -> V_35 -> V_36 . V_27 ) )
{
F_20 ( V_12 ) ;
if ( ! F_21 ( V_12 ) )
return ( 0 ) ;
F_4 ( V_12 , & ( V_12 -> V_35 -> V_39 ) ,
V_12 -> V_16 -> V_22 . V_40 ) ;
}
}
V_12 -> V_35 -> V_39 . V_37 = V_12 -> V_35 -> V_38 ;
V_12 -> V_35 -> V_36 . V_37 = V_12 -> V_35 -> V_38 + 1 ;
return ( 1 ) ;
}
static int
F_21 ( T_1 * V_12 )
{
int V_6 , V_41 ;
int V_42 = 0 ;
int V_43 ;
T_5 * V_44 ;
V_23 * V_45 ;
unsigned int V_46 ;
unsigned char V_47 [ V_48 ] ;
int V_49 = 0 ;
unsigned char * V_50 = NULL ;
V_45 = & ( V_12 -> V_16 -> V_22 ) ;
V_44 = V_12 -> V_51 ;
V_45 -> V_52 = & ( V_12 -> V_19 [ V_53 ] ) ;
if ( V_45 -> V_54 > V_55 )
{
V_41 = V_56 ;
F_9 ( V_57 , V_58 ) ;
goto V_59;
}
V_45 -> V_15 = V_45 -> V_52 ;
V_43 = V_12 -> V_60 -> V_61 -> V_62 ( V_12 , 0 ) ;
if ( V_43 <= 0 )
{
V_49 = 1 ;
}
#ifdef F_22
printf ( L_1 , V_45 -> V_54 ) ;
{ unsigned int V_63 ; for ( V_63 = 0 ; V_63 < V_45 -> V_54 ; V_63 ++ ) printf ( L_2 , V_45 -> V_15 [ V_63 ] , ( ( V_63 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
if ( ( V_44 == NULL ) ||
( V_12 -> V_64 == NULL ) ||
( V_12 -> V_65 == NULL ) )
V_42 = 1 ;
if ( ! V_42 )
{
int V_66 ;
V_66 = F_23 ( V_12 -> V_65 ) ;
F_24 ( V_66 >= 0 ) ;
V_46 = V_66 ;
if ( V_45 -> V_54 > V_67 + V_46 )
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
V_49 = 1 ;
#endif
}
if ( V_45 -> V_54 >= V_46 )
{
V_45 -> V_54 -= V_46 ;
V_50 = & V_45 -> V_15 [ V_45 -> V_54 ] ;
}
else
V_45 -> V_54 = 0 ;
V_6 = V_12 -> V_60 -> V_61 -> V_50 ( V_12 , V_47 , 0 ) ;
if ( V_6 < 0 || V_50 == NULL || memcmp ( V_47 , V_50 , V_46 ) != 0 )
{
V_49 = 1 ;
}
}
if ( V_49 )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_68;
}
if ( V_12 -> V_69 != NULL )
{
if ( V_45 -> V_54 > V_67 )
{
V_41 = V_56 ;
F_9 ( V_57 , V_70 ) ;
goto V_59;
}
if ( ! F_25 ( V_12 ) )
{
V_41 = V_71 ;
F_9 ( V_57 , V_72 ) ;
goto V_59;
}
}
if ( V_45 -> V_54 > V_73 )
{
V_41 = V_56 ;
F_9 ( V_57 , V_74 ) ;
goto V_59;
}
V_45 -> V_75 = 0 ;
V_12 -> V_20 = 0 ;
F_26 ( V_12 , & ( V_12 -> V_35 -> V_76 ) ) ;
return ( 1 ) ;
V_59:
F_27 ( V_12 , V_77 , V_41 ) ;
V_68:
return ( 0 ) ;
}
int F_28 ( T_1 * V_12 )
{
int V_78 , V_79 ;
int V_6 , V_80 ;
V_23 * V_45 ;
unsigned char * V_81 = NULL ;
unsigned short V_82 ;
T_6 * V_76 ;
unsigned int V_83 ;
V_45 = & ( V_12 -> V_16 -> V_22 ) ;
F_18 ( V_12 ) ;
if ( F_29 ( V_12 ) )
return 1 ;
V_84:
if ( ( V_12 -> V_85 != V_86 ) ||
( V_12 -> V_20 < V_53 ) )
{
V_80 = F_30 ( V_12 , V_53 , V_12 -> V_16 -> V_17 . V_87 , 0 ) ;
if ( V_80 <= 0 ) return ( V_80 ) ;
if ( V_12 -> V_20 != V_53 )
{
V_12 -> V_20 = 0 ;
goto V_84;
}
V_12 -> V_85 = V_86 ;
V_81 = V_12 -> V_19 ;
V_45 -> type = * ( V_81 ++ ) ;
V_78 = * ( V_81 ++ ) ;
V_79 = * ( V_81 ++ ) ;
V_82 = ( V_78 << 8 ) | V_79 ;
F_31 ( V_81 , V_45 -> V_37 ) ;
memcpy ( & ( V_12 -> V_16 -> V_24 [ 2 ] ) , V_81 , 6 ) ;
V_81 += 6 ;
F_31 ( V_81 , V_45 -> V_54 ) ;
if ( ! V_12 -> V_88 )
{
if ( V_82 != V_12 -> V_82 )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
}
if ( ( V_82 & 0xff00 ) != ( V_12 -> V_82 & 0xff00 ) )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
if ( V_45 -> V_54 > V_55 )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
}
if ( V_45 -> V_54 > V_12 -> V_20 - V_53 )
{
V_6 = V_45 -> V_54 ;
V_80 = F_30 ( V_12 , V_6 , V_6 , 1 ) ;
if ( V_80 <= 0 ) return ( V_80 ) ;
if ( V_80 != V_6 )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
}
V_12 -> V_85 = V_89 ;
V_76 = F_32 ( V_12 , V_45 , & V_83 ) ;
if ( V_76 == NULL )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
#ifndef F_10
if ( ! F_11 ( F_12 ( V_12 ) ) )
{
#endif
if ( ! ( V_12 -> V_35 -> V_90 && V_45 -> type == V_91 &&
* V_81 == V_92 ) &&
! F_33 ( V_12 , V_76 ) )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
#ifndef F_10
}
#endif
if ( V_45 -> V_54 == 0 ) goto V_84;
if ( V_83 )
{
if ( ( F_34 ( V_12 ) || V_12 -> V_93 ) && ! V_12 -> V_35 -> V_90 )
{
F_4 ( V_12 , & ( V_12 -> V_35 -> V_36 ) , V_45 -> V_40 ) ;
}
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
if ( ! F_21 ( V_12 ) )
{
V_45 -> V_54 = 0 ;
V_12 -> V_20 = 0 ;
goto V_84;
}
return ( 1 ) ;
}
int F_35 ( T_1 * V_12 , int type , unsigned char * V_18 , int V_87 , int V_94 )
{
int V_41 , V_6 , V_95 , V_3 ;
unsigned int V_80 ;
V_23 * V_45 ;
void (* F_36)( const T_1 * V_96 , int V_97 , int V_98 ) = NULL ;
if ( V_12 -> V_16 -> V_17 . V_18 == NULL )
if ( ! F_15 ( V_12 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_99 ) &&
( type != V_91 ) && type ) ||
( V_94 && ( type != V_99 ) ) )
{
F_9 ( V_100 , V_29 ) ;
return - 1 ;
}
if ( ( V_3 = F_37 ( V_12 , type , V_18 , V_87 , V_94 ) ) )
return V_3 ;
#ifndef F_10
if ( ( ! V_12 -> V_93 && F_34 ( V_12 ) ) ||
( F_11 ( F_12 ( V_12 ) ) &&
( V_12 -> V_30 == V_101 || V_12 -> V_30 == V_102 ) &&
V_12 -> V_16 -> V_103 != 2 ) )
#else
if ( ! V_12 -> V_93 && F_34 ( V_12 ) )
#endif
{
V_6 = V_12 -> V_104 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_100 , V_105 ) ;
return ( - 1 ) ;
}
}
V_106:
V_12 -> V_107 = V_108 ;
V_45 = & ( V_12 -> V_16 -> V_22 ) ;
if ( V_12 -> V_30 == V_109 && V_45 -> V_54 == 0 )
{
T_2 * V_13 ;
V_13 = F_17 ( V_12 -> V_35 -> V_110 . V_27 ) ;
if ( V_13 )
{
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) )
{
T_3 * V_14 = ( T_3 * ) V_13 -> V_15 ;
F_13 ( F_12 ( V_12 ) , V_111 , sizeof( V_14 -> V_34 ) , & V_14 -> V_34 ) ;
}
#endif
F_2 ( V_12 , V_13 ) ;
F_3 ( V_13 -> V_15 ) ;
F_8 ( V_13 ) ;
}
}
if ( F_38 ( V_12 ) > 0 )
goto V_106;
if ( ( V_45 -> V_54 == 0 ) || ( V_12 -> V_85 == V_86 ) )
{
V_3 = F_28 ( V_12 ) ;
if ( V_3 <= 0 )
{
V_3 = F_39 ( V_12 , V_3 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
else
goto V_106;
}
}
if ( V_12 -> V_16 -> V_112
&& ( V_45 -> type != V_91 ) )
{
F_4 ( V_12 , & ( V_12 -> V_35 -> V_110 ) , V_45 -> V_40 ) ;
V_45 -> V_54 = 0 ;
goto V_106;
}
if ( V_12 -> V_113 & V_114 )
{
V_45 -> V_54 = 0 ;
V_12 -> V_107 = V_108 ;
return ( 0 ) ;
}
if ( type == V_45 -> type )
{
if ( F_34 ( V_12 ) && ( type == V_99 ) &&
( V_12 -> V_64 == NULL ) )
{
V_41 = V_115 ;
F_9 ( V_100 , V_116 ) ;
goto V_59;
}
if ( V_87 <= 0 ) return ( V_87 ) ;
if ( ( unsigned int ) V_87 > V_45 -> V_54 )
V_80 = V_45 -> V_54 ;
else
V_80 = ( unsigned int ) V_87 ;
memcpy ( V_18 , & ( V_45 -> V_15 [ V_45 -> V_75 ] ) , V_80 ) ;
if ( ! V_94 )
{
V_45 -> V_54 -= V_80 ;
V_45 -> V_75 += V_80 ;
if ( V_45 -> V_54 == 0 )
{
V_12 -> V_85 = V_89 ;
V_45 -> V_75 = 0 ;
}
}
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) &&
V_45 -> type == V_99 &&
( V_12 -> V_30 == V_101 || V_12 -> V_30 == V_102 ) )
{
V_12 -> V_107 = V_117 ;
F_40 ( F_12 ( V_12 ) ) ;
F_41 ( F_12 ( V_12 ) ) ;
}
if ( F_11 ( F_12 ( V_12 ) ) &&
V_12 -> V_35 -> V_118 && ! F_42 ( F_12 ( V_12 ) ) )
{
V_12 -> V_113 |= V_114 ;
return ( 0 ) ;
}
#endif
return ( V_80 ) ;
}
{
unsigned int V_119 , V_120 = 0 ;
unsigned char * V_121 = NULL ;
unsigned int * V_122 = NULL ;
if ( V_45 -> type == V_91 )
{
V_120 = sizeof V_12 -> V_35 -> V_123 ;
V_121 = V_12 -> V_35 -> V_123 ;
V_122 = & V_12 -> V_35 -> V_124 ;
}
else if ( V_45 -> type == V_125 )
{
V_120 = sizeof( V_12 -> V_35 -> V_126 ) ;
V_121 = V_12 -> V_35 -> V_126 ;
V_122 = & V_12 -> V_35 -> V_127 ;
}
#ifndef F_43
else if ( V_45 -> type == V_128 )
{
F_44 ( V_12 ) ;
V_45 -> V_54 = 0 ;
V_12 -> V_107 = V_117 ;
F_40 ( F_12 ( V_12 ) ) ;
F_41 ( F_12 ( V_12 ) ) ;
return ( - 1 ) ;
}
#endif
else if ( V_45 -> type != V_129 )
{
if ( V_45 -> type == V_99 )
{
T_7 * V_130 ;
V_12 -> V_16 -> V_103 = 2 ;
V_130 = F_12 ( V_12 ) ;
V_12 -> V_107 = V_117 ;
F_40 ( V_130 ) ;
F_41 ( V_130 ) ;
return ( - 1 ) ;
}
V_41 = V_115 ;
F_9 ( V_100 , V_131 ) ;
goto V_59;
}
if ( V_120 > 0 )
{
if ( V_45 -> V_54 < V_120 )
{
#ifdef F_45
T_8 T_9
#endif
V_12 -> V_85 = V_89 ;
V_45 -> V_54 = 0 ;
goto V_106;
}
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ )
{
V_121 [ V_119 ] = V_45 -> V_15 [ V_45 -> V_75 ++ ] ;
V_45 -> V_54 -- ;
}
* V_122 = V_120 ;
}
}
if ( ( ! V_12 -> V_132 ) &&
( V_12 -> V_35 -> V_124 >= V_133 ) &&
( V_12 -> V_35 -> V_123 [ 0 ] == V_134 ) &&
( V_12 -> V_51 != NULL ) && ( V_12 -> V_51 -> V_135 != NULL ) )
{
V_12 -> V_35 -> V_124 = 0 ;
if ( ( V_12 -> V_35 -> V_123 [ 1 ] != 0 ) ||
( V_12 -> V_35 -> V_123 [ 2 ] != 0 ) ||
( V_12 -> V_35 -> V_123 [ 3 ] != 0 ) )
{
V_41 = V_136 ;
F_9 ( V_100 , V_137 ) ;
goto V_68;
}
if ( V_12 -> V_138 )
V_12 -> V_138 ( 0 , V_12 -> V_82 , V_91 ,
V_12 -> V_35 -> V_123 , 4 , V_12 , V_12 -> V_139 ) ;
if ( F_46 ( V_12 ) &&
! ( V_12 -> V_16 -> V_140 & V_141 ) &&
! V_12 -> V_16 -> V_142 )
{
V_12 -> V_143 = 1 ;
F_47 ( V_12 ) ;
if ( F_48 ( V_12 ) )
{
V_6 = V_12 -> V_104 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_100 , V_105 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_144 & V_145 ) )
{
if ( V_12 -> V_16 -> V_17 . V_146 == 0 )
{
T_7 * V_130 ;
V_12 -> V_107 = V_117 ;
V_130 = F_12 ( V_12 ) ;
F_40 ( V_130 ) ;
F_41 ( V_130 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_106;
}
if ( V_12 -> V_35 -> V_127 >= V_147 )
{
int V_148 = V_12 -> V_35 -> V_126 [ 0 ] ;
int V_149 = V_12 -> V_35 -> V_126 [ 1 ] ;
V_12 -> V_35 -> V_127 = 0 ;
if ( V_12 -> V_138 )
V_12 -> V_138 ( 0 , V_12 -> V_82 , V_125 ,
V_12 -> V_35 -> V_126 , 2 , V_12 , V_12 -> V_139 ) ;
if ( V_12 -> V_150 != NULL )
F_36 = V_12 -> V_150 ;
else if ( V_12 -> V_151 -> V_150 != NULL )
F_36 = V_12 -> V_151 -> V_150 ;
if ( F_36 != NULL )
{
V_95 = ( V_148 << 8 ) | V_149 ;
F_36 ( V_12 , V_152 , V_95 ) ;
}
if ( V_148 == 1 )
{
V_12 -> V_16 -> V_153 = V_149 ;
if ( V_149 == V_154 )
{
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) &&
F_42 ( F_12 ( V_12 ) ) )
{
V_12 -> V_35 -> V_118 = 1 ;
V_12 -> V_107 = V_117 ;
F_40 ( F_12 ( V_12 ) ) ;
F_41 ( F_12 ( V_12 ) ) ;
return - 1 ;
}
#endif
V_12 -> V_113 |= V_114 ;
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
else if ( V_148 == 2 )
{
char V_155 [ 16 ] ;
V_12 -> V_107 = V_108 ;
V_12 -> V_16 -> V_156 = V_149 ;
F_9 ( V_100 , V_157 + V_149 ) ;
F_49 ( V_155 , sizeof V_155 , L_4 , V_149 ) ;
F_50 ( 2 , L_5 , V_155 ) ;
V_12 -> V_113 |= V_114 ;
F_51 ( V_12 -> V_151 , V_12 -> V_51 ) ;
return ( 0 ) ;
}
else
{
V_41 = V_158 ;
F_9 ( V_100 , V_159 ) ;
goto V_59;
}
goto V_106;
}
if ( V_12 -> V_113 & V_160 )
{
V_12 -> V_107 = V_108 ;
V_45 -> V_54 = 0 ;
return ( 0 ) ;
}
if ( V_45 -> type == V_129 )
{
struct V_161 V_162 ;
unsigned int V_163 = V_164 ;
F_52 ( V_45 -> V_15 , & V_162 ) ;
if ( V_12 -> V_82 == V_165 )
V_163 = 3 ;
if ( ( V_45 -> V_54 != V_163 ) ||
( V_45 -> V_75 != 0 ) || ( V_45 -> V_15 [ 0 ] != V_166 ) )
{
V_6 = V_158 ;
F_9 ( V_100 , V_167 ) ;
goto V_68;
}
V_45 -> V_54 = 0 ;
if ( V_12 -> V_138 )
V_12 -> V_138 ( 0 , V_12 -> V_82 , V_129 ,
V_45 -> V_15 , 1 , V_12 , V_12 -> V_139 ) ;
if ( ! V_12 -> V_35 -> V_168 )
{
goto V_106;
}
V_12 -> V_35 -> V_168 = 0 ;
V_12 -> V_16 -> V_112 = 1 ;
if ( ! F_53 ( V_12 ) )
goto V_68;
F_54 ( V_12 , V_169 ) ;
if ( V_12 -> V_82 == V_165 )
V_12 -> V_35 -> V_170 ++ ;
#ifndef F_10
F_13 ( F_55 ( V_12 ) , V_171 , 1 , NULL ) ;
#endif
goto V_106;
}
if ( ( V_12 -> V_35 -> V_124 >= V_133 ) &&
! V_12 -> V_93 )
{
struct V_172 V_173 ;
F_56 ( V_45 -> V_15 , & V_173 ) ;
if( V_45 -> V_37 != V_12 -> V_35 -> V_38 )
{
V_45 -> V_54 = 0 ;
goto V_106;
}
if ( V_173 . type == V_174 )
{
if ( F_57 ( V_12 ) < 0 )
return - 1 ;
F_58 ( V_12 ) ;
V_45 -> V_54 = 0 ;
goto V_106;
}
if ( ( ( V_12 -> V_30 & V_175 ) == V_109 ) &&
! ( V_12 -> V_16 -> V_140 & V_141 ) )
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
V_12 -> V_30 = V_12 -> V_132 ? V_176 : V_177 ;
#endif
V_12 -> V_142 = 1 ;
V_12 -> V_143 = 1 ;
}
V_6 = V_12 -> V_104 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_100 , V_105 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_144 & V_145 ) )
{
if ( V_12 -> V_16 -> V_17 . V_146 == 0 )
{
T_7 * V_130 ;
V_12 -> V_107 = V_117 ;
V_130 = F_12 ( V_12 ) ;
F_40 ( V_130 ) ;
F_41 ( V_130 ) ;
return ( - 1 ) ;
}
}
goto V_106;
}
switch ( V_45 -> type )
{
default:
#ifndef F_59
if ( V_12 -> V_82 == V_178 )
{
V_45 -> V_54 = 0 ;
goto V_106;
}
#endif
V_41 = V_115 ;
F_9 ( V_100 , V_131 ) ;
goto V_59;
case V_129 :
case V_125 :
case V_91 :
V_41 = V_115 ;
F_9 ( V_100 , V_29 ) ;
goto V_59;
case V_99 :
if ( V_12 -> V_16 -> V_103 &&
( V_12 -> V_16 -> V_179 != 0 ) &&
( (
( V_12 -> V_30 & V_177 ) &&
( V_12 -> V_30 >= V_180 ) &&
( V_12 -> V_30 <= V_181 )
) || (
( V_12 -> V_30 & V_176 ) &&
( V_12 -> V_30 <= V_182 ) &&
( V_12 -> V_30 >= V_183 )
)
) )
{
V_12 -> V_16 -> V_103 = 2 ;
return ( - 1 ) ;
}
else
{
V_41 = V_115 ;
F_9 ( V_100 , V_131 ) ;
goto V_59;
}
}
V_59:
F_27 ( V_12 , V_77 , V_41 ) ;
V_68:
return ( - 1 ) ;
}
int
F_60 ( T_1 * V_12 , int type , const void * V_184 , int V_87 )
{
int V_6 ;
#ifndef F_10
if ( ( F_34 ( V_12 ) && ! V_12 -> V_93 ) ||
( F_11 ( F_55 ( V_12 ) ) &&
( V_12 -> V_30 == V_101 || V_12 -> V_30 == V_102 ) ) )
#else
if ( F_34 ( V_12 ) && ! V_12 -> V_93 )
#endif
{
V_6 = V_12 -> V_104 ( V_12 ) ;
if ( V_6 < 0 ) return ( V_6 ) ;
if ( V_6 == 0 )
{
F_9 ( V_185 , V_105 ) ;
return - 1 ;
}
}
if ( V_87 > V_73 )
{
F_9 ( V_185 , V_186 ) ;
return - 1 ;
}
V_6 = F_61 ( V_12 , type , V_184 , V_87 ) ;
return V_6 ;
}
static int
F_37 ( T_1 * V_12 , int type , unsigned char * V_18 ,
int V_87 , int V_94 )
{
if ( ( type == V_91 ) && ( V_12 -> V_35 -> V_124 > 0 ) )
{
unsigned char * V_187 = V_12 -> V_35 -> V_123 ;
unsigned char * V_188 = V_18 ;
unsigned int V_119 , V_80 ;
V_80 = 0 ;
while ( ( V_87 > 0 ) && ( V_12 -> V_35 -> V_124 > 0 ) )
{
* V_188 ++ = * V_187 ++ ;
V_87 -- ; V_12 -> V_35 -> V_124 -- ;
V_80 ++ ;
}
for ( V_119 = 0 ; V_119 < V_12 -> V_35 -> V_124 ; V_119 ++ )
V_12 -> V_35 -> V_123 [ V_119 ] = * V_187 ++ ;
return V_80 ;
}
return 0 ;
}
int F_61 ( T_1 * V_12 , int type , const void * V_18 , int V_87 )
{
int V_6 ;
F_24 ( V_87 <= V_73 ) ;
V_12 -> V_107 = V_108 ;
V_6 = F_62 ( V_12 , type , V_18 , V_87 , 0 ) ;
return V_6 ;
}
int F_62 ( T_1 * V_12 , int type , const unsigned char * V_18 , unsigned int V_87 , int V_189 )
{
unsigned char * V_81 , * V_190 ;
int V_6 , V_46 , V_42 = 0 ;
int V_191 = 0 ;
V_23 * V_192 ;
V_21 * V_193 ;
T_5 * V_44 ;
int V_194 ;
if ( V_12 -> V_16 -> V_195 . V_146 != 0 )
{
F_24 ( 0 ) ;
return ( F_63 ( V_12 , type , V_18 , V_87 ) ) ;
}
if ( V_12 -> V_16 -> V_196 )
{
V_6 = V_12 -> V_60 -> V_197 ( V_12 ) ;
if ( V_6 <= 0 )
return ( V_6 ) ;
}
if ( V_87 == 0 && ! V_189 )
return 0 ;
V_192 = & ( V_12 -> V_16 -> V_198 ) ;
V_193 = & ( V_12 -> V_16 -> V_195 ) ;
V_44 = V_12 -> V_51 ;
if ( ( V_44 == NULL ) ||
( V_12 -> V_199 == NULL ) ||
( F_64 ( V_12 -> V_200 ) == NULL ) )
V_42 = 1 ;
if ( V_42 )
V_46 = 0 ;
else
{
V_46 = F_23 ( V_12 -> V_200 ) ;
if ( V_46 < 0 )
goto V_68;
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
V_81 = V_193 -> V_18 + V_191 ;
* ( V_81 ++ ) = type & 0xff ;
V_192 -> type = type ;
* ( V_81 ++ ) = ( V_12 -> V_82 >> 8 ) ;
* ( V_81 ++ ) = V_12 -> V_82 & 0xff ;
V_190 = V_81 ;
V_81 += 10 ;
if ( V_12 -> V_199 &&
( F_65 ( V_12 -> V_199 -> V_135 ) & V_201 ) )
V_194 = F_66 ( V_12 -> V_199 -> V_135 ) ;
else
V_194 = 0 ;
V_192 -> V_15 = V_81 + V_194 ;
V_192 -> V_54 = ( int ) V_87 ;
V_192 -> V_52 = ( unsigned char * ) V_18 ;
if ( V_12 -> V_202 != NULL )
{
if ( ! F_67 ( V_12 ) )
{
F_9 ( V_203 , V_204 ) ;
goto V_68;
}
}
else
{
memcpy ( V_192 -> V_15 , V_192 -> V_52 , V_192 -> V_54 ) ;
V_192 -> V_52 = V_192 -> V_15 ;
}
if ( V_46 != 0 )
{
if( V_12 -> V_60 -> V_61 -> V_50 ( V_12 , & ( V_81 [ V_192 -> V_54 + V_194 ] ) , 1 ) < 0 )
goto V_68;
V_192 -> V_54 += V_46 ;
}
V_192 -> V_52 = V_81 ;
V_192 -> V_15 = V_81 ;
if ( V_194 )
{
F_68 ( V_81 , V_194 ) ;
V_192 -> V_54 += V_194 ;
}
V_12 -> V_60 -> V_61 -> V_62 ( V_12 , 1 ) ;
F_69 ( V_12 -> V_35 -> V_205 , V_190 ) ;
memcpy ( V_190 , & ( V_12 -> V_16 -> V_206 [ 2 ] ) , 6 ) ;
V_190 += 6 ;
F_69 ( V_192 -> V_54 , V_190 ) ;
V_192 -> type = type ;
V_192 -> V_54 += V_53 ;
#if 0
if ( type == SSL3_RT_HANDSHAKE || type == SSL3_RT_CHANGE_CIPHER_SPEC)
dtls1_buffer_record(s, wr->data, wr->length,
*((PQ_64BIT *)&(s->s3->write_sequence[0])));
#endif
F_70 ( & ( V_12 -> V_16 -> V_206 [ 0 ] ) ) ;
if ( V_189 )
{
return V_192 -> V_54 ;
}
V_193 -> V_146 = V_191 + V_192 -> V_54 ;
V_193 -> V_207 = 0 ;
V_12 -> V_16 -> V_208 = V_87 ;
V_12 -> V_16 -> V_209 = V_18 ;
V_12 -> V_16 -> V_210 = type ;
V_12 -> V_16 -> V_211 = V_87 ;
return F_63 ( V_12 , type , V_18 , V_87 ) ;
V_68:
return - 1 ;
}
static int F_33 ( T_1 * V_12 , T_6 * V_76 )
{
int V_212 ;
unsigned int V_213 ;
const unsigned char * V_214 = V_12 -> V_16 -> V_24 ;
V_212 = F_1 ( V_214 , V_76 -> V_215 ) ;
if ( V_212 > 0 )
{
memcpy ( V_12 -> V_16 -> V_22 . V_40 , V_214 , 8 ) ;
return 1 ;
}
V_213 = - V_212 ;
if ( V_213 >= sizeof( V_76 -> V_216 ) * 8 )
return 0 ;
else if ( V_76 -> V_216 & ( 1UL << V_213 ) )
return 0 ;
memcpy ( V_12 -> V_16 -> V_22 . V_40 , V_214 , 8 ) ;
return 1 ;
}
static void F_26 ( T_1 * V_12 , T_6 * V_76 )
{
int V_212 ;
unsigned int V_213 ;
const unsigned char * V_214 = V_12 -> V_16 -> V_24 ;
V_212 = F_1 ( V_214 , V_76 -> V_215 ) ;
if ( V_212 > 0 )
{
V_213 = V_212 ;
if ( V_213 < sizeof( V_76 -> V_216 ) * 8 )
V_76 -> V_216 <<= V_213 , V_76 -> V_216 |= 1UL ;
else
V_76 -> V_216 = 1UL ;
memcpy ( V_76 -> V_215 , V_214 , 8 ) ;
}
else {
V_213 = - V_212 ;
if ( V_213 < sizeof( V_76 -> V_216 ) * 8 )
V_76 -> V_216 |= 1UL << V_213 ;
}
}
int F_71 ( T_1 * V_12 )
{
int V_6 , V_95 ;
void (* F_36)( const T_1 * V_96 , int type , int V_98 ) = NULL ;
unsigned char V_18 [ V_147 ] ;
unsigned char * V_217 = & V_18 [ 0 ] ;
V_12 -> V_16 -> V_196 = 0 ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
* V_217 ++ = V_12 -> V_16 -> V_218 [ 0 ] ;
* V_217 ++ = V_12 -> V_16 -> V_218 [ 1 ] ;
#ifdef F_45
if ( V_12 -> V_16 -> V_218 [ 1 ] == F_45 )
{
F_69 ( V_12 -> V_35 -> V_170 , V_217 ) ;
#if 0
if ( s->d1->r_msg_hdr.frag_off == 0)
else
s2n(s->d1->r_msg_hdr.seq, ptr);
#endif
#if 0
fprintf(stderr, "s->d1->handshake_read_seq = %d, s->d1->r_msg_hdr.seq = %d\n",s->d1->handshake_read_seq,s->d1->r_msg_hdr.seq);
#endif
F_72 ( V_12 -> V_35 -> V_219 . V_220 , V_217 ) ;
}
#endif
V_6 = F_62 ( V_12 , V_125 , & V_18 [ 0 ] , sizeof( V_18 ) , 0 ) ;
if ( V_6 <= 0 )
{
V_12 -> V_16 -> V_196 = 1 ;
}
else
{
if ( V_12 -> V_16 -> V_218 [ 0 ] == V_77
#ifdef F_45
|| V_12 -> V_16 -> V_218 [ 1 ] == F_45
#endif
)
( void ) F_73 ( V_12 -> V_221 ) ;
if ( V_12 -> V_138 )
V_12 -> V_138 ( 1 , V_12 -> V_82 , V_125 , V_12 -> V_16 -> V_218 ,
2 , V_12 , V_12 -> V_139 ) ;
if ( V_12 -> V_150 != NULL )
F_36 = V_12 -> V_150 ;
else if ( V_12 -> V_151 -> V_150 != NULL )
F_36 = V_12 -> V_151 -> V_150 ;
if ( F_36 != NULL )
{
V_95 = ( V_12 -> V_16 -> V_218 [ 0 ] << 8 ) | V_12 -> V_16 -> V_218 [ 1 ] ;
F_36 ( V_12 , V_222 , V_95 ) ;
}
}
return ( V_6 ) ;
}
static T_6 *
F_32 ( T_1 * V_12 , V_23 * V_45 , unsigned int * V_83 )
{
* V_83 = 0 ;
if ( V_45 -> V_37 == V_12 -> V_35 -> V_38 )
return & V_12 -> V_35 -> V_76 ;
else if ( V_45 -> V_37 == ( unsigned long ) ( V_12 -> V_35 -> V_38 + 1 ) &&
( V_45 -> type == V_91 ||
V_45 -> type == V_125 ) )
{
* V_83 = 1 ;
return & V_12 -> V_35 -> V_223 ;
}
return NULL ;
}
void
F_54 ( T_1 * V_12 , int V_224 )
{
unsigned char * V_214 ;
unsigned int V_225 = sizeof( V_12 -> V_16 -> V_24 ) ;
if ( V_224 & V_169 )
{
V_214 = V_12 -> V_16 -> V_24 ;
V_12 -> V_35 -> V_38 ++ ;
memcpy ( & ( V_12 -> V_35 -> V_76 ) , & ( V_12 -> V_35 -> V_223 ) , sizeof( T_6 ) ) ;
memset ( & ( V_12 -> V_35 -> V_223 ) , 0x00 , sizeof( T_6 ) ) ;
}
else
{
V_214 = V_12 -> V_16 -> V_206 ;
memcpy ( V_12 -> V_35 -> V_226 , V_214 , sizeof( V_12 -> V_16 -> V_206 ) ) ;
V_12 -> V_35 -> V_205 ++ ;
}
memset ( V_214 , 0x00 , V_225 ) ;
}
