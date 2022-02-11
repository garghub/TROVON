static struct V_1 * F_1 ( int V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] . V_9 ;
struct V_1 * V_10 = NULL ;
F_2 (report, feature_report_list, list) {
if ( V_10 -> V_2 == V_2 )
return V_10 ;
}
F_3 ( V_4 , L_1 , V_2 ) ;
return NULL ;
}
static struct V_11 * F_4 ( struct V_3 * V_4 ,
int V_12 , const T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_11 * V_17 ;
struct V_1 * V_10 = F_6 ( V_12 , V_4 ) ;
unsigned long V_18 ;
int V_19 , V_20 , V_21 ;
if ( ! V_10 || ! V_16 )
return NULL ;
if ( V_16 -> V_22 & V_23 )
return NULL ;
V_17 = F_7 ( sizeof( * V_17 ) , V_24 ) ;
if ( ! V_17 )
return NULL ;
F_8 ( & V_17 -> V_25 ) ;
V_17 -> V_26 = V_10 ;
V_17 -> V_27 = NULL ;
V_17 -> V_28 = 0 ;
F_9 ( & V_16 -> V_29 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
for ( V_19 = V_21 = 0 ; V_19 < V_10 -> V_31 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < V_10 -> V_32 [ V_19 ] -> V_33 ; V_20 ++ ) {
F_11 ( V_10 -> V_32 [ V_19 ] , V_20 , V_21 < V_14 ? V_13 [ V_21 ] : 0 ) ;
V_21 ++ ;
}
V_16 -> V_34 = V_17 ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
F_14 ( & V_17 -> V_25 , V_36 * 2 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
V_16 -> V_34 = NULL ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
F_15 ( & V_16 -> V_29 ) ;
return V_17 ;
}
static int F_16 ( struct V_3 * V_4 , int V_37 , int V_38 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_1 * V_39 = F_6 ( V_40 , V_4 ) ;
struct V_1 * V_41 = F_6 ( V_42 , V_4 ) ;
unsigned long V_18 ;
T_1 * V_43 ;
int V_19 ;
if ( ! V_39 || V_39 -> V_31 != 1 || ! V_41 || V_41 -> V_31 != 1 )
return - V_44 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 0 , V_37 << 2 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 1 , 0x02 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 2 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 3 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 4 , 0xb8 | V_38 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 5 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 6 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 7 , 0x40 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 8 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 9 , 0x00 ) ;
F_11 ( V_39 -> V_32 [ 0 ] , 10 , 32 ) ;
F_11 ( V_41 -> V_32 [ 0 ] , 0 , ( V_37 << 2 ) | 0x01 ) ;
F_11 ( V_41 -> V_32 [ 0 ] , 1 , 0x00 ) ;
F_11 ( V_41 -> V_32 [ 0 ] , 2 , 0x00 ) ;
F_11 ( V_41 -> V_32 [ 0 ] , 3 , 32 ) ;
V_43 = V_16 -> V_45 + ( V_38 * 4 + V_37 ) * 64 ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ )
if ( V_19 < 32 )
F_11 ( V_39 -> V_32 [ 0 ] , 11 + V_19 , V_43 [ V_19 ] ) ;
else
F_11 ( V_41 -> V_32 [ 0 ] , 4 + V_19 - 32 , V_43 [ V_19 ] ) ;
F_12 ( V_16 -> V_4 , V_39 , V_35 ) ;
F_12 ( V_16 -> V_4 , V_41 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
return 0 ;
}
static int F_17 ( T_1 * V_46 , const T_1 * V_47 , int V_48 ,
int V_37 , int V_38 )
{
int V_19 , V_49 , V_50 = 0 ;
T_1 V_43 [ 64 ] ;
T_1 * V_51 = V_46 + ( V_38 * 4 + V_37 ) * 64 ;
if ( V_48 == 1 ) {
for ( V_49 = 7 ; V_49 >= 0 ; V_49 -- ) {
const T_1 * V_52 = V_47 + V_38 * 256 + V_37 * 8 + V_49 * 32 ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ ) {
V_43 [ V_19 ] <<= 1 ;
V_43 [ V_19 ] |= ( V_52 [ V_19 / 8 ] >> ( V_19 % 8 ) ) & 0x01 ;
}
}
} else if ( V_48 == 8 ) {
for ( V_49 = 7 ; V_49 >= 0 ; V_49 -- ) {
const T_1 * V_52 = V_47 + ( V_38 * 256 + V_37 * 8 + V_49 * 32 ) * 8 ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ ) {
V_43 [ V_19 ] <<= 1 ;
V_43 [ V_19 ] |= ( V_52 [ V_19 ] & 0x80 ) ? 0x01 : 0x00 ;
}
}
} else {
F_18 ( 1 ) ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ )
if ( V_43 [ V_19 ] != V_51 [ V_19 ] ) {
V_50 = 1 ;
V_51 [ V_19 ] = V_43 [ V_19 ] ;
}
return V_50 ;
}
static int F_19 ( struct V_15 * V_16 , int V_53 )
{
struct V_1 * V_10 = F_6 ( V_54 , V_16 -> V_4 ) ;
int V_19 , V_20 ;
unsigned long V_18 ;
static const T_1 V_55 [ 8 ] = { 0x00 , 0x02 , 0x00 , 0x64 , 0x3f , 0x00 , 0x64 , 0xc0 } ;
if ( ! V_10 || V_10 -> V_31 != 1 )
return - V_44 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < V_10 -> V_32 [ 0 ] -> V_56 ; V_20 ++ )
if ( V_20 == 0 )
F_11 ( V_10 -> V_32 [ 0 ] , V_20 , V_19 << 2 ) ;
else if ( V_20 < sizeof( V_55 ) )
F_11 ( V_10 -> V_32 [ 0 ] , V_20 , V_55 [ V_20 ] ) ;
else
F_11 ( V_10 -> V_32 [ 0 ] , V_20 , 0 ) ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
}
V_16 -> V_22 |= V_57 ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
if ( V_16 -> V_58 ) {
if ( V_53 ) {
memset ( V_16 -> V_45 , 0 , V_59 ) ;
memset ( V_16 -> V_58 , 0 , V_59 * V_16 -> V_60 ) ;
}
V_16 -> V_61 = 1 ;
}
if ( V_16 -> V_62 )
F_20 ( & V_16 -> V_62 -> V_63 , 0 ) ;
return 0 ;
}
static void F_21 ( struct V_15 * V_16 )
{
int V_37 , V_38 , V_64 ;
unsigned long V_18 ;
if ( ! V_16 )
return;
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( ! ( V_16 -> V_22 & V_57 ) ) {
F_13 ( & V_16 -> V_30 , V_18 ) ;
F_19 ( V_16 , 0 ) ;
} else {
F_13 ( & V_16 -> V_30 , V_18 ) ;
}
V_64 = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ )
if ( F_17 ( V_16 -> V_45 ,
V_16 -> V_58 , V_16 -> V_60 , V_37 , V_38 ) ||
V_16 -> V_61 ) {
V_64 += 2 ;
if ( ! V_16 -> V_62 -> V_65 )
return;
if ( V_64 >= V_66 / 2 ) {
F_22 ( V_16 -> V_4 ) ;
V_64 = 0 ;
}
F_16 ( V_16 -> V_4 , V_37 , V_38 ) ;
}
V_16 -> V_61 = false ;
if ( V_64 )
F_22 ( V_16 -> V_4 ) ;
}
static void F_23 ( struct V_62 * V_67 ,
const struct V_68 * V_69 )
{
if ( ! V_67 -> V_65 )
return;
F_24 ( V_67 , V_69 ) ;
F_20 ( & V_67 -> V_63 , 0 ) ;
}
static void F_25 ( struct V_62 * V_67 ,
const struct V_70 * V_71 )
{
if ( ! V_67 -> V_65 )
return;
F_26 ( V_67 , V_71 ) ;
F_20 ( & V_67 -> V_63 , 0 ) ;
}
static void F_27 ( struct V_62 * V_67 , const struct V_72 * V_73 )
{
if ( ! V_67 -> V_65 )
return;
F_28 ( V_67 , V_73 ) ;
F_20 ( & V_67 -> V_63 , 0 ) ;
}
static T_2 F_29 ( struct V_62 * V_67 , const char T_3 * V_74 ,
T_4 V_75 , T_5 * V_76 )
{
T_2 V_77 ;
if ( ! V_67 -> V_65 )
return - V_44 ;
V_77 = F_30 ( V_67 , V_74 , V_75 , V_76 ) ;
if ( V_77 >= 0 )
F_20 ( & V_67 -> V_63 , 0 ) ;
return V_77 ;
}
static int F_31 ( int V_78 , struct V_62 * V_67 )
{
if ( ! V_67 -> V_65 )
return - V_44 ;
return 0 ;
}
static void F_32 ( struct V_62 * V_67 )
{
struct V_15 * V_16 = V_67 -> V_65 ;
T_6 * V_79 = V_67 -> V_80 ;
int V_81 ;
V_67 -> V_65 = NULL ;
if ( V_16 )
V_16 -> V_62 = NULL ;
F_33 ( V_67 ) ;
V_79 -- ;
F_9 ( & V_67 -> V_30 ) ;
( * V_79 ) -- ;
V_81 = ! * V_79 ;
F_15 ( & V_67 -> V_30 ) ;
if ( V_81 ) {
F_34 ( ( T_1 * ) V_67 -> V_82 . V_83 ) ;
F_35 ( V_67 ) ;
}
}
static int F_36 ( struct V_84 * V_85 , struct V_62 * V_67 )
{
T_7 V_48 = V_85 -> V_86 ;
T_7 V_87 = V_85 -> V_87 ;
* V_85 = V_88 ;
V_85 -> V_87 = V_87 ;
if ( V_48 >= 8 ) {
V_85 -> V_86 = 8 ;
V_85 -> V_89 . V_90 = 8 ;
V_85 -> V_91 . V_90 = 8 ;
V_85 -> V_92 . V_90 = 8 ;
} else {
V_85 -> V_86 = 1 ;
V_85 -> V_89 . V_90 = 1 ;
V_85 -> V_91 . V_90 = 1 ;
V_85 -> V_92 . V_90 = 1 ;
}
return 0 ;
}
static int F_37 ( struct V_62 * V_67 )
{
struct V_15 * V_16 = V_67 -> V_65 ;
T_1 * V_93 , * V_94 ;
if ( ! V_16 )
return - V_44 ;
if ( V_67 -> V_85 . V_86 == V_16 -> V_60 )
return 0 ;
if ( V_67 -> V_85 . V_86 != 1 && V_67 -> V_85 . V_86 != 8 )
return - V_95 ;
V_94 = V_16 -> V_58 ;
V_93 = F_38 ( V_59 * V_67 -> V_85 . V_86 , V_24 ) ;
if ( ! V_93 )
return - V_96 ;
if ( V_67 -> V_85 . V_86 == 1 ) {
int V_19 , V_49 ;
for ( V_19 = 0 ; V_19 < V_59 ; V_19 ++ ) {
T_1 V_97 = 0 ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_97 <<= 1 ;
V_97 |= V_94 [ V_19 * 8 + V_49 ] ? 0x01 : 0x00 ;
}
V_93 [ V_19 ] = V_97 ;
}
memcpy ( V_94 , V_93 , V_59 ) ;
V_67 -> V_82 . V_98 = V_99 ;
V_67 -> V_82 . V_100 = V_101 / 8 ;
} else {
int V_19 ;
memcpy ( V_93 , V_94 , V_59 ) ;
for ( V_19 = 0 ; V_19 < V_59 * 8 ; V_19 ++ )
V_94 [ V_19 ] = V_93 [ V_19 / 8 ] & ( 0x01 << ( 7 - V_19 % 8 ) ) ? 0xff : 0x00 ;
V_67 -> V_82 . V_98 = V_102 ;
V_67 -> V_82 . V_100 = V_101 ;
}
F_39 ( V_93 ) ;
V_16 -> V_60 = V_67 -> V_85 . V_86 ;
return 0 ;
}
static void F_40 ( struct V_103 * V_16 )
{
struct V_104 * V_105 ;
unsigned long V_18 ;
do {
F_10 ( & V_106 , V_18 ) ;
V_105 = V_107 ;
V_107 = V_105 ? V_105 -> V_108 : NULL ;
F_13 ( & V_106 , V_18 ) ;
if ( V_105 ) {
T_1 * V_109 = ( T_1 * ) V_105 -> V_67 -> V_82 . V_83 ;
F_9 ( & V_105 -> V_67 -> V_30 ) ;
F_15 ( & V_105 -> V_67 -> V_30 ) ;
F_35 ( V_105 -> V_67 ) ;
F_34 ( V_109 ) ;
}
} while ( V_105 );
}
static int F_41 ( struct V_62 * V_67 , int V_110 )
{
T_6 * V_79 = V_67 -> V_80 ;
V_79 -- ;
( * V_79 ) ++ ;
return 0 ;
}
static int F_42 ( struct V_62 * V_67 , int V_110 )
{
T_6 * V_79 = V_67 -> V_80 ;
V_79 -- ;
( * V_79 ) ++ ;
if ( ! * V_79 ) {
unsigned long V_18 ;
struct V_104 * V_105 = (struct V_104 * ) V_79 ;
V_105 -- ;
F_10 ( & V_106 , V_18 ) ;
V_105 -> V_108 = V_107 ;
V_107 = V_105 ;
F_13 ( & V_106 , V_18 ) ;
F_43 ( & V_111 ) ;
}
return 0 ;
}
static void F_44 ( struct V_62 * V_67 , struct V_6 * V_112 )
{
F_21 ( V_67 -> V_65 ) ;
}
static T_2 F_45 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_74 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
unsigned V_19 , V_117 = V_16 -> V_117 ;
T_4 V_77 = 0 ;
for ( V_19 = 1 ; V_19 <= V_118 ; V_19 ++ )
if ( V_77 >= V_119 )
break;
else if ( V_19 == V_117 )
V_77 += snprintf ( V_74 + V_77 , V_119 - V_77 , L_2 , V_19 ) ;
else
V_77 += snprintf ( V_74 + V_77 , V_119 - V_77 , L_3 , V_19 ) ;
if ( V_77 > 0 )
V_74 [ F_47 ( V_77 , ( T_4 ) V_119 ) - 1 ] = '\n' ;
return V_77 ;
}
static T_2 F_48 ( struct V_113 * V_114 ,
struct V_115 * V_116 , const char * V_74 , T_4 V_75 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
int V_19 ;
unsigned V_110 ;
if ( V_75 < 1 || V_75 > 10 )
return - V_95 ;
V_19 = sscanf ( V_74 , L_4 , & V_110 ) ;
if ( V_19 != 1 )
return - V_95 ;
if ( V_110 > V_118 )
return - V_120 ;
else if ( V_110 == 0 )
V_110 = V_121 ;
V_16 -> V_117 = V_110 ;
V_16 -> V_122 . V_123 = V_36 / V_16 -> V_117 ;
return V_75 ;
}
static int F_49 ( struct V_15 * V_16 )
{
struct V_113 * V_114 = & V_16 -> V_4 -> V_114 ;
struct V_62 * V_67 = NULL ;
int V_19 , error = - V_96 ;
T_1 * V_45 = NULL ;
T_1 * V_58 = NULL ;
T_6 * V_124 ;
V_58 = F_50 ( V_59 * 8 ) ;
if ( V_58 == NULL ) {
F_51 ( V_114 , L_5 ) ;
goto V_125;
}
V_45 = F_38 ( V_59 , V_24 ) ;
if ( V_45 == NULL ) {
F_51 ( V_114 , L_6 ) ;
goto V_125;
}
V_16 -> V_117 = V_121 ;
V_16 -> V_122 = V_126 ;
V_67 = F_52 ( 257 * sizeof( T_6 ) + sizeof( struct V_104 ) , V_114 ) ;
if ( V_67 == NULL ) {
F_51 ( V_114 , L_7 ) ;
goto V_125;
}
V_124 = V_67 -> V_65 + sizeof( struct V_104 ) ;
* V_124 = 1 ;
V_124 ++ ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 ++ )
V_124 [ V_19 ] = V_19 > 0 && V_19 < 16 ? 0xff : 0 ;
V_67 -> V_80 = V_124 ;
V_67 -> V_127 = & V_16 -> V_122 ;
V_67 -> V_128 = ( char V_129 V_130 * ) V_58 ;
V_67 -> V_131 = & V_132 ;
V_67 -> V_85 = V_88 ;
V_67 -> V_82 = V_133 ;
V_67 -> V_82 . V_134 = V_59 * 8 ;
V_67 -> V_82 . V_83 = ( unsigned long ) V_58 ;
V_67 -> V_65 = V_16 ;
V_67 -> V_18 = V_135 ;
V_16 -> V_45 = V_45 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_60 = V_88 . V_86 ;
error = F_19 ( V_16 , 1 ) ;
if ( error ) {
F_51 ( V_114 , L_8 ) ;
goto V_136;
}
error = F_53 ( V_114 , & V_137 ) ;
if ( error ) {
F_51 ( V_114 , L_9 ) ;
goto V_136;
}
F_54 ( V_67 ) ;
V_16 -> V_62 = V_67 ;
error = F_55 ( V_67 ) ;
if ( error ) {
F_51 ( V_114 , L_10 ) ;
goto V_138;
}
V_16 -> V_61 = 1 ;
F_20 ( & V_67 -> V_63 , 0 ) ;
return 0 ;
V_138:
F_33 ( V_67 ) ;
F_56 ( V_114 , & V_137 ) ;
V_136:
V_16 -> V_45 = NULL ;
V_16 -> V_58 = NULL ;
V_16 -> V_60 = 0 ;
V_16 -> V_62 = NULL ;
V_125:
F_35 ( V_67 ) ;
F_34 ( V_58 ) ;
F_39 ( V_45 ) ;
return error ;
}
static void F_57 ( struct V_15 * V_16 )
{
struct V_62 * V_67 = V_16 -> V_62 ;
T_1 * V_45 = V_16 -> V_45 ;
if ( ! V_67 )
return;
V_67 -> V_65 = NULL ;
F_56 ( & V_16 -> V_4 -> V_114 , & V_137 ) ;
F_58 ( V_67 ) ;
V_16 -> V_45 = NULL ;
V_16 -> V_58 = NULL ;
V_16 -> V_60 = 0 ;
V_16 -> V_62 = NULL ;
F_39 ( V_45 ) ;
}
static inline int F_19 ( struct V_15 * V_16 , int V_53 )
{
return 0 ;
}
static inline int F_49 ( struct V_15 * V_16 )
{
return 0 ;
}
static inline void F_57 ( struct V_15 * V_16 )
{
}
static int F_59 ( struct V_139 * V_140 )
{
struct V_15 * V_16 = F_60 ( V_140 ) ;
return V_16 -> V_141 ;
}
static int F_61 ( struct V_139 * V_140 )
{
struct V_15 * V_16 = F_60 ( V_140 ) ;
struct V_1 * V_10 = F_6 ( V_142 , V_16 -> V_4 ) ;
unsigned long V_18 ;
if ( ! V_10 || V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 )
return - V_44 ;
V_16 -> V_141 = V_140 -> V_143 . V_144 & 0x0ff ;
V_16 -> V_145 = V_140 -> V_143 . V_146 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , V_16 -> V_145 == V_147 ? V_16 -> V_141 : 0 ) ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
return 0 ;
}
static int F_62 ( struct V_139 * V_140 , struct V_62 * V_109 )
{
return V_109 && V_109 == F_63 ( (struct V_15 * ) F_60 ( V_140 ) ) ;
}
static int F_64 ( struct V_15 * V_16 , struct V_1 * V_10 )
{
struct V_113 * V_114 = & V_16 -> V_4 -> V_114 ;
struct V_139 * V_140 ;
struct V_148 V_143 ;
if ( ! V_10 )
return - V_44 ;
if ( V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 ||
V_10 -> V_32 [ 0 ] -> V_149 != 8 ) {
F_51 ( V_114 , L_11 ) ;
return - V_95 ;
}
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . type = V_150 ;
V_143 . V_151 = 0xff ;
V_140 = F_65 ( F_66 ( V_114 ) , V_114 , V_16 ,
& V_152 , & V_143 ) ;
if ( F_67 ( V_140 ) ) {
F_51 ( V_114 , L_12 ) ;
return F_68 ( V_140 ) ;
}
V_140 -> V_143 . V_144 = 0xff ;
V_16 -> V_141 = 0xff ;
V_16 -> V_153 = V_140 ;
F_61 ( V_140 ) ;
return 0 ;
}
static void F_69 ( struct V_15 * V_16 )
{
struct V_139 * V_140 = V_16 -> V_153 ;
V_16 -> V_153 = NULL ;
if ( V_140 )
F_70 ( V_140 ) ;
}
static inline int F_71 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_153 )
return 0 ;
return F_61 ( V_16 -> V_153 ) ;
}
static void F_72 ( struct V_15 * V_16 )
{
int V_154 = V_16 -> V_145 ;
if ( ! V_16 -> V_153 )
return;
V_16 -> V_153 -> V_143 . V_146 = V_155 ;
F_61 ( V_16 -> V_153 ) ;
V_16 -> V_145 = V_16 -> V_153 -> V_143 . V_146 = V_154 ;
}
static inline int F_64 ( struct V_15 * V_16 ,
struct V_1 * V_10 )
{
return 0 ;
}
static inline void F_69 ( struct V_15 * V_16 )
{
}
static inline int F_71 ( struct V_15 * V_16 )
{
return 0 ;
}
static inline void F_72 ( struct V_15 * V_16 )
{
}
static int F_73 ( struct V_156 * V_157 )
{
struct V_15 * V_16 = F_74 ( V_157 ) ;
return V_16 -> V_158 ;
}
static int F_75 ( struct V_156 * V_157 , int V_159 )
{
struct V_15 * V_16 = F_74 ( V_157 ) ;
struct V_1 * V_10 = F_6 ( V_160 , V_16 -> V_4 ) ;
unsigned long V_18 ;
if ( ! V_10 || V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 )
return - V_44 ;
V_16 -> V_158 = V_159 & 0x0ff ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , V_16 -> V_158 ) ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
return 0 ;
}
static int F_76 ( struct V_156 * V_157 , struct V_62 * V_109 )
{
return V_109 && V_109 == F_63 ( (struct V_15 * ) F_74 ( V_157 ) ) ;
}
static int F_77 ( struct V_15 * V_16 , struct V_1 * V_10 )
{
struct V_113 * V_114 = & V_16 -> V_4 -> V_114 ;
struct V_156 * V_157 ;
if ( ! V_10 )
return - V_44 ;
if ( V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 ||
V_10 -> V_32 [ 0 ] -> V_149 != 8 ) {
F_51 ( V_114 , L_13 ) ;
return - V_95 ;
}
V_157 = F_78 ( F_66 ( V_114 ) , V_114 , V_16 , & V_161 ) ;
if ( F_67 ( V_157 ) ) {
F_51 ( V_114 , L_14 ) ;
return F_68 ( V_157 ) ;
}
V_157 -> V_143 . V_162 = 0x0ff ;
V_16 -> V_158 = 0xe5 ;
V_16 -> V_163 = V_157 ;
F_75 ( V_157 , 0xe5 ) ;
return 0 ;
}
static void F_79 ( struct V_15 * V_16 )
{
struct V_156 * V_157 = V_16 -> V_163 ;
V_16 -> V_163 = NULL ;
if ( V_157 )
F_80 ( V_157 ) ;
}
static inline int F_81 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_163 )
return 0 ;
return F_75 ( V_16 -> V_163 , V_16 -> V_158 ) ;
}
static inline int F_77 ( struct V_15 * V_16 ,
struct V_1 * V_10 )
{
return 0 ;
}
static inline void F_79 ( struct V_15 * V_16 )
{
}
static inline int F_81 ( struct V_15 * V_16 )
{
return 0 ;
}
static void F_82 ( struct V_15 * V_16 )
{
struct V_1 * V_10 ;
unsigned long V_18 ;
if ( ! V_16 -> V_164 [ 0 ] )
return;
V_10 = F_6 ( V_165 , V_16 -> V_4 ) ;
if ( ! V_10 || V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 )
return;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , V_16 -> V_166 ) ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
}
static void F_83 ( struct V_167 * V_168 ,
enum V_169 V_170 )
{
struct V_113 * V_114 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_19 , V_171 = 0 ;
V_114 = V_168 -> V_114 -> V_172 ;
V_4 = F_84 ( V_114 , struct V_3 , V_114 ) ;
V_16 = F_5 ( V_4 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_168 != V_16 -> V_164 [ V_19 ] )
continue;
V_171 = ( V_16 -> V_166 >> V_19 ) & 1 ;
if ( V_170 == V_173 && V_171 ) {
V_16 -> V_166 &= ~ ( 1 << V_19 ) ;
F_82 ( V_16 ) ;
} else if ( V_170 != V_173 && ! V_171 ) {
V_16 -> V_166 |= 1 << V_19 ;
F_82 ( V_16 ) ;
}
break;
}
}
static enum V_169 F_85 ( struct V_167 * V_168 )
{
struct V_113 * V_114 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_19 , V_170 = 0 ;
V_114 = V_168 -> V_114 -> V_172 ;
V_4 = F_84 ( V_114 , struct V_3 , V_114 ) ;
V_16 = F_5 ( V_4 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
if ( V_168 == V_16 -> V_164 [ V_19 ] ) {
V_170 = ( V_16 -> V_166 >> V_19 ) & 1 ;
break;
}
return V_170 ? V_174 : V_173 ;
}
static int F_86 ( struct V_15 * V_16 , struct V_1 * V_10 )
{
struct V_113 * V_114 = & V_16 -> V_4 -> V_114 ;
struct V_167 * V_164 ;
T_4 V_175 = strlen ( F_66 ( V_114 ) ) + 8 ;
char * V_176 ;
int V_19 , V_77 = 0 ;
if ( ! V_10 )
return - V_44 ;
if ( V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 1 ||
V_10 -> V_32 [ 0 ] -> V_149 != 8 ) {
F_51 ( V_114 , L_15 ) ;
return - V_95 ;
}
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_164 = F_7 ( sizeof( struct V_167 ) + V_175 , V_24 ) ;
if ( ! V_164 ) {
F_51 ( V_114 , L_16 , V_19 ) ;
V_77 = - V_96 ;
goto V_177;
}
V_176 = ( void * ) ( & V_164 [ 1 ] ) ;
snprintf ( V_176 , V_175 , L_17 , F_66 ( V_114 ) , V_19 ) ;
V_164 -> V_176 = V_176 ;
V_164 -> V_144 = 0 ;
V_164 -> V_151 = 1 ;
V_164 -> V_178 = F_85 ;
V_164 -> V_179 = F_83 ;
V_16 -> V_164 [ V_19 ] = V_164 ;
V_77 = F_87 ( V_114 , V_16 -> V_164 [ V_19 ] ) ;
if ( V_77 ) {
V_16 -> V_164 [ V_19 ] = NULL ;
F_39 ( V_164 ) ;
F_51 ( V_114 , L_18 , V_19 ) ;
goto V_177;
}
}
return 0 ;
V_177:
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
if ( V_16 -> V_164 [ V_19 ] ) {
V_164 = V_16 -> V_164 [ V_19 ] ;
V_16 -> V_164 [ V_19 ] = NULL ;
F_88 ( V_164 ) ;
F_39 ( V_164 ) ;
}
return V_77 ;
}
static void F_89 ( struct V_15 * V_16 )
{
struct V_167 * V_164 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_164 = V_16 -> V_164 [ V_19 ] ;
V_16 -> V_164 [ V_19 ] = NULL ;
if ( ! V_164 )
continue;
F_88 ( V_164 ) ;
F_39 ( V_164 ) ;
}
}
static inline int F_86 ( struct V_15 * V_16 ,
struct V_1 * V_10 )
{
return 0 ;
}
static inline void F_89 ( struct V_15 * V_16 )
{
}
static inline int F_82 ( struct V_15 * V_16 )
{
return 0 ;
}
static int F_90 ( struct V_15 * V_16 ,
struct V_1 * V_10 , T_1 * V_13 , int V_14 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
unsigned int V_180 ;
if ( V_13 [ V_19 ] == 0 )
continue;
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_181 ) ; V_20 ++ )
if ( V_16 -> V_181 [ V_20 ] == V_13 [ V_19 ] )
goto V_182;
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_181 ) ; V_20 ++ )
if ( V_16 -> V_181 [ V_20 ] == 0 ) {
V_16 -> V_181 [ V_20 ] = V_13 [ V_19 ] ;
break;
}
F_91 ( V_16 -> V_183 , V_184 , V_185 , V_13 [ V_19 ] ) ;
if ( V_13 [ V_19 ] < V_186 )
V_180 = V_16 -> V_187 [ V_13 [ V_19 ] ] ;
else
V_180 = V_188 ;
if ( V_180 != V_188 ) {
F_92 ( V_189 L_19 ,
V_13 [ V_19 ] , V_180 ) ;
F_93 ( V_16 -> V_183 , V_180 , 1 ) ;
}
F_94 ( V_16 -> V_183 ) ;
V_182:
continue;
}
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_181 ) ; V_20 ++ ) {
unsigned int V_180 ;
if ( V_16 -> V_181 [ V_20 ] == 0 )
continue;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
if ( V_16 -> V_181 [ V_20 ] == V_13 [ V_19 ] )
goto V_190;
F_91 ( V_16 -> V_183 , V_184 , V_185 , V_16 -> V_181 [ V_20 ] ) ;
if ( V_16 -> V_181 [ V_20 ] < V_186 )
V_180 = V_16 -> V_187 [ V_16 -> V_181 [ V_20 ] ] ;
else
V_180 = V_188 ;
if ( V_180 != V_188 ) {
F_92 ( V_189 L_20 ,
V_16 -> V_181 [ V_20 ] , V_180 ) ;
F_93 ( V_16 -> V_183 , V_180 , 0 ) ;
}
F_94 ( V_16 -> V_183 ) ;
V_16 -> V_181 [ V_20 ] = 0 ;
V_190:
continue;
}
return 1 ;
}
static int F_95 ( struct V_15 * V_16 ,
struct V_1 * V_10 , T_1 * V_13 , int V_14 )
{
return 1 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_11 * V_191 ;
int V_77 = 0 ;
if ( ! V_16 )
return - V_44 ;
V_191 = F_4 ( V_4 , V_192 , NULL , 0 ) ;
if ( ! V_191 ) {
F_97 ( V_4 , L_21 ) ;
return - V_44 ;
}
if ( V_191 -> V_28 == 2 ) {
V_16 -> V_193 [ 0 ] = V_191 -> V_13 [ 1 ] ;
V_16 -> V_193 [ 1 ] = V_191 -> V_13 [ 0 ] ;
if ( V_16 -> V_22 & V_194 ) {
F_98 ( V_4 , L_22 ,
V_191 -> V_13 [ 1 ] , V_191 -> V_13 [ 0 ] ) ;
} else {
F_98 ( V_4 , L_23 ,
V_191 -> V_13 [ 1 ] , V_191 -> V_13 [ 0 ] ) ;
}
} else {
F_97 ( V_4 , L_24 ) ;
V_77 = - V_95 ;
}
F_39 ( V_191 ) ;
return V_77 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_1 * V_10 = F_6 ( V_195 , V_4 ) ;
unsigned long V_18 ;
int error ;
if ( ! V_16 || ! V_10 || V_10 -> V_31 != 1 )
return - V_44 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_4 -> V_196 == V_197 )
V_16 -> V_22 |= V_194 ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , 1 ) ;
F_12 ( V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
error = F_96 ( V_4 ) ;
if ( error )
return error ;
F_81 ( V_16 ) ;
F_71 ( V_16 ) ;
#ifdef F_100
if ( V_16 -> V_62 )
F_20 ( & V_16 -> V_62 -> V_63 , 0 ) ;
#endif
F_82 ( V_16 ) ;
return 0 ;
}
static T_2 F_101 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_74 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
if ( V_16 -> V_22 & V_194 )
return snprintf ( V_74 , V_119 , L_25 ) ;
else
return snprintf ( V_74 , V_119 , L_26 ) ;
}
static T_2 F_102 ( struct V_113 * V_114 ,
struct V_115 * V_116 , const char * V_74 , T_4 V_75 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
struct V_1 * V_10 = NULL ;
T_4 V_198 = V_75 ;
int V_199 = V_16 -> V_200 ;
unsigned long V_18 ;
if ( V_198 >= 3 && strncmp ( L_27 , V_74 , 3 ) == 0 ) {
if ( V_16 -> V_22 & V_194 )
V_10 = F_6 ( V_201 , V_16 -> V_4 ) ;
V_74 += 3 ;
V_198 -= 3 ;
} else if ( V_198 >= 10 && strncmp ( L_28 , V_74 , 10 ) == 0 ) {
if ( ! ( V_16 -> V_22 & V_194 ) )
V_10 = F_6 ( V_202 , V_16 -> V_4 ) ;
V_74 += 10 ;
V_198 -= 10 ;
}
if ( ! V_10 )
return - V_95 ;
while ( V_198 > 0 && ( V_74 [ V_198 - 1 ] == '\n' || V_74 [ V_198 - 1 ] == '\r' ) )
V_198 -- ;
if ( V_198 != 0 )
return - V_95 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , V_199 & 0xff ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 1 , ( V_199 >> 8 ) & 0xff ) ;
F_12 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
return V_75 ;
}
static T_2 F_103 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_74 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
return snprintf ( V_74 , V_119 , L_29 , V_16 -> V_200 ) ;
}
static T_2 F_104 ( struct V_113 * V_114 ,
struct V_115 * V_116 , const char * V_74 , T_4 V_75 )
{
struct V_15 * V_16 = F_46 ( V_114 ) ;
unsigned V_110 ;
if ( sscanf ( V_74 , L_4 , & V_110 ) != 1 )
return - V_95 ;
if ( V_110 > 30000 )
return - V_95 ;
else
V_16 -> V_200 = V_110 ;
return V_75 ;
}
static int F_105 ( struct V_203 * V_204 , void * V_97 )
{
if ( F_63 ( (struct V_15 * ) V_204 -> V_205 ) )
F_106 ( V_204 , L_30 ) ;
else
F_106 ( V_204 , L_31 ) ;
return 0 ;
}
static int F_107 ( struct V_206 * V_206 , struct V_207 * V_204 )
{
return F_108 ( V_204 , F_105 , V_206 -> V_208 ) ;
}
static T_2 F_109 ( struct V_207 * V_204 , const char T_3 * V_209 ,
T_4 V_75 , T_5 * V_76 )
{
struct V_15 * V_16 = ( (struct V_203 * ) V_204 -> V_210 ) -> V_205 ;
char V_74 [ 32 ] ;
T_4 V_198 = F_47 ( V_75 , sizeof( V_74 ) - 1 ) ;
if ( F_110 ( V_74 , V_209 , V_198 ) )
return - V_211 ;
while ( V_198 > 0 && ( V_74 [ V_198 - 1 ] == ' ' || V_74 [ V_198 - 1 ] == '\n' ) )
V_198 -- ;
V_74 [ V_198 ] = '\0' ;
if ( strcmp ( V_74 , L_32 ) == 0 ) {
F_99 ( V_16 -> V_4 ) ;
F_19 ( V_16 , 1 ) ;
} else if ( strcmp ( V_74 , L_33 ) == 0 ) {
F_19 ( V_16 , 1 ) ;
} else {
return - V_95 ;
}
return V_75 ;
}
static int F_111 ( struct V_206 * V_19 , struct V_207 * V_204 )
{
V_204 -> V_210 = V_19 -> V_208 ;
return 0 ;
}
static T_2 F_112 ( struct V_207 * V_204 , char T_3 * V_110 ,
T_4 V_212 , T_5 * V_213 )
{
struct V_15 * V_16 = V_204 -> V_210 ;
struct V_11 * V_214 ;
T_1 V_13 [ 3 ] ;
T_2 V_77 = - V_215 ;
if ( V_212 == 0 )
return - V_95 ;
if ( * V_213 > 0x0ff )
return 0 ;
V_13 [ 0 ] = * V_213 & 0xff ;
V_13 [ 1 ] = ( * V_213 >> 8 ) & 0xff ;
V_13 [ 2 ] = V_212 < 20 ? V_212 : 20 ;
if ( * V_213 + V_13 [ 2 ] > 0xff )
V_13 [ 2 ] = 0x100 - * V_213 ;
V_214 = F_4 ( V_16 -> V_4 , V_216 , V_13 ,
sizeof( V_13 ) ) ;
if ( ! V_214 )
return - V_215 ;
if ( V_214 -> V_27 && V_214 -> V_27 -> V_2 == V_217 ) {
V_77 = V_214 -> V_13 [ 2 ] ;
if ( V_77 > V_212 )
V_77 = V_212 ;
if ( F_113 ( V_110 , V_214 -> V_13 + 3 , V_77 ) )
V_77 = - V_211 ;
else
* V_213 += V_77 ;
}
F_39 ( V_214 ) ;
return V_77 ;
}
static T_2 F_114 ( struct V_207 * V_204 , const char T_3 * V_110 ,
T_4 V_212 , T_5 * V_213 )
{
struct V_15 * V_16 = V_204 -> V_210 ;
struct V_11 * V_214 ;
T_2 V_77 = - V_215 ;
T_1 V_13 [ 23 ] ;
if ( V_212 == 0 )
return - V_95 ;
if ( * V_213 > 0x0ff )
return - V_218 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] = * V_213 & 0xff ;
V_13 [ 1 ] = ( * V_213 >> 8 ) & 0xff ;
V_13 [ 2 ] = F_47 ( ( T_4 ) 20 , V_212 ) ;
if ( * V_213 + V_13 [ 2 ] > 0xff )
V_13 [ 2 ] = 0x100 - * V_213 ;
if ( F_110 ( V_13 + 3 , V_110 , F_47 ( ( T_1 ) 20 , V_13 [ 2 ] ) ) )
return - V_211 ;
V_214 = F_4 ( V_16 -> V_4 , V_219 , V_13 ,
sizeof( V_13 ) ) ;
if ( ! V_214 )
return - V_215 ;
if ( V_214 -> V_27 && V_214 -> V_27 -> V_2 == V_217 ) {
if ( memcmp ( V_13 , V_214 -> V_13 , 3 + V_13 [ 2 ] ) == 0 ) {
* V_213 += V_13 [ 2 ] ;
V_77 = V_13 [ 2 ] ;
}
}
F_39 ( V_214 ) ;
return V_77 ;
}
static int F_115 ( struct V_206 * V_19 , struct V_207 * V_204 )
{
V_204 -> V_210 = V_19 -> V_208 ;
return 0 ;
}
static int F_116 ( struct V_15 * V_16 , T_1 * V_74 , long V_213 )
{
V_74 [ 0 ] = V_213 & 0xff ;
V_74 [ 1 ] = ( V_213 >> 8 ) & 0xff ;
if ( V_16 -> V_220 == 3 )
V_74 [ 2 ] = ( V_213 >> 16 ) & 0xff ;
return V_16 -> V_220 == 2 ? 2 : 3 ;
}
static T_2 F_117 ( struct V_15 * V_16 , int V_12 ,
char T_3 * V_110 , T_4 V_212 , T_5 * V_213 )
{
struct V_11 * V_214 ;
T_1 V_13 [ 4 ] ;
T_2 V_77 = 0 ;
int V_221 , V_177 = - V_215 ;
while ( V_212 > 0 ) {
V_177 = - V_215 ;
V_221 = F_116 ( V_16 , V_13 , * V_213 ) ;
V_13 [ V_221 ] = V_212 > 32 ? 32 : V_212 ;
V_214 = F_4 ( V_16 -> V_4 , V_12 , V_13 , V_221 + 1 ) ;
if ( ! V_214 || ! V_214 -> V_27 )
goto V_222;
if ( V_214 -> V_27 -> V_2 == V_223 ||
V_214 -> V_27 -> V_2 == V_224 ) {
if ( memcmp ( V_13 , V_214 -> V_13 , V_221 + 1 ) != 0 )
goto V_222;
if ( F_113 ( V_110 + V_77 , V_214 -> V_13 + V_221 + 1 , V_13 [ V_221 ] ) ) {
V_177 = - V_211 ;
goto V_222;
}
* V_213 += V_13 [ V_221 ] ;
V_212 -= V_13 [ V_221 ] ;
V_77 += V_13 [ V_221 ] ;
V_177 = 0 ;
}
V_222:
F_39 ( V_214 ) ;
if ( V_177 )
return V_77 > 0 ? V_77 : V_177 ;
}
return V_77 ;
}
static T_2 F_118 ( struct V_207 * V_204 , char T_3 * V_110 ,
T_4 V_212 , T_5 * V_213 )
{
struct V_15 * V_16 = V_204 -> V_210 ;
if ( V_212 == 0 )
return - V_95 ;
if ( * V_213 > 0x05fff )
return 0 ;
if ( * V_213 + V_212 > 0x05fff )
V_212 = 0x06000 - * V_213 ;
if ( V_16 -> V_22 & V_194 )
return F_117 ( V_16 , V_224 , V_110 , V_212 , V_213 ) ;
else
return F_117 ( V_16 , V_225 , V_110 , V_212 , V_213 ) ;
}
static T_2 F_119 ( struct V_15 * V_16 , int V_12 ,
T_5 * V_213 )
{
struct V_11 * V_214 ;
T_1 V_13 [ 3 ] ;
int V_221 ;
T_2 V_77 = - V_215 ;
if ( * V_213 & 0x3f )
return - V_95 ;
V_221 = F_116 ( V_16 , V_13 , * V_213 ) ;
V_214 = F_4 ( V_16 -> V_4 , V_12 , V_13 , V_221 ) ;
if ( ! V_214 || ! V_214 -> V_27 )
goto V_222;
if ( V_214 -> V_27 -> V_2 == V_223 ||
V_214 -> V_27 -> V_2 == V_226 ) {
if ( memcmp ( V_13 , V_214 -> V_13 , V_221 ) != 0 )
goto V_222;
V_77 = 0 ;
}
V_222:
F_39 ( V_214 ) ;
return V_77 ;
}
static T_2 F_120 ( struct V_15 * V_16 , int V_12 ,
const char T_3 * V_110 , T_4 V_212 , T_5 * V_213 )
{
struct V_11 * V_214 ;
T_1 V_13 [ 36 ] ;
T_2 V_77 = 0 ;
int V_221 , V_177 = - V_215 ;
while ( V_212 > 0 ) {
V_177 = - V_215 ;
V_221 = F_116 ( V_16 , V_13 , * V_213 ) ;
V_13 [ V_221 ] = V_212 > 32 ? 32 : V_212 ;
if ( F_110 ( V_13 + V_221 + 1 , V_110 , V_13 [ V_221 ] ) ) {
V_177 = - V_211 ;
break;
}
V_214 = F_4 ( V_16 -> V_4 , V_12 , V_13 ,
V_221 + 1 + V_13 [ V_221 ] ) ;
if ( ! V_214 || ! V_214 -> V_27 )
goto V_222;
if ( V_214 -> V_27 -> V_2 == V_223 ||
V_214 -> V_27 -> V_2 == V_227 ) {
if ( memcmp ( V_13 , V_214 -> V_13 , V_221 + 1 + V_13 [ V_221 ] ) != 0 )
goto V_222;
* V_213 += V_13 [ V_221 ] ;
V_212 -= V_13 [ V_221 ] ;
V_77 += V_13 [ V_221 ] ;
V_177 = 0 ;
}
V_222:
F_39 ( V_214 ) ;
if ( V_177 )
break;
}
return V_77 > 0 ? V_77 : V_177 ;
}
static T_2 F_121 ( struct V_207 * V_204 , const char T_3 * V_110 ,
T_4 V_212 , T_5 * V_213 )
{
struct V_15 * V_16 = V_204 -> V_210 ;
T_2 V_177 , V_77 = 0 ;
int V_228 , V_229 ;
if ( V_212 == 0 )
return - V_95 ;
if ( * V_213 > 0x5fff )
return - V_218 ;
if ( V_212 & 0x3f )
return - V_95 ;
if ( * V_213 & 0x3f )
return - V_95 ;
if ( V_16 -> V_22 & V_194 ) {
V_228 = V_226 ;
V_229 = V_227 ;
} else {
V_228 = V_230 ;
V_229 = V_231 ;
}
F_9 ( & V_16 -> V_232 ) ;
while ( V_212 > 0 ) {
V_177 = F_119 ( V_16 , V_228 , V_213 ) ;
if ( V_177 )
break;
V_177 = F_120 ( V_16 , V_229 , V_110 , 64 , V_213 ) ;
if ( V_177 < 0 )
break;
V_77 += V_177 ;
* V_213 += V_177 ;
V_212 -= V_177 ;
if ( V_177 != 64 )
break;
}
F_15 ( & V_16 -> V_232 ) ;
return V_77 > 0 ? V_77 : V_177 ;
}
static void F_122 ( char * V_233 , T_4 V_234 , const T_1 * V_16 ,
const T_4 V_235 )
{
int V_19 , V_20 ;
for ( V_19 = V_20 = 0 ; V_19 < V_235 && V_20 + 3 < V_234 ; V_19 ++ ) {
V_233 [ V_20 ++ ] = V_236 [ ( V_16 [ V_19 ] >> 4 ) & 0x0f ] ;
V_233 [ V_20 ++ ] = V_236 [ V_16 [ V_19 ] & 0x0f ] ;
V_233 [ V_20 ++ ] = ' ' ;
}
if ( V_20 < V_234 ) {
V_233 [ V_20 -- ] = '\0' ;
V_233 [ V_20 ] = '\n' ;
} else
V_233 [ V_20 ] = '\0' ;
}
static void F_123 ( struct V_15 * V_16 ,
struct V_3 * V_4 , struct V_1 * V_10 )
{
T_1 V_13 [ 70 ] ;
int V_28 = ( V_10 -> V_14 >> 3 ) + 1 ;
char * V_237 ;
#define F_124 256
if ( ! V_4 -> V_238 )
return;
V_237 = F_38 ( F_124 , V_239 ) ;
if ( ! V_237 )
return;
snprintf ( V_237 , F_124 , L_34 ,
V_10 -> V_2 , V_28 ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_28 + 5 > sizeof( V_13 ) ) {
F_39 ( V_237 ) ;
F_125 ( V_4 , L_35 ) ;
return;
} else {
V_13 [ 0 ] = V_10 -> V_2 ;
F_126 ( V_10 , V_13 ) ;
F_122 ( V_237 , F_124 , V_13 , V_28 ) ;
F_125 ( V_4 , V_237 ) ;
}
switch ( V_10 -> V_2 ) {
case V_165 :
snprintf ( V_237 , F_124 , L_36 ,
L_37 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_38 , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_142 :
snprintf ( V_237 , F_124 , L_36 ,
L_39 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_40 , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_160 :
snprintf ( V_237 , F_124 , L_36 ,
L_41 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_42 , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_195 :
snprintf ( V_237 , F_124 , L_36 ,
L_43 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_44 ,
V_13 [ 2 ] , V_13 [ 1 ] , V_13 [ 2 ] << 8 | V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_54 :
snprintf ( V_237 , F_124 , L_36 ,
L_45 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_42 :
snprintf ( V_237 , F_124 , L_36 ,
L_45 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_40 :
snprintf ( V_237 , F_124 , L_36 ,
L_45 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_216 :
snprintf ( V_237 , F_124 , L_36 ,
L_46 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_219 :
snprintf ( V_237 , F_124 , L_36 ,
L_49 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 3 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
} else if ( V_13 [ 3 ] + 4 <= V_28 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 4 , V_13 [ 3 ] ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
}
F_125 ( V_4 , V_237 ) ;
break;
case V_230 :
case V_226 :
snprintf ( V_237 , F_124 , L_36 ,
L_53 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
switch ( V_16 -> V_220 ) {
case 2 :
snprintf ( V_237 , F_124 , L_54 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
break;
case 3 :
snprintf ( V_237 , F_124 , L_55 ,
V_13 [ 3 ] , V_13 [ 2 ] , V_13 [ 1 ] ) ;
break;
default:
snprintf ( V_237 , F_124 , L_56 ) ;
}
F_125 ( V_4 , V_237 ) ;
break;
case V_225 :
case V_224 :
snprintf ( V_237 , F_124 , L_36 ,
L_57 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
switch ( V_16 -> V_220 ) {
case 2 :
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
break;
case 3 :
snprintf ( V_237 , F_124 , L_58 ,
V_13 [ 3 ] , V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 4 ] ) ;
break;
default:
snprintf ( V_237 , F_124 , L_56 ) ;
}
F_125 ( V_4 , V_237 ) ;
break;
case V_231 :
case V_227 :
snprintf ( V_237 , F_124 , L_36 ,
L_59 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
switch ( V_16 -> V_220 ) {
case 2 :
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 3 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
} else if ( V_13 [ 3 ] + 4 <= V_28 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 4 , V_13 [ 3 ] ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
}
break;
case 3 :
snprintf ( V_237 , F_124 , L_58 ,
V_13 [ 3 ] , V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 4 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 4 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
} else if ( V_13 [ 4 ] + 5 <= V_28 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 5 , V_13 [ 4 ] ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
}
break;
default:
snprintf ( V_237 , F_124 , L_56 ) ;
}
F_125 ( V_4 , V_237 ) ;
break;
case V_240 :
break;
case V_202 :
snprintf ( V_237 , F_124 , L_36 ,
L_60 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_61 ,
V_13 [ 1 ] | ( V_13 [ 2 ] << 8 ) ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_192 :
snprintf ( V_237 , F_124 , L_36 ,
L_62 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_241 :
snprintf ( V_237 , F_124 , L_36 ,
L_63 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_242 :
snprintf ( V_237 , F_124 , L_36 ,
L_64 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_243 :
snprintf ( V_237 , F_124 , L_36 ,
L_65 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_201 :
snprintf ( V_237 , F_124 , L_36 ,
L_62 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_61 ,
V_13 [ 1 ] | ( V_13 [ 2 ] << 8 ) ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
default:
snprintf ( V_237 , F_124 , L_36 ,
L_66 , V_10 -> V_2 , V_28 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
}
F_127 ( & V_4 -> V_244 ) ;
F_39 ( V_237 ) ;
}
static void F_128 ( struct V_15 * V_16 ,
struct V_3 * V_4 , struct V_1 * V_10 ,
T_1 * V_13 , int V_14 )
{
char * V_237 ;
#define F_124 256
if ( ! V_4 -> V_238 )
return;
V_237 = F_38 ( F_124 , V_239 ) ;
if ( ! V_237 )
return;
switch ( V_10 -> V_2 ) {
case V_245 :
snprintf ( V_237 , F_124 , L_67 ,
L_68 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 2 ] < F_129 ( V_246 ) )
snprintf ( V_237 , F_124 , L_69 ,
V_13 [ 2 ] , V_246 [ V_13 [ 2 ] ] , V_13 [ 1 ] ) ;
else
snprintf ( V_237 , F_124 , L_70 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_247 :
snprintf ( V_237 , F_124 , L_67 ,
L_71 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 1 ] == 0 )
snprintf ( V_237 , F_124 , L_72 ) ;
else if ( V_13 [ 2 ] == 0 )
snprintf ( V_237 , F_124 , L_73 ,
V_13 [ 1 ] , V_13 [ 1 ] ) ;
else
snprintf ( V_237 , F_124 , L_74 ,
V_13 [ 1 ] , V_13 [ 1 ] , V_13 [ 2 ] , V_13 [ 2 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_248 :
snprintf ( V_237 , F_124 , L_67 ,
L_75 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 1 ] == 0 ) {
snprintf ( V_237 , F_124 , L_76 ) ;
F_125 ( V_4 , V_237 ) ;
} else if ( V_13 [ 1 ] + 1 <= V_14 ) {
snprintf ( V_237 , F_124 , L_77 ,
V_13 [ 1 ] - 1 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 2 , V_13 [ 1 ] - 1 ) ;
F_125 ( V_4 , V_237 ) ;
} else {
snprintf ( V_237 , F_124 , L_78 ,
V_13 [ 1 ] - 1 ) ;
F_125 ( V_4 , V_237 ) ;
}
break;
case V_217 :
snprintf ( V_237 , F_124 , L_67 ,
L_79 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 3 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
F_125 ( V_4 , V_237 ) ;
} else if ( V_13 [ 3 ] + 4 <= V_14 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 4 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
F_125 ( V_4 , V_237 ) ;
}
break;
case V_223 :
snprintf ( V_237 , F_124 , L_67 ,
L_80 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
switch ( V_16 -> V_220 ) {
case 2 :
snprintf ( V_237 , F_124 , L_47 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 3 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
} else if ( V_13 [ 3 ] + 4 <= V_14 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 4 , V_13 [ 3 ] ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
}
break;
case 3 :
snprintf ( V_237 , F_124 , L_58 ,
V_13 [ 3 ] , V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_48 , V_13 [ 4 ] ) ;
F_125 ( V_4 , V_237 ) ;
if ( V_13 [ 4 ] == 0 ) {
snprintf ( V_237 , F_124 , L_50 ) ;
} else if ( V_13 [ 4 ] + 5 <= V_14 ) {
snprintf ( V_237 , F_124 , L_51 ) ;
F_125 ( V_4 , V_237 ) ;
F_122 ( V_237 , F_124 , V_13 + 5 , V_13 [ 4 ] ) ;
} else {
snprintf ( V_237 , F_124 , L_52 ) ;
}
break;
default:
snprintf ( V_237 , F_124 , L_56 ) ;
}
F_125 ( V_4 , V_237 ) ;
break;
case V_192 :
snprintf ( V_237 , F_124 , L_67 ,
L_62 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_81 ,
V_13 [ 2 ] , V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_226 :
snprintf ( V_237 , F_124 , L_67 ,
L_82 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_224 :
snprintf ( V_237 , F_124 , L_67 ,
L_83 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_227 :
snprintf ( V_237 , F_124 , L_67 ,
L_84 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_241 :
snprintf ( V_237 , F_124 , L_67 ,
L_63 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_85 ,
V_13 [ 1 ] , V_13 [ 2 ] , V_13 [ 3 ] , V_13 [ 4 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_86 ,
V_13 [ 5 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_242 :
snprintf ( V_237 , F_124 , L_67 ,
L_64 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_87 ,
( V_13 [ 2 ] << 8 ) | V_13 [ 1 ] ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_88 ,
( V_13 [ 4 ] << 8 ) | V_13 [ 3 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
case V_243 :
snprintf ( V_237 , F_124 , L_67 ,
L_65 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
snprintf ( V_237 , F_124 , L_81 ,
V_13 [ 1 ] , V_13 [ 2 ] ) ;
F_125 ( V_4 , V_237 ) ;
break;
default:
snprintf ( V_237 , F_124 , L_67 ,
L_66 , V_10 -> V_2 , V_14 - 1 ) ;
F_125 ( V_4 , V_237 ) ;
break;
}
F_127 ( & V_4 -> V_244 ) ;
F_39 ( V_237 ) ;
}
static void F_130 ( struct V_15 * V_16 ,
struct V_1 * V_249 , struct V_1 * V_250 ,
struct V_1 * V_251 , struct V_1 * V_252 ,
struct V_1 * V_253 )
{
struct V_3 * V_4 = V_16 -> V_4 ;
F_131 ( & V_16 -> V_232 ) ;
if ( V_253 )
V_16 -> V_254 = F_132 ( L_89 , 0600 ,
V_4 -> V_255 , V_16 , & V_256 ) ;
if ( V_249 || V_250 )
V_16 -> V_257 = F_132 ( L_90 ,
( V_250 ? V_258 : 0 ) | ( V_249 ? V_259 : 0 ) ,
V_4 -> V_255 , V_16 , & V_260 ) ;
if ( V_251 && V_251 -> V_31 == 1 && V_251 -> V_32 [ 0 ] -> V_149 == 8 )
V_16 -> V_220 = V_251 -> V_32 [ 0 ] -> V_33 - 1 ;
else
V_16 -> V_220 = - 1 ;
if ( V_16 -> V_220 == 2 || V_16 -> V_220 == 3 ) {
V_16 -> V_261 = F_132 ( L_91 ,
( V_252 ? V_258 : 0 ) | ( V_251 ? V_259 : 0 ) ,
V_4 -> V_255 , V_16 , & V_262 ) ;
} else if ( V_251 || V_252 )
F_3 ( V_4 , L_92 ) ;
}
static void F_133 ( struct V_15 * V_16 )
{
struct V_263 * V_264 ;
V_264 = V_16 -> V_254 ;
V_16 -> V_254 = NULL ;
if ( V_264 )
F_134 ( V_264 ) ;
V_264 = V_16 -> V_257 ;
V_16 -> V_257 = NULL ;
if ( V_264 )
F_134 ( V_264 ) ;
V_264 = V_16 -> V_261 ;
V_16 -> V_261 = NULL ;
if ( V_264 )
F_134 ( V_264 ) ;
F_135 ( & V_16 -> V_232 ) ;
}
static inline void F_128 ( struct V_15 * V_16 ,
struct V_3 * V_4 , struct V_1 * V_10 ,
T_1 * V_13 , int V_14 )
{
}
static inline void F_130 ( struct V_15 * V_16 ,
struct V_1 * V_249 , struct V_1 * V_250 ,
struct V_1 * V_251 , struct V_1 * V_252 ,
struct V_1 * V_253 )
{
}
static inline void F_133 ( struct V_15 * V_16 )
{
}
static int F_136 ( struct V_3 * V_4 ,
struct V_1 * V_10 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
unsigned long V_18 ;
int V_77 = 0 ;
if ( ! V_16 )
return 1 ;
if ( V_10 -> V_2 == V_247 ) {
if ( V_16 -> V_183 )
V_77 = F_90 ( V_16 , V_10 , V_13 + 1 , V_14 - 1 ) ;
} else if ( V_10 -> V_2 == V_248 ) {
if ( V_16 -> V_265 )
V_77 = F_95 ( V_16 , V_10 , V_13 + 1 , V_14 - 1 ) ;
} else {
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_16 -> V_34 ) {
memcpy ( V_16 -> V_34 -> V_13 , V_13 + 1 , V_14 - 1 ) ;
V_16 -> V_34 -> V_28 = V_14 - 1 ;
V_16 -> V_34 -> V_27 = V_10 ;
F_137 ( & V_16 -> V_34 -> V_25 ) ;
}
F_13 ( & V_16 -> V_30 , V_18 ) ;
}
F_128 ( V_16 , V_4 , V_10 , V_13 , V_14 ) ;
return 1 ;
}
static int F_138 ( struct V_3 * V_4 , T_8 V_266 )
{
if ( F_139 ( V_266 ) )
return 0 ;
F_72 ( F_5 ( V_4 ) ) ;
F_92 ( V_189 L_93 ) ;
return 0 ;
}
static int F_140 ( struct V_3 * V_4 )
{
int V_77 ;
V_77 = F_71 ( F_5 ( V_4 ) ) ;
if ( V_77 )
F_92 ( V_189 L_94 , V_77 ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
int V_77 ;
V_77 = F_99 ( V_4 ) ;
if ( V_77 )
F_92 ( V_189 L_95 , V_77 ) ;
V_77 = F_19 ( F_5 ( V_4 ) , 0 ) ;
if ( V_77 )
F_92 ( V_189 L_96 , V_77 ) ;
V_77 = F_81 ( F_5 ( V_4 ) ) ;
if ( V_77 )
F_92 ( V_189 L_97 , V_77 ) ;
V_77 = F_71 ( F_5 ( V_4 ) ) ;
if ( V_77 )
F_92 ( V_189 L_94 , V_77 ) ;
F_82 ( F_5 ( V_4 ) ) ;
return 0 ;
}
static int F_142 ( struct V_15 * V_16 ,
struct V_1 * V_10 )
{
struct V_3 * V_4 = V_16 -> V_4 ;
struct V_267 * V_268 ;
int error , V_19 ;
if ( ! V_10 )
return - V_44 ;
if ( V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 2 ||
V_10 -> V_32 [ 0 ] -> V_149 != 8 ) {
F_97 ( V_4 , L_98 ) ;
return - V_95 ;
}
V_268 = F_143 () ;
if ( V_268 == NULL ) {
F_97 ( V_4 , L_99 ) ;
return - V_96 ;
}
F_144 ( V_268 , V_4 ) ;
memcpy ( V_16 -> V_187 , V_269 , sizeof( V_269 ) ) ;
V_268 -> V_176 = V_4 -> V_176 ;
V_268 -> V_270 = V_4 -> V_270 ;
V_268 -> V_271 = V_4 -> V_271 ;
V_268 -> V_2 . V_272 = V_4 -> V_273 ;
V_268 -> V_2 . V_274 = V_4 -> V_274 ;
V_268 -> V_2 . V_196 = V_4 -> V_196 ;
V_268 -> V_2 . V_193 = V_4 -> V_193 ;
V_268 -> V_114 . V_172 = V_4 -> V_114 . V_172 ;
V_268 -> V_187 = & V_16 -> V_187 ;
V_268 -> V_275 = V_186 ;
V_268 -> V_276 = sizeof( V_16 -> V_187 [ 0 ] ) ;
F_145 ( V_268 , V_184 , V_185 ) ;
F_146 ( V_277 , V_268 -> V_278 ) ;
for ( V_19 = 0 ; V_19 < V_186 ; V_19 ++ )
F_145 ( V_268 , V_279 , V_16 -> V_187 [ V_19 ] ) ;
error = F_147 ( V_268 ) ;
if ( error ) {
F_97 ( V_4 , L_100 ) ;
F_148 ( V_268 ) ;
return error ;
}
V_16 -> V_183 = V_268 ;
return 0 ;
}
static void F_149 ( struct V_15 * V_16 )
{
struct V_267 * V_268 = V_16 -> V_183 ;
V_16 -> V_183 = NULL ;
if ( V_268 )
F_150 ( V_268 ) ;
}
static inline int F_151 ( struct V_15 * V_16 , struct V_1 * V_10 )
{
return 0 ;
}
static inline void F_152 ( struct V_15 * V_16 )
{
}
static int F_153 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
int error ;
error = F_96 ( V_4 ) ;
if ( error )
return error ;
if ( V_16 -> V_193 [ 0 ] != 0 && V_16 -> V_193 [ 1 ] != 3 )
F_98 ( V_4 , L_101 ,
F_66 ( & V_4 -> V_114 ) ) ;
error = F_142 ( V_16 , F_154 ( V_247 , V_4 ) ) ;
if ( error )
goto V_177;
error = F_151 ( V_16 , F_154 ( V_248 , V_4 ) ) ;
if ( error )
goto V_177;
error = F_49 ( V_16 ) ;
if ( error )
goto V_177;
error = F_77 ( V_16 , F_6 ( V_160 , V_4 ) ) ;
if ( error )
goto V_177;
error = F_64 ( V_16 , F_6 ( V_142 , V_4 ) ) ;
if ( error )
goto V_177;
error = F_86 ( V_16 , F_6 ( V_165 , V_4 ) ) ;
if ( error )
goto V_177;
F_130 ( V_16 , F_6 ( V_216 , V_4 ) ,
F_6 ( V_219 , V_4 ) ,
F_6 ( V_225 , V_4 ) ,
F_6 ( V_231 , V_4 ) ,
F_6 ( V_195 , V_4 ) ) ;
return 0 ;
V_177:
F_89 ( V_16 ) ;
F_69 ( V_16 ) ;
F_79 ( V_16 ) ;
F_57 ( V_16 ) ;
F_152 ( V_16 ) ;
F_149 ( V_16 ) ;
return error ;
}
static int F_155 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
int error ;
error = F_96 ( V_4 ) ;
if ( error )
return error ;
if ( V_16 -> V_193 [ 0 ] != 1 && V_16 -> V_193 [ 1 ] != 0 )
F_98 ( V_4 , L_102 ,
F_66 ( & V_4 -> V_114 ) ) ;
F_130 ( V_16 , NULL , NULL ,
F_6 ( V_224 , V_4 ) ,
F_6 ( V_227 , V_4 ) , NULL ) ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 ,
const struct V_280 * V_2 )
{
struct V_15 * V_16 ;
int error = - V_96 ;
F_92 ( V_189 L_103 ) ;
V_16 = F_7 ( sizeof( struct V_15 ) , V_24 ) ;
if ( V_16 == NULL ) {
F_97 ( V_4 , L_104 ) ;
error = - V_96 ;
goto V_281;
}
F_157 ( & V_16 -> V_30 ) ;
F_131 ( & V_16 -> V_29 ) ;
V_16 -> V_4 = V_4 ;
V_16 -> V_200 = 5000 ;
if ( V_4 -> V_196 == V_197 )
V_16 -> V_22 |= V_194 ;
F_158 ( V_4 , V_16 ) ;
error = F_159 ( V_4 ) ;
if ( error ) {
F_97 ( V_4 , L_105 ) ;
goto V_282;
}
V_4 -> V_283 = V_284 ;
error = F_160 ( V_4 , 0 ) ;
V_4 -> V_283 = 0 ;
if ( error ) {
F_97 ( V_4 , L_106 ) ;
goto V_282;
}
error = F_161 ( V_4 ) ;
if ( error ) {
F_97 ( V_4 , L_107 ) ;
goto V_285;
}
error = F_53 ( & V_4 -> V_114 , & V_286 ) ;
if ( error ) {
F_97 ( V_4 , L_9 ) ;
goto V_287;
}
error = F_53 ( & V_4 -> V_114 , & V_288 ) ;
if ( error ) {
F_97 ( V_4 , L_9 ) ;
goto V_289;
}
if ( V_16 -> V_22 & V_194 )
error = F_155 ( V_4 , V_16 ) ;
else
error = F_153 ( V_4 , V_16 ) ;
if ( error )
goto V_290;
F_92 ( V_189 L_108 ) ;
return 0 ;
V_290:
F_56 ( & V_4 -> V_114 , & V_288 ) ;
V_289:
F_56 ( & V_4 -> V_114 , & V_286 ) ;
V_287:
F_162 ( V_4 ) ;
V_285:
F_163 ( V_4 ) ;
V_282:
F_39 ( V_16 ) ;
V_281:
F_158 ( V_4 , NULL ) ;
return error ;
}
static void F_164 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
unsigned long V_18 ;
F_92 ( V_189 L_109 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
V_16 -> V_22 |= V_23 ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
#ifdef F_100
if ( V_16 -> V_62 )
V_16 -> V_62 -> V_65 = NULL ;
#endif
F_133 ( V_16 ) ;
F_56 ( & V_4 -> V_114 , & V_288 ) ;
F_56 ( & V_4 -> V_114 , & V_286 ) ;
F_162 ( V_4 ) ;
F_163 ( V_4 ) ;
F_158 ( V_4 , NULL ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_16 -> V_34 )
F_137 ( & V_16 -> V_34 -> V_25 ) ;
F_13 ( & V_16 -> V_30 , V_18 ) ;
F_89 ( V_16 ) ;
F_69 ( V_16 ) ;
F_79 ( V_16 ) ;
F_57 ( V_16 ) ;
F_152 ( V_16 ) ;
F_149 ( V_16 ) ;
F_135 ( & V_16 -> V_29 ) ;
F_39 ( V_16 ) ;
}
static int T_9 F_165 ( void )
{
return F_166 ( & V_291 ) ;
}
static void T_10 F_167 ( void )
{
F_168 ( & V_291 ) ;
#ifdef F_100
F_169 ( & V_111 ) ;
F_18 ( V_107 ) ;
#endif
}
