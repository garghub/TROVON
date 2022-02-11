static struct V_1 * F_1 ( int (* F_2)( void * ) ,
void * V_2 , char * V_3 )
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
static void * F_11 ( struct V_5 * V_6 , int V_20 )
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
struct V_5 * V_6 =
(struct V_5 * ) V_40 -> V_41 -> V_42 ;
int V_43 = 0xffff ;
T_2 V_44 ;
int V_45 = 0 ;
if ( V_6 -> V_46 || V_6 -> V_47 )
return V_48 ;
V_45 = F_8 ( V_6 , V_49 ,
NULL ) ;
if ( V_45 < 0 )
return V_48 ;
V_19 = F_12 ( V_6 , V_45 ) ;
F_21 ( & V_44 ) ;
V_19 -> V_7 = V_49 ;
F_17 ( & V_6 -> V_24 , & V_6 -> V_13 , V_19 ,
& V_44 , & V_43 ) ;
V_19 -> V_34 . V_38 = V_38 ;
V_19 -> V_34 . V_50 . V_51 = V_40 -> V_51 ;
V_19 -> V_34 . V_50 . V_28 = V_40 -> V_28 ;
V_19 -> V_34 . V_50 . V_52 = V_40 -> V_52 ;
V_19 -> V_34 . V_53 = V_45 ;
F_22 ( & V_40 -> V_54 ,
L_3 , V_38 ) ;
if ( F_23 ( V_6 -> V_55 -> V_56 ,
V_57 ,
V_19 ) )
goto V_58;
if ( ! F_24 ( V_44 , V_43 != 0xffff ,
F_25 ( 45000 ) ) )
goto V_58;
F_22 ( & V_40 -> V_54 ,
L_4 ,
V_38 , V_43 ) ;
F_18 ( & V_6 -> V_24 , V_19 ) ;
return V_59 ;
V_58:
F_22 ( & V_40 -> V_54 ,
L_5 , V_38 ) ;
F_11 ( V_6 , V_45 ) ;
F_18 ( & V_6 -> V_24 , V_19 ) ;
return V_48 ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_39 * V_40 ;
struct V_62 * V_63 ;
int V_64 ;
V_40 = V_61 -> V_65 ;
V_63 = V_40 -> V_42 ;
if ( F_27 ( & V_63 -> V_66 ) < V_67 )
F_28 ( & V_63 -> V_66 ) ;
else
F_29 ( & V_63 -> V_68 , V_69 ) ;
V_64 = F_20 ( V_70 , V_40 ) ;
if ( V_64 == V_59 ) {
V_61 -> V_33 = V_71 << 16 ;
V_61 -> V_72 ( V_61 ) ;
}
return V_64 ;
}
static int F_30 ( struct V_60 * V_61 )
{
struct V_39 * V_40 ;
struct V_62 * V_63 ;
int V_64 ;
V_40 = V_61 -> V_65 ;
V_63 = V_40 -> V_42 ;
if ( F_27 ( & V_63 -> V_66 ) < V_67 )
F_28 ( & V_63 -> V_66 ) ;
else
F_29 ( & V_63 -> V_68 , V_69 ) ;
V_64 = F_20 ( V_73 , V_40 ) ;
if ( V_64 == V_59 ) {
V_61 -> V_33 = V_74 << 16 ;
V_61 -> V_72 ( V_61 ) ;
}
return V_64 ;
}
static int F_31 ( struct V_60 * V_61 )
{
struct V_39 * V_40 ;
struct V_62 * V_63 ;
int V_64 ;
V_40 = V_61 -> V_65 ;
F_32 (scsidev, scsidev->host) {
V_63 = V_40 -> V_42 ;
if ( F_27 ( & V_63 -> V_66 ) < V_67 )
F_28 ( & V_63 -> V_66 ) ;
else
F_29 ( & V_63 -> V_68 , V_69 ) ;
}
V_64 = F_20 ( V_75 , V_40 ) ;
if ( V_64 == V_59 ) {
V_61 -> V_33 = V_74 << 16 ;
V_61 -> V_72 ( V_61 ) ;
}
return V_64 ;
}
static int F_33 ( struct V_60 * V_61 )
{
return V_59 ;
}
static const char * F_34 ( struct V_76 * V_77 )
{
return L_6 ;
}
static T_3 F_35 ( enum V_78 V_79 )
{
switch ( V_79 ) {
case V_80 :
return V_81 ;
case V_82 :
return V_83 ;
case V_84 :
return V_85 ;
case V_86 :
return V_87 ;
default:
return V_87 ;
}
}
static int F_36 ( struct V_60 * V_61 ,
void (* F_37)
( struct V_60 * ) )
{
struct V_21 * V_19 ;
struct V_39 * V_40 = V_61 -> V_65 ;
int V_12 ;
unsigned char * V_88 = V_61 -> V_89 ;
struct V_76 * V_90 = V_40 -> V_41 ;
unsigned int V_91 ;
struct V_5 * V_6 =
(struct V_5 * ) V_90 -> V_42 ;
struct V_92 * V_93 = NULL ;
struct V_92 * V_94 = NULL ;
if ( V_6 -> V_46 || V_6 -> V_47 )
return V_95 ;
V_12 = F_8 ( V_6 , V_96 ,
( void * ) V_61 ) ;
if ( V_12 < 0 )
return V_95 ;
V_19 = F_12 ( V_6 , V_12 ) ;
V_19 -> V_7 = V_96 ;
V_19 -> V_97 . V_53 = V_12 ;
V_61 -> V_72 = F_37 ;
V_19 -> V_97 . V_50 . V_51 = V_40 -> V_51 ;
V_19 -> V_97 . V_50 . V_28 = V_40 -> V_28 ;
V_19 -> V_97 . V_50 . V_52 = V_40 -> V_52 ;
V_19 -> V_97 . V_98 =
F_35 ( V_61 -> V_99 ) ;
memcpy ( V_19 -> V_97 . V_89 , V_88 , V_100 ) ;
V_19 -> V_97 . V_101 = F_38 ( V_61 ) ;
if ( V_19 -> V_97 . V_101 > V_6 -> V_102 )
V_6 -> V_102 = V_19 -> V_97 . V_101 ;
if ( F_39 ( V_61 ) > V_103 )
goto V_58;
V_94 = F_40 ( V_61 ) ;
F_41 (sglist, sg, scsi_sg_count(scsicmd), i) {
V_19 -> V_97 . V_104 [ V_91 ] . V_105 = F_42 ( V_93 ) ;
V_19 -> V_97 . V_104 [ V_91 ] . V_106 = V_93 -> V_106 ;
}
V_19 -> V_97 . V_107 = F_39 ( V_61 ) ;
if ( F_23 ( V_6 -> V_55 -> V_56 ,
V_57 ,
V_19 ) )
goto V_58;
return 0 ;
V_58:
F_11 ( V_6 , V_12 ) ;
return V_95 ;
}
void F_43 ( struct V_39 * V_40 )
{
struct V_62 * V_63 ;
V_63 = V_40 -> V_42 ;
V_40 -> V_42 = NULL ;
F_44 ( V_63 ) ;
}
static int F_45 ( struct V_108 * V_109 , void * V_110 )
{
struct V_5 * V_6 = V_109 -> V_111 ;
F_46 ( V_109 , L_7 , V_6 -> V_102 ) ;
F_46 ( V_109 , L_8 , V_6 -> V_112 ) ;
F_46 ( V_109 , L_9 ,
V_6 -> V_113 ) ;
F_46 ( V_109 , L_10 ,
V_6 -> V_114 ) ;
F_46 ( V_109 , L_11 , V_6 -> V_115 ) ;
if ( V_6 -> V_115 ) {
T_4 V_116 =
F_47 ( ( V_117 void * ) V_6 -> V_115 ) ;
F_46 ( V_109 , L_12 ,
V_116 ) ;
F_46 ( V_109 , L_13 ,
( T_4 ) F_48 ( V_6 -> V_115 ) ) ;
}
F_46 ( V_109 , L_14 ,
V_6 -> V_118 ) ;
return 0 ;
}
static int F_49 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_50 ( V_120 , F_45 , V_119 -> V_121 ) ;
}
static void F_51 ( struct V_24 * V_25 ,
struct V_21 * V_19 , int V_33 )
{
T_2 * V_122 =
F_52 ( V_25 , V_19 -> V_34 . V_35 ) ;
int * V_123 =
F_52 ( V_25 , V_19 -> V_34 . V_36 ) ;
if ( F_53 ( ! ( V_122 && V_123 ) ) ) {
F_5 ( L_15 ) ;
return;
}
F_54 ( L_16 , V_33 ) ;
* V_123 = V_33 ;
F_55 ( V_122 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
int V_91 ;
struct V_10 * V_124 = NULL ;
struct V_60 * V_61 = NULL ;
struct V_21 * V_19 ;
unsigned long V_9 ;
F_6 ( V_6 -> V_125 ) ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
for ( V_91 = 0 ; V_91 < V_17 ; V_91 ++ ) {
V_124 = & V_6 -> V_15 [ V_91 ] ;
switch ( V_124 -> V_7 ) {
case V_96 :
V_61 = V_124 -> V_16 ;
V_61 -> V_33 = V_74 << 16 ;
if ( V_61 -> V_72 )
V_61 -> V_72 ( V_61 ) ;
break;
case V_49 :
V_19 = V_124 -> V_16 ;
F_51 ( & V_6 -> V_24 , V_19 ,
V_126 ) ;
break;
default:
break;
}
V_124 -> V_7 = 0 ;
V_124 -> V_16 = NULL ;
}
F_10 ( & V_6 -> V_13 , V_9 ) ;
V_6 -> V_46 = true ;
V_6 -> V_47 = false ;
}
static int F_57 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_46 && ! V_6 -> V_47 ) {
V_6 -> V_47 = true ;
F_56 ( V_6 ) ;
} else if ( V_6 -> V_47 ) {
return - V_127 ;
}
return 0 ;
}
static void F_58 ( struct V_21 * V_19 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 ;
struct V_39 * V_40 ;
V_40 = V_61 -> V_65 ;
memcpy ( V_61 -> V_128 , V_19 -> V_97 . V_129 , V_130 ) ;
if ( ( V_19 -> V_97 . V_89 [ 0 ] == V_131 ) &&
( F_59 ( V_19 -> V_97 . V_132 ) == V_133 ) &&
( V_19 -> V_97 . V_134 == V_135 ) )
return;
V_63 = V_40 -> V_42 ;
if ( F_27 ( & V_63 -> V_66 ) < V_67 ) {
F_28 ( & V_63 -> V_66 ) ;
F_29 ( & V_63 -> V_68 , V_69 ) ;
}
}
static int F_60 ( unsigned char * V_136 , T_5 V_137 ,
bool V_138 )
{
if ( V_137 < V_139 )
return - V_127 ;
memset ( V_136 , 0 , V_139 ) ;
V_136 [ 2 ] = V_140 ;
if ( V_138 ) {
V_136 [ 0 ] = V_141 ;
V_136 [ 3 ] = V_142 ;
} else {
V_136 [ 0 ] = V_143 ;
}
V_136 [ 4 ] = V_139 - 5 ;
strncpy ( V_136 + 8 , L_17 , V_139 - 8 ) ;
return 0 ;
}
static void F_61 ( struct V_21 * V_19 ,
struct V_60 * V_61 )
{
struct V_39 * V_40 ;
unsigned char * V_136 ;
struct V_92 * V_93 ;
unsigned int V_91 ;
char * V_144 ;
char * V_145 ;
int V_146 = 0 ;
struct V_62 * V_63 ;
V_40 = V_61 -> V_65 ;
if ( ( V_19 -> V_97 . V_89 [ 0 ] == V_131 ) &&
( V_19 -> V_97 . V_101 >= V_147 ) ) {
if ( V_19 -> V_97 . V_148 == 0 )
return;
V_136 = F_62 ( sizeof( char ) * 36 , V_29 ) ;
if ( ! V_136 )
return;
F_60 ( V_136 , ( T_5 ) V_19 -> V_97 . V_101 ,
V_40 -> V_52 == 0 ) ;
if ( F_39 ( V_61 ) == 0 ) {
memcpy ( F_40 ( V_61 ) , V_136 ,
V_19 -> V_97 . V_101 ) ;
F_44 ( V_136 ) ;
return;
}
V_93 = F_40 ( V_61 ) ;
for ( V_91 = 0 ; V_91 < F_39 ( V_61 ) ; V_91 ++ ) {
V_145 = F_63 ( F_64 ( V_93 + V_91 ) ) ;
V_144 = ( void * ) ( ( unsigned long ) V_145 |
V_93 [ V_91 ] . V_149 ) ;
memcpy ( V_144 , V_136 + V_146 , V_93 [ V_91 ] . V_106 ) ;
F_65 ( V_145 ) ;
}
F_44 ( V_136 ) ;
} else {
V_63 = V_40 -> V_42 ;
if ( F_27 ( & V_63 -> V_68 ) > 0 ) {
F_66 ( & V_63 -> V_68 ) ;
if ( F_27 ( & V_63 -> V_68 ) == 0 )
F_29 ( & V_63 -> V_66 , 0 ) ;
}
}
}
static void F_67 ( struct V_21 * V_19 ,
struct V_60 * V_61 )
{
V_61 -> V_33 = V_19 -> V_97 . V_132 ;
if ( V_19 -> V_97 . V_132 )
F_58 ( V_19 , V_61 ) ;
else
F_61 ( V_19 , V_61 ) ;
V_61 -> V_72 ( V_61 ) ;
}
static void F_68 ( struct V_21 * V_19 ,
struct V_5 * V_6 )
{
struct V_60 * V_61 ;
while ( 1 ) {
if ( F_69 ( V_6 -> V_55 -> V_56 ,
V_150 ,
V_19 ) )
break;
if ( V_19 -> V_7 == V_96 ) {
V_61 = F_11 ( V_6 ,
V_19 -> V_97 . V_53 ) ;
if ( ! V_61 )
break;
F_67 ( V_19 , V_61 ) ;
} else if ( V_19 -> V_7 == V_49 ) {
if ( ! F_11 ( V_6 ,
V_19 -> V_34 . V_53 ) )
break;
F_51 ( & V_6 -> V_24 , V_19 ,
V_19 -> V_34 . V_33 ) ;
} else if ( V_19 -> V_7 == V_151 )
F_70 ( & V_6 -> V_55 -> V_65 ,
L_18 ) ;
}
}
static int F_71 ( void * V_110 )
{
struct V_5 * V_6 = V_110 ;
struct V_21 * V_19 = NULL ;
const int V_152 = sizeof( * V_19 ) ;
V_19 = F_72 ( V_152 , V_153 ) ;
if ( ! V_19 )
return - V_154 ;
while ( 1 ) {
if ( F_73 () )
break;
F_74 (
V_6 -> V_155 , ( F_27 (
& V_6 -> V_156 ) == 1 ) ,
F_25 ( V_6 -> V_157 ) ) ;
F_68 ( V_19 , V_6 ) ;
}
F_44 ( V_19 ) ;
return 0 ;
}
static int F_75 ( struct V_158 * V_55 ,
T_6 V_159 )
{
struct V_5 * V_6 = F_76 ( & V_55 -> V_65 ) ;
F_57 ( V_6 ) ;
V_159 ( V_55 , 0 ) ;
return 0 ;
}
static int F_77 ( struct V_158 * V_55 ,
T_6 V_159 )
{
struct V_5 * V_6 ;
V_6 = F_76 ( & V_55 -> V_65 ) ;
if ( ! V_6 )
return - V_127 ;
if ( V_6 -> V_46 && ! V_6 -> V_47 )
V_6 -> V_47 = true ;
V_6 -> V_125 = F_1 ( F_71 , V_6 ,
L_19 ) ;
V_6 -> V_46 = false ;
V_6 -> V_47 = false ;
return 0 ;
}
static int F_78 ( struct V_158 * V_55 )
{
struct V_76 * V_90 ;
struct V_160 V_161 ;
struct V_5 * V_6 = NULL ;
int V_162 , V_163 ;
T_4 V_164 ;
V_90 = F_79 ( & V_165 ,
sizeof( * V_6 ) ) ;
if ( ! V_90 )
return - V_166 ;
V_163 = F_80 ( struct V_167 , V_168 . V_161 ) ;
V_162 = F_81 ( V_55 , V_163 , & V_161 ,
sizeof( struct V_160 ) ) ;
if ( V_162 < 0 )
goto V_169;
V_90 -> V_170 = ( unsigned int ) V_161 . V_170 ;
V_90 -> V_171 = ( unsigned int ) V_161 . V_171 ;
V_90 -> V_172 = ( unsigned int ) V_161 . V_172 ;
V_90 -> V_173 =
( unsigned short ) ( V_161 . V_174 >> 9 ) ;
V_90 -> V_175 =
( unsigned short ) ( V_161 . V_174 / V_176 ) ;
if ( V_90 -> V_175 > V_103 )
V_90 -> V_175 = V_103 ;
V_162 = F_82 ( V_90 , & V_55 -> V_65 ) ;
if ( V_162 < 0 )
goto V_169;
V_6 = (struct V_5 * ) V_90 -> V_42 ;
V_6 -> V_55 = V_55 ;
F_83 ( & V_55 -> V_65 , V_6 ) ;
V_6 -> V_177 = F_84 ( F_85 ( & V_55 -> V_65 ) ,
V_178 ) ;
if ( ! V_6 -> V_177 ) {
V_162 = - V_154 ;
goto V_179;
}
V_6 -> V_180 =
F_86 ( L_20 , 0440 ,
V_6 -> V_177 , V_6 ,
& V_181 ) ;
if ( ! V_6 -> V_180 ) {
V_162 = - V_154 ;
goto V_182;
}
F_21 ( & V_6 -> V_155 ) ;
F_87 ( & V_6 -> V_13 ) ;
V_6 -> V_46 = false ;
V_6 -> V_47 = false ;
V_6 -> V_90 = V_90 ;
V_163 = F_80 ( struct V_167 ,
V_183 . V_164 ) ;
V_162 = F_81 ( V_55 , V_163 , & V_164 , 8 ) ;
if ( V_162 )
goto V_184;
V_164 |= V_185 ;
V_162 = F_88 ( V_55 , V_163 , & V_164 , 8 ) ;
if ( V_162 )
goto V_184;
F_89 ( & V_6 -> V_24 ) ;
V_6 -> V_157 = 2 ;
V_6 -> V_125 = F_1 ( F_71 , V_6 ,
L_21 ) ;
F_90 ( V_90 ) ;
return 0 ;
V_184:
F_91 ( V_6 -> V_180 ) ;
V_182:
F_92 ( V_6 -> V_177 ) ;
V_179:
F_93 ( V_90 ) ;
V_169:
F_94 ( V_90 ) ;
return V_162 ;
}
static void F_95 ( struct V_158 * V_55 )
{
struct V_5 * V_6 = F_76 ( & V_55 -> V_65 ) ;
struct V_76 * V_90 = NULL ;
if ( ! V_6 )
return;
V_90 = V_6 -> V_90 ;
F_6 ( V_6 -> V_125 ) ;
F_93 ( V_90 ) ;
F_94 ( V_90 ) ;
F_96 ( & V_6 -> V_24 ) ;
F_83 ( & V_55 -> V_65 , NULL ) ;
F_91 ( V_6 -> V_180 ) ;
F_92 ( V_6 -> V_177 ) ;
}
static int F_97 ( void )
{
int V_186 = - V_154 ;
V_178 = F_84 ( L_6 , NULL ) ;
if ( ! V_178 )
return - V_154 ;
V_186 = F_98 ( & V_187 ) ;
if ( V_186 )
goto V_188;
return 0 ;
V_188:
F_92 ( V_178 ) ;
return V_186 ;
}
static void F_99 ( void )
{
F_100 ( & V_187 ) ;
F_92 ( V_178 ) ;
}
