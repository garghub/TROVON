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
if ( V_88 > 0 ) {
V_73 -> V_89 = V_88 ;
F_60 () ;
}
return V_73 -> V_89 ;
}
int F_61 ( struct V_25 * V_73 , int V_88 )
{
if ( ( V_34 >> 4 ) == ( V_73 -> V_90 >> 4 ) )
return 0 ;
V_73 -> V_90 = V_34 ;
if ( V_73 -> V_91 != V_88 ) {
V_73 -> V_92 = 1 ;
V_73 -> V_91 = V_88 ;
} else {
V_73 -> V_92 ++ ;
}
if ( V_73 -> V_92 <= 10 )
return 0 ;
return F_59 ( V_73 , V_88 ) ;
}
static int F_62 ( struct V_25 * V_73 , unsigned char * V_93 ,
T_3 V_94 , unsigned V_95 )
{
int V_66 ;
unsigned char V_4 [ 16 ] ;
if ( V_95 < 4 )
return - V_96 ;
V_4 [ 0 ] = V_97 ;
V_4 [ 1 ] = 1 ;
V_4 [ 2 ] = V_94 ;
V_4 [ 3 ] = V_95 >> 8 ;
V_4 [ 4 ] = V_95 & 0xff ;
V_4 [ 5 ] = 0 ;
V_66 = F_63 ( V_73 , V_4 , V_98 , V_93 ,
V_95 , NULL , 30 * V_99 , 3 , NULL ) ;
if ( V_66 )
return - V_100 ;
if ( V_93 [ 1 ] != V_94 )
return - V_100 ;
return F_64 ( & V_93 [ 2 ] ) + 4 ;
}
int F_65 ( struct V_25 * V_73 , T_3 V_94 , unsigned char * V_23 ,
int V_101 )
{
int V_102 , V_66 ;
if ( V_73 -> V_103 )
goto V_14;
V_66 = F_62 ( V_73 , V_23 , 0 , V_101 ) ;
if ( V_66 < 4 )
goto V_14;
if ( V_94 == 0 )
return 0 ;
for ( V_102 = 4 ; V_102 < F_66 ( V_66 , V_101 ) ; V_102 ++ )
if ( V_23 [ V_102 ] == V_94 )
goto V_104;
if ( V_102 < V_66 && V_102 >= V_101 )
goto V_104;
goto V_14;
V_104:
V_66 = F_62 ( V_73 , V_23 , V_94 , V_101 ) ;
if ( V_66 < 0 )
goto V_14;
return 0 ;
V_14:
return - V_96 ;
}
void F_67 ( struct V_25 * V_73 )
{
int V_66 , V_102 ;
int V_105 = V_106 ;
int V_107 = 0 ;
int V_108 = 0 ;
unsigned char T_4 * V_109 , * V_110 = NULL ;
if ( ! F_68 ( V_73 ) )
return;
V_111:
V_109 = F_69 ( V_105 , V_43 ) ;
if ( ! V_109 )
return;
V_66 = F_62 ( V_73 , V_109 , 0 , V_105 ) ;
if ( V_66 < 0 ) {
F_26 ( V_109 ) ;
return;
}
if ( V_66 > V_105 ) {
V_105 = V_66 ;
F_26 ( V_109 ) ;
goto V_111;
}
for ( V_102 = 4 ; V_102 < V_66 ; V_102 ++ ) {
if ( V_109 [ V_102 ] == 0x80 )
V_107 = 1 ;
if ( V_109 [ V_102 ] == 0x83 )
V_108 = 1 ;
}
F_26 ( V_109 ) ;
V_105 = V_106 ;
if ( V_107 ) {
V_112:
V_109 = F_69 ( V_105 , V_43 ) ;
if ( ! V_109 )
return;
V_66 = F_62 ( V_73 , V_109 , 0x80 , V_105 ) ;
if ( V_66 < 0 ) {
F_26 ( V_109 ) ;
return;
}
if ( V_66 > V_105 ) {
V_105 = V_66 ;
F_26 ( V_109 ) ;
goto V_112;
}
F_31 ( & V_73 -> V_113 ) ;
V_110 = V_73 -> V_114 ;
V_73 -> V_115 = V_66 ;
F_70 ( V_73 -> V_114 , V_109 ) ;
F_33 ( & V_73 -> V_113 ) ;
F_71 () ;
if ( V_110 ) {
F_26 ( V_110 ) ;
V_110 = NULL ;
}
V_105 = V_106 ;
}
if ( V_108 ) {
V_116:
V_109 = F_69 ( V_105 , V_43 ) ;
if ( ! V_109 )
return;
V_66 = F_62 ( V_73 , V_109 , 0x83 , V_105 ) ;
if ( V_66 < 0 ) {
F_26 ( V_109 ) ;
return;
}
if ( V_66 > V_105 ) {
V_105 = V_66 ;
F_26 ( V_109 ) ;
goto V_116;
}
F_31 ( & V_73 -> V_113 ) ;
V_110 = V_73 -> V_117 ;
V_73 -> V_118 = V_66 ;
F_70 ( V_73 -> V_117 , V_109 ) ;
F_33 ( & V_73 -> V_113 ) ;
F_71 () ;
if ( V_110 )
F_26 ( V_110 ) ;
}
}
int F_72 ( struct V_25 * V_73 , unsigned char * V_93 ,
unsigned int V_95 , unsigned char V_119 )
{
unsigned char V_4 [ 16 ] ;
struct V_120 V_121 ;
int V_66 ;
if ( V_73 -> V_122 || V_73 -> V_123 < V_124 )
return - V_96 ;
memset ( V_4 , 0 , 16 ) ;
V_4 [ 0 ] = V_125 ;
V_4 [ 1 ] = V_126 ;
V_4 [ 2 ] = 1 ;
V_4 [ 3 ] = V_119 ;
F_73 ( V_95 , & V_4 [ 6 ] ) ;
memset ( V_93 , 0 , V_95 ) ;
V_66 = F_63 ( V_73 , V_4 , V_98 , V_93 , V_95 ,
& V_121 , 30 * V_99 , 3 , NULL ) ;
if ( V_66 && F_74 ( & V_121 ) &&
V_121 . V_127 == V_128 &&
( V_121 . V_129 == 0x20 || V_121 . V_129 == 0x24 ) && V_121 . V_130 == 0x00 )
return - V_96 ;
if ( ( V_93 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_75 ( struct V_25 * V_73 )
{
if ( V_73 -> V_131 == V_132 || V_73 -> V_131 == V_133 )
goto V_14;
if ( ! F_76 ( & V_73 -> V_134 ) )
goto V_14;
if ( ! F_77 ( V_73 -> V_27 -> V_35 -> V_135 ) )
goto V_136;
return 0 ;
V_136:
F_78 ( & V_73 -> V_134 ) ;
V_14:
return - V_137 ;
}
void F_79 ( struct V_25 * V_73 )
{
F_80 ( V_73 -> V_27 -> V_35 -> V_135 ) ;
F_78 ( & V_73 -> V_134 ) ;
}
struct V_25 * F_81 ( struct V_1 * V_2 ,
struct V_25 * V_138 )
{
struct V_139 * V_22 = ( V_138 ? & V_138 -> V_140 : & V_2 -> V_141 ) ;
struct V_25 * V_21 = NULL ;
unsigned long V_18 ;
F_9 ( V_2 -> V_142 , V_18 ) ;
while ( V_22 -> V_21 != & V_2 -> V_141 ) {
V_21 = F_12 ( V_22 -> V_21 , struct V_25 , V_140 ) ;
if ( ! F_75 ( V_21 ) )
break;
V_21 = NULL ;
V_22 = V_22 -> V_21 ;
}
F_14 ( V_2 -> V_142 , V_18 ) ;
if ( V_138 )
F_79 ( V_138 ) ;
return V_21 ;
}
void F_82 ( struct V_74 * V_75 , void * V_143 ,
void (* F_83)( struct V_25 * , void * ) )
{
struct V_1 * V_2 = F_84 ( V_75 -> V_26 . V_144 ) ;
struct V_25 * V_73 ;
F_85 (sdev, shost) {
if ( ( V_73 -> V_145 == V_75 -> V_145 ) &&
( V_73 -> V_146 == V_75 -> V_146 ) )
F_83 ( V_73 , V_143 ) ;
}
}
void F_86 ( struct V_74 * V_75 , void * V_143 ,
void (* F_83)( struct V_25 * , void * ) )
{
struct V_1 * V_2 = F_84 ( V_75 -> V_26 . V_144 ) ;
struct V_25 * V_73 ;
F_87 (sdev, shost) {
if ( ( V_73 -> V_145 == V_75 -> V_145 ) &&
( V_73 -> V_146 == V_75 -> V_146 ) )
F_83 ( V_73 , V_143 ) ;
}
}
struct V_25 * F_88 ( struct V_74 * V_75 ,
T_5 V_147 )
{
struct V_25 * V_73 ;
F_89 (sdev, &starget->devices, same_target_siblings) {
if ( V_73 -> V_131 == V_132 )
continue;
if ( V_73 -> V_147 == V_147 )
return V_73 ;
}
return NULL ;
}
struct V_25 * F_90 ( struct V_74 * V_75 ,
T_5 V_147 )
{
struct V_25 * V_73 ;
struct V_1 * V_2 = F_84 ( V_75 -> V_26 . V_144 ) ;
unsigned long V_18 ;
F_9 ( V_2 -> V_142 , V_18 ) ;
V_73 = F_88 ( V_75 , V_147 ) ;
if ( V_73 && F_75 ( V_73 ) )
V_73 = NULL ;
F_14 ( V_2 -> V_142 , V_18 ) ;
return V_73 ;
}
struct V_25 * F_91 ( struct V_1 * V_2 ,
T_6 V_145 , T_6 V_146 , T_5 V_147 )
{
struct V_25 * V_73 ;
F_89 (sdev, &shost->__devices, siblings) {
if ( V_73 -> V_145 == V_145 && V_73 -> V_146 == V_146 &&
V_73 -> V_147 == V_147 )
return V_73 ;
}
return NULL ;
}
struct V_25 * F_92 ( struct V_1 * V_2 ,
T_6 V_145 , T_6 V_146 , T_5 V_147 )
{
struct V_25 * V_73 ;
unsigned long V_18 ;
F_9 ( V_2 -> V_142 , V_18 ) ;
V_73 = F_91 ( V_2 , V_145 , V_146 , V_147 ) ;
if ( V_73 && F_75 ( V_73 ) )
V_73 = NULL ;
F_14 ( V_2 -> V_142 , V_18 ) ;
return V_73 ;
}
static int T_7 F_93 ( void )
{
int error ;
error = F_94 () ;
if ( error )
return error ;
error = F_95 () ;
if ( error )
goto V_148;
error = F_96 () ;
if ( error )
goto V_149;
error = F_97 () ;
if ( error )
goto V_150;
error = F_98 () ;
if ( error )
goto V_151;
error = F_99 () ;
if ( error )
goto V_152;
F_100 () ;
F_101 ( V_153 L_8 ) ;
return 0 ;
V_152:
F_102 () ;
V_151:
F_103 () ;
V_150:
F_104 () ;
V_149:
F_105 () ;
V_148:
F_106 () ;
F_101 ( V_154 L_9 ,
- error ) ;
return error ;
}
static void T_8 F_107 ( void )
{
F_108 () ;
F_109 () ;
F_102 () ;
F_103 () ;
F_104 () ;
F_105 () ;
F_106 () ;
F_110 ( & V_155 ) ;
}
