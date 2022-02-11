static T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
T_1 * F_2 ( void )
{
static int V_3 = 1 ;
static T_1 V_4 ;
if ( V_3 )
{
memcpy ( ( char * ) & V_4 , ( char * ) F_3 () ,
sizeof( T_1 ) ) ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = F_1 ;
V_3 = 0 ;
}
return ( & V_4 ) ;
}
int V_6 ( T_2 * V_8 )
{
unsigned long V_9 = time ( NULL ) ;
T_3 * V_10 = NULL ;
int V_11 = - 1 ;
void (* F_4)() = NULL ;
int V_12 , V_13 ;
F_5 ( & V_9 , sizeof( V_9 ) , 0 ) ;
F_6 () ;
F_7 () ;
if ( V_8 -> V_14 != NULL )
F_4 = V_8 -> V_14 ;
else if ( V_8 -> V_15 -> V_14 != NULL )
F_4 = V_8 -> V_15 -> V_14 ;
if ( ! F_8 ( V_8 ) || F_9 ( V_8 ) ) F_10 ( V_8 ) ;
V_8 -> V_16 ++ ;
for (; ; )
{
V_13 = V_8 -> V_13 ;
switch ( V_8 -> V_13 )
{
case V_17 :
case V_18 :
case V_17 | V_18 :
case V_19 | V_18 :
V_8 -> V_20 = 0 ;
if ( F_4 != NULL ) F_4 ( V_8 , V_21 , 1 ) ;
V_8 -> V_22 = V_2 ;
V_8 -> type = V_18 ;
V_10 = V_8 -> V_23 ;
if ( ( V_10 == NULL ) && ( ( V_10 = F_11 () ) == NULL ) )
{
V_11 = - 1 ;
goto V_24;
}
if ( ! F_12 ( V_10 ,
V_25 ) )
{
V_11 = - 1 ;
goto V_24;
}
V_8 -> V_23 = V_10 ;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_27 ;
V_8 -> V_15 -> V_28 . V_29 ++ ;
V_8 -> V_30 = V_6 ;
BREAK ;
case V_27 :
case V_31 :
V_8 -> V_32 = 0 ;
V_11 = F_13 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_33 ;
BREAK ;
case V_33 :
case V_34 :
V_11 = F_14 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
if ( ! V_8 -> V_35 )
{
V_8 -> V_13 = V_36 ;
BREAK ;
}
else
{
V_8 -> V_13 = V_37 ;
break;
}
case V_36 :
case V_38 :
V_11 = F_15 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_37 ;
break;
case V_37 :
if ( ! F_16 ( V_8 , 1 ) )
{
V_11 = - 1 ;
goto V_24;
}
V_8 -> V_39 -> V_40 = 0 ;
V_8 -> V_13 = V_41 ;
break;
case V_41 :
case V_42 :
V_11 = F_17 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_43 ;
break;
case V_43 :
case V_44 :
V_11 = F_18 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_45 ;
break;
case V_45 :
case V_46 :
V_11 = F_19 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_11 = F_20 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_45 ;
break;
case V_19 :
if ( V_8 -> V_23 != NULL )
{
F_21 ( V_8 -> V_23 ) ;
V_8 -> V_23 = NULL ;
}
V_8 -> V_26 = 0 ;
F_22 ( V_8 , V_52 ) ;
if ( V_8 -> V_35 ) V_8 -> V_15 -> V_28 . V_53 ++ ;
V_11 = 1 ;
V_8 -> V_15 -> V_28 . V_54 ++ ;
if ( F_4 != NULL ) F_4 ( V_8 , V_55 , 1 ) ;
goto V_24;
default:
F_23 ( V_56 , V_57 ) ;
return ( - 1 ) ;
}
if ( ( F_4 != NULL ) && ( V_8 -> V_13 != V_13 ) )
{
V_12 = V_8 -> V_13 ;
V_8 -> V_13 = V_13 ;
F_4 ( V_8 , V_58 , 1 ) ;
V_8 -> V_13 = V_12 ;
}
}
V_24:
V_8 -> V_16 -- ;
if ( F_4 != NULL )
F_4 ( V_8 , V_59 , V_11 ) ;
return ( V_11 ) ;
}
static int F_14 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 ;
int V_61 , V_62 ;
F_24 ( V_63 ) * V_64 = NULL , * V_65 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_60 = V_10 ;
if ( V_8 -> V_13 == V_33 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , 11 - V_8 -> V_26 ) ;
if ( V_61 < ( 11 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_67 , V_61 ) ) ;
if ( * ( V_60 ++ ) != V_68 )
{
if ( V_60 [ - 1 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 ,
V_71 ) ;
}
else
F_23 ( V_67 ,
V_72 ) ;
return ( - 1 ) ;
}
#ifdef F_28
V_8 -> V_35 = ( V_61 = * ( V_60 ++ ) ) ? 1 : 0 ;
#else
V_8 -> V_35 = ( * ( V_60 ++ ) ) ? 1 : 0 ;
#endif
V_8 -> V_39 -> V_73 . V_74 = * ( V_60 ++ ) ;
F_29 ( V_60 , V_61 ) ;
if ( V_61 < V_8 -> V_22 ) V_8 -> V_22 = V_61 ;
F_29 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_75 = V_61 ;
F_29 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_76 = V_61 ;
F_29 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_77 = V_61 ;
V_8 -> V_13 = V_34 ;
V_8 -> V_26 = 0 ;
}
V_62 = V_8 -> V_39 -> V_73 . V_75 + V_8 -> V_39 -> V_73 . V_76 + V_8 -> V_39 -> V_73 . V_77
- V_8 -> V_26 ;
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , V_62 ) ;
if ( V_61 != V_62 ) return ( F_26 ( V_8 , V_67 , V_61 ) ) ;
V_60 = V_10 ;
if ( V_8 -> V_35 )
{
if ( V_8 -> V_39 -> V_73 . V_75 != 0 )
{
F_23 ( V_67 , V_78 ) ;
return ( - 1 ) ;
}
if ( V_8 -> V_39 -> V_73 . V_74 != 0 )
{
if ( ! ( V_8 -> V_79 &
V_80 ) )
{
F_23 ( V_67 , V_81 ) ;
return ( - 1 ) ;
}
}
if ( V_8 -> V_39 -> V_73 . V_76 != 0 )
{
F_23 ( V_67 , V_82 ) ;
return ( - 1 ) ;
}
}
else
{
#ifdef undef
memset ( V_8 -> V_83 -> V_84 , 0 ,
V_85 ) ;
V_8 -> V_83 -> V_86 = 0 ;
* /
#endif
if ( V_8 -> V_83 -> V_86 > 0 )
{
if ( ! F_30 ( V_8 , 0 ) )
{
F_27 ( V_8 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( F_31 ( V_8 , V_8 -> V_39 -> V_73 . V_74 ,
V_8 -> V_39 -> V_73 . V_75 , V_60 ) <= 0 )
{
F_27 ( V_8 , V_87 ) ;
return ( - 1 ) ;
}
V_60 += V_8 -> V_39 -> V_73 . V_75 ;
if ( V_8 -> V_39 -> V_73 . V_76 == 0 )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_67 , V_89 ) ;
return ( - 1 ) ;
}
V_64 = F_32 ( V_8 , V_60 , V_8 -> V_39 -> V_73 . V_76 ,
& V_8 -> V_83 -> V_90 ) ;
V_60 += V_8 -> V_39 -> V_73 . V_76 ;
if ( V_64 == NULL )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 , V_91 ) ;
return ( - 1 ) ;
}
F_33 ( V_64 , V_92 ) ;
V_65 = F_34 ( V_8 ) ;
for ( V_61 = 0 ; V_61 < F_35 ( V_65 ) ; V_61 ++ )
{
if ( F_36 ( V_64 ,
F_37 ( V_65 , V_61 ) ) >= 0 )
break;
}
if ( V_61 >= F_35 ( V_65 ) )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_67 , V_93 ) ;
return ( - 1 ) ;
}
V_8 -> V_83 -> V_94 = F_37 ( V_65 , V_61 ) ;
if ( V_8 -> V_83 -> V_95 != NULL )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 , V_96 ) ;
return ( - 1 ) ;
}
V_8 -> V_83 -> V_95 = V_8 -> V_83 -> V_97 -> V_98 -> V_99 ;
F_38 ( & V_8 -> V_83 -> V_95 -> V_100 , 1 , V_101 ) ;
}
if ( V_8 -> V_83 -> V_95 != V_8 -> V_83 -> V_97 -> V_98 -> V_99 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 , V_96 ) ;
return ( - 1 ) ;
}
V_8 -> V_39 -> V_77 = V_8 -> V_39 -> V_73 . V_77 ;
memcpy ( V_8 -> V_39 -> V_102 , V_60 , V_8 -> V_39 -> V_73 . V_77 ) ;
return ( 1 ) ;
}
static int F_13 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_103 ;
int V_61 , V_104 , V_62 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_27 )
{
if ( ( V_8 -> V_83 == NULL ) ||
( V_8 -> V_83 -> V_105 != V_8 -> V_22 ) )
{
if ( ! F_30 ( V_8 , 0 ) )
{
F_27 ( V_8 , V_70 ) ;
return ( - 1 ) ;
}
}
V_60 = V_10 ;
V_103 = V_60 + 9 ;
* ( V_60 ++ ) = V_106 ;
F_39 ( V_2 , V_60 ) ;
V_104 = V_62 = 0 ;
V_104 = F_40 ( V_8 , F_41 ( V_8 ) , V_103 ) ;
V_103 += V_104 ;
if ( V_104 == 0 )
{
F_23 ( V_107 , V_108 ) ;
return ( - 1 ) ;
}
F_39 ( V_104 , V_60 ) ;
if ( ( V_8 -> V_83 -> V_86 > 0 ) &&
( V_8 -> V_83 -> V_86 <=
V_109 ) )
{
V_61 = V_8 -> V_83 -> V_86 ;
F_39 ( V_61 , V_60 ) ;
memcpy ( V_103 , V_8 -> V_83 -> V_84 , ( unsigned int ) V_61 ) ;
V_103 += V_61 ;
}
else
{
F_39 ( 0 , V_60 ) ;
}
V_8 -> V_39 -> V_110 = V_111 ;
F_39 ( V_111 , V_60 ) ;
F_42 ( V_8 -> V_39 -> V_112 , V_111 ) ;
memcpy ( V_103 , V_8 -> V_39 -> V_112 , V_111 ) ;
V_103 += V_111 ;
V_8 -> V_13 = V_31 ;
V_8 -> V_26 = V_103 - V_10 ;
V_8 -> V_113 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_15 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_103 ;
int V_114 , V_115 , V_116 , V_61 ;
T_4 * V_117 ;
const T_5 * V_118 ;
const T_6 * V_119 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_36 )
{
if ( ! F_44 ( V_8 -> V_83 , & V_118 , & V_119 , NULL ) )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_120 , V_121 ) ;
return ( - 1 ) ;
}
V_117 = V_8 -> V_83 ;
V_60 = V_10 ;
V_103 = V_60 + 10 ;
* ( V_60 ++ ) = V_122 ;
V_61 = F_45 ( V_8 , V_117 -> V_94 , V_60 ) ;
V_60 += V_61 ;
V_61 = F_46 ( V_118 ) ;
V_117 -> V_123 = V_61 ;
if ( V_61 > 0 ) F_42 ( V_117 -> V_124 , V_61 ) ;
V_61 = F_47 ( V_118 ) ;
V_117 -> V_125 = V_61 ;
if ( V_61 > 0 )
{
if ( F_48 ( V_117 -> V_126 , V_61 ) <= 0 )
{
F_27 ( V_8 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( V_117 -> V_94 -> V_127 & V_128 )
V_115 = 8 ;
else if ( F_49 ( V_117 -> V_94 ) )
V_115 = 5 ;
else
V_115 = V_61 ;
if ( V_61 < V_115 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_120 , V_129 ) ;
return ( - 1 ) ;
}
V_114 = V_61 - V_115 ;
F_39 ( V_114 , V_60 ) ;
memcpy ( V_103 , V_117 -> V_126 , ( unsigned int ) V_114 ) ;
V_103 += V_114 ;
V_115 = F_50 ( V_117 -> V_97 , V_115 ,
& ( V_117 -> V_126 [ V_114 ] ) , V_103 ,
( V_8 -> V_39 -> V_130 ) ? V_131 : V_132 ) ;
if ( V_115 <= 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_120 , V_133 ) ;
return ( - 1 ) ;
}
#ifdef F_51
if ( V_8 -> V_79 & V_134 ) V_103 [ 1 ] ++ ;
if ( V_8 -> V_79 & V_135 )
V_117 -> V_126 [ V_114 ] ++ ;
#endif
F_39 ( V_115 , V_60 ) ;
V_103 += V_115 ;
V_116 = V_117 -> V_123 ;
F_39 ( V_116 , V_60 ) ;
memcpy ( V_103 , V_117 -> V_124 , ( unsigned int ) V_116 ) ;
V_103 += V_116 ;
V_8 -> V_13 = V_38 ;
V_8 -> V_26 = V_103 - V_10 ;
V_8 -> V_113 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_17 ( T_2 * V_8 )
{
unsigned char * V_60 ;
if ( V_8 -> V_13 == V_41 )
{
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
* ( V_60 ++ ) = V_136 ;
memcpy ( V_60 , V_8 -> V_39 -> V_102 , ( unsigned int ) V_8 -> V_39 -> V_77 ) ;
V_8 -> V_13 = V_42 ;
V_8 -> V_26 = V_8 -> V_39 -> V_77 + 1 ;
V_8 -> V_113 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_20 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_103 ;
int V_61 ;
unsigned int V_104 ;
int V_137 = 0 ;
unsigned char * V_138 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_138 = & ( V_10 [ 2 ] ) ;
if ( V_8 -> V_13 == V_47 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) ,
V_139 + 1 - V_8 -> V_26 ) ;
if ( V_61 < ( V_140 + 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_141 , V_61 ) ) ;
if ( V_10 [ 1 ] != V_142 )
{
F_27 ( V_8 , V_143 ) ;
F_23 ( V_141 , V_144 ) ;
return ( - 1 ) ;
}
V_137 = V_61 - 1 ;
if ( ( V_8 -> V_145 == NULL ) ||
( V_8 -> V_145 -> V_146 -> V_99 == NULL ) ||
( V_8 -> V_145 -> V_146 -> V_147 == NULL ) )
{
V_8 -> V_13 = V_51 ;
}
else
V_8 -> V_13 = V_49 ;
}
if ( V_8 -> V_13 == V_51 )
{
T_7 * V_99 = NULL ;
T_8 * V_148 = NULL ;
V_61 = 0 ;
if ( V_8 -> V_15 -> V_149 != NULL )
{
V_61 = V_8 -> V_15 -> V_149 ( V_8 , & ( V_99 ) , & ( V_148 ) ) ;
}
if ( V_61 < 0 )
{
V_8 -> V_150 = V_151 ;
return ( - 1 ) ;
}
V_8 -> V_150 = V_152 ;
if ( ( V_61 == 1 ) && ( V_148 != NULL ) && ( V_99 != NULL ) )
{
V_8 -> V_13 = V_49 ;
if ( ! F_52 ( V_8 , V_99 ) ||
! F_53 ( V_8 , V_148 ) )
{
V_61 = 0 ;
}
F_54 ( V_99 ) ;
F_55 ( V_148 ) ;
}
else if ( V_61 == 1 )
{
if ( V_99 != NULL ) F_54 ( V_99 ) ;
if ( V_148 != NULL ) F_55 ( V_148 ) ;
F_23 ( V_141 , V_153 ) ;
V_61 = 0 ;
}
if ( V_61 == 0 )
{
V_8 -> V_13 = V_48 ;
V_60 = V_10 ;
* ( V_60 ++ ) = V_69 ;
F_39 ( V_154 , V_60 ) ;
V_8 -> V_113 = 0 ;
V_8 -> V_26 = 3 ;
}
}
if ( V_8 -> V_13 == V_48 )
{
return ( F_43 ( V_8 ) ) ;
}
if ( V_8 -> V_13 == V_49 )
{
T_9 V_15 ;
V_60 = V_10 ;
F_56 ( & V_15 , V_8 -> V_15 -> V_155 ) ;
F_57 ( & V_15 , V_8 -> V_39 -> V_156 ,
( unsigned int ) V_8 -> V_39 -> V_157 ) ;
F_57 ( & V_15 , V_138 , ( unsigned int ) V_137 ) ;
V_104 = F_58 ( V_8 -> V_83 -> V_97 -> V_98 -> V_99 , & V_60 ) ;
F_57 ( & V_15 , V_10 , ( unsigned int ) V_104 ) ;
V_60 = V_10 ;
V_103 = V_60 + 6 ;
* ( V_60 ++ ) = V_158 ;
* ( V_60 ++ ) = V_159 ;
V_104 = F_58 ( V_8 -> V_145 -> V_146 -> V_99 , & V_103 ) ;
F_39 ( V_104 , V_60 ) ;
if ( ! F_59 ( & V_15 , V_103 , & V_104 , V_8 -> V_145 -> V_146 -> V_147 ) )
{
}
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
F_39 ( V_104 , V_60 ) ;
V_103 += V_104 ;
V_8 -> V_13 = V_50 ;
V_8 -> V_26 = V_103 - V_10 ;
V_8 -> V_113 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_18 ( T_2 * V_8 )
{
unsigned char * V_60 ;
int V_61 ;
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_43 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_60 [ V_8 -> V_26 ] ) , 1 - V_8 -> V_26 ) ;
if ( V_61 < ( 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_160 , V_61 ) ) ;
V_8 -> V_13 = V_44 ;
V_8 -> V_26 = 0 ;
if ( * V_60 != V_161 )
{
if ( V_60 [ 0 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_160 ,
V_71 ) ;
}
else
F_23 ( V_160 ,
V_72 ) ;
return ( - 1 ) ;
}
}
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_61 = F_25 ( V_8 , ( char * ) & ( V_60 [ V_8 -> V_26 ] ) ,
( unsigned int ) V_8 -> V_39 -> V_110 - V_8 -> V_26 ) ;
if ( V_61 < ( ( int ) V_8 -> V_39 -> V_110 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_160 , V_61 ) ) ;
if ( memcmp ( V_60 , V_8 -> V_39 -> V_112 , ( unsigned int ) V_8 -> V_39 -> V_110 ) != 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_160 , V_162 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_19 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 ;
int V_61 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_60 = V_10 ;
if ( V_8 -> V_13 == V_45 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , 1 - V_8 -> V_26 ) ;
if ( V_61 < ( 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_163 , V_61 ) ) ;
V_8 -> V_26 = V_61 ;
if ( * V_60 == V_164 )
{
V_8 -> V_13 = V_47 ;
return ( 1 ) ;
}
else if ( * V_60 != V_165 )
{
if ( V_60 [ 0 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_163 , V_71 ) ;
}
else
F_23 ( V_163 , V_72 ) ;
return ( - 1 ) ;
}
V_8 -> V_13 = V_19 ;
V_8 -> V_26 = 0 ;
}
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) ,
V_166 - V_8 -> V_26 ) ;
if ( V_61 < ( V_166 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_163 , V_61 ) ) ;
if ( ! V_8 -> V_35 )
{
V_8 -> V_83 -> V_86 = V_166 ;
memcpy ( V_8 -> V_83 -> V_84 , V_60 , V_166 ) ;
}
else
{
if ( ! ( V_8 -> V_79 & V_167 ) )
{
if ( memcmp ( V_10 , V_8 -> V_83 -> V_84 ,
( unsigned int ) V_8 -> V_83 -> V_86 ) != 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_163 , V_168 ) ;
return ( - 1 ) ;
}
}
}
return ( 1 ) ;
}
int F_31 ( T_2 * V_8 , int type , int V_169 , unsigned char * V_66 )
{
F_24 ( T_7 ) * V_64 = NULL ;
T_8 * V_148 = NULL ;
T_10 * V_170 = NULL ;
int V_61 ;
T_7 * V_99 = NULL ;
int V_11 = 0 ;
V_99 = F_60 ( NULL , & V_66 , ( long ) V_169 ) ;
if ( V_99 == NULL )
{
F_23 ( V_171 , V_172 ) ;
goto V_173;
}
if ( ( V_64 = F_61 () ) == NULL || ! F_62 ( V_64 , V_99 ) )
{
F_23 ( V_171 , V_91 ) ;
goto V_173;
}
V_61 = F_63 ( V_8 , V_64 ) ;
if ( ( V_8 -> V_174 != V_175 ) && ( ! V_61 ) )
{
F_23 ( V_171 , V_176 ) ;
goto V_173;
}
F_6 () ;
V_170 = F_64 () ;
if ( V_170 == NULL )
{
V_11 = - 1 ;
goto V_173;
}
if ( V_8 -> V_83 -> V_97 ) F_65 ( V_8 -> V_83 -> V_97 ) ;
V_8 -> V_83 -> V_97 = V_170 ;
V_170 -> V_177 [ V_178 ] . V_99 = V_99 ;
V_170 -> V_98 = & ( V_170 -> V_177 [ V_178 ] ) ;
V_148 = F_66 ( V_99 ) ;
V_99 = NULL ;
if ( V_148 == NULL )
{
F_23 ( V_171 , V_179 ) ;
goto V_173;
}
if ( V_148 -> type != V_180 )
{
F_23 ( V_171 , V_181 ) ;
goto V_173;
}
if ( ! F_67 ( V_170 , V_159 ) )
goto V_173;
V_11 = 1 ;
V_173:
F_68 ( V_64 ) ;
F_54 ( V_99 ) ;
F_55 ( V_148 ) ;
return ( V_11 ) ;
}
static int F_50 ( T_10 * V_170 , int V_169 , unsigned char * V_182 ,
unsigned char * V_183 , int V_184 )
{
T_8 * V_148 = NULL ;
int V_61 = - 1 ;
if ( ( V_170 == NULL ) || ( V_170 -> V_98 -> V_99 == NULL ) ||
( ( V_148 = F_66 ( V_170 -> V_98 -> V_99 ) ) == NULL ) )
{
F_23 ( V_185 , V_186 ) ;
return ( - 1 ) ;
}
if ( V_148 -> type != V_180 )
{
F_23 ( V_185 , V_187 ) ;
goto V_24;
}
V_61 = F_69 ( V_169 , V_182 , V_183 , V_148 -> V_148 . V_188 , V_184 ) ;
if ( V_61 < 0 )
F_23 ( V_185 , V_189 ) ;
V_24:
F_55 ( V_148 ) ;
return ( V_61 ) ;
}
