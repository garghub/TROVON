static bool F_1 ( void )
{
return ( F_2 ( V_1 ) & 0x80 ) != 0 ;
}
static bool F_3 ( void )
{
return ( F_2 ( V_1 ) & 0x88 ) == 8 ;
}
static bool F_4 ( void )
{
unsigned long V_2 = V_3 + V_4 ;
while ( ( F_2 ( V_1 ) & 0x80 ) &&
( F_5 ( V_3 , V_2 ) ) )
F_6 () ;
return F_5 ( V_3 , V_2 + 1 ) ;
}
static bool F_7 ( void )
{
unsigned long V_2 ;
V_2 = V_3 + V_4 ;
while ( ! F_1 () && F_5 ( V_3 , V_2 ) )
F_6 () ;
return F_4 () ;
}
static void F_8 ( void * V_5 )
{
int V_6 ;
short * V_7 = V_5 ;
if ( ! F_4 () ) {
F_9 ( NULL ) ;
return;
}
F_10 ( V_8 , V_9 ) ;
if ( ! F_7 () ) {
F_9 ( NULL ) ;
return;
}
for ( V_6 = 0 ; V_6 < 40 ; V_6 ++ )
V_7 [ V_6 ] = F_11 ( V_10 ) ;
}
static void F_12 ( void * V_11 , int V_12 )
{
short * V_13 = V_11 ;
unsigned long V_2 ;
F_10 ( 0x08 , V_1 ) ;
F_10 ( V_12 & 0xFF , V_14 ) ;
F_10 ( ( V_12 >> 8 ) & 0xFF , V_15 ) ;
F_10 ( 0 , V_16 ) ;
F_10 ( 0 , V_17 ) ;
F_10 ( 0 , V_18 ) ;
if ( ! F_4 () ) {
F_9 ( NULL ) ;
return;
}
V_2 = V_3 + V_4 ;
F_10 ( V_19 , V_9 ) ;
while ( ! F_3 () && F_5 ( V_3 , V_2 ) )
F_6 () ;
if ( ! F_5 ( V_3 , V_2 + 1 ) ) {
F_9 ( NULL ) ;
return;
}
F_13 ( V_10 , V_13 , 6 ) ;
}
static char F_14 ( void )
{
F_15 ( V_20 . V_21 ) ;
if ( ! F_4 () )
return 0 ;
F_10 ( V_22 , V_9 ) ;
if ( ! F_7 () )
return 0 ;
return F_2 ( V_18 ) ;
}
static int F_16 ( void )
{
struct V_23 * V_24 ;
V_24 = F_17 ( sizeof( struct V_23 ) , V_25 ) ;
if ( ! V_24 )
return - V_26 ;
V_24 -> V_13 [ 0 ] = 0x70 ;
V_24 -> V_13 [ 2 ] = 0x1f ;
V_24 -> V_12 = 0 ;
V_20 . V_27 = 1 ;
F_18 ( V_20 . V_21 , V_24 ) ;
F_19 ( V_28 , V_20 . V_27 == 0 ,
V_4 ) ;
V_20 . V_27 = 0 ;
F_20 ( V_24 ) ;
if ( V_20 . V_29 & 0x01 ) {
F_9 ( NULL ) ;
return - V_30 ;
}
return 0 ;
}
static int F_21 ( struct V_31 * V_32 , int V_33 )
{
int V_34 ;
struct V_23 * V_35 ;
int V_36 = 0 ;
V_35 = F_17 ( sizeof( struct V_23 ) , V_25 ) ;
if ( ! V_35 )
return - V_26 ;
V_34 = sizeof( struct V_31 ) ;
V_35 -> V_13 [ 0 ] = 0x14 ;
V_35 -> V_13 [ 1 ] = V_33 ;
V_35 -> V_13 [ 3 ] = V_34 >> 8 ;
V_35 -> V_13 [ 4 ] = V_34 & 0xff ;
V_35 -> V_12 = V_34 ;
if ( V_20 . V_27 ) {
V_36 = - V_37 ;
goto V_38;
}
V_20 . V_27 = 1 ;
F_18 ( V_20 . V_21 , V_35 ) ;
F_19 ( V_28 , V_20 . V_27 == 0 ,
V_4 ) ;
if ( V_20 . V_27 ) {
V_36 = - V_39 ;
goto V_40;
}
F_22 ( V_10 , V_32 , V_34 / 2 ) ;
if ( V_20 . V_29 & 0x01 )
V_36 = - V_39 ;
V_40:
V_20 . V_27 = 0 ;
V_38:
F_20 ( V_35 ) ;
return V_36 ;
}
static int F_23 ( int V_41 )
{
return ( F_24 ( V_41 & 0xffffff00 ) - V_42 ) ;
}
static int F_25 ( int V_41 )
{
return ( V_41 & 0x000000f0 ) >> 4 ;
}
static int F_26 ( int V_41 )
{
return ( V_41 & 0x0000ff00 ) >> 8 ;
}
static int F_27 ( struct V_43 * V_21 ,
struct V_44 * V_45 )
{
int V_46 , V_47 , V_41 , V_7 , V_48 , V_36 ;
if ( ! V_20 . V_32 )
return - V_26 ;
V_48 = 1 ;
V_36 = F_21 ( V_20 . V_32 , 1 ) ;
if ( V_36 ) {
V_48 = 0 ;
V_36 = F_21 ( V_20 . V_32 , 0 ) ;
if ( V_36 ) {
F_28 ( L_1 ) ;
return - V_49 ;
}
}
V_46 = F_26 ( V_20 . V_32 -> V_50 ) ;
V_47 = F_26 ( V_20 . V_32 -> V_51 ) ;
V_41 = F_26 ( V_20 . V_32 -> V_51 ) ;
do {
V_7 = V_20 . V_32 -> V_52 [ V_41 - 1 ] ;
if ( F_25 ( V_7 ) )
break;
V_41 -- ;
} while ( V_41 >= V_46 );
if ( ( V_41 > 100 ) || ( V_41 < F_26 ( V_20 . V_32 -> V_50 ) ) ) {
F_28 ( L_2 ) ;
F_9 ( NULL ) ;
return - V_49 ;
}
V_45 -> V_53 = V_54 ;
V_45 -> V_55 . V_56 = F_23 ( V_7 ) ;
V_45 -> V_57 = 1 ;
return 0 ;
}
static int F_29 ( struct V_43 * V_21 , int V_58 )
{
return F_16 () ;
}
static void F_30 ( struct V_43 * V_21 )
{
}
static int F_31 ( struct V_43 * V_21 , int V_59 )
{
char V_60 = F_2 ( V_18 ) ;
V_60 &= 0xF0 ;
if ( V_60 == 0 )
return V_61 ;
if ( V_60 == 0x20 )
return V_62 ;
return V_63 ;
}
static unsigned int F_32 ( struct V_43 * V_21 ,
unsigned int V_64 , int V_59 )
{
return ( F_2 ( V_18 ) & 0xF0 ) == 0x60 ?
V_65 : 0 ;
}
static int F_15 ( struct V_43 * V_21 )
{
int V_66 ;
F_33 ( 0x1fffff , V_67 ) ;
for ( V_66 = 0xa0000000 ; V_66 < 0xa0200000 ; V_66 += 4 )
F_34 ( V_66 ) ;
return 0 ;
}
static int F_18 ( struct V_43 * V_21 ,
struct V_23 * V_68 )
{
F_12 ( & V_68 -> V_13 , V_68 -> V_12 ) ;
return 0 ;
}
static int F_9 ( short * V_69 )
{
struct V_23 * V_70 ;
short V_60 [ 5 ] ;
int V_71 ;
int V_36 = - V_30 ;
V_70 = F_17 ( sizeof( struct V_23 ) , V_25 ) ;
if ( ! V_70 )
return - V_26 ;
V_70 -> V_13 [ 0 ] = 0x13 ;
V_70 -> V_13 [ 4 ] = 10 ;
V_70 -> V_12 = 10 ;
if ( V_20 . V_27 && ! F_4 () ) {
V_36 = - V_37 ;
goto V_72;
}
V_20 . V_27 = 1 ;
F_18 ( V_20 . V_21 , V_70 ) ;
F_19 ( V_28 , V_20 . V_27 == 0 ,
V_4 ) ;
if ( V_20 . V_27 )
goto V_73;
F_22 ( V_10 , & V_60 , V_70 -> V_12 / 2 ) ;
if ( V_60 [ 1 ] & 40 ) {
F_28 ( L_3 ) ;
goto V_73;
}
V_71 = V_60 [ 1 ] & 0x0F ;
if ( V_71 < F_35 ( V_74 ) )
F_28 ( L_4 , V_74 [ V_71 ] . V_75 ) ;
else
F_36 ( L_5 , V_71 ) ;
if ( V_69 )
memcpy ( V_69 , & V_60 [ 4 ] , 2 ) ;
if ( V_71 < 2 )
V_36 = 0 ;
V_73:
V_20 . V_27 = 0 ;
V_72:
F_20 ( V_70 ) ;
return V_36 ;
}
static int F_37 ( struct V_43 * V_76 , unsigned int V_13 ,
void * V_77 )
{
return - V_39 ;
}
static int F_38 ( struct V_78 * V_79 , T_1 V_80 )
{
int V_81 ;
F_39 ( & V_82 ) ;
V_81 = F_40 ( V_20 . V_21 , V_79 , V_80 ) ;
F_41 ( & V_82 ) ;
return V_81 ;
}
static int F_42 ( struct V_83 * V_84 , T_1 V_80 )
{
F_39 ( & V_82 ) ;
F_43 ( V_20 . V_21 , V_80 ) ;
F_41 ( & V_82 ) ;
return 0 ;
}
static unsigned int F_44 ( struct V_83 * V_84 ,
unsigned int V_64 )
{
return F_45 ( V_20 . V_21 , V_64 ) ;
}
static int F_46 ( struct V_78 * V_79 , T_1 V_80 ,
unsigned V_13 , unsigned long V_77 )
{
int V_81 ;
F_39 ( & V_82 ) ;
V_81 = F_47 ( V_20 . V_21 , V_79 , V_80 , V_13 , V_77 ) ;
F_41 ( & V_82 ) ;
return V_81 ;
}
static T_2 F_48 ( int V_85 , void * V_86 )
{
V_20 . V_29 = F_2 ( V_9 ) ;
if ( V_20 . V_27 != 1 )
return V_87 ;
V_20 . V_27 = 0 ;
F_49 ( & V_28 ) ;
return V_87 ;
}
static T_2 F_50 ( int V_85 , void * V_86 )
{
V_20 . V_29 = F_2 ( V_9 ) ;
if ( V_20 . V_88 != 1 )
return V_87 ;
V_20 . V_88 = 0 ;
F_49 ( & V_89 ) ;
return V_87 ;
}
static int F_51 ( void )
{
int V_36 ;
V_36 = F_52 ( V_90 , F_48 ,
V_91 , L_6 , & V_20 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_52 ( V_92 , F_50 ,
V_91 , L_7 , & V_20 ) ;
if ( V_36 )
F_53 ( V_90 , & V_20 ) ;
return V_36 ;
}
static void F_54 ( struct V_93 * V_94 )
{
int V_36 , V_95 , V_96 ;
struct V_23 * V_97 ;
struct V_98 * V_99 , * V_100 ;
struct V_101 * V_102 ;
unsigned long V_2 ;
if ( F_55 ( & V_103 ) )
return;
V_97 = F_17 ( sizeof( struct V_23 ) , V_25 ) ;
if ( ! V_97 )
return;
V_97 -> V_13 [ 0 ] = 0x30 ;
V_97 -> V_13 [ 1 ] = 0x20 ;
F_56 ( & V_104 ) ;
F_57 (elem, next, &gdrom_deferred) {
V_102 = F_58 ( V_99 , struct V_101 , V_105 ) ;
F_59 ( & V_104 ) ;
V_95 = F_60 ( V_102 ) / V_106 + V_42 ;
V_96 = F_61 ( V_102 ) / V_106 ;
F_33 ( F_62 ( V_102 -> V_107 ) , V_108 ) ;
F_33 ( V_96 * V_109 , V_110 ) ;
F_33 ( 1 , V_111 ) ;
F_33 ( 1 , V_112 ) ;
V_97 -> V_13 [ 2 ] = ( V_95 >> 16 ) & 0xFF ;
V_97 -> V_13 [ 3 ] = ( V_95 >> 8 ) & 0xFF ;
V_97 -> V_13 [ 4 ] = V_95 & 0xFF ;
V_97 -> V_13 [ 8 ] = ( V_96 >> 16 ) & 0xFF ;
V_97 -> V_13 [ 9 ] = ( V_96 >> 8 ) & 0xFF ;
V_97 -> V_13 [ 10 ] = V_96 & 0xFF ;
F_10 ( 1 , V_18 ) ;
F_10 ( 0 , V_17 ) ;
F_10 ( 0 , V_14 ) ;
F_10 ( 0 , V_15 ) ;
F_10 ( 0 , V_113 ) ;
F_10 ( 0 , V_16 ) ;
V_2 = V_3 + V_114 / 2 ;
while ( F_1 () && F_5 ( V_3 , V_2 ) )
F_6 () ;
F_10 ( V_19 , V_9 ) ;
V_2 = V_3 + V_114 / 2 ;
while ( F_1 () && F_5 ( V_3 , V_2 ) )
F_6 () ;
V_20 . V_27 = 1 ;
V_20 . V_88 = 1 ;
F_13 ( V_10 , & V_97 -> V_13 , 6 ) ;
V_2 = V_3 + V_114 / 2 ;
while ( F_2 ( V_115 ) &&
F_5 ( V_3 , V_2 ) )
F_6 () ;
F_10 ( 1 , V_115 ) ;
F_19 ( V_89 ,
V_20 . V_88 == 0 , V_4 ) ;
V_36 = V_20 . V_88 ? - V_30 : 0 ;
V_20 . V_88 = 0 ;
V_20 . V_27 = 0 ;
F_56 ( & V_104 ) ;
F_63 ( & V_102 -> V_105 ) ;
F_64 ( V_102 , V_36 ) ;
}
F_59 ( & V_104 ) ;
F_20 ( V_97 ) ;
}
static void F_65 ( struct V_89 * V_116 )
{
struct V_101 * V_102 ;
while ( ( V_102 = F_66 ( V_116 ) ) != NULL ) {
if ( V_102 -> V_117 != V_118 ) {
F_67 ( V_119 L_8 ) ;
F_64 ( V_102 , - V_30 ) ;
continue;
}
if ( F_68 ( V_102 ) != V_120 ) {
F_69 ( L_9 ) ;
F_64 ( V_102 , - V_30 ) ;
continue;
}
F_70 ( & V_102 -> V_105 , & V_103 ) ;
F_71 ( & V_94 ) ;
}
}
static int F_72 ( void )
{
struct V_121 * V_122 ;
char * V_123 , * V_124 , * V_125 ;
int V_36 = - V_26 ;
V_122 = F_17 ( sizeof( struct V_121 ) , V_25 ) ;
if ( ! V_122 )
return V_36 ;
F_8 ( V_122 ) ;
V_123 = F_73 ( V_122 -> V_126 , 16 , V_25 ) ;
if ( ! V_123 )
goto V_127;
V_124 = F_73 ( V_122 -> V_128 , 16 , V_25 ) ;
if ( ! V_124 )
goto V_129;
V_125 = F_73 ( V_122 -> V_130 , 16 , V_25 ) ;
if ( ! V_125 )
goto V_131;
F_28 ( L_10 ,
V_123 , V_124 , V_125 ) ;
V_36 = 0 ;
F_20 ( V_125 ) ;
V_131:
F_20 ( V_124 ) ;
V_129:
F_20 ( V_123 ) ;
V_127:
F_20 ( V_122 ) ;
return V_36 ;
}
static int F_74 ( void )
{
F_10 ( 0x13 , V_18 ) ;
F_10 ( 0x22 , V_16 ) ;
if ( ! F_4 () )
return - V_37 ;
F_10 ( 0xEF , V_9 ) ;
if ( ! F_7 () )
return - V_37 ;
F_33 ( 0x8843407F , V_132 ) ;
F_33 ( 9 , V_133 ) ;
return 0 ;
}
static void F_75 ( void )
{
V_20 . V_21 -> V_134 = & V_135 ;
V_20 . V_21 -> V_136 = 1 ;
strcpy ( V_20 . V_21 -> V_137 , V_138 ) ;
V_20 . V_21 -> V_139 = V_140 | V_141 | V_142 |
V_143 ;
}
static void F_76 ( void )
{
V_20 . V_84 -> V_144 = V_145 ;
V_20 . V_84 -> V_146 = 1 ;
V_20 . V_84 -> V_147 = 1 ;
strcpy ( V_20 . V_84 -> V_148 , V_138 ) ;
}
static int F_77 ( void )
{
F_78 ( V_20 . V_149 , V_109 ) ;
F_79 ( V_20 . V_149 , 1 ) ;
F_80 ( V_20 . V_149 , 0x40000 ) ;
V_20 . V_84 -> V_150 = V_20 . V_149 ;
return F_74 () ;
}
static int F_81 ( struct V_151 * V_152 )
{
int V_36 ;
if ( F_14 () != 1 ) {
F_82 ( L_11 ) ;
return - V_153 ;
}
if ( F_72 () )
return - V_26 ;
V_145 = F_83 ( 0 , V_138 ) ;
if ( V_145 <= 0 )
return V_145 ;
F_28 ( L_12 ,
V_145 ) ;
V_20 . V_21 = F_17 ( sizeof( struct V_43 ) , V_25 ) ;
if ( ! V_20 . V_21 ) {
V_36 = - V_26 ;
goto V_154;
}
F_75 () ;
V_20 . V_84 = F_84 ( 1 ) ;
if ( ! V_20 . V_84 ) {
V_36 = - V_153 ;
goto V_155;
}
F_76 () ;
if ( F_85 ( V_20 . V_21 ) ) {
V_36 = - V_153 ;
goto V_156;
}
V_20 . V_84 -> V_157 = & V_158 ;
V_36 = F_51 () ;
if ( V_36 )
goto V_159;
V_20 . V_149 = F_86 ( F_65 , & V_104 ) ;
if ( ! V_20 . V_149 )
goto V_160;
V_36 = F_77 () ;
if ( V_36 )
goto V_161;
V_20 . V_32 = F_17 ( sizeof( struct V_31 ) , V_25 ) ;
if ( ! V_20 . V_32 )
goto V_161;
F_87 ( V_20 . V_84 ) ;
return 0 ;
V_161:
F_88 ( V_20 . V_149 ) ;
V_160:
F_53 ( V_92 , & V_20 ) ;
F_53 ( V_90 , & V_20 ) ;
V_159:
V_156:
F_89 ( V_20 . V_84 ) ;
V_155:
F_20 ( V_20 . V_21 ) ;
F_90 ( V_145 , V_138 ) ;
V_145 = 0 ;
V_154:
F_82 ( L_13 , V_36 ) ;
return V_36 ;
}
static int F_91 ( struct V_151 * V_152 )
{
F_92 ( & V_94 ) ;
F_88 ( V_20 . V_149 ) ;
F_53 ( V_90 , & V_20 ) ;
F_53 ( V_92 , & V_20 ) ;
F_89 ( V_20 . V_84 ) ;
if ( V_145 )
F_90 ( V_145 , V_138 ) ;
F_93 ( V_20 . V_21 ) ;
return 0 ;
}
static int T_3 F_94 ( void )
{
int V_162 ;
V_20 . V_32 = NULL ;
V_162 = F_95 ( & V_163 ) ;
if ( V_162 )
return V_162 ;
V_164 = F_96 ( V_138 , - 1 , NULL , 0 ) ;
if ( F_97 ( V_164 ) ) {
F_98 ( & V_163 ) ;
return F_99 ( V_164 ) ;
}
return 0 ;
}
static void T_4 F_100 ( void )
{
F_101 ( V_164 ) ;
F_98 ( & V_163 ) ;
F_20 ( V_20 . V_32 ) ;
}
