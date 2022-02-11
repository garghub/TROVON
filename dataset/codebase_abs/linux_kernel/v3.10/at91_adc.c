static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_12 ; V_10 ++ ) {
if ( ! F_3 ( V_10 , V_6 -> V_13 ) )
continue;
V_9 -> V_14 [ V_11 ] = F_4 ( V_9 , F_5 ( V_9 , V_10 ) ) ;
V_11 ++ ;
}
if ( V_6 -> V_15 ) {
T_2 * V_16 = ( T_2 * ) ( ( V_17 * ) V_9 -> V_14 +
F_6 ( V_11 , sizeof( T_2 ) ) ) ;
* V_16 = V_4 -> V_16 ;
}
F_7 ( V_6 , ( V_17 * ) V_9 -> V_14 ) ;
F_8 ( V_6 -> V_18 ) ;
F_4 ( V_9 , V_19 ) ;
F_9 ( V_9 -> V_1 ) ;
return V_20 ;
}
static T_1 F_10 ( int V_1 , void * V_21 )
{
struct V_5 * V_6 = V_21 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_3 V_22 = F_4 ( V_9 , V_9 -> V_23 -> V_24 ) ;
if ( ! ( V_22 & V_9 -> V_23 -> V_25 ) )
return V_20 ;
if ( F_11 ( V_6 ) ) {
F_12 ( V_1 ) ;
F_13 ( V_6 -> V_18 , F_14 () ) ;
} else {
V_9 -> V_26 = F_4 ( V_9 , V_19 ) ;
V_9 -> V_27 = true ;
F_15 ( & V_9 -> V_28 ) ;
}
return V_20 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_29 * V_30 , * V_16 ;
int V_31 , V_32 = 0 ;
V_6 -> V_33 = F_17 ( & V_9 -> V_34 ,
V_9 -> V_33 ) + 1 ;
V_30 = F_18 ( & V_6 -> V_35 ,
( ( V_6 -> V_33 + 1 ) *
sizeof( struct V_29 ) ) ,
V_36 ) ;
if ( ! V_30 )
return - V_37 ;
F_19 (bit, &st->channels_mask, st->num_channels) {
struct V_29 * V_38 = V_30 + V_32 ;
V_38 -> type = V_39 ;
V_38 -> V_40 = 1 ;
V_38 -> V_41 = V_31 ;
V_38 -> V_42 = V_32 ;
V_38 -> V_43 . V_44 = 'u' ;
V_38 -> V_43 . V_45 = V_9 -> V_46 ;
V_38 -> V_43 . V_47 = 16 ;
V_38 -> V_48 = F_20 ( V_49 ) ;
V_38 -> V_50 = F_20 ( V_51 ) ;
V_32 ++ ;
}
V_16 = V_30 + V_32 ;
V_16 -> type = V_52 ;
V_16 -> V_41 = - 1 ;
V_16 -> V_42 = V_32 ;
V_16 -> V_43 . V_44 = 's' ;
V_16 -> V_43 . V_45 = 64 ;
V_16 -> V_43 . V_47 = 64 ;
V_6 -> V_53 = V_30 ;
return V_6 -> V_33 ;
}
static V_17 F_21 ( struct V_5 * V_6 ,
struct V_54 * V_55 ,
const char * V_56 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
V_17 V_57 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_58 ; V_10 ++ ) {
char * V_59 = F_22 ( V_36 ,
L_1 ,
V_6 -> V_59 ,
V_6 -> V_60 ,
V_55 [ V_10 ] . V_59 ) ;
if ( ! V_59 )
return - V_37 ;
if ( strcmp ( V_56 , V_59 ) == 0 ) {
V_57 = V_55 [ V_10 ] . V_57 ;
F_23 ( V_59 ) ;
break;
}
F_23 ( V_59 ) ;
}
return V_57 ;
}
static int F_24 ( struct V_61 * V_18 , bool V_62 )
{
struct V_5 * V_6 = F_25 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_63 * V_14 = V_6 -> V_14 ;
struct V_64 * V_65 = V_9 -> V_23 ;
T_3 V_22 = F_4 ( V_9 , V_65 -> V_66 ) ;
V_17 V_57 ;
V_17 V_31 ;
V_57 = F_21 ( V_6 ,
V_9 -> V_67 ,
V_6 -> V_18 -> V_59 ) ;
if ( V_57 == 0 )
return - V_68 ;
if ( V_62 ) {
V_9 -> V_14 = F_26 ( V_6 -> V_69 , V_36 ) ;
if ( V_9 -> V_14 == NULL )
return - V_37 ;
F_27 ( V_9 , V_65 -> V_66 ,
V_22 | V_57 ) ;
F_19 (bit, buffer->scan_mask,
st->num_channels) {
struct V_29 const * V_38 = V_6 -> V_53 + V_31 ;
F_27 ( V_9 , V_70 ,
F_28 ( V_38 -> V_41 ) ) ;
}
F_27 ( V_9 , V_71 , V_65 -> V_25 ) ;
} else {
F_27 ( V_9 , V_72 , V_65 -> V_25 ) ;
F_27 ( V_9 , V_65 -> V_66 ,
V_22 & ~ V_57 ) ;
F_19 (bit, buffer->scan_mask,
st->num_channels) {
struct V_29 const * V_38 = V_6 -> V_53 + V_31 ;
F_27 ( V_9 , V_73 ,
F_28 ( V_38 -> V_41 ) ) ;
}
F_23 ( V_9 -> V_14 ) ;
}
return 0 ;
}
static struct V_61 * F_29 ( struct V_5 * V_6 ,
struct V_54 * V_74 )
{
struct V_61 * V_18 ;
int V_75 ;
V_18 = F_30 ( L_1 , V_6 -> V_59 ,
V_6 -> V_60 , V_74 -> V_59 ) ;
if ( V_18 == NULL )
return NULL ;
V_18 -> V_35 . V_76 = V_6 -> V_35 . V_76 ;
F_31 ( V_18 , V_6 ) ;
V_18 -> V_77 = & V_78 ;
V_75 = F_32 ( V_18 ) ;
if ( V_75 )
return NULL ;
return V_18 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_75 ;
V_9 -> V_18 = F_18 ( & V_6 -> V_35 ,
V_9 -> V_58 * sizeof( V_9 -> V_18 ) ,
V_36 ) ;
if ( V_9 -> V_18 == NULL ) {
V_75 = - V_37 ;
goto V_79;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_58 ; V_10 ++ ) {
if ( V_9 -> V_67 [ V_10 ] . V_80 && ! ( V_9 -> V_81 ) )
continue;
V_9 -> V_18 [ V_10 ] = F_29 ( V_6 ,
V_9 -> V_67 + V_10 ) ;
if ( V_9 -> V_18 [ V_10 ] == NULL ) {
F_34 ( & V_6 -> V_35 ,
L_2 , V_10 ) ;
V_75 = - V_37 ;
goto V_82;
}
}
return 0 ;
V_82:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- ) {
F_35 ( V_9 -> V_18 [ V_10 ] ) ;
F_36 ( V_9 -> V_18 [ V_10 ] ) ;
}
V_79:
return V_75 ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_58 ; V_10 ++ ) {
F_35 ( V_9 -> V_18 [ V_10 ] ) ;
F_36 ( V_9 -> V_18 [ V_10 ] ) ;
}
}
static int F_38 ( struct V_5 * V_6 )
{
return F_39 ( V_6 , & V_83 ,
& F_1 , NULL ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
F_41 ( V_6 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_29 const * V_38 ,
int * V_84 , int * V_85 , long V_86 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_75 ;
switch ( V_86 ) {
case V_51 :
F_43 ( & V_9 -> V_87 ) ;
F_27 ( V_9 , V_70 ,
F_28 ( V_38 -> V_41 ) ) ;
F_27 ( V_9 , V_71 , V_9 -> V_23 -> V_25 ) ;
F_27 ( V_9 , V_88 , V_89 ) ;
V_75 = F_44 ( V_9 -> V_28 ,
V_9 -> V_27 ,
F_45 ( 1000 ) ) ;
if ( V_75 == 0 )
V_75 = - V_90 ;
if ( V_75 < 0 ) {
F_46 ( & V_9 -> V_87 ) ;
return V_75 ;
}
* V_84 = V_9 -> V_26 ;
F_27 ( V_9 , V_73 ,
F_28 ( V_38 -> V_41 ) ) ;
F_27 ( V_9 , V_72 , V_9 -> V_23 -> V_25 ) ;
V_9 -> V_26 = 0 ;
V_9 -> V_27 = false ;
F_46 ( & V_9 -> V_87 ) ;
return V_91 ;
case V_49 :
* V_84 = ( V_9 -> V_92 * 1000 ) >> V_38 -> V_43 . V_45 ;
* V_85 = 0 ;
return V_93 ;
default:
break;
}
return - V_68 ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_48 ( V_9 ) ;
struct V_96 * V_97 = V_95 -> V_35 . V_98 ;
int V_99 , V_10 , V_75 = 0 ;
char * V_100 , * V_101 ;
T_3 * V_102 ;
V_99 = F_49 ( V_97 , L_3 ) ;
if ( V_99 < 2 ) {
F_34 ( & V_6 -> V_35 , L_4
L_5 ) ;
return V_99 ;
}
V_102 = F_26 ( V_99 * sizeof( * V_102 ) , V_36 ) ;
if ( ! V_102 )
return - V_37 ;
if ( F_50 ( V_97 , L_6 , V_102 , V_99 ) ) {
F_34 ( & V_6 -> V_35 , L_7 ) ;
V_75 = - V_103 ;
goto V_75;
}
if ( F_51 ( V_97 , L_8 , ( const char * * ) & V_100 ) )
V_100 = L_9 ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
if ( F_52 ( V_97 , L_3 , V_10 , ( const char * * ) & V_101 ) )
continue;
if ( strcmp ( V_100 , V_101 ) )
continue;
V_9 -> V_46 = V_102 [ V_10 ] ;
if ( ! strcmp ( V_100 , L_10 ) )
V_9 -> V_104 = true ;
else
V_9 -> V_104 = false ;
F_53 ( & V_6 -> V_35 , L_11 , V_9 -> V_46 ) ;
goto V_75;
}
F_34 ( & V_6 -> V_35 , L_12 , V_100 ) ;
V_75:
F_23 ( V_102 ) ;
return V_75 ;
}
static int F_54 ( struct V_8 * V_9 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_48 ( V_9 ) ;
struct V_96 * V_105 = V_95 -> V_35 . V_98 ;
struct V_96 * V_106 ;
int V_10 = 0 , V_75 ;
T_3 V_107 ;
if ( ! V_105 )
return - V_68 ;
V_9 -> V_81 = F_55 ( V_105 , L_13 ) ;
if ( F_56 ( V_105 , L_14 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_15 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_34 = V_107 ;
if ( F_56 ( V_105 , L_16 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_17 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_33 = V_107 ;
V_9 -> V_108 = F_55 ( V_105 , L_18 ) ;
if ( F_56 ( V_105 , L_19 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_20 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_109 = V_107 ;
V_107 = 0 ;
F_56 ( V_105 , L_21 , & V_107 ) ;
V_9 -> V_110 = V_107 ;
if ( F_56 ( V_105 , L_22 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_23 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_92 = V_107 ;
V_75 = F_47 ( V_9 , V_95 ) ;
if ( V_75 )
goto V_79;
V_9 -> V_23 = F_18 ( & V_6 -> V_35 ,
sizeof( struct V_64 ) ,
V_36 ) ;
if ( ! V_9 -> V_23 ) {
F_34 ( & V_6 -> V_35 , L_24 ) ;
V_75 = - V_37 ;
goto V_79;
}
if ( F_56 ( V_105 , L_25 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_26 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_23 -> V_111 = V_107 ;
if ( F_56 ( V_105 , L_27 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_28 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_23 -> V_25 = V_107 ;
if ( F_56 ( V_105 , L_29 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_30 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_23 -> V_24 = V_107 ;
if ( F_56 ( V_105 , L_31 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_32 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_9 -> V_23 -> V_66 = V_107 ;
V_9 -> V_58 = F_57 ( V_105 ) ;
V_9 -> V_67 = F_18 ( & V_6 -> V_35 , V_9 -> V_58 *
sizeof( struct V_54 ) ,
V_36 ) ;
if ( ! V_9 -> V_67 ) {
F_34 ( & V_6 -> V_35 , L_33 ) ;
V_75 = - V_37 ;
goto V_79;
}
F_58 (node, trig_node) {
struct V_54 * V_18 = V_9 -> V_67 + V_10 ;
const char * V_59 ;
if ( F_51 ( V_106 , L_34 , & V_59 ) ) {
F_34 ( & V_6 -> V_35 , L_35 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_18 -> V_59 = V_59 ;
if ( F_56 ( V_106 , L_36 , & V_107 ) ) {
F_34 ( & V_6 -> V_35 , L_37 ) ;
V_75 = - V_68 ;
goto V_79;
}
V_18 -> V_57 = V_107 ;
V_18 -> V_80 = F_55 ( V_106 , L_38 ) ;
V_10 ++ ;
}
return 0 ;
V_79:
return V_75 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_94 * V_95 )
{
struct V_112 * V_113 = V_95 -> V_35 . V_114 ;
if ( ! V_113 )
return - V_68 ;
V_9 -> V_81 = V_113 -> V_115 ;
V_9 -> V_92 = V_113 -> V_116 ;
V_9 -> V_34 = V_113 -> V_117 ;
V_9 -> V_33 = V_113 -> V_33 ;
V_9 -> V_109 = V_113 -> V_109 ;
V_9 -> V_58 = V_113 -> V_58 ;
V_9 -> V_67 = V_113 -> V_67 ;
V_9 -> V_23 = V_113 -> V_23 ;
return 0 ;
}
static int F_60 ( struct V_94 * V_95 )
{
unsigned int V_118 , V_119 , V_120 , V_121 , V_122 ;
int V_75 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_123 * V_46 ;
T_3 V_65 ;
V_6 = F_61 ( sizeof( struct V_8 ) ) ;
if ( V_6 == NULL ) {
V_75 = - V_37 ;
goto V_79;
}
V_9 = F_2 ( V_6 ) ;
if ( V_95 -> V_35 . V_98 )
V_75 = F_54 ( V_9 , V_95 ) ;
else
V_75 = F_59 ( V_9 , V_95 ) ;
if ( V_75 ) {
F_34 ( & V_95 -> V_35 , L_39 ) ;
V_75 = - V_68 ;
goto V_124;
}
F_62 ( V_95 , V_6 ) ;
V_6 -> V_35 . V_76 = & V_95 -> V_35 ;
V_6 -> V_59 = F_63 ( & V_95 -> V_35 ) ;
V_6 -> V_125 = V_126 ;
V_6 -> V_127 = & V_128 ;
V_9 -> V_1 = F_64 ( V_95 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_34 ( & V_95 -> V_35 , L_40 ) ;
V_75 = - V_103 ;
goto V_124;
}
V_46 = F_65 ( V_95 , V_129 , 0 ) ;
V_9 -> V_130 = F_66 ( & V_95 -> V_35 , V_46 ) ;
if ( F_67 ( V_9 -> V_130 ) ) {
V_75 = F_68 ( V_9 -> V_130 ) ;
goto V_124;
}
F_27 ( V_9 , V_88 , V_131 ) ;
F_27 ( V_9 , V_72 , 0xFFFFFFFF ) ;
V_75 = F_69 ( V_9 -> V_1 ,
F_10 ,
0 ,
V_95 -> V_35 . V_132 -> V_59 ,
V_6 ) ;
if ( V_75 ) {
F_34 ( & V_95 -> V_35 , L_41 ) ;
goto V_124;
}
V_9 -> V_133 = F_70 ( & V_95 -> V_35 , L_42 ) ;
if ( F_67 ( V_9 -> V_133 ) ) {
F_34 ( & V_95 -> V_35 , L_43 ) ;
V_75 = F_68 ( V_9 -> V_133 ) ;
goto V_134;
}
V_75 = F_71 ( V_9 -> V_133 ) ;
if ( V_75 ) {
F_34 ( & V_95 -> V_35 ,
L_44 ) ;
goto V_134;
}
V_9 -> V_121 = F_70 ( & V_95 -> V_35 , L_45 ) ;
if ( F_67 ( V_9 -> V_121 ) ) {
F_34 ( & V_95 -> V_35 , L_46 ) ;
V_75 = F_68 ( V_9 -> V_121 ) ;
goto V_135;
}
V_75 = F_71 ( V_9 -> V_121 ) ;
if ( V_75 ) {
F_34 ( & V_95 -> V_35 ,
L_47 ) ;
goto V_135;
}
V_119 = F_72 ( V_9 -> V_133 ) ;
V_121 = F_72 ( V_9 -> V_121 ) ;
V_118 = ( V_119 / ( 2 * V_121 ) ) - 1 ;
if ( ! V_9 -> V_109 ) {
F_34 ( & V_95 -> V_35 , L_48 ) ;
V_75 = - V_68 ;
goto V_136;
}
V_120 = F_73 ( ( V_9 -> V_109 * V_121 /
1000000 ) - 1 , 8 ) / 8 ;
V_122 = F_73 ( ( V_9 -> V_110 * V_121 /
1000000 ) - 1 , 1 ) ;
V_65 = F_74 ( V_118 ) & V_137 ;
V_65 |= F_75 ( V_120 ) & V_138 ;
if ( V_9 -> V_104 )
V_65 |= V_139 ;
if ( V_9 -> V_108 )
V_65 |= V_140 ;
V_65 |= F_76 ( V_122 ) & V_141 ;
F_27 ( V_9 , V_142 , V_65 ) ;
V_75 = F_16 ( V_6 ) ;
if ( V_75 < 0 ) {
F_34 ( & V_95 -> V_35 , L_49 ) ;
goto V_136;
}
F_77 ( & V_9 -> V_28 ) ;
F_78 ( & V_9 -> V_87 ) ;
V_75 = F_38 ( V_6 ) ;
if ( V_75 < 0 ) {
F_34 ( & V_95 -> V_35 , L_50 ) ;
goto V_136;
}
V_75 = F_33 ( V_6 ) ;
if ( V_75 < 0 ) {
F_34 ( & V_95 -> V_35 , L_51 ) ;
goto V_143;
}
V_75 = F_79 ( V_6 ) ;
if ( V_75 < 0 ) {
F_34 ( & V_95 -> V_35 , L_52 ) ;
goto V_144;
}
return 0 ;
V_144:
F_37 ( V_6 ) ;
V_143:
F_40 ( V_6 ) ;
V_136:
F_80 ( V_9 -> V_121 ) ;
V_135:
F_80 ( V_9 -> V_133 ) ;
V_134:
F_81 ( V_9 -> V_1 , V_6 ) ;
V_124:
F_82 ( V_6 ) ;
V_79:
return V_75 ;
}
static int F_83 ( struct V_94 * V_95 )
{
struct V_5 * V_6 = F_84 ( V_95 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_85 ( V_6 ) ;
F_37 ( V_6 ) ;
F_40 ( V_6 ) ;
F_80 ( V_9 -> V_121 ) ;
F_80 ( V_9 -> V_133 ) ;
F_81 ( V_9 -> V_1 , V_6 ) ;
F_82 ( V_6 ) ;
return 0 ;
}
