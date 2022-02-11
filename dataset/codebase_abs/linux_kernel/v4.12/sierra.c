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
static int F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
int V_13 = 0 ;
T_2 V_14 , V_15 ;
V_14 = V_10 -> V_16 -> V_17 -> V_18 . V_19 ;
V_15 = V_10 -> V_16 -> V_17 -> V_18 . V_20 ;
if ( V_14 == 0x99 )
V_13 = 0 ;
else if ( V_15 <= 3 )
V_13 = 1 ;
else
V_13 = ( V_15 - 1 ) / 2 ;
return V_13 ;
}
static int F_6 ( const T_2 V_14 ,
const struct V_21 * V_22 )
{
const T_2 * V_23 ;
int V_24 ;
if ( V_22 ) {
V_23 = V_22 -> V_25 ;
for ( V_24 = 0 ; V_24 < V_22 -> V_26 ; V_24 ++ ) {
if ( V_23 [ V_24 ] == V_14 )
return 1 ;
}
}
return 0 ;
}
static int F_7 ( const T_2 V_14 ,
const struct V_21 * V_27 )
{
const T_2 * V_23 ;
int V_24 ;
if ( V_27 ) {
V_23 = V_27 -> V_25 ;
for ( V_24 = 0 ; V_24 < V_27 -> V_26 ; V_24 ++ ) {
if ( V_23 [ V_24 ] == V_14 )
return 1 ;
}
}
return 0 ;
}
static T_2 F_8 ( struct V_9 * V_10 )
{
return V_10 -> V_16 -> V_17 -> V_18 . V_19 ;
}
static int F_9 ( struct V_9 * V_10 ,
const struct V_28 * V_29 )
{
int V_30 = 0 ;
struct V_1 * V_2 ;
T_2 V_14 ;
V_2 = V_10 -> V_31 ;
V_14 = F_8 ( V_10 ) ;
if ( V_10 -> V_16 -> V_32 == 2 ) {
F_10 ( & V_2 -> V_31 , L_1 ,
V_14 ) ;
F_11 ( V_2 , V_14 , 1 ) ;
}
if ( F_6 ( V_14 ,
(struct V_21 * ) V_29 -> V_33 ) ) {
F_10 ( & V_10 -> V_31 -> V_31 ,
L_2 , V_14 ) ;
return - V_34 ;
}
return V_30 ;
}
static int F_12 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_37 * V_38 ;
T_1 V_16 = 0 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 ;
V_38 = F_13 ( V_36 ) ;
if ( V_38 -> V_42 )
V_39 |= 0x01 ;
if ( V_38 -> V_43 )
V_39 |= 0x02 ;
if ( V_10 -> V_13 == 1 ) {
V_16 = F_8 ( V_10 ) ;
if ( V_36 -> V_44 ) {
V_40 = 1 ;
}
}
else {
if ( V_36 -> V_45 == 2 )
V_16 = 0 ;
else if ( V_36 -> V_45 == 4 )
V_16 = 1 ;
else if ( V_36 -> V_45 == 5 )
V_16 = 2 ;
V_40 = 1 ;
}
if ( ! V_40 )
return 0 ;
V_41 = F_14 ( V_10 -> V_16 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_2 ( V_10 -> V_31 , F_3 ( V_10 -> V_31 , 0 ) ,
0x22 , 0x21 , V_39 , V_16 , NULL , 0 , V_6 ) ;
F_15 ( V_10 -> V_16 ) ;
return V_41 ;
}
static int F_16 ( struct V_46 * V_47 )
{
struct V_35 * V_36 = V_47 -> V_48 ;
unsigned int V_49 ;
struct V_37 * V_38 ;
V_38 = F_13 ( V_36 ) ;
V_49 = ( ( V_38 -> V_43 ) ? V_50 : 0 ) |
( ( V_38 -> V_42 ) ? V_51 : 0 ) |
( ( V_38 -> V_52 ) ? V_53 : 0 ) |
( ( V_38 -> V_54 ) ? V_55 : 0 ) |
( ( V_38 -> V_56 ) ? V_57 : 0 ) |
( ( V_38 -> V_58 ) ? V_59 : 0 ) ;
return V_49 ;
}
static int F_17 ( struct V_46 * V_47 ,
unsigned int V_60 , unsigned int V_61 )
{
struct V_35 * V_36 = V_47 -> V_48 ;
struct V_37 * V_38 ;
V_38 = F_13 ( V_36 ) ;
if ( V_60 & V_50 )
V_38 -> V_43 = 1 ;
if ( V_60 & V_51 )
V_38 -> V_42 = 1 ;
if ( V_61 & V_50 )
V_38 -> V_43 = 0 ;
if ( V_61 & V_51 )
V_38 -> V_42 = 0 ;
return F_12 ( V_36 ) ;
}
static void F_18 ( struct V_62 * V_62 )
{
if ( V_62 ) {
F_19 ( V_62 -> V_63 ) ;
F_20 ( V_62 ) ;
}
}
static void F_21 ( struct V_62 * V_62 )
{
struct V_35 * V_36 = V_62 -> V_64 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
struct V_65 * V_66 ;
int V_67 = V_62 -> V_67 ;
V_66 = F_22 ( V_36 -> V_10 ) ;
F_19 ( V_62 -> V_63 ) ;
F_23 ( V_36 -> V_10 -> V_16 ) ;
if ( V_67 )
F_10 ( & V_36 -> V_31 , L_3
L_4 , V_68 , V_67 ) ;
F_24 ( & V_38 -> V_69 ) ;
-- V_38 -> V_70 ;
F_25 ( & V_38 -> V_69 ) ;
F_24 ( & V_66 -> V_71 ) ;
-- V_66 -> V_72 ;
F_25 ( & V_66 -> V_71 ) ;
F_26 ( V_36 ) ;
}
static int F_27 ( struct V_46 * V_47 , struct V_35 * V_36 ,
const unsigned char * V_73 , int V_74 )
{
struct V_37 * V_38 ;
struct V_65 * V_66 ;
struct V_9 * V_10 = V_36 -> V_10 ;
unsigned long V_75 ;
unsigned char * V_76 ;
struct V_62 * V_62 ;
T_3 V_77 = F_28 ( ( T_3 ) V_74 , ( T_3 ) V_78 ) ;
int V_41 = 0 ;
if ( V_74 == 0 )
return 0 ;
V_38 = F_13 ( V_36 ) ;
V_66 = F_22 ( V_10 ) ;
F_10 ( & V_36 -> V_31 , L_5 , V_68 , V_77 ) ;
F_29 ( & V_38 -> V_69 , V_75 ) ;
F_10 ( & V_36 -> V_31 , L_6 , V_68 ,
V_38 -> V_70 ) ;
if ( V_38 -> V_70 > V_38 -> V_79 ) {
F_30 ( & V_38 -> V_69 , V_75 ) ;
F_10 ( & V_36 -> V_31 , L_7 , V_68 ) ;
return 0 ;
}
V_38 -> V_70 ++ ;
F_10 ( & V_36 -> V_31 , L_8 , V_68 ,
V_38 -> V_70 ) ;
F_30 ( & V_38 -> V_69 , V_75 ) ;
V_41 = F_31 ( V_10 -> V_16 ) ;
if ( V_41 < 0 ) {
F_29 ( & V_38 -> V_69 , V_75 ) ;
V_38 -> V_70 -- ;
F_30 ( & V_38 -> V_69 , V_75 ) ;
goto V_80;
}
V_76 = F_32 ( V_77 , V_81 ) ;
if ( ! V_76 ) {
V_41 = - V_82 ;
goto V_83;
}
V_62 = F_33 ( 0 , V_81 ) ;
if ( ! V_62 ) {
V_41 = - V_82 ;
goto V_84;
}
memcpy ( V_76 , V_73 , V_77 ) ;
F_34 ( & V_36 -> V_31 , V_68 , V_77 , V_76 ) ;
F_35 ( V_62 , V_10 -> V_31 ,
F_36 ( V_10 -> V_31 ,
V_36 -> V_45 ) ,
V_76 , V_77 , F_21 , V_36 ) ;
V_62 -> V_85 |= V_86 ;
F_29 ( & V_66 -> V_71 , V_75 ) ;
if ( V_66 -> V_87 ) {
F_37 ( V_62 , & V_38 -> V_88 ) ;
F_30 ( & V_66 -> V_71 , V_75 ) ;
goto V_89;
} else {
F_37 ( V_62 , & V_38 -> V_90 ) ;
}
V_41 = F_38 ( V_62 , V_81 ) ;
if ( V_41 ) {
F_39 ( V_62 ) ;
F_30 ( & V_66 -> V_71 , V_75 ) ;
F_40 ( & V_36 -> V_31 , L_9
L_10 , V_68 , V_41 ) ;
goto error;
} else {
V_66 -> V_72 ++ ;
F_30 ( & V_66 -> V_71 , V_75 ) ;
}
V_89:
F_20 ( V_62 ) ;
return V_77 ;
error:
F_20 ( V_62 ) ;
V_84:
F_19 ( V_76 ) ;
V_83:
F_29 ( & V_38 -> V_69 , V_75 ) ;
-- V_38 -> V_70 ;
F_10 ( & V_36 -> V_31 , L_11 , V_68 ,
V_38 -> V_70 ) ;
F_30 ( & V_38 -> V_69 , V_75 ) ;
F_23 ( V_10 -> V_16 ) ;
V_80:
return V_41 ;
}
static void F_41 ( struct V_62 * V_62 )
{
int V_91 ;
int V_92 ;
struct V_35 * V_36 ;
unsigned char * V_93 = V_62 -> V_63 ;
int V_67 = V_62 -> V_67 ;
V_92 = F_42 ( V_62 -> V_94 ) ;
V_36 = V_62 -> V_64 ;
if ( V_67 ) {
F_10 ( & V_36 -> V_31 , L_12
L_13 , V_68 , V_67 , V_92 ) ;
} else {
if ( V_62 -> V_95 ) {
F_43 ( & V_36 -> V_36 , V_93 ,
V_62 -> V_95 ) ;
F_44 ( & V_36 -> V_36 ) ;
F_34 ( & V_36 -> V_31 , V_68 ,
V_62 -> V_95 , V_93 ) ;
} else {
F_10 ( & V_36 -> V_31 , L_14
L_15 , V_68 ) ;
}
}
if ( V_67 != - V_96 && V_67 != - V_97 ) {
F_45 ( V_36 -> V_10 -> V_31 ) ;
V_91 = F_38 ( V_62 , V_81 ) ;
if ( V_91 && V_91 != - V_97 )
F_40 ( & V_36 -> V_31 , L_16
L_17 , V_91 ) ;
}
}
static void F_46 ( struct V_62 * V_62 )
{
int V_91 ;
int V_67 = V_62 -> V_67 ;
struct V_35 * V_36 = V_62 -> V_64 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
struct V_9 * V_10 = V_36 -> V_10 ;
F_10 ( & V_36 -> V_31 , L_18 , V_68 ,
V_62 , V_36 , V_38 ) ;
if ( V_67 == 0 ) {
struct V_98 * V_99 =
(struct V_98 * ) V_62 -> V_63 ;
if ( ! V_99 ) {
F_10 ( & V_36 -> V_31 , L_19 ,
V_68 ) ;
return;
}
if ( ( V_99 -> V_100 == 0xA1 ) &&
( V_99 -> V_101 == 0x20 ) ) {
int V_102 ;
unsigned char V_103 = * ( ( unsigned char * )
V_62 -> V_63 +
sizeof( struct V_98 ) ) ;
F_10 ( & V_36 -> V_31 , L_20 , V_68 ,
V_103 ) ;
V_102 = V_38 -> V_56 ;
V_38 -> V_52 = 1 ;
V_38 -> V_56 = ( ( V_103 & 0x01 ) ? 1 : 0 ) ;
V_38 -> V_54 = ( ( V_103 & 0x02 ) ? 1 : 0 ) ;
V_38 -> V_58 = ( ( V_103 & 0x08 ) ? 1 : 0 ) ;
if ( V_102 && ! V_38 -> V_56 )
F_47 ( & V_36 -> V_36 , true ) ;
} else {
F_10 ( & V_36 -> V_31 , L_21 ,
V_68 , V_99 -> V_100 ,
V_99 -> V_101 ) ;
}
} else
F_10 ( & V_36 -> V_31 , L_22 , V_68 , V_67 ) ;
if ( V_67 != - V_96 && V_67 != - V_104 ) {
F_45 ( V_10 -> V_31 ) ;
V_91 = F_38 ( V_62 , V_81 ) ;
if ( V_91 && V_91 != - V_97 )
F_40 ( & V_36 -> V_31 , L_23
L_24 , V_68 , V_91 ) ;
}
}
static int F_48 ( struct V_46 * V_47 )
{
struct V_35 * V_36 = V_47 -> V_48 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
unsigned long V_75 ;
F_29 ( & V_38 -> V_69 , V_75 ) ;
if ( V_38 -> V_70 > ( V_38 -> V_79 * 2 ) / 3 ) {
F_30 ( & V_38 -> V_69 , V_75 ) ;
F_10 ( & V_36 -> V_31 , L_7 , V_68 ) ;
return 0 ;
}
F_30 ( & V_38 -> V_69 , V_75 ) ;
return 2048 ;
}
static int F_49 ( struct V_46 * V_47 )
{
struct V_35 * V_36 = V_47 -> V_48 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
unsigned long V_75 ;
int V_105 ;
F_29 ( & V_38 -> V_69 , V_75 ) ;
V_105 = V_38 -> V_70 * V_78 ;
F_30 ( & V_38 -> V_69 , V_75 ) ;
F_10 ( & V_36 -> V_31 , L_25 , V_68 , V_105 ) ;
return V_105 ;
}
static void F_50 ( struct V_35 * V_36 )
{
int V_24 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
for ( V_24 = 0 ; V_24 < V_38 -> V_106 ; V_24 ++ )
F_51 ( V_38 -> V_107 [ V_24 ] ) ;
F_51 ( V_36 -> V_44 ) ;
}
static int F_52 ( struct V_35 * V_36 , T_4 V_108 )
{
int V_109 ;
int V_91 = - V_110 ;
int V_24 ;
struct V_62 * V_62 ;
struct V_37 * V_38 = F_13 ( V_36 ) ;
V_109 = 0 ;
for ( V_24 = 0 ; V_24 < V_38 -> V_106 ; V_24 ++ ) {
V_62 = V_38 -> V_107 [ V_24 ] ;
if ( ! V_62 )
continue;
V_91 = F_38 ( V_62 , V_108 ) ;
if ( V_91 ) {
F_40 ( & V_36 -> V_31 , L_26 ,
V_68 , V_91 ) ;
} else {
V_109 ++ ;
}
}
if ( V_109 && V_36 -> V_44 ) {
V_91 = F_38 ( V_36 -> V_44 , V_108 ) ;
if ( V_91 ) {
F_40 ( & V_36 -> V_31 , L_27 ,
V_68 , V_91 ) ;
}
}
if ( V_109 > 0 )
return 0 ;
else
return V_91 ;
}
static struct V_62 * F_53 ( struct V_9 * V_10 , int V_92 ,
int V_111 , void * V_112 , int V_113 ,
T_4 V_108 ,
T_5 V_114 )
{
struct V_62 * V_62 ;
T_2 * V_73 ;
V_62 = F_33 ( 0 , V_108 ) ;
if ( ! V_62 )
return NULL ;
V_73 = F_32 ( V_113 , V_108 ) ;
if ( V_73 ) {
F_35 ( V_62 , V_10 -> V_31 ,
F_36 ( V_10 -> V_31 , V_92 ) | V_111 ,
V_73 , V_113 , V_114 , V_112 ) ;
F_10 ( & V_10 -> V_31 -> V_31 , L_28 , V_68 ,
V_111 == V_115 ? 'i' : 'o' , V_62 , V_73 ) ;
} else {
F_18 ( V_62 ) ;
V_62 = NULL ;
}
return V_62 ;
}
static void F_54 ( struct V_35 * V_36 )
{
int V_24 ;
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_37 * V_38 ;
struct V_65 * V_66 = F_22 ( V_10 ) ;
struct V_62 * V_62 ;
V_38 = F_13 ( V_36 ) ;
F_55 ( & V_66 -> V_71 ) ;
if ( -- V_66 -> V_116 == 0 )
V_10 -> V_16 -> V_117 = 0 ;
F_56 ( & V_66 -> V_71 ) ;
for (; ; ) {
V_62 = F_57 ( & V_38 -> V_88 ) ;
if ( ! V_62 )
break;
F_19 ( V_62 -> V_63 ) ;
F_20 ( V_62 ) ;
F_23 ( V_10 -> V_16 ) ;
F_24 ( & V_38 -> V_69 ) ;
V_38 -> V_70 -- ;
F_25 ( & V_38 -> V_69 ) ;
}
F_50 ( V_36 ) ;
F_58 ( & V_38 -> V_90 ) ;
for ( V_24 = 0 ; V_24 < V_38 -> V_106 ; V_24 ++ ) {
F_18 ( V_38 -> V_107 [ V_24 ] ) ;
V_38 -> V_107 [ V_24 ] = NULL ;
}
F_59 ( V_10 -> V_16 ) ;
}
static int F_60 ( struct V_46 * V_47 , struct V_35 * V_36 )
{
struct V_37 * V_38 ;
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_65 * V_66 = F_22 ( V_10 ) ;
int V_24 ;
int V_91 ;
int V_92 ;
struct V_62 * V_62 ;
V_38 = F_13 ( V_36 ) ;
V_92 = V_36 -> V_118 ;
for ( V_24 = 0 ; V_24 < V_38 -> V_106 ; V_24 ++ ) {
V_62 = F_53 ( V_10 , V_92 , V_115 , V_36 ,
V_119 , V_120 ,
F_41 ) ;
V_38 -> V_107 [ V_24 ] = V_62 ;
}
F_61 ( V_10 -> V_31 ,
F_36 ( V_10 -> V_31 , V_92 ) | V_115 ) ;
V_91 = F_52 ( V_36 , V_120 ) ;
if ( V_91 )
goto V_121;
F_55 ( & V_66 -> V_71 ) ;
if ( ++ V_66 -> V_116 == 1 )
V_10 -> V_16 -> V_117 = 1 ;
F_56 ( & V_66 -> V_71 ) ;
F_15 ( V_10 -> V_16 ) ;
return 0 ;
V_121:
F_50 ( V_36 ) ;
for ( V_24 = 0 ; V_24 < V_38 -> V_106 ; V_24 ++ ) {
F_18 ( V_38 -> V_107 [ V_24 ] ) ;
V_38 -> V_107 [ V_24 ] = NULL ;
}
return V_91 ;
}
static void F_62 ( struct V_35 * V_36 , int V_122 )
{
struct V_37 * V_38 ;
V_38 = F_13 ( V_36 ) ;
V_38 -> V_43 = V_122 ;
V_38 -> V_42 = V_122 ;
F_12 ( V_36 ) ;
}
static int F_63 ( struct V_9 * V_10 )
{
struct V_65 * V_66 ;
V_66 = F_64 ( sizeof( * V_66 ) , V_120 ) ;
if ( ! V_66 )
return - V_82 ;
F_65 ( & V_66 -> V_71 ) ;
F_66 ( V_10 , V_66 ) ;
F_1 ( V_10 -> V_31 , 0x0000 ) ;
if ( V_123 )
F_4 ( V_10 -> V_31 , 1 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_65 * V_66 ;
V_66 = F_22 ( V_10 ) ;
F_19 ( V_66 ) ;
}
static int F_68 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_37 * V_38 ;
const struct V_21 * V_124 ;
T_2 V_14 ;
V_38 = F_64 ( sizeof( * V_38 ) , V_120 ) ;
if ( ! V_38 )
return - V_82 ;
F_65 ( & V_38 -> V_69 ) ;
F_69 ( & V_38 -> V_90 ) ;
F_69 ( & V_38 -> V_88 ) ;
V_38 -> V_79 = V_125 ;
V_38 -> V_106 = V_126 ;
if ( V_10 -> V_13 == 1 ) {
V_14 = F_8 ( V_10 ) ;
V_124 = & V_127 ;
} else {
V_14 = V_36 -> V_128 ;
V_124 = & V_129 ;
}
if ( F_7 ( V_14 , V_124 ) ) {
V_38 -> V_79 = V_130 ;
V_38 -> V_106 = V_131 ;
}
F_10 ( & V_36 -> V_31 ,
L_29 ,
V_14 , V_38 -> V_106 , V_38 -> V_79 ) ;
F_70 ( V_36 , V_38 ) ;
return 0 ;
}
static int F_71 ( struct V_35 * V_36 )
{
struct V_37 * V_38 ;
V_38 = F_13 ( V_36 ) ;
F_70 ( V_36 , NULL ) ;
F_19 ( V_38 ) ;
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
int V_24 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
for ( V_24 = 0 ; V_24 < V_10 -> V_13 ; ++ V_24 ) {
V_36 = V_10 -> V_36 [ V_24 ] ;
V_38 = F_13 ( V_36 ) ;
if ( ! V_38 )
continue;
F_50 ( V_36 ) ;
F_58 ( & V_38 -> V_90 ) ;
}
}
static int F_73 ( struct V_9 * V_10 , T_6 V_132 )
{
struct V_65 * V_66 = F_22 ( V_10 ) ;
F_55 ( & V_66 -> V_71 ) ;
if ( F_74 ( V_132 ) ) {
if ( V_66 -> V_72 ) {
F_56 ( & V_66 -> V_71 ) ;
return - V_133 ;
}
}
V_66 -> V_87 = 1 ;
F_56 ( & V_66 -> V_71 ) ;
F_72 ( V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_13 ( V_36 ) ;
struct V_65 * V_66 ;
struct V_62 * V_62 ;
int V_134 = 0 ;
int V_91 ;
V_66 = F_22 ( V_36 -> V_10 ) ;
for (; ; ) {
V_62 = F_57 ( & V_38 -> V_88 ) ;
if ( ! V_62 )
break;
F_37 ( V_62 , & V_38 -> V_90 ) ;
V_66 -> V_72 ++ ;
V_91 = F_38 ( V_62 , V_81 ) ;
if ( V_91 ) {
F_40 ( & V_36 -> V_31 , L_30 ,
V_68 , V_91 ) ;
V_134 ++ ;
V_66 -> V_72 -- ;
F_39 ( V_62 ) ;
F_19 ( V_62 -> V_63 ) ;
F_20 ( V_62 ) ;
F_24 ( & V_38 -> V_69 ) ;
V_38 -> V_70 -- ;
F_25 ( & V_38 -> V_69 ) ;
}
}
if ( V_134 )
return - V_135 ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 )
{
struct V_35 * V_36 ;
struct V_65 * V_66 = F_22 ( V_10 ) ;
int V_134 = 0 ;
int V_24 , V_91 ;
F_55 ( & V_66 -> V_71 ) ;
for ( V_24 = 0 ; V_24 < V_10 -> V_13 ; V_24 ++ ) {
V_36 = V_10 -> V_36 [ V_24 ] ;
if ( ! F_77 ( & V_36 -> V_36 ) )
continue;
V_91 = F_75 ( V_36 ) ;
if ( V_91 )
V_134 ++ ;
V_91 = F_52 ( V_36 , V_81 ) ;
if ( V_91 )
V_134 ++ ;
}
V_66 -> V_87 = 0 ;
F_56 ( & V_66 -> V_71 ) ;
return V_134 ? - V_135 : 0 ;
}
