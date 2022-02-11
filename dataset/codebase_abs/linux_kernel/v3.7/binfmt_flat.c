static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_3 -> V_4 , V_3 -> V_5 , ( int ) V_2 -> V_6 -> V_7 ) ;
return ( 1 ) ;
}
static unsigned long F_3 (
unsigned long V_8 ,
struct V_9 * V_10 )
{
unsigned long * V_11 , * V_12 ;
unsigned long * V_13 ;
char * V_14 = ( char * ) V_8 ;
int V_15 = V_10 -> V_15 ;
int V_16 = V_10 -> V_16 ;
char V_17 ( V_18 ) ;
V_13 = ( unsigned long * ) V_14 ;
V_13 -= ( V_16 + V_15 + 2 ) + 1 + ( F_4 () ? 2 : 0 ) ;
V_13 = ( unsigned long * ) ( ( unsigned long ) V_13 & - V_19 ) ;
V_11 = V_13 + 1 + ( F_4 () ? 2 : 0 ) ;
V_12 = V_11 + ( V_15 + 1 ) ;
if ( F_4 () ) {
F_5 ( ( unsigned long ) V_12 , V_13 + 2 ) ;
F_5 ( ( unsigned long ) V_11 , V_13 + 1 ) ;
}
F_5 ( V_15 , V_13 ) ;
V_3 -> V_20 -> V_21 = ( unsigned long ) V_14 ;
while ( V_15 -- > 0 ) {
F_5 ( ( unsigned long ) V_14 , V_11 ++ ) ;
do {
F_6 ( V_18 , V_14 ) ; V_14 ++ ;
} while ( V_18 );
}
F_5 ( ( unsigned long ) NULL , V_11 ) ;
V_3 -> V_20 -> V_22 = V_3 -> V_20 -> V_23 = ( unsigned long ) V_14 ;
while ( V_16 -- > 0 ) {
F_5 ( ( unsigned long ) V_14 , V_12 ) ; V_12 ++ ;
do {
F_6 ( V_18 , V_14 ) ; V_14 ++ ;
} while ( V_18 );
}
F_5 ( ( unsigned long ) NULL , V_12 ) ;
V_3 -> V_20 -> V_24 = ( unsigned long ) V_14 ;
return ( unsigned long ) V_13 ;
}
static int F_7 (
struct V_9 * V_10 ,
unsigned long V_25 ,
char * V_26 ,
long V_27 ,
int V_28 )
{
unsigned char * V_29 ;
T_1 V_30 ;
T_2 V_31 ;
int V_32 , V_33 ;
F_8 ( L_2 , ( int ) V_25 , ( int ) V_26 , ( int ) V_27 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_34 = F_9 ( F_10 () , V_35 ) ;
if ( V_30 . V_34 == NULL ) {
F_8 ( L_3 ) ;
return - V_36 ;
}
V_29 = F_9 ( V_37 , V_35 ) ;
if ( V_29 == NULL ) {
F_8 ( L_4 ) ;
V_33 = - V_36 ;
goto V_38;
}
V_31 = V_25 ;
V_32 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 , V_29 , V_37 , & V_31 ) ;
V_30 . V_42 = V_29 ;
V_30 . V_43 = V_32 ;
V_30 . V_44 = 0 ;
V_33 = - V_45 ;
if ( V_32 < 10 ) {
F_8 ( L_5 ) ;
goto V_46;
}
if ( ( V_29 [ 0 ] != 037 ) || ( ( V_29 [ 1 ] != 0213 ) && ( V_29 [ 1 ] != 0236 ) ) ) {
F_8 ( L_6 ) ;
goto V_46;
}
if ( V_29 [ 2 ] != 8 ) {
F_8 ( L_7 ) ;
goto V_46;
}
if ( ( V_29 [ 3 ] & V_47 ) || ( V_29 [ 3 ] & V_48 ) ||
( V_29 [ 3 ] & V_49 ) ) {
F_8 ( L_8 ) ;
goto V_46;
}
V_32 = 10 ;
if ( V_29 [ 3 ] & V_50 ) {
V_32 += 2 + V_29 [ 10 ] + ( V_29 [ 11 ] << 8 ) ;
if ( F_11 ( V_37 <= V_32 ) ) {
F_8 ( L_9 ) ;
goto V_46;
}
}
if ( V_29 [ 3 ] & V_51 ) {
while ( V_32 < V_37 && V_29 [ V_32 ++ ] != 0 )
;
if ( F_11 ( V_37 == V_32 ) ) {
F_8 ( L_10 ) ;
goto V_46;
}
}
if ( V_29 [ 3 ] & V_52 ) {
while ( V_32 < V_37 && V_29 [ V_32 ++ ] != 0 )
;
if ( F_11 ( V_37 == V_32 ) ) {
F_8 ( L_11 ) ;
goto V_46;
}
}
V_30 . V_42 += V_32 ;
V_30 . V_43 -= V_32 ;
V_30 . V_53 = V_26 ;
V_30 . V_54 = V_27 ;
V_30 . V_55 = 0 ;
if ( F_12 ( & V_30 , - V_56 ) != V_57 ) {
F_8 ( L_12 ) ;
goto V_46;
}
while ( ( V_32 = F_13 ( & V_30 , V_58 ) ) == V_57 ) {
V_32 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 , V_29 , V_37 , & V_31 ) ;
if ( V_32 <= 0 )
break;
V_27 -= V_32 ;
V_30 . V_42 = V_29 ;
V_30 . V_43 = V_32 ;
V_30 . V_44 = 0 ;
}
if ( V_32 < 0 ) {
F_8 ( L_13 ,
V_32 , V_30 . V_59 ) ;
goto V_60;
}
V_33 = 0 ;
V_60:
F_14 ( & V_30 ) ;
V_46:
F_15 ( V_29 ) ;
V_38:
F_15 ( V_30 . V_34 ) ;
return V_33 ;
}
static unsigned long
F_16 ( unsigned long V_61 , struct V_62 * V_14 , int V_63 , int V_64 )
{
unsigned long V_65 ;
int V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
unsigned long V_70 ;
#ifdef F_17
if ( V_61 == 0 )
V_66 = V_63 ;
else {
V_66 = ( V_61 >> 24 ) & 0xff ;
V_61 &= 0x00ffffff ;
}
if ( V_66 >= V_71 ) {
F_2 ( L_14 ,
( unsigned ) V_61 , V_66 ) ;
goto V_72;
}
if ( V_63 != V_66 ) {
if ( V_64 ) {
F_2 ( L_15
L_16 , ( unsigned ) V_61 , V_63 , V_66 ) ;
goto V_72;
} else if ( ! V_14 -> V_73 [ V_66 ] . V_74 &&
F_18 ( F_19 ( V_66 , V_14 ) ) ) {
F_2 ( L_17 , V_66 ) ;
goto V_72;
}
if ( V_14 -> V_73 [ V_66 ] . V_75 && V_14 -> V_73 [ V_63 ] . V_75 &&
V_14 -> V_73 [ V_63 ] . V_75 < V_14 -> V_73 [ V_66 ] . V_75 ) {
F_2 ( L_18 , V_66 , V_63 ) ;
goto V_72;
}
}
#else
V_66 = 0 ;
#endif
V_67 = V_14 -> V_73 [ V_66 ] . V_67 ;
V_68 = V_14 -> V_73 [ V_66 ] . V_68 ;
V_70 = V_14 -> V_73 [ V_66 ] . V_70 ;
V_69 = V_14 -> V_73 [ V_66 ] . V_69 ;
if ( ! F_20 ( V_61 , V_67 - V_68 + V_69 ) ) {
F_2 ( L_19 ,
( int ) V_61 , ( int ) ( V_67 - V_68 + V_69 ) , ( int ) V_69 ) ;
goto V_72;
}
if ( V_61 < V_69 )
V_65 = V_61 + V_70 ;
else
V_65 = V_61 - V_69 + V_68 ;
return ( V_65 ) ;
V_72:
F_2 ( L_20 , V_3 -> V_4 ) ;
F_21 ( V_76 , V_3 , 0 ) ;
return V_77 ;
}
void F_22 ( unsigned long V_78 )
{
#ifdef F_23
char * V_79 [] = { L_21 , L_22 , L_23 , L_24 } ;
#endif
T_3 V_61 ;
unsigned long * V_80 ;
V_61 . V_81 = V_78 ;
#if F_24 ( V_82 )
V_80 = ( unsigned long * ) ( V_3 -> V_20 -> V_70 + V_61 . V_83 . V_25 ) ;
#else
V_80 = ( unsigned long * ) ( V_3 -> V_20 -> V_68 + V_61 . V_83 . V_25 ) ;
#endif
#ifdef F_23
F_2 ( L_25
L_26 ,
V_61 . V_83 . V_25 , V_80 , ( int ) * V_80 , V_79 [ V_61 . V_83 . type ] ) ;
#endif
switch ( V_61 . V_83 . type ) {
case V_84 :
* V_80 += V_3 -> V_20 -> V_70 ;
break;
case V_85 :
* V_80 += V_3 -> V_20 -> V_68 ;
break;
case V_86 :
* V_80 += V_3 -> V_20 -> V_87 ;
break;
default:
F_2 ( L_27 , V_61 . V_83 . type ) ;
break;
}
#ifdef F_23
F_2 ( L_28 , ( int ) * V_80 ) ;
#endif
}
static int F_25 ( struct V_9 * V_10 ,
struct V_62 * V_88 , int V_66 , unsigned long * V_89 )
{
struct V_90 * V_91 ;
unsigned long V_92 = 0 , V_93 = 0 , V_94 ;
unsigned long V_95 = 0 ;
unsigned long V_69 , V_96 , V_97 , V_98 , V_99 ;
unsigned long V_27 , V_100 = 0 ;
unsigned long V_101 , V_102 , V_103 ;
unsigned long * V_83 = 0 , * V_104 ;
struct V_105 * V_105 ;
int V_106 , V_107 , V_108 = 0 ;
T_2 V_31 ;
unsigned long V_70 , V_109 ;
int V_32 ;
V_91 = ( (struct V_90 * ) V_10 -> V_29 ) ;
V_105 = V_10 -> V_39 -> V_110 . V_111 -> V_112 ;
V_69 = F_26 ( V_91 -> V_113 ) ;
V_96 = F_26 ( V_91 -> V_114 ) - F_26 ( V_91 -> V_113 ) ;
V_97 = F_26 ( V_91 -> V_115 ) - F_26 ( V_91 -> V_114 ) ;
V_98 = F_26 ( V_91 -> V_116 ) ;
if ( V_89 ) {
V_98 += * V_89 ;
* V_89 = V_98 ;
}
V_108 = F_26 ( V_91 -> V_117 ) ;
V_99 = F_26 ( V_91 -> V_99 ) ;
V_107 = F_26 ( V_91 -> V_107 ) ;
if ( strncmp ( V_91 -> V_118 , L_29 , 4 ) ) {
V_32 = - V_45 ;
goto V_119;
}
if ( V_99 & V_120 )
F_2 ( L_30 , V_10 -> V_121 ) ;
if ( V_107 != V_122 && V_107 != V_123 ) {
F_2 ( L_31
L_32 ,
V_107 , V_122 , V_123 ) ;
V_32 = - V_45 ;
goto V_119;
}
if ( V_107 == V_123 && V_66 != 0 ) {
F_2 ( L_33 ,
( int ) V_122 ) ;
V_32 = - V_45 ;
goto V_119;
}
if ( V_107 == V_123 && F_27 ( V_99 ) )
V_99 = V_124 ;
#ifndef F_28
if ( V_99 & ( V_125 | V_126 ) ) {
F_2 ( L_34 ) ;
V_32 = - V_45 ;
goto V_119;
}
#endif
V_103 = F_29 ( V_127 ) ;
if ( V_103 >= V_128 )
V_103 = ~ 0 ;
if ( V_96 + V_97 > V_103 ) {
V_32 = - V_36 ;
goto V_119;
}
if ( V_66 == 0 ) {
V_94 = F_30 ( V_10 ) ;
if ( V_94 ) {
V_32 = V_94 ;
goto V_119;
}
F_31 ( V_129 ) ;
F_32 ( V_10 ) ;
}
V_102 = F_33 (unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long)) ;
if ( ( V_99 & ( V_124 | V_125 ) ) == 0 ) {
F_8 ( L_35 ) ;
V_92 = F_34 ( V_10 -> V_39 , 0 , V_69 , V_130 | V_131 ,
V_132 | V_133 , 0 ) ;
if ( ! V_92 || F_18 ( V_92 ) ) {
if ( ! V_92 )
V_92 = ( unsigned long ) - V_36 ;
F_2 ( L_36 , ( int ) - V_92 ) ;
V_32 = V_92 ;
goto V_119;
}
V_27 = V_96 + V_102 + V_71 * sizeof( unsigned long ) ;
V_27 = F_35 ( V_27 ) ;
V_95 = F_34 ( 0 , 0 , V_27 ,
V_130 | V_134 | V_131 , V_132 , 0 ) ;
if ( V_95 == 0 || F_18 ( V_95 ) ) {
if ( ! V_95 )
V_95 = ( unsigned long ) - V_36 ;
F_2 ( L_37 ,
( int ) - V_95 ) ;
F_36 ( V_92 , V_69 ) ;
V_32 = V_95 ;
goto V_119;
}
V_93 = F_37 ( V_95 +
V_71 * sizeof( unsigned long ) ,
V_135 ) ;
F_8 ( L_38 ,
( int ) ( V_96 + V_97 + V_98 ) , ( int ) V_93 ) ;
V_31 = F_26 ( V_91 -> V_113 ) ;
#ifdef F_28
if ( V_99 & V_126 ) {
V_94 = F_7 ( V_10 , V_31 , ( char * ) V_93 ,
V_96 + ( V_108 * sizeof( unsigned long ) ) , 0 ) ;
} else
#endif
{
V_94 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 , ( char * ) V_93 ,
V_96 + ( V_108 * sizeof( unsigned long ) ) , & V_31 ) ;
}
if ( F_18 ( V_94 ) ) {
F_2 ( L_39 , ( int ) - V_94 ) ;
F_36 ( V_92 , V_69 ) ;
F_36 ( V_95 , V_27 ) ;
V_32 = V_94 ;
goto V_119;
}
V_83 = ( unsigned long * ) ( V_93 + ( F_26 ( V_91 -> V_136 ) - V_69 ) ) ;
V_100 = V_95 ;
V_101 = V_27 ;
} else {
V_27 = V_69 + V_96 + V_102 + V_71 * sizeof( unsigned long ) ;
V_27 = F_35 ( V_27 ) ;
V_92 = F_34 ( 0 , 0 , V_27 ,
V_130 | V_131 | V_134 , V_132 , 0 ) ;
if ( ! V_92 || F_18 ( V_92 ) ) {
if ( ! V_92 )
V_92 = ( unsigned long ) - V_36 ;
F_2 ( L_40 ,
( int ) - V_92 ) ;
V_32 = V_92 ;
goto V_119;
}
V_95 = V_92 + F_26 ( V_91 -> V_113 ) ;
V_93 = F_37 ( V_95 +
V_71 * sizeof( unsigned long ) ,
V_135 ) ;
V_83 = ( unsigned long * )
( V_93 + ( F_26 ( V_91 -> V_136 ) - V_69 ) ) ;
V_100 = V_92 ;
V_101 = V_27 ;
#ifdef F_28
if ( V_99 & V_125 ) {
V_94 = F_7 ( V_10 , sizeof ( struct V_90 ) ,
( ( ( char * ) V_92 ) + sizeof ( struct V_90 ) ) ,
( V_69 + V_96 + ( V_108 * sizeof( unsigned long ) )
- sizeof ( struct V_90 ) ) ,
0 ) ;
memmove ( ( void * ) V_93 , ( void * ) V_95 ,
V_96 + ( V_108 * sizeof( unsigned long ) ) ) ;
} else if ( V_99 & V_126 ) {
V_31 = 0 ;
V_94 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 ,
( char * ) V_92 , V_69 , & V_31 ) ;
if ( ! F_18 ( V_94 ) )
V_94 = F_7 ( V_10 , V_69 , ( char * ) V_93 ,
V_96 + ( V_108 * sizeof( unsigned long ) ) , 0 ) ;
}
else
#endif
{
V_31 = 0 ;
V_94 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 ,
( char * ) V_92 , V_69 , & V_31 ) ;
if ( ! F_18 ( V_94 ) ) {
V_31 = F_26 ( V_91 -> V_113 ) ;
V_94 = V_10 -> V_39 -> V_40 -> V_41 ( V_10 -> V_39 , ( char * ) V_93 ,
V_96 + ( V_108 * sizeof( unsigned long ) ) , & V_31 ) ;
}
}
if ( F_18 ( V_94 ) ) {
F_2 ( L_41 , ( int ) - V_94 ) ;
F_36 ( V_92 , V_69 + V_96 + V_102 +
V_71 * sizeof( unsigned long ) ) ;
V_32 = V_94 ;
goto V_119;
}
}
if ( V_99 & V_120 )
F_2 ( L_42 ,
( int ) V_92 , 0x00ffffff & F_26 ( V_91 -> V_137 ) , F_26 ( V_91 -> V_113 ) ) ;
V_70 = V_92 + sizeof ( struct V_90 ) ;
V_109 = V_92 + V_69 ;
if ( V_66 == 0 ) {
V_3 -> V_20 -> V_70 = V_70 ;
V_3 -> V_20 -> V_109 = V_109 ;
V_3 -> V_20 -> V_68 = V_93 ;
V_3 -> V_20 -> V_87 = V_93 + V_96 ;
V_3 -> V_20 -> V_67 = V_93 + V_96 + V_97 ;
V_3 -> V_20 -> V_138 = ( V_3 -> V_20 -> V_67 + 3 ) & ~ 3 ;
V_3 -> V_20 -> V_139 . V_140 = V_100 + V_101 - V_98 ;
}
if ( V_99 & V_120 )
F_2 ( L_43 ,
V_66 ? L_44 : L_45 , V_10 -> V_121 ,
( int ) V_70 , ( int ) V_109 ,
( int ) V_93 ,
( int ) ( V_93 + V_96 ) ,
( int ) ( V_93 + V_96 ) ,
( int ) ( ( ( V_93 + V_96 + V_97 ) + 3 ) & ~ 3 ) ) ;
V_69 -= sizeof( struct V_90 ) ;
V_88 -> V_73 [ V_66 ] . V_70 = V_70 ;
V_88 -> V_73 [ V_66 ] . V_68 = V_93 ;
V_88 -> V_73 [ V_66 ] . V_67 = V_93 + V_96 + V_97 ;
V_88 -> V_73 [ V_66 ] . V_69 = V_69 ;
V_88 -> V_73 [ V_66 ] . V_74 = 1 ;
V_88 -> V_73 [ V_66 ] . V_137 = ( 0x00ffffff & F_26 ( V_91 -> V_137 ) ) + V_92 ;
V_88 -> V_73 [ V_66 ] . V_75 = F_26 ( V_91 -> V_75 ) ;
if ( V_99 & V_141 ) {
for ( V_104 = ( unsigned long * ) V_93 ; * V_104 != 0xffffffff ; V_104 ++ ) {
unsigned long V_65 ;
if ( * V_104 ) {
V_65 = F_16 ( * V_104 , V_88 , V_66 , 0 ) ;
if ( V_65 == V_77 ) {
V_32 = - V_45 ;
goto V_119;
}
* V_104 = V_65 ;
}
}
}
if ( V_107 > V_123 ) {
unsigned long V_142 = 0 ;
for ( V_106 = 0 ; V_106 < V_108 ; V_106 ++ ) {
unsigned long V_65 , V_143 ;
V_143 = F_26 ( V_83 [ V_106 ] ) ;
if ( F_38 ( V_143 , & V_142 ) )
continue;
V_65 = F_39 ( V_143 ) ;
V_104 = ( unsigned long * ) F_16 ( V_65 , V_88 , V_66 , 1 ) ;
if ( V_104 == ( unsigned long * ) V_77 ) {
V_32 = - V_45 ;
goto V_119;
}
V_65 = F_40 ( V_104 , V_143 , V_99 ,
& V_142 ) ;
if ( V_65 != 0 ) {
if ( ( V_99 & V_141 ) == 0 )
V_65 = F_26 ( V_65 ) ;
V_65 = F_16 ( V_65 , V_88 , V_66 , 0 ) ;
if ( V_65 == V_77 ) {
V_32 = - V_45 ;
goto V_119;
}
F_41 ( V_104 , V_65 , V_143 ) ;
}
}
} else {
for ( V_106 = 0 ; V_106 < V_108 ; V_106 ++ )
F_22 ( F_26 ( V_83 [ V_106 ] ) ) ;
}
F_42 ( V_70 , V_109 ) ;
memset ( ( void * ) ( V_93 + V_96 ) , 0 , V_97 +
( V_100 + V_101 - V_98 -
V_88 -> V_73 [ V_66 ] . V_67 ) +
V_98 ) ;
return 0 ;
V_119:
return V_32 ;
}
static int F_19 ( int V_66 , struct V_62 * V_144 )
{
struct V_9 V_10 ;
int V_145 ;
char V_29 [ 16 ] ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
sprintf ( V_29 , L_46 , V_66 ) ;
V_10 . V_121 = V_29 ;
V_10 . V_39 = F_43 ( V_10 . V_121 ) ;
V_145 = F_44 ( V_10 . V_39 ) ;
if ( F_45 ( V_10 . V_39 ) )
return V_145 ;
V_10 . V_146 = F_46 () ;
V_145 = - V_36 ;
if ( ! V_10 . V_146 )
goto V_147;
V_10 . V_148 = 1 ;
V_145 = F_47 ( & V_10 ) ;
if ( ! F_18 ( V_145 ) )
V_145 = F_25 ( & V_10 , V_144 , V_66 , NULL ) ;
F_48 ( V_10 . V_146 ) ;
V_147:
F_49 ( V_10 . V_39 ) ;
F_50 ( V_10 . V_39 ) ;
return ( V_145 ) ;
}
static int F_51 ( struct V_9 * V_10 , struct V_149 * V_150 )
{
struct V_62 V_88 ;
unsigned long V_14 = V_10 -> V_14 ;
unsigned long V_98 ;
unsigned long V_151 ;
unsigned long * V_13 ;
int V_145 ;
int V_106 , V_152 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
#define F_52 (PAGE_SIZE * MAX_ARG_PAGES - sizeof(void *))
V_98 = F_52 - V_10 -> V_14 ;
V_98 += ( V_10 -> V_15 + 1 ) * sizeof( char * ) ;
V_98 += ( V_10 -> V_16 + 1 ) * sizeof( char * ) ;
V_98 += V_19 - 1 ;
V_145 = F_25 ( V_10 , & V_88 , 0 , & V_98 ) ;
if ( F_18 ( V_145 ) )
return V_145 ;
for ( V_106 = 0 ; V_106 < V_71 ; V_106 ++ )
if ( V_88 . V_73 [ V_106 ] . V_74 )
for ( V_152 = 0 ; V_152 < V_71 ; V_152 ++ )
( - ( V_152 + 1 ) ) [ ( unsigned long * ) ( V_88 . V_73 [ V_106 ] . V_68 ) ] =
( V_88 . V_73 [ V_152 ] . V_74 ) ?
V_88 . V_73 [ V_152 ] . V_68 : V_153 ;
F_53 ( V_10 ) ;
F_54 ( & V_154 ) ;
V_14 = ( ( V_3 -> V_20 -> V_139 . V_140 + V_98 + 3 ) & ~ 3 ) - 4 ;
F_8 ( L_47 , ( int ) V_14 ) ;
for ( V_106 = F_52 - 1 ; V_106 >= V_10 -> V_14 ; V_106 -- )
* ( char * ) -- V_14 =
( ( char * ) F_55 ( V_10 -> V_155 [ V_106 / V_156 ] ) ) [ V_106 % V_156 ] ;
V_13 = ( unsigned long * ) F_3 ( V_14 , V_10 ) ;
V_151 = V_88 . V_73 [ 0 ] . V_137 ;
#ifdef F_17
for ( V_106 = V_71 - 1 ; V_106 > 0 ; V_106 -- ) {
if ( V_88 . V_73 [ V_106 ] . V_74 ) {
-- V_13 ; F_5 ( V_151 , V_13 ) ;
V_151 = V_88 . V_73 [ V_106 ] . V_137 ;
}
}
#endif
V_3 -> V_20 -> V_157 = ( unsigned long ) V_13 ;
#ifdef F_56
F_56 ( V_150 ) ;
#endif
F_8 ( L_48 ,
( int ) V_150 , ( int ) V_151 , ( int ) V_3 -> V_20 -> V_157 ) ;
F_57 ( V_150 , V_151 , V_3 -> V_20 -> V_157 ) ;
return 0 ;
}
static int T_4 F_58 ( void )
{
F_59 ( & V_154 ) ;
return 0 ;
}
