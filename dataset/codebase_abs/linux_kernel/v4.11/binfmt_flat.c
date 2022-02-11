static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_3 -> V_4 , V_3 -> V_5 , V_2 -> V_6 -> V_7 ) ;
return 1 ;
}
static int F_3 ( struct V_8 * V_9 , unsigned long V_10 )
{
char T_1 * V_11 ;
unsigned long T_1 * V_12 ;
long V_13 , V_14 ;
V_11 = ( char T_1 * ) V_10 ;
V_12 = ( unsigned long T_1 * ) V_3 -> V_15 -> V_16 ;
V_12 -= V_9 -> V_17 + 1 ;
V_12 -= V_9 -> V_18 + 1 ;
V_12 -= F_4 () ? 2 : 0 ;
V_12 -= 1 ;
V_3 -> V_15 -> V_16 = ( unsigned long ) V_12 & - V_19 ;
V_12 = ( unsigned long T_1 * ) V_3 -> V_15 -> V_16 ;
F_5 ( V_9 -> V_18 , V_12 ++ ) ;
if ( F_4 () ) {
unsigned long V_20 , V_21 ;
V_20 = ( unsigned long ) ( V_12 + 2 ) ;
V_21 = ( unsigned long ) ( V_12 + 2 + V_9 -> V_18 + 1 ) ;
F_5 ( V_20 , V_12 ++ ) ;
F_5 ( V_21 , V_12 ++ ) ;
}
V_3 -> V_15 -> V_10 = ( unsigned long ) V_11 ;
for ( V_13 = V_9 -> V_18 ; V_13 > 0 ; V_13 -- ) {
F_5 ( ( unsigned long ) V_11 , V_12 ++ ) ;
V_14 = F_6 ( V_11 , V_22 ) ;
if ( ! V_14 || V_14 > V_22 )
return - V_23 ;
V_11 += V_14 ;
}
F_5 ( 0 , V_12 ++ ) ;
V_3 -> V_15 -> V_24 = ( unsigned long ) V_11 ;
V_3 -> V_15 -> V_25 = ( unsigned long ) V_11 ;
for ( V_13 = V_9 -> V_17 ; V_13 > 0 ; V_13 -- ) {
F_5 ( ( unsigned long ) V_11 , V_12 ++ ) ;
V_14 = F_6 ( V_11 , V_22 ) ;
if ( ! V_14 || V_14 > V_22 )
return - V_23 ;
V_11 += V_14 ;
}
F_5 ( 0 , V_12 ++ ) ;
V_3 -> V_15 -> V_26 = ( unsigned long ) V_11 ;
return 0 ;
}
static int F_7 (
struct V_8 * V_9 ,
unsigned long V_27 ,
char * V_28 ,
long V_14 ,
int V_29 )
{
unsigned char * V_30 ;
T_2 V_31 ;
T_3 V_32 ;
int V_33 , V_34 ;
F_8 ( L_2 , V_27 , V_28 , V_14 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = F_9 ( F_10 () , V_36 ) ;
if ( V_31 . V_35 == NULL ) {
F_8 ( L_3 ) ;
return - V_37 ;
}
V_30 = F_9 ( V_38 , V_36 ) ;
if ( V_30 == NULL ) {
F_8 ( L_4 ) ;
V_34 = - V_37 ;
goto V_39;
}
V_32 = V_27 ;
V_33 = F_11 ( V_9 -> V_40 , V_27 , V_30 , V_38 ) ;
V_31 . V_41 = V_30 ;
V_31 . V_42 = V_33 ;
V_31 . V_43 = 0 ;
V_32 += V_33 ;
V_34 = - V_44 ;
if ( V_33 < 10 ) {
F_8 ( L_5 ) ;
goto V_45;
}
if ( ( V_30 [ 0 ] != 037 ) || ( ( V_30 [ 1 ] != 0213 ) && ( V_30 [ 1 ] != 0236 ) ) ) {
F_8 ( L_6 ) ;
goto V_45;
}
if ( V_30 [ 2 ] != 8 ) {
F_8 ( L_7 ) ;
goto V_45;
}
if ( ( V_30 [ 3 ] & V_46 ) || ( V_30 [ 3 ] & V_47 ) ||
( V_30 [ 3 ] & V_48 ) ) {
F_8 ( L_8 ) ;
goto V_45;
}
V_33 = 10 ;
if ( V_30 [ 3 ] & V_49 ) {
V_33 += 2 + V_30 [ 10 ] + ( V_30 [ 11 ] << 8 ) ;
if ( F_12 ( V_33 >= V_38 ) ) {
F_8 ( L_9 ) ;
goto V_45;
}
}
if ( V_30 [ 3 ] & V_50 ) {
while ( V_33 < V_38 && V_30 [ V_33 ++ ] != 0 )
;
if ( F_12 ( V_33 == V_38 ) ) {
F_8 ( L_10 ) ;
goto V_45;
}
}
if ( V_30 [ 3 ] & V_51 ) {
while ( V_33 < V_38 && V_30 [ V_33 ++ ] != 0 )
;
if ( F_12 ( V_33 == V_38 ) ) {
F_8 ( L_11 ) ;
goto V_45;
}
}
V_31 . V_41 += V_33 ;
V_31 . V_42 -= V_33 ;
V_31 . V_52 = V_28 ;
V_31 . V_53 = V_14 ;
V_31 . V_54 = 0 ;
if ( F_13 ( & V_31 , - V_55 ) != V_56 ) {
F_8 ( L_12 ) ;
goto V_45;
}
while ( ( V_33 = F_14 ( & V_31 , V_57 ) ) == V_56 ) {
V_33 = F_11 ( V_9 -> V_40 , V_32 , V_30 , V_38 ) ;
if ( V_33 <= 0 )
break;
V_14 -= V_33 ;
V_31 . V_41 = V_30 ;
V_31 . V_42 = V_33 ;
V_31 . V_43 = 0 ;
V_32 += V_33 ;
}
if ( V_33 < 0 ) {
F_8 ( L_13 ,
V_33 , V_31 . V_58 ) ;
goto V_59;
}
V_34 = 0 ;
V_59:
F_15 ( & V_31 ) ;
V_45:
F_16 ( V_30 ) ;
V_39:
F_16 ( V_31 . V_35 ) ;
return V_34 ;
}
static unsigned long
F_17 ( unsigned long V_60 , struct V_61 * V_11 , int V_62 , int V_63 )
{
unsigned long V_64 ;
int V_65 ;
unsigned long V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
#ifdef F_18
if ( V_60 == 0 )
V_65 = V_62 ;
else {
V_65 = ( V_60 >> 24 ) & 0xff ;
V_60 &= 0x00ffffff ;
}
if ( V_65 >= V_70 ) {
F_19 ( L_14 , V_60 , V_65 ) ;
goto V_71;
}
if ( V_62 != V_65 ) {
if ( V_63 ) {
F_19 ( L_15
L_16 , V_60 , V_62 , V_65 ) ;
goto V_71;
} else if ( ! V_11 -> V_72 [ V_65 ] . V_73 &&
F_20 ( V_65 , V_11 ) < 0 ) {
F_19 ( L_17 , V_65 ) ;
goto V_71;
}
if ( V_11 -> V_72 [ V_65 ] . V_74 && V_11 -> V_72 [ V_62 ] . V_74 &&
V_11 -> V_72 [ V_62 ] . V_74 < V_11 -> V_72 [ V_65 ] . V_74 ) {
F_19 ( L_18 , V_65 , V_62 ) ;
goto V_71;
}
}
#else
V_65 = 0 ;
#endif
V_66 = V_11 -> V_72 [ V_65 ] . V_66 ;
V_67 = V_11 -> V_72 [ V_65 ] . V_67 ;
V_69 = V_11 -> V_72 [ V_65 ] . V_69 ;
V_68 = V_11 -> V_72 [ V_65 ] . V_68 ;
if ( ! F_21 ( V_60 , V_66 - V_67 + V_68 ) ) {
F_19 ( L_19 ,
V_60 , V_66 - V_67 + V_68 , V_68 ) ;
goto V_71;
}
if ( V_60 < V_68 )
V_64 = V_60 + V_69 ;
else
V_64 = V_60 - V_68 + V_67 ;
return V_64 ;
V_71:
F_22 ( L_20 , V_3 -> V_4 ) ;
F_23 ( V_75 , V_3 , 0 ) ;
return V_76 ;
}
static void F_24 ( unsigned long V_77 )
{
static const char * V_78 [] = { L_21 , L_22 , L_23 , L_24 } ;
T_4 V_60 ;
unsigned long T_1 * V_79 ;
unsigned long V_80 ;
V_60 . V_81 = V_77 ;
#if F_25 ( V_82 )
V_79 = ( unsigned long T_1 * ) ( V_3 -> V_15 -> V_69 + V_60 . V_83 . V_27 ) ;
#else
V_79 = ( unsigned long T_1 * ) ( V_3 -> V_15 -> V_67 + V_60 . V_83 . V_27 ) ;
#endif
F_26 ( V_80 , V_79 ) ;
F_8 ( L_25
L_26 ,
V_60 . V_83 . V_27 , V_79 , V_80 , V_78 [ V_60 . V_83 . type ] ) ;
switch ( V_60 . V_83 . type ) {
case V_84 :
V_80 += V_3 -> V_15 -> V_69 ;
break;
case V_85 :
V_80 += V_3 -> V_15 -> V_67 ;
break;
case V_86 :
V_80 += V_3 -> V_15 -> V_87 ;
break;
default:
F_19 ( L_27 , V_60 . V_83 . type ) ;
break;
}
F_27 ( V_80 , V_79 ) ;
F_8 ( L_28 , V_80 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_61 * V_88 , int V_65 , unsigned long * V_89 )
{
struct V_90 * V_91 ;
unsigned long V_92 , V_93 , V_94 ;
unsigned long V_68 , V_95 , V_96 , V_97 , V_98 , V_99 ;
unsigned long V_14 , V_100 , V_101 , V_102 , V_103 ;
unsigned long T_1 * V_83 , * V_104 ;
struct V_105 * V_105 ;
int V_13 , V_106 , V_107 ;
T_3 V_32 ;
unsigned long V_69 , V_108 ;
T_5 V_109 ;
int V_33 ;
V_91 = ( (struct V_90 * ) V_9 -> V_30 ) ;
V_105 = F_29 ( V_9 -> V_40 ) ;
V_68 = F_30 ( V_91 -> V_110 ) ;
V_95 = F_30 ( V_91 -> V_111 ) - F_30 ( V_91 -> V_110 ) ;
V_96 = F_30 ( V_91 -> V_112 ) - F_30 ( V_91 -> V_111 ) ;
V_97 = F_30 ( V_91 -> V_113 ) ;
if ( V_89 ) {
V_97 += * V_89 ;
* V_89 = V_97 ;
}
V_107 = F_30 ( V_91 -> V_114 ) ;
V_99 = F_30 ( V_91 -> V_99 ) ;
V_106 = F_30 ( V_91 -> V_106 ) ;
V_98 = V_95 + V_107 * sizeof( unsigned long ) ;
if ( strncmp ( V_91 -> V_115 , L_29 , 4 ) ) {
V_33 = - V_44 ;
goto V_116;
}
if ( V_99 & V_117 )
F_31 ( L_30 , V_9 -> V_118 ) ;
if ( V_106 != V_119 && V_106 != V_120 ) {
F_19 ( L_31 ,
V_106 , V_119 , V_120 ) ;
V_33 = - V_44 ;
goto V_116;
}
if ( V_106 == V_120 && V_65 != 0 ) {
F_19 ( L_32 ,
V_119 ) ;
V_33 = - V_44 ;
goto V_116;
}
if ( ( V_68 | V_95 | V_96 | V_97 | V_98 ) >> 28 ) {
F_19 ( L_33 ) ;
V_33 = - V_44 ;
goto V_116;
}
if ( V_106 == V_120 && F_32 ( V_99 ) )
V_99 = V_121 ;
#ifndef F_33
if ( V_99 & ( V_122 | V_123 ) ) {
F_19 ( L_34 ) ;
V_33 = - V_44 ;
goto V_116;
}
#endif
V_103 = F_34 ( V_124 ) ;
if ( V_103 >= V_125 )
V_103 = ~ 0 ;
if ( V_95 + V_96 > V_103 ) {
V_33 = - V_37 ;
goto V_116;
}
if ( V_65 == 0 ) {
V_33 = F_35 ( V_9 ) ;
if ( V_33 )
goto V_116;
F_36 ( V_126 ) ;
F_37 ( V_9 ) ;
}
V_102 = F_38 (unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long)) ;
if ( ! F_39 ( V_127 ) && ! ( V_99 & ( V_121 | V_122 ) ) ) {
F_8 ( L_35 ) ;
V_92 = F_40 ( V_9 -> V_40 , 0 , V_68 , V_128 | V_129 ,
V_130 | V_131 , 0 ) ;
if ( ! V_92 || F_41 ( V_92 ) ) {
V_33 = V_92 ;
if ( ! V_92 )
V_33 = - V_37 ;
F_19 ( L_36 , V_33 ) ;
goto V_116;
}
V_14 = V_95 + V_102 + V_70 * sizeof( unsigned long ) ;
V_14 = F_42 ( V_14 ) ;
V_94 = F_40 ( NULL , 0 , V_14 ,
V_128 | V_132 | V_129 , V_130 , 0 ) ;
if ( V_94 == 0 || F_41 ( V_94 ) ) {
V_33 = V_94 ;
if ( ! V_94 )
V_33 = - V_37 ;
F_19 ( L_37
L_38 , V_33 ) ;
F_43 ( V_92 , V_68 ) ;
goto V_116;
}
V_93 = F_44 ( V_94 +
V_70 * sizeof( unsigned long ) ,
V_133 ) ;
F_8 ( L_39 ,
V_95 + V_96 + V_97 , V_93 ) ;
V_32 = F_30 ( V_91 -> V_110 ) ;
#ifdef F_33
if ( V_99 & V_123 ) {
V_109 = F_7 ( V_9 , V_32 , ( char * ) V_93 ,
V_98 , 0 ) ;
} else
#endif
{
V_109 = F_45 ( V_9 -> V_40 , V_93 , V_32 ,
V_98 ) ;
}
if ( F_41 ( V_109 ) ) {
V_33 = V_109 ;
F_19 ( L_40 , V_33 ) ;
F_43 ( V_92 , V_68 ) ;
F_43 ( V_94 , V_14 ) ;
goto V_116;
}
V_83 = ( unsigned long T_1 * )
( V_93 + ( F_30 ( V_91 -> V_134 ) - V_68 ) ) ;
V_100 = V_94 ;
V_101 = V_14 ;
} else {
V_14 = V_68 + V_95 + V_102 + V_70 * sizeof( unsigned long ) ;
V_14 = F_42 ( V_14 ) ;
V_92 = F_40 ( NULL , 0 , V_14 ,
V_128 | V_129 | V_132 , V_130 , 0 ) ;
if ( ! V_92 || F_41 ( V_92 ) ) {
V_33 = V_92 ;
if ( ! V_92 )
V_33 = - V_37 ;
F_19 ( L_41
L_38 , V_33 ) ;
goto V_116;
}
V_94 = V_92 + F_30 ( V_91 -> V_110 ) ;
V_93 = F_44 ( V_94 +
V_70 * sizeof( unsigned long ) ,
V_133 ) ;
V_83 = ( unsigned long T_1 * )
( V_93 + ( F_30 ( V_91 -> V_134 ) - V_68 ) ) ;
V_100 = V_92 ;
V_101 = V_14 ;
#ifdef F_33
if ( V_99 & V_122 ) {
#ifndef V_127
V_109 = F_7 ( V_9 , sizeof( struct V_90 ) ,
( ( ( char * ) V_92 ) + sizeof( struct V_90 ) ) ,
( V_68 + V_98
- sizeof( struct V_90 ) ) ,
0 ) ;
memmove ( ( void * ) V_93 , ( void * ) V_94 ,
V_98 ) ;
#else
long V_135 = V_68 - sizeof( struct V_90 ) ;
long V_136 = V_135 + V_98 ;
char * V_137 = F_46 ( V_136 ) ;
if ( ! V_137 ) {
V_109 = - V_37 ;
} else {
V_109 = F_7 ( V_9 , sizeof( struct V_90 ) ,
V_137 , V_136 , 0 ) ;
if ( V_109 == 0 &&
( F_47 ( ( void T_1 * ) V_92 + sizeof( struct V_90 ) ,
V_137 , V_135 ) ||
F_47 ( ( void T_1 * ) V_93 ,
V_137 + V_135 , V_98 ) ) )
V_109 = - V_138 ;
F_48 ( V_137 ) ;
}
#endif
} else if ( V_99 & V_123 ) {
V_109 = F_45 ( V_9 -> V_40 , V_92 , 0 , V_68 ) ;
if ( ! F_41 ( V_109 ) ) {
#ifndef V_127
V_109 = F_7 ( V_9 , V_68 , ( char * ) V_93 ,
V_98 , 0 ) ;
#else
char * V_137 = F_46 ( V_98 ) ;
if ( ! V_137 ) {
V_109 = - V_37 ;
} else {
V_109 = F_7 ( V_9 , V_68 ,
V_137 , V_98 , 0 ) ;
if ( V_109 == 0 &&
F_47 ( ( void T_1 * ) V_93 ,
V_137 , V_98 ) )
V_109 = - V_138 ;
F_48 ( V_137 ) ;
}
#endif
}
} else
#endif
{
V_109 = F_45 ( V_9 -> V_40 , V_92 , 0 , V_68 ) ;
if ( ! F_41 ( V_109 ) )
V_109 = F_45 ( V_9 -> V_40 , V_93 ,
F_30 ( V_91 -> V_110 ) ,
V_98 ) ;
}
if ( F_41 ( V_109 ) ) {
V_33 = V_109 ;
F_19 ( L_42 , V_33 ) ;
F_43 ( V_92 , V_68 + V_95 + V_102 +
V_70 * sizeof( unsigned long ) ) ;
goto V_116;
}
}
V_69 = V_92 + sizeof( struct V_90 ) ;
V_108 = V_92 + V_68 ;
V_68 -= sizeof( struct V_90 ) ;
if ( V_65 == 0 ) {
V_3 -> V_15 -> V_69 = V_69 ;
V_3 -> V_15 -> V_108 = V_108 ;
V_3 -> V_15 -> V_67 = V_93 ;
V_3 -> V_15 -> V_87 = V_93 + V_95 ;
V_3 -> V_15 -> V_66 = V_93 + V_95 + V_96 ;
V_3 -> V_15 -> V_139 = ( V_3 -> V_15 -> V_66 + 3 ) & ~ 3 ;
#ifndef V_127
V_3 -> V_15 -> V_140 . V_141 = V_100 + V_101 - V_97 ;
#endif
}
if ( V_99 & V_117 ) {
F_31 ( L_43 ,
V_92 , 0x00ffffff & F_30 ( V_91 -> V_142 ) , F_30 ( V_91 -> V_110 ) ) ;
F_31 ( L_44 ,
V_65 ? L_45 : L_46 , V_9 -> V_118 ,
V_69 , V_108 , V_93 , V_93 + V_95 ,
V_93 + V_95 , ( V_93 + V_95 + V_96 + 3 ) & ~ 3 ) ;
}
V_88 -> V_72 [ V_65 ] . V_69 = V_69 ;
V_88 -> V_72 [ V_65 ] . V_67 = V_93 ;
V_88 -> V_72 [ V_65 ] . V_66 = V_93 + V_95 + V_96 ;
V_88 -> V_72 [ V_65 ] . V_68 = V_68 ;
V_88 -> V_72 [ V_65 ] . V_73 = 1 ;
V_88 -> V_72 [ V_65 ] . V_142 = ( 0x00ffffff & F_30 ( V_91 -> V_142 ) ) + V_92 ;
V_88 -> V_72 [ V_65 ] . V_74 = F_30 ( V_91 -> V_74 ) ;
if ( V_99 & V_143 ) {
for ( V_104 = ( unsigned long T_1 * ) V_93 ; ; V_104 ++ ) {
unsigned long V_64 , V_144 ;
if ( F_26 ( V_144 , V_104 ) )
return - V_138 ;
if ( V_144 == 0xffffffff )
break;
if ( V_144 ) {
V_64 = F_17 ( V_144 , V_88 , V_65 , 0 ) ;
if ( V_64 == V_76 ) {
V_33 = - V_44 ;
goto V_116;
}
if ( F_27 ( V_64 , V_104 ) )
return - V_138 ;
}
}
}
if ( V_106 > V_120 ) {
unsigned long T_6 V_145 = 0 ;
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ ) {
unsigned long V_64 , V_146 ;
if ( F_26 ( V_146 , V_83 + V_13 ) )
return - V_138 ;
V_146 = F_30 ( V_146 ) ;
if ( F_49 ( V_146 , & V_145 ) )
continue;
V_64 = F_50 ( V_146 ) ;
V_104 = ( unsigned long T_1 * ) F_17 ( V_64 , V_88 , V_65 , 1 ) ;
if ( V_104 == ( unsigned long T_1 * ) V_76 ) {
V_33 = - V_44 ;
goto V_116;
}
V_64 = F_51 ( V_104 , V_146 , V_99 ,
& V_145 ) ;
if ( V_64 != 0 ) {
if ( ( V_99 & V_143 ) == 0 )
V_64 = F_30 ( V_64 ) ;
V_64 = F_17 ( V_64 , V_88 , V_65 , 0 ) ;
if ( V_64 == V_76 ) {
V_33 = - V_44 ;
goto V_116;
}
F_52 ( V_104 , V_64 , V_146 ) ;
}
}
} else {
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ ) {
unsigned long V_146 ;
if ( F_26 ( V_146 , V_83 + V_13 ) )
return - V_138 ;
V_146 = F_30 ( V_146 ) ;
F_24 ( V_146 ) ;
}
}
F_53 ( V_69 , V_108 ) ;
if ( F_54 ( ( void T_1 * ) ( V_93 + V_95 ) , V_96 +
( V_100 + V_101 - V_97 -
V_88 -> V_72 [ V_65 ] . V_66 ) +
V_97 ) )
return - V_138 ;
return 0 ;
V_116:
return V_33 ;
}
static int F_20 ( int V_65 , struct V_61 * V_147 )
{
struct V_8 V_9 ;
int V_148 ;
char V_30 [ 16 ] ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
sprintf ( V_30 , L_47 , V_65 ) ;
V_9 . V_118 = V_30 ;
V_9 . V_40 = F_55 ( V_9 . V_118 ) ;
V_148 = F_56 ( V_9 . V_40 ) ;
if ( F_57 ( V_9 . V_40 ) )
return V_148 ;
V_9 . V_149 = F_58 () ;
V_148 = - V_37 ;
if ( ! V_9 . V_149 )
goto V_150;
V_9 . V_151 = 1 ;
V_148 = F_59 ( & V_9 ) ;
if ( ! V_148 )
V_148 = F_28 ( & V_9 , V_147 , V_65 , NULL ) ;
F_60 ( V_9 . V_149 ) ;
V_150:
F_61 ( V_9 . V_40 ) ;
F_62 ( V_9 . V_40 ) ;
return V_148 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_61 V_88 ;
struct V_152 * V_153 = F_64 () ;
unsigned long V_97 = 0 ;
unsigned long V_154 ;
int V_148 ;
int V_13 , V_155 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
#ifndef V_127
V_97 += V_156 * V_157 - V_9 -> V_11 ;
#endif
V_97 += ( V_9 -> V_18 + 1 ) * sizeof( char * ) ;
V_97 += ( V_9 -> V_17 + 1 ) * sizeof( char * ) ;
V_97 = F_44 ( V_97 , V_19 ) ;
V_148 = F_28 ( V_9 , & V_88 , 0 , & V_97 ) ;
if ( V_148 < 0 )
return V_148 ;
for ( V_13 = 0 ; V_13 < V_70 ; V_13 ++ ) {
if ( ! V_88 . V_72 [ V_13 ] . V_73 )
continue;
for ( V_155 = 0 ; V_155 < V_70 ; V_155 ++ ) {
unsigned long V_80 = V_88 . V_72 [ V_155 ] . V_73 ?
V_88 . V_72 [ V_155 ] . V_67 : V_158 ;
unsigned long T_1 * V_11 = ( unsigned long T_1 * )
V_88 . V_72 [ V_13 ] . V_67 ;
V_11 -= V_155 + 1 ;
if ( F_27 ( V_80 , V_11 ) )
return - V_138 ;
}
}
F_65 ( V_9 ) ;
F_66 ( & V_159 ) ;
#ifdef V_127
V_148 = F_67 ( V_9 , V_160 , V_161 ) ;
if ( ! V_148 )
V_148 = F_3 ( V_9 , V_9 -> V_11 ) ;
#else
V_3 -> V_15 -> V_16 =
( ( V_3 -> V_15 -> V_140 . V_141 + V_97 + 3 ) & ~ 3 ) - 4 ;
F_8 ( L_48 , V_3 -> V_15 -> V_16 ) ;
V_148 = F_68 ( V_9 , & V_3 -> V_15 -> V_16 ) ;
if ( ! V_148 )
V_148 = F_3 ( V_9 , V_3 -> V_15 -> V_16 ) ;
#endif
if ( V_148 )
return V_148 ;
V_154 = V_88 . V_72 [ 0 ] . V_142 ;
#ifdef F_18
for ( V_13 = V_70 - 1 ; V_13 > 0 ; V_13 -- ) {
if ( V_88 . V_72 [ V_13 ] . V_73 ) {
unsigned long T_1 * V_12 ;
V_3 -> V_15 -> V_16 -= sizeof( unsigned long ) ;
V_12 = ( unsigned long T_1 * ) V_3 -> V_15 -> V_16 ;
F_5 ( V_154 , V_12 ) ;
V_154 = V_88 . V_72 [ V_13 ] . V_142 ;
}
}
#endif
#ifdef F_69
F_69 ( V_153 ) ;
#endif
F_8 ( L_49 ,
V_153 , V_154 , V_3 -> V_15 -> V_16 ) ;
F_70 ( V_153 , V_154 , V_3 -> V_15 -> V_16 ) ;
return 0 ;
}
static int T_7 F_71 ( void )
{
F_72 ( & V_159 ) ;
return 0 ;
}
