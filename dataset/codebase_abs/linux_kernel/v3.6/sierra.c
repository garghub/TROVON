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
struct V_33 * V_34 ;
T_2 V_12 ;
V_2 = V_10 -> V_35 ;
V_12 = F_8 ( V_10 ) ;
if ( V_10 -> V_14 -> V_36 == 2 ) {
F_10 ( & V_2 -> V_35 , L_1 ,
V_12 ) ;
F_11 ( V_2 , V_12 , 1 ) ;
}
V_12 = F_8 ( V_10 ) ;
if ( F_6 ( V_12 ,
(struct V_19 * ) V_31 -> V_37 ) ) {
F_10 ( & V_10 -> V_35 -> V_35 ,
L_2 , V_12 ) ;
return - V_38 ;
}
V_34 = V_10 -> V_39 = F_12 ( sizeof( struct V_33 ) , V_40 ) ;
if ( ! V_34 )
return - V_41 ;
F_13 ( & V_34 -> V_42 ) ;
return V_32 ;
}
static int F_14 ( struct V_43 * V_44 )
{
struct V_9 * V_10 = V_44 -> V_10 ;
struct V_45 * V_46 ;
T_1 V_14 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 ;
V_46 = F_15 ( V_44 ) ;
if ( V_46 -> V_50 )
V_47 |= 0x01 ;
if ( V_46 -> V_51 )
V_47 |= 0x02 ;
if ( V_10 -> V_11 == 1 ) {
V_14 = F_8 ( V_10 ) ;
if ( V_44 -> V_52 ) {
V_48 = 1 ;
}
}
else {
if ( V_44 -> V_53 == 2 )
V_14 = 0 ;
else if ( V_44 -> V_53 == 4 )
V_14 = 1 ;
else if ( V_44 -> V_53 == 5 )
V_14 = 2 ;
V_48 = 1 ;
}
if ( ! V_48 )
return 0 ;
V_49 = F_16 ( V_10 -> V_14 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_2 ( V_10 -> V_35 , F_17 ( V_10 -> V_35 , 0 ) ,
0x22 , 0x21 , V_47 , V_14 , NULL , 0 , V_6 ) ;
F_18 ( V_10 -> V_14 ) ;
return V_49 ;
}
static void F_19 ( struct V_54 * V_55 ,
struct V_43 * V_44 , struct V_56 * V_57 )
{
F_20 ( V_55 -> V_58 , V_57 ) ;
F_14 ( V_44 ) ;
}
static int F_21 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = V_55 -> V_59 ;
unsigned int V_60 ;
struct V_45 * V_46 ;
V_46 = F_15 ( V_44 ) ;
V_60 = ( ( V_46 -> V_51 ) ? V_61 : 0 ) |
( ( V_46 -> V_50 ) ? V_62 : 0 ) |
( ( V_46 -> V_63 ) ? V_64 : 0 ) |
( ( V_46 -> V_65 ) ? V_66 : 0 ) |
( ( V_46 -> V_67 ) ? V_68 : 0 ) |
( ( V_46 -> V_69 ) ? V_70 : 0 ) ;
return V_60 ;
}
static int F_22 ( struct V_54 * V_55 ,
unsigned int V_71 , unsigned int V_72 )
{
struct V_43 * V_44 = V_55 -> V_59 ;
struct V_45 * V_46 ;
V_46 = F_15 ( V_44 ) ;
if ( V_71 & V_61 )
V_46 -> V_51 = 1 ;
if ( V_71 & V_62 )
V_46 -> V_50 = 1 ;
if ( V_72 & V_61 )
V_46 -> V_51 = 0 ;
if ( V_72 & V_62 )
V_46 -> V_50 = 0 ;
return F_14 ( V_44 ) ;
}
static void F_23 ( struct V_73 * V_73 )
{
struct V_43 * V_44 ;
if ( V_73 ) {
V_44 = V_73 -> V_74 ;
F_24 ( V_73 -> V_75 ) ;
F_25 ( V_73 ) ;
}
}
static void F_26 ( struct V_73 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_74 ;
struct V_45 * V_46 = F_15 ( V_44 ) ;
struct V_33 * V_76 ;
int V_77 = V_73 -> V_77 ;
V_76 = V_44 -> V_10 -> V_39 ;
F_24 ( V_73 -> V_75 ) ;
F_27 ( V_44 -> V_10 -> V_14 ) ;
if ( V_77 )
F_10 ( & V_44 -> V_35 , L_3
L_4 , V_78 , V_77 ) ;
F_28 ( & V_46 -> V_79 ) ;
-- V_46 -> V_80 ;
F_29 ( & V_46 -> V_79 ) ;
F_28 ( & V_76 -> V_42 ) ;
-- V_76 -> V_81 ;
F_29 ( & V_76 -> V_42 ) ;
F_30 ( V_44 ) ;
}
static int F_31 ( struct V_54 * V_55 , struct V_43 * V_44 ,
const unsigned char * V_82 , int V_83 )
{
struct V_45 * V_46 ;
struct V_33 * V_76 ;
struct V_9 * V_10 = V_44 -> V_10 ;
unsigned long V_84 ;
unsigned char * V_85 ;
struct V_73 * V_73 ;
T_3 V_86 = F_32 ( ( T_3 ) V_83 , ( T_3 ) V_87 ) ;
int V_49 = 0 ;
if ( V_83 == 0 )
return 0 ;
V_46 = F_15 ( V_44 ) ;
V_76 = V_10 -> V_39 ;
F_10 ( & V_44 -> V_35 , L_5 , V_78 , V_86 ) ;
F_33 ( & V_46 -> V_79 , V_84 ) ;
F_10 ( & V_44 -> V_35 , L_6 , V_78 ,
V_46 -> V_80 ) ;
if ( V_46 -> V_80 > V_46 -> V_88 ) {
F_34 ( & V_46 -> V_79 , V_84 ) ;
F_10 ( & V_44 -> V_35 , L_7 , V_78 ) ;
return 0 ;
}
V_46 -> V_80 ++ ;
F_10 ( & V_44 -> V_35 , L_8 , V_78 ,
V_46 -> V_80 ) ;
F_34 ( & V_46 -> V_79 , V_84 ) ;
V_49 = F_35 ( V_10 -> V_14 ) ;
if ( V_49 < 0 ) {
F_33 ( & V_46 -> V_79 , V_84 ) ;
V_46 -> V_80 -- ;
F_34 ( & V_46 -> V_79 , V_84 ) ;
goto V_89;
}
V_85 = F_36 ( V_86 , V_90 ) ;
if ( ! V_85 ) {
F_37 ( & V_44 -> V_35 , L_9 ) ;
V_49 = - V_41 ;
goto V_91;
}
V_73 = F_38 ( 0 , V_90 ) ;
if ( ! V_73 ) {
F_37 ( & V_44 -> V_35 , L_10 ) ;
V_49 = - V_41 ;
goto V_92;
}
memcpy ( V_85 , V_82 , V_86 ) ;
F_39 ( V_93 , & V_44 -> V_35 , V_78 , V_86 , V_85 ) ;
F_40 ( V_73 , V_10 -> V_35 ,
F_41 ( V_10 -> V_35 ,
V_44 -> V_53 ) ,
V_85 , V_86 , F_26 , V_44 ) ;
V_73 -> V_94 |= V_95 ;
F_33 ( & V_76 -> V_42 , V_84 ) ;
if ( V_76 -> V_96 ) {
F_42 ( V_73 , & V_46 -> V_97 ) ;
F_34 ( & V_76 -> V_42 , V_84 ) ;
goto V_98;
} else {
F_42 ( V_73 , & V_46 -> V_99 ) ;
}
V_49 = F_43 ( V_73 , V_90 ) ;
if ( V_49 ) {
F_44 ( V_73 ) ;
F_34 ( & V_76 -> V_42 , V_84 ) ;
F_37 ( & V_44 -> V_35 , L_11
L_12 , V_78 , V_49 ) ;
goto error;
} else {
V_76 -> V_81 ++ ;
F_34 ( & V_76 -> V_42 , V_84 ) ;
}
V_98:
F_25 ( V_73 ) ;
return V_86 ;
error:
F_25 ( V_73 ) ;
V_92:
F_24 ( V_85 ) ;
V_91:
F_33 ( & V_46 -> V_79 , V_84 ) ;
-- V_46 -> V_80 ;
F_10 ( & V_44 -> V_35 , L_13 , V_78 ,
V_46 -> V_80 ) ;
F_34 ( & V_46 -> V_79 , V_84 ) ;
F_27 ( V_10 -> V_14 ) ;
V_89:
return V_49 ;
}
static void F_45 ( struct V_73 * V_73 )
{
int V_100 ;
int V_101 ;
struct V_43 * V_44 ;
struct V_54 * V_55 ;
unsigned char * V_34 = V_73 -> V_75 ;
int V_77 = V_73 -> V_77 ;
V_101 = F_46 ( V_73 -> V_102 ) ;
V_44 = V_73 -> V_74 ;
if ( V_77 ) {
F_10 ( & V_44 -> V_35 , L_14
L_15 , V_78 , V_77 , V_101 ) ;
} else {
if ( V_73 -> V_103 ) {
V_55 = F_47 ( & V_44 -> V_44 ) ;
if ( V_55 ) {
F_48 ( V_55 , V_34 ,
V_73 -> V_103 ) ;
F_49 ( V_55 ) ;
F_50 ( V_55 ) ;
F_39 ( V_93 , & V_44 -> V_35 ,
V_78 , V_73 -> V_103 , V_34 ) ;
}
} else {
F_10 ( & V_44 -> V_35 , L_16
L_17 , V_78 ) ;
}
}
if ( V_77 != - V_104 && V_77 != - V_105 ) {
F_51 ( V_44 -> V_10 -> V_35 ) ;
V_100 = F_43 ( V_73 , V_90 ) ;
if ( V_100 && V_100 != - V_105 )
F_37 ( & V_44 -> V_35 , L_18
L_19 , V_100 ) ;
}
}
static void F_52 ( struct V_73 * V_73 )
{
int V_100 ;
int V_77 = V_73 -> V_77 ;
struct V_43 * V_44 = V_73 -> V_74 ;
struct V_45 * V_46 = F_15 ( V_44 ) ;
struct V_9 * V_10 = V_44 -> V_10 ;
F_10 ( & V_44 -> V_35 , L_20 , V_78 ,
V_73 , V_44 , V_46 ) ;
if ( V_77 == 0 ) {
struct V_106 * V_107 =
(struct V_106 * ) V_73 -> V_75 ;
if ( ! V_107 ) {
F_10 ( & V_44 -> V_35 , L_21 ,
V_78 ) ;
return;
}
if ( ( V_107 -> V_108 == 0xA1 ) &&
( V_107 -> V_109 == 0x20 ) ) {
int V_110 ;
unsigned char V_111 = * ( ( unsigned char * )
V_73 -> V_75 +
sizeof( struct V_106 ) ) ;
struct V_54 * V_55 ;
F_10 ( & V_44 -> V_35 , L_22 , V_78 ,
V_111 ) ;
V_110 = V_46 -> V_67 ;
V_46 -> V_63 = 1 ;
V_46 -> V_67 = ( ( V_111 & 0x01 ) ? 1 : 0 ) ;
V_46 -> V_65 = ( ( V_111 & 0x02 ) ? 1 : 0 ) ;
V_46 -> V_69 = ( ( V_111 & 0x08 ) ? 1 : 0 ) ;
V_55 = F_47 ( & V_44 -> V_44 ) ;
if ( V_55 && ! F_53 ( V_55 ) &&
V_110 && ! V_46 -> V_67 )
F_54 ( V_55 ) ;
F_50 ( V_55 ) ;
} else {
F_10 ( & V_44 -> V_35 , L_23 ,
V_78 , V_107 -> V_108 ,
V_107 -> V_109 ) ;
}
} else
F_10 ( & V_44 -> V_35 , L_24 , V_78 , V_77 ) ;
if ( V_77 != - V_104 && V_77 != - V_112 ) {
F_51 ( V_10 -> V_35 ) ;
V_100 = F_43 ( V_73 , V_90 ) ;
if ( V_100 && V_100 != - V_105 )
F_37 ( & V_44 -> V_35 , L_25
L_26 , V_78 , V_100 ) ;
}
}
static int F_55 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = V_55 -> V_59 ;
struct V_45 * V_46 = F_15 ( V_44 ) ;
unsigned long V_84 ;
F_33 ( & V_46 -> V_79 , V_84 ) ;
if ( V_46 -> V_80 > ( V_46 -> V_88 * 2 ) / 3 ) {
F_34 ( & V_46 -> V_79 , V_84 ) ;
F_10 ( & V_44 -> V_35 , L_7 , V_78 ) ;
return 0 ;
}
F_34 ( & V_46 -> V_79 , V_84 ) ;
return 2048 ;
}
static void F_56 ( struct V_43 * V_44 )
{
int V_22 ;
struct V_45 * V_46 = F_15 ( V_44 ) ;
for ( V_22 = 0 ; V_22 < V_46 -> V_113 ; V_22 ++ )
F_57 ( V_46 -> V_114 [ V_22 ] ) ;
F_57 ( V_44 -> V_52 ) ;
}
static int F_58 ( struct V_43 * V_44 , T_4 V_115 )
{
int V_116 ;
int V_100 = - V_117 ;
int V_22 ;
struct V_73 * V_73 ;
struct V_45 * V_46 = F_15 ( V_44 ) ;
V_116 = 0 ;
for ( V_22 = 0 ; V_22 < V_46 -> V_113 ; V_22 ++ ) {
V_73 = V_46 -> V_114 [ V_22 ] ;
if ( ! V_73 )
continue;
V_100 = F_43 ( V_73 , V_115 ) ;
if ( V_100 ) {
F_37 ( & V_44 -> V_35 , L_27 ,
V_78 , V_100 ) ;
} else {
V_116 ++ ;
}
}
if ( V_116 && V_44 -> V_52 ) {
V_100 = F_43 ( V_44 -> V_52 , V_115 ) ;
if ( V_100 ) {
F_37 ( & V_44 -> V_35 , L_28 ,
V_78 , V_100 ) ;
}
}
if ( V_116 > 0 )
return 0 ;
else
return V_100 ;
}
static struct V_73 * F_59 ( struct V_9 * V_10 , int V_101 ,
int V_118 , void * V_119 , int V_120 ,
T_4 V_115 ,
T_5 V_121 )
{
struct V_73 * V_73 ;
T_2 * V_82 ;
if ( V_101 == - 1 )
return NULL ;
V_73 = F_38 ( 0 , V_115 ) ;
if ( V_73 == NULL ) {
F_10 ( & V_10 -> V_35 -> V_35 , L_29 ,
V_78 , V_101 ) ;
return NULL ;
}
V_82 = F_36 ( V_120 , V_115 ) ;
if ( V_82 ) {
F_40 ( V_73 , V_10 -> V_35 ,
F_41 ( V_10 -> V_35 , V_101 ) | V_118 ,
V_82 , V_120 , V_121 , V_119 ) ;
F_10 ( & V_10 -> V_35 -> V_35 , L_30 , V_78 ,
V_118 == V_122 ? 'i' : 'o' , V_73 , V_82 ) ;
} else {
F_10 ( & V_10 -> V_35 -> V_35 , L_31 , V_78 ,
V_118 == V_122 ? 'i' : 'o' , V_73 , V_82 ) ;
F_23 ( V_73 ) ;
V_73 = NULL ;
}
return V_73 ;
}
static void F_60 ( struct V_43 * V_44 )
{
int V_22 ;
struct V_9 * V_10 = V_44 -> V_10 ;
struct V_45 * V_46 ;
struct V_33 * V_76 = V_44 -> V_10 -> V_39 ;
V_46 = F_15 ( V_44 ) ;
V_46 -> V_51 = 0 ;
V_46 -> V_50 = 0 ;
if ( V_10 -> V_35 ) {
F_61 ( & V_10 -> V_123 ) ;
if ( ! V_10 -> V_124 ) {
V_10 -> V_14 -> V_125 = 0 ;
if ( ! F_16 ( V_10 -> V_14 ) )
F_14 ( V_44 ) ;
else
F_62 ( V_10 -> V_14 ) ;
}
F_63 ( & V_10 -> V_123 ) ;
F_64 ( & V_76 -> V_42 ) ;
V_46 -> V_126 = 0 ;
F_65 ( & V_76 -> V_42 ) ;
F_56 ( V_44 ) ;
for ( V_22 = 0 ; V_22 < V_46 -> V_113 ; V_22 ++ ) {
F_23 ( V_46 -> V_114 [ V_22 ] ) ;
V_46 -> V_114 [ V_22 ] = NULL ;
}
}
}
static int F_66 ( struct V_54 * V_55 , struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_9 * V_10 = V_44 -> V_10 ;
struct V_33 * V_76 = V_10 -> V_39 ;
int V_22 ;
int V_100 ;
int V_101 ;
struct V_73 * V_73 ;
V_46 = F_15 ( V_44 ) ;
V_46 -> V_51 = 1 ;
V_46 -> V_50 = 1 ;
V_101 = V_44 -> V_127 ;
for ( V_22 = 0 ; V_22 < V_46 -> V_113 ; V_22 ++ ) {
V_73 = F_59 ( V_10 , V_101 , V_122 , V_44 ,
V_128 , V_40 ,
F_45 ) ;
V_46 -> V_114 [ V_22 ] = V_73 ;
}
F_67 ( V_10 -> V_35 ,
F_41 ( V_10 -> V_35 , V_101 ) | V_122 ) ;
V_100 = F_58 ( V_44 , V_40 ) ;
if ( V_100 ) {
F_60 ( V_44 ) ;
if ( ! V_10 -> V_124 )
F_18 ( V_10 -> V_14 ) ;
return V_100 ;
}
F_14 ( V_44 ) ;
V_10 -> V_14 -> V_125 = 1 ;
F_64 ( & V_76 -> V_42 ) ;
V_46 -> V_126 = 1 ;
F_65 ( & V_76 -> V_42 ) ;
F_18 ( V_10 -> V_14 ) ;
return 0 ;
}
static void F_68 ( struct V_43 * V_44 , int V_129 )
{
struct V_9 * V_10 = V_44 -> V_10 ;
struct V_45 * V_46 ;
V_46 = F_15 ( V_44 ) ;
V_46 -> V_51 = V_129 ;
V_46 -> V_50 = V_129 ;
if ( V_10 -> V_35 ) {
F_61 ( & V_10 -> V_123 ) ;
if ( ! V_10 -> V_124 )
F_14 ( V_44 ) ;
F_63 ( & V_10 -> V_123 ) ;
}
}
static int F_69 ( struct V_9 * V_10 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_19 * V_130 = NULL ;
int V_22 ;
T_2 V_12 ;
F_1 ( V_10 -> V_35 , 0x0000 ) ;
if ( V_131 )
F_4 ( V_10 -> V_35 , 1 ) ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; V_22 ++ ) {
V_44 = V_10 -> V_44 [ V_22 ] ;
V_46 = F_12 ( sizeof( * V_46 ) , V_40 ) ;
if ( ! V_46 ) {
F_10 ( & V_44 -> V_35 , L_32
L_33 ,
V_78 , V_22 ) ;
return - V_41 ;
}
F_13 ( & V_46 -> V_79 ) ;
F_70 ( & V_46 -> V_99 ) ;
F_70 ( & V_46 -> V_97 ) ;
V_12 = V_22 ;
V_46 -> V_88 = V_132 ;
V_46 -> V_113 = V_133 ;
if ( V_10 -> V_11 == 1 ) {
V_12 = F_8 ( V_10 ) ;
V_130 =
(struct V_19 * ) & V_134 ;
if ( F_7 ( V_12 , V_130 ) ) {
V_46 -> V_88 = V_135 ;
V_46 -> V_113 = V_136 ;
}
}
else {
V_130 =
(struct V_19 * ) & V_137 ;
if ( F_7 ( V_22 , V_130 ) ) {
V_46 -> V_88 = V_135 ;
V_46 -> V_113 = V_136 ;
}
}
F_10 ( & V_10 -> V_35 -> V_35 ,
L_34 ,
V_12 , V_46 -> V_113 , V_46 -> V_88 ) ;
F_71 ( V_44 , V_46 ) ;
}
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
int V_22 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; ++ V_22 ) {
V_44 = V_10 -> V_44 [ V_22 ] ;
if ( ! V_44 )
continue;
V_46 = F_15 ( V_44 ) ;
if ( ! V_46 )
continue;
F_24 ( V_46 ) ;
}
}
static void F_73 ( struct V_9 * V_10 )
{
int V_22 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; ++ V_22 ) {
V_44 = V_10 -> V_44 [ V_22 ] ;
V_46 = F_15 ( V_44 ) ;
F_56 ( V_44 ) ;
F_74 ( & V_46 -> V_99 ) ;
}
}
static int F_75 ( struct V_9 * V_10 , T_6 V_138 )
{
struct V_33 * V_76 ;
int V_139 ;
if ( F_76 ( V_138 ) ) {
V_76 = V_10 -> V_39 ;
F_64 ( & V_76 -> V_42 ) ;
V_139 = V_76 -> V_81 ;
if ( V_139 ) {
F_65 ( & V_76 -> V_42 ) ;
return - V_140 ;
} else {
V_76 -> V_96 = 1 ;
F_65 ( & V_76 -> V_42 ) ;
}
}
F_73 ( V_10 ) ;
return 0 ;
}
static int F_77 ( struct V_9 * V_10 )
{
struct V_43 * V_44 ;
struct V_33 * V_76 = V_10 -> V_39 ;
struct V_45 * V_46 ;
struct V_73 * V_73 ;
int V_141 = 0 ;
int V_22 , V_100 ;
F_64 ( & V_76 -> V_42 ) ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; V_22 ++ ) {
V_44 = V_10 -> V_44 [ V_22 ] ;
V_46 = F_15 ( V_44 ) ;
while ( ( V_73 = F_78 ( & V_46 -> V_97 ) ) ) {
F_42 ( V_73 , & V_46 -> V_99 ) ;
V_76 -> V_81 ++ ;
V_100 = F_43 ( V_73 , V_90 ) ;
if ( V_100 < 0 ) {
V_76 -> V_81 -- ;
F_44 ( V_73 ) ;
F_79 ( & V_46 -> V_97 ) ;
break;
}
}
if ( V_46 -> V_126 ) {
V_100 = F_58 ( V_44 , V_90 ) ;
if ( V_100 )
V_141 ++ ;
}
}
V_76 -> V_96 = 0 ;
F_65 ( & V_76 -> V_42 ) ;
return V_141 ? - V_142 : 0 ;
}
