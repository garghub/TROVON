const char * F_1 ( unsigned type )
{
if ( type == 0x1e )
return L_1 ;
if ( type == 0x1f )
return L_2 ;
if ( type >= F_2 ( V_1 ) )
return L_3 ;
return V_1 [ type ] ;
}
static void
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
if ( V_5 -> V_9 )
F_4 ( V_10 , V_5 -> V_9 ) ;
F_4 ( V_7 -> V_11 , V_5 -> V_12 ) ;
F_4 ( V_7 -> V_13 , V_5 ) ;
}
static struct V_4 *
F_5 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_4 * V_5 ;
V_5 = F_6 ( V_7 -> V_13 , V_14 | V_7 -> V_14 ) ;
if ( ! V_5 )
goto V_15;
V_5 -> V_12 = F_7 ( V_7 -> V_11 ,
V_14 | V_7 -> V_14 ) ;
if ( ! V_5 -> V_12 )
goto V_16;
if ( F_8 ( V_3 ) >= V_17 ) {
V_5 -> V_9 = F_6 ( V_10 , V_14 ) ;
if ( ! V_5 -> V_9 )
goto V_18;
}
return V_5 ;
V_18:
F_4 ( V_7 -> V_11 , V_5 -> V_12 ) ;
V_16:
F_4 ( V_7 -> V_13 , V_5 ) ;
V_15:
return NULL ;
}
static struct V_4 *
F_9 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_4 * V_5 = F_5 ( V_3 , V_14 ) ;
if ( F_10 ( ! V_5 ) ) {
unsigned long V_19 ;
F_11 ( & V_3 -> V_20 , V_19 ) ;
if ( F_12 ( ! F_13 ( & V_3 -> V_21 ) ) ) {
V_5 = F_14 ( V_3 -> V_21 . V_22 ,
struct V_4 , V_23 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
F_16 ( & V_3 -> V_20 , V_19 ) ;
if ( V_5 ) {
void * V_24 , * V_25 ;
V_24 = V_5 -> V_12 ;
V_25 = V_5 -> V_9 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_12 = V_24 ;
V_5 -> V_9 = V_25 ;
}
}
return V_5 ;
}
struct V_4 * F_17 ( struct V_26 * V_27 , T_1 V_14 )
{
struct V_4 * V_5 = F_9 ( V_27 -> V_28 , V_14 ) ;
unsigned long V_19 ;
if ( F_10 ( V_5 == NULL ) )
return NULL ;
V_5 -> V_29 = V_27 ;
F_18 ( & V_5 -> V_23 ) ;
F_19 ( & V_5 -> V_30 , V_31 ) ;
F_11 ( & V_27 -> V_32 , V_19 ) ;
F_20 ( & V_5 -> V_23 , & V_27 -> V_33 ) ;
F_16 ( & V_27 -> V_32 , V_19 ) ;
V_5 -> V_34 = V_35 ;
return V_5 ;
}
static void F_21 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_19 ;
if ( F_10 ( F_13 ( & V_3 -> V_21 ) ) ) {
F_11 ( & V_3 -> V_20 , V_19 ) ;
if ( F_13 ( & V_3 -> V_21 ) ) {
F_22 ( & V_5 -> V_23 , & V_3 -> V_21 ) ;
V_5 = NULL ;
}
F_16 ( & V_3 -> V_20 , V_19 ) ;
}
if ( F_12 ( V_5 != NULL ) )
F_3 ( V_3 , V_5 ) ;
}
void F_23 ( struct V_4 * V_5 )
{
unsigned long V_19 ;
F_11 ( & V_5 -> V_29 -> V_32 , V_19 ) ;
F_24 ( F_13 ( & V_5 -> V_23 ) ) ;
F_15 ( & V_5 -> V_23 ) ;
F_16 ( & V_5 -> V_29 -> V_32 , V_19 ) ;
F_24 ( F_25 ( & V_5 -> V_30 ) ) ;
F_21 ( V_5 -> V_29 -> V_28 , V_5 ) ;
}
static struct V_6 *
F_26 ( struct V_2 * V_3 )
{
if ( V_3 -> V_36 -> V_37 )
return V_3 -> V_36 -> V_8 ;
if ( V_3 -> V_38 )
return & V_39 ;
return & V_40 ;
}
static void
F_27 ( struct V_6 * V_7 )
{
F_28 ( V_7 -> V_41 ) ;
F_28 ( V_7 -> V_42 ) ;
F_28 ( V_7 ) ;
}
static struct V_6 *
F_29 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_7 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_42 = F_31 ( V_44 , L_4 , V_36 -> V_45 ) ;
V_7 -> V_41 = F_31 ( V_44 , L_5 , V_36 -> V_45 ) ;
if ( ! V_7 -> V_42 || ! V_7 -> V_41 ) {
F_27 ( V_7 ) ;
return NULL ;
}
V_7 -> V_46 = V_47 ;
if ( V_3 -> V_38 ) {
V_7 -> V_46 |= V_48 ;
V_7 -> V_14 = V_49 ;
}
if ( V_36 -> V_37 )
V_36 -> V_8 = V_7 ;
return V_7 ;
}
static struct V_6 *
F_32 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_50 = NULL , * V_7 ;
T_2 V_37 = sizeof( struct V_4 ) + V_36 -> V_37 ;
F_33 ( & V_51 ) ;
V_7 = F_26 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_29 ( V_3 ) ;
if ( ! V_7 )
goto V_52;
}
if ( ! V_7 -> V_53 ) {
V_7 -> V_13 = F_34 ( V_7 -> V_42 , V_37 , 0 ,
V_7 -> V_46 , NULL ) ;
if ( ! V_7 -> V_13 )
goto V_54;
V_7 -> V_11 = F_34 ( V_7 -> V_41 ,
V_55 , 0 ,
V_7 -> V_46 , NULL ) ;
if ( ! V_7 -> V_11 )
goto V_56;
}
V_7 -> V_53 ++ ;
V_50 = V_7 ;
V_52:
F_35 ( & V_51 ) ;
return V_50 ;
V_56:
F_36 ( V_7 -> V_13 ) ;
V_54:
if ( V_36 -> V_37 ) {
F_27 ( V_7 ) ;
V_36 -> V_8 = NULL ;
}
goto V_52;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_7 ;
F_33 ( & V_51 ) ;
V_7 = F_26 ( V_3 ) ;
F_24 ( V_7 -> V_53 == 0 ) ;
if ( ! -- V_7 -> V_53 ) {
F_36 ( V_7 -> V_13 ) ;
F_36 ( V_7 -> V_11 ) ;
if ( V_36 -> V_37 ) {
F_27 ( V_7 ) ;
V_36 -> V_8 = NULL ;
}
}
F_35 ( & V_51 ) ;
}
int F_38 ( struct V_2 * V_3 )
{
const T_1 V_14 = V_3 -> V_38 ? V_57 : V_44 ;
struct V_4 * V_5 ;
F_39 ( & V_3 -> V_20 ) ;
F_18 ( & V_3 -> V_21 ) ;
V_3 -> V_8 = F_32 ( V_3 ) ;
if ( ! V_3 -> V_8 )
return - V_58 ;
V_5 = F_5 ( V_3 , V_14 ) ;
if ( ! V_5 ) {
F_37 ( V_3 ) ;
V_3 -> V_8 = NULL ;
return - V_58 ;
}
F_22 ( & V_5 -> V_23 , & V_3 -> V_21 ) ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
return;
while ( ! F_13 ( & V_3 -> V_21 ) ) {
struct V_4 * V_5 ;
V_5 = F_14 ( V_3 -> V_21 . V_22 , struct V_4 , V_23 ) ;
F_15 ( & V_5 -> V_23 ) ;
F_3 ( V_3 , V_5 ) ;
}
V_3 -> V_8 = NULL ;
F_37 ( V_3 ) ;
}
void F_41 ( struct V_4 * V_5 )
{
unsigned int V_59 ;
if ( F_10 ( V_60 ) ) {
V_59 = F_42 ( V_61 ,
V_62 ) ;
if ( V_59 > 1 ) {
F_43 ( V_63 , V_5 ,
L_6 , V_5 ) ;
F_44 ( V_5 ) ;
if ( V_59 > 3 ) {
F_45 ( V_63 L_7
L_8 ,
F_46 ( V_5 ) , F_47 ( V_5 ) ,
V_5 -> V_29 -> V_28 -> V_36 -> V_64 ) ;
}
}
}
}
void F_48 ( struct V_4 * V_5 , int V_65 )
{
unsigned int V_59 ;
if ( F_10 ( V_60 ) ) {
V_59 = F_42 ( V_66 ,
V_67 ) ;
if ( ( ( V_59 > 0 ) && ( V_5 -> V_68 || V_65 != V_69 ) ) ||
( V_59 > 1 ) ) {
F_49 ( V_5 , L_9 , V_65 ) ;
F_44 ( V_5 ) ;
if ( F_50 ( V_5 -> V_68 ) & V_70 )
F_51 ( V_5 ) ;
if ( V_59 > 3 )
F_43 ( V_63 , V_5 ,
L_10 ,
F_52 ( & V_5 -> V_29 -> V_28 -> V_71 ) ,
V_5 -> V_29 -> V_28 -> V_72 ) ;
}
}
}
void F_53 ( struct V_2 * V_28 , struct V_4 * V_5 )
{
V_5 -> V_73 = V_28 -> V_74 ++ ;
if ( V_5 -> V_73 == 0 )
V_5 -> V_73 = V_28 -> V_74 ++ ;
}
void F_54 ( struct V_4 * V_5 )
{
struct V_26 * V_75 = V_5 -> V_29 ;
struct V_76 * V_77 = V_76 ( V_75 ) ;
struct V_2 * V_3 = V_75 -> V_28 ;
struct V_78 * V_79 ;
unsigned int V_80 ;
F_55 ( V_75 ) ;
if ( F_52 ( & V_3 -> V_81 ) )
F_56 ( & V_3 -> V_81 , 0 ) ;
if ( F_52 ( & V_77 -> V_82 ) )
F_56 ( & V_77 -> V_82 , 0 ) ;
if ( F_52 ( & V_75 -> V_83 ) )
F_56 ( & V_75 -> V_83 , 0 ) ;
if ( F_57 ( V_5 ) )
V_5 -> V_68 |= ( V_84 << 24 ) ;
F_58 ( 4 , F_59 ( V_63 , V_75 ,
L_11
L_12 , V_5 -> V_68 ) ) ;
V_80 = F_47 ( V_5 ) ;
if ( V_5 -> V_85 -> V_86 != V_87 ) {
int V_88 = V_80 ;
V_79 = F_60 ( V_5 ) ;
if ( V_79 -> V_89 )
V_80 = V_79 -> V_89 ( V_5 ) ;
if ( V_80 == V_88 )
V_80 -= F_61 ( V_5 ) ;
}
F_62 ( V_5 , V_80 ) ;
}
int F_63 ( struct V_26 * V_75 , int V_90 )
{
unsigned long V_19 ;
if ( V_90 <= 0 )
goto V_52;
F_11 ( V_75 -> V_91 -> V_92 , V_19 ) ;
if ( ! F_64 ( V_75 -> V_28 ) && ! V_75 -> V_28 -> V_93 ) {
if ( F_65 ( V_75 -> V_91 ) &&
F_66 ( V_75 -> V_91 , V_90 ) != 0 )
goto V_94;
}
V_75 -> V_95 = V_90 ;
V_94:
F_16 ( V_75 -> V_91 -> V_92 , V_19 ) ;
V_52:
return V_75 -> V_95 ;
}
int F_67 ( struct V_26 * V_75 , int V_90 )
{
if ( ( V_35 >> 4 ) == ( V_75 -> V_96 >> 4 ) )
return 0 ;
V_75 -> V_96 = V_35 ;
if ( V_75 -> V_97 != V_90 ) {
V_75 -> V_98 = 1 ;
V_75 -> V_97 = V_90 ;
} else {
V_75 -> V_98 ++ ;
}
if ( V_75 -> V_98 <= 10 )
return 0 ;
return F_63 ( V_75 , V_90 ) ;
}
static int F_68 ( struct V_26 * V_75 , unsigned char * V_99 ,
T_3 V_100 , unsigned V_101 )
{
int V_68 ;
unsigned char V_5 [ 16 ] ;
if ( V_101 < 4 )
return - V_102 ;
V_5 [ 0 ] = V_103 ;
V_5 [ 1 ] = 1 ;
V_5 [ 2 ] = V_100 ;
V_5 [ 3 ] = V_101 >> 8 ;
V_5 [ 4 ] = V_101 & 0xff ;
V_5 [ 5 ] = 0 ;
V_68 = F_69 ( V_75 , V_5 , V_104 , V_99 ,
V_101 , NULL , 30 * V_105 , 3 , NULL ) ;
if ( V_68 )
return - V_106 ;
if ( V_99 [ 1 ] != V_100 )
return - V_106 ;
return F_70 ( & V_99 [ 2 ] ) + 4 ;
}
int F_71 ( struct V_26 * V_75 , T_3 V_100 , unsigned char * V_24 ,
int V_107 )
{
int V_108 , V_68 ;
if ( V_75 -> V_109 )
goto V_15;
V_68 = F_68 ( V_75 , V_24 , 0 , V_107 ) ;
if ( V_68 < 4 )
goto V_15;
if ( V_100 == 0 )
return 0 ;
for ( V_108 = 4 ; V_108 < F_72 ( V_68 , V_107 ) ; V_108 ++ )
if ( V_24 [ V_108 ] == V_100 )
goto V_110;
if ( V_108 < V_68 && V_108 >= V_107 )
goto V_110;
goto V_15;
V_110:
V_68 = F_68 ( V_75 , V_24 , V_100 , V_107 ) ;
if ( V_68 < 0 )
goto V_15;
return 0 ;
V_15:
return - V_102 ;
}
void F_73 ( struct V_26 * V_75 )
{
int V_68 , V_108 ;
int V_111 = V_112 ;
int V_113 = 0 ;
int V_114 = 0 ;
unsigned char * V_115 ;
if ( V_75 -> V_109 )
return;
V_116:
V_115 = F_74 ( V_111 , V_44 ) ;
if ( ! V_115 )
return;
V_68 = F_68 ( V_75 , V_115 , 0 , V_111 ) ;
if ( V_68 < 0 ) {
F_28 ( V_115 ) ;
return;
}
if ( V_68 > V_111 ) {
V_111 = V_68 ;
F_28 ( V_115 ) ;
goto V_116;
}
for ( V_108 = 4 ; V_108 < V_68 ; V_108 ++ ) {
if ( V_115 [ V_108 ] == 0x80 )
V_113 = 1 ;
if ( V_115 [ V_108 ] == 0x83 )
V_114 = 1 ;
}
F_28 ( V_115 ) ;
V_111 = V_112 ;
if ( V_113 ) {
V_117:
V_115 = F_74 ( V_111 , V_44 ) ;
if ( ! V_115 )
return;
V_68 = F_68 ( V_75 , V_115 , 0x80 , V_111 ) ;
if ( V_68 < 0 ) {
F_28 ( V_115 ) ;
return;
}
if ( V_68 > V_111 ) {
V_111 = V_68 ;
F_28 ( V_115 ) ;
goto V_117;
}
V_75 -> V_118 = V_68 ;
V_75 -> V_119 = V_115 ;
V_111 = V_112 ;
}
if ( V_114 ) {
V_120:
V_115 = F_74 ( V_111 , V_44 ) ;
if ( ! V_115 )
return;
V_68 = F_68 ( V_75 , V_115 , 0x83 , V_111 ) ;
if ( V_68 < 0 ) {
F_28 ( V_115 ) ;
return;
}
if ( V_68 > V_111 ) {
V_111 = V_68 ;
F_28 ( V_115 ) ;
goto V_120;
}
V_75 -> V_121 = V_68 ;
V_75 -> V_122 = V_115 ;
}
}
int F_75 ( struct V_26 * V_75 , unsigned char * V_99 ,
unsigned int V_101 , unsigned char V_123 )
{
unsigned char V_5 [ 16 ] ;
struct V_124 V_125 ;
int V_68 ;
if ( V_75 -> V_126 || V_75 -> V_127 < V_128 )
return - V_102 ;
memset ( V_5 , 0 , 16 ) ;
V_5 [ 0 ] = V_129 ;
V_5 [ 1 ] = V_130 ;
V_5 [ 2 ] = 1 ;
V_5 [ 3 ] = V_123 ;
F_76 ( V_101 , & V_5 [ 6 ] ) ;
memset ( V_99 , 0 , V_101 ) ;
V_68 = F_69 ( V_75 , V_5 , V_104 , V_99 , V_101 ,
& V_125 , 30 * V_105 , 3 , NULL ) ;
if ( V_68 && F_77 ( & V_125 ) &&
V_125 . V_131 == V_132 &&
( V_125 . V_133 == 0x20 || V_125 . V_133 == 0x24 ) && V_125 . V_134 == 0x00 )
return - V_102 ;
if ( ( V_99 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_78 ( struct V_26 * V_75 )
{
if ( V_75 -> V_135 == V_136 )
return - V_137 ;
if ( ! F_79 ( & V_75 -> V_138 ) )
return - V_137 ;
F_80 ( V_75 -> V_28 -> V_36 -> V_139 ) ;
return 0 ;
}
void F_81 ( struct V_26 * V_75 )
{
F_82 ( V_75 -> V_28 -> V_36 -> V_139 ) ;
F_83 ( & V_75 -> V_138 ) ;
}
struct V_26 * F_84 ( struct V_2 * V_3 ,
struct V_26 * V_140 )
{
struct V_141 * V_23 = ( V_140 ? & V_140 -> V_142 : & V_3 -> V_143 ) ;
struct V_26 * V_22 = NULL ;
unsigned long V_19 ;
F_11 ( V_3 -> V_144 , V_19 ) ;
while ( V_23 -> V_22 != & V_3 -> V_143 ) {
V_22 = F_14 ( V_23 -> V_22 , struct V_26 , V_142 ) ;
if ( ! F_78 ( V_22 ) )
break;
V_22 = NULL ;
V_23 = V_23 -> V_22 ;
}
F_16 ( V_3 -> V_144 , V_19 ) ;
if ( V_140 )
F_81 ( V_140 ) ;
return V_22 ;
}
void F_85 ( struct V_76 * V_77 , void * V_145 ,
void (* F_86)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_87 ( V_77 -> V_27 . V_146 ) ;
struct V_26 * V_75 ;
F_88 (sdev, shost) {
if ( ( V_75 -> V_147 == V_77 -> V_147 ) &&
( V_75 -> V_148 == V_77 -> V_148 ) )
F_86 ( V_75 , V_145 ) ;
}
}
void F_89 ( struct V_76 * V_77 , void * V_145 ,
void (* F_86)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_87 ( V_77 -> V_27 . V_146 ) ;
struct V_26 * V_75 ;
F_90 (sdev, shost) {
if ( ( V_75 -> V_147 == V_77 -> V_147 ) &&
( V_75 -> V_148 == V_77 -> V_148 ) )
F_86 ( V_75 , V_145 ) ;
}
}
struct V_26 * F_91 ( struct V_76 * V_77 ,
T_4 V_149 )
{
struct V_26 * V_75 ;
F_92 (sdev, &starget->devices, same_target_siblings) {
if ( V_75 -> V_135 == V_136 )
continue;
if ( V_75 -> V_149 == V_149 )
return V_75 ;
}
return NULL ;
}
struct V_26 * F_93 ( struct V_76 * V_77 ,
T_4 V_149 )
{
struct V_26 * V_75 ;
struct V_2 * V_3 = F_87 ( V_77 -> V_27 . V_146 ) ;
unsigned long V_19 ;
F_11 ( V_3 -> V_144 , V_19 ) ;
V_75 = F_91 ( V_77 , V_149 ) ;
if ( V_75 && F_78 ( V_75 ) )
V_75 = NULL ;
F_16 ( V_3 -> V_144 , V_19 ) ;
return V_75 ;
}
struct V_26 * F_94 ( struct V_2 * V_3 ,
T_5 V_147 , T_5 V_148 , T_4 V_149 )
{
struct V_26 * V_75 ;
F_92 (sdev, &shost->__devices, siblings) {
if ( V_75 -> V_147 == V_147 && V_75 -> V_148 == V_148 &&
V_75 -> V_149 == V_149 )
return V_75 ;
}
return NULL ;
}
struct V_26 * F_95 ( struct V_2 * V_3 ,
T_5 V_147 , T_5 V_148 , T_4 V_149 )
{
struct V_26 * V_75 ;
unsigned long V_19 ;
F_11 ( V_3 -> V_144 , V_19 ) ;
V_75 = F_94 ( V_3 , V_147 , V_148 , V_149 ) ;
if ( V_75 && F_78 ( V_75 ) )
V_75 = NULL ;
F_16 ( V_3 -> V_144 , V_19 ) ;
return V_75 ;
}
static int T_6 F_96 ( void )
{
int error ;
error = F_97 () ;
if ( error )
return error ;
error = F_98 () ;
if ( error )
goto V_150;
error = F_99 () ;
if ( error )
goto V_151;
error = F_100 () ;
if ( error )
goto V_152;
error = F_101 () ;
if ( error )
goto V_153;
error = F_102 () ;
if ( error )
goto V_154;
F_103 () ;
F_45 ( V_155 L_13 ) ;
return 0 ;
V_154:
F_104 () ;
V_153:
F_105 () ;
V_152:
F_106 () ;
V_151:
F_107 () ;
V_150:
F_108 () ;
F_45 ( V_156 L_14 ,
- error ) ;
return error ;
}
static void T_7 F_109 ( void )
{
F_110 () ;
F_111 () ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_112 ( & V_157 ) ;
}
