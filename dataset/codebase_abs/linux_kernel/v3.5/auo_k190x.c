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
static int F_3 ( struct V_1 * V_2 , int V_9 ,
T_1 * V_3 )
{
struct V_10 * V_11 = V_2 -> V_12 -> V_10 ;
int V_13 ;
T_1 V_14 ;
if ( V_9 & 3 ) {
F_4 ( V_11 , L_1 ,
V_9 ) ;
return - V_15 ;
}
for ( V_13 = 0 ; V_13 < ( V_9 >> 1 ) ; V_13 ++ ) {
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_14 = ( V_3 [ 2 * V_13 ] & 0xF0 ) >> 4 ;
V_14 |= ( V_3 [ 2 * V_13 ] & 0xF000 ) >> 8 ;
V_14 |= ( V_3 [ 2 * V_13 + 1 ] & 0xF0 ) << 4 ;
V_14 |= ( V_3 [ 2 * V_13 + 1 ] & 0xF000 ) ;
V_2 -> V_4 -> V_7 ( V_2 , V_14 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 -> V_5 ( V_2 , V_16 , 0 ) ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_16 , 1 ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 0 ) ;
F_2 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 1 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_19 ,
int V_20 , T_1 * V_21 )
{
int V_13 ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 0 ) ;
F_2 ( V_2 , V_19 ) ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_1 ( V_2 , V_21 [ V_13 ] ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_22 ;
V_22 = V_2 -> V_4 -> V_23 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_6 ( V_2 , V_3 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_19 ,
int V_20 , T_1 * V_21 )
{
int V_22 ;
V_22 = V_2 -> V_4 -> V_23 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_7 ( V_2 , V_19 , V_20 , V_21 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_19 ,
int V_20 , T_1 * V_21 )
{
int V_13 , V_22 ;
V_22 = V_2 -> V_4 -> V_23 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 0 ) ;
F_2 ( V_2 , V_19 ) ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
V_21 [ V_13 ] = F_5 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 1 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_19 ,
int V_20 , T_1 * V_21 , int V_9 , T_1 * V_3 )
{
int V_13 ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 0 ) ;
F_2 ( V_2 , V_19 ) ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_1 ( V_2 , V_21 [ V_13 ] ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_18 , 1 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_19 ,
int V_20 , T_1 * V_21 , int V_9 , T_1 * V_3 )
{
int V_22 ;
V_22 = V_2 -> V_4 -> V_23 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_11 ( V_2 , V_19 , V_20 , V_21 , V_9 , V_3 ) ;
return 0 ;
}
static void F_13 ( struct V_24 * V_12 )
{
F_14 ( V_12 -> V_10 ) ;
}
static void F_15 ( struct V_24 * V_12 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_12 -> V_28 ;
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_29 = V_12 -> V_30 . V_29 ;
T_1 V_31 = V_12 -> V_30 . V_31 ;
T_1 y1 = 0 , V_32 = 0 ;
int V_33 = - 1 ;
struct V_34 * V_35 ;
int V_36 ;
int V_37 ;
if ( ! F_16 ( V_26 ) )
F_17 ( V_12 -> V_10 ) ;
else
F_18 ( V_12 -> V_10 ) ;
if ( V_2 -> V_38 ( V_2 ) ) {
V_2 -> V_39 ( V_2 ) ;
goto V_40;
}
V_36 = F_19 ( V_41 , V_31 ) ;
V_37 = V_2 -> V_42 / V_36 ;
if ( V_37 < 1 )
V_37 = 1 ;
F_20 (cur, &fbdefio->pagelist, lru) {
if ( V_33 < 0 ) {
y1 = ( V_35 -> V_43 << V_44 ) / V_31 ;
V_32 = V_36 ;
} else if ( ( V_35 -> V_43 - V_33 ) <= V_37 ) {
V_32 += V_36 * ( V_35 -> V_43 - V_33 ) ;
} else {
V_2 -> V_45 ( V_2 , y1 , y1 + V_32 ) ;
y1 = ( V_35 -> V_43 << V_44 ) / V_31 ;
V_32 = V_36 ;
}
V_33 = V_35 -> V_43 ;
}
if ( V_32 >= V_29 )
V_2 -> V_39 ( V_2 ) ;
else
V_2 -> V_45 ( V_2 , y1 , F_21 ( ( T_1 ) ( y1 + V_32 ) , V_29 ) ) ;
V_40:
F_22 ( V_12 -> V_10 ) ;
F_23 ( V_12 -> V_10 ) ;
}
static T_2 F_24 ( struct V_24 * V_12 , const char T_3 * V_46 ,
T_4 V_47 , T_5 * V_48 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_49 = * V_48 ;
void * V_50 ;
int V_51 = 0 ;
unsigned long V_52 ;
if ( V_12 -> V_53 != V_54 )
return - V_55 ;
V_52 = V_12 -> V_56 . V_57 ;
if ( V_49 > V_52 )
return - V_58 ;
if ( V_47 > V_52 ) {
V_51 = - V_58 ;
V_47 = V_52 ;
}
if ( V_47 + V_49 > V_52 ) {
if ( ! V_51 )
V_51 = - V_59 ;
V_47 = V_52 - V_49 ;
}
V_50 = ( void * ) ( V_12 -> V_60 + V_49 ) ;
if ( F_25 ( V_50 , V_46 , V_47 ) )
V_51 = - V_61 ;
if ( ! V_51 )
* V_48 += V_47 ;
V_2 -> V_39 ( V_2 ) ;
return ( V_51 ) ? V_51 : V_47 ;
}
static void F_26 ( struct V_24 * V_12 ,
const struct V_62 * V_63 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_27 ( V_12 , V_63 ) ;
V_2 -> V_39 ( V_2 ) ;
}
static void F_28 ( struct V_24 * V_12 ,
const struct V_64 * V_65 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_29 ( V_12 , V_65 ) ;
V_2 -> V_39 ( V_2 ) ;
}
static void F_30 ( struct V_24 * V_12 ,
const struct V_66 * V_67 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_31 ( V_12 , V_67 ) ;
V_2 -> V_39 ( V_2 ) ;
}
static int F_32 ( struct V_68 * V_30 ,
struct V_24 * V_12 )
{
if ( V_12 -> V_30 . V_31 != V_30 -> V_31 || V_12 -> V_30 . V_29 != V_30 -> V_29 ||
V_12 -> V_30 . V_69 != V_30 -> V_69 ||
V_12 -> V_30 . V_70 != V_30 -> V_70 ) {
F_33 ( L_2 ,
V_71 , V_30 -> V_31 , V_30 -> V_29 ) ;
return - V_15 ;
}
if ( ( V_12 -> V_56 . V_72 * V_30 -> V_70 ) > V_12 -> V_56 . V_57 ) {
F_33 ( L_3 ,
V_71 , V_30 -> V_70 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 -> V_10 ;
T_1 V_3 [ 4 ] ;
int V_74 ;
F_18 ( V_11 ) ;
F_35 ( & ( V_2 -> V_75 ) ) ;
F_10 ( V_2 , V_76 , 4 , V_3 ) ;
F_36 ( & ( V_2 -> V_75 ) ) ;
F_22 ( V_11 ) ;
F_23 ( V_11 ) ;
V_74 = ( ( V_3 [ 0 ] & V_77 ) >> 1 ) ;
if ( V_74 >= 201 )
return ( 255 - V_74 + 1 ) * ( - 1 ) ;
else
return V_74 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 -> V_10 ;
T_1 V_3 [ 4 ] ;
F_18 ( V_11 ) ;
F_35 ( & ( V_2 -> V_75 ) ) ;
F_10 ( V_2 , V_76 , 4 , V_3 ) ;
F_36 ( & ( V_2 -> V_75 ) ) ;
V_2 -> V_78 = V_3 [ 1 ] & V_77 ;
V_2 -> V_79 = F_38 ( V_3 [ 2 ] ) ;
V_2 -> V_80 = F_39 ( V_3 [ 2 ] ) ;
V_2 -> V_81 = F_40 ( V_3 [ 2 ] ) ;
V_2 -> V_82 = F_41 ( V_3 [ 3 ] ) ;
V_2 -> V_83 = F_42 ( V_3 [ 3 ] ) ;
F_43 ( V_11 , L_4 ,
V_2 -> V_79 , V_2 -> V_80 , V_2 -> V_81 ,
V_2 -> V_78 , V_2 -> V_82 , V_2 -> V_83 ) ;
F_22 ( V_11 ) ;
F_23 ( V_11 ) ;
}
static T_2 F_44 ( struct V_10 * V_11 ,
struct V_84 * V_85 , char * V_46 )
{
struct V_24 * V_12 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
return sprintf ( V_46 , L_5 , V_2 -> V_86 ) ;
}
static T_2 F_46 ( struct V_10 * V_11 ,
struct V_84 * V_85 ,
const char * V_46 , T_4 V_47 )
{
struct V_24 * V_12 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_87 , V_22 ;
V_22 = F_47 ( V_46 , 10 , & V_87 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_86 = V_87 ;
if ( V_2 -> V_88 > 1 && V_87 < V_2 -> V_88 )
V_2 -> V_39 ( V_2 ) ;
return V_47 ;
}
static T_2 F_48 ( struct V_10 * V_11 , struct V_84 * V_85 ,
char * V_46 )
{
struct V_24 * V_12 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
return sprintf ( V_46 , L_5 , V_2 -> V_89 ) ;
}
static T_2 F_49 ( struct V_10 * V_11 , struct V_84 * V_85 ,
const char * V_46 , T_4 V_47 )
{
struct V_24 * V_12 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_89 , V_22 ;
V_22 = F_47 ( V_46 , 10 , & V_89 ) ;
if ( V_22 )
return V_22 ;
if ( V_89 > 0 )
V_2 -> V_89 = 1 ;
else
V_2 -> V_89 = 0 ;
return V_47 ;
}
static T_2 F_50 ( struct V_10 * V_11 , struct V_84 * V_85 ,
char * V_46 )
{
struct V_24 * V_12 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_74 ;
V_74 = F_34 ( V_2 ) ;
return sprintf ( V_46 , L_5 , V_74 ) ;
}
static int F_51 ( struct V_1 * V_2 , bool V_90 )
{
struct V_91 * V_4 = V_2 -> V_4 ;
int V_22 ;
if ( V_90 ) {
V_22 = F_52 ( V_2 -> V_92 ) ;
if ( V_22 )
return V_22 ;
F_53 ( 200 ) ;
F_54 ( V_4 -> V_93 , 1 ) ;
F_54 ( V_4 -> V_94 , 1 ) ;
F_53 ( 200 ) ;
} else {
F_55 ( V_2 -> V_92 ) ;
F_54 ( V_4 -> V_93 , 0 ) ;
F_54 ( V_4 -> V_94 , 0 ) ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_51 ( V_2 , 0 ) ;
F_53 ( 100 ) ;
F_51 ( V_2 , 1 ) ;
V_2 -> V_95 ( V_2 ) ;
V_2 -> V_4 -> V_23 ( V_2 ) ;
}
static int F_57 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = F_58 ( V_11 ) ;
struct V_24 * V_12 = F_59 ( V_97 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_91 * V_4 = V_2 -> V_4 ;
T_1 V_98 ;
F_35 ( & ( V_2 -> V_75 ) ) ;
if ( V_2 -> V_99 ) {
F_60 ( V_11 , L_6 ) ;
F_36 ( & ( V_2 -> V_75 ) ) ;
return 0 ;
}
if ( V_4 -> V_100 & V_101 ) {
F_43 ( V_11 , L_7 ) ;
goto V_102;
} else if ( V_4 -> V_100 & V_103 ) {
F_43 ( V_11 , L_8 ) ;
V_98 = 0 ;
F_9 ( V_2 , V_104 , 1 ,
& V_98 ) ;
} else {
F_43 ( V_11 , L_9 ) ;
F_8 ( V_2 , V_104 ) ;
}
F_53 ( 64 ) ;
V_102:
V_2 -> V_99 = 1 ;
return 0 ;
}
static int F_61 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = F_58 ( V_11 ) ;
struct V_24 * V_12 = F_59 ( V_97 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_91 * V_4 = V_2 -> V_4 ;
if ( ! V_2 -> V_99 ) {
F_60 ( V_11 , L_10 ) ;
return 0 ;
}
if ( V_4 -> V_100 & V_101 ) {
F_43 ( V_11 , L_11 ) ;
} else {
F_43 ( V_11 , L_12 ) ;
F_6 ( V_2 , V_105 ) ;
F_53 ( 160 ) ;
V_4 -> V_23 ( V_2 ) ;
}
V_2 -> V_99 = 0 ;
F_36 ( & ( V_2 -> V_75 ) ) ;
return 0 ;
}
static int F_62 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = F_58 ( V_11 ) ;
struct V_24 * V_12 = F_59 ( V_97 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_91 * V_4 = V_2 -> V_4 ;
int V_22 ;
F_43 ( V_11 , L_13 ) ;
if ( V_4 -> V_100 & V_101 ) {
F_43 ( V_11 , L_14 ) ;
F_51 ( V_2 , 0 ) ;
} else {
F_43 ( V_11 , L_15 ) ;
if ( ! F_63 ( V_11 ) ) {
V_22 = F_57 ( V_11 ) ;
if ( V_22 < 0 ) {
F_4 ( V_11 , L_16 ,
V_22 ) ;
return V_22 ;
}
V_2 -> V_106 = 1 ;
}
F_64 ( V_4 -> V_94 , 0 ) ;
}
F_53 ( 100 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = F_58 ( V_11 ) ;
struct V_24 * V_12 = F_59 ( V_97 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_91 * V_4 = V_2 -> V_4 ;
F_43 ( V_11 , L_17 ) ;
if ( V_4 -> V_100 & V_101 ) {
F_43 ( V_11 , L_18 ) ;
F_51 ( V_2 , 1 ) ;
V_2 -> V_95 ( V_2 ) ;
} else {
F_43 ( V_11 , L_19 ) ;
F_64 ( V_4 -> V_94 , 1 ) ;
F_53 ( 100 ) ;
F_61 ( V_11 ) ;
V_2 -> V_95 ( V_2 ) ;
if ( ! V_2 -> V_106 )
F_57 ( V_11 ) ;
else
V_2 -> V_106 = 0 ;
}
return 0 ;
}
int T_6 F_66 ( struct V_96 * V_97 ,
struct V_107 * V_95 )
{
struct V_91 * V_4 = V_95 -> V_4 ;
struct V_1 * V_2 ;
struct V_24 * V_12 ;
struct V_108 * V_109 ;
int V_110 , V_22 ;
unsigned char * V_111 ;
if ( ! V_4 -> V_95 || ! V_4 -> V_112 || ! V_4 -> V_23
|| ! V_4 -> V_5 || ! V_4 -> V_7 || ! V_4 -> V_17
|| ! V_4 -> V_113 )
return - V_15 ;
V_12 = F_67 ( sizeof( struct V_1 ) , & V_97 -> V_11 ) ;
if ( ! V_12 )
return - V_73 ;
V_2 = V_12 -> V_2 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_114 = F_56 ;
V_2 -> V_45 = V_95 -> V_45 ;
V_2 -> V_39 = V_95 -> V_39 ;
V_2 -> V_38 = V_95 -> V_38 ;
V_2 -> V_95 = V_95 -> V_95 ;
V_2 -> V_115 = 0 ;
V_2 -> V_86 = - 1 ;
V_2 -> V_88 = - 1 ;
V_2 -> V_89 = 0 ;
V_2 -> V_92 = F_68 ( V_12 -> V_10 , L_20 ) ;
if ( F_69 ( V_2 -> V_92 ) ) {
V_22 = F_70 ( V_2 -> V_92 ) ;
F_4 ( V_12 -> V_10 , L_21 , V_22 ) ;
goto V_116;
}
V_22 = V_4 -> V_95 ( V_2 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_22 , V_22 ) ;
goto V_117;
}
V_22 = F_71 ( V_4 -> V_94 , L_23 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_24 ,
V_22 ) ;
goto V_118;
}
V_22 = F_64 ( V_4 -> V_94 , 0 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_25 , V_22 ) ;
goto V_119;
}
V_22 = F_71 ( V_4 -> V_93 , L_26 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_27 ,
V_22 ) ;
goto V_119;
}
V_22 = F_64 ( V_4 -> V_93 , 0 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_28 , V_22 ) ;
goto V_120;
}
V_22 = F_51 ( V_2 , 1 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_29 ,
V_22 ) ;
goto V_120;
}
F_72 ( & V_2 -> V_75 ) ;
F_73 ( & V_2 -> V_121 ) ;
V_22 = V_2 -> V_4 -> V_113 ( V_2 -> V_12 ) ;
if ( V_22 ) {
F_4 ( V_12 -> V_10 , L_30 , V_22 ) ;
goto V_122;
}
V_2 -> V_4 -> V_23 ( V_2 ) ;
F_74 ( V_12 -> V_56 . V_123 , V_95 -> V_123 , 16 ) ;
V_12 -> V_56 . type = V_124 ;
V_12 -> V_56 . V_125 = V_126 ;
V_12 -> V_56 . V_127 = 0 ;
V_12 -> V_56 . V_128 = 0 ;
V_12 -> V_56 . V_129 = 0 ;
V_12 -> V_56 . V_130 = V_131 ;
V_12 -> V_30 . V_132 = 8 ;
V_12 -> V_30 . V_133 = 1 ;
V_12 -> V_30 . V_134 . V_135 = 8 ;
V_12 -> V_30 . V_136 . V_135 = 8 ;
V_12 -> V_30 . V_137 . V_135 = 8 ;
V_109 = & V_138 [ V_4 -> V_139 ] ;
if ( V_4 -> V_140 & 1 ) {
V_12 -> V_30 . V_31 = V_109 -> V_32 ;
V_12 -> V_30 . V_29 = V_109 -> V_141 ;
V_12 -> V_30 . V_69 = V_109 -> V_32 ;
V_12 -> V_30 . V_70 = V_109 -> V_141 ;
V_12 -> V_56 . V_72 = V_109 -> V_32 ;
} else {
V_12 -> V_30 . V_31 = V_109 -> V_141 ;
V_12 -> V_30 . V_29 = V_109 -> V_32 ;
V_12 -> V_30 . V_69 = V_109 -> V_141 ;
V_12 -> V_30 . V_70 = V_109 -> V_32 ;
V_12 -> V_56 . V_72 = V_109 -> V_141 ;
}
V_2 -> V_139 = V_4 -> V_139 ;
V_2 -> V_140 = V_4 -> V_140 ;
V_110 = F_75 ( ( V_109 -> V_141 * V_109 -> V_32 ) , V_41 ) ;
V_111 = F_76 ( V_110 ) ;
if ( ! V_111 ) {
V_22 = - V_73 ;
goto V_122;
}
memset ( V_111 , 0 , V_110 ) ;
V_12 -> V_60 = ( char * ) V_111 ;
V_12 -> V_56 . V_57 = V_110 ;
V_12 -> V_142 = V_143 | V_144 ;
V_12 -> V_145 = & V_146 ;
V_12 -> V_28 = F_77 ( V_12 -> V_10 ,
sizeof( struct V_27 ) ,
V_147 ) ;
if ( ! V_12 -> V_28 ) {
F_4 ( V_12 -> V_10 , L_31 ) ;
V_22 = - V_73 ;
goto V_148;
}
F_43 ( V_12 -> V_10 , L_32 , V_4 -> V_149 ) ;
V_12 -> V_28 -> V_150 = V_151 / V_4 -> V_149 ;
V_12 -> V_28 -> V_152 = F_13 ,
V_12 -> V_28 -> V_153 = F_15 ,
F_78 ( V_12 ) ;
V_22 = F_79 ( & V_12 -> V_154 , 256 , 0 ) ;
if ( V_22 < 0 ) {
F_4 ( V_12 -> V_10 , L_33 ) ;
goto V_155;
}
V_2 -> V_42 = 100 ;
V_2 -> V_95 ( V_2 ) ;
F_37 ( V_2 ) ;
F_80 ( V_97 , V_12 ) ;
V_22 = F_81 ( V_12 ) ;
if ( V_22 < 0 )
goto V_156;
V_22 = F_82 ( & V_12 -> V_10 -> V_157 , & V_158 ) ;
if ( V_22 )
goto V_159;
F_83 ( V_12 -> V_10 , L_34 ,
V_12 -> V_160 , V_12 -> V_30 . V_31 , V_12 -> V_30 . V_29 ,
V_110 >> 10 ) ;
V_2 -> V_161 = ( V_4 -> V_100 & V_101 )
? 1000 : 200 ;
F_84 ( V_12 -> V_10 ) ;
F_85 ( V_12 -> V_10 ) ;
F_86 ( V_12 -> V_10 , V_2 -> V_161 ) ;
F_87 ( V_12 -> V_10 ) ;
return 0 ;
V_159:
F_88 ( V_12 ) ;
V_156:
F_89 ( & V_12 -> V_154 ) ;
V_155:
F_90 ( V_12 ) ;
F_91 ( V_12 -> V_28 ) ;
V_148:
F_92 ( ( void * ) V_12 -> V_60 ) ;
V_122:
F_51 ( V_2 , 0 ) ;
V_120:
F_93 ( V_4 -> V_93 ) ;
V_119:
F_93 ( V_4 -> V_94 ) ;
V_118:
V_4 -> V_112 ( V_2 ) ;
V_117:
F_94 ( V_2 -> V_92 ) ;
V_116:
F_95 ( V_12 ) ;
return V_22 ;
}
int T_7 F_96 ( struct V_96 * V_97 )
{
struct V_24 * V_12 = F_59 ( V_97 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_91 * V_4 = V_2 -> V_4 ;
F_97 ( V_12 -> V_10 ) ;
F_98 ( & V_12 -> V_10 -> V_157 , & V_158 ) ;
F_88 ( V_12 ) ;
F_89 ( & V_12 -> V_154 ) ;
F_90 ( V_12 ) ;
F_91 ( V_12 -> V_28 ) ;
F_92 ( ( void * ) V_12 -> V_60 ) ;
F_51 ( V_2 , 0 ) ;
F_93 ( V_4 -> V_93 ) ;
F_93 ( V_4 -> V_94 ) ;
V_4 -> V_112 ( V_2 ) ;
F_94 ( V_2 -> V_92 ) ;
F_95 ( V_12 ) ;
return 0 ;
}
