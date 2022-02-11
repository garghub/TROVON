static int T_1 F_1 ( struct V_1 * V_2 )
{
int * V_3 , V_4 [] = { 0xddffe , 0xd9ffe , 0xcdffe , 0xc9ffe , 0 } ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
if ( V_5 > 0x1ff )
return F_2 ( V_2 , V_5 ) ;
else if ( V_5 != 0 )
return - V_7 ;
for ( V_3 = V_4 ; * V_3 ; V_3 ++ ) {
void T_2 * V_8 = F_3 ( * V_3 , 1 ) ;
unsigned V_9 ;
int V_10 ;
if ( ! V_8 )
continue;
V_9 = F_4 ( V_8 ) ;
F_5 ( V_8 ) ;
V_10 = F_6 ( V_9 ) - 1 ;
if ( V_10 == - 1 || V_9 != ( 1 << V_10 ) )
continue;
if ( F_2 ( V_2 , V_11 [ V_10 ] ) == 0 )
return 0 ;
V_2 -> V_6 = V_6 ;
}
#if ! F_7 ( V_12 )
return F_8 ( V_2 ) ;
#else
return - V_13 ;
#endif
}
static int T_1
F_8 ( struct V_1 * V_2 )
{
int V_10 ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
if ( V_5 > 0x1ff )
return F_2 ( V_2 , V_5 ) ;
else if ( V_5 != 0 )
return - V_7 ;
for ( V_10 = 0 ; V_11 [ V_10 ] ; V_10 ++ ) {
if ( F_2 ( V_2 , V_11 [ V_10 ] ) == 0 )
return 0 ;
V_2 -> V_6 = V_6 ;
}
return - V_13 ;
}
struct V_1 * T_1 F_9 ( int V_14 )
{
struct V_1 * V_2 = F_10 () ;
int V_15 ;
if ( ! V_2 )
return F_11 ( - V_16 ) ;
sprintf ( V_2 -> V_17 , L_1 , V_14 ) ;
F_12 ( V_2 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
goto V_18;
return V_2 ;
V_18:
F_13 ( V_2 ) ;
return F_11 ( V_15 ) ;
}
static int T_1
F_2 ( struct V_1 * V_2 , int V_19 )
{
int V_10 , V_20 , V_21 , V_22 , V_23 , V_24 ;
static unsigned V_25 ;
unsigned long V_26 ;
if ( ! F_14 ( V_19 , V_27 , V_28 ) )
return - V_29 ;
if ( ! F_14 ( V_19 + 0x400 , 8 , V_28 ) ) {
V_24 = - V_29 ;
goto V_18;
}
if ( F_15 ( V_19 + 0x408 ) == 0xff ) {
F_16 ( 1 ) ;
V_24 = - V_13 ;
goto V_30;
}
V_20 = F_15 ( V_19 + 0x403 ) ;
V_21 = F_15 ( V_19 + 0x404 ) ;
if ( ( V_20 & ( V_20 - 1 ) ) ||
( V_21 & ( V_21 - 1 ) ) ) {
V_24 = - V_13 ;
goto V_30;
}
V_22 = F_17 ( V_19 + 0x406 ) ;
F_18 ( V_31 | V_32 , V_19 + 0x406 ) ;
F_18 ( V_32 , V_19 + 0x406 ) ;
F_19 ( V_33 | V_32 , V_19 + 0x406 ) ;
V_26 = F_15 ( V_19 ) * 0x10000 + F_15 ( V_19 + 1 ) * 0x100 + F_15 ( V_19 + 2 ) ;
if ( ( V_26 != V_34 ) && ( V_26 != V_35 ) ) {
F_19 ( V_22 , V_19 + 0x406 ) ;
V_24 = - V_13 ;
goto V_30;
}
if ( V_36 && V_25 ++ == 0 )
F_20 ( L_2 , V_37 ) ;
V_2 -> V_5 = V_19 ;
F_21 ( L_3 , V_2 -> V_17 , V_19 ) ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
V_2 -> V_38 [ V_10 ] = F_15 ( V_19 + V_10 ) ;
F_22 ( L_4 , V_2 -> V_38 ) ;
F_19 ( V_32 , V_19 + 0x406 ) ;
F_18 ( V_39 , V_19 + V_40 ) ;
F_18 ( 0 , V_19 + V_41 ) ;
F_18 ( V_42 , V_19 + V_40 ) ;
V_23 = F_17 ( V_19 + V_41 ) & V_43 ;
F_18 ( V_39 , V_19 + V_40 ) ;
if ( V_36 > 2 )
F_22 ( L_5 , V_21 ) ;
F_19 ( V_44 , V_19 + 0x405 ) ;
#if F_7 ( V_45 ) || F_7 ( V_46 )
V_47 . V_48 = 1 ;
#else
V_47 . V_48 = V_2 -> V_49 & 0xf ;
#endif
F_22 ( L_6 , V_47 . V_48 == 0 ? L_7 : L_8 ) ;
if ( ( V_21 & 0xf0 ) == 0 ) {
V_2 -> V_50 = 0 ;
V_47 . V_17 = L_9 ;
V_47 . V_51 = NULL ;
} else {
V_2 -> V_50 = ( ( V_21 & 0xc0 ) ? 0xD8000 : 0xC8000 ) +
( ( V_21 & 0xA0 ) ? 0x4000 : 0 ) ;
#define F_23 (EL2_MB1_STOP_PG - EL2_MB1_START_PG)*256
V_47 . V_51 = F_3 ( V_2 -> V_50 , F_23 ) ;
#ifdef F_24
{
void T_2 * V_52 = V_47 . V_51 ;
unsigned int V_53 = 0xbbadf00d ;
F_25 ( 0xba5eba5e , V_52 ) ;
for ( V_10 = sizeof( V_53 ) ; V_10 < F_23 ; V_10 += sizeof( V_53 ) ) {
F_25 ( V_53 , V_52 + V_10 ) ;
if ( F_26 ( V_52 ) != 0xba5eba5e ||
F_26 ( V_52 + V_10 ) != V_53 ) {
F_27 ( L_10 ) ;
V_2 -> V_50 = 0 ;
V_47 . V_17 = L_9 ;
F_5 ( V_52 ) ;
V_47 . V_51 = NULL ;
break;
}
V_53 += 0x55555555 ;
F_25 ( 0 , V_52 + V_10 ) ;
}
}
#endif
if ( V_2 -> V_50 )
V_2 -> V_49 = V_2 -> V_50 + F_23 ;
if ( V_23 ) {
V_47 . V_54 = 0 ;
V_47 . V_17 = L_11 ;
} else {
V_47 . V_54 = V_55 * 256 ;
V_47 . V_17 = L_12 ;
}
}
if ( V_23 ) {
V_47 . V_56 = V_57 ;
V_47 . V_58 = V_59 ;
} else {
V_47 . V_56 = V_59 ;
V_47 . V_58 = V_59 + V_55 ;
}
V_47 . V_60 = V_61 ;
V_47 . V_62 = V_23 ;
V_47 . V_63 = V_64 ;
V_47 . V_65 = V_66 ;
V_47 . V_67 = V_68 ;
V_47 . V_69 = V_70 ;
if ( V_2 -> V_6 == 2 )
V_2 -> V_6 = 9 ;
else if ( V_2 -> V_6 > 5 && V_2 -> V_6 != 9 ) {
F_27 ( L_13 ,
V_2 -> V_6 ) ;
V_2 -> V_6 = 0 ;
}
V_47 . V_71 = V_2 -> V_6 ;
V_2 -> V_72 = & V_73 ;
V_2 -> V_74 = & V_75 ;
V_24 = F_28 ( V_2 ) ;
if ( V_24 )
goto V_30;
if ( V_2 -> V_50 )
F_21 ( L_14 ,
V_2 -> V_17 , V_47 . V_17 , ( V_23 + 1 ) << 3 ,
V_2 -> V_50 , V_2 -> V_49 - 1 ) ;
else
{
V_47 . V_56 = V_59 ;
V_47 . V_58 = V_59 + V_55 ;
F_21 ( L_15 ,
V_2 -> V_17 , V_47 . V_17 , ( V_23 + 1 ) << 3 ) ;
}
F_29 ( V_19 + 0x400 , 8 ) ;
return 0 ;
V_30:
F_29 ( V_19 + 0x400 , 8 ) ;
V_18:
F_29 ( V_19 , V_27 ) ;
return V_24 ;
}
static T_3 F_30 ( int V_6 , void * V_76 )
{
* ( bool * ) V_76 = true ;
return V_77 ;
}
static int
F_31 ( struct V_1 * V_2 )
{
int V_24 ;
if ( V_2 -> V_6 < 2 ) {
static const int V_78 [] = { 5 , 9 , 3 , 4 , 0 } ;
const int * V_79 = V_78 ;
F_19 ( V_44 , V_80 ) ;
do {
bool V_76 ;
V_24 = F_32 ( * V_79 , F_30 , 0 ,
V_2 -> V_17 , & V_76 ) ;
if ( V_24 == - V_29 )
continue;
if ( V_24 < 0 )
goto V_81;
V_76 = false ;
F_33 () ;
F_18 ( 0x04 << ( ( * V_79 == 9 ) ? 2 : * V_79 ) , V_82 ) ;
F_18 ( 0x00 , V_82 ) ;
F_34 ( 1 ) ;
F_35 ( * V_79 , & V_76 ) ;
if ( ! V_76 )
continue;
V_24 = F_32 ( V_2 -> V_6 = * V_79 , V_83 , 0 ,
V_2 -> V_17 , V_2 ) ;
if ( V_24 == - V_29 )
continue;
if ( V_24 < 0 )
goto V_81;
break;
} while ( * ++ V_79 );
if ( * V_79 == 0 ) {
V_81:
F_19 ( V_84 , V_80 ) ;
return - V_85 ;
}
} else {
if ( ( V_24 = F_32 ( V_2 -> V_6 , V_83 , 0 , V_2 -> V_17 , V_2 ) ) ) {
return V_24 ;
}
}
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int
F_38 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_6 , V_2 ) ;
V_2 -> V_6 = V_47 . V_71 ;
F_19 ( V_84 , V_80 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static void
V_64 ( struct V_1 * V_2 )
{
if ( V_36 > 1 ) {
F_20 ( L_16 , V_2 -> V_17 ) ;
F_22 ( L_17 , V_82 , F_15 ( V_82 ) ,
V_86 , F_15 ( V_86 ) , V_80 , F_15 ( V_80 ) ) ;
}
F_18 ( V_31 | V_32 , V_86 ) ;
V_47 . V_87 = 0 ;
F_18 ( V_47 . V_48 == 0 ? V_32 : V_88 , V_86 ) ;
F_36 ( V_2 ) ;
if ( V_36 > 1 )
F_22 ( L_18 ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
F_18 ( V_47 . V_48 == 0 ? V_32 : V_88 , V_86 ) ;
F_19 ( V_47 . V_58 , V_89 ) ;
F_19 ( V_47 . V_60 , V_90 ) ;
F_19 ( 0xff , V_91 ) ;
F_19 ( 0xff , V_92 ) ;
F_19 ( 0x00 , V_93 ) ;
F_18 ( 0x00 , V_2 -> V_5 + V_94 ) ;
F_19 ( V_44 , V_80 ) ;
F_18 ( ( 0x04 << ( V_2 -> V_6 == 9 ? 2 : V_2 -> V_6 ) ) , V_82 ) ;
F_18 ( ( V_95 << 1 ) , V_96 ) ;
F_18 ( 0x20 , V_97 ) ;
F_18 ( 0x00 , V_98 ) ;
return;
}
static void
V_70 ( struct V_1 * V_2 , int V_99 ,
const unsigned char * V_100 , int V_101 )
{
unsigned short int * V_102 ;
int V_103 ;
unsigned short V_104 ;
void T_2 * V_105 = V_47 . V_51 ;
if ( V_47 . V_62 )
F_19 ( V_106 | V_107 , V_80 ) ;
else
F_19 ( V_44 , V_80 ) ;
if ( V_105 ) {
F_40 ( V_105 + ( ( V_101 - V_47 . V_56 ) << 8 ) ,
V_100 , V_99 ) ;
F_19 ( V_44 , V_80 ) ;
return;
}
V_104 = ( unsigned short ) V_101 ;
F_19 ( V_104 & 0xFF , V_97 ) ;
F_19 ( V_104 >> 8 , V_98 ) ;
F_18 ( ( V_47 . V_48 ? V_88 : V_32 ) | V_108
| V_109 , V_86 ) ;
V_102 = ( unsigned short int * ) V_100 ;
V_99 = ( V_99 + 1 ) >> 1 ;
for(; ; )
{
V_103 = 0x1000 ;
while ( ( F_15 ( V_110 ) & V_111 ) == 0 )
{
if( ! V_103 -- )
{
F_41 ( L_19 , V_2 -> V_17 ) ;
V_64 ( V_2 ) ;
goto V_112;
}
}
if( V_99 > V_95 )
{
F_42 ( V_113 , V_102 , V_95 ) ;
V_102 += V_95 ;
V_99 -= V_95 ;
}
else
{
F_42 ( V_113 , V_102 , V_99 ) ;
break;
}
}
V_112: ;
F_18 ( V_47 . V_48 == 0 ? V_32 : V_88 , V_86 ) ;
}
static void
V_66 ( struct V_1 * V_2 , struct V_114 * V_115 , int V_116 )
{
int V_103 ;
void T_2 * V_105 = V_47 . V_51 ;
unsigned short V_104 ;
if ( V_105 ) {
void T_2 * V_117 = V_105 + ( ( V_116 - V_59 ) << 8 ) ;
F_43 ( V_115 , V_117 , sizeof( struct V_114 ) ) ;
V_115 -> V_99 = F_44 ( V_115 -> V_99 ) ;
return;
}
V_104 = ( unsigned short ) V_116 ;
F_19 ( V_104 & 0xFF , V_97 ) ;
F_19 ( V_104 >> 8 , V_98 ) ;
F_18 ( ( V_47 . V_48 == 0 ? V_32 : V_88 ) | V_118
| V_109 , V_86 ) ;
V_103 = 0x1000 ;
while ( ( F_15 ( V_110 ) & V_111 ) == 0 )
{
if( ! V_103 -- )
{
F_41 ( L_20 , V_2 -> V_17 ) ;
memset ( V_115 , 0x00 , sizeof( struct V_114 ) ) ;
V_64 ( V_2 ) ;
goto V_112;
}
}
F_45 ( V_113 , V_115 , ( sizeof( struct V_114 ) ) >> 1 ) ;
V_112: ;
F_18 ( V_47 . V_48 == 0 ? V_32 : V_88 , V_86 ) ;
}
static void
V_68 ( struct V_1 * V_2 , int V_99 , struct V_119 * V_120 , int V_121 )
{
int V_103 = 0 ;
void T_2 * V_105 = V_47 . V_51 ;
unsigned short int * V_100 ;
unsigned short V_104 ;
if ( V_105 ) {
V_121 -= ( V_59 << 8 ) ;
if ( V_121 + V_99 > F_23 ) {
int V_122 = F_23 - V_121 ;
F_43 ( V_120 -> V_123 , V_105 + V_121 , V_122 ) ;
V_99 -= V_122 ;
F_43 ( V_120 -> V_123 + V_122 , V_105 + V_47 . V_54 , V_99 ) ;
} else {
F_43 ( V_120 -> V_123 , V_105 + V_121 , V_99 ) ;
}
return;
}
V_104 = ( unsigned short ) V_121 ;
F_19 ( V_104 >> 8 , V_97 ) ;
F_19 ( V_104 & 0xFF , V_98 ) ;
F_18 ( ( V_47 . V_48 == 0 ? V_32 : V_88 ) | V_118
| V_109 , V_86 ) ;
V_100 = ( unsigned short int * ) V_120 -> V_123 ;
V_99 = ( V_99 + 1 ) >> 1 ;
for(; ; )
{
V_103 = 0x1000 ;
while ( ( F_15 ( V_110 ) & V_111 ) == 0 )
{
if( ! V_103 -- )
{
F_41 ( L_21 , V_2 -> V_17 ) ;
V_64 ( V_2 ) ;
goto V_112;
}
}
if( V_99 > V_95 )
{
F_45 ( V_113 , V_100 , V_95 ) ;
V_100 += V_95 ;
V_99 -= V_95 ;
}
else
{
F_45 ( V_113 , V_100 , V_99 ) ;
break;
}
}
V_112: ;
F_18 ( V_47 . V_48 == 0 ? V_32 : V_88 , V_86 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
strcpy ( V_125 -> V_126 , V_28 ) ;
strcpy ( V_125 -> V_37 , V_127 ) ;
sprintf ( V_125 -> V_128 , L_22 , V_2 -> V_5 ) ;
}
int T_1
F_47 ( void )
{
struct V_1 * V_2 ;
int V_129 , V_130 = 0 ;
for ( V_129 = 0 ; V_129 < V_131 ; V_129 ++ ) {
if ( V_132 [ V_129 ] == 0 ) {
if ( V_129 != 0 ) break;
F_41 ( L_23 ) ;
}
V_2 = F_10 () ;
if ( ! V_2 )
break;
V_2 -> V_6 = V_6 [ V_129 ] ;
V_2 -> V_5 = V_132 [ V_129 ] ;
V_2 -> V_49 = V_133 [ V_129 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_134 [ V_130 ++ ] = V_2 ;
continue;
}
F_13 ( V_2 ) ;
F_27 ( L_24 , V_132 [ V_129 ] ) ;
break;
}
if ( V_130 )
return 0 ;
return - V_7 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_5 , V_27 ) ;
if ( V_47 . V_51 )
F_5 ( V_47 . V_51 ) ;
}
void T_4
F_49 ( void )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_131 ; V_129 ++ ) {
struct V_1 * V_2 = V_134 [ V_129 ] ;
if ( V_2 ) {
F_50 ( V_2 ) ;
F_48 ( V_2 ) ;
F_13 ( V_2 ) ;
}
}
}
