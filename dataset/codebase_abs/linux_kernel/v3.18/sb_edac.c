static char * F_1 ( T_1 V_1 )
{
switch( F_2 ( V_1 ) ) {
case 0 :
return L_1 ;
case 1 :
return L_2 ;
case 2 :
return L_3 ;
default:
return L_4 ;
}
}
static inline int F_3 ( const struct V_2 * V_3 , T_1 V_1 ,
int V_4 )
{
return F_4 ( V_1 , V_3 [ V_4 ] . V_5 ,
V_3 [ V_4 ] . V_6 ) ;
}
static inline int F_5 ( enum type type , T_1 V_7 )
{
int V_8 = ( 1 << F_6 ( V_7 ) ) ;
int V_9 = 4 ;
if ( type == V_10 )
V_9 = 8 ;
if ( V_8 > V_9 ) {
F_7 ( 0 , L_5 ,
V_8 , V_9 , ( unsigned int ) F_6 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return V_8 ;
}
static inline int F_8 ( T_1 V_7 )
{
int V_12 = ( F_9 ( V_7 ) + 12 ) ;
if ( V_12 < 13 || V_12 > 18 ) {
F_7 ( 0 , L_6 ,
V_12 , ( unsigned int ) F_9 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return 1 << V_12 ;
}
static inline int F_10 ( T_1 V_7 )
{
int V_13 = ( F_11 ( V_7 ) + 10 ) ;
if ( V_13 > 12 ) {
F_7 ( 0 , L_7 ,
V_13 , ( unsigned int ) F_11 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return 1 << V_13 ;
}
static struct V_14 * F_12 ( T_2 V_15 )
{
struct V_14 * V_14 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_14 -> V_15 == V_15 )
return V_14 ;
}
return NULL ;
}
static struct V_14 * F_14 ( T_2 V_15 ,
const struct V_16 * V_3 )
{
struct V_14 * V_14 ;
V_14 = F_15 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_18 = F_15 ( sizeof( * V_14 -> V_18 ) * V_3 -> V_19 ,
V_17 ) ;
if ( ! V_14 -> V_18 ) {
F_16 ( V_14 ) ;
return NULL ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_19 = V_3 -> V_19 ;
F_17 ( & V_14 -> V_20 , & V_21 ) ;
return V_14 ;
}
static void F_18 ( struct V_14 * V_14 )
{
F_19 ( & V_14 -> V_20 ) ;
F_16 ( V_14 -> V_18 ) ;
F_16 ( V_14 ) ;
}
static T_3 F_20 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_25 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_23 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_26 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_25 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_27 , V_25 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_26 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_27 , V_26 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_27 ( T_1 V_1 )
{
return ( ( T_3 ) F_4 ( V_1 , 1 , 10 ) << 29 ) | 0x1fffffff ;
}
static enum V_28 F_28 ( struct V_22 * V_23 )
{
T_1 V_1 ;
enum V_28 V_29 ;
if ( V_23 -> V_30 ) {
F_21 ( V_23 -> V_30 , V_23 -> V_31 . V_32 ,
& V_1 ) ;
if ( F_4 ( V_1 , 11 , 11 ) )
V_29 = V_33 ;
else
V_29 = V_34 ;
} else
V_29 = V_35 ;
return V_29 ;
}
static enum V_28 F_29 ( struct V_22 * V_23 )
{
T_1 V_1 ;
bool V_36 = false ;
enum V_28 V_29 = V_35 ;
if ( ! V_23 -> V_30 )
goto V_37;
F_21 ( V_23 -> V_30 ,
V_38 , & V_1 ) ;
if ( F_4 ( V_1 , 16 , 16 ) )
V_36 = true ;
F_21 ( V_23 -> V_39 , V_40 , & V_1 ) ;
if ( F_4 ( V_1 , 14 , 14 ) ) {
if ( V_36 )
V_29 = V_41 ;
else
V_29 = V_42 ;
} else {
if ( V_36 )
V_29 = V_33 ;
else
V_29 = V_34 ;
}
V_37:
return V_29 ;
}
static T_2 F_30 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_43 , V_44 , & V_1 ) ;
return F_4 ( V_1 , 0 , 2 ) ;
}
static T_2 F_31 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_44 , & V_1 ) ;
return F_4 ( V_1 , 0 , 3 ) ;
}
static T_3 F_32 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_31 . V_45 , V_25 , & V_1 ) ;
return ( F_4 ( V_1 , 26 , 31 ) << 26 ) | 0x1ffffff ;
}
static T_3 F_33 ( struct V_22 * V_23 )
{
T_3 V_46 ;
T_1 V_1 ;
F_21 ( V_23 -> V_31 . V_45 , V_47 , & V_1 ) ;
V_46 = F_4 ( V_1 , 26 , 31 ) ;
F_21 ( V_23 -> V_31 . V_45 , V_48 , & V_1 ) ;
V_46 = ( ( V_1 << 6 ) | V_46 ) << 26 ;
return V_46 | 0x1ffffff ;
}
static T_3 F_34 ( T_1 V_1 )
{
return ( ( ( T_3 ) F_4 ( V_1 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_35 ( T_2 V_49 )
{
return ( ( V_49 >> 3 ) << 2 ) | ( V_49 & 0x3 ) ;
}
static inline T_2 F_36 ( T_2 V_49 )
{
return ( V_49 >> 2 ) & 0x1 ;
}
static struct V_50 * F_37 ( T_2 V_15 , T_1 V_51 )
{
struct V_50 * V_18 = NULL ;
do {
V_18 = F_38 ( V_52 , V_51 , V_18 ) ;
if ( V_18 && V_18 -> V_15 -> V_53 == V_15 )
break;
} while ( V_18 );
return V_18 ;
}
static int F_39 ( const T_2 V_15 , enum type type )
{
struct V_50 * V_18 = NULL ;
T_1 V_54 , V_51 ;
if ( type == V_55 )
V_51 = V_56 ;
else if ( type == V_10 )
V_51 = V_57 ;
else
V_51 = V_58 ;
V_18 = F_37 ( V_15 , V_51 ) ;
if ( ! V_18 ) {
F_40 ( V_59 , L_8
L_9 ,
V_52 , V_51 , V_15 ) ;
return - V_60 ;
}
F_21 ( V_18 , V_40 , & V_54 ) ;
if ( ! F_41 ( V_54 ) ) {
F_40 ( V_59 , L_10 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
struct V_64 * V_65 ;
unsigned V_66 , V_67 , V_68 , V_8 , V_12 , V_13 , V_69 ;
T_3 V_70 ;
T_1 V_1 ;
enum V_71 V_72 ;
enum V_28 V_29 ;
if ( V_23 -> V_31 . type == V_10 )
F_21 ( V_23 -> V_24 , V_73 , & V_1 ) ;
else
F_21 ( V_23 -> V_43 , V_73 , & V_1 ) ;
V_23 -> V_14 -> V_74 = F_43 ( V_1 ) ;
V_23 -> V_14 -> V_75 = V_23 -> V_31 . F_30 ( V_23 ) ;
F_7 ( 0 , L_11 ,
V_23 -> V_14 -> V_76 ,
V_23 -> V_14 -> V_75 ,
V_23 -> V_14 -> V_74 ) ;
F_21 ( V_23 -> V_77 , V_78 , & V_1 ) ;
if ( F_44 ( V_1 ) ) {
F_7 ( 0 , L_12 ) ;
V_23 -> V_79 = true ;
} else {
F_7 ( 0 , L_13 ) ;
V_23 -> V_79 = false ;
}
F_21 ( V_23 -> V_39 , V_40 , & V_23 -> V_31 . V_54 ) ;
if ( F_45 ( V_23 -> V_31 . V_54 ) ) {
F_7 ( 0 , L_14 ) ;
V_72 = V_80 ;
V_23 -> V_81 = true ;
} else {
F_7 ( 0 , L_15 ) ;
V_72 = V_82 ;
V_23 -> V_81 = false ;
}
if ( F_46 ( V_23 -> V_31 . V_54 ) ) {
F_7 ( 0 , L_16 ) ;
V_23 -> V_83 = true ;
} else {
F_7 ( 0 , L_17 ) ;
V_23 -> V_83 = false ;
}
V_29 = V_23 -> V_31 . F_28 ( V_23 ) ;
if ( V_29 == V_33 || V_29 == V_41 )
F_7 ( 0 , L_18 ) ;
else if ( V_29 == V_35 )
F_7 ( 0 , L_19 ) ;
else
F_7 ( 0 , L_20 ) ;
if ( V_29 == V_42 || V_41 )
V_68 = 16 ;
else
V_68 = 8 ;
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
T_1 V_7 ;
for ( V_67 = 0 ; V_67 < F_47 ( V_85 ) ; V_67 ++ ) {
V_65 = F_48 ( V_62 -> V_86 , V_62 -> V_87 , V_62 -> V_88 ,
V_66 , V_67 , 0 ) ;
F_21 ( V_23 -> V_89 [ V_66 ] ,
V_85 [ V_67 ] , & V_7 ) ;
F_7 ( 4 , L_21 , V_66 , V_67 , V_7 ) ;
if ( F_49 ( V_7 ) ) {
V_23 -> V_90 [ V_66 ] . V_87 ++ ;
V_8 = F_5 ( V_23 -> V_31 . type , V_7 ) ;
V_12 = F_8 ( V_7 ) ;
V_13 = F_10 ( V_7 ) ;
V_70 = ( ( T_3 ) V_12 * V_13 * V_68 * V_8 ) >> ( 20 - 3 ) ;
V_69 = F_50 ( V_70 ) ;
F_7 ( 0 , L_22 ,
V_23 -> V_14 -> V_76 , V_66 , V_67 ,
V_70 , V_69 ,
V_68 , V_8 , V_12 , V_13 ) ;
V_65 -> V_91 = V_69 ;
V_65 -> V_92 = 32 ;
switch ( V_68 ) {
case 16 :
V_65 -> V_93 = V_94 ;
break;
case 8 :
V_65 -> V_93 = V_95 ;
break;
case 4 :
V_65 -> V_93 = V_96 ;
break;
}
V_65 -> V_29 = V_29 ;
V_65 -> V_97 = V_72 ;
snprintf ( V_65 -> V_98 , sizeof( V_65 -> V_98 ) ,
L_23 ,
V_23 -> V_14 -> V_74 , V_66 , V_67 ) ;
}
}
}
return 0 ;
}
static void F_51 ( const struct V_61 * V_62 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
int V_66 , V_67 , V_99 , V_100 , V_101 , V_102 ;
T_1 V_1 ;
T_3 V_103 , V_104 = 0 ;
T_3 V_105 ;
T_1 V_106 , V_107 ;
T_1 V_108 ;
V_23 -> V_109 = V_23 -> V_31 . V_110 ( V_23 ) ;
V_105 = ( 1 + V_23 -> V_109 ) >> 20 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_24 , V_106 , V_107 , ( T_3 ) V_23 -> V_109 ) ;
V_23 -> V_111 = V_23 -> V_31 . V_112 ( V_23 ) ;
V_105 = ( 1 + V_23 -> V_111 ) >> 20 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_25 , V_106 , V_107 , ( T_3 ) V_23 -> V_111 ) ;
V_104 = 0 ;
for ( V_100 = 0 ; V_100 < V_23 -> V_31 . V_113 ; V_100 ++ ) {
F_21 ( V_23 -> V_114 , V_23 -> V_31 . V_115 [ V_100 ] ,
& V_1 ) ;
V_103 = F_53 ( V_1 ) ;
if ( ! F_54 ( V_1 ) )
continue;
if ( V_103 <= V_104 )
break;
V_105 = ( V_103 + 1 ) >> 20 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_26 ,
V_100 ,
F_1 ( V_1 ) ,
V_106 , V_107 ,
( ( T_3 ) V_105 ) << 20L ,
F_55 ( V_1 ) ? L_27 : L_28 ,
V_1 ) ;
V_104 = V_103 ;
F_21 ( V_23 -> V_114 , V_23 -> V_31 . V_116 [ V_100 ] ,
& V_1 ) ;
V_102 = F_3 ( V_23 -> V_31 . V_2 , V_1 , 0 ) ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ ) {
T_1 V_49 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_67 ) ;
if ( V_67 > 0 && V_102 == V_49 )
break;
F_7 ( 0 , L_29 ,
V_100 , V_67 , V_49 ) ;
}
}
V_104 = 0 ;
for ( V_101 = 0 ; V_101 < V_117 ; V_101 ++ ) {
F_21 ( V_23 -> V_118 , V_119 [ V_101 ] ,
& V_1 ) ;
V_103 = F_56 ( V_1 ) ;
if ( V_103 <= V_104 )
break;
V_105 = ( V_103 + 1 ) >> 20 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_30 ,
V_101 , V_106 , V_107 ,
( ( T_3 ) V_105 ) << 20L ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
( T_1 ) F_59 ( V_1 ) ,
( T_1 ) F_60 ( V_1 ) ,
( T_1 ) F_61 ( V_1 ) ,
( T_1 ) F_62 ( V_1 ) ,
V_1 ) ;
V_104 = V_103 ;
}
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
if ( ! V_23 -> V_90 [ V_66 ] . V_87 )
continue;
for ( V_67 = 0 ; V_67 < V_101 ; V_67 ++ ) {
F_21 ( V_23 -> V_89 [ V_66 ] ,
V_120 [ V_67 ] ,
& V_1 ) ;
V_105 = F_63 ( V_1 ) >> 20 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_31 ,
V_66 , V_67 ,
V_106 , V_107 ,
( ( T_3 ) V_105 ) << 20L ,
V_1 ) ;
}
}
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
if ( ! V_23 -> V_90 [ V_66 ] . V_87 )
continue;
for ( V_67 = 0 ; V_67 < V_121 ; V_67 ++ ) {
F_21 ( V_23 -> V_89 [ V_66 ] ,
V_122 [ V_67 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_105 = V_23 -> V_31 . F_27 ( V_1 ) >> 20 ;
V_108 = 1 << F_65 ( V_1 ) ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_32 ,
V_66 , V_67 ,
V_106 , V_107 ,
( ( T_3 ) V_105 ) << 20L ,
V_108 ,
V_1 ) ;
for ( V_99 = 0 ; V_99 < V_108 ; V_99 ++ ) {
F_21 ( V_23 -> V_89 [ V_66 ] ,
V_123 [ V_67 ] [ V_99 ] ,
& V_1 ) ;
V_105 = F_66 ( V_1 ) << 6 ;
V_106 = F_52 ( V_105 , 1000 , & V_107 ) ;
F_7 ( 0 , L_33 ,
V_66 , V_67 , V_99 ,
V_106 , V_107 ,
( ( T_3 ) V_105 ) << 20L ,
( T_1 ) F_67 ( V_1 ) ,
V_1 ) ;
}
}
}
}
static struct V_61 * F_68 ( T_2 V_75 )
{
struct V_14 * V_14 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_14 -> V_75 == V_75 )
return V_14 -> V_62 ;
}
return NULL ;
}
static int F_69 ( struct V_61 * V_62 ,
T_3 V_124 ,
T_2 * V_125 ,
long * V_126 ,
T_2 * V_127 ,
char * * V_128 , char * V_129 )
{
struct V_61 * V_130 ;
struct V_22 * V_23 = V_62 -> V_63 ;
struct V_50 * V_131 ;
int V_132 , V_100 , V_101 , V_133 , V_134 ;
int V_102 , V_135 , V_136 ;
int V_137 , V_138 = 0 ;
unsigned V_139 [ V_23 -> V_31 . V_140 ] ;
T_1 V_1 , V_115 ;
T_2 V_141 , V_142 , V_49 , V_143 = 0 ;
T_1 V_144 ;
T_1 V_108 ;
T_1 V_106 , V_107 ;
T_3 V_145 , V_146 , V_103 = 0 , V_104 = 0 ;
if ( ( V_124 > ( T_3 ) V_23 -> V_109 ) && ( V_124 < ( 1LL << 32 ) ) ) {
sprintf ( V_129 , L_34 , V_124 ) ;
return - V_11 ;
}
if ( V_124 >= ( T_3 ) V_23 -> V_111 ) {
sprintf ( V_129 , L_35 , V_124 ) ;
return - V_11 ;
}
for ( V_100 = 0 ; V_100 < V_23 -> V_31 . V_113 ; V_100 ++ ) {
F_21 ( V_23 -> V_114 , V_23 -> V_31 . V_115 [ V_100 ] ,
& V_1 ) ;
if ( ! F_54 ( V_1 ) )
continue;
V_103 = F_53 ( V_1 ) ;
if ( V_103 <= V_104 ) {
sprintf ( V_129 , L_36 ) ;
return - V_11 ;
}
if ( V_124 <= V_103 )
break;
V_104 = V_103 ;
}
if ( V_100 == V_23 -> V_31 . V_113 ) {
sprintf ( V_129 , L_36 ) ;
return - V_11 ;
}
V_115 = V_1 ;
* V_128 = F_1 ( V_115 ) ;
V_137 = F_55 ( V_115 ) ;
F_21 ( V_23 -> V_114 , V_23 -> V_31 . V_116 [ V_100 ] ,
& V_1 ) ;
if ( V_23 -> V_31 . type == V_147 ) {
V_102 = F_3 ( V_23 -> V_31 . V_2 , V_1 , 0 ) ;
for ( V_133 = 0 ; V_133 < 8 ; V_133 ++ ) {
T_1 V_49 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_133 ) ;
if ( V_133 > 0 && V_102 == V_49 )
break;
V_139 [ V_133 ] = V_49 ;
F_7 ( 0 , L_37 ,
V_133 , V_139 [ V_133 ] ) ;
}
F_7 ( 0 , L_38 ,
V_23 -> V_14 -> V_76 ,
V_100 ,
V_124 ,
V_103 ,
V_133 + 7 ,
! V_137 ? L_39 : L_40 ) ;
if ( V_137 )
V_135 = ( ( V_124 >> 6 ) ^ ( V_124 >> 16 ) ) & 7 ;
else
V_135 = ( V_124 >> 6 ) & 7 ;
switch ( V_133 ) {
case 1 :
V_135 = 0 ;
break;
case 2 :
V_135 = V_135 & 1 ;
break;
case 4 :
V_135 = V_135 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_129 , L_41 ) ;
return - V_11 ;
}
* V_125 = V_139 [ V_135 ] ;
F_7 ( 0 , L_42 ,
V_135 , V_133 , * V_125 ) ;
} else if ( V_23 -> V_31 . type == V_10 ) {
int V_148 , V_149 = F_70 ( V_115 ) ;
if ( V_149 ) {
V_148 = F_4 ( V_124 , 7 , 8 ) << 1 ;
V_148 |= F_4 ( V_124 , 9 , 9 ) ;
} else
V_148 = F_4 ( V_124 , 7 , 9 ) ;
if ( V_137 ) {
V_135 = F_4 ( V_124 , 16 , 18 ) ;
V_135 ^= V_148 ;
} else
V_135 = V_148 ;
V_49 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_135 ) ;
* V_125 = F_35 ( V_49 ) ;
V_143 = F_36 ( V_49 ) ;
if ( V_149 ) {
F_21 ( V_23 -> V_118 ,
V_150 , & V_1 ) ;
V_138 = F_4 ( V_1 , 22 , 22 ) ;
}
F_7 ( 0 , L_43 ,
V_135 , * V_125 , V_143 , V_138 ) ;
} else {
V_135 = ( V_124 >> 6 ) & 7 ;
V_49 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_135 ) ;
* V_125 = F_35 ( V_49 ) ;
V_143 = F_36 ( V_49 ) ;
F_7 ( 0 , L_44 ,
V_135 , * V_125 , V_143 ) ;
}
V_130 = F_68 ( * V_125 ) ;
if ( ! V_130 ) {
sprintf ( V_129 , L_45 ,
* V_125 ) ;
return - V_11 ;
}
V_62 = V_130 ;
V_23 = V_62 -> V_63 ;
V_104 = 0 ;
if ( V_23 -> V_31 . type == V_147 )
V_131 = V_23 -> V_118 ;
else {
if ( V_143 )
V_131 = V_23 -> V_151 ;
else
V_131 = V_23 -> V_118 ;
}
for ( V_101 = 0 ; V_101 < V_117 ; V_101 ++ ) {
F_21 ( V_131 , V_119 [ V_101 ] , & V_1 ) ;
V_103 = F_56 ( V_1 ) ;
if ( V_103 <= V_104 ) {
sprintf ( V_129 , L_46 ) ;
return - V_11 ;
}
if ( V_124 <= V_103 )
break;
V_104 = V_103 ;
}
if ( V_101 == V_117 ) {
sprintf ( V_129 , L_46 ) ;
return - V_11 ;
}
V_141 = F_58 ( V_1 ) + 1 ;
V_142 = F_57 ( V_1 ) + 1 ;
if ( V_141 == 3 )
V_135 = V_124 >> 6 ;
else
V_135 = ( V_124 >> ( 6 + V_142 + V_138 ) ) & 0x3 ;
V_135 = V_135 % V_141 ;
switch ( V_135 ) {
case 0 :
V_136 = F_59 ( V_1 ) ;
break;
case 1 :
V_136 = F_60 ( V_1 ) ;
break;
case 2 :
V_136 = F_61 ( V_1 ) ;
break;
case 3 :
V_136 = F_62 ( V_1 ) ;
break;
default:
sprintf ( V_129 , L_47 ) ;
return - V_11 ;
}
* V_126 = 1 << V_136 ;
F_21 ( V_23 -> V_89 [ V_136 ] ,
V_120 [ V_101 ] ,
& V_144 ) ;
if ( V_23 -> V_79 ) {
* V_126 |= 1 << ( ( V_136 + 2 ) % 4 ) ;
switch( V_141 ) {
case 2 :
case 4 :
V_134 = 1 << V_142 * ( V_141 >> 1 ) ;
break;
default:
sprintf ( V_129 , L_48 ) ;
return - V_11 ;
}
} else
V_134 = ( 1 << V_142 ) * V_141 ;
if ( V_23 -> V_81 )
* V_126 |= 1 << ( ( V_136 + 1 ) % 4 ) ;
V_146 = F_63 ( V_144 ) ;
F_7 ( 0 , L_49 ,
V_101 ,
V_124 ,
V_103 ,
( T_1 ) F_57 ( V_1 ) ,
V_141 ,
V_146 ,
V_135 ,
V_136 ,
* V_126 ) ;
if ( V_146 > V_124 ) {
sprintf ( V_129 , L_50 ,
V_146 , V_124 ) ;
return - V_11 ;
}
V_124 -= V_146 ;
V_145 = V_124 & 0x7f ;
V_124 >>= 6 ;
V_124 = F_71 ( V_124 , V_134 ) ;
#if 0
addr = addr / ch_way;
#endif
V_145 |= V_124 << 6 ;
for ( V_132 = 0 ; V_132 < V_121 ; V_132 ++ ) {
F_21 ( V_23 -> V_89 [ V_136 ] ,
V_122 [ V_132 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_103 = V_23 -> V_31 . F_27 ( V_1 ) ;
V_106 = F_52 ( V_103 >> 20 , 1000 , & V_107 ) ;
F_7 ( 0 , L_51 ,
V_132 ,
V_106 , V_107 ,
V_103 ,
1 << F_65 ( V_1 ) ) ;
if ( V_145 <= V_103 )
break;
}
if ( V_132 == V_121 ) {
sprintf ( V_129 , L_52 ,
V_145 ) ;
return - V_11 ;
}
V_108 = F_65 ( V_1 ) ;
if ( V_23 -> V_83 )
V_135 = ( V_145 >> 6 ) ;
else
V_135 = ( V_145 >> 13 ) ;
V_135 %= 1 << V_108 ;
F_21 ( V_23 -> V_89 [ V_136 ] ,
V_123 [ V_132 ] [ V_135 ] ,
& V_1 ) ;
* V_127 = F_67 ( V_1 ) ;
F_7 ( 0 , L_53 ,
V_132 ,
V_145 ,
V_103 ,
V_108 ,
V_135 ) ;
return 0 ;
}
static void F_72 ( struct V_14 * V_14 )
{
int V_66 ;
F_7 ( 0 , L_54 ) ;
for ( V_66 = 0 ; V_66 < V_14 -> V_19 ; V_66 ++ ) {
struct V_50 * V_18 = V_14 -> V_18 [ V_66 ] ;
if ( ! V_18 )
continue;
F_7 ( 0 , L_55 ,
V_18 -> V_15 -> V_53 ,
F_73 ( V_18 -> V_152 ) , F_74 ( V_18 -> V_152 ) ) ;
F_75 ( V_18 ) ;
}
}
static void F_76 ( void )
{
struct V_14 * V_14 , * V_153 ;
F_77 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_72 ( V_14 ) ;
F_18 ( V_14 ) ;
}
}
static int F_78 ( struct V_50 * * V_154 ,
T_2 * V_155 ,
const struct V_16 * V_3 ,
const unsigned V_156 )
{
struct V_14 * V_14 ;
const struct V_157 * V_158 = & V_3 -> V_159 [ V_156 ] ;
struct V_50 * V_18 = NULL ;
T_2 V_15 = 0 ;
F_40 ( V_160 ,
L_56 ,
V_52 , V_158 -> V_161 ) ;
V_18 = F_38 ( V_52 ,
V_158 -> V_161 , * V_154 ) ;
if ( ! V_18 ) {
if ( * V_154 ) {
* V_154 = V_18 ;
return 0 ;
}
if ( V_158 -> V_162 )
return 0 ;
if ( V_156 == 0 )
return - V_60 ;
F_40 ( V_163 ,
L_57 ,
V_52 , V_158 -> V_161 ) ;
return - V_60 ;
}
V_15 = V_18 -> V_15 -> V_53 ;
V_14 = F_12 ( V_15 ) ;
if ( ! V_14 ) {
V_14 = F_14 ( V_15 , V_3 ) ;
if ( ! V_14 ) {
F_75 ( V_18 ) ;
return - V_164 ;
}
( * V_155 ) ++ ;
}
if ( V_14 -> V_18 [ V_156 ] ) {
F_40 ( V_59 ,
L_58 ,
V_52 , V_158 -> V_161 ) ;
F_75 ( V_18 ) ;
return - V_60 ;
}
V_14 -> V_18 [ V_156 ] = V_18 ;
if ( F_79 ( F_80 ( V_18 ) < 0 ) ) {
F_40 ( V_59 ,
L_59 ,
V_52 , V_158 -> V_161 ) ;
return - V_60 ;
}
F_7 ( 0 , L_60 ,
V_52 , V_158 -> V_161 ) ;
F_81 ( V_18 ) ;
* V_154 = V_18 ;
return 0 ;
}
static int F_82 ( T_2 * V_155 ,
const struct V_16 * V_3 )
{
int V_66 , V_46 ;
struct V_50 * V_18 = NULL ;
while ( V_3 && V_3 -> V_159 ) {
for ( V_66 = 0 ; V_66 < V_3 -> V_19 ; V_66 ++ ) {
V_18 = NULL ;
do {
V_46 = F_78 ( & V_18 , V_155 ,
V_3 , V_66 ) ;
if ( V_46 < 0 ) {
if ( V_66 == 0 ) {
V_66 = V_3 -> V_19 ;
break;
}
F_76 () ;
return - V_60 ;
}
} while ( V_18 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_83 ( struct V_61 * V_62 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
struct V_50 * V_18 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_14 -> V_19 ; V_66 ++ ) {
V_18 = V_14 -> V_18 [ V_66 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_165 ) {
case V_166 :
V_23 -> V_114 = V_18 ;
break;
case V_167 :
V_23 -> V_24 = V_18 ;
break;
case V_168 :
V_23 -> V_43 = V_18 ;
break;
case V_169 :
V_23 -> V_118 = V_18 ;
break;
case V_58 :
V_23 -> V_39 = V_18 ;
break;
case V_170 :
V_23 -> V_77 = V_18 ;
break;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
{
int V_51 = V_18 -> V_165 - V_171 ;
V_23 -> V_89 [ V_51 ] = V_18 ;
}
break;
case V_175 :
V_23 -> V_30 = V_18 ;
break;
default:
goto error;
}
F_7 ( 0 , L_61 ,
V_18 -> V_176 , V_18 -> V_165 ,
V_14 -> V_15 ,
V_18 ) ;
}
if ( ! V_23 -> V_114 || ! V_23 -> V_24 || ! V_23 -> V_118 ||
! V_23 -> V_89 || ! V_23 -> V_77 || ! V_23 -> V_39 )
goto V_177;
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
if ( ! V_23 -> V_89 [ V_66 ] )
goto V_177;
}
return 0 ;
V_177:
F_40 ( V_59 , L_62 ) ;
return - V_60 ;
error:
F_40 ( V_59 , L_63 ,
V_52 , V_18 -> V_165 ) ;
return - V_11 ;
}
static int F_84 ( struct V_61 * V_62 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
struct V_50 * V_18 , * V_153 ;
int V_66 ;
bool V_178 = false ;
V_153 = F_38 ( V_52 ,
V_179 , NULL ) ;
if ( V_153 ) {
V_178 = true ;
F_75 ( V_153 ) ;
}
for ( V_66 = 0 ; V_66 < V_14 -> V_19 ; V_66 ++ ) {
V_18 = V_14 -> V_18 [ V_66 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_165 ) {
case V_180 :
V_23 -> V_118 = V_18 ;
break;
case V_56 :
V_23 -> V_39 = V_18 ;
case V_181 :
V_23 -> V_77 = V_18 ;
break;
case V_182 :
case V_183 :
if ( V_178 )
break;
case V_184 :
case V_185 :
{
int V_51 = V_18 -> V_165 - V_184 ;
V_23 -> V_89 [ V_51 ] = V_18 ;
}
break;
case V_186 :
V_23 -> V_30 = V_18 ;
break;
case V_187 :
if ( ! V_178 )
V_23 -> V_30 = V_18 ;
break;
case V_188 :
V_23 -> V_114 = V_18 ;
break;
case V_189 :
V_23 -> V_43 = V_18 ;
break;
case V_190 :
V_23 -> V_27 = V_18 ;
break;
case V_179 :
V_23 -> V_151 = V_18 ;
break;
case V_191 :
case V_192 :
{
int V_51 = V_18 -> V_165 - V_191 + 2 ;
F_85 ( ! V_178 ) ;
V_23 -> V_89 [ V_51 ] = V_18 ;
}
break;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_14 -> V_15 ,
F_73 ( V_18 -> V_152 ) , F_74 ( V_18 -> V_152 ) ,
V_18 ) ;
}
if ( ! V_23 -> V_114 || ! V_23 -> V_118 || ! V_23 -> V_43 ||
! V_23 -> V_27 || ! V_23 -> V_89 || ! V_23 -> V_77 ||
! V_23 -> V_39 )
goto V_177;
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
if ( ! V_23 -> V_89 [ V_66 ] )
goto V_177;
}
return 0 ;
V_177:
F_40 ( V_59 , L_62 ) ;
return - V_60 ;
error:
F_40 ( V_59 ,
L_63 , V_52 ,
V_18 -> V_165 ) ;
return - V_11 ;
}
static int F_86 ( struct V_61 * V_62 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
struct V_50 * V_18 , * V_153 ;
int V_66 ;
bool V_178 = false ;
V_153 = F_38 ( V_52 ,
V_193 , NULL ) ;
if ( V_153 ) {
V_178 = true ;
F_75 ( V_153 ) ;
}
if ( V_23 -> V_31 . V_45 == NULL )
V_23 -> V_31 . V_45 = F_38 ( V_52 ,
V_194 ,
NULL ) ;
for ( V_66 = 0 ; V_66 < V_14 -> V_19 ; V_66 ++ ) {
V_18 = V_14 -> V_18 [ V_66 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_165 ) {
case V_195 :
V_23 -> V_114 = V_18 ;
break;
case V_196 :
V_23 -> V_24 = V_18 ;
break;
case V_197 :
V_23 -> V_118 = V_18 ;
break;
case V_57 :
V_23 -> V_39 = V_18 ;
break;
case V_198 :
V_23 -> V_77 = V_18 ;
break;
case V_199 :
V_23 -> V_89 [ 0 ] = V_18 ;
break;
case V_200 :
V_23 -> V_89 [ 1 ] = V_18 ;
break;
case V_201 :
if ( ! V_178 )
V_23 -> V_89 [ 2 ] = V_18 ;
break;
case V_202 :
if ( ! V_178 )
V_23 -> V_89 [ 3 ] = V_18 ;
break;
case V_203 :
V_23 -> V_30 = V_18 ;
break;
case V_193 :
V_23 -> V_151 = V_18 ;
break;
case V_204 :
V_23 -> V_205 = V_18 ;
break;
case V_206 :
if ( V_178 )
V_23 -> V_89 [ 2 ] = V_18 ;
break;
case V_207 :
if ( V_178 )
V_23 -> V_89 [ 3 ] = V_18 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_14 -> V_15 ,
F_73 ( V_18 -> V_152 ) , F_74 ( V_18 -> V_152 ) ,
V_18 ) ;
}
if ( ! V_23 -> V_114 || ! V_23 -> V_118 || ! V_23 -> V_24 ||
! V_23 -> V_77 || ! V_23 -> V_39 || ! V_23 -> V_31 . V_45 )
goto V_177;
for ( V_66 = 0 ; V_66 < V_84 ; V_66 ++ ) {
if ( ! V_23 -> V_89 [ V_66 ] )
goto V_177;
}
return 0 ;
V_177:
F_40 ( V_59 , L_62 ) ;
return - V_60 ;
}
static void F_87 ( struct V_61 * V_62 ,
const struct V_208 * V_209 )
{
struct V_61 * V_130 ;
struct V_22 * V_23 = V_62 -> V_63 ;
enum V_210 V_211 ;
char * type , * V_212 , V_129 [ 256 ] ;
bool V_213 = F_4 ( V_209 -> V_214 , 0 , 0 ) ;
bool V_215 = F_4 ( V_209 -> V_216 , 62 , 62 ) ;
bool V_217 = F_4 ( V_209 -> V_216 , 61 , 61 ) ;
bool V_218 ;
T_1 V_219 = F_4 ( V_209 -> V_216 , 38 , 52 ) ;
T_1 V_220 = F_4 ( V_209 -> V_216 , 16 , 31 ) ;
T_1 V_221 = F_4 ( V_209 -> V_216 , 0 , 15 ) ;
T_1 V_90 = F_4 ( V_209 -> V_216 , 0 , 3 ) ;
T_1 V_222 = F_4 ( V_209 -> V_216 , 4 , 6 ) ;
long V_126 , V_223 ;
T_2 V_127 , V_125 ;
int V_46 , V_65 ;
char * V_128 = NULL ;
if ( V_23 -> V_31 . type == V_55 )
V_218 = true ;
else
V_218 = F_4 ( V_209 -> V_216 , 56 , 56 ) ;
if ( V_217 ) {
if ( V_213 ) {
type = L_65 ;
V_211 = V_224 ;
} else {
type = L_66 ;
V_211 = V_225 ;
}
} else {
type = L_67 ;
V_211 = V_226 ;
}
if ( ! ( ( V_221 & 0xef80 ) == 0x80 ) ) {
V_212 = L_68 ;
} else {
switch ( V_222 ) {
case 0 :
V_212 = L_69 ;
break;
case 1 :
V_212 = L_70 ;
break;
case 2 :
V_212 = L_71 ;
break;
case 3 :
V_212 = L_72 ;
break;
case 4 :
V_212 = L_73 ;
break;
default:
V_212 = L_74 ;
break;
}
}
if ( ! F_4 ( V_209 -> V_216 , 58 , 58 ) )
return;
V_46 = F_69 ( V_62 , V_209 -> V_124 , & V_125 ,
& V_126 , & V_127 , & V_128 , V_129 ) ;
if ( V_46 < 0 )
goto V_227;
V_130 = F_68 ( V_125 ) ;
if ( ! V_130 ) {
strcpy ( V_129 , L_75 ) ;
goto V_227;
}
V_62 = V_130 ;
V_23 = V_62 -> V_63 ;
V_223 = F_88 ( & V_126 , V_84 ) ;
if ( V_127 < 4 )
V_65 = 0 ;
else if ( V_127 < 8 )
V_65 = 1 ;
else
V_65 = 2 ;
if ( ! V_23 -> V_81 && ! V_23 -> V_79 && ! V_23 -> V_83 )
V_90 = V_223 ;
snprintf ( V_129 , sizeof( V_129 ) ,
L_76 ,
V_215 ? L_77 : L_39 ,
( V_217 && V_218 ) ? L_78 : L_39 ,
V_128 ,
V_220 , V_221 ,
V_125 ,
V_126 ,
V_127 ) ;
F_7 ( 0 , L_79 , V_129 ) ;
if ( V_90 == V_228 )
V_90 = - 1 ;
F_89 ( V_211 , V_62 , V_219 ,
V_209 -> V_124 >> V_229 , V_209 -> V_124 & ~ V_230 , 0 ,
V_90 , V_65 , - 1 ,
V_212 , V_129 ) ;
return;
V_227:
F_89 ( V_211 , V_62 , V_219 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_129 , L_39 ) ;
}
static void F_90 ( struct V_61 * V_62 )
{
struct V_22 * V_23 = V_62 -> V_63 ;
int V_66 ;
unsigned V_231 = 0 ;
struct V_208 * V_209 ;
F_91 () ;
V_231 = ( V_23 -> V_232 + V_233 - V_23 -> V_234 )
% V_233 ;
if ( ! V_231 )
return;
V_209 = V_23 -> V_235 ;
if ( V_23 -> V_234 + V_231 > V_233 ) {
unsigned V_236 = V_233 - V_23 -> V_234 ;
memcpy ( V_209 , & V_23 -> V_237 [ V_23 -> V_234 ] , sizeof( * V_209 ) * V_236 ) ;
F_92 () ;
V_23 -> V_234 = 0 ;
V_231 -= V_236 ;
V_209 += V_236 ;
}
memcpy ( V_209 , & V_23 -> V_237 [ V_23 -> V_234 ] , sizeof( * V_209 ) * V_231 ) ;
F_92 () ;
V_23 -> V_234 += V_231 ;
F_91 () ;
if ( V_23 -> V_238 ) {
F_40 ( V_59 , L_80 ,
V_23 -> V_238 ) ;
F_92 () ;
V_23 -> V_238 = 0 ;
}
for ( V_66 = 0 ; V_66 < V_231 ; V_66 ++ )
F_87 ( V_62 , & V_23 -> V_235 [ V_66 ] ) ;
}
static int F_93 ( struct V_239 * V_240 , unsigned long V_241 ,
void * V_242 )
{
struct V_208 * V_208 = (struct V_208 * ) V_242 ;
struct V_61 * V_62 ;
struct V_22 * V_23 ;
char * type ;
if ( F_94 () == V_243 )
return V_244 ;
V_62 = F_68 ( V_208 -> V_245 ) ;
if ( ! V_62 )
return V_246 ;
V_23 = V_62 -> V_63 ;
if ( ( V_208 -> V_216 & 0xefff ) >> 7 != 1 )
return V_244 ;
if ( V_208 -> V_214 & V_247 )
type = L_81 ;
else
type = L_82 ;
F_95 ( V_62 , V_160 , L_83 ) ;
F_95 ( V_62 , V_160 , L_84
L_85 , V_208 -> V_248 , type ,
V_208 -> V_214 , V_208 -> V_249 , V_208 -> V_216 ) ;
F_95 ( V_62 , V_160 , L_86 , V_208 -> V_250 ) ;
F_95 ( V_62 , V_160 , L_87 , V_208 -> V_124 ) ;
F_95 ( V_62 , V_160 , L_88 , V_208 -> V_251 ) ;
F_95 ( V_62 , V_160 , L_89
L_90 , V_208 -> V_252 , V_208 -> V_253 ,
V_208 -> time , V_208 -> V_245 , V_208 -> V_254 ) ;
F_91 () ;
if ( ( V_23 -> V_232 + 1 ) % V_233 == V_23 -> V_234 ) {
F_92 () ;
V_23 -> V_238 ++ ;
return V_244 ;
}
memcpy ( & V_23 -> V_237 [ V_23 -> V_232 ] , V_208 , sizeof( * V_208 ) ) ;
F_92 () ;
V_23 -> V_232 = ( V_23 -> V_232 + 1 ) % V_233 ;
if ( V_208 -> V_214 & 1 )
F_90 ( V_62 ) ;
return V_255 ;
}
static void F_96 ( struct V_14 * V_14 )
{
struct V_61 * V_62 = V_14 -> V_62 ;
struct V_22 * V_23 ;
if ( F_79 ( ! V_62 || ! V_62 -> V_63 ) ) {
F_7 ( 0 , L_91 , & V_14 -> V_18 [ 0 ] -> V_256 ) ;
F_40 ( V_59 , L_92 ) ;
return;
}
V_23 = V_62 -> V_63 ;
F_7 ( 0 , L_93 ,
V_62 , & V_14 -> V_18 [ 0 ] -> V_256 ) ;
F_97 ( V_62 -> V_18 ) ;
F_7 ( 1 , L_94 , V_62 -> V_257 ) ;
F_16 ( V_62 -> V_257 ) ;
F_98 ( V_62 ) ;
V_14 -> V_62 = NULL ;
}
static int F_99 ( struct V_14 * V_14 , enum type type )
{
struct V_61 * V_62 ;
struct V_258 V_86 [ 2 ] ;
struct V_22 * V_23 ;
struct V_50 * V_18 = V_14 -> V_18 [ 0 ] ;
int V_46 ;
V_46 = F_39 ( V_14 -> V_15 , type ) ;
if ( F_79 ( V_46 < 0 ) )
return V_46 ;
V_86 [ 0 ] . type = V_259 ;
V_86 [ 0 ] . V_70 = V_84 ;
V_86 [ 0 ] . V_260 = false ;
V_86 [ 1 ] . type = V_261 ;
V_86 [ 1 ] . V_70 = V_262 ;
V_86 [ 1 ] . V_260 = true ;
V_62 = F_100 ( V_14 -> V_76 , F_47 ( V_86 ) , V_86 ,
sizeof( * V_23 ) ) ;
if ( F_79 ( ! V_62 ) )
return - V_164 ;
F_7 ( 0 , L_93 ,
V_62 , & V_18 -> V_256 ) ;
V_23 = V_62 -> V_63 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_14 = V_14 ;
V_14 -> V_62 = V_62 ;
V_62 -> V_263 = V_264 ;
V_62 -> V_265 = V_266 ;
V_62 -> V_267 = V_266 ;
V_62 -> V_268 = L_95 ;
V_62 -> V_269 = V_270 ;
V_62 -> V_271 = F_101 ( V_18 ) ;
V_62 -> V_272 = NULL ;
V_62 -> V_273 = F_90 ;
V_23 -> V_31 . type = type ;
switch ( type ) {
case V_55 :
V_23 -> V_31 . V_32 = V_274 ;
V_23 -> V_31 . V_110 = F_25 ;
V_23 -> V_31 . V_112 = F_26 ;
V_23 -> V_31 . V_115 = V_275 ;
V_23 -> V_31 . F_28 = F_28 ;
V_23 -> V_31 . F_30 = F_30 ;
V_23 -> V_31 . F_27 = F_27 ;
V_23 -> V_31 . V_113 = F_47 ( V_275 ) ;
V_23 -> V_31 . V_116 = V_276 ;
V_23 -> V_31 . V_140 = F_47 ( V_276 ) ;
V_23 -> V_31 . V_2 = V_277 ;
V_62 -> V_257 = F_102 ( V_17 , L_96 , V_62 -> V_278 ) ;
V_46 = F_84 ( V_62 , V_14 ) ;
if ( F_79 ( V_46 < 0 ) )
goto V_279;
break;
case V_147 :
V_23 -> V_31 . V_32 = V_280 ;
V_23 -> V_31 . V_110 = F_20 ;
V_23 -> V_31 . V_112 = F_23 ;
V_23 -> V_31 . V_115 = V_281 ;
V_23 -> V_31 . F_28 = F_28 ;
V_23 -> V_31 . F_30 = F_30 ;
V_23 -> V_31 . F_27 = F_27 ;
V_23 -> V_31 . V_113 = F_47 ( V_281 ) ;
V_23 -> V_31 . V_116 = V_282 ;
V_23 -> V_31 . V_140 = F_47 ( V_282 ) ;
V_23 -> V_31 . V_2 = V_283 ;
V_62 -> V_257 = F_102 ( V_17 , L_97 , V_62 -> V_278 ) ;
V_46 = F_83 ( V_62 , V_14 ) ;
if ( F_79 ( V_46 < 0 ) )
goto V_279;
break;
case V_10 :
V_23 -> V_31 . V_110 = F_32 ;
V_23 -> V_31 . V_112 = F_33 ;
V_23 -> V_31 . V_115 = V_275 ;
V_23 -> V_31 . F_28 = F_29 ;
V_23 -> V_31 . F_30 = F_31 ;
V_23 -> V_31 . F_27 = F_34 ;
V_23 -> V_31 . V_113 = F_47 ( V_275 ) ;
V_23 -> V_31 . V_116 = V_276 ;
V_23 -> V_31 . V_140 = F_47 ( V_276 ) ;
V_23 -> V_31 . V_2 = V_277 ;
V_62 -> V_257 = F_102 ( V_17 , L_98 , V_62 -> V_278 ) ;
V_46 = F_86 ( V_62 , V_14 ) ;
if ( F_79 ( V_46 < 0 ) )
goto V_279;
break;
}
F_42 ( V_62 ) ;
F_51 ( V_62 ) ;
V_62 -> V_18 = & V_18 -> V_256 ;
if ( F_79 ( F_103 ( V_62 ) ) ) {
F_7 ( 0 , L_99 ) ;
V_46 = - V_11 ;
goto V_279;
}
return 0 ;
V_279:
F_16 ( V_62 -> V_257 ) ;
F_98 ( V_62 ) ;
V_14 -> V_62 = NULL ;
return V_46 ;
}
static int F_104 ( struct V_50 * V_18 , const struct V_284 * V_51 )
{
int V_46 = - V_60 ;
T_2 V_76 , V_155 = 0 ;
struct V_14 * V_14 ;
enum type type = V_147 ;
F_105 ( & V_285 ) ;
if ( F_79 ( V_286 >= 1 ) ) {
F_106 ( & V_285 ) ;
return - V_60 ;
}
V_286 ++ ;
switch ( V_18 -> V_165 ) {
case V_56 :
V_46 = F_82 ( & V_155 , V_287 ) ;
type = V_55 ;
break;
case V_58 :
V_46 = F_82 ( & V_155 , V_288 ) ;
type = V_147 ;
break;
case V_197 :
V_46 = F_82 ( & V_155 , V_289 ) ;
type = V_10 ;
break;
}
if ( F_79 ( V_46 < 0 ) )
goto V_279;
V_76 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_7 ( 0 , L_100 ,
V_76 , V_76 + 1 , V_155 ) ;
V_14 -> V_76 = V_76 ++ ;
V_46 = F_99 ( V_14 , type ) ;
if ( F_79 ( V_46 < 0 ) )
goto V_290;
}
F_40 ( V_163 , L_101 ) ;
F_106 ( & V_285 ) ;
return 0 ;
V_290:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_96 ( V_14 ) ;
F_76 () ;
V_279:
F_106 ( & V_285 ) ;
return V_46 ;
}
static void F_107 ( struct V_50 * V_18 )
{
struct V_14 * V_14 ;
F_7 ( 0 , L_54 ) ;
F_105 ( & V_285 ) ;
if ( F_79 ( ! V_286 ) ) {
F_106 ( & V_285 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_96 ( V_14 ) ;
F_76 () ;
V_286 -- ;
F_106 ( & V_285 ) ;
}
static int T_4 F_108 ( void )
{
int V_291 ;
F_7 ( 2 , L_54 ) ;
F_109 () ;
V_291 = F_110 ( & V_292 ) ;
if ( V_291 >= 0 ) {
F_111 ( & V_293 ) ;
if ( F_94 () == V_243 )
F_40 ( V_294 , L_102 ) ;
return 0 ;
}
F_40 ( V_59 , L_103 ,
V_291 ) ;
return V_291 ;
}
static void T_5 F_112 ( void )
{
F_7 ( 2 , L_54 ) ;
F_113 ( & V_292 ) ;
F_114 ( & V_293 ) ;
}
