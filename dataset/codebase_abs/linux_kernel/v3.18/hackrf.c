static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
int V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_9 = F_2 ( V_2 -> V_15 , 0 ) ;
V_10 = ( V_16 | V_17 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_9 = F_3 ( V_2 -> V_15 , 0 ) ;
V_10 = ( V_16 | V_22 ) ;
break;
default:
F_4 ( V_2 -> V_2 , L_1 , V_3 ) ;
V_8 = - V_23 ;
goto V_24;
}
if ( ! ( V_10 & V_22 ) )
memcpy ( V_2 -> V_25 , V_6 , V_7 ) ;
V_8 = F_5 ( V_2 -> V_15 , V_9 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_25 , V_7 , 1000 ) ;
F_6 ( V_2 -> V_2 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_25 , V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_2 , L_2 ,
V_8 , V_3 ) ;
goto V_24;
}
if ( V_10 & V_22 )
memcpy ( V_6 , V_2 -> V_25 , V_7 ) ;
return 0 ;
V_24:
return V_8 ;
}
static struct V_26 * F_7 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
struct V_26 * V_25 = NULL ;
F_8 ( & V_2 -> V_28 , V_27 ) ;
if ( F_9 ( & V_2 -> V_29 ) )
goto V_30;
V_25 = F_10 ( V_2 -> V_29 . V_31 , struct V_26 , V_32 ) ;
F_11 ( & V_25 -> V_32 ) ;
V_30:
F_12 ( & V_2 -> V_28 , V_27 ) ;
return V_25 ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
void * V_33 , void * V_34 , unsigned int V_35 )
{
memcpy ( V_33 , V_34 , V_35 ) ;
if ( F_14 ( F_15 ( V_2 -> V_36 ) ) ) {
#define F_16 10000UL
unsigned int V_37 = F_17 ( V_38 -
V_2 -> V_36 + F_18 ( F_16 ) ) ;
unsigned int V_39 = V_2 -> V_40 - V_2 -> V_41 ;
V_2 -> V_36 = V_38 + F_18 ( F_16 ) ;
V_2 -> V_41 = V_2 -> V_40 ;
F_19 ( V_2 -> V_2 , L_3 ,
V_35 , V_39 , V_37 ,
V_39 * 1000UL / V_37 ) ;
}
V_2 -> V_40 += V_35 / 2 ;
return V_35 ;
}
static void F_20 ( struct V_42 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_26 * V_44 ;
F_21 ( V_2 -> V_2 , L_4 ,
V_42 -> V_45 , V_42 -> V_46 ,
V_42 -> V_47 , V_42 -> V_48 ) ;
switch ( V_42 -> V_45 ) {
case 0 :
case - V_49 :
break;
case - V_50 :
case - V_51 :
case - V_52 :
return;
default:
F_22 ( V_2 -> V_2 , L_5 , V_42 -> V_45 ) ;
break;
}
if ( F_23 ( V_42 -> V_46 > 0 ) ) {
void * V_53 ;
unsigned int V_54 ;
V_44 = F_7 ( V_2 ) ;
if ( F_14 ( V_44 == NULL ) ) {
V_2 -> V_55 ++ ;
F_24 ( V_2 -> V_2 ,
L_6 ,
V_2 -> V_55 ) ;
goto V_56;
}
V_53 = F_25 ( & V_44 -> V_57 , 0 ) ;
V_54 = F_13 ( V_2 , V_53 , V_42 -> V_58 ,
V_42 -> V_46 ) ;
F_26 ( & V_44 -> V_57 , 0 , V_54 ) ;
F_27 ( & V_44 -> V_57 . V_59 . V_60 ) ;
V_44 -> V_57 . V_59 . V_61 = V_2 -> V_61 ++ ;
F_28 ( & V_44 -> V_57 , V_62 ) ;
}
V_56:
F_29 ( V_42 , V_63 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_64 ;
for ( V_64 = V_2 -> V_65 - 1 ; V_64 >= 0 ; V_64 -- ) {
F_19 ( V_2 -> V_2 , L_7 , V_64 ) ;
F_31 ( V_2 -> V_66 [ V_64 ] ) ;
}
V_2 -> V_65 = 0 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_64 , V_8 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_67 ; V_64 ++ ) {
F_19 ( V_2 -> V_2 , L_8 , V_64 ) ;
V_8 = F_29 ( V_2 -> V_66 [ V_64 ] , V_63 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_9 ,
V_64 ) ;
F_30 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_65 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 & V_68 ) {
while ( V_2 -> V_69 ) {
V_2 -> V_69 -- ;
F_19 ( V_2 -> V_2 , L_10 , V_2 -> V_69 ) ;
F_34 ( V_2 -> V_15 , V_2 -> V_70 ,
V_2 -> V_71 [ V_2 -> V_69 ] ,
V_2 -> V_72 [ V_2 -> V_69 ] ) ;
}
}
V_2 -> V_27 &= ~ V_68 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
V_2 -> V_69 = 0 ;
V_2 -> V_70 = V_73 ;
F_19 ( V_2 -> V_2 , L_11 ,
V_74 * V_73 ) ;
for ( V_2 -> V_69 = 0 ; V_2 -> V_69 < V_74 ; V_2 -> V_69 ++ ) {
V_2 -> V_71 [ V_2 -> V_69 ] = F_36 ( V_2 -> V_15 ,
V_73 , V_63 ,
& V_2 -> V_72 [ V_2 -> V_69 ] ) ;
if ( ! V_2 -> V_71 [ V_2 -> V_69 ] ) {
F_19 ( V_2 -> V_2 , L_12 ,
V_2 -> V_69 ) ;
F_33 ( V_2 ) ;
return - V_75 ;
}
F_19 ( V_2 -> V_2 , L_13 , V_2 -> V_69 ,
V_2 -> V_71 [ V_2 -> V_69 ] ,
( long long ) V_2 -> V_72 [ V_2 -> V_69 ] ) ;
V_2 -> V_27 |= V_68 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_64 ;
F_30 ( V_2 ) ;
for ( V_64 = V_2 -> V_67 - 1 ; V_64 >= 0 ; V_64 -- ) {
if ( V_2 -> V_66 [ V_64 ] ) {
F_19 ( V_2 -> V_2 , L_14 , V_64 ) ;
F_38 ( V_2 -> V_66 [ V_64 ] ) ;
}
}
V_2 -> V_67 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_64 , V_76 ;
for ( V_64 = 0 ; V_64 < V_74 ; V_64 ++ ) {
F_19 ( V_2 -> V_2 , L_15 , V_64 ) ;
V_2 -> V_66 [ V_64 ] = F_40 ( 0 , V_63 ) ;
if ( ! V_2 -> V_66 [ V_64 ] ) {
F_19 ( V_2 -> V_2 , L_16 ) ;
for ( V_76 = 0 ; V_76 < V_64 ; V_76 ++ )
F_38 ( V_2 -> V_66 [ V_76 ] ) ;
return - V_75 ;
}
F_41 ( V_2 -> V_66 [ V_64 ] ,
V_2 -> V_15 ,
F_42 ( V_2 -> V_15 , 0x81 ) ,
V_2 -> V_71 [ V_64 ] ,
V_73 ,
F_20 , V_2 ) ;
V_2 -> V_66 [ V_64 ] -> V_77 = V_78 ;
V_2 -> V_66 [ V_64 ] -> V_79 = V_2 -> V_72 [ V_64 ] ;
V_2 -> V_67 ++ ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
F_19 ( V_2 -> V_2 , L_17 ) ;
F_8 ( & V_2 -> V_28 , V_27 ) ;
while ( ! F_9 ( & V_2 -> V_29 ) ) {
struct V_26 * V_25 ;
V_25 = F_10 ( V_2 -> V_29 . V_31 ,
struct V_26 , V_32 ) ;
F_11 ( & V_25 -> V_32 ) ;
F_28 ( & V_25 -> V_57 , V_80 ) ;
}
F_12 ( & V_2 -> V_28 , V_27 ) ;
}
static void F_44 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = F_45 ( V_82 ) ;
struct V_1 * V_2 = F_46 ( V_84 , struct V_1 , V_85 ) ;
F_19 ( V_2 -> V_2 , L_17 ) ;
F_47 ( & V_2 -> V_86 ) ;
F_47 ( & V_2 -> V_87 ) ;
V_2 -> V_15 = NULL ;
F_48 ( & V_2 -> V_85 ) ;
F_49 ( & V_2 -> V_88 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_50 ( & V_2 -> V_86 ) ;
F_51 ( & V_2 -> V_85 ) ;
}
static int F_52 ( struct V_89 * V_90 ,
const struct V_91 * V_92 , unsigned int * V_93 ,
unsigned int * V_94 , unsigned int V_95 [] , void * V_96 [] )
{
struct V_1 * V_2 = F_53 ( V_90 ) ;
F_19 ( V_2 -> V_2 , L_18 , * V_93 ) ;
if ( V_90 -> V_97 + * V_93 < 8 )
* V_93 = 8 - V_90 -> V_97 ;
* V_94 = 1 ;
V_95 [ 0 ] = F_54 ( V_2 -> V_98 ) ;
F_19 ( V_2 -> V_2 , L_19 , * V_93 , V_95 [ 0 ] ) ;
return 0 ;
}
static void F_55 ( struct V_99 * V_57 )
{
struct V_1 * V_2 = F_53 ( V_57 -> V_89 ) ;
struct V_26 * V_25 =
F_46 ( V_57 , struct V_26 , V_57 ) ;
unsigned long V_27 ;
F_8 ( & V_2 -> V_28 , V_27 ) ;
F_56 ( & V_25 -> V_32 , & V_2 -> V_29 ) ;
F_12 ( & V_2 -> V_28 , V_27 ) ;
}
static int F_57 ( struct V_89 * V_90 , unsigned int V_100 )
{
struct V_1 * V_2 = F_53 ( V_90 ) ;
int V_8 ;
F_19 ( V_2 -> V_2 , L_17 ) ;
if ( ! V_2 -> V_15 )
return - V_101 ;
F_47 ( & V_2 -> V_87 ) ;
V_2 -> V_61 = 0 ;
F_58 ( V_102 , & V_2 -> V_27 ) ;
V_8 = F_35 ( V_2 ) ;
if ( V_8 )
goto V_24;
V_8 = F_39 ( V_2 ) ;
if ( V_8 )
goto V_24;
V_8 = F_32 ( V_2 ) ;
if ( V_8 )
goto V_24;
V_8 = F_1 ( V_2 , V_11 , 1 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_24;
goto V_103;
V_24:
F_30 ( V_2 ) ;
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
F_59 ( V_102 , & V_2 -> V_27 ) ;
{
struct V_26 * V_25 , * V_104 ;
F_60 (buf, tmp, &dev->queued_bufs, list) {
F_11 ( & V_25 -> V_32 ) ;
F_28 ( & V_25 -> V_57 , V_105 ) ;
}
}
V_103:
F_50 ( & V_2 -> V_87 ) ;
return V_8 ;
}
static void F_61 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_53 ( V_90 ) ;
F_19 ( V_2 -> V_2 , L_17 ) ;
F_47 ( & V_2 -> V_87 ) ;
F_1 ( V_2 , V_11 , 0 , 0 , NULL , 0 ) ;
F_30 ( V_2 ) ;
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
F_43 ( V_2 ) ;
F_59 ( V_102 , & V_2 -> V_27 ) ;
F_50 ( & V_2 -> V_87 ) ;
}
static int F_62 ( struct V_106 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
F_19 ( V_2 -> V_2 , L_17 ) ;
F_64 ( V_109 -> V_110 , V_111 , sizeof( V_109 -> V_110 ) ) ;
F_64 ( V_109 -> V_112 , V_2 -> V_88 . V_113 , sizeof( V_109 -> V_112 ) ) ;
F_65 ( V_2 -> V_15 , V_109 -> V_114 , sizeof( V_109 -> V_114 ) ) ;
V_109 -> V_115 = V_116 | V_117 |
V_118 | V_119 ;
V_109 -> V_120 = V_109 -> V_115 | V_121 ;
return 0 ;
}
static int F_66 ( struct V_106 * V_106 , void * V_122 ,
struct V_91 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
struct V_89 * V_124 = & V_2 -> V_125 ;
int V_64 ;
F_19 ( V_2 -> V_2 , L_20 ,
( char * ) & V_123 -> V_92 . V_126 . V_127 ) ;
if ( F_67 ( V_124 ) )
return - V_128 ;
memset ( V_123 -> V_92 . V_126 . V_129 , 0 , sizeof( V_123 -> V_92 . V_126 . V_129 ) ) ;
for ( V_64 = 0 ; V_64 < V_130 ; V_64 ++ ) {
if ( V_123 -> V_92 . V_126 . V_127 == V_131 [ V_64 ] . V_127 ) {
V_2 -> V_127 = V_131 [ V_64 ] . V_127 ;
V_2 -> V_98 = V_131 [ V_64 ] . V_98 ;
V_123 -> V_92 . V_126 . V_98 = V_131 [ V_64 ] . V_98 ;
return 0 ;
}
}
V_2 -> V_127 = V_131 [ 0 ] . V_127 ;
V_2 -> V_98 = V_131 [ 0 ] . V_98 ;
V_123 -> V_92 . V_126 . V_127 = V_131 [ 0 ] . V_127 ;
V_123 -> V_92 . V_126 . V_98 = V_131 [ 0 ] . V_98 ;
return 0 ;
}
static int F_68 ( struct V_106 * V_106 , void * V_122 ,
struct V_91 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
F_19 ( V_2 -> V_2 , L_20 ,
( char * ) & V_2 -> V_127 ) ;
memset ( V_123 -> V_92 . V_126 . V_129 , 0 , sizeof( V_123 -> V_92 . V_126 . V_129 ) ) ;
V_123 -> V_92 . V_126 . V_127 = V_2 -> V_127 ;
V_123 -> V_92 . V_126 . V_98 = V_2 -> V_98 ;
return 0 ;
}
static int F_69 ( struct V_106 * V_106 , void * V_122 ,
struct V_91 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_64 ;
F_19 ( V_2 -> V_2 , L_20 ,
( char * ) & V_123 -> V_92 . V_126 . V_127 ) ;
memset ( V_123 -> V_92 . V_126 . V_129 , 0 , sizeof( V_123 -> V_92 . V_126 . V_129 ) ) ;
for ( V_64 = 0 ; V_64 < V_130 ; V_64 ++ ) {
if ( V_131 [ V_64 ] . V_127 == V_123 -> V_92 . V_126 . V_127 ) {
V_123 -> V_92 . V_126 . V_98 = V_131 [ V_64 ] . V_98 ;
return 0 ;
}
}
V_123 -> V_92 . V_126 . V_127 = V_131 [ 0 ] . V_127 ;
V_123 -> V_92 . V_126 . V_98 = V_131 [ 0 ] . V_98 ;
return 0 ;
}
static int F_70 ( struct V_106 * V_106 , void * V_122 ,
struct V_132 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
F_19 ( V_2 -> V_2 , L_21 , V_123 -> V_5 ) ;
if ( V_123 -> V_5 >= V_130 )
return - V_23 ;
F_64 ( V_123 -> V_133 , V_131 [ V_123 -> V_5 ] . V_113 , sizeof( V_123 -> V_133 ) ) ;
V_123 -> V_127 = V_131 [ V_123 -> V_5 ] . V_127 ;
return 0 ;
}
static int F_71 ( struct V_106 * V_106 , void * V_122 ,
const struct V_134 * V_84 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_8 ;
F_19 ( V_2 -> V_2 , L_21 , V_84 -> V_5 ) ;
if ( V_84 -> V_5 == 0 )
V_8 = 0 ;
else if ( V_84 -> V_5 == 1 )
V_8 = 0 ;
else
V_8 = - V_23 ;
return V_8 ;
}
static int F_72 ( struct V_106 * V_106 , void * V_122 , struct V_134 * V_84 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_8 ;
F_19 ( V_2 -> V_2 , L_21 , V_84 -> V_5 ) ;
if ( V_84 -> V_5 == 0 ) {
F_64 ( V_84 -> V_113 , L_22 , sizeof( V_84 -> V_113 ) ) ;
V_84 -> type = V_135 ;
V_84 -> V_136 = V_137 | V_138 ;
V_84 -> V_139 = V_140 [ 0 ] . V_139 ;
V_84 -> V_141 = V_140 [ 0 ] . V_141 ;
V_8 = 0 ;
} else if ( V_84 -> V_5 == 1 ) {
F_64 ( V_84 -> V_113 , L_23 , sizeof( V_84 -> V_113 ) ) ;
V_84 -> type = V_142 ;
V_84 -> V_136 = V_137 | V_138 ;
V_84 -> V_139 = V_143 [ 0 ] . V_139 ;
V_84 -> V_141 = V_143 [ 0 ] . V_141 ;
V_8 = 0 ;
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
static int F_73 ( struct V_106 * V_106 , void * V_122 ,
const struct V_144 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_8 ;
unsigned int V_145 , V_146 ;
T_1 V_25 [ 8 ] ;
F_19 ( V_2 -> V_2 , L_24 ,
V_123 -> V_147 , V_123 -> type , V_123 -> V_148 ) ;
if ( V_123 -> V_147 == 0 ) {
V_2 -> V_149 = F_74 (unsigned int, f->frequency,
bands_adc[0].rangelow, bands_adc[0].rangehigh) ;
F_19 ( V_2 -> V_2 , L_25 , V_2 -> V_149 ) ;
V_145 = V_2 -> V_149 ;
V_146 = 1 ;
V_25 [ 0 ] = ( V_145 >> 0 ) & 0xff ;
V_25 [ 1 ] = ( V_145 >> 8 ) & 0xff ;
V_25 [ 2 ] = ( V_145 >> 16 ) & 0xff ;
V_25 [ 3 ] = ( V_145 >> 24 ) & 0xff ;
V_25 [ 4 ] = ( V_146 >> 0 ) & 0xff ;
V_25 [ 5 ] = ( V_146 >> 8 ) & 0xff ;
V_25 [ 6 ] = ( V_146 >> 16 ) & 0xff ;
V_25 [ 7 ] = ( V_146 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_13 , 0 , 0 , V_25 , 8 ) ;
} else if ( V_123 -> V_147 == 1 ) {
V_2 -> V_150 = F_74 (unsigned int, f->frequency,
bands_rf[0].rangelow, bands_rf[0].rangehigh) ;
F_19 ( V_2 -> V_2 , L_26 , V_2 -> V_150 ) ;
V_145 = V_2 -> V_150 / 1000000 ;
V_146 = V_2 -> V_150 % 1000000 ;
V_25 [ 0 ] = ( V_145 >> 0 ) & 0xff ;
V_25 [ 1 ] = ( V_145 >> 8 ) & 0xff ;
V_25 [ 2 ] = ( V_145 >> 16 ) & 0xff ;
V_25 [ 3 ] = ( V_145 >> 24 ) & 0xff ;
V_25 [ 4 ] = ( V_146 >> 0 ) & 0xff ;
V_25 [ 5 ] = ( V_146 >> 8 ) & 0xff ;
V_25 [ 6 ] = ( V_146 >> 16 ) & 0xff ;
V_25 [ 7 ] = ( V_146 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_12 , 0 , 0 , V_25 , 8 ) ;
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
static int F_75 ( struct V_106 * V_106 , void * V_122 ,
struct V_144 * V_123 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_8 ;
F_19 ( V_2 -> V_2 , L_27 , V_123 -> V_147 , V_123 -> type ) ;
if ( V_123 -> V_147 == 0 ) {
V_123 -> type = V_135 ;
V_123 -> V_148 = V_2 -> V_149 ;
V_8 = 0 ;
} else if ( V_123 -> V_147 == 1 ) {
V_123 -> type = V_142 ;
V_123 -> V_148 = V_2 -> V_150 ;
V_8 = 0 ;
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
static int F_76 ( struct V_106 * V_106 , void * V_122 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
int V_8 ;
F_19 ( V_2 -> V_2 , L_28 ,
V_152 -> V_147 , V_152 -> type , V_152 -> V_5 ) ;
if ( V_152 -> V_147 == 0 ) {
if ( V_152 -> V_5 >= F_77 ( V_140 ) ) {
V_8 = - V_23 ;
} else {
* V_152 = V_140 [ V_152 -> V_5 ] ;
V_8 = 0 ;
}
} else if ( V_152 -> V_147 == 1 ) {
if ( V_152 -> V_5 >= F_77 ( V_143 ) ) {
V_8 = - V_23 ;
} else {
* V_152 = V_143 [ V_152 -> V_5 ] ;
V_8 = 0 ;
}
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
static void F_78 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_46 ( V_84 , struct V_1 , V_85 ) ;
F_79 ( & V_2 -> V_153 ) ;
F_80 ( & V_2 -> V_85 ) ;
F_81 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_8 , V_64 ;
T_2 V_154 , V_155 ;
unsigned int V_156 ;
static const struct {
T_3 V_157 ;
} V_158 [] = {
{ 1750000 } ,
{ 2500000 } ,
{ 3500000 } ,
{ 5000000 } ,
{ 5500000 } ,
{ 6000000 } ,
{ 7000000 } ,
{ 8000000 } ,
{ 9000000 } ,
{ 10000000 } ,
{ 12000000 } ,
{ 14000000 } ,
{ 15000000 } ,
{ 20000000 } ,
{ 24000000 } ,
{ 28000000 } ,
} ;
F_19 ( V_2 -> V_2 , L_29 ,
V_2 -> V_159 -> V_160 . V_161 ,
V_2 -> V_159 -> V_161 , V_2 -> V_156 -> V_160 . V_161 ,
V_2 -> V_156 -> V_161 , V_2 -> V_149 ) ;
if ( V_2 -> V_159 -> V_161 == true )
V_156 = V_2 -> V_149 ;
else
V_156 = V_2 -> V_156 -> V_161 ;
for ( V_64 = 0 ; V_64 < F_77 ( V_158 ) ; V_64 ++ ) {
if ( V_156 <= V_158 [ V_64 ] . V_157 ) {
V_156 = V_158 [ V_64 ] . V_157 ;
break;
}
}
V_2 -> V_156 -> V_161 = V_156 ;
V_2 -> V_156 -> V_160 . V_161 = V_156 ;
F_19 ( V_2 -> V_2 , L_30 , V_156 ) ;
V_154 = 0 ;
V_154 |= ( ( V_156 >> 0 ) & 0xff ) << 0 ;
V_154 |= ( ( V_156 >> 8 ) & 0xff ) << 8 ;
V_155 = 0 ;
V_155 |= ( ( V_156 >> 16 ) & 0xff ) << 0 ;
V_155 |= ( ( V_156 >> 24 ) & 0xff ) << 8 ;
V_8 = F_1 ( V_2 , V_14 ,
V_154 , V_155 , NULL , 0 ) ;
if ( V_8 )
F_19 ( V_2 -> V_2 , L_31 , V_8 ) ;
return V_8 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_162 ;
F_19 ( V_2 -> V_2 , L_32 ,
V_2 -> V_163 -> V_160 . V_161 , V_2 -> V_163 -> V_161 ) ;
V_8 = F_1 ( V_2 , V_20 , 0 , V_2 -> V_163 -> V_161 ,
& V_162 , 1 ) ;
if ( V_8 )
F_19 ( V_2 -> V_2 , L_31 , V_8 ) ;
return V_8 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_162 ;
F_19 ( V_2 -> V_2 , L_33 ,
V_2 -> V_164 -> V_160 . V_161 , V_2 -> V_164 -> V_161 ) ;
V_8 = F_1 ( V_2 , V_21 , 0 , V_2 -> V_164 -> V_161 ,
& V_162 , 1 ) ;
if ( V_8 )
F_19 ( V_2 -> V_2 , L_31 , V_8 ) ;
return V_8 ;
}
static int F_85 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_46 ( V_166 -> V_167 ,
struct V_1 , V_153 ) ;
int V_8 ;
switch ( V_166 -> V_168 ) {
case V_169 :
case V_170 :
V_8 = F_82 ( V_2 ) ;
break;
case V_171 :
V_8 = F_83 ( V_2 ) ;
break;
case V_172 :
V_8 = F_84 ( V_2 ) ;
break;
default:
F_19 ( V_2 -> V_2 , L_34 ,
V_166 -> V_168 , V_166 -> V_113 ) ;
V_8 = - V_23 ;
}
return V_8 ;
}
static int F_86 ( struct V_81 * V_82 ,
const struct V_173 * V_168 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_162 , V_25 [ V_174 ] ;
V_2 = F_87 ( sizeof( * V_2 ) , V_175 ) ;
if ( V_2 == NULL )
return - V_75 ;
F_88 ( & V_2 -> V_87 ) ;
F_88 ( & V_2 -> V_86 ) ;
F_89 ( & V_2 -> V_28 ) ;
F_90 ( & V_2 -> V_29 ) ;
V_2 -> V_2 = & V_82 -> V_2 ;
V_2 -> V_15 = F_91 ( V_82 ) ;
V_2 -> V_149 = V_140 [ 0 ] . V_139 ;
V_2 -> V_150 = V_143 [ 0 ] . V_139 ;
V_2 -> V_127 = V_131 [ 0 ] . V_127 ;
V_2 -> V_98 = V_131 [ 0 ] . V_98 ;
V_8 = F_1 ( V_2 , V_18 , 0 , 0 , & V_162 , 1 ) ;
if ( V_8 == 0 )
V_8 = F_1 ( V_2 , V_19 , 0 , 0 ,
V_25 , V_174 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_35 ) ;
goto V_176;
}
V_25 [ V_174 - 1 ] = '\0' ;
F_92 ( V_2 -> V_2 , L_36 , V_162 ) ;
F_92 ( V_2 -> V_2 , L_37 , V_25 ) ;
V_2 -> V_125 . type = V_177 ;
V_2 -> V_125 . V_178 = V_179 | V_180 | V_181 ;
V_2 -> V_125 . V_182 = V_2 ;
V_2 -> V_125 . V_183 = sizeof( struct V_26 ) ;
V_2 -> V_125 . V_184 = & V_185 ;
V_2 -> V_125 . V_186 = & V_187 ;
V_2 -> V_125 . V_188 = V_189 ;
V_8 = F_93 ( & V_2 -> V_125 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_38 ) ;
goto V_176;
}
V_2 -> V_88 = V_190 ;
V_2 -> V_88 . V_191 = & V_2 -> V_125 ;
V_2 -> V_88 . V_191 -> V_192 = & V_2 -> V_86 ;
F_94 ( & V_2 -> V_88 , V_2 ) ;
V_2 -> V_85 . V_193 = F_78 ;
V_8 = F_95 ( & V_82 -> V_2 , & V_2 -> V_85 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_39 , V_8 ) ;
goto V_176;
}
F_96 ( & V_2 -> V_153 , 4 ) ;
V_2 -> V_159 = F_97 ( & V_2 -> V_153 , & V_194 ,
V_169 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_156 = F_97 ( & V_2 -> V_153 , & V_194 ,
V_170 ,
1750000 , 28000000 , 50000 , 1750000 ) ;
F_98 ( 2 , & V_2 -> V_159 , 0 , false ) ;
V_2 -> V_163 = F_97 ( & V_2 -> V_153 , & V_194 ,
V_171 , 0 , 40 , 8 , 0 ) ;
V_2 -> V_164 = F_97 ( & V_2 -> V_153 , & V_194 ,
V_172 , 0 , 62 , 2 , 0 ) ;
if ( V_2 -> V_153 . error ) {
V_8 = V_2 -> V_153 . error ;
F_4 ( V_2 -> V_2 , L_40 ) ;
goto V_195;
}
F_99 ( & V_2 -> V_153 ) ;
V_2 -> V_85 . V_196 = & V_2 -> V_153 ;
V_2 -> V_88 . V_85 = & V_2 -> V_85 ;
V_2 -> V_88 . V_192 = & V_2 -> V_87 ;
V_8 = F_100 ( & V_2 -> V_88 , V_197 , - 1 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_41 ,
V_8 ) ;
goto V_198;
}
F_92 ( V_2 -> V_2 , L_42 ,
F_101 ( & V_2 -> V_88 ) ) ;
F_102 ( V_2 -> V_2 , L_43 ) ;
return 0 ;
V_195:
F_79 ( & V_2 -> V_153 ) ;
V_198:
F_80 ( & V_2 -> V_85 ) ;
V_176:
F_81 ( V_2 ) ;
return V_8 ;
}
