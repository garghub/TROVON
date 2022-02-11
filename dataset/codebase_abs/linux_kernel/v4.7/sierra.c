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
V_43 = F_2 ( V_10 -> V_33 , F_3 ( V_10 -> V_33 , 0 ) ,
0x22 , 0x21 , V_41 , V_14 , NULL , 0 , V_6 ) ;
F_15 ( V_10 -> V_14 ) ;
return V_43 ;
}
static int F_16 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_50 ;
unsigned int V_51 ;
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
V_51 = ( ( V_40 -> V_45 ) ? V_52 : 0 ) |
( ( V_40 -> V_44 ) ? V_53 : 0 ) |
( ( V_40 -> V_54 ) ? V_55 : 0 ) |
( ( V_40 -> V_56 ) ? V_57 : 0 ) |
( ( V_40 -> V_58 ) ? V_59 : 0 ) |
( ( V_40 -> V_60 ) ? V_61 : 0 ) ;
return V_51 ;
}
static int F_17 ( struct V_48 * V_49 ,
unsigned int V_62 , unsigned int V_63 )
{
struct V_37 * V_38 = V_49 -> V_50 ;
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
if ( V_62 & V_52 )
V_40 -> V_45 = 1 ;
if ( V_62 & V_53 )
V_40 -> V_44 = 1 ;
if ( V_63 & V_52 )
V_40 -> V_45 = 0 ;
if ( V_63 & V_53 )
V_40 -> V_44 = 0 ;
return F_12 ( V_38 ) ;
}
static void F_18 ( struct V_64 * V_64 )
{
if ( V_64 ) {
F_19 ( V_64 -> V_65 ) ;
F_20 ( V_64 ) ;
}
}
static void F_21 ( struct V_64 * V_64 )
{
struct V_37 * V_38 = V_64 -> V_66 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_67 * V_68 ;
int V_69 = V_64 -> V_69 ;
V_68 = F_22 ( V_38 -> V_10 ) ;
F_19 ( V_64 -> V_65 ) ;
F_23 ( V_38 -> V_10 -> V_14 ) ;
if ( V_69 )
F_10 ( & V_38 -> V_33 , L_3
L_4 , V_70 , V_69 ) ;
F_24 ( & V_40 -> V_71 ) ;
-- V_40 -> V_72 ;
F_25 ( & V_40 -> V_71 ) ;
F_24 ( & V_68 -> V_73 ) ;
-- V_68 -> V_74 ;
F_25 ( & V_68 -> V_73 ) ;
F_26 ( V_38 ) ;
}
static int F_27 ( struct V_48 * V_49 , struct V_37 * V_38 ,
const unsigned char * V_75 , int V_76 )
{
struct V_39 * V_40 ;
struct V_67 * V_68 ;
struct V_9 * V_10 = V_38 -> V_10 ;
unsigned long V_77 ;
unsigned char * V_78 ;
struct V_64 * V_64 ;
T_3 V_79 = F_28 ( ( T_3 ) V_76 , ( T_3 ) V_80 ) ;
int V_43 = 0 ;
if ( V_76 == 0 )
return 0 ;
V_40 = F_13 ( V_38 ) ;
V_68 = F_22 ( V_10 ) ;
F_10 ( & V_38 -> V_33 , L_5 , V_70 , V_79 ) ;
F_29 ( & V_40 -> V_71 , V_77 ) ;
F_10 ( & V_38 -> V_33 , L_6 , V_70 ,
V_40 -> V_72 ) ;
if ( V_40 -> V_72 > V_40 -> V_81 ) {
F_30 ( & V_40 -> V_71 , V_77 ) ;
F_10 ( & V_38 -> V_33 , L_7 , V_70 ) ;
return 0 ;
}
V_40 -> V_72 ++ ;
F_10 ( & V_38 -> V_33 , L_8 , V_70 ,
V_40 -> V_72 ) ;
F_30 ( & V_40 -> V_71 , V_77 ) ;
V_43 = F_31 ( V_10 -> V_14 ) ;
if ( V_43 < 0 ) {
F_29 ( & V_40 -> V_71 , V_77 ) ;
V_40 -> V_72 -- ;
F_30 ( & V_40 -> V_71 , V_77 ) ;
goto V_82;
}
V_78 = F_32 ( V_79 , V_83 ) ;
if ( ! V_78 ) {
V_43 = - V_84 ;
goto V_85;
}
V_64 = F_33 ( 0 , V_83 ) ;
if ( ! V_64 ) {
V_43 = - V_84 ;
goto V_86;
}
memcpy ( V_78 , V_75 , V_79 ) ;
F_34 ( & V_38 -> V_33 , V_70 , V_79 , V_78 ) ;
F_35 ( V_64 , V_10 -> V_33 ,
F_36 ( V_10 -> V_33 ,
V_38 -> V_47 ) ,
V_78 , V_79 , F_21 , V_38 ) ;
V_64 -> V_87 |= V_88 ;
F_29 ( & V_68 -> V_73 , V_77 ) ;
if ( V_68 -> V_89 ) {
F_37 ( V_64 , & V_40 -> V_90 ) ;
F_30 ( & V_68 -> V_73 , V_77 ) ;
goto V_91;
} else {
F_37 ( V_64 , & V_40 -> V_92 ) ;
}
V_43 = F_38 ( V_64 , V_83 ) ;
if ( V_43 ) {
F_39 ( V_64 ) ;
F_30 ( & V_68 -> V_73 , V_77 ) ;
F_40 ( & V_38 -> V_33 , L_9
L_10 , V_70 , V_43 ) ;
goto error;
} else {
V_68 -> V_74 ++ ;
F_30 ( & V_68 -> V_73 , V_77 ) ;
}
V_91:
F_20 ( V_64 ) ;
return V_79 ;
error:
F_20 ( V_64 ) ;
V_86:
F_19 ( V_78 ) ;
V_85:
F_29 ( & V_40 -> V_71 , V_77 ) ;
-- V_40 -> V_72 ;
F_10 ( & V_38 -> V_33 , L_11 , V_70 ,
V_40 -> V_72 ) ;
F_30 ( & V_40 -> V_71 , V_77 ) ;
F_23 ( V_10 -> V_14 ) ;
V_82:
return V_43 ;
}
static void F_41 ( struct V_64 * V_64 )
{
int V_93 ;
int V_94 ;
struct V_37 * V_38 ;
unsigned char * V_95 = V_64 -> V_65 ;
int V_69 = V_64 -> V_69 ;
V_94 = F_42 ( V_64 -> V_96 ) ;
V_38 = V_64 -> V_66 ;
if ( V_69 ) {
F_10 ( & V_38 -> V_33 , L_12
L_13 , V_70 , V_69 , V_94 ) ;
} else {
if ( V_64 -> V_97 ) {
F_43 ( & V_38 -> V_38 , V_95 ,
V_64 -> V_97 ) ;
F_44 ( & V_38 -> V_38 ) ;
F_34 ( & V_38 -> V_33 , V_70 ,
V_64 -> V_97 , V_95 ) ;
} else {
F_10 ( & V_38 -> V_33 , L_14
L_15 , V_70 ) ;
}
}
if ( V_69 != - V_98 && V_69 != - V_99 ) {
F_45 ( V_38 -> V_10 -> V_33 ) ;
V_93 = F_38 ( V_64 , V_83 ) ;
if ( V_93 && V_93 != - V_99 )
F_40 ( & V_38 -> V_33 , L_16
L_17 , V_93 ) ;
}
}
static void F_46 ( struct V_64 * V_64 )
{
int V_93 ;
int V_69 = V_64 -> V_69 ;
struct V_37 * V_38 = V_64 -> V_66 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_9 * V_10 = V_38 -> V_10 ;
F_10 ( & V_38 -> V_33 , L_18 , V_70 ,
V_64 , V_38 , V_40 ) ;
if ( V_69 == 0 ) {
struct V_100 * V_101 =
(struct V_100 * ) V_64 -> V_65 ;
if ( ! V_101 ) {
F_10 ( & V_38 -> V_33 , L_19 ,
V_70 ) ;
return;
}
if ( ( V_101 -> V_102 == 0xA1 ) &&
( V_101 -> V_103 == 0x20 ) ) {
int V_104 ;
unsigned char V_105 = * ( ( unsigned char * )
V_64 -> V_65 +
sizeof( struct V_100 ) ) ;
F_10 ( & V_38 -> V_33 , L_20 , V_70 ,
V_105 ) ;
V_104 = V_40 -> V_58 ;
V_40 -> V_54 = 1 ;
V_40 -> V_58 = ( ( V_105 & 0x01 ) ? 1 : 0 ) ;
V_40 -> V_56 = ( ( V_105 & 0x02 ) ? 1 : 0 ) ;
V_40 -> V_60 = ( ( V_105 & 0x08 ) ? 1 : 0 ) ;
if ( V_104 && ! V_40 -> V_58 )
F_47 ( & V_38 -> V_38 , true ) ;
} else {
F_10 ( & V_38 -> V_33 , L_21 ,
V_70 , V_101 -> V_102 ,
V_101 -> V_103 ) ;
}
} else
F_10 ( & V_38 -> V_33 , L_22 , V_70 , V_69 ) ;
if ( V_69 != - V_98 && V_69 != - V_106 ) {
F_45 ( V_10 -> V_33 ) ;
V_93 = F_38 ( V_64 , V_83 ) ;
if ( V_93 && V_93 != - V_99 )
F_40 ( & V_38 -> V_33 , L_23
L_24 , V_70 , V_93 ) ;
}
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_50 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
unsigned long V_77 ;
F_29 ( & V_40 -> V_71 , V_77 ) ;
if ( V_40 -> V_72 > ( V_40 -> V_81 * 2 ) / 3 ) {
F_30 ( & V_40 -> V_71 , V_77 ) ;
F_10 ( & V_38 -> V_33 , L_7 , V_70 ) ;
return 0 ;
}
F_30 ( & V_40 -> V_71 , V_77 ) ;
return 2048 ;
}
static int F_49 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_50 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
unsigned long V_77 ;
int V_107 ;
F_29 ( & V_40 -> V_71 , V_77 ) ;
V_107 = V_40 -> V_72 * V_80 ;
F_30 ( & V_40 -> V_71 , V_77 ) ;
F_10 ( & V_38 -> V_33 , L_25 , V_70 , V_107 ) ;
return V_107 ;
}
static void F_50 ( struct V_37 * V_38 )
{
int V_22 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_108 ; V_22 ++ )
F_51 ( V_40 -> V_109 [ V_22 ] ) ;
F_51 ( V_38 -> V_46 ) ;
}
static int F_52 ( struct V_37 * V_38 , T_4 V_110 )
{
int V_111 ;
int V_93 = - V_112 ;
int V_22 ;
struct V_64 * V_64 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
V_111 = 0 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_108 ; V_22 ++ ) {
V_64 = V_40 -> V_109 [ V_22 ] ;
if ( ! V_64 )
continue;
V_93 = F_38 ( V_64 , V_110 ) ;
if ( V_93 ) {
F_40 ( & V_38 -> V_33 , L_26 ,
V_70 , V_93 ) ;
} else {
V_111 ++ ;
}
}
if ( V_111 && V_38 -> V_46 ) {
V_93 = F_38 ( V_38 -> V_46 , V_110 ) ;
if ( V_93 ) {
F_40 ( & V_38 -> V_33 , L_27 ,
V_70 , V_93 ) ;
}
}
if ( V_111 > 0 )
return 0 ;
else
return V_93 ;
}
static struct V_64 * F_53 ( struct V_9 * V_10 , int V_94 ,
int V_113 , void * V_114 , int V_115 ,
T_4 V_110 ,
T_5 V_116 )
{
struct V_64 * V_64 ;
T_2 * V_75 ;
V_64 = F_33 ( 0 , V_110 ) ;
if ( ! V_64 )
return NULL ;
V_75 = F_32 ( V_115 , V_110 ) ;
if ( V_75 ) {
F_35 ( V_64 , V_10 -> V_33 ,
F_36 ( V_10 -> V_33 , V_94 ) | V_113 ,
V_75 , V_115 , V_116 , V_114 ) ;
F_10 ( & V_10 -> V_33 -> V_33 , L_28 , V_70 ,
V_113 == V_117 ? 'i' : 'o' , V_64 , V_75 ) ;
} else {
F_18 ( V_64 ) ;
V_64 = NULL ;
}
return V_64 ;
}
static void F_54 ( struct V_37 * V_38 )
{
int V_22 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_39 * V_40 ;
struct V_67 * V_68 = F_22 ( V_10 ) ;
struct V_64 * V_64 ;
V_40 = F_13 ( V_38 ) ;
F_55 ( & V_68 -> V_73 ) ;
if ( -- V_68 -> V_118 == 0 )
V_10 -> V_14 -> V_119 = 0 ;
F_56 ( & V_68 -> V_73 ) ;
for (; ; ) {
V_64 = F_57 ( & V_40 -> V_90 ) ;
if ( ! V_64 )
break;
F_19 ( V_64 -> V_65 ) ;
F_20 ( V_64 ) ;
F_23 ( V_10 -> V_14 ) ;
F_24 ( & V_40 -> V_71 ) ;
V_40 -> V_72 -- ;
F_25 ( & V_40 -> V_71 ) ;
}
F_50 ( V_38 ) ;
F_58 ( & V_40 -> V_92 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_108 ; V_22 ++ ) {
F_18 ( V_40 -> V_109 [ V_22 ] ) ;
V_40 -> V_109 [ V_22 ] = NULL ;
}
F_59 ( V_10 -> V_14 ) ;
}
static int F_60 ( struct V_48 * V_49 , struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_67 * V_68 = F_22 ( V_10 ) ;
int V_22 ;
int V_93 ;
int V_94 ;
struct V_64 * V_64 ;
V_40 = F_13 ( V_38 ) ;
V_94 = V_38 -> V_120 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_108 ; V_22 ++ ) {
V_64 = F_53 ( V_10 , V_94 , V_117 , V_38 ,
V_121 , V_122 ,
F_41 ) ;
V_40 -> V_109 [ V_22 ] = V_64 ;
}
F_61 ( V_10 -> V_33 ,
F_36 ( V_10 -> V_33 , V_94 ) | V_117 ) ;
V_93 = F_52 ( V_38 , V_122 ) ;
if ( V_93 )
goto V_123;
F_55 ( & V_68 -> V_73 ) ;
if ( ++ V_68 -> V_118 == 1 )
V_10 -> V_14 -> V_119 = 1 ;
F_56 ( & V_68 -> V_73 ) ;
F_15 ( V_10 -> V_14 ) ;
return 0 ;
V_123:
F_50 ( V_38 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_108 ; V_22 ++ ) {
F_18 ( V_40 -> V_109 [ V_22 ] ) ;
V_40 -> V_109 [ V_22 ] = NULL ;
}
return V_93 ;
}
static void F_62 ( struct V_37 * V_38 , int V_124 )
{
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
V_40 -> V_45 = V_124 ;
V_40 -> V_44 = V_124 ;
F_12 ( V_38 ) ;
}
static int F_63 ( struct V_9 * V_10 )
{
struct V_67 * V_68 ;
V_68 = F_64 ( sizeof( * V_68 ) , V_122 ) ;
if ( ! V_68 )
return - V_84 ;
F_65 ( & V_68 -> V_73 ) ;
F_66 ( V_10 , V_68 ) ;
F_1 ( V_10 -> V_33 , 0x0000 ) ;
if ( V_125 )
F_4 ( V_10 -> V_33 , 1 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_67 * V_68 ;
V_68 = F_22 ( V_10 ) ;
F_19 ( V_68 ) ;
}
static int F_68 ( struct V_37 * V_38 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_39 * V_40 ;
const struct V_19 * V_126 ;
T_2 V_12 ;
V_40 = F_64 ( sizeof( * V_40 ) , V_122 ) ;
if ( ! V_40 )
return - V_84 ;
F_65 ( & V_40 -> V_71 ) ;
F_69 ( & V_40 -> V_92 ) ;
F_69 ( & V_40 -> V_90 ) ;
V_40 -> V_81 = V_127 ;
V_40 -> V_108 = V_128 ;
if ( V_10 -> V_11 == 1 ) {
V_12 = F_8 ( V_10 ) ;
V_126 = & V_129 ;
} else {
V_12 = V_38 -> V_130 ;
V_126 = & V_131 ;
}
if ( F_7 ( V_12 , V_126 ) ) {
V_40 -> V_81 = V_132 ;
V_40 -> V_108 = V_133 ;
}
F_10 ( & V_38 -> V_33 ,
L_29 ,
V_12 , V_40 -> V_108 , V_40 -> V_81 ) ;
F_70 ( V_38 , V_40 ) ;
return 0 ;
}
static int F_71 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 ) ;
F_70 ( V_38 , NULL ) ;
F_19 ( V_40 ) ;
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
int V_22 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; ++ V_22 ) {
V_38 = V_10 -> V_38 [ V_22 ] ;
V_40 = F_13 ( V_38 ) ;
if ( ! V_40 )
continue;
F_50 ( V_38 ) ;
F_58 ( & V_40 -> V_92 ) ;
}
}
static int F_73 ( struct V_9 * V_10 , T_6 V_134 )
{
struct V_67 * V_68 = F_22 ( V_10 ) ;
F_55 ( & V_68 -> V_73 ) ;
if ( F_74 ( V_134 ) ) {
if ( V_68 -> V_74 ) {
F_56 ( & V_68 -> V_73 ) ;
return - V_135 ;
}
}
V_68 -> V_89 = 1 ;
F_56 ( & V_68 -> V_73 ) ;
F_72 ( V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_67 * V_68 ;
struct V_64 * V_64 ;
int V_136 = 0 ;
int V_93 ;
V_68 = F_22 ( V_38 -> V_10 ) ;
for (; ; ) {
V_64 = F_57 ( & V_40 -> V_90 ) ;
if ( ! V_64 )
break;
F_37 ( V_64 , & V_40 -> V_92 ) ;
V_68 -> V_74 ++ ;
V_93 = F_38 ( V_64 , V_83 ) ;
if ( V_93 ) {
F_40 ( & V_38 -> V_33 , L_30 ,
V_70 , V_93 ) ;
V_136 ++ ;
V_68 -> V_74 -- ;
F_39 ( V_64 ) ;
F_19 ( V_64 -> V_65 ) ;
F_20 ( V_64 ) ;
F_24 ( & V_40 -> V_71 ) ;
V_40 -> V_72 -- ;
F_25 ( & V_40 -> V_71 ) ;
}
}
if ( V_136 )
return - V_137 ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 )
{
struct V_37 * V_38 ;
struct V_67 * V_68 = F_22 ( V_10 ) ;
int V_136 = 0 ;
int V_22 , V_93 ;
F_55 ( & V_68 -> V_73 ) ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; V_22 ++ ) {
V_38 = V_10 -> V_38 [ V_22 ] ;
if ( ! F_77 ( & V_38 -> V_38 ) )
continue;
V_93 = F_75 ( V_38 ) ;
if ( V_93 )
V_136 ++ ;
V_93 = F_52 ( V_38 , V_83 ) ;
if ( V_93 )
V_136 ++ ;
}
V_68 -> V_89 = 0 ;
F_56 ( & V_68 -> V_73 ) ;
return V_136 ? - V_137 : 0 ;
}
