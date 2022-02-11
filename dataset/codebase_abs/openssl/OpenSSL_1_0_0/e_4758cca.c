static const char * F_1 ( void )
{
if( V_1 )
return V_1 ;
return V_2 ;
}
static void F_2 ( void )
{
if( V_1 )
F_3 ( ( void * ) V_1 ) ;
V_1 = NULL ;
}
static long F_4 ( const char * V_3 )
{
F_2 () ;
return ( ( ( V_1 = F_5 ( V_3 ) ) != NULL ) ? 1 : 0 ) ;
}
static int F_6 ( T_1 * V_4 )
{
if( ! F_7 ( V_4 , V_5 ) ||
! F_8 ( V_4 , V_6 ) ||
#ifndef F_9
! F_10 ( V_4 , & V_7 ) ||
#endif
! F_11 ( V_4 , & V_8 ) ||
! F_12 ( V_4 , V_9 ) ||
! F_13 ( V_4 , V_10 ) ||
! F_14 ( V_4 , V_11 ) ||
! F_15 ( V_4 , V_12 ) ||
#ifndef F_9
! F_16 ( V_4 , V_13 ) ||
! F_17 ( V_4 , V_14 ) ||
#endif
! F_18 ( V_4 , V_15 ) )
return 0 ;
F_19 () ;
return 1 ;
}
static T_1 * F_20 ( void )
{
T_1 * V_16 = F_21 () ;
if( ! V_16 )
return NULL ;
if( ! F_6 ( V_16 ) )
{
F_22 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
void F_23 ( void )
{
T_1 * V_17 = F_20 () ;
if ( ! V_17 ) return;
F_24 ( V_17 ) ;
F_22 ( V_17 ) ;
F_25 () ;
}
static int V_9 ( T_1 * V_4 )
{
F_26 () ;
F_2 () ;
return 1 ;
}
static int V_10 ( T_1 * V_4 )
{
if( V_18 )
{
F_27 ( V_19 , V_20 ) ;
goto V_21;
}
V_18 = F_28 ( NULL , F_1 () , NULL , 0 ) ;
if( ! V_18 )
{
F_27 ( V_19 , V_22 ) ;
goto V_21;
}
#ifndef F_9
if( ! ( V_23 = ( V_24 )
F_29 ( V_18 , V_25 ) ) ||
! ( V_26 = ( V_27 )
F_29 ( V_18 , V_28 ) ) ||
! ( V_29 = ( V_30 )
F_29 ( V_18 , V_31 ) ) ||
! ( V_32 = ( V_33 )
F_29 ( V_18 , V_34 ) ) ||
! ( V_35 = ( V_36 )
F_29 ( V_18 , V_37 ) ) ||
! ( V_38 = ( V_39 )
F_29 ( V_18 , V_40 ) ) ||
! ( V_41 = ( V_42 )
F_29 ( V_18 , V_43 ) ) )
{
F_27 ( V_19 , V_22 ) ;
goto V_21;
}
#else
if( ! ( V_26 = ( V_27 )
F_29 ( V_18 , V_28 ) ) )
{
F_27 ( V_19 , V_22 ) ;
goto V_21;
}
#endif
#ifndef F_9
V_44 = F_30 ( 0 , L_1 ,
NULL , NULL , V_45 ) ;
#endif
return 1 ;
V_21:
if( V_18 )
F_31 ( V_18 ) ;
V_18 = NULL ;
#ifndef F_9
V_23 = ( V_24 ) 0 ;
V_29 = ( V_30 ) 0 ;
V_32 = ( V_33 ) 0 ;
V_35 = ( V_36 ) 0 ;
V_38 = ( V_39 ) 0 ;
V_41 = ( V_42 ) 0 ;
#endif
V_26 = ( V_27 ) 0 ;
return 0 ;
}
static int V_11 ( T_1 * V_4 )
{
F_2 () ;
if( ! V_18 )
{
F_27 ( V_46 ,
V_47 ) ;
return 0 ;
}
if( ! F_31 ( V_18 ) )
{
F_27 ( V_46 ,
V_48 ) ;
return 0 ;
}
V_18 = NULL ;
#ifndef F_9
V_23 = ( V_24 ) 0 ;
V_26 = ( V_27 ) 0 ;
V_29 = ( V_30 ) 0 ;
V_32 = ( V_33 ) 0 ;
V_35 = ( V_36 ) 0 ;
V_38 = ( V_39 ) 0 ;
V_41 = ( V_42 ) 0 ;
#endif
V_26 = ( V_27 ) 0 ;
return 1 ;
}
static int V_12 ( T_1 * V_4 , int V_49 , long V_50 , void * V_51 , void (* F_32)( void ) )
{
int V_52 = ( ( V_18 == NULL ) ? 0 : 1 ) ;
switch( V_49 )
{
case V_53 :
if( V_51 == NULL )
{
F_27 ( V_54 ,
V_55 ) ;
return 0 ;
}
if( V_52 )
{
F_27 ( V_54 ,
V_20 ) ;
return 0 ;
}
return F_4 ( ( const char * ) V_51 ) ;
default:
break;
}
F_27 ( V_54 ,
V_56 ) ;
return 0 ;
}
static T_2 * V_13 ( T_1 * V_4 , const char * V_57 ,
T_3 * V_58 , void * V_59 )
{
T_4 * V_60 = NULL ;
T_2 * V_61 = NULL ;
unsigned char * V_62 = NULL ;
unsigned char V_63 [ V_64 ] ;
long V_65 = V_64 ;
long V_66 = V_64 ;
long V_67 ;
long V_68 ;
long V_69 = 0 ;
long V_70 = 0 ;
unsigned char V_71 [ 8 ] ;
unsigned char V_72 [ 8 ] ;
unsigned char V_73 [ 64 ] ;
unsigned long V_74 = strlen ( V_57 ) ;
unsigned char V_75 [ 256 ] ;
long V_76 = sizeof( V_75 ) ;
long V_77 = 0 ;
unsigned char V_78 [ 256 ] ;
long V_79 = sizeof( V_78 ) ;
if ( V_74 > sizeof( V_73 ) )
{
F_27 ( V_80 ,
V_81 ) ;
return NULL ;
}
memset ( V_73 , ' ' , sizeof( V_73 ) ) ;
memcpy ( V_73 , V_57 , V_74 ) ;
V_62 = F_33 ( V_64 + sizeof( long ) ) ;
if ( ! V_62 )
{
F_27 ( V_80 ,
V_82 ) ;
goto V_21;
}
V_23 ( & V_67 , & V_68 , & V_69 ,
V_71 , & V_70 , V_72 , V_73 ,
& V_66 , V_62 + sizeof( long ) ) ;
if ( V_67 )
{
F_27 ( V_80 ,
V_83 ) ;
goto V_21;
}
V_35 ( & V_67 , & V_68 , & V_69 ,
V_71 , & V_70 , V_72 , & V_66 ,
V_62 + sizeof( long ) , & V_65 , V_63 ) ;
if ( V_67 )
{
F_27 ( V_80 ,
V_83 ) ;
goto V_21;
}
if ( ! F_34 ( V_63 , & V_79 ,
V_78 , & V_77 , & V_76 ,
V_75 ) )
{
F_27 ( V_80 ,
V_83 ) ;
goto V_21;
}
( * ( long * ) V_62 ) = V_66 ;
V_60 = F_35 ( V_4 ) ;
F_36 ( V_60 , V_44 , ( char * ) V_62 ) ;
V_60 -> V_4 = F_37 ( V_78 , V_79 , NULL ) ;
V_60 -> V_84 = F_37 ( V_75 , V_76 , NULL ) ;
V_60 -> V_85 |= V_86 ;
V_61 = F_38 () ;
F_39 ( V_61 , V_60 ) ;
return V_61 ;
V_21:
if ( V_62 )
F_3 ( V_62 ) ;
return NULL ;
}
static T_2 * V_14 ( T_1 * V_4 , const char * V_57 ,
T_3 * V_58 , void * V_59 )
{
T_4 * V_60 = NULL ;
T_2 * V_61 = NULL ;
unsigned char * V_62 = NULL ;
long V_66 = V_64 ;
long V_67 ;
long V_68 ;
long V_69 = 0 ;
long V_70 = 0 ;
unsigned char V_71 [ 8 ] ;
unsigned char V_72 [ 8 ] ;
unsigned char V_73 [ 64 ] ;
unsigned long V_74 = strlen ( V_57 ) ;
unsigned char V_75 [ 512 ] ;
long V_76 = sizeof( V_75 ) ;
long V_77 = 0 ;
unsigned char V_78 [ 512 ] ;
long V_79 = sizeof( V_78 ) ;
if ( V_74 > sizeof( V_73 ) )
{
F_27 ( V_87 ,
V_81 ) ;
return NULL ;
}
memset ( V_73 , ' ' , sizeof( V_73 ) ) ;
memcpy ( V_73 , V_57 , V_74 ) ;
V_62 = F_33 ( V_64 + sizeof( long ) ) ;
if ( ! V_62 )
{
F_27 ( V_87 ,
V_82 ) ;
goto V_21;
}
V_23 ( & V_67 , & V_68 , & V_69 , V_71 ,
& V_70 , V_72 , V_73 , & V_66 ,
V_62 + sizeof( long ) ) ;
if ( V_67 )
{
F_27 ( V_87 ,
V_82 ) ;
goto V_21;
}
if ( ! F_34 ( V_62 + sizeof( long ) , & V_79 ,
V_78 , & V_77 , & V_76 , V_75 ) )
{
F_27 ( V_87 ,
V_88 ) ;
goto V_21;
}
( * ( long * ) V_62 ) = V_66 ;
V_60 = F_35 ( V_4 ) ;
F_36 ( V_60 , V_44 , ( char * ) V_62 ) ;
V_60 -> V_4 = F_37 ( V_78 , V_79 , NULL ) ;
V_60 -> V_84 = F_37 ( V_75 , V_76 , NULL ) ;
V_60 -> V_85 |= V_86 ;
V_61 = F_38 () ;
F_39 ( V_61 , V_60 ) ;
return V_61 ;
V_21:
if ( V_62 )
F_3 ( V_62 ) ;
return NULL ;
}
static int F_40 ( int V_89 , const unsigned char * V_90 ,
unsigned char * V_91 , T_4 * V_92 , int V_93 )
{
long V_67 ;
long V_68 ;
long V_94 = V_89 ;
long V_69 = 0 ;
unsigned char V_71 [ 8 ] ;
long V_70 = 1 ;
unsigned char V_72 [ 8 ] = L_2 ;
long V_95 = 0 ;
unsigned char V_96 [ 8 ] ;
long V_97 = F_41 ( V_92 ) ;
long V_66 ;
unsigned char * V_62 = ( unsigned char * ) F_42 ( V_92 , V_44 ) ;
V_66 = * ( long * ) V_62 ;
V_62 += sizeof( long ) ;
V_38 ( & V_67 , & V_68 , & V_69 , V_71 ,
& V_70 , V_72 , & V_94 , ( unsigned char * ) V_90 ,
& V_95 , V_96 , & V_66 ,
V_62 , & V_97 , V_91 ) ;
if ( V_67 || V_68 )
return - ( V_67 << 16 | V_68 ) ;
return V_97 ;
}
static int F_43 ( int V_89 , const unsigned char * V_90 ,
unsigned char * V_91 , T_4 * V_92 , int V_93 )
{
long V_67 ;
long V_68 ;
long V_94 = V_89 ;
long V_69 = 0 ;
unsigned char V_71 [ 8 ] ;
long V_70 = 1 ;
unsigned char V_72 [ 8 ] = L_2 ;
long V_95 = 0 ;
unsigned char V_96 [ 8 ] ;
long V_97 = F_41 ( V_92 ) ;
long V_66 ;
unsigned char * V_62 = ( unsigned char * ) F_42 ( V_92 , V_44 ) ;
V_66 = * ( long * ) V_62 ;
V_62 += sizeof( long ) ;
V_41 ( & V_67 , & V_68 , & V_69 , V_71 ,
& V_70 , V_72 , & V_94 , ( unsigned char * ) V_90 ,
& V_95 , V_96 , & V_66 ,
V_62 , & V_97 , V_91 ) ;
return ( V_67 | V_68 ) ? 0 : 1 ;
}
static int F_44 ( int type , const unsigned char * V_98 , unsigned int V_99 ,
const unsigned char * V_100 , unsigned int V_101 , const T_4 * V_92 )
{
long V_67 ;
long V_68 ;
long V_102 = V_101 ;
long V_69 = 0 ;
unsigned char V_71 [ 8 ] ;
long V_70 = 1 ;
unsigned char V_72 [ 8 ] = L_3 ;
long V_66 ;
unsigned char * V_62 = ( unsigned char * ) F_42 ( V_92 , V_44 ) ;
long V_103 = V_104 ;
long V_105 ;
unsigned char * V_106 = NULL ;
T_5 V_107 ;
T_6 V_108 ;
T_7 V_109 ;
T_8 V_110 ;
V_66 = * ( long * ) V_62 ;
V_62 += sizeof( long ) ;
if ( type == V_111 || type == V_112 )
{
V_107 . V_113 = & V_109 ;
V_109 . V_109 = F_45 ( type ) ;
if ( ! V_109 . V_109 )
{
F_27 ( V_114 ,
V_115 ) ;
return 0 ;
}
if ( ! V_109 . V_109 -> V_103 )
{
F_27 ( V_114 ,
V_116 ) ;
return 0 ;
}
V_108 . type = V_117 ;
V_108 . V_118 . V_119 = NULL ;
V_109 . V_108 = & V_108 ;
V_107 . V_110 = & V_110 ;
V_107 . V_110 -> V_120 = ( unsigned char * ) V_98 ;
V_107 . V_110 -> V_103 = V_99 ;
V_103 = F_46 ( & V_107 , NULL ) ;
}
V_105 = F_41 ( V_92 ) ;
if ( V_103 - V_121 > V_105 )
{
F_27 ( V_114 ,
V_81 ) ;
return 0 ;
}
switch ( type )
{
case V_122 :
if ( V_99 != V_104 )
{
F_27 ( V_114 ,
V_81 ) ;
return 0 ;
}
V_106 = ( unsigned char * ) V_98 ;
V_103 = V_99 ;
break;
case V_111 :
{
unsigned char * V_119 ;
V_119 = V_106 = F_33 (
( unsigned int ) V_105 + 1 ) ;
if ( ! V_106 )
{
F_27 ( V_114 ,
V_82 ) ;
return 0 ;
}
F_46 ( & V_107 , & V_119 ) ;
}
break;
case V_112 :
{
unsigned char * V_119 ;
V_119 = V_106 = F_33 (
( unsigned int ) V_105 + 1 ) ;
if ( ! V_106 )
{
F_27 ( V_114 ,
V_82 ) ;
return 0 ;
}
F_46 ( & V_107 , & V_119 ) ;
}
break;
default:
return 0 ;
}
V_32 ( & V_67 , & V_68 , & V_69 ,
V_71 , & V_70 , V_72 , & V_66 ,
V_62 , & V_103 , V_106 , & V_102 ,
( unsigned char * ) V_100 ) ;
if ( type == V_112 || type == V_111 )
{
F_47 ( V_106 , V_105 + 1 ) ;
F_3 ( V_106 ) ;
}
return ( ( V_67 || V_68 ) ? 0 : 1 ) ;
}
static int F_48 ( int type , const unsigned char * V_98 , unsigned int V_99 ,
unsigned char * V_123 , unsigned int * V_101 , const T_4 * V_92 )
{
long V_67 ;
long V_68 ;
long V_69 = 0 ;
unsigned char V_71 [ 8 ] ;
long V_70 = 1 ;
unsigned char V_72 [ 8 ] = L_3 ;
long V_97 = 256 ;
long V_124 ;
long V_66 ;
unsigned char * V_106 = NULL ;
unsigned char * V_62 = ( unsigned char * ) F_42 ( V_92 , V_44 ) ;
long V_103 = V_104 ;
long V_105 ;
T_5 V_107 ;
T_6 V_108 ;
T_7 V_109 ;
T_8 V_110 ;
V_66 = * ( long * ) V_62 ;
V_62 += sizeof( long ) ;
if ( type == V_111 || type == V_112 )
{
V_107 . V_113 = & V_109 ;
V_109 . V_109 = F_45 ( type ) ;
if ( ! V_109 . V_109 )
{
F_27 ( V_125 ,
V_115 ) ;
return 0 ;
}
if ( ! V_109 . V_109 -> V_103 )
{
F_27 ( V_125 ,
V_116 ) ;
return 0 ;
}
V_108 . type = V_117 ;
V_108 . V_118 . V_119 = NULL ;
V_109 . V_108 = & V_108 ;
V_107 . V_110 = & V_110 ;
V_107 . V_110 -> V_120 = ( unsigned char * ) V_98 ;
V_107 . V_110 -> V_103 = V_99 ;
V_103 = F_46 ( & V_107 , NULL ) ;
}
V_105 = F_41 ( V_92 ) ;
if ( V_103 - V_121 > V_105 )
{
F_27 ( V_125 ,
V_81 ) ;
return 0 ;
}
switch ( type )
{
case V_122 :
if ( V_99 != V_104 )
{
F_27 ( V_125 ,
V_81 ) ;
return 0 ;
}
V_106 = ( unsigned char * ) V_98 ;
V_103 = V_99 ;
break;
case V_111 :
{
unsigned char * V_119 ;
V_119 = V_106 = F_33 (
( unsigned int ) V_105 + 1 ) ;
if ( ! V_106 )
{
F_27 ( V_125 ,
V_82 ) ;
return 0 ;
}
F_46 ( & V_107 , & V_119 ) ;
}
break;
case V_112 :
{
unsigned char * V_119 ;
V_119 = V_106 = F_33 (
( unsigned int ) V_105 + 1 ) ;
if ( ! V_106 )
{
F_27 ( V_125 ,
V_82 ) ;
return 0 ;
}
F_46 ( & V_107 , & V_119 ) ;
}
break;
default:
return 0 ;
}
V_29 ( & V_67 , & V_68 , & V_69 ,
V_71 , & V_70 , V_72 , & V_66 ,
V_62 , & V_103 , V_106 , & V_97 , & V_124 ,
V_123 ) ;
if ( type == V_112 || type == V_111 )
{
F_47 ( V_106 , V_105 + 1 ) ;
F_3 ( V_106 ) ;
}
* V_101 = V_97 ;
return ( ( V_67 || V_68 ) ? 0 : 1 ) ;
}
static int F_34 ( const unsigned char * V_126 , long * V_79 ,
unsigned char * V_78 , long * V_77 , long * V_76 ,
unsigned char * V_75 )
{
unsigned long V_127 ;
if ( * V_126 ++ != ( char ) 0x1E )
return 0 ;
if ( * V_126 ++ )
return 0 ;
V_127 = * V_126 ++ ;
V_127 = V_127 << 8 ;
V_127 |= ( unsigned char ) * V_126 ++ ;
V_126 += 4 ;
if ( * V_126 ++ == ( char ) 0x04 )
{
if ( * V_126 ++ )
return 0 ;
V_127 = * V_126 ++ ;
V_127 = V_127 << 8 ;
V_127 |= ( unsigned char ) * V_126 ++ ;
V_126 += 2 ;
V_127 = * V_126 ++ ;
V_127 = V_127 << 8 ;
V_127 |= ( unsigned char ) * V_126 ++ ;
* V_79 = V_127 ;
V_127 = * V_126 ++ ;
V_127 = V_127 << 8 ;
V_127 |= ( unsigned char ) * V_126 ++ ;
* V_77 = V_127 ;
V_127 = * V_126 ++ ;
V_127 = V_127 << 8 ;
V_127 |= ( unsigned char ) * V_126 ++ ;
* V_76 = V_127 ;
memcpy ( V_78 , V_126 , * V_79 ) ;
V_126 += * V_79 ;
memcpy ( V_75 , V_126 , * V_76 ) ;
return 1 ;
}
return 0 ;
}
static int F_49 ( void )
{
return 1 ;
}
static int F_50 ( unsigned char * V_128 , int V_129 )
{
long V_130 ;
long V_131 ;
long V_132 ;
unsigned char V_133 [ 4 ] ;
unsigned char V_134 [] = L_4 ;
unsigned char V_135 [ 8 ] ;
while( V_129 >= ( int ) sizeof( V_135 ) )
{
V_26 ( & V_130 , & V_131 , & V_132 ,
V_133 , V_134 , V_135 ) ;
if ( V_130 )
return 0 ;
V_129 -= sizeof( V_135 ) ;
memcpy ( V_128 , V_135 , sizeof( V_135 ) ) ;
V_128 += sizeof( V_135 ) ;
}
if ( V_129 )
{
V_26 ( & V_130 , & V_131 , NULL , NULL ,
V_134 , V_135 ) ;
if ( V_130 )
return 0 ;
memcpy ( V_128 , V_135 , V_129 ) ;
}
return 1 ;
}
static void V_45 ( void * V_136 , void * V_137 , T_9 * V_138 , int V_139 ,
long V_140 , void * V_141 )
{
if ( V_137 )
F_3 ( V_137 ) ;
}
static int F_51 ( T_1 * V_4 , const char * V_142 )
{
if( V_142 && ( strcmp ( V_142 , V_5 ) != 0 ) &&
( strcmp ( V_142 , V_143 ) != 0 ) )
return 0 ;
if( ! F_6 ( V_4 ) )
return 0 ;
return 1 ;
}
