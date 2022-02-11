static int T_1 F_1 ( unsigned char * V_1 , int V_2 )
{
int V_3 = 0 ;
while ( V_2 -- )
V_3 += * V_1 ++ ;
return V_3 & 0xFF ;
}
int T_1 F_2 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ;
}
static void T_1 F_3 ( struct V_4 * V_5 )
{
int V_6 ;
char * V_7 = L_1 ;
if ( ! ( V_5 -> V_8 & V_9 ) ) {
V_10 ++ ;
return;
}
V_6 = V_11 . V_12 . V_13 ( V_5 ) ;
if ( V_5 -> V_8 & V_14 ) {
V_7 = L_2 ;
V_15 = V_5 -> V_6 ;
}
F_4 ( V_16 L_3 , V_5 -> V_6 , V_7 ) ;
F_5 ( V_6 , V_5 -> V_17 ) ;
}
void T_1 F_6 ( struct V_18 * V_5 , char * V_19 )
{
memcpy ( V_19 , V_5 -> V_20 , 6 ) ;
V_19 [ 6 ] = 0 ;
F_7 ( V_21 , L_4 , V_5 -> V_22 , V_19 ) ;
}
static void T_1 F_8 ( struct V_18 * V_5 )
{
char V_19 [ 7 ] ;
V_11 . V_12 . V_23 ( V_5 , V_19 ) ;
#if V_24 < 256
if ( V_5 -> V_22 >= V_24 ) {
F_4 ( V_25 L_5
L_6 ,
V_5 -> V_22 , V_19 , V_24 - 1 ) ;
return;
}
#endif
F_9 ( V_5 -> V_22 , V_26 ) ;
if ( strncmp ( V_19 , V_27 , sizeof( V_27 ) - 1 ) == 0 ) {
#if F_10 ( V_28 ) || F_10 ( V_29 )
V_30 [ V_5 -> V_22 ] = V_31 ;
#endif
} else if ( strncmp ( V_19 , V_32 , sizeof( V_32 ) - 1 ) == 0 ) {
if ( V_11 . V_12 . V_33 )
V_11 . V_12 . V_33 ( V_5 ) ;
F_11 ( V_5 -> V_22 , V_26 ) ;
#if F_10 ( V_28 ) || F_10 ( V_29 )
V_30 [ V_5 -> V_22 ] = V_34 ;
} else if ( strncmp ( V_19 , V_35 , sizeof( V_35 ) - 1 ) == 0 ) {
V_30 [ V_5 -> V_22 ] = V_36 ;
} else if ( strncmp ( V_19 , V_37 , sizeof( V_37 ) - 1 ) == 0 ) {
V_30 [ V_5 -> V_22 ] = V_38 ;
#endif
} else
F_4 ( V_25 L_7 , V_19 ) ;
}
static void T_1 F_12 ( struct V_39 * V_5 )
{
if ( V_5 -> V_40 & V_41 )
F_13 ( V_5 -> V_6 , V_5 -> V_42 , V_43 ) ;
}
static void T_1 F_14 ( struct V_44 * V_45 )
{
F_7 ( V_21 , L_8
L_9 ,
V_45 -> V_46 , V_45 -> V_47 & 3 ,
( V_45 -> V_47 >> 2 ) & 3 , V_45 -> V_48 ,
V_45 -> V_49 , V_45 -> V_50 , V_45 -> V_51 ) ;
}
static inline void T_1 F_8 ( struct V_18 * V_5 ) {}
static inline void T_1 F_12 ( struct V_39 * V_5 ) {}
static void T_1 F_15 ( struct V_52 * V_5 )
{
F_7 ( V_21 , L_10
L_11 ,
V_5 -> V_46 , V_5 -> V_47 & 3 , ( V_5 -> V_47 >> 2 ) & 3 , V_5 -> V_53 ,
V_5 -> V_49 , V_5 -> V_54 , V_5 -> V_55 ) ;
}
static int T_1 F_16 ( struct V_56 * V_57 , char * V_58 , char * V_19 )
{
if ( memcmp ( V_57 -> V_59 , V_60 , 4 ) ) {
F_4 ( V_61 L_12 ,
V_57 -> V_59 [ 0 ] , V_57 -> V_59 [ 1 ] ,
V_57 -> V_59 [ 2 ] , V_57 -> V_59 [ 3 ] ) ;
return 0 ;
}
if ( F_1 ( ( unsigned char * ) V_57 , V_57 -> V_62 ) ) {
F_4 ( V_61 L_13 ) ;
return 0 ;
}
if ( V_57 -> V_63 != 0x01 && V_57 -> V_63 != 0x04 ) {
F_4 ( V_61 L_14 ,
V_57 -> V_63 ) ;
return 0 ;
}
if ( ! V_57 -> V_64 ) {
F_4 ( V_61 L_15 ) ;
return 0 ;
}
memcpy ( V_58 , V_57 -> V_58 , 8 ) ;
V_58 [ 8 ] = 0 ;
F_4 ( V_16 L_16 , V_58 ) ;
memcpy ( V_19 , V_57 -> V_65 , 12 ) ;
V_19 [ 12 ] = 0 ;
F_4 ( V_16 L_17 , V_19 ) ;
F_4 ( V_16 L_18 , V_57 -> V_64 ) ;
return 1 ;
}
static void F_17 ( unsigned char * * V_66 , int * V_67 , int V_68 )
{
* V_66 += V_68 ;
* V_67 += V_68 ;
}
static void T_1 F_18 ( struct V_56 * V_57 , unsigned char * V_69 )
{
F_4 ( V_61 L_19
L_20 , * V_69 ) ;
F_19 ( V_61 , L_21 , V_70 , 16 ,
1 , V_57 , V_57 -> V_62 , 1 ) ;
}
void T_1 F_20 ( struct V_56 * V_57 ) { }
static int T_1 F_21 ( struct V_56 * V_57 , unsigned V_71 )
{
char V_19 [ 16 ] ;
char V_58 [ 10 ] ;
int V_67 = sizeof( * V_57 ) ;
unsigned char * V_69 = ( ( unsigned char * ) V_57 ) + V_67 ;
if ( ! F_16 ( V_57 , V_58 , V_19 ) )
return 0 ;
#ifdef F_22
F_23 ( V_57 , V_58 , V_19 ) ;
#endif
if ( ! V_72 )
F_24 ( V_57 -> V_64 ) ;
if ( V_71 )
return 1 ;
if ( V_57 -> V_73 )
V_11 . V_12 . V_74 ( V_57 ) ;
V_11 . V_12 . V_75 ( 0 ) ;
while ( V_67 < V_57 -> V_62 ) {
switch ( * V_69 ) {
case V_76 :
if ( ! V_72 )
F_3 ( (struct V_4 * ) V_69 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_4 ) ) ;
break;
case V_77 :
F_8 ( (struct V_18 * ) V_69 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_18 ) ) ;
break;
case V_78 :
F_12 ( (struct V_39 * ) V_69 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_39 ) ) ;
break;
case V_79 :
F_25 ( (struct V_44 * ) V_69 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_44 ) ) ;
break;
case V_80 :
F_15 ( (struct V_52 * ) V_69 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_52 ) ) ;
break;
default:
F_18 ( V_57 , V_69 ) ;
V_67 = V_57 -> V_62 ;
break;
}
V_11 . V_12 . V_75 ( 1 ) ;
}
if ( ! V_81 )
F_4 ( V_61 L_22 ) ;
return V_81 ;
}
static int T_1 F_26 ( unsigned int V_82 )
{
unsigned int V_83 ;
V_83 = 0x4d0 + ( V_82 >> 3 ) ;
return ( F_27 ( V_83 ) >> ( V_82 & 7 ) ) & 1 ;
}
static void T_1 F_28 ( int V_84 )
{
struct V_44 V_85 ;
int V_86 ;
int V_87 = 0 ;
V_85 . type = V_79 ;
V_85 . V_47 = 0 ;
V_85 . V_48 = 0 ;
V_85 . V_50 = F_29 ( 0 ) ;
V_85 . V_46 = V_88 ;
if ( V_84 == 5 ) {
F_4 ( V_16 L_23
L_24 ) ;
if ( F_26 ( 0 ) || F_26 ( 1 ) || F_26 ( 2 ) ||
F_26 ( 13 ) )
F_4 ( V_61 L_25
L_26 ) ;
else {
F_4 ( V_16
L_27 ) ;
V_87 = 1 ;
}
}
for ( V_86 = 0 ; V_86 < 16 ; V_86 ++ ) {
switch ( V_84 ) {
case 2 :
if ( V_86 == 0 || V_86 == 13 )
continue;
default:
if ( V_86 == 2 )
continue;
}
if ( V_87 ) {
if ( F_26 ( V_86 ) )
V_85 . V_47 = 13 ;
else
V_85 . V_47 = 0 ;
}
V_85 . V_49 = V_86 ;
V_85 . V_51 = V_86 ? V_86 : 2 ;
F_25 ( & V_85 ) ;
}
V_85 . V_46 = V_89 ;
V_85 . V_49 = 0 ;
V_85 . V_51 = 0 ;
F_25 ( & V_85 ) ;
}
static void T_1 F_30 ( int V_84 )
{
struct V_39 V_90 ;
struct V_18 V_91 ;
V_91 . type = V_77 ;
V_91 . V_22 = 0 ;
switch ( V_84 ) {
default:
F_4 ( V_61 L_28 ,
V_84 ) ;
case 1 :
case 5 :
memcpy ( V_91 . V_20 , L_29 , 6 ) ;
break;
case 2 :
case 6 :
case 3 :
memcpy ( V_91 . V_20 , L_30 , 6 ) ;
break;
case 4 :
case 7 :
memcpy ( V_91 . V_20 , L_31 , 6 ) ;
}
F_8 ( & V_91 ) ;
if ( V_84 > 4 ) {
V_91 . V_22 = 1 ;
memcpy ( V_91 . V_20 , L_32 , 6 ) ;
F_8 ( & V_91 ) ;
}
V_90 . type = V_78 ;
V_90 . V_6 = 2 ;
V_90 . V_17 = V_84 > 4 ? 0x10 : 0x01 ;
V_90 . V_40 = V_41 ;
V_90 . V_42 = V_92 ;
F_12 ( & V_90 ) ;
F_28 ( V_84 ) ;
}
static inline void T_1 F_30 ( int V_84 ) { }
static inline void T_1 F_31 ( int V_84 )
{
struct V_4 V_93 ;
struct V_52 V_94 ;
int V_95 [ 2 ] = { V_89 , V_96 } ;
int V_86 ;
V_97 = V_98 ;
V_93 . type = V_76 ;
V_93 . V_17 = V_84 > 4 ? 0x10 : 0x01 ;
V_93 . V_8 = V_9 ;
V_93 . V_99 = ( V_100 . V_101 << 8 ) |
( V_100 . V_102 << 4 ) | V_100 . V_103 ;
V_93 . V_104 = V_100 . V_105 [ 0 ] ;
V_93 . V_106 [ 0 ] = 0 ;
V_93 . V_106 [ 1 ] = 0 ;
for ( V_86 = 0 ; V_86 < 2 ; V_86 ++ ) {
V_93 . V_6 = V_86 ;
F_3 ( & V_93 ) ;
}
F_30 ( V_84 ) ;
V_94 . type = V_80 ;
V_94 . V_47 = 0 ;
V_94 . V_53 = 0 ;
V_94 . V_49 = 0 ;
V_94 . V_54 = V_107 ;
for ( V_86 = 0 ; V_86 < 2 ; V_86 ++ ) {
V_94 . V_46 = V_95 [ V_86 ] ;
V_94 . V_55 = V_86 ;
F_15 ( & V_94 ) ;
}
}
static unsigned long T_1 F_32 ( unsigned long V_108 )
{
struct V_56 * V_57 ;
unsigned long V_68 ;
V_57 = F_33 ( V_108 , V_109 ) ;
V_68 = V_57 -> V_62 ;
F_34 ( V_57 , V_109 ) ;
F_7 ( V_21 , L_33 , V_108 , V_108 + V_68 ) ;
return V_68 ;
}
static int T_1 F_35 ( struct V_110 * V_111 , unsigned int V_71 )
{
struct V_56 * V_57 ;
unsigned long V_68 ;
V_68 = F_32 ( V_111 -> V_108 ) ;
V_57 = F_33 ( V_111 -> V_108 , V_68 ) ;
if ( ! F_21 ( V_57 , V_71 ) ) {
#ifdef F_36
V_112 = 0 ;
#endif
F_4 ( V_61 L_34
L_35 ) ;
F_34 ( V_57 , V_68 ) ;
return - 1 ;
}
F_34 ( V_57 , V_68 ) ;
if ( V_71 )
return - 1 ;
#ifdef F_37
if ( ! V_113 ) {
struct V_18 V_91 ;
F_4 ( V_61 L_36
L_37 ) ;
V_91 . type = V_77 ;
V_91 . V_22 = 0 ;
memcpy ( V_91 . V_20 , L_29 , 6 ) ;
F_8 ( & V_91 ) ;
F_28 ( 0 ) ;
}
#endif
return 0 ;
}
void T_1 F_38 ( unsigned int V_71 )
{
struct V_110 * V_111 = V_114 ;
if ( ! V_111 )
return;
if ( V_72 && V_71 )
return;
if ( V_72 && V_115 )
return;
F_4 ( V_16 L_38 ,
V_111 -> V_116 ) ;
#if F_10 ( F_36 ) && F_10 ( F_22 )
if ( V_111 -> V_117 & ( 1 << 7 ) ) {
F_4 ( V_16 L_39 ) ;
V_118 = 1 ;
} else {
F_4 ( V_16 L_40 ) ;
V_118 = 0 ;
}
#endif
if ( V_111 -> V_119 != 0 ) {
if ( V_71 ) {
V_97 = V_98 ;
return;
}
F_4 ( V_16 L_41 ,
V_111 -> V_119 ) ;
F_31 ( V_111 -> V_119 ) ;
} else if ( V_111 -> V_108 ) {
if ( F_35 ( V_111 , V_71 ) )
return;
} else
F_39 () ;
if ( ! V_71 )
F_4 ( V_16 L_42 , V_81 ) ;
}
static void T_1 F_40 ( struct V_110 * V_111 )
{
unsigned long V_68 = F_32 ( V_111 -> V_108 ) ;
F_41 ( V_111 -> V_108 , V_111 -> V_108 + V_68 , L_43 ) ;
}
static int T_1 F_42 ( unsigned long V_120 , unsigned long V_62 )
{
unsigned int * V_121 = F_43 ( V_120 ) ;
struct V_110 * V_111 ;
unsigned long V_122 ;
F_7 ( V_21 , L_44 ,
V_121 , V_62 ) ;
F_44 ( sizeof( * V_111 ) != 16 ) ;
while ( V_62 > 0 ) {
V_111 = (struct V_110 * ) V_121 ;
if ( ( * V_121 == V_123 ) &&
( V_111 -> V_62 == 1 ) &&
! F_1 ( ( unsigned char * ) V_121 , 16 ) &&
( ( V_111 -> V_116 == 1 )
|| ( V_111 -> V_116 == 4 ) ) ) {
#ifdef F_36
V_112 = 1 ;
#endif
V_114 = V_111 ;
F_4 ( V_16 L_45 ,
V_111 , ( V_124 ) F_45 ( V_111 ) ) ;
V_122 = F_45 ( V_111 ) ;
F_41 ( V_122 , V_122 + sizeof( * V_111 ) , L_46 ) ;
if ( V_111 -> V_108 )
F_40 ( V_111 ) ;
return 1 ;
}
V_121 += 4 ;
V_62 -= 16 ;
}
return 0 ;
}
void T_1 F_46 ( void )
{
unsigned int V_125 ;
if ( F_42 ( 0x0 , 0x400 ) ||
F_42 ( 639 * 0x400 , 0x400 ) ||
F_42 ( 0xF0000 , 0x10000 ) )
return;
V_125 = F_47 () ;
if ( V_125 )
F_42 ( V_125 , 0x400 ) ;
}
static int T_1 F_48 ( struct V_44 * V_5 )
{
int V_86 ;
if ( V_5 -> V_46 != V_88 )
return 0 ;
if ( V_5 -> V_47 != 0x0f )
return 0 ;
for ( V_86 = 0 ; V_86 < V_113 ; V_86 ++ ) {
if ( V_126 [ V_86 ] . V_46 != V_88 )
continue;
if ( V_126 [ V_86 ] . V_47 != 0x0f )
continue;
if ( V_126 [ V_86 ] . V_48 != V_5 -> V_48 )
continue;
if ( V_126 [ V_86 ] . V_49 != V_5 -> V_49 )
continue;
if ( V_127 [ V_86 ] ) {
return - 2 ;
}
V_127 [ V_86 ] = 1 ;
return V_86 ;
}
return - 1 ;
}
static void T_1 F_49 ( struct V_44 * V_5 , int * V_128 )
{
int V_86 ;
F_7 ( V_21 , L_47 ) ;
F_14 ( V_5 ) ;
V_86 = F_48 ( V_5 ) ;
if ( V_86 > 0 ) {
memcpy ( V_5 , & V_126 [ V_86 ] , sizeof( * V_5 ) ) ;
F_7 ( V_21 , L_48 ) ;
F_14 ( & V_126 [ V_86 ] ) ;
return;
}
if ( ! V_86 ) {
return;
}
if ( * V_128 < V_129 ) {
V_130 [ * V_128 ] = V_5 ;
* V_128 += 1 ;
}
}
static int T_1
F_50 ( unsigned long V_131 , unsigned long V_132 , int V_67 )
{
if ( ! V_131 || V_67 <= V_132 ) {
F_51 ( 1 , L_49 , V_67 ) ;
return - 1 ;
}
return 0 ;
}
static
inline void T_1 F_49 ( struct V_44 * V_5 , int * V_128 ) {}
static int T_1 F_52 ( struct V_56 * V_57 ,
unsigned long V_131 ,
unsigned long V_132 )
{
#ifdef F_37
int V_86 ;
#endif
int V_67 = sizeof( * V_57 ) ;
int V_128 = 0 ;
unsigned char * V_69 = ( ( unsigned char * ) V_57 ) + V_67 ;
F_4 ( V_16 L_50 , V_57 -> V_62 ) ;
while ( V_67 < V_57 -> V_62 ) {
switch ( * V_69 ) {
case V_76 :
F_17 ( & V_69 , & V_67 , sizeof( struct V_4 ) ) ;
break;
case V_77 :
F_17 ( & V_69 , & V_67 , sizeof( struct V_18 ) ) ;
break;
case V_78 :
F_17 ( & V_69 , & V_67 , sizeof( struct V_39 ) ) ;
break;
case V_79 :
F_49 ( (struct V_44 * ) V_69 , & V_128 ) ;
F_17 ( & V_69 , & V_67 , sizeof( struct V_44 ) ) ;
break;
case V_80 :
F_17 ( & V_69 , & V_67 , sizeof( struct V_52 ) ) ;
break;
default:
F_18 ( V_57 , V_69 ) ;
goto V_133;
}
}
#ifdef F_37
for ( V_86 = 0 ; V_86 < V_113 ; V_86 ++ ) {
if ( V_127 [ V_86 ] )
continue;
if ( V_126 [ V_86 ] . V_46 != V_88 )
continue;
if ( V_126 [ V_86 ] . V_47 != 0x0f )
continue;
if ( V_128 > 0 ) {
F_7 ( V_21 , L_51 ) ;
V_128 -- ;
memcpy ( V_130 [ V_128 ] , & V_126 [ V_86 ] , sizeof( V_126 [ V_86 ] ) ) ;
V_130 [ V_128 ] = NULL ;
} else {
struct V_44 * V_5 = (struct V_44 * ) V_69 ;
V_67 += sizeof( struct V_44 ) ;
if ( F_50 ( V_131 , V_132 , V_67 ) < 0 )
goto V_133;
memcpy ( V_5 , & V_126 [ V_86 ] , sizeof( * V_5 ) ) ;
V_57 -> V_62 = V_67 ;
V_69 += sizeof( struct V_44 ) ;
}
F_14 ( & V_126 [ V_86 ] ) ;
}
#endif
V_133:
V_57 -> V_134 = 0 ;
V_57 -> V_134 -= F_1 ( ( unsigned char * ) V_57 , V_57 -> V_62 ) ;
return 0 ;
}
static int T_1 F_53 ( char * V_19 )
{
V_135 = 1 ;
#ifdef F_54
V_136 = 1 ;
#endif
return 0 ;
}
static int T_1 F_55 ( char * V_137 )
{
V_135 = 1 ;
#ifdef F_54
V_136 = 1 ;
#endif
V_138 = 1 ;
if ( ! V_137 )
return 0 ;
V_132 = F_56 ( V_137 , & V_137 ) ;
return 0 ;
}
void T_1 F_57 ( void )
{
if ( V_135 && V_138 ) {
V_124 V_139 = 0 ;
V_131 = F_58 ( V_139 , V_132 , 4 ) ;
}
}
static int T_1 F_59 ( void )
{
char V_19 [ 16 ] ;
char V_58 [ 10 ] ;
struct V_110 * V_111 ;
struct V_56 * V_57 , * V_140 ;
if ( ! V_135 )
return 0 ;
V_111 = V_114 ;
if ( ! V_111 )
return 0 ;
if ( V_111 -> V_119 != 0 )
return 0 ;
if ( ! V_111 -> V_108 )
return 0 ;
V_57 = F_43 ( V_111 -> V_108 ) ;
if ( ! F_16 ( V_57 , V_58 , V_19 ) )
return 0 ;
F_4 ( V_16 L_52 , ( V_124 ) F_45 ( V_111 ) ) ;
F_4 ( V_16 L_53 , V_111 -> V_108 ) ;
if ( V_131 && V_57 -> V_62 > V_132 ) {
V_131 = 0 ;
F_4 ( V_16 L_54 ,
V_132 ) ;
}
if ( ! V_131 ) {
unsigned char V_141 , V_142 ;
V_57 -> V_134 = 0 ;
V_141 = F_1 ( ( unsigned char * ) V_57 , V_57 -> V_62 ) ;
V_57 -> V_134 = 0xff ;
V_142 = F_1 ( ( unsigned char * ) V_57 , V_57 -> V_62 ) ;
if ( V_141 == V_142 ) {
F_4 ( V_16 L_55 ) ;
return 0 ;
}
F_4 ( V_16 L_56 ) ;
} else {
V_111 -> V_108 = V_131 ;
V_140 = F_43 ( V_131 ) ;
memcpy ( V_140 , V_57 , V_57 -> V_62 ) ;
V_57 = V_140 ;
if ( V_131 - V_111 -> V_108 ) {
struct V_110 * V_143 ;
F_4 ( V_16 L_57 , 0x400 - 16 ) ;
V_143 = F_43 ( 0x400 - 16 ) ;
memcpy ( V_143 , V_111 , 16 ) ;
V_111 = V_143 ;
V_111 -> V_108 = V_131 ;
}
V_111 -> V_134 = 0 ;
V_111 -> V_134 -= F_1 ( ( unsigned char * ) V_111 , 16 ) ;
F_4 ( V_16 L_58 , V_111 -> V_108 ) ;
}
F_52 ( V_57 , V_131 , V_132 ) ;
return 0 ;
}
