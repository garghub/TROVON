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
static int F_7 ( struct V_8 * V_9 , T_2 V_27 , char * V_28 ,
long V_14 , int V_29 )
{
unsigned char * V_30 ;
T_3 V_31 ;
int V_32 , V_33 ;
F_8 ( L_2 , V_27 , V_28 , V_14 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = F_9 ( F_10 () , V_35 ) ;
if ( ! V_31 . V_34 )
return - V_36 ;
V_30 = F_9 ( V_37 , V_35 ) ;
if ( ! V_30 ) {
V_33 = - V_36 ;
goto V_38;
}
V_32 = F_11 ( V_9 -> V_39 , V_30 , V_37 , & V_27 ) ;
V_31 . V_40 = V_30 ;
V_31 . V_41 = V_32 ;
V_31 . V_42 = 0 ;
V_33 = - V_43 ;
if ( V_32 < 10 ) {
F_8 ( L_3 ) ;
goto V_44;
}
if ( ( V_30 [ 0 ] != 037 ) || ( ( V_30 [ 1 ] != 0213 ) && ( V_30 [ 1 ] != 0236 ) ) ) {
F_8 ( L_4 ) ;
goto V_44;
}
if ( V_30 [ 2 ] != 8 ) {
F_8 ( L_5 ) ;
goto V_44;
}
if ( ( V_30 [ 3 ] & V_45 ) || ( V_30 [ 3 ] & V_46 ) ||
( V_30 [ 3 ] & V_47 ) ) {
F_8 ( L_6 ) ;
goto V_44;
}
V_32 = 10 ;
if ( V_30 [ 3 ] & V_48 ) {
V_32 += 2 + V_30 [ 10 ] + ( V_30 [ 11 ] << 8 ) ;
if ( F_12 ( V_32 >= V_37 ) ) {
F_8 ( L_7 ) ;
goto V_44;
}
}
if ( V_30 [ 3 ] & V_49 ) {
while ( V_32 < V_37 && V_30 [ V_32 ++ ] != 0 )
;
if ( F_12 ( V_32 == V_37 ) ) {
F_8 ( L_8 ) ;
goto V_44;
}
}
if ( V_30 [ 3 ] & V_50 ) {
while ( V_32 < V_37 && V_30 [ V_32 ++ ] != 0 )
;
if ( F_12 ( V_32 == V_37 ) ) {
F_8 ( L_9 ) ;
goto V_44;
}
}
V_31 . V_40 += V_32 ;
V_31 . V_41 -= V_32 ;
V_31 . V_51 = V_28 ;
V_31 . V_52 = V_14 ;
V_31 . V_53 = 0 ;
if ( F_13 ( & V_31 , - V_54 ) != V_55 ) {
F_8 ( L_10 ) ;
goto V_44;
}
while ( ( V_32 = F_14 ( & V_31 , V_56 ) ) == V_55 ) {
V_32 = F_11 ( V_9 -> V_39 , V_30 , V_37 , & V_27 ) ;
if ( V_32 <= 0 )
break;
V_14 -= V_32 ;
V_31 . V_40 = V_30 ;
V_31 . V_41 = V_32 ;
V_31 . V_42 = 0 ;
}
if ( V_32 < 0 ) {
F_8 ( L_11 ,
V_32 , V_31 . V_57 ) ;
goto V_58;
}
V_33 = 0 ;
V_58:
F_15 ( & V_31 ) ;
V_44:
F_16 ( V_30 ) ;
V_38:
F_16 ( V_31 . V_34 ) ;
return V_33 ;
}
static unsigned long
F_17 ( unsigned long V_59 , struct V_60 * V_11 , int V_61 , int V_62 )
{
unsigned long V_63 ;
int V_64 ;
unsigned long V_65 ;
unsigned long V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
#ifdef F_18
if ( V_59 == 0 )
V_64 = V_61 ;
else {
V_64 = ( V_59 >> 24 ) & 0xff ;
V_59 &= 0x00ffffff ;
}
if ( V_64 >= V_69 ) {
F_19 ( L_12 , V_59 , V_64 ) ;
goto V_70;
}
if ( V_61 != V_64 ) {
if ( V_62 ) {
F_19 ( L_13
L_14 , V_59 , V_61 , V_64 ) ;
goto V_70;
} else if ( ! V_11 -> V_71 [ V_64 ] . V_72 &&
F_20 ( V_64 , V_11 ) < 0 ) {
F_19 ( L_15 , V_64 ) ;
goto V_70;
}
if ( V_11 -> V_71 [ V_64 ] . V_73 && V_11 -> V_71 [ V_61 ] . V_73 &&
V_11 -> V_71 [ V_61 ] . V_73 < V_11 -> V_71 [ V_64 ] . V_73 ) {
F_19 ( L_16 , V_64 , V_61 ) ;
goto V_70;
}
}
#else
V_64 = 0 ;
#endif
V_65 = V_11 -> V_71 [ V_64 ] . V_65 ;
V_66 = V_11 -> V_71 [ V_64 ] . V_66 ;
V_68 = V_11 -> V_71 [ V_64 ] . V_68 ;
V_67 = V_11 -> V_71 [ V_64 ] . V_67 ;
if ( ! F_21 ( V_59 , V_65 - V_66 + V_67 ) ) {
F_19 ( L_17 ,
V_59 , V_65 - V_66 + V_67 , V_67 ) ;
goto V_70;
}
if ( V_59 < V_67 )
V_63 = V_59 + V_68 ;
else
V_63 = V_59 - V_67 + V_66 ;
return V_63 ;
V_70:
F_22 ( L_18 , V_3 -> V_4 ) ;
F_23 ( V_74 , V_3 , 0 ) ;
return V_75 ;
}
static void F_24 ( unsigned long V_76 )
{
static const char * V_77 [] = { L_19 , L_20 , L_21 , L_22 } ;
T_4 V_59 ;
unsigned long T_1 * V_78 ;
unsigned long V_79 ;
V_59 . V_80 = V_76 ;
#if F_25 ( V_81 )
V_78 = ( unsigned long T_1 * ) ( V_3 -> V_15 -> V_68 + V_59 . V_82 . V_83 ) ;
#else
V_78 = ( unsigned long T_1 * ) ( V_3 -> V_15 -> V_66 + V_59 . V_82 . V_83 ) ;
#endif
F_26 ( V_79 , V_78 ) ;
F_8 ( L_23
L_24 ,
V_59 . V_82 . V_83 , V_78 , V_79 , V_77 [ V_59 . V_82 . type ] ) ;
switch ( V_59 . V_82 . type ) {
case V_84 :
V_79 += V_3 -> V_15 -> V_68 ;
break;
case V_85 :
V_79 += V_3 -> V_15 -> V_66 ;
break;
case V_86 :
V_79 += V_3 -> V_15 -> V_87 ;
break;
default:
F_19 ( L_25 , V_59 . V_82 . type ) ;
break;
}
F_27 ( V_79 , V_78 ) ;
F_8 ( L_26 , V_79 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_60 * V_88 , int V_64 , unsigned long * V_89 )
{
struct V_90 * V_91 ;
unsigned long V_92 , V_93 , V_94 ;
T_5 V_67 , V_95 , V_96 , V_97 , V_98 , V_99 ;
unsigned long V_14 , V_100 , V_101 , V_102 , V_103 ;
T_5 T_1 * V_82 , * V_104 ;
struct V_105 * V_105 ;
int V_13 , V_106 , V_107 ;
T_2 V_27 ;
unsigned long V_68 , V_108 ;
T_6 V_109 ;
int V_32 ;
V_91 = ( (struct V_90 * ) V_9 -> V_30 ) ;
V_105 = F_29 ( V_9 -> V_39 ) ;
V_67 = F_30 ( V_91 -> V_110 ) ;
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
if ( strncmp ( V_91 -> V_115 , L_27 , 4 ) ) {
V_32 = - V_43 ;
goto V_116;
}
if ( V_99 & V_117 )
F_31 ( L_28 , V_9 -> V_118 ) ;
if ( V_106 != V_119 && V_106 != V_120 ) {
F_19 ( L_29 ,
V_106 , V_119 , V_120 ) ;
V_32 = - V_43 ;
goto V_116;
}
if ( V_106 == V_120 && V_64 != 0 ) {
F_19 ( L_30 ,
V_119 ) ;
V_32 = - V_43 ;
goto V_116;
}
if ( ( V_67 | V_95 | V_96 | V_97 | V_98 ) >> 28 ) {
F_19 ( L_31 ) ;
V_32 = - V_43 ;
goto V_116;
}
if ( V_106 == V_120 && F_32 ( V_99 ) )
V_99 = V_121 ;
#ifndef F_33
if ( V_99 & ( V_122 | V_123 ) ) {
F_19 ( L_32 ) ;
V_32 = - V_43 ;
goto V_116;
}
#endif
V_103 = F_34 ( V_124 ) ;
if ( V_103 >= V_125 )
V_103 = ~ 0 ;
if ( V_95 + V_96 > V_103 ) {
V_32 = - V_36 ;
goto V_116;
}
if ( V_64 == 0 ) {
V_32 = F_35 ( V_9 ) ;
if ( V_32 )
goto V_116;
F_36 ( V_126 ) ;
F_37 ( V_9 ) ;
}
V_102 = F_38 (unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long)) ;
if ( ! F_39 ( V_127 ) && ! ( V_99 & ( V_121 | V_122 ) ) ) {
F_8 ( L_33 ) ;
V_92 = F_40 ( V_9 -> V_39 , 0 , V_67 , V_128 | V_129 ,
V_130 | V_131 , 0 ) ;
if ( ! V_92 || F_41 ( V_92 ) ) {
V_32 = V_92 ;
if ( ! V_92 )
V_32 = - V_36 ;
F_19 ( L_34 , V_32 ) ;
goto V_116;
}
V_14 = V_95 + V_102 + V_69 * sizeof( unsigned long ) ;
V_14 = F_42 ( V_14 ) ;
V_94 = F_40 ( NULL , 0 , V_14 ,
V_128 | V_132 | V_129 , V_130 , 0 ) ;
if ( V_94 == 0 || F_41 ( V_94 ) ) {
V_32 = V_94 ;
if ( ! V_94 )
V_32 = - V_36 ;
F_19 ( L_35
L_36 , V_32 ) ;
F_43 ( V_92 , V_67 ) ;
goto V_116;
}
V_93 = F_44 ( V_94 +
V_69 * sizeof( unsigned long ) ,
V_133 ) ;
F_8 ( L_37 ,
V_95 + V_96 + V_97 , V_93 ) ;
V_27 = F_30 ( V_91 -> V_110 ) ;
#ifdef F_33
if ( V_99 & V_123 ) {
V_109 = F_7 ( V_9 , V_27 , ( char * ) V_93 ,
V_98 , 0 ) ;
} else
#endif
{
V_109 = F_45 ( V_9 -> V_39 , V_93 , V_27 ,
V_98 ) ;
}
if ( F_41 ( V_109 ) ) {
V_32 = V_109 ;
F_19 ( L_38 , V_32 ) ;
F_43 ( V_92 , V_67 ) ;
F_43 ( V_94 , V_14 ) ;
goto V_116;
}
V_82 = ( T_5 T_1 * )
( V_93 + ( F_30 ( V_91 -> V_134 ) - V_67 ) ) ;
V_100 = V_94 ;
V_101 = V_14 ;
} else {
V_14 = V_67 + V_95 + V_102 + V_69 * sizeof( T_5 ) ;
V_14 = F_42 ( V_14 ) ;
V_92 = F_40 ( NULL , 0 , V_14 ,
V_128 | V_129 | V_132 , V_130 , 0 ) ;
if ( ! V_92 || F_41 ( V_92 ) ) {
V_32 = V_92 ;
if ( ! V_92 )
V_32 = - V_36 ;
F_19 ( L_39
L_36 , V_32 ) ;
goto V_116;
}
V_94 = V_92 + F_30 ( V_91 -> V_110 ) ;
V_93 = F_44 ( V_94 +
V_69 * sizeof( T_5 ) ,
V_133 ) ;
V_82 = ( T_5 T_1 * )
( V_93 + ( F_30 ( V_91 -> V_134 ) - V_67 ) ) ;
V_100 = V_92 ;
V_101 = V_14 ;
#ifdef F_33
if ( V_99 & V_122 ) {
#ifndef V_127
V_109 = F_7 ( V_9 , sizeof( struct V_90 ) ,
( ( ( char * ) V_92 ) + sizeof( struct V_90 ) ) ,
( V_67 + V_98
- sizeof( struct V_90 ) ) ,
0 ) ;
memmove ( ( void * ) V_93 , ( void * ) V_94 ,
V_98 ) ;
#else
long V_135 = V_67 - sizeof( struct V_90 ) ;
long V_136 = V_135 + V_98 ;
char * V_137 = F_46 ( V_136 ) ;
if ( ! V_137 ) {
V_109 = - V_36 ;
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
V_109 = F_45 ( V_9 -> V_39 , V_92 , 0 , V_67 ) ;
if ( ! F_41 ( V_109 ) ) {
#ifndef V_127
V_109 = F_7 ( V_9 , V_67 , ( char * ) V_93 ,
V_98 , 0 ) ;
#else
char * V_137 = F_46 ( V_98 ) ;
if ( ! V_137 ) {
V_109 = - V_36 ;
} else {
V_109 = F_7 ( V_9 , V_67 ,
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
V_109 = F_45 ( V_9 -> V_39 , V_92 , 0 , V_67 ) ;
if ( ! F_41 ( V_109 ) )
V_109 = F_45 ( V_9 -> V_39 , V_93 ,
F_30 ( V_91 -> V_110 ) ,
V_98 ) ;
}
if ( F_41 ( V_109 ) ) {
V_32 = V_109 ;
F_19 ( L_40 , V_32 ) ;
F_43 ( V_92 , V_67 + V_95 + V_102 +
V_69 * sizeof( T_5 ) ) ;
goto V_116;
}
}
V_68 = V_92 + sizeof( struct V_90 ) ;
V_108 = V_92 + V_67 ;
V_67 -= sizeof( struct V_90 ) ;
if ( V_64 == 0 ) {
V_3 -> V_15 -> V_68 = V_68 ;
V_3 -> V_15 -> V_108 = V_108 ;
V_3 -> V_15 -> V_66 = V_93 ;
V_3 -> V_15 -> V_87 = V_93 + V_95 ;
V_3 -> V_15 -> V_65 = V_93 + V_95 + V_96 ;
V_3 -> V_15 -> V_139 = ( V_3 -> V_15 -> V_65 + 3 ) & ~ 3 ;
#ifndef V_127
V_3 -> V_15 -> V_140 . V_141 = V_100 + V_101 - V_97 ;
#endif
}
if ( V_99 & V_117 ) {
F_31 ( L_41 ,
V_92 , 0x00ffffff & F_30 ( V_91 -> V_142 ) , F_30 ( V_91 -> V_110 ) ) ;
F_31 ( L_42 ,
V_64 ? L_43 : L_44 , V_9 -> V_118 ,
V_68 , V_108 , V_93 , V_93 + V_95 ,
V_93 + V_95 , ( V_93 + V_95 + V_96 + 3 ) & ~ 3 ) ;
}
V_88 -> V_71 [ V_64 ] . V_68 = V_68 ;
V_88 -> V_71 [ V_64 ] . V_66 = V_93 ;
V_88 -> V_71 [ V_64 ] . V_65 = V_93 + V_95 + V_96 ;
V_88 -> V_71 [ V_64 ] . V_67 = V_67 ;
V_88 -> V_71 [ V_64 ] . V_72 = 1 ;
V_88 -> V_71 [ V_64 ] . V_142 = ( 0x00ffffff & F_30 ( V_91 -> V_142 ) ) + V_92 ;
V_88 -> V_71 [ V_64 ] . V_73 = F_30 ( V_91 -> V_73 ) ;
if ( V_99 & V_143 ) {
for ( V_104 = ( T_5 T_1 * ) V_93 ; ; V_104 ++ ) {
T_5 V_63 , V_144 ;
if ( F_26 ( V_144 , V_104 ) )
return - V_138 ;
if ( V_144 == 0xffffffff )
break;
if ( V_144 ) {
V_63 = F_17 ( V_144 , V_88 , V_64 , 0 ) ;
if ( V_63 == V_75 ) {
V_32 = - V_43 ;
goto V_116;
}
if ( F_27 ( V_63 , V_104 ) )
return - V_138 ;
}
}
}
if ( V_106 > V_120 ) {
T_5 T_7 V_145 = 0 ;
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ ) {
T_5 V_63 , V_146 ;
if ( F_26 ( V_146 , V_82 + V_13 ) )
return - V_138 ;
V_146 = F_30 ( V_146 ) ;
if ( F_49 ( V_146 , & V_145 ) )
continue;
V_63 = F_50 ( V_146 ) ;
V_104 = ( T_5 T_1 * ) F_17 ( V_63 , V_88 , V_64 , 1 ) ;
if ( V_104 == ( T_5 T_1 * ) V_75 ) {
V_32 = - V_43 ;
goto V_116;
}
V_32 = F_51 ( V_104 , V_146 , V_99 ,
& V_63 , & V_145 ) ;
if ( F_12 ( V_32 ) )
goto V_116;
if ( V_63 != 0 ) {
if ( ( V_99 & V_143 ) == 0 )
V_63 = F_30 ( V_63 ) ;
V_63 = F_17 ( V_63 , V_88 , V_64 , 0 ) ;
if ( V_63 == V_75 ) {
V_32 = - V_43 ;
goto V_116;
}
V_32 = F_52 ( V_104 , V_63 , V_146 ) ;
if ( F_12 ( V_32 ) )
goto V_116;
}
}
} else {
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ ) {
T_5 V_146 ;
if ( F_26 ( V_146 , V_82 + V_13 ) )
return - V_138 ;
V_146 = F_30 ( V_146 ) ;
F_24 ( V_146 ) ;
}
}
F_53 ( V_68 , V_108 ) ;
if ( F_54 ( ( void T_1 * ) ( V_93 + V_95 ) , V_96 +
( V_100 + V_101 - V_97 -
V_88 -> V_71 [ V_64 ] . V_65 ) +
V_97 ) )
return - V_138 ;
return 0 ;
V_116:
return V_32 ;
}
static int F_20 ( int V_64 , struct V_60 * V_147 )
{
struct V_8 V_9 ;
int V_148 ;
char V_30 [ 16 ] ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
sprintf ( V_30 , L_45 , V_64 ) ;
V_9 . V_118 = V_30 ;
V_9 . V_39 = F_55 ( V_9 . V_118 ) ;
V_148 = F_56 ( V_9 . V_39 ) ;
if ( F_57 ( V_9 . V_39 ) )
return V_148 ;
V_9 . V_149 = F_58 () ;
V_148 = - V_36 ;
if ( ! V_9 . V_149 )
goto V_150;
V_9 . V_151 = 1 ;
V_148 = F_59 ( & V_9 ) ;
if ( ! V_148 )
V_148 = F_28 ( & V_9 , V_147 , V_64 , NULL ) ;
F_60 ( V_9 . V_149 ) ;
V_150:
F_61 ( V_9 . V_39 ) ;
F_62 ( V_9 . V_39 ) ;
return V_148 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_60 V_88 ;
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
for ( V_13 = 0 ; V_13 < V_69 ; V_13 ++ ) {
if ( ! V_88 . V_71 [ V_13 ] . V_72 )
continue;
for ( V_155 = 0 ; V_155 < V_69 ; V_155 ++ ) {
unsigned long V_79 = V_88 . V_71 [ V_155 ] . V_72 ?
V_88 . V_71 [ V_155 ] . V_66 : V_158 ;
unsigned long T_1 * V_11 = ( unsigned long T_1 * )
V_88 . V_71 [ V_13 ] . V_66 ;
V_11 -= V_155 + 1 ;
if ( F_27 ( V_79 , V_11 ) )
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
F_8 ( L_46 , V_3 -> V_15 -> V_16 ) ;
V_148 = F_68 ( V_9 , & V_3 -> V_15 -> V_16 ) ;
if ( ! V_148 )
V_148 = F_3 ( V_9 , V_3 -> V_15 -> V_16 ) ;
#endif
if ( V_148 )
return V_148 ;
V_154 = V_88 . V_71 [ 0 ] . V_142 ;
#ifdef F_18
for ( V_13 = V_69 - 1 ; V_13 > 0 ; V_13 -- ) {
if ( V_88 . V_71 [ V_13 ] . V_72 ) {
unsigned long T_1 * V_12 ;
V_3 -> V_15 -> V_16 -= sizeof( unsigned long ) ;
V_12 = ( unsigned long T_1 * ) V_3 -> V_15 -> V_16 ;
F_5 ( V_154 , V_12 ) ;
V_154 = V_88 . V_71 [ V_13 ] . V_142 ;
}
}
#endif
#ifdef F_69
F_69 ( V_153 ) ;
#endif
F_8 ( L_47 ,
V_153 , V_154 , V_3 -> V_15 -> V_16 ) ;
F_70 ( V_153 , V_154 , V_3 -> V_15 -> V_16 ) ;
return 0 ;
}
static int T_8 F_71 ( void )
{
F_72 ( & V_159 ) ;
return 0 ;
}
