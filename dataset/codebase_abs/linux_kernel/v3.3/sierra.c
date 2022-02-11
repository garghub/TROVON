static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 , L_1 , V_6 ) ;
V_4 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_7 ,
V_8 ,
V_3 ,
0 ,
NULL ,
0 ,
V_9 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 , L_1 , V_6 ) ;
V_4 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_11 ,
V_8 ,
V_10 ,
0x0000 ,
NULL ,
0 ,
V_9 ) ;
return V_4 ;
}
static int F_6 ( struct V_12 * V_13 )
{
int V_14 = 0 ;
T_2 V_15 , V_16 ;
F_2 ( & V_13 -> V_5 -> V_5 , L_1 , V_6 ) ;
V_15 = V_13 -> V_17 -> V_18 -> V_19 . V_20 ;
V_16 = V_13 -> V_17 -> V_18 -> V_19 . V_21 ;
if ( V_15 == 0x99 )
V_14 = 0 ;
else if ( V_16 <= 3 )
V_14 = 1 ;
else
V_14 = ( V_16 - 1 ) / 2 ;
return V_14 ;
}
static int F_7 ( const T_2 V_15 ,
const struct V_22 * V_23 )
{
const T_2 * V_24 ;
int V_25 ;
if ( V_23 ) {
V_24 = V_23 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_27 ; V_25 ++ ) {
if ( V_24 [ V_25 ] == V_15 )
return 1 ;
}
}
return 0 ;
}
static int F_8 ( const T_2 V_15 ,
const struct V_22 * V_28 )
{
const T_2 * V_24 ;
int V_25 ;
if ( V_28 ) {
V_24 = V_28 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_28 -> V_27 ; V_25 ++ ) {
if ( V_24 [ V_25 ] == V_15 )
return 1 ;
}
}
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
int V_17 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
F_2 ( & V_13 -> V_5 -> V_5 , L_1 , V_6 ) ;
V_30 = V_13 -> V_17 ;
V_32 = V_30 -> V_18 ;
V_17 = V_32 -> V_19 . V_20 ;
return V_17 ;
}
static int F_10 ( struct V_12 * V_13 ,
const struct V_33 * V_34 )
{
int V_4 = 0 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
T_2 V_15 ;
V_2 = V_13 -> V_5 ;
F_2 ( & V_2 -> V_5 , L_1 , V_6 ) ;
V_15 = F_9 ( V_13 ) ;
if ( V_13 -> V_17 -> V_37 == 2 ) {
F_2 ( & V_2 -> V_5 , L_2 ,
V_15 ) ;
F_11 ( V_2 , V_15 , 1 ) ;
}
V_15 = F_9 ( V_13 ) ;
if ( F_7 ( V_15 ,
(struct V_22 * ) V_34 -> V_38 ) ) {
F_2 ( & V_13 -> V_5 -> V_5 ,
L_3 , V_15 ) ;
return - V_39 ;
}
V_36 = V_13 -> V_40 = F_12 ( sizeof( struct V_35 ) , V_41 ) ;
if ( ! V_36 )
return - V_42 ;
F_13 ( & V_36 -> V_43 ) ;
return V_4 ;
}
static int F_14 ( struct V_44 * V_45 )
{
struct V_12 * V_13 = V_45 -> V_13 ;
struct V_46 * V_47 ;
T_1 V_17 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
int V_50 ;
F_2 ( & V_45 -> V_5 , L_1 , V_6 ) ;
V_47 = F_15 ( V_45 ) ;
if ( V_47 -> V_51 )
V_48 |= 0x01 ;
if ( V_47 -> V_52 )
V_48 |= 0x02 ;
if ( V_13 -> V_14 == 1 ) {
V_17 = F_9 ( V_13 ) ;
if ( V_45 -> V_53 ) {
V_49 = 1 ;
}
}
else {
if ( V_45 -> V_54 == 2 )
V_17 = 0 ;
else if ( V_45 -> V_54 == 4 )
V_17 = 1 ;
else if ( V_45 -> V_54 == 5 )
V_17 = 2 ;
V_49 = 1 ;
}
if ( ! V_49 )
return 0 ;
V_50 = F_16 ( V_13 -> V_17 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_3 ( V_13 -> V_5 , F_17 ( V_13 -> V_5 , 0 ) ,
0x22 , 0x21 , V_48 , V_17 , NULL , 0 , V_9 ) ;
F_18 ( V_13 -> V_17 ) ;
return V_50 ;
}
static void F_19 ( struct V_55 * V_56 ,
struct V_44 * V_45 , struct V_57 * V_58 )
{
F_2 ( & V_45 -> V_5 , L_1 , V_6 ) ;
F_20 ( V_56 -> V_59 , V_58 ) ;
F_14 ( V_45 ) ;
}
static int F_21 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = V_56 -> V_60 ;
unsigned int V_61 ;
struct V_46 * V_47 ;
F_2 ( & V_45 -> V_5 , L_1 , V_6 ) ;
V_47 = F_15 ( V_45 ) ;
V_61 = ( ( V_47 -> V_52 ) ? V_62 : 0 ) |
( ( V_47 -> V_51 ) ? V_63 : 0 ) |
( ( V_47 -> V_64 ) ? V_65 : 0 ) |
( ( V_47 -> V_66 ) ? V_67 : 0 ) |
( ( V_47 -> V_68 ) ? V_69 : 0 ) |
( ( V_47 -> V_70 ) ? V_71 : 0 ) ;
return V_61 ;
}
static int F_22 ( struct V_55 * V_56 ,
unsigned int V_72 , unsigned int V_73 )
{
struct V_44 * V_45 = V_56 -> V_60 ;
struct V_46 * V_47 ;
V_47 = F_15 ( V_45 ) ;
if ( V_72 & V_62 )
V_47 -> V_52 = 1 ;
if ( V_72 & V_63 )
V_47 -> V_51 = 1 ;
if ( V_73 & V_62 )
V_47 -> V_52 = 0 ;
if ( V_73 & V_63 )
V_47 -> V_51 = 0 ;
return F_14 ( V_45 ) ;
}
static void F_23 ( struct V_74 * V_74 )
{
struct V_44 * V_45 ;
if ( V_74 ) {
V_45 = V_74 -> V_75 ;
F_2 ( & V_45 -> V_5 , L_4 , V_6 , V_74 ) ;
F_24 ( V_74 -> V_76 ) ;
F_25 ( V_74 ) ;
}
}
static void F_26 ( struct V_74 * V_74 )
{
struct V_44 * V_45 = V_74 -> V_75 ;
struct V_46 * V_47 = F_15 ( V_45 ) ;
struct V_35 * V_77 ;
int V_78 = V_74 -> V_78 ;
F_2 ( & V_45 -> V_5 , L_5 , V_6 , V_45 -> V_79 ) ;
V_77 = V_45 -> V_13 -> V_40 ;
F_24 ( V_74 -> V_76 ) ;
F_27 ( V_45 -> V_13 -> V_17 ) ;
if ( V_78 )
F_2 ( & V_45 -> V_5 , L_6
L_7 , V_6 , V_78 ) ;
F_28 ( & V_47 -> V_80 ) ;
-- V_47 -> V_81 ;
F_29 ( & V_47 -> V_80 ) ;
F_28 ( & V_77 -> V_43 ) ;
-- V_77 -> V_82 ;
F_29 ( & V_77 -> V_43 ) ;
F_30 ( V_45 ) ;
}
static int F_31 ( struct V_55 * V_56 , struct V_44 * V_45 ,
const unsigned char * V_83 , int V_84 )
{
struct V_46 * V_47 ;
struct V_35 * V_77 ;
struct V_12 * V_13 = V_45 -> V_13 ;
unsigned long V_85 ;
unsigned char * V_86 ;
struct V_74 * V_74 ;
T_3 V_87 = F_32 ( ( T_3 ) V_84 , ( T_3 ) V_88 ) ;
int V_50 = 0 ;
if ( V_84 == 0 )
return 0 ;
V_47 = F_15 ( V_45 ) ;
V_77 = V_13 -> V_40 ;
F_2 ( & V_45 -> V_5 , L_8 , V_6 , V_87 ) ;
F_33 ( & V_47 -> V_80 , V_85 ) ;
F_2 ( & V_45 -> V_5 , L_9 , V_6 ,
V_47 -> V_81 ) ;
if ( V_47 -> V_81 > V_47 -> V_89 ) {
F_34 ( & V_47 -> V_80 , V_85 ) ;
F_2 ( & V_45 -> V_5 , L_10 , V_6 ) ;
return 0 ;
}
V_47 -> V_81 ++ ;
F_2 ( & V_45 -> V_5 , L_11 , V_6 ,
V_47 -> V_81 ) ;
F_34 ( & V_47 -> V_80 , V_85 ) ;
V_50 = F_35 ( V_13 -> V_17 ) ;
if ( V_50 < 0 ) {
F_33 ( & V_47 -> V_80 , V_85 ) ;
V_47 -> V_81 -- ;
F_34 ( & V_47 -> V_80 , V_85 ) ;
goto V_90;
}
V_86 = F_36 ( V_87 , V_91 ) ;
if ( ! V_86 ) {
F_37 ( & V_45 -> V_5 , L_12 ) ;
V_50 = - V_42 ;
goto V_92;
}
V_74 = F_38 ( 0 , V_91 ) ;
if ( ! V_74 ) {
F_37 ( & V_45 -> V_5 , L_13 ) ;
V_50 = - V_42 ;
goto V_93;
}
memcpy ( V_86 , V_83 , V_87 ) ;
F_39 ( V_94 , & V_45 -> V_5 , V_6 , V_87 , V_86 ) ;
F_40 ( V_74 , V_13 -> V_5 ,
F_41 ( V_13 -> V_5 ,
V_45 -> V_54 ) ,
V_86 , V_87 , F_26 , V_45 ) ;
V_74 -> V_95 |= V_96 ;
F_33 ( & V_77 -> V_43 , V_85 ) ;
if ( V_77 -> V_97 ) {
F_42 ( V_74 , & V_47 -> V_98 ) ;
F_34 ( & V_77 -> V_43 , V_85 ) ;
goto V_99;
} else {
F_42 ( V_74 , & V_47 -> V_100 ) ;
}
V_50 = F_43 ( V_74 , V_91 ) ;
if ( V_50 ) {
F_44 ( V_74 ) ;
F_34 ( & V_77 -> V_43 , V_85 ) ;
F_37 ( & V_45 -> V_5 , L_14
L_15 , V_6 , V_50 ) ;
goto error;
} else {
V_77 -> V_82 ++ ;
F_34 ( & V_77 -> V_43 , V_85 ) ;
}
V_99:
F_25 ( V_74 ) ;
return V_87 ;
error:
F_25 ( V_74 ) ;
V_93:
F_24 ( V_86 ) ;
V_92:
F_33 ( & V_47 -> V_80 , V_85 ) ;
-- V_47 -> V_81 ;
F_2 ( & V_45 -> V_5 , L_16 , V_6 ,
V_47 -> V_81 ) ;
F_34 ( & V_47 -> V_80 , V_85 ) ;
F_27 ( V_13 -> V_17 ) ;
V_90:
return V_50 ;
}
static void F_45 ( struct V_74 * V_74 )
{
int V_101 ;
int V_102 ;
struct V_44 * V_45 ;
struct V_55 * V_56 ;
unsigned char * V_36 = V_74 -> V_76 ;
int V_78 = V_74 -> V_78 ;
V_102 = F_46 ( V_74 -> V_103 ) ;
V_45 = V_74 -> V_75 ;
F_2 ( & V_45 -> V_5 , L_4 , V_6 , V_74 ) ;
if ( V_78 ) {
F_2 ( & V_45 -> V_5 , L_17
L_18 , V_6 , V_78 , V_102 ) ;
} else {
if ( V_74 -> V_104 ) {
V_56 = F_47 ( & V_45 -> V_45 ) ;
if ( V_56 ) {
F_48 ( V_56 , V_36 ,
V_74 -> V_104 ) ;
F_49 ( V_56 ) ;
F_50 ( V_56 ) ;
F_39 ( V_94 , & V_45 -> V_5 ,
V_6 , V_74 -> V_104 , V_36 ) ;
}
} else {
F_2 ( & V_45 -> V_5 , L_19
L_20 , V_6 ) ;
}
}
if ( V_78 != - V_105 && V_78 != - V_106 ) {
F_51 ( V_45 -> V_13 -> V_5 ) ;
V_101 = F_43 ( V_74 , V_91 ) ;
if ( V_101 && V_101 != - V_106 )
F_37 ( & V_45 -> V_5 , L_21
L_22 , V_101 ) ;
}
}
static void F_52 ( struct V_74 * V_74 )
{
int V_101 ;
int V_78 = V_74 -> V_78 ;
struct V_44 * V_45 = V_74 -> V_75 ;
struct V_46 * V_47 = F_15 ( V_45 ) ;
struct V_12 * V_13 = V_45 -> V_13 ;
F_2 ( & V_45 -> V_5 , L_23 , V_6 ,
V_74 , V_45 , V_47 ) ;
if ( V_78 == 0 ) {
struct V_107 * V_108 =
(struct V_107 * ) V_74 -> V_76 ;
if ( ! V_108 ) {
F_2 ( & V_45 -> V_5 , L_24 ,
V_6 ) ;
return;
}
if ( ( V_108 -> V_109 == 0xA1 ) &&
( V_108 -> V_110 == 0x20 ) ) {
int V_111 ;
unsigned char V_112 = * ( ( unsigned char * )
V_74 -> V_76 +
sizeof( struct V_107 ) ) ;
struct V_55 * V_56 ;
F_2 ( & V_45 -> V_5 , L_25 , V_6 ,
V_112 ) ;
V_111 = V_47 -> V_68 ;
V_47 -> V_64 = 1 ;
V_47 -> V_68 = ( ( V_112 & 0x01 ) ? 1 : 0 ) ;
V_47 -> V_66 = ( ( V_112 & 0x02 ) ? 1 : 0 ) ;
V_47 -> V_70 = ( ( V_112 & 0x08 ) ? 1 : 0 ) ;
V_56 = F_47 ( & V_45 -> V_45 ) ;
if ( V_56 && ! F_53 ( V_56 ) &&
V_111 && ! V_47 -> V_68 )
F_54 ( V_56 ) ;
F_50 ( V_56 ) ;
} else {
F_2 ( & V_45 -> V_5 , L_26 ,
V_6 , V_108 -> V_109 ,
V_108 -> V_110 ) ;
}
} else
F_2 ( & V_45 -> V_5 , L_27 , V_6 , V_78 ) ;
if ( V_78 != - V_105 && V_78 != - V_113 ) {
F_51 ( V_13 -> V_5 ) ;
V_101 = F_43 ( V_74 , V_91 ) ;
if ( V_101 && V_101 != - V_106 )
F_37 ( & V_45 -> V_5 , L_28
L_29 , V_6 , V_101 ) ;
}
}
static int F_55 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = V_56 -> V_60 ;
struct V_46 * V_47 = F_15 ( V_45 ) ;
unsigned long V_85 ;
F_2 ( & V_45 -> V_5 , L_5 , V_6 , V_45 -> V_79 ) ;
F_33 ( & V_47 -> V_80 , V_85 ) ;
if ( V_47 -> V_81 > ( V_47 -> V_89 * 2 ) / 3 ) {
F_34 ( & V_47 -> V_80 , V_85 ) ;
F_2 ( & V_45 -> V_5 , L_10 , V_6 ) ;
return 0 ;
}
F_34 ( & V_47 -> V_80 , V_85 ) ;
return 2048 ;
}
static void F_56 ( struct V_44 * V_45 )
{
int V_25 ;
struct V_46 * V_47 = F_15 ( V_45 ) ;
for ( V_25 = 0 ; V_25 < V_47 -> V_114 ; V_25 ++ )
F_57 ( V_47 -> V_115 [ V_25 ] ) ;
F_57 ( V_45 -> V_53 ) ;
}
static int F_58 ( struct V_44 * V_45 , T_4 V_116 )
{
int V_117 ;
int V_101 = - V_118 ;
int V_25 ;
struct V_74 * V_74 ;
struct V_46 * V_47 = F_15 ( V_45 ) ;
V_117 = 0 ;
for ( V_25 = 0 ; V_25 < V_47 -> V_114 ; V_25 ++ ) {
V_74 = V_47 -> V_115 [ V_25 ] ;
if ( ! V_74 )
continue;
V_101 = F_43 ( V_74 , V_116 ) ;
if ( V_101 ) {
F_37 ( & V_45 -> V_5 , L_30 ,
V_6 , V_101 ) ;
} else {
V_117 ++ ;
}
}
if ( V_117 && V_45 -> V_53 ) {
V_101 = F_43 ( V_45 -> V_53 , V_116 ) ;
if ( V_101 ) {
F_37 ( & V_45 -> V_5 , L_31 ,
V_6 , V_101 ) ;
}
}
if ( V_117 > 0 )
return 0 ;
else
return V_101 ;
}
static struct V_74 * F_59 ( struct V_12 * V_13 , int V_102 ,
int V_119 , void * V_120 , int V_121 ,
T_4 V_116 ,
T_5 V_122 )
{
struct V_74 * V_74 ;
T_2 * V_83 ;
if ( V_102 == - 1 )
return NULL ;
V_74 = F_38 ( 0 , V_116 ) ;
if ( V_74 == NULL ) {
F_2 ( & V_13 -> V_5 -> V_5 , L_32 ,
V_6 , V_102 ) ;
return NULL ;
}
V_83 = F_36 ( V_121 , V_116 ) ;
if ( V_83 ) {
F_40 ( V_74 , V_13 -> V_5 ,
F_41 ( V_13 -> V_5 , V_102 ) | V_119 ,
V_83 , V_121 , V_122 , V_120 ) ;
F_2 ( & V_13 -> V_5 -> V_5 , L_33 , V_6 ,
V_119 == V_123 ? 'i' : 'o' , V_74 , V_83 ) ;
} else {
F_2 ( & V_13 -> V_5 -> V_5 , L_34 , V_6 ,
V_119 == V_123 ? 'i' : 'o' , V_74 , V_83 ) ;
F_23 ( V_74 ) ;
V_74 = NULL ;
}
return V_74 ;
}
static void F_60 ( struct V_44 * V_45 )
{
int V_25 ;
struct V_12 * V_13 = V_45 -> V_13 ;
struct V_46 * V_47 ;
struct V_35 * V_77 = V_45 -> V_13 -> V_40 ;
F_2 ( & V_45 -> V_5 , L_1 , V_6 ) ;
V_47 = F_15 ( V_45 ) ;
V_47 -> V_52 = 0 ;
V_47 -> V_51 = 0 ;
if ( V_13 -> V_5 ) {
F_61 ( & V_13 -> V_124 ) ;
if ( ! V_13 -> V_125 ) {
V_13 -> V_17 -> V_126 = 0 ;
if ( ! F_16 ( V_13 -> V_17 ) )
F_14 ( V_45 ) ;
else
F_62 ( V_13 -> V_17 ) ;
}
F_63 ( & V_13 -> V_124 ) ;
F_64 ( & V_77 -> V_43 ) ;
V_47 -> V_127 = 0 ;
F_65 ( & V_77 -> V_43 ) ;
F_56 ( V_45 ) ;
for ( V_25 = 0 ; V_25 < V_47 -> V_114 ; V_25 ++ ) {
F_23 ( V_47 -> V_115 [ V_25 ] ) ;
V_47 -> V_115 [ V_25 ] = NULL ;
}
}
}
static int F_66 ( struct V_55 * V_56 , struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_12 * V_13 = V_45 -> V_13 ;
struct V_35 * V_77 = V_13 -> V_40 ;
int V_25 ;
int V_101 ;
int V_102 ;
struct V_74 * V_74 ;
V_47 = F_15 ( V_45 ) ;
F_2 ( & V_45 -> V_5 , L_1 , V_6 ) ;
V_47 -> V_52 = 1 ;
V_47 -> V_51 = 1 ;
V_102 = V_45 -> V_128 ;
for ( V_25 = 0 ; V_25 < V_47 -> V_114 ; V_25 ++ ) {
V_74 = F_59 ( V_13 , V_102 , V_123 , V_45 ,
V_129 , V_41 ,
F_45 ) ;
V_47 -> V_115 [ V_25 ] = V_74 ;
}
F_67 ( V_13 -> V_5 ,
F_41 ( V_13 -> V_5 , V_102 ) | V_123 ) ;
V_101 = F_58 ( V_45 , V_41 ) ;
if ( V_101 ) {
F_60 ( V_45 ) ;
if ( ! V_13 -> V_125 )
F_18 ( V_13 -> V_17 ) ;
return V_101 ;
}
F_14 ( V_45 ) ;
V_13 -> V_17 -> V_126 = 1 ;
F_64 ( & V_77 -> V_43 ) ;
V_47 -> V_127 = 1 ;
F_65 ( & V_77 -> V_43 ) ;
F_18 ( V_13 -> V_17 ) ;
return 0 ;
}
static void F_68 ( struct V_44 * V_45 , int V_130 )
{
struct V_12 * V_13 = V_45 -> V_13 ;
struct V_46 * V_47 ;
V_47 = F_15 ( V_45 ) ;
V_47 -> V_52 = V_130 ;
V_47 -> V_51 = V_130 ;
if ( V_13 -> V_5 ) {
F_61 ( & V_13 -> V_124 ) ;
if ( ! V_13 -> V_125 )
F_14 ( V_45 ) ;
F_63 ( & V_13 -> V_124 ) ;
}
}
static int F_69 ( struct V_12 * V_13 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_22 * V_131 = NULL ;
int V_25 ;
T_2 V_15 ;
F_2 ( & V_13 -> V_5 -> V_5 , L_1 , V_6 ) ;
F_1 ( V_13 -> V_5 , 0x0000 ) ;
if ( V_132 )
F_5 ( V_13 -> V_5 , 1 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_14 ; V_25 ++ ) {
V_45 = V_13 -> V_45 [ V_25 ] ;
V_47 = F_12 ( sizeof( * V_47 ) , V_41 ) ;
if ( ! V_47 ) {
F_2 ( & V_45 -> V_5 , L_35
L_36 ,
V_6 , V_25 ) ;
return - V_42 ;
}
F_13 ( & V_47 -> V_80 ) ;
F_70 ( & V_47 -> V_100 ) ;
F_70 ( & V_47 -> V_98 ) ;
V_15 = V_25 ;
V_47 -> V_89 = V_133 ;
V_47 -> V_114 = V_134 ;
if ( V_13 -> V_14 == 1 ) {
V_15 = F_9 ( V_13 ) ;
V_131 =
(struct V_22 * ) & V_135 ;
if ( F_8 ( V_15 , V_131 ) ) {
V_47 -> V_89 = V_136 ;
V_47 -> V_114 = V_137 ;
}
}
else {
V_131 =
(struct V_22 * ) & V_138 ;
if ( F_8 ( V_25 , V_131 ) ) {
V_47 -> V_89 = V_136 ;
V_47 -> V_114 = V_137 ;
}
}
F_2 ( & V_13 -> V_5 -> V_5 ,
L_37 ,
V_15 , V_47 -> V_114 , V_47 -> V_89 ) ;
F_71 ( V_45 , V_47 ) ;
}
return 0 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_25 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
F_2 ( & V_13 -> V_5 -> V_5 , L_1 , V_6 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_14 ; ++ V_25 ) {
V_45 = V_13 -> V_45 [ V_25 ] ;
if ( ! V_45 )
continue;
V_47 = F_15 ( V_45 ) ;
if ( ! V_47 )
continue;
F_24 ( V_47 ) ;
}
}
static void F_73 ( struct V_12 * V_13 )
{
int V_25 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
for ( V_25 = 0 ; V_25 < V_13 -> V_14 ; ++ V_25 ) {
V_45 = V_13 -> V_45 [ V_25 ] ;
V_47 = F_15 ( V_45 ) ;
F_56 ( V_45 ) ;
F_74 ( & V_47 -> V_100 ) ;
}
}
static int F_75 ( struct V_12 * V_13 , T_6 V_139 )
{
struct V_35 * V_77 ;
int V_140 ;
if ( F_76 ( V_139 ) ) {
V_77 = V_13 -> V_40 ;
F_64 ( & V_77 -> V_43 ) ;
V_140 = V_77 -> V_82 ;
if ( V_140 ) {
F_65 ( & V_77 -> V_43 ) ;
return - V_141 ;
} else {
V_77 -> V_97 = 1 ;
F_65 ( & V_77 -> V_43 ) ;
}
}
F_73 ( V_13 ) ;
return 0 ;
}
static int F_77 ( struct V_12 * V_13 )
{
struct V_44 * V_45 ;
struct V_35 * V_77 = V_13 -> V_40 ;
struct V_46 * V_47 ;
struct V_74 * V_74 ;
int V_142 = 0 ;
int V_25 , V_101 ;
F_64 ( & V_77 -> V_43 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_14 ; V_25 ++ ) {
V_45 = V_13 -> V_45 [ V_25 ] ;
V_47 = F_15 ( V_45 ) ;
while ( ( V_74 = F_78 ( & V_47 -> V_98 ) ) ) {
F_42 ( V_74 , & V_47 -> V_100 ) ;
V_77 -> V_82 ++ ;
V_101 = F_43 ( V_74 , V_91 ) ;
if ( V_101 < 0 ) {
V_77 -> V_82 -- ;
F_44 ( V_74 ) ;
F_79 ( & V_47 -> V_98 ) ;
break;
}
}
if ( V_47 -> V_127 ) {
V_101 = F_58 ( V_45 , V_91 ) ;
if ( V_101 )
V_142 ++ ;
}
}
V_77 -> V_97 = 0 ;
F_65 ( & V_77 -> V_43 ) ;
return V_142 ? - V_143 : 0 ;
}
static int F_80 ( struct V_29 * V_144 )
{
struct V_12 * V_13 = F_81 ( V_144 ) ;
F_37 ( & V_13 -> V_5 -> V_5 , L_1 , V_6 ) ;
return F_82 ( V_144 ) ;
}
static int T_7 F_83 ( void )
{
int V_50 ;
V_50 = F_84 ( & V_145 ) ;
if ( V_50 )
goto V_146;
V_50 = F_85 ( & V_147 ) ;
if ( V_50 )
goto V_148;
F_86 (KERN_INFO KBUILD_MODNAME L_38 DRIVER_VERSION L_39
DRIVER_DESC L_40 ) ;
return 0 ;
V_148:
F_87 ( & V_145 ) ;
V_146:
return V_50 ;
}
static void T_8 F_88 ( void )
{
F_89 ( & V_147 ) ;
F_87 ( & V_145 ) ;
}
