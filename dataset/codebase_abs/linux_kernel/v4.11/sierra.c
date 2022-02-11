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
static T_2 F_8 ( struct V_9 * V_10 )
{
return V_10 -> V_14 -> V_15 -> V_16 . V_17 ;
}
static int F_9 ( struct V_9 * V_10 ,
const struct V_26 * V_27 )
{
int V_28 = 0 ;
struct V_1 * V_2 ;
T_2 V_12 ;
V_2 = V_10 -> V_29 ;
V_12 = F_8 ( V_10 ) ;
if ( V_10 -> V_14 -> V_30 == 2 ) {
F_10 ( & V_2 -> V_29 , L_1 ,
V_12 ) ;
F_11 ( V_2 , V_12 , 1 ) ;
}
if ( F_6 ( V_12 ,
(struct V_19 * ) V_27 -> V_31 ) ) {
F_10 ( & V_10 -> V_29 -> V_29 ,
L_2 , V_12 ) ;
return - V_32 ;
}
return V_28 ;
}
static int F_12 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_35 * V_36 ;
T_1 V_14 = 0 ;
int V_37 = 0 ;
int V_38 = 0 ;
int V_39 ;
V_36 = F_13 ( V_34 ) ;
if ( V_36 -> V_40 )
V_37 |= 0x01 ;
if ( V_36 -> V_41 )
V_37 |= 0x02 ;
if ( V_10 -> V_11 == 1 ) {
V_14 = F_8 ( V_10 ) ;
if ( V_34 -> V_42 ) {
V_38 = 1 ;
}
}
else {
if ( V_34 -> V_43 == 2 )
V_14 = 0 ;
else if ( V_34 -> V_43 == 4 )
V_14 = 1 ;
else if ( V_34 -> V_43 == 5 )
V_14 = 2 ;
V_38 = 1 ;
}
if ( ! V_38 )
return 0 ;
V_39 = F_14 ( V_10 -> V_14 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_2 ( V_10 -> V_29 , F_3 ( V_10 -> V_29 , 0 ) ,
0x22 , 0x21 , V_37 , V_14 , NULL , 0 , V_6 ) ;
F_15 ( V_10 -> V_14 ) ;
return V_39 ;
}
static int F_16 ( struct V_44 * V_45 )
{
struct V_33 * V_34 = V_45 -> V_46 ;
unsigned int V_47 ;
struct V_35 * V_36 ;
V_36 = F_13 ( V_34 ) ;
V_47 = ( ( V_36 -> V_41 ) ? V_48 : 0 ) |
( ( V_36 -> V_40 ) ? V_49 : 0 ) |
( ( V_36 -> V_50 ) ? V_51 : 0 ) |
( ( V_36 -> V_52 ) ? V_53 : 0 ) |
( ( V_36 -> V_54 ) ? V_55 : 0 ) |
( ( V_36 -> V_56 ) ? V_57 : 0 ) ;
return V_47 ;
}
static int F_17 ( struct V_44 * V_45 ,
unsigned int V_58 , unsigned int V_59 )
{
struct V_33 * V_34 = V_45 -> V_46 ;
struct V_35 * V_36 ;
V_36 = F_13 ( V_34 ) ;
if ( V_58 & V_48 )
V_36 -> V_41 = 1 ;
if ( V_58 & V_49 )
V_36 -> V_40 = 1 ;
if ( V_59 & V_48 )
V_36 -> V_41 = 0 ;
if ( V_59 & V_49 )
V_36 -> V_40 = 0 ;
return F_12 ( V_34 ) ;
}
static void F_18 ( struct V_60 * V_60 )
{
if ( V_60 ) {
F_19 ( V_60 -> V_61 ) ;
F_20 ( V_60 ) ;
}
}
static void F_21 ( struct V_60 * V_60 )
{
struct V_33 * V_34 = V_60 -> V_62 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
struct V_63 * V_64 ;
int V_65 = V_60 -> V_65 ;
V_64 = F_22 ( V_34 -> V_10 ) ;
F_19 ( V_60 -> V_61 ) ;
F_23 ( V_34 -> V_10 -> V_14 ) ;
if ( V_65 )
F_10 ( & V_34 -> V_29 , L_3
L_4 , V_66 , V_65 ) ;
F_24 ( & V_36 -> V_67 ) ;
-- V_36 -> V_68 ;
F_25 ( & V_36 -> V_67 ) ;
F_24 ( & V_64 -> V_69 ) ;
-- V_64 -> V_70 ;
F_25 ( & V_64 -> V_69 ) ;
F_26 ( V_34 ) ;
}
static int F_27 ( struct V_44 * V_45 , struct V_33 * V_34 ,
const unsigned char * V_71 , int V_72 )
{
struct V_35 * V_36 ;
struct V_63 * V_64 ;
struct V_9 * V_10 = V_34 -> V_10 ;
unsigned long V_73 ;
unsigned char * V_74 ;
struct V_60 * V_60 ;
T_3 V_75 = F_28 ( ( T_3 ) V_72 , ( T_3 ) V_76 ) ;
int V_39 = 0 ;
if ( V_72 == 0 )
return 0 ;
V_36 = F_13 ( V_34 ) ;
V_64 = F_22 ( V_10 ) ;
F_10 ( & V_34 -> V_29 , L_5 , V_66 , V_75 ) ;
F_29 ( & V_36 -> V_67 , V_73 ) ;
F_10 ( & V_34 -> V_29 , L_6 , V_66 ,
V_36 -> V_68 ) ;
if ( V_36 -> V_68 > V_36 -> V_77 ) {
F_30 ( & V_36 -> V_67 , V_73 ) ;
F_10 ( & V_34 -> V_29 , L_7 , V_66 ) ;
return 0 ;
}
V_36 -> V_68 ++ ;
F_10 ( & V_34 -> V_29 , L_8 , V_66 ,
V_36 -> V_68 ) ;
F_30 ( & V_36 -> V_67 , V_73 ) ;
V_39 = F_31 ( V_10 -> V_14 ) ;
if ( V_39 < 0 ) {
F_29 ( & V_36 -> V_67 , V_73 ) ;
V_36 -> V_68 -- ;
F_30 ( & V_36 -> V_67 , V_73 ) ;
goto V_78;
}
V_74 = F_32 ( V_75 , V_79 ) ;
if ( ! V_74 ) {
V_39 = - V_80 ;
goto V_81;
}
V_60 = F_33 ( 0 , V_79 ) ;
if ( ! V_60 ) {
V_39 = - V_80 ;
goto V_82;
}
memcpy ( V_74 , V_71 , V_75 ) ;
F_34 ( & V_34 -> V_29 , V_66 , V_75 , V_74 ) ;
F_35 ( V_60 , V_10 -> V_29 ,
F_36 ( V_10 -> V_29 ,
V_34 -> V_43 ) ,
V_74 , V_75 , F_21 , V_34 ) ;
V_60 -> V_83 |= V_84 ;
F_29 ( & V_64 -> V_69 , V_73 ) ;
if ( V_64 -> V_85 ) {
F_37 ( V_60 , & V_36 -> V_86 ) ;
F_30 ( & V_64 -> V_69 , V_73 ) ;
goto V_87;
} else {
F_37 ( V_60 , & V_36 -> V_88 ) ;
}
V_39 = F_38 ( V_60 , V_79 ) ;
if ( V_39 ) {
F_39 ( V_60 ) ;
F_30 ( & V_64 -> V_69 , V_73 ) ;
F_40 ( & V_34 -> V_29 , L_9
L_10 , V_66 , V_39 ) ;
goto error;
} else {
V_64 -> V_70 ++ ;
F_30 ( & V_64 -> V_69 , V_73 ) ;
}
V_87:
F_20 ( V_60 ) ;
return V_75 ;
error:
F_20 ( V_60 ) ;
V_82:
F_19 ( V_74 ) ;
V_81:
F_29 ( & V_36 -> V_67 , V_73 ) ;
-- V_36 -> V_68 ;
F_10 ( & V_34 -> V_29 , L_11 , V_66 ,
V_36 -> V_68 ) ;
F_30 ( & V_36 -> V_67 , V_73 ) ;
F_23 ( V_10 -> V_14 ) ;
V_78:
return V_39 ;
}
static void F_41 ( struct V_60 * V_60 )
{
int V_89 ;
int V_90 ;
struct V_33 * V_34 ;
unsigned char * V_91 = V_60 -> V_61 ;
int V_65 = V_60 -> V_65 ;
V_90 = F_42 ( V_60 -> V_92 ) ;
V_34 = V_60 -> V_62 ;
if ( V_65 ) {
F_10 ( & V_34 -> V_29 , L_12
L_13 , V_66 , V_65 , V_90 ) ;
} else {
if ( V_60 -> V_93 ) {
F_43 ( & V_34 -> V_34 , V_91 ,
V_60 -> V_93 ) ;
F_44 ( & V_34 -> V_34 ) ;
F_34 ( & V_34 -> V_29 , V_66 ,
V_60 -> V_93 , V_91 ) ;
} else {
F_10 ( & V_34 -> V_29 , L_14
L_15 , V_66 ) ;
}
}
if ( V_65 != - V_94 && V_65 != - V_95 ) {
F_45 ( V_34 -> V_10 -> V_29 ) ;
V_89 = F_38 ( V_60 , V_79 ) ;
if ( V_89 && V_89 != - V_95 )
F_40 ( & V_34 -> V_29 , L_16
L_17 , V_89 ) ;
}
}
static void F_46 ( struct V_60 * V_60 )
{
int V_89 ;
int V_65 = V_60 -> V_65 ;
struct V_33 * V_34 = V_60 -> V_62 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
struct V_9 * V_10 = V_34 -> V_10 ;
F_10 ( & V_34 -> V_29 , L_18 , V_66 ,
V_60 , V_34 , V_36 ) ;
if ( V_65 == 0 ) {
struct V_96 * V_97 =
(struct V_96 * ) V_60 -> V_61 ;
if ( ! V_97 ) {
F_10 ( & V_34 -> V_29 , L_19 ,
V_66 ) ;
return;
}
if ( ( V_97 -> V_98 == 0xA1 ) &&
( V_97 -> V_99 == 0x20 ) ) {
int V_100 ;
unsigned char V_101 = * ( ( unsigned char * )
V_60 -> V_61 +
sizeof( struct V_96 ) ) ;
F_10 ( & V_34 -> V_29 , L_20 , V_66 ,
V_101 ) ;
V_100 = V_36 -> V_54 ;
V_36 -> V_50 = 1 ;
V_36 -> V_54 = ( ( V_101 & 0x01 ) ? 1 : 0 ) ;
V_36 -> V_52 = ( ( V_101 & 0x02 ) ? 1 : 0 ) ;
V_36 -> V_56 = ( ( V_101 & 0x08 ) ? 1 : 0 ) ;
if ( V_100 && ! V_36 -> V_54 )
F_47 ( & V_34 -> V_34 , true ) ;
} else {
F_10 ( & V_34 -> V_29 , L_21 ,
V_66 , V_97 -> V_98 ,
V_97 -> V_99 ) ;
}
} else
F_10 ( & V_34 -> V_29 , L_22 , V_66 , V_65 ) ;
if ( V_65 != - V_94 && V_65 != - V_102 ) {
F_45 ( V_10 -> V_29 ) ;
V_89 = F_38 ( V_60 , V_79 ) ;
if ( V_89 && V_89 != - V_95 )
F_40 ( & V_34 -> V_29 , L_23
L_24 , V_66 , V_89 ) ;
}
}
static int F_48 ( struct V_44 * V_45 )
{
struct V_33 * V_34 = V_45 -> V_46 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
unsigned long V_73 ;
F_29 ( & V_36 -> V_67 , V_73 ) ;
if ( V_36 -> V_68 > ( V_36 -> V_77 * 2 ) / 3 ) {
F_30 ( & V_36 -> V_67 , V_73 ) ;
F_10 ( & V_34 -> V_29 , L_7 , V_66 ) ;
return 0 ;
}
F_30 ( & V_36 -> V_67 , V_73 ) ;
return 2048 ;
}
static int F_49 ( struct V_44 * V_45 )
{
struct V_33 * V_34 = V_45 -> V_46 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
unsigned long V_73 ;
int V_103 ;
F_29 ( & V_36 -> V_67 , V_73 ) ;
V_103 = V_36 -> V_68 * V_76 ;
F_30 ( & V_36 -> V_67 , V_73 ) ;
F_10 ( & V_34 -> V_29 , L_25 , V_66 , V_103 ) ;
return V_103 ;
}
static void F_50 ( struct V_33 * V_34 )
{
int V_22 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
for ( V_22 = 0 ; V_22 < V_36 -> V_104 ; V_22 ++ )
F_51 ( V_36 -> V_105 [ V_22 ] ) ;
F_51 ( V_34 -> V_42 ) ;
}
static int F_52 ( struct V_33 * V_34 , T_4 V_106 )
{
int V_107 ;
int V_89 = - V_108 ;
int V_22 ;
struct V_60 * V_60 ;
struct V_35 * V_36 = F_13 ( V_34 ) ;
V_107 = 0 ;
for ( V_22 = 0 ; V_22 < V_36 -> V_104 ; V_22 ++ ) {
V_60 = V_36 -> V_105 [ V_22 ] ;
if ( ! V_60 )
continue;
V_89 = F_38 ( V_60 , V_106 ) ;
if ( V_89 ) {
F_40 ( & V_34 -> V_29 , L_26 ,
V_66 , V_89 ) ;
} else {
V_107 ++ ;
}
}
if ( V_107 && V_34 -> V_42 ) {
V_89 = F_38 ( V_34 -> V_42 , V_106 ) ;
if ( V_89 ) {
F_40 ( & V_34 -> V_29 , L_27 ,
V_66 , V_89 ) ;
}
}
if ( V_107 > 0 )
return 0 ;
else
return V_89 ;
}
static struct V_60 * F_53 ( struct V_9 * V_10 , int V_90 ,
int V_109 , void * V_110 , int V_111 ,
T_4 V_106 ,
T_5 V_112 )
{
struct V_60 * V_60 ;
T_2 * V_71 ;
V_60 = F_33 ( 0 , V_106 ) ;
if ( ! V_60 )
return NULL ;
V_71 = F_32 ( V_111 , V_106 ) ;
if ( V_71 ) {
F_35 ( V_60 , V_10 -> V_29 ,
F_36 ( V_10 -> V_29 , V_90 ) | V_109 ,
V_71 , V_111 , V_112 , V_110 ) ;
F_10 ( & V_10 -> V_29 -> V_29 , L_28 , V_66 ,
V_109 == V_113 ? 'i' : 'o' , V_60 , V_71 ) ;
} else {
F_18 ( V_60 ) ;
V_60 = NULL ;
}
return V_60 ;
}
static void F_54 ( struct V_33 * V_34 )
{
int V_22 ;
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_35 * V_36 ;
struct V_63 * V_64 = F_22 ( V_10 ) ;
struct V_60 * V_60 ;
V_36 = F_13 ( V_34 ) ;
F_55 ( & V_64 -> V_69 ) ;
if ( -- V_64 -> V_114 == 0 )
V_10 -> V_14 -> V_115 = 0 ;
F_56 ( & V_64 -> V_69 ) ;
for (; ; ) {
V_60 = F_57 ( & V_36 -> V_86 ) ;
if ( ! V_60 )
break;
F_19 ( V_60 -> V_61 ) ;
F_20 ( V_60 ) ;
F_23 ( V_10 -> V_14 ) ;
F_24 ( & V_36 -> V_67 ) ;
V_36 -> V_68 -- ;
F_25 ( & V_36 -> V_67 ) ;
}
F_50 ( V_34 ) ;
F_58 ( & V_36 -> V_88 ) ;
for ( V_22 = 0 ; V_22 < V_36 -> V_104 ; V_22 ++ ) {
F_18 ( V_36 -> V_105 [ V_22 ] ) ;
V_36 -> V_105 [ V_22 ] = NULL ;
}
F_59 ( V_10 -> V_14 ) ;
}
static int F_60 ( struct V_44 * V_45 , struct V_33 * V_34 )
{
struct V_35 * V_36 ;
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_63 * V_64 = F_22 ( V_10 ) ;
int V_22 ;
int V_89 ;
int V_90 ;
struct V_60 * V_60 ;
V_36 = F_13 ( V_34 ) ;
V_90 = V_34 -> V_116 ;
for ( V_22 = 0 ; V_22 < V_36 -> V_104 ; V_22 ++ ) {
V_60 = F_53 ( V_10 , V_90 , V_113 , V_34 ,
V_117 , V_118 ,
F_41 ) ;
V_36 -> V_105 [ V_22 ] = V_60 ;
}
F_61 ( V_10 -> V_29 ,
F_36 ( V_10 -> V_29 , V_90 ) | V_113 ) ;
V_89 = F_52 ( V_34 , V_118 ) ;
if ( V_89 )
goto V_119;
F_55 ( & V_64 -> V_69 ) ;
if ( ++ V_64 -> V_114 == 1 )
V_10 -> V_14 -> V_115 = 1 ;
F_56 ( & V_64 -> V_69 ) ;
F_15 ( V_10 -> V_14 ) ;
return 0 ;
V_119:
F_50 ( V_34 ) ;
for ( V_22 = 0 ; V_22 < V_36 -> V_104 ; V_22 ++ ) {
F_18 ( V_36 -> V_105 [ V_22 ] ) ;
V_36 -> V_105 [ V_22 ] = NULL ;
}
return V_89 ;
}
static void F_62 ( struct V_33 * V_34 , int V_120 )
{
struct V_35 * V_36 ;
V_36 = F_13 ( V_34 ) ;
V_36 -> V_41 = V_120 ;
V_36 -> V_40 = V_120 ;
F_12 ( V_34 ) ;
}
static int F_63 ( struct V_9 * V_10 )
{
struct V_63 * V_64 ;
V_64 = F_64 ( sizeof( * V_64 ) , V_118 ) ;
if ( ! V_64 )
return - V_80 ;
F_65 ( & V_64 -> V_69 ) ;
F_66 ( V_10 , V_64 ) ;
F_1 ( V_10 -> V_29 , 0x0000 ) ;
if ( V_121 )
F_4 ( V_10 -> V_29 , 1 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_63 * V_64 ;
V_64 = F_22 ( V_10 ) ;
F_19 ( V_64 ) ;
}
static int F_68 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_35 * V_36 ;
const struct V_19 * V_122 ;
T_2 V_12 ;
V_36 = F_64 ( sizeof( * V_36 ) , V_118 ) ;
if ( ! V_36 )
return - V_80 ;
F_65 ( & V_36 -> V_67 ) ;
F_69 ( & V_36 -> V_88 ) ;
F_69 ( & V_36 -> V_86 ) ;
V_36 -> V_77 = V_123 ;
V_36 -> V_104 = V_124 ;
if ( V_10 -> V_11 == 1 ) {
V_12 = F_8 ( V_10 ) ;
V_122 = & V_125 ;
} else {
V_12 = V_34 -> V_126 ;
V_122 = & V_127 ;
}
if ( F_7 ( V_12 , V_122 ) ) {
V_36 -> V_77 = V_128 ;
V_36 -> V_104 = V_129 ;
}
F_10 ( & V_34 -> V_29 ,
L_29 ,
V_12 , V_36 -> V_104 , V_36 -> V_77 ) ;
F_70 ( V_34 , V_36 ) ;
return 0 ;
}
static int F_71 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_13 ( V_34 ) ;
F_70 ( V_34 , NULL ) ;
F_19 ( V_36 ) ;
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
int V_22 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; ++ V_22 ) {
V_34 = V_10 -> V_34 [ V_22 ] ;
V_36 = F_13 ( V_34 ) ;
if ( ! V_36 )
continue;
F_50 ( V_34 ) ;
F_58 ( & V_36 -> V_88 ) ;
}
}
static int F_73 ( struct V_9 * V_10 , T_6 V_130 )
{
struct V_63 * V_64 = F_22 ( V_10 ) ;
F_55 ( & V_64 -> V_69 ) ;
if ( F_74 ( V_130 ) ) {
if ( V_64 -> V_70 ) {
F_56 ( & V_64 -> V_69 ) ;
return - V_131 ;
}
}
V_64 -> V_85 = 1 ;
F_56 ( & V_64 -> V_69 ) ;
F_72 ( V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_13 ( V_34 ) ;
struct V_63 * V_64 ;
struct V_60 * V_60 ;
int V_132 = 0 ;
int V_89 ;
V_64 = F_22 ( V_34 -> V_10 ) ;
for (; ; ) {
V_60 = F_57 ( & V_36 -> V_86 ) ;
if ( ! V_60 )
break;
F_37 ( V_60 , & V_36 -> V_88 ) ;
V_64 -> V_70 ++ ;
V_89 = F_38 ( V_60 , V_79 ) ;
if ( V_89 ) {
F_40 ( & V_34 -> V_29 , L_30 ,
V_66 , V_89 ) ;
V_132 ++ ;
V_64 -> V_70 -- ;
F_39 ( V_60 ) ;
F_19 ( V_60 -> V_61 ) ;
F_20 ( V_60 ) ;
F_24 ( & V_36 -> V_67 ) ;
V_36 -> V_68 -- ;
F_25 ( & V_36 -> V_67 ) ;
}
}
if ( V_132 )
return - V_133 ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 )
{
struct V_33 * V_34 ;
struct V_63 * V_64 = F_22 ( V_10 ) ;
int V_132 = 0 ;
int V_22 , V_89 ;
F_55 ( & V_64 -> V_69 ) ;
for ( V_22 = 0 ; V_22 < V_10 -> V_11 ; V_22 ++ ) {
V_34 = V_10 -> V_34 [ V_22 ] ;
if ( ! F_77 ( & V_34 -> V_34 ) )
continue;
V_89 = F_75 ( V_34 ) ;
if ( V_89 )
V_132 ++ ;
V_89 = F_52 ( V_34 , V_79 ) ;
if ( V_89 )
V_132 ++ ;
}
V_64 -> V_85 = 0 ;
F_56 ( & V_64 -> V_69 ) ;
return V_132 ? - V_133 : 0 ;
}
