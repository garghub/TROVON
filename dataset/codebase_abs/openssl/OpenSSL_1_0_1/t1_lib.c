long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
if ( ! F_3 ( V_1 ) ) return ( 0 ) ;
V_1 -> V_2 -> V_3 ( V_1 ) ;
return ( 1 ) ;
}
void F_4 ( T_1 * V_1 )
{
#ifndef F_5
if ( V_1 -> V_4 )
{
F_6 ( V_1 -> V_4 ) ;
}
#endif
F_7 ( V_1 ) ;
}
void F_8 ( T_1 * V_1 )
{
F_9 ( V_1 ) ;
V_1 -> V_5 = V_1 -> V_2 -> V_5 ;
}
int F_10 ( int V_6 )
{
if ( ( V_6 < 1 ) || ( ( unsigned int ) V_6 >
sizeof( V_7 ) / sizeof( V_7 [ 0 ] ) ) )
return 0 ;
return V_7 [ V_6 - 1 ] ;
}
int F_11 ( int V_8 )
{
switch ( V_8 )
{
case V_9 :
return 1 ;
case V_10 :
return 2 ;
case V_11 :
return 3 ;
case V_12 :
return 4 ;
case V_13 :
return 5 ;
case V_14 :
return 6 ;
case V_15 :
return 7 ;
case V_16 :
return 8 ;
case V_17 :
return 9 ;
case V_18 :
return 10 ;
case V_19 :
return 11 ;
case V_20 :
return 12 ;
case V_21 :
return 13 ;
case V_22 :
return 14 ;
case V_23 :
return 15 ;
case V_24 :
return 16 ;
case V_25 :
return 17 ;
case V_26 :
return 18 ;
case V_27 :
return 19 ;
case V_28 :
return 20 ;
case V_29 :
return 21 ;
case V_30 :
return 22 ;
case V_31 :
return 23 ;
case V_32 :
return 24 ;
case V_33 :
return 25 ;
default:
return 0 ;
}
}
int F_12 ( T_1 * V_1 , unsigned char * V_34 )
{
T_2 V_35 = sizeof( V_36 ) ;
#ifdef F_13
if ( F_14 () )
V_35 -= 2 ;
#endif
if ( V_34 )
memcpy ( V_34 , V_36 , V_35 ) ;
return ( int ) V_35 ;
}
unsigned char * F_15 ( T_1 * V_1 , unsigned char * V_34 , unsigned char * V_37 )
{
int V_38 = 0 ;
unsigned char * V_39 = V_34 ;
if ( V_1 -> V_40 == V_41
&& ! V_1 -> V_42 -> V_43 )
return V_34 ;
V_39 += 2 ;
if ( V_39 >= V_37 ) return NULL ;
if ( V_1 -> V_44 != NULL )
{
unsigned long V_45 ;
long V_46 ;
if ( ( V_46 = V_37 - V_39 - 9 ) < 0
|| ( V_45 = strlen ( V_1 -> V_44 ) ) > ( unsigned long ) V_46 )
return NULL ;
F_16 ( V_47 , V_39 ) ;
F_16 ( V_45 + 5 , V_39 ) ;
F_16 ( V_45 + 3 , V_39 ) ;
* ( V_39 ++ ) = ( unsigned char ) V_48 ;
F_16 ( V_45 , V_39 ) ;
memcpy ( V_39 , V_1 -> V_44 , V_45 ) ;
V_39 += V_45 ;
}
if ( V_1 -> V_49 )
{
int V_50 ;
if( ! F_17 ( V_1 , 0 , & V_50 , 0 ) )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
if( ( V_37 - V_34 - 4 - V_50 ) < 0 ) return NULL ;
F_16 ( V_53 , V_39 ) ;
F_16 ( V_50 , V_39 ) ;
if( ! F_17 ( V_1 , V_39 , & V_50 , V_50 ) )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
V_39 += V_50 ;
}
#ifndef F_19
if ( V_1 -> V_54 . V_55 != NULL )
{
int V_56 = strlen ( V_1 -> V_54 . V_55 ) ;
if ( V_56 > 255 || V_56 == 0 )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
if ( ( V_37 - V_39 - 5 - V_56 ) < 0 ) return NULL ;
F_16 ( V_57 , V_39 ) ;
F_16 ( V_56 + 1 , V_39 ) ;
( * V_39 ++ ) = ( unsigned char ) V_56 ;
memcpy ( V_39 , V_1 -> V_54 . V_55 , V_56 ) ;
V_39 += V_56 ;
}
#endif
#ifndef F_20
if ( V_1 -> V_58 != NULL &&
V_1 -> V_5 != V_59 )
{
long V_46 ;
if ( ( V_46 = V_37 - V_39 - 5 ) < 0 ) return NULL ;
if ( V_1 -> V_60 > ( unsigned long ) V_46 ) return NULL ;
if ( V_1 -> V_60 > 255 )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
F_16 ( V_61 , V_39 ) ;
F_16 ( V_1 -> V_60 + 1 , V_39 ) ;
* ( V_39 ++ ) = ( unsigned char ) V_1 -> V_60 ;
memcpy ( V_39 , V_1 -> V_58 , V_1 -> V_60 ) ;
V_39 += V_1 -> V_60 ;
}
if ( V_1 -> V_62 != NULL &&
V_1 -> V_5 != V_59 )
{
long V_46 ;
if ( ( V_46 = V_37 - V_39 - 6 ) < 0 ) return NULL ;
if ( V_1 -> V_63 > ( unsigned long ) V_46 ) return NULL ;
if ( V_1 -> V_63 > 65532 )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
F_16 ( V_64 , V_39 ) ;
F_16 ( V_1 -> V_63 + 2 , V_39 ) ;
F_16 ( V_1 -> V_63 , V_39 ) ;
memcpy ( V_39 , V_1 -> V_62 , V_1 -> V_63 ) ;
V_39 += V_1 -> V_63 ;
}
#endif
if ( ! ( F_21 ( V_1 ) & V_65 ) )
{
int V_66 ;
if ( ! V_1 -> V_67 && V_1 -> V_68 && V_1 -> V_68 -> V_69 )
V_66 = V_1 -> V_68 -> V_70 ;
else if ( V_1 -> V_68 && V_1 -> V_4 &&
V_1 -> V_4 -> V_71 )
{
V_66 = V_1 -> V_4 -> V_72 ;
V_1 -> V_68 -> V_69 = F_22 ( V_66 ) ;
if ( ! V_1 -> V_68 -> V_69 )
return NULL ;
memcpy ( V_1 -> V_68 -> V_69 ,
V_1 -> V_4 -> V_71 ,
V_66 ) ;
V_1 -> V_68 -> V_70 = V_66 ;
}
else
V_66 = 0 ;
if ( V_66 == 0 && V_1 -> V_4 &&
V_1 -> V_4 -> V_71 == NULL )
goto V_73;
if ( ( long ) ( V_37 - V_39 - 4 - V_66 ) < 0 ) return NULL ;
F_16 ( V_74 , V_39 ) ;
F_16 ( V_66 , V_39 ) ;
if ( V_66 )
{
memcpy ( V_39 , V_1 -> V_68 -> V_69 , V_66 ) ;
V_39 += V_66 ;
}
}
V_73:
if ( F_23 ( V_1 ) >= V_75 )
{
if ( ( T_2 ) ( V_37 - V_39 ) < sizeof( V_36 ) + 6 )
return NULL ;
F_16 ( V_76 , V_39 ) ;
F_16 ( sizeof( V_36 ) + 2 , V_39 ) ;
F_16 ( sizeof( V_36 ) , V_39 ) ;
memcpy ( V_39 , V_36 , sizeof( V_36 ) ) ;
V_39 += sizeof( V_36 ) ;
}
#ifdef F_24
if ( V_1 -> V_42 -> V_77 != NULL &&
V_1 -> V_5 != V_59 )
{
T_2 V_78 = V_1 -> V_42 -> V_79 ;
if ( ( long ) ( V_37 - V_39 - 6 - V_78 < 0 ) )
return NULL ;
if ( V_78 > 0xFFFD )
return NULL ;
F_16 ( F_24 , V_39 ) ;
F_16 ( V_78 + 2 , V_39 ) ;
F_16 ( V_78 , V_39 ) ;
memcpy ( V_39 , V_1 -> V_42 -> V_77 , V_78 ) ;
V_39 += V_78 ;
}
#endif
if ( V_1 -> V_80 == V_81 &&
V_1 -> V_5 != V_59 )
{
int V_82 ;
long V_83 , V_84 , V_85 ;
T_3 * V_86 ;
V_84 = 0 ;
for ( V_82 = 0 ; V_82 < F_25 ( V_1 -> V_87 ) ; V_82 ++ )
{
V_86 = F_26 ( V_1 -> V_87 , V_82 ) ;
V_85 = F_27 ( V_86 , NULL ) ;
if ( V_85 <= 0 )
return NULL ;
V_84 += V_85 + 2 ;
}
if ( V_1 -> V_88 )
{
V_83 = F_28 ( V_1 -> V_88 , NULL ) ;
if ( V_83 < 0 )
return NULL ;
}
else
V_83 = 0 ;
if ( ( long ) ( V_37 - V_39 - 7 - V_83 - V_84 ) < 0 ) return NULL ;
F_16 ( V_89 , V_39 ) ;
if ( V_83 + V_84 > 0xFFF0 )
return NULL ;
F_16 ( V_83 + V_84 + 5 , V_39 ) ;
* ( V_39 ++ ) = V_81 ;
F_16 ( V_84 , V_39 ) ;
for ( V_82 = 0 ; V_82 < F_25 ( V_1 -> V_87 ) ; V_82 ++ )
{
unsigned char * V_90 = V_39 ;
V_86 = F_26 ( V_1 -> V_87 , V_82 ) ;
V_39 += 2 ;
V_85 = F_27 ( V_86 , & V_39 ) ;
F_16 ( V_85 , V_90 ) ;
}
F_16 ( V_83 , V_39 ) ;
if ( V_83 > 0 )
F_28 ( V_1 -> V_88 , & V_39 ) ;
}
#ifndef F_29
F_16 ( V_91 , V_39 ) ;
F_16 ( 1 , V_39 ) ;
if ( V_1 -> V_92 & V_93 )
* ( V_39 ++ ) = V_94 ;
else
* ( V_39 ++ ) = V_95 ;
#endif
#ifndef F_30
if ( V_1 -> V_96 -> V_97 && ! V_1 -> V_42 -> V_98 . V_99 )
{
if ( V_37 - V_39 - 4 < 0 )
return NULL ;
F_16 ( V_100 , V_39 ) ;
F_16 ( 0 , V_39 ) ;
}
#endif
if( F_31 ( V_1 ) )
{
int V_50 ;
F_32 ( V_1 , 0 , & V_50 , 0 ) ;
if( ( V_37 - V_34 - 4 - V_50 ) < 0 ) return NULL ;
F_16 ( V_101 , V_39 ) ;
F_16 ( V_50 , V_39 ) ;
if( F_32 ( V_1 , V_39 , & V_50 , V_50 ) )
{
F_18 ( V_51 , V_52 ) ;
return NULL ;
}
V_39 += V_50 ;
}
if ( ( V_38 = V_39 - V_34 - 2 ) == 0 )
return V_34 ;
F_16 ( V_38 , V_34 ) ;
return V_39 ;
}
unsigned char * F_33 ( T_1 * V_1 , unsigned char * V_34 , unsigned char * V_37 )
{
int V_38 = 0 ;
unsigned char * V_39 = V_34 ;
#ifndef F_30
int V_102 ;
#endif
if ( V_1 -> V_5 == V_41 && ! V_1 -> V_42 -> V_43 )
return V_34 ;
V_39 += 2 ;
if ( V_39 >= V_37 ) return NULL ;
if ( ! V_1 -> V_103 && V_1 -> V_104 == 1 && V_1 -> V_68 -> V_44 != NULL )
{
if ( ( long ) ( V_37 - V_39 - 4 ) < 0 ) return NULL ;
F_16 ( V_47 , V_39 ) ;
F_16 ( 0 , V_39 ) ;
}
if( V_1 -> V_42 -> V_43 )
{
int V_50 ;
if( ! F_34 ( V_1 , 0 , & V_50 , 0 ) )
{
F_18 ( V_105 , V_52 ) ;
return NULL ;
}
if( ( V_37 - V_34 - 4 - V_50 ) < 0 ) return NULL ;
F_16 ( V_53 , V_39 ) ;
F_16 ( V_50 , V_39 ) ;
if( ! F_34 ( V_1 , V_39 , & V_50 , V_50 ) )
{
F_18 ( V_105 , V_52 ) ;
return NULL ;
}
V_39 += V_50 ;
}
#ifndef F_20
if ( V_1 -> V_58 != NULL &&
V_1 -> V_5 != V_59 )
{
long V_46 ;
if ( ( V_46 = V_37 - V_39 - 5 ) < 0 ) return NULL ;
if ( V_1 -> V_60 > ( unsigned long ) V_46 ) return NULL ;
if ( V_1 -> V_60 > 255 )
{
F_18 ( V_105 , V_52 ) ;
return NULL ;
}
F_16 ( V_61 , V_39 ) ;
F_16 ( V_1 -> V_60 + 1 , V_39 ) ;
* ( V_39 ++ ) = ( unsigned char ) V_1 -> V_60 ;
memcpy ( V_39 , V_1 -> V_58 , V_1 -> V_60 ) ;
V_39 += V_1 -> V_60 ;
}
#endif
if ( V_1 -> V_106
&& ! ( F_21 ( V_1 ) & V_65 ) )
{
if ( ( long ) ( V_37 - V_39 - 4 ) < 0 ) return NULL ;
F_16 ( V_74 , V_39 ) ;
F_16 ( 0 , V_39 ) ;
}
if ( V_1 -> V_107 )
{
if ( ( long ) ( V_37 - V_39 - 4 ) < 0 ) return NULL ;
F_16 ( V_89 , V_39 ) ;
F_16 ( 0 , V_39 ) ;
}
#ifdef F_24
if ( V_1 -> V_42 -> V_108 != NULL &&
V_1 -> V_5 != V_59 )
{
T_2 V_109 = V_1 -> V_42 -> V_110 ;
if ( ( long ) ( V_37 - V_39 - 6 - V_109 ) < 0 )
return NULL ;
if ( V_109 > 0xFFFD )
return NULL ;
F_16 ( F_24 , V_39 ) ;
F_16 ( V_109 + 2 , V_39 ) ;
F_16 ( V_109 , V_39 ) ;
memcpy ( V_39 , V_1 -> V_42 -> V_108 , V_109 ) ;
V_39 += V_109 ;
}
#endif
if( V_1 -> V_111 )
{
int V_50 ;
F_35 ( V_1 , 0 , & V_50 , 0 ) ;
if( ( V_37 - V_34 - 4 - V_50 ) < 0 ) return NULL ;
F_16 ( V_101 , V_39 ) ;
F_16 ( V_50 , V_39 ) ;
if( F_35 ( V_1 , V_39 , & V_50 , V_50 ) )
{
F_18 ( V_105 , V_52 ) ;
return NULL ;
}
V_39 += V_50 ;
}
if ( ( ( V_1 -> V_42 -> V_98 . V_112 -> V_86 & 0xFFFF ) == 0x80 || ( V_1 -> V_42 -> V_98 . V_112 -> V_86 & 0xFFFF ) == 0x81 )
&& ( F_21 ( V_1 ) & V_113 ) )
{ const unsigned char V_114 [ 36 ] = {
0xfd , 0xe8 ,
0x00 , 0x20 ,
0x30 , 0x1e , 0x30 , 0x08 , 0x06 , 0x06 , 0x2a , 0x85 ,
0x03 , 0x02 , 0x02 , 0x09 , 0x30 , 0x08 , 0x06 , 0x06 ,
0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x16 , 0x30 , 0x08 ,
0x06 , 0x06 , 0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x17 } ;
if ( V_37 - V_39 < 36 ) return NULL ;
memcpy ( V_39 , V_114 , 36 ) ;
V_39 += 36 ;
}
#ifndef F_29
if ( V_1 -> V_92 & V_95 )
{
F_16 ( V_91 , V_39 ) ;
F_16 ( 1 , V_39 ) ;
if ( V_1 -> V_92 & V_93 )
* ( V_39 ++ ) = V_94 ;
else
* ( V_39 ++ ) = V_95 ;
}
#endif
#ifndef F_30
V_102 = V_1 -> V_42 -> V_102 ;
V_1 -> V_42 -> V_102 = 0 ;
if ( V_102 && V_1 -> V_96 -> V_115 )
{
const unsigned char * V_116 ;
unsigned int V_117 ;
int V_118 ;
V_118 = V_1 -> V_96 -> V_115 ( V_1 , & V_116 , & V_117 , V_1 -> V_96 -> V_119 ) ;
if ( V_118 == V_120 )
{
if ( ( long ) ( V_37 - V_39 - 4 - V_117 ) < 0 ) return NULL ;
F_16 ( V_100 , V_39 ) ;
F_16 ( V_117 , V_39 ) ;
memcpy ( V_39 , V_116 , V_117 ) ;
V_39 += V_117 ;
V_1 -> V_42 -> V_102 = 1 ;
}
}
#endif
if ( ( V_38 = V_39 - V_34 - 2 ) == 0 )
return V_34 ;
F_16 ( V_38 , V_34 ) ;
return V_39 ;
}
int F_36 ( T_1 * V_1 , unsigned char * * V_34 , unsigned char * V_121 , int V_122 , int * V_123 )
{
unsigned short type ;
unsigned short V_124 ;
unsigned short V_125 ;
unsigned char * V_71 = * V_34 ;
int V_126 = 0 ;
int V_127 = 0 ;
V_1 -> V_104 = 0 ;
V_1 -> V_80 = - 1 ;
#ifndef F_30
V_1 -> V_42 -> V_102 = 0 ;
#endif
#ifndef F_29
V_1 -> V_92 &= ~ ( V_95 |
V_94 ) ;
#endif
if ( V_71 >= ( V_121 + V_122 - 2 ) )
goto V_128;
F_37 ( V_71 , V_125 ) ;
if ( V_71 > ( V_121 + V_122 - V_125 ) )
goto V_128;
while ( V_71 <= ( V_121 + V_122 - 4 ) )
{
F_37 ( V_71 , type ) ;
F_37 ( V_71 , V_124 ) ;
if ( V_71 + V_124 > ( V_121 + V_122 ) )
goto V_128;
#if 0
fprintf(stderr,"Received extension type %d size %d\n",type,size);
#endif
if ( V_1 -> V_129 )
V_1 -> V_129 ( V_1 , 0 , type , V_71 , V_124 ,
V_1 -> V_130 ) ;
if ( type == V_47 )
{
unsigned char * V_131 ;
int V_132 ;
int V_133 ;
if ( V_124 < 2 )
{
* V_123 = V_134 ;
return 0 ;
}
F_37 ( V_71 , V_133 ) ;
V_124 -= 2 ;
if ( V_133 > V_124 )
{
* V_123 = V_134 ;
return 0 ;
}
V_131 = V_71 ;
while ( V_133 > 3 )
{
V_132 = * ( V_131 ++ ) ;
F_37 ( V_131 , V_125 ) ;
V_133 -= 3 ;
if ( V_125 > V_133 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_1 -> V_104 == 0 )
switch ( V_132 )
{
case V_48 :
if ( ! V_1 -> V_103 )
{
if( V_1 -> V_68 -> V_44 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_125 > V_135 )
{
* V_123 = V_136 ;
return 0 ;
}
if ( ( V_1 -> V_68 -> V_44 = F_22 ( V_125 + 1 ) ) == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
memcpy ( V_1 -> V_68 -> V_44 , V_131 , V_125 ) ;
V_1 -> V_68 -> V_44 [ V_125 ] = '\0' ;
if ( strlen ( V_1 -> V_68 -> V_44 ) != V_125 ) {
F_6 ( V_1 -> V_68 -> V_44 ) ;
V_1 -> V_68 -> V_44 = NULL ;
* V_123 = V_136 ;
return 0 ;
}
V_1 -> V_104 = 1 ;
}
else
V_1 -> V_104 = V_1 -> V_68 -> V_44
&& strlen ( V_1 -> V_68 -> V_44 ) == V_125
&& strncmp ( V_1 -> V_68 -> V_44 , ( char * ) V_131 , V_125 ) == 0 ;
break;
default:
break;
}
V_133 -= V_125 ;
}
if ( V_133 != 0 )
{
* V_123 = V_134 ;
return 0 ;
}
}
#ifndef F_19
else if ( type == V_57 )
{
if ( V_124 <= 0 || ( ( V_125 = V_71 [ 0 ] ) ) != ( V_124 - 1 ) )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_1 -> V_54 . V_55 != NULL )
{
* V_123 = V_134 ;
return 0 ;
}
if ( ( V_1 -> V_54 . V_55 = F_22 ( V_125 + 1 ) ) == NULL )
return - 1 ;
memcpy ( V_1 -> V_54 . V_55 , & V_71 [ 1 ] , V_125 ) ;
V_1 -> V_54 . V_55 [ V_125 ] = '\0' ;
if ( strlen ( V_1 -> V_54 . V_55 ) != V_125 )
{
* V_123 = V_134 ;
return 0 ;
}
}
#endif
#ifndef F_20
else if ( type == V_61 &&
V_1 -> V_5 != V_59 )
{
unsigned char * V_131 = V_71 ;
int V_138 = * ( V_131 ++ ) ;
if ( V_138 != V_124 - 1 )
{
* V_123 = V_139 ;
return 0 ;
}
if ( ! V_1 -> V_103 )
{
if( V_1 -> V_68 -> V_58 )
{
F_6 ( V_1 -> V_68 -> V_58 ) ;
V_1 -> V_68 -> V_58 = NULL ;
}
V_1 -> V_68 -> V_60 = 0 ;
if ( ( V_1 -> V_68 -> V_58 = F_22 ( V_138 ) ) == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
V_1 -> V_68 -> V_60 = V_138 ;
memcpy ( V_1 -> V_68 -> V_58 , V_131 , V_138 ) ;
}
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ecpointformatlist (length=%i) ", s->session->tlsext_ecpointformatlist_length);
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
else if ( type == V_64 &&
V_1 -> V_5 != V_59 )
{
unsigned char * V_131 = V_71 ;
int V_140 = ( * ( V_131 ++ ) << 8 ) ;
V_140 += ( * ( V_131 ++ ) ) ;
if ( V_140 != V_124 - 2 )
{
* V_123 = V_139 ;
return 0 ;
}
if ( ! V_1 -> V_103 )
{
if( V_1 -> V_68 -> V_62 )
{
* V_123 = V_139 ;
return 0 ;
}
V_1 -> V_68 -> V_63 = 0 ;
if ( ( V_1 -> V_68 -> V_62 = F_22 ( V_140 ) ) == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
V_1 -> V_68 -> V_63 = V_140 ;
memcpy ( V_1 -> V_68 -> V_62 , V_131 , V_140 ) ;
}
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ellipticcurvelist (length=%i) ", s->session->tlsext_ellipticcurvelist_length);
sdata = s->session->tlsext_ellipticcurvelist;
for (i = 0; i < s->session->tlsext_ellipticcurvelist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
#ifdef F_24
else if ( type == F_24 &&
V_1 -> V_5 != V_59 )
{
unsigned char * V_131 = V_71 ;
if ( V_124 < 2 )
{
* V_123 = V_134 ;
return 0 ;
}
F_37 ( V_131 , V_1 -> V_42 -> V_79 ) ;
if ( V_1 -> V_42 -> V_79 != V_124 - 2 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_1 -> V_42 -> V_77 != NULL )
F_6 ( V_1 -> V_42 -> V_77 ) ;
if ( V_1 -> V_42 -> V_79 == 0 )
V_1 -> V_42 -> V_77 = F_22 ( 1 ) ;
else
V_1 -> V_42 -> V_77 = F_38 ( V_131 , V_1 -> V_42 -> V_79 ) ;
if ( V_1 -> V_42 -> V_77 == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
}
#endif
else if ( type == V_74 )
{
if ( V_1 -> V_141 &&
! V_1 -> V_141 ( V_1 , V_71 , V_124 , V_1 -> V_142 ) )
{
* V_123 = V_137 ;
return 0 ;
}
}
else if ( type == V_53 )
{
if( ! F_39 ( V_1 , V_71 , V_124 , V_123 ) )
return 0 ;
V_126 = 1 ;
}
else if ( type == V_76 )
{
int V_133 ;
if ( V_127 || V_124 < 2 )
{
* V_123 = V_134 ;
return 0 ;
}
V_127 = 1 ;
F_37 ( V_71 , V_133 ) ;
V_124 -= 2 ;
if ( V_133 != V_124 || V_133 & 1 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( ! F_40 ( V_1 , V_71 , V_133 ) )
{
* V_123 = V_134 ;
return 0 ;
}
}
else if ( type == V_89 &&
V_1 -> V_5 != V_59 && V_1 -> V_96 -> V_143 )
{
if ( V_124 < 5 )
{
* V_123 = V_134 ;
return 0 ;
}
V_1 -> V_80 = * V_71 ++ ;
V_124 -- ;
if ( V_1 -> V_80 == V_81 )
{
const unsigned char * V_131 ;
int V_133 ;
F_37 ( V_71 , V_133 ) ;
V_124 -= 2 ;
if ( V_133 > V_124 )
{
* V_123 = V_134 ;
return 0 ;
}
while ( V_133 > 0 )
{
T_3 * V_86 ;
int V_144 ;
if ( V_133 < 4 )
{
* V_123 = V_134 ;
return 0 ;
}
F_37 ( V_71 , V_144 ) ;
V_133 -= 2 + V_144 ;
V_124 -= 2 + V_144 ;
if ( V_133 < 0 )
{
* V_123 = V_134 ;
return 0 ;
}
V_131 = V_71 ;
V_71 += V_144 ;
V_86 = F_41 ( NULL ,
& V_131 , V_144 ) ;
if ( ! V_86 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_71 != V_131 )
{
F_42 ( V_86 ) ;
* V_123 = V_134 ;
return 0 ;
}
if ( ! V_1 -> V_87
&& ! ( V_1 -> V_87 =
F_43 () ) )
{
F_42 ( V_86 ) ;
* V_123 = V_145 ;
return 0 ;
}
if ( ! F_44 (
V_1 -> V_87 , V_86 ) )
{
F_42 ( V_86 ) ;
* V_123 = V_145 ;
return 0 ;
}
}
if ( V_124 < 2 )
{
* V_123 = V_134 ;
return 0 ;
}
F_37 ( V_71 , V_133 ) ;
V_124 -= 2 ;
if ( V_133 != V_124 )
{
* V_123 = V_134 ;
return 0 ;
}
V_131 = V_71 ;
if ( V_133 > 0 )
{
if ( V_1 -> V_88 )
{
F_45 ( V_1 -> V_88 ,
V_146 ) ;
}
V_1 -> V_88 =
F_46 ( NULL ,
& V_131 , V_133 ) ;
if ( ! V_1 -> V_88
|| ( V_71 + V_133 != V_131 ) )
{
* V_123 = V_134 ;
return 0 ;
}
}
}
else
V_1 -> V_80 = - 1 ;
}
#ifndef F_29
else if ( type == V_91 )
{
switch( V_71 [ 0 ] )
{
case 0x01 :
V_1 -> V_92 |= V_95 ;
break;
case 0x02 :
V_1 -> V_92 |= V_95 ;
V_1 -> V_92 |= V_94 ;
break;
default: * V_123 = V_147 ;
return 0 ;
}
}
#endif
#ifndef F_30
else if ( type == V_100 &&
V_1 -> V_42 -> V_98 . V_99 == 0 )
{
V_1 -> V_42 -> V_102 = 1 ;
}
#endif
else if ( type == V_101 )
{
if( F_47 ( V_1 , V_71 , V_124 ,
V_123 ) )
return 0 ;
}
V_71 += V_124 ;
}
* V_34 = V_71 ;
V_128:
if ( ! V_126 && V_1 -> V_49 &&
! ( V_1 -> V_148 & V_149 ) )
{
* V_123 = V_150 ;
F_18 ( V_151 ,
V_152 ) ;
return 0 ;
}
return 1 ;
}
static char F_48 ( unsigned char * V_121 , unsigned V_125 )
{
unsigned int V_153 = 0 ;
while ( V_153 < V_125 )
{
if ( V_121 [ V_153 ] == 0 )
return 0 ;
V_153 += V_121 [ V_153 ] ;
V_153 ++ ;
}
return V_153 == V_125 ;
}
int F_49 ( T_1 * V_1 , unsigned char * * V_34 , unsigned char * V_121 , int V_122 , int * V_123 )
{
unsigned short V_72 ;
unsigned short type ;
unsigned short V_124 ;
unsigned char * V_71 = * V_34 ;
int V_154 = 0 ;
int V_126 = 0 ;
#ifndef F_30
V_1 -> V_42 -> V_102 = 0 ;
#endif
#ifndef F_29
V_1 -> V_92 &= ~ ( V_95 |
V_94 ) ;
#endif
if ( V_71 >= ( V_121 + V_122 - 2 ) )
goto V_128;
F_37 ( V_71 , V_72 ) ;
if ( V_71 + V_72 != V_121 + V_122 )
{
* V_123 = V_134 ;
return 0 ;
}
while( V_71 <= ( V_121 + V_122 - 4 ) )
{
F_37 ( V_71 , type ) ;
F_37 ( V_71 , V_124 ) ;
if ( V_71 + V_124 > ( V_121 + V_122 ) )
goto V_128;
if ( V_1 -> V_129 )
V_1 -> V_129 ( V_1 , 1 , type , V_71 , V_124 ,
V_1 -> V_130 ) ;
if ( type == V_47 )
{
if ( V_1 -> V_44 == NULL || V_124 > 0 )
{
* V_123 = V_136 ;
return 0 ;
}
V_154 = 1 ;
}
#ifndef F_20
else if ( type == V_61 &&
V_1 -> V_5 != V_59 )
{
unsigned char * V_131 = V_71 ;
int V_138 = * ( V_131 ++ ) ;
if ( V_138 != V_124 - 1 )
{
* V_123 = V_139 ;
return 0 ;
}
V_1 -> V_68 -> V_60 = 0 ;
if ( V_1 -> V_68 -> V_58 != NULL ) F_6 ( V_1 -> V_68 -> V_58 ) ;
if ( ( V_1 -> V_68 -> V_58 = F_22 ( V_138 ) ) == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
V_1 -> V_68 -> V_60 = V_138 ;
memcpy ( V_1 -> V_68 -> V_58 , V_131 , V_138 ) ;
#if 0
fprintf(stderr,"ssl_parse_serverhello_tlsext s->session->tlsext_ecpointformatlist ");
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
else if ( type == V_74 )
{
if ( V_1 -> V_141 &&
! V_1 -> V_141 ( V_1 , V_71 , V_124 , V_1 -> V_142 ) )
{
* V_123 = V_137 ;
return 0 ;
}
if ( ( F_21 ( V_1 ) & V_65 )
|| ( V_124 > 0 ) )
{
* V_123 = V_155 ;
return 0 ;
}
V_1 -> V_106 = 1 ;
}
#ifdef F_24
else if ( type == F_24 &&
V_1 -> V_5 != V_59 )
{
unsigned char * V_131 = V_71 ;
if ( V_124 < 2 )
{
* V_123 = V_134 ;
return 0 ;
}
F_37 ( V_131 , V_1 -> V_42 -> V_110 ) ;
if ( V_1 -> V_42 -> V_110 != V_124 - 2 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( V_1 -> V_42 -> V_108 != NULL )
F_6 ( V_1 -> V_42 -> V_108 ) ;
if ( V_1 -> V_42 -> V_110 == 0 )
V_1 -> V_42 -> V_108 = F_22 ( 1 ) ;
else
V_1 -> V_42 -> V_108 = F_38 ( V_131 , V_1 -> V_42 -> V_110 ) ;
if ( V_1 -> V_42 -> V_108 == NULL )
{
* V_123 = V_137 ;
return 0 ;
}
}
#endif
else if ( type == V_89 &&
V_1 -> V_5 != V_59 )
{
if ( ( V_1 -> V_80 == - 1 ) || ( V_124 > 0 ) )
{
* V_123 = V_155 ;
return 0 ;
}
V_1 -> V_107 = 1 ;
}
#ifndef F_30
else if ( type == V_100 &&
V_1 -> V_42 -> V_98 . V_99 == 0 )
{
unsigned char * V_156 ;
unsigned char V_157 ;
if ( ( V_1 -> V_96 -> V_97 == NULL ) )
{
* V_123 = V_155 ;
return 0 ;
}
if ( ! F_48 ( V_71 , V_124 ) )
{
* V_123 = V_139 ;
return 0 ;
}
if ( V_1 -> V_96 -> V_97 ( V_1 , & V_156 , & V_157 , V_71 , V_124 , V_1 -> V_96 -> V_158 ) != V_120 )
{
* V_123 = V_137 ;
return 0 ;
}
V_1 -> V_159 = F_22 ( V_157 ) ;
if ( ! V_1 -> V_159 )
{
* V_123 = V_137 ;
return 0 ;
}
memcpy ( V_1 -> V_159 , V_156 , V_157 ) ;
V_1 -> V_160 = V_157 ;
V_1 -> V_42 -> V_102 = 1 ;
}
#endif
else if ( type == V_53 )
{
if( ! F_50 ( V_1 , V_71 , V_124 , V_123 ) )
return 0 ;
V_126 = 1 ;
}
#ifndef F_29
else if ( type == V_91 )
{
switch( V_71 [ 0 ] )
{
case 0x01 :
V_1 -> V_92 |= V_95 ;
break;
case 0x02 :
V_1 -> V_92 |= V_95 ;
V_1 -> V_92 |= V_94 ;
break;
default: * V_123 = V_147 ;
return 0 ;
}
}
#endif
else if ( type == V_101 )
{
if( F_51 ( V_1 , V_71 , V_124 ,
V_123 ) )
return 0 ;
}
V_71 += V_124 ;
}
if ( V_71 != V_121 + V_122 )
{
* V_123 = V_134 ;
return 0 ;
}
if ( ! V_1 -> V_103 && V_154 == 1 )
{
if ( V_1 -> V_44 )
{
if ( V_1 -> V_68 -> V_44 == NULL )
{
V_1 -> V_68 -> V_44 = F_52 ( V_1 -> V_44 ) ;
if ( ! V_1 -> V_68 -> V_44 )
{
* V_123 = V_161 ;
return 0 ;
}
}
else
{
* V_123 = V_134 ;
return 0 ;
}
}
}
* V_34 = V_71 ;
V_128:
if ( ! V_126
&& ! ( V_1 -> V_148 & V_162 )
&& ! ( V_1 -> V_148 & V_149 ) )
{
* V_123 = V_150 ;
F_18 ( V_163 ,
V_152 ) ;
return 0 ;
}
return 1 ;
}
int F_53 ( T_1 * V_1 )
{
#ifndef F_20
int V_164 = 0 ;
int V_82 ;
unsigned char * V_165 ;
unsigned long V_166 , V_167 ;
F_54 ( V_168 ) * V_169 = F_55 ( V_1 ) ;
for ( V_82 = 0 ; V_82 < F_56 ( V_169 ) ; V_82 ++ )
{
V_168 * V_170 = F_57 ( V_169 , V_82 ) ;
V_166 = V_170 -> V_171 ;
V_167 = V_170 -> V_172 ;
if ( ( V_166 & ( V_173 | V_174 | V_175 ) || ( V_167 & V_176 ) ) )
{
V_164 = 1 ;
break;
}
}
V_164 = V_164 && ( V_1 -> V_5 >= V_177 ) ;
if ( V_164 )
{
if ( V_1 -> V_58 != NULL ) F_6 ( V_1 -> V_58 ) ;
if ( ( V_1 -> V_58 = F_22 ( 3 ) ) == NULL )
{
F_18 ( V_178 , V_179 ) ;
return - 1 ;
}
V_1 -> V_60 = 3 ;
V_1 -> V_58 [ 0 ] = V_180 ;
V_1 -> V_58 [ 1 ] = V_181 ;
V_1 -> V_58 [ 2 ] = V_182 ;
if ( V_1 -> V_62 != NULL ) F_6 ( V_1 -> V_62 ) ;
V_1 -> V_63 = sizeof( V_183 ) / sizeof( V_183 [ 0 ] ) * 2 ;
if ( ( V_1 -> V_62 = F_22 ( V_1 -> V_63 ) ) == NULL )
{
V_1 -> V_63 = 0 ;
F_18 ( V_178 , V_179 ) ;
return - 1 ;
}
for ( V_82 = 0 , V_165 = V_1 -> V_62 ; ( unsigned int ) V_82 <
sizeof( V_183 ) / sizeof( V_183 [ 0 ] ) ; V_82 ++ )
{
int V_86 = F_11 ( V_183 [ V_82 ] ) ;
F_16 ( V_86 , V_165 ) ;
}
}
#endif
#ifdef F_24
{
int V_118 = 1 ;
if ( V_1 -> V_96 -> V_184 != 0 )
{
V_118 = V_1 -> V_96 -> V_184 ( V_1 , NULL , 0 , V_1 -> V_96 -> V_185 ) ;
if ( ! V_118 )
return - 1 ;
}
if ( V_1 -> V_186 != NULL )
{
if ( V_1 -> V_42 -> V_77 != NULL )
F_6 ( V_1 -> V_42 -> V_77 ) ;
if ( V_1 -> V_187 == 0 )
V_1 -> V_42 -> V_77 = F_22 ( 1 ) ;
else
V_1 -> V_42 -> V_77 = F_38 ( V_1 -> V_186 , V_1 -> V_187 ) ;
if ( V_1 -> V_42 -> V_77 == NULL )
{
F_18 ( V_178 , V_179 ) ;
return - 1 ;
}
V_1 -> V_42 -> V_79 = V_1 -> V_187 ;
}
if ( V_118 == 2 )
V_1 -> V_42 -> V_110 = V_1 -> V_187 ;
}
#endif
return 1 ;
}
int F_58 ( T_1 * V_1 )
{
#ifndef F_20
unsigned long V_166 = V_1 -> V_42 -> V_98 . V_112 -> V_171 ;
unsigned long V_167 = V_1 -> V_42 -> V_98 . V_112 -> V_172 ;
int V_164 = ( V_166 & ( V_173 | V_174 | V_175 ) ) || ( V_167 & V_176 ) ;
V_164 = V_164 && ( V_1 -> V_68 -> V_58 != NULL ) ;
if ( V_164 )
{
if ( V_1 -> V_58 != NULL ) F_6 ( V_1 -> V_58 ) ;
if ( ( V_1 -> V_58 = F_22 ( 3 ) ) == NULL )
{
F_18 ( V_188 , V_179 ) ;
return - 1 ;
}
V_1 -> V_60 = 3 ;
V_1 -> V_58 [ 0 ] = V_180 ;
V_1 -> V_58 [ 1 ] = V_181 ;
V_1 -> V_58 [ 2 ] = V_182 ;
}
#endif
return 1 ;
}
int F_59 ( T_1 * V_1 )
{
int V_39 = V_189 ;
int V_123 = V_161 ;
#ifndef F_20
#endif
if ( V_1 -> V_96 != NULL && V_1 -> V_96 -> V_190 != 0 )
V_39 = V_1 -> V_96 -> V_190 ( V_1 , & V_123 , V_1 -> V_96 -> V_191 ) ;
else if ( V_1 -> V_192 != NULL && V_1 -> V_192 -> V_190 != 0 )
V_39 = V_1 -> V_192 -> V_190 ( V_1 , & V_123 , V_1 -> V_192 -> V_191 ) ;
if ( ( V_1 -> V_80 != - 1 ) && V_1 -> V_96 && V_1 -> V_96 -> V_143 )
{
int V_118 ;
V_118 = V_1 -> V_96 -> V_143 ( V_1 , V_1 -> V_96 -> V_193 ) ;
switch ( V_118 )
{
case V_189 :
V_1 -> V_107 = 0 ;
break;
case V_120 :
if ( V_1 -> V_194 )
V_1 -> V_107 = 1 ;
else
V_1 -> V_107 = 0 ;
break;
case V_195 :
V_39 = V_195 ;
V_123 = V_145 ;
goto V_196;
}
}
else
V_1 -> V_107 = 0 ;
#ifdef F_24
{
int V_118 = 1 ;
if ( V_1 -> V_96 -> V_184 != 0 )
{
V_118 = V_1 -> V_96 -> V_184 ( V_1 , NULL , 0 , V_1 -> V_96 -> V_185 ) ;
if ( ! V_118 )
{
V_39 = V_195 ;
V_123 = V_145 ;
goto V_196;
}
}
if ( V_1 -> V_42 -> V_108 != NULL )
F_6 ( V_1 -> V_42 -> V_108 ) ;
V_1 -> V_42 -> V_108 = NULL ;
if ( V_1 -> V_186 != NULL )
{
if ( V_1 -> V_42 -> V_77 != NULL &&
V_1 -> V_42 -> V_79 == V_1 -> V_187 )
{
if ( V_1 -> V_187 == 0 )
V_1 -> V_42 -> V_108 = F_22 ( 1 ) ;
else
V_1 -> V_42 -> V_108 = F_38 ( V_1 -> V_186 , V_1 -> V_187 ) ;
if ( V_1 -> V_42 -> V_108 == NULL )
{
V_39 = V_195 ;
V_123 = V_145 ;
goto V_196;
}
V_1 -> V_42 -> V_110 = V_1 -> V_187 ;
}
}
if ( V_118 == 2 && V_1 -> V_42 -> V_108 == NULL )
{
V_39 = V_195 ;
V_123 = V_150 ;
}
}
#endif
V_196:
switch ( V_39 )
{
case V_195 :
F_60 ( V_1 , V_197 , V_123 ) ;
return - 1 ;
case V_198 :
F_60 ( V_1 , V_199 , V_123 ) ;
return 1 ;
case V_189 :
V_1 -> V_104 = 0 ;
default:
return 1 ;
}
}
int F_61 ( T_1 * V_1 )
{
int V_39 = V_189 ;
int V_123 = V_161 ;
#ifndef F_20
unsigned long V_166 = V_1 -> V_42 -> V_98 . V_112 -> V_171 ;
unsigned long V_167 = V_1 -> V_42 -> V_98 . V_112 -> V_172 ;
if ( ( V_1 -> V_58 != NULL ) && ( V_1 -> V_60 > 0 ) &&
( V_1 -> V_68 -> V_58 != NULL ) && ( V_1 -> V_68 -> V_60 > 0 ) &&
( ( V_166 & ( V_173 | V_174 | V_175 ) ) || ( V_167 & V_176 ) ) )
{
T_2 V_82 ;
unsigned char * V_200 ;
int V_201 = 0 ;
V_200 = V_1 -> V_68 -> V_58 ;
for ( V_82 = 0 ; V_82 < V_1 -> V_68 -> V_60 ; V_82 ++ )
{
if ( * ( V_200 ++ ) == V_180 )
{
V_201 = 1 ;
break;
}
}
if ( ! V_201 )
{
F_18 ( V_202 , V_203 ) ;
return - 1 ;
}
}
V_39 = V_120 ;
#endif
if ( V_1 -> V_96 != NULL && V_1 -> V_96 -> V_190 != 0 )
V_39 = V_1 -> V_96 -> V_190 ( V_1 , & V_123 , V_1 -> V_96 -> V_191 ) ;
else if ( V_1 -> V_192 != NULL && V_1 -> V_192 -> V_190 != 0 )
V_39 = V_1 -> V_192 -> V_190 ( V_1 , & V_123 , V_1 -> V_192 -> V_191 ) ;
#ifdef F_24
if ( V_1 -> V_42 -> V_110 > 0 )
{
if ( V_1 -> V_42 -> V_108 == NULL )
{
V_39 = V_195 ;
V_123 = V_150 ;
}
if ( V_1 -> V_42 -> V_77 == NULL ||
V_1 -> V_42 -> V_79 != V_1 -> V_42 -> V_110 )
{
V_39 = V_195 ;
V_123 = V_147 ;
}
}
#endif
if ( ( V_1 -> V_80 != - 1 ) && ! ( V_1 -> V_107 )
&& V_1 -> V_96 && V_1 -> V_96 -> V_143 )
{
int V_118 ;
if ( V_1 -> V_194 )
{
F_6 ( V_1 -> V_194 ) ;
V_1 -> V_194 = NULL ;
}
V_1 -> V_204 = - 1 ;
V_118 = V_1 -> V_96 -> V_143 ( V_1 , V_1 -> V_96 -> V_193 ) ;
if ( V_118 == 0 )
{
V_123 = V_205 ;
V_39 = V_195 ;
}
if ( V_118 < 0 )
{
V_123 = V_145 ;
V_39 = V_195 ;
}
}
switch ( V_39 )
{
case V_195 :
F_60 ( V_1 , V_197 , V_123 ) ;
return - 1 ;
case V_198 :
F_60 ( V_1 , V_199 , V_123 ) ;
return 1 ;
case V_189 :
V_1 -> V_104 = 0 ;
default:
return 1 ;
}
}
int F_62 ( T_1 * V_1 , unsigned char * V_206 , int V_125 ,
const unsigned char * V_37 , T_4 * * V_39 )
{
const unsigned char * V_34 = V_206 + V_125 ;
unsigned short V_82 ;
* V_39 = NULL ;
V_1 -> V_106 = 0 ;
if ( F_21 ( V_1 ) & V_65 )
return 0 ;
if ( ( V_1 -> V_5 <= V_41 ) || ! V_37 )
return 0 ;
if ( V_34 >= V_37 )
return - 1 ;
if ( V_1 -> V_5 == V_59 || V_1 -> V_5 == V_207 )
{
V_82 = * ( V_34 ++ ) ;
V_34 += V_82 ;
if ( V_34 >= V_37 )
return - 1 ;
}
F_37 ( V_34 , V_82 ) ;
V_34 += V_82 ;
if ( V_34 >= V_37 )
return - 1 ;
V_82 = * ( V_34 ++ ) ;
V_34 += V_82 ;
if ( V_34 > V_37 )
return - 1 ;
if ( ( V_34 + 2 ) >= V_37 )
return 0 ;
F_37 ( V_34 , V_82 ) ;
while ( ( V_34 + 4 ) <= V_37 )
{
unsigned short type , V_124 ;
F_37 ( V_34 , type ) ;
F_37 ( V_34 , V_124 ) ;
if ( V_34 + V_124 > V_37 )
return 0 ;
if ( type == V_74 )
{
int V_118 ;
if ( V_124 == 0 )
{
V_1 -> V_106 = 1 ;
return 1 ;
}
if ( V_1 -> V_208 )
{
return 2 ;
}
V_118 = F_63 ( V_1 , V_34 , V_124 , V_206 , V_125 , V_39 ) ;
switch ( V_118 )
{
case 2 :
V_1 -> V_106 = 1 ;
return 2 ;
case 3 :
return V_118 ;
case 4 :
V_1 -> V_106 = 1 ;
return 3 ;
default:
return - 1 ;
}
}
V_34 += V_124 ;
}
return 0 ;
}
static int F_63 ( T_1 * V_1 , const unsigned char * V_209 , int V_210 ,
const unsigned char * V_211 , int V_212 ,
T_4 * * V_213 )
{
T_4 * V_214 ;
unsigned char * V_215 ;
const unsigned char * V_34 ;
int V_35 , V_216 , V_217 = 0 ;
unsigned char V_218 [ V_219 ] ;
T_5 V_220 ;
T_6 V_96 ;
T_7 * V_221 = V_1 -> V_192 ;
if ( V_210 < 48 )
return 2 ;
F_64 ( & V_220 ) ;
F_65 ( & V_96 ) ;
if ( V_221 -> V_222 )
{
unsigned char * V_223 = ( unsigned char * ) V_209 ;
int V_224 = V_221 -> V_222 ( V_1 , V_223 , V_223 + 16 ,
& V_96 , & V_220 , 0 ) ;
if ( V_224 < 0 )
return - 1 ;
if ( V_224 == 0 )
return 2 ;
if ( V_224 == 2 )
V_217 = 1 ;
}
else
{
if ( memcmp ( V_209 , V_221 -> V_225 , 16 ) )
return 2 ;
F_66 ( & V_220 , V_221 -> V_226 , 16 ,
F_67 () , NULL ) ;
F_68 ( & V_96 , F_69 () , NULL ,
V_221 -> V_227 , V_209 + 16 ) ;
}
V_216 = F_70 ( & V_220 ) ;
if ( V_216 < 0 )
{
F_71 ( & V_96 ) ;
return - 1 ;
}
V_210 -= V_216 ;
F_72 ( & V_220 , V_209 , V_210 ) ;
F_73 ( & V_220 , V_218 , NULL ) ;
F_74 ( & V_220 ) ;
if ( memcmp ( V_218 , V_209 + V_210 , V_216 ) )
return 2 ;
V_34 = V_209 + 16 + F_75 ( & V_96 ) ;
V_210 -= 16 + F_75 ( & V_96 ) ;
V_215 = F_22 ( V_210 ) ;
if ( ! V_215 )
{
F_71 ( & V_96 ) ;
return - 1 ;
}
F_76 ( & V_96 , V_215 , & V_35 , V_34 , V_210 ) ;
if ( F_77 ( & V_96 , V_215 + V_35 , & V_216 ) <= 0 )
return 2 ;
V_35 += V_216 ;
F_71 ( & V_96 ) ;
V_34 = V_215 ;
V_214 = F_78 ( NULL , & V_34 , V_35 ) ;
F_6 ( V_215 ) ;
if ( V_214 )
{
if ( V_212 )
memcpy ( V_214 -> V_206 , V_211 , V_212 ) ;
V_214 -> V_228 = V_212 ;
* V_213 = V_214 ;
if ( V_217 )
return 4 ;
else
return 3 ;
}
F_79 () ;
return 2 ;
}
static int F_80 ( int V_8 , T_8 * V_229 , T_2 V_230 )
{
T_2 V_82 ;
for ( V_82 = 0 ; V_82 < V_230 ; V_82 ++ )
{
if ( V_229 [ V_82 ] . V_8 == V_8 )
return V_229 [ V_82 ] . V_86 ;
}
return - 1 ;
}
int F_81 ( unsigned char * V_34 , const T_9 * V_231 , const T_10 * V_232 )
{
int V_233 , V_234 ;
if ( ! V_232 )
return 0 ;
V_234 = F_80 ( F_82 ( V_232 ) , V_235 ,
sizeof( V_235 ) / sizeof( T_8 ) ) ;
if ( V_234 == - 1 )
return 0 ;
V_233 = F_83 ( V_231 ) ;
if ( V_233 == - 1 )
return 0 ;
V_34 [ 0 ] = ( unsigned char ) V_234 ;
V_34 [ 1 ] = ( unsigned char ) V_233 ;
return 1 ;
}
int F_83 ( const T_9 * V_231 )
{
return F_80 ( V_231 -> type , V_236 ,
sizeof( V_236 ) / sizeof( T_8 ) ) ;
}
const T_10 * F_84 ( unsigned char V_237 )
{
switch( V_237 )
{
#ifndef F_85
case V_238 :
#ifdef F_13
if ( F_14 () )
return NULL ;
#endif
return F_86 () ;
#endif
#ifndef F_87
case V_239 :
return F_88 () ;
#endif
#ifndef F_89
case V_240 :
return F_90 () ;
case V_241 :
return F_91 () ;
#endif
#ifndef F_92
case V_242 :
return F_93 () ;
case V_243 :
return F_94 () ;
#endif
default:
return NULL ;
}
}
int F_40 ( T_1 * V_1 , const unsigned char * V_71 , int V_133 )
{
int V_82 , V_244 ;
const T_10 * V_232 ;
T_11 * V_170 = V_1 -> V_245 ;
if ( F_23 ( V_1 ) < V_75 )
return 1 ;
if ( ! V_170 )
return 0 ;
V_170 -> V_246 [ V_247 ] . V_248 = NULL ;
V_170 -> V_246 [ V_249 ] . V_248 = NULL ;
V_170 -> V_246 [ V_250 ] . V_248 = NULL ;
V_170 -> V_246 [ V_251 ] . V_248 = NULL ;
for ( V_82 = 0 ; V_82 < V_133 ; V_82 += 2 )
{
unsigned char V_237 = V_71 [ V_82 ] , V_252 = V_71 [ V_82 + 1 ] ;
switch( V_252 )
{
#ifndef F_95
case V_253 :
V_244 = V_249 ;
break;
#endif
#ifndef F_96
case V_254 :
V_244 = V_247 ;
break;
#endif
#ifndef F_97
case V_255 :
V_244 = V_251 ;
break;
#endif
default:
continue;
}
if ( V_170 -> V_246 [ V_244 ] . V_248 == NULL )
{
V_232 = F_84 ( V_237 ) ;
if ( V_232 )
{
V_170 -> V_246 [ V_244 ] . V_248 = V_232 ;
if ( V_244 == V_249 )
V_170 -> V_246 [ V_250 ] . V_248 = V_232 ;
}
}
}
#ifndef F_96
if ( ! V_170 -> V_246 [ V_247 ] . V_248 )
V_170 -> V_246 [ V_247 ] . V_248 = F_98 () ;
#endif
#ifndef F_95
if ( ! V_170 -> V_246 [ V_249 ] . V_248 )
{
V_170 -> V_246 [ V_249 ] . V_248 = F_88 () ;
V_170 -> V_246 [ V_250 ] . V_248 = F_88 () ;
}
#endif
#ifndef F_97
if ( ! V_170 -> V_246 [ V_251 ] . V_248 )
V_170 -> V_246 [ V_251 ] . V_248 = F_99 () ;
#endif
return 1 ;
}
int
F_100 ( T_1 * V_1 )
{
unsigned char * V_34 = & V_1 -> V_42 -> V_256 . V_71 [ 0 ] , * V_257 ;
unsigned short V_258 ;
unsigned int V_259 ;
unsigned int V_260 = 16 ;
V_258 = * V_34 ++ ;
F_37 ( V_34 , V_259 ) ;
V_257 = V_34 ;
if ( V_1 -> V_261 )
V_1 -> V_261 ( 0 , V_1 -> V_5 , V_262 ,
& V_1 -> V_42 -> V_256 . V_71 [ 0 ] , V_1 -> V_42 -> V_256 . V_72 ,
V_1 , V_1 -> V_263 ) ;
if ( V_258 == V_264 )
{
unsigned char * V_265 , * V_266 ;
int V_118 ;
V_265 = F_22 ( 1 + 2 + V_259 + V_260 ) ;
V_266 = V_265 ;
* V_266 ++ = V_267 ;
F_16 ( V_259 , V_266 ) ;
memcpy ( V_266 , V_257 , V_259 ) ;
V_266 += V_259 ;
F_101 ( V_266 , V_260 ) ;
V_118 = F_102 ( V_1 , V_262 , V_265 , 3 + V_259 + V_260 ) ;
if ( V_118 >= 0 && V_1 -> V_261 )
V_1 -> V_261 ( 1 , V_1 -> V_5 , V_262 ,
V_265 , 3 + V_259 + V_260 ,
V_1 , V_1 -> V_263 ) ;
F_6 ( V_265 ) ;
if ( V_118 < 0 )
return V_118 ;
}
else if ( V_258 == V_267 )
{
unsigned int V_268 ;
F_37 ( V_257 , V_268 ) ;
if ( V_259 == 18 && V_268 == V_1 -> V_269 )
{
V_1 -> V_269 ++ ;
V_1 -> V_270 = 0 ;
}
}
return 0 ;
}
int
F_103 ( T_1 * V_1 )
{
unsigned char * V_271 , * V_34 ;
int V_39 ;
unsigned int V_259 = 18 ;
unsigned int V_260 = 16 ;
if ( ! ( V_1 -> V_92 & V_95 ) ||
V_1 -> V_92 & V_94 )
{
F_18 ( V_272 , V_273 ) ;
return - 1 ;
}
if ( V_1 -> V_270 )
{
F_18 ( V_272 , V_274 ) ;
return - 1 ;
}
if ( F_104 ( V_1 ) || V_1 -> V_275 )
{
F_18 ( V_272 , V_276 ) ;
return - 1 ;
}
F_105 ( V_259 + V_260 <= 16381 ) ;
V_271 = F_22 ( 1 + 2 + V_259 + V_260 ) ;
V_34 = V_271 ;
* V_34 ++ = V_264 ;
F_16 ( V_259 , V_34 ) ;
F_16 ( V_1 -> V_269 , V_34 ) ;
F_101 ( V_34 , 16 ) ;
V_34 += 16 ;
F_101 ( V_34 , V_260 ) ;
V_39 = F_102 ( V_1 , V_262 , V_271 , 3 + V_259 + V_260 ) ;
if ( V_39 >= 0 )
{
if ( V_1 -> V_261 )
V_1 -> V_261 ( 1 , V_1 -> V_5 , V_262 ,
V_271 , 3 + V_259 + V_260 ,
V_1 , V_1 -> V_263 ) ;
V_1 -> V_270 = 1 ;
}
F_6 ( V_271 ) ;
return V_39 ;
}
