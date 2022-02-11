static int F_1 ( struct V_1 * V_2 ,
int (* F_2)( void * ) ,
void * V_3 , char * V_4 )
{
F_3 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = F_4 ( F_2 , V_3 , V_4 ) ;
if ( F_5 ( V_2 -> V_6 ) ) {
V_2 -> V_7 = 0 ;
return F_6 ( V_2 -> V_6 ) ;
}
V_2 -> V_7 = V_2 -> V_6 -> V_8 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 ,
char V_11 , void * V_12 )
{
unsigned long V_13 ;
struct V_14 * V_15 ;
int V_16 ;
F_8 ( & V_10 -> V_17 , V_13 ) ;
V_16 = V_10 -> V_18 ;
while ( V_10 -> V_19 [ V_16 ] . V_20 ) {
V_16 = ( V_16 + 1 ) % V_21 ;
if ( V_16 == ( int ) V_10 -> V_18 ) {
F_9 ( & V_10 -> V_17 , V_13 ) ;
return - 1 ;
}
}
V_15 = & V_10 -> V_19 [ V_16 ] ;
memset ( & V_15 -> V_22 , 0 , sizeof( V_15 -> V_22 ) ) ;
V_15 -> V_11 = V_11 ;
if ( V_12 )
V_15 -> V_20 = V_12 ;
else
V_15 -> V_20 = & V_15 -> V_22 ;
V_10 -> V_18 = ( V_16 + 1 ) % V_21 ;
F_9 ( & V_10 -> V_17 , V_13 ) ;
return V_16 ;
}
static void * F_10 ( struct V_9 * V_10 ,
int V_23 )
{
unsigned long V_13 ;
void * V_20 = NULL ;
if ( V_23 < V_21 ) {
F_8 ( & V_10 -> V_17 , V_13 ) ;
V_20 = V_10 -> V_19 [ V_23 ] . V_20 ;
V_10 -> V_19 [ V_23 ] . V_11 = 0 ;
V_10 -> V_19 [ V_23 ] . V_20 = NULL ;
F_9 ( & V_10 -> V_17 , V_13 ) ;
}
return V_20 ;
}
static struct V_24 * F_11 ( struct V_9 * V_25 ,
int V_26 )
{
if ( V_25 -> V_19 [ V_26 ] . V_20 )
return & V_25 -> V_19 [ V_26 ] . V_22 ;
return NULL ;
}
static int F_12 ( enum V_27 V_28 ,
struct V_29 * V_30 )
{
struct V_24 * V_22 ;
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_9 * V_10 =
(struct V_9 * ) V_32 -> V_34 -> V_35 ;
int V_36 = 0xffff ;
T_1 V_37 ;
int V_38 = 0 ;
if ( V_10 -> V_39 || V_10 -> V_40 )
return V_41 ;
V_38 = F_7 ( V_10 , V_42 ,
NULL ) ;
if ( V_38 < 0 )
return V_41 ;
V_22 = F_11 ( V_10 , V_38 ) ;
F_13 ( & V_37 ) ;
V_22 -> V_11 = V_42 ;
V_22 -> V_43 . V_44 = ( V_45 ) & V_37 ;
V_22 -> V_43 . V_46 = ( V_45 ) & V_36 ;
V_22 -> V_43 . V_28 = V_28 ;
V_22 -> V_43 . V_47 . V_48 = V_32 -> V_48 ;
V_22 -> V_43 . V_47 . V_7 = V_32 -> V_7 ;
V_22 -> V_43 . V_47 . V_49 = V_32 -> V_49 ;
V_22 -> V_43 . V_50 = V_38 ;
if ( ! F_14 ( V_10 -> V_51 -> V_52 ,
V_53 ,
V_22 ) )
goto V_54;
if ( ! F_15 ( V_37 , V_36 != 0xffff ,
F_16 ( 45000 ) ) )
goto V_54;
if ( V_28 == V_55 )
V_30 -> V_56 = ( V_57 << 16 ) ;
else
V_30 -> V_56 = ( V_58 << 16 ) ;
V_30 -> V_59 ( V_30 ) ;
return V_60 ;
V_54:
F_10 ( V_10 , V_38 ) ;
return V_41 ;
}
static int F_17 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_61 * V_62 ;
struct V_9 * V_10 ;
V_32 = V_30 -> V_33 ;
V_10 = (struct V_9 * ) V_32 -> V_34 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
if ( F_19 ( & V_62 -> V_63 ) < V_64 )
F_20 ( & V_62 -> V_63 ) ;
else
F_21 ( & V_62 -> V_65 , V_66 ) ;
}
return F_12 ( V_55 , V_30 ) ;
}
static int F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_61 * V_62 ;
struct V_9 * V_10 ;
V_32 = V_30 -> V_33 ;
V_10 = (struct V_9 * ) V_32 -> V_34 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
if ( F_19 ( & V_62 -> V_63 ) < V_64 )
F_20 ( & V_62 -> V_63 ) ;
else
F_21 ( & V_62 -> V_65 , V_66 ) ;
}
return F_12 ( V_67 , V_30 ) ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_61 * V_62 ;
struct V_9 * V_10 ;
V_32 = V_30 -> V_33 ;
V_10 = (struct V_9 * ) V_32 -> V_34 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
if ( F_19 ( & V_62 -> V_63 ) < V_64 )
F_20 ( & V_62 -> V_63 ) ;
else
F_21 ( & V_62 -> V_65 , V_66 ) ;
}
return F_12 ( V_68 , V_30 ) ;
}
static int
F_24 ( struct V_29 * V_30 )
{
return V_60 ;
}
static const char * F_25 ( struct V_69 * V_70 )
{
return L_1 ;
}
static int
F_26 ( struct V_29 * V_30 ,
void (* F_27)( struct V_29 * ) )
{
struct V_24 * V_22 ;
struct V_31 * V_32 = V_30 -> V_33 ;
int V_16 ;
unsigned char V_71 ;
unsigned char * V_72 = V_30 -> V_73 ;
struct V_69 * V_74 = V_32 -> V_34 ;
unsigned int V_75 ;
struct V_9 * V_10 =
(struct V_9 * ) V_74 -> V_35 ;
struct V_76 * V_77 = NULL ;
struct V_76 * V_78 = NULL ;
int V_79 = 0 ;
if ( V_10 -> V_39 || V_10 -> V_40 )
return V_80 ;
V_16 = F_7 ( V_10 , V_81 ,
( void * ) V_30 ) ;
if ( V_16 < 0 )
return V_80 ;
V_22 = F_11 ( V_10 , V_16 ) ;
V_22 -> V_11 = V_81 ;
V_22 -> V_82 . V_50 = V_16 ;
V_30 -> V_59 = F_27 ;
V_22 -> V_82 . V_47 . V_48 = V_32 -> V_48 ;
V_22 -> V_82 . V_47 . V_7 = V_32 -> V_7 ;
V_22 -> V_82 . V_47 . V_49 = V_32 -> V_49 ;
V_22 -> V_82 . V_83 = V_30 -> V_84 ;
memcpy ( V_22 -> V_82 . V_73 , V_72 , V_85 ) ;
V_22 -> V_82 . V_86 = F_28 ( V_30 ) ;
if ( V_22 -> V_82 . V_86 > V_10 -> V_87 )
V_10 -> V_87 = V_22 -> V_82 . V_86 ;
if ( F_29 ( V_30 ) > V_88 ) {
V_79 = V_80 ;
goto V_54;
}
V_78 = F_30 ( V_30 ) ;
F_31 (sglist, sg, scsi_sg_count(scsicmd), i) {
V_22 -> V_82 . V_89 [ V_75 ] . V_90 = F_32 ( V_77 ) ;
V_22 -> V_82 . V_89 [ V_75 ] . V_91 = V_77 -> V_91 ;
}
V_22 -> V_82 . V_92 = F_29 ( V_30 ) ;
V_71 = V_72 [ 0 ] ;
if ( ! F_14 ( V_10 -> V_51 -> V_52 ,
V_53 ,
V_22 ) ) {
V_79 = V_80 ;
goto V_54;
}
return 0 ;
V_54:
F_10 ( V_10 , V_16 ) ;
return V_79 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_61 * V_62 ;
struct V_61 * V_93 ;
struct V_9 * V_10 ;
struct V_69 * V_74 = (struct V_69 * ) V_32 -> V_34 ;
V_10 = (struct V_9 * ) V_74 -> V_35 ;
if ( ! V_10 )
return 0 ;
F_18 (vdisk, devdata, scsidev)
return 0 ;
V_93 = F_34 ( sizeof( * V_93 ) , V_94 ) ;
if ( ! V_93 )
return - V_95 ;
V_93 -> V_48 = V_32 -> V_48 ;
V_93 -> V_7 = V_32 -> V_7 ;
V_93 -> V_49 = V_32 -> V_49 ;
V_62 -> V_96 = V_93 ;
return 0 ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_61 * V_62 , * V_97 ;
struct V_9 * V_10 ;
struct V_69 * V_74 = (struct V_69 * ) V_32 -> V_34 ;
V_10 = (struct V_9 * ) V_74 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
V_97 = V_62 -> V_96 ;
V_62 -> V_96 = V_97 -> V_96 ;
F_36 ( V_97 ) ;
return;
}
}
static T_2 F_37 ( struct V_98 * V_98 , char T_3 * V_99 ,
T_4 V_100 , T_5 * V_101 )
{
T_2 V_102 = 0 ;
int V_103 = 0 ;
V_45 V_104 ;
int V_75 ;
struct V_9 * V_10 ;
char * V_105 ;
if ( V_100 > V_106 )
V_100 = V_106 ;
V_105 = F_34 ( V_100 , V_107 ) ;
if ( ! V_105 )
return - V_95 ;
for ( V_75 = 0 ; V_75 < V_108 ; V_75 ++ ) {
if ( ! V_109 [ V_75 ] . V_10 )
continue;
V_10 = V_109 [ V_75 ] . V_10 ;
V_103 += F_38 ( V_105 + V_103 ,
V_100 - V_103 , L_2 ,
V_10 -> V_87 ) ;
V_103 += F_38 ( V_105 + V_103 , V_100 - V_103 ,
L_3 ,
V_10 -> V_110 ,
V_10 -> V_111 ) ;
V_103 += F_38 ( V_105 + V_103 ,
V_100 - V_103 , L_4 ,
V_10 -> V_112 ) ;
V_104 = F_39 ( ( V_113 void * )
V_10 -> V_114 ) ;
V_103 += F_38 ( V_105 + V_103 , V_100 - V_103 ,
L_5 ,
V_10 -> V_114 , V_104 ,
( V_115 ) F_40 ( V_10 -> V_114 ) ) ;
V_103 += F_38 ( V_105 + V_103 ,
V_100 - V_103 , L_6 ,
V_10 -> V_116 ) ;
V_103 += F_38 ( V_105 + V_103 , V_100 - V_103 , L_7 ) ;
}
V_102 = F_41 ( V_99 , V_100 , V_101 , V_105 , V_103 ) ;
F_36 ( V_105 ) ;
return V_102 ;
}
static void F_42 ( struct V_9 * V_10 )
{
int V_75 ;
struct V_14 * V_117 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_24 * V_22 ;
unsigned long V_13 ;
F_43 ( V_10 -> V_118 . V_6 ) ;
F_8 ( & V_10 -> V_17 , V_13 ) ;
for ( V_75 = 0 ; V_75 < V_21 ; V_75 ++ ) {
V_117 = & V_10 -> V_19 [ V_75 ] ;
switch ( V_117 -> V_11 ) {
case V_81 :
V_30 = V_117 -> V_20 ;
V_30 -> V_56 = V_58 << 16 ;
if ( V_30 -> V_59 )
V_30 -> V_59 ( V_30 ) ;
break;
case V_42 :
V_22 = V_117 -> V_20 ;
V_22 -> V_43 . V_46
= V_119 ;
F_44 ( ( T_1 * )
V_22 -> V_43 . V_44 ) ;
break;
case V_120 :
V_22 = V_117 -> V_20 ;
V_22 -> V_121 . V_46
= V_122 ;
F_44 ( ( T_1 * )
V_22 -> V_121 . V_44 ) ;
break;
default:
break;
}
V_117 -> V_11 = 0 ;
V_117 -> V_20 = NULL ;
}
F_9 ( & V_10 -> V_17 , V_13 ) ;
V_10 -> V_39 = true ;
V_10 -> V_40 = false ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_39 && ! V_10 -> V_40 ) {
V_10 -> V_40 = true ;
F_42 ( V_10 ) ;
} else if ( V_10 -> V_40 ) {
return - V_123 ;
}
return 0 ;
}
static void
F_46 ( struct V_24 * V_22 , struct V_29 * V_30 )
{
struct V_9 * V_10 ;
struct V_61 * V_62 ;
struct V_31 * V_32 ;
struct V_124 * V_125 ;
V_32 = V_30 -> V_33 ;
memcpy ( V_30 -> V_126 , V_22 -> V_82 . V_127 , V_128 ) ;
V_125 = (struct V_124 * ) V_30 -> V_126 ;
if ( ( V_22 -> V_82 . V_73 [ 0 ] == V_129 ) &&
( F_47 ( V_22 -> V_82 . V_130 ) == V_131 ) &&
( V_22 -> V_82 . V_132 == V_133 ) )
return;
V_10 = (struct V_9 * ) V_32 -> V_34 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
if ( F_19 ( & V_62 -> V_63 ) < V_64 ) {
F_20 ( & V_62 -> V_63 ) ;
F_21 ( & V_62 -> V_65 , V_66 ) ;
}
}
}
static void
F_48 ( struct V_24 * V_22 , struct V_29 * V_30 )
{
struct V_31 * V_32 ;
unsigned char V_99 [ 36 ] ;
struct V_76 * V_77 ;
unsigned int V_75 ;
char * V_134 ;
char * V_135 ;
int V_136 = 0 ;
struct V_61 * V_62 ;
struct V_9 * V_10 ;
V_32 = V_30 -> V_33 ;
if ( ( V_22 -> V_82 . V_73 [ 0 ] == V_129 ) &&
( V_22 -> V_82 . V_86 >= V_137 ) ) {
if ( V_22 -> V_82 . V_138 == 0 )
return;
F_49 ( V_99 , V_22 -> V_82 . V_86 ,
V_32 -> V_49 ,
V_139 ,
V_140 ) ;
if ( F_29 ( V_30 ) == 0 ) {
memcpy ( F_30 ( V_30 ) , V_99 ,
V_22 -> V_82 . V_86 ) ;
return;
}
V_77 = F_30 ( V_30 ) ;
for ( V_75 = 0 ; V_75 < F_29 ( V_30 ) ; V_75 ++ ) {
V_135 = F_50 ( F_51 ( V_77 + V_75 ) ) ;
V_134 = ( void * ) ( ( unsigned long ) V_135 |
V_77 [ V_75 ] . V_101 ) ;
memcpy ( V_134 , V_99 + V_136 , V_77 [ V_75 ] . V_91 ) ;
F_52 ( V_135 ) ;
}
} else {
V_10 = (struct V_9 * ) V_32 -> V_34 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
if ( F_19 ( & V_62 -> V_65 ) > 0 ) {
F_53 ( & V_62 -> V_65 ) ;
if ( F_19 ( & V_62 -> V_65 ) == 0 )
F_21 ( & V_62 -> V_63 , 0 ) ;
}
}
}
}
static void
F_54 ( struct V_24 * V_22 , struct V_29 * V_30 )
{
V_30 -> V_56 = V_22 -> V_82 . V_130 ;
if ( V_22 -> V_82 . V_130 )
F_46 ( V_22 , V_30 ) ;
else
F_48 ( V_22 , V_30 ) ;
V_30 -> V_59 ( V_30 ) ;
}
static inline void F_55 ( struct V_24 * V_22 )
{
V_22 -> V_121 . V_46 = V_22 -> V_121 . V_56 ;
F_44 ( ( T_1 * ) V_22 -> V_121 . V_44 ) ;
}
static inline void F_56 ( struct V_24 * V_22 )
{
V_22 -> V_121 . V_46 = V_22 -> V_121 . V_56 ;
F_44 ( ( T_1 * ) V_22 -> V_43 . V_44 ) ;
}
static inline void F_57 ( struct V_141 * V_142 )
{
unsigned long V_13 ;
F_8 ( & V_143 , V_13 ) ;
if ( ! V_144 ) {
V_144 = V_142 ;
V_142 -> V_96 = NULL ;
} else {
V_142 -> V_96 = V_144 ;
V_144 = V_142 ;
}
if ( ! V_145 ) {
F_58 ( & V_146 ) ;
V_145 = 1 ;
}
F_9 ( & V_143 , V_13 ) ;
}
static void F_59 ( struct V_69 * V_147 ,
struct V_24 * V_22 )
{
struct V_141 * V_142 ;
V_142 = F_34 ( sizeof( * V_142 ) , V_94 ) ;
if ( V_142 ) {
V_142 -> V_148 = V_22 -> V_149 . V_148 ;
V_142 -> V_147 = V_147 ;
V_142 -> V_48 = V_22 -> V_149 . V_48 ;
V_142 -> V_7 = V_22 -> V_149 . V_7 ;
V_142 -> V_49 = V_22 -> V_149 . V_49 ;
F_57 ( V_142 ) ;
}
}
static void
F_60 ( struct V_24 * V_22 , struct V_9 * V_10 )
{
struct V_29 * V_30 ;
struct V_69 * V_147 = V_10 -> V_74 ;
while ( 1 ) {
if ( ! F_61 ( V_10 -> V_51 -> V_52 ,
V_150 ,
V_22 ) )
break;
if ( V_22 -> V_11 == V_81 ) {
V_30 = F_10 ( V_10 ,
V_22 -> V_82 . V_50 ) ;
if ( ! V_30 )
break;
F_54 ( V_22 , V_30 ) ;
} else if ( V_22 -> V_11 == V_42 ) {
if ( ! F_10 ( V_10 ,
V_22 -> V_43 . V_50 ) )
break;
F_56 ( V_22 ) ;
} else if ( V_22 -> V_11 == V_151 ) {
V_22 -> V_149 . V_152 = NULL ;
F_59 ( V_147 , V_22 ) ;
} else if ( V_22 -> V_11 == V_120 ) {
if ( ! F_10 ( V_10 ,
V_22 -> V_121 . V_50 ) )
break;
F_55 ( V_22 ) ;
}
}
}
static int F_62 ( void * V_153 )
{
struct V_9 * V_10 = V_153 ;
struct V_24 * V_22 = NULL ;
const int V_154 = sizeof( * V_22 ) ;
V_22 = F_63 ( V_154 , V_94 ) ;
if ( ! V_22 )
return - V_95 ;
while ( 1 ) {
if ( F_64 () )
break;
F_65 (
V_10 -> V_155 , ( F_19 (
& V_10 -> V_156 ) == 1 ) ,
F_16 ( V_10 -> V_157 ) ) ;
F_60 ( V_22 , V_10 ) ;
}
F_36 ( V_22 ) ;
return 0 ;
}
static int F_66 ( struct V_158 * V_51 ,
T_6 V_159 )
{
struct V_9 * V_10 = F_67 ( & V_51 -> V_33 ) ;
F_45 ( V_10 ) ;
V_159 ( V_51 , 0 ) ;
return 0 ;
}
static int F_68 ( struct V_158 * V_51 ,
T_6 V_159 )
{
struct V_9 * V_10 ;
V_10 = F_67 ( & V_51 -> V_33 ) ;
if ( ! V_10 )
return - V_123 ;
if ( V_10 -> V_39 && ! V_10 -> V_40 )
V_10 -> V_40 = 1 ;
F_1 ( & V_10 -> V_118 , F_62 ,
V_10 , L_8 ) ;
V_10 -> V_39 = false ;
V_10 -> V_40 = false ;
return 0 ;
}
static int F_69 ( struct V_158 * V_51 )
{
struct V_69 * V_74 ;
struct V_160 V_161 ;
struct V_9 * V_10 = NULL ;
int V_75 , V_79 , V_162 ;
V_45 V_163 ;
V_74 = F_70 ( & V_164 ,
sizeof( * V_10 ) ) ;
if ( ! V_74 )
return - V_165 ;
V_162 = F_71 ( struct V_166 ,
V_167 . V_161 ) ;
V_79 = F_72 ( V_51 , V_162 , & V_161 ,
sizeof( struct V_160 ) ) ;
if ( V_79 < 0 )
goto V_168;
V_74 -> V_169 = ( unsigned ) V_161 . V_169 ;
V_74 -> V_170 = ( unsigned ) V_161 . V_170 ;
V_74 -> V_171 = ( unsigned ) V_161 . V_171 ;
V_74 -> V_172 =
( unsigned short ) ( V_161 . V_173 >> 9 ) ;
V_74 -> V_174 =
( unsigned short ) ( V_161 . V_173 / V_175 ) ;
if ( V_74 -> V_174 > V_88 )
V_74 -> V_174 = V_88 ;
V_79 = F_73 ( V_74 , & V_51 -> V_33 ) ;
if ( V_79 < 0 )
goto V_168;
V_10 = (struct V_9 * ) V_74 -> V_35 ;
for ( V_75 = 0 ; V_75 < V_108 ; V_75 ++ ) {
if ( ! V_109 [ V_75 ] . V_10 ) {
V_109 [ V_75 ] . V_10 = V_10 ;
break;
}
}
V_10 -> V_51 = V_51 ;
F_74 ( & V_51 -> V_33 , V_10 ) ;
F_13 ( & V_10 -> V_155 ) ;
F_75 ( & V_10 -> V_17 ) ;
V_10 -> V_39 = false ;
V_10 -> V_40 = false ;
V_10 -> V_74 = V_74 ;
V_162 = F_71 ( struct V_166 ,
V_176 . V_163 ) ;
V_79 = F_72 ( V_51 , V_162 , & V_163 , 8 ) ;
if ( V_79 )
goto V_177;
V_163 |= V_178 ;
V_79 = F_76 ( V_51 , V_162 , & V_163 , 8 ) ;
if ( V_79 )
goto V_177;
V_10 -> V_157 = 2 ;
F_1 ( & V_10 -> V_118 , F_62 ,
V_10 , L_9 ) ;
F_77 ( V_74 ) ;
return 0 ;
V_177:
F_78 ( V_74 ) ;
V_168:
F_79 ( V_74 ) ;
return V_79 ;
}
static void F_80 ( struct V_158 * V_51 )
{
struct V_9 * V_10 = F_67 ( & V_51 -> V_33 ) ;
struct V_69 * V_74 = NULL ;
if ( ! V_10 )
return;
V_74 = V_10 -> V_74 ;
F_43 ( V_10 -> V_118 . V_6 ) ;
F_78 ( V_74 ) ;
F_79 ( V_74 ) ;
F_74 ( & V_51 -> V_33 , NULL ) ;
}
static int F_81 ( void )
{
struct V_179 * V_180 ;
int V_181 = - V_95 ;
V_182 = F_82 ( L_1 , NULL ) ;
if ( ! V_182 )
return - V_95 ;
V_180 = F_83 ( L_10 , V_183 , V_182 , NULL ,
& V_184 ) ;
if ( ! V_180 ) {
V_181 = - V_185 ;
goto V_186;
}
V_181 = F_84 ( & V_187 ) ;
if ( V_181 )
goto V_186;
return V_181 ;
V_186:
F_85 ( V_182 ) ;
return V_181 ;
}
static void F_86 ( void )
{
F_87 ( & V_187 ) ;
F_85 ( V_182 ) ;
}
