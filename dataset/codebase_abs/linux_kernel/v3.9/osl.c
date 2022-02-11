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
V_32 = F_13 ( V_31 , NULL , 16 ) ;
return 0 ;
}
T_6 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_32 )
return V_32 ;
#endif
if ( F_16 ( V_33 ) ) {
if ( V_34 . V_35 != V_36 )
return V_34 . V_35 ;
else if ( V_34 . V_37 != V_36 )
return V_34 . V_37 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_6 V_38 = 0 ;
F_17 ( & V_38 ) ;
return V_38 ;
}
}
static struct V_39 *
F_18 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 *
F_20 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_8 * F_21 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 = NULL ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_43 = V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
V_42 -> V_45 ++ ;
}
F_23 ( & V_44 ) ;
return V_43 ;
}
static struct V_39 *
F_24 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 * F_25 ( T_6 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_8 V_51 * ) F_27 ( F_28 ( V_48 ) ) ;
} else
return F_29 ( V_46 , V_47 ) ;
}
static void F_30 ( T_6 V_46 , void T_8 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) )
F_31 ( F_28 ( V_48 ) ) ;
else
F_32 ( V_52 ) ;
}
void T_8 * T_9
F_33 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 ;
T_6 V_46 ;
T_7 V_47 ;
if ( V_40 > V_53 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
return NULL ;
}
if ( ! V_54 )
return F_34 ( ( unsigned long ) V_40 , V_41 ) ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_45 ++ ;
goto V_55;
}
V_42 = F_35 ( sizeof( * V_42 ) , V_56 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return NULL ;
}
V_46 = F_36 ( V_40 , V_50 ) ;
V_47 = F_37 ( V_40 + V_41 , V_50 ) - V_46 ;
V_43 = F_25 ( V_46 , V_47 ) ;
if ( ! V_43 ) {
F_23 ( & V_44 ) ;
F_38 ( V_42 ) ;
return NULL ;
}
F_39 ( & V_42 -> V_57 ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_40 = V_46 ;
V_42 -> V_41 = V_47 ;
V_42 -> V_45 = 1 ;
F_40 ( & V_42 -> V_57 , & V_58 ) ;
V_55:
F_23 ( & V_44 ) ;
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
}
static void F_41 ( struct V_39 * V_42 )
{
if ( ! -- V_42 -> V_45 )
F_42 ( & V_42 -> V_57 ) ;
}
static void F_43 ( struct V_39 * V_42 )
{
if ( ! V_42 -> V_45 ) {
F_44 () ;
F_30 ( V_42 -> V_40 , V_42 -> V_43 ) ;
F_38 ( V_42 ) ;
}
}
void T_10 F_45 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
if ( ! V_54 ) {
F_46 ( V_43 , V_41 ) ;
return;
}
F_22 ( & V_44 ) ;
V_42 = F_24 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
F_47 ( true , V_59 L_19 , V_60 , V_43 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
void T_3 F_48 ( void T_8 * V_43 , T_7 V_41 )
{
if ( ! V_54 )
F_46 ( V_43 , V_41 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_43 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return - V_62 ;
V_43 = F_33 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_43 )
return - V_63 ;
return 0 ;
}
void F_50 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_39 * V_42 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
T_11
F_51 ( void * V_43 , T_6 * V_40 )
{
if ( ! V_40 || ! V_43 )
return V_64 ;
* V_40 = F_52 ( V_43 ) ;
return V_65 ;
}
T_11
F_53 ( const struct V_66 * V_67 ,
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
T_12 T_3 F_54 ( T_12 * V_28 , T_1 V_5 )
{
T_12 V_71 = 0 ;
T_12 * V_72 = V_28 + V_5 ;
while ( V_28 < V_72 )
V_71 = ( T_12 ) ( V_71 + * ( V_28 ++ ) ) ;
return V_71 ;
}
void T_3 F_55 ( void * V_73 , T_13 V_41 )
{
int V_74 , V_75 , V_76 = 0 , V_77 = 0 ;
long V_78 = 0 ;
struct V_79 * V_80 ;
char V_81 [ 32 ] = L_22 ;
struct V_82 V_83 ;
struct V_82 V_84 [ V_85 ] ;
char * V_86 ;
if ( V_73 == NULL || V_41 == 0 )
return;
for ( V_75 = 0 ; V_75 < V_85 ; V_75 ++ ) {
V_83 = F_56 ( V_81 , V_73 , V_41 , & V_78 ) ;
if ( ! V_83 . V_73 )
break;
V_73 += V_78 ;
V_41 -= V_78 ;
if ( V_83 . V_41 < sizeof( struct V_79 ) )
F_57 ( L_23 ,
V_81 , V_83 . V_69 ) ;
V_80 = V_83 . V_73 ;
for ( V_74 = 0 ; V_87 [ V_74 ] ; V_74 ++ )
if ( ! memcmp ( V_80 -> V_88 , V_87 [ V_74 ] , 4 ) )
break;
if ( ! V_87 [ V_74 ] )
F_57 ( L_24 ,
V_81 , V_83 . V_69 ) ;
if ( V_83 . V_41 != V_80 -> V_5 )
F_57 ( L_25 ,
V_81 , V_83 . V_69 ) ;
if ( F_54 ( V_83 . V_73 , V_80 -> V_5 ) )
F_57 ( L_26 ,
V_81 , V_83 . V_69 ) ;
F_58 ( L_27 ,
V_80 -> V_88 , V_81 , V_83 . V_69 , V_80 -> V_5 ) ;
V_89 += V_80 -> V_5 ;
V_84 [ V_76 ] . V_73 = V_83 . V_73 ;
V_84 [ V_76 ] . V_41 = V_83 . V_41 ;
V_76 ++ ;
}
if ( V_76 == 0 )
return;
V_90 =
F_59 ( 0 , V_91 << V_49 ,
V_89 , V_50 ) ;
if ( ! V_90 ) {
F_60 ( 1 ) ;
return;
}
F_61 ( V_90 , V_90 + V_89 ) ;
F_62 ( V_90 , V_89 ) ;
V_86 = F_63 ( V_90 , V_89 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
memcpy ( V_86 + V_77 , V_84 [ V_75 ] . V_73 ,
V_84 [ V_75 ] . V_41 ) ;
V_77 += V_84 [ V_75 ] . V_41 ;
}
F_64 ( V_86 , V_89 ) ;
}
static void F_65 ( struct V_79 * V_80 )
{
F_66 ( V_59
L_28 ,
V_80 -> V_88 , V_80 -> V_92 ) ;
F_67 ( V_93 , V_94 ) ;
}
T_11
F_68 ( struct V_79 * V_95 ,
struct V_79 * * V_96 )
{
if ( ! V_95 || ! V_96 )
return V_64 ;
* V_96 = NULL ;
#ifdef F_69
if ( strncmp ( V_95 -> V_88 , L_29 , 4 ) == 0 )
* V_96 = (struct V_79 * ) V_97 ;
#endif
if ( * V_96 != NULL )
F_65 ( V_95 ) ;
return V_65 ;
}
T_11
F_70 ( struct V_79 * V_95 ,
T_6 * V_8 ,
T_1 * V_98 )
{
#ifndef F_71
* V_98 = 0 ;
* V_8 = 0 ;
return V_65 ;
#else
int V_99 = 0 ;
struct V_79 * V_80 ;
* V_98 = 0 ;
* V_8 = 0 ;
if ( ! V_90 )
return V_65 ;
do {
if ( V_99 + V_100 > V_89 ) {
F_60 ( 1 ) ;
return V_65 ;
}
V_80 = F_33 ( V_90 + V_99 ,
V_100 ) ;
if ( V_99 + V_80 -> V_5 > V_89 ) {
F_45 ( V_80 , V_100 ) ;
F_60 ( 1 ) ;
return V_65 ;
}
V_99 += V_80 -> V_5 ;
if ( memcmp ( V_95 -> V_88 , V_80 -> V_88 , 4 ) ) {
F_45 ( V_80 ,
V_100 ) ;
continue;
}
if ( memcmp ( V_80 -> V_92 , V_95 -> V_92 ,
V_101 ) ) {
F_45 ( V_80 ,
V_100 ) ;
continue;
}
V_99 -= V_80 -> V_5 ;
* V_98 = V_80 -> V_5 ;
F_45 ( V_80 , V_100 ) ;
* V_8 = V_90 + V_99 ;
break;
} while ( V_99 + V_100 < V_89 );
if ( * V_8 != 0 )
F_65 ( V_95 ) ;
return V_65 ;
#endif
}
static T_14 F_72 ( int V_102 , void * V_103 )
{
T_1 V_104 ;
V_104 = (* F_73) ( V_105 ) ;
if ( V_104 ) {
V_106 ++ ;
return V_107 ;
} else {
V_108 ++ ;
return V_109 ;
}
}
T_11
F_74 ( T_1 V_110 , T_15 V_111 ,
void * V_112 )
{
unsigned int V_102 ;
F_75 () ;
if ( V_110 != V_12 . V_113 )
return V_64 ;
if ( F_73 )
return V_114 ;
if ( F_76 ( V_110 , & V_102 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_30 ,
gsi) ;
return V_65 ;
}
F_73 = V_111 ;
V_105 = V_112 ;
if ( F_77 ( V_102 , F_72 , V_115 | V_116 , L_31 , F_72 ) ) {
F_11 (KERN_ERR PREFIX L_32 , irq) ;
F_73 = NULL ;
return V_117 ;
}
return V_65 ;
}
T_11 F_78 ( T_1 V_102 , T_15 V_111 )
{
if ( V_102 != V_12 . V_113 )
return V_64 ;
F_79 ( V_102 , F_72 ) ;
F_73 = NULL ;
return V_65 ;
}
void F_80 ( T_4 V_118 )
{
F_81 ( F_82 ( V_118 ) ) ;
}
void F_83 ( T_1 V_119 )
{
while ( V_119 ) {
T_1 V_120 = 1000 ;
if ( V_120 > V_119 )
V_120 = V_119 ;
F_84 ( V_120 ) ;
F_85 () ;
V_119 -= V_120 ;
}
}
T_4 F_86 ( void )
{
static T_4 V_121 ;
#ifdef F_87
#endif
#ifdef F_88
#endif
if ( ! V_121 )
F_11 (KERN_ERR PREFIX L_33 ) ;
return ++ V_121 ;
}
T_11 F_89 ( T_16 V_122 , T_1 * V_123 , T_1 V_124 )
{
T_1 V_125 ;
if ( ! V_123 )
V_123 = & V_125 ;
* V_123 = 0 ;
if ( V_124 <= 8 ) {
* ( T_12 * ) V_123 = F_90 ( V_122 ) ;
} else if ( V_124 <= 16 ) {
* ( V_126 * ) V_123 = F_91 ( V_122 ) ;
} else if ( V_124 <= 32 ) {
* ( T_1 * ) V_123 = F_92 ( V_122 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
T_11 F_94 ( T_16 V_122 , T_1 V_123 , T_1 V_124 )
{
if ( V_124 <= 8 ) {
F_95 ( V_123 , V_122 ) ;
} else if ( V_124 <= 16 ) {
F_96 ( V_123 , V_122 ) ;
} else if ( V_124 <= 32 ) {
F_97 ( V_123 , V_122 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
return F_99 ( V_7 ) ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
T_4 V_127 , V_128 ;
V_127 = F_100 ( V_7 ) ;
V_128 = F_100 ( V_7 + 4 ) ;
return V_127 | ( V_128 << 32 ) ;
}
T_11
F_101 ( T_6 V_129 , T_4 * V_123 , T_1 V_124 )
{
void T_8 * V_130 ;
unsigned int V_41 = V_124 / 8 ;
bool V_131 = false ;
T_4 V_125 ;
F_102 () ;
V_130 = F_20 ( V_129 , V_41 ) ;
if ( ! V_130 ) {
F_103 () ;
V_130 = F_29 ( V_129 , V_41 ) ;
if ( ! V_130 )
return V_132 ;
V_131 = true ;
}
if ( ! V_123 )
V_123 = & V_125 ;
switch ( V_124 ) {
case 8 :
* ( T_12 * ) V_123 = F_104 ( V_130 ) ;
break;
case 16 :
* ( V_126 * ) V_123 = F_105 ( V_130 ) ;
break;
case 32 :
* ( T_1 * ) V_123 = F_100 ( V_130 ) ;
break;
case 64 :
* ( T_4 * ) V_123 = F_98 ( V_130 ) ;
break;
default:
F_93 () ;
}
if ( V_131 )
F_32 ( V_130 ) ;
else
F_103 () ;
return V_65 ;
}
static inline void F_106 ( T_4 V_133 , volatile void T_8 * V_7 )
{
F_107 ( V_133 , V_7 ) ;
}
static inline void F_106 ( T_4 V_133 , volatile void T_8 * V_7 )
{
F_108 ( V_133 , V_7 ) ;
F_108 ( V_133 >> 32 , V_7 + 4 ) ;
}
T_11
F_109 ( T_6 V_129 , T_4 V_123 , T_1 V_124 )
{
void T_8 * V_130 ;
unsigned int V_41 = V_124 / 8 ;
bool V_131 = false ;
F_102 () ;
V_130 = F_20 ( V_129 , V_41 ) ;
if ( ! V_130 ) {
F_103 () ;
V_130 = F_29 ( V_129 , V_41 ) ;
if ( ! V_130 )
return V_132 ;
V_131 = true ;
}
switch ( V_124 ) {
case 8 :
F_110 ( V_123 , V_130 ) ;
break;
case 16 :
F_111 ( V_123 , V_130 ) ;
break;
case 32 :
F_108 ( V_123 , V_130 ) ;
break;
case 64 :
F_106 ( V_123 , V_130 ) ;
break;
default:
F_93 () ;
}
if ( V_131 )
F_32 ( V_130 ) ;
else
F_103 () ;
return V_65 ;
}
T_11
F_112 ( struct V_134 * V_135 , T_1 V_136 ,
T_4 * V_123 , T_1 V_124 )
{
int V_137 , V_41 ;
T_1 V_138 ;
if ( ! V_123 )
return V_64 ;
switch ( V_124 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_139 ;
}
V_137 = F_113 ( V_135 -> V_140 , V_135 -> V_141 ,
F_114 ( V_135 -> V_142 , V_135 -> V_143 ) ,
V_136 , V_41 , & V_138 ) ;
* V_123 = V_138 ;
return ( V_137 ? V_139 : V_65 ) ;
}
T_11
F_115 ( struct V_134 * V_135 , T_1 V_136 ,
T_4 V_123 , T_1 V_124 )
{
int V_137 , V_41 ;
switch ( V_124 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_139 ;
}
V_137 = F_116 ( V_135 -> V_140 , V_135 -> V_141 ,
F_114 ( V_135 -> V_142 , V_135 -> V_143 ) ,
V_136 , V_41 , V_123 ) ;
return ( V_137 ? V_139 : V_65 ) ;
}
static void F_117 ( struct V_144 * V_145 )
{
struct V_146 * V_147 = F_118 ( V_145 , struct V_146 , V_145 ) ;
if ( V_147 -> V_148 )
F_119 () ;
V_147 -> V_143 ( V_147 -> V_112 ) ;
F_38 ( V_147 ) ;
}
static T_11 F_120 ( T_17 type ,
T_18 V_143 , void * V_112 , int V_149 )
{
T_11 V_150 = V_65 ;
struct V_146 * V_147 ;
struct V_151 * V_152 ;
int V_153 ;
F_121 ( ( V_154 ,
L_34 ,
V_143 , V_112 ) ) ;
V_147 = F_35 ( sizeof( struct V_146 ) , V_155 ) ;
if ( ! V_147 )
return V_156 ;
V_147 -> V_143 = V_143 ;
V_147 -> V_112 = V_112 ;
if ( V_149 ) {
V_152 = V_157 ;
V_147 -> V_148 = 1 ;
F_122 ( & V_147 -> V_145 , F_117 ) ;
} else if ( type == V_158 ) {
V_152 = V_159 ;
F_122 ( & V_147 -> V_145 , F_117 ) ;
} else {
V_152 = V_160 ;
F_122 ( & V_147 -> V_145 , F_117 ) ;
}
V_153 = F_123 ( 0 , V_152 , & V_147 -> V_145 ) ;
if ( ! V_153 ) {
F_11 (KERN_ERR PREFIX
L_35 ) ;
V_150 = V_139 ;
F_38 ( V_147 ) ;
}
return V_150 ;
}
T_11 F_124 ( T_17 type ,
T_18 V_143 , void * V_112 )
{
return F_120 ( type , V_143 , V_112 , 0 ) ;
}
T_11 F_125 ( T_18 V_143 ,
void * V_112 )
{
return F_120 ( 0 , V_143 , V_112 , 1 ) ;
}
void F_119 ( void )
{
F_126 ( V_160 ) ;
F_126 ( V_159 ) ;
}
T_11
F_127 ( T_1 V_161 , T_1 V_162 , T_19 * V_163 )
{
struct V_164 * V_165 = NULL ;
V_165 = F_128 ( sizeof( struct V_164 ) ) ;
if ( ! V_165 )
return V_156 ;
memset ( V_165 , 0 , sizeof( struct V_164 ) ) ;
F_129 ( V_165 , V_162 ) ;
* V_163 = ( T_19 * ) V_165 ;
F_121 ( ( V_166 , L_36 ,
* V_163 , V_162 ) ) ;
return V_65 ;
}
T_11 F_130 ( T_19 V_163 )
{
struct V_164 * V_165 = (struct V_164 * ) V_163 ;
if ( ! V_165 )
return V_64 ;
F_121 ( ( V_166 , L_37 , V_163 ) ) ;
F_131 ( ! F_132 ( & V_165 -> V_167 ) ) ;
F_38 ( V_165 ) ;
V_165 = NULL ;
return V_65 ;
}
T_11 F_133 ( T_19 V_163 , T_1 V_168 , V_126 V_169 )
{
T_11 V_150 = V_65 ;
struct V_164 * V_165 = (struct V_164 * ) V_163 ;
long V_170 ;
int V_153 = 0 ;
if ( ! V_165 || ( V_168 < 1 ) )
return V_64 ;
if ( V_168 > 1 )
return V_171 ;
F_121 ( ( V_166 , L_38 ,
V_163 , V_168 , V_169 ) ) ;
if ( V_169 == V_172 )
V_170 = V_173 ;
else
V_170 = F_82 ( V_169 ) ;
V_153 = F_134 ( V_165 , V_170 ) ;
if ( V_153 )
V_150 = V_174 ;
if ( F_135 ( V_150 ) ) {
F_121 ( ( V_166 ,
L_39 ,
V_163 , V_168 , V_169 ,
F_136 ( V_150 ) ) ) ;
} else {
F_121 ( ( V_166 ,
L_40 , V_163 ,
V_168 , V_169 ) ) ;
}
return V_150 ;
}
T_11 F_137 ( T_19 V_163 , T_1 V_168 )
{
struct V_164 * V_165 = (struct V_164 * ) V_163 ;
if ( ! V_165 || ( V_168 < 1 ) )
return V_64 ;
if ( V_168 > 1 )
return V_171 ;
F_121 ( ( V_166 , L_41 , V_163 ,
V_168 ) ) ;
F_138 ( V_165 ) ;
return V_65 ;
}
T_1 F_139 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_175 ;
F_140 ( V_28 , sizeof( V_176 ) ) ;
V_175 = strlen ( V_28 ) - 1 ;
V_28 [ V_175 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_141 ( T_1 V_143 , void * V_177 )
{
switch ( V_143 ) {
case V_178 :
F_11 (KERN_ERR PREFIX L_42 ) ;
break;
case V_179 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_142 ( char * V_180 )
{
char * V_86 = V_70 ;
int V_181 = V_182 - 1 ;
if ( ! V_180 || ! * V_180 )
return 0 ;
for (; V_181 -- && V_180 && * V_180 ; V_180 ++ ) {
if ( isalnum ( * V_180 ) || * V_180 == ' ' || * V_180 == ':' )
* V_86 ++ = * V_180 ;
else if ( * V_180 == '\'' || * V_180 == '"' )
continue;
else
break;
}
* V_86 = 0 ;
return 1 ;
}
void T_3 F_143 ( char * V_180 )
{
struct V_183 * V_184 ;
bool V_185 = true ;
int V_186 ;
if ( ! V_187 )
return;
if ( V_180 == NULL || * V_180 == '\0' ) {
F_11 (KERN_INFO PREFIX L_43 ) ;
V_187 = FALSE ;
return;
}
if ( * V_180 == '!' ) {
V_180 ++ ;
V_185 = false ;
}
for ( V_186 = 0 ; V_186 < V_188 ; V_186 ++ ) {
V_184 = & V_189 [ V_186 ] ;
if ( ! strcmp ( V_184 -> string , V_180 ) ) {
V_184 -> V_185 = V_185 ;
break;
} else if ( V_184 -> string [ 0 ] == '\0' ) {
V_184 -> V_185 = V_185 ;
strncpy ( V_184 -> string , V_180 , V_190 ) ;
break;
}
}
}
static void T_3 F_144 ( unsigned int V_185 )
{
if ( V_191 . V_185 != V_185 )
V_191 . V_185 = V_185 ;
if ( V_191 . V_185 )
F_143 ( L_1 ) ;
else
F_143 ( L_44 ) ;
return;
}
static void T_3 F_145 ( unsigned int V_185 )
{
V_191 . V_192 = 1 ;
V_191 . V_193 = 0 ;
F_144 ( V_185 ) ;
return;
}
void T_3 F_146 ( int V_185 , const struct V_194 * V_195 )
{
F_11 (KERN_NOTICE PREFIX L_45 , d->ident) ;
if ( V_185 == - 1 )
return;
V_191 . V_193 = 1 ;
F_144 ( V_185 ) ;
return;
}
static void T_3 F_147 ( void )
{
struct V_183 * V_184 ;
char * V_180 ;
int V_186 ;
T_11 V_150 ;
for ( V_186 = 0 ; V_186 < V_188 ; V_186 ++ ) {
V_184 = & V_189 [ V_186 ] ;
V_180 = V_184 -> string ;
if ( * V_180 == '\0' )
break;
if ( V_184 -> V_185 ) {
V_150 = F_148 ( V_180 ) ;
if ( F_149 ( V_150 ) )
F_11 (KERN_INFO PREFIX L_46 , str) ;
} else {
V_150 = F_150 ( V_180 ) ;
if ( F_149 ( V_150 ) )
F_11 (KERN_INFO PREFIX L_47 , str) ;
}
}
}
static int T_3 F_151 ( char * V_180 )
{
if ( V_180 && ! strcmp ( L_1 , V_180 ) )
F_145 ( 1 ) ;
else if ( V_180 && ! strcmp ( L_44 , V_180 ) )
F_145 ( 0 ) ;
else
F_143 ( V_180 ) ;
return 1 ;
}
static int T_3 F_152 ( char * V_180 )
{
F_11 (KERN_INFO PREFIX L_48 ) ;
V_196 = TRUE ;
return 1 ;
}
static int T_3 F_153 ( char * V_180 )
{
if ( V_180 == NULL || * V_180 == '\0' )
return 0 ;
if ( ! strcmp ( L_49 , V_180 ) )
V_197 = V_198 ;
else if ( ! strcmp ( L_50 , V_180 ) )
V_197 = V_199 ;
else if ( ! strcmp ( L_51 , V_180 ) )
V_197 = V_200 ;
return 1 ;
}
int F_154 ( const struct V_201 * V_202 )
{
T_20 V_9 ;
T_7 V_5 ;
T_12 V_203 = 0 ;
int V_204 = 0 ;
if ( V_197 == V_200 )
return 0 ;
if ( ! ( V_202 -> V_205 & V_206 ) && ! ( V_202 -> V_205 & V_207 ) )
return 0 ;
if ( V_202 -> V_205 & V_206 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = V_202 -> V_72 - V_202 -> V_208 + 1 ;
if ( V_197 != V_200 )
V_203 = 1 ;
V_204 = F_155 ( V_9 , V_202 -> V_208 , V_5 , V_203 ) ;
if ( V_204 ) {
if ( V_197 != V_200 ) {
if ( V_197 == V_199 )
F_11 ( V_209 L_52
L_53
L_54 ) ;
F_11 ( V_210 L_55
L_56
L_57 ) ;
}
if ( V_197 == V_198 )
return - V_211 ;
}
return 0 ;
}
int F_156 ( T_21 V_208 , T_21 V_212 ,
const char * V_69 )
{
struct V_201 V_202 = {
. V_208 = V_208 ,
. V_72 = V_208 + V_212 - 1 ,
. V_69 = V_69 ,
. V_205 = V_206 ,
} ;
return F_154 ( & V_202 ) ;
}
int F_157 ( void )
{
return V_197 == V_198 ;
}
void F_158 ( T_22 V_163 )
{
F_159 ( V_163 ) ;
}
T_23 F_160 ( T_22 V_213 )
{
T_23 V_205 ;
F_161 ( V_213 , V_205 ) ;
return V_205 ;
}
void F_162 ( T_22 V_213 , T_23 V_205 )
{
F_163 ( V_213 , V_205 ) ;
}
T_11
F_164 ( char * V_69 , V_126 V_41 , V_126 V_214 , T_24 * * V_215 )
{
* V_215 = F_165 ( V_69 , V_41 , 0 , 0 , NULL ) ;
if ( * V_215 == NULL )
return V_139 ;
else
return V_65 ;
}
T_11 F_166 ( T_24 * V_215 )
{
F_167 ( V_215 ) ;
return ( V_65 ) ;
}
T_11 F_168 ( T_24 * V_215 )
{
F_169 ( V_215 ) ;
return ( V_65 ) ;
}
T_11 F_170 ( T_24 * V_215 , void * V_216 )
{
F_171 ( V_215 , V_216 ) ;
return ( V_65 ) ;
}
T_11 T_3 F_172 ( void )
{
F_49 ( & V_12 . V_13 ) ;
F_49 ( & V_12 . V_15 ) ;
F_49 ( & V_12 . V_24 ) ;
F_49 ( & V_12 . V_26 ) ;
return V_65 ;
}
T_11 T_3 F_173 ( void )
{
V_160 = F_174 ( L_58 , 0 , 1 ) ;
V_159 = F_174 ( L_59 , 0 , 1 ) ;
V_157 = F_174 ( L_60 , 0 , 1 ) ;
F_131 ( ! V_160 ) ;
F_131 ( ! V_159 ) ;
F_131 ( ! V_157 ) ;
F_175 ( F_1 ) ;
F_147 () ;
return V_65 ;
}
T_11 F_176 ( void )
{
if ( F_73 ) {
F_78 ( V_12 . V_113 ,
F_73 ) ;
}
F_50 ( & V_12 . V_26 ) ;
F_50 ( & V_12 . V_24 ) ;
F_50 ( & V_12 . V_15 ) ;
F_50 ( & V_12 . V_13 ) ;
F_177 ( V_160 ) ;
F_177 ( V_159 ) ;
F_177 ( V_157 ) ;
return V_65 ;
}
T_11 F_178 ( T_12 V_217 , T_1 V_218 ,
T_1 V_219 )
{
int V_220 = 0 ;
if ( V_221 )
V_220 = V_221 ( V_217 ,
V_218 , V_219 ) ;
if ( V_220 < 0 )
return V_139 ;
else if ( V_220 > 0 )
return V_222 ;
return V_65 ;
}
void F_179 ( int (* F_180)( T_12 V_217 ,
T_1 V_223 , T_1 V_224 ) )
{
V_221 = F_180 ;
}
void F_181 ( T_19 V_163 , T_1 type , void * V_112 ,
void (* F_180)( struct V_144 * V_145 ) )
{
struct V_225 * V_226 ;
int V_153 ;
V_226 = F_182 ( sizeof( * V_226 ) , V_56 ) ;
if ( ! V_226 )
return;
V_226 -> V_163 = V_163 ;
V_226 -> type = type ;
V_226 -> V_112 = V_112 ;
F_122 ( & V_226 -> V_145 , F_180 ) ;
V_153 = F_183 ( V_157 , & V_226 -> V_145 ) ;
if ( ! V_153 )
F_38 ( V_226 ) ;
}
