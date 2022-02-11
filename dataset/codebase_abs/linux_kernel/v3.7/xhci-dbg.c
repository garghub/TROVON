void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , L_1 ,
V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
F_2 ( V_2 , L_2 ,
& V_2 -> V_4 -> V_5 , V_3 ) ;
F_2 ( V_2 , L_3 ,
( unsigned int ) F_4 ( V_3 ) ) ;
#if 0
xhci_dbg(xhci, "// HCIVERSION: 0x%x\n",
(unsigned int) HC_VERSION(temp));
#endif
F_2 ( V_2 , L_4 , V_2 -> V_6 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_5 ,
& V_2 -> V_4 -> V_7 ,
( unsigned int ) V_3 & V_8 ) ;
F_2 ( V_2 , L_6 , V_2 -> V_9 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_10 ) ;
F_2 ( V_2 , L_7 , & V_2 -> V_4 -> V_10 , V_3 ) ;
F_2 ( V_2 , L_8 , V_2 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , L_9 , V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
F_2 ( V_2 , L_10 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_11 ,
( unsigned int ) F_4 ( V_3 ) ) ;
F_2 ( V_2 , L_12 ,
( unsigned int ) F_6 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_12 ) ;
F_2 ( V_2 , L_13 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_14 ,
( unsigned int ) F_7 ( V_3 ) ) ;
F_2 ( V_2 , L_15 ,
( unsigned int ) F_8 ( V_3 ) ) ;
F_2 ( V_2 , L_16 ,
( unsigned int ) F_9 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_13 ) ;
F_2 ( V_2 , L_17 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_18 ,
( unsigned int ) F_10 ( V_3 ) ) ;
F_2 ( V_2 , L_19 ,
( unsigned int ) F_11 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_14 ) ;
F_2 ( V_2 , L_20 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_21 ,
( unsigned int ) F_12 ( V_3 ) ) ;
F_2 ( V_2 , L_22 ,
( unsigned int ) F_13 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_15 ) ;
F_2 ( V_2 , L_23 , ( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_24 ,
F_14 ( V_3 ) ? L_25 : L_26 ) ;
F_2 ( V_2 , L_27 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_28 , V_3 & V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , & V_2 -> V_6 -> V_16 ) ;
F_2 ( V_2 , L_29 , V_3 ) ;
F_2 ( V_2 , L_30 ,
( V_3 & V_17 ) ? L_31 : L_32 ) ;
F_2 ( V_2 , L_33 ,
( V_3 & V_18 ) ? L_34 : L_35 ) ;
F_2 ( V_2 , L_36 ,
( V_3 & V_19 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_39 ,
( V_3 & V_20 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_40 ,
( V_3 & V_21 ) ? L_34 : L_35 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , & V_2 -> V_6 -> V_22 ) ;
F_2 ( V_2 , L_41 , V_3 ) ;
F_2 ( V_2 , L_42 ,
( V_3 & V_23 ) ? L_34 : L_35 ) ;
F_2 ( V_2 , L_43 ,
( V_3 & V_24 ) ? L_44 : L_45 ) ;
F_2 ( V_2 , L_30 ,
( V_3 & V_25 ) ? L_46 : L_31 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_47 , V_2 -> V_6 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 T_3 * V_26 ;
int V_27 , V_28 ;
int V_29 ;
char * V_30 [ V_31 ] = {
L_48 ,
L_49 ,
L_50 ,
L_51 ,
} ;
V_29 = F_9 ( V_2 -> V_12 ) ;
V_26 = & V_2 -> V_6 -> V_32 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
for ( V_28 = 0 ; V_28 < V_31 ; ++ V_28 ) {
F_2 ( V_2 , L_52 ,
V_26 , V_30 [ V_28 ] ,
( unsigned int ) F_3 ( V_2 , V_26 ) ) ;
V_26 ++ ;
}
}
}
void F_19 ( struct V_1 * V_2 , int V_33 )
{
struct V_34 T_3 * V_35 = & V_2 -> V_9 -> V_35 [ V_33 ] ;
void T_3 * V_26 ;
T_1 V_3 ;
T_4 V_36 ;
V_26 = & V_35 -> V_37 ;
V_3 = F_3 ( V_2 , V_26 ) ;
if ( V_3 == V_38 )
return;
F_2 ( V_2 , L_53 , V_35 , V_33 ) ;
F_2 ( V_2 , L_54 , V_26 ,
( unsigned int ) V_3 ) ;
V_26 = & V_35 -> V_39 ;
V_3 = F_3 ( V_2 , V_26 ) ;
F_2 ( V_2 , L_55 , V_26 ,
( unsigned int ) V_3 ) ;
V_26 = & V_35 -> V_40 ;
V_3 = F_3 ( V_2 , V_26 ) ;
F_2 ( V_2 , L_56 , V_26 ,
( unsigned int ) V_3 ) ;
V_26 = & V_35 -> V_41 ;
V_3 = F_3 ( V_2 , V_26 ) ;
if ( V_3 != V_38 )
F_2 ( V_2 , L_57 ,
V_26 , ( unsigned int ) V_3 ) ;
V_26 = & V_35 -> V_42 ;
V_36 = F_20 ( V_2 , V_26 ) ;
F_2 ( V_2 , L_58 ,
V_26 , V_36 ) ;
V_26 = & V_35 -> V_43 ;
V_36 = F_20 ( V_2 , V_26 ) ;
F_2 ( V_2 , L_59 ,
V_26 , V_36 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_27 ;
F_2 ( V_2 , L_60 , V_2 -> V_9 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_9 -> V_44 ) ;
F_2 ( V_2 , L_61 ,
& V_2 -> V_9 -> V_44 ,
( unsigned int ) V_3 ) ;
for ( V_27 = 0 ; V_27 < 7 ; ++ V_27 ) {
V_3 = F_3 ( V_2 , & V_2 -> V_9 -> V_41 [ V_27 ] ) ;
if ( V_3 != V_38 )
F_2 ( V_2 , L_62 ,
& V_2 -> V_9 -> V_41 [ V_27 ] ,
V_27 , ( unsigned int ) V_3 ) ;
}
}
void F_22 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 , union V_45 * V_46 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 )
F_2 ( V_2 , L_63 ,
V_27 * 4 , V_46 -> V_47 . V_48 [ V_27 ] ) ;
}
void F_24 ( struct V_1 * V_2 , union V_45 * V_46 )
{
T_4 V_49 ;
T_1 type = F_25 ( V_46 -> V_50 . V_51 ) & V_52 ;
switch ( type ) {
case F_26 ( V_53 ) :
F_2 ( V_2 , L_64 ) ;
F_23 ( V_2 , V_46 ) ;
V_49 = F_27 ( V_46 -> V_50 . V_54 ) ;
F_2 ( V_2 , L_65 , V_49 ) ;
F_2 ( V_2 , L_66 ,
F_28 ( F_25 ( V_46 -> V_50 . V_55 ) ) ) ;
F_2 ( V_2 , L_67 ,
F_25 ( V_46 -> V_50 . V_51 ) & V_56 ) ;
F_2 ( V_2 , L_68 ,
F_25 ( V_46 -> V_50 . V_51 ) & V_57 ) ;
F_2 ( V_2 , L_69 ,
F_25 ( V_46 -> V_50 . V_51 ) & V_58 ) ;
break;
case F_26 ( V_59 ) :
V_49 = F_27 ( V_46 -> V_60 . V_61 ) ;
F_2 ( V_2 , L_70 , V_49 ) ;
break;
case F_26 ( V_62 ) :
V_49 = F_27 ( V_46 -> V_63 . V_64 ) ;
F_2 ( V_2 , L_71 , V_49 ) ;
F_2 ( V_2 , L_72 ,
F_29 ( F_25 ( V_46 -> V_63 . V_22 ) ) ) ;
F_2 ( V_2 , L_73 ,
F_25 ( V_46 -> V_63 . V_65 ) ) ;
break;
default:
F_2 ( V_2 , L_74 ,
( unsigned int ) type >> 10 ) ;
F_23 ( V_2 , V_46 ) ;
break;
}
}
void F_30 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_27 ;
T_4 V_26 = V_67 -> V_68 ;
union V_45 * V_46 = V_67 -> V_69 ;
for ( V_27 = 0 ; V_27 < V_70 ; ++ V_27 ) {
V_46 = & V_67 -> V_69 [ V_27 ] ;
F_2 ( V_2 , L_75 , V_26 ,
F_31 ( F_27 ( V_46 -> V_50 . V_54 ) ) ,
F_32 ( F_27 ( V_46 -> V_50 . V_54 ) ) ,
F_25 ( V_46 -> V_50 . V_55 ) ,
F_25 ( V_46 -> V_50 . V_51 ) ) ;
V_26 += sizeof( * V_46 ) ;
}
}
void F_33 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
F_2 ( V_2 , L_76 ,
V_72 -> V_73 ,
( unsigned long long ) F_34 ( V_72 -> V_74 ,
V_72 -> V_73 ) ) ;
F_2 ( V_2 , L_77 ,
V_72 -> V_75 ) ;
F_2 ( V_2 , L_78 ,
V_72 -> V_76 ,
( unsigned long long ) F_34 ( V_72 -> V_77 ,
V_72 -> V_76 ) ) ;
F_2 ( V_2 , L_79 ,
V_72 -> V_78 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_66 * V_67 ;
struct V_66 * V_79 = V_72 -> V_79 ;
F_30 ( V_2 , V_79 ) ;
if ( ! V_72 -> V_78 && ! V_72 -> V_75 ) {
F_2 ( V_2 , L_80 ) ;
return;
}
for ( V_67 = V_79 -> V_80 ; V_67 != V_79 ; V_67 = V_67 -> V_80 )
F_30 ( V_2 , V_67 ) ;
}
void F_36 ( struct V_1 * V_2 ,
unsigned int V_81 , unsigned int V_82 ,
struct V_83 * V_84 )
{
int V_27 ;
struct V_71 * V_72 ;
if ( V_84 -> V_85 & V_86 ) {
for ( V_27 = 1 ; V_27 < V_84 -> V_87 -> V_88 ; V_27 ++ ) {
V_72 = V_84 -> V_87 -> V_89 [ V_27 ] ;
F_2 ( V_2 , L_81 ,
V_81 , V_82 , V_27 ) ;
F_30 ( V_2 , V_72 -> V_74 ) ;
}
} else {
V_72 = V_84 -> V_72 ;
if ( ! V_72 )
return;
F_2 ( V_2 , L_82 ,
V_81 , V_82 ) ;
F_30 ( V_2 , V_72 -> V_74 ) ;
}
}
void F_37 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
T_4 V_26 = V_91 -> V_92 ;
int V_27 ;
struct V_93 * V_94 ;
for ( V_27 = 0 ; V_27 < V_91 -> V_95 ; ++ V_27 ) {
V_94 = & V_91 -> V_96 [ V_27 ] ;
F_2 ( V_2 , L_75 ,
V_26 ,
F_31 ( F_27 ( V_94 -> V_97 ) ) ,
F_32 ( F_27 ( V_94 -> V_97 ) ) ,
F_25 ( V_94 -> V_98 ) ,
F_25 ( V_94 -> V_41 ) ) ;
V_26 += sizeof( * V_94 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
T_4 V_99 ;
V_99 = F_20 ( V_2 , & V_2 -> V_6 -> V_100 ) ;
F_2 ( V_2 , L_83 ,
F_31 ( V_99 ) ) ;
F_2 ( V_2 , L_84 ,
F_32 ( V_99 ) ) ;
}
static void F_39 ( struct V_1 * V_2 , T_4 * V_101 , T_5 V_68 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 ) {
F_2 ( V_2 , L_85
L_86 ,
& V_101 [ 4 + V_27 ] , ( unsigned long long ) V_68 ,
V_101 [ 4 + V_27 ] , V_27 ) ;
V_68 += 8 ;
}
}
char * F_40 ( struct V_1 * V_2 ,
struct V_102 * V_101 )
{
struct V_103 * V_104 = F_41 ( V_2 , V_101 ) ;
switch ( F_42 ( F_25 ( V_104 -> V_105 ) ) ) {
case V_106 :
return L_87 ;
case V_107 :
return L_88 ;
case V_108 :
return L_89 ;
case V_109 :
return L_90 ;
default:
return L_51 ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_102 * V_101 )
{
int V_110 = 32 / 8 ;
int V_27 ;
struct V_103 * V_104 = F_41 ( V_2 , V_101 ) ;
T_5 V_68 = V_101 -> V_68 +
( ( unsigned long ) V_104 - ( unsigned long ) V_101 -> V_111 ) ;
int V_112 = F_44 ( V_2 -> V_15 ) ;
F_2 ( V_2 , L_91 ) ;
F_2 ( V_2 , L_92 ,
& V_104 -> V_113 ,
( unsigned long long ) V_68 , V_104 -> V_113 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_93 ,
& V_104 -> V_114 ,
( unsigned long long ) V_68 , V_104 -> V_114 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_94 ,
& V_104 -> V_115 ,
( unsigned long long ) V_68 , V_104 -> V_115 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_95 ,
& V_104 -> V_105 ,
( unsigned long long ) V_68 , V_104 -> V_105 ) ;
V_68 += V_110 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 ) {
F_2 ( V_2 , L_96 ,
& V_104 -> V_116 [ V_27 ] , ( unsigned long long ) V_68 ,
V_104 -> V_116 [ V_27 ] , V_27 ) ;
V_68 += V_110 ;
}
if ( V_112 )
F_39 ( V_2 , ( T_4 * ) V_104 , V_68 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_102 * V_101 ,
unsigned int V_117 )
{
int V_27 , V_28 ;
int V_118 = 31 ;
int V_110 = 32 / 8 ;
int V_112 = F_44 ( V_2 -> V_15 ) ;
if ( V_117 < 31 )
V_118 = V_117 + 1 ;
for ( V_27 = 0 ; V_27 < V_118 ; ++ V_27 ) {
struct V_119 * V_120 = F_46 ( V_2 , V_101 , V_27 ) ;
T_5 V_68 = V_101 -> V_68 +
( ( unsigned long ) V_120 - ( unsigned long ) V_101 -> V_111 ) ;
F_2 ( V_2 , L_97 , V_27 ) ;
F_2 ( V_2 , L_98 ,
& V_120 -> V_121 ,
( unsigned long long ) V_68 , V_120 -> V_121 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_99 ,
& V_120 -> V_122 ,
( unsigned long long ) V_68 , V_120 -> V_122 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_100 ,
& V_120 -> V_123 ,
( unsigned long long ) V_68 , V_120 -> V_123 ) ;
V_68 += 2 * V_110 ;
F_2 ( V_2 , L_101 ,
& V_120 -> V_124 ,
( unsigned long long ) V_68 , V_120 -> V_124 ) ;
V_68 += V_110 ;
for ( V_28 = 0 ; V_28 < 3 ; ++ V_28 ) {
F_2 ( V_2 , L_96 ,
& V_120 -> V_116 [ V_28 ] ,
( unsigned long long ) V_68 ,
V_120 -> V_116 [ V_28 ] , V_28 ) ;
V_68 += V_110 ;
}
if ( V_112 )
F_39 ( V_2 , ( T_4 * ) V_120 , V_68 ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
struct V_102 * V_101 ,
unsigned int V_117 )
{
int V_27 ;
int V_110 = 32 / 8 ;
T_5 V_68 = V_101 -> V_68 ;
int V_112 = F_44 ( V_2 -> V_15 ) ;
if ( V_101 -> type == V_125 ) {
struct V_126 * V_127 =
F_48 ( V_2 , V_101 ) ;
F_2 ( V_2 , L_102 ,
& V_127 -> V_128 , ( unsigned long long ) V_68 ,
V_127 -> V_128 ) ;
V_68 += V_110 ;
F_2 ( V_2 , L_103 ,
& V_127 -> V_129 , ( unsigned long long ) V_68 ,
V_127 -> V_129 ) ;
V_68 += V_110 ;
for ( V_27 = 0 ; V_27 < 6 ; ++ V_27 ) {
F_2 ( V_2 , L_104 ,
& V_127 -> V_130 [ V_27 ] , ( unsigned long long ) V_68 ,
V_127 -> V_130 [ V_27 ] , V_27 ) ;
V_68 += V_110 ;
}
if ( V_112 )
F_39 ( V_2 , ( T_4 * ) V_127 , V_68 ) ;
}
F_43 ( V_2 , V_101 ) ;
F_45 ( V_2 , V_101 , V_117 ) ;
}
