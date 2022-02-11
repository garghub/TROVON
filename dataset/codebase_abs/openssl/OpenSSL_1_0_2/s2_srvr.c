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
long V_7 ;
void (* F_4) ( const T_2 * V_8 , int type , int V_9 ) = NULL ;
int V_10 , V_11 ;
F_5 ( & V_4 , sizeof( V_4 ) , 0 ) ;
F_6 () ;
F_7 () ;
if ( V_3 -> V_12 != NULL )
F_4 = V_3 -> V_12 ;
else if ( V_3 -> V_13 -> V_12 != NULL )
F_4 = V_3 -> V_13 -> V_12 ;
V_3 -> V_14 ++ ;
if ( ! F_8 ( V_3 ) || F_9 ( V_3 ) )
F_10 ( V_3 ) ;
if ( V_3 -> V_15 == NULL ) {
F_11 ( V_16 , V_17 ) ;
return ( - 1 ) ;
}
F_7 () ;
for (; ; ) {
V_11 = V_3 -> V_11 ;
switch ( V_3 -> V_11 ) {
case V_18 :
case V_19 :
case V_18 | V_19 :
case V_20 | V_19 :
V_3 -> V_21 = 1 ;
if ( F_4 != NULL )
F_4 ( V_3 , V_22 , 1 ) ;
V_3 -> V_23 = V_2 ;
V_3 -> type = V_19 ;
if ( V_3 -> V_24 == NULL ) {
if ( ( V_5 = F_12 () ) == NULL ) {
V_6 = - 1 ;
goto V_25;
}
if ( ! F_13
( V_5 , ( int ) V_26 ) ) {
F_14 ( V_5 ) ;
V_6 = - 1 ;
goto V_25;
}
V_3 -> V_24 = V_5 ;
}
V_3 -> V_27 = 0 ;
V_3 -> V_13 -> V_28 . V_29 ++ ;
V_3 -> V_30 = F_3 ;
V_3 -> V_11 = V_31 ;
BREAK ;
case V_31 :
case V_32 :
case V_33 :
V_3 -> V_34 = 0 ;
V_6 = F_15 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_35 ;
BREAK ;
case V_35 :
case V_36 :
V_6 = F_16 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
if ( ! V_3 -> V_37 ) {
V_3 -> V_11 = V_38 ;
BREAK ;
} else {
V_3 -> V_11 = V_39 ;
BREAK ;
}
case V_38 :
case V_40 :
V_6 = F_17 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_39 ;
BREAK ;
case V_39 :
if ( ! F_18 ( V_3 , 0 ) ) {
V_6 = - 1 ;
goto V_25;
}
V_3 -> V_41 -> V_42 = 0 ;
V_3 -> V_11 = V_43 ;
BREAK ;
case V_43 :
case V_44 :
V_6 = F_19 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
if ( V_3 -> V_37 ) {
V_3 -> V_11 = V_45 ;
BREAK ;
} else {
V_3 -> V_11 = V_46 ;
break;
}
case V_45 :
V_7 = F_20 ( V_3 -> V_47 , V_48 , 0 , NULL ) ;
if ( V_7 > 0 ) {
V_3 -> V_49 = V_50 ;
V_7 = F_21 ( V_3 -> V_47 ) ;
if ( V_7 <= 0 ) {
V_6 = - 1 ;
goto V_25;
}
V_3 -> V_49 = V_51 ;
}
V_3 -> V_47 = F_22 ( V_3 -> V_47 ) ;
V_3 -> V_11 = V_46 ;
BREAK ;
case V_46 :
case V_52 :
V_6 = F_23 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_53 ;
BREAK ;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
if ( ! ( V_3 -> V_57 & V_58 ) ||
( ( V_3 -> V_59 -> V_60 != NULL ) &&
( V_3 -> V_57 & V_61 ) ) ) {
V_3 -> V_11 = V_62 ;
break;
} else {
V_6 = F_24 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_62 ;
}
BREAK ;
case V_62 :
case V_63 :
V_6 = F_25 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_25;
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_20 ;
break;
case V_20 :
F_14 ( V_3 -> V_24 ) ;
F_26 ( V_3 ) ;
V_3 -> V_24 = NULL ;
V_3 -> V_27 = 0 ;
F_27 ( V_3 , V_64 ) ;
V_3 -> V_13 -> V_28 . V_65 ++ ;
V_6 = 1 ;
if ( F_4 != NULL )
F_4 ( V_3 , V_66 , 1 ) ;
goto V_25;
default:
F_11 ( V_16 , V_67 ) ;
V_6 = - 1 ;
goto V_25;
}
if ( ( F_4 != NULL ) && ( V_3 -> V_11 != V_11 ) ) {
V_10 = V_3 -> V_11 ;
V_3 -> V_11 = V_11 ;
F_4 ( V_3 , V_68 , 1 ) ;
V_3 -> V_11 = V_10 ;
}
}
V_25:
V_3 -> V_14 -- ;
if ( F_4 != NULL )
F_4 ( V_3 , V_69 , V_6 ) ;
return ( V_6 ) ;
}
static int F_17 ( T_2 * V_3 )
{
int V_70 , V_71 , V_72 , V_73 , V_74 ;
unsigned long V_75 ;
unsigned char * V_76 ;
const T_4 * V_77 ;
const T_5 * V_78 ;
const T_6 * V_79 ;
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
if ( V_3 -> V_11 == V_38 ) {
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , 10 - V_3 -> V_27 ) ;
if ( V_71 < ( 10 - V_3 -> V_27 ) )
return ( F_29 ( V_3 , V_81 , V_71 ) ) ;
V_3 -> V_27 = 10 ;
if ( * ( V_76 ++ ) != V_82 ) {
if ( V_76 [ - 1 ] != V_83 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 ,
V_85 ) ;
} else
F_11 ( V_81 , V_86 ) ;
return ( - 1 ) ;
}
V_77 = F_31 ( V_76 ) ;
if ( V_77 == NULL ) {
F_30 ( V_3 , V_87 ) ;
F_11 ( V_81 , V_88 ) ;
return ( - 1 ) ;
}
V_3 -> V_59 -> V_89 = V_77 ;
V_76 += 3 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_91 = V_71 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_92 = V_71 ;
F_32 ( V_76 , V_71 ) ;
if ( V_71 > V_93 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 , V_94 ) ;
return - 1 ;
}
V_3 -> V_59 -> V_95 = V_71 ;
V_3 -> V_11 = V_40 ;
}
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
if ( V_3 -> V_24 -> V_96 < V_26 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 , V_97 ) ;
return - 1 ;
}
V_73 = V_3 -> V_59 -> V_95 ;
V_75 =
10 + ( unsigned long ) V_3 -> V_41 -> V_90 . V_91 + ( unsigned long ) V_3 -> V_41 -> V_90 . V_92 +
( unsigned long ) V_73 ;
if ( V_75 > V_26 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 , V_98 ) ;
return - 1 ;
}
V_72 = ( int ) V_75 - V_3 -> V_27 ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , V_72 ) ;
if ( V_71 != V_72 )
return ( F_29 ( V_3 , V_81 , V_71 ) ) ;
if ( V_3 -> V_99 ) {
V_3 -> V_99 ( 0 , V_3 -> V_23 , 0 , V_76 , ( V_100 ) V_75 , V_3 ,
V_3 -> V_101 ) ;
}
V_76 += 10 ;
memcpy ( V_3 -> V_59 -> V_102 , & ( V_76 [ V_3 -> V_41 -> V_90 . V_91 + V_3 -> V_41 -> V_90 . V_92 ] ) ,
( unsigned int ) V_73 ) ;
if ( V_3 -> V_15 -> V_103 [ V_104 ] . V_105 == NULL ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 , V_106 ) ;
return ( - 1 ) ;
}
V_71 = F_33 ( V_3 -> V_15 , V_3 -> V_41 -> V_90 . V_92 ,
& ( V_76 [ V_3 -> V_41 -> V_90 . V_91 ] ) ,
& ( V_76 [ V_3 -> V_41 -> V_90 . V_91 ] ) ,
( V_3 -> V_41 -> V_107 ) ? V_108 :
V_109 ) ;
V_70 = F_34 ( V_3 -> V_59 -> V_89 ) ;
if ( ! F_35 ( V_3 -> V_59 , & V_78 , & V_79 , NULL , NULL , NULL ) ) {
F_30 ( V_3 , V_87 ) ;
F_11 ( V_81 ,
V_110 ) ;
return ( 0 ) ;
}
if ( V_3 -> V_59 -> V_89 -> V_111 & V_112 ) {
V_70 = 1 ;
V_74 = 8 ;
} else
V_74 = 5 ;
# if 1
if ( ( V_71 < 0 ) || ( ( ! V_70 && ( V_71 != F_36 ( V_78 ) ) )
|| ( V_70 && ( ( V_71 != V_74 )
|| ( V_3 -> V_41 -> V_90 . V_91 +
( unsigned int ) V_71 != ( unsigned int )
F_36 ( V_78 ) ) ) ) ) ) {
F_6 () ;
if ( V_70 )
V_71 = V_74 ;
else
V_71 = F_36 ( V_78 ) ;
if ( F_37 ( V_76 , V_71 ) <= 0 )
return 0 ;
}
# else
if ( V_71 < 0 ) {
error = 1 ;
F_11 ( V_81 , V_113 ) ;
}
else if ( ( ! V_70 && ( V_71 != F_36 ( V_78 ) ) )
|| ( V_70 && ( ( V_71 != V_74 ) || ( V_3 -> V_41 -> V_90 . V_91 + V_71 !=
F_36 ( V_78 ) ) ) ) ) {
error = 1 ;
F_11 ( V_81 , V_114 ) ;
}
if ( error ) {
F_30 ( V_3 , V_84 ) ;
return ( - 1 ) ;
}
# endif
if ( V_70 )
V_71 += V_3 -> V_41 -> V_90 . V_91 ;
if ( V_71 > V_115 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_81 , V_97 ) ;
return - 1 ;
}
V_3 -> V_59 -> V_116 = V_71 ;
memcpy ( V_3 -> V_59 -> V_117 , V_76 , ( unsigned int ) V_71 ) ;
return ( 1 ) ;
}
static int F_15 ( T_2 * V_3 )
{
int V_71 , V_72 ;
unsigned long V_75 ;
unsigned char * V_76 ;
F_38 ( T_4 ) * V_118 ;
F_38 ( T_4 ) * V_119 ;
F_38 ( T_4 ) * V_120 , * V_121 ;
int V_122 ;
if ( V_3 -> V_11 == V_31 ) {
V_3 -> V_123 = 1 ;
V_3 -> V_11 = V_32 ;
}
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
if ( V_3 -> V_11 == V_32 ) {
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , 9 - V_3 -> V_27 ) ;
if ( V_71 < ( 9 - V_3 -> V_27 ) )
return ( F_29 ( V_3 , V_124 , V_71 ) ) ;
V_3 -> V_27 = 9 ;
if ( * ( V_76 ++ ) != V_125 ) {
if ( V_76 [ - 1 ] != V_83 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_124 , V_85 ) ;
} else
F_11 ( V_124 , V_86 ) ;
return ( - 1 ) ;
}
F_32 ( V_76 , V_71 ) ;
if ( V_71 < V_3 -> V_23 )
V_3 -> V_23 = V_71 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_126 = V_71 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_127 = V_71 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_128 = V_71 ;
if ( ( V_71 < V_129 ) ||
( V_71 > V_130 ) ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_124 , V_131 ) ;
return ( - 1 ) ;
}
V_3 -> V_11 = V_33 ;
}
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
V_75 =
9 + ( unsigned long ) V_3 -> V_41 -> V_90 . V_126 +
( unsigned long ) V_3 -> V_41 -> V_128 +
( unsigned long ) V_3 -> V_41 -> V_90 . V_127 ;
if ( V_75 > V_26 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_124 , V_98 ) ;
return - 1 ;
}
V_72 = ( int ) V_75 - V_3 -> V_27 ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , V_72 ) ;
if ( V_71 != V_72 )
return ( F_29 ( V_3 , V_124 , V_71 ) ) ;
if ( V_3 -> V_99 ) {
V_3 -> V_99 ( 0 , V_3 -> V_23 , 0 , V_76 , ( V_100 ) V_75 , V_3 ,
V_3 -> V_101 ) ;
}
V_76 += 9 ;
if ( ( V_3 -> V_41 -> V_90 . V_127 != 0 ) &&
( V_3 -> V_41 -> V_90 . V_127 != V_132 ) ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_124 , V_133 ) ;
return ( - 1 ) ;
}
if ( V_3 -> V_41 -> V_90 . V_127 == 0 ) {
if ( ! F_39 ( V_3 , 1 ) ) {
F_30 ( V_3 , V_84 ) ;
return ( - 1 ) ;
}
} else {
V_71 = F_40 ( V_3 , & ( V_76 [ V_3 -> V_41 -> V_90 . V_126 ] ) ,
V_3 -> V_41 -> V_90 . V_127 , NULL ) ;
if ( V_71 == 1 ) {
V_3 -> V_37 = 1 ;
} else if ( V_71 == - 1 ) {
F_30 ( V_3 , V_84 ) ;
return ( - 1 ) ;
} else {
if ( V_3 -> V_15 == NULL ) {
F_30 ( V_3 , V_134 ) ;
F_11 ( V_124 , V_17 ) ;
return ( - 1 ) ;
}
if ( ! F_39 ( V_3 , 1 ) ) {
F_30 ( V_3 , V_84 ) ;
return ( - 1 ) ;
}
}
}
if ( ! V_3 -> V_37 ) {
V_118 = F_41 ( V_3 , V_76 , V_3 -> V_41 -> V_90 . V_126 ,
& V_3 -> V_59 -> V_135 ) ;
if ( V_118 == NULL )
goto V_136;
V_119 = F_42 ( V_3 ) ;
if ( V_3 -> V_137 & V_138 ) {
V_120 = F_43 ( V_119 ) ;
if ( V_120 == NULL )
goto V_136;
V_121 = V_118 ;
} else {
V_120 = V_118 ;
V_121 = V_119 ;
}
for ( V_122 = 0 ; V_122 < F_44 ( V_120 ) ; V_122 ++ ) {
if ( F_45 ( V_121 , F_46 ( V_120 , V_122 ) ) < 0 ) {
( void ) F_47 ( V_120 , V_122 ) ;
V_122 -- ;
}
}
if ( V_3 -> V_137 & V_138 ) {
F_48 ( V_3 -> V_59 -> V_135 ) ;
V_3 -> V_59 -> V_135 = V_120 ;
}
}
V_76 += V_3 -> V_41 -> V_90 . V_126 ;
V_76 += V_3 -> V_41 -> V_90 . V_127 ;
if ( V_3 -> V_41 -> V_128 > sizeof V_3 -> V_41 -> V_139 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_124 , V_97 ) ;
return - 1 ;
}
memcpy ( V_3 -> V_41 -> V_139 , V_76 , ( unsigned int ) V_3 -> V_41 -> V_128 ) ;
return ( 1 ) ;
V_136:
F_11 ( V_124 , V_140 ) ;
return ( 0 ) ;
}
static int F_16 ( T_2 * V_3 )
{
unsigned char * V_76 , * V_141 ;
int V_72 , V_37 ;
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
if ( V_3 -> V_11 == V_35 ) {
V_141 = V_76 + 11 ;
* ( V_76 ++ ) = V_142 ;
V_37 = V_3 -> V_37 ;
* ( V_76 ++ ) = ( unsigned char ) V_37 ;
# if 1
if ( ! V_37 ) {
if ( V_3 -> V_59 -> V_143 != NULL )
F_49 ( V_3 -> V_59 -> V_143 ) ;
V_3 -> V_59 -> V_143 = F_50 () ;
if ( V_3 -> V_59 -> V_143 == NULL ) {
F_11 ( V_144 , V_140 ) ;
return ( - 1 ) ;
}
}
# else
if ( ! V_37 ) {
F_51 ( & V_3 -> V_15 -> V_145 , 1 , V_146 ) ;
if ( V_3 -> V_59 -> V_143 != NULL )
F_52 ( V_3 -> V_59 -> V_143 ) ;
V_3 -> V_59 -> V_143 = V_3 -> V_15 ;
} else {
if ( V_3 -> V_59 -> V_143 == NULL ) {
F_51 ( & V_3 -> V_15 -> V_145 , 1 , V_146 ) ;
V_3 -> V_59 -> V_143 = V_3 -> V_15 ;
}
}
# endif
if ( V_3 -> V_15 == NULL ) {
F_30 ( V_3 , V_134 ) ;
F_11 ( V_144 , V_147 ) ;
return ( - 1 ) ;
}
if ( V_37 ) {
* ( V_76 ++ ) = 0 ;
F_53 ( V_3 -> V_23 , V_76 ) ;
F_53 ( 0 , V_76 ) ;
F_53 ( 0 , V_76 ) ;
} else {
* ( V_76 ++ ) = V_148 ;
F_53 ( V_3 -> V_23 , V_76 ) ;
V_72 = F_54 ( V_3 -> V_15 -> V_103 [ V_104 ] . V_149 , NULL ) ;
F_53 ( V_72 , V_76 ) ;
F_54 ( V_3 -> V_15 -> V_103 [ V_104 ] . V_149 , & V_141 ) ;
V_72 = 0 ;
V_72 = F_55 ( V_3 , V_3 -> V_59 -> V_135 , V_141 , 0 ) ;
V_141 += V_72 ;
F_53 ( V_72 , V_76 ) ;
}
F_53 ( V_150 , V_76 ) ;
V_3 -> V_41 -> V_151 = V_150 ;
if ( F_37 ( V_3 -> V_41 -> V_152 , ( int ) V_3 -> V_41 -> V_151 ) <=
0 )
return - 1 ;
memcpy ( V_141 , V_3 -> V_41 -> V_152 , V_150 ) ;
V_141 += V_150 ;
V_3 -> V_11 = V_36 ;
V_3 -> V_27 = V_141 - ( unsigned char * ) V_3 -> V_24 -> V_80 ;
V_3 -> V_153 = 0 ;
}
if ( V_3 -> V_37 ) {
if ( ! F_56 ( V_3 , 1 ) )
return ( - 1 ) ;
}
return ( F_57 ( V_3 ) ) ;
}
static int F_23 ( T_2 * V_3 )
{
unsigned char * V_76 ;
int V_71 , V_72 ;
unsigned long V_75 ;
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
if ( V_3 -> V_11 == V_46 ) {
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , 1 - V_3 -> V_27 ) ;
if ( V_71 < 1 - V_3 -> V_27 )
return ( F_29 ( V_3 , V_154 , V_71 ) ) ;
V_3 -> V_27 += V_71 ;
if ( * V_76 != V_155 ) {
if ( * V_76 != V_83 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_154 ,
V_85 ) ;
} else {
F_11 ( V_154 , V_86 ) ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , 3 - V_3 -> V_27 ) ;
return F_29 ( V_3 , V_156 , V_71 ) ;
}
return ( - 1 ) ;
}
V_3 -> V_11 = V_52 ;
}
if ( V_3 -> V_41 -> V_151 > sizeof V_3 -> V_41 -> V_152 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_154 , V_97 ) ;
return - 1 ;
}
V_75 = 1 + ( unsigned long ) V_3 -> V_41 -> V_151 ;
V_72 = ( int ) V_75 - V_3 -> V_27 ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , V_72 ) ;
if ( V_71 < V_72 ) {
return ( F_29 ( V_3 , V_154 , V_71 ) ) ;
}
if ( V_3 -> V_99 ) {
V_3 -> V_99 ( 0 , V_3 -> V_23 , 0 , V_76 , V_75 , V_3 , V_3 -> V_101 ) ;
}
V_76 += 1 ;
if ( memcmp ( V_76 , V_3 -> V_41 -> V_152 , V_3 -> V_41 -> V_151 ) != 0 ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_154 , V_157 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_19 ( T_2 * V_3 )
{
unsigned char * V_76 ;
if ( V_3 -> V_11 == V_43 ) {
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
* ( V_76 ++ ) = V_158 ;
if ( V_3 -> V_41 -> V_128 > sizeof V_3 -> V_41 -> V_139 ) {
F_11 ( V_159 , V_97 ) ;
return - 1 ;
}
memcpy ( V_76 , V_3 -> V_41 -> V_139 , ( unsigned int ) V_3 -> V_41 -> V_128 ) ;
V_3 -> V_11 = V_44 ;
V_3 -> V_27 = V_3 -> V_41 -> V_128 + 1 ;
V_3 -> V_153 = 0 ;
}
return ( F_57 ( V_3 ) ) ;
}
static int F_25 ( T_2 * V_3 )
{
unsigned char * V_76 ;
if ( V_3 -> V_11 == V_62 ) {
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
* ( V_76 ++ ) = V_160 ;
if ( V_3 -> V_59 -> V_127 > sizeof V_3 -> V_59 -> V_161 ) {
F_11 ( V_162 , V_97 ) ;
return - 1 ;
}
memcpy ( V_76 , V_3 -> V_59 -> V_161 ,
( unsigned int ) V_3 -> V_59 -> V_127 ) ;
V_3 -> V_11 = V_63 ;
V_3 -> V_27 = V_3 -> V_59 -> V_127 + 1 ;
V_3 -> V_153 = 0 ;
}
return ( F_57 ( V_3 ) ) ;
}
static int F_24 ( T_2 * V_3 )
{
const unsigned char * V_77 ;
unsigned char * V_76 , * V_163 , * V_164 ;
unsigned char * V_165 ;
int V_71 , V_166 , V_167 , V_6 = - 1 ;
unsigned long V_75 ;
T_7 * V_149 = NULL ;
F_38 ( T_7 ) * V_168 = NULL ;
V_165 = V_3 -> V_41 -> V_90 . V_169 ;
if ( V_3 -> V_11 == V_53 ) {
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
* ( V_76 ++ ) = V_170 ;
* ( V_76 ++ ) = V_171 ;
if ( F_37 ( V_165 , V_172 ) <= 0 )
return - 1 ;
memcpy ( V_76 , V_165 , V_172 ) ;
V_3 -> V_11 = V_54 ;
V_3 -> V_27 = V_172 + 2 ;
V_3 -> V_153 = 0 ;
}
if ( V_3 -> V_11 == V_54 ) {
V_71 = F_57 ( V_3 ) ;
if ( V_71 <= 0 ) {
V_6 = V_71 ;
goto V_25;
}
V_3 -> V_27 = 0 ;
V_3 -> V_11 = V_55 ;
}
if ( V_3 -> V_11 == V_55 ) {
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , 6 - V_3 -> V_27 ) ;
if ( V_71 < 3 - V_3 -> V_27 ) {
V_6 = F_29 ( V_3 , V_173 , V_71 ) ;
goto V_25;
}
V_3 -> V_27 += V_71 ;
if ( ( V_3 -> V_27 >= 3 ) && ( V_76 [ 0 ] == V_83 ) ) {
F_32 ( V_76 , V_71 ) ;
if ( V_71 != V_134 ) {
V_3 -> V_27 -= 3 ;
V_6 = F_29 ( V_3 , V_173 , 3 ) ;
goto V_25;
}
if ( V_3 -> V_99 ) {
V_3 -> V_99 ( 0 , V_3 -> V_23 , 0 , V_76 , 3 , V_3 ,
V_3 -> V_101 ) ;
}
if ( V_3 -> V_57 & V_174 ) {
F_30 ( V_3 , V_175 ) ;
F_11 ( V_173 ,
V_176 ) ;
goto V_25;
}
V_6 = 1 ;
goto V_25;
}
if ( ( * ( V_76 ++ ) != V_177 ) || ( V_3 -> V_27 < 6 ) ) {
F_30 ( V_3 , V_84 ) ;
F_11 ( V_173 , V_178 ) ;
goto V_25;
}
if ( V_3 -> V_27 != 6 ) {
F_11 ( V_173 , V_97 ) ;
goto V_25;
}
V_167 = * ( V_76 ++ ) ;
if ( V_167 != V_171 ) {
F_30 ( V_3 , V_179 ) ;
F_11 ( V_173 , V_180 ) ;
goto V_25;
}
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_181 = V_71 ;
F_32 ( V_76 , V_71 ) ;
V_3 -> V_41 -> V_90 . V_182 = V_71 ;
V_3 -> V_11 = V_56 ;
}
V_76 = ( unsigned char * ) V_3 -> V_24 -> V_80 ;
V_75 = 6 + ( unsigned long ) V_3 -> V_41 -> V_90 . V_181 + ( unsigned long ) V_3 -> V_41 -> V_90 . V_182 ;
if ( V_75 > V_26 ) {
F_11 ( V_173 , V_98 ) ;
goto V_25;
}
V_166 = ( int ) V_75 - V_3 -> V_27 ;
V_71 = F_28 ( V_3 , ( char * ) & ( V_76 [ V_3 -> V_27 ] ) , V_166 ) ;
if ( V_71 < V_166 ) {
V_6 = F_29 ( V_3 , V_173 , V_71 ) ;
goto V_25;
}
if ( V_3 -> V_99 ) {
V_3 -> V_99 ( 0 , V_3 -> V_23 , 0 , V_76 , V_75 , V_3 , V_3 -> V_101 ) ;
}
V_76 += 6 ;
V_77 = V_76 ;
V_149 = ( T_7 * ) F_58 ( NULL , & V_77 , ( long ) V_3 -> V_41 -> V_90 . V_181 ) ;
if ( V_149 == NULL ) {
F_11 ( V_173 , V_183 ) ;
goto V_184;
}
if ( ( ( V_168 = F_59 () ) == NULL ) || ( ! F_60 ( V_168 , V_149 ) ) ) {
F_11 ( V_173 , V_140 ) ;
goto V_184;
}
V_71 = F_61 ( V_3 , V_168 ) ;
if ( V_71 > 0 ) {
T_8 V_13 ;
T_9 * V_185 = NULL ;
F_62 ( & V_13 ) ;
if ( ! F_63 ( & V_13 , V_3 -> V_13 -> V_186 , NULL )
|| ! F_64 ( & V_13 , V_3 -> V_41 -> V_187 ,
V_3 -> V_41 -> V_188 )
|| ! F_64 ( & V_13 , V_165 , V_172 ) )
goto V_184;
V_71 = F_54 ( V_3 -> V_15 -> V_103 [ V_104 ] . V_149 , NULL ) ;
V_164 = F_65 ( ( unsigned int ) V_71 ) ;
if ( V_164 == NULL ) {
F_11 ( V_173 , V_140 ) ;
goto V_184;
}
V_163 = V_164 ;
V_71 = F_54 ( V_3 -> V_15 -> V_103 [ V_104 ] . V_149 , & V_163 ) ;
if ( ! F_64 ( & V_13 , V_164 , ( unsigned int ) V_71 ) ) {
F_66 ( V_164 ) ;
goto V_184;
}
F_66 ( V_164 ) ;
V_185 = F_67 ( V_149 ) ;
if ( V_185 == NULL )
goto V_25;
V_71 = F_68 ( & V_13 , V_77 , V_3 -> V_41 -> V_90 . V_182 , V_185 ) ;
F_69 ( V_185 ) ;
F_70 ( & V_13 ) ;
if ( V_71 > 0 ) {
if ( V_3 -> V_59 -> V_60 != NULL )
F_71 ( V_3 -> V_59 -> V_60 ) ;
V_3 -> V_59 -> V_60 = V_149 ;
F_51 ( & V_149 -> V_145 , 1 , V_189 ) ;
V_3 -> V_59 -> V_190 = V_3 -> V_190 ;
V_6 = 1 ;
goto V_25;
} else {
F_11 ( V_173 , V_191 ) ;
goto V_184;
}
} else {
V_184:
F_30 ( V_3 , V_175 ) ;
}
V_25:
F_72 ( V_168 ) ;
F_71 ( V_149 ) ;
return ( V_6 ) ;
}
static int F_33 ( T_10 * V_78 , int V_75 , unsigned char * V_192 ,
unsigned char * V_193 , int V_194 )
{
T_11 * V_195 ;
int V_71 ;
if ( ( V_78 == NULL ) || ( V_78 -> V_103 [ V_104 ] . V_105 == NULL ) ) {
F_11 ( V_196 , V_106 ) ;
return ( - 1 ) ;
}
if ( V_78 -> V_103 [ V_104 ] . V_105 -> type != V_197 ) {
F_11 ( V_196 , V_198 ) ;
return ( - 1 ) ;
}
V_195 = V_78 -> V_103 [ V_104 ] . V_105 -> V_185 . V_195 ;
V_71 = F_73 ( V_75 , V_192 , V_193 , V_195 , V_194 ) ;
if ( V_71 < 0 )
F_11 ( V_196 , V_199 ) ;
return ( V_71 ) ;
}
