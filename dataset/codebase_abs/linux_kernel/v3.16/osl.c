static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
return V_2 ;
}
static void T_3 F_3 ( struct V_3 * V_4 ,
unsigned int V_5 , char * V_6 )
{
T_4 V_7 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_5 )
return;
if ( V_4 -> V_9 == V_10 )
F_4 ( V_7 , V_5 , V_6 ) ;
else if ( V_4 -> V_9 == V_11 )
F_5 ( V_7 , V_5 , V_6 ) ;
}
static int T_3 F_6 ( void )
{
F_3 ( & V_12 . V_13 , V_12 . V_14 ,
L_8 ) ;
F_3 ( & V_12 . V_15 , V_12 . V_14 ,
L_9 ) ;
F_3 ( & V_12 . V_16 , V_12 . V_17 ,
L_10 ) ;
F_3 ( & V_12 . V_18 , V_12 . V_17 ,
L_11 ) ;
if ( V_12 . V_19 == 4 )
F_3 ( & V_12 . V_20 , 4 , L_12 ) ;
F_3 ( & V_12 . V_21 , V_12 . V_22 ,
L_13 ) ;
if ( ! ( V_12 . V_23 & 0x1 ) )
F_3 ( & V_12 . V_24 ,
V_12 . V_23 , L_14 ) ;
if ( ! ( V_12 . V_25 & 0x1 ) )
F_3 ( & V_12 . V_26 ,
V_12 . V_25 , L_15 ) ;
return 0 ;
}
void F_7 ( const char * V_27 , ... )
{
T_5 args ;
va_start ( args , V_27 ) ;
F_8 ( V_27 , args ) ;
va_end ( args ) ;
}
void F_8 ( const char * V_27 , T_5 args )
{
static char V_28 [ 512 ] ;
vsprintf ( V_28 , V_27 , args ) ;
#ifdef F_9
if ( V_29 ) {
F_10 ( L_16 , V_28 ) ;
} else {
F_11 ( V_30 L_16 , V_28 ) ;
}
#else
F_11 ( V_30 L_16 , V_28 ) ;
#endif
}
static int T_3 F_12 ( char * V_31 )
{
if ( F_13 ( V_31 , 16 , & V_32 ) )
return - V_33 ;
return 0 ;
}
T_6 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_32 )
return V_32 ;
#endif
if ( F_16 ( V_34 ) ) {
if ( V_35 . V_36 != V_37 )
return V_35 . V_36 ;
else if ( V_35 . V_38 != V_37 )
return V_35 . V_38 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_6 V_39 = 0 ;
F_17 ( & V_39 ) ;
return V_39 ;
}
}
static struct V_40 *
F_18 ( T_6 V_41 , T_7 V_42 )
{
struct V_40 * V_43 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_43 -> V_41 <= V_41 &&
V_41 + V_42 <= V_43 -> V_41 + V_43 -> V_42 )
return V_43 ;
return NULL ;
}
static void T_8 *
F_20 ( T_6 V_41 , unsigned int V_42 )
{
struct V_40 * V_43 ;
V_43 = F_18 ( V_41 , V_42 ) ;
if ( V_43 )
return V_43 -> V_44 + ( V_41 - V_43 -> V_41 ) ;
return NULL ;
}
void T_8 * F_21 ( T_6 V_41 , unsigned int V_42 )
{
struct V_40 * V_43 ;
void T_8 * V_44 = NULL ;
F_22 ( & V_45 ) ;
V_43 = F_18 ( V_41 , V_42 ) ;
if ( V_43 ) {
V_44 = V_43 -> V_44 + ( V_41 - V_43 -> V_41 ) ;
V_43 -> V_46 ++ ;
}
F_23 ( & V_45 ) ;
return V_44 ;
}
static struct V_40 *
F_24 ( void T_8 * V_44 , T_7 V_42 )
{
struct V_40 * V_43 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_43 -> V_44 <= V_44 &&
V_44 + V_42 <= V_43 -> V_44 + V_43 -> V_42 )
return V_43 ;
return NULL ;
}
static void T_8 * F_25 ( T_6 V_47 , unsigned long V_48 )
{
unsigned long V_49 ;
V_49 = V_47 >> V_50 ;
if ( F_26 ( V_49 ) ) {
if ( V_48 > V_51 )
return NULL ;
return ( void T_8 V_52 * ) F_27 ( F_28 ( V_49 ) ) ;
} else
return F_29 ( V_47 , V_48 ) ;
}
static void F_30 ( T_6 V_47 , void T_8 * V_53 )
{
unsigned long V_49 ;
V_49 = V_47 >> V_50 ;
if ( F_26 ( V_49 ) )
F_31 ( F_28 ( V_49 ) ) ;
else
F_32 ( V_53 ) ;
}
void T_8 * T_9
F_33 ( T_6 V_41 , T_7 V_42 )
{
struct V_40 * V_43 ;
void T_8 * V_44 ;
T_6 V_47 ;
T_7 V_48 ;
if ( V_41 > V_54 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_55 )
return F_34 ( ( unsigned long ) V_41 , V_42 ) ;
F_22 ( & V_45 ) ;
V_43 = F_18 ( V_41 , V_42 ) ;
if ( V_43 ) {
V_43 -> V_46 ++ ;
goto V_56;
}
V_43 = F_35 ( sizeof( * V_43 ) , V_57 ) ;
if ( ! V_43 ) {
F_23 ( & V_45 ) ;
return NULL ;
}
V_47 = F_36 ( V_41 , V_51 ) ;
V_48 = F_37 ( V_41 + V_42 , V_51 ) - V_47 ;
V_44 = F_25 ( V_47 , V_48 ) ;
if ( ! V_44 ) {
F_23 ( & V_45 ) ;
F_38 ( V_43 ) ;
return NULL ;
}
F_39 ( & V_43 -> V_58 ) ;
V_43 -> V_44 = V_44 ;
V_43 -> V_41 = V_47 ;
V_43 -> V_42 = V_48 ;
V_43 -> V_46 = 1 ;
F_40 ( & V_43 -> V_58 , & V_59 ) ;
V_56:
F_23 ( & V_45 ) ;
return V_43 -> V_44 + ( V_41 - V_43 -> V_41 ) ;
}
void * T_9
F_41 ( T_6 V_41 , T_7 V_42 )
{
return ( void * ) F_33 ( V_41 , V_42 ) ;
}
static void F_42 ( struct V_40 * V_43 )
{
if ( ! -- V_43 -> V_46 )
F_43 ( & V_43 -> V_58 ) ;
}
static void F_44 ( struct V_40 * V_43 )
{
if ( ! V_43 -> V_46 ) {
F_45 () ;
F_30 ( V_43 -> V_41 , V_43 -> V_44 ) ;
F_38 ( V_43 ) ;
}
}
void T_10 F_46 ( void T_8 * V_44 , T_7 V_42 )
{
struct V_40 * V_43 ;
if ( ! V_55 ) {
F_47 ( V_44 , V_42 ) ;
return;
}
F_22 ( & V_45 ) ;
V_43 = F_24 ( V_44 , V_42 ) ;
if ( ! V_43 ) {
F_23 ( & V_45 ) ;
F_48 ( true , V_60 L_19 , V_61 , V_44 ) ;
return;
}
F_42 ( V_43 ) ;
F_23 ( & V_45 ) ;
F_44 ( V_43 ) ;
}
void T_10 F_49 ( void * V_44 , T_7 V_42 )
{
return F_46 ( ( void T_8 * ) V_44 , V_42 ) ;
}
void T_3 F_50 ( void T_8 * V_44 , T_7 V_42 )
{
if ( ! V_55 )
F_47 ( V_44 , V_42 ) ;
}
int F_51 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_44 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_62 )
return - V_33 ;
V_44 = F_33 ( V_7 , V_4 -> V_62 / 8 ) ;
if ( ! V_44 )
return - V_63 ;
return 0 ;
}
void F_52 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_40 * V_43 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_62 )
return;
F_22 ( & V_45 ) ;
V_43 = F_18 ( V_7 , V_4 -> V_62 / 8 ) ;
if ( ! V_43 ) {
F_23 ( & V_45 ) ;
return;
}
F_42 ( V_43 ) ;
F_23 ( & V_45 ) ;
F_44 ( V_43 ) ;
}
T_11
F_53 ( void * V_44 , T_6 * V_41 )
{
if ( ! V_41 || ! V_44 )
return V_64 ;
* V_41 = F_54 ( V_44 ) ;
return V_65 ;
}
T_11
F_55 ( const struct V_66 * V_67 ,
T_2 * V_68 )
{
if ( ! V_67 || ! V_68 )
return V_64 ;
* V_68 = NULL ;
if ( ! memcmp ( V_67 -> V_69 , L_20 , 4 ) && strlen ( V_70 ) ) {
F_11 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_68 = V_70 ;
}
return V_65 ;
}
static T_12 T_3 F_56 ( T_12 * V_28 , T_1 V_5 )
{
T_12 V_71 = 0 ;
T_12 * V_72 = V_28 + V_5 ;
while ( V_28 < V_72 )
V_71 = ( T_12 ) ( V_71 + * ( V_28 ++ ) ) ;
return V_71 ;
}
void T_3 F_57 ( void * V_73 , T_13 V_42 )
{
int V_74 , V_75 , V_76 = 0 , V_77 = 0 ;
long V_78 = 0 ;
struct V_79 * V_80 ;
char V_81 [ 32 ] = L_22 ;
struct V_82 V_83 ;
if ( V_73 == NULL || V_42 == 0 )
return;
for ( V_75 = 0 ; V_75 < V_84 ; V_75 ++ ) {
V_83 = F_58 ( V_81 , V_73 , V_42 , & V_78 ) ;
if ( ! V_83 . V_73 )
break;
V_73 += V_78 ;
V_42 -= V_78 ;
if ( V_83 . V_42 < sizeof( struct V_79 ) ) {
F_59 ( L_23 ,
V_81 , V_83 . V_69 ) ;
continue;
}
V_80 = V_83 . V_73 ;
for ( V_74 = 0 ; V_85 [ V_74 ] ; V_74 ++ )
if ( ! memcmp ( V_80 -> V_86 , V_85 [ V_74 ] , 4 ) )
break;
if ( ! V_85 [ V_74 ] ) {
F_59 ( L_24 ,
V_81 , V_83 . V_69 ) ;
continue;
}
if ( V_83 . V_42 != V_80 -> V_5 ) {
F_59 ( L_25 ,
V_81 , V_83 . V_69 ) ;
continue;
}
if ( F_56 ( V_83 . V_73 , V_80 -> V_5 ) ) {
F_59 ( L_26 ,
V_81 , V_83 . V_69 ) ;
continue;
}
F_60 ( L_27 ,
V_80 -> V_86 , V_81 , V_83 . V_69 , V_80 -> V_5 ) ;
V_87 += V_80 -> V_5 ;
V_88 [ V_76 ] . V_73 = V_83 . V_73 ;
V_88 [ V_76 ] . V_42 = V_83 . V_42 ;
V_76 ++ ;
}
if ( V_76 == 0 )
return;
V_89 =
F_61 ( 0 , V_90 << V_50 ,
V_87 , V_51 ) ;
if ( ! V_89 ) {
F_62 ( 1 ) ;
return;
}
F_63 ( V_89 , V_87 ) ;
F_64 ( V_89 , V_87 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
unsigned char * V_91 = V_88 [ V_75 ] . V_73 ;
T_14 V_42 = V_88 [ V_75 ] . V_42 ;
T_14 V_92 = V_89 + V_77 ;
T_14 V_93 , V_94 ;
char * V_95 ;
V_77 += V_42 ;
while ( V_42 ) {
V_93 = V_92 & ~ V_96 ;
V_94 = V_42 ;
if ( V_94 > V_97 - V_93 )
V_94 = V_97 - V_93 ;
V_95 = F_65 ( V_92 & V_96 ,
V_94 + V_93 ) ;
memcpy ( V_95 + V_93 , V_91 , V_94 ) ;
F_66 ( V_95 , V_94 + V_93 ) ;
V_91 += V_94 ;
V_92 += V_94 ;
V_42 -= V_94 ;
}
}
}
static void F_67 ( struct V_79 * V_80 )
{
F_68 ( V_60
L_28 ,
V_80 -> V_86 , V_80 -> V_98 ) ;
F_69 ( V_99 , V_100 ) ;
}
T_11
F_70 ( struct V_79 * V_101 ,
struct V_79 * * V_102 )
{
if ( ! V_101 || ! V_102 )
return V_64 ;
* V_102 = NULL ;
#ifdef F_71
if ( strncmp ( V_101 -> V_86 , L_29 , 4 ) == 0 )
* V_102 = (struct V_79 * ) V_103 ;
#endif
if ( * V_102 != NULL )
F_67 ( V_101 ) ;
return V_65 ;
}
T_11
F_72 ( struct V_79 * V_101 ,
T_6 * V_8 ,
T_1 * V_104 )
{
#ifndef F_73
* V_104 = 0 ;
* V_8 = 0 ;
return V_65 ;
#else
int V_105 = 0 ;
struct V_79 * V_80 ;
* V_104 = 0 ;
* V_8 = 0 ;
if ( ! V_89 )
return V_65 ;
do {
if ( V_105 + V_106 > V_87 ) {
F_62 ( 1 ) ;
return V_65 ;
}
V_80 = F_41 ( V_89 + V_105 ,
V_106 ) ;
if ( V_105 + V_80 -> V_5 > V_87 ) {
F_49 ( V_80 , V_106 ) ;
F_62 ( 1 ) ;
return V_65 ;
}
V_105 += V_80 -> V_5 ;
if ( memcmp ( V_101 -> V_86 , V_80 -> V_86 , 4 ) ) {
F_49 ( V_80 ,
V_106 ) ;
continue;
}
if ( memcmp ( V_80 -> V_98 , V_101 -> V_98 ,
V_107 ) ) {
F_49 ( V_80 ,
V_106 ) ;
continue;
}
V_105 -= V_80 -> V_5 ;
* V_104 = V_80 -> V_5 ;
F_49 ( V_80 , V_106 ) ;
* V_8 = V_89 + V_105 ;
break;
} while ( V_105 + V_106 < V_87 );
if ( * V_8 != 0 )
F_67 ( V_101 ) ;
return V_65 ;
#endif
}
static T_15 F_74 ( int V_108 , void * V_109 )
{
T_1 V_110 ;
V_110 = (* F_75) ( V_111 ) ;
if ( V_110 ) {
V_112 ++ ;
return V_113 ;
} else {
V_114 ++ ;
return V_115 ;
}
}
T_11
F_76 ( T_1 V_116 , T_16 V_117 ,
void * V_118 )
{
unsigned int V_108 ;
F_77 () ;
if ( V_116 != V_12 . V_119 )
return V_64 ;
if ( F_75 )
return V_120 ;
if ( F_78 ( V_116 , & V_108 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_30 ,
gsi) ;
return V_65 ;
}
F_75 = V_117 ;
V_111 = V_118 ;
if ( F_79 ( V_108 , F_74 , V_121 | V_122 , L_31 , F_74 ) ) {
F_11 (KERN_ERR PREFIX L_32 , irq) ;
F_75 = NULL ;
return V_123 ;
}
return V_65 ;
}
T_11 F_80 ( T_1 V_108 , T_16 V_117 )
{
if ( V_108 != V_12 . V_119 )
return V_64 ;
F_81 ( V_108 , F_74 ) ;
F_75 = NULL ;
return V_65 ;
}
void F_82 ( T_4 V_124 )
{
F_83 ( V_124 ) ;
}
void F_84 ( T_1 V_125 )
{
while ( V_125 ) {
T_1 V_126 = 1000 ;
if ( V_126 > V_125 )
V_126 = V_125 ;
F_85 ( V_126 ) ;
F_86 () ;
V_125 -= V_126 ;
}
}
T_4 F_87 ( void )
{
T_4 V_127 = F_88 ( F_89 () ) ;
F_90 ( V_127 , 100 ) ;
return V_127 ;
}
T_11 F_91 ( T_17 V_128 , T_1 * V_129 , T_1 V_130 )
{
T_1 V_131 ;
if ( ! V_129 )
V_129 = & V_131 ;
* V_129 = 0 ;
if ( V_130 <= 8 ) {
* ( T_12 * ) V_129 = F_92 ( V_128 ) ;
} else if ( V_130 <= 16 ) {
* ( V_132 * ) V_129 = F_93 ( V_128 ) ;
} else if ( V_130 <= 32 ) {
* ( T_1 * ) V_129 = F_94 ( V_128 ) ;
} else {
F_95 () ;
}
return V_65 ;
}
T_11 F_96 ( T_17 V_128 , T_1 V_129 , T_1 V_130 )
{
if ( V_130 <= 8 ) {
F_97 ( V_129 , V_128 ) ;
} else if ( V_130 <= 16 ) {
F_98 ( V_129 , V_128 ) ;
} else if ( V_130 <= 32 ) {
F_99 ( V_129 , V_128 ) ;
} else {
F_95 () ;
}
return V_65 ;
}
static inline T_4 F_100 ( const volatile void T_8 * V_7 )
{
return F_101 ( V_7 ) ;
}
static inline T_4 F_100 ( const volatile void T_8 * V_7 )
{
T_4 V_133 , V_134 ;
V_133 = F_102 ( V_7 ) ;
V_134 = F_102 ( V_7 + 4 ) ;
return V_133 | ( V_134 << 32 ) ;
}
T_11
F_103 ( T_6 V_135 , T_4 * V_129 , T_1 V_130 )
{
void T_8 * V_136 ;
unsigned int V_42 = V_130 / 8 ;
bool V_137 = false ;
T_4 V_131 ;
F_104 () ;
V_136 = F_20 ( V_135 , V_42 ) ;
if ( ! V_136 ) {
F_105 () ;
V_136 = F_29 ( V_135 , V_42 ) ;
if ( ! V_136 )
return V_138 ;
V_137 = true ;
}
if ( ! V_129 )
V_129 = & V_131 ;
switch ( V_130 ) {
case 8 :
* ( T_12 * ) V_129 = F_106 ( V_136 ) ;
break;
case 16 :
* ( V_132 * ) V_129 = F_107 ( V_136 ) ;
break;
case 32 :
* ( T_1 * ) V_129 = F_102 ( V_136 ) ;
break;
case 64 :
* ( T_4 * ) V_129 = F_100 ( V_136 ) ;
break;
default:
F_95 () ;
}
if ( V_137 )
F_32 ( V_136 ) ;
else
F_105 () ;
return V_65 ;
}
static inline void F_108 ( T_4 V_139 , volatile void T_8 * V_7 )
{
F_109 ( V_139 , V_7 ) ;
}
static inline void F_108 ( T_4 V_139 , volatile void T_8 * V_7 )
{
F_110 ( V_139 , V_7 ) ;
F_110 ( V_139 >> 32 , V_7 + 4 ) ;
}
T_11
F_111 ( T_6 V_135 , T_4 V_129 , T_1 V_130 )
{
void T_8 * V_136 ;
unsigned int V_42 = V_130 / 8 ;
bool V_137 = false ;
F_104 () ;
V_136 = F_20 ( V_135 , V_42 ) ;
if ( ! V_136 ) {
F_105 () ;
V_136 = F_29 ( V_135 , V_42 ) ;
if ( ! V_136 )
return V_138 ;
V_137 = true ;
}
switch ( V_130 ) {
case 8 :
F_112 ( V_129 , V_136 ) ;
break;
case 16 :
F_113 ( V_129 , V_136 ) ;
break;
case 32 :
F_110 ( V_129 , V_136 ) ;
break;
case 64 :
F_108 ( V_129 , V_136 ) ;
break;
default:
F_95 () ;
}
if ( V_137 )
F_32 ( V_136 ) ;
else
F_105 () ;
return V_65 ;
}
T_11
F_114 ( struct V_140 * V_141 , T_1 V_142 ,
T_4 * V_129 , T_1 V_130 )
{
int V_143 , V_42 ;
T_1 V_144 ;
if ( ! V_129 )
return V_64 ;
switch ( V_130 ) {
case 8 :
V_42 = 1 ;
break;
case 16 :
V_42 = 2 ;
break;
case 32 :
V_42 = 4 ;
break;
default:
return V_145 ;
}
V_143 = F_115 ( V_141 -> V_146 , V_141 -> V_147 ,
F_116 ( V_141 -> V_148 , V_141 -> V_149 ) ,
V_142 , V_42 , & V_144 ) ;
* V_129 = V_144 ;
return ( V_143 ? V_145 : V_65 ) ;
}
T_11
F_117 ( struct V_140 * V_141 , T_1 V_142 ,
T_4 V_129 , T_1 V_130 )
{
int V_143 , V_42 ;
switch ( V_130 ) {
case 8 :
V_42 = 1 ;
break;
case 16 :
V_42 = 2 ;
break;
case 32 :
V_42 = 4 ;
break;
default:
return V_145 ;
}
V_143 = F_118 ( V_141 -> V_146 , V_141 -> V_147 ,
F_116 ( V_141 -> V_148 , V_141 -> V_149 ) ,
V_142 , V_42 , V_129 ) ;
return ( V_143 ? V_145 : V_65 ) ;
}
static void F_119 ( struct V_150 * V_151 )
{
struct V_152 * V_153 = F_120 ( V_151 , struct V_152 , V_151 ) ;
V_153 -> V_149 ( V_153 -> V_118 ) ;
F_38 ( V_153 ) ;
}
T_11 F_121 ( T_18 type ,
T_19 V_149 , void * V_118 )
{
T_11 V_154 = V_65 ;
struct V_152 * V_153 ;
struct V_155 * V_156 ;
int V_157 ;
F_122 ( ( V_158 ,
L_33 ,
V_149 , V_118 ) ) ;
V_153 = F_35 ( sizeof( struct V_152 ) , V_159 ) ;
if ( ! V_153 )
return V_160 ;
V_153 -> V_149 = V_149 ;
V_153 -> V_118 = V_118 ;
if ( type == V_161 ) {
V_156 = V_162 ;
F_123 ( & V_153 -> V_151 , F_119 ) ;
} else {
V_156 = V_163 ;
F_123 ( & V_153 -> V_151 , F_119 ) ;
}
V_157 = F_124 ( 0 , V_156 , & V_153 -> V_151 ) ;
if ( ! V_157 ) {
F_11 (KERN_ERR PREFIX
L_34 ) ;
V_154 = V_145 ;
F_38 ( V_153 ) ;
}
return V_154 ;
}
void F_125 ( void )
{
F_126 ( V_163 ) ;
F_126 ( V_162 ) ;
}
static void F_127 ( struct V_150 * V_151 )
{
struct V_164 * V_165 = F_120 ( V_151 , struct V_164 , V_151 ) ;
F_125 () ;
F_128 ( V_165 -> V_166 , V_165 -> V_167 ) ;
F_38 ( V_165 ) ;
}
T_11 F_129 ( struct V_168 * V_166 , T_1 V_167 )
{
struct V_164 * V_165 ;
F_122 ( ( V_158 ,
L_35 ,
V_166 , V_167 ) ) ;
V_165 = F_130 ( sizeof( * V_165 ) , V_57 ) ;
if ( ! V_165 )
return V_160 ;
F_123 ( & V_165 -> V_151 , F_127 ) ;
V_165 -> V_166 = V_166 ;
V_165 -> V_167 = V_167 ;
if ( ! F_131 ( V_169 , & V_165 -> V_151 ) ) {
F_38 ( V_165 ) ;
return V_145 ;
}
return V_65 ;
}
bool F_132 ( struct V_150 * V_151 )
{
return F_131 ( V_169 , V_151 ) ;
}
T_11
F_133 ( T_1 V_170 , T_1 V_171 , T_20 * V_172 )
{
struct V_173 * V_174 = NULL ;
V_174 = F_134 ( sizeof( struct V_173 ) ) ;
if ( ! V_174 )
return V_160 ;
F_135 ( V_174 , V_171 ) ;
* V_172 = ( T_20 * ) V_174 ;
F_122 ( ( V_175 , L_36 ,
* V_172 , V_171 ) ) ;
return V_65 ;
}
T_11 F_136 ( T_20 V_172 )
{
struct V_173 * V_174 = (struct V_173 * ) V_172 ;
if ( ! V_174 )
return V_64 ;
F_122 ( ( V_175 , L_37 , V_172 ) ) ;
F_137 ( ! F_138 ( & V_174 -> V_176 ) ) ;
F_38 ( V_174 ) ;
V_174 = NULL ;
return V_65 ;
}
T_11 F_139 ( T_20 V_172 , T_1 V_177 , V_132 V_178 )
{
T_11 V_154 = V_65 ;
struct V_173 * V_174 = (struct V_173 * ) V_172 ;
long V_179 ;
int V_157 = 0 ;
if ( ! V_174 || ( V_177 < 1 ) )
return V_64 ;
if ( V_177 > 1 )
return V_180 ;
F_122 ( ( V_175 , L_38 ,
V_172 , V_177 , V_178 ) ) ;
if ( V_178 == V_181 )
V_179 = V_182 ;
else
V_179 = F_140 ( V_178 ) ;
V_157 = F_141 ( V_174 , V_179 ) ;
if ( V_157 )
V_154 = V_183 ;
if ( F_142 ( V_154 ) ) {
F_122 ( ( V_175 ,
L_39 ,
V_172 , V_177 , V_178 ,
F_143 ( V_154 ) ) ) ;
} else {
F_122 ( ( V_175 ,
L_40 , V_172 ,
V_177 , V_178 ) ) ;
}
return V_154 ;
}
T_11 F_144 ( T_20 V_172 , T_1 V_177 )
{
struct V_173 * V_174 = (struct V_173 * ) V_172 ;
if ( ! V_174 || ( V_177 < 1 ) )
return V_64 ;
if ( V_177 > 1 )
return V_180 ;
F_122 ( ( V_175 , L_41 , V_172 ,
V_177 ) ) ;
F_145 ( V_174 ) ;
return V_65 ;
}
T_1 F_146 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_184 ;
F_147 ( V_28 , sizeof( V_185 ) ) ;
V_184 = strlen ( V_28 ) - 1 ;
V_28 [ V_184 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_148 ( T_1 V_149 , void * V_186 )
{
switch ( V_149 ) {
case V_187 :
F_11 (KERN_ERR PREFIX L_42 ) ;
break;
case V_188 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_149 ( char * V_189 )
{
char * V_190 = V_70 ;
int V_191 = V_192 - 1 ;
if ( ! V_189 || ! * V_189 )
return 0 ;
for (; V_191 -- && * V_189 ; V_189 ++ ) {
if ( isalnum ( * V_189 ) || * V_189 == ' ' || * V_189 == ':' )
* V_190 ++ = * V_189 ;
else if ( * V_189 == '\'' || * V_189 == '"' )
continue;
else
break;
}
* V_190 = 0 ;
return 1 ;
}
void T_3 F_150 ( char * V_189 )
{
struct V_193 * V_194 ;
bool V_195 = true ;
int V_196 ;
if ( ! V_197 )
return;
if ( V_189 == NULL || * V_189 == '\0' ) {
F_11 (KERN_INFO PREFIX L_43 ) ;
V_197 = FALSE ;
return;
}
if ( * V_189 == '!' ) {
V_189 ++ ;
if ( * V_189 == '\0' ) {
V_198 . V_199 = 1 ;
return;
} else if ( * V_189 == '*' ) {
F_151 ( V_200 ) ;
for ( V_196 = 0 ; V_196 < V_201 ; V_196 ++ ) {
V_194 = & V_202 [ V_196 ] ;
V_194 -> V_195 = false ;
}
return;
}
V_195 = false ;
}
for ( V_196 = 0 ; V_196 < V_201 ; V_196 ++ ) {
V_194 = & V_202 [ V_196 ] ;
if ( ! strcmp ( V_194 -> string , V_189 ) ) {
V_194 -> V_195 = V_195 ;
break;
} else if ( V_194 -> string [ 0 ] == '\0' ) {
V_194 -> V_195 = V_195 ;
strncpy ( V_194 -> string , V_189 , V_203 ) ;
break;
}
}
}
static void T_3 F_152 ( unsigned int V_195 )
{
if ( V_198 . V_195 != V_195 )
V_198 . V_195 = V_195 ;
if ( V_198 . V_195 )
F_150 ( L_1 ) ;
else
F_150 ( L_44 ) ;
return;
}
static void T_3 F_153 ( unsigned int V_195 )
{
V_198 . V_204 = 1 ;
V_198 . V_205 = 0 ;
F_152 ( V_195 ) ;
return;
}
void T_3 F_154 ( int V_195 , const struct V_206 * V_207 )
{
F_11 (KERN_NOTICE PREFIX L_45 , d->ident) ;
if ( V_195 == - 1 )
return;
V_198 . V_205 = 1 ;
F_152 ( V_195 ) ;
return;
}
static void T_3 F_155 ( void )
{
struct V_193 * V_194 ;
char * V_189 ;
int V_196 ;
T_11 V_154 ;
if ( V_198 . V_199 ) {
V_154 = F_151 ( V_208 ) ;
if ( F_156 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_46 ) ;
}
for ( V_196 = 0 ; V_196 < V_201 ; V_196 ++ ) {
V_194 = & V_202 [ V_196 ] ;
V_189 = V_194 -> string ;
if ( * V_189 == '\0' )
break;
if ( V_194 -> V_195 ) {
V_154 = F_157 ( V_189 ) ;
if ( F_156 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_47 , str) ;
} else {
V_154 = F_158 ( V_189 ) ;
if ( F_156 ( V_154 ) )
F_11 (KERN_INFO PREFIX L_48 , str) ;
}
}
}
static int T_3 F_159 ( char * V_189 )
{
if ( V_189 && ! strcmp ( L_1 , V_189 ) )
F_153 ( 1 ) ;
else if ( V_189 && ! strcmp ( L_44 , V_189 ) )
F_153 ( 0 ) ;
else
F_150 ( V_189 ) ;
return 1 ;
}
static int T_3 F_160 ( char * V_189 )
{
V_209 = FALSE ;
F_60 ( L_49 ) ;
return 1 ;
}
static int T_3 F_161 ( char * V_189 )
{
if ( V_189 == NULL || * V_189 == '\0' )
return 0 ;
if ( ! strcmp ( L_50 , V_189 ) )
V_210 = V_211 ;
else if ( ! strcmp ( L_51 , V_189 ) )
V_210 = V_212 ;
else if ( ! strcmp ( L_52 , V_189 ) )
V_210 = V_213 ;
return 1 ;
}
int F_162 ( const struct V_214 * V_215 )
{
T_21 V_9 ;
T_7 V_5 ;
T_12 V_216 = 0 ;
int V_217 = 0 ;
if ( V_210 == V_213 )
return 0 ;
if ( ! ( V_215 -> V_218 & V_219 ) && ! ( V_215 -> V_218 & V_220 ) )
return 0 ;
if ( V_215 -> V_218 & V_219 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = F_163 ( V_215 ) ;
if ( V_210 != V_213 )
V_216 = 1 ;
V_217 = F_164 ( V_9 , V_215 -> V_221 , V_5 , V_216 ) ;
if ( V_217 ) {
if ( V_210 != V_213 ) {
if ( V_210 == V_212 )
F_11 ( V_222 L_53
L_54
L_55 ) ;
F_11 ( V_223 L_56
L_57
L_58 ) ;
}
if ( V_210 == V_211 )
return - V_224 ;
}
return 0 ;
}
int F_165 ( T_22 V_221 , T_22 V_225 ,
const char * V_69 )
{
struct V_214 V_215 = {
. V_221 = V_221 ,
. V_72 = V_221 + V_225 - 1 ,
. V_69 = V_69 ,
. V_218 = V_219 ,
} ;
return F_162 ( & V_215 ) ;
}
int F_166 ( void )
{
return V_210 == V_211 ;
}
void F_167 ( T_23 V_172 )
{
F_168 ( V_172 ) ;
}
T_24 F_169 ( T_23 V_226 )
{
T_24 V_218 ;
F_170 ( V_226 , V_218 ) ;
return V_218 ;
}
void F_171 ( T_23 V_226 , T_24 V_218 )
{
F_172 ( V_226 , V_218 ) ;
}
T_11
F_173 ( char * V_69 , V_132 V_42 , V_132 V_227 , T_25 * * V_228 )
{
* V_228 = F_174 ( V_69 , V_42 , 0 , 0 , NULL ) ;
if ( * V_228 == NULL )
return V_145 ;
else
return V_65 ;
}
T_11 F_175 ( T_25 * V_228 )
{
F_176 ( V_228 ) ;
return ( V_65 ) ;
}
T_11 F_177 ( T_25 * V_228 )
{
F_178 ( V_228 ) ;
return ( V_65 ) ;
}
T_11 F_179 ( T_25 * V_228 , void * V_229 )
{
F_180 ( V_228 , V_229 ) ;
return ( V_65 ) ;
}
static int T_3 F_181 ( char * V_230 )
{
V_231 = TRUE ;
F_60 ( L_59 ) ;
return 0 ;
}
static int T_3 F_182 ( char * V_230 )
{
F_11 (KERN_NOTICE PREFIX
L_60 ) ;
V_232 = TRUE ;
return 1 ;
}
T_11 T_3 F_183 ( void )
{
F_51 ( & V_12 . V_13 ) ;
F_51 ( & V_12 . V_15 ) ;
F_51 ( & V_12 . V_24 ) ;
F_51 ( & V_12 . V_26 ) ;
if ( V_12 . V_218 & V_233 ) {
int V_234 ;
V_234 = F_51 ( & V_12 . V_235 ) ;
F_184 ( V_60 L_61 , V_61 , V_234 ) ;
}
return V_65 ;
}
T_11 T_3 F_185 ( void )
{
V_163 = F_186 ( L_62 , 0 , 1 ) ;
V_162 = F_186 ( L_63 , 0 , 1 ) ;
V_169 = F_187 ( L_64 , 0 ) ;
F_137 ( ! V_163 ) ;
F_137 ( ! V_162 ) ;
F_137 ( ! V_169 ) ;
F_188 ( F_1 ) ;
F_155 () ;
return V_65 ;
}
T_11 F_189 ( void )
{
if ( F_75 ) {
F_80 ( V_12 . V_119 ,
F_75 ) ;
}
F_52 ( & V_12 . V_26 ) ;
F_52 ( & V_12 . V_24 ) ;
F_52 ( & V_12 . V_15 ) ;
F_52 ( & V_12 . V_13 ) ;
if ( V_12 . V_218 & V_233 )
F_52 ( & V_12 . V_235 ) ;
F_190 ( V_163 ) ;
F_190 ( V_162 ) ;
F_190 ( V_169 ) ;
return V_65 ;
}
T_11 F_191 ( T_12 V_236 , T_1 V_237 ,
T_1 V_238 )
{
int V_239 = 0 ;
if ( V_240 )
V_239 = V_240 ( V_236 ,
V_237 , V_238 ) ;
if ( V_239 < 0 )
return V_145 ;
else if ( V_239 > 0 )
return V_241 ;
return V_65 ;
}
void F_192 ( int (* F_193)( T_12 V_236 ,
T_1 V_242 , T_1 V_243 ) )
{
V_240 = F_193 ;
}
T_11 F_194 ( T_12 V_236 , T_1 V_244 ,
T_1 V_245 )
{
int V_239 = 0 ;
if ( V_246 )
V_239 = V_246 ( V_236 ,
V_244 , V_245 ) ;
if ( V_239 < 0 )
return V_145 ;
else if ( V_239 > 0 )
return V_241 ;
return V_65 ;
}
void F_195 ( int (* F_193)( T_12 V_236 ,
T_1 V_244 , T_1 V_245 ) )
{
V_246 = F_193 ;
}
