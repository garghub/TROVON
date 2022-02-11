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
unsigned long V_69 ;
int V_70 = 0 ;
F_51 ( & V_6 -> V_27 -> V_71 ) ;
if ( F_11 ( V_6 -> V_27 -> V_72 == V_73 ) ) {
V_6 -> V_58 = V_74 << 16 ;
F_52 ( V_6 ) ;
goto V_75;
}
if ( F_11 ( F_53 ( V_6 -> V_27 ) ) ) {
F_54 ( V_6 , V_76 ) ;
F_55 ( 3 , F_41 ( L_18 ) ) ;
goto V_75;
}
if ( V_6 -> V_27 -> V_77 <= V_78 &&
V_6 -> V_27 -> V_77 != V_79 ) {
V_6 -> V_80 [ 1 ] = ( V_6 -> V_80 [ 1 ] & 0x1f ) |
( V_6 -> V_27 -> V_81 << 5 & 0xe0 ) ;
}
V_69 = V_26 -> V_82 + V_83 ;
if ( V_26 -> V_84 && F_56 ( V_31 , V_69 ) ) {
int V_85 = V_69 - V_31 ;
while ( -- V_85 >= 0 )
F_57 ( 1 + 999 / V_86 ) ;
V_26 -> V_84 = 0 ;
}
F_38 ( V_6 ) ;
if ( V_6 -> V_87 > V_6 -> V_27 -> V_26 -> V_88 ) {
F_55 ( 3 ,
F_41 ( L_19
L_20 ,
V_6 -> V_87 , V_6 -> V_27 -> V_26 -> V_88 ) ) ;
V_6 -> V_58 = ( V_89 << 16 ) ;
F_52 ( V_6 ) ;
goto V_75;
}
if ( F_11 ( V_26 -> V_90 == V_91 ) ) {
V_6 -> V_58 = ( V_74 << 16 ) ;
F_52 ( V_6 ) ;
} else {
F_58 ( V_6 ) ;
V_6 -> F_52 = F_52 ;
V_70 = V_26 -> V_53 -> V_54 ( V_26 , V_6 ) ;
}
if ( V_70 ) {
F_59 ( V_6 , V_70 ) ;
if ( V_70 != V_76 &&
V_70 != V_92 )
V_70 = V_93 ;
F_54 ( V_6 , V_70 ) ;
F_55 ( 3 ,
F_41 ( L_21 ) ) ;
}
V_75:
F_55 ( 3 , F_41 ( L_22 ) ) ;
return V_70 ;
}
static void F_52 ( struct V_2 * V_6 )
{
F_60 ( V_6 ) ;
F_61 ( V_6 -> V_94 ) ;
}
void F_62 ( struct V_2 * V_6 )
{
struct V_23 * V_32 = V_6 -> V_27 ;
struct V_95 * V_96 = V_95 ( V_32 ) ;
struct V_12 * V_13 = V_32 -> V_26 ;
struct V_97 * V_98 ;
unsigned int V_99 ;
F_63 ( V_32 ) ;
V_13 -> V_100 = 0 ;
V_96 -> V_101 = 0 ;
V_32 -> V_102 = 0 ;
if ( F_64 ( V_6 ) )
V_6 -> V_58 |= ( V_103 << 24 ) ;
F_65 ( 4 , F_66 ( V_52 , V_32 ,
L_23
L_24 , V_6 -> V_58 ) ) ;
V_99 = F_44 ( V_6 ) ;
if ( V_6 -> V_94 -> V_104 != V_105 ) {
int V_106 = V_99 ;
V_98 = F_67 ( V_6 ) ;
if ( V_98 -> V_107 )
V_99 = V_98 -> V_107 ( V_6 ) ;
if ( V_99 == V_106 )
V_99 -= F_68 ( V_6 ) ;
}
F_69 ( V_6 , V_99 ) ;
}
void F_70 ( struct V_23 * V_32 , int V_108 , int V_109 )
{
unsigned long V_16 ;
if ( V_109 <= 0 )
return;
F_12 ( V_32 -> V_110 -> V_111 , V_16 ) ;
if ( ! V_32 -> V_26 -> V_112 ) {
if ( F_71 ( V_32 -> V_110 ) &&
F_72 ( V_32 -> V_110 , V_109 ) != 0 )
goto V_75;
}
V_32 -> V_113 = V_109 ;
switch ( V_108 ) {
case V_114 :
V_32 -> V_115 = 1 ;
V_32 -> V_116 = 1 ;
break;
case V_117 :
V_32 -> V_115 = 0 ;
V_32 -> V_116 = 1 ;
break;
default:
F_66 ( V_118 , V_32 ,
L_25
L_26 ) ;
case 0 :
V_32 -> V_115 = V_32 -> V_116 = 0 ;
V_32 -> V_113 = V_109 ;
break;
}
V_75:
F_17 ( V_32 -> V_110 -> V_111 , V_16 ) ;
}
int F_73 ( struct V_23 * V_32 , int V_119 )
{
if ( ( V_31 >> 4 ) == ( V_32 -> V_120 >> 4 ) )
return 0 ;
V_32 -> V_120 = V_31 ;
if ( V_32 -> V_121 != V_119 ) {
V_32 -> V_122 = 1 ;
V_32 -> V_121 = V_119 ;
} else {
V_32 -> V_122 ++ ;
}
if ( V_32 -> V_122 <= 10 )
return 0 ;
if ( V_32 -> V_121 < 8 ) {
F_70 ( V_32 , 0 , V_32 -> V_26 -> V_123 ) ;
return - 1 ;
}
if ( V_32 -> V_115 )
F_70 ( V_32 , V_114 , V_119 ) ;
else
F_70 ( V_32 , V_117 , V_119 ) ;
return V_119 ;
}
static int F_74 ( struct V_23 * V_32 , unsigned char * V_124 ,
T_2 V_125 , unsigned V_126 )
{
int V_58 ;
unsigned char V_6 [ 16 ] ;
V_6 [ 0 ] = V_127 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_125 ;
V_6 [ 3 ] = V_126 >> 8 ;
V_6 [ 4 ] = V_126 & 0xff ;
V_6 [ 5 ] = 0 ;
V_58 = F_75 ( V_32 , V_6 , V_128 , V_124 ,
V_126 , NULL , 30 * V_86 , 3 , NULL ) ;
if ( V_58 )
return V_58 ;
if ( V_124 [ 1 ] != V_125 )
return - V_129 ;
return 0 ;
}
int F_76 ( struct V_23 * V_32 , T_2 V_125 , unsigned char * V_21 ,
int V_130 )
{
int V_131 , V_58 ;
V_58 = F_74 ( V_32 , V_21 , 0 , V_130 ) ;
if ( V_58 )
goto V_41;
if ( V_125 == 0 )
return 0 ;
for ( V_131 = 0 ; V_131 < F_77 ( ( int ) V_21 [ 3 ] , V_130 - 4 ) ; V_131 ++ )
if ( V_21 [ V_131 + 4 ] == V_125 )
goto V_132;
if ( V_131 < V_21 [ 3 ] && V_131 >= V_130 - 4 )
goto V_132;
goto V_41;
V_132:
V_58 = F_74 ( V_32 , V_21 , V_125 , V_130 ) ;
if ( V_58 )
goto V_41;
return 0 ;
V_41:
return - V_133 ;
}
int F_78 ( struct V_23 * V_32 , unsigned char * V_124 ,
unsigned int V_126 , unsigned char V_134 )
{
unsigned char V_6 [ 16 ] ;
struct V_135 V_136 ;
int V_58 ;
if ( V_32 -> V_137 || V_32 -> V_77 < V_138 )
return 0 ;
memset ( V_6 , 0 , 16 ) ;
V_6 [ 0 ] = V_139 ;
V_6 [ 1 ] = V_140 ;
V_6 [ 2 ] = 1 ;
V_6 [ 3 ] = V_134 ;
F_79 ( V_126 , & V_6 [ 6 ] ) ;
memset ( V_124 , 0 , V_126 ) ;
V_58 = F_75 ( V_32 , V_6 , V_128 , V_124 , V_126 ,
& V_136 , 30 * V_86 , 3 , NULL ) ;
if ( V_58 && F_80 ( & V_136 ) &&
V_136 . V_141 == V_142 &&
( V_136 . V_143 == 0x20 || V_136 . V_143 == 0x24 ) && V_136 . V_144 == 0x00 )
return 0 ;
if ( ( V_124 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_81 ( struct V_23 * V_32 )
{
if ( V_32 -> V_72 == V_73 )
return - V_145 ;
if ( ! F_19 ( & V_32 -> V_25 ) )
return - V_145 ;
F_82 ( V_32 -> V_26 -> V_53 -> V_146 ) ;
return 0 ;
}
void F_83 ( struct V_23 * V_32 )
{
#ifdef F_84
struct V_146 * V_146 = V_32 -> V_26 -> V_53 -> V_146 ;
if ( V_146 && F_85 ( V_146 ) != 0 )
F_86 ( V_146 ) ;
#endif
F_22 ( & V_32 -> V_25 ) ;
}
struct V_23 * F_87 ( struct V_12 * V_13 ,
struct V_23 * V_147 )
{
struct V_148 * V_20 = ( V_147 ? & V_147 -> V_149 : & V_13 -> V_150 ) ;
struct V_23 * V_19 = NULL ;
unsigned long V_16 ;
F_12 ( V_13 -> V_151 , V_16 ) ;
while ( V_20 -> V_19 != & V_13 -> V_150 ) {
V_19 = F_15 ( V_20 -> V_19 , struct V_23 , V_149 ) ;
if ( ! F_81 ( V_19 ) )
break;
V_19 = NULL ;
V_20 = V_20 -> V_19 ;
}
F_17 ( V_13 -> V_151 , V_16 ) ;
if ( V_147 )
F_83 ( V_147 ) ;
return V_19 ;
}
void F_88 ( struct V_95 * V_96 , void * V_152 ,
void (* F_89)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_90 ( V_96 -> V_24 . V_153 ) ;
struct V_23 * V_32 ;
F_91 (sdev, shost) {
if ( ( V_32 -> V_154 == V_96 -> V_154 ) &&
( V_32 -> V_155 == V_96 -> V_155 ) )
F_89 ( V_32 , V_152 ) ;
}
}
void F_92 ( struct V_95 * V_96 , void * V_152 ,
void (* F_89)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_90 ( V_96 -> V_24 . V_153 ) ;
struct V_23 * V_32 ;
F_93 (sdev, shost) {
if ( ( V_32 -> V_154 == V_96 -> V_154 ) &&
( V_32 -> V_155 == V_96 -> V_155 ) )
F_89 ( V_32 , V_152 ) ;
}
}
struct V_23 * F_94 ( struct V_95 * V_96 ,
T_3 V_81 )
{
struct V_23 * V_32 ;
F_95 (sdev, &starget->devices, same_target_siblings) {
if ( V_32 -> V_72 == V_73 )
continue;
if ( V_32 -> V_81 == V_81 )
return V_32 ;
}
return NULL ;
}
struct V_23 * F_96 ( struct V_95 * V_96 ,
T_3 V_81 )
{
struct V_23 * V_32 ;
struct V_12 * V_13 = F_90 ( V_96 -> V_24 . V_153 ) ;
unsigned long V_16 ;
F_12 ( V_13 -> V_151 , V_16 ) ;
V_32 = F_94 ( V_96 , V_81 ) ;
if ( V_32 && F_81 ( V_32 ) )
V_32 = NULL ;
F_17 ( V_13 -> V_151 , V_16 ) ;
return V_32 ;
}
struct V_23 * F_97 ( struct V_12 * V_13 ,
T_3 V_154 , T_3 V_155 , T_3 V_81 )
{
struct V_23 * V_32 ;
F_95 (sdev, &shost->__devices, siblings) {
if ( V_32 -> V_154 == V_154 && V_32 -> V_155 == V_155 &&
V_32 -> V_81 == V_81 )
return V_32 ;
}
return NULL ;
}
struct V_23 * F_98 ( struct V_12 * V_13 ,
T_3 V_154 , T_3 V_155 , T_3 V_81 )
{
struct V_23 * V_32 ;
unsigned long V_16 ;
F_12 ( V_13 -> V_151 , V_16 ) ;
V_32 = F_97 ( V_13 , V_154 , V_155 , V_81 ) ;
if ( V_32 && F_81 ( V_32 ) )
V_32 = NULL ;
F_17 ( V_13 -> V_151 , V_16 ) ;
return V_32 ;
}
static int T_4 F_99 ( void )
{
int error ;
error = F_100 () ;
if ( error )
return error ;
error = F_101 () ;
if ( error )
goto V_156;
error = F_102 () ;
if ( error )
goto V_157;
error = F_103 () ;
if ( error )
goto V_158;
error = F_104 () ;
if ( error )
goto V_159;
error = F_105 () ;
if ( error )
goto V_160;
F_106 () ;
F_41 ( V_161 L_27 ) ;
return 0 ;
V_160:
F_107 () ;
V_159:
F_108 () ;
V_158:
F_109 () ;
V_157:
F_110 () ;
V_156:
F_111 () ;
F_41 ( V_162 L_28 ,
- error ) ;
return error ;
}
static void T_5 F_112 ( void )
{
F_113 () ;
F_114 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_110 () ;
F_111 () ;
F_115 ( & V_163 ) ;
}
