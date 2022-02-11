static const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_5 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static int F_3 ( struct V_6 * V_7 ,
int type , unsigned int V_8 ,
void * V_9 , T_2 V_10 ,
void * V_11 , T_2 * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_4 ( V_7 , type , V_10 ,
* V_12 , V_8 ,
V_16 ) ;
if ( ! V_14 )
return - V_17 ;
if ( V_10 )
memcpy ( V_14 -> V_9 -> V_18 , V_9 , V_10 ) ;
V_15 = F_5 ( V_14 ) ;
if ( V_15 ) {
F_6 ( & V_7 -> V_19 -> V_20 ,
L_1 ,
V_7 -> V_21 , type , V_15 ) ;
} else {
* V_12 = V_14 -> V_11 -> V_22 ;
if ( V_14 -> V_11 -> V_22 )
memcpy ( V_11 , V_14 -> V_11 -> V_18 ,
V_14 -> V_11 -> V_22 ) ;
}
F_7 ( V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
unsigned int V_27 = 0 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_28 ; V_3 ++ ) {
struct V_29 * V_30 = & V_26 -> V_31 [ V_3 ] ;
const struct V_1 * V_32 ;
unsigned int V_33 ;
V_32 = F_1 ( V_30 -> V_34 ) ;
if ( ! V_32 ) {
F_9 ( V_24 , L_2 ,
V_30 -> V_34 ) ;
return - V_35 ;
}
if ( V_32 -> V_36 == 0 ) {
V_33 = F_10 ( V_30 -> V_27 ) ;
if ( V_33 == 0 ) {
F_9 ( V_24 ,
L_3 ,
V_3 ) ;
return - V_35 ;
}
} else {
V_33 = F_11 ( V_30 -> V_37 ) * V_32 -> V_36 / 8 ;
if ( V_33 != F_10 ( V_30 -> V_27 ) ) {
F_9 ( V_24 ,
L_4 ,
V_3 , V_33 , V_30 -> V_27 ) ;
return - V_35 ;
}
}
V_27 = F_12 ( V_33 , V_27 ) ;
}
return V_27 ;
}
static const int F_13 (
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int V_38 )
{
unsigned int V_3 ;
if ( V_26 -> V_39 [ 0 ] || V_26 -> V_39 [ 1 ] ) {
F_9 ( V_24 , L_5 ) ;
return - V_35 ;
}
if ( V_26 -> V_28 > V_38 ) {
F_9 ( V_24 , L_6 ,
V_26 -> V_28 , V_38 ) ;
return - V_35 ;
}
for ( V_3 = 0 ; V_3 < V_26 -> V_28 ; V_3 ++ ) {
struct V_29 * V_30 = & V_26 -> V_31 [ V_3 ] ;
if ( V_30 -> V_39 ) {
F_9 ( V_24 , L_7 , V_3 ) ;
return - V_35 ;
}
}
return 0 ;
}
static int F_14 ( struct V_23 * V_24 , T_3 V_40 ,
bool V_41 )
{
struct V_42 * V_43 = V_24 -> V_7 -> V_19 -> V_43 ;
int V_15 ;
if ( V_41 )
V_15 = F_15 ( V_43 , V_40 ,
V_44 ,
V_45 , 2 , 2 ,
V_46 ,
V_47 ,
V_45 , 2 , 2 ,
V_48 |
V_49 , 0 ,
NULL , NULL ) ;
else
V_15 = F_15 ( V_43 , V_40 ,
V_44 ,
V_50 ,
2 , 1 ,
V_46 ,
V_47 ,
V_50 ,
2 , 1 ,
0 , 0 ,
NULL , NULL ) ;
return V_15 ;
}
static int F_16 ( struct V_23 * V_24 , bool V_41 )
{
struct V_51 * V_52 = V_24 -> V_7 -> V_52 ;
struct V_42 * V_43 = V_24 -> V_7 -> V_19 -> V_43 ;
int V_15 ;
V_15 = F_14 ( V_24 , V_52 -> V_53 , V_41 ) ;
if ( V_15 < 0 ) {
F_9 ( V_24 , L_8 ,
V_41 ? L_9 : L_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_24 , V_43 -> V_54 , V_41 ) ;
if ( V_15 < 0 ) {
F_14 ( V_24 , V_52 -> V_53 , ! V_41 ) ;
F_9 ( V_24 , L_11 ,
V_41 ? L_9 : L_10 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_55 * V_56 )
{
struct V_57 V_58 ;
struct V_6 * V_59 ;
unsigned int V_60 ;
int V_15 ;
V_59 = F_18 ( V_24 -> V_61 , V_24 -> V_62 ,
V_63 |
V_64 ) ;
if ( F_19 ( V_59 ) )
return F_20 ( V_59 ) ;
V_24 -> V_65 = V_59 ;
F_21 ( V_59 , V_24 ) ;
V_15 = F_22 ( V_59 ) ;
if ( V_15 )
goto V_66;
V_15 = F_16 ( V_24 , true ) ;
if ( V_15 < 0 )
goto V_67;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_68 = 1 ;
V_58 . V_8 = 0 ;
V_58 . V_69 = V_70 ;
V_60 = V_26 -> V_71 / 2 / V_70 ;
V_60 = F_23 ( V_60 + V_72 ,
V_73 ,
V_74 ) ;
V_58 . V_75 = V_60 ;
V_15 = F_8 ( V_24 , V_26 ) ;
if ( V_15 < 0 ) {
V_15 = - V_35 ;
goto V_76;
}
V_58 . V_27 = V_15 ;
V_15 = F_24 ( V_24 -> V_7 -> V_19 , & V_58 ,
sizeof( V_58 ) ,
V_77 , false ) ;
if ( V_15 < 0 ) {
F_9 ( V_24 , L_12 ) ;
goto V_76;
}
if ( V_56 ) {
V_56 -> V_60 = V_58 . V_75 ;
V_56 -> V_69 = V_58 . V_69 ;
}
return 0 ;
V_76:
F_16 ( V_24 , false ) ;
V_67:
F_25 ( V_24 -> V_65 ) ;
V_66:
F_26 ( V_24 -> V_65 ) ;
V_24 -> V_65 = NULL ;
return V_15 ;
}
static void F_27 ( struct V_23 * V_24 )
{
struct V_57 V_58 ;
int V_15 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_68 = 1 ;
V_15 = F_24 ( V_24 -> V_7 -> V_19 , & V_58 ,
sizeof( V_58 ) ,
V_77 , false ) ;
if ( V_15 < 0 )
F_9 ( V_24 , L_13 ) ;
F_16 ( V_24 , false ) ;
F_25 ( V_24 -> V_65 ) ;
F_26 ( V_24 -> V_65 ) ;
V_24 -> V_65 = NULL ;
}
static int F_28 ( struct V_23 * V_24 ,
T_3 * V_78 , T_2 * V_79 )
{
int V_15 ;
V_15 = F_29 ( V_24 -> V_61 ) ;
if ( V_15 )
return V_15 ;
F_30 ( & V_24 -> V_80 ) ;
if ( ! V_24 -> V_7 ) {
V_15 = - V_81 ;
goto V_82;
}
V_15 = F_3 ( V_24 -> V_7 ,
V_83 ,
V_84 ,
NULL , 0 ,
( void * ) V_78 , V_79 ) ;
if ( V_15 )
F_9 ( V_24 , L_14 , V_15 ) ;
V_82:
F_31 ( & V_24 -> V_80 ) ;
F_32 ( V_24 -> V_61 ) ;
return V_15 ;
}
static int F_33 ( struct V_23 * V_24 ,
unsigned int * V_28 ,
unsigned int * V_8 ,
struct V_85 * V_86 ,
struct V_55 * V_56 )
{
struct V_87 * V_88 ;
struct V_25 * V_26 ;
unsigned int V_38 = * V_28 ;
unsigned int V_3 ;
T_2 V_89 ;
T_2 V_90 ;
int V_15 ;
if ( V_38 > V_91 )
return - V_81 ;
V_89 = sizeof( * V_88 ) + V_38 * sizeof( V_88 -> V_31 [ 0 ] ) ;
V_90 = sizeof( * V_26 ) + V_38 * sizeof( V_26 -> V_31 [ 0 ] ) ;
V_88 = F_34 ( V_89 , V_16 ) ;
V_26 = F_34 ( V_90 , V_16 ) ;
if ( ! V_88 || ! V_26 ) {
F_35 ( V_88 ) ;
F_35 ( V_26 ) ;
return - V_17 ;
}
V_88 -> V_28 = V_38 ;
V_88 -> V_8 = * V_8 ;
V_88 -> V_39 = 0 ;
for ( V_3 = 0 ; V_3 < V_38 ; ++ V_3 ) {
struct V_92 * V_30 = & V_88 -> V_31 [ V_3 ] ;
V_30 -> V_37 = F_36 ( V_86 [ V_3 ] . V_37 ) ;
V_30 -> V_93 = F_36 ( V_86 [ V_3 ] . V_93 ) ;
V_30 -> V_34 = F_36 ( V_86 [ V_3 ] . V_34 ) ;
V_30 -> V_39 = 0 ;
}
F_30 ( & V_24 -> V_80 ) ;
V_15 = F_29 ( V_24 -> V_61 ) ;
if ( V_15 )
goto V_94;
if ( ! V_24 -> V_7 ) {
V_15 = - V_81 ;
goto V_82;
}
V_15 = F_3 ( V_24 -> V_7 ,
V_95 ,
V_84 ,
V_88 , V_89 ,
V_26 , & V_90 ) ;
if ( V_15 < 0 )
goto V_82;
V_15 = F_13 ( V_24 , V_26 ,
V_38 ) ;
if ( V_15 < 0 )
goto V_82;
* V_8 = V_26 -> V_8 ;
* V_28 = V_26 -> V_28 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_28 ; ++ V_3 ) {
struct V_29 * V_30 = & V_26 -> V_31 [ V_3 ] ;
V_86 [ V_3 ] . V_37 = F_11 ( V_30 -> V_37 ) ;
V_86 [ V_3 ] . V_93 = F_11 ( V_30 -> V_93 ) ;
V_86 [ V_3 ] . V_34 = F_11 ( V_30 -> V_34 ) ;
V_86 [ V_3 ] . V_96 = V_30 -> V_97 ;
V_86 [ V_3 ] . V_98 [ 0 ] = V_30 -> V_99 [ 0 ] ;
V_86 [ V_3 ] . V_98 [ 1 ] = V_30 -> V_99 [ 1 ] ;
V_86 [ V_3 ] . V_100 = F_10 ( V_30 -> V_100 ) ;
}
if ( ( V_26 -> V_8 & V_101 ) ||
( V_88 -> V_8 & V_102 ) )
goto V_82;
if ( V_24 -> V_103 == V_104 ) {
F_27 ( V_24 ) ;
V_24 -> V_103 = V_105 ;
F_37 ( V_24 -> V_61 ) ;
}
if ( V_26 -> V_28 == 0 )
goto V_82;
F_38 ( V_24 -> V_61 ) ;
V_15 = F_17 ( V_24 , V_26 , V_56 ) ;
if ( V_15 < 0 ) {
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
F_39 ( V_24 -> V_7 ,
V_95 ,
V_88 , sizeof( * V_88 ) ,
V_26 , sizeof( * V_26 ) ) ;
* V_8 = 0 ;
* V_28 = 0 ;
F_37 ( V_24 -> V_61 ) ;
goto V_82;
}
V_24 -> V_103 = V_104 ;
V_82:
F_32 ( V_24 -> V_61 ) ;
V_94:
F_31 ( & V_24 -> V_80 ) ;
F_35 ( V_88 ) ;
F_35 ( V_26 ) ;
return V_15 ;
}
static int F_40 ( struct V_23 * V_24 , T_4 V_106 ,
unsigned int V_86 , unsigned int V_107 ,
T_2 V_108 , const void * V_109 )
{
struct V_110 * V_88 ;
T_2 V_89 ;
int V_15 ;
if ( V_108 > V_111 )
return - V_81 ;
V_89 = sizeof( * V_88 ) + V_108 ;
V_88 = F_34 ( V_89 , V_16 ) ;
if ( ! V_88 )
return - V_17 ;
V_88 -> V_106 = F_41 ( V_106 ) ;
V_88 -> V_86 = V_86 ;
V_88 -> V_39 = 0 ;
V_88 -> V_107 = F_36 ( V_107 ) ;
memcpy ( V_88 -> V_109 , V_109 , V_108 ) ;
F_30 ( & V_24 -> V_80 ) ;
if ( ! V_24 -> V_7 ) {
V_15 = - V_81 ;
goto V_82;
}
V_15 = F_39 ( V_24 -> V_7 , V_112 ,
V_88 , V_89 , NULL , 0 ) ;
V_82:
F_31 ( & V_24 -> V_80 ) ;
F_35 ( V_88 ) ;
return V_15 ;
}
static int F_42 ( struct V_23 * V_24 , T_4 * V_106 )
{
struct V_113 V_26 ;
int V_15 ;
F_30 ( & V_24 -> V_80 ) ;
if ( ! V_24 -> V_7 ) {
V_15 = - V_81 ;
goto V_82;
}
V_15 = F_39 ( V_24 -> V_7 , V_114 , NULL , 0 ,
& V_26 , sizeof( V_26 ) ) ;
if ( V_15 < 0 )
goto V_82;
if ( V_106 )
* V_106 = F_10 ( V_26 . V_106 ) ;
V_82:
F_31 ( & V_24 -> V_80 ) ;
return V_15 ;
}
static int F_43 ( struct V_13 * V_115 )
{
struct V_23 * V_24 = F_44 ( V_115 -> V_7 ) ;
struct V_116 * V_18 ;
struct V_117 * V_9 ;
if ( V_115 -> type != V_118 ) {
F_9 ( V_24 , L_15 , V_115 -> type ) ;
return - V_81 ;
}
V_9 = V_115 -> V_9 ;
if ( V_9 -> V_22 < sizeof( * V_18 ) ) {
F_9 ( V_24 , L_16 ,
V_9 -> V_22 , sizeof( * V_18 ) ) ;
return - V_81 ;
}
V_18 = V_9 -> V_18 ;
F_45 ( V_24 , L_17 ,
V_18 -> V_106 , V_18 -> V_119 , V_18 -> V_120 ) ;
return 0 ;
}
static unsigned int F_46 ( enum V_121 V_122 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_122 == V_122 )
return V_4 [ V_3 ] . V_5 ;
}
return V_4 [ 0 ] . V_5 ;
}
static enum V_121 F_47 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_5 == V_2 )
return V_4 [ V_3 ] . V_122 ;
}
return V_4 [ 0 ] . V_122 ;
}
static T_5 F_48 ( void * V_123 , char * V_124 , T_2 V_125 )
{
struct V_23 * V_24 = V_123 ;
T_2 V_126 = V_125 ;
int V_15 ;
V_15 = F_28 ( V_24 , V_124 , & V_126 ) ;
if ( V_15 )
return V_15 ;
return V_126 ;
}
static int F_49 ( void * V_123 , unsigned int * V_38 ,
unsigned int * V_8 , struct V_127 * V_86 ,
struct V_55 * V_56 )
{
struct V_23 * V_24 = V_123 ;
struct V_85 * V_128 ;
unsigned int V_129 = 0 ;
unsigned int V_130 = * V_38 ;
unsigned int V_3 ;
int V_15 ;
if ( V_130 > V_91 )
return - V_81 ;
V_128 = F_50 ( V_130 * sizeof( * V_128 ) , V_16 ) ;
if ( ! V_128 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_130 ; V_3 ++ ) {
V_128 [ V_3 ] . V_37 = V_86 [ V_3 ] . V_37 ;
V_128 [ V_3 ] . V_93 = V_86 [ V_3 ] . V_93 ;
V_128 [ V_3 ] . V_34 =
F_46 ( V_86 [ V_3 ] . V_131 ) ;
}
if ( * V_8 & V_132 )
V_129 |= V_102 ;
V_15 = F_33 ( V_24 , & V_130 ,
& V_129 , V_128 , V_56 ) ;
if ( V_15 < 0 )
goto V_82;
if ( V_130 > * V_38 ) {
V_15 = - V_81 ;
goto V_82;
}
* V_8 = 0 ;
if ( V_129 & V_101 )
* V_8 |= V_133 ;
for ( V_3 = 0 ; V_3 < V_130 ; V_3 ++ ) {
V_86 [ V_3 ] . V_37 = V_128 [ V_3 ] . V_37 ;
V_86 [ V_3 ] . V_93 = V_128 [ V_3 ] . V_93 ;
V_86 [ V_3 ] . V_96 = V_128 [ V_3 ] . V_96 ;
V_86 [ V_3 ] . V_98 [ 0 ] = V_128 [ V_3 ] . V_98 [ 0 ] ;
V_86 [ V_3 ] . V_98 [ 1 ] = V_128 [ V_3 ] . V_98 [ 1 ] ;
V_86 [ V_3 ] . V_100 = V_128 [ V_3 ] . V_100 ;
V_86 [ V_3 ] . V_131 =
F_47 ( V_128 [ V_3 ] . V_34 ) ;
}
* V_38 = V_130 ;
V_82:
F_35 ( V_128 ) ;
return V_15 ;
}
static int F_51 ( void * V_123 , T_4 V_106 ,
unsigned int V_86 , unsigned int V_107 ,
T_2 V_108 , const void * V_109 )
{
struct V_23 * V_24 = V_123 ;
return F_40 ( V_24 , V_106 , V_86 , V_107 ,
V_108 , V_109 ) ;
}
static int F_52 ( void * V_123 , T_4 * V_106 )
{
struct V_23 * V_24 = V_123 ;
return F_42 ( V_24 , V_106 ) ;
}
static T_5 F_53 ( struct V_23 * V_24 ,
char * V_134 , T_2 V_125 )
{
struct V_135 * V_136 =
& V_24 -> V_137 . V_138 [ V_139 ] ;
T_2 V_79 = 1024 ;
unsigned int V_3 ;
T_3 * V_140 ;
int V_15 ;
V_140 = F_34 ( V_79 , V_16 ) ;
if ( ! V_140 )
return - V_17 ;
V_15 = F_28 ( V_24 , V_140 , & V_79 ) ;
if ( V_15 < 0 )
goto V_82;
V_136 -> V_141 = 0 ;
for ( V_3 = 0 ; V_3 < V_79 ; V_3 += 16 ) {
unsigned int V_142 = F_54 (unsigned int, size - i, 16 ) ;
V_136 -> V_141 += sprintf ( V_136 -> V_124 + V_136 -> V_141 ,
L_18 , V_142 , V_140 + V_3 ) ;
}
V_82:
F_35 ( V_140 ) ;
return V_15 ;
}
static T_5 F_55 ( struct V_23 * V_24 ,
char * V_134 , T_2 V_125 )
{
struct V_135 * V_136 =
& V_24 -> V_137 . V_138 [ V_143 ] ;
struct V_85 * V_86 ;
unsigned int V_38 ;
unsigned int V_8 ;
unsigned int V_3 ;
char * V_144 ;
int V_15 ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
return - V_81 ;
V_15 = F_57 ( V_144 , 10 , & V_38 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_38 > V_91 )
return - V_81 ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
return - V_81 ;
V_15 = F_57 ( V_144 , 10 , & V_8 ) ;
if ( V_15 < 0 )
return V_15 ;
V_86 = F_50 ( V_38 * sizeof( * V_86 ) , V_16 ) ;
if ( ! V_86 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_38 ; ++ V_3 ) {
struct V_85 * V_120 = & V_86 [ V_3 ] ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL ) {
V_15 = - V_81 ;
goto V_82;
}
V_15 = F_57 ( V_144 , 10 , & V_120 -> V_37 ) ;
if ( V_15 < 0 )
goto V_82;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
goto V_82;
V_15 = F_57 ( V_144 , 10 , & V_120 -> V_93 ) ;
if ( V_15 < 0 )
goto V_82;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
goto V_82;
V_15 = F_57 ( V_144 , 16 , & V_120 -> V_34 ) ;
if ( V_15 < 0 )
goto V_82;
}
V_15 = F_33 ( V_24 , & V_38 , & V_8 , V_86 ,
NULL ) ;
if ( V_15 < 0 )
goto V_82;
V_136 -> V_141 = sprintf ( V_136 -> V_124 , L_20 , V_38 , V_8 ) ;
for ( V_3 = 0 ; V_3 < V_38 ; ++ V_3 ) {
struct V_85 * V_120 = & V_86 [ V_3 ] ;
V_136 -> V_141 += sprintf ( V_136 -> V_124 + V_136 -> V_141 ,
L_21 ,
V_120 -> V_37 , V_120 -> V_93 ,
V_120 -> V_34 , V_120 -> V_96 ,
V_120 -> V_98 [ 0 ] , V_120 -> V_98 [ 1 ] ,
V_120 -> V_100 ) ;
}
V_15 = V_125 ;
V_82:
F_35 ( V_86 ) ;
return V_15 ;
}
static T_5 F_58 ( struct V_23 * V_24 ,
char * V_134 , T_2 V_125 )
{
unsigned int V_106 ;
unsigned int V_145 ;
unsigned int V_107 ;
char * V_144 ;
int V_15 ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
return - V_81 ;
V_15 = F_57 ( V_144 , 10 , & V_106 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
return - V_81 ;
V_15 = F_57 ( V_144 , 16 , & V_145 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 = F_56 ( & V_134 , L_19 ) ;
if ( V_144 == NULL )
return - V_81 ;
V_15 = F_57 ( V_144 , 10 , & V_107 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_40 ( V_24 , V_106 , V_145 , V_107 , 0 ,
NULL ) ;
if ( V_15 < 0 )
return V_15 ;
return V_125 ;
}
static T_5 F_59 ( struct V_23 * V_24 ,
char * V_134 , T_2 V_125 )
{
struct V_135 * V_136 =
& V_24 -> V_137 . V_138 [ V_146 ] ;
unsigned int V_147 ;
int V_15 ;
V_15 = F_42 ( V_24 , & V_147 ) ;
if ( V_15 < 0 )
return V_15 ;
V_136 -> V_141 = sprintf ( V_136 -> V_124 , L_22 , V_147 ) ;
return V_125 ;
}
static T_5 F_60 ( struct V_148 * V_148 , char T_6 * V_134 ,
T_2 V_125 , T_7 * V_149 )
{
const struct V_150 * V_115 = V_148 -> V_151 ;
struct V_23 * V_24 = V_148 -> V_152 -> V_153 ;
struct V_135 * V_136 ;
T_5 V_15 ;
if ( ! ( V_115 -> V_154 & V_155 ) ) {
V_15 = V_115 -> V_156 ( V_24 , NULL , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_136 = & V_24 -> V_137 . V_138 [ V_115 -> V_136 ] ;
return F_61 ( V_134 , V_125 , V_149 , V_136 -> V_124 ,
V_136 -> V_141 ) ;
}
static T_5 F_62 ( struct V_148 * V_148 ,
const char T_6 * V_134 , T_2 V_125 ,
T_7 * V_149 )
{
const struct V_150 * V_115 = V_148 -> V_151 ;
struct V_23 * V_24 = V_148 -> V_152 -> V_153 ;
T_5 V_15 ;
char * V_157 ;
if ( V_125 > 1024 )
return - V_81 ;
V_157 = F_34 ( V_125 + 1 , V_16 ) ;
if ( ! V_157 )
return - V_17 ;
if ( F_63 ( V_157 , V_134 , V_125 ) ) {
V_15 = - V_158 ;
goto V_82;
}
V_157 [ V_125 ] = '\0' ;
V_15 = V_115 -> V_156 ( V_24 , V_157 , V_125 ) ;
V_82:
F_35 ( V_157 ) ;
return V_15 ;
}
static int F_64 ( struct V_159 * V_159 , struct V_148 * V_148 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_160 ) ; ++ V_3 ) {
const struct V_150 * V_161 =
& V_160 [ V_3 ] ;
if ( ! strcmp ( V_148 -> V_162 . V_163 -> V_164 , V_161 -> V_21 ) ) {
V_148 -> V_151 = ( void * ) V_161 ;
break;
}
}
return 0 ;
}
static int F_65 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_7 ;
char V_165 [ 27 ] ;
unsigned int V_3 ;
snprintf ( V_165 , 27 , L_23 , V_7 -> V_52 -> V_53 ,
V_24 -> V_61 -> V_166 ) ;
V_24 -> V_137 . V_167 = F_66 ( V_165 , F_67 () ) ;
if ( F_19 ( V_24 -> V_137 . V_167 ) ) {
F_9 ( V_24 , L_24 ,
F_20 ( V_24 -> V_137 . V_167 ) ) ;
return F_20 ( V_24 -> V_137 . V_167 ) ;
}
V_24 -> V_137 . V_138 = F_68 ( sizeof( * V_24 -> V_137 . V_138 ) *
V_168 ) ;
if ( ! V_24 -> V_137 . V_138 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_160 ) ; ++ V_3 ) {
const struct V_150 * V_161 =
& V_160 [ V_3 ] ;
struct V_163 * V_163 ;
V_24 -> V_137 . V_138 [ V_3 ] . V_141 = 0 ;
V_163 = F_69 ( V_161 -> V_21 , V_161 -> V_154 ,
V_24 -> V_137 . V_167 , V_24 ,
& V_169 ) ;
if ( F_19 ( V_163 ) ) {
F_9 ( V_24 ,
L_25 ,
V_161 -> V_21 , F_20 ( V_163 ) ) ;
return F_20 ( V_163 ) ;
}
}
return 0 ;
}
static void F_70 ( struct V_23 * V_24 )
{
F_71 ( V_24 -> V_137 . V_167 ) ;
F_72 ( V_24 -> V_137 . V_138 ) ;
}
static void F_73 ( struct V_23 * V_24 )
{
F_70 ( V_24 ) ;
F_30 ( & V_24 -> V_80 ) ;
if ( V_24 -> V_65 ) {
F_25 ( V_24 -> V_65 ) ;
F_26 ( V_24 -> V_65 ) ;
V_24 -> V_65 = NULL ;
}
if ( V_24 -> V_7 ) {
F_25 ( V_24 -> V_7 ) ;
F_26 ( V_24 -> V_7 ) ;
V_24 -> V_7 = NULL ;
}
F_31 ( & V_24 -> V_80 ) ;
}
static void F_74 ( struct V_170 * V_171 )
{
struct V_172 * V_173 =
F_75 ( V_171 , struct V_172 , V_174 ) ;
F_35 ( V_173 -> V_123 ) ;
}
static int F_76 ( struct V_175 * V_61 ,
const struct V_176 * V_166 )
{
struct V_6 * V_59 ;
struct V_23 * V_24 ;
T_1 V_177 = 0 ;
T_1 V_62 = 0 ;
unsigned int V_3 ;
int V_15 ;
if ( V_61 -> V_178 != 2 )
return - V_179 ;
for ( V_3 = 0 ; V_3 < V_61 -> V_178 ; ++ V_3 ) {
struct V_180 * V_181 = & V_61 -> V_182 [ V_3 ] ;
switch ( V_181 -> V_183 ) {
case V_184 :
V_177 = F_11 ( V_181 -> V_166 ) ;
break;
case V_185 :
V_62 = F_11 ( V_181 -> V_166 ) ;
break;
default:
return - V_179 ;
}
}
if ( ! V_177 || ! V_62 )
return - V_179 ;
V_24 = F_50 ( sizeof( * V_24 ) , V_16 ) ;
if ( ! V_24 )
return - V_17 ;
F_77 ( & V_24 -> V_80 ) ;
V_24 -> V_61 = V_61 ;
V_24 -> V_103 = V_105 ;
V_24 -> V_62 = V_62 ;
V_59 = F_78 ( V_61 , V_177 ,
F_43 ) ;
if ( F_19 ( V_59 ) ) {
V_15 = F_20 ( V_59 ) ;
goto error;
}
V_24 -> V_7 = V_59 ;
F_21 ( V_59 , V_24 ) ;
V_15 = F_22 ( V_59 ) ;
if ( V_15 )
goto error;
V_15 = F_65 ( V_24 ) ;
if ( V_15 < 0 )
goto error;
V_24 -> V_186 . V_123 = V_24 ;
V_24 -> V_186 . V_187 = & V_188 ;
V_24 -> V_186 . V_53 = V_24 -> V_7 -> V_52 -> V_53 ;
V_24 -> V_186 . V_189 = F_74 ;
V_15 = F_79 ( & V_24 -> V_186 ) ;
if ( V_15 < 0 )
goto error;
F_80 ( V_61 , V_24 ) ;
F_32 ( V_24 -> V_61 ) ;
return 0 ;
error:
F_73 ( V_24 ) ;
F_35 ( V_24 ) ;
return V_15 ;
}
static void F_81 ( struct V_175 * V_61 )
{
struct V_23 * V_24 = F_82 ( V_61 ) ;
int V_15 ;
V_15 = F_29 ( V_61 ) ;
if ( V_15 )
F_38 ( V_61 ) ;
F_73 ( V_24 ) ;
F_83 ( & V_24 -> V_186 ) ;
}
static int F_84 ( struct V_190 * V_20 )
{
struct V_175 * V_61 = F_85 ( V_20 ) ;
struct V_23 * V_24 = F_82 ( V_61 ) ;
if ( V_24 -> V_65 )
F_25 ( V_24 -> V_65 ) ;
F_25 ( V_24 -> V_7 ) ;
return 0 ;
}
static int F_86 ( struct V_190 * V_20 )
{
struct V_175 * V_61 = F_85 ( V_20 ) ;
struct V_23 * V_24 = F_82 ( V_61 ) ;
int V_15 ;
V_15 = F_22 ( V_24 -> V_7 ) ;
if ( V_15 ) {
F_9 ( V_24 , L_26 , V_15 ) ;
return V_15 ;
}
if ( V_24 -> V_65 ) {
V_15 = F_22 ( V_24 -> V_65 ) ;
if ( V_15 ) {
F_9 ( V_24 ,
L_27 , V_15 ) ;
return V_15 ;
}
}
return 0 ;
}
