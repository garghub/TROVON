static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
int F_3 ( T_2 * V_3 )
{
unsigned long V_4 = ( unsigned long ) time ( NULL ) ;
T_3 * V_5 = NULL ;
int V_6 = - 1 ;
void (* F_4)( const T_2 * V_7 , int type , int V_8 ) = NULL ;
int V_9 , V_10 ;
F_5 ( & V_4 , sizeof( V_4 ) , 0 ) ;
F_6 () ;
F_7 () ;
if ( V_3 -> V_11 != NULL )
F_4 = V_3 -> V_11 ;
else if ( V_3 -> V_12 -> V_11 != NULL )
F_4 = V_3 -> V_12 -> V_11 ;
V_3 -> V_13 ++ ;
if ( ! F_8 ( V_3 ) || F_9 ( V_3 ) ) F_10 ( V_3 ) ;
for (; ; )
{
V_10 = V_3 -> V_10 ;
switch ( V_3 -> V_10 )
{
case V_14 :
case V_15 :
case V_14 | V_15 :
case V_16 | V_15 :
V_3 -> V_17 = 0 ;
if ( F_4 != NULL ) F_4 ( V_3 , V_18 , 1 ) ;
V_3 -> V_19 = V_2 ;
V_3 -> type = V_15 ;
V_5 = V_3 -> V_20 ;
if ( ( V_5 == NULL ) && ( ( V_5 = F_11 () ) == NULL ) )
{
V_6 = - 1 ;
goto V_21;
}
if ( ! F_12 ( V_5 ,
V_22 ) )
{
if ( V_5 == V_3 -> V_20 )
V_5 = NULL ;
V_6 = - 1 ;
goto V_21;
}
V_3 -> V_20 = V_5 ;
V_5 = NULL ;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_24 ;
V_3 -> V_12 -> V_25 . V_26 ++ ;
V_3 -> V_27 = F_3 ;
BREAK ;
case V_24 :
case V_28 :
V_3 -> V_29 = 0 ;
V_6 = F_13 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_30 ;
BREAK ;
case V_30 :
case V_31 :
V_6 = F_14 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
if ( ! V_3 -> V_32 )
{
V_3 -> V_10 = V_33 ;
BREAK ;
}
else
{
V_3 -> V_10 = V_34 ;
break;
}
case V_33 :
case V_35 :
V_6 = F_15 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_34 ;
break;
case V_34 :
if ( ! F_16 ( V_3 , 1 ) )
{
V_6 = - 1 ;
goto V_21;
}
V_3 -> V_36 -> V_37 = 0 ;
V_3 -> V_10 = V_38 ;
break;
case V_38 :
case V_39 :
V_6 = F_17 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_40 ;
break;
case V_40 :
case V_41 :
V_6 = F_18 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_42 ;
break;
case V_42 :
case V_43 :
V_6 = F_19 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_6 = F_20 ( V_3 ) ;
if ( V_6 <= 0 ) goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_42 ;
break;
case V_16 :
if ( V_3 -> V_20 != NULL )
{
F_21 ( V_3 -> V_20 ) ;
V_3 -> V_20 = NULL ;
}
V_3 -> V_23 = 0 ;
F_22 ( V_3 , V_49 ) ;
if ( V_3 -> V_32 ) V_3 -> V_12 -> V_25 . V_50 ++ ;
V_6 = 1 ;
V_3 -> V_12 -> V_25 . V_51 ++ ;
if ( F_4 != NULL ) F_4 ( V_3 , V_52 , 1 ) ;
goto V_21;
default:
F_23 ( V_53 , V_54 ) ;
return ( - 1 ) ;
}
if ( ( F_4 != NULL ) && ( V_3 -> V_10 != V_10 ) )
{
V_9 = V_3 -> V_10 ;
V_3 -> V_10 = V_10 ;
F_4 ( V_3 , V_55 , 1 ) ;
V_3 -> V_10 = V_9 ;
}
}
V_21:
V_3 -> V_13 -- ;
if ( V_5 != NULL )
F_21 ( V_5 ) ;
if ( F_4 != NULL )
F_4 ( V_3 , V_56 , V_6 ) ;
return ( V_6 ) ;
}
static int F_14 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 ;
int V_58 , V_59 ;
unsigned long V_60 ;
F_24 ( V_61 ) * V_62 = NULL , * V_63 , * V_64 , * V_65 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_57 = V_5 ;
if ( V_3 -> V_10 == V_30 )
{
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , 11 - V_3 -> V_23 ) ;
if ( V_58 < ( 11 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_67 , V_58 ) ) ;
V_3 -> V_23 = 11 ;
if ( * ( V_57 ++ ) != V_68 )
{
if ( V_57 [ - 1 ] != V_69 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 ,
V_71 ) ;
}
else
F_23 ( V_67 ,
V_72 ) ;
return ( - 1 ) ;
}
#ifdef F_28
V_3 -> V_32 = ( V_58 = * ( V_57 ++ ) ) ? 1 : 0 ;
#else
V_3 -> V_32 = ( * ( V_57 ++ ) ) ? 1 : 0 ;
#endif
V_3 -> V_36 -> V_73 . V_74 = * ( V_57 ++ ) ;
F_29 ( V_57 , V_58 ) ;
if ( V_58 < V_3 -> V_19 ) V_3 -> V_19 = V_58 ;
F_29 ( V_57 , V_58 ) ; V_3 -> V_36 -> V_73 . V_75 = V_58 ;
F_29 ( V_57 , V_58 ) ; V_3 -> V_36 -> V_73 . V_76 = V_58 ;
F_29 ( V_57 , V_58 ) ; V_3 -> V_36 -> V_73 . V_77 = V_58 ;
V_3 -> V_10 = V_31 ;
}
V_60 = 11 + ( unsigned long ) V_3 -> V_36 -> V_73 . V_75 + ( unsigned long ) V_3 -> V_36 -> V_73 . V_76 + ( unsigned long ) V_3 -> V_36 -> V_73 . V_77 ;
if ( V_60 > V_22 )
{
F_23 ( V_67 , V_78 ) ;
return - 1 ;
}
V_59 = ( int ) V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , V_59 ) ;
if ( V_58 != V_59 ) return ( F_26 ( V_3 , V_67 , V_58 ) ) ;
if ( V_3 -> V_79 )
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_60 , V_3 , V_3 -> V_81 ) ;
V_57 = V_5 + 11 ;
if ( V_3 -> V_32 )
{
if ( V_3 -> V_36 -> V_73 . V_75 != 0 )
{
F_23 ( V_67 , V_82 ) ;
return ( - 1 ) ;
}
if ( V_3 -> V_36 -> V_73 . V_74 != 0 )
{
if ( ! ( V_3 -> V_83 &
V_84 ) )
{
F_23 ( V_67 , V_85 ) ;
return ( - 1 ) ;
}
}
if ( V_3 -> V_36 -> V_73 . V_76 != 0 )
{
F_23 ( V_67 , V_86 ) ;
return ( - 1 ) ;
}
}
else
{
#ifdef undef
memset ( V_3 -> V_87 -> V_88 , 0 ,
V_89 ) ;
V_3 -> V_87 -> V_90 = 0 ;
* /
#endif
if ( V_3 -> V_87 -> V_90 > 0 )
{
if ( ! F_30 ( V_3 , 0 ) )
{
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( F_31 ( V_3 , V_3 -> V_36 -> V_73 . V_74 ,
V_3 -> V_36 -> V_73 . V_75 , V_57 ) <= 0 )
{
F_27 ( V_3 , V_91 ) ;
return ( - 1 ) ;
}
V_57 += V_3 -> V_36 -> V_73 . V_75 ;
if ( V_3 -> V_36 -> V_73 . V_76 == 0 )
{
F_27 ( V_3 , V_92 ) ;
F_23 ( V_67 , V_93 ) ;
return ( - 1 ) ;
}
V_62 = F_32 ( V_3 , V_57 , V_3 -> V_36 -> V_73 . V_76 ,
& V_3 -> V_87 -> V_94 ) ;
V_57 += V_3 -> V_36 -> V_73 . V_76 ;
if ( V_62 == NULL )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_95 ) ;
return ( - 1 ) ;
}
( void ) F_33 ( V_62 , V_96 ) ;
V_63 = F_34 ( V_3 ) ;
( void ) F_33 ( V_63 , V_96 ) ;
if ( V_3 -> V_83 & V_97 )
{
V_64 = V_62 ;
V_65 = V_63 ;
}
else
{
V_64 = V_63 ;
V_65 = V_62 ;
}
for ( V_58 = 0 ; V_58 < F_35 ( V_64 ) ; V_58 ++ )
{
if ( F_36 ( V_65 ,
F_37 ( V_64 , V_58 ) ) >= 0 )
break;
}
if ( V_58 >= F_35 ( V_64 ) )
{
F_27 ( V_3 , V_92 ) ;
F_23 ( V_67 , V_98 ) ;
return ( - 1 ) ;
}
V_3 -> V_87 -> V_99 = F_37 ( V_64 , V_58 ) ;
if ( V_3 -> V_87 -> V_100 != NULL )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_101 ) ;
return ( - 1 ) ;
}
V_3 -> V_87 -> V_100 = V_3 -> V_87 -> V_102 -> V_103 -> V_104 ;
F_38 ( & V_3 -> V_87 -> V_100 -> V_105 , 1 , V_106 ) ;
}
if ( V_3 -> V_87 -> V_102 == NULL
|| V_3 -> V_87 -> V_100 != V_3 -> V_87 -> V_102 -> V_103 -> V_104 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_101 ) ;
return ( - 1 ) ;
}
V_3 -> V_36 -> V_77 = V_3 -> V_36 -> V_73 . V_77 ;
if ( V_3 -> V_36 -> V_77 > sizeof V_3 -> V_36 -> V_107 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_108 ) ;
return - 1 ;
}
memcpy ( V_3 -> V_36 -> V_107 , V_57 , V_3 -> V_36 -> V_73 . V_77 ) ;
return ( 1 ) ;
}
static int F_13 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_109 ;
int V_58 , V_110 , V_59 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_24 )
{
if ( ( V_3 -> V_87 == NULL ) ||
( V_3 -> V_87 -> V_111 != V_3 -> V_19 ) )
{
if ( ! F_30 ( V_3 , 0 ) )
{
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
V_57 = V_5 ;
V_109 = V_57 + 9 ;
* ( V_57 ++ ) = V_112 ;
F_39 ( V_2 , V_57 ) ;
V_110 = V_59 = 0 ;
V_110 = F_40 ( V_3 , F_34 ( V_3 ) , V_109 , 0 ) ;
V_109 += V_110 ;
if ( V_110 == 0 )
{
F_23 ( V_113 , V_114 ) ;
return ( - 1 ) ;
}
F_39 ( V_110 , V_57 ) ;
if ( ( V_3 -> V_87 -> V_90 > 0 ) &&
( V_3 -> V_87 -> V_90 <=
V_115 ) )
{
V_58 = V_3 -> V_87 -> V_90 ;
F_39 ( V_58 , V_57 ) ;
memcpy ( V_109 , V_3 -> V_87 -> V_88 , ( unsigned int ) V_58 ) ;
V_109 += V_58 ;
}
else
{
F_39 ( 0 , V_57 ) ;
}
V_3 -> V_36 -> V_116 = V_117 ;
F_39 ( V_117 , V_57 ) ;
if ( F_41 ( V_3 -> V_36 -> V_118 , V_117 ) <= 0 )
return - 1 ;
memcpy ( V_109 , V_3 -> V_36 -> V_118 , V_117 ) ;
V_109 += V_117 ;
V_3 -> V_10 = V_28 ;
V_3 -> V_23 = V_109 - V_5 ;
V_3 -> V_119 = 0 ;
}
return ( F_42 ( V_3 ) ) ;
}
static int F_15 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_109 ;
int V_120 , V_121 , V_122 , V_58 ;
T_4 * V_123 ;
const T_5 * V_124 ;
const T_6 * V_125 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_33 )
{
if ( ! F_43 ( V_3 -> V_87 , & V_124 , & V_125 , NULL , NULL , NULL ) )
{
F_27 ( V_3 , V_92 ) ;
F_23 ( V_126 , V_127 ) ;
return ( - 1 ) ;
}
V_123 = V_3 -> V_87 ;
V_57 = V_5 ;
V_109 = V_57 + 10 ;
* ( V_57 ++ ) = V_128 ;
V_58 = F_44 ( V_3 , V_123 -> V_99 , V_57 ) ;
V_57 += V_58 ;
V_58 = F_45 ( V_124 ) ;
V_123 -> V_129 = V_58 ;
if ( V_58 > V_130 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_126 , V_101 ) ;
return - 1 ;
}
if ( V_58 > 0 )
if ( F_41 ( V_123 -> V_131 , V_58 ) <= 0 )
return - 1 ;
V_58 = F_46 ( V_124 ) ;
V_123 -> V_132 = V_58 ;
if ( V_58 > 0 )
{
if ( V_58 > ( int ) sizeof( V_123 -> V_133 ) )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_126 , V_101 ) ;
return - 1 ;
}
if ( F_47 ( V_123 -> V_133 , V_58 ) <= 0 )
{
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( V_123 -> V_99 -> V_134 & V_135 )
V_121 = 8 ;
else if ( F_48 ( V_123 -> V_99 ) )
V_121 = 5 ;
else
V_121 = V_58 ;
if ( ( int ) V_58 < V_121 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_126 , V_136 ) ;
return ( - 1 ) ;
}
V_120 = V_58 - V_121 ;
F_39 ( V_120 , V_57 ) ;
memcpy ( V_109 , V_123 -> V_133 , ( unsigned int ) V_120 ) ;
V_109 += V_120 ;
V_121 = F_49 ( V_123 -> V_102 , V_121 ,
& ( V_123 -> V_133 [ V_120 ] ) , V_109 ,
( V_3 -> V_36 -> V_137 ) ? V_138 : V_139 ) ;
if ( V_121 <= 0 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_126 , V_140 ) ;
return ( - 1 ) ;
}
#ifdef F_50
if ( V_3 -> V_83 & V_141 ) V_109 [ 1 ] ++ ;
if ( V_3 -> V_83 & V_142 )
V_123 -> V_133 [ V_120 ] ++ ;
#endif
F_39 ( V_121 , V_57 ) ;
V_109 += V_121 ;
V_122 = V_123 -> V_129 ;
F_39 ( V_122 , V_57 ) ;
if ( V_122 > ( int ) sizeof( V_123 -> V_131 ) )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_126 , V_101 ) ;
return - 1 ;
}
memcpy ( V_109 , V_123 -> V_131 , ( unsigned int ) V_122 ) ;
V_109 += V_122 ;
V_3 -> V_10 = V_35 ;
V_3 -> V_23 = V_109 - V_5 ;
V_3 -> V_119 = 0 ;
}
return ( F_42 ( V_3 ) ) ;
}
static int F_17 ( T_2 * V_3 )
{
unsigned char * V_57 ;
if ( V_3 -> V_10 == V_38 )
{
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
* ( V_57 ++ ) = V_143 ;
if ( V_3 -> V_36 -> V_77 > sizeof V_3 -> V_36 -> V_107 )
{
F_23 ( V_144 , V_101 ) ;
return - 1 ;
}
memcpy ( V_57 , V_3 -> V_36 -> V_107 , ( unsigned int ) V_3 -> V_36 -> V_77 ) ;
V_3 -> V_10 = V_39 ;
V_3 -> V_23 = V_3 -> V_36 -> V_77 + 1 ;
V_3 -> V_119 = 0 ;
}
return ( F_42 ( V_3 ) ) ;
}
static int F_20 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_109 ;
int V_58 ;
unsigned int V_110 ;
int V_145 ;
unsigned char * V_146 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_44 )
{
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) ,
V_147 + 2 - V_3 -> V_23 ) ;
if ( V_58 < ( V_148 + 2 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_149 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
if ( V_3 -> V_79 )
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_3 -> V_23 , V_3 , V_3 -> V_81 ) ;
if ( V_5 [ 1 ] != V_150 )
{
F_27 ( V_3 , V_151 ) ;
F_23 ( V_149 , V_152 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_153 == NULL ) ||
( V_3 -> V_153 -> V_154 -> V_104 == NULL ) ||
( V_3 -> V_153 -> V_154 -> V_155 == NULL ) )
{
V_3 -> V_10 = V_48 ;
}
else
V_3 -> V_10 = V_46 ;
}
V_146 = V_5 + 2 ;
V_145 = V_3 -> V_23 - 2 ;
if ( V_3 -> V_10 == V_48 )
{
T_7 * V_104 = NULL ;
T_8 * V_156 = NULL ;
V_58 = 0 ;
if ( V_3 -> V_12 -> V_157 != NULL )
{
V_58 = V_3 -> V_12 -> V_157 ( V_3 , & ( V_104 ) , & ( V_156 ) ) ;
}
if ( V_58 < 0 )
{
V_3 -> V_158 = V_159 ;
return ( - 1 ) ;
}
V_3 -> V_158 = V_160 ;
if ( ( V_58 == 1 ) && ( V_156 != NULL ) && ( V_104 != NULL ) )
{
V_3 -> V_10 = V_46 ;
if ( ! F_51 ( V_3 , V_104 ) ||
! F_52 ( V_3 , V_156 ) )
{
V_58 = 0 ;
}
F_53 ( V_104 ) ;
F_54 ( V_156 ) ;
}
else if ( V_58 == 1 )
{
if ( V_104 != NULL ) F_53 ( V_104 ) ;
if ( V_156 != NULL ) F_54 ( V_156 ) ;
F_23 ( V_149 , V_161 ) ;
V_58 = 0 ;
}
if ( V_58 == 0 )
{
V_3 -> V_10 = V_45 ;
V_57 = V_5 ;
* ( V_57 ++ ) = V_69 ;
F_39 ( V_162 , V_57 ) ;
V_3 -> V_119 = 0 ;
V_3 -> V_23 = 3 ;
}
}
if ( V_3 -> V_10 == V_45 )
{
return ( F_42 ( V_3 ) ) ;
}
if ( V_3 -> V_10 == V_46 )
{
T_9 V_12 ;
V_57 = V_5 ;
F_55 ( & V_12 ) ;
F_56 ( & V_12 , V_3 -> V_12 -> V_163 , NULL ) ;
F_57 ( & V_12 , V_3 -> V_36 -> V_164 ,
V_3 -> V_36 -> V_165 ) ;
F_57 ( & V_12 , V_146 , ( unsigned int ) V_145 ) ;
V_58 = F_58 ( V_3 -> V_87 -> V_102 -> V_103 -> V_104 , & V_57 ) ;
if( V_58 > 0 )
F_57 ( & V_12 , V_5 , ( unsigned int ) V_58 ) ;
V_57 = V_5 ;
V_109 = V_57 + 6 ;
* ( V_57 ++ ) = V_166 ;
* ( V_57 ++ ) = V_167 ;
V_110 = F_58 ( V_3 -> V_153 -> V_154 -> V_104 , & V_109 ) ;
F_39 ( V_110 , V_57 ) ;
if ( ! F_59 ( & V_12 , V_109 , & V_110 , V_3 -> V_153 -> V_154 -> V_155 ) )
{
}
F_60 ( & V_12 ) ;
F_39 ( V_110 , V_57 ) ;
V_109 += V_110 ;
V_3 -> V_10 = V_47 ;
V_3 -> V_23 = V_109 - V_5 ;
V_3 -> V_119 = 0 ;
}
return ( F_42 ( V_3 ) ) ;
}
static int F_18 ( T_2 * V_3 )
{
unsigned char * V_57 ;
int V_58 , V_110 , V_60 ;
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_40 )
{
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 1 - V_3 -> V_23 ) ;
if ( V_58 < ( 1 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_168 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
V_3 -> V_10 = V_41 ;
if ( * V_57 != V_169 )
{
if ( V_57 [ 0 ] != V_69 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_168 ,
V_71 ) ;
}
else
{
F_23 ( V_168 , V_72 ) ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 3 - V_3 -> V_23 ) ;
return F_26 ( V_3 , V_168 , V_58 ) ;
}
return ( - 1 ) ;
}
}
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_60 = 1 + V_3 -> V_36 -> V_116 ;
V_110 = V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , V_110 ) ;
if ( V_58 < V_110 )
return ( F_26 ( V_3 , V_168 , V_58 ) ) ;
if ( V_3 -> V_79 )
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_57 , V_60 , V_3 , V_3 -> V_81 ) ;
V_57 += 1 ;
if ( memcmp ( V_57 , V_3 -> V_36 -> V_118 , V_3 -> V_36 -> V_116 ) != 0 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_168 , V_170 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_19 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 ;
int V_58 , V_110 , V_60 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_57 = V_5 ;
if ( V_3 -> V_10 == V_42 )
{
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , 1 - V_3 -> V_23 ) ;
if ( V_58 < ( 1 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_171 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
if ( * V_57 == V_172 )
{
V_3 -> V_10 = V_44 ;
return ( 1 ) ;
}
else if ( * V_57 != V_173 )
{
if ( V_57 [ 0 ] != V_69 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_171 , V_71 ) ;
}
else
{
F_23 ( V_171 , V_72 ) ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 3 - V_3 -> V_23 ) ;
return F_26 ( V_3 , V_168 , V_58 ) ;
}
return ( - 1 ) ;
}
V_3 -> V_10 = V_43 ;
}
V_60 = 1 + V_174 ;
V_110 = V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , V_110 ) ;
if ( V_58 < V_110 )
return ( F_26 ( V_3 , V_171 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
if ( V_3 -> V_79 )
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_3 -> V_23 , V_3 , V_3 -> V_81 ) ;
if ( ! V_3 -> V_32 )
{
V_3 -> V_87 -> V_90 = V_174 ;
memcpy ( V_3 -> V_87 -> V_88 , V_57 + 1 , V_174 ) ;
}
else
{
if ( ! ( V_3 -> V_83 & V_175 ) )
{
if ( ( V_3 -> V_87 -> V_90 > sizeof V_3 -> V_87 -> V_88 )
|| ( 0 != memcmp ( V_5 + 1 , V_3 -> V_87 -> V_88 ,
( unsigned int ) V_3 -> V_87 -> V_90 ) ) )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_171 , V_176 ) ;
return ( - 1 ) ;
}
}
}
V_3 -> V_10 = V_16 ;
return ( 1 ) ;
}
int F_31 ( T_2 * V_3 , int type , int V_60 , const unsigned char * V_66 )
{
F_24 ( T_7 ) * V_62 = NULL ;
T_8 * V_156 = NULL ;
T_10 * V_177 = NULL ;
int V_58 ;
T_7 * V_104 = NULL ;
int V_6 = 0 ;
V_104 = F_61 ( NULL , & V_66 , ( long ) V_60 ) ;
if ( V_104 == NULL )
{
F_23 ( V_178 , V_179 ) ;
goto V_180;
}
if ( ( V_62 = F_62 () ) == NULL || ! F_63 ( V_62 , V_104 ) )
{
F_23 ( V_178 , V_95 ) ;
goto V_180;
}
V_58 = F_64 ( V_3 , V_62 ) ;
if ( ( V_3 -> V_181 != V_182 ) && ( V_58 <= 0 ) )
{
F_23 ( V_178 , V_183 ) ;
goto V_180;
}
F_6 () ;
V_3 -> V_87 -> V_184 = V_3 -> V_184 ;
V_177 = F_65 () ;
if ( V_177 == NULL )
{
V_6 = - 1 ;
goto V_180;
}
if ( V_3 -> V_87 -> V_102 ) F_66 ( V_3 -> V_87 -> V_102 ) ;
V_3 -> V_87 -> V_102 = V_177 ;
V_177 -> V_185 [ V_186 ] . V_104 = V_104 ;
V_177 -> V_103 = & ( V_177 -> V_185 [ V_186 ] ) ;
V_156 = F_67 ( V_104 ) ;
V_104 = NULL ;
if ( V_156 == NULL )
{
F_23 ( V_178 , V_187 ) ;
goto V_180;
}
if ( V_156 -> type != V_188 )
{
F_23 ( V_178 , V_189 ) ;
goto V_180;
}
if ( ! F_68 ( V_177 , V_167 ) )
goto V_180;
V_6 = 1 ;
V_180:
F_69 ( V_62 ) ;
F_53 ( V_104 ) ;
F_54 ( V_156 ) ;
return ( V_6 ) ;
}
static int F_49 ( T_10 * V_177 , int V_60 , unsigned char * V_190 ,
unsigned char * V_191 , int V_192 )
{
T_8 * V_156 = NULL ;
int V_58 = - 1 ;
if ( ( V_177 == NULL ) || ( V_177 -> V_103 -> V_104 == NULL ) ||
( ( V_156 = F_67 ( V_177 -> V_103 -> V_104 ) ) == NULL ) )
{
F_23 ( V_193 , V_194 ) ;
return ( - 1 ) ;
}
if ( V_156 -> type != V_188 )
{
F_23 ( V_193 , V_195 ) ;
goto V_21;
}
V_58 = F_70 ( V_60 , V_190 , V_191 , V_156 -> V_156 . V_196 , V_192 ) ;
if ( V_58 < 0 )
F_23 ( V_193 , V_197 ) ;
V_21:
F_54 ( V_156 ) ;
return ( V_58 ) ;
}
