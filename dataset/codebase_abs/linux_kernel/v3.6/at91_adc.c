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
return F_35 ( V_6 , & V_85 ,
& F_1 , NULL ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
F_37 ( V_6 ) ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_33 const * V_42 ,
int * V_86 , int * V_87 , long V_88 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_77 ;
switch ( V_88 ) {
case V_89 :
F_39 ( & V_9 -> V_90 ) ;
F_24 ( V_9 , V_72 ,
F_25 ( V_42 -> V_45 ) ) ;
F_24 ( V_9 , V_73 , V_9 -> V_27 -> V_29 ) ;
F_24 ( V_9 , V_91 , V_92 ) ;
V_77 = F_40 ( V_9 -> V_32 ,
V_9 -> V_31 ,
F_41 ( 1000 ) ) ;
if ( V_77 == 0 )
V_77 = - V_93 ;
if ( V_77 < 0 ) {
F_42 ( & V_9 -> V_90 ) ;
return V_77 ;
}
* V_86 = V_9 -> V_30 ;
F_24 ( V_9 , V_75 ,
F_25 ( V_42 -> V_45 ) ) ;
F_24 ( V_9 , V_74 , V_9 -> V_27 -> V_29 ) ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = false ;
F_42 ( & V_9 -> V_90 ) ;
return V_94 ;
case V_95 :
* V_86 = ( V_9 -> V_96 * 1000 ) >> V_42 -> V_47 . V_49 ;
* V_87 = 0 ;
return V_97 ;
default:
break;
}
return - V_70 ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = F_44 ( V_9 ) ;
struct V_100 * V_101 = V_99 -> V_39 . V_102 ;
struct V_100 * V_103 ;
int V_12 = 0 , V_77 ;
T_3 V_104 ;
if ( ! V_101 )
return - V_70 ;
V_9 -> V_83 = F_45 ( V_101 , L_3 ) ;
if ( F_46 ( V_101 , L_4 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_5 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_38 = V_104 ;
if ( F_46 ( V_101 , L_6 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_7 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_37 = V_104 ;
if ( F_46 ( V_101 , L_8 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_9 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_105 = V_104 ;
if ( F_46 ( V_101 , L_10 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_11 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_96 = V_104 ;
V_9 -> V_27 = F_17 ( & V_6 -> V_39 ,
sizeof( struct V_66 ) ,
V_40 ) ;
if ( ! V_9 -> V_27 ) {
F_30 ( & V_6 -> V_39 , L_12 ) ;
V_77 = - V_41 ;
goto V_81;
}
if ( F_46 ( V_101 , L_13 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_14 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_106 = V_104 ;
if ( F_46 ( V_101 , L_15 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_16 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_29 = V_104 ;
if ( F_46 ( V_101 , L_17 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_18 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_28 = V_104 ;
if ( F_46 ( V_101 , L_19 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_20 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_9 -> V_27 -> V_68 = V_104 ;
V_9 -> V_60 = F_47 ( V_101 ) ;
V_9 -> V_69 = F_17 ( & V_6 -> V_39 , V_9 -> V_60 *
sizeof( struct V_56 ) ,
V_40 ) ;
if ( ! V_9 -> V_69 ) {
F_30 ( & V_6 -> V_39 , L_21 ) ;
V_77 = - V_41 ;
goto V_81;
}
F_48 (node, trig_node) {
struct V_56 * V_21 = V_9 -> V_69 + V_12 ;
const char * V_61 ;
if ( F_49 ( V_103 , L_22 , & V_61 ) ) {
F_30 ( & V_6 -> V_39 , L_23 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_21 -> V_61 = V_61 ;
if ( F_46 ( V_103 , L_24 , & V_104 ) ) {
F_30 ( & V_6 -> V_39 , L_25 ) ;
V_77 = - V_70 ;
goto V_81;
}
V_21 -> V_59 = V_104 ;
V_21 -> V_82 = F_45 ( V_103 , L_26 ) ;
V_12 ++ ;
}
return 0 ;
V_81:
return V_77 ;
}
static int F_50 ( struct V_8 * V_9 ,
struct V_98 * V_99 )
{
struct V_107 * V_108 = V_99 -> V_39 . V_109 ;
if ( ! V_108 )
return - V_70 ;
V_9 -> V_83 = V_108 -> V_110 ;
V_9 -> V_96 = V_108 -> V_111 ;
V_9 -> V_38 = V_108 -> V_112 ;
V_9 -> V_37 = V_108 -> V_37 ;
V_9 -> V_105 = V_108 -> V_105 ;
V_9 -> V_60 = V_108 -> V_60 ;
V_9 -> V_69 = V_108 -> V_69 ;
V_9 -> V_27 = V_108 -> V_27 ;
return 0 ;
}
static int T_4 F_51 ( struct V_98 * V_99 )
{
unsigned int V_113 , V_114 , V_115 , V_116 ;
int V_77 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_117 * V_118 ;
V_6 = F_52 ( sizeof( struct V_8 ) ) ;
if ( V_6 == NULL ) {
V_77 = - V_41 ;
goto V_81;
}
V_9 = F_2 ( V_6 ) ;
if ( V_99 -> V_39 . V_102 )
V_77 = F_43 ( V_9 , V_99 ) ;
else
V_77 = F_50 ( V_9 , V_99 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_27 ) ;
V_77 = - V_70 ;
goto V_119;
}
V_118 = F_53 ( V_99 , V_120 , 0 ) ;
if ( ! V_118 ) {
F_30 ( & V_99 -> V_39 , L_28 ) ;
V_77 = - V_121 ;
goto V_81;
}
F_54 ( V_99 , V_6 ) ;
V_6 -> V_39 . V_78 = & V_99 -> V_39 ;
V_6 -> V_61 = F_55 ( & V_99 -> V_39 ) ;
V_6 -> V_122 = V_123 ;
V_6 -> V_124 = & V_125 ;
V_9 -> V_1 = F_56 ( V_99 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_30 ( & V_99 -> V_39 , L_29 ) ;
V_77 = - V_126 ;
goto V_119;
}
if ( ! F_57 ( V_118 -> V_127 , F_58 ( V_118 ) ,
L_30 ) ) {
F_30 ( & V_99 -> V_39 , L_31 ) ;
V_77 = - V_128 ;
goto V_119;
}
V_9 -> V_129 = F_59 ( V_118 -> V_127 , F_58 ( V_118 ) ) ;
if ( ! V_9 -> V_129 ) {
F_30 ( & V_99 -> V_39 , L_32 ) ;
V_77 = - V_41 ;
goto V_130;
}
F_24 ( V_9 , V_91 , V_131 ) ;
F_24 ( V_9 , V_74 , 0xFFFFFFFF ) ;
V_77 = F_60 ( V_9 -> V_1 ,
F_9 ,
0 ,
V_99 -> V_39 . V_132 -> V_61 ,
V_6 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_33 ) ;
goto V_133;
}
V_9 -> V_134 = F_61 ( & V_99 -> V_39 , L_34 ) ;
if ( F_62 ( V_9 -> V_134 ) ) {
F_30 ( & V_99 -> V_39 , L_35 ) ;
V_77 = F_63 ( V_9 -> V_134 ) ;
goto V_135;
}
V_77 = F_64 ( V_9 -> V_134 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_36 ) ;
goto V_136;
}
V_77 = F_65 ( V_9 -> V_134 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_37 ) ;
goto V_137;
}
V_9 -> V_116 = F_61 ( & V_99 -> V_39 , L_38 ) ;
if ( F_62 ( V_9 -> V_116 ) ) {
F_30 ( & V_99 -> V_39 , L_39 ) ;
V_77 = F_63 ( V_9 -> V_116 ) ;
goto V_138;
}
V_77 = F_64 ( V_9 -> V_116 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_40 ) ;
goto V_139;
}
V_77 = F_65 ( V_9 -> V_116 ) ;
if ( V_77 ) {
F_30 ( & V_99 -> V_39 , L_41 ) ;
goto V_140;
}
V_114 = F_66 ( V_9 -> V_134 ) ;
V_116 = F_66 ( V_9 -> V_116 ) ;
V_113 = ( V_114 / ( 2 * V_116 ) ) - 1 ;
if ( ! V_9 -> V_105 ) {
F_30 ( & V_99 -> V_39 , L_42 ) ;
V_77 = - V_70 ;
goto V_141;
}
V_115 = F_67 ( ( V_9 -> V_105 * V_116 /
1000000 ) - 1 , 8 ) / 8 ;
F_24 ( V_9 , V_142 ,
( F_68 ( V_113 ) & V_143 ) |
( F_69 ( V_115 ) & V_144 ) ) ;
V_77 = F_15 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_99 -> V_39 , L_43 ) ;
goto V_141;
}
F_70 ( & V_9 -> V_32 ) ;
F_71 ( & V_9 -> V_90 ) ;
V_77 = F_34 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_99 -> V_39 , L_44 ) ;
goto V_141;
}
V_77 = F_29 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_99 -> V_39 , L_45 ) ;
goto V_145;
}
V_77 = F_72 ( V_6 ) ;
if ( V_77 < 0 ) {
F_30 ( & V_99 -> V_39 , L_46 ) ;
goto V_146;
}
return 0 ;
V_146:
F_33 ( V_6 ) ;
V_145:
F_36 ( V_6 ) ;
V_141:
F_73 ( V_9 -> V_116 ) ;
V_140:
F_74 ( V_9 -> V_116 ) ;
V_139:
F_75 ( V_9 -> V_116 ) ;
V_138:
F_73 ( V_9 -> V_134 ) ;
V_137:
F_74 ( V_9 -> V_134 ) ;
V_136:
F_75 ( V_9 -> V_134 ) ;
V_135:
F_76 ( V_9 -> V_1 , V_6 ) ;
V_133:
F_77 ( V_9 -> V_129 ) ;
V_130:
F_78 ( V_118 -> V_127 , F_58 ( V_118 ) ) ;
V_119:
F_79 ( V_6 ) ;
V_81:
return V_77 ;
}
static int T_5 F_80 ( struct V_98 * V_99 )
{
struct V_5 * V_6 = F_81 ( V_99 ) ;
struct V_117 * V_118 = F_53 ( V_99 , V_120 , 0 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_82 ( V_6 ) ;
F_33 ( V_6 ) ;
F_36 ( V_6 ) ;
F_83 ( V_9 -> V_116 ) ;
F_75 ( V_9 -> V_116 ) ;
F_73 ( V_9 -> V_134 ) ;
F_74 ( V_9 -> V_134 ) ;
F_75 ( V_9 -> V_134 ) ;
F_76 ( V_9 -> V_1 , V_6 ) ;
F_77 ( V_9 -> V_129 ) ;
F_78 ( V_118 -> V_127 , F_58 ( V_118 ) ) ;
F_79 ( V_6 ) ;
return 0 ;
}
