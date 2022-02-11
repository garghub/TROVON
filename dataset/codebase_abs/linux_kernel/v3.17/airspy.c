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
F_4 ( & V_2 -> V_13 -> V_25 , L_1 , V_3 ) ;
V_8 = - V_26 ;
goto V_27;
}
if ( ! ( V_10 & V_24 ) )
memcpy ( V_2 -> V_28 , V_6 , V_7 ) ;
V_8 = F_5 ( V_2 -> V_13 , V_9 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_28 , V_7 , 1000 ) ;
F_6 ( V_2 -> V_13 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_28 , V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_25 ,
L_2 ,
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
unsigned long V_30 = 0 ;
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
unsigned int V_43 = V_2 -> V_44 - V_2 -> V_45 ;
V_2 -> V_42 = V_46 + F_17 ( F_16 ) ;
V_2 -> V_45 = V_2 -> V_44 ;
F_18 ( & V_2 -> V_13 -> V_25 ,
L_3 ,
V_38 , V_43 , F_16 ,
V_43 * 1000UL / F_16 ) ;
}
V_2 -> V_44 += V_38 / 2 ;
return V_39 ;
}
static void F_19 ( struct V_47 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
struct V_29 * V_49 ;
F_20 ( & V_2 -> V_13 -> V_25 ,
L_4 ,
V_50 , V_47 -> V_51 , V_47 -> V_52 ,
V_47 -> V_53 , V_47 -> V_54 ) ;
switch ( V_47 -> V_51 ) {
case 0 :
case - V_55 :
break;
case - V_56 :
case - V_57 :
case - V_58 :
return;
default:
F_21 ( & V_2 -> V_13 -> V_25 , L_5 ,
V_47 -> V_51 ) ;
break;
}
if ( F_22 ( V_47 -> V_52 > 0 ) ) {
void * V_59 ;
unsigned int V_60 ;
V_49 = F_7 ( V_2 ) ;
if ( F_14 ( V_49 == NULL ) ) {
V_2 -> V_61 ++ ;
F_23 ( & V_2 -> V_13 -> V_25 ,
L_6 ,
V_2 -> V_61 ) ;
goto V_62;
}
V_59 = F_24 ( & V_49 -> V_63 , 0 ) ;
V_60 = F_13 ( V_2 , V_59 , V_47 -> V_64 ,
V_47 -> V_52 ) ;
F_25 ( & V_49 -> V_63 , 0 , V_60 ) ;
F_26 ( & V_49 -> V_63 . V_65 . V_66 ) ;
V_49 -> V_63 . V_65 . V_67 = V_2 -> V_67 ++ ;
F_27 ( & V_49 -> V_63 , V_68 ) ;
}
V_62:
F_28 ( V_47 , V_69 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = V_2 -> V_71 - 1 ; V_70 >= 0 ; V_70 -- ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_7 , V_50 , V_70 ) ;
F_30 ( V_2 -> V_72 [ V_70 ] ) ;
}
V_2 -> V_71 = 0 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_70 , V_8 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_73 ; V_70 ++ ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_8 , V_50 , V_70 ) ;
V_8 = F_28 ( V_2 -> V_72 [ V_70 ] , V_69 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_13 -> V_25 ,
L_9 ,
V_70 ) ;
F_29 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_71 ++ ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 & V_74 ) {
while ( V_2 -> V_75 ) {
V_2 -> V_75 -- ;
F_18 ( & V_2 -> V_13 -> V_25 , L_10 ,
V_50 , V_2 -> V_75 ) ;
F_33 ( V_2 -> V_13 , V_2 -> V_76 ,
V_2 -> V_77 [ V_2 -> V_75 ] ,
V_2 -> V_78 [ V_2 -> V_75 ] ) ;
}
}
V_2 -> V_30 &= ~ V_74 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
V_2 -> V_75 = 0 ;
V_2 -> V_76 = V_79 ;
F_18 ( & V_2 -> V_13 -> V_25 ,
L_11 ,
V_50 , V_80 * V_79 ) ;
for ( V_2 -> V_75 = 0 ; V_2 -> V_75 < V_80 ; V_2 -> V_75 ++ ) {
V_2 -> V_77 [ V_2 -> V_75 ] = F_35 ( V_2 -> V_13 ,
V_79 , V_69 ,
& V_2 -> V_78 [ V_2 -> V_75 ] ) ;
if ( ! V_2 -> V_77 [ V_2 -> V_75 ] ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_12 ,
V_50 , V_2 -> V_75 ) ;
F_32 ( V_2 ) ;
return - V_81 ;
}
F_18 ( & V_2 -> V_13 -> V_25 , L_13 ,
V_50 , V_2 -> V_75 ,
V_2 -> V_77 [ V_2 -> V_75 ] ,
( long long ) V_2 -> V_78 [ V_2 -> V_75 ] ) ;
V_2 -> V_30 |= V_74 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_70 ;
F_29 ( V_2 ) ;
for ( V_70 = V_2 -> V_73 - 1 ; V_70 >= 0 ; V_70 -- ) {
if ( V_2 -> V_72 [ V_70 ] ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_14 ,
V_50 , V_70 ) ;
F_37 ( V_2 -> V_72 [ V_70 ] ) ;
}
}
V_2 -> V_73 = 0 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_70 , V_82 ;
for ( V_70 = 0 ; V_70 < V_80 ; V_70 ++ ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_15 , V_50 , V_70 ) ;
V_2 -> V_72 [ V_70 ] = F_39 ( 0 , V_69 ) ;
if ( ! V_2 -> V_72 [ V_70 ] ) {
F_18 ( & V_2 -> V_13 -> V_25 , L_16 , V_50 ) ;
for ( V_82 = 0 ; V_82 < V_70 ; V_82 ++ )
F_37 ( V_2 -> V_72 [ V_82 ] ) ;
return - V_81 ;
}
F_40 ( V_2 -> V_72 [ V_70 ] ,
V_2 -> V_13 ,
F_41 ( V_2 -> V_13 , 0x81 ) ,
V_2 -> V_77 [ V_70 ] ,
V_79 ,
F_19 , V_2 ) ;
V_2 -> V_72 [ V_70 ] -> V_83 = V_84 ;
V_2 -> V_72 [ V_70 ] -> V_85 = V_2 -> V_78 [ V_70 ] ;
V_2 -> V_73 ++ ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_30 = 0 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_17 , V_50 ) ;
F_8 ( & V_2 -> V_31 , V_30 ) ;
while ( ! F_9 ( & V_2 -> V_32 ) ) {
struct V_29 * V_28 ;
V_28 = F_10 ( V_2 -> V_32 . V_34 ,
struct V_29 , V_35 ) ;
F_11 ( & V_28 -> V_35 ) ;
F_27 ( & V_28 -> V_63 , V_86 ) ;
}
F_12 ( & V_2 -> V_31 , V_30 ) ;
}
static void F_43 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_44 ( V_88 ) ;
struct V_1 * V_2 = F_45 ( V_90 , struct V_1 , V_91 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_17 , V_50 ) ;
F_46 ( & V_2 -> V_92 ) ;
F_46 ( & V_2 -> V_93 ) ;
V_2 -> V_13 = NULL ;
F_47 ( & V_2 -> V_91 ) ;
F_48 ( & V_2 -> V_94 ) ;
F_49 ( & V_2 -> V_93 ) ;
F_49 ( & V_2 -> V_92 ) ;
F_50 ( & V_2 -> V_91 ) ;
}
static int F_51 ( struct V_95 * V_96 ,
const struct V_97 * V_98 , unsigned int * V_99 ,
unsigned int * V_100 , unsigned int V_101 [] , void * V_102 [] )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_18 , V_50 , * V_99 ) ;
if ( V_96 -> V_103 + * V_99 < 8 )
* V_99 = 8 - V_96 -> V_103 ;
* V_100 = 1 ;
V_101 [ 0 ] = F_53 ( V_2 -> V_104 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_19 ,
V_50 , * V_99 , V_101 [ 0 ] ) ;
return 0 ;
}
static void F_54 ( struct V_105 * V_63 )
{
struct V_1 * V_2 = F_52 ( V_63 -> V_95 ) ;
struct V_29 * V_28 =
F_45 ( V_63 , struct V_29 , V_63 ) ;
unsigned long V_30 = 0 ;
if ( F_14 ( ! V_2 -> V_13 ) ) {
F_27 ( & V_28 -> V_63 , V_86 ) ;
return;
}
F_8 ( & V_2 -> V_31 , V_30 ) ;
F_55 ( & V_28 -> V_35 , & V_2 -> V_32 ) ;
F_12 ( & V_2 -> V_31 , V_30 ) ;
}
static int F_56 ( struct V_95 * V_96 , unsigned int V_106 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
int V_8 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_17 , V_50 ) ;
if ( ! V_2 -> V_13 )
return - V_107 ;
F_46 ( & V_2 -> V_93 ) ;
F_57 ( V_108 , & V_2 -> V_30 ) ;
V_2 -> V_67 = 0 ;
V_8 = F_34 ( V_2 ) ;
if ( V_8 )
goto V_27;
V_8 = F_38 ( V_2 ) ;
if ( V_8 )
goto V_27;
V_8 = F_31 ( V_2 ) ;
if ( V_8 )
goto V_27;
V_8 = F_1 ( V_2 , V_11 , 1 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_27;
V_27:
F_49 ( & V_2 -> V_93 ) ;
return V_8 ;
}
static void F_58 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_17 , V_50 ) ;
F_46 ( & V_2 -> V_93 ) ;
F_1 ( V_2 , V_11 , 0 , 0 , NULL , 0 ) ;
F_29 ( V_2 ) ;
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
F_59 ( V_108 , & V_2 -> V_30 ) ;
F_49 ( & V_2 -> V_93 ) ;
}
static int F_60 ( struct V_109 * V_109 , void * V_110 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_17 , V_50 ) ;
F_62 ( V_112 -> V_113 , V_114 , sizeof( V_112 -> V_113 ) ) ;
F_62 ( V_112 -> V_115 , V_2 -> V_94 . V_116 , sizeof( V_112 -> V_115 ) ) ;
F_63 ( V_2 -> V_13 , V_112 -> V_117 , sizeof( V_112 -> V_117 ) ) ;
V_112 -> V_118 = V_119 | V_120 |
V_121 | V_122 ;
V_112 -> V_123 = V_112 -> V_118 | V_124 ;
return 0 ;
}
static int F_64 ( struct V_109 * V_109 , void * V_125 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_20 , V_50 , V_127 -> V_5 ) ;
if ( V_127 -> V_5 >= V_128 )
return - V_26 ;
F_62 ( V_127 -> V_129 , V_130 [ V_127 -> V_5 ] . V_116 , sizeof( V_127 -> V_129 ) ) ;
V_127 -> V_40 = V_130 [ V_127 -> V_5 ] . V_40 ;
return 0 ;
}
static int F_65 ( struct V_109 * V_109 , void * V_125 ,
struct V_97 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_21 , V_50 ,
( char * ) & V_2 -> V_40 ) ;
V_127 -> V_98 . V_131 . V_40 = V_2 -> V_40 ;
V_127 -> V_98 . V_131 . V_104 = V_2 -> V_104 ;
memset ( V_127 -> V_98 . V_131 . V_132 , 0 , sizeof( V_127 -> V_98 . V_131 . V_132 ) ) ;
return 0 ;
}
static int F_66 ( struct V_109 * V_109 , void * V_125 ,
struct V_97 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
struct V_95 * V_133 = & V_2 -> V_134 ;
int V_70 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_21 , V_50 ,
( char * ) & V_127 -> V_98 . V_131 . V_40 ) ;
if ( F_67 ( V_133 ) )
return - V_135 ;
memset ( V_127 -> V_98 . V_131 . V_132 , 0 , sizeof( V_127 -> V_98 . V_131 . V_132 ) ) ;
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ ) {
if ( V_130 [ V_70 ] . V_40 == V_127 -> V_98 . V_131 . V_40 ) {
V_2 -> V_40 = V_130 [ V_70 ] . V_40 ;
V_2 -> V_104 = V_130 [ V_70 ] . V_104 ;
V_127 -> V_98 . V_131 . V_104 = V_130 [ V_70 ] . V_104 ;
return 0 ;
}
}
V_2 -> V_40 = V_130 [ 0 ] . V_40 ;
V_2 -> V_104 = V_130 [ 0 ] . V_104 ;
V_127 -> V_98 . V_131 . V_40 = V_130 [ 0 ] . V_40 ;
V_127 -> V_98 . V_131 . V_104 = V_130 [ 0 ] . V_104 ;
return 0 ;
}
static int F_68 ( struct V_109 * V_109 , void * V_125 ,
struct V_97 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_70 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_21 , V_50 ,
( char * ) & V_127 -> V_98 . V_131 . V_40 ) ;
memset ( V_127 -> V_98 . V_131 . V_132 , 0 , sizeof( V_127 -> V_98 . V_131 . V_132 ) ) ;
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ ) {
if ( V_130 [ V_70 ] . V_40 == V_127 -> V_98 . V_131 . V_40 ) {
V_127 -> V_98 . V_131 . V_104 = V_130 [ V_70 ] . V_104 ;
return 0 ;
}
}
V_127 -> V_98 . V_131 . V_40 = V_130 [ 0 ] . V_40 ;
V_127 -> V_98 . V_131 . V_104 = V_130 [ 0 ] . V_104 ;
return 0 ;
}
static int F_69 ( struct V_109 * V_109 , void * V_125 ,
const struct V_136 * V_90 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_8 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_20 , V_50 , V_90 -> V_5 ) ;
if ( V_90 -> V_5 == 0 )
V_8 = 0 ;
else if ( V_90 -> V_5 == 1 )
V_8 = 0 ;
else
V_8 = - V_26 ;
return V_8 ;
}
static int F_70 ( struct V_109 * V_109 , void * V_125 , struct V_136 * V_90 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_8 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_20 , V_50 , V_90 -> V_5 ) ;
if ( V_90 -> V_5 == 0 ) {
F_62 ( V_90 -> V_116 , L_22 , sizeof( V_90 -> V_116 ) ) ;
V_90 -> type = V_137 ;
V_90 -> V_138 = V_139 | V_140 ;
V_90 -> V_141 = V_142 [ 0 ] . V_141 ;
V_90 -> V_143 = V_142 [ 0 ] . V_143 ;
V_8 = 0 ;
} else if ( V_90 -> V_5 == 1 ) {
F_62 ( V_90 -> V_116 , L_23 , sizeof( V_90 -> V_116 ) ) ;
V_90 -> type = V_144 ;
V_90 -> V_138 = V_139 | V_140 ;
V_90 -> V_141 = V_145 [ 0 ] . V_141 ;
V_90 -> V_143 = V_145 [ 0 ] . V_143 ;
V_8 = 0 ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_71 ( struct V_109 * V_109 , void * V_125 ,
struct V_146 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_8 = 0 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_24 ,
V_50 , V_127 -> V_147 , V_127 -> type ) ;
if ( V_127 -> V_147 == 0 ) {
V_127 -> type = V_137 ;
V_127 -> V_148 = V_2 -> V_149 ;
V_8 = 0 ;
} else if ( V_127 -> V_147 == 1 ) {
V_127 -> type = V_144 ;
V_127 -> V_148 = V_2 -> V_150 ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_72 ( struct V_109 * V_109 , void * V_125 ,
const struct V_146 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_8 ;
T_1 V_28 [ 4 ] ;
F_18 ( & V_2 -> V_13 -> V_25 , L_25 ,
V_50 , V_127 -> V_147 , V_127 -> type , V_127 -> V_148 ) ;
if ( V_127 -> V_147 == 0 ) {
V_2 -> V_149 = F_73 (unsigned int, f->frequency,
bands[0].rangelow,
bands[0].rangehigh) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_26 ,
V_50 , V_2 -> V_149 ) ;
V_8 = 0 ;
} else if ( V_127 -> V_147 == 1 ) {
V_2 -> V_150 = F_73 (unsigned int, f->frequency,
bands_rf[0].rangelow,
bands_rf[0].rangehigh) ;
F_18 ( & V_2 -> V_13 -> V_25 , L_27 ,
V_50 , V_2 -> V_150 ) ;
V_28 [ 0 ] = ( V_2 -> V_150 >> 0 ) & 0xff ;
V_28 [ 1 ] = ( V_2 -> V_150 >> 8 ) & 0xff ;
V_28 [ 2 ] = ( V_2 -> V_150 >> 16 ) & 0xff ;
V_28 [ 3 ] = ( V_2 -> V_150 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_12 , 0 , 0 , V_28 , 4 ) ;
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_74 ( struct V_109 * V_109 , void * V_125 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
int V_8 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_28 ,
V_50 , V_152 -> V_147 , V_152 -> type , V_152 -> V_5 ) ;
if ( V_152 -> V_147 == 0 ) {
if ( V_152 -> V_5 >= F_75 ( V_142 ) ) {
V_8 = - V_26 ;
} else {
* V_152 = V_142 [ V_152 -> V_5 ] ;
V_8 = 0 ;
}
} else if ( V_152 -> V_147 == 1 ) {
if ( V_152 -> V_5 >= F_75 ( V_145 ) ) {
V_8 = - V_26 ;
} else {
* V_152 = V_145 [ V_152 -> V_5 ] ;
V_8 = 0 ;
}
} else {
V_8 = - V_26 ;
}
return V_8 ;
}
static void F_76 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_45 ( V_90 , struct V_1 , V_91 ) ;
F_77 ( & V_2 -> V_153 ) ;
F_78 ( & V_2 -> V_91 ) ;
F_79 ( V_2 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_154 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_29 ,
V_50 , V_2 -> V_155 -> V_156 . V_157 ,
V_2 -> V_155 -> V_157 , V_2 -> V_158 -> V_156 . V_157 ,
V_2 -> V_158 -> V_157 ) ;
V_8 = F_1 ( V_2 , V_22 , 0 , V_2 -> V_155 -> V_157 ,
& V_154 , 1 ) ;
if ( V_8 )
goto V_27;
if ( V_2 -> V_155 -> V_157 == false ) {
V_8 = F_1 ( V_2 , V_19 , 0 , V_2 -> V_158 -> V_157 ,
& V_154 , 1 ) ;
if ( V_8 )
goto V_27;
}
V_27:
if ( V_8 )
F_18 ( & V_2 -> V_13 -> V_25 , L_30 , V_50 , V_8 ) ;
return V_8 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_154 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_31 ,
V_50 , V_2 -> V_159 -> V_156 . V_157 ,
V_2 -> V_159 -> V_157 , V_2 -> V_160 -> V_156 . V_157 ,
V_2 -> V_160 -> V_157 ) ;
V_8 = F_1 ( V_2 , V_23 , 0 , V_2 -> V_159 -> V_157 ,
& V_154 , 1 ) ;
if ( V_8 )
goto V_27;
if ( V_2 -> V_159 -> V_157 == false ) {
V_8 = F_1 ( V_2 , V_20 , 0 ,
V_2 -> V_160 -> V_157 , & V_154 , 1 ) ;
if ( V_8 )
goto V_27;
}
V_27:
if ( V_8 )
F_18 ( & V_2 -> V_13 -> V_25 , L_30 , V_50 , V_8 ) ;
return V_8 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_154 ;
F_18 ( & V_2 -> V_13 -> V_25 , L_32 ,
V_50 , V_2 -> V_161 -> V_156 . V_157 , V_2 -> V_161 -> V_157 ) ;
V_8 = F_1 ( V_2 , V_21 , 0 , V_2 -> V_161 -> V_157 ,
& V_154 , 1 ) ;
if ( V_8 )
goto V_27;
V_27:
if ( V_8 )
F_18 ( & V_2 -> V_13 -> V_25 , L_30 , V_50 , V_8 ) ;
return V_8 ;
}
static int F_83 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = F_45 ( V_163 -> V_164 , struct V_1 , V_153 ) ;
int V_8 ;
switch ( V_163 -> V_165 ) {
case V_166 :
case V_167 :
V_8 = F_80 ( V_2 ) ;
break;
case V_168 :
case V_169 :
V_8 = F_81 ( V_2 ) ;
break;
case V_170 :
V_8 = F_82 ( V_2 ) ;
break;
default:
F_18 ( & V_2 -> V_13 -> V_25 , L_33 ,
V_50 , V_163 -> V_165 , V_163 -> V_116 ) ;
V_8 = - V_26 ;
}
return V_8 ;
}
static int F_84 ( struct V_87 * V_88 ,
const struct V_171 * V_165 )
{
struct V_172 * V_13 = F_85 ( V_88 ) ;
struct V_1 * V_2 = NULL ;
int V_8 ;
T_1 V_154 , V_28 [ V_173 ] ;
V_2 = F_86 ( sizeof( struct V_1 ) , V_174 ) ;
if ( V_2 == NULL ) {
F_4 ( & V_13 -> V_25 ,
L_34 ) ;
return - V_81 ;
}
F_87 ( & V_2 -> V_93 ) ;
F_87 ( & V_2 -> V_92 ) ;
F_88 ( & V_2 -> V_31 ) ;
F_89 ( & V_2 -> V_32 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_149 = V_142 [ 0 ] . V_141 ;
V_2 -> V_150 = V_145 [ 0 ] . V_141 ;
V_2 -> V_40 = V_130 [ 0 ] . V_40 ;
V_2 -> V_104 = V_130 [ 0 ] . V_104 ;
V_8 = F_1 ( V_2 , V_16 , 0 , 0 , & V_154 , 1 ) ;
if ( V_8 == 0 )
V_8 = F_1 ( V_2 , V_17 , 0 , 0 ,
V_28 , V_173 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_13 -> V_25 , L_35 ) ;
goto V_175;
}
V_28 [ V_173 - 1 ] = '\0' ;
F_90 ( & V_2 -> V_13 -> V_25 , L_36 , V_154 ) ;
F_90 ( & V_2 -> V_13 -> V_25 , L_37 , V_28 ) ;
V_2 -> V_134 . type = V_176 ;
V_2 -> V_134 . V_177 = V_178 | V_179 | V_180 ;
V_2 -> V_134 . V_181 = V_2 ;
V_2 -> V_134 . V_182 = sizeof( struct V_29 ) ;
V_2 -> V_134 . V_183 = & V_184 ;
V_2 -> V_134 . V_185 = & V_186 ;
V_2 -> V_134 . V_187 = V_188 ;
V_8 = F_91 ( & V_2 -> V_134 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_13 -> V_25 , L_38 ) ;
goto V_175;
}
V_2 -> V_94 = V_189 ;
V_2 -> V_94 . V_190 = & V_2 -> V_134 ;
V_2 -> V_94 . V_190 -> V_191 = & V_2 -> V_92 ;
F_92 ( & V_2 -> V_94 , V_2 ) ;
V_2 -> V_91 . V_192 = F_76 ;
V_8 = F_93 ( & V_88 -> V_25 , & V_2 -> V_91 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_13 -> V_25 ,
L_39 , V_8 ) ;
goto V_175;
}
F_94 ( & V_2 -> V_153 , 5 ) ;
V_2 -> V_155 = F_95 ( & V_2 -> V_153 , & V_193 ,
V_166 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_158 = F_95 ( & V_2 -> V_153 , & V_193 ,
V_167 , 0 , 14 , 1 , 8 ) ;
F_96 ( 2 , & V_2 -> V_155 , 0 , false ) ;
V_2 -> V_159 = F_95 ( & V_2 -> V_153 , & V_193 ,
V_168 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_160 = F_95 ( & V_2 -> V_153 , & V_193 ,
V_169 , 0 , 15 , 1 , 8 ) ;
F_96 ( 2 , & V_2 -> V_159 , 0 , false ) ;
V_2 -> V_161 = F_95 ( & V_2 -> V_153 , & V_193 ,
V_170 , 0 , 15 , 1 , 0 ) ;
if ( V_2 -> V_153 . error ) {
V_8 = V_2 -> V_153 . error ;
F_4 ( & V_2 -> V_13 -> V_25 , L_40 ) ;
goto V_194;
}
F_97 ( & V_2 -> V_153 ) ;
V_2 -> V_91 . V_195 = & V_2 -> V_153 ;
V_2 -> V_94 . V_91 = & V_2 -> V_91 ;
V_2 -> V_94 . V_191 = & V_2 -> V_93 ;
V_8 = F_98 ( & V_2 -> V_94 , V_196 , - 1 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_13 -> V_25 ,
L_41 ,
V_8 ) ;
goto V_197;
}
F_90 ( & V_2 -> V_13 -> V_25 , L_42 ,
F_99 ( & V_2 -> V_94 ) ) ;
F_100 ( & V_2 -> V_13 -> V_25 ,
L_43 ,
V_114 ) ;
return 0 ;
V_194:
F_77 ( & V_2 -> V_153 ) ;
V_197:
F_78 ( & V_2 -> V_91 ) ;
V_175:
F_79 ( V_2 ) ;
return V_8 ;
}
