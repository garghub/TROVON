static T_1 *
F_1 ( unsigned long V_1 )
{
T_1 * V_2 = NULL ;
unsigned char * V_3 = NULL ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
return NULL ;
if ( V_1 )
{
V_3 = ( unsigned char * ) F_2 ( V_1 ) ;
if ( V_3 == NULL )
{
F_3 ( V_2 ) ;
return NULL ;
}
}
V_2 -> V_4 = V_3 ;
return V_2 ;
}
static void
F_4 ( T_1 * V_2 )
{
if ( V_2 -> V_4 ) F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
int F_5 ( T_2 * V_5 , int type )
{
int V_6 ;
int V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
if ( ! ( F_6 ( V_5 ) & V_12 ) )
{
V_5 -> V_13 -> V_14 =
F_7 ( F_8 ( V_5 ) , V_15 , 0 , NULL ) ;
if ( V_5 -> V_13 -> V_14 < F_9 () )
{
V_5 -> V_13 -> V_14 = 0 ;
V_5 -> V_13 -> V_14 = F_10 ( V_5 -> V_13 -> V_14 ) ;
F_7 ( F_8 ( V_5 ) , V_16 ,
V_5 -> V_13 -> V_14 , NULL ) ;
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
if ( V_5 -> V_17 == 0 && type == V_18 )
F_11 ( V_5 -> V_19 ==
( int ) V_5 -> V_13 -> V_20 . V_21 + V_22 ) ;
if ( V_5 -> V_23 )
V_10 = F_12 ( V_5 -> V_23 ) ;
else
V_10 = 0 ;
if ( V_5 -> V_24 &&
( F_13 ( V_5 -> V_24 -> V_25 ) & V_26 ) )
V_11 = 2 * F_14 ( V_5 -> V_24 -> V_25 ) ;
else
V_11 = 0 ;
V_9 = 0 ;
while( V_5 -> V_19 )
{
V_7 = V_5 -> V_13 -> V_14 - F_15 ( F_8 ( V_5 ) ) -
V_27 - V_10 - V_11 ;
if ( V_7 <= V_22 )
{
V_6 = F_16 ( F_8 ( V_5 ) ) ;
if ( V_6 <= 0 )
return V_6 ;
V_7 = V_5 -> V_13 -> V_14 - V_27 -
V_10 - V_11 ;
}
if ( V_5 -> V_19 > V_7 )
V_8 = V_7 ;
else
V_8 = V_5 -> V_19 ;
if ( type == V_18 )
{
if ( V_5 -> V_17 != 0 )
{
F_11 ( V_5 -> V_17 > V_22 ) ;
V_5 -> V_17 -= V_22 ;
V_5 -> V_19 += V_22 ;
if ( V_8 <= V_22 )
V_8 += V_22 ;
}
F_17 ( V_5 , V_9 ,
V_8 - V_22 ) ;
F_18 ( V_5 , ( unsigned char * ) & V_5 -> V_28 -> V_29 [ V_5 -> V_17 ] ) ;
F_11 ( V_8 >= V_22 ) ;
}
V_6 = F_19 ( V_5 , type , & V_5 -> V_28 -> V_29 [ V_5 -> V_17 ] ,
V_8 ) ;
if ( V_6 < 0 )
{
if ( F_7 ( F_8 ( V_5 ) ,
V_30 , 0 , NULL ) > 0 )
V_5 -> V_13 -> V_14 = F_7 ( F_8 ( V_5 ) ,
V_15 , 0 , NULL ) ;
else
return ( - 1 ) ;
}
else
{
F_11 ( V_8 == ( unsigned int ) V_6 ) ;
if ( type == V_18 && ! V_5 -> V_13 -> V_31 )
{
unsigned char * V_32 = ( unsigned char * ) & V_5 -> V_28 -> V_29 [ V_5 -> V_17 ] ;
const struct V_33 * V_34 = & V_5 -> V_13 -> V_20 ;
int V_35 ;
if ( V_9 == 0 && V_5 -> V_36 != V_37 )
{
* V_32 ++ = V_34 -> type ;
F_20 ( V_34 -> V_21 , V_32 ) ;
F_21 ( V_34 -> V_38 , V_32 ) ;
F_20 ( 0 , V_32 ) ;
F_20 ( V_34 -> V_21 , V_32 ) ;
V_32 -= V_22 ;
V_35 = V_6 ;
}
else
{
V_32 += V_22 ;
V_35 = V_6 - V_22 ;
}
F_22 ( V_5 , V_32 , V_35 ) ;
}
if ( V_6 == V_5 -> V_19 )
{
if ( V_5 -> V_39 )
V_5 -> V_39 ( 1 , V_5 -> V_36 , type , V_5 -> V_28 -> V_29 ,
( V_40 ) ( V_5 -> V_17 + V_5 -> V_19 ) , V_5 ,
V_5 -> V_41 ) ;
V_5 -> V_17 = 0 ;
V_5 -> V_19 = 0 ;
return ( 1 ) ;
}
V_5 -> V_17 += V_6 ;
V_5 -> V_19 -= V_6 ;
V_9 += ( V_6 -= V_22 ) ;
}
}
return ( 0 ) ;
}
long F_23 ( T_2 * V_5 , int V_42 , int V_43 , int V_44 , long V_45 , int * V_46 )
{
int V_47 , V_48 ;
struct V_33 * V_34 ;
if ( V_5 -> V_49 -> V_50 . V_51 )
{
V_5 -> V_49 -> V_50 . V_51 = 0 ;
if ( ( V_44 >= 0 ) && ( V_5 -> V_49 -> V_50 . V_52 != V_44 ) )
{
V_48 = V_53 ;
F_24 ( V_54 , V_55 ) ;
goto V_56;
}
* V_46 = 1 ;
V_5 -> V_57 = V_5 -> V_28 -> V_29 + V_22 ;
V_5 -> V_19 = ( int ) V_5 -> V_49 -> V_50 . V_58 ;
return V_5 -> V_19 ;
}
V_34 = & V_5 -> V_13 -> V_59 ;
do
{
if ( V_34 -> V_9 == 0 )
{
memset ( V_34 , 0x00 , sizeof( struct V_33 ) ) ;
}
V_47 = F_25 ( V_5 , V_42 , V_43 , V_45 , V_46 ) ;
if ( V_47 == V_60 ||
V_47 == V_61 )
continue;
else if ( V_47 <= 0 && ! * V_46 )
return V_47 ;
if ( ( unsigned int ) V_5 -> V_19 >= V_34 -> V_21 )
{
unsigned char * V_32 = ( unsigned char * ) V_5 -> V_28 -> V_29 ;
unsigned long V_21 = V_34 -> V_21 ;
* ( V_32 ++ ) = V_34 -> type ;
F_20 ( V_21 , V_32 ) ;
F_21 ( V_34 -> V_38 , V_32 ) ;
F_20 ( 0 , V_32 ) ;
F_20 ( V_21 , V_32 ) ;
if ( V_5 -> V_36 != V_37 ) {
V_32 -= V_22 ;
V_21 += V_22 ;
}
F_22 ( V_5 , V_32 , V_21 ) ;
if ( V_5 -> V_39 )
V_5 -> V_39 ( 0 , V_5 -> V_36 , V_18 ,
V_32 , V_21 ,
V_5 , V_5 -> V_41 ) ;
memset ( V_34 , 0x00 , sizeof( struct V_33 ) ) ;
V_5 -> V_13 -> V_62 ++ ;
F_26 ( V_5 ) ;
V_5 -> V_57 = V_5 -> V_28 -> V_29 + V_22 ;
return V_5 -> V_19 ;
}
else
V_34 -> V_9 = V_47 ;
} while( 1 ) ;
V_56:
F_27 ( V_5 , V_63 , V_48 ) ;
* V_46 = 0 ;
return - 1 ;
}
static int F_28 ( T_2 * V_5 , struct V_33 * V_34 , int V_45 )
{
V_40 V_9 , V_1 , V_21 ;
V_21 = V_34 -> V_21 ;
V_9 = V_34 -> V_9 ;
V_1 = V_34 -> V_1 ;
if ( ( V_9 + V_1 ) > V_21 )
{
F_24 ( V_64 , V_65 ) ;
return V_66 ;
}
if ( ( V_9 + V_1 ) > ( unsigned long ) V_45 )
{
F_24 ( V_64 , V_65 ) ;
return V_66 ;
}
if ( V_5 -> V_13 -> V_59 . V_9 == 0 )
{
if ( ! F_29 ( V_5 -> V_28 , V_21 + V_22 ) )
{
F_24 ( V_64 , V_67 ) ;
return V_68 ;
}
V_5 -> V_49 -> V_50 . V_58 = V_21 ;
V_5 -> V_13 -> V_59 . V_21 = V_21 ;
V_5 -> V_49 -> V_50 . V_52 = V_34 -> type ;
V_5 -> V_13 -> V_59 . type = V_34 -> type ;
V_5 -> V_13 -> V_59 . V_38 = V_34 -> V_38 ;
}
else if ( V_21 != V_5 -> V_13 -> V_59 . V_21 )
{
F_24 ( V_64 , V_65 ) ;
return V_66 ;
}
return 0 ;
}
static int
F_30 ( T_2 * V_5 , long V_45 , int * V_46 )
{
T_3 * V_69 ;
T_1 * V_2 ;
int V_48 ;
* V_46 = 0 ;
V_69 = F_31 ( V_5 -> V_13 -> V_70 ) ;
if ( V_69 == NULL )
return 0 ;
V_2 = ( T_1 * ) V_69 -> V_29 ;
if ( V_5 -> V_13 -> V_62 == V_2 -> V_71 . V_38 )
{
unsigned long V_1 = V_2 -> V_71 . V_1 ;
F_32 ( V_5 -> V_13 -> V_70 ) ;
V_48 = F_28 ( V_5 , & V_2 -> V_71 , V_45 ) ;
if ( V_48 == 0 )
{
unsigned char * V_32 = ( unsigned char * ) V_5 -> V_28 -> V_29 + V_22 ;
memcpy ( & V_32 [ V_2 -> V_71 . V_9 ] ,
V_2 -> V_4 , V_2 -> V_71 . V_1 ) ;
}
F_4 ( V_2 ) ;
F_33 ( V_69 ) ;
if ( V_48 == 0 )
{
* V_46 = 1 ;
return V_1 ;
}
F_27 ( V_5 , V_63 , V_48 ) ;
V_5 -> V_19 = 0 ;
* V_46 = 0 ;
return - 1 ;
}
else
return 0 ;
}
static int
F_34 ( T_2 * V_5 , struct V_33 * V_34 , int * V_46 )
{
int V_47 = - 1 ;
T_1 * V_2 = NULL ;
T_3 * V_69 = NULL ;
unsigned char V_72 [ 8 ] ;
unsigned long V_1 = V_34 -> V_1 ;
if ( ( V_34 -> V_9 + V_1 ) > V_34 -> V_21 )
goto V_73;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
V_72 [ 6 ] = ( unsigned char ) ( V_34 -> V_38 >> 8 ) ;
V_72 [ 7 ] = ( unsigned char ) V_34 -> V_38 ;
V_69 = F_35 ( V_5 -> V_13 -> V_70 , V_72 ) ;
if ( V_34 -> V_38 <= V_5 -> V_13 -> V_62 ||
V_34 -> V_38 > V_5 -> V_13 -> V_62 + 10 || V_69 != NULL ||
( V_5 -> V_13 -> V_62 == 0 && V_34 -> type == V_74 ) )
{
unsigned char V_75 [ 256 ] ;
while ( V_1 )
{
V_47 = V_5 -> V_76 -> V_77 ( V_5 , V_18 ,
V_75 ,
V_1 > sizeof( V_75 ) ? sizeof( V_75 ) : V_1 , 0 ) ;
if ( V_47 <= 0 ) goto V_73;
V_1 -= V_47 ;
}
}
if ( V_1 )
{
V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL )
goto V_73;
memcpy ( & ( V_2 -> V_71 ) , V_34 , sizeof( * V_34 ) ) ;
V_47 = V_5 -> V_76 -> V_77 ( V_5 , V_18 ,
V_2 -> V_4 , V_1 , 0 ) ;
if ( V_47 <= 0 || ( unsigned long ) V_47 != V_1 )
goto V_73;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
V_72 [ 6 ] = ( unsigned char ) ( V_34 -> V_38 >> 8 ) ;
V_72 [ 7 ] = ( unsigned char ) ( V_34 -> V_38 ) ;
V_69 = F_36 ( V_72 , V_2 ) ;
if ( V_69 == NULL )
goto V_73;
F_37 ( V_5 -> V_13 -> V_70 , V_69 ) ;
}
return V_61 ;
V_73:
if ( V_2 != NULL ) F_4 ( V_2 ) ;
if ( V_69 != NULL ) F_3 ( V_69 ) ;
* V_46 = 0 ;
return V_47 ;
}
static long
F_25 ( T_2 * V_5 , int V_42 , int V_43 , long V_45 , int * V_46 )
{
unsigned char V_78 [ V_22 ] ;
unsigned long V_79 , V_9 , V_1 ;
int V_47 , V_48 ;
struct V_33 V_34 ;
if ( ( V_1 = F_30 ( V_5 , V_45 , V_46 ) ) || * V_46 )
{
if ( * V_46 ) V_5 -> V_19 += V_1 ;
return V_1 ;
}
V_47 = V_5 -> V_76 -> V_77 ( V_5 , V_18 , V_78 ,
V_22 , 0 ) ;
if ( V_47 <= 0 )
{
V_5 -> V_80 = V_81 ;
* V_46 = 0 ;
return V_47 ;
}
F_11 ( V_47 == V_22 ) ;
F_38 ( V_78 , & V_34 ) ;
if ( V_34 . V_38 != V_5 -> V_13 -> V_62 )
return F_34 ( V_5 , & V_34 , V_46 ) ;
V_79 = V_34 . V_21 ;
V_9 = V_34 . V_9 ;
V_1 = V_34 . V_1 ;
if ( ! V_5 -> V_82 && V_5 -> V_13 -> V_59 . V_9 == 0 &&
V_78 [ 0 ] == V_83 )
{
if ( V_78 [ 1 ] == 0 && V_78 [ 2 ] == 0 && V_78 [ 3 ] == 0 )
{
if ( V_5 -> V_39 )
V_5 -> V_39 ( 0 , V_5 -> V_36 , V_18 ,
V_78 , V_22 , V_5 ,
V_5 -> V_41 ) ;
V_5 -> V_19 = 0 ;
return F_25 ( V_5 , V_42 , V_43 ,
V_45 , V_46 ) ;
}
else
{
V_48 = V_53 ;
F_24 ( V_84 , V_55 ) ;
goto V_56;
}
}
if ( ( V_48 = F_28 ( V_5 , & V_34 , V_45 ) ) )
goto V_56;
V_5 -> V_85 = V_43 ;
if ( V_1 > 0 )
{
unsigned char * V_32 = ( unsigned char * ) V_5 -> V_28 -> V_29 + V_22 ;
V_47 = V_5 -> V_76 -> V_77 ( V_5 , V_18 ,
& V_32 [ V_9 ] , V_1 , 0 ) ;
if ( V_47 <= 0 )
{
V_5 -> V_80 = V_81 ;
* V_46 = 0 ;
return V_47 ;
}
}
else
V_47 = 0 ;
F_11 ( V_47 == ( int ) V_1 ) ;
* V_46 = 1 ;
V_5 -> V_19 += V_1 ;
return V_1 ;
V_56:
F_27 ( V_5 , V_63 , V_48 ) ;
V_5 -> V_19 = 0 ;
* V_46 = 0 ;
return ( - 1 ) ;
}
int F_39 ( T_2 * V_5 , int V_86 , int V_87 , const char * V_88 , int V_89 )
{
unsigned char * V_32 , * V_90 ;
int V_47 ;
unsigned long V_79 ;
if ( V_5 -> V_85 == V_86 )
{
V_90 = ( unsigned char * ) V_5 -> V_28 -> V_29 ;
V_32 = & ( V_90 [ V_22 ] ) ;
V_47 = V_5 -> V_76 -> V_91 -> V_92 ( V_5 ,
V_88 , V_89 , V_5 -> V_49 -> V_50 . V_93 ) ;
V_5 -> V_49 -> V_50 . V_94 = V_47 ;
memcpy ( V_32 , V_5 -> V_49 -> V_50 . V_93 , V_47 ) ;
V_32 += V_47 ;
V_79 = V_47 ;
if( V_5 -> type == V_95 )
{
F_11 ( V_47 <= V_96 ) ;
memcpy ( V_5 -> V_49 -> V_97 ,
V_5 -> V_49 -> V_50 . V_93 , V_47 ) ;
V_5 -> V_49 -> V_98 = V_47 ;
}
else
{
F_11 ( V_47 <= V_96 ) ;
memcpy ( V_5 -> V_49 -> V_99 ,
V_5 -> V_49 -> V_50 . V_93 , V_47 ) ;
V_5 -> V_49 -> V_100 = V_47 ;
}
#ifdef F_40
V_79 &= 0xffff ;
#endif
V_90 = F_41 ( V_5 , V_90 , V_74 , V_79 , 0 , V_79 ) ;
V_5 -> V_19 = ( int ) V_79 + V_22 ;
V_5 -> V_17 = 0 ;
F_42 ( V_5 , 0 ) ;
V_5 -> V_85 = V_87 ;
}
return ( F_5 ( V_5 , V_18 ) ) ;
}
int F_43 ( T_2 * V_5 , int V_86 , int V_87 )
{
unsigned char * V_32 ;
if ( V_5 -> V_85 == V_86 )
{
V_32 = ( unsigned char * ) V_5 -> V_28 -> V_29 ;
* V_32 ++ = V_101 ;
V_5 -> V_13 -> V_102 = V_5 -> V_13 -> V_103 ;
V_5 -> V_19 = V_104 ;
if ( V_5 -> V_36 == V_37 ) {
V_5 -> V_13 -> V_103 ++ ;
F_21 ( V_5 -> V_13 -> V_102 , V_32 ) ;
V_5 -> V_19 += 2 ;
}
V_5 -> V_17 = 0 ;
F_44 ( V_5 , V_101 , 0 ,
V_5 -> V_13 -> V_102 , 0 , 0 ) ;
F_42 ( V_5 , 1 ) ;
V_5 -> V_85 = V_87 ;
}
return ( F_5 ( V_5 , V_105 ) ) ;
}
static int F_45 ( T_4 * V_3 , unsigned long * V_79 , T_5 * V_106 )
{
int V_107 ;
unsigned char * V_32 ;
V_107 = F_46 ( V_106 , NULL ) ;
if ( ! F_29 ( V_3 , ( int ) ( V_107 + ( * V_79 ) + 3 ) ) )
{
F_24 ( V_108 , V_67 ) ;
return 0 ;
}
V_32 = ( unsigned char * ) & ( V_3 -> V_29 [ * V_79 ] ) ;
F_20 ( V_107 , V_32 ) ;
F_46 ( V_106 , & V_32 ) ;
* V_79 += V_107 + 3 ;
return 1 ;
}
unsigned long F_47 ( T_2 * V_5 , T_5 * V_106 )
{
unsigned char * V_32 ;
int V_47 ;
unsigned long V_79 = 3 + V_22 ;
T_4 * V_3 ;
V_3 = V_5 -> V_28 ;
if ( ! F_29 ( V_3 , 10 ) )
{
F_24 ( V_109 , V_67 ) ;
return ( 0 ) ;
}
if ( V_106 != NULL )
{
T_6 V_110 ;
if ( ! F_48 ( & V_110 , V_5 -> V_111 -> V_112 , V_106 , NULL ) )
{
F_24 ( V_109 , V_113 ) ;
return ( 0 ) ;
}
F_49 ( & V_110 ) ;
F_50 () ;
for ( V_47 = 0 ; V_47 < F_51 ( V_110 . V_114 ) ; V_47 ++ )
{
V_106 = F_52 ( V_110 . V_114 , V_47 ) ;
if ( ! F_45 ( V_3 , & V_79 , V_106 ) )
{
F_53 ( & V_110 ) ;
return 0 ;
}
}
F_53 ( & V_110 ) ;
}
for ( V_47 = 0 ; V_47 < F_51 ( V_5 -> V_111 -> V_115 ) ; V_47 ++ )
{
V_106 = F_52 ( V_5 -> V_111 -> V_115 , V_47 ) ;
if ( ! F_45 ( V_3 , & V_79 , V_106 ) )
return 0 ;
}
V_79 -= ( 3 + V_22 ) ;
V_32 = ( unsigned char * ) & ( V_3 -> V_29 [ V_22 ] ) ;
F_20 ( V_79 , V_32 ) ;
V_79 += 3 ;
V_32 = ( unsigned char * ) & ( V_3 -> V_29 [ 0 ] ) ;
V_32 = F_41 ( V_5 , V_32 , V_116 , V_79 , 0 , V_79 ) ;
V_79 += V_22 ;
return ( V_79 ) ;
}
int F_54 ( T_2 * V_5 , int V_117 )
{
if ( V_117 > 0 )
{
fprintf ( V_118 , L_1 , __FILE__ , __LINE__ ) ;
return 1 ;
}
if ( ! F_55 ( V_5 ) )
{
return V_117 ;
}
if ( ! F_56 ( V_5 ) )
{
F_57 ( F_58 ( V_5 ) , V_119 ) ;
return V_117 ;
}
#if 0
item = pqueue_peek(state->rcvd_records);
if ( item )
{
}
else
#endif
#if 0
if ( state->timeout.read_timeouts >= DTLS1_TMO_READ_COUNT)
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
return F_59 ( V_5 ) ;
}
int
F_60 ( unsigned short V_38 , int V_120 )
{
return V_38 * 2 - V_120 ;
}
int
F_61 ( T_2 * V_5 )
{
T_7 V_121 = V_5 -> V_13 -> V_122 ;
T_8 V_123 ;
T_3 * V_69 ;
T_1 * V_2 ;
int V_124 = 0 ;
V_123 = F_62 ( V_121 ) ;
for ( V_69 = F_63 ( & V_123 ) ; V_69 != NULL ; V_69 = F_63 ( & V_123 ) )
{
V_2 = ( T_1 * ) V_69 -> V_29 ;
if ( F_64 ( V_5 ,
( unsigned short ) F_60 ( V_2 -> V_71 . V_38 , V_2 -> V_71 . V_120 ) ,
0 , & V_124 ) <= 0 && V_124 )
{
fprintf ( V_118 , L_2 ) ;
return - 1 ;
}
}
return 1 ;
}
int
F_42 ( T_2 * V_5 , int V_120 )
{
T_3 * V_69 ;
T_1 * V_2 ;
unsigned char V_72 [ 8 ] ;
F_11 ( V_5 -> V_17 == 0 ) ;
V_2 = F_1 ( V_5 -> V_19 ) ;
memcpy ( V_2 -> V_4 , V_5 -> V_28 -> V_29 , V_5 -> V_19 ) ;
if ( V_120 )
{
F_11 ( V_5 -> V_13 -> V_20 . V_21 +
( ( V_5 -> V_36 == V_125 ) ? V_104 : 3 ) == ( unsigned int ) V_5 -> V_19 ) ;
}
else
{
F_11 ( V_5 -> V_13 -> V_20 . V_21 +
V_22 == ( unsigned int ) V_5 -> V_19 ) ;
}
V_2 -> V_71 . V_21 = V_5 -> V_13 -> V_20 . V_21 ;
V_2 -> V_71 . V_38 = V_5 -> V_13 -> V_20 . V_38 ;
V_2 -> V_71 . type = V_5 -> V_13 -> V_20 . type ;
V_2 -> V_71 . V_9 = 0 ;
V_2 -> V_71 . V_1 = V_5 -> V_13 -> V_20 . V_21 ;
V_2 -> V_71 . V_120 = V_120 ;
V_2 -> V_71 . V_126 . V_24 = V_5 -> V_24 ;
V_2 -> V_71 . V_126 . V_23 = V_5 -> V_23 ;
V_2 -> V_71 . V_126 . V_127 = V_5 -> V_127 ;
V_2 -> V_71 . V_126 . V_128 = V_5 -> V_128 ;
V_2 -> V_71 . V_126 . V_129 = V_5 -> V_13 -> V_130 ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
V_72 [ 6 ] = ( unsigned char ) ( F_60 ( V_2 -> V_71 . V_38 ,
V_2 -> V_71 . V_120 ) >> 8 ) ;
V_72 [ 7 ] = ( unsigned char ) ( F_60 ( V_2 -> V_71 . V_38 ,
V_2 -> V_71 . V_120 ) ) ;
V_69 = F_36 ( V_72 , V_2 ) ;
if ( V_69 == NULL )
{
F_4 ( V_2 ) ;
return 0 ;
}
#if 0
fprintf( stderr, "buffered messge: \ttype = %xx\n", msg_buf->type);
fprintf( stderr, "\t\t\t\t\tlen = %d\n", msg_buf->len);
fprintf( stderr, "\t\t\t\t\tseq_num = %d\n", msg_buf->seq_num);
#endif
F_37 ( V_5 -> V_13 -> V_122 , V_69 ) ;
return 1 ;
}
int
F_64 ( T_2 * V_5 , unsigned short V_38 , unsigned long V_9 ,
int * V_124 )
{
int V_6 ;
T_3 * V_69 ;
T_1 * V_2 ;
unsigned long V_131 ;
unsigned char V_72 [ 8 ] ;
struct V_132 V_133 ;
unsigned char V_134 [ 8 ] ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
V_72 [ 6 ] = ( unsigned char ) ( V_38 >> 8 ) ;
V_72 [ 7 ] = ( unsigned char ) V_38 ;
V_69 = F_35 ( V_5 -> V_13 -> V_122 , V_72 ) ;
if ( V_69 == NULL )
{
fprintf ( V_118 , L_3 , V_38 ) ;
* V_124 = 0 ;
return 0 ;
}
* V_124 = 1 ;
V_2 = ( T_1 * ) V_69 -> V_29 ;
if ( V_2 -> V_71 . V_120 )
V_131 = V_104 ;
else
V_131 = V_22 ;
memcpy ( V_5 -> V_28 -> V_29 , V_2 -> V_4 ,
V_2 -> V_71 . V_21 + V_131 ) ;
V_5 -> V_19 = V_2 -> V_71 . V_21 + V_131 ;
F_44 ( V_5 , V_2 -> V_71 . type ,
V_2 -> V_71 . V_21 , V_2 -> V_71 . V_38 , 0 ,
V_2 -> V_71 . V_1 ) ;
V_133 . V_24 = V_5 -> V_24 ;
V_133 . V_23 = V_5 -> V_23 ;
V_133 . V_127 = V_5 -> V_127 ;
V_133 . V_128 = V_5 -> V_128 ;
V_133 . V_129 = V_5 -> V_13 -> V_130 ;
V_133 . V_129 = V_5 -> V_13 -> V_130 ;
V_5 -> V_13 -> V_31 = 1 ;
V_5 -> V_24 = V_2 -> V_71 . V_126 . V_24 ;
V_5 -> V_23 = V_2 -> V_71 . V_126 . V_23 ;
V_5 -> V_127 = V_2 -> V_71 . V_126 . V_127 ;
V_5 -> V_128 = V_2 -> V_71 . V_126 . V_128 ;
V_5 -> V_13 -> V_130 = V_2 -> V_71 . V_126 . V_129 ;
if ( V_2 -> V_71 . V_126 . V_129 == V_133 . V_129 - 1 )
{
memcpy ( V_134 , V_5 -> V_49 -> V_135 , sizeof( V_5 -> V_49 -> V_135 ) ) ;
memcpy ( V_5 -> V_49 -> V_135 , V_5 -> V_13 -> V_136 , sizeof( V_5 -> V_49 -> V_135 ) ) ;
}
V_6 = F_5 ( V_5 , V_2 -> V_71 . V_120 ?
V_105 : V_18 ) ;
V_5 -> V_24 = V_133 . V_24 ;
V_5 -> V_23 = V_133 . V_23 ;
V_5 -> V_127 = V_133 . V_127 ;
V_5 -> V_128 = V_133 . V_128 ;
V_5 -> V_13 -> V_130 = V_133 . V_129 ;
if ( V_2 -> V_71 . V_126 . V_129 == V_133 . V_129 - 1 )
{
memcpy ( V_5 -> V_13 -> V_136 , V_5 -> V_49 -> V_135 , sizeof( V_5 -> V_49 -> V_135 ) ) ;
memcpy ( V_5 -> V_49 -> V_135 , V_134 , sizeof( V_5 -> V_49 -> V_135 ) ) ;
}
V_5 -> V_13 -> V_31 = 0 ;
( void ) F_16 ( F_8 ( V_5 ) ) ;
return V_6 ;
}
void
F_26 ( T_2 * V_5 )
{
T_3 * V_69 ;
for( V_69 = F_32 ( V_5 -> V_13 -> V_122 ) ;
V_69 != NULL ; V_69 = F_32 ( V_5 -> V_13 -> V_122 ) )
{
F_4 ( ( T_1 * ) V_69 -> V_29 ) ;
F_33 ( V_69 ) ;
}
}
unsigned char *
F_41 ( T_2 * V_5 , unsigned char * V_32 , unsigned char V_44 ,
unsigned long V_8 , unsigned long V_9 , unsigned long V_1 )
{
if ( V_9 == 0 )
{
V_5 -> V_13 -> V_102 = V_5 -> V_13 -> V_103 ;
V_5 -> V_13 -> V_103 ++ ;
}
F_44 ( V_5 , V_44 , V_8 , V_5 -> V_13 -> V_102 ,
V_9 , V_1 ) ;
return V_32 += V_22 ;
}
static void
F_44 ( T_2 * V_5 , unsigned char V_44 ,
unsigned long V_8 , unsigned short V_137 , unsigned long V_9 ,
unsigned long V_1 )
{
struct V_33 * V_34 = & V_5 -> V_13 -> V_20 ;
V_34 -> type = V_44 ;
V_34 -> V_21 = V_8 ;
V_34 -> V_38 = V_137 ;
V_34 -> V_9 = V_9 ;
V_34 -> V_1 = V_1 ;
}
static void
F_17 ( T_2 * V_5 , unsigned long V_9 ,
unsigned long V_1 )
{
struct V_33 * V_34 = & V_5 -> V_13 -> V_20 ;
V_34 -> V_9 = V_9 ;
V_34 -> V_1 = V_1 ;
}
static unsigned char *
F_18 ( T_2 * V_5 , unsigned char * V_32 )
{
struct V_33 * V_34 = & V_5 -> V_13 -> V_20 ;
* V_32 ++ = V_34 -> type ;
F_20 ( V_34 -> V_21 , V_32 ) ;
F_21 ( V_34 -> V_38 , V_32 ) ;
F_20 ( V_34 -> V_9 , V_32 ) ;
F_20 ( V_34 -> V_1 , V_32 ) ;
return V_32 ;
}
static unsigned int
F_9 ( void )
{
return ( V_138 [ ( sizeof( V_138 ) /
sizeof( V_138 [ 0 ] ) ) - 1 ] ) ;
}
static unsigned int
F_10 ( unsigned int V_7 )
{
unsigned int V_47 ;
if ( V_7 == 0 )
return V_138 [ 0 ] ;
for ( V_47 = 0 ; V_47 < sizeof( V_138 ) / sizeof( V_138 [ 0 ] ) ; V_47 ++ )
if ( V_7 > V_138 [ V_47 ] )
return V_138 [ V_47 ] ;
return V_7 ;
}
void
F_38 ( unsigned char * V_29 , struct V_33 * V_34 )
{
memset ( V_34 , 0x00 , sizeof( struct V_33 ) ) ;
V_34 -> type = * ( V_29 ++ ) ;
F_65 ( V_29 , V_34 -> V_21 ) ;
F_66 ( V_29 , V_34 -> V_38 ) ;
F_65 ( V_29 , V_34 -> V_9 ) ;
F_65 ( V_29 , V_34 -> V_1 ) ;
}
void
F_67 ( unsigned char * V_29 , struct V_139 * V_140 )
{
memset ( V_140 , 0x00 , sizeof( struct V_139 ) ) ;
V_140 -> type = * ( V_29 ++ ) ;
}
