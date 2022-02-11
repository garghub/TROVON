static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_2 -> V_4 -> V_7 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
}
static inline int F_3 ( T_1 V_3 , struct V_9 * V_10 )
{
return ( ( ( ( V_3 & 0xF800 ) >> V_10 -> V_11 . V_12 ) * 77 +
( ( V_3 & 0x07E0 ) >> ( V_10 -> V_13 . V_12 + 1 ) ) * 151 +
( ( V_3 & 0x1F ) >> V_10 -> V_14 . V_12 ) * 28 ) >> 8 >> 1 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_15 ,
T_1 * V_3 )
{
struct V_9 * V_10 = & V_2 -> V_16 -> V_10 ;
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
int V_19 ;
T_1 V_20 ;
if ( V_15 & 7 ) {
F_5 ( V_18 , L_1 ,
V_15 ) ;
return - V_21 ;
}
for ( V_19 = 0 ; V_19 < ( V_15 >> 2 ) ; V_19 ++ ) {
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_20 = ( F_3 ( V_3 [ 4 * V_19 ] , V_10 ) & 0x000F ) ;
V_20 |= ( F_3 ( V_3 [ 4 * V_19 + 1 ] , V_10 ) << 4 ) & 0x00F0 ;
V_20 |= ( F_3 ( V_3 [ 4 * V_19 + 2 ] , V_10 ) << 8 ) & 0x0F00 ;
V_20 |= ( F_3 ( V_3 [ 4 * V_19 + 3 ] , V_10 ) << 12 ) & 0xF000 ;
V_2 -> V_4 -> V_7 ( V_2 , V_20 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_15 ,
T_1 * V_3 )
{
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
int V_19 ;
T_1 V_20 ;
if ( V_15 & 3 ) {
F_5 ( V_18 , L_2 ,
V_15 ) ;
return - V_21 ;
}
for ( V_19 = 0 ; V_19 < ( V_15 >> 1 ) ; V_19 ++ ) {
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_20 = ( V_3 [ 2 * V_19 ] & 0xF0 ) >> 4 ;
V_20 |= ( V_3 [ 2 * V_19 ] & 0xF000 ) >> 8 ;
V_20 |= ( V_3 [ 2 * V_19 + 1 ] & 0xF0 ) << 4 ;
V_20 |= ( V_3 [ 2 * V_19 + 1 ] & 0xF000 ) ;
V_2 -> V_4 -> V_7 ( V_2 , V_20 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_15 ,
T_1 * V_3 )
{
struct V_22 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
if ( V_16 -> V_10 . V_23 == 8 && V_16 -> V_10 . V_24 )
F_6 ( V_2 , V_15 , V_3 ) ;
else if ( V_16 -> V_10 . V_23 == 16 )
F_4 ( V_2 , V_15 , V_3 ) ;
else
F_5 ( V_18 , L_3 ,
V_16 -> V_10 . V_23 , V_16 -> V_10 . V_24 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 -> V_5 ( V_2 , V_25 , 0 ) ;
V_3 = V_2 -> V_4 -> V_26 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_25 , 1 ) ;
return V_3 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 0 ) ;
F_2 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 1 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_28 ,
int V_29 , T_1 * V_30 )
{
int V_19 ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 0 ) ;
F_2 ( V_2 , V_28 ) ;
for ( V_19 = 0 ; V_19 < V_29 ; V_19 ++ )
F_1 ( V_2 , V_30 [ V_19 ] ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 1 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_31 ;
V_31 = V_2 -> V_4 -> V_32 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_3 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_28 ,
int V_29 , T_1 * V_30 )
{
int V_31 ;
V_31 = V_2 -> V_4 -> V_32 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_10 ( V_2 , V_28 , V_29 , V_30 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_28 ,
int V_29 , T_1 * V_30 )
{
int V_19 , V_31 ;
V_31 = V_2 -> V_4 -> V_32 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 0 ) ;
F_2 ( V_2 , V_28 ) ;
for ( V_19 = 0 ; V_19 < V_29 ; V_19 ++ )
V_30 [ V_19 ] = F_8 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 1 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_28 ,
int V_29 , T_1 * V_30 , int V_15 , T_1 * V_3 )
{
int V_19 ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 0 ) ;
F_2 ( V_2 , V_28 ) ;
for ( V_19 = 0 ; V_19 < V_29 ; V_19 ++ )
F_1 ( V_2 , V_30 [ V_19 ] ) ;
F_7 ( V_2 , V_15 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_27 , 1 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_28 ,
int V_29 , T_1 * V_30 , int V_15 , T_1 * V_3 )
{
int V_31 ;
V_31 = V_2 -> V_4 -> V_32 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_14 ( V_2 , V_28 , V_29 , V_30 , V_15 , V_3 ) ;
return 0 ;
}
static void F_16 ( struct V_22 * V_16 )
{
F_17 ( V_16 -> V_17 ) ;
}
static void F_18 ( struct V_22 * V_16 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_16 -> V_36 ;
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_37 = V_16 -> V_38 . V_37 ;
T_1 V_39 = V_16 -> V_10 . V_39 ;
T_1 y1 = 0 , V_40 = 0 ;
int V_41 = - 1 ;
struct V_42 * V_43 ;
int V_44 ;
int V_45 ;
if ( ! F_19 ( V_34 ) )
F_20 ( V_16 -> V_17 ) ;
else
F_21 ( V_16 -> V_17 ) ;
if ( V_2 -> V_46 ( V_2 ) ) {
V_2 -> V_47 ( V_2 ) ;
goto V_48;
}
V_44 = F_22 ( V_49 , V_37 ) ;
V_45 = V_2 -> V_50 / V_44 ;
if ( V_45 < 1 )
V_45 = 1 ;
F_23 (cur, &fbdefio->pagelist, lru) {
if ( V_41 < 0 ) {
y1 = ( V_43 -> V_51 << V_52 ) / V_37 ;
V_40 = V_44 ;
} else if ( ( V_43 -> V_51 - V_41 ) <= V_45 ) {
V_40 += V_44 * ( V_43 -> V_51 - V_41 ) ;
} else {
V_2 -> V_53 ( V_2 , y1 , y1 + V_40 ) ;
y1 = ( V_43 -> V_51 << V_52 ) / V_37 ;
V_40 = V_44 ;
}
V_41 = V_43 -> V_51 ;
}
if ( V_40 >= V_39 )
V_2 -> V_47 ( V_2 ) ;
else
V_2 -> V_53 ( V_2 , y1 , F_24 ( ( T_1 ) ( y1 + V_40 ) , V_39 ) ) ;
V_48:
F_25 ( V_16 -> V_17 ) ;
F_26 ( V_16 -> V_17 ) ;
}
static T_2 F_27 ( struct V_22 * V_16 , const char T_3 * V_54 ,
T_4 V_55 , T_5 * V_56 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_57 = * V_56 ;
void * V_58 ;
int V_59 = 0 ;
unsigned long V_60 ;
if ( V_16 -> V_61 != V_62 )
return - V_63 ;
V_60 = V_16 -> V_38 . V_64 ;
if ( V_57 > V_60 )
return - V_65 ;
if ( V_55 > V_60 ) {
V_59 = - V_65 ;
V_55 = V_60 ;
}
if ( V_55 + V_57 > V_60 ) {
if ( ! V_59 )
V_59 = - V_66 ;
V_55 = V_60 - V_57 ;
}
V_58 = ( void * ) ( V_16 -> V_67 + V_57 ) ;
if ( F_28 ( V_58 , V_54 , V_55 ) )
V_59 = - V_68 ;
if ( ! V_59 )
* V_56 += V_55 ;
V_2 -> V_47 ( V_2 ) ;
return ( V_59 ) ? V_59 : V_55 ;
}
static void F_29 ( struct V_22 * V_16 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
F_30 ( V_16 , V_70 ) ;
V_2 -> V_47 ( V_2 ) ;
}
static void F_31 ( struct V_22 * V_16 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
F_32 ( V_16 , V_72 ) ;
V_2 -> V_47 ( V_2 ) ;
}
static void F_33 ( struct V_22 * V_16 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
F_34 ( V_16 , V_74 ) ;
V_2 -> V_47 ( V_2 ) ;
}
static int F_35 ( struct V_9 * V_10 ,
struct V_22 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_75 * V_76 = & V_77 [ V_2 -> V_78 ] ;
int V_15 ;
if ( V_10 -> V_23 == 8 && V_10 -> V_24 == 1 ) {
V_10 -> V_11 . V_79 = 8 ;
V_10 -> V_11 . V_12 = 0 ;
V_10 -> V_11 . V_80 = 0 ;
V_10 -> V_13 . V_79 = 8 ;
V_10 -> V_13 . V_12 = 0 ;
V_10 -> V_13 . V_80 = 0 ;
V_10 -> V_14 . V_79 = 8 ;
V_10 -> V_14 . V_12 = 0 ;
V_10 -> V_14 . V_80 = 0 ;
V_10 -> V_81 . V_79 = 0 ;
V_10 -> V_81 . V_12 = 0 ;
V_10 -> V_81 . V_80 = 0 ;
} else if ( V_10 -> V_23 == 16 ) {
V_10 -> V_11 . V_79 = 5 ;
V_10 -> V_11 . V_12 = 11 ;
V_10 -> V_11 . V_80 = 0 ;
V_10 -> V_13 . V_79 = 6 ;
V_10 -> V_13 . V_12 = 5 ;
V_10 -> V_13 . V_80 = 0 ;
V_10 -> V_14 . V_79 = 5 ;
V_10 -> V_14 . V_12 = 0 ;
V_10 -> V_14 . V_80 = 0 ;
V_10 -> V_81 . V_79 = 0 ;
V_10 -> V_81 . V_12 = 0 ;
V_10 -> V_81 . V_80 = 0 ;
} else {
F_36 ( V_18 , L_4 ,
V_16 -> V_10 . V_23 , V_16 -> V_10 . V_24 ) ;
return - V_21 ;
}
switch ( V_10 -> V_82 ) {
case V_83 :
case V_84 :
V_10 -> V_85 = V_76 -> V_86 ;
V_10 -> V_39 = V_76 -> V_40 ;
break;
case V_87 :
case V_88 :
V_10 -> V_85 = V_76 -> V_40 ;
V_10 -> V_39 = V_76 -> V_86 ;
break;
default:
F_37 ( V_18 , L_5 ) ;
return - V_21 ;
}
V_10 -> V_89 = V_10 -> V_85 ;
V_10 -> V_90 = V_10 -> V_39 ;
V_15 = V_10 -> V_89 * V_10 -> V_90 * V_10 -> V_23 / 8 ;
if ( V_15 > V_16 -> V_38 . V_64 ) {
F_5 ( V_18 , L_6 ,
V_15 >> 10 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_38 ( struct V_22 * V_16 )
{
struct V_92 * V_38 = & V_16 -> V_38 ;
struct V_9 * V_10 = & V_16 -> V_10 ;
V_38 -> V_37 = V_10 -> V_89 * V_10 -> V_23 / 8 ;
V_38 -> type = V_93 ;
V_38 -> V_94 = V_95 ;
V_38 -> V_96 = ( V_10 -> V_24 ) ? V_97
: V_98 ;
V_38 -> V_99 = 0 ;
V_38 -> V_100 = 0 ;
V_38 -> V_101 = 0 ;
return 0 ;
}
static int F_39 ( struct V_22 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
V_2 -> V_102 = V_16 -> V_10 . V_82 ;
F_38 ( V_16 ) ;
V_2 -> V_103 ( V_2 ) ;
V_2 -> V_4 -> V_32 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
T_1 V_3 [ 4 ] ;
int V_104 ;
F_21 ( V_18 ) ;
F_41 ( & ( V_2 -> V_105 ) ) ;
F_13 ( V_2 , V_106 , 4 , V_3 ) ;
F_42 ( & ( V_2 -> V_105 ) ) ;
F_25 ( V_18 ) ;
F_26 ( V_18 ) ;
V_104 = ( ( V_3 [ 0 ] & V_107 ) >> 1 ) ;
if ( V_104 >= 201 )
return ( 255 - V_104 + 1 ) * ( - 1 ) ;
else
return V_104 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
T_1 V_3 [ 4 ] ;
F_21 ( V_18 ) ;
F_41 ( & ( V_2 -> V_105 ) ) ;
F_13 ( V_2 , V_106 , 4 , V_3 ) ;
F_42 ( & ( V_2 -> V_105 ) ) ;
V_2 -> V_108 = V_3 [ 1 ] & V_107 ;
V_2 -> V_109 = F_44 ( V_3 [ 2 ] ) ;
V_2 -> V_110 = F_45 ( V_3 [ 2 ] ) ;
V_2 -> V_111 = F_46 ( V_3 [ 2 ] ) ;
V_2 -> V_112 = F_47 ( V_3 [ 3 ] ) ;
V_2 -> V_113 = F_48 ( V_3 [ 3 ] ) ;
F_37 ( V_18 , L_7 ,
V_2 -> V_109 , V_2 -> V_110 , V_2 -> V_111 ,
V_2 -> V_108 , V_2 -> V_112 , V_2 -> V_113 ) ;
F_25 ( V_18 ) ;
F_26 ( V_18 ) ;
}
static T_2 F_49 ( struct V_17 * V_18 ,
struct V_114 * V_115 , char * V_54 )
{
struct V_22 * V_16 = F_50 ( V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
return sprintf ( V_54 , L_8 , V_2 -> V_116 ) ;
}
static T_2 F_51 ( struct V_17 * V_18 ,
struct V_114 * V_115 ,
const char * V_54 , T_4 V_55 )
{
struct V_22 * V_16 = F_50 ( V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_117 , V_31 ;
V_31 = F_52 ( V_54 , 10 , & V_117 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_116 = V_117 ;
if ( V_2 -> V_118 > 1 && V_117 < V_2 -> V_118 )
V_2 -> V_47 ( V_2 ) ;
return V_55 ;
}
static T_2 F_53 ( struct V_17 * V_18 , struct V_114 * V_115 ,
char * V_54 )
{
struct V_22 * V_16 = F_50 ( V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
return sprintf ( V_54 , L_8 , V_2 -> V_119 ) ;
}
static T_2 F_54 ( struct V_17 * V_18 , struct V_114 * V_115 ,
const char * V_54 , T_4 V_55 )
{
struct V_22 * V_16 = F_50 ( V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_119 , V_31 ;
V_31 = F_52 ( V_54 , 10 , & V_119 ) ;
if ( V_31 )
return V_31 ;
if ( V_119 > 0 )
V_2 -> V_119 = 1 ;
else
V_2 -> V_119 = 0 ;
return V_55 ;
}
static T_2 F_55 ( struct V_17 * V_18 , struct V_114 * V_115 ,
char * V_54 )
{
struct V_22 * V_16 = F_50 ( V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_104 ;
V_104 = F_40 ( V_2 ) ;
return sprintf ( V_54 , L_8 , V_104 ) ;
}
static int F_56 ( struct V_1 * V_2 , bool V_120 )
{
struct V_121 * V_4 = V_2 -> V_4 ;
int V_31 ;
if ( V_120 ) {
V_31 = F_57 ( V_2 -> V_122 ) ;
if ( V_31 )
return V_31 ;
F_58 ( 200 ) ;
F_59 ( V_4 -> V_123 , 1 ) ;
F_59 ( V_4 -> V_124 , 1 ) ;
F_58 ( 200 ) ;
} else {
F_60 ( V_2 -> V_122 ) ;
F_59 ( V_4 -> V_123 , 0 ) ;
F_59 ( V_4 -> V_124 , 0 ) ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_16 -> V_17 ;
F_56 ( V_2 , 0 ) ;
F_58 ( 100 ) ;
F_56 ( V_2 , 1 ) ;
F_62 ( V_18 ) ;
V_2 -> V_125 = 0 ;
V_2 -> V_103 ( V_2 ) ;
V_2 -> V_4 -> V_32 ( V_2 ) ;
}
static int T_6 F_63 ( struct V_17 * V_18 )
{
struct V_126 * V_127 = F_64 ( V_18 ) ;
struct V_22 * V_16 = F_65 ( V_127 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_121 * V_4 = V_2 -> V_4 ;
T_1 V_128 ;
F_41 ( & ( V_2 -> V_105 ) ) ;
if ( V_2 -> V_125 ) {
F_36 ( V_18 , L_9 ) ;
F_42 ( & ( V_2 -> V_105 ) ) ;
return 0 ;
}
if ( V_4 -> V_129 & V_130 ) {
F_37 ( V_18 , L_10 ) ;
goto V_131;
} else if ( V_4 -> V_129 & V_132 ) {
F_37 ( V_18 , L_11 ) ;
V_128 = 0 ;
F_12 ( V_2 , V_133 , 1 ,
& V_128 ) ;
} else {
F_37 ( V_18 , L_12 ) ;
F_11 ( V_2 , V_133 ) ;
}
F_58 ( 64 ) ;
V_131:
V_2 -> V_125 = 1 ;
return 0 ;
}
static int T_6 F_66 ( struct V_17 * V_18 )
{
struct V_126 * V_127 = F_64 ( V_18 ) ;
struct V_22 * V_16 = F_65 ( V_127 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_121 * V_4 = V_2 -> V_4 ;
if ( ! V_2 -> V_125 ) {
F_36 ( V_18 , L_13 ) ;
return 0 ;
}
if ( V_4 -> V_129 & V_130 ) {
F_37 ( V_18 , L_14 ) ;
} else {
F_37 ( V_18 , L_15 ) ;
F_9 ( V_2 , V_134 ) ;
F_58 ( 160 ) ;
V_4 -> V_32 ( V_2 ) ;
}
V_2 -> V_125 = 0 ;
F_42 ( & ( V_2 -> V_105 ) ) ;
return 0 ;
}
static int T_6 F_67 ( struct V_17 * V_18 )
{
struct V_126 * V_127 = F_64 ( V_18 ) ;
struct V_22 * V_16 = F_65 ( V_127 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_121 * V_4 = V_2 -> V_4 ;
int V_31 ;
F_37 ( V_18 , L_16 ) ;
if ( V_4 -> V_129 & V_130 ) {
F_37 ( V_18 , L_17 ) ;
F_56 ( V_2 , 0 ) ;
} else {
F_37 ( V_18 , L_18 ) ;
if ( ! F_68 ( V_18 ) ) {
V_31 = F_63 ( V_18 ) ;
if ( V_31 < 0 ) {
F_5 ( V_18 , L_19 ,
V_31 ) ;
return V_31 ;
}
V_2 -> V_135 = 1 ;
}
F_69 ( V_4 -> V_124 , 0 ) ;
}
F_58 ( 100 ) ;
return 0 ;
}
static int T_6 F_70 ( struct V_17 * V_18 )
{
struct V_126 * V_127 = F_64 ( V_18 ) ;
struct V_22 * V_16 = F_65 ( V_127 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_121 * V_4 = V_2 -> V_4 ;
F_37 ( V_18 , L_20 ) ;
if ( V_4 -> V_129 & V_130 ) {
F_37 ( V_18 , L_21 ) ;
F_56 ( V_2 , 1 ) ;
V_2 -> V_103 ( V_2 ) ;
} else {
F_37 ( V_18 , L_22 ) ;
F_69 ( V_4 -> V_124 , 1 ) ;
F_58 ( 100 ) ;
F_66 ( V_18 ) ;
V_2 -> V_103 ( V_2 ) ;
if ( ! V_2 -> V_135 )
F_63 ( V_18 ) ;
else
V_2 -> V_135 = 0 ;
}
return 0 ;
}
int F_71 ( struct V_126 * V_127 ,
struct V_136 * V_103 )
{
struct V_121 * V_4 = V_103 -> V_4 ;
struct V_1 * V_2 ;
struct V_22 * V_16 ;
struct V_75 * V_76 ;
int V_137 , V_31 ;
unsigned char * V_138 ;
if ( ! V_4 -> V_103 || ! V_4 -> V_139 || ! V_4 -> V_32
|| ! V_4 -> V_5 || ! V_4 -> V_7 || ! V_4 -> V_26
|| ! V_4 -> V_140 )
return - V_21 ;
V_16 = F_72 ( sizeof( struct V_1 ) , & V_127 -> V_18 ) ;
if ( ! V_16 )
return - V_91 ;
V_2 = V_16 -> V_2 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_141 = F_61 ;
V_2 -> V_53 = V_103 -> V_53 ;
V_2 -> V_47 = V_103 -> V_47 ;
V_2 -> V_46 = V_103 -> V_46 ;
V_2 -> V_103 = V_103 -> V_103 ;
V_2 -> V_142 = 0 ;
V_2 -> V_116 = - 1 ;
V_2 -> V_118 = - 1 ;
V_2 -> V_119 = 0 ;
V_2 -> V_122 = F_73 ( V_16 -> V_17 , L_23 ) ;
if ( F_74 ( V_2 -> V_122 ) ) {
V_31 = F_75 ( V_2 -> V_122 ) ;
F_5 ( V_16 -> V_17 , L_24 , V_31 ) ;
goto V_143;
}
V_31 = V_4 -> V_103 ( V_2 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_25 , V_31 ) ;
goto V_144;
}
V_31 = F_76 ( V_4 -> V_124 , L_26 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_27 ,
V_31 ) ;
goto V_145;
}
V_31 = F_69 ( V_4 -> V_124 , 0 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_28 , V_31 ) ;
goto V_146;
}
V_31 = F_76 ( V_4 -> V_123 , L_29 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_30 ,
V_31 ) ;
goto V_146;
}
V_31 = F_69 ( V_4 -> V_123 , 0 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_31 , V_31 ) ;
goto V_147;
}
V_31 = F_56 ( V_2 , 1 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_32 ,
V_31 ) ;
goto V_147;
}
F_77 ( & V_2 -> V_105 ) ;
F_78 ( & V_2 -> V_148 ) ;
V_31 = V_2 -> V_4 -> V_140 ( V_2 -> V_16 ) ;
if ( V_31 ) {
F_5 ( V_16 -> V_17 , L_33 , V_31 ) ;
goto V_149;
}
V_2 -> V_4 -> V_32 ( V_2 ) ;
F_79 ( V_16 -> V_38 . V_150 , V_103 -> V_150 , 16 ) ;
V_16 -> V_10 . V_23 = 8 ;
V_16 -> V_10 . V_24 = 1 ;
V_76 = & V_77 [ V_4 -> V_78 ] ;
V_2 -> V_78 = V_4 -> V_78 ;
V_2 -> V_102 = 0 ;
V_137 = F_80 ( ( V_76 -> V_86 * V_76 -> V_40 ) * 2 , V_49 ) ;
V_138 = F_81 ( V_137 ) ;
if ( ! V_138 ) {
V_31 = - V_91 ;
goto V_149;
}
memset ( V_138 , 0 , V_137 ) ;
V_16 -> V_67 = ( char * ) V_138 ;
V_16 -> V_38 . V_64 = V_137 ;
V_16 -> V_151 = V_152 | V_153 ;
V_16 -> V_154 = & V_155 ;
V_31 = F_35 ( & V_16 -> V_10 , V_16 ) ;
if ( V_31 )
goto V_156;
F_38 ( V_16 ) ;
V_16 -> V_36 = F_82 ( V_16 -> V_17 ,
sizeof( struct V_35 ) ,
V_157 ) ;
if ( ! V_16 -> V_36 ) {
F_5 ( V_16 -> V_17 , L_34 ) ;
V_31 = - V_91 ;
goto V_156;
}
F_37 ( V_16 -> V_17 , L_35 , V_4 -> V_158 ) ;
V_16 -> V_36 -> V_159 = V_160 / V_4 -> V_158 ;
V_16 -> V_36 -> V_161 = F_16 ,
V_16 -> V_36 -> V_162 = F_18 ,
F_83 ( V_16 ) ;
V_31 = F_84 ( & V_16 -> V_163 , 256 , 0 ) ;
if ( V_31 < 0 ) {
F_5 ( V_16 -> V_17 , L_36 ) ;
goto V_164;
}
V_2 -> V_50 = 100 ;
V_2 -> V_103 ( V_2 ) ;
F_43 ( V_2 ) ;
F_85 ( V_127 , V_16 ) ;
V_31 = F_86 ( V_16 ) ;
if ( V_31 < 0 )
goto V_165;
V_31 = F_87 ( & V_16 -> V_17 -> V_166 , & V_167 ) ;
if ( V_31 )
goto V_168;
F_88 ( V_16 -> V_17 , L_37 ,
V_16 -> V_169 , V_16 -> V_10 . V_85 , V_16 -> V_10 . V_39 ,
V_137 >> 10 ) ;
V_2 -> V_170 = ( V_4 -> V_129 & V_130 )
? 1000 : 200 ;
F_62 ( V_16 -> V_17 ) ;
F_89 ( V_16 -> V_17 ) ;
F_90 ( V_16 -> V_17 , V_2 -> V_170 ) ;
F_91 ( V_16 -> V_17 ) ;
return 0 ;
V_168:
F_92 ( V_16 ) ;
V_165:
F_93 ( & V_16 -> V_163 ) ;
V_164:
F_94 ( V_16 ) ;
V_156:
F_95 ( ( void * ) V_16 -> V_67 ) ;
V_149:
F_56 ( V_2 , 0 ) ;
V_147:
F_96 ( V_4 -> V_123 ) ;
V_146:
F_96 ( V_4 -> V_124 ) ;
V_145:
V_4 -> V_139 ( V_2 ) ;
V_144:
F_97 ( V_2 -> V_122 ) ;
V_143:
F_98 ( V_16 ) ;
return V_31 ;
}
int F_99 ( struct V_126 * V_127 )
{
struct V_22 * V_16 = F_65 ( V_127 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_121 * V_4 = V_2 -> V_4 ;
F_100 ( V_16 -> V_17 ) ;
F_101 ( & V_16 -> V_17 -> V_166 , & V_167 ) ;
F_92 ( V_16 ) ;
F_93 ( & V_16 -> V_163 ) ;
F_94 ( V_16 ) ;
F_95 ( ( void * ) V_16 -> V_67 ) ;
F_56 ( V_2 , 0 ) ;
F_96 ( V_4 -> V_123 ) ;
F_96 ( V_4 -> V_124 ) ;
V_4 -> V_139 ( V_2 ) ;
F_97 ( V_2 -> V_122 ) ;
F_98 ( V_16 ) ;
return 0 ;
}
