static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_14 ; V_12 ++ ) {
if ( ! F_3 ( V_12 , V_6 -> V_15 ) )
continue;
V_9 -> V_11 [ V_13 ] = F_4 ( V_9 , F_5 ( V_9 , V_12 ) ) ;
V_13 ++ ;
}
if ( V_6 -> V_16 ) {
T_2 * V_17 = ( T_2 * ) ( ( V_18 * ) V_9 -> V_11 +
F_6 ( V_13 , sizeof( T_2 ) ) ) ;
* V_17 = V_4 -> V_17 ;
}
V_11 -> V_19 -> V_20 ( V_11 , ( V_18 * ) V_9 -> V_11 , V_4 -> V_17 ) ;
F_7 ( V_6 -> V_21 ) ;
V_9 -> V_22 = true ;
F_4 ( V_9 , V_23 ) ;
F_8 ( V_9 -> V_1 ) ;
return V_24 ;
}
static T_1 F_9 ( int V_1 , void * V_25 )
{
struct V_5 * V_6 = V_25 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_3 V_26 = F_4 ( V_9 , V_9 -> V_27 -> V_28 ) ;
if ( ! ( V_26 & V_9 -> V_27 -> V_29 ) )
return V_24 ;
if ( F_10 ( V_6 ) ) {
F_11 ( V_1 ) ;
V_9 -> V_22 = false ;
F_12 ( V_6 -> V_21 , F_13 () ) ;
} else {
V_9 -> V_30 = F_4 ( V_9 , V_23 ) ;
V_9 -> V_31 = true ;
F_14 ( & V_9 -> V_32 ) ;
}
return V_24 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_33 * V_34 , * V_17 ;
int V_35 , V_36 = 0 ;
V_6 -> V_37 = F_16 ( & V_9 -> V_38 ,
V_9 -> V_37 ) + 1 ;
V_34 = F_17 ( & V_6 -> V_39 ,
( ( V_6 -> V_37 + 1 ) *
sizeof( struct V_33 ) ) ,
V_40 ) ;
if ( ! V_34 )
return - V_41 ;
F_18 (bit, &st->channels_mask, st->num_channels) {
struct V_33 * V_42 = V_34 + V_36 ;
V_42 -> type = V_43 ;
V_42 -> V_44 = 1 ;
V_42 -> V_45 = V_35 ;
V_42 -> V_46 = V_36 ;
V_42 -> V_47 . V_48 = 'u' ;
V_42 -> V_47 . V_49 = 10 ;
V_42 -> V_47 . V_50 = 16 ;
V_42 -> V_51 = V_52 |
V_53 ;
V_36 ++ ;
}
V_17 = V_34 + V_36 ;
V_17 -> type = V_54 ;
V_17 -> V_45 = - 1 ;
V_17 -> V_46 = V_36 ;
V_17 -> V_47 . V_48 = 's' ;
V_17 -> V_47 . V_49 = 64 ;
V_17 -> V_47 . V_50 = 64 ;
V_6 -> V_55 = V_34 ;
return V_6 -> V_37 ;
}
static V_18 F_19 ( struct V_5 * V_6 ,
struct V_56 * V_57 ,
const char * V_58 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
V_18 V_59 = 0 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_60 ; V_12 ++ ) {
char * V_61 = F_20 ( V_40 ,
L_1 ,
V_6 -> V_61 ,
V_6 -> V_62 ,
V_57 [ V_12 ] . V_61 ) ;
if ( ! V_61 )
return - V_41 ;
if ( strcmp ( V_58 , V_61 ) == 0 ) {
V_59 = V_57 [ V_12 ] . V_59 ;
F_21 ( V_61 ) ;
break;
}
F_21 ( V_61 ) ;
}
return V_59 ;
}
static int F_22 ( struct V_63 * V_21 , bool V_64 )
{
struct V_5 * V_6 = V_21 -> V_65 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_66 * V_67 = V_9 -> V_27 ;
T_3 V_26 = F_4 ( V_9 , V_67 -> V_68 ) ;
V_18 V_59 ;
V_18 V_35 ;
V_59 = F_19 ( V_6 ,
V_9 -> V_69 ,
V_6 -> V_21 -> V_61 ) ;
if ( V_59 == 0 )
return - V_70 ;
if ( V_64 ) {
V_9 -> V_11 = F_23 ( V_6 -> V_71 , V_40 ) ;
if ( V_9 -> V_11 == NULL )
return - V_41 ;
F_24 ( V_9 , V_67 -> V_68 ,
V_26 | V_59 ) ;
F_18 (bit, buffer->scan_mask,
st->num_channels) {
struct V_33 const * V_42 = V_6 -> V_55 + V_35 ;
F_24 ( V_9 , V_72 ,
F_25 ( V_42 -> V_45 ) ) ;
}
F_24 ( V_9 , V_73 , V_67 -> V_29 ) ;
} else {
F_24 ( V_9 , V_74 , V_67 -> V_29 ) ;
F_24 ( V_9 , V_67 -> V_68 ,
V_26 & ~ V_59 ) ;
F_18 (bit, buffer->scan_mask,
st->num_channels) {
struct V_33 const * V_42 = V_6 -> V_55 + V_35 ;
F_24 ( V_9 , V_75 ,
F_25 ( V_42 -> V_45 ) ) ;
}
F_21 ( V_9 -> V_11 ) ;
}
return 0 ;
}
static struct V_63 * F_26 ( struct V_5 * V_6 ,
struct V_56 * V_76 )
{
struct V_63 * V_21 ;
int V_77 ;
V_21 = F_27 ( L_1 , V_6 -> V_61 ,
V_6 -> V_62 , V_76 -> V_61 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_39 . V_78 = V_6 -> V_39 . V_78 ;
V_21 -> V_65 = V_6 ;
V_21 -> V_79 = & V_80 ;
V_77 = F_28 ( V_21 ) ;
if ( V_77 )
return NULL ;
return V_21 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_12 , V_77 ;
V_9 -> V_21 = F_17 ( & V_6 -> V_39 ,
V_9 -> V_60 * sizeof( V_9 -> V_21 ) ,
V_40 ) ;
if ( V_9 -> V_21 == NULL ) {
V_77 = - V_41 ;
goto V_81;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_60 ; V_12 ++ ) {
if ( V_9 -> V_69 [ V_12 ] . V_82 && ! ( V_9 -> V_83 ) )
continue;
V_9 -> V_21 [ V_12 ] = F_26 ( V_6 ,
V_9 -> V_69 + V_12 ) ;
if ( V_9 -> V_21 [ V_12 ] == NULL ) {
F_30 ( & V_6 -> V_39 ,
L_2 , V_12 ) ;
V_77 = - V_41 ;
goto V_84;
}
}
return 0 ;
V_84:
for ( V_12 -- ; V_12 >= 0 ; V_12 -- ) {
F_31 ( V_9 -> V_21 [ V_12 ] ) ;
F_32 ( V_9 -> V_21 [ V_12 ] ) ;
}
V_81:
return V_77 ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_60 ; V_12 ++ ) {
F_31 ( V_9 -> V_21 [ V_12 ] ) ;
F_32 ( V_9 -> V_21 [ V_12 ] ) ;
}
}
static int F_34 ( struct V_5 * V_6 )
{
int V_77 ;
V_6 -> V_11 = F_35 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_77 = - V_41 ;
goto V_81;
}
V_6 -> V_85 = F_36 ( & V_86 ,
& F_1 ,
V_87 ,
V_6 ,
L_3 ,
V_6 -> V_61 ,
V_6 -> V_62 ) ;
if ( V_6 -> V_85 == NULL ) {
V_77 = - V_41 ;
goto V_88;
}
V_6 -> V_89 = & V_90 ;
V_6 -> V_91 |= V_92 ;
V_77 = F_37 ( V_6 ,
V_6 -> V_55 ,
V_6 -> V_37 ) ;
if ( V_77 )
goto V_93;
return 0 ;
V_93:
F_38 ( V_6 -> V_85 ) ;
V_88:
F_39 ( V_6 -> V_11 ) ;
V_81:
return V_77 ;
}
static void F_40 ( struct V_5 * V_6 )
{
F_41 ( V_6 ) ;
F_38 ( V_6 -> V_85 ) ;
F_39 ( V_6 -> V_11 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_33 const * V_42 ,
int * V_94 , int * V_95 , long V_96 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_77 ;
switch ( V_96 ) {
case V_97 :
F_43 ( & V_9 -> V_98 ) ;
F_24 ( V_9 , V_72 ,
F_25 ( V_42 -> V_45 ) ) ;
F_24 ( V_9 , V_73 , V_9 -> V_27 -> V_29 ) ;
F_24 ( V_9 , V_99 , V_100 ) ;
V_77 = F_44 ( V_9 -> V_32 ,
V_9 -> V_31 ,
F_45 ( 1000 ) ) ;
if ( V_77 == 0 )
return - V_101 ;
else if ( V_77 < 0 )
return V_77 ;
* V_94 = V_9 -> V_30 ;
F_24 ( V_9 , V_75 ,
F_25 ( V_42 -> V_45 ) ) ;
F_24 ( V_9 , V_74 , V_9 -> V_27 -> V_29 ) ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = false ;
F_46 ( & V_9 -> V_98 ) ;
return V_102 ;
case V_103 :
* V_94 = ( V_9 -> V_104 * 1000 ) >> V_42 -> V_47 . V_49 ;
* V_95 = 0 ;
return V_105 ;
default:
break;
}
return - V_70 ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_106 * V_107 )
{
struct V_5 * V_6 = F_48 ( V_9 ) ;
struct V_108 * V_109 = V_107 -> V_39 . V_110 ;
struct V_108 * V_111 ;
int V_12 = 0 , V_77 ;
T_3 V_112 ;
if ( ! V_109 )
return - V_70 ;
V_9 -> V_83 = F_49 ( V_109 , L_4 ) ;
if ( F_50 ( V_109 , L_5 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_6 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_38 = V_112 ;
if ( F_50 ( V_109 , L_7 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_8 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_37 = V_112 ;
if ( F_50 ( V_109 , L_9 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_10 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_113 = V_112 ;
if ( F_50 ( V_109 , L_11 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_12 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_104 = V_112 ;
V_9 -> V_27 = F_17 ( & V_6 -> V_39 ,
sizeof( struct V_66 ) ,
V_40 ) ;
if ( ! V_9 -> V_27 ) {
F_30 ( & V_6 -> V_39 , L_13 ) ;
V_77 = - V_41 ;
goto V_81;
}
if ( F_50 ( V_109 , L_14 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_15 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_114 = V_112 ;
if ( F_50 ( V_109 , L_16 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_17 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_29 = V_112 ;
if ( F_50 ( V_109 , L_18 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_19 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_28 = V_112 ;
if ( F_50 ( V_109 , L_20 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_21 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_68 = V_112 ;
V_9 -> V_60 = F_51 ( V_109 ) ;
V_9 -> V_69 = F_17 ( & V_6 -> V_39 , V_9 -> V_60 *
sizeof( struct V_56 ) ,
V_40 ) ;
if ( ! V_9 -> V_69 ) {
F_30 ( & V_6 -> V_39 , L_22 ) ;
V_77 = - V_41 ;
goto V_81;
}
F_52 (node, trig_node) {
struct V_56 * V_21 = V_9 -> V_69 + V_12 ;
const char * V_61 ;
if ( F_53 ( V_111 , L_23 , & V_61 ) ) {
F_30 ( & V_6 -> V_39 , L_24 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_21 -> V_61 = V_61 ;
if ( F_50 ( V_111 , L_25 , & V_112 ) ) {
F_30 ( & V_6 -> V_39 , L_26 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_21 -> V_59 = V_112 ;
V_21 -> V_82 = F_49 ( V_111 , L_27 ) ;
V_12 ++ ;
}
return 0 ;
V_81:
return V_77 ;
}
static int F_54 ( struct V_8 * V_9 ,
struct V_106 * V_107 )
{
struct V_115 * V_116 = V_107 -> V_39 . V_117 ;
if ( ! V_116 )
return - V_70 ;
V_9 -> V_83 = V_116 -> V_118 ;
V_9 -> V_104 = V_116 -> V_119 ;
V_9 -> V_38 = V_116 -> V_120 ;
V_9 -> V_37 = V_116 -> V_37 ;
V_9 -> V_113 = V_116 -> V_113 ;
V_9 -> V_60 = V_116 -> V_60 ;
V_9 -> V_69 = V_116 -> V_69 ;
V_9 -> V_27 = V_116 -> V_27 ;
return 0 ;
}
static int T_4 F_55 ( struct V_106 * V_107 )
{
unsigned int V_121 , V_122 , V_123 , V_124 ;
int V_77 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_125 * V_126 ;
V_6 = F_56 ( sizeof( struct V_8 ) ) ;
if ( V_6 == NULL ) {
V_77 = - V_41 ;
goto V_81;
}
V_9 = F_2 ( V_6 ) ;
if ( V_107 -> V_39 . V_110 )
V_77 = F_47 ( V_9 , V_107 ) ;
else
V_77 = F_54 ( V_9 , V_107 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_28 ) ;
V_77 = - V_70 ;
goto V_127;
}
V_126 = F_57 ( V_107 , V_128 , 0 ) ;
if ( ! V_126 ) {
F_30 ( & V_107 -> V_39 , L_29 ) ;
V_77 = - V_129 ;
goto V_81;
}
F_58 ( V_107 , V_6 ) ;
V_6 -> V_39 . V_78 = & V_107 -> V_39 ;
V_6 -> V_61 = F_59 ( & V_107 -> V_39 ) ;
V_6 -> V_91 = V_130 ;
V_6 -> V_131 = & V_132 ;
V_9 -> V_1 = F_60 ( V_107 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_30 ( & V_107 -> V_39 , L_30 ) ;
V_77 = - V_133 ;
goto V_127;
}
if ( ! F_61 ( V_126 -> V_134 , F_62 ( V_126 ) ,
L_31 ) ) {
F_30 ( & V_107 -> V_39 , L_32 ) ;
V_77 = - V_135 ;
goto V_127;
}
V_9 -> V_136 = F_63 ( V_126 -> V_134 , F_62 ( V_126 ) ) ;
if ( ! V_9 -> V_136 ) {
F_30 ( & V_107 -> V_39 , L_33 ) ;
V_77 = - V_41 ;
goto V_137;
}
F_24 ( V_9 , V_99 , V_138 ) ;
F_24 ( V_9 , V_74 , 0xFFFFFFFF ) ;
V_77 = F_64 ( V_9 -> V_1 ,
F_9 ,
0 ,
V_107 -> V_39 . V_139 -> V_61 ,
V_6 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_34 ) ;
goto V_140;
}
V_9 -> V_141 = F_65 ( & V_107 -> V_39 , L_35 ) ;
if ( F_66 ( V_9 -> V_141 ) ) {
F_30 ( & V_107 -> V_39 , L_36 ) ;
V_77 = F_67 ( V_9 -> V_141 ) ;
goto V_142;
}
V_77 = F_68 ( V_9 -> V_141 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_37 ) ;
goto V_143;
}
V_77 = F_69 ( V_9 -> V_141 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_38 ) ;
goto V_144;
}
V_9 -> V_124 = F_65 ( & V_107 -> V_39 , L_39 ) ;
if ( F_66 ( V_9 -> V_124 ) ) {
F_30 ( & V_107 -> V_39 , L_40 ) ;
V_77 = F_67 ( V_9 -> V_141 ) ;
goto V_145;
}
V_77 = F_68 ( V_9 -> V_124 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_41 ) ;
goto V_146;
}
V_77 = F_69 ( V_9 -> V_124 ) ;
if ( V_77 ) {
F_30 ( & V_107 -> V_39 , L_42 ) ;
goto V_147;
}
V_122 = F_70 ( V_9 -> V_141 ) ;
V_124 = F_70 ( V_9 -> V_124 ) ;
V_121 = ( V_122 / ( 2 * V_124 ) ) - 1 ;
if ( ! V_9 -> V_113 ) {
F_30 ( & V_107 -> V_39 , L_43 ) ;
V_77 = - V_70 ;
goto V_148;
}
V_123 = F_71 ( ( V_9 -> V_113 * V_124 /
1000000 ) - 1 , 8 ) / 8 ;
F_24 ( V_9 , V_149 ,
( F_72 ( V_121 ) & V_150 ) |
( F_73 ( V_123 ) & V_151 ) ) ;
V_77 = F_15 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_107 -> V_39 , L_44 ) ;
goto V_148;
}
F_74 ( & V_9 -> V_32 ) ;
F_75 ( & V_9 -> V_98 ) ;
V_77 = F_34 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_107 -> V_39 , L_45 ) ;
goto V_148;
}
V_77 = F_29 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_107 -> V_39 , L_46 ) ;
goto V_152;
}
V_77 = F_76 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_107 -> V_39 , L_47 ) ;
goto V_153;
}
return 0 ;
V_153:
F_33 ( V_6 ) ;
V_152:
F_40 ( V_6 ) ;
V_148:
F_77 ( V_9 -> V_124 ) ;
V_147:
F_78 ( V_9 -> V_124 ) ;
V_146:
F_79 ( V_9 -> V_124 ) ;
V_145:
F_77 ( V_9 -> V_141 ) ;
V_144:
F_78 ( V_9 -> V_141 ) ;
V_143:
F_79 ( V_9 -> V_141 ) ;
V_142:
F_80 ( V_9 -> V_1 , V_6 ) ;
V_140:
F_81 ( V_9 -> V_136 ) ;
V_137:
F_82 ( V_126 -> V_134 , F_62 ( V_126 ) ) ;
V_127:
F_83 ( V_6 ) ;
V_81:
return V_77 ;
}
static int T_5 F_84 ( struct V_106 * V_107 )
{
struct V_5 * V_6 = F_85 ( V_107 ) ;
struct V_125 * V_126 = F_57 ( V_107 , V_128 , 0 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_86 ( V_6 ) ;
F_33 ( V_6 ) ;
F_40 ( V_6 ) ;
F_87 ( V_9 -> V_124 ) ;
F_79 ( V_9 -> V_124 ) ;
F_77 ( V_9 -> V_141 ) ;
F_78 ( V_9 -> V_141 ) ;
F_79 ( V_9 -> V_141 ) ;
F_80 ( V_9 -> V_1 , V_6 ) ;
F_81 ( V_9 -> V_136 ) ;
F_82 ( V_126 -> V_134 , F_62 ( V_126 ) ) ;
F_83 ( V_6 ) ;
return 0 ;
}
