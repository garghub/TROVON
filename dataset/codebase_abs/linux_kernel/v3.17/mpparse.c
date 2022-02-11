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
F_4 ( L_3 , V_5 -> V_6 , V_7 ) ;
F_5 ( V_6 , V_5 -> V_16 ) ;
}
void T_1 F_6 ( struct V_17 * V_5 , char * V_18 )
{
memcpy ( V_18 , V_5 -> V_19 , 6 ) ;
V_18 [ 6 ] = 0 ;
F_7 ( V_20 , L_4 , V_5 -> V_21 , V_18 ) ;
}
static void T_1 F_8 ( struct V_17 * V_5 )
{
char V_18 [ 7 ] ;
V_11 . V_12 . V_22 ( V_5 , V_18 ) ;
#if V_23 < 256
if ( V_5 -> V_21 >= V_23 ) {
F_9 ( L_5 ,
V_5 -> V_21 , V_18 , V_23 - 1 ) ;
return;
}
#endif
F_10 ( V_5 -> V_21 , V_24 ) ;
if ( strncmp ( V_18 , V_25 , sizeof( V_25 ) - 1 ) == 0 ) {
#ifdef F_11
V_26 [ V_5 -> V_21 ] = V_27 ;
#endif
} else if ( strncmp ( V_18 , V_28 , sizeof( V_28 ) - 1 ) == 0 ) {
if ( V_11 . V_12 . V_29 )
V_11 . V_12 . V_29 ( V_5 ) ;
F_12 ( V_5 -> V_21 , V_24 ) ;
#ifdef F_11
V_26 [ V_5 -> V_21 ] = V_30 ;
} else if ( strncmp ( V_18 , V_31 , sizeof( V_31 ) - 1 ) == 0 ) {
V_26 [ V_5 -> V_21 ] = V_32 ;
#endif
} else
F_9 ( L_6 , V_18 ) ;
}
static void T_1 F_13 ( struct V_33 * V_5 )
{
struct V_34 V_35 = {
. type = V_36 ,
. V_37 = & V_38 ,
} ;
if ( V_5 -> V_39 & V_40 )
F_14 ( V_5 -> V_6 , V_5 -> V_41 , V_42 , & V_35 ) ;
}
static void T_1 F_15 ( struct V_43 * V_44 )
{
F_7 ( V_20 ,
L_7 ,
V_44 -> V_45 , V_44 -> V_46 & 3 ,
( V_44 -> V_46 >> 2 ) & 3 , V_44 -> V_47 ,
V_44 -> V_48 , V_44 -> V_49 , V_44 -> V_50 ) ;
}
static inline void T_1 F_8 ( struct V_17 * V_5 ) {}
static inline void T_1 F_13 ( struct V_33 * V_5 ) {}
static void T_1 F_16 ( struct V_51 * V_5 )
{
F_7 ( V_20 ,
L_8 ,
V_5 -> V_45 , V_5 -> V_46 & 3 , ( V_5 -> V_46 >> 2 ) & 3 , V_5 -> V_52 ,
V_5 -> V_48 , V_5 -> V_53 , V_5 -> V_54 ) ;
}
static int T_1 F_17 ( struct V_55 * V_56 , char * V_57 , char * V_18 )
{
if ( memcmp ( V_56 -> V_58 , V_59 , 4 ) ) {
F_18 ( L_9 ,
V_56 -> V_58 [ 0 ] , V_56 -> V_58 [ 1 ] ,
V_56 -> V_58 [ 2 ] , V_56 -> V_58 [ 3 ] ) ;
return 0 ;
}
if ( F_1 ( ( unsigned char * ) V_56 , V_56 -> V_60 ) ) {
F_18 ( L_10 ) ;
return 0 ;
}
if ( V_56 -> V_61 != 0x01 && V_56 -> V_61 != 0x04 ) {
F_18 ( L_11 , V_56 -> V_61 ) ;
return 0 ;
}
if ( ! V_56 -> V_62 ) {
F_18 ( L_12 ) ;
return 0 ;
}
memcpy ( V_57 , V_56 -> V_57 , 8 ) ;
V_57 [ 8 ] = 0 ;
F_4 ( L_13 , V_57 ) ;
memcpy ( V_18 , V_56 -> V_63 , 12 ) ;
V_18 [ 12 ] = 0 ;
F_4 ( L_14 , V_18 ) ;
F_4 ( L_15 , V_56 -> V_62 ) ;
return 1 ;
}
static void F_19 ( unsigned char * * V_64 , int * V_65 , int V_66 )
{
* V_64 += V_66 ;
* V_65 += V_66 ;
}
static void T_1 F_20 ( struct V_55 * V_56 , unsigned char * V_67 )
{
F_18 ( L_16 ) ;
F_21 ( L_17 , * V_67 ) ;
F_22 ( V_68 , L_18 , V_69 , 16 ,
1 , V_56 , V_56 -> V_60 , 1 ) ;
}
void T_1 F_23 ( struct V_55 * V_56 ) { }
static int T_1 F_24 ( struct V_55 * V_56 , unsigned V_70 )
{
char V_18 [ 16 ] ;
char V_57 [ 10 ] ;
int V_65 = sizeof( * V_56 ) ;
unsigned char * V_67 = ( ( unsigned char * ) V_56 ) + V_65 ;
if ( ! F_17 ( V_56 , V_57 , V_18 ) )
return 0 ;
if ( ! V_71 )
F_25 ( V_56 -> V_62 ) ;
if ( V_70 )
return 1 ;
if ( V_56 -> V_72 )
V_11 . V_12 . V_73 ( V_56 ) ;
V_11 . V_12 . V_74 ( 0 ) ;
while ( V_65 < V_56 -> V_60 ) {
switch ( * V_67 ) {
case V_75 :
if ( ! V_71 )
F_3 ( (struct V_4 * ) V_67 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_4 ) ) ;
break;
case V_76 :
F_8 ( (struct V_17 * ) V_67 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_17 ) ) ;
break;
case V_77 :
F_13 ( (struct V_33 * ) V_67 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_33 ) ) ;
break;
case V_78 :
F_26 ( (struct V_43 * ) V_67 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_43 ) ) ;
break;
case V_79 :
F_16 ( (struct V_51 * ) V_67 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_51 ) ) ;
break;
default:
F_20 ( V_56 , V_67 ) ;
V_65 = V_56 -> V_60 ;
break;
}
V_11 . V_12 . V_74 ( 1 ) ;
}
if ( ! V_80 )
F_18 ( L_19 ) ;
return V_80 ;
}
static int T_1 F_27 ( unsigned int V_81 )
{
unsigned int V_82 ;
V_82 = 0x4d0 + ( V_81 >> 3 ) ;
return ( F_28 ( V_82 ) >> ( V_81 & 7 ) ) & 1 ;
}
static void T_1 F_29 ( int V_83 )
{
struct V_43 V_84 ;
int V_85 ;
int V_86 = 0 ;
V_84 . type = V_78 ;
V_84 . V_46 = 0 ;
V_84 . V_47 = 0 ;
V_84 . V_49 = F_30 ( 0 ) ;
V_84 . V_45 = V_87 ;
if ( V_83 == 5 ) {
F_4 ( L_20 ) ;
if ( F_27 ( 0 ) || F_27 ( 1 ) || F_27 ( 2 ) ||
F_27 ( 13 ) )
F_18 ( L_21 ) ;
else {
F_4 ( L_22 ) ;
V_86 = 1 ;
}
}
for ( V_85 = 0 ; V_85 < 16 ; V_85 ++ ) {
switch ( V_83 ) {
case 2 :
if ( V_85 == 0 || V_85 == 13 )
continue;
default:
if ( V_85 == 2 )
continue;
}
if ( V_86 ) {
if ( F_27 ( V_85 ) )
V_84 . V_46 = 13 ;
else
V_84 . V_46 = 0 ;
}
V_84 . V_48 = V_85 ;
V_84 . V_50 = V_85 ? V_85 : 2 ;
F_26 ( & V_84 ) ;
}
V_84 . V_45 = V_88 ;
V_84 . V_48 = 0 ;
V_84 . V_50 = 0 ;
F_26 ( & V_84 ) ;
}
static void T_1 F_31 ( int V_83 )
{
struct V_33 V_89 ;
struct V_17 V_90 ;
V_90 . type = V_76 ;
V_90 . V_21 = 0 ;
switch ( V_83 ) {
default:
F_18 ( L_23 ,
V_83 ) ;
case 1 :
case 5 :
memcpy ( V_90 . V_19 , L_24 , 6 ) ;
break;
case 2 :
case 6 :
case 3 :
memcpy ( V_90 . V_19 , L_25 , 6 ) ;
break;
}
F_8 ( & V_90 ) ;
if ( V_83 > 4 ) {
V_90 . V_21 = 1 ;
memcpy ( V_90 . V_19 , L_26 , 6 ) ;
F_8 ( & V_90 ) ;
}
V_89 . type = V_77 ;
V_89 . V_6 = 2 ;
V_89 . V_16 = V_83 > 4 ? 0x10 : 0x01 ;
V_89 . V_39 = V_40 ;
V_89 . V_41 = V_91 ;
F_13 ( & V_89 ) ;
F_29 ( V_83 ) ;
}
static inline void T_1 F_31 ( int V_83 ) { }
static inline void T_1 F_32 ( int V_83 )
{
struct V_4 V_92 ;
struct V_51 V_93 ;
int V_94 [ 2 ] = { V_88 , V_95 } ;
int V_85 ;
V_96 = V_97 ;
V_92 . type = V_75 ;
V_92 . V_16 = V_83 > 4 ? 0x10 : 0x01 ;
V_92 . V_8 = V_9 ;
V_92 . V_98 = ( V_99 . V_100 << 8 ) |
( V_99 . V_101 << 4 ) | V_99 . V_102 ;
V_92 . V_103 = V_99 . V_104 [ 0 ] ;
V_92 . V_105 [ 0 ] = 0 ;
V_92 . V_105 [ 1 ] = 0 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
V_92 . V_6 = V_85 ;
F_3 ( & V_92 ) ;
}
F_31 ( V_83 ) ;
V_93 . type = V_79 ;
V_93 . V_46 = 0 ;
V_93 . V_52 = 0 ;
V_93 . V_48 = 0 ;
V_93 . V_53 = V_106 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
V_93 . V_45 = V_94 [ V_85 ] ;
V_93 . V_54 = V_85 ;
F_16 ( & V_93 ) ;
}
}
static unsigned long T_1 F_33 ( unsigned long V_107 )
{
struct V_55 * V_56 ;
unsigned long V_66 ;
V_56 = F_34 ( V_107 , V_108 ) ;
V_66 = V_56 -> V_60 ;
F_35 ( V_56 , V_108 ) ;
F_7 ( V_20 , L_27 , V_107 , V_107 + V_66 ) ;
return V_66 ;
}
static int T_1 F_36 ( struct V_109 * V_110 , unsigned int V_70 )
{
struct V_55 * V_56 ;
unsigned long V_66 ;
V_66 = F_33 ( V_110 -> V_107 ) ;
V_56 = F_34 ( V_110 -> V_107 , V_66 ) ;
if ( ! F_24 ( V_56 , V_70 ) ) {
#ifdef F_37
V_111 = 0 ;
#endif
F_18 ( L_28 ) ;
F_21 ( L_29 ) ;
F_35 ( V_56 , V_66 ) ;
return - 1 ;
}
F_35 ( V_56 , V_66 ) ;
if ( V_70 )
return - 1 ;
#ifdef F_38
if ( ! V_112 ) {
struct V_17 V_90 ;
F_18 ( L_30 ) ;
V_90 . type = V_76 ;
V_90 . V_21 = 0 ;
memcpy ( V_90 . V_19 , L_24 , 6 ) ;
F_8 ( & V_90 ) ;
F_29 ( 0 ) ;
}
#endif
return 0 ;
}
void T_1 F_39 ( unsigned int V_70 )
{
struct V_109 * V_110 = V_113 ;
if ( ! V_110 )
return;
if ( V_71 && V_70 )
return;
if ( V_71 && V_114 )
return;
F_4 ( L_31 ,
V_110 -> V_115 ) ;
#if F_40 ( F_37 ) && F_40 ( V_116 )
if ( V_110 -> V_117 & ( 1 << 7 ) ) {
F_4 ( L_32 ) ;
V_118 = 1 ;
} else {
F_4 ( L_33 ) ;
V_118 = 0 ;
}
#endif
if ( V_110 -> V_119 != 0 ) {
if ( V_70 ) {
V_96 = V_97 ;
return;
}
F_4 ( L_34 , V_110 -> V_119 ) ;
F_32 ( V_110 -> V_119 ) ;
} else if ( V_110 -> V_107 ) {
if ( F_36 ( V_110 , V_70 ) )
return;
} else
F_41 () ;
if ( ! V_70 )
F_4 ( L_35 , V_80 ) ;
}
static void T_1 F_42 ( struct V_109 * V_110 )
{
F_43 ( V_110 -> V_107 , F_33 ( V_110 -> V_107 ) ) ;
}
static int T_1 F_44 ( unsigned long V_120 , unsigned long V_60 )
{
unsigned int * V_121 = F_45 ( V_120 ) ;
struct V_109 * V_110 ;
unsigned long V_122 ;
F_7 ( V_20 , L_36 ,
V_120 , V_120 + V_60 - 1 ) ;
F_46 ( sizeof( * V_110 ) != 16 ) ;
while ( V_60 > 0 ) {
V_110 = (struct V_109 * ) V_121 ;
if ( ( * V_121 == V_123 ) &&
( V_110 -> V_60 == 1 ) &&
! F_1 ( ( unsigned char * ) V_121 , 16 ) &&
( ( V_110 -> V_115 == 1 )
|| ( V_110 -> V_115 == 4 ) ) ) {
#ifdef F_37
V_111 = 1 ;
#endif
V_113 = V_110 ;
F_4 ( L_37 ,
( unsigned long long ) F_47 ( V_110 ) ,
( unsigned long long ) F_47 ( V_110 ) +
sizeof( * V_110 ) - 1 , V_110 ) ;
V_122 = F_47 ( V_110 ) ;
F_43 ( V_122 , sizeof( * V_110 ) ) ;
if ( V_110 -> V_107 )
F_42 ( V_110 ) ;
return 1 ;
}
V_121 += 4 ;
V_60 -= 16 ;
}
return 0 ;
}
void T_1 F_48 ( void )
{
unsigned int V_124 ;
if ( F_44 ( 0x0 , 0x400 ) ||
F_44 ( 639 * 0x400 , 0x400 ) ||
F_44 ( 0xF0000 , 0x10000 ) )
return;
V_124 = F_49 () ;
if ( V_124 )
F_44 ( V_124 , 0x400 ) ;
}
static int T_1 F_50 ( struct V_43 * V_5 )
{
int V_85 ;
if ( V_5 -> V_45 != V_87 )
return 0 ;
if ( V_5 -> V_46 != 0x0f )
return 0 ;
for ( V_85 = 0 ; V_85 < V_112 ; V_85 ++ ) {
if ( V_125 [ V_85 ] . V_45 != V_87 )
continue;
if ( V_125 [ V_85 ] . V_46 != 0x0f )
continue;
if ( V_125 [ V_85 ] . V_47 != V_5 -> V_47 )
continue;
if ( V_125 [ V_85 ] . V_48 != V_5 -> V_48 )
continue;
if ( V_126 [ V_85 ] ) {
return - 2 ;
}
V_126 [ V_85 ] = 1 ;
return V_85 ;
}
return - 1 ;
}
static void T_1 F_51 ( struct V_43 * V_5 , int * V_127 )
{
int V_85 ;
F_7 ( V_20 , L_38 ) ;
F_15 ( V_5 ) ;
V_85 = F_50 ( V_5 ) ;
if ( V_85 > 0 ) {
memcpy ( V_5 , & V_125 [ V_85 ] , sizeof( * V_5 ) ) ;
F_7 ( V_20 , L_39 ) ;
F_15 ( & V_125 [ V_85 ] ) ;
return;
}
if ( ! V_85 ) {
return;
}
if ( * V_127 < V_128 ) {
V_129 [ * V_127 ] = V_5 ;
* V_127 += 1 ;
}
}
static int T_1
F_52 ( unsigned long V_130 , unsigned long V_131 , int V_65 )
{
if ( ! V_130 || V_65 <= V_131 ) {
F_53 ( 1 , L_40 , V_65 ) ;
return - 1 ;
}
return 0 ;
}
static
inline void T_1 F_51 ( struct V_43 * V_5 , int * V_127 ) {}
static int T_1 F_54 ( struct V_55 * V_56 ,
unsigned long V_130 ,
unsigned long V_131 )
{
#ifdef F_38
int V_85 ;
#endif
int V_65 = sizeof( * V_56 ) ;
int V_127 = 0 ;
unsigned char * V_67 = ( ( unsigned char * ) V_56 ) + V_65 ;
F_4 ( L_41 , V_56 -> V_60 ) ;
while ( V_65 < V_56 -> V_60 ) {
switch ( * V_67 ) {
case V_75 :
F_19 ( & V_67 , & V_65 , sizeof( struct V_4 ) ) ;
break;
case V_76 :
F_19 ( & V_67 , & V_65 , sizeof( struct V_17 ) ) ;
break;
case V_77 :
F_19 ( & V_67 , & V_65 , sizeof( struct V_33 ) ) ;
break;
case V_78 :
F_51 ( (struct V_43 * ) V_67 , & V_127 ) ;
F_19 ( & V_67 , & V_65 , sizeof( struct V_43 ) ) ;
break;
case V_79 :
F_19 ( & V_67 , & V_65 , sizeof( struct V_51 ) ) ;
break;
default:
F_20 ( V_56 , V_67 ) ;
goto V_132;
}
}
#ifdef F_38
for ( V_85 = 0 ; V_85 < V_112 ; V_85 ++ ) {
if ( V_126 [ V_85 ] )
continue;
if ( V_125 [ V_85 ] . V_45 != V_87 )
continue;
if ( V_125 [ V_85 ] . V_46 != 0x0f )
continue;
if ( V_127 > 0 ) {
F_7 ( V_20 , L_42 ) ;
V_127 -- ;
memcpy ( V_129 [ V_127 ] , & V_125 [ V_85 ] , sizeof( V_125 [ V_85 ] ) ) ;
V_129 [ V_127 ] = NULL ;
} else {
struct V_43 * V_5 = (struct V_43 * ) V_67 ;
V_65 += sizeof( struct V_43 ) ;
if ( F_52 ( V_130 , V_131 , V_65 ) < 0 )
goto V_132;
memcpy ( V_5 , & V_125 [ V_85 ] , sizeof( * V_5 ) ) ;
V_56 -> V_60 = V_65 ;
V_67 += sizeof( struct V_43 ) ;
}
F_15 ( & V_125 [ V_85 ] ) ;
}
#endif
V_132:
V_56 -> V_133 = 0 ;
V_56 -> V_133 -= F_1 ( ( unsigned char * ) V_56 , V_56 -> V_60 ) ;
return 0 ;
}
static int T_1 F_55 ( char * V_18 )
{
V_134 = 1 ;
#ifdef F_56
V_135 = 1 ;
#endif
return 0 ;
}
static int T_1 F_57 ( char * V_136 )
{
V_134 = 1 ;
#ifdef F_56
V_135 = 1 ;
#endif
V_137 = 1 ;
if ( ! V_136 )
return 0 ;
V_131 = F_58 ( V_136 , & V_136 ) ;
return 0 ;
}
void T_1 F_59 ( void )
{
if ( V_134 && V_137 )
V_130 = F_60 ( V_131 , 4 ) ;
}
static int T_1 F_61 ( void )
{
char V_18 [ 16 ] ;
char V_57 [ 10 ] ;
struct V_109 * V_110 ;
struct V_55 * V_56 , * V_138 ;
if ( ! V_134 )
return 0 ;
V_110 = V_113 ;
if ( ! V_110 )
return 0 ;
if ( V_110 -> V_119 != 0 )
return 0 ;
if ( ! V_110 -> V_107 )
return 0 ;
V_56 = F_45 ( V_110 -> V_107 ) ;
if ( ! F_17 ( V_56 , V_57 , V_18 ) )
return 0 ;
F_4 ( L_43 , ( V_139 ) F_47 ( V_110 ) ) ;
F_4 ( L_44 , V_110 -> V_107 ) ;
if ( V_130 && V_56 -> V_60 > V_131 ) {
V_130 = 0 ;
F_4 ( L_45 ,
V_131 ) ;
}
if ( ! V_130 ) {
unsigned char V_140 , V_141 ;
V_56 -> V_133 = 0 ;
V_140 = F_1 ( ( unsigned char * ) V_56 , V_56 -> V_60 ) ;
V_56 -> V_133 = 0xff ;
V_141 = F_1 ( ( unsigned char * ) V_56 , V_56 -> V_60 ) ;
if ( V_140 == V_141 ) {
F_4 ( L_46 ) ;
return 0 ;
}
F_4 ( L_47 ) ;
} else {
V_110 -> V_107 = V_130 ;
V_138 = F_45 ( V_130 ) ;
memcpy ( V_138 , V_56 , V_56 -> V_60 ) ;
V_56 = V_138 ;
if ( V_130 - V_110 -> V_107 ) {
struct V_109 * V_142 ;
F_4 ( L_48 , 0x400 - 16 ) ;
V_142 = F_45 ( 0x400 - 16 ) ;
memcpy ( V_142 , V_110 , 16 ) ;
V_110 = V_142 ;
V_110 -> V_107 = V_130 ;
}
V_110 -> V_133 = 0 ;
V_110 -> V_133 -= F_1 ( ( unsigned char * ) V_110 , 16 ) ;
F_4 ( L_49 , V_110 -> V_107 ) ;
}
F_54 ( V_56 , V_130 , V_131 ) ;
return 0 ;
}
