static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
if ( ! strcmp ( L_8 , V_1 ) ) {
F_3 ( V_3 ) ;
V_2 = V_4 ;
}
return V_2 ;
}
static void T_3 F_4 ( struct V_5 * V_6 ,
unsigned int V_7 , char * V_8 )
{
T_4 V_9 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_7 )
return;
if ( V_6 -> V_11 == V_12 )
F_5 ( V_9 , V_7 , V_8 ) ;
else if ( V_6 -> V_11 == V_13 )
F_6 ( V_9 , V_7 , V_8 ) ;
}
static int T_3 F_7 ( void )
{
F_4 ( & V_14 . V_15 , V_14 . V_16 ,
L_9 ) ;
F_4 ( & V_14 . V_17 , V_14 . V_16 ,
L_10 ) ;
F_4 ( & V_14 . V_18 , V_14 . V_19 ,
L_11 ) ;
F_4 ( & V_14 . V_20 , V_14 . V_19 ,
L_12 ) ;
if ( V_14 . V_21 == 4 )
F_4 ( & V_14 . V_22 , 4 , L_13 ) ;
F_4 ( & V_14 . V_23 , V_14 . V_24 ,
L_14 ) ;
if ( ! ( V_14 . V_25 & 0x1 ) )
F_4 ( & V_14 . V_26 ,
V_14 . V_25 , L_15 ) ;
if ( ! ( V_14 . V_27 & 0x1 ) )
F_4 ( & V_14 . V_28 ,
V_14 . V_27 , L_16 ) ;
return 0 ;
}
void F_8 ( const char * V_29 , ... )
{
T_5 args ;
va_start ( args , V_29 ) ;
F_9 ( V_29 , args ) ;
va_end ( args ) ;
}
void F_9 ( const char * V_29 , T_5 args )
{
static char V_30 [ 512 ] ;
vsprintf ( V_30 , V_29 , args ) ;
#ifdef F_10
if ( V_31 ) {
F_11 ( L_17 , V_30 ) ;
} else {
F_12 ( V_32 L_17 , V_30 ) ;
}
#else
if ( F_13 ( V_30 ) < 0 )
F_12 ( V_32 L_17 , V_30 ) ;
#endif
}
static int T_3 F_14 ( char * V_33 )
{
if ( F_15 ( V_33 , 16 , & V_34 ) )
return - V_35 ;
return 0 ;
}
T_6 T_3 F_16 ( void )
{
#ifdef F_17
if ( V_34 )
return V_34 ;
#endif
if ( F_18 ( V_36 ) ) {
if ( V_37 . V_38 != V_39 )
return V_37 . V_38 ;
else if ( V_37 . V_40 != V_39 )
return V_37 . V_40 ;
else {
F_12 (KERN_ERR PREFIX
L_18 ) ;
return 0 ;
}
} else if ( F_19 ( V_41 ) ) {
T_6 V_42 = 0 ;
F_20 ( & V_42 ) ;
return V_42 ;
}
return 0 ;
}
static struct V_43 *
F_21 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_22 (map, &acpi_ioremaps, list)
if ( V_46 -> V_44 <= V_44 &&
V_44 + V_45 <= V_46 -> V_44 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 *
F_23 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 )
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
return NULL ;
}
void T_8 * F_24 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 = NULL ;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_47 = V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
V_46 -> V_49 ++ ;
}
F_26 ( & V_48 ) ;
return V_47 ;
}
static struct V_43 *
F_27 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_22 (map, &acpi_ioremaps, list)
if ( V_46 -> V_47 <= V_47 &&
V_47 + V_45 <= V_46 -> V_47 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 * F_28 ( T_6 V_50 , unsigned long V_51 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_29 ( V_52 ) ) {
if ( V_51 > V_54 )
return NULL ;
return ( void T_8 V_55 * ) F_30 ( F_31 ( V_52 ) ) ;
} else
return F_32 ( V_50 , V_51 ) ;
}
static void F_33 ( T_6 V_50 , void T_8 * V_56 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_29 ( V_52 ) )
F_34 ( F_31 ( V_52 ) ) ;
else
F_35 ( V_56 ) ;
}
void T_8 * T_9
F_36 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 ;
T_6 V_50 ;
T_7 V_51 ;
if ( V_44 > V_57 ) {
F_12 (KERN_ERR PREFIX L_19 ) ;
return NULL ;
}
if ( ! V_58 )
return F_37 ( ( unsigned long ) V_44 , V_45 ) ;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_46 -> V_49 ++ ;
goto V_59;
}
V_46 = F_38 ( sizeof( * V_46 ) , V_60 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
return NULL ;
}
V_50 = F_39 ( V_44 , V_54 ) ;
V_51 = F_40 ( V_44 + V_45 , V_54 ) - V_50 ;
V_47 = F_28 ( V_50 , V_51 ) ;
if ( ! V_47 ) {
F_26 ( & V_48 ) ;
F_41 ( V_46 ) ;
return NULL ;
}
F_42 ( & V_46 -> V_61 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_44 = V_50 ;
V_46 -> V_45 = V_51 ;
V_46 -> V_49 = 1 ;
F_43 ( & V_46 -> V_61 , & V_62 ) ;
V_59:
F_26 ( & V_48 ) ;
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
}
void * T_9
F_44 ( T_6 V_44 , T_7 V_45 )
{
return ( void * ) F_36 ( V_44 , V_45 ) ;
}
static void F_45 ( struct V_43 * V_46 )
{
if ( ! -- V_46 -> V_49 )
F_46 ( & V_46 -> V_61 ) ;
}
static void F_47 ( struct V_43 * V_46 )
{
if ( ! V_46 -> V_49 ) {
F_48 () ;
F_33 ( V_46 -> V_44 , V_46 -> V_47 ) ;
F_41 ( V_46 ) ;
}
}
void T_10 F_49 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
if ( ! V_58 ) {
F_50 ( V_47 , V_45 ) ;
return;
}
F_25 ( & V_48 ) ;
V_46 = F_27 ( V_47 , V_45 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
F_51 ( true , V_63 L_20 , V_64 , V_47 ) ;
return;
}
F_45 ( V_46 ) ;
F_26 ( & V_48 ) ;
F_47 ( V_46 ) ;
}
void T_10 F_52 ( void * V_47 , T_7 V_45 )
{
return F_49 ( ( void T_8 * ) V_47 , V_45 ) ;
}
void T_3 F_53 ( void T_8 * V_47 , T_7 V_45 )
{
if ( ! V_58 )
F_50 ( V_47 , V_45 ) ;
}
int F_54 ( struct V_5 * V_6 )
{
T_4 V_9 ;
void T_8 * V_47 ;
if ( V_6 -> V_11 != V_13 )
return 0 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return - V_35 ;
V_47 = F_36 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_47 )
return - V_66 ;
return 0 ;
}
void F_55 ( struct V_5 * V_6 )
{
T_4 V_9 ;
struct V_43 * V_46 ;
if ( V_6 -> V_11 != V_13 )
return;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return;
F_25 ( & V_48 ) ;
V_46 = F_21 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_46 ) {
F_26 ( & V_48 ) ;
return;
}
F_45 ( V_46 ) ;
F_26 ( & V_48 ) ;
F_47 ( V_46 ) ;
}
T_11
F_56 ( void * V_47 , T_6 * V_44 )
{
if ( ! V_44 || ! V_47 )
return V_67 ;
* V_44 = F_57 ( V_47 ) ;
return V_68 ;
}
int T_3 F_58 ( char * V_69 )
{
V_70 = true ;
return 1 ;
}
T_11
F_59 ( const struct V_71 * V_72 ,
char * * V_73 )
{
if ( ! V_72 || ! V_73 )
return V_67 ;
* V_73 = NULL ;
if ( ! memcmp ( V_72 -> V_74 , L_21 , 4 ) && strlen ( V_75 ) ) {
F_12 (KERN_INFO PREFIX L_22 ,
acpi_os_name) ;
* V_73 = V_75 ;
}
if ( ! memcmp ( V_72 -> V_74 , L_23 , 4 ) && V_70 ) {
F_12 (KERN_INFO PREFIX L_24 ) ;
* V_73 = ( char * ) 5 ;
}
return V_68 ;
}
static void F_60 ( struct V_76 * V_77 )
{
F_61 ( V_63
L_25 ,
V_77 -> V_78 , V_77 -> V_79 ) ;
F_62 ( V_80 , V_81 ) ;
}
static T_12 T_3 F_63 ( T_12 * V_30 , T_1 V_7 )
{
T_12 V_82 = 0 ;
T_12 * V_83 = V_30 + V_7 ;
while ( V_30 < V_83 )
V_82 = ( T_12 ) ( V_82 + * ( V_30 ++ ) ) ;
return V_82 ;
}
void T_3 F_64 ( void * V_84 , T_13 V_45 )
{
int V_85 , V_86 , V_87 = 0 , V_88 = 0 ;
long V_89 = 0 ;
struct V_76 * V_77 ;
char V_90 [ 32 ] = L_26 ;
struct V_91 V_92 ;
if ( V_84 == NULL || V_45 == 0 )
return;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
V_92 = F_65 ( V_90 , V_84 , V_45 , & V_89 ) ;
if ( ! V_92 . V_84 )
break;
V_84 += V_89 ;
V_45 -= V_89 ;
if ( V_92 . V_45 < sizeof( struct V_76 ) ) {
F_66 ( L_27 ,
V_90 , V_92 . V_74 ) ;
continue;
}
V_77 = V_92 . V_84 ;
for ( V_85 = 0 ; V_94 [ V_85 ] ; V_85 ++ )
if ( ! memcmp ( V_77 -> V_78 , V_94 [ V_85 ] , 4 ) )
break;
if ( ! V_94 [ V_85 ] ) {
F_66 ( L_28 ,
V_90 , V_92 . V_74 ) ;
continue;
}
if ( V_92 . V_45 != V_77 -> V_7 ) {
F_66 ( L_29 ,
V_90 , V_92 . V_74 ) ;
continue;
}
if ( F_63 ( V_92 . V_84 , V_77 -> V_7 ) ) {
F_66 ( L_30 ,
V_90 , V_92 . V_74 ) ;
continue;
}
F_67 ( L_31 ,
V_77 -> V_78 , V_90 , V_92 . V_74 , V_77 -> V_7 ) ;
V_95 += V_77 -> V_7 ;
V_96 [ V_87 ] . V_84 = V_92 . V_84 ;
V_96 [ V_87 ] . V_45 = V_92 . V_45 ;
V_87 ++ ;
}
if ( V_87 == 0 )
return;
V_97 =
F_68 ( 0 , V_98 << V_53 ,
V_95 , V_54 ) ;
if ( ! V_97 ) {
F_69 ( 1 ) ;
return;
}
F_70 ( V_97 , V_95 ) ;
F_71 ( V_97 , V_95 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
unsigned char * V_99 = V_96 [ V_86 ] . V_84 ;
T_14 V_45 = V_96 [ V_86 ] . V_45 ;
T_14 V_100 = V_97 + V_88 ;
T_14 V_101 , V_102 ;
char * V_103 ;
V_88 += V_45 ;
while ( V_45 ) {
V_101 = V_100 & ~ V_104 ;
V_102 = V_45 ;
if ( V_102 > V_105 - V_101 )
V_102 = V_105 - V_101 ;
V_103 = F_72 ( V_100 & V_104 ,
V_102 + V_101 ) ;
memcpy ( V_103 + V_101 , V_99 , V_102 ) ;
F_73 ( V_103 , V_102 + V_101 ) ;
V_99 += V_102 ;
V_100 += V_102 ;
V_45 -= V_102 ;
}
}
}
T_11
F_74 ( struct V_76 * V_106 ,
T_6 * V_10 , T_1 * V_7 )
{
int V_107 = 0 ;
int V_108 = 0 ;
struct V_76 * V_77 ;
T_1 V_109 ;
* V_7 = 0 ;
* V_10 = 0 ;
if ( ! V_97 )
return V_68 ;
while ( V_107 + V_110 <= V_95 ) {
V_77 = F_44 ( V_97 + V_107 ,
V_110 ) ;
if ( V_107 + V_77 -> V_7 > V_95 ) {
F_52 ( V_77 , V_110 ) ;
F_69 ( 1 ) ;
return V_68 ;
}
V_109 = V_77 -> V_7 ;
if ( F_75 ( V_108 , V_111 ) ||
memcmp ( V_106 -> V_78 , V_77 -> V_78 , 4 ) ||
memcmp ( V_77 -> V_79 , V_106 -> V_79 ,
V_112 ) ) {
F_52 ( V_77 , V_110 ) ;
goto V_113;
}
* V_7 = V_109 ;
* V_10 = V_97 + V_107 ;
F_60 ( V_106 ) ;
F_52 ( V_77 , V_110 ) ;
F_76 ( V_108 , V_111 ) ;
break;
V_113:
V_107 += V_109 ;
V_108 ++ ;
}
return V_68 ;
}
void T_3 F_77 ( void )
{
int V_107 = 0 ;
int V_108 = 0 ;
T_1 V_109 ;
struct V_76 * V_77 ;
if ( ! V_97 )
return;
while ( V_107 + V_110 <= V_95 ) {
V_77 = F_44 ( V_97 + V_107 ,
V_110 ) ;
if ( V_107 + V_77 -> V_7 > V_95 ) {
F_52 ( V_77 , V_110 ) ;
F_69 ( 1 ) ;
return;
}
V_109 = V_77 -> V_7 ;
if ( F_75 ( V_108 , V_111 ) ||
F_78 ( V_77 -> V_78 , V_114 ) ||
F_78 ( V_77 -> V_78 , V_115 ) ) {
F_52 ( V_77 , V_110 ) ;
goto V_113;
}
F_60 ( V_77 ) ;
F_52 ( V_77 , V_110 ) ;
F_79 ( V_97 + V_107 , TRUE ) ;
F_76 ( V_108 , V_111 ) ;
V_113:
V_107 += V_109 ;
V_108 ++ ;
}
}
T_11
F_74 ( struct V_76 * V_106 ,
T_6 * V_10 ,
T_1 * V_109 )
{
* V_109 = 0 ;
* V_10 = 0 ;
return V_68 ;
}
void T_3 F_77 ( void )
{
}
T_11
F_80 ( struct V_76 * V_106 ,
struct V_76 * * V_116 )
{
if ( ! V_106 || ! V_116 )
return V_67 ;
* V_116 = NULL ;
#ifdef F_81
if ( strncmp ( V_106 -> V_78 , L_32 , 4 ) == 0 )
* V_116 = (struct V_76 * ) V_117 ;
#endif
if ( * V_116 != NULL )
F_60 ( V_106 ) ;
return V_68 ;
}
static T_15 F_82 ( int V_118 , void * V_119 )
{
T_1 V_120 ;
V_120 = (* F_83) ( V_121 ) ;
if ( V_120 ) {
V_122 ++ ;
return V_123 ;
} else {
V_124 ++ ;
return V_125 ;
}
}
T_11
F_84 ( T_1 V_126 , T_16 V_127 ,
void * V_128 )
{
unsigned int V_118 ;
F_85 () ;
if ( V_126 != V_14 . V_129 )
return V_67 ;
if ( F_83 )
return V_130 ;
if ( F_86 ( V_126 , & V_118 ) < 0 ) {
F_12 (KERN_ERR PREFIX L_33 ,
gsi) ;
return V_68 ;
}
F_83 = V_127 ;
V_121 = V_128 ;
if ( F_87 ( V_118 , F_82 , V_131 , L_34 , F_82 ) ) {
F_12 (KERN_ERR PREFIX L_35 , irq) ;
F_83 = NULL ;
return V_132 ;
}
V_133 = V_118 ;
return V_68 ;
}
T_11 F_88 ( T_1 V_126 , T_16 V_127 )
{
if ( V_126 != V_14 . V_129 || ! F_89 () )
return V_67 ;
F_90 ( V_133 , F_82 ) ;
F_83 = NULL ;
V_133 = V_134 ;
return V_68 ;
}
void F_91 ( T_4 V_135 )
{
F_92 ( V_135 ) ;
}
void F_93 ( T_1 V_136 )
{
while ( V_136 ) {
T_1 V_137 = 1000 ;
if ( V_137 > V_136 )
V_137 = V_136 ;
F_94 ( V_137 ) ;
F_95 () ;
V_136 -= V_137 ;
}
}
T_4 F_96 ( void )
{
T_4 V_138 = F_97 ( F_98 () ) ;
F_99 ( V_138 , 100 ) ;
return V_138 ;
}
T_11 F_100 ( T_17 V_139 , T_1 * V_140 , T_1 V_141 )
{
T_1 V_142 ;
if ( ! V_140 )
V_140 = & V_142 ;
* V_140 = 0 ;
if ( V_141 <= 8 ) {
* ( T_12 * ) V_140 = F_101 ( V_139 ) ;
} else if ( V_141 <= 16 ) {
* ( V_143 * ) V_140 = F_102 ( V_139 ) ;
} else if ( V_141 <= 32 ) {
* ( T_1 * ) V_140 = F_103 ( V_139 ) ;
} else {
F_104 () ;
}
return V_68 ;
}
T_11 F_105 ( T_17 V_139 , T_1 V_140 , T_1 V_141 )
{
if ( V_141 <= 8 ) {
F_106 ( V_140 , V_139 ) ;
} else if ( V_141 <= 16 ) {
F_107 ( V_140 , V_139 ) ;
} else if ( V_141 <= 32 ) {
F_108 ( V_140 , V_139 ) ;
} else {
F_104 () ;
}
return V_68 ;
}
T_11
F_109 ( T_6 V_144 , T_4 * V_140 , T_1 V_141 )
{
void T_8 * V_145 ;
unsigned int V_45 = V_141 / 8 ;
bool V_146 = false ;
T_4 V_142 ;
F_110 () ;
V_145 = F_23 ( V_144 , V_45 ) ;
if ( ! V_145 ) {
F_111 () ;
V_145 = F_32 ( V_144 , V_45 ) ;
if ( ! V_145 )
return V_147 ;
V_146 = true ;
}
if ( ! V_140 )
V_140 = & V_142 ;
switch ( V_141 ) {
case 8 :
* ( T_12 * ) V_140 = F_112 ( V_145 ) ;
break;
case 16 :
* ( V_143 * ) V_140 = F_113 ( V_145 ) ;
break;
case 32 :
* ( T_1 * ) V_140 = F_114 ( V_145 ) ;
break;
case 64 :
* ( T_4 * ) V_140 = F_115 ( V_145 ) ;
break;
default:
F_104 () ;
}
if ( V_146 )
F_35 ( V_145 ) ;
else
F_111 () ;
return V_68 ;
}
T_11
F_116 ( T_6 V_144 , T_4 V_140 , T_1 V_141 )
{
void T_8 * V_145 ;
unsigned int V_45 = V_141 / 8 ;
bool V_146 = false ;
F_110 () ;
V_145 = F_23 ( V_144 , V_45 ) ;
if ( ! V_145 ) {
F_111 () ;
V_145 = F_32 ( V_144 , V_45 ) ;
if ( ! V_145 )
return V_147 ;
V_146 = true ;
}
switch ( V_141 ) {
case 8 :
F_117 ( V_140 , V_145 ) ;
break;
case 16 :
F_118 ( V_140 , V_145 ) ;
break;
case 32 :
F_119 ( V_140 , V_145 ) ;
break;
case 64 :
F_120 ( V_140 , V_145 ) ;
break;
default:
F_104 () ;
}
if ( V_146 )
F_35 ( V_145 ) ;
else
F_111 () ;
return V_68 ;
}
T_11
F_121 ( struct V_148 * V_149 , T_1 V_150 ,
T_4 * V_140 , T_1 V_141 )
{
int V_151 , V_45 ;
T_1 V_152 ;
if ( ! V_140 )
return V_67 ;
switch ( V_141 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_153 ;
}
V_151 = F_122 ( V_149 -> V_154 , V_149 -> V_155 ,
F_123 ( V_149 -> V_156 , V_149 -> V_157 ) ,
V_150 , V_45 , & V_152 ) ;
* V_140 = V_152 ;
return ( V_151 ? V_153 : V_68 ) ;
}
T_11
F_124 ( struct V_148 * V_149 , T_1 V_150 ,
T_4 V_140 , T_1 V_141 )
{
int V_151 , V_45 ;
switch ( V_141 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_153 ;
}
V_151 = F_125 ( V_149 -> V_154 , V_149 -> V_155 ,
F_123 ( V_149 -> V_156 , V_149 -> V_157 ) ,
V_150 , V_45 , V_140 ) ;
return ( V_151 ? V_153 : V_68 ) ;
}
static void F_126 ( struct V_158 * V_159 )
{
struct V_160 * V_161 = F_127 ( V_159 , struct V_160 , V_159 ) ;
V_161 -> V_157 ( V_161 -> V_128 ) ;
F_41 ( V_161 ) ;
}
int F_128 ( struct V_162 * V_163 ,
const struct V_164 * V_165 )
{
int V_166 = 0 ;
F_25 ( & V_167 . V_168 ) ;
if ( V_167 . V_165 ) {
V_166 = - V_169 ;
goto V_170;
}
V_167 . V_163 = V_163 ;
V_167 . V_165 = V_165 ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
void F_129 ( const struct V_164 * V_165 )
{
F_25 ( & V_167 . V_168 ) ;
if ( V_165 == V_167 . V_165 ) {
V_167 . V_165 = NULL ;
V_167 . V_163 = NULL ;
}
F_26 ( & V_167 . V_168 ) ;
}
int F_130 ( T_18 V_157 , void * V_128 )
{
int V_166 ;
int (* F_131)( T_18 , void * );
struct V_162 * V_163 ;
if ( ! V_171 )
return - V_172 ;
F_25 ( & V_167 . V_168 ) ;
if ( ! V_167 . V_165 ) {
V_166 = - V_172 ;
goto V_170;
}
if ( ! F_132 ( V_167 . V_163 ) ) {
V_166 = - V_172 ;
goto V_170;
}
F_131 = V_167 . V_165 -> V_173 ;
V_163 = V_167 . V_163 ;
F_26 ( & V_167 . V_168 ) ;
V_166 = F_131 ( V_157 , V_128 ) ;
F_25 ( & V_167 . V_168 ) ;
F_133 ( V_163 ) ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
T_19 F_13 ( const char * V_174 )
{
T_19 V_166 ;
T_19 (* F_131)( const char * );
struct V_162 * V_163 ;
if ( ! V_171 )
return - V_172 ;
F_25 ( & V_167 . V_168 ) ;
if ( ! V_167 . V_165 ) {
V_166 = - V_172 ;
goto V_170;
}
if ( ! F_132 ( V_167 . V_163 ) ) {
V_166 = - V_172 ;
goto V_170;
}
F_131 = V_167 . V_165 -> V_175 ;
V_163 = V_167 . V_163 ;
F_26 ( & V_167 . V_168 ) ;
V_166 = F_131 ( V_174 ) ;
F_25 ( & V_167 . V_168 ) ;
F_133 ( V_163 ) ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
T_19 F_134 ( char * V_30 , T_13 V_176 )
{
T_19 V_166 ;
T_19 (* F_131)( char * , T_13 );
struct V_162 * V_163 ;
if ( ! V_171 )
return - V_172 ;
F_25 ( & V_167 . V_168 ) ;
if ( ! V_167 . V_165 ) {
V_166 = - V_172 ;
goto V_170;
}
if ( ! F_132 ( V_167 . V_163 ) ) {
V_166 = - V_172 ;
goto V_170;
}
F_131 = V_167 . V_165 -> V_177 ;
V_163 = V_167 . V_163 ;
F_26 ( & V_167 . V_168 ) ;
V_166 = F_131 ( V_30 , V_176 ) ;
F_25 ( & V_167 . V_168 ) ;
F_133 ( V_163 ) ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
int F_135 ( void )
{
int V_166 ;
int (* F_131)( bool , char * , T_13 );
struct V_162 * V_163 ;
if ( ! V_171 )
return - V_172 ;
F_25 ( & V_167 . V_168 ) ;
if ( ! V_167 . V_165 ) {
V_166 = - V_172 ;
goto V_170;
}
if ( ! F_132 ( V_167 . V_163 ) ) {
V_166 = - V_172 ;
goto V_170;
}
F_131 = V_167 . V_165 -> V_178 ;
V_163 = V_167 . V_163 ;
F_26 ( & V_167 . V_168 ) ;
V_166 = F_131 ( V_179 ,
V_180 , V_181 ) ;
F_25 ( & V_167 . V_168 ) ;
F_133 ( V_163 ) ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
int F_136 ( void )
{
int V_166 ;
int (* F_131)( void );
struct V_162 * V_163 ;
if ( ! V_171 )
return - V_172 ;
F_25 ( & V_167 . V_168 ) ;
if ( ! V_167 . V_165 ) {
V_166 = - V_172 ;
goto V_170;
}
if ( ! F_132 ( V_167 . V_163 ) ) {
V_166 = - V_172 ;
goto V_170;
}
F_131 = V_167 . V_165 -> V_182 ;
V_163 = V_167 . V_163 ;
F_26 ( & V_167 . V_168 ) ;
V_166 = F_131 () ;
F_25 ( & V_167 . V_168 ) ;
F_133 ( V_163 ) ;
V_170:
F_26 ( & V_167 . V_168 ) ;
return V_166 ;
}
int T_3 F_137 ( void )
{
F_138 ( & V_167 . V_168 ) ;
V_171 = true ;
return 0 ;
}
T_11 F_139 ( T_20 type ,
T_18 V_157 , void * V_128 )
{
T_11 V_183 = V_68 ;
struct V_160 * V_161 ;
struct V_184 * V_185 ;
int V_166 ;
F_140 ( ( V_186 ,
L_36 ,
V_157 , V_128 ) ) ;
if ( type == V_187 ) {
V_166 = F_130 ( V_157 , V_128 ) ;
if ( V_166 ) {
F_66 ( L_37 ) ;
V_183 = V_153 ;
}
goto V_188;
}
V_161 = F_38 ( sizeof( struct V_160 ) , V_189 ) ;
if ( ! V_161 )
return V_190 ;
V_161 -> V_157 = V_157 ;
V_161 -> V_128 = V_128 ;
if ( type == V_191 ) {
V_185 = V_192 ;
F_141 ( & V_161 -> V_159 , F_126 ) ;
} else if ( type == V_193 ) {
V_185 = V_194 ;
F_141 ( & V_161 -> V_159 , F_126 ) ;
} else {
F_66 ( L_38 , type ) ;
V_183 = V_153 ;
}
if ( F_142 ( V_183 ) )
goto V_195;
V_166 = F_143 ( 0 , V_185 , & V_161 -> V_159 ) ;
if ( ! V_166 ) {
F_12 (KERN_ERR PREFIX
L_39 ) ;
V_183 = V_153 ;
}
V_195:
if ( F_142 ( V_183 ) )
F_41 ( V_161 ) ;
V_188:
return V_183 ;
}
void F_144 ( void )
{
if ( F_89 () )
F_145 ( V_133 ) ;
F_146 ( V_194 ) ;
F_146 ( V_192 ) ;
}
static void F_147 ( struct V_158 * V_159 )
{
struct V_196 * V_197 = F_127 ( V_159 , struct V_196 , V_159 ) ;
F_144 () ;
F_148 ( V_197 -> V_198 , V_197 -> V_199 ) ;
F_41 ( V_197 ) ;
}
T_11 F_149 ( struct V_200 * V_198 , T_1 V_199 )
{
struct V_196 * V_197 ;
F_140 ( ( V_186 ,
L_40 ,
V_198 , V_199 ) ) ;
V_197 = F_150 ( sizeof( * V_197 ) , V_60 ) ;
if ( ! V_197 )
return V_190 ;
F_141 ( & V_197 -> V_159 , F_147 ) ;
V_197 -> V_198 = V_198 ;
V_197 -> V_199 = V_199 ;
if ( ! F_151 ( V_201 , & V_197 -> V_159 ) ) {
F_41 ( V_197 ) ;
return V_153 ;
}
return V_68 ;
}
bool F_152 ( struct V_158 * V_159 )
{
return F_151 ( V_201 , V_159 ) ;
}
T_11
F_153 ( T_1 V_202 , T_1 V_203 , T_21 * V_204 )
{
struct V_205 * V_206 = NULL ;
V_206 = F_154 ( sizeof( struct V_205 ) ) ;
if ( ! V_206 )
return V_190 ;
F_155 ( V_206 , V_203 ) ;
* V_204 = ( T_21 * ) V_206 ;
F_140 ( ( V_207 , L_41 ,
* V_204 , V_203 ) ) ;
return V_68 ;
}
T_11 F_156 ( T_21 V_204 )
{
struct V_205 * V_206 = (struct V_205 * ) V_204 ;
if ( ! V_206 )
return V_67 ;
F_140 ( ( V_207 , L_42 , V_204 ) ) ;
F_157 ( ! F_158 ( & V_206 -> V_208 ) ) ;
F_41 ( V_206 ) ;
V_206 = NULL ;
return V_68 ;
}
T_11 F_159 ( T_21 V_204 , T_1 V_209 , V_143 V_210 )
{
T_11 V_183 = V_68 ;
struct V_205 * V_206 = (struct V_205 * ) V_204 ;
long V_211 ;
int V_166 = 0 ;
if ( ! V_212 )
return V_68 ;
if ( ! V_206 || ( V_209 < 1 ) )
return V_67 ;
if ( V_209 > 1 )
return V_213 ;
F_140 ( ( V_207 , L_43 ,
V_204 , V_209 , V_210 ) ) ;
if ( V_210 == V_214 )
V_211 = V_215 ;
else
V_211 = F_160 ( V_210 ) ;
V_166 = F_161 ( V_206 , V_211 ) ;
if ( V_166 )
V_183 = V_216 ;
if ( F_142 ( V_183 ) ) {
F_140 ( ( V_207 ,
L_44 ,
V_204 , V_209 , V_210 ,
F_162 ( V_183 ) ) ) ;
} else {
F_140 ( ( V_207 ,
L_45 , V_204 ,
V_209 , V_210 ) ) ;
}
return V_183 ;
}
T_11 F_163 ( T_21 V_204 , T_1 V_209 )
{
struct V_205 * V_206 = (struct V_205 * ) V_204 ;
if ( ! V_212 )
return V_68 ;
if ( ! V_206 || ( V_209 < 1 ) )
return V_67 ;
if ( V_209 > 1 )
return V_213 ;
F_140 ( ( V_207 , L_46 , V_204 ,
V_209 ) ) ;
F_164 ( V_206 ) ;
return V_68 ;
}
T_11 F_165 ( char * V_30 , T_1 V_176 , T_1 * V_217 )
{
#ifdef F_10
if ( V_31 ) {
T_1 V_218 ;
F_166 ( V_30 , V_176 ) ;
V_218 = strlen ( V_30 ) - 1 ;
V_30 [ V_218 ] = '\0' ;
}
#else
int V_166 ;
V_166 = F_134 ( V_30 , V_176 ) ;
if ( V_166 < 0 )
return V_153 ;
if ( V_217 )
* V_217 = V_166 ;
#endif
return V_68 ;
}
T_11 F_167 ( void )
{
int V_166 ;
V_166 = F_135 () ;
if ( V_166 < 0 )
return V_153 ;
return V_68 ;
}
T_11 F_168 ( void )
{
int V_166 ;
V_166 = F_136 () ;
if ( V_166 < 0 )
return V_153 ;
return V_68 ;
}
T_11 F_169 ( T_1 V_157 , void * V_219 )
{
switch ( V_157 ) {
case V_220 :
F_12 (KERN_ERR PREFIX L_47 ) ;
break;
case V_221 :
break;
default:
break;
}
return V_68 ;
}
static int T_3 F_170 ( char * V_69 )
{
char * V_222 = V_75 ;
int V_223 = V_224 - 1 ;
if ( ! V_69 || ! * V_69 )
return 0 ;
for (; V_223 -- && * V_69 ; V_69 ++ ) {
if ( isalnum ( * V_69 ) || * V_69 == ' ' || * V_69 == ':' )
* V_222 ++ = * V_69 ;
else if ( * V_69 == '\'' || * V_69 == '"' )
continue;
else
break;
}
* V_222 = 0 ;
return 1 ;
}
void T_3 F_171 ( char * V_69 )
{
struct V_225 * V_226 ;
bool V_227 = true ;
int V_228 ;
if ( ! V_229 )
return;
if ( V_69 == NULL || * V_69 == '\0' ) {
F_12 (KERN_INFO PREFIX L_48 ) ;
V_229 = FALSE ;
return;
}
if ( * V_69 == '!' ) {
V_69 ++ ;
if ( * V_69 == '\0' ) {
V_230 . V_231 = 1 ;
return;
} else if ( * V_69 == '*' ) {
F_3 ( V_232 ) ;
for ( V_228 = 0 ; V_228 < V_233 ; V_228 ++ ) {
V_226 = & V_234 [ V_228 ] ;
V_226 -> V_227 = false ;
}
return;
}
V_227 = false ;
}
for ( V_228 = 0 ; V_228 < V_233 ; V_228 ++ ) {
V_226 = & V_234 [ V_228 ] ;
if ( ! strcmp ( V_226 -> string , V_69 ) ) {
V_226 -> V_227 = V_227 ;
break;
} else if ( V_226 -> string [ 0 ] == '\0' ) {
V_226 -> V_227 = V_227 ;
strncpy ( V_226 -> string , V_69 , V_235 ) ;
break;
}
}
}
static void T_3 F_172 ( unsigned int V_227 )
{
if ( V_230 . V_227 != V_227 )
V_230 . V_227 = V_227 ;
if ( V_230 . V_227 )
F_171 ( L_1 ) ;
else
F_171 ( L_49 ) ;
return;
}
static void T_3 F_173 ( unsigned int V_227 )
{
V_230 . V_236 = 1 ;
V_230 . V_237 = 0 ;
F_172 ( V_227 ) ;
return;
}
void T_3 F_174 ( int V_227 , const struct V_238 * V_239 )
{
F_12 (KERN_NOTICE PREFIX L_50 , d->ident) ;
if ( V_227 == - 1 )
return;
V_230 . V_237 = 1 ;
F_172 ( V_227 ) ;
return;
}
static void T_3 F_175 ( void )
{
struct V_225 * V_226 ;
char * V_69 ;
int V_228 ;
T_11 V_183 ;
if ( V_230 . V_231 ) {
V_183 = F_3 ( V_3 ) ;
if ( F_176 ( V_183 ) )
F_12 (KERN_INFO PREFIX L_51 ) ;
}
for ( V_228 = 0 ; V_228 < V_233 ; V_228 ++ ) {
V_226 = & V_234 [ V_228 ] ;
V_69 = V_226 -> string ;
if ( * V_69 == '\0' )
break;
if ( V_226 -> V_227 ) {
V_183 = F_177 ( V_69 ) ;
if ( F_176 ( V_183 ) )
F_12 (KERN_INFO PREFIX L_52 , str) ;
} else {
V_183 = F_178 ( V_69 ) ;
if ( F_176 ( V_183 ) )
F_12 (KERN_INFO PREFIX L_53 , str) ;
}
}
}
static int T_3 F_179 ( char * V_69 )
{
if ( V_69 && ! strcmp ( L_1 , V_69 ) )
F_173 ( 1 ) ;
else if ( V_69 && ! strcmp ( L_49 , V_69 ) )
F_173 ( 0 ) ;
else
F_171 ( V_69 ) ;
return 1 ;
}
static int T_3 F_180 ( char * V_69 )
{
V_240 = FALSE ;
F_67 ( L_54 ) ;
return 1 ;
}
static int T_3 F_181 ( char * V_69 )
{
if ( V_69 == NULL || * V_69 == '\0' )
return 0 ;
if ( ! strcmp ( L_55 , V_69 ) )
V_241 = V_242 ;
else if ( ! strcmp ( L_56 , V_69 ) )
V_241 = V_243 ;
else if ( ! strcmp ( L_57 , V_69 ) )
V_241 = V_244 ;
return 1 ;
}
int F_182 ( const struct V_245 * V_246 )
{
T_22 V_11 ;
T_7 V_7 ;
T_12 V_247 = 0 ;
int V_248 = 0 ;
if ( V_241 == V_244 )
return 0 ;
if ( ! ( V_246 -> V_249 & V_250 ) && ! ( V_246 -> V_249 & V_251 ) )
return 0 ;
if ( V_246 -> V_249 & V_250 )
V_11 = V_12 ;
else
V_11 = V_13 ;
V_7 = F_183 ( V_246 ) ;
if ( V_241 != V_244 )
V_247 = 1 ;
V_248 = F_184 ( V_11 , V_246 -> V_252 , V_7 , V_247 ) ;
if ( V_248 ) {
if ( V_241 != V_244 ) {
if ( V_241 == V_243 )
F_12 ( V_253 L_58
L_59
L_60 ) ;
F_12 ( V_254 L_61
L_62
L_63 ) ;
}
if ( V_241 == V_242 )
return - V_169 ;
}
return 0 ;
}
int F_185 ( T_23 V_252 , T_23 V_255 ,
const char * V_74 )
{
struct V_245 V_246 = {
. V_252 = V_252 ,
. V_83 = V_252 + V_255 - 1 ,
. V_74 = V_74 ,
. V_249 = V_250 ,
} ;
return F_182 ( & V_246 ) ;
}
int F_186 ( void )
{
return V_241 == V_242 ;
}
bool F_187 ( void )
{
return V_256 >= V_257 ;
}
void F_188 ( T_24 V_204 )
{
F_189 ( V_204 ) ;
}
T_25 F_190 ( T_24 V_258 )
{
T_25 V_249 ;
F_191 ( V_258 , V_249 ) ;
return V_249 ;
}
void F_192 ( T_24 V_258 , T_25 V_249 )
{
F_193 ( V_258 , V_249 ) ;
}
T_11
F_194 ( char * V_74 , V_143 V_45 , V_143 V_259 , T_26 * * V_260 )
{
* V_260 = F_195 ( V_74 , V_45 , 0 , 0 , NULL ) ;
if ( * V_260 == NULL )
return V_153 ;
else
return V_68 ;
}
T_11 F_196 ( T_26 * V_260 )
{
F_197 ( V_260 ) ;
return ( V_68 ) ;
}
T_11 F_198 ( T_26 * V_260 )
{
F_199 ( V_260 ) ;
return ( V_68 ) ;
}
T_11 F_200 ( T_26 * V_260 , void * V_261 )
{
F_201 ( V_260 , V_261 ) ;
return ( V_68 ) ;
}
static int T_3 F_202 ( char * V_262 )
{
V_263 = TRUE ;
F_67 ( L_64 ) ;
return 0 ;
}
static int T_3 F_203 ( char * V_262 )
{
F_12 (KERN_NOTICE PREFIX
L_65 ) ;
V_264 = TRUE ;
return 1 ;
}
T_11 T_3 F_204 ( void )
{
F_54 ( & V_14 . V_15 ) ;
F_54 ( & V_14 . V_17 ) ;
F_54 ( & V_14 . V_26 ) ;
F_54 ( & V_14 . V_28 ) ;
if ( V_14 . V_249 & V_265 ) {
int V_266 ;
V_266 = F_54 ( & V_14 . V_267 ) ;
F_205 ( V_63 L_66 , V_64 , V_266 ) ;
}
V_212 = true ;
return V_68 ;
}
T_11 T_3 F_206 ( void )
{
V_194 = F_207 ( L_67 , 0 , 1 ) ;
V_192 = F_207 ( L_68 , 0 , 1 ) ;
V_201 = F_208 ( L_69 , 0 ) ;
F_157 ( ! V_194 ) ;
F_157 ( ! V_192 ) ;
F_157 ( ! V_201 ) ;
F_209 ( F_1 ) ;
F_175 () ;
return V_68 ;
}
T_11 F_210 ( void )
{
if ( F_83 ) {
F_88 ( V_14 . V_129 ,
F_83 ) ;
}
F_55 ( & V_14 . V_28 ) ;
F_55 ( & V_14 . V_26 ) ;
F_55 ( & V_14 . V_17 ) ;
F_55 ( & V_14 . V_15 ) ;
if ( V_14 . V_249 & V_265 )
F_55 ( & V_14 . V_267 ) ;
F_211 ( V_194 ) ;
F_211 ( V_192 ) ;
F_211 ( V_201 ) ;
return V_68 ;
}
T_11 F_212 ( T_12 V_268 , T_1 V_269 ,
T_1 V_270 )
{
int V_271 = 0 ;
if ( V_272 )
V_271 = V_272 ( V_268 ,
V_269 , V_270 ) ;
if ( V_271 < 0 )
return V_153 ;
else if ( V_271 > 0 )
return V_273 ;
return V_68 ;
}
void F_213 ( int (* F_131)( T_12 V_268 ,
T_1 V_274 , T_1 V_275 ) )
{
V_272 = F_131 ;
}
T_11 F_214 ( T_12 V_268 , T_1 V_276 ,
T_1 V_277 )
{
int V_271 = 0 ;
if ( V_278 )
V_271 = V_278 ( V_268 ,
V_276 , V_277 ) ;
if ( V_271 < 0 )
return V_153 ;
else if ( V_271 > 0 )
return V_273 ;
return V_68 ;
}
void F_215 ( int (* F_131)( T_12 V_268 ,
T_1 V_276 , T_1 V_277 ) )
{
V_278 = F_131 ;
}
