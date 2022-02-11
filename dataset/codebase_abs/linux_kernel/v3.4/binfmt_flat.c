static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_3 -> V_4 , V_3 -> V_5 , ( int ) V_2 -> V_6 ) ;
return ( 1 ) ;
}
static unsigned long F_3 (
unsigned long V_7 ,
struct V_8 * V_9 )
{
unsigned long * V_10 , * V_11 ;
unsigned long * V_12 ;
char * V_13 = ( char * ) V_7 ;
int V_14 = V_9 -> V_14 ;
int V_15 = V_9 -> V_15 ;
char V_16 ( V_17 ) ;
V_12 = ( unsigned long * ) V_13 ;
V_12 -= ( V_15 + V_14 + 2 ) + 1 + ( F_4 () ? 2 : 0 ) ;
V_12 = ( unsigned long * ) ( ( unsigned long ) V_12 & - V_18 ) ;
V_10 = V_12 + 1 + ( F_4 () ? 2 : 0 ) ;
V_11 = V_10 + ( V_14 + 1 ) ;
if ( F_4 () ) {
F_5 ( ( unsigned long ) V_11 , V_12 + 2 ) ;
F_5 ( ( unsigned long ) V_10 , V_12 + 1 ) ;
}
F_5 ( V_14 , V_12 ) ;
V_3 -> V_19 -> V_20 = ( unsigned long ) V_13 ;
while ( V_14 -- > 0 ) {
F_5 ( ( unsigned long ) V_13 , V_10 ++ ) ;
do {
F_6 ( V_17 , V_13 ) ; V_13 ++ ;
} while ( V_17 );
}
F_5 ( ( unsigned long ) NULL , V_10 ) ;
V_3 -> V_19 -> V_21 = V_3 -> V_19 -> V_22 = ( unsigned long ) V_13 ;
while ( V_15 -- > 0 ) {
F_5 ( ( unsigned long ) V_13 , V_11 ) ; V_11 ++ ;
do {
F_6 ( V_17 , V_13 ) ; V_13 ++ ;
} while ( V_17 );
}
F_5 ( ( unsigned long ) NULL , V_11 ) ;
V_3 -> V_19 -> V_23 = ( unsigned long ) V_13 ;
return ( unsigned long ) V_12 ;
}
static int F_7 (
struct V_8 * V_9 ,
unsigned long V_24 ,
char * V_25 ,
long V_26 ,
int V_27 )
{
unsigned char * V_28 ;
T_1 V_29 ;
T_2 V_30 ;
int V_31 , V_32 ;
F_8 ( L_2 , ( int ) V_24 , ( int ) V_25 , ( int ) V_26 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_33 = F_9 ( F_10 () , V_34 ) ;
if ( V_29 . V_33 == NULL ) {
F_8 ( L_3 ) ;
return - V_35 ;
}
V_28 = F_9 ( V_36 , V_34 ) ;
if ( V_28 == NULL ) {
F_8 ( L_4 ) ;
V_32 = - V_35 ;
goto V_37;
}
V_30 = V_24 ;
V_31 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 , V_28 , V_36 , & V_30 ) ;
V_29 . V_41 = V_28 ;
V_29 . V_42 = V_31 ;
V_29 . V_43 = 0 ;
V_32 = - V_44 ;
if ( V_31 < 10 ) {
F_8 ( L_5 ) ;
goto V_45;
}
if ( ( V_28 [ 0 ] != 037 ) || ( ( V_28 [ 1 ] != 0213 ) && ( V_28 [ 1 ] != 0236 ) ) ) {
F_8 ( L_6 ) ;
goto V_45;
}
if ( V_28 [ 2 ] != 8 ) {
F_8 ( L_7 ) ;
goto V_45;
}
if ( ( V_28 [ 3 ] & V_46 ) || ( V_28 [ 3 ] & V_47 ) ||
( V_28 [ 3 ] & V_48 ) ) {
F_8 ( L_8 ) ;
goto V_45;
}
V_31 = 10 ;
if ( V_28 [ 3 ] & V_49 ) {
V_31 += 2 + V_28 [ 10 ] + ( V_28 [ 11 ] << 8 ) ;
if ( F_11 ( V_36 <= V_31 ) ) {
F_8 ( L_9 ) ;
goto V_45;
}
}
if ( V_28 [ 3 ] & V_50 ) {
while ( V_31 < V_36 && V_28 [ V_31 ++ ] != 0 )
;
if ( F_11 ( V_36 == V_31 ) ) {
F_8 ( L_10 ) ;
goto V_45;
}
}
if ( V_28 [ 3 ] & V_51 ) {
while ( V_31 < V_36 && V_28 [ V_31 ++ ] != 0 )
;
if ( F_11 ( V_36 == V_31 ) ) {
F_8 ( L_11 ) ;
goto V_45;
}
}
V_29 . V_41 += V_31 ;
V_29 . V_42 -= V_31 ;
V_29 . V_52 = V_25 ;
V_29 . V_53 = V_26 ;
V_29 . V_54 = 0 ;
if ( F_12 ( & V_29 , - V_55 ) != V_56 ) {
F_8 ( L_12 ) ;
goto V_45;
}
while ( ( V_31 = F_13 ( & V_29 , V_57 ) ) == V_56 ) {
V_31 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 , V_28 , V_36 , & V_30 ) ;
if ( V_31 <= 0 )
break;
V_26 -= V_31 ;
V_29 . V_41 = V_28 ;
V_29 . V_42 = V_31 ;
V_29 . V_43 = 0 ;
}
if ( V_31 < 0 ) {
F_8 ( L_13 ,
V_31 , V_29 . V_58 ) ;
goto V_59;
}
V_32 = 0 ;
V_59:
F_14 ( & V_29 ) ;
V_45:
F_15 ( V_28 ) ;
V_37:
F_15 ( V_29 . V_33 ) ;
return V_32 ;
}
static unsigned long
F_16 ( unsigned long V_60 , struct V_61 * V_13 , int V_62 , int V_63 )
{
unsigned long V_64 ;
int V_65 ;
unsigned long V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
#ifdef F_17
if ( V_60 == 0 )
V_65 = V_62 ;
else {
V_65 = ( V_60 >> 24 ) & 0xff ;
V_60 &= 0x00ffffff ;
}
if ( V_65 >= V_70 ) {
F_2 ( L_14 ,
( unsigned ) V_60 , V_65 ) ;
goto V_71;
}
if ( V_62 != V_65 ) {
if ( V_63 ) {
F_2 ( L_15
L_16 , ( unsigned ) V_60 , V_62 , V_65 ) ;
goto V_71;
} else if ( ! V_13 -> V_72 [ V_65 ] . V_73 &&
F_18 ( F_19 ( V_65 , V_13 ) ) ) {
F_2 ( L_17 , V_65 ) ;
goto V_71;
}
if ( V_13 -> V_72 [ V_65 ] . V_74 && V_13 -> V_72 [ V_62 ] . V_74 &&
V_13 -> V_72 [ V_62 ] . V_74 < V_13 -> V_72 [ V_65 ] . V_74 ) {
F_2 ( L_18 , V_65 , V_62 ) ;
goto V_71;
}
}
#else
V_65 = 0 ;
#endif
V_66 = V_13 -> V_72 [ V_65 ] . V_66 ;
V_67 = V_13 -> V_72 [ V_65 ] . V_67 ;
V_69 = V_13 -> V_72 [ V_65 ] . V_69 ;
V_68 = V_13 -> V_72 [ V_65 ] . V_68 ;
if ( ! F_20 ( V_60 , V_66 - V_67 + V_68 ) ) {
F_2 ( L_19 ,
( int ) V_60 , ( int ) ( V_66 - V_67 + V_68 ) , ( int ) V_68 ) ;
goto V_71;
}
if ( V_60 < V_68 )
V_64 = V_60 + V_69 ;
else
V_64 = V_60 - V_68 + V_67 ;
return ( V_64 ) ;
V_71:
F_2 ( L_20 , V_3 -> V_4 ) ;
F_21 ( V_75 , V_3 , 0 ) ;
return V_76 ;
}
void F_22 ( unsigned long V_77 )
{
#ifdef F_23
char * V_78 [] = { L_21 , L_22 , L_23 , L_24 } ;
#endif
T_3 V_60 ;
unsigned long * V_79 ;
V_60 . V_80 = V_77 ;
#if F_24 ( V_81 )
V_79 = ( unsigned long * ) ( V_3 -> V_19 -> V_69 + V_60 . V_82 . V_24 ) ;
#else
V_79 = ( unsigned long * ) ( V_3 -> V_19 -> V_67 + V_60 . V_82 . V_24 ) ;
#endif
#ifdef F_23
F_2 ( L_25
L_26 ,
V_60 . V_82 . V_24 , V_79 , ( int ) * V_79 , V_78 [ V_60 . V_82 . type ] ) ;
#endif
switch ( V_60 . V_82 . type ) {
case V_83 :
* V_79 += V_3 -> V_19 -> V_69 ;
break;
case V_84 :
* V_79 += V_3 -> V_19 -> V_67 ;
break;
case V_85 :
* V_79 += V_3 -> V_19 -> V_86 ;
break;
default:
F_2 ( L_27 , V_60 . V_82 . type ) ;
break;
}
#ifdef F_23
F_2 ( L_28 , ( int ) * V_79 ) ;
#endif
}
static int F_25 ( struct V_8 * V_9 ,
struct V_61 * V_87 , int V_65 , unsigned long * V_88 )
{
struct V_89 * V_90 ;
unsigned long V_91 = 0 , V_92 = 0 , V_93 ;
unsigned long V_94 = 0 ;
unsigned long V_68 , V_95 , V_96 , V_97 , V_98 ;
unsigned long V_26 , V_99 = 0 ;
unsigned long V_100 , V_101 , V_102 ;
unsigned long * V_82 = 0 , * V_103 ;
struct V_104 * V_104 ;
int V_105 , V_106 , V_107 = 0 ;
T_2 V_30 ;
unsigned long V_69 , V_108 ;
int V_31 ;
V_90 = ( (struct V_89 * ) V_9 -> V_28 ) ;
V_104 = V_9 -> V_38 -> V_109 . V_110 -> V_111 ;
V_68 = F_26 ( V_90 -> V_112 ) ;
V_95 = F_26 ( V_90 -> V_113 ) - F_26 ( V_90 -> V_112 ) ;
V_96 = F_26 ( V_90 -> V_114 ) - F_26 ( V_90 -> V_113 ) ;
V_97 = F_26 ( V_90 -> V_115 ) ;
if ( V_88 ) {
V_97 += * V_88 ;
* V_88 = V_97 ;
}
V_107 = F_26 ( V_90 -> V_116 ) ;
V_98 = F_26 ( V_90 -> V_98 ) ;
V_106 = F_26 ( V_90 -> V_106 ) ;
if ( strncmp ( V_90 -> V_117 , L_29 , 4 ) ) {
V_31 = - V_44 ;
goto V_118;
}
if ( V_98 & V_119 )
F_2 ( L_30 , V_9 -> V_120 ) ;
if ( V_106 != V_121 && V_106 != V_122 ) {
F_2 ( L_31
L_32 ,
V_106 , V_121 , V_122 ) ;
V_31 = - V_44 ;
goto V_118;
}
if ( V_106 == V_122 && V_65 != 0 ) {
F_2 ( L_33 ,
( int ) V_121 ) ;
V_31 = - V_44 ;
goto V_118;
}
if ( V_106 == V_122 && F_27 ( V_98 ) )
V_98 = V_123 ;
#ifndef F_28
if ( V_98 & ( V_124 | V_125 ) ) {
F_2 ( L_34 ) ;
V_31 = - V_44 ;
goto V_118;
}
#endif
V_102 = F_29 ( V_126 ) ;
if ( V_102 >= V_127 )
V_102 = ~ 0 ;
if ( V_95 + V_96 > V_102 ) {
V_31 = - V_35 ;
goto V_118;
}
if ( V_65 == 0 ) {
V_93 = F_30 ( V_9 ) ;
if ( V_93 ) {
V_31 = V_93 ;
goto V_118;
}
F_31 ( V_128 ) ;
F_32 ( V_9 ) ;
}
V_101 = F_33 (unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long)) ;
if ( ( V_98 & ( V_123 | V_124 ) ) == 0 ) {
F_8 ( L_35 ) ;
V_91 = F_34 ( V_9 -> V_38 , 0 , V_68 , V_129 | V_130 ,
V_131 | V_132 , 0 ) ;
if ( ! V_91 || F_18 ( V_91 ) ) {
if ( ! V_91 )
V_91 = ( unsigned long ) - V_35 ;
F_2 ( L_36 , ( int ) - V_91 ) ;
V_31 = V_91 ;
goto V_118;
}
V_26 = V_95 + V_101 + V_70 * sizeof( unsigned long ) ;
V_26 = F_35 ( V_26 ) ;
V_94 = F_34 ( 0 , 0 , V_26 ,
V_129 | V_133 | V_130 , V_131 , 0 ) ;
if ( V_94 == 0 || F_18 ( V_94 ) ) {
if ( ! V_94 )
V_94 = ( unsigned long ) - V_35 ;
F_2 ( L_37 ,
( int ) - V_94 ) ;
F_36 ( V_3 -> V_19 , V_91 , V_68 ) ;
V_31 = V_94 ;
goto V_118;
}
V_92 = F_37 ( V_94 +
V_70 * sizeof( unsigned long ) ,
V_134 ) ;
F_8 ( L_38 ,
( int ) ( V_95 + V_96 + V_97 ) , ( int ) V_92 ) ;
V_30 = F_26 ( V_90 -> V_112 ) ;
#ifdef F_28
if ( V_98 & V_125 ) {
V_93 = F_7 ( V_9 , V_30 , ( char * ) V_92 ,
V_95 + ( V_107 * sizeof( unsigned long ) ) , 0 ) ;
} else
#endif
{
V_93 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 , ( char * ) V_92 ,
V_95 + ( V_107 * sizeof( unsigned long ) ) , & V_30 ) ;
}
if ( F_18 ( V_93 ) ) {
F_2 ( L_39 , ( int ) - V_93 ) ;
F_36 ( V_3 -> V_19 , V_91 , V_68 ) ;
F_36 ( V_3 -> V_19 , V_94 , V_26 ) ;
V_31 = V_93 ;
goto V_118;
}
V_82 = ( unsigned long * ) ( V_92 + ( F_26 ( V_90 -> V_135 ) - V_68 ) ) ;
V_99 = V_94 ;
V_100 = V_26 ;
} else {
V_26 = V_68 + V_95 + V_101 + V_70 * sizeof( unsigned long ) ;
V_26 = F_35 ( V_26 ) ;
V_91 = F_34 ( 0 , 0 , V_26 ,
V_129 | V_130 | V_133 , V_131 , 0 ) ;
if ( ! V_91 || F_18 ( V_91 ) ) {
if ( ! V_91 )
V_91 = ( unsigned long ) - V_35 ;
F_2 ( L_40 ,
( int ) - V_91 ) ;
V_31 = V_91 ;
goto V_118;
}
V_94 = V_91 + F_26 ( V_90 -> V_112 ) ;
V_92 = F_37 ( V_94 +
V_70 * sizeof( unsigned long ) ,
V_134 ) ;
V_82 = ( unsigned long * )
( V_92 + ( F_26 ( V_90 -> V_135 ) - V_68 ) ) ;
V_99 = V_91 ;
V_100 = V_26 ;
#ifdef F_28
if ( V_98 & V_124 ) {
V_93 = F_7 ( V_9 , sizeof ( struct V_89 ) ,
( ( ( char * ) V_91 ) + sizeof ( struct V_89 ) ) ,
( V_68 + V_95 + ( V_107 * sizeof( unsigned long ) )
- sizeof ( struct V_89 ) ) ,
0 ) ;
memmove ( ( void * ) V_92 , ( void * ) V_94 ,
V_95 + ( V_107 * sizeof( unsigned long ) ) ) ;
} else if ( V_98 & V_125 ) {
V_30 = 0 ;
V_93 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 ,
( char * ) V_91 , V_68 , & V_30 ) ;
if ( ! F_18 ( V_93 ) )
V_93 = F_7 ( V_9 , V_68 , ( char * ) V_92 ,
V_95 + ( V_107 * sizeof( unsigned long ) ) , 0 ) ;
}
else
#endif
{
V_30 = 0 ;
V_93 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 ,
( char * ) V_91 , V_68 , & V_30 ) ;
if ( ! F_18 ( V_93 ) ) {
V_30 = F_26 ( V_90 -> V_112 ) ;
V_93 = V_9 -> V_38 -> V_39 -> V_40 ( V_9 -> V_38 , ( char * ) V_92 ,
V_95 + ( V_107 * sizeof( unsigned long ) ) , & V_30 ) ;
}
}
if ( F_18 ( V_93 ) ) {
F_2 ( L_41 , ( int ) - V_93 ) ;
F_36 ( V_3 -> V_19 , V_91 , V_68 + V_95 + V_101 +
V_70 * sizeof( unsigned long ) ) ;
V_31 = V_93 ;
goto V_118;
}
}
if ( V_98 & V_119 )
F_2 ( L_42 ,
( int ) V_91 , 0x00ffffff & F_26 ( V_90 -> V_136 ) , F_26 ( V_90 -> V_112 ) ) ;
V_69 = V_91 + sizeof ( struct V_89 ) ;
V_108 = V_91 + V_68 ;
if ( V_65 == 0 ) {
V_3 -> V_19 -> V_69 = V_69 ;
V_3 -> V_19 -> V_108 = V_108 ;
V_3 -> V_19 -> V_67 = V_92 ;
V_3 -> V_19 -> V_86 = V_92 + V_95 ;
V_3 -> V_19 -> V_66 = V_92 + V_95 + V_96 ;
V_3 -> V_19 -> V_137 = ( V_3 -> V_19 -> V_66 + 3 ) & ~ 3 ;
V_3 -> V_19 -> V_138 . V_139 = V_99 + V_100 - V_97 ;
}
if ( V_98 & V_119 )
F_2 ( L_43 ,
V_65 ? L_44 : L_45 , V_9 -> V_120 ,
( int ) V_69 , ( int ) V_108 ,
( int ) V_92 ,
( int ) ( V_92 + V_95 ) ,
( int ) ( V_92 + V_95 ) ,
( int ) ( ( ( V_92 + V_95 + V_96 ) + 3 ) & ~ 3 ) ) ;
V_68 -= sizeof( struct V_89 ) ;
V_87 -> V_72 [ V_65 ] . V_69 = V_69 ;
V_87 -> V_72 [ V_65 ] . V_67 = V_92 ;
V_87 -> V_72 [ V_65 ] . V_66 = V_92 + V_95 + V_96 ;
V_87 -> V_72 [ V_65 ] . V_68 = V_68 ;
V_87 -> V_72 [ V_65 ] . V_73 = 1 ;
V_87 -> V_72 [ V_65 ] . V_136 = ( 0x00ffffff & F_26 ( V_90 -> V_136 ) ) + V_91 ;
V_87 -> V_72 [ V_65 ] . V_74 = F_26 ( V_90 -> V_74 ) ;
if ( V_98 & V_140 ) {
for ( V_103 = ( unsigned long * ) V_92 ; * V_103 != 0xffffffff ; V_103 ++ ) {
unsigned long V_64 ;
if ( * V_103 ) {
V_64 = F_16 ( * V_103 , V_87 , V_65 , 0 ) ;
if ( V_64 == V_76 ) {
V_31 = - V_44 ;
goto V_118;
}
* V_103 = V_64 ;
}
}
}
if ( V_106 > V_122 ) {
unsigned long V_141 = 0 ;
for ( V_105 = 0 ; V_105 < V_107 ; V_105 ++ ) {
unsigned long V_64 , V_142 ;
V_142 = F_26 ( V_82 [ V_105 ] ) ;
if ( F_38 ( V_142 , & V_141 ) )
continue;
V_64 = F_39 ( V_142 ) ;
V_103 = ( unsigned long * ) F_16 ( V_64 , V_87 , V_65 , 1 ) ;
if ( V_103 == ( unsigned long * ) V_76 ) {
V_31 = - V_44 ;
goto V_118;
}
V_64 = F_40 ( V_103 , V_142 , V_98 ,
& V_141 ) ;
if ( V_64 != 0 ) {
if ( ( V_98 & V_140 ) == 0 )
V_64 = F_26 ( V_64 ) ;
V_64 = F_16 ( V_64 , V_87 , V_65 , 0 ) ;
if ( V_64 == V_76 ) {
V_31 = - V_44 ;
goto V_118;
}
F_41 ( V_103 , V_64 , V_142 ) ;
}
}
} else {
for ( V_105 = 0 ; V_105 < V_107 ; V_105 ++ )
F_22 ( F_26 ( V_82 [ V_105 ] ) ) ;
}
F_42 ( V_69 , V_108 ) ;
memset ( ( void * ) ( V_92 + V_95 ) , 0 , V_96 +
( V_99 + V_100 - V_97 -
V_87 -> V_72 [ V_65 ] . V_66 ) +
V_97 ) ;
return 0 ;
V_118:
return V_31 ;
}
static int F_19 ( int V_65 , struct V_61 * V_143 )
{
struct V_8 V_9 ;
int V_144 ;
char V_28 [ 16 ] ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
sprintf ( V_28 , L_46 , V_65 ) ;
V_9 . V_120 = V_28 ;
V_9 . V_38 = F_43 ( V_9 . V_120 ) ;
V_144 = F_44 ( V_9 . V_38 ) ;
if ( F_45 ( V_9 . V_38 ) )
return V_144 ;
V_9 . V_145 = F_46 () ;
V_144 = - V_35 ;
if ( ! V_9 . V_145 )
goto V_146;
V_9 . V_147 = 1 ;
V_144 = F_47 ( & V_9 ) ;
if ( ! F_18 ( V_144 ) )
V_144 = F_25 ( & V_9 , V_143 , V_65 , NULL ) ;
F_48 ( V_9 . V_145 ) ;
V_146:
F_49 ( V_9 . V_38 ) ;
F_50 ( V_9 . V_38 ) ;
return ( V_144 ) ;
}
static int F_51 ( struct V_8 * V_9 , struct V_148 * V_149 )
{
struct V_61 V_87 ;
unsigned long V_13 = V_9 -> V_13 ;
unsigned long V_97 ;
unsigned long V_150 ;
unsigned long * V_12 ;
int V_144 ;
int V_105 , V_151 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
#define F_52 (PAGE_SIZE * MAX_ARG_PAGES - sizeof(void *))
V_97 = F_52 - V_9 -> V_13 ;
V_97 += ( V_9 -> V_14 + 1 ) * sizeof( char * ) ;
V_97 += ( V_9 -> V_15 + 1 ) * sizeof( char * ) ;
V_97 += V_18 - 1 ;
V_144 = F_25 ( V_9 , & V_87 , 0 , & V_97 ) ;
if ( F_18 ( V_144 ) )
return V_144 ;
for ( V_105 = 0 ; V_105 < V_70 ; V_105 ++ )
if ( V_87 . V_72 [ V_105 ] . V_73 )
for ( V_151 = 0 ; V_151 < V_70 ; V_151 ++ )
( - ( V_151 + 1 ) ) [ ( unsigned long * ) ( V_87 . V_72 [ V_105 ] . V_67 ) ] =
( V_87 . V_72 [ V_151 ] . V_73 ) ?
V_87 . V_72 [ V_151 ] . V_67 : V_152 ;
F_53 ( V_9 ) ;
F_54 ( & V_153 ) ;
V_13 = ( ( V_3 -> V_19 -> V_138 . V_139 + V_97 + 3 ) & ~ 3 ) - 4 ;
F_8 ( L_47 , ( int ) V_13 ) ;
for ( V_105 = F_52 - 1 ; V_105 >= V_9 -> V_13 ; V_105 -- )
* ( char * ) -- V_13 =
( ( char * ) F_55 ( V_9 -> V_154 [ V_105 / V_155 ] ) ) [ V_105 % V_155 ] ;
V_12 = ( unsigned long * ) F_3 ( V_13 , V_9 ) ;
V_150 = V_87 . V_72 [ 0 ] . V_136 ;
#ifdef F_17
for ( V_105 = V_70 - 1 ; V_105 > 0 ; V_105 -- ) {
if ( V_87 . V_72 [ V_105 ] . V_73 ) {
-- V_12 ; F_5 ( V_150 , V_12 ) ;
V_150 = V_87 . V_72 [ V_105 ] . V_136 ;
}
}
#endif
V_3 -> V_19 -> V_156 = ( unsigned long ) V_12 ;
#ifdef F_56
F_56 ( V_149 ) ;
#endif
F_8 ( L_48 ,
( int ) V_149 , ( int ) V_150 , ( int ) V_3 -> V_19 -> V_156 ) ;
F_57 ( V_149 , V_150 , V_3 -> V_19 -> V_156 ) ;
return 0 ;
}
static int T_4 F_58 ( void )
{
F_59 ( & V_153 ) ;
return 0 ;
}
