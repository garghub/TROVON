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
return - 1 ;
}
}
V_11 = & V_6 -> V_15 [ V_12 ] ;
memset ( & V_11 -> V_18 , 0 , sizeof( V_11 -> V_18 ) ) ;
V_11 -> V_7 = V_7 ;
if ( V_8 )
V_11 -> V_16 = V_8 ;
else
V_11 -> V_16 = & V_11 -> V_18 ;
V_6 -> V_14 = ( V_12 + 1 ) % V_17 ;
F_10 ( & V_6 -> V_13 , V_9 ) ;
return V_12 ;
}
static void * F_11 ( struct V_5 * V_6 ,
int V_19 )
{
unsigned long V_9 ;
void * V_16 ;
if ( V_19 >= V_17 )
return NULL ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
V_16 = V_6 -> V_15 [ V_19 ] . V_16 ;
V_6 -> V_15 [ V_19 ] . V_7 = 0 ;
V_6 -> V_15 [ V_19 ] . V_16 = NULL ;
F_10 ( & V_6 -> V_13 , V_9 ) ;
return V_16 ;
}
static struct V_20 * F_12 ( struct V_5 * V_21 ,
int V_22 )
{
if ( V_21 -> V_15 [ V_22 ] . V_16 )
return & V_21 -> V_15 [ V_22 ] . V_18 ;
return NULL ;
}
static int F_13 ( enum V_23 V_24 ,
struct V_25 * V_26 )
{
struct V_20 * V_18 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_5 * V_6 =
(struct V_5 * ) V_28 -> V_30 -> V_31 ;
int V_32 = 0xffff ;
T_1 V_33 ;
int V_34 = 0 ;
if ( V_6 -> V_35 || V_6 -> V_36 )
return V_37 ;
V_34 = F_8 ( V_6 , V_38 ,
NULL ) ;
if ( V_34 < 0 )
return V_37 ;
V_18 = F_12 ( V_6 , V_34 ) ;
F_14 ( & V_33 ) ;
V_18 -> V_7 = V_38 ;
V_18 -> V_39 . V_40 = ( V_41 ) & V_33 ;
V_18 -> V_39 . V_42 = ( V_41 ) & V_32 ;
V_18 -> V_39 . V_24 = V_24 ;
V_18 -> V_39 . V_43 . V_44 = V_28 -> V_44 ;
V_18 -> V_39 . V_43 . V_45 = V_28 -> V_45 ;
V_18 -> V_39 . V_43 . V_46 = V_28 -> V_46 ;
V_18 -> V_39 . V_47 = V_34 ;
if ( ! F_15 ( V_6 -> V_48 -> V_49 ,
V_50 ,
V_18 ) )
goto V_51;
if ( ! F_16 ( V_33 , V_32 != 0xffff ,
F_17 ( 45000 ) ) )
goto V_51;
if ( V_24 == V_52 )
V_26 -> V_53 = V_54 << 16 ;
else
V_26 -> V_53 = V_55 << 16 ;
V_26 -> V_56 ( V_26 ) ;
return V_57 ;
V_51:
F_11 ( V_6 , V_34 ) ;
return V_37 ;
}
static int F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_58 * V_59 ;
struct V_5 * V_6 ;
V_28 = V_26 -> V_29 ;
V_6 = (struct V_5 * ) V_28 -> V_30 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
if ( F_20 ( & V_59 -> V_60 ) < V_61 )
F_21 ( & V_59 -> V_60 ) ;
else
F_22 ( & V_59 -> V_62 , V_63 ) ;
}
return F_13 ( V_52 , V_26 ) ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_58 * V_59 ;
struct V_5 * V_6 ;
V_28 = V_26 -> V_29 ;
V_6 = (struct V_5 * ) V_28 -> V_30 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
if ( F_20 ( & V_59 -> V_60 ) < V_61 )
F_21 ( & V_59 -> V_60 ) ;
else
F_22 ( & V_59 -> V_62 , V_63 ) ;
}
return F_13 ( V_64 , V_26 ) ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_58 * V_59 ;
struct V_5 * V_6 ;
V_28 = V_26 -> V_29 ;
V_6 = (struct V_5 * ) V_28 -> V_30 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
if ( F_20 ( & V_59 -> V_60 ) < V_61 )
F_21 ( & V_59 -> V_60 ) ;
else
F_22 ( & V_59 -> V_62 , V_63 ) ;
}
return F_13 ( V_65 , V_26 ) ;
}
static int
F_25 ( struct V_25 * V_26 )
{
return V_57 ;
}
static const char * F_26 ( struct V_66 * V_67 )
{
return L_3 ;
}
static int
F_27 ( struct V_25 * V_26 ,
void (* F_28)( struct V_25 * ) )
{
struct V_20 * V_18 ;
struct V_27 * V_28 = V_26 -> V_29 ;
int V_12 ;
unsigned char * V_68 = V_26 -> V_69 ;
struct V_66 * V_70 = V_28 -> V_30 ;
unsigned int V_71 ;
struct V_5 * V_6 =
(struct V_5 * ) V_70 -> V_31 ;
struct V_72 * V_73 = NULL ;
struct V_72 * V_74 = NULL ;
if ( V_6 -> V_35 || V_6 -> V_36 )
return V_75 ;
V_12 = F_8 ( V_6 , V_76 ,
( void * ) V_26 ) ;
if ( V_12 < 0 )
return V_75 ;
V_18 = F_12 ( V_6 , V_12 ) ;
V_18 -> V_7 = V_76 ;
V_18 -> V_77 . V_47 = V_12 ;
V_26 -> V_56 = F_28 ;
V_18 -> V_77 . V_43 . V_44 = V_28 -> V_44 ;
V_18 -> V_77 . V_43 . V_45 = V_28 -> V_45 ;
V_18 -> V_77 . V_43 . V_46 = V_28 -> V_46 ;
V_18 -> V_77 . V_78 = V_26 -> V_79 ;
memcpy ( V_18 -> V_77 . V_69 , V_68 , V_80 ) ;
V_18 -> V_77 . V_81 = F_29 ( V_26 ) ;
if ( V_18 -> V_77 . V_81 > V_6 -> V_82 )
V_6 -> V_82 = V_18 -> V_77 . V_81 ;
if ( F_30 ( V_26 ) > V_83 )
goto V_51;
V_74 = F_31 ( V_26 ) ;
F_32 (sglist, sg, scsi_sg_count(scsicmd), i) {
V_18 -> V_77 . V_84 [ V_71 ] . V_85 = F_33 ( V_73 ) ;
V_18 -> V_77 . V_84 [ V_71 ] . V_86 = V_73 -> V_86 ;
}
V_18 -> V_77 . V_87 = F_30 ( V_26 ) ;
if ( ! F_15 ( V_6 -> V_48 -> V_49 ,
V_50 ,
V_18 ) )
goto V_51;
return 0 ;
V_51:
F_11 ( V_6 , V_12 ) ;
return V_75 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_58 * V_59 ;
struct V_58 * V_88 ;
struct V_5 * V_6 ;
struct V_66 * V_70 = (struct V_66 * ) V_28 -> V_30 ;
V_6 = (struct V_5 * ) V_70 -> V_31 ;
if ( ! V_6 )
return 0 ;
F_19 (vdisk, devdata, scsidev)
return 0 ;
V_88 = F_35 ( sizeof( * V_88 ) , V_89 ) ;
if ( ! V_88 )
return - V_90 ;
V_88 -> V_44 = V_28 -> V_44 ;
V_88 -> V_45 = V_28 -> V_45 ;
V_88 -> V_46 = V_28 -> V_46 ;
V_59 -> V_91 = V_88 ;
return 0 ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_58 * V_59 , * V_92 ;
struct V_5 * V_6 ;
struct V_66 * V_70 = (struct V_66 * ) V_28 -> V_30 ;
V_6 = (struct V_5 * ) V_70 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
V_92 = V_59 -> V_91 ;
V_59 -> V_91 = V_92 -> V_91 ;
F_37 ( V_92 ) ;
return;
}
}
static T_2 F_38 ( struct V_93 * V_93 , char T_3 * V_94 ,
T_4 V_95 , T_5 * V_96 )
{
T_2 V_97 = 0 ;
int V_98 = 0 ;
V_41 V_99 ;
int V_71 ;
struct V_5 * V_6 ;
char * V_100 ;
if ( V_95 > V_101 )
V_95 = V_101 ;
V_100 = F_35 ( V_95 , V_102 ) ;
if ( ! V_100 )
return - V_90 ;
for ( V_71 = 0 ; V_71 < V_103 ; V_71 ++ ) {
if ( ! V_104 [ V_71 ] . V_6 )
continue;
V_6 = V_104 [ V_71 ] . V_6 ;
V_98 += F_39 ( V_100 + V_98 ,
V_95 - V_98 , L_4 ,
V_6 -> V_82 ) ;
V_98 += F_39 ( V_100 + V_98 , V_95 - V_98 ,
L_5 ,
V_6 -> V_105 ,
V_6 -> V_106 ) ;
V_98 += F_39 ( V_100 + V_98 ,
V_95 - V_98 , L_6 ,
V_6 -> V_107 ) ;
V_99 = F_40 ( ( V_108 void * )
V_6 -> V_109 ) ;
V_98 += F_39 ( V_100 + V_98 , V_95 - V_98 ,
L_7 ,
V_6 -> V_109 , V_99 ,
( V_110 ) F_41 ( V_6 -> V_109 ) ) ;
V_98 += F_39 ( V_100 + V_98 ,
V_95 - V_98 , L_8 ,
V_6 -> V_111 ) ;
V_98 += F_39 ( V_100 + V_98 , V_95 - V_98 , L_9 ) ;
}
V_97 = F_42 ( V_94 , V_95 , V_96 , V_100 , V_98 ) ;
F_37 ( V_100 ) ;
return V_97 ;
}
static void F_43 ( struct V_5 * V_6 )
{
int V_71 ;
struct V_10 * V_112 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_20 * V_18 ;
unsigned long V_9 ;
F_6 ( V_6 -> V_113 ) ;
F_9 ( & V_6 -> V_13 , V_9 ) ;
for ( V_71 = 0 ; V_71 < V_17 ; V_71 ++ ) {
V_112 = & V_6 -> V_15 [ V_71 ] ;
switch ( V_112 -> V_7 ) {
case V_76 :
V_26 = V_112 -> V_16 ;
V_26 -> V_53 = V_55 << 16 ;
if ( V_26 -> V_56 )
V_26 -> V_56 ( V_26 ) ;
break;
case V_38 :
V_18 = V_112 -> V_16 ;
V_18 -> V_39 . V_42
= V_114 ;
F_44 ( ( T_1 * )
V_18 -> V_39 . V_40 ) ;
break;
case V_115 :
V_18 = V_112 -> V_16 ;
V_18 -> V_116 . V_42
= V_117 ;
F_44 ( ( T_1 * )
V_18 -> V_116 . V_40 ) ;
break;
default:
break;
}
V_112 -> V_7 = 0 ;
V_112 -> V_16 = NULL ;
}
F_10 ( & V_6 -> V_13 , V_9 ) ;
V_6 -> V_35 = true ;
V_6 -> V_36 = false ;
}
static int F_45 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_35 && ! V_6 -> V_36 ) {
V_6 -> V_36 = true ;
F_43 ( V_6 ) ;
} else if ( V_6 -> V_36 ) {
return - V_118 ;
}
return 0 ;
}
static void
F_46 ( struct V_20 * V_18 , struct V_25 * V_26 )
{
struct V_5 * V_6 ;
struct V_58 * V_59 ;
struct V_27 * V_28 ;
V_28 = V_26 -> V_29 ;
memcpy ( V_26 -> V_119 , V_18 -> V_77 . V_120 , V_121 ) ;
if ( ( V_18 -> V_77 . V_69 [ 0 ] == V_122 ) &&
( F_47 ( V_18 -> V_77 . V_123 ) == V_124 ) &&
( V_18 -> V_77 . V_125 == V_126 ) )
return;
V_6 = (struct V_5 * ) V_28 -> V_30 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
if ( F_20 ( & V_59 -> V_60 ) < V_61 ) {
F_21 ( & V_59 -> V_60 ) ;
F_22 ( & V_59 -> V_62 , V_63 ) ;
}
}
}
static int F_48 ( unsigned char * V_94 ,
T_4 V_95 , bool V_127 )
{
if ( ! V_94 || V_95 < V_128 )
return - V_118 ;
memset ( V_94 , 0 , V_128 ) ;
V_94 [ 2 ] = V_129 ;
if ( V_127 ) {
V_94 [ 0 ] = V_130 ;
V_94 [ 3 ] = V_131 ;
} else {
V_94 [ 0 ] = V_132 ;
}
V_94 [ 4 ] = V_128 - 5 ;
strncpy ( V_94 + 8 , L_10 , V_128 - 8 ) ;
return 0 ;
}
static void
F_49 ( struct V_20 * V_18 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
unsigned char V_94 [ 36 ] ;
struct V_72 * V_73 ;
unsigned int V_71 ;
char * V_133 ;
char * V_134 ;
int V_135 = 0 ;
struct V_58 * V_59 ;
struct V_5 * V_6 ;
V_28 = V_26 -> V_29 ;
if ( ( V_18 -> V_77 . V_69 [ 0 ] == V_122 ) &&
( V_18 -> V_77 . V_81 >= V_136 ) ) {
if ( V_18 -> V_77 . V_137 == 0 )
return;
F_48 ( V_94 , ( T_4 ) V_18 -> V_77 . V_81 ,
V_28 -> V_46 == 0 ) ;
if ( F_30 ( V_26 ) == 0 ) {
memcpy ( F_31 ( V_26 ) , V_94 ,
V_18 -> V_77 . V_81 ) ;
return;
}
V_73 = F_31 ( V_26 ) ;
for ( V_71 = 0 ; V_71 < F_30 ( V_26 ) ; V_71 ++ ) {
V_134 = F_50 ( F_51 ( V_73 + V_71 ) ) ;
V_133 = ( void * ) ( ( unsigned long ) V_134 |
V_73 [ V_71 ] . V_96 ) ;
memcpy ( V_133 , V_94 + V_135 , V_73 [ V_71 ] . V_86 ) ;
F_52 ( V_134 ) ;
}
} else {
V_6 = (struct V_5 * ) V_28 -> V_30 -> V_31 ;
F_19 (vdisk, devdata, scsidev) {
if ( F_20 ( & V_59 -> V_62 ) > 0 ) {
F_53 ( & V_59 -> V_62 ) ;
if ( F_20 ( & V_59 -> V_62 ) == 0 )
F_22 ( & V_59 -> V_60 , 0 ) ;
}
}
}
}
static void
F_54 ( struct V_20 * V_18 , struct V_25 * V_26 )
{
V_26 -> V_53 = V_18 -> V_77 . V_123 ;
if ( V_18 -> V_77 . V_123 )
F_46 ( V_18 , V_26 ) ;
else
F_49 ( V_18 , V_26 ) ;
V_26 -> V_56 ( V_26 ) ;
}
static inline void F_55 ( struct V_20 * V_18 )
{
V_18 -> V_116 . V_42 = V_18 -> V_116 . V_53 ;
F_44 ( ( T_1 * ) V_18 -> V_116 . V_40 ) ;
}
static inline void F_56 ( struct V_20 * V_18 )
{
V_18 -> V_116 . V_42 = V_18 -> V_116 . V_53 ;
F_44 ( ( T_1 * ) V_18 -> V_39 . V_40 ) ;
}
static inline void F_57 ( struct V_138 * V_139 )
{
unsigned long V_9 ;
F_9 ( & V_140 , V_9 ) ;
if ( ! V_141 ) {
V_141 = V_139 ;
V_139 -> V_91 = NULL ;
} else {
V_139 -> V_91 = V_141 ;
V_141 = V_139 ;
}
if ( ! V_142 ) {
F_58 ( & V_143 ) ;
V_142 = 1 ;
}
F_10 ( & V_140 , V_9 ) ;
}
static void F_59 ( struct V_66 * V_144 ,
struct V_20 * V_18 )
{
struct V_138 * V_139 ;
V_139 = F_35 ( sizeof( * V_139 ) , V_89 ) ;
if ( ! V_139 )
return;
V_139 -> V_145 = V_18 -> V_146 . V_145 ;
V_139 -> V_144 = V_144 ;
V_139 -> V_44 = V_18 -> V_146 . V_44 ;
V_139 -> V_45 = V_18 -> V_146 . V_45 ;
V_139 -> V_46 = V_18 -> V_146 . V_46 ;
F_57 ( V_139 ) ;
}
static void
F_60 ( struct V_20 * V_18 , struct V_5 * V_6 )
{
struct V_25 * V_26 ;
struct V_66 * V_144 = V_6 -> V_70 ;
while ( 1 ) {
if ( ! F_61 ( V_6 -> V_48 -> V_49 ,
V_147 ,
V_18 ) )
break;
if ( V_18 -> V_7 == V_76 ) {
V_26 = F_11 ( V_6 ,
V_18 -> V_77 . V_47 ) ;
if ( ! V_26 )
break;
F_54 ( V_18 , V_26 ) ;
} else if ( V_18 -> V_7 == V_38 ) {
if ( ! F_11 ( V_6 ,
V_18 -> V_39 . V_47 ) )
break;
F_56 ( V_18 ) ;
} else if ( V_18 -> V_7 == V_148 ) {
V_18 -> V_146 . V_149 = NULL ;
F_59 ( V_144 , V_18 ) ;
} else if ( V_18 -> V_7 == V_115 ) {
if ( ! F_11 ( V_6 ,
V_18 -> V_116 . V_47 ) )
break;
F_55 ( V_18 ) ;
}
}
}
static int F_62 ( void * V_150 )
{
struct V_5 * V_6 = V_150 ;
struct V_20 * V_18 = NULL ;
const int V_151 = sizeof( * V_18 ) ;
V_18 = F_63 ( V_151 , V_89 ) ;
if ( ! V_18 )
return - V_90 ;
while ( 1 ) {
if ( F_64 () )
break;
F_65 (
V_6 -> V_152 , ( F_20 (
& V_6 -> V_153 ) == 1 ) ,
F_17 ( V_6 -> V_154 ) ) ;
F_60 ( V_18 , V_6 ) ;
}
F_37 ( V_18 ) ;
return 0 ;
}
static int F_66 ( struct V_155 * V_48 ,
T_6 V_156 )
{
struct V_5 * V_6 = F_67 ( & V_48 -> V_29 ) ;
F_45 ( V_6 ) ;
V_156 ( V_48 , 0 ) ;
return 0 ;
}
static int F_68 ( struct V_155 * V_48 ,
T_6 V_156 )
{
struct V_5 * V_6 ;
V_6 = F_67 ( & V_48 -> V_29 ) ;
if ( ! V_6 )
return - V_118 ;
if ( V_6 -> V_35 && ! V_6 -> V_36 )
V_6 -> V_36 = true ;
V_6 -> V_113 = F_1 ( F_62 , V_6 ,
L_11 ) ;
V_6 -> V_35 = false ;
V_6 -> V_36 = false ;
return 0 ;
}
static int F_69 ( struct V_155 * V_48 )
{
struct V_66 * V_70 ;
struct V_157 V_158 ;
struct V_5 * V_6 = NULL ;
int V_71 , V_159 , V_160 ;
V_41 V_161 ;
V_70 = F_70 ( & V_162 ,
sizeof( * V_6 ) ) ;
if ( ! V_70 )
return - V_163 ;
V_160 = F_71 ( struct V_164 ,
V_165 . V_158 ) ;
V_159 = F_72 ( V_48 , V_160 , & V_158 ,
sizeof( struct V_157 ) ) ;
if ( V_159 < 0 )
goto V_166;
V_70 -> V_167 = ( unsigned ) V_158 . V_167 ;
V_70 -> V_168 = ( unsigned ) V_158 . V_168 ;
V_70 -> V_169 = ( unsigned ) V_158 . V_169 ;
V_70 -> V_170 =
( unsigned short ) ( V_158 . V_171 >> 9 ) ;
V_70 -> V_172 =
( unsigned short ) ( V_158 . V_171 / V_173 ) ;
if ( V_70 -> V_172 > V_83 )
V_70 -> V_172 = V_83 ;
V_159 = F_73 ( V_70 , & V_48 -> V_29 ) ;
if ( V_159 < 0 )
goto V_166;
V_6 = (struct V_5 * ) V_70 -> V_31 ;
for ( V_71 = 0 ; V_71 < V_103 ; V_71 ++ ) {
if ( ! V_104 [ V_71 ] . V_6 ) {
V_104 [ V_71 ] . V_6 = V_6 ;
break;
}
}
V_6 -> V_48 = V_48 ;
F_74 ( & V_48 -> V_29 , V_6 ) ;
F_14 ( & V_6 -> V_152 ) ;
F_75 ( & V_6 -> V_13 ) ;
V_6 -> V_35 = false ;
V_6 -> V_36 = false ;
V_6 -> V_70 = V_70 ;
V_160 = F_71 ( struct V_164 ,
V_174 . V_161 ) ;
V_159 = F_72 ( V_48 , V_160 , & V_161 , 8 ) ;
if ( V_159 )
goto V_175;
V_161 |= V_176 ;
V_159 = F_76 ( V_48 , V_160 , & V_161 , 8 ) ;
if ( V_159 )
goto V_175;
V_6 -> V_154 = 2 ;
V_6 -> V_113 = F_1 ( F_62 , V_6 ,
L_12 ) ;
F_77 ( V_70 ) ;
return 0 ;
V_175:
F_78 ( V_70 ) ;
V_166:
F_79 ( V_70 ) ;
return V_159 ;
}
static void F_80 ( struct V_155 * V_48 )
{
struct V_5 * V_6 = F_67 ( & V_48 -> V_29 ) ;
struct V_66 * V_70 = NULL ;
if ( ! V_6 )
return;
V_70 = V_6 -> V_70 ;
F_6 ( V_6 -> V_113 ) ;
F_78 ( V_70 ) ;
F_79 ( V_70 ) ;
F_74 ( & V_48 -> V_29 , NULL ) ;
}
static int F_81 ( void )
{
struct V_177 * V_178 ;
int V_179 = - V_90 ;
V_180 = F_82 ( L_3 , NULL ) ;
if ( ! V_180 )
return - V_90 ;
V_178 = F_83 ( L_13 , V_181 , V_180 , NULL ,
& V_182 ) ;
if ( ! V_178 ) {
V_179 = - V_183 ;
goto V_184;
}
V_179 = F_84 ( & V_185 ) ;
if ( V_179 )
goto V_184;
return V_179 ;
V_184:
F_85 ( V_180 ) ;
return V_179 ;
}
static void F_86 ( void )
{
F_87 ( & V_185 ) ;
F_85 ( V_180 ) ;
}
