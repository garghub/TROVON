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
#ifdef F_10
V_28 [ V_5 -> V_22 ] = V_29 ;
#endif
} else if ( strncmp ( V_19 , V_30 , sizeof( V_30 ) - 1 ) == 0 ) {
if ( V_11 . V_12 . V_31 )
V_11 . V_12 . V_31 ( V_5 ) ;
F_11 ( V_5 -> V_22 , V_26 ) ;
#ifdef F_10
V_28 [ V_5 -> V_22 ] = V_32 ;
} else if ( strncmp ( V_19 , V_33 , sizeof( V_33 ) - 1 ) == 0 ) {
V_28 [ V_5 -> V_22 ] = V_34 ;
#endif
} else
F_4 ( V_25 L_7 , V_19 ) ;
}
static void T_1 F_12 ( struct V_35 * V_5 )
{
if ( V_5 -> V_36 & V_37 )
F_13 ( V_5 -> V_6 , V_5 -> V_38 , V_39 ) ;
}
static void T_1 F_14 ( struct V_40 * V_41 )
{
F_7 ( V_21 , L_8
L_9 ,
V_41 -> V_42 , V_41 -> V_43 & 3 ,
( V_41 -> V_43 >> 2 ) & 3 , V_41 -> V_44 ,
V_41 -> V_45 , V_41 -> V_46 , V_41 -> V_47 ) ;
}
static inline void T_1 F_8 ( struct V_18 * V_5 ) {}
static inline void T_1 F_12 ( struct V_35 * V_5 ) {}
static void T_1 F_15 ( struct V_48 * V_5 )
{
F_7 ( V_21 , L_10
L_11 ,
V_5 -> V_42 , V_5 -> V_43 & 3 , ( V_5 -> V_43 >> 2 ) & 3 , V_5 -> V_49 ,
V_5 -> V_45 , V_5 -> V_50 , V_5 -> V_51 ) ;
}
static int T_1 F_16 ( struct V_52 * V_53 , char * V_54 , char * V_19 )
{
if ( memcmp ( V_53 -> V_55 , V_56 , 4 ) ) {
F_4 ( V_57 L_12 ,
V_53 -> V_55 [ 0 ] , V_53 -> V_55 [ 1 ] ,
V_53 -> V_55 [ 2 ] , V_53 -> V_55 [ 3 ] ) ;
return 0 ;
}
if ( F_1 ( ( unsigned char * ) V_53 , V_53 -> V_58 ) ) {
F_4 ( V_57 L_13 ) ;
return 0 ;
}
if ( V_53 -> V_59 != 0x01 && V_53 -> V_59 != 0x04 ) {
F_4 ( V_57 L_14 ,
V_53 -> V_59 ) ;
return 0 ;
}
if ( ! V_53 -> V_60 ) {
F_4 ( V_57 L_15 ) ;
return 0 ;
}
memcpy ( V_54 , V_53 -> V_54 , 8 ) ;
V_54 [ 8 ] = 0 ;
F_4 ( V_16 L_16 , V_54 ) ;
memcpy ( V_19 , V_53 -> V_61 , 12 ) ;
V_19 [ 12 ] = 0 ;
F_4 ( V_16 L_17 , V_19 ) ;
F_4 ( V_16 L_18 , V_53 -> V_60 ) ;
return 1 ;
}
static void F_17 ( unsigned char * * V_62 , int * V_63 , int V_64 )
{
* V_62 += V_64 ;
* V_63 += V_64 ;
}
static void T_1 F_18 ( struct V_52 * V_53 , unsigned char * V_65 )
{
F_4 ( V_57 L_19
L_20 , * V_65 ) ;
F_19 ( V_57 , L_21 , V_66 , 16 ,
1 , V_53 , V_53 -> V_58 , 1 ) ;
}
void T_1 F_20 ( struct V_52 * V_53 ) { }
static int T_1 F_21 ( struct V_52 * V_53 , unsigned V_67 )
{
char V_19 [ 16 ] ;
char V_54 [ 10 ] ;
int V_63 = sizeof( * V_53 ) ;
unsigned char * V_65 = ( ( unsigned char * ) V_53 ) + V_63 ;
if ( ! F_16 ( V_53 , V_54 , V_19 ) )
return 0 ;
#ifdef F_22
F_23 ( V_53 , V_54 , V_19 ) ;
#endif
if ( ! V_68 )
F_24 ( V_53 -> V_60 ) ;
if ( V_67 )
return 1 ;
if ( V_53 -> V_69 )
V_11 . V_12 . V_70 ( V_53 ) ;
V_11 . V_12 . V_71 ( 0 ) ;
while ( V_63 < V_53 -> V_58 ) {
switch ( * V_65 ) {
case V_72 :
if ( ! V_68 )
F_3 ( (struct V_4 * ) V_65 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_4 ) ) ;
break;
case V_73 :
F_8 ( (struct V_18 * ) V_65 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_18 ) ) ;
break;
case V_74 :
F_12 ( (struct V_35 * ) V_65 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_35 ) ) ;
break;
case V_75 :
F_25 ( (struct V_40 * ) V_65 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_40 ) ) ;
break;
case V_76 :
F_15 ( (struct V_48 * ) V_65 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_48 ) ) ;
break;
default:
F_18 ( V_53 , V_65 ) ;
V_63 = V_53 -> V_58 ;
break;
}
V_11 . V_12 . V_71 ( 1 ) ;
}
if ( ! V_77 )
F_4 ( V_57 L_22 ) ;
return V_77 ;
}
static int T_1 F_26 ( unsigned int V_78 )
{
unsigned int V_79 ;
V_79 = 0x4d0 + ( V_78 >> 3 ) ;
return ( F_27 ( V_79 ) >> ( V_78 & 7 ) ) & 1 ;
}
static void T_1 F_28 ( int V_80 )
{
struct V_40 V_81 ;
int V_82 ;
int V_83 = 0 ;
V_81 . type = V_75 ;
V_81 . V_43 = 0 ;
V_81 . V_44 = 0 ;
V_81 . V_46 = F_29 ( 0 ) ;
V_81 . V_42 = V_84 ;
if ( V_80 == 5 ) {
F_4 ( V_16 L_23
L_24 ) ;
if ( F_26 ( 0 ) || F_26 ( 1 ) || F_26 ( 2 ) ||
F_26 ( 13 ) )
F_4 ( V_57 L_25
L_26 ) ;
else {
F_4 ( V_16
L_27 ) ;
V_83 = 1 ;
}
}
for ( V_82 = 0 ; V_82 < 16 ; V_82 ++ ) {
switch ( V_80 ) {
case 2 :
if ( V_82 == 0 || V_82 == 13 )
continue;
default:
if ( V_82 == 2 )
continue;
}
if ( V_83 ) {
if ( F_26 ( V_82 ) )
V_81 . V_43 = 13 ;
else
V_81 . V_43 = 0 ;
}
V_81 . V_45 = V_82 ;
V_81 . V_47 = V_82 ? V_82 : 2 ;
F_25 ( & V_81 ) ;
}
V_81 . V_42 = V_85 ;
V_81 . V_45 = 0 ;
V_81 . V_47 = 0 ;
F_25 ( & V_81 ) ;
}
static void T_1 F_30 ( int V_80 )
{
struct V_35 V_86 ;
struct V_18 V_87 ;
V_87 . type = V_73 ;
V_87 . V_22 = 0 ;
switch ( V_80 ) {
default:
F_4 ( V_57 L_28 ,
V_80 ) ;
case 1 :
case 5 :
memcpy ( V_87 . V_20 , L_29 , 6 ) ;
break;
case 2 :
case 6 :
case 3 :
memcpy ( V_87 . V_20 , L_30 , 6 ) ;
break;
}
F_8 ( & V_87 ) ;
if ( V_80 > 4 ) {
V_87 . V_22 = 1 ;
memcpy ( V_87 . V_20 , L_31 , 6 ) ;
F_8 ( & V_87 ) ;
}
V_86 . type = V_74 ;
V_86 . V_6 = 2 ;
V_86 . V_17 = V_80 > 4 ? 0x10 : 0x01 ;
V_86 . V_36 = V_37 ;
V_86 . V_38 = V_88 ;
F_12 ( & V_86 ) ;
F_28 ( V_80 ) ;
}
static inline void T_1 F_30 ( int V_80 ) { }
static inline void T_1 F_31 ( int V_80 )
{
struct V_4 V_89 ;
struct V_48 V_90 ;
int V_91 [ 2 ] = { V_85 , V_92 } ;
int V_82 ;
V_93 = V_94 ;
V_89 . type = V_72 ;
V_89 . V_17 = V_80 > 4 ? 0x10 : 0x01 ;
V_89 . V_8 = V_9 ;
V_89 . V_95 = ( V_96 . V_97 << 8 ) |
( V_96 . V_98 << 4 ) | V_96 . V_99 ;
V_89 . V_100 = V_96 . V_101 [ 0 ] ;
V_89 . V_102 [ 0 ] = 0 ;
V_89 . V_102 [ 1 ] = 0 ;
for ( V_82 = 0 ; V_82 < 2 ; V_82 ++ ) {
V_89 . V_6 = V_82 ;
F_3 ( & V_89 ) ;
}
F_30 ( V_80 ) ;
V_90 . type = V_76 ;
V_90 . V_43 = 0 ;
V_90 . V_49 = 0 ;
V_90 . V_45 = 0 ;
V_90 . V_50 = V_103 ;
for ( V_82 = 0 ; V_82 < 2 ; V_82 ++ ) {
V_90 . V_42 = V_91 [ V_82 ] ;
V_90 . V_51 = V_82 ;
F_15 ( & V_90 ) ;
}
}
static unsigned long T_1 F_32 ( unsigned long V_104 )
{
struct V_52 * V_53 ;
unsigned long V_64 ;
V_53 = F_33 ( V_104 , V_105 ) ;
V_64 = V_53 -> V_58 ;
F_34 ( V_53 , V_105 ) ;
F_7 ( V_21 , L_32 , V_104 , V_104 + V_64 ) ;
return V_64 ;
}
static int T_1 F_35 ( struct V_106 * V_107 , unsigned int V_67 )
{
struct V_52 * V_53 ;
unsigned long V_64 ;
V_64 = F_32 ( V_107 -> V_104 ) ;
V_53 = F_33 ( V_107 -> V_104 , V_64 ) ;
if ( ! F_21 ( V_53 , V_67 ) ) {
#ifdef F_36
V_108 = 0 ;
#endif
F_4 ( V_57 L_33
L_34 ) ;
F_34 ( V_53 , V_64 ) ;
return - 1 ;
}
F_34 ( V_53 , V_64 ) ;
if ( V_67 )
return - 1 ;
#ifdef F_37
if ( ! V_109 ) {
struct V_18 V_87 ;
F_4 ( V_57 L_35
L_36 ) ;
V_87 . type = V_73 ;
V_87 . V_22 = 0 ;
memcpy ( V_87 . V_20 , L_29 , 6 ) ;
F_8 ( & V_87 ) ;
F_28 ( 0 ) ;
}
#endif
return 0 ;
}
void T_1 F_38 ( unsigned int V_67 )
{
struct V_106 * V_107 = V_110 ;
if ( ! V_107 )
return;
if ( V_68 && V_67 )
return;
if ( V_68 && V_111 )
return;
F_4 ( V_16 L_37 ,
V_107 -> V_112 ) ;
#if F_39 ( F_36 ) && F_39 ( F_22 )
if ( V_107 -> V_113 & ( 1 << 7 ) ) {
F_4 ( V_16 L_38 ) ;
V_114 = 1 ;
} else {
F_4 ( V_16 L_39 ) ;
V_114 = 0 ;
}
#endif
if ( V_107 -> V_115 != 0 ) {
if ( V_67 ) {
V_93 = V_94 ;
return;
}
F_4 ( V_16 L_40 ,
V_107 -> V_115 ) ;
F_31 ( V_107 -> V_115 ) ;
} else if ( V_107 -> V_104 ) {
if ( F_35 ( V_107 , V_67 ) )
return;
} else
F_40 () ;
if ( ! V_67 )
F_4 ( V_16 L_41 , V_77 ) ;
}
static void T_1 F_41 ( struct V_106 * V_107 )
{
F_42 ( V_107 -> V_104 , F_32 ( V_107 -> V_104 ) ) ;
}
static int T_1 F_43 ( unsigned long V_116 , unsigned long V_58 )
{
unsigned int * V_117 = F_44 ( V_116 ) ;
struct V_106 * V_107 ;
unsigned long V_118 ;
F_7 ( V_21 , L_42 ,
V_116 , V_116 + V_58 - 1 ) ;
F_45 ( sizeof( * V_107 ) != 16 ) ;
while ( V_58 > 0 ) {
V_107 = (struct V_106 * ) V_117 ;
if ( ( * V_117 == V_119 ) &&
( V_107 -> V_58 == 1 ) &&
! F_1 ( ( unsigned char * ) V_117 , 16 ) &&
( ( V_107 -> V_112 == 1 )
|| ( V_107 -> V_112 == 4 ) ) ) {
#ifdef F_36
V_108 = 1 ;
#endif
V_110 = V_107 ;
F_4 ( V_16 L_43 ,
( unsigned long long ) F_46 ( V_107 ) ,
( unsigned long long ) F_46 ( V_107 ) +
sizeof( * V_107 ) - 1 , V_107 ) ;
V_118 = F_46 ( V_107 ) ;
F_42 ( V_118 , sizeof( * V_107 ) ) ;
if ( V_107 -> V_104 )
F_41 ( V_107 ) ;
return 1 ;
}
V_117 += 4 ;
V_58 -= 16 ;
}
return 0 ;
}
void T_1 F_47 ( void )
{
unsigned int V_120 ;
if ( F_43 ( 0x0 , 0x400 ) ||
F_43 ( 639 * 0x400 , 0x400 ) ||
F_43 ( 0xF0000 , 0x10000 ) )
return;
V_120 = F_48 () ;
if ( V_120 )
F_43 ( V_120 , 0x400 ) ;
}
static int T_1 F_49 ( struct V_40 * V_5 )
{
int V_82 ;
if ( V_5 -> V_42 != V_84 )
return 0 ;
if ( V_5 -> V_43 != 0x0f )
return 0 ;
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ ) {
if ( V_121 [ V_82 ] . V_42 != V_84 )
continue;
if ( V_121 [ V_82 ] . V_43 != 0x0f )
continue;
if ( V_121 [ V_82 ] . V_44 != V_5 -> V_44 )
continue;
if ( V_121 [ V_82 ] . V_45 != V_5 -> V_45 )
continue;
if ( V_122 [ V_82 ] ) {
return - 2 ;
}
V_122 [ V_82 ] = 1 ;
return V_82 ;
}
return - 1 ;
}
static void T_1 F_50 ( struct V_40 * V_5 , int * V_123 )
{
int V_82 ;
F_7 ( V_21 , L_44 ) ;
F_14 ( V_5 ) ;
V_82 = F_49 ( V_5 ) ;
if ( V_82 > 0 ) {
memcpy ( V_5 , & V_121 [ V_82 ] , sizeof( * V_5 ) ) ;
F_7 ( V_21 , L_45 ) ;
F_14 ( & V_121 [ V_82 ] ) ;
return;
}
if ( ! V_82 ) {
return;
}
if ( * V_123 < V_124 ) {
V_125 [ * V_123 ] = V_5 ;
* V_123 += 1 ;
}
}
static int T_1
F_51 ( unsigned long V_126 , unsigned long V_127 , int V_63 )
{
if ( ! V_126 || V_63 <= V_127 ) {
F_52 ( 1 , L_46 , V_63 ) ;
return - 1 ;
}
return 0 ;
}
static
inline void T_1 F_50 ( struct V_40 * V_5 , int * V_123 ) {}
static int T_1 F_53 ( struct V_52 * V_53 ,
unsigned long V_126 ,
unsigned long V_127 )
{
#ifdef F_37
int V_82 ;
#endif
int V_63 = sizeof( * V_53 ) ;
int V_123 = 0 ;
unsigned char * V_65 = ( ( unsigned char * ) V_53 ) + V_63 ;
F_4 ( V_16 L_47 , V_53 -> V_58 ) ;
while ( V_63 < V_53 -> V_58 ) {
switch ( * V_65 ) {
case V_72 :
F_17 ( & V_65 , & V_63 , sizeof( struct V_4 ) ) ;
break;
case V_73 :
F_17 ( & V_65 , & V_63 , sizeof( struct V_18 ) ) ;
break;
case V_74 :
F_17 ( & V_65 , & V_63 , sizeof( struct V_35 ) ) ;
break;
case V_75 :
F_50 ( (struct V_40 * ) V_65 , & V_123 ) ;
F_17 ( & V_65 , & V_63 , sizeof( struct V_40 ) ) ;
break;
case V_76 :
F_17 ( & V_65 , & V_63 , sizeof( struct V_48 ) ) ;
break;
default:
F_18 ( V_53 , V_65 ) ;
goto V_128;
}
}
#ifdef F_37
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ ) {
if ( V_122 [ V_82 ] )
continue;
if ( V_121 [ V_82 ] . V_42 != V_84 )
continue;
if ( V_121 [ V_82 ] . V_43 != 0x0f )
continue;
if ( V_123 > 0 ) {
F_7 ( V_21 , L_48 ) ;
V_123 -- ;
memcpy ( V_125 [ V_123 ] , & V_121 [ V_82 ] , sizeof( V_121 [ V_82 ] ) ) ;
V_125 [ V_123 ] = NULL ;
} else {
struct V_40 * V_5 = (struct V_40 * ) V_65 ;
V_63 += sizeof( struct V_40 ) ;
if ( F_51 ( V_126 , V_127 , V_63 ) < 0 )
goto V_128;
memcpy ( V_5 , & V_121 [ V_82 ] , sizeof( * V_5 ) ) ;
V_53 -> V_58 = V_63 ;
V_65 += sizeof( struct V_40 ) ;
}
F_14 ( & V_121 [ V_82 ] ) ;
}
#endif
V_128:
V_53 -> V_129 = 0 ;
V_53 -> V_129 -= F_1 ( ( unsigned char * ) V_53 , V_53 -> V_58 ) ;
return 0 ;
}
static int T_1 F_54 ( char * V_19 )
{
V_130 = 1 ;
#ifdef F_55
V_131 = 1 ;
#endif
return 0 ;
}
static int T_1 F_56 ( char * V_132 )
{
V_130 = 1 ;
#ifdef F_55
V_131 = 1 ;
#endif
V_133 = 1 ;
if ( ! V_132 )
return 0 ;
V_127 = F_57 ( V_132 , & V_132 ) ;
return 0 ;
}
void T_1 F_58 ( void )
{
if ( V_130 && V_133 )
V_126 = F_59 ( V_127 , 4 ) ;
}
static int T_1 F_60 ( void )
{
char V_19 [ 16 ] ;
char V_54 [ 10 ] ;
struct V_106 * V_107 ;
struct V_52 * V_53 , * V_134 ;
if ( ! V_130 )
return 0 ;
V_107 = V_110 ;
if ( ! V_107 )
return 0 ;
if ( V_107 -> V_115 != 0 )
return 0 ;
if ( ! V_107 -> V_104 )
return 0 ;
V_53 = F_44 ( V_107 -> V_104 ) ;
if ( ! F_16 ( V_53 , V_54 , V_19 ) )
return 0 ;
F_4 ( V_16 L_49 , ( V_135 ) F_46 ( V_107 ) ) ;
F_4 ( V_16 L_50 , V_107 -> V_104 ) ;
if ( V_126 && V_53 -> V_58 > V_127 ) {
V_126 = 0 ;
F_4 ( V_16 L_51 ,
V_127 ) ;
}
if ( ! V_126 ) {
unsigned char V_136 , V_137 ;
V_53 -> V_129 = 0 ;
V_136 = F_1 ( ( unsigned char * ) V_53 , V_53 -> V_58 ) ;
V_53 -> V_129 = 0xff ;
V_137 = F_1 ( ( unsigned char * ) V_53 , V_53 -> V_58 ) ;
if ( V_136 == V_137 ) {
F_4 ( V_16 L_52 ) ;
return 0 ;
}
F_4 ( V_16 L_53 ) ;
} else {
V_107 -> V_104 = V_126 ;
V_134 = F_44 ( V_126 ) ;
memcpy ( V_134 , V_53 , V_53 -> V_58 ) ;
V_53 = V_134 ;
if ( V_126 - V_107 -> V_104 ) {
struct V_106 * V_138 ;
F_4 ( V_16 L_54 , 0x400 - 16 ) ;
V_138 = F_44 ( 0x400 - 16 ) ;
memcpy ( V_138 , V_107 , 16 ) ;
V_107 = V_138 ;
V_107 -> V_104 = V_126 ;
}
V_107 -> V_129 = 0 ;
V_107 -> V_129 -= F_1 ( ( unsigned char * ) V_107 , 16 ) ;
F_4 ( V_16 L_55 , V_107 -> V_104 ) ;
}
F_53 ( V_53 , V_126 , V_127 ) ;
return 0 ;
}
