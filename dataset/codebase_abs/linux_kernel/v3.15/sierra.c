static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_4 ,
V_5 ,
V_3 ,
0 ,
NULL ,
0 ,
V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_7 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_8 ,
V_5 ,
V_7 ,
0x0000 ,
NULL ,
0 ,
V_6 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
T_2 V_12 , V_13 ;
V_12 = V_10 -> V_14 -> V_15 -> V_16 . V_17 ;
V_13 = V_10 -> V_14 -> V_15 -> V_16 . V_18 ;
if ( V_12 == 0x99 )
V_11 = 0 ;
else if ( V_13 <= 3 )
V_11 = 1 ;
else
V_11 = ( V_13 - 1 ) / 2 ;
return V_11 ;
}
static int F_6 ( const T_2 V_12 ,
const struct V_19 * V_20 )
{
const T_2 * V_21 ;
int V_22 ;
if ( V_20 ) {
V_21 = V_20 -> V_23 ;
for ( V_22 = 0 ; V_22 < V_20 -> V_24 ; V_22 ++ ) {
if ( V_21 [ V_22 ] == V_12 )
return 1 ;
}
}
return 0 ;
}
static int F_7 ( const T_2 V_12 ,
const struct V_19 * V_25 )
{
const T_2 * V_21 ;
int V_22 ;
if ( V_25 ) {
V_21 = V_25 -> V_23 ;
for ( V_22 = 0 ; V_22 < V_25 -> V_24 ; V_22 ++ ) {
if ( V_21 [ V_22 ] == V_12 )
return 1 ;
}
}
return 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_14 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = V_10 -> V_14 ;
V_29 = V_27 -> V_15 ;
V_14 = V_29 -> V_16 . V_17 ;
return V_14 ;
}
static int F_9 ( struct V_9 * V_10 ,
const struct V_30 * V_31 )
{
int V_32 = 0 ;
struct V_1 * V_2 ;
T_2 V_12 ;
V_2 = V_10 -> V_33 ;
V_12 = F_8 ( V_10 ) ;
if ( V_10 -> V_14 -> V_34 == 2 ) {
F_10 ( & V_2 -> V_33 , L_1 ,
V_12 ) ;
F_11 ( V_2 , V_12 , 1 ) ;
}
V_12 = F_8 ( V_10 ) ;
if ( F_6 ( V_12 ,
(struct V_19 * ) V_31 -> V_35 ) ) {
F_10 ( & V_10 -> V_33 -> V_33 ,
L_2 , V_12 ) ;
return - V_36 ;
}
return V_32 ;
}
static int F_12 ( struct V_37 * V_38 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_39 * V_40 ;
T_1 V_14 = 0 ;
int V_41 = 0 ;
int V_42 = 0 ;
int V_43 ;
V_40 = F_13 ( V_38 ) ;
if ( V_40 -> V_44 )
V_41 |= 0x01 ;
if ( V_40 -> V_45 )
V_41 |= 0x02 ;
if ( V_10 -> V_11 == 1 ) {
V_14 = F_8 ( V_10 ) ;
if ( V_38 -> V_46 ) {
V_42 = 1 ;
}
}
else {
if ( V_38 -> V_47 == 2 )
V_14 = 0 ;
else if ( V_38 -> V_47 == 4 )
V_14 = 1 ;
else if ( V_38 -> V_47 == 5 )
V_14 = 2 ;
V_42 = 1 ;
}
if ( ! V_42 )
return 0 ;
V_43 = F_14 ( V_10 -> V_14 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_2 ( V_10 -> V_33 , F_15 ( V_10 -> V_33 , 0 ) ,
0x22 , 0x21 , V_41 , V_14 , NULL , 0 , V_6 ) ;
F_16 ( V_10 -> V_14 ) ;
return V_43 ;
}
static void F_17 ( struct V_48 * V_49 ,
struct V_37 * V_38 , struct V_50 * V_51 )
{
F_18 ( & V_49 -> V_52 , V_51 ) ;
F_12 ( V_38 ) ;
}
static int F_19 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_53 ;
unsigned int V_54 ;
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
V_54 = ( ( V_40 -> V_45 ) ? V_55 : 0 ) |
( ( V_40 -> V_44 ) ? V_56 : 0 ) |
( ( V_40 -> V_57 ) ? V_58 : 0 ) |
( ( V_40 -> V_59 ) ? V_60 : 0 ) |
( ( V_40 -> V_61 ) ? V_62 : 0 ) |
( ( V_40 -> V_63 ) ? V_64 : 0 ) ;
return V_54 ;
}
static int F_20 ( struct V_48 * V_49 ,
unsigned int V_65 , unsigned int V_66 )
{
struct V_37 * V_38 = V_49 -> V_53 ;
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
if ( V_65 & V_55 )
V_40 -> V_45 = 1 ;
if ( V_65 & V_56 )
V_40 -> V_44 = 1 ;
if ( V_66 & V_55 )
V_40 -> V_45 = 0 ;
if ( V_66 & V_56 )
V_40 -> V_44 = 0 ;
return F_12 ( V_38 ) ;
}
static void F_21 ( struct V_67 * V_67 )
{
struct V_37 * V_38 ;
if ( V_67 ) {
V_38 = V_67 -> V_68 ;
F_22 ( V_67 -> V_69 ) ;
F_23 ( V_67 ) ;
}
}
static void F_24 ( struct V_67 * V_67 )
{
struct V_37 * V_38 = V_67 -> V_68 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_70 * V_71 ;
int V_72 = V_67 -> V_72 ;
V_71 = V_38 -> V_10 -> V_73 ;
F_22 ( V_67 -> V_69 ) ;
F_25 ( V_38 -> V_10 -> V_14 ) ;
if ( V_72 )
F_10 ( & V_38 -> V_33 , L_3
L_4 , V_74 , V_72 ) ;
F_26 ( & V_40 -> V_75 ) ;
-- V_40 -> V_76 ;
F_27 ( & V_40 -> V_75 ) ;
F_26 ( & V_71 -> V_77 ) ;
-- V_71 -> V_78 ;
F_27 ( & V_71 -> V_77 ) ;
F_28 ( V_38 ) ;
}
static int F_29 ( struct V_48 * V_49 , struct V_37 * V_38 ,
const unsigned char * V_79 , int V_80 )
{
struct V_39 * V_40 ;
struct V_70 * V_71 ;
struct V_9 * V_10 = V_38 -> V_10 ;
unsigned long V_81 ;
unsigned char * V_82 ;
struct V_67 * V_67 ;
T_3 V_83 = F_30 ( ( T_3 ) V_80 , ( T_3 ) V_84 ) ;
int V_43 = 0 ;
if ( V_80 == 0 )
return 0 ;
V_40 = F_13 ( V_38 ) ;
V_71 = V_10 -> V_73 ;
F_10 ( & V_38 -> V_33 , L_5 , V_74 , V_83 ) ;
F_31 ( & V_40 -> V_75 , V_81 ) ;
F_10 ( & V_38 -> V_33 , L_6 , V_74 ,
V_40 -> V_76 ) ;
if ( V_40 -> V_76 > V_40 -> V_85 ) {
F_32 ( & V_40 -> V_75 , V_81 ) ;
F_10 ( & V_38 -> V_33 , L_7 , V_74 ) ;
return 0 ;
}
V_40 -> V_76 ++ ;
F_10 ( & V_38 -> V_33 , L_8 , V_74 ,
V_40 -> V_76 ) ;
F_32 ( & V_40 -> V_75 , V_81 ) ;
V_43 = F_33 ( V_10 -> V_14 ) ;
if ( V_43 < 0 ) {
F_31 ( & V_40 -> V_75 , V_81 ) ;
V_40 -> V_76 -- ;
F_32 ( & V_40 -> V_75 , V_81 ) ;
goto V_86;
}
V_82 = F_34 ( V_83 , V_87 ) ;
if ( ! V_82 ) {
V_43 = - V_88 ;
goto V_89;
}
V_67 = F_35 ( 0 , V_87 ) ;
if ( ! V_67 ) {
V_43 = - V_88 ;
goto V_90;
}
memcpy ( V_82 , V_79 , V_83 ) ;
F_36 ( & V_38 -> V_33 , V_74 , V_83 , V_82 ) ;
F_37 ( V_67 , V_10 -> V_33 ,
F_38 ( V_10 -> V_33 ,
V_38 -> V_47 ) ,
V_82 , V_83 , F_24 , V_38 ) ;
V_67 -> V_91 |= V_92 ;
F_31 ( & V_71 -> V_77 , V_81 ) ;
if ( V_71 -> V_93 ) {
F_39 ( V_67 , & V_40 -> V_94 ) ;
F_32 ( & V_71 -> V_77 , V_81 ) ;
goto V_95;
} else {
F_39 ( V_67 , & V_40 -> V_96 ) ;
}
V_43 = F_40 ( V_67 , V_87 ) ;
if ( V_43 ) {
F_41 ( V_67 ) ;
F_32 ( & V_71 -> V_77 , V_81 ) ;
F_42 ( & V_38 -> V_33 , L_9
L_10 , V_74 , V_43 ) ;
goto error;
} else {
V_71 -> V_78 ++ ;
F_32 ( & V_71 -> V_77 , V_81 ) ;
}
V_95:
F_23 ( V_67 ) ;
return V_83 ;
error:
F_23 ( V_67 ) ;
V_90:
F_22 ( V_82 ) ;
V_89:
F_31 ( & V_40 -> V_75 , V_81 ) ;
-- V_40 -> V_76 ;
F_10 ( & V_38 -> V_33 , L_11 , V_74 ,
V_40 -> V_76 ) ;
F_32 ( & V_40 -> V_75 , V_81 ) ;
F_25 ( V_10 -> V_14 ) ;
V_86:
return V_43 ;
}
static void F_43 ( struct V_67 * V_67 )
{
int V_97 ;
int V_98 ;
struct V_37 * V_38 ;
unsigned char * V_99 = V_67 -> V_69 ;
int V_72 = V_67 -> V_72 ;
V_98 = F_44 ( V_67 -> V_100 ) ;
V_38 = V_67 -> V_68 ;
if ( V_72 ) {
F_10 ( & V_38 -> V_33 , L_12
L_13 , V_74 , V_72 , V_98 ) ;
} else {
if ( V_67 -> V_101 ) {
F_45 ( & V_38 -> V_38 , V_99 ,
V_67 -> V_101 ) ;
F_46 ( & V_38 -> V_38 ) ;
F_36 ( & V_38 -> V_33 , V_74 ,
V_67 -> V_101 , V_99 ) ;
} else {
F_10 ( & V_38 -> V_33 , L_14
L_15 , V_74 ) ;
}
}
if ( V_72 != - V_102 && V_72 != - V_103 ) {
F_47 ( V_38 -> V_10 -> V_33 ) ;
V_97 = F_40 ( V_67 , V_87 ) ;
if ( V_97 && V_97 != - V_103 )
F_42 ( & V_38 -> V_33 , L_16
L_17 , V_97 ) ;
}
}
static void F_48 ( struct V_67 * V_67 )
{
int V_97 ;
int V_72 = V_67 -> V_72 ;
struct V_37 * V_38 = V_67 -> V_68 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_9 * V_10 = V_38 -> V_10 ;
F_10 ( & V_38 -> V_33 , L_18 , V_74 ,
V_67 , V_38 , V_40 ) ;
if ( V_72 == 0 ) {
struct V_104 * V_105 =
(struct V_104 * ) V_67 -> V_69 ;
if ( ! V_105 ) {
F_10 ( & V_38 -> V_33 , L_19 ,
V_74 ) ;
return;
}
if ( ( V_105 -> V_106 == 0xA1 ) &&
( V_105 -> V_107 == 0x20 ) ) {
int V_108 ;
unsigned char V_109 = * ( ( unsigned char * )
V_67 -> V_69 +
sizeof( struct V_104 ) ) ;
F_10 ( & V_38 -> V_33 , L_20 , V_74 ,
V_109 ) ;
V_108 = V_40 -> V_61 ;
V_40 -> V_57 = 1 ;
V_40 -> V_61 = ( ( V_109 & 0x01 ) ? 1 : 0 ) ;
V_40 -> V_59 = ( ( V_109 & 0x02 ) ? 1 : 0 ) ;
V_40 -> V_63 = ( ( V_109 & 0x08 ) ? 1 : 0 ) ;
if ( V_108 && ! V_40 -> V_61 )
F_49 ( & V_38 -> V_38 , true ) ;
} else {
F_10 ( & V_38 -> V_33 , L_21 ,
V_74 , V_105 -> V_106 ,
V_105 -> V_107 ) ;
}
} else
F_10 ( & V_38 -> V_33 , L_22 , V_74 , V_72 ) ;
if ( V_72 != - V_102 && V_72 != - V_110 ) {
F_47 ( V_10 -> V_33 ) ;
V_97 = F_40 ( V_67 , V_87 ) ;
if ( V_97 && V_97 != - V_103 )
F_42 ( & V_38 -> V_33 , L_23
L_24 , V_74 , V_97 ) ;
}
}
static int F_50 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_53 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
unsigned long V_81 ;
F_31 ( & V_40 -> V_75 , V_81 ) ;
if ( V_40 -> V_76 > ( V_40 -> V_85 * 2 ) / 3 ) {
F_32 ( & V_40 -> V_75 , V_81 ) ;
F_10 ( & V_38 -> V_33 , L_7 , V_74 ) ;
return 0 ;
}
F_32 ( & V_40 -> V_75 , V_81 ) ;
return 2048 ;
}
static void F_51 ( struct V_37 * V_38 )
{
int V_22 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_111 ; V_22 ++ )
F_52 ( V_40 -> V_112 [ V_22 ] ) ;
F_52 ( V_38 -> V_46 ) ;
}
static int F_53 ( struct V_37 * V_38 , T_4 V_113 )
{
int V_114 ;
int V_97 = - V_115 ;
int V_22 ;
struct V_67 * V_67 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
V_114 = 0 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_111 ; V_22 ++ ) {
V_67 = V_40 -> V_112 [ V_22 ] ;
if ( ! V_67 )
continue;
V_97 = F_40 ( V_67 , V_113 ) ;
if ( V_97 ) {
F_42 ( & V_38 -> V_33 , L_25 ,
V_74 , V_97 ) ;
} else {
V_114 ++ ;
}
}
if ( V_114 && V_38 -> V_46 ) {
V_97 = F_40 ( V_38 -> V_46 , V_113 ) ;
if ( V_97 ) {
F_42 ( & V_38 -> V_33 , L_26 ,
V_74 , V_97 ) ;
}
}
if ( V_114 > 0 )
return 0 ;
else
return V_97 ;
}
static struct V_67 * F_54 ( struct V_9 * V_10 , int V_98 ,
int V_116 , void * V_117 , int V_118 ,
T_4 V_113 ,
T_5 V_119 )
{
struct V_67 * V_67 ;
T_2 * V_79 ;
if ( V_98 == - 1 )
return NULL ;
V_67 = F_35 ( 0 , V_113 ) ;
if ( ! V_67 )
return NULL ;
V_79 = F_34 ( V_118 , V_113 ) ;
if ( V_79 ) {
F_37 ( V_67 , V_10 -> V_33 ,
F_38 ( V_10 -> V_33 , V_98 ) | V_116 ,
V_79 , V_118 , V_119 , V_117 ) ;
F_10 ( & V_10 -> V_33 -> V_33 , L_27 , V_74 ,
V_116 == V_120 ? 'i' : 'o' , V_67 , V_79 ) ;
} else {
F_21 ( V_67 ) ;
V_67 = NULL ;
}
return V_67 ;
}
static void F_55 ( struct V_37 * V_38 )
{
int V_22 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_39 * V_40 ;
struct V_70 * V_71 = V_38 -> V_10 -> V_73 ;
V_40 = F_13 ( V_38 ) ;
V_40 -> V_45 = 0 ;
V_40 -> V_44 = 0 ;
F_56 ( & V_10 -> V_121 ) ;
if ( ! V_10 -> V_122 ) {
V_10 -> V_14 -> V_123 = 0 ;
if ( ! F_14 ( V_10 -> V_14 ) )
F_12 ( V_38 ) ;
else
F_57 ( V_10 -> V_14 ) ;
}
F_58 ( & V_10 -> V_121 ) ;
F_59 ( & V_71 -> V_77 ) ;
V_40 -> V_124 = 0 ;
F_60 ( & V_71 -> V_77 ) ;
F_51 ( V_38 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_111 ; V_22 ++ ) {
F_21 ( V_40 -> V_112 [ V_22 ] ) ;
V_40 -> V_112 [ V_22 ] = NULL ;
}
}
static int F_61 ( struct V_48 * V_49 , struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_70 * V_71 = V_10 -> V_73 ;
int V_22 ;
int V_97 ;
int V_98 ;
struct V_67 * V_67 ;
V_40 = F_13 ( V_38 ) ;
V_40 -> V_45 = 1 ;
V_40 -> V_44 = 1 ;
V_98 = V_38 -> V_125 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_111 ; V_22 ++ ) {
V_67 = F_54 ( V_10 , V_98 , V_120 , V_38 ,
V_126 , V_127 ,
F_43 ) ;
V_40 -> V_112 [ V_22 ] = V_67 ;
}
F_62 ( V_10 -> V_33 ,
F_38 ( V_10 -> V_33 , V_98 ) | V_120 ) ;
V_97 = F_53 ( V_38 , V_127 ) ;
if ( V_97 ) {
F_55 ( V_38 ) ;
if ( ! V_10 -> V_122 )
F_16 ( V_10 -> V_14 ) ;
return V_97 ;
}
F_12 ( V_38 ) ;
V_10 -> V_14 -> V_123 = 1 ;
F_59 ( & V_71 -> V_77 ) ;
V_40 -> V_124 = 1 ;
F_60 ( & V_71 -> V_77 ) ;
F_16 ( V_10 -> V_14 ) ;
return 0 ;
}
static void F_63 ( struct V_37 * V_38 , int V_128 )
{
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
V_40 -> V_45 = V_128 ;
V_40 -> V_44 = V_128 ;
F_12 ( V_38 ) ;
}
static int F_64 ( struct V_9 * V_10 )
{
struct V_70 * V_71 ;
V_71 = F_65 ( sizeof( * V_71 ) , V_127 ) ;
if ( ! V_71 )
return - V_88 ;
F_66 ( & V_71 -> V_77 ) ;
F_67 ( V_10 , V_71 ) ;
F_1 ( V_10 -> V_33 , 0x0000 ) ;
if ( V_129 )
F_4 ( V_10 -> V_33 , 1 ) ;
return 0 ;
}
static void F_68 ( struct V_9 * V_10 )
{
struct V_70 * V_71 ;
V_71 = F_69 ( V_10 ) ;
F_22 ( V_71 ) ;
}
static int F_70 ( struct V_37 * V_38 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_39 * V_40 ;
const struct V_19 * V_130 ;
T_2 V_12 ;
V_40 = F_65 ( sizeof( * V_40 ) , V_127 ) ;
if ( ! V_40 )
return - V_88 ;
F_66 ( & V_40 -> V_75 ) ;
F_71 ( & V_40 -> V_96 ) ;
F_71 ( & V_40 -> V_94 ) ;
V_40 -> V_85 = V_131 ;
V_40 -> V_111 = V_132 ;
if ( V_10 -> V_11 == 1 ) {
V_12 = F_8 ( V_10 ) ;
V_130 = & V_133 ;
} else {
V_12 = V_38 -> V_134 ;
V_130 = & V_135 ;
}
if ( F_7 ( V_12 , V_130 ) ) {
V_40 -> V_85 = V_136 ;
V_40 -> V_111 = V_137 ;
}
F_10 ( & V_38 -> V_33 ,
L_28 ,
V_12 , V_40 -> V_111 , V_40 -> V_85 ) ;
F_72 ( V_38 , V_40 ) ;
return 0 ;
}
static int F_73 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
F_22 ( V_40 ) ;
return 0 ;
}
static void F_74 ( struct V_9 * V_10 )
{
int V_22 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; ++ V_22 ) {
V_38 = V_10 -> V_38 [ V_22 ] ;
V_40 = F_13 ( V_38 ) ;
F_51 ( V_38 ) ;
F_75 ( & V_40 -> V_96 ) ;
}
}
static int F_76 ( struct V_9 * V_10 , T_6 V_138 )
{
struct V_70 * V_71 ;
int V_139 ;
if ( F_77 ( V_138 ) ) {
V_71 = V_10 -> V_73 ;
F_59 ( & V_71 -> V_77 ) ;
V_139 = V_71 -> V_78 ;
if ( V_139 ) {
F_60 ( & V_71 -> V_77 ) ;
return - V_140 ;
} else {
V_71 -> V_93 = 1 ;
F_60 ( & V_71 -> V_77 ) ;
}
}
F_74 ( V_10 ) ;
return 0 ;
}
static int F_78 ( struct V_9 * V_10 )
{
struct V_37 * V_38 ;
struct V_70 * V_71 = V_10 -> V_73 ;
struct V_39 * V_40 ;
struct V_67 * V_67 ;
int V_141 = 0 ;
int V_22 , V_97 ;
F_59 ( & V_71 -> V_77 ) ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; V_22 ++ ) {
V_38 = V_10 -> V_38 [ V_22 ] ;
V_40 = F_13 ( V_38 ) ;
while ( ( V_67 = F_79 ( & V_40 -> V_94 ) ) ) {
F_39 ( V_67 , & V_40 -> V_96 ) ;
V_71 -> V_78 ++ ;
V_97 = F_40 ( V_67 , V_87 ) ;
if ( V_97 < 0 ) {
V_71 -> V_78 -- ;
F_41 ( V_67 ) ;
F_80 ( & V_40 -> V_94 ) ;
break;
}
}
if ( V_40 -> V_124 ) {
V_97 = F_53 ( V_38 , V_87 ) ;
if ( V_97 )
V_141 ++ ;
}
}
V_71 -> V_93 = 0 ;
F_60 ( & V_71 -> V_77 ) ;
return V_141 ? - V_142 : 0 ;
}
