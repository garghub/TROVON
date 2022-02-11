static struct V_1 * F_1
( int (* F_2)( void * ) , void * V_2 , char * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_3 ( F_2 , V_2 , L_1 , V_3 ) ;
if ( F_4 ( V_4 ) ) {
F_5 ( L_2 ) ;
return NULL ;
}
return V_4 ;
}
static void F_6 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
char V_7 , void * V_8 )
{
unsigned long V_9 ;
struct V_10 * V_11 ;
int V_12 ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
V_12 = V_6 -> V_14 ;
while ( V_6 -> V_15 [ V_12 ] . V_16 ) {
V_12 = ( V_12 + 1 ) % V_17 ;
if ( V_12 == ( int ) V_6 -> V_14 ) {
F_10 ( & V_6 -> V_13 , V_9 ) ;
return - V_18 ;
}
}
V_11 = & V_6 -> V_15 [ V_12 ] ;
memset ( & V_11 -> V_19 , 0 , sizeof( V_11 -> V_19 ) ) ;
V_11 -> V_7 = V_7 ;
if ( V_8 )
V_11 -> V_16 = V_8 ;
else
V_11 -> V_16 = & V_11 -> V_19 ;
V_6 -> V_14 = ( V_12 + 1 ) % V_17 ;
F_10 ( & V_6 -> V_13 , V_9 ) ;
return V_12 ;
}
static void * F_11 ( struct V_5 * V_6 ,
int V_20 )
{
unsigned long V_9 ;
void * V_16 ;
if ( V_20 >= V_17 )
return NULL ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
V_16 = V_6 -> V_15 [ V_20 ] . V_16 ;
V_6 -> V_15 [ V_20 ] . V_7 = 0 ;
V_6 -> V_15 [ V_20 ] . V_16 = NULL ;
F_10 ( & V_6 -> V_13 , V_9 ) ;
return V_16 ;
}
static struct V_21 * F_12 ( struct V_5 * V_22 ,
int V_23 )
{
if ( V_22 -> V_15 [ V_23 ] . V_16 )
return & V_22 -> V_15 [ V_23 ] . V_19 ;
return NULL ;
}
static unsigned int F_13 ( struct V_24 * V_25 , void * V_26 ,
T_1 * V_27 )
{
int V_28 ;
unsigned long V_9 ;
F_14 ( V_29 ) ;
F_9 ( V_27 , V_9 ) ;
V_28 = F_15 ( V_25 , V_26 , 1 , V_30 , V_31 ) ;
F_10 ( V_27 , V_9 ) ;
F_16 () ;
if ( V_28 < 0 )
return 0 ;
return ( unsigned int ) ( V_28 ) ;
}
static void F_17 ( struct V_24 * V_25 , T_1 * V_27 ,
struct V_21 * V_19 ,
T_2 * V_32 , int * V_33 )
{
V_19 -> V_34 . V_35 =
F_13 ( V_25 , V_32 , V_27 ) ;
V_19 -> V_34 . V_36 =
F_13 ( V_25 , V_33 , V_27 ) ;
}
static void F_18 ( struct V_24 * V_25 ,
struct V_21 * V_19 )
{
if ( V_19 -> V_34 . V_35 )
F_19 ( V_25 , V_19 -> V_34 . V_35 ) ;
if ( V_19 -> V_34 . V_36 )
F_19 ( V_25 , V_19 -> V_34 . V_36 ) ;
}
static int F_20 ( enum V_37 V_38 ,
struct V_39 * V_40 )
{
struct V_21 * V_19 ;
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_5 * V_6 =
(struct V_5 * ) V_42 -> V_44 -> V_45 ;
int V_46 = 0xffff ;
T_2 V_47 ;
int V_48 = 0 ;
if ( V_6 -> V_49 || V_6 -> V_50 )
return V_51 ;
V_48 = F_8 ( V_6 , V_52 ,
NULL ) ;
if ( V_48 < 0 )
return V_51 ;
V_19 = F_12 ( V_6 , V_48 ) ;
F_21 ( & V_47 ) ;
V_19 -> V_7 = V_52 ;
F_17 ( & V_6 -> V_24 , & V_6 -> V_13 , V_19 ,
& V_47 , & V_46 ) ;
V_19 -> V_34 . V_38 = V_38 ;
V_19 -> V_34 . V_53 . V_54 = V_42 -> V_54 ;
V_19 -> V_34 . V_53 . V_28 = V_42 -> V_28 ;
V_19 -> V_34 . V_53 . V_55 = V_42 -> V_55 ;
V_19 -> V_34 . V_56 = V_48 ;
F_22 ( & V_42 -> V_57 ,
L_3 , V_38 ) ;
if ( F_23 ( V_6 -> V_58 -> V_59 ,
V_60 ,
V_19 ) )
goto V_61;
if ( ! F_24 ( V_47 , V_46 != 0xffff ,
F_25 ( 45000 ) ) )
goto V_61;
F_22 ( & V_42 -> V_57 ,
L_4 ,
V_38 , V_46 ) ;
if ( V_38 == V_62 )
V_40 -> V_33 = V_63 << 16 ;
else
V_40 -> V_33 = V_64 << 16 ;
V_40 -> V_65 ( V_40 ) ;
F_18 ( & V_6 -> V_24 , V_19 ) ;
return V_66 ;
V_61:
F_22 ( & V_42 -> V_57 ,
L_5 , V_38 ) ;
F_11 ( V_6 , V_48 ) ;
F_18 ( & V_6 -> V_24 , V_19 ) ;
return V_51 ;
}
static int F_26 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
V_42 = V_40 -> V_43 ;
V_6 = (struct V_5 * ) V_42 -> V_44 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
if ( F_28 ( & V_68 -> V_69 ) < V_70 )
F_29 ( & V_68 -> V_69 ) ;
else
F_30 ( & V_68 -> V_71 , V_72 ) ;
}
return F_20 ( V_62 , V_40 ) ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
V_42 = V_40 -> V_43 ;
V_6 = (struct V_5 * ) V_42 -> V_44 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
if ( F_28 ( & V_68 -> V_69 ) < V_70 )
F_29 ( & V_68 -> V_69 ) ;
else
F_30 ( & V_68 -> V_71 , V_72 ) ;
}
return F_20 ( V_73 , V_40 ) ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
V_42 = V_40 -> V_43 ;
V_6 = (struct V_5 * ) V_42 -> V_44 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
if ( F_28 ( & V_68 -> V_69 ) < V_70 )
F_29 ( & V_68 -> V_69 ) ;
else
F_30 ( & V_68 -> V_71 , V_72 ) ;
}
return F_20 ( V_74 , V_40 ) ;
}
static int
F_33 ( struct V_39 * V_40 )
{
return V_66 ;
}
static const char * F_34 ( struct V_75 * V_76 )
{
return L_6 ;
}
static int
F_35 ( struct V_39 * V_40 ,
void (* F_36)( struct V_39 * ) )
{
struct V_21 * V_19 ;
struct V_41 * V_42 = V_40 -> V_43 ;
int V_12 ;
unsigned char * V_77 = V_40 -> V_78 ;
struct V_75 * V_79 = V_42 -> V_44 ;
unsigned int V_80 ;
struct V_5 * V_6 =
(struct V_5 * ) V_79 -> V_45 ;
struct V_81 * V_82 = NULL ;
struct V_81 * V_83 = NULL ;
if ( V_6 -> V_49 || V_6 -> V_50 )
return V_84 ;
V_12 = F_8 ( V_6 , V_85 ,
( void * ) V_40 ) ;
if ( V_12 < 0 )
return V_84 ;
V_19 = F_12 ( V_6 , V_12 ) ;
V_19 -> V_7 = V_85 ;
V_19 -> V_86 . V_56 = V_12 ;
V_40 -> V_65 = F_36 ;
V_19 -> V_86 . V_53 . V_54 = V_42 -> V_54 ;
V_19 -> V_86 . V_53 . V_28 = V_42 -> V_28 ;
V_19 -> V_86 . V_53 . V_55 = V_42 -> V_55 ;
V_19 -> V_86 . V_87 = V_40 -> V_88 ;
memcpy ( V_19 -> V_86 . V_78 , V_77 , V_89 ) ;
V_19 -> V_86 . V_90 = F_37 ( V_40 ) ;
if ( V_19 -> V_86 . V_90 > V_6 -> V_91 )
V_6 -> V_91 = V_19 -> V_86 . V_90 ;
if ( F_38 ( V_40 ) > V_92 )
goto V_61;
V_83 = F_39 ( V_40 ) ;
F_40 (sglist, sg, scsi_sg_count(scsicmd), i) {
V_19 -> V_86 . V_93 [ V_80 ] . V_94 = F_41 ( V_82 ) ;
V_19 -> V_86 . V_93 [ V_80 ] . V_95 = V_82 -> V_95 ;
}
V_19 -> V_86 . V_96 = F_38 ( V_40 ) ;
if ( F_23 ( V_6 -> V_58 -> V_59 ,
V_60 ,
V_19 ) )
goto V_61;
return 0 ;
V_61:
F_11 ( V_6 , V_12 ) ;
return V_84 ;
}
void F_42 ( struct V_41 * V_42 )
{
struct V_67 * V_68 , * V_97 ;
struct V_5 * V_6 ;
struct V_75 * V_79 = (struct V_75 * ) V_42 -> V_44 ;
V_6 = (struct V_5 * ) V_79 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
V_97 = V_68 -> V_98 ;
V_68 -> V_98 = V_97 -> V_98 ;
F_43 ( V_97 ) ;
return;
}
}
static int F_44 ( struct V_99 * V_100 , void * V_101 )
{
struct V_5 * V_6 = V_100 -> V_102 ;
F_45 ( V_100 , L_7 , V_6 -> V_91 ) ;
F_45 ( V_100 , L_8 , V_6 -> V_103 ) ;
F_45 ( V_100 , L_9 ,
V_6 -> V_104 ) ;
F_45 ( V_100 , L_10 ,
V_6 -> V_105 ) ;
F_45 ( V_100 , L_11 , V_6 -> V_106 ) ;
if ( V_6 -> V_106 ) {
T_3 V_107 =
F_46 ( ( V_108 void * ) V_6 -> V_106 ) ;
F_45 ( V_100 , L_12 ,
V_107 ) ;
F_45 ( V_100 , L_13 ,
( V_109 ) F_47 ( V_6 -> V_106 ) ) ;
}
F_45 ( V_100 , L_14 ,
V_6 -> V_110 ) ;
return 0 ;
}
static int F_48 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
return F_49 ( V_112 , F_44 , V_111 -> V_113 ) ;
}
static void F_50 ( struct V_24 * V_25 ,
struct V_21 * V_19 , int V_33 )
{
T_2 * V_114 =
F_51 ( V_25 , V_19 -> V_34 . V_35 ) ;
int * V_115 =
F_51 ( V_25 , V_19 -> V_34 . V_36 ) ;
if ( F_52 ( ! ( V_114 && V_115 ) ) ) {
F_5 ( L_15 ) ;
return;
}
F_53 ( L_16 , V_33 ) ;
* V_115 = V_33 ;
F_54 ( V_114 ) ;
}
static void F_55 ( struct V_5 * V_6 )
{
int V_80 ;
struct V_10 * V_116 = NULL ;
struct V_39 * V_40 = NULL ;
struct V_21 * V_19 ;
unsigned long V_9 ;
F_6 ( V_6 -> V_117 ) ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
for ( V_80 = 0 ; V_80 < V_17 ; V_80 ++ ) {
V_116 = & V_6 -> V_15 [ V_80 ] ;
switch ( V_116 -> V_7 ) {
case V_85 :
V_40 = V_116 -> V_16 ;
V_40 -> V_33 = V_64 << 16 ;
if ( V_40 -> V_65 )
V_40 -> V_65 ( V_40 ) ;
break;
case V_52 :
V_19 = V_116 -> V_16 ;
F_50 ( & V_6 -> V_24 , V_19 ,
V_118 ) ;
break;
default:
break;
}
V_116 -> V_7 = 0 ;
V_116 -> V_16 = NULL ;
}
F_10 ( & V_6 -> V_13 , V_9 ) ;
V_6 -> V_49 = true ;
V_6 -> V_50 = false ;
}
static int F_56 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_49 && ! V_6 -> V_50 ) {
V_6 -> V_50 = true ;
F_55 ( V_6 ) ;
} else if ( V_6 -> V_50 ) {
return - V_119 ;
}
return 0 ;
}
static void
F_57 ( struct V_21 * V_19 , struct V_39 * V_40 )
{
struct V_5 * V_6 ;
struct V_67 * V_68 ;
struct V_41 * V_42 ;
V_42 = V_40 -> V_43 ;
memcpy ( V_40 -> V_120 , V_19 -> V_86 . V_121 , V_122 ) ;
if ( ( V_19 -> V_86 . V_78 [ 0 ] == V_123 ) &&
( F_58 ( V_19 -> V_86 . V_124 ) == V_125 ) &&
( V_19 -> V_86 . V_126 == V_127 ) )
return;
V_6 = (struct V_5 * ) V_42 -> V_44 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
if ( F_28 ( & V_68 -> V_69 ) < V_70 ) {
F_29 ( & V_68 -> V_69 ) ;
F_30 ( & V_68 -> V_71 , V_72 ) ;
}
}
}
static int F_59 ( unsigned char * V_128 ,
T_4 V_129 , bool V_130 )
{
if ( ! V_128 || V_129 < V_131 )
return - V_119 ;
memset ( V_128 , 0 , V_131 ) ;
V_128 [ 2 ] = V_132 ;
if ( V_130 ) {
V_128 [ 0 ] = V_133 ;
V_128 [ 3 ] = V_134 ;
} else {
V_128 [ 0 ] = V_135 ;
}
V_128 [ 4 ] = V_131 - 5 ;
strncpy ( V_128 + 8 , L_17 , V_131 - 8 ) ;
return 0 ;
}
static void
F_60 ( struct V_21 * V_19 , struct V_39 * V_40 )
{
struct V_41 * V_42 ;
unsigned char * V_128 ;
struct V_81 * V_82 ;
unsigned int V_80 ;
char * V_136 ;
char * V_137 ;
int V_138 = 0 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
V_42 = V_40 -> V_43 ;
if ( ( V_19 -> V_86 . V_78 [ 0 ] == V_123 ) &&
( V_19 -> V_86 . V_90 >= V_139 ) ) {
if ( V_19 -> V_86 . V_140 == 0 )
return;
V_128 = F_61 ( sizeof( char ) * 36 , V_29 ) ;
if ( ! V_128 )
return;
F_59 ( V_128 , ( T_4 ) V_19 -> V_86 . V_90 ,
V_42 -> V_55 == 0 ) ;
if ( F_38 ( V_40 ) == 0 ) {
memcpy ( F_39 ( V_40 ) , V_128 ,
V_19 -> V_86 . V_90 ) ;
F_43 ( V_128 ) ;
return;
}
V_82 = F_39 ( V_40 ) ;
for ( V_80 = 0 ; V_80 < F_38 ( V_40 ) ; V_80 ++ ) {
V_137 = F_62 ( F_63 ( V_82 + V_80 ) ) ;
V_136 = ( void * ) ( ( unsigned long ) V_137 |
V_82 [ V_80 ] . V_141 ) ;
memcpy ( V_136 , V_128 + V_138 , V_82 [ V_80 ] . V_95 ) ;
F_64 ( V_137 ) ;
}
F_43 ( V_128 ) ;
} else {
V_6 = (struct V_5 * ) V_42 -> V_44 -> V_45 ;
F_27 (vdisk, devdata, scsidev) {
if ( F_28 ( & V_68 -> V_71 ) > 0 ) {
F_65 ( & V_68 -> V_71 ) ;
if ( F_28 ( & V_68 -> V_71 ) == 0 )
F_30 ( & V_68 -> V_69 , 0 ) ;
}
}
}
}
static void
F_66 ( struct V_21 * V_19 , struct V_39 * V_40 )
{
V_40 -> V_33 = V_19 -> V_86 . V_124 ;
if ( V_19 -> V_86 . V_124 )
F_57 ( V_19 , V_40 ) ;
else
F_60 ( V_19 , V_40 ) ;
V_40 -> V_65 ( V_40 ) ;
}
static void
F_67 ( struct V_21 * V_19 , struct V_5 * V_6 )
{
struct V_39 * V_40 ;
while ( 1 ) {
if ( F_68 ( V_6 -> V_58 -> V_59 ,
V_142 ,
V_19 ) )
break;
if ( V_19 -> V_7 == V_85 ) {
V_40 = F_11 ( V_6 ,
V_19 -> V_86 . V_56 ) ;
if ( ! V_40 )
break;
F_66 ( V_19 , V_40 ) ;
} else if ( V_19 -> V_7 == V_52 ) {
if ( ! F_11 ( V_6 ,
V_19 -> V_34 . V_56 ) )
break;
F_50 ( & V_6 -> V_24 , V_19 ,
V_19 -> V_34 . V_33 ) ;
} else if ( V_19 -> V_7 == V_143 )
F_69 ( & V_6 -> V_58 -> V_43 ,
L_18 ) ;
}
}
static int F_70 ( void * V_101 )
{
struct V_5 * V_6 = V_101 ;
struct V_21 * V_19 = NULL ;
const int V_144 = sizeof( * V_19 ) ;
V_19 = F_71 ( V_144 , V_145 ) ;
if ( ! V_19 )
return - V_146 ;
while ( 1 ) {
if ( F_72 () )
break;
F_73 (
V_6 -> V_147 , ( F_28 (
& V_6 -> V_148 ) == 1 ) ,
F_25 ( V_6 -> V_149 ) ) ;
F_67 ( V_19 , V_6 ) ;
}
F_43 ( V_19 ) ;
return 0 ;
}
static int F_74 ( struct V_150 * V_58 ,
T_5 V_151 )
{
struct V_5 * V_6 = F_75 ( & V_58 -> V_43 ) ;
F_56 ( V_6 ) ;
V_151 ( V_58 , 0 ) ;
return 0 ;
}
static int F_76 ( struct V_150 * V_58 ,
T_5 V_151 )
{
struct V_5 * V_6 ;
V_6 = F_75 ( & V_58 -> V_43 ) ;
if ( ! V_6 )
return - V_119 ;
if ( V_6 -> V_49 && ! V_6 -> V_50 )
V_6 -> V_50 = true ;
V_6 -> V_117 = F_1 ( F_70 , V_6 ,
L_19 ) ;
V_6 -> V_49 = false ;
V_6 -> V_50 = false ;
return 0 ;
}
static int F_77 ( struct V_150 * V_58 )
{
struct V_75 * V_79 ;
struct V_152 V_153 ;
struct V_5 * V_6 = NULL ;
int V_154 , V_155 ;
T_3 V_156 ;
V_79 = F_78 ( & V_157 ,
sizeof( * V_6 ) ) ;
if ( ! V_79 )
return - V_158 ;
V_155 = F_79 ( struct V_159 ,
V_160 . V_153 ) ;
V_154 = F_80 ( V_58 , V_155 , & V_153 ,
sizeof( struct V_152 ) ) ;
if ( V_154 < 0 )
goto V_161;
V_79 -> V_162 = ( unsigned int ) V_153 . V_162 ;
V_79 -> V_163 = ( unsigned int ) V_153 . V_163 ;
V_79 -> V_164 = ( unsigned int ) V_153 . V_164 ;
V_79 -> V_165 =
( unsigned short ) ( V_153 . V_166 >> 9 ) ;
V_79 -> V_167 =
( unsigned short ) ( V_153 . V_166 / V_168 ) ;
if ( V_79 -> V_167 > V_92 )
V_79 -> V_167 = V_92 ;
V_154 = F_81 ( V_79 , & V_58 -> V_43 ) ;
if ( V_154 < 0 )
goto V_161;
V_6 = (struct V_5 * ) V_79 -> V_45 ;
V_6 -> V_58 = V_58 ;
F_82 ( & V_58 -> V_43 , V_6 ) ;
V_6 -> V_169 = F_83 ( F_84 ( & V_58 -> V_43 ) ,
V_170 ) ;
if ( ! V_6 -> V_169 ) {
V_154 = - V_146 ;
goto V_171;
}
V_6 -> V_172 =
F_85 ( L_20 , V_173 | V_174 ,
V_6 -> V_169 , V_6 ,
& V_175 ) ;
if ( ! V_6 -> V_172 ) {
V_154 = - V_146 ;
goto V_176;
}
F_21 ( & V_6 -> V_147 ) ;
F_86 ( & V_6 -> V_13 ) ;
V_6 -> V_49 = false ;
V_6 -> V_50 = false ;
V_6 -> V_79 = V_79 ;
V_155 = F_79 ( struct V_159 ,
V_177 . V_156 ) ;
V_154 = F_80 ( V_58 , V_155 , & V_156 , 8 ) ;
if ( V_154 )
goto V_178;
V_156 |= V_179 ;
V_154 = F_87 ( V_58 , V_155 , & V_156 , 8 ) ;
if ( V_154 )
goto V_178;
F_88 ( & V_6 -> V_24 ) ;
V_6 -> V_149 = 2 ;
V_6 -> V_117 = F_1 ( F_70 , V_6 ,
L_21 ) ;
F_89 ( V_79 ) ;
return 0 ;
V_178:
F_90 ( V_6 -> V_172 ) ;
V_176:
F_91 ( V_6 -> V_169 ) ;
V_171:
F_92 ( V_79 ) ;
V_161:
F_93 ( V_79 ) ;
return V_154 ;
}
static void F_94 ( struct V_150 * V_58 )
{
struct V_5 * V_6 = F_75 ( & V_58 -> V_43 ) ;
struct V_75 * V_79 = NULL ;
if ( ! V_6 )
return;
V_79 = V_6 -> V_79 ;
F_6 ( V_6 -> V_117 ) ;
F_92 ( V_79 ) ;
F_93 ( V_79 ) ;
F_95 ( & V_6 -> V_24 ) ;
F_82 ( & V_58 -> V_43 , NULL ) ;
F_90 ( V_6 -> V_172 ) ;
F_91 ( V_6 -> V_169 ) ;
}
static int F_96 ( void )
{
int V_180 = - V_146 ;
V_170 = F_83 ( L_6 , NULL ) ;
if ( ! V_170 )
return - V_146 ;
V_180 = F_97 ( & V_181 ) ;
if ( V_180 )
goto V_182;
return 0 ;
V_182:
F_91 ( V_170 ) ;
return V_180 ;
}
static void F_98 ( void )
{
F_99 ( & V_181 ) ;
F_91 ( V_170 ) ;
}
