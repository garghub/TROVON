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
static struct V_2 *
F_3 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_2 * V_6 ;
V_6 = F_4 ( V_4 -> V_7 , V_5 | V_4 -> V_5 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_8 = F_5 ( V_4 -> V_9 ,
V_5 | V_4 -> V_5 ) ;
if ( ! V_6 -> V_8 ) {
F_6 ( V_4 -> V_7 , V_6 ) ;
return NULL ;
}
return V_6 ;
}
static void
F_7 ( struct V_3 * V_4 ,
struct V_2 * V_6 )
{
if ( V_6 -> V_10 )
F_6 ( V_11 , V_6 -> V_10 ) ;
F_6 ( V_4 -> V_9 , V_6 -> V_8 ) ;
F_6 ( V_4 -> V_7 , V_6 ) ;
}
static struct V_2 *
F_8 ( struct V_12 * V_13 , T_1 V_5 )
{
struct V_2 * V_6 ;
V_6 = F_3 ( V_13 -> V_14 , V_5 ) ;
if ( ! V_6 )
return NULL ;
if ( F_9 ( V_13 ) >= V_15 ) {
V_6 -> V_10 = F_4 ( V_11 , V_5 ) ;
if ( ! V_6 -> V_10 ) {
F_7 ( V_13 -> V_14 , V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
struct V_2 * F_10 ( struct V_12 * V_13 , T_1 V_5 )
{
struct V_2 * V_6 = F_8 ( V_13 , V_5 ) ;
if ( F_11 ( ! V_6 ) ) {
unsigned long V_16 ;
F_12 ( & V_13 -> V_17 , V_16 ) ;
if ( F_13 ( ! F_14 ( & V_13 -> V_18 ) ) ) {
V_6 = F_15 ( V_13 -> V_18 . V_19 ,
struct V_2 , V_20 ) ;
F_16 ( & V_6 -> V_20 ) ;
}
F_17 ( & V_13 -> V_17 , V_16 ) ;
if ( V_6 ) {
void * V_21 , * V_22 ;
V_21 = V_6 -> V_8 ;
V_22 = V_6 -> V_10 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_8 = V_21 ;
V_6 -> V_10 = V_22 ;
}
}
return V_6 ;
}
struct V_2 * F_18 ( struct V_23 * V_24 , T_1 V_5 )
{
struct V_2 * V_6 ;
if ( ! F_19 ( & V_24 -> V_25 ) )
return NULL ;
V_6 = F_10 ( V_24 -> V_26 , V_5 ) ;
if ( F_13 ( V_6 != NULL ) ) {
unsigned long V_16 ;
V_6 -> V_27 = V_24 ;
F_20 ( & V_6 -> V_20 ) ;
F_12 ( & V_24 -> V_28 , V_16 ) ;
F_21 ( & V_6 -> V_20 , & V_24 -> V_29 ) ;
F_17 ( & V_24 -> V_28 , V_16 ) ;
V_6 -> V_30 = V_31 ;
} else
F_22 ( & V_24 -> V_25 ) ;
return V_6 ;
}
void F_23 ( struct V_12 * V_13 , struct V_2 * V_6 ,
struct V_27 * V_24 )
{
unsigned long V_16 ;
F_12 ( & V_13 -> V_17 , V_16 ) ;
if ( F_11 ( F_14 ( & V_13 -> V_18 ) ) ) {
F_24 ( & V_6 -> V_20 , & V_13 -> V_18 ) ;
V_6 = NULL ;
}
F_17 ( & V_13 -> V_17 , V_16 ) ;
if ( F_13 ( V_6 != NULL ) )
F_7 ( V_13 -> V_14 , V_6 ) ;
F_22 ( V_24 ) ;
}
void F_25 ( struct V_2 * V_6 )
{
struct V_23 * V_32 = V_6 -> V_27 ;
unsigned long V_16 ;
F_12 ( & V_6 -> V_27 -> V_28 , V_16 ) ;
F_26 ( F_14 ( & V_6 -> V_20 ) ) ;
F_16 ( & V_6 -> V_20 ) ;
F_17 ( & V_6 -> V_27 -> V_28 , V_16 ) ;
F_23 ( V_6 -> V_27 -> V_26 , V_6 , & V_32 -> V_25 ) ;
}
static struct V_3 * F_27 ( T_1 V_5 )
{
struct V_3 * V_33 = NULL , * V_4 ;
F_28 ( & V_34 ) ;
V_4 = ( V_5 & V_35 ) ? & V_36 :
& V_37 ;
if ( ! V_4 -> V_38 ) {
V_4 -> V_7 = F_29 ( V_4 -> V_39 ,
sizeof( struct V_2 ) , 0 ,
V_4 -> V_40 , NULL ) ;
if ( ! V_4 -> V_7 )
goto V_41;
V_4 -> V_9 = F_29 ( V_4 -> V_42 ,
V_43 , 0 ,
V_4 -> V_40 , NULL ) ;
if ( ! V_4 -> V_9 ) {
F_30 ( V_4 -> V_7 ) ;
goto V_41;
}
}
V_4 -> V_38 ++ ;
V_33 = V_4 ;
V_41:
F_31 ( & V_34 ) ;
return V_33 ;
}
static void F_32 ( T_1 V_5 )
{
struct V_3 * V_4 ;
F_28 ( & V_34 ) ;
V_4 = ( V_5 & V_35 ) ? & V_36 :
& V_37 ;
F_26 ( V_4 -> V_38 == 0 ) ;
if ( ! -- V_4 -> V_38 ) {
F_30 ( V_4 -> V_7 ) ;
F_30 ( V_4 -> V_9 ) ;
}
F_31 ( & V_34 ) ;
}
struct V_2 * F_33 ( T_1 V_5 )
{
struct V_3 * V_4 = F_27 ( V_5 ) ;
if ( ! V_4 )
return NULL ;
return F_3 ( V_4 , V_5 ) ;
}
void F_34 ( T_1 V_5 , struct V_2 * V_6 )
{
struct V_3 * V_4 = F_27 ( V_5 ) ;
F_26 ( ! V_4 ) ;
F_7 ( V_4 , V_6 ) ;
F_32 ( V_5 ) ;
F_32 ( V_5 ) ;
}
int F_35 ( struct V_12 * V_13 )
{
struct V_2 * V_6 ;
const T_1 V_5 = V_13 -> V_44 ? V_45 : V_46 ;
F_36 ( & V_13 -> V_17 ) ;
F_20 ( & V_13 -> V_18 ) ;
V_13 -> V_14 = F_27 ( V_5 ) ;
if ( ! V_13 -> V_14 )
return - V_47 ;
V_6 = F_8 ( V_13 , V_5 ) ;
if ( ! V_6 ) {
F_32 ( V_5 ) ;
V_13 -> V_14 = NULL ;
return - V_47 ;
}
F_24 ( & V_6 -> V_20 , & V_13 -> V_18 ) ;
return 0 ;
}
void F_37 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_14 )
return;
while ( ! F_14 ( & V_13 -> V_18 ) ) {
struct V_2 * V_6 ;
V_6 = F_15 ( V_13 -> V_18 . V_19 , struct V_2 , V_20 ) ;
F_16 ( & V_6 -> V_20 ) ;
F_7 ( V_13 -> V_14 , V_6 ) ;
}
V_13 -> V_14 = NULL ;
F_32 ( V_13 -> V_44 ? V_45 : V_46 ) ;
}
void F_38 ( struct V_2 * V_6 )
{
unsigned int V_48 ;
if ( F_11 ( V_49 ) ) {
V_48 = F_39 ( V_50 ,
V_51 ) ;
if ( V_48 > 1 ) {
F_40 ( V_52 , V_6 , L_4 ) ;
if ( V_48 > 2 )
F_41 ( L_5 , V_6 ) ;
F_41 ( L_6 ) ;
F_42 ( V_6 ) ;
if ( V_48 > 3 ) {
F_41 ( V_52 L_7
L_8 ,
F_43 ( V_6 ) , F_44 ( V_6 ) ,
V_6 -> V_27 -> V_26 -> V_53 -> V_54 ) ;
}
}
}
}
void F_45 ( struct V_2 * V_6 , int V_55 )
{
unsigned int V_48 ;
if ( F_11 ( V_49 ) ) {
V_48 = F_39 ( V_56 ,
V_57 ) ;
if ( ( ( V_48 > 0 ) && ( V_6 -> V_58 || V_55 != V_59 ) ) ||
( V_48 > 1 ) ) {
F_40 ( V_52 , V_6 , L_9 ) ;
if ( V_48 > 2 )
F_41 ( L_5 , V_6 ) ;
switch ( V_55 ) {
case V_59 :
F_41 ( L_10 ) ;
break;
case V_60 :
F_41 ( L_11 ) ;
break;
case V_61 :
F_41 ( L_12 ) ;
break;
case V_62 :
F_41 ( L_13 ) ;
break;
case V_63 :
F_41 ( L_14 ) ;
break;
default:
F_41 ( L_15 ) ;
}
F_46 ( V_6 ) ;
F_42 ( V_6 ) ;
if ( F_47 ( V_6 -> V_58 ) & V_64 )
F_48 ( L_16 , V_6 ) ;
if ( V_48 > 3 )
F_40 ( V_52 , V_6 ,
L_17 ,
V_6 -> V_27 -> V_26 -> V_65 ,
V_6 -> V_27 -> V_26 -> V_66 ) ;
}
}
}
void F_49 ( struct V_12 * V_26 , struct V_2 * V_6 )
{
V_6 -> V_67 = V_26 -> V_68 ++ ;
if ( V_6 -> V_67 == 0 )
V_6 -> V_67 = V_26 -> V_68 ++ ;
}
int F_50 ( struct V_2 * V_6 )
{
struct V_12 * V_26 = V_6 -> V_27 -> V_26 ;
int V_69 = 0 ;
F_51 ( & V_6 -> V_27 -> V_70 ) ;
if ( F_11 ( V_6 -> V_27 -> V_71 == V_72 ) ) {
V_6 -> V_58 = V_73 << 16 ;
F_52 ( V_6 ) ;
goto V_74;
}
if ( F_11 ( F_53 ( V_6 -> V_27 ) ) ) {
F_54 ( V_6 , V_75 ) ;
F_55 ( 3 , F_41 ( L_18 ) ) ;
goto V_74;
}
if ( V_6 -> V_27 -> V_76 <= V_77 &&
V_6 -> V_27 -> V_76 != V_78 ) {
V_6 -> V_79 [ 1 ] = ( V_6 -> V_79 [ 1 ] & 0x1f ) |
( V_6 -> V_27 -> V_80 << 5 & 0xe0 ) ;
}
F_38 ( V_6 ) ;
if ( V_6 -> V_81 > V_6 -> V_27 -> V_26 -> V_82 ) {
F_55 ( 3 ,
F_41 ( L_19
L_20 ,
V_6 -> V_81 , V_6 -> V_27 -> V_26 -> V_82 ) ) ;
V_6 -> V_58 = ( V_83 << 16 ) ;
F_52 ( V_6 ) ;
goto V_74;
}
if ( F_11 ( V_26 -> V_84 == V_85 ) ) {
V_6 -> V_58 = ( V_73 << 16 ) ;
F_52 ( V_6 ) ;
} else {
F_56 ( V_6 ) ;
V_6 -> F_52 = F_52 ;
V_69 = V_26 -> V_53 -> V_54 ( V_26 , V_6 ) ;
}
if ( V_69 ) {
F_57 ( V_6 , V_69 ) ;
if ( V_69 != V_75 &&
V_69 != V_86 )
V_69 = V_87 ;
F_54 ( V_6 , V_69 ) ;
F_55 ( 3 ,
F_41 ( L_21 ) ) ;
}
V_74:
F_55 ( 3 , F_41 ( L_22 ) ) ;
return V_69 ;
}
static void F_52 ( struct V_2 * V_6 )
{
F_58 ( V_6 ) ;
F_59 ( V_6 -> V_88 ) ;
}
void F_60 ( struct V_2 * V_6 )
{
struct V_23 * V_32 = V_6 -> V_27 ;
struct V_89 * V_90 = V_89 ( V_32 ) ;
struct V_12 * V_13 = V_32 -> V_26 ;
struct V_91 * V_92 ;
unsigned int V_93 ;
F_61 ( V_32 ) ;
V_13 -> V_94 = 0 ;
V_90 -> V_95 = 0 ;
V_32 -> V_96 = 0 ;
if ( F_62 ( V_6 ) )
V_6 -> V_58 |= ( V_97 << 24 ) ;
F_63 ( 4 , F_64 ( V_52 , V_32 ,
L_23
L_24 , V_6 -> V_58 ) ) ;
V_93 = F_44 ( V_6 ) ;
if ( V_6 -> V_88 -> V_98 != V_99 ) {
int V_100 = V_93 ;
V_92 = F_65 ( V_6 ) ;
if ( V_92 -> V_101 )
V_93 = V_92 -> V_101 ( V_6 ) ;
if ( V_93 == V_100 )
V_93 -= F_66 ( V_6 ) ;
}
F_67 ( V_6 , V_93 ) ;
}
void F_68 ( struct V_23 * V_32 , int V_102 , int V_103 )
{
unsigned long V_16 ;
if ( V_103 <= 0 )
return;
F_12 ( V_32 -> V_104 -> V_105 , V_16 ) ;
if ( ! V_32 -> V_26 -> V_106 ) {
if ( F_69 ( V_32 -> V_104 ) &&
F_70 ( V_32 -> V_104 , V_103 ) != 0 )
goto V_74;
}
V_32 -> V_107 = V_103 ;
switch ( V_102 ) {
case V_108 :
V_32 -> V_109 = 1 ;
V_32 -> V_110 = 1 ;
break;
case V_111 :
V_32 -> V_109 = 0 ;
V_32 -> V_110 = 1 ;
break;
default:
F_64 ( V_112 , V_32 ,
L_25
L_26 ) ;
case 0 :
V_32 -> V_109 = V_32 -> V_110 = 0 ;
V_32 -> V_107 = V_103 ;
break;
}
V_74:
F_17 ( V_32 -> V_104 -> V_105 , V_16 ) ;
}
int F_71 ( struct V_23 * V_32 , int V_113 )
{
if ( ( V_31 >> 4 ) == ( V_32 -> V_114 >> 4 ) )
return 0 ;
V_32 -> V_114 = V_31 ;
if ( V_32 -> V_115 != V_113 ) {
V_32 -> V_116 = 1 ;
V_32 -> V_115 = V_113 ;
} else {
V_32 -> V_116 ++ ;
}
if ( V_32 -> V_116 <= 10 )
return 0 ;
if ( V_32 -> V_115 < 8 ) {
F_68 ( V_32 , 0 , V_32 -> V_26 -> V_117 ) ;
return - 1 ;
}
if ( V_32 -> V_109 )
F_68 ( V_32 , V_108 , V_113 ) ;
else
F_68 ( V_32 , V_111 , V_113 ) ;
return V_113 ;
}
static int F_72 ( struct V_23 * V_32 , unsigned char * V_118 ,
T_2 V_119 , unsigned V_120 )
{
int V_58 ;
unsigned char V_6 [ 16 ] ;
V_6 [ 0 ] = V_121 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_119 ;
V_6 [ 3 ] = V_120 >> 8 ;
V_6 [ 4 ] = V_120 & 0xff ;
V_6 [ 5 ] = 0 ;
V_58 = F_73 ( V_32 , V_6 , V_122 , V_118 ,
V_120 , NULL , 30 * V_123 , 3 , NULL ) ;
if ( V_58 )
return V_58 ;
if ( V_118 [ 1 ] != V_119 )
return - V_124 ;
return 0 ;
}
int F_74 ( struct V_23 * V_32 , T_2 V_119 , unsigned char * V_21 ,
int V_125 )
{
int V_126 , V_58 ;
if ( V_32 -> V_127 )
goto V_41;
V_58 = F_72 ( V_32 , V_21 , 0 , V_125 ) ;
if ( V_58 )
goto V_41;
if ( V_119 == 0 )
return 0 ;
for ( V_126 = 0 ; V_126 < F_75 ( ( int ) V_21 [ 3 ] , V_125 - 4 ) ; V_126 ++ )
if ( V_21 [ V_126 + 4 ] == V_119 )
goto V_128;
if ( V_126 < V_21 [ 3 ] && V_126 >= V_125 - 4 )
goto V_128;
goto V_41;
V_128:
V_58 = F_72 ( V_32 , V_21 , V_119 , V_125 ) ;
if ( V_58 )
goto V_41;
return 0 ;
V_41:
return - V_129 ;
}
int F_76 ( struct V_23 * V_32 , unsigned char * V_118 ,
unsigned int V_120 , unsigned char V_130 )
{
unsigned char V_6 [ 16 ] ;
struct V_131 V_132 ;
int V_58 ;
if ( V_32 -> V_133 || V_32 -> V_76 < V_134 )
return - V_129 ;
memset ( V_6 , 0 , 16 ) ;
V_6 [ 0 ] = V_135 ;
V_6 [ 1 ] = V_136 ;
V_6 [ 2 ] = 1 ;
V_6 [ 3 ] = V_130 ;
F_77 ( V_120 , & V_6 [ 6 ] ) ;
memset ( V_118 , 0 , V_120 ) ;
V_58 = F_73 ( V_32 , V_6 , V_122 , V_118 , V_120 ,
& V_132 , 30 * V_123 , 3 , NULL ) ;
if ( V_58 && F_78 ( & V_132 ) &&
V_132 . V_137 == V_138 &&
( V_132 . V_139 == 0x20 || V_132 . V_139 == 0x24 ) && V_132 . V_140 == 0x00 )
return - V_129 ;
if ( ( V_118 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_79 ( struct V_23 * V_32 )
{
if ( V_32 -> V_71 == V_72 )
return - V_141 ;
if ( ! F_19 ( & V_32 -> V_25 ) )
return - V_141 ;
F_80 ( V_32 -> V_26 -> V_53 -> V_142 ) ;
return 0 ;
}
void F_81 ( struct V_23 * V_32 )
{
#ifdef F_82
struct V_142 * V_142 = V_32 -> V_26 -> V_53 -> V_142 ;
if ( V_142 && F_83 ( V_142 ) != 0 )
F_84 ( V_142 ) ;
#endif
F_22 ( & V_32 -> V_25 ) ;
}
struct V_23 * F_85 ( struct V_12 * V_13 ,
struct V_23 * V_143 )
{
struct V_144 * V_20 = ( V_143 ? & V_143 -> V_145 : & V_13 -> V_146 ) ;
struct V_23 * V_19 = NULL ;
unsigned long V_16 ;
F_12 ( V_13 -> V_147 , V_16 ) ;
while ( V_20 -> V_19 != & V_13 -> V_146 ) {
V_19 = F_15 ( V_20 -> V_19 , struct V_23 , V_145 ) ;
if ( ! F_79 ( V_19 ) )
break;
V_19 = NULL ;
V_20 = V_20 -> V_19 ;
}
F_17 ( V_13 -> V_147 , V_16 ) ;
if ( V_143 )
F_81 ( V_143 ) ;
return V_19 ;
}
void F_86 ( struct V_89 * V_90 , void * V_148 ,
void (* F_87)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_88 ( V_90 -> V_24 . V_149 ) ;
struct V_23 * V_32 ;
F_89 (sdev, shost) {
if ( ( V_32 -> V_150 == V_90 -> V_150 ) &&
( V_32 -> V_151 == V_90 -> V_151 ) )
F_87 ( V_32 , V_148 ) ;
}
}
void F_90 ( struct V_89 * V_90 , void * V_148 ,
void (* F_87)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_88 ( V_90 -> V_24 . V_149 ) ;
struct V_23 * V_32 ;
F_91 (sdev, shost) {
if ( ( V_32 -> V_150 == V_90 -> V_150 ) &&
( V_32 -> V_151 == V_90 -> V_151 ) )
F_87 ( V_32 , V_148 ) ;
}
}
struct V_23 * F_92 ( struct V_89 * V_90 ,
T_3 V_80 )
{
struct V_23 * V_32 ;
F_93 (sdev, &starget->devices, same_target_siblings) {
if ( V_32 -> V_71 == V_72 )
continue;
if ( V_32 -> V_80 == V_80 )
return V_32 ;
}
return NULL ;
}
struct V_23 * F_94 ( struct V_89 * V_90 ,
T_3 V_80 )
{
struct V_23 * V_32 ;
struct V_12 * V_13 = F_88 ( V_90 -> V_24 . V_149 ) ;
unsigned long V_16 ;
F_12 ( V_13 -> V_147 , V_16 ) ;
V_32 = F_92 ( V_90 , V_80 ) ;
if ( V_32 && F_79 ( V_32 ) )
V_32 = NULL ;
F_17 ( V_13 -> V_147 , V_16 ) ;
return V_32 ;
}
struct V_23 * F_95 ( struct V_12 * V_13 ,
T_3 V_150 , T_3 V_151 , T_3 V_80 )
{
struct V_23 * V_32 ;
F_93 (sdev, &shost->__devices, siblings) {
if ( V_32 -> V_150 == V_150 && V_32 -> V_151 == V_151 &&
V_32 -> V_80 == V_80 )
return V_32 ;
}
return NULL ;
}
struct V_23 * F_96 ( struct V_12 * V_13 ,
T_3 V_150 , T_3 V_151 , T_3 V_80 )
{
struct V_23 * V_32 ;
unsigned long V_16 ;
F_12 ( V_13 -> V_147 , V_16 ) ;
V_32 = F_95 ( V_13 , V_150 , V_151 , V_80 ) ;
if ( V_32 && F_79 ( V_32 ) )
V_32 = NULL ;
F_17 ( V_13 -> V_147 , V_16 ) ;
return V_32 ;
}
static int T_4 F_97 ( void )
{
int error ;
error = F_98 () ;
if ( error )
return error ;
error = F_99 () ;
if ( error )
goto V_152;
error = F_100 () ;
if ( error )
goto V_153;
error = F_101 () ;
if ( error )
goto V_154;
error = F_102 () ;
if ( error )
goto V_155;
error = F_103 () ;
if ( error )
goto V_156;
F_104 () ;
F_41 ( V_157 L_27 ) ;
return 0 ;
V_156:
F_105 () ;
V_155:
F_106 () ;
V_154:
F_107 () ;
V_153:
F_108 () ;
V_152:
F_109 () ;
F_41 ( V_158 L_28 ,
- error ) ;
return error ;
}
static void T_5 F_110 ( void )
{
F_111 () ;
F_112 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_113 ( & V_159 ) ;
}
