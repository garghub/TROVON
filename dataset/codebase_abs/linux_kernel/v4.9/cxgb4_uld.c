static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_6 ;
unsigned int V_7 ;
F_2 ( & V_4 -> V_8 , V_6 ) ;
V_7 = F_3 ( V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 < V_4 -> V_10 ) {
F_4 ( V_7 , V_4 -> V_9 ) ;
} else {
F_5 ( & V_4 -> V_8 , V_6 ) ;
return - V_11 ;
}
F_5 ( & V_4 -> V_8 , V_6 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_8 , V_6 ) ;
F_7 ( V_7 , V_4 -> V_9 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_2 -> V_14 [ V_13 -> V_14 ] . V_15 )
V_2 -> V_14 [ V_13 -> V_14 ] . V_15 ( & V_13 -> V_16 ) ;
}
static int F_9 ( struct V_12 * V_13 , const T_1 * V_17 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_20 * V_21 = F_10 ( V_13 , struct V_20 , V_22 ) ;
int V_23 ;
if ( ( ( const struct V_24 * ) V_17 ) -> V_25 == V_26 &&
( ( const struct V_27 * ) ( V_17 + 1 ) ) -> type == V_28 )
V_17 += 2 ;
if ( V_13 -> V_29 )
V_23 = V_2 -> V_14 [ V_13 -> V_14 ] . F_11 ( V_2 -> V_14 [ V_13 -> V_14 ] . V_30 ,
V_17 , V_19 , & V_13 -> V_16 ,
& V_13 -> V_31 ) ;
else
V_23 = V_2 -> V_14 [ V_13 -> V_14 ] . F_12 ( V_2 -> V_14 [ V_13 -> V_14 ] . V_30 ,
V_17 , V_19 ) ;
if ( V_23 ) {
V_21 -> V_32 . V_33 ++ ;
return - 1 ;
}
if ( ! V_19 )
V_21 -> V_32 . V_34 ++ ;
else if ( V_19 == V_35 )
V_21 -> V_32 . V_36 ++ ;
else
V_21 -> V_32 . V_37 ++ ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_38 * V_39 , bool V_40 )
{
struct V_41 * V_42 = & V_2 -> V_41 ;
unsigned int V_43 = V_39 -> V_44 + V_39 -> V_45 ;
struct V_20 * V_13 = V_39 -> V_46 ;
unsigned short * V_47 = V_39 -> V_48 ;
unsigned int V_49 = 0 ;
unsigned int V_50 ;
int V_51 , V_52 , V_53 , V_54 = 0 ;
V_50 = V_39 -> V_44 / V_2 -> V_55 . V_56 ;
if ( V_2 -> V_6 & V_57 )
V_53 = 1 ;
else
V_53 = - ( ( int ) V_42 -> V_58 . V_59 + 1 ) ;
for ( V_51 = 0 ; V_51 < V_43 ; V_51 ++ , V_13 ++ ) {
if ( V_51 == V_39 -> V_44 ) {
V_50 = V_39 -> V_45 / V_2 -> V_55 . V_56 ;
V_54 = 0 ;
}
if ( V_53 >= 0 ) {
V_49 = F_1 ( V_2 ) ;
V_53 = V_2 -> V_60 [ V_49 ] . V_61 ;
}
V_52 = F_14 ( V_2 , & V_13 -> V_22 , false ,
V_2 -> V_62 [ V_54 ++ / V_50 ] ,
V_53 ,
V_13 -> V_63 . V_64 ? & V_13 -> V_63 : NULL ,
F_9 ,
V_40 ? F_8 : NULL ,
0 ) ;
if ( V_52 )
goto V_65;
if ( V_53 >= 0 )
V_39 -> V_66 [ V_51 ] = V_49 ;
memset ( & V_13 -> V_32 , 0 , sizeof( V_13 -> V_32 ) ) ;
if ( V_47 )
V_47 [ V_51 ] = V_13 -> V_22 . V_59 ;
}
return 0 ;
V_65:
V_13 = V_39 -> V_46 ;
for ( ; V_51 ; V_51 -- , V_13 ++ ) {
if ( V_13 -> V_22 . V_67 )
F_15 ( V_2 , & V_13 -> V_22 ,
V_13 -> V_63 . V_64 ? & V_13 -> V_63 : NULL ) ;
}
return V_52 ;
}
static int
F_16 ( struct V_1 * V_2 , unsigned int V_68 , bool V_40 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
int V_51 , V_23 = 0 ;
if ( V_2 -> V_6 & V_57 ) {
V_39 -> V_66 = F_17 ( ( V_39 -> V_44 + V_39 -> V_45 ) ,
sizeof( unsigned short ) ,
V_70 ) ;
if ( ! V_39 -> V_66 )
return - V_71 ;
}
V_23 = ! ( ! F_13 ( V_2 , V_39 , V_40 ) ) ;
if ( V_2 -> V_6 & V_72 &&
! V_23 && V_68 == V_73 ) {
struct V_41 * V_42 = & V_2 -> V_41 ;
unsigned int V_74 ;
T_2 V_75 , V_76 ;
V_76 = V_77 ;
F_18 (adap, i) {
V_74 = V_39 -> V_46 [ V_51 ] . V_22 . V_78 ;
V_75 = ( F_19 ( V_79 ) |
F_20 ( V_76 ) |
F_21 ( V_42 -> V_80 [ V_51 ] . V_13 . V_78 ) ) ;
V_23 = F_22 ( V_2 , V_2 -> V_81 , V_2 -> V_82 ,
0 , 1 , & V_75 , & V_74 ) ;
}
}
return V_23 ;
}
static void F_23 ( struct V_1 * V_2 , int V_83 ,
struct V_20 * V_13 )
{
for ( ; V_83 ; V_83 -- , V_13 ++ ) {
if ( V_13 -> V_22 . V_67 )
F_15 ( V_2 , & V_13 -> V_22 ,
V_13 -> V_63 . V_64 ? & V_13 -> V_63 : NULL ) ;
}
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
if ( V_2 -> V_6 & V_72 && V_68 == V_73 ) {
struct V_41 * V_42 = & V_2 -> V_41 ;
T_2 V_75 , V_76 , V_74 = 0 ;
int V_51 ;
V_76 = V_77 ;
F_18 (adap, i) {
V_75 = ( F_19 ( V_79 ) |
F_20 ( V_76 ) |
F_21 ( V_42 -> V_80 [ V_51 ] . V_13 . V_78 ) ) ;
F_22 ( V_2 , V_2 -> V_81 , V_2 -> V_82 ,
0 , 1 , & V_75 , & V_74 ) ;
}
}
if ( V_39 -> V_45 )
F_23 ( V_2 , V_39 -> V_45 ,
V_39 -> V_46 + V_39 -> V_44 ) ;
F_23 ( V_2 , V_39 -> V_44 , V_39 -> V_46 ) ;
if ( V_2 -> V_6 & V_57 )
F_25 ( V_39 -> V_66 ) ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_68 ,
const struct V_84 * V_85 )
{
struct V_41 * V_42 = & V_2 -> V_41 ;
struct V_38 * V_39 ;
int V_51 , V_44 , V_86 ;
V_39 = F_27 ( sizeof( * V_39 ) , V_70 ) ;
if ( ! V_39 )
return - V_71 ;
if ( V_2 -> V_6 & V_57 && V_85 -> V_44 > V_42 -> V_87 ) {
V_51 = V_42 -> V_87 ;
V_39 -> V_44 = F_28 ( V_51 , V_2 -> V_55 . V_56 ) ;
} else {
V_51 = F_29 ( int , V_85 -> V_44 ,
F_30 () ) ;
V_39 -> V_44 = F_28 ( V_51 , V_2 -> V_55 . V_56 ) ;
}
if ( ! V_85 -> V_88 ) {
V_39 -> V_45 = 0 ;
} else {
if ( V_2 -> V_6 & V_57 )
V_39 -> V_45 = F_29 ( int , V_42 -> V_87 ,
F_30 () ) ;
else
V_39 -> V_45 = F_29 ( int , V_89 ,
F_30 () ) ;
V_39 -> V_45 = ( ( V_39 -> V_45 / V_2 -> V_55 . V_56 ) *
V_2 -> V_55 . V_56 ) ;
V_39 -> V_45 = F_31 ( int , V_39 -> V_45 ,
V_2 -> V_55 . V_56 ) ;
}
V_44 = V_39 -> V_44 + V_39 -> V_45 ;
V_39 -> V_46 = F_17 ( V_44 , sizeof( struct V_20 ) ,
V_70 ) ;
if ( ! V_39 -> V_46 ) {
F_25 ( V_39 ) ;
return - V_71 ;
}
V_39 -> V_48 = F_17 ( V_44 , sizeof( unsigned short ) , V_70 ) ;
if ( ! V_39 -> V_48 ) {
F_25 ( V_39 -> V_46 ) ;
F_25 ( V_39 ) ;
return - V_71 ;
}
for ( V_51 = 0 ; V_51 < V_39 -> V_44 ; V_51 ++ ) {
struct V_20 * V_90 = & V_39 -> V_46 [ V_51 ] ;
F_32 ( V_2 , & V_90 -> V_22 , 5 , 1 , V_85 -> V_91 , 64 ) ;
V_90 -> V_22 . V_14 = V_68 ;
V_90 -> V_63 . V_64 = 72 ;
}
V_86 = 64 + V_2 -> V_92 . V_93 . V_64 + V_2 -> V_94 . V_95 ;
if ( V_86 > V_96 ) {
F_33 ( V_2 -> V_97 , L_1 ) ;
V_86 = V_96 ;
}
for ( V_51 = V_39 -> V_44 ; V_51 < V_44 ; V_51 ++ ) {
struct V_20 * V_90 = & V_39 -> V_46 [ V_51 ] ;
F_32 ( V_2 , & V_90 -> V_22 , 5 , 1 , V_86 , 64 ) ;
V_90 -> V_22 . V_14 = V_68 ;
}
memcpy ( V_39 -> V_98 , V_85 -> V_98 , V_99 ) ;
V_2 -> V_41 . V_69 [ V_68 ] = V_39 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
F_25 ( V_39 -> V_48 ) ;
F_25 ( V_39 -> V_46 ) ;
F_25 ( V_39 ) ;
}
static int
F_35 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
int V_52 = 0 ;
unsigned int V_61 , V_49 ;
F_36 (rxq_info, idx) {
V_49 = V_39 -> V_66 [ V_61 ] ;
V_52 = F_37 ( V_2 -> V_60 [ V_49 ] . V_100 ,
V_101 , 0 ,
V_2 -> V_60 [ V_49 ] . V_67 ,
& V_39 -> V_46 [ V_61 ] . V_22 ) ;
if ( V_52 )
goto V_102;
}
return 0 ;
V_102:
while ( V_61 -- > 0 ) {
V_49 = V_39 -> V_66 [ V_61 ] ;
F_6 ( V_2 , V_49 ) ;
F_38 ( V_2 -> V_60 [ V_49 ] . V_100 ,
& V_39 -> V_46 [ V_61 ] . V_22 ) ;
}
return V_52 ;
}
static void
F_39 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
unsigned int V_61 , V_49 ;
F_36 (rxq_info, idx) {
V_49 = V_39 -> V_66 [ V_61 ] ;
F_6 ( V_2 , V_49 ) ;
F_38 ( V_2 -> V_60 [ V_49 ] . V_100 ,
& V_39 -> V_46 [ V_61 ] . V_22 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
int V_83 = sizeof( V_2 -> V_60 [ 0 ] . V_67 ) ;
unsigned int V_61 , V_49 ;
F_36 (rxq_info, idx) {
V_49 = V_39 -> V_66 [ V_61 ] ;
snprintf ( V_2 -> V_60 [ V_49 ] . V_67 , V_83 , L_2 ,
V_2 -> V_62 [ 0 ] -> V_98 , V_39 -> V_98 , V_61 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_13 )
return;
if ( V_13 -> V_103 ) {
F_42 ( V_13 ) ;
F_43 ( & V_13 -> V_31 ) ;
}
F_44 ( V_2 , F_45 ( V_104 ) ,
F_46 ( V_13 -> V_105 ) |
F_47 ( V_13 -> V_78 ) ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( V_13 && V_13 -> V_103 ) {
F_49 ( & V_13 -> V_31 ) ;
F_50 () ;
while ( ! F_51 ( V_13 ) )
F_52 ( 1 ) ;
F_53 () ;
}
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
int V_61 ;
F_36 (rxq_info, idx)
F_41 ( V_2 , & V_39 -> V_46 [ V_61 ] . V_22 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
int V_61 ;
F_36 (rxq_info, idx)
F_48 ( V_2 , & V_39 -> V_46 [ V_61 ] . V_22 ) ;
}
static void F_56 ( struct V_1 * V_2 , unsigned int V_68 ,
struct V_106 * V_107 )
{
struct V_38 * V_39 = V_2 -> V_41 . V_69 [ V_68 ] ;
V_107 -> V_108 = V_39 -> V_48 ;
V_107 -> V_44 = V_39 -> V_44 ;
V_107 -> V_109 = V_39 -> V_48 + V_39 -> V_44 ;
V_107 -> V_45 = V_39 -> V_45 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_41 ;
V_2 -> V_14 = F_17 ( V_110 , sizeof( * V_2 -> V_14 ) , V_70 ) ;
if ( ! V_2 -> V_14 )
return - V_71 ;
V_42 -> V_69 = F_27 ( V_110 *
sizeof( struct V_38 * ) ,
V_70 ) ;
if ( ! V_42 -> V_69 )
goto V_111;
return 0 ;
V_111:
F_25 ( V_2 -> V_14 ) ;
return - V_71 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_41 ;
F_25 ( V_42 -> V_69 ) ;
F_25 ( V_2 -> V_14 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
unsigned int V_51 ;
if ( ! V_2 -> V_14 )
return;
for ( V_51 = 0 ; V_51 < V_110 ; V_51 ++ ) {
if ( ! V_2 -> V_14 [ V_51 ] . V_30 )
continue;
V_39 = V_2 -> V_41 . V_69 [ V_51 ] ;
if ( V_2 -> V_6 & V_72 )
F_55 ( V_2 , V_51 ) ;
if ( V_2 -> V_6 & V_57 )
F_39 ( V_2 , V_51 ) ;
F_24 ( V_2 , V_51 ) ;
F_34 ( V_2 , V_51 ) ;
}
}
static void F_60 ( struct V_1 * V_2 , struct V_106 * V_112 )
{
int V_51 ;
V_112 -> V_113 = V_2 -> V_113 ;
V_112 -> V_82 = V_2 -> V_82 ;
V_112 -> V_114 = V_2 -> V_114 ;
V_112 -> V_94 = & V_2 -> V_94 ;
V_112 -> V_115 = V_2 -> V_62 ;
V_112 -> V_116 = & V_2 -> V_92 ;
V_112 -> V_117 = V_2 -> V_55 . V_117 ;
V_112 -> V_118 = V_2 -> V_41 . V_119 ;
V_112 -> V_120 = V_2 -> V_55 . V_56 ;
V_112 -> V_56 = V_2 -> V_55 . V_56 ;
V_112 -> V_121 = V_2 -> V_55 . V_122 ;
V_112 -> V_123 = F_61 ( F_62 ( V_2 , V_124 ) ) ;
V_112 -> V_125 = F_62 ( V_2 , V_126 ) ;
V_112 -> V_127 = F_62 ( V_2 , V_128 ) ;
V_112 -> V_129 = F_62 ( V_2 , V_130 ) ;
V_112 -> V_131 = & V_2 -> V_131 ;
V_112 -> V_132 = V_2 -> V_55 . V_133 ;
V_112 -> V_134 = 1000000000 / V_2 -> V_55 . V_135 . V_136 ;
V_112 -> V_137 = 1 << V_2 -> V_55 . V_41 . V_138 ;
V_112 -> V_139 = 1 << V_2 -> V_55 . V_41 . V_140 ;
V_112 -> V_141 = V_2 -> V_55 . V_142 . V_143 ;
for ( V_51 = 0 ; V_51 < V_144 ; V_51 ++ )
V_112 -> V_145 [ V_51 ] = V_51 ;
V_112 -> V_146 = V_2 -> V_147 + F_45 ( V_104 ) ;
V_112 -> V_148 = V_2 -> V_147 + F_45 ( V_149 ) ;
V_112 -> V_150 = V_2 -> V_55 . V_150 ;
V_112 -> V_151 = V_151 ;
V_112 -> V_152 = V_2 -> V_41 . V_153 ;
V_112 -> V_154 = V_2 -> V_41 . V_155 ;
V_112 -> V_156 = V_2 -> V_41 . V_157 ;
V_112 -> V_158 = V_2 -> V_6 & V_159 ;
V_112 -> V_160 = V_2 -> V_55 . V_160 ;
V_112 -> V_161 = V_2 -> V_55 . V_161 ;
V_112 -> V_162 = V_2 -> V_55 . V_162 ;
V_112 -> V_163 = F_63 ( V_2 -> V_97 ) ;
V_112 -> V_164 = V_2 -> V_55 . V_164 ;
}
static void F_64 ( struct V_1 * V_2 , unsigned int V_14 )
{
void * V_30 ;
struct V_106 V_107 ;
F_60 ( V_2 , & V_107 ) ;
F_56 ( V_2 , V_14 , & V_107 ) ;
V_30 = V_2 -> V_14 [ V_14 ] . F_65 ( & V_107 ) ;
if ( F_66 ( V_30 ) ) {
F_33 ( V_2 -> V_97 ,
L_3 ,
V_2 -> V_14 [ V_14 ] . V_98 , F_67 ( V_30 ) ) ;
return;
}
V_2 -> V_14 [ V_14 ] . V_30 = V_30 ;
F_68 () ;
if ( V_2 -> V_6 & V_72 )
V_2 -> V_14 [ V_14 ] . F_69 ( V_30 , V_165 ) ;
}
int F_70 ( enum V_166 type ,
const struct V_84 * V_167 )
{
int V_23 = 0 ;
unsigned int V_168 = 0 ;
struct V_1 * V_2 ;
if ( type >= V_110 )
return - V_169 ;
F_71 ( & V_170 ) ;
F_72 (adap, &adapter_list, list_node) {
if ( ( type == V_171 && ! F_73 ( V_2 ) ) ||
( type != V_171 && ! F_74 ( V_2 ) ) )
continue;
if ( type == V_172 && F_75 ( V_2 -> V_55 . V_133 ) )
continue;
V_23 = F_26 ( V_2 , type , V_167 ) ;
if ( V_23 )
goto V_173;
V_23 = F_16 ( V_2 , type , V_167 -> V_40 ) ;
if ( V_23 )
goto V_174;
if ( V_2 -> V_6 & V_57 ) {
F_40 ( V_2 , type ) ;
V_23 = F_35 ( V_2 , type ) ;
if ( V_23 )
goto V_175;
}
if ( V_2 -> V_6 & V_72 )
F_54 ( V_2 , type ) ;
if ( V_2 -> V_14 [ type ] . F_65 ) {
V_23 = - V_176 ;
goto F_38;
}
V_2 -> V_14 [ type ] = * V_167 ;
F_64 ( V_2 , type ) ;
V_168 ++ ;
}
F_76 ( & V_170 ) ;
return 0 ;
F_38:
if ( V_2 -> V_6 & V_72 )
F_55 ( V_2 , type ) ;
if ( V_2 -> V_6 & V_57 )
F_39 ( V_2 , type ) ;
V_175:
F_24 ( V_2 , type ) ;
V_174:
F_34 ( V_2 , type ) ;
V_173:
F_72 (adap, &adapter_list, list_node) {
if ( ( type == V_171 && ! F_73 ( V_2 ) ) ||
( type != V_171 && ! F_74 ( V_2 ) ) )
continue;
if ( type == V_172 && F_75 ( V_2 -> V_55 . V_133 ) )
continue;
if ( ! V_168 )
break;
V_2 -> V_14 [ type ] . V_30 = NULL ;
V_2 -> V_14 [ type ] . F_65 = NULL ;
if ( V_2 -> V_6 & V_72 )
F_55 ( V_2 , type ) ;
if ( V_2 -> V_6 & V_57 )
F_39 ( V_2 , type ) ;
F_24 ( V_2 , type ) ;
F_34 ( V_2 , type ) ;
V_168 -- ;
}
F_76 ( & V_170 ) ;
return V_23 ;
}
int F_77 ( enum V_166 type )
{
struct V_1 * V_2 ;
if ( type >= V_110 )
return - V_169 ;
F_71 ( & V_170 ) ;
F_72 (adap, &adapter_list, list_node) {
if ( ( type == V_171 && ! F_73 ( V_2 ) ) ||
( type != V_171 && ! F_74 ( V_2 ) ) )
continue;
if ( type == V_172 && F_75 ( V_2 -> V_55 . V_133 ) )
continue;
V_2 -> V_14 [ type ] . V_30 = NULL ;
V_2 -> V_14 [ type ] . F_65 = NULL ;
if ( V_2 -> V_6 & V_72 )
F_55 ( V_2 , type ) ;
if ( V_2 -> V_6 & V_57 )
F_39 ( V_2 , type ) ;
F_24 ( V_2 , type ) ;
F_34 ( V_2 , type ) ;
}
F_76 ( & V_170 ) ;
return 0 ;
}
