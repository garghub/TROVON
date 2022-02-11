static int F_1 ( struct V_1 * V_2 ,
int (* F_2)( void * ) ,
void * V_3 , char * V_4 )
{
F_3 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = F_4 ( F_2 , V_3 , L_1 , V_4 ) ;
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
V_30 -> V_56 = V_57 << 16 ;
else
V_30 -> V_56 = V_58 << 16 ;
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
return L_2 ;
}
static int
F_26 ( struct V_29 * V_30 ,
void (* F_27)( struct V_29 * ) )
{
struct V_24 * V_22 ;
struct V_31 * V_32 = V_30 -> V_33 ;
int V_16 ;
unsigned char * V_71 = V_30 -> V_72 ;
struct V_69 * V_73 = V_32 -> V_34 ;
unsigned int V_74 ;
struct V_9 * V_10 =
(struct V_9 * ) V_73 -> V_35 ;
struct V_75 * V_76 = NULL ;
struct V_75 * V_77 = NULL ;
if ( V_10 -> V_39 || V_10 -> V_40 )
return V_78 ;
V_16 = F_7 ( V_10 , V_79 ,
( void * ) V_30 ) ;
if ( V_16 < 0 )
return V_78 ;
V_22 = F_11 ( V_10 , V_16 ) ;
V_22 -> V_11 = V_79 ;
V_22 -> V_80 . V_50 = V_16 ;
V_30 -> V_59 = F_27 ;
V_22 -> V_80 . V_47 . V_48 = V_32 -> V_48 ;
V_22 -> V_80 . V_47 . V_7 = V_32 -> V_7 ;
V_22 -> V_80 . V_47 . V_49 = V_32 -> V_49 ;
V_22 -> V_80 . V_81 = V_30 -> V_82 ;
memcpy ( V_22 -> V_80 . V_72 , V_71 , V_83 ) ;
V_22 -> V_80 . V_84 = F_28 ( V_30 ) ;
if ( V_22 -> V_80 . V_84 > V_10 -> V_85 )
V_10 -> V_85 = V_22 -> V_80 . V_84 ;
if ( F_29 ( V_30 ) > V_86 )
goto V_54;
V_77 = F_30 ( V_30 ) ;
F_31 (sglist, sg, scsi_sg_count(scsicmd), i) {
V_22 -> V_80 . V_87 [ V_74 ] . V_88 = F_32 ( V_76 ) ;
V_22 -> V_80 . V_87 [ V_74 ] . V_89 = V_76 -> V_89 ;
}
V_22 -> V_80 . V_90 = F_29 ( V_30 ) ;
if ( ! F_14 ( V_10 -> V_51 -> V_52 ,
V_53 ,
V_22 ) )
goto V_54;
return 0 ;
V_54:
F_10 ( V_10 , V_16 ) ;
return V_78 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_61 * V_62 ;
struct V_61 * V_91 ;
struct V_9 * V_10 ;
struct V_69 * V_73 = (struct V_69 * ) V_32 -> V_34 ;
V_10 = (struct V_9 * ) V_73 -> V_35 ;
if ( ! V_10 )
return 0 ;
F_18 (vdisk, devdata, scsidev)
return 0 ;
V_91 = F_34 ( sizeof( * V_91 ) , V_92 ) ;
if ( ! V_91 )
return - V_93 ;
V_91 -> V_48 = V_32 -> V_48 ;
V_91 -> V_7 = V_32 -> V_7 ;
V_91 -> V_49 = V_32 -> V_49 ;
V_62 -> V_94 = V_91 ;
return 0 ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_61 * V_62 , * V_95 ;
struct V_9 * V_10 ;
struct V_69 * V_73 = (struct V_69 * ) V_32 -> V_34 ;
V_10 = (struct V_9 * ) V_73 -> V_35 ;
F_18 (vdisk, devdata, scsidev) {
V_95 = V_62 -> V_94 ;
V_62 -> V_94 = V_95 -> V_94 ;
F_36 ( V_95 ) ;
return;
}
}
static T_2 F_37 ( struct V_96 * V_96 , char T_3 * V_97 ,
T_4 V_98 , T_5 * V_99 )
{
T_2 V_100 = 0 ;
int V_101 = 0 ;
V_45 V_102 ;
int V_74 ;
struct V_9 * V_10 ;
char * V_103 ;
if ( V_98 > V_104 )
V_98 = V_104 ;
V_103 = F_34 ( V_98 , V_105 ) ;
if ( ! V_103 )
return - V_93 ;
for ( V_74 = 0 ; V_74 < V_106 ; V_74 ++ ) {
if ( ! V_107 [ V_74 ] . V_10 )
continue;
V_10 = V_107 [ V_74 ] . V_10 ;
V_101 += F_38 ( V_103 + V_101 ,
V_98 - V_101 , L_3 ,
V_10 -> V_85 ) ;
V_101 += F_38 ( V_103 + V_101 , V_98 - V_101 ,
L_4 ,
V_10 -> V_108 ,
V_10 -> V_109 ) ;
V_101 += F_38 ( V_103 + V_101 ,
V_98 - V_101 , L_5 ,
V_10 -> V_110 ) ;
V_102 = F_39 ( ( V_111 void * )
V_10 -> V_112 ) ;
V_101 += F_38 ( V_103 + V_101 , V_98 - V_101 ,
L_6 ,
V_10 -> V_112 , V_102 ,
( V_113 ) F_40 ( V_10 -> V_112 ) ) ;
V_101 += F_38 ( V_103 + V_101 ,
V_98 - V_101 , L_7 ,
V_10 -> V_114 ) ;
V_101 += F_38 ( V_103 + V_101 , V_98 - V_101 , L_8 ) ;
}
V_100 = F_41 ( V_97 , V_98 , V_99 , V_103 , V_101 ) ;
F_36 ( V_103 ) ;
return V_100 ;
}
static void F_42 ( struct V_9 * V_10 )
{
int V_74 ;
struct V_14 * V_115 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_24 * V_22 ;
unsigned long V_13 ;
F_43 ( V_10 -> V_116 . V_6 ) ;
F_8 ( & V_10 -> V_17 , V_13 ) ;
for ( V_74 = 0 ; V_74 < V_21 ; V_74 ++ ) {
V_115 = & V_10 -> V_19 [ V_74 ] ;
switch ( V_115 -> V_11 ) {
case V_79 :
V_30 = V_115 -> V_20 ;
V_30 -> V_56 = V_58 << 16 ;
if ( V_30 -> V_59 )
V_30 -> V_59 ( V_30 ) ;
break;
case V_42 :
V_22 = V_115 -> V_20 ;
V_22 -> V_43 . V_46
= V_117 ;
F_44 ( ( T_1 * )
V_22 -> V_43 . V_44 ) ;
break;
case V_118 :
V_22 = V_115 -> V_20 ;
V_22 -> V_119 . V_46
= V_120 ;
F_44 ( ( T_1 * )
V_22 -> V_119 . V_44 ) ;
break;
default:
break;
}
V_115 -> V_11 = 0 ;
V_115 -> V_20 = NULL ;
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
return - V_121 ;
}
return 0 ;
}
static void
F_46 ( struct V_24 * V_22 , struct V_29 * V_30 )
{
struct V_9 * V_10 ;
struct V_61 * V_62 ;
struct V_31 * V_32 ;
V_32 = V_30 -> V_33 ;
memcpy ( V_30 -> V_122 , V_22 -> V_80 . V_123 , V_124 ) ;
if ( ( V_22 -> V_80 . V_72 [ 0 ] == V_125 ) &&
( F_47 ( V_22 -> V_80 . V_126 ) == V_127 ) &&
( V_22 -> V_80 . V_128 == V_129 ) )
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
unsigned char V_97 [ 36 ] ;
struct V_75 * V_76 ;
unsigned int V_74 ;
char * V_130 ;
char * V_131 ;
int V_132 = 0 ;
struct V_61 * V_62 ;
struct V_9 * V_10 ;
V_32 = V_30 -> V_33 ;
if ( ( V_22 -> V_80 . V_72 [ 0 ] == V_125 ) &&
( V_22 -> V_80 . V_84 >= V_133 ) ) {
if ( V_22 -> V_80 . V_134 == 0 )
return;
F_49 ( V_97 , V_22 -> V_80 . V_84 ,
V_32 -> V_49 ,
V_135 ,
V_136 ) ;
if ( F_29 ( V_30 ) == 0 ) {
memcpy ( F_30 ( V_30 ) , V_97 ,
V_22 -> V_80 . V_84 ) ;
return;
}
V_76 = F_30 ( V_30 ) ;
for ( V_74 = 0 ; V_74 < F_29 ( V_30 ) ; V_74 ++ ) {
V_131 = F_50 ( F_51 ( V_76 + V_74 ) ) ;
V_130 = ( void * ) ( ( unsigned long ) V_131 |
V_76 [ V_74 ] . V_99 ) ;
memcpy ( V_130 , V_97 + V_132 , V_76 [ V_74 ] . V_89 ) ;
F_52 ( V_131 ) ;
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
V_30 -> V_56 = V_22 -> V_80 . V_126 ;
if ( V_22 -> V_80 . V_126 )
F_46 ( V_22 , V_30 ) ;
else
F_48 ( V_22 , V_30 ) ;
V_30 -> V_59 ( V_30 ) ;
}
static inline void F_55 ( struct V_24 * V_22 )
{
V_22 -> V_119 . V_46 = V_22 -> V_119 . V_56 ;
F_44 ( ( T_1 * ) V_22 -> V_119 . V_44 ) ;
}
static inline void F_56 ( struct V_24 * V_22 )
{
V_22 -> V_119 . V_46 = V_22 -> V_119 . V_56 ;
F_44 ( ( T_1 * ) V_22 -> V_43 . V_44 ) ;
}
static inline void F_57 ( struct V_137 * V_138 )
{
unsigned long V_13 ;
F_8 ( & V_139 , V_13 ) ;
if ( ! V_140 ) {
V_140 = V_138 ;
V_138 -> V_94 = NULL ;
} else {
V_138 -> V_94 = V_140 ;
V_140 = V_138 ;
}
if ( ! V_141 ) {
F_58 ( & V_142 ) ;
V_141 = 1 ;
}
F_9 ( & V_139 , V_13 ) ;
}
static void F_59 ( struct V_69 * V_143 ,
struct V_24 * V_22 )
{
struct V_137 * V_138 ;
V_138 = F_34 ( sizeof( * V_138 ) , V_92 ) ;
if ( V_138 ) {
V_138 -> V_144 = V_22 -> V_145 . V_144 ;
V_138 -> V_143 = V_143 ;
V_138 -> V_48 = V_22 -> V_145 . V_48 ;
V_138 -> V_7 = V_22 -> V_145 . V_7 ;
V_138 -> V_49 = V_22 -> V_145 . V_49 ;
F_57 ( V_138 ) ;
}
}
static void
F_60 ( struct V_24 * V_22 , struct V_9 * V_10 )
{
struct V_29 * V_30 ;
struct V_69 * V_143 = V_10 -> V_73 ;
while ( 1 ) {
if ( ! F_61 ( V_10 -> V_51 -> V_52 ,
V_146 ,
V_22 ) )
break;
if ( V_22 -> V_11 == V_79 ) {
V_30 = F_10 ( V_10 ,
V_22 -> V_80 . V_50 ) ;
if ( ! V_30 )
break;
F_54 ( V_22 , V_30 ) ;
} else if ( V_22 -> V_11 == V_42 ) {
if ( ! F_10 ( V_10 ,
V_22 -> V_43 . V_50 ) )
break;
F_56 ( V_22 ) ;
} else if ( V_22 -> V_11 == V_147 ) {
V_22 -> V_145 . V_148 = NULL ;
F_59 ( V_143 , V_22 ) ;
} else if ( V_22 -> V_11 == V_118 ) {
if ( ! F_10 ( V_10 ,
V_22 -> V_119 . V_50 ) )
break;
F_55 ( V_22 ) ;
}
}
}
static int F_62 ( void * V_149 )
{
struct V_9 * V_10 = V_149 ;
struct V_24 * V_22 = NULL ;
const int V_150 = sizeof( * V_22 ) ;
V_22 = F_63 ( V_150 , V_92 ) ;
if ( ! V_22 )
return - V_93 ;
while ( 1 ) {
if ( F_64 () )
break;
F_65 (
V_10 -> V_151 , ( F_19 (
& V_10 -> V_152 ) == 1 ) ,
F_16 ( V_10 -> V_153 ) ) ;
F_60 ( V_22 , V_10 ) ;
}
F_36 ( V_22 ) ;
return 0 ;
}
static int F_66 ( struct V_154 * V_51 ,
T_6 V_155 )
{
struct V_9 * V_10 = F_67 ( & V_51 -> V_33 ) ;
F_45 ( V_10 ) ;
V_155 ( V_51 , 0 ) ;
return 0 ;
}
static int F_68 ( struct V_154 * V_51 ,
T_6 V_155 )
{
struct V_9 * V_10 ;
V_10 = F_67 ( & V_51 -> V_33 ) ;
if ( ! V_10 )
return - V_121 ;
if ( V_10 -> V_39 && ! V_10 -> V_40 )
V_10 -> V_40 = true ;
F_1 ( & V_10 -> V_116 , F_62 ,
V_10 , L_9 ) ;
V_10 -> V_39 = false ;
V_10 -> V_40 = false ;
return 0 ;
}
static int F_69 ( struct V_154 * V_51 )
{
struct V_69 * V_73 ;
struct V_156 V_157 ;
struct V_9 * V_10 = NULL ;
int V_74 , V_158 , V_159 ;
V_45 V_160 ;
V_73 = F_70 ( & V_161 ,
sizeof( * V_10 ) ) ;
if ( ! V_73 )
return - V_162 ;
V_159 = F_71 ( struct V_163 ,
V_164 . V_157 ) ;
V_158 = F_72 ( V_51 , V_159 , & V_157 ,
sizeof( struct V_156 ) ) ;
if ( V_158 < 0 )
goto V_165;
V_73 -> V_166 = ( unsigned ) V_157 . V_166 ;
V_73 -> V_167 = ( unsigned ) V_157 . V_167 ;
V_73 -> V_168 = ( unsigned ) V_157 . V_168 ;
V_73 -> V_169 =
( unsigned short ) ( V_157 . V_170 >> 9 ) ;
V_73 -> V_171 =
( unsigned short ) ( V_157 . V_170 / V_172 ) ;
if ( V_73 -> V_171 > V_86 )
V_73 -> V_171 = V_86 ;
V_158 = F_73 ( V_73 , & V_51 -> V_33 ) ;
if ( V_158 < 0 )
goto V_165;
V_10 = (struct V_9 * ) V_73 -> V_35 ;
for ( V_74 = 0 ; V_74 < V_106 ; V_74 ++ ) {
if ( ! V_107 [ V_74 ] . V_10 ) {
V_107 [ V_74 ] . V_10 = V_10 ;
break;
}
}
V_10 -> V_51 = V_51 ;
F_74 ( & V_51 -> V_33 , V_10 ) ;
F_13 ( & V_10 -> V_151 ) ;
F_75 ( & V_10 -> V_17 ) ;
V_10 -> V_39 = false ;
V_10 -> V_40 = false ;
V_10 -> V_73 = V_73 ;
V_159 = F_71 ( struct V_163 ,
V_173 . V_160 ) ;
V_158 = F_72 ( V_51 , V_159 , & V_160 , 8 ) ;
if ( V_158 )
goto V_174;
V_160 |= V_175 ;
V_158 = F_76 ( V_51 , V_159 , & V_160 , 8 ) ;
if ( V_158 )
goto V_174;
V_10 -> V_153 = 2 ;
F_1 ( & V_10 -> V_116 , F_62 ,
V_10 , L_10 ) ;
F_77 ( V_73 ) ;
return 0 ;
V_174:
F_78 ( V_73 ) ;
V_165:
F_79 ( V_73 ) ;
return V_158 ;
}
static void F_80 ( struct V_154 * V_51 )
{
struct V_9 * V_10 = F_67 ( & V_51 -> V_33 ) ;
struct V_69 * V_73 = NULL ;
if ( ! V_10 )
return;
V_73 = V_10 -> V_73 ;
F_43 ( V_10 -> V_116 . V_6 ) ;
F_78 ( V_73 ) ;
F_79 ( V_73 ) ;
F_74 ( & V_51 -> V_33 , NULL ) ;
}
static int F_81 ( void )
{
struct V_176 * V_177 ;
int V_178 = - V_93 ;
V_179 = F_82 ( L_2 , NULL ) ;
if ( ! V_179 )
return - V_93 ;
V_177 = F_83 ( L_11 , V_180 , V_179 , NULL ,
& V_181 ) ;
if ( ! V_177 ) {
V_178 = - V_182 ;
goto V_183;
}
V_178 = F_84 ( & V_184 ) ;
if ( V_178 )
goto V_183;
return V_178 ;
V_183:
F_85 ( V_179 ) ;
return V_178 ;
}
static void F_86 ( void )
{
F_87 ( & V_184 ) ;
F_85 ( V_179 ) ;
}
