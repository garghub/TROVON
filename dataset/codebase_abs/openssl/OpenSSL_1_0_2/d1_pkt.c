static int F_1 ( const unsigned char * V_1 , const unsigned char * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
if ( sizeof( long ) == 8 )
do {
const union {
long V_7 ;
char V_8 ;
} V_9 = {
1
} ;
long V_10 ;
if ( V_9 . V_8 )
break;
if ( ( ( V_11 ) V_1 | ( V_11 ) V_2 ) & 0x7 )
break;
V_10 = * ( ( long * ) V_1 ) ;
V_10 -= * ( ( long * ) V_2 ) ;
if ( V_10 > 128 )
return 128 ;
else if ( V_10 < - 128 )
return - 128 ;
else
return ( int ) V_10 ;
} while ( 0 );
V_3 = ( int ) V_1 [ 7 ] - ( int ) V_2 [ 7 ] ;
V_4 = 0 ;
V_5 = V_3 >> 8 ;
if ( V_3 & 0x80 ) {
for ( V_6 = 6 ; V_6 >= 0 ; V_6 -- ) {
V_5 += ( int ) V_1 [ V_6 ] - ( int ) V_2 [ V_6 ] ;
V_4 |= ~ V_5 ;
V_5 >>= 8 ;
}
} else {
for ( V_6 = 6 ; V_6 >= 0 ; V_6 -- ) {
V_5 += ( int ) V_1 [ V_6 ] - ( int ) V_2 [ V_6 ] ;
V_4 |= V_5 ;
V_5 >>= 8 ;
}
}
V_5 <<= 8 ;
if ( V_4 & 0xff )
return V_5 | 0x80 ;
else
return V_5 + ( V_3 & 0xFF ) ;
}
static int F_2 ( T_1 * V_12 , T_2 * V_13 )
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
if ( V_14 == NULL || V_13 == NULL ) {
if ( V_14 != NULL )
F_3 ( V_14 ) ;
if ( V_13 != NULL )
F_8 ( V_13 ) ;
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
( V_12 -> V_30 == V_31
|| V_12 -> V_30 == V_32 ) ) {
F_13 ( F_12 ( V_12 ) , V_33 ,
sizeof( V_14 -> V_34 ) , & V_14 -> V_34 ) ;
}
#endif
V_12 -> V_19 = NULL ;
V_12 -> V_20 = 0 ;
memset ( & ( V_12 -> V_16 -> V_17 ) , 0 , sizeof( V_21 ) ) ;
memset ( & ( V_12 -> V_16 -> V_22 ) , 0 , sizeof( V_23 ) ) ;
if ( ! F_14 ( V_12 ) ) {
F_9 ( V_28 , V_29 ) ;
if ( V_14 -> V_17 . V_18 != NULL )
F_3 ( V_14 -> V_17 . V_18 ) ;
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( - 1 ) ;
}
if ( F_15 ( V_25 -> V_27 , V_13 ) == NULL ) {
F_9 ( V_28 , V_29 ) ;
if ( V_14 -> V_17 . V_18 != NULL )
F_3 ( V_14 -> V_17 . V_18 ) ;
F_3 ( V_14 ) ;
F_8 ( V_13 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_16 ( T_1 * V_12 , T_4 * V_25 )
{
T_2 * V_13 ;
V_13 = F_17 ( V_25 -> V_27 ) ;
if ( V_13 ) {
F_2 ( V_12 , V_13 ) ;
F_3 ( V_13 -> V_15 ) ;
F_8 ( V_13 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static int F_18 ( T_1 * V_12 )
{
T_2 * V_13 ;
V_13 = F_19 ( V_12 -> V_35 -> V_36 . V_27 ) ;
if ( V_13 ) {
if ( V_12 -> V_35 -> V_36 . V_37 != V_12 -> V_35 -> V_38 )
return ( 1 ) ;
while ( F_19 ( V_12 -> V_35 -> V_36 . V_27 ) ) {
F_20 ( V_12 ) ;
if ( ! F_21 ( V_12 ) )
return ( 0 ) ;
if ( F_4 ( V_12 , & ( V_12 -> V_35 -> V_39 ) ,
V_12 -> V_16 -> V_22 . V_40 ) < 0 )
return - 1 ;
}
}
V_12 -> V_35 -> V_39 . V_37 = V_12 -> V_35 -> V_38 ;
V_12 -> V_35 -> V_36 . V_37 = V_12 -> V_35 -> V_38 + 1 ;
return ( 1 ) ;
}
static int F_21 ( T_1 * V_12 )
{
int V_6 , V_41 ;
int V_42 ;
T_5 * V_43 ;
V_23 * V_44 ;
unsigned int V_45 , V_46 ;
unsigned char V_47 [ V_48 ] ;
V_44 = & ( V_12 -> V_16 -> V_22 ) ;
V_43 = V_12 -> V_49 ;
V_44 -> V_50 = & ( V_12 -> V_19 [ V_51 ] ) ;
if ( V_44 -> V_52 > V_53 ) {
V_41 = V_54 ;
F_9 ( V_55 , V_56 ) ;
goto V_57;
}
V_44 -> V_15 = V_44 -> V_50 ;
V_42 = V_12 -> V_58 -> V_59 -> V_60 ( V_12 , 0 ) ;
if ( V_42 == 0 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_61;
}
#ifdef F_22
printf ( L_1 , V_44 -> V_52 ) ;
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_44 -> V_52 ; V_62 ++ )
printf ( L_2 , V_44 -> V_15 [ V_62 ] , ( ( V_62 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_3 ) ;
#endif
if ( ( V_43 != NULL ) &&
( V_12 -> V_63 != NULL ) && ( F_23 ( V_12 -> V_64 ) != NULL ) ) {
unsigned char * V_65 = NULL ;
unsigned char V_66 [ V_48 ] ;
V_45 = F_24 ( V_12 -> V_64 ) ;
F_25 ( V_45 <= V_48 ) ;
V_46 = V_44 -> V_52 + ( ( unsigned int ) V_44 -> type >> 8 ) ;
if ( V_46 < V_45 ||
( F_26 ( V_12 -> V_63 ) == V_67 &&
V_46 < V_45 + 1 ) ) {
V_41 = V_68 ;
F_9 ( V_55 , V_69 ) ;
goto V_57;
}
if ( F_26 ( V_12 -> V_63 ) == V_67 ) {
V_65 = V_66 ;
F_27 ( V_66 , V_44 , V_45 , V_46 ) ;
V_44 -> V_52 -= V_45 ;
} else {
V_44 -> V_52 -= V_45 ;
V_65 = & V_44 -> V_15 [ V_44 -> V_52 ] ;
}
V_6 = V_12 -> V_58 -> V_59 -> V_65 ( V_12 , V_47 , 0 ) ;
if ( V_6 < 0 || V_65 == NULL
|| F_28 ( V_47 , V_65 , ( V_11 ) V_45 ) != 0 )
V_42 = - 1 ;
if ( V_44 -> V_52 > V_70 + V_45 )
V_42 = - 1 ;
}
if ( V_42 < 0 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_61;
}
if ( V_12 -> V_71 != NULL ) {
if ( V_44 -> V_52 > V_70 ) {
V_41 = V_54 ;
F_9 ( V_55 ,
V_72 ) ;
goto V_57;
}
if ( ! F_29 ( V_12 ) ) {
V_41 = V_73 ;
F_9 ( V_55 , V_74 ) ;
goto V_57;
}
}
if ( V_44 -> V_52 > V_75 ) {
V_41 = V_54 ;
F_9 ( V_55 , V_76 ) ;
goto V_57;
}
V_44 -> V_77 = 0 ;
V_12 -> V_20 = 0 ;
return ( 1 ) ;
V_57:
F_30 ( V_12 , V_78 , V_41 ) ;
V_61:
return ( 0 ) ;
}
int F_31 ( T_1 * V_12 )
{
int V_79 , V_80 ;
int V_6 , V_81 ;
V_23 * V_44 ;
unsigned char * V_82 = NULL ;
unsigned short V_83 ;
T_6 * V_84 ;
unsigned int V_85 ;
V_44 = & ( V_12 -> V_16 -> V_22 ) ;
if ( F_18 ( V_12 ) < 0 )
return - 1 ;
if ( F_32 ( V_12 ) )
return 1 ;
V_86:
if ( ( V_12 -> V_87 != V_88 ) ||
( V_12 -> V_20 < V_51 ) ) {
V_81 = F_33 ( V_12 , V_51 , V_12 -> V_16 -> V_17 . V_89 , 0 ) ;
if ( V_81 <= 0 )
return ( V_81 ) ;
if ( V_12 -> V_20 != V_51 ) {
V_12 -> V_20 = 0 ;
goto V_86;
}
V_12 -> V_87 = V_88 ;
V_82 = V_12 -> V_19 ;
if ( V_12 -> V_90 )
V_12 -> V_90 ( 0 , 0 , V_91 , V_82 , V_51 ,
V_12 , V_12 -> V_92 ) ;
V_44 -> type = * ( V_82 ++ ) ;
V_79 = * ( V_82 ++ ) ;
V_80 = * ( V_82 ++ ) ;
V_83 = ( V_79 << 8 ) | V_80 ;
F_34 ( V_82 , V_44 -> V_37 ) ;
memcpy ( & ( V_12 -> V_16 -> V_24 [ 2 ] ) , V_82 , 6 ) ;
V_82 += 6 ;
F_34 ( V_82 , V_44 -> V_52 ) ;
if ( ! V_12 -> V_93 ) {
if ( V_83 != V_12 -> V_83 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
}
if ( ( V_83 & 0xff00 ) != ( V_12 -> V_83 & 0xff00 ) ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
if ( V_44 -> V_52 > V_53 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
}
if ( V_44 -> V_52 > V_12 -> V_20 - V_51 ) {
V_6 = V_44 -> V_52 ;
V_81 = F_33 ( V_12 , V_6 , V_6 , 1 ) ;
if ( V_81 != V_6 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
}
V_12 -> V_87 = V_94 ;
V_84 = F_35 ( V_12 , V_44 , & V_85 ) ;
if ( V_84 == NULL ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
#ifndef F_10
if ( ! F_11 ( F_12 ( V_12 ) ) ) {
#endif
if ( ! ( V_12 -> V_35 -> V_95 && V_44 -> type == V_96 &&
V_12 -> V_20 > V_51 &&
V_12 -> V_19 [ V_51 ] == V_97 ) &&
! F_36 ( V_12 , V_84 ) ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
#ifndef F_10
}
#endif
if ( V_44 -> V_52 == 0 )
goto V_86;
if ( V_85 ) {
if ( ( F_37 ( V_12 ) || V_12 -> V_98 ) && ! V_12 -> V_35 -> V_95 ) {
if ( F_4
( V_12 , & ( V_12 -> V_35 -> V_36 ) , V_44 -> V_40 ) < 0 )
return - 1 ;
F_38 ( V_12 , V_84 ) ;
}
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
if ( ! F_21 ( V_12 ) ) {
V_44 -> V_52 = 0 ;
V_12 -> V_20 = 0 ;
goto V_86;
}
F_38 ( V_12 , V_84 ) ;
return ( 1 ) ;
}
int F_39 ( T_1 * V_12 , int type , unsigned char * V_18 , int V_89 , int V_99 )
{
int V_41 , V_6 , V_100 , V_3 ;
unsigned int V_81 ;
V_23 * V_44 ;
void (* F_40) ( const T_1 * V_101 , int V_102 , int V_103 ) = NULL ;
if ( V_12 -> V_16 -> V_17 . V_18 == NULL )
if ( ! F_14 ( V_12 ) )
return ( - 1 ) ;
if ( ( type && ( type != V_104 ) &&
( type != V_96 ) && type ) ||
( V_99 && ( type != V_104 ) ) ) {
F_9 ( V_105 , V_29 ) ;
return - 1 ;
}
if ( ( V_3 = F_41 ( V_12 , type , V_18 , V_89 , V_99 ) ) )
return V_3 ;
#ifndef F_10
if ( ( ! V_12 -> V_98 && F_37 ( V_12 ) ) ||
( F_11 ( F_12 ( V_12 ) ) &&
( V_12 -> V_30 == V_106
|| V_12 -> V_30 == V_107 )
&& V_12 -> V_16 -> V_108 != 2 ) )
#else
if ( ! V_12 -> V_98 && F_37 ( V_12 ) )
#endif
{
V_6 = V_12 -> V_109 ( V_12 ) ;
if ( V_6 < 0 )
return ( V_6 ) ;
if ( V_6 == 0 ) {
F_9 ( V_105 , V_110 ) ;
return ( - 1 ) ;
}
}
V_111:
V_12 -> V_112 = V_113 ;
V_44 = & ( V_12 -> V_16 -> V_22 ) ;
if ( V_12 -> V_30 == V_114 && V_44 -> V_52 == 0 ) {
T_2 * V_13 ;
V_13 = F_17 ( V_12 -> V_35 -> V_115 . V_27 ) ;
if ( V_13 ) {
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) ) {
T_3 * V_14 = ( T_3 * ) V_13 -> V_15 ;
F_13 ( F_12 ( V_12 ) , V_116 ,
sizeof( V_14 -> V_34 ) , & V_14 -> V_34 ) ;
}
#endif
F_2 ( V_12 , V_13 ) ;
F_3 ( V_13 -> V_15 ) ;
F_8 ( V_13 ) ;
}
}
if ( F_42 ( V_12 ) > 0 )
goto V_111;
if ( ( V_44 -> V_52 == 0 ) || ( V_12 -> V_87 == V_88 ) ) {
V_3 = F_31 ( V_12 ) ;
if ( V_3 <= 0 ) {
V_3 = F_43 ( V_12 , V_3 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
else
goto V_111;
}
}
if ( V_12 -> V_35 -> V_95 && V_44 -> type != V_96 ) {
V_44 -> V_52 = 0 ;
goto V_111;
}
if ( V_12 -> V_16 -> V_117
&& ( V_44 -> type != V_96 ) ) {
if ( F_4 ( V_12 , & ( V_12 -> V_35 -> V_115 ) , V_44 -> V_40 ) <
0 ) {
F_9 ( V_105 , V_29 ) ;
return - 1 ;
}
V_44 -> V_52 = 0 ;
goto V_111;
}
if ( V_12 -> V_118 & V_119 ) {
V_44 -> V_52 = 0 ;
V_12 -> V_112 = V_113 ;
return ( 0 ) ;
}
if ( type == V_44 -> type ) {
if ( F_37 ( V_12 ) && ( type == V_104 ) &&
( V_12 -> V_63 == NULL ) ) {
V_41 = V_120 ;
F_9 ( V_105 , V_121 ) ;
goto V_57;
}
if ( V_89 <= 0 )
return ( V_89 ) ;
if ( ( unsigned int ) V_89 > V_44 -> V_52 )
V_81 = V_44 -> V_52 ;
else
V_81 = ( unsigned int ) V_89 ;
memcpy ( V_18 , & ( V_44 -> V_15 [ V_44 -> V_77 ] ) , V_81 ) ;
if ( ! V_99 ) {
V_44 -> V_52 -= V_81 ;
V_44 -> V_77 += V_81 ;
if ( V_44 -> V_52 == 0 ) {
V_12 -> V_87 = V_94 ;
V_44 -> V_77 = 0 ;
}
}
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) &&
V_44 -> type == V_104 &&
( V_12 -> V_30 == V_106
|| V_12 -> V_30 == V_107 ) ) {
V_12 -> V_112 = V_122 ;
F_44 ( F_12 ( V_12 ) ) ;
F_45 ( F_12 ( V_12 ) ) ;
}
if ( F_11 ( F_12 ( V_12 ) ) &&
V_12 -> V_35 -> V_123
&& ! F_46 ( F_12 ( V_12 ) ) ) {
V_12 -> V_118 |= V_119 ;
return ( 0 ) ;
}
#endif
return ( V_81 ) ;
}
{
unsigned int V_124 , V_125 = 0 ;
unsigned char * V_126 = NULL ;
unsigned int * V_127 = NULL ;
if ( V_44 -> type == V_96 ) {
V_125 = sizeof V_12 -> V_35 -> V_128 ;
V_126 = V_12 -> V_35 -> V_128 ;
V_127 = & V_12 -> V_35 -> V_129 ;
} else if ( V_44 -> type == V_130 ) {
V_125 = sizeof( V_12 -> V_35 -> V_131 ) ;
V_126 = V_12 -> V_35 -> V_131 ;
V_127 = & V_12 -> V_35 -> V_132 ;
}
#ifndef F_47
else if ( V_44 -> type == V_133 ) {
F_48 ( V_12 ) ;
V_44 -> V_52 = 0 ;
V_12 -> V_112 = V_122 ;
F_44 ( F_12 ( V_12 ) ) ;
F_45 ( F_12 ( V_12 ) ) ;
return ( - 1 ) ;
}
#endif
else if ( V_44 -> type != V_134 ) {
if ( V_44 -> type == V_104 ) {
T_7 * V_135 ;
V_12 -> V_16 -> V_108 = 2 ;
V_135 = F_12 ( V_12 ) ;
V_12 -> V_112 = V_122 ;
F_44 ( V_135 ) ;
F_45 ( V_135 ) ;
return ( - 1 ) ;
}
V_41 = V_120 ;
F_9 ( V_105 , V_136 ) ;
goto V_57;
}
if ( V_125 > 0 ) {
if ( V_44 -> V_52 < V_125 ) {
#ifdef F_49
T_8 T_9
#endif
V_12 -> V_87 = V_94 ;
V_44 -> V_52 = 0 ;
goto V_111;
}
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ ) {
V_126 [ V_124 ] = V_44 -> V_15 [ V_44 -> V_77 ++ ] ;
V_44 -> V_52 -- ;
}
* V_127 = V_125 ;
}
}
if ( ( ! V_12 -> V_137 ) &&
( V_12 -> V_35 -> V_129 >= V_138 ) &&
( V_12 -> V_35 -> V_128 [ 0 ] == V_139 ) &&
( V_12 -> V_49 != NULL ) && ( V_12 -> V_49 -> V_140 != NULL ) ) {
V_12 -> V_35 -> V_129 = 0 ;
if ( ( V_12 -> V_35 -> V_128 [ 1 ] != 0 ) ||
( V_12 -> V_35 -> V_128 [ 2 ] != 0 ) ||
( V_12 -> V_35 -> V_128 [ 3 ] != 0 ) ) {
V_41 = V_68 ;
F_9 ( V_105 , V_141 ) ;
goto V_61;
}
if ( V_12 -> V_90 )
V_12 -> V_90 ( 0 , V_12 -> V_83 , V_96 ,
V_12 -> V_35 -> V_128 , 4 , V_12 ,
V_12 -> V_92 ) ;
if ( F_50 ( V_12 ) &&
! ( V_12 -> V_16 -> V_142 & V_143 ) &&
! V_12 -> V_16 -> V_144 ) {
V_12 -> V_35 -> V_145 ++ ;
V_12 -> V_146 = 1 ;
F_51 ( V_12 ) ;
if ( F_52 ( V_12 ) ) {
V_6 = V_12 -> V_109 ( V_12 ) ;
if ( V_6 < 0 )
return ( V_6 ) ;
if ( V_6 == 0 ) {
F_9 ( V_105 ,
V_110 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_147 & V_148 ) ) {
if ( V_12 -> V_16 -> V_17 . V_149 == 0 ) {
T_7 * V_135 ;
V_12 -> V_112 = V_122 ;
V_135 = F_12 ( V_12 ) ;
F_44 ( V_135 ) ;
F_45 ( V_135 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_111;
}
if ( V_12 -> V_35 -> V_132 >= V_150 ) {
int V_151 = V_12 -> V_35 -> V_131 [ 0 ] ;
int V_152 = V_12 -> V_35 -> V_131 [ 1 ] ;
V_12 -> V_35 -> V_132 = 0 ;
if ( V_12 -> V_90 )
V_12 -> V_90 ( 0 , V_12 -> V_83 , V_130 ,
V_12 -> V_35 -> V_131 , 2 , V_12 , V_12 -> V_92 ) ;
if ( V_12 -> V_153 != NULL )
F_40 = V_12 -> V_153 ;
else if ( V_12 -> V_154 -> V_153 != NULL )
F_40 = V_12 -> V_154 -> V_153 ;
if ( F_40 != NULL ) {
V_100 = ( V_151 << 8 ) | V_152 ;
F_40 ( V_12 , V_155 , V_100 ) ;
}
if ( V_151 == 1 ) {
V_12 -> V_16 -> V_156 = V_152 ;
if ( V_152 == V_157 ) {
#ifndef F_10
if ( F_11 ( F_12 ( V_12 ) ) &&
F_46 ( F_12 ( V_12 ) ) ) {
V_12 -> V_35 -> V_123 = 1 ;
V_12 -> V_112 = V_122 ;
F_44 ( F_12 ( V_12 ) ) ;
F_45 ( F_12 ( V_12 ) ) ;
return - 1 ;
}
#endif
V_12 -> V_118 |= V_119 ;
return ( 0 ) ;
}
#if 0
if (alert_descr == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE) {
unsigned short seq;
unsigned int frag_off;
unsigned char *p = &(s->d1->alert_fragment[2]);
n2s(p, seq);
n2l3(p, frag_off);
dtls1_retransmit_message(s,
dtls1_get_queue_priority
(frag->msg_header.seq, 0), frag_off,
&found);
if (!found && SSL_in_init(s)) {
ssl3_send_alert(s, SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
}
}
#endif
} else if ( V_151 == 2 ) {
char V_158 [ 16 ] ;
V_12 -> V_112 = V_113 ;
V_12 -> V_16 -> V_159 = V_152 ;
F_9 ( V_105 ,
V_160 + V_152 ) ;
F_53 ( V_158 , sizeof V_158 , L_4 , V_152 ) ;
F_54 ( 2 , L_5 , V_158 ) ;
V_12 -> V_118 |= V_119 ;
F_55 ( V_12 -> V_154 , V_12 -> V_49 ) ;
return ( 0 ) ;
} else {
V_41 = V_161 ;
F_9 ( V_105 , V_162 ) ;
goto V_57;
}
goto V_111;
}
if ( V_12 -> V_118 & V_163 ) {
V_12 -> V_112 = V_113 ;
V_44 -> V_52 = 0 ;
return ( 0 ) ;
}
if ( V_44 -> type == V_134 ) {
struct V_164 V_165 ;
unsigned int V_166 = V_167 ;
F_56 ( V_44 -> V_15 , & V_165 ) ;
if ( V_12 -> V_83 == V_168 )
V_166 = 3 ;
if ( ( V_44 -> V_52 != V_166 ) ||
( V_44 -> V_77 != 0 ) || ( V_44 -> V_15 [ 0 ] != V_169 ) ) {
V_6 = V_161 ;
F_9 ( V_105 , V_170 ) ;
goto V_61;
}
V_44 -> V_52 = 0 ;
if ( V_12 -> V_90 )
V_12 -> V_90 ( 0 , V_12 -> V_83 , V_134 ,
V_44 -> V_15 , 1 , V_12 , V_12 -> V_92 ) ;
if ( ! V_12 -> V_35 -> V_171 ) {
goto V_111;
}
V_12 -> V_35 -> V_171 = 0 ;
V_12 -> V_16 -> V_117 = 1 ;
if ( ! F_57 ( V_12 ) )
goto V_61;
F_58 ( V_12 , V_172 ) ;
if ( V_12 -> V_83 == V_168 )
V_12 -> V_35 -> V_145 ++ ;
#ifndef F_10
F_13 ( F_59 ( V_12 ) , V_173 , 1 , NULL ) ;
#endif
goto V_111;
}
if ( ( V_12 -> V_35 -> V_129 >= V_138 ) &&
! V_12 -> V_98 ) {
struct V_174 V_175 ;
F_60 ( V_44 -> V_15 , & V_175 ) ;
if ( V_44 -> V_37 != V_12 -> V_35 -> V_38 ) {
V_44 -> V_52 = 0 ;
goto V_111;
}
if ( V_175 . type == V_176 ) {
if ( F_61 ( V_12 ) < 0 )
return - 1 ;
F_62 ( V_12 ) ;
V_44 -> V_52 = 0 ;
goto V_111;
}
if ( ( ( V_12 -> V_30 & V_177 ) == V_114 ) &&
! ( V_12 -> V_16 -> V_142 & V_143 ) ) {
#if 0
s->state = SSL_ST_BEFORE | (s->server)
? SSL_ST_ACCEPT : SSL_ST_CONNECT;
#else
V_12 -> V_30 = V_12 -> V_137 ? V_178 : V_179 ;
#endif
V_12 -> V_144 = 1 ;
V_12 -> V_146 = 1 ;
}
V_6 = V_12 -> V_109 ( V_12 ) ;
if ( V_6 < 0 )
return ( V_6 ) ;
if ( V_6 == 0 ) {
F_9 ( V_105 , V_110 ) ;
return ( - 1 ) ;
}
if ( ! ( V_12 -> V_147 & V_148 ) ) {
if ( V_12 -> V_16 -> V_17 . V_149 == 0 ) {
T_7 * V_135 ;
V_12 -> V_112 = V_122 ;
V_135 = F_12 ( V_12 ) ;
F_44 ( V_135 ) ;
F_45 ( V_135 ) ;
return ( - 1 ) ;
}
}
goto V_111;
}
switch ( V_44 -> type ) {
default:
#ifndef F_63
if ( V_12 -> V_83 == V_180 ) {
V_44 -> V_52 = 0 ;
goto V_111;
}
#endif
V_41 = V_120 ;
F_9 ( V_105 , V_136 ) ;
goto V_57;
case V_134 :
case V_130 :
case V_96 :
V_41 = V_120 ;
F_9 ( V_105 , V_29 ) ;
goto V_57;
case V_104 :
if ( V_12 -> V_16 -> V_108 &&
( V_12 -> V_16 -> V_181 != 0 ) &&
( ( ( V_12 -> V_30 & V_179 ) &&
( V_12 -> V_30 >= V_182 ) &&
( V_12 -> V_30 <= V_183 )
) || ( ( V_12 -> V_30 & V_178 ) &&
( V_12 -> V_30 <= V_184 ) &&
( V_12 -> V_30 >= V_185 )
)
) ) {
V_12 -> V_16 -> V_108 = 2 ;
return ( - 1 ) ;
} else {
V_41 = V_120 ;
F_9 ( V_105 , V_136 ) ;
goto V_57;
}
}
V_57:
F_30 ( V_12 , V_78 , V_41 ) ;
V_61:
return ( - 1 ) ;
}
int F_64 ( T_1 * V_12 , int type , const void * V_186 , int V_89 )
{
int V_6 ;
#ifndef F_10
if ( ( F_37 ( V_12 ) && ! V_12 -> V_98 ) ||
( F_11 ( F_59 ( V_12 ) ) &&
( V_12 -> V_30 == V_106
|| V_12 -> V_30 == V_107 ) ) )
#else
if ( F_37 ( V_12 ) && ! V_12 -> V_98 )
#endif
{
V_6 = V_12 -> V_109 ( V_12 ) ;
if ( V_6 < 0 )
return ( V_6 ) ;
if ( V_6 == 0 ) {
F_9 ( V_187 ,
V_110 ) ;
return - 1 ;
}
}
if ( V_89 > V_75 ) {
F_9 ( V_187 , V_188 ) ;
return - 1 ;
}
V_6 = F_65 ( V_12 , type , V_186 , V_89 ) ;
return V_6 ;
}
static int
F_41 ( T_1 * V_12 , int type , unsigned char * V_18 ,
int V_89 , int V_99 )
{
if ( ( type == V_96 ) && ( V_12 -> V_35 -> V_129 > 0 ) )
{
unsigned char * V_189 = V_12 -> V_35 -> V_128 ;
unsigned char * V_190 = V_18 ;
unsigned int V_124 , V_81 ;
V_81 = 0 ;
while ( ( V_89 > 0 ) && ( V_12 -> V_35 -> V_129 > 0 ) ) {
* V_190 ++ = * V_189 ++ ;
V_89 -- ;
V_12 -> V_35 -> V_129 -- ;
V_81 ++ ;
}
for ( V_124 = 0 ; V_124 < V_12 -> V_35 -> V_129 ; V_124 ++ )
V_12 -> V_35 -> V_128 [ V_124 ] = * V_189 ++ ;
return V_81 ;
}
return 0 ;
}
int F_65 ( T_1 * V_12 , int type , const void * V_18 , int V_89 )
{
int V_6 ;
F_25 ( V_89 <= V_75 ) ;
V_12 -> V_112 = V_113 ;
V_6 = F_66 ( V_12 , type , V_18 , V_89 , 0 ) ;
return V_6 ;
}
int F_66 ( T_1 * V_12 , int type , const unsigned char * V_18 ,
unsigned int V_89 , int V_191 )
{
unsigned char * V_82 , * V_192 ;
int V_6 , V_45 , V_193 = 0 ;
int V_194 = 0 ;
int V_195 ;
V_23 * V_196 ;
V_21 * V_197 ;
T_5 * V_43 ;
if ( V_12 -> V_16 -> V_198 . V_149 != 0 ) {
F_25 ( 0 ) ;
return ( F_67 ( V_12 , type , V_18 , V_89 ) ) ;
}
if ( V_12 -> V_16 -> V_199 ) {
V_6 = V_12 -> V_58 -> V_200 ( V_12 ) ;
if ( V_6 <= 0 )
return ( V_6 ) ;
}
if ( V_89 == 0 && ! V_191 )
return 0 ;
V_196 = & ( V_12 -> V_16 -> V_201 ) ;
V_197 = & ( V_12 -> V_16 -> V_198 ) ;
V_43 = V_12 -> V_49 ;
if ( ( V_43 == NULL ) ||
( V_12 -> V_202 == NULL ) || ( F_23 ( V_12 -> V_203 ) == NULL ) )
V_193 = 1 ;
if ( V_193 )
V_45 = 0 ;
else {
V_45 = F_24 ( V_12 -> V_203 ) ;
if ( V_45 < 0 )
goto V_61;
}
#if 0
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done
&& SSL_version(s) != DTLS1_VERSION && SSL_version(s) != DTLS1_BAD_VER)
{
if (s->s3->need_empty_fragments && type == SSL3_RT_APPLICATION_DATA) {
prefix_len = s->method->do_ssl_write(s, type, buf, 0, 1);
if (prefix_len <= 0)
goto err;
if (s->s3->wbuf.len <
(size_t)prefix_len + SSL3_RT_MAX_PACKET_SIZE) {
SSLerr(SSL_F_DO_DTLS1_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
}
s->s3->empty_fragment_done = 1;
}
#endif
V_82 = V_197 -> V_18 + V_194 ;
* ( V_82 ++ ) = type & 0xff ;
V_196 -> type = type ;
if ( V_12 -> V_58 -> V_83 == V_204 ) {
* ( V_82 ++ ) = V_205 >> 8 ;
* ( V_82 ++ ) = V_205 & 0xff ;
} else {
* ( V_82 ++ ) = V_12 -> V_83 >> 8 ;
* ( V_82 ++ ) = V_12 -> V_83 & 0xff ;
}
V_192 = V_82 ;
V_82 += 10 ;
if ( V_12 -> V_202 ) {
int V_147 = F_26 ( V_12 -> V_202 ) ;
if ( V_147 == V_67 ) {
V_195 = F_68 ( V_12 -> V_202 ) ;
if ( V_195 <= 1 )
V_195 = 0 ;
}
else if ( V_147 == V_206 )
V_195 = V_207 ;
else
V_195 = 0 ;
} else
V_195 = 0 ;
V_196 -> V_15 = V_82 + V_195 ;
V_196 -> V_52 = ( int ) V_89 ;
V_196 -> V_50 = ( unsigned char * ) V_18 ;
if ( V_12 -> V_208 != NULL ) {
if ( ! F_69 ( V_12 ) ) {
F_9 ( V_209 , V_210 ) ;
goto V_61;
}
} else {
memcpy ( V_196 -> V_15 , V_196 -> V_50 , V_196 -> V_52 ) ;
V_196 -> V_50 = V_196 -> V_15 ;
}
if ( V_45 != 0 ) {
if ( V_12 -> V_58 -> V_59 -> V_65 ( V_12 , & ( V_82 [ V_196 -> V_52 + V_195 ] ) , 1 ) < 0 )
goto V_61;
V_196 -> V_52 += V_45 ;
}
V_196 -> V_50 = V_82 ;
V_196 -> V_15 = V_82 ;
if ( V_195 )
V_196 -> V_52 += V_195 ;
if ( V_12 -> V_58 -> V_59 -> V_60 ( V_12 , 1 ) < 1 )
goto V_61;
F_70 ( V_12 -> V_35 -> V_211 , V_192 ) ;
memcpy ( V_192 , & ( V_12 -> V_16 -> V_212 [ 2 ] ) , 6 ) ;
V_192 += 6 ;
F_70 ( V_196 -> V_52 , V_192 ) ;
if ( V_12 -> V_90 )
V_12 -> V_90 ( 1 , 0 , V_91 , V_192 - V_51 ,
V_51 , V_12 , V_12 -> V_92 ) ;
V_196 -> type = type ;
V_196 -> V_52 += V_51 ;
#if 0
if (type == SSL3_RT_HANDSHAKE || type == SSL3_RT_CHANGE_CIPHER_SPEC)
dtls1_buffer_record(s, wr->data, wr->length,
*((PQ_64BIT *) & (s->s3->write_sequence[0])));
#endif
F_71 ( & ( V_12 -> V_16 -> V_212 [ 0 ] ) ) ;
if ( V_191 ) {
return V_196 -> V_52 ;
}
V_197 -> V_149 = V_194 + V_196 -> V_52 ;
V_197 -> V_213 = 0 ;
V_12 -> V_16 -> V_214 = V_89 ;
V_12 -> V_16 -> V_215 = V_18 ;
V_12 -> V_16 -> V_216 = type ;
V_12 -> V_16 -> V_217 = V_89 ;
return F_67 ( V_12 , type , V_18 , V_89 ) ;
V_61:
return - 1 ;
}
static int F_36 ( T_1 * V_12 , T_6 * V_84 )
{
int V_218 ;
unsigned int V_219 ;
const unsigned char * V_220 = V_12 -> V_16 -> V_24 ;
V_218 = F_1 ( V_220 , V_84 -> V_221 ) ;
if ( V_218 > 0 ) {
memcpy ( V_12 -> V_16 -> V_22 . V_40 , V_220 , 8 ) ;
return 1 ;
}
V_219 = - V_218 ;
if ( V_219 >= sizeof( V_84 -> V_222 ) * 8 )
return 0 ;
else if ( V_84 -> V_222 & ( 1UL << V_219 ) )
return 0 ;
memcpy ( V_12 -> V_16 -> V_22 . V_40 , V_220 , 8 ) ;
return 1 ;
}
static void F_38 ( T_1 * V_12 , T_6 * V_84 )
{
int V_218 ;
unsigned int V_219 ;
const unsigned char * V_220 = V_12 -> V_16 -> V_24 ;
V_218 = F_1 ( V_220 , V_84 -> V_221 ) ;
if ( V_218 > 0 ) {
V_219 = V_218 ;
if ( V_219 < sizeof( V_84 -> V_222 ) * 8 )
V_84 -> V_222 <<= V_219 , V_84 -> V_222 |= 1UL ;
else
V_84 -> V_222 = 1UL ;
memcpy ( V_84 -> V_221 , V_220 , 8 ) ;
} else {
V_219 = - V_218 ;
if ( V_219 < sizeof( V_84 -> V_222 ) * 8 )
V_84 -> V_222 |= 1UL << V_219 ;
}
}
int F_72 ( T_1 * V_12 )
{
int V_6 , V_100 ;
void (* F_40) ( const T_1 * V_101 , int type , int V_103 ) = NULL ;
unsigned char V_18 [ V_150 ] ;
unsigned char * V_223 = & V_18 [ 0 ] ;
V_12 -> V_16 -> V_199 = 0 ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
* V_223 ++ = V_12 -> V_16 -> V_224 [ 0 ] ;
* V_223 ++ = V_12 -> V_16 -> V_224 [ 1 ] ;
#ifdef F_49
if ( V_12 -> V_16 -> V_224 [ 1 ] == F_49 ) {
F_70 ( V_12 -> V_35 -> V_145 , V_223 ) ;
# if 0
if (s->d1->r_msg_hdr.frag_off == 0)
else
s2n(s->d1->r_msg_hdr.seq, ptr);
# endif
# if 0
fprintf(stderr,
"s->d1->handshake_read_seq = %d, s->d1->r_msg_hdr.seq = %d\n",
s->d1->handshake_read_seq, s->d1->r_msg_hdr.seq);
# endif
F_73 ( V_12 -> V_35 -> V_225 . V_226 , V_223 ) ;
}
#endif
V_6 = F_66 ( V_12 , V_130 , & V_18 [ 0 ] , sizeof( V_18 ) , 0 ) ;
if ( V_6 <= 0 ) {
V_12 -> V_16 -> V_199 = 1 ;
} else {
if ( V_12 -> V_16 -> V_224 [ 0 ] == V_78
#ifdef F_49
|| V_12 -> V_16 -> V_224 [ 1 ] == F_49
#endif
)
( void ) F_74 ( V_12 -> V_227 ) ;
if ( V_12 -> V_90 )
V_12 -> V_90 ( 1 , V_12 -> V_83 , V_130 , V_12 -> V_16 -> V_224 ,
2 , V_12 , V_12 -> V_92 ) ;
if ( V_12 -> V_153 != NULL )
F_40 = V_12 -> V_153 ;
else if ( V_12 -> V_154 -> V_153 != NULL )
F_40 = V_12 -> V_154 -> V_153 ;
if ( F_40 != NULL ) {
V_100 = ( V_12 -> V_16 -> V_224 [ 0 ] << 8 ) | V_12 -> V_16 -> V_224 [ 1 ] ;
F_40 ( V_12 , V_228 , V_100 ) ;
}
}
return ( V_6 ) ;
}
static T_6 * F_35 ( T_1 * V_12 , V_23 * V_44 ,
unsigned int * V_85 )
{
* V_85 = 0 ;
if ( V_44 -> V_37 == V_12 -> V_35 -> V_38 )
return & V_12 -> V_35 -> V_84 ;
else if ( V_44 -> V_37 == ( unsigned long ) ( V_12 -> V_35 -> V_38 + 1 ) &&
( V_44 -> type == V_96 || V_44 -> type == V_130 ) ) {
* V_85 = 1 ;
return & V_12 -> V_35 -> V_229 ;
}
return NULL ;
}
void F_58 ( T_1 * V_12 , int V_230 )
{
unsigned char * V_220 ;
unsigned int V_231 = sizeof( V_12 -> V_16 -> V_24 ) ;
if ( V_230 & V_172 ) {
V_220 = V_12 -> V_16 -> V_24 ;
V_12 -> V_35 -> V_38 ++ ;
memcpy ( & ( V_12 -> V_35 -> V_84 ) , & ( V_12 -> V_35 -> V_229 ) , sizeof( T_6 ) ) ;
memset ( & ( V_12 -> V_35 -> V_229 ) , 0x00 , sizeof( T_6 ) ) ;
} else {
V_220 = V_12 -> V_16 -> V_212 ;
memcpy ( V_12 -> V_35 -> V_232 , V_220 ,
sizeof( V_12 -> V_16 -> V_212 ) ) ;
V_12 -> V_35 -> V_211 ++ ;
}
memset ( V_220 , 0x00 , V_231 ) ;
}
