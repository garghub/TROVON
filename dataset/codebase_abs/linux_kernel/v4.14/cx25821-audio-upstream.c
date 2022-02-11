static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 ;
T_1 V_9 ;
if ( V_4 -> V_10 == 0 ) {
F_2 ( V_4 -> V_11 , 0 ) ;
F_2 ( V_4 -> V_12 , 0 ) ;
F_2 ( V_4 -> V_13 , 0 ) ;
F_2 ( V_4 -> V_14 , 0 ) ;
return 0 ;
}
V_5 = ( V_5 + 7 ) & ~ 7 ;
V_9 = V_4 -> V_9 ;
V_8 = V_4 -> V_15 / V_5 ;
if ( V_8 > 3 )
V_8 = 3 ;
F_3 ( V_8 < 2 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
F_2 ( V_9 + 16 * V_7 , V_4 -> V_16 + V_5 * V_7 ) ;
F_2 ( V_9 + 16 * V_7 + 4 , 0 ) ;
F_2 ( V_9 + 16 * V_7 + 8 , 0 ) ;
F_2 ( V_9 + 16 * V_7 + 12 , 0 ) ;
}
F_2 ( V_4 -> V_10 + 0 , V_6 ) ;
F_2 ( V_4 -> V_10 + 4 , 0 ) ;
F_2 ( V_4 -> V_10 + 8 , V_9 ) ;
F_2 ( V_4 -> V_10 + 12 , V_17 ) ;
F_2 ( V_4 -> V_10 + 16 , V_4 -> V_18 ) ;
F_2 ( V_4 -> V_10 + 20 , V_19 ) ;
for ( V_7 = 24 ; V_7 < 80 ; V_7 += 4 )
F_2 ( V_4 -> V_10 + V_7 , 0 ) ;
F_2 ( V_4 -> V_11 , V_4 -> V_16 ) ;
F_2 ( V_4 -> V_12 , V_9 ) ;
F_2 ( V_4 -> V_13 , V_17 ) ;
F_2 ( V_4 -> V_14 , V_20 - 1 ) ;
return 0 ;
}
static T_2 * F_4 ( struct V_1 * V_2 ,
T_2 * V_21 ,
T_3 V_22 ,
unsigned int V_5 ,
int V_23 )
{
unsigned int line ;
const struct V_3 * V_24 =
V_2 -> V_25 [ V_2 -> V_26 ] . V_27 ;
int V_28 = 0 ;
for ( line = 0 ; line < V_29 ; line ++ ) {
* ( V_21 ++ ) = F_5 ( V_30 | V_31 | V_32 | V_5 ) ;
* ( V_21 ++ ) = F_5 ( V_22 + V_28 ) ;
* ( V_21 ++ ) = F_5 ( 0 ) ;
if ( V_23 && line == 2 ) {
* ( V_21 ++ ) = V_33 ;
* ( V_21 ++ ) = V_24 -> V_34 ;
* ( V_21 ++ ) = V_24 -> V_35 ;
* ( V_21 ++ ) = 0x00000020 ;
}
V_28 += V_36 ;
}
return V_21 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
unsigned int V_5 , unsigned int V_8 )
{
T_2 * V_21 ;
int V_23 = 0 ;
int V_39 = 0 , V_7 = 0 ;
int V_40 = V_41 ;
int V_42 = 0 ;
int V_43 = V_44 ;
T_3 V_45 ;
V_21 = V_2 -> V_46 ;
* ( V_21 ++ ) = F_5 ( V_47 | V_48 ) ;
for ( V_39 = 0 ; V_39 < V_49 ; V_39 ++ ) {
V_42 = V_40 * V_39 ;
if ( V_39 == 0 ) {
V_23 = 1 ;
V_43 = V_50 ;
} else {
V_23 = 0 ;
V_43 = V_44 ;
}
if ( ( V_39 + 1 ) == V_49 ) {
V_45 =
V_2 -> V_51 +
V_52 ;
} else {
V_45 =
V_2 -> V_51 +
V_52 +
V_53 * ( V_39 + 1 ) ;
}
V_21 = F_4 ( V_2 , V_21 ,
V_2 -> V_54 + V_42 ,
V_5 , V_23 ) ;
if ( V_55 ) {
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ )
* ( V_21 ++ ) = F_5 ( V_57 ) ;
}
* ( V_21 ++ ) = F_5 ( V_58 | V_59 | V_43 ) ;
* ( V_21 ++ ) = F_5 ( V_45 ) ;
* ( V_21 ++ ) = F_5 ( 0 ) ;
V_21 = V_2 -> V_46 + V_52 / 4 +
( V_53 * ( V_39 + 1 ) / 4 ) ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_8 ( V_2 -> V_38 , V_2 -> V_60 ,
V_2 -> V_46 , V_2 -> V_61 ) ;
V_2 -> V_46 = NULL ;
}
if ( V_2 -> V_62 ) {
F_8 ( V_2 -> V_38 , V_2 -> V_63 ,
V_2 -> V_62 ,
V_2 -> V_54 ) ;
V_2 -> V_62 = NULL ;
}
}
void F_9 ( struct V_1 * V_2 )
{
const struct V_3 * V_24 =
V_2 -> V_25 [ V_64 ] . V_27 ;
T_1 V_65 = 0 ;
if ( ! V_2 -> V_66 ) {
F_10 (KERN_DEBUG
pr_fmt(L_1)) ;
return;
}
F_2 ( V_24 -> V_67 , 0 ) ;
V_65 = F_11 ( V_24 -> V_34 ) ;
F_2 ( V_24 -> V_34 ,
V_65 & ~ ( V_24 -> V_35 | V_24 -> V_68 ) ) ;
if ( V_2 -> V_62 )
memset ( V_2 -> V_62 , 0 ,
V_2 -> V_63 ) ;
V_2 -> V_66 = 0 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_71 = V_72 ;
F_12 ( & V_2 -> V_73 ) ;
F_13 ( V_2 -> V_74 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 )
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_24 )
{
struct V_75 * V_75 ;
int V_76 = V_2 -> V_77 ;
int V_7 = 0 ;
int V_40 = V_41 ;
int V_78 = V_40 * V_76 ;
char V_79 [ V_36 ] ;
T_4 V_80 = V_2 -> V_70 * V_40 ;
char * V_81 = NULL ;
if ( V_2 -> V_71 == V_72 )
return 0 ;
V_75 = F_16 ( V_2 -> V_74 , V_82 | V_83 , 0 ) ;
if ( F_17 ( V_75 ) ) {
F_18 ( L_2 ,
V_84 , V_2 -> V_74 , - F_19 ( V_75 ) ) ;
return F_19 ( V_75 ) ;
}
if ( V_2 -> V_62 )
V_81 = ( char * ) V_2 -> V_62 + V_78 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_85 ; V_7 ++ ) {
int V_86 = F_20 ( V_75 , V_79 , V_36 , & V_80 ) ;
if ( V_86 < V_36 ) {
F_21 ( L_3 ,
V_84 ) ;
V_2 -> V_71 = V_72 ;
F_22 ( V_75 ) ;
return 0 ;
}
V_2 -> V_71 = V_87 ;
if ( V_81 ) {
memcpy ( V_81 , V_79 , V_86 ) ;
V_81 += V_86 ;
}
}
V_2 -> V_70 ++ ;
F_22 ( V_75 ) ;
return 0 ;
}
static void F_23 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_24 ( V_89 , struct V_1 ,
V_73 ) ;
if ( ! V_2 ) {
F_18 ( L_4 ,
V_84 ) ;
return;
}
F_15 ( V_2 , V_2 -> V_25 [ V_2 -> V_26 ] .
V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_3 * V_24 )
{
char * V_81 = ( void * ) V_2 -> V_62 ;
struct V_75 * V_75 ;
T_4 V_80 = 0 ;
int V_7 , V_90 ;
V_75 = F_16 ( V_2 -> V_74 , V_82 | V_83 , 0 ) ;
if ( F_17 ( V_75 ) ) {
F_18 ( L_2 ,
V_84 , V_2 -> V_74 , F_19 ( V_75 ) ) ;
return F_19 ( V_75 ) ;
}
for ( V_90 = 0 ; V_90 < V_49 ; V_90 ++ ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_85 ; V_7 ++ ) {
char V_91 [ V_36 ] ;
T_4 V_28 = V_80 ;
int V_86 = F_20 ( V_75 , V_91 , V_36 , & V_80 ) ;
if ( V_86 < V_36 ) {
F_21 ( L_3 ,
V_84 ) ;
V_2 -> V_71 = V_72 ;
F_22 ( V_75 ) ;
return 0 ;
}
if ( V_81 )
memcpy ( V_81 + V_28 , V_91 , V_86 ) ;
}
V_2 -> V_70 ++ ;
}
V_2 -> V_71 = V_87 ;
F_22 ( V_75 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_3 * V_24 ,
int V_5 )
{
int V_92 = 0 ;
T_3 V_93 ;
T_3 V_94 ;
F_7 ( V_2 ) ;
V_2 -> V_46 = F_27 ( V_2 -> V_38 ,
V_2 -> V_95 , & V_93 ) ;
V_2 -> V_96 = V_2 -> V_46 ;
V_2 -> V_51 = V_93 ;
V_2 -> V_61 = V_93 ;
V_2 -> V_60 = V_2 -> V_95 ;
if ( ! V_2 -> V_46 ) {
F_10 (KERN_DEBUG
pr_fmt(L_5)) ;
return - V_97 ;
}
memset ( V_2 -> V_46 , 0 , V_2 -> V_60 ) ;
V_2 -> V_62 = F_27 ( V_2 -> V_38 ,
V_2 -> V_98 , & V_94 ) ;
V_2 -> V_54 = V_94 ;
V_2 -> V_63 = V_2 -> V_98 ;
if ( ! V_2 -> V_62 ) {
F_10 (KERN_DEBUG
pr_fmt(L_6)) ;
return - V_97 ;
}
memset ( V_2 -> V_62 , 0 , V_2 -> V_63 ) ;
V_92 = F_25 ( V_2 , V_24 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_6 ( V_2 , V_2 -> V_38 , V_5 ,
V_2 -> V_85 ) ;
if ( V_92 < 0 ) {
F_10 (KERN_DEBUG
pr_fmt(L_7)) ;
goto error;
}
return 0 ;
error:
return V_92 ;
}
static int F_28 ( struct V_1 * V_2 , int V_99 ,
T_1 V_100 )
{
int V_7 = 0 ;
T_1 V_101 ;
const struct V_3 * V_102 = V_2 -> V_25 [ V_99 ] . V_27 ;
T_3 V_45 ;
T_2 * V_21 ;
if ( V_100 & V_103 ) {
T_1 V_104 = F_11 ( V_102 -> V_105 ) ;
F_2 ( V_102 -> V_67 , 0 ) ;
F_2 ( V_102 -> V_106 , F_11 ( V_102 -> V_106 ) ) ;
F_29 ( & V_2 -> V_107 ) ;
while ( V_104 != V_2 -> V_108 ) {
if ( V_2 -> V_108 < ( V_109 - 1 ) )
V_2 -> V_108 ++ ;
else
V_2 -> V_108 = 0 ;
V_2 -> V_77 = V_2 -> V_108 ;
F_30 ( & V_2 -> V_73 ) ;
}
if ( V_2 -> V_69 ) {
V_2 -> V_69 = 0 ;
if ( V_2 -> V_96 != NULL ) {
V_45 =
V_2 -> V_51 +
V_52 +
V_53 ;
V_21 = F_4 ( V_2 ,
V_2 -> V_96 + 1 ,
V_2 -> V_54 ,
V_36 , V_110 ) ;
if ( V_55 ) {
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
* ( V_21 ++ ) =
F_5 ( V_57 ) ;
}
}
* ( V_21 ++ ) = F_5 ( V_58 | V_59 |
V_50 ) ;
* ( V_21 ++ ) = F_5 ( V_45 ) ;
* ( V_21 ++ ) = F_5 ( 0 ) ;
}
}
F_31 ( & V_2 -> V_107 ) ;
} else {
if ( V_100 & V_111 )
F_32 ( L_8 ,
V_84 ) ;
if ( V_100 & V_112 )
F_32 ( L_9 ,
V_84 ) ;
if ( V_100 & V_113 )
F_32 ( L_10 ,
V_84 ) ;
F_2 ( V_102 -> V_106 , F_11 ( V_102 -> V_106 ) ) ;
}
if ( V_2 -> V_71 == V_72 ) {
F_32 ( L_11 ,
V_2 -> V_70 ) ;
return - 1 ;
}
V_101 = F_11 ( V_102 -> V_67 ) ;
F_2 ( V_102 -> V_67 , V_101 |= V_114 ) ;
return 0 ;
}
static T_5 F_33 ( int V_115 , void * V_116 )
{
struct V_1 * V_2 = V_116 ;
T_1 V_117 ;
int V_118 = 0 ;
const struct V_3 * V_24 ;
if ( ! V_2 )
return - 1 ;
V_24 = V_2 -> V_25 [ V_2 -> V_26 ] . V_27 ;
V_117 = F_11 ( V_24 -> V_106 ) ;
if ( V_117 ) {
V_118 = F_28 ( V_2 ,
V_2 -> V_26 , V_117 ) ;
}
if ( V_118 < 0 )
F_9 ( V_2 ) ;
else
V_118 += V_118 ;
return F_34 ( V_118 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
const struct V_3 * V_24 )
{
int V_119 = 0 ;
T_1 V_65 ;
do {
F_36 ( 10 ) ;
V_65 = F_11 ( V_24 -> V_34 ) ;
if ( V_119 ++ > 1000 ) {
F_18 ( L_12 ,
V_84 ) ;
return;
}
} while ( ! ( V_65 & V_24 -> V_35 ) );
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_3 * V_24 )
{
T_1 V_65 = 0 ;
int V_120 = 0 ;
F_2 ( V_24 -> V_10 + 0 , V_2 -> V_61 ) ;
F_2 ( V_24 -> V_10 + 4 , 0 ) ;
F_2 ( V_24 -> V_121 , 3 ) ;
F_2 ( V_24 -> V_122 , V_36 & V_123 ) ;
V_65 = F_11 ( V_24 -> V_124 ) ;
V_65 |= V_125 | V_126 | V_127 |
V_128 | V_129 |
V_130 ;
F_2 ( V_24 -> V_124 , V_65 ) ;
V_65 = F_11 ( V_24 -> V_106 ) ;
F_2 ( V_24 -> V_106 , V_65 ) ;
F_2 ( V_24 -> V_106 , V_114 ) ;
F_38 ( V_131 , F_11 ( V_131 ) | ( 1 << V_24 -> V_132 ) ) ;
V_65 = F_11 ( V_24 -> V_67 ) ;
F_2 ( V_24 -> V_67 , V_65 |= V_114 ) ;
V_120 = F_39 ( V_2 -> V_38 -> V_115 , F_33 ,
V_133 , V_2 -> V_134 , V_2 ) ;
if ( V_120 < 0 ) {
F_18 ( L_13 , V_2 -> V_134 ,
V_2 -> V_38 -> V_115 ) ;
goto V_135;
}
V_65 = F_11 ( V_24 -> V_34 ) ;
F_38 ( V_24 -> V_34 , V_65 | V_24 -> V_68 ) ;
V_2 -> V_66 = 1 ;
V_2 -> V_69 = 1 ;
F_35 ( V_2 , V_24 ) ;
return 0 ;
V_135:
F_40 ( V_2 ) ;
return V_120 ;
}
int F_41 ( struct V_1 * V_2 , int V_136 )
{
const struct V_3 * V_24 ;
int V_120 = 0 ;
if ( V_2 -> V_66 ) {
F_32 ( L_14 ) ;
return 0 ;
}
V_2 -> V_26 = V_136 ;
V_24 = V_2 -> V_25 [ V_136 ] . V_27 ;
F_42 ( & V_2 -> V_73 , F_23 ) ;
V_2 -> V_108 = 0 ;
V_2 -> V_66 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_71 = V_137 ;
V_2 -> V_85 = V_29 ;
V_138 = V_36 ;
if ( ( V_2 -> V_139 ) &&
( strcmp ( V_2 -> V_139 , L_15 ) != 0 ) )
V_2 -> V_74 = F_43 ( V_2 -> V_139 ,
V_140 ) ;
else
V_2 -> V_74 = F_43 ( V_141 ,
V_140 ) ;
if ( ! V_2 -> V_74 ) {
V_120 = - V_97 ;
goto error;
}
F_1 ( V_2 , V_24 ,
V_138 , 0 ) ;
V_2 -> V_95 =
V_53 * V_142 +
V_52 ;
V_2 -> V_98 = V_41 * V_142 ;
V_120 = F_26 ( V_2 , V_24 ,
V_138 ) ;
if ( V_120 < 0 ) {
F_18 ( L_16 ,
V_2 -> V_134 ) ;
goto error;
}
F_37 ( V_2 , V_24 ) ;
return 0 ;
error:
F_40 ( V_2 ) ;
return V_120 ;
}
