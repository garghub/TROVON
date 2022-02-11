static T_1 *
F_1 ( unsigned long V_1 , int V_2 )
{
T_1 * V_3 = NULL ;
unsigned char * V_4 = NULL ;
unsigned char * V_5 = NULL ;
V_3 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
return NULL ;
if ( V_1 )
{
V_4 = ( unsigned char * ) F_2 ( V_1 ) ;
if ( V_4 == NULL )
{
F_3 ( V_3 ) ;
return NULL ;
}
}
V_3 -> V_6 = V_4 ;
if ( V_2 )
{
V_5 = ( unsigned char * ) F_2 ( F_4 ( V_1 ) ) ;
if ( V_5 == NULL )
{
if ( V_4 != NULL ) F_3 ( V_4 ) ;
F_3 ( V_3 ) ;
return NULL ;
}
memset ( V_5 , 0 , F_4 ( V_1 ) ) ;
}
V_3 -> V_2 = V_5 ;
return V_3 ;
}
static void
F_5 ( T_1 * V_3 )
{
if ( V_3 -> V_6 ) F_3 ( V_3 -> V_6 ) ;
if ( V_3 -> V_2 ) F_3 ( V_3 -> V_2 ) ;
F_3 ( V_3 ) ;
}
int F_6 ( T_2 * V_7 , int type )
{
int V_8 ;
int V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
if ( V_7 -> V_14 -> V_15 < F_7 () && ! ( F_8 ( V_7 ) & V_16 ) )
{
V_7 -> V_14 -> V_15 =
F_9 ( F_10 ( V_7 ) , V_17 , 0 , NULL ) ;
if ( V_7 -> V_14 -> V_15 < F_7 () )
{
V_7 -> V_14 -> V_15 = 0 ;
V_7 -> V_14 -> V_15 = F_11 ( V_7 -> V_14 -> V_15 ) ;
F_9 ( F_10 ( V_7 ) , V_18 ,
V_7 -> V_14 -> V_15 , NULL ) ;
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
#endif
F_12 ( V_7 -> V_14 -> V_15 >= F_7 () ) ;
if ( V_7 -> V_19 == 0 && type == V_20 )
F_12 ( V_7 -> V_21 ==
( int ) V_7 -> V_14 -> V_22 . V_23 + V_24 ) ;
if ( V_7 -> V_25 )
V_12 = F_13 ( V_7 -> V_25 ) ;
else
V_12 = 0 ;
if ( V_7 -> V_26 &&
( F_14 ( V_7 -> V_26 -> V_27 ) & V_28 ) )
V_13 = 2 * F_15 ( V_7 -> V_26 -> V_27 ) ;
else
V_13 = 0 ;
V_11 = 0 ;
while( V_7 -> V_21 )
{
V_9 = V_7 -> V_14 -> V_15 - F_16 ( F_10 ( V_7 ) ) -
V_29 - V_12 - V_13 ;
if ( V_9 <= V_24 )
{
V_8 = F_17 ( F_10 ( V_7 ) ) ;
if ( V_8 <= 0 )
return V_8 ;
V_9 = V_7 -> V_14 -> V_15 - V_29 -
V_12 - V_13 ;
}
if ( V_7 -> V_21 > V_9 )
V_10 = V_9 ;
else
V_10 = V_7 -> V_21 ;
if ( type == V_20 )
{
if ( V_7 -> V_19 != 0 )
{
F_12 ( V_7 -> V_19 > V_24 ) ;
V_7 -> V_19 -= V_24 ;
V_7 -> V_21 += V_24 ;
if ( V_10 <= V_24 )
V_10 += V_24 ;
}
F_18 ( V_7 , V_11 ,
V_10 - V_24 ) ;
F_19 ( V_7 , ( unsigned char * ) & V_7 -> V_30 -> V_31 [ V_7 -> V_19 ] ) ;
F_12 ( V_10 >= V_24 ) ;
}
V_8 = F_20 ( V_7 , type , & V_7 -> V_30 -> V_31 [ V_7 -> V_19 ] ,
V_10 ) ;
if ( V_8 < 0 )
{
if ( F_9 ( F_10 ( V_7 ) ,
V_32 , 0 , NULL ) > 0 )
V_7 -> V_14 -> V_15 = F_9 ( F_10 ( V_7 ) ,
V_17 , 0 , NULL ) ;
else
return ( - 1 ) ;
}
else
{
F_12 ( V_10 == ( unsigned int ) V_8 ) ;
if ( type == V_20 && ! V_7 -> V_14 -> V_33 )
{
unsigned char * V_34 = ( unsigned char * ) & V_7 -> V_30 -> V_31 [ V_7 -> V_19 ] ;
const struct V_35 * V_36 = & V_7 -> V_14 -> V_22 ;
int V_37 ;
if ( V_11 == 0 && V_7 -> V_38 != V_39 )
{
* V_34 ++ = V_36 -> type ;
F_21 ( V_36 -> V_23 , V_34 ) ;
F_22 ( V_36 -> V_40 , V_34 ) ;
F_21 ( 0 , V_34 ) ;
F_21 ( V_36 -> V_23 , V_34 ) ;
V_34 -= V_24 ;
V_37 = V_8 ;
}
else
{
V_34 += V_24 ;
V_37 = V_8 - V_24 ;
}
F_23 ( V_7 , V_34 , V_37 ) ;
}
if ( V_8 == V_7 -> V_21 )
{
if ( V_7 -> V_41 )
V_7 -> V_41 ( 1 , V_7 -> V_38 , type , V_7 -> V_30 -> V_31 ,
( V_42 ) ( V_7 -> V_19 + V_7 -> V_21 ) , V_7 ,
V_7 -> V_43 ) ;
V_7 -> V_19 = 0 ;
V_7 -> V_21 = 0 ;
return ( 1 ) ;
}
V_7 -> V_19 += V_8 ;
V_7 -> V_21 -= V_8 ;
V_11 += ( V_8 -= V_24 ) ;
}
}
return ( 0 ) ;
}
long F_24 ( T_2 * V_7 , int V_44 , int V_45 , int V_46 , long V_47 , int * V_48 )
{
int V_49 , V_50 ;
struct V_35 * V_36 ;
unsigned char * V_34 ;
unsigned long V_23 ;
if ( V_7 -> V_51 -> V_52 . V_53 )
{
V_7 -> V_51 -> V_52 . V_53 = 0 ;
if ( ( V_46 >= 0 ) && ( V_7 -> V_51 -> V_52 . V_54 != V_46 ) )
{
V_50 = V_55 ;
F_25 ( V_56 , V_57 ) ;
goto V_58;
}
* V_48 = 1 ;
V_7 -> V_59 = V_7 -> V_30 -> V_31 + V_24 ;
V_7 -> V_21 = ( int ) V_7 -> V_51 -> V_52 . V_60 ;
return V_7 -> V_21 ;
}
V_36 = & V_7 -> V_14 -> V_61 ;
memset ( V_36 , 0x00 , sizeof( struct V_35 ) ) ;
V_62:
V_49 = F_26 ( V_7 , V_44 , V_45 , V_47 , V_48 ) ;
if ( V_49 == V_63 ||
V_49 == V_64 )
goto V_62;
else if ( V_49 <= 0 && ! * V_48 )
return V_49 ;
V_34 = ( unsigned char * ) V_7 -> V_30 -> V_31 ;
V_23 = V_36 -> V_23 ;
* ( V_34 ++ ) = V_36 -> type ;
F_21 ( V_23 , V_34 ) ;
F_22 ( V_36 -> V_40 , V_34 ) ;
F_21 ( 0 , V_34 ) ;
F_21 ( V_23 , V_34 ) ;
if ( V_7 -> V_38 != V_39 ) {
V_34 -= V_24 ;
V_23 += V_24 ;
}
F_23 ( V_7 , V_34 , V_23 ) ;
if ( V_7 -> V_41 )
V_7 -> V_41 ( 0 , V_7 -> V_38 , V_20 ,
V_34 , V_23 ,
V_7 , V_7 -> V_43 ) ;
memset ( V_36 , 0x00 , sizeof( struct V_35 ) ) ;
if ( ! V_7 -> V_14 -> V_65 )
V_7 -> V_14 -> V_66 ++ ;
V_7 -> V_59 = V_7 -> V_30 -> V_31 + V_24 ;
return V_7 -> V_21 ;
V_58:
F_27 ( V_7 , V_67 , V_50 ) ;
* V_48 = 0 ;
return - 1 ;
}
static int F_28 ( T_2 * V_7 , struct V_35 * V_36 , int V_47 )
{
V_42 V_11 , V_1 , V_23 ;
V_23 = V_36 -> V_23 ;
V_11 = V_36 -> V_11 ;
V_1 = V_36 -> V_1 ;
if ( ( V_11 + V_1 ) > V_23 )
{
F_25 ( V_68 , V_69 ) ;
return V_70 ;
}
if ( ( V_11 + V_1 ) > ( unsigned long ) V_47 )
{
F_25 ( V_68 , V_69 ) ;
return V_70 ;
}
if ( V_7 -> V_14 -> V_61 . V_11 == 0 )
{
if ( ! F_29 ( V_7 -> V_30 , V_23 + V_24 ) )
{
F_25 ( V_68 , V_71 ) ;
return V_72 ;
}
V_7 -> V_51 -> V_52 . V_60 = V_23 ;
V_7 -> V_14 -> V_61 . V_23 = V_23 ;
V_7 -> V_51 -> V_52 . V_54 = V_36 -> type ;
V_7 -> V_14 -> V_61 . type = V_36 -> type ;
V_7 -> V_14 -> V_61 . V_40 = V_36 -> V_40 ;
}
else if ( V_23 != V_7 -> V_14 -> V_61 . V_23 )
{
F_25 ( V_68 , V_69 ) ;
return V_70 ;
}
return 0 ;
}
static int
F_30 ( T_2 * V_7 , long V_47 , int * V_48 )
{
T_3 * V_73 ;
T_1 * V_3 ;
int V_50 ;
* V_48 = 0 ;
V_73 = F_31 ( V_7 -> V_14 -> V_74 ) ;
if ( V_73 == NULL )
return 0 ;
V_3 = ( T_1 * ) V_73 -> V_31 ;
if ( V_3 -> V_2 != NULL )
return 0 ;
if ( V_7 -> V_14 -> V_66 == V_3 -> V_75 . V_40 )
{
unsigned long V_1 = V_3 -> V_75 . V_1 ;
F_32 ( V_7 -> V_14 -> V_74 ) ;
V_50 = F_28 ( V_7 , & V_3 -> V_75 , V_47 ) ;
if ( V_50 == 0 )
{
unsigned char * V_34 = ( unsigned char * ) V_7 -> V_30 -> V_31 + V_24 ;
memcpy ( & V_34 [ V_3 -> V_75 . V_11 ] ,
V_3 -> V_6 , V_3 -> V_75 . V_1 ) ;
}
F_5 ( V_3 ) ;
F_33 ( V_73 ) ;
if ( V_50 == 0 )
{
* V_48 = 1 ;
return V_1 ;
}
F_27 ( V_7 , V_67 , V_50 ) ;
V_7 -> V_21 = 0 ;
* V_48 = 0 ;
return - 1 ;
}
else
return 0 ;
}
static int
F_34 ( T_2 * V_7 , struct V_35 * V_36 , int * V_48 )
{
T_1 * V_3 = NULL ;
T_3 * V_73 = NULL ;
int V_49 = - 1 , V_76 ;
unsigned char V_77 [ 8 ] ;
unsigned long V_1 = V_36 -> V_1 , V_78 ;
if ( ( V_36 -> V_11 + V_1 ) > V_36 -> V_23 )
goto V_79;
if ( V_24 + V_80 < V_7 -> V_81 )
V_78 = V_7 -> V_81 ;
else
V_78 = V_24 + V_80 ;
if ( ( V_36 -> V_11 + V_1 ) > V_78 )
goto V_79;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( V_36 -> V_40 >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) V_36 -> V_40 ;
V_73 = F_35 ( V_7 -> V_14 -> V_74 , V_77 ) ;
if ( V_73 == NULL )
{
V_3 = F_1 ( V_36 -> V_23 , 1 ) ;
if ( V_3 == NULL )
goto V_79;
memcpy ( & ( V_3 -> V_75 ) , V_36 , sizeof( * V_36 ) ) ;
V_3 -> V_75 . V_1 = V_3 -> V_75 . V_23 ;
V_3 -> V_75 . V_11 = 0 ;
}
else
V_3 = ( T_1 * ) V_73 -> V_31 ;
if ( V_3 -> V_2 == NULL )
{
unsigned char V_82 [ 256 ] ;
while ( V_1 )
{
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 ,
V_82 ,
V_1 > sizeof( V_82 ) ? sizeof( V_82 ) : V_1 , 0 ) ;
if ( V_49 <= 0 ) goto V_79;
V_1 -= V_49 ;
}
return V_64 ;
}
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 ,
V_3 -> V_6 + V_36 -> V_11 , V_1 , 0 ) ;
if ( V_49 <= 0 || ( unsigned long ) V_49 != V_1 )
goto V_79;
F_36 ( V_3 -> V_2 , ( long ) V_36 -> V_11 ,
( long ) ( V_36 -> V_11 + V_1 ) ) ;
F_37 ( V_3 -> V_2 , ( long ) V_36 -> V_23 ,
V_76 ) ;
if ( V_76 )
{
F_3 ( V_3 -> V_2 ) ;
V_3 -> V_2 = NULL ;
}
if ( V_73 == NULL )
{
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( V_36 -> V_40 >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) ( V_36 -> V_40 ) ;
V_73 = F_38 ( V_77 , V_3 ) ;
if ( V_73 == NULL )
{
goto V_79;
V_49 = - 1 ;
}
F_39 ( V_7 -> V_14 -> V_74 , V_73 ) ;
}
return V_64 ;
V_79:
if ( V_3 != NULL ) F_5 ( V_3 ) ;
if ( V_73 != NULL ) F_3 ( V_73 ) ;
* V_48 = 0 ;
return V_49 ;
}
static int
F_40 ( T_2 * V_7 , struct V_35 * V_36 , int * V_48 )
{
int V_49 = - 1 ;
T_1 * V_3 = NULL ;
T_3 * V_73 = NULL ;
unsigned char V_77 [ 8 ] ;
unsigned long V_1 = V_36 -> V_1 ;
if ( ( V_36 -> V_11 + V_1 ) > V_36 -> V_23 )
goto V_79;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( V_36 -> V_40 >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) V_36 -> V_40 ;
V_73 = F_35 ( V_7 -> V_14 -> V_74 , V_77 ) ;
if ( V_73 != NULL && V_1 < V_36 -> V_23 )
V_73 = NULL ;
if ( V_36 -> V_40 <= V_7 -> V_14 -> V_66 ||
V_36 -> V_40 > V_7 -> V_14 -> V_66 + 10 || V_73 != NULL ||
( V_7 -> V_14 -> V_66 == 0 && V_36 -> type == V_85 ) )
{
unsigned char V_82 [ 256 ] ;
while ( V_1 )
{
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 ,
V_82 ,
V_1 > sizeof( V_82 ) ? sizeof( V_82 ) : V_1 , 0 ) ;
if ( V_49 <= 0 ) goto V_79;
V_1 -= V_49 ;
}
}
else
{
if ( V_1 && V_1 < V_36 -> V_23 )
return F_34 ( V_7 , V_36 , V_48 ) ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 == NULL )
goto V_79;
memcpy ( & ( V_3 -> V_75 ) , V_36 , sizeof( * V_36 ) ) ;
if ( V_1 )
{
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 ,
V_3 -> V_6 , V_1 , 0 ) ;
if ( V_49 <= 0 || ( unsigned long ) V_49 != V_1 )
goto V_79;
}
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( V_36 -> V_40 >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) ( V_36 -> V_40 ) ;
V_73 = F_38 ( V_77 , V_3 ) ;
if ( V_73 == NULL )
goto V_79;
F_39 ( V_7 -> V_14 -> V_74 , V_73 ) ;
}
return V_64 ;
V_79:
if ( V_3 != NULL ) F_5 ( V_3 ) ;
if ( V_73 != NULL ) F_3 ( V_73 ) ;
* V_48 = 0 ;
return V_49 ;
}
static long
F_26 ( T_2 * V_7 , int V_44 , int V_45 , long V_47 , int * V_48 )
{
unsigned char V_86 [ V_24 ] ;
unsigned long V_10 , V_11 , V_1 ;
int V_49 , V_50 ;
struct V_35 V_36 ;
if ( ( V_1 = F_30 ( V_7 , V_47 , V_48 ) ) || * V_48 )
{
if ( * V_48 ) V_7 -> V_21 = V_1 ;
return V_1 ;
}
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 , V_86 ,
V_24 , 0 ) ;
if ( V_49 <= 0 )
{
V_7 -> V_87 = V_88 ;
* V_48 = 0 ;
return V_49 ;
}
if ( V_49 != V_24 )
{
V_50 = V_55 ;
F_25 ( V_89 , V_57 ) ;
goto V_58;
}
F_41 ( V_86 , & V_36 ) ;
if ( V_36 . V_40 != V_7 -> V_14 -> V_66 && ! ( V_7 -> V_14 -> V_65 && V_36 . V_40 == 1 ) )
return F_40 ( V_7 , & V_36 , V_48 ) ;
V_10 = V_36 . V_23 ;
V_11 = V_36 . V_11 ;
V_1 = V_36 . V_1 ;
if ( V_1 && V_1 < V_10 )
return F_34 ( V_7 , & V_36 , V_48 ) ;
if ( ! V_7 -> V_90 && V_7 -> V_14 -> V_61 . V_11 == 0 &&
V_86 [ 0 ] == V_91 )
{
if ( V_86 [ 1 ] == 0 && V_86 [ 2 ] == 0 && V_86 [ 3 ] == 0 )
{
if ( V_7 -> V_41 )
V_7 -> V_41 ( 0 , V_7 -> V_38 , V_20 ,
V_86 , V_24 , V_7 ,
V_7 -> V_43 ) ;
V_7 -> V_21 = 0 ;
return F_26 ( V_7 , V_44 , V_45 ,
V_47 , V_48 ) ;
}
else
{
V_50 = V_55 ;
F_25 ( V_89 , V_57 ) ;
goto V_58;
}
}
if ( ( V_50 = F_28 ( V_7 , & V_36 , V_47 ) ) )
goto V_58;
V_7 -> V_92 = V_45 ;
if ( V_1 > 0 )
{
unsigned char * V_34 = ( unsigned char * ) V_7 -> V_30 -> V_31 + V_24 ;
V_49 = V_7 -> V_83 -> V_84 ( V_7 , V_20 ,
& V_34 [ V_11 ] , V_1 , 0 ) ;
if ( V_49 <= 0 )
{
V_7 -> V_87 = V_88 ;
* V_48 = 0 ;
return V_49 ;
}
}
else
V_49 = 0 ;
if ( V_49 != ( int ) V_1 )
{
V_50 = V_93 ;
F_25 ( V_89 , V_93 ) ;
goto V_58;
}
* V_48 = 1 ;
V_7 -> V_21 = V_1 ;
return V_1 ;
V_58:
F_27 ( V_7 , V_67 , V_50 ) ;
V_7 -> V_21 = 0 ;
* V_48 = 0 ;
return ( - 1 ) ;
}
int F_42 ( T_2 * V_7 , int V_94 , int V_95 , const char * V_96 , int V_97 )
{
unsigned char * V_34 , * V_98 ;
int V_49 ;
unsigned long V_99 ;
if ( V_7 -> V_92 == V_94 )
{
V_98 = ( unsigned char * ) V_7 -> V_30 -> V_31 ;
V_34 = & ( V_98 [ V_24 ] ) ;
V_49 = V_7 -> V_83 -> V_100 -> V_101 ( V_7 ,
V_96 , V_97 , V_7 -> V_51 -> V_52 . V_102 ) ;
V_7 -> V_51 -> V_52 . V_103 = V_49 ;
memcpy ( V_34 , V_7 -> V_51 -> V_52 . V_102 , V_49 ) ;
V_34 += V_49 ;
V_99 = V_49 ;
if( V_7 -> type == V_104 )
{
F_12 ( V_49 <= V_105 ) ;
memcpy ( V_7 -> V_51 -> V_106 ,
V_7 -> V_51 -> V_52 . V_102 , V_49 ) ;
V_7 -> V_51 -> V_107 = V_49 ;
}
else
{
F_12 ( V_49 <= V_105 ) ;
memcpy ( V_7 -> V_51 -> V_108 ,
V_7 -> V_51 -> V_52 . V_102 , V_49 ) ;
V_7 -> V_51 -> V_109 = V_49 ;
}
#ifdef F_43
V_99 &= 0xffff ;
#endif
V_98 = F_44 ( V_7 , V_98 , V_85 , V_99 , 0 , V_99 ) ;
V_7 -> V_21 = ( int ) V_99 + V_24 ;
V_7 -> V_19 = 0 ;
F_45 ( V_7 , 0 ) ;
V_7 -> V_92 = V_95 ;
}
return ( F_6 ( V_7 , V_20 ) ) ;
}
int F_46 ( T_2 * V_7 , int V_94 , int V_95 )
{
unsigned char * V_34 ;
if ( V_7 -> V_92 == V_94 )
{
V_34 = ( unsigned char * ) V_7 -> V_30 -> V_31 ;
* V_34 ++ = V_110 ;
V_7 -> V_14 -> V_111 = V_7 -> V_14 -> V_112 ;
V_7 -> V_21 = V_113 ;
if ( V_7 -> V_38 == V_39 ) {
V_7 -> V_14 -> V_112 ++ ;
F_22 ( V_7 -> V_14 -> V_111 , V_34 ) ;
V_7 -> V_21 += 2 ;
}
V_7 -> V_19 = 0 ;
F_47 ( V_7 , V_110 , 0 ,
V_7 -> V_14 -> V_111 , 0 , 0 ) ;
F_45 ( V_7 , 1 ) ;
V_7 -> V_92 = V_95 ;
}
return ( F_6 ( V_7 , V_114 ) ) ;
}
static int F_48 ( T_4 * V_4 , unsigned long * V_99 , T_5 * V_115 )
{
int V_116 ;
unsigned char * V_34 ;
V_116 = F_49 ( V_115 , NULL ) ;
if ( ! F_29 ( V_4 , ( int ) ( V_116 + ( * V_99 ) + 3 ) ) )
{
F_25 ( V_117 , V_71 ) ;
return 0 ;
}
V_34 = ( unsigned char * ) & ( V_4 -> V_31 [ * V_99 ] ) ;
F_21 ( V_116 , V_34 ) ;
F_49 ( V_115 , & V_34 ) ;
* V_99 += V_116 + 3 ;
return 1 ;
}
unsigned long F_50 ( T_2 * V_7 , T_5 * V_115 )
{
unsigned char * V_34 ;
int V_49 ;
unsigned long V_99 = 3 + V_24 ;
T_4 * V_4 ;
V_4 = V_7 -> V_30 ;
if ( ! F_29 ( V_4 , 10 ) )
{
F_25 ( V_118 , V_71 ) ;
return ( 0 ) ;
}
if ( V_115 != NULL )
{
T_6 V_119 ;
if ( ! F_51 ( & V_119 , V_7 -> V_120 -> V_121 , V_115 , NULL ) )
{
F_25 ( V_118 , V_122 ) ;
return ( 0 ) ;
}
F_52 ( & V_119 ) ;
F_53 () ;
for ( V_49 = 0 ; V_49 < F_54 ( V_119 . V_123 ) ; V_49 ++ )
{
V_115 = F_55 ( V_119 . V_123 , V_49 ) ;
if ( ! F_48 ( V_4 , & V_99 , V_115 ) )
{
F_56 ( & V_119 ) ;
return 0 ;
}
}
F_56 ( & V_119 ) ;
}
for ( V_49 = 0 ; V_49 < F_54 ( V_7 -> V_120 -> V_124 ) ; V_49 ++ )
{
V_115 = F_55 ( V_7 -> V_120 -> V_124 , V_49 ) ;
if ( ! F_48 ( V_4 , & V_99 , V_115 ) )
return 0 ;
}
V_99 -= ( 3 + V_24 ) ;
V_34 = ( unsigned char * ) & ( V_4 -> V_31 [ V_24 ] ) ;
F_21 ( V_99 , V_34 ) ;
V_99 += 3 ;
V_34 = ( unsigned char * ) & ( V_4 -> V_31 [ 0 ] ) ;
V_34 = F_44 ( V_7 , V_34 , V_125 , V_99 , 0 , V_99 ) ;
V_99 += V_24 ;
return ( V_99 ) ;
}
int F_57 ( T_2 * V_7 , int V_126 )
{
if ( V_126 > 0 )
{
fprintf ( V_127 , L_1 , __FILE__ , __LINE__ ) ;
return 1 ;
}
if ( ! F_58 ( V_7 ) )
{
return V_126 ;
}
#ifndef F_59
if ( ! F_60 ( V_7 ) && ! V_7 -> V_128 )
#else
if ( ! F_60 ( V_7 ) )
#endif
{
F_61 ( F_62 ( V_7 ) , V_129 ) ;
return V_126 ;
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
return F_63 ( V_7 ) ;
}
int
F_64 ( unsigned short V_40 , int V_130 )
{
return V_40 * 2 - V_130 ;
}
int
F_65 ( T_2 * V_7 )
{
T_7 V_131 = V_7 -> V_14 -> V_132 ;
T_8 V_133 ;
T_3 * V_73 ;
T_1 * V_3 ;
int V_134 = 0 ;
V_133 = F_66 ( V_131 ) ;
for ( V_73 = F_67 ( & V_133 ) ; V_73 != NULL ; V_73 = F_67 ( & V_133 ) )
{
V_3 = ( T_1 * ) V_73 -> V_31 ;
if ( F_68 ( V_7 ,
( unsigned short ) F_64 ( V_3 -> V_75 . V_40 , V_3 -> V_75 . V_130 ) ,
0 , & V_134 ) <= 0 && V_134 )
{
fprintf ( V_127 , L_2 ) ;
return - 1 ;
}
}
return 1 ;
}
int
F_45 ( T_2 * V_7 , int V_130 )
{
T_3 * V_73 ;
T_1 * V_3 ;
unsigned char V_77 [ 8 ] ;
F_12 ( V_7 -> V_19 == 0 ) ;
V_3 = F_1 ( V_7 -> V_21 , 0 ) ;
memcpy ( V_3 -> V_6 , V_7 -> V_30 -> V_31 , V_7 -> V_21 ) ;
if ( V_130 )
{
F_12 ( V_7 -> V_14 -> V_22 . V_23 +
( ( V_7 -> V_38 == V_135 ) ? V_113 : 3 ) == ( unsigned int ) V_7 -> V_21 ) ;
}
else
{
F_12 ( V_7 -> V_14 -> V_22 . V_23 +
V_24 == ( unsigned int ) V_7 -> V_21 ) ;
}
V_3 -> V_75 . V_23 = V_7 -> V_14 -> V_22 . V_23 ;
V_3 -> V_75 . V_40 = V_7 -> V_14 -> V_22 . V_40 ;
V_3 -> V_75 . type = V_7 -> V_14 -> V_22 . type ;
V_3 -> V_75 . V_11 = 0 ;
V_3 -> V_75 . V_1 = V_7 -> V_14 -> V_22 . V_23 ;
V_3 -> V_75 . V_130 = V_130 ;
V_3 -> V_75 . V_136 . V_26 = V_7 -> V_26 ;
V_3 -> V_75 . V_136 . V_25 = V_7 -> V_25 ;
V_3 -> V_75 . V_136 . V_137 = V_7 -> V_137 ;
V_3 -> V_75 . V_136 . V_138 = V_7 -> V_138 ;
V_3 -> V_75 . V_136 . V_139 = V_7 -> V_14 -> V_140 ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( F_64 ( V_3 -> V_75 . V_40 ,
V_3 -> V_75 . V_130 ) >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) ( F_64 ( V_3 -> V_75 . V_40 ,
V_3 -> V_75 . V_130 ) ) ;
V_73 = F_38 ( V_77 , V_3 ) ;
if ( V_73 == NULL )
{
F_5 ( V_3 ) ;
return 0 ;
}
#if 0
fprintf( stderr, "buffered messge: \ttype = %xx\n", msg_buf->type);
fprintf( stderr, "\t\t\t\t\tlen = %d\n", msg_buf->len);
fprintf( stderr, "\t\t\t\t\tseq_num = %d\n", msg_buf->seq_num);
#endif
F_39 ( V_7 -> V_14 -> V_132 , V_73 ) ;
return 1 ;
}
int
F_68 ( T_2 * V_7 , unsigned short V_40 , unsigned long V_11 ,
int * V_134 )
{
int V_8 ;
T_3 * V_73 ;
T_1 * V_3 ;
unsigned long V_141 ;
unsigned char V_77 [ 8 ] ;
struct V_142 V_143 ;
unsigned char V_144 [ 8 ] ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_77 [ 6 ] = ( unsigned char ) ( V_40 >> 8 ) ;
V_77 [ 7 ] = ( unsigned char ) V_40 ;
V_73 = F_35 ( V_7 -> V_14 -> V_132 , V_77 ) ;
if ( V_73 == NULL )
{
fprintf ( V_127 , L_3 , V_40 ) ;
* V_134 = 0 ;
return 0 ;
}
* V_134 = 1 ;
V_3 = ( T_1 * ) V_73 -> V_31 ;
if ( V_3 -> V_75 . V_130 )
V_141 = V_113 ;
else
V_141 = V_24 ;
memcpy ( V_7 -> V_30 -> V_31 , V_3 -> V_6 ,
V_3 -> V_75 . V_23 + V_141 ) ;
V_7 -> V_21 = V_3 -> V_75 . V_23 + V_141 ;
F_47 ( V_7 , V_3 -> V_75 . type ,
V_3 -> V_75 . V_23 , V_3 -> V_75 . V_40 , 0 ,
V_3 -> V_75 . V_1 ) ;
V_143 . V_26 = V_7 -> V_26 ;
V_143 . V_25 = V_7 -> V_25 ;
V_143 . V_137 = V_7 -> V_137 ;
V_143 . V_138 = V_7 -> V_138 ;
V_143 . V_139 = V_7 -> V_14 -> V_140 ;
V_143 . V_139 = V_7 -> V_14 -> V_140 ;
V_7 -> V_14 -> V_33 = 1 ;
V_7 -> V_26 = V_3 -> V_75 . V_136 . V_26 ;
V_7 -> V_25 = V_3 -> V_75 . V_136 . V_25 ;
V_7 -> V_137 = V_3 -> V_75 . V_136 . V_137 ;
V_7 -> V_138 = V_3 -> V_75 . V_136 . V_138 ;
V_7 -> V_14 -> V_140 = V_3 -> V_75 . V_136 . V_139 ;
if ( V_3 -> V_75 . V_136 . V_139 == V_143 . V_139 - 1 )
{
memcpy ( V_144 , V_7 -> V_51 -> V_145 , sizeof( V_7 -> V_51 -> V_145 ) ) ;
memcpy ( V_7 -> V_51 -> V_145 , V_7 -> V_14 -> V_146 , sizeof( V_7 -> V_51 -> V_145 ) ) ;
}
V_8 = F_6 ( V_7 , V_3 -> V_75 . V_130 ?
V_114 : V_20 ) ;
V_7 -> V_26 = V_143 . V_26 ;
V_7 -> V_25 = V_143 . V_25 ;
V_7 -> V_137 = V_143 . V_137 ;
V_7 -> V_138 = V_143 . V_138 ;
V_7 -> V_14 -> V_140 = V_143 . V_139 ;
if ( V_3 -> V_75 . V_136 . V_139 == V_143 . V_139 - 1 )
{
memcpy ( V_7 -> V_14 -> V_146 , V_7 -> V_51 -> V_145 , sizeof( V_7 -> V_51 -> V_145 ) ) ;
memcpy ( V_7 -> V_51 -> V_145 , V_144 , sizeof( V_7 -> V_51 -> V_145 ) ) ;
}
V_7 -> V_14 -> V_33 = 0 ;
( void ) F_17 ( F_10 ( V_7 ) ) ;
return V_8 ;
}
void
F_69 ( T_2 * V_7 )
{
T_3 * V_73 ;
for( V_73 = F_32 ( V_7 -> V_14 -> V_132 ) ;
V_73 != NULL ; V_73 = F_32 ( V_7 -> V_14 -> V_132 ) )
{
F_5 ( ( T_1 * ) V_73 -> V_31 ) ;
F_33 ( V_73 ) ;
}
}
unsigned char *
F_44 ( T_2 * V_7 , unsigned char * V_34 , unsigned char V_46 ,
unsigned long V_10 , unsigned long V_11 , unsigned long V_1 )
{
if ( V_11 == 0 && ! V_7 -> V_14 -> V_65 )
{
V_7 -> V_14 -> V_111 = V_7 -> V_14 -> V_112 ;
V_7 -> V_14 -> V_112 ++ ;
}
F_47 ( V_7 , V_46 , V_10 , V_7 -> V_14 -> V_111 ,
V_11 , V_1 ) ;
return V_34 += V_24 ;
}
static void
F_47 ( T_2 * V_7 , unsigned char V_46 ,
unsigned long V_10 , unsigned short V_147 , unsigned long V_11 ,
unsigned long V_1 )
{
struct V_35 * V_36 = & V_7 -> V_14 -> V_22 ;
V_36 -> type = V_46 ;
V_36 -> V_23 = V_10 ;
V_36 -> V_40 = V_147 ;
V_36 -> V_11 = V_11 ;
V_36 -> V_1 = V_1 ;
}
static void
F_18 ( T_2 * V_7 , unsigned long V_11 ,
unsigned long V_1 )
{
struct V_35 * V_36 = & V_7 -> V_14 -> V_22 ;
V_36 -> V_11 = V_11 ;
V_36 -> V_1 = V_1 ;
}
static unsigned char *
F_19 ( T_2 * V_7 , unsigned char * V_34 )
{
struct V_35 * V_36 = & V_7 -> V_14 -> V_22 ;
* V_34 ++ = V_36 -> type ;
F_21 ( V_36 -> V_23 , V_34 ) ;
F_22 ( V_36 -> V_40 , V_34 ) ;
F_21 ( V_36 -> V_11 , V_34 ) ;
F_21 ( V_36 -> V_1 , V_34 ) ;
return V_34 ;
}
unsigned int
F_7 ( void )
{
return ( V_148 [ ( sizeof( V_148 ) /
sizeof( V_148 [ 0 ] ) ) - 1 ] ) ;
}
static unsigned int
F_11 ( unsigned int V_9 )
{
unsigned int V_49 ;
if ( V_9 == 0 )
return V_148 [ 0 ] ;
for ( V_49 = 0 ; V_49 < sizeof( V_148 ) / sizeof( V_148 [ 0 ] ) ; V_49 ++ )
if ( V_9 > V_148 [ V_49 ] )
return V_148 [ V_49 ] ;
return V_9 ;
}
void
F_41 ( unsigned char * V_31 , struct V_35 * V_36 )
{
memset ( V_36 , 0x00 , sizeof( struct V_35 ) ) ;
V_36 -> type = * ( V_31 ++ ) ;
F_70 ( V_31 , V_36 -> V_23 ) ;
F_71 ( V_31 , V_36 -> V_40 ) ;
F_70 ( V_31 , V_36 -> V_11 ) ;
F_70 ( V_31 , V_36 -> V_1 ) ;
}
void
F_72 ( unsigned char * V_31 , struct V_149 * V_150 )
{
memset ( V_150 , 0x00 , sizeof( struct V_149 ) ) ;
V_150 -> type = * ( V_31 ++ ) ;
}
int F_73 ( T_2 * V_7 )
{
int V_8 ;
#ifndef F_74
if ( F_75 ( F_10 ( V_7 ) ) &&
! ( V_7 -> V_151 & V_152 ) )
{
V_8 = F_76 ( F_10 ( V_7 ) ) ;
if ( V_8 < 0 ) return - 1 ;
if ( V_8 == 0 )
F_9 ( F_10 ( V_7 ) , V_153 , 1 , NULL ) ;
}
#endif
V_8 = F_77 ( V_7 ) ;
#ifndef F_74
F_9 ( F_10 ( V_7 ) , V_153 , 0 , NULL ) ;
#endif
return V_8 ;
}
int
F_78 ( T_2 * V_7 )
{
unsigned char * V_34 = & V_7 -> V_51 -> V_154 . V_31 [ 0 ] , * V_155 ;
unsigned short V_156 ;
unsigned int V_157 ;
unsigned int V_158 = 16 ;
V_156 = * V_34 ++ ;
F_71 ( V_34 , V_157 ) ;
V_155 = V_34 ;
if ( V_7 -> V_41 )
V_7 -> V_41 ( 0 , V_7 -> V_38 , V_159 ,
& V_7 -> V_51 -> V_154 . V_31 [ 0 ] , V_7 -> V_51 -> V_154 . V_160 ,
V_7 , V_7 -> V_43 ) ;
if ( V_156 == V_161 )
{
unsigned char * V_162 , * V_163 ;
int V_164 ;
V_162 = F_2 ( 1 + 2 + V_157 + V_158 ) ;
V_163 = V_162 ;
* V_163 ++ = V_165 ;
F_22 ( V_157 , V_163 ) ;
memcpy ( V_163 , V_155 , V_157 ) ;
V_163 += V_157 ;
F_79 ( V_163 , V_158 ) ;
V_164 = F_20 ( V_7 , V_159 , V_162 , 3 + V_157 + V_158 ) ;
if ( V_164 >= 0 && V_7 -> V_41 )
V_7 -> V_41 ( 1 , V_7 -> V_38 , V_159 ,
V_162 , 3 + V_157 + V_158 ,
V_7 , V_7 -> V_43 ) ;
F_3 ( V_162 ) ;
if ( V_164 < 0 )
return V_164 ;
}
else if ( V_156 == V_165 )
{
unsigned int V_40 ;
F_71 ( V_155 , V_40 ) ;
if ( V_157 == 18 && V_40 == V_7 -> V_166 )
{
F_80 ( V_7 ) ;
V_7 -> V_166 ++ ;
V_7 -> V_128 = 0 ;
}
}
return 0 ;
}
int
F_81 ( T_2 * V_7 )
{
unsigned char * V_4 , * V_34 ;
int V_8 ;
unsigned int V_157 = 18 ;
unsigned int V_158 = 16 ;
if ( ! ( V_7 -> V_167 & V_168 ) ||
V_7 -> V_167 & V_169 )
{
F_25 ( V_170 , V_171 ) ;
return - 1 ;
}
if ( V_7 -> V_128 )
{
F_25 ( V_170 , V_172 ) ;
return - 1 ;
}
if ( F_60 ( V_7 ) || V_7 -> V_173 )
{
F_25 ( V_170 , V_57 ) ;
return - 1 ;
}
F_12 ( V_157 + V_158 <= 16381 ) ;
V_4 = F_2 ( 1 + 2 + V_157 + V_158 ) ;
V_34 = V_4 ;
* V_34 ++ = V_161 ;
F_22 ( V_157 , V_34 ) ;
F_22 ( V_7 -> V_166 , V_34 ) ;
F_79 ( V_34 , 16 ) ;
V_34 += 16 ;
F_79 ( V_34 , V_158 ) ;
V_8 = F_20 ( V_7 , V_159 , V_4 , 3 + V_157 + V_158 ) ;
if ( V_8 >= 0 )
{
if ( V_7 -> V_41 )
V_7 -> V_41 ( 1 , V_7 -> V_38 , V_159 ,
V_4 , 3 + V_157 + V_158 ,
V_7 , V_7 -> V_43 ) ;
F_82 ( V_7 ) ;
V_7 -> V_128 = 1 ;
}
F_3 ( V_4 ) ;
return V_8 ;
}
