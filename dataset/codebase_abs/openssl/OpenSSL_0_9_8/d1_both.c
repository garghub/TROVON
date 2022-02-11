static T_1 *
F_1 ( unsigned long V_1 )
{
T_1 * V_2 = NULL ;
unsigned char * V_3 = NULL ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
return NULL ;
V_3 = ( unsigned char * ) F_2 ( V_1
+ V_4 ) ;
if ( V_3 == NULL )
{
F_3 ( V_2 ) ;
return NULL ;
}
V_2 -> V_5 = V_3 ;
return V_2 ;
}
static void
F_4 ( T_1 * V_2 )
{
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
}
int F_5 ( T_2 * V_6 , int type )
{
int V_7 ;
int V_8 ;
unsigned int V_9 , V_10 ;
if ( ! ( F_6 ( V_6 ) & V_11 ) )
{
V_6 -> V_12 -> V_13 =
F_7 ( F_8 ( V_6 ) , V_14 , 0 , NULL ) ;
if ( V_6 -> V_12 -> V_13 < F_9 () )
{
V_6 -> V_12 -> V_13 = 0 ;
V_6 -> V_12 -> V_13 = F_10 ( V_6 -> V_12 -> V_13 ) ;
F_7 ( F_8 ( V_6 ) , V_15 ,
V_6 -> V_12 -> V_13 , NULL ) ;
}
}
#if 0
mtu = s->d1->mtu;
fprintf(stderr, "using MTU = %d\n", mtu);
mtu -= (DTLS1_HM_HEADER_LENGTH + DTLS1_RT_HEADER_LENGTH);
curr_mtu = mtu - BIO_wpending(SSL_get_wbio(s));
if ( curr_mtu > 0)
mtu = curr_mtu;
else if ( ( ret = BIO_flush(SSL_get_wbio(s))) <= 0)
return ret;
if ( BIO_wpending(SSL_get_wbio(s)) + s->init_num >= mtu)
{
ret = BIO_flush(SSL_get_wbio(s));
if ( ret <= 0)
return ret;
mtu = s->d1->mtu - (DTLS1_HM_HEADER_LENGTH + DTLS1_RT_HEADER_LENGTH);
}
OPENSSL_assert(mtu > 0);
#endif
if ( V_6 -> V_16 == 0 && type == V_17 )
F_11 ( V_6 -> V_18 ==
( int ) V_6 -> V_12 -> V_19 . V_20 + V_4 ) ;
V_10 = 0 ;
while( V_6 -> V_18 )
{
V_8 = V_6 -> V_12 -> V_13 - F_12 ( F_8 ( V_6 ) ) -
V_21 ;
if ( V_8 <= V_4 )
{
V_7 = F_13 ( F_8 ( V_6 ) ) ;
if ( V_7 <= 0 )
return V_7 ;
V_8 = V_6 -> V_12 -> V_13 - V_21 ;
}
if ( V_6 -> V_18 > V_8 )
V_9 = V_8 ;
else
V_9 = V_6 -> V_18 ;
if ( type == V_17 )
{
if ( V_6 -> V_16 != 0 )
{
F_11 ( V_6 -> V_16 > V_4 ) ;
V_6 -> V_16 -= V_4 ;
V_6 -> V_18 += V_4 ;
if ( V_9 <= V_4 )
V_9 += V_4 ;
}
F_14 ( V_6 , V_10 ,
V_9 - V_4 ) ;
F_15 ( V_6 , ( unsigned char * ) & V_6 -> V_22 -> V_23 [ V_6 -> V_16 ] ) ;
F_11 ( V_9 >= V_4 ) ;
}
V_7 = F_16 ( V_6 , type , & V_6 -> V_22 -> V_23 [ V_6 -> V_16 ] ,
V_9 ) ;
if ( V_7 < 0 )
{
if ( F_7 ( F_8 ( V_6 ) ,
V_24 , 0 , NULL ) )
V_6 -> V_12 -> V_13 = F_7 ( F_8 ( V_6 ) ,
V_14 , 0 , NULL ) ;
else
return ( - 1 ) ;
}
else
{
F_11 ( V_9 == ( unsigned int ) V_7 ) ;
if ( type == V_17 && ! V_6 -> V_12 -> V_25 )
F_17 ( V_6 ,
( unsigned char * ) & V_6 -> V_22 -> V_23 [ V_6 -> V_16 +
V_4 ] , V_7 - V_4 ) ;
if ( V_7 == V_6 -> V_18 )
{
if ( V_6 -> V_26 )
V_6 -> V_26 ( 1 , V_6 -> V_27 , type , V_6 -> V_22 -> V_23 ,
( V_28 ) ( V_6 -> V_16 + V_6 -> V_18 ) , V_6 ,
V_6 -> V_29 ) ;
V_6 -> V_16 = 0 ;
V_6 -> V_18 = 0 ;
return ( 1 ) ;
}
V_6 -> V_16 += V_7 ;
V_6 -> V_18 -= V_7 ;
V_10 += ( V_7 -= V_4 ) ;
}
}
return ( 0 ) ;
}
long F_18 ( T_2 * V_6 , int V_30 , int V_31 , int V_32 , long V_33 , int * V_34 )
{
int V_35 , V_36 ;
if ( V_6 -> V_37 -> V_38 . V_39 )
{
V_6 -> V_37 -> V_38 . V_39 = 0 ;
if ( ( V_32 >= 0 ) && ( V_6 -> V_37 -> V_38 . V_40 != V_32 ) )
{
V_36 = V_41 ;
F_19 ( V_42 , V_43 ) ;
goto V_44;
}
* V_34 = 1 ;
V_6 -> V_45 = V_6 -> V_22 -> V_23 + V_4 ;
V_6 -> V_18 = ( int ) V_6 -> V_37 -> V_38 . V_46 ;
return V_6 -> V_18 ;
}
do
{
if ( V_6 -> V_12 -> V_47 . V_10 == 0 )
{
memset ( & ( V_6 -> V_12 -> V_47 ) , 0x00 , sizeof( struct V_48 ) ) ;
}
V_35 = F_20 ( V_6 , V_30 , V_31 , V_33 , V_34 ) ;
if ( V_35 == V_49 ||
V_35 == V_50 )
continue;
else if ( V_35 <= 0 && ! * V_34 )
return V_35 ;
if ( V_6 -> V_12 -> V_47 . V_20 == ( unsigned int ) V_6 -> V_18 - V_4 )
{
memset ( & ( V_6 -> V_12 -> V_47 ) , 0x00 , sizeof( struct V_48 ) ) ;
V_6 -> V_12 -> V_51 ++ ;
F_21 ( V_6 ) ;
V_6 -> V_45 = V_6 -> V_22 -> V_23 + V_4 ;
return V_6 -> V_18 - V_4 ;
}
else
V_6 -> V_12 -> V_47 . V_10 = V_35 ;
} while( 1 ) ;
V_44:
F_22 ( V_6 , V_52 , V_36 ) ;
* V_34 = 0 ;
return - 1 ;
}
static int
F_23 ( T_2 * V_6 , unsigned long * V_53 )
{
T_3 * V_54 ;
T_1 * V_2 ;
unsigned long V_55 ;
unsigned char * V_56 ;
V_54 = F_24 ( V_6 -> V_12 -> V_57 ) ;
if ( V_54 == NULL )
return 0 ;
V_2 = ( T_1 * ) V_54 -> V_23 ;
if ( V_6 -> V_12 -> V_51 == V_2 -> V_58 . V_59 &&
V_2 -> V_58 . V_10 <= ( unsigned int ) V_6 -> V_18 - V_4 )
{
F_25 ( V_6 -> V_12 -> V_57 ) ;
V_55 = V_6 -> V_18 - V_4
- V_2 -> V_58 . V_10 ;
V_56 = V_2 -> V_5 ;
memcpy ( & V_6 -> V_22 -> V_23 [ V_6 -> V_18 ] ,
V_56 + V_4 + V_55 ,
V_2 -> V_58 . V_1 - V_55 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
F_26 ( V_54 ) ;
* V_53 = V_2 -> V_58 . V_1 - V_55 ;
return * V_53 ;
}
else
return 0 ;
}
static int
F_27 ( T_2 * V_6 , struct V_48 * V_60 )
{
T_1 * V_2 = NULL ;
T_3 * V_54 = NULL ;
T_4 V_61 ;
V_2 = F_1 ( V_60 -> V_1 ) ;
if ( V_2 == NULL )
goto V_62;
memcpy ( V_2 -> V_5 , & ( V_6 -> V_22 -> V_23 [ V_6 -> V_18 ] ) ,
V_60 -> V_1 + V_4 ) ;
memcpy ( & ( V_2 -> V_58 ) , V_60 , sizeof( * V_60 ) ) ;
F_28 ( & V_61 ) ;
F_29 ( & V_61 , V_60 -> V_59 ) ;
V_54 = F_30 ( V_61 , V_2 ) ;
if ( V_54 == NULL )
goto V_62;
F_31 ( & V_61 ) ;
F_32 ( V_6 -> V_12 -> V_57 , V_54 ) ;
return 1 ;
V_62:
if ( V_2 != NULL ) F_4 ( V_2 ) ;
if ( V_54 != NULL ) F_3 ( V_54 ) ;
return 0 ;
}
static void
F_33 ( T_2 * V_6 , int V_1 )
{
unsigned char * V_56 ;
V_56 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
F_17 ( V_6 , & V_56 [ V_6 -> V_18 - V_1 ] , V_1 ) ;
}
static int
F_34 ( T_2 * V_6 , struct V_48 * V_60 , int * V_34 )
{
int V_35 ;
unsigned char * V_56 ;
if ( ( int ) V_60 -> V_1 && ! F_35 ( V_6 -> V_22 ,
( int ) V_60 -> V_1 + V_4 + V_6 -> V_18 ) )
{
F_19 ( V_63 , V_64 ) ;
goto V_62;
}
V_56 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
if ( V_60 -> V_1 > 0 )
{
V_35 = V_6 -> V_65 -> V_66 ( V_6 , V_17 ,
& V_56 [ V_6 -> V_18 ] ,
V_60 -> V_1 , 0 ) ;
if ( V_35 <= 0 )
{
* V_34 = 0 ;
return V_35 ;
}
}
if ( V_60 -> V_59 > V_6 -> V_12 -> V_51 )
F_27 ( V_6 , V_60 ) ;
else
F_11 ( V_60 -> V_59 < V_6 -> V_12 -> V_51 ) ;
return V_50 ;
V_62:
* V_34 = 0 ;
return - 1 ;
}
static long
F_20 ( T_2 * V_6 , int V_30 , int V_31 , long V_33 , int * V_34 )
{
unsigned char * V_56 ;
unsigned long V_67 , V_10 , V_1 ;
int V_35 , V_36 ;
struct V_48 V_60 ;
unsigned long V_55 ;
if ( F_23 ( V_6 , & V_67 ) )
{
F_33 ( V_6 , V_67 ) ;
V_6 -> V_45 = V_6 -> V_22 -> V_23 + V_4 ;
V_6 -> V_68 = V_31 ;
return 1 ;
}
V_56 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
V_35 = V_6 -> V_65 -> V_66 ( V_6 , V_17 , & V_56 [ V_6 -> V_18 ] ,
V_4 , 0 ) ;
if ( V_35 <= 0 )
{
V_6 -> V_69 = V_70 ;
* V_34 = 0 ;
return V_35 ;
}
F_11 ( V_35 == V_4 ) ;
V_56 += V_6 -> V_18 ;
F_36 ( V_56 , & V_60 ) ;
if ( V_60 . V_59 != V_6 -> V_12 -> V_51 )
return F_34 ( V_6 , & V_60 , V_34 ) ;
V_67 = V_60 . V_20 ;
V_10 = V_60 . V_10 ;
V_1 = V_60 . V_1 ;
if ( V_10 + V_1 > V_67 )
{
V_36 = V_71 ;
F_19 ( V_72 , V_73 ) ;
goto V_44;
}
if ( ! V_6 -> V_74 && V_6 -> V_12 -> V_47 . V_10 == 0 &&
V_56 [ 0 ] == V_75 )
{
if ( V_56 [ 1 ] == 0 && V_56 [ 2 ] == 0 && V_56 [ 3 ] == 0 )
{
if ( V_6 -> V_26 )
V_6 -> V_26 ( 0 , V_6 -> V_27 , V_17 ,
V_56 , V_4 , V_6 ,
V_6 -> V_29 ) ;
V_6 -> V_18 = 0 ;
return F_20 ( V_6 , V_30 , V_31 ,
V_33 , V_34 ) ;
}
else
{
V_36 = V_41 ;
F_19 ( V_72 , V_43 ) ;
goto V_44;
}
}
V_6 -> V_18 += V_35 ;
if ( V_6 -> V_12 -> V_47 . V_10 == 0 )
{
if ( V_67 > ( V_76 - V_4 ) )
{
V_36 = V_71 ;
F_19 ( V_72 , V_73 ) ;
goto V_44;
}
if ( V_67 && ! F_35 ( V_6 -> V_22 , ( int ) V_67
+ V_4 ) )
{
F_19 ( V_72 , V_64 ) ;
goto V_62;
}
if ( V_67 > ( unsigned long ) V_33 )
{
V_36 = V_71 ;
F_19 ( V_72 , V_73 ) ;
goto V_44;
}
V_6 -> V_37 -> V_38 . V_46 = V_67 ;
}
if ( V_1 > ( unsigned long ) V_33 )
{
V_36 = V_71 ;
F_19 ( V_72 , V_73 ) ;
goto V_44;
}
if ( V_1 + V_6 -> V_18 > ( V_76 - V_4 ) )
{
V_36 = V_71 ;
F_19 ( V_72 , V_73 ) ;
goto V_44;
}
if ( V_1 & ! F_35 ( V_6 -> V_22 , ( int ) V_1
+ V_4 + V_6 -> V_18 ) )
{
F_19 ( V_72 , V_64 ) ;
goto V_62;
}
if ( V_6 -> V_12 -> V_47 . V_10 == 0 )
{
V_6 -> V_37 -> V_38 . V_40 = V_60 . type ;
V_6 -> V_12 -> V_47 . type = V_60 . type ;
V_6 -> V_12 -> V_47 . V_20 = V_67 ;
}
V_6 -> V_68 = V_31 ;
V_56 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
if ( V_1 > 0 )
{
V_35 = V_6 -> V_65 -> V_66 ( V_6 , V_17 ,
& V_56 [ V_6 -> V_18 ] ,
V_1 , 0 ) ;
if ( V_35 <= 0 )
{
V_6 -> V_69 = V_70 ;
* V_34 = 0 ;
return V_35 ;
}
}
else
V_35 = 0 ;
F_11 ( V_35 == ( int ) V_1 ) ;
#if 0
if ( msg_hdr.seq > s->d1->handshake_read_seq ||
frag_off > s->init_num - DTLS1_HM_HEADER_LENGTH)
{
dtls1_buffer_handshake_fragment(s, &msg_hdr);
return DTLS1_HM_FRAGMENT_RETRY;
}
if ( msg_hdr.seq < s->d1->handshake_read_seq ||
frag_off + frag_len < s->init_num - DTLS1_HM_HEADER_LENGTH)
{
s->init_num -= DTLS1_HM_HEADER_LENGTH;
return DTLS1_HM_FRAGMENT_RETRY;
}
#endif
V_55 = ( V_6 -> V_18 - V_4 ) - V_10 ;
if ( V_6 -> V_18 > V_4 )
{
memmove ( & ( V_6 -> V_22 -> V_23 [ V_6 -> V_18 ] ) ,
& ( V_6 -> V_22 -> V_23 [ V_6 -> V_18 + V_4 + V_55 ] ) ,
V_1 - V_55 ) ;
V_6 -> V_18 += V_1 - V_55 ;
}
else
V_6 -> V_18 += V_1 ;
F_33 ( V_6 , V_1 - V_55 ) ;
if ( V_6 -> V_26 )
V_6 -> V_26 ( 0 , V_6 -> V_27 , V_17 , V_6 -> V_22 -> V_23 ,
( V_28 ) V_6 -> V_18 , V_6 ,
V_6 -> V_29 ) ;
* V_34 = 1 ;
return V_6 -> V_18 ;
V_44:
F_22 ( V_6 , V_52 , V_36 ) ;
V_6 -> V_18 = 0 ;
V_62:
* V_34 = 0 ;
return ( - 1 ) ;
}
int F_37 ( T_2 * V_6 , int V_77 , int V_78 , const char * V_79 , int V_80 )
{
unsigned char * V_56 , * V_81 ;
int V_35 ;
unsigned long V_67 ;
if ( V_6 -> V_68 == V_77 )
{
V_81 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
V_56 = & ( V_81 [ V_4 ] ) ;
V_35 = V_6 -> V_65 -> V_82 -> V_83 ( V_6 ,
& ( V_6 -> V_37 -> V_84 ) ,
& ( V_6 -> V_37 -> V_85 ) ,
V_79 , V_80 , V_6 -> V_37 -> V_38 . V_86 ) ;
V_6 -> V_37 -> V_38 . V_87 = V_35 ;
memcpy ( V_56 , V_6 -> V_37 -> V_38 . V_86 , V_35 ) ;
V_56 += V_35 ;
V_67 = V_35 ;
#ifdef F_38
V_67 &= 0xffff ;
#endif
V_81 = F_39 ( V_6 , V_81 , V_88 , V_67 , 0 , V_67 ) ;
V_6 -> V_18 = ( int ) V_67 + V_4 ;
V_6 -> V_16 = 0 ;
F_40 ( V_6 , 0 ) ;
V_6 -> V_68 = V_78 ;
}
return ( F_5 ( V_6 , V_17 ) ) ;
}
int F_41 ( T_2 * V_6 , int V_77 , int V_78 )
{
unsigned char * V_56 ;
if ( V_6 -> V_68 == V_77 )
{
V_56 = ( unsigned char * ) V_6 -> V_22 -> V_23 ;
* V_56 ++ = V_89 ;
V_6 -> V_12 -> V_90 = V_6 -> V_12 -> V_91 ;
V_6 -> V_12 -> V_91 ++ ;
F_42 ( V_6 -> V_12 -> V_90 , V_56 ) ;
V_6 -> V_18 = V_92 ;
V_6 -> V_16 = 0 ;
F_43 ( V_6 , V_89 , 0 ,
V_6 -> V_12 -> V_90 , 0 , 0 ) ;
F_40 ( V_6 , 1 ) ;
V_6 -> V_68 = V_78 ;
}
return ( F_5 ( V_6 , V_93 ) ) ;
}
unsigned long F_44 ( T_2 * V_6 , T_5 * V_94 )
{
unsigned char * V_56 ;
int V_95 , V_35 ;
unsigned long V_67 = 3 + V_4 ;
T_6 * V_3 ;
T_7 V_96 ;
T_8 V_97 ;
V_3 = V_6 -> V_22 ;
if ( ! F_35 ( V_3 , 10 ) )
{
F_19 ( V_98 , V_64 ) ;
return ( 0 ) ;
}
if ( V_94 != NULL )
{
if( ! F_45 ( & V_96 , V_6 -> V_99 -> V_100 , NULL , NULL ) )
{
F_19 ( V_98 , V_101 ) ;
return ( 0 ) ;
}
for (; ; )
{
V_95 = F_46 ( V_94 , NULL ) ;
if ( ! F_35 ( V_3 , ( int ) ( V_95 + V_67 + 3 ) ) )
{
F_19 ( V_98 , V_64 ) ;
return ( 0 ) ;
}
V_56 = ( unsigned char * ) & ( V_3 -> V_23 [ V_67 ] ) ;
F_47 ( V_95 , V_56 ) ;
F_46 ( V_94 , & V_56 ) ;
V_67 += V_95 + 3 ;
if ( F_48 ( F_49 ( V_94 ) ,
F_50 ( V_94 ) ) == 0 ) break;
V_35 = F_51 ( & V_96 , V_102 ,
F_50 ( V_94 ) , & V_97 ) ;
if ( V_35 <= 0 ) break;
V_94 = V_97 . V_23 . V_103 ;
F_52 ( V_94 ) ;
}
F_53 ( & V_96 ) ;
}
if ( V_6 -> V_99 -> V_104 != NULL )
for ( V_35 = 0 ; V_35 < F_54 ( V_6 -> V_99 -> V_104 ) ; V_35 ++ )
{
V_94 = F_55 ( V_6 -> V_99 -> V_104 , V_35 ) ;
V_95 = F_46 ( V_94 , NULL ) ;
if ( ! F_35 ( V_3 , ( int ) ( V_95 + V_67 + 3 ) ) )
{
F_19 ( V_98 , V_64 ) ;
return ( 0 ) ;
}
V_56 = ( unsigned char * ) & ( V_3 -> V_23 [ V_67 ] ) ;
F_47 ( V_95 , V_56 ) ;
F_46 ( V_94 , & V_56 ) ;
V_67 += V_95 + 3 ;
}
V_67 -= ( 3 + V_4 ) ;
V_56 = ( unsigned char * ) & ( V_3 -> V_23 [ V_4 ] ) ;
F_47 ( V_67 , V_56 ) ;
V_67 += 3 ;
V_56 = ( unsigned char * ) & ( V_3 -> V_23 [ 0 ] ) ;
V_56 = F_39 ( V_6 , V_56 , V_105 , V_67 , 0 , V_67 ) ;
V_67 += V_4 ;
return ( V_67 ) ;
}
int F_56 ( T_2 * V_6 , int V_106 )
{
T_9 * V_68 ;
T_10 * V_107 ;
int V_108 = 0 ;
if ( V_106 > 0 )
{
fprintf ( V_109 , L_1 , __FILE__ , __LINE__ ) ;
return 1 ;
}
V_107 = F_57 ( V_6 ) ;
if ( ! F_58 ( V_107 ) )
{
return V_106 ;
}
if ( ! F_59 ( V_6 ) )
{
F_60 ( F_57 ( V_6 ) , V_110 ) ;
return V_106 ;
}
V_68 = V_6 -> V_12 ;
V_68 -> V_111 . V_112 ++ ;
if ( V_68 -> V_111 . V_112 > V_113 )
{
F_19 ( V_114 , V_115 ) ;
return 0 ;
}
V_68 -> V_111 . V_116 ++ ;
if ( V_68 -> V_111 . V_116 > V_117 )
{
V_108 = 1 ;
V_68 -> V_111 . V_116 = 1 ;
}
#if 0
item = pqueue_peek(state->rcvd_records);
if ( item )
{
}
else
#endif
#if 0
if ( send_alert)
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
return F_61 ( V_6 ) ;
}
static int
F_61 ( T_2 * V_6 )
{
T_11 V_118 = V_6 -> V_12 -> V_119 ;
T_12 V_120 ;
T_3 * V_54 ;
T_1 * V_2 ;
int V_121 = 0 ;
V_120 = F_62 ( V_118 ) ;
for ( V_54 = F_63 ( & V_120 ) ; V_54 != NULL ; V_54 = F_63 ( & V_120 ) )
{
V_2 = ( T_1 * ) V_54 -> V_23 ;
if ( F_64 ( V_6 , V_2 -> V_58 . V_59 , 0 , & V_121 ) <= 0 &&
V_121 )
{
fprintf ( V_109 , L_2 ) ;
return - 1 ;
}
}
return 1 ;
}
int
F_40 ( T_2 * V_6 , int V_122 )
{
T_3 * V_54 ;
T_1 * V_2 ;
T_4 V_61 ;
F_11 ( V_6 -> V_16 == 0 ) ;
V_2 = F_1 ( V_6 -> V_18 ) ;
memcpy ( V_2 -> V_5 , V_6 -> V_22 -> V_23 , V_6 -> V_18 ) ;
if ( V_122 )
{
F_11 ( V_6 -> V_12 -> V_19 . V_20 +
V_92 == ( unsigned int ) V_6 -> V_18 ) ;
}
else
{
F_11 ( V_6 -> V_12 -> V_19 . V_20 +
V_4 == ( unsigned int ) V_6 -> V_18 ) ;
}
V_2 -> V_58 . V_20 = V_6 -> V_12 -> V_19 . V_20 ;
V_2 -> V_58 . V_59 = V_6 -> V_12 -> V_19 . V_59 ;
V_2 -> V_58 . type = V_6 -> V_12 -> V_19 . type ;
V_2 -> V_58 . V_10 = 0 ;
V_2 -> V_58 . V_1 = V_6 -> V_12 -> V_19 . V_20 ;
V_2 -> V_58 . V_122 = V_122 ;
F_28 ( & V_61 ) ;
F_29 ( & V_61 , V_2 -> V_58 . V_59 ) ;
V_54 = F_30 ( V_61 , V_2 ) ;
F_31 ( & V_61 ) ;
if ( V_54 == NULL )
{
F_4 ( V_2 ) ;
return 0 ;
}
#if 0
fprintf( stderr, "buffered messge: \ttype = %xx\n", msg_buf->type);
fprintf( stderr, "\t\t\t\t\tlen = %d\n", msg_buf->len);
fprintf( stderr, "\t\t\t\t\tseq_num = %d\n", msg_buf->seq_num);
#endif
F_32 ( V_6 -> V_12 -> V_119 , V_54 ) ;
return 1 ;
}
int
F_64 ( T_2 * V_6 , unsigned short V_59 , unsigned long V_10 ,
int * V_121 )
{
int V_7 ;
T_3 * V_54 ;
T_1 * V_2 ;
unsigned long V_123 ;
T_4 V_61 ;
F_28 ( & V_61 ) ;
F_29 ( & V_61 , V_59 ) ;
V_54 = F_65 ( V_6 -> V_12 -> V_119 , V_61 ) ;
F_31 ( & V_61 ) ;
if ( V_54 == NULL )
{
fprintf ( V_109 , L_3 , V_59 ) ;
* V_121 = 0 ;
return 0 ;
}
* V_121 = 1 ;
V_2 = ( T_1 * ) V_54 -> V_23 ;
if ( V_2 -> V_58 . V_122 )
V_123 = V_92 ;
else
V_123 = V_4 ;
memcpy ( V_6 -> V_22 -> V_23 , V_2 -> V_5 ,
V_2 -> V_58 . V_20 + V_123 ) ;
V_6 -> V_18 = V_2 -> V_58 . V_20 + V_123 ;
F_43 ( V_6 , V_2 -> V_58 . type ,
V_2 -> V_58 . V_20 , V_2 -> V_58 . V_59 , 0 ,
V_2 -> V_58 . V_1 ) ;
V_6 -> V_12 -> V_25 = 1 ;
V_7 = F_5 ( V_6 , V_2 -> V_58 . V_122 ?
V_93 : V_17 ) ;
V_6 -> V_12 -> V_25 = 0 ;
F_13 ( F_8 ( V_6 ) ) ;
return V_7 ;
}
void
F_21 ( T_2 * V_6 )
{
T_3 * V_54 ;
for( V_54 = F_25 ( V_6 -> V_12 -> V_119 ) ;
V_54 != NULL ; V_54 = F_25 ( V_6 -> V_12 -> V_119 ) )
{
F_4 ( ( T_1 * ) V_54 -> V_23 ) ;
F_26 ( V_54 ) ;
}
}
unsigned char *
F_39 ( T_2 * V_6 , unsigned char * V_56 , unsigned char V_32 ,
unsigned long V_9 , unsigned long V_10 , unsigned long V_1 )
{
if ( V_10 == 0 )
{
V_6 -> V_12 -> V_90 = V_6 -> V_12 -> V_91 ;
V_6 -> V_12 -> V_91 ++ ;
}
F_43 ( V_6 , V_32 , V_9 , V_6 -> V_12 -> V_90 ,
V_10 , V_1 ) ;
return V_56 += V_4 ;
}
static void
F_43 ( T_2 * V_6 , unsigned char V_32 ,
unsigned long V_9 , unsigned short V_124 , unsigned long V_10 ,
unsigned long V_1 )
{
struct V_48 * V_60 = & V_6 -> V_12 -> V_19 ;
V_60 -> type = V_32 ;
V_60 -> V_20 = V_9 ;
V_60 -> V_59 = V_124 ;
V_60 -> V_10 = V_10 ;
V_60 -> V_1 = V_1 ;
}
static void
F_14 ( T_2 * V_6 , unsigned long V_10 ,
unsigned long V_1 )
{
struct V_48 * V_60 = & V_6 -> V_12 -> V_19 ;
V_60 -> V_10 = V_10 ;
V_60 -> V_1 = V_1 ;
}
static unsigned char *
F_15 ( T_2 * V_6 , unsigned char * V_56 )
{
struct V_48 * V_60 = & V_6 -> V_12 -> V_19 ;
* V_56 ++ = V_60 -> type ;
F_47 ( V_60 -> V_20 , V_56 ) ;
F_42 ( V_60 -> V_59 , V_56 ) ;
F_47 ( V_60 -> V_10 , V_56 ) ;
F_47 ( V_60 -> V_1 , V_56 ) ;
return V_56 ;
}
static unsigned int
F_9 ( void )
{
return
V_125 [ ( sizeof( V_125 ) /
sizeof( V_125 [ 0 ] ) ) - 1 ] ;
}
static unsigned int
F_10 ( unsigned int V_8 )
{
int V_35 ;
if ( V_8 == 0 )
return V_125 [ 0 ] ;
for ( V_35 = 0 ; V_35 < sizeof( V_125 ) / sizeof( V_125 [ 0 ] ) ; V_35 ++ )
if ( V_8 > V_125 [ V_35 ] )
return V_125 [ V_35 ] ;
return V_8 ;
}
void
F_36 ( unsigned char * V_23 , struct V_48 * V_60 )
{
memset ( V_60 , 0x00 , sizeof( struct V_48 ) ) ;
V_60 -> type = * ( V_23 ++ ) ;
F_66 ( V_23 , V_60 -> V_20 ) ;
F_67 ( V_23 , V_60 -> V_59 ) ;
F_66 ( V_23 , V_60 -> V_10 ) ;
F_66 ( V_23 , V_60 -> V_1 ) ;
}
void
F_68 ( unsigned char * V_23 , struct V_126 * V_127 )
{
memset ( V_127 , 0x00 , sizeof( struct V_126 ) ) ;
V_127 -> type = * ( V_23 ++ ) ;
F_67 ( V_23 , V_127 -> V_59 ) ;
}
