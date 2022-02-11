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
V_1 -> V_5 = V_6 ;
}
int F_10 ( int V_7 )
{
if ( ( V_7 < 1 ) || ( ( unsigned int ) V_7 >
sizeof( V_8 ) / sizeof( V_8 [ 0 ] ) ) )
return 0 ;
return V_8 [ V_7 - 1 ] ;
}
int F_11 ( int V_9 )
{
switch ( V_9 )
{
case V_10 :
return 1 ;
case V_11 :
return 2 ;
case V_12 :
return 3 ;
case V_13 :
return 4 ;
case V_14 :
return 5 ;
case V_15 :
return 6 ;
case V_16 :
return 7 ;
case V_17 :
return 8 ;
case V_18 :
return 9 ;
case V_19 :
return 10 ;
case V_20 :
return 11 ;
case V_21 :
return 12 ;
case V_22 :
return 13 ;
case V_23 :
return 14 ;
case V_24 :
return 15 ;
case V_25 :
return 16 ;
case V_26 :
return 17 ;
case V_27 :
return 18 ;
case V_28 :
return 19 ;
case V_29 :
return 20 ;
case V_30 :
return 21 ;
case V_31 :
return 22 ;
case V_32 :
return 23 ;
case V_33 :
return 24 ;
case V_34 :
return 25 ;
default:
return 0 ;
}
}
unsigned char * F_12 ( T_1 * V_1 , unsigned char * V_35 , unsigned char * V_36 )
{
int V_37 = 0 ;
unsigned char * V_38 = V_35 ;
if ( V_1 -> V_39 == V_40
&& ! V_1 -> V_41 -> V_42 )
return V_35 ;
V_38 += 2 ;
if ( V_38 >= V_36 ) return NULL ;
if ( V_1 -> V_43 != NULL )
{
unsigned long V_44 ;
long V_45 ;
if ( ( V_45 = V_36 - V_38 - 9 ) < 0
|| ( V_44 = strlen ( V_1 -> V_43 ) ) > ( unsigned long ) V_45 )
return NULL ;
F_13 ( V_46 , V_38 ) ;
F_13 ( V_44 + 5 , V_38 ) ;
F_13 ( V_44 + 3 , V_38 ) ;
* ( V_38 ++ ) = ( unsigned char ) V_47 ;
F_13 ( V_44 , V_38 ) ;
memcpy ( V_38 , V_1 -> V_43 , V_44 ) ;
V_38 += V_44 ;
}
if ( V_1 -> V_48 )
{
int V_49 ;
if( ! F_14 ( V_1 , 0 , & V_49 , 0 ) )
{
F_15 ( V_50 , V_51 ) ;
return NULL ;
}
if( ( V_36 - V_35 - 4 - V_49 ) < 0 ) return NULL ;
F_13 ( V_52 , V_38 ) ;
F_13 ( V_49 , V_38 ) ;
if( ! F_14 ( V_1 , V_38 , & V_49 , V_49 ) )
{
F_15 ( V_50 , V_51 ) ;
return NULL ;
}
V_38 += V_49 ;
}
#ifndef F_16
if ( V_1 -> V_53 != NULL &&
V_1 -> V_5 != V_54 )
{
long V_45 ;
if ( ( V_45 = V_36 - V_38 - 5 ) < 0 ) return NULL ;
if ( V_1 -> V_55 > ( unsigned long ) V_45 ) return NULL ;
if ( V_1 -> V_55 > 255 )
{
F_15 ( V_50 , V_51 ) ;
return NULL ;
}
F_13 ( V_56 , V_38 ) ;
F_13 ( V_1 -> V_55 + 1 , V_38 ) ;
* ( V_38 ++ ) = ( unsigned char ) V_1 -> V_55 ;
memcpy ( V_38 , V_1 -> V_53 , V_1 -> V_55 ) ;
V_38 += V_1 -> V_55 ;
}
if ( V_1 -> V_57 != NULL &&
V_1 -> V_5 != V_54 )
{
long V_45 ;
if ( ( V_45 = V_36 - V_38 - 6 ) < 0 ) return NULL ;
if ( V_1 -> V_58 > ( unsigned long ) V_45 ) return NULL ;
if ( V_1 -> V_58 > 65532 )
{
F_15 ( V_50 , V_51 ) ;
return NULL ;
}
F_13 ( V_59 , V_38 ) ;
F_13 ( V_1 -> V_58 + 2 , V_38 ) ;
F_13 ( V_1 -> V_58 , V_38 ) ;
memcpy ( V_38 , V_1 -> V_57 , V_1 -> V_58 ) ;
V_38 += V_1 -> V_58 ;
}
#endif
if ( ! ( F_17 ( V_1 ) & V_60 ) )
{
int V_61 ;
if ( ! V_1 -> V_48 && V_1 -> V_62 && V_1 -> V_62 -> V_63 )
V_61 = V_1 -> V_62 -> V_64 ;
else if ( V_1 -> V_62 && V_1 -> V_4 &&
V_1 -> V_4 -> V_65 )
{
V_61 = V_1 -> V_4 -> V_66 ;
V_1 -> V_62 -> V_63 = F_18 ( V_61 ) ;
if ( ! V_1 -> V_62 -> V_63 )
return NULL ;
memcpy ( V_1 -> V_62 -> V_63 ,
V_1 -> V_4 -> V_65 ,
V_61 ) ;
V_1 -> V_62 -> V_64 = V_61 ;
}
else
V_61 = 0 ;
if ( V_61 == 0 && V_1 -> V_4 &&
V_1 -> V_4 -> V_65 == NULL )
goto V_67;
if ( ( long ) ( V_36 - V_38 - 4 - V_61 ) < 0 ) return NULL ;
F_13 ( V_68 , V_38 ) ;
F_13 ( V_61 , V_38 ) ;
if ( V_61 )
{
memcpy ( V_38 , V_1 -> V_62 -> V_63 , V_61 ) ;
V_38 += V_61 ;
}
}
V_67:
#ifdef F_19
if ( V_1 -> V_41 -> V_69 != NULL &&
V_1 -> V_5 != V_54 )
{
T_2 V_70 = V_1 -> V_41 -> V_71 ;
if ( ( long ) ( V_36 - V_38 - 6 - V_70 < 0 ) )
return NULL ;
if ( V_70 > 0xFFFD )
return NULL ;
F_13 ( F_19 , V_38 ) ;
F_13 ( V_70 + 2 , V_38 ) ;
F_13 ( V_70 , V_38 ) ;
memcpy ( V_38 , V_1 -> V_41 -> V_69 , V_70 ) ;
V_38 += V_70 ;
}
#endif
if ( V_1 -> V_72 == V_73 &&
V_1 -> V_5 != V_54 )
{
int V_74 ;
long V_75 , V_76 , V_77 ;
T_3 * V_78 ;
V_76 = 0 ;
for ( V_74 = 0 ; V_74 < F_20 ( V_1 -> V_79 ) ; V_74 ++ )
{
V_78 = F_21 ( V_1 -> V_79 , V_74 ) ;
V_77 = F_22 ( V_78 , NULL ) ;
if ( V_77 <= 0 )
return NULL ;
V_76 += V_77 + 2 ;
}
if ( V_1 -> V_80 )
{
V_75 = F_23 ( V_1 -> V_80 , NULL ) ;
if ( V_75 < 0 )
return NULL ;
}
else
V_75 = 0 ;
if ( ( long ) ( V_36 - V_38 - 7 - V_75 - V_76 ) < 0 ) return NULL ;
F_13 ( V_81 , V_38 ) ;
if ( V_75 + V_76 > 0xFFF0 )
return NULL ;
F_13 ( V_75 + V_76 + 5 , V_38 ) ;
* ( V_38 ++ ) = V_73 ;
F_13 ( V_76 , V_38 ) ;
for ( V_74 = 0 ; V_74 < F_20 ( V_1 -> V_79 ) ; V_74 ++ )
{
unsigned char * V_82 = V_38 ;
V_78 = F_21 ( V_1 -> V_79 , V_74 ) ;
V_38 += 2 ;
V_77 = F_22 ( V_78 , & V_38 ) ;
F_13 ( V_77 , V_82 ) ;
}
F_13 ( V_75 , V_38 ) ;
if ( V_75 > 0 )
F_23 ( V_1 -> V_80 , & V_38 ) ;
}
if ( ( V_37 = V_38 - V_35 - 2 ) == 0 )
return V_35 ;
F_13 ( V_37 , V_35 ) ;
return V_38 ;
}
unsigned char * F_24 ( T_1 * V_1 , unsigned char * V_35 , unsigned char * V_36 )
{
int V_37 = 0 ;
unsigned char * V_38 = V_35 ;
if ( V_1 -> V_5 == V_40 && ! V_1 -> V_41 -> V_42 )
return V_35 ;
V_38 += 2 ;
if ( V_38 >= V_36 ) return NULL ;
if ( ! V_1 -> V_83 && V_1 -> V_84 == 1 && V_1 -> V_62 -> V_43 != NULL )
{
if ( ( long ) ( V_36 - V_38 - 4 ) < 0 ) return NULL ;
F_13 ( V_46 , V_38 ) ;
F_13 ( 0 , V_38 ) ;
}
if( V_1 -> V_41 -> V_42 )
{
int V_49 ;
if( ! F_25 ( V_1 , 0 , & V_49 , 0 ) )
{
F_15 ( V_85 , V_51 ) ;
return NULL ;
}
if( ( V_36 - V_35 - 4 - V_49 ) < 0 ) return NULL ;
F_13 ( V_52 , V_38 ) ;
F_13 ( V_49 , V_38 ) ;
if( ! F_25 ( V_1 , V_38 , & V_49 , V_49 ) )
{
F_15 ( V_85 , V_51 ) ;
return NULL ;
}
V_38 += V_49 ;
}
#ifndef F_16
if ( V_1 -> V_53 != NULL &&
V_1 -> V_5 != V_54 )
{
long V_45 ;
if ( ( V_45 = V_36 - V_38 - 5 ) < 0 ) return NULL ;
if ( V_1 -> V_55 > ( unsigned long ) V_45 ) return NULL ;
if ( V_1 -> V_55 > 255 )
{
F_15 ( V_85 , V_51 ) ;
return NULL ;
}
F_13 ( V_56 , V_38 ) ;
F_13 ( V_1 -> V_55 + 1 , V_38 ) ;
* ( V_38 ++ ) = ( unsigned char ) V_1 -> V_55 ;
memcpy ( V_38 , V_1 -> V_53 , V_1 -> V_55 ) ;
V_38 += V_1 -> V_55 ;
}
#endif
if ( V_1 -> V_86
&& ! ( F_17 ( V_1 ) & V_60 ) )
{
if ( ( long ) ( V_36 - V_38 - 4 ) < 0 ) return NULL ;
F_13 ( V_68 , V_38 ) ;
F_13 ( 0 , V_38 ) ;
}
if ( V_1 -> V_87 )
{
if ( ( long ) ( V_36 - V_38 - 4 ) < 0 ) return NULL ;
F_13 ( V_81 , V_38 ) ;
F_13 ( 0 , V_38 ) ;
}
#ifdef F_19
if ( V_1 -> V_41 -> V_88 != NULL &&
V_1 -> V_5 != V_54 )
{
T_2 V_89 = V_1 -> V_41 -> V_90 ;
if ( ( long ) ( V_36 - V_38 - 6 - V_89 ) < 0 )
return NULL ;
if ( V_89 > 0xFFFD )
return NULL ;
F_13 ( F_19 , V_38 ) ;
F_13 ( V_89 + 2 , V_38 ) ;
F_13 ( V_89 , V_38 ) ;
memcpy ( V_38 , V_1 -> V_41 -> V_88 , V_89 ) ;
V_38 += V_89 ;
}
#endif
if ( ( ( V_1 -> V_41 -> V_91 . V_92 -> V_78 & 0xFFFF ) == 0x80 || ( V_1 -> V_41 -> V_91 . V_92 -> V_78 & 0xFFFF ) == 0x81 )
&& ( F_17 ( V_1 ) & V_93 ) )
{ const unsigned char V_94 [ 36 ] = {
0xfd , 0xe8 ,
0x00 , 0x20 ,
0x30 , 0x1e , 0x30 , 0x08 , 0x06 , 0x06 , 0x2a , 0x85 ,
0x03 , 0x02 , 0x02 , 0x09 , 0x30 , 0x08 , 0x06 , 0x06 ,
0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x16 , 0x30 , 0x08 ,
0x06 , 0x06 , 0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x17 } ;
if ( V_36 - V_38 < 36 ) return NULL ;
memcpy ( V_38 , V_94 , 36 ) ;
V_38 += 36 ;
}
if ( ( V_37 = V_38 - V_35 - 2 ) == 0 )
return V_35 ;
F_13 ( V_37 , V_35 ) ;
return V_38 ;
}
int F_26 ( T_1 * V_1 , unsigned char * * V_35 , unsigned char * V_95 , int V_96 , int * V_97 )
{
unsigned short type ;
unsigned short V_98 ;
unsigned short V_99 ;
unsigned char * V_65 = * V_35 ;
int V_100 = 0 ;
V_1 -> V_84 = 0 ;
V_1 -> V_72 = - 1 ;
if ( V_65 >= ( V_95 + V_96 - 2 ) )
goto V_101;
F_27 ( V_65 , V_99 ) ;
if ( V_65 > ( V_95 + V_96 - V_99 ) )
goto V_101;
while ( V_65 <= ( V_95 + V_96 - 4 ) )
{
F_27 ( V_65 , type ) ;
F_27 ( V_65 , V_98 ) ;
if ( V_65 + V_98 > ( V_95 + V_96 ) )
goto V_101;
#if 0
fprintf(stderr,"Received extension type %d size %d\n",type,size);
#endif
if ( V_1 -> V_102 )
V_1 -> V_102 ( V_1 , 0 , type , V_65 , V_98 ,
V_1 -> V_103 ) ;
if ( type == V_46 )
{
unsigned char * V_104 ;
int V_105 ;
int V_106 ;
if ( V_98 < 2 )
{
* V_97 = V_107 ;
return 0 ;
}
F_27 ( V_65 , V_106 ) ;
V_98 -= 2 ;
if ( V_106 > V_98 )
{
* V_97 = V_107 ;
return 0 ;
}
V_104 = V_65 ;
while ( V_106 > 3 )
{
V_105 = * ( V_104 ++ ) ;
F_27 ( V_104 , V_99 ) ;
V_106 -= 3 ;
if ( V_99 > V_106 )
{
* V_97 = V_107 ;
return 0 ;
}
if ( V_1 -> V_84 == 0 )
switch ( V_105 )
{
case V_47 :
if ( V_1 -> V_62 -> V_43 == NULL )
{
if ( V_99 > V_108 ||
( ( V_1 -> V_62 -> V_43 = F_18 ( V_99 + 1 ) ) == NULL ) )
{
* V_97 = V_109 ;
return 0 ;
}
memcpy ( V_1 -> V_62 -> V_43 , V_104 , V_99 ) ;
V_1 -> V_62 -> V_43 [ V_99 ] = '\0' ;
if ( strlen ( V_1 -> V_62 -> V_43 ) != V_99 ) {
F_6 ( V_1 -> V_62 -> V_43 ) ;
V_1 -> V_62 -> V_43 = NULL ;
* V_97 = V_109 ;
return 0 ;
}
V_1 -> V_84 = 1 ;
}
else
V_1 -> V_84 = strlen ( V_1 -> V_62 -> V_43 ) == V_99
&& strncmp ( V_1 -> V_62 -> V_43 , ( char * ) V_104 , V_99 ) == 0 ;
break;
default:
break;
}
V_106 -= V_99 ;
}
if ( V_106 != 0 )
{
* V_97 = V_107 ;
return 0 ;
}
}
#ifndef F_16
else if ( type == V_56 &&
V_1 -> V_5 != V_54 )
{
unsigned char * V_104 = V_65 ;
int V_110 = * ( V_104 ++ ) ;
if ( V_110 != V_98 - 1 )
{
* V_97 = V_111 ;
return 0 ;
}
V_1 -> V_62 -> V_55 = 0 ;
if ( V_1 -> V_62 -> V_53 != NULL ) F_6 ( V_1 -> V_62 -> V_53 ) ;
if ( ( V_1 -> V_62 -> V_53 = F_18 ( V_110 ) ) == NULL )
{
* V_97 = V_112 ;
return 0 ;
}
V_1 -> V_62 -> V_55 = V_110 ;
memcpy ( V_1 -> V_62 -> V_53 , V_104 , V_110 ) ;
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ecpointformatlist (length=%i) ", s->session->tlsext_ecpointformatlist_length);
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
else if ( type == V_59 &&
V_1 -> V_5 != V_54 )
{
unsigned char * V_104 = V_65 ;
int V_113 = ( * ( V_104 ++ ) << 8 ) ;
V_113 += ( * ( V_104 ++ ) ) ;
if ( V_113 != V_98 - 2 )
{
* V_97 = V_111 ;
return 0 ;
}
V_1 -> V_62 -> V_58 = 0 ;
if ( V_1 -> V_62 -> V_57 != NULL ) F_6 ( V_1 -> V_62 -> V_57 ) ;
if ( ( V_1 -> V_62 -> V_57 = F_18 ( V_113 ) ) == NULL )
{
* V_97 = V_112 ;
return 0 ;
}
V_1 -> V_62 -> V_58 = V_113 ;
memcpy ( V_1 -> V_62 -> V_57 , V_104 , V_113 ) ;
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ellipticcurvelist (length=%i) ", s->session->tlsext_ellipticcurvelist_length);
sdata = s->session->tlsext_ellipticcurvelist;
for (i = 0; i < s->session->tlsext_ellipticcurvelist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
#ifdef F_19
else if ( type == F_19 &&
V_1 -> V_5 != V_54 )
{
unsigned char * V_104 = V_65 ;
if ( V_98 < 2 )
{
* V_97 = V_107 ;
return 0 ;
}
F_27 ( V_104 , V_1 -> V_41 -> V_71 ) ;
if ( V_1 -> V_41 -> V_71 != V_98 - 2 )
{
* V_97 = V_107 ;
return 0 ;
}
if ( V_1 -> V_41 -> V_69 != NULL )
F_6 ( V_1 -> V_41 -> V_69 ) ;
if ( V_1 -> V_41 -> V_71 == 0 )
V_1 -> V_41 -> V_69 = F_18 ( 1 ) ;
else
V_1 -> V_41 -> V_69 = F_28 ( V_104 , V_1 -> V_41 -> V_71 ) ;
if ( V_1 -> V_41 -> V_69 == NULL )
{
* V_97 = V_112 ;
return 0 ;
}
}
#endif
else if ( type == V_68 )
{
if ( V_1 -> V_114 &&
! V_1 -> V_114 ( V_1 , V_65 , V_98 , V_1 -> V_115 ) )
{
* V_97 = V_112 ;
return 0 ;
}
}
else if ( type == V_52 )
{
if( ! F_29 ( V_1 , V_65 , V_98 , V_97 ) )
return 0 ;
V_100 = 1 ;
}
else if ( type == V_81 &&
V_1 -> V_5 != V_54 && V_1 -> V_116 -> V_117 )
{
if ( V_98 < 5 )
{
* V_97 = V_107 ;
return 0 ;
}
V_1 -> V_72 = * V_65 ++ ;
V_98 -- ;
if ( V_1 -> V_72 == V_73 )
{
const unsigned char * V_104 ;
int V_106 ;
F_27 ( V_65 , V_106 ) ;
V_98 -= 2 ;
if ( V_106 > V_98 )
{
* V_97 = V_107 ;
return 0 ;
}
while ( V_106 > 0 )
{
T_3 * V_78 ;
int V_118 ;
if ( V_106 < 4 )
{
* V_97 = V_107 ;
return 0 ;
}
F_27 ( V_65 , V_118 ) ;
V_106 -= 2 + V_118 ;
if ( V_106 < 0 )
{
* V_97 = V_107 ;
return 0 ;
}
V_104 = V_65 ;
V_65 += V_118 ;
V_78 = F_30 ( NULL ,
& V_104 , V_118 ) ;
if ( ! V_78 )
{
* V_97 = V_107 ;
return 0 ;
}
if ( V_65 != V_104 )
{
F_31 ( V_78 ) ;
* V_97 = V_107 ;
return 0 ;
}
if ( ! V_1 -> V_79
&& ! ( V_1 -> V_79 =
F_32 () ) )
{
F_31 ( V_78 ) ;
* V_97 = V_119 ;
return 0 ;
}
if ( ! F_33 (
V_1 -> V_79 , V_78 ) )
{
F_31 ( V_78 ) ;
* V_97 = V_119 ;
return 0 ;
}
}
F_27 ( V_65 , V_106 ) ;
V_98 -= 2 ;
if ( V_106 > V_98 )
{
* V_97 = V_107 ;
return 0 ;
}
V_104 = V_65 ;
if ( V_106 > 0 )
{
V_1 -> V_80 =
F_34 ( NULL ,
& V_104 , V_106 ) ;
if ( ! V_1 -> V_80
|| ( V_65 + V_106 != V_104 ) )
{
* V_97 = V_107 ;
return 0 ;
}
}
}
else
V_1 -> V_72 = - 1 ;
}
V_65 += V_98 ;
}
* V_35 = V_65 ;
V_101:
if ( ! V_100 && V_1 -> V_48 &&
! ( V_1 -> V_120 & V_121 ) )
{
* V_97 = V_122 ;
F_15 ( V_123 ,
V_124 ) ;
return 0 ;
}
return 1 ;
}
int F_35 ( T_1 * V_1 , unsigned char * * V_35 , unsigned char * V_95 , int V_96 , int * V_97 )
{
unsigned short type ;
unsigned short V_98 ;
unsigned short V_99 ;
unsigned char * V_65 = * V_35 ;
int V_125 = 0 ;
int V_100 = 0 ;
if ( V_65 >= ( V_95 + V_96 - 2 ) )
goto V_101;
F_27 ( V_65 , V_99 ) ;
while( V_65 <= ( V_95 + V_96 - 4 ) )
{
F_27 ( V_65 , type ) ;
F_27 ( V_65 , V_98 ) ;
if ( V_65 + V_98 > ( V_95 + V_96 ) )
goto V_101;
if ( V_1 -> V_102 )
V_1 -> V_102 ( V_1 , 1 , type , V_65 , V_98 ,
V_1 -> V_103 ) ;
if ( type == V_46 )
{
if ( V_1 -> V_43 == NULL || V_98 > 0 )
{
* V_97 = V_109 ;
return 0 ;
}
V_125 = 1 ;
}
#ifndef F_16
else if ( type == V_56 &&
V_1 -> V_5 != V_54 )
{
unsigned char * V_104 = V_65 ;
int V_110 = * ( V_104 ++ ) ;
if ( V_110 != V_98 - 1 )
{
* V_97 = V_111 ;
return 0 ;
}
V_1 -> V_62 -> V_55 = 0 ;
if ( V_1 -> V_62 -> V_53 != NULL ) F_6 ( V_1 -> V_62 -> V_53 ) ;
if ( ( V_1 -> V_62 -> V_53 = F_18 ( V_110 ) ) == NULL )
{
* V_97 = V_112 ;
return 0 ;
}
V_1 -> V_62 -> V_55 = V_110 ;
memcpy ( V_1 -> V_62 -> V_53 , V_104 , V_110 ) ;
#if 0
fprintf(stderr,"ssl_parse_serverhello_tlsext s->session->tlsext_ecpointformatlist ");
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
else if ( type == V_68 )
{
if ( V_1 -> V_114 &&
! V_1 -> V_114 ( V_1 , V_65 , V_98 , V_1 -> V_115 ) )
{
* V_97 = V_112 ;
return 0 ;
}
if ( ( F_17 ( V_1 ) & V_60 )
|| ( V_98 > 0 ) )
{
* V_97 = V_126 ;
return 0 ;
}
V_1 -> V_86 = 1 ;
}
#ifdef F_19
else if ( type == F_19 &&
V_1 -> V_5 != V_54 )
{
unsigned char * V_104 = V_65 ;
if ( V_98 < 2 )
{
* V_97 = V_107 ;
return 0 ;
}
F_27 ( V_104 , V_1 -> V_41 -> V_90 ) ;
if ( V_1 -> V_41 -> V_90 != V_98 - 2 )
{
* V_97 = V_107 ;
return 0 ;
}
if ( V_1 -> V_41 -> V_88 != NULL )
F_6 ( V_1 -> V_41 -> V_88 ) ;
if ( V_1 -> V_41 -> V_90 == 0 )
V_1 -> V_41 -> V_88 = F_18 ( 1 ) ;
else
V_1 -> V_41 -> V_88 = F_28 ( V_104 , V_1 -> V_41 -> V_90 ) ;
if ( V_1 -> V_41 -> V_88 == NULL )
{
* V_97 = V_112 ;
return 0 ;
}
}
#endif
else if ( type == V_81 &&
V_1 -> V_5 != V_54 )
{
if ( ( V_1 -> V_72 == - 1 ) || ( V_98 > 0 ) )
{
* V_97 = V_126 ;
return 0 ;
}
V_1 -> V_87 = 1 ;
}
else if ( type == V_52 )
{
if( ! F_36 ( V_1 , V_65 , V_98 , V_97 ) )
return 0 ;
V_100 = 1 ;
}
V_65 += V_98 ;
}
if ( V_65 != V_95 + V_96 )
{
* V_97 = V_107 ;
return 0 ;
}
if ( ! V_1 -> V_83 && V_125 == 1 )
{
if ( V_1 -> V_43 )
{
if ( V_1 -> V_62 -> V_43 == NULL )
{
V_1 -> V_62 -> V_43 = F_37 ( V_1 -> V_43 ) ;
if ( ! V_1 -> V_62 -> V_43 )
{
* V_97 = V_127 ;
return 0 ;
}
}
else
{
* V_97 = V_107 ;
return 0 ;
}
}
}
* V_35 = V_65 ;
V_101:
if ( ! V_100
&& ! ( V_1 -> V_120 & V_128 )
&& ! ( V_1 -> V_120 & V_121 ) )
{
* V_97 = V_122 ;
F_15 ( V_129 ,
V_124 ) ;
return 0 ;
}
return 1 ;
}
int F_38 ( T_1 * V_1 )
{
#ifndef F_16
int V_130 = 0 ;
int V_74 ;
unsigned char * V_131 ;
unsigned long V_132 , V_133 ;
F_39 ( V_134 ) * V_135 = F_40 ( V_1 ) ;
for ( V_74 = 0 ; V_74 < F_41 ( V_135 ) ; V_74 ++ )
{
V_134 * V_136 = F_42 ( V_135 , V_74 ) ;
V_132 = V_136 -> V_137 ;
V_133 = V_136 -> V_138 ;
if ( ( V_132 & ( V_139 | V_140 | V_141 ) || ( V_133 & V_142 ) ) )
{
V_130 = 1 ;
break;
}
}
V_130 = V_130 && ( V_1 -> V_5 == V_6 ) ;
if ( V_130 )
{
if ( V_1 -> V_53 != NULL ) F_6 ( V_1 -> V_53 ) ;
if ( ( V_1 -> V_53 = F_18 ( 3 ) ) == NULL )
{
F_15 ( V_143 , V_144 ) ;
return - 1 ;
}
V_1 -> V_55 = 3 ;
V_1 -> V_53 [ 0 ] = V_145 ;
V_1 -> V_53 [ 1 ] = V_146 ;
V_1 -> V_53 [ 2 ] = V_147 ;
if ( V_1 -> V_57 != NULL ) F_6 ( V_1 -> V_57 ) ;
V_1 -> V_58 = sizeof( V_8 ) / sizeof( V_8 [ 0 ] ) * 2 ;
if ( ( V_1 -> V_57 = F_18 ( V_1 -> V_58 ) ) == NULL )
{
V_1 -> V_58 = 0 ;
F_15 ( V_143 , V_144 ) ;
return - 1 ;
}
for ( V_74 = 1 , V_131 = V_1 -> V_57 ; ( unsigned int ) V_74 <=
sizeof( V_8 ) / sizeof( V_8 [ 0 ] ) ; V_74 ++ )
F_13 ( V_74 , V_131 ) ;
}
#endif
#ifdef F_19
{
int V_148 = 1 ;
if ( V_1 -> V_116 -> V_149 != 0 )
{
V_148 = V_1 -> V_116 -> V_149 ( V_1 , NULL , 0 , V_1 -> V_116 -> V_150 ) ;
if ( ! V_148 )
return - 1 ;
}
if ( V_1 -> V_151 != NULL )
{
if ( V_1 -> V_41 -> V_69 != NULL )
F_6 ( V_1 -> V_41 -> V_69 ) ;
if ( V_1 -> V_152 == 0 )
V_1 -> V_41 -> V_69 = F_18 ( 1 ) ;
else
V_1 -> V_41 -> V_69 = F_28 ( V_1 -> V_151 , V_1 -> V_152 ) ;
if ( V_1 -> V_41 -> V_69 == NULL )
{
F_15 ( V_143 , V_144 ) ;
return - 1 ;
}
V_1 -> V_41 -> V_71 = V_1 -> V_152 ;
}
if ( V_148 == 2 )
V_1 -> V_41 -> V_90 = V_1 -> V_152 ;
}
#endif
return 1 ;
}
int F_43 ( T_1 * V_1 )
{
#ifndef F_16
unsigned long V_132 = V_1 -> V_41 -> V_91 . V_92 -> V_137 ;
unsigned long V_133 = V_1 -> V_41 -> V_91 . V_92 -> V_138 ;
int V_130 = ( V_132 & ( V_139 | V_140 | V_141 ) ) || ( V_133 & V_142 ) ;
V_130 = V_130 && ( V_1 -> V_62 -> V_53 != NULL ) ;
if ( V_130 )
{
if ( V_1 -> V_53 != NULL ) F_6 ( V_1 -> V_53 ) ;
if ( ( V_1 -> V_53 = F_18 ( 3 ) ) == NULL )
{
F_15 ( V_153 , V_144 ) ;
return - 1 ;
}
V_1 -> V_55 = 3 ;
V_1 -> V_53 [ 0 ] = V_145 ;
V_1 -> V_53 [ 1 ] = V_146 ;
V_1 -> V_53 [ 2 ] = V_147 ;
}
#endif
return 1 ;
}
int F_44 ( T_1 * V_1 )
{
int V_38 = V_154 ;
int V_97 = V_127 ;
#ifndef F_16
#endif
if ( V_1 -> V_116 != NULL && V_1 -> V_116 -> V_155 != 0 )
V_38 = V_1 -> V_116 -> V_155 ( V_1 , & V_97 , V_1 -> V_116 -> V_156 ) ;
else if ( V_1 -> V_157 != NULL && V_1 -> V_157 -> V_155 != 0 )
V_38 = V_1 -> V_157 -> V_155 ( V_1 , & V_97 , V_1 -> V_157 -> V_156 ) ;
if ( ( V_1 -> V_72 != - 1 ) && V_1 -> V_116 && V_1 -> V_116 -> V_117 )
{
int V_148 ;
V_148 = V_1 -> V_116 -> V_117 ( V_1 , V_1 -> V_116 -> V_158 ) ;
switch ( V_148 )
{
case V_154 :
V_1 -> V_87 = 0 ;
break;
case V_159 :
if ( V_1 -> V_160 )
V_1 -> V_87 = 1 ;
else
V_1 -> V_87 = 0 ;
break;
case V_161 :
V_38 = V_161 ;
V_97 = V_119 ;
goto V_162;
}
}
else
V_1 -> V_87 = 0 ;
#ifdef F_19
{
int V_148 = 1 ;
if ( V_1 -> V_116 -> V_149 != 0 )
{
V_148 = V_1 -> V_116 -> V_149 ( V_1 , NULL , 0 , V_1 -> V_116 -> V_150 ) ;
if ( ! V_148 )
{
V_38 = V_161 ;
V_97 = V_119 ;
goto V_162;
}
}
if ( V_1 -> V_41 -> V_88 != NULL )
F_6 ( V_1 -> V_41 -> V_88 ) ;
V_1 -> V_41 -> V_88 = NULL ;
if ( V_1 -> V_151 != NULL )
{
if ( V_1 -> V_41 -> V_69 != NULL &&
V_1 -> V_41 -> V_71 == V_1 -> V_152 )
{
if ( V_1 -> V_152 == 0 )
V_1 -> V_41 -> V_88 = F_18 ( 1 ) ;
else
V_1 -> V_41 -> V_88 = F_28 ( V_1 -> V_151 , V_1 -> V_152 ) ;
if ( V_1 -> V_41 -> V_88 == NULL )
{
V_38 = V_161 ;
V_97 = V_119 ;
goto V_162;
}
V_1 -> V_41 -> V_90 = V_1 -> V_152 ;
}
}
if ( V_148 == 2 && V_1 -> V_41 -> V_88 == NULL )
{
V_38 = V_161 ;
V_97 = V_122 ;
}
}
#endif
V_162:
switch ( V_38 )
{
case V_161 :
F_45 ( V_1 , V_163 , V_97 ) ;
return - 1 ;
case V_164 :
F_45 ( V_1 , V_165 , V_97 ) ;
return 1 ;
case V_154 :
V_1 -> V_84 = 0 ;
default:
return 1 ;
}
}
int F_46 ( T_1 * V_1 )
{
int V_38 = V_154 ;
int V_97 = V_127 ;
#ifndef F_16
unsigned long V_132 = V_1 -> V_41 -> V_91 . V_92 -> V_137 ;
unsigned long V_133 = V_1 -> V_41 -> V_91 . V_92 -> V_138 ;
if ( ( V_1 -> V_53 != NULL ) && ( V_1 -> V_55 > 0 ) &&
( ( V_132 & ( V_139 | V_140 | V_141 ) ) || ( V_133 & V_142 ) ) )
{
T_2 V_74 ;
unsigned char * V_166 ;
int V_167 = 0 ;
if ( ( V_1 -> V_62 -> V_53 == NULL ) || ( V_1 -> V_62 -> V_55 == 0 ) )
{
F_15 ( V_168 , V_169 ) ;
return - 1 ;
}
V_166 = V_1 -> V_62 -> V_53 ;
for ( V_74 = 0 ; V_74 < V_1 -> V_62 -> V_55 ; V_74 ++ )
{
if ( * ( V_166 ++ ) == V_145 )
{
V_167 = 1 ;
break;
}
}
if ( ! V_167 )
{
F_15 ( V_168 , V_169 ) ;
return - 1 ;
}
}
V_38 = V_159 ;
#endif
if ( V_1 -> V_116 != NULL && V_1 -> V_116 -> V_155 != 0 )
V_38 = V_1 -> V_116 -> V_155 ( V_1 , & V_97 , V_1 -> V_116 -> V_156 ) ;
else if ( V_1 -> V_157 != NULL && V_1 -> V_157 -> V_155 != 0 )
V_38 = V_1 -> V_157 -> V_155 ( V_1 , & V_97 , V_1 -> V_157 -> V_156 ) ;
#ifdef F_19
if ( V_1 -> V_41 -> V_90 > 0 )
{
if ( V_1 -> V_41 -> V_88 == NULL )
{
V_38 = V_161 ;
V_97 = V_122 ;
}
if ( V_1 -> V_41 -> V_69 == NULL ||
V_1 -> V_41 -> V_71 != V_1 -> V_41 -> V_90 )
{
V_38 = V_161 ;
V_97 = V_170 ;
}
}
#endif
if ( ( V_1 -> V_72 != - 1 ) && ! ( V_1 -> V_87 )
&& V_1 -> V_116 && V_1 -> V_116 -> V_117 )
{
int V_148 ;
if ( V_1 -> V_160 )
{
F_6 ( V_1 -> V_160 ) ;
V_1 -> V_160 = NULL ;
}
V_1 -> V_171 = - 1 ;
V_148 = V_1 -> V_116 -> V_117 ( V_1 , V_1 -> V_116 -> V_158 ) ;
if ( V_148 == 0 )
{
V_97 = V_172 ;
V_38 = V_161 ;
}
if ( V_148 < 0 )
{
V_97 = V_119 ;
V_38 = V_161 ;
}
}
switch ( V_38 )
{
case V_161 :
F_45 ( V_1 , V_163 , V_97 ) ;
return - 1 ;
case V_164 :
F_45 ( V_1 , V_165 , V_97 ) ;
return 1 ;
case V_154 :
V_1 -> V_84 = 0 ;
default:
return 1 ;
}
}
int F_47 ( T_1 * V_1 , unsigned char * V_173 , int V_99 ,
const unsigned char * V_36 , T_4 * * V_38 )
{
const unsigned char * V_35 = V_173 + V_99 ;
unsigned short V_74 ;
if ( F_17 ( V_1 ) & V_60 )
return 1 ;
if ( ( V_1 -> V_5 <= V_40 ) || ! V_36 )
return 1 ;
if ( V_35 >= V_36 )
return - 1 ;
if ( V_1 -> V_5 == V_54 || V_1 -> V_5 == V_174 )
{
V_74 = * ( V_35 ++ ) ;
V_35 += V_74 ;
if ( V_35 >= V_36 )
return - 1 ;
}
F_27 ( V_35 , V_74 ) ;
V_35 += V_74 ;
if ( V_35 >= V_36 )
return - 1 ;
V_74 = * ( V_35 ++ ) ;
V_35 += V_74 ;
if ( V_35 > V_36 )
return - 1 ;
if ( ( V_35 + 2 ) >= V_36 )
return 1 ;
F_27 ( V_35 , V_74 ) ;
while ( ( V_35 + 4 ) <= V_36 )
{
unsigned short type , V_98 ;
F_27 ( V_35 , type ) ;
F_27 ( V_35 , V_98 ) ;
if ( V_35 + V_98 > V_36 )
return 1 ;
if ( type == V_68 )
{
if ( F_17 ( V_1 ) & V_60 )
return 1 ;
if ( V_98 == 0 )
{
V_1 -> V_86 = 1 ;
return 0 ;
}
if ( V_1 -> V_175 )
{
return 0 ;
}
return F_48 ( V_1 , V_35 , V_98 , V_173 , V_99 ,
V_38 ) ;
}
V_35 += V_98 ;
}
return 1 ;
}
static int F_48 ( T_1 * V_1 , const unsigned char * V_176 , int V_177 ,
const unsigned char * V_178 , int V_179 ,
T_4 * * V_180 )
{
T_4 * V_181 ;
unsigned char * V_182 ;
const unsigned char * V_35 ;
int V_183 , V_184 , V_185 = 0 ;
unsigned char V_186 [ V_187 ] ;
T_5 V_188 ;
T_6 V_116 ;
T_7 * V_189 = V_1 -> V_157 ;
if ( V_177 < 48 )
goto V_190;
F_49 ( & V_188 ) ;
F_50 ( & V_116 ) ;
if ( V_189 -> V_191 )
{
unsigned char * V_192 = ( unsigned char * ) V_176 ;
int V_193 = V_189 -> V_191 ( V_1 , V_192 , V_192 + 16 ,
& V_116 , & V_188 , 0 ) ;
if ( V_193 < 0 )
return - 1 ;
if ( V_193 == 0 )
goto V_190;
if ( V_193 == 2 )
V_185 = 1 ;
}
else
{
if ( memcmp ( V_176 , V_189 -> V_194 , 16 ) )
goto V_190;
F_51 ( & V_188 , V_189 -> V_195 , 16 ,
F_52 () , NULL ) ;
F_53 ( & V_116 , F_54 () , NULL ,
V_189 -> V_196 , V_176 + 16 ) ;
}
V_184 = F_55 ( & V_188 ) ;
if ( V_184 < 0 )
{
F_56 ( & V_116 ) ;
return - 1 ;
}
V_177 -= V_184 ;
F_57 ( & V_188 , V_176 , V_177 ) ;
F_58 ( & V_188 , V_186 , NULL ) ;
F_59 ( & V_188 ) ;
if ( memcmp ( V_186 , V_176 + V_177 , V_184 ) )
goto V_190;
V_35 = V_176 + 16 + F_60 ( & V_116 ) ;
V_177 -= 16 + F_60 ( & V_116 ) ;
V_182 = F_18 ( V_177 ) ;
if ( ! V_182 )
{
F_56 ( & V_116 ) ;
return - 1 ;
}
F_61 ( & V_116 , V_182 , & V_183 , V_35 , V_177 ) ;
if ( F_62 ( & V_116 , V_182 + V_183 , & V_184 ) <= 0 )
goto V_190;
V_183 += V_184 ;
F_56 ( & V_116 ) ;
V_35 = V_182 ;
V_181 = F_63 ( NULL , & V_35 , V_183 ) ;
F_6 ( V_182 ) ;
if ( V_181 )
{
if ( V_179 )
memcpy ( V_181 -> V_173 , V_178 , V_179 ) ;
V_181 -> V_197 = V_179 ;
* V_180 = V_181 ;
V_1 -> V_86 = V_185 ;
return 1 ;
}
V_190:
V_1 -> V_86 = 1 ;
return 0 ;
}
