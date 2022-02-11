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
}
}
}
void F_45 ( struct V_4 * V_5 , int V_64 )
{
unsigned int V_59 ;
if ( F_10 ( V_60 ) ) {
V_59 = F_42 ( V_65 ,
V_66 ) ;
if ( ( ( V_59 > 0 ) && ( V_5 -> V_67 || V_64 != V_68 ) ) ||
( V_59 > 1 ) ) {
F_46 ( V_5 , L_7 , V_64 ) ;
F_44 ( V_5 ) ;
if ( F_47 ( V_5 -> V_67 ) & V_69 )
F_48 ( V_5 ) ;
if ( V_59 > 3 )
F_43 ( V_63 , V_5 ,
L_8 ,
F_49 ( & V_5 -> V_29 -> V_28 -> V_70 ) ,
V_5 -> V_29 -> V_28 -> V_71 ) ;
}
}
}
void F_50 ( struct V_2 * V_28 , struct V_4 * V_5 )
{
V_5 -> V_72 = V_28 -> V_73 ++ ;
if ( V_5 -> V_72 == 0 )
V_5 -> V_72 = V_28 -> V_73 ++ ;
}
void F_51 ( struct V_4 * V_5 )
{
struct V_26 * V_74 = V_5 -> V_29 ;
struct V_75 * V_76 = V_75 ( V_74 ) ;
struct V_2 * V_3 = V_74 -> V_28 ;
struct V_77 * V_78 ;
unsigned int V_79 ;
F_52 ( V_74 ) ;
if ( F_49 ( & V_3 -> V_80 ) )
F_53 ( & V_3 -> V_80 , 0 ) ;
if ( F_49 ( & V_76 -> V_81 ) )
F_53 ( & V_76 -> V_81 , 0 ) ;
if ( F_49 ( & V_74 -> V_82 ) )
F_53 ( & V_74 -> V_82 , 0 ) ;
if ( F_54 ( V_5 ) )
V_5 -> V_67 |= ( V_83 << 24 ) ;
F_55 ( 4 , F_56 ( V_63 , V_74 ,
L_9
L_10 , V_5 -> V_67 ) ) ;
V_79 = F_57 ( V_5 ) ;
if ( V_5 -> V_84 -> V_85 != V_86 ) {
int V_87 = V_79 ;
V_78 = F_58 ( V_5 ) ;
if ( V_78 -> V_88 )
V_79 = V_78 -> V_88 ( V_5 ) ;
if ( V_79 == V_87 )
V_79 -= F_59 ( V_5 ) ;
}
F_60 ( V_5 , V_79 ) ;
}
int F_61 ( struct V_26 * V_74 , int V_89 )
{
unsigned long V_19 ;
if ( V_89 <= 0 )
goto V_52;
F_11 ( V_74 -> V_90 -> V_91 , V_19 ) ;
if ( ! F_62 ( V_74 -> V_28 ) && ! V_74 -> V_28 -> V_92 ) {
if ( F_63 ( V_74 -> V_90 ) &&
F_64 ( V_74 -> V_90 , V_89 ) != 0 )
goto V_93;
}
V_74 -> V_94 = V_89 ;
V_93:
F_16 ( V_74 -> V_90 -> V_91 , V_19 ) ;
V_52:
return V_74 -> V_94 ;
}
int F_65 ( struct V_26 * V_74 , int V_89 )
{
if ( ( V_35 >> 4 ) == ( V_74 -> V_95 >> 4 ) )
return 0 ;
V_74 -> V_95 = V_35 ;
if ( V_74 -> V_96 != V_89 ) {
V_74 -> V_97 = 1 ;
V_74 -> V_96 = V_89 ;
} else {
V_74 -> V_97 ++ ;
}
if ( V_74 -> V_97 <= 10 )
return 0 ;
return F_61 ( V_74 , V_89 ) ;
}
static int F_66 ( struct V_26 * V_74 , unsigned char * V_98 ,
T_3 V_99 , unsigned V_100 )
{
int V_67 ;
unsigned char V_5 [ 16 ] ;
if ( V_100 < 4 )
return - V_101 ;
V_5 [ 0 ] = V_102 ;
V_5 [ 1 ] = 1 ;
V_5 [ 2 ] = V_99 ;
V_5 [ 3 ] = V_100 >> 8 ;
V_5 [ 4 ] = V_100 & 0xff ;
V_5 [ 5 ] = 0 ;
V_67 = F_67 ( V_74 , V_5 , V_103 , V_98 ,
V_100 , NULL , 30 * V_104 , 3 , NULL ) ;
if ( V_67 )
return - V_105 ;
if ( V_98 [ 1 ] != V_99 )
return - V_105 ;
return F_68 ( & V_98 [ 2 ] ) + 4 ;
}
int F_69 ( struct V_26 * V_74 , T_3 V_99 , unsigned char * V_24 ,
int V_106 )
{
int V_107 , V_67 ;
if ( V_74 -> V_108 )
goto V_15;
V_67 = F_66 ( V_74 , V_24 , 0 , V_106 ) ;
if ( V_67 < 4 )
goto V_15;
if ( V_99 == 0 )
return 0 ;
for ( V_107 = 4 ; V_107 < F_70 ( V_67 , V_106 ) ; V_107 ++ )
if ( V_24 [ V_107 ] == V_99 )
goto V_109;
if ( V_107 < V_67 && V_107 >= V_106 )
goto V_109;
goto V_15;
V_109:
V_67 = F_66 ( V_74 , V_24 , V_99 , V_106 ) ;
if ( V_67 < 0 )
goto V_15;
return 0 ;
V_15:
return - V_101 ;
}
void F_71 ( struct V_26 * V_74 )
{
int V_67 , V_107 ;
int V_110 = V_111 ;
int V_112 = 0 ;
int V_113 = 0 ;
unsigned char * V_114 ;
if ( V_74 -> V_108 )
return;
V_115:
V_114 = F_72 ( V_110 , V_44 ) ;
if ( ! V_114 )
return;
V_67 = F_66 ( V_74 , V_114 , 0 , V_110 ) ;
if ( V_67 < 0 ) {
F_28 ( V_114 ) ;
return;
}
if ( V_67 > V_110 ) {
V_110 = V_67 ;
F_28 ( V_114 ) ;
goto V_115;
}
for ( V_107 = 4 ; V_107 < V_67 ; V_107 ++ ) {
if ( V_114 [ V_107 ] == 0x80 )
V_112 = 1 ;
if ( V_114 [ V_107 ] == 0x83 )
V_113 = 1 ;
}
F_28 ( V_114 ) ;
V_110 = V_111 ;
if ( V_112 ) {
V_116:
V_114 = F_72 ( V_110 , V_44 ) ;
if ( ! V_114 )
return;
V_67 = F_66 ( V_74 , V_114 , 0x80 , V_110 ) ;
if ( V_67 < 0 ) {
F_28 ( V_114 ) ;
return;
}
if ( V_67 > V_110 ) {
V_110 = V_67 ;
F_28 ( V_114 ) ;
goto V_116;
}
V_74 -> V_117 = V_67 ;
V_74 -> V_118 = V_114 ;
V_110 = V_111 ;
}
if ( V_113 ) {
V_119:
V_114 = F_72 ( V_110 , V_44 ) ;
if ( ! V_114 )
return;
V_67 = F_66 ( V_74 , V_114 , 0x83 , V_110 ) ;
if ( V_67 < 0 ) {
F_28 ( V_114 ) ;
return;
}
if ( V_67 > V_110 ) {
V_110 = V_67 ;
F_28 ( V_114 ) ;
goto V_119;
}
V_74 -> V_120 = V_67 ;
V_74 -> V_121 = V_114 ;
}
}
int F_73 ( struct V_26 * V_74 , unsigned char * V_98 ,
unsigned int V_100 , unsigned char V_122 )
{
unsigned char V_5 [ 16 ] ;
struct V_123 V_124 ;
int V_67 ;
if ( V_74 -> V_125 || V_74 -> V_126 < V_127 )
return - V_101 ;
memset ( V_5 , 0 , 16 ) ;
V_5 [ 0 ] = V_128 ;
V_5 [ 1 ] = V_129 ;
V_5 [ 2 ] = 1 ;
V_5 [ 3 ] = V_122 ;
F_74 ( V_100 , & V_5 [ 6 ] ) ;
memset ( V_98 , 0 , V_100 ) ;
V_67 = F_67 ( V_74 , V_5 , V_103 , V_98 , V_100 ,
& V_124 , 30 * V_104 , 3 , NULL ) ;
if ( V_67 && F_75 ( & V_124 ) &&
V_124 . V_130 == V_131 &&
( V_124 . V_132 == 0x20 || V_124 . V_132 == 0x24 ) && V_124 . V_133 == 0x00 )
return - V_101 ;
if ( ( V_98 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_76 ( struct V_26 * V_74 )
{
if ( V_74 -> V_134 == V_135 || V_74 -> V_134 == V_136 )
goto V_15;
if ( ! F_77 ( & V_74 -> V_137 ) )
goto V_15;
if ( ! F_78 ( V_74 -> V_28 -> V_36 -> V_138 ) )
goto V_139;
return 0 ;
V_139:
F_79 ( & V_74 -> V_137 ) ;
V_15:
return - V_140 ;
}
void F_80 ( struct V_26 * V_74 )
{
F_81 ( V_74 -> V_28 -> V_36 -> V_138 ) ;
F_79 ( & V_74 -> V_137 ) ;
}
struct V_26 * F_82 ( struct V_2 * V_3 ,
struct V_26 * V_141 )
{
struct V_142 * V_23 = ( V_141 ? & V_141 -> V_143 : & V_3 -> V_144 ) ;
struct V_26 * V_22 = NULL ;
unsigned long V_19 ;
F_11 ( V_3 -> V_145 , V_19 ) ;
while ( V_23 -> V_22 != & V_3 -> V_144 ) {
V_22 = F_14 ( V_23 -> V_22 , struct V_26 , V_143 ) ;
if ( ! F_76 ( V_22 ) )
break;
V_22 = NULL ;
V_23 = V_23 -> V_22 ;
}
F_16 ( V_3 -> V_145 , V_19 ) ;
if ( V_141 )
F_80 ( V_141 ) ;
return V_22 ;
}
void F_83 ( struct V_75 * V_76 , void * V_146 ,
void (* F_84)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_85 ( V_76 -> V_27 . V_147 ) ;
struct V_26 * V_74 ;
F_86 (sdev, shost) {
if ( ( V_74 -> V_148 == V_76 -> V_148 ) &&
( V_74 -> V_149 == V_76 -> V_149 ) )
F_84 ( V_74 , V_146 ) ;
}
}
void F_87 ( struct V_75 * V_76 , void * V_146 ,
void (* F_84)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_85 ( V_76 -> V_27 . V_147 ) ;
struct V_26 * V_74 ;
F_88 (sdev, shost) {
if ( ( V_74 -> V_148 == V_76 -> V_148 ) &&
( V_74 -> V_149 == V_76 -> V_149 ) )
F_84 ( V_74 , V_146 ) ;
}
}
struct V_26 * F_89 ( struct V_75 * V_76 ,
T_4 V_150 )
{
struct V_26 * V_74 ;
F_90 (sdev, &starget->devices, same_target_siblings) {
if ( V_74 -> V_134 == V_135 )
continue;
if ( V_74 -> V_150 == V_150 )
return V_74 ;
}
return NULL ;
}
struct V_26 * F_91 ( struct V_75 * V_76 ,
T_4 V_150 )
{
struct V_26 * V_74 ;
struct V_2 * V_3 = F_85 ( V_76 -> V_27 . V_147 ) ;
unsigned long V_19 ;
F_11 ( V_3 -> V_145 , V_19 ) ;
V_74 = F_89 ( V_76 , V_150 ) ;
if ( V_74 && F_76 ( V_74 ) )
V_74 = NULL ;
F_16 ( V_3 -> V_145 , V_19 ) ;
return V_74 ;
}
struct V_26 * F_92 ( struct V_2 * V_3 ,
T_5 V_148 , T_5 V_149 , T_4 V_150 )
{
struct V_26 * V_74 ;
F_90 (sdev, &shost->__devices, siblings) {
if ( V_74 -> V_148 == V_148 && V_74 -> V_149 == V_149 &&
V_74 -> V_150 == V_150 )
return V_74 ;
}
return NULL ;
}
struct V_26 * F_93 ( struct V_2 * V_3 ,
T_5 V_148 , T_5 V_149 , T_4 V_150 )
{
struct V_26 * V_74 ;
unsigned long V_19 ;
F_11 ( V_3 -> V_145 , V_19 ) ;
V_74 = F_92 ( V_3 , V_148 , V_149 , V_150 ) ;
if ( V_74 && F_76 ( V_74 ) )
V_74 = NULL ;
F_16 ( V_3 -> V_145 , V_19 ) ;
return V_74 ;
}
static int T_6 F_94 ( void )
{
int error ;
error = F_95 () ;
if ( error )
return error ;
error = F_96 () ;
if ( error )
goto V_151;
error = F_97 () ;
if ( error )
goto V_152;
error = F_98 () ;
if ( error )
goto V_153;
error = F_99 () ;
if ( error )
goto V_154;
error = F_100 () ;
if ( error )
goto V_155;
F_101 () ;
F_102 ( V_156 L_11 ) ;
return 0 ;
V_155:
F_103 () ;
V_154:
F_104 () ;
V_153:
F_105 () ;
V_152:
F_106 () ;
V_151:
F_107 () ;
F_102 ( V_157 L_12 ,
- error ) ;
return error ;
}
static void T_7 F_108 ( void )
{
F_109 () ;
F_110 () ;
F_103 () ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_111 ( & V_158 ) ;
}
