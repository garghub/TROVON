static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_1 * V_6 , T_2 V_7 )
{
int V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
switch ( V_3 ) {
case V_11 :
case V_12 :
V_9 = F_2 ( V_2 -> V_13 , 0 ) ;
V_10 = ( V_14 | V_15 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_9 = F_3 ( V_2 -> V_13 , 0 ) ;
V_10 = ( V_14 | V_24 ) ;
break;
default:
F_4 ( V_2 -> V_25 , L_1 , V_3 ) ;
V_8 = - V_26 ;
goto V_27;
}
if ( ! ( V_10 & V_24 ) )
memcpy ( V_2 -> V_28 , V_6 , V_7 ) ;
V_8 = F_5 ( V_2 -> V_13 , V_9 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_28 , V_7 , 1000 ) ;
F_6 ( V_2 -> V_25 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_28 , V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_25 , L_2 ,
V_8 , V_3 ) ;
goto V_27;
}
if ( V_10 & V_24 )
memcpy ( V_6 , V_2 -> V_28 , V_7 ) ;
return 0 ;
V_27:
return V_8 ;
}
static struct V_29 * F_7 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
struct V_29 * V_28 = NULL ;
F_8 ( & V_2 -> V_31 , V_30 ) ;
if ( F_9 ( & V_2 -> V_32 ) )
goto V_33;
V_28 = F_10 ( V_2 -> V_32 . V_34 ,
struct V_29 , V_35 ) ;
F_11 ( & V_28 -> V_35 ) ;
V_33:
F_12 ( & V_2 -> V_31 , V_30 ) ;
return V_28 ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
void * V_36 , void * V_37 , unsigned int V_38 )
{
unsigned int V_39 ;
if ( V_2 -> V_40 == V_41 ) {
memcpy ( V_36 , V_37 , V_38 ) ;
V_39 = V_38 ;
} else {
V_39 = 0 ;
}
if ( F_14 ( F_15 ( V_2 -> V_42 ) ) ) {
#define F_16 10000UL
unsigned int V_43 = F_17 ( V_44 -
V_2 -> V_42 + F_18 ( F_16 ) ) ;
unsigned int V_45 = V_2 -> V_46 - V_2 -> V_47 ;
V_2 -> V_42 = V_44 + F_18 ( F_16 ) ;
V_2 -> V_47 = V_2 -> V_46 ;
F_19 ( V_2 -> V_25 , L_3 ,
V_38 , V_45 , V_43 ,
V_45 * 1000UL / V_43 ) ;
}
V_2 -> V_46 += V_38 / 2 ;
return V_39 ;
}
static void F_20 ( struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_29 * V_50 ;
F_21 ( V_2 -> V_25 , L_4 ,
V_48 -> V_51 , V_48 -> V_52 ,
V_48 -> V_53 , V_48 -> V_54 ) ;
switch ( V_48 -> V_51 ) {
case 0 :
case - V_55 :
break;
case - V_56 :
case - V_57 :
case - V_58 :
return;
default:
F_22 ( V_2 -> V_25 , L_5 , V_48 -> V_51 ) ;
break;
}
if ( F_23 ( V_48 -> V_52 > 0 ) ) {
void * V_59 ;
unsigned int V_60 ;
V_50 = F_7 ( V_2 ) ;
if ( F_14 ( V_50 == NULL ) ) {
V_2 -> V_61 ++ ;
F_24 ( V_2 -> V_25 ,
L_6 ,
V_2 -> V_61 ) ;
goto V_62;
}
V_59 = F_25 ( & V_50 -> V_63 . V_64 , 0 ) ;
V_60 = F_13 ( V_2 , V_59 , V_48 -> V_65 ,
V_48 -> V_52 ) ;
F_26 ( & V_50 -> V_63 . V_64 , 0 , V_60 ) ;
V_50 -> V_63 . V_64 . V_66 = F_27 () ;
V_50 -> V_63 . V_67 = V_2 -> V_67 ++ ;
F_28 ( & V_50 -> V_63 . V_64 , V_68 ) ;
}
V_62:
F_29 ( V_48 , V_69 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = V_2 -> V_71 - 1 ; V_70 >= 0 ; V_70 -- ) {
F_19 ( V_2 -> V_25 , L_7 , V_70 ) ;
F_31 ( V_2 -> V_72 [ V_70 ] ) ;
}
V_2 -> V_71 = 0 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_70 , V_8 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_73 ; V_70 ++ ) {
F_19 ( V_2 -> V_25 , L_8 , V_70 ) ;
V_8 = F_29 ( V_2 -> V_72 [ V_70 ] , V_69 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_25 , L_9 ,
V_70 ) ;
F_30 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_71 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( F_34 ( V_74 , & V_2 -> V_30 ) ) {
while ( V_2 -> V_75 ) {
V_2 -> V_75 -- ;
F_19 ( V_2 -> V_25 , L_10 , V_2 -> V_75 ) ;
F_35 ( V_2 -> V_13 , V_2 -> V_76 ,
V_2 -> V_77 [ V_2 -> V_75 ] ,
V_2 -> V_78 [ V_2 -> V_75 ] ) ;
}
}
F_36 ( V_74 , & V_2 -> V_30 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_75 = 0 ;
V_2 -> V_76 = V_79 ;
F_19 ( V_2 -> V_25 , L_11 ,
V_80 * V_79 ) ;
for ( V_2 -> V_75 = 0 ; V_2 -> V_75 < V_80 ; V_2 -> V_75 ++ ) {
V_2 -> V_77 [ V_2 -> V_75 ] = F_38 ( V_2 -> V_13 ,
V_79 , V_69 ,
& V_2 -> V_78 [ V_2 -> V_75 ] ) ;
if ( ! V_2 -> V_77 [ V_2 -> V_75 ] ) {
F_19 ( V_2 -> V_25 , L_12 , V_2 -> V_75 ) ;
F_33 ( V_2 ) ;
return - V_81 ;
}
F_19 ( V_2 -> V_25 , L_13 , V_2 -> V_75 ,
V_2 -> V_77 [ V_2 -> V_75 ] ,
( long long ) V_2 -> V_78 [ V_2 -> V_75 ] ) ;
F_39 ( V_74 , & V_2 -> V_30 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_70 ;
F_30 ( V_2 ) ;
for ( V_70 = V_2 -> V_73 - 1 ; V_70 >= 0 ; V_70 -- ) {
if ( V_2 -> V_72 [ V_70 ] ) {
F_19 ( V_2 -> V_25 , L_14 , V_70 ) ;
F_41 ( V_2 -> V_72 [ V_70 ] ) ;
}
}
V_2 -> V_73 = 0 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_70 , V_82 ;
for ( V_70 = 0 ; V_70 < V_80 ; V_70 ++ ) {
F_19 ( V_2 -> V_25 , L_15 , V_70 ) ;
V_2 -> V_72 [ V_70 ] = F_43 ( 0 , V_69 ) ;
if ( ! V_2 -> V_72 [ V_70 ] ) {
for ( V_82 = 0 ; V_82 < V_70 ; V_82 ++ )
F_41 ( V_2 -> V_72 [ V_82 ] ) ;
return - V_81 ;
}
F_44 ( V_2 -> V_72 [ V_70 ] ,
V_2 -> V_13 ,
F_45 ( V_2 -> V_13 , 0x81 ) ,
V_2 -> V_77 [ V_70 ] ,
V_79 ,
F_20 , V_2 ) ;
V_2 -> V_72 [ V_70 ] -> V_83 = V_84 ;
V_2 -> V_72 [ V_70 ] -> V_85 = V_2 -> V_78 [ V_70 ] ;
V_2 -> V_73 ++ ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
F_19 ( V_2 -> V_25 , L_16 ) ;
F_8 ( & V_2 -> V_31 , V_30 ) ;
while ( ! F_9 ( & V_2 -> V_32 ) ) {
struct V_29 * V_28 ;
V_28 = F_10 ( V_2 -> V_32 . V_34 ,
struct V_29 , V_35 ) ;
F_11 ( & V_28 -> V_35 ) ;
F_28 ( & V_28 -> V_63 . V_64 , V_86 ) ;
}
F_12 ( & V_2 -> V_31 , V_30 ) ;
}
static void F_47 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_48 ( V_88 ) ;
struct V_1 * V_2 = F_49 ( V_90 , struct V_1 , V_91 ) ;
F_19 ( V_2 -> V_25 , L_16 ) ;
F_50 ( & V_2 -> V_92 ) ;
F_50 ( & V_2 -> V_93 ) ;
V_2 -> V_13 = NULL ;
F_51 ( & V_2 -> V_91 ) ;
F_52 ( & V_2 -> V_94 ) ;
F_53 ( & V_2 -> V_93 ) ;
F_53 ( & V_2 -> V_92 ) ;
F_54 ( & V_2 -> V_91 ) ;
}
static int F_55 ( struct V_95 * V_96 ,
unsigned int * V_97 ,
unsigned int * V_98 , unsigned int V_99 [] , struct V_100 * V_101 [] )
{
struct V_1 * V_2 = F_56 ( V_96 ) ;
F_19 ( V_2 -> V_25 , L_17 , * V_97 ) ;
if ( V_96 -> V_102 + * V_97 < 8 )
* V_97 = 8 - V_96 -> V_102 ;
* V_98 = 1 ;
V_99 [ 0 ] = F_57 ( V_2 -> V_103 ) ;
F_19 ( V_2 -> V_25 , L_18 , * V_97 , V_99 [ 0 ] ) ;
return 0 ;
}
static void F_58 ( struct V_104 * V_63 )
{
struct V_105 * V_106 = F_59 ( V_63 ) ;
struct V_1 * V_2 = F_56 ( V_63 -> V_95 ) ;
struct V_29 * V_28 =
F_49 ( V_106 , struct V_29 , V_63 ) ;
unsigned long V_30 ;
if ( F_14 ( ! V_2 -> V_13 ) ) {
F_28 ( & V_28 -> V_63 . V_64 , V_86 ) ;
return;
}
F_8 ( & V_2 -> V_31 , V_30 ) ;
F_60 ( & V_28 -> V_35 , & V_2 -> V_32 ) ;
F_12 ( & V_2 -> V_31 , V_30 ) ;
}
static int F_61 ( struct V_95 * V_96 , unsigned int V_107 )
{
struct V_1 * V_2 = F_56 ( V_96 ) ;
int V_8 ;
F_19 ( V_2 -> V_25 , L_16 ) ;
if ( ! V_2 -> V_13 )
return - V_108 ;
F_50 ( & V_2 -> V_93 ) ;
V_2 -> V_67 = 0 ;
F_39 ( V_109 , & V_2 -> V_30 ) ;
V_8 = F_37 ( V_2 ) ;
if ( V_8 )
goto V_110;
V_8 = F_42 ( V_2 ) ;
if ( V_8 )
goto V_111;
V_8 = F_32 ( V_2 ) ;
if ( V_8 )
goto V_112;
V_8 = F_1 ( V_2 , V_11 , 1 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_113;
goto V_114;
V_113:
F_30 ( V_2 ) ;
V_112:
F_40 ( V_2 ) ;
V_111:
F_33 ( V_2 ) ;
V_110:
F_36 ( V_109 , & V_2 -> V_30 ) ;
{
struct V_29 * V_28 , * V_115 ;
F_62 (buf, tmp, &s->queued_bufs, list) {
F_11 ( & V_28 -> V_35 ) ;
F_28 ( & V_28 -> V_63 . V_64 ,
V_116 ) ;
}
}
V_114:
F_53 ( & V_2 -> V_93 ) ;
return V_8 ;
}
static void F_63 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_56 ( V_96 ) ;
F_19 ( V_2 -> V_25 , L_16 ) ;
F_50 ( & V_2 -> V_93 ) ;
F_1 ( V_2 , V_11 , 0 , 0 , NULL , 0 ) ;
F_30 ( V_2 ) ;
F_40 ( V_2 ) ;
F_33 ( V_2 ) ;
F_46 ( V_2 ) ;
F_36 ( V_109 , & V_2 -> V_30 ) ;
F_53 ( & V_2 -> V_93 ) ;
}
static int F_64 ( struct V_117 * V_117 , void * V_118 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_65 ( V_117 ) ;
F_66 ( V_120 -> V_121 , V_122 , sizeof( V_120 -> V_121 ) ) ;
F_66 ( V_120 -> V_123 , V_2 -> V_94 . V_124 , sizeof( V_120 -> V_123 ) ) ;
F_67 ( V_2 -> V_13 , V_120 -> V_125 , sizeof( V_120 -> V_125 ) ) ;
V_120 -> V_126 = V_127 | V_128 |
V_129 | V_130 ;
V_120 -> V_131 = V_120 -> V_126 | V_132 ;
return 0 ;
}
static int F_68 ( struct V_117 * V_117 , void * V_133 ,
struct V_134 * V_135 )
{
if ( V_135 -> V_5 >= V_136 )
return - V_26 ;
F_66 ( V_135 -> V_137 , V_138 [ V_135 -> V_5 ] . V_124 , sizeof( V_135 -> V_137 ) ) ;
V_135 -> V_40 = V_138 [ V_135 -> V_5 ] . V_40 ;
return 0 ;
}
static int F_69 ( struct V_117 * V_117 , void * V_133 ,
struct V_139 * V_135 )
{
struct V_1 * V_2 = F_65 ( V_117 ) ;
V_135 -> V_140 . V_141 . V_40 = V_2 -> V_40 ;
V_135 -> V_140 . V_141 . V_103 = V_2 -> V_103 ;
memset ( V_135 -> V_140 . V_141 . V_142 , 0 , sizeof( V_135 -> V_140 . V_141 . V_142 ) ) ;
return 0 ;
}
static int F_70 ( struct V_117 * V_117 , void * V_133 ,
struct V_139 * V_135 )
{
struct V_1 * V_2 = F_65 ( V_117 ) ;
struct V_95 * V_143 = & V_2 -> V_144 ;
int V_70 ;
if ( F_71 ( V_143 ) )
return - V_145 ;
memset ( V_135 -> V_140 . V_141 . V_142 , 0 , sizeof( V_135 -> V_140 . V_141 . V_142 ) ) ;
for ( V_70 = 0 ; V_70 < V_136 ; V_70 ++ ) {
if ( V_138 [ V_70 ] . V_40 == V_135 -> V_140 . V_141 . V_40 ) {
V_2 -> V_40 = V_138 [ V_70 ] . V_40 ;
V_2 -> V_103 = V_138 [ V_70 ] . V_103 ;
V_135 -> V_140 . V_141 . V_103 = V_138 [ V_70 ] . V_103 ;
return 0 ;
}
}
V_2 -> V_40 = V_138 [ 0 ] . V_40 ;
V_2 -> V_103 = V_138 [ 0 ] . V_103 ;
V_135 -> V_140 . V_141 . V_40 = V_138 [ 0 ] . V_40 ;
V_135 -> V_140 . V_141 . V_103 = V_138 [ 0 ] . V_103 ;
return 0 ;
}
static int F_72 ( struct V_117 * V_117 , void * V_133 ,
struct V_139 * V_135 )
{
int V_70 ;
memset ( V_135 -> V_140 . V_141 . V_142 , 0 , sizeof( V_135 -> V_140 . V_141 . V_142 ) ) ;
for ( V_70 = 0 ; V_70 < V_136 ; V_70 ++ ) {
if ( V_138 [ V_70 ] . V_40 == V_135 -> V_140 . V_141 . V_40 ) {
V_135 -> V_140 . V_141 . V_103 = V_138 [ V_70 ] . V_103 ;
return 0 ;
}
}
V_135 -> V_140 . V_141 . V_40 = V_138 [ 0 ] . V_40 ;
V_135 -> V_140 . V_141 . V_103 = V_138 [ 0 ] . V_103 ;
return 0 ;
}
static int F_73 ( struct V_117 * V_117 , void * V_133 ,
const struct V_146 * V_90 )
{
int V_8 ;
if ( V_90 -> V_5 == 0 )
V_8 = 0 ;
else if ( V_90 -> V_5 == 1 )
V_8 = 0 ;
else
V_8 = - V_26 ;
return V_8 ;
}
static int F_74 ( struct V_117 * V_117 , void * V_133 , struct V_146 * V_90 )
{
int V_8 ;
if ( V_90 -> V_5 == 0 ) {
F_66 ( V_90 -> V_124 , L_19 , sizeof( V_90 -> V_124 ) ) ;
V_90 -> type = V_147 ;
V_90 -> V_148 = V_149 | V_150 ;
V_90 -> V_151 = V_152 [ 0 ] . V_151 ;
V_90 -> V_153 = V_152 [ 0 ] . V_153 ;
V_8 = 0 ;
} else if ( V_90 -> V_5 == 1 ) {
F_66 ( V_90 -> V_124 , L_20 , sizeof( V_90 -> V_124 ) ) ;
V_90 -> type = V_154 ;
V_90 -> V_148 = V_149 | V_150 ;
V_90 -> V_151 = V_155 [ 0 ] . V_151 ;
V_90 -> V_153 = V_155 [ 0 ] . V_153 ;
V_8 = 0 ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_75 ( struct V_117 * V_117 , void * V_133 ,
struct V_156 * V_135 )
{
struct V_1 * V_2 = F_65 ( V_117 ) ;
int V_8 ;
if ( V_135 -> V_157 == 0 ) {
V_135 -> type = V_147 ;
V_135 -> V_158 = V_2 -> V_159 ;
F_19 ( V_2 -> V_25 , L_21 , V_2 -> V_159 ) ;
V_8 = 0 ;
} else if ( V_135 -> V_157 == 1 ) {
V_135 -> type = V_154 ;
V_135 -> V_158 = V_2 -> V_160 ;
F_19 ( V_2 -> V_25 , L_22 , V_2 -> V_160 ) ;
V_8 = 0 ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_76 ( struct V_117 * V_117 , void * V_133 ,
const struct V_156 * V_135 )
{
struct V_1 * V_2 = F_65 ( V_117 ) ;
int V_8 ;
T_1 V_28 [ 4 ] ;
if ( V_135 -> V_157 == 0 ) {
V_2 -> V_159 = F_77 (unsigned int, f->frequency,
bands[0].rangelow,
bands[0].rangehigh) ;
F_19 ( V_2 -> V_25 , L_21 , V_2 -> V_159 ) ;
V_8 = 0 ;
} else if ( V_135 -> V_157 == 1 ) {
V_2 -> V_160 = F_77 (unsigned int, f->frequency,
bands_rf[0].rangelow,
bands_rf[0].rangehigh) ;
F_19 ( V_2 -> V_25 , L_22 , V_2 -> V_160 ) ;
V_28 [ 0 ] = ( V_2 -> V_160 >> 0 ) & 0xff ;
V_28 [ 1 ] = ( V_2 -> V_160 >> 8 ) & 0xff ;
V_28 [ 2 ] = ( V_2 -> V_160 >> 16 ) & 0xff ;
V_28 [ 3 ] = ( V_2 -> V_160 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_12 , 0 , 0 , V_28 , 4 ) ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_78 ( struct V_117 * V_117 , void * V_133 ,
struct V_161 * V_162 )
{
int V_8 ;
if ( V_162 -> V_157 == 0 ) {
if ( V_162 -> V_5 >= F_79 ( V_152 ) ) {
V_8 = - V_26 ;
} else {
* V_162 = V_152 [ V_162 -> V_5 ] ;
V_8 = 0 ;
}
} else if ( V_162 -> V_157 == 1 ) {
if ( V_162 -> V_5 >= F_79 ( V_155 ) ) {
V_8 = - V_26 ;
} else {
* V_162 = V_155 [ V_162 -> V_5 ] ;
V_8 = 0 ;
}
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static void F_80 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_49 ( V_90 , struct V_1 , V_91 ) ;
F_81 ( & V_2 -> V_163 ) ;
F_82 ( & V_2 -> V_91 ) ;
F_83 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_164 ;
F_19 ( V_2 -> V_25 , L_23 ,
V_2 -> V_165 -> V_166 . V_167 , V_2 -> V_165 -> V_167 ,
V_2 -> V_168 -> V_166 . V_167 , V_2 -> V_168 -> V_167 ) ;
V_8 = F_1 ( V_2 , V_22 , 0 , V_2 -> V_165 -> V_167 ,
& V_164 , 1 ) ;
if ( V_8 )
goto V_27;
if ( V_2 -> V_165 -> V_167 == false ) {
V_8 = F_1 ( V_2 , V_19 , 0 , V_2 -> V_168 -> V_167 ,
& V_164 , 1 ) ;
if ( V_8 )
goto V_27;
}
V_27:
if ( V_8 )
F_19 ( V_2 -> V_25 , L_24 , V_8 ) ;
return V_8 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_164 ;
F_19 ( V_2 -> V_25 , L_25 ,
V_2 -> V_169 -> V_166 . V_167 , V_2 -> V_169 -> V_167 ,
V_2 -> V_170 -> V_166 . V_167 , V_2 -> V_170 -> V_167 ) ;
V_8 = F_1 ( V_2 , V_23 , 0 , V_2 -> V_169 -> V_167 ,
& V_164 , 1 ) ;
if ( V_8 )
goto V_27;
if ( V_2 -> V_169 -> V_167 == false ) {
V_8 = F_1 ( V_2 , V_20 , 0 ,
V_2 -> V_170 -> V_167 , & V_164 , 1 ) ;
if ( V_8 )
goto V_27;
}
V_27:
if ( V_8 )
F_19 ( V_2 -> V_25 , L_24 , V_8 ) ;
return V_8 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_164 ;
F_19 ( V_2 -> V_25 , L_26 , V_2 -> V_171 -> V_166 . V_167 , V_2 -> V_171 -> V_167 ) ;
V_8 = F_1 ( V_2 , V_21 , 0 , V_2 -> V_171 -> V_167 ,
& V_164 , 1 ) ;
if ( V_8 )
F_19 ( V_2 -> V_25 , L_24 , V_8 ) ;
return V_8 ;
}
static int F_87 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_49 ( V_173 -> V_174 , struct V_1 , V_163 ) ;
int V_8 ;
switch ( V_173 -> V_175 ) {
case V_176 :
case V_177 :
V_8 = F_84 ( V_2 ) ;
break;
case V_178 :
case V_179 :
V_8 = F_85 ( V_2 ) ;
break;
case V_180 :
V_8 = F_86 ( V_2 ) ;
break;
default:
F_19 ( V_2 -> V_25 , L_27 ,
V_173 -> V_175 , V_173 -> V_124 ) ;
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_88 ( struct V_87 * V_88 ,
const struct V_181 * V_175 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_164 , V_28 [ V_182 ] ;
V_2 = F_89 ( sizeof( struct V_1 ) , V_183 ) ;
if ( V_2 == NULL ) {
F_4 ( & V_88 -> V_25 , L_28 ) ;
return - V_81 ;
}
F_90 ( & V_2 -> V_93 ) ;
F_90 ( & V_2 -> V_92 ) ;
F_91 ( & V_2 -> V_31 ) ;
F_92 ( & V_2 -> V_32 ) ;
V_2 -> V_25 = & V_88 -> V_25 ;
V_2 -> V_13 = F_93 ( V_88 ) ;
V_2 -> V_159 = V_152 [ 0 ] . V_151 ;
V_2 -> V_160 = V_155 [ 0 ] . V_151 ;
V_2 -> V_40 = V_138 [ 0 ] . V_40 ;
V_2 -> V_103 = V_138 [ 0 ] . V_103 ;
V_8 = F_1 ( V_2 , V_16 , 0 , 0 , & V_164 , 1 ) ;
if ( V_8 == 0 )
V_8 = F_1 ( V_2 , V_17 , 0 , 0 ,
V_28 , V_182 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_25 , L_29 ) ;
goto V_184;
}
V_28 [ V_182 - 1 ] = '\0' ;
F_94 ( V_2 -> V_25 , L_30 , V_164 ) ;
F_94 ( V_2 -> V_25 , L_31 , V_28 ) ;
V_2 -> V_144 . type = V_185 ;
V_2 -> V_144 . V_186 = V_187 | V_188 | V_189 ;
V_2 -> V_144 . V_190 = V_2 ;
V_2 -> V_144 . V_191 = sizeof( struct V_29 ) ;
V_2 -> V_144 . V_192 = & V_193 ;
V_2 -> V_144 . V_194 = & V_195 ;
V_2 -> V_144 . V_196 = V_197 ;
V_8 = F_95 ( & V_2 -> V_144 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_25 , L_32 ) ;
goto V_184;
}
V_2 -> V_94 = V_198 ;
V_2 -> V_94 . V_199 = & V_2 -> V_144 ;
V_2 -> V_94 . V_199 -> V_200 = & V_2 -> V_92 ;
F_96 ( & V_2 -> V_94 , V_2 ) ;
V_2 -> V_91 . V_201 = F_80 ;
V_8 = F_97 ( & V_88 -> V_25 , & V_2 -> V_91 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_25 , L_33 , V_8 ) ;
goto V_184;
}
F_98 ( & V_2 -> V_163 , 5 ) ;
V_2 -> V_165 = F_99 ( & V_2 -> V_163 , & V_202 ,
V_176 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_168 = F_99 ( & V_2 -> V_163 , & V_202 ,
V_177 , 0 , 14 , 1 , 8 ) ;
F_100 ( 2 , & V_2 -> V_165 , 0 , false ) ;
V_2 -> V_169 = F_99 ( & V_2 -> V_163 , & V_202 ,
V_178 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_170 = F_99 ( & V_2 -> V_163 , & V_202 ,
V_179 , 0 , 15 , 1 , 8 ) ;
F_100 ( 2 , & V_2 -> V_169 , 0 , false ) ;
V_2 -> V_171 = F_99 ( & V_2 -> V_163 , & V_202 ,
V_180 , 0 , 15 , 1 , 0 ) ;
if ( V_2 -> V_163 . error ) {
V_8 = V_2 -> V_163 . error ;
F_4 ( V_2 -> V_25 , L_34 ) ;
goto V_203;
}
F_101 ( & V_2 -> V_163 ) ;
V_2 -> V_91 . V_204 = & V_2 -> V_163 ;
V_2 -> V_94 . V_91 = & V_2 -> V_91 ;
V_2 -> V_94 . V_200 = & V_2 -> V_93 ;
V_8 = F_102 ( & V_2 -> V_94 , V_205 , - 1 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_25 , L_35 ,
V_8 ) ;
goto V_203;
}
F_94 ( V_2 -> V_25 , L_36 ,
F_103 ( & V_2 -> V_94 ) ) ;
F_104 ( V_2 -> V_25 , L_37 ) ;
return 0 ;
V_203:
F_81 ( & V_2 -> V_163 ) ;
F_82 ( & V_2 -> V_91 ) ;
V_184:
F_83 ( V_2 ) ;
return V_8 ;
}
