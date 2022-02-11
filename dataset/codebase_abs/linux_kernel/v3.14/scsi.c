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
F_21 ( & V_6 -> V_28 , V_29 ) ;
F_12 ( & V_24 -> V_30 , V_16 ) ;
F_22 ( & V_6 -> V_20 , & V_24 -> V_31 ) ;
F_17 ( & V_24 -> V_30 , V_16 ) ;
V_6 -> V_32 = V_33 ;
} else
F_23 ( & V_24 -> V_25 ) ;
return V_6 ;
}
void F_24 ( struct V_12 * V_13 , struct V_2 * V_6 ,
struct V_27 * V_24 )
{
unsigned long V_16 ;
F_12 ( & V_13 -> V_17 , V_16 ) ;
if ( F_11 ( F_14 ( & V_13 -> V_18 ) ) ) {
F_25 ( & V_6 -> V_20 , & V_13 -> V_18 ) ;
V_6 = NULL ;
}
F_17 ( & V_13 -> V_17 , V_16 ) ;
if ( F_13 ( V_6 != NULL ) )
F_7 ( V_13 -> V_14 , V_6 ) ;
F_23 ( V_24 ) ;
}
void F_26 ( struct V_2 * V_6 )
{
struct V_23 * V_34 = V_6 -> V_27 ;
unsigned long V_16 ;
F_12 ( & V_6 -> V_27 -> V_30 , V_16 ) ;
F_27 ( F_14 ( & V_6 -> V_20 ) ) ;
F_16 ( & V_6 -> V_20 ) ;
F_17 ( & V_6 -> V_27 -> V_30 , V_16 ) ;
F_28 ( & V_6 -> V_28 ) ;
F_24 ( V_6 -> V_27 -> V_26 , V_6 , & V_34 -> V_25 ) ;
}
static struct V_3 * F_29 ( T_1 V_5 )
{
struct V_3 * V_35 = NULL , * V_4 ;
F_30 ( & V_36 ) ;
V_4 = ( V_5 & V_37 ) ? & V_38 :
& V_39 ;
if ( ! V_4 -> V_40 ) {
V_4 -> V_7 = F_31 ( V_4 -> V_41 ,
sizeof( struct V_2 ) , 0 ,
V_4 -> V_42 , NULL ) ;
if ( ! V_4 -> V_7 )
goto V_43;
V_4 -> V_9 = F_31 ( V_4 -> V_44 ,
V_45 , 0 ,
V_4 -> V_42 , NULL ) ;
if ( ! V_4 -> V_9 ) {
F_32 ( V_4 -> V_7 ) ;
goto V_43;
}
}
V_4 -> V_40 ++ ;
V_35 = V_4 ;
V_43:
F_33 ( & V_36 ) ;
return V_35 ;
}
static void F_34 ( T_1 V_5 )
{
struct V_3 * V_4 ;
F_30 ( & V_36 ) ;
V_4 = ( V_5 & V_37 ) ? & V_38 :
& V_39 ;
F_27 ( V_4 -> V_40 == 0 ) ;
if ( ! -- V_4 -> V_40 ) {
F_32 ( V_4 -> V_7 ) ;
F_32 ( V_4 -> V_9 ) ;
}
F_33 ( & V_36 ) ;
}
struct V_2 * F_35 ( T_1 V_5 )
{
struct V_3 * V_4 = F_29 ( V_5 ) ;
if ( ! V_4 )
return NULL ;
return F_3 ( V_4 , V_5 ) ;
}
void F_36 ( T_1 V_5 , struct V_2 * V_6 )
{
struct V_3 * V_4 = F_29 ( V_5 ) ;
F_27 ( ! V_4 ) ;
F_7 ( V_4 , V_6 ) ;
F_34 ( V_5 ) ;
F_34 ( V_5 ) ;
}
int F_37 ( struct V_12 * V_13 )
{
struct V_2 * V_6 ;
const T_1 V_5 = V_13 -> V_46 ? V_47 : V_48 ;
F_38 ( & V_13 -> V_17 ) ;
F_20 ( & V_13 -> V_18 ) ;
V_13 -> V_14 = F_29 ( V_5 ) ;
if ( ! V_13 -> V_14 )
return - V_49 ;
V_6 = F_8 ( V_13 , V_5 ) ;
if ( ! V_6 ) {
F_34 ( V_5 ) ;
V_13 -> V_14 = NULL ;
return - V_49 ;
}
F_25 ( & V_6 -> V_20 , & V_13 -> V_18 ) ;
return 0 ;
}
void F_39 ( struct V_12 * V_13 )
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
F_34 ( V_13 -> V_46 ? V_47 : V_48 ) ;
}
void F_40 ( struct V_2 * V_6 )
{
unsigned int V_50 ;
if ( F_11 ( V_51 ) ) {
V_50 = F_41 ( V_52 ,
V_53 ) ;
if ( V_50 > 1 ) {
F_42 ( V_54 , V_6 , L_4 ) ;
if ( V_50 > 2 )
F_43 ( L_5 , V_6 ) ;
F_43 ( L_6 ) ;
F_44 ( V_6 ) ;
if ( V_50 > 3 ) {
F_43 ( V_54 L_7
L_8 ,
F_45 ( V_6 ) , F_46 ( V_6 ) ,
V_6 -> V_27 -> V_26 -> V_55 -> V_56 ) ;
}
}
}
}
void F_47 ( struct V_2 * V_6 , int V_57 )
{
unsigned int V_50 ;
if ( F_11 ( V_51 ) ) {
V_50 = F_41 ( V_58 ,
V_59 ) ;
if ( ( ( V_50 > 0 ) && ( V_6 -> V_60 || V_57 != V_61 ) ) ||
( V_50 > 1 ) ) {
F_42 ( V_54 , V_6 , L_9 ) ;
if ( V_50 > 2 )
F_43 ( L_5 , V_6 ) ;
switch ( V_57 ) {
case V_61 :
F_43 ( L_10 ) ;
break;
case V_62 :
F_43 ( L_11 ) ;
break;
case V_63 :
F_43 ( L_12 ) ;
break;
case V_64 :
F_43 ( L_13 ) ;
break;
case V_65 :
F_43 ( L_14 ) ;
break;
default:
F_43 ( L_15 ) ;
}
F_48 ( V_6 ) ;
F_44 ( V_6 ) ;
if ( F_49 ( V_6 -> V_60 ) & V_66 )
F_50 ( L_16 , V_6 ) ;
if ( V_50 > 3 )
F_42 ( V_54 , V_6 ,
L_17 ,
V_6 -> V_27 -> V_26 -> V_67 ,
V_6 -> V_27 -> V_26 -> V_68 ) ;
}
}
}
void F_51 ( struct V_12 * V_26 , struct V_2 * V_6 )
{
V_6 -> V_69 = V_26 -> V_70 ++ ;
if ( V_6 -> V_69 == 0 )
V_6 -> V_69 = V_26 -> V_70 ++ ;
}
int F_52 ( struct V_2 * V_6 )
{
struct V_12 * V_26 = V_6 -> V_27 -> V_26 ;
int V_71 = 0 ;
F_53 ( & V_6 -> V_27 -> V_72 ) ;
if ( F_11 ( V_6 -> V_27 -> V_73 == V_74 ) ) {
V_6 -> V_60 = V_75 << 16 ;
F_54 ( V_6 ) ;
goto V_76;
}
if ( F_11 ( F_55 ( V_6 -> V_27 ) ) ) {
F_56 ( V_6 , V_77 ) ;
F_57 ( 3 , F_43 ( L_18 ) ) ;
goto V_76;
}
if ( V_6 -> V_27 -> V_78 <= V_79 &&
V_6 -> V_27 -> V_78 != V_80 ) {
V_6 -> V_81 [ 1 ] = ( V_6 -> V_81 [ 1 ] & 0x1f ) |
( V_6 -> V_27 -> V_82 << 5 & 0xe0 ) ;
}
F_40 ( V_6 ) ;
if ( V_6 -> V_83 > V_6 -> V_27 -> V_26 -> V_84 ) {
F_57 ( 3 ,
F_43 ( L_19
L_20 ,
V_6 -> V_83 , V_6 -> V_27 -> V_26 -> V_84 ) ) ;
V_6 -> V_60 = ( V_85 << 16 ) ;
F_54 ( V_6 ) ;
goto V_76;
}
if ( F_11 ( V_26 -> V_86 == V_87 ) ) {
V_6 -> V_60 = ( V_75 << 16 ) ;
F_54 ( V_6 ) ;
} else {
F_58 ( V_6 ) ;
V_6 -> F_54 = F_54 ;
V_71 = V_26 -> V_55 -> V_56 ( V_26 , V_6 ) ;
}
if ( V_71 ) {
F_59 ( V_6 , V_71 ) ;
if ( V_71 != V_77 &&
V_71 != V_88 )
V_71 = V_89 ;
F_56 ( V_6 , V_71 ) ;
F_57 ( 3 ,
F_43 ( L_21 ) ) ;
}
V_76:
F_57 ( 3 , F_43 ( L_22 ) ) ;
return V_71 ;
}
static void F_54 ( struct V_2 * V_6 )
{
F_60 ( V_6 ) ;
F_61 ( V_6 -> V_90 ) ;
}
void F_62 ( struct V_2 * V_6 )
{
struct V_23 * V_34 = V_6 -> V_27 ;
struct V_91 * V_92 = V_91 ( V_34 ) ;
struct V_12 * V_13 = V_34 -> V_26 ;
struct V_93 * V_94 ;
unsigned int V_95 ;
F_63 ( V_34 ) ;
V_13 -> V_96 = 0 ;
V_92 -> V_97 = 0 ;
V_34 -> V_98 = 0 ;
if ( F_64 ( V_6 ) )
V_6 -> V_60 |= ( V_99 << 24 ) ;
F_65 ( 4 , F_66 ( V_54 , V_34 ,
L_23
L_24 , V_6 -> V_60 ) ) ;
V_95 = F_46 ( V_6 ) ;
if ( V_6 -> V_90 -> V_100 != V_101 ) {
int V_102 = V_95 ;
V_94 = F_67 ( V_6 ) ;
if ( V_94 -> V_103 )
V_95 = V_94 -> V_103 ( V_6 ) ;
if ( V_95 == V_102 )
V_95 -= F_68 ( V_6 ) ;
}
F_69 ( V_6 , V_95 ) ;
}
void F_70 ( struct V_23 * V_34 , int V_104 , int V_105 )
{
unsigned long V_16 ;
if ( V_105 <= 0 )
return;
F_12 ( V_34 -> V_106 -> V_107 , V_16 ) ;
if ( ! V_34 -> V_26 -> V_108 ) {
if ( F_71 ( V_34 -> V_106 ) &&
F_72 ( V_34 -> V_106 , V_105 ) != 0 )
goto V_76;
}
V_34 -> V_109 = V_105 ;
switch ( V_104 ) {
case V_110 :
V_34 -> V_111 = 1 ;
V_34 -> V_112 = 1 ;
break;
case V_113 :
V_34 -> V_111 = 0 ;
V_34 -> V_112 = 1 ;
break;
default:
F_66 ( V_114 , V_34 ,
L_25
L_26 ) ;
case 0 :
V_34 -> V_111 = V_34 -> V_112 = 0 ;
V_34 -> V_109 = V_105 ;
break;
}
V_76:
F_17 ( V_34 -> V_106 -> V_107 , V_16 ) ;
}
int F_73 ( struct V_23 * V_34 , int V_115 )
{
if ( ( V_33 >> 4 ) == ( V_34 -> V_116 >> 4 ) )
return 0 ;
V_34 -> V_116 = V_33 ;
if ( V_34 -> V_117 != V_115 ) {
V_34 -> V_118 = 1 ;
V_34 -> V_117 = V_115 ;
} else {
V_34 -> V_118 ++ ;
}
if ( V_34 -> V_118 <= 10 )
return 0 ;
if ( V_34 -> V_117 < 8 ) {
F_70 ( V_34 , 0 , V_34 -> V_26 -> V_119 ) ;
return - 1 ;
}
if ( V_34 -> V_111 )
F_70 ( V_34 , V_110 , V_115 ) ;
else
F_70 ( V_34 , V_113 , V_115 ) ;
return V_115 ;
}
static int F_74 ( struct V_23 * V_34 , unsigned char * V_120 ,
T_2 V_121 , unsigned V_122 )
{
int V_60 ;
unsigned char V_6 [ 16 ] ;
V_6 [ 0 ] = V_123 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_121 ;
V_6 [ 3 ] = V_122 >> 8 ;
V_6 [ 4 ] = V_122 & 0xff ;
V_6 [ 5 ] = 0 ;
V_60 = F_75 ( V_34 , V_6 , V_124 , V_120 ,
V_122 , NULL , 30 * V_125 , 3 , NULL ) ;
if ( V_60 )
return V_60 ;
if ( V_120 [ 1 ] != V_121 )
return - V_126 ;
return 0 ;
}
int F_76 ( struct V_23 * V_34 , T_2 V_121 , unsigned char * V_21 ,
int V_127 )
{
int V_128 , V_60 ;
if ( V_34 -> V_129 )
goto V_43;
V_60 = F_74 ( V_34 , V_21 , 0 , V_127 ) ;
if ( V_60 )
goto V_43;
if ( V_121 == 0 )
return 0 ;
for ( V_128 = 0 ; V_128 < F_77 ( ( int ) V_21 [ 3 ] , V_127 - 4 ) ; V_128 ++ )
if ( V_21 [ V_128 + 4 ] == V_121 )
goto V_130;
if ( V_128 < V_21 [ 3 ] && V_128 >= V_127 - 4 )
goto V_130;
goto V_43;
V_130:
V_60 = F_74 ( V_34 , V_21 , V_121 , V_127 ) ;
if ( V_60 )
goto V_43;
return 0 ;
V_43:
return - V_131 ;
}
int F_78 ( struct V_23 * V_34 , unsigned char * V_120 ,
unsigned int V_122 , unsigned char V_132 )
{
unsigned char V_6 [ 16 ] ;
struct V_133 V_134 ;
int V_60 ;
if ( V_34 -> V_135 || V_34 -> V_78 < V_136 )
return - V_131 ;
memset ( V_6 , 0 , 16 ) ;
V_6 [ 0 ] = V_137 ;
V_6 [ 1 ] = V_138 ;
V_6 [ 2 ] = 1 ;
V_6 [ 3 ] = V_132 ;
F_79 ( V_122 , & V_6 [ 6 ] ) ;
memset ( V_120 , 0 , V_122 ) ;
V_60 = F_75 ( V_34 , V_6 , V_124 , V_120 , V_122 ,
& V_134 , 30 * V_125 , 3 , NULL ) ;
if ( V_60 && F_80 ( & V_134 ) &&
V_134 . V_139 == V_140 &&
( V_134 . V_141 == 0x20 || V_134 . V_141 == 0x24 ) && V_134 . V_142 == 0x00 )
return - V_131 ;
if ( ( V_120 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_81 ( struct V_23 * V_34 )
{
if ( V_34 -> V_73 == V_74 )
return - V_143 ;
if ( ! F_19 ( & V_34 -> V_25 ) )
return - V_143 ;
F_82 ( V_34 -> V_26 -> V_55 -> V_144 ) ;
return 0 ;
}
void F_83 ( struct V_23 * V_34 )
{
#ifdef F_84
struct V_144 * V_144 = V_34 -> V_26 -> V_55 -> V_144 ;
if ( V_144 && F_85 ( V_144 ) != 0 )
F_86 ( V_144 ) ;
#endif
F_23 ( & V_34 -> V_25 ) ;
}
struct V_23 * F_87 ( struct V_12 * V_13 ,
struct V_23 * V_145 )
{
struct V_146 * V_20 = ( V_145 ? & V_145 -> V_147 : & V_13 -> V_148 ) ;
struct V_23 * V_19 = NULL ;
unsigned long V_16 ;
F_12 ( V_13 -> V_149 , V_16 ) ;
while ( V_20 -> V_19 != & V_13 -> V_148 ) {
V_19 = F_15 ( V_20 -> V_19 , struct V_23 , V_147 ) ;
if ( ! F_81 ( V_19 ) )
break;
V_19 = NULL ;
V_20 = V_20 -> V_19 ;
}
F_17 ( V_13 -> V_149 , V_16 ) ;
if ( V_145 )
F_83 ( V_145 ) ;
return V_19 ;
}
void F_88 ( struct V_91 * V_92 , void * V_150 ,
void (* F_89)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_90 ( V_92 -> V_24 . V_151 ) ;
struct V_23 * V_34 ;
F_91 (sdev, shost) {
if ( ( V_34 -> V_152 == V_92 -> V_152 ) &&
( V_34 -> V_153 == V_92 -> V_153 ) )
F_89 ( V_34 , V_150 ) ;
}
}
void F_92 ( struct V_91 * V_92 , void * V_150 ,
void (* F_89)( struct V_23 * , void * ) )
{
struct V_12 * V_13 = F_90 ( V_92 -> V_24 . V_151 ) ;
struct V_23 * V_34 ;
F_93 (sdev, shost) {
if ( ( V_34 -> V_152 == V_92 -> V_152 ) &&
( V_34 -> V_153 == V_92 -> V_153 ) )
F_89 ( V_34 , V_150 ) ;
}
}
struct V_23 * F_94 ( struct V_91 * V_92 ,
T_3 V_82 )
{
struct V_23 * V_34 ;
F_95 (sdev, &starget->devices, same_target_siblings) {
if ( V_34 -> V_73 == V_74 )
continue;
if ( V_34 -> V_82 == V_82 )
return V_34 ;
}
return NULL ;
}
struct V_23 * F_96 ( struct V_91 * V_92 ,
T_3 V_82 )
{
struct V_23 * V_34 ;
struct V_12 * V_13 = F_90 ( V_92 -> V_24 . V_151 ) ;
unsigned long V_16 ;
F_12 ( V_13 -> V_149 , V_16 ) ;
V_34 = F_94 ( V_92 , V_82 ) ;
if ( V_34 && F_81 ( V_34 ) )
V_34 = NULL ;
F_17 ( V_13 -> V_149 , V_16 ) ;
return V_34 ;
}
struct V_23 * F_97 ( struct V_12 * V_13 ,
T_3 V_152 , T_3 V_153 , T_3 V_82 )
{
struct V_23 * V_34 ;
F_95 (sdev, &shost->__devices, siblings) {
if ( V_34 -> V_152 == V_152 && V_34 -> V_153 == V_153 &&
V_34 -> V_82 == V_82 )
return V_34 ;
}
return NULL ;
}
struct V_23 * F_98 ( struct V_12 * V_13 ,
T_3 V_152 , T_3 V_153 , T_3 V_82 )
{
struct V_23 * V_34 ;
unsigned long V_16 ;
F_12 ( V_13 -> V_149 , V_16 ) ;
V_34 = F_97 ( V_13 , V_152 , V_153 , V_82 ) ;
if ( V_34 && F_81 ( V_34 ) )
V_34 = NULL ;
F_17 ( V_13 -> V_149 , V_16 ) ;
return V_34 ;
}
static int T_4 F_99 ( void )
{
int error ;
error = F_100 () ;
if ( error )
return error ;
error = F_101 () ;
if ( error )
goto V_154;
error = F_102 () ;
if ( error )
goto V_155;
error = F_103 () ;
if ( error )
goto V_156;
error = F_104 () ;
if ( error )
goto V_157;
error = F_105 () ;
if ( error )
goto V_158;
F_106 () ;
F_43 ( V_159 L_27 ) ;
return 0 ;
V_158:
F_107 () ;
V_157:
F_108 () ;
V_156:
F_109 () ;
V_155:
F_110 () ;
V_154:
F_111 () ;
F_43 ( V_160 L_28 ,
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
F_115 ( & V_161 ) ;
}
