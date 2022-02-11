static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_8 )
F_2 ( V_9 , V_4 -> V_8 ) ;
F_2 ( V_6 -> V_10 , V_4 -> V_11 ) ;
F_2 ( V_6 -> V_12 , V_4 ) ;
}
static struct V_3 *
F_3 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
V_4 = F_4 ( V_6 -> V_12 , V_13 | V_6 -> V_13 ) ;
if ( ! V_4 )
goto V_14;
V_4 -> V_11 = F_5 ( V_6 -> V_10 ,
V_13 | V_6 -> V_13 ) ;
if ( ! V_4 -> V_11 )
goto V_15;
if ( F_6 ( V_2 ) >= V_16 ) {
V_4 -> V_8 = F_4 ( V_9 , V_13 ) ;
if ( ! V_4 -> V_8 )
goto V_17;
}
return V_4 ;
V_17:
F_2 ( V_6 -> V_10 , V_4 -> V_11 ) ;
V_15:
F_2 ( V_6 -> V_12 , V_4 ) ;
V_14:
return NULL ;
}
static struct V_3 *
F_7 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_3 * V_4 = F_3 ( V_2 , V_13 ) ;
if ( F_8 ( ! V_4 ) ) {
unsigned long V_18 ;
F_9 ( & V_2 -> V_19 , V_18 ) ;
if ( F_10 ( ! F_11 ( & V_2 -> V_20 ) ) ) {
V_4 = F_12 ( V_2 -> V_20 . V_21 ,
struct V_3 , V_22 ) ;
F_13 ( & V_4 -> V_22 ) ;
}
F_14 ( & V_2 -> V_19 , V_18 ) ;
if ( V_4 ) {
void * V_23 , * V_24 ;
V_23 = V_4 -> V_11 ;
V_24 = V_4 -> V_8 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_11 = V_23 ;
V_4 -> V_8 = V_24 ;
}
}
return V_4 ;
}
struct V_3 * F_15 ( struct V_25 * V_26 , T_1 V_13 )
{
struct V_3 * V_4 = F_7 ( V_26 -> V_27 , V_13 ) ;
unsigned long V_18 ;
if ( F_8 ( V_4 == NULL ) )
return NULL ;
V_4 -> V_28 = V_26 ;
F_16 ( & V_4 -> V_22 ) ;
F_17 ( & V_4 -> V_29 , V_30 ) ;
F_9 ( & V_26 -> V_31 , V_18 ) ;
F_18 ( & V_4 -> V_22 , & V_26 -> V_32 ) ;
F_14 ( & V_26 -> V_31 , V_18 ) ;
V_4 -> V_33 = V_34 ;
return V_4 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_18 ;
if ( F_8 ( F_11 ( & V_2 -> V_20 ) ) ) {
F_9 ( & V_2 -> V_19 , V_18 ) ;
if ( F_11 ( & V_2 -> V_20 ) ) {
F_20 ( & V_4 -> V_22 , & V_2 -> V_20 ) ;
V_4 = NULL ;
}
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
if ( F_10 ( V_4 != NULL ) )
F_1 ( V_2 , V_4 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
unsigned long V_18 ;
F_9 ( & V_4 -> V_28 -> V_31 , V_18 ) ;
F_22 ( F_11 ( & V_4 -> V_22 ) ) ;
F_13 ( & V_4 -> V_22 ) ;
F_14 ( & V_4 -> V_28 -> V_31 , V_18 ) ;
F_22 ( F_23 ( & V_4 -> V_29 ) ) ;
F_19 ( V_4 -> V_28 -> V_27 , V_4 ) ;
}
static struct V_5 *
F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 -> V_36 )
return V_2 -> V_35 -> V_7 ;
if ( V_2 -> V_37 )
return & V_38 ;
return & V_39 ;
}
static void
F_25 ( struct V_5 * V_6 )
{
F_26 ( V_6 -> V_40 ) ;
F_26 ( V_6 -> V_41 ) ;
F_26 ( V_6 ) ;
}
static struct V_5 *
F_27 ( struct V_1 * V_2 )
{
struct V_42 * V_35 = V_2 -> V_35 ;
struct V_5 * V_6 ;
V_6 = F_28 ( sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_41 = F_29 ( V_43 , L_1 , V_35 -> V_44 ) ;
V_6 -> V_40 = F_29 ( V_43 , L_2 , V_35 -> V_44 ) ;
if ( ! V_6 -> V_41 || ! V_6 -> V_40 ) {
F_25 ( V_6 ) ;
return NULL ;
}
V_6 -> V_45 = V_46 ;
if ( V_2 -> V_37 ) {
V_6 -> V_45 |= V_47 ;
V_6 -> V_13 = V_48 ;
}
if ( V_35 -> V_36 )
V_35 -> V_7 = V_6 ;
return V_6 ;
}
static struct V_5 *
F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_35 = V_2 -> V_35 ;
struct V_5 * V_49 = NULL , * V_6 ;
T_2 V_36 = sizeof( struct V_3 ) + V_35 -> V_36 ;
F_31 ( & V_50 ) ;
V_6 = F_24 ( V_2 ) ;
if ( ! V_6 ) {
V_6 = F_27 ( V_2 ) ;
if ( ! V_6 )
goto V_51;
}
if ( ! V_6 -> V_52 ) {
V_6 -> V_12 = F_32 ( V_6 -> V_41 , V_36 , 0 ,
V_6 -> V_45 , NULL ) ;
if ( ! V_6 -> V_12 )
goto V_53;
V_6 -> V_10 = F_32 ( V_6 -> V_40 ,
V_54 , 0 ,
V_6 -> V_45 , NULL ) ;
if ( ! V_6 -> V_10 )
goto V_55;
}
V_6 -> V_52 ++ ;
V_49 = V_6 ;
V_51:
F_33 ( & V_50 ) ;
return V_49 ;
V_55:
F_34 ( V_6 -> V_12 ) ;
V_53:
if ( V_35 -> V_36 ) {
F_25 ( V_6 ) ;
V_35 -> V_7 = NULL ;
}
goto V_51;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_42 * V_35 = V_2 -> V_35 ;
struct V_5 * V_6 ;
F_31 ( & V_50 ) ;
V_6 = F_24 ( V_2 ) ;
F_22 ( V_6 -> V_52 == 0 ) ;
if ( ! -- V_6 -> V_52 ) {
F_34 ( V_6 -> V_12 ) ;
F_34 ( V_6 -> V_10 ) ;
if ( V_35 -> V_36 ) {
F_25 ( V_6 ) ;
V_35 -> V_7 = NULL ;
}
}
F_33 ( & V_50 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
const T_1 V_13 = V_2 -> V_37 ? V_56 : V_43 ;
struct V_3 * V_4 ;
F_37 ( & V_2 -> V_19 ) ;
F_16 ( & V_2 -> V_20 ) ;
V_2 -> V_7 = F_30 ( V_2 ) ;
if ( ! V_2 -> V_7 )
return - V_57 ;
V_4 = F_3 ( V_2 , V_13 ) ;
if ( ! V_4 ) {
F_35 ( V_2 ) ;
V_2 -> V_7 = NULL ;
return - V_57 ;
}
F_20 ( & V_4 -> V_22 , & V_2 -> V_20 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
while ( ! F_11 ( & V_2 -> V_20 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_2 -> V_20 . V_21 , struct V_3 , V_22 ) ;
F_13 ( & V_4 -> V_22 ) ;
F_1 ( V_2 , V_4 ) ;
}
V_2 -> V_7 = NULL ;
F_35 ( V_2 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
unsigned int V_58 ;
if ( F_8 ( V_59 ) ) {
V_58 = F_40 ( V_60 ,
V_61 ) ;
if ( V_58 > 1 ) {
F_41 ( V_62 , V_4 ,
L_3 , V_4 ) ;
F_42 ( V_4 ) ;
}
}
}
void F_43 ( struct V_3 * V_4 , int V_63 )
{
unsigned int V_58 ;
if ( F_8 ( V_59 ) ) {
V_58 = F_40 ( V_64 ,
V_65 ) ;
if ( ( ( V_58 > 0 ) && ( V_4 -> V_66 || V_63 != V_67 ) ) ||
( V_58 > 1 ) ) {
F_44 ( V_4 , L_4 , V_63 ) ;
F_42 ( V_4 ) ;
if ( F_45 ( V_4 -> V_66 ) & V_68 )
F_46 ( V_4 ) ;
if ( V_58 > 3 )
F_41 ( V_62 , V_4 ,
L_5 ,
F_47 ( & V_4 -> V_28 -> V_27 -> V_69 ) ,
V_4 -> V_28 -> V_27 -> V_70 ) ;
}
}
}
void F_48 ( struct V_1 * V_27 , struct V_3 * V_4 )
{
V_4 -> V_71 = V_27 -> V_72 ++ ;
if ( V_4 -> V_71 == 0 )
V_4 -> V_71 = V_27 -> V_72 ++ ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_25 * V_73 = V_4 -> V_28 ;
struct V_74 * V_75 = V_74 ( V_73 ) ;
struct V_1 * V_2 = V_73 -> V_27 ;
struct V_76 * V_77 ;
unsigned int V_78 ;
F_50 ( V_73 ) ;
if ( F_47 ( & V_2 -> V_79 ) )
F_51 ( & V_2 -> V_79 , 0 ) ;
if ( F_47 ( & V_75 -> V_80 ) )
F_51 ( & V_75 -> V_80 , 0 ) ;
if ( F_47 ( & V_73 -> V_81 ) )
F_51 ( & V_73 -> V_81 , 0 ) ;
if ( F_52 ( V_4 ) )
V_4 -> V_66 |= ( V_82 << 24 ) ;
F_53 ( 4 , F_54 ( V_62 , V_73 ,
L_6
L_7 , V_4 -> V_66 ) ) ;
V_78 = F_55 ( V_4 ) ;
if ( V_4 -> V_83 -> V_84 != V_85 ) {
int V_86 = V_78 ;
V_77 = F_56 ( V_4 ) ;
if ( V_77 -> V_87 )
V_78 = V_77 -> V_87 ( V_4 ) ;
if ( V_78 == V_86 )
V_78 -= F_57 ( V_4 ) ;
}
F_58 ( V_4 , V_78 ) ;
}
int F_59 ( struct V_25 * V_73 , int V_88 )
{
unsigned long V_18 ;
if ( V_88 <= 0 )
goto V_51;
F_9 ( V_73 -> V_89 -> V_90 , V_18 ) ;
if ( ! F_60 ( V_73 -> V_27 ) && ! V_73 -> V_27 -> V_91 ) {
if ( F_61 ( V_73 -> V_89 ) &&
F_62 ( V_73 -> V_89 , V_88 ) != 0 )
goto V_92;
}
V_73 -> V_93 = V_88 ;
V_92:
F_14 ( V_73 -> V_89 -> V_90 , V_18 ) ;
V_51:
return V_73 -> V_93 ;
}
int F_63 ( struct V_25 * V_73 , int V_88 )
{
if ( ( V_34 >> 4 ) == ( V_73 -> V_94 >> 4 ) )
return 0 ;
V_73 -> V_94 = V_34 ;
if ( V_73 -> V_95 != V_88 ) {
V_73 -> V_96 = 1 ;
V_73 -> V_95 = V_88 ;
} else {
V_73 -> V_96 ++ ;
}
if ( V_73 -> V_96 <= 10 )
return 0 ;
return F_59 ( V_73 , V_88 ) ;
}
static int F_64 ( struct V_25 * V_73 , unsigned char * V_97 ,
T_3 V_98 , unsigned V_99 )
{
int V_66 ;
unsigned char V_4 [ 16 ] ;
if ( V_99 < 4 )
return - V_100 ;
V_4 [ 0 ] = V_101 ;
V_4 [ 1 ] = 1 ;
V_4 [ 2 ] = V_98 ;
V_4 [ 3 ] = V_99 >> 8 ;
V_4 [ 4 ] = V_99 & 0xff ;
V_4 [ 5 ] = 0 ;
V_66 = F_65 ( V_73 , V_4 , V_102 , V_97 ,
V_99 , NULL , 30 * V_103 , 3 , NULL ) ;
if ( V_66 )
return - V_104 ;
if ( V_97 [ 1 ] != V_98 )
return - V_104 ;
return F_66 ( & V_97 [ 2 ] ) + 4 ;
}
int F_67 ( struct V_25 * V_73 , T_3 V_98 , unsigned char * V_23 ,
int V_105 )
{
int V_106 , V_66 ;
if ( V_73 -> V_107 )
goto V_14;
V_66 = F_64 ( V_73 , V_23 , 0 , V_105 ) ;
if ( V_66 < 4 )
goto V_14;
if ( V_98 == 0 )
return 0 ;
for ( V_106 = 4 ; V_106 < F_68 ( V_66 , V_105 ) ; V_106 ++ )
if ( V_23 [ V_106 ] == V_98 )
goto V_108;
if ( V_106 < V_66 && V_106 >= V_105 )
goto V_108;
goto V_14;
V_108:
V_66 = F_64 ( V_73 , V_23 , V_98 , V_105 ) ;
if ( V_66 < 0 )
goto V_14;
return 0 ;
V_14:
return - V_100 ;
}
void F_69 ( struct V_25 * V_73 )
{
int V_66 , V_106 ;
int V_109 = V_110 ;
int V_111 = 0 ;
int V_112 = 0 ;
unsigned char * V_113 ;
if ( V_73 -> V_107 )
return;
V_114:
V_113 = F_70 ( V_109 , V_43 ) ;
if ( ! V_113 )
return;
V_66 = F_64 ( V_73 , V_113 , 0 , V_109 ) ;
if ( V_66 < 0 ) {
F_26 ( V_113 ) ;
return;
}
if ( V_66 > V_109 ) {
V_109 = V_66 ;
F_26 ( V_113 ) ;
goto V_114;
}
for ( V_106 = 4 ; V_106 < V_66 ; V_106 ++ ) {
if ( V_113 [ V_106 ] == 0x80 )
V_111 = 1 ;
if ( V_113 [ V_106 ] == 0x83 )
V_112 = 1 ;
}
F_26 ( V_113 ) ;
V_109 = V_110 ;
if ( V_111 ) {
V_115:
V_113 = F_70 ( V_109 , V_43 ) ;
if ( ! V_113 )
return;
V_66 = F_64 ( V_73 , V_113 , 0x80 , V_109 ) ;
if ( V_66 < 0 ) {
F_26 ( V_113 ) ;
return;
}
if ( V_66 > V_109 ) {
V_109 = V_66 ;
F_26 ( V_113 ) ;
goto V_115;
}
V_73 -> V_116 = V_66 ;
V_73 -> V_117 = V_113 ;
V_109 = V_110 ;
}
if ( V_112 ) {
V_118:
V_113 = F_70 ( V_109 , V_43 ) ;
if ( ! V_113 )
return;
V_66 = F_64 ( V_73 , V_113 , 0x83 , V_109 ) ;
if ( V_66 < 0 ) {
F_26 ( V_113 ) ;
return;
}
if ( V_66 > V_109 ) {
V_109 = V_66 ;
F_26 ( V_113 ) ;
goto V_118;
}
V_73 -> V_119 = V_66 ;
V_73 -> V_120 = V_113 ;
}
}
int F_71 ( struct V_25 * V_73 , unsigned char * V_97 ,
unsigned int V_99 , unsigned char V_121 )
{
unsigned char V_4 [ 16 ] ;
struct V_122 V_123 ;
int V_66 ;
if ( V_73 -> V_124 || V_73 -> V_125 < V_126 )
return - V_100 ;
memset ( V_4 , 0 , 16 ) ;
V_4 [ 0 ] = V_127 ;
V_4 [ 1 ] = V_128 ;
V_4 [ 2 ] = 1 ;
V_4 [ 3 ] = V_121 ;
F_72 ( V_99 , & V_4 [ 6 ] ) ;
memset ( V_97 , 0 , V_99 ) ;
V_66 = F_65 ( V_73 , V_4 , V_102 , V_97 , V_99 ,
& V_123 , 30 * V_103 , 3 , NULL ) ;
if ( V_66 && F_73 ( & V_123 ) &&
V_123 . V_129 == V_130 &&
( V_123 . V_131 == 0x20 || V_123 . V_131 == 0x24 ) && V_123 . V_132 == 0x00 )
return - V_100 ;
if ( ( V_97 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_74 ( struct V_25 * V_73 )
{
if ( V_73 -> V_133 == V_134 || V_73 -> V_133 == V_135 )
goto V_14;
if ( ! F_75 ( & V_73 -> V_136 ) )
goto V_14;
if ( ! F_76 ( V_73 -> V_27 -> V_35 -> V_137 ) )
goto V_138;
return 0 ;
V_138:
F_77 ( & V_73 -> V_136 ) ;
V_14:
return - V_139 ;
}
void F_78 ( struct V_25 * V_73 )
{
F_79 ( V_73 -> V_27 -> V_35 -> V_137 ) ;
F_77 ( & V_73 -> V_136 ) ;
}
struct V_25 * F_80 ( struct V_1 * V_2 ,
struct V_25 * V_140 )
{
struct V_141 * V_22 = ( V_140 ? & V_140 -> V_142 : & V_2 -> V_143 ) ;
struct V_25 * V_21 = NULL ;
unsigned long V_18 ;
F_9 ( V_2 -> V_144 , V_18 ) ;
while ( V_22 -> V_21 != & V_2 -> V_143 ) {
V_21 = F_12 ( V_22 -> V_21 , struct V_25 , V_142 ) ;
if ( ! F_74 ( V_21 ) )
break;
V_21 = NULL ;
V_22 = V_22 -> V_21 ;
}
F_14 ( V_2 -> V_144 , V_18 ) ;
if ( V_140 )
F_78 ( V_140 ) ;
return V_21 ;
}
void F_81 ( struct V_74 * V_75 , void * V_145 ,
void (* F_82)( struct V_25 * , void * ) )
{
struct V_1 * V_2 = F_83 ( V_75 -> V_26 . V_146 ) ;
struct V_25 * V_73 ;
F_84 (sdev, shost) {
if ( ( V_73 -> V_147 == V_75 -> V_147 ) &&
( V_73 -> V_148 == V_75 -> V_148 ) )
F_82 ( V_73 , V_145 ) ;
}
}
void F_85 ( struct V_74 * V_75 , void * V_145 ,
void (* F_82)( struct V_25 * , void * ) )
{
struct V_1 * V_2 = F_83 ( V_75 -> V_26 . V_146 ) ;
struct V_25 * V_73 ;
F_86 (sdev, shost) {
if ( ( V_73 -> V_147 == V_75 -> V_147 ) &&
( V_73 -> V_148 == V_75 -> V_148 ) )
F_82 ( V_73 , V_145 ) ;
}
}
struct V_25 * F_87 ( struct V_74 * V_75 ,
T_4 V_149 )
{
struct V_25 * V_73 ;
F_88 (sdev, &starget->devices, same_target_siblings) {
if ( V_73 -> V_133 == V_134 )
continue;
if ( V_73 -> V_149 == V_149 )
return V_73 ;
}
return NULL ;
}
struct V_25 * F_89 ( struct V_74 * V_75 ,
T_4 V_149 )
{
struct V_25 * V_73 ;
struct V_1 * V_2 = F_83 ( V_75 -> V_26 . V_146 ) ;
unsigned long V_18 ;
F_9 ( V_2 -> V_144 , V_18 ) ;
V_73 = F_87 ( V_75 , V_149 ) ;
if ( V_73 && F_74 ( V_73 ) )
V_73 = NULL ;
F_14 ( V_2 -> V_144 , V_18 ) ;
return V_73 ;
}
struct V_25 * F_90 ( struct V_1 * V_2 ,
T_5 V_147 , T_5 V_148 , T_4 V_149 )
{
struct V_25 * V_73 ;
F_88 (sdev, &shost->__devices, siblings) {
if ( V_73 -> V_147 == V_147 && V_73 -> V_148 == V_148 &&
V_73 -> V_149 == V_149 )
return V_73 ;
}
return NULL ;
}
struct V_25 * F_91 ( struct V_1 * V_2 ,
T_5 V_147 , T_5 V_148 , T_4 V_149 )
{
struct V_25 * V_73 ;
unsigned long V_18 ;
F_9 ( V_2 -> V_144 , V_18 ) ;
V_73 = F_90 ( V_2 , V_147 , V_148 , V_149 ) ;
if ( V_73 && F_74 ( V_73 ) )
V_73 = NULL ;
F_14 ( V_2 -> V_144 , V_18 ) ;
return V_73 ;
}
static int T_6 F_92 ( void )
{
int error ;
error = F_93 () ;
if ( error )
return error ;
error = F_94 () ;
if ( error )
goto V_150;
error = F_95 () ;
if ( error )
goto V_151;
error = F_96 () ;
if ( error )
goto V_152;
error = F_97 () ;
if ( error )
goto V_153;
error = F_98 () ;
if ( error )
goto V_154;
F_99 () ;
F_100 ( V_155 L_8 ) ;
return 0 ;
V_154:
F_101 () ;
V_153:
F_102 () ;
V_152:
F_103 () ;
V_151:
F_104 () ;
V_150:
F_105 () ;
F_100 ( V_156 L_9 ,
- error ) ;
return error ;
}
static void T_7 F_106 ( void )
{
F_107 () ;
F_108 () ;
F_101 () ;
F_102 () ;
F_103 () ;
F_104 () ;
F_105 () ;
F_109 ( & V_157 ) ;
}
